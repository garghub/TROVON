int
F_1 ( T_1 * V_1 , T_1 * V_2 ,
unsigned int V_3 , unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 , V_8 ;
register int V_9 ;
F_2 ( V_1 , V_5 , V_6 ) ;
F_2 ( V_2 , V_7 , V_8 ) ;
if( ( F_3 ( V_5 ) == V_10 )
|| ( F_3 ( V_7 ) == V_10 ) )
{
if( ( ( F_3 ( V_5 ) == V_10 )
&& F_4 ( V_5 , V_6 )
&& ( F_5 ( V_3 ) || F_6 ( V_5 ) ) )
||
( ( F_3 ( V_7 ) == V_10 )
&& F_4 ( V_7 , V_8 )
&& ( F_5 ( V_3 ) || F_6 ( V_7 ) ) ) )
{
if( F_7 () ) {
F_8 ( F_9 ( V_3 ) ) ;
return ( V_11 ) ;
}
else F_10 () ;
F_8 ( F_9 ( V_3 ) ) ;
return ( V_12 ) ;
}
else if( ( ( F_3 ( V_5 ) == V_10 )
&& F_4 ( V_5 , V_6 ) )
||
( ( F_3 ( V_7 ) == V_10 )
&& F_4 ( V_7 , V_8 ) ) )
{
F_8 ( F_9 ( V_3 ) ) ;
return ( V_12 ) ;
}
}
F_11 ( V_5 , V_7 , V_9 ) ;
if( V_9 < 0 )
{
if( F_12 ( V_5 , V_6 )
&& F_12 ( V_7 , V_8 ) )
{
F_8 ( F_13 ( V_3 ) ) ;
}
else if( F_14 ( V_5 ) )
{
F_8 ( F_15 ( V_3 ) ) ;
}
else
{
F_8 ( F_16 ( V_3 ) ) ;
}
}
else if( F_17 ( V_5 , V_6 , V_7 , V_8 ) )
{
F_8 ( F_13 ( V_3 ) ) ;
}
else if( F_18 ( V_5 ) )
{
if( F_19 ( V_5 ) < F_19 ( V_7 ) )
{
F_8 ( F_15 ( V_3 ) ) ;
}
else if( F_19 ( V_5 ) > F_19 ( V_7 ) )
{
F_8 ( F_16 ( V_3 ) ) ;
}
else
{
if( F_20 ( V_6 ) < F_20 ( V_8 ) )
{
F_8 ( F_15 ( V_3 ) ) ;
}
else
{
F_8 ( F_16 ( V_3 ) ) ;
}
}
}
else
{
if( F_19 ( V_5 ) > F_19 ( V_7 ) )
{
F_8 ( F_15 ( V_3 ) ) ;
}
else if( F_19 ( V_5 ) < F_19 ( V_7 ) )
{
F_8 ( F_16 ( V_3 ) ) ;
}
else
{
if( F_20 ( V_6 ) > F_20 ( V_8 ) )
{
F_8 ( F_15 ( V_3 ) ) ;
}
else
{
F_8 ( F_16 ( V_3 ) ) ;
}
}
}
return ( V_12 ) ;
}
