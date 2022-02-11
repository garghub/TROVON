void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
char * V_6 = V_5 [ V_4 ] . V_6 ;
F_3 (node, NULL,
of_rtc_table[i].compatible) {
struct V_7 * V_8 ;
V_8 = F_4 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 ) {
F_5 ( V_10 L_1
L_2 ,
V_2 -> V_11 ) ;
continue;
}
V_3 = F_6 ( V_2 , 0 , V_8 ) ;
if ( V_3 ) {
F_5 ( V_10 L_3
L_4 ,
V_2 -> V_11 ) ;
continue;
}
F_5 ( V_12 L_5 ,
V_2 -> V_11 , V_6 ,
( unsigned long long ) V_8 -> V_13 ,
( unsigned long long ) V_8 -> V_14 ) ;
F_7 ( V_6 , - 1 , V_8 , 1 ) ;
}
}
}
