static int F_1 ( unsigned long V_1 )
{
struct V_2 V_3 = {
. V_4 = V_5 ,
. V_1 = V_1 ,
} ;
int V_6 ;
if ( F_2 ( V_7 , & V_3 ) )
return - V_8 ;
switch ( V_3 . V_9 ) {
case V_10 :
V_6 = 0 ;
break;
case V_11 :
case V_12 :
default:
V_6 = 1 ;
break;
}
return V_6 ;
}
static void F_3 ( struct V_13 * V_14 )
{
struct V_15 V_3 ;
int V_16 ;
V_3 . V_4 = V_5 ;
V_3 . V_17 = F_4 ( V_14 -> V_18 ) ;
V_16 = F_2 ( V_19 , & V_3 ) ;
F_5 ( V_16 < 0 ) ;
}
static int F_6 ( void )
{
struct V_15 V_3 ;
int V_16 = 0 ;
V_3 . V_4 = V_5 ;
V_3 . V_17 = 0x00 ;
V_16 = F_2 ( V_19 , & V_3 ) ;
if ( V_16 < 0 ) {
F_7 ( V_20 L_1 ) ;
return 0 ;
}
return 1 ;
}
void T_1 F_8 ( void )
{
if ( F_6 () )
V_21 . V_22 = F_3 ;
#ifdef F_9
F_10 ( & F_1 ) ;
#endif
}
