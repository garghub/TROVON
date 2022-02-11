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
unsigned int V_48 = 1 ;
if ( V_2 -> V_8 & V_49 )
V_48 = 5 ;
return 8 + V_2 -> V_38 * V_2 -> V_37 * 4 * V_48 ;
}
void F_18 ( struct V_1 * V_2 ,
T_1 V_50 )
{
if ( F_7 ( F_19 ( V_2 ) ) )
return;
switch ( V_50 ) {
default:
F_7 ( 1 ) ;
case V_51 :
if ( V_2 -> V_9 == V_52 ) {
V_2 -> V_53 = V_54 ;
break;
}
F_7 ( 1 ) ;
case V_55 :
if ( V_2 -> V_9 == V_52 )
V_2 -> V_53 = V_56 ;
else
V_2 -> V_53 = V_57 ;
break;
}
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_12 ) ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_60 = true ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_61 )
{
unsigned int V_62 , V_63 ;
if ( V_2 -> V_8 & V_24 ) {
if ( V_61 == V_64 )
V_63 = 0 ;
else
V_63 = V_2 -> V_38 ;
} else {
if ( ! F_23 ( V_2 -> V_31 ) ) {
V_63 = V_2 -> V_65 ;
} else {
V_62 = V_2 -> V_65 ;
if ( V_2 -> V_31 == V_66 )
V_63 = 5 + ( ( V_62 & 1 ) ^
( V_62 == 0 || V_62 >= 40 ) ) ;
else
V_63 = 11 * ( V_2 -> V_31 >> 1 ) + ( V_62 == 0 ) ;
if ( ++ V_62 >= ( 80 >> ( V_2 -> V_31 >> 1 ) ) )
V_62 = 0 ;
V_2 -> V_65 = V_62 ;
}
}
return V_63 ;
}
static unsigned int F_24 ( struct V_1 * V_2 ,
unsigned int V_67 )
{
unsigned int V_68 , V_62 , V_69 , V_61 ;
if ( V_2 -> V_70 < V_42 ) {
if ( ! F_23 ( V_2 -> V_31 ) )
V_68 = V_2 -> V_70 + V_2 -> V_71 ;
else {
V_62 = V_2 -> V_71 ;
V_69 = V_62 % 13 ;
V_68 = V_2 -> V_70 ;
V_68 += 1386 + ( ( V_69 && ! ( V_69 & 3 ) ) ||
V_62 == 146 ) ;
if ( ++ V_62 >= 147 )
V_62 = 0 ;
V_2 -> V_71 = V_62 ;
}
} else
V_68 = V_2 -> V_70 - V_42 ;
V_2 -> V_70 = V_68 ;
if ( V_68 < V_42 ) {
V_68 += V_2 -> V_40 ;
V_61 = ( V_67 + V_68 / V_42 ) << 12 ;
V_61 += V_68 % V_42 ;
return V_61 & V_72 ;
} else {
return V_64 ;
}
}
static void V_56 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
T_2 * V_75 , unsigned int V_76 )
{
struct V_18 * V_19 = V_74 -> V_19 ;
unsigned int V_77 , V_78 , V_30 , V_79 ;
const T_3 * V_80 ;
V_77 = V_2 -> V_28 ;
V_80 = ( void * ) V_19 -> V_81 +
F_25 ( V_19 , V_2 -> V_58 ) ;
V_78 = V_19 -> V_82 - V_2 -> V_58 ;
for ( V_30 = 0 ; V_30 < V_76 ; ++ V_30 ) {
for ( V_79 = 0 ; V_79 < V_77 ; ++ V_79 ) {
V_75 [ V_2 -> V_44 [ V_79 ] ] =
F_26 ( ( * V_80 >> 8 ) | 0x40000000 ) ;
V_80 ++ ;
}
V_75 += V_2 -> V_37 ;
if ( -- V_78 == 0 )
V_80 = ( void * ) V_19 -> V_81 ;
}
}
static void V_54 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
T_2 * V_75 , unsigned int V_76 )
{
struct V_18 * V_19 = V_74 -> V_19 ;
unsigned int V_77 , V_78 , V_30 , V_79 ;
const T_4 * V_80 ;
V_77 = V_2 -> V_28 ;
V_80 = ( void * ) V_19 -> V_81 +
F_25 ( V_19 , V_2 -> V_58 ) ;
V_78 = V_19 -> V_82 - V_2 -> V_58 ;
for ( V_30 = 0 ; V_30 < V_76 ; ++ V_30 ) {
for ( V_79 = 0 ; V_79 < V_77 ; ++ V_79 ) {
V_75 [ V_2 -> V_44 [ V_79 ] ] =
F_26 ( ( * V_80 << 8 ) | 0x42000000 ) ;
V_80 ++ ;
}
V_75 += V_2 -> V_37 ;
if ( -- V_78 == 0 )
V_80 = ( void * ) V_19 -> V_81 ;
}
}
static void V_57 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
T_2 * V_75 , unsigned int V_76 )
{
struct V_18 * V_19 = V_74 -> V_19 ;
unsigned int V_77 , V_78 , V_30 , V_79 ;
T_3 * V_83 ;
V_77 = V_2 -> V_28 ;
V_83 = ( void * ) V_19 -> V_81 +
F_25 ( V_19 , V_2 -> V_58 ) ;
V_78 = V_19 -> V_82 - V_2 -> V_58 ;
for ( V_30 = 0 ; V_30 < V_76 ; ++ V_30 ) {
for ( V_79 = 0 ; V_79 < V_77 ; ++ V_79 ) {
* V_83 = F_27 ( V_75 [ V_2 -> V_44 [ V_79 ] ] ) << 8 ;
V_83 ++ ;
}
V_75 += V_2 -> V_37 ;
if ( -- V_78 == 0 )
V_83 = ( void * ) V_19 -> V_81 ;
}
}
static void F_28 ( struct V_1 * V_2 ,
T_2 * V_75 , unsigned int V_76 )
{
unsigned int V_30 , V_79 ;
for ( V_30 = 0 ; V_30 < V_76 ; ++ V_30 ) {
for ( V_79 = 0 ; V_79 < V_2 -> V_28 ; ++ V_79 )
V_75 [ V_2 -> V_44 [ V_79 ] ] = F_26 ( 0x40000000 ) ;
V_75 += V_2 -> V_37 ;
}
}
static bool F_29 ( struct V_1 * V_2 , unsigned int V_84 )
{
int V_85 ;
V_85 = V_2 -> V_86 [ V_84 ] ;
if ( V_85 == 0 )
return true ;
V_85 -= V_47 * V_2 -> V_38 ;
V_85 = F_30 ( V_85 , 0 ) ;
V_2 -> V_86 [ V_84 ] = V_85 ;
return V_85 < V_2 -> V_46 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_84 )
{
V_2 -> V_86 [ V_84 ] += V_35 [ V_2 -> V_31 ] ;
}
static void F_32 ( struct V_1 * V_2 ,
T_2 * V_75 , unsigned int V_76 )
{
unsigned int V_87 , V_84 ;
T_5 * V_88 ;
for ( V_87 = 0 ; V_87 < V_76 ; V_87 ++ ) {
V_88 = ( T_5 * ) & V_75 [ V_2 -> V_45 ] ;
V_84 = ( V_2 -> V_89 + V_87 ) % 8 ;
if ( V_87 < V_90 &&
F_29 ( V_2 , V_84 ) &&
V_2 -> V_91 [ V_84 ] != NULL &&
F_33 ( V_2 -> V_91 [ V_84 ] , & V_88 [ 1 ] , 1 ) == 1 ) {
F_31 ( V_2 , V_84 ) ;
V_88 [ 0 ] = 0x81 ;
} else {
V_88 [ 0 ] = 0x80 ;
V_88 [ 1 ] = 0 ;
}
V_88 [ 2 ] = 0 ;
V_88 [ 3 ] = 0 ;
V_75 += V_2 -> V_37 ;
}
}
static void F_34 ( struct V_1 * V_2 ,
T_2 * V_75 , unsigned int V_76 )
{
unsigned int V_87 , V_84 ;
int V_92 ;
T_5 * V_88 ;
for ( V_87 = 0 ; V_87 < V_76 ; V_87 ++ ) {
V_84 = ( V_2 -> V_89 + V_87 ) % 8 ;
V_88 = ( T_5 * ) & V_75 [ V_2 -> V_45 ] ;
V_92 = V_88 [ 0 ] - 0x80 ;
if ( ( 1 <= V_92 ) && ( V_92 <= 3 ) && ( V_2 -> V_91 [ V_84 ] ) )
F_35 ( V_2 -> V_91 [ V_84 ] , V_88 + 1 , V_92 ) ;
V_75 += V_2 -> V_37 ;
}
}
static void F_36 ( struct V_1 * V_2 ,
struct V_73 * V_74 ,
unsigned int V_76 )
{
unsigned int V_93 ;
if ( V_2 -> V_94 )
V_76 *= 2 ;
V_93 = V_2 -> V_58 + V_76 ;
if ( V_93 >= V_74 -> V_19 -> V_82 )
V_93 -= V_74 -> V_19 -> V_82 ;
F_37 ( V_2 -> V_58 ) = V_93 ;
V_2 -> V_59 += V_76 ;
if ( V_2 -> V_59 >= V_74 -> V_19 -> V_95 ) {
V_2 -> V_59 -= V_74 -> V_19 -> V_95 ;
V_2 -> V_60 = false ;
F_38 ( & V_2 -> V_12 ) ;
}
}
static void V_13 ( unsigned long V_96 )
{
struct V_1 * V_2 = ( void * ) V_96 ;
struct V_73 * V_74 = F_37 ( V_2 -> V_74 ) ;
if ( V_74 )
F_39 ( V_74 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned int V_97 ,
unsigned int V_98 , bool V_99 )
{
struct V_100 V_101 = { 0 } ;
int V_20 = 0 ;
if ( F_41 ( V_2 -> V_10 ) )
goto V_21;
V_101 . V_102 = F_42 ( V_2 -> V_14 + 1 , V_103 ) ;
V_101 . V_104 = V_105 ;
V_101 . V_97 = V_97 ;
V_101 . V_98 = ( ! V_99 ) ? V_98 : 0 ;
V_101 . V_99 = V_99 ;
V_20 = F_43 ( V_2 -> V_10 , & V_101 , & V_2 -> V_75 . V_106 ,
V_2 -> V_75 . V_107 [ V_2 -> V_14 ] . V_108 ) ;
if ( V_20 < 0 ) {
F_44 ( & V_2 -> V_4 -> V_109 , L_1 , V_20 ) ;
goto V_21;
}
if ( ++ V_2 -> V_14 >= V_110 )
V_2 -> V_14 = 0 ;
V_21:
return V_20 ;
}
static inline int F_45 ( struct V_1 * V_2 ,
unsigned int V_98 , bool V_99 )
{
return F_40 ( V_2 , V_111 ,
V_98 , V_99 ) ;
}
static inline int F_46 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_112 ,
F_17 ( V_2 ) , false ) ;
}
static int F_47 ( struct V_1 * V_2 , unsigned int V_63 ,
unsigned int V_61 )
{
T_2 * V_75 ;
unsigned int V_98 ;
struct V_73 * V_74 ;
V_75 = V_2 -> V_75 . V_107 [ V_2 -> V_14 ] . V_75 ;
V_75 [ 0 ] = F_26 ( F_37 ( V_2 -> V_113 ) |
( V_2 -> V_37 << V_114 ) |
V_2 -> V_89 ) ;
V_75 [ 1 ] = F_26 ( V_115 | V_116 | V_117 |
( V_2 -> V_31 << V_118 ) | V_61 ) ;
V_75 += 2 ;
V_74 = F_37 ( V_2 -> V_74 ) ;
if ( V_74 )
V_2 -> V_53 ( V_2 , V_74 , V_75 , V_63 ) ;
else
F_28 ( V_2 , V_75 , V_63 ) ;
if ( V_2 -> V_29 )
F_32 ( V_2 , V_75 , V_63 ) ;
V_2 -> V_89 = ( V_2 -> V_89 + V_63 ) & 0xff ;
V_98 = 8 + V_63 * 4 * V_2 -> V_37 ;
if ( F_45 ( V_2 , V_98 , false ) < 0 )
return - V_119 ;
if ( V_74 )
F_36 ( V_2 , V_74 , V_63 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned int V_120 , T_2 * V_75 ,
unsigned int * V_63 )
{
T_3 V_121 [ 2 ] ;
unsigned int V_37 , V_89 , V_122 ;
struct V_73 * V_74 = NULL ;
bool V_123 ;
V_121 [ 0 ] = F_27 ( V_75 [ 0 ] ) ;
V_121 [ 1 ] = F_27 ( V_75 [ 1 ] ) ;
if ( ( ( V_121 [ 0 ] & V_124 ) == V_115 ) ||
( ( V_121 [ 1 ] & V_124 ) != V_115 ) ||
( ( V_121 [ 1 ] & V_125 ) != V_116 ) ) {
F_49 ( & V_2 -> V_4 -> V_109 ,
L_2 ,
V_121 [ 0 ] , V_121 [ 1 ] ) ;
* V_63 = 0 ;
goto V_21;
}
if ( V_120 < 3 ||
( ( V_121 [ 1 ] & V_126 ) ==
( V_127 << V_118 ) ) ) {
* V_63 = 0 ;
} else {
V_37 =
( V_121 [ 0 ] & V_128 ) >> V_114 ;
if ( V_37 == 0 ) {
F_44 ( & V_2 -> V_4 -> V_109 ,
L_3 ,
V_121 [ 0 ] ) ;
return - V_129 ;
}
if ( V_2 -> V_8 & V_130 )
V_37 = V_2 -> V_37 ;
* V_63 = ( V_120 - 2 ) / V_37 ;
}
V_89 = V_121 [ 0 ] & V_131 ;
if ( * V_63 == 0 && ( V_2 -> V_8 & V_132 ) &&
V_2 -> V_89 != V_23 )
V_89 = V_2 -> V_89 ;
if ( ( ( V_2 -> V_8 & V_133 ) &&
V_89 == V_2 -> V_134 ) ||
V_2 -> V_89 == V_23 ) {
V_123 = false ;
} else if ( ! ( V_2 -> V_8 & V_135 ) ) {
V_123 = V_89 != V_2 -> V_89 ;
} else {
if ( ( * V_63 > 0 ) && ( V_2 -> V_136 > 0 ) )
V_122 = V_2 -> V_136 ;
else
V_122 = * V_63 ;
V_123 = V_89 !=
( ( V_2 -> V_89 + V_122 ) & 0xff ) ;
}
if ( V_123 ) {
F_44 ( & V_2 -> V_4 -> V_109 ,
L_4 ,
V_2 -> V_89 , V_89 ) ;
return - V_119 ;
}
if ( * V_63 > 0 ) {
V_75 += 2 ;
V_74 = F_37 ( V_2 -> V_74 ) ;
if ( V_74 )
V_2 -> V_53 ( V_2 , V_74 , V_75 , * V_63 ) ;
if ( V_2 -> V_29 )
F_34 ( V_2 , V_75 , * V_63 ) ;
}
if ( V_2 -> V_8 & V_135 )
V_2 -> V_89 = V_89 ;
else
V_2 -> V_89 =
( V_89 + * V_63 ) & 0xff ;
V_21:
if ( F_46 ( V_2 ) < 0 )
return - V_119 ;
if ( V_74 )
F_36 ( V_2 , V_74 , * V_63 ) ;
return 0 ;
}
static void F_50 ( struct V_137 * V_10 , T_3 V_67 ,
T_6 V_97 , void * V_138 ,
void * V_139 )
{
struct V_1 * V_2 = V_139 ;
unsigned int V_30 , V_61 , V_107 = V_97 / 4 ;
unsigned int V_63 ;
if ( V_2 -> V_14 < 0 )
return;
V_67 += V_110 - V_107 ;
for ( V_30 = 0 ; V_30 < V_107 ; ++ V_30 ) {
V_61 = F_24 ( V_2 , ++ V_67 ) ;
V_63 = F_22 ( V_2 , V_61 ) ;
if ( F_47 ( V_2 , V_63 , V_61 ) < 0 ) {
V_2 -> V_14 = - 1 ;
F_51 ( V_2 ) ;
return;
}
}
F_52 ( V_2 -> V_10 ) ;
}
static void F_53 ( struct V_137 * V_10 , T_3 V_67 ,
T_6 V_97 , void * V_138 ,
void * V_139 )
{
struct V_1 * V_2 = V_139 ;
unsigned int V_101 , V_61 , V_107 ;
unsigned int V_120 , V_140 ;
unsigned int V_63 ;
T_2 * V_75 , * V_141 = V_138 ;
if ( V_2 -> V_14 < 0 )
return;
V_107 = V_97 / V_112 ;
V_140 = F_17 ( V_2 ) / 4 ;
for ( V_101 = 0 ; V_101 < V_107 ; V_101 ++ ) {
V_75 = V_2 -> V_75 . V_107 [ V_2 -> V_14 ] . V_75 ;
V_120 =
( F_27 ( V_141 [ V_101 ] ) >> V_142 ) / 4 ;
if ( V_120 > V_140 ) {
F_44 ( & V_2 -> V_4 -> V_109 ,
L_5 ,
V_120 , V_140 ) ;
V_2 -> V_14 = - 1 ;
break;
}
if ( F_48 ( V_2 , V_120 , V_75 ,
& V_63 ) < 0 ) {
V_2 -> V_14 = - 1 ;
break;
}
if ( V_2 -> V_17 && V_2 -> V_17 -> V_16 ) {
V_61 = F_27 ( V_75 [ 1 ] ) & V_72 ;
if ( F_47 ( V_2 -> V_17 ,
V_63 , V_61 ) < 0 ) {
V_2 -> V_14 = - 1 ;
break;
}
}
}
if ( V_2 -> V_14 < 0 ) {
F_51 ( V_2 ) ;
if ( V_2 -> V_17 ) {
V_2 -> V_17 -> V_14 = - 1 ;
F_51 ( V_2 -> V_17 ) ;
}
return;
}
if ( V_2 -> V_17 && V_2 -> V_17 -> V_16 )
F_52 ( V_2 -> V_17 -> V_10 ) ;
F_52 ( V_2 -> V_10 ) ;
}
static void F_54 ( struct V_137 * V_10 , T_3 V_67 ,
T_6 V_97 , void * V_138 ,
void * V_139 )
{
return;
}
static void F_55 ( struct V_137 * V_10 ,
T_3 V_67 , T_6 V_97 ,
void * V_138 , void * V_139 )
{
struct V_1 * V_2 = V_139 ;
V_2 -> V_16 = true ;
F_56 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_9 == V_143 )
V_10 -> V_144 . V_145 = F_53 ;
else if ( V_2 -> V_8 & V_146 )
V_10 -> V_144 . V_145 = F_54 ;
else
V_10 -> V_144 . V_145 = F_50 ;
V_10 -> V_144 . V_145 ( V_10 , V_67 , V_97 , V_138 , V_2 ) ;
}
int F_57 ( struct V_1 * V_2 , int V_147 , int V_148 )
{
static const struct {
unsigned int V_149 ;
unsigned int V_68 ;
} V_150 [] = {
[ V_151 ] = { 4 , 3072 } ,
[ V_152 ] = { 6 , 1024 } ,
[ V_153 ] = { 12 , 1024 } ,
[ V_154 ] = { 24 , 1024 } ,
[ V_66 ] = { 0 , 67 } ,
[ V_155 ] = { 0 , 67 } ,
[ V_156 ] = { 0 , 67 } ,
} ;
unsigned int V_157 ;
enum V_158 V_6 ;
int type , V_104 , V_20 ;
F_58 ( & V_2 -> V_11 ) ;
if ( F_7 ( F_8 ( V_2 ) ||
( V_2 -> V_37 < 1 ) ) ) {
V_20 = - V_159 ;
goto V_160;
}
if ( V_2 -> V_9 == V_143 &&
V_2 -> V_8 & V_161 )
V_2 -> V_89 = V_23 ;
else
V_2 -> V_89 = 0 ;
V_2 -> V_65 = V_150 [ V_2 -> V_31 ] . V_149 ;
V_2 -> V_71 = V_150 [ V_2 -> V_31 ] . V_68 ;
V_2 -> V_70 = V_42 ;
if ( V_2 -> V_9 == V_143 ) {
V_6 = V_162 ;
type = V_163 ;
V_157 = V_112 ;
} else {
V_6 = V_164 ;
type = V_165 ;
V_157 = V_111 ;
}
V_20 = F_59 ( & V_2 -> V_75 , V_2 -> V_4 , V_110 ,
F_17 ( V_2 ) , V_6 ) ;
if ( V_20 < 0 )
goto V_160;
V_2 -> V_10 = F_60 ( F_61 ( V_2 -> V_4 ) -> V_166 ,
type , V_147 , V_148 , V_157 ,
F_55 , V_2 ) ;
if ( F_41 ( V_2 -> V_10 ) ) {
V_20 = F_62 ( V_2 -> V_10 ) ;
if ( V_20 == - V_167 )
F_44 ( & V_2 -> V_4 -> V_109 ,
L_6 ) ;
goto V_168;
}
F_63 ( V_2 ) ;
V_2 -> V_14 = 0 ;
do {
if ( V_2 -> V_9 == V_143 )
V_20 = F_46 ( V_2 ) ;
else
V_20 = F_45 ( V_2 , 0 , true ) ;
if ( V_20 < 0 )
goto V_169;
} while ( V_2 -> V_14 > 0 );
V_104 = V_170 ;
if ( V_2 -> V_8 & V_171 )
V_104 |= V_172 ;
V_2 -> V_16 = false ;
V_20 = F_64 ( V_2 -> V_10 , - 1 , 0 , V_104 ) ;
if ( V_20 < 0 )
goto V_169;
F_65 ( & V_2 -> V_11 ) ;
return 0 ;
V_169:
F_66 ( V_2 -> V_10 ) ;
V_2 -> V_10 = F_2 ( - 1 ) ;
V_168:
F_67 ( & V_2 -> V_75 , V_2 -> V_4 ) ;
V_160:
F_65 ( & V_2 -> V_11 ) ;
return V_20 ;
}
unsigned long F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 && F_8 ( V_2 ) )
F_69 ( V_2 -> V_10 ) ;
else
V_2 -> V_60 = true ;
return F_37 ( V_2 -> V_58 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_113 ) =
( F_61 ( V_2 -> V_4 ) -> V_166 -> V_173 << V_174 ) &
V_175 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_11 ) ;
if ( ! F_8 ( V_2 ) ) {
F_65 ( & V_2 -> V_11 ) ;
return;
}
F_21 ( & V_2 -> V_12 ) ;
F_71 ( V_2 -> V_10 ) ;
F_66 ( V_2 -> V_10 ) ;
V_2 -> V_10 = F_2 ( - 1 ) ;
F_67 ( & V_2 -> V_75 , V_2 -> V_4 ) ;
V_2 -> V_16 = false ;
F_65 ( & V_2 -> V_11 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_73 * V_74 ;
V_74 = F_37 ( V_2 -> V_74 ) ;
if ( V_74 )
F_72 ( V_74 ) ;
}
