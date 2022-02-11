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
static void
F_4 ( struct V_1 * V_2 , T_2 * V_7 , T_1 V_8 , T_2 V_9 )
{
T_1 V_10 = F_5 ( V_2 -> V_6 + V_8 ) ;
memcpy ( V_7 , & V_10 , ( V_9 & 3 ) + 1 ) ;
}
static void F_6 ( struct V_1 * V_2 , const T_2 * V_7 ,
T_1 V_8 , T_2 V_9 )
{
T_1 V_10 = 0 ;
memcpy ( & V_10 , V_7 , ( V_9 & 3 ) + 1 ) ;
F_7 ( V_10 , V_2 -> V_5 + V_8 ) ;
}
static int F_8 ( struct V_11 * V_12 ,
void T_3 * V_13 , T_2 V_14 , T_4 V_15 ,
enum V_16 V_17 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
T_1 V_18 = 0 ;
T_1 V_19 = V_20 ;
T_1 V_3 ;
int V_21 ;
V_21 = V_2 -> V_22 -> V_3 ( V_2 , V_14 , V_15 , V_17 ) ;
if ( V_21 < 0 )
return V_21 ;
V_3 = V_21 ;
V_3 += V_23 ;
while ( V_19 -- ) {
V_18 = F_10 ( V_13 + V_3 ) ;
if ( V_18 & V_24 ) {
if ( V_18 & V_25 ) {
F_11 ( & V_12 -> V_26 , L_1 ,
V_27 , V_18 ) ;
return - V_28 ;
}
if ( V_18 & V_29 ) {
F_11 ( & V_12 -> V_26 , L_2 ,
V_27 , V_18 ) ;
return - V_30 ;
}
if ( V_18 & V_31 ) {
F_11 ( & V_12 -> V_26 , L_3 ,
V_27 , V_18 ) ;
return - V_30 ;
}
return 0 ;
}
F_12 ( 1 ) ;
}
F_11 ( & V_12 -> V_26 , L_4 ,
V_27 , V_18 ) ;
return - V_32 ;
}
static int
F_13 ( struct V_11 * V_12 , T_2 V_33 , T_2 V_14 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
unsigned long V_34 ;
T_1 V_35 ;
int V_21 ;
T_1 V_3 ;
V_21 = V_2 -> V_22 -> V_3 ( V_2 , V_14 , 0 , V_36 ) ;
if ( V_21 < 0 )
return V_21 ;
V_3 = V_21 ;
V_35 = ( ( V_33 | 0x40 ) << 27 ) | ( ( V_14 & 0xf ) << 20 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_1 ( V_2 , V_3 + V_38 , V_35 ) ;
V_21 = F_8 ( V_12 , V_2 -> V_5 , V_14 , 0 ,
V_36 ) ;
F_15 ( & V_2 -> V_37 , V_34 ) ;
return V_21 ;
}
static int
F_16 ( struct V_11 * V_12 , T_2 V_33 , T_2 V_14 )
{
return - V_39 ;
}
static int F_17 ( struct V_11 * V_12 , T_2 V_33 , T_2 V_14 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
F_18 ( & V_12 -> V_26 , L_5 , V_33 , V_14 ) ;
if ( V_33 < V_40 || V_33 > V_41 )
return - V_42 ;
return V_2 -> V_22 -> V_43 ( V_12 , V_33 , V_14 ) ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_33 , T_2 V_14 ,
T_4 V_15 , T_2 * V_7 , T_5 V_44 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
unsigned long V_34 ;
T_2 V_9 = V_44 - 1 ;
T_1 V_35 ;
int V_21 ;
T_1 V_3 ;
V_21 = V_2 -> V_22 -> V_3 ( V_2 , V_14 , V_15 ,
V_45 ) ;
if ( V_21 < 0 )
return V_21 ;
V_3 = V_21 ;
if ( V_9 >= V_46 ) {
F_11 ( & V_12 -> V_26 , L_6 ,
V_46 , V_44 ) ;
return - V_42 ;
}
if ( V_33 >= 0x60 && V_33 <= 0x7F )
V_33 = V_47 ;
else if ( V_33 >= 0x20 && V_33 <= 0x2F )
V_33 = V_48 ;
else if ( V_33 >= 0x38 && V_33 <= 0x3F )
V_33 = V_49 ;
else
return - V_42 ;
V_35 = V_2 -> V_22 -> V_50 ( V_33 , V_14 , V_15 , V_9 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_3 ( V_2 , V_3 + V_38 , V_35 ) ;
V_21 = F_8 ( V_12 , V_2 -> V_6 , V_14 , V_15 ,
V_45 ) ;
if ( V_21 )
goto V_51;
F_4 ( V_2 , V_7 , V_3 + V_52 ,
F_20 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_4 ( V_2 , V_7 + 4 , V_3 + V_53 ,
V_9 - 4 ) ;
V_51:
F_15 ( & V_2 -> V_37 , V_34 ) ;
return V_21 ;
}
static int F_21 ( struct V_11 * V_12 , T_2 V_33 , T_2 V_14 ,
T_4 V_15 , const T_2 * V_7 , T_5 V_44 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
unsigned long V_34 ;
T_2 V_9 = V_44 - 1 ;
T_1 V_35 ;
int V_21 ;
T_1 V_3 ;
V_21 = V_2 -> V_22 -> V_3 ( V_2 , V_14 , V_15 ,
V_36 ) ;
if ( V_21 < 0 )
return V_21 ;
V_3 = V_21 ;
if ( V_9 >= V_46 ) {
F_11 ( & V_12 -> V_26 , L_6 ,
V_46 , V_44 ) ;
return - V_42 ;
}
if ( V_33 >= 0x40 && V_33 <= 0x5F )
V_33 = V_54 ;
else if ( V_33 <= 0x0F )
V_33 = V_55 ;
else if ( V_33 >= 0x30 && V_33 <= 0x37 )
V_33 = V_56 ;
else if ( V_33 >= 0x80 )
V_33 = V_57 ;
else
return - V_42 ;
V_35 = V_2 -> V_22 -> V_50 ( V_33 , V_14 , V_15 , V_9 ) ;
F_14 ( & V_2 -> V_37 , V_34 ) ;
F_6 ( V_2 , V_7 , V_3 + V_58 ,
F_20 ( T_2 , V_9 , 3 ) ) ;
if ( V_9 > 3 )
F_6 ( V_2 , V_7 + 4 , V_3 + V_59 ,
V_9 - 4 ) ;
F_1 ( V_2 , V_3 + V_38 , V_35 ) ;
V_21 = F_8 ( V_12 , V_2 -> V_5 , V_14 , V_15 ,
V_36 ) ;
F_15 ( & V_2 -> V_37 , V_34 ) ;
return V_21 ;
}
static void F_22 ( struct V_60 * V_61 , T_2 V_8 , void * V_7 ,
T_5 V_44 )
{
struct V_1 * V_2 = F_23 ( V_61 ) ;
T_2 V_14 = F_24 ( V_61 -> V_62 ) ;
T_2 V_63 = F_25 ( V_61 -> V_62 ) ;
if ( F_21 ( V_2 -> V_64 , V_65 , V_14 ,
( V_63 << 8 ) + V_8 , V_7 , V_44 ) )
F_26 ( & V_2 -> V_64 -> V_26 , L_7 ,
V_61 -> V_66 ) ;
}
static void F_27 ( struct V_60 * V_61 , T_2 V_8 , void * V_7 , T_5 V_44 )
{
struct V_1 * V_2 = F_23 ( V_61 ) ;
T_2 V_14 = F_24 ( V_61 -> V_62 ) ;
T_2 V_63 = F_25 ( V_61 -> V_62 ) ;
if ( F_19 ( V_2 -> V_64 , V_67 , V_14 ,
( V_63 << 8 ) + V_8 , V_7 , V_44 ) )
F_26 ( & V_2 -> V_64 -> V_26 , L_7 ,
V_61 -> V_66 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_4 V_68 , int V_69 )
{
T_4 V_70 = V_2 -> V_71 [ V_68 ] . V_70 ;
T_2 V_14 = V_70 >> 8 ;
T_2 V_63 = V_70 & 0xFF ;
T_2 V_72 = F_29 ( V_69 ) ;
F_2 ( V_72 , V_2 -> V_22 -> V_73 ( V_2 , V_68 ) ) ;
if ( F_21 ( V_2 -> V_64 , V_65 , V_14 ,
( V_63 << 8 ) + V_74 , & V_72 , 1 ) )
F_26 ( & V_2 -> V_64 -> V_26 , L_8 ,
V_72 , V_70 ) ;
if ( F_21 ( V_2 -> V_64 , V_65 , V_14 ,
( V_63 << 8 ) + V_75 , & V_72 , 1 ) )
F_26 ( & V_2 -> V_64 -> V_26 , L_8 ,
V_72 , V_70 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_4 V_68 )
{
unsigned int V_66 ;
T_1 V_18 ;
int V_69 ;
T_2 V_14 = ( V_2 -> V_71 [ V_68 ] . V_70 >> 8 ) & 0xF ;
T_2 V_63 = V_2 -> V_71 [ V_68 ] . V_70 & 0xFF ;
V_18 = F_10 ( V_2 -> V_22 -> V_76 ( V_2 , V_68 ) ) ;
while ( V_18 ) {
V_69 = F_31 ( V_18 ) - 1 ;
V_18 &= ~ F_29 ( V_69 ) ;
V_66 = F_32 ( V_2 -> V_77 ,
F_33 ( V_14 , V_63 , V_69 , V_68 ) ) ;
if ( V_66 == 0 ) {
F_28 ( V_2 , V_68 , V_69 ) ;
continue;
}
F_34 ( V_66 ) ;
}
}
static void F_35 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_36 ( V_79 ) ;
const struct V_80 * V_22 = V_2 -> V_22 ;
struct V_81 * V_82 = F_37 ( V_79 ) ;
int V_83 = V_2 -> V_84 >> 5 ;
int V_85 = V_2 -> V_86 >> 5 ;
T_2 V_87 = V_2 -> V_87 ;
T_1 V_18 , V_88 ;
int V_89 , V_69 , V_68 ;
F_38 ( V_82 , V_79 ) ;
for ( V_89 = V_83 ; V_89 <= V_85 ; ++ V_89 ) {
V_18 = F_10 (
V_22 -> V_90 ( V_2 , V_87 , V_89 ) ) ;
while ( V_18 ) {
V_69 = F_31 ( V_18 ) - 1 ;
V_18 &= ~ F_29 ( V_69 ) ;
V_68 = V_69 + V_89 * 32 ;
V_88 = F_10 (
V_22 -> V_91 ( V_2 , V_68 ) ) ;
if ( V_88 & V_92 )
F_30 ( V_2 , V_68 ) ;
}
}
F_39 ( V_82 , V_79 ) ;
}
static void F_40 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_23 ( V_61 ) ;
T_2 V_66 = F_41 ( V_61 -> V_62 ) ;
T_4 V_68 = F_42 ( V_61 -> V_62 ) ;
T_2 V_10 ;
F_2 ( F_29 ( V_66 ) , V_2 -> V_22 -> V_73 ( V_2 , V_68 ) ) ;
V_10 = F_29 ( V_66 ) ;
F_22 ( V_61 , V_74 , & V_10 , 1 ) ;
}
static void F_43 ( struct V_60 * V_61 )
{
T_2 V_66 = F_41 ( V_61 -> V_62 ) ;
T_2 V_10 = F_29 ( V_66 ) ;
F_22 ( V_61 , V_75 , & V_10 , 1 ) ;
}
static void F_44 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_23 ( V_61 ) ;
const struct V_80 * V_22 = V_2 -> V_22 ;
T_2 V_66 = F_41 ( V_61 -> V_62 ) ;
T_4 V_68 = F_42 ( V_61 -> V_62 ) ;
T_2 V_7 [ 2 ] ;
F_2 ( V_92 ,
V_22 -> V_91 ( V_2 , V_68 ) ) ;
F_27 ( V_61 , V_93 , & V_7 [ 0 ] , 1 ) ;
if ( ! ( V_7 [ 0 ] & F_29 ( V_66 ) ) ) {
V_7 [ 0 ] = F_29 ( V_66 ) ;
V_7 [ 1 ] = F_29 ( V_66 ) ;
F_22 ( V_61 , V_74 , & V_7 , 2 ) ;
}
}
static int F_45 ( struct V_60 * V_61 , unsigned int V_94 )
{
struct V_95 type ;
T_6 V_96 ;
T_2 V_66 = F_41 ( V_61 -> V_62 ) ;
F_27 ( V_61 , V_97 , & type , sizeof( type ) ) ;
if ( V_94 & ( V_98 | V_99 ) ) {
type . type |= F_29 ( V_66 ) ;
if ( V_94 & V_98 )
type . V_100 |= F_29 ( V_66 ) ;
if ( V_94 & V_99 )
type . V_101 |= F_29 ( V_66 ) ;
V_96 = V_102 ;
} else {
if ( ( V_94 & ( V_103 ) ) &&
( V_94 & ( V_104 ) ) )
return - V_42 ;
type . type &= ~ F_29 ( V_66 ) ;
if ( V_94 & V_103 )
type . V_100 |= F_29 ( V_66 ) ;
else
type . V_101 |= F_29 ( V_66 ) ;
V_96 = V_105 ;
}
F_22 ( V_61 , V_97 , & type , sizeof( type ) ) ;
F_46 ( V_61 , V_96 ) ;
return 0 ;
}
static int F_47 ( struct V_60 * V_61 , unsigned int V_106 )
{
struct V_1 * V_2 = F_23 ( V_61 ) ;
return F_48 ( V_2 -> V_66 , V_106 ) ;
}
static int F_49 ( struct V_60 * V_61 ,
enum V_107 V_108 ,
bool * V_109 )
{
T_2 V_66 = F_41 ( V_61 -> V_62 ) ;
T_2 V_18 = 0 ;
if ( V_108 != V_110 )
return - V_42 ;
F_27 ( V_61 , V_111 , & V_18 , 1 ) ;
* V_109 = ! ! ( V_18 & F_29 ( V_66 ) ) ;
return 0 ;
}
static int F_50 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_23 ( V_61 ) ;
T_4 V_112 = F_25 ( V_61 -> V_62 ) ;
T_4 V_68 = F_42 ( V_61 -> V_62 ) ;
T_4 V_14 = F_24 ( V_61 -> V_62 ) ;
T_4 V_66 = F_41 ( V_61 -> V_62 ) ;
if ( V_2 -> V_71 [ V_68 ] . V_113 != V_2 -> V_87 ) {
F_11 ( & V_2 -> V_64 -> V_26 , L_9 ,
V_14 , V_112 , V_66 , V_2 -> V_87 ,
V_2 -> V_71 [ V_68 ] . V_113 ) ;
return - V_114 ;
}
return 0 ;
}
static int F_51 ( struct V_115 * V_61 ,
struct V_116 * V_117 ,
const T_1 * V_118 ,
unsigned int V_119 ,
unsigned long * V_120 ,
unsigned int * V_121 )
{
struct V_1 * V_2 = V_61 -> V_122 ;
T_4 V_68 , V_70 ;
int V_21 ;
F_18 ( & V_2 -> V_64 -> V_26 , L_10 ,
V_118 [ 0 ] , V_118 [ 1 ] , V_118 [ 2 ] ) ;
if ( F_52 ( V_61 ) != V_117 )
return - V_42 ;
if ( V_119 != 4 )
return - V_42 ;
if ( V_118 [ 0 ] > 0xF || V_118 [ 1 ] > 0xFF || V_118 [ 2 ] > 0x7 )
return - V_42 ;
V_70 = V_118 [ 0 ] << 8 | V_118 [ 1 ] ;
V_21 = V_2 -> V_22 -> V_123 ( V_2 , V_70 ) ;
if ( V_21 < 0 ) {
F_11 ( & V_2 -> V_64 -> V_26 , L_11 ,
V_118 [ 0 ] , V_118 [ 1 ] , V_118 [ 2 ] , V_21 ) ;
return V_21 ;
}
V_68 = V_21 ;
if ( V_68 > V_2 -> V_86 )
V_2 -> V_86 = V_68 ;
if ( V_68 < V_2 -> V_84 )
V_2 -> V_84 = V_68 ;
* V_120 = F_33 ( V_118 [ 0 ] , V_118 [ 1 ] , V_118 [ 2 ] , V_68 ) ;
* V_121 = V_118 [ 3 ] & V_124 ;
F_18 ( & V_2 -> V_64 -> V_26 , L_12 , * V_120 ) ;
return 0 ;
}
static int F_53 ( struct V_115 * V_61 ,
unsigned int V_125 ,
T_7 V_62 )
{
struct V_1 * V_2 = V_61 -> V_122 ;
F_18 ( & V_2 -> V_64 -> V_26 , L_13 , V_125 , V_62 ) ;
F_54 ( V_125 , & V_126 , V_105 ) ;
F_55 ( V_125 , V_61 -> V_122 ) ;
F_56 ( V_125 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , T_4 V_70 )
{
T_1 * V_127 = V_2 -> V_127 ;
int V_128 = 0 , V_89 ;
T_4 V_129 ;
T_4 V_68 ;
T_1 V_10 ;
V_129 = V_2 -> V_123 [ V_70 ] ;
if ( V_129 & V_130 ) {
V_68 = V_129 & ~ V_130 ;
return V_68 ;
}
for ( V_89 = 0 ; V_89 < V_131 ; ++ V_89 ) {
if ( ! F_58 ( V_128 , V_2 -> V_132 ) )
V_127 [ V_128 ] = F_10 ( V_2 -> V_133 +
F_59 ( V_128 ) ) ;
V_10 = V_127 [ V_128 ] ;
if ( V_70 & F_29 ( F_60 ( V_10 ) ) ) {
if ( F_61 ( V_10 ) ) {
V_128 = F_62 ( V_10 ) ;
} else {
V_68 = F_62 ( V_10 ) ;
V_2 -> V_123 [ V_70 ]
= V_68 | V_130 ;
V_2 -> V_71 [ V_68 ] . V_70 = V_70 ;
return V_68 ;
}
} else {
if ( F_63 ( V_10 ) ) {
V_128 = F_64 ( V_10 ) ;
} else {
V_68 = F_64 ( V_10 ) ;
V_2 -> V_123 [ V_70 ]
= V_68 | V_130 ;
V_2 -> V_71 [ V_68 ] . V_70 = V_70 ;
return V_68 ;
}
}
}
return - V_114 ;
}
static int F_65 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 ,
enum V_16 V_17 )
{
return 0x800 + 0x80 * V_2 -> V_134 ;
}
static T_4 F_66 ( struct V_1 * V_2 , T_4 V_70 )
{
struct V_71 * V_135 = & V_2 -> V_71 [ V_2 -> V_136 ] ;
T_1 V_137 , V_3 ;
T_4 V_69 , V_68 ;
for ( V_68 = V_2 -> V_136 ; ; V_68 ++ , V_135 ++ ) {
V_3 = V_2 -> V_22 -> V_138 ( V_68 ) ;
if ( V_3 >= V_2 -> V_139 )
break;
V_137 = F_10 ( V_2 -> V_133 +
F_67 ( V_68 ) ) ;
V_135 -> V_113 = F_68 ( V_137 ) ;
V_135 -> V_140 = V_135 -> V_113 ;
V_137 = F_10 ( V_2 -> V_141 + V_3 ) ;
if ( ! V_137 )
continue;
V_69 = ( V_137 >> 8 ) & V_142 ;
V_2 -> V_123 [ V_69 ] = V_68 | V_130 ;
V_135 -> V_70 = V_69 ;
if ( V_69 == V_70 ) {
V_68 |= V_130 ;
break;
}
}
V_2 -> V_136 = V_68 & ~ V_130 ;
return V_68 ;
}
static int F_69 ( struct V_1 * V_2 , T_4 V_70 )
{
T_4 V_129 ;
V_129 = V_2 -> V_123 [ V_70 ] ;
if ( ! ( V_129 & V_130 ) )
V_129 = F_66 ( V_2 , V_70 ) ;
if ( ! ( V_129 & V_130 ) )
return - V_114 ;
return V_129 & ~ V_130 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_71 * V_135 = V_2 -> V_71 ;
struct V_71 * V_143 ;
T_4 V_89 , V_68 , V_70 ;
bool V_144 , V_145 ;
T_1 V_137 , V_3 ;
for ( V_89 = 0 ; ; V_89 ++ , V_135 ++ ) {
V_3 = V_2 -> V_22 -> V_138 ( V_89 ) ;
if ( V_3 >= V_2 -> V_139 )
break;
V_137 = F_10 ( V_2 -> V_141 + V_3 ) ;
if ( ! V_137 )
continue;
V_70 = ( V_137 >> 8 ) & V_142 ;
V_145 = F_71 ( V_137 ) ;
V_137 = F_10 ( V_2 -> V_133 +
F_67 ( V_89 ) ) ;
V_135 -> V_140 = F_68 ( V_137 ) ;
V_135 -> V_113 = V_145 ? V_135 -> V_140 : V_146 ;
V_144 = V_2 -> V_123 [ V_70 ] & V_130 ;
V_68 = V_2 -> V_123 [ V_70 ] & ~ V_130 ;
V_143 = & V_2 -> V_71 [ V_68 ] ;
if ( V_144 && V_145 &&
V_143 -> V_140 == V_2 -> V_87 ) {
V_143 -> V_113 = V_135 -> V_113 ;
} else if ( ! V_144 || V_145 ) {
V_2 -> V_123 [ V_70 ] = V_89 | V_130 ;
}
V_135 -> V_70 = V_70 ;
V_2 -> V_136 = V_89 ;
}
F_18 ( & V_2 -> V_64 -> V_26 , L_14 ) ;
for ( V_70 = 0 ; V_70 < V_147 ; V_70 ++ ) {
V_68 = V_2 -> V_123 [ V_70 ] ;
if ( V_68 & V_130 ) {
V_68 &= ~ V_130 ;
V_135 = & V_2 -> V_71 [ V_68 ] ;
F_18 ( & V_2 -> V_64 -> V_26 , L_15 ,
V_70 , V_68 , V_135 -> V_140 , V_135 -> V_113 ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , T_4 V_70 )
{
if ( ! ( V_2 -> V_123 [ V_70 ] & V_130 ) )
return - V_114 ;
return V_2 -> V_123 [ V_70 ] & ~ V_130 ;
}
static int F_73 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 ,
enum V_16 V_17 )
{
T_4 V_68 ;
T_4 V_70 ;
int V_21 ;
V_70 = V_14 << 8 | ( ( V_15 >> 8 ) & 0xFF ) ;
V_21 = F_69 ( V_2 , V_70 ) ;
if ( V_21 < 0 )
return V_21 ;
V_68 = V_21 ;
return 0x1000 * V_2 -> V_87 + 0x8000 * V_68 ;
}
static int F_74 ( struct V_1 * V_2 , T_2 V_14 , T_4 V_15 ,
enum V_16 V_17 )
{
T_4 V_68 ;
int V_21 ;
T_1 V_3 = 0 ;
T_4 V_70 = ( V_14 << 8 ) | ( V_15 >> 8 ) ;
V_21 = F_72 ( V_2 , V_70 ) ;
if ( V_21 < 0 )
return V_21 ;
V_68 = V_21 ;
switch ( V_17 ) {
case V_45 :
V_3 = 0x10000 * V_2 -> V_87 + 0x80 * V_68 ;
break;
case V_36 :
V_3 = 0x10000 * V_68 ;
break;
}
return V_3 ;
}
static T_1 F_75 ( T_2 V_33 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_33 << 27 ) | ( ( V_14 & 0xf ) << 20 ) | ( V_15 << 4 ) | ( V_9 & 0x7 ) ;
}
static T_1 F_76 ( T_2 V_33 , T_2 V_14 , T_4 V_15 , T_2 V_9 )
{
return ( V_33 << 27 ) | ( ( V_15 & 0xff ) << 4 ) | ( V_9 & 0x7 ) ;
}
static void T_3 *
F_77 ( struct V_1 * V_2 , T_2 V_148 , T_4 V_149 )
{
return V_2 -> V_150 + 0x20 * V_148 + 0x4 * V_149 ;
}
static void T_3 *
F_78 ( struct V_1 * V_2 , T_2 V_148 , T_4 V_149 )
{
return V_2 -> V_150 + 0x100000 + 0x1000 * V_148 + 0x4 * V_149 ;
}
static void T_3 *
F_79 ( struct V_1 * V_2 , T_2 V_148 , T_4 V_149 )
{
return V_2 -> V_150 + 0x200000 + 0x1000 * V_148 + 0x4 * V_149 ;
}
static void T_3 *
F_80 ( struct V_1 * V_2 , T_2 V_148 , T_4 V_149 )
{
return V_2 -> V_150 + 0x10000 * V_148 + 0x4 * V_149 ;
}
static void T_3 *
F_81 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_150 + 0x200 + 0x4 * V_149 ;
}
static void T_3 *
F_82 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_150 + 0x1000 * V_149 ;
}
static void T_3 *
F_83 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_5 + 0x100 + 0x10000 * V_149 ;
}
static void T_3 *
F_84 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_150 + 0x600 + 0x4 * V_149 ;
}
static void T_3 *
F_85 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_150 + 0x4 + 0x1000 * V_149 ;
}
static void T_3 *
F_86 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_5 + 0x104 + 0x10000 * V_149 ;
}
static void T_3 *
F_87 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_150 + 0xA00 + 0x4 * V_149 ;
}
static void T_3 *
F_88 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_150 + 0x8 + 0x1000 * V_149 ;
}
static void T_3 *
F_89 ( struct V_1 * V_2 , T_4 V_149 )
{
return V_2 -> V_5 + 0x108 + 0x10000 * V_149 ;
}
static T_1 F_90 ( T_4 V_149 )
{
return 0x800 + 0x4 * V_149 ;
}
static T_1 F_91 ( T_4 V_149 )
{
return 0x900 + 0x4 * V_149 ;
}
static int F_92 ( struct V_151 * V_152 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_153 * V_154 ;
void T_3 * V_141 ;
T_1 * V_127 ;
T_1 V_134 , V_87 , V_155 ;
int V_156 ;
V_12 = F_93 ( & V_152 -> V_26 , sizeof( * V_2 ) ) ;
if ( ! V_12 )
return - V_157 ;
V_2 = F_9 ( V_12 ) ;
V_2 -> V_64 = V_12 ;
V_154 = F_94 ( V_152 , V_158 , L_16 ) ;
V_141 = F_95 ( & V_12 -> V_26 , V_154 ) ;
if ( F_96 ( V_141 ) ) {
V_156 = F_97 ( V_141 ) ;
goto V_159;
}
V_2 -> V_139 = F_98 ( V_154 ) ;
V_2 -> V_123 = F_99 ( & V_12 -> V_26 , V_147 ,
sizeof( * V_2 -> V_123 ) ,
V_160 ) ;
if ( ! V_2 -> V_123 ) {
V_156 = - V_157 ;
goto V_159;
}
V_155 = F_10 ( V_141 + V_161 ) ;
if ( V_155 < V_162 ) {
V_2 -> V_22 = & V_163 ;
V_2 -> V_5 = V_141 ;
V_2 -> V_6 = V_141 ;
} else {
V_2 -> V_141 = V_141 ;
if ( V_155 < V_164 )
V_2 -> V_22 = & V_165 ;
else if ( V_155 < V_166 )
V_2 -> V_22 = & V_167 ;
else
V_2 -> V_22 = & V_168 ;
V_154 = F_94 ( V_152 , V_158 ,
L_17 ) ;
V_2 -> V_6 = F_95 ( & V_12 -> V_26 , V_154 ) ;
if ( F_96 ( V_2 -> V_6 ) ) {
V_156 = F_97 ( V_2 -> V_6 ) ;
goto V_159;
}
V_154 = F_94 ( V_152 , V_158 ,
L_18 ) ;
V_2 -> V_5 = F_95 ( & V_12 -> V_26 , V_154 ) ;
if ( F_96 ( V_2 -> V_5 ) ) {
V_156 = F_97 ( V_2 -> V_5 ) ;
goto V_159;
}
}
F_100 ( & V_12 -> V_26 , L_19 ,
V_2 -> V_22 -> V_169 , V_155 ) ;
V_154 = F_94 ( V_152 , V_158 , L_20 ) ;
V_2 -> V_150 = F_95 ( & V_12 -> V_26 , V_154 ) ;
if ( F_96 ( V_2 -> V_150 ) ) {
V_156 = F_97 ( V_2 -> V_150 ) ;
goto V_159;
}
V_154 = F_94 ( V_152 , V_158 , L_21 ) ;
V_2 -> V_133 = F_95 ( & V_12 -> V_26 , V_154 ) ;
if ( F_96 ( V_2 -> V_133 ) ) {
V_156 = F_97 ( V_2 -> V_133 ) ;
goto V_159;
}
V_2 -> V_66 = F_101 ( V_152 , L_22 ) ;
if ( V_2 -> V_66 < 0 ) {
V_156 = V_2 -> V_66 ;
goto V_159;
}
V_156 = F_102 ( V_152 -> V_26 . V_170 , L_23 , & V_134 ) ;
if ( V_156 ) {
F_11 ( & V_152 -> V_26 , L_24 ) ;
goto V_159;
}
if ( V_134 > 5 ) {
F_11 ( & V_152 -> V_26 , L_25 ,
V_134 ) ;
V_156 = - V_42 ;
goto V_159;
}
V_2 -> V_134 = V_134 ;
V_156 = F_102 ( V_152 -> V_26 . V_170 , L_26 , & V_87 ) ;
if ( V_156 ) {
F_11 ( & V_152 -> V_26 , L_27 ) ;
goto V_159;
}
if ( V_87 > 5 ) {
F_11 ( & V_152 -> V_26 , L_28 , V_87 ) ;
V_156 = - V_42 ;
goto V_159;
}
V_2 -> V_87 = V_87 ;
V_127 = F_99 ( & V_12 -> V_26 , V_171 ,
sizeof( * V_127 ) , V_160 ) ;
if ( ! V_127 ) {
V_156 = - V_157 ;
goto V_159;
}
V_2 -> V_127 = V_127 ;
V_2 -> V_86 = 0 ;
V_2 -> V_84 = V_171 - 1 ;
F_103 ( V_152 , V_12 ) ;
F_104 ( & V_2 -> V_37 ) ;
V_12 -> V_35 = F_17 ;
V_12 -> V_172 = F_19 ;
V_12 -> V_173 = F_21 ;
if ( V_155 >= V_166 ) {
V_156 = F_70 ( V_2 ) ;
if ( V_156 ) {
F_11 ( & V_152 -> V_26 , L_29 ,
V_156 ) ;
goto V_159;
}
}
F_18 ( & V_152 -> V_26 , L_30 ) ;
V_2 -> V_77 = F_105 ( V_152 -> V_26 . V_170 ,
& V_174 , V_2 ) ;
if ( ! V_2 -> V_77 ) {
F_11 ( & V_152 -> V_26 , L_31 ) ;
V_156 = - V_157 ;
goto V_159;
}
F_106 ( V_2 -> V_66 , F_35 ,
V_2 ) ;
V_156 = F_107 ( V_12 ) ;
if ( V_156 )
goto V_175;
return 0 ;
V_175:
F_106 ( V_2 -> V_66 , NULL , NULL ) ;
F_108 ( V_2 -> V_77 ) ;
V_159:
F_109 ( V_12 ) ;
return V_156 ;
}
static int F_110 ( struct V_151 * V_152 )
{
struct V_11 * V_12 = F_111 ( V_152 ) ;
struct V_1 * V_2 = F_9 ( V_12 ) ;
F_112 ( V_12 ) ;
F_106 ( V_2 -> V_66 , NULL , NULL ) ;
F_108 ( V_2 -> V_77 ) ;
F_109 ( V_12 ) ;
return 0 ;
}
