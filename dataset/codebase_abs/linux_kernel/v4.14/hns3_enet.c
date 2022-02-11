static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_3 * V_9 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 ; V_10 ++ ) {
V_9 = & V_8 -> V_4 [ V_10 ] ;
if ( V_9 -> V_12 != V_13 )
continue;
F_4 ( V_9 -> V_14 , V_9 ) ;
V_9 -> V_12 = V_15 ;
}
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_3 * V_9 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
unsigned int V_10 ;
int V_19 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 ; V_10 ++ ) {
V_9 = & V_8 -> V_4 [ V_10 ] ;
if ( V_9 -> V_12 == V_13 )
continue;
if ( V_9 -> V_20 . V_21 && V_9 -> V_22 . V_21 ) {
snprintf ( V_9 -> V_23 , V_24 - 1 ,
L_1 , V_8 -> V_25 -> V_23 , L_2 ,
V_16 ++ ) ;
V_16 ++ ;
} else if ( V_9 -> V_22 . V_21 ) {
snprintf ( V_9 -> V_23 , V_24 - 1 ,
L_1 , V_8 -> V_25 -> V_23 , L_3 ,
V_17 ++ ) ;
} else if ( V_9 -> V_20 . V_21 ) {
snprintf ( V_9 -> V_23 , V_24 - 1 ,
L_1 , V_8 -> V_25 -> V_23 , L_4 ,
V_18 ++ ) ;
} else {
continue;
}
V_9 -> V_23 [ V_24 - 1 ] = '\0' ;
V_19 = F_6 ( V_9 -> V_14 , F_1 , 0 ,
V_9 -> V_23 ,
V_9 ) ;
if ( V_19 ) {
F_7 ( V_8 -> V_25 , L_5 ,
V_9 -> V_14 ) ;
return V_19 ;
}
V_9 -> V_12 = V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_3 * V_4 ,
T_2 V_26 )
{
F_9 ( V_26 , V_4 -> V_27 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_5 ) ;
F_8 ( V_4 , 1 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
F_8 ( V_4 , 0 ) ;
F_13 ( V_4 -> V_14 ) ;
F_14 ( & V_4 -> V_5 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
T_2 V_28 )
{
F_9 ( V_28 , V_4 -> V_27 + V_29 ) ;
F_9 ( V_28 , V_4 -> V_27 + V_30 ) ;
F_9 ( V_28 , V_4 -> V_27 + V_31 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
T_2 V_32 )
{
F_9 ( V_32 , V_4 -> V_27 + V_33 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
V_4 -> V_22 . V_34 = V_35 ;
V_4 -> V_20 . V_34 = V_35 ;
F_15 ( V_4 , V_35 ) ;
F_16 ( V_4 , 0 ) ;
V_4 -> V_22 . V_36 = V_37 ;
V_4 -> V_20 . V_36 = V_37 ;
}
static int F_18 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
int V_10 , V_42 ;
int V_19 ;
V_19 = F_5 ( V_8 ) ;
if ( V_19 ) {
F_7 ( V_25 , L_6 , V_19 ) ;
return V_19 ;
}
for ( V_10 = 0 ; V_10 < V_8 -> V_11 ; V_10 ++ )
F_10 ( & V_8 -> V_4 [ V_10 ] ) ;
V_19 = V_40 -> V_43 -> V_44 -> V_45 ? V_40 -> V_43 -> V_44 -> V_45 ( V_40 ) : 0 ;
if ( V_19 )
goto V_46;
return 0 ;
V_46:
for ( V_42 = V_10 - 1 ; V_42 >= 0 ; V_42 -- )
F_12 ( & V_8 -> V_4 [ V_42 ] ) ;
F_3 ( V_8 ) ;
return V_19 ;
}
static int F_20 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
int V_19 ;
F_21 ( V_25 ) ;
V_19 = F_22 ( V_25 , V_40 -> V_47 . V_48 ) ;
if ( V_19 ) {
F_7 ( V_25 ,
L_7 ,
V_19 ) ;
return V_19 ;
}
V_19 = F_23 ( V_25 , V_40 -> V_47 . V_48 ) ;
if ( V_19 ) {
F_7 ( V_25 ,
L_8 , V_19 ) ;
return V_19 ;
}
V_19 = F_18 ( V_25 ) ;
if ( V_19 ) {
F_7 ( V_25 ,
L_9 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static void F_24 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
const struct V_49 * V_44 ;
int V_10 ;
V_44 = V_8 -> V_41 -> V_43 -> V_44 ;
if ( V_44 -> V_50 )
V_44 -> V_50 ( V_8 -> V_41 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 ; V_10 ++ )
F_12 ( & V_8 -> V_4 [ V_10 ] ) ;
F_3 ( V_8 ) ;
}
static int F_25 ( struct V_38 * V_25 )
{
F_26 ( V_25 ) ;
F_21 ( V_25 ) ;
F_24 ( V_25 ) ;
return 0 ;
}
void F_27 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_51 * V_52 = NULL ;
if ( V_40 -> V_43 -> V_44 -> V_53 ) {
F_28 (ha, netdev)
if ( V_40 -> V_43 -> V_44 -> V_53 ( V_40 , V_52 -> V_54 ) )
F_7 ( V_25 , L_10 ) ;
}
}
static int F_29 ( struct V_38 * V_25 ,
const unsigned char * V_54 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( V_40 -> V_43 -> V_44 -> V_55 )
return V_40 -> V_43 -> V_44 -> V_55 ( V_40 , V_54 ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_25 ,
const unsigned char * V_54 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( V_40 -> V_43 -> V_44 -> V_56 )
return V_40 -> V_43 -> V_44 -> V_56 ( V_40 , V_54 ) ;
return 0 ;
}
static int F_31 ( struct V_38 * V_25 ,
const unsigned char * V_54 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( V_40 -> V_43 -> V_44 -> V_57 )
return V_40 -> V_43 -> V_44 -> V_57 ( V_40 , V_54 ) ;
return 0 ;
}
static int F_32 ( struct V_38 * V_25 ,
const unsigned char * V_54 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( V_40 -> V_43 -> V_44 -> V_58 )
return V_40 -> V_43 -> V_44 -> V_58 ( V_40 , V_54 ) ;
return 0 ;
}
void F_33 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( V_40 -> V_43 -> V_44 -> V_59 ) {
if ( V_25 -> V_60 & V_61 )
V_40 -> V_43 -> V_44 -> V_59 ( V_40 , 1 ) ;
else
V_40 -> V_43 -> V_44 -> V_59 ( V_40 , 0 ) ;
}
if ( F_34 ( V_25 , F_29 , F_30 ) )
F_7 ( V_25 , L_11 ) ;
if ( V_25 -> V_60 & V_62 )
if ( F_35 ( V_25 , F_31 , F_32 ) )
F_7 ( V_25 , L_12 ) ;
}
static int F_36 ( struct V_63 * V_64 , T_2 * V_65 ,
T_3 * V_66 , T_2 * V_67 )
{
T_2 V_68 , V_69 ;
union V_70 V_71 ;
union V_72 V_73 ;
T_2 V_74 ;
int V_19 ;
if ( ! F_37 ( V_64 ) )
return 0 ;
V_19 = F_38 ( V_64 , 0 ) ;
if ( V_19 )
return V_19 ;
V_71 . V_75 = F_39 ( V_64 ) ;
V_73 . V_75 = F_40 ( V_64 ) ;
if ( V_71 . V_76 -> V_77 == 4 )
V_71 . V_76 -> V_78 = 0 ;
if ( F_41 ( V_64 ) -> V_79 & ( V_80 |
V_81 |
V_82 |
V_83 ) ) {
if ( ( ! ( F_41 ( V_64 ) -> V_79 &
V_84 ) ) &&
( F_41 ( V_64 ) -> V_79 &
V_83 ) ) {
V_73 . V_85 -> V_78 = 0 ;
}
V_71 . V_75 = F_42 ( V_64 ) ;
V_73 . V_75 = F_43 ( V_64 ) ;
if ( V_71 . V_76 -> V_77 == 4 )
V_71 . V_76 -> V_78 = 0 ;
}
V_68 = V_73 . V_75 - V_64 -> V_86 ;
V_69 = ( V_73 . V_87 -> V_88 * 4 ) + V_68 ;
V_74 = V_64 -> V_89 - V_68 ;
F_44 ( & V_73 . V_87 -> V_78 ,
( V_90 V_91 ) F_45 ( V_74 ) ) ;
* V_65 = V_64 -> V_89 - V_69 ;
F_46 ( * V_67 ,
V_92 , 1 ) ;
* V_66 = F_41 ( V_64 ) -> V_93 ;
return 0 ;
}
static int F_47 ( struct V_63 * V_64 , T_4 * V_94 ,
T_4 * V_95 )
{
union {
struct V_96 * V_76 ;
struct V_97 * V_98 ;
unsigned char * V_75 ;
} V_71 ;
unsigned char * V_99 ;
unsigned char * V_100 ;
T_4 V_101 ;
T_5 V_102 ;
V_71 . V_75 = F_39 ( V_64 ) ;
V_99 = F_43 ( V_64 ) ;
if ( V_64 -> V_103 == F_48 ( V_104 ) ) {
V_100 = V_71 . V_75 + sizeof( * V_71 . V_98 ) ;
V_101 = V_71 . V_98 -> V_105 ;
if ( V_99 != V_100 )
F_49 ( V_64 , V_100 - V_64 -> V_86 ,
& V_101 , & V_102 ) ;
} else if ( V_64 -> V_103 == F_48 ( V_106 ) ) {
V_101 = V_71 . V_76 -> V_103 ;
} else {
return - V_107 ;
}
* V_94 = V_101 ;
if ( ! V_64 -> V_108 ) {
* V_95 = 0 ;
return 0 ;
}
V_71 . V_75 = F_42 ( V_64 ) ;
V_99 = F_43 ( V_64 ) ;
if ( V_71 . V_98 -> V_77 == 6 ) {
V_100 = V_71 . V_75 + sizeof( * V_71 . V_98 ) ;
V_101 = V_71 . V_98 -> V_105 ;
if ( V_99 != V_100 )
F_49 ( V_64 , V_100 - V_64 -> V_86 ,
& V_101 , & V_102 ) ;
} else if ( V_71 . V_76 -> V_77 == 4 ) {
V_101 = V_71 . V_76 -> V_103 ;
}
* V_95 = V_101 ;
return 0 ;
}
static void F_50 ( struct V_63 * V_64 , T_4 V_94 ,
T_4 V_95 , T_2 * V_67 ,
T_2 * V_109 )
{
union {
struct V_96 * V_76 ;
struct V_97 * V_98 ;
unsigned char * V_75 ;
} V_71 ;
union {
struct V_110 * V_87 ;
struct V_111 * V_85 ;
struct V_112 * V_113 ;
unsigned char * V_75 ;
} V_73 ;
unsigned char * V_114 ;
T_4 V_115 = V_94 ;
T_2 V_116 ;
T_2 V_117 ;
T_2 V_118 ;
T_2 V_119 ;
T_2 V_120 ;
V_71 . V_75 = F_39 ( V_64 ) ;
V_73 . V_75 = F_40 ( V_64 ) ;
V_119 = V_71 . V_75 - V_64 -> V_86 ;
F_51 ( * V_67 , V_121 ,
V_122 , V_119 >> 1 ) ;
if ( V_64 -> V_108 ) {
V_116 = V_119 ;
F_51 ( * V_109 ,
V_121 ,
V_122 , V_116 >> 1 ) ;
V_117 = V_73 . V_75 - V_71 . V_75 ;
F_51 ( * V_109 , V_123 ,
V_124 , V_117 >> 2 ) ;
if ( ( V_94 == V_125 ) || ( V_94 == V_126 ) ) {
V_114 = F_52 ( V_64 ) ;
V_118 = V_114 - V_73 . V_75 ;
F_51 ( * V_109 , V_127 ,
V_128 , V_118 >> 2 ) ;
V_71 . V_75 = F_42 ( V_64 ) ;
V_119 = V_71 . V_75 - V_114 ;
F_51 ( * V_67 , V_121 ,
V_122 , V_119 >> 1 ) ;
} else {
return;
}
V_73 . V_75 = F_43 ( V_64 ) ;
V_115 = V_95 ;
}
V_120 = V_73 . V_75 - V_71 . V_75 ;
F_51 ( * V_67 , V_123 ,
V_124 , V_120 >> 2 ) ;
switch ( V_115 ) {
case V_129 :
F_51 ( * V_67 , V_127 ,
V_128 , V_73 . V_87 -> V_88 ) ;
break;
case V_130 :
F_51 ( * V_67 , V_127 ,
V_128 , ( sizeof( struct V_131 ) >> 2 ) ) ;
break;
case V_125 :
F_51 ( * V_67 , V_127 ,
V_128 , ( sizeof( struct V_111 ) >> 2 ) ) ;
break;
default:
return;
}
}
static int F_53 ( struct V_63 * V_64 , T_4 V_94 ,
T_4 V_95 , T_2 * V_67 ,
T_2 * V_109 )
{
union {
struct V_96 * V_76 ;
struct V_97 * V_98 ;
unsigned char * V_75 ;
} V_71 ;
T_2 V_115 = V_94 ;
V_71 . V_75 = F_39 ( V_64 ) ;
if ( V_64 -> V_108 ) {
if ( V_64 -> V_103 == F_48 ( V_106 ) ) {
if ( F_37 ( V_64 ) )
F_51 ( * V_109 ,
V_132 , V_133 ,
V_134 ) ;
else
F_51 ( * V_109 ,
V_132 , V_133 ,
V_135 ) ;
} else if ( V_64 -> V_103 == F_48 ( V_104 ) ) {
F_51 ( * V_109 , V_132 ,
V_133 , V_136 ) ;
}
switch ( V_115 ) {
case V_125 :
F_51 ( * V_109 ,
V_137 ,
V_138 ,
V_139 ) ;
break;
case V_126 :
F_51 ( * V_109 ,
V_137 ,
V_138 ,
V_140 ) ;
break;
default:
if ( F_37 ( V_64 ) )
return - V_141 ;
F_54 ( V_64 ) ;
return 0 ;
}
V_71 . V_75 = F_42 ( V_64 ) ;
V_115 = V_95 ;
}
if ( V_71 . V_76 -> V_77 == 4 ) {
F_51 ( * V_67 , V_142 ,
V_143 , V_144 ) ;
if ( F_37 ( V_64 ) )
F_46 ( * V_67 , V_145 , 1 ) ;
F_46 ( * V_67 , V_146 , 1 ) ;
} else if ( V_71 . V_98 -> V_77 == 6 ) {
F_51 ( * V_67 , V_142 ,
V_143 , V_147 ) ;
F_46 ( * V_67 , V_146 , 1 ) ;
}
switch ( V_115 ) {
case V_129 :
F_51 ( * V_67 ,
V_148 ,
V_149 ,
V_150 ) ;
break;
case V_125 :
F_51 ( * V_67 ,
V_148 ,
V_149 ,
V_151 ) ;
break;
case V_130 :
F_51 ( * V_67 ,
V_148 ,
V_149 ,
V_152 ) ;
break;
default:
if ( F_37 ( V_64 ) )
return - V_141 ;
F_54 ( V_64 ) ;
return 0 ;
}
return 0 ;
}
static void F_55 ( T_3 * V_153 , int V_154 )
{
F_51 ( * V_153 , V_155 ,
V_155 , 0 ) ;
F_46 ( * V_153 , V_156 , ! ! V_154 ) ;
F_46 ( * V_153 , V_157 , 1 ) ;
F_51 ( * V_153 , V_158 , V_159 , 1 ) ;
}
static int F_56 ( struct V_160 * V_21 , void * V_8 ,
int V_161 , T_6 V_162 , int V_154 ,
enum V_163 type )
{
struct V_164 * V_165 = & V_21 -> V_165 [ V_21 -> V_166 ] ;
struct V_167 * V_168 = & V_21 -> V_168 [ V_21 -> V_166 ] ;
T_2 V_109 = 0 ;
T_3 V_153 = 0 ;
T_2 V_67 = 0 ;
struct V_63 * V_64 ;
T_2 V_65 = 0 ;
T_3 V_66 = 0 ;
T_5 V_103 ;
T_4 V_94 ;
T_4 V_95 ;
int V_19 ;
V_165 -> V_8 = V_8 ;
V_165 -> V_169 = V_161 ;
V_165 -> V_162 = V_162 ;
V_165 -> type = type ;
V_168 -> V_54 = F_57 ( V_162 ) ;
V_168 -> V_170 . V_171 = F_58 ( ( T_3 ) V_161 ) ;
F_55 ( & V_153 , V_154 ) ;
V_168 -> V_170 . V_153 = F_58 ( V_153 ) ;
if ( type == V_172 ) {
V_64 = (struct V_63 * ) V_8 ;
V_65 = F_58 ( V_64 -> V_89 ) ;
if ( V_64 -> V_173 == V_174 ) {
F_59 ( V_64 ) ;
V_103 = V_64 -> V_103 ;
if ( V_103 == F_48 ( V_175 ) ) {
V_103 = F_60 ( V_64 ) ;
V_64 -> V_103 = V_103 ;
}
V_19 = F_47 ( V_64 , & V_94 , & V_95 ) ;
if ( V_19 )
return V_19 ;
F_50 ( V_64 , V_94 , V_95 ,
& V_67 ,
& V_109 ) ;
V_19 = F_53 ( V_64 , V_94 , V_95 ,
& V_67 ,
& V_109 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_36 ( V_64 , & V_65 , & V_66 ,
& V_67 ) ;
if ( V_19 )
return V_19 ;
}
V_168 -> V_170 . V_109 =
F_61 ( V_109 ) ;
V_168 -> V_170 . V_176 =
F_61 ( V_67 ) ;
V_168 -> V_170 . V_65 = F_58 ( V_65 ) ;
V_168 -> V_170 . V_66 = F_58 ( V_66 ) ;
}
F_62 ( V_21 , V_166 ) ;
return 0 ;
}
static int F_63 ( struct V_160 * V_21 , void * V_8 ,
int V_161 , T_6 V_162 , int V_154 ,
enum V_163 type )
{
unsigned int V_177 ;
unsigned int V_178 ;
int V_179 ;
int V_19 ;
V_177 = ( V_161 + V_180 - 1 ) / V_180 ;
V_179 = V_161 % V_180 ;
V_179 = V_179 ? V_179 : V_180 ;
for ( V_178 = 0 ; V_178 < V_177 ; V_178 ++ ) {
V_19 = F_56 ( V_21 , V_8 ,
( V_178 == V_177 - 1 ) ?
V_179 : V_180 ,
V_162 + V_180 * V_178 ,
V_154 && ( V_178 == V_177 - 1 ) ? 1 : 0 ,
( type == V_172 && ! V_178 ) ?
V_172 : V_181 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_64 ( struct V_63 * * V_182 , int * V_183 ,
struct V_160 * V_21 )
{
struct V_63 * V_64 = * V_182 ;
struct V_184 * V_185 ;
int V_186 ;
int V_187 ;
int V_188 ;
int V_161 ;
int V_10 ;
V_161 = F_65 ( V_64 ) ;
V_188 = ( V_161 + V_180 - 1 ) / V_180 ;
V_187 = F_41 ( V_64 ) -> V_189 ;
for ( V_10 = 0 ; V_10 < V_187 ; V_10 ++ ) {
V_185 = & F_41 ( V_64 ) -> V_190 [ V_10 ] ;
V_161 = F_66 ( V_185 ) ;
V_186 =
( V_161 + V_180 - 1 ) / V_180 ;
if ( V_186 > V_191 )
return - V_192 ;
V_188 += V_186 ;
}
if ( V_188 > F_67 ( V_21 ) )
return - V_193 ;
* V_183 = V_188 ;
return 0 ;
}
static int F_68 ( struct V_63 * * V_182 , int * V_183 ,
struct V_160 * V_21 )
{
struct V_63 * V_64 = * V_182 ;
int V_188 ;
V_188 = F_41 ( V_64 ) -> V_189 + 1 ;
if ( V_188 > F_67 ( V_21 ) )
return - V_193 ;
* V_183 = V_188 ;
return 0 ;
}
static void F_69 ( struct V_160 * V_21 , int V_194 )
{
struct V_195 * V_2 = F_70 ( V_21 ) ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_21 -> V_196 ; V_10 ++ ) {
if ( V_21 -> V_166 == V_194 )
break;
if ( V_21 -> V_165 [ V_21 -> V_166 ] . type == V_172 )
F_71 ( V_2 ,
V_21 -> V_165 [ V_21 -> V_166 ] . V_162 ,
V_21 -> V_165 [ V_21 -> V_166 ] . V_169 ,
V_197 ) ;
else
F_72 ( V_2 ,
V_21 -> V_165 [ V_21 -> V_166 ] . V_162 ,
V_21 -> V_165 [ V_21 -> V_166 ] . V_169 ,
V_197 ) ;
F_73 ( V_21 , V_166 ) ;
}
}
static T_7 F_74 ( struct V_63 * V_64 ,
struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_198 * V_199 =
& F_75 ( V_8 , V_64 -> V_200 ) ;
struct V_160 * V_21 = V_199 -> V_21 ;
struct V_195 * V_2 = V_8 -> V_2 ;
struct V_201 * V_202 ;
struct V_184 * V_185 ;
int V_203 ;
int V_204 ;
T_6 V_162 ;
int V_188 ;
int V_205 ;
int V_161 ;
int V_19 ;
int V_10 ;
F_76 ( V_64 -> V_86 ) ;
switch ( V_8 -> V_44 . V_206 ( & V_64 , & V_188 , V_21 ) ) {
case - V_193 :
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_209 ++ ;
F_78 ( & V_21 -> V_207 ) ;
goto V_210;
case - V_192 :
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_211 ++ ;
F_78 ( & V_21 -> V_207 ) ;
F_7 ( V_25 , L_13 ) ;
goto V_212;
default:
break;
}
V_205 = F_41 ( V_64 ) -> V_189 + 1 ;
V_161 = F_65 ( V_64 ) ;
V_203 = V_21 -> V_166 ;
V_162 = F_79 ( V_2 , V_64 -> V_86 , V_161 , V_197 ) ;
if ( F_80 ( V_2 , V_162 ) ) {
F_7 ( V_25 , L_14 ) ;
V_21 -> V_208 . V_211 ++ ;
goto V_212;
}
V_19 = V_8 -> V_44 . V_213 ( V_21 , V_64 , V_161 , V_162 , V_205 == 1 ? 1 : 0 ,
V_172 ) ;
if ( V_19 )
goto V_214;
V_204 = V_21 -> V_166 ;
for ( V_10 = 1 ; V_10 < V_205 ; V_10 ++ ) {
V_185 = & F_41 ( V_64 ) -> V_190 [ V_10 - 1 ] ;
V_161 = F_66 ( V_185 ) ;
V_162 = F_81 ( V_2 , V_185 , 0 , V_161 , V_197 ) ;
if ( F_80 ( V_2 , V_162 ) ) {
F_7 ( V_25 , L_15 , V_10 ) ;
V_21 -> V_208 . V_211 ++ ;
goto V_215;
}
V_19 = V_8 -> V_44 . V_213 ( V_21 , F_82 ( V_185 ) , V_161 , V_162 ,
V_205 - 1 == V_10 ? 1 : 0 ,
V_181 ) ;
if ( V_19 )
goto V_215;
}
V_202 = F_83 ( V_25 , V_199 -> V_216 ) ;
F_84 ( V_202 , V_64 -> V_89 ) ;
F_85 () ;
F_86 ( V_21 -> V_217 , V_188 ) ;
return V_218 ;
V_215:
F_69 ( V_21 , V_204 ) ;
V_214:
F_69 ( V_21 , V_203 ) ;
V_212:
F_87 ( V_64 ) ;
return V_218 ;
V_210:
F_88 ( V_25 , V_199 -> V_216 ) ;
F_89 () ;
return V_219 ;
}
static int F_90 ( struct V_38 * V_25 , void * V_220 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_221 * V_222 = V_220 ;
int V_19 ;
if ( ! V_222 || ! F_91 ( ( const T_4 * ) V_222 -> V_223 ) )
return - V_224 ;
V_19 = V_40 -> V_43 -> V_44 -> V_225 ( V_40 , V_222 -> V_223 ) ;
if ( V_19 ) {
F_7 ( V_25 , L_16 , V_19 ) ;
return V_19 ;
}
F_92 ( V_25 -> V_226 , V_222 -> V_223 ) ;
return 0 ;
}
static int F_93 ( struct V_38 * V_25 ,
T_8 V_227 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
if ( V_227 & ( V_228 | V_229 ) ) {
V_8 -> V_44 . V_213 = F_63 ;
V_8 -> V_44 . V_206 = F_64 ;
} else {
V_8 -> V_44 . V_213 = F_56 ;
V_8 -> V_44 . V_206 = F_68 ;
}
V_25 -> V_227 = V_227 ;
return 0 ;
}
static void
F_94 ( struct V_38 * V_25 , struct V_230 * V_208 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
int V_231 = V_8 -> V_41 -> V_47 . V_48 ;
struct V_160 * V_21 ;
unsigned int V_45 ;
unsigned int V_232 ;
T_9 V_233 = 0 ;
T_9 V_234 = 0 ;
T_9 V_235 = 0 ;
T_9 V_236 = 0 ;
for ( V_232 = 0 ; V_232 < V_231 ; V_232 ++ ) {
V_21 = V_8 -> V_199 [ V_232 ] . V_21 ;
do {
V_45 = F_95 ( & V_21 -> V_207 ) ;
V_233 += V_21 -> V_208 . V_233 ;
V_235 += V_21 -> V_208 . V_235 ;
} while ( F_96 ( & V_21 -> V_207 , V_45 ) );
V_21 = V_8 -> V_199 [ V_232 + V_231 ] . V_21 ;
do {
V_45 = F_95 ( & V_21 -> V_207 ) ;
V_234 += V_21 -> V_208 . V_234 ;
V_236 += V_21 -> V_208 . V_236 ;
} while ( F_96 ( & V_21 -> V_207 , V_45 ) );
}
V_208 -> V_233 = V_233 ;
V_208 -> V_237 = V_235 ;
V_208 -> V_234 = V_234 ;
V_208 -> V_238 = V_236 ;
V_208 -> V_239 = V_25 -> V_208 . V_239 ;
V_208 -> V_240 = V_25 -> V_208 . V_240 ;
V_208 -> V_241 = V_25 -> V_208 . V_241 ;
V_208 -> V_242 = V_25 -> V_208 . V_242 ;
V_208 -> V_243 = V_25 -> V_208 . V_243 ;
V_208 -> V_244 = V_25 -> V_208 . V_244 ;
V_208 -> V_245 = V_25 -> V_208 . V_245 ;
V_208 -> V_246 = V_25 -> V_208 . V_246 ;
V_208 -> V_247 = V_25 -> V_208 . V_247 ;
V_208 -> V_248 = V_25 -> V_208 . V_248 ;
V_208 -> V_249 = V_25 -> V_208 . V_249 ;
V_208 -> V_250 = V_25 -> V_208 . V_250 ;
V_208 -> V_251 = V_25 -> V_208 . V_251 ;
V_208 -> V_252 = V_25 -> V_208 . V_252 ;
V_208 -> V_253 = V_25 -> V_208 . V_253 ;
V_208 -> V_254 = V_25 -> V_208 . V_254 ;
V_208 -> V_255 = V_25 -> V_208 . V_255 ;
V_208 -> V_256 = V_25 -> V_208 . V_256 ;
V_208 -> V_257 = V_25 -> V_208 . V_257 ;
}
static void F_97 ( struct V_38 * V_25 , T_3 V_258 ,
enum V_259 type )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_260 * V_261 = & V_8 -> V_261 [ type ] ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( V_261 -> V_262 && V_261 -> V_263 == V_258 ) {
V_261 -> V_262 ++ ;
return;
}
if ( V_261 -> V_262 ) {
F_98 ( V_25 ,
L_17 , type , V_258 ) ;
return;
}
V_261 -> V_263 = V_258 ;
V_261 -> V_262 = 1 ;
if ( V_40 -> V_43 -> V_44 -> V_264 )
V_40 -> V_43 -> V_44 -> V_264 ( V_40 , V_258 ) ;
}
static void F_99 ( struct V_38 * V_25 , T_3 V_258 ,
enum V_259 type )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_260 * V_261 = & V_8 -> V_261 [ type ] ;
struct V_39 * V_40 = V_8 -> V_41 ;
if ( ! V_261 -> V_262 || V_261 -> V_263 != V_258 ) {
F_98 ( V_25 ,
L_18 , V_258 ) ;
return;
}
V_261 -> V_262 -- ;
if ( V_261 -> V_262 )
return;
V_261 -> V_263 = 0 ;
if ( V_40 -> V_43 -> V_44 -> V_265 )
V_40 -> V_43 -> V_44 -> V_265 ( V_40 , V_258 ) ;
}
static void F_100 ( struct V_38 * V_25 ,
struct V_266 * V_267 )
{
T_3 V_268 = F_101 ( V_267 -> V_258 ) ;
switch ( V_267 -> type ) {
case V_269 :
F_97 ( V_25 , V_268 , V_270 ) ;
break;
case V_271 :
F_97 ( V_25 , V_268 , V_272 ) ;
break;
default:
F_7 ( V_25 , L_19 , V_267 -> type ) ;
break;
}
}
static void F_102 ( struct V_38 * V_25 ,
struct V_266 * V_267 )
{
T_3 V_268 = F_101 ( V_267 -> V_258 ) ;
switch ( V_267 -> type ) {
case V_269 :
F_99 ( V_25 , V_268 , V_270 ) ;
break;
case V_271 :
F_99 ( V_25 , V_268 , V_272 ) ;
break;
default:
break;
}
}
static int F_103 ( struct V_38 * V_25 , T_4 V_273 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_274 * V_47 = & V_40 -> V_47 ;
unsigned int V_10 ;
int V_19 ;
if ( V_273 > V_275 )
return - V_107 ;
if ( V_47 -> V_276 == V_273 )
return 0 ;
if ( ! V_25 )
return - V_107 ;
if ( ! V_273 ) {
F_104 ( V_25 ) ;
return 0 ;
}
V_19 = F_105 ( V_25 , V_273 ) ;
if ( V_19 )
return V_19 ;
for ( V_10 = 0 ; V_10 < V_275 ; V_10 ++ ) {
if ( V_47 -> V_277 [ V_10 ] . V_278 )
F_106 ( V_25 ,
V_47 -> V_277 [ V_10 ] . V_273 ,
V_47 -> V_277 [ V_10 ] . V_279 ,
V_47 -> V_277 [ V_10 ] . V_280 ) ;
}
return 0 ;
}
static int F_107 ( struct V_38 * V_2 , enum V_281 type ,
void * V_282 )
{
struct V_283 * V_284 = V_282 ;
if ( type != V_285 )
return - V_286 ;
return F_103 ( V_2 , V_284 -> V_276 ) ;
}
static int F_108 ( struct V_38 * V_25 ,
T_5 V_287 , T_3 V_288 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
int V_19 = - V_289 ;
if ( V_40 -> V_43 -> V_44 -> V_290 )
V_19 = V_40 -> V_43 -> V_44 -> V_290 ( V_40 , V_287 , V_288 , false ) ;
return V_19 ;
}
static int F_109 ( struct V_38 * V_25 ,
T_5 V_287 , T_3 V_288 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
int V_19 = - V_289 ;
if ( V_40 -> V_43 -> V_44 -> V_290 )
V_19 = V_40 -> V_43 -> V_44 -> V_290 ( V_40 , V_287 , V_288 , true ) ;
return V_19 ;
}
static int F_110 ( struct V_38 * V_25 , int V_291 , T_3 V_292 ,
T_4 V_293 , T_5 V_294 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
int V_19 = - V_289 ;
if ( V_40 -> V_43 -> V_44 -> V_295 )
V_19 = V_40 -> V_43 -> V_44 -> V_295 ( V_40 , V_291 , V_292 ,
V_293 , V_294 ) ;
return V_19 ;
}
static int F_111 ( struct V_38 * V_25 , int V_296 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
bool V_297 = F_112 ( V_25 ) ;
int V_19 ;
if ( ! V_40 -> V_43 -> V_44 -> V_298 )
return - V_286 ;
if ( V_297 ) {
( void ) F_25 ( V_25 ) ;
F_113 ( 100 ) ;
}
V_19 = V_40 -> V_43 -> V_44 -> V_298 ( V_40 , V_296 ) ;
if ( V_19 ) {
F_7 ( V_25 , L_20 ,
V_19 ) ;
return V_19 ;
}
if ( V_297 && F_20 ( V_25 ) )
V_19 = - V_107 ;
return V_19 ;
}
static int F_114 ( struct V_299 * V_300 , const struct V_301 * V_302 )
{
struct V_303 * V_304 ;
int V_19 ;
V_304 = F_115 ( & V_300 -> V_2 , sizeof( * V_304 ) ,
V_305 ) ;
if ( ! V_304 ) {
V_19 = - V_192 ;
return V_19 ;
}
V_304 -> V_300 = V_300 ;
V_304 -> V_306 = V_302 -> V_307 ;
V_304 -> V_308 = V_309 ;
F_116 ( V_300 , V_304 ) ;
return F_117 ( V_304 ) ;
}
static void F_118 ( struct V_299 * V_300 )
{
struct V_303 * V_304 = F_119 ( V_300 ) ;
F_120 ( V_304 ) ;
F_121 ( & V_300 -> V_2 , V_304 ) ;
F_116 ( V_300 , NULL ) ;
}
static void F_122 ( struct V_38 * V_25 )
{
V_25 -> V_310 |= V_311 ;
V_25 -> V_312 |= V_313 | V_314 |
V_315 | V_316 | V_317 |
V_318 | V_228 | V_229 | V_319 |
V_320 | V_321 |
V_322 ;
V_25 -> V_312 |= V_323 ;
V_25 -> V_324 |= V_320 ;
V_25 -> V_227 |= V_313 | V_314 |
V_325 |
V_315 | V_316 | V_317 |
V_318 | V_228 | V_229 | V_319 |
V_320 | V_321 |
V_322 ;
V_25 -> V_326 |=
V_313 | V_314 | V_315 |
V_316 | V_317 | V_318 |
V_228 | V_229 | V_319 |
V_320 | V_321 |
V_322 ;
V_25 -> V_327 |= V_313 | V_314 |
V_325 |
V_315 | V_316 | V_317 |
V_318 | V_228 | V_229 | V_319 |
V_320 | V_321 |
V_322 ;
}
static int F_123 ( struct V_160 * V_21 ,
struct V_164 * V_328 )
{
unsigned int V_329 = F_124 ( V_21 ) ;
struct V_330 * V_220 ;
V_220 = F_125 ( V_329 ) ;
if ( ! V_220 )
return - V_192 ;
V_328 -> V_8 = V_220 ;
V_328 -> V_331 = 0 ;
V_328 -> V_332 = 0 ;
V_328 -> V_333 = F_126 ( V_220 ) ;
V_328 -> V_169 = F_127 ( V_21 ) ;
V_328 -> type = V_181 ;
memset ( V_328 -> V_333 , 0 , V_328 -> V_169 ) ;
return 0 ;
}
static void F_128 ( struct V_160 * V_21 ,
struct V_164 * V_328 )
{
if ( V_328 -> type == V_172 )
F_87 ( (struct V_63 * ) V_328 -> V_8 ) ;
else if ( ! F_129 ( V_21 ) )
F_130 ( (struct V_330 * ) V_328 -> V_8 ) ;
memset ( V_328 , 0 , sizeof( * V_328 ) ) ;
}
static int F_131 ( struct V_160 * V_21 , struct V_164 * V_328 )
{
V_328 -> V_162 = F_132 ( F_70 ( V_21 ) , V_328 -> V_8 , 0 ,
V_328 -> V_169 , F_133 ( V_21 ) ) ;
if ( F_80 ( F_70 ( V_21 ) , V_328 -> V_162 ) )
return - V_289 ;
return 0 ;
}
static void F_134 ( struct V_160 * V_21 ,
struct V_164 * V_328 )
{
if ( V_328 -> type == V_172 )
F_71 ( F_70 ( V_21 ) , V_328 -> V_162 , V_328 -> V_169 ,
F_133 ( V_21 ) ) ;
else
F_72 ( F_70 ( V_21 ) , V_328 -> V_162 , V_328 -> V_169 ,
F_133 ( V_21 ) ) ;
}
static void F_135 ( struct V_160 * V_21 , int V_10 )
{
F_134 ( V_21 , & V_21 -> V_165 [ V_10 ] ) ;
V_21 -> V_168 [ V_10 ] . V_54 = 0 ;
}
static void F_136 ( struct V_160 * V_21 , int V_10 )
{
struct V_164 * V_328 = & V_21 -> V_165 [ V_10 ] ;
if ( ! V_21 -> V_165 [ V_10 ] . V_162 )
return;
F_135 ( V_21 , V_10 ) ;
F_128 ( V_21 , V_328 ) ;
}
static void F_137 ( struct V_160 * V_21 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_21 -> V_196 ; V_10 ++ )
F_136 ( V_21 , V_10 ) ;
}
static void F_138 ( struct V_160 * V_21 )
{
F_137 ( V_21 ) ;
F_71 ( F_70 ( V_21 ) , V_21 -> V_334 ,
V_21 -> V_196 * sizeof( V_21 -> V_168 [ 0 ] ) ,
V_335 ) ;
V_21 -> V_334 = 0 ;
F_139 ( V_21 -> V_168 ) ;
V_21 -> V_168 = NULL ;
}
static int F_140 ( struct V_160 * V_21 )
{
int V_161 = V_21 -> V_196 * sizeof( V_21 -> V_168 [ 0 ] ) ;
V_21 -> V_168 = F_141 ( V_161 , V_305 ) ;
if ( ! V_21 -> V_168 )
return - V_192 ;
V_21 -> V_334 = F_79 ( F_70 ( V_21 ) , V_21 -> V_168 ,
V_161 , V_335 ) ;
if ( F_80 ( F_70 ( V_21 ) , V_21 -> V_334 ) ) {
V_21 -> V_334 = 0 ;
F_139 ( V_21 -> V_168 ) ;
V_21 -> V_168 = NULL ;
return - V_192 ;
}
return 0 ;
}
static int F_142 ( struct V_160 * V_21 ,
struct V_164 * V_328 )
{
int V_19 ;
V_19 = F_123 ( V_21 , V_328 ) ;
if ( V_19 )
goto V_336;
V_19 = F_131 ( V_21 , V_328 ) ;
if ( V_19 )
goto V_337;
return 0 ;
V_337:
F_137 ( V_21 ) ;
V_336:
return V_19 ;
}
static int F_143 ( struct V_160 * V_21 , int V_10 )
{
int V_19 = F_142 ( V_21 , & V_21 -> V_165 [ V_10 ] ) ;
if ( V_19 )
return V_19 ;
V_21 -> V_168 [ V_10 ] . V_54 = F_57 ( V_21 -> V_165 [ V_10 ] . V_162 ) ;
return 0 ;
}
static int F_144 ( struct V_160 * V_21 )
{
int V_10 , V_42 , V_19 ;
for ( V_10 = 0 ; V_10 < V_21 -> V_196 ; V_10 ++ ) {
V_19 = F_143 ( V_21 , V_10 ) ;
if ( V_19 )
goto V_338;
}
return 0 ;
V_338:
for ( V_42 = V_10 - 1 ; V_42 >= 0 ; V_42 -- )
F_136 ( V_21 , V_42 ) ;
return V_19 ;
}
static void F_145 ( struct V_160 * V_21 , int V_10 ,
struct V_164 * V_339 )
{
F_131 ( V_21 , & V_21 -> V_165 [ V_10 ] ) ;
V_21 -> V_165 [ V_10 ] = * V_339 ;
V_21 -> V_168 [ V_10 ] . V_54 = F_57 ( V_21 -> V_165 [ V_10 ] . V_162 ) ;
}
static void F_146 ( struct V_160 * V_21 , int V_10 )
{
V_21 -> V_165 [ V_10 ] . V_332 = 0 ;
V_21 -> V_168 [ V_10 ] . V_54 = F_57 ( V_21 -> V_165 [ V_10 ] . V_162
+ V_21 -> V_165 [ V_10 ] . V_331 ) ;
}
static void F_147 ( struct V_160 * V_21 , int * V_340 ,
int * V_341 )
{
struct V_164 * V_165 = & V_21 -> V_165 [ V_21 -> V_342 ] ;
( * V_341 ) += ( V_165 -> type == V_172 ) ;
( * V_340 ) += V_165 -> V_169 ;
F_136 ( V_21 , V_21 -> V_342 ) ;
F_62 ( V_21 , V_342 ) ;
}
static int F_148 ( struct V_160 * V_21 , int V_40 )
{
int V_343 = V_21 -> V_166 ;
int V_344 = V_21 -> V_342 ;
if ( F_149 ( V_40 > V_21 -> V_196 ) )
return 0 ;
return V_343 > V_344 ? ( V_40 > V_344 && V_40 <= V_343 ) : ( V_40 > V_344 || V_40 <= V_343 ) ;
}
int F_150 ( struct V_160 * V_21 , int V_345 )
{
struct V_38 * V_25 = V_21 -> V_217 -> V_346 -> V_47 . V_25 ;
struct V_201 * V_202 ;
int V_340 , V_341 ;
int V_347 ;
V_347 = F_151 ( V_21 -> V_217 -> V_348 + V_349 ) ;
F_152 () ;
if ( F_153 ( V_21 ) || V_347 == V_21 -> V_342 )
return 0 ;
if ( ! F_148 ( V_21 , V_347 ) ) {
F_7 ( V_25 , L_21 , V_347 ,
V_21 -> V_166 , V_21 -> V_342 ) ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_350 ++ ;
F_78 ( & V_21 -> V_207 ) ;
return - V_289 ;
}
V_340 = 0 ;
V_341 = 0 ;
while ( V_347 != V_21 -> V_342 && V_345 ) {
F_147 ( V_21 , & V_340 , & V_341 ) ;
F_76 ( & V_21 -> V_165 [ V_21 -> V_342 ] ) ;
V_345 -- ;
}
V_21 -> V_4 -> V_20 . V_351 += V_340 ;
V_21 -> V_4 -> V_20 . V_352 += V_341 ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_233 += V_340 ;
V_21 -> V_208 . V_235 += V_341 ;
F_78 ( & V_21 -> V_207 ) ;
V_202 = F_83 ( V_25 , V_21 -> V_217 -> V_353 ) ;
F_154 ( V_202 , V_341 , V_340 ) ;
if ( F_149 ( V_341 && F_155 ( V_25 ) &&
( F_67 ( V_21 ) > V_354 ) ) ) {
F_89 () ;
if ( F_156 ( V_202 ) ) {
F_157 ( V_202 ) ;
V_21 -> V_208 . V_355 ++ ;
}
}
return ! ! V_345 ;
}
static int F_158 ( struct V_160 * V_21 )
{
int V_356 = V_21 -> V_342 ;
int V_357 = V_21 -> V_166 ;
return ( ( V_356 >= V_357 ) ? 0 : V_21 -> V_196 ) + V_356 - V_357 ;
}
static void
F_159 ( struct V_160 * V_21 , int V_358 )
{
struct V_164 * V_165 ;
struct V_164 V_359 ;
int V_10 , V_19 ;
for ( V_10 = 0 ; V_10 < V_358 ; V_10 ++ ) {
V_165 = & V_21 -> V_165 [ V_21 -> V_166 ] ;
if ( V_165 -> V_332 ) {
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_360 ++ ;
F_78 ( & V_21 -> V_207 ) ;
F_146 ( V_21 , V_21 -> V_166 ) ;
} else {
V_19 = F_142 ( V_21 , & V_359 ) ;
if ( V_19 ) {
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_211 ++ ;
F_78 ( & V_21 -> V_207 ) ;
F_7 ( V_21 -> V_217 -> V_346 -> V_47 . V_25 ,
L_22 ) ;
break;
}
F_145 ( V_21 , V_21 -> V_166 , & V_359 ) ;
}
F_62 ( V_21 , V_166 ) ;
}
F_85 () ;
F_160 ( V_10 , V_21 -> V_217 -> V_348 + V_361 ) ;
}
static unsigned int F_161 ( unsigned char * V_86 , T_2 V_306 ,
unsigned int V_362 )
{
unsigned char * V_363 ;
T_4 V_364 ;
if ( V_362 < V_365 )
return V_362 ;
V_363 = V_86 ;
V_363 += V_365 ;
if ( F_162 ( V_306 , V_366 , V_367 )
== V_368 ) {
if ( ( F_163 ( V_362 ) ) ( V_363 - V_86 ) > ( V_362 - V_369 ) )
return V_362 ;
V_363 += V_369 ;
}
if ( F_162 ( V_306 , V_370 , V_371 )
== V_372 ) {
if ( ( F_163 ( V_362 ) ) ( V_363 - V_86 ) >
( V_362 - sizeof( struct V_96 ) ) )
return V_362 ;
V_364 = ( V_363 [ 0 ] & 0x0F ) << 2 ;
if ( V_364 < sizeof( struct V_96 ) )
return V_363 - V_86 ;
} else if ( F_162 ( V_306 , V_370 , V_371 )
== V_373 ) {
if ( ( F_163 ( V_362 ) ) ( V_363 - V_86 ) >
( V_362 - sizeof( struct V_97 ) ) )
return V_362 ;
V_364 = sizeof( struct V_97 ) ;
} else {
return V_363 - V_86 ;
}
V_363 += V_364 ;
if ( F_162 ( V_306 , V_374 , V_375 )
== V_376 ) {
if ( ( F_163 ( V_362 ) ) ( V_363 - V_86 ) >
( V_362 - sizeof( struct V_110 ) ) )
return V_362 ;
V_364 = ( V_363 [ 12 ] & 0xF0 ) >> 2 ;
if ( V_364 < sizeof( struct V_110 ) )
return V_363 - V_86 ;
V_363 += V_364 ;
} else if ( F_162 ( V_306 , V_374 , V_375 )
== V_377 ) {
if ( ( F_163 ( V_362 ) ) ( V_363 - V_86 ) >
( V_362 - sizeof( struct V_111 ) ) )
return V_362 ;
V_363 += sizeof( struct V_111 ) ;
}
if ( ( F_163 ( V_362 ) ) ( V_363 - V_86 ) < V_362 )
return V_363 - V_86 ;
else
return V_362 ;
}
static void F_164 ( struct V_63 * V_64 , int V_10 ,
struct V_160 * V_21 , int V_378 ,
struct V_164 * V_165 )
{
struct V_167 * V_168 ;
int V_379 , V_161 ;
int V_380 ;
bool V_381 ;
V_381 = ( ( V_382 < 8192 ) &&
F_165 ( V_21 ) == V_383 ) ;
V_168 = & V_21 -> V_168 [ V_21 -> V_342 ] ;
V_161 = F_166 ( V_168 -> V_384 . V_161 ) ;
if ( V_381 ) {
V_379 = F_165 ( V_21 ) ;
} else {
V_379 = F_167 ( V_161 , V_385 ) ;
V_380 = F_127 ( V_21 ) - F_165 ( V_21 ) ;
}
F_168 ( V_64 , V_10 , V_165 -> V_8 , V_165 -> V_331 + V_378 ,
V_161 - V_378 , V_379 - V_378 ) ;
if ( F_149 ( F_169 ( V_165 -> V_8 ) != F_170 () ) )
return;
if ( V_381 ) {
if ( F_171 ( F_172 ( V_165 -> V_8 ) == 1 ) ) {
V_165 -> V_331 ^= V_379 ;
V_165 -> V_332 = 1 ;
F_173 ( V_165 -> V_8 ) ;
}
return;
}
V_165 -> V_331 += V_379 ;
if ( V_165 -> V_331 <= V_380 ) {
V_165 -> V_332 = 1 ;
F_173 ( V_165 -> V_8 ) ;
}
}
static void F_174 ( struct V_160 * V_21 , struct V_63 * V_64 ,
struct V_167 * V_168 )
{
struct V_38 * V_25 = V_21 -> V_217 -> V_346 -> V_47 . V_25 ;
int V_386 , V_387 ;
T_2 V_388 ;
int V_389 ;
T_2 V_390 ;
V_388 = F_175 ( V_168 -> V_384 . V_388 ) ;
V_390 = F_175 ( V_168 -> V_384 . V_391 ) ;
V_64 -> V_173 = V_392 ;
F_176 ( V_64 ) ;
if ( ! ( V_25 -> V_227 & V_315 ) )
return;
if ( ! F_177 ( V_388 , V_393 ) )
return;
if ( F_149 ( F_177 ( V_390 , V_394 ) ||
F_177 ( V_390 , V_395 ) ||
F_177 ( V_390 , V_396 ) ||
F_177 ( V_390 , V_397 ) ) ) {
F_7 ( V_25 , L_23 ) ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_398 ++ ;
F_78 ( & V_21 -> V_207 ) ;
return;
}
V_386 = F_162 ( V_390 , V_370 ,
V_371 ) ;
V_387 = F_162 ( V_390 , V_374 ,
V_375 ) ;
V_389 = F_162 ( V_390 , V_399 , V_400 ) ;
switch ( V_389 ) {
case V_401 :
case V_402 :
V_64 -> V_403 = 1 ;
case V_404 :
if ( V_386 == V_405 ||
( V_386 == V_406 &&
( V_387 == V_407 ||
V_387 == V_408 ||
V_387 == V_409 ) ) )
V_64 -> V_173 = V_410 ;
break;
}
}
static int F_178 ( struct V_160 * V_21 ,
struct V_63 * * V_182 , int * V_411 )
{
struct V_38 * V_25 = V_21 -> V_217 -> V_346 -> V_47 . V_25 ;
struct V_164 * V_165 ;
struct V_167 * V_168 ;
struct V_63 * V_64 ;
unsigned char * V_412 ;
T_2 V_388 ;
int V_378 ;
T_2 V_390 ;
int V_169 ;
int V_183 ;
V_168 = & V_21 -> V_168 [ V_21 -> V_342 ] ;
V_165 = & V_21 -> V_165 [ V_21 -> V_342 ] ;
F_76 ( V_168 ) ;
V_169 = F_166 ( V_168 -> V_384 . V_413 ) ;
V_388 = F_175 ( V_168 -> V_384 . V_388 ) ;
V_390 = F_175 ( V_168 -> V_384 . V_391 ) ;
if ( ! F_177 ( V_388 , V_414 ) )
return - V_415 ;
V_412 = ( unsigned char * ) V_165 -> V_333 + V_165 -> V_331 ;
F_76 ( V_412 ) ;
#if V_385 < 128
F_76 ( V_412 + V_385 ) ;
#endif
V_64 = * V_182 = F_179 ( & V_21 -> V_4 -> V_5 ,
V_416 ) ;
if ( F_149 ( ! V_64 ) ) {
F_7 ( V_25 , L_24 ) ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_211 ++ ;
F_78 ( & V_21 -> V_207 ) ;
return - V_192 ;
}
F_180 ( V_64 -> V_86 ) ;
V_183 = 1 ;
if ( V_169 <= V_416 ) {
memcpy ( F_181 ( V_64 , V_169 ) , V_412 , F_167 ( V_169 , sizeof( long ) ) ) ;
if ( F_171 ( F_169 ( V_165 -> V_8 ) == F_170 () ) )
V_165 -> V_332 = 1 ;
else
F_130 ( V_165 -> V_8 ) ;
F_62 ( V_21 , V_342 ) ;
} else {
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_417 ++ ;
F_78 ( & V_21 -> V_207 ) ;
V_378 = F_161 ( V_412 , V_390 ,
V_416 ) ;
memcpy ( F_181 ( V_64 , V_378 ) , V_412 ,
F_167 ( V_378 , sizeof( long ) ) ) ;
F_164 ( V_64 , 0 , V_21 , V_378 , V_165 ) ;
F_62 ( V_21 , V_342 ) ;
while ( ! F_177 ( V_388 , V_418 ) ) {
V_168 = & V_21 -> V_168 [ V_21 -> V_342 ] ;
V_165 = & V_21 -> V_165 [ V_21 -> V_342 ] ;
V_388 = F_175 ( V_168 -> V_384 . V_388 ) ;
F_164 ( V_64 , V_183 , V_21 , 0 , V_165 ) ;
F_62 ( V_21 , V_342 ) ;
V_183 ++ ;
}
}
* V_411 = V_183 ;
if ( F_149 ( ! F_177 ( V_388 , V_414 ) ) ) {
F_7 ( V_25 , L_25 ,
( ( T_9 * ) V_168 ) [ 0 ] , ( ( T_9 * ) V_168 ) [ 1 ] ) ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_419 ++ ;
F_78 ( & V_21 -> V_207 ) ;
F_87 ( V_64 ) ;
return - V_107 ;
}
if ( F_149 ( ( ! V_168 -> V_384 . V_413 ) ||
F_177 ( V_390 , V_420 ) ) ) {
F_7 ( V_25 , L_26 ) ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_421 ++ ;
F_78 ( & V_21 -> V_207 ) ;
F_87 ( V_64 ) ;
return - V_415 ;
}
if ( F_149 ( F_177 ( V_390 , V_422 ) ) ) {
F_7 ( V_25 , L_27 ) ;
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_423 ++ ;
F_78 ( & V_21 -> V_207 ) ;
F_87 ( V_64 ) ;
return - V_415 ;
}
F_77 ( & V_21 -> V_207 ) ;
V_21 -> V_208 . V_236 ++ ;
V_21 -> V_208 . V_234 += V_64 -> V_89 ;
F_78 ( & V_21 -> V_207 ) ;
V_21 -> V_4 -> V_22 . V_351 += V_64 -> V_89 ;
F_174 ( V_21 , V_64 , V_168 ) ;
return 0 ;
}
static int F_182 ( struct V_160 * V_21 , int V_345 )
{
#define F_183 16
struct V_38 * V_25 = V_21 -> V_217 -> V_346 -> V_47 . V_25 ;
int V_424 , V_425 , V_426 , V_427 ;
int V_428 = F_158 ( V_21 ) ;
struct V_63 * V_64 = NULL ;
int V_429 , V_183 = 0 ;
V_429 = F_151 ( V_21 -> V_217 -> V_348 + V_430 ) ;
F_152 () ;
V_424 = 0 , V_425 = 0 , V_426 = 0 ;
V_429 -= V_428 ;
while ( V_424 < V_345 && V_425 < V_429 ) {
if ( V_426 + V_428 >= F_183 ) {
F_159 ( V_21 ,
V_426 + V_428 ) ;
V_426 = 0 ;
V_428 = F_158 ( V_21 ) ;
}
V_427 = F_178 ( V_21 , & V_64 , & V_183 ) ;
if ( F_149 ( ! V_64 ) )
goto V_336;
V_425 += V_183 ;
V_426 += V_183 ;
if ( F_149 ( V_427 ) ) {
V_424 ++ ;
continue;
}
V_64 -> V_103 = F_184 ( V_64 , V_25 ) ;
( void ) F_185 ( & V_21 -> V_4 -> V_5 , V_64 ) ;
V_424 ++ ;
}
V_336:
if ( V_426 + V_428 > 0 )
F_159 ( V_21 ,
V_426 + V_428 ) ;
return V_424 ;
}
static bool F_186 ( struct V_431 * V_432 )
{
#define F_187 40000
enum V_433 V_434 ;
struct V_3 * V_4 ;
int V_435 ;
int V_436 ;
T_3 V_437 ;
int V_438 ;
if ( ! V_432 -> V_34 )
return false ;
if ( V_432 -> V_352 == 0 ) {
V_432 -> V_34 = V_35 ;
V_432 -> V_36 = V_37 ;
return true ;
}
V_434 = V_432 -> V_36 ;
V_437 = V_432 -> V_34 ;
V_4 = V_432 -> V_21 -> V_4 ;
V_438 = ( V_432 -> V_34 << 1 ) ;
V_436 = V_432 -> V_351 / V_438 ;
V_435 = V_432 -> V_352 * 1000000 / V_438 ;
switch ( V_434 ) {
case V_37 :
if ( V_436 > 10 )
V_434 = V_439 ;
break;
case V_439 :
if ( V_436 > 20 )
V_434 = V_440 ;
else if ( V_436 <= 10 )
V_434 = V_37 ;
break;
case V_440 :
case V_441 :
default:
if ( V_436 <= 20 )
V_434 = V_439 ;
break;
}
if ( ( V_435 > F_187 ) &&
( & V_4 -> V_22 == V_432 ) )
V_434 = V_441 ;
switch ( V_434 ) {
case V_37 :
V_437 = V_35 ;
break;
case V_439 :
V_437 = V_442 ;
break;
case V_440 :
V_437 = V_443 ;
break;
case V_441 :
V_437 = V_444 ;
break;
default:
break;
}
V_432 -> V_351 = 0 ;
V_432 -> V_352 = 0 ;
V_432 -> V_36 = V_434 ;
if ( V_437 != V_432 -> V_34 ) {
V_432 -> V_34 = V_437 ;
return true ;
}
return false ;
}
static void F_188 ( struct V_3 * V_4 )
{
T_3 V_445 , V_446 ;
bool V_384 , V_170 ;
V_384 = F_186 ( & V_4 -> V_22 ) ;
V_170 = F_186 ( & V_4 -> V_20 ) ;
V_445 = V_4 -> V_22 . V_34 ;
V_446 = V_4 -> V_20 . V_34 ;
if ( V_384 && V_170 ) {
if ( V_445 > V_446 ) {
V_4 -> V_20 . V_34 = V_445 ;
V_4 -> V_20 . V_36 =
V_4 -> V_22 . V_36 ;
F_15 ( V_4 , V_445 ) ;
} else {
V_4 -> V_22 . V_34 = V_446 ;
V_4 -> V_22 . V_36 =
V_4 -> V_20 . V_36 ;
F_15 ( V_4 , V_446 ) ;
}
}
}
static int F_189 ( struct V_447 * V_5 , int V_345 )
{
struct V_160 * V_21 ;
int V_448 = 0 ;
struct V_3 * V_4 =
F_190 ( V_5 , struct V_3 , V_5 ) ;
bool V_449 = true ;
int V_450 ;
F_191 (ring, tqp_vector->tx_group) {
if ( ! F_150 ( V_21 , V_345 ) )
V_449 = false ;
}
V_450 = F_192 ( V_345 / V_4 -> V_48 , 1 ) ;
F_191 (ring, tqp_vector->rx_group) {
int V_451 = F_182 ( V_21 , V_450 ) ;
if ( V_451 >= V_450 )
V_449 = false ;
V_448 += V_451 ;
}
V_4 -> V_22 . V_352 += V_448 ;
if ( ! V_449 )
return V_345 ;
F_193 ( V_5 ) ;
F_188 ( V_4 ) ;
F_8 ( V_4 , 1 ) ;
return V_448 ;
}
static int F_194 ( struct V_3 * V_4 ,
struct V_452 * V_347 )
{
struct V_299 * V_300 = V_4 -> V_346 -> V_300 ;
struct V_452 * V_453 = V_347 ;
struct V_452 * V_454 ;
struct V_160 * V_455 ;
struct V_160 * V_456 ;
V_455 = V_4 -> V_20 . V_21 ;
if ( V_455 ) {
V_453 -> V_353 = V_455 -> V_217 -> V_353 ;
F_46 ( V_453 -> V_306 , V_457 ,
V_458 ) ;
V_453 -> V_459 = NULL ;
while ( V_455 -> V_459 ) {
V_455 = V_455 -> V_459 ;
V_454 = F_115 ( & V_300 -> V_2 , sizeof( * V_454 ) ,
V_305 ) ;
if ( ! V_454 )
return - V_192 ;
V_453 -> V_459 = V_454 ;
V_454 -> V_353 = V_455 -> V_217 -> V_353 ;
F_46 ( V_454 -> V_306 , V_457 ,
V_458 ) ;
V_453 = V_454 ;
}
}
V_456 = V_4 -> V_22 . V_21 ;
if ( ! V_455 && V_456 ) {
V_453 -> V_459 = NULL ;
V_453 -> V_353 = V_456 -> V_217 -> V_353 ;
F_46 ( V_453 -> V_306 , V_457 ,
V_460 ) ;
V_456 = V_456 -> V_459 ;
}
while ( V_456 ) {
V_454 = F_115 ( & V_300 -> V_2 , sizeof( * V_454 ) , V_305 ) ;
if ( ! V_454 )
return - V_192 ;
V_453 -> V_459 = V_454 ;
V_454 -> V_353 = V_456 -> V_217 -> V_353 ;
F_46 ( V_454 -> V_306 , V_457 ,
V_460 ) ;
V_453 = V_454 ;
V_456 = V_456 -> V_459 ;
}
return 0 ;
}
static void F_195 ( struct V_3 * V_4 ,
struct V_452 * V_347 )
{
struct V_299 * V_300 = V_4 -> V_346 -> V_300 ;
struct V_452 * V_461 , * V_454 ;
V_454 = V_347 -> V_459 ;
while ( V_454 ) {
V_461 = V_454 -> V_459 ;
F_121 ( & V_300 -> V_2 , V_454 ) ;
V_454 = V_461 ;
}
}
static void F_196 ( struct V_431 * V_462 ,
struct V_160 * V_21 )
{
V_21 -> V_459 = V_462 -> V_21 ;
V_462 -> V_21 = V_21 ;
V_462 -> V_463 ++ ;
}
static int F_197 ( struct V_7 * V_8 )
{
struct V_452 V_464 ;
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_3 * V_4 ;
struct V_465 * V_466 ;
struct V_299 * V_300 = V_40 -> V_300 ;
T_3 V_467 = V_40 -> V_47 . V_48 ;
T_3 V_11 ;
int V_19 = 0 ;
T_3 V_10 ;
V_11 = F_198 ( T_3 , F_199 () , V_467 ) ;
V_466 = F_200 ( & V_300 -> V_2 , V_11 , sizeof( * V_466 ) ,
V_305 ) ;
if ( ! V_466 )
return - V_192 ;
V_11 = V_40 -> V_43 -> V_44 -> V_468 ( V_40 , V_11 , V_466 ) ;
V_8 -> V_11 = V_11 ;
V_8 -> V_4 = (struct V_3 * )
F_200 ( & V_300 -> V_2 , V_11 , sizeof( * V_8 -> V_4 ) ,
V_305 ) ;
if ( ! V_8 -> V_4 )
return - V_192 ;
for ( V_10 = 0 ; V_10 < V_467 ; V_10 ++ ) {
T_3 V_469 = V_10 % V_11 ;
V_4 = & V_8 -> V_4 [ V_469 ] ;
F_196 ( & V_4 -> V_20 ,
V_8 -> V_199 [ V_10 ] . V_21 ) ;
F_196 ( & V_4 -> V_22 ,
V_8 -> V_199 [ V_10 + V_467 ] . V_21 ) ;
V_4 -> V_232 = V_469 ;
V_4 -> V_27 = V_466 [ V_469 ] . V_470 ;
V_4 -> V_14 = V_466 [ V_469 ] . V_466 ;
V_4 -> V_48 ++ ;
V_8 -> V_199 [ V_10 ] . V_21 -> V_4 = V_4 ;
V_8 -> V_199 [ V_10 + V_467 ] . V_21 -> V_4 = V_4 ;
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_4 = & V_8 -> V_4 [ V_10 ] ;
V_4 -> V_22 . V_351 = 0 ;
V_4 -> V_22 . V_352 = 0 ;
V_4 -> V_20 . V_351 = 0 ;
V_4 -> V_20 . V_352 = 0 ;
F_17 ( V_4 ) ;
V_4 -> V_346 = V_40 ;
V_19 = F_194 ( V_4 ,
& V_464 ) ;
if ( V_19 )
goto V_336;
V_19 = V_40 -> V_43 -> V_44 -> V_471 ( V_40 ,
V_4 -> V_14 , & V_464 ) ;
if ( V_19 )
goto V_336;
F_195 ( V_4 , & V_464 ) ;
F_201 ( V_8 -> V_25 , & V_4 -> V_5 ,
F_189 , V_472 ) ;
}
V_336:
F_121 ( & V_300 -> V_2 , V_466 ) ;
return V_19 ;
}
static int F_202 ( struct V_7 * V_8 )
{
struct V_452 V_464 ;
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_3 * V_4 ;
struct V_299 * V_300 = V_40 -> V_300 ;
int V_10 , V_19 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 ; V_10 ++ ) {
V_4 = & V_8 -> V_4 [ V_10 ] ;
V_19 = F_194 ( V_4 ,
& V_464 ) ;
if ( V_19 )
return V_19 ;
V_19 = V_40 -> V_43 -> V_44 -> V_473 ( V_40 ,
V_4 -> V_14 , & V_464 ) ;
if ( V_19 )
return V_19 ;
F_195 ( V_4 , & V_464 ) ;
if ( V_8 -> V_4 [ V_10 ] . V_12 == V_13 ) {
( void ) F_203 (
V_8 -> V_4 [ V_10 ] . V_14 ,
NULL ) ;
F_204 ( & V_300 -> V_2 ,
V_8 -> V_4 [ V_10 ] . V_14 ,
& V_8 -> V_4 [ V_10 ] ) ;
}
V_8 -> V_199 [ V_10 ] . V_21 -> V_12 = V_15 ;
F_205 ( & V_8 -> V_4 [ V_10 ] . V_5 ) ;
}
F_121 ( & V_300 -> V_2 , V_8 -> V_4 ) ;
return 0 ;
}
static int F_206 ( struct V_474 * V_475 , struct V_7 * V_8 ,
int V_476 )
{
struct V_198 * V_199 = V_8 -> V_199 ;
int V_231 = V_8 -> V_41 -> V_47 . V_48 ;
struct V_299 * V_300 = V_8 -> V_41 -> V_300 ;
struct V_160 * V_21 ;
V_21 = F_115 ( & V_300 -> V_2 , sizeof( * V_21 ) , V_305 ) ;
if ( ! V_21 )
return - V_192 ;
if ( V_476 == V_458 ) {
V_199 [ V_475 -> V_353 ] . V_21 = V_21 ;
V_21 -> V_348 = ( T_4 V_477 * ) V_475 -> V_348 + V_478 ;
} else {
V_199 [ V_475 -> V_353 + V_231 ] . V_21 = V_21 ;
V_21 -> V_348 = V_475 -> V_348 ;
}
F_46 ( V_21 -> V_306 , V_457 , V_476 ) ;
V_199 [ V_475 -> V_353 ] . V_216 = V_475 -> V_353 ;
V_21 -> V_217 = V_475 ;
V_21 -> V_168 = NULL ;
V_21 -> V_165 = NULL ;
V_21 -> V_2 = V_8 -> V_2 ;
V_21 -> V_334 = 0 ;
V_21 -> V_479 = V_475 -> V_479 ;
V_21 -> V_196 = V_475 -> V_196 ;
V_21 -> V_166 = 0 ;
V_21 -> V_342 = 0 ;
return 0 ;
}
static int F_207 ( struct V_474 * V_217 ,
struct V_7 * V_8 )
{
int V_19 ;
V_19 = F_206 ( V_217 , V_8 , V_458 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_206 ( V_217 , V_8 , V_460 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_208 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_41 ;
struct V_299 * V_300 = V_40 -> V_300 ;
int V_10 , V_19 ;
V_8 -> V_199 = F_115 ( & V_300 -> V_2 , V_40 -> V_47 . V_48 *
sizeof( * V_8 -> V_199 ) * 2 ,
V_305 ) ;
if ( ! V_8 -> V_199 )
return - V_192 ;
for ( V_10 = 0 ; V_10 < V_40 -> V_47 . V_48 ; V_10 ++ ) {
V_19 = F_207 ( V_40 -> V_47 . V_217 [ V_10 ] , V_8 ) ;
if ( V_19 )
goto V_427;
}
return 0 ;
V_427:
F_121 ( & V_300 -> V_2 , V_8 -> V_199 ) ;
return V_19 ;
}
static int F_209 ( struct V_160 * V_21 )
{
int V_19 ;
if ( V_21 -> V_196 <= 0 || V_21 -> V_479 <= 0 )
return - V_107 ;
V_21 -> V_165 = F_210 ( V_21 -> V_196 , sizeof( V_21 -> V_165 [ 0 ] ) ,
V_305 ) ;
if ( ! V_21 -> V_165 ) {
V_19 = - V_192 ;
goto V_336;
}
V_19 = F_140 ( V_21 ) ;
if ( V_19 )
goto V_480;
if ( ! F_129 ( V_21 ) ) {
V_19 = F_144 ( V_21 ) ;
if ( V_19 )
goto V_481;
}
return 0 ;
V_481:
F_138 ( V_21 ) ;
V_480:
F_139 ( V_21 -> V_165 ) ;
V_21 -> V_165 = NULL ;
V_336:
return V_19 ;
}
static void F_211 ( struct V_160 * V_21 )
{
F_138 ( V_21 ) ;
F_139 ( V_21 -> V_165 ) ;
V_21 -> V_165 = NULL ;
V_21 -> V_342 = 0 ;
V_21 -> V_166 = 0 ;
}
int F_212 ( T_2 V_479 )
{
int V_482 ;
switch ( V_479 ) {
case 512 :
V_482 = V_483 ;
break;
case 1024 :
V_482 = V_484 ;
break;
case 2048 :
V_482 = V_485 ;
break;
case 4096 :
V_482 = V_486 ;
break;
default:
V_482 = V_485 ;
}
return V_482 ;
}
static void F_213 ( struct V_160 * V_21 )
{
T_6 V_162 = V_21 -> V_334 ;
struct V_474 * V_475 = V_21 -> V_217 ;
if ( ! F_129 ( V_21 ) ) {
F_214 ( V_475 , V_487 ,
( T_2 ) V_162 ) ;
F_214 ( V_475 , V_488 ,
( T_2 ) ( ( V_162 >> 31 ) >> 1 ) ) ;
F_214 ( V_475 , V_489 ,
F_212 ( V_21 -> V_479 ) ) ;
F_214 ( V_475 , V_490 ,
V_21 -> V_196 / 8 - 1 ) ;
} else {
F_214 ( V_475 , V_491 ,
( T_2 ) V_162 ) ;
F_214 ( V_475 , V_492 ,
( T_2 ) ( ( V_162 >> 31 ) >> 1 ) ) ;
F_214 ( V_475 , V_493 ,
F_212 ( V_21 -> V_479 ) ) ;
F_214 ( V_475 , V_494 ,
V_21 -> V_196 / 8 - 1 ) ;
}
}
static int F_215 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_41 ;
int V_495 = V_40 -> V_47 . V_48 * 2 ;
int V_10 , V_42 ;
int V_19 ;
for ( V_10 = 0 ; V_10 < V_495 ; V_10 ++ ) {
V_19 = F_209 ( V_8 -> V_199 [ V_10 ] . V_21 ) ;
if ( V_19 ) {
F_216 ( V_8 -> V_2 ,
L_28 , V_19 ) ;
goto V_496;
}
F_213 ( V_8 -> V_199 [ V_10 ] . V_21 ) ;
F_217 ( & V_8 -> V_199 [ V_10 ] . V_21 -> V_207 ) ;
}
return 0 ;
V_496:
for ( V_42 = V_10 - 1 ; V_42 >= 0 ; V_42 -- )
F_211 ( V_8 -> V_199 [ V_10 ] . V_21 ) ;
return - V_192 ;
}
static int F_218 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_41 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_40 -> V_47 . V_48 ; V_10 ++ ) {
if ( V_40 -> V_43 -> V_44 -> V_497 )
V_40 -> V_43 -> V_44 -> V_497 ( V_40 , V_10 ) ;
F_211 ( V_8 -> V_199 [ V_10 ] . V_21 ) ;
F_211 ( V_8 -> V_199 [ V_10 + V_40 -> V_47 . V_48 ] . V_21 ) ;
}
return 0 ;
}
static void F_219 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
struct V_39 * V_40 = V_8 -> V_41 ;
T_4 V_498 [ V_499 ] ;
if ( V_40 -> V_43 -> V_44 -> V_500 ) {
V_40 -> V_43 -> V_44 -> V_500 ( V_40 , V_498 ) ;
F_92 ( V_25 -> V_226 , V_498 ) ;
}
if ( ! F_91 ( V_25 -> V_226 ) ) {
F_220 ( V_25 ) ;
F_221 ( V_8 -> V_2 , L_29 ,
V_25 -> V_226 ) ;
}
if ( V_40 -> V_43 -> V_44 -> V_225 )
V_40 -> V_43 -> V_44 -> V_225 ( V_40 , V_25 -> V_226 ) ;
}
static void F_222 ( struct V_38 * V_25 )
{
struct V_7 * V_8 = F_19 ( V_25 ) ;
if ( ( V_25 -> V_227 & V_228 ) ||
( V_25 -> V_227 & V_229 ) ) {
V_8 -> V_44 . V_213 = F_63 ;
V_8 -> V_44 . V_206 = F_64 ;
} else {
V_8 -> V_44 . V_213 = F_56 ;
V_8 -> V_44 . V_206 = F_68 ;
}
}
static int F_223 ( struct V_39 * V_346 )
{
struct V_299 * V_300 = V_346 -> V_300 ;
struct V_7 * V_8 ;
struct V_38 * V_25 ;
int V_19 ;
V_25 = F_224 ( sizeof( struct V_7 ) ,
V_346 -> V_47 . V_48 ) ;
if ( ! V_25 )
return - V_192 ;
V_8 = F_19 ( V_25 ) ;
V_8 -> V_2 = & V_300 -> V_2 ;
V_8 -> V_25 = V_25 ;
V_8 -> V_41 = V_346 ;
V_346 -> V_47 . V_25 = V_25 ;
V_346 -> V_8 = ( void * ) V_8 ;
F_219 ( V_25 ) ;
F_122 ( V_25 ) ;
V_25 -> V_501 = V_502 ;
V_25 -> V_310 |= V_311 ;
V_25 -> V_503 = & V_504 ;
F_225 ( V_25 , & V_300 -> V_2 ) ;
F_226 ( V_25 ) ;
F_222 ( V_25 ) ;
F_21 ( V_25 ) ;
V_19 = F_208 ( V_8 ) ;
if ( V_19 ) {
V_19 = - V_192 ;
goto V_505;
}
V_19 = F_197 ( V_8 ) ;
if ( V_19 ) {
V_19 = - V_192 ;
goto V_506;
}
V_19 = F_215 ( V_8 ) ;
if ( V_19 ) {
V_19 = - V_192 ;
goto V_507;
}
V_19 = F_227 ( V_25 ) ;
if ( V_19 ) {
F_216 ( V_8 -> V_2 , L_30 ) ;
goto V_508;
}
V_25 -> V_509 = V_510 - ( V_365 + V_511 + V_369 ) ;
return V_19 ;
V_508:
V_507:
( void ) F_202 ( V_8 ) ;
V_8 -> V_199 = NULL ;
V_506:
V_505:
V_8 -> V_41 = NULL ;
F_228 ( V_25 ) ;
return V_19 ;
}
static void F_229 ( struct V_39 * V_346 , bool V_512 )
{
struct V_38 * V_25 = V_346 -> V_47 . V_25 ;
struct V_7 * V_8 = F_19 ( V_25 ) ;
int V_19 ;
if ( V_25 -> V_513 != V_514 )
F_230 ( V_25 ) ;
V_19 = F_202 ( V_8 ) ;
if ( V_19 )
F_7 ( V_25 , L_31 ) ;
V_19 = F_218 ( V_8 ) ;
if ( V_19 )
F_7 ( V_25 , L_32 ) ;
V_8 -> V_199 = NULL ;
F_228 ( V_25 ) ;
}
static void F_231 ( struct V_39 * V_346 , bool V_515 )
{
struct V_38 * V_25 = V_346 -> V_47 . V_25 ;
if ( ! V_25 )
return;
if ( V_515 ) {
F_232 ( V_25 ) ;
F_233 ( V_25 ) ;
F_234 ( V_25 , L_33 ) ;
} else {
F_21 ( V_25 ) ;
F_26 ( V_25 ) ;
F_234 ( V_25 , L_34 ) ;
}
}
static int T_10 F_235 ( void )
{
int V_19 ;
F_236 ( L_35 , V_516 , V_517 ) ;
F_236 ( L_36 , V_516 , V_518 ) ;
V_519 . type = V_520 ;
snprintf ( V_519 . V_23 , V_521 - 1 , L_37 ,
V_516 ) ;
V_519 . V_44 = & V_522 ;
V_19 = F_237 ( & V_519 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_238 ( & V_523 ) ;
if ( V_19 )
F_239 ( & V_519 ) ;
return V_19 ;
}
static void T_11 F_240 ( void )
{
F_241 ( & V_523 ) ;
F_239 ( & V_519 ) ;
}
