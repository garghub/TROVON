static void T_1 F_1 ( T_2 V_1 )
{
if ( V_2 - V_1 <= 0 ) {
F_2 ( L_1 ,
V_1 , V_2 ) ;
return;
}
F_3 ( L_2 , V_1 ) ;
F_4 ( V_1 , F_5 ( F_6 ( V_3 ) ) ) ;
}
static int T_1 F_7 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
int V_11 ;
V_7 = (struct V_6 * ) V_5 ;
V_11 = F_8 ( V_7 , struct V_8 ) ;
V_9 = (struct V_8 * ) V_7 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
F_1 ( V_9 -> V_12 ) ;
V_9 ++ ;
}
V_13 = 1 ;
return 0 ;
}
static int T_1 F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_14 * V_9 ;
int V_10 , V_15 ;
struct V_16 V_17 = {
. type = V_18 ,
. V_19 = & V_20 ,
} ;
V_7 = (struct V_6 * ) V_5 ;
V_15 = F_8 ( V_7 , struct V_14 ) ;
V_9 = (struct V_14 * ) V_7 -> V_9 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
F_10 ( V_10 , V_9 -> V_21 , V_22 , & V_17 ) ;
V_9 ++ ;
}
F_11 ( V_23 , V_24
L_3 ) ;
V_23 = 0 ;
return 0 ;
}
int T_1 F_12 ( void )
{
#ifdef F_13
F_14 ( V_25 ) ;
F_15 ( V_26 , NULL , NULL , F_7 ) ;
#endif
#ifdef F_16
F_15 ( V_27 , NULL , NULL , F_9 ) ;
#endif
return 0 ;
}
