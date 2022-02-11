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
if ( ! V_3 -> V_17 . V_57 || ! V_3 -> V_17 . V_58 || ! V_3 -> V_17 . V_59 || ! V_3 -> V_17 . V_60 ) {
F_4 ( V_5 L_11 , V_3 -> V_6 ) ;
return - V_62 ;
}
for ( V_53 = V_47 + 1 ; V_53 < V_54 ; ++ V_53 ) {
const T_2 * V_63 = ( void * ) V_46 + V_53 -> V_64 ;
unsigned long V_65 = V_53 -> V_66 / sizeof( T_2 ) ;
if ( V_53 -> V_67 != V_68 )
continue;
V_51 += F_16 ( V_63 , V_65 ) ;
V_52 += F_19 ( V_63 , V_65 ) ;
if ( strstr ( V_48 + V_53 -> V_56 , L_12 ) )
V_50 += F_18 ( V_63 , V_65 ) ;
else
V_49 += F_18 ( V_63 , V_65 ) ;
}
V_3 -> V_17 . V_57 -> V_67 = V_69 ;
V_3 -> V_17 . V_57 -> V_70 = V_71 | V_72 ;
V_3 -> V_17 . V_57 -> V_73 = 16 ;
V_3 -> V_17 . V_57 -> V_66 = V_49 * sizeof( struct V_8 ) ;
V_3 -> V_17 . V_58 -> V_67 = V_69 ;
V_3 -> V_17 . V_58 -> V_70 = V_71 | V_72 ;
V_3 -> V_17 . V_58 -> V_73 = 16 ;
V_3 -> V_17 . V_58 -> V_66 = V_50 * sizeof( struct V_8 ) ;
V_3 -> V_17 . V_59 -> V_67 = V_69 ;
V_3 -> V_17 . V_59 -> V_70 = V_74 | V_72 ;
V_3 -> V_17 . V_59 -> V_73 = 8 ;
V_3 -> V_17 . V_59 -> V_66 = V_51 * sizeof( struct V_75 ) ;
V_3 -> V_17 . V_60 -> V_67 = V_69 ;
V_3 -> V_17 . V_60 -> V_70 = V_72 ;
V_3 -> V_17 . V_60 -> V_73 = 8 ;
V_3 -> V_17 . V_60 -> V_66 = V_52 * sizeof( struct V_76 ) ;
F_21 ( L_13 ,
V_77 , V_3 -> V_17 . V_57 -> V_66 , V_3 -> V_17 . V_58 -> V_66 ,
V_3 -> V_17 . V_59 -> V_66 , V_3 -> V_17 . V_60 -> V_66 ) ;
return 0 ;
}
static inline int
F_22 ( const struct V_2 * V_3 , T_1 V_78 )
{
return V_78 - ( T_1 ) V_3 -> V_79 . V_80 < V_3 -> V_79 . V_81 ;
}
static inline int
F_23 ( const struct V_2 * V_3 , T_1 V_78 )
{
return V_78 - ( T_1 ) V_3 -> V_82 . V_80 < V_3 -> V_82 . V_81 ;
}
static inline int
F_24 ( const struct V_2 * V_3 , T_1 V_83 )
{
return F_22 ( V_3 , V_83 ) || F_23 ( V_3 , V_83 ) ;
}
static T_1
F_25 ( struct V_2 * V_3 , T_1 V_83 , int * V_84 )
{
struct V_75 * V_59 , * V_85 ;
if ( ! * V_84 )
return 0 ;
V_59 = ( void * ) V_3 -> V_17 . V_59 -> V_86 ;
for ( V_85 = V_59 ; V_85 < V_59 + V_3 -> V_17 . V_87 ; ++ V_85 )
if ( V_85 -> V_4 == V_83 )
goto V_88;
F_26 ( V_85 >= (struct V_75 * ) ( V_3 -> V_17 . V_59 -> V_86 + V_3 -> V_17 . V_59 -> V_66 ) ) ;
V_85 -> V_4 = V_83 ;
++ V_3 -> V_17 . V_87 ;
V_88:
return ( T_1 ) V_85 - V_3 -> V_17 . V_89 ;
}
static inline int
F_27 ( struct V_2 * V_3 , T_1 V_83 )
{
return V_83 - V_3 -> V_17 . V_89 + V_90 / 2 < V_90 ;
}
static T_1
F_28 ( struct V_2 * V_3 , const struct V_1 * V_1 , T_1 V_83 , int * V_84 )
{
struct V_8 * V_9 , * V_91 ;
T_1 V_10 , V_11 ;
if ( ! * V_84 )
return 0 ;
if ( F_22 ( V_3 , ( T_1 ) V_1 ) ) {
V_9 = ( void * ) V_3 -> V_17 . V_58 -> V_86 ;
V_91 = ( void * ) V_9 + V_3 -> V_17 . V_58 -> V_66 ;
} else {
V_9 = ( void * ) V_3 -> V_17 . V_57 -> V_86 ;
V_91 = ( void * ) V_9 + V_3 -> V_17 . V_57 -> V_66 ;
}
V_10 = ( ( T_1 * ) V_83 ) [ 0 ] ;
V_11 = ( ( T_1 * ) V_83 ) [ 1 ] ;
while ( V_9 -> F_1 [ 0 ] [ 0 ] ) {
if ( F_12 ( V_9 ) == V_10 )
goto V_88;
if ( ++ V_9 >= V_91 )
F_29 () ;
}
* V_9 = V_92 ;
if ( ! F_11 ( V_3 , V_9 , V_10 , V_11 ) ) {
* V_84 = 0 ;
return 0 ;
}
#if V_93
if ( F_12 ( V_9 ) != V_10 ) {
F_4 ( L_14 ,
V_77 , V_10 , F_12 ( V_9 ) ) ;
* V_84 = 0 ;
return 0 ;
}
#endif
V_88:
return ( T_1 ) V_9 ;
}
static T_1
F_30 ( struct V_2 * V_3 , T_1 V_83 , int * V_84 )
{
struct V_76 * V_76 = ( void * ) V_3 -> V_17 . V_60 -> V_86 ;
if ( ! * V_84 )
return 0 ;
if ( ! V_83 ) {
F_4 ( V_5 L_15 , V_3 -> V_6 ) ;
return 0 ;
}
if ( ! F_24 ( V_3 , V_83 ) )
return V_83 ;
while ( V_76 -> V_94 ) {
if ( V_76 -> V_94 == V_83 )
return ( T_1 ) V_76 ;
if ( ( T_1 ) ++ V_76 >= V_3 -> V_17 . V_60 -> V_86 + V_3 -> V_17 . V_60 -> V_66 )
F_29 () ;
}
V_76 -> V_94 = V_83 ;
V_76 -> V_89 = V_3 -> V_17 . V_89 ;
return ( T_1 ) V_76 ;
}
static inline int
F_31 ( struct V_2 * V_3 , T_6 V_95 , T_7 * V_96 , T_1 V_97 ,
T_5 * V_98 , void * V_99 )
{
enum V_100 V_101 = ( V_95 >> V_102 ) & V_103 ;
enum V_104 V_105 = ( V_95 >> V_106 ) & V_107 ;
T_1 V_4 ;
int V_108 = 1 ;
V_4 = V_96 -> V_109 + V_97 ;
switch ( V_105 ) {
case V_110 :
case V_111 :
break;
case V_112 : V_4 -= V_3 -> V_17 . V_89 ; break;
case V_113 : V_4 = F_25 ( V_3 , V_4 , & V_108 ) ; break;
case V_114 : V_4 = F_28 ( V_3 , V_99 , V_4 , & V_108 ) ; break;
case V_115 : V_4 = F_30 ( V_3 , V_4 , & V_108 ) ; break;
case V_116 : V_4 -= V_98 -> V_86 ; break;
case V_117 : V_4 = F_25 ( V_3 , F_30 ( V_3 , V_4 , & V_108 ) , & V_108 ) ; break;
case V_118 :
switch ( V_95 ) {
case V_34 :
if ( ( F_22 ( V_3 , V_4 ) && F_23 ( V_3 , ( T_1 ) V_99 ) ) ||
( F_23 ( V_3 , V_4 ) && F_22 ( V_3 , ( T_1 ) V_99 ) ) ) {
T_1 V_119 = ( ( V_12 ) V_4 - ( V_12 ) V_99 ) / 16 ;
if ( V_119 + ( 1 << 20 ) >= ( 1 << 21 ) ) {
V_4 = F_30 ( V_3 , V_4 , & V_108 ) ;
V_4 = F_28 ( V_3 , V_99 , V_4 , & V_108 ) ;
}
} else if ( ! F_24 ( V_3 , V_4 ) )
V_4 = F_28 ( V_3 , V_99 , V_4 , & V_108 ) ;
default:
V_4 -= F_1 ( V_99 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_4 -= ( T_1 ) V_99 ;
break;
}
switch ( V_95 ) {
case V_124 : V_101 = V_125 ; break;
case V_34 : V_101 = V_126 ; break;
case V_127 : V_101 = V_128 ; break;
case V_129 : V_101 = V_130 ; break;
default: break;
}
break;
case V_131 :
V_4 -= ( T_1 ) ( F_22 ( V_3 , V_4 ) ? V_3 -> V_79 . V_80 : V_3 -> V_82 . V_80 ) ;
break;
case V_132 :
F_29 () ;
break;
case V_133 :
if ( V_95 == V_134 ) {
if ( ! F_24 ( V_3 , V_4 ) ) {
F_4 ( V_5 L_16
L_17 , V_77 ,
V_135 [ V_95 ] , ( unsigned long ) V_4 ) ;
return - V_62 ;
}
V_101 = V_126 ;
}
V_4 -= F_1 ( V_99 ) ;
break;
case V_136 :
switch ( V_95 ) {
case V_39 :
case V_40 :
V_4 = F_30 ( V_3 , F_28 ( V_3 , V_99 , V_4 , & V_108 ) , & V_108 ) ;
V_101 = V_137 ;
if ( V_95 == V_39 )
V_101 = V_138 ;
break;
case V_139 :
V_4 = V_97 - V_96 -> V_109 ;
V_101 = V_140 ;
break;
case V_26 :
if ( F_27 ( V_3 , V_4 ) )
V_4 -= V_3 -> V_17 . V_89 ;
else
V_4 = F_25 ( V_3 , V_4 , & V_108 ) ;
V_101 = V_141 ;
break;
case V_142 :
if ( F_27 ( V_3 , V_4 ) ) {
F_21 ( L_18 , V_77 , V_99 ) ;
F_9 ( ( V_7 ) V_99 , 0x1fff80fe000UL , 0x10000000000UL ) ;
}
return 0 ;
default:
if ( V_135 [ V_95 ] )
F_4 ( V_5 L_19 ,
V_3 -> V_6 , V_135 [ V_95 ] ) ;
else
F_4 ( V_5 L_20 ,
V_3 -> V_6 , V_95 ) ;
return - V_62 ;
}
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
F_4 ( V_5 L_21 ,
V_3 -> V_6 , V_135 [ V_95 ] ? V_135 [ V_95 ] : L_22 ) ;
return - V_62 ;
default:
F_4 ( V_5 L_23 , V_3 -> V_6 , V_95 ) ;
return - V_62 ;
}
if ( ! V_108 )
return - V_62 ;
F_21 ( L_24 , V_77 , V_99 , V_4 ,
V_135 [ V_95 ] ? V_135 [ V_95 ] : L_22 , V_96 -> V_109 + V_97 ) ;
switch ( V_101 ) {
case V_126 : V_108 = F_10 ( V_3 , V_99 , ( V_12 ) V_4 / 16 ) ; break;
case V_141 : V_108 = F_8 ( V_3 , V_99 , V_4 ) ; break;
case V_140 : V_108 = F_3 ( V_3 , V_99 , V_4 ) ; break;
case V_125 : V_108 = F_6 ( V_3 , V_99 , ( V_12 ) V_4 / 16 ) ; break;
case V_149 : F_32 ( V_4 , ( V_150 * ) V_99 ) ; break;
case V_137 : F_32 ( V_4 , ( T_1 * ) V_99 ) ; break;
case V_151 :
case V_138 :
case V_152 :
case V_128 :
case V_130 :
F_4 ( V_5 L_25 ,
V_3 -> V_6 , V_101 , V_135 [ V_95 ] ? V_135 [ V_95 ] : L_22 ) ;
return - V_62 ;
default:
F_4 ( V_5 L_26 ,
V_3 -> V_6 , V_135 [ V_95 ] ? V_135 [ V_95 ] : L_22 , V_101 ) ;
return - V_62 ;
}
return V_108 ? 0 : - V_62 ;
}
int
F_33 ( T_5 * V_47 , const char * V_153 , unsigned int V_154 ,
unsigned int V_155 , struct V_2 * V_3 )
{
unsigned int V_21 , V_156 = V_47 [ V_155 ] . V_66 / sizeof( T_2 ) ;
T_2 * V_19 = ( void * ) V_47 [ V_155 ] . V_86 ;
T_5 * V_157 ;
int V_24 ;
F_21 ( L_27 , V_77 ,
V_155 , V_156 , V_47 [ V_155 ] . V_158 ) ;
V_157 = V_47 + V_47 [ V_155 ] . V_158 ;
if ( V_157 -> V_159 == ~ 0UL )
return 0 ;
if ( ! V_3 -> V_17 . V_89 ) {
T_1 V_89 ;
if ( V_3 -> V_82 . V_81 > V_90 )
V_89 = V_3 -> V_82 . V_81 - V_90 / 2 ;
else
V_89 = V_3 -> V_82 . V_81 / 2 ;
V_89 = ( T_1 ) V_3 -> V_82 . V_80 + ( ( V_89 + 7 ) & - 8 ) ;
V_3 -> V_17 . V_89 = V_89 ;
F_21 ( L_28 , V_77 , V_89 ) ;
}
for ( V_21 = 0 ; V_21 < V_156 ; V_21 ++ ) {
V_24 = F_31 ( V_3 , F_17 ( V_19 [ V_21 ] . V_22 ) ,
( ( T_7 * ) V_47 [ V_154 ] . V_86
+ F_34 ( V_19 [ V_21 ] . V_22 ) ) ,
V_19 [ V_21 ] . V_23 , V_157 ,
( void * ) V_157 -> V_86 + V_19 [ V_21 ] . V_160 ) ;
if ( V_24 < 0 )
return V_24 ;
}
return 0 ;
}
static void
F_35 ( struct V_2 * V_3 )
{
struct V_161 * V_162 = ( void * ) V_3 -> V_17 . V_61 -> V_86 ;
struct V_161 * V_163 = V_162 + V_3 -> V_17 . V_61 -> V_66 / sizeof ( * V_162 ) ;
struct V_161 V_164 , * V_165 , * V_166 , * V_167 , * V_168 ;
unsigned long V_169 = 0 , V_170 = 0 ;
for ( V_165 = V_162 ; V_165 < V_163 ; ++ V_165 )
if ( F_22 ( V_3 , V_165 -> V_171 ) )
++ V_169 ;
else
++ V_170 ;
for ( V_165 = V_162 ; V_165 < V_163 ; ++ V_165 ) {
for ( V_166 = V_165 + 1 ; V_166 < V_163 ; ++ V_166 ) {
if ( V_166 -> V_171 < V_165 -> V_171 ) {
V_164 = * V_165 ;
* V_165 = * V_166 ;
* V_166 = V_164 ;
}
}
}
if ( F_22 ( V_3 , V_162 -> V_171 ) ) {
V_168 = V_162 ;
V_167 = V_162 + V_169 ;
} else {
V_167 = V_162 ;
V_168 = V_162 + V_170 ;
}
F_21 ( L_29 , V_77 ,
V_3 -> V_6 , V_3 -> V_17 . V_89 , V_169 , V_170 ) ;
if ( V_170 > 0 ) {
V_3 -> V_17 . V_172 = F_36 ( V_3 -> V_6 , 0 , V_3 -> V_17 . V_89 ,
V_167 , V_167 + V_170 ) ;
F_21 ( L_30 , V_77 ,
V_3 -> V_17 . V_172 , V_167 , V_167 + V_170 ) ;
}
if ( V_169 > 0 ) {
V_3 -> V_17 . V_18 = F_36 ( V_3 -> V_6 , 0 , V_3 -> V_17 . V_89 ,
V_168 , V_168 + V_169 ) ;
F_21 ( L_31 , V_77 ,
V_3 -> V_17 . V_18 , V_168 , V_168 + V_169 ) ;
}
}
int
F_37 ( const T_3 * V_173 , const T_4 * V_47 , struct V_2 * V_3 )
{
F_21 ( L_32 , V_77 , V_3 -> V_168 ) ;
if ( V_3 -> V_17 . V_61 )
F_35 ( V_3 ) ;
return 0 ;
}
void
F_38 ( struct V_2 * V_3 )
{
if ( V_3 -> V_17 . V_18 )
F_14 ( V_3 -> V_17 . V_18 ) ;
if ( V_3 -> V_17 . V_172 )
F_14 ( V_3 -> V_17 . V_172 ) ;
}
