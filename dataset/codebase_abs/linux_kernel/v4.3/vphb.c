static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 < F_2 ( 64 ) ) {
F_3 ( L_1 , V_4 ) ;
return - V_5 ;
}
* ( V_2 -> V_6 . V_3 ) = V_3 ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 )
{
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , int V_10 , int type )
{
return - V_11 ;
}
static void F_6 ( struct V_1 * V_2 )
{
}
static bool F_7 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
V_15 = (struct V_14 * ) V_13 -> V_18 ;
if ( ! F_9 ( V_15 -> V_19 ) ) {
F_10 ( & V_6 -> V_6 , L_2 , V_4 ) ;
return false ;
}
F_11 ( & V_6 -> V_6 , & V_20 ) ;
F_12 ( & V_6 -> V_6 , V_21 ) ;
V_17 = F_13 ( V_6 ) ;
if ( ! V_17 )
return false ;
V_6 -> V_6 . V_22 . V_23 = V_17 ;
return ( F_14 ( V_15 ) == 0 ) ;
}
static void F_15 ( struct V_1 * V_6 )
{
struct V_16 * V_17 = F_16 ( V_6 ) ;
if ( V_17 ) {
if ( V_17 -> V_24 == V_25 ) {
F_17 ( & V_6 -> V_6 , L_3 ) ;
return;
}
V_6 -> V_6 . V_22 . V_23 = NULL ;
F_18 ( V_17 ) ;
}
}
static T_2 F_19 ( struct V_7 * V_8 ,
unsigned long type )
{
return 1 ;
}
static void F_20 ( struct V_1 * V_6 )
{
}
static int F_21 ( T_3 V_8 , T_3 V_26 )
{
return ( V_8 << 8 ) + V_26 ;
}
static unsigned long F_22 ( struct V_12 * V_13 ,
T_3 V_8 , T_3 V_26 , int V_27 )
{
int V_28 = F_21 ( V_8 , V_26 ) ;
return ( unsigned long ) V_13 -> V_29 + ( ( unsigned long ) V_13 -> V_30 * V_28 ) + V_27 ;
}
static int F_23 ( struct V_7 * V_8 , unsigned int V_26 ,
int V_27 , int V_31 ,
volatile void T_4 * * V_32 ,
T_5 * V_33 , int * V_34 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned long V_35 ;
V_13 = F_8 ( V_8 ) ;
if ( V_13 == NULL )
return V_36 ;
V_15 = (struct V_14 * ) V_13 -> V_18 ;
if ( F_21 ( V_8 -> V_37 , V_26 ) > V_15 -> V_38 )
return V_36 ;
if ( V_27 >= ( unsigned long ) V_13 -> V_30 )
return V_39 ;
V_35 = F_22 ( V_13 , V_8 -> V_37 , V_26 , V_27 ) ;
* V_32 = ( void * ) ( V_35 & ~ 0x3ULL ) ;
* V_34 = ( ( V_35 & 0x3 ) * 8 ) ;
switch ( V_31 ) {
case 1 :
* V_33 = 0xff ;
break;
case 2 :
* V_33 = 0xffff ;
break;
default:
* V_33 = 0xffffffff ;
break;
}
return 0 ;
}
static inline bool F_24 ( struct V_7 * V_8 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_8 ( V_8 ) ;
if ( V_13 == NULL )
return false ;
V_15 = (struct V_14 * ) V_13 -> V_18 ;
return F_9 ( V_15 -> V_19 ) ;
}
static int F_25 ( struct V_7 * V_8 , unsigned int V_26 ,
int V_27 , int V_31 , T_5 * V_40 )
{
volatile void T_4 * V_32 ;
int V_34 , V_41 ;
T_5 V_33 ;
V_41 = F_23 ( V_8 , V_26 , V_27 , V_31 , & V_32 ,
& V_33 , & V_34 ) ;
if ( V_41 )
return V_41 ;
if ( ! F_24 ( V_8 ) )
return V_36 ;
* V_40 = ( F_26 ( V_32 ) >> V_34 ) & V_33 ;
return V_42 ;
}
static int F_27 ( struct V_7 * V_8 , unsigned int V_26 ,
int V_27 , int V_31 , T_5 V_40 )
{
volatile void T_4 * V_32 ;
T_5 V_43 , V_33 ;
int V_34 , V_41 ;
V_41 = F_23 ( V_8 , V_26 , V_27 , V_31 , & V_32 ,
& V_33 , & V_34 ) ;
if ( V_41 )
return V_41 ;
if ( ! F_24 ( V_8 ) )
return V_36 ;
V_33 <<= V_34 ;
V_40 <<= V_34 ;
V_43 = ( F_26 ( V_32 ) & ~ V_33 ) || ( V_40 & V_33 ) ;
F_28 ( V_32 , V_43 ) ;
return V_42 ;
}
int F_29 ( struct V_14 * V_15 )
{
struct V_1 * V_44 ;
struct V_12 * V_13 , * V_45 ;
V_44 = F_30 ( V_15 -> V_19 -> V_6 . V_46 ) ;
V_45 = F_8 ( V_44 -> V_8 ) ;
V_13 = F_31 ( V_45 -> V_47 ) ;
if ( ! V_13 )
return - V_11 ;
V_13 -> V_46 = & V_44 -> V_6 ;
V_13 -> V_48 = & V_49 ;
V_13 -> V_29 = V_15 -> V_50 + V_15 -> V_51 ;
V_13 -> V_30 = ( void * ) ( T_1 ) V_15 -> V_52 ;
V_13 -> V_18 = V_15 ;
V_13 -> V_53 = V_54 ;
F_32 ( V_13 ) ;
if ( V_13 -> V_8 == NULL )
return - V_55 ;
F_33 ( V_13 -> V_8 ) ;
F_34 ( V_13 -> V_8 ) ;
V_15 -> V_13 = V_13 ;
return 0 ;
}
void F_35 ( struct V_14 * V_15 )
{
V_15 -> V_13 -> V_29 = V_15 -> V_50 + V_15 -> V_51 ;
}
void F_36 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
if ( ! V_15 || ! V_15 -> V_13 )
return;
V_13 = V_15 -> V_13 ;
F_37 ( V_13 -> V_8 ) ;
}
struct V_14 * F_38 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
return (struct V_14 * ) V_13 -> V_18 ;
}
unsigned int F_39 ( struct V_1 * V_6 )
{
return F_21 ( V_6 -> V_8 -> V_37 , V_6 -> V_26 ) ;
}
