static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
struct V_5 V_14 ;
V_13 = F_2 ( V_2 , & V_9 ) ;
F_3 ( V_13 && ( V_9 == V_15 || V_9 == V_16 ||
V_9 == V_17 ) ) ;
if ( F_4 ( F_5 ( V_4 -> V_18 ) , V_4 -> V_18 ,
& F_6 ( V_2 ) -> V_19 , 0 , & V_11 ) < 0 )
return V_20 ;
F_7 ( V_13 ) -> V_21 = V_4 -> V_18 -> V_22 ;
V_14 . V_23 = V_6 -> V_23 | V_24 ;
V_14 . V_25 . V_26 = V_11 ;
V_14 . V_27 . V_26 = V_11 ;
V_14 . V_28 = V_6 -> V_28 ;
V_14 . V_29 = V_6 -> V_29 ;
return F_8 ( V_13 , & V_14 , V_30 ) ;
}
static int F_9 ( const struct V_31 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_23 & V_24 )
return - V_32 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , void * V_22 )
{
const struct V_33 * V_34 = F_7 ( V_13 ) ;
if ( ! V_34 )
return 0 ;
if ( F_11 ( V_13 ) != V_35 )
return 0 ;
return V_34 -> V_21 == ( int ) ( long ) V_22 ;
}
static int F_12 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
const struct V_40 * V_41 = V_39 ;
struct V_42 * V_42 = F_5 ( V_41 ) ;
if ( V_38 == V_43 )
F_13 ( V_42 , F_10 ,
( void * ) ( long ) V_41 -> V_22 ) ;
return V_44 ;
}
static int F_14 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
struct V_45 * V_46 = V_39 ;
return F_12 ( V_37 , V_38 , V_46 -> V_47 -> V_41 ) ;
}
static int T_1 F_15 ( void )
{
int V_48 ;
V_48 = F_16 ( & V_49 ) ;
if ( V_48 == 0 ) {
F_17 ( & V_50 ) ;
F_18 ( & V_51 ) ;
}
return V_48 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_51 ) ;
F_21 ( & V_50 ) ;
F_22 ( & V_49 ) ;
}
