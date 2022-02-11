static void F_1 ( int V_1 )
{
if ( V_1 ) {
V_2 |= ( 1 << 1 ) ;
} else {
V_2 &= ~ ( 1 << 1 ) ;
}
}
static void F_2 ( int V_1 )
{
if ( V_1 ) {
V_2 |= ( 1 << 2 ) ;
} else {
V_2 &= ~ ( 1 << 2 ) ;
}
}
static void F_3 ( int V_1 , struct V_3 * V_4 )
{
if ( V_1 ) {
V_2 |= ( 1 << 0 ) ;
} else {
V_2 &= ~ ( 1 << 0 ) ;
}
F_2 ( V_1 ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( L_1 ) ;
F_6 ( F_7 ( V_5 ) ) ;
F_8 ( NULL ) ;
F_9 ( NULL ) ;
F_10 ( NULL ) ;
F_11 ( & V_6 ) ;
F_12 ( NULL , & V_7 ) ;
F_13 ( & V_8 ) ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_16 ( V_9 , F_17 ( V_9 ) ) ;
}
static void F_18 ( struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_14 * V_15 = F_19 ( V_11 ,
struct V_14 , V_11 ) ;
T_2 V_16 = V_17 ;
if ( V_13 != V_18 )
V_16 &= ~ V_15 -> V_19 ;
else
V_16 |= V_15 -> V_19 ;
V_17 = V_16 ;
}
static enum V_12 F_20 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_19 ( V_11 ,
struct V_14 , V_11 ) ;
return ( V_17 & V_15 -> V_19 ) ? V_18 : V_20 ;
}
static int T_1 F_21 ( void )
{
int V_21 ;
if ( ! F_22 () )
return - V_22 ;
for ( V_21 = 0 ; V_21 < F_17 ( V_23 ) ; V_21 ++ ) {
struct V_14 * V_15 ;
V_15 = F_23 ( sizeof( * V_15 ) , V_24 ) ;
if ( ! V_15 )
break;
V_15 -> V_11 . V_25 = V_23 [ V_21 ] . V_25 ;
V_15 -> V_11 . V_26 = F_18 ;
V_15 -> V_11 . V_27 = F_20 ;
V_15 -> V_11 . V_28 = V_23 [ V_21 ] . V_29 ;
if ( V_21 == 0 )
V_15 -> V_19 = V_30 ;
else
V_15 -> V_19 = V_31 ;
if ( F_24 ( NULL , & V_15 -> V_11 ) < 0 ) {
F_25 ( V_15 ) ;
break;
}
}
return 0 ;
}
