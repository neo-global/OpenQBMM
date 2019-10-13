/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2013-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.
    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.
    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.
\*---------------------------------------------------------------------------*/

#include "RK2.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace ButcherTables
{

    defineTypeNameAndDebug(RK2, 0);
    addToRunTimeSelectionTable(ButcherTable, RK2, dictionary);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::ButcherTables::RK2::RK2(const fvMesh& mesh)
:
    ButcherTable(mesh)
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::ButcherTables::RK2::~RK2()
{}

// * * * * * * * * * * *  Protected Member Fucntions * * * * * * * * * * * * //

Foam::List<Foam::scalarList>
Foam::ButcherTables::RK2::coeffs() const
{
    return  {{1.0}, {1.0, 0.0}};
}

Foam::List<Foam::scalarList>
Foam::ButcherTables::RK2::Fcoeffs() const
{
    return {{0.5}, {0.0, 1.0}};
}

// ************************************************************************* //