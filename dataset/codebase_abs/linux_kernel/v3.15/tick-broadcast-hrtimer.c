static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
switch ( V_2 ) {
case V_5 :
F_2 ( & V_6 ) ;
break;
default:
break;
}
}
static int F_3 ( T_1 V_7 , struct V_3 * V_4 )
{
if ( F_2 ( & V_6 ) >= 0 ) {
F_4 ( & V_6 , V_7 , V_8 ) ;
V_4 -> V_9 = F_5 () ;
} else if ( V_4 -> V_9 == F_5 () ) {
F_6 ( & V_6 , V_7 ) ;
}
return 0 ;
}
static enum V_10 F_7 ( struct V_11 * V_12 )
{
V_13 . V_14 ( & V_13 ) ;
if ( V_13 . V_15 . V_16 == V_17 )
return V_18 ;
return V_19 ;
}
void F_8 ( void )
{
F_9 ( & V_6 , V_20 , V_21 ) ;
V_6 . V_22 = F_7 ;
F_10 ( & V_13 ) ;
}
