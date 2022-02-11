void F_1 ( void )
{
V_1 |= 3 << ( ( V_2 & 7 ) * 2 ) ;
V_2 ++ ;
}
int F_2 ( void )
{
return ( V_1 >> ( ( V_2 & 7 ) * 2 ) ) & 3 ;
}
int F_3 ( int V_3 )
{
return ( V_1 >> ( ( ( V_2 + V_3 ) & 7 ) * 2 ) ) & 3 ;
}
int F_4 ( int V_4 )
{
return ( V_1 >> ( ( V_4 & 7 ) * 2 ) ) & 3 ;
}
void F_5 ( int V_5 )
{
int V_4 = V_2 ;
V_4 &= 7 ;
V_1 &= ~ ( 3 << ( V_4 * 2 ) ) ;
V_1 |= ( V_5 & 3 ) << ( V_4 * 2 ) ;
}
void F_6 ( int V_3 , int V_5 )
{
int V_4 = V_3 + V_2 ;
V_4 &= 7 ;
V_1 &= ~ ( 3 << ( V_4 * 2 ) ) ;
V_1 |= ( V_5 & 3 ) << ( V_4 * 2 ) ;
}
void F_7 ( int V_4 , int V_5 )
{
V_4 &= 7 ;
V_1 &= ~ ( 3 << ( V_4 * 2 ) ) ;
V_1 |= ( V_5 & 3 ) << ( V_4 * 2 ) ;
}
int F_8 ( T_1 const * V_6 )
{
int exp = F_9 ( V_6 ) ;
if ( exp == V_7 + V_8 )
return V_9 ;
else if ( exp != V_7 + V_10 )
return V_11 ;
else if ( ( V_6 -> V_12 == 0x80000000 ) && ( V_6 -> V_13 == 0 ) )
return V_14 ;
return V_11 ;
}
int F_10 ( T_1 const * V_6 )
{
return ( ( F_9 ( V_6 ) == V_7 + V_10 )
&& ! ( ( V_6 -> V_12 == 0x80000000 ) && ( V_6 -> V_13 == 0 ) ) ) ;
}
int F_11 ( int V_3 )
{
int V_4 = ( V_2 + V_3 ) & 7 ;
return ( ( V_1 >> ( V_4 * 2 ) ) & 3 ) == V_15 ;
}
int F_12 ( T_1 * * V_16 )
{
* V_16 = & F_13 ( - 1 ) ;
return ( ( V_1 >> ( ( ( V_2 - 1 ) & 7 ) * 2 ) ) & 3 ) != V_15 ;
}
void F_14 ( T_1 const * V_17 , T_2 V_5 , int V_3 )
{
F_15 ( V_17 , & F_13 ( V_3 ) ) ;
F_6 ( V_3 , V_5 ) ;
}
void F_16 ( T_1 const * V_17 , T_2 V_5 )
{
F_15 ( V_17 , & F_13 ( 1 ) ) ;
F_6 ( 1 , V_5 ) ;
}
void F_17 ( T_1 const * V_17 , T_2 V_5 )
{
int V_4 = V_2 ;
V_4 &= 7 ;
F_15 ( V_17 , & F_13 ( 0 ) ) ;
V_1 &= ~ ( 3 << ( V_4 * 2 ) ) ;
V_1 |= ( V_5 & 3 ) << ( V_4 * 2 ) ;
}
