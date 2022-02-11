int F_1 ( T_1 * V_1 , T_2 V_2 )
{
V_1 -> V_3 = V_2 ;
return 1 ;
}
int F_2 ( T_1 * V_1 , T_2 V_4 )
{
V_1 -> V_5 = V_4 ;
return 1 ;
}
int F_3 ( T_1 * V_1 ,
T_3 V_6 )
{
V_1 -> V_7 = V_6 ;
return 1 ;
}
T_2 F_4 ( const T_1 * V_1 )
{
return V_1 -> V_3 ;
}
T_2 F_5 ( const T_1 * V_1 )
{
return V_1 -> V_5 ;
}
T_3 F_6 ( const T_1 * V_1 )
{
return V_1 -> V_7 ;
}
T_4 * F_7 ( T_1 * V_1 , const char * V_8 ,
T_5 * V_9 , void * V_10 )
{
T_4 * V_11 ;
if( V_1 == NULL )
{
F_8 ( V_12 ,
V_13 ) ;
return 0 ;
}
F_9 ( V_14 ) ;
if( V_1 -> V_15 == 0 )
{
F_10 ( V_14 ) ;
F_8 ( V_12 ,
V_16 ) ;
return 0 ;
}
F_10 ( V_14 ) ;
if ( ! V_1 -> V_3 )
{
F_8 ( V_12 ,
V_17 ) ;
return 0 ;
}
V_11 = V_1 -> V_3 ( V_1 , V_8 , V_9 , V_10 ) ;
if ( ! V_11 )
{
F_8 ( V_12 ,
V_18 ) ;
return 0 ;
}
return V_11 ;
}
T_4 * F_11 ( T_1 * V_1 , const char * V_8 ,
T_5 * V_9 , void * V_10 )
{
T_4 * V_11 ;
if( V_1 == NULL )
{
F_8 ( V_19 ,
V_13 ) ;
return 0 ;
}
F_9 ( V_14 ) ;
if( V_1 -> V_15 == 0 )
{
F_10 ( V_14 ) ;
F_8 ( V_19 ,
V_16 ) ;
return 0 ;
}
F_10 ( V_14 ) ;
if ( ! V_1 -> V_5 )
{
F_8 ( V_19 ,
V_17 ) ;
return 0 ;
}
V_11 = V_1 -> V_5 ( V_1 , V_8 , V_9 , V_10 ) ;
if ( ! V_11 )
{
F_8 ( V_19 ,
V_20 ) ;
return 0 ;
}
return V_11 ;
}
