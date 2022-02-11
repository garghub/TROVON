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
V_5 = F_4 ( V_2 , V_15 , NULL , V_4 ,
F_5 ( V_4 ) -> V_16 . V_17 ) ;
if ( V_5 != V_18 && V_5 != V_19 ) {
V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_9 != V_9 ||
V_7 -> V_10 != V_10 ||
V_2 -> V_11 != V_11 ||
V_7 -> V_8 != V_8 ) {
V_12 = F_6 ( V_2 , V_20 ) ;
if ( V_12 < 0 )
V_5 = F_7 ( V_12 ) ;
}
}
return V_5 ;
}
static unsigned int
F_8 ( const struct V_21 * V_22 ,
struct V_1 * V_2 ,
const struct V_3 * V_23 ,
const struct V_3 * V_4 ,
int (* F_9)( struct V_1 * ) )
{
if ( V_22 -> V_24 == V_15 )
return F_1 ( V_2 , V_4 ) ;
if ( V_22 -> V_24 == V_25 )
return F_4 ( V_2 , V_22 -> V_24 , V_23 , V_4 ,
F_5 ( V_4 ) -> V_16 . V_17 ) ;
return F_4 ( V_2 , V_22 -> V_24 , V_23 , V_4 ,
F_5 ( V_23 ) -> V_16 . V_17 ) ;
}
static int T_4 F_10 ( struct V_26 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_11 ( & V_29 ) ;
if ( V_28 == NULL )
return - V_30 ;
V_26 -> V_16 . V_17 =
F_12 ( V_26 , & V_29 , V_28 ) ;
F_13 ( V_28 ) ;
return F_14 ( V_26 -> V_16 . V_17 ) ;
}
static void T_5 F_15 ( struct V_26 * V_26 )
{
F_16 ( V_26 , V_26 -> V_16 . V_17 ) ;
}
static int T_6 F_17 ( void )
{
int V_5 ;
V_5 = F_18 ( & V_31 ) ;
if ( V_5 < 0 )
return V_5 ;
V_32 = F_19 ( & V_29 , F_8 ) ;
if ( F_20 ( V_32 ) ) {
V_5 = F_21 ( V_32 ) ;
F_22 ( & V_31 ) ;
}
return V_5 ;
}
static void T_7 F_23 ( void )
{
F_24 ( & V_29 , V_32 ) ;
F_22 ( & V_31 ) ;
}
