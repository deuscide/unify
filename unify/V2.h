/*
 * Unify Library
 * https://github.com/kit10us/unify
 * Copyright (c) 2002, Kit10 Studios LLC
 *
 * This file is part of Unify Library (a.k.a. Unify)
 *
 * Unify is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Unify is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Unify.  If not, see <https://www.gnu.org/licenses/>.
 */


#pragma once

#include <unify/Unify.h>
#include <unify/String.h>
#include <unify/Angle.h>
#include <unify/Exception.h>

namespace unify
{
	template < class T > class V3;
	template < class T > class Size;

	template < class T = float >
	class V2
	{
	public:
		T x, y;

		V2();
		V2( T x, T y );
		V2( const V2< T > & vec );
		explicit V2( const Size< T > & size );
        explicit V2( std::string text );
		
		// Conversion operators...
		V2< T > & operator = ( const Size< T > & size );
		V2< T > & operator = ( const V3< T > & vec3 );

		// binary operators
		V2< T > & operator = ( const V2< T > & vec );

		V2< T > & operator += ( const V2< T > & vec );
		V2< T > & operator -= ( const V2< T > & vec );
		V2< T > & operator *= ( const V2< T > & vec );
		V2< T > & operator /= ( const V2< T > & vec );
		V2< T > & operator *= ( T val );
		V2< T > & operator /= ( T val );

		V2< T > operator + ( const V2< T > & vec) const;
		V2< T > operator - ( const V2< T > & vec ) const;
		V2< T > operator * ( const V2< T > & vec ) const;
		V2< T > operator / ( const V2< T > & vec ) const;
		V2< T > operator * ( T val ) const;
		V2< T > operator / ( T val ) const;

		bool operator == ( const V2< T > & vec ) const;
		bool operator != ( const V2< T > & vec ) const;

        T & operator[]( size_t i );
        const T & operator[]( size_t i ) const;

		T Length() const;
		void Normalize();
		V2< T > Absolute() const;
		const T DistanceTo(const V2<T> & to) const;
		T Dot(const V2< T > & a) const;
		Angle Angle(const V2< T > & a) const;
		bool IsZero() const;

        std::string ToString() const;

		// Named constructors
		static V2< T > V2Zero();
		static V2< T > V2Lerp(V2< T > first, V2< T > second, float ratio);
		static V2< T > V2X(T x);
		static V2< T > V2Y(T y);
		static V2< T > V2Normalized(const V2< T > & in);
		static V2< T > V2Inverse(const V2< T > & in);
		static T V2Dot(const V2< T > & l, const V2< T > &  r);
	};
	#include <unify/V2.inl>
}
