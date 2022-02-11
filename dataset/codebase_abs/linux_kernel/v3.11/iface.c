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
static int F_21 ( struct V_1 * V_2 , T_2 * V_47 ,
bool V_48 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_1 * V_49 ;
T_3 V_50 , V_51 , V_52 ;
T_2 * V_53 ;
int V_54 = 0 ;
if ( F_22 ( V_15 -> V_18 . V_55 -> V_56 ) )
return 0 ;
V_53 = V_47 ;
V_50 = ( ( T_3 ) V_53 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_53 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_53 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_53 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_53 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_53 [ 5 ] << 0 * 8 ) ;
V_53 = V_15 -> V_18 . V_55 -> V_56 ;
V_51 = ( ( T_3 ) V_53 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_53 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_53 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_53 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_53 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_53 [ 5 ] << 0 * 8 ) ;
if ( ! V_48 )
return V_54 ;
F_23 ( & V_15 -> V_57 ) ;
F_15 (iter, &local->interfaces, list) {
if ( V_49 == V_2 )
continue;
if ( V_49 -> V_6 . type == V_58 &&
! ( V_49 -> V_59 . V_60 & V_61 ) )
continue;
V_53 = V_49 -> V_6 . V_47 ;
V_52 = ( ( T_3 ) V_53 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_53 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_53 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_53 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_53 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_53 [ 5 ] << 0 * 8 ) ;
if ( ( V_50 & ~ V_51 ) != ( V_52 & ~ V_51 ) ) {
V_54 = - V_45 ;
break;
}
}
F_24 ( & V_15 -> V_57 ) ;
return V_54 ;
}
static int F_25 ( struct V_41 * V_42 , void * V_47 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_62 * V_63 = V_47 ;
bool V_48 = true ;
int V_54 ;
if ( F_27 ( V_2 ) )
return - V_64 ;
if ( V_2 -> V_6 . type == V_58 &&
! ( V_2 -> V_59 . V_60 & V_61 ) )
V_48 = false ;
V_54 = F_21 ( V_2 , V_63 -> V_65 , V_48 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_28 ( V_42 , V_63 ) ;
if ( V_54 == 0 )
memcpy ( V_2 -> V_6 . V_47 , V_63 -> V_65 , V_66 ) ;
return V_54 ;
}
static inline int F_29 ( int V_67 , int V_68 )
{
return V_67 == V_58 ||
V_68 == V_58 ||
V_67 == V_69 ||
V_68 == V_69 ||
( V_67 == V_70 && V_68 == V_71 ) ||
( V_67 == V_71 &&
( V_68 == V_71 ||
V_68 == V_70 ) ) ||
( V_67 == V_70 && V_68 == V_72 ) ||
( V_67 == V_72 &&
( V_68 == V_70 ||
V_68 == V_72 ) ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_73 V_74 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_1 * V_75 ;
F_31 () ;
F_15 (nsdata, &local->interfaces, list) {
if ( V_75 != V_2 && F_27 ( V_75 ) ) {
if ( V_74 == V_76 &&
V_75 -> V_6 . type == V_76 )
return - V_64 ;
if ( ! F_32 ( V_2 -> V_6 . V_47 ,
V_75 -> V_6 . V_47 ) )
continue;
if ( ! F_29 ( V_74 ,
V_75 -> V_6 . type ) )
return - V_77 ;
if ( V_74 == V_72 &&
V_75 -> V_6 . type == V_70 )
V_2 -> V_78 = & V_75 -> V_59 . V_79 ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_80 = V_2 -> V_15 -> V_18 . V_81 ;
int V_82 ;
if ( V_2 -> V_6 . type != V_69 ) {
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ ) {
if ( F_34 ( V_2 -> V_6 . V_84 [ V_82 ] ==
V_85 ) )
return - V_45 ;
if ( F_34 ( V_2 -> V_6 . V_84 [ V_82 ] >=
V_80 ) )
return - V_45 ;
}
}
if ( ( V_2 -> V_6 . type != V_70 &&
V_2 -> V_6 . type != V_86 ) ||
! ( V_2 -> V_15 -> V_18 . V_20 & V_87 ) ) {
V_2 -> V_6 . V_88 = V_85 ;
return 0 ;
}
if ( F_34 ( V_2 -> V_6 . V_88 == V_85 ) )
return - V_45 ;
if ( F_34 ( V_2 -> V_6 . V_88 >= V_80 ) )
return - V_45 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
const int V_89 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
T_1 V_20 = V_2 -> V_59 . V_60 ;
#define F_36 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_36 ( V_90 , V_91 ) ;
F_36 ( V_92 , V_93 ) ;
F_36 ( V_94 , V_95 ) ;
F_36 ( V_94 , V_96 ) ;
F_36 ( V_97 , V_98 ) ;
#undef F_36
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ ) {
if ( V_15 -> V_18 . V_20 & V_87 )
V_2 -> V_6 . V_84 [ V_82 ] = V_85 ;
else if ( V_15 -> V_18 . V_81 >= V_83 )
V_2 -> V_6 . V_84 [ V_82 ] = V_82 ;
else
V_2 -> V_6 . V_84 [ V_82 ] = 0 ;
}
V_2 -> V_6 . V_88 = V_85 ;
}
int F_38 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
int V_54 ;
if ( ! ( V_15 -> V_18 . V_20 & V_99 ) )
return 0 ;
F_31 () ;
if ( V_15 -> V_100 )
return 0 ;
V_2 = F_39 ( sizeof( * V_2 ) + V_15 -> V_18 . V_101 , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_6 . type = V_58 ;
snprintf ( V_2 -> V_104 , V_105 , L_1 ,
F_40 ( V_15 -> V_18 . V_55 ) ) ;
F_37 ( V_2 ) ;
V_54 = F_41 ( V_15 , V_2 ) ;
if ( F_42 ( V_54 ) ) {
F_43 ( V_2 ) ;
return V_54 ;
}
V_54 = F_33 ( V_2 ) ;
if ( V_54 ) {
F_43 ( V_2 ) ;
return V_54 ;
}
V_54 = F_44 ( V_2 , & V_15 -> V_106 ,
V_107 ) ;
if ( V_54 ) {
F_45 ( V_15 , V_2 ) ;
F_43 ( V_2 ) ;
return V_54 ;
}
F_23 ( & V_15 -> V_57 ) ;
F_46 ( V_15 -> V_100 , V_2 ) ;
F_24 ( & V_15 -> V_57 ) ;
return 0 ;
}
void F_47 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
if ( ! ( V_15 -> V_18 . V_20 & V_99 ) )
return;
F_31 () ;
F_23 ( & V_15 -> V_57 ) ;
V_2 = F_48 ( V_15 -> V_100 ,
F_49 ( & V_15 -> V_57 ) ) ;
if ( ! V_2 ) {
F_24 ( & V_15 -> V_57 ) ;
return;
}
F_46 ( V_15 -> V_100 , NULL ) ;
F_24 ( & V_15 -> V_57 ) ;
F_50 () ;
F_51 ( V_2 ) ;
F_45 ( V_15 , V_2 ) ;
F_43 ( V_2 ) ;
}
int F_52 ( struct V_108 * V_109 , bool V_110 )
{
struct V_1 * V_2 = F_53 ( V_109 ) ;
struct V_41 * V_42 = V_109 -> V_111 ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_112 * V_113 ;
T_1 V_114 = 0 ;
int V_115 ;
T_1 V_116 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_71 :
if ( ! F_54 ( V_2 -> V_59 . V_117 . V_118 ) )
return - V_119 ;
break;
case V_72 : {
struct V_1 * V_120 ;
if ( ! V_2 -> V_78 )
return - V_119 ;
F_55 ( & V_2 -> V_59 . V_121 . V_122 , & V_2 -> V_78 -> V_123 ) ;
V_120 = F_56 ( V_2 -> V_78 ,
struct V_1 , V_59 . V_79 ) ;
V_2 -> V_124 =
V_120 -> V_124 ;
V_2 -> V_125 =
V_120 -> V_125 ;
V_2 -> V_6 . V_88 = V_120 -> V_6 . V_88 ;
memcpy ( V_2 -> V_6 . V_84 , V_120 -> V_6 . V_84 ,
sizeof( V_2 -> V_6 . V_84 ) ) ;
break;
}
case V_70 :
V_2 -> V_78 = & V_2 -> V_59 . V_79 ;
break;
case V_86 :
case V_126 :
case V_58 :
case V_76 :
case V_69 :
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
F_42 ( 1 ) ;
break;
}
if ( V_15 -> V_131 == 0 ) {
V_115 = F_57 ( V_15 ) ;
if ( V_115 )
goto V_132;
V_116 = ~ 0 ;
F_58 ( V_15 , true ) ;
F_17 ( V_15 ,
V_133 , 0 ) ;
}
if ( V_42 && F_22 ( V_42 -> V_134 ) ) {
memcpy ( V_42 -> V_134 ,
V_15 -> V_18 . V_55 -> V_135 ,
V_66 ) ;
memcpy ( V_42 -> V_135 , V_42 -> V_134 , V_66 ) ;
if ( ! F_54 ( V_42 -> V_134 ) ) {
V_115 = - V_136 ;
goto V_137;
}
}
switch ( V_2 -> V_6 . type ) {
case V_72 :
if ( F_59 ( V_2 -> V_78 -> V_138 ) ) {
F_60 ( V_2 ) ;
F_61 ( V_42 ) ;
} else {
F_62 ( V_42 ) ;
}
break;
case V_58 :
if ( V_2 -> V_59 . V_60 & V_139 ) {
V_15 -> V_140 ++ ;
break;
}
if ( V_2 -> V_59 . V_60 & V_61 ) {
V_115 = F_41 ( V_15 , V_2 ) ;
if ( V_115 )
goto V_137;
} else if ( V_15 -> V_33 == 0 && V_15 -> V_131 == 0 ) {
V_115 = F_38 ( V_15 ) ;
if ( V_115 )
goto V_137;
}
V_15 -> V_33 ++ ;
if ( V_15 -> V_33 == 1 ) {
V_15 -> V_18 . V_19 . V_20 |= V_141 ;
V_116 |= V_142 ;
}
F_35 ( V_2 , 1 ) ;
F_63 ( V_15 ) ;
F_23 ( & V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
F_24 ( & V_15 -> V_31 ) ;
F_61 ( V_42 ) ;
break;
default:
if ( V_110 ) {
F_47 ( V_15 ) ;
V_115 = F_41 ( V_15 , V_2 ) ;
if ( V_115 )
goto V_137;
V_115 = F_33 ( V_2 ) ;
if ( V_115 )
goto V_143;
}
if ( V_2 -> V_6 . type == V_70 ) {
V_15 -> V_144 ++ ;
V_15 -> V_145 ++ ;
F_63 ( V_15 ) ;
} else if ( V_2 -> V_6 . type == V_76 ) {
V_15 -> V_145 ++ ;
}
if ( V_2 -> V_6 . type != V_69 )
V_114 |= F_64 ( V_2 ) ;
F_8 ( V_2 , V_114 ) ;
switch ( V_2 -> V_6 . type ) {
case V_126 :
case V_76 :
case V_70 :
case V_86 :
F_62 ( V_42 ) ;
break;
case V_71 :
case V_69 :
break;
default:
F_42 ( 1 ) ;
}
F_65 ( V_2 , true ) ;
}
F_66 ( V_146 , & V_2 -> V_147 ) ;
if ( V_2 -> V_6 . type == V_71 ) {
V_113 = F_67 ( V_2 , V_2 -> V_59 . V_117 . V_118 ,
V_102 ) ;
if ( ! V_113 ) {
V_115 = - V_103 ;
goto V_143;
}
F_68 ( V_113 , V_148 ) ;
F_68 ( V_113 , V_149 ) ;
F_68 ( V_113 , V_150 ) ;
V_115 = F_69 ( V_113 ) ;
if ( V_115 ) {
goto V_143;
}
F_70 ( V_113 ) ;
F_61 ( V_42 ) ;
} else if ( V_2 -> V_6 . type == V_69 ) {
F_46 ( V_15 -> V_151 , V_2 ) ;
}
if ( V_2 -> V_20 & V_152 )
F_71 ( & V_15 -> V_153 ) ;
if ( V_2 -> V_20 & V_154 )
F_71 ( & V_15 -> V_155 ) ;
if ( V_110 )
V_15 -> V_131 ++ ;
if ( V_116 )
F_6 ( V_15 , V_116 ) ;
F_72 ( V_15 , - 1 ) ;
if ( V_2 -> V_6 . type == V_58 ||
V_2 -> V_6 . type == V_72 ) {
F_73 ( V_42 ) ;
} else if ( V_42 ) {
unsigned long V_20 ;
int V_156 = V_83 ;
int V_157 ;
if ( V_15 -> V_18 . V_81 < V_83 )
V_156 = 1 ;
F_74 ( & V_15 -> V_158 , V_20 ) ;
if ( V_2 -> V_6 . V_88 == V_85 ||
( V_15 -> V_159 [ V_2 -> V_6 . V_88 ] == 0 &&
F_75 ( & V_15 -> V_160 [ V_2 -> V_6 . V_88 ] ) ) ) {
for ( V_157 = 0 ; V_157 < V_156 ; V_157 ++ ) {
int V_161 = V_2 -> V_6 . V_84 [ V_157 ] ;
if ( V_15 -> V_159 [ V_161 ] == 0 &&
F_75 ( & V_15 -> V_160 [ V_161 ] ) )
F_76 ( V_42 , V_157 ) ;
}
}
F_77 ( & V_15 -> V_158 , V_20 ) ;
}
return 0 ;
V_143:
F_45 ( V_15 , V_2 ) ;
V_137:
if ( ! V_15 -> V_131 )
F_78 ( V_15 ) ;
V_132:
V_2 -> V_78 = NULL ;
if ( V_2 -> V_6 . type == V_72 )
F_79 ( & V_2 -> V_59 . V_121 . V_122 ) ;
F_80 ( V_146 , & V_2 -> V_147 ) ;
return V_115 ;
}
static int F_81 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
int V_162 ;
if ( ! F_54 ( V_42 -> V_134 ) )
return - V_136 ;
V_162 = F_30 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_162 )
return V_162 ;
return F_52 ( & V_2 -> V_109 , true ) ;
}
static void F_82 ( struct V_1 * V_2 ,
bool V_163 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
unsigned long V_20 ;
struct V_164 * V_165 , * V_52 ;
T_1 V_116 = 0 ;
int V_82 , V_166 ;
struct V_167 * V_168 ;
F_80 ( V_146 , & V_2 -> V_147 ) ;
if ( F_83 ( V_15 -> V_169 ) == V_2 )
F_84 ( V_15 ) ;
if ( V_2 -> V_42 )
F_85 ( V_2 -> V_42 ) ;
F_86 ( V_15 , V_2 ) ;
if ( V_2 -> V_6 . type == V_126 )
F_87 ( V_2 ) ;
V_166 = F_88 ( V_2 ) ;
F_34 ( ( V_2 -> V_6 . type != V_71 && V_166 > 0 ) ||
( V_2 -> V_6 . type == V_71 && V_166 != 1 ) ) ;
if ( V_2 -> V_20 & V_152 )
F_89 ( & V_15 -> V_153 ) ;
if ( V_2 -> V_20 & V_154 )
F_89 ( & V_15 -> V_155 ) ;
if ( V_2 -> V_6 . type == V_70 ) {
V_15 -> V_144 -- ;
V_15 -> V_145 -- ;
} else if ( V_2 -> V_6 . type == V_76 ) {
V_15 -> V_145 -- ;
}
if ( V_2 -> V_42 ) {
F_90 ( V_2 -> V_42 ) ;
F_91 ( & V_15 -> V_170 ) ;
F_92 ( & V_15 -> V_171 , & V_2 -> V_42 -> V_172 ,
V_2 -> V_42 -> V_173 ) ;
F_93 ( & V_15 -> V_170 ) ;
F_94 ( V_2 -> V_42 ) ;
}
F_95 ( & V_15 -> V_174 ) ;
F_96 ( & V_15 -> V_175 ) ;
F_96 ( & V_2 -> V_176 ) ;
F_97 ( & V_2 -> V_177 ) ;
if ( V_2 -> V_109 . V_178 ) {
F_42 ( V_15 -> V_179 ) ;
F_23 ( & V_15 -> V_57 ) ;
F_51 ( V_2 ) ;
F_24 ( & V_15 -> V_57 ) ;
F_98 ( V_2 -> V_42 , V_180 ,
V_102 ) ;
}
if ( V_2 -> V_6 . type == V_70 ) {
struct V_1 * V_121 , * V_181 ;
F_99 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_100 ( V_121 -> V_42 ) ;
F_42 ( ! F_14 ( & V_2 -> V_59 . V_79 . V_123 ) ) ;
} else if ( V_2 -> V_6 . type == V_72 ) {
V_168 = & V_2 -> V_78 -> V_168 ;
F_74 ( & V_168 -> V_182 . V_183 , V_20 ) ;
F_101 (&ps->bc_buf, skb, tmp) {
if ( V_165 -> V_42 == V_2 -> V_42 ) {
F_102 ( V_165 , & V_168 -> V_182 ) ;
V_15 -> V_184 -- ;
F_103 ( & V_15 -> V_18 , V_165 ) ;
}
}
F_77 ( & V_168 -> V_182 . V_183 , V_20 ) ;
}
if ( V_163 )
V_15 -> V_131 -- ;
switch ( V_2 -> V_6 . type ) {
case V_72 :
F_79 ( & V_2 -> V_59 . V_121 . V_122 ) ;
F_46 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_58 :
if ( V_2 -> V_59 . V_60 & V_139 ) {
V_15 -> V_140 -- ;
break;
}
V_15 -> V_33 -- ;
if ( V_15 -> V_33 == 0 ) {
V_15 -> V_18 . V_19 . V_20 &= ~ V_141 ;
V_116 |= V_142 ;
}
F_35 ( V_2 , - 1 ) ;
break;
case V_69 :
F_46 ( V_15 -> V_151 , NULL ) ;
default:
F_96 ( & V_2 -> V_185 ) ;
F_104 () ;
F_105 () ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
case V_70 :
F_108 ( & V_2 -> V_186 ) ;
}
V_2 -> V_78 = NULL ;
F_74 ( & V_15 -> V_158 , V_20 ) ;
for ( V_82 = 0 ; V_82 < V_187 ; V_82 ++ ) {
F_101 (&local->pending[i], skb, tmp) {
struct V_188 * V_189 = F_109 ( V_165 ) ;
if ( V_189 -> V_95 . V_6 == & V_2 -> V_6 ) {
F_102 ( V_165 , & V_15 -> V_160 [ V_82 ] ) ;
F_103 ( & V_15 -> V_18 , V_165 ) ;
}
}
}
F_77 ( & V_15 -> V_158 , V_20 ) ;
if ( V_15 -> V_131 == 0 )
F_110 ( V_15 ) ;
if ( V_15 -> V_179 ) {
F_42 ( V_15 -> V_190 ) ;
F_42 ( F_59 ( V_15 -> V_100 ) ) ;
return;
}
switch ( V_2 -> V_6 . type ) {
case V_72 :
break;
case V_58 :
if ( V_15 -> V_33 == 0 )
F_47 ( V_15 ) ;
F_23 ( & V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
F_24 ( & V_15 -> V_31 ) ;
if ( ! ( V_2 -> V_59 . V_60 & V_61 ) )
break;
default:
if ( V_163 )
F_45 ( V_15 , V_2 ) ;
}
F_72 ( V_15 , - 1 ) ;
if ( V_15 -> V_131 == 0 ) {
F_111 ( V_15 ) ;
return;
}
F_63 ( V_15 ) ;
F_6 ( V_15 , V_116 ) ;
if ( V_15 -> V_33 == V_15 -> V_131 )
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
int V_191 , V_192 , V_193 , V_194 ;
V_191 = ! ! ( V_42 -> V_20 & V_195 ) ;
V_192 = ! ! ( V_42 -> V_20 & V_196 ) ;
V_193 = ! ! ( V_2 -> V_20 & V_152 ) ;
V_194 = ! ! ( V_2 -> V_20 & V_154 ) ;
if ( V_191 != V_193 ) {
if ( V_42 -> V_20 & V_195 )
F_71 ( & V_15 -> V_153 ) ;
else
F_89 ( & V_15 -> V_153 ) ;
V_2 -> V_20 ^= V_152 ;
}
if ( V_192 != V_194 ) {
if ( V_42 -> V_20 & V_196 )
F_71 ( & V_15 -> V_155 ) ;
else
F_89 ( & V_15 -> V_155 ) ;
V_2 -> V_20 ^= V_154 ;
}
if ( V_2 -> V_6 . type != V_58 &&
V_2 -> V_6 . type != V_72 &&
V_2 -> V_6 . type != V_70 )
F_114 ( V_15 , V_2 , & V_42 -> V_172 ) ;
F_91 ( & V_15 -> V_170 ) ;
F_115 ( & V_15 -> V_171 , & V_42 -> V_172 , V_42 -> V_173 ) ;
F_93 ( & V_15 -> V_170 ) ;
F_116 ( & V_15 -> V_18 , & V_15 -> V_197 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_166 ;
int V_82 ;
F_107 ( V_2 ) ;
F_118 ( V_2 ) ;
for ( V_82 = 0 ; V_82 < V_198 ; V_82 ++ )
F_119 ( & V_2 -> V_199 [ V_82 ] . V_200 ) ;
V_2 -> V_201 = 0 ;
if ( F_120 ( & V_2 -> V_6 ) )
F_121 ( V_2 ) ;
V_166 = F_122 ( V_2 ) ;
F_42 ( V_166 ) ;
}
static void F_123 ( struct V_41 * V_42 )
{
F_117 ( F_26 ( V_42 ) ) ;
}
static T_6 F_124 ( struct V_41 * V_42 ,
struct V_164 * V_165 )
{
return F_125 ( F_26 ( V_42 ) , V_165 ) ;
}
static T_6 F_126 ( struct V_41 * V_42 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_202 * V_203 ;
struct V_204 * V_205 = ( void * ) V_165 -> V_206 ;
if ( V_15 -> V_18 . V_81 < V_83 )
return 0 ;
if ( V_165 -> V_207 < 4 ||
V_165 -> V_207 < F_127 ( V_205 -> V_208 ) + 2 )
return 0 ;
V_203 = ( void * ) ( ( T_2 * ) V_165 -> V_206 + F_127 ( V_205 -> V_208 ) ) ;
return F_128 ( V_2 , V_165 , V_203 ) ;
}
static void F_129 ( struct V_41 * V_42 )
{
F_130 ( V_42 ) ;
V_42 -> V_209 &= ~ V_210 ;
V_42 -> V_211 = & V_212 ;
V_42 -> V_213 = V_214 ;
}
static void F_131 ( struct V_215 * V_185 )
{
struct V_1 * V_2 =
F_56 ( V_185 , struct V_1 , V_185 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_164 * V_165 ;
struct V_112 * V_113 ;
struct V_216 * V_217 ;
if ( ! F_27 ( V_2 ) )
return;
if ( V_15 -> V_25 )
return;
if ( F_132 ( V_15 -> V_179 ,
L_2 ) )
return;
while ( ( V_165 = F_133 ( & V_2 -> V_186 ) ) ) {
struct V_218 * V_219 = ( void * ) V_165 -> V_206 ;
if ( V_165 -> V_220 == V_221 ) {
V_217 = ( void * ) & V_165 -> V_222 ;
F_134 ( & V_2 -> V_6 , V_217 -> V_223 ,
V_217 -> V_224 ) ;
} else if ( V_165 -> V_220 == V_225 ) {
V_217 = ( void * ) & V_165 -> V_222 ;
F_135 ( & V_2 -> V_6 , V_217 -> V_223 ,
V_217 -> V_224 ) ;
} else if ( F_136 ( V_219 -> V_226 ) &&
V_219 -> V_59 . V_227 . V_228 == V_229 ) {
int V_207 = V_165 -> V_207 ;
F_23 ( & V_15 -> V_230 ) ;
V_113 = F_137 ( V_2 , V_219 -> V_63 ) ;
if ( V_113 ) {
switch ( V_219 -> V_59 . V_227 . V_59 . V_231 . V_232 ) {
case V_233 :
F_138 (
V_15 , V_113 , V_219 , V_207 ) ;
break;
case V_234 :
F_139 ( V_15 , V_113 ,
V_219 , V_207 ) ;
break;
case V_235 :
F_140 ( V_2 , V_113 ,
V_219 , V_207 ) ;
break;
default:
F_42 ( 1 ) ;
break;
}
}
F_24 ( & V_15 -> V_230 ) ;
} else if ( F_141 ( V_219 -> V_226 ) ) {
struct V_202 * V_203 = ( void * ) V_219 ;
F_42 ( V_203 -> V_226 &
F_142 ( V_236 ) ) ;
F_42 ( ! ( V_203 -> V_237 &
F_142 ( V_238 ) ) ) ;
F_23 ( & V_15 -> V_230 ) ;
V_113 = F_137 ( V_2 , V_219 -> V_63 ) ;
if ( V_113 ) {
T_6 V_224 = * F_143 ( V_203 ) &
V_239 ;
F_144 (
V_113 , V_224 , V_240 ,
V_241 ,
true ) ;
}
F_24 ( & V_15 -> V_230 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_126 :
F_145 ( V_2 , V_165 ) ;
break;
case V_76 :
F_146 ( V_2 , V_165 ) ;
break;
case V_86 :
if ( ! F_120 ( & V_2 -> V_6 ) )
break;
F_147 ( V_2 , V_165 ) ;
break;
default:
F_132 ( 1 , L_3 ) ;
break;
}
F_148 ( V_165 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_126 :
F_149 ( V_2 ) ;
break;
case V_76 :
F_150 ( V_2 ) ;
break;
case V_86 :
if ( ! F_120 ( & V_2 -> V_6 ) )
break;
F_151 ( V_2 ) ;
break;
default:
break;
}
}
static void F_152 ( struct V_215 * V_185 )
{
struct V_1 * V_2 =
F_56 ( V_185 , struct V_1 , V_176 ) ;
F_153 ( V_2 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
enum V_73 type )
{
memset ( & V_2 -> V_59 , 0 , sizeof( V_2 -> V_59 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_242 = false ;
V_2 -> V_109 . V_74 = type ;
V_2 -> V_124 = F_155 ( V_243 ) ;
V_2 -> V_125 = false ;
V_2 -> V_244 = 0 ;
if ( V_2 -> V_42 ) {
V_2 -> V_42 -> V_211 = & V_212 ;
V_2 -> V_42 -> type = V_245 ;
}
F_156 ( & V_2 -> V_186 ) ;
F_157 ( & V_2 -> V_185 , F_131 ) ;
F_157 ( & V_2 -> V_176 , F_152 ) ;
switch ( type ) {
case V_130 :
type = V_70 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_242 = true ;
case V_70 :
F_156 ( & V_2 -> V_59 . V_79 . V_168 . V_182 ) ;
F_158 ( & V_2 -> V_59 . V_79 . V_123 ) ;
V_2 -> V_6 . V_13 . V_246 = V_2 -> V_6 . V_47 ;
break;
case V_129 :
type = V_126 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_242 = true ;
case V_126 :
V_2 -> V_6 . V_13 . V_246 = V_2 -> V_59 . V_247 . V_246 ;
F_159 ( V_2 ) ;
break;
case V_76 :
V_2 -> V_6 . V_13 . V_246 = V_2 -> V_59 . V_248 . V_246 ;
F_160 ( V_2 ) ;
break;
case V_86 :
if ( F_120 ( & V_2 -> V_6 ) )
F_161 ( V_2 ) ;
break;
case V_58 :
V_2 -> V_42 -> type = V_249 ;
V_2 -> V_42 -> V_211 = & V_250 ;
V_2 -> V_59 . V_60 = V_251 |
V_252 ;
break;
case V_71 :
V_2 -> V_6 . V_13 . V_246 = NULL ;
break;
case V_72 :
break;
case V_69 :
V_2 -> V_6 . V_13 . V_246 = V_2 -> V_6 . V_47 ;
break;
case V_127 :
case V_128 :
F_162 () ;
break;
}
F_163 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
enum V_73 type )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_54 , V_162 ;
enum V_73 V_253 = type ;
bool V_242 = false ;
F_31 () ;
if ( ! V_15 -> V_34 -> V_254 )
return - V_64 ;
switch ( V_2 -> V_6 . type ) {
case V_70 :
case V_126 :
case V_76 :
break;
default:
return - V_64 ;
}
switch ( type ) {
case V_70 :
case V_126 :
case V_76 :
break;
case V_129 :
V_242 = true ;
V_253 = V_126 ;
break;
case V_130 :
V_242 = true ;
V_253 = V_70 ;
break;
default:
return - V_64 ;
}
V_54 = F_30 ( V_2 , V_253 ) ;
if ( V_54 )
return V_54 ;
F_82 ( V_2 , false ) ;
F_117 ( V_2 ) ;
V_54 = F_165 ( V_15 , V_2 , V_253 , V_242 ) ;
if ( V_54 )
type = V_2 -> V_6 . type ;
F_33 ( V_2 ) ;
F_154 ( V_2 , type ) ;
V_162 = F_52 ( & V_2 -> V_109 , false ) ;
F_132 ( V_162 , L_4 , V_162 ) ;
return V_54 ;
}
int F_166 ( struct V_1 * V_2 ,
enum V_73 type )
{
int V_54 ;
F_31 () ;
if ( type == F_167 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_27 ( V_2 ) ) {
V_54 = F_164 ( V_2 , type ) ;
if ( V_54 )
return V_54 ;
} else {
F_117 ( V_2 ) ;
F_154 ( V_2 , type ) ;
}
V_2 -> V_255 = 0 ;
if ( type == V_126 )
V_2 -> V_59 . V_247 . V_256 = false ;
return 0 ;
}
static void F_168 ( struct V_17 * V_15 ,
T_2 * V_135 , enum V_73 type )
{
struct V_1 * V_2 ;
T_3 V_51 , V_257 , V_47 , V_258 , V_259 ;
T_2 * V_53 ;
T_2 V_260 [ V_66 ] ;
int V_82 ;
memcpy ( V_135 , V_15 -> V_18 . V_55 -> V_135 , V_66 ) ;
if ( F_22 ( V_15 -> V_18 . V_55 -> V_56 ) &&
V_15 -> V_18 . V_55 -> V_261 <= 1 )
return;
F_23 ( & V_15 -> V_57 ) ;
switch ( type ) {
case V_58 :
break;
case V_71 :
case V_72 :
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_70 )
continue;
memcpy ( V_135 , V_2 -> V_6 . V_47 , V_66 ) ;
break;
}
break;
case V_129 :
case V_130 :
if ( V_15 -> V_18 . V_20 & V_262 ) {
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_69 )
continue;
if ( ! F_27 ( V_2 ) )
continue;
memcpy ( V_135 , V_2 -> V_6 . V_47 , V_66 ) ;
goto V_263;
}
}
default:
for ( V_82 = 0 ; V_82 < V_15 -> V_18 . V_55 -> V_261 ; V_82 ++ ) {
bool V_264 = false ;
F_15 (sdata, &local->interfaces, list) {
if ( memcmp ( V_15 -> V_18 . V_55 -> V_265 [ V_82 ] . V_47 ,
V_2 -> V_6 . V_47 , V_66 ) == 0 ) {
V_264 = true ;
break;
}
}
if ( ! V_264 ) {
memcpy ( V_135 ,
V_15 -> V_18 . V_55 -> V_265 [ V_82 ] . V_47 ,
V_66 ) ;
break;
}
}
if ( F_22 ( V_15 -> V_18 . V_55 -> V_56 ) )
break;
V_53 = V_15 -> V_18 . V_55 -> V_56 ;
V_51 = ( ( T_3 ) V_53 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_53 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_53 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_53 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_53 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_53 [ 5 ] << 0 * 8 ) ;
if ( F_169 ( V_51 ) + F_170 ( V_51 ) != F_171 ( V_51 ) ) {
F_172 ( L_5 ) ;
break;
}
V_53 = V_15 -> V_18 . V_55 -> V_135 ;
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_58 )
continue;
V_53 = V_2 -> V_6 . V_47 ;
break;
}
V_257 = ( ( T_3 ) V_53 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_53 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_53 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_53 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_53 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_53 [ 5 ] << 0 * 8 ) ;
V_259 = 1ULL << F_169 ( V_51 ) ;
V_258 = ( V_257 & V_51 ) ;
V_47 = ( V_257 & ~ V_51 ) | ( V_258 & V_51 ) ;
do {
bool V_264 = false ;
V_260 [ 5 ] = V_47 >> 0 * 8 ;
V_260 [ 4 ] = V_47 >> 1 * 8 ;
V_260 [ 3 ] = V_47 >> 2 * 8 ;
V_260 [ 2 ] = V_47 >> 3 * 8 ;
V_260 [ 1 ] = V_47 >> 4 * 8 ;
V_260 [ 0 ] = V_47 >> 5 * 8 ;
V_258 += V_259 ;
F_15 (sdata, &local->interfaces, list) {
if ( memcmp ( V_260 , V_2 -> V_6 . V_47 ,
V_66 ) == 0 ) {
V_264 = true ;
break;
}
}
if ( ! V_264 ) {
memcpy ( V_135 , V_260 , V_66 ) ;
break;
}
V_47 = ( V_257 & ~ V_51 ) | ( V_258 & V_51 ) ;
} while ( V_47 != V_257 );
break;
}
V_263:
F_24 ( & V_15 -> V_57 ) ;
}
static void F_173 ( struct V_215 * V_266 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_266 , struct V_1 , V_267 ) ;
F_174 ( V_2 ) ;
}
int F_175 ( struct V_17 * V_15 , const char * V_104 ,
struct V_108 * * V_268 , enum V_73 type ,
struct V_269 * V_270 )
{
struct V_41 * V_271 = NULL ;
struct V_1 * V_2 = NULL ;
int V_54 , V_82 ;
int V_272 = 1 ;
F_31 () ;
if ( type == V_69 ) {
struct V_108 * V_109 ;
V_2 = F_39 ( sizeof( * V_2 ) + V_15 -> V_18 . V_101 ,
V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_109 = & V_2 -> V_109 ;
V_2 -> V_42 = NULL ;
F_176 ( V_2 -> V_104 , V_104 , V_105 ) ;
F_168 ( V_15 , V_109 -> V_273 , type ) ;
memcpy ( V_2 -> V_6 . V_47 , V_109 -> V_273 , V_66 ) ;
} else {
if ( V_15 -> V_18 . V_81 >= V_83 )
V_272 = V_83 ;
V_271 = F_177 ( sizeof( * V_2 ) +
V_15 -> V_18 . V_101 ,
V_104 , F_129 , V_272 , 1 ) ;
if ( ! V_271 )
return - V_103 ;
F_178 ( V_271 , F_179 ( V_15 -> V_18 . V_55 ) ) ;
V_271 -> V_274 = V_15 -> V_275 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_276
+ V_277 ;
V_271 -> V_278 = V_279 ;
V_54 = F_180 ( V_271 , V_271 -> V_104 ) ;
if ( V_54 < 0 ) {
V_214 ( V_271 ) ;
return V_54 ;
}
F_168 ( V_15 , V_271 -> V_135 , type ) ;
memcpy ( V_271 -> V_134 , V_271 -> V_135 , V_66 ) ;
F_181 ( V_271 , F_182 ( V_15 -> V_18 . V_55 ) ) ;
V_2 = F_183 ( V_271 ) ;
V_271 -> V_280 = & V_2 -> V_109 ;
memcpy ( V_2 -> V_6 . V_47 , V_271 -> V_134 , V_66 ) ;
memcpy ( V_2 -> V_104 , V_271 -> V_104 , V_105 ) ;
V_2 -> V_42 = V_271 ;
}
V_2 -> V_109 . V_55 = V_15 -> V_18 . V_55 ;
V_2 -> V_15 = V_15 ;
for ( V_82 = 0 ; V_82 < V_198 ; V_82 ++ )
F_156 ( & V_2 -> V_199 [ V_82 ] . V_200 ) ;
F_158 ( & V_2 -> V_281 ) ;
F_184 ( & V_2 -> V_282 ) ;
F_158 ( & V_2 -> V_283 ) ;
F_157 ( & V_2 -> V_267 , F_173 ) ;
F_185 ( & V_2 -> V_177 ,
V_284 ) ;
F_185 ( & V_2 -> V_285 ,
V_286 ) ;
for ( V_82 = 0 ; V_82 < V_287 ; V_82 ++ ) {
struct V_288 * V_289 ;
V_289 = V_15 -> V_18 . V_55 -> V_290 [ V_82 ] ;
V_2 -> V_291 [ V_82 ] =
V_289 ? ( 1 << V_289 -> V_292 ) - 1 : 0 ;
if ( V_289 )
memcpy ( V_2 -> V_293 [ V_82 ] ,
V_289 -> V_294 . V_295 . V_296 ,
sizeof( V_2 -> V_293 [ V_82 ] ) ) ;
else
memset ( V_2 -> V_293 [ V_82 ] , 0 ,
sizeof( V_2 -> V_293 [ V_82 ] ) ) ;
}
F_37 ( V_2 ) ;
V_2 -> V_12 = V_11 ;
V_2 -> V_10 = V_15 -> V_10 ;
F_154 ( V_2 , type ) ;
if ( V_271 ) {
if ( V_270 ) {
V_271 -> V_280 -> V_256 = V_270 -> V_256 ;
if ( type == V_126 )
V_2 -> V_59 . V_247 . V_256 = V_270 -> V_256 ;
}
V_271 -> V_297 |= V_15 -> V_18 . V_298 ;
V_54 = F_186 ( V_271 ) ;
if ( V_54 ) {
V_214 ( V_271 ) ;
return V_54 ;
}
}
F_23 ( & V_15 -> V_57 ) ;
F_187 ( & V_2 -> V_122 , & V_15 -> V_299 ) ;
F_24 ( & V_15 -> V_57 ) ;
if ( V_268 )
* V_268 = & V_2 -> V_109 ;
return 0 ;
}
void F_188 ( struct V_1 * V_2 )
{
F_31 () ;
F_23 ( & V_2 -> V_15 -> V_57 ) ;
F_189 ( & V_2 -> V_122 ) ;
F_24 ( & V_2 -> V_15 -> V_57 ) ;
F_104 () ;
if ( V_2 -> V_42 ) {
F_190 ( V_2 -> V_42 ) ;
} else {
F_191 ( & V_2 -> V_109 ) ;
F_43 ( V_2 ) ;
}
}
void F_192 ( struct V_1 * V_2 )
{
if ( F_34 ( ! F_16 ( V_146 , & V_2 -> V_147 ) ) )
return;
F_82 ( V_2 , true ) ;
F_117 ( V_2 ) ;
}
void F_193 ( struct V_17 * V_15 )
{
struct V_1 * V_2 , * V_52 ;
F_194 ( V_300 ) ;
F_194 ( V_301 ) ;
F_31 () ;
F_15 (sdata, &local->interfaces, list)
if ( V_2 -> V_6 . type == V_72 )
F_100 ( V_2 -> V_42 ) ;
F_23 ( & V_15 -> V_57 ) ;
F_99 (sdata, tmp, &local->interfaces, list) {
F_79 ( & V_2 -> V_122 ) ;
if ( V_2 -> V_42 )
F_195 ( V_2 -> V_42 , & V_300 ) ;
else
F_55 ( & V_2 -> V_122 , & V_301 ) ;
}
F_24 ( & V_15 -> V_57 ) ;
F_196 ( & V_300 ) ;
F_79 ( & V_300 ) ;
F_99 (sdata, tmp, &wdev_list, list) {
F_79 ( & V_2 -> V_122 ) ;
F_191 ( & V_2 -> V_109 ) ;
F_43 ( V_2 ) ;
}
}
static int F_197 ( struct V_302 * V_303 ,
unsigned long V_147 , void * V_304 )
{
struct V_41 * V_42 = F_198 ( V_304 ) ;
struct V_1 * V_2 ;
if ( V_147 != V_305 )
return 0 ;
if ( ! V_42 -> V_280 || ! V_42 -> V_280 -> V_55 )
return 0 ;
if ( V_42 -> V_280 -> V_55 -> V_306 != V_307 )
return 0 ;
V_2 = F_26 ( V_42 ) ;
memcpy ( V_2 -> V_104 , V_42 -> V_104 , V_105 ) ;
F_199 ( V_2 ) ;
return 0 ;
}
int F_200 ( void )
{
return F_201 ( & V_308 ) ;
}
void F_202 ( void )
{
F_203 ( & V_308 ) ;
}
