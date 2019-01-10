// Copyright (c) 2002 - 2018, Evil Quail LLC
// All Rights Reserved

/// <summary>
/// Test DataLock.
/// </summary>

#include <unify/DataLock.h>
#include <unify/String.h>
#include <unify/test/Suite.h>

int main( int argc, char ** argv )
{
	using namespace unify;
	using namespace test;
	using namespace string;

	Suite suite;
	suite.BeginSuite( "DataLock" );
	{
		suite.BeginCase( "FromString" );
		suite.Assert( "from \"None\"", DataLock::None == DataLock::FromString( "None" ) );
		suite.Assert( "from \"Readonly\"", DataLock::Readonly == DataLock::FromString( "Readonly" ) );
		suite.Assert( "from \"Writeonly\"", DataLock::Writeonly == DataLock::FromString( "Writeonly" ) );
		suite.Assert( "from \"Readonly\"", DataLock::ReadWrite == DataLock::FromString( "ReadWrite" ) );
		suite.EndCase();

		suite.BeginCase( "ToString" );
		suite.Assert( "from \"None\"", "None" == DataLock::ToString( DataLock::None ) );
		suite.Assert( "from \"Readonly\"", "Readonly" == DataLock::ToString( DataLock::Readonly ) );
		suite.Assert( "from \"Writeonly\"", "Writeonly" == DataLock::ToString( DataLock::Writeonly ) );
		suite.Assert( "from \"Readonly\"", "ReadWrite" == DataLock::ToString( DataLock::ReadWrite ) );
		suite.EndCase();

		suite.BeginCase( "ReadAccess" );
		suite.Assert( "None", DataLock::ReadAccess( DataLock::None ) == false );
		suite.Assert( "Readonly", DataLock::ReadAccess( DataLock::Readonly ) == true );
		suite.Assert( "Writeonly", DataLock::ReadAccess( DataLock::Writeonly ) == false );
		suite.Assert( "Readonly", DataLock::ReadAccess( DataLock::ReadWrite ) == true );
		suite.EndCase();

		suite.BeginCase( "WriteAccess" );
		suite.Assert( "None", DataLock::WriteAccess( DataLock::None ) == false );
		suite.Assert( "Readonly", DataLock::WriteAccess( DataLock::Readonly ) == false );
		suite.Assert( "Writeonly", DataLock::WriteAccess( DataLock::Writeonly ) == true );
		suite.Assert( "Readonly", DataLock::WriteAccess( DataLock::ReadWrite ) == true );
		suite.EndCase();
	}
	suite.EndSuite();
	return 0;
}