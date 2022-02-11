int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 , enum V_7 V_8 )
{
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> V_9 = V_6 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_10 = F_3 ( - 1 ) ;
F_4 ( & V_2 -> V_11 ) ;
F_5 ( & V_2 -> V_12 , V_13 , ( unsigned long ) V_2 ) ;
V_2 -> V_14 = 0 ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_16 = false ;
V_2 -> V_17 = NULL ;
V_2 -> V_18 = V_19 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( F_9 ( V_2 ) ) ;
F_10 ( & V_2 -> V_11 ) ;
F_11 ( V_2 -> V_4 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_22 ;
V_22 = F_13 ( V_21 , 0 , 32 , 24 ) ;
if ( V_22 < 0 )
goto V_23;
V_22 = F_14 ( V_21 ,
V_24 ,
5000 , V_19 ) ;
if ( V_22 < 0 )
goto V_23;
if ( ! ( V_2 -> V_8 & V_25 ) )
goto V_23;
V_22 = F_15 ( V_21 , 0 ,
V_26 , 32 ) ;
if ( V_22 < 0 )
goto V_23;
V_22 = F_15 ( V_21 , 0 ,
V_27 , 32 ) ;
V_23:
return V_22 ;
}
void F_16 ( struct V_1 * V_2 ,
unsigned int V_28 ,
unsigned int V_29 ,
unsigned int V_30 )
{
unsigned int V_31 , V_32 , V_33 ;
V_33 = F_17 ( V_30 , 8 ) ;
if ( F_8 ( F_9 ( V_2 ) ) |
F_8 ( V_29 > V_34 ) |
F_8 ( V_33 > V_35 ) )
return;
for ( V_32 = 0 ; V_32 < F_18 ( V_36 ) ; ++ V_32 )
if ( V_36 [ V_32 ] == V_28 )
goto V_37;
F_8 ( 1 ) ;
return;
V_37:
V_2 -> V_29 = V_29 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_38 = V_2 -> V_29 + V_33 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_39 = V_40 [ V_32 ] ;
V_2 -> V_41 = V_42 - V_43 ;
if ( V_2 -> V_8 & V_25 )
V_2 -> V_41 += V_44 * V_2 -> V_39 / V_28 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ )
V_2 -> V_45 [ V_31 ] = V_31 ;
V_2 -> V_46 = V_2 -> V_29 ;
}
unsigned int F_19 ( struct V_1 * V_2 )
{
return 8 + V_2 -> V_39 * V_2 -> V_38 * 4 ;
}
void F_20 ( struct V_1 * V_2 ,
T_1 V_47 )
{
if ( F_8 ( F_21 ( V_2 ) ) )
return;
switch ( V_47 ) {
default:
F_8 ( 1 ) ;
case V_48 :
if ( V_2 -> V_9 == V_49 ) {
V_2 -> V_50 = V_51 ;
break;
}
F_8 ( 1 ) ;
case V_52 :
if ( V_2 -> V_9 == V_49 )
V_2 -> V_50 = V_53 ;
else
V_2 -> V_50 = V_54 ;
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_12 ) ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
V_2 -> V_57 = true ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
unsigned int V_58 , V_59 ;
if ( V_2 -> V_8 & V_25 )
V_59 = V_2 -> V_39 ;
else if ( ! F_25 ( V_2 -> V_32 ) ) {
V_59 = V_2 -> V_60 ;
} else {
V_58 = V_2 -> V_60 ;
if ( V_2 -> V_32 == V_61 )
V_59 = 5 + ( ( V_58 & 1 ) ^
( V_58 == 0 || V_58 >= 40 ) ) ;
else
V_59 = 11 * ( V_2 -> V_32 >> 1 ) + ( V_58 == 0 ) ;
if ( ++ V_58 >= ( 80 >> ( V_2 -> V_32 >> 1 ) ) )
V_58 = 0 ;
V_2 -> V_60 = V_58 ;
}
return V_59 ;
}
static unsigned int F_26 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
unsigned int V_63 , V_58 , V_64 , V_65 ;
if ( V_2 -> V_66 < V_43 ) {
if ( ! F_25 ( V_2 -> V_32 ) )
V_63 = V_2 -> V_66 + V_2 -> V_67 ;
else {
V_58 = V_2 -> V_67 ;
V_64 = V_58 % 13 ;
V_63 = V_2 -> V_66 ;
V_63 += 1386 + ( ( V_64 && ! ( V_64 & 3 ) ) ||
V_58 == 146 ) ;
if ( ++ V_58 >= 147 )
V_58 = 0 ;
V_2 -> V_67 = V_58 ;
}
} else
V_63 = V_2 -> V_66 - V_43 ;
V_2 -> V_66 = V_63 ;
if ( V_63 < V_43 ) {
V_63 += V_2 -> V_41 ;
V_65 = ( V_62 + V_63 / V_43 ) << 12 ;
V_65 += V_63 % V_43 ;
return V_65 & V_68 ;
} else {
return V_69 ;
}
}
static void V_53 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 * V_72 , unsigned int V_73 )
{
struct V_20 * V_21 = V_71 -> V_21 ;
unsigned int V_74 , V_75 , V_31 , V_76 ;
const T_3 * V_77 ;
V_74 = V_2 -> V_29 ;
V_77 = ( void * ) V_21 -> V_78 +
F_27 ( V_21 , V_2 -> V_55 ) ;
V_75 = V_21 -> V_79 - V_2 -> V_55 ;
for ( V_31 = 0 ; V_31 < V_73 ; ++ V_31 ) {
for ( V_76 = 0 ; V_76 < V_74 ; ++ V_76 ) {
V_72 [ V_2 -> V_45 [ V_76 ] ] =
F_28 ( ( * V_77 >> 8 ) | 0x40000000 ) ;
V_77 ++ ;
}
V_72 += V_2 -> V_38 ;
if ( -- V_75 == 0 )
V_77 = ( void * ) V_21 -> V_78 ;
}
}
static void V_51 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 * V_72 , unsigned int V_73 )
{
struct V_20 * V_21 = V_71 -> V_21 ;
unsigned int V_74 , V_75 , V_31 , V_76 ;
const T_4 * V_77 ;
V_74 = V_2 -> V_29 ;
V_77 = ( void * ) V_21 -> V_78 +
F_27 ( V_21 , V_2 -> V_55 ) ;
V_75 = V_21 -> V_79 - V_2 -> V_55 ;
for ( V_31 = 0 ; V_31 < V_73 ; ++ V_31 ) {
for ( V_76 = 0 ; V_76 < V_74 ; ++ V_76 ) {
V_72 [ V_2 -> V_45 [ V_76 ] ] =
F_28 ( ( * V_77 << 8 ) | 0x42000000 ) ;
V_77 ++ ;
}
V_72 += V_2 -> V_38 ;
if ( -- V_75 == 0 )
V_77 = ( void * ) V_21 -> V_78 ;
}
}
static void V_54 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 * V_72 , unsigned int V_73 )
{
struct V_20 * V_21 = V_71 -> V_21 ;
unsigned int V_74 , V_75 , V_31 , V_76 ;
T_3 * V_80 ;
V_74 = V_2 -> V_29 ;
V_80 = ( void * ) V_21 -> V_78 +
F_27 ( V_21 , V_2 -> V_55 ) ;
V_75 = V_21 -> V_79 - V_2 -> V_55 ;
for ( V_31 = 0 ; V_31 < V_73 ; ++ V_31 ) {
for ( V_76 = 0 ; V_76 < V_74 ; ++ V_76 ) {
* V_80 = F_29 ( V_72 [ V_2 -> V_45 [ V_76 ] ] ) << 8 ;
V_80 ++ ;
}
V_72 += V_2 -> V_38 ;
if ( -- V_75 == 0 )
V_80 = ( void * ) V_21 -> V_78 ;
}
}
static void F_30 ( struct V_1 * V_2 ,
T_2 * V_72 , unsigned int V_73 )
{
unsigned int V_31 , V_76 ;
for ( V_31 = 0 ; V_31 < V_73 ; ++ V_31 ) {
for ( V_76 = 0 ; V_76 < V_2 -> V_29 ; ++ V_76 )
V_72 [ V_2 -> V_45 [ V_76 ] ] = F_28 ( 0x40000000 ) ;
V_72 += V_2 -> V_38 ;
}
}
static void F_31 ( struct V_1 * V_2 ,
T_2 * V_72 , unsigned int V_73 )
{
unsigned int V_81 , V_82 ;
T_5 * V_83 ;
for ( V_81 = 0 ; V_81 < V_73 ; V_81 ++ ) {
V_72 [ V_2 -> V_46 ] = 0 ;
V_83 = ( T_5 * ) & V_72 [ V_2 -> V_46 ] ;
V_82 = ( V_2 -> V_84 + V_81 ) % 8 ;
if ( ( V_81 >= V_2 -> V_18 ) ||
( V_2 -> V_85 [ V_82 ] == NULL ) ||
( F_32 ( V_2 -> V_85 [ V_82 ] , V_83 + 1 , 1 ) <= 0 ) )
V_83 [ 0 ] = 0x80 ;
else
V_83 [ 0 ] = 0x81 ;
V_72 += V_2 -> V_38 ;
}
}
static void F_33 ( struct V_1 * V_2 ,
T_2 * V_72 , unsigned int V_73 )
{
unsigned int V_81 , V_82 ;
int V_86 ;
T_5 * V_83 ;
for ( V_81 = 0 ; V_81 < V_73 ; V_81 ++ ) {
V_82 = ( V_2 -> V_84 + V_81 ) % 8 ;
V_83 = ( T_5 * ) & V_72 [ V_2 -> V_46 ] ;
V_86 = V_83 [ 0 ] - 0x80 ;
if ( ( 1 <= V_86 ) && ( V_86 <= 3 ) && ( V_2 -> V_85 [ V_82 ] ) )
F_34 ( V_2 -> V_85 [ V_82 ] , V_83 + 1 , V_86 ) ;
V_72 += V_2 -> V_38 ;
}
}
static void F_35 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
unsigned int V_73 )
{ unsigned int V_87 ;
V_87 = V_2 -> V_55 + V_73 ;
if ( V_87 >= V_71 -> V_21 -> V_79 )
V_87 -= V_71 -> V_21 -> V_79 ;
F_36 ( V_2 -> V_55 ) = V_87 ;
V_2 -> V_56 += V_73 ;
if ( V_2 -> V_56 >= V_71 -> V_21 -> V_88 ) {
V_2 -> V_56 -= V_71 -> V_21 -> V_88 ;
V_2 -> V_57 = false ;
F_37 ( & V_2 -> V_12 ) ;
}
}
static void V_13 ( unsigned long V_89 )
{
struct V_1 * V_2 = ( void * ) V_89 ;
struct V_70 * V_71 = F_36 ( V_2 -> V_71 ) ;
if ( V_71 )
F_38 ( V_71 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned int V_90 ,
unsigned int V_91 , bool V_92 )
{
struct V_93 V_94 = { 0 } ;
int V_22 = 0 ;
if ( F_40 ( V_2 -> V_10 ) )
goto V_23;
V_94 . V_95 = F_41 ( V_2 -> V_14 + 1 , V_96 ) ;
V_94 . V_97 = V_98 ;
V_94 . V_90 = V_90 ;
V_94 . V_91 = ( ! V_92 ) ? V_91 : 0 ;
V_94 . V_92 = V_92 ;
V_22 = F_42 ( V_2 -> V_10 , & V_94 , & V_2 -> V_72 . V_99 ,
V_2 -> V_72 . V_100 [ V_2 -> V_14 ] . V_101 ) ;
if ( V_22 < 0 ) {
F_43 ( & V_2 -> V_4 -> V_102 , L_1 , V_22 ) ;
goto V_23;
}
if ( ++ V_2 -> V_14 >= V_103 )
V_2 -> V_14 = 0 ;
V_23:
return V_22 ;
}
static inline int F_44 ( struct V_1 * V_2 ,
unsigned int V_91 , bool V_92 )
{
return F_39 ( V_2 , V_104 ,
V_91 , V_92 ) ;
}
static inline int F_45 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_105 ,
F_19 ( V_2 ) , false ) ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_65 )
{
T_2 * V_72 ;
unsigned int V_59 , V_91 ;
struct V_70 * V_71 ;
if ( V_2 -> V_14 < 0 )
return;
if ( ! ( V_2 -> V_8 & V_25 ) || ( V_65 != V_69 ) )
V_59 = F_24 ( V_2 ) ;
else
V_59 = 0 ;
V_72 = V_2 -> V_72 . V_100 [ V_2 -> V_14 ] . V_72 ;
V_72 [ 0 ] = F_28 ( F_36 ( V_2 -> V_106 ) |
( V_2 -> V_38 << V_107 ) |
V_2 -> V_84 ) ;
V_72 [ 1 ] = F_28 ( V_108 | V_109 | V_110 |
( V_2 -> V_32 << V_111 ) | V_65 ) ;
V_72 += 2 ;
V_71 = F_36 ( V_2 -> V_71 ) ;
if ( V_71 )
V_2 -> V_50 ( V_2 , V_71 , V_72 , V_59 ) ;
else
F_30 ( V_2 , V_72 , V_59 ) ;
if ( V_2 -> V_30 )
F_31 ( V_2 , V_72 , V_59 ) ;
V_2 -> V_84 = ( V_2 -> V_84 + V_59 ) & 0xff ;
V_91 = 8 + V_59 * 4 * V_2 -> V_38 ;
if ( F_44 ( V_2 , V_91 , false ) < 0 ) {
V_2 -> V_14 = - 1 ;
F_47 ( V_2 ) ;
return;
}
if ( V_71 )
F_35 ( V_2 , V_71 , V_59 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
unsigned int V_112 ,
T_2 * V_72 )
{
T_3 V_113 [ 2 ] ;
unsigned int V_59 , V_38 , V_84 ,
V_114 ;
struct V_70 * V_71 = NULL ;
bool V_115 ;
V_113 [ 0 ] = F_29 ( V_72 [ 0 ] ) ;
V_113 [ 1 ] = F_29 ( V_72 [ 1 ] ) ;
if ( ( ( V_113 [ 0 ] & V_116 ) == V_108 ) ||
( ( V_113 [ 1 ] & V_116 ) != V_108 ) ||
( ( V_113 [ 1 ] & V_117 ) != V_109 ) ) {
F_49 ( & V_2 -> V_4 -> V_102 ,
L_2 ,
V_113 [ 0 ] , V_113 [ 1 ] ) ;
goto V_23;
}
if ( V_112 < 3 ||
( ( V_113 [ 1 ] & V_118 ) ==
( V_119 << V_111 ) ) ) {
V_59 = 0 ;
} else {
V_38 =
( V_113 [ 0 ] & V_120 ) >> V_107 ;
if ( V_38 == 0 ) {
F_49 ( & V_2 -> V_4 -> V_102 ,
L_3 ,
V_113 [ 0 ] ) ;
goto V_22;
}
if ( V_2 -> V_8 & V_121 )
V_38 = V_2 -> V_38 ;
V_59 = ( V_112 - 2 ) / V_38 ;
}
V_84 = V_113 [ 0 ] & V_122 ;
if ( V_59 == 0 && ( V_2 -> V_8 & V_123 ) &&
V_2 -> V_84 != V_19 )
V_84 = V_2 -> V_84 ;
if ( ( ( V_2 -> V_8 & V_124 ) && V_84 == 0 ) ||
( V_2 -> V_84 == V_19 ) ) {
V_115 = false ;
} else if ( ! ( V_2 -> V_8 & V_125 ) ) {
V_115 = V_84 != V_2 -> V_84 ;
} else {
if ( ( V_59 > 0 ) && ( V_2 -> V_126 > 0 ) )
V_114 = V_2 -> V_126 ;
else
V_114 = V_59 ;
V_115 = V_84 !=
( ( V_2 -> V_84 + V_114 ) & 0xff ) ;
}
if ( V_115 ) {
F_50 ( & V_2 -> V_4 -> V_102 ,
L_4 ,
V_2 -> V_84 , V_84 ) ;
goto V_22;
}
if ( V_59 > 0 ) {
V_72 += 2 ;
V_71 = F_36 ( V_2 -> V_71 ) ;
if ( V_71 )
V_2 -> V_50 ( V_2 , V_71 , V_72 , V_59 ) ;
if ( V_2 -> V_30 )
F_33 ( V_2 , V_72 , V_59 ) ;
}
if ( V_2 -> V_8 & V_125 )
V_2 -> V_84 = V_84 ;
else
V_2 -> V_84 =
( V_84 + V_59 ) & 0xff ;
V_23:
if ( F_45 ( V_2 ) < 0 )
goto V_22;
if ( V_71 )
F_35 ( V_2 , V_71 , V_59 ) ;
return;
V_22:
V_2 -> V_14 = - 1 ;
F_47 ( V_2 ) ;
}
static void F_51 ( struct V_127 * V_10 , T_3 V_62 ,
T_6 V_90 , void * V_128 ,
void * V_129 )
{
struct V_1 * V_2 = V_129 ;
unsigned int V_31 , V_65 , V_100 = V_90 / 4 ;
V_62 += V_103 - V_100 ;
for ( V_31 = 0 ; V_31 < V_100 ; ++ V_31 ) {
V_65 = F_26 ( V_2 , ++ V_62 ) ;
F_46 ( V_2 , V_65 ) ;
}
F_52 ( V_2 -> V_10 ) ;
}
static void F_53 ( struct V_127 * V_10 , T_3 V_62 ,
T_6 V_90 , void * V_128 ,
void * V_129 )
{
struct V_1 * V_2 = V_129 ;
unsigned int V_94 , V_65 , V_100 , V_112 ;
T_2 * V_72 , * V_130 = V_128 ;
V_100 = V_90 / V_105 ;
for ( V_94 = 0 ; V_94 < V_100 ; V_94 ++ ) {
if ( V_2 -> V_14 < 0 )
break;
V_72 = V_2 -> V_72 . V_100 [ V_2 -> V_14 ] . V_72 ;
if ( V_2 -> V_17 && V_2 -> V_17 -> V_16 ) {
V_65 = F_29 ( V_72 [ 1 ] ) & V_68 ;
F_46 ( V_2 -> V_17 , V_65 ) ;
}
V_112 =
( F_29 ( V_130 [ V_94 ] ) >> V_131 ) / 4 ;
F_48 ( V_2 , V_112 , V_72 ) ;
}
if ( V_2 -> V_14 < 0 ) {
if ( V_2 -> V_17 ) {
V_2 -> V_17 -> V_14 = - 1 ;
F_47 ( V_2 -> V_17 ) ;
}
return;
}
if ( V_2 -> V_17 && V_2 -> V_17 -> V_16 )
F_52 ( V_2 -> V_17 -> V_10 ) ;
F_52 ( V_2 -> V_10 ) ;
}
static void F_54 ( struct V_127 * V_10 , T_3 V_62 ,
T_6 V_90 , void * V_128 ,
void * V_129 )
{
return;
}
static void F_55 ( struct V_127 * V_10 ,
T_3 V_62 , T_6 V_90 ,
void * V_128 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
V_2 -> V_16 = true ;
F_56 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_9 == V_132 )
V_10 -> V_133 . V_134 = F_53 ;
else if ( ( V_2 -> V_8 & V_25 ) && ( V_2 -> V_8 & V_135 ) )
V_10 -> V_133 . V_134 = F_54 ;
else
V_10 -> V_133 . V_134 = F_51 ;
V_10 -> V_133 . V_134 ( V_10 , V_62 , V_90 , V_128 , V_2 ) ;
}
int F_57 ( struct V_1 * V_2 , int V_136 , int V_137 )
{
static const struct {
unsigned int V_138 ;
unsigned int V_63 ;
} V_139 [] = {
[ V_140 ] = { 4 , 3072 } ,
[ V_141 ] = { 6 , 1024 } ,
[ V_142 ] = { 12 , 1024 } ,
[ V_143 ] = { 24 , 1024 } ,
[ V_61 ] = { 0 , 67 } ,
[ V_144 ] = { 0 , 67 } ,
[ V_145 ] = { 0 , 67 } ,
} ;
unsigned int V_146 ;
enum V_147 V_6 ;
int type , V_97 , V_22 ;
F_58 ( & V_2 -> V_11 ) ;
if ( F_8 ( F_9 ( V_2 ) ||
( V_2 -> V_38 < 1 ) ) ) {
V_22 = - V_148 ;
goto V_149;
}
if ( V_2 -> V_9 == V_132 &&
V_2 -> V_8 & V_150 )
V_2 -> V_84 = V_19 ;
else
V_2 -> V_84 = 0 ;
V_2 -> V_60 = V_139 [ V_2 -> V_32 ] . V_138 ;
V_2 -> V_67 = V_139 [ V_2 -> V_32 ] . V_63 ;
V_2 -> V_66 = V_43 ;
if ( V_2 -> V_9 == V_132 ) {
V_6 = V_151 ;
type = V_152 ;
V_146 = V_105 ;
} else {
V_6 = V_153 ;
type = V_154 ;
V_146 = V_104 ;
}
V_22 = F_59 ( & V_2 -> V_72 , V_2 -> V_4 , V_103 ,
F_19 ( V_2 ) , V_6 ) ;
if ( V_22 < 0 )
goto V_149;
V_2 -> V_10 = F_60 ( F_61 ( V_2 -> V_4 ) -> V_155 ,
type , V_136 , V_137 , V_146 ,
F_55 , V_2 ) ;
if ( F_40 ( V_2 -> V_10 ) ) {
V_22 = F_62 ( V_2 -> V_10 ) ;
if ( V_22 == - V_156 )
F_43 ( & V_2 -> V_4 -> V_102 ,
L_5 ) ;
goto V_157;
}
F_63 ( V_2 ) ;
V_2 -> V_14 = 0 ;
do {
if ( V_2 -> V_9 == V_132 )
V_22 = F_45 ( V_2 ) ;
else
V_22 = F_44 ( V_2 , 0 , true ) ;
if ( V_22 < 0 )
goto V_158;
} while ( V_2 -> V_14 > 0 );
V_97 = V_159 ;
if ( V_2 -> V_8 & V_160 )
V_97 |= V_161 ;
V_2 -> V_16 = false ;
V_22 = F_64 ( V_2 -> V_10 , - 1 , 0 , V_97 ) ;
if ( V_22 < 0 )
goto V_158;
F_65 ( & V_2 -> V_11 ) ;
return 0 ;
V_158:
F_66 ( V_2 -> V_10 ) ;
V_2 -> V_10 = F_3 ( - 1 ) ;
V_157:
F_67 ( & V_2 -> V_72 , V_2 -> V_4 ) ;
V_149:
F_65 ( & V_2 -> V_11 ) ;
return V_22 ;
}
unsigned long F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 && F_9 ( V_2 ) )
F_69 ( V_2 -> V_10 ) ;
else
V_2 -> V_57 = true ;
return F_36 ( V_2 -> V_55 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_106 ) =
( F_61 ( V_2 -> V_4 ) -> V_155 -> V_162 & 0x3f ) << 24 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_58 ( & V_2 -> V_11 ) ;
if ( ! F_9 ( V_2 ) ) {
F_65 ( & V_2 -> V_11 ) ;
return;
}
F_23 ( & V_2 -> V_12 ) ;
F_71 ( V_2 -> V_10 ) ;
F_66 ( V_2 -> V_10 ) ;
V_2 -> V_10 = F_3 ( - 1 ) ;
F_67 ( & V_2 -> V_72 , V_2 -> V_4 ) ;
V_2 -> V_16 = false ;
F_65 ( & V_2 -> V_11 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
V_71 = F_36 ( V_2 -> V_71 ) ;
if ( V_71 ) {
F_72 ( V_71 ) ;
if ( F_73 ( V_71 ) )
F_74 ( V_71 , V_163 ) ;
F_75 ( V_71 ) ;
}
}
