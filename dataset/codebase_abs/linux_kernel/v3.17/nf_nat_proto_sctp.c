static void
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_7 V_8 ,
const struct V_9 * V_10 )
{
F_2 ( V_2 , V_4 , V_6 , V_8 , V_10 ,
& V_11 ) ;
}
static bool
F_3 ( struct V_12 * V_13 ,
const struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_15 ,
const struct V_3 * V_4 ,
enum V_7 V_8 )
{
T_1 * V_16 ;
if ( ! F_4 ( V_13 , V_15 + sizeof( * V_16 ) ) )
return false ;
V_16 = (struct V_17 * ) ( V_13 -> V_18 + V_15 ) ;
if ( V_8 == V_19 ) {
V_16 -> V_20 = V_4 -> V_21 . V_22 . V_23 . V_24 ;
} else {
V_16 -> V_25 = V_4 -> V_26 . V_22 . V_23 . V_24 ;
}
V_16 -> V_27 = F_5 ( V_13 , V_15 ) ;
return true ;
}
static int T_2 F_6 ( void )
{
int V_28 ;
V_28 = F_7 ( V_29 , & V_30 ) ;
if ( V_28 < 0 )
goto V_31;
V_28 = F_7 ( V_32 , & V_30 ) ;
if ( V_28 < 0 )
goto V_33;
return 0 ;
V_33:
F_8 ( V_29 , & V_30 ) ;
V_31:
return V_28 ;
}
static void T_3 F_9 ( void )
{
F_8 ( V_32 , & V_30 ) ;
F_8 ( V_29 , & V_30 ) ;
}
