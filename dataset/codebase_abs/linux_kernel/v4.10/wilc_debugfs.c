static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] ;
int V_6 = 0 ;
if ( * V_4 > 0 )
return 0 ;
V_6 = F_2 ( V_5 , sizeof( V_5 ) , L_1 , F_3 ( & V_7 ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_8 , const char T_2 * V_5 ,
T_3 V_3 , T_4 * V_4 )
{
int V_9 = 0 ;
int V_10 ;
V_10 = F_6 ( V_5 , V_3 , 16 , & V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 > V_11 ) {
F_7 ( L_2 , V_12 , V_9 , F_3 ( & V_7 ) ) ;
return - V_13 ;
}
F_8 ( & V_7 , ( int ) V_9 ) ;
if ( V_9 == 0 )
F_7 ( L_3 ) ;
else
F_7 ( L_4 ) ;
return V_3 ;
}
static int T_5 F_9 ( void )
{
int V_14 ;
struct V_15 * V_16 ;
V_17 = F_10 ( L_5 , NULL ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_18 ) ; V_14 ++ ) {
V_16 = & V_18 [ V_14 ] ;
F_12 ( V_16 -> V_19 ,
V_16 -> V_20 ,
V_17 ,
& V_16 -> V_21 ,
& V_16 -> V_22 ) ;
}
return 0 ;
}
static void T_6 F_13 ( void )
{
F_14 ( V_17 ) ;
}
