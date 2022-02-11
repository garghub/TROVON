void F_1 ( enum V_1 V_2 )
{
struct V_3 * V_4 = F_2 ( & V_5 ) ;
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
static int F_7 ( unsigned int V_14 )
{
F_1 ( V_7 ) ;
return 0 ;
}
static int F_8 ( unsigned int V_14 )
{
F_1 ( V_11 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
int V_14 ;
int V_15 ;
F_10 ( V_16 > 9999 ) ;
F_11 (cpu) {
struct V_3 * V_4 = & F_12 ( V_5 , V_14 ) ;
snprintf ( V_4 -> V_17 , V_18 , L_1 , V_14 ) ;
F_13 ( V_4 -> V_17 , & V_4 -> V_8 ) ;
}
F_14 ( & V_19 ) ;
V_15 = F_15 ( V_20 , L_2 ,
F_7 , F_8 ) ;
if ( V_15 < 0 )
F_16 ( L_3 ,
V_15 ) ;
F_17 ( L_4 ) ;
return 0 ;
}
