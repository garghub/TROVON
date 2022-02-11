static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 = ( V_6 -> V_7 . type == V_8 ) ? 5 : 0 ;
if ( V_3 < 256 ||
V_3 > V_9 - 24 - 6 - V_4 ) {
return - V_10 ;
}
#ifdef F_3
F_4 ( V_11 L_1 , V_2 -> V_12 , V_3 ) ;
#endif
V_2 -> V_13 = V_3 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , void * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_14 ;
int V_17 ;
if ( F_6 ( V_6 ) )
return - V_18 ;
V_17 = F_7 ( V_2 , V_16 ) ;
if ( V_17 == 0 )
memcpy ( V_6 -> V_7 . V_14 , V_16 -> V_19 , V_20 ) ;
return V_17 ;
}
static inline int F_8 ( int V_21 , int V_22 )
{
return V_21 == V_23 ||
V_22 == V_23 ||
( V_21 == V_24 && V_22 == V_25 ) ||
( V_21 == V_25 &&
( V_22 == V_25 ||
V_22 == V_24 ) ) ||
( V_21 == V_24 && V_22 == V_26 ) ||
( V_21 == V_26 &&
( V_22 == V_24 ||
V_22 == V_26 ) ) ;
}
static int F_9 ( struct V_5 * V_6 ,
enum V_27 V_28 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_5 * V_31 ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_10 () ;
F_11 (nsdata, &local->interfaces, list) {
struct V_1 * V_32 = V_31 -> V_2 ;
if ( V_32 != V_2 && F_6 ( V_31 ) ) {
if ( V_28 == V_33 &&
V_31 -> V_7 . type == V_33 )
return - V_18 ;
if ( F_12 ( V_2 -> V_34 , V_32 -> V_34 ) )
continue;
if ( ! F_8 ( V_28 ,
V_31 -> V_7 . type ) )
return - V_35 ;
if ( V_28 == V_26 &&
V_31 -> V_7 . type == V_24 )
V_6 -> V_36 = & V_31 -> V_37 . V_38 ;
}
}
return 0 ;
}
void F_13 ( struct V_5 * V_6 ,
const int V_39 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
T_1 V_40 = V_6 -> V_37 . V_41 ;
#define F_14 ( T_2 , T_3 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_14 ( V_42 , V_43 ) ;
F_14 ( V_44 , V_45 ) ;
F_14 ( V_46 , V_47 ) ;
F_14 ( V_46 , V_48 ) ;
F_14 ( V_49 , V_50 ) ;
#undef F_14
}
static int F_15 ( struct V_1 * V_2 , bool V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_52 * V_53 ;
T_1 V_54 = 0 ;
int V_55 ;
T_1 V_56 = 0 ;
switch ( V_6 -> V_7 . type ) {
case V_25 :
if ( ! F_16 ( V_6 -> V_37 . V_57 . V_58 ) )
return - V_59 ;
break;
case V_26 :
if ( ! V_6 -> V_36 )
return - V_59 ;
F_17 ( & V_6 -> V_37 . V_60 . V_61 , & V_6 -> V_36 -> V_62 ) ;
break;
case V_24 :
V_6 -> V_36 = & V_6 -> V_37 . V_38 ;
break;
case V_8 :
case V_63 :
case V_23 :
case V_33 :
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_18 ( 1 ) ;
break;
}
if ( V_30 -> V_68 == 0 ) {
V_55 = F_19 ( V_30 ) ;
if ( V_55 )
goto V_69;
if ( V_30 -> V_70 -> V_71 )
F_20 ( & V_30 -> V_72 ) ;
V_56 = ~ 0 ;
F_21 ( V_30 , true ) ;
F_22 ( V_30 ,
V_73 , 0 ) ;
}
if ( F_23 ( V_2 -> V_34 ) ) {
memcpy ( V_2 -> V_34 ,
V_30 -> V_74 . V_75 -> V_76 ,
V_20 ) ;
memcpy ( V_2 -> V_76 , V_2 -> V_34 , V_20 ) ;
if ( ! F_16 ( V_2 -> V_34 ) ) {
if ( ! V_30 -> V_68 )
F_24 ( V_30 ) ;
return - V_77 ;
}
}
switch ( V_6 -> V_7 . type ) {
case V_26 :
break;
case V_23 :
if ( V_6 -> V_37 . V_41 & V_78 ) {
V_30 -> V_79 ++ ;
break;
}
V_30 -> V_80 ++ ;
if ( V_30 -> V_80 == 1 ) {
V_30 -> V_74 . V_81 . V_40 |= V_82 ;
V_56 |= V_83 ;
}
F_13 ( V_6 , 1 ) ;
F_25 ( V_30 ) ;
F_26 ( V_2 ) ;
break;
default:
if ( V_51 ) {
V_55 = F_27 ( V_30 , & V_6 -> V_7 ) ;
if ( V_55 )
goto V_84;
}
if ( V_6 -> V_7 . type == V_24 ) {
V_30 -> V_85 ++ ;
V_30 -> V_86 ++ ;
F_25 ( V_30 ) ;
} else if ( V_6 -> V_7 . type == V_33 ) {
V_30 -> V_86 ++ ;
}
V_54 |= F_28 ( V_6 ) ;
F_29 ( V_6 , V_54 ) ;
if ( V_6 -> V_7 . type == V_63 )
F_30 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
F_31 ( V_87 , & V_6 -> V_88 ) ;
if ( V_6 -> V_7 . type == V_25 ) {
V_53 = F_32 ( V_6 , V_6 -> V_37 . V_57 . V_58 ,
V_89 ) ;
if ( ! V_53 ) {
V_55 = - V_90 ;
goto V_91;
}
V_53 -> V_40 |= V_92 ;
V_55 = F_33 ( V_53 ) ;
if ( V_55 ) {
goto V_91;
}
F_34 ( V_53 ) ;
}
if ( V_6 -> V_40 & V_93 )
F_35 ( & V_30 -> V_94 ) ;
if ( V_6 -> V_40 & V_95 )
F_35 ( & V_30 -> V_96 ) ;
F_36 ( & V_30 -> V_97 ) ;
V_56 |= F_37 ( V_30 ) ;
F_38 ( & V_30 -> V_97 ) ;
if ( V_51 )
V_30 -> V_68 ++ ;
if ( V_56 ) {
F_39 ( V_30 , V_56 ) ;
F_40 ( V_6 ) ;
}
F_41 ( V_30 , - 1 ) ;
F_42 ( V_2 ) ;
return 0 ;
V_91:
F_43 ( V_30 , & V_6 -> V_7 ) ;
V_84:
if ( ! V_30 -> V_68 )
F_24 ( V_30 ) ;
V_69:
V_6 -> V_36 = NULL ;
if ( V_6 -> V_7 . type == V_26 )
F_44 ( & V_6 -> V_37 . V_60 . V_61 ) ;
F_45 ( V_87 , & V_6 -> V_88 ) ;
return V_55 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_98 ;
if ( ! F_16 ( V_2 -> V_34 ) )
return - V_77 ;
V_98 = F_9 ( V_6 , V_6 -> V_7 . type ) ;
if ( V_98 )
return V_98 ;
return F_15 ( V_2 , true ) ;
}
static void F_47 ( struct V_5 * V_6 ,
bool V_99 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
unsigned long V_40 ;
struct V_100 * V_101 , * V_102 ;
T_1 V_56 = 0 ;
int V_103 ;
enum V_104 V_105 ;
F_45 ( V_87 , & V_6 -> V_88 ) ;
if ( V_30 -> V_106 == V_6 )
F_48 ( V_30 ) ;
F_49 ( V_6 -> V_2 ) ;
F_50 ( V_6 ) ;
F_51 ( V_30 , V_6 ) ;
if ( V_6 -> V_40 & V_93 )
F_52 ( & V_30 -> V_94 ) ;
if ( V_6 -> V_40 & V_95 )
F_52 ( & V_30 -> V_96 ) ;
if ( V_6 -> V_7 . type == V_24 ) {
V_30 -> V_85 -- ;
V_30 -> V_86 -- ;
} else if ( V_6 -> V_7 . type == V_33 ) {
V_30 -> V_86 -- ;
}
F_53 ( V_6 -> V_2 ) ;
F_54 ( & V_30 -> V_107 ) ;
F_55 ( & V_30 -> V_108 , & V_6 -> V_2 -> V_109 ,
V_6 -> V_2 -> V_110 ) ;
F_56 ( & V_30 -> V_107 ) ;
F_57 ( V_6 -> V_2 ) ;
F_25 ( V_30 ) ;
F_58 ( & V_30 -> V_111 ) ;
F_59 ( & V_30 -> V_112 ) ;
if ( V_6 -> V_7 . type == V_24 ) {
struct V_5 * V_60 , * V_113 ;
struct V_114 * V_115 =
F_60 ( V_6 -> V_37 . V_38 . V_116 ) ;
F_29 ( V_6 ,
V_117 ) ;
F_61 ( V_6 -> V_37 . V_38 . V_116 , NULL ) ;
F_62 () ;
F_63 ( V_115 ) ;
while ( ( V_101 = F_64 ( & V_6 -> V_37 . V_38 . V_118 ) ) ) {
V_30 -> V_119 -- ;
F_65 ( V_101 ) ;
}
F_66 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_67 ( V_60 -> V_2 ) ;
F_18 ( ! F_68 ( & V_6 -> V_37 . V_38 . V_62 ) ) ;
}
if ( V_99 )
V_30 -> V_68 -- ;
switch ( V_6 -> V_7 . type ) {
case V_26 :
F_44 ( & V_6 -> V_37 . V_60 . V_61 ) ;
break;
case V_23 :
if ( V_6 -> V_37 . V_41 & V_78 ) {
V_30 -> V_79 -- ;
break;
}
V_30 -> V_80 -- ;
if ( V_30 -> V_80 == 0 ) {
V_30 -> V_74 . V_81 . V_40 &= ~ V_82 ;
V_56 |= V_83 ;
}
F_13 ( V_6 , - 1 ) ;
F_25 ( V_30 ) ;
break;
default:
F_69 ( & V_6 -> V_120 ) ;
F_62 () ;
F_70 ( & V_6 -> V_121 ) ;
if ( V_6 -> V_7 . type == V_8 )
F_29 ( V_6 ,
V_117 ) ;
F_71 ( V_6 ) ;
if ( V_99 )
F_43 ( V_30 , & V_6 -> V_7 ) ;
}
V_6 -> V_36 = NULL ;
F_36 ( & V_30 -> V_97 ) ;
V_56 |= F_37 ( V_30 ) ;
F_38 ( & V_30 -> V_97 ) ;
F_41 ( V_30 , - 1 ) ;
if ( V_30 -> V_68 == 0 ) {
if ( V_30 -> V_70 -> V_71 )
F_72 ( & V_30 -> V_72 ) ;
F_73 ( V_30 ) ;
F_74 ( V_30 ) ;
V_56 = 0 ;
}
V_105 = V_30 -> V_122 ;
F_75 ( V_30 , NULL , V_123 ) ;
if ( V_56 || ( V_105 != V_30 -> V_122 ) )
F_39 ( V_30 , V_56 ) ;
F_76 ( & V_30 -> V_124 , V_40 ) ;
for ( V_103 = 0 ; V_103 < V_125 ; V_103 ++ ) {
F_77 (&local->pending[i], skb, tmp) {
struct V_126 * V_127 = F_78 ( V_101 ) ;
if ( V_127 -> V_47 . V_7 == & V_6 -> V_7 ) {
F_79 ( V_101 , & V_30 -> V_128 [ V_103 ] ) ;
F_80 ( V_101 ) ;
}
}
}
F_81 ( & V_30 -> V_124 , V_40 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_47 ( V_6 , true ) ;
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
int V_129 , V_130 , V_131 , V_132 ;
V_129 = ! ! ( V_2 -> V_40 & V_133 ) ;
V_130 = ! ! ( V_2 -> V_40 & V_134 ) ;
V_131 = ! ! ( V_6 -> V_40 & V_93 ) ;
V_132 = ! ! ( V_6 -> V_40 & V_95 ) ;
if ( V_129 != V_131 ) {
if ( V_2 -> V_40 & V_133 )
F_35 ( & V_30 -> V_94 ) ;
else
F_52 ( & V_30 -> V_94 ) ;
V_6 -> V_40 ^= V_93 ;
}
if ( V_130 != V_132 ) {
if ( V_2 -> V_40 & V_134 )
F_35 ( & V_30 -> V_96 ) ;
else
F_52 ( & V_30 -> V_96 ) ;
V_6 -> V_40 ^= V_95 ;
}
F_54 ( & V_30 -> V_107 ) ;
F_84 ( & V_30 -> V_108 , & V_2 -> V_109 , V_2 -> V_110 ) ;
F_56 ( & V_30 -> V_107 ) ;
F_85 ( & V_30 -> V_74 , & V_30 -> V_135 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
int V_136 ;
int V_103 ;
F_71 ( V_6 ) ;
F_87 ( V_6 ) ;
for ( V_103 = 0 ; V_103 < V_137 ; V_103 ++ )
F_88 ( & V_6 -> V_138 [ V_103 ] . V_139 ) ;
V_6 -> V_140 = 0 ;
if ( F_89 ( & V_6 -> V_7 ) )
F_90 ( V_6 ) ;
V_136 = F_51 ( V_30 , V_6 ) ;
F_18 ( V_136 ) ;
}
static T_4 F_91 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
return F_92 ( F_2 ( V_2 ) , V_101 ) ;
}
static T_4 F_93 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_141 * V_142 ;
struct V_143 * V_144 = ( void * ) V_101 -> V_145 ;
T_5 * V_146 ;
if ( V_30 -> V_74 . V_147 < 4 )
return 0 ;
if ( V_101 -> V_148 < 4 ||
V_101 -> V_148 < F_94 ( V_144 -> V_149 ) + 2 )
return 0 ;
V_142 = ( void * ) ( ( T_5 * ) V_101 -> V_145 + F_94 ( V_144 -> V_149 ) ) ;
if ( ! F_95 ( V_142 -> V_150 ) ) {
V_101 -> V_151 = 7 ;
return V_152 [ V_101 -> V_151 ] ;
}
if ( ! F_96 ( V_142 -> V_150 ) ) {
V_101 -> V_151 = 0 ;
return V_152 [ V_101 -> V_151 ] ;
}
V_146 = F_97 ( V_142 ) ;
V_101 -> V_151 = * V_146 & V_153 ;
return F_98 ( V_30 , V_101 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_100 ( V_2 ) ;
V_2 -> V_154 &= ~ V_155 ;
V_2 -> V_156 = & V_157 ;
V_2 -> V_158 = V_159 ;
}
static void F_101 ( struct V_160 * V_120 )
{
struct V_5 * V_6 =
F_102 ( V_120 , struct V_5 , V_120 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_100 * V_101 ;
struct V_52 * V_53 ;
struct V_161 * V_162 ;
if ( ! F_6 ( V_6 ) )
return;
if ( V_30 -> V_163 )
return;
if ( F_103 ( V_30 -> V_164 ,
L_2 ) )
return;
while ( ( V_101 = F_64 ( & V_6 -> V_121 ) ) ) {
struct V_165 * V_166 = ( void * ) V_101 -> V_145 ;
if ( V_101 -> V_167 == V_168 ) {
V_162 = ( void * ) & V_101 -> V_169 ;
F_104 ( & V_6 -> V_7 , V_162 -> V_170 ,
V_162 -> V_171 ) ;
} else if ( V_101 -> V_167 == V_172 ) {
V_162 = ( void * ) & V_101 -> V_169 ;
F_105 ( & V_6 -> V_7 , V_162 -> V_170 ,
V_162 -> V_171 ) ;
} else if ( F_106 ( V_166 -> V_150 ) &&
V_166 -> V_37 . V_173 . V_174 == V_175 ) {
int V_148 = V_101 -> V_148 ;
F_36 ( & V_30 -> V_176 ) ;
V_53 = F_107 ( V_6 , V_166 -> V_16 ) ;
if ( V_53 ) {
switch ( V_166 -> V_37 . V_173 . V_37 . V_177 . V_178 ) {
case V_179 :
F_108 (
V_30 , V_53 , V_166 , V_148 ) ;
break;
case V_180 :
F_109 ( V_30 , V_53 ,
V_166 , V_148 ) ;
break;
case V_181 :
F_110 ( V_6 , V_53 ,
V_166 , V_148 ) ;
break;
default:
F_18 ( 1 ) ;
break;
}
}
F_38 ( & V_30 -> V_176 ) ;
} else if ( F_96 ( V_166 -> V_150 ) ) {
struct V_141 * V_142 = ( void * ) V_166 ;
F_18 ( V_142 -> V_150 &
F_111 ( V_182 ) ) ;
F_18 ( ! ( V_142 -> V_183 &
F_111 ( V_184 ) ) ) ;
F_36 ( & V_30 -> V_176 ) ;
V_53 = F_107 ( V_6 , V_166 -> V_16 ) ;
if ( V_53 ) {
T_4 V_171 = * F_97 ( V_142 ) &
V_185 ;
F_112 (
V_53 , V_171 , V_186 ,
V_187 ,
true ) ;
}
F_38 ( & V_30 -> V_176 ) ;
} else switch ( V_6 -> V_7 . type ) {
case V_63 :
F_113 ( V_6 , V_101 ) ;
break;
case V_33 :
F_114 ( V_6 , V_101 ) ;
break;
case V_8 :
if ( ! F_89 ( & V_6 -> V_7 ) )
break;
F_115 ( V_6 , V_101 ) ;
break;
default:
F_103 ( 1 , L_3 ) ;
break;
}
F_116 ( V_101 ) ;
}
switch ( V_6 -> V_7 . type ) {
case V_63 :
F_117 ( V_6 ) ;
break;
case V_33 :
F_118 ( V_6 ) ;
break;
case V_8 :
if ( ! F_89 ( & V_6 -> V_7 ) )
break;
F_119 ( V_6 ) ;
break;
default:
break;
}
}
static void F_120 ( struct V_5 * V_6 ,
enum V_27 type )
{
memset ( & V_6 -> V_37 , 0 , sizeof( V_6 -> V_37 ) ) ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_188 = false ;
V_6 -> V_2 -> V_156 = & V_157 ;
V_6 -> V_189 . V_28 = type ;
V_6 -> V_190 = F_121 ( V_191 ) ;
V_6 -> V_192 = false ;
V_6 -> V_2 -> type = V_193 ;
F_122 ( & V_6 -> V_121 ) ;
F_123 ( & V_6 -> V_120 , F_101 ) ;
switch ( type ) {
case V_67 :
type = V_24 ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_188 = true ;
case V_24 :
F_122 ( & V_6 -> V_37 . V_38 . V_118 ) ;
F_124 ( & V_6 -> V_37 . V_38 . V_62 ) ;
break;
case V_66 :
type = V_63 ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_188 = true ;
case V_63 :
F_125 ( V_6 ) ;
break;
case V_33 :
F_126 ( V_6 ) ;
break;
case V_8 :
if ( F_89 ( & V_6 -> V_7 ) )
F_127 ( V_6 ) ;
break;
case V_23 :
V_6 -> V_2 -> type = V_194 ;
V_6 -> V_2 -> V_156 = & V_195 ;
V_6 -> V_37 . V_41 = V_196 |
V_197 ;
break;
case V_25 :
case V_26 :
break;
case V_64 :
case V_65 :
F_128 () ;
break;
}
F_129 ( V_6 ) ;
}
static int F_130 ( struct V_5 * V_6 ,
enum V_27 type )
{
struct V_29 * V_30 = V_6 -> V_30 ;
int V_17 , V_98 ;
enum V_27 V_198 = type ;
bool V_188 = false ;
F_10 () ;
if ( ! V_30 -> V_70 -> V_199 )
return - V_18 ;
switch ( V_6 -> V_7 . type ) {
case V_24 :
case V_63 :
case V_33 :
break;
default:
return - V_18 ;
}
switch ( type ) {
case V_24 :
case V_63 :
case V_33 :
break;
case V_66 :
V_188 = true ;
V_198 = V_63 ;
break;
case V_67 :
V_188 = true ;
V_198 = V_24 ;
break;
default:
return - V_18 ;
}
V_17 = F_9 ( V_6 , V_198 ) ;
if ( V_17 )
return V_17 ;
F_47 ( V_6 , false ) ;
F_86 ( V_6 -> V_2 ) ;
V_17 = F_131 ( V_30 , V_6 , V_198 , V_188 ) ;
if ( V_17 )
type = V_6 -> V_7 . type ;
F_120 ( V_6 , type ) ;
V_98 = F_15 ( V_6 -> V_2 , false ) ;
F_103 ( V_98 , L_4 , V_98 ) ;
return V_17 ;
}
int F_132 ( struct V_5 * V_6 ,
enum V_27 type )
{
int V_17 ;
F_10 () ;
if ( type == F_133 ( & V_6 -> V_7 ) )
return 0 ;
if ( V_6 -> V_30 -> V_200 -> V_40 & V_201 &&
type == V_33 )
return - V_202 ;
if ( F_6 ( V_6 ) ) {
V_17 = F_130 ( V_6 , type ) ;
if ( V_17 )
return V_17 ;
} else {
F_86 ( V_6 -> V_2 ) ;
F_120 ( V_6 , type ) ;
}
V_6 -> V_7 . V_203 . V_204 =
F_134 ( V_6 -> V_30 ,
V_6 -> V_30 -> V_74 . V_81 . V_205 -> V_206 ) ;
V_6 -> V_207 = 0 ;
if ( type == V_63 )
V_6 -> V_37 . V_208 . V_209 = false ;
return 0 ;
}
static void F_135 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_27 type )
{
struct V_5 * V_6 ;
T_6 V_210 , V_211 , V_14 , V_212 , V_213 ;
T_5 * V_214 ;
T_5 V_215 [ V_20 ] ;
int V_103 ;
memcpy ( V_2 -> V_76 , V_30 -> V_74 . V_75 -> V_76 , V_20 ) ;
if ( F_23 ( V_30 -> V_74 . V_75 -> V_216 ) &&
V_30 -> V_74 . V_75 -> V_217 <= 1 )
return;
F_36 ( & V_30 -> V_218 ) ;
switch ( type ) {
case V_23 :
break;
case V_25 :
case V_26 :
F_11 (sdata, &local->interfaces, list) {
if ( V_6 -> V_7 . type != V_24 )
continue;
memcpy ( V_2 -> V_76 , V_6 -> V_7 . V_14 , V_20 ) ;
break;
}
break;
default:
for ( V_103 = 0 ; V_103 < V_30 -> V_74 . V_75 -> V_217 ; V_103 ++ ) {
bool V_219 = false ;
F_11 (sdata, &local->interfaces, list) {
if ( memcmp ( V_30 -> V_74 . V_75 -> V_220 [ V_103 ] . V_14 ,
V_6 -> V_7 . V_14 , V_20 ) == 0 ) {
V_219 = true ;
break;
}
}
if ( ! V_219 ) {
memcpy ( V_2 -> V_76 ,
V_30 -> V_74 . V_75 -> V_220 [ V_103 ] . V_14 ,
V_20 ) ;
break;
}
}
if ( F_23 ( V_30 -> V_74 . V_75 -> V_216 ) )
break;
V_214 = V_30 -> V_74 . V_75 -> V_216 ;
V_210 = ( ( T_6 ) V_214 [ 0 ] << 5 * 8 ) | ( ( T_6 ) V_214 [ 1 ] << 4 * 8 ) |
( ( T_6 ) V_214 [ 2 ] << 3 * 8 ) | ( ( T_6 ) V_214 [ 3 ] << 2 * 8 ) |
( ( T_6 ) V_214 [ 4 ] << 1 * 8 ) | ( ( T_6 ) V_214 [ 5 ] << 0 * 8 ) ;
if ( F_136 ( V_210 ) + F_137 ( V_210 ) != F_138 ( V_210 ) ) {
F_4 ( V_11 L_5 ) ;
break;
}
V_214 = V_30 -> V_74 . V_75 -> V_76 ;
V_211 = ( ( T_6 ) V_214 [ 0 ] << 5 * 8 ) | ( ( T_6 ) V_214 [ 1 ] << 4 * 8 ) |
( ( T_6 ) V_214 [ 2 ] << 3 * 8 ) | ( ( T_6 ) V_214 [ 3 ] << 2 * 8 ) |
( ( T_6 ) V_214 [ 4 ] << 1 * 8 ) | ( ( T_6 ) V_214 [ 5 ] << 0 * 8 ) ;
V_213 = 1ULL << F_136 ( V_210 ) ;
V_212 = ( V_211 & V_210 ) ;
V_14 = ( V_211 & ~ V_210 ) | ( V_212 & V_210 ) ;
do {
bool V_219 = false ;
V_215 [ 5 ] = V_14 >> 0 * 8 ;
V_215 [ 4 ] = V_14 >> 1 * 8 ;
V_215 [ 3 ] = V_14 >> 2 * 8 ;
V_215 [ 2 ] = V_14 >> 3 * 8 ;
V_215 [ 1 ] = V_14 >> 4 * 8 ;
V_215 [ 0 ] = V_14 >> 5 * 8 ;
V_212 += V_213 ;
F_11 (sdata, &local->interfaces, list) {
if ( memcmp ( V_215 , V_6 -> V_7 . V_14 ,
V_20 ) == 0 ) {
V_219 = true ;
break;
}
}
if ( ! V_219 ) {
memcpy ( V_2 -> V_76 , V_215 , V_20 ) ;
break;
}
V_14 = ( V_211 & ~ V_210 ) | ( V_212 & V_210 ) ;
} while ( V_14 != V_211 );
break;
}
F_38 ( & V_30 -> V_218 ) ;
}
int F_139 ( struct V_29 * V_30 , const char * V_12 ,
struct V_1 * * V_221 , enum V_27 type ,
struct V_222 * V_223 )
{
struct V_1 * V_32 ;
struct V_5 * V_6 = NULL ;
int V_17 , V_103 ;
F_10 () ;
V_32 = F_140 ( sizeof( * V_6 ) + V_30 -> V_74 . V_224 ,
V_12 , F_99 , V_30 -> V_74 . V_147 , 1 ) ;
if ( ! V_32 )
return - V_90 ;
F_141 ( V_32 , F_142 ( V_30 -> V_74 . V_75 ) ) ;
V_32 -> V_225 = V_30 -> V_226 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_227
+ V_228 ;
V_32 -> V_229 = V_230 ;
V_17 = F_143 ( V_32 , V_32 -> V_12 ) ;
if ( V_17 < 0 )
goto V_231;
F_135 ( V_30 , V_32 , type ) ;
memcpy ( V_32 -> V_34 , V_32 -> V_76 , V_20 ) ;
F_144 ( V_32 , F_145 ( V_30 -> V_74 . V_75 ) ) ;
V_6 = F_146 ( V_32 ) ;
V_32 -> V_232 = & V_6 -> V_189 ;
memcpy ( V_6 -> V_7 . V_14 , V_32 -> V_34 , V_20 ) ;
memcpy ( V_6 -> V_12 , V_32 -> V_12 , V_233 ) ;
V_6 -> V_189 . V_75 = V_30 -> V_74 . V_75 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_2 = V_32 ;
#ifdef F_147
V_6 -> V_234 = true ;
#endif
for ( V_103 = 0 ; V_103 < V_137 ; V_103 ++ )
F_122 ( & V_6 -> V_138 [ V_103 ] . V_139 ) ;
F_124 ( & V_6 -> V_235 ) ;
for ( V_103 = 0 ; V_103 < V_236 ; V_103 ++ ) {
struct V_237 * V_238 ;
V_238 = V_30 -> V_74 . V_75 -> V_239 [ V_103 ] ;
V_6 -> V_240 [ V_103 ] =
V_238 ? ( 1 << V_238 -> V_241 ) - 1 : 0 ;
}
F_120 ( V_6 , type ) ;
if ( V_223 ) {
V_32 -> V_232 -> V_209 = V_223 -> V_209 ;
if ( type == V_63 )
V_6 -> V_37 . V_208 . V_209 = V_223 -> V_209 ;
}
V_17 = F_148 ( V_32 ) ;
if ( V_17 )
goto V_231;
F_36 ( & V_30 -> V_218 ) ;
F_149 ( & V_6 -> V_61 , & V_30 -> V_242 ) ;
F_38 ( & V_30 -> V_218 ) ;
if ( V_221 )
* V_221 = V_32 ;
return 0 ;
V_231:
V_159 ( V_32 ) ;
return V_17 ;
}
void F_150 ( struct V_5 * V_6 )
{
F_10 () ;
F_36 ( & V_6 -> V_30 -> V_218 ) ;
F_151 ( & V_6 -> V_61 ) ;
F_38 ( & V_6 -> V_30 -> V_218 ) ;
F_62 () ;
F_152 ( V_6 -> V_2 ) ;
}
void F_153 ( struct V_29 * V_30 )
{
struct V_5 * V_6 , * V_102 ;
F_154 ( V_243 ) ;
F_10 () ;
F_36 ( & V_30 -> V_218 ) ;
F_66 (sdata, tmp, &local->interfaces, list) {
F_44 ( & V_6 -> V_61 ) ;
F_155 ( V_6 -> V_2 , & V_243 ) ;
}
F_38 ( & V_30 -> V_218 ) ;
F_156 ( & V_243 ) ;
F_44 ( & V_243 ) ;
}
static T_1 F_157 ( struct V_29 * V_30 ,
const char * V_244 )
{
if ( ! ( V_30 -> V_74 . V_81 . V_40 & V_245 ) )
return 0 ;
#ifdef F_3
F_158 ( V_30 -> V_74 . V_75 , L_6 , V_244 ) ;
#endif
V_30 -> V_74 . V_81 . V_40 &= ~ V_245 ;
return V_246 ;
}
static T_1 F_159 ( struct V_29 * V_30 )
{
if ( V_30 -> V_74 . V_81 . V_40 & V_245 )
return 0 ;
#ifdef F_3
F_158 ( V_30 -> V_74 . V_75 , L_7 ) ;
#endif
F_160 ( V_30 , false ) ;
V_30 -> V_74 . V_81 . V_40 |= V_245 ;
return V_246 ;
}
T_1 F_37 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
int V_247 = 0 ;
bool V_248 = false , V_163 = false , V_249 = false ;
struct V_250 * V_251 ;
unsigned int V_252 = 0 , V_253 = 0 ;
#ifdef F_161
F_18 ( V_254 && ! F_162 () &&
! F_163 ( & V_30 -> V_218 ) ) ;
#endif
F_164 ( & V_30 -> V_97 ) ;
F_11 (sdata, &local->interfaces, list) {
if ( ! F_6 ( V_6 ) ) {
V_6 -> V_7 . V_203 . V_255 = true ;
continue;
}
V_6 -> V_256 = V_6 -> V_7 . V_203 . V_255 ;
if ( V_6 -> V_7 . type == V_63 &&
! V_6 -> V_37 . V_208 . V_257 ) {
V_6 -> V_7 . V_203 . V_255 = true ;
continue;
}
if ( V_6 -> V_7 . type == V_33 &&
! V_6 -> V_37 . V_258 . V_259 ) {
V_6 -> V_7 . V_203 . V_255 = true ;
continue;
}
V_247 ++ ;
}
F_11 (wk, &local->work_list, list) {
V_248 = true ;
V_251 -> V_6 -> V_7 . V_203 . V_255 = false ;
}
if ( V_30 -> V_106 ) {
V_163 = true ;
V_30 -> V_106 -> V_7 . V_203 . V_255 = false ;
}
if ( V_30 -> V_260 )
V_249 = true ;
F_11 (sdata, &local->interfaces, list) {
if ( V_6 -> V_256 == V_6 -> V_7 . V_203 . V_255 )
continue;
if ( ! F_6 ( V_6 ) )
continue;
F_29 ( V_6 , V_261 ) ;
}
if ( V_248 || V_163 || V_249 )
V_252 |= V_262 ;
else
V_253 |= V_262 ;
if ( V_247 )
V_252 |= V_263 ;
else
V_253 |= V_263 ;
F_22 ( V_30 , V_252 , V_253 ) ;
if ( V_249 )
return F_157 ( V_30 , L_8 ) ;
if ( V_248 )
return F_157 ( V_30 , L_9 ) ;
if ( V_163 )
return F_157 ( V_30 , L_10 ) ;
if ( ! V_247 )
return F_159 ( V_30 ) ;
else
return F_157 ( V_30 , L_11 ) ;
return 0 ;
}
void F_165 ( struct V_29 * V_30 )
{
T_1 V_264 ;
F_36 ( & V_30 -> V_218 ) ;
V_264 = F_37 ( V_30 ) ;
F_38 ( & V_30 -> V_218 ) ;
if ( V_264 )
F_39 ( V_30 , V_264 ) ;
}
static int F_166 ( struct V_265 * V_266 ,
unsigned long V_88 ,
void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_5 * V_6 ;
if ( V_88 != V_267 )
return 0 ;
if ( ! V_2 -> V_232 || ! V_2 -> V_232 -> V_75 )
return 0 ;
if ( V_2 -> V_232 -> V_75 -> V_268 != V_269 )
return 0 ;
V_6 = F_2 ( V_2 ) ;
memcpy ( V_6 -> V_12 , V_2 -> V_12 , V_233 ) ;
F_167 ( V_6 ) ;
return 0 ;
}
int F_168 ( void )
{
return F_169 ( & V_270 ) ;
}
void F_170 ( void )
{
F_171 ( & V_270 ) ;
}
