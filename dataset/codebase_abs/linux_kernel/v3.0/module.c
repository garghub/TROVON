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
void *
F_13 ( unsigned long V_17 )
{
if ( ! V_17 )
return NULL ;
return F_14 ( V_17 ) ;
}
void
F_15 ( struct V_2 * V_3 , void * V_18 )
{
if ( V_3 && V_3 -> V_19 . V_20 &&
V_18 == V_3 -> V_21 ) {
F_16 ( V_3 -> V_19 . V_20 ) ;
V_3 -> V_19 . V_20 = NULL ;
}
F_17 ( V_18 ) ;
}
static int
F_18 ( const T_2 * V_22 , unsigned int V_23 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
if ( V_22 [ V_24 ] . V_25 == V_22 [ V_23 ] . V_25 && V_22 [ V_24 ] . V_26 == V_22 [ V_23 ] . V_26 )
return 1 ;
}
return 0 ;
}
static unsigned int
F_19 ( const T_2 * V_22 , unsigned int V_23 )
{
unsigned int V_24 , V_27 = 0 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
switch ( F_20 ( V_22 [ V_24 ] . V_25 ) ) {
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
if ( ! F_18 ( V_22 , V_24 ) )
V_27 ++ ;
break;
}
}
return V_27 ;
}
static unsigned int
F_21 ( const T_2 * V_22 , unsigned int V_23 )
{
unsigned int V_24 , V_27 = 0 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
switch ( F_20 ( V_22 [ V_24 ] . V_25 ) ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
if ( ! F_18 ( V_22 , V_24 ) )
V_27 ++ ;
break;
}
}
return V_27 ;
}
static unsigned int
F_22 ( const T_2 * V_22 , unsigned int V_23 )
{
unsigned int V_24 , V_27 = 0 ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
switch ( F_20 ( V_22 [ V_24 ] . V_25 ) ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_31 :
case V_34 :
case V_33 :
case V_32 :
case V_36 :
case V_35 :
case V_42 :
case V_43 :
case V_37 :
if ( ! F_18 ( V_22 , V_24 ) )
V_27 ++ ;
break;
}
}
return V_27 ;
}
int
F_23 ( T_3 * V_49 , T_4 * V_50 , char * V_51 ,
struct V_2 * V_3 )
{
unsigned long V_52 = 0 , V_53 = 0 , V_54 = 0 , V_55 = 0 ;
T_5 * V_56 , * V_57 = V_50 + V_49 -> V_58 ;
for ( V_56 = V_50 ; V_56 < V_57 ; ++ V_56 )
if ( strcmp ( L_6 , V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_60 = V_56 ;
else if ( strcmp ( L_7 , V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_61 = V_56 ;
else if ( strcmp ( L_8 , V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_62 = V_56 ;
else if ( strcmp ( L_9 , V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_63 = V_56 ;
else if ( strcmp ( L_10 , V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_64 = V_56 ;
#ifdef F_24
else if ( strcmp ( L_11 ,
V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_65 = V_56 ;
else if ( strcmp ( L_12 ,
V_51 + V_56 -> V_59 ) == 0 )
V_3 -> V_19 . V_66 = V_56 ;
#endif
if ( ! V_3 -> V_19 . V_60 || ! V_3 -> V_19 . V_61 || ! V_3 -> V_19 . V_62 || ! V_3 -> V_19 . V_63 ) {
F_4 ( V_5 L_13 , V_3 -> V_6 ) ;
return - V_67 ;
}
for ( V_56 = V_50 + 1 ; V_56 < V_57 ; ++ V_56 ) {
const T_2 * V_68 = ( void * ) V_49 + V_56 -> V_69 ;
unsigned long V_70 = V_56 -> V_71 / sizeof( T_2 ) ;
if ( V_56 -> V_72 != V_73 )
continue;
V_54 += F_19 ( V_68 , V_70 ) ;
V_55 += F_22 ( V_68 , V_70 ) ;
if ( strstr ( V_51 + V_56 -> V_59 , L_14 ) )
V_53 += F_21 ( V_68 , V_70 ) ;
else
V_52 += F_21 ( V_68 , V_70 ) ;
}
V_3 -> V_19 . V_60 -> V_72 = V_74 ;
V_3 -> V_19 . V_60 -> V_75 = V_76 | V_77 ;
V_3 -> V_19 . V_60 -> V_78 = 16 ;
V_3 -> V_19 . V_60 -> V_71 = V_52 * sizeof( struct V_8 ) ;
V_3 -> V_19 . V_61 -> V_72 = V_74 ;
V_3 -> V_19 . V_61 -> V_75 = V_76 | V_77 ;
V_3 -> V_19 . V_61 -> V_78 = 16 ;
V_3 -> V_19 . V_61 -> V_71 = V_53 * sizeof( struct V_8 ) ;
V_3 -> V_19 . V_62 -> V_72 = V_74 ;
V_3 -> V_19 . V_62 -> V_75 = V_79 | V_77 ;
V_3 -> V_19 . V_62 -> V_78 = 8 ;
V_3 -> V_19 . V_62 -> V_71 = V_54 * sizeof( struct V_80 ) ;
V_3 -> V_19 . V_63 -> V_72 = V_74 ;
V_3 -> V_19 . V_63 -> V_75 = V_77 ;
V_3 -> V_19 . V_63 -> V_78 = 8 ;
V_3 -> V_19 . V_63 -> V_71 = V_55 * sizeof( struct V_81 ) ;
F_25 ( L_15 ,
V_82 , V_3 -> V_19 . V_60 -> V_71 , V_3 -> V_19 . V_61 -> V_71 ,
V_3 -> V_19 . V_62 -> V_71 , V_3 -> V_19 . V_63 -> V_71 ) ;
return 0 ;
}
static inline int
F_26 ( const struct V_2 * V_3 , T_1 V_83 )
{
return V_83 - ( T_1 ) V_3 -> V_21 < V_3 -> V_84 ;
}
static inline int
F_27 ( const struct V_2 * V_3 , T_1 V_83 )
{
return V_83 - ( T_1 ) V_3 -> V_85 < V_3 -> V_86 ;
}
static inline int
F_28 ( const struct V_2 * V_3 , T_1 V_87 )
{
return F_26 ( V_3 , V_87 ) || F_27 ( V_3 , V_87 ) ;
}
static T_1
F_29 ( struct V_2 * V_3 , T_1 V_87 , int * V_88 )
{
struct V_80 * V_62 , * V_89 ;
if ( ! * V_88 )
return 0 ;
V_62 = ( void * ) V_3 -> V_19 . V_62 -> V_90 ;
for ( V_89 = V_62 ; V_89 < V_62 + V_3 -> V_19 . V_91 ; ++ V_89 )
if ( V_89 -> V_4 == V_87 )
goto V_92;
F_30 ( V_89 >= (struct V_80 * ) ( V_3 -> V_19 . V_62 -> V_90 + V_3 -> V_19 . V_62 -> V_71 ) ) ;
V_89 -> V_4 = V_87 ;
++ V_3 -> V_19 . V_91 ;
V_92:
return ( T_1 ) V_89 - V_3 -> V_19 . V_93 ;
}
static inline int
F_31 ( struct V_2 * V_3 , T_1 V_87 )
{
return V_87 - V_3 -> V_19 . V_93 + V_94 / 2 < V_94 ;
}
static T_1
F_32 ( struct V_2 * V_3 , const struct V_1 * V_1 , T_1 V_87 , int * V_88 )
{
struct V_8 * V_9 , * V_95 ;
T_1 V_10 , V_11 ;
if ( ! * V_88 )
return 0 ;
if ( F_26 ( V_3 , ( T_1 ) V_1 ) ) {
V_9 = ( void * ) V_3 -> V_19 . V_61 -> V_90 ;
V_95 = ( void * ) V_9 + V_3 -> V_19 . V_61 -> V_71 ;
} else {
V_9 = ( void * ) V_3 -> V_19 . V_60 -> V_90 ;
V_95 = ( void * ) V_9 + V_3 -> V_19 . V_60 -> V_71 ;
}
V_10 = ( ( T_1 * ) V_87 ) [ 0 ] ;
V_11 = ( ( T_1 * ) V_87 ) [ 1 ] ;
while ( V_9 -> F_1 [ 0 ] [ 0 ] ) {
if ( F_12 ( V_9 ) == V_10 )
goto V_92;
if ( ++ V_9 >= V_95 )
F_33 () ;
}
* V_9 = V_96 ;
if ( ! F_11 ( V_3 , V_9 , V_10 , V_11 ) ) {
* V_88 = 0 ;
return 0 ;
}
#if V_97
if ( F_12 ( V_9 ) != V_10 ) {
F_4 ( L_16 ,
V_82 , V_10 , F_12 ( V_9 ) ) ;
* V_88 = 0 ;
return 0 ;
}
#endif
V_92:
return ( T_1 ) V_9 ;
}
static T_1
F_34 ( struct V_2 * V_3 , T_1 V_87 , int * V_88 )
{
struct V_81 * V_81 = ( void * ) V_3 -> V_19 . V_63 -> V_90 ;
if ( ! * V_88 )
return 0 ;
if ( ! V_87 ) {
F_4 ( V_5 L_17 , V_3 -> V_6 ) ;
return 0 ;
}
if ( ! F_28 ( V_3 , V_87 ) )
return V_87 ;
while ( V_81 -> V_98 ) {
if ( V_81 -> V_98 == V_87 )
return ( T_1 ) V_81 ;
if ( ( T_1 ) ++ V_81 >= V_3 -> V_19 . V_63 -> V_90 + V_3 -> V_19 . V_63 -> V_71 )
F_33 () ;
}
V_81 -> V_98 = V_87 ;
V_81 -> V_93 = V_3 -> V_19 . V_93 ;
return ( T_1 ) V_81 ;
}
static inline int
F_35 ( struct V_2 * V_3 , T_6 V_99 , T_7 * V_100 , T_1 V_101 ,
T_5 * V_102 , void * V_103 )
{
enum V_104 V_105 = ( V_99 >> V_106 ) & V_107 ;
enum V_108 V_109 = ( V_99 >> V_110 ) & V_111 ;
T_1 V_4 ;
int V_112 = 1 ;
V_4 = V_100 -> V_113 + V_101 ;
switch ( V_109 ) {
case V_114 :
case V_115 :
break;
case V_116 : V_4 -= V_3 -> V_19 . V_93 ; break;
case V_117 : V_4 = F_29 ( V_3 , V_4 , & V_112 ) ; break;
case V_118 : V_4 = F_32 ( V_3 , V_103 , V_4 , & V_112 ) ; break;
case V_119 : V_4 = F_34 ( V_3 , V_4 , & V_112 ) ; break;
case V_120 : V_4 -= V_102 -> V_90 ; break;
case V_121 : V_4 = F_29 ( V_3 , F_34 ( V_3 , V_4 , & V_112 ) , & V_112 ) ; break;
case V_122 :
switch ( V_99 ) {
case V_37 :
if ( ( F_26 ( V_3 , V_4 ) && F_27 ( V_3 , ( T_1 ) V_103 ) ) ||
( F_27 ( V_3 , V_4 ) && F_26 ( V_3 , ( T_1 ) V_103 ) ) ) {
T_1 V_123 = ( ( V_12 ) V_4 - ( V_12 ) V_103 ) / 16 ;
if ( V_123 + ( 1 << 20 ) >= ( 1 << 21 ) ) {
V_4 = F_34 ( V_3 , V_4 , & V_112 ) ;
V_4 = F_32 ( V_3 , V_103 , V_4 , & V_112 ) ;
}
} else if ( ! F_28 ( V_3 , V_4 ) )
V_4 = F_32 ( V_3 , V_103 , V_4 , & V_112 ) ;
default:
V_4 -= F_1 ( V_103 ) ;
break;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_4 -= ( T_1 ) V_103 ;
break;
}
switch ( V_99 ) {
case V_128 : V_105 = V_129 ; break;
case V_37 : V_105 = V_130 ; break;
case V_131 : V_105 = V_132 ; break;
case V_133 : V_105 = V_134 ; break;
default: break;
}
break;
case V_135 :
V_4 -= ( T_1 ) ( F_26 ( V_3 , V_4 ) ? V_3 -> V_21 : V_3 -> V_85 ) ;
break;
case V_136 :
F_33 () ;
break;
case V_137 :
if ( V_99 == V_138 ) {
if ( ! F_28 ( V_3 , V_4 ) ) {
F_4 ( V_5 L_18
L_19 , V_82 ,
V_139 [ V_99 ] , ( unsigned long ) V_4 ) ;
return - V_67 ;
}
V_105 = V_130 ;
}
V_4 -= F_1 ( V_103 ) ;
break;
case V_140 :
switch ( V_99 ) {
case V_42 :
case V_43 :
V_4 = F_34 ( V_3 , F_32 ( V_3 , V_103 , V_4 , & V_112 ) , & V_112 ) ;
V_105 = V_141 ;
if ( V_99 == V_42 )
V_105 = V_142 ;
break;
case V_143 :
V_4 = V_101 - V_100 -> V_113 ;
V_105 = V_144 ;
break;
case V_29 :
if ( F_31 ( V_3 , V_4 ) )
V_4 -= V_3 -> V_19 . V_93 ;
else
V_4 = F_29 ( V_3 , V_4 , & V_112 ) ;
V_105 = V_145 ;
break;
case V_146 :
if ( F_31 ( V_3 , V_4 ) ) {
F_25 ( L_20 , V_82 , V_103 ) ;
F_9 ( ( V_7 ) V_103 , 0x1fff80fe000UL , 0x10000000000UL ) ;
}
return 0 ;
default:
if ( V_139 [ V_99 ] )
F_4 ( V_5 L_21 ,
V_3 -> V_6 , V_139 [ V_99 ] ) ;
else
F_4 ( V_5 L_22 ,
V_3 -> V_6 , V_99 ) ;
return - V_67 ;
}
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
F_4 ( V_5 L_23 ,
V_3 -> V_6 , V_139 [ V_99 ] ? V_139 [ V_99 ] : L_24 ) ;
return - V_67 ;
default:
F_4 ( V_5 L_25 , V_3 -> V_6 , V_99 ) ;
return - V_67 ;
}
if ( ! V_112 )
return - V_67 ;
F_25 ( L_26 , V_82 , V_103 , V_4 ,
V_139 [ V_99 ] ? V_139 [ V_99 ] : L_24 , V_100 -> V_113 + V_101 ) ;
switch ( V_105 ) {
case V_130 : V_112 = F_10 ( V_3 , V_103 , ( V_12 ) V_4 / 16 ) ; break;
case V_145 : V_112 = F_8 ( V_3 , V_103 , V_4 ) ; break;
case V_144 : V_112 = F_3 ( V_3 , V_103 , V_4 ) ; break;
case V_129 : V_112 = F_6 ( V_3 , V_103 , ( V_12 ) V_4 / 16 ) ; break;
case V_153 : F_36 ( V_4 , ( V_154 * ) V_103 ) ; break;
case V_141 : F_36 ( V_4 , ( T_1 * ) V_103 ) ; break;
case V_155 :
case V_142 :
case V_156 :
case V_132 :
case V_134 :
F_4 ( V_5 L_27 ,
V_3 -> V_6 , V_105 , V_139 [ V_99 ] ? V_139 [ V_99 ] : L_24 ) ;
return - V_67 ;
default:
F_4 ( V_5 L_28 ,
V_3 -> V_6 , V_139 [ V_99 ] ? V_139 [ V_99 ] : L_24 , V_105 ) ;
return - V_67 ;
}
return V_112 ? 0 : - V_67 ;
}
int
F_37 ( T_5 * V_50 , const char * V_157 , unsigned int V_158 ,
unsigned int V_159 , struct V_2 * V_3 )
{
unsigned int V_24 , V_160 = V_50 [ V_159 ] . V_71 / sizeof( T_2 ) ;
T_2 * V_22 = ( void * ) V_50 [ V_159 ] . V_90 ;
T_5 * V_161 ;
int V_27 ;
F_25 ( L_29 , V_82 ,
V_159 , V_160 , V_50 [ V_159 ] . V_162 ) ;
V_161 = V_50 + V_50 [ V_159 ] . V_162 ;
if ( V_161 -> V_163 == ~ 0UL )
return 0 ;
if ( ! V_3 -> V_19 . V_93 ) {
T_1 V_93 ;
if ( V_3 -> V_86 > V_94 )
V_93 = V_3 -> V_86 - V_94 / 2 ;
else
V_93 = V_3 -> V_86 / 2 ;
V_93 = ( T_1 ) V_3 -> V_85 + ( ( V_93 + 7 ) & - 8 ) ;
V_3 -> V_19 . V_93 = V_93 ;
F_25 ( L_30 , V_82 , V_93 ) ;
}
for ( V_24 = 0 ; V_24 < V_160 ; V_24 ++ ) {
V_27 = F_35 ( V_3 , F_20 ( V_22 [ V_24 ] . V_25 ) ,
( ( T_7 * ) V_50 [ V_158 ] . V_90
+ F_38 ( V_22 [ V_24 ] . V_25 ) ) ,
V_22 [ V_24 ] . V_26 , V_161 ,
( void * ) V_161 -> V_90 + V_22 [ V_24 ] . V_164 ) ;
if ( V_27 < 0 )
return V_27 ;
}
return 0 ;
}
int
F_39 ( T_5 * V_50 , const char * V_157 , unsigned int V_158 ,
unsigned int V_159 , struct V_2 * V_3 )
{
F_4 ( V_5 L_31 , V_3 -> V_6 , V_159 ) ;
return - V_67 ;
}
static void
F_40 ( struct V_2 * V_3 )
{
struct V_165 * V_166 = ( void * ) V_3 -> V_19 . V_64 -> V_90 ;
struct V_165 * V_167 = V_166 + V_3 -> V_19 . V_64 -> V_71 / sizeof ( * V_166 ) ;
struct V_165 V_168 , * V_169 , * V_170 , * V_171 , * V_172 ;
unsigned long V_173 = 0 , V_174 = 0 ;
for ( V_169 = V_166 ; V_169 < V_167 ; ++ V_169 )
if ( F_26 ( V_3 , V_169 -> V_175 ) )
++ V_173 ;
else
++ V_174 ;
for ( V_169 = V_166 ; V_169 < V_167 ; ++ V_169 ) {
for ( V_170 = V_169 + 1 ; V_170 < V_167 ; ++ V_170 ) {
if ( V_170 -> V_175 < V_169 -> V_175 ) {
V_168 = * V_169 ;
* V_169 = * V_170 ;
* V_170 = V_168 ;
}
}
}
if ( F_26 ( V_3 , V_166 -> V_175 ) ) {
V_172 = V_166 ;
V_171 = V_166 + V_173 ;
} else {
V_171 = V_166 ;
V_172 = V_166 + V_174 ;
}
F_25 ( L_32 , V_82 ,
V_3 -> V_6 , V_3 -> V_19 . V_93 , V_173 , V_174 ) ;
if ( V_174 > 0 ) {
V_3 -> V_19 . V_176 = F_41 ( V_3 -> V_6 , 0 , V_3 -> V_19 . V_93 ,
V_171 , V_171 + V_174 ) ;
F_25 ( L_33 , V_82 ,
V_3 -> V_19 . V_176 , V_171 , V_171 + V_174 ) ;
}
if ( V_173 > 0 ) {
V_3 -> V_19 . V_20 = F_41 ( V_3 -> V_6 , 0 , V_3 -> V_19 . V_93 ,
V_172 , V_172 + V_173 ) ;
F_25 ( L_34 , V_82 ,
V_3 -> V_19 . V_20 , V_172 , V_172 + V_173 ) ;
}
}
int
F_42 ( const T_3 * V_177 , const T_4 * V_50 , struct V_2 * V_3 )
{
F_25 ( L_35 , V_82 , V_3 -> V_172 ) ;
if ( V_3 -> V_19 . V_64 )
F_40 ( V_3 ) ;
#ifdef F_24
if ( V_3 -> V_19 . V_65 ) {
struct V_178 * V_166 =
(struct V_178 * )
V_3 -> V_19 . V_65 -> V_90 ;
struct V_178 * V_167 =
(struct V_178 * )
( V_3 -> V_19 . V_65 -> V_90 +
V_3 -> V_19 . V_65 -> V_71 ) ;
F_43 ( V_166 , V_167 ) ;
}
if ( V_3 -> V_19 . V_66 ) {
struct V_179 * V_166 =
(struct V_179 * )
V_3 -> V_19 . V_66 -> V_90 ;
struct V_179 * V_167 =
(struct V_179 * )
( V_3 -> V_19 . V_66 -> V_90 +
V_3 -> V_19 . V_66 -> V_71 ) ;
F_44 ( V_166 , V_167 ) ;
}
#endif
return 0 ;
}
void
F_45 ( struct V_2 * V_3 )
{
if ( V_3 -> V_19 . V_20 )
F_16 ( V_3 -> V_19 . V_20 ) ;
if ( V_3 -> V_19 . V_176 )
F_16 ( V_3 -> V_19 . V_176 ) ;
}
