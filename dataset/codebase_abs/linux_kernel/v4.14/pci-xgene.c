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
( ( V_29 & ~ 0x3 ) == V_35 + V_36 ) )
* V_5 &= ~ ( V_37 << 16 ) ;
if ( V_30 <= 2 )
* V_5 = ( * V_5 >> ( 8 * ( V_29 & 3 ) ) ) & ( ( 1 << ( V_30 * 8 ) ) - 1 ) ;
return V_31 ;
}
static int F_16 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = & V_39 -> V_43 ;
struct V_44 * V_45 ;
struct V_46 V_47 ;
unsigned long V_7 ;
int V_48 ;
F_17 ( & V_47 ) ;
V_7 = V_49 ;
V_48 = F_18 ( V_39 , & V_47 ,
V_50 ,
( void * ) V_7 ) ;
if ( V_48 < 0 ) {
F_19 ( V_43 , L_1 ,
V_48 ) ;
return V_48 ;
}
if ( V_48 == 0 ) {
F_19 ( V_43 , L_2 ) ;
return - V_51 ;
}
V_45 = F_20 ( & V_47 , struct V_44 , V_52 ) ;
* V_41 = * V_45 -> V_41 ;
F_21 ( & V_47 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 , T_1 V_53 )
{
struct V_42 * V_43 = V_12 -> V_54 ;
struct V_38 * V_39 = F_23 ( V_43 ) ;
struct V_1 * V_2 ;
struct V_40 V_55 ;
int V_48 ;
V_2 = F_24 ( V_43 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_57 ;
V_48 = F_16 ( V_39 , & V_55 ) ;
if ( V_48 ) {
F_19 ( V_43 , L_3 ) ;
return V_48 ;
}
V_2 -> V_4 = F_25 ( V_43 , & V_55 ) ;
if ( F_26 ( V_2 -> V_4 ) )
return F_27 ( V_2 -> V_4 ) ;
V_2 -> V_18 = V_12 -> V_58 ;
V_2 -> V_33 = V_53 ;
V_12 -> V_15 = V_2 ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
return F_22 ( V_12 , V_34 ) ;
}
static int F_29 ( struct V_11 * V_12 )
{
return F_22 ( V_12 , V_59 ) ;
}
static T_4 F_30 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_4 V_30 )
{
T_4 V_60 = ( ~ ( V_30 - 1 ) & V_8 ) | V_7 ;
T_1 V_61 = 0 ;
T_1 V_5 ;
V_61 = F_1 ( V_2 , V_6 ) ;
V_5 = ( V_61 & 0x0000ffff ) | ( F_31 ( V_60 ) << 16 ) ;
F_3 ( V_2 , V_6 , V_5 ) ;
V_61 = F_1 ( V_2 , V_6 + 0x04 ) ;
V_5 = ( V_61 & 0xffff0000 ) | ( F_31 ( V_60 ) >> 16 ) ;
F_3 ( V_2 , V_6 + 0x04 , V_5 ) ;
V_61 = F_1 ( V_2 , V_6 + 0x04 ) ;
V_5 = ( V_61 & 0x0000ffff ) | ( F_32 ( V_60 ) << 16 ) ;
F_3 ( V_2 , V_6 + 0x04 , V_5 ) ;
V_61 = F_1 ( V_2 , V_6 + 0x08 ) ;
V_5 = ( V_61 & 0xffff0000 ) | ( F_32 ( V_60 ) >> 16 ) ;
F_3 ( V_2 , V_6 + 0x08 , V_5 ) ;
return V_60 ;
}
static void F_33 ( struct V_1 * V_2 ,
T_1 * V_62 , T_1 * V_63 )
{
T_1 V_61 ;
V_2 -> V_64 = false ;
V_61 = F_1 ( V_2 , V_65 ) ;
if ( V_61 & V_66 ) {
V_2 -> V_64 = true ;
* V_63 = F_34 ( V_61 ) ;
V_61 = F_1 ( V_2 , V_67 ) ;
* V_62 = V_61 >> 26 ;
}
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
int V_68 ;
V_2 -> V_69 = F_36 ( V_43 , NULL ) ;
if ( F_26 ( V_2 -> V_69 ) ) {
F_19 ( V_43 , L_4 ) ;
return - V_70 ;
}
V_68 = F_37 ( V_2 -> V_69 ) ;
if ( V_68 ) {
F_19 ( V_43 , L_5 ) ;
return V_68 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_40 * V_41 ;
V_41 = F_39 ( V_72 , V_49 , L_6 ) ;
V_2 -> V_4 = F_25 ( V_43 , V_41 ) ;
if ( F_26 ( V_2 -> V_4 ) )
return F_27 ( V_2 -> V_4 ) ;
V_41 = F_39 ( V_72 , V_49 , L_7 ) ;
V_2 -> V_18 = F_40 ( V_43 , V_41 ) ;
if ( F_26 ( V_2 -> V_18 ) )
return F_27 ( V_2 -> V_18 ) ;
V_2 -> V_73 = V_41 -> V_74 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_1 V_26 ,
T_4 V_75 , T_4 V_76 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
T_5 V_30 = F_42 ( V_41 ) ;
T_4 V_77 = F_43 ( V_41 ) ;
T_4 V_60 = 0 ;
T_1 V_78 ;
T_1 V_79 = V_80 ;
if ( V_77 == V_49 ) {
V_78 = V_81 ;
} else {
V_78 = 128 ;
V_79 |= V_82 ;
}
if ( V_30 >= V_78 )
V_60 = ~ ( V_30 - 1 ) | V_79 ;
else
F_44 ( V_43 , L_8 ,
( T_4 ) V_30 , V_78 ) ;
F_3 ( V_2 , V_26 , F_31 ( V_75 ) ) ;
F_3 ( V_2 , V_26 + 0x04 , F_32 ( V_75 ) ) ;
F_3 ( V_2 , V_26 + 0x08 , F_31 ( V_60 ) ) ;
F_3 ( V_2 , V_26 + 0x0c , F_32 ( V_60 ) ) ;
F_3 ( V_2 , V_26 + 0x10 , F_31 ( V_76 ) ) ;
F_3 ( V_2 , V_26 + 0x14 , F_32 ( V_76 ) ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_4 V_6 = V_2 -> V_73 ;
F_3 ( V_2 , V_83 , F_31 ( V_6 ) ) ;
F_3 ( V_2 , V_84 , F_32 ( V_6 ) ) ;
F_3 ( V_2 , V_85 , V_80 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_46 * V_41 ,
T_5 V_86 )
{
struct V_44 * V_87 ;
struct V_42 * V_43 = V_2 -> V_43 ;
int V_48 ;
F_47 (window, res) {
struct V_40 * V_41 = V_87 -> V_41 ;
T_4 V_77 = F_43 ( V_41 ) ;
F_48 ( V_43 , L_9 , V_41 ) ;
switch ( V_77 ) {
case V_88 :
F_41 ( V_2 , V_41 , V_89 , V_86 ,
V_41 -> V_74 - V_87 -> V_26 ) ;
V_48 = F_49 ( V_41 , V_86 ) ;
if ( V_48 < 0 )
return V_48 ;
break;
case V_49 :
if ( V_41 -> V_7 & V_90 )
F_41 ( V_2 , V_41 , V_91 ,
V_41 -> V_74 ,
V_41 -> V_74 -
V_87 -> V_26 ) ;
else
F_41 ( V_2 , V_41 , V_92 ,
V_41 -> V_74 ,
V_41 -> V_74 -
V_87 -> V_26 ) ;
break;
case V_93 :
break;
default:
F_19 ( V_43 , L_10 , V_41 ) ;
return - V_51 ;
}
}
F_45 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 V_94 ,
T_4 V_95 , T_4 V_30 )
{
F_3 ( V_2 , V_94 , F_31 ( V_95 ) ) ;
F_3 ( V_2 , V_94 + 0x04 ,
F_32 ( V_95 ) | V_96 ) ;
F_3 ( V_2 , V_94 + 0x10 , F_31 ( V_30 ) ) ;
F_3 ( V_2 , V_94 + 0x14 , F_32 ( V_30 ) ) ;
}
static int F_51 ( T_6 * V_97 , T_4 V_30 )
{
if ( ( V_30 > 4 ) && ( V_30 < V_98 ) && ! ( * V_97 & ( 1 << 1 ) ) ) {
* V_97 |= ( 1 << 1 ) ;
return 1 ;
}
if ( ( V_30 > V_99 ) && ( V_30 < V_100 ) && ! ( * V_97 & ( 1 << 0 ) ) ) {
* V_97 |= ( 1 << 0 ) ;
return 0 ;
}
if ( ( V_30 > V_101 ) && ( V_30 < V_100 ) && ! ( * V_97 & ( 1 << 2 ) ) ) {
* V_97 |= ( 1 << 2 ) ;
return 2 ;
}
return - V_51 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_102 * V_103 , T_6 * V_97 )
{
void T_2 * V_18 = V_2 -> V_18 ;
struct V_42 * V_43 = V_2 -> V_43 ;
void * V_104 ;
T_1 V_94 ;
T_4 V_75 = V_103 -> V_75 ;
T_4 V_76 = V_103 -> V_76 ;
T_4 V_30 = V_103 -> V_30 ;
T_4 V_60 = ~ ( V_30 - 1 ) | V_80 ;
T_1 V_7 = V_105 ;
T_1 V_106 ;
int V_107 ;
V_107 = F_51 ( V_97 , V_103 -> V_30 ) ;
if ( V_107 < 0 ) {
F_44 ( V_43 , L_11 ) ;
return;
}
if ( V_103 -> V_7 & V_90 )
V_7 |= V_108 ;
V_106 = F_5 ( ( T_1 ) V_75 , V_7 ) ;
switch ( V_107 ) {
case 0 :
F_30 ( V_2 , V_109 , V_7 , V_30 ) ;
V_104 = V_18 + V_27 ;
F_4 ( V_106 , V_104 ) ;
F_4 ( F_32 ( V_75 ) , V_104 + 0x4 ) ;
V_94 = V_110 ;
break;
case 1 :
F_3 ( V_2 , V_111 , V_106 ) ;
F_3 ( V_2 , V_112 , F_31 ( V_60 ) ) ;
V_94 = V_113 ;
break;
case 2 :
F_3 ( V_2 , V_114 , V_106 ) ;
F_3 ( V_2 , V_114 + 0x4 , F_32 ( V_75 ) ) ;
F_3 ( V_2 , V_115 , F_31 ( V_60 ) ) ;
F_3 ( V_2 , V_115 + 0x4 , F_32 ( V_60 ) ) ;
V_94 = V_116 ;
break;
}
F_50 ( V_2 , V_94 , V_76 , ~ ( V_30 - 1 ) ) ;
}
static int F_53 ( struct V_117 * V_118 ,
struct V_119 * V_52 )
{
const int V_120 = 3 , V_121 = 2 ;
int V_122 ;
V_118 -> V_52 = V_52 ;
V_118 -> V_123 = F_54 ( V_52 ) ;
V_118 -> V_124 = V_118 -> V_123 + V_120 + V_121 ;
V_118 -> V_103 = F_55 ( V_52 , L_12 , & V_122 ) ;
if ( ! V_118 -> V_103 )
return - V_125 ;
V_118 -> V_126 = V_118 -> V_103 + V_122 / sizeof( V_127 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_119 * V_124 = V_2 -> V_52 ;
struct V_102 V_103 ;
struct V_117 V_118 ;
struct V_42 * V_43 = V_2 -> V_43 ;
T_6 V_97 = 0 ;
if ( F_53 ( & V_118 , V_124 ) ) {
F_19 ( V_43 , L_13 ) ;
return - V_51 ;
}
F_57 (&parser, &range) {
T_4 V_126 = V_103 . V_75 + V_103 . V_30 - 1 ;
F_48 ( V_43 , L_14 ,
V_103 . V_7 , V_103 . V_75 , V_126 , V_103 . V_76 ) ;
F_52 ( V_2 , & V_103 , & V_97 ) ;
}
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_128 ;
for ( V_128 = V_110 ; V_128 <= V_85 ; V_128 += 4 )
F_3 ( V_2 , V_128 , 0 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_46 * V_41 ,
T_5 V_86 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
T_1 V_5 , V_62 = 0 , V_63 = 0 ;
int V_48 ;
F_58 ( V_2 ) ;
V_5 = ( V_129 << 16 ) | V_130 ;
F_3 ( V_2 , V_131 , V_5 ) ;
V_48 = F_46 ( V_2 , V_41 , V_86 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_56 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_33 ( V_2 , & V_62 , & V_63 ) ;
if ( ! V_2 -> V_64 )
F_60 ( V_43 , L_15 ) ;
else
F_60 ( V_43 , L_16 , V_62 , V_63 + 1 ) ;
return 0 ;
}
static int F_61 ( struct V_71 * V_72 )
{
struct V_42 * V_43 = & V_72 -> V_43 ;
struct V_119 * V_132 = V_43 -> V_133 ;
struct V_1 * V_2 ;
T_5 V_134 = 0 ;
struct V_9 * V_10 , * V_135 ;
struct V_136 * V_137 ;
int V_48 ;
F_62 ( V_41 ) ;
V_137 = F_63 ( V_43 , sizeof( * V_2 ) ) ;
if ( ! V_137 )
return - V_57 ;
V_2 = F_64 ( V_137 ) ;
V_2 -> V_52 = F_65 ( V_132 ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_33 = V_138 ;
if ( F_66 ( V_2 -> V_52 , L_17 ) )
V_2 -> V_33 = V_34 ;
V_48 = F_38 ( V_2 , V_72 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_35 ( V_2 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_67 ( V_132 , 0 , 0xff , & V_41 , & V_134 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_68 ( V_43 , & V_41 ) ;
if ( V_48 )
goto error;
V_48 = F_59 ( V_2 , & V_41 , V_134 ) ;
if ( V_48 )
goto error;
F_69 ( & V_41 , & V_137 -> V_139 ) ;
V_137 -> V_43 . V_54 = V_43 ;
V_137 -> V_14 = V_2 ;
V_137 -> V_140 = 0 ;
V_137 -> V_141 = & V_142 ;
V_137 -> V_143 = V_144 ;
V_137 -> V_145 = V_146 ;
V_48 = F_70 ( V_137 ) ;
if ( V_48 < 0 )
goto error;
V_10 = V_137 -> V_10 ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
F_73 (child, &bus->children, node)
F_74 ( V_135 ) ;
F_75 ( V_10 ) ;
return 0 ;
error:
F_76 ( & V_41 ) ;
return V_48 ;
}
