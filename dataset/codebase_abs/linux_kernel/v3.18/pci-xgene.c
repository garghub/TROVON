static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & V_3 ) | V_2 ;
}
static inline void F_2 ( void T_2 * V_1 , int V_4 , T_1 V_5 )
{
F_3 ( V_5 , V_1 + V_4 ) ;
}
static inline void F_4 ( void T_2 * V_1 , int V_4 , T_3 V_5 )
{
T_1 V_6 = F_5 ( V_1 + ( V_4 & ~ 0x3 ) ) ;
switch ( V_4 & 0x3 ) {
case 2 :
V_6 &= ~ 0xFFFF0000 ;
V_6 |= ( T_1 ) V_5 << 16 ;
break;
case 0 :
default:
V_6 &= ~ 0xFFFF ;
V_6 |= V_5 ;
break;
}
F_3 ( V_6 , V_1 + ( V_4 & ~ 0x3 ) ) ;
}
static inline void F_6 ( void T_2 * V_1 , int V_4 , T_4 V_5 )
{
T_1 V_6 = F_5 ( V_1 + ( V_4 & ~ 0x3 ) ) ;
switch ( V_4 & 0x3 ) {
case 0 :
V_6 &= ~ 0xFF ;
V_6 |= V_5 ;
break;
case 1 :
V_6 &= ~ 0xFF00 ;
V_6 |= ( T_1 ) V_5 << 8 ;
break;
case 2 :
V_6 &= ~ 0xFF0000 ;
V_6 |= ( T_1 ) V_5 << 16 ;
break;
case 3 :
default:
V_6 &= ~ 0xFF000000 ;
V_6 |= ( T_1 ) V_5 << 24 ;
break;
}
F_3 ( V_6 , V_1 + ( V_4 & ~ 0x3 ) ) ;
}
static inline void F_7 ( void T_2 * V_1 , int V_4 , T_1 * V_5 )
{
* V_5 = F_5 ( V_1 + V_4 ) ;
}
static inline void F_8 ( void T_2 * V_1 , int V_4 , T_1 * V_5 )
{
* V_5 = F_5 ( V_1 + ( V_4 & ~ 0x3 ) ) ;
switch ( V_4 & 0x3 ) {
case 2 :
* V_5 >>= 16 ;
break;
}
* V_5 &= 0xFFFF ;
}
static inline void F_9 ( void T_2 * V_1 , int V_4 , T_1 * V_5 )
{
* V_5 = F_5 ( V_1 + ( V_4 & ~ 0x3 ) ) ;
switch ( V_4 & 0x3 ) {
case 3 :
* V_5 = * V_5 >> 24 ;
break;
case 2 :
* V_5 = * V_5 >> 16 ;
break;
case 1 :
* V_5 = * V_5 >> 8 ;
break;
}
* V_5 &= 0xFF ;
}
static void T_2 * F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
if ( V_8 -> V_12 >= ( V_8 -> V_13 + 1 ) )
return V_10 -> V_14 + V_15 ;
return V_10 -> V_14 ;
}
static void F_11 ( struct V_7 * V_8 , T_5 V_16 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned int V_17 , V_18 , V_19 ;
T_1 V_20 = 0 ;
V_17 = V_8 -> V_12 ;
V_18 = F_12 ( V_16 ) ;
V_19 = F_13 ( V_16 ) ;
if ( ! F_14 ( V_8 ) )
V_20 = ( V_17 << 8 ) | ( V_18 << 3 ) | V_19 ;
F_3 ( V_20 , V_10 -> V_21 + V_22 ) ;
F_5 ( V_10 -> V_21 + V_22 ) ;
}
static bool F_15 ( struct V_7 * V_8 , int V_4 )
{
if ( F_14 ( V_8 ) && ( ( V_4 == V_23 ) ||
( V_4 == V_24 ) ) )
return true ;
return false ;
}
static int F_16 ( struct V_7 * V_8 , unsigned int V_16 ,
int V_4 , int V_25 , T_1 * V_5 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
void T_2 * V_1 ;
if ( ( F_14 ( V_8 ) && V_16 != 0 ) || ! V_10 -> V_26 )
return V_27 ;
if ( F_15 ( V_8 , V_4 ) ) {
* V_5 = 0 ;
return V_28 ;
}
F_11 ( V_8 , V_16 ) ;
V_1 = F_10 ( V_8 ) ;
switch ( V_25 ) {
case 1 :
F_9 ( V_1 , V_4 , V_5 ) ;
break;
case 2 :
F_8 ( V_1 , V_4 , V_5 ) ;
break;
default:
F_7 ( V_1 , V_4 , V_5 ) ;
break;
}
return V_28 ;
}
static int F_17 ( struct V_7 * V_8 , unsigned int V_16 ,
int V_4 , int V_25 , T_1 V_5 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
void T_2 * V_1 ;
if ( ( F_14 ( V_8 ) && V_16 != 0 ) || ! V_10 -> V_26 )
return V_27 ;
if ( F_15 ( V_8 , V_4 ) )
return V_28 ;
F_11 ( V_8 , V_16 ) ;
V_1 = F_10 ( V_8 ) ;
switch ( V_25 ) {
case 1 :
F_6 ( V_1 , V_4 , ( T_4 ) V_5 ) ;
break;
case 2 :
F_4 ( V_1 , V_4 , ( T_3 ) V_5 ) ;
break;
default:
F_2 ( V_1 , V_4 , V_5 ) ;
break;
}
return V_28 ;
}
static T_6 F_18 ( void T_2 * V_21 , T_1 V_1 ,
T_1 V_2 , T_6 V_29 )
{
T_6 V_30 = ( ~ ( V_29 - 1 ) & V_3 ) | V_2 ;
T_1 V_6 = 0 ;
T_1 V_5 ;
V_6 = F_5 ( V_21 + V_1 ) ;
V_5 = ( V_6 & 0x0000ffff ) | ( F_19 ( V_30 ) << 16 ) ;
F_3 ( V_5 , V_21 + V_1 ) ;
V_6 = F_5 ( V_21 + V_1 + 0x04 ) ;
V_5 = ( V_6 & 0xffff0000 ) | ( F_19 ( V_30 ) >> 16 ) ;
F_3 ( V_5 , V_21 + V_1 + 0x04 ) ;
V_6 = F_5 ( V_21 + V_1 + 0x04 ) ;
V_5 = ( V_6 & 0x0000ffff ) | ( F_20 ( V_30 ) << 16 ) ;
F_3 ( V_5 , V_21 + V_1 + 0x04 ) ;
V_6 = F_5 ( V_21 + V_1 + 0x08 ) ;
V_5 = ( V_6 & 0xffff0000 ) | ( F_20 ( V_30 ) >> 16 ) ;
F_3 ( V_5 , V_21 + V_1 + 0x08 ) ;
return V_30 ;
}
static void F_21 ( struct V_9 * V_10 ,
T_1 * V_31 , T_1 * V_32 )
{
void T_2 * V_21 = V_10 -> V_21 ;
T_1 V_6 ;
V_10 -> V_26 = false ;
V_6 = F_5 ( V_21 + V_33 ) ;
if ( V_6 & V_34 ) {
V_10 -> V_26 = true ;
* V_32 = F_22 ( V_6 ) ;
V_6 = F_5 ( V_21 + V_35 ) ;
* V_31 = V_6 >> 26 ;
}
}
static int F_23 ( struct V_9 * V_10 )
{
int V_36 ;
V_10 -> V_37 = F_24 ( V_10 -> V_38 , NULL ) ;
if ( F_25 ( V_10 -> V_37 ) ) {
F_26 ( V_10 -> V_38 , L_1 ) ;
return - V_39 ;
}
V_36 = F_27 ( V_10 -> V_37 ) ;
if ( V_36 ) {
F_26 ( V_10 -> V_38 , L_2 ) ;
return V_36 ;
}
return 0 ;
}
static int F_28 ( struct V_9 * V_10 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 ;
V_43 = F_29 ( V_41 , V_44 , L_3 ) ;
V_10 -> V_21 = F_30 ( V_10 -> V_38 , V_43 ) ;
if ( F_25 ( V_10 -> V_21 ) )
return F_31 ( V_10 -> V_21 ) ;
V_43 = F_29 ( V_41 , V_44 , L_4 ) ;
V_10 -> V_14 = F_30 ( V_10 -> V_38 , V_43 ) ;
if ( F_25 ( V_10 -> V_14 ) )
return F_31 ( V_10 -> V_14 ) ;
V_10 -> V_45 = V_43 -> V_46 ;
return 0 ;
}
static void F_32 ( struct V_9 * V_10 ,
struct V_42 * V_43 , T_1 V_4 ,
T_6 V_47 , T_6 V_48 )
{
void T_2 * V_49 = V_10 -> V_21 + V_4 ;
T_7 V_29 = F_33 ( V_43 ) ;
T_6 V_50 = F_34 ( V_43 ) ;
T_6 V_30 = 0 ;
T_1 V_51 ;
T_1 V_52 = V_53 ;
if ( V_50 == V_44 ) {
V_51 = V_54 ;
} else {
V_51 = 128 ;
V_52 |= V_55 ;
}
if ( V_29 >= V_51 )
V_30 = ~ ( V_29 - 1 ) | V_52 ;
else
F_35 ( V_10 -> V_38 , L_5 ,
( T_6 ) V_29 , V_51 ) ;
F_3 ( F_19 ( V_47 ) , V_49 ) ;
F_3 ( F_20 ( V_47 ) , V_49 + 0x04 ) ;
F_3 ( F_19 ( V_30 ) , V_49 + 0x08 ) ;
F_3 ( F_20 ( V_30 ) , V_49 + 0x0c ) ;
F_3 ( F_19 ( V_48 ) , V_49 + 0x10 ) ;
F_3 ( F_20 ( V_48 ) , V_49 + 0x14 ) ;
}
static void F_36 ( void T_2 * V_21 , T_6 V_1 )
{
F_3 ( F_19 ( V_1 ) , V_21 + V_56 ) ;
F_3 ( F_20 ( V_1 ) , V_21 + V_57 ) ;
F_3 ( V_53 , V_21 + V_58 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
struct V_59 * V_43 ,
T_7 V_60 )
{
struct V_61 * V_62 ;
struct V_63 * V_38 = V_10 -> V_38 ;
int V_64 ;
F_38 (window, res, list) {
struct V_42 * V_43 = V_62 -> V_43 ;
T_6 V_50 = F_34 ( V_43 ) ;
F_39 ( V_10 -> V_38 , L_6 , V_43 ) ;
switch ( V_50 ) {
case V_65 :
F_32 ( V_10 , V_43 , V_66 , V_60 ,
V_43 -> V_46 - V_62 -> V_4 ) ;
V_64 = F_40 ( V_43 , V_60 ) ;
if ( V_64 < 0 )
return V_64 ;
break;
case V_44 :
F_32 ( V_10 , V_43 , V_67 , V_43 -> V_46 ,
V_43 -> V_46 - V_62 -> V_4 ) ;
break;
case V_68 :
break;
default:
F_26 ( V_38 , L_7 , V_43 ) ;
return - V_69 ;
}
}
F_36 ( V_10 -> V_21 , V_10 -> V_45 ) ;
return 0 ;
}
static void F_41 ( void * V_1 , T_6 V_70 , T_6 V_29 )
{
F_3 ( F_19 ( V_70 ) , V_1 ) ;
F_3 ( F_20 ( V_70 ) | V_71 , V_1 + 0x04 ) ;
F_3 ( F_19 ( V_29 ) , V_1 + 0x10 ) ;
F_3 ( F_20 ( V_29 ) , V_1 + 0x14 ) ;
}
static int F_42 ( T_4 * V_72 , T_6 V_29 )
{
if ( ( V_29 > 4 ) && ( V_29 < V_73 ) && ! ( * V_72 & ( 1 << 1 ) ) ) {
* V_72 |= ( 1 << 1 ) ;
return 1 ;
}
if ( ( V_29 > V_74 ) && ( V_29 < V_75 ) && ! ( * V_72 & ( 1 << 0 ) ) ) {
* V_72 |= ( 1 << 0 ) ;
return 0 ;
}
if ( ( V_29 > V_76 ) && ( V_29 < V_75 ) && ! ( * V_72 & ( 1 << 2 ) ) ) {
* V_72 |= ( 1 << 2 ) ;
return 2 ;
}
return - V_69 ;
}
static void F_43 ( struct V_9 * V_10 ,
struct V_77 * V_78 , T_4 * V_72 )
{
void T_2 * V_21 = V_10 -> V_21 ;
void T_2 * V_14 = V_10 -> V_14 ;
void * V_79 ;
void * V_80 ;
T_6 V_47 = V_78 -> V_47 ;
T_6 V_48 = V_78 -> V_48 ;
T_6 V_29 = V_78 -> V_29 ;
T_6 V_30 = ~ ( V_29 - 1 ) | V_53 ;
T_1 V_2 = V_81 ;
T_1 V_82 ;
int V_83 ;
V_83 = F_42 ( V_72 , V_78 -> V_29 ) ;
if ( V_83 < 0 ) {
F_35 ( V_10 -> V_38 , L_8 ) ;
return;
}
if ( V_78 -> V_2 & V_84 )
V_2 |= V_85 ;
V_82 = F_1 ( ( T_1 ) V_47 , V_2 ) ;
switch ( V_83 ) {
case 0 :
F_18 ( V_21 , V_86 , V_2 , V_29 ) ;
V_79 = V_14 + V_23 ;
F_3 ( V_82 , V_79 ) ;
F_3 ( F_20 ( V_47 ) , V_79 + 0x4 ) ;
V_80 = V_21 + V_87 ;
break;
case 1 :
V_79 = V_21 + V_88 ;
F_3 ( V_82 , V_79 ) ;
F_3 ( F_19 ( V_30 ) , V_21 + V_89 ) ;
V_80 = V_21 + V_90 ;
break;
case 2 :
V_79 = V_21 + V_91 ;
F_3 ( V_82 , V_79 ) ;
F_3 ( F_20 ( V_47 ) , V_79 + 0x4 ) ;
F_3 ( F_19 ( V_30 ) , V_21 + V_92 ) ;
F_3 ( F_20 ( V_30 ) , V_21 + V_92 + 0x4 ) ;
V_80 = V_21 + V_93 ;
break;
}
F_41 ( V_80 , V_48 , ~ ( V_29 - 1 ) ) ;
}
static int F_44 ( struct V_94 * V_95 ,
struct V_96 * V_97 )
{
const int V_98 = 3 , V_99 = 2 ;
int V_100 ;
V_95 -> V_97 = V_97 ;
V_95 -> V_101 = F_45 ( V_97 ) ;
V_95 -> V_102 = V_95 -> V_101 + V_98 + V_99 ;
V_95 -> V_78 = F_46 ( V_97 , L_9 , & V_100 ) ;
if ( ! V_95 -> V_78 )
return - V_103 ;
V_95 -> V_104 = V_95 -> V_78 + V_100 / sizeof( V_105 ) ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 )
{
struct V_96 * V_102 = V_10 -> V_97 ;
struct V_77 V_78 ;
struct V_94 V_95 ;
struct V_63 * V_38 = V_10 -> V_38 ;
T_4 V_72 = 0 ;
if ( F_44 ( & V_95 , V_102 ) ) {
F_26 ( V_38 , L_10 ) ;
return - V_69 ;
}
F_48 (&parser, &range) {
T_6 V_104 = V_78 . V_47 + V_78 . V_29 - 1 ;
F_39 ( V_10 -> V_38 , L_11 ,
V_78 . V_2 , V_78 . V_47 , V_104 , V_78 . V_48 ) ;
F_43 ( V_10 , & V_78 , & V_72 ) ;
}
return 0 ;
}
static void F_49 ( struct V_9 * V_10 )
{
int V_106 ;
for ( V_106 = V_87 ; V_106 <= V_58 ; V_106 += 4 )
F_3 ( 0x0 , V_10 -> V_21 + V_106 ) ;
}
static int F_50 ( struct V_9 * V_10 ,
struct V_59 * V_43 ,
T_7 V_60 )
{
T_1 V_5 , V_31 = 0 , V_32 = 0 ;
int V_64 ;
F_49 ( V_10 ) ;
V_5 = ( V_107 << 16 ) | V_108 ;
F_3 ( V_5 , V_10 -> V_21 + V_109 ) ;
V_64 = F_37 ( V_10 , V_43 , V_60 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_47 ( V_10 ) ;
if ( V_64 )
return V_64 ;
F_21 ( V_10 , & V_31 , & V_32 ) ;
if ( ! V_10 -> V_26 )
F_51 ( V_10 -> V_38 , L_12 ) ;
else
F_51 ( V_10 -> V_38 , L_13 ,
V_31 , V_32 + 1 ) ;
return 0 ;
}
static int F_52 ( struct V_40 * V_41 )
{
struct V_96 * V_110 = V_41 -> V_38 . V_111 ;
struct V_9 * V_10 ;
T_7 V_112 = 0 ;
struct V_7 * V_8 ;
int V_64 ;
F_53 ( V_43 ) ;
V_10 = F_54 ( & V_41 -> V_38 , sizeof( * V_10 ) , V_113 ) ;
if ( ! V_10 )
return - V_114 ;
V_10 -> V_97 = F_55 ( V_41 -> V_38 . V_111 ) ;
V_10 -> V_38 = & V_41 -> V_38 ;
V_64 = F_28 ( V_10 , V_41 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_23 ( V_10 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_56 ( V_110 , 0 , 0xff , & V_43 , & V_112 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_50 ( V_10 , & V_43 , V_112 ) ;
if ( V_64 )
return V_64 ;
V_8 = F_57 ( & V_41 -> V_38 , 0 ,
& V_115 , V_10 , & V_43 ) ;
if ( ! V_8 )
return - V_114 ;
F_58 ( V_8 ) ;
F_59 ( V_8 ) ;
F_60 ( V_8 ) ;
F_61 ( V_41 , V_10 ) ;
return 0 ;
}
