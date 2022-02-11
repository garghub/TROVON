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
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_72 ;
if ( V_4 -> V_73 &&
( V_4 -> V_74 [ 0 ] & V_75 ) ) {
V_72 = F_48 ( int , V_76 ,
F_49 () ) ;
if ( V_72 > 1 ) {
F_43 ( V_77 ,
& V_2 -> V_46 ) ;
V_2 -> V_78 = V_72 ;
}
} else {
V_2 -> V_78 = 1 ;
}
}
int F_50 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_80 , V_81 , V_82 ;
int V_51 = - 1 , V_83 ;
if ( V_2 -> V_41 & V_84 ) {
V_80 = 0 ;
V_82 = 0 ;
} else {
V_80 = V_2 -> V_78 ;
V_82 = 1 ;
}
if ( ! V_2 -> V_85 ) {
V_2 -> V_85 = F_51 ( V_79 ,
sizeof( struct V_86 ) ,
V_20 ) ;
if ( ! V_2 -> V_85 )
return - V_56 ;
}
V_2 -> V_81 = 1 ;
V_2 -> V_41 &= ~ ( V_87 | V_88 ) ;
if ( V_2 -> V_4 -> V_73 ) {
V_89:
for ( V_83 = 0 ; V_83 < V_79 ; V_83 ++ )
V_2 -> V_85 [ V_83 ] . V_90 = V_83 ;
V_51 = F_52 ( V_5 , V_2 -> V_85 , V_79 ) ;
if ( V_51 == 0 ) {
V_2 -> V_41 |= V_88 ;
if ( F_53 ( V_2 ) ) {
V_2 -> V_4 -> V_79 = V_79 ;
V_2 -> V_81 = V_79 -
V_80 - 1 ;
} else {
V_2 -> V_4 -> V_79 = V_79 ;
if ( F_54 ( V_2 ) &&
! V_2 -> V_4 -> V_91 &&
( V_2 -> V_78 > 1 ) )
V_81 = V_79 - V_80 ;
else
V_81 = V_79 ;
V_2 -> V_81 = V_81 ;
}
F_55 ( & V_5 -> V_30 , L_3 ) ;
return V_51 ;
} else if ( V_51 > 0 ) {
F_55 ( & V_5 -> V_30 ,
L_4 ,
V_79 ) ;
if ( F_53 ( V_2 ) ) {
if ( V_51 < ( V_92 - V_82 ) )
return V_51 ;
V_51 -= ( V_80 + 1 ) ;
V_79 = F_56 ( V_51 ) ;
V_79 += ( V_80 + 1 ) ;
} else {
V_79 = F_56 ( V_51 ) ;
if ( F_54 ( V_2 ) )
V_79 += V_80 ;
}
if ( V_79 ) {
F_55 ( & V_5 -> V_30 ,
L_5 ,
V_79 ) ;
goto V_89;
}
} else {
F_55 ( & V_5 -> V_30 ,
L_4 ,
V_79 ) ;
}
}
return V_51 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
T_1 V_93 , V_94 ;
const struct V_95 * V_96 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_5 = V_2 -> V_5 ;
if ( V_97 && ! F_58 ( V_5 ) ) {
V_2 -> V_41 |= V_87 ;
V_93 = V_98 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_99 = F_59 ( V_2 -> V_4 ,
V_93 ) ;
F_55 ( & V_5 -> V_30 , L_6 ) ;
V_2 -> V_85 [ 0 ] . V_100 = V_5 -> V_101 ;
return V_51 ;
}
if ( V_97 || V_102 )
return - V_43 ;
V_96 = & V_103 [ V_2 -> V_4 -> V_27 ] ;
V_2 -> V_4 -> V_104 = V_96 -> V_104 ;
V_93 = V_96 -> V_99 ;
V_2 -> V_99 = F_59 ( V_4 , V_93 ) ;
V_94 = V_96 -> V_105 ;
V_2 -> V_105 = F_59 ( V_4 , V_94 ) ;
V_2 -> V_106 = F_59 ( V_4 , V_107 ) ;
V_2 -> V_108 = F_59 ( V_4 , V_109 ) ;
F_55 ( & V_5 -> V_30 , L_7 ) ;
V_2 -> V_85 [ 0 ] . V_100 = V_5 -> V_101 ;
return V_51 ;
}
int F_60 ( struct V_1 * V_2 , T_2 V_110 , int V_111 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_79 , V_51 = 0 ;
if ( ! V_110 )
V_110 = V_112 ;
if ( V_4 -> V_73 ) {
V_79 = F_56 ( F_48 ( int , F_49 () ,
V_110 ) ) ;
if ( F_54 ( V_2 ) ) {
if ( V_111 )
V_2 -> V_78 = V_111 ;
V_79 += V_2 -> V_78 ;
}
} else {
V_79 = 1 ;
}
V_51 = F_50 ( V_2 , V_79 ) ;
if ( V_51 == - V_56 )
return V_51 ;
if ( ! ( V_2 -> V_41 & V_88 ) ) {
F_61 ( V_2 ) ;
V_51 = F_57 ( V_2 ) ;
if ( ! V_51 )
return V_51 ;
}
return 0 ;
}
int F_62 ( struct V_1 * V_2 , int V_113 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 , V_83 ;
if ( F_54 ( V_2 ) &&
! V_4 -> V_91 &&
( V_2 -> V_41 & V_88 ) ) {
V_4 -> V_114 = F_63 ( V_4 -> V_79 *
sizeof( struct V_115 ) ) ;
if ( ! V_4 -> V_114 )
return - V_56 ;
for ( V_83 = 0 ; V_83 < V_4 -> V_79 ; V_83 ++ ) {
V_4 -> V_114 [ V_83 ] . type = V_116 ;
V_4 -> V_114 [ V_83 ] . V_71 = V_83 ;
V_4 -> V_114 [ V_83 ] . V_117 = 0 ;
}
V_51 = F_64 ( V_2 , 1 ) ;
if ( V_51 )
F_65 ( & V_2 -> V_5 -> V_30 ,
L_8 ,
V_4 -> V_79 ) ;
return V_51 ;
}
return 0 ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 & V_88 )
F_67 ( V_2 -> V_5 ) ;
if ( V_2 -> V_41 & V_87 )
F_68 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_85 ) ;
V_2 -> V_85 = NULL ;
if ( V_2 -> V_4 -> V_114 ) {
F_69 ( V_2 -> V_4 -> V_114 ) ;
V_2 -> V_4 -> V_114 = NULL ;
}
}
static void F_70 ( struct V_3 * V_4 )
{
if ( V_4 -> V_118 != NULL )
F_71 ( V_4 -> V_118 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_119 * V_120 ;
int V_26 ;
if ( ! ( V_2 -> V_41 & V_53 ) ) {
switch ( V_2 -> V_4 -> V_121 ) {
case V_122 :
V_2 -> V_4 -> V_123 = V_124 ;
break;
case V_125 :
V_2 -> V_4 -> V_123 = V_126 ;
break;
}
return 0 ;
}
if ( V_2 -> V_4 -> V_127 == V_128 )
return 0 ;
V_120 = F_51 ( V_129 , sizeof( * V_120 ) , V_20 ) ;
if ( ! V_120 )
return - V_56 ;
V_26 = F_73 ( V_2 , V_120 ) ;
F_7 ( V_120 ) ;
return V_26 ;
}
static bool F_74 ( struct V_1 * V_2 )
{
bool V_26 = false ;
if ( F_75 ( V_2 ) ) {
V_26 = true ;
} else if ( F_53 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_74 [ 0 ] &
V_130 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_119 * V_120 ;
int V_83 , V_26 = 0 , V_131 = 0 ;
T_3 V_123 ;
T_2 V_132 ;
V_120 = F_51 ( V_129 , sizeof( * V_120 ) , V_20 ) ;
if ( ! V_120 )
return - V_56 ;
V_26 = F_73 ( V_2 , V_120 ) ;
if ( V_26 )
goto V_133;
V_123 = V_2 -> V_4 -> V_123 ;
V_2 -> V_134 = F_5 ( sizeof( struct V_135 ) *
V_123 , V_20 ) ;
if ( ! V_2 -> V_134 ) {
V_26 = - V_56 ;
goto V_133;
}
V_2 -> V_136 = F_5 ( sizeof( struct V_137 ) *
V_126 , V_20 ) ;
if ( ! V_2 -> V_136 ) {
V_26 = - V_56 ;
goto V_138;
}
for ( V_83 = 0 ; V_83 < V_129 ; V_83 ++ ) {
V_132 = V_120 [ V_83 ] . V_71 ;
if ( V_132 >= V_129 ) {
V_26 = V_139 ;
goto V_140;
}
if ( ! V_120 [ V_83 ] . V_141 ||
( V_120 [ V_83 ] . type != V_142 ) )
continue;
if ( F_74 ( V_2 ) ) {
if ( ! F_77 ( V_2 , V_132 ) )
V_2 -> V_134 [ V_131 ] . V_143 = true ;
else
continue;
} else {
V_2 -> V_134 [ V_131 ] . V_143 = true ;
}
V_2 -> V_134 [ V_131 ] . V_27 = V_132 ;
V_2 -> V_134 [ V_131 ] . V_141 = ( T_2 ) V_120 [ V_83 ] . V_141 ;
V_2 -> V_134 [ V_131 ] . type = ( T_2 ) V_120 [ V_83 ] . type ;
V_2 -> V_134 [ V_131 ] . V_144 = ( T_2 ) V_120 [ V_83 ] . V_145 ;
V_2 -> V_134 [ V_131 ] . V_146 = V_120 [ V_83 ] . V_147 ;
V_2 -> V_134 [ V_131 ] . V_148 = V_120 [ V_83 ] . V_149 ;
V_131 ++ ;
}
if ( F_78 ( V_2 ) ) {
for ( V_83 = 0 ; V_83 < V_126 ; V_83 ++ )
V_2 -> V_136 [ V_83 ] . V_41 |= V_150 ;
} else if ( ! F_74 ( V_2 ) ) {
for ( V_83 = 0 ; V_83 < V_126 ; V_83 ++ )
F_79 ( V_2 , V_83 , 1 ) ;
}
F_7 ( V_120 ) ;
return 0 ;
V_140:
F_7 ( V_2 -> V_136 ) ;
V_2 -> V_136 = NULL ;
V_138:
F_7 ( V_2 -> V_134 ) ;
V_2 -> V_134 = NULL ;
V_133:
F_7 ( V_120 ) ;
return V_26 ;
}
static int
F_80 ( struct V_1 * V_2 )
{
T_2 V_71 ;
int V_26 ;
T_1 V_151 = V_128 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_26 = F_81 ( V_2 ) ;
if ( V_26 )
goto V_152;
V_71 = V_4 -> V_27 ;
V_151 = F_82 ( V_2 , V_153 ) ;
V_151 = ( V_151 & ~ F_83 ( 0xf , V_71 ) ) |
F_83 ( V_128 , V_71 ) ;
F_84 ( V_2 , V_153 , V_151 ) ;
F_85 ( V_2 ) ;
V_152:
return V_26 ;
}
static void F_86 ( struct V_1 * V_2 ,
const struct V_154 * V_155 )
{
T_1 V_127 , V_156 ;
V_2 -> V_4 -> V_157 = F_82 ( V_2 ,
V_158 ) ;
F_87 ( V_2 ) ;
V_127 = F_82 ( V_2 , V_153 ) ;
if ( V_127 == V_159 )
V_156 = V_128 ;
else
V_156 = F_88 ( V_127 , V_2 -> V_4 -> V_27 ) ;
if ( V_156 == V_160 ) {
V_2 -> V_4 -> V_127 = V_160 ;
F_55 ( & V_2 -> V_5 -> V_30 ,
L_9 ,
V_2 -> V_4 -> V_157 ) ;
V_2 -> V_161 = & V_162 ;
} else
V_2 -> V_161 = & V_163 ;
}
static void F_89 ( T_1 V_164 , T_4 * V_165 )
{
switch ( V_164 ) {
case V_7 :
* V_165 = V_166 ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
* V_165 = V_171 ;
break;
default:
* V_165 = 0 ;
}
}
static int F_90 ( struct V_23 * V_5 ,
struct V_3 * V_4 )
{
T_1 V_93 ;
void T_5 * V_172 = NULL ;
unsigned long V_173 , V_174 = 0 , V_175 ;
V_173 = F_91 ( V_5 , 0 ) ;
F_89 ( V_5 -> V_6 , & V_175 ) ;
if ( V_173 >= V_175 ) {
V_172 = F_92 ( V_5 , 0 ) ;
if ( V_172 == NULL ) {
F_65 ( & V_5 -> V_30 , L_10 ) ;
return - V_176 ;
}
V_174 = V_173 ;
} else {
return - V_176 ;
}
F_55 ( & V_5 -> V_30 , L_11 , ( int ) ( V_173 >> 10 ) ) ;
V_4 -> V_118 = V_172 ;
V_4 -> V_174 = V_174 ;
V_93 = F_93 ( F_94 ( V_4 -> V_27 ) ) ;
F_59 ( V_4 , V_93 ) ;
return 0 ;
}
static bool F_95 ( struct V_1 * V_2 ,
int V_177 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
unsigned short V_178 ;
bool V_26 = true ;
V_178 = V_5 -> V_178 ;
if ( V_5 -> V_6 == V_7 ||
V_5 -> V_6 == V_167 ) {
if ( V_179 [ V_177 ] . V_180 == V_178 &&
V_179 [ V_177 ] . V_181 == V_5 -> V_182 )
V_26 = true ;
else
V_26 = false ;
}
return V_26 ;
}
static void F_96 ( struct V_1 * V_2 , char * V_183 )
{
struct V_23 * V_5 = V_2 -> V_5 ;
int V_83 , V_184 = 0 ;
for ( V_83 = 0 ; V_83 < V_185 ; ++ V_83 ) {
if ( V_179 [ V_83 ] . V_186 == V_5 -> V_186 &&
V_179 [ V_83 ] . V_6 == V_5 -> V_6 &&
F_95 ( V_2 , V_83 ) ) {
V_184 = 1 ;
break;
}
}
if ( ! V_184 )
sprintf ( V_183 , L_12 , V_2 -> V_24 ) ;
else
sprintf ( V_183 , L_13 , V_2 -> V_24 ,
V_179 [ V_83 ] . V_187 ) ;
}
static void
F_97 ( struct V_1 * V_2 )
{
int V_51 ;
T_1 V_188 , V_189 , V_190 , V_191 ;
struct V_23 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_192 * V_193 = & V_4 -> V_193 ;
V_191 = V_2 -> V_194 ;
V_188 = F_82 ( V_2 , V_195 ) ;
V_189 = F_82 ( V_2 , V_196 ) ;
V_190 = F_82 ( V_2 , V_197 ) ;
V_2 -> V_194 = F_98 ( V_188 , V_189 , V_190 ) ;
V_51 = F_99 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_14 ) ;
return;
}
if ( V_4 -> V_127 != V_160 ) {
if ( V_193 -> V_198 == NULL ||
V_2 -> V_194 > V_191 ) {
if ( V_193 -> V_198 )
F_69 ( V_193 -> V_198 ) ;
if ( ! F_100 ( V_2 ) )
F_55 ( & V_5 -> V_30 ,
L_15 ) ;
}
}
F_55 ( & V_5 -> V_30 , L_16 ,
V_199 , V_188 , V_189 , V_190 ) ;
if ( V_2 -> V_4 -> V_121 == V_125 ) {
if ( V_2 -> V_41 & V_53 ) {
V_2 -> V_200 = V_201 ;
V_2 -> V_202 = V_203 ;
} else {
V_2 -> V_200 = V_204 ;
V_2 -> V_202 = V_205 ;
}
V_2 -> V_206 = V_207 ;
V_2 -> V_208 = V_207 ;
} else if ( V_2 -> V_4 -> V_121 == V_122 ) {
V_2 -> V_200 = V_209 ;
V_2 -> V_206 = V_210 ;
V_2 -> V_208 = V_210 ;
V_2 -> V_202 = V_211 ;
}
V_2 -> V_4 -> V_73 = ! ! V_102 ;
V_2 -> V_212 = V_213 ;
V_2 -> V_214 = V_215 ;
}
static int
F_101 ( struct V_1 * V_2 )
{
struct V_216 V_217 ;
int V_51 = 0 ;
memset ( & V_217 , 0 , sizeof( struct V_216 ) ) ;
V_51 = F_102 ( V_2 , & V_217 , V_2 -> V_4 -> V_27 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_4 -> V_218 = ( T_2 ) V_217 . V_219 ;
V_2 -> V_4 -> V_220 = V_217 . V_220 ;
V_2 -> V_4 -> V_221 = V_217 . V_221 ;
V_2 -> V_4 -> V_222 = V_217 . V_222 ;
V_2 -> V_4 -> V_8 = V_217 . V_8 ;
if ( V_2 -> V_4 -> V_8 & V_223 ) {
T_1 V_224 ;
V_224 = F_103 ( V_2 , V_225 , & V_51 ) ;
if ( V_51 == - V_176 )
return V_51 ;
V_2 -> V_4 -> V_74 [ 0 ] = V_224 ;
}
V_2 -> V_4 -> V_226 = V_217 . V_226 ;
V_2 -> V_4 -> V_227 = V_217 . V_227 ;
if ( F_53 ( V_2 ) )
return V_51 ;
if ( V_2 -> V_4 -> V_8 & V_228 )
V_2 -> V_41 |= V_53 ;
else
V_2 -> V_41 &= ~ V_53 ;
return V_51 ;
}
void F_104 ( struct V_1 * V_2 ,
struct V_229 * V_230 )
{
if ( V_230 -> V_231 )
V_2 -> V_41 &= ~ V_232 ;
else
V_2 -> V_41 |= V_232 ;
if ( V_230 -> V_233 ) {
V_2 -> V_234 = V_230 -> V_233 ;
V_2 -> V_235 = V_230 -> V_233 ;
} else {
V_2 -> V_234 = 0 ;
V_2 -> V_235 = 0 ;
}
}
static int
F_105 ( struct V_21 * V_22 , T_6 V_236 , T_3 V_237 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 ;
if ( F_19 ( V_2 ) ) {
V_51 = F_106 ( V_2 , V_237 , 1 ) ;
if ( V_51 ) {
F_107 ( V_22 ,
L_17 ,
V_237 , V_51 ) ;
return V_51 ;
}
}
F_108 ( V_237 , V_2 -> V_238 ) ;
return 0 ;
}
static int
F_109 ( struct V_21 * V_22 , T_6 V_236 , T_3 V_237 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_51 ;
if ( F_19 ( V_2 ) ) {
V_51 = F_106 ( V_2 , V_237 , 0 ) ;
if ( V_51 ) {
F_107 ( V_22 ,
L_18 ,
V_237 , V_51 ) ;
return V_51 ;
}
}
F_110 ( V_22 , V_239 ) ;
F_111 ( V_237 , V_2 -> V_238 ) ;
return 0 ;
}
void F_112 ( struct V_1 * V_2 ,
struct V_229 * V_230 )
{
V_2 -> V_41 &= ~ ( V_240 | V_42 |
V_241 ) ;
if ( V_230 -> V_242 )
V_2 -> V_41 |= V_240 ;
if ( ! V_230 -> V_243 )
V_2 -> V_41 |= V_42 ;
if ( ! V_230 -> V_244 )
V_2 -> V_41 |= V_241 ;
}
int F_113 ( struct V_1 * V_2 )
{
struct V_229 V_230 ;
if ( ! ( V_2 -> V_41 & V_53 ) )
return 0 ;
V_230 . V_27 = V_2 -> V_4 -> V_27 ;
if ( F_114 ( V_2 , & V_230 ) )
return - V_176 ;
F_104 ( V_2 , & V_230 ) ;
F_112 ( V_2 , & V_230 ) ;
F_115 ( V_2 , & V_230 ) ;
return 0 ;
}
void F_115 ( struct V_1 * V_2 ,
struct V_229 * V_230 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_53 ( V_2 ) )
return;
V_2 -> V_245 = V_230 -> V_245 ;
V_2 -> V_41 |= V_246 ;
F_116 ( V_22 ) ;
V_2 -> V_41 &= ~ V_246 ;
}
static int
F_117 ( struct V_1 * V_2 )
{
T_1 V_127 , V_156 ;
int V_51 = 0 ;
V_51 = F_101 ( V_2 ) ;
if ( V_51 )
return V_51 ;
if ( V_2 -> V_41 & V_247 )
return 0 ;
V_127 = F_82 ( V_2 , V_153 ) ;
V_156 = F_88 ( V_127 , V_2 -> V_4 -> V_27 ) ;
if ( V_127 == V_159 )
V_156 = V_128 ;
else
V_156 = F_88 ( V_127 , V_2 -> V_4 -> V_27 ) ;
if ( V_2 -> V_41 & V_53 ) {
if ( V_156 == V_128 ) {
V_2 -> V_4 -> V_127 = V_128 ;
V_51 = F_76 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_80 ( V_2 ) ;
F_55 ( & V_2 -> V_5 -> V_30 ,
L_19 ,
V_2 -> V_4 -> V_157 ) ;
} else if ( V_156 == V_248 ) {
V_2 -> V_4 -> V_127 = V_248 ;
F_55 ( & V_2 -> V_5 -> V_30 ,
L_20 ,
V_2 -> V_4 -> V_157 ) ;
}
}
V_2 -> V_41 |= V_247 ;
return V_51 ;
}
int F_118 ( struct V_1 * V_2 )
{
struct V_229 V_230 ;
struct V_135 * V_249 ;
T_2 V_83 ;
if ( V_2 -> V_250 )
return 0 ;
for ( V_83 = 0 ; V_83 < V_2 -> V_4 -> V_123 ; V_83 ++ ) {
if ( ! V_2 -> V_134 [ V_83 ] . V_143 )
continue;
memset ( & V_230 , 0 , sizeof( struct V_229 ) ) ;
V_230 . V_27 = V_2 -> V_134 [ V_83 ] . V_27 ;
V_230 . V_243 = V_251 ;
V_230 . V_244 = V_251 ;
if ( F_78 ( V_2 ) ) {
V_230 . V_245 = V_251 ;
if ( F_119 ( V_2 ) )
V_230 . V_245 |= ( V_252 | V_253 ) ;
}
if ( F_120 ( V_2 , & V_230 ) )
return - V_176 ;
V_249 = & V_2 -> V_134 [ V_83 ] ;
V_249 -> V_254 = V_230 . V_233 ;
V_249 -> V_243 = V_230 . V_243 ;
V_249 -> V_242 = V_230 . V_242 ;
V_249 -> V_231 = V_230 . V_231 ;
V_249 -> V_244 = V_230 . V_244 ;
V_249 -> V_245 = V_230 . V_245 ;
}
return 0 ;
}
static int
F_121 ( struct V_1 * V_2 ,
struct V_135 * V_249 , int V_27 )
{
struct V_229 V_230 ;
V_230 . V_127 = V_255 ;
V_230 . V_27 = V_27 ;
V_230 . V_233 = V_249 -> V_254 ;
V_230 . V_243 = V_249 -> V_243 ;
V_230 . V_231 = V_249 -> V_231 ;
V_230 . V_242 = V_249 -> V_242 ;
V_230 . V_245 = V_249 -> V_245 ;
V_230 . V_244 = V_249 -> V_244 ;
if ( F_120 ( V_2 , & V_230 ) )
return - V_176 ;
V_230 . V_127 = V_256 ;
if ( F_120 ( V_2 , & V_230 ) )
return - V_176 ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 )
{
int V_83 , V_51 ;
struct V_135 * V_249 ;
struct V_216 V_217 ;
T_2 V_27 ;
if ( F_78 ( V_2 ) )
if ( ! V_2 -> V_250 )
return 0 ;
for ( V_83 = 0 ; V_83 < V_2 -> V_4 -> V_123 ; V_83 ++ ) {
V_249 = & V_2 -> V_134 [ V_83 ] ;
V_27 = V_249 -> V_27 ;
if ( ! V_2 -> V_134 [ V_83 ] . V_143 )
continue;
memset ( & V_217 , 0 , sizeof( struct V_216 ) ) ;
V_51 = F_102 ( V_2 , & V_217 , V_27 ) ;
if ( V_51 )
return V_51 ;
V_217 . V_257 = V_249 -> V_146 ;
V_217 . V_258 = V_249 -> V_148 ;
V_51 = F_123 ( V_2 , & V_217 ) ;
if ( V_51 )
return V_51 ;
if ( V_249 -> V_259 ) {
V_51 = F_124 ( V_2 ,
V_249 -> V_260 , 1 ,
V_27 ) ;
if ( V_51 )
return V_51 ;
}
V_51 = F_121 ( V_2 , V_249 , V_27 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
T_2 V_261 = V_262 ;
T_1 V_263 ;
if ( V_2 -> V_4 -> V_127 == V_128 )
return 0 ;
V_263 = F_82 ( V_2 ,
V_264 ) ;
while ( V_263 != V_265 && -- V_261 ) {
F_126 ( 1000 ) ;
V_263 = F_82 ( V_2 ,
V_264 ) ;
}
if ( ! V_261 ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_21 ) ;
return - V_176 ;
}
return 0 ;
}
static int
F_127 ( struct V_1 * V_2 )
{
int V_51 ;
if ( ! ( V_2 -> V_41 & V_53 ) ||
V_2 -> V_4 -> V_127 != V_128 )
return 0 ;
V_51 = F_118 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_122 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_128 ( V_2 ) ;
return V_51 ;
}
int F_129 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_130 ( V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
else if ( ! V_51 )
goto V_266;
if ( V_267 )
F_131 ( V_2 ) ;
else {
V_51 = F_132 ( V_2 ) ;
if ( V_51 )
goto V_268;
V_2 -> V_4 -> V_269 = V_270 ;
}
V_51 = F_133 ( V_2 ) ;
if ( V_51 == 0 )
goto V_266;
V_51 = F_134 ( V_2 ) ;
if ( V_51 )
goto V_268;
V_51 = F_135 ( V_2 ) ;
if ( V_51 )
goto V_268;
F_136 ( V_2 ) ;
F_137 ( V_2 , V_271 , V_272 ) ;
V_266:
V_51 = F_138 ( V_2 ) ;
if ( V_51 )
goto V_268;
F_84 ( V_2 , V_273 , V_274 ) ;
F_139 ( V_2 , 1 ) ;
V_51 = F_117 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_22 ) ;
goto V_268;
}
V_51 = F_127 ( V_2 ) ;
if ( V_51 )
goto V_268;
F_97 ( V_2 ) ;
V_2 -> V_250 = 0 ;
F_136 ( V_2 ) ;
return 0 ;
V_268:
F_84 ( V_2 , V_273 , V_275 ) ;
F_65 ( & V_2 -> V_5 -> V_30 , L_23 ) ;
F_136 ( V_2 ) ;
return V_51 ;
}
static int
F_140 ( struct V_1 * V_2 )
{
T_7 V_276 ;
struct V_18 * V_277 ;
struct V_10 * V_11 ;
int V_51 , V_278 , V_279 ;
unsigned long V_41 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_91 == V_280 ) {
if ( F_78 ( V_2 ) )
V_276 = V_281 ;
else
V_276 = V_282 ;
if ( ! F_141 ( V_2 ) )
V_41 |= V_283 ;
} else {
if ( V_2 -> V_41 & V_88 )
V_276 = V_284 ;
else if ( V_2 -> V_41 & V_87 )
V_276 = V_285 ;
else {
V_41 |= V_283 ;
if ( F_78 ( V_2 ) )
V_276 = V_286 ;
else
V_276 = V_287 ;
}
}
V_2 -> V_101 = V_22 -> V_101 ;
if ( V_2 -> V_4 -> V_91 != V_288 ) {
if ( F_78 ( V_2 ) ||
( F_53 ( V_2 ) &&
( V_2 -> V_41 & V_88 ) ) ) {
V_279 = V_2 -> V_81 ;
for ( V_278 = 0 ; V_278 < V_279 ; V_278 ++ ) {
V_277 = & V_15 -> V_19 [ V_278 ] ;
if ( F_78 ( V_2 ) &&
! F_54 ( V_2 ) &&
( V_278 == ( V_279 - 1 ) ) ) {
if ( ! ( V_2 -> V_41 &
V_88 ) )
snprintf ( V_277 -> V_183 ,
sizeof( V_277 -> V_183 ) ,
L_24 ) ;
else
snprintf ( V_277 -> V_183 ,
sizeof( V_277 -> V_183 ) ,
L_25 ,
V_22 -> V_183 , V_278 ) ;
} else {
snprintf ( V_277 -> V_183 ,
sizeof( V_277 -> V_183 ) ,
L_26 ,
V_22 -> V_183 , V_278 ) ;
}
V_51 = F_142 ( V_277 -> V_101 , V_276 , V_41 ,
V_277 -> V_183 , V_277 ) ;
if ( V_51 )
return V_51 ;
}
}
if ( ( F_78 ( V_2 ) &&
F_54 ( V_2 ) ) ||
( F_53 ( V_2 ) &&
( V_2 -> V_41 & V_88 ) &&
! ( V_2 -> V_41 & V_84 ) ) ) {
V_276 = V_289 ;
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ;
V_278 ++ ) {
V_11 = & V_2 -> V_11 [ V_278 ] ;
snprintf ( V_11 -> V_183 , sizeof( V_11 -> V_183 ) ,
L_27 , V_22 -> V_183 , V_278 ) ;
V_51 = F_142 ( V_11 -> V_101 , V_276 , V_41 ,
V_11 -> V_183 , V_11 ) ;
if ( V_51 )
return V_51 ;
}
}
}
return 0 ;
}
static void
F_143 ( struct V_1 * V_2 )
{
int V_278 ;
struct V_18 * V_277 ;
struct V_10 * V_11 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_4 -> V_91 != V_288 ) {
if ( F_78 ( V_2 ) ||
( F_53 ( V_2 ) &&
( V_2 -> V_41 & V_88 ) ) ) {
for ( V_278 = 0 ; V_278 < V_2 -> V_81 ; V_278 ++ ) {
V_277 = & V_15 -> V_19 [ V_278 ] ;
F_144 ( V_277 -> V_101 , V_277 ) ;
}
}
if ( ( F_53 ( V_2 ) &&
! ( V_2 -> V_41 & V_84 ) ) ||
( F_78 ( V_2 ) &&
F_54 ( V_2 ) ) ) {
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ;
V_278 ++ ) {
V_11 = & V_2 -> V_11 [ V_278 ] ;
if ( V_11 -> V_101 )
F_144 ( V_11 -> V_101 , V_11 ) ;
}
}
}
}
static void F_145 ( struct V_1 * V_2 )
{
T_1 V_290 = 0 ;
if ( F_78 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_74 [ 0 ] &
V_291 )
V_2 -> V_41 |= V_292 ;
} else {
V_290 = V_2 -> V_4 -> V_8 ;
if ( F_146 ( V_290 ) )
V_2 -> V_41 |= V_292 ;
}
}
int F_147 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_278 ;
struct V_293 * V_294 ;
if ( V_2 -> V_295 != V_296 )
return - V_176 ;
if ( F_20 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
if ( F_113 ( V_2 ) )
return - V_176 ;
F_145 ( V_2 ) ;
if ( F_148 ( V_2 ) )
return - V_176 ;
for ( V_278 = 0 ; V_278 < V_2 -> V_214 ; V_278 ++ ) {
V_294 = & V_2 -> V_15 -> V_297 [ V_278 ] ;
F_149 ( V_2 , V_294 , V_278 ) ;
}
F_23 ( V_22 ) ;
F_150 ( V_2 , V_22 -> V_298 ) ;
V_2 -> V_4 -> V_299 = 0 ;
if ( V_2 -> V_81 > 1 )
F_151 ( V_2 , 1 ) ;
F_152 ( V_2 ) ;
if ( V_22 -> V_300 & V_301 )
F_153 ( V_2 , V_302 ) ;
F_108 ( V_45 , & V_2 -> V_46 ) ;
F_25 ( V_2 ) ;
F_154 ( V_2 , 1 ) ;
V_2 -> V_4 -> V_303 = 0 ;
return 0 ;
}
int F_155 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_51 = 0 ;
F_156 () ;
if ( F_157 ( V_22 ) )
V_51 = F_147 ( V_2 , V_22 ) ;
F_158 () ;
return V_51 ;
}
void F_159 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_278 ;
if ( V_2 -> V_295 != V_296 )
return;
if ( ! F_160 ( V_45 , & V_2 -> V_46 ) )
return;
if ( F_19 ( V_2 ) )
F_161 ( & V_2 -> V_4 -> V_304 -> V_305 ) ;
F_162 () ;
F_163 ( V_22 ) ;
V_2 -> V_4 -> V_299 = 0 ;
F_164 ( V_22 ) ;
F_165 ( V_2 ) ;
if ( V_2 -> V_306 . V_307 )
F_166 ( V_2 ) ;
F_167 ( V_2 , V_308 ) ;
F_22 ( V_2 ) ;
F_168 ( V_2 ) ;
V_2 -> V_41 &= ~ V_292 ;
F_169 ( V_2 ) ;
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ; V_278 ++ )
F_170 ( V_2 , & V_2 -> V_11 [ V_278 ] ) ;
}
void F_171 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
F_156 () ;
if ( F_157 ( V_22 ) )
F_159 ( V_2 , V_22 ) ;
F_158 () ;
}
int
F_172 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_5 = V_2 -> V_5 ;
int V_51 ;
if ( V_2 -> V_295 == V_296 )
return 0 ;
V_51 = F_173 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_174 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_28 ) ;
goto V_309;
}
V_51 = F_175 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_29 ) ;
goto V_310;
}
V_51 = F_140 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_30 ) ;
goto V_311;
}
F_176 ( V_2 ) ;
V_2 -> V_295 = V_296 ;
return 0 ;
V_311:
F_177 ( V_2 ) ;
V_310:
F_178 ( V_2 ) ;
V_309:
F_179 ( V_2 ) ;
return V_51 ;
}
void F_180 ( struct V_1 * V_2 )
{
if ( V_2 -> V_295 != V_296 )
return;
F_181 ( V_2 ) ;
F_177 ( V_2 ) ;
F_182 ( V_2 ) ;
F_143 ( V_2 ) ;
F_179 ( V_2 ) ;
F_178 ( V_2 ) ;
V_2 -> V_295 = 0 ;
}
void F_183 ( struct V_21 * V_22 , int V_81 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_18 * V_277 ;
int V_80 = V_2 -> V_78 ;
int V_278 ;
F_111 ( V_45 , & V_2 -> V_46 ) ;
if ( V_2 -> V_4 -> V_91 == V_280 ) {
for ( V_278 = 0 ; V_278 < V_2 -> V_81 ; V_278 ++ ) {
V_277 = & V_2 -> V_15 -> V_19 [ V_278 ] ;
F_184 ( V_277 ) ;
}
}
F_168 ( V_2 ) ;
F_180 ( V_2 ) ;
V_2 -> V_4 -> V_91 = 0 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_78 = V_80 ;
if ( F_172 ( V_2 ) )
goto V_312;
if ( F_157 ( V_22 ) )
F_147 ( V_2 , V_22 ) ;
V_312:
F_24 ( V_22 ) ;
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_51 = 0 ;
V_2 -> V_15 = F_5 ( sizeof( struct V_14 ) ,
V_20 ) ;
if ( ! V_2 -> V_15 ) {
V_51 = - V_56 ;
goto V_268;
}
V_4 -> V_313 . V_314 = V_315 ;
V_4 -> V_313 . type = V_316 ;
V_4 -> V_313 . V_317 = V_318 ;
V_4 -> V_313 . V_319 = V_320 ;
if ( F_53 ( V_2 ) ) {
V_4 -> V_313 . V_321 = V_322 ;
V_4 -> V_313 . V_323 = V_324 ;
}
memset ( & V_2 -> V_325 , 0 , sizeof( V_2 -> V_325 ) ) ;
V_268:
return V_51 ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_4 -> V_193 . V_198 ) {
F_69 ( V_2 -> V_4 -> V_193 . V_198 ) ;
V_2 -> V_4 -> V_193 . V_198 = NULL ;
}
F_7 ( V_2 -> V_4 -> V_326 . V_327 ) ;
V_2 -> V_4 -> V_193 . V_198 = NULL ;
}
int F_187 ( struct V_21 * V_22 , int V_328 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_18 * V_277 ;
struct V_293 * V_294 ;
int V_278 ;
int V_26 ;
F_21 ( V_22 ) ;
if ( F_157 ( V_22 ) )
F_159 ( V_2 , V_22 ) ;
F_180 ( V_2 ) ;
V_2 -> V_81 = 1 ;
V_2 -> V_4 -> V_91 = V_328 ;
V_2 -> V_4 -> V_299 = 0 ;
V_2 -> V_78 = 1 ;
V_26 = F_172 ( V_2 ) ;
if ( V_26 ) {
F_24 ( V_22 ) ;
return V_26 ;
}
V_26 = F_148 ( V_2 ) ;
if ( V_26 ) {
F_180 ( V_2 ) ;
F_24 ( V_22 ) ;
return V_26 ;
}
for ( V_278 = 0 ; V_278 < V_2 -> V_214 ; V_278 ++ ) {
V_294 = & V_2 -> V_15 -> V_297 [ V_278 ] ;
F_149 ( V_2 , V_294 , V_278 ) ;
}
if ( V_2 -> V_4 -> V_91 == V_280 ) {
for ( V_278 = 0 ; V_278 < V_2 -> V_81 ; V_278 ++ ) {
V_277 = & V_2 -> V_15 -> V_19 [ V_278 ] ;
F_188 ( V_277 ) ;
}
}
if ( V_2 -> V_4 -> V_91 == V_288 ) {
V_2 -> V_4 -> V_329 = 0 ;
F_154 ( V_2 , 1 ) ;
}
F_108 ( V_45 , & V_2 -> V_46 ) ;
return 0 ;
}
static int
F_189 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_43 ( V_62 , & V_2 -> V_46 ) )
return - V_330 ;
F_21 ( V_22 ) ;
F_171 ( V_2 , V_22 ) ;
F_155 ( V_2 , V_22 ) ;
F_24 ( V_22 ) ;
F_111 ( V_62 , & V_2 -> V_46 ) ;
F_65 ( & V_2 -> V_5 -> V_30 , L_31 , V_54 ) ;
return 0 ;
}
int
F_190 ( struct V_1 * V_2 )
{
int V_51 = 0 ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( F_43 ( V_62 , & V_2 -> V_46 ) )
return - V_330 ;
if ( V_2 -> V_295 == V_296 ) {
F_21 ( V_22 ) ;
if ( F_157 ( V_22 ) )
F_159 ( V_2 , V_22 ) ;
F_180 ( V_2 ) ;
if ( F_157 ( V_22 ) ) {
V_51 = F_172 ( V_2 ) ;
if ( ! V_51 ) {
F_147 ( V_2 , V_22 ) ;
F_110 ( V_22 , V_331 ) ;
}
}
F_24 ( V_22 ) ;
}
F_111 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
void F_191 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_332 = V_4 -> V_123 ;
T_3 V_16 ;
V_4 -> V_333 = V_334 ;
if ( V_332 <= 2 )
V_16 = ( V_335 - V_334 ) /
V_332 ;
else
V_16 = ( V_336 - V_334 ) /
V_332 ;
V_4 -> V_55 = V_16 ;
}
int
F_192 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_337 )
{
int V_51 ;
struct V_23 * V_5 = V_2 -> V_5 ;
V_2 -> V_338 = 1 ;
V_2 -> V_4 -> V_339 = 0 ;
F_193 ( V_2 ) ;
V_22 -> V_340 = & V_341 ;
V_22 -> V_342 = V_343 * V_344 ;
F_194 ( V_22 , V_22 -> V_298 ) ;
if ( F_19 ( V_2 ) )
F_195 ( V_22 , & V_345 ) ;
else
F_195 ( V_22 , & V_346 ) ;
V_22 -> V_300 |= ( V_347 | V_348 | V_349 |
V_350 | V_351 |
V_352 ) ;
V_22 -> V_353 |= ( V_347 | V_348 |
V_350 ) ;
if ( F_119 ( V_2 ) ) {
V_22 -> V_300 |= ( V_354 | V_355 ) ;
V_22 -> V_353 |= ( V_354 | V_355 ) ;
}
if ( V_337 ) {
V_22 -> V_300 |= V_356 ;
V_22 -> V_353 |= V_356 ;
}
if ( F_1 ( V_2 ) )
V_22 -> V_300 |= ( V_357 ) ;
if ( F_19 ( V_2 ) )
V_22 -> V_300 |= V_358 ;
if ( V_2 -> V_4 -> V_8 & V_359 )
V_22 -> V_300 |= V_301 ;
V_22 -> V_360 = V_22 -> V_300 ;
V_22 -> V_361 |= V_362 ;
V_22 -> V_101 = V_2 -> V_85 [ 0 ] . V_100 ;
V_51 = F_196 ( V_2 , V_22 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_197 ( V_22 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_32 ) ;
return V_51 ;
}
F_198 ( V_2 ) ;
return 0 ;
}
static int F_199 ( struct V_23 * V_5 , int * V_337 )
{
if ( ! F_200 ( V_5 , F_201 ( 64 ) ) &&
! F_202 ( V_5 , F_201 ( 64 ) ) )
* V_337 = 1 ;
else if ( ! F_200 ( V_5 , F_201 ( 32 ) ) &&
! F_202 ( V_5 , F_201 ( 32 ) ) )
* V_337 = 0 ;
else {
F_65 ( & V_5 -> V_30 , L_33 ) ;
return - V_176 ;
}
return 0 ;
}
void F_203 ( struct V_1 * V_2 )
{
int V_278 ;
struct V_10 * V_11 ;
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ; V_278 ++ ) {
V_11 = & V_2 -> V_11 [ V_278 ] ;
if ( V_11 && V_11 -> V_363 != NULL ) {
F_69 ( V_11 -> V_363 ) ;
V_11 -> V_363 = NULL ;
}
}
if ( V_2 -> V_11 != NULL )
F_7 ( V_2 -> V_11 ) ;
}
int F_204 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_278 , V_100 , V_177 ;
struct V_10 * V_11 ;
struct V_364 * V_363 ;
V_11 = F_51 ( V_2 -> V_78 ,
sizeof( struct V_10 ) , V_20 ) ;
if ( V_11 == NULL )
return - V_56 ;
V_2 -> V_11 = V_11 ;
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ; V_278 ++ ) {
V_11 = & V_2 -> V_11 [ V_278 ] ;
V_11 -> V_365 = V_2 -> V_212 ;
V_11 -> V_111 = F_205 ( V_22 , V_278 ) ;
V_363 = F_63 ( F_206 ( V_11 ) ) ;
if ( V_363 == NULL ) {
F_203 ( V_2 ) ;
return - V_56 ;
}
memset ( V_363 , 0 , F_206 ( V_11 ) ) ;
V_11 -> V_363 = V_363 ;
}
if ( F_53 ( V_2 ) ||
( F_78 ( V_2 ) && F_54 ( V_2 ) ) ) {
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ; V_278 ++ ) {
V_11 = & V_2 -> V_11 [ V_278 ] ;
V_11 -> V_2 = V_2 ;
if ( V_2 -> V_41 & V_88 ) {
V_177 = V_2 -> V_81 + V_278 ;
V_100 = V_2 -> V_85 [ V_177 ] . V_100 ;
V_11 -> V_101 = V_100 ;
}
}
}
return 0 ;
}
void F_207 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_366 = 0 ;
if ( F_78 ( V_2 ) )
V_366 = V_367 ;
else if ( F_53 ( V_2 ) )
V_366 = V_368 ;
if ( ( V_4 -> V_8 & V_223 ) &&
( V_4 -> V_74 [ 0 ] & V_369 ) )
F_208 ( V_2 , V_366 ) ;
}
static int F_209 ( struct V_1 * V_2 )
{
return F_210 ( V_2 ) ;
}
void F_211 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_370 ) ;
V_2 -> V_370 = NULL ;
}
static int
F_212 ( struct V_23 * V_5 , const struct V_154 * V_155 )
{
struct V_21 * V_22 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_4 ;
int V_51 , V_337 = - 1 ;
char V_371 [ V_372 + 19 ] ;
if ( V_5 -> V_373 )
return - V_374 ;
V_51 = F_213 ( V_5 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( F_214 ( V_5 , 0 ) & V_375 ) ) {
V_51 = - V_374 ;
goto V_376;
}
V_51 = F_199 ( V_5 , & V_337 ) ;
if ( V_51 )
goto V_376;
V_51 = F_215 ( V_5 , V_377 ) ;
if ( V_51 )
goto V_376;
F_216 ( V_5 ) ;
F_217 ( V_5 ) ;
V_4 = F_5 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 ) {
V_51 = - V_56 ;
goto V_378;
}
switch ( V_155 -> V_6 ) {
case V_7 :
V_4 -> V_379 = & V_380 ;
V_4 -> V_381 = ( T_1 * ) V_382 ;
break;
case V_167 :
case V_168 :
F_218 ( V_4 ) ;
break;
case V_169 :
case V_170 :
F_219 ( V_4 ) ;
break;
default:
goto V_383;
}
V_51 = F_90 ( V_5 , V_4 ) ;
if ( V_51 )
goto V_383;
V_22 = F_220 ( sizeof( struct V_1 ) ,
V_384 ) ;
if ( ! V_22 ) {
V_51 = - V_56 ;
goto V_385;
}
F_221 ( V_22 , & V_5 -> V_30 ) ;
V_2 = F_18 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_386 = F_222 ( L_24 ) ;
if ( V_2 -> V_386 == NULL ) {
V_51 = - V_56 ;
F_65 ( & V_5 -> V_30 , L_34 ) ;
goto V_387;
}
V_51 = F_185 ( V_2 ) ;
if ( V_51 )
goto V_388;
V_2 -> V_389 = V_390 ;
V_2 -> V_4 -> V_391 = V_5 -> V_392 ;
if ( V_393 == V_394 )
V_2 -> V_52 = true ;
else if ( V_393 == V_395 )
V_2 -> V_396 = true ;
F_223 ( & V_2 -> V_4 -> V_397 ) ;
F_224 ( & V_2 -> V_4 -> V_398 ) ;
F_225 ( & V_2 -> V_399 ) ;
F_209 ( V_2 ) ;
if ( F_78 ( V_2 ) ) {
F_86 ( V_2 , V_155 ) ;
V_2 -> V_400 = V_2 -> V_4 -> V_27 ;
V_51 = F_226 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_35
L_36 ) ;
goto V_401;
}
F_47 ( V_2 ) ;
if ( ( V_2 -> V_4 -> V_123 > 2 ) &&
F_54 ( V_2 ) ) {
V_2 -> V_78 = V_76 ;
F_55 ( & V_2 -> V_5 -> V_30 ,
L_37 ,
V_2 -> V_78 ) ;
}
if ( ! F_54 ( V_2 ) ) {
F_111 ( V_77 , & V_2 -> V_46 ) ;
V_2 -> V_78 = 1 ;
}
V_51 = F_227 ( V_2 ) ;
if ( V_51 )
goto V_311;
V_2 -> V_41 |= V_402 ;
if ( V_2 -> V_370 && F_228 ( V_2 ) )
F_211 ( V_2 ) ;
} else if ( F_53 ( V_2 ) ) {
V_2 -> V_78 = 1 ;
F_229 ( V_2 , V_155 ) ;
V_2 -> V_400 = V_2 -> V_4 -> V_27 ;
V_51 = F_230 ( V_2 , V_337 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_38 , V_54 ) ;
goto V_311;
}
if ( F_19 ( V_2 ) )
return 0 ;
} else {
F_65 ( & V_5 -> V_30 ,
L_39 , V_54 ) ;
goto V_311;
}
if ( F_8 ( V_2 ) )
F_11 ( & V_5 -> V_30 , L_40 ) ;
F_231 ( V_2 ) ;
if ( V_2 -> V_400 == 0 ) {
F_96 ( V_2 , V_371 ) ;
F_35 ( L_41 ,
F_232 ( V_403 ) ,
V_371 , V_2 -> V_4 -> V_391 ) ;
}
if ( F_53 ( V_2 ) && ! V_102 &&
! ! V_97 )
F_11 ( & V_5 -> V_30 ,
L_42 ) ;
if ( F_78 ( V_2 ) ) {
V_51 = F_233 ( V_2 , 0 , 0 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_43 ) ;
goto V_404;
}
}
V_51 = F_72 ( V_2 ) ;
if ( V_51 )
goto V_405;
V_51 = F_192 ( V_2 , V_22 , V_337 ) ;
if ( V_51 )
goto V_405;
if ( V_2 -> V_400 == 0 )
F_207 ( V_2 ) ;
F_234 ( V_5 , V_2 ) ;
if ( F_78 ( V_2 ) )
F_235 ( V_2 , V_406 ,
V_407 ) ;
switch ( V_2 -> V_4 -> V_121 ) {
case V_122 :
F_55 ( & V_2 -> V_5 -> V_30 , L_44 ,
V_2 -> V_22 -> V_183 ) ;
break;
case V_125 :
F_55 ( & V_2 -> V_5 -> V_30 , L_45 ,
V_2 -> V_22 -> V_183 ) ;
break;
}
if ( V_2 -> V_396 )
F_236 ( V_2 ) ;
F_237 ( V_2 ) ;
return 0 ;
V_405:
if ( F_53 ( V_2 ) )
F_238 ( V_2 ) ;
V_404:
F_66 ( V_2 ) ;
F_239 ( V_2 ) ;
F_240 ( V_2 , 0 ) ;
V_311:
F_186 ( V_2 ) ;
V_388:
F_241 ( V_2 -> V_386 ) ;
V_387:
F_242 ( V_22 ) ;
V_385:
F_70 ( V_4 ) ;
V_383:
F_7 ( V_4 ) ;
V_378:
F_243 ( V_5 ) ;
V_376:
F_234 ( V_5 , NULL ) ;
F_244 ( V_5 ) ;
return V_51 ;
V_401:
V_22 -> V_340 = & V_408 ;
F_195 ( V_22 , & V_409 ) ;
V_51 = F_197 ( V_22 ) ;
if ( V_51 ) {
F_65 ( & V_5 -> V_30 , L_46 ) ;
F_240 ( V_2 , 0 ) ;
goto V_311;
}
F_234 ( V_5 , V_2 ) ;
F_237 ( V_2 ) ;
return 0 ;
}
static void F_245 ( struct V_23 * V_5 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
V_2 = F_246 ( V_5 ) ;
if ( V_2 == NULL )
return;
V_22 = V_2 -> V_22 ;
F_247 ( V_2 ) ;
F_239 ( V_2 ) ;
V_4 = V_2 -> V_4 ;
F_248 ( V_2 ) ;
F_249 ( V_22 ) ;
F_250 ( V_2 ) ;
if ( F_53 ( V_2 ) ) {
F_251 ( V_2 , 0 ) ;
F_45 ( & V_2 -> V_410 ) ;
F_238 ( V_2 ) ;
F_252 ( V_2 ) ;
F_253 ( V_4 -> V_411 ) ;
F_7 ( V_4 -> V_412 ) ;
}
F_180 ( V_2 ) ;
if ( V_2 -> V_134 != NULL )
F_7 ( V_2 -> V_134 ) ;
if ( V_2 -> V_136 != NULL )
F_7 ( V_2 -> V_136 ) ;
if ( F_78 ( V_2 ) )
F_240 ( V_2 , 0 ) ;
F_111 ( V_62 , & V_2 -> V_46 ) ;
F_254 ( V_2 ) ;
F_66 ( V_2 ) ;
F_255 ( V_2 ) ;
F_70 ( V_2 -> V_4 ) ;
F_136 ( V_2 ) ;
F_256 ( V_5 ) ;
F_243 ( V_5 ) ;
F_244 ( V_5 ) ;
F_234 ( V_5 , NULL ) ;
if ( V_2 -> V_386 ) {
F_241 ( V_2 -> V_386 ) ;
V_2 -> V_386 = NULL ;
}
F_186 ( V_2 ) ;
F_7 ( V_4 ) ;
F_242 ( V_22 ) ;
}
static void F_257 ( struct V_23 * V_5 )
{
if ( F_258 ( V_5 ) )
return;
F_244 ( V_5 ) ;
}
static int F_259 ( struct V_23 * V_5 , T_8 V_46 )
{
int V_413 ;
V_413 = F_258 ( V_5 ) ;
if ( V_413 )
return V_413 ;
F_260 ( V_5 , F_261 ( V_5 , V_46 ) ) ;
return 0 ;
}
static int F_262 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_246 ( V_5 ) ;
int V_51 ;
V_51 = F_213 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_260 ( V_5 , V_414 ) ;
F_216 ( V_5 ) ;
F_263 ( V_5 ) ;
return F_264 ( V_2 ) ;
}
static int F_265 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
T_1 V_46 ;
int V_51 ;
V_46 = F_82 ( V_2 , V_273 ) ;
if ( V_46 == V_275 || V_46 == V_415 ) {
F_107 ( V_22 , L_47 , V_54 ) ;
return - V_176 ;
}
F_163 ( V_22 ) ;
V_51 = F_172 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_147 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_268;
F_266 ( V_22 ) ;
return 0 ;
V_268:
F_180 ( V_2 ) ;
return V_51 ;
}
static int F_267 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
F_159 ( V_2 , V_22 ) ;
return 0 ;
}
void F_236 ( struct V_1 * V_2 )
{
void * V_34 ;
int V_83 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_416 = 0 ;
T_3 V_123 = 0 ;
if ( V_2 -> V_306 . V_417 && V_2 -> V_306 . V_418 )
return;
V_123 = V_2 -> V_4 -> V_123 ;
F_268 ( & V_2 -> V_419 ) ;
F_268 ( & V_2 -> V_420 ) ;
if ( F_78 ( V_2 ) ) {
V_416 = V_336 ;
V_2 -> V_306 . V_421 = V_422 ;
} else {
V_416 = V_423 ;
V_2 -> V_306 . V_421 = V_424 ;
}
V_34 = F_51 ( V_2 -> V_306 . V_421 ,
sizeof( struct V_425 ) , V_426 ) ;
if ( ! V_34 )
return;
V_2 -> V_306 . V_417 = ( V_416 / V_123 ) ;
V_2 -> V_306 . V_418 = V_34 ;
F_269 ( V_22 , L_48 ,
V_123 , V_2 -> V_306 . V_417 ) ;
for ( V_83 = 0 ; V_83 < V_2 -> V_306 . V_421 ; V_83 ++ )
F_270 ( & V_2 -> V_306 . V_418 [ V_83 ] ) ;
V_2 -> V_427 . V_421 = V_2 -> V_306 . V_421 ;
V_34 = F_51 ( V_2 -> V_427 . V_421 ,
sizeof( struct V_425 ) , V_426 ) ;
if ( ! V_34 )
return;
V_2 -> V_427 . V_417 = ( V_416 / V_123 ) ;
V_2 -> V_427 . V_418 = V_34 ;
for ( V_83 = 0 ; V_83 < V_2 -> V_427 . V_421 ; V_83 ++ )
F_270 ( & V_2 -> V_427 . V_418 [ V_83 ] ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( V_2 -> V_306 . V_417 && V_2 -> V_306 . V_418 )
F_7 ( V_2 -> V_306 . V_418 ) ;
V_2 -> V_306 . V_418 = NULL ;
V_2 -> V_306 . V_417 = 0 ;
if ( V_2 -> V_427 . V_417 && V_2 -> V_427 . V_418 )
F_7 ( V_2 -> V_427 . V_418 ) ;
V_2 -> V_427 . V_417 = 0 ;
V_2 -> V_427 . V_418 = NULL ;
}
int F_271 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_428 , V_429 , V_224 = 0 ;
int V_430 = 0 ;
if ( F_53 ( V_2 ) )
V_224 = F_272 ( V_2 -> V_4 , V_431 ) ;
if ( F_78 ( V_2 ) )
V_224 = F_82 ( V_2 , V_432 ) ;
V_428 = F_273 ( V_224 ) ;
V_429 = F_274 ( V_224 ) ;
if ( V_428 == V_433 ) {
F_65 ( & V_22 -> V_30 ,
L_49
L_50 ,
V_429 ) ;
V_430 = 1 ;
} else if ( V_428 == V_434 ) {
if ( V_2 -> V_4 -> V_224 == V_435 ) {
F_65 ( & V_22 -> V_30 ,
L_51
L_52
L_53 ,
V_429 ) ;
}
} else {
if ( V_2 -> V_4 -> V_224 == V_434 ) {
F_55 ( & V_22 -> V_30 ,
L_54
L_55 , V_429 ) ;
}
}
V_2 -> V_4 -> V_224 = V_428 ;
return V_430 ;
}
static void F_275 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_10 * V_11 ;
int V_278 ;
if ( F_20 ( V_62 , & V_2 -> V_46 ) )
return;
if ( ++ V_2 -> V_436 >= V_437 ) {
F_269 ( V_22 , L_56 ) ;
if ( F_78 ( V_2 ) )
V_2 -> V_250 = 1 ;
else if ( F_53 ( V_2 ) )
F_276 ( V_2 ,
V_438 ) ;
} else {
F_269 ( V_22 , L_57 ) ;
if ( F_78 ( V_2 ) ) {
for ( V_278 = 0 ; V_278 < V_2 -> V_78 ;
V_278 ++ ) {
V_11 = & V_2 -> V_11 [ V_278 ] ;
F_55 ( & V_22 -> V_30 , L_58 , V_278 ) ;
F_55 ( & V_22 -> V_30 , L_59 ,
F_277 ( V_11 -> V_439 ) ) ;
F_55 ( & V_22 -> V_30 , L_60 ,
F_277 ( V_11 -> V_13 ) ) ;
F_55 ( & V_22 -> V_30 , L_61 ,
V_11 -> V_440 ) ;
F_55 ( & V_22 -> V_30 , L_62 ,
F_278 ( * ( V_11 -> V_441 ) ) ) ;
F_55 ( & V_22 -> V_30 , L_63 ,
V_11 -> V_442 ) ;
F_55 ( & V_22 -> V_30 , L_64 ,
V_11 -> V_443 ) ;
}
}
V_2 -> V_4 -> V_303 = 1 ;
}
}
static struct V_444 * F_279 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_444 * V_325 = & V_22 -> V_325 ;
V_325 -> V_319 = V_2 -> V_325 . V_445 + V_2 -> V_325 . V_446 ;
V_325 -> V_323 = V_2 -> V_325 . V_447 ;
V_325 -> V_448 = V_2 -> V_325 . V_449 + V_2 -> V_325 . V_450 ;
V_325 -> V_451 = V_2 -> V_325 . V_452 ;
V_325 -> V_453 = V_2 -> V_325 . V_454 ;
V_325 -> V_455 = V_2 -> V_325 . V_456 ;
return V_325 ;
}
T_9 F_280 ( struct V_1 * V_2 )
{
T_1 V_457 ;
V_457 = F_277 ( V_2 -> V_106 ) ;
if ( ! ( V_457 & V_2 -> V_4 -> V_104 ) )
return V_458 ;
V_457 = F_277 ( V_2 -> V_108 ) ;
if ( ! F_281 ( V_457 ) )
return V_458 ;
F_3 ( 0xffffffff , V_2 -> V_99 ) ;
F_277 ( V_2 -> V_106 ) ;
F_277 ( V_2 -> V_106 ) ;
return V_459 ;
}
static T_9 V_281 ( int V_101 , void * V_151 )
{
struct V_18 * V_277 = V_151 ;
struct V_1 * V_2 = V_277 -> V_2 ;
if ( V_2 -> V_41 & V_88 )
goto V_460;
else if ( V_2 -> V_41 & V_87 ) {
F_3 ( 0xffffffff , V_2 -> V_99 ) ;
goto V_460;
}
if ( F_282 ( V_2 ) == V_458 )
return V_458 ;
V_460:
V_2 -> V_4 -> V_461 ++ ;
F_188 ( V_277 ) ;
return V_459 ;
}
static T_9 V_286 ( int V_101 , void * V_151 )
{
struct V_18 * V_277 = V_151 ;
struct V_1 * V_2 = V_277 -> V_2 ;
if ( F_282 ( V_2 ) == V_458 )
return V_458 ;
F_283 ( & V_277 -> V_462 ) ;
return V_459 ;
}
static T_9 V_285 ( int V_101 , void * V_151 )
{
struct V_18 * V_277 = V_151 ;
struct V_1 * V_2 = V_277 -> V_2 ;
F_3 ( 0xffffffff , V_2 -> V_99 ) ;
F_283 ( & V_277 -> V_462 ) ;
return V_459 ;
}
static T_9 V_284 ( int V_101 , void * V_151 )
{
struct V_18 * V_277 = V_151 ;
F_283 ( & V_277 -> V_462 ) ;
return V_459 ;
}
static T_9 V_289 ( int V_101 , void * V_151 )
{
struct V_10 * V_11 = V_151 ;
F_283 ( & V_11 -> V_462 ) ;
return V_459 ;
}
static void F_284 ( struct V_21 * V_22 )
{
int V_278 ;
struct V_18 * V_277 ;
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_285 ( V_2 -> V_101 ) ;
for ( V_278 = 0 ; V_278 < V_2 -> V_81 ; V_278 ++ ) {
V_277 = & V_15 -> V_19 [ V_278 ] ;
V_286 ( V_2 -> V_101 , V_277 ) ;
}
F_286 ( V_2 -> V_101 ) ;
}
static void
F_139 ( struct V_1 * V_2 , T_2 V_463 )
{
T_1 V_464 ;
V_464 = V_2 -> V_400 & 0xf ;
V_464 |= V_463 << 7 ;
V_464 |= ( V_390 - V_2 -> V_389 ) << 8 ;
F_84 ( V_2 , V_465 , V_464 ) ;
V_2 -> V_389 = V_390 ;
}
static int
F_287 ( struct V_1 * V_2 , T_2 V_46 )
{
T_1 V_464 ;
F_288 ( V_46 != V_466 &&
V_46 != V_467 ) ;
if ( F_81 ( V_2 ) )
return - V_176 ;
V_464 = F_82 ( V_2 , V_468 ) ;
if ( V_46 == V_466 )
F_289 ( V_464 , V_2 -> V_400 ) ;
else if ( V_46 == V_467 )
F_290 ( V_464 , V_2 -> V_400 ) ;
F_84 ( V_2 , V_468 , V_464 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int
F_291 ( struct V_1 * V_2 )
{
T_1 V_464 ;
if ( F_81 ( V_2 ) )
return - V_330 ;
V_464 = F_82 ( V_2 , V_468 ) ;
F_292 ( V_464 , V_2 -> V_400 ) ;
F_84 ( V_2 , V_468 , V_464 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
void F_240 ( struct V_1 * V_2 , T_2 V_469 )
{
T_1 V_464 ;
if ( F_81 ( V_2 ) )
goto V_51;
V_464 = F_82 ( V_2 , V_470 ) ;
F_293 ( V_464 , V_2 -> V_400 ) ;
F_84 ( V_2 , V_470 , V_464 ) ;
if ( V_469 ) {
F_84 ( V_2 , V_273 ,
V_275 ) ;
F_55 ( & V_2 -> V_5 -> V_30 ,
L_65 ) ;
} else if ( ! ( V_464 & 0x11111111 ) )
F_84 ( V_2 , V_273 ,
V_471 ) ;
V_464 = F_82 ( V_2 , V_468 ) ;
F_292 ( V_464 , V_2 -> V_400 ) ;
F_84 ( V_2 , V_468 , V_464 ) ;
F_85 ( V_2 ) ;
V_51:
V_2 -> V_472 = 0 ;
V_2 -> V_41 &= ~ V_473 ;
F_111 ( V_474 , & V_2 -> V_46 ) ;
F_111 ( V_62 , & V_2 -> V_46 ) ;
}
static int
F_294 ( struct V_1 * V_2 )
{
int V_475 , V_46 , V_476 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_46 = F_82 ( V_2 , V_468 ) ;
V_475 = F_82 ( V_2 , V_470 ) ;
if ( V_2 -> V_41 & V_477 ) {
V_476 = ( ~ ( 1 << ( V_4 -> V_27 * 4 ) ) ) ;
V_475 = V_475 & V_476 ;
}
if ( ( ( V_46 & 0x11111111 ) == ( V_475 & 0x11111111 ) ) ||
( ( V_475 & 0x11111111 ) == ( ( V_46 >> 1 ) & 0x11111111 ) ) )
return 0 ;
else
return 1 ;
}
static int F_295 ( struct V_1 * V_2 )
{
T_1 V_464 = F_82 ( V_2 , V_478 ) ;
if ( V_464 != V_479 ) {
F_11 ( & V_2 -> V_5 -> V_30 , L_66
L_67 , V_479 , V_464 ) ;
}
return 0 ;
}
static int
F_130 ( struct V_1 * V_2 )
{
T_1 V_464 , V_480 ;
T_2 V_481 = V_2 -> V_481 ;
T_2 V_400 = V_2 -> V_400 ;
T_2 V_26 ;
if ( F_160 ( V_474 , & V_2 -> V_46 ) )
return 1 ;
if ( F_81 ( V_2 ) )
return - 1 ;
V_464 = F_82 ( V_2 , V_470 ) ;
if ( ! ( V_464 & ( 1 << ( V_400 * 4 ) ) ) ) {
F_296 ( V_464 , V_400 ) ;
F_84 ( V_2 , V_470 , V_464 ) ;
}
V_480 = F_82 ( V_2 , V_273 ) ;
F_297 ( V_2 , V_482 , L_68 , V_480 ) ;
switch ( V_480 ) {
case V_471 :
F_84 ( V_2 , V_273 ,
V_483 ) ;
F_84 ( V_2 , V_478 ,
V_479 ) ;
F_139 ( V_2 , 0 ) ;
F_85 ( V_2 ) ;
return 1 ;
case V_274 :
V_26 = F_295 ( V_2 ) ;
F_85 ( V_2 ) ;
return V_26 ;
case V_466 :
V_464 = F_82 ( V_2 , V_468 ) ;
F_289 ( V_464 , V_400 ) ;
F_84 ( V_2 , V_468 , V_464 ) ;
break;
case V_467 :
V_464 = F_82 ( V_2 , V_468 ) ;
F_290 ( V_464 , V_400 ) ;
F_84 ( V_2 , V_468 , V_464 ) ;
break;
case V_275 :
F_65 ( & V_2 -> V_5 -> V_30 , L_69 ) ;
F_85 ( V_2 ) ;
return - 1 ;
case V_483 :
case V_484 :
break;
}
F_85 ( V_2 ) ;
do {
F_126 ( 1000 ) ;
V_480 = F_82 ( V_2 , V_273 ) ;
if ( V_480 == V_484 )
continue;
} while ( ( V_480 != V_274 ) && -- V_481 );
if ( ! V_481 ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_70 ) ;
return - 1 ;
}
if ( F_81 ( V_2 ) )
return - 1 ;
V_464 = F_82 ( V_2 , V_468 ) ;
F_292 ( V_464 , V_400 ) ;
F_84 ( V_2 , V_468 , V_464 ) ;
V_26 = F_295 ( V_2 ) ;
F_85 ( V_2 ) ;
return V_26 ;
}
static void
F_298 ( struct V_485 * V_64 )
{
struct V_1 * V_2 = F_299 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
T_1 V_486 = 0xf ;
T_1 V_464 ;
if ( F_81 ( V_2 ) )
goto V_487;
V_486 = F_82 ( V_2 , V_273 ) ;
if ( V_486 == V_484 ||
V_486 == V_467 ) {
F_85 ( V_2 ) ;
F_235 ( V_2 , F_298 ,
V_407 * 2 ) ;
return;
}
if ( V_2 -> V_4 -> V_127 == V_160 ) {
F_85 ( V_2 ) ;
goto V_488;
}
if ( V_486 == V_483 ||
V_486 == V_274 ) {
F_55 ( & V_2 -> V_5 -> V_30 , L_71
L_72 ) ;
goto V_489;
}
if ( V_2 -> V_490 ++ > V_2 -> V_491 ) {
F_55 ( & V_2 -> V_5 -> V_30 , L_73 ,
V_2 -> V_491 ) ;
goto V_489;
}
if ( ! F_294 ( V_2 ) ) {
V_489:
V_486 = F_82 ( V_2 , V_273 ) ;
if ( V_486 == V_466 ) {
F_84 ( V_2 , V_273 ,
V_483 ) ;
F_108 ( V_474 , & V_2 -> V_46 ) ;
F_297 ( V_2 , V_492 , L_74 ) ;
F_139 ( V_2 , 0 ) ;
V_464 = F_82 ( V_2 ,
V_468 ) ;
F_289 ( V_464 , V_2 -> V_400 ) ;
F_84 ( V_2 ,
V_468 , V_464 ) ;
}
F_85 ( V_2 ) ;
F_156 () ;
if ( F_300 ( V_2 ) &&
( V_2 -> V_41 & V_477 ) ) {
F_297 ( V_2 , V_492 , L_75 ) ;
F_301 ( V_2 ) ;
V_2 -> V_41 |= V_473 ;
}
F_158 () ;
V_2 -> V_41 &= ~ V_477 ;
if ( ! V_2 -> V_161 -> V_493 ( V_2 ) ) {
F_235 ( V_2 , V_494 , 0 ) ;
V_2 -> V_490 = 0 ;
return;
}
goto V_487;
}
F_85 ( V_2 ) ;
V_488:
V_486 = F_82 ( V_2 , V_273 ) ;
F_297 ( V_2 , V_482 , L_76 , V_486 ) ;
switch ( V_486 ) {
case V_274 :
if ( ! F_226 ( V_2 ) ) {
F_235 ( V_2 , V_494 , 0 ) ;
V_2 -> V_490 = 0 ;
return;
}
case V_275 :
break;
default:
F_235 ( V_2 ,
F_298 , V_407 ) ;
return;
}
V_487:
F_65 ( & V_2 -> V_5 -> V_30 , L_77
L_78 , V_486 , V_2 -> V_490 ) ;
F_24 ( V_2 -> V_22 ) ;
F_240 ( V_2 , 0 ) ;
}
static void
F_302 ( struct V_485 * V_64 )
{
struct V_1 * V_2 = F_299 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_457 ;
F_21 ( V_22 ) ;
if ( V_2 -> V_486 == V_467 ) {
if ( F_157 ( V_22 ) )
F_159 ( V_2 , V_22 ) ;
} else
F_171 ( V_2 , V_22 ) ;
V_457 = F_82 ( V_2 , V_495 ) ;
if ( V_457 & V_496 ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_79 ,
V_457 ) ;
if ( F_303 ( V_457 ) == V_497 ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_80
L_81 ) ;
F_65 ( & V_2 -> V_5 -> V_30 ,
L_82 ) ;
}
goto V_487;
}
if ( V_2 -> V_4 -> V_224 == V_433 ) {
F_65 ( & V_2 -> V_5 -> V_30 , L_83 ,
V_2 -> V_4 -> V_224 ) ;
goto V_487;
}
if ( ! ( V_2 -> V_41 & V_477 ) ) {
if ( F_287 ( V_2 , V_2 -> V_486 ) ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_84
L_85 ) ;
goto V_487;
}
}
V_2 -> V_490 = 0 ;
F_235 ( V_2 , F_298 , V_407 ) ;
return;
V_487:
F_24 ( V_22 ) ;
F_240 ( V_2 , 1 ) ;
}
static void
F_304 ( struct V_1 * V_2 )
{
T_1 V_46 ;
V_46 = F_82 ( V_2 , V_264 ) ;
if ( V_46 == V_498 )
return;
if ( F_81 ( V_2 ) )
return;
F_84 ( V_2 , V_264 ,
V_498 ) ;
F_85 ( V_2 ) ;
}
void F_305 ( struct V_1 * V_2 , T_1 V_499 )
{
T_1 V_46 , V_500 = 0 , V_501 = 0 ;
F_306 ( V_500 ) ;
F_307 ( V_500 ) ;
F_137 ( V_2 , V_502 , V_500 ) ;
F_308 ( V_501 ) ;
F_309 ( V_501 ) ;
F_310 ( V_501 ) ;
F_311 ( V_501 ) ;
F_137 ( V_2 , V_503 , V_501 ) ;
F_55 ( & V_2 -> V_5 -> V_30 , L_86
L_87 ) ;
V_2 -> V_250 = 1 ;
if ( F_81 ( V_2 ) )
return;
V_46 = F_82 ( V_2 , V_273 ) ;
if ( V_46 == V_275 || V_46 == V_415 ) {
F_107 ( V_2 -> V_22 , L_47 ,
V_54 ) ;
F_85 ( V_2 ) ;
return;
}
if ( V_46 == V_274 ) {
F_84 ( V_2 , V_273 ,
V_466 ) ;
V_2 -> V_41 |= V_477 ;
F_297 ( V_2 , V_492 , L_88 ) ;
F_139 ( V_2 , 0 ) ;
}
F_84 ( V_2 , V_264 ,
V_498 ) ;
F_85 ( V_2 ) ;
}
static void
F_128 ( struct V_1 * V_2 )
{
if ( F_81 ( V_2 ) )
return;
F_84 ( V_2 , V_264 ,
V_265 ) ;
F_297 ( V_2 , V_492 , L_89 ) ;
F_85 ( V_2 ) ;
}
void F_235 ( struct V_1 * V_2 ,
T_10 V_65 , int V_504 )
{
if ( F_20 ( V_505 , & V_2 -> V_46 ) )
return;
F_312 ( & V_2 -> V_63 , V_65 ) ;
F_313 ( V_2 -> V_386 , & V_2 -> V_63 ,
F_314 ( V_504 ) ) ;
}
static void
V_494 ( struct V_485 * V_64 )
{
struct V_1 * V_2 = F_299 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_1 V_263 ;
if ( V_2 -> V_4 -> V_127 != V_128 ) {
V_263 = F_82 ( V_2 ,
V_264 ) ;
if ( V_2 -> V_490 ++ > V_262 )
F_240 ( V_2 , 0 ) ;
else if ( V_263 != V_265 )
F_235 ( V_2 , V_494 ,
V_407 ) ;
else
goto V_506;
F_297 ( V_2 , V_492 , L_90 ) ;
return;
}
V_506:
F_315 ( V_2 ) ;
if ( F_157 ( V_22 ) ) {
if ( F_155 ( V_2 , V_22 ) )
goto V_460;
F_110 ( V_22 , V_331 ) ;
}
V_460:
F_24 ( V_22 ) ;
V_2 -> V_472 = 0 ;
V_2 -> V_41 &= ~ V_473 ;
F_111 ( V_62 , & V_2 -> V_46 ) ;
if ( V_2 -> V_400 == 0 )
F_207 ( V_2 ) ;
if ( ! F_291 ( V_2 ) )
F_235 ( V_2 , V_406 ,
V_407 ) ;
}
static int
F_316 ( struct V_1 * V_2 )
{
T_1 V_46 = 0 , V_507 ;
T_1 V_508 ;
int V_51 = 0 ;
if ( F_271 ( V_2 ) )
goto V_509;
if ( V_2 -> V_250 )
F_317 ( V_2 , 0 ) ;
V_46 = F_82 ( V_2 , V_273 ) ;
if ( V_46 == V_466 ) {
F_304 ( V_2 ) ;
V_2 -> V_250 = 1 ;
} else if ( V_46 == V_467 )
goto V_509;
V_507 = F_82 ( V_2 , V_510 ) ;
if ( V_507 != V_2 -> V_507 ) {
V_2 -> V_507 = V_507 ;
V_2 -> V_472 = 0 ;
if ( V_2 -> V_250 )
goto V_509;
if ( V_2 -> V_4 -> V_303 && V_511 )
F_189 ( V_2 ) ;
return 0 ;
}
if ( ++ V_2 -> V_472 < V_512 )
return 0 ;
V_2 -> V_41 |= V_473 ;
F_317 ( V_2 , 0 ) ;
if ( V_511 )
F_111 ( V_513 , & V_2 -> V_46 ) ;
F_65 ( & V_2 -> V_5 -> V_30 , L_91 ) ;
V_508 = F_82 ( V_2 , V_495 ) ;
F_65 ( & V_2 -> V_5 -> V_30 , L_92
L_93
L_94
L_95
L_96 ,
V_508 ,
F_82 ( V_2 , V_514 ) ,
F_103 ( V_2 , V_515 + 0x3c , & V_51 ) ,
F_103 ( V_2 , V_516 + 0x3c , & V_51 ) ,
F_103 ( V_2 , V_517 + 0x3c , & V_51 ) ,
F_103 ( V_2 , V_518 + 0x3c , & V_51 ) ,
F_103 ( V_2 , V_519 + 0x3c , & V_51 ) ) ;
if ( F_303 ( V_508 ) == 0x67 )
F_65 ( & V_2 -> V_5 -> V_30 ,
L_97
L_98 ) ;
V_509:
V_2 -> V_486 = ( V_46 == V_467 ) ? V_46 :
V_466 ;
if ( V_511 && ! F_43 ( V_62 ,
& V_2 -> V_46 ) ) {
F_235 ( V_2 , F_302 , 0 ) ;
F_297 ( V_2 , V_492 , L_99 ) ;
}
return 1 ;
}
void V_406 ( struct V_485 * V_64 )
{
struct V_1 * V_2 = F_299 ( V_64 ,
struct V_1 , V_63 . V_64 ) ;
if ( F_20 ( V_62 , & V_2 -> V_46 ) )
goto V_520;
if ( F_316 ( V_2 ) )
return;
if ( V_2 -> V_306 . V_307 )
F_318 ( V_2 ) ;
V_520:
F_235 ( V_2 , V_406 , V_407 ) ;
}
static int F_319 ( struct V_23 * V_5 )
{
struct V_23 * V_521 ;
int V_464 = V_5 -> V_522 ;
while ( V_464 -- > 0 ) {
V_521 = F_320 ( F_321
( V_5 -> V_523 ) , V_5 -> V_523 -> V_524 ,
F_322 ( F_323 ( V_5 -> V_522 ) , V_464 ) ) ;
if ( ! V_521 )
continue;
if ( V_521 -> V_525 != V_526 ) {
F_324 ( V_521 ) ;
return 0 ;
}
F_324 ( V_521 ) ;
}
return 1 ;
}
static int F_325 ( struct V_23 * V_5 )
{
int V_51 , V_527 ;
struct V_1 * V_2 = F_246 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_528 = V_529 ;
V_51 = F_213 ( V_5 ) ;
if ( V_51 )
return V_51 ;
F_216 ( V_5 ) ;
F_263 ( V_5 ) ;
V_527 = F_319 ( V_5 ) ;
if ( F_81 ( V_2 ) )
return - V_40 ;
if ( V_2 -> V_4 -> V_127 != V_160 && V_527 ) {
V_2 -> V_250 = 1 ;
F_108 ( V_474 , & V_2 -> V_46 ) ;
F_84 ( V_2 , V_273 ,
V_483 ) ;
F_297 ( V_2 , V_492 , L_74 ) ;
}
F_85 ( V_2 ) ;
V_51 = F_226 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_291 ( V_2 ) ;
F_7 ( V_2 -> V_85 ) ;
V_2 -> V_85 = NULL ;
V_51 = F_233 ( V_2 , 0 , 0 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_85 ) ;
F_107 ( V_22 , L_30 ) ;
return V_51 ;
}
if ( F_157 ( V_22 ) ) {
V_51 = F_172 ( V_2 ) ;
if ( V_51 ) {
F_240 ( V_2 , 1 ) ;
F_111 ( V_505 , & V_2 -> V_46 ) ;
F_24 ( V_22 ) ;
return V_51 ;
}
V_51 = F_155 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_460;
F_110 ( V_22 , V_331 ) ;
}
V_460:
F_24 ( V_22 ) ;
return V_51 ;
}
T_11 F_326 ( struct V_23 * V_5 ,
T_12 V_46 )
{
struct V_1 * V_2 = F_246 ( V_5 ) ;
struct V_21 * V_22 = V_2 -> V_22 ;
if ( V_46 == V_530 )
return V_531 ;
if ( V_46 == V_529 )
return V_532 ;
F_108 ( V_505 , & V_2 -> V_46 ) ;
F_21 ( V_22 ) ;
F_45 ( & V_2 -> V_63 ) ;
if ( F_157 ( V_22 ) )
F_171 ( V_2 , V_22 ) ;
F_180 ( V_2 ) ;
F_66 ( V_2 ) ;
F_111 ( V_62 , & V_2 -> V_46 ) ;
F_327 ( V_5 ) ;
F_244 ( V_5 ) ;
return V_533 ;
}
T_11 F_328 ( struct V_23 * V_5 )
{
return F_325 ( V_5 ) ? V_531 :
V_532 ;
}
void F_329 ( struct V_23 * V_5 )
{
T_1 V_46 ;
struct V_1 * V_2 = F_246 ( V_5 ) ;
F_330 ( V_5 ) ;
V_46 = F_82 ( V_2 , V_273 ) ;
if ( V_46 == V_274 && F_160 ( V_505 ,
& V_2 -> V_46 ) )
F_235 ( V_2 , V_406 ,
V_407 ) ;
}
static T_11 F_331 ( struct V_23 * V_5 ,
T_12 V_46 )
{
struct V_1 * V_2 = F_246 ( V_5 ) ;
struct V_534 * V_379 = V_2 -> V_4 -> V_379 ;
if ( V_379 -> V_535 ) {
return V_379 -> V_535 ( V_5 , V_46 ) ;
} else {
F_65 ( & V_5 -> V_30 , L_100 ) ;
return V_531 ;
}
}
static T_11 F_332 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_246 ( V_5 ) ;
struct V_534 * V_379 = V_2 -> V_4 -> V_379 ;
if ( V_379 -> V_536 ) {
return V_379 -> V_536 ( V_5 ) ;
} else {
F_65 ( & V_5 -> V_30 , L_101 ) ;
return V_531 ;
}
}
static void F_333 ( struct V_23 * V_5 )
{
struct V_1 * V_2 = F_246 ( V_5 ) ;
struct V_534 * V_379 = V_2 -> V_4 -> V_379 ;
if ( V_379 -> V_537 )
V_379 -> V_537 ( V_5 ) ;
else
F_65 ( & V_5 -> V_30 , L_102 ) ;
}
static int
F_334 ( struct V_1 * V_2 )
{
int V_51 ;
V_51 = F_130 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_125 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_101 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_97 ( V_2 ) ;
V_51 = F_113 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_250 = 0 ;
return V_51 ;
}
int F_335 ( struct V_1 * V_2 , T_1 V_111 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_538 = V_384 ;
T_1 V_539 ;
if ( ! V_102 && ! V_97 ) {
F_107 ( V_22 , L_103 ) ;
return - V_40 ;
}
if ( ! F_54 ( V_2 ) ) {
F_107 ( V_22 , L_104 ) ;
return - V_40 ;
}
if ( V_111 > V_384 ) {
F_107 ( V_22 , L_105 ) ;
return - V_40 ;
}
V_539 = F_56 ( F_48 ( int , V_538 ,
F_49 () ) ) ;
if ( ( V_111 > V_539 ) || ! F_336 ( V_111 ) ) {
if ( ! F_336 ( V_111 ) )
F_107 ( V_22 ,
L_106 ) ;
if ( V_111 > F_49 () )
F_107 ( V_22 ,
L_107 ,
F_49 () ) ;
F_107 ( V_22 , L_108 , V_111 ) ;
return - V_40 ;
}
return 0 ;
}
int F_337 ( struct V_1 * V_2 ,
T_13 V_464 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_2 V_538 = V_2 -> V_4 -> V_222 ;
T_1 V_539 ;
if ( ! V_102 && ! V_97 ) {
F_107 ( V_22 , L_109 ) ;
return - V_40 ;
}
if ( V_464 > V_540 ) {
F_107 ( V_22 , L_110 ,
V_540 ) ;
return - V_40 ;
}
V_539 = F_56 ( F_48 ( int , V_538 ,
F_49 () ) ) ;
if ( ( V_464 > V_539 ) || ( V_464 < 2 ) || ! F_336 ( V_464 ) ) {
if ( ! F_336 ( V_464 ) )
F_107 ( V_22 , L_111 ) ;
if ( V_464 < 2 )
F_107 ( V_22 , L_112 ) ;
if ( V_464 > V_538 )
F_107 ( V_22 ,
L_113 ,
V_538 ) ;
if ( V_464 > F_49 () )
F_107 ( V_22 ,
L_114 ,
F_49 () ) ;
F_107 ( V_22 , L_115 , V_464 ) ;
return - V_40 ;
}
return 0 ;
}
int F_338 ( struct V_1 * V_2 , T_2 V_151 , int V_111 )
{
int V_51 ;
struct V_21 * V_22 = V_2 -> V_22 ;
int V_79 ;
if ( F_20 ( V_62 , & V_2 -> V_46 ) )
return - V_330 ;
if ( F_78 ( V_2 ) && ! V_102 &&
! V_97 ) {
F_107 ( V_22 , L_109 ) ;
return - V_40 ;
}
F_21 ( V_22 ) ;
if ( F_157 ( V_22 ) )
F_159 ( V_2 , V_22 ) ;
F_180 ( V_2 ) ;
if ( F_78 ( V_2 ) ) {
if ( V_111 != 0 )
V_2 -> V_78 = V_111 ;
if ( F_54 ( V_2 ) &&
( V_111 > V_2 -> V_78 ) )
V_79 = V_2 -> V_78 ;
else
V_79 = V_151 ;
}
if ( F_53 ( V_2 ) ) {
F_238 ( V_2 ) ;
F_339 ( V_2 ) ;
}
F_340 ( V_22 , V_2 -> V_78 ) ;
F_66 ( V_2 ) ;
V_51 = F_233 ( V_2 , V_151 , V_111 ) ;
if ( V_51 ) {
F_7 ( V_2 -> V_85 ) ;
F_107 ( V_22 , L_30 ) ;
return V_51 ;
}
if ( F_53 ( V_2 ) ) {
F_251 ( V_2 , 1 ) ;
V_51 = F_341 ( V_2 ) ;
F_342 ( V_2 ) ;
if ( V_51 ) {
F_65 ( & V_2 -> V_5 -> V_30 ,
L_116 ) ;
goto V_460;
}
}
if ( F_157 ( V_22 ) ) {
V_51 = F_172 ( V_2 ) ;
if ( V_51 )
goto V_460;
V_51 = F_147 ( V_2 , V_22 ) ;
if ( V_51 )
goto V_460;
F_110 ( V_22 , V_331 ) ;
}
V_460:
F_24 ( V_22 ) ;
F_111 ( V_62 , & V_2 -> V_46 ) ;
return V_51 ;
}
static void
F_343 ( struct V_1 * V_2 ,
struct V_21 * V_30 , unsigned long V_541 )
{
struct V_542 * V_543 ;
V_543 = F_344 ( V_30 ) ;
if ( ! V_543 )
return;
F_345 (indev) {
switch ( V_541 ) {
case V_331 :
F_346 ( V_2 ,
V_544 -> V_545 , V_546 ) ;
break;
case V_239 :
F_346 ( V_2 ,
V_544 -> V_545 , V_547 ) ;
break;
default:
break;
}
} F_347 ( V_543 ) ;
F_348 ( V_543 ) ;
}
void F_110 ( struct V_21 * V_22 , unsigned long V_541 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_21 * V_30 ;
T_3 V_237 ;
F_343 ( V_2 , V_22 , V_541 ) ;
F_349 () ;
F_350 (vid, adapter->vlans, VLAN_N_VID) {
V_30 = F_351 ( V_22 , F_352 ( V_548 ) , V_237 ) ;
if ( ! V_30 )
continue;
F_343 ( V_2 , V_30 , V_541 ) ;
}
F_353 () ;
}
static int F_354 ( struct V_549 * V_550 ,
unsigned long V_541 , void * V_551 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 = F_355 ( V_551 ) ;
V_552:
if ( V_30 == NULL )
goto V_460;
if ( V_30 -> V_361 & V_553 ) {
V_30 = F_356 ( V_30 ) ;
goto V_552;
}
if ( ! F_357 ( V_30 ) )
goto V_460;
V_2 = F_18 ( V_30 ) ;
if ( ! V_2 )
goto V_460;
if ( ! F_20 ( V_45 , & V_2 -> V_46 ) )
goto V_460;
F_343 ( V_2 , V_30 , V_541 ) ;
V_460:
return V_554 ;
}
static int
F_358 ( struct V_549 * V_550 ,
unsigned long V_541 , void * V_551 )
{
struct V_1 * V_2 ;
struct V_21 * V_30 ;
struct V_555 * V_544 = (struct V_555 * ) V_551 ;
V_30 = V_544 -> V_556 ? V_544 -> V_556 -> V_30 : NULL ;
V_552:
if ( V_30 == NULL )
goto V_460;
if ( V_30 -> V_361 & V_553 ) {
V_30 = F_356 ( V_30 ) ;
goto V_552;
}
if ( ! F_357 ( V_30 ) )
goto V_460;
V_2 = F_18 ( V_30 ) ;
if ( ! V_2 )
goto V_460;
if ( ! F_20 ( V_45 , & V_2 -> V_46 ) )
goto V_460;
switch ( V_541 ) {
case V_331 :
F_346 ( V_2 , V_544 -> V_545 , V_546 ) ;
break;
case V_239 :
F_346 ( V_2 , V_544 -> V_545 , V_547 ) ;
break;
default:
break;
}
V_460:
return V_554 ;
}
void F_110 ( struct V_21 * V_30 , unsigned long V_541 )
{ }
static int T_14 F_359 ( void )
{
int V_26 ;
F_360 ( V_557 L_117 , V_558 ) ;
#ifdef F_361
F_362 ( & V_559 ) ;
F_363 ( & V_560 ) ;
#endif
V_26 = F_364 ( & V_561 ) ;
if ( V_26 ) {
#ifdef F_361
F_365 ( & V_560 ) ;
F_366 ( & V_559 ) ;
#endif
}
return V_26 ;
}
static void T_15 F_367 ( void )
{
F_368 ( & V_561 ) ;
#ifdef F_361
F_365 ( & V_560 ) ;
F_366 ( & V_559 ) ;
#endif
}
