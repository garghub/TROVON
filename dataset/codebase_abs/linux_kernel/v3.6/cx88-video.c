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
if ( V_11 -> V_31 . V_32 &&
V_11 -> V_31 . V_32 == V_33 ) {
F_17 ( V_11 , V_34 , V_35 ,
F_12 ( V_15 ) . V_30 , 0 , 0 ) ;
}
if ( F_12 ( V_15 ) . type != V_36 &&
F_12 ( V_15 ) . type != V_37 ) {
V_11 -> V_38 = V_39 ;
F_18 ( V_11 ) ;
} else {
F_14 ( V_40 , 0x0 ) ;
F_16 ( V_41 , V_42 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
F_20 ( V_11 , & V_47 [ V_48 ] ,
V_46 -> V_49 , V_46 -> V_50 . V_51 ) ;
F_21 ( V_11 , V_46 -> V_52 . V_53 , V_46 -> V_52 . V_54 , V_46 -> V_52 . V_55 ) ;
F_14 ( V_56 , V_46 -> V_57 -> V_58 | V_59 ) ;
F_14 ( V_60 , V_61 ) ;
V_44 -> V_62 = 1 ;
F_15 ( V_63 , V_11 -> V_64 | V_65 ) ;
F_15 ( V_66 , 0x0f0011 ) ;
F_15 ( V_67 , 0x06 ) ;
F_15 ( V_68 , ( 1 << 5 ) ) ;
F_15 ( V_69 , 0x11 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
F_16 ( V_69 , 0x11 ) ;
F_16 ( V_67 , 0x06 ) ;
F_16 ( V_63 , V_65 ) ;
F_16 ( V_66 , 0x0f0011 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_43 * V_44 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_45 * V_46 , * V_70 ;
if ( ! F_24 ( & V_44 -> V_71 ) ) {
V_46 = F_25 ( V_44 -> V_71 . V_72 , struct V_45 , V_52 . V_73 ) ;
F_6 ( 2 , L_4 ,
V_46 , V_46 -> V_52 . V_3 ) ;
F_19 ( V_6 , V_44 , V_46 ) ;
F_26 (buf, &q->active, vb.queue)
V_46 -> V_62 = V_44 -> V_62 ++ ;
F_27 ( & V_44 -> V_74 , V_75 + V_76 ) ;
return 0 ;
}
V_70 = NULL ;
for (; ; ) {
if ( F_24 ( & V_44 -> V_77 ) )
return 0 ;
V_46 = F_25 ( V_44 -> V_77 . V_72 , struct V_45 , V_52 . V_73 ) ;
if ( NULL == V_70 ) {
F_28 ( & V_46 -> V_52 . V_73 , & V_44 -> V_71 ) ;
F_19 ( V_6 , V_44 , V_46 ) ;
V_46 -> V_52 . V_78 = V_79 ;
V_46 -> V_62 = V_44 -> V_62 ++ ;
F_27 ( & V_44 -> V_74 , V_75 + V_76 ) ;
F_6 ( 2 , L_5 ,
V_46 , V_46 -> V_52 . V_3 ) ;
} else if ( V_70 -> V_52 . V_53 == V_46 -> V_52 . V_53 &&
V_70 -> V_52 . V_54 == V_46 -> V_52 . V_54 &&
V_70 -> V_57 == V_46 -> V_57 ) {
F_28 ( & V_46 -> V_52 . V_73 , & V_44 -> V_71 ) ;
V_46 -> V_52 . V_78 = V_79 ;
V_46 -> V_62 = V_44 -> V_62 ++ ;
V_70 -> V_50 . V_80 [ 1 ] = F_29 ( V_46 -> V_50 . V_51 ) ;
F_6 ( 2 , L_6 ,
V_46 , V_46 -> V_52 . V_3 ) ;
} else {
return 0 ;
}
V_70 = V_46 ;
}
}
static int
F_30 ( struct V_81 * V_44 , unsigned int * V_62 , unsigned int * V_82 )
{
struct V_7 * V_8 = V_44 -> V_83 ;
struct V_5 * V_6 = V_8 -> V_6 ;
* V_82 = V_6 -> V_57 -> V_84 * V_6 -> V_53 * V_6 -> V_54 >> 3 ;
if ( 0 == * V_62 )
* V_62 = 32 ;
if ( * V_82 * * V_62 > V_85 * 1024 * 1024 )
* V_62 = ( V_85 * 1024 * 1024 ) / * V_82 ;
return 0 ;
}
static int
F_31 ( struct V_81 * V_44 , struct V_86 * V_52 ,
enum V_87 V_55 )
{
struct V_7 * V_8 = V_44 -> V_83 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_45 * V_46 = F_32 ( V_52 , struct V_45 , V_52 ) ;
struct V_88 * V_51 = F_33 ( & V_46 -> V_52 ) ;
int V_89 , V_90 = 0 ;
F_10 ( NULL == V_6 -> V_57 ) ;
if ( V_6 -> V_53 < 48 || V_6 -> V_53 > F_34 ( V_11 -> V_91 ) ||
V_6 -> V_54 < 32 || V_6 -> V_54 > F_35 ( V_11 -> V_91 ) )
return - V_92 ;
V_46 -> V_52 . V_82 = ( V_6 -> V_53 * V_6 -> V_54 * V_6 -> V_57 -> V_84 ) >> 3 ;
if ( 0 != V_46 -> V_52 . V_93 && V_46 -> V_52 . V_94 < V_46 -> V_52 . V_82 )
return - V_92 ;
if ( V_46 -> V_57 != V_6 -> V_57 ||
V_46 -> V_52 . V_53 != V_6 -> V_53 ||
V_46 -> V_52 . V_54 != V_6 -> V_54 ||
V_46 -> V_52 . V_55 != V_55 ) {
V_46 -> V_57 = V_6 -> V_57 ;
V_46 -> V_52 . V_53 = V_6 -> V_53 ;
V_46 -> V_52 . V_54 = V_6 -> V_54 ;
V_46 -> V_52 . V_55 = V_55 ;
V_90 = 1 ;
}
if ( V_95 == V_46 -> V_52 . V_78 ) {
V_90 = 1 ;
if ( 0 != ( V_89 = F_36 ( V_44 , & V_46 -> V_52 , NULL ) ) )
goto V_96;
}
if ( V_90 ) {
V_46 -> V_49 = V_46 -> V_52 . V_53 * V_46 -> V_57 -> V_84 >> 3 ;
switch ( V_46 -> V_52 . V_55 ) {
case V_97 :
F_37 ( V_6 -> V_98 , & V_46 -> V_50 ,
V_51 -> V_99 , 0 , V_100 ,
V_46 -> V_49 , 0 , V_46 -> V_52 . V_54 ) ;
break;
case V_101 :
F_37 ( V_6 -> V_98 , & V_46 -> V_50 ,
V_51 -> V_99 , V_100 , 0 ,
V_46 -> V_49 , 0 , V_46 -> V_52 . V_54 ) ;
break;
case V_102 :
F_37 ( V_6 -> V_98 , & V_46 -> V_50 ,
V_51 -> V_99 , 0 , V_46 -> V_49 ,
V_46 -> V_49 , V_46 -> V_49 ,
V_46 -> V_52 . V_54 >> 1 ) ;
break;
case V_103 :
F_37 ( V_6 -> V_98 , & V_46 -> V_50 ,
V_51 -> V_99 ,
0 , V_46 -> V_49 * ( V_46 -> V_52 . V_54 >> 1 ) ,
V_46 -> V_49 , 0 ,
V_46 -> V_52 . V_54 >> 1 ) ;
break;
case V_104 :
F_37 ( V_6 -> V_98 , & V_46 -> V_50 ,
V_51 -> V_99 ,
V_46 -> V_49 * ( V_46 -> V_52 . V_54 >> 1 ) , 0 ,
V_46 -> V_49 , 0 ,
V_46 -> V_52 . V_54 >> 1 ) ;
break;
default:
F_38 () ;
}
}
F_6 ( 2 , L_7 ,
V_46 , V_46 -> V_52 . V_3 ,
V_6 -> V_53 , V_6 -> V_54 , V_6 -> V_57 -> V_84 , V_6 -> V_57 -> V_105 ,
( unsigned long ) V_46 -> V_50 . V_51 ) ;
V_46 -> V_52 . V_78 = V_106 ;
return 0 ;
V_96:
F_39 ( V_44 , V_46 ) ;
return V_89 ;
}
static void
F_40 ( struct V_81 * V_107 , struct V_86 * V_52 )
{
struct V_45 * V_46 = F_32 ( V_52 , struct V_45 , V_52 ) ;
struct V_45 * V_70 ;
struct V_7 * V_8 = V_107 -> V_83 ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_43 * V_44 = & V_6 -> V_108 ;
V_46 -> V_50 . V_80 [ 0 ] = F_29 ( V_109 | V_110 | V_111 ) ;
V_46 -> V_50 . V_80 [ 1 ] = F_29 ( V_44 -> V_112 . V_51 ) ;
if ( ! F_24 ( & V_44 -> V_77 ) ) {
F_41 ( & V_46 -> V_52 . V_73 , & V_44 -> V_77 ) ;
V_46 -> V_52 . V_78 = V_113 ;
F_6 ( 2 , L_8 ,
V_46 , V_46 -> V_52 . V_3 ) ;
} else if ( F_24 ( & V_44 -> V_71 ) ) {
F_41 ( & V_46 -> V_52 . V_73 , & V_44 -> V_71 ) ;
F_19 ( V_6 , V_44 , V_46 ) ;
V_46 -> V_52 . V_78 = V_79 ;
V_46 -> V_62 = V_44 -> V_62 ++ ;
F_27 ( & V_44 -> V_74 , V_75 + V_76 ) ;
F_6 ( 2 , L_9 ,
V_46 , V_46 -> V_52 . V_3 ) ;
} else {
V_70 = F_25 ( V_44 -> V_71 . V_70 , struct V_45 , V_52 . V_73 ) ;
if ( V_70 -> V_52 . V_53 == V_46 -> V_52 . V_53 &&
V_70 -> V_52 . V_54 == V_46 -> V_52 . V_54 &&
V_70 -> V_57 == V_46 -> V_57 ) {
F_41 ( & V_46 -> V_52 . V_73 , & V_44 -> V_71 ) ;
V_46 -> V_52 . V_78 = V_79 ;
V_46 -> V_62 = V_44 -> V_62 ++ ;
V_70 -> V_50 . V_80 [ 1 ] = F_29 ( V_46 -> V_50 . V_51 ) ;
F_6 ( 2 , L_10 ,
V_46 , V_46 -> V_52 . V_3 ) ;
} else {
F_41 ( & V_46 -> V_52 . V_73 , & V_44 -> V_77 ) ;
V_46 -> V_52 . V_78 = V_113 ;
F_6 ( 2 , L_11 ,
V_46 , V_46 -> V_52 . V_3 ) ;
}
}
}
static void F_42 ( struct V_81 * V_44 , struct V_86 * V_52 )
{
struct V_45 * V_46 = F_32 ( V_52 , struct V_45 , V_52 ) ;
F_39 ( V_44 , V_46 ) ;
}
static struct V_81 * F_43 ( struct V_114 * V_114 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
struct V_7 * V_8 = V_114 -> V_117 ;
switch ( V_116 -> V_118 ) {
case V_119 :
return & V_8 -> V_108 ;
case V_120 :
return & V_8 -> V_121 ;
default:
F_38 () ;
return NULL ;
}
}
static int F_45 ( struct V_114 * V_114 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
switch ( V_116 -> V_118 ) {
case V_119 :
return V_122 ;
case V_120 :
return V_123 ;
default:
F_38 () ;
return 0 ;
}
}
static int F_46 ( struct V_114 * V_114 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
struct V_5 * V_6 = F_47 ( V_114 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_7 * V_8 ;
enum V_124 type = 0 ;
int V_125 = 0 ;
switch ( V_116 -> V_118 ) {
case V_119 :
type = V_126 ;
break;
case V_120 :
type = V_127 ;
break;
case V_128 :
V_125 = 1 ;
break;
}
F_6 ( 1 , L_12 ,
F_48 ( V_116 ) , V_125 , V_129 [ type ] ) ;
V_8 = F_49 ( sizeof( * V_8 ) , V_130 ) ;
if ( F_50 ( ! V_8 ) )
return - V_131 ;
F_51 ( & V_8 -> V_8 , V_116 ) ;
V_114 -> V_117 = V_8 ;
V_8 -> V_6 = V_6 ;
F_4 ( & V_11 -> V_13 ) ;
F_52 ( & V_8 -> V_108 , & V_132 ,
& V_6 -> V_98 -> V_6 , & V_6 -> V_133 ,
V_126 ,
V_102 ,
sizeof( struct V_45 ) ,
V_8 , NULL ) ;
F_52 ( & V_8 -> V_121 , & V_134 ,
& V_6 -> V_98 -> V_6 , & V_6 -> V_133 ,
V_127 ,
V_103 ,
sizeof( struct V_45 ) ,
V_8 , NULL ) ;
if ( V_116 -> V_118 == V_128 ) {
F_6 ( 1 , L_13 ) ;
F_14 ( V_22 , V_11 -> V_31 . V_125 . V_20 ) ;
F_14 ( V_23 , V_11 -> V_31 . V_125 . V_17 ) ;
F_14 ( V_24 , V_11 -> V_31 . V_125 . V_18 ) ;
F_14 ( V_25 , V_11 -> V_31 . V_125 . V_19 ) ;
if ( V_11 -> V_31 . V_125 . V_30 ) {
if( V_11 -> V_31 . V_32 &&
V_11 -> V_31 . V_32 == V_33 ) {
F_17 ( V_11 , V_34 , V_35 ,
V_11 -> V_31 . V_125 . V_30 , 0 , 0 ) ;
}
V_11 -> V_38 = V_39 ;
F_18 ( V_11 ) ;
} else {
V_11 -> V_38 = V_135 ;
F_18 ( V_11 ) ;
F_53 ( V_11 , V_136 , 1 ) ;
}
F_17 ( V_11 , V_137 , V_138 ) ;
}
V_11 -> V_139 ++ ;
F_5 ( & V_11 -> V_13 ) ;
F_54 ( & V_8 -> V_8 ) ;
return 0 ;
}
static T_1
F_55 ( struct V_114 * V_114 , char T_2 * V_140 , T_3 V_62 , T_4 * V_141 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
struct V_7 * V_8 = V_114 -> V_117 ;
switch ( V_116 -> V_118 ) {
case V_119 :
if ( F_8 ( V_8 -> V_6 , V_122 ) )
return - V_142 ;
return F_56 ( & V_8 -> V_108 , V_140 , V_62 , V_141 ,
V_114 -> V_143 & V_144 ) ;
case V_120 :
if ( ! F_3 ( V_8 -> V_6 , V_8 , V_123 ) )
return - V_142 ;
return F_57 ( & V_8 -> V_121 , V_140 , V_62 , V_141 , 1 ,
V_114 -> V_143 & V_144 ) ;
default:
F_38 () ;
return 0 ;
}
}
static unsigned int
F_58 ( struct V_114 * V_114 , struct V_145 * V_146 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
struct V_7 * V_8 = V_114 -> V_117 ;
struct V_45 * V_46 ;
unsigned int V_89 = F_59 ( V_114 , V_146 ) ;
if ( V_116 -> V_118 == V_120 ) {
if ( ! F_3 ( V_8 -> V_6 , V_8 , V_123 ) )
return V_89 | V_147 ;
return V_89 | F_60 ( V_114 , & V_8 -> V_121 , V_146 ) ;
}
F_4 ( & V_8 -> V_108 . V_148 ) ;
if ( F_7 ( V_8 , V_122 ) ) {
if ( F_24 ( & V_8 -> V_108 . V_149 ) )
goto V_150;
V_46 = F_25 ( V_8 -> V_108 . V_149 . V_72 , struct V_45 , V_52 . V_149 ) ;
} else {
V_46 = (struct V_45 * ) V_8 -> V_108 . V_151 ;
if ( NULL == V_46 )
goto V_150;
}
F_61 ( V_114 , & V_46 -> V_52 . V_150 , V_146 ) ;
if ( V_46 -> V_52 . V_78 == V_152 ||
V_46 -> V_52 . V_78 == V_153 )
V_89 |= V_154 | V_155 ;
V_150:
F_5 ( & V_8 -> V_108 . V_148 ) ;
return V_89 ;
}
static int F_62 ( struct V_114 * V_114 )
{
struct V_7 * V_8 = V_114 -> V_117 ;
struct V_5 * V_6 = V_8 -> V_6 ;
if ( F_7 ( V_8 , V_156 ) ) {
F_9 ( V_6 , V_8 , V_156 ) ;
}
if ( F_7 ( V_8 , V_122 ) ) {
F_63 ( & V_8 -> V_108 ) ;
F_9 ( V_6 , V_8 , V_122 ) ;
}
if ( V_8 -> V_108 . V_151 ) {
F_42 ( & V_8 -> V_108 , V_8 -> V_108 . V_151 ) ;
F_64 ( V_8 -> V_108 . V_151 ) ;
}
if ( F_7 ( V_8 , V_123 ) ) {
F_65 ( & V_8 -> V_121 ) ;
F_9 ( V_6 , V_8 , V_123 ) ;
}
F_66 ( & V_8 -> V_108 ) ;
F_66 ( & V_8 -> V_121 ) ;
F_4 ( & V_6 -> V_11 -> V_13 ) ;
F_67 ( & V_8 -> V_8 ) ;
F_68 ( & V_8 -> V_8 ) ;
V_114 -> V_117 = NULL ;
F_64 ( V_8 ) ;
V_6 -> V_11 -> V_139 -- ;
if ( ! V_6 -> V_11 -> V_139 )
F_17 ( V_6 -> V_11 , V_11 , V_157 , 0 ) ;
F_5 ( & V_6 -> V_11 -> V_13 ) ;
return 0 ;
}
static int
F_69 ( struct V_114 * V_114 , struct V_158 * V_159 )
{
return F_70 ( F_43 ( V_114 ) , V_159 ) ;
}
static int F_71 ( struct V_160 * V_161 )
{
struct V_10 * V_11 =
F_32 ( V_161 -> V_162 , struct V_10 , V_163 ) ;
const struct V_164 * V_165 = V_161 -> V_166 ;
T_5 V_167 , V_168 ;
V_168 = V_165 -> V_168 ;
switch ( V_161 -> V_169 ) {
case V_170 :
V_167 = ( ( V_161 -> V_171 - V_165 -> V_172 ) << V_165 -> V_173 ) & V_165 -> V_168 ;
if ( V_11 -> V_91 & V_174 ) {
V_167 = V_167 << 8 | V_167 ;
} else {
V_167 = ( V_167 * 0x5a ) / 0x7f << 8 | V_167 ;
}
V_168 = 0xffff ;
break;
case V_175 :
V_167 = ( V_161 -> V_171 < 1 ? 0 : ( ( V_161 -> V_171 + 3 ) << 7 ) ) ;
F_13 ( V_28 , V_168 , V_167 ) ;
break;
case V_176 :
V_167 = ( ( V_161 -> V_171 - V_165 -> V_172 ) << V_165 -> V_173 ) & V_165 -> V_168 ;
break;
default:
V_167 = ( ( V_161 -> V_171 - V_165 -> V_172 ) << V_165 -> V_173 ) & V_165 -> V_168 ;
break;
}
F_6 ( 1 , L_14 ,
V_161 -> V_169 , V_161 -> V_105 , V_161 -> V_171 , V_165 -> V_177 , V_167 ,
V_168 , V_165 -> V_178 ? L_15 : L_16 ) ;
if ( V_165 -> V_178 )
F_72 ( V_165 -> V_178 , V_165 -> V_177 , V_168 , V_167 ) ;
else
F_13 ( V_165 -> V_177 , V_168 , V_167 ) ;
return 0 ;
}
static int F_73 ( struct V_160 * V_161 )
{
struct V_10 * V_11 =
F_32 ( V_161 -> V_162 , struct V_10 , V_179 ) ;
const struct V_164 * V_165 = V_161 -> V_166 ;
T_5 V_167 , V_168 ;
if ( V_11 -> V_31 . V_32 == V_33 ) {
switch ( V_161 -> V_169 ) {
case V_180 :
F_74 ( V_11 , V_161 -> V_169 , V_161 -> V_171 ) ;
break;
case V_181 :
F_74 ( V_11 , V_161 -> V_169 , ( V_161 -> V_171 ) ?
( 0x90 + V_161 -> V_171 ) << 8 : 0 ) ;
break;
case V_182 :
F_74 ( V_11 , V_161 -> V_169 , V_161 -> V_171 << 9 ) ;
break;
default:
break;
}
}
V_168 = V_165 -> V_168 ;
switch ( V_161 -> V_169 ) {
case V_182 :
V_167 = ( V_161 -> V_171 < 0x40 ) ? ( 0x7f - V_161 -> V_171 ) : ( V_161 -> V_171 - 0x40 ) ;
break;
case V_181 :
V_167 = 0x3f - ( V_161 -> V_171 & 0x3f ) ;
break;
default:
V_167 = ( ( V_161 -> V_171 - V_165 -> V_172 ) << V_165 -> V_173 ) & V_165 -> V_168 ;
break;
}
F_6 ( 1 , L_14 ,
V_161 -> V_169 , V_161 -> V_105 , V_161 -> V_171 , V_165 -> V_177 , V_167 ,
V_168 , V_165 -> V_178 ? L_15 : L_16 ) ;
if ( V_165 -> V_178 )
F_72 ( V_165 -> V_178 , V_165 -> V_177 , V_168 , V_167 ) ;
else
F_13 ( V_165 -> V_177 , V_168 , V_167 ) ;
return 0 ;
}
static int F_75 ( struct V_114 * V_114 , void * V_166 ,
struct V_183 * V_184 )
{
struct V_7 * V_8 = V_166 ;
struct V_5 * V_6 = V_8 -> V_6 ;
V_184 -> V_57 . V_185 . V_53 = V_6 -> V_53 ;
V_184 -> V_57 . V_185 . V_54 = V_6 -> V_54 ;
V_184 -> V_57 . V_185 . V_55 = V_8 -> V_108 . V_55 ;
V_184 -> V_57 . V_185 . V_186 = V_6 -> V_57 -> V_2 ;
V_184 -> V_57 . V_185 . V_187 =
( V_184 -> V_57 . V_185 . V_53 * V_6 -> V_57 -> V_84 ) >> 3 ;
V_184 -> V_57 . V_185 . V_188 =
V_184 -> V_57 . V_185 . V_54 * V_184 -> V_57 . V_185 . V_187 ;
V_184 -> V_57 . V_185 . V_189 = V_190 ;
return 0 ;
}
static int F_76 ( struct V_114 * V_114 , void * V_166 ,
struct V_183 * V_184 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
const struct V_1 * V_57 ;
enum V_87 V_55 ;
unsigned int V_191 , V_192 ;
V_57 = F_1 ( V_184 -> V_57 . V_185 . V_186 ) ;
if ( NULL == V_57 )
return - V_92 ;
V_55 = V_184 -> V_57 . V_185 . V_55 ;
V_191 = F_34 ( V_11 -> V_91 ) ;
V_192 = F_35 ( V_11 -> V_91 ) ;
if ( V_193 == V_55 ) {
V_55 = ( V_184 -> V_57 . V_185 . V_54 > V_192 / 2 )
? V_102
: V_101 ;
}
switch ( V_55 ) {
case V_97 :
case V_101 :
V_192 = V_192 / 2 ;
break;
case V_102 :
break;
default:
return - V_92 ;
}
V_184 -> V_57 . V_185 . V_55 = V_55 ;
F_77 ( & V_184 -> V_57 . V_185 . V_53 , 48 , V_191 , 2 ,
& V_184 -> V_57 . V_185 . V_54 , 32 , V_192 , 0 , 0 ) ;
V_184 -> V_57 . V_185 . V_187 =
( V_184 -> V_57 . V_185 . V_53 * V_57 -> V_84 ) >> 3 ;
V_184 -> V_57 . V_185 . V_188 =
V_184 -> V_57 . V_185 . V_54 * V_184 -> V_57 . V_185 . V_187 ;
return 0 ;
}
static int F_78 ( struct V_114 * V_114 , void * V_166 ,
struct V_183 * V_184 )
{
struct V_7 * V_8 = V_166 ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_194 = F_76 ( V_114 , V_166 , V_184 ) ;
if ( 0 != V_194 )
return V_194 ;
V_6 -> V_57 = F_1 ( V_184 -> V_57 . V_185 . V_186 ) ;
V_6 -> V_53 = V_184 -> V_57 . V_185 . V_53 ;
V_6 -> V_54 = V_184 -> V_57 . V_185 . V_54 ;
V_8 -> V_108 . V_55 = V_184 -> V_57 . V_185 . V_55 ;
return 0 ;
}
void F_79 ( struct V_114 * V_114 , struct V_10 * V_11 ,
struct V_195 * V_196 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
F_80 ( V_196 -> V_197 , V_11 -> V_31 . V_105 , sizeof( V_196 -> V_197 ) ) ;
V_196 -> V_198 = V_199 | V_200 ;
if ( V_100 != V_11 -> V_31 . V_201 )
V_196 -> V_198 |= V_202 ;
switch ( V_116 -> V_118 ) {
case V_128 :
V_196 -> V_198 = V_203 | V_202 ;
break;
case V_119 :
V_196 -> V_198 |= V_204 ;
break;
case V_120 :
V_196 -> V_198 |= V_205 ;
break;
}
V_196 -> V_206 = V_196 -> V_198 | V_204 |
V_205 | V_207 ;
if ( V_11 -> V_31 . V_125 . type == V_208 )
V_196 -> V_206 |= V_203 ;
}
static int F_81 ( struct V_114 * V_114 , void * V_166 ,
struct V_195 * V_196 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_166 ) -> V_6 ;
struct V_10 * V_11 = V_6 -> V_11 ;
strcpy ( V_196 -> V_209 , L_17 ) ;
sprintf ( V_196 -> V_210 , L_18 , F_82 ( V_6 -> V_98 ) ) ;
F_79 ( V_114 , V_11 , V_196 ) ;
return 0 ;
}
static int F_83 ( struct V_114 * V_114 , void * V_166 ,
struct V_211 * V_184 )
{
if ( F_50 ( V_184 -> V_212 >= F_2 ( V_4 ) ) )
return - V_92 ;
F_80 ( V_184 -> V_213 , V_4 [ V_184 -> V_212 ] . V_105 , sizeof( V_184 -> V_213 ) ) ;
V_184 -> V_186 = V_4 [ V_184 -> V_212 ] . V_2 ;
return 0 ;
}
static int F_84 ( struct V_114 * V_114 , void * V_166 , struct V_214 * V_215 )
{
return F_85 ( F_43 ( V_114 ) , V_215 ) ;
}
static int F_86 ( struct V_114 * V_114 , void * V_166 , struct V_216 * V_215 )
{
return F_87 ( F_43 ( V_114 ) , V_215 ) ;
}
static int F_88 ( struct V_114 * V_114 , void * V_166 , struct V_216 * V_215 )
{
return F_89 ( F_43 ( V_114 ) , V_215 ) ;
}
static int F_90 ( struct V_114 * V_114 , void * V_166 , struct V_216 * V_215 )
{
return F_91 ( F_43 ( V_114 ) , V_215 ,
V_114 -> V_143 & V_144 ) ;
}
static int F_92 ( struct V_114 * V_114 , void * V_166 , enum V_124 V_3 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
struct V_7 * V_8 = V_166 ;
struct V_5 * V_6 = V_8 -> V_6 ;
if ( ( V_116 -> V_118 == V_119 && V_3 != V_126 ) ||
( V_116 -> V_118 == V_120 && V_3 != V_127 ) )
return - V_92 ;
if ( F_50 ( ! F_3 ( V_6 , V_8 , F_45 ( V_114 ) ) ) )
return - V_142 ;
return F_93 ( F_43 ( V_114 ) ) ;
}
static int F_94 ( struct V_114 * V_114 , void * V_166 , enum V_124 V_3 )
{
struct V_115 * V_116 = F_44 ( V_114 ) ;
struct V_7 * V_8 = V_166 ;
struct V_5 * V_6 = V_8 -> V_6 ;
int V_194 , V_217 ;
if ( ( V_116 -> V_118 == V_119 && V_3 != V_126 ) ||
( V_116 -> V_118 == V_120 && V_3 != V_127 ) )
return - V_92 ;
V_217 = F_45 ( V_114 ) ;
V_194 = F_95 ( F_43 ( V_114 ) ) ;
if ( V_194 < 0 )
return V_194 ;
F_9 ( V_6 , V_8 , V_217 ) ;
return 0 ;
}
static int F_96 ( struct V_114 * V_114 , void * V_166 , T_6 * V_91 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
* V_91 = V_11 -> V_91 ;
return 0 ;
}
static int F_97 ( struct V_114 * V_114 , void * V_166 , T_6 * V_218 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
F_4 ( & V_11 -> V_13 ) ;
F_98 ( V_11 , * V_218 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
int F_99 ( struct V_10 * V_11 , struct V_219 * V_3 )
{
static const char * const V_220 [] = {
[ V_221 ] = L_19 ,
[ V_222 ] = L_20 ,
[ V_223 ] = L_21 ,
[ V_224 ] = L_22 ,
[ V_26 ] = L_23 ,
[ V_36 ] = L_24 ,
[ V_37 ] = L_25 ,
[ V_225 ] = L_26 ,
[ V_226 ] = L_27 ,
} ;
unsigned int V_227 = V_3 -> V_212 ;
if ( V_227 >= 4 )
return - V_92 ;
if ( 0 == F_12 ( V_227 ) . type )
return - V_92 ;
V_3 -> type = V_228 ;
strcpy ( V_3 -> V_105 , V_220 [ F_12 ( V_227 ) . type ] ) ;
if ( ( V_36 == F_12 ( V_227 ) . type ) ||
( V_37 == F_12 ( V_227 ) . type ) ) {
V_3 -> type = V_229 ;
}
V_3 -> V_230 = V_231 ;
return 0 ;
}
static int F_100 ( struct V_114 * V_114 , void * V_166 ,
struct V_219 * V_3 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
return F_99 ( V_11 , V_3 ) ;
}
static int F_101 ( struct V_114 * V_114 , void * V_166 , unsigned int * V_3 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
* V_3 = V_11 -> V_15 ;
return 0 ;
}
static int F_102 ( struct V_114 * V_114 , void * V_166 , unsigned int V_3 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
if ( V_3 >= 4 )
return - V_92 ;
if ( 0 == F_12 ( V_3 ) . type )
return - V_92 ;
F_4 ( & V_11 -> V_13 ) ;
F_103 ( V_11 ) ;
F_11 ( V_11 , V_3 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_104 ( struct V_114 * V_114 , void * V_166 ,
struct V_232 * V_233 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
T_5 V_177 ;
if ( F_50 ( V_100 == V_11 -> V_31 . V_201 ) )
return - V_92 ;
if ( 0 != V_233 -> V_212 )
return - V_92 ;
strcpy ( V_233 -> V_105 , L_24 ) ;
V_233 -> V_234 = V_235 ;
V_233 -> V_236 = 0xffffffffUL ;
F_17 ( V_11 , V_137 , V_237 , V_233 ) ;
F_105 ( V_11 , V_233 ) ;
V_177 = F_106 ( V_238 ) ;
V_233 -> signal = ( V_177 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_107 ( struct V_114 * V_114 , void * V_166 ,
struct V_232 * V_233 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
if ( V_100 == V_11 -> V_31 . V_201 )
return - V_92 ;
if ( 0 != V_233 -> V_212 )
return - V_92 ;
F_53 ( V_11 , V_233 -> V_239 , 1 ) ;
return 0 ;
}
static int F_108 ( struct V_114 * V_114 , void * V_166 ,
struct V_240 * V_184 )
{
struct V_7 * V_8 = V_166 ;
struct V_10 * V_11 = V_8 -> V_6 -> V_11 ;
if ( F_50 ( V_100 == V_11 -> V_31 . V_201 ) )
return - V_92 ;
if ( V_184 -> V_137 )
return - V_92 ;
V_184 -> V_241 = V_11 -> V_242 ;
F_17 ( V_11 , V_137 , V_243 , V_184 ) ;
return 0 ;
}
int F_109 ( struct V_10 * V_11 ,
struct V_240 * V_184 )
{
if ( F_50 ( V_100 == V_11 -> V_31 . V_201 ) )
return - V_92 ;
if ( F_50 ( V_184 -> V_137 != 0 ) )
return - V_92 ;
F_4 ( & V_11 -> V_13 ) ;
F_103 ( V_11 ) ;
F_17 ( V_11 , V_137 , V_244 , V_184 ) ;
F_17 ( V_11 , V_137 , V_243 , V_184 ) ;
V_11 -> V_242 = V_184 -> V_241 ;
F_110 ( 10 ) ;
F_18 ( V_11 ) ;
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
}
static int F_111 ( struct V_114 * V_114 , void * V_166 ,
struct V_240 * V_184 )
{
struct V_7 * V_8 = V_166 ;
struct V_10 * V_11 = V_8 -> V_6 -> V_11 ;
return F_109 ( V_11 , V_184 ) ;
}
static int F_112 ( struct V_114 * V_114 , void * V_166 ,
struct V_245 * V_246 )
{
if ( ! F_113 ( & V_246 -> V_247 ) )
return - V_92 ;
V_246 -> V_248 = 0 ;
V_246 -> V_249 = V_250 ;
return 0 ;
}
static int F_114 ( struct V_114 * V_114 , void * V_8 ,
struct V_251 * V_177 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_8 ) -> V_6 -> V_11 ;
if ( ! F_113 ( & V_177 -> V_247 ) )
return - V_92 ;
V_177 -> V_171 = F_106 ( V_177 -> V_177 & 0xffffff ) ;
V_177 -> V_82 = 4 ;
return 0 ;
}
static int F_115 ( struct V_114 * V_114 , void * V_8 ,
struct V_251 * V_177 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_8 ) -> V_6 -> V_11 ;
if ( ! F_113 ( & V_177 -> V_247 ) )
return - V_92 ;
F_14 ( V_177 -> V_177 & 0xffffff , V_177 -> V_171 ) ;
return 0 ;
}
static int F_116 ( struct V_114 * V_114 , void * V_166 ,
struct V_232 * V_233 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
if ( F_50 ( V_233 -> V_212 > 0 ) )
return - V_92 ;
strcpy ( V_233 -> V_105 , L_28 ) ;
F_17 ( V_11 , V_137 , V_237 , V_233 ) ;
return 0 ;
}
static int F_117 ( struct V_114 * V_114 , void * V_166 ,
struct V_232 * V_233 )
{
struct V_10 * V_11 = ( (struct V_7 * ) V_166 ) -> V_6 -> V_11 ;
if ( 0 != V_233 -> V_212 )
return - V_92 ;
if ( V_233 -> V_239 > V_136 )
V_233 -> V_239 = V_136 ;
F_17 ( V_11 , V_137 , V_252 , V_233 ) ;
return 0 ;
}
static void F_118 ( unsigned long V_140 )
{
struct V_5 * V_6 = (struct V_5 * ) V_140 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_43 * V_44 = & V_6 -> V_108 ;
struct V_45 * V_46 ;
unsigned long V_253 ;
F_119 ( V_11 , & V_47 [ V_48 ] ) ;
F_16 ( V_69 , 0x11 ) ;
F_16 ( V_67 , 0x06 ) ;
F_120 ( & V_6 -> V_133 , V_253 ) ;
while ( ! F_24 ( & V_44 -> V_71 ) ) {
V_46 = F_25 ( V_44 -> V_71 . V_72 , struct V_45 , V_52 . V_73 ) ;
F_121 ( & V_46 -> V_52 . V_73 ) ;
V_46 -> V_52 . V_78 = V_153 ;
F_122 ( & V_46 -> V_52 . V_150 ) ;
F_123 ( L_29 , V_11 -> V_105 ,
V_46 , V_46 -> V_52 . V_3 , ( unsigned long ) V_46 -> V_50 . V_51 ) ;
}
F_23 ( V_6 , V_44 ) ;
F_124 ( & V_6 -> V_133 , V_253 ) ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
T_5 V_254 , V_168 , V_62 ;
V_254 = F_106 ( V_255 ) ;
V_168 = F_106 ( V_66 ) ;
if ( 0 == ( V_254 & V_168 ) )
return;
F_14 ( V_255 , V_254 ) ;
if ( V_256 || ( V_254 & V_168 & ~ 0xff ) )
F_126 ( V_11 -> V_105 , L_30 ,
V_257 , F_2 ( V_257 ) ,
V_254 , V_168 ) ;
if ( V_254 & ( 1 << 16 ) ) {
F_123 ( V_258 L_31 , V_11 -> V_105 ) ;
F_16 ( V_69 , 0x11 ) ;
F_16 ( V_67 , 0x06 ) ;
F_119 ( V_11 , & V_47 [ V_48 ] ) ;
}
if ( V_254 & 0x01 ) {
F_127 ( & V_6 -> V_133 ) ;
V_62 = F_106 ( V_259 ) ;
F_128 ( V_11 , & V_6 -> V_108 , V_62 ) ;
F_129 ( & V_6 -> V_133 ) ;
}
if ( V_254 & 0x08 ) {
F_127 ( & V_6 -> V_133 ) ;
V_62 = F_106 ( V_260 ) ;
F_128 ( V_11 , & V_6 -> V_121 , V_62 ) ;
F_129 ( & V_6 -> V_133 ) ;
}
if ( V_254 & 0x10 ) {
F_6 ( 2 , L_32 ) ;
F_127 ( & V_6 -> V_133 ) ;
F_23 ( V_6 , & V_6 -> V_108 ) ;
F_129 ( & V_6 -> V_133 ) ;
}
if ( V_254 & 0x80 ) {
F_6 ( 2 , L_33 ) ;
F_127 ( & V_6 -> V_133 ) ;
F_130 ( V_6 , & V_6 -> V_121 ) ;
F_129 ( & V_6 -> V_133 ) ;
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
( V_11 -> V_64 | V_65 ) ;
if ( 0 == V_254 )
goto V_266;
F_14 ( V_265 , V_254 ) ;
V_264 = 1 ;
if ( V_254 & V_11 -> V_64 )
F_132 ( V_11 , V_254 ) ;
if ( V_254 & V_65 )
F_125 ( V_6 ) ;
} ;
if ( 10 == V_263 ) {
F_123 ( V_258 L_34 ,
V_11 -> V_105 ) ;
F_14 ( V_63 , 0 ) ;
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
static int T_8 F_138 ( struct V_270 * V_270 ,
const struct V_271 * V_272 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_194 ;
int V_3 ;
V_6 = F_49 ( sizeof( * V_6 ) , V_130 ) ;
if ( NULL == V_6 )
return - V_131 ;
V_6 -> V_98 = V_270 ;
if ( F_139 ( V_270 ) ) {
V_194 = - V_273 ;
goto V_274;
}
V_11 = F_140 ( V_6 -> V_98 ) ;
if ( NULL == V_11 ) {
V_194 = - V_92 ;
goto V_274;
}
V_6 -> V_11 = V_11 ;
V_6 -> V_275 = V_270 -> V_248 ;
F_141 ( V_270 , V_276 , & V_6 -> V_277 ) ;
F_123 ( V_278 L_35
L_36 , V_11 -> V_105 ,
F_82 ( V_270 ) , V_6 -> V_275 , V_270 -> V_261 ,
V_6 -> V_277 , ( unsigned long long ) F_142 ( V_270 , 0 ) ) ;
F_143 ( V_270 ) ;
if ( ! F_144 ( V_270 , F_145 ( 32 ) ) ) {
F_123 ( L_37 , V_11 -> V_105 ) ;
V_194 = - V_273 ;
goto V_279;
}
F_146 ( & V_6 -> V_133 ) ;
V_11 -> V_91 = V_280 ;
F_147 ( & V_6 -> V_108 . V_71 ) ;
F_147 ( & V_6 -> V_108 . V_77 ) ;
V_6 -> V_108 . V_74 . V_281 = F_118 ;
V_6 -> V_108 . V_74 . V_140 = ( unsigned long ) V_6 ;
F_148 ( & V_6 -> V_108 . V_74 ) ;
F_149 ( V_6 -> V_98 , & V_6 -> V_108 . V_112 ,
V_69 , 0x11 , 0x00 ) ;
F_147 ( & V_6 -> V_121 . V_71 ) ;
F_147 ( & V_6 -> V_121 . V_77 ) ;
V_6 -> V_121 . V_74 . V_281 = V_282 ;
V_6 -> V_121 . V_74 . V_140 = ( unsigned long ) V_6 ;
F_148 ( & V_6 -> V_121 . V_74 ) ;
F_149 ( V_6 -> V_98 , & V_6 -> V_121 . V_112 ,
V_69 , 0x88 , 0x00 ) ;
V_194 = F_150 ( V_270 -> V_261 , F_131 ,
V_283 | V_284 , V_11 -> V_105 , V_6 ) ;
if ( V_194 < 0 ) {
F_123 ( V_285 L_38 ,
V_11 -> V_105 , V_270 -> V_261 ) ;
goto V_279;
}
F_15 ( V_63 , V_11 -> V_64 ) ;
for ( V_3 = 0 ; V_3 < V_286 ; V_3 ++ ) {
const struct V_164 * V_165 = & V_287 [ V_3 ] ;
struct V_160 * V_288 ;
V_288 = F_151 ( & V_11 -> V_179 , & V_289 ,
V_165 -> V_169 , V_165 -> V_290 , V_165 -> V_291 , V_165 -> V_292 , V_165 -> V_293 ) ;
if ( V_288 == NULL ) {
V_194 = V_11 -> V_179 . error ;
goto V_279;
}
V_288 -> V_166 = ( void * ) V_165 ;
}
for ( V_3 = 0 ; V_3 < V_294 ; V_3 ++ ) {
const struct V_164 * V_165 = & V_295 [ V_3 ] ;
struct V_160 * V_288 ;
V_288 = F_151 ( & V_11 -> V_163 , & V_296 ,
V_165 -> V_169 , V_165 -> V_290 , V_165 -> V_291 , V_165 -> V_292 , V_165 -> V_293 ) ;
if ( V_288 == NULL ) {
V_194 = V_11 -> V_163 . error ;
goto V_279;
}
V_288 -> V_166 = ( void * ) V_165 ;
if ( V_288 -> V_169 == V_176 )
V_11 -> V_297 = V_288 ;
}
F_152 ( & V_11 -> V_163 , & V_11 -> V_179 ) ;
if ( V_11 -> V_31 . V_32 == V_33 ) {
struct V_298 V_299 = {
. type = L_39 ,
. V_300 = 0x36 >> 1 ,
. V_301 = & V_11 -> V_302 ,
} ;
struct V_303 * V_304 ;
if ( V_11 -> V_305 == V_306 )
V_11 -> V_302 . V_307 = true ;
else
V_11 -> V_302 . V_307 = false ;
V_304 = F_153 ( & V_11 -> V_308 , & V_11 -> V_309 ,
& V_299 , NULL ) ;
if ( V_304 != NULL ) {
V_11 -> V_310 = V_304 ;
V_304 -> V_311 = V_312 ;
}
}
if ( V_11 -> V_31 . V_32 == V_313 ) {
F_154 ( & V_11 -> V_308 , & V_11 -> V_309 ,
L_40 , 0 , F_155 ( 0xb0 >> 1 ) ) ;
}
switch ( V_11 -> V_305 ) {
case V_314 :
case V_315 : {
static const struct V_298 V_316 = {
F_156 ( L_41 , 0x6f )
} ;
F_157 ( L_42 ) ;
V_11 -> V_317 = F_158 ( & V_11 -> V_309 , & V_316 ) ;
}
case V_318 :
F_157 ( L_43 ) ;
}
F_159 ( V_270 , V_6 ) ;
V_6 -> V_53 = 320 ;
V_6 -> V_54 = 240 ;
V_6 -> V_57 = F_1 ( V_319 ) ;
F_4 ( & V_11 -> V_13 ) ;
F_98 ( V_11 , V_11 -> V_91 ) ;
F_160 ( & V_11 -> V_163 ) ;
F_160 ( & V_11 -> V_179 ) ;
F_11 ( V_11 , 0 ) ;
V_6 -> V_269 = F_161 ( V_11 , V_6 -> V_98 ,
& V_320 , L_44 ) ;
F_162 ( V_6 -> V_269 , V_6 ) ;
V_6 -> V_269 -> V_321 = & V_11 -> V_163 ;
V_194 = F_163 ( V_6 -> V_269 , V_119 ,
V_322 [ V_11 -> V_323 ] ) ;
if ( V_194 < 0 ) {
F_123 ( V_285 L_45 ,
V_11 -> V_105 ) ;
goto V_324;
}
F_123 ( V_278 L_46 ,
V_11 -> V_105 , F_48 ( V_6 -> V_269 ) ) ;
V_6 -> V_268 = F_161 ( V_11 , V_6 -> V_98 , & V_325 , L_47 ) ;
F_162 ( V_6 -> V_268 , V_6 ) ;
V_194 = F_163 ( V_6 -> V_268 , V_120 ,
V_326 [ V_11 -> V_323 ] ) ;
if ( V_194 < 0 ) {
F_123 ( V_285 L_48 ,
V_11 -> V_105 ) ;
goto V_324;
}
F_123 ( V_278 L_49 ,
V_11 -> V_105 , F_48 ( V_6 -> V_268 ) ) ;
if ( V_11 -> V_31 . V_125 . type == V_208 ) {
V_6 -> V_267 = F_161 ( V_11 , V_6 -> V_98 ,
& V_327 , L_50 ) ;
F_162 ( V_6 -> V_267 , V_6 ) ;
V_6 -> V_267 -> V_321 = & V_11 -> V_179 ;
V_194 = F_163 ( V_6 -> V_267 , V_128 ,
V_328 [ V_11 -> V_323 ] ) ;
if ( V_194 < 0 ) {
F_123 ( V_285 L_51 ,
V_11 -> V_105 ) ;
goto V_324;
}
F_123 ( V_278 L_49 ,
V_11 -> V_105 , F_48 ( V_6 -> V_267 ) ) ;
}
if ( V_11 -> V_31 . V_201 != V_329 ) {
V_11 -> V_330 = F_164 ( V_331 , V_11 , L_52 ) ;
if ( F_165 ( V_11 -> V_330 ) ) {
V_194 = F_166 ( V_11 -> V_330 ) ;
F_123 ( V_285 L_53 ,
V_11 -> V_105 , V_194 ) ;
}
}
F_5 ( & V_11 -> V_13 ) ;
return 0 ;
V_324:
F_134 ( V_6 ) ;
F_167 ( V_270 -> V_261 , V_6 ) ;
F_5 ( & V_11 -> V_13 ) ;
V_279:
F_168 ( V_11 , V_6 -> V_98 ) ;
V_274:
F_64 ( V_6 ) ;
return V_194 ;
}
static void T_9 F_169 ( struct V_270 * V_270 )
{
struct V_5 * V_6 = F_170 ( V_270 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
if ( V_11 -> V_330 ) {
F_171 ( V_11 -> V_330 ) ;
V_11 -> V_330 = NULL ;
}
if ( V_11 -> V_332 )
F_172 ( V_11 ) ;
F_173 ( V_11 ) ;
F_174 ( V_270 ) ;
F_167 ( V_270 -> V_261 , V_6 ) ;
F_134 ( V_6 ) ;
F_159 ( V_270 , NULL ) ;
F_175 ( V_6 -> V_98 , & V_6 -> V_108 . V_112 ) ;
F_168 ( V_11 , V_6 -> V_98 ) ;
F_64 ( V_6 ) ;
}
static int F_176 ( struct V_270 * V_270 , T_10 V_78 )
{
struct V_5 * V_6 = F_170 ( V_270 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
F_127 ( & V_6 -> V_133 ) ;
if ( ! F_24 ( & V_6 -> V_108 . V_71 ) ) {
F_123 ( L_54 , V_11 -> V_105 ) ;
F_22 ( V_6 ) ;
F_177 ( & V_6 -> V_108 . V_74 ) ;
}
if ( ! F_24 ( & V_6 -> V_121 . V_71 ) ) {
F_123 ( L_55 , V_11 -> V_105 ) ;
F_178 ( V_6 ) ;
F_177 ( & V_6 -> V_121 . V_74 ) ;
}
F_129 ( & V_6 -> V_133 ) ;
if ( V_11 -> V_332 )
F_172 ( V_11 ) ;
F_173 ( V_11 ) ;
F_179 ( V_270 ) ;
if ( 0 != F_180 ( V_270 , F_181 ( V_270 , V_78 ) ) ) {
F_174 ( V_270 ) ;
V_6 -> V_78 . V_333 = 1 ;
}
return 0 ;
}
static int F_182 ( struct V_270 * V_270 )
{
struct V_5 * V_6 = F_170 ( V_270 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
int V_194 ;
if ( V_6 -> V_78 . V_333 ) {
V_194 = F_139 ( V_270 ) ;
if ( V_194 ) {
F_123 ( V_285 L_56 ,
V_11 -> V_105 ) ;
return V_194 ;
}
V_6 -> V_78 . V_333 = 0 ;
}
V_194 = F_180 ( V_270 , V_334 ) ;
if ( V_194 ) {
F_123 ( V_285 L_57 , V_11 -> V_105 ) ;
F_174 ( V_270 ) ;
V_6 -> V_78 . V_333 = 1 ;
return V_194 ;
}
F_183 ( V_270 ) ;
F_184 ( V_11 ) ;
if ( V_11 -> V_332 )
F_185 ( V_11 ) ;
F_15 ( V_63 , V_11 -> V_64 ) ;
F_127 ( & V_6 -> V_133 ) ;
if ( ! F_24 ( & V_6 -> V_108 . V_71 ) ) {
F_123 ( L_58 , V_11 -> V_105 ) ;
F_23 ( V_6 , & V_6 -> V_108 ) ;
}
if ( ! F_24 ( & V_6 -> V_121 . V_71 ) ) {
F_123 ( L_59 , V_11 -> V_105 ) ;
F_130 ( V_6 , & V_6 -> V_121 ) ;
}
F_129 ( & V_6 -> V_133 ) ;
return 0 ;
}
static int T_11 F_186 ( void )
{
F_123 ( V_278 L_60 ,
V_335 ) ;
return F_187 ( & V_336 ) ;
}
static void T_12 F_188 ( void )
{
F_189 ( & V_336 ) ;
}
