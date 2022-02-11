int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_7 ) ;
#ifdef F_5
if( V_2 -> V_8 > 0 )
{
unsigned long V_9 = F_6 () ;
F_7 ( V_2 -> V_8 ) ;
F_8 ( V_2 -> V_8 , V_10 ) ;
F_9 ( V_2 -> V_8 ) ;
F_10 ( V_9 ) ;
}
#endif
V_5 = F_11 ( V_2 ) ;
if( V_5 )
{
F_12 ( V_11 L_1 ,
V_2 -> V_12 ) ;
return - 1 ;
}
V_4 -> V_7 . V_13 = V_14 + 30 * V_15 ;
V_4 -> V_7 . V_16 = V_17 ;
V_4 -> V_7 . V_18 = ( unsigned long ) V_2 ;
F_13 ( & V_4 -> V_7 ) ;
F_12 ( V_19 L_2 ,
V_2 -> V_12 , F_14 ( V_2 ) ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
V_4 -> V_20 = 1 ;
F_18 ( & V_4 -> V_21 ) ;
F_19 ( & V_4 -> V_7 ) ;
if( V_4 -> V_22 == 0 )
{
F_20 ( V_2 ) ;
return - 1 ;
}
V_4 -> V_23 = V_14 ;
V_4 -> V_7 . V_13 = V_14 + 2 * V_15 ;
V_4 -> V_7 . V_16 = V_24 ;
V_4 -> V_7 . V_18 = ( unsigned long ) V_2 ;
F_13 ( & V_4 -> V_7 ) ;
return 0 ;
}
static void V_17 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if( V_4 -> V_20 )
{
V_4 -> V_20 = 0 ;
F_21 ( & V_4 -> V_21 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_22 ( V_4 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
if( V_25 > 3 )
F_12 ( V_19 L_3 , V_2 -> V_12 ) ;
V_5 = F_25 ( V_2 ) ;
if( V_5 < 0 )
return - 1 ;
if( V_25 > 3 )
F_12 ( V_19 L_4 , V_2 -> V_12 ) ;
V_5 = F_26 ( V_2 ) ;
if( V_5 < 0 )
return - 1 ;
if( V_25 > 3 )
F_12 ( V_19 L_5 , V_2 -> V_12 ) ;
V_5 = F_27 ( V_2 ) ;
if( V_5 < 0 )
return - 1 ;
if( V_25 > 3 )
F_12 ( V_19 L_6 , V_2 -> V_12 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_26 ;
T_1 V_27 ;
V_4 -> V_28 . V_29 = 0 ;
V_4 -> V_28 . V_30 [ 0 ] = 0 ;
V_4 -> V_28 . V_30 [ 1 ] = 0 ;
V_4 -> V_31 . V_32 = 0 ;
V_4 -> V_31 . V_30 [ 0 ] = 0 ;
V_4 -> V_31 . V_30 [ 1 ] = 0 ;
V_4 -> V_31 . V_30 [ 2 ] = 0 ;
V_4 -> V_33 = 0 ;
V_4 -> V_34 = 0 ;
V_4 -> V_22 = 0 ;
V_4 -> V_35 = 0 ;
V_4 -> V_36 = 0 ;
V_4 -> V_37 = 0 ;
V_4 -> V_38 = 0 ;
V_4 -> V_39 = 0 ;
V_4 -> V_40 = 0 ;
V_4 -> V_41 = 0 ;
V_4 -> V_42 = V_43 ;
for ( V_26 = 0 ; V_26 < V_44 ; V_26 ++ )
{
V_4 -> V_45 [ V_26 ] . V_46 = F_28 ( ( ( char * ) ( & V_4 -> V_45 [ ( V_26 + 1 ) % V_44 ] ) - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_45 [ V_26 ] . V_48 = 0 ;
V_4 -> V_45 [ V_26 ] . V_49 = 0 ;
V_4 -> V_45 [ V_26 ] . V_50 [ 0 ] . V_51 = 0 ;
V_4 -> V_45 [ V_26 ] . V_50 [ 0 ] . V_52 = 0 ;
V_4 -> V_45 [ V_26 ] . V_53 = & V_4 -> V_45 [ ( V_26 + 1 ) % V_44 ] ;
V_4 -> V_45 [ V_26 ] . V_54 = NULL ;
V_4 -> V_45 [ V_26 ] . V_55 = V_26 ;
V_4 -> V_45 [ V_26 ] . V_56 = 0 ;
V_4 -> V_45 [ V_26 ] . V_57 = 0 ;
}
V_4 -> V_58 = V_4 -> V_59 = & V_4 -> V_45 [ 0 ] ;
for ( V_26 = 0 ; V_26 < V_60 ; V_26 ++ )
{
V_4 -> V_61 [ V_26 ] . V_62 = F_28 ( ( ( char * ) ( & V_4 -> V_61 [ ( V_26 + 1 ) % V_60 ] ) - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_61 [ V_26 ] . V_48 = ( V_63 | V_64 | V_65 | V_66 ) ;
V_4 -> V_61 [ V_26 ] . V_49 = 0 ;
V_4 -> V_61 [ V_26 ] . V_50 [ 0 ] . V_51 = F_29 ( ( unsigned short ) V_4 -> V_42 ) ;
V_4 -> V_61 [ V_26 ] . V_67 = F_30 ( V_4 -> V_42 ) ;
V_4 -> V_61 [ V_26 ] . V_56 = 0 ;
if( V_4 -> V_61 [ V_26 ] . V_67 == NULL )
{
V_4 -> V_61 [ V_26 ] . V_68 = V_69 ;
V_4 -> V_61 [ V_26 ] . V_50 [ 0 ] . V_52 = F_28 ( ( ( char * ) V_4 -> V_70 [ V_26 ] - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_61 [ V_26 ] . V_54 = V_4 -> V_70 [ V_26 ] ;
}
else
{
V_4 -> V_61 [ V_26 ] . V_67 -> V_2 = V_2 ;
F_31 ( V_4 -> V_61 [ V_26 ] . V_67 , V_4 -> V_42 ) ;
V_27 = F_32 ( V_4 -> V_71 , V_4 -> V_61 [ V_26 ] . V_67 -> V_18 , V_4 -> V_42 , V_72 ) ;
if( V_4 -> V_73 && ( V_27 + V_4 -> V_42 > V_4 -> V_73 ) )
{
V_4 -> V_61 [ V_26 ] . V_68 = V_74 ;
V_4 -> V_61 [ V_26 ] . V_50 [ 0 ] . V_52 = F_28 ( ( ( char * ) V_4 -> V_70 [ V_26 ] - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_61 [ V_26 ] . V_54 = V_4 -> V_70 [ V_26 ] ;
}
else
{
V_4 -> V_61 [ V_26 ] . V_68 = V_75 ;
V_4 -> V_61 [ V_26 ] . V_50 [ 0 ] . V_52 = F_28 ( V_27 ) ;
V_4 -> V_61 [ V_26 ] . V_54 = V_4 -> V_61 [ V_26 ] . V_67 -> V_18 ;
V_4 -> V_61 [ V_26 ] . V_56 = V_27 ;
}
}
V_4 -> V_61 [ V_26 ] . V_76 = & V_4 -> V_61 [ ( V_26 + 1 ) % V_60 ] ;
V_4 -> V_61 [ V_26 ] . V_77 = V_26 ;
}
V_4 -> V_78 = & V_4 -> V_61 [ 0 ] ;
V_4 -> V_79 = & V_4 -> V_61 [ V_60 - 1 ] ;
V_4 -> V_79 -> V_48 = ( V_64 | V_65 | V_66 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
V_4 -> V_80 . V_81 = V_82 ;
V_4 -> V_80 . V_83 = 0 ;
V_4 -> V_80 . V_84 = 0 ;
V_4 -> V_80 . V_85 = 0 ;
V_4 -> V_80 . V_86 = 0 ;
V_4 -> V_80 . V_87 = 0 ;
V_4 -> V_80 . V_88 = 0 ;
V_4 -> V_80 . V_89 = V_90 ;
V_4 -> V_80 . V_91 = V_90 ;
V_4 -> V_80 . V_92 = V_93 ;
V_4 -> V_80 . V_94 = 0 ;
V_4 -> V_80 . V_95 = 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_96 ;
unsigned short V_97 = V_98 ;
unsigned short V_99 = V_100 ;
unsigned short V_101 = V_102 ;
int V_26 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_103 . V_104 = 0 ;
V_4 -> V_103 . V_104 |= V_105 ;
V_4 -> V_103 . V_106 = 0 ;
V_4 -> V_103 . V_106 |= V_107 ;
for ( V_26 = 0 ; V_26 < 6 ; V_26 ++ )
V_4 -> V_103 . V_108 [ V_26 ] = ( ( unsigned char * ) V_2 -> V_109 ) [ V_26 ] ;
V_4 -> V_103 . V_110 = 0 ;
V_4 -> V_103 . V_111 = 0 ;
V_4 -> V_103 . V_112 = F_29 ( ( unsigned short ) V_97 ) ;
V_4 -> V_103 . V_113 = F_29 ( ( unsigned short ) V_99 ) ;
V_4 -> V_103 . V_114 = F_29 ( ( unsigned short ) V_101 ) ;
V_4 -> V_103 . V_115 = 0 ;
V_4 -> V_103 . V_116 = V_117 ;
V_4 -> V_103 . V_118 = V_119 ;
V_96 = F_28 ( ( ( char * ) V_4 -> V_120 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_103 . V_121 [ 0 ] = F_33 ( V_96 ) ;
V_4 -> V_103 . V_121 [ 1 ] = F_34 ( V_96 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if( V_4 -> V_36 )
return;
V_4 -> V_36 = 1 ;
F_35 ( V_2 , V_122 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_36 ( 0 , V_123 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_36 ( V_124 , V_123 ) ;
}
static void F_35 ( struct V_1 * V_2 , unsigned short V_125 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_33 |= V_125 ;
F_37 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_126 = V_14 ;
F_39 ( V_2 ) ;
}
static T_2 F_40 ( struct V_127 * V_128 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_129 ;
V_129 = F_41 ( V_128 , V_2 ) ;
if( V_4 -> V_58 -> V_53 -> V_57 )
F_42 ( V_2 ) ;
return V_129 ;
}
static T_2 F_41 ( struct V_127 * V_128 ,
struct V_1 * V_2 )
{
T_3 * V_130 ;
short V_131 ;
unsigned char * V_132 ;
unsigned long V_9 ;
int V_26 ;
T_1 V_27 , V_133 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_43 ( & V_4 -> V_6 , V_9 ) ;
if( V_4 -> V_58 -> V_53 -> V_57 ) {
if ( V_25 > 0 )
F_12 ( V_19 L_7 , V_2 -> V_12 ) ;
F_44 ( & V_4 -> V_6 , V_9 ) ;
return V_134 ;
}
V_27 = 0 ;
V_131 = V_128 -> V_135 ;
V_27 = F_32 ( V_4 -> V_71 , V_128 -> V_18 , V_131 , V_136 ) ;
if( V_4 -> V_73 && ( V_27 + V_131 > V_4 -> V_73 ) ) {
F_45 ( V_4 -> V_71 , V_27 , V_131 , V_136 ) ;
V_27 = 0 ;
V_26 = V_4 -> V_58 -> V_55 ;
V_132 = V_4 -> V_137 [ V_26 ] ;
F_46 ( V_128 , V_132 , V_131 ) ;
V_133 = ( ( char * ) V_132 - ( char * ) V_4 ) + V_4 -> V_47 ;
}
else {
V_133 = V_27 ;
V_132 = V_128 -> V_18 ;
}
F_47 ( V_132 , V_2 -> V_109 ) ;
V_4 -> V_138 = V_14 ;
V_130 = V_4 -> V_58 ;
V_130 -> V_57 = 1 ;
V_4 -> V_58 = V_130 -> V_53 ;
V_130 -> V_67 = V_128 ;
V_130 -> V_56 = V_27 ;
V_130 -> V_50 [ 0 ] . V_51 = F_29 ( ( unsigned short ) V_131 ) ;
V_130 -> V_50 [ 0 ] . V_52 = F_28 ( V_133 ) ;
V_130 -> V_49 = F_29 ( ( unsigned short ) V_131 ) ;
V_130 -> V_54 = V_132 ;
F_48 ( V_130 , V_139 | V_140
| V_141 | V_142
| V_143 ) ;
F_49 ( V_2 , V_144 ) ;
F_44 ( & V_4 -> V_6 , V_9 ) ;
return V_145 ;
}
static void F_48 ( T_3 * V_130 , unsigned int V_48 )
{
V_130 -> V_48 = V_48 ;
}
static void F_47 ( unsigned char * V_146 , unsigned char * V_147 )
{
unsigned char V_148 ;
if( ( ( ( unsigned long ) V_146 [ 8 ] ) & ~ 0x80 ) != 0 )
return;
if( ( unsigned short ) V_146 [ 12 ] != 0 )
return;
V_148 = V_146 [ 8 ] & 0x80 ;
memcpy ( & V_146 [ 8 ] , V_147 , 6 ) ;
V_146 [ 8 ] |= V_148 ;
}
static void V_24 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if( V_4 -> V_38 )
return;
F_37 ( V_2 ) ;
if( F_50 ( V_4 -> V_138 + V_149 , V_14 ) &&
( V_4 -> V_58 != V_4 -> V_59 ) )
{
V_4 -> V_138 = V_14 ;
F_35 ( V_2 , V_150 ) ;
}
V_4 -> V_7 . V_13 = V_14 + 2 * V_15 ;
F_13 ( & V_4 -> V_7 ) ;
if( V_4 -> V_34 || V_4 -> V_37 )
return;
V_4 -> V_37 = 1 ;
F_16 ( V_2 ) ;
}
T_4 F_51 ( int V_151 , void * V_152 )
{
struct V_1 * V_2 = V_152 ;
struct V_3 * V_4 ;
unsigned short V_153 ;
int V_154 = 0 ;
V_4 = F_2 ( V_2 ) ;
V_153 = F_52 ( V_155 ) ;
while( V_153 & V_156 ) {
V_154 = 1 ;
V_153 &= V_157 ;
if( ! F_53 ( V_4 , V_153 ) ) {
F_12 ( V_19 L_8 , V_2 -> V_12 ) ;
break;
}
switch( V_153 ) {
case V_158 :
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
break;
case V_159 :
if( V_4 -> V_31 . V_30 [ 0 ] & V_160 ) {
V_4 -> V_161 = 0 ;
V_4 -> V_39 = 0 ;
F_35 ( V_2 , V_162 ) ;
}
F_54 ( V_2 ) ;
F_56 ( V_2 ) ;
break;
case V_163 :
F_57 ( V_2 ) ;
break;
case V_164 :
V_4 -> V_35 = 0 ;
F_37 ( V_2 ) ;
break;
case V_165 :
F_58 ( V_2 ) ;
break;
case V_166 :
F_59 ( V_2 ) ;
break;
case V_167 :
F_12 ( V_19 L_9 ) ;
break;
case V_168 :
F_12 ( V_19 L_10 ) ;
break;
case V_169 :
F_12 ( V_19 L_11 ) ;
break;
default:
F_12 ( V_19 L_12 , V_153 ) ;
break;
}
if( V_153 != V_159 &&
V_153 != V_158 ) {
F_54 ( V_2 ) ;
}
V_153 = F_52 ( V_155 ) ;
}
return F_60 ( V_154 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 * V_31 = & V_4 -> V_31 ;
V_31 -> V_32 = ( unsigned short ) - 1 ;
V_31 -> V_30 [ 0 ] = ( unsigned short ) - 1 ;
V_31 -> V_30 [ 1 ] = ( unsigned short ) - 1 ;
V_31 -> V_30 [ 2 ] = ( unsigned short ) - 1 ;
F_49 ( V_2 , V_170 | V_171 ) ;
}
static unsigned char F_53 ( struct V_3 * V_4 , unsigned short V_172 )
{
T_5 * V_31 = & V_4 -> V_31 ;
if( V_172 != V_159 &&
V_172 != V_158 &&
V_172 != V_163 &&
V_172 != V_165 )
{
return 1 ;
}
if( V_31 -> V_32 == ( unsigned short ) - 1 )
return 0 ;
if( V_172 == V_163 )
return 1 ;
if( V_31 -> V_30 [ 0 ] == ( unsigned short ) - 1 )
return 0 ;
if( V_172 == V_165 )
return 1 ;
if( V_31 -> V_30 [ 1 ] == ( unsigned short ) - 1 )
return 0 ;
if( V_31 -> V_30 [ 2 ] == ( unsigned short ) - 1 )
return 0 ;
return 1 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_173 , V_174 ;
unsigned short V_175 ;
char * V_176 = L_13 ;
char * V_177 = L_14 ;
V_173 = V_4 -> V_31 . V_32 ;
V_174 = V_4 -> V_31 . V_30 [ 0 ] ;
V_175 = V_4 -> V_31 . V_30 [ 1 ] ;
if( V_173 == V_178 )
{
V_4 -> V_20 = 0 ;
if( ! V_4 -> V_37 )
F_21 ( & V_4 -> V_21 ) ;
V_4 -> V_36 = 0 ;
V_4 -> V_35 = 0 ;
if( ( V_174 & 0x00FF ) == V_179 )
{
V_4 -> V_40 = 0 ;
V_4 -> V_34 = 1 ;
V_4 -> V_22 = 1 ;
V_4 -> V_161 = 0 ;
F_35 ( V_2 , V_162 ) ;
F_35 ( V_2 , V_180 ) ;
if( V_4 -> V_37 )
V_4 -> V_37 = 0 ;
return;
}
else
{
if( V_174 & V_181 )
F_12 ( V_11 L_15 ,
V_2 -> V_12 ) ;
if( V_174 & V_182 )
F_12 ( V_11 L_16 ,
V_2 -> V_12 ) ;
if( V_174 & V_183 )
F_12 ( V_11 L_17 ,
V_2 -> V_12 ) ;
if( V_174 & V_184 )
F_12 ( V_11 L_18 ,
V_2 -> V_12 ) ;
if( V_174 & V_185 )
F_12 ( V_11 L_19 ,
V_2 -> V_12 ) ;
if( V_174 & V_186 )
{
switch( V_174 & V_187 )
{
case V_188 :
if( ! V_4 -> V_40 )
{
V_4 -> V_40 = 1 ;
F_12 ( V_11 L_20 , V_2 -> V_12 , V_176 ) ;
}
V_4 -> V_37 = 1 ;
V_4 -> V_34 = 0 ;
V_4 -> V_22 = 1 ;
F_16 ( V_2 ) ;
return;
case V_189 :
F_12 ( V_11 L_21 , V_2 -> V_12 , V_176 ) ;
break;
case V_190 :
F_12 ( V_11 L_22 , V_2 -> V_12 , V_176 ) ;
break;
case V_191 :
F_12 ( V_11 L_23 , V_2 -> V_12 , V_176 ) ;
break;
case V_192 :
F_12 ( V_11 L_24 , V_2 -> V_12 , V_176 ) ;
break;
case V_193 :
F_12 ( V_11 L_25 , V_2 -> V_12 , V_176 ) ;
break;
default:
F_12 ( V_11 L_26 , V_2 -> V_12 , V_176 ) ;
break;
}
switch( V_174 & V_194 )
{
case V_195 :
F_12 ( V_11 L_27 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_195 ;
break;
case V_196 :
F_12 ( V_11 L_28 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_196 ;
break;
case V_197 :
F_12 ( V_11 L_29 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_197 ;
break;
case V_198 :
F_12 ( V_11 L_30 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_198 ;
break;
case V_199 :
F_12 ( V_11 L_31 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_199 ;
break;
case V_200 :
F_12 ( V_11 L_32 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_200 ;
break;
case V_201 :
F_12 ( V_11 L_33 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_201 ;
break;
case V_202 :
F_12 ( V_11 L_34 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_202 ;
break;
case V_203 :
F_12 ( V_11 L_35 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_203 ;
break;
default:
F_12 ( V_11 L_36 , V_2 -> V_12 , V_177 ) ;
V_4 -> V_41 =
V_195 ;
break;
}
}
V_4 -> V_34 = 0 ;
V_4 -> V_22 = 0 ;
return;
}
}
else
{
if( V_173 != V_204 )
return;
V_4 -> V_205 . V_206 += V_4 -> V_207 . V_208 ;
V_4 -> V_205 . V_209 += V_4 -> V_207 . V_210 ;
V_4 -> V_205 . V_211 += V_4 -> V_207 . V_212 ;
V_4 -> V_205 . V_213 += V_4 -> V_207 . V_214 ;
V_4 -> V_205 . V_215 += V_4 -> V_207 . V_216 ;
V_4 -> V_205 . V_217 += V_4 -> V_207 . V_216 ;
V_4 -> V_205 . V_218 += V_4 -> V_207 . V_219 ;
V_4 -> V_205 . V_220 += V_4 -> V_207 . V_221 ;
V_4 -> V_205 . V_222 += V_4 -> V_207 . V_223 ;
V_4 -> V_205 . V_222 += V_4 -> V_207 . V_224 ;
V_4 -> V_205 . V_225 += V_4 -> V_207 . V_226 ;
V_4 -> V_205 . V_227 += V_4 -> V_207 . V_228 ;
V_4 -> V_205 . V_229 += V_4 -> V_207 . V_230 ;
}
}
int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_42 ( V_2 ) ;
F_19 ( & V_4 -> V_7 ) ;
V_4 -> V_38 = 1 ;
F_35 ( V_2 , V_150 ) ;
V_4 -> V_7 . V_13 = V_14 + 1 * V_15 ;
V_4 -> V_7 . V_16 = V_17 ;
V_4 -> V_7 . V_18 = ( unsigned long ) V_2 ;
F_13 ( & V_4 -> V_7 ) ;
F_15 ( V_2 ) ;
V_4 -> V_20 = 1 ;
F_18 ( & V_4 -> V_21 ) ;
V_4 -> V_161 = 0 ;
F_19 ( & V_4 -> V_7 ) ;
F_20 ( V_2 ) ;
#ifdef F_5
if( V_2 -> V_8 > 0 )
{
unsigned long V_9 = F_6 () ;
F_7 ( V_2 -> V_8 ) ;
F_10 ( V_9 ) ;
}
#endif
F_62 ( 0xFF00 , V_231 ) ;
#if 0
if(dev->dma > 0)
SIFWRITEB(0xff, POSREG);
#endif
F_63 ( V_4 ) ;
return 0 ;
}
static struct V_232 * F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return (struct V_232 * ) & V_4 -> V_205 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_233 ;
V_233 = V_4 -> V_103 . V_104 &
~ ( V_234
| V_235
| V_236
| V_237
| V_238 ) ;
V_4 -> V_103 . V_111 = 0 ;
if( V_2 -> V_9 & V_239 )
V_233 |= V_238 |
V_237 ;
else
{
if( V_2 -> V_9 & V_240 )
{
V_4 -> V_103 . V_111 = 0xFFFFFFFF ;
}
else
{
struct V_241 * V_242 ;
F_66 (ha, dev) {
( ( char * ) ( & V_4 -> V_103 . V_111 ) ) [ 0 ] |=
V_242 -> V_243 [ 2 ] ;
( ( char * ) ( & V_4 -> V_103 . V_111 ) ) [ 1 ] |=
V_242 -> V_243 [ 3 ] ;
( ( char * ) ( & V_4 -> V_103 . V_111 ) ) [ 2 ] |=
V_242 -> V_243 [ 4 ] ;
( ( char * ) ( & V_4 -> V_103 . V_111 ) ) [ 3 ] |=
V_242 -> V_243 [ 5 ] ;
}
}
F_35 ( V_2 , V_244 ) ;
}
V_4 -> V_103 . V_104 = V_233 ;
F_35 ( V_2 , V_245 ) ;
}
void F_67 ( unsigned long time )
{
#if 0
long tmp;
tmp = jiffies + time/(1000000/HZ);
do {
tmp = schedule_timeout_interruptible(tmp);
} while(time_after(tmp, jiffies));
#else
F_68 ( time / 1000 ) ;
#endif
}
static void F_49 ( struct V_1 * V_2 , unsigned int V_246 )
{
unsigned short V_247 ;
unsigned short V_248 ;
unsigned long V_249 ;
V_246 = ( ( V_246 ^ V_250 ) | V_251 ) ;
V_247 = ( unsigned short ) V_246 ;
V_249 = 0 , 5 * 800000 ;
do {
V_248 = F_52 ( V_155 ) ;
} while( ( V_248 & V_251 ) && V_249 -- );
F_62 ( V_247 , V_231 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short * V_252 ;
unsigned short V_253 , V_254 , V_255 ;
const struct V_256 * V_257 = NULL ;
if ( F_69 ( & V_257 , L_37 , V_4 -> V_71 ) != 0 ) {
F_12 ( V_258 L_38 ,
V_2 -> V_12 , L_37 ) ;
return - 1 ;
}
V_252 = ( unsigned short * ) V_257 -> V_18 ;
V_255 = V_257 -> V_259 / 2 ;
F_62 ( V_260 , V_123 ) ;
F_67 ( 40 ) ;
V_254 = F_52 ( V_123 ) ;
F_67 ( 20 ) ;
if( V_2 -> V_8 == 0 )
{
V_254 &= ~ ( V_261 | V_262 ) ;
if( V_4 -> V_263 )
V_254 |= (* V_4 -> V_263 )( V_2 ) ;
}
V_4 -> V_35 = 0 ;
V_254 &= ~ V_260 ;
V_254 |= V_264 ;
V_254 |= V_265 ;
V_254 |= V_124 ;
V_254 &= ~ V_266 ;
F_62 ( V_254 , V_123 ) ;
F_67 ( 40 ) ;
V_253 = 0 ;
do {
if ( V_255 < 3 ) continue;
F_62 ( * V_252 , V_267 ) ;
V_252 ++ ;
V_255 -- ;
F_62 ( * V_252 , V_268 ) ;
V_252 ++ ;
V_255 -- ;
if( ( V_253 = * V_252 ) != 0 )
{
V_252 ++ ;
V_255 -- ;
if ( V_253 > V_255 ) continue;
for(; V_253 > 0 ; V_253 -- )
{
F_62 ( * V_252 , V_269 ) ;
V_252 ++ ;
V_255 -- ;
}
}
else
{
V_254 = F_52 ( V_123 ) ;
V_254 &= ( ~ V_264 | V_124 ) ;
F_62 ( V_254 , V_123 ) ;
F_70 ( V_257 ) ;
return 1 ;
}
} while( V_253 == 0 );
F_70 ( V_257 ) ;
F_12 ( V_11 L_39 , V_2 -> V_12 ) ;
return - 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_270 , V_271 ;
unsigned short V_48 ;
F_67 ( V_272 ) ;
F_49 ( V_2 , V_273 ) ;
F_67 ( V_272 ) ;
V_271 = V_274 ;
do {
V_271 -- ;
if( V_25 > 3 )
F_12 ( V_19 L_40 ) ;
V_270 = V_275 ;
do {
V_270 -- ;
F_67 ( V_272 ) ;
V_48 = F_52 ( V_155 ) ;
V_48 &= V_276 ;
if( V_25 > 3 )
F_12 ( V_19 L_41 , V_48 ) ;
if( V_48 == V_277 )
return 1 ;
} while( ( V_270 > 0 ) && ( ( V_48 & ( V_278 | V_279 ) )
!= ( V_278 | V_279 ) ) );
if( V_271 > 0 )
{
F_12 ( V_11 L_42 ,
V_2 -> V_12 ) ;
F_49 ( V_2 , V_273 ) ;
F_67 ( V_272 ) ;
}
} while( V_271 > 0 );
V_48 = F_52 ( V_155 ) ;
F_12 ( V_11 L_43 , V_2 -> V_12 ) ;
V_48 &= 0x001f ;
if ( V_48 & 0x0010 )
F_12 ( V_11 L_44 , V_2 -> V_12 ) ;
else if ( ( V_48 & 0x000f ) > 6 )
F_12 ( V_11 L_45 , V_2 -> V_12 ) ;
else
F_12 ( V_11 L_46 , V_2 -> V_12 , V_48 & 0x000f ) ;
return - 1 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const unsigned char V_280 [ 6 ] = { 0x00 , 0x00 , 0xC1 , 0xE2 , 0xD4 , 0x8B } ;
const unsigned char V_281 [ 8 ] = { 0xFF , 0xFF , 0xD1 , 0xD7 ,
0xC5 , 0xD9 , 0xC3 , 0xD4 } ;
void * V_282 = ( void * ) & V_4 -> V_80 ;
unsigned short * V_283 = ( unsigned short * ) V_282 ;
unsigned char * V_284 = ( unsigned char * ) & V_4 -> V_28 ;
unsigned char * V_285 = ( unsigned char * ) & V_4 -> V_31 ;
unsigned short V_48 ;
int V_26 , V_270 , V_271 ;
V_4 -> V_80 . V_94 = F_71 ( ( ( char * ) & V_4 -> V_28 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_80 . V_95 = F_71 ( ( ( char * ) & V_4 -> V_31 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
if( V_25 > 3 )
{
F_12 ( V_19 L_47 , V_2 -> V_12 , ( long ) & V_4 -> V_28 ) ;
F_12 ( V_19 L_48 , V_2 -> V_12 , ( long ) ( ( char * ) & V_4 -> V_28 - ( char * ) V_4 ) + ( long ) V_4 -> V_47 ) ;
F_12 ( V_19 L_49 , V_2 -> V_12 , ( long ) V_4 -> V_47 ) ;
F_12 ( V_19 L_50 , V_2 -> V_12 , ( long ) V_4 ) ;
}
V_271 = V_286 ;
do {
V_271 -- ;
F_62 ( 0x0001 , V_267 ) ;
F_62 ( 0x0A00 , V_268 ) ;
for( V_26 = 0 ; V_26 < 11 ; V_26 ++ )
F_62 ( V_283 [ V_26 ] , V_269 ) ;
F_49 ( V_2 , V_287 ) ;
V_270 = V_288 ;
do {
V_48 = 0 ;
V_270 -- ;
F_67 ( V_272 ) ;
V_48 = F_52 ( V_155 ) ;
V_48 &= V_276 ;
} while( ( ( V_48 & ( V_277 | V_278 | V_279 ) ) != 0 ) &&
( ( V_48 & V_278 ) == 0 ) && ( V_270 != 0 ) );
if( ( V_48 & ( V_277 | V_278 | V_279 ) ) == 0 )
{
V_26 = 0 ;
do {
if( V_280 [ V_26 ] != * ( V_284 + V_26 ) )
{
F_12 ( V_11 L_51 , V_2 -> V_12 ) ;
return - 1 ;
}
V_26 ++ ;
} while( V_26 < 6 );
V_26 = 0 ;
do {
if( V_281 [ V_26 ] != * ( V_285 + V_26 ) )
return - 1 ;
V_26 ++ ;
} while ( V_26 < 8 );
return 1 ;
}
else
{
if( ( V_48 & V_278 ) != 0 )
{
V_48 = F_52 ( V_155 ) ;
V_48 &= V_289 ;
F_12 ( V_11 L_52 , V_2 -> V_12 , V_48 ) ;
return - 1 ;
}
else
{
if( V_271 > 0 )
{
F_49 ( V_2 , V_273 ) ;
F_67 ( V_272 ) ;
}
}
}
} while( V_271 > 0 );
F_12 ( V_11 L_53 , V_2 -> V_12 ) ;
return - 1 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_96 = 0 ;
if( V_4 -> V_33 == 0 )
return;
if( V_4 -> V_35 == 1 )
return;
if( V_4 -> V_34 == 0 )
{
if( V_4 -> V_33 & V_122 )
{
V_4 -> V_33 ^= V_122 ;
V_96 = F_28 ( ( ( char * ) & V_4 -> V_103 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_28 . V_30 [ 0 ] = F_33 ( V_96 ) ;
V_4 -> V_28 . V_30 [ 1 ] = F_34 ( V_96 ) ;
V_4 -> V_28 . V_29 = V_178 ;
}
else
return;
}
else
{
if( V_4 -> V_33 & V_150 )
{
V_4 -> V_33 ^= V_150 ;
V_4 -> V_34 = 0 ;
V_4 -> V_28 . V_30 [ 0 ] = 0 ;
V_4 -> V_28 . V_30 [ 1 ] = 0 ;
V_4 -> V_28 . V_29 = V_290 ;
if( ! V_4 -> V_38 )
V_4 -> V_33 |= V_122 ;
else
V_4 -> V_33 = 0 ;
}
else
{
if( V_4 -> V_33 & V_180 )
{
V_4 -> V_33 ^= V_180 ;
V_96 = F_28 ( ( ( char * ) V_4 -> V_78 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_28 . V_30 [ 0 ] = F_33 ( V_96 ) ;
V_4 -> V_28 . V_30 [ 1 ] = F_34 ( V_96 ) ;
V_4 -> V_28 . V_29 = V_291 ;
}
else
{
if( V_4 -> V_33 & V_292 )
{
V_4 -> V_33 ^= V_292 ;
V_4 -> V_28 . V_29 = V_293 ;
V_4 -> V_28 . V_30 [ 0 ] = 0 ;
V_4 -> V_28 . V_30 [ 1 ] = 0 ;
}
else
{
if( V_4 -> V_33 & V_162 )
{
if( V_4 -> V_161 )
{
if( ! V_4 -> V_39 )
{
V_4 -> V_39 = 1 ;
F_35 ( V_2 , V_292 ) ;
}
V_4 -> V_161 = 0 ;
return;
}
V_4 -> V_33 ^= V_162 ;
F_63 ( V_4 ) ;
V_96 = F_28 ( ( ( char * ) V_4 -> V_59 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_28 . V_30 [ 0 ] = F_33 ( V_96 ) ;
V_4 -> V_28 . V_30 [ 1 ] = F_34 ( V_96 ) ;
V_4 -> V_28 . V_29 = V_294 ;
V_4 -> V_161 = 1 ;
}
else
{
if( V_4 -> V_33 & V_245 )
{
V_4 -> V_33 ^= V_245 ;
V_4 -> V_28 . V_30 [ 0 ] = V_4 -> V_103 . V_104 ;
V_4 -> V_28 . V_30 [ 0 ] |= V_105 ;
V_4 -> V_28 . V_30 [ 1 ] = 0 ;
V_4 -> V_28 . V_29 = V_295 ;
}
else
{
if( V_4 -> V_33 & V_244 )
{
V_4 -> V_33 ^= V_244 ;
V_4 -> V_28 . V_30 [ 0 ] = F_33 ( V_4 -> V_103 . V_111 ) ;
V_4 -> V_28 . V_30 [ 1 ] = F_34 ( V_4 -> V_103 . V_111 ) ;
V_4 -> V_28 . V_29 = V_296 ;
}
else
{
if( V_4 -> V_33 & V_297 )
{
V_4 -> V_33 ^= V_297 ;
V_4 -> V_28 . V_30 [ 0 ] = F_33 ( V_4 -> V_103 . V_110 ) ;
V_4 -> V_28 . V_30 [ 1 ] = F_34 ( V_4 -> V_103 . V_110 ) ;
V_4 -> V_28 . V_29 = V_298 ;
}
else
{
if( V_4 -> V_33 & V_299 )
{
V_4 -> V_33 ^= V_299 ;
V_96 = F_28 ( ( ( char * ) & V_4 -> V_207 - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_4 -> V_28 . V_30 [ 0 ] = F_33 ( V_96 ) ;
V_4 -> V_28 . V_30 [ 1 ] = F_34 ( V_96 ) ;
V_4 -> V_28 . V_29 = V_204 ;
}
else
{
F_12 ( V_300 L_54 ) ;
V_4 -> V_33 = 0 ;
return;
}
}
}
}
}
}
}
}
}
V_4 -> V_35 = 1 ;
F_49 ( V_2 , V_287 | V_301 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_302 = F_72 ( ( unsigned short ) V_4 -> V_31 . V_30 [ 0 ] ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_303 )
{
F_12 ( V_11 L_55 , V_2 -> V_12 ) ;
V_4 -> V_205 . V_206 ++ ;
}
if( V_4 -> V_31 . V_30 [ 0 ] & V_304 )
{
F_12 ( V_11 L_56 ,
V_2 -> V_12 ) ;
V_4 -> V_205 . V_206 ++ ;
}
if( V_4 -> V_31 . V_30 [ 0 ] & V_305 )
F_12 ( V_11 L_57 , V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_306 )
{
F_12 ( V_11 L_58 , V_2 -> V_12 ) ;
F_35 ( V_2 , V_299 ) ;
}
if( V_4 -> V_31 . V_30 [ 0 ] & V_307 )
F_12 ( V_11 L_59 ,
V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_308 )
F_12 ( V_11 L_60 ,
V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_309 )
F_12 ( V_11 L_61 , V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_310 )
F_12 ( V_11 L_62 , V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_311 )
F_12 ( V_11 L_63 , V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_312 )
F_12 ( V_11 L_64 , V_2 -> V_12 ) ;
if( V_4 -> V_31 . V_30 [ 0 ] & V_313 )
{
F_12 ( V_11 L_65
L_66 ,
V_2 -> V_12 , V_4 -> V_302 ) ;
V_4 -> V_34 = 0 ;
F_16 ( V_2 ) ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
int V_26 ;
unsigned short V_314 [ 4 ] ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_34 = 0 ;
F_62 ( 0x0001 , V_267 ) ;
F_62 ( V_315 , V_316 ) ;
for( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
V_314 [ V_26 ] = F_52 ( V_269 ) ;
if( V_25 > 3 )
{
F_12 ( V_19 L_67 , V_2 -> V_12 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
F_12 ( L_68 , V_314 [ V_26 ] ) ;
F_12 ( L_69 ) ;
}
switch( V_314 [ 0 ] )
{
case V_317 :
F_12 ( V_11 L_70 , V_2 -> V_12 ) ;
break;
case V_318 :
F_12 ( V_11 L_71 ,
V_2 -> V_12 ) ;
switch ( V_314 [ 1 ] )
{
case 0 :
F_12 ( V_11 L_72 ) ;
F_12 ( V_11 L_73 ,
V_314 [ 2 ] ,
V_314 [ 3 ] ) ;
break;
case 1 :
F_12 ( V_11 L_74 ) ;
F_12 ( V_11 L_73 ,
V_314 [ 2 ] ,
V_314 [ 3 ] ) ;
break;
case 2 :
F_12 ( V_11 L_75 ) ;
F_12 ( V_11 L_73 ,
V_314 [ 2 ] ,
V_314 [ 3 ] ) ;
break;
default:
F_12 ( V_11 L_76 ) ;
break;
}
break;
case V_319 :
F_12 ( V_11 L_77 ,
V_2 -> V_12 ) ;
switch ( V_314 [ 1 ] )
{
case 0 :
F_12 ( V_11 L_72 ) ;
F_12 ( V_11 L_73 ,
V_314 [ 2 ] ,
V_314 [ 3 ] ) ;
break;
case 1 :
F_12 ( V_11 L_74 ) ;
F_12 ( V_11 L_73 ,
V_314 [ 2 ] ,
V_314 [ 3 ] ) ;
break;
case 2 :
F_12 ( V_11 L_75 ) ;
F_12 ( V_11 L_73 ,
V_314 [ 2 ] ,
V_314 [ 3 ] ) ;
break;
default:
F_12 ( V_11 L_76 ) ;
break;
}
break;
case V_320 :
F_12 ( V_11 L_78 ,
V_2 -> V_12 ) ;
break;
case V_321 :
F_12 ( V_11 L_79 ,
V_2 -> V_12 ) ;
break;
case V_322 :
F_12 ( V_11 L_80 , V_2 -> V_12 ) ;
break;
case V_323 :
F_12 ( V_11 L_81 , V_2 -> V_12 ) ;
break;
case V_324 :
F_12 ( V_11 L_82 ,
V_2 -> V_12 ) ;
break;
case V_325 :
F_12 ( V_11 L_83 ,
V_2 -> V_12 ) ;
break;
case V_326 :
F_12 ( V_11 L_84 ,
V_2 -> V_12 ) ;
break;
case V_327 :
F_12 ( V_11 L_85 ,
V_2 -> V_12 ) ;
break;
default:
F_12 ( V_11 L_86 , V_2 -> V_12 ) ;
break;
}
if( F_11 ( V_2 ) == 1 )
{
V_4 -> V_34 = 1 ;
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_328 ;
F_73 ( V_2 , ( unsigned char * ) & V_4 -> V_329 . V_330 ,
V_331 , 16 ) ;
F_73 ( V_2 , ( unsigned char * ) & V_328 ,
F_29 ( ( unsigned short ) V_4 -> V_329 . V_332 ) , 2 ) ;
return F_72 ( V_328 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned char * V_333 ,
unsigned short V_334 , int V_335 )
{
int V_26 ;
unsigned short V_336 , V_337 , V_338 ;
V_336 = F_52 ( V_267 ) ;
V_337 = F_52 ( V_316 ) ;
F_62 ( 0x0001 , V_267 ) ;
F_62 ( V_334 , V_316 ) ;
V_26 = 0 ;
for(; ; )
{
V_338 = F_52 ( V_269 ) ;
* ( V_333 + V_26 ) = F_74 ( V_338 ) ;
if( ++ V_26 == V_335 )
break;
* ( V_333 + V_26 ) = F_75 ( V_338 ) ;
if ( ++ V_26 == V_335 )
break;
}
F_62 ( V_336 , V_267 ) ;
F_62 ( V_337 , V_316 ) ;
}
static void F_63 ( struct V_3 * V_4 )
{
T_3 * V_130 ;
if( V_4 -> V_161 )
return;
for(; ; )
{
V_130 = V_4 -> V_59 ;
if( ! V_130 -> V_57 )
break;
V_4 -> V_59 = V_130 -> V_53 ;
F_48 ( V_130 , 0 ) ;
V_130 -> V_57 = 0 ;
F_12 ( V_11 L_87 , ( unsigned long ) V_130 ) ;
if ( V_130 -> V_56 )
F_45 ( V_4 -> V_71 , V_130 -> V_56 , V_130 -> V_67 -> V_135 , V_136 ) ;
F_76 ( V_130 -> V_67 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char V_339 , V_340 , V_341 ;
T_3 * V_130 ;
for(; ; )
{
V_130 = V_4 -> V_59 ;
if( ! V_130 -> V_57 || ( V_130 -> V_48
& ( V_139 | V_342 ) )
!= V_342 )
{
break;
}
V_4 -> V_59 = V_130 -> V_53 ;
if( F_77 ( V_130 ) && ( V_130 -> V_48 & V_343 ) == 0 )
{
V_339 = F_78 ( V_130 -> V_48 ) ;
V_340 = F_79 ( V_339 ) ;
V_341 = F_80 ( V_339 ) ;
if( ( V_340 != V_341 ) || ( V_340 == V_344 ) )
{
F_12 ( V_19 L_88 ,
V_2 -> V_12 ,
* ( unsigned long * ) & V_130 -> V_54 [ 2 + 2 ] ) ;
}
else
{
if( V_25 > 3 )
F_12 ( V_19 L_89 ,
V_2 -> V_12 ) ;
}
}
else
{
if( ! F_77 ( V_130 ) )
{
if( V_25 > 3 )
F_12 ( V_19 L_90 ,
V_2 -> V_12 ) ;
}
}
V_4 -> V_205 . V_345 ++ ;
if ( V_130 -> V_56 )
F_45 ( V_4 -> V_71 , V_130 -> V_56 , V_130 -> V_67 -> V_135 , V_136 ) ;
F_81 ( V_130 -> V_67 ) ;
V_130 -> V_57 = 0 ;
}
if( ! V_4 -> V_58 -> V_53 -> V_57 )
F_39 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char * V_346 ;
struct V_127 * V_128 ;
unsigned int V_335 , V_347 ;
T_6 * V_348 ;
T_6 * V_349 ;
T_1 V_27 ;
for(; ; )
{
V_348 = V_4 -> V_78 ;
if( V_348 -> V_48 & V_63 )
break;
V_349 = V_4 -> V_78 ;
V_4 -> V_78 = V_348 -> V_76 ;
V_335 = F_72 ( V_348 -> V_49 ) ;
if( ( V_348 -> V_48 & V_350 )
== V_350 )
{
V_346 = V_348 -> V_54 ;
V_347 = F_72 ( V_348 -> V_49 ) ;
if( V_335 == 0 || V_335 != V_347 )
{
V_4 -> V_78 = V_349 ;
break;
}
F_82 ( V_4 , V_346 , V_335 ) ;
if( V_25 > 3 )
F_12 ( V_19 L_91 ,
V_2 -> V_12 , V_335 , V_335 ) ;
V_128 = V_348 -> V_67 ;
if( V_348 -> V_68 == V_69 )
{
V_128 = F_30 ( V_4 -> V_42 ) ;
if( V_128 == NULL )
{
}
else
{
F_31 ( V_128 , V_4 -> V_42 ) ;
V_348 -> V_68 = V_74 ;
V_346 = V_348 -> V_54 ;
}
}
if( V_128 && ( V_348 -> V_68 == V_74 ||
V_348 -> V_68 == V_75 ) )
{
if( V_348 -> V_68 == V_74 )
F_83 ( V_128 , V_346 ,
V_335 ) ;
V_348 -> V_67 = NULL ;
F_84 ( V_128 , V_335 ) ;
V_128 -> V_351 = F_85 ( V_128 , V_2 ) ;
F_86 ( V_128 ) ;
}
}
else
{
if( V_348 -> V_67 != NULL )
F_81 ( V_348 -> V_67 ) ;
if( V_348 -> V_48 & V_64 )
V_4 -> V_205 . V_217 ++ ;
}
if ( V_348 -> V_56 )
F_45 ( V_4 -> V_71 , V_348 -> V_56 , V_4 -> V_42 , V_136 ) ;
V_348 -> V_56 = 0 ;
V_348 -> V_67 = F_30 ( V_4 -> V_42 ) ;
if( V_348 -> V_67 == NULL )
{
V_348 -> V_68 = V_69 ;
V_348 -> V_50 [ 0 ] . V_52 = F_28 ( ( ( char * ) V_4 -> V_70 [ V_348 -> V_77 ] - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_348 -> V_54 = V_4 -> V_70 [ V_348 -> V_77 ] ;
}
else
{
V_348 -> V_67 -> V_2 = V_2 ;
F_31 ( V_348 -> V_67 , V_4 -> V_42 ) ;
V_27 = F_32 ( V_4 -> V_71 , V_348 -> V_67 -> V_18 , V_4 -> V_42 , V_72 ) ;
if( V_4 -> V_73 && ( V_27 + V_4 -> V_42 > V_4 -> V_73 ) )
{
V_348 -> V_68 = V_74 ;
V_348 -> V_50 [ 0 ] . V_52 = F_28 ( ( ( char * ) V_4 -> V_70 [ V_348 -> V_77 ] - ( char * ) V_4 ) + V_4 -> V_47 ) ;
V_348 -> V_54 = V_4 -> V_70 [ V_348 -> V_77 ] ;
}
else
{
V_348 -> V_68 = V_75 ;
V_348 -> V_50 [ 0 ] . V_52 = F_28 ( V_27 ) ;
V_348 -> V_54 = V_348 -> V_67 -> V_18 ;
V_348 -> V_56 = V_27 ;
}
}
V_348 -> V_50 [ 0 ] . V_51 = F_29 ( ( unsigned short ) V_4 -> V_42 ) ;
V_348 -> V_49 = 0 ;
V_4 -> V_79 -> V_49 = 0 ;
F_87 ( V_4 -> V_79 , V_63 | V_66 ) ;
V_4 -> V_79 = V_4 -> V_79 -> V_76 ;
F_49 ( V_2 , V_352 ) ;
}
}
static void F_87 ( T_6 * V_348 , unsigned int V_48 )
{
V_348 -> V_48 = V_48 ;
}
static void F_82 ( struct V_3 * V_4 , unsigned char V_353 [] ,
unsigned int V_335 )
{
V_4 -> V_205 . V_354 ++ ;
V_4 -> V_205 . V_355 += V_335 ;
if( V_353 [ 2 ] & V_356 )
V_4 -> V_205 . V_357 ++ ;
}
static int F_88 ( struct V_1 * V_2 , void * V_243 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_358 * V_359 = V_243 ;
if ( V_4 -> V_34 || V_4 -> V_22 ) {
F_12 ( V_300 L_92 , V_2 -> V_12 ) ;
return - V_360 ;
}
memcpy ( V_2 -> V_109 , V_359 -> V_361 , V_2 -> V_362 ) ;
return 0 ;
}
static void F_89 ( unsigned char * V_333 , int V_131 )
{
int V_26 , V_363 ;
for ( V_26 = 0 , V_363 = 0 ; V_26 < V_131 / 8 ; V_26 ++ , V_363 += 8 )
{
F_12 ( V_19 L_93 ,
V_333 [ V_363 + 0 ] , V_333 [ V_363 + 1 ] , V_333 [ V_363 + 2 ] , V_333 [ V_363 + 3 ] ,
V_333 [ V_363 + 4 ] , V_333 [ V_363 + 5 ] , V_333 [ V_363 + 6 ] , V_333 [ V_363 + 7 ] ) ;
}
}
void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
F_45 ( V_4 -> V_71 , V_4 -> V_47 , sizeof( struct V_3 ) ,
V_364 ) ;
}
int F_91 ( struct V_1 * V_2 , struct V_365 * V_71 )
{
struct V_3 * V_366 ;
memset ( F_2 ( V_2 ) , 0 , sizeof( struct V_3 ) ) ;
V_366 = F_2 ( V_2 ) ;
F_92 ( & V_366 -> V_21 ) ;
if ( V_71 -> V_367 )
V_366 -> V_73 = * V_71 -> V_367 ;
else
return - V_368 ;
V_366 -> V_71 = V_71 ;
V_366 -> V_47 = F_32 ( V_71 , ( void * ) V_366 ,
sizeof( struct V_3 ) , V_364 ) ;
if ( V_366 -> V_47 + sizeof( struct V_3 ) >
V_366 -> V_73 )
{
F_12 ( V_11 L_94 ,
V_2 -> V_12 ) ;
F_90 ( V_2 ) ;
return - V_368 ;
}
V_2 -> V_369 = & V_370 ;
V_2 -> V_371 = V_15 ;
return 0 ;
}
int F_93 ( void )
{
F_12 ( V_19 L_95 , V_372 ) ;
V_373 = & V_374 ;
return 0 ;
}
void F_94 ( void )
{
V_373 = NULL ;
}
