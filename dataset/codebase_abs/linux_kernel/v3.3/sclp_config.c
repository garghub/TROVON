static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
F_2 () ;
F_3 ( L_1 ) ;
F_4 () ;
F_5 (cpu) {
V_5 = F_6 ( V_3 ) ;
F_7 ( & V_5 -> V_6 , V_7 ) ;
}
F_8 () ;
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
F_10 () ;
}
static void F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
V_11 = (struct V_10 * ) ( V_9 + 1 ) ;
switch ( V_11 -> V_12 ) {
case V_13 :
F_12 ( & V_14 ) ;
break;
case V_15 :
F_12 ( & V_16 ) ;
break;
}
}
static int T_2 F_13 ( void )
{
F_14 ( & V_16 , F_1 ) ;
F_14 ( & V_14 , F_9 ) ;
return F_15 ( & V_17 ) ;
}
