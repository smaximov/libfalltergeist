/*
 * Copyright 2012-2014 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBFALLTERGEIST_MAPFILETYPE_H
#define LIBFALLTERGEIST_MAPFILETYPE_H

// C++ standard includes
#include <string>
#include <vector>

// libfalltergeist includes
#include "../src/DatFileItem.h"

// Third party includes

namespace libfalltergeist
{
class MapElevation;
class ProFileType;
class MapObject;
class MapScript;

typedef std::shared_ptr<ProFileType> (*ProFileTypeLoaderCallback)(unsigned int);

class MapFileType : public DatFileItem
{
protected:
    ProFileTypeLoaderCallback _proFileTypeLoaderCallback = 0;

    std::vector<std::shared_ptr<MapElevation>> _elevations;
    std::vector<std::shared_ptr<MapScript>> _scripts;
    unsigned int _version;
    std::string _name;
    unsigned int _defaultPosition;
    unsigned int _defaultElevation;
    unsigned int _defaultOrientaion;
    unsigned int _MVARsize;
    unsigned int _LVARsize;
    unsigned int _elevationsFlag;
    unsigned int _mapId;
    unsigned int _timeTicks;
    unsigned int _unknown1;

    int _scriptId = -1;

    std::shared_ptr<MapObject> _readObject();
    virtual void _initialize();


public:
    MapFileType(std::shared_ptr<DatFileEntry> datFileEntry);
    MapFileType(std::ifstream* stream);
    ~MapFileType();

    MapFileType* setCallback(ProFileTypeLoaderCallback callback);
    ProFileTypeLoaderCallback callback();

    std::vector<std::shared_ptr<MapElevation>>* elevations();
    unsigned int defaultPosition();
    unsigned int defaultElevation();
    unsigned int defaultOrientation();
    int scriptId();

    unsigned int MVARsize();
    unsigned int LVARsize();
    std::string name();
};


}

#endif // LIBFALLTERGEIST_MAPFILETYPE_H
