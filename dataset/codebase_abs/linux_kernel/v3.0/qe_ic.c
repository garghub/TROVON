static inline T_1 F_1 ( volatile T_2 T_3 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + ( V_2 >> 2 ) ) ;
}
static inline void F_3 ( volatile T_2 T_3 * V_1 , unsigned int V_2 ,
T_1 V_3 )
{
F_4 ( V_1 + ( V_2 >> 2 ) , V_3 ) ;
}
static inline struct V_4 * F_5 ( unsigned int V_5 )
{
return F_6 ( V_5 ) ;
}
static inline struct V_4 * F_7 ( struct V_6 * V_7 )
{
return F_8 ( V_7 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_4 * V_4 = F_7 ( V_7 ) ;
unsigned int V_8 = F_10 ( V_7 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_11 ( & V_11 , V_9 ) ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ) ;
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ,
V_10 | V_13 [ V_8 ] . V_15 ) ;
F_12 ( & V_11 , V_9 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_4 * V_4 = F_7 ( V_7 ) ;
unsigned int V_8 = F_10 ( V_7 ) ;
unsigned long V_9 ;
T_1 V_10 ;
F_11 ( & V_11 , V_9 ) ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ) ;
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_14 ,
V_10 & ~ V_13 [ V_8 ] . V_15 ) ;
F_14 () ;
F_12 ( & V_11 , V_9 ) ;
}
static int F_15 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
return V_17 -> V_20 == NULL || V_17 -> V_20 == V_19 ;
}
static int F_16 ( struct V_16 * V_17 , unsigned int V_5 ,
T_4 V_21 )
{
struct V_4 * V_4 = V_17 -> V_22 ;
struct V_23 * V_24 ;
if ( V_13 [ V_21 ] . V_15 == 0 ) {
F_17 ( V_25 L_1 ) ;
return - V_26 ;
}
V_24 = & V_4 -> V_27 ;
F_18 ( V_5 , V_4 ) ;
F_19 ( V_5 , V_28 ) ;
F_20 ( V_5 , V_24 , V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_18 * V_30 ,
const T_1 * V_31 , unsigned int V_32 ,
T_4 * V_33 ,
unsigned int * V_34 )
{
* V_33 = V_31 [ 0 ] ;
if ( V_32 > 1 )
* V_34 = V_31 [ 1 ] ;
else
* V_34 = V_35 ;
return 0 ;
}
unsigned int F_22 ( struct V_4 * V_4 )
{
int V_36 ;
F_23 ( V_4 == NULL ) ;
V_36 = F_1 ( V_4 -> V_12 , V_37 ) >> 26 ;
if ( V_36 == 0 )
return V_38 ;
return F_24 ( V_4 -> V_39 , V_36 ) ;
}
unsigned int F_25 ( struct V_4 * V_4 )
{
int V_36 ;
F_23 ( V_4 == NULL ) ;
V_36 = F_1 ( V_4 -> V_12 , V_40 ) >> 26 ;
if ( V_36 == 0 )
return V_38 ;
return F_24 ( V_4 -> V_39 , V_36 ) ;
}
void T_5 F_26 ( struct V_18 * V_19 , unsigned int V_9 ,
void (* F_27)( unsigned int V_36 , struct V_41 * V_42 ) ,
void (* F_28)( unsigned int V_36 , struct V_41 * V_42 ) )
{
struct V_4 * V_4 ;
struct V_43 V_44 ;
T_1 V_10 = 0 , V_45 , V_46 = 0 ;
V_45 = F_29 ( V_19 , 0 , & V_44 ) ;
if ( V_45 )
return;
V_4 = F_30 ( sizeof( * V_4 ) , V_47 ) ;
if ( V_4 == NULL )
return;
V_4 -> V_39 = F_31 ( V_19 , V_48 ,
V_49 , & V_50 , 0 ) ;
if ( V_4 -> V_39 == NULL ) {
F_32 ( V_4 ) ;
return;
}
V_4 -> V_12 = F_33 ( V_44 . V_51 , V_44 . V_52 - V_44 . V_51 + 1 ) ;
V_4 -> V_39 -> V_22 = V_4 ;
V_4 -> V_27 = V_53 ;
V_4 -> V_54 = F_34 ( V_19 , 0 ) ;
V_4 -> V_55 = F_34 ( V_19 , 1 ) ;
if ( V_4 -> V_55 == V_38 ) {
F_17 ( V_25 L_2 ) ;
F_32 ( V_4 ) ;
return;
}
if ( V_9 & V_56 )
V_10 |= V_57 ;
if ( V_9 & V_58 )
V_10 |= V_59 ;
if ( V_9 & V_60 )
V_10 |= V_61 ;
if ( V_9 & V_62 )
V_10 |= V_63 ;
if ( V_9 & V_64 )
V_10 |= V_65 ;
if ( V_9 & V_66 )
V_10 |= V_67 ;
if ( V_9 & V_68 ) {
V_10 |= ( V_69 << V_70 ) ;
V_46 = 1 ;
}
F_3 ( V_4 -> V_12 , V_71 , V_10 ) ;
F_35 ( V_4 -> V_55 , V_4 ) ;
F_36 ( V_4 -> V_55 , F_27 ) ;
if ( V_4 -> V_54 != V_38 &&
V_4 -> V_54 != V_4 -> V_55 ) {
F_35 ( V_4 -> V_54 , V_4 ) ;
F_36 ( V_4 -> V_54 , F_28 ) ;
}
}
void F_37 ( unsigned int V_5 , int V_72 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_38 ( V_5 ) ;
T_1 V_10 = 0 ;
V_10 = F_1 ( V_4 -> V_12 , V_71 ) ;
V_10 &= ~ V_73 ;
V_10 |= V_8 << V_74 ;
V_10 &= ~ V_75 ;
V_10 |= ( V_72 ? V_69 : V_76 ) << V_70 ;
F_3 ( V_4 -> V_12 , V_71 , V_10 ) ;
}
int F_39 ( unsigned int V_5 , unsigned int V_77 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_38 ( V_5 ) ;
T_1 V_10 ;
if ( V_77 > 8 || V_77 == 0 )
return - V_26 ;
if ( V_8 > 127 )
return - V_26 ;
if ( V_13 [ V_8 ] . V_78 == 0 )
return - V_26 ;
V_10 = F_1 ( V_4 -> V_12 , V_13 [ V_8 ] . V_78 ) ;
if ( V_77 < 4 ) {
V_10 &= ~ ( 0x7 << ( 32 - V_77 * 3 ) ) ;
V_10 |= V_13 [ V_8 ] . V_79 << ( 32 - V_77 * 3 ) ;
} else {
V_10 &= ~ ( 0x7 << ( 24 - V_77 * 3 ) ) ;
V_10 |= V_13 [ V_8 ] . V_79 << ( 24 - V_77 * 3 ) ;
}
F_3 ( V_4 -> V_12 , V_13 [ V_8 ] . V_78 , V_10 ) ;
return 0 ;
}
int F_40 ( unsigned int V_5 , unsigned int V_77 , int V_72 )
{
struct V_4 * V_4 = F_5 ( V_5 ) ;
unsigned int V_8 = F_38 ( V_5 ) ;
T_1 V_10 , V_80 = V_81 , V_82 = 0 ;
if ( V_77 > 2 || V_77 == 0 )
return - V_26 ;
switch ( V_13 [ V_8 ] . V_78 ) {
case V_83 :
V_82 = V_84 ;
break;
case V_85 :
V_82 = V_86 ;
break;
case V_87 :
V_82 = V_88 ;
break;
case V_89 :
V_82 = V_90 ;
break;
case V_91 :
V_82 = V_92 ;
V_80 = V_93 ;
break;
case V_94 :
V_82 = V_95 ;
V_80 = V_93 ;
break;
default:
return - V_26 ;
}
V_82 += ( 2 - V_77 ) * 2 ;
V_10 = F_1 ( V_4 -> V_12 , V_80 ) ;
V_10 &= ~ ( V_96 << V_82 ) ;
V_10 |= ( V_72 ? V_69 : V_76 ) << V_82 ;
F_3 ( V_4 -> V_12 , V_80 , V_10 ) ;
return 0 ;
}
static int T_5 F_41 ( void )
{
int V_97 ;
F_17 ( V_98 L_3 ) ;
V_97 = F_42 ( & V_99 ) ;
if ( V_97 ) {
F_17 ( V_25 L_4 ) ;
return - V_100 ;
}
V_97 = F_43 ( & V_101 ) ;
if ( V_97 ) {
F_17 ( V_25 L_5 ) ;
return - V_100 ;
}
return 0 ;
}
