int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 () ;
if ( V_1 != 0 )
return V_1 ;
V_1 = F_3 () ;
if ( V_1 != 0 )
return V_1 ;
V_1 = F_4 () ;
if ( V_1 != 0 )
return V_1 ;
return 0 ;
}
struct V_2 * F_5 ( int type ,
struct V_3 * V_4 )
{
struct V_2 * V_5 ;
char * V_6 ;
T_2 V_7 ;
if ( V_8 == 0 )
return NULL ;
V_5 = F_6 ( V_9 -> V_10 , V_11 , type ) ;
if ( V_5 == NULL )
return NULL ;
F_7 ( V_5 , L_1 ,
F_8 ( & V_12 , V_4 -> V_13 ) ,
V_4 -> V_14 ) ;
if ( V_4 -> V_15 != 0 &&
F_9 ( V_4 -> V_15 ,
& V_6 ,
& V_7 ) == 0 ) {
F_7 ( V_5 , L_2 , V_6 ) ;
F_10 ( V_6 , V_7 ) ;
}
return V_5 ;
}
