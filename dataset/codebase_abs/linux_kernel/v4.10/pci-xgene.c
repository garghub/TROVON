static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( T_1 V_6 , T_1 V_7 )
{
return ( V_6 & V_8 ) | V_7 ;
}
static inline struct V_1 * F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
if ( V_13 )
return (struct V_1 * ) ( V_10 -> V_14 ) ;
V_12 = V_10 -> V_14 ;
return (struct V_1 * ) ( V_12 -> V_15 ) ;
}
static void T_2 * F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
if ( V_10 -> V_16 >= ( V_10 -> V_17 + 1 ) )
return V_2 -> V_18 + V_19 ;
return V_2 -> V_18 ;
}
static void F_8 ( struct V_9 * V_10 , T_3 V_20 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
unsigned int V_21 , V_22 , V_23 ;
T_1 V_24 = 0 ;
V_21 = V_10 -> V_16 ;
V_22 = F_9 ( V_20 ) ;
V_23 = F_10 ( V_20 ) ;
if ( ! F_11 ( V_10 ) )
V_24 = ( V_21 << 8 ) | ( V_22 << 3 ) | V_23 ;
F_3 ( V_2 , V_25 , V_24 ) ;
F_1 ( V_2 , V_25 ) ;
}
static bool F_12 ( struct V_9 * V_10 , int V_26 )
{
if ( F_11 ( V_10 ) && ( ( V_26 == V_27 ) ||
( V_26 == V_28 ) ) )
return true ;
return false ;
}
static void T_2 * F_13 ( struct V_9 * V_10 , unsigned int V_20 ,
int V_26 )
{
if ( ( F_11 ( V_10 ) && V_20 != 0 ) ||
F_12 ( V_10 , V_26 ) )
return NULL ;
F_8 ( V_10 , V_20 ) ;
return F_7 ( V_10 ) + V_26 ;
}
static int F_14 ( struct V_9 * V_10 , unsigned int V_20 ,
int V_29 , int V_30 , T_1 * V_5 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
if ( F_15 ( V_10 , V_20 , V_29 & ~ 0x3 , 4 , V_5 ) !=
V_31 )
return V_32 ;
if ( F_11 ( V_10 ) && ( V_2 -> V_33 == V_34 ) &&
( ( V_29 & ~ 0x3 ) == V_35 ) )
* V_5 &= ~ ( V_36 << 16 ) ;
if ( V_30 <= 2 )
* V_5 = ( * V_5 >> ( 8 * ( V_29 & 3 ) ) ) & ( ( 1 << ( V_30 * 8 ) ) - 1 ) ;
return V_31 ;
}
static int F_16 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_38 -> V_42 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
unsigned long V_7 ;
int V_47 ;
F_17 ( & V_46 ) ;
V_7 = V_48 ;
V_47 = F_18 ( V_38 , & V_46 ,
V_49 ,
( void * ) V_7 ) ;
if ( V_47 < 0 ) {
F_19 ( V_42 , L_1 ,
V_47 ) ;
return V_47 ;
}
if ( V_47 == 0 ) {
F_19 ( V_42 , L_2 ) ;
return - V_50 ;
}
V_44 = F_20 ( & V_46 , struct V_43 , V_51 ) ;
* V_40 = * V_44 -> V_40 ;
F_21 ( & V_46 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 , T_1 V_52 )
{
struct V_41 * V_42 = V_12 -> V_53 ;
struct V_37 * V_38 = F_23 ( V_42 ) ;
struct V_1 * V_2 ;
struct V_39 V_54 ;
int V_47 ;
V_2 = F_24 ( V_42 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_47 = F_16 ( V_38 , & V_54 ) ;
if ( V_47 ) {
F_19 ( V_42 , L_3 ) ;
F_25 ( V_2 ) ;
return V_47 ;
}
V_2 -> V_4 = F_26 ( V_42 , & V_54 ) ;
if ( F_27 ( V_2 -> V_4 ) ) {
F_25 ( V_2 ) ;
return - V_56 ;
}
V_2 -> V_18 = V_12 -> V_57 ;
V_2 -> V_33 = V_52 ;
V_12 -> V_15 = V_2 ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
return F_22 ( V_12 , V_34 ) ;
}
static int F_29 ( struct V_11 * V_12 )
{
return F_22 ( V_12 , V_58 ) ;
}
static T_4 F_30 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_4 V_30 )
{
T_4 V_59 = ( ~ ( V_30 - 1 ) & V_8 ) | V_7 ;
T_1 V_60 = 0 ;
T_1 V_5 ;
V_60 = F_1 ( V_2 , V_6 ) ;
V_5 = ( V_60 & 0x0000ffff ) | ( F_31 ( V_59 ) << 16 ) ;
F_3 ( V_2 , V_6 , V_5 ) ;
V_60 = F_1 ( V_2 , V_6 + 0x04 ) ;
V_5 = ( V_60 & 0xffff0000 ) | ( F_31 ( V_59 ) >> 16 ) ;
F_3 ( V_2 , V_6 + 0x04 , V_5 ) ;
V_60 = F_1 ( V_2 , V_6 + 0x04 ) ;
V_5 = ( V_60 & 0x0000ffff ) | ( F_32 ( V_59 ) << 16 ) ;
F_3 ( V_2 , V_6 + 0x04 , V_5 ) ;
V_60 = F_1 ( V_2 , V_6 + 0x08 ) ;
V_5 = ( V_60 & 0xffff0000 ) | ( F_32 ( V_59 ) >> 16 ) ;
F_3 ( V_2 , V_6 + 0x08 , V_5 ) ;
return V_59 ;
}
static void F_33 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 * V_62 )
{
T_1 V_60 ;
V_2 -> V_63 = false ;
V_60 = F_1 ( V_2 , V_64 ) ;
if ( V_60 & V_65 ) {
V_2 -> V_63 = true ;
* V_62 = F_34 ( V_60 ) ;
V_60 = F_1 ( V_2 , V_66 ) ;
* V_61 = V_60 >> 26 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
int V_67 ;
V_2 -> V_68 = F_36 ( V_42 , NULL ) ;
if ( F_27 ( V_2 -> V_68 ) ) {
F_19 ( V_42 , L_4 ) ;
return - V_69 ;
}
V_67 = F_37 ( V_2 -> V_68 ) ;
if ( V_67 ) {
F_19 ( V_42 , L_5 ) ;
return V_67 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_39 * V_40 ;
V_40 = F_39 ( V_71 , V_48 , L_6 ) ;
V_2 -> V_4 = F_26 ( V_42 , V_40 ) ;
if ( F_27 ( V_2 -> V_4 ) )
return F_40 ( V_2 -> V_4 ) ;
V_40 = F_39 ( V_71 , V_48 , L_7 ) ;
V_2 -> V_18 = F_26 ( V_42 , V_40 ) ;
if ( F_27 ( V_2 -> V_18 ) )
return F_40 ( V_2 -> V_18 ) ;
V_2 -> V_72 = V_40 -> V_73 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_39 * V_40 , T_1 V_26 ,
T_4 V_74 , T_4 V_75 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_5 V_30 = F_42 ( V_40 ) ;
T_4 V_76 = F_43 ( V_40 ) ;
T_4 V_59 = 0 ;
T_1 V_77 ;
T_1 V_78 = V_79 ;
if ( V_76 == V_48 ) {
V_77 = V_80 ;
} else {
V_77 = 128 ;
V_78 |= V_81 ;
}
if ( V_30 >= V_77 )
V_59 = ~ ( V_30 - 1 ) | V_78 ;
else
F_44 ( V_42 , L_8 ,
( T_4 ) V_30 , V_77 ) ;
F_3 ( V_2 , V_26 , F_31 ( V_74 ) ) ;
F_3 ( V_2 , V_26 + 0x04 , F_32 ( V_74 ) ) ;
F_3 ( V_2 , V_26 + 0x08 , F_31 ( V_59 ) ) ;
F_3 ( V_2 , V_26 + 0x0c , F_32 ( V_59 ) ) ;
F_3 ( V_2 , V_26 + 0x10 , F_31 ( V_75 ) ) ;
F_3 ( V_2 , V_26 + 0x14 , F_32 ( V_75 ) ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_4 V_6 = V_2 -> V_72 ;
F_3 ( V_2 , V_82 , F_31 ( V_6 ) ) ;
F_3 ( V_2 , V_83 , F_32 ( V_6 ) ) ;
F_3 ( V_2 , V_84 , V_79 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_45 * V_40 ,
T_5 V_85 )
{
struct V_43 * V_86 ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_47 ;
F_47 (window, res) {
struct V_39 * V_40 = V_86 -> V_40 ;
T_4 V_76 = F_43 ( V_40 ) ;
F_48 ( V_42 , L_9 , V_40 ) ;
switch ( V_76 ) {
case V_87 :
F_41 ( V_2 , V_40 , V_88 , V_85 ,
V_40 -> V_73 - V_86 -> V_26 ) ;
V_47 = F_49 ( V_40 , V_85 ) ;
if ( V_47 < 0 )
return V_47 ;
break;
case V_48 :
if ( V_40 -> V_7 & V_89 )
F_41 ( V_2 , V_40 , V_90 ,
V_40 -> V_73 ,
V_40 -> V_73 -
V_86 -> V_26 ) ;
else
F_41 ( V_2 , V_40 , V_91 ,
V_40 -> V_73 ,
V_40 -> V_73 -
V_86 -> V_26 ) ;
break;
case V_92 :
break;
default:
F_19 ( V_42 , L_10 , V_40 ) ;
return - V_50 ;
}
}
F_45 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_93 ,
T_4 V_94 , T_4 V_30 )
{
F_3 ( V_2 , V_93 , F_31 ( V_94 ) ) ;
F_3 ( V_2 , V_93 + 0x04 ,
F_32 ( V_94 ) | V_95 ) ;
F_3 ( V_2 , V_93 + 0x10 , F_31 ( V_30 ) ) ;
F_3 ( V_2 , V_93 + 0x14 , F_32 ( V_30 ) ) ;
}
static int F_51 ( T_6 * V_96 , T_4 V_30 )
{
if ( ( V_30 > 4 ) && ( V_30 < V_97 ) && ! ( * V_96 & ( 1 << 1 ) ) ) {
* V_96 |= ( 1 << 1 ) ;
return 1 ;
}
if ( ( V_30 > V_98 ) && ( V_30 < V_99 ) && ! ( * V_96 & ( 1 << 0 ) ) ) {
* V_96 |= ( 1 << 0 ) ;
return 0 ;
}
if ( ( V_30 > V_100 ) && ( V_30 < V_99 ) && ! ( * V_96 & ( 1 << 2 ) ) ) {
* V_96 |= ( 1 << 2 ) ;
return 2 ;
}
return - V_50 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_101 * V_102 , T_6 * V_96 )
{
void T_2 * V_18 = V_2 -> V_18 ;
struct V_41 * V_42 = V_2 -> V_42 ;
void * V_103 ;
T_1 V_93 ;
T_4 V_74 = V_102 -> V_74 ;
T_4 V_75 = V_102 -> V_75 ;
T_4 V_30 = V_102 -> V_30 ;
T_4 V_59 = ~ ( V_30 - 1 ) | V_79 ;
T_1 V_7 = V_104 ;
T_1 V_105 ;
int V_106 ;
V_106 = F_51 ( V_96 , V_102 -> V_30 ) ;
if ( V_106 < 0 ) {
F_44 ( V_42 , L_11 ) ;
return;
}
if ( V_102 -> V_7 & V_89 )
V_7 |= V_107 ;
V_105 = F_5 ( ( T_1 ) V_74 , V_7 ) ;
switch ( V_106 ) {
case 0 :
F_30 ( V_2 , V_108 , V_7 , V_30 ) ;
V_103 = V_18 + V_27 ;
F_4 ( V_105 , V_103 ) ;
F_4 ( F_32 ( V_74 ) , V_103 + 0x4 ) ;
V_93 = V_109 ;
break;
case 1 :
F_3 ( V_2 , V_110 , V_105 ) ;
F_3 ( V_2 , V_111 , F_31 ( V_59 ) ) ;
V_93 = V_112 ;
break;
case 2 :
F_3 ( V_2 , V_113 , V_105 ) ;
F_3 ( V_2 , V_113 + 0x4 , F_32 ( V_74 ) ) ;
F_3 ( V_2 , V_114 , F_31 ( V_59 ) ) ;
F_3 ( V_2 , V_114 + 0x4 , F_32 ( V_59 ) ) ;
V_93 = V_115 ;
break;
}
F_50 ( V_2 , V_93 , V_75 , ~ ( V_30 - 1 ) ) ;
}
static int F_53 ( struct V_116 * V_117 ,
struct V_118 * V_51 )
{
const int V_119 = 3 , V_120 = 2 ;
int V_121 ;
V_117 -> V_51 = V_51 ;
V_117 -> V_122 = F_54 ( V_51 ) ;
V_117 -> V_123 = V_117 -> V_122 + V_119 + V_120 ;
V_117 -> V_102 = F_55 ( V_51 , L_12 , & V_121 ) ;
if ( ! V_117 -> V_102 )
return - V_124 ;
V_117 -> V_125 = V_117 -> V_102 + V_121 / sizeof( V_126 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_118 * V_123 = V_2 -> V_51 ;
struct V_101 V_102 ;
struct V_116 V_117 ;
struct V_41 * V_42 = V_2 -> V_42 ;
T_6 V_96 = 0 ;
if ( F_53 ( & V_117 , V_123 ) ) {
F_19 ( V_42 , L_13 ) ;
return - V_50 ;
}
F_57 (&parser, &range) {
T_4 V_125 = V_102 . V_74 + V_102 . V_30 - 1 ;
F_48 ( V_42 , L_14 ,
V_102 . V_7 , V_102 . V_74 , V_125 , V_102 . V_75 ) ;
F_52 ( V_2 , & V_102 , & V_96 ) ;
}
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = V_109 ; V_127 <= V_84 ; V_127 += 4 )
F_3 ( V_2 , V_127 , 0 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_45 * V_40 ,
T_5 V_85 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_1 V_5 , V_61 = 0 , V_62 = 0 ;
int V_47 ;
F_58 ( V_2 ) ;
V_5 = ( V_128 << 16 ) | V_129 ;
F_3 ( V_2 , V_130 , V_5 ) ;
V_47 = F_46 ( V_2 , V_40 , V_85 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_56 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_33 ( V_2 , & V_61 , & V_62 ) ;
if ( ! V_2 -> V_63 )
F_60 ( V_42 , L_15 ) ;
else
F_60 ( V_42 , L_16 , V_61 , V_62 + 1 ) ;
return 0 ;
}
static int F_61 ( struct V_70 * V_71 )
{
struct V_41 * V_42 = & V_71 -> V_42 ;
struct V_118 * V_131 = V_42 -> V_132 ;
struct V_1 * V_2 ;
T_5 V_133 = 0 ;
struct V_9 * V_10 ;
int V_47 ;
F_62 ( V_40 ) ;
V_2 = F_24 ( V_42 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_51 = F_63 ( V_131 ) ;
V_2 -> V_42 = V_42 ;
V_2 -> V_33 = V_134 ;
if ( F_64 ( V_2 -> V_51 , L_17 ) )
V_2 -> V_33 = V_34 ;
V_47 = F_38 ( V_2 , V_71 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_2 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_65 ( V_131 , 0 , 0xff , & V_40 , & V_133 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_66 ( V_42 , & V_40 ) ;
if ( V_47 )
goto error;
V_47 = F_59 ( V_2 , & V_40 , V_133 ) ;
if ( V_47 )
goto error;
V_10 = F_67 ( V_42 , 0 , & V_135 , V_2 , & V_40 ) ;
if ( ! V_10 ) {
V_47 = - V_56 ;
goto error;
}
F_68 ( V_10 ) ;
F_69 ( V_10 ) ;
F_70 ( V_10 ) ;
return 0 ;
error:
F_71 ( & V_40 ) ;
return V_47 ;
}
