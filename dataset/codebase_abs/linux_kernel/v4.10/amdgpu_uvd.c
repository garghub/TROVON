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
default:
return - V_44 ;
}
V_15 = F_4 ( & V_2 -> V_16 . V_45 , V_8 , V_2 -> V_46 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_46 , L_1 ,
V_8 ) ;
return V_15 ;
}
V_15 = F_6 ( V_2 -> V_16 . V_45 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_46 , L_2 ,
V_8 ) ;
F_7 ( V_2 -> V_16 . V_45 ) ;
V_2 -> V_16 . V_45 = NULL ;
return V_15 ;
}
V_2 -> V_16 . V_47 = V_48 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_45 -> V_49 ;
V_13 = F_8 ( V_10 -> V_50 ) & 0xff ;
V_11 = ( F_8 ( V_10 -> V_50 ) >> 24 ) & 0xff ;
V_12 = ( F_8 ( V_10 -> V_50 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_11 , V_12 , V_13 ) ;
if ( ( V_11 > 0x01 ) ||
( ( V_11 == 0x01 ) && ( V_12 >= 0x50 ) ) )
V_2 -> V_16 . V_47 = V_51 ;
V_2 -> V_16 . V_52 = ( ( V_11 << 24 ) | ( V_12 << 16 ) |
( V_13 << 8 ) ) ;
if ( ( V_2 -> V_19 == V_38 ||
V_2 -> V_19 == V_40 ) &&
( V_2 -> V_16 . V_52 < V_53 ) )
F_10 ( L_4 ,
V_11 , V_12 ) ;
V_7 = F_11 ( F_8 ( V_10 -> V_54 ) + 8 )
+ V_55 + V_56
+ V_57 * V_2 -> V_16 . V_47 ;
V_15 = F_12 ( V_2 , V_7 , V_58 ,
V_59 , & V_2 -> V_16 . V_60 ,
& V_2 -> V_16 . V_61 , & V_2 -> V_16 . V_62 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_46 , L_5 , V_15 ) ;
return V_15 ;
}
V_4 = & V_2 -> V_16 . V_4 ;
V_6 = & V_4 -> V_63 . V_64 [ V_65 ] ;
V_15 = F_13 ( & V_4 -> V_63 , & V_2 -> V_16 . V_66 ,
V_6 , V_67 ) ;
if ( V_15 != 0 ) {
F_10 ( L_6 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_47 ; ++ V_14 ) {
F_14 ( & V_2 -> V_16 . V_68 [ V_14 ] , 0 ) ;
V_2 -> V_16 . V_69 [ V_14 ] = NULL ;
}
if ( ! F_15 ( V_2 , V_70 , 5 , 0 ) )
V_2 -> V_16 . V_71 = true ;
switch ( V_2 -> V_19 ) {
case V_30 :
V_2 -> V_16 . V_72 = V_2 -> V_16 . V_52 >= V_73 ;
break;
case V_34 :
V_2 -> V_16 . V_72 = V_2 -> V_16 . V_52 >= V_74 ;
break;
case V_32 :
V_2 -> V_16 . V_72 = V_2 -> V_16 . V_52 >= V_75 ;
break;
case V_36 :
V_2 -> V_16 . V_72 = V_2 -> V_16 . V_52 >= V_76 ;
break;
default:
V_2 -> V_16 . V_72 = V_2 -> V_19 >= V_38 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_16 . V_77 ) ;
F_18 ( & V_2 -> V_16 . V_4 . V_63 , & V_2 -> V_16 . V_66 ) ;
F_19 ( & V_2 -> V_16 . V_60 ,
& V_2 -> V_16 . V_61 ,
( void * * ) & V_2 -> V_16 . V_62 ) ;
F_20 ( & V_2 -> V_16 . V_4 ) ;
F_7 ( V_2 -> V_16 . V_45 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned V_78 ;
void * V_79 ;
int V_14 ;
if ( V_2 -> V_16 . V_60 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_47 ; ++ V_14 )
if ( F_22 ( & V_2 -> V_16 . V_68 [ V_14 ] ) )
break;
if ( V_14 == V_51 )
return 0 ;
F_23 ( & V_2 -> V_16 . V_17 ) ;
V_78 = F_24 ( V_2 -> V_16 . V_60 ) ;
V_79 = V_2 -> V_16 . V_62 ;
V_2 -> V_16 . V_77 = F_25 ( V_78 , V_80 ) ;
if ( ! V_2 -> V_16 . V_77 )
return - V_81 ;
F_26 ( V_2 -> V_16 . V_77 , V_79 , V_78 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_78 ;
void * V_79 ;
if ( V_2 -> V_16 . V_60 == NULL )
return - V_44 ;
V_78 = F_24 ( V_2 -> V_16 . V_60 ) ;
V_79 = V_2 -> V_16 . V_62 ;
if ( V_2 -> V_16 . V_77 != NULL ) {
F_28 ( V_79 , V_2 -> V_16 . V_77 , V_78 ) ;
F_17 ( V_2 -> V_16 . V_77 ) ;
V_2 -> V_16 . V_77 = NULL ;
} else {
const struct V_9 * V_10 ;
unsigned V_82 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_45 -> V_49 ;
V_82 = F_8 ( V_10 -> V_83 ) ;
F_28 ( V_2 -> V_16 . V_62 , V_2 -> V_16 . V_45 -> V_49 + V_82 ,
F_8 ( V_10 -> V_54 ) ) ;
V_78 -= F_8 ( V_10 -> V_54 ) ;
V_79 += F_8 ( V_10 -> V_54 ) ;
F_29 ( V_79 , 0 , V_78 ) ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 , struct V_84 * V_69 )
{
struct V_3 * V_4 = & V_2 -> V_16 . V_4 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_47 ; ++ V_14 ) {
T_1 V_85 = F_22 ( & V_2 -> V_16 . V_68 [ V_14 ] ) ;
if ( V_85 != 0 && V_2 -> V_16 . V_69 [ V_14 ] == V_69 ) {
struct V_86 * V_87 ;
V_15 = F_31 ( V_4 , V_85 ,
false , & V_87 ) ;
if ( V_15 ) {
F_10 ( L_7 , V_15 ) ;
continue;
}
F_32 ( V_87 , false ) ;
F_33 ( V_87 ) ;
V_2 -> V_16 . V_69 [ V_14 ] = NULL ;
F_14 ( & V_2 -> V_16 . V_68 [ V_14 ] , 0 ) ;
}
}
}
static void F_34 ( struct V_88 * V_89 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_89 -> V_90 . V_91 ; ++ V_14 ) {
V_89 -> V_92 [ V_14 ] . V_93 = 0 >> V_94 ;
V_89 -> V_92 [ V_14 ] . V_95 = ( 256 * 1024 * 1024 ) >> V_94 ;
}
}
static T_2 F_35 ( struct V_96 * V_97 )
{
T_1 V_98 , V_99 ;
T_3 V_100 ;
V_98 = F_36 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_103 ) ;
V_99 = F_36 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_104 ) ;
V_100 = ( ( T_3 ) V_98 ) | ( ( ( T_3 ) V_99 ) << 32 ) ;
return V_100 ;
}
static int F_37 ( struct V_96 * V_97 )
{
struct V_105 * V_106 ;
struct V_88 * V_107 ;
T_1 V_108 ;
T_3 V_100 = F_35 ( V_97 ) ;
int V_15 = 0 ;
V_106 = F_38 ( V_97 -> V_101 , V_100 , & V_107 ) ;
if ( V_106 == NULL ) {
F_10 ( L_8 , V_100 ) ;
return - V_44 ;
}
if ( ! V_97 -> V_101 -> V_2 -> V_16 . V_71 ) {
V_108 = F_36 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_109 ) >> 1 ;
if ( V_108 == 0x0 || V_108 == 0x3 ) {
T_1 V_110 = V_59 ;
F_39 ( V_107 , V_110 ) ;
}
F_34 ( V_107 ) ;
V_15 = F_40 ( & V_107 -> V_111 , & V_107 -> V_90 , false , false ) ;
}
return V_15 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 * V_112 ,
unsigned V_113 [] )
{
unsigned V_114 = V_112 [ 4 ] ;
unsigned V_115 = V_112 [ 6 ] ;
unsigned V_116 = V_112 [ 7 ] ;
unsigned V_117 = V_112 [ 9 ] ;
unsigned V_118 = V_112 [ 28 ] ;
unsigned V_119 = V_112 [ 57 ] ;
unsigned V_120 = V_115 / 16 ;
unsigned V_121 = F_42 ( V_116 / 16 , 2 ) ;
unsigned V_122 = V_120 * V_121 ;
unsigned V_123 , V_124 , V_125 , V_126 ;
unsigned V_127 = ~ 0 ;
V_123 = V_115 * V_116 ;
V_123 += V_123 / 2 ;
V_123 = F_42 ( V_123 , 1024 ) ;
switch ( V_114 ) {
case 0 :
switch( V_119 ) {
case 30 :
V_126 = 8100 / V_122 ;
break;
case 31 :
V_126 = 18000 / V_122 ;
break;
case 32 :
V_126 = 20480 / V_122 ;
break;
case 41 :
V_126 = 32768 / V_122 ;
break;
case 42 :
V_126 = 34816 / V_122 ;
break;
case 50 :
V_126 = 110400 / V_122 ;
break;
case 51 :
V_126 = 184320 / V_122 ;
break;
default:
V_126 = 184320 / V_122 ;
break;
}
V_126 ++ ;
if ( V_126 > 17 )
V_126 = 17 ;
V_125 = V_123 * V_126 ;
V_125 += V_120 * V_121 * V_126 * 192 ;
V_125 += V_120 * V_121 * 32 ;
break;
case 1 :
V_125 = V_123 * 3 ;
V_125 += V_120 * V_121 * 128 ;
V_125 += V_120 * 64 ;
V_125 += V_120 * 128 ;
V_124 = F_43 ( V_120 , V_121 ) ;
V_125 += F_42 ( V_124 * 7 * 16 , 64 ) ;
break;
case 3 :
V_125 = V_123 * 3 ;
break;
case 4 :
V_125 = V_123 * 3 ;
V_125 += V_120 * V_121 * 64 ;
V_125 += F_42 ( V_120 * V_121 * 32 , 64 ) ;
break;
case 7 :
switch( V_119 ) {
case 30 :
V_126 = 8100 / V_122 ;
break;
case 31 :
V_126 = 18000 / V_122 ;
break;
case 32 :
V_126 = 20480 / V_122 ;
break;
case 41 :
V_126 = 32768 / V_122 ;
break;
case 42 :
V_126 = 34816 / V_122 ;
break;
case 50 :
V_126 = 110400 / V_122 ;
break;
case 51 :
V_126 = 184320 / V_122 ;
break;
default:
V_126 = 184320 / V_122 ;
break;
}
V_126 ++ ;
if ( V_126 > 17 )
V_126 = 17 ;
V_125 = V_123 * V_126 ;
if ( ! V_2 -> V_16 . V_72 ) {
V_125 +=
V_120 * V_121 * V_126 * 192 ;
V_125 += V_120 * V_121 * 32 ;
} else {
V_127 =
V_120 * V_121 * V_126 * 192 ;
}
break;
case 16 :
V_123 = ( F_42 ( V_115 , 16 ) * F_42 ( V_116 , 16 ) * 3 ) / 2 ;
V_123 = F_42 ( V_123 , 256 ) ;
V_126 = ( F_8 ( V_112 [ 59 ] ) & 0xff ) + 2 ;
V_125 = V_123 * V_126 ;
V_127 = ( ( V_115 + 255 ) / 16 ) * ( ( V_116 + 255 ) / 16 )
* 16 * V_126 + 52 * 1024 ;
break;
default:
F_10 ( L_9 , V_114 ) ;
return - V_44 ;
}
if ( V_115 > V_118 ) {
F_10 ( L_10 ) ;
return - V_44 ;
}
if ( V_117 < V_125 ) {
F_10 ( L_11 ,
V_117 , V_125 ) ;
return - V_44 ;
}
V_113 [ 0x1 ] = V_117 ;
V_113 [ 0x2 ] = V_123 ;
V_113 [ 0x4 ] = V_127 ;
return 0 ;
}
static int F_44 ( struct V_96 * V_97 ,
struct V_88 * V_107 , unsigned V_82 )
{
struct V_1 * V_2 = V_97 -> V_101 -> V_2 ;
T_4 * V_112 , V_128 , V_85 ;
void * V_79 ;
long V_15 ;
int V_14 ;
if ( V_82 & 0x3F ) {
F_10 ( L_12 ) ;
return - V_44 ;
}
V_15 = F_45 ( V_107 , & V_79 ) ;
if ( V_15 ) {
F_10 ( L_13 , V_15 ) ;
return V_15 ;
}
V_112 = V_79 + V_82 ;
V_128 = V_112 [ 1 ] ;
V_85 = V_112 [ 2 ] ;
if ( V_85 == 0 ) {
F_10 ( L_14 ) ;
return - V_44 ;
}
switch ( V_128 ) {
case 0 :
F_46 ( V_107 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_47 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_68 [ V_14 ] ) == V_85 ) {
F_10 ( L_15 , V_85 ) ;
return - V_44 ;
}
if ( ! F_47 ( & V_2 -> V_16 . V_68 [ V_14 ] , 0 , V_85 ) ) {
V_2 -> V_16 . V_69 [ V_14 ] = V_97 -> V_101 -> V_69 ;
return 0 ;
}
}
F_10 ( L_16 ) ;
return - V_129 ;
case 1 :
V_15 = F_41 ( V_2 , V_112 , V_97 -> V_113 ) ;
F_46 ( V_107 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_47 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_68 [ V_14 ] ) == V_85 ) {
if ( V_2 -> V_16 . V_69 [ V_14 ] != V_97 -> V_101 -> V_69 ) {
F_10 ( L_17 ) ;
return - V_44 ;
}
return 0 ;
}
}
F_10 ( L_18 , V_85 ) ;
return - V_130 ;
case 2 :
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_47 ; ++ V_14 )
F_47 ( & V_2 -> V_16 . V_68 [ V_14 ] , V_85 , 0 ) ;
F_46 ( V_107 ) ;
return 0 ;
default:
F_10 ( L_19 , V_128 ) ;
return - V_44 ;
}
F_48 () ;
return - V_44 ;
}
static int F_49 ( struct V_96 * V_97 )
{
struct V_105 * V_106 ;
struct V_88 * V_107 ;
T_1 V_108 ;
T_3 V_131 , V_132 ;
T_3 V_100 = F_35 ( V_97 ) ;
int V_15 ;
V_106 = F_38 ( V_97 -> V_101 , V_100 , & V_107 ) ;
if ( V_106 == NULL ) {
F_10 ( L_8 , V_100 ) ;
return - V_44 ;
}
V_131 = F_50 ( V_107 ) ;
V_132 = ( V_106 -> V_133 . V_134 + 1 - V_106 -> V_133 . V_131 ) ;
V_132 = V_132 * V_135 + V_131 ;
V_100 -= ( ( T_3 ) V_106 -> V_133 . V_131 ) * V_135 ;
V_131 += V_100 ;
F_51 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_103 ,
F_52 ( V_131 ) ) ;
F_51 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_104 ,
F_53 ( V_131 ) ) ;
V_108 = F_36 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_109 ) >> 1 ;
if ( V_108 < 0x4 ) {
if ( ( V_132 - V_131 ) < V_97 -> V_113 [ V_108 ] ) {
F_10 ( L_20 , V_108 ,
( unsigned ) ( V_132 - V_131 ) ,
V_97 -> V_113 [ V_108 ] ) ;
return - V_44 ;
}
} else if ( V_108 == 0x206 ) {
if ( ( V_132 - V_131 ) < V_97 -> V_113 [ 4 ] ) {
F_10 ( L_20 , V_108 ,
( unsigned ) ( V_132 - V_131 ) ,
V_97 -> V_113 [ 4 ] ) ;
return - V_44 ;
}
} else if ( ( V_108 != 0x100 ) && ( V_108 != 0x204 ) ) {
F_10 ( L_21 , V_108 ) ;
return - V_44 ;
}
if ( ! V_97 -> V_101 -> V_2 -> V_16 . V_71 ) {
if ( ( V_131 >> 28 ) != ( ( V_132 - 1 ) >> 28 ) ) {
F_10 ( L_22 ,
V_131 , V_132 ) ;
return - V_44 ;
}
if ( ( V_108 == 0 || V_108 == 0x3 ) &&
( V_131 >> 28 ) != ( V_97 -> V_101 -> V_2 -> V_16 . V_61 >> 28 ) ) {
F_10 ( L_23 ,
V_131 , V_132 ) ;
return - V_44 ;
}
}
if ( V_108 == 0 ) {
V_97 -> V_136 = true ;
V_15 = F_44 ( V_97 , V_107 , V_100 ) ;
if ( V_15 )
return V_15 ;
} else if ( ! V_97 -> V_136 ) {
F_10 ( L_24 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_54 ( struct V_96 * V_97 ,
int (* F_55)( struct V_96 * V_97 ) )
{
struct V_137 * V_138 = & V_97 -> V_101 -> V_139 -> V_140 [ V_97 -> V_102 ] ;
int V_14 , V_15 ;
V_97 -> V_109 ++ ;
for ( V_14 = 0 ; V_14 <= V_97 -> V_141 ; ++ V_14 ) {
unsigned V_142 = V_97 -> V_142 + V_14 ;
if ( V_97 -> V_109 >= V_138 -> V_143 ) {
F_10 ( L_25 ) ;
return - V_44 ;
}
switch ( V_142 ) {
case V_144 :
V_97 -> V_103 = V_97 -> V_109 ;
break;
case V_145 :
V_97 -> V_104 = V_97 -> V_109 ;
break;
case V_146 :
V_15 = F_55 ( V_97 ) ;
if ( V_15 )
return V_15 ;
break;
case V_147 :
case V_148 :
break;
default:
F_10 ( L_26 , V_142 ) ;
return - V_44 ;
}
V_97 -> V_109 ++ ;
}
return 0 ;
}
static int F_56 ( struct V_96 * V_97 ,
int (* F_55)( struct V_96 * V_97 ) )
{
struct V_137 * V_138 = & V_97 -> V_101 -> V_139 -> V_140 [ V_97 -> V_102 ] ;
int V_15 ;
for ( V_97 -> V_109 = 0 ; V_97 -> V_109 < V_138 -> V_143 ; ) {
T_1 V_108 = F_36 ( V_97 -> V_101 , V_97 -> V_102 , V_97 -> V_109 ) ;
unsigned type = F_57 ( V_108 ) ;
switch ( type ) {
case V_149 :
V_97 -> V_142 = F_58 ( V_108 ) ;
V_97 -> V_141 = F_59 ( V_108 ) ;
V_15 = F_54 ( V_97 , F_55 ) ;
if ( V_15 )
return V_15 ;
break;
case V_150 :
++ V_97 -> V_109 ;
break;
default:
F_10 ( L_27 , type ) ;
return - V_44 ;
}
}
return 0 ;
}
int F_60 ( struct V_151 * V_101 , T_1 V_102 )
{
struct V_96 V_97 = {} ;
unsigned V_113 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_137 * V_138 = & V_101 -> V_139 -> V_140 [ V_102 ] ;
int V_15 ;
V_101 -> V_139 -> V_152 = NULL ;
V_138 -> V_61 = F_61 ( V_138 -> V_153 ) ;
if ( V_138 -> V_143 % 16 ) {
F_10 ( L_28 ,
V_138 -> V_143 ) ;
return - V_44 ;
}
V_15 = F_62 ( V_101 ) ;
if ( V_15 )
return V_15 ;
V_97 . V_101 = V_101 ;
V_97 . V_113 = V_113 ;
V_97 . V_102 = V_102 ;
if ( ! V_101 -> V_2 -> V_16 . V_71 ) {
V_15 = F_56 ( & V_97 , F_37 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_56 ( & V_97 , F_49 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_97 . V_136 ) {
F_10 ( L_29 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_63 ( struct V_3 * V_4 , struct V_88 * V_107 ,
bool V_154 , struct V_86 * * V_87 )
{
struct V_155 V_156 ;
struct V_157 V_158 ;
struct V_159 V_160 ;
struct V_161 * V_139 ;
struct V_137 * V_138 ;
struct V_86 * V_162 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_3 V_100 ;
int V_14 , V_15 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_107 = & V_107 -> V_111 ;
F_64 ( & V_160 ) ;
F_65 ( & V_156 . V_160 , & V_160 ) ;
V_15 = F_66 ( & V_158 , & V_160 , true , NULL ) ;
if ( V_15 )
return V_15 ;
if ( ! V_4 -> V_2 -> V_16 . V_71 ) {
F_39 ( V_107 , V_59 ) ;
F_34 ( V_107 ) ;
}
V_15 = F_40 ( & V_107 -> V_111 , & V_107 -> V_90 , true , false ) ;
if ( V_15 )
goto V_163;
V_15 = F_67 ( V_2 , 64 , & V_139 ) ;
if ( V_15 )
goto V_163;
V_138 = & V_139 -> V_140 [ 0 ] ;
V_100 = F_50 ( V_107 ) ;
V_138 -> V_79 [ 0 ] = F_68 ( V_144 , 0 ) ;
V_138 -> V_79 [ 1 ] = V_100 ;
V_138 -> V_79 [ 2 ] = F_68 ( V_145 , 0 ) ;
V_138 -> V_79 [ 3 ] = V_100 >> 32 ;
V_138 -> V_79 [ 4 ] = F_68 ( V_146 , 0 ) ;
V_138 -> V_79 [ 5 ] = 0 ;
for ( V_14 = 6 ; V_14 < 16 ; V_14 += 2 ) {
V_138 -> V_79 [ V_14 ] = F_68 ( V_148 , 0 ) ;
V_138 -> V_79 [ V_14 + 1 ] = 0 ;
}
V_138 -> V_143 = 16 ;
if ( V_154 ) {
V_15 = F_69 ( V_4 , 1 , V_138 , NULL , NULL , & V_162 ) ;
V_139 -> V_87 = F_70 ( V_162 ) ;
if ( V_15 )
goto V_164;
F_71 ( V_139 ) ;
} else {
V_15 = F_72 ( V_139 , V_4 , & V_2 -> V_16 . V_66 ,
V_165 , & V_162 ) ;
if ( V_15 )
goto V_164;
}
F_73 ( & V_158 , & V_160 , V_162 ) ;
if ( V_87 )
* V_87 = F_70 ( V_162 ) ;
F_74 ( & V_107 ) ;
F_33 ( V_162 ) ;
return 0 ;
V_164:
F_71 ( V_139 ) ;
V_163:
F_75 ( & V_158 , & V_160 ) ;
return V_15 ;
}
int F_76 ( struct V_3 * V_4 , T_1 V_85 ,
struct V_86 * * V_87 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_88 * V_107 ;
T_1 * V_112 ;
int V_15 , V_14 ;
V_15 = F_77 ( V_2 , 1024 , V_58 , true ,
V_59 ,
V_166 |
V_167 ,
NULL , NULL , & V_107 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_78 ( V_107 , false ) ;
if ( V_15 ) {
F_74 ( & V_107 ) ;
return V_15 ;
}
V_15 = F_45 ( V_107 , ( void * * ) & V_112 ) ;
if ( V_15 ) {
F_79 ( V_107 ) ;
F_74 ( & V_107 ) ;
return V_15 ;
}
V_112 [ 0 ] = F_80 ( 0x00000de4 ) ;
V_112 [ 1 ] = F_80 ( 0x00000000 ) ;
V_112 [ 2 ] = F_80 ( V_85 ) ;
V_112 [ 3 ] = F_80 ( 0x00000000 ) ;
V_112 [ 4 ] = F_80 ( 0x00000000 ) ;
V_112 [ 5 ] = F_80 ( 0x00000000 ) ;
V_112 [ 6 ] = F_80 ( 0x00000000 ) ;
V_112 [ 7 ] = F_80 ( 0x00000780 ) ;
V_112 [ 8 ] = F_80 ( 0x00000440 ) ;
V_112 [ 9 ] = F_80 ( 0x00000000 ) ;
V_112 [ 10 ] = F_80 ( 0x01b37000 ) ;
for ( V_14 = 11 ; V_14 < 1024 ; ++ V_14 )
V_112 [ V_14 ] = F_80 ( 0x0 ) ;
F_46 ( V_107 ) ;
F_79 ( V_107 ) ;
return F_63 ( V_4 , V_107 , true , V_87 ) ;
}
int F_31 ( struct V_3 * V_4 , T_1 V_85 ,
bool V_154 , struct V_86 * * V_87 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_88 * V_107 ;
T_1 * V_112 ;
int V_15 , V_14 ;
V_15 = F_77 ( V_2 , 1024 , V_58 , true ,
V_59 ,
V_166 |
V_167 ,
NULL , NULL , & V_107 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_78 ( V_107 , false ) ;
if ( V_15 ) {
F_74 ( & V_107 ) ;
return V_15 ;
}
V_15 = F_45 ( V_107 , ( void * * ) & V_112 ) ;
if ( V_15 ) {
F_79 ( V_107 ) ;
F_74 ( & V_107 ) ;
return V_15 ;
}
V_112 [ 0 ] = F_80 ( 0x00000de4 ) ;
V_112 [ 1 ] = F_80 ( 0x00000002 ) ;
V_112 [ 2 ] = F_80 ( V_85 ) ;
V_112 [ 3 ] = F_80 ( 0x00000000 ) ;
for ( V_14 = 4 ; V_14 < 1024 ; ++ V_14 )
V_112 [ V_14 ] = F_80 ( 0x0 ) ;
F_46 ( V_107 ) ;
F_79 ( V_107 ) ;
return F_63 ( V_4 , V_107 , V_154 , V_87 ) ;
}
static void V_18 ( struct V_168 * V_169 )
{
struct V_1 * V_2 =
F_81 ( V_169 , struct V_1 , V_16 . V_17 . V_169 ) ;
unsigned V_170 = F_82 ( & V_2 -> V_16 . V_4 ) ;
if ( V_170 == 0 ) {
if ( V_2 -> V_171 . V_172 ) {
F_83 ( V_2 , false ) ;
} else {
F_84 ( V_2 , 0 , 0 ) ;
}
} else {
F_85 ( & V_2 -> V_16 . V_17 , V_173 ) ;
}
}
void F_86 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_174 = ! F_23 ( & V_2 -> V_16 . V_17 ) ;
if ( V_174 ) {
if ( V_2 -> V_171 . V_172 ) {
F_83 ( V_2 , true ) ;
} else {
F_84 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_87 ( struct V_3 * V_4 )
{
F_85 ( & V_4 -> V_2 -> V_16 . V_17 , V_173 ) ;
}
int F_88 ( struct V_3 * V_4 , long V_175 )
{
struct V_86 * V_87 ;
long V_15 ;
V_15 = F_76 ( V_4 , 1 , NULL ) ;
if ( V_15 ) {
F_10 ( L_30 , V_15 ) ;
goto error;
}
V_15 = F_31 ( V_4 , 1 , true , & V_87 ) ;
if ( V_15 ) {
F_10 ( L_31 , V_15 ) ;
goto error;
}
V_15 = F_89 ( V_87 , false , V_175 ) ;
if ( V_15 == 0 ) {
F_10 ( L_32 ) ;
V_15 = - V_176 ;
} else if ( V_15 < 0 ) {
F_10 ( L_33 , V_15 ) ;
} else {
F_9 ( L_34 , V_4 -> V_109 ) ;
V_15 = 0 ;
}
F_33 ( V_87 ) ;
error:
return V_15 ;
}
