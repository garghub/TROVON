static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 * V_7 , T_1 V_8 , T_2 V_9 )
{
T_1 V_10 = F_5 ( V_2 -> V_6 + V_8 ) ;
memcpy ( V_7 , & V_10 , ( V_9 & 3 ) + 1 ) ;
}
static void
F_6 ( struct V_1 * V_2 , const T_2 * V_7 , T_1 V_8 , T_2 V_9 )
{
T_1 V_10 = 0 ;
memcpy ( & V_10 , V_7 , ( V_9 & 3 ) + 1 ) ;
F_7 ( V_10 , V_2 -> V_5 + V_8 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
void T_3 * V_13 , T_2 V_14 , T_4 V_15 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
T_1 V_16 = 0 ;
T_1 V_17 = V_18 ;
T_1 V_3 ;
int V_19 ;
V_19 = V_2 -> V_20 -> V_3 ( V_2 , V_14 , V_15 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_3 += V_21 ;
while ( V_17 -- ) {
V_16 = F_10 ( V_13 + V_3 ) ;
if ( V_16 & V_22 ) {
if ( V_16 & V_23 ) {
F_11 ( & V_12 -> V_2 ,
L_1 ,
V_24 , V_16 ) ;
return - V_25 ;
}
if ( V_16 & V_26 ) {
F_11 ( & V_12 -> V_2 ,
L_2 ,
V_24 , V_16 ) ;
return - V_27 ;
}
if ( V_16 & V_28 ) {
F_11 ( & V_12 -> V_2 ,
L_3 ,
V_24 , V_16 ) ;
return - V_27 ;
}
return 0 ;
}
F_12 ( 1 ) ;
}
F_11 ( & V_12 -> V_2 ,
L_4 ,
V_24 , V_16 ) ;
return - V_29 ;
}
static int
F_13 ( struct V_11 * V_12 , T_2 V_30 , T_2 V_14 )
{
struct V_1 * V_31 = F_9 ( V_12 ) ;
unsigned long V_32 ;
T_1 V_33 ;
int V_19 ;
T_1 V_3 ;
V_19 = V_31 -> V_20 -> V_3 ( V_31 , V_14 , 0 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_33 = ( ( V_30 | 0x40 ) << 27 ) | ( ( V_14 & 0xf ) << 20 ) ;
F_14 ( & V_31 -> V_34 , V_32 ) ;
F_1 ( V_31 , V_3 + V_35 , V_33 ) ;
V_19 = F_8 ( V_12 , V_31 -> V_5 , V_14 , 0 ) ;
F_15 ( & V_31 -> V_34 , V_32 ) ;
return V_19 ;
}
static int
F_16 ( struct V_11 * V_12 , T_2 V_30 , T_2 V_14 )
{
return - V_36 ;
}
static int F_17 ( struct V_11 * V_12 , T_2 V_30 , T_2 V_14 )
{
struct V_1 * V_31 = F_9 ( V_12 ) ;
F_18 ( & V_12 -> V_2 , L_5 , V_30 , V_14 ) ;
if ( V_30 < V_37 || V_30 > V_38 )
return - V_39 ;
return V_31 -> V_20 -> V_40 ( V_12 , V_30 , V_14 ) ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_30 , T_2 V_14 ,
T_4 V_15 , T_2 * V_7 , T_5 V_41 )
{
struct V_1 * V_31 = F_9 ( V_12 ) ;
unsigned long V_32 ;
T_2 V_9 = V_41 - 1 ;
T_1 V_33 ;
int V_19 ;
T_1 V_3 ;
V_19 = V_31 -> V_20 -> V_3 ( V_31 , V_14 , V_15 , & V_3 ) ;
if ( V_19 )
return V_19 ;
if ( V_9 >= V_42 ) {
F_11 ( & V_12 -> V_2 ,
L_6 ,
V_42 , V_41 ) ;
return - V_39 ;
}
if ( V_30 >= 0x60 && V_30 <= 0x7F )
V_30 = V_43 ;
else if ( V_30 >= 0x20 && V_30 <= 0x2F )
V_30 = V_44 ;
else if ( V_30 >= 0x38 && V_30 <= 0x3F )
V_30 = V_45 ;
else
return - V_39 ;
V_33 = V_31 -> V_20 -> V_46 ( V_30 , V_14 , V_15 , V_9 ) ;
F_14 ( & V_31 -> V_34 , V_32 ) ;
F_3 ( V_31 , V_3 + V_35 , V_33 ) ;
V_19 = F_8 ( V_12 , V_31 -> V_6 , V_14 , V_15 ) ;
if ( V_19 )
goto V_47;
F_4 ( V_31 , V_7 , V_3 + V_48 ,
F_20 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_4 ( V_31 , V_7 + 4 ,
V_3 + V_49 , V_9 - 4 ) ;
V_47:
F_15 ( & V_31 -> V_34 , V_32 ) ;
return V_19 ;
}
static int F_21 ( struct V_11 * V_12 , T_2 V_30 , T_2 V_14 ,
T_4 V_15 , const T_2 * V_7 , T_5 V_41 )
{
struct V_1 * V_31 = F_9 ( V_12 ) ;
unsigned long V_32 ;
T_2 V_9 = V_41 - 1 ;
T_1 V_33 ;
int V_19 ;
T_1 V_3 ;
V_19 = V_31 -> V_20 -> V_3 ( V_31 , V_14 , V_15 , & V_3 ) ;
if ( V_19 )
return V_19 ;
if ( V_9 >= V_42 ) {
F_11 ( & V_12 -> V_2 ,
L_6 ,
V_42 , V_41 ) ;
return - V_39 ;
}
if ( V_30 >= 0x40 && V_30 <= 0x5F )
V_30 = V_50 ;
else if ( V_30 >= 0x00 && V_30 <= 0x0F )
V_30 = V_51 ;
else if ( V_30 >= 0x30 && V_30 <= 0x37 )
V_30 = V_52 ;
else if ( V_30 >= 0x80 )
V_30 = V_53 ;
else
return - V_39 ;
V_33 = V_31 -> V_20 -> V_46 ( V_30 , V_14 , V_15 , V_9 ) ;
F_14 ( & V_31 -> V_34 , V_32 ) ;
F_6 ( V_31 , V_7 , V_3 + V_54 ,
F_20 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_6 ( V_31 , V_7 + 4 ,
V_3 + V_55 , V_9 - 4 ) ;
F_1 ( V_31 , V_3 + V_35 , V_33 ) ;
V_19 = F_8 ( V_12 , V_31 -> V_5 , V_14 , V_15 ) ;
F_15 ( & V_31 -> V_34 , V_32 ) ;
return V_19 ;
}
static void F_22 ( struct V_56 * V_57 , T_2 V_8 , void * V_7 ,
T_5 V_41 )
{
struct V_1 * V_58 = F_23 ( V_57 ) ;
T_2 V_14 = V_57 -> V_59 >> 24 ;
T_2 V_60 = V_57 -> V_59 >> 16 ;
if ( F_21 ( V_58 -> V_61 , V_62 , V_14 ,
( V_60 << 8 ) + V_8 , V_7 , V_41 ) )
F_24 ( & V_58 -> V_61 -> V_2 ,
L_7 ,
V_57 -> V_63 ) ;
}
static void F_25 ( struct V_56 * V_57 , T_2 V_8 , void * V_7 , T_5 V_41 )
{
struct V_1 * V_58 = F_23 ( V_57 ) ;
T_2 V_14 = V_57 -> V_59 >> 24 ;
T_2 V_60 = V_57 -> V_59 >> 16 ;
if ( F_19 ( V_58 -> V_61 , V_64 , V_14 ,
( V_60 << 8 ) + V_8 , V_7 , V_41 ) )
F_24 ( & V_58 -> V_61 -> V_2 ,
L_7 ,
V_57 -> V_63 ) ;
}
static void F_26 ( struct V_1 * V_58 , T_2 V_65 )
{
unsigned int V_63 ;
T_1 V_16 ;
int V_66 ;
V_16 = F_10 ( V_58 -> V_67 + V_58 -> V_20 -> V_68 ( V_65 ) ) ;
while ( V_16 ) {
V_66 = F_27 ( V_16 ) - 1 ;
V_16 &= ~ ( 1 << V_66 ) ;
V_63 = F_28 ( V_58 -> V_69 ,
V_58 -> V_70 [ V_65 ] << 16
| V_66 << 8
| V_65 ) ;
F_29 ( V_63 ) ;
}
}
static void F_30 ( struct V_71 * V_72 )
{
struct V_1 * V_58 = F_31 ( V_72 ) ;
struct V_73 * V_74 = F_32 ( V_72 ) ;
void T_3 * V_67 = V_58 -> V_67 ;
int V_75 = V_58 -> V_76 >> 5 ;
int V_77 = V_58 -> V_78 >> 5 ;
T_1 V_16 ;
int V_79 , V_66 ;
F_33 ( V_74 , V_72 ) ;
for ( V_79 = V_75 ; V_79 <= V_77 ; ++ V_79 ) {
V_16 = F_10 ( V_67 +
V_58 -> V_20 -> V_80 ( V_58 -> V_81 , V_79 ) ) ;
while ( V_16 ) {
V_66 = F_27 ( V_16 ) - 1 ;
V_16 &= ~ ( 1 << V_66 ) ;
F_26 ( V_58 , V_66 + V_79 * 32 ) ;
}
}
F_34 ( V_74 , V_72 ) ;
}
static void F_35 ( struct V_56 * V_57 )
{
struct V_1 * V_58 = F_23 ( V_57 ) ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_65 = V_57 -> V_59 ;
unsigned long V_32 ;
T_2 V_10 ;
F_14 ( & V_58 -> V_34 , V_32 ) ;
F_2 ( 1 << V_63 , V_58 -> V_67 + V_58 -> V_20 -> V_82 ( V_65 ) ) ;
F_15 ( & V_58 -> V_34 , V_32 ) ;
V_10 = 1 << V_63 ;
F_22 ( V_57 , V_83 , & V_10 , 1 ) ;
}
static void F_36 ( struct V_56 * V_57 )
{
struct V_1 * V_58 = F_23 ( V_57 ) ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_65 = V_57 -> V_59 ;
unsigned long V_32 ;
T_1 V_16 ;
T_2 V_10 ;
F_14 ( & V_58 -> V_34 , V_32 ) ;
V_16 = F_10 ( V_58 -> V_67 + V_58 -> V_20 -> V_84 ( V_65 ) ) ;
if ( V_16 & V_85 ) {
V_16 = V_16 & ~ V_85 ;
F_2 ( V_16 , V_58 -> V_67 +
V_58 -> V_20 -> V_84 ( V_65 ) ) ;
}
F_15 ( & V_58 -> V_34 , V_32 ) ;
V_10 = 1 << V_63 ;
F_22 ( V_57 , V_86 , & V_10 , 1 ) ;
}
static void F_37 ( struct V_56 * V_57 )
{
struct V_1 * V_58 = F_23 ( V_57 ) ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_65 = V_57 -> V_59 ;
unsigned long V_32 ;
T_1 V_16 ;
T_2 V_10 ;
F_14 ( & V_58 -> V_34 , V_32 ) ;
V_16 = F_10 ( V_58 -> V_67 + V_58 -> V_20 -> V_84 ( V_65 ) ) ;
if ( ! ( V_16 & V_85 ) ) {
F_2 ( V_16 | V_85 ,
V_58 -> V_67 + V_58 -> V_20 -> V_84 ( V_65 ) ) ;
}
F_15 ( & V_58 -> V_34 , V_32 ) ;
V_10 = 1 << V_63 ;
F_22 ( V_57 , V_87 , & V_10 , 1 ) ;
}
static void F_38 ( struct V_56 * V_57 )
{
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_10 ;
F_37 ( V_57 ) ;
V_10 = 1 << V_63 ;
F_22 ( V_57 , V_83 , & V_10 , 1 ) ;
}
static int F_39 ( struct V_56 * V_57 , unsigned int V_88 )
{
struct V_89 type ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
F_25 ( V_57 , V_90 , & type , sizeof( type ) ) ;
if ( V_88 & ( V_91 | V_92 ) ) {
type . type |= 1 << V_63 ;
if ( V_88 & V_91 )
type . V_93 |= 1 << V_63 ;
if ( V_88 & V_92 )
type . V_94 |= 1 << V_63 ;
} else {
if ( ( V_88 & ( V_95 ) ) &&
( V_88 & ( V_96 ) ) )
return - V_39 ;
type . type &= ~ ( 1 << V_63 ) ;
if ( V_88 & V_95 )
type . V_93 |= 1 << V_63 ;
else
type . V_94 |= 1 << V_63 ;
}
F_22 ( V_57 , V_90 , & type , sizeof( type ) ) ;
return 0 ;
}
static int F_40 ( struct V_56 * V_57 ,
enum V_97 V_98 ,
bool * V_99 )
{
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_16 = 0 ;
if ( V_98 != V_100 )
return - V_39 ;
F_25 ( V_57 , V_101 , & V_16 , 1 ) ;
* V_99 = ! ! ( V_16 & F_41 ( V_63 ) ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_58 ,
struct V_102 * V_103 ,
T_2 * V_65 )
{
T_4 V_104 = V_103 -> V_105 << 8 | V_103 -> V_60 ;
T_1 * V_106 = V_58 -> V_106 ;
int V_107 = 0 , V_79 ;
T_1 V_10 ;
for ( V_79 = 0 ; V_79 < V_108 ; ++ V_79 ) {
if ( ! F_43 ( V_107 , V_58 -> V_109 ) )
V_106 [ V_107 ] = F_10 ( V_58 -> V_110 +
F_44 ( V_107 ) ) ;
V_10 = V_106 [ V_107 ] ;
if ( V_104 & ( 1 << F_45 ( V_10 ) ) ) {
if ( F_46 ( V_10 ) ) {
V_107 = F_47 ( V_10 ) ;
} else {
* V_65 = F_47 ( V_10 ) ;
return 0 ;
}
} else {
if ( F_48 ( V_10 ) ) {
V_107 = F_49 ( V_10 ) ;
} else {
* V_65 = F_49 ( V_10 ) ;
return 0 ;
}
}
}
return - V_111 ;
}
static int F_50 ( struct V_112 * V_57 ,
struct V_113 * V_114 ,
const T_1 * V_115 ,
unsigned int V_116 ,
unsigned long * V_117 ,
unsigned int * V_118 )
{
struct V_1 * V_58 = V_57 -> V_119 ;
struct V_102 V_103 ;
int V_120 ;
T_2 V_65 ;
F_18 ( & V_58 -> V_61 -> V_2 ,
L_8 ,
V_115 [ 0 ] , V_115 [ 1 ] , V_115 [ 2 ] ) ;
if ( F_51 ( V_57 ) != V_114 )
return - V_39 ;
if ( V_116 != 4 )
return - V_39 ;
if ( V_115 [ 0 ] > 0xF || V_115 [ 1 ] > 0xFF || V_115 [ 2 ] > 0x7 )
return - V_39 ;
V_103 . V_105 = V_115 [ 0 ] ;
V_103 . V_60 = V_115 [ 1 ] ;
V_103 . V_63 = V_115 [ 2 ] ;
V_120 = F_42 ( V_58 , & V_103 , & V_65 ) ;
if ( V_120 )
return V_120 ;
V_58 -> V_70 [ V_65 ] = V_103 . V_105 << 8 | V_103 . V_60 ;
if ( V_65 > V_58 -> V_78 )
V_58 -> V_78 = V_65 ;
if ( V_65 < V_58 -> V_76 )
V_58 -> V_76 = V_65 ;
* V_117 = V_103 . V_105 << 24
| V_103 . V_60 << 16
| V_103 . V_63 << 8
| V_65 ;
* V_118 = V_115 [ 3 ] & V_121 ;
F_18 ( & V_58 -> V_61 -> V_2 , L_9 , * V_117 ) ;
return 0 ;
}
static int F_52 ( struct V_112 * V_57 ,
unsigned int V_122 ,
T_6 V_59 )
{
struct V_1 * V_58 = V_57 -> V_119 ;
F_18 ( & V_58 -> V_61 -> V_2 , L_10 , V_122 , V_59 ) ;
F_53 ( V_122 , & V_123 , V_124 ) ;
F_54 ( V_122 , V_57 -> V_119 ) ;
F_55 ( V_122 ) ;
return 0 ;
}
static int
F_56 ( struct V_1 * V_58 , T_2 V_14 , T_4 V_15 , T_1 * V_3 )
{
* V_3 = 0x800 + 0x80 * V_58 -> V_125 ;
return 0 ;
}
static T_4 F_57 ( struct V_1 * V_58 , T_4 V_104 )
{
T_1 V_126 , V_3 ;
T_4 V_127 ;
T_4 V_66 ;
for ( V_127 = V_58 -> V_128 ; ; V_127 ++ ) {
V_3 = F_58 ( V_127 ) ;
if ( V_3 >= V_58 -> V_129 )
break;
V_126 = F_10 ( V_58 -> V_130 + V_3 ) ;
if ( ! V_126 )
continue;
V_66 = ( V_126 >> 8 ) & V_131 ;
V_58 -> V_132 [ V_66 ] = V_127 | V_133 ;
if ( V_66 == V_104 ) {
V_127 |= V_133 ;
break;
}
}
V_58 -> V_128 = V_127 & ~ V_133 ;
return V_127 ;
}
static int
F_59 ( struct V_1 * V_58 , T_2 V_14 , T_4 V_15 , T_1 * V_3 )
{
T_4 V_104 = ( V_14 << 8 ) | ( V_15 >> 8 ) ;
T_4 V_127 ;
V_127 = V_58 -> V_132 [ V_104 ] ;
if ( ! ( V_127 & V_133 ) )
V_127 = F_57 ( V_58 , V_104 ) ;
if ( ! ( V_127 & V_133 ) )
return - V_111 ;
V_127 &= ~ V_133 ;
* V_3 = 0x1000 * V_58 -> V_81 + 0x8000 * V_127 ;
return 0 ;
}
static T_1 F_60 ( T_2 V_30 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_30 << 27 ) | ( ( V_14 & 0xf ) << 20 ) | ( V_15 << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_61 ( T_2 V_30 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_30 << 27 ) | ( ( V_15 & 0xff ) << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_62 ( T_2 V_134 , T_2 V_135 )
{
return 0x20 * V_134 + 0x4 * V_135 ;
}
static T_1 F_63 ( T_2 V_134 , T_2 V_135 )
{
return 0x100000 + 0x1000 * V_134 + 0x4 * V_135 ;
}
static T_1 F_64 ( T_2 V_135 )
{
return 0x200 + 0x4 * V_135 ;
}
static T_1 F_65 ( T_2 V_135 )
{
return 0x1000 * V_135 ;
}
static T_1 F_66 ( T_2 V_135 )
{
return 0x600 + 0x4 * V_135 ;
}
static T_1 F_67 ( T_2 V_135 )
{
return 0x4 + 0x1000 * V_135 ;
}
static T_1 F_68 ( T_2 V_135 )
{
return 0xA00 + 0x4 * V_135 ;
}
static T_1 F_69 ( T_2 V_135 )
{
return 0x8 + 0x1000 * V_135 ;
}
static int F_70 ( struct V_136 * V_137 )
{
struct V_1 * V_58 ;
struct V_11 * V_12 ;
struct V_138 * V_139 ;
void T_3 * V_130 ;
T_1 V_125 , V_81 , V_140 ;
int V_120 ;
bool V_141 ;
V_12 = F_71 ( & V_137 -> V_2 , sizeof( * V_58 ) ) ;
if ( ! V_12 )
return - V_142 ;
V_58 = F_9 ( V_12 ) ;
V_58 -> V_61 = V_12 ;
V_139 = F_72 ( V_137 , V_143 , L_11 ) ;
V_58 -> V_129 = F_73 ( V_139 ) ;
V_130 = F_74 ( & V_12 -> V_2 , V_139 ) ;
if ( F_75 ( V_130 ) ) {
V_120 = F_76 ( V_130 ) ;
goto V_144;
}
V_140 = F_10 ( V_130 + V_145 ) ;
V_141 = ( V_140 < V_146 ) ;
F_77 ( & V_12 -> V_2 , L_12 , ( V_141 ? 1 : 2 ) ,
V_140 ) ;
if ( V_141 ) {
V_58 -> V_20 = & V_147 ;
V_58 -> V_5 = V_130 ;
V_58 -> V_6 = V_130 ;
} else {
V_58 -> V_130 = V_130 ;
V_58 -> V_20 = & V_148 ;
V_139 = F_72 ( V_137 , V_143 ,
L_13 ) ;
V_58 -> V_6 = F_74 ( & V_12 -> V_2 , V_139 ) ;
if ( F_75 ( V_58 -> V_6 ) ) {
V_120 = F_76 ( V_58 -> V_6 ) ;
goto V_144;
}
V_139 = F_72 ( V_137 , V_143 ,
L_14 ) ;
V_58 -> V_5 = F_74 ( & V_12 -> V_2 , V_139 ) ;
if ( F_75 ( V_58 -> V_5 ) ) {
V_120 = F_76 ( V_58 -> V_5 ) ;
goto V_144;
}
V_58 -> V_132 = F_78 ( & V_12 -> V_2 ,
V_149 ,
sizeof( * V_58 -> V_132 ) ,
V_150 ) ;
if ( ! V_58 -> V_132 ) {
V_120 = - V_142 ;
goto V_144;
}
}
V_139 = F_72 ( V_137 , V_143 , L_15 ) ;
V_58 -> V_67 = F_74 ( & V_12 -> V_2 , V_139 ) ;
if ( F_75 ( V_58 -> V_67 ) ) {
V_120 = F_76 ( V_58 -> V_67 ) ;
goto V_144;
}
V_139 = F_72 ( V_137 , V_143 , L_16 ) ;
V_58 -> V_110 = F_74 ( & V_12 -> V_2 , V_139 ) ;
if ( F_75 ( V_58 -> V_110 ) ) {
V_120 = F_76 ( V_58 -> V_110 ) ;
goto V_144;
}
V_58 -> V_63 = F_79 ( V_137 , L_17 ) ;
if ( V_58 -> V_63 < 0 ) {
V_120 = V_58 -> V_63 ;
goto V_144;
}
V_120 = F_80 ( V_137 -> V_2 . V_151 , L_18 , & V_125 ) ;
if ( V_120 ) {
F_11 ( & V_137 -> V_2 , L_19 ) ;
goto V_144;
}
if ( V_125 > 5 ) {
F_11 ( & V_137 -> V_2 , L_20 ,
V_125 ) ;
V_120 = - V_39 ;
goto V_144;
}
V_58 -> V_125 = V_125 ;
V_120 = F_80 ( V_137 -> V_2 . V_151 , L_21 , & V_81 ) ;
if ( V_120 ) {
F_11 ( & V_137 -> V_2 , L_22 ) ;
goto V_144;
}
if ( V_81 > 5 ) {
F_11 ( & V_137 -> V_2 , L_23 , V_81 ) ;
V_120 = - V_39 ;
goto V_144;
}
V_58 -> V_81 = V_81 ;
V_58 -> V_70 = F_78 ( & V_12 -> V_2 , V_152 ,
sizeof( * V_58 -> V_70 ) ,
V_150 ) ;
if ( ! V_58 -> V_70 ) {
V_120 = - V_142 ;
goto V_144;
}
V_58 -> V_106 = F_78 ( & V_12 -> V_2 , V_152 - 1 ,
sizeof( * V_58 -> V_106 ) , V_150 ) ;
if ( ! V_58 -> V_106 ) {
V_120 = - V_142 ;
goto V_144;
}
V_58 -> V_78 = 0 ;
V_58 -> V_76 = V_152 - 1 ;
F_81 ( V_137 , V_12 ) ;
F_82 ( & V_58 -> V_34 ) ;
V_12 -> V_33 = F_17 ;
V_12 -> V_153 = F_19 ;
V_12 -> V_154 = F_21 ;
F_18 ( & V_137 -> V_2 , L_24 ) ;
V_58 -> V_69 = F_83 ( V_137 -> V_2 . V_151 ,
& V_155 , V_58 ) ;
if ( ! V_58 -> V_69 ) {
F_11 ( & V_137 -> V_2 , L_25 ) ;
V_120 = - V_142 ;
goto V_144;
}
F_84 ( V_58 -> V_63 , F_30 , V_58 ) ;
V_120 = F_85 ( V_12 ) ;
if ( V_120 )
goto V_156;
return 0 ;
V_156:
F_84 ( V_58 -> V_63 , NULL , NULL ) ;
F_86 ( V_58 -> V_69 ) ;
V_144:
F_87 ( V_12 ) ;
return V_120 ;
}
static int F_88 ( struct V_136 * V_137 )
{
struct V_11 * V_12 = F_89 ( V_137 ) ;
struct V_1 * V_58 = F_9 ( V_12 ) ;
F_90 ( V_12 ) ;
F_84 ( V_58 -> V_63 , NULL , NULL ) ;
F_86 ( V_58 -> V_69 ) ;
F_87 ( V_12 ) ;
return 0 ;
}
