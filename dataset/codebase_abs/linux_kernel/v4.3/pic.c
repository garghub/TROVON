static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
if ( V_5 != V_6 )
F_4 ( V_5 ) ;
V_4 -> V_7 ( & V_2 -> V_8 ) ;
}
void T_1 F_5 ( void )
{
#ifdef F_6
struct V_9 * V_10 ;
struct V_9 * V_11 = NULL ;
int V_5 ;
#endif
struct V_12 * V_12 = F_7 ( NULL , 0 , V_13 |
V_14 ,
0 , 256 , L_1 ) ;
F_8 ( V_12 == NULL ) ;
F_9 ( V_12 ) ;
#ifdef F_6
F_10 (np, L_2 )
if ( F_11 ( V_10 , L_3 ) ) {
V_11 = V_10 ;
break;
}
if ( V_11 == NULL ) {
F_12 ( V_15 L_4 ) ;
return;
}
V_5 = F_13 ( V_11 , 0 ) ;
if ( V_5 == V_6 ) {
F_12 ( V_16 L_5 ) ;
return;
}
F_14 ( V_11 , 0 ) ;
F_15 ( V_11 ) ;
F_16 ( V_5 , F_1 ) ;
#endif
}
