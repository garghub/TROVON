static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_7 = V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
V_2 -> V_7 = V_11 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
F_7 ( V_2 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned long V_12 )
{
unsigned long V_13 = V_12 * 1000 ;
unsigned long V_9 ;
unsigned int V_7 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
V_7 = V_2 -> V_7 ;
F_7 ( V_2 ) ;
F_3 ( V_13 , V_2 -> V_4 + V_14 ) ;
if ( V_7 == V_8 )
F_1 ( V_2 ) ;
V_2 -> V_13 = V_13 ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned long * V_12 )
{
* V_12 = V_2 -> V_13 / 1000 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_5 ( & V_2 -> V_10 , V_9 ) ;
F_3 ( V_2 -> V_13 , V_2 -> V_4 + V_14 ) ;
F_6 ( & V_2 -> V_10 , V_9 ) ;
}
static int F_12 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_2 = F_13 ( V_17 ) ;
if ( F_14 ( 0 , & V_18 ) )
return - V_19 ;
V_16 -> V_20 = V_2 ;
F_9 ( V_2 , 30 ) ;
F_4 ( V_2 ) ;
return F_15 ( V_15 , V_16 ) ;
}
static int F_16 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_20 ;
F_8 ( V_2 ) ;
F_17 ( 0 , & V_18 ) ;
return 0 ;
}
static long F_18 ( struct V_16 * V_16 , unsigned int V_21 , unsigned long V_22 )
{
struct V_1 * V_2 = V_16 -> V_20 ;
void T_2 * V_23 = ( void T_2 * ) V_22 ;
unsigned long T_2 * V_24 = V_23 ;
unsigned long V_12 = 0 ;
unsigned int V_25 ;
long V_26 = - V_27 ;
switch ( V_21 ) {
case V_28 :
if ( F_19 ( V_23 , & V_29 , sizeof( V_29 ) ) )
return - V_30 ;
else
return 0 ;
case V_31 :
case V_32 :
return F_20 ( 0 , V_24 ) ;
case V_33 :
F_11 ( V_2 ) ;
return 0 ;
case V_34 :
if ( F_21 ( V_12 , V_24 ) )
return - V_30 ;
F_9 ( V_2 , V_12 ) ;
case V_35 :
F_10 ( V_2 , & V_12 ) ;
return F_20 ( V_12 , V_24 ) ;
case V_36 :
if ( F_22 ( & V_25 , V_23 , sizeof( V_25 ) ) )
return - V_30 ;
if ( V_25 & V_37 ) {
F_8 ( V_2 ) ;
V_26 = 0 ;
}
if ( V_25 & V_38 ) {
F_4 ( V_2 ) ;
V_26 = 0 ;
}
return V_26 ;
default:
break;
}
return - V_39 ;
}
static T_3 F_23 ( struct V_16 * V_16 , const char T_2 * V_40 ,
T_4 V_41 , T_5 * V_42 )
{
struct V_1 * V_2 = V_16 -> V_20 ;
if ( V_41 )
F_11 ( V_2 ) ;
return V_41 ;
}
static int T_6 F_24 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 ;
int V_26 = 0 ;
T_1 V_3 ;
V_2 = F_25 ( & V_44 -> V_47 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 ) {
F_26 ( & V_44 -> V_47 , L_1 ) ;
return - V_49 ;
}
F_27 ( & V_2 -> V_10 ) ;
V_46 = F_28 ( V_44 , V_50 , 0 ) ;
if ( ! V_46 ) {
F_26 ( & V_44 -> V_47 , L_2 ) ;
return - V_51 ;
}
V_46 = F_29 ( & V_44 -> V_47 , V_46 -> V_52 ,
F_30 ( V_46 ) , V_46 -> V_53 ) ;
if ( ! V_46 ) {
F_26 ( & V_44 -> V_47 , L_3 ) ;
return - V_51 ;
}
V_2 -> V_4 = F_31 ( & V_44 -> V_47 , V_46 -> V_52 ,
F_30 ( V_46 ) ) ;
if ( ! V_2 -> V_4 ) {
F_26 ( & V_44 -> V_47 , L_4 ) ;
return - V_51 ;
}
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 &= ~ V_6 ;
V_3 &= ~ V_54 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_32 ( V_44 , V_2 ) ;
V_17 = V_44 ;
V_26 = F_33 ( & V_55 ) ;
if ( V_26 ) {
F_26 ( & V_44 -> V_47 , L_5
L_6 , V_56 , V_26 ) ;
return V_26 ;
}
return 0 ;
}
static int T_7 F_34 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_13 ( V_44 ) ;
F_35 ( & V_55 ) ;
F_8 ( V_2 ) ;
F_32 ( V_44 , NULL ) ;
return 0 ;
}
static void F_36 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_13 ( V_44 ) ;
F_8 ( V_2 ) ;
}
static int F_37 ( struct V_57 * V_47 )
{
struct V_43 * V_44 = F_38 ( V_47 ) ;
struct V_1 * V_2 = F_13 ( V_44 ) ;
V_2 -> V_58 = ( V_2 -> V_7 == V_8 ) ? 1 : 0 ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_57 * V_47 )
{
struct V_43 * V_44 = F_38 ( V_47 ) ;
struct V_1 * V_2 = F_13 ( V_44 ) ;
if ( V_2 -> V_58 )
F_4 ( V_2 ) ;
return 0 ;
}
static int T_8 F_40 ( void )
{
return F_41 ( & V_59 ) ;
}
static void T_9 F_42 ( void )
{
F_43 ( & V_59 ) ;
}
