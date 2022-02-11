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
default:
return - V_38 ;
}
V_15 = F_4 ( & V_2 -> V_16 . V_39 , V_8 , V_2 -> V_40 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_40 , L_1 ,
V_8 ) ;
return V_15 ;
}
V_15 = F_6 ( V_2 -> V_16 . V_39 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_40 , L_2 ,
V_8 ) ;
F_7 ( V_2 -> V_16 . V_39 ) ;
V_2 -> V_16 . V_39 = NULL ;
return V_15 ;
}
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_39 -> V_41 ;
V_13 = F_8 ( V_10 -> V_42 ) & 0xff ;
V_11 = ( F_8 ( V_10 -> V_42 ) >> 24 ) & 0xff ;
V_12 = ( F_8 ( V_10 -> V_42 ) >> 8 ) & 0xff ;
F_9 ( L_3 ,
V_11 , V_12 , V_13 ) ;
V_2 -> V_16 . V_43 = ( ( V_11 << 24 ) | ( V_12 << 16 ) |
( V_13 << 8 ) ) ;
V_7 = F_10 ( F_8 ( V_10 -> V_44 ) + 8 )
+ V_45 + V_46 ;
V_15 = F_11 ( V_2 , V_7 , V_47 , true ,
V_48 ,
V_49 ,
NULL , NULL , & V_2 -> V_16 . V_50 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_40 , L_4 , V_15 ) ;
return V_15 ;
}
V_15 = F_12 ( V_2 -> V_16 . V_50 , false ) ;
if ( V_15 ) {
F_13 ( & V_2 -> V_16 . V_50 ) ;
F_5 ( V_2 -> V_40 , L_5 , V_15 ) ;
return V_15 ;
}
V_15 = F_14 ( V_2 -> V_16 . V_50 , V_48 ,
& V_2 -> V_16 . V_51 ) ;
if ( V_15 ) {
F_15 ( V_2 -> V_16 . V_50 ) ;
F_13 ( & V_2 -> V_16 . V_50 ) ;
F_5 ( V_2 -> V_40 , L_6 , V_15 ) ;
return V_15 ;
}
V_15 = F_16 ( V_2 -> V_16 . V_50 , & V_2 -> V_16 . V_52 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_40 , L_7 , V_15 ) ;
return V_15 ;
}
F_15 ( V_2 -> V_16 . V_50 ) ;
V_4 = & V_2 -> V_16 . V_4 ;
V_6 = & V_4 -> V_53 . V_54 [ V_55 ] ;
V_15 = F_17 ( & V_4 -> V_53 , & V_2 -> V_16 . V_56 ,
V_6 , V_57 ) ;
if ( V_15 != 0 ) {
F_18 ( L_8 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
F_19 ( & V_2 -> V_16 . V_59 [ V_14 ] , 0 ) ;
V_2 -> V_16 . V_60 [ V_14 ] = NULL ;
}
if ( ! F_20 ( V_2 , V_61 , 5 , 0 ) )
V_2 -> V_16 . V_62 = true ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_15 ;
if ( V_2 -> V_16 . V_50 == NULL )
return 0 ;
F_22 ( & V_2 -> V_16 . V_4 . V_53 , & V_2 -> V_16 . V_56 ) ;
V_15 = F_12 ( V_2 -> V_16 . V_50 , false ) ;
if ( ! V_15 ) {
F_23 ( V_2 -> V_16 . V_50 ) ;
F_24 ( V_2 -> V_16 . V_50 ) ;
F_15 ( V_2 -> V_16 . V_50 ) ;
}
F_13 ( & V_2 -> V_16 . V_50 ) ;
F_25 ( & V_2 -> V_16 . V_4 ) ;
F_7 ( V_2 -> V_16 . V_39 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned V_63 ;
void * V_64 ;
int V_14 ;
if ( V_2 -> V_16 . V_50 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 )
if ( F_27 ( & V_2 -> V_16 . V_59 [ V_14 ] ) )
break;
if ( V_14 == V_58 )
return 0 ;
F_28 ( & V_2 -> V_16 . V_17 ) ;
V_63 = F_29 ( V_2 -> V_16 . V_50 ) ;
V_64 = V_2 -> V_16 . V_52 ;
V_2 -> V_16 . V_65 = F_30 ( V_63 , V_66 ) ;
if ( ! V_2 -> V_16 . V_65 )
return - V_67 ;
memcpy ( V_2 -> V_16 . V_65 , V_64 , V_63 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned V_63 ;
void * V_64 ;
if ( V_2 -> V_16 . V_50 == NULL )
return - V_38 ;
V_63 = F_29 ( V_2 -> V_16 . V_50 ) ;
V_64 = V_2 -> V_16 . V_52 ;
if ( V_2 -> V_16 . V_65 != NULL ) {
memcpy ( V_64 , V_2 -> V_16 . V_65 , V_63 ) ;
F_32 ( V_2 -> V_16 . V_65 ) ;
V_2 -> V_16 . V_65 = NULL ;
} else {
const struct V_9 * V_10 ;
unsigned V_68 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_39 -> V_41 ;
V_68 = F_8 ( V_10 -> V_69 ) ;
memcpy ( V_2 -> V_16 . V_52 , ( V_2 -> V_16 . V_39 -> V_41 ) + V_68 ,
( V_2 -> V_16 . V_39 -> V_63 ) - V_68 ) ;
V_63 -= F_8 ( V_10 -> V_44 ) ;
V_64 += F_8 ( V_10 -> V_44 ) ;
memset ( V_64 , 0 , V_63 ) ;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 , struct V_70 * V_60 )
{
struct V_3 * V_4 = & V_2 -> V_16 . V_4 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
T_1 V_71 = F_27 ( & V_2 -> V_16 . V_59 [ V_14 ] ) ;
if ( V_71 != 0 && V_2 -> V_16 . V_60 [ V_14 ] == V_60 ) {
struct V_72 * V_72 ;
F_34 ( V_2 ) ;
V_15 = F_35 ( V_4 , V_71 ,
false , & V_72 ) ;
if ( V_15 ) {
F_18 ( L_9 , V_15 ) ;
continue;
}
F_36 ( V_72 , false ) ;
F_37 ( V_72 ) ;
V_2 -> V_16 . V_60 [ V_14 ] = NULL ;
F_19 ( & V_2 -> V_16 . V_59 [ V_14 ] , 0 ) ;
}
}
}
static void F_38 ( struct V_73 * V_74 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_74 -> V_75 . V_76 ; ++ V_14 ) {
V_74 -> V_77 [ V_14 ] . V_78 = 0 >> V_79 ;
V_74 -> V_77 [ V_14 ] . V_80 = ( 256 * 1024 * 1024 ) >> V_79 ;
}
}
static int F_39 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_73 * V_85 ;
T_1 V_86 , V_87 , V_88 ;
T_2 V_89 ;
int V_15 = 0 ;
V_87 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_92 ) ;
V_88 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_93 ) ;
V_89 = ( ( T_2 ) V_87 ) | ( ( ( T_2 ) V_88 ) << 32 ) ;
V_84 = F_41 ( V_82 -> V_90 , V_89 , & V_85 ) ;
if ( V_84 == NULL ) {
F_18 ( L_10 , V_89 ) ;
return - V_38 ;
}
if ( ! V_82 -> V_90 -> V_2 -> V_16 . V_62 ) {
V_86 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_94 ) >> 1 ;
if ( V_86 == 0x0 || V_86 == 0x3 ) {
T_1 V_95 = V_48 ;
F_42 ( V_85 , V_95 ) ;
}
F_38 ( V_85 ) ;
V_15 = F_43 ( & V_85 -> V_96 , & V_85 -> V_75 , false , false ) ;
}
return V_15 ;
}
static int F_44 ( T_1 * V_97 , unsigned V_98 [] )
{
unsigned V_99 = V_97 [ 4 ] ;
unsigned V_100 = V_97 [ 6 ] ;
unsigned V_101 = V_97 [ 7 ] ;
unsigned V_102 = V_97 [ 9 ] ;
unsigned V_103 = V_97 [ 28 ] ;
unsigned V_104 = V_97 [ 57 ] ;
unsigned V_105 = V_100 / 16 ;
unsigned V_106 = F_45 ( V_101 / 16 , 2 ) ;
unsigned V_107 = V_105 * V_106 ;
unsigned V_108 , V_109 , V_110 , V_111 ;
unsigned V_112 = 0 ;
V_108 = V_100 * V_101 ;
V_108 += V_108 / 2 ;
V_108 = F_45 ( V_108 , 1024 ) ;
switch ( V_99 ) {
case 0 :
case 7 :
switch( V_104 ) {
case 30 :
V_111 = 8100 / V_107 ;
break;
case 31 :
V_111 = 18000 / V_107 ;
break;
case 32 :
V_111 = 20480 / V_107 ;
break;
case 41 :
V_111 = 32768 / V_107 ;
break;
case 42 :
V_111 = 34816 / V_107 ;
break;
case 50 :
V_111 = 110400 / V_107 ;
break;
case 51 :
V_111 = 184320 / V_107 ;
break;
default:
V_111 = 184320 / V_107 ;
break;
}
V_111 ++ ;
if ( V_111 > 17 )
V_111 = 17 ;
V_110 = V_108 * V_111 ;
V_110 += V_105 * V_106 * V_111 * 192 ;
V_110 += V_105 * V_106 * 32 ;
break;
case 1 :
V_110 = V_108 * 3 ;
V_110 += V_105 * V_106 * 128 ;
V_110 += V_105 * 64 ;
V_110 += V_105 * 128 ;
V_109 = F_46 ( V_105 , V_106 ) ;
V_110 += F_45 ( V_109 * 7 * 16 , 64 ) ;
break;
case 3 :
V_110 = V_108 * 3 ;
break;
case 4 :
V_110 = V_108 * 3 ;
V_110 += V_105 * V_106 * 64 ;
V_110 += F_45 ( V_105 * V_106 * 32 , 64 ) ;
break;
case 16 :
V_108 = ( F_45 ( V_100 , 16 ) * F_45 ( V_101 , 16 ) * 3 ) / 2 ;
V_108 = F_45 ( V_108 , 256 ) ;
V_111 = ( F_8 ( V_97 [ 59 ] ) & 0xff ) + 2 ;
V_110 = V_108 * V_111 ;
V_112 = ( ( V_100 + 255 ) / 16 ) * ( ( V_101 + 255 ) / 16 )
* 16 * V_111 + 52 * 1024 ;
break;
default:
F_18 ( L_11 , V_99 ) ;
return - V_38 ;
}
if ( V_100 > V_103 ) {
F_18 ( L_12 ) ;
return - V_38 ;
}
if ( V_102 < V_110 ) {
F_18 ( L_13 ,
V_102 , V_110 ) ;
return - V_38 ;
}
V_98 [ 0x1 ] = V_102 ;
V_98 [ 0x2 ] = V_108 ;
V_98 [ 0x4 ] = V_112 ;
return 0 ;
}
static int F_47 ( struct V_81 * V_82 ,
struct V_73 * V_85 , unsigned V_68 )
{
struct V_1 * V_2 = V_82 -> V_90 -> V_2 ;
T_3 * V_97 , V_113 , V_71 ;
void * V_64 ;
long V_15 ;
int V_14 ;
if ( V_68 & 0x3F ) {
F_18 ( L_14 ) ;
return - V_38 ;
}
V_15 = F_16 ( V_85 , & V_64 ) ;
if ( V_15 ) {
F_18 ( L_15 , V_15 ) ;
return V_15 ;
}
V_97 = V_64 + V_68 ;
V_113 = V_97 [ 1 ] ;
V_71 = V_97 [ 2 ] ;
if ( V_71 == 0 ) {
F_18 ( L_16 ) ;
return - V_38 ;
}
switch ( V_113 ) {
case 0 :
F_23 ( V_85 ) ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
if ( F_27 ( & V_2 -> V_16 . V_59 [ V_14 ] ) == V_71 ) {
F_18 ( L_17 , V_71 ) ;
return - V_38 ;
}
if ( ! F_48 ( & V_2 -> V_16 . V_59 [ V_14 ] , 0 , V_71 ) ) {
V_2 -> V_16 . V_60 [ V_14 ] = V_82 -> V_90 -> V_60 ;
return 0 ;
}
}
F_18 ( L_18 ) ;
return - V_38 ;
case 1 :
V_15 = F_44 ( V_97 , V_82 -> V_98 ) ;
F_23 ( V_85 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
if ( F_27 ( & V_2 -> V_16 . V_59 [ V_14 ] ) == V_71 ) {
if ( V_2 -> V_16 . V_60 [ V_14 ] != V_82 -> V_90 -> V_60 ) {
F_18 ( L_19 ) ;
return - V_38 ;
}
return 0 ;
}
}
F_18 ( L_20 , V_71 ) ;
return - V_114 ;
case 2 :
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 )
F_48 ( & V_2 -> V_16 . V_59 [ V_14 ] , V_71 , 0 ) ;
F_23 ( V_85 ) ;
return 0 ;
default:
F_18 ( L_21 , V_113 ) ;
return - V_38 ;
}
F_49 () ;
return - V_38 ;
}
static int F_50 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_73 * V_85 ;
T_1 V_86 , V_87 , V_88 ;
T_2 V_115 , V_116 ;
T_2 V_89 ;
int V_15 ;
V_87 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_92 ) ;
V_88 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_93 ) ;
V_89 = ( ( T_2 ) V_87 ) | ( ( ( T_2 ) V_88 ) << 32 ) ;
V_84 = F_41 ( V_82 -> V_90 , V_89 , & V_85 ) ;
if ( V_84 == NULL )
return - V_38 ;
V_115 = F_51 ( V_85 ) ;
V_116 = ( V_84 -> V_117 . V_118 + 1 - V_84 -> V_117 . V_115 ) ;
V_116 = V_116 * V_119 + V_115 ;
V_89 -= ( ( T_2 ) V_84 -> V_117 . V_115 ) * V_119 ;
V_115 += V_89 ;
F_52 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_92 ,
F_53 ( V_115 ) ) ;
F_52 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_93 ,
F_54 ( V_115 ) ) ;
V_86 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_94 ) >> 1 ;
if ( V_86 < 0x4 ) {
if ( ( V_116 - V_115 ) < V_82 -> V_98 [ V_86 ] ) {
F_18 ( L_22 , V_86 ,
( unsigned ) ( V_116 - V_115 ) ,
V_82 -> V_98 [ V_86 ] ) ;
return - V_38 ;
}
} else if ( V_86 == 0x206 ) {
if ( ( V_116 - V_115 ) < V_82 -> V_98 [ 4 ] ) {
F_18 ( L_22 , V_86 ,
( unsigned ) ( V_116 - V_115 ) ,
V_82 -> V_98 [ 4 ] ) ;
return - V_38 ;
}
} else if ( ( V_86 != 0x100 ) && ( V_86 != 0x204 ) ) {
F_18 ( L_23 , V_86 ) ;
return - V_38 ;
}
if ( ! V_82 -> V_90 -> V_2 -> V_16 . V_62 ) {
if ( ( V_115 >> 28 ) != ( ( V_116 - 1 ) >> 28 ) ) {
F_18 ( L_24 ,
V_115 , V_116 ) ;
return - V_38 ;
}
if ( ( V_86 == 0 || V_86 == 0x3 ) &&
( V_115 >> 28 ) != ( V_82 -> V_90 -> V_2 -> V_16 . V_51 >> 28 ) ) {
F_18 ( L_25 ,
V_115 , V_116 ) ;
return - V_38 ;
}
}
if ( V_86 == 0 ) {
V_82 -> V_120 = true ;
V_15 = F_47 ( V_82 , V_85 , V_89 ) ;
if ( V_15 )
return V_15 ;
} else if ( ! V_82 -> V_120 ) {
F_18 ( L_26 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_55 ( struct V_81 * V_82 ,
int (* F_56)( struct V_81 * V_82 ) )
{
struct V_121 * V_122 = & V_82 -> V_90 -> V_123 -> V_124 [ V_82 -> V_91 ] ;
int V_14 , V_15 ;
V_82 -> V_94 ++ ;
for ( V_14 = 0 ; V_14 <= V_82 -> V_125 ; ++ V_14 ) {
unsigned V_126 = V_82 -> V_126 + V_14 ;
if ( V_82 -> V_94 >= V_122 -> V_127 ) {
F_18 ( L_27 ) ;
return - V_38 ;
}
switch ( V_126 ) {
case V_128 :
V_82 -> V_92 = V_82 -> V_94 ;
break;
case V_129 :
V_82 -> V_93 = V_82 -> V_94 ;
break;
case V_130 :
V_15 = F_56 ( V_82 ) ;
if ( V_15 )
return V_15 ;
break;
case V_131 :
break;
default:
F_18 ( L_28 , V_126 ) ;
return - V_38 ;
}
V_82 -> V_94 ++ ;
}
return 0 ;
}
static int F_57 ( struct V_81 * V_82 ,
int (* F_56)( struct V_81 * V_82 ) )
{
struct V_121 * V_122 = & V_82 -> V_90 -> V_123 -> V_124 [ V_82 -> V_91 ] ;
int V_15 ;
for ( V_82 -> V_94 = 0 ; V_82 -> V_94 < V_122 -> V_127 ; ) {
T_1 V_86 = F_40 ( V_82 -> V_90 , V_82 -> V_91 , V_82 -> V_94 ) ;
unsigned type = F_58 ( V_86 ) ;
switch ( type ) {
case V_132 :
V_82 -> V_126 = F_59 ( V_86 ) ;
V_82 -> V_125 = F_60 ( V_86 ) ;
V_15 = F_55 ( V_82 , F_56 ) ;
if ( V_15 )
return V_15 ;
break;
case V_133 :
++ V_82 -> V_94 ;
break;
default:
F_18 ( L_29 , type ) ;
return - V_38 ;
}
}
return 0 ;
}
int F_61 ( struct V_134 * V_90 , T_1 V_91 )
{
struct V_81 V_82 = {} ;
unsigned V_98 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_121 * V_122 = & V_90 -> V_123 -> V_124 [ V_91 ] ;
int V_15 ;
if ( V_122 -> V_127 % 16 ) {
F_18 ( L_30 ,
V_122 -> V_127 ) ;
return - V_38 ;
}
V_82 . V_90 = V_90 ;
V_82 . V_98 = V_98 ;
V_82 . V_91 = V_91 ;
V_15 = F_57 ( & V_82 , F_39 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_57 ( & V_82 , F_50 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_82 . V_120 ) {
F_18 ( L_31 ) ;
return - V_38 ;
}
F_34 ( V_82 . V_90 -> V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 , struct V_73 * V_85 ,
bool V_135 , struct V_72 * * V_72 )
{
struct V_136 V_137 ;
struct V_138 V_139 ;
struct V_140 V_141 ;
struct V_142 * V_123 ;
struct V_121 * V_122 ;
struct V_72 * V_143 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_89 ;
int V_14 , V_15 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_85 = & V_85 -> V_96 ;
F_63 ( & V_141 ) ;
F_64 ( & V_137 . V_141 , & V_141 ) ;
V_15 = F_65 ( & V_139 , & V_141 , true , NULL ) ;
if ( V_15 )
return V_15 ;
if ( ! V_85 -> V_2 -> V_16 . V_62 ) {
F_42 ( V_85 , V_48 ) ;
F_38 ( V_85 ) ;
}
V_15 = F_43 ( & V_85 -> V_96 , & V_85 -> V_75 , true , false ) ;
if ( V_15 )
goto V_144;
V_15 = F_66 ( V_2 , 64 , & V_123 ) ;
if ( V_15 )
goto V_144;
V_122 = & V_123 -> V_124 [ 0 ] ;
V_89 = F_51 ( V_85 ) ;
V_122 -> V_64 [ 0 ] = F_67 ( V_128 , 0 ) ;
V_122 -> V_64 [ 1 ] = V_89 ;
V_122 -> V_64 [ 2 ] = F_67 ( V_129 , 0 ) ;
V_122 -> V_64 [ 3 ] = V_89 >> 32 ;
V_122 -> V_64 [ 4 ] = F_67 ( V_130 , 0 ) ;
V_122 -> V_64 [ 5 ] = 0 ;
for ( V_14 = 6 ; V_14 < 16 ; ++ V_14 )
V_122 -> V_64 [ V_14 ] = F_68 ( 0 ) ;
V_122 -> V_127 = 16 ;
if ( V_135 ) {
V_15 = F_69 ( V_4 , 1 , V_122 , NULL , & V_143 ) ;
V_123 -> V_72 = V_143 ;
if ( V_15 )
goto V_145;
F_70 ( V_123 ) ;
} else {
V_15 = F_71 ( V_123 , V_4 , & V_2 -> V_16 . V_56 ,
V_146 , & V_143 ) ;
if ( V_15 )
goto V_145;
}
F_72 ( & V_139 , & V_141 , V_143 ) ;
if ( V_72 )
* V_72 = F_73 ( V_143 ) ;
F_13 ( & V_85 ) ;
F_37 ( V_143 ) ;
return 0 ;
V_145:
F_70 ( V_123 ) ;
V_144:
F_74 ( & V_139 , & V_141 ) ;
return V_15 ;
}
int F_75 ( struct V_3 * V_4 , T_1 V_71 ,
struct V_72 * * V_72 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_73 * V_85 ;
T_1 * V_97 ;
int V_15 , V_14 ;
V_15 = F_11 ( V_2 , 1024 , V_47 , true ,
V_48 ,
V_49 ,
NULL , NULL , & V_85 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_12 ( V_85 , false ) ;
if ( V_15 ) {
F_13 ( & V_85 ) ;
return V_15 ;
}
V_15 = F_16 ( V_85 , ( void * * ) & V_97 ) ;
if ( V_15 ) {
F_15 ( V_85 ) ;
F_13 ( & V_85 ) ;
return V_15 ;
}
V_97 [ 0 ] = F_76 ( 0x00000de4 ) ;
V_97 [ 1 ] = F_76 ( 0x00000000 ) ;
V_97 [ 2 ] = F_76 ( V_71 ) ;
V_97 [ 3 ] = F_76 ( 0x00000000 ) ;
V_97 [ 4 ] = F_76 ( 0x00000000 ) ;
V_97 [ 5 ] = F_76 ( 0x00000000 ) ;
V_97 [ 6 ] = F_76 ( 0x00000000 ) ;
V_97 [ 7 ] = F_76 ( 0x00000780 ) ;
V_97 [ 8 ] = F_76 ( 0x00000440 ) ;
V_97 [ 9 ] = F_76 ( 0x00000000 ) ;
V_97 [ 10 ] = F_76 ( 0x01b37000 ) ;
for ( V_14 = 11 ; V_14 < 1024 ; ++ V_14 )
V_97 [ V_14 ] = F_76 ( 0x0 ) ;
F_23 ( V_85 ) ;
F_15 ( V_85 ) ;
return F_62 ( V_4 , V_85 , true , V_72 ) ;
}
int F_35 ( struct V_3 * V_4 , T_1 V_71 ,
bool V_135 , struct V_72 * * V_72 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_73 * V_85 ;
T_1 * V_97 ;
int V_15 , V_14 ;
V_15 = F_11 ( V_2 , 1024 , V_47 , true ,
V_48 ,
V_49 ,
NULL , NULL , & V_85 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_12 ( V_85 , false ) ;
if ( V_15 ) {
F_13 ( & V_85 ) ;
return V_15 ;
}
V_15 = F_16 ( V_85 , ( void * * ) & V_97 ) ;
if ( V_15 ) {
F_15 ( V_85 ) ;
F_13 ( & V_85 ) ;
return V_15 ;
}
V_97 [ 0 ] = F_76 ( 0x00000de4 ) ;
V_97 [ 1 ] = F_76 ( 0x00000002 ) ;
V_97 [ 2 ] = F_76 ( V_71 ) ;
V_97 [ 3 ] = F_76 ( 0x00000000 ) ;
for ( V_14 = 4 ; V_14 < 1024 ; ++ V_14 )
V_97 [ V_14 ] = F_76 ( 0x0 ) ;
F_23 ( V_85 ) ;
F_15 ( V_85 ) ;
return F_62 ( V_4 , V_85 , V_135 , V_72 ) ;
}
static void V_18 ( struct V_147 * V_148 )
{
struct V_1 * V_2 =
F_77 ( V_148 , struct V_1 , V_16 . V_17 . V_148 ) ;
unsigned V_14 , V_149 , V_59 = 0 ;
V_149 = F_78 ( & V_2 -> V_16 . V_4 ) ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 )
if ( F_27 ( & V_2 -> V_16 . V_59 [ V_14 ] ) )
++ V_59 ;
if ( V_149 == 0 && V_59 == 0 ) {
if ( V_2 -> V_150 . V_151 ) {
F_79 ( V_2 , false ) ;
} else {
F_80 ( V_2 , 0 , 0 ) ;
}
} else {
F_81 ( & V_2 -> V_16 . V_17 ,
F_82 ( V_152 ) ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
bool V_153 = ! F_28 ( & V_2 -> V_16 . V_17 ) ;
V_153 &= F_81 ( & V_2 -> V_16 . V_17 ,
F_82 ( V_152 ) ) ;
if ( V_153 ) {
if ( V_2 -> V_150 . V_151 ) {
F_79 ( V_2 , true ) ;
} else {
F_80 ( V_2 , 53300 , 40000 ) ;
}
}
}
