static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
int V_6 , V_7 ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & 0x20 ;
do {
V_7 = V_6 ;
V_3 = F_3 ( V_2 -> V_8 + V_10 ) ;
V_4 = F_3 ( V_2 -> V_8 + V_10 ) ;
V_5 = F_3 ( V_2 -> V_8 + V_10 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & 0x20 ;
} while ( F_4 ( ( V_6 != V_7 ) || ( V_3 > V_4 && V_3 < V_5 )
|| ( V_4 > V_5 && V_4 < V_3 ) || ( V_5 > V_3 && V_5 < V_4 ) ) );
V_4 |= V_6 << 10 ;
return V_4 ;
}
static T_1 F_5 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_6 ( F_2 ( V_2 -> V_8 + V_9 ) & ~ 0x40 ,
V_2 -> V_8 + V_9 ) ;
V_2 -> V_13 |= V_14 ;
F_7 ( V_2 -> V_15 , V_2 -> V_8 + V_16 ) ;
if ( ! ( V_2 -> V_13 & V_17 ) ) {
if ( V_2 -> V_18 . V_19 == V_20 )
F_7 ( 0x0000 , V_2 -> V_8 + V_21 ) ;
V_2 -> V_18 . V_22 ( & V_2 -> V_18 ) ;
}
V_2 -> V_13 &= ~ ( V_17 | V_14 ) ;
return V_23 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned long V_24 )
{
unsigned long V_13 ;
unsigned long V_25 ;
F_9 ( & V_2 -> V_26 , V_13 ) ;
if ( V_24 >= 0x10000 )
F_10 ( & V_2 -> V_27 -> V_28 , L_1 ) ;
V_25 = F_1 ( V_2 ) ;
V_2 -> V_15 = V_24 ;
F_6 ( F_2 ( V_2 -> V_8 + V_21 ) | 0x40 , V_2 -> V_8 + V_21 ) ;
if ( V_24 > V_25 )
F_7 ( V_24 , V_2 -> V_8 + V_16 ) ;
else
F_7 ( V_25 + 1 , V_2 -> V_8 + V_16 ) ;
F_11 ( & V_2 -> V_26 , V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_29 = F_13 ( V_2 -> V_30 ) / 64 ;
F_7 ( 0xffff , V_2 -> V_8 + V_16 ) ;
F_7 ( 0x0000 , V_2 -> V_8 + V_10 ) ;
F_7 ( 0x0c02 , V_2 -> V_8 + V_21 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
unsigned long V_13 ;
F_9 ( & V_2 -> V_26 , V_13 ) ;
if ( ! ( V_2 -> V_13 & V_32 ) )
V_31 = F_12 ( V_2 ) ;
if ( V_31 )
goto V_33;
V_2 -> V_13 |= V_32 ;
V_33:
F_11 ( & V_2 -> V_26 , V_13 ) ;
return V_31 ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
F_9 ( & V_2 -> V_26 , V_13 ) ;
F_7 ( 0x0000 , V_2 -> V_8 + V_21 ) ;
F_11 ( & V_2 -> V_26 , V_13 ) ;
}
static inline struct V_1 * F_16 ( struct V_34 * V_18 )
{
return F_17 ( V_18 , struct V_1 , V_18 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_35 )
{
struct V_34 * V_18 = & V_2 -> V_18 ;
F_14 ( V_2 ) ;
V_18 -> V_36 = 32 ;
V_18 -> V_37 = F_19 ( V_2 -> V_29 , V_38 , V_18 -> V_36 ) ;
V_18 -> V_39 = F_20 ( 0xffff , V_18 ) ;
V_18 -> V_40 = F_20 ( 0x0001 , V_18 ) ;
F_8 ( V_2 , V_35 ? ( V_2 -> V_29 + V_41 / 2 ) / V_41 : 0x10000 ) ;
}
static void F_21 ( enum V_42 V_19 ,
struct V_34 * V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
switch ( V_19 ) {
case V_43 :
F_22 ( & V_2 -> V_27 -> V_28 , L_2 ) ;
F_15 ( V_2 ) ;
F_18 ( V_2 , V_44 ) ;
break;
case V_20 :
F_22 ( & V_2 -> V_27 -> V_28 , L_3 ) ;
F_15 ( V_2 ) ;
F_18 ( V_2 , V_45 ) ;
break;
case V_46 :
case V_47 :
F_15 ( V_2 ) ;
break;
default:
break;
}
}
static int F_23 ( unsigned long V_24 ,
struct V_34 * V_18 )
{
struct V_1 * V_2 = F_16 ( V_18 ) ;
F_24 ( V_18 -> V_19 != V_20 ) ;
F_8 ( V_2 , V_24 - 1 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_48 * V_27 )
{
struct V_49 * V_50 ;
int V_11 ;
int V_31 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_27 = V_27 ;
V_50 = F_26 ( V_2 -> V_27 , V_51 , 0 ) ;
if ( ! V_50 ) {
F_27 ( & V_2 -> V_27 -> V_28 , L_4 ) ;
return - V_52 ;
}
V_11 = F_28 ( V_2 -> V_27 , 0 ) ;
if ( V_11 < 0 ) {
F_27 ( & V_2 -> V_27 -> V_28 , L_5 ) ;
return - V_52 ;
}
V_2 -> V_8 = V_50 -> V_53 ;
V_2 -> V_54 . V_55 = F_29 ( & V_2 -> V_27 -> V_28 ) ;
V_2 -> V_54 . V_56 = F_5 ;
V_2 -> V_54 . V_12 = V_2 ;
V_2 -> V_54 . V_13 = V_57 ;
V_2 -> V_30 = F_30 ( & V_2 -> V_27 -> V_28 , L_6 ) ;
if ( F_31 ( V_2 -> V_30 ) ) {
F_27 ( & V_2 -> V_27 -> V_28 , L_7 ) ;
return F_32 ( V_2 -> V_30 ) ;
}
V_2 -> V_18 . V_55 = V_27 -> V_55 ;
V_2 -> V_18 . V_58 = V_59 |
V_60 ;
V_2 -> V_18 . V_61 = 200 ;
V_2 -> V_18 . V_62 = F_33 ( 0 ) ;
V_2 -> V_18 . V_63 = F_23 ;
V_2 -> V_18 . V_64 = F_21 ;
V_31 = F_34 ( V_11 , & V_2 -> V_54 ) ;
if ( V_31 < 0 ) {
F_27 ( & V_2 -> V_27 -> V_28 ,
L_8 , V_11 ) ;
return V_31 ;
}
F_35 ( & V_2 -> V_18 ) ;
F_36 ( V_27 , V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_27 )
{
struct V_1 * V_2 = F_38 ( V_27 ) ;
if ( V_2 ) {
F_22 ( & V_27 -> V_28 , L_9 ) ;
return 0 ;
}
V_2 = F_39 ( & V_27 -> V_28 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_66 ;
return F_25 ( V_2 , V_27 ) ;
}
static int F_40 ( struct V_48 * V_27 )
{
return - V_67 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_68 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_68 ) ;
}
