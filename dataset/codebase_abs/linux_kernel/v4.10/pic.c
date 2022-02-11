static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
if ( V_5 )
F_4 ( V_5 ) ;
V_4 -> V_6 ( & V_2 -> V_7 ) ;
}
void T_1 F_5 ( void )
{
#ifdef F_6
struct V_8 * V_9 ;
struct V_8 * V_10 = NULL ;
int V_5 ;
#endif
struct V_11 * V_11 = F_7 ( NULL , 0 , V_12 |
V_13 ,
0 , 256 , L_1 ) ;
F_8 ( V_11 == NULL ) ;
F_9 ( V_11 ) ;
#ifdef F_6
F_10 (np, L_2 )
if ( F_11 ( V_9 , L_3 ) ) {
V_10 = V_9 ;
break;
}
if ( V_10 == NULL ) {
F_12 ( V_14 L_4 ) ;
return;
}
V_5 = F_13 ( V_10 , 0 ) ;
if ( ! V_5 ) {
F_12 ( V_15 L_5 ) ;
return;
}
F_14 ( V_10 , 0 ) ;
F_15 ( V_10 ) ;
F_16 ( V_5 , F_1 ) ;
#endif
}
