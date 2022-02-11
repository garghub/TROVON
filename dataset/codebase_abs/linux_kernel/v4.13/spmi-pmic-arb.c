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
F_1 ( V_2 , V_8 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
void T_3 * V_13 , T_2 V_14 , T_4 V_15 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
T_1 V_16 = 0 ;
T_1 V_17 = V_18 ;
T_1 V_3 ;
int V_19 ;
V_19 = V_2 -> V_20 -> V_3 ( V_2 , V_14 , V_15 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_3 += V_21 ;
while ( V_17 -- ) {
V_16 = F_9 ( V_13 + V_3 ) ;
if ( V_16 & V_22 ) {
if ( V_16 & V_23 ) {
F_10 ( & V_12 -> V_24 ,
L_1 ,
V_25 , V_16 ) ;
return - V_26 ;
}
if ( V_16 & V_27 ) {
F_10 ( & V_12 -> V_24 ,
L_2 ,
V_25 , V_16 ) ;
return - V_28 ;
}
if ( V_16 & V_29 ) {
F_10 ( & V_12 -> V_24 ,
L_3 ,
V_25 , V_16 ) ;
return - V_28 ;
}
return 0 ;
}
F_11 ( 1 ) ;
}
F_10 ( & V_12 -> V_24 ,
L_4 ,
V_25 , V_16 ) ;
return - V_30 ;
}
static int
F_12 ( struct V_11 * V_12 , T_2 V_31 , T_2 V_14 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
unsigned long V_32 ;
T_1 V_33 ;
int V_19 ;
T_1 V_3 ;
V_19 = V_2 -> V_20 -> V_3 ( V_2 , V_14 , 0 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_33 = ( ( V_31 | 0x40 ) << 27 ) | ( ( V_14 & 0xf ) << 20 ) ;
F_13 ( & V_2 -> V_34 , V_32 ) ;
F_1 ( V_2 , V_3 + V_35 , V_33 ) ;
V_19 = F_7 ( V_12 , V_2 -> V_5 , V_14 , 0 ) ;
F_14 ( & V_2 -> V_34 , V_32 ) ;
return V_19 ;
}
static int
F_15 ( struct V_11 * V_12 , T_2 V_31 , T_2 V_14 )
{
return - V_36 ;
}
static int F_16 ( struct V_11 * V_12 , T_2 V_31 , T_2 V_14 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
F_17 ( & V_12 -> V_24 , L_5 , V_31 , V_14 ) ;
if ( V_31 < V_37 || V_31 > V_38 )
return - V_39 ;
return V_2 -> V_20 -> V_40 ( V_12 , V_31 , V_14 ) ;
}
static int F_18 ( struct V_11 * V_12 , T_2 V_31 , T_2 V_14 ,
T_4 V_15 , T_2 * V_7 , T_5 V_41 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
unsigned long V_32 ;
T_2 V_9 = V_41 - 1 ;
T_1 V_33 ;
int V_19 ;
T_1 V_3 ;
T_6 V_42 ;
V_19 = V_2 -> V_20 -> V_3 ( V_2 , V_14 , V_15 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_2 -> V_20 -> V_42 ( V_2 , V_14 , V_15 , & V_42 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( V_42 & V_43 ) ) {
F_10 ( & V_2 -> V_44 -> V_24 ,
L_6 ,
V_14 , V_15 ) ;
return - V_26 ;
}
if ( V_9 >= V_45 ) {
F_10 ( & V_12 -> V_24 ,
L_7 ,
V_45 , V_41 ) ;
return - V_39 ;
}
if ( V_31 >= 0x60 && V_31 <= 0x7F )
V_31 = V_46 ;
else if ( V_31 >= 0x20 && V_31 <= 0x2F )
V_31 = V_47 ;
else if ( V_31 >= 0x38 && V_31 <= 0x3F )
V_31 = V_48 ;
else
return - V_39 ;
V_33 = V_2 -> V_20 -> V_49 ( V_31 , V_14 , V_15 , V_9 ) ;
F_13 ( & V_2 -> V_34 , V_32 ) ;
F_3 ( V_2 , V_3 + V_35 , V_33 ) ;
V_19 = F_7 ( V_12 , V_2 -> V_6 , V_14 , V_15 ) ;
if ( V_19 )
goto V_50;
F_4 ( V_2 , V_7 , V_3 + V_51 ,
F_19 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_4 ( V_2 , V_7 + 4 , V_3 + V_52 , V_9 - 4 ) ;
V_50:
F_14 ( & V_2 -> V_34 , V_32 ) ;
return V_19 ;
}
static int F_20 ( struct V_11 * V_12 , T_2 V_31 , T_2 V_14 ,
T_4 V_15 , const T_2 * V_7 , T_5 V_41 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
unsigned long V_32 ;
T_2 V_9 = V_41 - 1 ;
T_1 V_33 ;
int V_19 ;
T_1 V_3 ;
T_6 V_42 ;
V_19 = V_2 -> V_20 -> V_3 ( V_2 , V_14 , V_15 , & V_3 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_2 -> V_20 -> V_42 ( V_2 , V_14 , V_15 , & V_42 ) ;
if ( V_19 )
return V_19 ;
if ( ! ( V_42 & V_53 ) ) {
F_10 ( & V_2 -> V_44 -> V_24 ,
L_8 ,
V_14 , V_15 ) ;
return - V_26 ;
}
if ( V_9 >= V_45 ) {
F_10 ( & V_12 -> V_24 ,
L_7 ,
V_45 , V_41 ) ;
return - V_39 ;
}
if ( V_31 >= 0x40 && V_31 <= 0x5F )
V_31 = V_54 ;
else if ( V_31 >= 0x00 && V_31 <= 0x0F )
V_31 = V_55 ;
else if ( V_31 >= 0x30 && V_31 <= 0x37 )
V_31 = V_56 ;
else if ( V_31 >= 0x80 )
V_31 = V_57 ;
else
return - V_39 ;
V_33 = V_2 -> V_20 -> V_49 ( V_31 , V_14 , V_15 , V_9 ) ;
F_13 ( & V_2 -> V_34 , V_32 ) ;
F_6 ( V_2 , V_7 , V_3 + V_58 , F_19 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_6 ( V_2 , V_7 + 4 , V_3 + V_59 , V_9 - 4 ) ;
F_1 ( V_2 , V_3 + V_35 , V_33 ) ;
V_19 = F_7 ( V_12 , V_2 -> V_5 , V_14 , V_15 ) ;
F_14 ( & V_2 -> V_34 , V_32 ) ;
return V_19 ;
}
static void F_21 ( struct V_60 * V_61 , T_2 V_8 , void * V_7 ,
T_5 V_41 )
{
struct V_1 * V_2 = F_22 ( V_61 ) ;
T_2 V_14 = F_23 ( V_61 -> V_62 ) ;
T_2 V_63 = F_24 ( V_61 -> V_62 ) ;
if ( F_20 ( V_2 -> V_44 , V_64 , V_14 ,
( V_63 << 8 ) + V_8 , V_7 , V_41 ) )
F_25 ( & V_2 -> V_44 -> V_24 ,
L_9 ,
V_61 -> V_65 ) ;
}
static void F_26 ( struct V_60 * V_61 , T_2 V_8 , void * V_7 , T_5 V_41 )
{
struct V_1 * V_2 = F_22 ( V_61 ) ;
T_2 V_14 = F_23 ( V_61 -> V_62 ) ;
T_2 V_63 = F_24 ( V_61 -> V_62 ) ;
if ( F_18 ( V_2 -> V_44 , V_66 , V_14 ,
( V_63 << 8 ) + V_8 , V_7 , V_41 ) )
F_25 ( & V_2 -> V_44 -> V_24 ,
L_9 ,
V_61 -> V_65 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_4 V_67 , int V_68 )
{
T_4 V_69 = V_2 -> V_70 [ V_67 ] . V_69 ;
T_2 V_14 = V_69 >> 8 ;
T_2 V_63 = V_69 & 0xFF ;
T_2 V_71 = F_28 ( V_68 ) ;
F_2 ( V_71 , V_2 -> V_72 + V_2 -> V_20 -> V_73 ( V_67 ) ) ;
if ( F_20 ( V_2 -> V_44 , V_64 , V_14 ,
( V_63 << 8 ) + V_74 , & V_71 , 1 ) )
F_25 ( & V_2 -> V_44 -> V_24 ,
L_10 ,
V_71 , V_69 ) ;
if ( F_20 ( V_2 -> V_44 , V_64 , V_14 ,
( V_63 << 8 ) + V_75 , & V_71 , 1 ) )
F_25 ( & V_2 -> V_44 -> V_24 ,
L_10 ,
V_71 , V_69 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_4 V_67 )
{
unsigned int V_65 ;
T_1 V_16 ;
int V_68 ;
T_2 V_14 = ( V_2 -> V_70 [ V_67 ] . V_69 >> 8 ) & 0xF ;
T_2 V_63 = V_2 -> V_70 [ V_67 ] . V_69 & 0xFF ;
V_16 = F_9 ( V_2 -> V_72 + V_2 -> V_20 -> V_76 ( V_67 ) ) ;
while ( V_16 ) {
V_68 = F_30 ( V_16 ) - 1 ;
V_16 &= ~ F_28 ( V_68 ) ;
V_65 = F_31 ( V_2 -> V_77 , F_32 ( V_14 , V_63 , V_68 , V_67 ) ) ;
if ( V_65 == 0 ) {
F_27 ( V_2 , V_67 , V_68 ) ;
continue;
}
F_33 ( V_65 ) ;
}
}
static void F_34 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_35 ( V_79 ) ;
struct V_80 * V_81 = F_36 ( V_79 ) ;
void T_3 * V_72 = V_2 -> V_72 ;
int V_82 = V_2 -> V_83 >> 5 ;
int V_84 = V_2 -> V_85 >> 5 ;
T_1 V_16 , V_86 ;
int V_87 , V_68 , V_67 ;
F_37 ( V_81 , V_79 ) ;
for ( V_87 = V_82 ; V_87 <= V_84 ; ++ V_87 ) {
V_16 = F_9 ( V_72 +
V_2 -> V_20 -> V_88 ( V_2 -> V_89 , V_87 ) ) ;
while ( V_16 ) {
V_68 = F_30 ( V_16 ) - 1 ;
V_16 &= ~ F_28 ( V_68 ) ;
V_67 = V_68 + V_87 * 32 ;
V_86 = F_9 ( V_72 +
V_2 -> V_20 -> V_90 ( V_67 ) ) ;
if ( V_86 & V_91 )
F_29 ( V_2 , V_67 ) ;
}
}
F_38 ( V_81 , V_79 ) ;
}
static void F_39 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_22 ( V_61 ) ;
T_2 V_65 = F_40 ( V_61 -> V_62 ) ;
T_4 V_67 = F_41 ( V_61 -> V_62 ) ;
T_2 V_10 ;
F_2 ( F_28 ( V_65 ) , V_2 -> V_72 + V_2 -> V_20 -> V_73 ( V_67 ) ) ;
V_10 = F_28 ( V_65 ) ;
F_21 ( V_61 , V_74 , & V_10 , 1 ) ;
}
static void F_42 ( struct V_60 * V_61 )
{
T_2 V_65 = F_40 ( V_61 -> V_62 ) ;
T_2 V_10 = F_28 ( V_65 ) ;
F_21 ( V_61 , V_75 , & V_10 , 1 ) ;
}
static void F_43 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_22 ( V_61 ) ;
T_2 V_65 = F_40 ( V_61 -> V_62 ) ;
T_4 V_67 = F_41 ( V_61 -> V_62 ) ;
T_2 V_7 [ 2 ] ;
F_2 ( V_91 ,
V_2 -> V_72 + V_2 -> V_20 -> V_90 ( V_67 ) ) ;
F_26 ( V_61 , V_92 , & V_7 [ 0 ] , 1 ) ;
if ( ! ( V_7 [ 0 ] & F_28 ( V_65 ) ) ) {
V_7 [ 0 ] = F_28 ( V_65 ) ;
V_7 [ 1 ] = F_28 ( V_65 ) ;
F_21 ( V_61 , V_74 , & V_7 , 2 ) ;
}
}
static int F_44 ( struct V_60 * V_61 , unsigned int V_93 )
{
struct V_94 type ;
T_2 V_65 = F_40 ( V_61 -> V_62 ) ;
T_2 V_95 = F_28 ( V_65 ) ;
F_26 ( V_61 , V_96 , & type , sizeof( type ) ) ;
if ( V_93 & ( V_97 | V_98 ) ) {
type . type |= V_95 ;
if ( V_93 & V_97 )
type . V_99 |= V_95 ;
if ( V_93 & V_98 )
type . V_100 |= V_95 ;
} else {
if ( ( V_93 & ( V_101 ) ) &&
( V_93 & ( V_102 ) ) )
return - V_39 ;
type . type &= ~ V_95 ;
if ( V_93 & V_101 )
type . V_99 |= V_95 ;
else
type . V_100 |= V_95 ;
}
F_21 ( V_61 , V_96 , & type , sizeof( type ) ) ;
if ( V_93 & V_103 )
F_45 ( V_61 , V_104 ) ;
else
F_45 ( V_61 , V_105 ) ;
return 0 ;
}
static int F_46 ( struct V_60 * V_61 ,
enum V_106 V_107 ,
bool * V_108 )
{
T_2 V_65 = F_40 ( V_61 -> V_62 ) ;
T_2 V_16 = 0 ;
if ( V_107 != V_109 )
return - V_39 ;
F_26 ( V_61 , V_110 , & V_16 , 1 ) ;
* V_108 = ! ! ( V_16 & F_28 ( V_65 ) ) ;
return 0 ;
}
static int F_47 ( struct V_111 * V_61 ,
struct V_112 * V_113 ,
const T_1 * V_114 ,
unsigned int V_115 ,
unsigned long * V_116 ,
unsigned int * V_117 )
{
struct V_1 * V_2 = V_61 -> V_118 ;
int V_19 ;
T_4 V_67 ;
F_17 ( & V_2 -> V_44 -> V_24 ,
L_11 ,
V_114 [ 0 ] , V_114 [ 1 ] , V_114 [ 2 ] ) ;
if ( F_48 ( V_61 ) != V_113 )
return - V_39 ;
if ( V_115 != 4 )
return - V_39 ;
if ( V_114 [ 0 ] > 0xF || V_114 [ 1 ] > 0xFF || V_114 [ 2 ] > 0x7 )
return - V_39 ;
V_19 = V_2 -> V_20 -> V_119 ( V_2 , V_114 [ 0 ] ,
( V_114 [ 1 ] << 8 ) , & V_67 ) ;
if ( V_19 < 0 ) {
F_10 ( & V_2 -> V_44 -> V_24 ,
L_12 ,
V_114 [ 0 ] , V_114 [ 1 ] , V_114 [ 2 ] , V_19 ) ;
return V_19 ;
}
if ( V_67 > V_2 -> V_85 )
V_2 -> V_85 = V_67 ;
if ( V_67 < V_2 -> V_83 )
V_2 -> V_83 = V_67 ;
* V_116 = F_32 ( V_114 [ 0 ] , V_114 [ 1 ] , V_114 [ 2 ] , V_67 ) ;
* V_117 = V_114 [ 3 ] & V_120 ;
F_17 ( & V_2 -> V_44 -> V_24 , L_13 , * V_116 ) ;
return 0 ;
}
static int F_49 ( struct V_111 * V_61 ,
unsigned int V_121 ,
T_7 V_62 )
{
struct V_1 * V_2 = V_61 -> V_118 ;
F_17 ( & V_2 -> V_44 -> V_24 , L_14 , V_121 , V_62 ) ;
F_50 ( V_121 , & V_122 , V_105 ) ;
F_51 ( V_121 , V_61 -> V_118 ) ;
F_52 ( V_121 ) ;
return 0 ;
}
static int
F_53 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 , T_4 * V_67 )
{
T_4 V_69 = V_14 << 8 | ( ( V_15 >> 8 ) & 0xFF ) ;
T_1 * V_123 = V_2 -> V_123 ;
int V_124 = 0 , V_87 ;
T_4 V_125 ;
T_1 V_10 ;
V_125 = V_2 -> V_119 [ V_69 ] ;
if ( V_125 & V_126 ) {
* V_67 = ( V_125 & ~ V_126 ) ;
return 0 ;
}
for ( V_87 = 0 ; V_87 < V_127 ; ++ V_87 ) {
if ( ! F_54 ( V_124 , V_2 -> V_128 ) )
V_123 [ V_124 ] = F_9 ( V_2 -> V_129 +
F_55 ( V_124 ) ) ;
V_10 = V_123 [ V_124 ] ;
if ( V_69 & F_28 ( F_56 ( V_10 ) ) ) {
if ( F_57 ( V_10 ) ) {
V_124 = F_58 ( V_10 ) ;
} else {
* V_67 = F_58 ( V_10 ) ;
V_2 -> V_119 [ V_69 ]
= * V_67 | V_126 ;
V_2 -> V_70 [ * V_67 ] . V_69 = V_69 ;
return 0 ;
}
} else {
if ( F_59 ( V_10 ) ) {
V_124 = F_60 ( V_10 ) ;
} else {
* V_67 = F_60 ( V_10 ) ;
V_2 -> V_119 [ V_69 ]
= * V_67 | V_126 ;
V_2 -> V_70 [ * V_67 ] . V_69 = V_69 ;
return 0 ;
}
}
}
return - V_130 ;
}
static int
F_61 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 , T_6 * V_42 )
{
* V_42 = V_43 | V_53 ;
return 0 ;
}
static int
F_62 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 , T_1 * V_3 )
{
* V_3 = 0x800 + 0x80 * V_2 -> V_131 ;
return 0 ;
}
static T_4 F_63 ( struct V_1 * V_2 , T_4 V_69 )
{
T_1 V_132 , V_3 ;
T_4 V_67 ;
T_4 V_68 ;
for ( V_67 = V_2 -> V_133 ; V_67 < V_2 -> V_134 ; V_67 ++ ) {
V_132 = F_9 ( V_2 -> V_129 +
F_64 ( V_67 ) ) ;
V_2 -> V_70 [ V_67 ] . V_135 = F_65 ( V_132 ) ;
V_3 = F_66 ( V_67 ) ;
if ( V_3 >= V_2 -> V_136 )
break;
V_132 = F_9 ( V_2 -> V_137 + V_3 ) ;
if ( ! V_132 )
continue;
V_68 = ( V_132 >> 8 ) & V_138 ;
V_2 -> V_119 [ V_68 ] = V_67 | V_126 ;
V_2 -> V_70 [ V_67 ] . V_69 = V_68 ;
if ( V_68 == V_69 ) {
V_67 |= V_126 ;
break;
}
}
V_2 -> V_133 = V_67 & ~ V_126 ;
return V_67 ;
}
static int
F_67 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 , T_4 * V_67 )
{
T_4 V_69 = ( V_14 << 8 ) | ( V_15 >> 8 ) ;
T_4 V_125 ;
V_125 = V_2 -> V_119 [ V_69 ] ;
if ( ! ( V_125 & V_126 ) )
V_125 = F_63 ( V_2 , V_69 ) ;
if ( ! ( V_125 & V_126 ) )
return - V_130 ;
* V_67 = ( V_125 & ~ V_126 ) ;
return 0 ;
}
static int
F_68 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 , T_6 * V_42 )
{
T_4 V_67 ;
int V_19 ;
V_19 = F_67 ( V_2 , V_14 , V_15 , & V_67 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_42 = 0 ;
* V_42 |= V_43 ;
if ( V_2 -> V_89 == V_2 -> V_70 [ V_67 ] . V_135 )
* V_42 |= V_53 ;
return 0 ;
}
static int
F_69 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 , T_1 * V_3 )
{
T_4 V_67 ;
int V_19 ;
V_19 = F_67 ( V_2 , V_14 , V_15 , & V_67 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_3 = 0x1000 * V_2 -> V_89 + 0x8000 * V_67 ;
return 0 ;
}
static T_1 F_70 ( T_2 V_31 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_31 << 27 ) | ( ( V_14 & 0xf ) << 20 ) | ( V_15 << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_71 ( T_2 V_31 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_31 << 27 ) | ( ( V_15 & 0xff ) << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_72 ( T_2 V_139 , T_4 V_140 )
{
return 0x20 * V_139 + 0x4 * V_140 ;
}
static T_1 F_73 ( T_2 V_139 , T_4 V_140 )
{
return 0x100000 + 0x1000 * V_139 + 0x4 * V_140 ;
}
static T_1 F_74 ( T_2 V_139 , T_4 V_140 )
{
return 0x200000 + 0x1000 * V_139 + 0x4 * V_140 ;
}
static T_1 F_75 ( T_4 V_140 )
{
return 0x200 + 0x4 * V_140 ;
}
static T_1 F_76 ( T_4 V_140 )
{
return 0x1000 * V_140 ;
}
static T_1 F_77 ( T_4 V_140 )
{
return 0x600 + 0x4 * V_140 ;
}
static T_1 F_78 ( T_4 V_140 )
{
return 0x4 + 0x1000 * V_140 ;
}
static T_1 F_79 ( T_4 V_140 )
{
return 0xA00 + 0x4 * V_140 ;
}
static T_1 F_80 ( T_4 V_140 )
{
return 0x8 + 0x1000 * V_140 ;
}
static int F_81 ( struct V_141 * V_142 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_143 * V_144 ;
void T_3 * V_137 ;
T_1 V_131 , V_89 , V_145 ;
int V_146 ;
V_12 = F_82 ( & V_142 -> V_24 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_147 ;
V_2 = F_8 ( V_12 ) ;
V_2 -> V_44 = V_12 ;
V_144 = F_83 ( V_142 , V_148 , L_15 ) ;
V_2 -> V_136 = F_84 ( V_144 ) ;
if ( V_2 -> V_136 <= 0x800 ) {
F_10 ( & V_142 -> V_24 , L_16 ) ;
V_146 = - V_39 ;
goto V_149;
}
V_137 = F_85 ( & V_12 -> V_24 , V_144 ) ;
if ( F_86 ( V_137 ) ) {
V_146 = F_87 ( V_137 ) ;
goto V_149;
}
V_2 -> V_119 = F_88 ( & V_12 -> V_24 , V_150 ,
sizeof( * V_2 -> V_119 ) , V_151 ) ;
if ( ! V_2 -> V_119 ) {
V_146 = - V_147 ;
goto V_149;
}
V_145 = F_9 ( V_137 + V_152 ) ;
if ( V_145 < V_153 ) {
V_2 -> V_20 = & V_154 ;
V_2 -> V_5 = V_137 ;
V_2 -> V_6 = V_137 ;
} else {
V_2 -> V_137 = V_137 ;
if ( V_145 < V_155 )
V_2 -> V_20 = & V_156 ;
else
V_2 -> V_20 = & V_157 ;
V_2 -> V_134 = ( V_2 -> V_136 - F_66 ( 0 ) ) / 4 ;
V_144 = F_83 ( V_142 , V_148 ,
L_17 ) ;
V_2 -> V_6 = F_85 ( & V_12 -> V_24 , V_144 ) ;
if ( F_86 ( V_2 -> V_6 ) ) {
V_146 = F_87 ( V_2 -> V_6 ) ;
goto V_149;
}
V_144 = F_83 ( V_142 , V_148 ,
L_18 ) ;
V_2 -> V_5 = F_85 ( & V_12 -> V_24 , V_144 ) ;
if ( F_86 ( V_2 -> V_5 ) ) {
V_146 = F_87 ( V_2 -> V_5 ) ;
goto V_149;
}
}
F_89 ( & V_12 -> V_24 , L_19 ,
V_2 -> V_20 -> V_158 , V_145 ) ;
V_144 = F_83 ( V_142 , V_148 , L_20 ) ;
V_2 -> V_72 = F_85 ( & V_12 -> V_24 , V_144 ) ;
if ( F_86 ( V_2 -> V_72 ) ) {
V_146 = F_87 ( V_2 -> V_72 ) ;
goto V_149;
}
V_144 = F_83 ( V_142 , V_148 , L_21 ) ;
V_2 -> V_129 = F_85 ( & V_12 -> V_24 , V_144 ) ;
if ( F_86 ( V_2 -> V_129 ) ) {
V_146 = F_87 ( V_2 -> V_129 ) ;
goto V_149;
}
V_2 -> V_65 = F_90 ( V_142 , L_22 ) ;
if ( V_2 -> V_65 < 0 ) {
V_146 = V_2 -> V_65 ;
goto V_149;
}
V_146 = F_91 ( V_142 -> V_24 . V_159 , L_23 , & V_131 ) ;
if ( V_146 ) {
F_10 ( & V_142 -> V_24 , L_24 ) ;
goto V_149;
}
if ( V_131 > 5 ) {
F_10 ( & V_142 -> V_24 , L_25 ,
V_131 ) ;
V_146 = - V_39 ;
goto V_149;
}
V_2 -> V_131 = V_131 ;
V_146 = F_91 ( V_142 -> V_24 . V_159 , L_26 , & V_89 ) ;
if ( V_146 ) {
F_10 ( & V_142 -> V_24 , L_27 ) ;
goto V_149;
}
if ( V_89 > 5 ) {
F_10 ( & V_142 -> V_24 , L_28 , V_89 ) ;
V_146 = - V_39 ;
goto V_149;
}
V_2 -> V_89 = V_89 ;
V_2 -> V_123 = F_88 ( & V_12 -> V_24 , V_160 - 1 ,
sizeof( * V_2 -> V_123 ) , V_151 ) ;
if ( ! V_2 -> V_123 ) {
V_146 = - V_147 ;
goto V_149;
}
V_2 -> V_85 = 0 ;
V_2 -> V_83 = V_160 - 1 ;
F_92 ( V_142 , V_12 ) ;
F_93 ( & V_2 -> V_34 ) ;
V_12 -> V_33 = F_16 ;
V_12 -> V_161 = F_18 ;
V_12 -> V_162 = F_20 ;
F_17 ( & V_142 -> V_24 , L_29 ) ;
V_2 -> V_77 = F_94 ( V_142 -> V_24 . V_159 ,
& V_163 , V_2 ) ;
if ( ! V_2 -> V_77 ) {
F_10 ( & V_142 -> V_24 , L_30 ) ;
V_146 = - V_147 ;
goto V_149;
}
F_95 ( V_2 -> V_65 , F_34 , V_2 ) ;
F_96 ( V_2 -> V_65 ) ;
V_146 = F_97 ( V_12 ) ;
if ( V_146 )
goto V_164;
return 0 ;
V_164:
F_95 ( V_2 -> V_65 , NULL , NULL ) ;
F_98 ( V_2 -> V_77 ) ;
V_149:
F_99 ( V_12 ) ;
return V_146 ;
}
static int F_100 ( struct V_141 * V_142 )
{
struct V_11 * V_12 = F_101 ( V_142 ) ;
struct V_1 * V_2 = F_8 ( V_12 ) ;
F_102 ( V_12 ) ;
F_95 ( V_2 -> V_65 , NULL , NULL ) ;
F_98 ( V_2 -> V_77 ) ;
F_99 ( V_12 ) ;
return 0 ;
}
