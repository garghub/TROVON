static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_2 V_5 = F_2 ( V_6 ) ;
T_2 type = F_2 ( V_7 ) ;
F_3 ( V_4 , L_1 ,
( type & V_8 ) ? ( L_2 ) : ( L_3 ) ,
V_9 [ ( type >> V_10 ) & V_11 ] ,
V_5 , ( type >> V_12 ) & V_13 ,
type & V_14 ) ;
F_4 ( V_15 , V_7 ) ;
return V_16 ;
}
static int T_3 F_5 ( void )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_1 ;
if ( F_6 ( L_4 ) )
return - V_21 ;
V_20 = F_7 ( NULL , NULL , L_5 ) ;
if ( ! V_20 )
return - V_21 ;
V_18 = F_8 ( V_20 ) ;
if ( ! V_18 ) {
F_9 ( L_6 , V_20 -> V_22 ) ;
return - V_21 ;
}
V_1 = F_10 ( V_20 , 0 ) ;
if ( ! V_1 ) {
F_3 ( & V_18 -> V_4 , L_7 ) ;
return - V_21 ;
}
if ( F_11 ( V_1 , F_1 , 0 , L_8 , & V_18 -> V_4 ) ) {
F_3 ( & V_18 -> V_4 , L_9 ) ;
return - V_21 ;
}
F_4 ( V_15 , V_7 ) ;
F_12 ( & V_18 -> V_4 , L_10 ) ;
return 0 ;
}
