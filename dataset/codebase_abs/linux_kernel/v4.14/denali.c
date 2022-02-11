static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
F_5 ( V_6 , V_5 -> V_8 + V_9 ) ;
F_5 ( V_7 , V_5 -> V_8 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_5 )
{
T_1 V_11 = F_7 ( V_5 -> V_12 + V_13 ) ;
V_5 -> V_14 = 1 << ( V_11 & V_15 ) ;
if ( V_5 -> V_16 < 0x0501 )
V_5 -> V_14 <<= 1 ;
}
static void F_8 ( struct V_1 * V_5 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_5 ( V_19 , V_5 -> V_12 + F_9 ( V_17 ) ) ;
F_5 ( V_20 , V_5 -> V_12 + V_21 ) ;
}
static void F_10 ( struct V_1 * V_5 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_5 ( 0 , V_5 -> V_12 + F_9 ( V_17 ) ) ;
F_5 ( 0 , V_5 -> V_12 + V_21 ) ;
}
static void F_11 ( struct V_1 * V_5 ,
int V_22 , T_1 V_23 )
{
F_5 ( V_23 , V_5 -> V_12 + F_12 ( V_22 ) ) ;
}
static void F_13 ( struct V_1 * V_5 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_11 ( V_5 , V_17 , V_19 ) ;
}
static T_2 F_14 ( int V_24 , void * V_25 )
{
struct V_1 * V_5 = V_25 ;
T_2 V_26 = V_27 ;
T_1 V_23 ;
int V_17 ;
F_15 ( & V_5 -> V_28 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_23 = F_7 ( V_5 -> V_12 + F_12 ( V_17 ) ) ;
if ( V_23 )
V_26 = V_29 ;
F_11 ( V_5 , V_17 , V_23 ) ;
if ( V_17 != V_5 -> V_30 )
continue;
V_5 -> V_23 |= V_23 ;
if ( V_5 -> V_23 & V_5 -> V_31 )
F_16 ( & V_5 -> F_16 ) ;
}
F_17 ( & V_5 -> V_28 ) ;
return V_26 ;
}
static void F_18 ( struct V_1 * V_5 )
{
unsigned long V_32 ;
F_19 ( & V_5 -> V_28 , V_32 ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_31 = 0 ;
F_20 ( & V_5 -> V_28 , V_32 ) ;
}
static T_1 F_21 ( struct V_1 * V_5 ,
T_1 V_31 )
{
unsigned long V_33 , V_32 ;
T_1 V_23 ;
F_19 ( & V_5 -> V_28 , V_32 ) ;
V_23 = V_5 -> V_23 ;
if ( V_31 & V_23 ) {
F_20 ( & V_5 -> V_28 , V_32 ) ;
return V_23 ;
}
V_5 -> V_31 = V_31 ;
F_22 ( & V_5 -> F_16 ) ;
F_20 ( & V_5 -> V_28 , V_32 ) ;
V_33 = F_23 ( & V_5 -> F_16 ,
F_24 ( 1000 ) ) ;
if ( ! V_33 ) {
F_25 ( V_5 -> V_34 , L_1 ,
V_5 -> V_31 ) ;
return 0 ;
}
return V_5 -> V_23 ;
}
static T_1 F_26 ( struct V_1 * V_5 )
{
unsigned long V_32 ;
T_1 V_23 ;
F_19 ( & V_5 -> V_28 , V_32 ) ;
V_23 = V_5 -> V_23 ;
F_20 ( & V_5 -> V_28 , V_32 ) ;
return V_23 ;
}
static void F_27 ( struct V_1 * V_5 , bool V_35 ,
bool V_36 )
{
int V_37 , V_38 ;
V_37 = V_35 ? V_39 : 0 ;
V_38 = V_36 ? V_40 : 0 ;
F_5 ( V_37 , V_5 -> V_12 + V_41 ) ;
F_5 ( V_38 , V_5 -> V_12 + V_42 ) ;
}
static void F_28 ( struct V_2 * V_3 , T_3 * V_43 , int V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_17 ;
F_5 ( V_45 | F_29 ( V_5 ) ,
V_5 -> V_8 + V_9 ) ;
for ( V_17 = 0 ; V_17 < V_44 ; V_17 ++ )
V_43 [ V_17 ] = F_7 ( V_5 -> V_8 + V_10 ) ;
}
static void F_30 ( struct V_2 * V_3 , const T_3 * V_43 , int V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_17 ;
F_5 ( V_45 | F_29 ( V_5 ) ,
V_5 -> V_8 + V_9 ) ;
for ( V_17 = 0 ; V_17 < V_44 ; V_17 ++ )
F_5 ( V_43 [ V_17 ] , V_5 -> V_8 + V_10 ) ;
}
static void F_31 ( struct V_2 * V_3 , T_3 * V_43 , int V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_4 * V_46 = ( T_4 * ) V_43 ;
int V_17 ;
F_5 ( V_45 | F_29 ( V_5 ) ,
V_5 -> V_8 + V_9 ) ;
for ( V_17 = 0 ; V_17 < V_44 / 2 ; V_17 ++ )
V_46 [ V_17 ] = F_7 ( V_5 -> V_8 + V_10 ) ;
}
static void F_32 ( struct V_2 * V_3 , const T_3 * V_43 ,
int V_44 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
const T_4 * V_46 = ( const T_4 * ) V_43 ;
int V_17 ;
F_5 ( V_45 | F_29 ( V_5 ) ,
V_5 -> V_8 + V_9 ) ;
for ( V_17 = 0 ; V_17 < V_44 / 2 ; V_17 ++ )
F_5 ( V_46 [ V_17 ] , V_5 -> V_8 + V_10 ) ;
}
static T_3 F_33 ( struct V_2 * V_3 )
{
T_3 V_47 ;
F_28 ( V_3 , & V_47 , 1 ) ;
return V_47 ;
}
static void F_34 ( struct V_2 * V_3 , T_3 V_47 )
{
F_30 ( V_3 , & V_47 , 1 ) ;
}
static T_4 F_35 ( struct V_2 * V_3 )
{
T_4 V_48 ;
F_31 ( V_3 , ( T_3 * ) & V_48 , 2 ) ;
return V_48 ;
}
static void F_36 ( struct V_2 * V_3 , int V_49 , unsigned int V_50 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 type ;
if ( V_50 & V_51 )
type = V_52 ;
else if ( V_50 & V_53 )
type = V_54 ;
else
return;
if ( V_50 & V_55 )
F_18 ( V_5 ) ;
F_4 ( V_5 , F_29 ( V_5 ) | type , V_49 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return ! ! ( F_26 ( V_5 ) & V_56 ) ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_57 * V_58 , T_3 * V_43 ,
unsigned long V_59 ,
unsigned int V_60 )
{
T_3 * V_61 = V_58 -> V_62 -> V_63 ;
int V_64 = V_58 -> V_65 . V_66 ;
int V_67 = V_58 -> V_65 . V_68 ;
int V_69 = V_58 -> V_65 . V_70 ;
int V_17 , V_26 , V_71 ;
V_26 = F_39 ( V_3 , V_61 , V_58 -> V_72 , 0 ,
V_58 -> V_65 . V_73 ) ;
if ( V_26 )
return V_26 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
if ( ! ( V_59 & F_40 ( V_17 ) ) )
continue;
V_71 = F_41 ( V_43 , V_67 ,
V_61 , V_69 ,
NULL , 0 ,
V_58 -> V_65 . V_74 ) ;
if ( V_71 < 0 ) {
V_3 -> V_75 . V_76 ++ ;
} else {
V_3 -> V_75 . V_77 += V_71 ;
V_60 = F_42 (unsigned int, max_bitflips, stat) ;
}
V_43 += V_67 ;
V_61 += V_69 ;
}
return V_60 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
unsigned long * V_59 )
{
struct V_57 * V_58 = F_3 ( V_3 ) ;
int V_22 = V_5 -> V_30 ;
T_1 V_78 ;
unsigned int V_60 ;
V_78 = F_7 ( V_5 -> V_12 + F_44 ( V_22 ) ) ;
V_78 >>= F_45 ( V_22 ) ;
if ( V_78 & V_79 ) {
* V_59 = F_46 ( V_58 -> V_65 . V_66 - 1 , 0 ) ;
return 0 ;
}
V_60 = V_78 & V_80 ;
V_3 -> V_75 . V_77 += V_60 ;
return V_60 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
unsigned long * V_59 , T_3 * V_43 )
{
unsigned int V_67 = V_5 -> V_4 . V_65 . V_68 ;
unsigned int V_81 = 0 ;
unsigned int V_60 = 0 ;
T_1 V_82 , V_83 ;
unsigned int V_84 , V_85 , V_86 ;
T_3 V_87 ;
unsigned int V_88 = 0 ;
T_1 V_23 ;
F_18 ( V_5 ) ;
do {
V_82 = F_7 ( V_5 -> V_12 + V_89 ) ;
V_85 = F_48 ( V_82 ) ;
V_84 = F_49 ( V_82 ) ;
V_83 = F_7 ( V_5 -> V_12 + V_90 ) ;
V_87 = F_50 ( V_83 ) ;
V_86 = F_51 ( V_83 ) ;
if ( V_85 != V_88 )
V_81 = 0 ;
if ( F_52 ( V_83 ) ) {
* V_59 |= F_40 ( V_85 ) ;
} else if ( V_84 < V_67 ) {
int V_91 ;
unsigned int V_92 ;
V_91 = ( V_85 * V_67 + V_84 ) *
V_5 -> V_93 + V_86 ;
V_92 = F_53 ( V_43 [ V_91 ] ^ V_87 ) ;
V_43 [ V_91 ] ^= V_87 ;
V_3 -> V_75 . V_77 += V_92 ;
V_81 += V_92 ;
V_60 = F_54 ( V_60 , V_81 ) ;
}
V_88 = V_85 ;
} while ( ! F_55 ( V_83 ) );
V_23 = F_21 ( V_5 , V_94 ) ;
if ( ! ( V_23 & V_94 ) )
return - V_95 ;
return V_60 ;
}
static void F_56 ( struct V_1 * V_5 , bool V_96 )
{
F_5 ( V_96 ? V_97 : 0 , V_5 -> V_12 + V_98 ) ;
F_7 ( V_5 -> V_12 + V_98 ) ;
}
static void F_57 ( struct V_1 * V_5 ,
T_5 V_99 , int V_100 , int V_101 )
{
T_1 V_102 ;
const int V_103 = 1 ;
V_102 = V_104 | F_29 ( V_5 ) | V_100 ;
F_4 ( V_5 , V_102 ,
0x01002000 | ( 64 << 16 ) | ( V_101 << 8 ) | V_103 ) ;
F_4 ( V_5 , V_102 , V_99 ) ;
F_4 ( V_5 , V_102 , ( V_105 ) V_99 >> 32 ) ;
}
static void F_58 ( struct V_1 * V_5 ,
T_5 V_99 , int V_100 , int V_101 )
{
T_1 V_102 ;
const int V_103 = 1 ;
V_102 = V_104 | F_29 ( V_5 ) ;
F_4 ( V_5 , V_102 | V_100 ,
0x2000 | ( V_101 << 8 ) | V_103 ) ;
F_4 ( V_5 , V_102 | ( ( V_99 >> 16 ) << 8 ) , 0x2200 ) ;
F_4 ( V_5 , V_102 | ( ( V_99 & 0xffff ) << 8 ) , 0x2300 ) ;
F_4 ( V_5 , V_102 | 0x14000 , 0x2400 ) ;
}
static void F_59 ( struct V_1 * V_5 ,
T_5 V_99 , int V_100 , int V_101 )
{
if ( V_5 -> V_106 & V_107 )
F_57 ( V_5 , V_99 , V_100 , V_101 ) ;
else
F_58 ( V_5 , V_99 , V_100 , V_101 ) ;
}
static int F_60 ( struct V_1 * V_5 , void * V_43 ,
T_6 V_68 , int V_100 , int V_108 )
{
T_1 V_6 = F_29 ( V_5 ) | V_100 ;
T_1 * V_109 = ( T_1 * ) V_43 ;
T_1 V_23 , V_110 ;
int V_17 ;
if ( V_5 -> V_106 & V_111 )
V_110 = V_112 ;
else
V_110 = V_113 ;
F_18 ( V_5 ) ;
F_5 ( V_114 | V_6 , V_5 -> V_8 + V_9 ) ;
for ( V_17 = 0 ; V_17 < V_68 / 4 ; V_17 ++ )
* V_109 ++ = F_7 ( V_5 -> V_8 + V_10 ) ;
V_23 = F_21 ( V_5 , V_115 ) ;
if ( ! ( V_23 & V_115 ) )
return - V_95 ;
if ( V_23 & V_116 )
memset ( V_43 , 0xff , V_68 ) ;
return V_23 & V_110 ? - V_117 : 0 ;
}
static int F_61 ( struct V_1 * V_5 ,
const void * V_43 , T_6 V_68 , int V_100 , int V_108 )
{
T_1 V_6 = F_29 ( V_5 ) | V_100 ;
const T_1 * V_109 = ( T_1 * ) V_43 ;
T_1 V_23 ;
int V_17 ;
F_18 ( V_5 ) ;
F_5 ( V_114 | V_6 , V_5 -> V_8 + V_9 ) ;
for ( V_17 = 0 ; V_17 < V_68 / 4 ; V_17 ++ )
F_5 ( * V_109 ++ , V_5 -> V_8 + V_10 ) ;
V_23 = F_21 ( V_5 ,
V_118 | V_119 ) ;
if ( ! ( V_23 & V_118 ) )
return - V_95 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_5 , void * V_43 ,
T_6 V_68 , int V_100 , int V_108 , int V_101 )
{
if ( V_101 )
return F_61 ( V_5 , V_43 , V_68 , V_100 , V_108 ) ;
else
return F_60 ( V_5 , V_43 , V_68 , V_100 , V_108 ) ;
}
static int F_63 ( struct V_1 * V_5 , void * V_43 ,
T_6 V_68 , int V_100 , int V_108 , int V_101 )
{
T_5 V_99 ;
T_1 V_31 , V_23 , V_110 ;
enum V_120 V_121 = V_101 ? V_122 : V_123 ;
int V_26 = 0 ;
V_99 = F_64 ( V_5 -> V_34 , V_43 , V_68 , V_121 ) ;
if ( F_65 ( V_5 -> V_34 , V_99 ) ) {
F_66 ( V_5 -> V_34 , L_2 ) ;
return F_62 ( V_5 , V_43 , V_68 , V_100 , V_108 , V_101 ) ;
}
if ( V_101 ) {
V_31 = V_124 | V_119 ;
V_110 = 0 ;
} else if ( V_5 -> V_106 & V_111 ) {
V_31 = V_124 ;
V_110 = V_112 ;
} else {
V_31 = V_124 ;
V_110 = V_113 ;
}
F_56 ( V_5 , true ) ;
F_18 ( V_5 ) ;
F_59 ( V_5 , V_99 , V_100 , V_101 ) ;
V_23 = F_21 ( V_5 , V_31 ) ;
if ( ! ( V_23 & V_124 ) )
V_26 = - V_95 ;
else if ( V_23 & V_110 )
V_26 = - V_117 ;
F_56 ( V_5 , false ) ;
F_67 ( V_5 -> V_34 , V_99 , V_68 , V_121 ) ;
if ( V_23 & V_116 )
memset ( V_43 , 0xff , V_68 ) ;
return V_26 ;
}
static int F_68 ( struct V_1 * V_5 , void * V_43 ,
T_6 V_68 , int V_100 , int V_108 , int V_101 )
{
F_27 ( V_5 , ! V_108 , V_108 ) ;
if ( V_5 -> V_125 )
return F_63 ( V_5 , V_43 , V_68 , V_100 , V_108 , V_101 ) ;
else
return F_62 ( V_5 , V_43 , V_68 , V_100 , V_108 , V_101 ) ;
}
static void F_69 ( struct V_2 * V_3 , struct V_57 * V_58 ,
int V_100 , int V_101 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_126 = V_101 ? V_127 : V_128 ;
unsigned int V_129 = V_101 ? V_130 : V_131 ;
int V_132 = V_3 -> V_132 ;
int V_133 = V_3 -> V_133 ;
T_3 * V_134 = V_58 -> V_72 ;
int V_64 = V_58 -> V_65 . V_66 ;
int V_67 = V_58 -> V_65 . V_68 ;
int V_69 = V_58 -> V_65 . V_70 ;
int V_135 = V_5 -> V_136 ;
T_6 V_68 = V_132 + V_133 ;
int V_17 , V_137 , V_44 ;
V_58 -> V_138 ( V_3 , V_126 , V_132 , V_100 ) ;
if ( V_101 )
V_58 -> V_139 ( V_3 , V_134 , V_135 ) ;
else
V_58 -> V_140 ( V_3 , V_134 , V_135 ) ;
V_134 += V_135 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
V_137 = V_67 + V_17 * ( V_67 + V_69 ) ;
V_44 = V_69 ;
if ( V_137 >= V_132 )
V_137 += V_135 ;
else if ( V_137 + V_44 > V_132 )
V_44 = V_132 - V_137 ;
V_58 -> V_138 ( V_3 , V_129 , V_137 , - 1 ) ;
if ( V_101 )
V_58 -> V_139 ( V_3 , V_134 , V_44 ) ;
else
V_58 -> V_140 ( V_3 , V_134 , V_44 ) ;
V_134 += V_44 ;
if ( V_44 < V_69 ) {
V_44 = V_69 - V_44 ;
V_58 -> V_138 ( V_3 , V_129 , V_132 + V_135 , - 1 ) ;
if ( V_101 )
V_58 -> V_139 ( V_3 , V_134 , V_44 ) ;
else
V_58 -> V_140 ( V_3 , V_134 , V_44 ) ;
V_134 += V_44 ;
}
}
V_44 = V_133 - ( V_134 - V_58 -> V_72 ) ;
V_58 -> V_138 ( V_3 , V_129 , V_68 - V_44 , - 1 ) ;
if ( V_101 )
V_58 -> V_139 ( V_3 , V_134 , V_44 ) ;
else
V_58 -> V_140 ( V_3 , V_134 , V_44 ) ;
}
static int F_70 ( struct V_2 * V_3 , struct V_57 * V_58 ,
T_3 * V_43 , int V_141 , int V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_132 = V_3 -> V_132 ;
int V_133 = V_3 -> V_133 ;
int V_64 = V_58 -> V_65 . V_66 ;
int V_67 = V_58 -> V_65 . V_68 ;
int V_69 = V_58 -> V_65 . V_70 ;
void * V_142 = V_5 -> V_43 ;
int V_135 = V_5 -> V_136 ;
T_6 V_68 = V_132 + V_133 ;
int V_26 , V_17 , V_137 , V_44 ;
V_26 = F_68 ( V_5 , V_142 , V_68 , V_100 , 1 , 0 ) ;
if ( V_26 )
return V_26 ;
if ( V_43 ) {
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
V_137 = V_17 * ( V_67 + V_69 ) ;
V_44 = V_67 ;
if ( V_137 >= V_132 )
V_137 += V_135 ;
else if ( V_137 + V_44 > V_132 )
V_44 = V_132 - V_137 ;
memcpy ( V_43 , V_142 + V_137 , V_44 ) ;
V_43 += V_44 ;
if ( V_44 < V_67 ) {
V_44 = V_67 - V_44 ;
memcpy ( V_43 , V_142 + V_132 + V_135 ,
V_44 ) ;
V_43 += V_44 ;
}
}
}
if ( V_141 ) {
T_3 * V_143 = V_58 -> V_72 ;
memcpy ( V_143 , V_142 + V_132 , V_135 ) ;
V_143 += V_135 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
V_137 = V_67 + V_17 * ( V_67 + V_69 ) ;
V_44 = V_69 ;
if ( V_137 >= V_132 )
V_137 += V_135 ;
else if ( V_137 + V_44 > V_132 )
V_44 = V_132 - V_137 ;
memcpy ( V_143 , V_142 + V_137 , V_44 ) ;
V_143 += V_44 ;
if ( V_44 < V_69 ) {
V_44 = V_69 - V_44 ;
memcpy ( V_143 , V_142 + V_132 + V_135 ,
V_44 ) ;
V_143 += V_44 ;
}
}
V_44 = V_133 - ( V_143 - V_58 -> V_72 ) ;
memcpy ( V_143 , V_142 + V_68 - V_44 , V_44 ) ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 , struct V_57 * V_58 ,
int V_100 )
{
F_69 ( V_3 , V_58 , V_100 , 0 ) ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 , struct V_57 * V_58 ,
int V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_144 ;
F_18 ( V_5 ) ;
F_69 ( V_3 , V_58 , V_100 , 1 ) ;
V_58 -> V_138 ( V_3 , V_145 , - 1 , - 1 ) ;
V_144 = V_58 -> V_146 ( V_3 , V_58 ) ;
return V_144 & V_147 ? - V_95 : 0 ;
}
static int F_73 ( struct V_2 * V_3 , struct V_57 * V_58 ,
T_3 * V_43 , int V_141 , int V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_59 = 0 ;
int V_71 = 0 ;
int V_26 ;
V_26 = F_68 ( V_5 , V_43 , V_3 -> V_132 , V_100 , 0 , 0 ) ;
if ( V_26 && V_26 != - V_117 )
return V_26 ;
if ( V_5 -> V_106 & V_111 )
V_71 = F_43 ( V_3 , V_5 , & V_59 ) ;
else if ( V_26 == - V_117 )
V_71 = F_47 ( V_3 , V_5 , & V_59 , V_43 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_59 ) {
V_26 = F_71 ( V_3 , V_58 , V_100 ) ;
if ( V_26 )
return V_26 ;
V_71 = F_38 ( V_3 , V_58 , V_43 ,
V_59 , V_71 ) ;
}
return V_71 ;
}
static int F_74 ( struct V_2 * V_3 , struct V_57 * V_58 ,
const T_3 * V_43 , int V_141 , int V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_132 = V_3 -> V_132 ;
int V_133 = V_3 -> V_133 ;
int V_64 = V_58 -> V_65 . V_66 ;
int V_67 = V_58 -> V_65 . V_68 ;
int V_69 = V_58 -> V_65 . V_70 ;
void * V_142 = V_5 -> V_43 ;
int V_135 = V_5 -> V_136 ;
T_6 V_68 = V_132 + V_133 ;
int V_17 , V_137 , V_44 ;
if ( ! V_43 || ! V_141 )
memset ( V_142 , 0xff , V_68 ) ;
if ( V_43 ) {
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
V_137 = V_17 * ( V_67 + V_69 ) ;
V_44 = V_67 ;
if ( V_137 >= V_132 )
V_137 += V_135 ;
else if ( V_137 + V_44 > V_132 )
V_44 = V_132 - V_137 ;
memcpy ( V_142 + V_137 , V_43 , V_44 ) ;
V_43 += V_44 ;
if ( V_44 < V_67 ) {
V_44 = V_67 - V_44 ;
memcpy ( V_142 + V_132 + V_135 , V_43 ,
V_44 ) ;
V_43 += V_44 ;
}
}
}
if ( V_141 ) {
const T_3 * V_143 = V_58 -> V_72 ;
memcpy ( V_142 + V_132 , V_143 , V_135 ) ;
V_143 += V_135 ;
for ( V_17 = 0 ; V_17 < V_64 ; V_17 ++ ) {
V_137 = V_67 + V_17 * ( V_67 + V_69 ) ;
V_44 = V_69 ;
if ( V_137 >= V_132 )
V_137 += V_135 ;
else if ( V_137 + V_44 > V_132 )
V_44 = V_132 - V_137 ;
memcpy ( V_142 + V_137 , V_143 , V_44 ) ;
V_143 += V_44 ;
if ( V_44 < V_69 ) {
V_44 = V_69 - V_44 ;
memcpy ( V_142 + V_132 + V_135 , V_143 ,
V_44 ) ;
V_143 += V_44 ;
}
}
V_44 = V_133 - ( V_143 - V_58 -> V_72 ) ;
memcpy ( V_142 + V_68 - V_44 , V_143 , V_44 ) ;
}
return F_68 ( V_5 , V_142 , V_68 , V_100 , 1 , 1 ) ;
}
static int F_75 ( struct V_2 * V_3 , struct V_57 * V_58 ,
const T_3 * V_43 , int V_141 , int V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_68 ( V_5 , ( void * ) V_43 , V_3 -> V_132 ,
V_100 , 0 , 1 ) ;
}
static void F_76 ( struct V_2 * V_3 , int V_58 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
V_5 -> V_30 = V_58 ;
}
static int F_77 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_23 ;
V_23 = F_21 ( V_5 , V_56 ) ;
return V_23 & V_56 ? 0 : V_147 ;
}
static int F_78 ( struct V_2 * V_3 , int V_100 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_23 ;
F_18 ( V_5 ) ;
F_4 ( V_5 , V_104 | F_29 ( V_5 ) | V_100 ,
V_148 ) ;
V_23 = F_21 ( V_5 ,
V_149 | V_150 ) ;
return V_23 & V_149 ? 0 : V_147 ;
}
static int F_79 ( struct V_2 * V_3 , int V_151 ,
const struct V_152 * V_153 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
const struct V_154 * V_155 ;
unsigned long V_156 ;
int V_157 , V_158 , V_159 , V_160 , V_161 ;
int V_162 , V_163 , V_164 , V_165 ;
int V_166 ;
T_1 V_167 ;
V_155 = F_80 ( V_153 ) ;
if ( F_81 ( V_155 ) )
return F_82 ( V_155 ) ;
V_156 = F_83 ( 1000000000000ULL , V_5 -> V_168 ) ;
if ( ! V_156 )
return - V_169 ;
if ( V_151 == V_170 )
return 0 ;
V_157 = F_84 ( V_155 -> V_171 , V_156 ) ;
V_157 = F_85 ( int , V_157 , V_172 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_173 ) ;
V_167 &= ~ V_172 ;
V_167 |= V_157 ;
F_5 ( V_167 , V_5 -> V_12 + V_173 ) ;
V_158 = F_84 ( V_155 -> V_174 , V_156 ) ;
V_158 = F_85 ( int , V_158 , V_175 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_176 ) ;
V_167 &= ~ V_175 ;
V_167 |= V_158 ;
F_5 ( V_167 , V_5 -> V_12 + V_176 ) ;
V_159 = F_84 ( V_155 -> V_177 , V_156 ) ;
V_159 = F_85 ( int , V_159 , V_178 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_179 ) ;
V_167 &= ~ V_178 ;
V_167 |= V_159 ;
F_5 ( V_167 , V_5 -> V_12 + V_179 ) ;
V_160 = F_84 ( V_155 -> V_180 , V_156 ) ;
V_160 = F_85 ( int , V_160 , V_181 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_182 ) ;
V_167 &= ~ V_181 ;
V_167 |= V_160 ;
F_5 ( V_167 , V_5 -> V_12 + V_182 ) ;
V_166 = V_183 ;
if ( V_5 -> V_16 < 0x0501 )
V_166 >>= 1 ;
V_161 = F_84 ( V_155 -> V_184 , V_156 ) ;
V_161 = F_85 ( int , V_161 , V_166 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_185 ) ;
V_167 &= ~ V_166 ;
V_167 |= V_161 ;
F_5 ( V_167 , V_5 -> V_12 + V_185 ) ;
V_163 = F_84 ( F_54 ( V_155 -> V_186 , V_155 -> V_187 ) ,
V_156 ) ;
V_163 = F_85 ( int , V_163 , V_188 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_189 ) ;
V_167 &= ~ V_188 ;
V_167 |= V_163 ;
F_5 ( V_167 , V_5 -> V_12 + V_189 ) ;
V_162 = F_84 ( F_54 ( V_155 -> V_190 , V_155 -> V_191 ) ,
V_156 ) ;
V_164 = F_84 ( F_54 ( V_155 -> V_192 , V_155 -> V_193 ) ,
V_156 ) ;
V_164 = F_54 ( V_164 , V_194 ) ;
V_162 = F_54 ( V_162 , V_164 - V_163 ) ;
V_162 = F_85 ( int , V_162 , V_195 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_196 ) ;
V_167 &= ~ V_195 ;
V_167 |= V_162 ;
F_5 ( V_167 , V_5 -> V_12 + V_196 ) ;
V_165 = F_86 ( ( int ) F_84 ( V_155 -> V_197 , V_156 ) - V_162 ,
( int ) F_84 ( V_155 -> V_198 , V_156 ) - V_157 ,
0 ) ;
V_165 = F_85 ( int , V_165 , V_199 ) ;
V_167 = F_7 ( V_5 -> V_12 + V_200 ) ;
V_167 &= ~ V_199 ;
V_167 |= V_165 ;
F_5 ( V_167 , V_5 -> V_12 + V_200 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_5 )
{
T_7 V_23 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_5 -> V_14 ; V_17 ++ ) {
V_5 -> V_30 = V_17 ;
F_18 ( V_5 ) ;
F_5 ( F_88 ( V_17 ) ,
V_5 -> V_12 + V_201 ) ;
V_23 = F_21 ( V_5 ,
V_202 | V_56 | V_203 ) ;
if ( ! ( V_23 & V_56 ) )
break;
}
F_66 ( V_5 -> V_34 , L_3 , V_17 ) ;
V_5 -> V_14 = V_17 ;
}
static void F_89 ( struct V_1 * V_5 )
{
if ( ! V_5 -> V_16 )
V_5 -> V_16 = F_90 ( F_7 ( V_5 -> V_12 + V_204 ) ) ;
V_5 -> V_136 = F_7 ( V_5 -> V_12 + V_205 ) ;
F_6 ( V_5 ) ;
F_5 ( 0x0F , V_5 -> V_12 + V_206 ) ;
F_5 ( V_207 , V_5 -> V_12 + V_208 ) ;
F_5 ( 0xffff , V_5 -> V_12 + V_209 ) ;
F_5 ( 0 , V_5 -> V_12 + V_210 ) ;
F_5 ( 1 , V_5 -> V_12 + V_41 ) ;
}
int F_91 ( int V_211 , int V_74 )
{
return F_84 ( V_74 * F_92 ( V_211 * 8 ) , 16 ) * 2 ;
}
static int F_93 ( struct V_2 * V_3 , struct V_57 * V_58 ,
struct V_1 * V_5 )
{
int V_212 = V_3 -> V_133 - V_5 -> V_136 ;
int V_26 ;
if ( V_58 -> V_65 . V_68 && V_58 -> V_65 . V_74 )
return F_94 ( V_58 , V_5 -> V_213 , V_212 ) ;
if ( ! ( V_58 -> V_65 . V_214 & V_215 ) ) {
V_26 = F_95 ( V_58 , V_5 -> V_213 , V_212 ) ;
if ( ! V_26 )
return 0 ;
}
return F_96 ( V_58 , V_5 -> V_213 , V_212 ) ;
}
static int F_97 ( struct V_2 * V_3 , int V_216 ,
struct V_217 * V_218 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_57 * V_58 = F_3 ( V_3 ) ;
if ( V_216 )
return - V_219 ;
V_218 -> V_91 = V_5 -> V_136 ;
V_218 -> V_220 = V_58 -> V_65 . V_73 ;
return 0 ;
}
static int F_98 ( struct V_2 * V_3 , int V_216 ,
struct V_217 * V_218 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_57 * V_58 = F_3 ( V_3 ) ;
if ( V_216 )
return - V_219 ;
V_218 -> V_91 = V_58 -> V_65 . V_73 + V_5 -> V_136 ;
V_218 -> V_220 = V_3 -> V_133 - V_218 -> V_91 ;
return 0 ;
}
static void F_99 ( struct V_1 * V_5 )
{
F_100 ( & V_5 -> F_16 ) ;
F_101 ( & V_5 -> V_28 ) ;
}
static int F_102 ( struct V_1 * V_5 )
{
struct V_57 * V_58 = & V_5 -> V_4 ;
struct V_2 * V_3 = F_103 ( V_58 ) ;
V_5 -> V_93 = F_7 ( V_5 -> V_12 + V_221 ) ;
if ( V_5 -> V_93 == 0 ) {
V_5 -> V_93 = 1 ;
F_5 ( 1 , V_5 -> V_12 + V_221 ) ;
}
if ( V_5 -> V_93 == 1 )
return 0 ;
if ( V_5 -> V_93 != 2 ) {
F_25 ( V_5 -> V_34 , L_4 ,
V_5 -> V_93 ) ;
return - V_169 ;
}
V_3 -> V_68 <<= 1 ;
V_3 -> V_222 <<= 1 ;
V_3 -> V_132 <<= 1 ;
V_3 -> V_133 <<= 1 ;
V_58 -> V_223 <<= 1 ;
V_58 -> V_224 += 1 ;
V_58 -> V_225 += 1 ;
V_58 -> V_226 += 1 ;
V_58 -> V_227 += 1 ;
V_58 -> V_228 <<= 1 ;
V_58 -> V_65 . V_68 <<= 1 ;
V_58 -> V_65 . V_70 <<= 1 ;
V_58 -> V_65 . V_74 <<= 1 ;
V_5 -> V_136 <<= 1 ;
return 0 ;
}
int F_104 ( struct V_1 * V_5 )
{
struct V_57 * V_58 = & V_5 -> V_4 ;
struct V_2 * V_3 = F_103 ( V_58 ) ;
int V_26 ;
V_3 -> V_34 . V_229 = V_5 -> V_34 ;
F_89 ( V_5 ) ;
F_99 ( V_5 ) ;
F_13 ( V_5 ) ;
V_26 = F_105 ( V_5 -> V_34 , V_5 -> V_24 , F_14 ,
V_230 , V_231 , V_5 ) ;
if ( V_26 ) {
F_25 ( V_5 -> V_34 , L_5 ) ;
return V_26 ;
}
F_8 ( V_5 ) ;
F_87 ( V_5 ) ;
V_5 -> V_30 = V_232 ;
F_106 ( V_58 , V_5 -> V_34 -> V_233 ) ;
if ( ! V_3 -> V_234 )
V_3 -> V_234 = L_6 ;
V_58 -> V_235 = F_76 ;
V_58 -> V_236 = F_33 ;
V_58 -> V_237 = F_34 ;
V_58 -> V_238 = F_35 ;
V_58 -> V_239 = F_36 ;
V_58 -> V_240 = F_37 ;
V_58 -> V_146 = F_77 ;
if ( V_5 -> V_168 )
V_58 -> V_241 = F_79 ;
V_26 = F_107 ( V_3 , V_5 -> V_14 , NULL ) ;
if ( V_26 )
goto V_242;
if ( F_7 ( V_5 -> V_12 + V_13 ) & V_243 )
V_5 -> V_125 = 1 ;
if ( V_5 -> V_125 ) {
int V_244 = V_5 -> V_106 & V_107 ? 64 : 32 ;
V_26 = F_108 ( V_5 -> V_34 , F_109 ( V_244 ) ) ;
if ( V_26 ) {
F_110 ( V_5 -> V_34 ,
L_7 ) ;
V_5 -> V_125 = 0 ;
}
}
if ( V_5 -> V_125 ) {
V_58 -> V_214 |= V_245 ;
V_58 -> V_246 = 16 ;
}
V_58 -> V_247 |= V_248 ;
V_58 -> V_247 |= V_249 ;
V_58 -> V_65 . V_102 = V_250 ;
V_58 -> V_214 |= V_251 ;
V_26 = F_93 ( V_3 , V_58 , V_5 ) ;
if ( V_26 ) {
F_25 ( V_5 -> V_34 , L_8 ) ;
goto V_242;
}
F_66 ( V_5 -> V_34 ,
L_9 ,
V_58 -> V_65 . V_68 , V_58 -> V_65 . V_74 , V_58 -> V_65 . V_70 ) ;
F_5 ( F_111 ( V_58 -> V_65 . V_74 , 1 ) ,
V_5 -> V_12 + V_252 ) ;
F_5 ( V_3 -> V_222 / V_3 -> V_132 ,
V_5 -> V_12 + V_253 ) ;
F_5 ( V_58 -> V_214 & V_254 ? 1 : 0 ,
V_5 -> V_12 + V_255 ) ;
F_5 ( V_3 -> V_132 , V_5 -> V_12 + V_256 ) ;
F_5 ( V_3 -> V_133 , V_5 -> V_12 + V_257 ) ;
F_5 ( V_58 -> V_65 . V_68 , V_5 -> V_12 + V_258 ) ;
F_5 ( V_58 -> V_65 . V_68 , V_5 -> V_12 + V_259 ) ;
F_5 ( V_3 -> V_132 / V_58 -> V_65 . V_68 ,
V_5 -> V_12 + V_260 ) ;
F_112 ( V_3 , & V_261 ) ;
if ( V_58 -> V_214 & V_254 ) {
V_58 -> V_140 = F_31 ;
V_58 -> V_139 = F_32 ;
} else {
V_58 -> V_140 = F_28 ;
V_58 -> V_139 = F_30 ;
}
V_58 -> V_65 . V_214 |= V_262 ;
V_58 -> V_65 . V_263 = F_73 ;
V_58 -> V_65 . V_264 = F_70 ;
V_58 -> V_65 . V_265 = F_75 ;
V_58 -> V_65 . V_266 = F_74 ;
V_58 -> V_65 . V_267 = F_71 ;
V_58 -> V_65 . V_268 = F_72 ;
V_58 -> V_269 = F_78 ;
V_26 = F_102 ( V_5 ) ;
if ( V_26 )
goto V_242;
V_5 -> V_43 = F_113 ( V_3 -> V_132 + V_3 -> V_133 , V_270 ) ;
if ( ! V_5 -> V_43 ) {
V_26 = - V_271 ;
goto V_242;
}
V_26 = F_114 ( V_3 ) ;
if ( V_26 )
goto V_272;
V_26 = F_115 ( V_3 , NULL , 0 ) ;
if ( V_26 ) {
F_25 ( V_5 -> V_34 , L_10 , V_26 ) ;
goto V_272;
}
return 0 ;
V_272:
F_116 ( V_5 -> V_43 ) ;
V_242:
F_10 ( V_5 ) ;
return V_26 ;
}
void F_117 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_103 ( & V_5 -> V_4 ) ;
F_118 ( V_3 ) ;
F_116 ( V_5 -> V_43 ) ;
F_10 ( V_5 ) ;
}
