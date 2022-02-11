static struct V_1 T_1 T_2 * F_1 (
const struct V_2 * V_3 )
{
struct V_4 V_5 [] = {
{
. V_6 = V_3 -> V_7 ,
. V_8 = V_3 -> V_7 + V_9 - 1 ,
. V_10 = V_11 ,
} , {
. V_6 = V_3 -> V_12 ,
. V_8 = V_3 -> V_12 ,
. V_10 = V_13 ,
} ,
} ;
return F_2 ( L_1 , - 1 ,
V_5 , F_3 ( V_5 ) ,
& V_3 -> V_14 , sizeof( V_3 -> V_14 ) ) ;
}
static struct V_1 T_1 T_2 * F_4 ( void )
{
return F_2 ( L_2 , - 1 , NULL , 0 , NULL , 0 ) ;
}
static int T_1 F_5 ( void )
{
struct V_1 * V_15 ;
#if F_6 ( V_16 ) || F_6 ( V_17 )
if ( F_7 () || F_8 () )
V_15 = F_4 () ;
else
#endif
#if F_6 ( V_18 )
if ( F_9 () ) {
V_19 . V_14 . V_20 = & V_21 ;
V_15 = F_1 ( & V_19 ) ;
} else
#endif
#if F_6 ( V_22 )
if ( F_10 () ) {
int V_23 = F_11 () >> 4 ;
V_24 . V_14 . V_23 = V_23 ;
if ( V_23 == 1 )
V_24 . V_14 . V_20 = & V_25 ;
else
V_24 . V_14 . V_20 = & V_26 ;
V_15 = F_1 ( & V_24 ) ;
} else
#endif
#if F_6 ( V_27 )
if ( F_12 () ) {
int V_23 = F_13 () >> 4 ;
V_28 . V_14 . V_23 = V_23 ;
if ( V_23 == 1 )
V_28 . V_14 . V_20 = & V_29 ;
else
V_28 . V_14 . V_20 = & V_30 ;
V_15 = F_1 ( & V_28 ) ;
} else
#endif
#if F_6 ( V_31 )
if ( F_14 () ) {
int V_23 = F_15 () >> 4 ;
V_32 . V_14 . V_23 = V_23 ;
V_32 . V_14 . V_20 = & V_33 ;
V_15 = F_1 ( & V_32 ) ;
} else
#endif
V_15 = F_16 ( - V_34 ) ;
if ( F_17 ( V_15 ) )
return F_18 ( V_15 ) ;
return 0 ;
}
