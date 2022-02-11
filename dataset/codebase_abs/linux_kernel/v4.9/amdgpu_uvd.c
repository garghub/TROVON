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
default:
return - V_42 ;
}
V_15 = F_4 ( & V_2 -> V_16 . V_43 , V_8 , V_2 -> V_44 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_44 , L_1 ,
V_8 ) ;
return V_15 ;
}
V_15 = F_6 ( V_2 -> V_16 . V_43 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_44 , L_2 ,
V_8 ) ;
F_7 ( V_2 -> V_16 . V_43 ) ;
V_2 -> V_16 . V_43 = NULL ;
return V_15 ;
}
V_2 -> V_16 . V_45 = V_46 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_43 -> V_47 ;
V_13 = F_8 ( V_10 -> V_48 ) & 0xff ;
V_11 = ( F_8 ( V_10 -> V_48 ) >> 24 ) & 0xff ;
V_12 = ( F_8 ( V_10 -> V_48 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_11 , V_12 , V_13 ) ;
if ( ( V_11 > 0x01 ) ||
( ( V_11 == 0x01 ) && ( V_12 >= 0x50 ) ) )
V_2 -> V_16 . V_45 = V_49 ;
V_2 -> V_16 . V_50 = ( ( V_11 << 24 ) | ( V_12 << 16 ) |
( V_13 << 8 ) ) ;
if ( ( V_2 -> V_19 == V_38 ||
V_2 -> V_19 == V_40 ) &&
( V_2 -> V_16 . V_50 < V_51 ) )
F_10 ( L_4 ,
V_11 , V_12 ) ;
V_7 = F_11 ( F_8 ( V_10 -> V_52 ) + 8 )
+ V_53 + V_54
+ V_55 * V_2 -> V_16 . V_45 ;
V_15 = F_12 ( V_2 , V_7 , V_56 ,
V_57 , & V_2 -> V_16 . V_58 ,
& V_2 -> V_16 . V_59 , & V_2 -> V_16 . V_60 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_44 , L_5 , V_15 ) ;
return V_15 ;
}
V_4 = & V_2 -> V_16 . V_4 ;
V_6 = & V_4 -> V_61 . V_62 [ V_63 ] ;
V_15 = F_13 ( & V_4 -> V_61 , & V_2 -> V_16 . V_64 ,
V_6 , V_65 ) ;
if ( V_15 != 0 ) {
F_10 ( L_6 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
F_14 ( & V_2 -> V_16 . V_66 [ V_14 ] , 0 ) ;
V_2 -> V_16 . V_67 [ V_14 ] = NULL ;
}
if ( ! F_15 ( V_2 , V_68 , 5 , 0 ) )
V_2 -> V_16 . V_69 = true ;
switch ( V_2 -> V_19 ) {
case V_30 :
V_2 -> V_16 . V_70 = V_2 -> V_16 . V_50 >= V_71 ;
break;
case V_34 :
V_2 -> V_16 . V_70 = V_2 -> V_16 . V_50 >= V_72 ;
break;
case V_32 :
V_2 -> V_16 . V_70 = V_2 -> V_16 . V_50 >= V_73 ;
break;
case V_36 :
V_2 -> V_16 . V_70 = V_2 -> V_16 . V_50 >= V_74 ;
break;
default:
V_2 -> V_16 . V_70 = V_2 -> V_19 >= V_38 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_16 . V_75 ) ;
F_18 ( & V_2 -> V_16 . V_4 . V_61 , & V_2 -> V_16 . V_64 ) ;
F_19 ( & V_2 -> V_16 . V_58 ,
& V_2 -> V_16 . V_59 ,
( void * * ) & V_2 -> V_16 . V_60 ) ;
F_20 ( & V_2 -> V_16 . V_4 ) ;
F_7 ( V_2 -> V_16 . V_43 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
unsigned V_76 ;
void * V_77 ;
int V_14 ;
if ( V_2 -> V_16 . V_58 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
if ( F_22 ( & V_2 -> V_16 . V_66 [ V_14 ] ) )
break;
if ( V_14 == V_49 )
return 0 ;
F_23 ( & V_2 -> V_16 . V_17 ) ;
V_76 = F_24 ( V_2 -> V_16 . V_58 ) ;
V_77 = V_2 -> V_16 . V_60 ;
V_2 -> V_16 . V_75 = F_25 ( V_76 , V_78 ) ;
if ( ! V_2 -> V_16 . V_75 )
return - V_79 ;
F_26 ( V_2 -> V_16 . V_75 , V_77 , V_76 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_76 ;
void * V_77 ;
if ( V_2 -> V_16 . V_58 == NULL )
return - V_42 ;
V_76 = F_24 ( V_2 -> V_16 . V_58 ) ;
V_77 = V_2 -> V_16 . V_60 ;
if ( V_2 -> V_16 . V_75 != NULL ) {
F_28 ( V_77 , V_2 -> V_16 . V_75 , V_76 ) ;
F_17 ( V_2 -> V_16 . V_75 ) ;
V_2 -> V_16 . V_75 = NULL ;
} else {
const struct V_9 * V_10 ;
unsigned V_80 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_43 -> V_47 ;
V_80 = F_8 ( V_10 -> V_81 ) ;
F_28 ( V_2 -> V_16 . V_60 , V_2 -> V_16 . V_43 -> V_47 + V_80 ,
F_8 ( V_10 -> V_52 ) ) ;
V_76 -= F_8 ( V_10 -> V_52 ) ;
V_77 += F_8 ( V_10 -> V_52 ) ;
F_29 ( V_77 , 0 , V_76 ) ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 , struct V_82 * V_67 )
{
struct V_3 * V_4 = & V_2 -> V_16 . V_4 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
T_1 V_83 = F_22 ( & V_2 -> V_16 . V_66 [ V_14 ] ) ;
if ( V_83 != 0 && V_2 -> V_16 . V_67 [ V_14 ] == V_67 ) {
struct V_84 * V_84 ;
V_15 = F_31 ( V_4 , V_83 ,
false , & V_84 ) ;
if ( V_15 ) {
F_10 ( L_7 , V_15 ) ;
continue;
}
F_32 ( V_84 , false ) ;
F_33 ( V_84 ) ;
V_2 -> V_16 . V_67 [ V_14 ] = NULL ;
F_14 ( & V_2 -> V_16 . V_66 [ V_14 ] , 0 ) ;
}
}
}
static void F_34 ( struct V_85 * V_86 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_86 -> V_87 . V_88 ; ++ V_14 ) {
V_86 -> V_89 [ V_14 ] . V_90 = 0 >> V_91 ;
V_86 -> V_89 [ V_14 ] . V_92 = ( 256 * 1024 * 1024 ) >> V_91 ;
}
}
static int F_35 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
struct V_85 * V_97 ;
T_1 V_98 , V_99 , V_100 ;
T_2 V_101 ;
int V_15 = 0 ;
V_99 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_104 ) ;
V_100 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_105 ) ;
V_101 = ( ( T_2 ) V_99 ) | ( ( ( T_2 ) V_100 ) << 32 ) ;
V_96 = F_37 ( V_94 -> V_102 , V_101 , & V_97 ) ;
if ( V_96 == NULL ) {
F_10 ( L_8 , V_101 ) ;
return - V_42 ;
}
if ( ! V_94 -> V_102 -> V_2 -> V_16 . V_69 ) {
V_98 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_106 ) >> 1 ;
if ( V_98 == 0x0 || V_98 == 0x3 ) {
T_1 V_107 = V_57 ;
F_38 ( V_97 , V_107 ) ;
}
F_34 ( V_97 ) ;
V_15 = F_39 ( & V_97 -> V_108 , & V_97 -> V_87 , false , false ) ;
}
return V_15 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_109 ,
unsigned V_110 [] )
{
unsigned V_111 = V_109 [ 4 ] ;
unsigned V_112 = V_109 [ 6 ] ;
unsigned V_113 = V_109 [ 7 ] ;
unsigned V_114 = V_109 [ 9 ] ;
unsigned V_115 = V_109 [ 28 ] ;
unsigned V_116 = V_109 [ 57 ] ;
unsigned V_117 = V_112 / 16 ;
unsigned V_118 = F_41 ( V_113 / 16 , 2 ) ;
unsigned V_119 = V_117 * V_118 ;
unsigned V_120 , V_121 , V_122 , V_123 ;
unsigned V_124 = ~ 0 ;
V_120 = V_112 * V_113 ;
V_120 += V_120 / 2 ;
V_120 = F_41 ( V_120 , 1024 ) ;
switch ( V_111 ) {
case 0 :
switch( V_116 ) {
case 30 :
V_123 = 8100 / V_119 ;
break;
case 31 :
V_123 = 18000 / V_119 ;
break;
case 32 :
V_123 = 20480 / V_119 ;
break;
case 41 :
V_123 = 32768 / V_119 ;
break;
case 42 :
V_123 = 34816 / V_119 ;
break;
case 50 :
V_123 = 110400 / V_119 ;
break;
case 51 :
V_123 = 184320 / V_119 ;
break;
default:
V_123 = 184320 / V_119 ;
break;
}
V_123 ++ ;
if ( V_123 > 17 )
V_123 = 17 ;
V_122 = V_120 * V_123 ;
V_122 += V_117 * V_118 * V_123 * 192 ;
V_122 += V_117 * V_118 * 32 ;
break;
case 1 :
V_122 = V_120 * 3 ;
V_122 += V_117 * V_118 * 128 ;
V_122 += V_117 * 64 ;
V_122 += V_117 * 128 ;
V_121 = F_42 ( V_117 , V_118 ) ;
V_122 += F_41 ( V_121 * 7 * 16 , 64 ) ;
break;
case 3 :
V_122 = V_120 * 3 ;
break;
case 4 :
V_122 = V_120 * 3 ;
V_122 += V_117 * V_118 * 64 ;
V_122 += F_41 ( V_117 * V_118 * 32 , 64 ) ;
break;
case 7 :
switch( V_116 ) {
case 30 :
V_123 = 8100 / V_119 ;
break;
case 31 :
V_123 = 18000 / V_119 ;
break;
case 32 :
V_123 = 20480 / V_119 ;
break;
case 41 :
V_123 = 32768 / V_119 ;
break;
case 42 :
V_123 = 34816 / V_119 ;
break;
case 50 :
V_123 = 110400 / V_119 ;
break;
case 51 :
V_123 = 184320 / V_119 ;
break;
default:
V_123 = 184320 / V_119 ;
break;
}
V_123 ++ ;
if ( V_123 > 17 )
V_123 = 17 ;
V_122 = V_120 * V_123 ;
if ( ! V_2 -> V_16 . V_70 ) {
V_122 +=
V_117 * V_118 * V_123 * 192 ;
V_122 += V_117 * V_118 * 32 ;
} else {
V_124 =
V_117 * V_118 * V_123 * 192 ;
}
break;
case 16 :
V_120 = ( F_41 ( V_112 , 16 ) * F_41 ( V_113 , 16 ) * 3 ) / 2 ;
V_120 = F_41 ( V_120 , 256 ) ;
V_123 = ( F_8 ( V_109 [ 59 ] ) & 0xff ) + 2 ;
V_122 = V_120 * V_123 ;
V_124 = ( ( V_112 + 255 ) / 16 ) * ( ( V_113 + 255 ) / 16 )
* 16 * V_123 + 52 * 1024 ;
break;
default:
F_10 ( L_9 , V_111 ) ;
return - V_42 ;
}
if ( V_112 > V_115 ) {
F_10 ( L_10 ) ;
return - V_42 ;
}
if ( V_114 < V_122 ) {
F_10 ( L_11 ,
V_114 , V_122 ) ;
return - V_42 ;
}
V_110 [ 0x1 ] = V_114 ;
V_110 [ 0x2 ] = V_120 ;
V_110 [ 0x4 ] = V_124 ;
return 0 ;
}
static int F_43 ( struct V_93 * V_94 ,
struct V_85 * V_97 , unsigned V_80 )
{
struct V_1 * V_2 = V_94 -> V_102 -> V_2 ;
T_3 * V_109 , V_125 , V_83 ;
void * V_77 ;
long V_15 ;
int V_14 ;
if ( V_80 & 0x3F ) {
F_10 ( L_12 ) ;
return - V_42 ;
}
V_15 = F_44 ( V_97 , & V_77 ) ;
if ( V_15 ) {
F_10 ( L_13 , V_15 ) ;
return V_15 ;
}
V_109 = V_77 + V_80 ;
V_125 = V_109 [ 1 ] ;
V_83 = V_109 [ 2 ] ;
if ( V_83 == 0 ) {
F_10 ( L_14 ) ;
return - V_42 ;
}
switch ( V_125 ) {
case 0 :
F_45 ( V_97 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_66 [ V_14 ] ) == V_83 ) {
F_10 ( L_15 , V_83 ) ;
return - V_42 ;
}
if ( ! F_46 ( & V_2 -> V_16 . V_66 [ V_14 ] , 0 , V_83 ) ) {
V_2 -> V_16 . V_67 [ V_14 ] = V_94 -> V_102 -> V_67 ;
return 0 ;
}
}
F_10 ( L_16 ) ;
return - V_126 ;
case 1 :
V_15 = F_40 ( V_2 , V_109 , V_94 -> V_110 ) ;
F_45 ( V_97 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
if ( F_22 ( & V_2 -> V_16 . V_66 [ V_14 ] ) == V_83 ) {
if ( V_2 -> V_16 . V_67 [ V_14 ] != V_94 -> V_102 -> V_67 ) {
F_10 ( L_17 ) ;
return - V_42 ;
}
return 0 ;
}
}
F_10 ( L_18 , V_83 ) ;
return - V_127 ;
case 2 :
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
F_46 ( & V_2 -> V_16 . V_66 [ V_14 ] , V_83 , 0 ) ;
F_45 ( V_97 ) ;
return 0 ;
default:
F_10 ( L_19 , V_125 ) ;
return - V_42 ;
}
F_47 () ;
return - V_42 ;
}
static int F_48 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
struct V_85 * V_97 ;
T_1 V_98 , V_99 , V_100 ;
T_2 V_128 , V_129 ;
T_2 V_101 ;
int V_15 ;
V_99 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_104 ) ;
V_100 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_105 ) ;
V_101 = ( ( T_2 ) V_99 ) | ( ( ( T_2 ) V_100 ) << 32 ) ;
V_96 = F_37 ( V_94 -> V_102 , V_101 , & V_97 ) ;
if ( V_96 == NULL )
return - V_42 ;
V_128 = F_49 ( V_97 ) ;
V_129 = ( V_96 -> V_130 . V_131 + 1 - V_96 -> V_130 . V_128 ) ;
V_129 = V_129 * V_132 + V_128 ;
V_101 -= ( ( T_2 ) V_96 -> V_130 . V_128 ) * V_132 ;
V_128 += V_101 ;
F_50 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_104 ,
F_51 ( V_128 ) ) ;
F_50 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_105 ,
F_52 ( V_128 ) ) ;
V_98 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_106 ) >> 1 ;
if ( V_98 < 0x4 ) {
if ( ( V_129 - V_128 ) < V_94 -> V_110 [ V_98 ] ) {
F_10 ( L_20 , V_98 ,
( unsigned ) ( V_129 - V_128 ) ,
V_94 -> V_110 [ V_98 ] ) ;
return - V_42 ;
}
} else if ( V_98 == 0x206 ) {
if ( ( V_129 - V_128 ) < V_94 -> V_110 [ 4 ] ) {
F_10 ( L_20 , V_98 ,
( unsigned ) ( V_129 - V_128 ) ,
V_94 -> V_110 [ 4 ] ) ;
return - V_42 ;
}
} else if ( ( V_98 != 0x100 ) && ( V_98 != 0x204 ) ) {
F_10 ( L_21 , V_98 ) ;
return - V_42 ;
}
if ( ! V_94 -> V_102 -> V_2 -> V_16 . V_69 ) {
if ( ( V_128 >> 28 ) != ( ( V_129 - 1 ) >> 28 ) ) {
F_10 ( L_22 ,
V_128 , V_129 ) ;
return - V_42 ;
}
if ( ( V_98 == 0 || V_98 == 0x3 ) &&
( V_128 >> 28 ) != ( V_94 -> V_102 -> V_2 -> V_16 . V_59 >> 28 ) ) {
F_10 ( L_23 ,
V_128 , V_129 ) ;
return - V_42 ;
}
}
if ( V_98 == 0 ) {
V_94 -> V_133 = true ;
V_15 = F_43 ( V_94 , V_97 , V_101 ) ;
if ( V_15 )
return V_15 ;
} else if ( ! V_94 -> V_133 ) {
F_10 ( L_24 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_53 ( struct V_93 * V_94 ,
int (* F_54)( struct V_93 * V_94 ) )
{
struct V_134 * V_135 = & V_94 -> V_102 -> V_136 -> V_137 [ V_94 -> V_103 ] ;
int V_14 , V_15 ;
V_94 -> V_106 ++ ;
for ( V_14 = 0 ; V_14 <= V_94 -> V_138 ; ++ V_14 ) {
unsigned V_139 = V_94 -> V_139 + V_14 ;
if ( V_94 -> V_106 >= V_135 -> V_140 ) {
F_10 ( L_25 ) ;
return - V_42 ;
}
switch ( V_139 ) {
case V_141 :
V_94 -> V_104 = V_94 -> V_106 ;
break;
case V_142 :
V_94 -> V_105 = V_94 -> V_106 ;
break;
case V_143 :
V_15 = F_54 ( V_94 ) ;
if ( V_15 )
return V_15 ;
break;
case V_144 :
case V_145 :
break;
default:
F_10 ( L_26 , V_139 ) ;
return - V_42 ;
}
V_94 -> V_106 ++ ;
}
return 0 ;
}
static int F_55 ( struct V_93 * V_94 ,
int (* F_54)( struct V_93 * V_94 ) )
{
struct V_134 * V_135 = & V_94 -> V_102 -> V_136 -> V_137 [ V_94 -> V_103 ] ;
int V_15 ;
for ( V_94 -> V_106 = 0 ; V_94 -> V_106 < V_135 -> V_140 ; ) {
T_1 V_98 = F_36 ( V_94 -> V_102 , V_94 -> V_103 , V_94 -> V_106 ) ;
unsigned type = F_56 ( V_98 ) ;
switch ( type ) {
case V_146 :
V_94 -> V_139 = F_57 ( V_98 ) ;
V_94 -> V_138 = F_58 ( V_98 ) ;
V_15 = F_53 ( V_94 , F_54 ) ;
if ( V_15 )
return V_15 ;
break;
case V_147 :
++ V_94 -> V_106 ;
break;
default:
F_10 ( L_27 , type ) ;
return - V_42 ;
}
}
return 0 ;
}
int F_59 ( struct V_148 * V_102 , T_1 V_103 )
{
struct V_93 V_94 = {} ;
unsigned V_110 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_134 * V_135 = & V_102 -> V_136 -> V_137 [ V_103 ] ;
int V_15 ;
if ( V_135 -> V_140 % 16 ) {
F_10 ( L_28 ,
V_135 -> V_140 ) ;
return - V_42 ;
}
V_15 = F_60 ( V_102 ) ;
if ( V_15 )
return V_15 ;
V_94 . V_102 = V_102 ;
V_94 . V_110 = V_110 ;
V_94 . V_103 = V_103 ;
V_15 = F_55 ( & V_94 , F_35 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_55 ( & V_94 , F_48 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_94 . V_133 ) {
F_10 ( L_29 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_61 ( struct V_3 * V_4 , struct V_85 * V_97 ,
bool V_149 , struct V_84 * * V_84 )
{
struct V_150 V_151 ;
struct V_152 V_153 ;
struct V_154 V_155 ;
struct V_156 * V_136 ;
struct V_134 * V_135 ;
struct V_84 * V_157 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_101 ;
int V_14 , V_15 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_97 = & V_97 -> V_108 ;
F_62 ( & V_155 ) ;
F_63 ( & V_151 . V_155 , & V_155 ) ;
V_15 = F_64 ( & V_153 , & V_155 , true , NULL ) ;
if ( V_15 )
return V_15 ;
if ( ! V_97 -> V_2 -> V_16 . V_69 ) {
F_38 ( V_97 , V_57 ) ;
F_34 ( V_97 ) ;
}
V_15 = F_39 ( & V_97 -> V_108 , & V_97 -> V_87 , true , false ) ;
if ( V_15 )
goto V_158;
V_15 = F_65 ( V_2 , 64 , & V_136 ) ;
if ( V_15 )
goto V_158;
V_135 = & V_136 -> V_137 [ 0 ] ;
V_101 = F_49 ( V_97 ) ;
V_135 -> V_77 [ 0 ] = F_66 ( V_141 , 0 ) ;
V_135 -> V_77 [ 1 ] = V_101 ;
V_135 -> V_77 [ 2 ] = F_66 ( V_142 , 0 ) ;
V_135 -> V_77 [ 3 ] = V_101 >> 32 ;
V_135 -> V_77 [ 4 ] = F_66 ( V_143 , 0 ) ;
V_135 -> V_77 [ 5 ] = 0 ;
for ( V_14 = 6 ; V_14 < 16 ; V_14 += 2 ) {
V_135 -> V_77 [ V_14 ] = F_66 ( V_145 , 0 ) ;
V_135 -> V_77 [ V_14 + 1 ] = 0 ;
}
V_135 -> V_140 = 16 ;
if ( V_149 ) {
V_15 = F_67 ( V_4 , 1 , V_135 , NULL , NULL , & V_157 ) ;
V_136 -> V_84 = F_68 ( V_157 ) ;
if ( V_15 )
goto V_159;
F_69 ( V_136 ) ;
} else {
V_15 = F_70 ( V_136 , V_4 , & V_2 -> V_16 . V_64 ,
V_160 , & V_157 ) ;
if ( V_15 )
goto V_159;
}
F_71 ( & V_153 , & V_155 , V_157 ) ;
if ( V_84 )
* V_84 = F_68 ( V_157 ) ;
F_72 ( & V_97 ) ;
F_33 ( V_157 ) ;
return 0 ;
V_159:
F_69 ( V_136 ) ;
V_158:
F_73 ( & V_153 , & V_155 ) ;
return V_15 ;
}
int F_74 ( struct V_3 * V_4 , T_1 V_83 ,
struct V_84 * * V_84 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_85 * V_97 ;
T_1 * V_109 ;
int V_15 , V_14 ;
V_15 = F_75 ( V_2 , 1024 , V_56 , true ,
V_57 ,
V_161 ,
NULL , NULL , & V_97 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_76 ( V_97 , false ) ;
if ( V_15 ) {
F_72 ( & V_97 ) ;
return V_15 ;
}
V_15 = F_44 ( V_97 , ( void * * ) & V_109 ) ;
if ( V_15 ) {
F_77 ( V_97 ) ;
F_72 ( & V_97 ) ;
return V_15 ;
}
V_109 [ 0 ] = F_78 ( 0x00000de4 ) ;
V_109 [ 1 ] = F_78 ( 0x00000000 ) ;
V_109 [ 2 ] = F_78 ( V_83 ) ;
V_109 [ 3 ] = F_78 ( 0x00000000 ) ;
V_109 [ 4 ] = F_78 ( 0x00000000 ) ;
V_109 [ 5 ] = F_78 ( 0x00000000 ) ;
V_109 [ 6 ] = F_78 ( 0x00000000 ) ;
V_109 [ 7 ] = F_78 ( 0x00000780 ) ;
V_109 [ 8 ] = F_78 ( 0x00000440 ) ;
V_109 [ 9 ] = F_78 ( 0x00000000 ) ;
V_109 [ 10 ] = F_78 ( 0x01b37000 ) ;
for ( V_14 = 11 ; V_14 < 1024 ; ++ V_14 )
V_109 [ V_14 ] = F_78 ( 0x0 ) ;
F_45 ( V_97 ) ;
F_77 ( V_97 ) ;
return F_61 ( V_4 , V_97 , true , V_84 ) ;
}
int F_31 ( struct V_3 * V_4 , T_1 V_83 ,
bool V_149 , struct V_84 * * V_84 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_85 * V_97 ;
T_1 * V_109 ;
int V_15 , V_14 ;
V_15 = F_75 ( V_2 , 1024 , V_56 , true ,
V_57 ,
V_161 ,
NULL , NULL , & V_97 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_76 ( V_97 , false ) ;
if ( V_15 ) {
F_72 ( & V_97 ) ;
return V_15 ;
}
V_15 = F_44 ( V_97 , ( void * * ) & V_109 ) ;
if ( V_15 ) {
F_77 ( V_97 ) ;
F_72 ( & V_97 ) ;
return V_15 ;
}
V_109 [ 0 ] = F_78 ( 0x00000de4 ) ;
V_109 [ 1 ] = F_78 ( 0x00000002 ) ;
V_109 [ 2 ] = F_78 ( V_83 ) ;
V_109 [ 3 ] = F_78 ( 0x00000000 ) ;
for ( V_14 = 4 ; V_14 < 1024 ; ++ V_14 )
V_109 [ V_14 ] = F_78 ( 0x0 ) ;
F_45 ( V_97 ) ;
F_77 ( V_97 ) ;
return F_61 ( V_4 , V_97 , V_149 , V_84 ) ;
}
static void V_18 ( struct V_162 * V_163 )
{
struct V_1 * V_2 =
F_79 ( V_163 , struct V_1 , V_16 . V_17 . V_163 ) ;
unsigned V_164 = F_80 ( & V_2 -> V_16 . V_4 ) ;
if ( V_164 == 0 ) {
if ( V_2 -> V_165 . V_166 ) {
F_81 ( V_2 , false ) ;
} else {
F_82 ( V_2 , 0 , 0 ) ;
}
} else {
F_83 ( & V_2 -> V_16 . V_17 , V_167 ) ;
}
}
void F_84 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_168 = ! F_23 ( & V_2 -> V_16 . V_17 ) ;
if ( V_168 ) {
if ( V_2 -> V_165 . V_166 ) {
F_81 ( V_2 , true ) ;
} else {
F_82 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_85 ( struct V_3 * V_4 )
{
F_83 ( & V_4 -> V_2 -> V_16 . V_17 , V_167 ) ;
}
int F_86 ( struct V_3 * V_4 , long V_169 )
{
struct V_84 * V_84 ;
long V_15 ;
V_15 = F_74 ( V_4 , 1 , NULL ) ;
if ( V_15 ) {
F_10 ( L_30 , V_15 ) ;
goto error;
}
V_15 = F_31 ( V_4 , 1 , true , & V_84 ) ;
if ( V_15 ) {
F_10 ( L_31 , V_15 ) ;
goto error;
}
V_15 = F_87 ( V_84 , false , V_169 ) ;
if ( V_15 == 0 ) {
F_10 ( L_32 ) ;
V_15 = - V_170 ;
} else if ( V_15 < 0 ) {
F_10 ( L_33 , V_15 ) ;
} else {
F_9 ( L_34 , V_4 -> V_106 ) ;
V_15 = 0 ;
}
F_33 ( V_84 ) ;
error:
return V_15 ;
}
