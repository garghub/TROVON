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
T_2 F_3 ( const T_1 * V_1 )
{
return V_1 -> V_3 ;
}
T_2 F_4 ( const T_1 * V_1 )
{
return V_1 -> V_5 ;
}
T_3 * F_5 ( T_1 * V_1 , const char * V_6 ,
T_4 * V_7 , void * V_8 )
{
T_3 * V_9 ;
if( V_1 == NULL )
{
F_6 ( V_10 ,
V_11 ) ;
return 0 ;
}
F_7 ( V_12 ) ;
if( V_1 -> V_13 == 0 )
{
F_8 ( V_12 ) ;
F_6 ( V_10 ,
V_14 ) ;
return 0 ;
}
F_8 ( V_12 ) ;
if ( ! V_1 -> V_3 )
{
F_6 ( V_10 ,
V_15 ) ;
return 0 ;
}
V_9 = V_1 -> V_3 ( V_1 , V_6 , V_7 , V_8 ) ;
if ( ! V_9 )
{
F_6 ( V_10 ,
V_16 ) ;
return 0 ;
}
return V_9 ;
}
T_3 * F_9 ( T_1 * V_1 , const char * V_6 ,
T_4 * V_7 , void * V_8 )
{
T_3 * V_9 ;
if( V_1 == NULL )
{
F_6 ( V_17 ,
V_11 ) ;
return 0 ;
}
F_7 ( V_12 ) ;
if( V_1 -> V_13 == 0 )
{
F_8 ( V_12 ) ;
F_6 ( V_17 ,
V_14 ) ;
return 0 ;
}
F_8 ( V_12 ) ;
if ( ! V_1 -> V_5 )
{
F_6 ( V_17 ,
V_15 ) ;
return 0 ;
}
V_9 = V_1 -> V_5 ( V_1 , V_6 , V_7 , V_8 ) ;
if ( ! V_9 )
{
F_6 ( V_17 ,
V_18 ) ;
return 0 ;
}
return V_9 ;
}
