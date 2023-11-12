#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <unordered_set> 
 
using namespace std; 
 
struct Journey { 
    string route; 
    vector<string> stops; 
}; 
 
class GTFSProcessor { 
private: 
    unordered_map<string, vector<string>> routes; 
    unordered_map<string, string> stopToRoute; 
 
public: 
    void addRoute(const string& routeId, const vector<string>& stops) { 
        routes[routeId] = stops; 
 
        for (const auto& stop : stops) { 
            if (stopToRoute.find(stop) == stopToRoute.end()) { 
                stopToRoute[stop] = routeId; 
            } 
        } 
    } 
 
    vector<Journey> findDirectJourneys(const string& sourceStop, const string& destStop) { 
        vector<Journey> directJourneys; 
         
        if (stopToRoute.find(sourceStop) != stopToRoute.end() && 
            stopToRoute.find(destStop) != stopToRoute.end() && 
            stopToRoute[sourceStop] == stopToRoute[destStop]) { 
            directJourneys.push_back({stopToRoute[sourceStop], {sourceStop, destStop}}); 
        } 
 
        return directJourneys; 
    } 
 
    vector<Journey> findJourneysWithOneTransfer(const string& sourceStop, const string& destStop) { 
        vector<Journey> journeysWithOneTransfer; 
 
        for (const auto& entry : stopToRoute) { 
            const string& transferStop = entry.first; 
            const string& transferRoute = entry.second; 
 
            if (transferStop != sourceStop && transferStop != destStop) { 
                if (stopToRoute[sourceStop] == transferRoute && 
                    stopToRoute[transferStop] == stopToRoute[destStop]) { 
                    journeysWithOneTransfer.push_back({stopToRoute[sourceStop], {sourceStop, transferStop, destStop}}); 
                } 
            } 
        } 
 
        return journeysWithOneTransfer; 
    } 
}; 
 
int main() { 
    GTFSProcessor gtfsProcessor; 
 
 
    gtfsProcessor.addRoute("R1", {"so", "s1", "sd"}); 
    gtfsProcessor.addRoute("R2", {"so", "s1"}); 
    gtfsProcessor.addRoute("R3", {"s1", "sd"}); 
    gtfsProcessor.addRoute("R4", {"so", "s2"}); 
    gtfsProcessor.addRoute("R5", {"s2", "sd"}); 
    gtfsProcessor.addRoute("R6", {"so", "s5"}); 
    gtfsProcessor.addRoute("R7", {"s5", "s6"}); 
    gtfsProcessor.addRoute("R8", {"s6", "sd"}); 
 
    
    string sourceStop, destStop; 
    cout << "Enter source stop: "; 
    cin >> sourceStop; 
    cout << "Enter destination stop: "; 
    cin >> destStop; 
 
    auto directJourneys = gtfsProcessor.findDirectJourneys(sourceStop, destStop); 
    cout << "Direct journeys: "; 
    for (const auto& journey : directJourneys) { 
        cout << journey.route << "("; 
        for (const auto& stop : journey.stops) { 
            cout << stop << " > "; 
        } 
        cout << "\b\b) "; 
    } 
    cout << endl; 
 

    auto oneTransferJourneys = gtfsProcessor.findJourneysWithOneTransfer(sourceStop, destStop); 
    cout << "Journeys with one transfer: "; 
    for (const auto& journey : oneTransferJourneys) { 
        cout << journey.route << "("; 
        for (const auto& stop : journey.stops) { 
            cout << stop << " > "; 
        } 
        cout << "\b\b) "; 
    } 
    cout << endl; 
 
    return 0; 
}