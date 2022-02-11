static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 || ! V_3 -> V_4 )
return NULL ;
return (struct V_1 * ) V_3 -> V_4 ;
}
static inline int F_2 ( struct V_1 * V_5 )
{
T_1 V_6 ;
V_6 = F_3 ( V_5 -> V_7 + V_8 ) ;
return F_4 ( V_6 ) ;
}
static inline int F_5 ( struct V_1 * V_5 )
{
T_1 V_6 ;
V_6 = F_3 ( V_5 -> V_7 + V_8 ) ;
return F_6 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_5 , bool V_9 )
{
T_1 V_10 ;
V_10 = F_3 ( V_5 -> V_7 + V_11 ) ;
if ( V_9 )
V_10 |= V_12 ;
else
V_10 &= ~ V_12 ;
F_8 ( V_10 , V_5 -> V_7 + V_11 ) ;
}
static void F_9 ( struct V_1 * V_5 , bool V_9 )
{
T_1 V_10 ;
V_10 = F_3 ( V_5 -> V_7 + V_11 ) ;
if ( V_9 )
V_10 |= V_13 ;
else
V_10 &= ~ V_13 ;
F_8 ( V_10 , V_5 -> V_7 + V_11 ) ;
}
static bool F_10 ( struct V_1 * V_5 )
{
T_1 V_14 ;
#define F_11 0xA5A5AA55
F_8 ( F_11 , V_5 -> V_7 + V_15 ) ;
V_14 = F_3 ( V_5 -> V_7 + V_15 ) ;
if ( V_14 == F_11 ) {
F_8 ( 0 , V_5 -> V_7 + V_15 ) ;
return true ;
}
return false ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_16 [ 2 ] ;
if ( F_5 ( V_5 ) ) {
V_16 [ V_17 ] =
F_3 ( V_5 -> V_7 + V_15 ) ;
V_16 [ V_18 ] =
F_3 ( V_5 -> V_7 + V_19 ) ;
F_13 ( V_3 , ( void * ) V_16 ) ;
}
}
static void F_14 ( unsigned long V_16 )
{
struct V_2 * V_3 = (struct V_2 * ) V_16 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_12 ( V_3 ) ;
F_15 ( & V_5 -> V_20 ,
V_21 + F_16 ( V_22 ) ) ;
}
static T_2 F_17 ( int V_23 , void * V_24 )
{
struct V_2 * V_3 = (struct V_2 * ) V_24 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_9 ( V_5 , false ) ;
F_18 ( V_3 , 0 ) ;
return V_25 ;
}
static T_2 F_19 ( int V_23 , void * V_24 )
{
struct V_2 * V_3 = (struct V_2 * ) V_24 ;
F_12 ( V_3 ) ;
return V_25 ;
}
static int F_20 ( struct V_2 * V_3 )
{
int V_26 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_27 ) {
V_26 = F_21 ( V_5 -> V_23 , F_17 , 0 ,
V_28 , V_3 ) ;
if ( F_22 ( V_26 ) ) {
F_23 ( V_5 -> V_29 ,
L_1 ,
V_26 ) ;
return V_26 ;
}
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_26 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_27 ) {
V_26 = F_21 ( V_5 -> V_23 , F_19 , 0 ,
V_28 , V_3 ) ;
if ( F_22 ( V_26 ) ) {
V_5 -> V_27 = false ;
goto V_30;
}
F_7 ( V_5 , true ) ;
return 0 ;
}
V_30:
F_25 ( & V_5 -> V_20 , F_14 ,
( unsigned long ) V_3 ) ;
F_15 ( & V_5 -> V_20 ,
V_21 + F_16 ( V_22 ) ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , void * V_16 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 * V_31 = ( T_1 * ) V_16 ;
if ( ! V_5 || ! V_16 )
return - V_32 ;
if ( ! V_5 -> V_33 ) {
F_27 ( V_5 -> V_29 ,
L_2 ) ;
return - V_32 ;
}
if ( F_2 ( V_5 ) )
return - V_34 ;
if ( V_5 -> V_27 )
F_9 ( V_5 , true ) ;
F_8 ( V_31 [ V_17 ] , V_5 -> V_7 + V_15 ) ;
F_8 ( V_31 [ V_18 ] , V_5 -> V_7 + V_19 ) ;
return 0 ;
}
static bool F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_2 ( V_5 ) ? false : true ;
}
static bool F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_5 ( V_5 ) ? true : false ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_26 = 0 ;
if ( ! V_5 )
return - V_32 ;
if ( V_5 -> V_33 )
V_26 = F_20 ( V_3 ) ;
else
V_26 = F_24 ( V_3 ) ;
return V_26 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_27 ) {
F_8 ( ~ 0 , V_5 -> V_7 + V_11 ) ;
F_32 ( V_5 -> V_23 , V_3 ) ;
} else if ( ! V_5 -> V_33 ) {
F_33 ( & V_5 -> V_20 ) ;
}
}
static int F_34 ( struct V_35 * V_36 )
{
struct V_1 * V_5 ;
struct V_37 * V_38 ;
struct V_2 * V_39 ;
int V_26 ;
V_5 = F_35 ( & V_36 -> V_29 , sizeof( * V_5 ) ,
V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_39 = F_35 ( & V_36 -> V_29 , sizeof( * V_39 ) , V_40 ) ;
if ( ! V_39 )
return - V_41 ;
V_38 = F_36 ( V_36 , V_42 , 0 ) ;
V_5 -> V_7 = F_37 ( & V_36 -> V_29 , V_38 ) ;
if ( F_38 ( V_5 -> V_7 ) )
return F_39 ( V_5 -> V_7 ) ;
V_5 -> V_33 = F_10 ( V_5 ) ;
V_5 -> V_23 = F_40 ( V_36 , 0 ) ;
if ( V_5 -> V_23 >= 0 )
V_5 -> V_27 = true ;
V_5 -> V_29 = & V_36 -> V_29 ;
V_39 [ 0 ] . V_4 = V_5 ;
V_5 -> V_43 . V_29 = V_5 -> V_29 ;
V_5 -> V_43 . V_44 = 1 ;
V_5 -> V_43 . V_39 = V_39 ;
V_5 -> V_43 . V_45 = & V_46 ;
if ( V_5 -> V_33 ) {
if ( V_5 -> V_27 ) {
V_5 -> V_43 . V_47 = true ;
} else {
V_5 -> V_43 . V_48 = true ;
V_5 -> V_43 . V_49 = V_22 ;
}
}
V_26 = F_41 ( & V_5 -> V_43 ) ;
if ( V_26 ) {
F_23 ( & V_36 -> V_29 , L_3 ) ;
goto V_50;
}
F_42 ( V_36 , V_5 ) ;
V_50:
return V_26 ;
}
static int F_43 ( struct V_35 * V_36 )
{
struct V_1 * V_5 = F_44 ( V_36 ) ;
if ( ! V_5 )
return - V_32 ;
F_45 ( & V_5 -> V_43 ) ;
return 0 ;
}
