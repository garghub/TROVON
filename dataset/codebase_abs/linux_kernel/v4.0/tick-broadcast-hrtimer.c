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
int V_8 ;
F_4 ( V_8 = ( F_2 ( & V_6 ) >= 0 ) ?
! F_5 ( & V_6 , V_7 , V_9 ) :
0 ) ;
if ( V_8 ) {
V_4 -> V_10 = F_6 () ;
} else if ( V_4 -> V_10 == F_6 () ) {
F_7 ( & V_6 , V_7 ) ;
}
return 0 ;
}
static enum V_11 F_8 ( struct V_12 * V_13 )
{
V_14 . V_15 ( & V_14 ) ;
if ( V_14 . V_16 . V_17 == V_18 )
return V_19 ;
return V_20 ;
}
void F_9 ( void )
{
F_10 ( & V_6 , V_21 , V_22 ) ;
V_6 . V_23 = F_8 ;
F_11 ( & V_14 ) ;
}
