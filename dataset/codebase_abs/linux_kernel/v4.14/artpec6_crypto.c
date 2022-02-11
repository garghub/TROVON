static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
T_1 V_6 )
{
while ( V_6 && V_2 -> V_4 ) {
T_1 V_7 ;
F_3 ( V_2 -> V_5 > V_2 -> V_4 -> V_8 ) ;
V_7 = F_4 ( V_6 , ( T_1 ) V_2 -> V_4 -> V_8 - V_2 -> V_5 ) ;
V_6 -= V_7 ;
V_2 -> V_5 += V_7 ;
if ( V_2 -> V_5 == V_2 -> V_4 -> V_8 ) {
V_2 -> V_4 = F_5 ( V_2 -> V_4 ) ;
V_2 -> V_5 = 0 ;
}
}
return V_6 ;
}
static T_1
F_6 ( const struct V_1 * V_2 )
{
F_3 ( V_2 -> V_4 -> V_8 == V_2 -> V_5 ) ;
return V_2 -> V_4 -> V_8 - V_2 -> V_5 ;
}
static T_2
F_7 ( const struct V_1 * V_2 )
{
return F_8 ( V_2 -> V_4 ) + V_2 -> V_5 ;
}
static void
F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
F_10 (b, next, &dma->bounce_buffers, list) {
F_11 ( L_1 ,
V_14 , V_14 -> V_8 , V_14 -> V_5 , V_14 -> V_16 ) ;
F_12 ( V_14 -> V_4 ,
1 ,
V_14 -> V_16 ,
V_14 -> V_8 ,
V_14 -> V_5 ) ;
F_13 ( & V_14 -> V_17 ) ;
F_14 ( V_14 ) ;
}
}
static inline bool F_15 ( void )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
int V_21 = V_19 -> V_22 ;
return V_21 > 6 ;
}
static int F_17 ( struct V_9 * V_23 )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
int V_24 = - V_25 ;
F_18 ( & V_19 -> V_26 ) ;
if ( ! F_15 () ) {
F_19 ( & V_23 -> V_17 , & V_19 -> V_27 ) ;
F_20 ( V_23 ) ;
V_24 = - V_28 ;
} else if ( V_23 -> V_23 -> V_29 & V_30 ) {
F_19 ( & V_23 -> V_17 , & V_19 -> V_31 ) ;
} else {
F_21 ( V_23 ) ;
}
F_22 ( & V_19 -> V_26 ) ;
return V_24 ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
void T_3 * V_34 = V_19 -> V_34 ;
struct V_11 * V_12 = V_10 -> V_12 ;
T_4 V_35 , V_36 , V_37 ;
F_23 () ;
V_35 = F_24 ( V_38 , V_12 -> V_39 - 1 ) |
F_24 ( V_40 , V_12 -> V_41 >> 6 ) ;
V_36 = F_24 ( V_42 , V_12 -> V_39 - 1 ) |
F_24 ( V_43 , V_12 -> V_44 >> 6 ) ;
V_37 = F_24 ( V_45 , V_12 -> V_46 - 1 ) |
F_24 ( V_47 , V_12 -> V_48 >> 6 ) ;
if ( V_33 == V_49 ) {
F_25 ( V_35 , V_34 + V_50 ) ;
F_25 ( V_36 , V_34 + V_51 ) ;
F_25 ( V_52 , V_34 + V_53 ) ;
} else {
F_25 ( V_35 , V_34 + V_54 ) ;
F_25 ( V_36 , V_34 + V_55 ) ;
F_25 ( V_52 , V_34 + V_56 ) ;
}
F_25 ( V_37 , V_34 + V_57 ) ;
F_25 ( V_58 , V_34 + V_59 ) ;
V_19 -> V_22 ++ ;
}
static void
F_26 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
V_12 -> V_46 = 0 ;
V_12 -> V_39 = 0 ;
V_12 -> V_60 = 0 ;
F_27 ( & V_12 -> V_61 ) ;
}
static bool F_28 ( void )
{
#ifdef F_29
return F_30 ( & V_62 , 1 ) ;
#else
return false ;
#endif
}
static int
F_31 ( struct V_9 * V_10 ,
T_2 V_63 , T_1 V_64 , bool V_65 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_66 * V_67 ;
if ( V_12 -> V_46 >= V_68 ||
F_28 () ) {
F_32 ( L_2 ) ;
return - V_69 ;
}
V_67 = & V_12 -> V_70 [ V_12 -> V_46 ++ ] ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_71 . V_72 = 0 ;
V_67 -> V_71 . V_65 = V_65 ;
V_67 -> V_73 . V_64 = V_64 ;
V_67 -> V_73 . V_16 = V_63 ;
return 0 ;
}
static int
F_33 ( struct V_9 * V_10 ,
void * V_74 , unsigned int V_64 , bool V_65 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_66 * V_67 ;
if ( V_12 -> V_46 >= V_68 ||
F_28 () ) {
F_32 ( L_2 ) ;
return - V_69 ;
} else if ( V_64 > 7 || V_64 < 1 ) {
return - V_75 ;
}
V_67 = & V_12 -> V_70 [ V_12 -> V_46 ++ ] ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_71 . V_72 = 1 ;
V_67 -> V_71 . V_76 = V_64 ;
V_67 -> V_71 . V_65 = V_65 ;
memcpy ( V_67 -> V_77 . V_73 , V_74 , V_64 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 ,
struct V_78 * V_78 , T_1 V_5 ,
T_1 V_79 ,
enum V_80 V_81 ,
T_2 * V_82 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_83 * V_84 = V_20 ;
struct V_85 * V_86 ;
T_2 V_87 ;
* V_82 = 0 ;
if ( V_12 -> V_60 >= F_35 ( V_12 -> V_88 ) )
return - V_89 ;
V_87 = F_36 ( V_84 , V_78 , V_5 , V_79 , V_81 ) ;
if ( F_37 ( V_84 , V_87 ) )
return - V_89 ;
V_86 = & V_12 -> V_88 [ V_12 -> V_60 ++ ] ;
V_86 -> V_79 = V_79 ;
V_86 -> V_87 = V_87 ;
V_86 -> V_81 = V_81 ;
* V_82 = V_87 ;
return 0 ;
}
static int
F_38 ( struct V_9 * V_10 ,
void * V_90 , T_1 V_79 ,
enum V_80 V_81 ,
T_2 * V_82 )
{
struct V_78 * V_78 = F_39 ( V_90 ) ;
T_1 V_5 = ( V_91 ) V_90 & ~ V_92 ;
return F_34 ( V_10 , V_78 , V_5 , V_79 , V_81 ,
V_82 ) ;
}
static int
F_40 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
int V_24 ;
V_24 = F_38 ( V_10 , V_12 -> V_93 ,
sizeof( V_12 -> V_93 [ 0 ] ) * V_12 -> V_39 ,
V_94 , & V_12 -> V_41 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_38 ( V_10 , V_12 -> V_70 ,
sizeof( V_12 -> V_70 [ 0 ] ) * V_12 -> V_46 ,
V_94 , & V_12 -> V_48 ) ;
if ( V_24 )
return V_24 ;
V_12 -> V_95 [ V_12 -> V_39 - 1 ] = 0 ;
return F_38 ( V_10 ,
V_12 -> V_95 + V_12 -> V_39 - 1 ,
sizeof( V_12 -> V_95 [ 0 ] ) ,
V_96 ,
& V_12 -> V_44 ) ;
}
static void
F_41 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_83 * V_84 = V_20 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_12 -> V_60 ; V_97 ++ ) {
struct V_85 * V_86 = & V_12 -> V_88 [ V_97 ] ;
F_42 ( V_84 , V_86 -> V_87 , V_86 -> V_79 , V_86 -> V_81 ) ;
}
V_12 -> V_60 = 0 ;
}
static int
F_43 ( struct V_9 * V_10 ,
void * V_74 , unsigned int V_64 , bool V_65 ,
bool V_98 )
{
if ( V_98 && V_64 < 7 ) {
return F_33 ( V_10 , V_74 , V_64 ,
V_65 ) ;
} else {
int V_24 ;
T_2 V_87 ;
V_24 = F_38 ( V_10 , V_74 , V_64 ,
V_94 ,
& V_87 ) ;
if ( V_24 )
return V_24 ;
return F_31 ( V_10 , V_87 ,
V_64 , V_65 ) ;
}
}
static int
F_44 ( struct V_9 * V_10 ,
T_2 V_63 , unsigned int V_64 , bool V_99 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_66 * V_67 ;
if ( V_12 -> V_39 >= V_68 ||
F_28 () ) {
F_32 ( L_3 ) ;
return - V_69 ;
}
V_67 = & V_12 -> V_93 [ V_12 -> V_39 ++ ] ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_71 . V_99 = V_99 ;
V_67 -> V_73 . V_64 = V_64 ;
V_67 -> V_73 . V_16 = V_63 ;
return 0 ;
}
static int
F_45 ( struct V_9 * V_10 ,
void * V_100 , unsigned int V_64 , bool V_101 )
{
T_2 V_87 ;
int V_24 ;
V_24 = F_38 ( V_10 , V_100 , V_64 ,
V_102 , & V_87 ) ;
if ( V_24 )
return V_24 ;
return F_44 ( V_10 , V_87 , V_64 , V_101 ) ;
}
static struct V_13 *
F_46 ( T_5 V_29 )
{
void * V_34 ;
T_1 V_103 = sizeof( struct V_13 ) +
2 * V_104 ;
struct V_13 * V_105 = F_47 ( V_103 , V_29 ) ;
if ( ! V_105 )
return NULL ;
V_34 = V_105 + 1 ;
V_105 -> V_16 = F_48 ( V_34 , V_104 ) ;
return V_105 ;
}
static int F_49 ( struct V_9 * V_10 ,
struct V_1 * V_106 , T_1 V_79 )
{
struct V_13 * V_105 ;
int V_24 ;
V_105 = F_46 ( V_10 -> V_107 ) ;
if ( ! V_105 )
return - V_89 ;
V_105 -> V_8 = V_79 ;
V_105 -> V_4 = V_106 -> V_4 ;
V_105 -> V_5 = V_106 -> V_5 ;
V_24 = F_45 ( V_10 , V_105 -> V_16 , V_79 , false ) ;
if ( V_24 ) {
F_14 ( V_105 ) ;
return V_24 ;
}
F_11 ( L_4 , V_79 , V_106 -> V_5 ) ;
F_19 ( & V_105 -> V_17 , & V_10 -> V_12 -> V_61 ) ;
return 0 ;
}
static int
F_50 ( struct V_9 * V_10 ,
struct V_1 * V_106 ,
T_1 V_108 )
{
T_1 V_109 ;
int V_24 ;
T_2 V_63 ;
while ( V_106 -> V_4 && V_108 ) {
V_109 = F_4 ( V_108 , F_6 ( V_106 ) ) ;
V_63 = F_7 ( V_106 ) ;
if ( ! F_51 ( V_63 , V_104 ) ) {
V_109 = F_52 ( T_2 , V_109 ,
F_53 ( V_63 , V_104 ) -
V_63 ) ;
F_11 ( L_5 , & V_63 , V_109 ) ;
V_24 = F_49 ( V_10 , V_106 , V_109 ) ;
} else if ( V_109 < V_104 ) {
F_11 ( L_5 , & V_63 , V_109 ) ;
V_24 = F_49 ( V_10 , V_106 , V_109 ) ;
} else {
T_2 V_87 ;
V_109 = V_109 & ~ ( V_104 - 1 ) ;
F_11 ( L_6 , & V_63 , V_109 ) ;
V_24 = F_34 ( V_10 ,
F_54 ( V_106 -> V_4 ) ,
V_106 -> V_4 -> V_5 +
V_106 -> V_5 ,
V_109 ,
V_102 ,
& V_87 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_44 ( V_10 ,
V_87 ,
V_109 , false ) ;
}
if ( V_24 )
return V_24 ;
V_108 = V_108 - V_109 ;
F_2 ( V_106 , V_109 ) ;
}
if ( V_108 )
F_32 ( L_7 , V_108 ) ;
return V_108 ? - V_75 : 0 ;
}
static int
F_55 ( struct V_9 * V_10 ,
struct V_1 * V_106 ,
T_1 V_108 )
{
T_1 V_109 ;
int V_24 ;
T_2 V_63 ;
while ( V_106 -> V_4 && V_108 ) {
V_109 = F_4 ( V_108 , F_6 ( V_106 ) ) ;
V_63 = F_7 ( V_106 ) ;
F_11 ( L_8 , & V_63 , V_109 ) ;
if ( V_63 & 3 ) {
char V_16 [ 3 ] ;
V_109 = F_52 ( T_1 , V_109 , ( 4 - ( V_63 & 3 ) ) ) ;
F_56 ( V_106 -> V_4 , 1 , V_16 , V_109 ,
V_106 -> V_5 ) ;
V_24 = F_33 ( V_10 , V_16 ,
V_109 ,
false ) ;
} else {
T_2 V_87 ;
V_24 = F_34 ( V_10 ,
F_54 ( V_106 -> V_4 ) ,
V_106 -> V_4 -> V_5 +
V_106 -> V_5 ,
V_109 ,
V_94 ,
& V_87 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_31 ( V_10 ,
V_87 ,
V_109 , false ) ;
}
if ( V_24 )
return V_24 ;
V_108 = V_108 - V_109 ;
F_2 ( V_106 , V_109 ) ;
}
if ( V_108 )
F_32 ( L_7 , V_108 ) ;
return V_108 ? - V_75 : 0 ;
}
static int
F_57 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_66 * V_67 ;
if ( ! V_12 -> V_46 || V_12 -> V_46 > V_68 ) {
F_32 ( L_9 ,
V_110 , V_12 -> V_46 ? L_10 : L_11 ) ;
return - V_75 ;
}
V_67 = & V_12 -> V_70 [ V_12 -> V_46 - 1 ] ;
V_67 -> V_71 . V_65 = 1 ;
return 0 ;
}
static int
F_58 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_66 * V_67 ;
if ( ! V_12 -> V_39 || V_12 -> V_39 > V_68 ) {
F_32 ( L_12 ,
V_110 , V_12 -> V_39 ? L_10 : L_11 ) ;
return - V_75 ;
}
V_67 = & V_12 -> V_93 [ V_12 -> V_39 - 1 ] ;
V_67 -> V_71 . V_99 = 1 ;
return 0 ;
}
static T_1
F_59 ( int V_111 , unsigned char * V_74 , T_6 V_112 , T_6 V_113 )
{
unsigned int V_114 , V_115 , V_116 , V_117 , V_118 ;
T_7 V_119 = F_60 ( V_113 ) ;
switch ( V_111 ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
V_115 = 448 / 8 ;
V_114 = 512 / 8 ;
V_118 = 8 ;
break;
default:
V_115 = 896 / 8 ;
V_114 = 1024 / 8 ;
V_118 = 16 ;
break;
}
V_115 -= 1 ;
V_116 = V_112 & ( V_114 - 1 ) ;
V_117 = V_116 > V_115 ? V_115 + V_114 - V_116 : V_115 - V_116 ;
memset ( V_74 + 1 , 0 , V_117 ) ;
V_74 [ 0 ] = 0x80 ;
if ( V_118 == 16 ) {
memset ( V_74 + 1 + V_117 , 0 , 8 ) ;
memcpy ( V_74 + 1 + V_117 + 8 , & V_119 , 8 ) ;
} else {
memcpy ( V_74 + 1 + V_117 , & V_119 , 8 ) ;
}
return V_117 + V_118 + 1 ;
}
static int F_61 ( struct V_9 * V_10 ,
struct V_124 * V_125 ,
void (* F_62)( struct V_124 * V_23 ) ,
struct V_3 * V_126 , unsigned int V_6 )
{
T_5 V_29 ;
struct V_18 * V_19 = F_16 ( V_20 ) ;
V_29 = ( V_125 -> V_29 & V_127 ) ?
V_128 : V_129 ;
V_10 -> V_107 = V_29 ;
V_10 -> V_12 = F_63 ( V_19 -> V_130 , V_29 ) ;
if ( ! V_10 -> V_12 )
return - V_89 ;
V_10 -> V_23 = V_125 ;
V_10 -> F_62 = F_62 ;
return 0 ;
}
static void
F_64 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_13 * V_15 ;
F_10 (b, next, &dma->bounce_buffers, list) {
F_14 ( V_14 ) ;
}
}
static int
F_21 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
F_41 ( V_10 ) ;
F_64 ( V_10 -> V_12 ) ;
F_65 ( V_19 -> V_130 , V_10 -> V_12 ) ;
V_10 -> V_12 = NULL ;
return 0 ;
}
static int F_66 ( struct V_131 * V_23 )
{
struct V_132 * V_133 = F_67 ( V_23 ) ;
struct V_134 * V_135 = F_68 ( V_133 ) ;
struct V_136 * V_137 = NULL ;
void (* F_62)( struct V_124 * V_23 );
int V_24 ;
V_137 = F_69 ( V_23 ) ;
switch ( V_135 -> V_138 ) {
case V_139 :
case V_140 :
case V_141 :
V_137 -> V_142 = 0 ;
break;
default:
break;
}
switch ( V_135 -> V_138 ) {
case V_139 :
F_62 = V_143 ;
break;
default:
F_62 = V_144 ;
break;
}
V_24 = F_61 ( & V_137 -> V_10 ,
& V_23 -> V_34 ,
F_62 ,
V_23 -> V_74 , V_23 -> V_145 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_70 ( V_23 ) ;
if ( V_24 ) {
F_21 ( & V_137 -> V_10 ) ;
return V_24 ;
}
return F_17 ( & V_137 -> V_10 ) ;
}
static int F_71 ( struct V_131 * V_23 )
{
int V_24 ;
struct V_132 * V_133 = F_67 ( V_23 ) ;
struct V_134 * V_135 = F_68 ( V_133 ) ;
struct V_136 * V_137 = NULL ;
void (* F_62)( struct V_124 * V_23 );
V_137 = F_69 ( V_23 ) ;
switch ( V_135 -> V_138 ) {
case V_139 :
case V_140 :
case V_141 :
V_137 -> V_142 = 1 ;
break;
default:
break;
}
switch ( V_135 -> V_138 ) {
case V_139 :
F_62 = V_146 ;
break;
default:
F_62 = V_144 ;
break;
}
V_24 = F_61 ( & V_137 -> V_10 , & V_23 -> V_34 ,
F_62 ,
V_23 -> V_74 , V_23 -> V_145 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_70 ( V_23 ) ;
if ( V_24 ) {
F_21 ( & V_137 -> V_10 ) ;
return V_24 ;
}
return F_17 ( & V_137 -> V_10 ) ;
}
static int
F_72 ( struct V_131 * V_23 , bool V_147 )
{
struct V_132 * V_133 = F_67 ( V_23 ) ;
struct V_134 * V_135 = F_68 ( V_133 ) ;
T_1 V_148 = F_73 ( V_133 ) ;
unsigned int V_149 = F_74 ( ( V_150 * )
( V_23 -> V_151 + V_148 - 4 ) ) ;
unsigned int V_152 = F_53 ( V_23 -> V_145 , V_153 ) /
V_153 ;
if ( V_149 + V_152 < V_149 ) {
int V_24 ;
F_11 ( L_13 ,
V_149 , V_149 + V_152 ) ;
V_24 = F_75 ( V_135 -> V_154 , V_135 -> V_155 ,
V_135 -> V_156 ) ;
if ( V_24 )
return V_24 ;
{
F_76 ( V_157 , V_135 -> V_154 ) ;
F_77 ( V_157 , V_135 -> V_154 ) ;
F_78 ( V_157 , V_23 -> V_34 . V_29 ,
NULL , NULL ) ;
F_79 ( V_157 , V_23 -> V_158 , V_23 -> V_74 ,
V_23 -> V_145 , V_23 -> V_151 ) ;
V_24 = V_147 ? F_80 ( V_157 )
: F_81 ( V_157 ) ;
F_82 ( V_157 ) ;
}
return V_24 ;
}
return V_147 ? F_66 ( V_23 )
: F_71 ( V_23 ) ;
}
static int F_83 ( struct V_131 * V_23 )
{
return F_72 ( V_23 , true ) ;
}
static int F_84 ( struct V_131 * V_23 )
{
return F_72 ( V_23 , false ) ;
}
static int F_85 ( struct V_159 * V_160 )
{
struct V_134 * V_161 = F_86 ( V_160 ) ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
F_87 ( V_160 ,
sizeof( struct V_162 ) ) ;
return 0 ;
}
static int F_88 ( struct V_159 * V_160 , const T_8 * V_163 ,
unsigned int V_64 )
{
struct V_134 * V_135 = F_89 ( & V_160 -> V_34 ) ;
if ( V_64 != 16 && V_64 != 24 && V_64 != 32 ) {
F_90 ( V_160 , V_164 ) ;
return - 1 ;
}
V_135 -> V_156 = V_64 ;
memcpy ( V_135 -> V_155 , V_163 , V_64 ) ;
return 0 ;
}
static int F_91 ( struct V_165 * V_23 )
{
int V_24 ;
struct V_162 * V_137 = F_92 ( V_23 ) ;
V_137 -> V_142 = false ;
V_24 = F_61 ( & V_137 -> V_10 , & V_23 -> V_34 ,
V_166 ,
NULL , 0 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_93 ( V_23 ) ;
if ( V_24 ) {
F_21 ( & V_137 -> V_10 ) ;
return V_24 ;
}
return F_17 ( & V_137 -> V_10 ) ;
}
static int F_94 ( struct V_165 * V_23 )
{
int V_24 ;
struct V_162 * V_137 = F_92 ( V_23 ) ;
V_137 -> V_142 = true ;
if ( V_23 -> V_145 < V_153 )
return - V_75 ;
V_24 = F_61 ( & V_137 -> V_10 ,
& V_23 -> V_34 ,
V_166 ,
NULL , 0 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_93 ( V_23 ) ;
if ( V_24 ) {
F_21 ( & V_137 -> V_10 ) ;
return V_24 ;
}
return F_17 ( & V_137 -> V_10 ) ;
}
static int F_95 ( struct V_167 * V_168 )
{
struct V_169 * V_135 = F_89 ( V_168 -> V_34 . V_160 ) ;
struct V_170 * V_137 = F_96 ( V_168 ) ;
T_1 V_171 = F_97 ( F_98 ( V_168 ) ) ;
T_1 V_172 = V_171 == V_173 ?
V_174 : V_171 ;
T_1 V_175 = F_99 (
F_100 ( F_98 ( V_168 ) ) ) ;
struct V_9 * V_10 = & V_137 -> V_10 ;
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
T_4 V_176 ;
bool V_177 = false ;
bool V_178 = false ;
int error = 0 ;
F_26 ( V_10 ) ;
if ( V_137 -> V_179 & V_180 ) {
if ( V_33 == V_49 ) {
V_137 -> V_181 = F_24 ( V_182 ,
V_183 ) ;
} else {
V_137 -> V_181 = F_24 ( V_184 ,
V_185 ) ;
}
memcpy ( V_137 -> V_186 , V_135 -> V_187 ,
V_135 -> V_188 ) ;
memset ( V_137 -> V_186 + V_135 -> V_188 , 0 ,
V_175 - V_135 -> V_188 ) ;
error = F_43 ( V_10 ,
( void * ) & V_137 -> V_181 ,
sizeof( V_137 -> V_181 ) , false , false ) ;
if ( error )
return error ;
error = F_43 ( V_10 ,
V_137 -> V_186 , V_175 ,
true , false ) ;
if ( error )
return error ;
}
if ( ! ( V_137 -> V_179 & V_189 ) ) {
V_176 = V_190 ;
V_177 = true ;
} else {
V_176 = V_191 ;
}
if ( V_33 == V_49 ) {
V_137 -> V_192 &= ~ V_193 ;
V_137 -> V_192 |= F_24 ( V_193 , V_176 ) ;
if ( V_137 -> V_179 & V_194 )
V_137 -> V_192 |= V_195 ;
} else {
V_137 -> V_192 &= ~ V_196 ;
V_137 -> V_192 |= F_24 ( V_196 , V_176 ) ;
if ( V_137 -> V_179 & V_194 )
V_137 -> V_192 |= V_197 ;
}
error = F_43 ( V_10 ,
( void * ) & V_137 -> V_192 ,
sizeof( V_137 -> V_192 ) , false , false ) ;
if ( error )
return error ;
error = F_45 ( V_10 , V_19 -> V_198 , 4 , false ) ;
if ( error )
return error ;
if ( V_177 ) {
error = F_43 ( V_10 ,
V_137 -> V_199 ,
V_172 , false , false ) ;
if ( error )
return error ;
}
if ( V_137 -> V_179 & V_200 ) {
T_1 V_201 = 0 ;
T_1 V_202 = V_168 -> V_6 + V_137 -> V_203 ;
T_1 V_204 = F_101 ( V_202 , V_175 ) ;
struct V_1 V_106 ;
V_178 = V_204 > 0 ;
if ( V_137 -> V_203 && V_204 ) {
memcpy ( V_137 -> V_205 ,
V_137 -> V_206 ,
V_137 -> V_203 ) ;
error = F_43 ( V_10 ,
V_137 -> V_205 ,
V_137 -> V_203 ,
false , true ) ;
if ( error )
return error ;
V_201 += V_137 -> V_203 ;
V_137 -> V_203 = 0 ;
}
F_1 ( & V_106 , V_168 -> V_158 ) ;
error = F_55 ( V_10 , & V_106 ,
V_204 -
V_201 ) ;
if ( error )
return error ;
if ( V_106 . V_4 ) {
T_1 V_207 = V_204 - V_201 ;
T_1 V_208 = V_168 -> V_6 - V_207 ;
F_56 ( V_168 -> V_158 , F_102 ( V_168 -> V_158 ) ,
V_137 -> V_206 +
V_137 -> V_203 ,
V_208 , V_207 ) ;
V_137 -> V_203 += V_208 ;
}
V_137 -> V_209 += V_204 ;
V_137 -> V_179 &= ~ ( V_200 ) ;
}
if ( V_137 -> V_179 & V_194 ) {
bool V_210 = V_172 != V_171 ;
T_1 V_211 ;
T_6 V_212 ;
T_4 V_111 ;
if ( V_33 == V_49 )
V_111 = F_103 ( V_182 , V_137 -> V_192 ) ;
else
V_111 = F_103 ( V_184 , V_137 -> V_192 ) ;
if ( V_137 -> V_203 ) {
memcpy ( V_137 -> V_205 ,
V_137 -> V_206 ,
V_137 -> V_203 ) ;
error = F_43 ( V_10 ,
V_137 -> V_205 ,
V_137 -> V_203 ,
false , true ) ;
if ( error )
return error ;
V_137 -> V_209 += V_137 -> V_203 ;
V_137 -> V_203 = 0 ;
}
if ( V_137 -> V_179 & V_180 )
V_212 = 8 * ( V_137 -> V_209 + V_175 ) ;
else
V_212 = 8 * V_137 -> V_209 ;
V_211 = F_59 ( V_111 , V_137 -> V_198 ,
V_137 -> V_209 , V_212 ) ;
error = F_43 ( V_10 ,
V_137 -> V_198 ,
V_211 , false ,
true ) ;
V_137 -> V_209 = 0 ;
if ( error )
return error ;
error = F_45 ( V_10 , V_168 -> V_213 ,
V_171 ,
! V_210 ) ;
if ( error )
return error ;
if ( V_210 ) {
error = F_45 ( V_10 ,
V_137 -> V_206 ,
V_171 - V_172 , true ) ;
if ( error )
return error ;
}
} else {
if ( ! V_178 )
return V_214 ;
error = F_45 ( V_10 ,
V_137 -> V_199 ,
V_172 , false ) ;
if ( error )
return error ;
}
V_137 -> V_179 &= ~ ( V_189 | V_200 |
V_194 ) ;
error = F_58 ( V_10 ) ;
if ( error )
return error ;
error = F_57 ( V_10 ) ;
if ( error )
return error ;
error = F_40 ( V_10 ) ;
if ( error )
return error ;
return V_215 ;
}
static int F_104 ( struct V_132 * V_160 )
{
struct V_134 * V_135 = F_68 ( V_160 ) ;
V_160 -> V_216 = sizeof( struct V_136 ) ;
V_135 -> V_138 = V_140 ;
return 0 ;
}
static int F_105 ( struct V_132 * V_160 )
{
struct V_134 * V_135 = F_68 ( V_160 ) ;
V_135 -> V_154 = F_106 ( F_107 ( & V_160 -> V_34 ) ,
0 ,
V_217 |
V_218 ) ;
if ( F_108 ( V_135 -> V_154 ) )
return F_109 ( V_135 -> V_154 ) ;
V_160 -> V_216 = sizeof( struct V_136 ) ;
V_135 -> V_138 = V_219 ;
return 0 ;
}
static int F_110 ( struct V_132 * V_160 )
{
struct V_134 * V_135 = F_68 ( V_160 ) ;
V_160 -> V_216 = sizeof( struct V_136 ) ;
V_135 -> V_138 = V_139 ;
return 0 ;
}
static int F_111 ( struct V_132 * V_160 )
{
struct V_134 * V_135 = F_68 ( V_160 ) ;
V_160 -> V_216 = sizeof( struct V_136 ) ;
V_135 -> V_138 = V_141 ;
return 0 ;
}
static void F_112 ( struct V_132 * V_160 )
{
struct V_134 * V_135 = F_68 ( V_160 ) ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
}
static void F_113 ( struct V_132 * V_160 )
{
struct V_134 * V_135 = F_68 ( V_160 ) ;
F_114 ( V_135 -> V_154 ) ;
F_112 ( V_160 ) ;
}
static int
F_115 ( struct V_132 * V_133 , const T_8 * V_163 ,
unsigned int V_220 )
{
struct V_134 * V_135 =
F_68 ( V_133 ) ;
switch ( V_220 ) {
case 16 :
case 24 :
case 32 :
break;
default:
F_116 ( V_133 ,
V_164 ) ;
return - V_75 ;
}
memcpy ( V_135 -> V_155 , V_163 , V_220 ) ;
V_135 -> V_156 = V_220 ;
return 0 ;
}
static int
F_117 ( struct V_132 * V_133 , const T_8 * V_163 ,
unsigned int V_220 )
{
struct V_134 * V_135 =
F_68 ( V_133 ) ;
int V_24 ;
V_24 = F_118 ( & V_133 -> V_34 , V_163 , V_220 ) ;
if ( V_24 )
return V_24 ;
switch ( V_220 ) {
case 32 :
case 48 :
case 64 :
break;
default:
F_116 ( V_133 ,
V_164 ) ;
return - V_75 ;
}
memcpy ( V_135 -> V_155 , V_163 , V_220 ) ;
V_135 -> V_156 = V_220 ;
return 0 ;
}
static int F_70 ( struct V_131 * V_168 )
{
int V_24 ;
struct V_1 V_106 ;
struct V_132 * V_133 = F_67 ( V_168 ) ;
struct V_134 * V_135 = F_68 ( V_133 ) ;
struct V_136 * V_137 = NULL ;
T_1 V_148 = F_73 ( V_133 ) ;
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
struct V_9 * V_10 ;
bool V_221 = false ;
T_1 V_222 ;
T_4 V_223 = 0 ;
T_4 V_111 ;
V_137 = F_69 ( V_168 ) ;
V_10 = & V_137 -> V_10 ;
F_26 ( V_10 ) ;
if ( V_33 == V_49 )
V_135 -> V_181 = F_24 ( V_182 , V_183 ) ;
else
V_135 -> V_181 = F_24 ( V_184 , V_185 ) ;
V_24 = F_43 ( V_10 , ( void * ) & V_135 -> V_181 ,
sizeof( V_135 -> V_181 ) , false , false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_43 ( V_10 , V_135 -> V_155 ,
V_135 -> V_156 , true , false ) ;
if ( V_24 )
return V_24 ;
V_137 -> V_224 = 0 ;
if ( V_135 -> V_138 == V_141 )
V_222 = V_135 -> V_156 / 2 ;
else
V_222 = V_135 -> V_156 ;
switch ( V_222 ) {
case 16 :
V_223 = V_225 ;
break;
case 24 :
V_223 = V_226 ;
break;
case 32 :
V_223 = V_227 ;
break;
default:
F_32 ( L_14 ,
V_110 , V_135 -> V_156 ) ;
return - V_75 ;
}
switch ( V_135 -> V_138 ) {
case V_140 :
V_111 = V_228 ;
V_221 = V_137 -> V_142 ;
break;
case V_139 :
V_111 = V_229 ;
V_221 = V_137 -> V_142 ;
break;
case V_219 :
V_111 = V_230 ;
V_221 = false ;
break;
case V_141 :
V_111 = V_231 ;
V_221 = V_137 -> V_142 ;
if ( V_33 == V_49 )
V_137 -> V_224 |= V_232 ;
else
V_137 -> V_224 |= V_233 ;
break;
default:
F_32 ( L_15 ,
V_110 , V_135 -> V_138 ) ;
return - V_75 ;
}
if ( V_33 == V_49 ) {
V_137 -> V_224 |= F_24 ( V_182 , V_111 ) ;
V_137 -> V_224 |= F_24 ( V_234 ,
V_223 ) ;
if ( V_221 )
V_137 -> V_224 |= V_235 ;
} else {
V_137 -> V_224 |= F_24 ( V_184 , V_111 ) ;
V_137 -> V_224 |= F_24 ( V_236 ,
V_223 ) ;
if ( V_221 )
V_137 -> V_224 |= V_237 ;
}
V_24 = F_43 ( V_10 ,
& V_137 -> V_224 ,
sizeof( V_137 -> V_224 ) ,
false , false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_45 ( V_10 , V_19 -> V_198 , 4 , false ) ;
if ( V_24 )
return V_24 ;
if ( V_148 ) {
V_24 = F_43 ( V_10 , V_168 -> V_151 , V_148 ,
false , false ) ;
if ( V_24 )
return V_24 ;
}
F_1 ( & V_106 , V_168 -> V_158 ) ;
V_24 = F_55 ( V_10 , & V_106 , V_168 -> V_145 ) ;
if ( V_24 )
return V_24 ;
F_1 ( & V_106 , V_168 -> V_74 ) ;
V_24 = F_50 ( V_10 , & V_106 , V_168 -> V_145 ) ;
if ( V_24 )
return V_24 ;
if ( V_135 -> V_138 == V_219 ||
V_135 -> V_138 == V_141 ) {
T_1 V_238 = F_53 ( V_168 -> V_145 , V_153 ) -
V_168 -> V_145 ;
if ( V_238 ) {
V_24 = F_43 ( V_10 ,
V_19 -> V_198 ,
V_238 , false , false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_45 ( V_10 ,
V_19 -> V_198 , V_238 ,
false ) ;
if ( V_24 )
return V_24 ;
}
}
V_24 = F_57 ( V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_58 ( V_10 ) ;
if ( V_24 )
return V_24 ;
return F_40 ( V_10 ) ;
}
static int F_93 ( struct V_165 * V_168 )
{
T_1 V_108 ;
int V_24 ;
T_1 V_239 ;
struct V_134 * V_135 = F_89 ( V_168 -> V_34 . V_160 ) ;
struct V_162 * V_137 = F_92 ( V_168 ) ;
struct V_159 * V_133 = F_119 ( V_168 ) ;
struct V_9 * V_10 = & V_137 -> V_10 ;
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
T_4 V_240 ;
F_26 ( V_10 ) ;
if ( V_33 == V_49 ) {
V_135 -> V_181 = F_24 ( V_182 ,
V_183 ) ;
} else {
V_135 -> V_181 = F_24 ( V_184 ,
V_185 ) ;
}
V_24 = F_43 ( V_10 , ( void * ) & V_135 -> V_181 ,
sizeof( V_135 -> V_181 ) , false , false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_43 ( V_10 , V_135 -> V_155 ,
V_135 -> V_156 , true , false ) ;
if ( V_24 )
return V_24 ;
V_137 -> V_224 = 0 ;
switch ( V_135 -> V_156 ) {
case 16 :
V_240 = V_225 ;
break;
case 24 :
V_240 = V_226 ;
break;
case 32 :
V_240 = V_227 ;
break;
default:
return - V_75 ;
}
if ( V_33 == V_49 ) {
V_137 -> V_224 |= F_24 ( V_182 ,
V_241 ) ;
V_137 -> V_224 |= F_24 ( V_234 ,
V_240 ) ;
if ( V_137 -> V_142 )
V_137 -> V_224 |= V_235 ;
} else {
V_137 -> V_224 |= F_24 ( V_184 ,
V_241 ) ;
V_137 -> V_224 |= F_24 ( V_236 ,
V_240 ) ;
if ( V_137 -> V_142 )
V_137 -> V_224 |= V_237 ;
}
V_24 = F_43 ( V_10 ,
( void * ) & V_137 -> V_224 ,
sizeof( V_137 -> V_224 ) , false ,
false ) ;
if ( V_24 )
return V_24 ;
V_24 = F_45 ( V_10 , V_19 -> V_198 , 4 , false ) ;
if ( V_24 )
return V_24 ;
V_239 = V_168 -> V_145 ;
if ( V_137 -> V_142 )
V_239 -= V_153 ;
V_137 -> V_242 . V_243 =
F_60 ( 8 * V_168 -> V_244 ) ;
V_137 -> V_242 . V_245 =
F_60 ( 8 * V_239 ) ;
memcpy ( V_137 -> V_242 . J0 , V_168 -> V_151 , F_120 ( V_133 ) ) ;
F_121 ( V_137 -> V_242 . J0 + 12 , 4 ) ;
V_24 = F_43 ( V_10 , & V_137 -> V_242 ,
sizeof( struct V_246 ) , false , false ) ;
if ( V_24 )
return V_24 ;
{
struct V_1 V_106 ;
F_1 ( & V_106 , V_168 -> V_158 ) ;
V_108 = V_168 -> V_244 ;
V_24 = F_55 ( V_10 , & V_106 , V_108 ) ;
if ( V_24 )
return V_24 ;
if ( ! F_51 ( V_168 -> V_244 , 16 ) ) {
T_1 V_247 = 16 - ( V_168 -> V_244 % 16 ) ;
V_24 = F_43 ( V_10 ,
V_19 -> V_248 ,
V_247 , false ,
false ) ;
if ( V_24 )
return V_24 ;
}
V_108 = V_239 ;
V_24 = F_55 ( V_10 , & V_106 , V_108 ) ;
if ( V_24 )
return V_24 ;
if ( ! F_51 ( V_239 , 16 ) ) {
T_1 V_249 = 16 - ( V_239 % 16 ) ;
V_24 = F_43 ( V_10 ,
V_19 -> V_248 ,
V_249 ,
false ,
false ) ;
if ( V_24 )
return V_24 ;
}
}
{
struct V_1 V_106 ;
T_1 V_250 = V_168 -> V_145 ;
if ( V_137 -> V_142 )
V_250 -= V_153 ;
F_1 ( & V_106 , V_168 -> V_74 ) ;
V_108 = F_2 ( & V_106 , V_168 -> V_244 ) ;
if ( V_108 )
return - V_75 ;
V_108 = V_250 ;
V_24 = F_50 ( V_10 , & V_106 , V_108 ) ;
if ( V_24 )
return V_24 ;
if ( ! F_51 ( V_250 , 16 ) ) {
T_1 V_249 = 16 - ( V_250 % 16 ) ;
V_24 = F_45 ( V_10 ,
V_19 -> V_198 ,
V_249 , false ) ;
if ( V_24 )
return V_24 ;
}
V_108 = V_153 ;
if ( V_137 -> V_142 ) {
V_24 = F_45 ( V_10 ,
V_137 -> V_251 , V_108 , false ) ;
if ( V_24 )
return V_24 ;
} else {
V_24 = F_50 ( V_10 , & V_106 ,
V_108 ) ;
if ( V_24 )
return V_24 ;
}
}
V_24 = F_58 ( V_10 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_57 ( V_10 ) ;
if ( V_24 )
return V_24 ;
return F_40 ( V_10 ) ;
}
static void F_122 ( struct V_18 * V_19 )
{
struct V_9 * V_23 ;
while ( ! F_123 ( & V_19 -> V_31 ) && ! F_15 () ) {
V_23 = F_124 ( & V_19 -> V_31 ,
struct V_9 ,
V_17 ) ;
F_125 ( & V_23 -> V_17 , & V_19 -> V_27 ) ;
F_20 ( V_23 ) ;
V_23 -> V_23 -> F_62 ( V_23 -> V_23 , - V_28 ) ;
}
if ( V_19 -> V_22 )
F_126 ( & V_19 -> V_252 , V_253 + F_127 ( 100 ) ) ;
else
F_128 ( & V_19 -> V_252 ) ;
}
static void F_129 ( unsigned long V_73 )
{
struct V_18 * V_19 = (struct V_18 * ) V_73 ;
F_130 ( V_20 , L_16 ) ;
F_131 ( & V_19 -> V_254 ) ;
}
static void F_132 ( unsigned long V_73 )
{
struct V_18 * V_19 = (struct V_18 * ) V_73 ;
struct V_9 * V_23 ;
struct V_9 * V_255 ;
if ( F_123 ( & V_19 -> V_27 ) ) {
F_11 ( L_17 ) ;
return;
}
F_18 ( & V_19 -> V_26 ) ;
F_10 (req, n, &ac->pending, list) {
struct V_11 * V_12 = V_23 -> V_12 ;
T_4 V_95 ;
F_133 ( V_20 , V_12 -> V_44 ,
sizeof( V_12 -> V_95 [ 0 ] ) ,
V_96 ) ;
V_95 = V_23 -> V_12 -> V_95 [ V_23 -> V_12 -> V_39 - 1 ] ;
F_11 ( L_18 , V_23 , V_95 ) ;
if ( ! V_95 )
break;
#ifdef F_29
if ( F_30 ( & V_256 , 1 ) )
continue;
#endif
F_11 ( L_19 , V_23 ) ;
F_13 ( & V_23 -> V_17 ) ;
F_41 ( V_23 ) ;
F_9 ( V_23 ) ;
V_19 -> V_22 -- ;
F_21 ( V_23 ) ;
V_23 -> F_62 ( V_23 -> V_23 ) ;
}
F_122 ( V_19 ) ;
F_22 ( & V_19 -> V_26 ) ;
}
static void V_144 ( struct V_124 * V_23 )
{
V_23 -> F_62 ( V_23 , 0 ) ;
}
static void
V_146 ( struct V_124 * V_23 )
{
struct V_131 * V_257 = F_134 ( V_23 ,
struct V_131 , V_34 ) ;
F_135 ( V_257 -> V_151 , V_257 -> V_158 ,
V_257 -> V_145 - V_153 ,
V_153 , 0 ) ;
V_23 -> F_62 ( V_23 , 0 ) ;
}
static void
V_143 ( struct V_124 * V_23 )
{
struct V_131 * V_257 = F_134 ( V_23 ,
struct V_131 , V_34 ) ;
F_135 ( V_257 -> V_151 , V_257 -> V_74 ,
V_257 -> V_145 - V_153 ,
V_153 , 0 ) ;
V_23 -> F_62 ( V_23 , 0 ) ;
}
static void V_166 ( struct V_124 * V_23 )
{
int V_213 = 0 ;
struct V_165 * V_168 = F_134 ( V_23 ,
struct V_165 , V_34 ) ;
struct V_162 * V_137 = F_92 ( V_168 ) ;
if ( V_137 -> V_142 ) {
T_8 V_258 [ V_153 ] ;
F_56 ( V_168 -> V_158 ,
F_102 ( V_168 -> V_158 ) ,
V_258 ,
V_153 ,
V_168 -> V_244 + V_168 -> V_145 -
V_153 ) ;
if ( memcmp ( V_137 -> V_251 ,
V_258 ,
V_153 ) ) {
F_11 ( L_20 ) ;
F_136 ( L_21 , V_259 , 32 , 1 ,
V_258 , V_153 , true ) ;
F_136 ( L_22 , V_259 , 32 , 1 ,
V_137 -> V_251 ,
V_153 , true ) ;
V_213 = - V_260 ;
}
}
V_23 -> F_62 ( V_23 , V_213 ) ;
}
static void F_137 ( struct V_124 * V_23 )
{
V_23 -> F_62 ( V_23 , 0 ) ;
}
static int
F_138 ( struct V_261 * V_160 ,
const T_8 * V_163 , unsigned int V_220 )
{
struct V_169 * V_161 = F_89 ( & V_160 -> V_34 ) ;
T_1 V_175 ;
int V_24 ;
if ( ! V_220 ) {
F_32 ( L_23 ,
V_220 ) ;
return - V_75 ;
}
memset ( V_161 -> V_187 , 0 , sizeof( V_161 -> V_187 ) ) ;
V_175 = F_99 ( F_100 ( V_160 ) ) ;
if ( V_220 > V_175 ) {
F_139 ( V_262 , V_161 -> V_263 ) ;
V_262 -> V_160 = V_161 -> V_263 ;
V_262 -> V_29 = F_140 ( V_160 ) &
V_127 ;
V_161 -> V_188 = V_175 ;
V_24 = F_141 ( V_262 , V_163 , V_220 ,
V_161 -> V_187 ) ;
if ( V_24 )
return V_24 ;
} else {
memcpy ( V_161 -> V_187 , V_163 , V_220 ) ;
V_161 -> V_188 = V_220 ;
}
return 0 ;
}
static int
F_142 ( struct V_167 * V_23 , T_8 type , int V_264 )
{
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
struct V_170 * V_137 = F_96 ( V_23 ) ;
T_4 V_111 ;
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
V_137 -> V_179 = V_189 ;
if ( V_264 )
V_137 -> V_179 |= ( V_180 | V_265 ) ;
switch ( type ) {
case V_266 :
V_111 = V_264 ? V_122 : V_120 ;
break;
case V_267 :
V_111 = V_264 ? V_123 : V_121 ;
break;
case V_268 :
V_111 = V_264 ? V_269 : V_270 ;
break;
case V_271 :
V_111 = V_264 ? V_272 : V_273 ;
break;
default:
F_32 ( L_24 , V_110 , type ) ;
return - V_75 ;
}
if ( V_33 == V_49 )
V_137 -> V_192 = F_24 ( V_182 , V_111 ) ;
else
V_137 -> V_192 = F_24 ( V_184 , V_111 ) ;
return 0 ;
}
static int F_143 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
int V_24 ;
if ( ! V_137 -> V_10 . V_12 ) {
V_24 = F_61 ( & V_137 -> V_10 ,
& V_23 -> V_34 ,
F_137 ,
NULL , 0 ) ;
if ( V_24 )
return V_24 ;
}
V_24 = F_95 ( V_23 ) ;
switch ( V_24 ) {
case V_215 :
V_24 = F_17 ( & V_137 -> V_10 ) ;
break;
case V_214 :
V_24 = 0 ;
default:
F_21 ( & V_137 -> V_10 ) ;
break;
}
return V_24 ;
}
static int F_144 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
V_137 -> V_179 |= V_194 ;
return F_143 ( V_23 ) ;
}
static int F_145 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
V_137 -> V_179 |= V_200 ;
return F_143 ( V_23 ) ;
}
static int F_146 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_266 , 0 ) ;
}
static int F_147 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_266 , 0 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int F_148 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_267 , 0 ) ;
}
static int F_149 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_267 , 0 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int T_9 F_150 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_268 , 0 ) ;
}
static int T_9
F_151 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_268 , 0 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int F_152 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_271 , 0 ) ;
}
static int F_153 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_271 , 0 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int F_154 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_267 , 1 ) ;
}
static int T_9
F_155 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_268 , 1 ) ;
}
static int F_156 ( struct V_167 * V_23 )
{
return F_142 ( V_23 , V_271 , 1 ) ;
}
static int F_157 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_267 , 1 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int T_9
F_158 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_268 , 1 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int F_159 ( struct V_167 * V_23 )
{
struct V_170 * V_137 = F_96 ( V_23 ) ;
F_142 ( V_23 , V_271 , 1 ) ;
V_137 -> V_179 |= V_200 | V_194 ;
return F_143 ( V_23 ) ;
}
static int F_160 ( struct V_274 * V_160 ,
const char * V_275 )
{
struct V_169 * V_161 = F_89 ( V_160 ) ;
F_161 ( F_162 ( V_160 ) ,
sizeof( struct V_170 ) ) ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
if ( V_275 ) {
struct V_276 * V_277 ;
V_277 = F_163 ( V_275 , 0 ,
V_218 ) ;
if ( F_108 ( V_277 ) )
return F_109 ( V_277 ) ;
V_161 -> V_263 = V_277 ;
}
return 0 ;
}
static int F_164 ( struct V_274 * V_160 )
{
return F_160 ( V_160 , NULL ) ;
}
static int F_165 ( struct V_274 * V_160 )
{
return F_160 ( V_160 , L_25 ) ;
}
static int T_9
F_166 ( struct V_274 * V_160 )
{
return F_160 ( V_160 , L_26 ) ;
}
static int F_167 ( struct V_274 * V_160 )
{
return F_160 ( V_160 , L_27 ) ;
}
static void F_168 ( struct V_274 * V_160 )
{
struct V_169 * V_161 = F_89 ( V_160 ) ;
if ( V_161 -> V_263 )
F_169 ( V_161 -> V_263 ) ;
memset ( V_161 -> V_187 , 0 , sizeof( V_161 -> V_187 ) ) ;
V_161 -> V_188 = 0 ;
}
static int F_170 ( struct V_167 * V_23 , void * V_70 )
{
const struct V_170 * V_135 = F_96 ( V_23 ) ;
struct V_278 * V_279 = V_70 ;
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
F_171 ( sizeof( V_279 -> V_206 ) !=
sizeof( V_135 -> V_206 ) ) ;
F_171 ( sizeof( V_279 -> V_199 ) != sizeof( V_135 -> V_199 ) ) ;
V_279 -> V_209 = V_135 -> V_209 ;
V_279 -> V_203 = V_135 -> V_203 ;
V_279 -> V_179 = V_135 -> V_179 ;
if ( V_33 == V_49 )
V_279 -> V_111 = F_103 ( V_182 , V_135 -> V_192 ) ;
else
V_279 -> V_111 = F_103 ( V_184 , V_135 -> V_192 ) ;
memcpy ( V_279 -> V_206 , V_135 -> V_206 ,
sizeof( V_279 -> V_206 ) ) ;
memcpy ( V_279 -> V_199 , V_135 -> V_199 ,
sizeof( V_279 -> V_199 ) ) ;
return 0 ;
}
static int F_172 ( struct V_167 * V_23 , const void * V_93 )
{
struct V_170 * V_135 = F_96 ( V_23 ) ;
const struct V_278 * V_279 = V_93 ;
struct V_18 * V_19 = F_16 ( V_20 ) ;
enum V_32 V_33 = V_19 -> V_33 ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_135 -> V_209 = V_279 -> V_209 ;
V_135 -> V_203 = V_279 -> V_203 ;
V_135 -> V_179 = V_279 -> V_179 ;
if ( V_33 == V_49 )
V_135 -> V_192 = F_24 ( V_182 , V_279 -> V_111 ) ;
else
V_135 -> V_192 = F_24 ( V_184 , V_279 -> V_111 ) ;
memcpy ( V_135 -> V_206 , V_279 -> V_206 ,
sizeof( V_279 -> V_206 ) ) ;
memcpy ( V_135 -> V_199 , V_279 -> V_199 ,
sizeof( V_279 -> V_199 ) ) ;
return 0 ;
}
static int F_173 ( struct V_18 * V_19 )
{
enum V_32 V_33 = V_19 -> V_33 ;
void T_3 * V_34 = V_19 -> V_34 ;
T_4 V_280 ;
T_4 V_281 ;
T_4 V_282 ;
T_4 V_283 ;
T_4 V_284 ;
T_4 V_93 , V_70 ;
V_281 = 16 ;
V_280 = 15 ;
V_282 = 8 ;
V_283 = 4 ;
V_284 = 4 ;
F_174 ( ( V_281
+ V_280 ) * 64 > 1984 ,
L_28 ) ;
F_174 ( ( V_282
+ V_283
+ V_284 ) * 64 > 1024 ,
L_29 ) ;
V_93 = F_24 ( V_285 , V_282 ) |
F_24 ( V_286 , V_283 ) |
F_24 ( V_287 , V_284 ) ;
V_70 = F_24 ( V_288 , V_281 ) |
F_24 ( V_289 , V_280 ) ;
F_25 ( V_70 , V_34 + V_290 ) ;
F_25 ( V_291 , V_34 + V_292 ) ;
if ( V_33 == V_49 ) {
F_25 ( V_93 , V_34 + V_293 ) ;
F_25 ( V_294 , V_34 + V_295 ) ;
F_25 ( V_296 |
V_297 ,
V_34 + V_298 ) ;
} else {
F_25 ( V_93 , V_34 + V_299 ) ;
F_25 ( V_294 , V_34 + V_300 ) ;
F_25 ( V_301 |
V_302 ,
V_34 + V_303 ) ;
}
return 0 ;
}
static void F_175 ( struct V_18 * V_19 )
{
enum V_32 V_33 = V_19 -> V_33 ;
void T_3 * V_34 = V_19 -> V_34 ;
if ( V_33 == V_49 ) {
F_25 ( V_304 , V_34 + V_53 ) ;
F_25 ( 0 , V_34 + V_295 ) ;
F_25 ( V_305 , V_34 + V_59 ) ;
} else {
F_25 ( V_306 , V_34 + V_56 ) ;
F_25 ( 0 , V_34 + V_300 ) ;
F_25 ( V_307 , V_34 + V_59 ) ;
}
F_25 ( 0 , V_34 + V_292 ) ;
}
static T_10 F_176 ( int V_308 , void * V_309 )
{
struct V_18 * V_19 = V_309 ;
enum V_32 V_33 = V_19 -> V_33 ;
void T_3 * V_34 = V_19 -> V_34 ;
T_4 V_310 , V_311 ;
T_4 V_312 , V_313 ;
T_4 V_314 ;
T_4 V_315 = 0 ;
T_4 V_99 ;
if ( V_33 == V_49 ) {
V_99 = F_177 ( V_34 + V_316 ) ;
V_310 = V_296 ;
V_311 = V_297 ;
V_312 = V_317 ;
V_313 = V_53 ;
V_314 = V_318 ;
} else {
V_99 = F_177 ( V_34 + V_319 ) ;
V_310 = V_301 ;
V_311 = V_302 ;
V_312 = V_320 ;
V_313 = V_56 ;
V_314 = V_321 ;
}
if ( V_99 & V_310 )
V_315 |= V_310 ;
if ( V_99 & V_311 )
V_315 |= V_311 ;
else
F_25 ( V_312 , V_34 + V_313 ) ;
F_25 ( V_315 , V_34 + V_314 ) ;
if ( V_99 & V_311 )
F_131 ( & V_19 -> V_254 ) ;
return V_322 ;
}
static void F_178 ( void )
{
V_323 = F_179 ( L_30 , NULL ) ;
if ( ! V_323 || F_108 ( V_323 ) ) {
V_323 = NULL ;
F_32 ( L_31 , V_110 ) ;
return;
}
#ifdef F_29
F_180 ( L_32 , V_323 ,
& V_256 ) ;
F_180 ( L_33 , V_323 ,
& V_62 ) ;
#endif
}
static void F_181 ( void )
{
if ( ! V_323 )
return;
F_182 ( V_323 ) ;
V_323 = NULL ;
}
static int F_183 ( struct V_324 * V_325 )
{
const struct V_326 * V_327 ;
enum V_32 V_33 ;
struct V_18 * V_19 ;
struct V_83 * V_84 = & V_325 -> V_84 ;
void T_3 * V_34 ;
struct V_328 * V_329 ;
int V_308 ;
int V_330 ;
if ( V_20 )
return - V_331 ;
V_327 = F_184 ( V_332 , V_84 -> V_333 ) ;
if ( ! V_327 )
return - V_75 ;
V_33 = (enum V_32 ) V_327 -> V_73 ;
V_329 = F_185 ( V_325 , V_334 , 0 ) ;
if ( ! V_329 )
return - V_331 ;
V_34 = F_186 ( & V_325 -> V_84 , V_329 ) ;
if ( F_108 ( V_34 ) )
return F_109 ( V_34 ) ;
V_308 = F_187 ( V_325 , 0 ) ;
if ( V_308 < 0 )
return - V_331 ;
V_19 = F_188 ( & V_325 -> V_84 , sizeof( struct V_18 ) ,
V_128 ) ;
if ( ! V_19 )
return - V_89 ;
F_189 ( V_325 , V_19 ) ;
V_19 -> V_33 = V_33 ;
F_190 ( & V_19 -> V_26 ) ;
F_27 ( & V_19 -> V_31 ) ;
F_27 ( & V_19 -> V_27 ) ;
F_191 ( & V_19 -> V_252 , F_129 , ( unsigned long ) V_19 ) ;
V_19 -> V_34 = V_34 ;
V_19 -> V_130 = F_192 ( L_34 ,
sizeof( struct V_11 ) ,
64 ,
0 ,
NULL ) ;
if ( ! V_19 -> V_130 )
return - V_89 ;
#ifdef F_193
F_178 () ;
#endif
F_194 ( & V_19 -> V_254 , F_132 ,
( unsigned long ) V_19 ) ;
V_19 -> V_198 = F_188 ( & V_325 -> V_84 , 2 * V_104 ,
V_128 ) ;
if ( ! V_19 -> V_198 )
return - V_89 ;
V_19 -> V_198 = F_48 ( V_19 -> V_198 , V_104 ) ;
V_19 -> V_248 = F_188 ( & V_325 -> V_84 , 2 * V_104 ,
V_128 ) ;
if ( ! V_19 -> V_248 )
return - V_89 ;
V_19 -> V_248 = F_48 ( V_19 -> V_248 , V_104 ) ;
V_330 = F_173 ( V_19 ) ;
if ( V_330 )
goto V_335;
V_330 = F_195 ( & V_325 -> V_84 , V_308 , F_176 , 0 ,
L_35 , V_19 ) ;
if ( V_330 )
goto V_336;
V_20 = & V_325 -> V_84 ;
V_330 = F_196 ( V_337 , F_35 ( V_337 ) ) ;
if ( V_330 ) {
F_197 ( V_84 , L_36 ) ;
goto V_336;
}
if ( V_33 != V_49 ) {
V_330 = F_196 ( V_338 ,
F_35 ( V_338 ) ) ;
if ( V_330 ) {
F_197 ( V_84 , L_36 ) ;
goto V_339;
}
}
V_330 = F_198 ( V_340 , F_35 ( V_340 ) ) ;
if ( V_330 ) {
F_197 ( V_84 , L_37 ) ;
goto V_341;
}
V_330 = F_199 ( V_342 , F_35 ( V_342 ) ) ;
if ( V_330 ) {
F_197 ( V_84 , L_38 ) ;
goto V_343;
}
return 0 ;
V_343:
F_200 ( V_340 , F_35 ( V_340 ) ) ;
V_341:
if ( V_33 != V_49 )
F_201 ( V_338 ,
F_35 ( V_338 ) ) ;
V_339:
F_201 ( V_337 , F_35 ( V_337 ) ) ;
V_336:
F_175 ( V_19 ) ;
V_335:
F_202 ( V_19 -> V_130 ) ;
return V_330 ;
}
static int F_203 ( struct V_324 * V_325 )
{
struct V_18 * V_19 = F_204 ( V_325 ) ;
int V_308 = F_187 ( V_325 , 0 ) ;
F_201 ( V_337 , F_35 ( V_337 ) ) ;
if ( V_19 -> V_33 != V_49 )
F_201 ( V_338 ,
F_35 ( V_338 ) ) ;
F_200 ( V_340 , F_35 ( V_340 ) ) ;
F_205 ( V_342 , F_35 ( V_342 ) ) ;
F_206 ( & V_19 -> V_254 ) ;
F_207 ( & V_325 -> V_84 , V_308 , V_19 ) ;
F_208 ( & V_19 -> V_254 ) ;
F_209 ( & V_19 -> V_252 ) ;
F_175 ( V_19 ) ;
F_202 ( V_19 -> V_130 ) ;
#ifdef F_193
F_181 () ;
#endif
return 0 ;
}
