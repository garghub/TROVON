static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & V_3 ) | V_2 ;
}
static void T_2 * F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_5 -> V_9 >= ( V_5 -> V_10 + 1 ) )
return V_7 -> V_11 + V_12 ;
return V_7 -> V_11 ;
}
static void F_3 ( struct V_4 * V_5 , T_3 V_13 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_14 , V_15 , V_16 ;
T_1 V_17 = 0 ;
V_14 = V_5 -> V_9 ;
V_15 = F_4 ( V_13 ) ;
V_16 = F_5 ( V_13 ) ;
if ( ! F_6 ( V_5 ) )
V_17 = ( V_14 << 8 ) | ( V_15 << 3 ) | V_16 ;
F_7 ( V_17 , V_7 -> V_18 + V_19 ) ;
F_8 ( V_7 -> V_18 + V_19 ) ;
}
static bool F_9 ( struct V_4 * V_5 , int V_20 )
{
if ( F_6 ( V_5 ) && ( ( V_20 == V_21 ) ||
( V_20 == V_22 ) ) )
return true ;
return false ;
}
static void T_2 * F_10 ( struct V_4 * V_5 , unsigned int V_13 ,
int V_20 )
{
if ( ( F_6 ( V_5 ) && V_13 != 0 ) ||
F_9 ( V_5 , V_20 ) )
return NULL ;
F_3 ( V_5 , V_13 ) ;
return F_2 ( V_5 ) + V_20 ;
}
static int F_11 ( struct V_4 * V_5 , unsigned int V_13 ,
int V_23 , int V_24 , T_1 * V_25 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( F_12 ( V_5 , V_13 , V_23 & ~ 0x3 , 4 , V_25 ) !=
V_26 )
return V_27 ;
if ( F_6 ( V_5 ) && ( V_7 -> V_28 == V_29 ) &&
( ( V_23 & ~ 0x3 ) == V_30 ) )
* V_25 &= ~ ( V_31 << 16 ) ;
if ( V_24 <= 2 )
* V_25 = ( * V_25 >> ( 8 * ( V_23 & 3 ) ) ) & ( ( 1 << ( V_24 * 8 ) ) - 1 ) ;
return V_26 ;
}
static T_4 F_13 ( void T_2 * V_18 , T_1 V_1 ,
T_1 V_2 , T_4 V_24 )
{
T_4 V_32 = ( ~ ( V_24 - 1 ) & V_3 ) | V_2 ;
T_1 V_33 = 0 ;
T_1 V_25 ;
V_33 = F_8 ( V_18 + V_1 ) ;
V_25 = ( V_33 & 0x0000ffff ) | ( F_14 ( V_32 ) << 16 ) ;
F_7 ( V_25 , V_18 + V_1 ) ;
V_33 = F_8 ( V_18 + V_1 + 0x04 ) ;
V_25 = ( V_33 & 0xffff0000 ) | ( F_14 ( V_32 ) >> 16 ) ;
F_7 ( V_25 , V_18 + V_1 + 0x04 ) ;
V_33 = F_8 ( V_18 + V_1 + 0x04 ) ;
V_25 = ( V_33 & 0x0000ffff ) | ( F_15 ( V_32 ) << 16 ) ;
F_7 ( V_25 , V_18 + V_1 + 0x04 ) ;
V_33 = F_8 ( V_18 + V_1 + 0x08 ) ;
V_25 = ( V_33 & 0xffff0000 ) | ( F_15 ( V_32 ) >> 16 ) ;
F_7 ( V_25 , V_18 + V_1 + 0x08 ) ;
return V_32 ;
}
static void F_16 ( struct V_6 * V_7 ,
T_1 * V_34 , T_1 * V_35 )
{
void T_2 * V_18 = V_7 -> V_18 ;
T_1 V_33 ;
V_7 -> V_36 = false ;
V_33 = F_8 ( V_18 + V_37 ) ;
if ( V_33 & V_38 ) {
V_7 -> V_36 = true ;
* V_35 = F_17 ( V_33 ) ;
V_33 = F_8 ( V_18 + V_39 ) ;
* V_34 = V_33 >> 26 ;
}
}
static int F_18 ( struct V_6 * V_7 )
{
int V_40 ;
V_7 -> V_41 = F_19 ( V_7 -> V_42 , NULL ) ;
if ( F_20 ( V_7 -> V_41 ) ) {
F_21 ( V_7 -> V_42 , L_1 ) ;
return - V_43 ;
}
V_40 = F_22 ( V_7 -> V_41 ) ;
if ( V_40 ) {
F_21 ( V_7 -> V_42 , L_2 ) ;
return V_40 ;
}
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
V_47 = F_24 ( V_45 , V_48 , L_3 ) ;
V_7 -> V_18 = F_25 ( V_7 -> V_42 , V_47 ) ;
if ( F_20 ( V_7 -> V_18 ) )
return F_26 ( V_7 -> V_18 ) ;
V_47 = F_24 ( V_45 , V_48 , L_4 ) ;
V_7 -> V_11 = F_25 ( V_7 -> V_42 , V_47 ) ;
if ( F_20 ( V_7 -> V_11 ) )
return F_26 ( V_7 -> V_11 ) ;
V_7 -> V_49 = V_47 -> V_50 ;
return 0 ;
}
static void F_27 ( struct V_6 * V_7 ,
struct V_46 * V_47 , T_1 V_20 ,
T_4 V_51 , T_4 V_52 )
{
void T_2 * V_53 = V_7 -> V_18 + V_20 ;
T_5 V_24 = F_28 ( V_47 ) ;
T_4 V_54 = F_29 ( V_47 ) ;
T_4 V_32 = 0 ;
T_1 V_55 ;
T_1 V_56 = V_57 ;
if ( V_54 == V_48 ) {
V_55 = V_58 ;
} else {
V_55 = 128 ;
V_56 |= V_59 ;
}
if ( V_24 >= V_55 )
V_32 = ~ ( V_24 - 1 ) | V_56 ;
else
F_30 ( V_7 -> V_42 , L_5 ,
( T_4 ) V_24 , V_55 ) ;
F_7 ( F_14 ( V_51 ) , V_53 ) ;
F_7 ( F_15 ( V_51 ) , V_53 + 0x04 ) ;
F_7 ( F_14 ( V_32 ) , V_53 + 0x08 ) ;
F_7 ( F_15 ( V_32 ) , V_53 + 0x0c ) ;
F_7 ( F_14 ( V_52 ) , V_53 + 0x10 ) ;
F_7 ( F_15 ( V_52 ) , V_53 + 0x14 ) ;
}
static void F_31 ( void T_2 * V_18 , T_4 V_1 )
{
F_7 ( F_14 ( V_1 ) , V_18 + V_60 ) ;
F_7 ( F_15 ( V_1 ) , V_18 + V_61 ) ;
F_7 ( V_57 , V_18 + V_62 ) ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_63 * V_47 ,
T_5 V_64 )
{
struct V_65 * V_66 ;
struct V_67 * V_42 = V_7 -> V_42 ;
int V_68 ;
F_33 (window, res) {
struct V_46 * V_47 = V_66 -> V_47 ;
T_4 V_54 = F_29 ( V_47 ) ;
F_34 ( V_7 -> V_42 , L_6 , V_47 ) ;
switch ( V_54 ) {
case V_69 :
F_27 ( V_7 , V_47 , V_70 , V_64 ,
V_47 -> V_50 - V_66 -> V_20 ) ;
V_68 = F_35 ( V_47 , V_64 ) ;
if ( V_68 < 0 )
return V_68 ;
break;
case V_48 :
F_27 ( V_7 , V_47 , V_71 , V_47 -> V_50 ,
V_47 -> V_50 - V_66 -> V_20 ) ;
break;
case V_72 :
break;
default:
F_21 ( V_42 , L_7 , V_47 ) ;
return - V_73 ;
}
}
F_31 ( V_7 -> V_18 , V_7 -> V_49 ) ;
return 0 ;
}
static void F_36 ( void * V_1 , T_4 V_74 , T_4 V_24 )
{
F_7 ( F_14 ( V_74 ) , V_1 ) ;
F_7 ( F_15 ( V_74 ) | V_75 , V_1 + 0x04 ) ;
F_7 ( F_14 ( V_24 ) , V_1 + 0x10 ) ;
F_7 ( F_15 ( V_24 ) , V_1 + 0x14 ) ;
}
static int F_37 ( T_6 * V_76 , T_4 V_24 )
{
if ( ( V_24 > 4 ) && ( V_24 < V_77 ) && ! ( * V_76 & ( 1 << 1 ) ) ) {
* V_76 |= ( 1 << 1 ) ;
return 1 ;
}
if ( ( V_24 > V_78 ) && ( V_24 < V_79 ) && ! ( * V_76 & ( 1 << 0 ) ) ) {
* V_76 |= ( 1 << 0 ) ;
return 0 ;
}
if ( ( V_24 > V_80 ) && ( V_24 < V_79 ) && ! ( * V_76 & ( 1 << 2 ) ) ) {
* V_76 |= ( 1 << 2 ) ;
return 2 ;
}
return - V_73 ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_81 * V_82 , T_6 * V_76 )
{
void T_2 * V_18 = V_7 -> V_18 ;
void T_2 * V_11 = V_7 -> V_11 ;
void * V_83 ;
void * V_84 ;
T_4 V_51 = V_82 -> V_51 ;
T_4 V_52 = V_82 -> V_52 ;
T_4 V_24 = V_82 -> V_24 ;
T_4 V_32 = ~ ( V_24 - 1 ) | V_57 ;
T_1 V_2 = V_85 ;
T_1 V_86 ;
int V_87 ;
V_87 = F_37 ( V_76 , V_82 -> V_24 ) ;
if ( V_87 < 0 ) {
F_30 ( V_7 -> V_42 , L_8 ) ;
return;
}
if ( V_82 -> V_2 & V_88 )
V_2 |= V_89 ;
V_86 = F_1 ( ( T_1 ) V_51 , V_2 ) ;
switch ( V_87 ) {
case 0 :
F_13 ( V_18 , V_90 , V_2 , V_24 ) ;
V_83 = V_11 + V_21 ;
F_7 ( V_86 , V_83 ) ;
F_7 ( F_15 ( V_51 ) , V_83 + 0x4 ) ;
V_84 = V_18 + V_91 ;
break;
case 1 :
V_83 = V_18 + V_92 ;
F_7 ( V_86 , V_83 ) ;
F_7 ( F_14 ( V_32 ) , V_18 + V_93 ) ;
V_84 = V_18 + V_94 ;
break;
case 2 :
V_83 = V_18 + V_95 ;
F_7 ( V_86 , V_83 ) ;
F_7 ( F_15 ( V_51 ) , V_83 + 0x4 ) ;
F_7 ( F_14 ( V_32 ) , V_18 + V_96 ) ;
F_7 ( F_15 ( V_32 ) , V_18 + V_96 + 0x4 ) ;
V_84 = V_18 + V_97 ;
break;
}
F_36 ( V_84 , V_52 , ~ ( V_24 - 1 ) ) ;
}
static int F_39 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
const int V_102 = 3 , V_103 = 2 ;
int V_104 ;
V_99 -> V_101 = V_101 ;
V_99 -> V_105 = F_40 ( V_101 ) ;
V_99 -> V_106 = V_99 -> V_105 + V_102 + V_103 ;
V_99 -> V_82 = F_41 ( V_101 , L_9 , & V_104 ) ;
if ( ! V_99 -> V_82 )
return - V_107 ;
V_99 -> V_108 = V_99 -> V_82 + V_104 / sizeof( V_109 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_100 * V_106 = V_7 -> V_101 ;
struct V_81 V_82 ;
struct V_98 V_99 ;
struct V_67 * V_42 = V_7 -> V_42 ;
T_6 V_76 = 0 ;
if ( F_39 ( & V_99 , V_106 ) ) {
F_21 ( V_42 , L_10 ) ;
return - V_73 ;
}
F_43 (&parser, &range) {
T_4 V_108 = V_82 . V_51 + V_82 . V_24 - 1 ;
F_34 ( V_7 -> V_42 , L_11 ,
V_82 . V_2 , V_82 . V_51 , V_108 , V_82 . V_52 ) ;
F_38 ( V_7 , & V_82 , & V_76 ) ;
}
return 0 ;
}
static void F_44 ( struct V_6 * V_7 )
{
int V_110 ;
for ( V_110 = V_91 ; V_110 <= V_62 ; V_110 += 4 )
F_7 ( 0x0 , V_7 -> V_18 + V_110 ) ;
}
static int F_45 ( struct V_6 * V_7 ,
struct V_63 * V_47 ,
T_5 V_64 )
{
T_1 V_25 , V_34 = 0 , V_35 = 0 ;
int V_68 ;
F_44 ( V_7 ) ;
V_25 = ( V_111 << 16 ) | V_112 ;
F_7 ( V_25 , V_7 -> V_18 + V_113 ) ;
V_68 = F_32 ( V_7 , V_47 , V_64 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_42 ( V_7 ) ;
if ( V_68 )
return V_68 ;
F_16 ( V_7 , & V_34 , & V_35 ) ;
if ( ! V_7 -> V_36 )
F_46 ( V_7 -> V_42 , L_12 ) ;
else
F_46 ( V_7 -> V_42 , L_13 ,
V_34 , V_35 + 1 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_100 * V_114 ;
V_114 = F_48 ( V_5 -> V_42 . V_115 ,
L_14 , 0 ) ;
if ( ! V_114 )
return - V_43 ;
V_5 -> V_116 = F_49 ( V_114 ) ;
if ( ! V_5 -> V_116 )
return - V_43 ;
V_5 -> V_116 -> V_42 = & V_5 -> V_42 ;
return 0 ;
}
static int F_50 ( struct V_44 * V_45 )
{
struct V_100 * V_117 = V_45 -> V_42 . V_115 ;
struct V_6 * V_7 ;
T_5 V_118 = 0 ;
struct V_4 * V_5 ;
int V_68 ;
F_51 ( V_47 ) ;
V_7 = F_52 ( & V_45 -> V_42 , sizeof( * V_7 ) , V_119 ) ;
if ( ! V_7 )
return - V_120 ;
V_7 -> V_101 = F_53 ( V_45 -> V_42 . V_115 ) ;
V_7 -> V_42 = & V_45 -> V_42 ;
V_7 -> V_28 = V_121 ;
if ( F_54 ( V_7 -> V_101 , L_15 ) )
V_7 -> V_28 = V_29 ;
V_68 = F_23 ( V_7 , V_45 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_18 ( V_7 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_55 ( V_117 , 0 , 0xff , & V_47 , & V_118 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_45 ( V_7 , & V_47 , V_118 ) ;
if ( V_68 )
return V_68 ;
V_5 = F_56 ( & V_45 -> V_42 , 0 ,
& V_122 , V_7 , & V_47 ) ;
if ( ! V_5 )
return - V_120 ;
if ( F_57 ( V_123 ) )
if ( F_47 ( V_5 ) )
F_46 ( V_7 -> V_42 , L_16 ) ;
F_58 ( V_5 ) ;
F_59 ( V_5 ) ;
F_60 ( V_5 ) ;
F_61 ( V_45 , V_7 ) ;
return 0 ;
}
