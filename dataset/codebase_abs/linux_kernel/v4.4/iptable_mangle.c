static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned int V_5 ;
const struct V_6 * V_7 ;
T_1 V_8 ;
T_2 V_9 , V_10 ;
T_3 V_11 ;
int V_12 ;
if ( V_2 -> V_13 < sizeof( struct V_6 ) ||
F_2 ( V_2 ) < sizeof( struct V_6 ) )
return V_14 ;
V_11 = V_2 -> V_11 ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_7 -> V_9 ;
V_10 = V_7 -> V_10 ;
V_8 = V_7 -> V_8 ;
V_5 = F_4 ( V_2 , V_4 , V_4 -> V_15 -> V_16 . V_17 ) ;
if ( V_5 != V_18 && V_5 != V_19 ) {
V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_9 != V_9 ||
V_7 -> V_10 != V_10 ||
V_2 -> V_11 != V_11 ||
V_7 -> V_8 != V_8 ) {
V_12 = F_5 ( V_4 -> V_15 , V_2 , V_20 ) ;
if ( V_12 < 0 )
V_5 = F_6 ( V_12 ) ;
}
}
return V_5 ;
}
static unsigned int
F_7 ( void * V_21 ,
struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
if ( V_4 -> V_22 == V_23 )
return F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_22 == V_24 )
return F_4 ( V_2 , V_4 ,
V_4 -> V_15 -> V_16 . V_17 ) ;
return F_4 ( V_2 , V_4 , V_4 -> V_15 -> V_16 . V_17 ) ;
}
static int T_4 F_8 ( struct V_15 * V_15 )
{
struct V_25 * V_26 ;
V_26 = F_9 ( & V_27 ) ;
if ( V_26 == NULL )
return - V_28 ;
V_15 -> V_16 . V_17 =
F_10 ( V_15 , & V_27 , V_26 ) ;
F_11 ( V_26 ) ;
return F_12 ( V_15 -> V_16 . V_17 ) ;
}
static void T_5 F_13 ( struct V_15 * V_15 )
{
F_14 ( V_15 , V_15 -> V_16 . V_17 ) ;
}
static int T_6 F_15 ( void )
{
int V_5 ;
V_5 = F_16 ( & V_29 ) ;
if ( V_5 < 0 )
return V_5 ;
V_30 = F_17 ( & V_27 , F_7 ) ;
if ( F_18 ( V_30 ) ) {
V_5 = F_19 ( V_30 ) ;
F_20 ( & V_29 ) ;
}
return V_5 ;
}
static void T_7 F_21 ( void )
{
F_22 ( & V_27 , V_30 ) ;
F_20 ( & V_29 ) ;
}
