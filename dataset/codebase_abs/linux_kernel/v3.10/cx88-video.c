static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
static int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 , unsigned int V_9 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
if ( V_8 -> V_12 & V_9 )
return 1 ;
F_4 ( & V_11 -> V_13 ) ;
if ( V_6 -> V_12 & V_9 ) {
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
V_8 -> V_12 |= V_9 ;
V_6 -> V_12 |= V_9 ;
F_6 ( 1 , L_1 , V_9 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 1 ;
}
static
int F_7 ( struct V_7 * V_8 , unsigned int V_9 )
{
return ( V_8 -> V_12 & V_9 ) ;
}
static
int F_8 ( struct V_5 * V_6 , unsigned int V_9 )
{
return ( V_6 -> V_12 & V_9 ) ;
}
static
void F_9 ( struct V_5 * V_6 , struct V_7 * V_8 , unsigned int V_14 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
F_10 ( ( V_8 -> V_12 & V_14 ) != V_14 ) ;
F_4 ( & V_11 -> V_13 ) ;
V_8 -> V_12 &= ~ V_14 ;
V_6 -> V_12 &= ~ V_14 ;
F_6 ( 1 , L_2 , V_14 ) ;
F_5 ( & V_11 -> V_13 ) ;
}
int F_11 ( struct V_10 * V_11 , unsigned int V_15 )
{
F_6 ( 1 , L_3 ,
V_15 , F_12 ( V_15 ) . V_16 ,
F_12 ( V_15 ) . V_17 , F_12 ( V_15 ) . V_18 ,
F_12 ( V_15 ) . V_19 , F_12 ( V_15 ) . V_20 ) ;
V_11 -> V_15 = V_15 ;
F_13 ( V_21 , 0x03 << 14 , F_12 ( V_15 ) . V_16 << 14 ) ;
F_14 ( V_22 , F_12 ( V_15 ) . V_20 ) ;
F_14 ( V_23 , F_12 ( V_15 ) . V_17 ) ;
F_14 ( V_24 , F_12 ( V_15 ) . V_18 ) ;
F_14 ( V_25 , F_12 ( V_15 ) . V_19 ) ;
switch ( F_12 ( V_15 ) . type ) {
case V_26 :
F_15 ( V_27 , 0x00000001 ) ;
F_15 ( V_21 , 0x00010010 ) ;
F_15 ( V_28 , 0x00002020 ) ;
F_15 ( V_29 , 0x00002020 ) ;
break;
default:
F_16 ( V_27 , 0x00000001 ) ;
F_16 ( V_21 , 0x00010010 ) ;
F_16 ( V_28 , 0x00002020 ) ;
F_16 ( V_29 , 0x00002020 ) ;
break;
}
if ( F_12 ( V_15 ) . V_30 ) {
if ( V_11 -> V_31 ) {
F_17 ( V_11 , V_32 , V_33 ,
F_12 ( V_15 ) . V_30 , 0 , 0 ) ;
}
if ( F_12 ( V_15 ) . type != V_34 &&
F_12 ( V_15 ) . type != V_35 ) {
V_11 -> V_36 = V_37 ;
F_18 ( V_11 ) ;
} else {
F_14 ( V_38 , 0x0 ) ;
F_16 ( V_39 , V_40 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
F_20 ( V_11 , & V_45 [ V_46 ] ,
V_44 -> V_47 , V_44 -> V_48 . V_49 ) ;
F_21 ( V_11 , V_44 -> V_50 . V_51 , V_44 -> V_50 . V_52 , V_44 -> V_50 . V_53 ) ;
F_14 ( V_54 , V_44 -> V_55 -> V_56 | V_57 ) ;
F_14 ( V_58 , V_59 ) ;
V_42 -> V_60 = 1 ;
F_15 ( V_61 , V_11 -> V_62 | V_63 ) ;
F_15 ( V_64 , 0x0f0011 ) ;
F_15 ( V_65 , 0x06 ) ;
F_15 ( V_66 , ( 1 << 5 ) ) ;
F_15 ( V_67 , 0x11 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
F_16 ( V_67 , 0x11 ) ;
F_16 ( V_65 , 0x06 ) ;
F_16 ( V_61 , V_63 ) ;
F_16 ( V_64 , 0x0f0011 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_41 * V_42 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_43 * V_44 , * V_68 ;
if ( ! F_24 ( & V_42 -> V_69 ) ) {
V_44 = F_25 ( V_42 -> V_69 . V_70 , struct V_43 , V_50 . V_71 ) ;
F_6 ( 2 , L_4 ,
V_44 , V_44 -> V_50 . V_3 ) ;
F_19 ( V_6 , V_42 , V_44 ) ;
F_26 (buf, &q->active, vb.queue)
V_44 -> V_60 = V_42 -> V_60 ++ ;
F_27 ( & V_42 -> V_72 , V_73 + V_74 ) ;
return 0 ;
}
V_68 = NULL ;
for (; ; ) {
if ( F_24 ( & V_42 -> V_75 ) )
return 0 ;
V_44 = F_25 ( V_42 -> V_75 . V_70 , struct V_43 , V_50 . V_71 ) ;
if ( NULL == V_68 ) {
F_28 ( & V_44 -> V_50 . V_71 , & V_42 -> V_69 ) ;
F_19 ( V_6 , V_42 , V_44 ) ;
V_44 -> V_50 . V_76 = V_77 ;
V_44 -> V_60 = V_42 -> V_60 ++ ;
F_27 ( & V_42 -> V_72 , V_73 + V_74 ) ;
F_6 ( 2 , L_5 ,
V_44 , V_44 -> V_50 . V_3 ) ;
} else if ( V_68 -> V_50 . V_51 == V_44 -> V_50 . V_51 &&
V_68 -> V_50 . V_52 == V_44 -> V_50 . V_52 &&
V_68 -> V_55 == V_44 -> V_55 ) {
F_28 ( & V_44 -> V_50 . V_71 , & V_42 -> V_69 ) ;
V_44 -> V_50 . V_76 = V_77 ;
V_44 -> V_60 = V_42 -> V_60 ++ ;
V_68 -> V_48 . V_78 [ 1 ] = F_29 ( V_44 -> V_48 . V_49 ) ;
F_6 ( 2 , L_6 ,
V_44 , V_44 -> V_50 . V_3 ) ;
} else {
return 0 ;
}
V_68 = V_44 ;
}
}
static int
F_30 ( struct V_79 * V_42 , unsigned int * V_60 , unsigned int * V_80 )
{
struct V_7 * V_8 = V_42 -> V_81 ;
struct V_5 * V_6 = V_8 -> V_6 ;
* V_80 = V_6 -> V_55 -> V_82 * V_6 -> V_51 * V_6 -> V_52 >> 3 ;
if ( 0 == * V_60 )
* V_60 = 32 ;
if ( * V_80 * * V_60 > V_83 * 1024 * 1024 )
* V_60 = ( V_83 * 1024 * 1024 ) / * V_80 ;
return 0 ;
}
static int
F_31 ( struct V_79 * V_42 , struct V_84 * V_50 ,
enum V_85 V_53 )
{
struct V_7 * V_8 = V_42 -> V_81 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_43 * V_44 = F_32 ( V_50 , struct V_43 , V_50 ) ;
struct V_86 * V_49 = F_33 ( & V_44 -> V_50 ) ;
int V_87 , V_88 = 0 ;
F_10 ( NULL == V_6 -> V_55 ) ;
if ( V_6 -> V_51 < 48 || V_6 -> V_51 > F_34 ( V_11 -> V_89 ) ||
V_6 -> V_52 < 32 || V_6 -> V_52 > F_35 ( V_11 -> V_89 ) )
return - V_90 ;
V_44 -> V_50 . V_80 = ( V_6 -> V_51 * V_6 -> V_52 * V_6 -> V_55 -> V_82 ) >> 3 ;
if ( 0 != V_44 -> V_50 . V_91 && V_44 -> V_50 . V_92 < V_44 -> V_50 . V_80 )
return - V_90 ;
if ( V_44 -> V_55 != V_6 -> V_55 ||
V_44 -> V_50 . V_51 != V_6 -> V_51 ||
V_44 -> V_50 . V_52 != V_6 -> V_52 ||
V_44 -> V_50 . V_53 != V_53 ) {
V_44 -> V_55 = V_6 -> V_55 ;
V_44 -> V_50 . V_51 = V_6 -> V_51 ;
V_44 -> V_50 . V_52 = V_6 -> V_52 ;
V_44 -> V_50 . V_53 = V_53 ;
V_88 = 1 ;
}
if ( V_93 == V_44 -> V_50 . V_76 ) {
V_88 = 1 ;
if ( 0 != ( V_87 = F_36 ( V_42 , & V_44 -> V_50 , NULL ) ) )
goto V_94;
}
if ( V_88 ) {
V_44 -> V_47 = V_44 -> V_50 . V_51 * V_44 -> V_55 -> V_82 >> 3 ;
switch ( V_44 -> V_50 . V_53 ) {
case V_95 :
F_37 ( V_6 -> V_96 , & V_44 -> V_48 ,
V_49 -> V_97 , 0 , V_98 ,
V_44 -> V_47 , 0 , V_44 -> V_50 . V_52 ) ;
break;
case V_99 :
F_37 ( V_6 -> V_96 , & V_44 -> V_48 ,
V_49 -> V_97 , V_98 , 0 ,
V_44 -> V_47 , 0 , V_44 -> V_50 . V_52 ) ;
break;
case V_100 :
F_37 ( V_6 -> V_96 , & V_44 -> V_48 ,
V_49 -> V_97 , 0 , V_44 -> V_47 ,
V_44 -> V_47 , V_44 -> V_47 ,
V_44 -> V_50 . V_52 >> 1 ) ;
break;
case V_101 :
F_37 ( V_6 -> V_96 , & V_44 -> V_48 ,
V_49 -> V_97 ,
0 , V_44 -> V_47 * ( V_44 -> V_50 . V_52 >> 1 ) ,
V_44 -> V_47 , 0 ,
V_44 -> V_50 . V_52 >> 1 ) ;
break;
case V_102 :
F_37 ( V_6 -> V_96 , & V_44 -> V_48 ,
V_49 -> V_97 ,
V_44 -> V_47 * ( V_44 -> V_50 . V_52 >> 1 ) , 0 ,
V_44 -> V_47 , 0 ,
V_44 -> V_50 . V_52 >> 1 ) ;
break;
default:
F_38 () ;
}
}
F_6 ( 2 , L_7 ,
V_44 , V_44 -> V_50 . V_3 ,
V_6 -> V_51 , V_6 -> V_52 , V_6 -> V_55 -> V_82 , V_6 -> V_55 -> V_103 ,
( unsigned long ) V_44 -> V_48 . V_49 ) ;
V_44 -> V_50 . V_76 = V_104 ;
return 0 ;
V_94:
F_39 ( V_42 , V_44 ) ;
return V_87 ;
}
static void
F_40 ( struct V_79 * V_105 , struct V_84 * V_50 )
{
struct V_43 * V_44 = F_32 ( V_50 , struct V_43 , V_50 ) ;
struct V_43 * V_68 ;
struct V_7 * V_8 = V_105 -> V_81 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_41 * V_42 = & V_6 -> V_106 ;
V_44 -> V_48 . V_78 [ 0 ] = F_29 ( V_107 | V_108 | V_109 ) ;
V_44 -> V_48 . V_78 [ 1 ] = F_29 ( V_42 -> V_110 . V_49 ) ;
if ( ! F_24 ( & V_42 -> V_75 ) ) {
F_41 ( & V_44 -> V_50 . V_71 , & V_42 -> V_75 ) ;
V_44 -> V_50 . V_76 = V_111 ;
F_6 ( 2 , L_8 ,
V_44 , V_44 -> V_50 . V_3 ) ;
} else if ( F_24 ( & V_42 -> V_69 ) ) {
F_41 ( & V_44 -> V_50 . V_71 , & V_42 -> V_69 ) ;
F_19 ( V_6 , V_42 , V_44 ) ;
V_44 -> V_50 . V_76 = V_77 ;
V_44 -> V_60 = V_42 -> V_60 ++ ;
F_27 ( & V_42 -> V_72 , V_73 + V_74 ) ;
F_6 ( 2 , L_9 ,
V_44 , V_44 -> V_50 . V_3 ) ;
} else {
V_68 = F_25 ( V_42 -> V_69 . V_68 , struct V_43 , V_50 . V_71 ) ;
if ( V_68 -> V_50 . V_51 == V_44 -> V_50 . V_51 &&
V_68 -> V_50 . V_52 == V_44 -> V_50 . V_52 &&
V_68 -> V_55 == V_44 -> V_55 ) {
F_41 ( & V_44 -> V_50 . V_71 , & V_42 -> V_69 ) ;
V_44 -> V_50 . V_76 = V_77 ;
V_44 -> V_60 = V_42 -> V_60 ++ ;
V_68 -> V_48 . V_78 [ 1 ] = F_29 ( V_44 -> V_48 . V_49 ) ;
F_6 ( 2 , L_10 ,
V_44 , V_44 -> V_50 . V_3 ) ;
} else {
F_41 ( & V_44 -> V_50 . V_71 , & V_42 -> V_75 ) ;
V_44 -> V_50 . V_76 = V_111 ;
F_6 ( 2 , L_11 ,
V_44 , V_44 -> V_50 . V_3 ) ;
}
}
}
static void F_42 ( struct V_79 * V_42 , struct V_84 * V_50 )
{
struct V_43 * V_44 = F_32 ( V_50 , struct V_43 , V_50 ) ;
F_39 ( V_42 , V_44 ) ;
}
static struct V_79 * F_43 ( struct V_112 * V_112 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
struct V_7 * V_8 = V_112 -> V_115 ;
switch ( V_114 -> V_116 ) {
case V_117 :
return & V_8 -> V_106 ;
case V_118 :
return & V_8 -> V_119 ;
default:
F_38 () ;
return NULL ;
}
}
static int F_45 ( struct V_112 * V_112 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
switch ( V_114 -> V_116 ) {
case V_117 :
return V_120 ;
case V_118 :
return V_121 ;
default:
F_38 () ;
return 0 ;
}
}
static int F_46 ( struct V_112 * V_112 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
struct V_5 * V_6 = F_47 ( V_112 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_7 * V_8 ;
enum V_122 type = 0 ;
int V_123 = 0 ;
switch ( V_114 -> V_116 ) {
case V_117 :
type = V_124 ;
break;
case V_118 :
type = V_125 ;
break;
case V_126 :
V_123 = 1 ;
break;
}
F_6 ( 1 , L_12 ,
F_48 ( V_114 ) , V_123 , V_127 [ type ] ) ;
V_8 = F_49 ( sizeof( * V_8 ) , V_128 ) ;
if ( F_50 ( ! V_8 ) )
return - V_129 ;
F_51 ( & V_8 -> V_8 , V_114 ) ;
V_112 -> V_115 = V_8 ;
V_8 -> V_6 = V_6 ;
F_4 ( & V_11 -> V_13 ) ;
F_52 ( & V_8 -> V_106 , & V_130 ,
& V_6 -> V_96 -> V_6 , & V_6 -> V_131 ,
V_124 ,
V_100 ,
sizeof( struct V_43 ) ,
V_8 , NULL ) ;
F_52 ( & V_8 -> V_119 , & V_132 ,
& V_6 -> V_96 -> V_6 , & V_6 -> V_131 ,
V_125 ,
V_101 ,
sizeof( struct V_43 ) ,
V_8 , NULL ) ;
if ( V_114 -> V_116 == V_126 ) {
F_6 ( 1 , L_13 ) ;
F_14 ( V_22 , V_11 -> V_133 . V_123 . V_20 ) ;
F_14 ( V_23 , V_11 -> V_133 . V_123 . V_17 ) ;
F_14 ( V_24 , V_11 -> V_133 . V_123 . V_18 ) ;
F_14 ( V_25 , V_11 -> V_133 . V_123 . V_19 ) ;
if ( V_11 -> V_133 . V_123 . V_30 ) {
if ( V_11 -> V_31 ) {
F_17 ( V_11 , V_32 , V_33 ,
V_11 -> V_133 . V_123 . V_30 , 0 , 0 ) ;
}
V_11 -> V_36 = V_37 ;
F_18 ( V_11 ) ;
} else {
V_11 -> V_36 = V_134 ;
F_18 ( V_11 ) ;
F_53 ( V_11 , V_135 , 1 ) ;
}
F_17 ( V_11 , V_136 , V_137 ) ;
}
V_11 -> V_138 ++ ;
F_5 ( & V_11 -> V_13 ) ;
F_54 ( & V_8 -> V_8 ) ;
return 0 ;
}
static T_1
F_55 ( struct V_112 * V_112 , char T_2 * V_139 , T_3 V_60 , T_4 * V_140 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
struct V_7 * V_8 = V_112 -> V_115 ;
switch ( V_114 -> V_116 ) {
case V_117 :
if ( F_8 ( V_8 -> V_6 , V_120 ) )
return - V_141 ;
return F_56 ( & V_8 -> V_106 , V_139 , V_60 , V_140 ,
V_112 -> V_142 & V_143 ) ;
case V_118 :
if ( ! F_3 ( V_8 -> V_6 , V_8 , V_121 ) )
return - V_141 ;
return F_57 ( & V_8 -> V_119 , V_139 , V_60 , V_140 , 1 ,
V_112 -> V_142 & V_143 ) ;
default:
F_38 () ;
return 0 ;
}
}
static unsigned int
F_58 ( struct V_112 * V_112 , struct V_144 * V_145 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
struct V_7 * V_8 = V_112 -> V_115 ;
struct V_43 * V_44 ;
unsigned int V_87 = F_59 ( V_112 , V_145 ) ;
if ( V_114 -> V_116 == V_118 ) {
if ( ! F_3 ( V_8 -> V_6 , V_8 , V_121 ) )
return V_87 | V_146 ;
return V_87 | F_60 ( V_112 , & V_8 -> V_119 , V_145 ) ;
}
F_4 ( & V_8 -> V_106 . V_147 ) ;
if ( F_7 ( V_8 , V_120 ) ) {
if ( F_24 ( & V_8 -> V_106 . V_148 ) )
goto V_149;
V_44 = F_25 ( V_8 -> V_106 . V_148 . V_70 , struct V_43 , V_50 . V_148 ) ;
} else {
V_44 = (struct V_43 * ) V_8 -> V_106 . V_150 ;
if ( NULL == V_44 )
goto V_149;
}
F_61 ( V_112 , & V_44 -> V_50 . V_149 , V_145 ) ;
if ( V_44 -> V_50 . V_76 == V_151 ||
V_44 -> V_50 . V_76 == V_152 )
V_87 |= V_153 | V_154 ;
V_149:
F_5 ( & V_8 -> V_106 . V_147 ) ;
return V_87 ;
}
static int F_62 ( struct V_112 * V_112 )
{
struct V_7 * V_8 = V_112 -> V_115 ;
struct V_5 * V_6 = V_8 -> V_6 ;
if ( F_7 ( V_8 , V_155 ) ) {
F_9 ( V_6 , V_8 , V_155 ) ;
}
if ( F_7 ( V_8 , V_120 ) ) {
F_63 ( & V_8 -> V_106 ) ;
F_9 ( V_6 , V_8 , V_120 ) ;
}
if ( V_8 -> V_106 . V_150 ) {
F_42 ( & V_8 -> V_106 , V_8 -> V_106 . V_150 ) ;
F_64 ( V_8 -> V_106 . V_150 ) ;
}
if ( F_7 ( V_8 , V_121 ) ) {
F_65 ( & V_8 -> V_119 ) ;
F_9 ( V_6 , V_8 , V_121 ) ;
}
F_66 ( & V_8 -> V_106 ) ;
F_66 ( & V_8 -> V_119 ) ;
F_4 ( & V_6 -> V_11 -> V_13 ) ;
F_67 ( & V_8 -> V_8 ) ;
F_68 ( & V_8 -> V_8 ) ;
V_112 -> V_115 = NULL ;
F_64 ( V_8 ) ;
V_6 -> V_11 -> V_138 -- ;
if ( ! V_6 -> V_11 -> V_138 )
F_17 ( V_6 -> V_11 , V_11 , V_156 , 0 ) ;
F_5 ( & V_6 -> V_11 -> V_13 ) ;
return 0 ;
}
static int
F_69 ( struct V_112 * V_112 , struct V_157 * V_158 )
{
return F_70 ( F_43 ( V_112 ) , V_158 ) ;
}
static int F_71 ( struct V_159 * V_160 )
{
struct V_10 * V_11 =
F_32 ( V_160 -> V_161 , struct V_10 , V_162 ) ;
const struct V_163 * V_164 = V_160 -> V_165 ;
T_5 V_166 , V_167 ;
V_167 = V_164 -> V_167 ;
switch ( V_160 -> V_168 ) {
case V_169 :
V_166 = ( ( V_160 -> V_170 - V_164 -> V_171 ) << V_164 -> V_172 ) & V_164 -> V_167 ;
if ( V_11 -> V_89 & V_173 ) {
V_166 = V_166 << 8 | V_166 ;
} else {
V_166 = ( V_166 * 0x5a ) / 0x7f << 8 | V_166 ;
}
V_167 = 0xffff ;
break;
case V_174 :
V_166 = ( V_160 -> V_170 < 1 ? 0 : ( ( V_160 -> V_170 + 3 ) << 7 ) ) ;
F_13 ( V_28 , V_167 , V_166 ) ;
break;
case V_175 :
V_166 = ( ( V_160 -> V_170 - V_164 -> V_171 ) << V_164 -> V_172 ) & V_164 -> V_167 ;
break;
default:
V_166 = ( ( V_160 -> V_170 - V_164 -> V_171 ) << V_164 -> V_172 ) & V_164 -> V_167 ;
break;
}
F_6 ( 1 , L_14 ,
V_160 -> V_168 , V_160 -> V_103 , V_160 -> V_170 , V_164 -> V_176 , V_166 ,
V_167 , V_164 -> V_177 ? L_15 : L_16 ) ;
if ( V_164 -> V_177 )
F_72 ( V_164 -> V_177 , V_164 -> V_176 , V_167 , V_166 ) ;
else
F_13 ( V_164 -> V_176 , V_167 , V_166 ) ;
return 0 ;
}
static int F_73 ( struct V_159 * V_160 )
{
struct V_10 * V_11 =
F_32 ( V_160 -> V_161 , struct V_10 , V_178 ) ;
const struct V_163 * V_164 = V_160 -> V_165 ;
T_5 V_166 , V_167 ;
if ( V_11 -> V_31 ) {
switch ( V_160 -> V_168 ) {
case V_179 :
F_74 ( V_11 , V_160 -> V_168 , V_160 -> V_170 ) ;
break;
case V_180 :
F_74 ( V_11 , V_160 -> V_168 , ( V_160 -> V_170 ) ?
( 0x90 + V_160 -> V_170 ) << 8 : 0 ) ;
break;
case V_181 :
F_74 ( V_11 , V_160 -> V_168 , V_160 -> V_170 << 9 ) ;
break;
default:
break;
}
}
V_167 = V_164 -> V_167 ;
switch ( V_160 -> V_168 ) {
case V_181 :
V_166 = ( V_160 -> V_170 < 0x40 ) ? ( 0x7f - V_160 -> V_170 ) : ( V_160 -> V_170 - 0x40 ) ;
break;
case V_180 :
V_166 = 0x3f - ( V_160 -> V_170 & 0x3f ) ;
break;
default:
V_166 = ( ( V_160 -> V_170 - V_164 -> V_171 ) << V_164 -> V_172 ) & V_164 -> V_167 ;
break;
}
F_6 ( 1 , L_14 ,
V_160 -> V_168 , V_160 -> V_103 , V_160 -> V_170 , V_164 -> V_176 , V_166 ,
V_167 , V_164 -> V_177 ? L_15 : L_16 ) ;
if ( V_164 -> V_177 )
F_72 ( V_164 -> V_177 , V_164 -> V_176 , V_167 , V_166 ) ;
else
F_13 ( V_164 -> V_176 , V_167 , V_166 ) ;
return 0 ;
}
static int F_75 ( struct V_112 * V_112 , void * V_165 ,
struct V_182 * V_183 )
{
struct V_7 * V_8 = V_165 ;
struct V_5 * V_6 = V_8 -> V_6 ;
V_183 -> V_55 . V_184 . V_51 = V_6 -> V_51 ;
V_183 -> V_55 . V_184 . V_52 = V_6 -> V_52 ;
V_183 -> V_55 . V_184 . V_53 = V_8 -> V_106 . V_53 ;
V_183 -> V_55 . V_184 . V_185 = V_6 -> V_55 -> V_2 ;
V_183 -> V_55 . V_184 . V_186 =
( V_183 -> V_55 . V_184 . V_51 * V_6 -> V_55 -> V_82 ) >> 3 ;
V_183 -> V_55 . V_184 . V_187 =
V_183 -> V_55 . V_184 . V_52 * V_183 -> V_55 . V_184 . V_186 ;
V_183 -> V_55 . V_184 . V_188 = V_189 ;
return 0 ;
}
static int F_76 ( struct V_112 * V_112 , void * V_165 ,
struct V_182 * V_183 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
const struct V_1 * V_55 ;
enum V_85 V_53 ;
unsigned int V_190 , V_191 ;
V_55 = F_1 ( V_183 -> V_55 . V_184 . V_185 ) ;
if ( NULL == V_55 )
return - V_90 ;
V_53 = V_183 -> V_55 . V_184 . V_53 ;
V_190 = F_34 ( V_11 -> V_89 ) ;
V_191 = F_35 ( V_11 -> V_89 ) ;
if ( V_192 == V_53 ) {
V_53 = ( V_183 -> V_55 . V_184 . V_52 > V_191 / 2 )
? V_100
: V_99 ;
}
switch ( V_53 ) {
case V_95 :
case V_99 :
V_191 = V_191 / 2 ;
break;
case V_100 :
break;
default:
return - V_90 ;
}
V_183 -> V_55 . V_184 . V_53 = V_53 ;
F_77 ( & V_183 -> V_55 . V_184 . V_51 , 48 , V_190 , 2 ,
& V_183 -> V_55 . V_184 . V_52 , 32 , V_191 , 0 , 0 ) ;
V_183 -> V_55 . V_184 . V_186 =
( V_183 -> V_55 . V_184 . V_51 * V_55 -> V_82 ) >> 3 ;
V_183 -> V_55 . V_184 . V_187 =
V_183 -> V_55 . V_184 . V_52 * V_183 -> V_55 . V_184 . V_186 ;
return 0 ;
}
static int F_78 ( struct V_112 * V_112 , void * V_165 ,
struct V_182 * V_183 )
{
struct V_7 * V_8 = V_165 ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_193 = F_76 ( V_112 , V_165 , V_183 ) ;
if ( 0 != V_193 )
return V_193 ;
V_6 -> V_55 = F_1 ( V_183 -> V_55 . V_184 . V_185 ) ;
V_6 -> V_51 = V_183 -> V_55 . V_184 . V_51 ;
V_6 -> V_52 = V_183 -> V_55 . V_184 . V_52 ;
V_8 -> V_106 . V_53 = V_183 -> V_55 . V_184 . V_53 ;
return 0 ;
}
void F_79 ( struct V_112 * V_112 , struct V_10 * V_11 ,
struct V_194 * V_195 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
F_80 ( V_195 -> V_196 , V_11 -> V_133 . V_103 , sizeof( V_195 -> V_196 ) ) ;
V_195 -> V_197 = V_198 | V_199 ;
if ( V_98 != V_11 -> V_133 . V_200 )
V_195 -> V_197 |= V_201 ;
switch ( V_114 -> V_116 ) {
case V_126 :
V_195 -> V_197 = V_202 | V_201 ;
break;
case V_117 :
V_195 -> V_197 |= V_203 ;
break;
case V_118 :
V_195 -> V_197 |= V_204 ;
break;
}
V_195 -> V_205 = V_195 -> V_197 | V_203 |
V_204 | V_206 ;
if ( V_11 -> V_133 . V_123 . type == V_207 )
V_195 -> V_205 |= V_202 ;
}
static int F_81 ( struct V_112 * V_112 , void * V_165 ,
struct V_194 * V_195 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_165 ) -> V_6 ;
struct V_10 * V_11 = V_6 -> V_11 ;
strcpy ( V_195 -> V_208 , L_17 ) ;
sprintf ( V_195 -> V_209 , L_18 , F_82 ( V_6 -> V_96 ) ) ;
F_79 ( V_112 , V_11 , V_195 ) ;
return 0 ;
}
static int F_83 ( struct V_112 * V_112 , void * V_165 ,
struct V_210 * V_183 )
{
if ( F_50 ( V_183 -> V_211 >= F_2 ( V_4 ) ) )
return - V_90 ;
F_80 ( V_183 -> V_212 , V_4 [ V_183 -> V_211 ] . V_103 , sizeof( V_183 -> V_212 ) ) ;
V_183 -> V_185 = V_4 [ V_183 -> V_211 ] . V_2 ;
return 0 ;
}
static int F_84 ( struct V_112 * V_112 , void * V_165 , struct V_213 * V_214 )
{
return F_85 ( F_43 ( V_112 ) , V_214 ) ;
}
static int F_86 ( struct V_112 * V_112 , void * V_165 , struct V_215 * V_214 )
{
return F_87 ( F_43 ( V_112 ) , V_214 ) ;
}
static int F_88 ( struct V_112 * V_112 , void * V_165 , struct V_215 * V_214 )
{
return F_89 ( F_43 ( V_112 ) , V_214 ) ;
}
static int F_90 ( struct V_112 * V_112 , void * V_165 , struct V_215 * V_214 )
{
return F_91 ( F_43 ( V_112 ) , V_214 ,
V_112 -> V_142 & V_143 ) ;
}
static int F_92 ( struct V_112 * V_112 , void * V_165 , enum V_122 V_3 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
struct V_7 * V_8 = V_165 ;
struct V_5 * V_6 = V_8 -> V_6 ;
if ( ( V_114 -> V_116 == V_117 && V_3 != V_124 ) ||
( V_114 -> V_116 == V_118 && V_3 != V_125 ) )
return - V_90 ;
if ( F_50 ( ! F_3 ( V_6 , V_8 , F_45 ( V_112 ) ) ) )
return - V_141 ;
return F_93 ( F_43 ( V_112 ) ) ;
}
static int F_94 ( struct V_112 * V_112 , void * V_165 , enum V_122 V_3 )
{
struct V_113 * V_114 = F_44 ( V_112 ) ;
struct V_7 * V_8 = V_165 ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_193 , V_216 ;
if ( ( V_114 -> V_116 == V_117 && V_3 != V_124 ) ||
( V_114 -> V_116 == V_118 && V_3 != V_125 ) )
return - V_90 ;
V_216 = F_45 ( V_112 ) ;
V_193 = F_95 ( F_43 ( V_112 ) ) ;
if ( V_193 < 0 )
return V_193 ;
F_9 ( V_6 , V_8 , V_216 ) ;
return 0 ;
}
static int F_96 ( struct V_112 * V_112 , void * V_165 , T_6 * V_89 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
* V_89 = V_11 -> V_89 ;
return 0 ;
}
static int F_97 ( struct V_112 * V_112 , void * V_165 , T_6 V_217 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
F_4 ( & V_11 -> V_13 ) ;
F_98 ( V_11 , V_217 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
int F_99 ( struct V_10 * V_11 , struct V_218 * V_3 )
{
static const char * const V_219 [] = {
[ V_220 ] = L_19 ,
[ V_221 ] = L_20 ,
[ V_222 ] = L_21 ,
[ V_223 ] = L_22 ,
[ V_26 ] = L_23 ,
[ V_34 ] = L_24 ,
[ V_35 ] = L_25 ,
[ V_224 ] = L_26 ,
[ V_225 ] = L_27 ,
} ;
unsigned int V_226 = V_3 -> V_211 ;
if ( V_226 >= 4 )
return - V_90 ;
if ( 0 == F_12 ( V_226 ) . type )
return - V_90 ;
V_3 -> type = V_227 ;
strcpy ( V_3 -> V_103 , V_219 [ F_12 ( V_226 ) . type ] ) ;
if ( ( V_34 == F_12 ( V_226 ) . type ) ||
( V_35 == F_12 ( V_226 ) . type ) ) {
V_3 -> type = V_228 ;
}
V_3 -> V_229 = V_230 ;
return 0 ;
}
static int F_100 ( struct V_112 * V_112 , void * V_165 ,
struct V_218 * V_3 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
return F_99 ( V_11 , V_3 ) ;
}
static int F_101 ( struct V_112 * V_112 , void * V_165 , unsigned int * V_3 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
* V_3 = V_11 -> V_15 ;
return 0 ;
}
static int F_102 ( struct V_112 * V_112 , void * V_165 , unsigned int V_3 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
if ( V_3 >= 4 )
return - V_90 ;
if ( 0 == F_12 ( V_3 ) . type )
return - V_90 ;
F_4 ( & V_11 -> V_13 ) ;
F_103 ( V_11 ) ;
F_11 ( V_11 , V_3 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_104 ( struct V_112 * V_112 , void * V_165 ,
struct V_231 * V_232 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
T_5 V_176 ;
if ( F_50 ( V_98 == V_11 -> V_133 . V_200 ) )
return - V_90 ;
if ( 0 != V_232 -> V_211 )
return - V_90 ;
strcpy ( V_232 -> V_103 , L_24 ) ;
V_232 -> V_233 = V_234 ;
V_232 -> V_235 = 0xffffffffUL ;
F_17 ( V_11 , V_136 , V_236 , V_232 ) ;
F_105 ( V_11 , V_232 ) ;
V_176 = F_106 ( V_237 ) ;
V_232 -> signal = ( V_176 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_107 ( struct V_112 * V_112 , void * V_165 ,
const struct V_231 * V_232 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
if ( V_98 == V_11 -> V_133 . V_200 )
return - V_90 ;
if ( 0 != V_232 -> V_211 )
return - V_90 ;
F_53 ( V_11 , V_232 -> V_238 , 1 ) ;
return 0 ;
}
static int F_108 ( struct V_112 * V_112 , void * V_165 ,
struct V_239 * V_183 )
{
struct V_7 * V_8 = V_165 ;
struct V_10 * V_11 = V_8 -> V_6 -> V_11 ;
if ( F_50 ( V_98 == V_11 -> V_133 . V_200 ) )
return - V_90 ;
if ( V_183 -> V_136 )
return - V_90 ;
V_183 -> V_240 = V_11 -> V_241 ;
F_17 ( V_11 , V_136 , V_242 , V_183 ) ;
return 0 ;
}
int F_109 ( struct V_10 * V_11 ,
const struct V_239 * V_183 )
{
struct V_239 V_243 = * V_183 ;
if ( F_50 ( V_98 == V_11 -> V_133 . V_200 ) )
return - V_90 ;
if ( F_50 ( V_183 -> V_136 != 0 ) )
return - V_90 ;
F_4 ( & V_11 -> V_13 ) ;
F_103 ( V_11 ) ;
F_17 ( V_11 , V_136 , V_244 , V_183 ) ;
F_17 ( V_11 , V_136 , V_242 , & V_243 ) ;
V_11 -> V_241 = V_243 . V_240 ;
F_110 ( 10 ) ;
F_18 ( V_11 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_111 ( struct V_112 * V_112 , void * V_165 ,
const struct V_239 * V_183 )
{
struct V_7 * V_8 = V_165 ;
struct V_10 * V_11 = V_8 -> V_6 -> V_11 ;
return F_109 ( V_11 , V_183 ) ;
}
static int F_112 ( struct V_112 * V_112 , void * V_165 ,
struct V_245 * V_246 )
{
if ( ! F_113 ( & V_246 -> V_247 ) )
return - V_90 ;
V_246 -> V_248 = 0 ;
V_246 -> V_249 = V_250 ;
return 0 ;
}
static int F_114 ( struct V_112 * V_112 , void * V_8 ,
struct V_251 * V_176 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_8 ) -> V_6 -> V_11 ;
if ( ! F_113 ( & V_176 -> V_247 ) )
return - V_90 ;
V_176 -> V_170 = F_106 ( V_176 -> V_176 & 0xffffff ) ;
V_176 -> V_80 = 4 ;
return 0 ;
}
static int F_115 ( struct V_112 * V_112 , void * V_8 ,
const struct V_251 * V_176 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_8 ) -> V_6 -> V_11 ;
if ( ! F_113 ( & V_176 -> V_247 ) )
return - V_90 ;
F_14 ( V_176 -> V_176 & 0xffffff , V_176 -> V_170 ) ;
return 0 ;
}
static int F_116 ( struct V_112 * V_112 , void * V_165 ,
struct V_231 * V_232 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
if ( F_50 ( V_232 -> V_211 > 0 ) )
return - V_90 ;
strcpy ( V_232 -> V_103 , L_28 ) ;
F_17 ( V_11 , V_136 , V_236 , V_232 ) ;
return 0 ;
}
static int F_117 ( struct V_112 * V_112 , void * V_165 ,
const struct V_231 * V_232 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_165 ) -> V_6 -> V_11 ;
if ( 0 != V_232 -> V_211 )
return - V_90 ;
F_17 ( V_11 , V_136 , V_252 , V_232 ) ;
return 0 ;
}
static void F_118 ( unsigned long V_139 )
{
struct V_5 * V_6 = (struct V_5 * ) V_139 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_41 * V_42 = & V_6 -> V_106 ;
struct V_43 * V_44 ;
unsigned long V_253 ;
F_119 ( V_11 , & V_45 [ V_46 ] ) ;
F_16 ( V_67 , 0x11 ) ;
F_16 ( V_65 , 0x06 ) ;
F_120 ( & V_6 -> V_131 , V_253 ) ;
while ( ! F_24 ( & V_42 -> V_69 ) ) {
V_44 = F_25 ( V_42 -> V_69 . V_70 , struct V_43 , V_50 . V_71 ) ;
F_121 ( & V_44 -> V_50 . V_71 ) ;
V_44 -> V_50 . V_76 = V_152 ;
F_122 ( & V_44 -> V_50 . V_149 ) ;
F_123 ( L_29 , V_11 -> V_103 ,
V_44 , V_44 -> V_50 . V_3 , ( unsigned long ) V_44 -> V_48 . V_49 ) ;
}
F_23 ( V_6 , V_42 ) ;
F_124 ( & V_6 -> V_131 , V_253 ) ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
T_5 V_254 , V_167 , V_60 ;
V_254 = F_106 ( V_255 ) ;
V_167 = F_106 ( V_64 ) ;
if ( 0 == ( V_254 & V_167 ) )
return;
F_14 ( V_255 , V_254 ) ;
if ( V_256 || ( V_254 & V_167 & ~ 0xff ) )
F_126 ( V_11 -> V_103 , L_30 ,
V_257 , F_2 ( V_257 ) ,
V_254 , V_167 ) ;
if ( V_254 & ( 1 << 16 ) ) {
F_123 ( V_258 L_31 , V_11 -> V_103 ) ;
F_16 ( V_67 , 0x11 ) ;
F_16 ( V_65 , 0x06 ) ;
F_119 ( V_11 , & V_45 [ V_46 ] ) ;
}
if ( V_254 & 0x01 ) {
F_127 ( & V_6 -> V_131 ) ;
V_60 = F_106 ( V_259 ) ;
F_128 ( V_11 , & V_6 -> V_106 , V_60 ) ;
F_129 ( & V_6 -> V_131 ) ;
}
if ( V_254 & 0x08 ) {
F_127 ( & V_6 -> V_131 ) ;
V_60 = F_106 ( V_260 ) ;
F_128 ( V_11 , & V_6 -> V_119 , V_60 ) ;
F_129 ( & V_6 -> V_131 ) ;
}
if ( V_254 & 0x10 ) {
F_6 ( 2 , L_32 ) ;
F_127 ( & V_6 -> V_131 ) ;
F_23 ( V_6 , & V_6 -> V_106 ) ;
F_129 ( & V_6 -> V_131 ) ;
}
if ( V_254 & 0x80 ) {
F_6 ( 2 , L_33 ) ;
F_127 ( & V_6 -> V_131 ) ;
F_130 ( V_6 , & V_6 -> V_119 ) ;
F_129 ( & V_6 -> V_131 ) ;
}
}
static T_7 F_131 ( int V_261 , void * V_262 )
{
struct V_5 * V_6 = V_262 ;
struct V_10 * V_11 = V_6 -> V_11 ;
T_5 V_254 ;
int V_263 , V_264 = 0 ;
for ( V_263 = 0 ; V_263 < 10 ; V_263 ++ ) {
V_254 = F_106 ( V_265 ) &
( V_11 -> V_62 | V_63 ) ;
if ( 0 == V_254 )
goto V_266;
F_14 ( V_265 , V_254 ) ;
V_264 = 1 ;
if ( V_254 & V_11 -> V_62 )
F_132 ( V_11 , V_254 ) ;
if ( V_254 & V_63 )
F_125 ( V_6 ) ;
}
if ( 10 == V_263 ) {
F_123 ( V_258 L_34 ,
V_11 -> V_103 ) ;
F_14 ( V_61 , 0 ) ;
}
V_266:
return F_133 ( V_264 ) ;
}
static void F_134 ( struct V_5 * V_6 )
{
if ( V_6 -> V_267 ) {
if ( F_135 ( V_6 -> V_267 ) )
F_136 ( V_6 -> V_267 ) ;
else
F_137 ( V_6 -> V_267 ) ;
V_6 -> V_267 = NULL ;
}
if ( V_6 -> V_268 ) {
if ( F_135 ( V_6 -> V_268 ) )
F_136 ( V_6 -> V_268 ) ;
else
F_137 ( V_6 -> V_268 ) ;
V_6 -> V_268 = NULL ;
}
if ( V_6 -> V_269 ) {
if ( F_135 ( V_6 -> V_269 ) )
F_136 ( V_6 -> V_269 ) ;
else
F_137 ( V_6 -> V_269 ) ;
V_6 -> V_269 = NULL ;
}
}
static int F_138 ( struct V_270 * V_270 ,
const struct V_271 * V_272 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_193 ;
int V_3 ;
V_6 = F_49 ( sizeof( * V_6 ) , V_128 ) ;
if ( NULL == V_6 )
return - V_129 ;
V_6 -> V_96 = V_270 ;
if ( F_139 ( V_270 ) ) {
V_193 = - V_273 ;
goto V_274;
}
V_11 = F_140 ( V_6 -> V_96 ) ;
if ( NULL == V_11 ) {
V_193 = - V_90 ;
goto V_274;
}
V_6 -> V_11 = V_11 ;
V_6 -> V_275 = V_270 -> V_248 ;
F_141 ( V_270 , V_276 , & V_6 -> V_277 ) ;
F_123 ( V_278 L_35
L_36 , V_11 -> V_103 ,
F_82 ( V_270 ) , V_6 -> V_275 , V_270 -> V_261 ,
V_6 -> V_277 , ( unsigned long long ) F_142 ( V_270 , 0 ) ) ;
F_143 ( V_270 ) ;
if ( ! F_144 ( V_270 , F_145 ( 32 ) ) ) {
F_123 ( L_37 , V_11 -> V_103 ) ;
V_193 = - V_273 ;
goto V_279;
}
F_146 ( & V_6 -> V_131 ) ;
V_11 -> V_89 = V_280 ;
F_147 ( & V_6 -> V_106 . V_69 ) ;
F_147 ( & V_6 -> V_106 . V_75 ) ;
V_6 -> V_106 . V_72 . V_281 = F_118 ;
V_6 -> V_106 . V_72 . V_139 = ( unsigned long ) V_6 ;
F_148 ( & V_6 -> V_106 . V_72 ) ;
F_149 ( V_6 -> V_96 , & V_6 -> V_106 . V_110 ,
V_67 , 0x11 , 0x00 ) ;
F_147 ( & V_6 -> V_119 . V_69 ) ;
F_147 ( & V_6 -> V_119 . V_75 ) ;
V_6 -> V_119 . V_72 . V_281 = V_282 ;
V_6 -> V_119 . V_72 . V_139 = ( unsigned long ) V_6 ;
F_148 ( & V_6 -> V_119 . V_72 ) ;
F_149 ( V_6 -> V_96 , & V_6 -> V_119 . V_110 ,
V_67 , 0x88 , 0x00 ) ;
V_193 = F_150 ( V_270 -> V_261 , F_131 ,
V_283 | V_284 , V_11 -> V_103 , V_6 ) ;
if ( V_193 < 0 ) {
F_123 ( V_285 L_38 ,
V_11 -> V_103 , V_270 -> V_261 ) ;
goto V_279;
}
F_15 ( V_61 , V_11 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_286 ; V_3 ++ ) {
const struct V_163 * V_164 = & V_287 [ V_3 ] ;
struct V_159 * V_288 ;
V_288 = F_151 ( & V_11 -> V_178 , & V_289 ,
V_164 -> V_168 , V_164 -> V_290 , V_164 -> V_291 , V_164 -> V_292 , V_164 -> V_293 ) ;
if ( V_288 == NULL ) {
V_193 = V_11 -> V_178 . error ;
goto V_279;
}
V_288 -> V_165 = ( void * ) V_164 ;
}
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
const struct V_163 * V_164 = & V_295 [ V_3 ] ;
struct V_159 * V_288 ;
V_288 = F_151 ( & V_11 -> V_162 , & V_296 ,
V_164 -> V_168 , V_164 -> V_290 , V_164 -> V_291 , V_164 -> V_292 , V_164 -> V_293 ) ;
if ( V_288 == NULL ) {
V_193 = V_11 -> V_162 . error ;
goto V_279;
}
V_288 -> V_165 = ( void * ) V_164 ;
if ( V_288 -> V_168 == V_175 )
V_11 -> V_297 = V_288 ;
}
F_152 ( & V_11 -> V_162 , & V_11 -> V_178 , NULL ) ;
if ( V_11 -> V_133 . V_298 == V_299 ) {
struct V_300 V_301 = {
. type = L_39 ,
. V_302 = 0x36 >> 1 ,
. V_303 = & V_11 -> V_304 ,
} ;
struct V_305 * V_306 ;
if ( V_11 -> V_307 == V_308 )
V_11 -> V_304 . V_309 = true ;
else
V_11 -> V_304 . V_309 = false ;
V_306 = F_153 ( & V_11 -> V_310 , & V_11 -> V_311 ,
& V_301 , NULL ) ;
if ( V_306 != NULL ) {
V_11 -> V_31 = V_306 ;
V_306 -> V_312 = V_313 ;
}
}
if ( V_11 -> V_133 . V_298 == V_314 ) {
F_154 ( & V_11 -> V_310 , & V_11 -> V_311 ,
L_40 , 0 , F_155 ( 0xb0 >> 1 ) ) ;
}
switch ( V_11 -> V_307 ) {
case V_315 :
case V_316 : {
static const struct V_300 V_317 = {
F_156 ( L_41 , 0x6f )
} ;
F_157 ( L_42 ) ;
V_11 -> V_318 = F_158 ( & V_11 -> V_311 , & V_317 ) ;
}
case V_319 :
F_157 ( L_43 ) ;
}
F_159 ( V_270 , V_6 ) ;
V_6 -> V_51 = 320 ;
V_6 -> V_52 = 240 ;
V_6 -> V_55 = F_1 ( V_320 ) ;
F_4 ( & V_11 -> V_13 ) ;
F_98 ( V_11 , V_11 -> V_89 ) ;
F_160 ( & V_11 -> V_162 ) ;
F_160 ( & V_11 -> V_178 ) ;
F_11 ( V_11 , 0 ) ;
V_6 -> V_269 = F_161 ( V_11 , V_6 -> V_96 ,
& V_321 , L_44 ) ;
F_162 ( V_6 -> V_269 , V_6 ) ;
V_6 -> V_269 -> V_322 = & V_11 -> V_162 ;
V_193 = F_163 ( V_6 -> V_269 , V_117 ,
V_323 [ V_11 -> V_324 ] ) ;
if ( V_193 < 0 ) {
F_123 ( V_285 L_45 ,
V_11 -> V_103 ) ;
goto V_325;
}
F_123 ( V_278 L_46 ,
V_11 -> V_103 , F_48 ( V_6 -> V_269 ) ) ;
V_6 -> V_268 = F_161 ( V_11 , V_6 -> V_96 , & V_326 , L_47 ) ;
F_162 ( V_6 -> V_268 , V_6 ) ;
V_193 = F_163 ( V_6 -> V_268 , V_118 ,
V_327 [ V_11 -> V_324 ] ) ;
if ( V_193 < 0 ) {
F_123 ( V_285 L_48 ,
V_11 -> V_103 ) ;
goto V_325;
}
F_123 ( V_278 L_49 ,
V_11 -> V_103 , F_48 ( V_6 -> V_268 ) ) ;
if ( V_11 -> V_133 . V_123 . type == V_207 ) {
V_6 -> V_267 = F_161 ( V_11 , V_6 -> V_96 ,
& V_328 , L_50 ) ;
F_162 ( V_6 -> V_267 , V_6 ) ;
V_6 -> V_267 -> V_322 = & V_11 -> V_178 ;
V_193 = F_163 ( V_6 -> V_267 , V_126 ,
V_329 [ V_11 -> V_324 ] ) ;
if ( V_193 < 0 ) {
F_123 ( V_285 L_51 ,
V_11 -> V_103 ) ;
goto V_325;
}
F_123 ( V_278 L_49 ,
V_11 -> V_103 , F_48 ( V_6 -> V_267 ) ) ;
}
if ( V_11 -> V_133 . V_200 != V_330 ) {
V_11 -> V_331 = F_164 ( V_332 , V_11 , L_52 ) ;
if ( F_165 ( V_11 -> V_331 ) ) {
V_193 = F_166 ( V_11 -> V_331 ) ;
F_123 ( V_285 L_53 ,
V_11 -> V_103 , V_193 ) ;
}
}
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
V_325:
F_134 ( V_6 ) ;
F_167 ( V_270 -> V_261 , V_6 ) ;
F_5 ( & V_11 -> V_13 ) ;
V_279:
F_168 ( V_11 , V_6 -> V_96 ) ;
V_274:
F_64 ( V_6 ) ;
return V_193 ;
}
static void F_169 ( struct V_270 * V_270 )
{
struct V_5 * V_6 = F_170 ( V_270 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
if ( V_11 -> V_331 ) {
F_171 ( V_11 -> V_331 ) ;
V_11 -> V_331 = NULL ;
}
if ( V_11 -> V_333 )
F_172 ( V_11 ) ;
F_173 ( V_11 ) ;
F_174 ( V_270 ) ;
F_167 ( V_270 -> V_261 , V_6 ) ;
F_134 ( V_6 ) ;
F_159 ( V_270 , NULL ) ;
F_175 ( V_6 -> V_96 , & V_6 -> V_106 . V_110 ) ;
F_168 ( V_11 , V_6 -> V_96 ) ;
F_64 ( V_6 ) ;
}
static int F_176 ( struct V_270 * V_270 , T_8 V_76 )
{
struct V_5 * V_6 = F_170 ( V_270 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned long V_253 ;
F_120 ( & V_6 -> V_131 , V_253 ) ;
if ( ! F_24 ( & V_6 -> V_106 . V_69 ) ) {
F_123 ( L_54 , V_11 -> V_103 ) ;
F_22 ( V_6 ) ;
F_177 ( & V_6 -> V_106 . V_72 ) ;
}
if ( ! F_24 ( & V_6 -> V_119 . V_69 ) ) {
F_123 ( L_55 , V_11 -> V_103 ) ;
F_178 ( V_6 ) ;
F_177 ( & V_6 -> V_119 . V_72 ) ;
}
F_124 ( & V_6 -> V_131 , V_253 ) ;
if ( V_11 -> V_333 )
F_172 ( V_11 ) ;
F_173 ( V_11 ) ;
F_179 ( V_270 ) ;
if ( 0 != F_180 ( V_270 , F_181 ( V_270 , V_76 ) ) ) {
F_174 ( V_270 ) ;
V_6 -> V_76 . V_334 = 1 ;
}
return 0 ;
}
static int F_182 ( struct V_270 * V_270 )
{
struct V_5 * V_6 = F_170 ( V_270 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
unsigned long V_253 ;
int V_193 ;
if ( V_6 -> V_76 . V_334 ) {
V_193 = F_139 ( V_270 ) ;
if ( V_193 ) {
F_123 ( V_285 L_56 ,
V_11 -> V_103 ) ;
return V_193 ;
}
V_6 -> V_76 . V_334 = 0 ;
}
V_193 = F_180 ( V_270 , V_335 ) ;
if ( V_193 ) {
F_123 ( V_285 L_57 , V_11 -> V_103 ) ;
F_174 ( V_270 ) ;
V_6 -> V_76 . V_334 = 1 ;
return V_193 ;
}
F_183 ( V_270 ) ;
F_184 ( V_11 ) ;
if ( V_11 -> V_333 )
F_185 ( V_11 ) ;
F_15 ( V_61 , V_11 -> V_62 ) ;
F_120 ( & V_6 -> V_131 , V_253 ) ;
if ( ! F_24 ( & V_6 -> V_106 . V_69 ) ) {
F_123 ( L_58 , V_11 -> V_103 ) ;
F_23 ( V_6 , & V_6 -> V_106 ) ;
}
if ( ! F_24 ( & V_6 -> V_119 . V_69 ) ) {
F_123 ( L_59 , V_11 -> V_103 ) ;
F_130 ( V_6 , & V_6 -> V_119 ) ;
}
F_124 ( & V_6 -> V_131 , V_253 ) ;
return 0 ;
}
static int T_9 F_186 ( void )
{
F_123 ( V_278 L_60 ,
V_336 ) ;
return F_187 ( & V_337 ) ;
}
static void T_10 F_188 ( void )
{
F_189 ( & V_337 ) ;
}
