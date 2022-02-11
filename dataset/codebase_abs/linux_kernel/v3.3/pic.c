static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_6 = F_3 () ;
if ( V_6 != V_7 )
F_4 ( V_6 ) ;
V_5 -> V_8 ( & V_3 -> V_9 ) ;
}
void T_1 F_5 ( void )
{
#ifdef F_6
struct V_10 * V_11 ;
struct V_10 * V_12 = NULL ;
int V_6 ;
#endif
struct V_13 * V_13 = F_7 ( NULL , 0 ,
V_14 | V_15 |
V_16 | V_17 ,
0 , 256 , L_1 ) ;
F_8 ( V_13 == NULL ) ;
F_9 ( V_13 ) ;
#ifdef F_6
F_10 (np, L_2 )
if ( F_11 ( V_11 , L_3 ) ) {
V_12 = V_11 ;
break;
}
if ( V_12 == NULL ) {
F_12 ( V_18 L_4 ) ;
return;
}
V_6 = F_13 ( V_12 , 0 ) ;
if ( V_6 == V_7 ) {
F_12 ( V_19 L_5 ) ;
return;
}
F_14 ( V_12 , 0 ) ;
F_15 ( V_12 ) ;
F_16 ( V_6 , F_1 ) ;
#endif
}
