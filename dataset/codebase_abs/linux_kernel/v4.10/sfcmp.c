int
F_1 ( T_1 * V_1 , T_1 * V_2 ,
unsigned int V_3 , unsigned int * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 ;
V_5 = * V_1 ;
V_6 = * V_2 ;
if( ( F_2 ( V_5 ) == V_8 )
|| ( F_2 ( V_6 ) == V_8 ) )
{
if( ( ( F_2 ( V_5 ) == V_8 )
&& F_3 ( V_5 )
&& ( F_4 ( V_3 ) || F_5 ( V_5 ) ) )
||
( ( F_2 ( V_6 ) == V_8 )
&& F_3 ( V_6 )
&& ( F_4 ( V_3 ) || F_5 ( V_6 ) ) ) )
{
if( F_6 () ) {
F_7 ( F_8 ( V_3 ) ) ;
return ( V_9 ) ;
}
else F_9 () ;
F_7 ( F_8 ( V_3 ) ) ;
return ( V_10 ) ;
}
else if( ( ( F_2 ( V_5 ) == V_8 )
&& F_3 ( V_5 ) )
||
( ( F_2 ( V_6 ) == V_8 )
&& F_3 ( V_6 ) ) )
{
F_7 ( F_8 ( V_3 ) ) ;
return ( V_10 ) ;
}
}
F_10 ( V_5 , V_6 , V_7 ) ;
if( V_7 < 0 )
{
if( F_11 ( V_5 )
&& F_11 ( V_6 ) )
{
F_7 ( F_12 ( V_3 ) ) ;
}
else if( F_13 ( V_5 ) )
{
F_7 ( F_14 ( V_3 ) ) ;
}
else
{
F_7 ( F_15 ( V_3 ) ) ;
}
}
else if( F_16 ( V_5 ) == F_16 ( V_6 ) )
{
F_7 ( F_12 ( V_3 ) ) ;
}
else if( F_17 ( V_5 ) )
{
if( F_16 ( V_5 ) < F_16 ( V_6 ) )
{
F_7 ( F_14 ( V_3 ) ) ;
}
else
{
F_7 ( F_15 ( V_3 ) ) ;
}
}
else
{
if( F_16 ( V_5 ) > F_16 ( V_6 ) )
{
F_7 ( F_14 ( V_3 ) ) ;
}
else
{
F_7 ( F_15 ( V_3 ) ) ;
}
}
return ( V_10 ) ;
}
