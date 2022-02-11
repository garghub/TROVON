static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
const struct V_8 * V_9 ;
T_1 V_10 ;
T_2 V_11 , V_12 ;
T_3 V_13 ;
int V_14 ;
if ( V_2 -> V_15 < sizeof( struct V_8 ) ||
F_2 ( V_2 ) < sizeof( struct V_8 ) )
return V_16 ;
V_13 = V_2 -> V_13 ;
V_9 = F_3 ( V_2 ) ;
V_11 = V_9 -> V_11 ;
V_12 = V_9 -> V_12 ;
V_10 = V_9 -> V_10 ;
V_7 = F_4 ( V_2 , V_17 , V_4 ,
F_5 ( V_6 ) -> V_18 . V_19 ) ;
if ( V_7 != V_20 && V_7 != V_21 ) {
V_9 = F_3 ( V_2 ) ;
if ( V_9 -> V_11 != V_11 ||
V_9 -> V_12 != V_12 ||
V_2 -> V_13 != V_13 ||
V_9 -> V_10 != V_10 ) {
V_14 = F_6 ( V_2 , V_22 ) ;
if ( V_14 < 0 )
V_7 = F_7 ( V_14 ) ;
}
}
return V_7 ;
}
static unsigned int
F_8 ( const struct V_23 * V_24 ,
struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_24 -> V_25 == V_17 )
return F_1 ( V_2 , V_4 ) ;
if ( V_24 -> V_25 == V_26 )
return F_4 ( V_2 , V_24 -> V_25 , V_4 ,
F_5 ( V_4 -> V_6 ) -> V_18 . V_19 ) ;
return F_4 ( V_2 , V_24 -> V_25 , V_4 ,
F_5 ( V_4 -> V_27 ) -> V_18 . V_19 ) ;
}
static int T_4 F_9 ( struct V_28 * V_28 )
{
struct V_29 * V_30 ;
V_30 = F_10 ( & V_31 ) ;
if ( V_30 == NULL )
return - V_32 ;
V_28 -> V_18 . V_19 =
F_11 ( V_28 , & V_31 , V_30 ) ;
F_12 ( V_30 ) ;
return F_13 ( V_28 -> V_18 . V_19 ) ;
}
static void T_5 F_14 ( struct V_28 * V_28 )
{
F_15 ( V_28 , V_28 -> V_18 . V_19 ) ;
}
static int T_6 F_16 ( void )
{
int V_7 ;
V_7 = F_17 ( & V_33 ) ;
if ( V_7 < 0 )
return V_7 ;
V_34 = F_18 ( & V_31 , F_8 ) ;
if ( F_19 ( V_34 ) ) {
V_7 = F_20 ( V_34 ) ;
F_21 ( & V_33 ) ;
}
return V_7 ;
}
static void T_7 F_22 ( void )
{
F_23 ( & V_31 , V_34 ) ;
F_21 ( & V_33 ) ;
}
