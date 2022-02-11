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
T_1 * V_18 , V_19 , V_20 ;
int V_21 = 8 ;
if ( V_13 -> V_22 >= V_15 + sizeof( struct V_16 ) )
V_21 = sizeof( struct V_16 ) ;
if ( ! F_4 ( V_13 , V_15 + V_21 ) )
return false ;
V_17 = (struct V_16 * ) ( V_13 -> V_23 + V_15 ) ;
if ( V_8 == V_24 ) {
V_20 = V_4 -> V_25 . V_26 . V_27 . V_28 ;
V_18 = & V_17 -> V_29 ;
} else {
V_20 = V_4 -> V_30 . V_26 . V_27 . V_28 ;
V_18 = & V_17 -> V_31 ;
}
V_19 = * V_18 ;
* V_18 = V_20 ;
if ( V_21 < sizeof( * V_17 ) )
return true ;
V_2 -> V_32 ( V_13 , V_14 , & V_17 -> V_33 ,
V_4 , V_8 ) ;
F_5 ( & V_17 -> V_33 , V_13 , V_19 , V_20 ,
0 ) ;
return true ;
}
static int T_2 F_6 ( void )
{
int V_34 ;
V_34 = F_7 ( V_35 , & V_36 ) ;
if ( V_34 < 0 )
goto V_37;
V_34 = F_7 ( V_38 , & V_36 ) ;
if ( V_34 < 0 )
goto V_39;
return 0 ;
V_39:
F_8 ( V_35 , & V_36 ) ;
V_37:
return V_34 ;
}
static void T_3 F_9 ( void )
{
F_8 ( V_38 , & V_36 ) ;
F_8 ( V_35 , & V_36 ) ;
}
