package HetWLAN;

import HetWLAN.nodes.StandardStation;
import HetWLAN.nodes.StandardAccessPoint;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;

network HetWLAN
{
    @display("bgb=606,325");
    submodules:
        AP: StandardAccessPoint {
            @display("p=310,119");
        }
        STA: StandardStation {
            @display("p=310,200");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=100,100");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=100,200");
        }
}
