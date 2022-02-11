static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
return 0 ;
}
static int F_3 ( T_1 V_4 , struct V_1 * V_5 )
{
int V_6 ;
F_4 ({
bc_moved = hrtimer_try_to_cancel(&bctimer) >= 0;
if (bc_moved)
hrtimer_start(&bctimer, expires,
HRTIMER_MODE_ABS_PINNED);}) ;
if ( V_6 ) {
V_5 -> V_7 = F_5 () ;
} else if ( V_5 -> V_7 == F_5 () ) {
F_6 ( & V_3 , V_4 ) ;
}
return 0 ;
}
static enum V_8 F_7 ( struct V_9 * V_10 )
{
V_11 . V_12 ( & V_11 ) ;
if ( F_8 ( & V_11 ) )
if ( V_11 . V_13 != V_14 )
return V_15 ;
return V_16 ;
}
void F_9 ( void )
{
F_10 ( & V_3 , V_17 , V_18 ) ;
V_3 . V_19 = F_7 ;
F_11 ( & V_11 ) ;
}
