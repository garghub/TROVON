static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
F_3 ( V_5 L_1 , V_6 ,
( V_2 & 0xff ) ,
( ( V_2 >> 8 ) & 0xff ) ,
( ( V_2 >> 16 ) & 0xff ) ,
( ( V_2 >> 24 ) & 0xff )
) ;
return NULL ;
}
void F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_11 )
{
struct V_12 * V_13 ;
int V_14 ;
for ( V_14 = 0 ; ; V_14 ++ ) {
if ( F_5 ( & V_10 -> V_15 ) )
break;
V_13 = F_6 ( V_10 -> V_15 . V_16 ,
struct V_12 , V_17 . V_18 ) ;
if ( ( V_19 ) ( V_11 - V_13 -> V_11 ) < 0 )
break;
F_7 ( & V_13 -> V_17 . V_20 ) ;
F_8 ( 2 , L_2 , V_13 , V_13 -> V_17 . V_3 ,
V_11 , V_13 -> V_11 ) ;
V_13 -> V_17 . V_21 = V_22 ;
F_9 ( & V_13 -> V_17 . V_18 ) ;
F_10 ( & V_13 -> V_17 . V_23 ) ;
}
if ( F_5 ( & V_10 -> V_15 ) )
F_11 ( & V_10 -> V_24 ) ;
else
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
if ( V_14 != 1 )
F_3 ( V_5 L_3 ,
V_6 , V_14 ) ;
}
int F_13 ( struct V_7 * V_8 , T_2 V_27 )
{
F_8 ( 1 , L_4 ,
V_6 ,
( unsigned int ) V_27 ,
F_14 ( V_27 ) ) ;
V_8 -> V_28 = V_27 ;
F_15 ( V_8 , V_29 , V_30 , V_27 ) ;
return 0 ;
}
static struct V_31 * F_16 ( struct V_7 * V_8 ,
struct V_32 * V_33 ,
struct V_31 * V_34 ,
char * type )
{
struct V_31 * V_35 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_35 = F_17 () ;
if ( NULL == V_35 )
return NULL ;
* V_35 = * V_34 ;
V_35 -> V_36 = & V_8 -> V_36 ;
V_35 -> V_37 = V_38 ;
snprintf ( V_35 -> V_39 , sizeof( V_35 -> V_39 ) , L_6 ,
V_40 [ V_8 -> V_41 ] . V_39 , type ) ;
F_18 ( V_35 , V_8 ) ;
return V_35 ;
}
static int F_19 ( struct V_42 * V_43 )
{
int V_3 ;
if ( V_43 -> V_44 < V_45 ||
V_43 -> V_44 >= V_46 )
return - V_47 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ )
if ( V_49 [ V_3 ] . V_50 . V_44 == V_43 -> V_44 )
break;
if ( V_3 == V_48 ) {
* V_43 = V_51 ;
return 0 ;
}
* V_43 = V_49 [ V_3 ] . V_50 ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_52 * V_53 ,
unsigned int V_54 )
{
F_8 ( 1 , L_5 , V_6 ) ;
if ( V_53 -> V_55 & V_54 )
return 1 ;
F_21 ( & V_8 -> V_56 ) ;
if ( V_8 -> V_55 & V_54 ) {
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
V_53 -> V_55 |= V_54 ;
V_8 -> V_55 |= V_54 ;
F_8 ( 1 , L_7 , V_54 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 1 ;
}
static int F_23 ( struct V_52 * V_53 , unsigned int V_54 )
{
return V_53 -> V_55 & V_54 ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_54 )
{
return V_8 -> V_55 & V_54 ;
}
static void F_25 ( struct V_7 * V_8 , struct V_52 * V_53 ,
unsigned int V_57 )
{
F_26 ( ( V_53 -> V_55 & V_57 ) != V_57 ) ;
F_8 ( 1 , L_5 , V_6 ) ;
F_21 ( & V_8 -> V_56 ) ;
V_53 -> V_55 &= ~ V_57 ;
V_8 -> V_55 &= ~ V_57 ;
F_8 ( 1 , L_8 , V_57 ) ;
F_22 ( & V_8 -> V_56 ) ;
}
int F_27 ( struct V_7 * V_8 , T_3 V_58 , T_3 V_59 )
{
T_3 V_13 [] = { V_58 , V_59 } ;
struct V_60 V_61 = { . V_62 = 0x98 >> 1 ,
. V_63 = 0 , . V_13 = V_13 , . V_64 = 2 } ;
return F_28 ( & V_8 -> V_65 [ 2 ] . V_66 , & V_61 , 1 ) ;
}
T_3 F_29 ( struct V_7 * V_8 , T_3 V_58 )
{
int V_67 ;
T_3 V_68 [] = { V_58 } ;
T_3 V_69 [] = { 0 } ;
struct V_60 V_61 [] = {
{ . V_62 = 0x98 >> 1 , . V_63 = 0 , . V_13 = V_68 , . V_64 = 1 } ,
{ . V_62 = 0x98 >> 1 , . V_63 = V_70 , . V_13 = V_69 , . V_64 = 1 }
} ;
V_67 = F_28 ( & V_8 -> V_65 [ 2 ] . V_66 , & V_61 [ 0 ] , 2 ) ;
if ( V_67 != 2 )
F_3 ( V_5 L_9 , V_6 ) ;
return V_69 [ 0 ] ;
}
static void F_30 ( struct V_7 * V_8 )
{
int V_3 ;
F_8 ( 1 , L_10 ) ;
for ( V_3 = 0 ; V_3 < 0x24 ; V_3 ++ ) {
F_8 ( 1 , L_11 , V_3 ,
F_29 ( V_8 , V_3 ) ) ;
}
}
static int F_31 ( struct V_7 * V_8 , int V_71 )
{
T_3 V_72 ;
F_8 ( 1 , L_12 , V_6 , V_71 ) ;
if ( V_71 == 1 )
V_72 = F_29 ( V_8 , V_73 ) & ~ V_74 ;
else if ( V_71 == 2 )
V_72 = F_29 ( V_8 , V_73 ) | V_74 ;
else
return - V_47 ;
V_72 |= 0x20 ;
F_27 ( V_8 , V_73 , V_72 ) ;
F_27 ( V_8 , V_75 , 0 ) ;
if ( V_76 )
F_30 ( V_8 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 , unsigned int V_71 )
{
F_8 ( 1 , L_13 ,
V_6 ,
V_71 , F_33 ( V_71 ) -> V_77 ,
F_33 ( V_71 ) -> V_78 , F_33 ( V_71 ) -> V_79 ,
F_33 ( V_71 ) -> V_80 , F_33 ( V_71 ) -> V_81 ) ;
V_8 -> V_71 = V_71 ;
if ( V_8 -> V_41 == V_82 ||
V_8 -> V_41 == V_83 ||
V_8 -> V_41 == V_84 ) {
if ( F_33 ( V_71 ) -> type == V_85 )
F_34 ( V_8 , V_86 ) ;
}
F_35 ( V_8 -> V_87 , V_88 , V_89 ,
F_33 ( V_71 ) -> V_77 , 0 , 0 ) ;
if ( ( V_8 -> V_41 == V_90 ) ||
( V_8 -> V_41 == V_91 ) ||
( V_8 -> V_41 == V_92 ) ||
( V_8 -> V_41 == V_93 ) ||
( V_8 -> V_41 == V_94 ) ||
( V_8 -> V_41 == V_95 ) ||
( V_8 -> V_41 == V_84 ) ||
( V_8 -> V_41 == V_96 ) ) {
F_35 ( V_8 -> V_87 , V_97 , V_89 ,
F_33 ( V_71 ) -> V_98 , 0 , 0 ) ;
if ( F_33 ( V_71 ) -> V_98 == V_99 )
F_31 ( V_8 , 1 ) ;
else if ( F_33 ( V_71 ) -> V_98 == V_100 )
F_31 ( V_8 , 2 ) ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , unsigned int V_71 )
{
F_8 ( 1 , L_14 , V_6 , V_71 ) ;
if ( F_33 ( V_71 ) -> V_98 == V_99 )
F_31 ( V_8 , 1 ) ;
else if ( F_33 ( V_71 ) -> V_98 == V_100 )
F_31 ( V_8 , 2 ) ;
else {
F_31 ( V_8 , 1 ) ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_12 * V_13 )
{
F_8 ( 1 , L_5 , V_6 ) ;
F_38 ( V_101 , 0x11 ) ;
F_39 ( V_8 , & V_8 -> V_102 [ V_103 ] ,
V_13 -> V_104 , V_13 -> V_105 . V_106 ) ;
F_40 ( V_107 , 3 ) ;
V_10 -> V_11 = 1 ;
F_41 ( V_8 , 0x01 ) ;
F_42 ( V_108 , 0x000011 ) ;
F_42 ( V_109 , ( 1 << 5 ) ) ;
F_42 ( V_101 , 0x11 ) ;
return 0 ;
}
static int F_43 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 , * V_110 ;
struct V_111 * V_112 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ! F_5 ( & V_10 -> V_15 ) ) {
V_13 = F_6 ( V_10 -> V_15 . V_16 , struct V_12 ,
V_17 . V_18 ) ;
F_8 ( 2 , L_15 ,
V_13 , V_13 -> V_17 . V_3 ) ;
F_37 ( V_8 , V_10 , V_13 ) ;
F_44 (item, &q->active) {
V_13 = F_6 ( V_112 , struct V_12 ,
V_17 . V_18 ) ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
}
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
return 0 ;
}
V_110 = NULL ;
for (; ; ) {
if ( F_5 ( & V_10 -> V_113 ) )
return 0 ;
V_13 = F_6 ( V_10 -> V_113 . V_16 , struct V_12 ,
V_17 . V_18 ) ;
if ( NULL == V_110 ) {
F_45 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
F_37 ( V_8 , V_10 , V_13 ) ;
V_13 -> V_17 . V_21 = V_114 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
F_8 ( 2 , L_16 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else if ( V_110 -> V_17 . V_115 == V_13 -> V_17 . V_115 &&
V_110 -> V_17 . V_116 == V_13 -> V_17 . V_116 &&
V_110 -> V_117 == V_13 -> V_117 ) {
F_45 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
V_13 -> V_17 . V_21 = V_114 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
V_110 -> V_105 . V_118 [ 1 ] = F_46 ( V_13 -> V_105 . V_106 ) ;
V_110 -> V_105 . V_118 [ 2 ] = F_46 ( 0 ) ;
F_8 ( 2 , L_17 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
return 0 ;
}
V_110 = V_13 ;
}
}
static int F_47 ( struct V_119 * V_10 , unsigned int * V_11 ,
unsigned int * V_120 )
{
struct V_52 * V_53 = V_10 -> V_121 ;
* V_120 = V_53 -> V_117 -> V_122 * V_53 -> V_115 * V_53 -> V_116 >> 3 ;
if ( 0 == * V_11 )
* V_11 = 32 ;
if ( * V_120 * * V_11 > V_123 * 1024 * 1024 )
* V_11 = ( V_123 * 1024 * 1024 ) / * V_120 ;
return 0 ;
}
static int F_48 ( struct V_119 * V_10 , struct V_124 * V_17 ,
enum V_125 V_126 )
{
struct V_52 * V_53 = V_10 -> V_121 ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_12 * V_13 =
F_49 ( V_17 , struct V_12 , V_17 ) ;
int V_127 , V_128 = 0 ;
T_1 V_129 , V_130 ;
struct V_131 * V_106 = F_50 ( & V_13 -> V_17 ) ;
int V_132 ;
F_26 ( NULL == V_53 -> V_117 ) ;
if ( V_53 -> V_115 < 48 || V_53 -> V_115 > F_51 ( V_8 -> V_28 ) ||
V_53 -> V_116 < 32 || V_53 -> V_116 > F_52 ( V_8 -> V_28 ) )
return - V_47 ;
V_13 -> V_17 . V_120 = ( V_53 -> V_115 * V_53 -> V_116 * V_53 -> V_117 -> V_122 ) >> 3 ;
if ( 0 != V_13 -> V_17 . V_133 && V_13 -> V_17 . V_134 < V_13 -> V_17 . V_120 )
return - V_47 ;
if ( V_13 -> V_117 != V_53 -> V_117 ||
V_13 -> V_17 . V_115 != V_53 -> V_115 ||
V_13 -> V_17 . V_116 != V_53 -> V_116 ||
V_13 -> V_17 . V_126 != V_126 ) {
V_13 -> V_117 = V_53 -> V_117 ;
V_13 -> V_17 . V_115 = V_53 -> V_115 ;
V_13 -> V_17 . V_116 = V_53 -> V_116 ;
V_13 -> V_17 . V_126 = V_126 ;
V_128 = 1 ;
}
if ( V_135 == V_13 -> V_17 . V_21 ) {
V_128 = 1 ;
V_127 = F_53 ( V_10 , & V_13 -> V_17 , NULL ) ;
if ( 0 != V_127 )
goto V_136;
}
if ( V_128 ) {
V_13 -> V_104 = V_13 -> V_17 . V_115 * V_13 -> V_117 -> V_122 >> 3 ;
switch ( V_13 -> V_17 . V_126 ) {
case V_137 :
F_54 ( V_8 -> V_33 , & V_13 -> V_105 ,
V_106 -> V_138 , 0 , V_139 ,
V_13 -> V_104 , 0 , V_13 -> V_17 . V_116 ) ;
break;
case V_140 :
F_54 ( V_8 -> V_33 , & V_13 -> V_105 ,
V_106 -> V_138 , V_139 , 0 ,
V_13 -> V_104 , 0 , V_13 -> V_17 . V_116 ) ;
break;
case V_141 :
if ( V_8 -> V_28 & V_142 )
V_132 = 1 ;
else
V_132 = 0 ;
if ( V_40 [ V_8 -> V_41 ] . V_143 )
V_132 = 0 ;
if ( V_132 ) {
F_8 ( 1 , L_18 ,
V_6 ) ;
V_129 = V_13 -> V_104 ;
V_130 = 0 ;
} else {
F_8 ( 1 , L_19 ,
V_6 ) ;
V_129 = 0 ;
V_130 = V_13 -> V_104 ;
}
F_54 ( V_8 -> V_33 , & V_13 -> V_105 ,
V_106 -> V_138 , V_129 ,
V_130 ,
V_13 -> V_104 , V_13 -> V_104 ,
V_13 -> V_17 . V_116 >> 1 ) ;
break;
case V_144 :
F_54 ( V_8 -> V_33 , & V_13 -> V_105 ,
V_106 -> V_138 ,
0 , V_13 -> V_104 * ( V_13 -> V_17 . V_116 >> 1 ) ,
V_13 -> V_104 , 0 ,
V_13 -> V_17 . V_116 >> 1 ) ;
break;
case V_145 :
F_54 ( V_8 -> V_33 , & V_13 -> V_105 ,
V_106 -> V_138 ,
V_13 -> V_104 * ( V_13 -> V_17 . V_116 >> 1 ) , 0 ,
V_13 -> V_104 , 0 ,
V_13 -> V_17 . V_116 >> 1 ) ;
break;
default:
F_55 () ;
}
}
F_8 ( 2 , L_20 ,
V_13 , V_13 -> V_17 . V_3 ,
V_53 -> V_115 , V_53 -> V_116 , V_53 -> V_117 -> V_122 , V_53 -> V_117 -> V_39 ,
( unsigned long ) V_13 -> V_105 . V_106 ) ;
V_13 -> V_17 . V_21 = V_146 ;
return 0 ;
V_136:
F_56 ( V_10 , V_13 ) ;
return V_127 ;
}
static void F_57 ( struct V_119 * V_147 , struct V_124 * V_17 )
{
struct V_12 * V_13 = F_49 ( V_17 ,
struct V_12 , V_17 ) ;
struct V_12 * V_110 ;
struct V_52 * V_53 = V_147 -> V_121 ;
struct V_7 * V_8 = V_53 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_148 ;
V_13 -> V_105 . V_118 [ 0 ] = F_46 ( V_149 | V_150 | V_151 ) ;
V_13 -> V_105 . V_118 [ 1 ] = F_46 ( V_10 -> V_152 . V_106 ) ;
V_13 -> V_105 . V_118 [ 2 ] = F_46 ( 0 ) ;
if ( ! F_5 ( & V_10 -> V_113 ) ) {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_113 ) ;
V_13 -> V_17 . V_21 = V_153 ;
F_8 ( 2 , L_21 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else if ( F_5 ( & V_10 -> V_15 ) ) {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
F_37 ( V_8 , V_10 , V_13 ) ;
V_13 -> V_17 . V_21 = V_114 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
F_12 ( & V_10 -> V_24 , V_25 + V_26 ) ;
F_8 ( 2 , L_22 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
V_110 = F_6 ( V_10 -> V_15 . V_110 , struct V_12 ,
V_17 . V_18 ) ;
if ( V_110 -> V_17 . V_115 == V_13 -> V_17 . V_115 &&
V_110 -> V_17 . V_116 == V_13 -> V_17 . V_116 &&
V_110 -> V_117 == V_13 -> V_117 ) {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_15 ) ;
V_13 -> V_17 . V_21 = V_114 ;
V_13 -> V_11 = V_10 -> V_11 ++ ;
V_110 -> V_105 . V_118 [ 1 ] = F_46 ( V_13 -> V_105 . V_106 ) ;
V_110 -> V_105 . V_118 [ 2 ] = F_46 ( 0 ) ;
F_8 ( 2 , L_23 ,
V_13 , V_13 -> V_17 . V_3 ) ;
} else {
F_58 ( & V_13 -> V_17 . V_18 , & V_10 -> V_113 ) ;
V_13 -> V_17 . V_21 = V_153 ;
F_8 ( 2 , L_24 ,
V_13 , V_13 -> V_17 . V_3 ) ;
}
}
}
static void F_59 ( struct V_119 * V_10 ,
struct V_124 * V_17 )
{
struct V_12 * V_13 = F_49 ( V_17 ,
struct V_12 , V_17 ) ;
F_56 ( V_10 , V_13 ) ;
}
static struct V_119 * F_60 ( struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_154 :
return & V_53 -> V_148 ;
case V_155 :
return & V_53 -> V_156 ;
default:
F_55 () ;
return NULL ;
}
}
static int F_61 ( struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_154 :
return V_157 ;
case V_155 :
return V_158 ;
default:
F_55 () ;
return 0 ;
}
}
static int F_62 ( struct V_159 * V_159 )
{
struct V_31 * V_160 = F_63 ( V_159 ) ;
struct V_7 * V_8 = F_64 ( V_159 ) ;
struct V_52 * V_53 ;
enum V_161 type = 0 ;
int V_162 = 0 ;
switch ( V_160 -> V_163 ) {
case V_164 :
type = V_154 ;
break;
case V_165 :
type = V_155 ;
break;
case V_166 :
V_162 = 1 ;
break;
}
F_8 ( 1 , L_25 ,
F_65 ( V_160 ) , V_162 , V_167 [ type ] ) ;
V_53 = F_66 ( sizeof( * V_53 ) , V_168 ) ;
if ( NULL == V_53 )
return - V_169 ;
V_159 -> V_170 = V_53 ;
V_53 -> V_8 = V_8 ;
V_53 -> V_162 = V_162 ;
V_53 -> type = type ;
V_53 -> V_115 = 320 ;
V_53 -> V_116 = 240 ;
V_53 -> V_117 = F_1 ( V_171 ) ;
F_67 ( & V_53 -> V_148 , & V_172 ,
& V_8 -> V_33 -> V_8 , & V_8 -> V_173 ,
V_154 ,
V_141 ,
sizeof( struct V_12 ) ,
V_53 , NULL ) ;
F_67 ( & V_53 -> V_156 , & V_174 ,
& V_8 -> V_33 -> V_8 , & V_8 -> V_173 ,
V_155 ,
V_144 ,
sizeof( struct V_12 ) ,
V_53 , NULL ) ;
F_8 ( 1 , L_26 ) ;
return 0 ;
}
static T_4 F_68 ( struct V_159 * V_159 , char T_5 * V_59 ,
T_6 V_11 , T_7 * V_175 )
{
struct V_52 * V_53 = V_159 -> V_170 ;
switch ( V_53 -> type ) {
case V_154 :
if ( F_24 ( V_53 -> V_8 , V_157 ) )
return - V_176 ;
return F_69 ( & V_53 -> V_148 , V_59 , V_11 , V_175 ,
V_159 -> V_177 & V_178 ) ;
case V_155 :
if ( ! F_20 ( V_53 -> V_8 , V_53 , V_158 ) )
return - V_176 ;
return F_70 ( & V_53 -> V_156 , V_59 , V_11 , V_175 , 1 ,
V_159 -> V_177 & V_178 ) ;
default:
F_55 () ;
return 0 ;
}
}
static unsigned int F_71 ( struct V_159 * V_159 ,
struct V_179 * V_180 )
{
struct V_52 * V_53 = V_159 -> V_170 ;
struct V_12 * V_13 ;
unsigned int V_127 = V_181 ;
if ( V_155 == V_53 -> type ) {
if ( ! F_20 ( V_53 -> V_8 , V_53 , V_158 ) )
return V_181 ;
return F_72 ( V_159 , & V_53 -> V_156 , V_180 ) ;
}
F_21 ( & V_53 -> V_148 . V_182 ) ;
if ( F_23 ( V_53 , V_157 ) ) {
if ( F_5 ( & V_53 -> V_148 . V_183 ) )
goto V_23;
V_13 = F_6 ( V_53 -> V_148 . V_183 . V_16 ,
struct V_12 , V_17 . V_183 ) ;
} else {
V_13 = (struct V_12 * ) V_53 -> V_148 . V_184 ;
if ( NULL == V_13 )
goto V_23;
}
F_73 ( V_159 , & V_13 -> V_17 . V_23 , V_180 ) ;
if ( V_13 -> V_17 . V_21 == V_22 ||
V_13 -> V_17 . V_21 == V_185 )
V_127 = V_186 | V_187 ;
else
V_127 = 0 ;
V_23:
F_22 ( & V_53 -> V_148 . V_182 ) ;
return V_127 ;
}
static int F_74 ( struct V_159 * V_159 )
{
struct V_52 * V_53 = V_159 -> V_170 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_23 ( V_53 , V_188 ) ) {
F_25 ( V_8 , V_53 , V_188 ) ;
}
if ( F_23 ( V_53 , V_157 ) ) {
F_75 ( & V_53 -> V_148 ) ;
F_25 ( V_8 , V_53 , V_157 ) ;
}
if ( V_53 -> V_148 . V_184 ) {
F_59 ( & V_53 -> V_148 , V_53 -> V_148 . V_184 ) ;
F_76 ( V_53 -> V_148 . V_184 ) ;
}
if ( F_23 ( V_53 , V_158 ) ) {
if ( V_53 -> V_156 . V_189 )
F_77 ( & V_53 -> V_156 ) ;
if ( V_53 -> V_156 . V_190 )
F_78 ( & V_53 -> V_156 ) ;
F_25 ( V_8 , V_53 , V_158 ) ;
}
F_79 ( & V_53 -> V_148 ) ;
F_79 ( & V_53 -> V_156 ) ;
V_159 -> V_170 = NULL ;
F_76 ( V_53 ) ;
return 0 ;
}
static int F_80 ( struct V_159 * V_159 , struct V_191 * V_192 )
{
struct V_52 * V_53 = V_159 -> V_170 ;
return F_81 ( F_60 ( V_53 ) , V_192 ) ;
}
int F_82 ( struct V_7 * V_8 ,
struct V_193 * V_194 )
{
F_8 ( 1 , L_27 , V_6 ) ;
F_15 ( V_8 , V_29 , V_195 , V_194 ) ;
return 0 ;
}
int F_83 ( struct V_7 * V_8 ,
struct V_193 * V_194 )
{
F_8 ( 1 , L_28 , V_6 ) ;
F_15 ( V_8 , V_29 , V_196 , V_194 ) ;
return 0 ;
}
static void F_84 ( struct V_7 * V_8 )
{
struct V_193 V_197 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_48 ; V_3 ++ ) {
V_197 . V_44 = V_49 [ V_3 ] . V_50 . V_44 ;
V_197 . V_198 = V_49 [ V_3 ] . V_50 . V_199 ;
F_83 ( V_8 , & V_197 ) ;
}
}
static int F_85 ( struct V_159 * V_159 , void * V_200 ,
struct V_201 * V_202 )
{
struct V_52 * V_53 = V_200 ;
V_202 -> V_117 . V_203 . V_115 = V_53 -> V_115 ;
V_202 -> V_117 . V_203 . V_116 = V_53 -> V_116 ;
V_202 -> V_117 . V_203 . V_126 = V_53 -> V_148 . V_126 ;
V_202 -> V_117 . V_203 . V_204 = V_53 -> V_117 -> V_2 ;
V_202 -> V_117 . V_203 . V_205 =
( V_202 -> V_117 . V_203 . V_115 * V_53 -> V_117 -> V_122 ) >> 3 ;
V_202 -> V_117 . V_203 . V_206 =
V_202 -> V_117 . V_203 . V_116 * V_202 -> V_117 . V_203 . V_205 ;
return 0 ;
}
static int F_86 ( struct V_159 * V_159 , void * V_200 ,
struct V_201 * V_202 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
struct V_1 * V_117 ;
enum V_125 V_126 ;
unsigned int V_207 , V_208 ;
V_117 = F_1 ( V_202 -> V_117 . V_203 . V_204 ) ;
if ( NULL == V_117 )
return - V_47 ;
V_126 = V_202 -> V_117 . V_203 . V_126 ;
V_207 = F_51 ( V_8 -> V_28 ) ;
V_208 = F_52 ( V_8 -> V_28 ) ;
if ( V_209 == V_126 ) {
V_126 = ( V_202 -> V_117 . V_203 . V_116 > V_208 / 2 )
? V_141
: V_140 ;
}
switch ( V_126 ) {
case V_137 :
case V_140 :
V_208 = V_208 / 2 ;
break;
case V_141 :
break;
default:
return - V_47 ;
}
V_202 -> V_117 . V_203 . V_126 = V_126 ;
F_87 ( & V_202 -> V_117 . V_203 . V_115 , 48 , V_207 , 2 ,
& V_202 -> V_117 . V_203 . V_116 , 32 , V_208 , 0 , 0 ) ;
V_202 -> V_117 . V_203 . V_205 =
( V_202 -> V_117 . V_203 . V_115 * V_117 -> V_122 ) >> 3 ;
V_202 -> V_117 . V_203 . V_206 =
V_202 -> V_117 . V_203 . V_116 * V_202 -> V_117 . V_203 . V_205 ;
return 0 ;
}
static int F_88 ( struct V_159 * V_159 , void * V_200 ,
struct V_201 * V_202 )
{
struct V_52 * V_53 = V_200 ;
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
struct V_210 V_211 ;
int V_212 ;
F_8 ( 2 , L_5 , V_6 ) ;
V_212 = F_86 ( V_159 , V_200 , V_202 ) ;
if ( 0 != V_212 )
return V_212 ;
V_53 -> V_117 = F_1 ( V_202 -> V_117 . V_203 . V_204 ) ;
V_53 -> V_115 = V_202 -> V_117 . V_203 . V_115 ;
V_53 -> V_116 = V_202 -> V_117 . V_203 . V_116 ;
V_53 -> V_148 . V_126 = V_202 -> V_117 . V_203 . V_126 ;
F_8 ( 2 , L_29 , V_6 ,
V_53 -> V_115 , V_53 -> V_116 , V_53 -> V_148 . V_126 ) ;
F_89 ( & V_211 , & V_202 -> V_117 . V_203 , V_213 ) ;
F_15 ( V_8 , V_88 , V_214 , & V_211 ) ;
F_90 ( & V_202 -> V_117 . V_203 , & V_211 ) ;
return 0 ;
}
static int F_91 ( struct V_159 * V_159 , void * V_200 ,
struct V_215 * V_216 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
strcpy ( V_216 -> V_217 , L_30 ) ;
F_92 ( V_216 -> V_218 , V_40 [ V_8 -> V_41 ] . V_39 ,
sizeof( V_216 -> V_218 ) ) ;
sprintf ( V_216 -> V_219 , L_31 , F_93 ( V_8 -> V_33 ) ) ;
V_216 -> V_220 =
V_221 |
V_222 |
V_223 |
V_224 ;
if ( V_139 != V_8 -> V_225 )
V_216 -> V_220 |= V_226 ;
return 0 ;
}
static int F_94 ( struct V_159 * V_159 , void * V_200 ,
struct V_227 * V_202 )
{
if ( F_95 ( V_202 -> V_228 >= F_2 ( V_4 ) ) )
return - V_47 ;
F_92 ( V_202 -> V_229 , V_4 [ V_202 -> V_228 ] . V_39 ,
sizeof( V_202 -> V_229 ) ) ;
V_202 -> V_204 = V_4 [ V_202 -> V_228 ] . V_2 ;
return 0 ;
}
static int F_96 ( struct V_159 * V_159 , void * V_200 ,
struct V_230 * V_231 )
{
struct V_52 * V_53 = V_200 ;
return F_97 ( F_60 ( V_53 ) , V_231 ) ;
}
static int F_98 ( struct V_159 * V_159 , void * V_200 ,
struct V_232 * V_231 )
{
struct V_52 * V_53 = V_200 ;
return F_99 ( F_60 ( V_53 ) , V_231 ) ;
}
static int F_100 ( struct V_159 * V_159 , void * V_200 ,
struct V_232 * V_231 )
{
struct V_52 * V_53 = V_200 ;
return F_101 ( F_60 ( V_53 ) , V_231 ) ;
}
static int F_102 ( struct V_159 * V_159 , void * V_200 ,
struct V_232 * V_231 )
{
struct V_52 * V_53 = V_200 ;
return F_103 ( F_60 ( V_53 ) , V_231 ,
V_159 -> V_177 & V_178 ) ;
}
static int F_104 ( struct V_159 * V_159 , void * V_200 ,
enum V_161 V_3 )
{
struct V_52 * V_53 = V_200 ;
struct V_7 * V_8 = V_53 -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ( V_53 -> type != V_154 ) &&
( V_53 -> type != V_155 ) )
return - V_47 ;
if ( F_95 ( V_3 != V_53 -> type ) )
return - V_47 ;
if ( F_95 ( ! F_20 ( V_8 , V_53 , F_61 ( V_53 ) ) ) )
return - V_176 ;
if ( ( V_53 -> type == V_155 ) &&
( ( F_105 ( V_101 ) & 0x11 ) == 0 ) )
return - V_47 ;
return F_106 ( F_60 ( V_53 ) ) ;
}
static int F_107 ( struct V_159 * V_159 , void * V_200 , enum V_161 V_3 )
{
struct V_52 * V_53 = V_200 ;
struct V_7 * V_8 = V_53 -> V_8 ;
int V_212 , V_233 ;
F_8 ( 1 , L_5 , V_6 ) ;
if ( ( V_53 -> type != V_154 ) &&
( V_53 -> type != V_155 ) )
return - V_47 ;
if ( V_3 != V_53 -> type )
return - V_47 ;
V_233 = F_61 ( V_53 ) ;
V_212 = F_77 ( F_60 ( V_53 ) ) ;
if ( V_212 < 0 )
return V_212 ;
F_25 ( V_8 , V_53 , V_233 ) ;
return 0 ;
}
static int F_108 ( struct V_159 * V_159 , void * V_200 , T_2 * V_44 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
* V_44 = V_8 -> V_28 ;
return 0 ;
}
static int F_109 ( struct V_159 * V_159 , void * V_200 , T_2 V_234 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_21 ( & V_8 -> V_56 ) ;
F_13 ( V_8 , V_234 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
int F_110 ( struct V_7 * V_8 , struct V_235 * V_3 )
{
static const char * V_236 [] = {
[ V_237 ] = L_32 ,
[ V_238 ] = L_33 ,
[ V_239 ] = L_34 ,
[ V_240 ] = L_35 ,
[ V_241 ] = L_36 ,
[ V_242 ] = L_37 ,
[ V_85 ] = L_38 ,
[ V_243 ] = L_39 ,
[ V_244 ] = L_40 ,
[ V_245 ] = L_41 ,
} ;
unsigned int V_246 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_246 = V_3 -> V_228 ;
if ( V_246 >= V_247 )
return - V_47 ;
if ( 0 == F_33 ( V_246 ) -> type )
return - V_47 ;
V_3 -> V_228 = V_246 ;
V_3 -> type = V_248 ;
strcpy ( V_3 -> V_39 , V_236 [ F_33 ( V_246 ) -> type ] ) ;
if ( ( V_85 == F_33 ( V_246 ) -> type ) ||
( V_243 == F_33 ( V_246 ) -> type ) ) {
V_3 -> type = V_249 ;
V_3 -> V_250 = V_251 ;
}
if ( F_33 ( V_246 ) -> type != V_85 )
V_3 -> V_252 = 0x3 ;
if ( V_8 -> V_71 == V_246 ) {
F_15 ( V_8 , V_88 , V_253 , & V_3 -> V_254 ) ;
}
return 0 ;
}
static int F_111 ( struct V_159 * V_159 , void * V_200 ,
struct V_235 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
F_8 ( 1 , L_5 , V_6 ) ;
return F_110 ( V_8 , V_3 ) ;
}
int F_112 ( struct V_159 * V_159 , void * V_200 , unsigned int * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
* V_3 = V_8 -> V_71 ;
F_8 ( 1 , L_42 , V_6 , * V_3 ) ;
return 0 ;
}
static int F_113 ( struct V_159 * V_159 , void * V_200 , unsigned int * V_3 )
{
return F_112 ( V_159 , V_200 , V_3 ) ;
}
int F_114 ( struct V_159 * V_159 , void * V_200 , unsigned int V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
F_8 ( 1 , L_43 , V_6 , V_3 ) ;
if ( V_3 >= V_247 ) {
F_8 ( 1 , L_44 , V_6 ) ;
return - V_47 ;
}
if ( F_33 ( V_3 ) -> type == 0 )
return - V_47 ;
F_21 ( & V_8 -> V_56 ) ;
F_32 ( V_8 , V_3 ) ;
F_36 ( V_8 , V_3 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_115 ( struct V_159 * V_159 , void * V_200 , unsigned int V_3 )
{
return F_114 ( V_159 , V_200 , V_3 ) ;
}
static int F_116 ( struct V_159 * V_159 , void * V_200 )
{
struct V_52 * V_53 = V_200 ;
struct V_7 * V_8 = V_53 -> V_8 ;
F_3 ( V_255
L_45 ,
V_8 -> V_39 ) ;
F_15 ( V_8 , V_29 , V_256 ) ;
F_3 ( V_255
L_46 ,
V_8 -> V_39 ) ;
return 0 ;
}
static int F_117 ( struct V_159 * V_159 , void * V_200 ,
struct V_257 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
static const char * V_236 [] = {
[ 0 ] = L_47 ,
[ 1 ] = L_48 ,
} ;
unsigned int V_246 ;
F_8 ( 1 , L_5 , V_6 ) ;
V_246 = V_3 -> V_228 ;
if ( V_246 >= 2 )
return - V_47 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_228 = V_246 ;
strcpy ( V_3 -> V_39 , V_236 [ V_246 ] ) ;
V_3 -> V_258 = V_259 ;
V_3 -> V_260 = V_261 ;
return 0 ;
}
static int F_118 ( struct V_159 * V_159 , void * V_200 ,
struct V_257 * V_3 )
{
return F_117 ( V_159 , V_200 , V_3 ) ;
}
static int F_119 ( struct V_159 * V_159 , void * V_200 ,
struct V_257 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
V_3 -> V_228 = V_8 -> V_262 ;
F_8 ( 1 , L_14 , V_6 , V_3 -> V_228 ) ;
return F_117 ( V_159 , V_200 , V_3 ) ;
}
static int F_120 ( struct V_159 * V_159 , void * V_200 ,
const struct V_257 * V_3 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
if ( V_3 -> V_228 >= 2 )
return - V_47 ;
F_8 ( 1 , L_43 , V_6 , V_3 -> V_228 ) ;
V_8 -> V_262 = V_3 -> V_228 ;
F_31 ( V_8 , V_8 -> V_262 + 1 ) ;
return 0 ;
}
static int F_121 ( struct V_159 * V_159 , void * V_200 ,
struct V_42 * V_43 )
{
V_43 -> V_44 = F_122 ( V_263 , V_43 -> V_44 ) ;
if ( F_95 ( V_43 -> V_44 == 0 ) )
return - V_47 ;
return F_19 ( V_43 ) ;
}
static int F_123 ( struct V_159 * V_159 , void * V_200 ,
struct V_193 * V_194 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
return F_82 ( V_8 , V_194 ) ;
}
static int F_124 ( struct V_159 * V_159 , void * V_200 ,
struct V_193 * V_194 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
return F_83 ( V_8 , V_194 ) ;
}
static int F_125 ( struct V_159 * V_159 , void * V_200 ,
struct V_264 * V_265 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
if ( F_95 ( V_139 == V_8 -> V_225 ) )
return - V_47 ;
if ( 0 != V_265 -> V_228 )
return - V_47 ;
strcpy ( V_265 -> V_39 , L_38 ) ;
F_15 ( V_8 , V_266 , V_267 , V_265 ) ;
return 0 ;
}
static int F_126 ( struct V_159 * V_159 , void * V_200 ,
const struct V_264 * V_265 )
{
struct V_7 * V_8 = ( (struct V_52 * ) V_200 ) -> V_8 ;
if ( V_139 == V_8 -> V_225 )
return - V_47 ;
if ( 0 != V_265 -> V_228 )
return - V_47 ;
F_15 ( V_8 , V_266 , V_268 , V_265 ) ;
return 0 ;
}
static int F_127 ( struct V_159 * V_159 , void * V_200 ,
struct V_269 * V_202 )
{
struct V_52 * V_53 = V_200 ;
struct V_7 * V_8 = V_53 -> V_8 ;
if ( F_95 ( V_139 == V_8 -> V_225 ) )
return - V_47 ;
V_202 -> type = V_53 -> V_162 ? V_270 : V_271 ;
V_202 -> V_272 = V_8 -> V_273 ;
F_15 ( V_8 , V_266 , V_274 , V_202 ) ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 , const struct V_269 * V_202 )
{
struct V_193 V_197 ;
if ( F_95 ( V_139 == V_8 -> V_225 ) )
return - V_47 ;
if ( F_95 ( V_202 -> V_266 != 0 ) )
return - V_47 ;
F_21 ( & V_8 -> V_56 ) ;
V_8 -> V_273 = V_202 -> V_272 ;
V_197 . V_44 = V_275 ;
V_197 . V_198 = 1 ;
F_83 ( V_8 , & V_197 ) ;
F_15 ( V_8 , V_266 , V_276 , V_202 ) ;
F_129 ( 100 ) ;
V_197 . V_198 = 0 ;
F_83 ( V_8 , & V_197 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
static int F_130 ( struct V_7 * V_8 ,
const struct V_269 * V_202 )
{
struct V_193 V_197 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
struct V_281 V_282 = {
. V_260 = V_271 ,
. V_283 = V_284 ,
. V_250 = V_8 -> V_28 ,
. V_272 = V_202 -> V_272
} ;
F_21 ( & V_8 -> V_56 ) ;
V_8 -> V_273 = V_202 -> V_272 ;
V_197 . V_44 = V_275 ;
V_197 . V_198 = 1 ;
F_83 ( V_8 , & V_197 ) ;
F_8 ( 1 , L_49 , V_6 ,
V_282 . V_272 , V_202 -> V_266 , V_282 . V_250 ) ;
V_278 = F_131 ( & V_8 -> V_285 . V_286 , 1 ) ;
if ( ! V_278 ) {
F_22 ( & V_8 -> V_56 ) ;
return - V_47 ;
}
V_280 = V_278 -> V_287 . V_288 ;
if ( ( V_8 -> V_41 == V_95 ) ||
( V_8 -> V_41 == V_93 ) ||
( V_8 -> V_41 == V_94 ) )
V_280 = & V_8 -> V_289 . V_290 ;
if ( V_280 && V_280 -> V_291 . V_292 . V_293 ) {
F_15 ( V_8 , V_29 , V_30 , V_8 -> V_28 ) ;
V_280 -> V_291 . V_292 . V_293 ( V_280 , & V_282 ) ;
}
else
F_3 ( V_5 L_50 , V_6 ) ;
F_129 ( 100 ) ;
V_197 . V_198 = 0 ;
F_83 ( V_8 , & V_197 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
}
int F_132 ( struct V_159 * V_159 , void * V_200 ,
const struct V_269 * V_202 )
{
struct V_52 * V_53 = V_200 ;
struct V_7 * V_8 = V_53 -> V_8 ;
int V_67 ;
switch ( V_8 -> V_41 ) {
case V_93 :
case V_94 :
case V_95 :
V_67 = F_130 ( V_8 , V_202 ) ;
break;
default:
V_67 = F_128 ( V_8 , V_202 ) ;
}
return V_67 ;
}
static int F_133 ( struct V_159 * V_159 , void * V_200 ,
const struct V_269 * V_202 )
{
return F_132 ( V_159 , V_200 , V_202 ) ;
}
static void F_134 ( unsigned long V_59 )
{
struct V_7 * V_8 = (struct V_7 * ) V_59 ;
struct V_9 * V_10 = & V_8 -> V_148 ;
struct V_12 * V_13 ;
unsigned long V_63 ;
F_135 ( & V_8 -> V_173 , V_63 ) ;
while ( ! F_5 ( & V_10 -> V_15 ) ) {
V_13 = F_6 ( V_10 -> V_15 . V_16 ,
struct V_12 , V_17 . V_18 ) ;
F_9 ( & V_13 -> V_17 . V_18 ) ;
V_13 -> V_17 . V_21 = V_185 ;
F_10 ( & V_13 -> V_17 . V_23 ) ;
F_3 ( V_5 L_51 ,
V_8 -> V_39 , V_13 , V_13 -> V_17 . V_3 ,
( unsigned long ) V_13 -> V_105 . V_106 ) ;
}
F_43 ( V_8 , V_10 ) ;
F_136 ( & V_8 -> V_173 , V_63 ) ;
}
int F_137 ( struct V_7 * V_8 , T_1 V_254 )
{
T_1 V_294 , V_11 ;
int V_295 = 0 ;
V_294 = F_105 ( V_108 ) ;
if ( 0 == ( V_254 & V_294 ) )
return V_295 ;
F_40 ( V_296 , V_254 ) ;
if ( ( V_254 & V_297 ) ||
( V_254 & V_298 ) ||
( V_254 & V_299 ) ) {
if ( V_254 & V_297 ) {
F_8 ( 7 , L_52 ,
V_297 ) ;
F_3 ( V_300 L_53 ,
V_8 -> V_39 ) ;
F_138 ( V_8 ,
& V_8 -> V_102 [ V_103 ] ) ;
}
if ( V_254 & V_298 )
F_8 ( 7 , L_54
L_55 ,
V_298 ) ;
if ( V_254 & V_299 )
F_8 ( 7 , L_56 ,
V_299 ) ;
}
if ( V_254 & V_301 ) {
F_139 ( & V_8 -> V_173 ) ;
V_11 = F_105 ( V_302 ) ;
F_4 ( V_8 , & V_8 -> V_148 , V_11 ) ;
F_140 ( & V_8 -> V_173 ) ;
V_295 ++ ;
}
if ( V_254 & V_303 ) {
F_8 ( 2 , L_57 ) ;
F_139 ( & V_8 -> V_173 ) ;
F_43 ( V_8 , & V_8 -> V_148 ) ;
F_140 ( & V_8 -> V_173 ) ;
V_295 ++ ;
}
V_295 += F_141 ( V_8 , V_254 ) ;
return V_295 ;
}
void F_142 ( struct V_7 * V_8 )
{
F_8 ( 1 , L_5 , V_6 ) ;
F_143 ( V_8 , 0x01 ) ;
if ( V_8 -> V_304 ) {
if ( F_144 ( V_8 -> V_304 ) )
F_145 ( V_8 -> V_304 ) ;
else
V_38 ( V_8 -> V_304 ) ;
V_8 -> V_304 = NULL ;
F_146 ( V_8 -> V_33 , & V_8 -> V_156 . V_152 ) ;
}
if ( V_8 -> V_305 ) {
if ( F_144 ( V_8 -> V_305 ) )
F_145 ( V_8 -> V_305 ) ;
else
V_38 ( V_8 -> V_305 ) ;
V_8 -> V_305 = NULL ;
F_146 ( V_8 -> V_33 , & V_8 -> V_148 . V_152 ) ;
}
if ( V_8 -> V_306 )
F_147 ( V_8 ) ;
}
int F_148 ( struct V_7 * V_8 )
{
int V_212 ;
F_8 ( 1 , L_5 , V_6 ) ;
F_149 ( & V_8 -> V_173 ) ;
V_307 = V_308 ;
strcpy ( V_307 . V_39 , L_58 ) ;
V_8 -> V_28 = V_309 ;
F_150 ( & V_8 -> V_148 . V_15 ) ;
F_150 ( & V_8 -> V_148 . V_113 ) ;
V_8 -> V_148 . V_24 . V_310 = F_134 ;
V_8 -> V_148 . V_24 . V_59 = ( unsigned long ) V_8 ;
F_151 ( & V_8 -> V_148 . V_24 ) ;
F_152 ( V_8 -> V_33 , & V_8 -> V_148 . V_152 ,
V_101 , 0x11 , 0x00 ) ;
F_150 ( & V_8 -> V_156 . V_15 ) ;
F_150 ( & V_8 -> V_156 . V_113 ) ;
V_8 -> V_156 . V_24 . V_310 = V_311 ;
V_8 -> V_156 . V_24 . V_59 = ( unsigned long ) V_8 ;
F_151 ( & V_8 -> V_156 . V_24 ) ;
F_152 ( V_8 -> V_33 , & V_8 -> V_156 . V_152 ,
V_101 , 0x22 , 0x00 ) ;
F_41 ( V_8 , 0x01 ) ;
if ( ( V_312 != V_8 -> V_225 ) &&
( ( V_8 -> V_313 == 0 ) || ( V_8 -> V_313 == 1 ) ) ) {
struct V_314 * V_315 = NULL ;
if ( V_8 -> V_316 )
V_315 = F_153 ( & V_8 -> V_36 ,
& V_8 -> V_65 [ V_8 -> V_313 ] . V_66 ,
L_59 , V_8 -> V_316 , NULL ) ;
else
V_315 = F_153 ( & V_8 -> V_36 ,
& V_8 -> V_65 [ V_8 -> V_313 ] . V_66 ,
L_59 , 0 , F_154 ( V_317 ) ) ;
if ( V_315 ) {
struct V_318 V_319 ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
V_319 . V_320 = V_321 ;
V_319 . type = V_8 -> V_225 ;
V_319 . V_62 = F_155 ( V_315 ) ;
V_319 . V_322 = V_323 ;
F_35 ( V_315 , V_266 , V_324 , & V_319 ) ;
if ( V_8 -> V_41 == V_325 ) {
struct V_326 V_197 = {
. V_327 = V_328 ,
. V_329 = 64
} ;
struct V_330 V_331 = {
. V_266 = V_8 -> V_225 ,
. V_200 = & V_197
} ;
F_35 ( V_315 , V_266 , V_332 , & V_331 ) ;
}
if ( V_8 -> V_41 == V_96 ) {
struct V_326 V_197 = {
. V_327 = L_60 ,
. V_329 = 64
} ;
struct V_330 V_331 = {
. V_266 = V_8 -> V_225 ,
. V_200 = & V_197
} ;
F_35 ( V_315 , V_266 , V_332 , & V_331 ) ;
}
}
}
V_8 -> V_305 = F_16 ( V_8 , V_8 -> V_33 ,
& V_308 , L_61 ) ;
V_212 = F_156 ( V_8 -> V_305 , V_164 ,
V_333 [ V_8 -> V_334 ] ) ;
if ( V_212 < 0 ) {
F_3 ( V_255 L_62 ,
V_8 -> V_39 ) ;
goto V_335;
}
F_3 ( V_255 L_63 ,
V_8 -> V_39 , F_65 ( V_8 -> V_305 ) ) ;
V_8 -> V_304 = F_16 ( V_8 , V_8 -> V_33 ,
& V_307 , L_64 ) ;
V_212 = F_156 ( V_8 -> V_304 , V_165 ,
V_336 [ V_8 -> V_334 ] ) ;
if ( V_212 < 0 ) {
F_3 ( V_255 L_65 ,
V_8 -> V_39 ) ;
goto V_335;
}
F_3 ( V_255 L_66 ,
V_8 -> V_39 , F_65 ( V_8 -> V_304 ) ) ;
V_8 -> V_306 = F_157 ( V_8 ) ;
F_21 ( & V_8 -> V_56 ) ;
F_13 ( V_8 , V_8 -> V_28 ) ;
F_84 ( V_8 ) ;
F_32 ( V_8 , 0 ) ;
F_36 ( V_8 , 0 ) ;
F_22 ( & V_8 -> V_56 ) ;
return 0 ;
V_335:
F_142 ( V_8 ) ;
return V_212 ;
}
