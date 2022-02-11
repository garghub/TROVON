static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 * V_7 , T_1 V_8 , T_2 V_9 )
{
T_1 V_10 = F_1 ( V_2 , V_8 ) ;
memcpy ( V_7 , & V_10 , ( V_9 & 3 ) + 1 ) ;
}
static void
F_7 ( struct V_1 * V_2 , const T_2 * V_7 , T_1 V_8 , T_2 V_9 )
{
T_1 V_10 = 0 ;
memcpy ( & V_10 , V_7 , ( V_9 & 3 ) + 1 ) ;
F_3 ( V_2 , V_8 , V_10 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
void T_3 * V_13 , T_2 V_14 , T_4 V_15 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
T_1 V_16 = 0 ;
T_1 V_17 = V_18 ;
T_1 V_3 = V_2 -> V_19 -> V_3 ( V_2 , V_14 , V_15 ) + V_20 ;
while ( V_17 -- ) {
V_16 = F_2 ( V_13 + V_3 ) ;
if ( V_16 & V_21 ) {
if ( V_16 & V_22 ) {
F_10 ( & V_12 -> V_2 ,
L_1 ,
V_23 , V_16 ) ;
return - V_24 ;
}
if ( V_16 & V_25 ) {
F_10 ( & V_12 -> V_2 ,
L_2 ,
V_23 , V_16 ) ;
return - V_26 ;
}
if ( V_16 & V_27 ) {
F_10 ( & V_12 -> V_2 ,
L_3 ,
V_23 , V_16 ) ;
return - V_26 ;
}
return 0 ;
}
F_11 ( 1 ) ;
}
F_10 ( & V_12 -> V_2 ,
L_4 ,
V_23 , V_16 ) ;
return - V_28 ;
}
static int
F_12 ( struct V_11 * V_12 , T_2 V_29 , T_2 V_14 )
{
struct V_1 * V_30 = F_9 ( V_12 ) ;
unsigned long V_31 ;
T_1 V_32 ;
int V_33 ;
T_1 V_3 = V_30 -> V_19 -> V_3 ( V_30 , V_14 , 0 ) ;
V_32 = ( ( V_29 | 0x40 ) << 27 ) | ( ( V_14 & 0xf ) << 20 ) ;
F_13 ( & V_30 -> V_34 , V_31 ) ;
F_3 ( V_30 , V_3 + V_35 , V_32 ) ;
V_33 = F_8 ( V_12 , V_30 -> V_6 , V_14 , 0 ) ;
F_14 ( & V_30 -> V_34 , V_31 ) ;
return V_33 ;
}
static int
F_15 ( struct V_11 * V_12 , T_2 V_29 , T_2 V_14 )
{
return - V_36 ;
}
static int F_16 ( struct V_11 * V_12 , T_2 V_29 , T_2 V_14 )
{
struct V_1 * V_30 = F_9 ( V_12 ) ;
F_17 ( & V_12 -> V_2 , L_5 , V_29 , V_14 ) ;
if ( V_29 < V_37 || V_29 > V_38 )
return - V_39 ;
return V_30 -> V_19 -> V_40 ( V_12 , V_29 , V_14 ) ;
}
static int F_18 ( struct V_11 * V_12 , T_2 V_29 , T_2 V_14 ,
T_4 V_15 , T_2 * V_7 , T_5 V_41 )
{
struct V_1 * V_30 = F_9 ( V_12 ) ;
unsigned long V_31 ;
T_2 V_9 = V_41 - 1 ;
T_1 V_32 ;
int V_33 ;
T_1 V_3 = V_30 -> V_19 -> V_3 ( V_30 , V_14 , V_15 ) ;
if ( V_9 >= V_42 ) {
F_10 ( & V_12 -> V_2 ,
L_6 ,
V_42 , V_41 ) ;
return - V_39 ;
}
if ( V_29 >= 0x60 && V_29 <= 0x7F )
V_29 = V_43 ;
else if ( V_29 >= 0x20 && V_29 <= 0x2F )
V_29 = V_44 ;
else if ( V_29 >= 0x38 && V_29 <= 0x3F )
V_29 = V_45 ;
else
return - V_39 ;
V_32 = V_30 -> V_19 -> V_46 ( V_29 , V_14 , V_15 , V_9 ) ;
F_13 ( & V_30 -> V_34 , V_31 ) ;
F_5 ( V_30 , V_3 + V_35 , V_32 ) ;
V_33 = F_8 ( V_12 , V_30 -> V_4 , V_14 , V_15 ) ;
if ( V_33 )
goto V_47;
F_6 ( V_30 , V_7 , V_3 + V_48 ,
F_19 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_6 ( V_30 , V_7 + 4 ,
V_3 + V_49 , V_9 - 4 ) ;
V_47:
F_14 ( & V_30 -> V_34 , V_31 ) ;
return V_33 ;
}
static int F_20 ( struct V_11 * V_12 , T_2 V_29 , T_2 V_14 ,
T_4 V_15 , const T_2 * V_7 , T_5 V_41 )
{
struct V_1 * V_30 = F_9 ( V_12 ) ;
unsigned long V_31 ;
T_2 V_9 = V_41 - 1 ;
T_1 V_32 ;
int V_33 ;
T_1 V_3 = V_30 -> V_19 -> V_3 ( V_30 , V_14 , V_15 ) ;
if ( V_9 >= V_42 ) {
F_10 ( & V_12 -> V_2 ,
L_6 ,
V_42 , V_41 ) ;
return - V_39 ;
}
if ( V_29 >= 0x40 && V_29 <= 0x5F )
V_29 = V_50 ;
else if ( V_29 >= 0x00 && V_29 <= 0x0F )
V_29 = V_51 ;
else if ( V_29 >= 0x30 && V_29 <= 0x37 )
V_29 = V_52 ;
else if ( V_29 >= 0x80 && V_29 <= 0xFF )
V_29 = V_53 ;
else
return - V_39 ;
V_32 = V_30 -> V_19 -> V_46 ( V_29 , V_14 , V_15 , V_9 ) ;
F_13 ( & V_30 -> V_34 , V_31 ) ;
F_7 ( V_30 , V_7 , V_3 + V_54 ,
F_19 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_7 ( V_30 , V_7 + 4 ,
V_3 + V_55 , V_9 - 4 ) ;
F_3 ( V_30 , V_3 + V_35 , V_32 ) ;
V_33 = F_8 ( V_12 , V_30 -> V_6 , V_14 , V_15 ) ;
F_14 ( & V_30 -> V_34 , V_31 ) ;
return V_33 ;
}
static void F_21 ( struct V_56 * V_57 , T_2 V_8 , void * V_7 ,
T_5 V_41 )
{
struct V_1 * V_58 = F_22 ( V_57 ) ;
T_2 V_14 = V_57 -> V_59 >> 24 ;
T_2 V_60 = V_57 -> V_59 >> 16 ;
if ( F_20 ( V_58 -> V_61 , V_62 , V_14 ,
( V_60 << 8 ) + V_8 , V_7 , V_41 ) )
F_23 ( & V_58 -> V_61 -> V_2 ,
L_7 ,
V_57 -> V_63 ) ;
}
static void F_24 ( struct V_56 * V_57 , T_2 V_8 , void * V_7 , T_5 V_41 )
{
struct V_1 * V_58 = F_22 ( V_57 ) ;
T_2 V_14 = V_57 -> V_59 >> 24 ;
T_2 V_60 = V_57 -> V_59 >> 16 ;
if ( F_18 ( V_58 -> V_61 , V_64 , V_14 ,
( V_60 << 8 ) + V_8 , V_7 , V_41 ) )
F_23 ( & V_58 -> V_61 -> V_2 ,
L_7 ,
V_57 -> V_63 ) ;
}
static void F_25 ( struct V_1 * V_58 , T_2 V_65 )
{
unsigned int V_63 ;
T_1 V_16 ;
int V_66 ;
V_16 = F_2 ( V_58 -> V_67 + V_58 -> V_19 -> V_68 ( V_65 ) ) ;
while ( V_16 ) {
V_66 = F_26 ( V_16 ) - 1 ;
V_16 &= ~ ( 1 << V_66 ) ;
V_63 = F_27 ( V_58 -> V_69 ,
V_58 -> V_70 [ V_65 ] << 16
| V_66 << 8
| V_65 ) ;
F_28 ( V_63 ) ;
}
}
static void F_29 ( unsigned int V_63 , struct V_71 * V_72 )
{
struct V_1 * V_58 = F_30 ( V_63 ) ;
struct V_73 * V_74 = F_31 ( V_63 ) ;
void T_3 * V_67 = V_58 -> V_67 ;
int V_75 = V_58 -> V_76 >> 5 ;
int V_77 = V_58 -> V_78 >> 5 ;
T_1 V_16 ;
int V_79 , V_66 ;
F_32 ( V_74 , V_72 ) ;
for ( V_79 = V_75 ; V_79 <= V_77 ; ++ V_79 ) {
V_16 = F_2 ( V_67 +
V_58 -> V_19 -> V_80 ( V_58 -> V_81 , V_79 ) ) ;
while ( V_16 ) {
V_66 = F_26 ( V_16 ) - 1 ;
V_16 &= ~ ( 1 << V_66 ) ;
F_25 ( V_58 , V_66 + V_79 * 32 ) ;
}
}
F_33 ( V_74 , V_72 ) ;
}
static void F_34 ( struct V_56 * V_57 )
{
struct V_1 * V_58 = F_22 ( V_57 ) ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_65 = V_57 -> V_59 ;
unsigned long V_31 ;
T_2 V_10 ;
F_13 ( & V_58 -> V_34 , V_31 ) ;
F_4 ( 1 << V_63 , V_58 -> V_67 + V_58 -> V_19 -> V_82 ( V_65 ) ) ;
F_14 ( & V_58 -> V_34 , V_31 ) ;
V_10 = 1 << V_63 ;
F_21 ( V_57 , V_83 , & V_10 , 1 ) ;
}
static void F_35 ( struct V_56 * V_57 )
{
struct V_1 * V_58 = F_22 ( V_57 ) ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_65 = V_57 -> V_59 ;
unsigned long V_31 ;
T_1 V_16 ;
T_2 V_10 ;
F_13 ( & V_58 -> V_34 , V_31 ) ;
V_16 = F_2 ( V_58 -> V_67 + V_58 -> V_19 -> V_84 ( V_65 ) ) ;
if ( V_16 & V_85 ) {
V_16 = V_16 & ~ V_85 ;
F_4 ( V_16 , V_58 -> V_67 +
V_58 -> V_19 -> V_84 ( V_65 ) ) ;
}
F_14 ( & V_58 -> V_34 , V_31 ) ;
V_10 = 1 << V_63 ;
F_21 ( V_57 , V_86 , & V_10 , 1 ) ;
}
static void F_36 ( struct V_56 * V_57 )
{
struct V_1 * V_58 = F_22 ( V_57 ) ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_65 = V_57 -> V_59 ;
unsigned long V_31 ;
T_1 V_16 ;
T_2 V_10 ;
F_13 ( & V_58 -> V_34 , V_31 ) ;
V_16 = F_2 ( V_58 -> V_67 + V_58 -> V_19 -> V_84 ( V_65 ) ) ;
if ( ! ( V_16 & V_85 ) ) {
F_4 ( V_16 | V_85 ,
V_58 -> V_67 + V_58 -> V_19 -> V_84 ( V_65 ) ) ;
}
F_14 ( & V_58 -> V_34 , V_31 ) ;
V_10 = 1 << V_63 ;
F_21 ( V_57 , V_87 , & V_10 , 1 ) ;
}
static void F_37 ( struct V_56 * V_57 )
{
T_2 V_63 = V_57 -> V_59 >> 8 ;
T_2 V_10 ;
F_36 ( V_57 ) ;
V_10 = 1 << V_63 ;
F_21 ( V_57 , V_83 , & V_10 , 1 ) ;
}
static int F_38 ( struct V_56 * V_57 , unsigned int V_88 )
{
struct V_89 type ;
T_2 V_63 = V_57 -> V_59 >> 8 ;
F_24 ( V_57 , V_90 , & type , sizeof( type ) ) ;
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
F_21 ( V_57 , V_90 , & type , sizeof( type ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_58 ,
struct V_97 * V_98 ,
T_2 * V_65 )
{
T_4 V_99 = V_98 -> V_100 << 8 | V_98 -> V_60 ;
T_1 * V_101 = V_58 -> V_101 ;
int V_102 = 0 , V_79 ;
T_1 V_10 ;
for ( V_79 = 0 ; V_79 < V_103 ; ++ V_79 ) {
V_10 = V_101 [ V_102 ] ;
if ( V_99 & ( 1 << F_40 ( V_10 ) ) ) {
if ( F_41 ( V_10 ) ) {
V_102 = F_42 ( V_10 ) ;
} else {
* V_65 = F_42 ( V_10 ) ;
return 0 ;
}
} else {
if ( F_43 ( V_10 ) ) {
V_102 = F_44 ( V_10 ) ;
} else {
* V_65 = F_44 ( V_10 ) ;
return 0 ;
}
}
}
return - V_104 ;
}
static int F_45 ( struct V_105 * V_57 ,
struct V_106 * V_107 ,
const T_1 * V_108 ,
unsigned int V_109 ,
unsigned long * V_110 ,
unsigned int * V_111 )
{
struct V_1 * V_58 = V_57 -> V_112 ;
struct V_97 V_98 ;
int V_113 ;
T_2 V_65 ;
F_17 ( & V_58 -> V_61 -> V_2 ,
L_8 ,
V_108 [ 0 ] , V_108 [ 1 ] , V_108 [ 2 ] ) ;
if ( V_57 -> V_114 != V_107 )
return - V_39 ;
if ( V_109 != 4 )
return - V_39 ;
if ( V_108 [ 0 ] > 0xF || V_108 [ 1 ] > 0xFF || V_108 [ 2 ] > 0x7 )
return - V_39 ;
V_98 . V_100 = V_108 [ 0 ] ;
V_98 . V_60 = V_108 [ 1 ] ;
V_98 . V_63 = V_108 [ 2 ] ;
V_113 = F_39 ( V_58 , & V_98 , & V_65 ) ;
if ( V_113 )
return V_113 ;
V_58 -> V_70 [ V_65 ] = V_98 . V_100 << 8 | V_98 . V_60 ;
if ( V_65 > V_58 -> V_78 )
V_58 -> V_78 = V_65 ;
if ( V_65 < V_58 -> V_76 )
V_58 -> V_76 = V_65 ;
* V_110 = V_98 . V_100 << 24
| V_98 . V_60 << 16
| V_98 . V_63 << 8
| V_65 ;
* V_111 = V_108 [ 3 ] & V_115 ;
F_17 ( & V_58 -> V_61 -> V_2 , L_9 , * V_110 ) ;
return 0 ;
}
static int F_46 ( struct V_105 * V_57 ,
unsigned int V_116 ,
T_6 V_59 )
{
struct V_1 * V_58 = V_57 -> V_112 ;
F_17 ( & V_58 -> V_61 -> V_2 , L_10 , V_116 , V_59 ) ;
F_47 ( V_116 , & V_117 , V_118 ) ;
F_48 ( V_116 , V_57 -> V_112 ) ;
F_49 ( V_116 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_1 * V_58 , T_2 V_14 , T_4 V_15 )
{
return 0x800 + 0x80 * V_58 -> V_119 ;
}
static T_1 F_51 ( struct V_1 * V_58 , T_2 V_14 , T_4 V_15 )
{
T_4 V_99 = ( V_14 << 8 ) | ( V_15 >> 8 ) ;
T_2 V_120 = V_58 -> V_121 [ V_99 ] ;
return 0x1000 * V_58 -> V_81 + 0x8000 * V_120 ;
}
static T_1 F_52 ( T_2 V_29 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_29 << 27 ) | ( ( V_14 & 0xf ) << 20 ) | ( V_15 << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_53 ( T_2 V_29 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_29 << 27 ) | ( ( V_15 & 0xff ) << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_54 ( T_2 V_122 , T_2 V_123 )
{
return 0x20 * V_122 + 0x4 * V_123 ;
}
static T_1 F_55 ( T_2 V_122 , T_2 V_123 )
{
return 0x100000 + 0x1000 * V_122 + 0x4 * V_123 ;
}
static T_1 F_56 ( T_2 V_123 )
{
return 0x200 + 0x4 * V_123 ;
}
static T_1 F_57 ( T_2 V_123 )
{
return 0x1000 * V_123 ;
}
static T_1 F_58 ( T_2 V_123 )
{
return 0x600 + 0x4 * V_123 ;
}
static T_1 F_59 ( T_2 V_123 )
{
return 0x4 + 0x1000 * V_123 ;
}
static T_1 F_60 ( T_2 V_123 )
{
return 0xA00 + 0x4 * V_123 ;
}
static T_1 F_61 ( T_2 V_123 )
{
return 0x8 + 0x1000 * V_123 ;
}
static int F_62 ( struct V_124 * V_125 )
{
struct V_1 * V_58 ;
struct V_11 * V_12 ;
struct V_126 * V_127 ;
void T_3 * V_128 ;
T_1 V_119 , V_81 , V_129 ;
int V_113 , V_79 ;
bool V_130 ;
V_12 = F_63 ( & V_125 -> V_2 , sizeof( * V_58 ) ) ;
if ( ! V_12 )
return - V_131 ;
V_58 = F_9 ( V_12 ) ;
V_58 -> V_61 = V_12 ;
V_127 = F_64 ( V_125 , V_132 , L_11 ) ;
V_128 = F_65 ( & V_12 -> V_2 , V_127 ) ;
if ( F_66 ( V_128 ) ) {
V_113 = F_67 ( V_128 ) ;
goto V_133;
}
V_129 = F_2 ( V_128 + V_134 ) ;
V_130 = ( V_129 < V_135 ) ;
F_68 ( & V_12 -> V_2 , L_12 , ( V_130 ? 1 : 2 ) ,
V_129 ) ;
if ( V_130 ) {
V_58 -> V_19 = & V_136 ;
V_58 -> V_6 = V_128 ;
V_58 -> V_4 = V_128 ;
} else {
T_2 V_120 ;
T_4 V_99 ;
T_1 V_137 ;
V_58 -> V_19 = & V_138 ;
V_127 = F_64 ( V_125 , V_132 ,
L_13 ) ;
V_58 -> V_4 = F_65 ( & V_12 -> V_2 , V_127 ) ;
if ( F_66 ( V_58 -> V_4 ) ) {
V_113 = F_67 ( V_58 -> V_4 ) ;
goto V_133;
}
V_127 = F_64 ( V_125 , V_132 ,
L_14 ) ;
V_58 -> V_6 = F_65 ( & V_12 -> V_2 , V_127 ) ;
if ( F_66 ( V_58 -> V_6 ) ) {
V_113 = F_67 ( V_58 -> V_6 ) ;
goto V_133;
}
V_58 -> V_121 = F_69 ( & V_12 -> V_2 ,
V_139 , V_140 ) ;
if ( ! V_58 -> V_121 ) {
V_113 = - V_131 ;
goto V_133;
}
for ( V_120 = 0 ; V_120 < V_141 ; ++ V_120 ) {
V_137 = F_2 ( V_128 + F_70 ( V_120 ) ) ;
if ( ! V_137 )
continue;
V_99 = ( V_137 >> 8 ) & 0xFFF ;
V_58 -> V_121 [ V_99 ] = V_120 ;
}
}
V_127 = F_64 ( V_125 , V_132 , L_15 ) ;
V_58 -> V_67 = F_65 ( & V_12 -> V_2 , V_127 ) ;
if ( F_66 ( V_58 -> V_67 ) ) {
V_113 = F_67 ( V_58 -> V_67 ) ;
goto V_133;
}
V_127 = F_64 ( V_125 , V_132 , L_16 ) ;
V_58 -> V_142 = F_65 ( & V_12 -> V_2 , V_127 ) ;
if ( F_66 ( V_58 -> V_142 ) ) {
V_113 = F_67 ( V_58 -> V_142 ) ;
goto V_133;
}
V_58 -> V_63 = F_71 ( V_125 , L_17 ) ;
if ( V_58 -> V_63 < 0 ) {
V_113 = V_58 -> V_63 ;
goto V_133;
}
V_113 = F_72 ( V_125 -> V_2 . V_114 , L_18 , & V_119 ) ;
if ( V_113 ) {
F_10 ( & V_125 -> V_2 , L_19 ) ;
goto V_133;
}
if ( V_119 > 5 ) {
F_10 ( & V_125 -> V_2 , L_20 ,
V_119 ) ;
goto V_133;
}
V_58 -> V_119 = V_119 ;
V_113 = F_72 ( V_125 -> V_2 . V_114 , L_21 , & V_81 ) ;
if ( V_113 ) {
F_10 ( & V_125 -> V_2 , L_22 ) ;
goto V_133;
}
if ( V_81 > 5 ) {
F_10 ( & V_125 -> V_2 , L_23 , V_81 ) ;
V_113 = - V_39 ;
goto V_133;
}
V_58 -> V_81 = V_81 ;
for ( V_79 = 0 ; V_79 < F_73 ( V_58 -> V_101 ) ; ++ V_79 )
V_58 -> V_101 [ V_79 ] = F_2 (
V_58 -> V_142 + F_74 ( V_79 ) ) ;
V_58 -> V_78 = 0 ;
V_58 -> V_76 = V_143 - 1 ;
F_75 ( V_125 , V_12 ) ;
F_76 ( & V_58 -> V_34 ) ;
V_12 -> V_32 = F_16 ;
V_12 -> V_144 = F_18 ;
V_12 -> V_145 = F_20 ;
F_17 ( & V_125 -> V_2 , L_24 ) ;
V_58 -> V_69 = F_77 ( V_125 -> V_2 . V_114 ,
& V_146 , V_58 ) ;
if ( ! V_58 -> V_69 ) {
F_10 ( & V_125 -> V_2 , L_25 ) ;
V_113 = - V_131 ;
goto V_133;
}
F_78 ( V_58 -> V_63 , V_58 ) ;
F_79 ( V_58 -> V_63 , F_29 ) ;
V_113 = F_80 ( V_12 ) ;
if ( V_113 )
goto V_147;
return 0 ;
V_147:
F_79 ( V_58 -> V_63 , NULL ) ;
F_78 ( V_58 -> V_63 , NULL ) ;
F_81 ( V_58 -> V_69 ) ;
V_133:
F_82 ( V_12 ) ;
return V_113 ;
}
static int F_83 ( struct V_124 * V_125 )
{
struct V_11 * V_12 = F_84 ( V_125 ) ;
struct V_1 * V_58 = F_9 ( V_12 ) ;
F_85 ( V_12 ) ;
F_79 ( V_58 -> V_63 , NULL ) ;
F_78 ( V_58 -> V_63 , NULL ) ;
F_81 ( V_58 -> V_69 ) ;
F_82 ( V_12 ) ;
return 0 ;
}
