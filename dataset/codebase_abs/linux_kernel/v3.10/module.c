static inline T_1
F_1 ( const struct V_1 * V_1 )
{
return ( T_1 ) V_1 & ~ 0xfUL ;
}
static inline int
F_2 ( const struct V_1 * V_1 )
{
return ( T_1 ) V_1 & 0x3 ;
}
static int
F_3 ( struct V_2 * V_3 , struct V_1 * V_1 , T_1 V_4 )
{
if ( F_2 ( V_1 ) != 2 ) {
F_4 ( V_5 L_1 ,
V_3 -> V_6 , F_2 ( V_1 ) ) ;
return 0 ;
}
F_5 ( ( V_7 ) V_1 , V_4 ) ;
return 1 ;
}
static int
F_6 ( struct V_2 * V_3 , struct V_1 * V_1 , T_1 V_4 )
{
if ( F_2 ( V_1 ) != 2 ) {
F_4 ( V_5 L_2 ,
V_3 -> V_6 , F_2 ( V_1 ) ) ;
return 0 ;
}
if ( V_4 + ( ( T_1 ) 1 << 59 ) >= ( 1UL << 60 ) ) {
F_4 ( V_5 L_3 ,
V_3 -> V_6 , ( long ) V_4 ) ;
return 0 ;
}
F_7 ( ( V_7 ) V_1 , V_4 ) ;
return 1 ;
}
static int
F_8 ( struct V_2 * V_3 , struct V_1 * V_1 , T_1 V_4 )
{
if ( V_4 + ( 1 << 21 ) >= ( 1 << 22 ) ) {
F_4 ( V_5 L_4 ,
V_3 -> V_6 , ( long ) V_4 ) ;
return 0 ;
}
F_9 ( ( V_7 ) V_1 , 0x01fffcfe000UL , ( ( ( V_4 & 0x200000UL ) << 15 )
| ( ( V_4 & 0x1f0000UL ) << 6 )
| ( ( V_4 & 0x00ff80UL ) << 20 )
| ( ( V_4 & 0x00007fUL ) << 13 ) ) ) ;
return 1 ;
}
static int
F_10 ( struct V_2 * V_3 , struct V_1 * V_1 , T_1 V_4 )
{
if ( V_4 + ( 1 << 20 ) >= ( 1 << 21 ) ) {
F_4 ( V_5 L_5 ,
V_3 -> V_6 , ( long ) V_4 ) ;
return 0 ;
}
F_9 ( ( V_7 ) V_1 , 0x11ffffe000UL , ( ( ( V_4 & 0x100000UL ) << 16 )
| ( ( V_4 & 0x0fffffUL ) << 13 ) ) ) ;
return 1 ;
}
static int
F_11 ( struct V_2 * V_3 , struct V_8 * V_9 , long V_10 , unsigned long V_11 )
{
if ( F_3 ( V_3 , (struct V_1 * ) ( V_9 -> F_1 [ 0 ] + 2 ) , V_11 )
&& F_6 ( V_3 , (struct V_1 * ) ( V_9 -> F_1 [ 1 ] + 2 ) ,
( V_10 - ( V_12 ) V_9 -> F_1 [ 1 ] ) / 16 ) )
return 1 ;
return 0 ;
}
unsigned long
F_12 ( struct V_8 * V_9 )
{
T_1 V_13 , V_14 , * V_15 = ( T_1 * ) V_9 -> F_1 [ 1 ] ;
long V_16 ;
V_13 = V_15 [ 0 ] ; V_14 = V_15 [ 1 ] ;
V_16 = ( ( ( V_14 & 0x00fffff000000000UL ) >> 36 )
| ( ( V_13 >> 48 ) << 20 ) | ( ( V_14 & 0x7fffffUL ) << 36 )
| ( ( V_14 & 0x0800000000000000UL ) << 0 ) ) ;
return ( long ) V_9 -> F_1 [ 1 ] + 16 * V_16 ;
}
static int
F_11 ( struct V_2 * V_3 , struct V_8 * V_9 , long V_10 , unsigned long V_11 )
{
if ( F_3 ( V_3 , (struct V_1 * ) ( V_9 -> F_1 [ 0 ] + 2 ) , V_10 )
&& F_3 ( V_3 , (struct V_1 * ) ( V_9 -> F_1 [ 1 ] + 2 ) , V_11 ) )
return 1 ;
return 0 ;
}
unsigned long
F_12 ( struct V_8 * V_9 )
{
T_1 V_13 , V_14 , * V_15 = ( T_1 * ) V_9 -> F_1 [ 0 ] ;
V_13 = V_15 [ 0 ] ; V_14 = V_15 [ 1 ] ;
return ( ( ( V_14 & 0x000007f000000000 ) >> 36 )
| ( ( V_14 & 0x07fc000000000000 ) >> 43 )
| ( ( V_14 & 0x0003e00000000000 ) >> 29 )
| ( ( V_14 & 0x0000100000000000 ) >> 23 )
| ( ( V_13 >> 46 ) << 22 ) | ( ( V_14 & 0x7fffff ) << 40 )
| ( ( V_14 & 0x0800000000000000 ) << 4 ) ) ;
}
void
F_13 ( struct V_2 * V_3 , void * V_17 )
{
if ( V_3 && V_3 -> V_18 . V_19 &&
V_17 == V_3 -> V_20 ) {
F_14 ( V_3 -> V_18 . V_19 ) ;
V_3 -> V_18 . V_19 = NULL ;
}
F_15 ( V_17 ) ;
}
static int
F_16 ( const T_2 * V_21 , unsigned int V_22 )
{
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
if ( V_21 [ V_23 ] . V_24 == V_21 [ V_22 ] . V_24 && V_21 [ V_23 ] . V_25 == V_21 [ V_22 ] . V_25 )
return 1 ;
}
return 0 ;
}
static unsigned int
F_17 ( const T_2 * V_21 , unsigned int V_22 )
{
unsigned int V_23 , V_26 = 0 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
switch ( F_18 ( V_21 [ V_23 ] . V_24 ) ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
if ( ! F_16 ( V_21 , V_23 ) )
V_26 ++ ;
break;
}
}
return V_26 ;
}
static unsigned int
F_19 ( const T_2 * V_21 , unsigned int V_22 )
{
unsigned int V_23 , V_26 = 0 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
switch ( F_18 ( V_21 [ V_23 ] . V_24 ) ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
if ( ! F_16 ( V_21 , V_23 ) )
V_26 ++ ;
break;
}
}
return V_26 ;
}
static unsigned int
F_20 ( const T_2 * V_21 , unsigned int V_22 )
{
unsigned int V_23 , V_26 = 0 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
switch ( F_18 ( V_21 [ V_23 ] . V_24 ) ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_30 :
case V_33 :
case V_32 :
case V_31 :
case V_35 :
case V_34 :
case V_41 :
case V_42 :
case V_36 :
if ( ! F_16 ( V_21 , V_23 ) )
V_26 ++ ;
break;
}
}
return V_26 ;
}
int
F_21 ( T_3 * V_48 , T_4 * V_49 , char * V_50 ,
struct V_2 * V_3 )
{
unsigned long V_51 = 0 , V_52 = 0 , V_53 = 0 , V_54 = 0 ;
T_5 * V_55 , * V_56 = V_49 + V_48 -> V_57 ;
for ( V_55 = V_49 ; V_55 < V_56 ; ++ V_55 )
if ( strcmp ( L_6 , V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_59 = V_55 ;
else if ( strcmp ( L_7 , V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_60 = V_55 ;
else if ( strcmp ( L_8 , V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_61 = V_55 ;
else if ( strcmp ( L_9 , V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_62 = V_55 ;
else if ( strcmp ( L_10 , V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_63 = V_55 ;
#ifdef F_22
else if ( strcmp ( L_11 ,
V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_64 = V_55 ;
else if ( strcmp ( L_12 ,
V_50 + V_55 -> V_58 ) == 0 )
V_3 -> V_18 . V_65 = V_55 ;
#endif
if ( ! V_3 -> V_18 . V_59 || ! V_3 -> V_18 . V_60 || ! V_3 -> V_18 . V_61 || ! V_3 -> V_18 . V_62 ) {
F_4 ( V_5 L_13 , V_3 -> V_6 ) ;
return - V_66 ;
}
for ( V_55 = V_49 + 1 ; V_55 < V_56 ; ++ V_55 ) {
const T_2 * V_67 = ( void * ) V_48 + V_55 -> V_68 ;
unsigned long V_69 = V_55 -> V_70 / sizeof( T_2 ) ;
if ( V_55 -> V_71 != V_72 )
continue;
V_53 += F_17 ( V_67 , V_69 ) ;
V_54 += F_20 ( V_67 , V_69 ) ;
if ( strstr ( V_50 + V_55 -> V_58 , L_14 ) )
V_52 += F_19 ( V_67 , V_69 ) ;
else
V_51 += F_19 ( V_67 , V_69 ) ;
}
V_3 -> V_18 . V_59 -> V_71 = V_73 ;
V_3 -> V_18 . V_59 -> V_74 = V_75 | V_76 ;
V_3 -> V_18 . V_59 -> V_77 = 16 ;
V_3 -> V_18 . V_59 -> V_70 = V_51 * sizeof( struct V_8 ) ;
V_3 -> V_18 . V_60 -> V_71 = V_73 ;
V_3 -> V_18 . V_60 -> V_74 = V_75 | V_76 ;
V_3 -> V_18 . V_60 -> V_77 = 16 ;
V_3 -> V_18 . V_60 -> V_70 = V_52 * sizeof( struct V_8 ) ;
V_3 -> V_18 . V_61 -> V_71 = V_73 ;
V_3 -> V_18 . V_61 -> V_74 = V_78 | V_76 ;
V_3 -> V_18 . V_61 -> V_77 = 8 ;
V_3 -> V_18 . V_61 -> V_70 = V_53 * sizeof( struct V_79 ) ;
V_3 -> V_18 . V_62 -> V_71 = V_73 ;
V_3 -> V_18 . V_62 -> V_74 = V_76 ;
V_3 -> V_18 . V_62 -> V_77 = 8 ;
V_3 -> V_18 . V_62 -> V_70 = V_54 * sizeof( struct V_80 ) ;
F_23 ( L_15 ,
V_81 , V_3 -> V_18 . V_59 -> V_70 , V_3 -> V_18 . V_60 -> V_70 ,
V_3 -> V_18 . V_61 -> V_70 , V_3 -> V_18 . V_62 -> V_70 ) ;
return 0 ;
}
static inline int
F_24 ( const struct V_2 * V_3 , T_1 V_82 )
{
return V_82 - ( T_1 ) V_3 -> V_20 < V_3 -> V_83 ;
}
static inline int
F_25 ( const struct V_2 * V_3 , T_1 V_82 )
{
return V_82 - ( T_1 ) V_3 -> V_84 < V_3 -> V_85 ;
}
static inline int
F_26 ( const struct V_2 * V_3 , T_1 V_86 )
{
return F_24 ( V_3 , V_86 ) || F_25 ( V_3 , V_86 ) ;
}
static T_1
F_27 ( struct V_2 * V_3 , T_1 V_86 , int * V_87 )
{
struct V_79 * V_61 , * V_88 ;
if ( ! * V_87 )
return 0 ;
V_61 = ( void * ) V_3 -> V_18 . V_61 -> V_89 ;
for ( V_88 = V_61 ; V_88 < V_61 + V_3 -> V_18 . V_90 ; ++ V_88 )
if ( V_88 -> V_4 == V_86 )
goto V_91;
F_28 ( V_88 >= (struct V_79 * ) ( V_3 -> V_18 . V_61 -> V_89 + V_3 -> V_18 . V_61 -> V_70 ) ) ;
V_88 -> V_4 = V_86 ;
++ V_3 -> V_18 . V_90 ;
V_91:
return ( T_1 ) V_88 - V_3 -> V_18 . V_92 ;
}
static inline int
F_29 ( struct V_2 * V_3 , T_1 V_86 )
{
return V_86 - V_3 -> V_18 . V_92 + V_93 / 2 < V_93 ;
}
static T_1
F_30 ( struct V_2 * V_3 , const struct V_1 * V_1 , T_1 V_86 , int * V_87 )
{
struct V_8 * V_9 , * V_94 ;
T_1 V_10 , V_11 ;
if ( ! * V_87 )
return 0 ;
if ( F_24 ( V_3 , ( T_1 ) V_1 ) ) {
V_9 = ( void * ) V_3 -> V_18 . V_60 -> V_89 ;
V_94 = ( void * ) V_9 + V_3 -> V_18 . V_60 -> V_70 ;
} else {
V_9 = ( void * ) V_3 -> V_18 . V_59 -> V_89 ;
V_94 = ( void * ) V_9 + V_3 -> V_18 . V_59 -> V_70 ;
}
V_10 = ( ( T_1 * ) V_86 ) [ 0 ] ;
V_11 = ( ( T_1 * ) V_86 ) [ 1 ] ;
while ( V_9 -> F_1 [ 0 ] [ 0 ] ) {
if ( F_12 ( V_9 ) == V_10 )
goto V_91;
if ( ++ V_9 >= V_94 )
F_31 () ;
}
* V_9 = V_95 ;
if ( ! F_11 ( V_3 , V_9 , V_10 , V_11 ) ) {
* V_87 = 0 ;
return 0 ;
}
#if V_96
if ( F_12 ( V_9 ) != V_10 ) {
F_4 ( L_16 ,
V_81 , V_10 , F_12 ( V_9 ) ) ;
* V_87 = 0 ;
return 0 ;
}
#endif
V_91:
return ( T_1 ) V_9 ;
}
static T_1
F_32 ( struct V_2 * V_3 , T_1 V_86 , int * V_87 )
{
struct V_80 * V_80 = ( void * ) V_3 -> V_18 . V_62 -> V_89 ;
if ( ! * V_87 )
return 0 ;
if ( ! V_86 ) {
F_4 ( V_5 L_17 , V_3 -> V_6 ) ;
return 0 ;
}
if ( ! F_26 ( V_3 , V_86 ) )
return V_86 ;
while ( V_80 -> V_97 ) {
if ( V_80 -> V_97 == V_86 )
return ( T_1 ) V_80 ;
if ( ( T_1 ) ++ V_80 >= V_3 -> V_18 . V_62 -> V_89 + V_3 -> V_18 . V_62 -> V_70 )
F_31 () ;
}
V_80 -> V_97 = V_86 ;
V_80 -> V_92 = V_3 -> V_18 . V_92 ;
return ( T_1 ) V_80 ;
}
static inline int
F_33 ( struct V_2 * V_3 , T_6 V_98 , T_7 * V_99 , T_1 V_100 ,
T_5 * V_101 , void * V_102 )
{
enum V_103 V_104 = ( V_98 >> V_105 ) & V_106 ;
enum V_107 V_108 = ( V_98 >> V_109 ) & V_110 ;
T_1 V_4 ;
int V_111 = 1 ;
V_4 = V_99 -> V_112 + V_100 ;
switch ( V_108 ) {
case V_113 :
case V_114 :
break;
case V_115 : V_4 -= V_3 -> V_18 . V_92 ; break;
case V_116 : V_4 = F_27 ( V_3 , V_4 , & V_111 ) ; break;
case V_117 : V_4 = F_30 ( V_3 , V_102 , V_4 , & V_111 ) ; break;
case V_118 : V_4 = F_32 ( V_3 , V_4 , & V_111 ) ; break;
case V_119 : V_4 -= V_101 -> V_89 ; break;
case V_120 : V_4 = F_27 ( V_3 , F_32 ( V_3 , V_4 , & V_111 ) , & V_111 ) ; break;
case V_121 :
switch ( V_98 ) {
case V_36 :
if ( ( F_24 ( V_3 , V_4 ) && F_25 ( V_3 , ( T_1 ) V_102 ) ) ||
( F_25 ( V_3 , V_4 ) && F_24 ( V_3 , ( T_1 ) V_102 ) ) ) {
T_1 V_122 = ( ( V_12 ) V_4 - ( V_12 ) V_102 ) / 16 ;
if ( V_122 + ( 1 << 20 ) >= ( 1 << 21 ) ) {
V_4 = F_32 ( V_3 , V_4 , & V_111 ) ;
V_4 = F_30 ( V_3 , V_102 , V_4 , & V_111 ) ;
}
} else if ( ! F_26 ( V_3 , V_4 ) )
V_4 = F_30 ( V_3 , V_102 , V_4 , & V_111 ) ;
default:
V_4 -= F_1 ( V_102 ) ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_4 -= ( T_1 ) V_102 ;
break;
}
switch ( V_98 ) {
case V_127 : V_104 = V_128 ; break;
case V_36 : V_104 = V_129 ; break;
case V_130 : V_104 = V_131 ; break;
case V_132 : V_104 = V_133 ; break;
default: break;
}
break;
case V_134 :
V_4 -= ( T_1 ) ( F_24 ( V_3 , V_4 ) ? V_3 -> V_20 : V_3 -> V_84 ) ;
break;
case V_135 :
F_31 () ;
break;
case V_136 :
if ( V_98 == V_137 ) {
if ( ! F_26 ( V_3 , V_4 ) ) {
F_4 ( V_5 L_18
L_19 , V_81 ,
V_138 [ V_98 ] , ( unsigned long ) V_4 ) ;
return - V_66 ;
}
V_104 = V_129 ;
}
V_4 -= F_1 ( V_102 ) ;
break;
case V_139 :
switch ( V_98 ) {
case V_41 :
case V_42 :
V_4 = F_32 ( V_3 , F_30 ( V_3 , V_102 , V_4 , & V_111 ) , & V_111 ) ;
V_104 = V_140 ;
if ( V_98 == V_41 )
V_104 = V_141 ;
break;
case V_142 :
V_4 = V_100 - V_99 -> V_112 ;
V_104 = V_143 ;
break;
case V_28 :
if ( F_29 ( V_3 , V_4 ) )
V_4 -= V_3 -> V_18 . V_92 ;
else
V_4 = F_27 ( V_3 , V_4 , & V_111 ) ;
V_104 = V_144 ;
break;
case V_145 :
if ( F_29 ( V_3 , V_4 ) ) {
F_23 ( L_20 , V_81 , V_102 ) ;
F_9 ( ( V_7 ) V_102 , 0x1fff80fe000UL , 0x10000000000UL ) ;
}
return 0 ;
default:
if ( V_138 [ V_98 ] )
F_4 ( V_5 L_21 ,
V_3 -> V_6 , V_138 [ V_98 ] ) ;
else
F_4 ( V_5 L_22 ,
V_3 -> V_6 , V_98 ) ;
return - V_66 ;
}
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
F_4 ( V_5 L_23 ,
V_3 -> V_6 , V_138 [ V_98 ] ? V_138 [ V_98 ] : L_24 ) ;
return - V_66 ;
default:
F_4 ( V_5 L_25 , V_3 -> V_6 , V_98 ) ;
return - V_66 ;
}
if ( ! V_111 )
return - V_66 ;
F_23 ( L_26 , V_81 , V_102 , V_4 ,
V_138 [ V_98 ] ? V_138 [ V_98 ] : L_24 , V_99 -> V_112 + V_100 ) ;
switch ( V_104 ) {
case V_129 : V_111 = F_10 ( V_3 , V_102 , ( V_12 ) V_4 / 16 ) ; break;
case V_144 : V_111 = F_8 ( V_3 , V_102 , V_4 ) ; break;
case V_143 : V_111 = F_3 ( V_3 , V_102 , V_4 ) ; break;
case V_128 : V_111 = F_6 ( V_3 , V_102 , ( V_12 ) V_4 / 16 ) ; break;
case V_152 : F_34 ( V_4 , ( V_153 * ) V_102 ) ; break;
case V_140 : F_34 ( V_4 , ( T_1 * ) V_102 ) ; break;
case V_154 :
case V_141 :
case V_155 :
case V_131 :
case V_133 :
F_4 ( V_5 L_27 ,
V_3 -> V_6 , V_104 , V_138 [ V_98 ] ? V_138 [ V_98 ] : L_24 ) ;
return - V_66 ;
default:
F_4 ( V_5 L_28 ,
V_3 -> V_6 , V_138 [ V_98 ] ? V_138 [ V_98 ] : L_24 , V_104 ) ;
return - V_66 ;
}
return V_111 ? 0 : - V_66 ;
}
int
F_35 ( T_5 * V_49 , const char * V_156 , unsigned int V_157 ,
unsigned int V_158 , struct V_2 * V_3 )
{
unsigned int V_23 , V_159 = V_49 [ V_158 ] . V_70 / sizeof( T_2 ) ;
T_2 * V_21 = ( void * ) V_49 [ V_158 ] . V_89 ;
T_5 * V_160 ;
int V_26 ;
F_23 ( L_29 , V_81 ,
V_158 , V_159 , V_49 [ V_158 ] . V_161 ) ;
V_160 = V_49 + V_49 [ V_158 ] . V_161 ;
if ( V_160 -> V_162 == ~ 0UL )
return 0 ;
if ( ! V_3 -> V_18 . V_92 ) {
T_1 V_92 ;
if ( V_3 -> V_85 > V_93 )
V_92 = V_3 -> V_85 - V_93 / 2 ;
else
V_92 = V_3 -> V_85 / 2 ;
V_92 = ( T_1 ) V_3 -> V_84 + ( ( V_92 + 7 ) & - 8 ) ;
V_3 -> V_18 . V_92 = V_92 ;
F_23 ( L_30 , V_81 , V_92 ) ;
}
for ( V_23 = 0 ; V_23 < V_159 ; V_23 ++ ) {
V_26 = F_33 ( V_3 , F_18 ( V_21 [ V_23 ] . V_24 ) ,
( ( T_7 * ) V_49 [ V_157 ] . V_89
+ F_36 ( V_21 [ V_23 ] . V_24 ) ) ,
V_21 [ V_23 ] . V_25 , V_160 ,
( void * ) V_160 -> V_89 + V_21 [ V_23 ] . V_163 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return 0 ;
}
static void
F_37 ( struct V_2 * V_3 )
{
struct V_164 * V_165 = ( void * ) V_3 -> V_18 . V_63 -> V_89 ;
struct V_164 * V_166 = V_165 + V_3 -> V_18 . V_63 -> V_70 / sizeof ( * V_165 ) ;
struct V_164 V_167 , * V_168 , * V_169 , * V_170 , * V_171 ;
unsigned long V_172 = 0 , V_173 = 0 ;
for ( V_168 = V_165 ; V_168 < V_166 ; ++ V_168 )
if ( F_24 ( V_3 , V_168 -> V_174 ) )
++ V_172 ;
else
++ V_173 ;
for ( V_168 = V_165 ; V_168 < V_166 ; ++ V_168 ) {
for ( V_169 = V_168 + 1 ; V_169 < V_166 ; ++ V_169 ) {
if ( V_169 -> V_174 < V_168 -> V_174 ) {
V_167 = * V_168 ;
* V_168 = * V_169 ;
* V_169 = V_167 ;
}
}
}
if ( F_24 ( V_3 , V_165 -> V_174 ) ) {
V_171 = V_165 ;
V_170 = V_165 + V_172 ;
} else {
V_170 = V_165 ;
V_171 = V_165 + V_173 ;
}
F_23 ( L_31 , V_81 ,
V_3 -> V_6 , V_3 -> V_18 . V_92 , V_172 , V_173 ) ;
if ( V_173 > 0 ) {
V_3 -> V_18 . V_175 = F_38 ( V_3 -> V_6 , 0 , V_3 -> V_18 . V_92 ,
V_170 , V_170 + V_173 ) ;
F_23 ( L_32 , V_81 ,
V_3 -> V_18 . V_175 , V_170 , V_170 + V_173 ) ;
}
if ( V_172 > 0 ) {
V_3 -> V_18 . V_19 = F_38 ( V_3 -> V_6 , 0 , V_3 -> V_18 . V_92 ,
V_171 , V_171 + V_172 ) ;
F_23 ( L_33 , V_81 ,
V_3 -> V_18 . V_19 , V_171 , V_171 + V_172 ) ;
}
}
int
F_39 ( const T_3 * V_176 , const T_4 * V_49 , struct V_2 * V_3 )
{
F_23 ( L_34 , V_81 , V_3 -> V_171 ) ;
if ( V_3 -> V_18 . V_63 )
F_37 ( V_3 ) ;
#ifdef F_22
if ( V_3 -> V_18 . V_64 ) {
struct V_177 * V_165 =
(struct V_177 * )
V_3 -> V_18 . V_64 -> V_89 ;
struct V_177 * V_166 =
(struct V_177 * )
( V_3 -> V_18 . V_64 -> V_89 +
V_3 -> V_18 . V_64 -> V_70 ) ;
F_40 ( V_165 , V_166 ) ;
}
if ( V_3 -> V_18 . V_65 ) {
struct V_178 * V_165 =
(struct V_178 * )
V_3 -> V_18 . V_65 -> V_89 ;
struct V_178 * V_166 =
(struct V_178 * )
( V_3 -> V_18 . V_65 -> V_89 +
V_3 -> V_18 . V_65 -> V_70 ) ;
F_41 ( V_165 , V_166 ) ;
}
#endif
return 0 ;
}
void
F_42 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 . V_19 )
F_14 ( V_3 -> V_18 . V_19 ) ;
if ( V_3 -> V_18 . V_175 )
F_14 ( V_3 -> V_18 . V_175 ) ;
}
