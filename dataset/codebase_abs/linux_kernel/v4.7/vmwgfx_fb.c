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
switch ( V_9 -> V_12 -> V_13 ) {
case 24 :
case 32 :
V_10 [ V_1 ] = ( ( V_2 & 0xff00 ) << 8 ) |
( V_3 & 0xff00 ) |
( ( V_4 & 0xff00 ) >> 8 ) ;
break;
default:
F_2 ( L_2 , V_9 -> V_12 -> V_13 ,
V_9 -> V_12 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
static int F_3 ( struct V_15 * V_16 ,
struct V_6 * V_7 )
{
int V_13 = V_16 -> V_14 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_18 ;
switch ( V_16 -> V_14 ) {
case 32 :
V_13 = ( V_16 -> V_5 . V_19 > 0 ) ? 32 : 24 ;
break;
default:
F_2 ( L_3 , V_16 -> V_14 ) ;
return - V_20 ;
}
switch ( V_13 ) {
case 24 :
V_16 -> V_2 . V_21 = 16 ;
V_16 -> V_3 . V_21 = 8 ;
V_16 -> V_4 . V_21 = 0 ;
V_16 -> V_2 . V_19 = 8 ;
V_16 -> V_3 . V_19 = 8 ;
V_16 -> V_4 . V_19 = 8 ;
V_16 -> V_5 . V_19 = 0 ;
V_16 -> V_5 . V_21 = 0 ;
break;
case 32 :
V_16 -> V_2 . V_21 = 16 ;
V_16 -> V_3 . V_21 = 8 ;
V_16 -> V_4 . V_21 = 0 ;
V_16 -> V_2 . V_19 = 8 ;
V_16 -> V_3 . V_19 = 8 ;
V_16 -> V_4 . V_19 = 8 ;
V_16 -> V_5 . V_19 = 8 ;
V_16 -> V_5 . V_21 = 24 ;
break;
default:
F_2 ( L_4 , V_13 ) ;
return - V_20 ;
}
if ( ( V_16 -> V_22 + V_16 -> V_23 ) > V_9 -> V_24 ||
( V_16 -> V_25 + V_16 -> V_26 ) > V_9 -> V_27 ) {
F_2 ( L_5 ) ;
return - V_20 ;
}
if ( ! F_4 ( V_18 ,
V_16 -> V_23 * V_16 -> V_14 / 8 ,
V_16 -> V_25 + V_16 -> V_26 ) ) {
F_2 ( L_5 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_5 ( int V_28 , struct V_6 * V_7 )
{
return 0 ;
}
static void F_6 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = F_7 ( V_30 , struct V_8 ,
V_31 . V_30 ) ;
struct V_17 * V_18 = V_9 -> V_18 ;
struct V_6 * V_7 = V_18 -> V_6 ;
unsigned long V_32 ;
T_2 V_33 , V_34 , V_35 , V_36 , V_37 , V_38 ;
T_1 V_39 , V_40 , V_41 ;
struct V_42 V_43 ;
struct V_44 * V_45 ;
T_3 * V_46 , * V_47 ;
if ( V_18 -> V_48 )
return;
F_8 ( & V_9 -> V_49 ) ;
V_45 = V_9 -> V_12 ;
if ( ! V_45 )
goto V_50;
F_9 ( & V_9 -> V_51 . V_52 , V_32 ) ;
if ( ! V_9 -> V_51 . V_53 ) {
F_10 ( & V_9 -> V_51 . V_52 , V_32 ) ;
goto V_50;
}
V_39 = ( V_45 -> V_14 + 7 ) / 8 ;
V_40 = V_9 -> V_54 + V_45 -> V_55 ;
V_41 = V_9 -> V_56 + V_45 -> V_57 ;
V_33 = V_9 -> V_51 . V_58 - V_9 -> V_54 ;
V_35 = V_9 -> V_51 . y1 - V_9 -> V_56 ;
V_33 = F_11 ( T_2 , V_33 , 0 ) ;
V_35 = F_11 ( T_2 , V_35 , 0 ) ;
V_34 = V_9 -> V_51 . V_59 - V_9 -> V_54 ;
V_36 = V_9 -> V_51 . V_60 - V_9 -> V_56 ;
V_34 = F_12 ( T_2 , V_34 , V_40 ) ;
V_36 = F_12 ( T_2 , V_36 , V_41 ) ;
V_37 = V_34 - V_33 ;
V_38 = V_36 - V_35 ;
V_37 = F_11 ( T_2 , 0 , V_37 ) ;
V_38 = F_11 ( T_2 , 0 , V_38 ) ;
V_9 -> V_51 . V_58 = V_9 -> V_51 . V_59 = 0 ;
V_9 -> V_51 . y1 = V_9 -> V_51 . V_60 = 0 ;
F_10 ( & V_9 -> V_51 . V_52 , V_32 ) ;
if ( V_37 && V_38 ) {
V_47 = ( T_3 * ) V_9 -> V_61 +
( V_35 * V_9 -> V_12 -> V_62 [ 0 ] + V_33 * V_39 ) ;
V_46 = ( T_3 * ) V_9 -> V_63 +
( ( V_35 + V_9 -> V_56 ) * V_7 -> V_64 . V_65 +
( V_33 + V_9 -> V_54 ) * V_39 ) ;
while ( V_38 -- > 0 ) {
memcpy ( V_47 , V_46 , V_37 * V_39 ) ;
V_47 += V_9 -> V_12 -> V_62 [ 0 ] ;
V_46 += V_7 -> V_64 . V_65 ;
}
V_43 . V_58 = V_33 ;
V_43 . V_59 = V_34 ;
V_43 . y1 = V_35 ;
V_43 . V_60 = V_36 ;
F_13 ( V_9 -> V_12 -> V_66 -> V_51 ( V_45 , NULL , 0 , 0 ,
& V_43 , 1 ) ) ;
F_14 ( V_18 , false ) ;
}
V_50:
F_15 ( & V_9 -> V_49 ) ;
}
static void F_16 ( struct V_8 * V_9 ,
unsigned V_58 , unsigned y1 ,
unsigned V_55 , unsigned V_57 )
{
unsigned long V_67 ;
unsigned V_59 = V_58 + V_55 ;
unsigned V_60 = y1 + V_57 ;
F_9 ( & V_9 -> V_51 . V_52 , V_67 ) ;
if ( V_9 -> V_51 . V_58 == V_9 -> V_51 . V_59 ) {
V_9 -> V_51 . V_58 = V_58 ;
V_9 -> V_51 . y1 = y1 ;
V_9 -> V_51 . V_59 = V_59 ;
V_9 -> V_51 . V_60 = V_60 ;
if ( V_9 -> V_51 . V_53 )
F_17 ( & V_9 -> V_31 ,
V_68 ) ;
} else {
if ( V_58 < V_9 -> V_51 . V_58 )
V_9 -> V_51 . V_58 = V_58 ;
if ( y1 < V_9 -> V_51 . y1 )
V_9 -> V_51 . y1 = y1 ;
if ( V_59 > V_9 -> V_51 . V_59 )
V_9 -> V_51 . V_59 = V_59 ;
if ( V_60 > V_9 -> V_51 . V_60 )
V_9 -> V_51 . V_60 = V_60 ;
}
F_10 ( & V_9 -> V_51 . V_52 , V_67 ) ;
}
static int F_18 ( struct V_15 * V_16 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( ( V_16 -> V_22 + V_16 -> V_23 ) > V_16 -> V_69 ||
( V_16 -> V_25 + V_16 -> V_26 ) > V_16 -> V_70 ) {
F_2 ( L_6 ) ;
return - V_20 ;
}
F_8 ( & V_9 -> V_49 ) ;
V_9 -> V_54 = V_16 -> V_22 ;
V_9 -> V_56 = V_16 -> V_25 ;
if ( V_9 -> V_12 )
F_16 ( V_9 , V_9 -> V_54 , V_9 -> V_56 , V_9 -> V_12 -> V_55 ,
V_9 -> V_12 -> V_57 ) ;
F_15 ( & V_9 -> V_49 ) ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_71 * V_72 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_73 , V_74 , V_75 , V_76 ;
unsigned long V_67 ;
struct V_77 * V_77 ;
int y1 , V_60 ;
V_75 = V_78 ;
V_76 = 0 ;
F_20 (page, pagelist, lru) {
V_73 = V_77 -> V_79 << V_80 ;
V_74 = V_73 + V_81 - 1 ;
V_75 = V_75 ( V_75 , V_73 ) ;
V_76 = V_76 ( V_76 , V_74 ) ;
}
if ( V_75 < V_76 ) {
y1 = V_75 / V_7 -> V_64 . V_65 ;
V_60 = ( V_76 / V_7 -> V_64 . V_65 ) + 1 ;
F_9 ( & V_9 -> V_51 . V_52 , V_67 ) ;
V_9 -> V_51 . V_58 = 0 ;
V_9 -> V_51 . y1 = y1 ;
V_9 -> V_51 . V_59 = V_7 -> V_16 . V_23 ;
V_9 -> V_51 . V_60 = V_60 ;
F_10 ( & V_9 -> V_51 . V_52 , V_67 ) ;
F_21 ( & V_9 -> V_31 ) ;
F_17 ( & V_9 -> V_31 , 0 ) ;
}
}
static void F_22 ( struct V_6 * V_7 , const struct V_82 * V_83 )
{
F_23 ( V_7 , V_83 ) ;
F_16 ( V_7 -> V_9 , V_83 -> V_84 , V_83 -> V_85 ,
V_83 -> V_55 , V_83 -> V_57 ) ;
}
static void F_24 ( struct V_6 * V_7 , const struct V_86 * V_87 )
{
F_25 ( V_7 , V_87 ) ;
F_16 ( V_7 -> V_9 , V_87 -> V_84 , V_87 -> V_85 ,
V_87 -> V_55 , V_87 -> V_57 ) ;
}
static void F_26 ( struct V_6 * V_7 , const struct V_88 * V_89 )
{
F_27 ( V_7 , V_89 ) ;
F_16 ( V_7 -> V_9 , V_89 -> V_84 , V_89 -> V_85 ,
V_89 -> V_55 , V_89 -> V_57 ) ;
}
static int F_28 ( struct V_17 * V_18 ,
T_4 V_90 , struct V_91 * * V_92 )
{
struct V_91 * V_93 ;
int V_94 ;
( void ) F_29 ( & V_18 -> V_95 , false ) ;
V_93 = F_30 ( sizeof( * V_93 ) , V_96 ) ;
if ( ! V_93 ) {
V_94 = - V_97 ;
goto V_98;
}
V_94 = F_31 ( V_18 , V_93 , V_90 ,
& V_99 ,
false ,
& V_100 ) ;
if ( F_32 ( V_94 != 0 ) )
goto V_98;
* V_92 = V_93 ;
F_33 ( & V_18 -> V_95 ) ;
return 0 ;
V_98:
F_33 ( & V_18 -> V_95 ) ;
return V_94 ;
}
static int F_34 ( struct V_15 * V_16 ,
int * V_13 )
{
switch ( V_16 -> V_14 ) {
case 32 :
* V_13 = ( V_16 -> V_5 . V_19 > 0 ) ? 32 : 24 ;
break;
default:
F_2 ( L_3 , V_16 -> V_14 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_9 ,
bool V_101 ,
bool V_102 )
{
struct V_44 * V_45 = V_9 -> V_12 ;
int V_94 ;
if ( V_9 -> V_103 ) {
struct V_104 V_105 ;
V_105 . V_106 = V_9 -> V_106 ;
V_105 . V_107 = 0 ;
V_105 . V_108 = 0 ;
V_105 . V_109 = NULL ;
V_105 . V_110 = NULL ;
V_105 . V_111 = 1 ;
V_105 . V_112 = & V_9 -> V_113 ;
V_94 = F_36 ( & V_105 ) ;
if ( V_94 ) {
F_2 ( L_7 ) ;
return V_94 ;
}
F_37 ( V_9 -> V_18 -> V_114 , V_9 -> V_103 ) ;
V_9 -> V_103 = NULL ;
}
if ( V_45 ) {
F_38 ( V_45 ) ;
V_9 -> V_12 = NULL ;
}
if ( V_9 -> V_93 && V_101 ) {
if ( V_9 -> V_61 ) {
F_39 ( & V_9 -> V_115 ) ;
V_9 -> V_61 = NULL ;
}
if ( V_102 )
F_40 ( & V_9 -> V_93 ) ;
else
F_41 ( V_9 -> V_18 , V_9 -> V_93 , false ) ;
}
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
struct V_116 V_117 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_15 * V_16 = & V_7 -> V_16 ;
struct V_44 * V_45 ;
struct V_118 * V_119 ;
int V_94 = 0 ;
T_4 V_120 ;
V_94 = F_34 ( V_16 , & V_117 . V_13 ) ;
if ( V_94 )
return V_94 ;
V_117 . V_55 = V_16 -> V_23 ;
V_117 . V_57 = V_16 -> V_26 ;
V_117 . V_121 = V_16 -> V_14 ;
V_117 . V_122 = ( ( V_117 . V_121 + 7 ) / 8 ) * V_117 . V_55 ;
V_45 = V_9 -> V_12 ;
if ( V_45 && V_45 -> V_55 == V_117 . V_55 &&
V_45 -> V_57 == V_117 . V_57 &&
V_45 -> V_14 == V_117 . V_121 &&
V_45 -> V_13 == V_117 . V_13 &&
V_45 -> V_62 [ 0 ] == V_117 . V_122 )
return 0 ;
V_120 = ( T_4 ) V_117 . V_122 * ( T_4 ) V_117 . V_57 ;
V_94 = F_35 ( V_9 ,
V_9 -> V_123 < V_120 ||
V_9 -> V_123 > 2 * V_120 ,
true ) ;
if ( V_94 )
return V_94 ;
if ( ! V_9 -> V_93 ) {
V_94 = F_28 ( V_9 -> V_18 , V_120 ,
& V_9 -> V_93 ) ;
if ( V_94 ) {
F_2 ( L_8
L_9 ) ;
return V_94 ;
}
V_9 -> V_123 = V_120 ;
}
V_119 = F_43 ( V_9 -> V_18 , V_9 -> V_93 , NULL ,
true , & V_117 ) ;
if ( F_44 ( V_119 ) )
return F_45 ( V_119 ) ;
V_9 -> V_12 = & V_119 -> V_124 ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_18 ;
struct V_104 V_105 ;
struct V_15 * V_16 = & V_7 -> V_16 ;
struct V_125 V_126 = { F_47 ( L_10 ,
DRM_MODE_TYPE_DRIVER,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
struct V_125 * V_127 ;
struct V_125 * V_109 ;
int V_94 ;
V_127 = V_9 -> V_103 ;
V_109 = F_48 ( V_18 -> V_114 , & V_126 ) ;
if ( ! V_109 ) {
F_2 ( L_11 ) ;
return - V_97 ;
}
V_109 -> V_128 = V_16 -> V_23 ;
V_109 -> V_129 = V_16 -> V_26 ;
F_49 ( V_109 ) ;
if ( V_127 && F_50 ( V_127 , V_109 ) ) {
F_37 ( V_18 -> V_114 , V_109 ) ;
V_109 = V_127 ;
V_127 = NULL ;
} else if ( ! F_4 ( V_18 ,
V_109 -> V_128 *
F_51 ( V_16 -> V_14 , 8 ) ,
V_109 -> V_129 ) ) {
F_37 ( V_18 -> V_114 , V_109 ) ;
return - V_20 ;
}
F_8 ( & V_9 -> V_49 ) ;
F_52 ( V_18 -> V_114 ) ;
V_94 = F_42 ( V_7 ) ;
if ( V_94 )
goto V_50;
V_9 -> V_54 = V_16 -> V_22 ;
V_9 -> V_56 = V_16 -> V_25 ;
V_105 . V_106 = V_9 -> V_106 ;
V_105 . V_107 = 0 ;
V_105 . V_108 = 0 ;
V_105 . V_109 = V_109 ;
V_105 . V_110 = V_9 -> V_12 ;
V_105 . V_111 = 1 ;
V_105 . V_112 = & V_9 -> V_113 ;
V_94 = F_36 ( & V_105 ) ;
if ( V_94 )
goto V_50;
if ( ! V_9 -> V_61 ) {
struct V_118 * V_119 = F_53 ( V_105 . V_110 ) ;
V_94 = V_119 -> V_130 ( V_119 ) ;
if ( V_94 ) {
F_2 ( L_12 ) ;
goto V_50;
}
V_94 = F_54 ( & V_9 -> V_93 -> V_124 , 0 ,
V_9 -> V_93 -> V_124 . V_131 , & V_9 -> V_115 ) ;
if ( V_94 ) {
V_119 -> V_132 ( V_119 ) ;
F_2 ( L_13 ) ;
goto V_50;
}
V_9 -> V_61 = F_55 ( & V_9 -> V_115 , & V_9 -> V_133 ) ;
}
F_16 ( V_9 , V_9 -> V_54 , V_9 -> V_56 ,
V_9 -> V_12 -> V_55 , V_9 -> V_12 -> V_57 ) ;
F_17 ( & V_9 -> V_31 , 0 ) ;
V_50:
if ( V_127 )
F_37 ( V_18 -> V_114 , V_127 ) ;
V_9 -> V_103 = V_109 ;
F_56 ( V_18 -> V_114 ) ;
F_15 ( & V_9 -> V_49 ) ;
return V_94 ;
}
int F_57 ( struct V_17 * V_18 )
{
struct V_134 * V_134 = & V_18 -> V_114 -> V_135 -> V_114 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
unsigned V_136 , V_137 ;
unsigned V_138 , V_139 , V_140 , V_141 , V_142 ;
struct V_125 * V_143 ;
int V_94 ;
V_138 = 32 ;
V_139 = 24 ;
V_136 = V_75 ( V_18 -> V_144 , ( unsigned ) 2048 ) ;
V_137 = V_75 ( V_18 -> V_145 , ( unsigned ) 2048 ) ;
V_141 = V_136 * V_138 / 8 ;
V_142 = V_141 * V_137 ;
V_140 = F_58 ( V_18 , V_146 ) ;
V_7 = F_59 ( sizeof( * V_9 ) , V_134 ) ;
if ( ! V_7 )
return - V_97 ;
V_18 -> V_6 = V_7 ;
V_9 = V_7 -> V_9 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
F_60 ( & V_9 -> V_31 , & F_6 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_63 = NULL ;
V_9 -> V_24 = V_136 ;
V_9 -> V_27 = V_137 ;
F_52 ( V_18 -> V_114 ) ;
V_94 = F_61 ( V_18 , 0 , V_9 -> V_24 ,
V_9 -> V_27 , & V_9 -> V_113 ,
& V_9 -> V_106 , & V_143 ) ;
if ( V_94 ) {
F_56 ( V_18 -> V_114 ) ;
goto V_147;
}
V_7 -> V_16 . V_23 = V_143 -> V_128 ;
V_7 -> V_16 . V_26 = V_143 -> V_129 ;
F_56 ( V_18 -> V_114 ) ;
V_9 -> V_63 = F_62 ( V_142 ) ;
if ( F_32 ( V_9 -> V_63 == NULL ) ) {
V_94 = - V_97 ;
goto V_148;
}
strcpy ( V_7 -> V_64 . V_149 , L_14 ) ;
V_7 -> V_64 . type = V_150 ;
V_7 -> V_64 . V_151 = V_152 ;
V_7 -> V_64 . V_153 = 0 ;
V_7 -> V_64 . V_154 = 1 ;
V_7 -> V_64 . V_155 = 1 ;
V_7 -> V_64 . V_156 = 0 ;
V_7 -> V_64 . V_157 = V_158 ;
V_7 -> V_64 . V_65 = V_141 ;
V_7 -> V_64 . V_159 = 0 ;
V_7 -> V_64 . V_160 = V_142 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_161 = ( char V_162 * ) V_9 -> V_63 ;
V_7 -> V_163 = V_142 ;
V_7 -> V_67 = V_164 ;
V_7 -> V_165 = & V_166 ;
V_7 -> V_16 . V_2 . V_21 = 16 ;
V_7 -> V_16 . V_3 . V_21 = 8 ;
V_7 -> V_16 . V_4 . V_21 = 0 ;
V_7 -> V_16 . V_2 . V_19 = 8 ;
V_7 -> V_16 . V_3 . V_19 = 8 ;
V_7 -> V_16 . V_4 . V_19 = 8 ;
V_7 -> V_16 . V_5 . V_21 = 0 ;
V_7 -> V_16 . V_5 . V_19 = 0 ;
V_7 -> V_16 . V_69 = V_136 ;
V_7 -> V_16 . V_70 = V_137 ;
V_7 -> V_16 . V_14 = V_138 ;
V_7 -> V_16 . V_22 = 0 ;
V_7 -> V_16 . V_25 = 0 ;
V_7 -> V_16 . V_167 = V_168 ;
V_7 -> V_16 . V_57 = - 1 ;
V_7 -> V_16 . V_55 = - 1 ;
V_7 -> V_169 = F_63 ( 1 ) ;
if ( ! V_7 -> V_169 ) {
V_94 = - V_97 ;
goto V_170;
}
V_7 -> V_169 -> V_171 [ 0 ] . V_124 = V_18 -> V_172 ;
V_7 -> V_169 -> V_171 [ 0 ] . V_90 = V_18 -> V_173 ;
V_9 -> V_51 . V_58 = V_9 -> V_51 . V_59 = 0 ;
V_9 -> V_51 . y1 = V_9 -> V_51 . V_60 = 0 ;
V_9 -> V_51 . V_53 = true ;
F_64 ( & V_9 -> V_51 . V_52 ) ;
F_65 ( & V_9 -> V_49 ) ;
V_7 -> V_174 = & V_175 ;
F_66 ( V_7 ) ;
V_94 = F_67 ( V_7 ) ;
if ( F_32 ( V_94 != 0 ) )
goto V_176;
F_46 ( V_7 ) ;
return 0 ;
V_176:
F_68 ( V_7 ) ;
V_170:
V_148:
F_69 ( V_9 -> V_63 ) ;
V_147:
F_70 ( V_7 ) ;
V_18 -> V_6 = NULL ;
return V_94 ;
}
int F_71 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( ! V_18 -> V_6 )
return 0 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_68 ( V_7 ) ;
F_72 ( & V_9 -> V_31 ) ;
F_73 ( V_7 ) ;
( void ) F_35 ( V_9 , true , true ) ;
F_69 ( V_9 -> V_63 ) ;
F_70 ( V_7 ) ;
return 0 ;
}
int F_74 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_67 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_9 ( & V_9 -> V_51 . V_52 , V_67 ) ;
V_9 -> V_51 . V_53 = false ;
F_10 ( & V_9 -> V_51 . V_52 , V_67 ) ;
F_75 ( & V_7 -> V_177 ) ;
F_75 ( & V_9 -> V_31 ) ;
F_8 ( & V_9 -> V_49 ) ;
( void ) F_35 ( V_9 , true , false ) ;
F_15 ( & V_9 -> V_49 ) ;
return 0 ;
}
int F_76 ( struct V_17 * V_18 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned long V_67 ;
if ( ! V_18 -> V_6 )
return - V_20 ;
V_7 = V_18 -> V_6 ;
V_9 = V_7 -> V_9 ;
F_46 ( V_7 ) ;
F_9 ( & V_9 -> V_51 . V_52 , V_67 ) ;
V_9 -> V_51 . V_53 = true ;
F_10 ( & V_9 -> V_51 . V_52 , V_67 ) ;
return 0 ;
}
