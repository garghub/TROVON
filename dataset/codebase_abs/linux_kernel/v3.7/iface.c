static T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
if ( ! ( V_2 -> V_4 . V_5 . V_6 & V_7 ) )
return 0 ;
V_2 -> V_4 . V_5 . V_6 &= ~ V_7 ;
return V_8 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_5 . V_6 & V_7 )
return 0 ;
F_3 ( V_2 , false ) ;
V_2 -> V_4 . V_5 . V_6 |= V_7 ;
return V_8 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_11 = 0 ;
bool V_12 = false , V_13 = false ;
unsigned int V_14 = 0 , V_15 = 0 ;
struct V_16 * V_17 ;
#ifdef F_5
F_6 ( V_18 && ! F_7 () &&
! F_8 ( & V_2 -> V_19 ) ) ;
#endif
F_9 ( & V_2 -> V_20 ) ;
F_10 (sdata, &local->interfaces, list) {
if ( ! F_11 ( V_10 ) ) {
V_10 -> V_21 . V_22 . V_23 = true ;
continue;
}
V_10 -> V_24 = V_10 -> V_21 . V_22 . V_23 ;
if ( V_10 -> V_21 . type == V_25 &&
! V_10 -> V_26 . V_27 . V_28 &&
! V_10 -> V_26 . V_27 . V_29 &&
! V_10 -> V_26 . V_27 . V_30 ) {
V_10 -> V_21 . V_22 . V_23 = true ;
continue;
}
if ( V_10 -> V_21 . type == V_31 &&
! V_10 -> V_26 . V_32 . V_33 ) {
V_10 -> V_21 . V_22 . V_23 = true ;
continue;
}
if ( V_10 -> V_21 . type == V_34 )
continue;
V_10 -> V_21 . V_22 . V_23 = false ;
V_11 ++ ;
}
if ( ! V_2 -> V_35 -> V_36 ) {
F_10 (roc, &local->roc_list, list) {
V_12 = true ;
V_17 -> V_10 -> V_21 . V_22 . V_23 = false ;
}
}
V_10 = F_12 ( V_2 -> V_37 ,
F_8 ( & V_2 -> V_20 ) ) ;
if ( V_10 && ! ( V_2 -> V_4 . V_6 & V_38 ) ) {
V_13 = true ;
V_10 -> V_21 . V_22 . V_23 = false ;
}
F_10 (sdata, &local->interfaces, list) {
if ( V_10 -> V_21 . type == V_39 ||
V_10 -> V_21 . type == V_40 ||
V_10 -> V_21 . type == V_34 )
continue;
if ( V_10 -> V_24 == V_10 -> V_21 . V_22 . V_23 )
continue;
if ( ! F_11 ( V_10 ) )
continue;
F_13 ( V_10 , V_41 ) ;
}
if ( V_12 || V_13 )
V_14 |= V_42 ;
else
V_15 |= V_42 ;
if ( V_11 )
V_14 |= V_43 ;
else
V_15 |= V_43 ;
F_14 ( V_2 , V_14 , V_15 ) ;
if ( V_12 )
return F_1 ( V_2 , L_1 ) ;
if ( V_13 )
return F_1 ( V_2 , L_2 ) ;
if ( ! V_11 )
return F_2 ( V_2 ) ;
else
return F_1 ( V_2 , L_3 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_44 ;
F_16 ( & V_2 -> V_19 ) ;
V_44 = F_4 ( V_2 ) ;
F_17 ( & V_2 -> V_19 ) ;
if ( V_44 )
F_18 ( V_2 , V_44 ) ;
}
static int F_19 ( struct V_45 * V_46 , int V_47 )
{
int V_48 ;
struct V_9 * V_10 = F_20 ( V_46 ) ;
V_48 = ( V_10 -> V_21 . type == V_49 ) ? 5 : 0 ;
if ( V_47 < 256 ||
V_47 > V_50 - 24 - 6 - V_48 ) {
return - V_51 ;
}
V_46 -> V_52 = V_47 ;
return 0 ;
}
static int F_21 ( struct V_45 * V_46 , void * V_53 )
{
struct V_9 * V_10 = F_20 ( V_46 ) ;
struct V_54 * V_55 = V_53 ;
int V_56 ;
if ( F_11 ( V_10 ) )
return - V_57 ;
V_56 = F_22 ( V_46 , V_55 ) ;
if ( V_56 == 0 )
memcpy ( V_10 -> V_21 . V_53 , V_55 -> V_58 , V_59 ) ;
return V_56 ;
}
static inline int F_23 ( int V_60 , int V_61 )
{
return V_60 == V_39 ||
V_61 == V_39 ||
V_60 == V_34 ||
V_61 == V_34 ||
( V_60 == V_62 && V_61 == V_63 ) ||
( V_60 == V_63 &&
( V_61 == V_63 ||
V_61 == V_62 ) ) ||
( V_60 == V_62 && V_61 == V_40 ) ||
( V_60 == V_40 &&
( V_61 == V_62 ||
V_61 == V_40 ) ) ;
}
static int F_24 ( struct V_9 * V_10 ,
enum V_64 V_65 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_9 * V_66 ;
F_25 () ;
F_10 (nsdata, &local->interfaces, list) {
if ( V_66 != V_10 && F_11 ( V_66 ) ) {
if ( V_65 == V_31 &&
V_66 -> V_21 . type == V_31 )
return - V_57 ;
if ( ! F_26 ( V_10 -> V_21 . V_53 ,
V_66 -> V_21 . V_53 ) )
continue;
if ( ! F_23 ( V_65 ,
V_66 -> V_21 . type ) )
return - V_67 ;
if ( V_65 == V_40 &&
V_66 -> V_21 . type == V_62 )
V_10 -> V_68 = & V_66 -> V_26 . V_69 ;
}
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
int V_70 = V_10 -> V_2 -> V_4 . V_71 ;
int V_72 ;
if ( V_10 -> V_21 . type != V_34 ) {
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
if ( F_28 ( V_10 -> V_21 . V_74 [ V_72 ] ==
V_75 ) )
return - V_51 ;
if ( F_28 ( V_10 -> V_21 . V_74 [ V_72 ] >=
V_70 ) )
return - V_51 ;
}
}
if ( ( V_10 -> V_21 . type != V_62 ) ||
! ( V_10 -> V_2 -> V_4 . V_6 & V_76 ) ) {
V_10 -> V_21 . V_77 = V_75 ;
return 0 ;
}
if ( F_28 ( V_10 -> V_21 . V_77 == V_75 ) )
return - V_51 ;
if ( F_28 ( V_10 -> V_21 . V_77 >= V_70 ) )
return - V_51 ;
return 0 ;
}
void F_29 ( struct V_9 * V_10 ,
const int V_78 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_6 = V_10 -> V_26 . V_79 ;
#define F_30 ( T_2 , T_3 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_30 ( V_80 , V_81 ) ;
F_30 ( V_82 , V_83 ) ;
F_30 ( V_84 , V_85 ) ;
F_30 ( V_84 , V_86 ) ;
F_30 ( V_87 , V_88 ) ;
#undef F_30
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
if ( V_2 -> V_4 . V_6 & V_76 )
V_10 -> V_21 . V_74 [ V_72 ] = V_75 ;
else if ( V_2 -> V_4 . V_71 >= V_73 )
V_10 -> V_21 . V_74 [ V_72 ] = V_72 ;
else
V_10 -> V_21 . V_74 [ V_72 ] = 0 ;
}
V_10 -> V_21 . V_77 = V_75 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_56 = 0 ;
if ( ! ( V_2 -> V_4 . V_6 & V_89 ) )
return 0 ;
F_16 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_90 )
goto V_91;
V_10 = F_33 ( sizeof( * V_10 ) + V_2 -> V_4 . V_92 , V_93 ) ;
if ( ! V_10 ) {
V_56 = - V_94 ;
goto V_91;
}
V_10 -> V_2 = V_2 ;
V_10 -> V_21 . type = V_39 ;
snprintf ( V_10 -> V_95 , V_96 , L_4 ,
F_34 ( V_2 -> V_4 . V_97 ) ) ;
F_31 ( V_10 ) ;
V_56 = F_35 ( V_2 , V_10 ) ;
if ( F_6 ( V_56 ) ) {
F_36 ( V_10 ) ;
goto V_91;
}
V_56 = F_27 ( V_10 ) ;
if ( V_56 ) {
F_36 ( V_10 ) ;
goto V_91;
}
F_37 ( V_2 -> V_90 , V_10 ) ;
V_91:
F_17 ( & V_2 -> V_19 ) ;
return V_56 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! ( V_2 -> V_4 . V_6 & V_89 ) )
return;
F_16 ( & V_2 -> V_19 ) ;
V_10 = F_12 ( V_2 -> V_90 ,
F_8 ( & V_2 -> V_19 ) ) ;
if ( ! V_10 )
goto V_91;
F_37 ( V_2 -> V_90 , NULL ) ;
F_39 () ;
F_40 ( V_2 , V_10 ) ;
F_36 ( V_10 ) ;
V_91:
F_17 ( & V_2 -> V_19 ) ;
}
int F_41 ( struct V_98 * V_99 , bool V_100 )
{
struct V_9 * V_10 = F_42 ( V_99 ) ;
struct V_45 * V_46 = V_99 -> V_101 ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_102 * V_103 ;
T_1 V_104 = 0 ;
int V_105 ;
T_1 V_106 = 0 ;
switch ( V_10 -> V_21 . type ) {
case V_63 :
if ( ! F_43 ( V_10 -> V_26 . V_107 . V_108 ) )
return - V_109 ;
break;
case V_40 : {
struct V_9 * V_110 ;
if ( ! V_10 -> V_68 )
return - V_109 ;
F_44 ( & V_10 -> V_26 . V_111 . V_112 , & V_10 -> V_68 -> V_113 ) ;
V_110 = F_45 ( V_10 -> V_68 ,
struct V_9 , V_26 . V_69 ) ;
V_10 -> V_114 =
V_110 -> V_114 ;
V_10 -> V_115 =
V_110 -> V_115 ;
break;
}
case V_62 :
V_10 -> V_68 = & V_10 -> V_26 . V_69 ;
break;
case V_49 :
case V_25 :
case V_39 :
case V_31 :
case V_34 :
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
F_6 ( 1 ) ;
break;
}
if ( V_2 -> V_120 == 0 ) {
V_105 = F_46 ( V_2 ) ;
if ( V_105 )
goto V_121;
if ( V_2 -> V_35 -> V_122 )
F_47 ( & V_2 -> V_123 ) ;
V_106 = ~ 0 ;
F_48 ( V_2 , true ) ;
F_14 ( V_2 ,
V_124 , 0 ) ;
}
if ( V_46 && F_49 ( V_46 -> V_125 ) ) {
memcpy ( V_46 -> V_125 ,
V_2 -> V_4 . V_97 -> V_126 ,
V_59 ) ;
memcpy ( V_46 -> V_126 , V_46 -> V_125 , V_59 ) ;
if ( ! F_43 ( V_46 -> V_125 ) ) {
V_105 = - V_127 ;
goto V_128;
}
}
switch ( V_10 -> V_21 . type ) {
case V_40 :
if ( F_50 ( V_10 -> V_68 -> V_129 ) )
F_51 ( V_46 ) ;
else
F_52 ( V_46 ) ;
break;
case V_39 :
if ( V_10 -> V_26 . V_79 & V_130 ) {
V_2 -> V_131 ++ ;
break;
}
if ( V_2 -> V_132 == 0 && V_2 -> V_120 == 0 ) {
V_105 = F_32 ( V_2 ) ;
if ( V_105 )
goto V_128;
}
V_2 -> V_132 ++ ;
if ( V_2 -> V_132 == 1 ) {
V_2 -> V_4 . V_5 . V_6 |= V_133 ;
V_106 |= V_134 ;
}
F_29 ( V_10 , 1 ) ;
F_53 ( V_2 ) ;
F_51 ( V_46 ) ;
break;
default:
if ( V_100 ) {
F_38 ( V_2 ) ;
V_105 = F_35 ( V_2 , V_10 ) ;
if ( V_105 )
goto V_128;
V_105 = F_27 ( V_10 ) ;
if ( V_105 )
goto V_135;
}
if ( V_10 -> V_21 . type == V_62 ) {
V_2 -> V_136 ++ ;
V_2 -> V_137 ++ ;
F_53 ( V_2 ) ;
} else if ( V_10 -> V_21 . type == V_31 ) {
V_2 -> V_137 ++ ;
}
if ( V_10 -> V_21 . type != V_34 )
V_104 |= F_54 ( V_10 ) ;
F_13 ( V_10 , V_104 ) ;
switch ( V_10 -> V_21 . type ) {
case V_25 :
case V_31 :
case V_62 :
case V_49 :
F_52 ( V_46 ) ;
break;
case V_63 :
case V_34 :
break;
default:
F_51 ( V_46 ) ;
}
F_55 ( V_10 , true ) ;
}
F_56 ( V_138 , & V_10 -> V_139 ) ;
if ( V_10 -> V_21 . type == V_63 ) {
V_103 = F_57 ( V_10 , V_10 -> V_26 . V_107 . V_108 ,
V_93 ) ;
if ( ! V_103 ) {
V_105 = - V_94 ;
goto V_135;
}
F_58 ( V_103 , V_140 ) ;
F_58 ( V_103 , V_141 ) ;
F_58 ( V_103 , V_142 ) ;
V_105 = F_59 ( V_103 ) ;
if ( V_105 ) {
goto V_135;
}
F_60 ( V_103 ) ;
F_51 ( V_46 ) ;
} else if ( V_10 -> V_21 . type == V_34 ) {
F_37 ( V_2 -> V_143 , V_10 ) ;
}
if ( V_10 -> V_6 & V_144 )
F_61 ( & V_2 -> V_145 ) ;
if ( V_10 -> V_6 & V_146 )
F_61 ( & V_2 -> V_147 ) ;
F_16 ( & V_2 -> V_20 ) ;
V_106 |= F_4 ( V_2 ) ;
F_17 ( & V_2 -> V_20 ) ;
if ( V_100 )
V_2 -> V_120 ++ ;
if ( V_106 )
F_18 ( V_2 , V_106 ) ;
F_62 ( V_2 , - 1 ) ;
if ( V_46 )
F_63 ( V_46 ) ;
return 0 ;
V_135:
F_40 ( V_2 , V_10 ) ;
V_128:
if ( ! V_2 -> V_120 )
F_64 ( V_2 ) ;
V_121:
V_10 -> V_68 = NULL ;
if ( V_10 -> V_21 . type == V_40 )
F_65 ( & V_10 -> V_26 . V_111 . V_112 ) ;
F_66 ( V_138 , & V_10 -> V_139 ) ;
return V_105 ;
}
static int F_67 ( struct V_45 * V_46 )
{
struct V_9 * V_10 = F_20 ( V_46 ) ;
int V_148 ;
if ( ! F_43 ( V_46 -> V_125 ) )
return - V_127 ;
V_148 = F_24 ( V_10 , V_10 -> V_21 . type ) ;
if ( V_148 )
return V_148 ;
return F_41 ( & V_10 -> V_99 , true ) ;
}
static void F_68 ( struct V_9 * V_10 ,
bool V_149 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_6 ;
struct V_150 * V_151 , * V_152 ;
T_1 V_106 = 0 ;
int V_72 ;
enum V_153 V_154 ;
F_66 ( V_138 , & V_10 -> V_139 ) ;
if ( F_69 ( V_2 -> V_37 ) == V_10 )
F_70 ( V_2 ) ;
if ( V_10 -> V_46 )
F_71 ( V_10 -> V_46 ) ;
F_72 ( V_10 ) ;
F_73 ( V_2 , V_10 ) ;
if ( V_10 -> V_6 & V_144 )
F_74 ( & V_2 -> V_145 ) ;
if ( V_10 -> V_6 & V_146 )
F_74 ( & V_2 -> V_147 ) ;
if ( V_10 -> V_21 . type == V_62 ) {
V_2 -> V_136 -- ;
V_2 -> V_137 -- ;
} else if ( V_10 -> V_21 . type == V_31 ) {
V_2 -> V_137 -- ;
}
if ( V_10 -> V_46 ) {
F_75 ( V_10 -> V_46 ) ;
F_76 ( & V_2 -> V_155 ) ;
F_77 ( & V_2 -> V_156 , & V_10 -> V_46 -> V_157 ,
V_10 -> V_46 -> V_158 ) ;
F_78 ( & V_2 -> V_155 ) ;
F_79 ( V_10 -> V_46 ) ;
F_53 ( V_2 ) ;
}
F_80 ( & V_2 -> V_159 ) ;
F_81 ( & V_2 -> V_160 ) ;
if ( V_10 -> V_21 . type == V_62 ) {
struct V_9 * V_111 , * V_161 ;
struct V_162 * V_163 =
F_50 ( V_10 -> V_26 . V_69 . V_129 ) ;
struct V_164 * V_165 =
F_50 ( V_10 -> V_26 . V_69 . V_164 ) ;
F_13 ( V_10 ,
V_166 ) ;
F_82 ( V_10 -> V_26 . V_69 . V_129 , NULL ) ;
F_82 ( V_10 -> V_26 . V_69 . V_164 , NULL ) ;
F_83 () ;
F_36 ( V_163 ) ;
F_36 ( V_165 ) ;
F_84 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_85 ( V_111 -> V_46 ) ;
F_6 ( ! F_86 ( & V_10 -> V_26 . V_69 . V_113 ) ) ;
V_2 -> V_167 -= F_87 ( & V_10 -> V_26 . V_69 . V_168 ) ;
F_88 ( & V_10 -> V_26 . V_69 . V_168 ) ;
} else if ( V_10 -> V_21 . type == V_25 ) {
F_89 ( V_10 ) ;
}
if ( V_149 )
V_2 -> V_120 -- ;
switch ( V_10 -> V_21 . type ) {
case V_40 :
F_65 ( & V_10 -> V_26 . V_111 . V_112 ) ;
break;
case V_39 :
if ( V_10 -> V_26 . V_79 & V_130 ) {
V_2 -> V_131 -- ;
break;
}
V_2 -> V_132 -- ;
if ( V_2 -> V_132 == 0 ) {
V_2 -> V_4 . V_5 . V_6 &= ~ V_133 ;
V_106 |= V_134 ;
F_38 ( V_2 ) ;
}
F_29 ( V_10 , - 1 ) ;
F_53 ( V_2 ) ;
break;
case V_34 :
F_37 ( V_2 -> V_143 , NULL ) ;
default:
F_90 ( & V_10 -> V_169 ) ;
F_91 () ;
F_92 ( V_2 -> V_170 ) ;
F_88 ( & V_10 -> V_171 ) ;
F_93 ( V_10 ) ;
if ( V_149 )
F_40 ( V_2 , V_10 ) ;
}
V_10 -> V_68 = NULL ;
F_16 ( & V_2 -> V_20 ) ;
V_106 |= F_4 ( V_2 ) ;
F_17 ( & V_2 -> V_20 ) ;
F_62 ( V_2 , - 1 ) ;
if ( V_2 -> V_120 == 0 ) {
if ( V_2 -> V_35 -> V_122 )
F_94 ( & V_2 -> V_123 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
V_106 = 0 ;
}
V_154 = V_2 -> V_172 ;
F_97 ( V_2 , NULL , V_173 ) ;
if ( V_106 || ( V_154 != V_2 -> V_172 ) )
F_18 ( V_2 , V_106 ) ;
F_98 ( & V_2 -> V_174 , V_6 ) ;
for ( V_72 = 0 ; V_72 < V_175 ; V_72 ++ ) {
F_99 (&local->pending[i], skb, tmp) {
struct V_176 * V_177 = F_100 ( V_151 ) ;
if ( V_177 -> V_85 . V_21 == & V_10 -> V_21 ) {
F_101 ( V_151 , & V_2 -> V_178 [ V_72 ] ) ;
F_102 ( & V_2 -> V_4 , V_151 ) ;
}
}
}
F_103 ( & V_2 -> V_174 , V_6 ) ;
if ( V_2 -> V_132 == V_2 -> V_120 && V_2 -> V_132 > 0 )
F_32 ( V_2 ) ;
}
static int F_104 ( struct V_45 * V_46 )
{
struct V_9 * V_10 = F_20 ( V_46 ) ;
F_68 ( V_10 , true ) ;
return 0 ;
}
static void F_105 ( struct V_45 * V_46 )
{
struct V_9 * V_10 = F_20 ( V_46 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_179 , V_180 , V_181 , V_182 ;
V_179 = ! ! ( V_46 -> V_6 & V_183 ) ;
V_180 = ! ! ( V_46 -> V_6 & V_184 ) ;
V_181 = ! ! ( V_10 -> V_6 & V_144 ) ;
V_182 = ! ! ( V_10 -> V_6 & V_146 ) ;
if ( V_179 != V_181 ) {
if ( V_46 -> V_6 & V_183 )
F_61 ( & V_2 -> V_145 ) ;
else
F_74 ( & V_2 -> V_145 ) ;
V_10 -> V_6 ^= V_144 ;
}
if ( V_180 != V_182 ) {
if ( V_46 -> V_6 & V_184 )
F_61 ( & V_2 -> V_147 ) ;
else
F_74 ( & V_2 -> V_147 ) ;
V_10 -> V_6 ^= V_146 ;
}
F_76 ( & V_2 -> V_155 ) ;
F_106 ( & V_2 -> V_156 , & V_46 -> V_157 , V_46 -> V_158 ) ;
F_78 ( & V_2 -> V_155 ) ;
F_107 ( & V_2 -> V_4 , & V_2 -> V_185 ) ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_186 ;
int V_72 ;
F_93 ( V_10 ) ;
F_109 ( V_10 ) ;
for ( V_72 = 0 ; V_72 < V_187 ; V_72 ++ )
F_110 ( & V_10 -> V_188 [ V_72 ] . V_189 ) ;
V_10 -> V_190 = 0 ;
if ( F_111 ( & V_10 -> V_21 ) )
F_112 ( V_10 ) ;
V_186 = F_73 ( V_2 , V_10 ) ;
F_6 ( V_186 ) ;
}
static void F_113 ( struct V_45 * V_46 )
{
F_108 ( F_20 ( V_46 ) ) ;
}
static T_4 F_114 ( struct V_45 * V_46 ,
struct V_150 * V_151 )
{
return F_115 ( F_20 ( V_46 ) , V_151 ) ;
}
static T_4 F_116 ( struct V_45 * V_46 ,
struct V_150 * V_151 )
{
struct V_9 * V_10 = F_20 ( V_46 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_191 * V_192 ;
struct V_193 * V_194 = ( void * ) V_151 -> V_195 ;
if ( V_2 -> V_4 . V_71 < V_73 )
return 0 ;
if ( V_151 -> V_196 < 4 ||
V_151 -> V_196 < F_117 ( V_194 -> V_197 ) + 2 )
return 0 ;
V_192 = ( void * ) ( ( V_198 * ) V_151 -> V_195 + F_117 ( V_194 -> V_197 ) ) ;
return F_118 ( V_10 , V_151 , V_192 ) ;
}
static void F_119 ( struct V_45 * V_46 )
{
F_120 ( V_46 ) ;
V_46 -> V_199 &= ~ V_200 ;
V_46 -> V_201 = & V_202 ;
V_46 -> V_203 = V_204 ;
}
static void F_121 ( struct V_205 * V_169 )
{
struct V_9 * V_10 =
F_45 ( V_169 , struct V_9 , V_169 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_150 * V_151 ;
struct V_102 * V_103 ;
struct V_206 * V_207 ;
if ( ! F_11 ( V_10 ) )
return;
if ( V_2 -> V_13 )
return;
if ( F_122 ( V_2 -> V_208 ,
L_5 ) )
return;
while ( ( V_151 = F_123 ( & V_10 -> V_171 ) ) ) {
struct V_209 * V_210 = ( void * ) V_151 -> V_195 ;
if ( V_151 -> V_211 == V_212 ) {
V_207 = ( void * ) & V_151 -> V_213 ;
F_124 ( & V_10 -> V_21 , V_207 -> V_214 ,
V_207 -> V_215 ) ;
} else if ( V_151 -> V_211 == V_216 ) {
V_207 = ( void * ) & V_151 -> V_213 ;
F_125 ( & V_10 -> V_21 , V_207 -> V_214 ,
V_207 -> V_215 ) ;
} else if ( F_126 ( V_210 -> V_217 ) &&
V_210 -> V_26 . V_218 . V_219 == V_220 ) {
int V_196 = V_151 -> V_196 ;
F_16 ( & V_2 -> V_221 ) ;
V_103 = F_127 ( V_10 , V_210 -> V_55 ) ;
if ( V_103 ) {
switch ( V_210 -> V_26 . V_218 . V_26 . V_222 . V_223 ) {
case V_224 :
F_128 (
V_2 , V_103 , V_210 , V_196 ) ;
break;
case V_225 :
F_129 ( V_2 , V_103 ,
V_210 , V_196 ) ;
break;
case V_226 :
F_130 ( V_10 , V_103 ,
V_210 , V_196 ) ;
break;
default:
F_6 ( 1 ) ;
break;
}
}
F_17 ( & V_2 -> V_221 ) ;
} else if ( F_131 ( V_210 -> V_217 ) ) {
struct V_191 * V_192 = ( void * ) V_210 ;
F_6 ( V_192 -> V_217 &
F_132 ( V_227 ) ) ;
F_6 ( ! ( V_192 -> V_228 &
F_132 ( V_229 ) ) ) ;
F_16 ( & V_2 -> V_221 ) ;
V_103 = F_127 ( V_10 , V_210 -> V_55 ) ;
if ( V_103 ) {
T_4 V_215 = * F_133 ( V_192 ) &
V_230 ;
F_134 (
V_103 , V_215 , V_231 ,
V_232 ,
true ) ;
}
F_17 ( & V_2 -> V_221 ) ;
} else switch ( V_10 -> V_21 . type ) {
case V_25 :
F_135 ( V_10 , V_151 ) ;
break;
case V_31 :
F_136 ( V_10 , V_151 ) ;
break;
case V_49 :
if ( ! F_111 ( & V_10 -> V_21 ) )
break;
F_137 ( V_10 , V_151 ) ;
break;
default:
F_122 ( 1 , L_6 ) ;
break;
}
F_138 ( V_151 ) ;
}
switch ( V_10 -> V_21 . type ) {
case V_25 :
F_139 ( V_10 ) ;
break;
case V_31 :
F_140 ( V_10 ) ;
break;
case V_49 :
if ( ! F_111 ( & V_10 -> V_21 ) )
break;
F_141 ( V_10 ) ;
break;
default:
break;
}
}
static void F_142 ( struct V_9 * V_10 ,
enum V_64 type )
{
memset ( & V_10 -> V_26 , 0 , sizeof( V_10 -> V_26 ) ) ;
V_10 -> V_21 . type = type ;
V_10 -> V_21 . V_233 = false ;
V_10 -> V_99 . V_65 = type ;
V_10 -> V_114 = F_143 ( V_234 ) ;
V_10 -> V_115 = false ;
V_10 -> V_235 = 0 ;
if ( V_10 -> V_46 ) {
V_10 -> V_46 -> V_201 = & V_202 ;
V_10 -> V_46 -> type = V_236 ;
}
F_144 ( & V_10 -> V_171 ) ;
F_145 ( & V_10 -> V_169 , F_121 ) ;
switch ( type ) {
case V_119 :
type = V_62 ;
V_10 -> V_21 . type = type ;
V_10 -> V_21 . V_233 = true ;
case V_62 :
F_144 ( & V_10 -> V_26 . V_69 . V_168 ) ;
F_146 ( & V_10 -> V_26 . V_69 . V_113 ) ;
break;
case V_118 :
type = V_25 ;
V_10 -> V_21 . type = type ;
V_10 -> V_21 . V_233 = true ;
case V_25 :
F_147 ( V_10 ) ;
break;
case V_31 :
F_148 ( V_10 ) ;
break;
case V_49 :
if ( F_111 ( & V_10 -> V_21 ) )
F_149 ( V_10 ) ;
break;
case V_39 :
V_10 -> V_46 -> type = V_237 ;
V_10 -> V_46 -> V_201 = & V_238 ;
V_10 -> V_26 . V_79 = V_239 |
V_240 ;
break;
case V_63 :
case V_40 :
case V_34 :
break;
case V_116 :
case V_117 :
F_150 () ;
break;
}
F_151 ( V_10 ) ;
}
static int F_152 ( struct V_9 * V_10 ,
enum V_64 type )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_56 , V_148 ;
enum V_64 V_241 = type ;
bool V_233 = false ;
F_25 () ;
if ( ! V_2 -> V_35 -> V_242 )
return - V_57 ;
switch ( V_10 -> V_21 . type ) {
case V_62 :
case V_25 :
case V_31 :
break;
default:
return - V_57 ;
}
switch ( type ) {
case V_62 :
case V_25 :
case V_31 :
break;
case V_118 :
V_233 = true ;
V_241 = V_25 ;
break;
case V_119 :
V_233 = true ;
V_241 = V_62 ;
break;
default:
return - V_57 ;
}
V_56 = F_24 ( V_10 , V_241 ) ;
if ( V_56 )
return V_56 ;
F_68 ( V_10 , false ) ;
F_108 ( V_10 ) ;
V_56 = F_153 ( V_2 , V_10 , V_241 , V_233 ) ;
if ( V_56 )
type = V_10 -> V_21 . type ;
F_27 ( V_10 ) ;
F_142 ( V_10 , type ) ;
V_148 = F_41 ( & V_10 -> V_99 , false ) ;
F_122 ( V_148 , L_7 , V_148 ) ;
return V_56 ;
}
int F_154 ( struct V_9 * V_10 ,
enum V_64 type )
{
int V_56 ;
F_25 () ;
if ( type == F_155 ( & V_10 -> V_21 ) )
return 0 ;
if ( V_10 -> V_2 -> V_243 -> V_6 & V_244 &&
type == V_31 )
return - V_245 ;
if ( F_11 ( V_10 ) ) {
V_56 = F_152 ( V_10 , type ) ;
if ( V_56 )
return V_56 ;
} else {
F_108 ( V_10 ) ;
F_142 ( V_10 , type ) ;
}
V_10 -> V_21 . V_22 . V_246 =
F_156 ( V_10 -> V_2 ,
V_10 -> V_2 -> V_243 -> V_247 ) ;
V_10 -> V_248 = 0 ;
if ( type == V_25 )
V_10 -> V_26 . V_27 . V_249 = false ;
return 0 ;
}
static void F_157 ( struct V_1 * V_2 ,
V_198 * V_126 , enum V_64 type )
{
struct V_9 * V_10 ;
T_5 V_250 , V_251 , V_53 , V_252 , V_253 ;
V_198 * V_254 ;
V_198 V_255 [ V_59 ] ;
int V_72 ;
memcpy ( V_126 , V_2 -> V_4 . V_97 -> V_126 , V_59 ) ;
if ( F_49 ( V_2 -> V_4 . V_97 -> V_256 ) &&
V_2 -> V_4 . V_97 -> V_257 <= 1 )
return;
F_16 ( & V_2 -> V_19 ) ;
switch ( type ) {
case V_39 :
break;
case V_63 :
case V_40 :
F_10 (sdata, &local->interfaces, list) {
if ( V_10 -> V_21 . type != V_62 )
continue;
memcpy ( V_126 , V_10 -> V_21 . V_53 , V_59 ) ;
break;
}
break;
case V_118 :
case V_119 :
if ( V_2 -> V_4 . V_6 & V_258 ) {
F_10 (sdata, &local->interfaces, list) {
if ( V_10 -> V_21 . type != V_34 )
continue;
if ( ! F_11 ( V_10 ) )
continue;
memcpy ( V_126 , V_10 -> V_21 . V_53 , V_59 ) ;
goto V_91;
}
}
default:
for ( V_72 = 0 ; V_72 < V_2 -> V_4 . V_97 -> V_257 ; V_72 ++ ) {
bool V_259 = false ;
F_10 (sdata, &local->interfaces, list) {
if ( memcmp ( V_2 -> V_4 . V_97 -> V_260 [ V_72 ] . V_53 ,
V_10 -> V_21 . V_53 , V_59 ) == 0 ) {
V_259 = true ;
break;
}
}
if ( ! V_259 ) {
memcpy ( V_126 ,
V_2 -> V_4 . V_97 -> V_260 [ V_72 ] . V_53 ,
V_59 ) ;
break;
}
}
if ( F_49 ( V_2 -> V_4 . V_97 -> V_256 ) )
break;
V_254 = V_2 -> V_4 . V_97 -> V_256 ;
V_250 = ( ( T_5 ) V_254 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_254 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_254 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_254 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_254 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_254 [ 5 ] << 0 * 8 ) ;
if ( F_158 ( V_250 ) + F_159 ( V_250 ) != F_160 ( V_250 ) ) {
F_161 ( L_8 ) ;
break;
}
V_254 = V_2 -> V_4 . V_97 -> V_126 ;
V_251 = ( ( T_5 ) V_254 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_254 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_254 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_254 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_254 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_254 [ 5 ] << 0 * 8 ) ;
V_253 = 1ULL << F_158 ( V_250 ) ;
V_252 = ( V_251 & V_250 ) ;
V_53 = ( V_251 & ~ V_250 ) | ( V_252 & V_250 ) ;
do {
bool V_259 = false ;
V_255 [ 5 ] = V_53 >> 0 * 8 ;
V_255 [ 4 ] = V_53 >> 1 * 8 ;
V_255 [ 3 ] = V_53 >> 2 * 8 ;
V_255 [ 2 ] = V_53 >> 3 * 8 ;
V_255 [ 1 ] = V_53 >> 4 * 8 ;
V_255 [ 0 ] = V_53 >> 5 * 8 ;
V_252 += V_253 ;
F_10 (sdata, &local->interfaces, list) {
if ( memcmp ( V_255 , V_10 -> V_21 . V_53 ,
V_59 ) == 0 ) {
V_259 = true ;
break;
}
}
if ( ! V_259 ) {
memcpy ( V_126 , V_255 , V_59 ) ;
break;
}
V_53 = ( V_251 & ~ V_250 ) | ( V_252 & V_250 ) ;
} while ( V_53 != V_251 );
break;
}
V_91:
F_17 ( & V_2 -> V_19 ) ;
}
int F_162 ( struct V_1 * V_2 , const char * V_95 ,
struct V_98 * * V_261 , enum V_64 type ,
struct V_262 * V_263 )
{
struct V_45 * V_264 = NULL ;
struct V_9 * V_10 = NULL ;
int V_56 , V_72 ;
int V_265 = 1 ;
F_25 () ;
if ( type == V_34 ) {
struct V_98 * V_99 ;
V_10 = F_33 ( sizeof( * V_10 ) + V_2 -> V_4 . V_92 ,
V_93 ) ;
if ( ! V_10 )
return - V_94 ;
V_99 = & V_10 -> V_99 ;
V_10 -> V_46 = NULL ;
F_163 ( V_10 -> V_95 , V_95 , V_96 ) ;
F_157 ( V_2 , V_99 -> V_266 , type ) ;
memcpy ( V_10 -> V_21 . V_53 , V_99 -> V_266 , V_59 ) ;
} else {
if ( V_2 -> V_4 . V_71 >= V_73 )
V_265 = V_73 ;
V_264 = F_164 ( sizeof( * V_10 ) +
V_2 -> V_4 . V_92 ,
V_95 , F_119 , V_265 , 1 ) ;
if ( ! V_264 )
return - V_94 ;
F_165 ( V_264 , F_166 ( V_2 -> V_4 . V_97 ) ) ;
V_264 -> V_267 = V_2 -> V_268 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_269
+ V_270 ;
V_264 -> V_271 = V_272 ;
V_56 = F_167 ( V_264 , V_264 -> V_95 ) ;
if ( V_56 < 0 ) {
V_204 ( V_264 ) ;
return V_56 ;
}
F_157 ( V_2 , V_264 -> V_126 , type ) ;
memcpy ( V_264 -> V_125 , V_264 -> V_126 , V_59 ) ;
F_168 ( V_264 , F_169 ( V_2 -> V_4 . V_97 ) ) ;
V_10 = F_170 ( V_264 ) ;
V_264 -> V_273 = & V_10 -> V_99 ;
memcpy ( V_10 -> V_21 . V_53 , V_264 -> V_125 , V_59 ) ;
memcpy ( V_10 -> V_95 , V_264 -> V_95 , V_96 ) ;
V_10 -> V_46 = V_264 ;
}
V_10 -> V_99 . V_97 = V_2 -> V_4 . V_97 ;
V_10 -> V_2 = V_2 ;
#ifdef F_171
V_10 -> V_274 = true ;
#endif
for ( V_72 = 0 ; V_72 < V_187 ; V_72 ++ )
F_144 ( & V_10 -> V_188 [ V_72 ] . V_189 ) ;
F_146 ( & V_10 -> V_275 ) ;
for ( V_72 = 0 ; V_72 < V_276 ; V_72 ++ ) {
struct V_277 * V_278 ;
V_278 = V_2 -> V_4 . V_97 -> V_279 [ V_72 ] ;
V_10 -> V_280 [ V_72 ] =
V_278 ? ( 1 << V_278 -> V_281 ) - 1 : 0 ;
if ( V_278 )
memcpy ( V_10 -> V_282 [ V_72 ] ,
V_278 -> V_283 . V_284 . V_285 ,
sizeof( V_10 -> V_282 [ V_72 ] ) ) ;
else
memset ( V_10 -> V_282 [ V_72 ] , 0 ,
sizeof( V_10 -> V_282 [ V_72 ] ) ) ;
}
F_31 ( V_10 ) ;
F_142 ( V_10 , type ) ;
if ( V_264 ) {
if ( V_263 ) {
V_264 -> V_273 -> V_249 = V_263 -> V_249 ;
if ( type == V_25 )
V_10 -> V_26 . V_27 . V_249 = V_263 -> V_249 ;
}
V_264 -> V_286 |= V_2 -> V_4 . V_287 ;
V_56 = F_172 ( V_264 ) ;
if ( V_56 ) {
V_204 ( V_264 ) ;
return V_56 ;
}
}
F_16 ( & V_2 -> V_19 ) ;
F_173 ( & V_10 -> V_112 , & V_2 -> V_288 ) ;
F_17 ( & V_2 -> V_19 ) ;
if ( V_261 )
* V_261 = & V_10 -> V_99 ;
return 0 ;
}
void F_174 ( struct V_9 * V_10 )
{
F_25 () ;
F_16 ( & V_10 -> V_2 -> V_19 ) ;
F_175 ( & V_10 -> V_112 ) ;
F_17 ( & V_10 -> V_2 -> V_19 ) ;
F_83 () ;
if ( V_10 -> V_46 ) {
F_176 ( V_10 -> V_46 ) ;
} else {
F_177 ( & V_10 -> V_99 ) ;
F_36 ( V_10 ) ;
}
}
void F_178 ( struct V_9 * V_10 )
{
if ( F_28 ( ! F_179 ( V_138 , & V_10 -> V_139 ) ) )
return;
F_68 ( V_10 , true ) ;
F_108 ( V_10 ) ;
}
void F_180 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_152 ;
F_181 ( V_289 ) ;
F_181 ( V_290 ) ;
F_25 () ;
F_16 ( & V_2 -> V_19 ) ;
F_84 (sdata, tmp, &local->interfaces, list) {
F_65 ( & V_10 -> V_112 ) ;
if ( V_10 -> V_46 )
F_182 ( V_10 -> V_46 , & V_289 ) ;
else
F_44 ( & V_10 -> V_112 , & V_290 ) ;
}
F_17 ( & V_2 -> V_19 ) ;
F_183 ( & V_289 ) ;
F_65 ( & V_289 ) ;
F_84 (sdata, tmp, &wdev_list, list) {
F_65 ( & V_10 -> V_112 ) ;
F_177 ( & V_10 -> V_99 ) ;
F_36 ( V_10 ) ;
}
}
static int F_184 ( struct V_291 * V_292 ,
unsigned long V_139 ,
void * V_264 )
{
struct V_45 * V_46 = V_264 ;
struct V_9 * V_10 ;
if ( V_139 != V_293 )
return 0 ;
if ( ! V_46 -> V_273 || ! V_46 -> V_273 -> V_97 )
return 0 ;
if ( V_46 -> V_273 -> V_97 -> V_294 != V_295 )
return 0 ;
V_10 = F_20 ( V_46 ) ;
memcpy ( V_10 -> V_95 , V_46 -> V_95 , V_96 ) ;
F_185 ( V_10 ) ;
return 0 ;
}
int F_186 ( void )
{
return F_187 ( & V_296 ) ;
}
void F_188 ( void )
{
F_189 ( & V_296 ) ;
}
