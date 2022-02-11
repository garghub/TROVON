static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 * V_10 = V_9 -> V_11 ;
if ( V_1 > 15 ) {
F_2 ( L_1 , V_1 ) ;
return 1 ;
}
switch ( V_9 -> V_12 ) {
case 24 :
case 32 :
V_10 [ V_1 ] = ( ( V_2 & 0xff00 ) << 8 ) |
( V_3 & 0xff00 ) |
( ( V_4 & 0xff00 ) >> 8 ) ;
break;
default:
F_2 ( L_2 , V_9 -> V_12 , V_9 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_6 * V_7 )
{
int V_12 = V_15 -> V_16 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_18 ;
switch ( V_15 -> V_16 ) {
case 32 :
V_12 = ( V_15 -> V_5 . V_19 > 0 ) ? 32 : 24 ;
break;
default:
F_2 ( L_3 , V_15 -> V_16 ) ;
return - V_20 ;
}
switch ( V_12 ) {
case 24 :
V_15 -> V_2 . V_21 = 16 ;
V_15 -> V_3 . V_21 = 8 ;
V_15 -> V_4 . V_21 = 0 ;
V_15 -> V_2 . V_19 = 8 ;
V_15 -> V_3 . V_19 = 8 ;
V_15 -> V_4 . V_19 = 8 ;
V_15 -> V_5 . V_19 = 0 ;
V_15 -> V_5 . V_21 = 0 ;
break;
case 32 :
V_15 -> V_2 . V_21 = 16 ;
V_15 -> V_3 . V_21 = 8 ;
V_15 -> V_4 . V_21 = 0 ;
V_15 -> V_2 . V_19 = 8 ;
V_15 -> V_3 . V_19 = 8 ;
V_15 -> V_4 . V_19 = 8 ;
V_15 -> V_5 . V_19 = 8 ;
V_15 -> V_5 . V_21 = 24 ;
break;
default:
F_2 ( L_4 , V_12 ) ;
return - V_20 ;
}
if ( ! ( V_18 -> V_22 & V_23 ) &&
( V_15 -> V_24 != 0 || V_15 -> V_25 != 0 ) ) {
F_2 ( L_5 ) ;
return - V_20 ;
}
if ( ( V_15 -> V_24 + V_15 -> V_26 ) > V_9 -> V_27 ||
( V_15 -> V_25 + V_15 -> V_28 ) > V_9 -> V_29 ) {
F_2 ( L_6 ) ;
return - V_20 ;
}
if ( ! F_4 ( V_18 ,
V_7 -> V_30 . V_31 ,
V_15 -> V_25 + V_15 -> V_28 ) ) {
F_2 ( L_6 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_18 ;
F_6 ( V_18 , V_7 -> V_15 . V_26 , V_7 -> V_15 . V_28 ,
V_7 -> V_30 . V_31 ,
V_9 -> V_13 , V_9 -> V_12 ) ;
if ( V_18 -> V_22 & V_23 ) {
F_7 ( V_18 , V_32 , 1 ) ;
F_7 ( V_18 , V_33 , 0 ) ;
F_7 ( V_18 , V_34 , true ) ;
F_7 ( V_18 , V_35 , V_7 -> V_15 . V_24 ) ;
F_7 ( V_18 , V_36 , V_7 -> V_15 . V_25 ) ;
F_7 ( V_18 , V_37 , V_7 -> V_15 . V_26 ) ;
F_7 ( V_18 , V_38 , V_7 -> V_15 . V_28 ) ;
F_7 ( V_18 , V_33 , V_39 ) ;
}
F_8 ( F_9 ( V_18 , V_40 ) != 0 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_6 * V_7 )
{
return 0 ;
}
static int F_11 ( int V_41 , struct V_6 * V_7 )
{
return 0 ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = V_9 -> V_18 ;
struct V_6 * V_7 = V_18 -> V_6 ;
int V_42 = ( V_7 -> V_30 . V_31 / 4 ) ;
int * V_43 = ( int * ) V_7 -> V_44 ;
T_2 T_3 * V_45 = V_9 -> V_46 ;
unsigned long V_47 ;
unsigned V_48 , V_49 , V_50 , V_51 ;
int V_52 , V_53 ;
struct {
T_4 V_54 ;
T_5 V_55 ;
} * V_56 ;
if ( V_18 -> V_57 )
return;
F_13 ( & V_9 -> V_58 . V_59 , V_47 ) ;
if ( ! V_9 -> V_58 . V_60 ) {
F_14 ( & V_9 -> V_58 . V_59 , V_47 ) ;
return;
}
V_48 = V_9 -> V_58 . V_61 ;
V_49 = V_9 -> V_58 . y1 ;
V_50 = F_15 ( V_9 -> V_58 . V_62 , V_7 -> V_15 . V_26 ) - V_48 ;
V_51 = F_15 ( V_9 -> V_58 . V_63 , V_7 -> V_15 . V_28 ) - V_49 ;
V_9 -> V_58 . V_61 = V_9 -> V_58 . V_62 = 0 ;
V_9 -> V_58 . y1 = V_9 -> V_58 . V_63 = 0 ;
F_14 ( & V_9 -> V_58 . V_59 , V_47 ) ;
for ( V_52 = V_49 * V_42 ; V_52 < V_7 -> V_30 . V_64 / 4 ; V_52 += V_42 ) {
for ( V_53 = V_52 + V_48 ; V_53 < V_52 + V_48 + V_50 && V_53 < V_7 -> V_30 . V_64 / 4 ; V_53 ++ )
F_16 ( V_43 [ V_53 ] , V_45 + V_53 ) ;
}
#if 0
DRM_INFO("%s, (%u, %u) (%ux%u)\n", __func__, x, y, w, h);
#endif
V_56 = F_17 ( V_18 , sizeof( * V_56 ) ) ;
if ( F_18 ( V_56 == NULL ) ) {
F_2 ( L_7 ) ;
return;
}
V_56 -> V_54 = F_19 ( V_65 ) ;
V_56 -> V_55 . V_48 = F_19 ( V_48 ) ;
V_56 -> V_55 . V_49 = F_19 ( V_49 ) ;
V_56 -> V_55 . V_66 = F_19 ( V_50 ) ;
V_56 -> V_55 . V_67 = F_19 ( V_51 ) ;
F_20 ( V_18 , sizeof( * V_56 ) ) ;
}
static void F_21 ( struct V_8 * V_9 ,
unsigned V_61 , unsigned y1 ,
unsigned V_66 , unsigned V_67 )
{
struct V_6 * V_7 = V_9 -> V_18 -> V_6 ;
unsigned long V_47 ;
unsigned V_62 = V_61 + V_66 ;
unsigned V_63 = y1 + V_67 ;
F_13 ( & V_9 -> V_58 . V_59 , V_47 ) ;
if ( V_9 -> V_58 . V_61 == V_9 -> V_58 . V_62 ) {
V_9 -> V_58 . V_61 = V_61 ;
V_9 -> V_58 . y1 = y1 ;
V_9 -> V_58 . V_62 = V_62 ;
V_9 -> V_58 . V_63 = V_63 ;
if ( V_9 -> V_58 . V_60 )
F_22 ( & V_7 -> V_68 , V_69 ) ;
} else {
if ( V_61 < V_9 -> V_58 . V_61 )
V_9 -> V_58 . V_61 = V_61 ;
if ( y1 < V_9 -> V_58 . y1 )
V_9 -> V_58 . y1 = y1 ;
if ( V_62 > V_9 -> V_58 . V_62 )
V_9 -> V_58 . V_62 = V_62 ;
if ( V_63 > V_9 -> V_58 . V_63 )
V_9 -> V_58 . V_63 = V_63 ;
}
F_14 ( & V_9 -> V_58 . V_59 , V_47 ) ;
}
static void F_23 ( struct V_6 * V_7 ,
struct V_70 * V_71 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_72 , V_73 , F_15 , V_74 ;
unsigned long V_47 ;
struct V_75 * V_75 ;
int y1 , V_63 ;
F_15 = V_76 ;
V_74 = 0 ;
F_24 (page, pagelist, lru) {
V_72 = V_75 -> V_77 << V_78 ;
V_73 = V_72 + V_79 - 1 ;
F_15 = F_15 ( F_15 , V_72 ) ;
V_74 = V_74 ( V_74 , V_73 ) ;
}
if ( F_15 < V_74 ) {
y1 = F_15 / V_7 -> V_30 . V_31 ;
V_63 = ( V_74 / V_7 -> V_30 . V_31 ) + 1 ;
F_13 ( & V_9 -> V_58 . V_59 , V_47 ) ;
V_9 -> V_58 . V_61 = 0 ;
V_9 -> V_58 . y1 = y1 ;
V_9 -> V_58 . V_62 = V_7 -> V_15 . V_26 ;
V_9 -> V_58 . V_63 = V_63 ;
F_14 ( & V_9 -> V_58 . V_59 , V_47 ) ;
}
F_12 ( V_9 ) ;
}
static void F_25 ( struct V_6 * V_7 , const struct V_80 * V_81 )
{
F_26 ( V_7 , V_81 ) ;
F_21 ( V_7 -> V_9 , V_81 -> V_82 , V_81 -> V_83 ,
V_81 -> V_66 , V_81 -> V_67 ) ;
}
static void F_27 ( struct V_6 * V_7 , const struct V_84 * V_85 )
{
F_28 ( V_7 , V_85 ) ;
F_21 ( V_7 -> V_9 , V_85 -> V_82 , V_85 -> V_83 ,
V_85 -> V_66 , V_85 -> V_67 ) ;
}
static void F_29 ( struct V_6 * V_7 , const struct V_86 * V_87 )
{
F_30 ( V_7 , V_87 ) ;
F_21 ( V_7 -> V_9 , V_87 -> V_82 , V_87 -> V_83 ,
V_87 -> V_66 , V_87 -> V_67 ) ;
}
static int F_31 ( struct V_17 * V_18 ,
T_6 V_88 , struct V_89 * * V_90 )
{
struct V_89 * V_91 ;
struct V_92 V_93 = V_94 ;
int V_95 ;
V_93 . V_96 = ( V_88 + V_79 - 1 ) >> V_78 ;
V_95 = F_32 ( & V_18 -> V_97 . V_59 , false ) ;
if ( F_18 ( V_95 != 0 ) )
return V_95 ;
V_91 = F_33 ( sizeof( * V_91 ) , V_98 ) ;
if ( ! V_91 )
goto V_99;
V_95 = F_34 ( V_18 , V_91 , V_88 ,
& V_93 ,
false ,
& V_100 ) ;
if ( F_18 ( V_95 != 0 ) )
goto V_99;
* V_90 = V_91 ;
F_35 ( & V_18 -> V_97 . V_59 ) ;
return 0 ;
V_99:
F_35 ( & V_18 -> V_97 . V_59 ) ;
return V_95 ;
}
int F_36 ( struct V_17 * V_18 )
{
struct V_101 * V_101 = & V_18 -> V_102 -> V_103 -> V_102 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
unsigned V_104 , V_105 ;
unsigned V_106 , V_107 ;
unsigned V_108 , V_109 , V_110 , V_111 , V_112 ;
int V_95 ;
V_104 = 800 ;
V_105 = 600 ;
V_108 = 32 ;
V_109 = 24 ;
V_106 = F_15 ( V_18 -> V_113 , ( unsigned ) 2048 ) ;
V_107 = F_15 ( V_18 -> V_114 , ( unsigned ) 2048 ) ;
V_104 = F_15 ( V_106 , V_104 ) ;
V_105 = F_15 ( V_107 , V_105 ) ;
V_111 = V_106 * V_108 / 8 ;
V_112 = V_111 * V_107 ;
V_110 = F_9 ( V_18 , V_40 ) ;
V_7 = F_37 ( sizeof( * V_9 ) , V_101 ) ;
if ( ! V_7 )
return - V_115 ;
V_18 -> V_6 = V_7 ;
V_9 = V_7 -> V_9 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_12 = V_109 ;
V_9 -> V_13 = V_108 ;
V_9 -> V_116 = NULL ;
V_9 -> V_27 = V_106 ;
V_9 -> V_29 = V_107 ;
V_9 -> V_116 = V_116 ( V_112 ) ;
if ( F_18 ( V_9 -> V_116 == NULL ) ) {
V_95 = - V_115 ;
goto V_117;
}
V_95 = F_31 ( V_18 , V_112 , & V_9 -> V_91 ) ;
if ( F_18 ( V_95 != 0 ) )
goto V_117;
V_95 = F_38 ( & V_9 -> V_91 -> V_118 ,
0 ,
V_9 -> V_91 -> V_118 . V_119 ,
& V_9 -> V_120 ) ;
if ( F_18 ( V_95 != 0 ) )
goto V_121;
V_9 -> V_46 = F_39 ( & V_9 -> V_120 , & V_9 -> V_122 ) ;
V_9 -> V_123 = V_112 ;
strcpy ( V_7 -> V_30 . V_124 , L_8 ) ;
V_7 -> V_30 . type = V_125 ;
V_7 -> V_30 . V_126 = V_127 ;
V_7 -> V_30 . V_128 = 0 ;
V_7 -> V_30 . V_129 = 1 ;
V_7 -> V_30 . V_130 = 1 ;
V_7 -> V_30 . V_131 = 0 ;
V_7 -> V_30 . V_132 = V_133 ;
V_7 -> V_30 . V_31 = V_111 ;
V_7 -> V_30 . V_134 = 0 ;
V_7 -> V_30 . V_64 = V_112 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_44 = V_9 -> V_116 ;
V_7 -> V_135 = V_112 ;
V_7 -> V_47 = V_136 ;
V_7 -> V_137 = & V_138 ;
V_7 -> V_15 . V_2 . V_21 = 16 ;
V_7 -> V_15 . V_3 . V_21 = 8 ;
V_7 -> V_15 . V_4 . V_21 = 0 ;
V_7 -> V_15 . V_2 . V_19 = 8 ;
V_7 -> V_15 . V_3 . V_19 = 8 ;
V_7 -> V_15 . V_4 . V_19 = 8 ;
V_7 -> V_15 . V_5 . V_21 = 0 ;
V_7 -> V_15 . V_5 . V_19 = 0 ;
V_7 -> V_15 . V_139 = V_106 ;
V_7 -> V_15 . V_140 = V_107 ;
V_7 -> V_15 . V_16 = V_9 -> V_13 ;
V_7 -> V_15 . V_24 = 0 ;
V_7 -> V_15 . V_25 = 0 ;
V_7 -> V_15 . V_141 = V_142 ;
V_7 -> V_15 . V_67 = - 1 ;
V_7 -> V_15 . V_66 = - 1 ;
V_7 -> V_15 . V_26 = V_104 ;
V_7 -> V_15 . V_28 = V_105 ;
#if 0
info->pixmap.size = 64*1024;
info->pixmap.buf_align = 8;
info->pixmap.access_align = 32;
info->pixmap.flags = FB_PIXMAP_SYSTEM;
info->pixmap.scan_align = 1;
#else
V_7 -> V_143 . V_88 = 0 ;
V_7 -> V_143 . V_144 = 8 ;
V_7 -> V_143 . V_145 = 32 ;
V_7 -> V_143 . V_47 = V_146 ;
V_7 -> V_143 . V_147 = 1 ;
#endif
V_7 -> V_148 = F_40 ( 1 ) ;
if ( ! V_7 -> V_148 ) {
V_95 = - V_115 ;
goto V_149;
}
V_7 -> V_148 -> V_150 [ 0 ] . V_118 = V_18 -> V_151 ;
V_7 -> V_148 -> V_150 [ 0 ] . V_88 = V_18 -> V_152 ;
V_9 -> V_58 . V_61 = V_9 -> V_58 . V_62 = 0 ;
V_9 -> V_58 . y1 = V_9 -> V_58 . V_63 = 0 ;
V_9 -> V_58 . V_60 = true ;
F_41 ( & V_9 -> V_58 . V_59 ) ;
V_7 -> V_153 = & V_154 ;
F_42 ( V_7 ) ;
V_95 = F_43 ( V_7 ) ;
if ( F_18 ( V_95 != 0 ) )
goto V_155;
return 0 ;
V_155:
F_44 ( V_7 ) ;
V_149:
F_45 ( & V_9 -> V_120 ) ;
V_121:
F_46 ( (struct V_156 * * ) & V_9 -> V_91 ) ;
V_117:
F_47 ( V_9 -> V_116 ) ;
F_48 ( V_7 ) ;
V_18 -> V_6 = NULL ;
return V_95 ;
}
int F_49 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_156 * V_157 ;
if ( ! V_18 -> V_6 )
return 0 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
V_157 = & V_9 -> V_91 -> V_118 ;
V_9 -> V_91 = NULL ;
F_44 ( V_7 ) ;
F_50 ( V_7 ) ;
F_45 ( & V_9 -> V_120 ) ;
F_46 ( & V_157 ) ;
F_47 ( V_9 -> V_116 ) ;
F_48 ( V_7 ) ;
return 0 ;
}
int F_51 ( struct V_17 * V_18 ,
struct V_89 * V_91 )
{
struct V_156 * V_157 = & V_91 -> V_118 ;
int V_95 = 0 ;
V_95 = F_52 ( V_157 , false , false , false , 0 ) ;
if ( F_18 ( V_95 != 0 ) )
return V_95 ;
V_95 = F_53 ( V_157 , & V_158 , false , false , false ) ;
F_54 ( V_157 ) ;
return V_95 ;
}
int F_55 ( struct V_17 * V_18 ,
struct V_89 * V_91 )
{
struct V_156 * V_157 = & V_91 -> V_118 ;
struct V_92 V_93 = V_94 ;
int V_95 = 0 ;
V_93 . V_96 = V_157 -> V_119 ;
V_95 = F_32 ( & V_18 -> V_159 -> V_59 , false ) ;
if ( F_18 ( V_95 != 0 ) )
return V_95 ;
V_95 = F_52 ( V_157 , false , false , false , 0 ) ;
if ( F_18 ( V_95 != 0 ) )
goto V_99;
if ( V_157 -> V_160 . V_161 == V_162 &&
V_157 -> V_160 . V_72 < V_157 -> V_119 &&
V_157 -> V_160 . V_72 > 0 )
( void ) F_53 ( V_157 , & V_158 , false ,
false , false ) ;
V_95 = F_53 ( V_157 , & V_93 , false , false , false ) ;
F_8 ( V_157 -> V_21 != 0 ) ;
F_54 ( V_157 ) ;
V_99:
F_35 ( & V_18 -> V_159 -> V_59 ) ;
return V_95 ;
}
int F_56 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_47 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_13 ( & V_9 -> V_58 . V_59 , V_47 ) ;
V_9 -> V_58 . V_60 = false ;
F_14 ( & V_9 -> V_58 . V_59 , V_47 ) ;
F_57 ( & V_7 -> V_68 ) ;
V_9 -> V_46 = NULL ;
F_45 ( & V_9 -> V_120 ) ;
F_51 ( V_18 , V_9 -> V_91 ) ;
return 0 ;
}
int F_58 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_47 ;
bool V_163 ;
int V_95 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
if ( V_9 -> V_46 != NULL )
return 0 ;
F_59 ( V_18 ) ;
V_95 = F_55 ( V_18 , V_9 -> V_91 ) ;
if ( F_18 ( V_95 != 0 ) ) {
F_2 ( L_9 ) ;
goto V_164;
}
V_95 = F_38 ( & V_9 -> V_91 -> V_118 ,
0 ,
V_9 -> V_91 -> V_118 . V_119 ,
& V_9 -> V_120 ) ;
F_60 ( V_95 != 0 ) ;
V_9 -> V_46 = F_39 ( & V_9 -> V_120 , & V_163 ) ;
F_13 ( & V_9 -> V_58 . V_59 , V_47 ) ;
V_9 -> V_58 . V_60 = true ;
F_14 ( & V_9 -> V_58 . V_59 , V_47 ) ;
V_164:
F_5 ( V_7 ) ;
F_21 ( V_9 , 0 , 0 , V_7 -> V_15 . V_26 , V_7 -> V_15 . V_28 ) ;
F_22 ( & V_7 -> V_68 , 0 ) ;
return 0 ;
}
