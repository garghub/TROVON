static int T_1 F_1 ( void )
{
int V_1 ;
void T_2 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! F_2 () )
return - V_9 ;
F_3 ( F_4 ( V_10 ) | 0x04 ,
V_10 ) ;
for ( V_1 = 0 ; V_1 < F_5 ( V_11 ) ; V_1 ++ ) {
V_6 = V_11 [ V_1 ] ;
V_8 = V_6 -> V_12 . V_13 ;
V_4 = F_6 ( V_6 , V_14 , 0 ) ;
if ( F_7 ( ! V_4 ) ) {
F_8 ( & V_6 -> V_12 , L_1 ) ;
return - V_15 ;
}
V_2 = F_9 ( V_4 -> V_16 , F_10 ( V_4 ) ) ;
if ( F_7 ( ! V_2 ) ) {
F_8 ( & V_6 -> V_12 , L_2 ) ;
return - V_17 ;
}
F_11 ( V_18 , V_2 + V_19 ) ;
F_12 ( V_2 ) ;
F_13 ( V_11 [ V_1 ] ) ;
}
return 0 ;
}
