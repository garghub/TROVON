int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
const char * V_8 ;
const struct V_9 * V_10 ;
unsigned V_11 , V_12 , V_13 ;
int V_14 , V_15 ;
F_2 ( & V_2 -> V_16 . V_17 , V_18 ) ;
switch ( V_2 -> V_19 ) {
#ifdef F_3
case V_20 :
V_8 = V_21 ;
break;
case V_22 :
V_8 = V_23 ;
break;
case V_24 :
V_8 = V_25 ;
break;
case V_26 :
V_8 = V_27 ;
break;
case V_28 :
V_8 = V_29 ;
break;
#endif
case V_30 :
V_8 = V_31 ;
break;
case V_32 :
V_8 = V_33 ;
break;
case V_34 :
V_8 = V_35 ;
break;
case V_36 :
V_8 = V_37 ;
break;
case V_38 :
V_8 = V_39 ;
break;
case V_40 :
V_8 = V_41 ;
break;
case V_42 :
V_8 = V_43 ;
break;
case V_44 :
V_8 = V_45 ;
break;
default:
return - V_46 ;
}
V_15 = F_4 ( & V_2 -> V_16 . V_47 , V_8 , V_2 -> V_48 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_48 , L_1 ,
V_8 ) ;
return V_15 ;
}
V_15 = F_6 ( V_2 -> V_16 . V_47 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_48 , L_2 ,
V_8 ) ;
F_7 ( V_2 -> V_16 . V_47 ) ;
V_2 -> V_16 . V_47 = NULL ;
return V_15 ;
}
V_2 -> V_16 . V_49 = V_50 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_47 -> V_51 ;
V_13 = F_8 ( V_10 -> V_52 ) & 0xff ;
V_11 = ( F_8 ( V_10 -> V_52 ) >> 24 ) & 0xff ;
V_12 = ( F_8 ( V_10 -> V_52 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_11 , V_12 , V_13 ) ;
if ( ( V_11 > 0x01 ) ||
( ( V_11 == 0x01 ) && ( V_12 >= 0x50 ) ) )
V_2 -> V_16 . V_49 = V_53 ;
V_2 -> V_16 . V_54 = ( ( V_11 << 24 ) | ( V_12 << 16 ) |
( V_13 << 8 ) ) ;
if ( ( V_2 -> V_19 == V_38 ||
V_2 -> V_19 == V_40 ) &&
( V_2 -> V_16 . V_54 < V_55 ) )
F_10 ( L_4 ,
V_11 , V_12 ) ;
V_7 = V_56 + V_57
+ V_58 * V_2 -> V_16 . V_49 ;
if ( V_2 -> V_59 . V_60 != V_61 )
V_7 += F_11 ( F_8 ( V_10 -> V_62 ) + 8 ) ;
V_15 = F_12 ( V_2 , V_7 , V_63 ,
V_64 , & V_2 -> V_16 . V_65 ,
& V_2 -> V_16 . V_66 , & V_2 -> V_16 . V_67 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_48 , L_5 , V_15 ) ;
return V_15 ;
}
V_4 = & V_2 -> V_16 . V_4 ;
V_6 = & V_4 -> V_68 . V_69 [ V_70 ] ;
V_15 = F_13 ( & V_4 -> V_68 , & V_2 -> V_16 . V_71 ,
V_6 , V_72 ) ;
if ( V_15 != 0 ) {
F_10 ( L_6 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 ) {
F_14 ( & V_2 -> V_16 . V_73 [ V_14 ] , 0 ) ;
V_2 -> V_16 . V_74 [ V_14 ] = NULL ;
}
if ( ! F_15 ( V_2 , V_75 , 5 , 0 ) )
V_2 -> V_16 . V_76 = true ;
switch ( V_2 -> V_19 ) {
case V_30 :
V_2 -> V_16 . V_77 = V_2 -> V_16 . V_54 >= V_78 ;
break;
case V_34 :
V_2 -> V_16 . V_77 = V_2 -> V_16 . V_54 >= V_79 ;
break;
case V_32 :
V_2 -> V_16 . V_77 = V_2 -> V_16 . V_54 >= V_80 ;
break;
case V_36 :
V_2 -> V_16 . V_77 = V_2 -> V_16 . V_54 >= V_81 ;
break;
default:
V_2 -> V_16 . V_77 = V_2 -> V_19 >= V_38 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_16 . V_82 ) ;
F_18 ( & V_2 -> V_16 . V_4 . V_68 , & V_2 -> V_16 . V_71 ) ;
F_19 ( & V_2 -> V_16 . V_65 ,
& V_2 -> V_16 . V_66 ,
( void * * ) & V_2 -> V_16 . V_67 ) ;
F_20 ( & V_2 -> V_16 . V_4 ) ;
F_7 ( V_2 -> V_16 . V_47 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned V_83 ;
void * V_84 ;
int V_14 ;
if ( V_2 -> V_16 . V_65 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 )
if ( F_22 ( & V_2 -> V_16 . V_73 [ V_14 ] ) )
break;
if ( V_14 == V_53 )
return 0 ;
F_23 ( & V_2 -> V_16 . V_17 ) ;
V_83 = F_24 ( V_2 -> V_16 . V_65 ) ;
V_84 = V_2 -> V_16 . V_67 ;
V_2 -> V_16 . V_82 = F_25 ( V_83 , V_85 ) ;
if ( ! V_2 -> V_16 . V_82 )
return - V_86 ;
F_26 ( V_2 -> V_16 . V_82 , V_84 , V_83 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_83 ;
void * V_84 ;
if ( V_2 -> V_16 . V_65 == NULL )
return - V_46 ;
V_83 = F_24 ( V_2 -> V_16 . V_65 ) ;
V_84 = V_2 -> V_16 . V_67 ;
if ( V_2 -> V_16 . V_82 != NULL ) {
F_28 ( V_84 , V_2 -> V_16 . V_82 , V_83 ) ;
F_17 ( V_2 -> V_16 . V_82 ) ;
V_2 -> V_16 . V_82 = NULL ;
} else {
const struct V_9 * V_10 ;
unsigned V_87 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_47 -> V_51 ;
if ( V_2 -> V_59 . V_60 != V_61 ) {
V_87 = F_8 ( V_10 -> V_88 ) ;
F_28 ( V_2 -> V_16 . V_67 , V_2 -> V_16 . V_47 -> V_51 + V_87 ,
F_8 ( V_10 -> V_62 ) ) ;
V_83 -= F_8 ( V_10 -> V_62 ) ;
V_84 += F_8 ( V_10 -> V_62 ) ;
}
F_29 ( V_84 , 0 , V_83 ) ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 , struct V_89 * V_74 )
{
struct V_3 * V_4 = & V_2 -> V_16 . V_4 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 ) {
T_1 V_90 = F_22 ( & V_2 -> V_16 . V_73 [ V_14 ] ) ;
if ( V_90 != 0 && V_2 -> V_16 . V_74 [ V_14 ] == V_74 ) {
struct V_91 * V_92 ;
V_15 = F_31 ( V_4 , V_90 ,
false , & V_92 ) ;
if ( V_15 ) {
F_10 ( L_7 , V_15 ) ;
continue;
}
F_32 ( V_92 , false ) ;
F_33 ( V_92 ) ;
V_2 -> V_16 . V_74 [ V_14 ] = NULL ;
F_14 ( & V_2 -> V_16 . V_73 [ V_14 ] , 0 ) ;
}
}
}
static void F_34 ( struct V_93 * V_94 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_94 -> V_95 . V_96 ; ++ V_14 ) {
V_94 -> V_97 [ V_14 ] . V_98 = 0 >> V_99 ;
V_94 -> V_97 [ V_14 ] . V_100 = ( 256 * 1024 * 1024 ) >> V_99 ;
}
}
static T_2 F_35 ( struct V_101 * V_102 )
{
T_1 V_103 , V_104 ;
T_3 V_105 ;
V_103 = F_36 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_108 ) ;
V_104 = F_36 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_109 ) ;
V_105 = ( ( T_3 ) V_103 ) | ( ( ( T_3 ) V_104 ) << 32 ) ;
return V_105 ;
}
static int F_37 ( struct V_101 * V_102 )
{
struct V_110 * V_111 ;
struct V_93 * V_112 ;
T_1 V_113 ;
T_3 V_105 = F_35 ( V_102 ) ;
int V_15 = 0 ;
V_111 = F_38 ( V_102 -> V_106 , V_105 , & V_112 ) ;
if ( V_111 == NULL ) {
F_10 ( L_8 , V_105 ) ;
return - V_46 ;
}
if ( ! V_102 -> V_106 -> V_2 -> V_16 . V_76 ) {
V_113 = F_36 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_114 ) >> 1 ;
if ( V_113 == 0x0 || V_113 == 0x3 ) {
T_1 V_115 = V_64 ;
F_39 ( V_112 , V_115 ) ;
}
F_34 ( V_112 ) ;
V_15 = F_40 ( & V_112 -> V_116 , & V_112 -> V_95 , false , false ) ;
}
return V_15 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_117 ,
unsigned V_118 [] )
{
unsigned V_119 = V_117 [ 4 ] ;
unsigned V_120 = V_117 [ 6 ] ;
unsigned V_121 = V_117 [ 7 ] ;
unsigned V_122 = V_117 [ 9 ] ;
unsigned V_123 = V_117 [ 28 ] ;
unsigned V_124 = V_117 [ 57 ] ;
unsigned V_125 = V_120 / 16 ;
unsigned V_126 = F_42 ( V_121 / 16 , 2 ) ;
unsigned V_127 = V_125 * V_126 ;
unsigned V_128 , V_129 , V_130 , V_131 ;
unsigned V_132 = ~ 0 ;
V_128 = V_120 * V_121 ;
V_128 += V_128 / 2 ;
V_128 = F_42 ( V_128 , 1024 ) ;
switch ( V_119 ) {
case 0 :
switch( V_124 ) {
case 30 :
V_131 = 8100 / V_127 ;
break;
case 31 :
V_131 = 18000 / V_127 ;
break;
case 32 :
V_131 = 20480 / V_127 ;
break;
case 41 :
V_131 = 32768 / V_127 ;
break;
case 42 :
V_131 = 34816 / V_127 ;
break;
case 50 :
V_131 = 110400 / V_127 ;
break;
case 51 :
V_131 = 184320 / V_127 ;
break;
default:
V_131 = 184320 / V_127 ;
break;
}
V_131 ++ ;
if ( V_131 > 17 )
V_131 = 17 ;
V_130 = V_128 * V_131 ;
V_130 += V_125 * V_126 * V_131 * 192 ;
V_130 += V_125 * V_126 * 32 ;
break;
case 1 :
V_130 = V_128 * 3 ;
V_130 += V_125 * V_126 * 128 ;
V_130 += V_125 * 64 ;
V_130 += V_125 * 128 ;
V_129 = F_43 ( V_125 , V_126 ) ;
V_130 += F_42 ( V_129 * 7 * 16 , 64 ) ;
break;
case 3 :
V_130 = V_128 * 3 ;
break;
case 4 :
V_130 = V_128 * 3 ;
V_130 += V_125 * V_126 * 64 ;
V_130 += F_42 ( V_125 * V_126 * 32 , 64 ) ;
break;
case 7 :
switch( V_124 ) {
case 30 :
V_131 = 8100 / V_127 ;
break;
case 31 :
V_131 = 18000 / V_127 ;
break;
case 32 :
V_131 = 20480 / V_127 ;
break;
case 41 :
V_131 = 32768 / V_127 ;
break;
case 42 :
V_131 = 34816 / V_127 ;
break;
case 50 :
V_131 = 110400 / V_127 ;
break;
case 51 :
V_131 = 184320 / V_127 ;
break;
default:
V_131 = 184320 / V_127 ;
break;
}
V_131 ++ ;
if ( V_131 > 17 )
V_131 = 17 ;
V_130 = V_128 * V_131 ;
if ( ! V_2 -> V_16 . V_77 ) {
V_130 +=
V_125 * V_126 * V_131 * 192 ;
V_130 += V_125 * V_126 * 32 ;
} else {
V_132 =
V_125 * V_126 * V_131 * 192 ;
}
break;
case 8 :
V_130 = 0 ;
break;
case 16 :
V_128 = ( F_42 ( V_120 , 16 ) * F_42 ( V_121 , 16 ) * 3 ) / 2 ;
V_128 = F_42 ( V_128 , 256 ) ;
V_131 = ( F_8 ( V_117 [ 59 ] ) & 0xff ) + 2 ;
V_130 = V_128 * V_131 ;
V_132 = ( ( V_120 + 255 ) / 16 ) * ( ( V_121 + 255 ) / 16 )
* 16 * V_131 + 52 * 1024 ;
break;
default:
F_10 ( L_9 , V_119 ) ;
return - V_46 ;
}
if ( V_120 > V_123 ) {
F_10 ( L_10 ) ;
return - V_46 ;
}
if ( V_122 < V_130 ) {
F_10 ( L_11 ,
V_122 , V_130 ) ;
return - V_46 ;
}
V_118 [ 0x1 ] = V_122 ;
V_118 [ 0x2 ] = V_128 ;
V_118 [ 0x4 ] = V_132 ;
return 0 ;
}
static int F_44 ( struct V_101 * V_102 ,
struct V_93 * V_112 , unsigned V_87 )
{
struct V_1 * V_2 = V_102 -> V_106 -> V_2 ;
T_4 * V_117 , V_133 , V_90 ;
void * V_84 ;
long V_15 ;
int V_14 ;
if ( V_87 & 0x3F ) {
F_10 ( L_12 ) ;
return - V_46 ;
}
V_15 = F_45 ( V_112 , & V_84 ) ;
if ( V_15 ) {
F_10 ( L_13 , V_15 ) ;
return V_15 ;
}
V_117 = V_84 + V_87 ;
V_133 = V_117 [ 1 ] ;
V_90 = V_117 [ 2 ] ;
if ( V_90 == 0 ) {
F_10 ( L_14 ) ;
return - V_46 ;
}
switch ( V_133 ) {
case 0 :
F_46 ( V_112 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_73 [ V_14 ] ) == V_90 ) {
F_10 ( L_15 , V_90 ) ;
return - V_46 ;
}
if ( ! F_47 ( & V_2 -> V_16 . V_73 [ V_14 ] , 0 , V_90 ) ) {
V_2 -> V_16 . V_74 [ V_14 ] = V_102 -> V_106 -> V_74 ;
return 0 ;
}
}
F_10 ( L_16 ) ;
return - V_134 ;
case 1 :
V_15 = F_41 ( V_2 , V_117 , V_102 -> V_118 ) ;
F_46 ( V_112 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_73 [ V_14 ] ) == V_90 ) {
if ( V_2 -> V_16 . V_74 [ V_14 ] != V_102 -> V_106 -> V_74 ) {
F_10 ( L_17 ) ;
return - V_46 ;
}
return 0 ;
}
}
F_10 ( L_18 , V_90 ) ;
return - V_135 ;
case 2 :
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 )
F_47 ( & V_2 -> V_16 . V_73 [ V_14 ] , V_90 , 0 ) ;
F_46 ( V_112 ) ;
return 0 ;
default:
F_10 ( L_19 , V_133 ) ;
return - V_46 ;
}
F_48 () ;
return - V_46 ;
}
static int F_49 ( struct V_101 * V_102 )
{
struct V_110 * V_111 ;
struct V_93 * V_112 ;
T_1 V_113 ;
T_3 V_136 , V_137 ;
T_3 V_105 = F_35 ( V_102 ) ;
int V_15 ;
V_111 = F_38 ( V_102 -> V_106 , V_105 , & V_112 ) ;
if ( V_111 == NULL ) {
F_10 ( L_8 , V_105 ) ;
return - V_46 ;
}
V_136 = F_50 ( V_112 ) ;
V_137 = ( V_111 -> V_138 + 1 - V_111 -> V_136 ) ;
V_137 = V_137 * V_139 + V_136 ;
V_105 -= V_111 -> V_136 * V_139 ;
V_136 += V_105 ;
F_51 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_108 ,
F_52 ( V_136 ) ) ;
F_51 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_109 ,
F_53 ( V_136 ) ) ;
V_113 = F_36 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_114 ) >> 1 ;
if ( V_113 < 0x4 ) {
if ( ( V_137 - V_136 ) < V_102 -> V_118 [ V_113 ] ) {
F_10 ( L_20 , V_113 ,
( unsigned ) ( V_137 - V_136 ) ,
V_102 -> V_118 [ V_113 ] ) ;
return - V_46 ;
}
} else if ( V_113 == 0x206 ) {
if ( ( V_137 - V_136 ) < V_102 -> V_118 [ 4 ] ) {
F_10 ( L_20 , V_113 ,
( unsigned ) ( V_137 - V_136 ) ,
V_102 -> V_118 [ 4 ] ) ;
return - V_46 ;
}
} else if ( ( V_113 != 0x100 ) && ( V_113 != 0x204 ) ) {
F_10 ( L_21 , V_113 ) ;
return - V_46 ;
}
if ( ! V_102 -> V_106 -> V_2 -> V_16 . V_76 ) {
if ( ( V_136 >> 28 ) != ( ( V_137 - 1 ) >> 28 ) ) {
F_10 ( L_22 ,
V_136 , V_137 ) ;
return - V_46 ;
}
if ( ( V_113 == 0 || V_113 == 0x3 ) &&
( V_136 >> 28 ) != ( V_102 -> V_106 -> V_2 -> V_16 . V_66 >> 28 ) ) {
F_10 ( L_23 ,
V_136 , V_137 ) ;
return - V_46 ;
}
}
if ( V_113 == 0 ) {
V_102 -> V_140 = true ;
V_15 = F_44 ( V_102 , V_112 , V_105 ) ;
if ( V_15 )
return V_15 ;
} else if ( ! V_102 -> V_140 ) {
F_10 ( L_24 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_54 ( struct V_101 * V_102 ,
int (* F_55)( struct V_101 * V_102 ) )
{
struct V_141 * V_142 = & V_102 -> V_106 -> V_143 -> V_144 [ V_102 -> V_107 ] ;
int V_14 , V_15 ;
V_102 -> V_114 ++ ;
for ( V_14 = 0 ; V_14 <= V_102 -> V_145 ; ++ V_14 ) {
unsigned V_146 = V_102 -> V_146 + V_14 ;
if ( V_102 -> V_114 >= V_142 -> V_147 ) {
F_10 ( L_25 ) ;
return - V_46 ;
}
switch ( V_146 ) {
case V_148 :
V_102 -> V_108 = V_102 -> V_114 ;
break;
case V_149 :
V_102 -> V_109 = V_102 -> V_114 ;
break;
case V_150 :
V_15 = F_55 ( V_102 ) ;
if ( V_15 )
return V_15 ;
break;
case V_151 :
case V_152 :
break;
default:
F_10 ( L_26 , V_146 ) ;
return - V_46 ;
}
V_102 -> V_114 ++ ;
}
return 0 ;
}
static int F_56 ( struct V_101 * V_102 ,
int (* F_55)( struct V_101 * V_102 ) )
{
struct V_141 * V_142 = & V_102 -> V_106 -> V_143 -> V_144 [ V_102 -> V_107 ] ;
int V_15 ;
for ( V_102 -> V_114 = 0 ; V_102 -> V_114 < V_142 -> V_147 ; ) {
T_1 V_113 = F_36 ( V_102 -> V_106 , V_102 -> V_107 , V_102 -> V_114 ) ;
unsigned type = F_57 ( V_113 ) ;
switch ( type ) {
case V_153 :
V_102 -> V_146 = F_58 ( V_113 ) ;
V_102 -> V_145 = F_59 ( V_113 ) ;
V_15 = F_54 ( V_102 , F_55 ) ;
if ( V_15 )
return V_15 ;
break;
case V_154 :
++ V_102 -> V_114 ;
break;
default:
F_10 ( L_27 , type ) ;
return - V_46 ;
}
}
return 0 ;
}
int F_60 ( struct V_155 * V_106 , T_1 V_107 )
{
struct V_101 V_102 = {} ;
unsigned V_118 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_141 * V_142 = & V_106 -> V_143 -> V_144 [ V_107 ] ;
int V_15 ;
V_106 -> V_143 -> V_156 = NULL ;
V_142 -> V_66 = F_61 ( V_142 -> V_157 ) ;
if ( V_142 -> V_147 % 16 ) {
F_10 ( L_28 ,
V_142 -> V_147 ) ;
return - V_46 ;
}
V_15 = F_62 ( V_106 ) ;
if ( V_15 )
return V_15 ;
V_102 . V_106 = V_106 ;
V_102 . V_118 = V_118 ;
V_102 . V_107 = V_107 ;
if ( ! V_106 -> V_2 -> V_16 . V_76 ) {
V_15 = F_56 ( & V_102 , F_37 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_56 ( & V_102 , F_49 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_102 . V_140 ) {
F_10 ( L_29 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_63 ( struct V_3 * V_4 , struct V_93 * V_112 ,
bool V_158 , struct V_91 * * V_92 )
{
struct V_159 V_160 ;
struct V_161 V_162 ;
struct V_163 V_164 ;
struct V_165 * V_143 ;
struct V_141 * V_142 ;
struct V_91 * V_166 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_105 ;
T_1 V_51 [ 4 ] ;
int V_14 , V_15 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_160 . V_112 = & V_112 -> V_116 ;
F_64 ( & V_164 ) ;
F_65 ( & V_160 . V_164 , & V_164 ) ;
V_15 = F_66 ( & V_162 , & V_164 , true , NULL ) ;
if ( V_15 )
return V_15 ;
if ( ! V_4 -> V_2 -> V_16 . V_76 ) {
F_39 ( V_112 , V_64 ) ;
F_34 ( V_112 ) ;
}
V_15 = F_40 ( & V_112 -> V_116 , & V_112 -> V_95 , true , false ) ;
if ( V_15 )
goto V_167;
V_15 = F_67 ( V_2 , 64 , & V_143 ) ;
if ( V_15 )
goto V_167;
if ( V_2 -> V_19 >= V_42 ) {
V_51 [ 0 ] = F_68 ( V_168 , 0 ) ;
V_51 [ 1 ] = F_68 ( V_169 , 0 ) ;
V_51 [ 2 ] = F_68 ( V_170 , 0 ) ;
V_51 [ 3 ] = F_68 ( V_171 , 0 ) ;
} else {
V_51 [ 0 ] = F_68 ( V_148 , 0 ) ;
V_51 [ 1 ] = F_68 ( V_149 , 0 ) ;
V_51 [ 2 ] = F_68 ( V_150 , 0 ) ;
V_51 [ 3 ] = F_68 ( V_152 , 0 ) ;
}
V_142 = & V_143 -> V_144 [ 0 ] ;
V_105 = F_50 ( V_112 ) ;
V_142 -> V_84 [ 0 ] = V_51 [ 0 ] ;
V_142 -> V_84 [ 1 ] = V_105 ;
V_142 -> V_84 [ 2 ] = V_51 [ 1 ] ;
V_142 -> V_84 [ 3 ] = V_105 >> 32 ;
V_142 -> V_84 [ 4 ] = V_51 [ 2 ] ;
V_142 -> V_84 [ 5 ] = 0 ;
for ( V_14 = 6 ; V_14 < 16 ; V_14 += 2 ) {
V_142 -> V_84 [ V_14 ] = V_51 [ 3 ] ;
V_142 -> V_84 [ V_14 + 1 ] = 0 ;
}
V_142 -> V_147 = 16 ;
if ( V_158 ) {
V_15 = F_69 ( V_4 , 1 , V_142 , NULL , & V_166 ) ;
V_143 -> V_92 = F_70 ( V_166 ) ;
if ( V_15 )
goto V_172;
F_71 ( V_143 ) ;
} else {
V_15 = F_72 ( V_143 , V_4 , & V_2 -> V_16 . V_71 ,
V_173 , & V_166 ) ;
if ( V_15 )
goto V_172;
}
F_73 ( & V_162 , & V_164 , V_166 ) ;
if ( V_92 )
* V_92 = F_70 ( V_166 ) ;
F_74 ( & V_112 ) ;
F_33 ( V_166 ) ;
return 0 ;
V_172:
F_71 ( V_143 ) ;
V_167:
F_75 ( & V_162 , & V_164 ) ;
return V_15 ;
}
int F_76 ( struct V_3 * V_4 , T_1 V_90 ,
struct V_91 * * V_92 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_93 * V_112 ;
T_1 * V_117 ;
int V_15 , V_14 ;
V_15 = F_77 ( V_2 , 1024 , V_63 , true ,
V_64 ,
V_174 |
V_175 ,
NULL , NULL , 0 , & V_112 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_78 ( V_112 , false ) ;
if ( V_15 ) {
F_74 ( & V_112 ) ;
return V_15 ;
}
V_15 = F_45 ( V_112 , ( void * * ) & V_117 ) ;
if ( V_15 ) {
F_79 ( V_112 ) ;
F_74 ( & V_112 ) ;
return V_15 ;
}
V_117 [ 0 ] = F_80 ( 0x00000de4 ) ;
V_117 [ 1 ] = F_80 ( 0x00000000 ) ;
V_117 [ 2 ] = F_80 ( V_90 ) ;
V_117 [ 3 ] = F_80 ( 0x00000000 ) ;
V_117 [ 4 ] = F_80 ( 0x00000000 ) ;
V_117 [ 5 ] = F_80 ( 0x00000000 ) ;
V_117 [ 6 ] = F_80 ( 0x00000000 ) ;
V_117 [ 7 ] = F_80 ( 0x00000780 ) ;
V_117 [ 8 ] = F_80 ( 0x00000440 ) ;
V_117 [ 9 ] = F_80 ( 0x00000000 ) ;
V_117 [ 10 ] = F_80 ( 0x01b37000 ) ;
for ( V_14 = 11 ; V_14 < 1024 ; ++ V_14 )
V_117 [ V_14 ] = F_80 ( 0x0 ) ;
F_46 ( V_112 ) ;
F_79 ( V_112 ) ;
return F_63 ( V_4 , V_112 , true , V_92 ) ;
}
int F_31 ( struct V_3 * V_4 , T_1 V_90 ,
bool V_158 , struct V_91 * * V_92 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_93 * V_112 ;
T_1 * V_117 ;
int V_15 , V_14 ;
V_15 = F_77 ( V_2 , 1024 , V_63 , true ,
V_64 ,
V_174 |
V_175 ,
NULL , NULL , 0 , & V_112 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_78 ( V_112 , false ) ;
if ( V_15 ) {
F_74 ( & V_112 ) ;
return V_15 ;
}
V_15 = F_45 ( V_112 , ( void * * ) & V_117 ) ;
if ( V_15 ) {
F_79 ( V_112 ) ;
F_74 ( & V_112 ) ;
return V_15 ;
}
V_117 [ 0 ] = F_80 ( 0x00000de4 ) ;
V_117 [ 1 ] = F_80 ( 0x00000002 ) ;
V_117 [ 2 ] = F_80 ( V_90 ) ;
V_117 [ 3 ] = F_80 ( 0x00000000 ) ;
for ( V_14 = 4 ; V_14 < 1024 ; ++ V_14 )
V_117 [ V_14 ] = F_80 ( 0x0 ) ;
F_46 ( V_112 ) ;
F_79 ( V_112 ) ;
return F_63 ( V_4 , V_112 , V_158 , V_92 ) ;
}
static void V_18 ( struct V_176 * V_177 )
{
struct V_1 * V_2 =
F_81 ( V_177 , struct V_1 , V_16 . V_17 . V_177 ) ;
unsigned V_178 = F_82 ( & V_2 -> V_16 . V_4 ) ;
if ( F_83 ( V_2 ) )
return;
if ( V_178 == 0 ) {
if ( V_2 -> V_179 . V_180 ) {
F_84 ( V_2 , false ) ;
} else {
F_85 ( V_2 , 0 , 0 ) ;
F_86 ( V_2 , V_75 ,
V_181 ) ;
F_87 ( V_2 , V_75 ,
V_182 ) ;
}
} else {
F_88 ( & V_2 -> V_16 . V_17 , V_183 ) ;
}
}
void F_89 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_184 = ! F_23 ( & V_2 -> V_16 . V_17 ) ;
if ( F_83 ( V_2 ) )
return;
if ( V_184 ) {
if ( V_2 -> V_179 . V_180 ) {
F_84 ( V_2 , true ) ;
} else {
F_85 ( V_2 , 53300 , 40000 ) ;
F_87 ( V_2 , V_75 ,
V_185 ) ;
F_86 ( V_2 , V_75 ,
V_186 ) ;
}
}
}
void F_90 ( struct V_3 * V_4 )
{
F_88 ( & V_4 -> V_2 -> V_16 . V_17 , V_183 ) ;
}
int F_91 ( struct V_3 * V_4 , long V_187 )
{
struct V_91 * V_92 ;
long V_15 ;
V_15 = F_76 ( V_4 , 1 , NULL ) ;
if ( V_15 ) {
F_10 ( L_30 , V_15 ) ;
goto error;
}
V_15 = F_31 ( V_4 , 1 , true , & V_92 ) ;
if ( V_15 ) {
F_10 ( L_31 , V_15 ) ;
goto error;
}
V_15 = F_92 ( V_92 , false , V_187 ) ;
if ( V_15 == 0 ) {
F_10 ( L_32 ) ;
V_15 = - V_188 ;
} else if ( V_15 < 0 ) {
F_10 ( L_33 , V_15 ) ;
} else {
F_9 ( L_34 , V_4 -> V_114 ) ;
V_15 = 0 ;
}
F_33 ( V_92 ) ;
error:
return V_15 ;
}
T_1 F_93 ( struct V_1 * V_2 )
{
unsigned V_14 ;
T_1 V_189 = 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_49 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_73 [ V_14 ] ) )
V_189 ++ ;
}
return V_189 ;
}
