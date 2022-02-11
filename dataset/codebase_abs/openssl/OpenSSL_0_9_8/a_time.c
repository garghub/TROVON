T_1 * F_1 ( T_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_4 ;
struct V_3 V_5 ;
V_4 = F_2 ( & V_2 , & V_5 ) ;
if ( V_4 == NULL )
{
F_3 ( V_6 , V_7 ) ;
return NULL ;
}
if( ( V_4 -> V_8 >= 50 ) && ( V_4 -> V_8 < 150 ) )
return F_4 ( V_1 , V_2 ) ;
return F_5 ( V_1 , V_2 ) ;
}
int F_6 ( T_1 * V_2 )
{
if ( V_2 -> type == V_9 )
return F_7 ( V_2 ) ;
else if ( V_2 -> type == V_10 )
return F_8 ( V_2 ) ;
return 0 ;
}
T_3 * F_9 ( T_1 * V_2 , T_3 * * V_11 )
{
T_3 * V_12 ;
char * V_13 ;
int V_14 ;
if ( ! F_6 ( V_2 ) ) return NULL ;
if ( ! V_11 || ! * V_11 )
{
if ( ! ( V_12 = F_10 () ) )
return NULL ;
if ( V_11 ) * V_11 = V_12 ;
}
else V_12 = * V_11 ;
if ( V_2 -> type == V_9 )
{
if( ! F_11 ( V_12 , V_2 -> V_5 , V_2 -> V_15 ) )
return NULL ;
return V_12 ;
}
if ( ! F_11 ( V_12 , NULL , V_2 -> V_15 + 2 ) )
return NULL ;
V_14 = V_2 -> V_15 + 2 + 1 ;
V_13 = ( char * ) V_12 -> V_5 ;
if ( V_2 -> V_5 [ 0 ] >= '5' ) F_12 ( V_13 , L_1 , V_14 ) ;
else F_12 ( V_13 , L_2 , V_14 ) ;
F_13 ( V_13 , ( char * ) V_2 -> V_5 , V_14 ) ;
return V_12 ;
}
