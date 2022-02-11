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
V_10 -> V_21 . V_22 . V_23 = false ;
V_11 ++ ;
}
if ( ! V_2 -> V_34 -> V_35 ) {
F_10 (roc, &local->roc_list, list) {
V_12 = true ;
V_17 -> V_10 -> V_21 . V_22 . V_23 = false ;
}
}
V_10 = F_12 ( V_2 -> V_36 ,
F_8 ( & V_2 -> V_20 ) ) ;
if ( V_10 && ! ( V_2 -> V_4 . V_6 & V_37 ) ) {
V_13 = true ;
V_10 -> V_21 . V_22 . V_23 = false ;
}
F_10 (sdata, &local->interfaces, list) {
if ( V_10 -> V_21 . type == V_38 ||
V_10 -> V_21 . type == V_39 )
continue;
if ( V_10 -> V_24 == V_10 -> V_21 . V_22 . V_23 )
continue;
if ( ! F_11 ( V_10 ) )
continue;
F_13 ( V_10 , V_40 ) ;
}
if ( V_12 || V_13 )
V_14 |= V_41 ;
else
V_15 |= V_41 ;
if ( V_11 )
V_14 |= V_42 ;
else
V_15 |= V_42 ;
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
T_1 V_43 ;
F_16 ( & V_2 -> V_19 ) ;
V_43 = F_4 ( V_2 ) ;
F_17 ( & V_2 -> V_19 ) ;
if ( V_43 )
F_18 ( V_2 , V_43 ) ;
}
static int F_19 ( struct V_44 * V_45 , int V_46 )
{
int V_47 ;
struct V_9 * V_10 = F_20 ( V_45 ) ;
V_47 = ( V_10 -> V_21 . type == V_48 ) ? 5 : 0 ;
if ( V_46 < 256 ||
V_46 > V_49 - 24 - 6 - V_47 ) {
return - V_50 ;
}
V_45 -> V_51 = V_46 ;
return 0 ;
}
static int F_21 ( struct V_44 * V_45 , void * V_52 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
struct V_53 * V_54 = V_52 ;
int V_55 ;
if ( F_11 ( V_10 ) )
return - V_56 ;
V_55 = F_22 ( V_45 , V_54 ) ;
if ( V_55 == 0 )
memcpy ( V_10 -> V_21 . V_52 , V_54 -> V_57 , V_58 ) ;
return V_55 ;
}
static inline int F_23 ( int V_59 , int V_60 )
{
return V_59 == V_38 ||
V_60 == V_38 ||
( V_59 == V_61 && V_60 == V_62 ) ||
( V_59 == V_62 &&
( V_60 == V_62 ||
V_60 == V_61 ) ) ||
( V_59 == V_61 && V_60 == V_39 ) ||
( V_59 == V_39 &&
( V_60 == V_61 ||
V_60 == V_39 ) ) ;
}
static int F_24 ( struct V_9 * V_10 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_9 * V_65 ;
F_25 () ;
F_10 (nsdata, &local->interfaces, list) {
if ( V_65 != V_10 && F_11 ( V_65 ) ) {
if ( V_64 == V_31 &&
V_65 -> V_21 . type == V_31 )
return - V_56 ;
if ( ! F_26 ( V_10 -> V_21 . V_52 ,
V_65 -> V_21 . V_52 ) )
continue;
if ( ! F_23 ( V_64 ,
V_65 -> V_21 . type ) )
return - V_66 ;
if ( V_64 == V_39 &&
V_65 -> V_21 . type == V_61 )
V_10 -> V_67 = & V_65 -> V_26 . V_68 ;
}
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
int V_69 = V_10 -> V_2 -> V_4 . V_70 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
if ( F_28 ( V_10 -> V_21 . V_73 [ V_71 ] ==
V_74 ) )
return - V_50 ;
if ( F_28 ( V_10 -> V_21 . V_73 [ V_71 ] >=
V_69 ) )
return - V_50 ;
}
if ( ( V_10 -> V_21 . type != V_61 ) ||
! ( V_10 -> V_2 -> V_4 . V_6 & V_75 ) ) {
V_10 -> V_21 . V_76 = V_74 ;
return 0 ;
}
if ( F_28 ( V_10 -> V_21 . V_76 == V_74 ) )
return - V_50 ;
if ( F_28 ( V_10 -> V_21 . V_76 >= V_69 ) )
return - V_50 ;
return 0 ;
}
void F_29 ( struct V_9 * V_10 ,
const int V_77 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_6 = V_10 -> V_26 . V_78 ;
#define F_30 ( T_2 , T_3 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_30 ( V_79 , V_80 ) ;
F_30 ( V_81 , V_82 ) ;
F_30 ( V_83 , V_84 ) ;
F_30 ( V_83 , V_85 ) ;
F_30 ( V_86 , V_87 ) ;
#undef F_30
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
if ( V_2 -> V_4 . V_6 & V_75 )
V_10 -> V_21 . V_73 [ V_71 ] = V_74 ;
else if ( V_2 -> V_4 . V_70 >= V_72 )
V_10 -> V_21 . V_73 [ V_71 ] = V_71 ;
else
V_10 -> V_21 . V_73 [ V_71 ] = 0 ;
}
V_10 -> V_21 . V_76 = V_74 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_55 = 0 ;
if ( ! ( V_2 -> V_4 . V_6 & V_88 ) )
return 0 ;
F_16 ( & V_2 -> V_19 ) ;
if ( V_2 -> V_89 )
goto V_90;
V_10 = F_33 ( sizeof( * V_10 ) + V_2 -> V_4 . V_91 , V_92 ) ;
if ( ! V_10 ) {
V_55 = - V_93 ;
goto V_90;
}
V_10 -> V_2 = V_2 ;
V_10 -> V_21 . type = V_38 ;
snprintf ( V_10 -> V_94 , V_95 , L_4 ,
F_34 ( V_2 -> V_4 . V_96 ) ) ;
F_31 ( V_10 ) ;
V_55 = F_35 ( V_2 , V_10 ) ;
if ( F_6 ( V_55 ) ) {
F_36 ( V_10 ) ;
goto V_90;
}
V_55 = F_27 ( V_10 ) ;
if ( V_55 ) {
F_36 ( V_10 ) ;
goto V_90;
}
F_37 ( V_2 -> V_89 , V_10 ) ;
V_90:
F_17 ( & V_2 -> V_19 ) ;
return V_55 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
if ( ! ( V_2 -> V_4 . V_6 & V_88 ) )
return;
F_16 ( & V_2 -> V_19 ) ;
V_10 = F_12 ( V_2 -> V_89 ,
F_8 ( & V_2 -> V_19 ) ) ;
if ( ! V_10 )
goto V_90;
F_37 ( V_2 -> V_89 , NULL ) ;
F_39 () ;
F_40 ( V_2 , V_10 ) ;
F_36 ( V_10 ) ;
V_90:
F_17 ( & V_2 -> V_19 ) ;
}
static int F_41 ( struct V_44 * V_45 , bool V_97 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_98 * V_99 ;
T_1 V_100 = 0 ;
int V_101 ;
T_1 V_102 = 0 ;
switch ( V_10 -> V_21 . type ) {
case V_62 :
if ( ! F_42 ( V_10 -> V_26 . V_103 . V_104 ) )
return - V_105 ;
break;
case V_39 : {
struct V_9 * V_106 ;
if ( ! V_10 -> V_67 )
return - V_105 ;
F_43 ( & V_10 -> V_26 . V_107 . V_108 , & V_10 -> V_67 -> V_109 ) ;
V_106 = F_44 ( V_10 -> V_67 ,
struct V_9 , V_26 . V_68 ) ;
V_10 -> V_110 =
V_106 -> V_110 ;
V_10 -> V_111 =
V_106 -> V_111 ;
break;
}
case V_61 :
V_10 -> V_67 = & V_10 -> V_26 . V_68 ;
break;
case V_48 :
case V_25 :
case V_38 :
case V_31 :
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
F_6 ( 1 ) ;
break;
}
if ( V_2 -> V_116 == 0 ) {
V_101 = F_45 ( V_2 ) ;
if ( V_101 )
goto V_117;
if ( V_2 -> V_34 -> V_118 )
F_46 ( & V_2 -> V_119 ) ;
V_102 = ~ 0 ;
F_47 ( V_2 , true ) ;
F_14 ( V_2 ,
V_120 , 0 ) ;
}
if ( F_48 ( V_45 -> V_121 ) ) {
memcpy ( V_45 -> V_121 ,
V_2 -> V_4 . V_96 -> V_122 ,
V_58 ) ;
memcpy ( V_45 -> V_122 , V_45 -> V_121 , V_58 ) ;
if ( ! F_42 ( V_45 -> V_121 ) ) {
V_101 = - V_123 ;
goto V_124;
}
}
switch ( V_10 -> V_21 . type ) {
case V_39 :
if ( F_49 ( V_10 -> V_67 -> V_125 ) )
F_50 ( V_45 ) ;
else
F_51 ( V_45 ) ;
break;
case V_38 :
if ( V_10 -> V_26 . V_78 & V_126 ) {
V_2 -> V_127 ++ ;
break;
}
if ( V_2 -> V_128 == 0 && V_2 -> V_116 == 0 ) {
V_101 = F_32 ( V_2 ) ;
if ( V_101 )
goto V_124;
}
V_2 -> V_128 ++ ;
if ( V_2 -> V_128 == 1 ) {
V_2 -> V_4 . V_5 . V_6 |= V_129 ;
V_102 |= V_130 ;
}
F_29 ( V_10 , 1 ) ;
F_52 ( V_2 ) ;
F_50 ( V_45 ) ;
break;
default:
if ( V_97 ) {
F_38 ( V_2 ) ;
V_101 = F_35 ( V_2 , V_10 ) ;
if ( V_101 )
goto V_124;
V_101 = F_27 ( V_10 ) ;
if ( V_101 )
goto V_131;
}
if ( V_10 -> V_21 . type == V_61 ) {
V_2 -> V_132 ++ ;
V_2 -> V_133 ++ ;
F_52 ( V_2 ) ;
} else if ( V_10 -> V_21 . type == V_31 ) {
V_2 -> V_133 ++ ;
}
V_100 |= F_53 ( V_10 ) ;
F_13 ( V_10 , V_100 ) ;
if ( V_10 -> V_21 . type == V_25 ||
V_10 -> V_21 . type == V_31 ||
V_10 -> V_21 . type == V_61 )
F_51 ( V_45 ) ;
else
F_50 ( V_45 ) ;
F_54 ( V_10 , true ) ;
}
F_55 ( V_134 , & V_10 -> V_135 ) ;
if ( V_10 -> V_21 . type == V_62 ) {
V_99 = F_56 ( V_10 , V_10 -> V_26 . V_103 . V_104 ,
V_92 ) ;
if ( ! V_99 ) {
V_101 = - V_93 ;
goto V_131;
}
F_57 ( V_99 , V_136 ) ;
F_57 ( V_99 , V_137 ) ;
F_57 ( V_99 , V_138 ) ;
V_101 = F_58 ( V_99 ) ;
if ( V_101 ) {
goto V_131;
}
F_59 ( V_99 ) ;
}
if ( V_10 -> V_6 & V_139 )
F_60 ( & V_2 -> V_140 ) ;
if ( V_10 -> V_6 & V_141 )
F_60 ( & V_2 -> V_142 ) ;
F_16 ( & V_2 -> V_20 ) ;
V_102 |= F_4 ( V_2 ) ;
F_17 ( & V_2 -> V_20 ) ;
if ( V_97 )
V_2 -> V_116 ++ ;
if ( V_102 )
F_18 ( V_2 , V_102 ) ;
F_61 ( V_2 , - 1 ) ;
F_62 ( V_45 ) ;
return 0 ;
V_131:
F_40 ( V_2 , V_10 ) ;
V_124:
if ( ! V_2 -> V_116 )
F_63 ( V_2 ) ;
V_117:
V_10 -> V_67 = NULL ;
if ( V_10 -> V_21 . type == V_39 )
F_64 ( & V_10 -> V_26 . V_107 . V_108 ) ;
F_65 ( V_134 , & V_10 -> V_135 ) ;
return V_101 ;
}
static int F_66 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
int V_143 ;
if ( ! F_42 ( V_45 -> V_121 ) )
return - V_123 ;
V_143 = F_24 ( V_10 , V_10 -> V_21 . type ) ;
if ( V_143 )
return V_143 ;
return F_41 ( V_45 , true ) ;
}
static void F_67 ( struct V_9 * V_10 ,
bool V_144 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_6 ;
struct V_145 * V_146 , * V_147 ;
T_1 V_102 = 0 ;
int V_71 ;
enum V_148 V_149 ;
F_65 ( V_134 , & V_10 -> V_135 ) ;
if ( F_68 ( V_2 -> V_36 ) == V_10 )
F_69 ( V_2 ) ;
F_70 ( V_10 -> V_45 ) ;
F_71 ( V_10 ) ;
F_72 ( V_2 , V_10 ) ;
if ( V_10 -> V_6 & V_139 )
F_73 ( & V_2 -> V_140 ) ;
if ( V_10 -> V_6 & V_141 )
F_73 ( & V_2 -> V_142 ) ;
if ( V_10 -> V_21 . type == V_61 ) {
V_2 -> V_132 -- ;
V_2 -> V_133 -- ;
} else if ( V_10 -> V_21 . type == V_31 ) {
V_2 -> V_133 -- ;
}
F_74 ( V_10 -> V_45 ) ;
F_75 ( & V_2 -> V_150 ) ;
F_76 ( & V_2 -> V_151 , & V_10 -> V_45 -> V_152 ,
V_10 -> V_45 -> V_153 ) ;
F_77 ( & V_2 -> V_150 ) ;
F_78 ( V_10 -> V_45 ) ;
F_52 ( V_2 ) ;
F_79 ( & V_2 -> V_154 ) ;
F_80 ( & V_2 -> V_155 ) ;
if ( V_10 -> V_21 . type == V_61 ) {
struct V_9 * V_107 , * V_156 ;
struct V_157 * V_158 =
F_49 ( V_10 -> V_26 . V_68 . V_125 ) ;
struct V_145 * V_159 =
F_49 ( V_10 -> V_26 . V_68 . V_160 ) ;
F_13 ( V_10 ,
V_161 ) ;
F_81 ( V_10 -> V_26 . V_68 . V_125 , NULL ) ;
F_81 ( V_10 -> V_26 . V_68 . V_160 , NULL ) ;
F_82 () ;
F_36 ( V_158 ) ;
F_83 ( V_159 ) ;
F_84 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_85 ( V_107 -> V_45 ) ;
F_6 ( ! F_86 ( & V_10 -> V_26 . V_68 . V_109 ) ) ;
V_2 -> V_162 -= F_87 ( & V_10 -> V_26 . V_68 . V_163 ) ;
F_88 ( & V_10 -> V_26 . V_68 . V_163 ) ;
} else if ( V_10 -> V_21 . type == V_25 ) {
F_89 ( V_10 ) ;
}
if ( V_144 )
V_2 -> V_116 -- ;
switch ( V_10 -> V_21 . type ) {
case V_39 :
F_64 ( & V_10 -> V_26 . V_107 . V_108 ) ;
break;
case V_38 :
if ( V_10 -> V_26 . V_78 & V_126 ) {
V_2 -> V_127 -- ;
break;
}
V_2 -> V_128 -- ;
if ( V_2 -> V_128 == 0 ) {
V_2 -> V_4 . V_5 . V_6 &= ~ V_129 ;
V_102 |= V_130 ;
F_38 ( V_2 ) ;
}
F_29 ( V_10 , - 1 ) ;
F_52 ( V_2 ) ;
break;
default:
F_90 ( & V_10 -> V_164 ) ;
F_82 () ;
F_88 ( & V_10 -> V_165 ) ;
if ( V_10 -> V_21 . type == V_48 )
F_13 ( V_10 ,
V_161 ) ;
F_91 ( V_10 ) ;
if ( V_144 )
F_40 ( V_2 , V_10 ) ;
}
V_10 -> V_67 = NULL ;
F_16 ( & V_2 -> V_20 ) ;
V_102 |= F_4 ( V_2 ) ;
F_17 ( & V_2 -> V_20 ) ;
F_61 ( V_2 , - 1 ) ;
if ( V_2 -> V_116 == 0 ) {
if ( V_2 -> V_34 -> V_118 )
F_92 ( & V_2 -> V_119 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
V_102 = 0 ;
}
V_149 = V_2 -> V_166 ;
F_95 ( V_2 , NULL , V_167 ) ;
if ( V_102 || ( V_149 != V_2 -> V_166 ) )
F_18 ( V_2 , V_102 ) ;
F_96 ( & V_2 -> V_168 , V_6 ) ;
for ( V_71 = 0 ; V_71 < V_169 ; V_71 ++ ) {
F_97 (&local->pending[i], skb, tmp) {
struct V_170 * V_171 = F_98 ( V_146 ) ;
if ( V_171 -> V_84 . V_21 == & V_10 -> V_21 ) {
F_99 ( V_146 , & V_2 -> V_172 [ V_71 ] ) ;
F_100 ( V_146 ) ;
}
}
}
F_101 ( & V_2 -> V_168 , V_6 ) ;
if ( V_2 -> V_128 == V_2 -> V_116 && V_2 -> V_128 > 0 )
F_32 ( V_2 ) ;
}
static int F_102 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
F_67 ( V_10 , true ) ;
return 0 ;
}
static void F_103 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_173 , V_174 , V_175 , V_176 ;
V_173 = ! ! ( V_45 -> V_6 & V_177 ) ;
V_174 = ! ! ( V_45 -> V_6 & V_178 ) ;
V_175 = ! ! ( V_10 -> V_6 & V_139 ) ;
V_176 = ! ! ( V_10 -> V_6 & V_141 ) ;
if ( V_173 != V_175 ) {
if ( V_45 -> V_6 & V_177 )
F_60 ( & V_2 -> V_140 ) ;
else
F_73 ( & V_2 -> V_140 ) ;
V_10 -> V_6 ^= V_139 ;
}
if ( V_174 != V_176 ) {
if ( V_45 -> V_6 & V_178 )
F_60 ( & V_2 -> V_142 ) ;
else
F_73 ( & V_2 -> V_142 ) ;
V_10 -> V_6 ^= V_141 ;
}
F_75 ( & V_2 -> V_150 ) ;
F_104 ( & V_2 -> V_151 , & V_45 -> V_152 , V_45 -> V_153 ) ;
F_77 ( & V_2 -> V_150 ) ;
F_105 ( & V_2 -> V_4 , & V_2 -> V_179 ) ;
}
static void F_106 ( struct V_44 * V_45 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_180 ;
int V_71 ;
F_91 ( V_10 ) ;
F_107 ( V_10 ) ;
for ( V_71 = 0 ; V_71 < V_181 ; V_71 ++ )
F_108 ( & V_10 -> V_182 [ V_71 ] . V_183 ) ;
V_10 -> V_184 = 0 ;
if ( F_109 ( & V_10 -> V_21 ) )
F_110 ( V_10 ) ;
V_180 = F_72 ( V_2 , V_10 ) ;
F_6 ( V_180 ) ;
}
static T_4 F_111 ( struct V_44 * V_45 ,
struct V_145 * V_146 )
{
return F_112 ( F_20 ( V_45 ) , V_146 ) ;
}
static T_4 F_113 ( struct V_44 * V_45 ,
struct V_145 * V_146 )
{
struct V_9 * V_10 = F_20 ( V_45 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_185 * V_186 ;
struct V_187 * V_188 = ( void * ) V_146 -> V_189 ;
if ( V_2 -> V_4 . V_70 < V_72 )
return 0 ;
if ( V_146 -> V_190 < 4 ||
V_146 -> V_190 < F_114 ( V_188 -> V_191 ) + 2 )
return 0 ;
V_186 = ( void * ) ( ( V_192 * ) V_146 -> V_189 + F_114 ( V_188 -> V_191 ) ) ;
return F_115 ( V_10 , V_146 , V_186 ) ;
}
static void F_116 ( struct V_44 * V_45 )
{
F_117 ( V_45 ) ;
V_45 -> V_193 &= ~ V_194 ;
V_45 -> V_195 = & V_196 ;
V_45 -> V_197 = V_198 ;
}
static void F_118 ( struct V_199 * V_164 )
{
struct V_9 * V_10 =
F_44 ( V_164 , struct V_9 , V_164 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_145 * V_146 ;
struct V_98 * V_99 ;
struct V_200 * V_201 ;
if ( ! F_11 ( V_10 ) )
return;
if ( V_2 -> V_13 )
return;
if ( F_119 ( V_2 -> V_202 ,
L_5 ) )
return;
while ( ( V_146 = F_120 ( & V_10 -> V_165 ) ) ) {
struct V_203 * V_204 = ( void * ) V_146 -> V_189 ;
if ( V_146 -> V_205 == V_206 ) {
V_201 = ( void * ) & V_146 -> V_207 ;
F_121 ( & V_10 -> V_21 , V_201 -> V_208 ,
V_201 -> V_209 ) ;
} else if ( V_146 -> V_205 == V_210 ) {
V_201 = ( void * ) & V_146 -> V_207 ;
F_122 ( & V_10 -> V_21 , V_201 -> V_208 ,
V_201 -> V_209 ) ;
} else if ( F_123 ( V_204 -> V_211 ) &&
V_204 -> V_26 . V_212 . V_213 == V_214 ) {
int V_190 = V_146 -> V_190 ;
F_16 ( & V_2 -> V_215 ) ;
V_99 = F_124 ( V_10 , V_204 -> V_54 ) ;
if ( V_99 ) {
switch ( V_204 -> V_26 . V_212 . V_26 . V_216 . V_217 ) {
case V_218 :
F_125 (
V_2 , V_99 , V_204 , V_190 ) ;
break;
case V_219 :
F_126 ( V_2 , V_99 ,
V_204 , V_190 ) ;
break;
case V_220 :
F_127 ( V_10 , V_99 ,
V_204 , V_190 ) ;
break;
default:
F_6 ( 1 ) ;
break;
}
}
F_17 ( & V_2 -> V_215 ) ;
} else if ( F_128 ( V_204 -> V_211 ) ) {
struct V_185 * V_186 = ( void * ) V_204 ;
F_6 ( V_186 -> V_211 &
F_129 ( V_221 ) ) ;
F_6 ( ! ( V_186 -> V_222 &
F_129 ( V_223 ) ) ) ;
F_16 ( & V_2 -> V_215 ) ;
V_99 = F_124 ( V_10 , V_204 -> V_54 ) ;
if ( V_99 ) {
T_4 V_209 = * F_130 ( V_186 ) &
V_224 ;
F_131 (
V_99 , V_209 , V_225 ,
V_226 ,
true ) ;
}
F_17 ( & V_2 -> V_215 ) ;
} else switch ( V_10 -> V_21 . type ) {
case V_25 :
F_132 ( V_10 , V_146 ) ;
break;
case V_31 :
F_133 ( V_10 , V_146 ) ;
break;
case V_48 :
if ( ! F_109 ( & V_10 -> V_21 ) )
break;
F_134 ( V_10 , V_146 ) ;
break;
default:
F_119 ( 1 , L_6 ) ;
break;
}
F_83 ( V_146 ) ;
}
switch ( V_10 -> V_21 . type ) {
case V_25 :
F_135 ( V_10 ) ;
break;
case V_31 :
F_136 ( V_10 ) ;
break;
case V_48 :
if ( ! F_109 ( & V_10 -> V_21 ) )
break;
F_137 ( V_10 ) ;
break;
default:
break;
}
}
static void F_138 ( struct V_9 * V_10 ,
enum V_63 type )
{
memset ( & V_10 -> V_26 , 0 , sizeof( V_10 -> V_26 ) ) ;
V_10 -> V_21 . type = type ;
V_10 -> V_21 . V_227 = false ;
V_10 -> V_45 -> V_195 = & V_196 ;
V_10 -> V_228 . V_64 = type ;
V_10 -> V_110 = F_139 ( V_229 ) ;
V_10 -> V_111 = false ;
V_10 -> V_230 = 0 ;
V_10 -> V_45 -> type = V_231 ;
F_140 ( & V_10 -> V_165 ) ;
F_141 ( & V_10 -> V_164 , F_118 ) ;
switch ( type ) {
case V_115 :
type = V_61 ;
V_10 -> V_21 . type = type ;
V_10 -> V_21 . V_227 = true ;
case V_61 :
F_140 ( & V_10 -> V_26 . V_68 . V_163 ) ;
F_142 ( & V_10 -> V_26 . V_68 . V_109 ) ;
break;
case V_114 :
type = V_25 ;
V_10 -> V_21 . type = type ;
V_10 -> V_21 . V_227 = true ;
case V_25 :
F_143 ( V_10 ) ;
break;
case V_31 :
F_144 ( V_10 ) ;
break;
case V_48 :
if ( F_109 ( & V_10 -> V_21 ) )
F_145 ( V_10 ) ;
break;
case V_38 :
V_10 -> V_45 -> type = V_232 ;
V_10 -> V_45 -> V_195 = & V_233 ;
V_10 -> V_26 . V_78 = V_234 |
V_235 ;
break;
case V_62 :
case V_39 :
break;
case V_112 :
case V_113 :
F_146 () ;
break;
}
F_147 ( V_10 ) ;
}
static void F_148 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_21 . type ) {
case V_48 :
F_149 ( V_10 ) ;
break;
default:
break;
}
}
static int F_150 ( struct V_9 * V_10 ,
enum V_63 type )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_55 , V_143 ;
enum V_63 V_236 = type ;
bool V_227 = false ;
F_25 () ;
if ( ! V_2 -> V_34 -> V_237 )
return - V_56 ;
switch ( V_10 -> V_21 . type ) {
case V_61 :
case V_25 :
case V_31 :
break;
default:
return - V_56 ;
}
switch ( type ) {
case V_61 :
case V_25 :
case V_31 :
break;
case V_114 :
V_227 = true ;
V_236 = V_25 ;
break;
case V_115 :
V_227 = true ;
V_236 = V_61 ;
break;
default:
return - V_56 ;
}
V_55 = F_24 ( V_10 , V_236 ) ;
if ( V_55 )
return V_55 ;
F_67 ( V_10 , false ) ;
F_106 ( V_10 -> V_45 ) ;
V_55 = F_151 ( V_2 , V_10 , V_236 , V_227 ) ;
if ( V_55 )
type = V_10 -> V_21 . type ;
F_27 ( V_10 ) ;
F_138 ( V_10 , type ) ;
V_143 = F_41 ( V_10 -> V_45 , false ) ;
F_119 ( V_143 , L_7 , V_143 ) ;
return V_55 ;
}
int F_152 ( struct V_9 * V_10 ,
enum V_63 type )
{
int V_55 ;
F_25 () ;
if ( type == F_153 ( & V_10 -> V_21 ) )
return 0 ;
if ( V_10 -> V_2 -> V_238 -> V_6 & V_239 &&
type == V_31 )
return - V_240 ;
if ( F_11 ( V_10 ) ) {
V_55 = F_150 ( V_10 , type ) ;
if ( V_55 )
return V_55 ;
} else {
F_106 ( V_10 -> V_45 ) ;
F_138 ( V_10 , type ) ;
}
V_10 -> V_21 . V_22 . V_241 =
F_154 ( V_10 -> V_2 ,
V_10 -> V_2 -> V_4 . V_5 . V_242 -> V_243 ) ;
V_10 -> V_244 = 0 ;
if ( type == V_25 )
V_10 -> V_26 . V_27 . V_245 = false ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
enum V_63 type )
{
struct V_9 * V_10 ;
T_5 V_246 , V_247 , V_52 , V_248 , V_249 ;
V_192 * V_250 ;
V_192 V_251 [ V_58 ] ;
int V_71 ;
memcpy ( V_45 -> V_122 , V_2 -> V_4 . V_96 -> V_122 , V_58 ) ;
if ( F_48 ( V_2 -> V_4 . V_96 -> V_252 ) &&
V_2 -> V_4 . V_96 -> V_253 <= 1 )
return;
F_16 ( & V_2 -> V_19 ) ;
switch ( type ) {
case V_38 :
break;
case V_62 :
case V_39 :
F_10 (sdata, &local->interfaces, list) {
if ( V_10 -> V_21 . type != V_61 )
continue;
memcpy ( V_45 -> V_122 , V_10 -> V_21 . V_52 , V_58 ) ;
break;
}
break;
default:
for ( V_71 = 0 ; V_71 < V_2 -> V_4 . V_96 -> V_253 ; V_71 ++ ) {
bool V_254 = false ;
F_10 (sdata, &local->interfaces, list) {
if ( memcmp ( V_2 -> V_4 . V_96 -> V_255 [ V_71 ] . V_52 ,
V_10 -> V_21 . V_52 , V_58 ) == 0 ) {
V_254 = true ;
break;
}
}
if ( ! V_254 ) {
memcpy ( V_45 -> V_122 ,
V_2 -> V_4 . V_96 -> V_255 [ V_71 ] . V_52 ,
V_58 ) ;
break;
}
}
if ( F_48 ( V_2 -> V_4 . V_96 -> V_252 ) )
break;
V_250 = V_2 -> V_4 . V_96 -> V_252 ;
V_246 = ( ( T_5 ) V_250 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_250 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_250 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_250 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_250 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_250 [ 5 ] << 0 * 8 ) ;
if ( F_156 ( V_246 ) + F_157 ( V_246 ) != F_158 ( V_246 ) ) {
F_159 ( L_8 ) ;
break;
}
V_250 = V_2 -> V_4 . V_96 -> V_122 ;
V_247 = ( ( T_5 ) V_250 [ 0 ] << 5 * 8 ) | ( ( T_5 ) V_250 [ 1 ] << 4 * 8 ) |
( ( T_5 ) V_250 [ 2 ] << 3 * 8 ) | ( ( T_5 ) V_250 [ 3 ] << 2 * 8 ) |
( ( T_5 ) V_250 [ 4 ] << 1 * 8 ) | ( ( T_5 ) V_250 [ 5 ] << 0 * 8 ) ;
V_249 = 1ULL << F_156 ( V_246 ) ;
V_248 = ( V_247 & V_246 ) ;
V_52 = ( V_247 & ~ V_246 ) | ( V_248 & V_246 ) ;
do {
bool V_254 = false ;
V_251 [ 5 ] = V_52 >> 0 * 8 ;
V_251 [ 4 ] = V_52 >> 1 * 8 ;
V_251 [ 3 ] = V_52 >> 2 * 8 ;
V_251 [ 2 ] = V_52 >> 3 * 8 ;
V_251 [ 1 ] = V_52 >> 4 * 8 ;
V_251 [ 0 ] = V_52 >> 5 * 8 ;
V_248 += V_249 ;
F_10 (sdata, &local->interfaces, list) {
if ( memcmp ( V_251 , V_10 -> V_21 . V_52 ,
V_58 ) == 0 ) {
V_254 = true ;
break;
}
}
if ( ! V_254 ) {
memcpy ( V_45 -> V_122 , V_251 , V_58 ) ;
break;
}
V_52 = ( V_247 & ~ V_246 ) | ( V_248 & V_246 ) ;
} while ( V_52 != V_247 );
break;
}
F_17 ( & V_2 -> V_19 ) ;
}
int F_160 ( struct V_1 * V_2 , const char * V_94 ,
struct V_256 * * V_257 , enum V_63 type ,
struct V_258 * V_259 )
{
struct V_44 * V_260 ;
struct V_9 * V_10 = NULL ;
int V_55 , V_71 ;
int V_261 = 1 ;
F_25 () ;
if ( V_2 -> V_4 . V_70 >= V_72 )
V_261 = V_72 ;
V_260 = F_161 ( sizeof( * V_10 ) + V_2 -> V_4 . V_91 ,
V_94 , F_116 , V_261 , 1 ) ;
if ( ! V_260 )
return - V_93 ;
F_162 ( V_260 , F_163 ( V_2 -> V_4 . V_96 ) ) ;
V_260 -> V_262 = V_2 -> V_263 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_264
+ V_265 ;
V_260 -> V_266 = V_267 ;
V_55 = F_164 ( V_260 , V_260 -> V_94 ) ;
if ( V_55 < 0 )
goto V_268;
F_155 ( V_2 , V_260 , type ) ;
memcpy ( V_260 -> V_121 , V_260 -> V_122 , V_58 ) ;
F_165 ( V_260 , F_166 ( V_2 -> V_4 . V_96 ) ) ;
V_10 = F_167 ( V_260 ) ;
V_260 -> V_269 = & V_10 -> V_228 ;
memcpy ( V_10 -> V_21 . V_52 , V_260 -> V_121 , V_58 ) ;
memcpy ( V_10 -> V_94 , V_260 -> V_94 , V_95 ) ;
V_10 -> V_228 . V_96 = V_2 -> V_4 . V_96 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_45 = V_260 ;
#ifdef F_168
V_10 -> V_270 = true ;
#endif
for ( V_71 = 0 ; V_71 < V_181 ; V_71 ++ )
F_140 ( & V_10 -> V_182 [ V_71 ] . V_183 ) ;
F_142 ( & V_10 -> V_271 ) ;
for ( V_71 = 0 ; V_71 < V_272 ; V_71 ++ ) {
struct V_273 * V_274 ;
V_274 = V_2 -> V_4 . V_96 -> V_275 [ V_71 ] ;
V_10 -> V_276 [ V_71 ] =
V_274 ? ( 1 << V_274 -> V_277 ) - 1 : 0 ;
if ( V_274 )
memcpy ( V_10 -> V_278 [ V_71 ] ,
V_274 -> V_279 . V_280 . V_281 ,
sizeof( V_10 -> V_278 [ V_71 ] ) ) ;
else
memset ( V_10 -> V_278 [ V_71 ] , 0 ,
sizeof( V_10 -> V_278 [ V_71 ] ) ) ;
}
F_31 ( V_10 ) ;
F_138 ( V_10 , type ) ;
if ( V_259 ) {
V_260 -> V_269 -> V_245 = V_259 -> V_245 ;
if ( type == V_25 )
V_10 -> V_26 . V_27 . V_245 = V_259 -> V_245 ;
}
V_260 -> V_282 |= V_2 -> V_4 . V_283 ;
V_55 = F_169 ( V_260 ) ;
if ( V_55 )
goto V_268;
F_16 ( & V_2 -> V_19 ) ;
F_170 ( & V_10 -> V_108 , & V_2 -> V_284 ) ;
F_17 ( & V_2 -> V_19 ) ;
if ( V_257 )
* V_257 = & V_10 -> V_228 ;
return 0 ;
V_268:
V_198 ( V_260 ) ;
return V_55 ;
}
void F_171 ( struct V_9 * V_10 )
{
F_25 () ;
F_16 ( & V_10 -> V_2 -> V_19 ) ;
F_172 ( & V_10 -> V_108 ) ;
F_17 ( & V_10 -> V_2 -> V_19 ) ;
F_148 ( V_10 ) ;
F_82 () ;
F_173 ( V_10 -> V_45 ) ;
}
void F_174 ( struct V_1 * V_2 )
{
struct V_9 * V_10 , * V_147 ;
F_175 ( V_285 ) ;
F_25 () ;
F_16 ( & V_2 -> V_19 ) ;
F_84 (sdata, tmp, &local->interfaces, list) {
F_64 ( & V_10 -> V_108 ) ;
F_148 ( V_10 ) ;
F_176 ( V_10 -> V_45 , & V_285 ) ;
}
F_17 ( & V_2 -> V_19 ) ;
F_177 ( & V_285 ) ;
F_64 ( & V_285 ) ;
}
static int F_178 ( struct V_286 * V_287 ,
unsigned long V_135 ,
void * V_260 )
{
struct V_44 * V_45 = V_260 ;
struct V_9 * V_10 ;
if ( V_135 != V_288 )
return 0 ;
if ( ! V_45 -> V_269 || ! V_45 -> V_269 -> V_96 )
return 0 ;
if ( V_45 -> V_269 -> V_96 -> V_289 != V_290 )
return 0 ;
V_10 = F_20 ( V_45 ) ;
memcpy ( V_10 -> V_94 , V_45 -> V_94 , V_95 ) ;
F_179 ( V_10 ) ;
return 0 ;
}
int F_180 ( void )
{
return F_181 ( & V_291 ) ;
}
void F_182 ( void )
{
F_183 ( & V_291 ) ;
}
