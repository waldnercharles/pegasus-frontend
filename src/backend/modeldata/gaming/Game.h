// Pegasus Frontend
// Copyright (C) 2017-2018  Mátyás Mustoha
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include "GameAssets.h"

#include <QDateTime>
#include <QFileInfo>
#include <QString>
#include <QStringList>


namespace modeldata {

struct Game {
    explicit Game(QFileInfo fileinfo);

    const QFileInfo& fileinfo() const { return m_fileinfo; }

    QString title;
    QString summary;
    QString description;
    QString launch_cmd;

    int player_count;
    bool is_favorite;
    float rating;

    int playcount;
    QTime playtime;
    QDateTime lastplayed;

    QStringList developer_list;
    QStringList publisher_list;
    QStringList genre_list;
    QString developer_str;
    QString publisher_str;
    QString genre_str;
    void addDeveloper(const QString&);
    void addPublisher(const QString&);
    void addGenre(const QString&);
    void addDevelopers(const QStringList&);
    void addPublishers(const QStringList&);
    void addGenres(const QStringList&);

    void setReleaseDate(QDate);
    int release_year;
    int release_month;
    int release_day;
    QDate release_date;

    GameAssets assets;


    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    Game(Game&&) = default;
    Game& operator=(Game&&) = default;

private:
    QFileInfo m_fileinfo;
};

} // namespace modeldata