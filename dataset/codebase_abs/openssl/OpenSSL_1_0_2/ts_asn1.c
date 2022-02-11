int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
return F_2 ( T_2 , V_3 , V_1 , V_2 ) ;
}
T_2 * F_3 ( T_3 * V_4 , T_2 * * V_2 )
{
return F_4 ( T_2 , V_5 ,
V_6 , V_4 , V_2 ) ;
}
int F_5 ( T_3 * V_4 , T_2 * V_2 )
{
return F_6 ( T_2 , V_3 , V_4 , V_2 ) ;
}
int F_7 ( T_1 * V_1 , T_4 * V_2 )
{
return F_2 ( T_4 , V_7 , V_1 , V_2 ) ;
}
T_4 * F_8 ( T_3 * V_4 , T_4 * * V_2 )
{
return F_4 ( T_4 , V_8 , V_9 , V_4 , V_2 ) ;
}
int F_9 ( T_3 * V_4 , T_4 * V_2 )
{
return F_6 ( T_4 , V_7 , V_4 , V_2 ) ;
}
int F_10 ( T_1 * V_1 , T_5 * V_2 )
{
return F_2 ( T_5 , V_10 , V_1 , V_2 ) ;
}
T_5 * F_11 ( T_3 * V_4 , T_5 * * V_2 )
{
return F_4 ( T_5 , V_11 , V_12 , V_4 ,
V_2 ) ;
}
int F_12 ( T_3 * V_4 , T_5 * V_2 )
{
return F_6 ( T_5 , V_10 , V_4 , V_2 ) ;
}
int F_13 ( int V_13 , T_6 * * V_14 , const T_7 * V_15 ,
void * V_16 )
{
T_8 * V_17 = ( T_8 * ) * V_14 ;
if ( V_13 == V_18 ) {
V_17 -> V_19 = NULL ;
} else if ( V_13 == V_20 ) {
if ( V_17 -> V_19 != NULL )
F_14 ( V_17 -> V_19 ) ;
} else if ( V_13 == V_21 ) {
if ( F_15 ( V_17 ) == 0 )
return 0 ;
}
return 1 ;
}
int F_16 ( T_1 * V_1 , T_8 * V_2 )
{
return F_2 ( T_8 , V_22 , V_1 , V_2 ) ;
}
T_8 * F_17 ( T_3 * V_4 , T_8 * * V_2 )
{
return F_4 ( T_8 , V_23 , V_24 , V_4 , V_2 ) ;
}
int F_18 ( T_3 * V_4 , T_8 * V_2 )
{
return F_6 ( T_8 , V_22 , V_4 , V_2 ) ;
}
