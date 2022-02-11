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
struct V_16 * V_17 ;
T_1 * V_18 , V_19 ;
if ( ! F_4 ( V_13 , V_15 + sizeof( * V_17 ) ) )
return false ;
V_17 = (struct V_16 * ) ( V_13 -> V_20 + V_15 ) ;
if ( V_8 == V_21 ) {
V_19 = V_4 -> V_22 . V_23 . V_24 . V_25 ;
V_18 = & V_17 -> V_26 ;
} else {
V_19 = V_4 -> V_27 . V_23 . V_24 . V_25 ;
V_18 = & V_17 -> V_28 ;
}
V_2 -> V_29 ( V_13 , V_14 , & V_17 -> V_30 , V_4 , V_8 ) ;
F_5 ( & V_17 -> V_30 , V_13 , * V_18 , V_19 , 0 ) ;
if ( ! V_17 -> V_30 )
V_17 -> V_30 = V_31 ;
* V_18 = V_19 ;
return true ;
}
static int T_2 F_6 ( void )
{
int V_32 ;
V_32 = F_7 ( V_33 , & V_34 ) ;
if ( V_32 < 0 )
goto V_35;
V_32 = F_7 ( V_36 , & V_34 ) ;
if ( V_32 < 0 )
goto V_37;
return 0 ;
V_37:
F_8 ( V_33 , & V_34 ) ;
V_35:
return V_32 ;
}
static void T_3 F_9 ( void )
{
F_8 ( V_36 , & V_34 ) ;
F_8 ( V_33 , & V_34 ) ;
}
