bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 () ;
V_4 = F_3 ( V_2 -> V_6 . V_4 ) ;
if ( ! V_4 ) {
F_4 () ;
return false ;
}
V_5 = V_4 -> V_7 . V_8 -> V_9 ;
F_4 () ;
if ( V_2 -> V_10 != V_11 )
V_5 = F_5 ( V_5 , V_2 -> V_10 ) ;
if ( V_2 -> V_12 != V_11 )
V_5 = F_5 ( V_5 , V_2 -> V_12 ) ;
if ( V_5 != V_2 -> V_6 . V_13 . V_14 ) {
V_2 -> V_6 . V_13 . V_14 = V_5 ;
F_6 ( V_2 -> V_15 , 0 ) ;
return true ;
}
return false ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
F_8 ( V_2 , V_16 ) ;
}
static T_1 F_9 ( struct V_17 * V_15 )
{
if ( ! ( V_15 -> V_18 . V_19 . V_20 & V_21 ) )
return 0 ;
V_15 -> V_18 . V_19 . V_20 &= ~ V_21 ;
return V_22 ;
}
static T_1 F_10 ( struct V_17 * V_15 )
{
if ( V_15 -> V_18 . V_19 . V_20 & V_21 )
return 0 ;
F_11 ( V_15 , NULL ) ;
V_15 -> V_18 . V_19 . V_20 |= V_21 ;
return V_22 ;
}
static T_1 F_12 ( struct V_17 * V_15 ,
bool V_23 )
{
bool V_24 = false , V_25 , V_26 ;
unsigned int V_27 = 0 , V_28 = 0 ;
struct V_29 * V_30 ;
F_13 ( & V_15 -> V_31 ) ;
V_26 = V_23 ||
! F_14 ( & V_15 -> V_32 ) ||
V_15 -> V_33 ;
if ( ! V_15 -> V_34 -> V_35 ) {
F_15 (roc, &local->roc_list, list) {
V_24 = true ;
break;
}
}
V_25 = F_16 ( V_36 , & V_15 -> V_25 ) ||
F_16 ( V_37 , & V_15 -> V_25 ) ;
if ( V_24 || V_25 )
V_27 |= V_38 ;
else
V_28 |= V_38 ;
if ( V_26 )
V_27 |= V_39 ;
else
V_28 |= V_39 ;
F_17 ( V_15 , V_27 , V_28 ) ;
if ( V_24 || V_25 || V_26 )
return F_9 ( V_15 ) ;
return F_10 ( V_15 ) ;
}
T_1 F_18 ( struct V_17 * V_15 )
{
return F_12 ( V_15 , true ) ;
}
void F_19 ( struct V_17 * V_15 )
{
T_1 V_40 = F_12 ( V_15 , false ) ;
if ( V_40 )
F_6 ( V_15 , V_40 ) ;
}
static int F_20 ( struct V_41 * V_42 , int V_43 )
{
if ( V_43 < 256 || V_43 > V_44 )
return - V_45 ;
V_42 -> V_46 = V_43 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 * V_47 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_1 * V_48 ;
T_3 V_49 , V_50 , V_51 ;
T_2 * V_52 ;
int V_53 = 0 ;
if ( F_22 ( V_15 -> V_18 . V_54 -> V_55 ) )
return 0 ;
V_52 = V_47 ;
V_49 = ( ( T_3 ) V_52 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_52 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_52 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_52 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_52 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_52 [ 5 ] << 0 * 8 ) ;
V_52 = V_15 -> V_18 . V_54 -> V_55 ;
V_50 = ( ( T_3 ) V_52 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_52 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_52 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_52 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_52 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_52 [ 5 ] << 0 * 8 ) ;
F_23 ( & V_15 -> V_56 ) ;
F_15 (iter, &local->interfaces, list) {
if ( V_48 == V_2 )
continue;
if ( V_48 -> V_6 . type == V_57 )
continue;
V_52 = V_48 -> V_6 . V_47 ;
V_51 = ( ( T_3 ) V_52 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_52 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_52 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_52 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_52 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_52 [ 5 ] << 0 * 8 ) ;
if ( ( V_49 & ~ V_50 ) != ( V_51 & ~ V_50 ) ) {
V_53 = - V_45 ;
break;
}
}
F_24 ( & V_15 -> V_56 ) ;
return V_53 ;
}
static int F_25 ( struct V_41 * V_42 , void * V_47 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_58 * V_59 = V_47 ;
int V_53 ;
if ( F_27 ( V_2 ) )
return - V_60 ;
V_53 = F_21 ( V_2 , V_59 -> V_61 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_28 ( V_42 , V_59 ) ;
if ( V_53 == 0 )
memcpy ( V_2 -> V_6 . V_47 , V_59 -> V_61 , V_62 ) ;
return V_53 ;
}
static inline int F_29 ( int V_63 , int V_64 )
{
return V_63 == V_57 ||
V_64 == V_57 ||
V_63 == V_65 ||
V_64 == V_65 ||
( V_63 == V_66 && V_64 == V_67 ) ||
( V_63 == V_67 &&
( V_64 == V_67 ||
V_64 == V_66 ) ) ||
( V_63 == V_66 && V_64 == V_68 ) ||
( V_63 == V_68 &&
( V_64 == V_66 ||
V_64 == V_68 ) ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_69 V_70 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_1 * V_71 ;
F_31 () ;
F_15 (nsdata, &local->interfaces, list) {
if ( V_71 != V_2 && F_27 ( V_71 ) ) {
if ( V_70 == V_72 &&
V_71 -> V_6 . type == V_72 )
return - V_60 ;
if ( ! F_32 ( V_2 -> V_6 . V_47 ,
V_71 -> V_6 . V_47 ) )
continue;
if ( ! F_29 ( V_70 ,
V_71 -> V_6 . type ) )
return - V_73 ;
if ( V_70 == V_68 &&
V_71 -> V_6 . type == V_66 )
V_2 -> V_74 = & V_71 -> V_75 . V_76 ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_77 = V_2 -> V_15 -> V_18 . V_78 ;
int V_79 ;
if ( V_2 -> V_6 . type != V_65 ) {
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
if ( F_34 ( V_2 -> V_6 . V_81 [ V_79 ] ==
V_82 ) )
return - V_45 ;
if ( F_34 ( V_2 -> V_6 . V_81 [ V_79 ] >=
V_77 ) )
return - V_45 ;
}
}
if ( ( V_2 -> V_6 . type != V_66 &&
V_2 -> V_6 . type != V_83 ) ||
! ( V_2 -> V_15 -> V_18 . V_20 & V_84 ) ) {
V_2 -> V_6 . V_85 = V_82 ;
return 0 ;
}
if ( F_34 ( V_2 -> V_6 . V_85 == V_82 ) )
return - V_45 ;
if ( F_34 ( V_2 -> V_6 . V_85 >= V_77 ) )
return - V_45 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
const int V_86 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
T_1 V_20 = V_2 -> V_75 . V_87 ;
#define F_36 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_36 ( V_88 , V_89 ) ;
F_36 ( V_90 , V_91 ) ;
F_36 ( V_92 , V_93 ) ;
F_36 ( V_92 , V_94 ) ;
F_36 ( V_95 , V_96 ) ;
#undef F_36
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
if ( V_15 -> V_18 . V_20 & V_84 )
V_2 -> V_6 . V_81 [ V_79 ] = V_82 ;
else if ( V_15 -> V_18 . V_78 >= V_80 )
V_2 -> V_6 . V_81 [ V_79 ] = V_79 ;
else
V_2 -> V_6 . V_81 [ V_79 ] = 0 ;
}
V_2 -> V_6 . V_85 = V_82 ;
}
int F_38 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
int V_53 ;
if ( ! ( V_15 -> V_18 . V_20 & V_97 ) )
return 0 ;
F_31 () ;
if ( V_15 -> V_98 )
return 0 ;
V_2 = F_39 ( sizeof( * V_2 ) + V_15 -> V_18 . V_99 , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_6 . type = V_57 ;
snprintf ( V_2 -> V_102 , V_103 , L_1 ,
F_40 ( V_15 -> V_18 . V_54 ) ) ;
F_37 ( V_2 ) ;
V_53 = F_41 ( V_15 , V_2 ) ;
if ( F_42 ( V_53 ) ) {
F_43 ( V_2 ) ;
return V_53 ;
}
V_53 = F_33 ( V_2 ) ;
if ( V_53 ) {
F_43 ( V_2 ) ;
return V_53 ;
}
V_53 = F_44 ( V_2 , & V_15 -> V_104 ,
V_105 ) ;
if ( V_53 ) {
F_45 ( V_15 , V_2 ) ;
F_43 ( V_2 ) ;
return V_53 ;
}
F_23 ( & V_15 -> V_56 ) ;
F_46 ( V_15 -> V_98 , V_2 ) ;
F_24 ( & V_15 -> V_56 ) ;
return 0 ;
}
void F_47 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
if ( ! ( V_15 -> V_18 . V_20 & V_97 ) )
return;
F_31 () ;
F_23 ( & V_15 -> V_56 ) ;
V_2 = F_48 ( V_15 -> V_98 ,
F_49 ( & V_15 -> V_56 ) ) ;
if ( ! V_2 ) {
F_24 ( & V_15 -> V_56 ) ;
return;
}
F_46 ( V_15 -> V_98 , NULL ) ;
F_24 ( & V_15 -> V_56 ) ;
F_50 () ;
F_51 ( V_2 ) ;
F_45 ( V_15 , V_2 ) ;
F_43 ( V_2 ) ;
}
int F_52 ( struct V_106 * V_107 , bool V_108 )
{
struct V_1 * V_2 = F_53 ( V_107 ) ;
struct V_41 * V_42 = V_107 -> V_109 ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_110 * V_111 ;
T_1 V_112 = 0 ;
int V_113 ;
T_1 V_114 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_67 :
if ( ! F_54 ( V_2 -> V_75 . V_115 . V_116 ) )
return - V_117 ;
break;
case V_68 : {
struct V_1 * V_118 ;
if ( ! V_2 -> V_74 )
return - V_117 ;
F_55 ( & V_2 -> V_75 . V_119 . V_120 , & V_2 -> V_74 -> V_121 ) ;
V_118 = F_56 ( V_2 -> V_74 ,
struct V_1 , V_75 . V_76 ) ;
V_2 -> V_122 =
V_118 -> V_122 ;
V_2 -> V_123 =
V_118 -> V_123 ;
V_2 -> V_6 . V_85 = V_118 -> V_6 . V_85 ;
memcpy ( V_2 -> V_6 . V_81 , V_118 -> V_6 . V_81 ,
sizeof( V_2 -> V_6 . V_81 ) ) ;
break;
}
case V_66 :
V_2 -> V_74 = & V_2 -> V_75 . V_76 ;
break;
case V_83 :
case V_124 :
case V_57 :
case V_72 :
case V_65 :
break;
case V_125 :
case V_126 :
case V_127 :
case V_128 :
F_42 ( 1 ) ;
break;
}
if ( V_15 -> V_129 == 0 ) {
V_113 = F_57 ( V_15 ) ;
if ( V_113 )
goto V_130;
V_114 = ~ 0 ;
F_58 ( V_15 , true ) ;
F_17 ( V_15 ,
V_131 , 0 ) ;
}
if ( V_42 && F_22 ( V_42 -> V_132 ) ) {
memcpy ( V_42 -> V_132 ,
V_15 -> V_18 . V_54 -> V_133 ,
V_62 ) ;
memcpy ( V_42 -> V_133 , V_42 -> V_132 , V_62 ) ;
if ( ! F_54 ( V_42 -> V_132 ) ) {
V_113 = - V_134 ;
goto V_135;
}
}
switch ( V_2 -> V_6 . type ) {
case V_68 :
if ( F_59 ( V_2 -> V_74 -> V_136 ) ) {
F_60 ( V_2 ) ;
F_61 ( V_42 ) ;
} else {
F_62 ( V_42 ) ;
}
break;
case V_57 :
if ( V_2 -> V_75 . V_87 & V_137 ) {
V_15 -> V_138 ++ ;
break;
}
if ( V_15 -> V_33 == 0 && V_15 -> V_129 == 0 ) {
V_113 = F_38 ( V_15 ) ;
if ( V_113 )
goto V_135;
}
V_15 -> V_33 ++ ;
if ( V_15 -> V_33 == 1 ) {
V_15 -> V_18 . V_19 . V_20 |= V_139 ;
V_114 |= V_140 ;
}
F_35 ( V_2 , 1 ) ;
F_63 ( V_15 ) ;
F_23 ( & V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
F_24 ( & V_15 -> V_31 ) ;
F_61 ( V_42 ) ;
break;
default:
if ( V_108 ) {
F_47 ( V_15 ) ;
V_113 = F_41 ( V_15 , V_2 ) ;
if ( V_113 )
goto V_135;
V_113 = F_33 ( V_2 ) ;
if ( V_113 )
goto V_141;
}
if ( V_2 -> V_6 . type == V_66 ) {
V_15 -> V_142 ++ ;
V_15 -> V_143 ++ ;
F_63 ( V_15 ) ;
} else if ( V_2 -> V_6 . type == V_72 ) {
V_15 -> V_143 ++ ;
}
if ( V_2 -> V_6 . type != V_65 )
V_112 |= F_64 ( V_2 ) ;
F_8 ( V_2 , V_112 ) ;
switch ( V_2 -> V_6 . type ) {
case V_124 :
case V_72 :
case V_66 :
case V_83 :
F_62 ( V_42 ) ;
break;
case V_67 :
case V_65 :
break;
default:
F_42 ( 1 ) ;
}
F_65 ( V_2 , true ) ;
}
F_66 ( V_144 , & V_2 -> V_145 ) ;
if ( V_2 -> V_6 . type == V_67 ) {
V_111 = F_67 ( V_2 , V_2 -> V_75 . V_115 . V_116 ,
V_100 ) ;
if ( ! V_111 ) {
V_113 = - V_101 ;
goto V_141;
}
F_68 ( V_111 , V_146 ) ;
F_68 ( V_111 , V_147 ) ;
F_68 ( V_111 , V_148 ) ;
V_113 = F_69 ( V_111 ) ;
if ( V_113 ) {
goto V_141;
}
F_70 ( V_111 ) ;
F_61 ( V_42 ) ;
} else if ( V_2 -> V_6 . type == V_65 ) {
F_46 ( V_15 -> V_149 , V_2 ) ;
}
if ( V_2 -> V_20 & V_150 )
F_71 ( & V_15 -> V_151 ) ;
if ( V_2 -> V_20 & V_152 )
F_71 ( & V_15 -> V_153 ) ;
if ( V_108 )
V_15 -> V_129 ++ ;
if ( V_114 )
F_6 ( V_15 , V_114 ) ;
F_72 ( V_15 , - 1 ) ;
if ( V_2 -> V_6 . type == V_57 ||
V_2 -> V_6 . type == V_68 ) {
F_73 ( V_42 ) ;
} else if ( V_42 ) {
unsigned long V_20 ;
int V_154 = V_80 ;
int V_155 ;
if ( V_15 -> V_18 . V_78 < V_80 )
V_154 = 1 ;
F_74 ( & V_15 -> V_156 , V_20 ) ;
if ( V_2 -> V_6 . V_85 == V_82 ||
( V_15 -> V_157 [ V_2 -> V_6 . V_85 ] == 0 &&
F_75 ( & V_15 -> V_158 [ V_2 -> V_6 . V_85 ] ) ) ) {
for ( V_155 = 0 ; V_155 < V_154 ; V_155 ++ ) {
int V_159 = V_2 -> V_6 . V_81 [ V_155 ] ;
if ( V_15 -> V_157 [ V_159 ] == 0 &&
F_75 ( & V_15 -> V_158 [ V_159 ] ) )
F_76 ( V_42 , V_155 ) ;
}
}
F_77 ( & V_15 -> V_156 , V_20 ) ;
}
return 0 ;
V_141:
F_45 ( V_15 , V_2 ) ;
V_135:
if ( ! V_15 -> V_129 )
F_78 ( V_15 ) ;
V_130:
V_2 -> V_74 = NULL ;
if ( V_2 -> V_6 . type == V_68 )
F_79 ( & V_2 -> V_75 . V_119 . V_120 ) ;
F_80 ( V_144 , & V_2 -> V_145 ) ;
return V_113 ;
}
static int F_81 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
int V_160 ;
if ( ! F_54 ( V_42 -> V_132 ) )
return - V_134 ;
V_160 = F_30 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_160 )
return V_160 ;
return F_52 ( & V_2 -> V_107 , true ) ;
}
static void F_82 ( struct V_1 * V_2 ,
bool V_161 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
unsigned long V_20 ;
struct V_162 * V_163 , * V_51 ;
T_1 V_114 = 0 ;
int V_79 , V_164 ;
struct V_165 * V_166 ;
F_80 ( V_144 , & V_2 -> V_145 ) ;
if ( F_83 ( V_15 -> V_167 ) == V_2 )
F_84 ( V_15 ) ;
if ( V_2 -> V_42 )
F_85 ( V_2 -> V_42 ) ;
F_86 ( V_15 , V_2 ) ;
if ( V_2 -> V_6 . type == V_124 )
F_87 ( V_2 ) ;
V_164 = F_88 ( V_2 ) ;
F_34 ( ( V_2 -> V_6 . type != V_67 && V_164 > 0 ) ||
( V_2 -> V_6 . type == V_67 && V_164 != 1 ) ) ;
if ( V_2 -> V_20 & V_150 )
F_89 ( & V_15 -> V_151 ) ;
if ( V_2 -> V_20 & V_152 )
F_89 ( & V_15 -> V_153 ) ;
if ( V_2 -> V_6 . type == V_66 ) {
V_15 -> V_142 -- ;
V_15 -> V_143 -- ;
} else if ( V_2 -> V_6 . type == V_72 ) {
V_15 -> V_143 -- ;
}
if ( V_2 -> V_42 ) {
F_90 ( V_2 -> V_42 ) ;
F_91 ( & V_15 -> V_168 ) ;
F_92 ( & V_15 -> V_169 , & V_2 -> V_42 -> V_170 ,
V_2 -> V_42 -> V_171 ) ;
F_93 ( & V_15 -> V_168 ) ;
F_94 ( V_2 -> V_42 ) ;
}
F_95 ( & V_15 -> V_172 ) ;
F_96 ( & V_15 -> V_173 ) ;
F_96 ( & V_2 -> V_174 ) ;
F_97 ( & V_2 -> V_175 ) ;
if ( V_2 -> V_107 . V_176 ) {
F_42 ( V_15 -> V_177 ) ;
F_23 ( & V_15 -> V_56 ) ;
F_51 ( V_2 ) ;
F_24 ( & V_15 -> V_56 ) ;
F_98 ( V_2 -> V_42 , V_178 ,
V_100 ) ;
}
if ( V_2 -> V_6 . type == V_66 ) {
struct V_1 * V_119 , * V_179 ;
F_99 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_100 ( V_119 -> V_42 ) ;
F_42 ( ! F_14 ( & V_2 -> V_75 . V_76 . V_121 ) ) ;
} else if ( V_2 -> V_6 . type == V_68 ) {
V_166 = & V_2 -> V_74 -> V_166 ;
F_74 ( & V_166 -> V_180 . V_181 , V_20 ) ;
F_101 (&ps->bc_buf, skb, tmp) {
if ( V_163 -> V_42 == V_2 -> V_42 ) {
F_102 ( V_163 , & V_166 -> V_180 ) ;
V_15 -> V_182 -- ;
F_103 ( & V_15 -> V_18 , V_163 ) ;
}
}
F_77 ( & V_166 -> V_180 . V_181 , V_20 ) ;
}
if ( V_161 )
V_15 -> V_129 -- ;
switch ( V_2 -> V_6 . type ) {
case V_68 :
F_79 ( & V_2 -> V_75 . V_119 . V_120 ) ;
F_46 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_57 :
if ( V_2 -> V_75 . V_87 & V_137 ) {
V_15 -> V_138 -- ;
break;
}
V_15 -> V_33 -- ;
if ( V_15 -> V_33 == 0 ) {
V_15 -> V_18 . V_19 . V_20 &= ~ V_139 ;
V_114 |= V_140 ;
}
F_35 ( V_2 , - 1 ) ;
break;
case V_65 :
F_46 ( V_15 -> V_149 , NULL ) ;
default:
F_96 ( & V_2 -> V_183 ) ;
F_104 () ;
F_105 () ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
case V_66 :
F_108 ( & V_2 -> V_184 ) ;
}
V_2 -> V_74 = NULL ;
F_74 ( & V_15 -> V_156 , V_20 ) ;
for ( V_79 = 0 ; V_79 < V_185 ; V_79 ++ ) {
F_101 (&local->pending[i], skb, tmp) {
struct V_186 * V_187 = F_109 ( V_163 ) ;
if ( V_187 -> V_93 . V_6 == & V_2 -> V_6 ) {
F_102 ( V_163 , & V_15 -> V_158 [ V_79 ] ) ;
F_103 ( & V_15 -> V_18 , V_163 ) ;
}
}
}
F_77 ( & V_15 -> V_156 , V_20 ) ;
if ( V_15 -> V_129 == 0 )
F_110 ( V_15 ) ;
if ( V_15 -> V_177 ) {
F_42 ( V_15 -> V_188 ) ;
F_42 ( F_59 ( V_15 -> V_98 ) ) ;
return;
}
switch ( V_2 -> V_6 . type ) {
case V_68 :
break;
case V_57 :
if ( V_15 -> V_33 == 0 )
F_47 ( V_15 ) ;
F_23 ( & V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
F_24 ( & V_15 -> V_31 ) ;
break;
default:
if ( V_161 )
F_45 ( V_15 , V_2 ) ;
}
F_72 ( V_15 , - 1 ) ;
if ( V_15 -> V_129 == 0 ) {
F_111 ( V_15 ) ;
return;
}
F_63 ( V_15 ) ;
F_6 ( V_15 , V_114 ) ;
if ( V_15 -> V_33 == V_15 -> V_129 )
F_38 ( V_15 ) ;
}
static int F_112 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
F_82 ( V_2 , true ) ;
return 0 ;
}
static void F_113 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
int V_189 , V_190 , V_191 , V_192 ;
V_189 = ! ! ( V_42 -> V_20 & V_193 ) ;
V_190 = ! ! ( V_42 -> V_20 & V_194 ) ;
V_191 = ! ! ( V_2 -> V_20 & V_150 ) ;
V_192 = ! ! ( V_2 -> V_20 & V_152 ) ;
if ( V_189 != V_191 ) {
if ( V_42 -> V_20 & V_193 )
F_71 ( & V_15 -> V_151 ) ;
else
F_89 ( & V_15 -> V_151 ) ;
V_2 -> V_20 ^= V_150 ;
}
if ( V_190 != V_192 ) {
if ( V_42 -> V_20 & V_194 )
F_71 ( & V_15 -> V_153 ) ;
else
F_89 ( & V_15 -> V_153 ) ;
V_2 -> V_20 ^= V_152 ;
}
if ( V_2 -> V_6 . type != V_57 &&
V_2 -> V_6 . type != V_68 &&
V_2 -> V_6 . type != V_66 )
F_114 ( V_15 , V_2 , & V_42 -> V_170 ) ;
F_91 ( & V_15 -> V_168 ) ;
F_115 ( & V_15 -> V_169 , & V_42 -> V_170 , V_42 -> V_171 ) ;
F_93 ( & V_15 -> V_168 ) ;
F_116 ( & V_15 -> V_18 , & V_15 -> V_195 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_164 ;
int V_79 ;
F_107 ( V_2 ) ;
F_118 ( V_2 ) ;
for ( V_79 = 0 ; V_79 < V_196 ; V_79 ++ )
F_119 ( & V_2 -> V_197 [ V_79 ] . V_198 ) ;
V_2 -> V_199 = 0 ;
if ( F_120 ( & V_2 -> V_6 ) )
F_121 ( V_2 ) ;
V_164 = F_122 ( V_2 ) ;
F_42 ( V_164 ) ;
}
static void F_123 ( struct V_41 * V_42 )
{
F_117 ( F_26 ( V_42 ) ) ;
}
static T_6 F_124 ( struct V_41 * V_42 ,
struct V_162 * V_163 )
{
return F_125 ( F_26 ( V_42 ) , V_163 ) ;
}
static T_6 F_126 ( struct V_41 * V_42 ,
struct V_162 * V_163 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_200 * V_201 ;
struct V_202 * V_203 = ( void * ) V_163 -> V_204 ;
if ( V_15 -> V_18 . V_78 < V_80 )
return 0 ;
if ( V_163 -> V_205 < 4 ||
V_163 -> V_205 < F_127 ( V_203 -> V_206 ) + 2 )
return 0 ;
V_201 = ( void * ) ( ( T_2 * ) V_163 -> V_204 + F_127 ( V_203 -> V_206 ) ) ;
return F_128 ( V_2 , V_163 , V_201 ) ;
}
static void F_129 ( struct V_41 * V_42 )
{
F_130 ( V_42 ) ;
V_42 -> V_207 &= ~ V_208 ;
V_42 -> V_209 = & V_210 ;
V_42 -> V_211 = V_212 ;
}
static void F_131 ( struct V_213 * V_183 )
{
struct V_1 * V_2 =
F_56 ( V_183 , struct V_1 , V_183 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_162 * V_163 ;
struct V_110 * V_111 ;
struct V_214 * V_215 ;
if ( ! F_27 ( V_2 ) )
return;
if ( V_15 -> V_25 )
return;
if ( F_132 ( V_15 -> V_177 ,
L_2 ) )
return;
while ( ( V_163 = F_133 ( & V_2 -> V_184 ) ) ) {
struct V_216 * V_217 = ( void * ) V_163 -> V_204 ;
if ( V_163 -> V_218 == V_219 ) {
V_215 = ( void * ) & V_163 -> V_220 ;
F_134 ( & V_2 -> V_6 , V_215 -> V_221 ,
V_215 -> V_222 ) ;
} else if ( V_163 -> V_218 == V_223 ) {
V_215 = ( void * ) & V_163 -> V_220 ;
F_135 ( & V_2 -> V_6 , V_215 -> V_221 ,
V_215 -> V_222 ) ;
} else if ( F_136 ( V_217 -> V_224 ) &&
V_217 -> V_75 . V_225 . V_226 == V_227 ) {
int V_205 = V_163 -> V_205 ;
F_23 ( & V_15 -> V_228 ) ;
V_111 = F_137 ( V_2 , V_217 -> V_59 ) ;
if ( V_111 ) {
switch ( V_217 -> V_75 . V_225 . V_75 . V_229 . V_230 ) {
case V_231 :
F_138 (
V_15 , V_111 , V_217 , V_205 ) ;
break;
case V_232 :
F_139 ( V_15 , V_111 ,
V_217 , V_205 ) ;
break;
case V_233 :
F_140 ( V_2 , V_111 ,
V_217 , V_205 ) ;
break;
default:
F_42 ( 1 ) ;
break;
}
}
F_24 ( & V_15 -> V_228 ) ;
} else if ( F_141 ( V_217 -> V_224 ) ) {
struct V_200 * V_201 = ( void * ) V_217 ;
F_42 ( V_201 -> V_224 &
F_142 ( V_234 ) ) ;
F_42 ( ! ( V_201 -> V_235 &
F_142 ( V_236 ) ) ) ;
F_23 ( & V_15 -> V_228 ) ;
V_111 = F_137 ( V_2 , V_217 -> V_59 ) ;
if ( V_111 ) {
T_6 V_222 = * F_143 ( V_201 ) &
V_237 ;
F_144 (
V_111 , V_222 , V_238 ,
V_239 ,
true ) ;
}
F_24 ( & V_15 -> V_228 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_124 :
F_145 ( V_2 , V_163 ) ;
break;
case V_72 :
F_146 ( V_2 , V_163 ) ;
break;
case V_83 :
if ( ! F_120 ( & V_2 -> V_6 ) )
break;
F_147 ( V_2 , V_163 ) ;
break;
default:
F_132 ( 1 , L_3 ) ;
break;
}
F_148 ( V_163 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_124 :
F_149 ( V_2 ) ;
break;
case V_72 :
F_150 ( V_2 ) ;
break;
case V_83 :
if ( ! F_120 ( & V_2 -> V_6 ) )
break;
F_151 ( V_2 ) ;
break;
default:
break;
}
}
static void F_152 ( struct V_213 * V_183 )
{
struct V_1 * V_2 =
F_56 ( V_183 , struct V_1 , V_174 ) ;
F_153 ( V_2 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
enum V_69 type )
{
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_240 = false ;
V_2 -> V_107 . V_70 = type ;
V_2 -> V_122 = F_155 ( V_241 ) ;
V_2 -> V_123 = false ;
V_2 -> V_242 = 0 ;
if ( V_2 -> V_42 ) {
V_2 -> V_42 -> V_209 = & V_210 ;
V_2 -> V_42 -> type = V_243 ;
}
F_156 ( & V_2 -> V_184 ) ;
F_157 ( & V_2 -> V_183 , F_131 ) ;
F_157 ( & V_2 -> V_174 , F_152 ) ;
switch ( type ) {
case V_128 :
type = V_66 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_240 = true ;
case V_66 :
F_156 ( & V_2 -> V_75 . V_76 . V_166 . V_180 ) ;
F_158 ( & V_2 -> V_75 . V_76 . V_121 ) ;
V_2 -> V_6 . V_13 . V_244 = V_2 -> V_6 . V_47 ;
break;
case V_127 :
type = V_124 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_240 = true ;
case V_124 :
V_2 -> V_6 . V_13 . V_244 = V_2 -> V_75 . V_245 . V_244 ;
F_159 ( V_2 ) ;
break;
case V_72 :
V_2 -> V_6 . V_13 . V_244 = V_2 -> V_75 . V_246 . V_244 ;
F_160 ( V_2 ) ;
break;
case V_83 :
if ( F_120 ( & V_2 -> V_6 ) )
F_161 ( V_2 ) ;
break;
case V_57 :
V_2 -> V_42 -> type = V_247 ;
V_2 -> V_42 -> V_209 = & V_248 ;
V_2 -> V_75 . V_87 = V_249 |
V_250 ;
break;
case V_67 :
V_2 -> V_6 . V_13 . V_244 = NULL ;
break;
case V_68 :
break;
case V_65 :
V_2 -> V_6 . V_13 . V_244 = V_2 -> V_6 . V_47 ;
break;
case V_125 :
case V_126 :
F_162 () ;
break;
}
F_163 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
enum V_69 type )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_53 , V_160 ;
enum V_69 V_251 = type ;
bool V_240 = false ;
F_31 () ;
if ( ! V_15 -> V_34 -> V_252 )
return - V_60 ;
switch ( V_2 -> V_6 . type ) {
case V_66 :
case V_124 :
case V_72 :
break;
default:
return - V_60 ;
}
switch ( type ) {
case V_66 :
case V_124 :
case V_72 :
break;
case V_127 :
V_240 = true ;
V_251 = V_124 ;
break;
case V_128 :
V_240 = true ;
V_251 = V_66 ;
break;
default:
return - V_60 ;
}
V_53 = F_30 ( V_2 , V_251 ) ;
if ( V_53 )
return V_53 ;
F_82 ( V_2 , false ) ;
F_117 ( V_2 ) ;
V_53 = F_165 ( V_15 , V_2 , V_251 , V_240 ) ;
if ( V_53 )
type = V_2 -> V_6 . type ;
F_33 ( V_2 ) ;
F_154 ( V_2 , type ) ;
V_160 = F_52 ( & V_2 -> V_107 , false ) ;
F_132 ( V_160 , L_4 , V_160 ) ;
return V_53 ;
}
int F_166 ( struct V_1 * V_2 ,
enum V_69 type )
{
int V_53 ;
F_31 () ;
if ( type == F_167 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_27 ( V_2 ) ) {
V_53 = F_164 ( V_2 , type ) ;
if ( V_53 )
return V_53 ;
} else {
F_117 ( V_2 ) ;
F_154 ( V_2 , type ) ;
}
V_2 -> V_253 = 0 ;
if ( type == V_124 )
V_2 -> V_75 . V_245 . V_254 = false ;
return 0 ;
}
static void F_168 ( struct V_17 * V_15 ,
T_2 * V_133 , enum V_69 type )
{
struct V_1 * V_2 ;
T_3 V_50 , V_255 , V_47 , V_256 , V_257 ;
T_2 * V_52 ;
T_2 V_258 [ V_62 ] ;
int V_79 ;
memcpy ( V_133 , V_15 -> V_18 . V_54 -> V_133 , V_62 ) ;
if ( F_22 ( V_15 -> V_18 . V_54 -> V_55 ) &&
V_15 -> V_18 . V_54 -> V_259 <= 1 )
return;
F_23 ( & V_15 -> V_56 ) ;
switch ( type ) {
case V_57 :
break;
case V_67 :
case V_68 :
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_66 )
continue;
memcpy ( V_133 , V_2 -> V_6 . V_47 , V_62 ) ;
break;
}
break;
case V_127 :
case V_128 :
if ( V_15 -> V_18 . V_20 & V_260 ) {
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_65 )
continue;
if ( ! F_27 ( V_2 ) )
continue;
memcpy ( V_133 , V_2 -> V_6 . V_47 , V_62 ) ;
goto V_261;
}
}
default:
for ( V_79 = 0 ; V_79 < V_15 -> V_18 . V_54 -> V_259 ; V_79 ++ ) {
bool V_262 = false ;
F_15 (sdata, &local->interfaces, list) {
if ( memcmp ( V_15 -> V_18 . V_54 -> V_263 [ V_79 ] . V_47 ,
V_2 -> V_6 . V_47 , V_62 ) == 0 ) {
V_262 = true ;
break;
}
}
if ( ! V_262 ) {
memcpy ( V_133 ,
V_15 -> V_18 . V_54 -> V_263 [ V_79 ] . V_47 ,
V_62 ) ;
break;
}
}
if ( F_22 ( V_15 -> V_18 . V_54 -> V_55 ) )
break;
V_52 = V_15 -> V_18 . V_54 -> V_55 ;
V_50 = ( ( T_3 ) V_52 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_52 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_52 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_52 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_52 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_52 [ 5 ] << 0 * 8 ) ;
if ( F_169 ( V_50 ) + F_170 ( V_50 ) != F_171 ( V_50 ) ) {
F_172 ( L_5 ) ;
break;
}
V_52 = V_15 -> V_18 . V_54 -> V_133 ;
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_57 )
continue;
V_52 = V_2 -> V_6 . V_47 ;
break;
}
V_255 = ( ( T_3 ) V_52 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_52 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_52 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_52 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_52 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_52 [ 5 ] << 0 * 8 ) ;
V_257 = 1ULL << F_169 ( V_50 ) ;
V_256 = ( V_255 & V_50 ) ;
V_47 = ( V_255 & ~ V_50 ) | ( V_256 & V_50 ) ;
do {
bool V_262 = false ;
V_258 [ 5 ] = V_47 >> 0 * 8 ;
V_258 [ 4 ] = V_47 >> 1 * 8 ;
V_258 [ 3 ] = V_47 >> 2 * 8 ;
V_258 [ 2 ] = V_47 >> 3 * 8 ;
V_258 [ 1 ] = V_47 >> 4 * 8 ;
V_258 [ 0 ] = V_47 >> 5 * 8 ;
V_256 += V_257 ;
F_15 (sdata, &local->interfaces, list) {
if ( memcmp ( V_258 , V_2 -> V_6 . V_47 ,
V_62 ) == 0 ) {
V_262 = true ;
break;
}
}
if ( ! V_262 ) {
memcpy ( V_133 , V_258 , V_62 ) ;
break;
}
V_47 = ( V_255 & ~ V_50 ) | ( V_256 & V_50 ) ;
} while ( V_47 != V_255 );
break;
}
V_261:
F_24 ( & V_15 -> V_56 ) ;
}
static void F_173 ( struct V_213 * V_264 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_264 , struct V_1 , V_265 ) ;
F_174 ( V_2 ) ;
}
int F_175 ( struct V_17 * V_15 , const char * V_102 ,
struct V_106 * * V_266 , enum V_69 type ,
struct V_267 * V_268 )
{
struct V_41 * V_269 = NULL ;
struct V_1 * V_2 = NULL ;
int V_53 , V_79 ;
int V_270 = 1 ;
F_31 () ;
if ( type == V_65 ) {
struct V_106 * V_107 ;
V_2 = F_39 ( sizeof( * V_2 ) + V_15 -> V_18 . V_99 ,
V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_107 = & V_2 -> V_107 ;
V_2 -> V_42 = NULL ;
F_176 ( V_2 -> V_102 , V_102 , V_103 ) ;
F_168 ( V_15 , V_107 -> V_271 , type ) ;
memcpy ( V_2 -> V_6 . V_47 , V_107 -> V_271 , V_62 ) ;
} else {
if ( V_15 -> V_18 . V_78 >= V_80 )
V_270 = V_80 ;
V_269 = F_177 ( sizeof( * V_2 ) +
V_15 -> V_18 . V_99 ,
V_102 , F_129 , V_270 , 1 ) ;
if ( ! V_269 )
return - V_101 ;
F_178 ( V_269 , F_179 ( V_15 -> V_18 . V_54 ) ) ;
V_269 -> V_272 = V_15 -> V_273 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_274
+ V_275 ;
V_269 -> V_276 = V_277 ;
V_53 = F_180 ( V_269 , V_269 -> V_102 ) ;
if ( V_53 < 0 ) {
V_212 ( V_269 ) ;
return V_53 ;
}
F_168 ( V_15 , V_269 -> V_133 , type ) ;
memcpy ( V_269 -> V_132 , V_269 -> V_133 , V_62 ) ;
F_181 ( V_269 , F_182 ( V_15 -> V_18 . V_54 ) ) ;
V_2 = F_183 ( V_269 ) ;
V_269 -> V_278 = & V_2 -> V_107 ;
memcpy ( V_2 -> V_6 . V_47 , V_269 -> V_132 , V_62 ) ;
memcpy ( V_2 -> V_102 , V_269 -> V_102 , V_103 ) ;
V_2 -> V_42 = V_269 ;
}
V_2 -> V_107 . V_54 = V_15 -> V_18 . V_54 ;
V_2 -> V_15 = V_15 ;
for ( V_79 = 0 ; V_79 < V_196 ; V_79 ++ )
F_156 ( & V_2 -> V_197 [ V_79 ] . V_198 ) ;
F_158 ( & V_2 -> V_279 ) ;
F_184 ( & V_2 -> V_280 ) ;
F_158 ( & V_2 -> V_281 ) ;
F_157 ( & V_2 -> V_265 , F_173 ) ;
F_185 ( & V_2 -> V_175 ,
V_282 ) ;
F_185 ( & V_2 -> V_283 ,
V_284 ) ;
for ( V_79 = 0 ; V_79 < V_285 ; V_79 ++ ) {
struct V_286 * V_287 ;
V_287 = V_15 -> V_18 . V_54 -> V_288 [ V_79 ] ;
V_2 -> V_289 [ V_79 ] =
V_287 ? ( 1 << V_287 -> V_290 ) - 1 : 0 ;
if ( V_287 )
memcpy ( V_2 -> V_291 [ V_79 ] ,
V_287 -> V_292 . V_293 . V_294 ,
sizeof( V_2 -> V_291 [ V_79 ] ) ) ;
else
memset ( V_2 -> V_291 [ V_79 ] , 0 ,
sizeof( V_2 -> V_291 [ V_79 ] ) ) ;
}
F_37 ( V_2 ) ;
V_2 -> V_12 = V_11 ;
V_2 -> V_10 = V_15 -> V_10 ;
F_154 ( V_2 , type ) ;
if ( V_269 ) {
if ( V_268 ) {
V_269 -> V_278 -> V_254 = V_268 -> V_254 ;
if ( type == V_124 )
V_2 -> V_75 . V_245 . V_254 = V_268 -> V_254 ;
}
V_269 -> V_295 |= V_15 -> V_18 . V_296 ;
V_53 = F_186 ( V_269 ) ;
if ( V_53 ) {
V_212 ( V_269 ) ;
return V_53 ;
}
}
F_23 ( & V_15 -> V_56 ) ;
F_187 ( & V_2 -> V_120 , & V_15 -> V_297 ) ;
F_24 ( & V_15 -> V_56 ) ;
if ( V_266 )
* V_266 = & V_2 -> V_107 ;
return 0 ;
}
void F_188 ( struct V_1 * V_2 )
{
F_31 () ;
F_23 ( & V_2 -> V_15 -> V_56 ) ;
F_189 ( & V_2 -> V_120 ) ;
F_24 ( & V_2 -> V_15 -> V_56 ) ;
F_104 () ;
if ( V_2 -> V_42 ) {
F_190 ( V_2 -> V_42 ) ;
} else {
F_191 ( & V_2 -> V_107 ) ;
F_43 ( V_2 ) ;
}
}
void F_192 ( struct V_1 * V_2 )
{
if ( F_34 ( ! F_16 ( V_144 , & V_2 -> V_145 ) ) )
return;
F_82 ( V_2 , true ) ;
F_117 ( V_2 ) ;
}
void F_193 ( struct V_17 * V_15 )
{
struct V_1 * V_2 , * V_51 ;
F_194 ( V_298 ) ;
F_194 ( V_299 ) ;
F_31 () ;
F_15 (sdata, &local->interfaces, list)
if ( V_2 -> V_6 . type == V_68 )
F_100 ( V_2 -> V_42 ) ;
F_23 ( & V_15 -> V_56 ) ;
F_99 (sdata, tmp, &local->interfaces, list) {
F_79 ( & V_2 -> V_120 ) ;
if ( V_2 -> V_42 )
F_195 ( V_2 -> V_42 , & V_298 ) ;
else
F_55 ( & V_2 -> V_120 , & V_299 ) ;
}
F_24 ( & V_15 -> V_56 ) ;
F_196 ( & V_298 ) ;
F_79 ( & V_298 ) ;
F_99 (sdata, tmp, &wdev_list, list) {
F_79 ( & V_2 -> V_120 ) ;
F_191 ( & V_2 -> V_107 ) ;
F_43 ( V_2 ) ;
}
}
static int F_197 ( struct V_300 * V_301 ,
unsigned long V_145 ,
void * V_269 )
{
struct V_41 * V_42 = V_269 ;
struct V_1 * V_2 ;
if ( V_145 != V_302 )
return 0 ;
if ( ! V_42 -> V_278 || ! V_42 -> V_278 -> V_54 )
return 0 ;
if ( V_42 -> V_278 -> V_54 -> V_303 != V_304 )
return 0 ;
V_2 = F_26 ( V_42 ) ;
memcpy ( V_2 -> V_102 , V_42 -> V_102 , V_103 ) ;
F_198 ( V_2 ) ;
return 0 ;
}
int F_199 ( void )
{
return F_200 ( & V_305 ) ;
}
void F_201 ( void )
{
F_202 ( & V_305 ) ;
}
