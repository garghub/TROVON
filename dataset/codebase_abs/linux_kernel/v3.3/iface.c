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
case V_26 : {
struct V_5 * V_60 ;
if ( ! V_6 -> V_36 )
return - V_59 ;
F_17 ( & V_6 -> V_37 . V_61 . V_62 , & V_6 -> V_36 -> V_63 ) ;
V_60 = F_18 ( V_6 -> V_36 ,
struct V_5 , V_37 . V_38 ) ;
V_6 -> V_64 =
V_60 -> V_64 ;
V_6 -> V_65 =
V_60 -> V_65 ;
break;
}
case V_24 :
V_6 -> V_36 = & V_6 -> V_37 . V_38 ;
break;
case V_8 :
case V_66 :
case V_23 :
case V_33 :
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_19 ( 1 ) ;
break;
}
if ( V_30 -> V_71 == 0 ) {
V_55 = F_20 ( V_30 ) ;
if ( V_55 )
goto V_72;
if ( V_30 -> V_73 -> V_74 )
F_21 ( & V_30 -> V_75 ) ;
V_56 = ~ 0 ;
F_22 ( V_30 , true ) ;
F_23 ( V_30 ,
V_76 , 0 ) ;
}
if ( F_24 ( V_2 -> V_34 ) ) {
memcpy ( V_2 -> V_34 ,
V_30 -> V_77 . V_78 -> V_79 ,
V_20 ) ;
memcpy ( V_2 -> V_79 , V_2 -> V_34 , V_20 ) ;
if ( ! F_16 ( V_2 -> V_34 ) ) {
if ( ! V_30 -> V_71 )
F_25 ( V_30 ) ;
return - V_80 ;
}
}
switch ( V_6 -> V_7 . type ) {
case V_26 :
break;
case V_23 :
if ( V_6 -> V_37 . V_41 & V_81 ) {
V_30 -> V_82 ++ ;
break;
}
V_30 -> V_83 ++ ;
if ( V_30 -> V_83 == 1 ) {
V_30 -> V_77 . V_84 . V_40 |= V_85 ;
V_56 |= V_86 ;
}
F_13 ( V_6 , 1 ) ;
F_26 ( V_30 ) ;
F_27 ( V_2 ) ;
break;
default:
if ( V_51 ) {
V_55 = F_28 ( V_30 , V_6 ) ;
if ( V_55 )
goto V_87;
}
if ( V_6 -> V_7 . type == V_24 ) {
V_30 -> V_88 ++ ;
V_30 -> V_89 ++ ;
F_26 ( V_30 ) ;
} else if ( V_6 -> V_7 . type == V_33 ) {
V_30 -> V_89 ++ ;
}
V_54 |= F_29 ( V_6 ) ;
F_30 ( V_6 , V_54 ) ;
if ( V_6 -> V_7 . type == V_66 ||
V_6 -> V_7 . type == V_33 )
F_31 ( V_2 ) ;
else
F_27 ( V_2 ) ;
F_32 ( V_6 ) ;
}
F_33 ( V_90 , & V_6 -> V_91 ) ;
if ( V_6 -> V_7 . type == V_25 ) {
V_53 = F_34 ( V_6 , V_6 -> V_37 . V_57 . V_58 ,
V_92 ) ;
if ( ! V_53 ) {
V_55 = - V_93 ;
goto V_94;
}
F_35 ( V_53 , V_95 ) ;
F_35 ( V_53 , V_96 ) ;
F_35 ( V_53 , V_97 ) ;
V_55 = F_36 ( V_53 ) ;
if ( V_55 ) {
goto V_94;
}
F_37 ( V_53 ) ;
}
if ( V_6 -> V_40 & V_98 )
F_38 ( & V_30 -> V_99 ) ;
if ( V_6 -> V_40 & V_100 )
F_38 ( & V_30 -> V_101 ) ;
F_39 ( & V_30 -> V_102 ) ;
V_56 |= F_40 ( V_30 ) ;
F_41 ( & V_30 -> V_102 ) ;
if ( V_51 )
V_30 -> V_71 ++ ;
if ( V_56 )
F_42 ( V_30 , V_56 ) ;
F_43 ( V_30 , - 1 ) ;
F_44 ( V_2 ) ;
return 0 ;
V_94:
F_45 ( V_30 , V_6 ) ;
V_87:
if ( ! V_30 -> V_71 )
F_25 ( V_30 ) ;
V_72:
V_6 -> V_36 = NULL ;
if ( V_6 -> V_7 . type == V_26 )
F_46 ( & V_6 -> V_37 . V_61 . V_62 ) ;
F_47 ( V_90 , & V_6 -> V_91 ) ;
return V_55 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_103 ;
if ( ! F_16 ( V_2 -> V_34 ) )
return - V_80 ;
V_103 = F_9 ( V_6 , V_6 -> V_7 . type ) ;
if ( V_103 )
return V_103 ;
return F_15 ( V_2 , true ) ;
}
static void F_49 ( struct V_5 * V_6 ,
bool V_104 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
unsigned long V_40 ;
struct V_105 * V_106 , * V_107 ;
T_1 V_56 = 0 ;
int V_108 ;
enum V_109 V_110 ;
F_47 ( V_90 , & V_6 -> V_91 ) ;
if ( V_30 -> V_111 == V_6 )
F_50 ( V_30 ) ;
F_51 ( V_6 -> V_2 ) ;
F_52 ( V_6 ) ;
F_53 ( V_30 , V_6 ) ;
if ( V_6 -> V_40 & V_98 )
F_54 ( & V_30 -> V_99 ) ;
if ( V_6 -> V_40 & V_100 )
F_54 ( & V_30 -> V_101 ) ;
if ( V_6 -> V_7 . type == V_24 ) {
V_30 -> V_88 -- ;
V_30 -> V_89 -- ;
} else if ( V_6 -> V_7 . type == V_33 ) {
V_30 -> V_89 -- ;
}
F_55 ( V_6 -> V_2 ) ;
F_56 ( & V_30 -> V_112 ) ;
F_57 ( & V_30 -> V_113 , & V_6 -> V_2 -> V_114 ,
V_6 -> V_2 -> V_115 ) ;
F_58 ( & V_30 -> V_112 ) ;
F_59 ( V_6 -> V_2 ) ;
F_26 ( V_30 ) ;
F_60 ( & V_30 -> V_116 ) ;
F_61 ( & V_30 -> V_117 ) ;
if ( V_6 -> V_7 . type == V_24 ) {
struct V_5 * V_61 , * V_118 ;
struct V_119 * V_120 =
F_62 ( V_6 -> V_37 . V_38 . V_121 ) ;
struct V_105 * V_122 =
F_62 ( V_6 -> V_37 . V_38 . V_123 ) ;
F_30 ( V_6 ,
V_124 ) ;
F_63 ( V_6 -> V_37 . V_38 . V_121 , NULL ) ;
F_63 ( V_6 -> V_37 . V_38 . V_123 , NULL ) ;
F_64 () ;
F_65 ( V_120 ) ;
F_66 ( V_122 ) ;
F_67 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_68 ( V_61 -> V_2 ) ;
F_19 ( ! F_69 ( & V_6 -> V_37 . V_38 . V_63 ) ) ;
V_30 -> V_125 -= F_70 ( & V_6 -> V_37 . V_38 . V_126 ) ;
F_71 ( & V_6 -> V_37 . V_38 . V_126 ) ;
}
if ( V_104 )
V_30 -> V_71 -- ;
switch ( V_6 -> V_7 . type ) {
case V_26 :
F_46 ( & V_6 -> V_37 . V_61 . V_62 ) ;
break;
case V_23 :
if ( V_6 -> V_37 . V_41 & V_81 ) {
V_30 -> V_82 -- ;
break;
}
V_30 -> V_83 -- ;
if ( V_30 -> V_83 == 0 ) {
V_30 -> V_77 . V_84 . V_40 &= ~ V_85 ;
V_56 |= V_86 ;
}
F_13 ( V_6 , - 1 ) ;
F_26 ( V_30 ) ;
break;
default:
F_72 ( & V_6 -> V_127 ) ;
F_64 () ;
F_71 ( & V_6 -> V_128 ) ;
if ( V_6 -> V_7 . type == V_8 )
F_30 ( V_6 ,
V_124 ) ;
F_73 ( V_6 ) ;
if ( V_104 )
F_45 ( V_30 , V_6 ) ;
}
V_6 -> V_36 = NULL ;
F_39 ( & V_30 -> V_102 ) ;
V_56 |= F_40 ( V_30 ) ;
F_41 ( & V_30 -> V_102 ) ;
F_43 ( V_30 , - 1 ) ;
if ( V_30 -> V_71 == 0 ) {
if ( V_30 -> V_73 -> V_74 )
F_74 ( & V_30 -> V_75 ) ;
F_75 ( V_30 ) ;
F_76 ( V_30 ) ;
V_56 = 0 ;
}
V_110 = V_30 -> V_129 ;
F_77 ( V_30 , NULL , V_130 ) ;
if ( V_56 || ( V_110 != V_30 -> V_129 ) )
F_42 ( V_30 , V_56 ) ;
F_78 ( & V_30 -> V_131 , V_40 ) ;
for ( V_108 = 0 ; V_108 < V_132 ; V_108 ++ ) {
F_79 (&local->pending[i], skb, tmp) {
struct V_133 * V_134 = F_80 ( V_106 ) ;
if ( V_134 -> V_47 . V_7 == & V_6 -> V_7 ) {
F_81 ( V_106 , & V_30 -> V_135 [ V_108 ] ) ;
F_82 ( V_106 ) ;
}
}
}
F_83 ( & V_30 -> V_131 , V_40 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_49 ( V_6 , true ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
int V_136 , V_137 , V_138 , V_139 ;
V_136 = ! ! ( V_2 -> V_40 & V_140 ) ;
V_137 = ! ! ( V_2 -> V_40 & V_141 ) ;
V_138 = ! ! ( V_6 -> V_40 & V_98 ) ;
V_139 = ! ! ( V_6 -> V_40 & V_100 ) ;
if ( V_136 != V_138 ) {
if ( V_2 -> V_40 & V_140 )
F_38 ( & V_30 -> V_99 ) ;
else
F_54 ( & V_30 -> V_99 ) ;
V_6 -> V_40 ^= V_98 ;
}
if ( V_137 != V_139 ) {
if ( V_2 -> V_40 & V_141 )
F_38 ( & V_30 -> V_101 ) ;
else
F_54 ( & V_30 -> V_101 ) ;
V_6 -> V_40 ^= V_100 ;
}
F_56 ( & V_30 -> V_112 ) ;
F_86 ( & V_30 -> V_113 , & V_2 -> V_114 , V_2 -> V_115 ) ;
F_58 ( & V_30 -> V_112 ) ;
F_87 ( & V_30 -> V_77 , & V_30 -> V_142 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
int V_143 ;
int V_108 ;
F_73 ( V_6 ) ;
F_89 ( V_6 ) ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ )
F_90 ( & V_6 -> V_145 [ V_108 ] . V_146 ) ;
V_6 -> V_147 = 0 ;
if ( F_91 ( & V_6 -> V_7 ) )
F_92 ( V_6 ) ;
V_143 = F_53 ( V_30 , V_6 ) ;
F_19 ( V_143 ) ;
}
static T_4 F_93 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
return F_94 ( F_2 ( V_2 ) , V_106 ) ;
}
static T_4 F_95 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_148 * V_149 ;
struct V_150 * V_151 = ( void * ) V_106 -> V_152 ;
if ( V_30 -> V_77 . V_153 < 4 )
return 0 ;
if ( V_106 -> V_154 < 4 ||
V_106 -> V_154 < F_96 ( V_151 -> V_155 ) + 2 )
return 0 ;
V_149 = ( void * ) ( ( V_156 * ) V_106 -> V_152 + F_96 ( V_151 -> V_155 ) ) ;
return F_97 ( V_30 , V_106 , V_149 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_99 ( V_2 ) ;
V_2 -> V_157 &= ~ V_158 ;
V_2 -> V_159 = & V_160 ;
V_2 -> V_161 = V_162 ;
}
static void F_100 ( struct V_163 * V_127 )
{
struct V_5 * V_6 =
F_18 ( V_127 , struct V_5 , V_127 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_105 * V_106 ;
struct V_52 * V_53 ;
struct V_164 * V_165 ;
if ( ! F_6 ( V_6 ) )
return;
if ( V_30 -> V_166 )
return;
if ( F_101 ( V_30 -> V_167 ,
L_2 ) )
return;
while ( ( V_106 = F_102 ( & V_6 -> V_128 ) ) ) {
struct V_168 * V_169 = ( void * ) V_106 -> V_152 ;
if ( V_106 -> V_170 == V_171 ) {
V_165 = ( void * ) & V_106 -> V_172 ;
F_103 ( & V_6 -> V_7 , V_165 -> V_173 ,
V_165 -> V_174 ) ;
} else if ( V_106 -> V_170 == V_175 ) {
V_165 = ( void * ) & V_106 -> V_172 ;
F_104 ( & V_6 -> V_7 , V_165 -> V_173 ,
V_165 -> V_174 ) ;
} else if ( F_105 ( V_169 -> V_176 ) &&
V_169 -> V_37 . V_177 . V_178 == V_179 ) {
int V_154 = V_106 -> V_154 ;
F_39 ( & V_30 -> V_180 ) ;
V_53 = F_106 ( V_6 , V_169 -> V_16 ) ;
if ( V_53 ) {
switch ( V_169 -> V_37 . V_177 . V_37 . V_181 . V_182 ) {
case V_183 :
F_107 (
V_30 , V_53 , V_169 , V_154 ) ;
break;
case V_184 :
F_108 ( V_30 , V_53 ,
V_169 , V_154 ) ;
break;
case V_185 :
F_109 ( V_6 , V_53 ,
V_169 , V_154 ) ;
break;
default:
F_19 ( 1 ) ;
break;
}
}
F_41 ( & V_30 -> V_180 ) ;
} else if ( F_110 ( V_169 -> V_176 ) ) {
struct V_148 * V_149 = ( void * ) V_169 ;
F_19 ( V_149 -> V_176 &
F_111 ( V_186 ) ) ;
F_19 ( ! ( V_149 -> V_187 &
F_111 ( V_188 ) ) ) ;
F_39 ( & V_30 -> V_180 ) ;
V_53 = F_106 ( V_6 , V_169 -> V_16 ) ;
if ( V_53 ) {
T_4 V_174 = * F_112 ( V_149 ) &
V_189 ;
F_113 (
V_53 , V_174 , V_190 ,
V_191 ,
true ) ;
}
F_41 ( & V_30 -> V_180 ) ;
} else switch ( V_6 -> V_7 . type ) {
case V_66 :
F_114 ( V_6 , V_106 ) ;
break;
case V_33 :
F_115 ( V_6 , V_106 ) ;
break;
case V_8 :
if ( ! F_91 ( & V_6 -> V_7 ) )
break;
F_116 ( V_6 , V_106 ) ;
break;
default:
F_101 ( 1 , L_3 ) ;
break;
}
F_66 ( V_106 ) ;
}
switch ( V_6 -> V_7 . type ) {
case V_66 :
F_117 ( V_6 ) ;
break;
case V_33 :
F_118 ( V_6 ) ;
break;
case V_8 :
if ( ! F_91 ( & V_6 -> V_7 ) )
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
V_6 -> V_7 . V_192 = false ;
V_6 -> V_2 -> V_159 = & V_160 ;
V_6 -> V_193 . V_28 = type ;
V_6 -> V_64 = F_121 ( V_194 ) ;
V_6 -> V_65 = false ;
V_6 -> V_195 = 0 ;
V_6 -> V_2 -> type = V_196 ;
F_122 ( & V_6 -> V_128 ) ;
F_123 ( & V_6 -> V_127 , F_100 ) ;
switch ( type ) {
case V_70 :
type = V_24 ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_192 = true ;
case V_24 :
F_122 ( & V_6 -> V_37 . V_38 . V_126 ) ;
F_124 ( & V_6 -> V_37 . V_38 . V_63 ) ;
break;
case V_69 :
type = V_66 ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_192 = true ;
case V_66 :
F_125 ( V_6 ) ;
break;
case V_33 :
F_126 ( V_6 ) ;
break;
case V_8 :
if ( F_91 ( & V_6 -> V_7 ) )
F_127 ( V_6 ) ;
break;
case V_23 :
V_6 -> V_2 -> type = V_197 ;
V_6 -> V_2 -> V_159 = & V_198 ;
V_6 -> V_37 . V_41 = V_199 |
V_200 ;
break;
case V_25 :
case V_26 :
break;
case V_67 :
case V_68 :
F_128 () ;
break;
}
F_129 ( V_6 ) ;
}
static int F_130 ( struct V_5 * V_6 ,
enum V_27 type )
{
struct V_29 * V_30 = V_6 -> V_30 ;
int V_17 , V_103 ;
enum V_27 V_201 = type ;
bool V_192 = false ;
F_10 () ;
if ( ! V_30 -> V_73 -> V_202 )
return - V_18 ;
switch ( V_6 -> V_7 . type ) {
case V_24 :
case V_66 :
case V_33 :
break;
default:
return - V_18 ;
}
switch ( type ) {
case V_24 :
case V_66 :
case V_33 :
break;
case V_69 :
V_192 = true ;
V_201 = V_66 ;
break;
case V_70 :
V_192 = true ;
V_201 = V_24 ;
break;
default:
return - V_18 ;
}
V_17 = F_9 ( V_6 , V_201 ) ;
if ( V_17 )
return V_17 ;
F_49 ( V_6 , false ) ;
F_88 ( V_6 -> V_2 ) ;
V_17 = F_131 ( V_30 , V_6 , V_201 , V_192 ) ;
if ( V_17 )
type = V_6 -> V_7 . type ;
F_120 ( V_6 , type ) ;
V_103 = F_15 ( V_6 -> V_2 , false ) ;
F_101 ( V_103 , L_4 , V_103 ) ;
return V_17 ;
}
int F_132 ( struct V_5 * V_6 ,
enum V_27 type )
{
int V_17 ;
F_10 () ;
if ( type == F_133 ( & V_6 -> V_7 ) )
return 0 ;
if ( V_6 -> V_30 -> V_203 -> V_40 & V_204 &&
type == V_33 )
return - V_205 ;
if ( F_6 ( V_6 ) ) {
V_17 = F_130 ( V_6 , type ) ;
if ( V_17 )
return V_17 ;
} else {
F_88 ( V_6 -> V_2 ) ;
F_120 ( V_6 , type ) ;
}
V_6 -> V_7 . V_206 . V_207 =
F_134 ( V_6 -> V_30 ,
V_6 -> V_30 -> V_77 . V_84 . V_208 -> V_209 ) ;
V_6 -> V_210 = 0 ;
if ( type == V_66 )
V_6 -> V_37 . V_211 . V_212 = false ;
return 0 ;
}
static void F_135 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_27 type )
{
struct V_5 * V_6 ;
T_5 V_213 , V_214 , V_14 , V_215 , V_216 ;
V_156 * V_217 ;
V_156 V_218 [ V_20 ] ;
int V_108 ;
memcpy ( V_2 -> V_79 , V_30 -> V_77 . V_78 -> V_79 , V_20 ) ;
if ( F_24 ( V_30 -> V_77 . V_78 -> V_219 ) &&
V_30 -> V_77 . V_78 -> V_220 <= 1 )
return;
F_39 ( & V_30 -> V_221 ) ;
switch ( type ) {
case V_23 :
break;
case V_25 :
case V_26 :
F_11 (sdata, &local->interfaces, list) {
if ( V_6 -> V_7 . type != V_24 )
continue;
memcpy ( V_2 -> V_79 , V_6 -> V_7 . V_14 , V_20 ) ;
break;
}
break;
default:
for ( V_108 = 0 ; V_108 < V_30 -> V_77 . V_78 -> V_220 ; V_108 ++ ) {
bool V_222 = false ;
F_11 (sdata, &local->interfaces, list) {
if ( memcmp ( V_30 -> V_77 . V_78 -> V_223 [ V_108 ] . V_14 ,
V_6 -> V_7 . V_14 , V_20 ) == 0 ) {
V_222 = true ;
break;
}
}
if ( ! V_222 ) {
memcpy ( V_2 -> V_79 ,
V_30 -> V_77 . V_78 -> V_223 [ V_108 ] . V_14 ,
V_20 ) ;
break;
}
}
if ( F_24 ( V_30 -> V_77 . V_78 -> V_219 ) )
break;
V_217 = V_30 -> V_77 . V_78 -> V_219 ;
V_213 = ( ( T_5 ) V_217 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_217 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_217 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_217 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_217 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_217 [ 5 ] << 0 * 8 ) ;
if ( F_136 ( V_213 ) + F_137 ( V_213 ) != F_138 ( V_213 ) ) {
F_4 ( V_11 L_5 ) ;
break;
}
V_217 = V_30 -> V_77 . V_78 -> V_79 ;
V_214 = ( ( T_5 ) V_217 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_217 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_217 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_217 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_217 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_217 [ 5 ] << 0 * 8 ) ;
V_216 = 1ULL << F_136 ( V_213 ) ;
V_215 = ( V_214 & V_213 ) ;
V_14 = ( V_214 & ~ V_213 ) | ( V_215 & V_213 ) ;
do {
bool V_222 = false ;
V_218 [ 5 ] = V_14 >> 0 * 8 ;
V_218 [ 4 ] = V_14 >> 1 * 8 ;
V_218 [ 3 ] = V_14 >> 2 * 8 ;
V_218 [ 2 ] = V_14 >> 3 * 8 ;
V_218 [ 1 ] = V_14 >> 4 * 8 ;
V_218 [ 0 ] = V_14 >> 5 * 8 ;
V_215 += V_216 ;
F_11 (sdata, &local->interfaces, list) {
if ( memcmp ( V_218 , V_6 -> V_7 . V_14 ,
V_20 ) == 0 ) {
V_222 = true ;
break;
}
}
if ( ! V_222 ) {
memcpy ( V_2 -> V_79 , V_218 , V_20 ) ;
break;
}
V_14 = ( V_214 & ~ V_213 ) | ( V_215 & V_213 ) ;
} while ( V_14 != V_214 );
break;
}
F_41 ( & V_30 -> V_221 ) ;
}
int F_139 ( struct V_29 * V_30 , const char * V_12 ,
struct V_1 * * V_224 , enum V_27 type ,
struct V_225 * V_226 )
{
struct V_1 * V_32 ;
struct V_5 * V_6 = NULL ;
int V_17 , V_108 ;
F_10 () ;
V_32 = F_140 ( sizeof( * V_6 ) + V_30 -> V_77 . V_227 ,
V_12 , F_98 , V_30 -> V_77 . V_153 , 1 ) ;
if ( ! V_32 )
return - V_93 ;
F_141 ( V_32 , F_142 ( V_30 -> V_77 . V_78 ) ) ;
V_32 -> V_228 = V_30 -> V_229 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_230
+ V_231 ;
V_32 -> V_232 = V_233 ;
V_17 = F_143 ( V_32 , V_32 -> V_12 ) ;
if ( V_17 < 0 )
goto V_234;
F_135 ( V_30 , V_32 , type ) ;
memcpy ( V_32 -> V_34 , V_32 -> V_79 , V_20 ) ;
F_144 ( V_32 , F_145 ( V_30 -> V_77 . V_78 ) ) ;
V_6 = F_146 ( V_32 ) ;
V_32 -> V_235 = & V_6 -> V_193 ;
memcpy ( V_6 -> V_7 . V_14 , V_32 -> V_34 , V_20 ) ;
memcpy ( V_6 -> V_12 , V_32 -> V_12 , V_236 ) ;
V_6 -> V_193 . V_78 = V_30 -> V_77 . V_78 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_2 = V_32 ;
#ifdef F_147
V_6 -> V_237 = true ;
#endif
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ )
F_122 ( & V_6 -> V_145 [ V_108 ] . V_146 ) ;
F_124 ( & V_6 -> V_238 ) ;
for ( V_108 = 0 ; V_108 < V_239 ; V_108 ++ ) {
struct V_240 * V_241 ;
V_241 = V_30 -> V_77 . V_78 -> V_242 [ V_108 ] ;
V_6 -> V_243 [ V_108 ] =
V_241 ? ( 1 << V_241 -> V_244 ) - 1 : 0 ;
}
F_120 ( V_6 , type ) ;
if ( V_226 ) {
V_32 -> V_235 -> V_212 = V_226 -> V_212 ;
if ( type == V_66 )
V_6 -> V_37 . V_211 . V_212 = V_226 -> V_212 ;
}
V_17 = F_148 ( V_32 ) ;
if ( V_17 )
goto V_234;
F_39 ( & V_30 -> V_221 ) ;
F_149 ( & V_6 -> V_62 , & V_30 -> V_245 ) ;
F_41 ( & V_30 -> V_221 ) ;
if ( V_224 )
* V_224 = V_32 ;
return 0 ;
V_234:
V_162 ( V_32 ) ;
return V_17 ;
}
void F_150 ( struct V_5 * V_6 )
{
F_10 () ;
F_39 ( & V_6 -> V_30 -> V_221 ) ;
F_151 ( & V_6 -> V_62 ) ;
F_41 ( & V_6 -> V_30 -> V_221 ) ;
if ( F_91 ( & V_6 -> V_7 ) )
F_152 ( V_6 ) ;
F_64 () ;
F_153 ( V_6 -> V_2 ) ;
}
void F_154 ( struct V_29 * V_30 )
{
struct V_5 * V_6 , * V_107 ;
F_155 ( V_246 ) ;
F_10 () ;
F_39 ( & V_30 -> V_221 ) ;
F_67 (sdata, tmp, &local->interfaces, list) {
F_46 ( & V_6 -> V_62 ) ;
if ( F_91 ( & V_6 -> V_7 ) )
F_152 ( V_6 ) ;
F_156 ( V_6 -> V_2 , & V_246 ) ;
}
F_41 ( & V_30 -> V_221 ) ;
F_157 ( & V_246 ) ;
F_46 ( & V_246 ) ;
}
static T_1 F_158 ( struct V_29 * V_30 ,
const char * V_247 )
{
if ( ! ( V_30 -> V_77 . V_84 . V_40 & V_248 ) )
return 0 ;
#ifdef F_3
F_159 ( V_30 -> V_77 . V_78 , L_6 , V_247 ) ;
#endif
V_30 -> V_77 . V_84 . V_40 &= ~ V_248 ;
return V_249 ;
}
static T_1 F_160 ( struct V_29 * V_30 )
{
if ( V_30 -> V_77 . V_84 . V_40 & V_248 )
return 0 ;
#ifdef F_3
F_159 ( V_30 -> V_77 . V_78 , L_7 ) ;
#endif
F_161 ( V_30 , false ) ;
V_30 -> V_77 . V_84 . V_40 |= V_248 ;
return V_249 ;
}
T_1 F_40 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
int V_250 = 0 ;
bool V_251 = false , V_166 = false , V_252 = false ;
struct V_253 * V_254 ;
unsigned int V_255 = 0 , V_256 = 0 ;
#ifdef F_162
F_19 ( V_257 && ! F_163 () &&
! F_164 ( & V_30 -> V_221 ) ) ;
#endif
F_165 ( & V_30 -> V_102 ) ;
F_11 (sdata, &local->interfaces, list) {
if ( ! F_6 ( V_6 ) ) {
V_6 -> V_7 . V_206 . V_258 = true ;
continue;
}
V_6 -> V_259 = V_6 -> V_7 . V_206 . V_258 ;
if ( V_6 -> V_7 . type == V_66 &&
! V_6 -> V_37 . V_211 . V_260 ) {
V_6 -> V_7 . V_206 . V_258 = true ;
continue;
}
if ( V_6 -> V_7 . type == V_33 &&
! V_6 -> V_37 . V_261 . V_262 ) {
V_6 -> V_7 . V_206 . V_258 = true ;
continue;
}
V_6 -> V_7 . V_206 . V_258 = false ;
V_250 ++ ;
}
F_11 (wk, &local->work_list, list) {
V_251 = true ;
V_254 -> V_6 -> V_7 . V_206 . V_258 = false ;
}
if ( V_30 -> V_111 ) {
V_166 = true ;
V_30 -> V_111 -> V_7 . V_206 . V_258 = false ;
}
if ( V_30 -> V_263 )
V_252 = true ;
F_11 (sdata, &local->interfaces, list) {
if ( V_6 -> V_7 . type == V_23 ||
V_6 -> V_7 . type == V_26 )
continue;
if ( V_6 -> V_259 == V_6 -> V_7 . V_206 . V_258 )
continue;
if ( ! F_6 ( V_6 ) )
continue;
F_30 ( V_6 , V_264 ) ;
}
if ( V_251 || V_166 || V_252 )
V_255 |= V_265 ;
else
V_256 |= V_265 ;
if ( V_250 )
V_255 |= V_266 ;
else
V_256 |= V_266 ;
F_23 ( V_30 , V_255 , V_256 ) ;
if ( V_252 )
return F_158 ( V_30 , L_8 ) ;
if ( V_251 )
return F_158 ( V_30 , L_9 ) ;
if ( V_166 )
return F_158 ( V_30 , L_10 ) ;
if ( ! V_250 )
return F_160 ( V_30 ) ;
else
return F_158 ( V_30 , L_11 ) ;
return 0 ;
}
void F_166 ( struct V_29 * V_30 )
{
T_1 V_267 ;
F_39 ( & V_30 -> V_221 ) ;
V_267 = F_40 ( V_30 ) ;
F_41 ( & V_30 -> V_221 ) ;
if ( V_267 )
F_42 ( V_30 , V_267 ) ;
}
static int F_167 ( struct V_268 * V_269 ,
unsigned long V_91 ,
void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_5 * V_6 ;
if ( V_91 != V_270 )
return 0 ;
if ( ! V_2 -> V_235 || ! V_2 -> V_235 -> V_78 )
return 0 ;
if ( V_2 -> V_235 -> V_78 -> V_271 != V_272 )
return 0 ;
V_6 = F_2 ( V_2 ) ;
memcpy ( V_6 -> V_12 , V_2 -> V_12 , V_236 ) ;
F_168 ( V_6 ) ;
return 0 ;
}
int F_169 ( void )
{
return F_170 ( & V_273 ) ;
}
void F_171 ( void )
{
F_172 ( & V_273 ) ;
}
