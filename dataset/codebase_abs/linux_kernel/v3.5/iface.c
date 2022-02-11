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
if ( ! F_12 ( V_2 -> V_34 , V_32 -> V_34 ) )
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
static int F_13 ( struct V_5 * V_6 )
{
int V_39 = V_6 -> V_30 -> V_40 . V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( F_14 ( V_6 -> V_7 . V_44 [ V_42 ] ==
V_45 ) )
return - V_10 ;
if ( F_14 ( V_6 -> V_7 . V_44 [ V_42 ] >=
V_39 ) )
return - V_10 ;
}
if ( ( V_6 -> V_7 . type != V_24 ) ||
! ( V_6 -> V_30 -> V_40 . V_46 & V_47 ) ) {
V_6 -> V_7 . V_48 = V_45 ;
return 0 ;
}
if ( F_14 ( V_6 -> V_7 . V_48 == V_45 ) )
return - V_10 ;
if ( F_14 ( V_6 -> V_7 . V_48 >= V_39 ) )
return - V_10 ;
return 0 ;
}
void F_15 ( struct V_5 * V_6 ,
const int V_49 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
T_1 V_46 = V_6 -> V_37 . V_50 ;
#define F_16 ( T_2 , T_3 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_16 ( V_51 , V_52 ) ;
F_16 ( V_53 , V_54 ) ;
F_16 ( V_55 , V_56 ) ;
F_16 ( V_55 , V_57 ) ;
F_16 ( V_58 , V_59 ) ;
#undef F_16
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_30 -> V_40 . V_46 & V_47 )
V_6 -> V_7 . V_44 [ V_42 ] = V_45 ;
else if ( V_30 -> V_40 . V_41 >= V_43 )
V_6 -> V_7 . V_44 [ V_42 ] = V_42 ;
else
V_6 -> V_7 . V_44 [ V_42 ] = 0 ;
}
V_6 -> V_7 . V_48 = V_45 ;
}
static int F_18 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
int V_17 ;
if ( ! ( V_30 -> V_40 . V_46 & V_60 ) )
return 0 ;
if ( V_30 -> V_61 )
return 0 ;
V_6 = F_19 ( sizeof( * V_6 ) + V_30 -> V_40 . V_62 , V_63 ) ;
if ( ! V_6 )
return - V_64 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_7 . type = V_23 ;
snprintf ( V_6 -> V_12 , V_65 , L_2 ,
F_20 ( V_30 -> V_40 . V_66 ) ) ;
F_17 ( V_6 ) ;
V_17 = F_21 ( V_30 , V_6 ) ;
if ( F_22 ( V_17 ) ) {
F_23 ( V_6 ) ;
return V_17 ;
}
V_17 = F_13 ( V_6 ) ;
if ( V_17 ) {
F_23 ( V_6 ) ;
return V_17 ;
}
F_24 ( V_30 -> V_61 , V_6 ) ;
return 0 ;
}
static void F_25 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
if ( ! ( V_30 -> V_40 . V_46 & V_60 ) )
return;
V_6 = F_26 ( V_30 -> V_61 ) ;
if ( ! V_6 )
return;
F_24 ( V_30 -> V_61 , NULL ) ;
F_27 () ;
F_28 ( V_30 , V_6 ) ;
F_23 ( V_6 ) ;
}
static int F_29 ( struct V_1 * V_2 , bool V_67 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_68 * V_69 ;
T_1 V_70 = 0 ;
int V_71 ;
T_1 V_72 = 0 ;
switch ( V_6 -> V_7 . type ) {
case V_25 :
if ( ! F_30 ( V_6 -> V_37 . V_73 . V_74 ) )
return - V_75 ;
break;
case V_26 : {
struct V_5 * V_76 ;
if ( ! V_6 -> V_36 )
return - V_75 ;
F_31 ( & V_6 -> V_37 . V_77 . V_78 , & V_6 -> V_36 -> V_79 ) ;
V_76 = F_32 ( V_6 -> V_36 ,
struct V_5 , V_37 . V_38 ) ;
V_6 -> V_80 =
V_76 -> V_80 ;
V_6 -> V_81 =
V_76 -> V_81 ;
break;
}
case V_24 :
V_6 -> V_36 = & V_6 -> V_37 . V_38 ;
break;
case V_8 :
case V_82 :
case V_23 :
case V_33 :
break;
case V_83 :
case V_84 :
case V_85 :
case V_86 :
F_22 ( 1 ) ;
break;
}
if ( V_30 -> V_87 == 0 ) {
V_71 = F_33 ( V_30 ) ;
if ( V_71 )
goto V_88;
if ( V_30 -> V_89 -> V_90 )
F_34 ( & V_30 -> V_91 ) ;
V_72 = ~ 0 ;
F_35 ( V_30 , true ) ;
F_36 ( V_30 ,
V_92 , 0 ) ;
}
if ( F_37 ( V_2 -> V_34 ) ) {
memcpy ( V_2 -> V_34 ,
V_30 -> V_40 . V_66 -> V_93 ,
V_20 ) ;
memcpy ( V_2 -> V_93 , V_2 -> V_34 , V_20 ) ;
if ( ! F_30 ( V_2 -> V_34 ) ) {
V_71 = - V_94 ;
goto V_95;
}
}
switch ( V_6 -> V_7 . type ) {
case V_26 :
if ( F_26 ( V_6 -> V_36 -> V_96 ) )
F_38 ( V_2 ) ;
else
F_39 ( V_2 ) ;
break;
case V_23 :
if ( V_6 -> V_37 . V_50 & V_97 ) {
V_30 -> V_98 ++ ;
break;
}
if ( V_30 -> V_99 == 0 && V_30 -> V_87 == 0 ) {
V_71 = F_18 ( V_30 ) ;
if ( V_71 )
goto V_95;
}
V_30 -> V_99 ++ ;
if ( V_30 -> V_99 == 1 ) {
V_30 -> V_40 . V_100 . V_46 |= V_101 ;
V_72 |= V_102 ;
}
F_15 ( V_6 , 1 ) ;
F_40 ( V_30 ) ;
F_38 ( V_2 ) ;
break;
default:
if ( V_67 ) {
F_25 ( V_30 ) ;
V_71 = F_21 ( V_30 , V_6 ) ;
if ( V_71 )
goto V_95;
V_71 = F_13 ( V_6 ) ;
if ( V_71 )
goto V_103;
}
if ( V_6 -> V_7 . type == V_24 ) {
V_30 -> V_104 ++ ;
V_30 -> V_105 ++ ;
F_40 ( V_30 ) ;
} else if ( V_6 -> V_7 . type == V_33 ) {
V_30 -> V_105 ++ ;
}
V_70 |= F_41 ( V_6 ) ;
F_42 ( V_6 , V_70 ) ;
if ( V_6 -> V_7 . type == V_82 ||
V_6 -> V_7 . type == V_33 ||
V_6 -> V_7 . type == V_24 )
F_39 ( V_2 ) ;
else
F_38 ( V_2 ) ;
F_43 ( V_6 , true ) ;
}
F_44 ( V_106 , & V_6 -> V_107 ) ;
if ( V_6 -> V_7 . type == V_25 ) {
V_69 = F_45 ( V_6 , V_6 -> V_37 . V_73 . V_74 ,
V_63 ) ;
if ( ! V_69 ) {
V_71 = - V_64 ;
goto V_103;
}
F_46 ( V_69 , V_108 ) ;
F_46 ( V_69 , V_109 ) ;
F_46 ( V_69 , V_110 ) ;
V_71 = F_47 ( V_69 ) ;
if ( V_71 ) {
goto V_103;
}
F_48 ( V_69 ) ;
}
if ( V_6 -> V_46 & V_111 )
F_49 ( & V_30 -> V_112 ) ;
if ( V_6 -> V_46 & V_113 )
F_49 ( & V_30 -> V_114 ) ;
F_50 ( & V_30 -> V_115 ) ;
V_72 |= F_51 ( V_30 ) ;
F_52 ( & V_30 -> V_115 ) ;
if ( V_67 )
V_30 -> V_87 ++ ;
if ( V_72 )
F_53 ( V_30 , V_72 ) ;
F_54 ( V_30 , - 1 ) ;
F_55 ( V_2 ) ;
return 0 ;
V_103:
F_28 ( V_30 , V_6 ) ;
V_95:
if ( ! V_30 -> V_87 )
F_56 ( V_30 ) ;
V_88:
V_6 -> V_36 = NULL ;
if ( V_6 -> V_7 . type == V_26 )
F_57 ( & V_6 -> V_37 . V_77 . V_78 ) ;
F_58 ( V_106 , & V_6 -> V_107 ) ;
return V_71 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_116 ;
if ( ! F_30 ( V_2 -> V_34 ) )
return - V_94 ;
V_116 = F_9 ( V_6 , V_6 -> V_7 . type ) ;
if ( V_116 )
return V_116 ;
return F_29 ( V_2 , true ) ;
}
static void F_60 ( struct V_5 * V_6 ,
bool V_117 )
{
struct V_29 * V_30 = V_6 -> V_30 ;
unsigned long V_46 ;
struct V_118 * V_119 , * V_120 ;
T_1 V_72 = 0 ;
int V_42 ;
enum V_121 V_122 ;
F_58 ( V_106 , & V_6 -> V_107 ) ;
if ( V_30 -> V_123 == V_6 )
F_61 ( V_30 ) ;
F_62 ( V_6 -> V_2 ) ;
F_63 ( V_6 ) ;
F_64 ( V_30 , V_6 ) ;
if ( V_6 -> V_46 & V_111 )
F_65 ( & V_30 -> V_112 ) ;
if ( V_6 -> V_46 & V_113 )
F_65 ( & V_30 -> V_114 ) ;
if ( V_6 -> V_7 . type == V_24 ) {
V_30 -> V_104 -- ;
V_30 -> V_105 -- ;
} else if ( V_6 -> V_7 . type == V_33 ) {
V_30 -> V_105 -- ;
}
F_66 ( V_6 -> V_2 ) ;
F_67 ( & V_30 -> V_124 ) ;
F_68 ( & V_30 -> V_125 , & V_6 -> V_2 -> V_126 ,
V_6 -> V_2 -> V_127 ) ;
F_69 ( & V_30 -> V_124 ) ;
F_70 ( V_6 -> V_2 ) ;
F_40 ( V_30 ) ;
F_71 ( & V_30 -> V_128 ) ;
F_72 ( & V_30 -> V_129 ) ;
if ( V_6 -> V_7 . type == V_24 ) {
struct V_5 * V_77 , * V_130 ;
struct V_131 * V_132 =
F_26 ( V_6 -> V_37 . V_38 . V_96 ) ;
struct V_118 * V_133 =
F_26 ( V_6 -> V_37 . V_38 . V_134 ) ;
F_42 ( V_6 ,
V_135 ) ;
F_73 ( V_6 -> V_37 . V_38 . V_96 , NULL ) ;
F_73 ( V_6 -> V_37 . V_38 . V_134 , NULL ) ;
F_74 () ;
F_23 ( V_132 ) ;
F_75 ( V_133 ) ;
F_76 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_77 ( V_77 -> V_2 ) ;
F_22 ( ! F_78 ( & V_6 -> V_37 . V_38 . V_79 ) ) ;
V_30 -> V_136 -= F_79 ( & V_6 -> V_37 . V_38 . V_137 ) ;
F_80 ( & V_6 -> V_37 . V_38 . V_137 ) ;
} else if ( V_6 -> V_7 . type == V_82 ) {
F_81 ( V_6 ) ;
}
if ( V_117 )
V_30 -> V_87 -- ;
switch ( V_6 -> V_7 . type ) {
case V_26 :
F_57 ( & V_6 -> V_37 . V_77 . V_78 ) ;
break;
case V_23 :
if ( V_6 -> V_37 . V_50 & V_97 ) {
V_30 -> V_98 -- ;
break;
}
V_30 -> V_99 -- ;
if ( V_30 -> V_99 == 0 ) {
V_30 -> V_40 . V_100 . V_46 &= ~ V_101 ;
V_72 |= V_102 ;
F_25 ( V_30 ) ;
}
F_15 ( V_6 , - 1 ) ;
F_40 ( V_30 ) ;
break;
default:
F_50 ( & V_30 -> V_115 ) ;
if ( V_30 -> V_138 == V_6 -> V_2 &&
V_30 -> V_139 ) {
F_82 ( V_30 ) ;
F_83 ( & V_30 -> V_40 , & V_30 -> V_140 ) ;
}
F_52 ( & V_30 -> V_115 ) ;
F_84 ( & V_30 -> V_141 ) ;
F_84 ( & V_30 -> V_140 ) ;
F_84 ( & V_6 -> V_142 ) ;
F_74 () ;
F_80 ( & V_6 -> V_143 ) ;
if ( V_6 -> V_7 . type == V_8 )
F_42 ( V_6 ,
V_135 ) ;
F_85 ( V_6 ) ;
if ( V_117 )
F_28 ( V_30 , V_6 ) ;
}
V_6 -> V_36 = NULL ;
F_50 ( & V_30 -> V_115 ) ;
V_72 |= F_51 ( V_30 ) ;
F_52 ( & V_30 -> V_115 ) ;
F_54 ( V_30 , - 1 ) ;
if ( V_30 -> V_87 == 0 ) {
if ( V_30 -> V_89 -> V_90 )
F_86 ( & V_30 -> V_91 ) ;
F_87 ( V_30 ) ;
F_88 ( V_30 ) ;
V_72 = 0 ;
}
V_122 = V_30 -> V_144 ;
F_89 ( V_30 , NULL , V_145 ) ;
if ( V_72 || ( V_122 != V_30 -> V_144 ) )
F_53 ( V_30 , V_72 ) ;
F_90 ( & V_30 -> V_146 , V_46 ) ;
for ( V_42 = 0 ; V_42 < V_147 ; V_42 ++ ) {
F_91 (&local->pending[i], skb, tmp) {
struct V_148 * V_149 = F_92 ( V_119 ) ;
if ( V_149 -> V_56 . V_7 == & V_6 -> V_7 ) {
F_93 ( V_119 , & V_30 -> V_150 [ V_42 ] ) ;
F_94 ( V_119 ) ;
}
}
}
F_95 ( & V_30 -> V_146 , V_46 ) ;
if ( V_30 -> V_99 == V_30 -> V_87 && V_30 -> V_99 > 0 )
F_18 ( V_30 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_60 ( V_6 , true ) ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
int V_151 , V_152 , V_153 , V_154 ;
V_151 = ! ! ( V_2 -> V_46 & V_155 ) ;
V_152 = ! ! ( V_2 -> V_46 & V_156 ) ;
V_153 = ! ! ( V_6 -> V_46 & V_111 ) ;
V_154 = ! ! ( V_6 -> V_46 & V_113 ) ;
if ( V_151 != V_153 ) {
if ( V_2 -> V_46 & V_155 )
F_49 ( & V_30 -> V_112 ) ;
else
F_65 ( & V_30 -> V_112 ) ;
V_6 -> V_46 ^= V_111 ;
}
if ( V_152 != V_154 ) {
if ( V_2 -> V_46 & V_156 )
F_49 ( & V_30 -> V_114 ) ;
else
F_65 ( & V_30 -> V_114 ) ;
V_6 -> V_46 ^= V_113 ;
}
F_67 ( & V_30 -> V_124 ) ;
F_98 ( & V_30 -> V_125 , & V_2 -> V_126 , V_2 -> V_127 ) ;
F_69 ( & V_30 -> V_124 ) ;
F_83 ( & V_30 -> V_40 , & V_30 -> V_157 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
int V_158 ;
int V_42 ;
F_85 ( V_6 ) ;
F_100 ( V_6 ) ;
for ( V_42 = 0 ; V_42 < V_159 ; V_42 ++ )
F_101 ( & V_6 -> V_160 [ V_42 ] . V_161 ) ;
V_6 -> V_162 = 0 ;
if ( F_102 ( & V_6 -> V_7 ) )
F_103 ( V_6 ) ;
V_158 = F_64 ( V_30 , V_6 ) ;
F_22 ( V_158 ) ;
}
static T_4 F_104 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
return F_105 ( F_2 ( V_2 ) , V_119 ) ;
}
static T_4 F_106 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_163 * V_164 ;
struct V_165 * V_166 = ( void * ) V_119 -> V_167 ;
if ( V_30 -> V_40 . V_41 < V_43 )
return 0 ;
if ( V_119 -> V_168 < 4 ||
V_119 -> V_168 < F_107 ( V_166 -> V_169 ) + 2 )
return 0 ;
V_164 = ( void * ) ( ( V_170 * ) V_119 -> V_167 + F_107 ( V_166 -> V_169 ) ) ;
return F_108 ( V_30 , V_119 , V_164 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_110 ( V_2 ) ;
V_2 -> V_171 &= ~ V_172 ;
V_2 -> V_173 = & V_174 ;
V_2 -> V_175 = V_176 ;
}
static void F_111 ( struct V_177 * V_142 )
{
struct V_5 * V_6 =
F_32 ( V_142 , struct V_5 , V_142 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
struct V_118 * V_119 ;
struct V_68 * V_69 ;
struct V_178 * V_179 ;
if ( ! F_6 ( V_6 ) )
return;
if ( V_30 -> V_180 )
return;
if ( F_112 ( V_30 -> V_181 ,
L_3 ) )
return;
while ( ( V_119 = F_113 ( & V_6 -> V_143 ) ) ) {
struct V_182 * V_183 = ( void * ) V_119 -> V_167 ;
if ( V_119 -> V_184 == V_185 ) {
V_179 = ( void * ) & V_119 -> V_186 ;
F_114 ( & V_6 -> V_7 , V_179 -> V_187 ,
V_179 -> V_188 ) ;
} else if ( V_119 -> V_184 == V_189 ) {
V_179 = ( void * ) & V_119 -> V_186 ;
F_115 ( & V_6 -> V_7 , V_179 -> V_187 ,
V_179 -> V_188 ) ;
} else if ( F_116 ( V_183 -> V_190 ) &&
V_183 -> V_37 . V_191 . V_192 == V_193 ) {
int V_168 = V_119 -> V_168 ;
F_50 ( & V_30 -> V_194 ) ;
V_69 = F_117 ( V_6 , V_183 -> V_16 ) ;
if ( V_69 ) {
switch ( V_183 -> V_37 . V_191 . V_37 . V_195 . V_196 ) {
case V_197 :
F_118 (
V_30 , V_69 , V_183 , V_168 ) ;
break;
case V_198 :
F_119 ( V_30 , V_69 ,
V_183 , V_168 ) ;
break;
case V_199 :
F_120 ( V_6 , V_69 ,
V_183 , V_168 ) ;
break;
default:
F_22 ( 1 ) ;
break;
}
}
F_52 ( & V_30 -> V_194 ) ;
} else if ( F_121 ( V_183 -> V_190 ) ) {
struct V_163 * V_164 = ( void * ) V_183 ;
F_22 ( V_164 -> V_190 &
F_122 ( V_200 ) ) ;
F_22 ( ! ( V_164 -> V_201 &
F_122 ( V_202 ) ) ) ;
F_50 ( & V_30 -> V_194 ) ;
V_69 = F_117 ( V_6 , V_183 -> V_16 ) ;
if ( V_69 ) {
T_4 V_188 = * F_123 ( V_164 ) &
V_203 ;
F_124 (
V_69 , V_188 , V_204 ,
V_205 ,
true ) ;
}
F_52 ( & V_30 -> V_194 ) ;
} else switch ( V_6 -> V_7 . type ) {
case V_82 :
F_125 ( V_6 , V_119 ) ;
break;
case V_33 :
F_126 ( V_6 , V_119 ) ;
break;
case V_8 :
if ( ! F_102 ( & V_6 -> V_7 ) )
break;
F_127 ( V_6 , V_119 ) ;
break;
default:
F_112 ( 1 , L_4 ) ;
break;
}
F_75 ( V_119 ) ;
}
switch ( V_6 -> V_7 . type ) {
case V_82 :
F_128 ( V_6 ) ;
break;
case V_33 :
F_129 ( V_6 ) ;
break;
case V_8 :
if ( ! F_102 ( & V_6 -> V_7 ) )
break;
F_130 ( V_6 ) ;
break;
default:
break;
}
}
static void F_131 ( struct V_5 * V_6 ,
enum V_27 type )
{
memset ( & V_6 -> V_37 , 0 , sizeof( V_6 -> V_37 ) ) ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_206 = false ;
V_6 -> V_2 -> V_173 = & V_174 ;
V_6 -> V_207 . V_28 = type ;
V_6 -> V_80 = F_132 ( V_208 ) ;
V_6 -> V_81 = false ;
V_6 -> V_209 = 0 ;
V_6 -> V_2 -> type = V_210 ;
F_133 ( & V_6 -> V_143 ) ;
F_134 ( & V_6 -> V_142 , F_111 ) ;
switch ( type ) {
case V_86 :
type = V_24 ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_206 = true ;
case V_24 :
F_133 ( & V_6 -> V_37 . V_38 . V_137 ) ;
F_135 ( & V_6 -> V_37 . V_38 . V_79 ) ;
break;
case V_85 :
type = V_82 ;
V_6 -> V_7 . type = type ;
V_6 -> V_7 . V_206 = true ;
case V_82 :
F_136 ( V_6 ) ;
break;
case V_33 :
F_137 ( V_6 ) ;
break;
case V_8 :
if ( F_102 ( & V_6 -> V_7 ) )
F_138 ( V_6 ) ;
break;
case V_23 :
V_6 -> V_2 -> type = V_211 ;
V_6 -> V_2 -> V_173 = & V_212 ;
V_6 -> V_37 . V_50 = V_213 |
V_214 ;
break;
case V_25 :
case V_26 :
break;
case V_83 :
case V_84 :
F_139 () ;
break;
}
F_140 ( V_6 ) ;
}
static void F_141 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_7 . type ) {
case V_8 :
F_142 ( V_6 ) ;
break;
default:
break;
}
}
static int F_143 ( struct V_5 * V_6 ,
enum V_27 type )
{
struct V_29 * V_30 = V_6 -> V_30 ;
int V_17 , V_116 ;
enum V_27 V_215 = type ;
bool V_206 = false ;
F_10 () ;
if ( ! V_30 -> V_89 -> V_216 )
return - V_18 ;
switch ( V_6 -> V_7 . type ) {
case V_24 :
case V_82 :
case V_33 :
break;
default:
return - V_18 ;
}
switch ( type ) {
case V_24 :
case V_82 :
case V_33 :
break;
case V_85 :
V_206 = true ;
V_215 = V_82 ;
break;
case V_86 :
V_206 = true ;
V_215 = V_24 ;
break;
default:
return - V_18 ;
}
V_17 = F_9 ( V_6 , V_215 ) ;
if ( V_17 )
return V_17 ;
F_60 ( V_6 , false ) ;
F_99 ( V_6 -> V_2 ) ;
V_17 = F_144 ( V_30 , V_6 , V_215 , V_206 ) ;
if ( V_17 )
type = V_6 -> V_7 . type ;
F_13 ( V_6 ) ;
F_131 ( V_6 , type ) ;
V_116 = F_29 ( V_6 -> V_2 , false ) ;
F_112 ( V_116 , L_5 , V_116 ) ;
return V_17 ;
}
int F_145 ( struct V_5 * V_6 ,
enum V_27 type )
{
int V_17 ;
F_10 () ;
if ( type == F_146 ( & V_6 -> V_7 ) )
return 0 ;
if ( V_6 -> V_30 -> V_217 -> V_46 & V_218 &&
type == V_33 )
return - V_219 ;
if ( F_6 ( V_6 ) ) {
V_17 = F_143 ( V_6 , type ) ;
if ( V_17 )
return V_17 ;
} else {
F_99 ( V_6 -> V_2 ) ;
F_131 ( V_6 , type ) ;
}
V_6 -> V_7 . V_220 . V_221 =
F_147 ( V_6 -> V_30 ,
V_6 -> V_30 -> V_40 . V_100 . V_222 -> V_223 ) ;
V_6 -> V_224 = 0 ;
if ( type == V_82 )
V_6 -> V_37 . V_225 . V_226 = false ;
return 0 ;
}
static void F_148 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_27 type )
{
struct V_5 * V_6 ;
T_5 V_227 , V_228 , V_14 , V_229 , V_230 ;
V_170 * V_231 ;
V_170 V_232 [ V_20 ] ;
int V_42 ;
memcpy ( V_2 -> V_93 , V_30 -> V_40 . V_66 -> V_93 , V_20 ) ;
if ( F_37 ( V_30 -> V_40 . V_66 -> V_233 ) &&
V_30 -> V_40 . V_66 -> V_234 <= 1 )
return;
F_50 ( & V_30 -> V_235 ) ;
switch ( type ) {
case V_23 :
break;
case V_25 :
case V_26 :
F_11 (sdata, &local->interfaces, list) {
if ( V_6 -> V_7 . type != V_24 )
continue;
memcpy ( V_2 -> V_93 , V_6 -> V_7 . V_14 , V_20 ) ;
break;
}
break;
default:
for ( V_42 = 0 ; V_42 < V_30 -> V_40 . V_66 -> V_234 ; V_42 ++ ) {
bool V_236 = false ;
F_11 (sdata, &local->interfaces, list) {
if ( memcmp ( V_30 -> V_40 . V_66 -> V_237 [ V_42 ] . V_14 ,
V_6 -> V_7 . V_14 , V_20 ) == 0 ) {
V_236 = true ;
break;
}
}
if ( ! V_236 ) {
memcpy ( V_2 -> V_93 ,
V_30 -> V_40 . V_66 -> V_237 [ V_42 ] . V_14 ,
V_20 ) ;
break;
}
}
if ( F_37 ( V_30 -> V_40 . V_66 -> V_233 ) )
break;
V_231 = V_30 -> V_40 . V_66 -> V_233 ;
V_227 = ( ( T_5 ) V_231 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_231 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_231 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_231 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_231 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_231 [ 5 ] << 0 * 8 ) ;
if ( F_149 ( V_227 ) + F_150 ( V_227 ) != F_151 ( V_227 ) ) {
F_4 ( V_11 L_6 ) ;
break;
}
V_231 = V_30 -> V_40 . V_66 -> V_93 ;
V_228 = ( ( T_5 ) V_231 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_231 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_231 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_231 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_231 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_231 [ 5 ] << 0 * 8 ) ;
V_230 = 1ULL << F_149 ( V_227 ) ;
V_229 = ( V_228 & V_227 ) ;
V_14 = ( V_228 & ~ V_227 ) | ( V_229 & V_227 ) ;
do {
bool V_236 = false ;
V_232 [ 5 ] = V_14 >> 0 * 8 ;
V_232 [ 4 ] = V_14 >> 1 * 8 ;
V_232 [ 3 ] = V_14 >> 2 * 8 ;
V_232 [ 2 ] = V_14 >> 3 * 8 ;
V_232 [ 1 ] = V_14 >> 4 * 8 ;
V_232 [ 0 ] = V_14 >> 5 * 8 ;
V_229 += V_230 ;
F_11 (sdata, &local->interfaces, list) {
if ( memcmp ( V_232 , V_6 -> V_7 . V_14 ,
V_20 ) == 0 ) {
V_236 = true ;
break;
}
}
if ( ! V_236 ) {
memcpy ( V_2 -> V_93 , V_232 , V_20 ) ;
break;
}
V_14 = ( V_228 & ~ V_227 ) | ( V_229 & V_227 ) ;
} while ( V_14 != V_228 );
break;
}
F_52 ( & V_30 -> V_235 ) ;
}
int F_152 ( struct V_29 * V_30 , const char * V_12 ,
struct V_1 * * V_238 , enum V_27 type ,
struct V_239 * V_240 )
{
struct V_1 * V_32 ;
struct V_5 * V_6 = NULL ;
int V_17 , V_42 ;
int V_241 = 1 ;
F_10 () ;
if ( V_30 -> V_40 . V_41 >= V_43 )
V_241 = V_43 ;
V_32 = F_153 ( sizeof( * V_6 ) + V_30 -> V_40 . V_62 ,
V_12 , F_109 , V_241 , 1 ) ;
if ( ! V_32 )
return - V_64 ;
F_154 ( V_32 , F_155 ( V_30 -> V_40 . V_66 ) ) ;
V_32 -> V_242 = V_30 -> V_243 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_244
+ V_245 ;
V_32 -> V_246 = V_247 ;
V_17 = F_156 ( V_32 , V_32 -> V_12 ) ;
if ( V_17 < 0 )
goto V_248;
F_148 ( V_30 , V_32 , type ) ;
memcpy ( V_32 -> V_34 , V_32 -> V_93 , V_20 ) ;
F_157 ( V_32 , F_158 ( V_30 -> V_40 . V_66 ) ) ;
V_6 = F_159 ( V_32 ) ;
V_32 -> V_249 = & V_6 -> V_207 ;
memcpy ( V_6 -> V_7 . V_14 , V_32 -> V_34 , V_20 ) ;
memcpy ( V_6 -> V_12 , V_32 -> V_12 , V_65 ) ;
V_6 -> V_207 . V_66 = V_30 -> V_40 . V_66 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_2 = V_32 ;
#ifdef F_160
V_6 -> V_250 = true ;
#endif
for ( V_42 = 0 ; V_42 < V_159 ; V_42 ++ )
F_133 ( & V_6 -> V_160 [ V_42 ] . V_161 ) ;
F_135 ( & V_6 -> V_251 ) ;
for ( V_42 = 0 ; V_42 < V_252 ; V_42 ++ ) {
struct V_253 * V_254 ;
V_254 = V_30 -> V_40 . V_66 -> V_255 [ V_42 ] ;
V_6 -> V_256 [ V_42 ] =
V_254 ? ( 1 << V_254 -> V_257 ) - 1 : 0 ;
if ( V_254 )
memcpy ( V_6 -> V_258 [ V_42 ] ,
V_254 -> V_259 . V_260 . V_261 ,
sizeof( V_6 -> V_258 [ V_42 ] ) ) ;
else
memset ( V_6 -> V_258 [ V_42 ] , 0 ,
sizeof( V_6 -> V_258 [ V_42 ] ) ) ;
}
F_17 ( V_6 ) ;
F_131 ( V_6 , type ) ;
if ( V_240 ) {
V_32 -> V_249 -> V_226 = V_240 -> V_226 ;
if ( type == V_82 )
V_6 -> V_37 . V_225 . V_226 = V_240 -> V_226 ;
}
V_17 = F_161 ( V_32 ) ;
if ( V_17 )
goto V_248;
F_50 ( & V_30 -> V_235 ) ;
F_162 ( & V_6 -> V_78 , & V_30 -> V_262 ) ;
F_52 ( & V_30 -> V_235 ) ;
if ( V_238 )
* V_238 = V_32 ;
return 0 ;
V_248:
V_176 ( V_32 ) ;
return V_17 ;
}
void F_163 ( struct V_5 * V_6 )
{
F_10 () ;
F_50 ( & V_6 -> V_30 -> V_235 ) ;
F_164 ( & V_6 -> V_78 ) ;
F_52 ( & V_6 -> V_30 -> V_235 ) ;
F_141 ( V_6 ) ;
F_74 () ;
F_165 ( V_6 -> V_2 ) ;
}
void F_166 ( struct V_29 * V_30 )
{
struct V_5 * V_6 , * V_120 ;
F_167 ( V_263 ) ;
F_10 () ;
F_50 ( & V_30 -> V_235 ) ;
F_76 (sdata, tmp, &local->interfaces, list) {
F_57 ( & V_6 -> V_78 ) ;
F_141 ( V_6 ) ;
F_168 ( V_6 -> V_2 , & V_263 ) ;
}
F_52 ( & V_30 -> V_235 ) ;
F_169 ( & V_263 ) ;
F_57 ( & V_263 ) ;
}
static T_1 F_170 ( struct V_29 * V_30 ,
const char * V_264 )
{
if ( ! ( V_30 -> V_40 . V_100 . V_46 & V_265 ) )
return 0 ;
#ifdef F_3
F_171 ( V_30 -> V_40 . V_66 , L_7 , V_264 ) ;
#endif
V_30 -> V_40 . V_100 . V_46 &= ~ V_265 ;
return V_266 ;
}
static T_1 F_172 ( struct V_29 * V_30 )
{
if ( V_30 -> V_40 . V_100 . V_46 & V_265 )
return 0 ;
#ifdef F_3
F_171 ( V_30 -> V_40 . V_66 , L_8 ) ;
#endif
F_173 ( V_30 , false ) ;
V_30 -> V_40 . V_100 . V_46 |= V_265 ;
return V_266 ;
}
T_1 F_51 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
int V_267 = 0 ;
bool V_268 = false , V_180 = false , V_269 = false ;
struct V_270 * V_271 ;
unsigned int V_272 = 0 , V_273 = 0 ;
#ifdef F_174
F_22 ( V_274 && ! F_175 () &&
! F_176 ( & V_30 -> V_235 ) ) ;
#endif
F_177 ( & V_30 -> V_115 ) ;
F_11 (sdata, &local->interfaces, list) {
if ( ! F_6 ( V_6 ) ) {
V_6 -> V_7 . V_220 . V_275 = true ;
continue;
}
V_6 -> V_276 = V_6 -> V_7 . V_220 . V_275 ;
if ( V_6 -> V_7 . type == V_82 &&
! V_6 -> V_37 . V_225 . V_277 &&
! V_6 -> V_37 . V_225 . V_278 &&
! V_6 -> V_37 . V_225 . V_279 ) {
V_6 -> V_7 . V_220 . V_275 = true ;
continue;
}
if ( V_6 -> V_7 . type == V_33 &&
! V_6 -> V_37 . V_280 . V_281 ) {
V_6 -> V_7 . V_220 . V_275 = true ;
continue;
}
V_6 -> V_7 . V_220 . V_275 = false ;
V_267 ++ ;
}
F_11 (wk, &local->work_list, list) {
V_268 = true ;
V_271 -> V_6 -> V_7 . V_220 . V_275 = false ;
}
if ( V_30 -> V_123 &&
! ( V_30 -> V_40 . V_46 & V_282 ) ) {
V_180 = true ;
V_30 -> V_123 -> V_7 . V_220 . V_275 = false ;
}
if ( V_30 -> V_139 )
V_269 = true ;
F_11 (sdata, &local->interfaces, list) {
if ( V_6 -> V_7 . type == V_23 ||
V_6 -> V_7 . type == V_26 )
continue;
if ( V_6 -> V_276 == V_6 -> V_7 . V_220 . V_275 )
continue;
if ( ! F_6 ( V_6 ) )
continue;
F_42 ( V_6 , V_283 ) ;
}
if ( V_268 || V_180 || V_269 )
V_272 |= V_284 ;
else
V_273 |= V_284 ;
if ( V_267 )
V_272 |= V_285 ;
else
V_273 |= V_285 ;
F_36 ( V_30 , V_272 , V_273 ) ;
if ( V_269 )
return F_170 ( V_30 , L_9 ) ;
if ( V_268 )
return F_170 ( V_30 , L_10 ) ;
if ( V_180 )
return F_170 ( V_30 , L_11 ) ;
if ( ! V_267 )
return F_172 ( V_30 ) ;
else
return F_170 ( V_30 , L_12 ) ;
return 0 ;
}
void F_178 ( struct V_29 * V_30 )
{
T_1 V_286 ;
F_50 ( & V_30 -> V_235 ) ;
V_286 = F_51 ( V_30 ) ;
F_52 ( & V_30 -> V_235 ) ;
if ( V_286 )
F_53 ( V_30 , V_286 ) ;
}
static int F_179 ( struct V_287 * V_288 ,
unsigned long V_107 ,
void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_5 * V_6 ;
if ( V_107 != V_289 )
return 0 ;
if ( ! V_2 -> V_249 || ! V_2 -> V_249 -> V_66 )
return 0 ;
if ( V_2 -> V_249 -> V_66 -> V_290 != V_291 )
return 0 ;
V_6 = F_2 ( V_2 ) ;
memcpy ( V_6 -> V_12 , V_2 -> V_12 , V_65 ) ;
F_180 ( V_6 ) ;
return 0 ;
}
int F_181 ( void )
{
return F_182 ( & V_292 ) ;
}
void F_183 ( void )
{
F_184 ( & V_292 ) ;
}
