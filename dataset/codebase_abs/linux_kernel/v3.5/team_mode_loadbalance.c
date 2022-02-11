static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return (struct V_1 * ) & V_2 -> V_3 ;
}
static bool F_1 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
int V_11 ;
V_7 = F_2 ( V_1 ( V_2 ) -> V_7 ) ;
if ( F_3 ( ! V_7 ) )
goto V_12;
V_10 = F_4 ( V_7 , V_5 ) ;
V_11 = V_10 % V_2 -> V_13 ;
V_9 = F_5 ( V_2 , V_11 ) ;
if ( F_3 ( ! V_9 ) )
goto V_12;
V_5 -> V_14 = V_9 -> V_14 ;
if ( F_6 ( V_5 ) )
return false ;
return true ;
V_12:
F_7 ( V_5 ) ;
return false ;
}
static int F_8 ( struct V_2 * V_2 , struct V_15 * V_16 )
{
if ( ! V_1 ( V_2 ) -> V_17 ) {
V_16 -> V_18 . V_19 . V_20 = 0 ;
V_16 -> V_18 . V_19 . V_21 = NULL ;
return 0 ;
}
V_16 -> V_18 . V_19 . V_20 = V_1 ( V_2 ) -> V_17 -> V_20 *
sizeof( struct V_22 ) ;
V_16 -> V_18 . V_19 . V_21 = V_1 ( V_2 ) -> V_17 -> V_23 ;
return 0 ;
}
static int F_9 ( struct V_24 * * V_25 , T_1 V_26 ,
const void * V_18 )
{
struct V_24 * V_27 ;
struct V_22 * V_23 = (struct V_22 * ) V_18 ;
if ( V_26 % sizeof( struct V_22 ) )
return - V_28 ;
V_27 = F_10 ( sizeof( struct V_24 ) , V_29 ) ;
if ( ! V_27 )
return - V_30 ;
V_27 -> V_23 = F_11 ( V_23 , V_26 , V_29 ) ;
if ( ! V_27 -> V_23 ) {
F_12 ( V_27 ) ;
return - V_30 ;
}
V_27 -> V_20 = V_26 / sizeof( struct V_22 ) ;
* V_25 = V_27 ;
return 0 ;
}
static void F_13 ( struct V_24 * V_27 )
{
F_12 ( V_27 -> V_23 ) ;
F_12 ( V_27 ) ;
}
static int F_14 ( struct V_2 * V_2 , struct V_15 * V_16 )
{
struct V_6 * V_7 = NULL ;
struct V_24 * V_27 = NULL ;
int V_31 ;
if ( V_16 -> V_18 . V_19 . V_20 ) {
V_31 = F_9 ( & V_27 , V_16 -> V_18 . V_19 . V_20 ,
V_16 -> V_18 . V_19 . V_21 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_15 ( & V_7 , V_27 ) ;
if ( V_31 ) {
F_13 ( V_27 ) ;
return V_31 ;
}
}
if ( V_1 ( V_2 ) -> V_17 ) {
F_13 ( V_1 ( V_2 ) -> V_17 ) ;
F_16 ( V_1 ( V_2 ) -> V_7 ) ;
}
F_17 ( V_1 ( V_2 ) -> V_7 , V_7 ) ;
V_1 ( V_2 ) -> V_17 = V_27 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_2 )
{
return F_19 ( V_2 , V_32 ,
F_20 ( V_32 ) ) ;
}
static void F_21 ( struct V_2 * V_2 )
{
F_22 ( V_2 , V_32 ,
F_20 ( V_32 ) ) ;
}
static int T_2 F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
