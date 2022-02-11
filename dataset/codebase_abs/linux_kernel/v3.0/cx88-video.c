static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
int V_3 ;
if ( V_8 -> V_9 < V_10 ||
V_8 -> V_9 >= V_11 )
return - V_12 ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ )
if ( V_14 [ V_3 ] . V_15 . V_9 == V_8 -> V_9 )
break;
if ( V_3 == V_13 ) {
* V_8 = V_16 ;
return 0 ;
}
* V_8 = V_14 [ V_3 ] . V_15 ;
if ( V_14 [ V_3 ] . V_15 . V_9 == V_17 &&
V_6 -> V_18 & V_19 )
V_8 -> V_20 |= V_21 ;
return 0 ;
}
static int F_4 ( struct V_22 * V_23 , struct V_24 * V_25 , unsigned int V_26 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
if ( V_25 -> V_27 & V_26 )
return 1 ;
F_5 ( & V_6 -> V_28 ) ;
if ( V_23 -> V_27 & V_26 ) {
F_6 ( & V_6 -> V_28 ) ;
return 0 ;
}
V_25 -> V_27 |= V_26 ;
V_23 -> V_27 |= V_26 ;
F_7 ( 1 , L_1 , V_26 ) ;
F_6 ( & V_6 -> V_28 ) ;
return 1 ;
}
static
int F_8 ( struct V_24 * V_25 , unsigned int V_26 )
{
return ( V_25 -> V_27 & V_26 ) ;
}
static
int F_9 ( struct V_22 * V_23 , unsigned int V_26 )
{
return ( V_23 -> V_27 & V_26 ) ;
}
static
void F_10 ( struct V_22 * V_23 , struct V_24 * V_25 , unsigned int V_29 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
F_11 ( ( V_25 -> V_27 & V_29 ) != V_29 ) ;
F_5 ( & V_6 -> V_28 ) ;
V_25 -> V_27 &= ~ V_29 ;
V_23 -> V_27 &= ~ V_29 ;
F_7 ( 1 , L_2 , V_29 ) ;
F_6 ( & V_6 -> V_28 ) ;
}
int F_12 ( struct V_5 * V_6 , unsigned int V_30 )
{
F_7 ( 1 , L_3 ,
V_30 , F_13 ( V_30 ) . V_31 ,
F_13 ( V_30 ) . V_32 , F_13 ( V_30 ) . V_33 ,
F_13 ( V_30 ) . V_34 , F_13 ( V_30 ) . V_35 ) ;
V_6 -> V_30 = V_30 ;
F_14 ( V_36 , 0x03 << 14 , F_13 ( V_30 ) . V_31 << 14 ) ;
F_15 ( V_37 , F_13 ( V_30 ) . V_35 ) ;
F_15 ( V_38 , F_13 ( V_30 ) . V_32 ) ;
F_15 ( V_39 , F_13 ( V_30 ) . V_33 ) ;
F_15 ( V_40 , F_13 ( V_30 ) . V_34 ) ;
switch ( F_13 ( V_30 ) . type ) {
case V_41 :
F_16 ( V_42 , 0x00000001 ) ;
F_16 ( V_36 , 0x00010010 ) ;
F_16 ( V_43 , 0x00002020 ) ;
F_16 ( V_44 , 0x00002020 ) ;
break;
default:
F_17 ( V_42 , 0x00000001 ) ;
F_17 ( V_36 , 0x00010010 ) ;
F_17 ( V_43 , 0x00002020 ) ;
F_17 ( V_44 , 0x00002020 ) ;
break;
}
if ( F_13 ( V_30 ) . V_45 ) {
if ( V_6 -> V_46 . V_47 &&
V_6 -> V_46 . V_47 == V_48 ) {
F_18 ( V_6 , V_49 , V_50 ,
F_13 ( V_30 ) . V_45 , 0 , 0 ) ;
}
if ( F_13 ( V_30 ) . type != V_51 &&
F_13 ( V_30 ) . type != V_52 ) {
V_6 -> V_53 = V_54 ;
F_19 ( V_6 ) ;
} else {
F_15 ( V_55 , 0x0 ) ;
F_17 ( V_56 , V_57 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_22 * V_23 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
F_21 ( V_6 , & V_62 [ V_63 ] ,
V_61 -> V_64 , V_61 -> V_65 . V_66 ) ;
F_22 ( V_6 , V_61 -> V_67 . V_68 , V_61 -> V_67 . V_69 , V_61 -> V_67 . V_70 ) ;
F_15 ( V_71 , V_61 -> V_72 -> V_73 | V_74 ) ;
F_15 ( V_75 , V_76 ) ;
V_59 -> V_77 = 1 ;
F_16 ( V_78 , V_6 -> V_79 | V_80 ) ;
F_16 ( V_81 , 0x0f0011 ) ;
F_16 ( V_82 , 0x06 ) ;
F_16 ( V_83 , ( 1 << 5 ) ) ;
F_16 ( V_84 , 0x11 ) ;
return 0 ;
}
static int F_23 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
F_17 ( V_84 , 0x11 ) ;
F_17 ( V_82 , 0x06 ) ;
F_17 ( V_78 , V_80 ) ;
F_17 ( V_81 , 0x0f0011 ) ;
return 0 ;
}
static int F_24 ( struct V_22 * V_23 ,
struct V_58 * V_59 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_60 * V_61 , * V_85 ;
if ( ! F_25 ( & V_59 -> V_86 ) ) {
V_61 = F_26 ( V_59 -> V_86 . V_87 , struct V_60 , V_67 . V_88 ) ;
F_7 ( 2 , L_4 ,
V_61 , V_61 -> V_67 . V_3 ) ;
F_20 ( V_23 , V_59 , V_61 ) ;
F_27 (buf, &q->active, vb.queue)
V_61 -> V_77 = V_59 -> V_77 ++ ;
F_28 ( & V_59 -> V_89 , V_90 + V_91 ) ;
return 0 ;
}
V_85 = NULL ;
for (; ; ) {
if ( F_25 ( & V_59 -> V_92 ) )
return 0 ;
V_61 = F_26 ( V_59 -> V_92 . V_87 , struct V_60 , V_67 . V_88 ) ;
if ( NULL == V_85 ) {
F_29 ( & V_61 -> V_67 . V_88 , & V_59 -> V_86 ) ;
F_20 ( V_23 , V_59 , V_61 ) ;
V_61 -> V_67 . V_93 = V_94 ;
V_61 -> V_77 = V_59 -> V_77 ++ ;
F_28 ( & V_59 -> V_89 , V_90 + V_91 ) ;
F_7 ( 2 , L_5 ,
V_61 , V_61 -> V_67 . V_3 ) ;
} else if ( V_85 -> V_67 . V_68 == V_61 -> V_67 . V_68 &&
V_85 -> V_67 . V_69 == V_61 -> V_67 . V_69 &&
V_85 -> V_72 == V_61 -> V_72 ) {
F_29 ( & V_61 -> V_67 . V_88 , & V_59 -> V_86 ) ;
V_61 -> V_67 . V_93 = V_94 ;
V_61 -> V_77 = V_59 -> V_77 ++ ;
V_85 -> V_65 . V_95 [ 1 ] = F_30 ( V_61 -> V_65 . V_66 ) ;
F_7 ( 2 , L_6 ,
V_61 , V_61 -> V_67 . V_3 ) ;
} else {
return 0 ;
}
V_85 = V_61 ;
}
}
static int
F_31 ( struct V_96 * V_59 , unsigned int * V_77 , unsigned int * V_97 )
{
struct V_24 * V_25 = V_59 -> V_98 ;
* V_97 = V_25 -> V_72 -> V_99 * V_25 -> V_68 * V_25 -> V_69 >> 3 ;
if ( 0 == * V_77 )
* V_77 = 32 ;
if ( * V_97 * * V_77 > V_100 * 1024 * 1024 )
* V_77 = ( V_100 * 1024 * 1024 ) / * V_97 ;
return 0 ;
}
static int
F_32 ( struct V_96 * V_59 , struct V_101 * V_67 ,
enum V_102 V_70 )
{
struct V_24 * V_25 = V_59 -> V_98 ;
struct V_22 * V_23 = V_25 -> V_23 ;
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_60 * V_61 = F_33 ( V_67 , struct V_60 , V_67 ) ;
struct V_103 * V_66 = F_34 ( & V_61 -> V_67 ) ;
int V_104 , V_105 = 0 ;
F_11 ( NULL == V_25 -> V_72 ) ;
if ( V_25 -> V_68 < 48 || V_25 -> V_68 > F_35 ( V_6 -> V_18 ) ||
V_25 -> V_69 < 32 || V_25 -> V_69 > F_36 ( V_6 -> V_18 ) )
return - V_12 ;
V_61 -> V_67 . V_97 = ( V_25 -> V_68 * V_25 -> V_69 * V_25 -> V_72 -> V_99 ) >> 3 ;
if ( 0 != V_61 -> V_67 . V_106 && V_61 -> V_67 . V_107 < V_61 -> V_67 . V_97 )
return - V_12 ;
if ( V_61 -> V_72 != V_25 -> V_72 ||
V_61 -> V_67 . V_68 != V_25 -> V_68 ||
V_61 -> V_67 . V_69 != V_25 -> V_69 ||
V_61 -> V_67 . V_70 != V_70 ) {
V_61 -> V_72 = V_25 -> V_72 ;
V_61 -> V_67 . V_68 = V_25 -> V_68 ;
V_61 -> V_67 . V_69 = V_25 -> V_69 ;
V_61 -> V_67 . V_70 = V_70 ;
V_105 = 1 ;
}
if ( V_108 == V_61 -> V_67 . V_93 ) {
V_105 = 1 ;
if ( 0 != ( V_104 = F_37 ( V_59 , & V_61 -> V_67 , NULL ) ) )
goto V_109;
}
if ( V_105 ) {
V_61 -> V_64 = V_61 -> V_67 . V_68 * V_61 -> V_72 -> V_99 >> 3 ;
switch ( V_61 -> V_67 . V_70 ) {
case V_110 :
F_38 ( V_23 -> V_111 , & V_61 -> V_65 ,
V_66 -> V_112 , 0 , V_113 ,
V_61 -> V_64 , 0 , V_61 -> V_67 . V_69 ) ;
break;
case V_114 :
F_38 ( V_23 -> V_111 , & V_61 -> V_65 ,
V_66 -> V_112 , V_113 , 0 ,
V_61 -> V_64 , 0 , V_61 -> V_67 . V_69 ) ;
break;
case V_115 :
F_38 ( V_23 -> V_111 , & V_61 -> V_65 ,
V_66 -> V_112 , 0 , V_61 -> V_64 ,
V_61 -> V_64 , V_61 -> V_64 ,
V_61 -> V_67 . V_69 >> 1 ) ;
break;
case V_116 :
F_38 ( V_23 -> V_111 , & V_61 -> V_65 ,
V_66 -> V_112 ,
0 , V_61 -> V_64 * ( V_61 -> V_67 . V_69 >> 1 ) ,
V_61 -> V_64 , 0 ,
V_61 -> V_67 . V_69 >> 1 ) ;
break;
case V_117 :
F_38 ( V_23 -> V_111 , & V_61 -> V_65 ,
V_66 -> V_112 ,
V_61 -> V_64 * ( V_61 -> V_67 . V_69 >> 1 ) , 0 ,
V_61 -> V_64 , 0 ,
V_61 -> V_67 . V_69 >> 1 ) ;
break;
default:
F_39 () ;
}
}
F_7 ( 2 , L_7 ,
V_61 , V_61 -> V_67 . V_3 ,
V_25 -> V_68 , V_25 -> V_69 , V_25 -> V_72 -> V_99 , V_25 -> V_72 -> V_118 ,
( unsigned long ) V_61 -> V_65 . V_66 ) ;
V_61 -> V_67 . V_93 = V_119 ;
return 0 ;
V_109:
F_40 ( V_59 , V_61 ) ;
return V_104 ;
}
static void
F_41 ( struct V_96 * V_120 , struct V_101 * V_67 )
{
struct V_60 * V_61 = F_33 ( V_67 , struct V_60 , V_67 ) ;
struct V_60 * V_85 ;
struct V_24 * V_25 = V_120 -> V_98 ;
struct V_22 * V_23 = V_25 -> V_23 ;
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_58 * V_59 = & V_23 -> V_121 ;
V_61 -> V_65 . V_95 [ 0 ] = F_30 ( V_122 | V_123 | V_124 ) ;
V_61 -> V_65 . V_95 [ 1 ] = F_30 ( V_59 -> V_125 . V_66 ) ;
if ( ! F_25 ( & V_59 -> V_92 ) ) {
F_42 ( & V_61 -> V_67 . V_88 , & V_59 -> V_92 ) ;
V_61 -> V_67 . V_93 = V_126 ;
F_7 ( 2 , L_8 ,
V_61 , V_61 -> V_67 . V_3 ) ;
} else if ( F_25 ( & V_59 -> V_86 ) ) {
F_42 ( & V_61 -> V_67 . V_88 , & V_59 -> V_86 ) ;
F_20 ( V_23 , V_59 , V_61 ) ;
V_61 -> V_67 . V_93 = V_94 ;
V_61 -> V_77 = V_59 -> V_77 ++ ;
F_28 ( & V_59 -> V_89 , V_90 + V_91 ) ;
F_7 ( 2 , L_9 ,
V_61 , V_61 -> V_67 . V_3 ) ;
} else {
V_85 = F_26 ( V_59 -> V_86 . V_85 , struct V_60 , V_67 . V_88 ) ;
if ( V_85 -> V_67 . V_68 == V_61 -> V_67 . V_68 &&
V_85 -> V_67 . V_69 == V_61 -> V_67 . V_69 &&
V_85 -> V_72 == V_61 -> V_72 ) {
F_42 ( & V_61 -> V_67 . V_88 , & V_59 -> V_86 ) ;
V_61 -> V_67 . V_93 = V_94 ;
V_61 -> V_77 = V_59 -> V_77 ++ ;
V_85 -> V_65 . V_95 [ 1 ] = F_30 ( V_61 -> V_65 . V_66 ) ;
F_7 ( 2 , L_10 ,
V_61 , V_61 -> V_67 . V_3 ) ;
} else {
F_42 ( & V_61 -> V_67 . V_88 , & V_59 -> V_92 ) ;
V_61 -> V_67 . V_93 = V_126 ;
F_7 ( 2 , L_11 ,
V_61 , V_61 -> V_67 . V_3 ) ;
}
}
}
static void F_43 ( struct V_96 * V_59 , struct V_101 * V_67 )
{
struct V_60 * V_61 = F_33 ( V_67 , struct V_60 , V_67 ) ;
F_40 ( V_59 , V_61 ) ;
}
static struct V_96 * F_44 ( struct V_24 * V_25 )
{
switch ( V_25 -> type ) {
case V_127 :
return & V_25 -> V_121 ;
case V_128 :
return & V_25 -> V_129 ;
default:
F_39 () ;
return NULL ;
}
}
static int F_45 ( struct V_24 * V_25 )
{
switch ( V_25 -> type ) {
case V_127 :
return V_130 ;
case V_128 :
return V_131 ;
default:
F_39 () ;
return 0 ;
}
}
static int F_46 ( struct V_132 * V_132 )
{
struct V_133 * V_134 = F_47 ( V_132 ) ;
struct V_22 * V_23 = F_48 ( V_132 ) ;
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_24 * V_25 ;
enum V_135 type = 0 ;
int V_136 = 0 ;
switch ( V_134 -> V_137 ) {
case V_138 :
type = V_127 ;
break;
case V_139 :
type = V_128 ;
break;
case V_140 :
V_136 = 1 ;
break;
}
F_7 ( 1 , L_12 ,
F_49 ( V_134 ) , V_136 , V_141 [ type ] ) ;
V_25 = F_50 ( sizeof( * V_25 ) , V_142 ) ;
if ( F_51 ( ! V_25 ) )
return - V_143 ;
V_132 -> V_144 = V_25 ;
V_25 -> V_23 = V_23 ;
V_25 -> V_136 = V_136 ;
V_25 -> type = type ;
V_25 -> V_68 = 320 ;
V_25 -> V_69 = 240 ;
V_25 -> V_72 = F_1 ( V_145 ) ;
F_5 ( & V_6 -> V_28 ) ;
F_52 ( & V_25 -> V_121 , & V_146 ,
& V_23 -> V_111 -> V_23 , & V_23 -> V_147 ,
V_127 ,
V_115 ,
sizeof( struct V_60 ) ,
V_25 , NULL ) ;
F_52 ( & V_25 -> V_129 , & V_148 ,
& V_23 -> V_111 -> V_23 , & V_23 -> V_147 ,
V_128 ,
V_116 ,
sizeof( struct V_60 ) ,
V_25 , NULL ) ;
if ( V_25 -> V_136 ) {
F_7 ( 1 , L_13 ) ;
F_15 ( V_37 , V_6 -> V_46 . V_136 . V_35 ) ;
F_15 ( V_38 , V_6 -> V_46 . V_136 . V_32 ) ;
F_15 ( V_39 , V_6 -> V_46 . V_136 . V_33 ) ;
F_15 ( V_40 , V_6 -> V_46 . V_136 . V_34 ) ;
if ( V_6 -> V_46 . V_136 . V_45 ) {
if( V_6 -> V_46 . V_47 &&
V_6 -> V_46 . V_47 == V_48 ) {
F_18 ( V_6 , V_49 , V_50 ,
V_6 -> V_46 . V_136 . V_45 , 0 , 0 ) ;
}
V_6 -> V_53 = V_54 ;
F_19 ( V_6 ) ;
} else {
V_6 -> V_53 = V_149 ;
F_19 ( V_6 ) ;
F_53 ( V_6 , V_150 , 1 ) ;
}
F_18 ( V_6 , V_151 , V_152 ) ;
}
V_6 -> V_153 ++ ;
F_6 ( & V_6 -> V_28 ) ;
return 0 ;
}
static T_1
F_54 ( struct V_132 * V_132 , char T_2 * V_154 , T_3 V_77 , T_4 * V_155 )
{
struct V_24 * V_25 = V_132 -> V_144 ;
switch ( V_25 -> type ) {
case V_127 :
if ( F_9 ( V_25 -> V_23 , V_130 ) )
return - V_156 ;
return F_55 ( & V_25 -> V_121 , V_154 , V_77 , V_155 ,
V_132 -> V_157 & V_158 ) ;
case V_128 :
if ( ! F_4 ( V_25 -> V_23 , V_25 , V_131 ) )
return - V_156 ;
return F_56 ( & V_25 -> V_129 , V_154 , V_77 , V_155 , 1 ,
V_132 -> V_157 & V_158 ) ;
default:
F_39 () ;
return 0 ;
}
}
static unsigned int
F_57 ( struct V_132 * V_132 , struct V_159 * V_160 )
{
struct V_24 * V_25 = V_132 -> V_144 ;
struct V_60 * V_61 ;
unsigned int V_104 = V_161 ;
if ( V_128 == V_25 -> type ) {
if ( ! F_4 ( V_25 -> V_23 , V_25 , V_131 ) )
return V_161 ;
return F_58 ( V_132 , & V_25 -> V_129 , V_160 ) ;
}
F_5 ( & V_25 -> V_121 . V_162 ) ;
if ( F_8 ( V_25 , V_130 ) ) {
if ( F_25 ( & V_25 -> V_121 . V_163 ) )
goto V_164;
V_61 = F_26 ( V_25 -> V_121 . V_163 . V_87 , struct V_60 , V_67 . V_163 ) ;
} else {
V_61 = (struct V_60 * ) V_25 -> V_121 . V_165 ;
if ( NULL == V_61 )
goto V_164;
}
F_59 ( V_132 , & V_61 -> V_67 . V_164 , V_160 ) ;
if ( V_61 -> V_67 . V_93 == V_166 ||
V_61 -> V_67 . V_93 == V_167 )
V_104 = V_168 | V_169 ;
else
V_104 = 0 ;
V_164:
F_6 ( & V_25 -> V_121 . V_162 ) ;
return V_104 ;
}
static int F_60 ( struct V_132 * V_132 )
{
struct V_24 * V_25 = V_132 -> V_144 ;
struct V_22 * V_23 = V_25 -> V_23 ;
if ( F_8 ( V_25 , V_170 ) ) {
F_10 ( V_23 , V_25 , V_170 ) ;
}
if ( F_8 ( V_25 , V_130 ) ) {
F_61 ( & V_25 -> V_121 ) ;
F_10 ( V_23 , V_25 , V_130 ) ;
}
if ( V_25 -> V_121 . V_165 ) {
F_43 ( & V_25 -> V_121 , V_25 -> V_121 . V_165 ) ;
F_62 ( V_25 -> V_121 . V_165 ) ;
}
if ( F_8 ( V_25 , V_131 ) ) {
F_63 ( & V_25 -> V_129 ) ;
F_10 ( V_23 , V_25 , V_131 ) ;
}
F_64 ( & V_25 -> V_121 ) ;
F_64 ( & V_25 -> V_129 ) ;
F_5 ( & V_23 -> V_6 -> V_28 ) ;
V_132 -> V_144 = NULL ;
F_62 ( V_25 ) ;
V_23 -> V_6 -> V_153 -- ;
if ( ! V_23 -> V_6 -> V_153 )
F_18 ( V_23 -> V_6 , V_6 , V_171 , 0 ) ;
F_6 ( & V_23 -> V_6 -> V_28 ) ;
return 0 ;
}
static int
F_65 ( struct V_132 * V_132 , struct V_172 * V_173 )
{
struct V_24 * V_25 = V_132 -> V_144 ;
return F_66 ( F_44 ( V_25 ) , V_173 ) ;
}
int F_67 ( struct V_5 * V_6 , struct V_174 * V_175 )
{
const struct V_176 * V_177 = NULL ;
T_5 V_178 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ )
if ( V_14 [ V_3 ] . V_15 . V_9 == V_175 -> V_9 )
V_177 = & V_14 [ V_3 ] ;
if ( F_51 ( NULL == V_177 ) )
return - V_12 ;
V_178 = V_177 -> V_179 ? F_68 ( V_177 -> V_179 ) : F_69 ( V_177 -> V_180 ) ;
switch ( V_175 -> V_9 ) {
case V_181 :
V_175 -> V_178 = ( ( V_178 & 0x7f ) < 0x40 ) ? ( ( V_178 & 0x7f ) + 0x40 )
: ( 0x7f - ( V_178 & 0x7f ) ) ;
break;
case V_182 :
V_175 -> V_178 = 0x3f - ( V_178 & 0x3f ) ;
break;
default:
V_175 -> V_178 = ( ( V_178 + ( V_177 -> V_183 << V_177 -> V_184 ) ) & V_177 -> V_185 ) >> V_177 -> V_184 ;
break;
}
F_7 ( 1 , L_14 ,
V_175 -> V_9 , V_177 -> V_15 . V_118 , V_175 -> V_178 , V_177 -> V_180 ,
V_178 , V_177 -> V_185 , V_177 -> V_179 ? L_15 : L_16 ) ;
return 0 ;
}
int F_70 ( struct V_5 * V_6 , struct V_174 * V_175 )
{
const struct V_176 * V_177 = NULL ;
T_5 V_178 , V_185 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
if ( V_14 [ V_3 ] . V_15 . V_9 == V_175 -> V_9 ) {
V_177 = & V_14 [ V_3 ] ;
}
}
if ( F_51 ( NULL == V_177 ) )
return - V_12 ;
if ( V_175 -> V_178 < V_177 -> V_15 . V_186 )
V_175 -> V_178 = V_177 -> V_15 . V_186 ;
if ( V_175 -> V_178 > V_177 -> V_15 . V_187 )
V_175 -> V_178 = V_177 -> V_15 . V_187 ;
if ( V_6 -> V_46 . V_47 == V_48 ) {
struct V_174 V_188 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_9 = V_175 -> V_9 ;
switch ( V_175 -> V_9 ) {
case V_189 :
V_188 . V_178 = V_175 -> V_178 ;
break;
case V_182 :
V_188 . V_178 = ( V_175 -> V_178 ) ?
( 0x90 + V_175 -> V_178 ) << 8 : 0 ;
break;
case V_181 :
V_188 . V_178 = V_175 -> V_178 << 9 ;
break;
default:
V_188 . V_9 = 0 ;
break;
}
if ( V_188 . V_9 )
F_71 ( V_6 , V_190 , V_6 , V_191 , & V_188 ) ;
}
V_185 = V_177 -> V_185 ;
switch ( V_175 -> V_9 ) {
case V_181 :
V_178 = ( V_175 -> V_178 < 0x40 ) ? ( 0x7f - V_175 -> V_178 ) : ( V_175 -> V_178 - 0x40 ) ;
break;
case V_182 :
V_178 = 0x3f - ( V_175 -> V_178 & 0x3f ) ;
break;
case V_192 :
V_178 = ( ( V_175 -> V_178 - V_177 -> V_183 ) << V_177 -> V_184 ) & V_177 -> V_185 ;
if ( V_6 -> V_18 & V_19 ) {
V_178 = V_178 << 8 | V_178 ;
} else {
V_178 = ( V_178 * 0x5a ) / 0x7f << 8 | V_178 ;
}
V_185 = 0xffff ;
break;
case V_17 :
V_178 = ( ( V_175 -> V_178 - V_177 -> V_183 ) << V_177 -> V_184 ) & V_177 -> V_185 ;
if ( V_6 -> V_18 & V_19 && V_178 )
return - V_12 ;
break;
default:
V_178 = ( ( V_175 -> V_178 - V_177 -> V_183 ) << V_177 -> V_184 ) & V_177 -> V_185 ;
break;
}
F_7 ( 1 , L_17 ,
V_175 -> V_9 , V_177 -> V_15 . V_118 , V_175 -> V_178 , V_177 -> V_180 , V_178 ,
V_185 , V_177 -> V_179 ? L_15 : L_16 ) ;
if ( V_177 -> V_179 ) {
F_72 ( V_177 -> V_179 , V_177 -> V_180 , V_185 , V_178 ) ;
} else {
F_14 ( V_177 -> V_180 , V_185 , V_178 ) ;
}
return 0 ;
}
static void F_73 ( struct V_5 * V_6 )
{
struct V_174 V_193 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
V_193 . V_9 = V_14 [ V_3 ] . V_15 . V_9 ;
V_193 . V_178 = V_14 [ V_3 ] . V_15 . V_194 ;
F_70 ( V_6 , & V_193 ) ;
}
}
static int F_74 ( struct V_132 * V_132 , void * V_195 ,
struct V_196 * V_197 )
{
struct V_24 * V_25 = V_195 ;
V_197 -> V_72 . V_198 . V_68 = V_25 -> V_68 ;
V_197 -> V_72 . V_198 . V_69 = V_25 -> V_69 ;
V_197 -> V_72 . V_198 . V_70 = V_25 -> V_121 . V_70 ;
V_197 -> V_72 . V_198 . V_199 = V_25 -> V_72 -> V_2 ;
V_197 -> V_72 . V_198 . V_200 =
( V_197 -> V_72 . V_198 . V_68 * V_25 -> V_72 -> V_99 ) >> 3 ;
V_197 -> V_72 . V_198 . V_201 =
V_197 -> V_72 . V_198 . V_69 * V_197 -> V_72 . V_198 . V_200 ;
return 0 ;
}
static int F_75 ( struct V_132 * V_132 , void * V_195 ,
struct V_196 * V_197 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
const struct V_1 * V_72 ;
enum V_102 V_70 ;
unsigned int V_202 , V_203 ;
V_72 = F_1 ( V_197 -> V_72 . V_198 . V_199 ) ;
if ( NULL == V_72 )
return - V_12 ;
V_70 = V_197 -> V_72 . V_198 . V_70 ;
V_202 = F_35 ( V_6 -> V_18 ) ;
V_203 = F_36 ( V_6 -> V_18 ) ;
if ( V_204 == V_70 ) {
V_70 = ( V_197 -> V_72 . V_198 . V_69 > V_203 / 2 )
? V_115
: V_114 ;
}
switch ( V_70 ) {
case V_110 :
case V_114 :
V_203 = V_203 / 2 ;
break;
case V_115 :
break;
default:
return - V_12 ;
}
V_197 -> V_72 . V_198 . V_70 = V_70 ;
F_76 ( & V_197 -> V_72 . V_198 . V_68 , 48 , V_202 , 2 ,
& V_197 -> V_72 . V_198 . V_69 , 32 , V_203 , 0 , 0 ) ;
V_197 -> V_72 . V_198 . V_200 =
( V_197 -> V_72 . V_198 . V_68 * V_72 -> V_99 ) >> 3 ;
V_197 -> V_72 . V_198 . V_201 =
V_197 -> V_72 . V_198 . V_69 * V_197 -> V_72 . V_198 . V_200 ;
return 0 ;
}
static int F_77 ( struct V_132 * V_132 , void * V_195 ,
struct V_196 * V_197 )
{
struct V_24 * V_25 = V_195 ;
int V_205 = F_75 ( V_132 , V_195 , V_197 ) ;
if ( 0 != V_205 )
return V_205 ;
V_25 -> V_72 = F_1 ( V_197 -> V_72 . V_198 . V_199 ) ;
V_25 -> V_68 = V_197 -> V_72 . V_198 . V_68 ;
V_25 -> V_69 = V_197 -> V_72 . V_198 . V_69 ;
V_25 -> V_121 . V_70 = V_197 -> V_72 . V_198 . V_70 ;
return 0 ;
}
static int F_78 ( struct V_132 * V_132 , void * V_195 ,
struct V_206 * V_207 )
{
struct V_22 * V_23 = ( (struct V_24 * ) V_195 ) -> V_23 ;
struct V_5 * V_6 = V_23 -> V_6 ;
strcpy ( V_207 -> V_208 , L_18 ) ;
F_79 ( V_207 -> V_209 , V_6 -> V_46 . V_118 , sizeof( V_207 -> V_209 ) ) ;
sprintf ( V_207 -> V_210 , L_19 , F_80 ( V_23 -> V_111 ) ) ;
V_207 -> V_211 = V_212 ;
V_207 -> V_213 =
V_214 |
V_215 |
V_216 |
V_217 ;
if ( V_113 != V_6 -> V_46 . V_218 )
V_207 -> V_213 |= V_219 ;
return 0 ;
}
static int F_81 ( struct V_132 * V_132 , void * V_195 ,
struct V_220 * V_197 )
{
if ( F_51 ( V_197 -> V_221 >= F_2 ( V_4 ) ) )
return - V_12 ;
F_79 ( V_197 -> V_222 , V_4 [ V_197 -> V_221 ] . V_118 , sizeof( V_197 -> V_222 ) ) ;
V_197 -> V_199 = V_4 [ V_197 -> V_221 ] . V_2 ;
return 0 ;
}
static int F_82 ( struct V_132 * V_132 , void * V_195 , struct V_223 * V_224 )
{
struct V_24 * V_25 = V_195 ;
return ( F_83 ( F_44 ( V_25 ) , V_224 ) ) ;
}
static int F_84 ( struct V_132 * V_132 , void * V_195 , struct V_225 * V_224 )
{
struct V_24 * V_25 = V_195 ;
return ( F_85 ( F_44 ( V_25 ) , V_224 ) ) ;
}
static int F_86 ( struct V_132 * V_132 , void * V_195 , struct V_225 * V_224 )
{
struct V_24 * V_25 = V_195 ;
return ( F_87 ( F_44 ( V_25 ) , V_224 ) ) ;
}
static int F_88 ( struct V_132 * V_132 , void * V_195 , struct V_225 * V_224 )
{
struct V_24 * V_25 = V_195 ;
return ( F_89 ( F_44 ( V_25 ) , V_224 ,
V_132 -> V_157 & V_158 ) ) ;
}
static int F_90 ( struct V_132 * V_132 , void * V_195 , enum V_135 V_3 )
{
struct V_24 * V_25 = V_195 ;
struct V_22 * V_23 = V_25 -> V_23 ;
if ( F_51 ( ( V_25 -> type != V_127 ) &&
( V_25 -> type != V_128 ) ) )
return - V_12 ;
if ( F_51 ( V_3 != V_25 -> type ) )
return - V_12 ;
if ( F_51 ( ! F_4 ( V_23 , V_25 , F_45 ( V_25 ) ) ) )
return - V_156 ;
return F_91 ( F_44 ( V_25 ) ) ;
}
static int F_92 ( struct V_132 * V_132 , void * V_195 , enum V_135 V_3 )
{
struct V_24 * V_25 = V_195 ;
struct V_22 * V_23 = V_25 -> V_23 ;
int V_205 , V_226 ;
if ( ( V_25 -> type != V_127 ) &&
( V_25 -> type != V_128 ) )
return - V_12 ;
if ( V_3 != V_25 -> type )
return - V_12 ;
V_226 = F_45 ( V_25 ) ;
V_205 = F_93 ( F_44 ( V_25 ) ) ;
if ( V_205 < 0 )
return V_205 ;
F_10 ( V_23 , V_25 , V_226 ) ;
return 0 ;
}
static int F_94 ( struct V_132 * V_132 , void * V_195 , T_6 * V_227 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
F_5 ( & V_6 -> V_28 ) ;
F_95 ( V_6 , * V_227 ) ;
F_6 ( & V_6 -> V_28 ) ;
return 0 ;
}
int F_96 ( struct V_5 * V_6 , struct V_228 * V_3 )
{
static const char * const V_229 [] = {
[ V_230 ] = L_20 ,
[ V_231 ] = L_21 ,
[ V_232 ] = L_22 ,
[ V_233 ] = L_23 ,
[ V_41 ] = L_24 ,
[ V_51 ] = L_25 ,
[ V_52 ] = L_26 ,
[ V_234 ] = L_27 ,
[ V_235 ] = L_28 ,
} ;
unsigned int V_236 = V_3 -> V_221 ;
if ( V_236 >= 4 )
return - V_12 ;
if ( 0 == F_13 ( V_236 ) . type )
return - V_12 ;
V_3 -> type = V_237 ;
strcpy ( V_3 -> V_118 , V_229 [ F_13 ( V_236 ) . type ] ) ;
if ( ( V_51 == F_13 ( V_236 ) . type ) ||
( V_52 == F_13 ( V_236 ) . type ) ) {
V_3 -> type = V_238 ;
V_3 -> V_239 = V_240 ;
}
return 0 ;
}
static int F_97 ( struct V_132 * V_132 , void * V_195 ,
struct V_228 * V_3 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
return F_96 ( V_6 , V_3 ) ;
}
static int F_98 ( struct V_132 * V_132 , void * V_195 , unsigned int * V_3 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
* V_3 = V_6 -> V_30 ;
return 0 ;
}
static int F_99 ( struct V_132 * V_132 , void * V_195 , unsigned int V_3 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
if ( V_3 >= 4 )
return - V_12 ;
F_5 ( & V_6 -> V_28 ) ;
F_100 ( V_6 ) ;
F_12 ( V_6 , V_3 ) ;
F_6 ( & V_6 -> V_28 ) ;
return 0 ;
}
static int F_101 ( struct V_132 * V_132 , void * V_195 ,
struct V_7 * V_8 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
V_8 -> V_9 = F_102 ( V_241 , V_8 -> V_9 ) ;
if ( F_51 ( V_8 -> V_9 == 0 ) )
return - V_12 ;
return F_3 ( V_6 , V_8 ) ;
}
static int F_103 ( struct V_132 * V_132 , void * V_195 ,
struct V_174 * V_175 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
return
F_67 ( V_6 , V_175 ) ;
}
static int F_104 ( struct V_132 * V_132 , void * V_195 ,
struct V_174 * V_175 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
return
F_70 ( V_6 , V_175 ) ;
}
static int F_105 ( struct V_132 * V_132 , void * V_195 ,
struct V_242 * V_243 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
T_5 V_180 ;
if ( F_51 ( V_113 == V_6 -> V_46 . V_218 ) )
return - V_12 ;
if ( 0 != V_243 -> V_221 )
return - V_12 ;
strcpy ( V_243 -> V_118 , L_25 ) ;
V_243 -> type = V_244 ;
V_243 -> V_245 = V_246 ;
V_243 -> V_247 = 0xffffffffUL ;
F_106 ( V_6 , V_243 ) ;
V_180 = F_69 ( V_248 ) ;
V_243 -> signal = ( V_180 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_107 ( struct V_132 * V_132 , void * V_195 ,
struct V_242 * V_243 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
if ( V_113 == V_6 -> V_46 . V_218 )
return - V_12 ;
if ( 0 != V_243 -> V_221 )
return - V_12 ;
F_53 ( V_6 , V_243 -> V_249 , 1 ) ;
return 0 ;
}
static int F_108 ( struct V_132 * V_132 , void * V_195 ,
struct V_250 * V_197 )
{
struct V_24 * V_25 = V_195 ;
struct V_5 * V_6 = V_25 -> V_23 -> V_6 ;
if ( F_51 ( V_113 == V_6 -> V_46 . V_218 ) )
return - V_12 ;
V_197 -> type = V_25 -> V_136 ? V_251 : V_244 ;
V_197 -> V_252 = V_6 -> V_253 ;
F_18 ( V_6 , V_151 , V_254 , V_197 ) ;
return 0 ;
}
int F_109 ( struct V_5 * V_6 ,
struct V_250 * V_197 )
{
if ( F_51 ( V_113 == V_6 -> V_46 . V_218 ) )
return - V_12 ;
if ( F_51 ( V_197 -> V_151 != 0 ) )
return - V_12 ;
F_5 ( & V_6 -> V_28 ) ;
V_6 -> V_253 = V_197 -> V_252 ;
F_100 ( V_6 ) ;
F_18 ( V_6 , V_151 , V_255 , V_197 ) ;
F_110 ( 10 ) ;
F_19 ( V_6 ) ;
F_6 ( & V_6 -> V_28 ) ;
return 0 ;
}
static int F_111 ( struct V_132 * V_132 , void * V_195 ,
struct V_250 * V_197 )
{
struct V_24 * V_25 = V_195 ;
struct V_5 * V_6 = V_25 -> V_23 -> V_6 ;
if ( F_51 ( 0 == V_25 -> V_136 && V_197 -> type != V_244 ) )
return - V_12 ;
if ( F_51 ( 1 == V_25 -> V_136 && V_197 -> type != V_251 ) )
return - V_12 ;
return
F_109 ( V_6 , V_197 ) ;
}
static int F_112 ( struct V_132 * V_132 , void * V_25 ,
struct V_256 * V_180 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_25 ) -> V_23 -> V_6 ;
if ( ! F_113 ( & V_180 -> V_257 ) )
return - V_12 ;
V_180 -> V_258 = F_69 ( V_180 -> V_180 & 0xffffff ) ;
V_180 -> V_97 = 4 ;
return 0 ;
}
static int F_114 ( struct V_132 * V_132 , void * V_25 ,
struct V_256 * V_180 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_25 ) -> V_23 -> V_6 ;
if ( ! F_113 ( & V_180 -> V_257 ) )
return - V_12 ;
F_15 ( V_180 -> V_180 & 0xffffff , V_180 -> V_258 ) ;
return 0 ;
}
static int F_115 ( struct V_132 * V_132 , void * V_195 ,
struct V_206 * V_207 )
{
struct V_22 * V_23 = ( (struct V_24 * ) V_195 ) -> V_23 ;
struct V_5 * V_6 = V_23 -> V_6 ;
strcpy ( V_207 -> V_208 , L_18 ) ;
F_79 ( V_207 -> V_209 , V_6 -> V_46 . V_118 , sizeof( V_207 -> V_209 ) ) ;
sprintf ( V_207 -> V_210 , L_19 , F_80 ( V_23 -> V_111 ) ) ;
V_207 -> V_211 = V_212 ;
V_207 -> V_213 = V_219 ;
return 0 ;
}
static int F_116 ( struct V_132 * V_132 , void * V_195 ,
struct V_242 * V_243 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
if ( F_51 ( V_243 -> V_221 > 0 ) )
return - V_12 ;
strcpy ( V_243 -> V_118 , L_29 ) ;
V_243 -> type = V_251 ;
F_18 ( V_6 , V_151 , V_259 , V_243 ) ;
return 0 ;
}
static int F_117 ( struct V_132 * V_132 , void * V_195 ,
struct V_228 * V_3 )
{
if ( V_3 -> V_221 != 0 )
return - V_12 ;
strcpy ( V_3 -> V_118 , L_29 ) ;
V_3 -> type = V_238 ;
return 0 ;
}
static int F_118 ( struct V_132 * V_132 , void * V_195 , struct V_260 * V_261 )
{
if ( F_51 ( V_261 -> V_221 ) )
return - V_12 ;
strcpy ( V_261 -> V_118 , L_29 ) ;
return 0 ;
}
static int F_119 ( struct V_132 * V_132 , void * V_195 ,
struct V_242 * V_243 )
{
struct V_5 * V_6 = ( (struct V_24 * ) V_195 ) -> V_23 -> V_6 ;
if ( 0 != V_243 -> V_221 )
return - V_12 ;
F_18 ( V_6 , V_151 , V_262 , V_243 ) ;
return 0 ;
}
static int F_120 ( struct V_132 * V_132 , void * V_25 ,
struct V_260 * V_261 )
{
return 0 ;
}
static int F_121 ( struct V_132 * V_132 , void * V_25 , unsigned int V_3 )
{
return 0 ;
}
static int F_122 ( struct V_132 * V_132 , void * V_195 ,
struct V_7 * V_177 )
{
int V_3 ;
if ( V_177 -> V_9 < V_10 ||
V_177 -> V_9 >= V_11 )
return - V_12 ;
if ( V_177 -> V_9 == V_189 ||
V_177 -> V_9 == V_182 ||
V_177 -> V_9 == V_181 ) {
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
if ( V_14 [ V_3 ] . V_15 . V_9 == V_177 -> V_9 )
break;
}
if ( V_3 == V_13 )
return - V_12 ;
* V_177 = V_14 [ V_3 ] . V_15 ;
} else
* V_177 = V_16 ;
return 0 ;
}
static void F_123 ( unsigned long V_154 )
{
struct V_22 * V_23 = (struct V_22 * ) V_154 ;
struct V_5 * V_6 = V_23 -> V_6 ;
struct V_58 * V_59 = & V_23 -> V_121 ;
struct V_60 * V_61 ;
unsigned long V_20 ;
F_124 ( V_6 , & V_62 [ V_63 ] ) ;
F_17 ( V_84 , 0x11 ) ;
F_17 ( V_82 , 0x06 ) ;
F_125 ( & V_23 -> V_147 , V_20 ) ;
while ( ! F_25 ( & V_59 -> V_86 ) ) {
V_61 = F_26 ( V_59 -> V_86 . V_87 , struct V_60 , V_67 . V_88 ) ;
F_126 ( & V_61 -> V_67 . V_88 ) ;
V_61 -> V_67 . V_93 = V_167 ;
F_127 ( & V_61 -> V_67 . V_164 ) ;
F_128 ( L_30 , V_6 -> V_118 ,
V_61 , V_61 -> V_67 . V_3 , ( unsigned long ) V_61 -> V_65 . V_66 ) ;
}
F_24 ( V_23 , V_59 ) ;
F_129 ( & V_23 -> V_147 , V_20 ) ;
}
static void F_130 ( struct V_22 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_6 ;
T_5 V_263 , V_185 , V_77 ;
V_263 = F_69 ( V_264 ) ;
V_185 = F_69 ( V_81 ) ;
if ( 0 == ( V_263 & V_185 ) )
return;
F_15 ( V_264 , V_263 ) ;
if ( V_265 || ( V_263 & V_185 & ~ 0xff ) )
F_131 ( V_6 -> V_118 , L_31 ,
V_266 , F_2 ( V_266 ) ,
V_263 , V_185 ) ;
if ( V_263 & ( 1 << 16 ) ) {
F_128 ( V_267 L_32 , V_6 -> V_118 ) ;
F_17 ( V_84 , 0x11 ) ;
F_17 ( V_82 , 0x06 ) ;
F_124 ( V_6 , & V_62 [ V_63 ] ) ;
}
if ( V_263 & 0x01 ) {
F_132 ( & V_23 -> V_147 ) ;
V_77 = F_69 ( V_268 ) ;
F_133 ( V_6 , & V_23 -> V_121 , V_77 ) ;
F_134 ( & V_23 -> V_147 ) ;
}
if ( V_263 & 0x08 ) {
F_132 ( & V_23 -> V_147 ) ;
V_77 = F_69 ( V_269 ) ;
F_133 ( V_6 , & V_23 -> V_129 , V_77 ) ;
F_134 ( & V_23 -> V_147 ) ;
}
if ( V_263 & 0x10 ) {
F_7 ( 2 , L_33 ) ;
F_132 ( & V_23 -> V_147 ) ;
F_24 ( V_23 , & V_23 -> V_121 ) ;
F_134 ( & V_23 -> V_147 ) ;
}
if ( V_263 & 0x80 ) {
F_7 ( 2 , L_34 ) ;
F_132 ( & V_23 -> V_147 ) ;
F_135 ( V_23 , & V_23 -> V_129 ) ;
F_134 ( & V_23 -> V_147 ) ;
}
}
static T_7 F_136 ( int V_270 , void * V_271 )
{
struct V_22 * V_23 = V_271 ;
struct V_5 * V_6 = V_23 -> V_6 ;
T_5 V_263 ;
int V_272 , V_273 = 0 ;
for ( V_272 = 0 ; V_272 < 10 ; V_272 ++ ) {
V_263 = F_69 ( V_274 ) &
( V_6 -> V_79 | V_80 ) ;
if ( 0 == V_263 )
goto V_275;
F_15 ( V_274 , V_263 ) ;
V_273 = 1 ;
if ( V_263 & V_6 -> V_79 )
F_137 ( V_6 , V_263 ) ;
if ( V_263 & V_80 )
F_130 ( V_23 ) ;
} ;
if ( 10 == V_272 ) {
F_128 ( V_267 L_35 ,
V_6 -> V_118 ) ;
F_15 ( V_78 , 0 ) ;
}
V_275:
return F_138 ( V_273 ) ;
}
static void F_139 ( struct V_22 * V_23 )
{
if ( V_23 -> V_276 ) {
if ( F_140 ( V_23 -> V_276 ) )
F_141 ( V_23 -> V_276 ) ;
else
F_142 ( V_23 -> V_276 ) ;
V_23 -> V_276 = NULL ;
}
if ( V_23 -> V_277 ) {
if ( F_140 ( V_23 -> V_277 ) )
F_141 ( V_23 -> V_277 ) ;
else
F_142 ( V_23 -> V_277 ) ;
V_23 -> V_277 = NULL ;
}
if ( V_23 -> V_278 ) {
if ( F_140 ( V_23 -> V_278 ) )
F_141 ( V_23 -> V_278 ) ;
else
F_142 ( V_23 -> V_278 ) ;
V_23 -> V_278 = NULL ;
}
}
static int T_8 F_143 ( struct V_279 * V_279 ,
const struct V_280 * V_281 )
{
struct V_22 * V_23 ;
struct V_5 * V_6 ;
int V_205 ;
V_23 = F_50 ( sizeof( * V_23 ) , V_142 ) ;
if ( NULL == V_23 )
return - V_143 ;
V_23 -> V_111 = V_279 ;
if ( F_144 ( V_279 ) ) {
V_205 = - V_282 ;
goto V_283;
}
V_6 = F_145 ( V_23 -> V_111 ) ;
if ( NULL == V_6 ) {
V_205 = - V_12 ;
goto V_283;
}
V_23 -> V_6 = V_6 ;
V_23 -> V_284 = V_279 -> V_285 ;
F_146 ( V_279 , V_286 , & V_23 -> V_287 ) ;
F_128 ( V_288 L_36
L_37 , V_6 -> V_118 ,
F_80 ( V_279 ) , V_23 -> V_284 , V_279 -> V_270 ,
V_23 -> V_287 , ( unsigned long long ) F_147 ( V_279 , 0 ) ) ;
F_148 ( V_279 ) ;
if ( ! F_149 ( V_279 , F_150 ( 32 ) ) ) {
F_128 ( L_38 , V_6 -> V_118 ) ;
V_205 = - V_282 ;
goto V_289;
}
memcpy ( & V_290 , & V_291 ,
sizeof( V_290 ) ) ;
strcpy ( V_290 . V_118 , L_39 ) ;
F_151 ( & V_23 -> V_147 ) ;
V_6 -> V_18 = V_291 . V_292 ;
F_152 ( & V_23 -> V_121 . V_86 ) ;
F_152 ( & V_23 -> V_121 . V_92 ) ;
V_23 -> V_121 . V_89 . V_293 = F_123 ;
V_23 -> V_121 . V_89 . V_154 = ( unsigned long ) V_23 ;
F_153 ( & V_23 -> V_121 . V_89 ) ;
F_154 ( V_23 -> V_111 , & V_23 -> V_121 . V_125 ,
V_84 , 0x11 , 0x00 ) ;
F_152 ( & V_23 -> V_129 . V_86 ) ;
F_152 ( & V_23 -> V_129 . V_92 ) ;
V_23 -> V_129 . V_89 . V_293 = V_294 ;
V_23 -> V_129 . V_89 . V_154 = ( unsigned long ) V_23 ;
F_153 ( & V_23 -> V_129 . V_89 ) ;
F_154 ( V_23 -> V_111 , & V_23 -> V_129 . V_125 ,
V_84 , 0x88 , 0x00 ) ;
V_205 = F_155 ( V_279 -> V_270 , F_136 ,
V_295 | V_296 , V_6 -> V_118 , V_23 ) ;
if ( V_205 < 0 ) {
F_128 ( V_297 L_40 ,
V_6 -> V_118 , V_279 -> V_270 ) ;
goto V_289;
}
F_16 ( V_78 , V_6 -> V_79 ) ;
if ( V_6 -> V_46 . V_47 == V_48 ) {
struct V_298 V_299 = {
. type = L_41 ,
. V_300 = 0x36 >> 1 ,
. V_301 = & V_6 -> V_302 ,
} ;
struct V_303 * V_304 ;
if ( V_6 -> V_305 == V_306 )
V_6 -> V_302 . V_307 = true ;
else
V_6 -> V_302 . V_307 = false ;
V_304 = F_156 ( & V_6 -> V_308 , & V_6 -> V_309 ,
& V_299 , NULL ) ;
if ( V_304 != NULL )
V_304 -> V_310 = V_190 ;
}
if ( V_6 -> V_46 . V_47 == V_311 ) {
F_157 ( & V_6 -> V_308 , & V_6 -> V_309 ,
L_42 , 0 , F_158 ( 0xb0 >> 1 ) ) ;
}
switch ( V_6 -> V_305 ) {
case V_312 :
case V_313 : {
static const struct V_298 V_314 = {
F_159 ( L_43 , 0x6f )
} ;
F_160 ( L_44 ) ;
V_6 -> V_315 = F_161 ( & V_6 -> V_309 , & V_314 ) ;
}
case V_316 :
F_160 ( L_45 ) ;
}
F_162 ( V_279 , V_23 ) ;
F_5 ( & V_6 -> V_28 ) ;
F_95 ( V_6 , V_6 -> V_18 ) ;
F_73 ( V_6 ) ;
F_12 ( V_6 , 0 ) ;
V_23 -> V_278 = F_163 ( V_6 , V_23 -> V_111 ,
& V_291 , L_46 ) ;
F_164 ( V_23 -> V_278 , V_23 ) ;
V_205 = F_165 ( V_23 -> V_278 , V_138 ,
V_317 [ V_6 -> V_318 ] ) ;
if ( V_205 < 0 ) {
F_128 ( V_297 L_47 ,
V_6 -> V_118 ) ;
goto V_319;
}
F_128 ( V_288 L_48 ,
V_6 -> V_118 , F_49 ( V_23 -> V_278 ) ) ;
V_23 -> V_277 = F_163 ( V_6 , V_23 -> V_111 , & V_290 , L_49 ) ;
F_164 ( V_23 -> V_277 , V_23 ) ;
V_205 = F_165 ( V_23 -> V_277 , V_139 ,
V_320 [ V_6 -> V_318 ] ) ;
if ( V_205 < 0 ) {
F_128 ( V_297 L_50 ,
V_6 -> V_118 ) ;
goto V_319;
}
F_128 ( V_288 L_51 ,
V_6 -> V_118 , F_49 ( V_23 -> V_277 ) ) ;
if ( V_6 -> V_46 . V_136 . type == V_321 ) {
V_23 -> V_276 = F_163 ( V_6 , V_23 -> V_111 ,
& V_322 , L_52 ) ;
F_164 ( V_23 -> V_276 , V_23 ) ;
V_205 = F_165 ( V_23 -> V_276 , V_140 ,
V_323 [ V_6 -> V_318 ] ) ;
if ( V_205 < 0 ) {
F_128 ( V_297 L_53 ,
V_6 -> V_118 ) ;
goto V_319;
}
F_128 ( V_288 L_51 ,
V_6 -> V_118 , F_49 ( V_23 -> V_276 ) ) ;
}
if ( V_6 -> V_46 . V_218 != V_324 ) {
V_6 -> V_325 = F_166 ( V_326 , V_6 , L_54 ) ;
if ( F_167 ( V_6 -> V_325 ) ) {
V_205 = F_168 ( V_6 -> V_325 ) ;
F_128 ( V_297 L_55 ,
V_6 -> V_118 , V_205 ) ;
}
}
F_6 ( & V_6 -> V_28 ) ;
return 0 ;
V_319:
F_139 ( V_23 ) ;
F_169 ( V_279 -> V_270 , V_23 ) ;
F_6 ( & V_6 -> V_28 ) ;
V_289:
F_170 ( V_6 , V_23 -> V_111 ) ;
V_283:
F_62 ( V_23 ) ;
return V_205 ;
}
static void T_9 F_171 ( struct V_279 * V_279 )
{
struct V_22 * V_23 = F_172 ( V_279 ) ;
struct V_5 * V_6 = V_23 -> V_6 ;
if ( V_6 -> V_325 ) {
F_173 ( V_6 -> V_325 ) ;
V_6 -> V_325 = NULL ;
}
if ( V_6 -> V_327 )
F_174 ( V_6 ) ;
F_175 ( V_6 ) ;
F_176 ( V_279 ) ;
F_169 ( V_279 -> V_270 , V_23 ) ;
F_139 ( V_23 ) ;
F_162 ( V_279 , NULL ) ;
F_177 ( V_23 -> V_111 , & V_23 -> V_121 . V_125 ) ;
F_170 ( V_6 , V_23 -> V_111 ) ;
F_62 ( V_23 ) ;
}
static int F_178 ( struct V_279 * V_279 , T_10 V_93 )
{
struct V_22 * V_23 = F_172 ( V_279 ) ;
struct V_5 * V_6 = V_23 -> V_6 ;
F_132 ( & V_23 -> V_147 ) ;
if ( ! F_25 ( & V_23 -> V_121 . V_86 ) ) {
F_128 ( L_56 , V_6 -> V_118 ) ;
F_23 ( V_23 ) ;
F_179 ( & V_23 -> V_121 . V_89 ) ;
}
if ( ! F_25 ( & V_23 -> V_129 . V_86 ) ) {
F_128 ( L_57 , V_6 -> V_118 ) ;
F_180 ( V_23 ) ;
F_179 ( & V_23 -> V_129 . V_89 ) ;
}
F_134 ( & V_23 -> V_147 ) ;
if ( V_6 -> V_327 )
F_174 ( V_6 ) ;
F_175 ( V_6 ) ;
F_181 ( V_279 ) ;
if ( 0 != F_182 ( V_279 , F_183 ( V_279 , V_93 ) ) ) {
F_176 ( V_279 ) ;
V_23 -> V_93 . V_328 = 1 ;
}
return 0 ;
}
static int F_184 ( struct V_279 * V_279 )
{
struct V_22 * V_23 = F_172 ( V_279 ) ;
struct V_5 * V_6 = V_23 -> V_6 ;
int V_205 ;
if ( V_23 -> V_93 . V_328 ) {
V_205 = F_144 ( V_279 ) ;
if ( V_205 ) {
F_128 ( V_297 L_58 ,
V_6 -> V_118 ) ;
return V_205 ;
}
V_23 -> V_93 . V_328 = 0 ;
}
V_205 = F_182 ( V_279 , V_329 ) ;
if ( V_205 ) {
F_128 ( V_297 L_59 , V_6 -> V_118 ) ;
F_176 ( V_279 ) ;
V_23 -> V_93 . V_328 = 1 ;
return V_205 ;
}
F_185 ( V_279 ) ;
F_186 ( V_6 ) ;
if ( V_6 -> V_327 )
F_187 ( V_6 ) ;
F_16 ( V_78 , V_6 -> V_79 ) ;
F_132 ( & V_23 -> V_147 ) ;
if ( ! F_25 ( & V_23 -> V_121 . V_86 ) ) {
F_128 ( L_60 , V_6 -> V_118 ) ;
F_24 ( V_23 , & V_23 -> V_121 ) ;
}
if ( ! F_25 ( & V_23 -> V_129 . V_86 ) ) {
F_128 ( L_61 , V_6 -> V_118 ) ;
F_135 ( V_23 , & V_23 -> V_129 ) ;
}
F_134 ( & V_23 -> V_147 ) ;
return 0 ;
}
static int T_11 F_188 ( void )
{
F_128 ( V_288 L_62 ,
( V_212 >> 16 ) & 0xff ,
( V_212 >> 8 ) & 0xff ,
V_212 & 0xff ) ;
#ifdef F_189
F_128 ( V_288 L_63 ,
F_189 / 10000 , ( F_189 / 100 ) % 100 , F_189 % 100 ) ;
#endif
return F_190 ( & V_330 ) ;
}
static void T_12 F_191 ( void )
{
F_192 ( & V_330 ) ;
}
