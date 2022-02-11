static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
T_2 V_9 ;
T_3 * V_10 ;
int V_11 ;
V_10 = F_3 ( V_6 -> V_12 , V_13 ) ;
if ( V_10 == NULL )
goto V_14;
V_11 = F_4 ( V_8 -> V_15 , V_10 ,
V_8 -> V_16 -> V_17 [ 0 ] . V_18 . V_19 / 8 ) ;
if ( V_11 < 0 )
goto V_14;
V_9 = F_5 () ;
if ( V_6 -> V_20 )
memcpy ( V_10 + V_6 -> V_12 - sizeof( T_2 ) ,
& V_9 , sizeof( V_9 ) ) ;
V_6 -> V_21 -> V_22 -> V_23 ( V_6 -> V_21 , V_10 , V_9 ) ;
V_14:
F_6 ( V_6 -> V_24 ) ;
F_7 ( V_10 ) ;
return V_25 ;
}
int F_8 ( struct V_5 * V_6 )
{
return F_9 ( V_6 , NULL ,
& F_1 , NULL ) ;
}
void F_10 ( struct V_5 * V_6 )
{
F_11 ( V_6 ) ;
}
