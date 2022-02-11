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
F_9 ( & V_6 -> V_6 , & V_19 ) ;
F_10 ( & V_6 -> V_6 , V_20 ) ;
V_17 = F_11 ( V_6 ) ;
if ( ! V_17 )
return false ;
V_6 -> V_6 . V_21 . V_22 = V_17 ;
return ( F_12 ( V_15 ) == 0 ) ;
}
static void F_13 ( struct V_1 * V_6 )
{
struct V_16 * V_17 = F_14 ( V_6 ) ;
if ( V_17 ) {
if ( V_17 -> V_23 == V_24 ) {
F_15 ( & V_6 -> V_6 , L_2 ) ;
return;
}
V_6 -> V_6 . V_21 . V_22 = NULL ;
F_16 ( V_17 ) ;
}
}
static T_2 F_17 ( struct V_7 * V_8 ,
unsigned long type )
{
return 1 ;
}
static void F_18 ( struct V_1 * V_6 )
{
}
static int F_19 ( T_3 V_8 , T_3 V_25 )
{
return ( V_8 << 8 ) + V_25 ;
}
static unsigned long F_20 ( struct V_12 * V_13 ,
T_3 V_8 , T_3 V_25 , int V_26 )
{
int V_27 = F_19 ( V_8 , V_25 ) ;
return ( unsigned long ) V_13 -> V_28 + ( ( unsigned long ) V_13 -> V_29 * V_27 ) + V_26 ;
}
static int F_21 ( struct V_7 * V_8 , unsigned int V_25 ,
int V_26 , int V_30 ,
volatile void T_4 * * V_31 ,
T_5 * V_32 , int * V_33 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned long V_34 ;
V_13 = F_8 ( V_8 ) ;
if ( V_13 == NULL )
return V_35 ;
V_15 = (struct V_14 * ) V_13 -> V_18 ;
if ( F_19 ( V_8 -> V_36 , V_25 ) > V_15 -> V_37 )
return V_35 ;
if ( V_26 >= ( unsigned long ) V_13 -> V_29 )
return V_38 ;
V_34 = F_20 ( V_13 , V_8 -> V_36 , V_25 , V_26 ) ;
* V_31 = ( void * ) ( V_34 & ~ 0x3ULL ) ;
* V_33 = ( ( V_34 & 0x3 ) * 8 ) ;
switch ( V_30 ) {
case 1 :
* V_32 = 0xff ;
break;
case 2 :
* V_32 = 0xffff ;
break;
default:
* V_32 = 0xffffffff ;
break;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_8 , unsigned int V_25 ,
int V_26 , int V_30 , T_5 * V_39 )
{
volatile void T_4 * V_31 ;
int V_33 , V_40 ;
T_5 V_32 ;
V_40 = F_21 ( V_8 , V_25 , V_26 , V_30 , & V_31 ,
& V_32 , & V_33 ) ;
if ( V_40 )
return V_40 ;
* V_39 = ( F_23 ( V_31 ) >> V_33 ) & V_32 ;
return V_41 ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_25 ,
int V_26 , int V_30 , T_5 V_39 )
{
volatile void T_4 * V_31 ;
T_5 V_42 , V_32 ;
int V_33 , V_40 ;
V_40 = F_21 ( V_8 , V_25 , V_26 , V_30 , & V_31 ,
& V_32 , & V_33 ) ;
if ( V_40 )
return V_40 ;
V_32 <<= V_33 ;
V_39 <<= V_33 ;
V_42 = ( F_23 ( V_31 ) & ~ V_32 ) || ( V_39 & V_32 ) ;
F_25 ( V_31 , V_42 ) ;
return V_41 ;
}
int F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_43 ;
struct V_12 * V_13 , * V_44 ;
V_43 = F_27 ( V_15 -> V_45 -> V_6 . V_46 ) ;
V_44 = F_8 ( V_43 -> V_8 ) ;
V_13 = F_28 ( V_44 -> V_47 ) ;
if ( ! V_13 )
return - V_11 ;
V_13 -> V_46 = & V_43 -> V_6 ;
V_13 -> V_48 = & V_49 ;
V_13 -> V_28 = V_15 -> V_50 + V_15 -> V_51 ;
V_13 -> V_29 = ( void * ) ( T_1 ) V_15 -> V_52 ;
V_13 -> V_18 = V_15 ;
V_13 -> V_53 = V_54 ;
F_29 ( V_13 ) ;
if ( V_13 -> V_8 == NULL )
return - V_55 ;
F_30 ( V_13 -> V_8 ) ;
F_31 ( V_13 -> V_8 ) ;
V_15 -> V_13 = V_13 ;
return 0 ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
if ( ! V_15 || ! V_15 -> V_13 )
return;
V_13 = V_15 -> V_13 ;
F_33 ( V_13 -> V_8 ) ;
}
struct V_14 * F_34 ( struct V_1 * V_6 )
{
struct V_12 * V_13 ;
V_13 = F_8 ( V_6 -> V_8 ) ;
return (struct V_14 * ) V_13 -> V_18 ;
}
unsigned int F_35 ( struct V_1 * V_6 )
{
return F_19 ( V_6 -> V_8 -> V_36 , V_6 -> V_25 ) ;
}
