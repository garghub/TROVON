int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 , enum V_7 V_8 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_9 = V_6 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_10 = F_2 ( - 1 ) ;
F_3 ( & V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_12 , V_13 , ( unsigned long ) V_2 ) ;
V_2 -> V_14 = 0 ;
F_5 ( & V_2 -> V_15 ) ;
V_2 -> V_16 = false ;
V_2 -> V_17 = NULL ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( F_8 ( V_2 ) ) ;
F_9 ( & V_2 -> V_11 ) ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
int V_20 ;
V_20 = F_11 ( V_19 , 0 , 32 , 24 ) ;
if ( V_20 < 0 )
goto V_21;
V_20 = F_12 ( V_19 ,
V_22 ,
5000 , V_23 ) ;
if ( V_20 < 0 )
goto V_21;
if ( ! ( V_2 -> V_8 & V_24 ) )
goto V_21;
V_20 = F_13 ( V_19 , 0 ,
V_25 , 32 ) ;
if ( V_20 < 0 )
goto V_21;
V_20 = F_13 ( V_19 , 0 ,
V_26 , 32 ) ;
V_21:
return V_20 ;
}
void F_14 ( struct V_1 * V_2 ,
unsigned int V_27 ,
unsigned int V_28 ,
unsigned int V_29 )
{
unsigned int V_30 , V_31 , V_32 ;
V_32 = F_15 ( V_29 , 8 ) ;
if ( F_7 ( F_8 ( V_2 ) ) |
F_7 ( V_28 > V_33 ) |
F_7 ( V_32 > V_34 ) )
return;
for ( V_31 = 0 ; V_31 < F_16 ( V_35 ) ; ++ V_31 )
if ( V_35 [ V_31 ] == V_27 )
goto V_36;
F_7 ( 1 ) ;
return;
V_36:
V_2 -> V_28 = V_28 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_37 = V_2 -> V_28 + V_32 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_38 = V_39 [ V_31 ] ;
V_2 -> V_40 = V_41 - V_42 ;
if ( V_2 -> V_8 & V_24 )
V_2 -> V_40 += V_43 * V_2 -> V_38 / V_27 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ )
V_2 -> V_44 [ V_30 ] = V_30 ;
V_2 -> V_45 = V_2 -> V_28 ;
V_2 -> V_46 = V_27 - V_47 * V_2 -> V_38 + 1 ;
}
unsigned int F_17 ( struct V_1 * V_2 )
{
return 8 + V_2 -> V_38 * V_2 -> V_37 * 4 ;
}
void F_18 ( struct V_1 * V_2 ,
T_1 V_48 )
{
if ( F_7 ( F_19 ( V_2 ) ) )
return;
switch ( V_48 ) {
default:
F_7 ( 1 ) ;
case V_49 :
if ( V_2 -> V_9 == V_50 ) {
V_2 -> V_51 = V_52 ;
break;
}
F_7 ( 1 ) ;
case V_53 :
if ( V_2 -> V_9 == V_50 )
V_2 -> V_51 = V_54 ;
else
V_2 -> V_51 = V_55 ;
break;
}
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_12 ) ;
V_2 -> V_56 = 0 ;
V_2 -> V_57 = 0 ;
V_2 -> V_58 = true ;
}
static unsigned int F_22 ( struct V_1 * V_2 )
{
unsigned int V_59 , V_60 ;
if ( V_2 -> V_8 & V_24 )
V_60 = V_2 -> V_38 ;
else if ( ! F_23 ( V_2 -> V_31 ) ) {
V_60 = V_2 -> V_61 ;
} else {
V_59 = V_2 -> V_61 ;
if ( V_2 -> V_31 == V_62 )
V_60 = 5 + ( ( V_59 & 1 ) ^
( V_59 == 0 || V_59 >= 40 ) ) ;
else
V_60 = 11 * ( V_2 -> V_31 >> 1 ) + ( V_59 == 0 ) ;
if ( ++ V_59 >= ( 80 >> ( V_2 -> V_31 >> 1 ) ) )
V_59 = 0 ;
V_2 -> V_61 = V_59 ;
}
return V_60 ;
}
static unsigned int F_24 ( struct V_1 * V_2 ,
unsigned int V_63 )
{
unsigned int V_64 , V_59 , V_65 , V_66 ;
if ( V_2 -> V_67 < V_42 ) {
if ( ! F_23 ( V_2 -> V_31 ) )
V_64 = V_2 -> V_67 + V_2 -> V_68 ;
else {
V_59 = V_2 -> V_68 ;
V_65 = V_59 % 13 ;
V_64 = V_2 -> V_67 ;
V_64 += 1386 + ( ( V_65 && ! ( V_65 & 3 ) ) ||
V_59 == 146 ) ;
if ( ++ V_59 >= 147 )
V_59 = 0 ;
V_2 -> V_68 = V_59 ;
}
} else
V_64 = V_2 -> V_67 - V_42 ;
V_2 -> V_67 = V_64 ;
if ( V_64 < V_42 ) {
V_64 += V_2 -> V_40 ;
V_66 = ( V_63 + V_64 / V_42 ) << 12 ;
V_66 += V_64 % V_42 ;
return V_66 & V_69 ;
} else {
return V_70 ;
}
}
static void V_54 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
T_2 * V_73 , unsigned int V_74 )
{
struct V_18 * V_19 = V_72 -> V_19 ;
unsigned int V_75 , V_76 , V_30 , V_77 ;
const T_3 * V_78 ;
V_75 = V_2 -> V_28 ;
V_78 = ( void * ) V_19 -> V_79 +
F_25 ( V_19 , V_2 -> V_56 ) ;
V_76 = V_19 -> V_80 - V_2 -> V_56 ;
for ( V_30 = 0 ; V_30 < V_74 ; ++ V_30 ) {
for ( V_77 = 0 ; V_77 < V_75 ; ++ V_77 ) {
V_73 [ V_2 -> V_44 [ V_77 ] ] =
F_26 ( ( * V_78 >> 8 ) | 0x40000000 ) ;
V_78 ++ ;
}
V_73 += V_2 -> V_37 ;
if ( -- V_76 == 0 )
V_78 = ( void * ) V_19 -> V_79 ;
}
}
static void V_52 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
T_2 * V_73 , unsigned int V_74 )
{
struct V_18 * V_19 = V_72 -> V_19 ;
unsigned int V_75 , V_76 , V_30 , V_77 ;
const T_4 * V_78 ;
V_75 = V_2 -> V_28 ;
V_78 = ( void * ) V_19 -> V_79 +
F_25 ( V_19 , V_2 -> V_56 ) ;
V_76 = V_19 -> V_80 - V_2 -> V_56 ;
for ( V_30 = 0 ; V_30 < V_74 ; ++ V_30 ) {
for ( V_77 = 0 ; V_77 < V_75 ; ++ V_77 ) {
V_73 [ V_2 -> V_44 [ V_77 ] ] =
F_26 ( ( * V_78 << 8 ) | 0x42000000 ) ;
V_78 ++ ;
}
V_73 += V_2 -> V_37 ;
if ( -- V_76 == 0 )
V_78 = ( void * ) V_19 -> V_79 ;
}
}
static void V_55 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
T_2 * V_73 , unsigned int V_74 )
{
struct V_18 * V_19 = V_72 -> V_19 ;
unsigned int V_75 , V_76 , V_30 , V_77 ;
T_3 * V_81 ;
V_75 = V_2 -> V_28 ;
V_81 = ( void * ) V_19 -> V_79 +
F_25 ( V_19 , V_2 -> V_56 ) ;
V_76 = V_19 -> V_80 - V_2 -> V_56 ;
for ( V_30 = 0 ; V_30 < V_74 ; ++ V_30 ) {
for ( V_77 = 0 ; V_77 < V_75 ; ++ V_77 ) {
* V_81 = F_27 ( V_73 [ V_2 -> V_44 [ V_77 ] ] ) << 8 ;
V_81 ++ ;
}
V_73 += V_2 -> V_37 ;
if ( -- V_76 == 0 )
V_81 = ( void * ) V_19 -> V_79 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
T_2 * V_73 , unsigned int V_74 )
{
unsigned int V_30 , V_77 ;
for ( V_30 = 0 ; V_30 < V_74 ; ++ V_30 ) {
for ( V_77 = 0 ; V_77 < V_2 -> V_28 ; ++ V_77 )
V_73 [ V_2 -> V_44 [ V_77 ] ] = F_26 ( 0x40000000 ) ;
V_73 += V_2 -> V_37 ;
}
}
static bool F_29 ( struct V_1 * V_2 , unsigned int V_82 )
{
int V_83 ;
V_83 = V_2 -> V_84 [ V_82 ] ;
if ( V_83 == 0 )
return true ;
V_83 -= V_47 * V_2 -> V_38 ;
V_83 = F_30 ( V_83 , 0 ) ;
V_2 -> V_84 [ V_82 ] = V_83 ;
return V_83 < V_2 -> V_46 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_82 )
{
V_2 -> V_84 [ V_82 ] += V_35 [ V_2 -> V_31 ] ;
}
static void F_32 ( struct V_1 * V_2 ,
T_2 * V_73 , unsigned int V_74 )
{
unsigned int V_85 , V_82 ;
T_5 * V_86 ;
for ( V_85 = 0 ; V_85 < V_74 ; V_85 ++ ) {
V_86 = ( T_5 * ) & V_73 [ V_2 -> V_45 ] ;
V_82 = ( V_2 -> V_87 + V_85 ) % 8 ;
if ( V_85 < V_88 &&
F_29 ( V_2 , V_82 ) &&
V_2 -> V_89 [ V_82 ] != NULL &&
F_33 ( V_2 -> V_89 [ V_82 ] , & V_86 [ 1 ] , 1 ) == 1 ) {
F_31 ( V_2 , V_82 ) ;
V_86 [ 0 ] = 0x81 ;
} else {
V_86 [ 0 ] = 0x80 ;
V_86 [ 1 ] = 0 ;
}
V_86 [ 2 ] = 0 ;
V_86 [ 3 ] = 0 ;
V_73 += V_2 -> V_37 ;
}
}
static void F_34 ( struct V_1 * V_2 ,
T_2 * V_73 , unsigned int V_74 )
{
unsigned int V_85 , V_82 ;
int V_90 ;
T_5 * V_86 ;
for ( V_85 = 0 ; V_85 < V_74 ; V_85 ++ ) {
V_82 = ( V_2 -> V_87 + V_85 ) % 8 ;
V_86 = ( T_5 * ) & V_73 [ V_2 -> V_45 ] ;
V_90 = V_86 [ 0 ] - 0x80 ;
if ( ( 1 <= V_90 ) && ( V_90 <= 3 ) && ( V_2 -> V_89 [ V_82 ] ) )
F_35 ( V_2 -> V_89 [ V_82 ] , V_86 + 1 , V_90 ) ;
V_73 += V_2 -> V_37 ;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
unsigned int V_74 )
{
unsigned int V_91 ;
if ( V_2 -> V_92 )
V_74 *= 2 ;
V_91 = V_2 -> V_56 + V_74 ;
if ( V_91 >= V_72 -> V_19 -> V_80 )
V_91 -= V_72 -> V_19 -> V_80 ;
F_37 ( V_2 -> V_56 ) = V_91 ;
V_2 -> V_57 += V_74 ;
if ( V_2 -> V_57 >= V_72 -> V_19 -> V_93 ) {
V_2 -> V_57 -= V_72 -> V_19 -> V_93 ;
V_2 -> V_58 = false ;
F_38 ( & V_2 -> V_12 ) ;
}
}
static void V_13 ( unsigned long V_94 )
{
struct V_1 * V_2 = ( void * ) V_94 ;
struct V_71 * V_72 = F_37 ( V_2 -> V_72 ) ;
if ( V_72 )
F_39 ( V_72 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned int V_95 ,
unsigned int V_96 , bool V_97 )
{
struct V_98 V_99 = { 0 } ;
int V_20 = 0 ;
if ( F_41 ( V_2 -> V_10 ) )
goto V_21;
V_99 . V_100 = F_42 ( V_2 -> V_14 + 1 , V_101 ) ;
V_99 . V_102 = V_103 ;
V_99 . V_95 = V_95 ;
V_99 . V_96 = ( ! V_97 ) ? V_96 : 0 ;
V_99 . V_97 = V_97 ;
V_20 = F_43 ( V_2 -> V_10 , & V_99 , & V_2 -> V_73 . V_104 ,
V_2 -> V_73 . V_105 [ V_2 -> V_14 ] . V_106 ) ;
if ( V_20 < 0 ) {
F_44 ( & V_2 -> V_4 -> V_107 , L_1 , V_20 ) ;
goto V_21;
}
if ( ++ V_2 -> V_14 >= V_108 )
V_2 -> V_14 = 0 ;
V_21:
return V_20 ;
}
static inline int F_45 ( struct V_1 * V_2 ,
unsigned int V_96 , bool V_97 )
{
return F_40 ( V_2 , V_109 ,
V_96 , V_97 ) ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_110 ,
F_17 ( V_2 ) , false ) ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_66 )
{
T_2 * V_73 ;
unsigned int V_60 , V_96 ;
struct V_71 * V_72 ;
if ( V_2 -> V_14 < 0 )
return;
if ( ! ( V_2 -> V_8 & V_24 ) || ( V_66 != V_70 ) )
V_60 = F_22 ( V_2 ) ;
else
V_60 = 0 ;
V_73 = V_2 -> V_73 . V_105 [ V_2 -> V_14 ] . V_73 ;
V_73 [ 0 ] = F_26 ( F_37 ( V_2 -> V_111 ) |
( V_2 -> V_37 << V_112 ) |
V_2 -> V_87 ) ;
V_73 [ 1 ] = F_26 ( V_113 | V_114 | V_115 |
( V_2 -> V_31 << V_116 ) | V_66 ) ;
V_73 += 2 ;
V_72 = F_37 ( V_2 -> V_72 ) ;
if ( V_72 )
V_2 -> V_51 ( V_2 , V_72 , V_73 , V_60 ) ;
else
F_28 ( V_2 , V_73 , V_60 ) ;
if ( V_2 -> V_29 )
F_32 ( V_2 , V_73 , V_60 ) ;
V_2 -> V_87 = ( V_2 -> V_87 + V_60 ) & 0xff ;
V_96 = 8 + V_60 * 4 * V_2 -> V_37 ;
if ( F_45 ( V_2 , V_96 , false ) < 0 ) {
V_2 -> V_14 = - 1 ;
F_48 ( V_2 ) ;
return;
}
if ( V_72 )
F_36 ( V_2 , V_72 , V_60 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
unsigned int V_117 ,
T_2 * V_73 )
{
T_3 V_118 [ 2 ] ;
unsigned int V_60 , V_37 , V_87 ,
V_119 ;
struct V_71 * V_72 = NULL ;
bool V_120 ;
V_118 [ 0 ] = F_27 ( V_73 [ 0 ] ) ;
V_118 [ 1 ] = F_27 ( V_73 [ 1 ] ) ;
if ( ( ( V_118 [ 0 ] & V_121 ) == V_113 ) ||
( ( V_118 [ 1 ] & V_121 ) != V_113 ) ||
( ( V_118 [ 1 ] & V_122 ) != V_114 ) ) {
F_50 ( & V_2 -> V_4 -> V_107 ,
L_2 ,
V_118 [ 0 ] , V_118 [ 1 ] ) ;
goto V_21;
}
if ( V_117 < 3 ||
( ( V_118 [ 1 ] & V_123 ) ==
( V_124 << V_116 ) ) ) {
V_60 = 0 ;
} else {
V_37 =
( V_118 [ 0 ] & V_125 ) >> V_112 ;
if ( V_37 == 0 ) {
F_50 ( & V_2 -> V_4 -> V_107 ,
L_3 ,
V_118 [ 0 ] ) ;
goto V_20;
}
if ( V_2 -> V_8 & V_126 )
V_37 = V_2 -> V_37 ;
V_60 = ( V_117 - 2 ) / V_37 ;
}
V_87 = V_118 [ 0 ] & V_127 ;
if ( V_60 == 0 && ( V_2 -> V_8 & V_128 ) &&
V_2 -> V_87 != V_23 )
V_87 = V_2 -> V_87 ;
if ( ( ( V_2 -> V_8 & V_129 ) && V_87 == 0 ) ||
( V_2 -> V_87 == V_23 ) ) {
V_120 = false ;
} else if ( ! ( V_2 -> V_8 & V_130 ) ) {
V_120 = V_87 != V_2 -> V_87 ;
} else {
if ( ( V_60 > 0 ) && ( V_2 -> V_131 > 0 ) )
V_119 = V_2 -> V_131 ;
else
V_119 = V_60 ;
V_120 = V_87 !=
( ( V_2 -> V_87 + V_119 ) & 0xff ) ;
}
if ( V_120 ) {
F_51 ( & V_2 -> V_4 -> V_107 ,
L_4 ,
V_2 -> V_87 , V_87 ) ;
goto V_20;
}
if ( V_60 > 0 ) {
V_73 += 2 ;
V_72 = F_37 ( V_2 -> V_72 ) ;
if ( V_72 )
V_2 -> V_51 ( V_2 , V_72 , V_73 , V_60 ) ;
if ( V_2 -> V_29 )
F_34 ( V_2 , V_73 , V_60 ) ;
}
if ( V_2 -> V_8 & V_130 )
V_2 -> V_87 = V_87 ;
else
V_2 -> V_87 =
( V_87 + V_60 ) & 0xff ;
V_21:
if ( F_46 ( V_2 ) < 0 )
goto V_20;
if ( V_72 )
F_36 ( V_2 , V_72 , V_60 ) ;
return;
V_20:
V_2 -> V_14 = - 1 ;
F_48 ( V_2 ) ;
}
static void F_52 ( struct V_132 * V_10 , T_3 V_63 ,
T_6 V_95 , void * V_133 ,
void * V_134 )
{
struct V_1 * V_2 = V_134 ;
unsigned int V_30 , V_66 , V_105 = V_95 / 4 ;
V_63 += V_108 - V_105 ;
for ( V_30 = 0 ; V_30 < V_105 ; ++ V_30 ) {
V_66 = F_24 ( V_2 , ++ V_63 ) ;
F_47 ( V_2 , V_66 ) ;
}
F_53 ( V_2 -> V_10 ) ;
}
static void F_54 ( struct V_132 * V_10 , T_3 V_63 ,
T_6 V_95 , void * V_133 ,
void * V_134 )
{
struct V_1 * V_2 = V_134 ;
unsigned int V_99 , V_66 , V_105 , V_117 ;
T_2 * V_73 , * V_135 = V_133 ;
V_105 = V_95 / V_110 ;
for ( V_99 = 0 ; V_99 < V_105 ; V_99 ++ ) {
if ( V_2 -> V_14 < 0 )
break;
V_73 = V_2 -> V_73 . V_105 [ V_2 -> V_14 ] . V_73 ;
if ( V_2 -> V_17 && V_2 -> V_17 -> V_16 ) {
V_66 = F_27 ( V_73 [ 1 ] ) & V_69 ;
F_47 ( V_2 -> V_17 , V_66 ) ;
}
V_117 =
( F_27 ( V_135 [ V_99 ] ) >> V_136 ) / 4 ;
F_49 ( V_2 , V_117 , V_73 ) ;
}
if ( V_2 -> V_14 < 0 ) {
if ( V_2 -> V_17 ) {
V_2 -> V_17 -> V_14 = - 1 ;
F_48 ( V_2 -> V_17 ) ;
}
return;
}
if ( V_2 -> V_17 && V_2 -> V_17 -> V_16 )
F_53 ( V_2 -> V_17 -> V_10 ) ;
F_53 ( V_2 -> V_10 ) ;
}
static void F_55 ( struct V_132 * V_10 , T_3 V_63 ,
T_6 V_95 , void * V_133 ,
void * V_134 )
{
return;
}
static void F_56 ( struct V_132 * V_10 ,
T_3 V_63 , T_6 V_95 ,
void * V_133 , void * V_134 )
{
struct V_1 * V_2 = V_134 ;
V_2 -> V_16 = true ;
F_57 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_9 == V_137 )
V_10 -> V_138 . V_139 = F_54 ;
else if ( ( V_2 -> V_8 & V_24 ) && ( V_2 -> V_8 & V_140 ) )
V_10 -> V_138 . V_139 = F_55 ;
else
V_10 -> V_138 . V_139 = F_52 ;
V_10 -> V_138 . V_139 ( V_10 , V_63 , V_95 , V_133 , V_2 ) ;
}
int F_58 ( struct V_1 * V_2 , int V_141 , int V_142 )
{
static const struct {
unsigned int V_143 ;
unsigned int V_64 ;
} V_144 [] = {
[ V_145 ] = { 4 , 3072 } ,
[ V_146 ] = { 6 , 1024 } ,
[ V_147 ] = { 12 , 1024 } ,
[ V_148 ] = { 24 , 1024 } ,
[ V_62 ] = { 0 , 67 } ,
[ V_149 ] = { 0 , 67 } ,
[ V_150 ] = { 0 , 67 } ,
} ;
unsigned int V_151 ;
enum V_152 V_6 ;
int type , V_102 , V_20 ;
F_59 ( & V_2 -> V_11 ) ;
if ( F_7 ( F_8 ( V_2 ) ||
( V_2 -> V_37 < 1 ) ) ) {
V_20 = - V_153 ;
goto V_154;
}
if ( V_2 -> V_9 == V_137 &&
V_2 -> V_8 & V_155 )
V_2 -> V_87 = V_23 ;
else
V_2 -> V_87 = 0 ;
V_2 -> V_61 = V_144 [ V_2 -> V_31 ] . V_143 ;
V_2 -> V_68 = V_144 [ V_2 -> V_31 ] . V_64 ;
V_2 -> V_67 = V_42 ;
if ( V_2 -> V_9 == V_137 ) {
V_6 = V_156 ;
type = V_157 ;
V_151 = V_110 ;
} else {
V_6 = V_158 ;
type = V_159 ;
V_151 = V_109 ;
}
V_20 = F_60 ( & V_2 -> V_73 , V_2 -> V_4 , V_108 ,
F_17 ( V_2 ) , V_6 ) ;
if ( V_20 < 0 )
goto V_154;
V_2 -> V_10 = F_61 ( F_62 ( V_2 -> V_4 ) -> V_160 ,
type , V_141 , V_142 , V_151 ,
F_56 , V_2 ) ;
if ( F_41 ( V_2 -> V_10 ) ) {
V_20 = F_63 ( V_2 -> V_10 ) ;
if ( V_20 == - V_161 )
F_44 ( & V_2 -> V_4 -> V_107 ,
L_5 ) ;
goto V_162;
}
F_64 ( V_2 ) ;
V_2 -> V_14 = 0 ;
do {
if ( V_2 -> V_9 == V_137 )
V_20 = F_46 ( V_2 ) ;
else
V_20 = F_45 ( V_2 , 0 , true ) ;
if ( V_20 < 0 )
goto V_163;
} while ( V_2 -> V_14 > 0 );
V_102 = V_164 ;
if ( V_2 -> V_8 & V_165 )
V_102 |= V_166 ;
V_2 -> V_16 = false ;
V_20 = F_65 ( V_2 -> V_10 , - 1 , 0 , V_102 ) ;
if ( V_20 < 0 )
goto V_163;
F_66 ( & V_2 -> V_11 ) ;
return 0 ;
V_163:
F_67 ( V_2 -> V_10 ) ;
V_2 -> V_10 = F_2 ( - 1 ) ;
V_162:
F_68 ( & V_2 -> V_73 , V_2 -> V_4 ) ;
V_154:
F_66 ( & V_2 -> V_11 ) ;
return V_20 ;
}
unsigned long F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_58 && F_8 ( V_2 ) )
F_70 ( V_2 -> V_10 ) ;
else
V_2 -> V_58 = true ;
return F_37 ( V_2 -> V_56 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_111 ) =
( F_62 ( V_2 -> V_4 ) -> V_160 -> V_167 & 0x3f ) << 24 ;
}
void F_71 ( struct V_1 * V_2 )
{
F_59 ( & V_2 -> V_11 ) ;
if ( ! F_8 ( V_2 ) ) {
F_66 ( & V_2 -> V_11 ) ;
return;
}
F_21 ( & V_2 -> V_12 ) ;
F_72 ( V_2 -> V_10 ) ;
F_67 ( V_2 -> V_10 ) ;
V_2 -> V_10 = F_2 ( - 1 ) ;
F_68 ( & V_2 -> V_73 , V_2 -> V_4 ) ;
V_2 -> V_16 = false ;
F_66 ( & V_2 -> V_11 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
V_72 = F_37 ( V_2 -> V_72 ) ;
if ( V_72 )
F_73 ( V_72 ) ;
}
