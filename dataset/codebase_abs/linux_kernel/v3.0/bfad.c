static void
F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_5 :
F_3 ( V_2 , V_6 ) ;
V_2 -> V_7 = F_4 ( V_8 , ( void * ) V_2 ,
L_1 , L_2 ) ;
if ( F_5 ( V_2 -> V_7 ) ) {
F_6 ( V_9 L_3
L_4 , V_2 -> V_10 ) ;
F_7 ( V_2 , V_11 ) ;
}
F_7 ( V_2 , V_12 ) ;
break;
case V_13 :
break;
default:
F_8 ( V_2 , V_4 ) ;
}
}
static void
V_6 ( struct V_1 * V_2 , enum V_3 V_4 )
{
unsigned long V_14 ;
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_12 :
F_3 ( V_2 , V_15 ) ;
F_9 ( & V_2 -> V_16 ) ;
if ( F_10 ( V_2 ) ) {
F_6 ( V_17 L_5 ,
V_2 -> V_10 ) ;
F_7 ( V_2 , V_18 ) ;
break;
}
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_12 ( & V_2 -> V_20 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
if ( ( V_2 -> V_21 & V_22 ) &&
F_14 ( V_2 ) ) {
F_6 ( V_17 L_6 ,
V_23 , V_2 -> V_10 ) ;
}
F_15 ( V_2 ) ;
F_16 ( & V_2 -> V_16 ) ;
if ( ( V_2 -> V_21 & V_24 ) ) {
F_7 ( V_2 , V_25 ) ;
} else {
F_6 ( V_17
L_7 ,
V_2 -> V_26 ) ;
V_2 -> V_21 |= V_27 ;
F_7 ( V_2 , V_28 ) ;
}
break;
case V_11 :
F_3 ( V_2 , F_1 ) ;
break;
default:
F_8 ( V_2 , V_4 ) ;
}
}
static void
V_15 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_29 ;
unsigned long V_14 ;
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_25 :
F_17 ( V_2 -> V_7 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_2 -> V_7 = NULL ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
V_29 = F_18 ( V_2 ) ;
if ( V_29 != V_30 )
break;
F_3 ( V_2 , V_31 ) ;
break;
case V_18 :
F_3 ( V_2 , F_1 ) ;
F_17 ( V_2 -> V_7 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_2 -> V_7 = NULL ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
break;
case V_28 :
F_3 ( V_2 , V_32 ) ;
break;
default:
F_8 ( V_2 , V_4 ) ;
}
}
static void
V_32 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_29 ;
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_25 :
V_29 = F_18 ( V_2 ) ;
if ( V_29 != V_30 )
break;
F_3 ( V_2 , V_31 ) ;
break;
case V_13 :
if ( V_2 -> V_21 & V_33 )
F_19 ( V_2 ) ;
if ( V_2 -> V_21 & V_34 ) {
F_20 ( V_2 ) ;
V_2 -> V_21 &= ~ V_34 ;
}
F_21 ( V_2 ) ;
break;
case V_35 :
F_3 ( V_2 , F_1 ) ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_36 ) ;
break;
default:
F_8 ( V_2 , V_4 ) ;
}
}
static void
V_31 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_13 :
F_3 ( V_2 , V_37 ) ;
F_24 ( V_2 ) ;
break;
default:
F_8 ( V_2 , V_4 ) ;
}
}
static void
V_37 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_38 :
F_3 ( V_2 , V_39 ) ;
F_21 ( V_2 ) ;
break;
default:
F_8 ( V_2 , V_4 ) ;
}
}
static void
V_39 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , V_4 ) ;
switch ( V_4 ) {
case V_35 :
F_3 ( V_2 , F_1 ) ;
F_22 ( V_2 ) ;
F_23 ( & V_2 -> V_36 ) ;
F_20 ( V_2 ) ;
V_2 -> V_21 &= ~ V_34 ;
F_19 ( V_2 ) ;
break;
default:
F_8 ( V_2 , V_4 ) ;
break;
}
}
void
F_25 ( void * V_40 , T_1 V_41 )
{
struct V_42 * V_43 = (struct V_42 * ) V_40 ;
V_43 -> V_41 = V_41 ;
F_26 ( & V_43 -> V_16 ) ;
}
void
F_27 ( void * V_44 , T_1 V_45 )
{
struct V_1 * V_2 = V_44 ;
if ( V_45 == V_30 ) {
V_2 -> V_21 |= V_24 ;
if ( ( V_2 -> V_21 & V_27 ) ) {
V_2 -> V_21 &= ~ V_27 ;
F_28 ( V_2 -> V_7 ) ;
}
}
F_26 ( & V_2 -> V_16 ) ;
}
struct V_46 *
F_29 ( struct V_1 * V_2 , struct V_47 * V_48 ,
enum V_49 V_50 , struct V_51 * V_52 ,
struct V_53 * V_54 )
{
T_1 V_55 ;
struct V_46 * V_56 ;
if ( ! V_54 && ! V_52 ) {
V_56 = & V_2 -> V_57 ;
V_56 -> V_58 = V_59 ;
} else if ( ! V_54 && V_52 ) {
V_56 = & V_52 -> V_60 ;
V_56 -> V_58 = V_61 ;
} else if ( V_54 && ! V_52 ) {
V_56 = & V_54 -> V_62 ;
V_56 -> V_58 = V_63 ;
} else {
V_56 = & V_54 -> V_62 ;
V_56 -> V_58 = V_64 ;
}
V_56 -> V_65 = V_48 ;
V_56 -> V_50 = V_50 ;
if ( V_50 & V_66 ) {
V_55 = F_30 ( V_2 , V_56 ) ;
if ( V_55 != V_30 ) {
F_31 ( V_2 , V_56 ) ;
V_56 = NULL ;
}
}
return V_56 ;
}
void
F_32 ( struct V_1 * V_2 , enum V_49 V_50 ,
struct V_51 * V_52 , struct V_53 * V_54 )
{
struct V_46 * V_56 ;
if ( V_54 && ! V_54 -> V_67 ) {
V_56 = ( V_54 ) ? ( & ( V_54 ) -> V_62 ) :
( ( V_52 ) ? ( & ( V_52 ) -> V_60 ) :
( & ( V_2 ) -> V_57 ) ) ;
F_2 ( V_2 , V_50 ) ;
if ( V_50 & V_66 )
F_31 ( V_2 , V_56 ) ;
}
}
T_1
F_33 ( struct V_1 * V_2 , struct V_68 * * V_69 ,
struct V_70 * * V_71 )
{
T_1 V_55 = V_30 ;
* V_71 = F_34 ( sizeof( struct V_70 ) , V_72 ) ;
if ( * V_71 == NULL ) {
V_55 = V_73 ;
goto V_74;
}
* V_69 = & ( * V_71 ) -> V_75 ;
V_74:
return V_55 ;
}
void
F_35 ( struct V_1 * V_2 , struct V_76 V_77 )
{
struct V_78 V_79 = { 0 } ;
struct V_53 * V_80 ;
int V_55 ;
V_80 = F_34 ( sizeof( struct V_53 ) , V_81 ) ;
if ( ! V_80 ) {
F_2 ( V_2 , 0 ) ;
return;
}
V_80 -> V_62 . V_2 = V_2 ;
V_79 . V_50 = V_66 ;
V_79 . V_82 = V_77 . V_83 ;
V_79 . V_84 = V_77 . V_85 ;
V_79 . V_86 = V_87 ;
V_55 = F_36 ( & V_80 -> V_88 , & V_2 -> V_89 , 0 ,
& V_79 , V_80 ) ;
if ( V_55 != V_30 ) {
F_2 ( V_2 , 0 ) ;
return;
}
F_37 ( & V_80 -> V_90 , & V_2 -> V_91 ) ;
}
void
F_38 ( struct V_1 * V_2 )
{
int V_92 ;
struct V_93 * V_94 = & V_2 -> V_95 ;
struct V_96 * V_97 ;
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
V_97 = & V_94 -> V_95 [ V_92 ] ;
if ( V_97 -> V_99 != NULL ) {
switch ( V_97 -> V_100 ) {
case V_101 :
F_39 ( V_97 -> V_99 ) ;
break;
case V_102 :
F_40 ( & V_2 -> V_103 -> V_104 ,
V_97 -> V_105 ,
V_97 -> V_99 ,
( V_106 ) V_97 -> V_107 ) ;
break;
default:
F_41 ( 1 ) ;
break;
}
}
}
memset ( V_94 , 0 , sizeof( struct V_93 ) ) ;
}
void
F_42 ( struct V_108 * V_109 )
{
if ( V_110 > 0 )
V_109 -> V_111 . V_110 = V_110 ;
if ( V_112 > 0 )
V_109 -> V_111 . V_113 = V_112 ;
if ( V_114 > 0 )
V_109 -> V_111 . V_115 = V_114 ;
if ( V_116 > 0 )
V_109 -> V_111 . V_117 = V_116 ;
if ( V_118 > 0 )
V_109 -> V_111 . V_119 = V_118 ;
if ( V_120 > 0 )
V_109 -> V_121 . V_122 = V_120 ;
if ( V_123 > 0 )
V_109 -> V_121 . V_124 = V_123 ;
if ( V_125 > 0 )
V_109 -> V_121 . V_125 = V_125 ;
V_110 = V_109 -> V_111 . V_110 ;
V_112 = V_109 -> V_111 . V_113 ;
V_114 = V_109 -> V_111 . V_115 ;
V_116 = V_109 -> V_111 . V_117 ;
V_118 = V_109 -> V_111 . V_119 ;
V_120 = V_109 -> V_121 . V_122 ;
V_123 = V_109 -> V_121 . V_124 ;
V_125 = V_109 -> V_121 . V_125 ;
}
T_1
F_43 ( struct V_1 * V_2 )
{
int V_92 ;
struct V_93 * V_94 = & V_2 -> V_95 ;
struct V_96 * V_97 ;
V_106 V_126 ;
void * V_99 ;
T_1 V_55 = V_30 ;
int V_127 = 0 ;
int V_128 = 1 ;
int V_129 = 512 ;
F_44 ( & V_2 -> V_130 ) ;
V_131:
F_42 ( & V_2 -> V_130 ) ;
V_2 -> V_132 . V_133 = V_2 -> V_130 . V_111 . V_113 ;
F_45 ( & V_2 -> V_130 , V_94 ) ;
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
V_97 = & V_94 -> V_95 [ V_92 ] ;
switch ( V_97 -> V_100 ) {
case V_101 :
V_99 = F_46 ( V_97 -> V_105 ) ;
if ( V_99 == NULL ) {
F_38 ( V_2 ) ;
V_55 = V_73 ;
goto V_74;
}
memset ( V_99 , 0 , V_97 -> V_105 ) ;
V_97 -> V_99 = V_99 ;
break;
case V_102 :
V_99 = F_47 ( & V_2 -> V_103 -> V_104 ,
V_97 -> V_105 , & V_126 , V_81 ) ;
if ( V_99 == NULL ) {
F_38 ( V_2 ) ;
if ( V_125 > V_129 ) {
F_6 ( V_9
L_8
L_9 ,
V_2 -> V_10 , V_125 ) ;
F_48 ( & V_125 ) ;
F_6 ( V_9
L_10
L_9 ,
V_2 -> V_10 , V_125 ) ;
V_127 ++ ;
goto V_131;
} else {
if ( V_134 > 0 )
V_125 = V_134 ;
else {
V_128 =
( 1 << V_127 ) ;
V_125 *= V_128 ;
}
V_55 = V_73 ;
goto V_74;
}
}
if ( V_134 > 0 )
V_125 = V_134 ;
else {
V_128 = ( 1 << V_127 ) ;
V_125 *= V_128 ;
}
memset ( V_99 , 0 , V_97 -> V_105 ) ;
V_97 -> V_99 = V_99 ;
V_97 -> V_107 = V_126 ;
break;
default:
break;
}
}
V_74:
return V_55 ;
}
T_1
F_49 ( struct V_1 * V_2 , T_2 V_135 ,
struct V_78 * V_79 , struct V_136 * V_104 )
{
struct V_53 * V_80 ;
int V_55 = V_30 ;
unsigned long V_14 ;
struct V_137 V_43 ;
V_80 = F_34 ( sizeof( struct V_53 ) , V_81 ) ;
if ( ! V_80 ) {
V_55 = V_73 ;
goto V_74;
}
V_80 -> V_62 . V_2 = V_2 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_55 = F_50 ( & V_80 -> V_88 , & V_2 -> V_89 , V_135 ,
V_79 , V_80 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
if ( V_55 != V_30 )
goto V_138;
if ( V_79 -> V_50 & V_66 ) {
V_55 = F_51 ( V_2 , V_80 -> V_62 . V_139 ,
V_104 ) ;
if ( V_55 != V_30 )
goto V_140;
}
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_52 ( & V_80 -> V_88 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
return V_30 ;
V_140:
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_80 -> V_67 = & V_43 ;
F_9 ( V_80 -> V_67 ) ;
F_53 ( & V_80 -> V_88 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
F_16 ( V_80 -> V_67 ) ;
V_138:
F_54 ( V_80 ) ;
V_74:
return V_55 ;
}
void
F_55 ( unsigned long V_141 )
{
struct V_1 * V_2 = (struct V_1 * ) V_141 ;
unsigned long V_14 ;
struct V_142 V_143 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_56 ( & V_2 -> V_20 . V_144 ) ;
F_57 ( & V_2 -> V_20 , & V_143 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
if ( ! F_58 ( & V_143 ) ) {
F_59 ( & V_2 -> V_20 , & V_143 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_60 ( & V_2 -> V_20 , & V_143 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
}
F_61 ( & V_2 -> V_36 ,
V_145 + F_62 ( V_146 ) ) ;
}
void
F_15 ( struct V_1 * V_2 )
{
F_63 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_147 = F_55 ;
V_2 -> V_36 . V_141 = ( unsigned long ) V_2 ;
F_61 ( & V_2 -> V_36 ,
V_145 + F_62 ( V_146 ) ) ;
}
int
F_64 ( struct V_148 * V_149 , struct V_1 * V_2 )
{
int V_55 = - V_150 ;
if ( F_65 ( V_149 ) ) {
F_6 ( V_151 L_11 , V_149 ) ;
goto V_152;
}
if ( F_66 ( V_149 , V_153 ) )
goto V_154;
F_67 ( V_149 ) ;
if ( F_68 ( V_149 , F_69 ( 64 ) ) != 0 )
if ( F_68 ( V_149 , F_69 ( 32 ) ) != 0 ) {
F_6 ( V_151 L_12 , V_149 ) ;
goto V_155;
}
V_2 -> V_156 = F_70 ( V_149 , 0 , F_71 ( V_149 , 0 ) ) ;
if ( V_2 -> V_156 == NULL ) {
F_6 ( V_151 L_13 ) ;
goto V_155;
}
V_2 -> V_157 . V_158 = F_72 ( V_149 -> V_159 ) ;
V_2 -> V_157 . V_160 = F_73 ( V_149 -> V_159 ) ;
V_2 -> V_157 . V_161 = V_2 -> V_156 ;
V_2 -> V_157 . V_162 = V_149 -> V_136 ;
V_2 -> V_26 = V_26 ( V_149 ) ;
V_2 -> V_163 . V_164 = V_149 -> V_165 ;
V_2 -> V_163 . V_162 = V_149 -> V_136 ;
V_2 -> V_163 . V_166 = V_149 -> V_167 ;
V_2 -> V_163 . V_168 = V_149 -> V_169 ;
V_2 -> V_163 . V_170 = F_73 ( V_149 -> V_159 ) ;
V_2 -> V_103 = V_149 ;
if ( V_171 > 0 ) {
int V_172 ;
T_2 V_173 ;
T_2 V_174 = 0xffff ;
switch ( V_171 ) {
case 128 :
V_174 = 0x0 ;
break;
case 256 :
V_174 = 0x1000 ;
break;
case 512 :
V_174 = 0x2000 ;
break;
case 1024 :
V_174 = 0x3000 ;
break;
case 2048 :
V_174 = 0x4000 ;
break;
case 4096 :
V_174 = 0x5000 ;
break;
default:
break;
}
V_172 = F_74 ( V_149 , V_175 ) ;
if ( V_174 != 0xffff && V_172 ) {
V_172 += 0x08 ;
F_75 ( V_149 , V_172 , & V_173 ) ;
if ( ( V_173 & 0x7000 ) != V_174 ) {
F_6 ( V_17 L_14
L_15
L_16 , V_2 -> V_26 ,
( 1 << ( ( V_173 & 0x7000 ) >> 12 ) ) << 7 ,
V_171 ) ;
V_173 &= ~ 0x7000 ;
F_76 ( V_149 , V_172 ,
V_173 | V_174 ) ;
}
}
}
return 0 ;
V_155:
F_77 ( V_149 ) ;
V_154:
F_78 ( V_149 ) ;
V_152:
return V_55 ;
}
void
F_79 ( struct V_148 * V_149 , struct V_1 * V_2 )
{
F_80 ( V_149 , V_2 -> V_156 ) ;
F_77 ( V_149 ) ;
F_78 ( V_149 ) ;
F_81 ( V_149 , NULL ) ;
}
T_1
F_82 ( struct V_1 * V_2 )
{
T_1 V_55 ;
unsigned long V_14 ;
V_2 -> V_132 . V_176 = V_176 ;
V_2 -> V_132 . V_177 = V_178 ;
V_2 -> V_132 . V_179 = V_180 ;
V_2 -> V_132 . V_181 = V_182 ;
V_55 = F_43 ( V_2 ) ;
if ( V_55 != V_30 ) {
F_6 ( V_17 L_17 ,
V_2 -> V_10 ) ;
F_6 ( V_17
L_18 ,
L_19 ) ;
goto V_183;
}
V_2 -> V_20 . V_184 = V_2 -> V_184 ;
V_2 -> V_20 . V_185 = & V_2 -> V_186 ;
F_83 ( & V_2 -> V_186 ) ;
F_84 ( & V_2 -> V_186 , V_187 , V_188 ,
0 , L_20 ) ;
F_85 ( & V_2 -> V_20 , V_2 , & V_2 -> V_130 , & V_2 -> V_95 ,
& V_2 -> V_157 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_2 -> V_89 . V_184 = V_2 -> V_184 ;
F_86 ( & V_2 -> V_89 , & V_2 -> V_20 , V_2 , V_189 ) ;
V_2 -> V_89 . V_190 = V_191 ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
V_2 -> V_21 |= V_192 ;
return V_30 ;
V_183:
return V_193 ;
}
void
F_87 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_88 ( & V_2 -> V_20 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
F_16 ( & V_2 -> V_16 ) ;
F_23 ( & V_2 -> V_36 ) ;
F_89 ( & V_2 -> V_20 ) ;
F_90 ( & V_2 -> V_20 ) ;
F_22 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_21 &= ~ V_192 ;
}
void
F_91 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_92 ( & V_2 -> V_20 ) ;
F_93 ( & V_2 -> V_89 ) ;
V_2 -> V_21 |= V_194 ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
if ( V_2 -> V_195 )
F_94 ( V_2 -> V_195 -> V_196 ) ;
}
void
F_24 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_9 ( & V_2 -> V_16 ) ;
V_2 -> V_57 . V_14 |= V_197 ;
F_95 ( & V_2 -> V_89 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
F_16 ( & V_2 -> V_16 ) ;
F_7 ( V_2 , V_38 ) ;
}
void
F_21 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_88 ( & V_2 -> V_20 ) ;
V_2 -> V_21 &= ~ V_194 ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
F_16 ( & V_2 -> V_16 ) ;
F_7 ( V_2 , V_35 ) ;
}
T_1
F_96 ( struct V_1 * V_2 , enum V_49 V_198 )
{
int V_55 = V_30 ;
if ( ( V_199 & V_66 ) &&
( V_198 & V_66 ) ) {
if ( V_2 -> V_57 . V_139 == NULL ) {
V_55 = V_193 ;
goto V_152;
}
V_55 = F_51 ( V_2 , V_2 -> V_57 . V_139 ,
& V_2 -> V_103 -> V_104 ) ;
if ( V_55 != V_30 )
goto V_152;
V_2 -> V_57 . V_50 |= V_66 ;
}
V_2 -> V_21 |= V_33 ;
V_152:
return V_55 ;
}
void
F_19 ( struct V_1 * V_2 )
{
if ( ( V_199 & V_66 ) &&
( V_2 -> V_57 . V_50 & V_66 ) ) {
F_97 ( V_2 , V_2 -> V_57 . V_139 ) ;
F_98 ( V_2 -> V_57 . V_139 ) ;
F_54 ( V_2 -> V_57 . V_139 ) ;
V_2 -> V_57 . V_50 &= ~ V_66 ;
}
V_2 -> V_21 &= ~ V_33 ;
}
T_1
F_18 ( struct V_1 * V_2 ) {
int V_29 ;
unsigned long V_14 ;
struct V_53 * V_80 , * V_200 ;
struct V_201 V_202 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
strncpy ( V_202 . V_203 , V_204 ,
sizeof( V_202 . V_203 ) - 1 ) ;
if ( V_205 )
strncpy ( V_202 . V_206 , V_205 ,
sizeof( V_202 . V_206 ) - 1 ) ;
if ( V_207 )
strncpy ( V_202 . V_208 , V_207 ,
sizeof( V_202 . V_208 ) - 1 ) ;
if ( V_209 )
strncpy ( V_202 . V_210 , V_209 ,
sizeof( V_202 . V_210 ) - 1 ) ;
strncpy ( V_202 . V_211 , V_2 -> V_26 ,
sizeof( V_202 . V_211 - 1 ) ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_99 ( & V_2 -> V_89 , & V_202 ) ;
F_100 ( & V_2 -> V_89 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
V_29 = F_96 ( V_2 , V_66 ) ;
if ( V_29 != V_30 ) {
if ( F_101 ( V_2 , V_15 ) )
F_3 ( V_2 , V_32 ) ;
F_21 ( V_2 ) ;
return V_193 ;
}
V_29 = F_102 ( V_2 ) ;
if ( V_29 != V_30 ) {
F_6 ( V_17 L_21 ) ;
if ( F_101 ( V_2 , V_15 ) )
F_3 ( V_2 , V_32 ) ;
F_20 ( V_2 ) ;
V_2 -> V_21 &= ~ V_34 ;
F_19 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_193 ;
} else
V_2 -> V_21 |= V_34 ;
F_91 ( V_2 ) ;
F_103 (vport, vport_new, &bfad->pbc_vport_list,
list_entry) {
struct V_212 V_213 ;
struct V_214 * V_214 ;
char V_215 [ V_216 ] ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
V_213 . V_50 = V_217 ;
V_213 . V_218 = V_219 ;
V_213 . V_220 = false ;
V_213 . V_221 = F_104 ( ( V_222 * )
( & ( ( V_80 -> V_88 ) . V_223 . V_79 . V_84 ) ) ) ;
V_213 . V_224 = F_104 ( ( V_222 * )
( & ( ( V_80 -> V_88 ) . V_223 . V_79 . V_82 ) ) ) ;
V_214 = F_105 ( V_2 -> V_57 . V_139 -> V_225 , 0 , & V_213 ) ;
if ( ! V_214 ) {
F_106 ( V_215 , V_213 . V_224 ) ;
F_6 ( V_17 L_22
L_23 , V_2 -> V_10 , V_215 ) ;
}
F_107 ( & V_80 -> V_90 ) ;
F_54 ( V_80 ) ;
}
if ( V_226 < 0 ) {
V_226 = F_108 ( V_2 ) ;
F_109 ( V_2 ) ;
V_226 = - 1 ;
} else
F_109 ( V_2 ) ;
F_110 ( V_9 , V_2 , V_227 , L_24 ) ;
return V_30 ;
}
int
V_8 ( void * V_228 )
{
struct V_1 * V_2 ;
unsigned long V_14 ;
V_2 = (struct V_1 * ) V_228 ;
while ( ! F_111 () ) {
F_7 ( V_2 , V_25 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_2 -> V_7 = NULL ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
break;
}
return 0 ;
}
T_3
F_112 ( int V_229 , void * V_230 )
{
struct V_1 * V_2 = V_230 ;
struct V_142 V_143 ;
unsigned long V_14 ;
T_4 V_55 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
V_55 = F_113 ( & V_2 -> V_20 ) ;
if ( ! V_55 ) {
F_13 ( & V_2 -> V_19 , V_14 ) ;
return V_231 ;
}
F_57 ( & V_2 -> V_20 , & V_143 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
if ( ! F_58 ( & V_143 ) ) {
F_59 ( & V_2 -> V_20 , & V_143 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_60 ( & V_2 -> V_20 , & V_143 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
}
return V_232 ;
}
static T_3
F_114 ( int V_229 , void * V_230 )
{
struct V_233 * V_234 = V_230 ;
struct V_1 * V_2 = V_234 -> V_2 ;
struct V_142 V_143 ;
unsigned long V_14 ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_115 ( & V_2 -> V_20 , V_234 -> V_235 . V_236 ) ;
F_57 ( & V_2 -> V_20 , & V_143 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
if ( ! F_58 ( & V_143 ) ) {
F_59 ( & V_2 -> V_20 , & V_143 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_60 ( & V_2 -> V_20 , & V_143 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
}
return V_232 ;
}
static void
F_116 ( struct V_1 * V_2 , struct V_237 * V_238 ,
int V_174 , int V_239 )
{
int V_92 ;
int V_240 = 0x00000001 ;
for ( V_92 = 0 , V_2 -> V_241 = 0 ; V_92 < V_242 ; V_92 ++ ) {
if ( V_174 & V_240 ) {
V_2 -> V_243 [ V_2 -> V_241 ] . V_235 . V_236 = V_92 ;
V_2 -> V_243 [ V_2 -> V_241 ] . V_2 = V_2 ;
V_238 [ V_2 -> V_241 ] . V_236 = V_92 ;
V_2 -> V_241 ++ ;
}
V_240 <<= 1 ;
}
}
int
F_14 ( struct V_1 * V_2 )
{
int V_92 , error = 0 ;
for ( V_92 = 0 ; V_92 < V_2 -> V_241 ; V_92 ++ ) {
sprintf ( V_2 -> V_243 [ V_92 ] . V_244 , L_25 ,
V_2 -> V_26 ,
( ( F_117 ( V_2 -> V_157 . V_162 ) ) ?
V_245 [ V_92 ] : V_246 [ V_92 ] ) ) ;
error = F_118 ( V_2 -> V_243 [ V_92 ] . V_235 . V_247 ,
( V_248 ) F_114 , 0 ,
V_2 -> V_243 [ V_92 ] . V_244 , & V_2 -> V_243 [ V_92 ] ) ;
F_2 ( V_2 , V_92 ) ;
F_2 ( V_2 , V_2 -> V_243 [ V_92 ] . V_235 . V_247 ) ;
if ( error ) {
int V_249 ;
for ( V_249 = 0 ; V_249 < V_92 ; V_249 ++ )
F_119 ( V_2 -> V_243 [ V_249 ] . V_235 . V_247 ,
& V_2 -> V_243 [ V_249 ] ) ;
return 1 ;
}
}
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
int error = 0 ;
T_5 V_174 = 0 , V_92 , V_250 = 0 , V_239 = 0 ;
struct V_237 V_238 [ V_242 ] ;
struct V_148 * V_149 = V_2 -> V_103 ;
F_120 ( & V_2 -> V_20 , & V_174 , & V_250 , & V_239 ) ;
F_116 ( V_2 , V_238 , V_174 , V_239 ) ;
if ( ( F_117 ( V_149 -> V_136 ) && ! V_251 ) ||
( ! F_117 ( V_149 -> V_136 ) && ! V_252 ) ) {
error = F_121 ( V_2 -> V_103 , V_238 , V_2 -> V_241 ) ;
if ( error ) {
F_6 ( V_17 L_26
L_27
L_28 , V_2 -> V_10 , error ) ;
goto V_253;
}
for ( V_92 = 0 ; V_92 < V_2 -> V_241 ; V_92 ++ ) {
F_2 ( V_2 , V_238 [ V_92 ] . V_247 ) ;
V_2 -> V_243 [ V_92 ] . V_235 . V_247 = V_238 [ V_92 ] . V_247 ;
}
F_122 ( & V_2 -> V_20 , V_2 -> V_241 ) ;
V_2 -> V_21 |= V_22 ;
return error ;
}
V_253:
error = 0 ;
if ( F_118
( V_2 -> V_103 -> V_229 , ( V_248 ) F_112 , V_254 ,
V_153 , V_2 ) != 0 ) {
return 1 ;
}
return error ;
}
void
F_22 ( struct V_1 * V_2 )
{
int V_92 ;
if ( V_2 -> V_21 & V_22 ) {
for ( V_92 = 0 ; V_92 < V_2 -> V_241 ; V_92 ++ )
F_119 ( V_2 -> V_243 [ V_92 ] . V_235 . V_247 ,
& V_2 -> V_243 [ V_92 ] ) ;
F_123 ( V_2 -> V_103 ) ;
V_2 -> V_21 &= ~ V_22 ;
} else {
F_119 ( V_2 -> V_103 -> V_229 , V_2 ) ;
}
}
int
F_124 ( struct V_148 * V_149 , const struct V_255 * V_256 )
{
struct V_1 * V_2 ;
int error = - V_150 , V_29 ;
if ( ( V_149 -> V_136 == V_257 ) &&
( F_73 ( V_149 -> V_159 ) != 0 ) )
return - V_150 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_2 ) {
error = - V_258 ;
goto V_152;
}
V_2 -> V_184 = F_34 ( sizeof( struct V_259 ) , V_81 ) ;
if ( ! V_2 -> V_184 ) {
F_6 ( V_17 L_29 ) ;
error = - V_258 ;
goto V_260;
}
F_125 ( V_2 -> V_184 ) ;
F_2 ( V_2 , V_261 ) ;
if ( ! ( F_126 ( V_149 ) ) ) {
F_54 ( V_2 -> V_184 ) ;
goto V_260;
}
V_29 = F_64 ( V_149 , V_2 ) ;
if ( V_29 ) {
F_6 ( V_17 L_30 ) ;
error = V_29 ;
goto V_262;
}
F_127 ( & V_263 ) ;
V_2 -> V_10 = V_261 ++ ;
F_37 ( & V_2 -> V_90 , & V_264 ) ;
F_128 ( & V_263 ) ;
F_3 ( V_2 , F_1 ) ;
F_129 ( & V_2 -> V_19 ) ;
F_81 ( V_149 , V_2 ) ;
V_2 -> V_265 = 0 ;
V_2 -> V_57 . V_2 = V_2 ;
F_130 ( & V_2 -> V_91 ) ;
if ( V_266 )
F_131 ( & V_2 -> V_57 ) ;
V_29 = F_82 ( V_2 ) ;
if ( V_29 != V_30 )
goto V_267;
F_7 ( V_2 , V_5 ) ;
if ( F_101 ( V_2 , F_1 ) )
goto V_268;
return 0 ;
V_268:
F_90 ( & V_2 -> V_20 ) ;
F_38 ( V_2 ) ;
V_267:
F_54 ( V_2 -> V_269 ) ;
F_132 ( & V_2 -> V_57 ) ;
F_127 ( & V_263 ) ;
V_261 -- ;
F_107 ( & V_2 -> V_90 ) ;
F_128 ( & V_263 ) ;
F_79 ( V_149 , V_2 ) ;
V_262:
F_54 ( V_2 -> V_184 ) ;
V_260:
F_54 ( V_2 ) ;
V_152:
return error ;
}
void
F_133 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_134 ( V_149 ) ;
unsigned long V_14 ;
F_2 ( V_2 , V_2 -> V_10 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
if ( V_2 -> V_7 != NULL ) {
F_13 ( & V_2 -> V_19 , V_14 ) ;
F_17 ( V_2 -> V_7 ) ;
} else {
F_13 ( & V_2 -> V_19 , V_14 ) ;
}
F_7 ( V_2 , V_13 ) ;
F_11 ( & V_2 -> V_19 , V_14 ) ;
F_90 ( & V_2 -> V_20 ) ;
F_13 ( & V_2 -> V_19 , V_14 ) ;
F_38 ( V_2 ) ;
F_54 ( V_2 -> V_269 ) ;
F_132 ( & V_2 -> V_57 ) ;
F_127 ( & V_263 ) ;
V_261 -- ;
F_107 ( & V_2 -> V_90 ) ;
F_128 ( & V_263 ) ;
F_79 ( V_149 , V_2 ) ;
F_54 ( V_2 -> V_184 ) ;
F_54 ( V_2 ) ;
}
static int T_6
F_135 ( void )
{
int error = 0 ;
F_6 ( V_9 L_31 ,
V_204 ) ;
if ( V_125 > 0 )
V_134 = V_125 ;
error = F_136 () ;
if ( error ) {
error = - V_258 ;
F_6 ( V_17 L_32 ) ;
goto V_74;
}
if ( strcmp ( V_270 , L_33 ) == 0 )
V_199 |= V_66 ;
V_271 = V_272 ;
F_137 ( V_176 ) ;
error = F_138 ( & V_273 ) ;
if ( error ) {
F_6 ( V_17 L_34 ) ;
goto V_74;
}
return 0 ;
V_74:
F_139 () ;
return error ;
}
static void T_7
F_140 ( void )
{
F_141 ( & V_273 ) ;
F_139 () ;
F_142 () ;
}
static void
F_143 ( struct V_148 * V_149 , T_5 * * V_274 ,
T_5 * V_275 , char * V_276 )
{
const struct V_277 * V_278 ;
if ( F_144 ( & V_278 , V_276 , & V_149 -> V_104 ) ) {
F_6 ( V_279 L_35 , V_276 ) ;
* V_274 = NULL ;
goto V_152;
}
* V_274 = F_46 ( V_278 -> V_280 ) ;
if ( NULL == * V_274 ) {
F_6 ( V_279 L_36
L_37 , ( T_5 ) V_278 -> V_280 ) ;
goto V_152;
}
memcpy ( * V_274 , V_278 -> V_141 , V_278 -> V_280 ) ;
* V_275 = V_278 -> V_280 / sizeof( T_5 ) ;
V_152:
F_145 ( V_278 ) ;
}
static T_5 *
F_126 ( struct V_148 * V_149 )
{
if ( V_149 -> V_136 == V_281 ) {
if ( V_282 == 0 )
F_143 ( V_149 , & V_283 ,
& V_282 , V_284 ) ;
return V_283 ;
} else if ( V_149 -> V_136 == V_285 ) {
if ( V_286 == 0 )
F_143 ( V_149 , & V_287 ,
& V_286 , V_288 ) ;
return V_287 ;
} else {
if ( V_289 == 0 )
F_143 ( V_149 , & V_290 ,
& V_289 , V_291 ) ;
return V_290 ;
}
}
static void
F_142 ( void )
{
if ( V_282 && V_283 )
F_39 ( V_283 ) ;
if ( V_286 && V_287 )
F_39 ( V_287 ) ;
if ( V_289 && V_290 )
F_39 ( V_290 ) ;
}
