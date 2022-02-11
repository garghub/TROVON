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
V_15 = F_12 ( V_2 , V_7 , V_56 , true ,
V_57 ,
V_58 ,
NULL , NULL , & V_2 -> V_16 . V_59 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_44 , L_5 , V_15 ) ;
return V_15 ;
}
V_15 = F_13 ( V_2 -> V_16 . V_59 , false ) ;
if ( V_15 ) {
F_14 ( & V_2 -> V_16 . V_59 ) ;
F_5 ( V_2 -> V_44 , L_6 , V_15 ) ;
return V_15 ;
}
V_15 = F_15 ( V_2 -> V_16 . V_59 , V_57 ,
& V_2 -> V_16 . V_60 ) ;
if ( V_15 ) {
F_16 ( V_2 -> V_16 . V_59 ) ;
F_14 ( & V_2 -> V_16 . V_59 ) ;
F_5 ( V_2 -> V_44 , L_7 , V_15 ) ;
return V_15 ;
}
V_15 = F_17 ( V_2 -> V_16 . V_59 , & V_2 -> V_16 . V_61 ) ;
if ( V_15 ) {
F_5 ( V_2 -> V_44 , L_8 , V_15 ) ;
return V_15 ;
}
F_16 ( V_2 -> V_16 . V_59 ) ;
V_4 = & V_2 -> V_16 . V_4 ;
V_6 = & V_4 -> V_62 . V_63 [ V_64 ] ;
V_15 = F_18 ( & V_4 -> V_62 , & V_2 -> V_16 . V_65 ,
V_6 , V_66 ) ;
if ( V_15 != 0 ) {
F_10 ( L_9 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
F_19 ( & V_2 -> V_16 . V_67 [ V_14 ] , 0 ) ;
V_2 -> V_16 . V_68 [ V_14 ] = NULL ;
}
if ( ! F_20 ( V_2 , V_69 , 5 , 0 ) )
V_2 -> V_16 . V_70 = true ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_15 ;
F_22 ( V_2 -> V_16 . V_71 ) ;
F_23 ( & V_2 -> V_16 . V_4 . V_62 , & V_2 -> V_16 . V_65 ) ;
if ( V_2 -> V_16 . V_59 ) {
V_15 = F_13 ( V_2 -> V_16 . V_59 , false ) ;
if ( ! V_15 ) {
F_24 ( V_2 -> V_16 . V_59 ) ;
F_25 ( V_2 -> V_16 . V_59 ) ;
F_16 ( V_2 -> V_16 . V_59 ) ;
}
F_14 ( & V_2 -> V_16 . V_59 ) ;
}
F_26 ( & V_2 -> V_16 . V_4 ) ;
F_7 ( V_2 -> V_16 . V_43 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned V_72 ;
void * V_73 ;
int V_14 ;
if ( V_2 -> V_16 . V_59 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) )
break;
if ( V_14 == V_49 )
return 0 ;
F_29 ( & V_2 -> V_16 . V_17 ) ;
V_72 = F_30 ( V_2 -> V_16 . V_59 ) ;
V_73 = V_2 -> V_16 . V_61 ;
V_2 -> V_16 . V_71 = F_31 ( V_72 , V_74 ) ;
if ( ! V_2 -> V_16 . V_71 )
return - V_75 ;
memcpy ( V_2 -> V_16 . V_71 , V_73 , V_72 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
unsigned V_72 ;
void * V_73 ;
if ( V_2 -> V_16 . V_59 == NULL )
return - V_42 ;
V_72 = F_30 ( V_2 -> V_16 . V_59 ) ;
V_73 = V_2 -> V_16 . V_61 ;
if ( V_2 -> V_16 . V_71 != NULL ) {
memcpy ( V_73 , V_2 -> V_16 . V_71 , V_72 ) ;
F_22 ( V_2 -> V_16 . V_71 ) ;
V_2 -> V_16 . V_71 = NULL ;
} else {
const struct V_9 * V_10 ;
unsigned V_76 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_43 -> V_47 ;
V_76 = F_8 ( V_10 -> V_77 ) ;
memcpy ( V_2 -> V_16 . V_61 , ( V_2 -> V_16 . V_43 -> V_47 ) + V_76 ,
( V_2 -> V_16 . V_43 -> V_72 ) - V_76 ) ;
V_72 -= F_8 ( V_10 -> V_52 ) ;
V_73 += F_8 ( V_10 -> V_52 ) ;
memset ( V_73 , 0 , V_72 ) ;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 , struct V_78 * V_68 )
{
struct V_3 * V_4 = & V_2 -> V_16 . V_4 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
T_1 V_79 = F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) ;
if ( V_79 != 0 && V_2 -> V_16 . V_68 [ V_14 ] == V_68 ) {
struct V_80 * V_80 ;
F_34 ( V_2 ) ;
V_15 = F_35 ( V_4 , V_79 ,
false , & V_80 ) ;
if ( V_15 ) {
F_10 ( L_10 , V_15 ) ;
continue;
}
F_36 ( V_80 , false ) ;
F_37 ( V_80 ) ;
V_2 -> V_16 . V_68 [ V_14 ] = NULL ;
F_19 ( & V_2 -> V_16 . V_67 [ V_14 ] , 0 ) ;
}
}
}
static void F_38 ( struct V_81 * V_82 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_82 -> V_83 . V_84 ; ++ V_14 ) {
V_82 -> V_85 [ V_14 ] . V_86 = 0 >> V_87 ;
V_82 -> V_85 [ V_14 ] . V_88 = ( 256 * 1024 * 1024 ) >> V_87 ;
}
}
static int F_39 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_81 * V_93 ;
T_1 V_94 , V_95 , V_96 ;
T_2 V_97 ;
int V_15 = 0 ;
V_95 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_100 ) ;
V_96 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_101 ) ;
V_97 = ( ( T_2 ) V_95 ) | ( ( ( T_2 ) V_96 ) << 32 ) ;
V_92 = F_41 ( V_90 -> V_98 , V_97 , & V_93 ) ;
if ( V_92 == NULL ) {
F_10 ( L_11 , V_97 ) ;
return - V_42 ;
}
if ( ! V_90 -> V_98 -> V_2 -> V_16 . V_70 ) {
V_94 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_102 ) >> 1 ;
if ( V_94 == 0x0 || V_94 == 0x3 ) {
T_1 V_103 = V_57 ;
F_42 ( V_93 , V_103 ) ;
}
F_38 ( V_93 ) ;
V_15 = F_43 ( & V_93 -> V_104 , & V_93 -> V_83 , false , false ) ;
}
return V_15 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 * V_105 ,
unsigned V_106 [] )
{
unsigned V_107 = V_105 [ 4 ] ;
unsigned V_108 = V_105 [ 6 ] ;
unsigned V_109 = V_105 [ 7 ] ;
unsigned V_110 = V_105 [ 9 ] ;
unsigned V_111 = V_105 [ 28 ] ;
unsigned V_112 = V_105 [ 57 ] ;
unsigned V_113 = V_108 / 16 ;
unsigned V_114 = F_45 ( V_109 / 16 , 2 ) ;
unsigned V_115 = V_113 * V_114 ;
unsigned V_116 , V_117 , V_118 , V_119 ;
unsigned V_120 = 0 ;
V_116 = V_108 * V_109 ;
V_116 += V_116 / 2 ;
V_116 = F_45 ( V_116 , 1024 ) ;
switch ( V_107 ) {
case 0 :
switch( V_112 ) {
case 30 :
V_119 = 8100 / V_115 ;
break;
case 31 :
V_119 = 18000 / V_115 ;
break;
case 32 :
V_119 = 20480 / V_115 ;
break;
case 41 :
V_119 = 32768 / V_115 ;
break;
case 42 :
V_119 = 34816 / V_115 ;
break;
case 50 :
V_119 = 110400 / V_115 ;
break;
case 51 :
V_119 = 184320 / V_115 ;
break;
default:
V_119 = 184320 / V_115 ;
break;
}
V_119 ++ ;
if ( V_119 > 17 )
V_119 = 17 ;
V_118 = V_116 * V_119 ;
V_118 += V_113 * V_114 * V_119 * 192 ;
V_118 += V_113 * V_114 * 32 ;
break;
case 1 :
V_118 = V_116 * 3 ;
V_118 += V_113 * V_114 * 128 ;
V_118 += V_113 * 64 ;
V_118 += V_113 * 128 ;
V_117 = F_46 ( V_113 , V_114 ) ;
V_118 += F_45 ( V_117 * 7 * 16 , 64 ) ;
break;
case 3 :
V_118 = V_116 * 3 ;
break;
case 4 :
V_118 = V_116 * 3 ;
V_118 += V_113 * V_114 * 64 ;
V_118 += F_45 ( V_113 * V_114 * 32 , 64 ) ;
break;
case 7 :
switch( V_112 ) {
case 30 :
V_119 = 8100 / V_115 ;
break;
case 31 :
V_119 = 18000 / V_115 ;
break;
case 32 :
V_119 = 20480 / V_115 ;
break;
case 41 :
V_119 = 32768 / V_115 ;
break;
case 42 :
V_119 = 34816 / V_115 ;
break;
case 50 :
V_119 = 110400 / V_115 ;
break;
case 51 :
V_119 = 184320 / V_115 ;
break;
default:
V_119 = 184320 / V_115 ;
break;
}
V_119 ++ ;
if ( V_119 > 17 )
V_119 = 17 ;
V_118 = V_116 * V_119 ;
if ( V_2 -> V_19 < V_38 ) {
V_118 +=
V_113 * V_114 * V_119 * 192 ;
V_118 += V_113 * V_114 * 32 ;
} else {
V_120 =
V_113 * V_114 * V_119 * 192 ;
}
break;
case 16 :
V_116 = ( F_45 ( V_108 , 16 ) * F_45 ( V_109 , 16 ) * 3 ) / 2 ;
V_116 = F_45 ( V_116 , 256 ) ;
V_119 = ( F_8 ( V_105 [ 59 ] ) & 0xff ) + 2 ;
V_118 = V_116 * V_119 ;
V_120 = ( ( V_108 + 255 ) / 16 ) * ( ( V_109 + 255 ) / 16 )
* 16 * V_119 + 52 * 1024 ;
break;
default:
F_10 ( L_12 , V_107 ) ;
return - V_42 ;
}
if ( V_108 > V_111 ) {
F_10 ( L_13 ) ;
return - V_42 ;
}
if ( V_110 < V_118 ) {
F_10 ( L_14 ,
V_110 , V_118 ) ;
return - V_42 ;
}
V_106 [ 0x1 ] = V_110 ;
V_106 [ 0x2 ] = V_116 ;
V_106 [ 0x4 ] = V_120 ;
return 0 ;
}
static int F_47 ( struct V_89 * V_90 ,
struct V_81 * V_93 , unsigned V_76 )
{
struct V_1 * V_2 = V_90 -> V_98 -> V_2 ;
T_3 * V_105 , V_121 , V_79 ;
void * V_73 ;
long V_15 ;
int V_14 ;
if ( V_76 & 0x3F ) {
F_10 ( L_15 ) ;
return - V_42 ;
}
V_15 = F_17 ( V_93 , & V_73 ) ;
if ( V_15 ) {
F_10 ( L_16 , V_15 ) ;
return V_15 ;
}
V_105 = V_73 + V_76 ;
V_121 = V_105 [ 1 ] ;
V_79 = V_105 [ 2 ] ;
if ( V_79 == 0 ) {
F_10 ( L_17 ) ;
return - V_42 ;
}
switch ( V_121 ) {
case 0 :
F_24 ( V_93 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) == V_79 ) {
F_10 ( L_18 , V_79 ) ;
return - V_42 ;
}
if ( ! F_48 ( & V_2 -> V_16 . V_67 [ V_14 ] , 0 , V_79 ) ) {
V_2 -> V_16 . V_68 [ V_14 ] = V_90 -> V_98 -> V_68 ;
return 0 ;
}
}
F_10 ( L_19 ) ;
return - V_42 ;
case 1 :
V_15 = F_44 ( V_2 , V_105 , V_90 -> V_106 ) ;
F_24 ( V_93 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) == V_79 ) {
if ( V_2 -> V_16 . V_68 [ V_14 ] != V_90 -> V_98 -> V_68 ) {
F_10 ( L_20 ) ;
return - V_42 ;
}
return 0 ;
}
}
F_10 ( L_21 , V_79 ) ;
return - V_122 ;
case 2 :
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
F_48 ( & V_2 -> V_16 . V_67 [ V_14 ] , V_79 , 0 ) ;
F_24 ( V_93 ) ;
return 0 ;
default:
F_10 ( L_22 , V_121 ) ;
return - V_42 ;
}
F_49 () ;
return - V_42 ;
}
static int F_50 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
struct V_81 * V_93 ;
T_1 V_94 , V_95 , V_96 ;
T_2 V_123 , V_124 ;
T_2 V_97 ;
int V_15 ;
V_95 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_100 ) ;
V_96 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_101 ) ;
V_97 = ( ( T_2 ) V_95 ) | ( ( ( T_2 ) V_96 ) << 32 ) ;
V_92 = F_41 ( V_90 -> V_98 , V_97 , & V_93 ) ;
if ( V_92 == NULL )
return - V_42 ;
V_123 = F_51 ( V_93 ) ;
V_124 = ( V_92 -> V_125 . V_126 + 1 - V_92 -> V_125 . V_123 ) ;
V_124 = V_124 * V_127 + V_123 ;
V_97 -= ( ( T_2 ) V_92 -> V_125 . V_123 ) * V_127 ;
V_123 += V_97 ;
F_52 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_100 ,
F_53 ( V_123 ) ) ;
F_52 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_101 ,
F_54 ( V_123 ) ) ;
V_94 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_102 ) >> 1 ;
if ( V_94 < 0x4 ) {
if ( ( V_124 - V_123 ) < V_90 -> V_106 [ V_94 ] ) {
F_10 ( L_23 , V_94 ,
( unsigned ) ( V_124 - V_123 ) ,
V_90 -> V_106 [ V_94 ] ) ;
return - V_42 ;
}
} else if ( V_94 == 0x206 ) {
if ( ( V_124 - V_123 ) < V_90 -> V_106 [ 4 ] ) {
F_10 ( L_23 , V_94 ,
( unsigned ) ( V_124 - V_123 ) ,
V_90 -> V_106 [ 4 ] ) ;
return - V_42 ;
}
} else if ( ( V_94 != 0x100 ) && ( V_94 != 0x204 ) ) {
F_10 ( L_24 , V_94 ) ;
return - V_42 ;
}
if ( ! V_90 -> V_98 -> V_2 -> V_16 . V_70 ) {
if ( ( V_123 >> 28 ) != ( ( V_124 - 1 ) >> 28 ) ) {
F_10 ( L_25 ,
V_123 , V_124 ) ;
return - V_42 ;
}
if ( ( V_94 == 0 || V_94 == 0x3 ) &&
( V_123 >> 28 ) != ( V_90 -> V_98 -> V_2 -> V_16 . V_60 >> 28 ) ) {
F_10 ( L_26 ,
V_123 , V_124 ) ;
return - V_42 ;
}
}
if ( V_94 == 0 ) {
V_90 -> V_128 = true ;
V_15 = F_47 ( V_90 , V_93 , V_97 ) ;
if ( V_15 )
return V_15 ;
} else if ( ! V_90 -> V_128 ) {
F_10 ( L_27 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_55 ( struct V_89 * V_90 ,
int (* F_56)( struct V_89 * V_90 ) )
{
struct V_129 * V_130 = & V_90 -> V_98 -> V_131 -> V_132 [ V_90 -> V_99 ] ;
int V_14 , V_15 ;
V_90 -> V_102 ++ ;
for ( V_14 = 0 ; V_14 <= V_90 -> V_133 ; ++ V_14 ) {
unsigned V_134 = V_90 -> V_134 + V_14 ;
if ( V_90 -> V_102 >= V_130 -> V_135 ) {
F_10 ( L_28 ) ;
return - V_42 ;
}
switch ( V_134 ) {
case V_136 :
V_90 -> V_100 = V_90 -> V_102 ;
break;
case V_137 :
V_90 -> V_101 = V_90 -> V_102 ;
break;
case V_138 :
V_15 = F_56 ( V_90 ) ;
if ( V_15 )
return V_15 ;
break;
case V_139 :
break;
default:
F_10 ( L_29 , V_134 ) ;
return - V_42 ;
}
V_90 -> V_102 ++ ;
}
return 0 ;
}
static int F_57 ( struct V_89 * V_90 ,
int (* F_56)( struct V_89 * V_90 ) )
{
struct V_129 * V_130 = & V_90 -> V_98 -> V_131 -> V_132 [ V_90 -> V_99 ] ;
int V_15 ;
for ( V_90 -> V_102 = 0 ; V_90 -> V_102 < V_130 -> V_135 ; ) {
T_1 V_94 = F_40 ( V_90 -> V_98 , V_90 -> V_99 , V_90 -> V_102 ) ;
unsigned type = F_58 ( V_94 ) ;
switch ( type ) {
case V_140 :
V_90 -> V_134 = F_59 ( V_94 ) ;
V_90 -> V_133 = F_60 ( V_94 ) ;
V_15 = F_55 ( V_90 , F_56 ) ;
if ( V_15 )
return V_15 ;
break;
case V_141 :
++ V_90 -> V_102 ;
break;
default:
F_10 ( L_30 , type ) ;
return - V_42 ;
}
}
return 0 ;
}
int F_61 ( struct V_142 * V_98 , T_1 V_99 )
{
struct V_89 V_90 = {} ;
unsigned V_106 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_129 * V_130 = & V_98 -> V_131 -> V_132 [ V_99 ] ;
int V_15 ;
if ( V_130 -> V_135 % 16 ) {
F_10 ( L_31 ,
V_130 -> V_135 ) ;
return - V_42 ;
}
V_90 . V_98 = V_98 ;
V_90 . V_106 = V_106 ;
V_90 . V_99 = V_99 ;
V_15 = F_57 ( & V_90 , F_39 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_57 ( & V_90 , F_50 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_90 . V_128 ) {
F_10 ( L_32 ) ;
return - V_42 ;
}
F_34 ( V_90 . V_98 -> V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 , struct V_81 * V_93 ,
bool V_143 , struct V_80 * * V_80 )
{
struct V_144 V_145 ;
struct V_146 V_147 ;
struct V_148 V_149 ;
struct V_150 * V_131 ;
struct V_129 * V_130 ;
struct V_80 * V_151 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_97 ;
int V_14 , V_15 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_93 = & V_93 -> V_104 ;
F_63 ( & V_149 ) ;
F_64 ( & V_145 . V_149 , & V_149 ) ;
V_15 = F_65 ( & V_147 , & V_149 , true , NULL ) ;
if ( V_15 )
return V_15 ;
if ( ! V_93 -> V_2 -> V_16 . V_70 ) {
F_42 ( V_93 , V_57 ) ;
F_38 ( V_93 ) ;
}
V_15 = F_43 ( & V_93 -> V_104 , & V_93 -> V_83 , true , false ) ;
if ( V_15 )
goto V_152;
V_15 = F_66 ( V_2 , 64 , & V_131 ) ;
if ( V_15 )
goto V_152;
V_130 = & V_131 -> V_132 [ 0 ] ;
V_97 = F_51 ( V_93 ) ;
V_130 -> V_73 [ 0 ] = F_67 ( V_136 , 0 ) ;
V_130 -> V_73 [ 1 ] = V_97 ;
V_130 -> V_73 [ 2 ] = F_67 ( V_137 , 0 ) ;
V_130 -> V_73 [ 3 ] = V_97 >> 32 ;
V_130 -> V_73 [ 4 ] = F_67 ( V_138 , 0 ) ;
V_130 -> V_73 [ 5 ] = 0 ;
for ( V_14 = 6 ; V_14 < 16 ; ++ V_14 )
V_130 -> V_73 [ V_14 ] = F_68 ( 0 ) ;
V_130 -> V_135 = 16 ;
if ( V_143 ) {
V_15 = F_69 ( V_4 , 1 , V_130 , NULL , NULL , & V_151 ) ;
V_131 -> V_80 = V_151 ;
if ( V_15 )
goto V_153;
F_70 ( V_131 ) ;
} else {
V_15 = F_71 ( V_131 , V_4 , & V_2 -> V_16 . V_65 ,
V_154 , & V_151 ) ;
if ( V_15 )
goto V_153;
}
F_72 ( & V_147 , & V_149 , V_151 ) ;
if ( V_80 )
* V_80 = F_73 ( V_151 ) ;
F_14 ( & V_93 ) ;
F_37 ( V_151 ) ;
return 0 ;
V_153:
F_70 ( V_131 ) ;
V_152:
F_74 ( & V_147 , & V_149 ) ;
return V_15 ;
}
int F_75 ( struct V_3 * V_4 , T_1 V_79 ,
struct V_80 * * V_80 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_81 * V_93 ;
T_1 * V_105 ;
int V_15 , V_14 ;
V_15 = F_12 ( V_2 , 1024 , V_56 , true ,
V_57 ,
V_58 ,
NULL , NULL , & V_93 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_93 , false ) ;
if ( V_15 ) {
F_14 ( & V_93 ) ;
return V_15 ;
}
V_15 = F_17 ( V_93 , ( void * * ) & V_105 ) ;
if ( V_15 ) {
F_16 ( V_93 ) ;
F_14 ( & V_93 ) ;
return V_15 ;
}
V_105 [ 0 ] = F_76 ( 0x00000de4 ) ;
V_105 [ 1 ] = F_76 ( 0x00000000 ) ;
V_105 [ 2 ] = F_76 ( V_79 ) ;
V_105 [ 3 ] = F_76 ( 0x00000000 ) ;
V_105 [ 4 ] = F_76 ( 0x00000000 ) ;
V_105 [ 5 ] = F_76 ( 0x00000000 ) ;
V_105 [ 6 ] = F_76 ( 0x00000000 ) ;
V_105 [ 7 ] = F_76 ( 0x00000780 ) ;
V_105 [ 8 ] = F_76 ( 0x00000440 ) ;
V_105 [ 9 ] = F_76 ( 0x00000000 ) ;
V_105 [ 10 ] = F_76 ( 0x01b37000 ) ;
for ( V_14 = 11 ; V_14 < 1024 ; ++ V_14 )
V_105 [ V_14 ] = F_76 ( 0x0 ) ;
F_24 ( V_93 ) ;
F_16 ( V_93 ) ;
return F_62 ( V_4 , V_93 , true , V_80 ) ;
}
int F_35 ( struct V_3 * V_4 , T_1 V_79 ,
bool V_143 , struct V_80 * * V_80 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_81 * V_93 ;
T_1 * V_105 ;
int V_15 , V_14 ;
V_15 = F_12 ( V_2 , 1024 , V_56 , true ,
V_57 ,
V_58 ,
NULL , NULL , & V_93 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_93 , false ) ;
if ( V_15 ) {
F_14 ( & V_93 ) ;
return V_15 ;
}
V_15 = F_17 ( V_93 , ( void * * ) & V_105 ) ;
if ( V_15 ) {
F_16 ( V_93 ) ;
F_14 ( & V_93 ) ;
return V_15 ;
}
V_105 [ 0 ] = F_76 ( 0x00000de4 ) ;
V_105 [ 1 ] = F_76 ( 0x00000002 ) ;
V_105 [ 2 ] = F_76 ( V_79 ) ;
V_105 [ 3 ] = F_76 ( 0x00000000 ) ;
for ( V_14 = 4 ; V_14 < 1024 ; ++ V_14 )
V_105 [ V_14 ] = F_76 ( 0x0 ) ;
F_24 ( V_93 ) ;
F_16 ( V_93 ) ;
return F_62 ( V_4 , V_93 , V_143 , V_80 ) ;
}
static void V_18 ( struct V_155 * V_156 )
{
struct V_1 * V_2 =
F_77 ( V_156 , struct V_1 , V_16 . V_17 . V_156 ) ;
unsigned V_14 , V_157 , V_67 = 0 ;
V_157 = F_78 ( & V_2 -> V_16 . V_4 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) )
++ V_67 ;
if ( V_157 == 0 && V_67 == 0 ) {
if ( V_2 -> V_158 . V_159 ) {
F_79 ( V_2 , false ) ;
if ( V_2 -> V_19 == V_38 )
F_80 ( V_2 , 0 , 0 ) ;
} else {
F_80 ( V_2 , 0 , 0 ) ;
}
} else {
F_81 ( & V_2 -> V_16 . V_17 ,
F_82 ( V_160 ) ) ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
bool V_161 = ! F_29 ( & V_2 -> V_16 . V_17 ) ;
V_161 &= F_81 ( & V_2 -> V_16 . V_17 ,
F_82 ( V_160 ) ) ;
if ( V_161 ) {
if ( V_2 -> V_158 . V_159 ) {
F_79 ( V_2 , true ) ;
} else {
F_80 ( V_2 , 53300 , 40000 ) ;
}
}
}
