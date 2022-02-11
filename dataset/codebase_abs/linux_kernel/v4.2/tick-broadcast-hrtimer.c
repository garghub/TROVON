static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
switch ( V_2 ) {
case V_5 :
case V_6 :
F_2 ( & V_7 ) ;
break;
default:
break;
}
}
static int F_3 ( T_1 V_8 , struct V_3 * V_4 )
{
int V_9 ;
F_4 ({
bc_moved = hrtimer_try_to_cancel(&bctimer) >= 0;
if (bc_moved)
hrtimer_start(&bctimer, expires,
HRTIMER_MODE_ABS_PINNED);}) ;
if ( V_9 ) {
V_4 -> V_10 = F_5 () ;
} else if ( V_4 -> V_10 == F_5 () ) {
F_6 ( & V_7 , V_8 ) ;
}
return 0 ;
}
static enum V_11 F_7 ( struct V_12 * V_13 )
{
V_14 . V_15 ( & V_14 ) ;
switch ( V_14 . V_2 ) {
case V_16 :
if ( V_14 . V_17 . V_18 != V_19 )
return V_20 ;
default:
return V_21 ;
}
}
void F_8 ( void )
{
F_9 ( & V_7 , V_22 , V_23 ) ;
V_7 . V_24 = F_7 ;
F_10 ( & V_14 ) ;
}
