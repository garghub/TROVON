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
switch ( V_2 -> V_19 ) {
case V_30 :
V_2 -> V_16 . V_71 = V_2 -> V_16 . V_50 >= V_72 ;
break;
case V_34 :
V_2 -> V_16 . V_71 = V_2 -> V_16 . V_50 >= V_73 ;
break;
case V_32 :
V_2 -> V_16 . V_71 = V_2 -> V_16 . V_50 >= V_74 ;
break;
case V_36 :
V_2 -> V_16 . V_71 = V_2 -> V_16 . V_50 >= V_75 ;
break;
default:
V_2 -> V_16 . V_71 = V_2 -> V_19 >= V_38 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_15 ;
F_22 ( V_2 -> V_16 . V_76 ) ;
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
unsigned V_77 ;
void * V_78 ;
int V_14 ;
if ( V_2 -> V_16 . V_59 == NULL )
return 0 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) )
break;
if ( V_14 == V_49 )
return 0 ;
F_29 ( & V_2 -> V_16 . V_17 ) ;
V_77 = F_30 ( V_2 -> V_16 . V_59 ) ;
V_78 = V_2 -> V_16 . V_61 ;
V_2 -> V_16 . V_76 = F_31 ( V_77 , V_79 ) ;
if ( ! V_2 -> V_16 . V_76 )
return - V_80 ;
memcpy ( V_2 -> V_16 . V_76 , V_78 , V_77 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
unsigned V_77 ;
void * V_78 ;
if ( V_2 -> V_16 . V_59 == NULL )
return - V_42 ;
V_77 = F_30 ( V_2 -> V_16 . V_59 ) ;
V_78 = V_2 -> V_16 . V_61 ;
if ( V_2 -> V_16 . V_76 != NULL ) {
memcpy ( V_78 , V_2 -> V_16 . V_76 , V_77 ) ;
F_22 ( V_2 -> V_16 . V_76 ) ;
V_2 -> V_16 . V_76 = NULL ;
} else {
const struct V_9 * V_10 ;
unsigned V_81 ;
V_10 = ( const struct V_9 * ) V_2 -> V_16 . V_43 -> V_47 ;
V_81 = F_8 ( V_10 -> V_82 ) ;
memcpy ( V_2 -> V_16 . V_61 , ( V_2 -> V_16 . V_43 -> V_47 ) + V_81 ,
( V_2 -> V_16 . V_43 -> V_77 ) - V_81 ) ;
V_77 -= F_8 ( V_10 -> V_52 ) ;
V_78 += F_8 ( V_10 -> V_52 ) ;
memset ( V_78 , 0 , V_77 ) ;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 , struct V_83 * V_68 )
{
struct V_3 * V_4 = & V_2 -> V_16 . V_4 ;
int V_14 , V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
T_1 V_84 = F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) ;
if ( V_84 != 0 && V_2 -> V_16 . V_68 [ V_14 ] == V_68 ) {
struct V_85 * V_85 ;
V_15 = F_34 ( V_4 , V_84 ,
false , & V_85 ) ;
if ( V_15 ) {
F_10 ( L_10 , V_15 ) ;
continue;
}
F_35 ( V_85 , false ) ;
F_36 ( V_85 ) ;
V_2 -> V_16 . V_68 [ V_14 ] = NULL ;
F_19 ( & V_2 -> V_16 . V_67 [ V_14 ] , 0 ) ;
}
}
}
static void F_37 ( struct V_86 * V_87 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_87 -> V_88 . V_89 ; ++ V_14 ) {
V_87 -> V_90 [ V_14 ] . V_91 = 0 >> V_92 ;
V_87 -> V_90 [ V_14 ] . V_93 = ( 256 * 1024 * 1024 ) >> V_92 ;
}
}
static int F_38 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
struct V_86 * V_98 ;
T_1 V_99 , V_100 , V_101 ;
T_2 V_102 ;
int V_15 = 0 ;
V_100 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_105 ) ;
V_101 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_106 ) ;
V_102 = ( ( T_2 ) V_100 ) | ( ( ( T_2 ) V_101 ) << 32 ) ;
V_97 = F_40 ( V_95 -> V_103 , V_102 , & V_98 ) ;
if ( V_97 == NULL ) {
F_10 ( L_11 , V_102 ) ;
return - V_42 ;
}
if ( ! V_95 -> V_103 -> V_2 -> V_16 . V_70 ) {
V_99 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_107 ) >> 1 ;
if ( V_99 == 0x0 || V_99 == 0x3 ) {
T_1 V_108 = V_57 ;
F_41 ( V_98 , V_108 ) ;
}
F_37 ( V_98 ) ;
V_15 = F_42 ( & V_98 -> V_109 , & V_98 -> V_88 , false , false ) ;
}
return V_15 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 * V_110 ,
unsigned V_111 [] )
{
unsigned V_112 = V_110 [ 4 ] ;
unsigned V_113 = V_110 [ 6 ] ;
unsigned V_114 = V_110 [ 7 ] ;
unsigned V_115 = V_110 [ 9 ] ;
unsigned V_116 = V_110 [ 28 ] ;
unsigned V_117 = V_110 [ 57 ] ;
unsigned V_118 = V_113 / 16 ;
unsigned V_119 = F_44 ( V_114 / 16 , 2 ) ;
unsigned V_120 = V_118 * V_119 ;
unsigned V_121 , V_122 , V_123 , V_124 ;
unsigned V_125 = ~ 0 ;
V_121 = V_113 * V_114 ;
V_121 += V_121 / 2 ;
V_121 = F_44 ( V_121 , 1024 ) ;
switch ( V_112 ) {
case 0 :
switch( V_117 ) {
case 30 :
V_124 = 8100 / V_120 ;
break;
case 31 :
V_124 = 18000 / V_120 ;
break;
case 32 :
V_124 = 20480 / V_120 ;
break;
case 41 :
V_124 = 32768 / V_120 ;
break;
case 42 :
V_124 = 34816 / V_120 ;
break;
case 50 :
V_124 = 110400 / V_120 ;
break;
case 51 :
V_124 = 184320 / V_120 ;
break;
default:
V_124 = 184320 / V_120 ;
break;
}
V_124 ++ ;
if ( V_124 > 17 )
V_124 = 17 ;
V_123 = V_121 * V_124 ;
V_123 += V_118 * V_119 * V_124 * 192 ;
V_123 += V_118 * V_119 * 32 ;
break;
case 1 :
V_123 = V_121 * 3 ;
V_123 += V_118 * V_119 * 128 ;
V_123 += V_118 * 64 ;
V_123 += V_118 * 128 ;
V_122 = F_45 ( V_118 , V_119 ) ;
V_123 += F_44 ( V_122 * 7 * 16 , 64 ) ;
break;
case 3 :
V_123 = V_121 * 3 ;
break;
case 4 :
V_123 = V_121 * 3 ;
V_123 += V_118 * V_119 * 64 ;
V_123 += F_44 ( V_118 * V_119 * 32 , 64 ) ;
break;
case 7 :
switch( V_117 ) {
case 30 :
V_124 = 8100 / V_120 ;
break;
case 31 :
V_124 = 18000 / V_120 ;
break;
case 32 :
V_124 = 20480 / V_120 ;
break;
case 41 :
V_124 = 32768 / V_120 ;
break;
case 42 :
V_124 = 34816 / V_120 ;
break;
case 50 :
V_124 = 110400 / V_120 ;
break;
case 51 :
V_124 = 184320 / V_120 ;
break;
default:
V_124 = 184320 / V_120 ;
break;
}
V_124 ++ ;
if ( V_124 > 17 )
V_124 = 17 ;
V_123 = V_121 * V_124 ;
if ( ! V_2 -> V_16 . V_71 ) {
V_123 +=
V_118 * V_119 * V_124 * 192 ;
V_123 += V_118 * V_119 * 32 ;
} else {
V_125 =
V_118 * V_119 * V_124 * 192 ;
}
break;
case 16 :
V_121 = ( F_44 ( V_113 , 16 ) * F_44 ( V_114 , 16 ) * 3 ) / 2 ;
V_121 = F_44 ( V_121 , 256 ) ;
V_124 = ( F_8 ( V_110 [ 59 ] ) & 0xff ) + 2 ;
V_123 = V_121 * V_124 ;
V_125 = ( ( V_113 + 255 ) / 16 ) * ( ( V_114 + 255 ) / 16 )
* 16 * V_124 + 52 * 1024 ;
break;
default:
F_10 ( L_12 , V_112 ) ;
return - V_42 ;
}
if ( V_113 > V_116 ) {
F_10 ( L_13 ) ;
return - V_42 ;
}
if ( V_115 < V_123 ) {
F_10 ( L_14 ,
V_115 , V_123 ) ;
return - V_42 ;
}
V_111 [ 0x1 ] = V_115 ;
V_111 [ 0x2 ] = V_121 ;
V_111 [ 0x4 ] = V_125 ;
return 0 ;
}
static int F_46 ( struct V_94 * V_95 ,
struct V_86 * V_98 , unsigned V_81 )
{
struct V_1 * V_2 = V_95 -> V_103 -> V_2 ;
T_3 * V_110 , V_126 , V_84 ;
void * V_78 ;
long V_15 ;
int V_14 ;
if ( V_81 & 0x3F ) {
F_10 ( L_15 ) ;
return - V_42 ;
}
V_15 = F_17 ( V_98 , & V_78 ) ;
if ( V_15 ) {
F_10 ( L_16 , V_15 ) ;
return V_15 ;
}
V_110 = V_78 + V_81 ;
V_126 = V_110 [ 1 ] ;
V_84 = V_110 [ 2 ] ;
if ( V_84 == 0 ) {
F_10 ( L_17 ) ;
return - V_42 ;
}
switch ( V_126 ) {
case 0 :
F_24 ( V_98 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) == V_84 ) {
F_10 ( L_18 , V_84 ) ;
return - V_42 ;
}
if ( ! F_47 ( & V_2 -> V_16 . V_67 [ V_14 ] , 0 , V_84 ) ) {
V_2 -> V_16 . V_68 [ V_14 ] = V_95 -> V_103 -> V_68 ;
return 0 ;
}
}
F_10 ( L_19 ) ;
return - V_127 ;
case 1 :
V_15 = F_43 ( V_2 , V_110 , V_95 -> V_111 ) ;
F_24 ( V_98 ) ;
if ( V_15 )
return V_15 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 ) {
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) == V_84 ) {
if ( V_2 -> V_16 . V_68 [ V_14 ] != V_95 -> V_103 -> V_68 ) {
F_10 ( L_20 ) ;
return - V_42 ;
}
return 0 ;
}
}
F_10 ( L_21 , V_84 ) ;
return - V_128 ;
case 2 :
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
F_47 ( & V_2 -> V_16 . V_67 [ V_14 ] , V_84 , 0 ) ;
F_24 ( V_98 ) ;
return 0 ;
default:
F_10 ( L_22 , V_126 ) ;
return - V_42 ;
}
F_48 () ;
return - V_42 ;
}
static int F_49 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
struct V_86 * V_98 ;
T_1 V_99 , V_100 , V_101 ;
T_2 V_129 , V_130 ;
T_2 V_102 ;
int V_15 ;
V_100 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_105 ) ;
V_101 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_106 ) ;
V_102 = ( ( T_2 ) V_100 ) | ( ( ( T_2 ) V_101 ) << 32 ) ;
V_97 = F_40 ( V_95 -> V_103 , V_102 , & V_98 ) ;
if ( V_97 == NULL )
return - V_42 ;
V_129 = F_50 ( V_98 ) ;
V_130 = ( V_97 -> V_131 . V_132 + 1 - V_97 -> V_131 . V_129 ) ;
V_130 = V_130 * V_133 + V_129 ;
V_102 -= ( ( T_2 ) V_97 -> V_131 . V_129 ) * V_133 ;
V_129 += V_102 ;
F_51 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_105 ,
F_52 ( V_129 ) ) ;
F_51 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_106 ,
F_53 ( V_129 ) ) ;
V_99 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_107 ) >> 1 ;
if ( V_99 < 0x4 ) {
if ( ( V_130 - V_129 ) < V_95 -> V_111 [ V_99 ] ) {
F_10 ( L_23 , V_99 ,
( unsigned ) ( V_130 - V_129 ) ,
V_95 -> V_111 [ V_99 ] ) ;
return - V_42 ;
}
} else if ( V_99 == 0x206 ) {
if ( ( V_130 - V_129 ) < V_95 -> V_111 [ 4 ] ) {
F_10 ( L_23 , V_99 ,
( unsigned ) ( V_130 - V_129 ) ,
V_95 -> V_111 [ 4 ] ) ;
return - V_42 ;
}
} else if ( ( V_99 != 0x100 ) && ( V_99 != 0x204 ) ) {
F_10 ( L_24 , V_99 ) ;
return - V_42 ;
}
if ( ! V_95 -> V_103 -> V_2 -> V_16 . V_70 ) {
if ( ( V_129 >> 28 ) != ( ( V_130 - 1 ) >> 28 ) ) {
F_10 ( L_25 ,
V_129 , V_130 ) ;
return - V_42 ;
}
if ( ( V_99 == 0 || V_99 == 0x3 ) &&
( V_129 >> 28 ) != ( V_95 -> V_103 -> V_2 -> V_16 . V_60 >> 28 ) ) {
F_10 ( L_26 ,
V_129 , V_130 ) ;
return - V_42 ;
}
}
if ( V_99 == 0 ) {
V_95 -> V_134 = true ;
V_15 = F_46 ( V_95 , V_98 , V_102 ) ;
if ( V_15 )
return V_15 ;
} else if ( ! V_95 -> V_134 ) {
F_10 ( L_27 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_54 ( struct V_94 * V_95 ,
int (* F_55)( struct V_94 * V_95 ) )
{
struct V_135 * V_136 = & V_95 -> V_103 -> V_137 -> V_138 [ V_95 -> V_104 ] ;
int V_14 , V_15 ;
V_95 -> V_107 ++ ;
for ( V_14 = 0 ; V_14 <= V_95 -> V_139 ; ++ V_14 ) {
unsigned V_140 = V_95 -> V_140 + V_14 ;
if ( V_95 -> V_107 >= V_136 -> V_141 ) {
F_10 ( L_28 ) ;
return - V_42 ;
}
switch ( V_140 ) {
case V_142 :
V_95 -> V_105 = V_95 -> V_107 ;
break;
case V_143 :
V_95 -> V_106 = V_95 -> V_107 ;
break;
case V_144 :
V_15 = F_55 ( V_95 ) ;
if ( V_15 )
return V_15 ;
break;
case V_145 :
break;
default:
F_10 ( L_29 , V_140 ) ;
return - V_42 ;
}
V_95 -> V_107 ++ ;
}
return 0 ;
}
static int F_56 ( struct V_94 * V_95 ,
int (* F_55)( struct V_94 * V_95 ) )
{
struct V_135 * V_136 = & V_95 -> V_103 -> V_137 -> V_138 [ V_95 -> V_104 ] ;
int V_15 ;
for ( V_95 -> V_107 = 0 ; V_95 -> V_107 < V_136 -> V_141 ; ) {
T_1 V_99 = F_39 ( V_95 -> V_103 , V_95 -> V_104 , V_95 -> V_107 ) ;
unsigned type = F_57 ( V_99 ) ;
switch ( type ) {
case V_146 :
V_95 -> V_140 = F_58 ( V_99 ) ;
V_95 -> V_139 = F_59 ( V_99 ) ;
V_15 = F_54 ( V_95 , F_55 ) ;
if ( V_15 )
return V_15 ;
break;
case V_147 :
++ V_95 -> V_107 ;
break;
default:
F_10 ( L_30 , type ) ;
return - V_42 ;
}
}
return 0 ;
}
int F_60 ( struct V_148 * V_103 , T_1 V_104 )
{
struct V_94 V_95 = {} ;
unsigned V_111 [] = {
[ 0x00000000 ] = 2048 ,
[ 0x00000001 ] = 0xFFFFFFFF ,
[ 0x00000002 ] = 0xFFFFFFFF ,
[ 0x00000003 ] = 2048 ,
[ 0x00000004 ] = 0xFFFFFFFF ,
} ;
struct V_135 * V_136 = & V_103 -> V_137 -> V_138 [ V_104 ] ;
int V_15 ;
if ( V_136 -> V_141 % 16 ) {
F_10 ( L_31 ,
V_136 -> V_141 ) ;
return - V_42 ;
}
V_95 . V_103 = V_103 ;
V_95 . V_111 = V_111 ;
V_95 . V_104 = V_104 ;
V_15 = F_56 ( & V_95 , F_38 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_56 ( & V_95 , F_49 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_95 . V_134 ) {
F_10 ( L_32 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_61 ( struct V_3 * V_4 , struct V_86 * V_98 ,
bool V_149 , struct V_85 * * V_85 )
{
struct V_150 V_151 ;
struct V_152 V_153 ;
struct V_154 V_155 ;
struct V_156 * V_137 ;
struct V_135 * V_136 ;
struct V_85 * V_157 = NULL ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_102 ;
int V_14 , V_15 ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_98 = & V_98 -> V_109 ;
F_62 ( & V_155 ) ;
F_63 ( & V_151 . V_155 , & V_155 ) ;
V_15 = F_64 ( & V_153 , & V_155 , true , NULL ) ;
if ( V_15 )
return V_15 ;
if ( ! V_98 -> V_2 -> V_16 . V_70 ) {
F_41 ( V_98 , V_57 ) ;
F_37 ( V_98 ) ;
}
V_15 = F_42 ( & V_98 -> V_109 , & V_98 -> V_88 , true , false ) ;
if ( V_15 )
goto V_158;
V_15 = F_65 ( V_2 , 64 , & V_137 ) ;
if ( V_15 )
goto V_158;
V_136 = & V_137 -> V_138 [ 0 ] ;
V_102 = F_50 ( V_98 ) ;
V_136 -> V_78 [ 0 ] = F_66 ( V_142 , 0 ) ;
V_136 -> V_78 [ 1 ] = V_102 ;
V_136 -> V_78 [ 2 ] = F_66 ( V_143 , 0 ) ;
V_136 -> V_78 [ 3 ] = V_102 >> 32 ;
V_136 -> V_78 [ 4 ] = F_66 ( V_144 , 0 ) ;
V_136 -> V_78 [ 5 ] = 0 ;
for ( V_14 = 6 ; V_14 < 16 ; ++ V_14 )
V_136 -> V_78 [ V_14 ] = F_67 ( 0 ) ;
V_136 -> V_141 = 16 ;
if ( V_149 ) {
V_15 = F_68 ( V_4 , 1 , V_136 , NULL , NULL , & V_157 ) ;
V_137 -> V_85 = F_69 ( V_157 ) ;
if ( V_15 )
goto V_159;
F_70 ( V_137 ) ;
} else {
V_15 = F_71 ( V_137 , V_4 , & V_2 -> V_16 . V_65 ,
V_160 , & V_157 ) ;
if ( V_15 )
goto V_159;
}
F_72 ( & V_153 , & V_155 , V_157 ) ;
if ( V_85 )
* V_85 = F_69 ( V_157 ) ;
F_14 ( & V_98 ) ;
F_36 ( V_157 ) ;
return 0 ;
V_159:
F_70 ( V_137 ) ;
V_158:
F_73 ( & V_153 , & V_155 ) ;
return V_15 ;
}
int F_74 ( struct V_3 * V_4 , T_1 V_84 ,
struct V_85 * * V_85 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_86 * V_98 ;
T_1 * V_110 ;
int V_15 , V_14 ;
V_15 = F_12 ( V_2 , 1024 , V_56 , true ,
V_57 ,
V_58 ,
NULL , NULL , & V_98 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_98 , false ) ;
if ( V_15 ) {
F_14 ( & V_98 ) ;
return V_15 ;
}
V_15 = F_17 ( V_98 , ( void * * ) & V_110 ) ;
if ( V_15 ) {
F_16 ( V_98 ) ;
F_14 ( & V_98 ) ;
return V_15 ;
}
V_110 [ 0 ] = F_75 ( 0x00000de4 ) ;
V_110 [ 1 ] = F_75 ( 0x00000000 ) ;
V_110 [ 2 ] = F_75 ( V_84 ) ;
V_110 [ 3 ] = F_75 ( 0x00000000 ) ;
V_110 [ 4 ] = F_75 ( 0x00000000 ) ;
V_110 [ 5 ] = F_75 ( 0x00000000 ) ;
V_110 [ 6 ] = F_75 ( 0x00000000 ) ;
V_110 [ 7 ] = F_75 ( 0x00000780 ) ;
V_110 [ 8 ] = F_75 ( 0x00000440 ) ;
V_110 [ 9 ] = F_75 ( 0x00000000 ) ;
V_110 [ 10 ] = F_75 ( 0x01b37000 ) ;
for ( V_14 = 11 ; V_14 < 1024 ; ++ V_14 )
V_110 [ V_14 ] = F_75 ( 0x0 ) ;
F_24 ( V_98 ) ;
F_16 ( V_98 ) ;
return F_61 ( V_4 , V_98 , true , V_85 ) ;
}
int F_34 ( struct V_3 * V_4 , T_1 V_84 ,
bool V_149 , struct V_85 * * V_85 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_86 * V_98 ;
T_1 * V_110 ;
int V_15 , V_14 ;
V_15 = F_12 ( V_2 , 1024 , V_56 , true ,
V_57 ,
V_58 ,
NULL , NULL , & V_98 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_98 , false ) ;
if ( V_15 ) {
F_14 ( & V_98 ) ;
return V_15 ;
}
V_15 = F_17 ( V_98 , ( void * * ) & V_110 ) ;
if ( V_15 ) {
F_16 ( V_98 ) ;
F_14 ( & V_98 ) ;
return V_15 ;
}
V_110 [ 0 ] = F_75 ( 0x00000de4 ) ;
V_110 [ 1 ] = F_75 ( 0x00000002 ) ;
V_110 [ 2 ] = F_75 ( V_84 ) ;
V_110 [ 3 ] = F_75 ( 0x00000000 ) ;
for ( V_14 = 4 ; V_14 < 1024 ; ++ V_14 )
V_110 [ V_14 ] = F_75 ( 0x0 ) ;
F_24 ( V_98 ) ;
F_16 ( V_98 ) ;
return F_61 ( V_4 , V_98 , V_149 , V_85 ) ;
}
static void V_18 ( struct V_161 * V_162 )
{
struct V_1 * V_2 =
F_76 ( V_162 , struct V_1 , V_16 . V_17 . V_162 ) ;
unsigned V_14 , V_163 , V_67 = 0 ;
V_163 = F_77 ( & V_2 -> V_16 . V_4 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_45 ; ++ V_14 )
if ( F_28 ( & V_2 -> V_16 . V_67 [ V_14 ] ) )
++ V_67 ;
if ( V_163 == 0 && V_67 == 0 ) {
if ( V_2 -> V_164 . V_165 ) {
F_78 ( V_2 , false ) ;
} else {
F_79 ( V_2 , 0 , 0 ) ;
}
} else {
F_80 ( & V_2 -> V_16 . V_17 , V_166 ) ;
}
}
void F_81 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
bool V_167 = ! F_29 ( & V_2 -> V_16 . V_17 ) ;
if ( V_167 ) {
if ( V_2 -> V_164 . V_165 ) {
F_78 ( V_2 , true ) ;
} else {
F_79 ( V_2 , 53300 , 40000 ) ;
}
}
}
void F_82 ( struct V_3 * V_4 )
{
F_80 ( & V_4 -> V_2 -> V_16 . V_17 , V_166 ) ;
}
int F_83 ( struct V_3 * V_4 , long V_168 )
{
struct V_85 * V_85 ;
long V_15 ;
V_15 = F_74 ( V_4 , 1 , NULL ) ;
if ( V_15 ) {
F_10 ( L_33 , V_15 ) ;
goto error;
}
V_15 = F_34 ( V_4 , 1 , true , & V_85 ) ;
if ( V_15 ) {
F_10 ( L_34 , V_15 ) ;
goto error;
}
V_15 = F_84 ( V_85 , false , V_168 ) ;
if ( V_15 == 0 ) {
F_10 ( L_35 ) ;
V_15 = - V_169 ;
} else if ( V_15 < 0 ) {
F_10 ( L_36 , V_15 ) ;
} else {
F_9 ( L_37 , V_4 -> V_107 ) ;
V_15 = 0 ;
}
F_36 ( V_85 ) ;
error:
return V_15 ;
}
