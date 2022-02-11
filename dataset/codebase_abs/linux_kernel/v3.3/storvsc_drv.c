static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_7 -> V_8 ; ++ V_5 ) {
if ( V_4 -> V_7 -> V_9 )
V_6 = V_4 -> V_7 -> V_8 - V_5 - 1 ;
else
V_6 = V_5 ;
F_3 ( & V_4 -> V_7 -> V_10 , 0 ,
V_6 , V_11 , 1 ) ;
}
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_6 ( V_4 -> V_7 ) )
goto V_14;
V_13 = F_7 ( V_4 -> V_7 , 0 , 0 , V_4 -> V_15 ) ;
if ( V_13 ) {
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
}
F_10 ( V_4 -> V_7 ) ;
V_14:
F_4 ( V_4 ) ;
}
static inline struct V_16 * F_11 (
struct V_17 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 && V_19 -> V_20 )
V_19 = NULL ;
return V_19 ;
}
static inline void F_13 ( struct V_16 * V_21 )
{
V_21 -> V_22 = true ;
F_14 ( V_21 -> V_23 ,
F_15 ( & V_21 -> V_24 ) == 0 ) ;
V_21 -> V_22 = false ;
}
static inline struct V_16 * F_16 (
struct V_17 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_12 ( V_18 ) ;
if ( ! V_19 )
goto V_25;
if ( V_19 -> V_20 &&
( F_15 ( & V_19 -> V_24 ) == 0 ) )
V_19 = NULL ;
V_25:
return V_19 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
int V_29 , V_30 ;
V_19 = F_11 ( V_18 ) ;
if ( ! V_19 )
return - V_31 ;
V_27 = & V_19 -> V_32 ;
V_28 = & V_27 -> V_28 ;
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
F_18 ( & V_27 -> F_14 ) ;
V_28 -> V_33 = V_34 ;
V_28 -> V_35 = V_36 ;
V_29 = F_19 ( V_18 -> V_37 , V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) V_27 ,
V_38 ,
V_39 ) ;
if ( V_29 != 0 )
goto V_40;
V_30 = F_20 ( & V_27 -> F_14 , 5 * V_41 ) ;
if ( V_30 == 0 ) {
V_29 = - V_42 ;
goto V_40;
}
if ( V_28 -> V_33 != V_43 ||
V_28 -> V_44 != 0 )
goto V_40;
memset ( V_28 , 0 , sizeof( struct V_28 ) ) ;
V_28 -> V_33 = V_45 ;
V_28 -> V_35 = V_36 ;
V_28 -> V_46 . V_47 = V_48 ;
F_21 ( V_28 -> V_46 . V_49 ) ;
V_29 = F_19 ( V_18 -> V_37 , V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) V_27 ,
V_38 ,
V_39 ) ;
if ( V_29 != 0 )
goto V_40;
V_30 = F_20 ( & V_27 -> F_14 , 5 * V_41 ) ;
if ( V_30 == 0 ) {
V_29 = - V_42 ;
goto V_40;
}
if ( V_28 -> V_33 != V_43 ||
V_28 -> V_44 != 0 )
goto V_40;
memset ( V_28 , 0 , sizeof( struct V_28 ) ) ;
V_28 -> V_33 = V_50 ;
V_28 -> V_35 = V_36 ;
V_28 -> V_51 . V_52 =
V_19 -> V_52 ;
V_29 = F_19 ( V_18 -> V_37 , V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) V_27 ,
V_38 ,
V_39 ) ;
if ( V_29 != 0 )
goto V_40;
V_30 = F_20 ( & V_27 -> F_14 , 5 * V_41 ) ;
if ( V_30 == 0 ) {
V_29 = - V_42 ;
goto V_40;
}
if ( V_28 -> V_33 != V_43 ||
V_28 -> V_44 != 0 )
goto V_40;
V_19 -> V_53 = V_28 -> V_51 . V_53 ;
V_19 -> V_54
= V_28 -> V_51 . V_54 ;
memset ( V_28 , 0 , sizeof( struct V_28 ) ) ;
V_28 -> V_33 = V_55 ;
V_28 -> V_35 = V_36 ;
V_29 = F_19 ( V_18 -> V_37 , V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) V_27 ,
V_38 ,
V_39 ) ;
if ( V_29 != 0 )
goto V_40;
V_30 = F_20 ( & V_27 -> F_14 , 5 * V_41 ) ;
if ( V_30 == 0 ) {
V_29 = - V_42 ;
goto V_40;
}
if ( V_28 -> V_33 != V_43 ||
V_28 -> V_44 != 0 )
goto V_40;
V_40:
return V_29 ;
}
static void F_22 ( struct V_17 * V_18 ,
struct V_28 * V_28 ,
struct V_26 * V_27 )
{
struct V_16 * V_19 ;
struct V_28 * V_56 ;
V_19 = F_12 ( V_18 ) ;
V_56 = & V_27 -> V_28 ;
if ( ( V_56 -> V_57 . V_58 [ 0 ] == V_59 ) ||
( V_56 -> V_57 . V_58 [ 0 ] == V_60 ) ) {
V_28 -> V_57 . V_61 = 0 ;
V_28 -> V_57 . V_62 = 0x1 ;
}
V_56 -> V_57 . V_61 = V_28 -> V_57 . V_61 ;
V_56 -> V_57 . V_62 = V_28 -> V_57 . V_62 ;
V_56 -> V_57 . V_63 =
V_28 -> V_57 . V_63 ;
if ( V_28 -> V_57 . V_61 != 0 ||
V_28 -> V_57 . V_62 != 1 ) {
F_23 ( & V_18 -> V_18 ,
L_1 ,
V_56 -> V_57 . V_58 [ 0 ] ,
V_28 -> V_57 . V_61 ,
V_28 -> V_57 . V_62 ) ;
}
if ( ( V_28 -> V_57 . V_61 & 0xFF ) == 0x02 ) {
if ( V_28 -> V_57 . V_62 & 0x80 ) {
F_23 ( & V_18 -> V_18 ,
L_2 ,
V_27 ,
V_28 -> V_57 . V_63 ) ;
memcpy ( V_27 -> V_64 ,
V_28 -> V_57 . V_65 ,
V_28 -> V_57 . V_63 ) ;
}
}
V_56 -> V_57 . V_66 =
V_28 -> V_57 . V_66 ;
V_27 -> V_67 ( V_27 ) ;
if ( F_24 ( & V_19 -> V_24 ) &&
V_19 -> V_22 )
F_25 ( & V_19 -> V_23 ) ;
}
static void F_26 ( struct V_17 * V_18 ,
struct V_28 * V_28 ,
struct V_26 * V_27 )
{
struct V_3 * V_2 ;
struct V_16 * V_19 ;
switch ( V_28 -> V_33 ) {
case V_43 :
F_22 ( V_18 , V_28 , V_27 ) ;
break;
case V_68 :
case V_69 :
V_19 = F_16 ( V_18 ) ;
V_2 = F_27 ( sizeof( struct V_3 ) , V_70 ) ;
if ( ! V_2 )
return;
F_28 ( & V_2 -> V_2 , F_1 ) ;
V_2 -> V_7 = V_19 -> V_7 ;
F_29 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void F_30 ( void * V_71 )
{
struct V_17 * V_18 = (struct V_17 * ) V_71 ;
struct V_16 * V_19 ;
T_1 V_72 ;
T_2 V_73 ;
unsigned char V_74 [ F_31 ( sizeof( struct V_28 ) , 8 ) ] ;
struct V_26 * V_27 ;
int V_29 ;
V_19 = F_16 ( V_18 ) ;
if ( ! V_19 )
return;
do {
V_29 = F_32 ( V_18 -> V_37 , V_74 ,
F_31 ( sizeof( struct V_28 ) , 8 ) ,
& V_72 , & V_73 ) ;
if ( V_29 == 0 && V_72 > 0 ) {
V_27 = (struct V_26 * )
( unsigned long ) V_73 ;
if ( ( V_27 == & V_19 -> V_32 ) ||
( V_27 == & V_19 -> V_75 ) ) {
memcpy ( & V_27 -> V_28 , V_74 ,
sizeof( struct V_28 ) ) ;
F_33 ( & V_27 -> F_14 ) ;
} else {
F_26 ( V_18 ,
(struct V_28 * ) V_74 ,
V_27 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_34 ( struct V_17 * V_18 , T_1 V_76 )
{
struct V_77 V_78 ;
int V_29 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_29 = F_35 ( V_18 -> V_37 ,
V_76 ,
V_76 ,
( void * ) & V_78 ,
sizeof( struct V_77 ) ,
F_30 , V_18 ) ;
if ( V_29 != 0 )
return V_29 ;
V_29 = F_17 ( V_18 ) ;
return V_29 ;
}
static int F_36 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
unsigned long V_35 ;
V_19 = F_12 ( V_18 ) ;
F_37 ( & V_18 -> V_37 -> V_79 , V_35 ) ;
V_19 -> V_20 = true ;
F_38 ( & V_18 -> V_37 -> V_79 , V_35 ) ;
F_13 ( V_19 ) ;
F_37 ( & V_18 -> V_37 -> V_79 , V_35 ) ;
F_39 ( V_18 , NULL ) ;
F_38 ( & V_18 -> V_37 -> V_79 , V_35 ) ;
F_40 ( V_18 -> V_37 ) ;
F_4 ( V_19 ) ;
return 0 ;
}
static int F_41 ( struct V_17 * V_18 ,
struct V_26 * V_27 )
{
struct V_16 * V_19 ;
struct V_28 * V_28 ;
int V_29 = 0 ;
V_28 = & V_27 -> V_28 ;
V_19 = F_11 ( V_18 ) ;
if ( ! V_19 )
return - V_31 ;
V_27 -> V_18 = V_18 ;
V_28 -> V_35 |= V_36 ;
V_28 -> V_57 . V_80 = sizeof( struct V_81 ) ;
V_28 -> V_57 . V_63 = V_82 ;
V_28 -> V_57 . V_66 =
V_27 -> V_83 . V_84 ;
V_28 -> V_33 = V_85 ;
if ( V_27 -> V_83 . V_84 ) {
V_29 = F_42 ( V_18 -> V_37 ,
& V_27 -> V_83 ,
V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) V_27 ) ;
} else {
V_29 = F_19 ( V_18 -> V_37 , V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) V_27 ,
V_38 ,
V_39 ) ;
}
if ( V_29 != 0 )
return V_29 ;
F_43 ( & V_19 -> V_24 ) ;
return V_29 ;
}
static void F_44 ( struct V_17 * V_21 , int * V_86 , int * V_87 )
{
* V_86 =
V_21 -> V_88 . V_89 [ 5 ] << 8 | V_21 -> V_88 . V_89 [ 4 ] ;
* V_87 =
V_21 -> V_88 . V_89 [ 3 ] << 24 |
V_21 -> V_88 . V_89 [ 2 ] << 16 |
V_21 -> V_88 . V_89 [ 1 ] << 8 | V_21 -> V_88 . V_89 [ 0 ] ;
}
static int F_45 ( struct V_12 * V_90 )
{
struct V_91 * V_92 ;
int V_93 = V_94 ;
V_92 = F_46 ( sizeof( struct V_91 ) , V_95 ) ;
if ( ! V_92 )
return - V_96 ;
V_92 -> V_97 =
F_47 ( F_48 ( & V_90 -> V_98 ) ,
sizeof( struct V_99 ) , 0 ,
V_100 , NULL ) ;
if ( ! V_92 -> V_97 )
goto V_101;
V_92 -> V_102 = F_49 ( V_93 , V_103 ,
V_104 ,
V_92 -> V_97 ) ;
if ( ! V_92 -> V_102 )
goto V_105;
V_90 -> V_106 = V_92 ;
return 0 ;
V_105:
F_50 ( V_92 -> V_97 ) ;
V_101:
F_4 ( V_92 ) ;
return - V_96 ;
}
static void F_51 ( struct V_12 * V_90 )
{
struct V_91 * V_92 = V_90 -> V_106 ;
F_52 ( V_92 -> V_102 ) ;
F_50 ( V_92 -> V_97 ) ;
F_4 ( V_92 ) ;
V_90 -> V_106 = NULL ;
}
static int F_53 ( struct V_12 * V_90 )
{
F_54 ( V_90 , V_107 ,
V_108 ) ;
F_55 ( V_90 -> V_109 , V_110 ) ;
F_56 ( V_90 -> V_109 , V_111 ) ;
return 0 ;
}
static void F_57 ( struct V_112 * V_113 ,
unsigned int V_114 )
{
int V_115 ;
struct V_116 * V_117 ;
for ( V_115 = 0 ; V_115 < V_114 ; V_115 ++ ) {
V_117 = F_58 ( ( & V_113 [ V_115 ] ) ) ;
if ( V_117 != NULL )
F_59 ( V_117 ) ;
}
F_4 ( V_113 ) ;
}
static int F_60 ( struct V_112 * V_113 , unsigned int V_114 )
{
int V_115 ;
if ( V_114 < 2 )
return - 1 ;
for ( V_115 = 0 ; V_115 < V_114 ; V_115 ++ ) {
if ( V_115 == 0 ) {
if ( V_113 [ V_115 ] . V_118 + V_113 [ V_115 ] . V_80 != V_110 )
return V_115 ;
} else if ( V_115 == V_114 - 1 ) {
if ( V_113 [ V_115 ] . V_118 != 0 )
return V_115 ;
} else {
if ( V_113 [ V_115 ] . V_80 != V_110 || V_113 [ V_115 ] . V_118 != 0 )
return V_115 ;
}
}
return - 1 ;
}
static struct V_112 * F_61 ( struct V_112 * V_113 ,
unsigned int V_114 ,
unsigned int V_84 ,
int V_119 )
{
int V_115 ;
int V_120 ;
struct V_112 * V_121 ;
struct V_116 * V_117 ;
unsigned int V_122 = ( ( V_119 == V_123 ) ? 0 : V_110 ) ;
V_120 = F_31 ( V_84 , V_110 ) >> V_124 ;
V_121 = F_62 ( V_120 , sizeof( struct V_112 ) , V_70 ) ;
if ( ! V_121 )
return NULL ;
for ( V_115 = 0 ; V_115 < V_120 ; V_115 ++ ) {
V_117 = F_63 ( V_70 ) ;
if ( ! V_117 )
goto V_40;
F_64 ( & V_121 [ V_115 ] , V_117 , V_122 , 0 ) ;
}
return V_121 ;
V_40:
F_57 ( V_121 , V_120 ) ;
return NULL ;
}
static unsigned int F_65 ( struct V_112 * V_125 ,
struct V_112 * V_121 ,
unsigned int V_126 ,
unsigned int V_127 )
{
int V_115 ;
int V_128 = 0 ;
unsigned long V_129 , V_130 ;
unsigned int V_131 , V_132 , V_133 ;
unsigned int V_134 = 0 ;
unsigned long V_135 = 0 ;
unsigned long V_136 = 0 ;
unsigned long V_35 ;
F_66 ( V_35 ) ;
for ( V_115 = 0 ; V_115 < V_126 ; V_115 ++ ) {
V_136 = ( unsigned long ) F_67 ( F_58 ( ( & V_125 [ V_115 ] ) ) ,
V_137 ) + V_125 [ V_115 ] . V_118 ;
V_130 = V_136 ;
V_132 = V_125 [ V_115 ] . V_80 ;
if ( V_135 == 0 )
V_135 =
( unsigned long ) F_67 ( F_58 ( ( & V_121 [ V_128 ] ) ) ,
V_137 ) ;
while ( V_132 ) {
V_129 = V_135 + V_121 [ V_128 ] . V_118 ;
V_131 = V_121 [ V_128 ] . V_80 - V_121 [ V_128 ] . V_118 ;
V_133 = F_68 ( V_131 , V_132 ) ;
memcpy ( ( void * ) V_130 , ( void * ) V_129 , V_133 ) ;
V_134 += V_133 ;
V_121 [ V_128 ] . V_118 += V_133 ;
V_132 -= V_133 ;
V_130 += V_133 ;
if ( V_121 [ V_128 ] . V_118 == V_121 [ V_128 ] . V_80 ) {
F_69 ( ( void * ) V_135 , V_137 ) ;
V_128 ++ ;
if ( V_128 == V_127 ) {
F_69 ( ( void * ) ( V_136 -
V_125 [ V_115 ] . V_118 ) ,
V_137 ) ;
F_70 ( V_35 ) ;
return V_134 ;
}
if ( V_132 || V_115 != V_126 - 1 )
V_135 =
( unsigned long ) F_67 (
F_58 ( ( & V_121 [ V_128 ] ) ) , V_137 ) ;
} else if ( V_132 == 0 && V_115 == V_126 - 1 ) {
F_69 ( ( void * ) V_135 , V_137 ) ;
}
}
F_69 ( ( void * ) ( V_136 - V_125 [ V_115 ] . V_118 ) ,
V_137 ) ;
}
F_70 ( V_35 ) ;
return V_134 ;
}
static unsigned int F_71 ( struct V_112 * V_125 ,
struct V_112 * V_121 ,
unsigned int V_126 )
{
int V_115 ;
int V_128 = 0 ;
unsigned long V_129 , V_130 ;
unsigned int V_131 , V_132 , V_133 ;
unsigned int V_134 = 0 ;
unsigned long V_135 = 0 ;
unsigned long V_138 = 0 ;
unsigned long V_35 ;
F_66 ( V_35 ) ;
for ( V_115 = 0 ; V_115 < V_126 ; V_115 ++ ) {
V_138 = ( unsigned long ) F_67 ( F_58 ( ( & V_125 [ V_115 ] ) ) ,
V_137 ) + V_125 [ V_115 ] . V_118 ;
V_129 = V_138 ;
V_131 = V_125 [ V_115 ] . V_80 ;
if ( V_135 == 0 )
V_135 =
( unsigned long ) F_67 ( F_58 ( ( & V_121 [ V_128 ] ) ) ,
V_137 ) ;
while ( V_131 ) {
V_130 = V_135 + V_121 [ V_128 ] . V_80 ;
V_132 = V_110 - V_121 [ V_128 ] . V_80 ;
V_133 = F_68 ( V_131 , V_132 ) ;
memcpy ( ( void * ) V_130 , ( void * ) V_129 , V_133 ) ;
V_134 += V_133 ;
V_121 [ V_128 ] . V_80 += V_133 ;
V_131 -= V_133 ;
V_129 += V_133 ;
if ( V_121 [ V_128 ] . V_80 == V_110 ) {
F_69 ( ( void * ) V_135 , V_137 ) ;
V_128 ++ ;
if ( V_131 || V_115 != V_126 - 1 )
V_135 =
( unsigned long ) F_67 (
F_58 ( ( & V_121 [ V_128 ] ) ) , V_137 ) ;
} else if ( V_131 == 0 && V_115 == V_126 - 1 ) {
F_69 ( ( void * ) V_135 , V_137 ) ;
}
}
F_69 ( ( void * ) ( V_138 - V_125 [ V_115 ] . V_118 ) , V_137 ) ;
}
F_70 ( V_35 ) ;
return V_134 ;
}
static int F_72 ( struct V_17 * V_21 )
{
struct V_16 * V_19 = F_12 ( V_21 ) ;
struct V_139 * V_7 = V_19 -> V_7 ;
F_73 ( V_7 ) ;
F_10 ( V_7 ) ;
F_36 ( V_21 ) ;
return 0 ;
}
static int F_74 ( struct V_12 * V_13 , struct V_140 * V_141 ,
T_3 V_142 , int * V_143 )
{
T_3 V_144 = V_142 ;
T_3 V_145 = V_144 ;
int V_146 , V_147 ;
V_146 = 0xff ;
V_147 = 0x3f ;
F_75 ( V_145 , V_146 * V_147 ) ;
if ( ( T_3 ) ( V_145 + 1 ) * V_146 * V_147 < V_144 )
V_145 = 0xffff ;
V_143 [ 0 ] = V_146 ;
V_143 [ 1 ] = V_147 ;
V_143 [ 2 ] = ( int ) V_145 ;
return 0 ;
}
static int F_76 ( struct V_17 * V_18 )
{
struct V_16 * V_19 ;
struct V_26 * V_27 ;
struct V_28 * V_28 ;
int V_29 , V_30 ;
V_19 = F_11 ( V_18 ) ;
if ( ! V_19 )
return V_148 ;
V_27 = & V_19 -> V_75 ;
V_28 = & V_27 -> V_28 ;
F_18 ( & V_27 -> F_14 ) ;
V_28 -> V_33 = V_149 ;
V_28 -> V_35 = V_36 ;
V_28 -> V_57 . V_53 = V_19 -> V_53 ;
V_29 = F_19 ( V_18 -> V_37 , V_28 ,
sizeof( struct V_28 ) ,
( unsigned long ) & V_19 -> V_75 ,
V_38 ,
V_39 ) ;
if ( V_29 != 0 )
return V_148 ;
V_30 = F_20 ( & V_27 -> F_14 , 5 * V_41 ) ;
if ( V_30 == 0 )
return V_150 ;
return V_151 ;
}
static int F_77 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = F_78 ( V_153 -> V_18 -> V_7 ) ;
struct V_17 * V_21 = V_155 -> V_21 ;
return F_76 ( V_21 ) ;
}
static void F_79 ( struct V_26 * V_27 )
{
struct V_99 * V_156 =
(struct V_99 * ) V_27 -> V_71 ;
struct V_152 * V_153 = V_156 -> V_157 ;
struct V_154 * V_155 = F_78 ( V_153 -> V_18 -> V_7 ) ;
void (* F_80)( struct V_152 * );
struct V_158 V_159 ;
struct V_81 * V_57 ;
struct V_3 * V_4 ;
struct V_91 * V_92 = V_153 -> V_18 -> V_106 ;
V_57 = & V_27 -> V_28 . V_57 ;
if ( V_156 -> V_127 ) {
if ( V_57 -> V_160 == V_161 )
F_65 ( F_81 ( V_153 ) ,
V_156 -> V_121 ,
F_82 ( V_153 ) ,
V_156 -> V_127 ) ;
F_57 ( V_156 -> V_121 ,
V_156 -> V_127 ) ;
}
if ( V_57 -> V_62 == 0x4 )
V_153 -> V_162 = V_163 << 16 ;
else
V_153 -> V_162 = V_57 -> V_61 ;
if ( V_57 -> V_62 == 0x20 ) {
struct V_16 * V_164 ;
struct V_17 * V_21 = V_155 -> V_21 ;
struct V_139 * V_7 ;
V_164 = F_16 ( V_21 ) ;
V_7 = V_164 -> V_7 ;
V_4 = F_27 ( sizeof( struct V_3 ) ,
V_70 ) ;
if ( ! V_4 ) {
V_153 -> V_162 = V_163 << 16 ;
} else {
V_4 -> V_7 = V_7 ;
V_4 -> V_15 = V_57 -> V_15 ;
F_28 ( & V_4 -> V_2 , F_5 ) ;
F_29 ( & V_4 -> V_2 ) ;
}
}
if ( V_153 -> V_162 ) {
if ( F_83 ( V_153 -> V_64 ,
V_165 , & V_159 ) )
F_84 ( L_3 , & V_159 ) ;
}
F_85 ( V_153 ,
V_27 -> V_83 . V_84 -
V_57 -> V_66 ) ;
F_80 = V_153 -> V_166 ;
V_153 -> V_167 = NULL ;
V_153 -> V_166 = NULL ;
F_80 ( V_153 ) ;
F_86 ( V_156 , V_92 -> V_102 ) ;
}
static bool F_87 ( struct V_152 * V_153 )
{
bool V_168 = true ;
T_4 V_169 = V_153 -> V_170 [ 0 ] ;
switch ( V_169 ) {
case V_171 :
V_153 -> V_162 = V_172 << 16 ;
V_168 = false ;
break;
default:
break;
}
return V_168 ;
}
static int F_88 ( struct V_139 * V_7 , struct V_152 * V_153 )
{
int V_29 ;
struct V_154 * V_155 = F_78 ( V_7 ) ;
struct V_17 * V_21 = V_155 -> V_21 ;
struct V_26 * V_27 ;
struct V_99 * V_156 ;
unsigned int V_173 = 0 ;
int V_115 ;
struct V_112 * V_113 ;
unsigned int V_114 = 0 ;
struct V_81 * V_57 ;
struct V_91 * V_92 = V_153 -> V_18 -> V_106 ;
if ( F_87 ( V_153 ) == false ) {
V_153 -> V_166 ( V_153 ) ;
return 0 ;
}
if ( V_153 -> V_167 ) {
V_156 =
(struct V_99 * ) V_153 -> V_167 ;
goto V_174;
}
V_173 = sizeof( struct V_99 ) ;
V_156 = F_89 ( V_92 -> V_102 ,
V_70 ) ;
if ( ! V_156 )
return V_175 ;
memset ( V_156 , 0 , sizeof( struct V_99 ) ) ;
V_156 -> V_127 = 0 ;
V_156 -> V_121 = NULL ;
V_156 -> V_157 = V_153 ;
V_153 -> V_167 = ( unsigned char * ) V_156 ;
V_27 = & V_156 -> V_27 ;
V_57 = & V_27 -> V_28 . V_57 ;
switch ( V_153 -> V_176 ) {
case V_177 :
V_57 -> V_160 = V_123 ;
break;
case V_178 :
V_57 -> V_160 = V_161 ;
break;
default:
V_57 -> V_160 = V_179 ;
break;
}
V_27 -> V_67 = F_79 ;
V_27 -> V_71 = V_156 ;
V_57 -> V_52 = V_155 -> V_180 ;
V_57 -> V_53 = V_153 -> V_18 -> V_37 ;
V_57 -> V_54 = V_153 -> V_18 -> V_5 ;
V_57 -> V_15 = V_153 -> V_18 -> V_15 ;
V_57 -> V_181 = V_153 -> V_182 ;
memcpy ( V_57 -> V_58 , V_153 -> V_170 , V_57 -> V_181 ) ;
V_27 -> V_64 = V_153 -> V_64 ;
V_27 -> V_83 . V_84 = F_90 ( V_153 ) ;
if ( F_82 ( V_153 ) ) {
V_113 = (struct V_112 * ) F_81 ( V_153 ) ;
V_114 = F_82 ( V_153 ) ;
if ( F_60 ( V_113 , F_82 ( V_153 ) ) != - 1 ) {
V_156 -> V_121 =
F_61 ( V_113 , F_82 ( V_153 ) ,
F_90 ( V_153 ) ,
V_57 -> V_160 ) ;
if ( ! V_156 -> V_121 ) {
V_153 -> V_167 = NULL ;
F_86 ( V_156 ,
V_92 -> V_102 ) ;
return V_183 ;
}
V_156 -> V_127 =
F_31 ( F_90 ( V_153 ) , V_110 ) >>
V_124 ;
if ( V_57 -> V_160 == V_123 )
F_71 ( V_113 ,
V_156 -> V_121 ,
F_82 ( V_153 ) ) ;
V_113 = V_156 -> V_121 ;
V_114 = V_156 -> V_127 ;
}
V_27 -> V_83 . V_118 = V_113 [ 0 ] . V_118 ;
for ( V_115 = 0 ; V_115 < V_114 ; V_115 ++ )
V_27 -> V_83 . V_184 [ V_115 ] =
F_91 ( F_58 ( ( & V_113 [ V_115 ] ) ) ) ;
} else if ( F_81 ( V_153 ) ) {
V_27 -> V_83 . V_118 =
F_92 ( F_81 ( V_153 ) ) & ( V_110 - 1 ) ;
V_27 -> V_83 . V_184 [ 0 ] =
F_92 ( F_81 ( V_153 ) ) >> V_124 ;
}
V_174:
V_29 = F_41 ( V_21 , & V_156 -> V_27 ) ;
if ( V_29 == - V_185 ) {
if ( V_156 -> V_127 )
F_57 ( V_156 -> V_121 ,
V_156 -> V_127 ) ;
F_86 ( V_156 , V_92 -> V_102 ) ;
V_153 -> V_167 = NULL ;
V_29 = V_175 ;
}
return V_29 ;
}
static int F_93 ( struct V_17 * V_18 ,
const struct V_186 * V_187 )
{
int V_29 ;
struct V_139 * V_7 ;
struct V_154 * V_155 ;
bool V_188 = ( ( V_187 -> V_189 == V_190 ) ? true : false ) ;
int V_87 = 0 ;
int V_86 = 0 ;
struct V_16 * V_19 ;
V_7 = F_94 ( & V_191 ,
sizeof( struct V_154 ) ) ;
if ( ! V_7 )
return - V_96 ;
V_155 = F_78 ( V_7 ) ;
memset ( V_155 , 0 , sizeof( struct V_154 ) ) ;
V_155 -> V_180 = V_7 -> V_192 ;
V_155 -> V_21 = V_18 ;
V_19 = F_46 ( sizeof( struct V_16 ) , V_95 ) ;
if ( ! V_19 ) {
V_29 = - V_96 ;
goto V_193;
}
V_19 -> V_20 = false ;
F_95 ( & V_19 -> V_23 ) ;
V_19 -> V_18 = V_18 ;
V_19 -> V_7 = V_7 ;
F_39 ( V_18 , V_19 ) ;
V_19 -> V_52 = V_7 -> V_192 ;
V_29 = F_34 ( V_18 , V_194 ) ;
if ( V_29 )
goto V_195;
if ( V_188 )
F_44 ( V_18 , & V_86 , & V_87 ) ;
V_155 -> V_87 = V_19 -> V_53 ;
V_155 -> V_86 = V_19 -> V_54 ;
V_7 -> V_196 = V_197 ;
V_7 -> V_8 = V_198 ;
V_7 -> V_199 = V_200 - 1 ;
V_7 -> V_201 = V_202 ;
V_29 = F_96 ( V_7 , & V_18 -> V_18 ) ;
if ( V_29 != 0 )
goto V_203;
if ( ! V_188 ) {
F_97 ( V_7 ) ;
return 0 ;
}
V_29 = F_98 ( V_7 , 0 , V_86 , 0 ) ;
if ( V_29 ) {
F_73 ( V_7 ) ;
goto V_203;
}
return 0 ;
V_203:
F_36 ( V_18 ) ;
goto V_193;
V_195:
F_4 ( V_19 ) ;
V_193:
F_10 ( V_7 ) ;
return V_29 ;
}
static int T_5 F_99 ( void )
{
T_1 V_204 ;
V_204 =
( ( V_194 - V_110 ) /
F_31 ( V_205 +
sizeof( struct V_28 ) + sizeof( T_2 ) ,
sizeof( T_2 ) ) ) ;
if ( V_204 <
V_108 )
return - V_206 ;
return F_100 ( & V_207 ) ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_207 ) ;
}
