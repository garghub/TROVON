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
int V_32 ;
V_32 = F_6 ( V_18 , V_7 -> V_15 . V_26 , V_7 -> V_15 . V_28 ,
V_7 -> V_30 . V_31 ,
V_9 -> V_13 , V_9 -> V_12 ) ;
if ( V_32 )
return V_32 ;
if ( V_18 -> V_22 & V_23 ) {
F_7 ( V_18 , V_33 , 1 ) ;
F_7 ( V_18 , V_34 , 0 ) ;
F_7 ( V_18 , V_35 , true ) ;
F_7 ( V_18 , V_36 , V_7 -> V_15 . V_24 ) ;
F_7 ( V_18 , V_37 , V_7 -> V_15 . V_25 ) ;
F_7 ( V_18 , V_38 , V_7 -> V_15 . V_26 ) ;
F_7 ( V_18 , V_39 , V_7 -> V_15 . V_28 ) ;
F_7 ( V_18 , V_34 , V_40 ) ;
}
F_8 ( F_9 ( V_18 , V_41 ) != 0 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_6 * V_7 )
{
return 0 ;
}
static int F_11 ( int V_42 , struct V_6 * V_7 )
{
return 0 ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = V_9 -> V_18 ;
struct V_6 * V_7 = V_18 -> V_6 ;
int V_43 = ( V_7 -> V_30 . V_31 / 4 ) ;
int * V_44 = ( int * ) V_7 -> V_45 ;
T_2 T_3 * V_46 = V_9 -> V_47 ;
unsigned long V_48 ;
unsigned V_49 , V_50 , V_51 , V_52 ;
int V_53 , V_54 ;
struct {
T_4 V_55 ;
T_5 V_56 ;
} * V_57 ;
if ( V_18 -> V_58 )
return;
F_13 ( & V_9 -> V_59 . V_60 , V_48 ) ;
if ( ! V_9 -> V_59 . V_61 ) {
F_14 ( & V_9 -> V_59 . V_60 , V_48 ) ;
return;
}
V_49 = V_9 -> V_59 . V_62 ;
V_50 = V_9 -> V_59 . y1 ;
V_51 = F_15 ( V_9 -> V_59 . V_63 , V_7 -> V_15 . V_26 ) - V_49 ;
V_52 = F_15 ( V_9 -> V_59 . V_64 , V_7 -> V_15 . V_28 ) - V_50 ;
V_9 -> V_59 . V_62 = V_9 -> V_59 . V_63 = 0 ;
V_9 -> V_59 . y1 = V_9 -> V_59 . V_64 = 0 ;
F_14 ( & V_9 -> V_59 . V_60 , V_48 ) ;
for ( V_53 = V_50 * V_43 ; V_53 < V_7 -> V_30 . V_65 / 4 ; V_53 += V_43 ) {
for ( V_54 = V_53 + V_49 ; V_54 < V_53 + V_49 + V_51 && V_54 < V_7 -> V_30 . V_65 / 4 ; V_54 ++ )
F_16 ( V_44 [ V_54 ] , V_46 + V_54 ) ;
}
#if 0
DRM_INFO("%s, (%u, %u) (%ux%u)\n", __func__, x, y, w, h);
#endif
V_57 = F_17 ( V_18 , sizeof( * V_57 ) ) ;
if ( F_18 ( V_57 == NULL ) ) {
F_2 ( L_7 ) ;
return;
}
V_57 -> V_55 = F_19 ( V_66 ) ;
V_57 -> V_56 . V_49 = F_19 ( V_49 ) ;
V_57 -> V_56 . V_50 = F_19 ( V_50 ) ;
V_57 -> V_56 . V_67 = F_19 ( V_51 ) ;
V_57 -> V_56 . V_68 = F_19 ( V_52 ) ;
F_20 ( V_18 , sizeof( * V_57 ) ) ;
}
static void F_21 ( struct V_8 * V_9 ,
unsigned V_62 , unsigned y1 ,
unsigned V_67 , unsigned V_68 )
{
struct V_6 * V_7 = V_9 -> V_18 -> V_6 ;
unsigned long V_48 ;
unsigned V_63 = V_62 + V_67 ;
unsigned V_64 = y1 + V_68 ;
F_13 ( & V_9 -> V_59 . V_60 , V_48 ) ;
if ( V_9 -> V_59 . V_62 == V_9 -> V_59 . V_63 ) {
V_9 -> V_59 . V_62 = V_62 ;
V_9 -> V_59 . y1 = y1 ;
V_9 -> V_59 . V_63 = V_63 ;
V_9 -> V_59 . V_64 = V_64 ;
if ( V_9 -> V_59 . V_61 )
F_22 ( & V_7 -> V_69 , V_70 ) ;
} else {
if ( V_62 < V_9 -> V_59 . V_62 )
V_9 -> V_59 . V_62 = V_62 ;
if ( y1 < V_9 -> V_59 . y1 )
V_9 -> V_59 . y1 = y1 ;
if ( V_63 > V_9 -> V_59 . V_63 )
V_9 -> V_59 . V_63 = V_63 ;
if ( V_64 > V_9 -> V_59 . V_64 )
V_9 -> V_59 . V_64 = V_64 ;
}
F_14 ( & V_9 -> V_59 . V_60 , V_48 ) ;
}
static void F_23 ( struct V_6 * V_7 ,
struct V_71 * V_72 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_73 , V_74 , F_15 , V_75 ;
unsigned long V_48 ;
struct V_76 * V_76 ;
int y1 , V_64 ;
F_15 = V_77 ;
V_75 = 0 ;
F_24 (page, pagelist, lru) {
V_73 = V_76 -> V_78 << V_79 ;
V_74 = V_73 + V_80 - 1 ;
F_15 = F_15 ( F_15 , V_73 ) ;
V_75 = V_75 ( V_75 , V_74 ) ;
}
if ( F_15 < V_75 ) {
y1 = F_15 / V_7 -> V_30 . V_31 ;
V_64 = ( V_75 / V_7 -> V_30 . V_31 ) + 1 ;
F_13 ( & V_9 -> V_59 . V_60 , V_48 ) ;
V_9 -> V_59 . V_62 = 0 ;
V_9 -> V_59 . y1 = y1 ;
V_9 -> V_59 . V_63 = V_7 -> V_15 . V_26 ;
V_9 -> V_59 . V_64 = V_64 ;
F_14 ( & V_9 -> V_59 . V_60 , V_48 ) ;
}
F_12 ( V_9 ) ;
}
static void F_25 ( struct V_6 * V_7 , const struct V_81 * V_82 )
{
F_26 ( V_7 , V_82 ) ;
F_21 ( V_7 -> V_9 , V_82 -> V_83 , V_82 -> V_84 ,
V_82 -> V_67 , V_82 -> V_68 ) ;
}
static void F_27 ( struct V_6 * V_7 , const struct V_85 * V_86 )
{
F_28 ( V_7 , V_86 ) ;
F_21 ( V_7 -> V_9 , V_86 -> V_83 , V_86 -> V_84 ,
V_86 -> V_67 , V_86 -> V_68 ) ;
}
static void F_29 ( struct V_6 * V_7 , const struct V_87 * V_88 )
{
F_30 ( V_7 , V_88 ) ;
F_21 ( V_7 -> V_9 , V_88 -> V_83 , V_88 -> V_84 ,
V_88 -> V_67 , V_88 -> V_68 ) ;
}
static int F_31 ( struct V_17 * V_18 ,
T_6 V_89 , struct V_90 * * V_91 )
{
struct V_90 * V_92 ;
struct V_93 V_94 = V_95 ;
int V_32 ;
V_94 . V_96 = ( V_89 + V_80 - 1 ) >> V_79 ;
V_32 = F_32 ( & V_18 -> V_97 . V_60 , false ) ;
if ( F_18 ( V_32 != 0 ) )
return V_32 ;
V_92 = F_33 ( sizeof( * V_92 ) , V_98 ) ;
if ( ! V_92 )
goto V_99;
V_32 = F_34 ( V_18 , V_92 , V_89 ,
& V_94 ,
false ,
& V_100 ) ;
if ( F_18 ( V_32 != 0 ) )
goto V_99;
* V_91 = V_92 ;
F_35 ( & V_18 -> V_97 . V_60 ) ;
return 0 ;
V_99:
F_35 ( & V_18 -> V_97 . V_60 ) ;
return V_32 ;
}
int F_36 ( struct V_17 * V_18 )
{
struct V_101 * V_101 = & V_18 -> V_102 -> V_103 -> V_102 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
unsigned V_104 , V_105 ;
unsigned V_106 , V_107 ;
unsigned V_108 , V_109 , V_110 , V_111 , V_112 ;
int V_32 ;
V_108 = 32 ;
V_109 = 24 ;
V_106 = F_15 ( V_18 -> V_113 , ( unsigned ) 2048 ) ;
V_107 = F_15 ( V_18 -> V_114 , ( unsigned ) 2048 ) ;
V_104 = F_15 ( V_18 -> V_104 , V_106 ) ;
V_105 = F_15 ( V_18 -> V_105 , V_107 ) ;
V_111 = V_106 * V_108 / 8 ;
V_112 = V_111 * V_107 ;
V_110 = F_9 ( V_18 , V_41 ) ;
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
V_32 = - V_115 ;
goto V_117;
}
V_32 = F_31 ( V_18 , V_112 , & V_9 -> V_92 ) ;
if ( F_18 ( V_32 != 0 ) )
goto V_117;
V_32 = F_38 ( & V_9 -> V_92 -> V_118 ,
0 ,
V_9 -> V_92 -> V_118 . V_119 ,
& V_9 -> V_120 ) ;
if ( F_18 ( V_32 != 0 ) )
goto V_121;
V_9 -> V_47 = F_39 ( & V_9 -> V_120 , & V_9 -> V_122 ) ;
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
V_7 -> V_30 . V_65 = V_112 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_45 = V_9 -> V_116 ;
V_7 -> V_135 = V_112 ;
V_7 -> V_48 = V_136 ;
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
V_7 -> V_15 . V_68 = - 1 ;
V_7 -> V_15 . V_67 = - 1 ;
V_7 -> V_15 . V_26 = V_104 ;
V_7 -> V_15 . V_28 = V_105 ;
V_7 -> V_143 = F_40 ( 1 ) ;
if ( ! V_7 -> V_143 ) {
V_32 = - V_115 ;
goto V_144;
}
V_7 -> V_143 -> V_145 [ 0 ] . V_118 = V_18 -> V_146 ;
V_7 -> V_143 -> V_145 [ 0 ] . V_89 = V_18 -> V_147 ;
V_9 -> V_59 . V_62 = V_9 -> V_59 . V_63 = 0 ;
V_9 -> V_59 . y1 = V_9 -> V_59 . V_64 = 0 ;
V_9 -> V_59 . V_61 = true ;
F_41 ( & V_9 -> V_59 . V_60 ) ;
V_7 -> V_148 = & V_149 ;
F_42 ( V_7 ) ;
V_32 = F_43 ( V_7 ) ;
if ( F_18 ( V_32 != 0 ) )
goto V_150;
return 0 ;
V_150:
F_44 ( V_7 ) ;
V_144:
F_45 ( & V_9 -> V_120 ) ;
V_121:
F_46 ( (struct V_151 * * ) & V_9 -> V_92 ) ;
V_117:
F_47 ( V_9 -> V_116 ) ;
F_48 ( V_7 ) ;
V_18 -> V_6 = NULL ;
return V_32 ;
}
int F_49 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_151 * V_152 ;
if ( ! V_18 -> V_6 )
return 0 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
V_152 = & V_9 -> V_92 -> V_118 ;
V_9 -> V_92 = NULL ;
F_44 ( V_7 ) ;
F_50 ( V_7 ) ;
F_45 ( & V_9 -> V_120 ) ;
F_46 ( & V_152 ) ;
F_47 ( V_9 -> V_116 ) ;
F_48 ( V_7 ) ;
return 0 ;
}
int F_51 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_48 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_13 ( & V_9 -> V_59 . V_60 , V_48 ) ;
V_9 -> V_59 . V_61 = false ;
F_14 ( & V_9 -> V_59 . V_60 , V_48 ) ;
F_52 ( & V_7 -> V_69 ) ;
V_9 -> V_47 = NULL ;
F_45 ( & V_9 -> V_120 ) ;
F_53 ( V_18 , V_9 -> V_92 , false ) ;
return 0 ;
}
int F_54 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_48 ;
bool V_153 ;
int V_32 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
if ( V_9 -> V_47 != NULL )
return 0 ;
F_55 ( V_18 ) ;
V_32 = F_56 ( V_18 , V_9 -> V_92 , true , false ) ;
if ( F_18 ( V_32 != 0 ) ) {
F_2 ( L_9 ) ;
goto V_154;
}
V_32 = F_38 ( & V_9 -> V_92 -> V_118 ,
0 ,
V_9 -> V_92 -> V_118 . V_119 ,
& V_9 -> V_120 ) ;
F_57 ( V_32 != 0 ) ;
V_9 -> V_47 = F_39 ( & V_9 -> V_120 , & V_153 ) ;
F_13 ( & V_9 -> V_59 . V_60 , V_48 ) ;
V_9 -> V_59 . V_61 = true ;
F_14 ( & V_9 -> V_59 . V_60 , V_48 ) ;
V_154:
F_5 ( V_7 ) ;
F_21 ( V_9 , 0 , 0 , V_7 -> V_15 . V_26 , V_7 -> V_15 . V_28 ) ;
F_22 ( & V_7 -> V_69 , 0 ) ;
return 0 ;
}
