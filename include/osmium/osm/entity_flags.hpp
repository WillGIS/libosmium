#ifndef OSMIUM_OSM_ENTITY_FLAGS_HPP
#define OSMIUM_OSM_ENTITY_FLAGS_HPP

/*

This file is part of Osmium (http://osmcode.org/osmium).

Copyright 2013 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

namespace osmium {

    namespace osm_entity {

        enum flags {

            nothing   = 0x00,
            node      = 0x01,
            way       = 0x02,
            relation  = 0x04,
            area      = 0x08,
            changeset = 0x10,
            all       = 0x1f

        }; // enum flags

        inline flags operator|(const flags lhs, const flags rhs) {
            return static_cast<flags>(static_cast<int>(lhs) | static_cast<int> (rhs));
        }

        inline flags& operator|=(flags& lhs, const flags rhs) {
            lhs = lhs | rhs;
            return lhs;
        }

        inline flags operator&(const flags lhs, const flags rhs) {
            return static_cast<flags>(static_cast<int>(lhs) & static_cast<int> (rhs));
        }

        inline flags operator&=(flags& lhs, const flags rhs) {
            lhs = lhs & rhs;
            return lhs;
        }

    } // namespace osm_entity

} // namespace osmium

#endif // OSMIUM_OSM_ENTITY_FLAGS_HPP
