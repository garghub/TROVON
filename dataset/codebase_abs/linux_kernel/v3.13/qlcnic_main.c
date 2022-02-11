static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_5 -> V_6 == V_7 )
return V_4 -> V_8 & V_9 ;
else
return 1 ;
}
inline void F_2 ( struct V_10 * V_11 )
{
F_3 ( V_11 -> V_12 , V_11 -> V_13 ) ;
}
int F_4 ( struct V_14 * V_15 , int V_16 )
{
int V_17 = sizeof( struct V_18 ) * V_16 ;
V_15 -> V_19 = F_5 ( V_17 , V_20 ) ;
return V_15 -> V_19 == NULL ;
}
void F_6 ( struct V_14 * V_15 )
{
if ( V_15 -> V_19 != NULL )
F_7 ( V_15 -> V_19 ) ;
V_15 -> V_19 = NULL ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
T_2 V_24 [ V_25 ] ;
int V_26 ;
V_26 = F_9 ( V_2 , V_24 ,
V_2 -> V_4 -> V_27 ) ;
if ( V_26 )
return V_26 ;
memcpy ( V_22 -> V_28 , V_24 , V_25 ) ;
memcpy ( V_2 -> V_24 , V_22 -> V_28 , V_22 -> V_29 ) ;
if ( ! F_10 ( V_22 -> V_28 ) )
F_11 ( & V_5 -> V_30 , L_1 ,
V_22 -> V_28 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
F_13 (head, &adapter->mac_list) {
V_32 = F_14 ( V_34 , struct V_31 , V_35 ) ;
if ( ! memcmp ( V_2 -> V_24 , V_32 -> V_24 , V_25 ) ) {
F_15 ( V_2 , V_32 -> V_24 ,
0 , V_36 ) ;
F_16 ( & V_32 -> V_35 ) ;
F_7 ( V_32 ) ;
return;
}
}
}
static int F_17 ( struct V_21 * V_22 , void * V_37 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_38 * V_39 = V_37 ;
if ( F_19 ( V_2 ) )
return - V_40 ;
if ( ( V_2 -> V_41 & V_42 ) )
return - V_43 ;
if ( ! F_10 ( V_39 -> V_44 ) )
return - V_40 ;
if ( ! memcmp ( V_2 -> V_24 , V_39 -> V_44 , V_25 ) )
return 0 ;
if ( F_20 ( V_45 , & V_2 -> V_46 ) ) {
F_21 ( V_22 ) ;
F_22 ( V_2 ) ;
}
F_12 ( V_2 ) ;
memcpy ( V_2 -> V_24 , V_39 -> V_44 , V_22 -> V_29 ) ;
memcpy ( V_22 -> V_28 , V_39 -> V_44 , V_22 -> V_29 ) ;
F_23 ( V_2 -> V_22 ) ;
if ( F_20 ( V_45 , & V_2 -> V_46 ) ) {
F_24 ( V_22 ) ;
F_25 ( V_2 ) ;
}
return 0 ;
}
static int F_26 ( struct V_47 * V_48 , struct V_49 * V_50 [] ,
struct V_21 * V_22 , const unsigned char * V_39 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 = - V_43 ;
if ( ! V_2 -> V_52 )
return F_27 ( V_48 , V_50 , V_22 , V_39 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( F_28 ( V_39 ) ) {
V_51 = F_29 ( V_22 , V_39 ) ;
if ( ! V_51 )
V_51 = F_30 ( V_2 , V_39 ) ;
} else if ( F_31 ( V_39 ) ) {
V_51 = F_32 ( V_22 , V_39 ) ;
} else {
V_51 = - V_40 ;
}
}
return V_51 ;
}
static int F_33 ( struct V_47 * V_48 , struct V_49 * V_50 [] ,
struct V_21 * V_22 ,
const unsigned char * V_39 , T_3 V_41 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 = 0 ;
if ( ! V_2 -> V_52 )
return F_34 ( V_48 , V_50 , V_22 , V_39 , V_41 ) ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
F_35 ( L_2 , V_54 ) ;
return - V_43 ;
}
if ( F_36 ( V_39 , V_2 -> V_24 ) )
return V_51 ;
if ( F_28 ( V_39 ) ) {
if ( F_37 ( V_22 ) < V_2 -> V_4 -> V_55 )
V_51 = F_38 ( V_22 , V_39 ) ;
else
V_51 = - V_56 ;
} else if ( F_31 ( V_39 ) ) {
V_51 = F_39 ( V_22 , V_39 ) ;
} else {
V_51 = - V_40 ;
}
return V_51 ;
}
static int F_40 ( struct V_57 * V_58 , struct V_59 * V_60 ,
struct V_21 * V_22 , int V_61 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
if ( ! V_2 -> V_52 )
return F_41 ( V_58 , V_60 , V_22 , V_61 ) ;
if ( V_2 -> V_41 & V_53 )
V_61 = F_41 ( V_58 , V_60 , V_22 , V_61 ) ;
return V_61 ;
}
static void F_42 ( struct V_1 * V_2 )
{
while ( F_43 ( V_62 , & V_2 -> V_46 ) )
F_44 ( 10000 , 11000 ) ;
if ( ! V_2 -> V_63 . V_64 . V_65 )
return;
F_45 ( & V_2 -> V_63 ) ;
}
static int F_46 ( struct V_21 * V_22 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! ( V_2 -> V_41 & V_68 ) )
return - V_43 ;
V_67 -> V_69 = sizeof( V_4 -> V_70 ) ;
memcpy ( V_67 -> V_71 , V_4 -> V_70 , V_67 -> V_69 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_48 ( V_2 ) &&
( V_4 -> V_72 [ 0 ] & V_73 ) ) {
F_43 ( V_74 , & V_2 -> V_46 ) ;
return 0 ;
} else {
return 1 ;
}
}
static int F_49 ( struct V_1 * V_2 , T_2 V_75 ,
int V_76 )
{
int V_77 , V_78 = V_79 ;
if ( V_76 == V_80 )
V_78 = V_2 -> V_81 ;
else if ( V_76 == V_82 )
V_78 = V_2 -> V_83 ;
V_77 = F_50 ( F_51 ( int , F_52 () ,
V_78 ) ) ;
if ( V_75 > V_77 )
return V_77 ;
else
return V_75 ;
}
void F_53 ( struct V_1 * V_2 , T_2 V_84 )
{
if ( V_2 -> V_83 )
V_2 -> V_85 = F_49 ( V_2 , V_84 ,
V_82 ) ;
else
V_2 -> V_85 = V_84 ;
F_54 ( & V_2 -> V_5 -> V_30 , L_3 ,
V_2 -> V_85 ) ;
}
void F_55 ( struct V_1 * V_2 , T_2 V_86 )
{
if ( V_2 -> V_81 )
V_2 -> V_87 = F_49 ( V_2 , V_86 ,
V_80 ) ;
else
V_2 -> V_87 = V_86 ;
F_54 ( & V_2 -> V_5 -> V_30 , L_4 ,
V_2 -> V_87 ) ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_88 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_85 , V_87 , V_89 ;
int V_51 = - 1 , V_90 ;
if ( V_2 -> V_41 & V_91 ) {
V_85 = 0 ;
V_89 = 0 ;
} else {
V_85 = V_2 -> V_85 ;
V_89 = 1 ;
}
if ( ! V_2 -> V_92 ) {
V_2 -> V_92 = F_57 ( V_88 ,
sizeof( struct V_93 ) ,
V_20 ) ;
if ( ! V_2 -> V_92 )
return - V_56 ;
}
V_2 -> V_87 = V_94 ;
V_2 -> V_41 &= ~ ( V_95 | V_96 ) ;
if ( V_2 -> V_4 -> V_97 ) {
V_98:
for ( V_90 = 0 ; V_90 < V_88 ; V_90 ++ )
V_2 -> V_92 [ V_90 ] . V_99 = V_90 ;
V_51 = F_58 ( V_5 , V_2 -> V_92 , V_88 ) ;
if ( V_51 == 0 ) {
V_2 -> V_41 |= V_96 ;
if ( F_59 ( V_2 ) ) {
V_2 -> V_4 -> V_88 = V_88 ;
V_2 -> V_87 = V_88 -
V_85 - 1 ;
} else {
V_2 -> V_4 -> V_88 = V_88 ;
if ( F_60 ( V_2 ) &&
! V_2 -> V_4 -> V_100 &&
( V_2 -> V_85 > 1 ) )
V_87 = V_88 - V_85 ;
else
V_87 = V_88 ;
V_2 -> V_87 = V_87 ;
}
F_54 ( & V_5 -> V_30 , L_5 ) ;
return V_51 ;
} else if ( V_51 > 0 ) {
F_54 ( & V_5 -> V_30 ,
L_6 ,
V_88 ) ;
if ( F_59 ( V_2 ) ) {
if ( V_51 < ( V_101 - V_89 ) )
return V_51 ;
V_51 -= V_85 + 1 ;
V_88 = F_50 ( V_51 ) ;
V_88 += V_85 + 1 ;
} else {
V_88 = F_50 ( V_51 ) ;
if ( F_60 ( V_2 ) )
V_88 += V_85 ;
}
if ( V_88 ) {
F_54 ( & V_5 -> V_30 ,
L_7 ,
V_88 ) ;
goto V_98;
}
} else {
F_54 ( & V_5 -> V_30 ,
L_6 ,
V_88 ) ;
}
}
return V_51 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_102 , V_103 ;
const struct V_104 * V_105 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_106 && ! F_62 ( V_5 ) ) {
V_2 -> V_41 |= V_95 ;
V_102 = V_107 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_108 = F_63 ( V_2 -> V_4 ,
V_102 ) ;
F_54 ( & V_5 -> V_30 , L_8 ) ;
V_2 -> V_92 [ 0 ] . V_109 = V_5 -> V_110 ;
return V_51 ;
}
if ( V_106 || V_111 )
return - V_43 ;
V_105 = & V_112 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_113 = V_105 -> V_113 ;
V_102 = V_105 -> V_108 ;
V_2 -> V_108 = F_63 ( V_4 , V_102 ) ;
V_103 = V_105 -> V_114 ;
V_2 -> V_114 = F_63 ( V_4 , V_103 ) ;
V_2 -> V_115 = F_63 ( V_4 , V_116 ) ;
V_2 -> V_117 = F_63 ( V_4 , V_118 ) ;
F_54 ( & V_5 -> V_30 , L_9 ) ;
V_2 -> V_92 [ 0 ] . V_109 = V_5 -> V_110 ;
return V_51 ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_88 , V_51 = 0 ;
V_88 = V_2 -> V_87 ;
if ( F_60 ( V_2 ) )
V_88 += V_2 -> V_85 ;
V_51 = F_56 ( V_2 , V_88 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_96 ) ) {
F_65 ( V_2 ) ;
V_51 = F_61 ( V_2 ) ;
if ( ! V_51 )
return V_51 ;
}
return 0 ;
}
int F_66 ( struct V_1 * V_2 , int V_119 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_90 ;
if ( F_60 ( V_2 ) &&
! V_4 -> V_100 &&
( V_2 -> V_41 & V_96 ) ) {
V_4 -> V_120 = F_67 ( V_4 -> V_88 *
sizeof( struct V_121 ) ) ;
if ( ! V_4 -> V_120 )
return - V_56 ;
for ( V_90 = 0 ; V_90 < V_4 -> V_88 ; V_90 ++ ) {
V_4 -> V_120 [ V_90 ] . type = V_122 ;
V_4 -> V_120 [ V_90 ] . V_71 = V_90 ;
V_4 -> V_120 [ V_90 ] . V_123 = 0 ;
}
V_51 = F_68 ( V_2 , 1 ) ;
if ( V_51 )
F_69 ( & V_2 -> V_5 -> V_30 ,
L_10 ,
V_4 -> V_88 ) ;
return V_51 ;
}
return 0 ;
}
void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_96 )
F_71 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_95 )
F_72 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_92 ) ;
V_2 -> V_92 = NULL ;
if ( V_2 -> V_4 -> V_120 ) {
F_73 ( V_2 -> V_4 -> V_120 ) ;
V_2 -> V_4 -> V_120 = NULL ;
}
}
static void F_74 ( struct V_3 * V_4 )
{
if ( V_4 -> V_124 != NULL )
F_75 ( V_4 -> V_124 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
switch ( V_2 -> V_4 -> V_127 ) {
case V_128 :
V_2 -> V_4 -> V_129 = V_130 ;
break;
case V_131 :
V_2 -> V_4 -> V_129 = V_132 ;
break;
}
return 0 ;
}
if ( V_2 -> V_4 -> V_133 == V_134 )
return 0 ;
V_126 = F_57 ( V_135 , sizeof( * V_126 ) , V_20 ) ;
if ( ! V_126 )
return - V_56 ;
V_26 = F_77 ( V_2 , V_126 ) ;
F_7 ( V_126 ) ;
return V_26 ;
}
static bool F_78 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_79 ( V_2 ) ) {
V_26 = true ;
} else if ( F_59 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_72 [ 0 ] &
V_136 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
int V_90 , V_71 = 0 , V_26 = 0 , V_137 = 0 ;
T_3 V_129 ;
T_2 V_138 ;
V_126 = F_57 ( V_135 , sizeof( * V_126 ) , V_20 ) ;
if ( ! V_126 )
return - V_56 ;
V_26 = F_77 ( V_2 , V_126 ) ;
if ( V_26 )
goto V_139;
V_129 = V_2 -> V_4 -> V_129 ;
V_2 -> V_140 = F_5 ( sizeof( struct V_141 ) *
V_129 , V_20 ) ;
if ( ! V_2 -> V_140 ) {
V_26 = - V_56 ;
goto V_139;
}
V_2 -> V_142 = F_5 ( sizeof( struct V_143 ) *
V_132 , V_20 ) ;
if ( ! V_2 -> V_142 ) {
V_26 = - V_56 ;
goto V_144;
}
for ( V_90 = 0 ; V_90 < V_135 ; V_90 ++ ) {
V_138 = V_126 [ V_90 ] . V_71 ;
if ( V_138 >= V_135 ) {
V_26 = V_145 ;
goto V_146;
}
if ( ! V_126 [ V_90 ] . V_147 ||
( V_126 [ V_90 ] . type != V_148 ) )
continue;
if ( F_78 ( V_2 ) ) {
if ( ! F_81 ( V_2 , V_138 ,
& V_71 ) )
V_2 -> V_140 [ V_137 ] . V_149 = true ;
else
continue;
} else {
V_2 -> V_140 [ V_137 ] . V_149 = true ;
}
V_2 -> V_140 [ V_137 ] . V_27 = V_138 ;
V_2 -> V_140 [ V_137 ] . V_147 = ( T_2 ) V_126 [ V_90 ] . V_147 ;
V_2 -> V_140 [ V_137 ] . type = ( T_2 ) V_126 [ V_90 ] . type ;
V_2 -> V_140 [ V_137 ] . V_150 = ( T_2 ) V_126 [ V_90 ] . V_151 ;
V_2 -> V_140 [ V_137 ] . V_152 = V_126 [ V_90 ] . V_153 ;
V_2 -> V_140 [ V_137 ] . V_154 = V_126 [ V_90 ] . V_155 ;
memcpy ( & V_2 -> V_140 [ V_137 ] . V_156 , & V_126 [ V_90 ] . V_156 , V_25 ) ;
V_137 ++ ;
}
if ( ! F_78 ( V_2 ) ) {
for ( V_90 = 0 ; V_90 < V_132 ; V_90 ++ )
V_2 -> V_142 [ V_90 ] . V_41 |= V_157 ;
}
F_7 ( V_126 ) ;
return 0 ;
V_146:
F_7 ( V_2 -> V_142 ) ;
V_2 -> V_142 = NULL ;
V_144:
F_7 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
V_139:
F_7 ( V_126 ) ;
return V_26 ;
}
static int
F_82 ( struct V_1 * V_2 )
{
T_2 V_71 ;
int V_26 ;
T_1 V_158 = V_134 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_83 ( V_2 ) ;
if ( V_26 )
goto V_159;
V_71 = V_4 -> V_27 ;
V_158 = F_84 ( V_2 , V_160 ) ;
V_158 = ( V_158 & ~ F_85 ( 0xf , V_71 ) ) |
F_85 ( V_134 , V_71 ) ;
F_86 ( V_2 , V_160 , V_158 ) ;
F_87 ( V_2 ) ;
V_159:
return V_26 ;
}
static void F_88 ( struct V_1 * V_2 ,
const struct V_161 * V_162 )
{
T_1 V_133 , V_163 ;
V_2 -> V_4 -> V_164 = F_84 ( V_2 ,
V_165 ) ;
F_89 ( V_2 ) ;
V_133 = F_84 ( V_2 , V_160 ) ;
if ( V_133 == V_166 )
V_163 = V_134 ;
else
V_163 = F_90 ( V_133 , V_2 -> V_4 -> V_27 ) ;
if ( V_163 == V_167 ) {
V_2 -> V_4 -> V_133 = V_167 ;
F_54 ( & V_2 -> V_5 -> V_30 ,
L_11 ,
V_2 -> V_4 -> V_164 ) ;
V_2 -> V_168 = & V_169 ;
} else
V_2 -> V_168 = & V_170 ;
}
static void F_91 ( T_1 V_171 , T_4 * V_172 )
{
switch ( V_171 ) {
case V_7 :
* V_172 = V_173 ;
break;
case V_174 :
case V_175 :
case V_176 :
case V_177 :
* V_172 = V_178 ;
break;
default:
* V_172 = 0 ;
}
}
static int F_92 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_102 ;
void T_5 * V_179 = NULL ;
unsigned long V_180 , V_181 = 0 , V_182 ;
V_180 = F_93 ( V_5 , 0 ) ;
F_91 ( V_5 -> V_6 , & V_182 ) ;
if ( V_180 >= V_182 ) {
V_179 = F_94 ( V_5 , 0 ) ;
if ( V_179 == NULL ) {
F_69 ( & V_5 -> V_30 , L_12 ) ;
return - V_183 ;
}
V_181 = V_180 ;
} else {
return - V_183 ;
}
F_54 ( & V_5 -> V_30 , L_13 , ( int ) ( V_180 >> 10 ) ) ;
V_4 -> V_124 = V_179 ;
V_4 -> V_181 = V_181 ;
V_102 = F_95 ( F_96 ( V_4 -> V_27 ) ) ;
F_63 ( V_4 , V_102 ) ;
return 0 ;
}
static bool F_97 ( struct V_1 * V_2 ,
int V_184 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_185 ;
bool V_26 = true ;
V_185 = V_5 -> V_185 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_174 ) {
if ( V_186 [ V_184 ] . V_187 == V_185 &&
V_186 [ V_184 ] . V_188 == V_5 -> V_189 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_98 ( struct V_1 * V_2 , char * V_190 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_90 , V_191 = 0 ;
for ( V_90 = 0 ; V_90 < V_192 ; ++ V_90 ) {
if ( V_186 [ V_90 ] . V_193 == V_5 -> V_193 &&
V_186 [ V_90 ] . V_6 == V_5 -> V_6 &&
F_97 ( V_2 , V_90 ) ) {
V_191 = 1 ;
break;
}
}
if ( ! V_191 )
sprintf ( V_190 , L_14 , V_2 -> V_24 ) ;
else
sprintf ( V_190 , L_15 , V_2 -> V_24 ,
V_186 [ V_90 ] . V_194 ) ;
}
static void
F_99 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_195 , V_196 , V_197 , V_198 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_199 * V_200 = & V_4 -> V_200 ;
V_198 = V_2 -> V_201 ;
V_195 = F_84 ( V_2 , V_202 ) ;
V_196 = F_84 ( V_2 , V_203 ) ;
V_197 = F_84 ( V_2 , V_204 ) ;
V_2 -> V_201 = F_100 ( V_195 , V_196 , V_197 ) ;
V_51 = F_101 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_16 ) ;
return;
}
if ( V_4 -> V_133 != V_167 ) {
if ( V_200 -> V_205 == NULL ||
V_2 -> V_201 > V_198 ) {
if ( V_200 -> V_205 )
F_73 ( V_200 -> V_205 ) ;
if ( ! F_102 ( V_2 ) )
F_54 ( & V_5 -> V_30 ,
L_17 ) ;
}
}
F_54 ( & V_5 -> V_30 , L_18 ,
V_206 , V_195 , V_196 , V_197 ) ;
if ( V_2 -> V_4 -> V_127 == V_131 ) {
if ( V_2 -> V_41 & V_53 ) {
V_2 -> V_207 = V_208 ;
V_2 -> V_209 = V_210 ;
} else {
V_2 -> V_207 = V_211 ;
V_2 -> V_209 = V_212 ;
}
V_2 -> V_213 = V_214 ;
V_2 -> V_215 = V_214 ;
} else if ( V_2 -> V_4 -> V_127 == V_128 ) {
V_2 -> V_207 = V_216 ;
V_2 -> V_213 = V_217 ;
V_2 -> V_215 = V_217 ;
V_2 -> V_209 = V_218 ;
}
V_2 -> V_4 -> V_97 = ! ! V_111 ;
V_2 -> V_219 = V_220 ;
V_2 -> V_221 = V_222 ;
}
static int
F_103 ( struct V_1 * V_2 )
{
struct V_223 V_224 ;
int V_51 = 0 ;
memset ( & V_224 , 0 , sizeof( struct V_223 ) ) ;
V_51 = F_104 ( V_2 , & V_224 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_225 = ( T_2 ) V_224 . V_226 ;
V_2 -> V_4 -> V_227 = V_224 . V_227 ;
V_2 -> V_4 -> V_228 = V_224 . V_228 ;
V_2 -> V_4 -> V_229 = V_224 . V_229 ;
V_2 -> V_4 -> V_8 = V_224 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_230 ) {
T_1 V_231 ;
V_231 = F_105 ( V_2 , V_232 , & V_51 ) ;
if ( V_51 == - V_183 )
return V_51 ;
V_2 -> V_4 -> V_72 [ 0 ] = V_231 ;
} else {
V_2 -> V_4 -> V_72 [ 0 ] = 0 ;
}
V_2 -> V_4 -> V_233 = V_224 . V_233 ;
V_2 -> V_4 -> V_234 = V_224 . V_234 ;
if ( V_2 -> V_4 -> V_8 & V_235 ) {
V_2 -> V_41 |= V_53 ;
V_2 -> V_4 -> V_236 = V_237 ;
V_2 -> V_83 = V_238 ;
V_2 -> V_81 = V_239 ;
F_54 ( & V_2 -> V_5 -> V_30 , L_19 ) ;
} else {
V_2 -> V_4 -> V_236 = V_240 ;
V_2 -> V_83 = V_241 ;
V_2 -> V_81 = V_79 ;
V_2 -> V_41 &= ~ V_53 ;
}
return V_51 ;
}
void F_106 ( struct V_1 * V_2 ,
struct V_242 * V_243 )
{
if ( V_243 -> V_244 )
V_2 -> V_41 &= ~ V_245 ;
else
V_2 -> V_41 |= V_245 ;
if ( V_243 -> V_246 ) {
V_2 -> V_247 = V_243 -> V_246 ;
V_2 -> V_248 = V_243 -> V_246 ;
} else {
V_2 -> V_247 = 0 ;
V_2 -> V_248 = 0 ;
}
}
static int
F_107 ( struct V_21 * V_22 , T_6 V_249 , T_3 V_250 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 ;
if ( F_19 ( V_2 ) ) {
V_51 = F_108 ( V_2 , V_250 , 1 ) ;
if ( V_51 ) {
F_109 ( V_22 ,
L_20 ,
V_250 , V_51 ) ;
return V_51 ;
}
}
F_110 ( V_250 , V_2 -> V_251 ) ;
return 0 ;
}
static int
F_111 ( struct V_21 * V_22 , T_6 V_249 , T_3 V_250 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 ;
if ( F_19 ( V_2 ) ) {
V_51 = F_108 ( V_2 , V_250 , 0 ) ;
if ( V_51 ) {
F_109 ( V_22 ,
L_21 ,
V_250 , V_51 ) ;
return V_51 ;
}
}
F_112 ( V_22 , V_252 ) ;
F_113 ( V_250 , V_2 -> V_251 ) ;
return 0 ;
}
void F_114 ( struct V_1 * V_2 ,
struct V_242 * V_243 )
{
V_2 -> V_41 &= ~ ( V_253 | V_42 |
V_254 ) ;
if ( V_243 -> V_255 )
V_2 -> V_41 |= V_253 ;
if ( ! V_243 -> V_256 )
V_2 -> V_41 |= V_42 ;
if ( ! V_243 -> V_257 )
V_2 -> V_41 |= V_254 ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_242 V_243 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_243 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_116 ( V_2 , & V_243 ) )
return - V_183 ;
F_106 ( V_2 , & V_243 ) ;
F_114 ( V_2 , & V_243 ) ;
F_117 ( V_2 , & V_243 ) ;
return 0 ;
}
void F_117 ( struct V_1 * V_2 ,
struct V_242 * V_243 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_59 ( V_2 ) )
return;
V_2 -> V_258 = V_243 -> V_258 ;
V_2 -> V_41 |= V_259 ;
F_118 ( V_22 ) ;
V_2 -> V_41 &= ~ V_259 ;
}
static int
F_119 ( struct V_1 * V_2 )
{
T_1 V_133 , V_163 ;
int V_51 = 0 ;
V_51 = F_103 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_260 )
return 0 ;
V_133 = F_84 ( V_2 , V_160 ) ;
V_163 = F_90 ( V_133 , V_2 -> V_4 -> V_27 ) ;
if ( V_133 == V_166 )
V_163 = V_134 ;
else
V_163 = F_90 ( V_133 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_163 == V_134 ) {
V_2 -> V_4 -> V_133 = V_134 ;
V_51 = F_80 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_82 ( V_2 ) ;
F_54 ( & V_2 -> V_5 -> V_30 ,
L_22 ,
V_2 -> V_4 -> V_164 ) ;
} else if ( V_163 == V_261 ) {
V_2 -> V_4 -> V_133 = V_261 ;
F_54 ( & V_2 -> V_5 -> V_30 ,
L_23 ,
V_2 -> V_4 -> V_164 ) ;
}
} else {
V_2 -> V_4 -> V_236 = V_240 ;
}
V_2 -> V_41 |= V_260 ;
return V_51 ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_242 V_243 ;
struct V_141 * V_262 ;
T_2 V_90 ;
if ( V_2 -> V_263 )
return 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_4 -> V_129 ; V_90 ++ ) {
if ( ! V_2 -> V_140 [ V_90 ] . V_149 )
continue;
memset ( & V_243 , 0 , sizeof( struct V_242 ) ) ;
V_243 . V_27 = V_2 -> V_140 [ V_90 ] . V_27 ;
V_243 . V_256 = V_264 ;
V_243 . V_257 = V_264 ;
if ( F_48 ( V_2 ) ) {
V_243 . V_258 = V_264 ;
if ( F_121 ( V_2 ) )
V_243 . V_258 |= ( V_265 | V_266 ) ;
}
if ( F_122 ( V_2 , & V_243 ) )
return - V_183 ;
V_262 = & V_2 -> V_140 [ V_90 ] ;
V_262 -> V_267 = V_243 . V_246 ;
V_262 -> V_256 = V_243 . V_256 ;
V_262 -> V_255 = V_243 . V_255 ;
V_262 -> V_244 = V_243 . V_244 ;
V_262 -> V_257 = V_243 . V_257 ;
V_262 -> V_258 = V_243 . V_258 ;
}
return 0 ;
}
static int
F_123 ( struct V_1 * V_2 ,
struct V_141 * V_262 , int V_27 )
{
struct V_242 V_243 ;
V_243 . V_133 = V_268 ;
V_243 . V_27 = V_27 ;
V_243 . V_246 = V_262 -> V_267 ;
V_243 . V_256 = V_262 -> V_256 ;
V_243 . V_244 = V_262 -> V_244 ;
V_243 . V_255 = V_262 -> V_255 ;
V_243 . V_258 = V_262 -> V_258 ;
V_243 . V_257 = V_262 -> V_257 ;
if ( F_122 ( V_2 , & V_243 ) )
return - V_183 ;
V_243 . V_133 = V_269 ;
if ( F_122 ( V_2 , & V_243 ) )
return - V_183 ;
return 0 ;
}
int F_124 ( struct V_1 * V_2 )
{
int V_90 , V_51 ;
struct V_141 * V_262 ;
struct V_223 V_224 ;
T_2 V_27 ;
if ( F_48 ( V_2 ) )
if ( ! V_2 -> V_263 )
return 0 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_4 -> V_129 ; V_90 ++ ) {
V_262 = & V_2 -> V_140 [ V_90 ] ;
V_27 = V_262 -> V_27 ;
if ( ! V_2 -> V_140 [ V_90 ] . V_149 )
continue;
memset ( & V_224 , 0 , sizeof( struct V_223 ) ) ;
V_51 = F_104 ( V_2 , & V_224 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_224 . V_270 = V_262 -> V_152 ;
V_224 . V_271 = V_262 -> V_154 ;
V_51 = F_125 ( V_2 , & V_224 ) ;
if ( V_51 )
return V_51 ;
if ( V_262 -> V_272 ) {
V_51 = F_126 ( V_2 ,
V_262 -> V_273 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_123 ( V_2 , V_262 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
T_2 V_274 = V_275 ;
T_1 V_276 ;
if ( V_2 -> V_4 -> V_133 == V_134 )
return 0 ;
V_276 = F_84 ( V_2 ,
V_277 ) ;
while ( V_276 != V_278 && -- V_274 ) {
F_128 ( 1000 ) ;
V_276 = F_84 ( V_2 ,
V_277 ) ;
}
if ( ! V_274 ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_24 ) ;
return - V_183 ;
}
return 0 ;
}
static int
F_129 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_133 != V_134 )
return 0 ;
V_51 = F_120 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_124 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_130 ( V_2 ) ;
return V_51 ;
}
int F_131 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_132 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
else if ( ! V_51 )
goto V_279;
if ( V_280 )
F_133 ( V_2 ) ;
else {
V_51 = F_134 ( V_2 ) ;
if ( V_51 )
goto V_281;
V_2 -> V_4 -> V_282 = V_283 ;
}
V_51 = F_135 ( V_2 ) ;
if ( V_51 == 0 )
goto V_279;
V_51 = F_136 ( V_2 ) ;
if ( V_51 )
goto V_281;
V_51 = F_137 ( V_2 ) ;
if ( V_51 )
goto V_281;
F_138 ( V_2 ) ;
F_139 ( V_2 , V_284 , V_285 ) ;
V_279:
V_51 = F_140 ( V_2 ) ;
if ( V_51 )
goto V_281;
F_86 ( V_2 , V_286 , V_287 ) ;
F_141 ( V_2 , 1 ) ;
V_51 = F_119 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_25 ) ;
goto V_281;
}
V_51 = F_129 ( V_2 ) ;
if ( V_51 )
goto V_281;
F_99 ( V_2 ) ;
V_2 -> V_263 = 0 ;
F_138 ( V_2 ) ;
return 0 ;
V_281:
F_86 ( V_2 , V_286 , V_288 ) ;
F_69 ( & V_2 -> V_5 -> V_30 , L_26 ) ;
F_138 ( V_2 ) ;
return V_51 ;
}
static int
F_142 ( struct V_1 * V_2 )
{
T_7 V_289 ;
struct V_18 * V_290 ;
struct V_10 * V_11 ;
int V_51 , V_291 , V_292 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_100 == V_293 ) {
if ( F_48 ( V_2 ) )
V_289 = V_294 ;
else
V_289 = V_295 ;
if ( ! F_143 ( V_2 ) )
V_41 |= V_296 ;
} else {
if ( V_2 -> V_41 & V_96 )
V_289 = V_297 ;
else if ( V_2 -> V_41 & V_95 )
V_289 = V_298 ;
else {
V_41 |= V_296 ;
if ( F_48 ( V_2 ) )
V_289 = V_299 ;
else
V_289 = V_300 ;
}
}
V_2 -> V_110 = V_22 -> V_110 ;
if ( V_2 -> V_4 -> V_100 != V_301 ) {
if ( F_48 ( V_2 ) ||
( F_59 ( V_2 ) &&
( V_2 -> V_41 & V_96 ) ) ) {
V_292 = V_2 -> V_87 ;
for ( V_291 = 0 ; V_291 < V_292 ; V_291 ++ ) {
V_290 = & V_15 -> V_19 [ V_291 ] ;
if ( F_48 ( V_2 ) &&
! F_60 ( V_2 ) &&
( V_291 == ( V_292 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_96 ) )
snprintf ( V_290 -> V_190 ,
sizeof( V_290 -> V_190 ) ,
L_27 ) ;
else
snprintf ( V_290 -> V_190 ,
sizeof( V_290 -> V_190 ) ,
L_28 ,
V_22 -> V_190 , V_291 ) ;
} else {
snprintf ( V_290 -> V_190 ,
sizeof( V_290 -> V_190 ) ,
L_29 ,
V_22 -> V_190 , V_291 ) ;
}
V_51 = F_144 ( V_290 -> V_110 , V_289 , V_41 ,
V_290 -> V_190 , V_290 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_48 ( V_2 ) &&
F_60 ( V_2 ) ) ||
( F_59 ( V_2 ) &&
( V_2 -> V_41 & V_96 ) &&
! ( V_2 -> V_41 & V_91 ) ) ) {
V_289 = V_302 ;
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ;
V_291 ++ ) {
V_11 = & V_2 -> V_11 [ V_291 ] ;
snprintf ( V_11 -> V_190 , sizeof( V_11 -> V_190 ) ,
L_30 , V_22 -> V_190 , V_291 ) ;
V_51 = F_144 ( V_11 -> V_110 , V_289 , V_41 ,
V_11 -> V_190 , V_11 ) ;
if ( V_51 )
return V_51 ;
}
}
}
return 0 ;
}
static void
F_145 ( struct V_1 * V_2 )
{
int V_291 ;
struct V_18 * V_290 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_100 != V_301 ) {
if ( F_48 ( V_2 ) ||
( F_59 ( V_2 ) &&
( V_2 -> V_41 & V_96 ) ) ) {
for ( V_291 = 0 ; V_291 < V_2 -> V_87 ; V_291 ++ ) {
V_290 = & V_15 -> V_19 [ V_291 ] ;
F_146 ( V_290 -> V_110 , V_290 ) ;
}
}
if ( ( F_59 ( V_2 ) &&
! ( V_2 -> V_41 & V_91 ) ) ||
( F_48 ( V_2 ) &&
F_60 ( V_2 ) ) ) {
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ;
V_291 ++ ) {
V_11 = & V_2 -> V_11 [ V_291 ] ;
if ( V_11 -> V_110 )
F_146 ( V_11 -> V_110 , V_11 ) ;
}
}
}
}
static void F_147 ( struct V_1 * V_2 )
{
T_1 V_303 = 0 ;
if ( F_48 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_72 [ 0 ] &
V_304 )
V_2 -> V_41 |= V_305 ;
} else {
V_303 = V_2 -> V_4 -> V_8 ;
if ( F_148 ( V_303 ) )
V_2 -> V_41 |= V_305 ;
}
}
int F_149 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_291 ;
struct V_306 * V_307 ;
if ( V_2 -> V_308 != V_309 )
return - V_183 ;
if ( F_20 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_115 ( V_2 ) )
return - V_183 ;
F_147 ( V_2 ) ;
if ( F_150 ( V_2 ) )
return - V_183 ;
for ( V_291 = 0 ; V_291 < V_2 -> V_221 ; V_291 ++ ) {
V_307 = & V_2 -> V_15 -> V_310 [ V_291 ] ;
F_151 ( V_2 , V_307 , V_291 ) ;
}
F_23 ( V_22 ) ;
F_152 ( V_2 , V_22 -> V_311 ) ;
V_2 -> V_4 -> V_312 = 0 ;
if ( V_2 -> V_87 > 1 )
F_153 ( V_2 , 1 ) ;
F_154 ( V_2 ) ;
if ( V_22 -> V_313 & V_314 )
F_155 ( V_2 , V_315 ) ;
F_110 ( V_45 , & V_2 -> V_46 ) ;
F_25 ( V_2 ) ;
F_156 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_316 = 0 ;
return 0 ;
}
int F_157 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_51 = 0 ;
F_158 () ;
if ( F_159 ( V_22 ) )
V_51 = F_149 ( V_2 , V_22 ) ;
F_160 () ;
return V_51 ;
}
void F_161 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_291 ;
if ( V_2 -> V_308 != V_309 )
return;
if ( ! F_162 ( V_45 , & V_2 -> V_46 ) )
return;
if ( F_19 ( V_2 ) )
F_163 ( & V_2 -> V_4 -> V_317 -> V_318 ) ;
F_164 () ;
F_165 ( V_22 ) ;
V_2 -> V_4 -> V_312 = 0 ;
F_166 ( V_22 ) ;
F_167 ( V_2 ) ;
if ( V_2 -> V_319 . V_320 )
F_168 ( V_2 ) ;
F_169 ( V_2 , V_321 ) ;
F_22 ( V_2 ) ;
F_170 ( V_2 ) ;
V_2 -> V_41 &= ~ V_305 ;
F_171 ( V_2 ) ;
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ; V_291 ++ )
F_172 ( V_2 , & V_2 -> V_11 [ V_291 ] ) ;
}
void F_173 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_158 () ;
if ( F_159 ( V_22 ) )
F_161 ( V_2 , V_22 ) ;
F_160 () ;
}
int
F_174 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( V_2 -> V_308 == V_309 )
return 0 ;
V_51 = F_175 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_176 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_31 ) ;
goto V_322;
}
V_51 = F_177 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_32 ) ;
goto V_323;
}
V_51 = F_142 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_33 ) ;
goto V_324;
}
F_178 ( V_2 ) ;
V_2 -> V_308 = V_309 ;
return 0 ;
V_324:
F_179 ( V_2 ) ;
V_323:
F_180 ( V_2 ) ;
V_322:
F_181 ( V_2 ) ;
return V_51 ;
}
void F_182 ( struct V_1 * V_2 )
{
if ( V_2 -> V_308 != V_309 )
return;
F_183 ( V_2 ) ;
F_179 ( V_2 ) ;
F_184 ( V_2 ) ;
F_145 ( V_2 ) ;
F_181 ( V_2 ) ;
F_180 ( V_2 ) ;
V_2 -> V_308 = 0 ;
}
void F_185 ( struct V_21 * V_22 , int V_87 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_18 * V_290 ;
int V_85 = V_2 -> V_85 ;
int V_291 ;
F_113 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_100 == V_293 ) {
for ( V_291 = 0 ; V_291 < V_2 -> V_87 ; V_291 ++ ) {
V_290 = & V_2 -> V_15 -> V_19 [ V_291 ] ;
F_186 ( V_290 ) ;
}
}
F_170 ( V_2 ) ;
F_182 ( V_2 ) ;
V_2 -> V_4 -> V_100 = 0 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_85 = V_85 ;
if ( F_174 ( V_2 ) )
goto V_325;
if ( F_159 ( V_22 ) )
F_149 ( V_2 , V_22 ) ;
V_325:
F_24 ( V_22 ) ;
}
static int F_187 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_51 = - V_56 ;
goto V_281;
}
V_4 -> V_326 . V_327 = V_328 ;
V_4 -> V_326 . type = V_329 ;
V_4 -> V_326 . V_330 = V_331 ;
V_4 -> V_326 . V_332 = V_333 ;
if ( F_59 ( V_2 ) ) {
V_4 -> V_326 . V_334 = V_335 ;
V_4 -> V_326 . V_336 = V_337 ;
}
memset ( & V_2 -> V_338 , 0 , sizeof( V_2 -> V_338 ) ) ;
V_281:
return V_51 ;
}
static void F_188 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_200 . V_205 ) {
F_73 ( V_2 -> V_4 -> V_200 . V_205 ) ;
V_2 -> V_4 -> V_200 . V_205 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_339 . V_340 ) ;
V_2 -> V_4 -> V_200 . V_205 = NULL ;
}
int F_189 ( struct V_21 * V_22 , int V_341 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_18 * V_290 ;
struct V_306 * V_307 ;
int V_291 ;
int V_26 ;
F_21 ( V_22 ) ;
if ( F_159 ( V_22 ) )
F_161 ( V_2 , V_22 ) ;
F_182 ( V_2 ) ;
V_2 -> V_87 = V_94 ;
V_2 -> V_4 -> V_100 = V_341 ;
V_2 -> V_4 -> V_312 = 0 ;
V_26 = F_174 ( V_2 ) ;
if ( V_26 ) {
F_24 ( V_22 ) ;
return V_26 ;
}
V_26 = F_150 ( V_2 ) ;
if ( V_26 ) {
F_182 ( V_2 ) ;
F_24 ( V_22 ) ;
return V_26 ;
}
for ( V_291 = 0 ; V_291 < V_2 -> V_221 ; V_291 ++ ) {
V_307 = & V_2 -> V_15 -> V_310 [ V_291 ] ;
F_151 ( V_2 , V_307 , V_291 ) ;
}
if ( V_2 -> V_4 -> V_100 == V_293 ) {
for ( V_291 = 0 ; V_291 < V_2 -> V_87 ; V_291 ++ ) {
V_290 = & V_2 -> V_15 -> V_19 [ V_291 ] ;
F_190 ( V_290 ) ;
}
}
if ( V_2 -> V_4 -> V_100 == V_301 ) {
V_2 -> V_4 -> V_342 = 0 ;
F_156 ( V_2 , 1 ) ;
}
F_110 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_191 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_43 ( V_62 , & V_2 -> V_46 ) )
return - V_343 ;
F_21 ( V_22 ) ;
F_173 ( V_2 , V_22 ) ;
F_157 ( V_2 , V_22 ) ;
F_24 ( V_22 ) ;
F_113 ( V_62 , & V_2 -> V_46 ) ;
F_69 ( & V_2 -> V_5 -> V_30 , L_34 , V_54 ) ;
return 0 ;
}
int
F_192 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_43 ( V_62 , & V_2 -> V_46 ) )
return - V_343 ;
if ( V_2 -> V_308 == V_309 ) {
F_21 ( V_22 ) ;
if ( F_159 ( V_22 ) )
F_161 ( V_2 , V_22 ) ;
F_182 ( V_2 ) ;
if ( F_159 ( V_22 ) ) {
V_51 = F_174 ( V_2 ) ;
if ( ! V_51 ) {
F_149 ( V_2 , V_22 ) ;
F_112 ( V_22 , V_344 ) ;
}
}
F_24 ( V_22 ) ;
}
F_113 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
void F_193 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_345 = V_4 -> V_129 ;
T_3 V_16 ;
V_4 -> V_346 = V_347 ;
if ( V_345 <= 2 )
V_16 = ( V_348 - V_347 ) /
V_345 ;
else
V_16 = ( V_349 - V_347 ) /
V_345 ;
V_4 -> V_55 = V_16 ;
}
int
F_194 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_350 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_351 = 1 ;
V_2 -> V_4 -> V_352 = 0 ;
F_195 ( V_2 ) ;
V_22 -> V_353 = & V_354 ;
V_22 -> V_355 = V_356 * V_357 ;
F_196 ( V_22 , V_22 -> V_311 ) ;
if ( F_19 ( V_2 ) )
F_197 ( V_22 , & V_358 ) ;
else
F_197 ( V_22 , & V_359 ) ;
V_22 -> V_313 |= ( V_360 | V_361 | V_362 |
V_363 | V_364 |
V_365 ) ;
V_22 -> V_366 |= ( V_360 | V_361 |
V_363 ) ;
if ( F_121 ( V_2 ) ) {
V_22 -> V_313 |= ( V_367 | V_368 ) ;
V_22 -> V_366 |= ( V_367 | V_368 ) ;
}
if ( V_350 ) {
V_22 -> V_313 |= V_369 ;
V_22 -> V_366 |= V_369 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_313 |= ( V_370 ) ;
if ( F_19 ( V_2 ) )
V_22 -> V_313 |= V_371 ;
if ( V_2 -> V_4 -> V_8 & V_372 )
V_22 -> V_313 |= V_314 ;
V_22 -> V_373 = V_22 -> V_313 ;
V_22 -> V_374 |= V_375 ;
V_22 -> V_110 = V_2 -> V_92 [ 0 ] . V_109 ;
V_51 = F_198 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_199 ( V_22 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_35 ) ;
return V_51 ;
}
F_200 ( V_2 -> V_376 ) ;
return 0 ;
}
static int F_201 ( struct V_23 * V_5 , int * V_350 )
{
if ( ! F_202 ( V_5 , F_203 ( 64 ) ) &&
! F_204 ( V_5 , F_203 ( 64 ) ) )
* V_350 = 1 ;
else if ( ! F_202 ( V_5 , F_203 ( 32 ) ) &&
! F_204 ( V_5 , F_203 ( 32 ) ) )
* V_350 = 0 ;
else {
F_69 ( & V_5 -> V_30 , L_36 ) ;
return - V_183 ;
}
return 0 ;
}
void F_205 ( struct V_1 * V_2 )
{
int V_291 ;
struct V_10 * V_11 ;
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ; V_291 ++ ) {
V_11 = & V_2 -> V_11 [ V_291 ] ;
if ( V_11 && V_11 -> V_377 != NULL ) {
F_73 ( V_11 -> V_377 ) ;
V_11 -> V_377 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_206 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_291 , V_109 , V_184 ;
struct V_10 * V_11 ;
struct V_378 * V_377 ;
V_11 = F_57 ( V_2 -> V_85 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ; V_291 ++ ) {
V_11 = & V_2 -> V_11 [ V_291 ] ;
V_11 -> V_379 = V_2 -> V_219 ;
V_11 -> V_380 = F_207 ( V_22 , V_291 ) ;
V_377 = F_67 ( F_208 ( V_11 ) ) ;
if ( V_377 == NULL ) {
F_205 ( V_2 ) ;
return - V_56 ;
}
memset ( V_377 , 0 , F_208 ( V_11 ) ) ;
V_11 -> V_377 = V_377 ;
F_209 ( & V_11 -> V_381 ) ;
}
if ( F_59 ( V_2 ) ||
( F_48 ( V_2 ) && F_60 ( V_2 ) ) ) {
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ; V_291 ++ ) {
V_11 = & V_2 -> V_11 [ V_291 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_96 ) {
V_184 = V_2 -> V_87 + V_291 ;
V_109 = V_2 -> V_92 [ V_184 ] . V_109 ;
V_11 -> V_110 = V_109 ;
}
}
}
return 0 ;
}
void F_210 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_382 = 0 ;
if ( F_48 ( V_2 ) )
V_382 = V_383 ;
else if ( F_59 ( V_2 ) )
V_382 = V_384 ;
if ( V_4 -> V_72 [ 0 ] & V_385 )
F_211 ( V_2 , V_382 ) ;
}
static int
F_212 ( struct V_23 * V_5 , const struct V_161 * V_162 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_350 = - 1 ;
char V_386 [ V_387 + 19 ] ;
struct V_388 * V_376 ;
if ( V_5 -> V_389 )
return - V_390 ;
V_51 = F_213 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_214 ( V_5 , 0 ) & V_391 ) ) {
V_51 = - V_390 ;
goto V_392;
}
V_51 = F_201 ( V_5 , & V_350 ) ;
if ( V_51 )
goto V_392;
V_51 = F_215 ( V_5 , V_393 ) ;
if ( V_51 )
goto V_392;
F_216 ( V_5 ) ;
F_217 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_394;
}
switch ( V_162 -> V_6 ) {
case V_7 :
V_4 -> V_395 = & V_396 ;
V_4 -> V_397 = ( T_1 * ) V_398 ;
break;
case V_174 :
case V_175 :
F_218 ( V_4 ) ;
break;
case V_176 :
case V_177 :
F_219 ( V_4 ) ;
break;
default:
goto V_399;
}
V_51 = F_92 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_399;
V_22 = F_220 ( sizeof( struct V_1 ) ,
V_400 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_401;
}
F_221 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_18 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_402 = F_222 ( L_27 ) ;
if ( V_2 -> V_402 == NULL ) {
V_51 = - V_56 ;
F_69 ( & V_5 -> V_30 , L_37 ) ;
goto V_403;
}
V_51 = F_187 ( V_2 ) ;
if ( V_51 )
goto V_404;
V_2 -> V_405 = V_406 ;
V_2 -> V_4 -> V_407 = V_5 -> V_408 ;
if ( V_409 == V_410 )
V_2 -> V_52 = true ;
else if ( V_409 == V_411 )
V_2 -> V_412 = true ;
F_223 ( & V_2 -> V_4 -> V_413 ) ;
F_224 ( & V_2 -> V_4 -> V_414 ) ;
F_225 ( & V_2 -> V_415 ) ;
F_226 ( V_2 ) ;
if ( F_48 ( V_2 ) ) {
F_88 ( V_2 , V_162 ) ;
V_2 -> V_416 = V_2 -> V_4 -> V_27 ;
V_51 = F_227 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_38
L_39 ) ;
goto V_417;
}
if ( V_2 -> V_4 -> V_97 ) {
if ( F_47 ( V_2 ) == 1 )
F_53 ( V_2 ,
V_94 ) ;
else
F_53 ( V_2 ,
V_418 ) ;
F_55 ( V_2 ,
V_419 ) ;
} else {
F_53 ( V_2 , V_94 ) ;
F_55 ( V_2 , V_94 ) ;
}
V_51 = F_228 ( V_2 ) ;
if ( V_51 )
goto V_324;
V_2 -> V_41 |= V_420 ;
V_376 = V_2 -> V_376 ;
if ( V_376 && F_229 ( V_376 ) )
F_230 ( V_376 ) ;
} else if ( F_59 ( V_2 ) ) {
F_231 ( V_2 , V_162 ) ;
V_2 -> V_416 = V_2 -> V_4 -> V_27 ;
V_51 = F_232 ( V_2 , V_350 ) ;
if ( V_51 ) {
switch ( V_51 ) {
case - V_421 :
F_69 ( & V_5 -> V_30 , L_40 ) ;
F_69 ( & V_5 -> V_30 , L_41 ) ;
goto V_324;
case - V_56 :
F_69 ( & V_5 -> V_30 , L_42 ) ;
goto V_324;
default:
F_69 ( & V_5 -> V_30 , L_43 ) ;
F_69 ( & V_5 -> V_30 , L_44 ) ;
goto V_417;
}
}
if ( F_19 ( V_2 ) )
return 0 ;
} else {
F_69 ( & V_5 -> V_30 ,
L_45 , V_54 ) ;
goto V_324;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_46 ) ;
F_233 ( V_2 ) ;
if ( V_2 -> V_416 == 0 ) {
F_98 ( V_2 , V_386 ) ;
F_35 ( L_47 ,
F_234 ( V_422 ) ,
V_386 , V_2 -> V_4 -> V_407 ) ;
}
if ( F_59 ( V_2 ) && ! V_111 &&
! ! V_106 )
F_11 ( & V_5 -> V_30 ,
L_48 ) ;
if ( F_48 ( V_2 ) ) {
V_51 = F_235 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_49 ) ;
goto V_423;
}
}
V_51 = F_76 ( V_2 ) ;
if ( V_51 )
goto V_424;
V_51 = F_194 ( V_2 , V_22 , V_350 ) ;
if ( V_51 )
goto V_424;
if ( V_2 -> V_416 == 0 )
F_210 ( V_2 ) ;
F_236 ( V_5 , V_2 ) ;
if ( F_48 ( V_2 ) )
F_237 ( V_2 , V_425 ,
V_426 ) ;
switch ( V_2 -> V_4 -> V_127 ) {
case V_128 :
F_54 ( & V_2 -> V_5 -> V_30 , L_50 ,
V_2 -> V_22 -> V_190 ) ;
break;
case V_131 :
F_54 ( & V_2 -> V_5 -> V_30 , L_51 ,
V_2 -> V_22 -> V_190 ) ;
break;
}
if ( V_2 -> V_412 )
F_238 ( V_2 ) ;
F_239 ( V_2 ) ;
return 0 ;
V_424:
if ( F_59 ( V_2 ) )
F_240 ( V_2 ) ;
V_423:
F_70 ( V_2 ) ;
F_241 ( V_2 ) ;
F_242 ( V_2 , 0 ) ;
V_324:
F_188 ( V_2 ) ;
V_404:
F_243 ( V_2 -> V_402 ) ;
V_403:
F_244 ( V_22 ) ;
V_401:
F_74 ( V_4 ) ;
V_399:
F_7 ( V_4 ) ;
V_394:
F_245 ( V_5 ) ;
V_392:
F_246 ( V_5 ) ;
return V_51 ;
V_417:
F_110 ( V_427 , & V_2 -> V_46 ) ;
V_22 -> V_353 = & V_428 ;
F_197 ( V_22 , & V_429 ) ;
V_4 -> V_127 = V_131 ;
if ( F_59 ( V_2 ) )
V_2 -> V_108 = NULL ;
else
V_4 -> V_430 = V_431 ;
V_51 = F_199 ( V_22 ) ;
if ( V_51 ) {
F_69 ( & V_5 -> V_30 , L_52 ) ;
F_242 ( V_2 , 0 ) ;
goto V_324;
}
F_236 ( V_5 , V_2 ) ;
F_239 ( V_2 ) ;
return 0 ;
}
static void F_247 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_248 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_249 ( V_2 ) ;
F_241 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_250 ( V_2 -> V_376 ) ;
F_251 ( V_22 ) ;
F_252 ( V_2 ) ;
if ( F_59 ( V_2 ) ) {
F_253 ( V_2 , 0 ) ;
F_45 ( & V_2 -> V_432 ) ;
F_240 ( V_2 ) ;
F_254 ( V_2 ) ;
F_255 ( V_4 -> V_433 ) ;
F_7 ( V_4 -> V_434 ) ;
}
F_182 ( V_2 ) ;
if ( V_2 -> V_140 != NULL )
F_7 ( V_2 -> V_140 ) ;
if ( V_2 -> V_142 != NULL )
F_7 ( V_2 -> V_142 ) ;
if ( F_48 ( V_2 ) )
F_242 ( V_2 , 0 ) ;
F_113 ( V_62 , & V_2 -> V_46 ) ;
F_256 ( V_2 ) ;
F_70 ( V_2 ) ;
F_257 ( V_2 ) ;
F_74 ( V_2 -> V_4 ) ;
F_138 ( V_2 ) ;
F_258 ( V_5 ) ;
F_245 ( V_5 ) ;
F_246 ( V_5 ) ;
if ( V_2 -> V_402 ) {
F_243 ( V_2 -> V_402 ) ;
V_2 -> V_402 = NULL ;
}
F_188 ( V_2 ) ;
F_7 ( V_4 ) ;
F_244 ( V_22 ) ;
}
static void F_259 ( struct V_23 * V_5 )
{
if ( F_260 ( V_5 ) )
return;
F_246 ( V_5 ) ;
}
static int F_261 ( struct V_23 * V_5 , T_8 V_46 )
{
int V_435 ;
V_435 = F_260 ( V_5 ) ;
if ( V_435 )
return V_435 ;
F_262 ( V_5 , F_263 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_264 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_248 ( V_5 ) ;
int V_51 ;
V_51 = F_213 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_262 ( V_5 , V_436 ) ;
F_216 ( V_5 ) ;
F_265 ( V_5 ) ;
return F_266 ( V_2 ) ;
}
static int F_267 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 ;
if ( F_20 ( V_427 , & V_2 -> V_46 ) ) {
F_109 ( V_22 , L_53 ,
V_54 ) ;
return - V_183 ;
}
F_165 ( V_22 ) ;
V_51 = F_174 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_149 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_281;
F_268 ( V_22 ) ;
return 0 ;
V_281:
F_182 ( V_2 ) ;
return V_51 ;
}
static int F_269 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
F_161 ( V_2 , V_22 ) ;
return 0 ;
}
void F_238 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_90 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_437 = 0 ;
T_3 V_129 = 0 ;
if ( V_2 -> V_319 . V_438 && V_2 -> V_319 . V_439 )
return;
V_129 = V_2 -> V_4 -> V_129 ;
F_209 ( & V_2 -> V_440 ) ;
F_209 ( & V_2 -> V_441 ) ;
if ( F_48 ( V_2 ) ) {
V_437 = V_349 ;
V_2 -> V_319 . V_442 = V_443 ;
} else {
V_437 = V_444 ;
V_2 -> V_319 . V_442 = V_445 ;
}
V_34 = F_57 ( V_2 -> V_319 . V_442 ,
sizeof( struct V_446 ) , V_447 ) ;
if ( ! V_34 )
return;
V_2 -> V_319 . V_438 = ( V_437 / V_129 ) ;
V_2 -> V_319 . V_439 = V_34 ;
F_270 ( V_22 , L_54 ,
V_129 , V_2 -> V_319 . V_438 ) ;
for ( V_90 = 0 ; V_90 < V_2 -> V_319 . V_442 ; V_90 ++ )
F_271 ( & V_2 -> V_319 . V_439 [ V_90 ] ) ;
V_2 -> V_448 . V_442 = V_2 -> V_319 . V_442 ;
V_34 = F_57 ( V_2 -> V_448 . V_442 ,
sizeof( struct V_446 ) , V_447 ) ;
if ( ! V_34 )
return;
V_2 -> V_448 . V_438 = ( V_437 / V_129 ) ;
V_2 -> V_448 . V_439 = V_34 ;
for ( V_90 = 0 ; V_90 < V_2 -> V_448 . V_442 ; V_90 ++ )
F_271 ( & V_2 -> V_448 . V_439 [ V_90 ] ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
if ( V_2 -> V_319 . V_438 && V_2 -> V_319 . V_439 )
F_7 ( V_2 -> V_319 . V_439 ) ;
V_2 -> V_319 . V_439 = NULL ;
V_2 -> V_319 . V_438 = 0 ;
if ( V_2 -> V_448 . V_438 && V_2 -> V_448 . V_439 )
F_7 ( V_2 -> V_448 . V_439 ) ;
V_2 -> V_448 . V_438 = 0 ;
V_2 -> V_448 . V_439 = NULL ;
}
int F_272 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_449 , V_450 , V_231 = 0 ;
int V_451 = 0 ;
if ( F_59 ( V_2 ) )
V_231 = F_273 ( V_2 -> V_4 , V_452 ) ;
if ( F_48 ( V_2 ) )
V_231 = F_84 ( V_2 , V_453 ) ;
V_449 = F_274 ( V_231 ) ;
V_450 = F_275 ( V_231 ) ;
if ( V_449 == V_454 ) {
F_69 ( & V_22 -> V_30 ,
L_55
L_56 ,
V_450 ) ;
V_451 = 1 ;
} else if ( V_449 == V_455 ) {
if ( V_2 -> V_4 -> V_231 == V_456 ) {
F_69 ( & V_22 -> V_30 ,
L_57
L_58
L_59 ,
V_450 ) ;
}
} else {
if ( V_2 -> V_4 -> V_231 == V_455 ) {
F_54 ( & V_22 -> V_30 ,
L_60
L_61 , V_450 ) ;
}
}
V_2 -> V_4 -> V_231 = V_449 ;
return V_451 ;
}
static void F_276 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_10 * V_11 ;
int V_291 ;
if ( F_20 ( V_62 , & V_2 -> V_46 ) )
return;
if ( ++ V_2 -> V_457 >= V_458 ) {
F_270 ( V_22 , L_62 ) ;
if ( F_48 ( V_2 ) )
V_2 -> V_263 = 1 ;
else if ( F_59 ( V_2 ) )
F_277 ( V_2 ,
V_459 ) ;
} else {
F_270 ( V_22 , L_63 ) ;
for ( V_291 = 0 ; V_291 < V_2 -> V_85 ; V_291 ++ ) {
V_11 = & V_2 -> V_11 [ V_291 ] ;
F_270 ( V_22 , L_64 , V_291 ) ;
F_270 ( V_22 ,
L_65 ,
F_278 ( V_11 -> V_460 ) ,
F_278 ( V_11 -> V_13 ) ,
V_11 -> V_461 ,
F_279 ( * ( V_11 -> V_462 ) ) ) ;
F_270 ( V_22 ,
L_66 ,
V_11 -> V_463 . V_464 ,
V_11 -> V_463 . V_465 ,
V_11 -> V_463 . V_466 ,
V_11 -> V_463 . V_467 ) ;
}
V_2 -> V_4 -> V_316 = 1 ;
}
}
static struct V_468 * F_280 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_468 * V_338 = & V_22 -> V_338 ;
if ( F_20 ( V_45 , & V_2 -> V_46 ) )
F_281 ( V_2 ) ;
V_338 -> V_332 = V_2 -> V_338 . V_469 + V_2 -> V_338 . V_470 ;
V_338 -> V_336 = V_2 -> V_338 . V_471 ;
V_338 -> V_472 = V_2 -> V_338 . V_473 + V_2 -> V_338 . V_474 ;
V_338 -> V_475 = V_2 -> V_338 . V_476 ;
V_338 -> V_477 = V_2 -> V_338 . V_478 ;
V_338 -> V_479 = V_2 -> V_338 . V_480 ;
return V_338 ;
}
T_9 F_282 ( struct V_1 * V_2 )
{
T_1 V_481 ;
V_481 = F_278 ( V_2 -> V_115 ) ;
if ( ! ( V_481 & V_2 -> V_4 -> V_113 ) )
return V_482 ;
V_481 = F_278 ( V_2 -> V_117 ) ;
if ( ! F_283 ( V_481 ) )
return V_482 ;
F_3 ( 0xffffffff , V_2 -> V_108 ) ;
F_278 ( V_2 -> V_115 ) ;
F_278 ( V_2 -> V_115 ) ;
return V_483 ;
}
static T_9 V_294 ( int V_110 , void * V_158 )
{
struct V_18 * V_290 = V_158 ;
struct V_1 * V_2 = V_290 -> V_2 ;
if ( V_2 -> V_41 & V_96 )
goto V_484;
else if ( V_2 -> V_41 & V_95 ) {
F_3 ( 0xffffffff , V_2 -> V_108 ) ;
goto V_484;
}
if ( F_284 ( V_2 ) == V_482 )
return V_482 ;
V_484:
V_2 -> V_4 -> V_485 ++ ;
F_190 ( V_290 ) ;
return V_483 ;
}
static T_9 V_299 ( int V_110 , void * V_158 )
{
struct V_18 * V_290 = V_158 ;
struct V_1 * V_2 = V_290 -> V_2 ;
if ( F_284 ( V_2 ) == V_482 )
return V_482 ;
F_285 ( & V_290 -> V_486 ) ;
return V_483 ;
}
static T_9 V_298 ( int V_110 , void * V_158 )
{
struct V_18 * V_290 = V_158 ;
struct V_1 * V_2 = V_290 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_108 ) ;
F_285 ( & V_290 -> V_486 ) ;
return V_483 ;
}
static T_9 V_297 ( int V_110 , void * V_158 )
{
struct V_18 * V_290 = V_158 ;
F_285 ( & V_290 -> V_486 ) ;
return V_483 ;
}
static T_9 V_302 ( int V_110 , void * V_158 )
{
struct V_10 * V_11 = V_158 ;
F_285 ( & V_11 -> V_486 ) ;
return V_483 ;
}
static void F_286 ( struct V_21 * V_22 )
{
int V_291 ;
struct V_18 * V_290 ;
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_287 ( V_2 -> V_110 ) ;
for ( V_291 = 0 ; V_291 < V_2 -> V_87 ; V_291 ++ ) {
V_290 = & V_15 -> V_19 [ V_291 ] ;
V_299 ( V_2 -> V_110 , V_290 ) ;
}
F_288 ( V_2 -> V_110 ) ;
}
static void
F_141 ( struct V_1 * V_2 , T_2 V_487 )
{
T_1 V_488 ;
V_488 = V_2 -> V_416 & 0xf ;
V_488 |= V_487 << 7 ;
V_488 |= ( V_406 - V_2 -> V_405 ) << 8 ;
F_86 ( V_2 , V_489 , V_488 ) ;
V_2 -> V_405 = V_406 ;
}
static int
F_289 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_488 ;
F_290 ( V_46 != V_490 &&
V_46 != V_491 ) ;
if ( F_83 ( V_2 ) )
return - V_183 ;
V_488 = F_84 ( V_2 , V_492 ) ;
if ( V_46 == V_490 )
F_291 ( V_488 , V_2 -> V_416 ) ;
else if ( V_46 == V_491 )
F_292 ( V_488 , V_2 -> V_416 ) ;
F_86 ( V_2 , V_492 , V_488 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
static int
F_293 ( struct V_1 * V_2 )
{
T_1 V_488 ;
if ( F_83 ( V_2 ) )
return - V_343 ;
V_488 = F_84 ( V_2 , V_492 ) ;
F_294 ( V_488 , V_2 -> V_416 ) ;
F_86 ( V_2 , V_492 , V_488 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
void F_242 ( struct V_1 * V_2 , T_2 V_493 )
{
T_1 V_488 ;
if ( F_83 ( V_2 ) )
goto V_51;
V_488 = F_84 ( V_2 , V_494 ) ;
F_295 ( V_488 , V_2 -> V_416 ) ;
F_86 ( V_2 , V_494 , V_488 ) ;
if ( V_493 ) {
F_86 ( V_2 , V_286 ,
V_288 ) ;
F_54 ( & V_2 -> V_5 -> V_30 ,
L_67 ) ;
} else if ( ! ( V_488 & 0x11111111 ) )
F_86 ( V_2 , V_286 ,
V_495 ) ;
V_488 = F_84 ( V_2 , V_492 ) ;
F_294 ( V_488 , V_2 -> V_416 ) ;
F_86 ( V_2 , V_492 , V_488 ) ;
F_87 ( V_2 ) ;
V_51:
V_2 -> V_496 = 0 ;
V_2 -> V_41 &= ~ V_497 ;
F_113 ( V_498 , & V_2 -> V_46 ) ;
F_113 ( V_62 , & V_2 -> V_46 ) ;
}
static int
F_296 ( struct V_1 * V_2 )
{
int V_499 , V_46 , V_500 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_84 ( V_2 , V_492 ) ;
V_499 = F_84 ( V_2 , V_494 ) ;
if ( V_2 -> V_41 & V_501 ) {
V_500 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_499 = V_499 & V_500 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_499 & 0x11111111 ) ) ||
( ( V_499 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_297 ( struct V_1 * V_2 )
{
T_1 V_488 = F_84 ( V_2 , V_502 ) ;
if ( V_488 != V_503 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_68
L_69 , V_503 , V_488 ) ;
}
return 0 ;
}
static int
F_132 ( struct V_1 * V_2 )
{
T_1 V_488 , V_504 ;
T_2 V_505 = V_2 -> V_505 ;
T_2 V_416 = V_2 -> V_416 ;
T_2 V_26 ;
if ( F_162 ( V_498 , & V_2 -> V_46 ) )
return 1 ;
if ( F_83 ( V_2 ) )
return - 1 ;
V_488 = F_84 ( V_2 , V_494 ) ;
if ( ! ( V_488 & ( 1 << ( V_416 * 4 ) ) ) ) {
F_298 ( V_488 , V_416 ) ;
F_86 ( V_2 , V_494 , V_488 ) ;
}
V_504 = F_84 ( V_2 , V_286 ) ;
F_299 ( V_2 , V_506 , L_70 , V_504 ) ;
switch ( V_504 ) {
case V_495 :
F_86 ( V_2 , V_286 ,
V_507 ) ;
F_86 ( V_2 , V_502 ,
V_503 ) ;
F_141 ( V_2 , 0 ) ;
F_87 ( V_2 ) ;
return 1 ;
case V_287 :
V_26 = F_297 ( V_2 ) ;
F_87 ( V_2 ) ;
return V_26 ;
case V_490 :
V_488 = F_84 ( V_2 , V_492 ) ;
F_291 ( V_488 , V_416 ) ;
F_86 ( V_2 , V_492 , V_488 ) ;
break;
case V_491 :
V_488 = F_84 ( V_2 , V_492 ) ;
F_292 ( V_488 , V_416 ) ;
F_86 ( V_2 , V_492 , V_488 ) ;
break;
case V_288 :
F_69 ( & V_2 -> V_5 -> V_30 , L_71 ) ;
F_87 ( V_2 ) ;
return - 1 ;
case V_507 :
case V_508 :
break;
}
F_87 ( V_2 ) ;
do {
F_128 ( 1000 ) ;
V_504 = F_84 ( V_2 , V_286 ) ;
if ( V_504 == V_508 )
continue;
} while ( ( V_504 != V_287 ) && -- V_505 );
if ( ! V_505 ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_72 ) ;
return - 1 ;
}
if ( F_83 ( V_2 ) )
return - 1 ;
V_488 = F_84 ( V_2 , V_492 ) ;
F_294 ( V_488 , V_416 ) ;
F_86 ( V_2 , V_492 , V_488 ) ;
V_26 = F_297 ( V_2 ) ;
F_87 ( V_2 ) ;
return V_26 ;
}
static void
F_300 ( struct V_509 * V_64 )
{
struct V_1 * V_2 = F_301 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
T_1 V_510 = 0xf ;
T_1 V_488 ;
if ( F_83 ( V_2 ) )
goto V_511;
V_510 = F_84 ( V_2 , V_286 ) ;
if ( V_510 == V_508 ||
V_510 == V_491 ) {
F_87 ( V_2 ) ;
F_237 ( V_2 , F_300 ,
V_426 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_133 == V_167 ) {
F_87 ( V_2 ) ;
goto V_512;
}
if ( V_510 == V_507 ||
V_510 == V_287 ) {
F_54 ( & V_2 -> V_5 -> V_30 , L_73
L_74 ) ;
goto V_513;
}
if ( V_2 -> V_514 ++ > V_2 -> V_515 ) {
F_54 ( & V_2 -> V_5 -> V_30 , L_75 ,
V_2 -> V_515 ) ;
goto V_513;
}
if ( ! F_296 ( V_2 ) ) {
V_513:
V_510 = F_84 ( V_2 , V_286 ) ;
if ( V_510 == V_490 ) {
F_86 ( V_2 , V_286 ,
V_507 ) ;
F_110 ( V_498 , & V_2 -> V_46 ) ;
F_299 ( V_2 , V_516 , L_76 ) ;
F_141 ( V_2 , 0 ) ;
V_488 = F_84 ( V_2 ,
V_492 ) ;
F_291 ( V_488 , V_2 -> V_416 ) ;
F_86 ( V_2 ,
V_492 , V_488 ) ;
}
F_87 ( V_2 ) ;
F_158 () ;
if ( F_302 ( V_2 ) &&
( V_2 -> V_41 & V_501 ) ) {
F_299 ( V_2 , V_516 , L_77 ) ;
F_303 ( V_2 ) ;
V_2 -> V_41 |= V_497 ;
}
F_160 () ;
V_2 -> V_41 &= ~ V_501 ;
if ( ! V_2 -> V_168 -> V_517 ( V_2 ) ) {
F_237 ( V_2 , V_518 , 0 ) ;
V_2 -> V_514 = 0 ;
return;
}
goto V_511;
}
F_87 ( V_2 ) ;
V_512:
V_510 = F_84 ( V_2 , V_286 ) ;
F_299 ( V_2 , V_506 , L_78 , V_510 ) ;
switch ( V_510 ) {
case V_287 :
if ( ! F_227 ( V_2 ) ) {
F_237 ( V_2 , V_518 , 0 ) ;
V_2 -> V_514 = 0 ;
return;
}
case V_288 :
break;
default:
F_237 ( V_2 ,
F_300 , V_426 ) ;
return;
}
V_511:
F_69 ( & V_2 -> V_5 -> V_30 , L_79
L_80 , V_510 , V_2 -> V_514 ) ;
F_24 ( V_2 -> V_22 ) ;
F_242 ( V_2 , 0 ) ;
}
static void
F_304 ( struct V_509 * V_64 )
{
struct V_1 * V_2 = F_301 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_481 ;
F_21 ( V_22 ) ;
if ( V_2 -> V_510 == V_491 ) {
if ( F_159 ( V_22 ) )
F_161 ( V_2 , V_22 ) ;
} else
F_173 ( V_2 , V_22 ) ;
V_481 = F_84 ( V_2 , V_519 ) ;
if ( V_481 & V_520 ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_81 ,
V_481 ) ;
if ( F_305 ( V_481 ) == V_521 ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_82
L_83 ) ;
F_69 ( & V_2 -> V_5 -> V_30 ,
L_84 ) ;
}
goto V_511;
}
if ( V_2 -> V_4 -> V_231 == V_454 ) {
F_69 ( & V_2 -> V_5 -> V_30 , L_85 ,
V_2 -> V_4 -> V_231 ) ;
goto V_511;
}
if ( ! ( V_2 -> V_41 & V_501 ) ) {
if ( F_289 ( V_2 , V_2 -> V_510 ) ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_86
L_87 ) ;
goto V_511;
}
}
V_2 -> V_514 = 0 ;
F_237 ( V_2 , F_300 , V_426 ) ;
return;
V_511:
F_24 ( V_22 ) ;
F_242 ( V_2 , 1 ) ;
}
static void
F_306 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_84 ( V_2 , V_277 ) ;
if ( V_46 == V_522 )
return;
if ( F_83 ( V_2 ) )
return;
F_86 ( V_2 , V_277 ,
V_522 ) ;
F_87 ( V_2 ) ;
}
void F_307 ( struct V_1 * V_2 , T_1 V_523 )
{
T_1 V_46 , V_524 = 0 , V_525 = 0 ;
F_308 ( V_524 ) ;
F_309 ( V_524 ) ;
F_139 ( V_2 , V_526 , V_524 ) ;
F_310 ( V_525 ) ;
F_311 ( V_525 ) ;
F_312 ( V_525 ) ;
F_313 ( V_525 ) ;
F_139 ( V_2 , V_527 , V_525 ) ;
F_54 ( & V_2 -> V_5 -> V_30 , L_88
L_89 ) ;
V_2 -> V_263 = 1 ;
if ( F_83 ( V_2 ) )
return;
V_46 = F_84 ( V_2 , V_286 ) ;
if ( F_20 ( V_427 , & V_2 -> V_46 ) ) {
F_109 ( V_2 -> V_22 , L_53 ,
V_54 ) ;
F_87 ( V_2 ) ;
return;
}
if ( V_46 == V_287 ) {
F_86 ( V_2 , V_286 ,
V_490 ) ;
V_2 -> V_41 |= V_501 ;
F_299 ( V_2 , V_516 , L_90 ) ;
F_141 ( V_2 , 0 ) ;
}
F_86 ( V_2 , V_277 ,
V_522 ) ;
F_87 ( V_2 ) ;
}
static void
F_130 ( struct V_1 * V_2 )
{
if ( F_83 ( V_2 ) )
return;
F_86 ( V_2 , V_277 ,
V_278 ) ;
F_299 ( V_2 , V_516 , L_91 ) ;
F_87 ( V_2 ) ;
}
void F_237 ( struct V_1 * V_2 ,
T_10 V_65 , int V_528 )
{
if ( F_20 ( V_529 , & V_2 -> V_46 ) )
return;
F_314 ( & V_2 -> V_63 , V_65 ) ;
F_315 ( V_2 -> V_402 , & V_2 -> V_63 ,
F_316 ( V_528 ) ) ;
}
static void
V_518 ( struct V_509 * V_64 )
{
struct V_1 * V_2 = F_301 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_276 ;
if ( V_2 -> V_4 -> V_133 != V_134 ) {
V_276 = F_84 ( V_2 ,
V_277 ) ;
if ( V_2 -> V_514 ++ > V_275 )
F_242 ( V_2 , 0 ) ;
else if ( V_276 != V_278 )
F_237 ( V_2 , V_518 ,
V_426 ) ;
else
goto V_530;
F_299 ( V_2 , V_516 , L_92 ) ;
return;
}
V_530:
F_317 ( V_2 -> V_376 ) ;
if ( F_159 ( V_22 ) ) {
if ( F_157 ( V_2 , V_22 ) )
goto V_484;
F_112 ( V_22 , V_344 ) ;
}
V_484:
F_24 ( V_22 ) ;
V_2 -> V_496 = 0 ;
V_2 -> V_41 &= ~ V_497 ;
F_113 ( V_62 , & V_2 -> V_46 ) ;
if ( V_2 -> V_416 == 0 )
F_210 ( V_2 ) ;
if ( ! F_293 ( V_2 ) )
F_237 ( V_2 , V_425 ,
V_426 ) ;
}
static int
F_318 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_199 * V_200 = & V_4 -> V_200 ;
T_1 V_46 = 0 , V_531 ;
T_1 V_532 ;
int V_51 = 0 ;
if ( F_272 ( V_2 ) )
goto V_533;
if ( V_2 -> V_263 )
F_319 ( V_2 , 0 ) ;
V_46 = F_84 ( V_2 , V_286 ) ;
if ( V_46 == V_490 ) {
F_306 ( V_2 ) ;
V_2 -> V_263 = 1 ;
} else if ( V_46 == V_491 )
goto V_533;
V_531 = F_84 ( V_2 , V_534 ) ;
if ( V_531 != V_2 -> V_531 ) {
V_2 -> V_531 = V_531 ;
V_2 -> V_496 = 0 ;
if ( V_2 -> V_263 )
goto V_533;
if ( V_4 -> V_316 && V_535 )
F_191 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_496 < V_536 )
return 0 ;
V_2 -> V_41 |= V_497 ;
F_319 ( V_2 , 0 ) ;
if ( V_535 )
F_113 ( V_537 , & V_2 -> V_46 ) ;
F_69 ( & V_2 -> V_5 -> V_30 , L_93 ) ;
V_532 = F_84 ( V_2 , V_519 ) ;
F_69 ( & V_2 -> V_5 -> V_30 , L_94
L_95
L_96
L_97
L_98 ,
V_532 ,
F_84 ( V_2 , V_538 ) ,
F_105 ( V_2 , V_539 + 0x3c , & V_51 ) ,
F_105 ( V_2 , V_540 + 0x3c , & V_51 ) ,
F_105 ( V_2 , V_541 + 0x3c , & V_51 ) ,
F_105 ( V_2 , V_542 + 0x3c , & V_51 ) ,
F_105 ( V_2 , V_543 + 0x3c , & V_51 ) ) ;
if ( F_305 ( V_532 ) == 0x67 )
F_69 ( & V_2 -> V_5 -> V_30 ,
L_99
L_100 ) ;
V_533:
V_2 -> V_510 = ( V_46 == V_491 ) ? V_46 :
V_490 ;
if ( V_535 && ! F_43 ( V_62 ,
& V_2 -> V_46 ) ) {
F_237 ( V_2 , F_304 , 0 ) ;
F_299 ( V_2 , V_516 , L_101 ) ;
} else if ( ! V_535 && V_200 -> V_544 &&
V_2 -> V_41 & V_501 ) {
F_303 ( V_2 ) ;
}
return 1 ;
}
void V_425 ( struct V_509 * V_64 )
{
struct V_1 * V_2 = F_301 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
if ( F_20 ( V_62 , & V_2 -> V_46 ) )
goto V_545;
if ( F_318 ( V_2 ) )
return;
if ( V_2 -> V_319 . V_320 )
F_320 ( V_2 ) ;
V_545:
F_237 ( V_2 , V_425 , V_426 ) ;
}
static int F_321 ( struct V_23 * V_5 )
{
struct V_23 * V_546 ;
int V_488 = V_5 -> V_547 ;
while ( V_488 -- > 0 ) {
V_546 = F_322 ( F_323
( V_5 -> V_548 ) , V_5 -> V_548 -> V_549 ,
F_324 ( F_325 ( V_5 -> V_547 ) , V_488 ) ) ;
if ( ! V_546 )
continue;
if ( V_546 -> V_550 != V_551 ) {
F_326 ( V_546 ) ;
return 0 ;
}
F_326 ( V_546 ) ;
}
return 1 ;
}
static int F_327 ( struct V_23 * V_5 )
{
int V_51 , V_552 ;
struct V_1 * V_2 = F_248 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_553 = V_554 ;
V_51 = F_213 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_216 ( V_5 ) ;
F_265 ( V_5 ) ;
V_552 = F_321 ( V_5 ) ;
if ( F_83 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_133 != V_167 && V_552 ) {
V_2 -> V_263 = 1 ;
F_110 ( V_498 , & V_2 -> V_46 ) ;
F_86 ( V_2 , V_286 ,
V_507 ) ;
F_299 ( V_2 , V_516 , L_76 ) ;
}
F_87 ( V_2 ) ;
V_51 = F_227 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_293 ( V_2 ) ;
F_7 ( V_2 -> V_92 ) ;
V_2 -> V_92 = NULL ;
V_51 = F_235 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_92 ) ;
F_109 ( V_22 , L_33 ) ;
return V_51 ;
}
if ( F_159 ( V_22 ) ) {
V_51 = F_174 ( V_2 ) ;
if ( V_51 ) {
F_242 ( V_2 , 1 ) ;
F_113 ( V_529 , & V_2 -> V_46 ) ;
F_24 ( V_22 ) ;
return V_51 ;
}
V_51 = F_157 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_484;
F_112 ( V_22 , V_344 ) ;
}
V_484:
F_24 ( V_22 ) ;
return V_51 ;
}
T_11 F_328 ( struct V_23 * V_5 ,
T_12 V_46 )
{
struct V_1 * V_2 = F_248 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_555 )
return V_556 ;
if ( V_46 == V_554 )
return V_557 ;
F_110 ( V_529 , & V_2 -> V_46 ) ;
F_21 ( V_22 ) ;
F_45 ( & V_2 -> V_63 ) ;
if ( F_159 ( V_22 ) )
F_173 ( V_2 , V_22 ) ;
F_182 ( V_2 ) ;
F_70 ( V_2 ) ;
F_113 ( V_62 , & V_2 -> V_46 ) ;
F_329 ( V_5 ) ;
F_246 ( V_5 ) ;
return V_558 ;
}
T_11 F_330 ( struct V_23 * V_5 )
{
return F_327 ( V_5 ) ? V_556 :
V_557 ;
}
void F_331 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_248 ( V_5 ) ;
F_332 ( V_5 ) ;
V_46 = F_84 ( V_2 , V_286 ) ;
if ( V_46 == V_287 && F_162 ( V_529 ,
& V_2 -> V_46 ) )
F_237 ( V_2 , V_425 ,
V_426 ) ;
}
static T_11 F_333 ( struct V_23 * V_5 ,
T_12 V_46 )
{
struct V_1 * V_2 = F_248 ( V_5 ) ;
struct V_559 * V_395 = V_2 -> V_4 -> V_395 ;
if ( V_395 -> V_560 ) {
return V_395 -> V_560 ( V_5 , V_46 ) ;
} else {
F_69 ( & V_5 -> V_30 , L_102 ) ;
return V_556 ;
}
}
static T_11 F_334 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_248 ( V_5 ) ;
struct V_559 * V_395 = V_2 -> V_4 -> V_395 ;
if ( V_395 -> V_561 ) {
return V_395 -> V_561 ( V_5 ) ;
} else {
F_69 ( & V_5 -> V_30 , L_103 ) ;
return V_556 ;
}
}
static void F_335 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_248 ( V_5 ) ;
struct V_559 * V_395 = V_2 -> V_4 -> V_395 ;
if ( V_395 -> V_562 )
V_395 -> V_562 ( V_5 ) ;
else
F_69 ( & V_5 -> V_30 , L_104 ) ;
}
static int
F_336 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_132 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_127 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_103 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_99 ( V_2 ) ;
V_51 = F_115 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_263 = 0 ;
return V_51 ;
}
int F_337 ( struct V_1 * V_2 , T_13 V_75 ,
int V_76 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_563 = 0 ;
char V_564 [ 8 ] ;
int V_565 ;
if ( V_76 == V_80 ) {
V_563 = V_2 -> V_81 ;
V_565 = V_2 -> V_87 ;
strcpy ( V_564 , L_105 ) ;
} else if ( V_76 == V_82 ) {
V_563 = V_2 -> V_83 ;
V_565 = V_2 -> V_85 ;
strcpy ( V_564 , L_106 ) ;
}
if ( ! V_111 && ! V_106 ) {
F_109 ( V_22 , L_107 ) ;
return - V_40 ;
}
if ( V_2 -> V_41 & V_95 ) {
F_109 ( V_22 , L_108 ) ;
return - V_40 ;
}
if ( V_75 < 2 ) {
F_109 ( V_22 ,
L_109 , V_564 ) ;
return - V_40 ;
}
if ( ! F_338 ( V_75 ) ) {
F_109 ( V_22 , L_110 ,
V_564 ) ;
return - V_40 ;
}
if ( F_48 ( V_2 ) && ( V_76 == V_82 ) &&
! F_60 ( V_2 ) ) {
F_109 ( V_22 , L_111 ) ;
return - V_40 ;
}
if ( V_75 > F_52 () ) {
F_109 ( V_22 ,
L_112 ,
V_564 , F_52 () ) ;
return - V_40 ;
}
return 0 ;
}
int F_339 ( struct V_1 * V_2 , T_2 V_86 , T_2 V_84 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
int V_51 ;
if ( F_20 ( V_62 , & V_2 -> V_46 ) )
return - V_343 ;
F_21 ( V_22 ) ;
if ( F_159 ( V_22 ) )
F_161 ( V_2 , V_22 ) ;
F_182 ( V_2 ) ;
if ( F_59 ( V_2 ) ) {
F_240 ( V_2 ) ;
F_340 ( V_2 ) ;
}
F_70 ( V_2 ) ;
F_53 ( V_2 , V_84 ) ;
F_55 ( V_2 , V_86 ) ;
F_341 ( V_22 , V_2 -> V_85 ) ;
V_51 = F_235 ( V_2 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_92 ) ;
F_109 ( V_22 , L_33 ) ;
return V_51 ;
}
if ( F_59 ( V_2 ) ) {
F_253 ( V_2 , 1 ) ;
V_51 = F_342 ( V_2 ) ;
F_343 ( V_2 ) ;
if ( V_51 ) {
F_69 ( & V_2 -> V_5 -> V_30 ,
L_113 ) ;
goto V_484;
}
}
if ( F_159 ( V_22 ) ) {
V_51 = F_174 ( V_2 ) ;
if ( V_51 )
goto V_484;
V_51 = F_149 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_484;
F_112 ( V_22 , V_344 ) ;
}
V_484:
F_24 ( V_22 ) ;
F_113 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_344 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_566 )
{
struct V_567 * V_568 ;
V_568 = F_345 ( V_30 ) ;
if ( ! V_568 )
return;
F_346 (indev) {
switch ( V_566 ) {
case V_344 :
F_347 ( V_2 ,
V_569 -> V_570 , V_571 ) ;
break;
case V_252 :
F_347 ( V_2 ,
V_569 -> V_570 , V_572 ) ;
break;
default:
break;
}
} F_348 ( V_568 ) ;
F_349 ( V_568 ) ;
}
void F_112 ( struct V_21 * V_22 , unsigned long V_566 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_250 ;
F_344 ( V_2 , V_22 , V_566 ) ;
F_350 () ;
F_351 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_352 ( V_22 , F_353 ( V_573 ) , V_250 ) ;
if ( ! V_30 )
continue;
F_344 ( V_2 , V_30 , V_566 ) ;
}
F_354 () ;
}
static int F_355 ( struct V_574 * V_575 ,
unsigned long V_566 , void * V_576 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_356 ( V_576 ) ;
V_577:
if ( V_30 == NULL )
goto V_484;
if ( V_30 -> V_374 & V_578 ) {
V_30 = F_357 ( V_30 ) ;
goto V_577;
}
if ( ! F_358 ( V_30 ) )
goto V_484;
V_2 = F_18 ( V_30 ) ;
if ( ! V_2 )
goto V_484;
if ( ! F_20 ( V_45 , & V_2 -> V_46 ) )
goto V_484;
F_344 ( V_2 , V_30 , V_566 ) ;
V_484:
return V_579 ;
}
static int
F_359 ( struct V_574 * V_575 ,
unsigned long V_566 , void * V_576 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_580 * V_569 = (struct V_580 * ) V_576 ;
V_30 = V_569 -> V_581 ? V_569 -> V_581 -> V_30 : NULL ;
V_577:
if ( V_30 == NULL )
goto V_484;
if ( V_30 -> V_374 & V_578 ) {
V_30 = F_357 ( V_30 ) ;
goto V_577;
}
if ( ! F_358 ( V_30 ) )
goto V_484;
V_2 = F_18 ( V_30 ) ;
if ( ! V_2 )
goto V_484;
if ( ! F_20 ( V_45 , & V_2 -> V_46 ) )
goto V_484;
switch ( V_566 ) {
case V_344 :
F_347 ( V_2 , V_569 -> V_570 , V_571 ) ;
break;
case V_252 :
F_347 ( V_2 , V_569 -> V_570 , V_572 ) ;
break;
default:
break;
}
V_484:
return V_579 ;
}
void F_112 ( struct V_21 * V_30 , unsigned long V_566 )
{ }
static int T_14 F_360 ( void )
{
int V_26 ;
F_361 ( V_582 L_114 , V_583 ) ;
#ifdef F_362
F_363 ( & V_584 ) ;
F_364 ( & V_585 ) ;
#endif
V_26 = F_365 ( & V_586 ) ;
if ( V_26 ) {
#ifdef F_362
F_366 ( & V_585 ) ;
F_367 ( & V_584 ) ;
#endif
}
return V_26 ;
}
static void T_15 F_368 ( void )
{
F_369 ( & V_586 ) ;
#ifdef F_362
F_366 ( & V_585 ) ;
F_367 ( & V_584 ) ;
#endif
}
