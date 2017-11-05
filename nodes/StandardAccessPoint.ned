//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

package HetWLAN.nodes;

import inet.node.wireless.AccessPoint;

//
// A generic access point supporting multiple wireless radios, and
// multiple ethernet ports. The type of the ethernet MAC, relay unit
// and wireless card can be specified as parameters.
//
// By default, the access point is stationary (~StationaryMobility),
// but that can also be configured by a parameter.
//
// The wlan[*].mgmtType can be configured for different management types
// currently it can be: ~Ieee80211MgmtAPSimplified and ~Ieee80211MgmtAP.
// By default it is ~Ieee80211MgmtAP. The Simplified version does not
// support channel scanning, authentication and association .
// In this case, nodes must explicitly specify the hardware address
// of the wlan card they want to be associated with.
//
module StandardAccessPoint extends AccessPoint
{
    
}
