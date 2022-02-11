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
F_13 ( struct V_2 * V_3 )
{
if ( V_3 -> V_17 . V_18 ) {
F_14 ( V_3 -> V_17 . V_18 ) ;
V_3 -> V_17 . V_18 = NULL ;
}
}
static int
F_15 ( const T_2 * V_19 , unsigned int V_20 )
{
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
if ( V_19 [ V_21 ] . V_22 == V_19 [ V_20 ] . V_22 && V_19 [ V_21 ] . V_23 == V_19 [ V_20 ] . V_23 )
return 1 ;
}
return 0 ;
}
static unsigned int
F_16 ( const T_2 * V_19 , unsigned int V_20 )
{
unsigned int V_21 , V_24 = 0 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
switch ( F_17 ( V_19 [ V_21 ] . V_22 ) ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
if ( ! F_15 ( V_19 , V_21 ) )
V_24 ++ ;
break;
}
}
return V_24 ;
}
static unsigned int
F_18 ( const T_2 * V_19 , unsigned int V_20 )
{
unsigned int V_21 , V_24 = 0 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
switch ( F_17 ( V_19 [ V_21 ] . V_22 ) ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
if ( ! F_15 ( V_19 , V_21 ) )
V_24 ++ ;
break;
}
}
return V_24 ;
}
static unsigned int
F_19 ( const T_2 * V_19 , unsigned int V_20 )
{
unsigned int V_21 , V_24 = 0 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
switch ( F_17 ( V_19 [ V_21 ] . V_22 ) ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_28 :
case V_31 :
case V_30 :
case V_29 :
case V_33 :
case V_32 :
case V_39 :
case V_40 :
case V_34 :
if ( ! F_15 ( V_19 , V_21 ) )
V_24 ++ ;
break;
}
}
return V_24 ;
}
int
F_20 ( T_3 * V_46 , T_4 * V_47 , char * V_48 ,
struct V_2 * V_3 )
{
unsigned long V_49 = 0 , V_50 = 0 , V_51 = 0 , V_52 = 0 ;
T_5 * V_53 , * V_54 = V_47 + V_46 -> V_55 ;
for ( V_53 = V_47 ; V_53 < V_54 ; ++ V_53 )
if ( strcmp ( L_6 , V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_57 = V_53 ;
else if ( strcmp ( L_7 , V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_58 = V_53 ;
else if ( strcmp ( L_8 , V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_59 = V_53 ;
else if ( strcmp ( L_9 , V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_60 = V_53 ;
else if ( strcmp ( L_10 , V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_61 = V_53 ;
#ifdef F_21
else if ( strcmp ( L_11 ,
V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_62 = V_53 ;
else if ( strcmp ( L_12 ,
V_48 + V_53 -> V_56 ) == 0 )
V_3 -> V_17 . V_63 = V_53 ;
#endif
if ( ! V_3 -> V_17 . V_57 || ! V_3 -> V_17 . V_58 || ! V_3 -> V_17 . V_59 || ! V_3 -> V_17 . V_60 ) {
F_4 ( V_5 L_13 , V_3 -> V_6 ) ;
return - V_64 ;
}
for ( V_53 = V_47 + 1 ; V_53 < V_54 ; ++ V_53 ) {
const T_2 * V_65 = ( void * ) V_46 + V_53 -> V_66 ;
unsigned long V_67 = V_53 -> V_68 / sizeof( T_2 ) ;
if ( V_53 -> V_69 != V_70 )
continue;
V_51 += F_16 ( V_65 , V_67 ) ;
V_52 += F_19 ( V_65 , V_67 ) ;
if ( strstr ( V_48 + V_53 -> V_56 , L_14 ) )
V_50 += F_18 ( V_65 , V_67 ) ;
else
V_49 += F_18 ( V_65 , V_67 ) ;
}
V_3 -> V_17 . V_57 -> V_69 = V_71 ;
V_3 -> V_17 . V_57 -> V_72 = V_73 | V_74 ;
V_3 -> V_17 . V_57 -> V_75 = 16 ;
V_3 -> V_17 . V_57 -> V_68 = V_49 * sizeof( struct V_8 ) ;
V_3 -> V_17 . V_58 -> V_69 = V_71 ;
V_3 -> V_17 . V_58 -> V_72 = V_73 | V_74 ;
V_3 -> V_17 . V_58 -> V_75 = 16 ;
V_3 -> V_17 . V_58 -> V_68 = V_50 * sizeof( struct V_8 ) ;
V_3 -> V_17 . V_59 -> V_69 = V_71 ;
V_3 -> V_17 . V_59 -> V_72 = V_76 | V_74 ;
V_3 -> V_17 . V_59 -> V_75 = 8 ;
V_3 -> V_17 . V_59 -> V_68 = V_51 * sizeof( struct V_77 ) ;
V_3 -> V_17 . V_60 -> V_69 = V_71 ;
V_3 -> V_17 . V_60 -> V_72 = V_74 ;
V_3 -> V_17 . V_60 -> V_75 = 8 ;
V_3 -> V_17 . V_60 -> V_68 = V_52 * sizeof( struct V_78 ) ;
F_22 ( L_15 ,
V_79 , V_3 -> V_17 . V_57 -> V_68 , V_3 -> V_17 . V_58 -> V_68 ,
V_3 -> V_17 . V_59 -> V_68 , V_3 -> V_17 . V_60 -> V_68 ) ;
return 0 ;
}
static inline int
F_23 ( const struct V_2 * V_3 , T_1 V_80 )
{
return V_80 - ( T_1 ) V_3 -> V_81 < V_3 -> V_82 ;
}
static inline int
F_24 ( const struct V_2 * V_3 , T_1 V_80 )
{
return V_80 - ( T_1 ) V_3 -> V_83 < V_3 -> V_84 ;
}
static inline int
F_25 ( const struct V_2 * V_3 , T_1 V_85 )
{
return F_23 ( V_3 , V_85 ) || F_24 ( V_3 , V_85 ) ;
}
static T_1
F_26 ( struct V_2 * V_3 , T_1 V_85 , int * V_86 )
{
struct V_77 * V_59 , * V_87 ;
if ( ! * V_86 )
return 0 ;
V_59 = ( void * ) V_3 -> V_17 . V_59 -> V_88 ;
for ( V_87 = V_59 ; V_87 < V_59 + V_3 -> V_17 . V_89 ; ++ V_87 )
if ( V_87 -> V_4 == V_85 )
goto V_90;
F_27 ( V_87 >= (struct V_77 * ) ( V_3 -> V_17 . V_59 -> V_88 + V_3 -> V_17 . V_59 -> V_68 ) ) ;
V_87 -> V_4 = V_85 ;
++ V_3 -> V_17 . V_89 ;
V_90:
return ( T_1 ) V_87 - V_3 -> V_17 . V_91 ;
}
static inline int
F_28 ( struct V_2 * V_3 , T_1 V_85 )
{
return V_85 - V_3 -> V_17 . V_91 + V_92 / 2 < V_92 ;
}
static T_1
F_29 ( struct V_2 * V_3 , const struct V_1 * V_1 , T_1 V_85 , int * V_86 )
{
struct V_8 * V_9 , * V_93 ;
T_1 V_10 , V_11 ;
if ( ! * V_86 )
return 0 ;
if ( F_23 ( V_3 , ( T_1 ) V_1 ) ) {
V_9 = ( void * ) V_3 -> V_17 . V_58 -> V_88 ;
V_93 = ( void * ) V_9 + V_3 -> V_17 . V_58 -> V_68 ;
} else {
V_9 = ( void * ) V_3 -> V_17 . V_57 -> V_88 ;
V_93 = ( void * ) V_9 + V_3 -> V_17 . V_57 -> V_68 ;
}
V_10 = ( ( T_1 * ) V_85 ) [ 0 ] ;
V_11 = ( ( T_1 * ) V_85 ) [ 1 ] ;
while ( V_9 -> F_1 [ 0 ] [ 0 ] ) {
if ( F_12 ( V_9 ) == V_10 )
goto V_90;
if ( ++ V_9 >= V_93 )
F_30 () ;
}
* V_9 = V_94 ;
if ( ! F_11 ( V_3 , V_9 , V_10 , V_11 ) ) {
* V_86 = 0 ;
return 0 ;
}
#if V_95
if ( F_12 ( V_9 ) != V_10 ) {
F_4 ( L_16 ,
V_79 , V_10 , F_12 ( V_9 ) ) ;
* V_86 = 0 ;
return 0 ;
}
#endif
V_90:
return ( T_1 ) V_9 ;
}
static T_1
F_31 ( struct V_2 * V_3 , T_1 V_85 , int * V_86 )
{
struct V_78 * V_78 = ( void * ) V_3 -> V_17 . V_60 -> V_88 ;
if ( ! * V_86 )
return 0 ;
if ( ! V_85 ) {
F_4 ( V_5 L_17 , V_3 -> V_6 ) ;
return 0 ;
}
if ( ! F_25 ( V_3 , V_85 ) )
return V_85 ;
while ( V_78 -> V_96 ) {
if ( V_78 -> V_96 == V_85 )
return ( T_1 ) V_78 ;
if ( ( T_1 ) ++ V_78 >= V_3 -> V_17 . V_60 -> V_88 + V_3 -> V_17 . V_60 -> V_68 )
F_30 () ;
}
V_78 -> V_96 = V_85 ;
V_78 -> V_91 = V_3 -> V_17 . V_91 ;
return ( T_1 ) V_78 ;
}
static inline int
F_32 ( struct V_2 * V_3 , T_6 V_97 , T_7 * V_98 , T_1 V_99 ,
T_5 * V_100 , void * V_101 )
{
enum V_102 V_103 = ( V_97 >> V_104 ) & V_105 ;
enum V_106 V_107 = ( V_97 >> V_108 ) & V_109 ;
T_1 V_4 ;
int V_110 = 1 ;
V_4 = V_98 -> V_111 + V_99 ;
switch ( V_107 ) {
case V_112 :
case V_113 :
break;
case V_114 : V_4 -= V_3 -> V_17 . V_91 ; break;
case V_115 : V_4 = F_26 ( V_3 , V_4 , & V_110 ) ; break;
case V_116 : V_4 = F_29 ( V_3 , V_101 , V_4 , & V_110 ) ; break;
case V_117 : V_4 = F_31 ( V_3 , V_4 , & V_110 ) ; break;
case V_118 : V_4 -= V_100 -> V_88 ; break;
case V_119 : V_4 = F_26 ( V_3 , F_31 ( V_3 , V_4 , & V_110 ) , & V_110 ) ; break;
case V_120 :
switch ( V_97 ) {
case V_34 :
if ( ( F_23 ( V_3 , V_4 ) && F_24 ( V_3 , ( T_1 ) V_101 ) ) ||
( F_24 ( V_3 , V_4 ) && F_23 ( V_3 , ( T_1 ) V_101 ) ) ) {
T_1 V_121 = ( ( V_12 ) V_4 - ( V_12 ) V_101 ) / 16 ;
if ( V_121 + ( 1 << 20 ) >= ( 1 << 21 ) ) {
V_4 = F_31 ( V_3 , V_4 , & V_110 ) ;
V_4 = F_29 ( V_3 , V_101 , V_4 , & V_110 ) ;
}
} else if ( ! F_25 ( V_3 , V_4 ) )
V_4 = F_29 ( V_3 , V_101 , V_4 , & V_110 ) ;
default:
V_4 -= F_1 ( V_101 ) ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_4 -= ( T_1 ) V_101 ;
break;
}
switch ( V_97 ) {
case V_126 : V_103 = V_127 ; break;
case V_34 : V_103 = V_128 ; break;
case V_129 : V_103 = V_130 ; break;
case V_131 : V_103 = V_132 ; break;
default: break;
}
break;
case V_133 :
V_4 -= ( T_1 ) ( F_23 ( V_3 , V_4 ) ? V_3 -> V_81 : V_3 -> V_83 ) ;
break;
case V_134 :
F_30 () ;
break;
case V_135 :
if ( V_97 == V_136 ) {
if ( ! F_25 ( V_3 , V_4 ) ) {
F_4 ( V_5 L_18
L_19 , V_79 ,
V_137 [ V_97 ] , ( unsigned long ) V_4 ) ;
return - V_64 ;
}
V_103 = V_128 ;
}
V_4 -= F_1 ( V_101 ) ;
break;
case V_138 :
switch ( V_97 ) {
case V_39 :
case V_40 :
V_4 = F_31 ( V_3 , F_29 ( V_3 , V_101 , V_4 , & V_110 ) , & V_110 ) ;
V_103 = V_139 ;
if ( V_97 == V_39 )
V_103 = V_140 ;
break;
case V_141 :
V_4 = V_99 - V_98 -> V_111 ;
V_103 = V_142 ;
break;
case V_26 :
if ( F_28 ( V_3 , V_4 ) )
V_4 -= V_3 -> V_17 . V_91 ;
else
V_4 = F_26 ( V_3 , V_4 , & V_110 ) ;
V_103 = V_143 ;
break;
case V_144 :
if ( F_28 ( V_3 , V_4 ) ) {
F_22 ( L_20 , V_79 , V_101 ) ;
F_9 ( ( V_7 ) V_101 , 0x1fff80fe000UL , 0x10000000000UL ) ;
}
return 0 ;
default:
if ( V_137 [ V_97 ] )
F_4 ( V_5 L_21 ,
V_3 -> V_6 , V_137 [ V_97 ] ) ;
else
F_4 ( V_5 L_22 ,
V_3 -> V_6 , V_97 ) ;
return - V_64 ;
}
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
F_4 ( V_5 L_23 ,
V_3 -> V_6 , V_137 [ V_97 ] ? V_137 [ V_97 ] : L_24 ) ;
return - V_64 ;
default:
F_4 ( V_5 L_25 , V_3 -> V_6 , V_97 ) ;
return - V_64 ;
}
if ( ! V_110 )
return - V_64 ;
F_22 ( L_26 , V_79 , V_101 , V_4 ,
V_137 [ V_97 ] ? V_137 [ V_97 ] : L_24 , V_98 -> V_111 + V_99 ) ;
switch ( V_103 ) {
case V_128 : V_110 = F_10 ( V_3 , V_101 , ( V_12 ) V_4 / 16 ) ; break;
case V_143 : V_110 = F_8 ( V_3 , V_101 , V_4 ) ; break;
case V_142 : V_110 = F_3 ( V_3 , V_101 , V_4 ) ; break;
case V_127 : V_110 = F_6 ( V_3 , V_101 , ( V_12 ) V_4 / 16 ) ; break;
case V_151 : F_33 ( V_4 , ( V_152 * ) V_101 ) ; break;
case V_139 : F_33 ( V_4 , ( T_1 * ) V_101 ) ; break;
case V_153 :
case V_140 :
case V_154 :
case V_130 :
case V_132 :
F_4 ( V_5 L_27 ,
V_3 -> V_6 , V_103 , V_137 [ V_97 ] ? V_137 [ V_97 ] : L_24 ) ;
return - V_64 ;
default:
F_4 ( V_5 L_28 ,
V_3 -> V_6 , V_137 [ V_97 ] ? V_137 [ V_97 ] : L_24 , V_103 ) ;
return - V_64 ;
}
return V_110 ? 0 : - V_64 ;
}
int
F_34 ( T_5 * V_47 , const char * V_155 , unsigned int V_156 ,
unsigned int V_157 , struct V_2 * V_3 )
{
unsigned int V_21 , V_158 = V_47 [ V_157 ] . V_68 / sizeof( T_2 ) ;
T_2 * V_19 = ( void * ) V_47 [ V_157 ] . V_88 ;
T_5 * V_159 ;
int V_24 ;
F_22 ( L_29 , V_79 ,
V_157 , V_158 , V_47 [ V_157 ] . V_160 ) ;
V_159 = V_47 + V_47 [ V_157 ] . V_160 ;
if ( V_159 -> V_161 == ~ 0UL )
return 0 ;
if ( ! V_3 -> V_17 . V_91 ) {
T_1 V_91 ;
if ( V_3 -> V_84 > V_92 )
V_91 = V_3 -> V_84 - V_92 / 2 ;
else
V_91 = V_3 -> V_84 / 2 ;
V_91 = ( T_1 ) V_3 -> V_83 + ( ( V_91 + 7 ) & - 8 ) ;
V_3 -> V_17 . V_91 = V_91 ;
F_22 ( L_30 , V_79 , V_91 ) ;
}
for ( V_21 = 0 ; V_21 < V_158 ; V_21 ++ ) {
V_24 = F_32 ( V_3 , F_17 ( V_19 [ V_21 ] . V_22 ) ,
( ( T_7 * ) V_47 [ V_156 ] . V_88
+ F_35 ( V_19 [ V_21 ] . V_22 ) ) ,
V_19 [ V_21 ] . V_23 , V_159 ,
( void * ) V_159 -> V_88 + V_19 [ V_21 ] . V_162 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
static void
F_36 ( struct V_2 * V_3 )
{
struct V_163 * V_164 = ( void * ) V_3 -> V_17 . V_61 -> V_88 ;
struct V_163 * V_165 = V_164 + V_3 -> V_17 . V_61 -> V_68 / sizeof ( * V_164 ) ;
struct V_163 V_166 , * V_167 , * V_168 , * V_169 , * V_170 ;
unsigned long V_171 = 0 , V_172 = 0 ;
for ( V_167 = V_164 ; V_167 < V_165 ; ++ V_167 )
if ( F_23 ( V_3 , V_167 -> V_173 ) )
++ V_171 ;
else
++ V_172 ;
for ( V_167 = V_164 ; V_167 < V_165 ; ++ V_167 ) {
for ( V_168 = V_167 + 1 ; V_168 < V_165 ; ++ V_168 ) {
if ( V_168 -> V_173 < V_167 -> V_173 ) {
V_166 = * V_167 ;
* V_167 = * V_168 ;
* V_168 = V_166 ;
}
}
}
if ( F_23 ( V_3 , V_164 -> V_173 ) ) {
V_170 = V_164 ;
V_169 = V_164 + V_171 ;
} else {
V_169 = V_164 ;
V_170 = V_164 + V_172 ;
}
F_22 ( L_31 , V_79 ,
V_3 -> V_6 , V_3 -> V_17 . V_91 , V_171 , V_172 ) ;
if ( V_172 > 0 ) {
V_3 -> V_17 . V_174 = F_37 ( V_3 -> V_6 , 0 , V_3 -> V_17 . V_91 ,
V_169 , V_169 + V_172 ) ;
F_22 ( L_32 , V_79 ,
V_3 -> V_17 . V_174 , V_169 , V_169 + V_172 ) ;
}
if ( V_171 > 0 ) {
V_3 -> V_17 . V_18 = F_37 ( V_3 -> V_6 , 0 , V_3 -> V_17 . V_91 ,
V_170 , V_170 + V_171 ) ;
F_22 ( L_33 , V_79 ,
V_3 -> V_17 . V_18 , V_170 , V_170 + V_171 ) ;
}
}
int
F_38 ( const T_3 * V_175 , const T_4 * V_47 , struct V_2 * V_3 )
{
F_22 ( L_34 , V_79 , V_3 -> V_170 ) ;
if ( V_3 -> V_17 . V_61 )
F_36 ( V_3 ) ;
#ifdef F_21
if ( V_3 -> V_17 . V_62 ) {
struct V_176 * V_164 =
(struct V_176 * )
V_3 -> V_17 . V_62 -> V_88 ;
struct V_176 * V_165 =
(struct V_176 * )
( V_3 -> V_17 . V_62 -> V_88 +
V_3 -> V_17 . V_62 -> V_68 ) ;
F_39 ( V_164 , V_165 ) ;
}
if ( V_3 -> V_17 . V_63 ) {
struct V_177 * V_164 =
(struct V_177 * )
V_3 -> V_17 . V_63 -> V_88 ;
struct V_177 * V_165 =
(struct V_177 * )
( V_3 -> V_17 . V_63 -> V_88 +
V_3 -> V_17 . V_63 -> V_68 ) ;
F_40 ( V_164 , V_165 ) ;
}
#endif
return 0 ;
}
void
F_41 ( struct V_2 * V_3 )
{
if ( V_3 -> V_17 . V_18 )
F_14 ( V_3 -> V_17 . V_18 ) ;
if ( V_3 -> V_17 . V_174 )
F_14 ( V_3 -> V_17 . V_174 ) ;
}
