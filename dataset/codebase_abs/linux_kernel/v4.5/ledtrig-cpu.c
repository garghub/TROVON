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
static int F_7 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
switch ( V_16 & ~ V_18 ) {
case V_19 :
F_1 ( V_7 ) ;
break;
case V_20 :
F_1 ( V_11 ) ;
break;
}
return V_21 ;
}
static int T_1 F_8 ( void )
{
int V_22 ;
F_9 ( V_23 > 9999 ) ;
F_10 (cpu) {
struct V_3 * V_4 = & F_11 ( V_5 , V_22 ) ;
snprintf ( V_4 -> V_24 , V_25 , L_1 , V_22 ) ;
F_12 ( V_4 -> V_24 , & V_4 -> V_8 ) ;
}
F_13 ( & V_26 ) ;
F_14 ( & V_27 ) ;
F_15 ( L_2 ) ;
return 0 ;
}
