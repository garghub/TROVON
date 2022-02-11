void F_1 ( enum V_1 V_2 )
{
struct V_3 * V_4 = & F_2 ( V_5 ) ;
switch ( V_2 ) {
case V_6 :
case V_7 :
F_3 ( V_4 -> V_8 , V_9 ) ;
break;
case V_10 :
case V_11 :
case V_12 :
F_3 ( V_4 -> V_8 , V_13 ) ;
break;
default:
break;
}
}
static int F_4 ( void )
{
F_1 ( V_11 ) ;
return 0 ;
}
static void F_5 ( void )
{
F_1 ( V_7 ) ;
}
static void F_6 ( void )
{
F_1 ( V_12 ) ;
}
static int T_1 F_7 ( void )
{
int V_14 ;
F_8 ( V_15 > 9999 ) ;
F_9 (cpu) {
struct V_3 * V_4 = & F_10 ( V_5 , V_14 ) ;
snprintf ( V_4 -> V_16 , V_17 , L_1 , V_14 ) ;
F_11 ( V_4 -> V_16 , & V_4 -> V_8 ) ;
}
F_12 ( & V_18 ) ;
F_13 ( L_2 ) ;
return 0 ;
}
static void T_2 F_14 ( void )
{
int V_14 ;
F_9 (cpu) {
struct V_3 * V_4 = & F_10 ( V_5 , V_14 ) ;
F_15 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
memset ( V_4 -> V_16 , 0 , V_17 ) ;
}
F_16 ( & V_18 ) ;
}
