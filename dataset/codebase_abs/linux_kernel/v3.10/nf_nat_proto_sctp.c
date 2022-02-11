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
struct V_12 * V_16 ;
T_1 * V_17 ;
T_2 V_18 ;
if ( ! F_4 ( V_13 , V_15 + sizeof( * V_17 ) ) )
return false ;
V_17 = (struct V_19 * ) ( V_13 -> V_20 + V_15 ) ;
if ( V_8 == V_21 ) {
V_17 -> V_22 = V_4 -> V_23 . V_24 . V_25 . V_26 ;
} else {
V_17 -> V_27 = V_4 -> V_28 . V_24 . V_25 . V_26 ;
}
V_18 = F_5 ( ( V_29 * ) V_17 , F_6 ( V_13 ) - V_15 ) ;
F_7 (skb, frag)
V_18 = F_8 ( ( V_29 * ) V_16 -> V_20 , F_6 ( V_16 ) ,
V_18 ) ;
V_17 -> V_30 = F_9 ( V_18 ) ;
return true ;
}
static int T_3 F_10 ( void )
{
int V_31 ;
V_31 = F_11 ( V_32 , & V_33 ) ;
if ( V_31 < 0 )
goto V_34;
V_31 = F_11 ( V_35 , & V_33 ) ;
if ( V_31 < 0 )
goto V_36;
return 0 ;
V_36:
F_12 ( V_32 , & V_33 ) ;
V_34:
return V_31 ;
}
static void T_4 F_13 ( void )
{
F_12 ( V_35 , & V_33 ) ;
F_12 ( V_32 , & V_33 ) ;
}
