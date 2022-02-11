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
V_5 = F_5 ( & V_4 -> V_7 ) ;
F_4 () ;
if ( V_2 -> V_8 != V_9 )
V_5 = F_6 ( V_5 , V_2 -> V_8 ) ;
if ( V_2 -> V_10 != V_9 )
V_5 = F_6 ( V_5 , V_2 -> V_10 ) ;
if ( V_5 != V_2 -> V_6 . V_11 . V_12 ) {
V_2 -> V_6 . V_11 . V_12 = V_5 ;
F_7 ( V_2 -> V_13 , 0 ) ;
return true ;
}
return false ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
F_9 ( V_2 , V_14 ) ;
}
static T_1 F_10 ( struct V_15 * V_13 )
{
if ( ! ( V_13 -> V_16 . V_17 . V_18 & V_19 ) )
return 0 ;
V_13 -> V_16 . V_17 . V_18 &= ~ V_19 ;
return V_20 ;
}
static T_1 F_11 ( struct V_15 * V_13 )
{
if ( V_13 -> V_16 . V_17 . V_18 & V_19 )
return 0 ;
F_12 ( V_13 , NULL ) ;
V_13 -> V_16 . V_17 . V_18 |= V_19 ;
return V_20 ;
}
static T_1 F_13 ( struct V_15 * V_13 ,
bool V_21 )
{
bool V_22 = false , V_23 , V_24 ;
unsigned int V_25 = 0 , V_26 = 0 ;
struct V_27 * V_28 ;
F_14 ( & V_13 -> V_29 ) ;
V_24 = V_21 ||
! F_15 ( & V_13 -> V_30 ) ||
V_13 -> V_31 ;
if ( ! V_13 -> V_32 -> V_33 ) {
F_16 (roc, &local->roc_list, list) {
V_22 = true ;
break;
}
}
V_23 = F_17 ( V_34 , & V_13 -> V_23 ) ||
F_17 ( V_35 , & V_13 -> V_23 ) ;
if ( V_22 || V_23 )
V_25 |= V_36 ;
else
V_26 |= V_36 ;
if ( V_24 )
V_25 |= V_37 ;
else
V_26 |= V_37 ;
F_18 ( V_13 , V_25 , V_26 ) ;
if ( V_22 || V_23 || V_24 )
return F_10 ( V_13 ) ;
return F_11 ( V_13 ) ;
}
T_1 F_19 ( struct V_15 * V_13 )
{
return F_13 ( V_13 , true ) ;
}
void F_20 ( struct V_15 * V_13 )
{
T_1 V_38 = F_13 ( V_13 , false ) ;
if ( V_38 )
F_7 ( V_13 , V_38 ) ;
}
static int F_21 ( struct V_39 * V_40 , int V_41 )
{
if ( V_41 < 256 || V_41 > V_42 )
return - V_43 ;
V_40 -> V_44 = V_41 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 * V_45 ,
bool V_46 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_1 * V_47 ;
T_3 V_48 , V_49 , V_50 ;
T_2 * V_51 ;
int V_52 = 0 ;
if ( F_23 ( V_13 -> V_16 . V_53 -> V_54 ) )
return 0 ;
V_51 = V_45 ;
V_48 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
V_51 = V_13 -> V_16 . V_53 -> V_54 ;
V_49 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
if ( ! V_46 )
return V_52 ;
F_24 ( & V_13 -> V_55 ) ;
F_16 (iter, &local->interfaces, list) {
if ( V_47 == V_2 )
continue;
if ( V_47 -> V_6 . type == V_56 &&
! ( V_47 -> V_57 . V_58 & V_59 ) )
continue;
V_51 = V_47 -> V_6 . V_45 ;
V_50 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
if ( ( V_48 & ~ V_49 ) != ( V_50 & ~ V_49 ) ) {
V_52 = - V_43 ;
break;
}
}
F_25 ( & V_13 -> V_55 ) ;
return V_52 ;
}
static int F_26 ( struct V_39 * V_40 , void * V_45 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
struct V_60 * V_61 = V_45 ;
bool V_46 = true ;
int V_52 ;
if ( F_28 ( V_2 ) )
return - V_62 ;
if ( V_2 -> V_6 . type == V_56 &&
! ( V_2 -> V_57 . V_58 & V_59 ) )
V_46 = false ;
V_52 = F_22 ( V_2 , V_61 -> V_63 , V_46 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_29 ( V_40 , V_61 ) ;
if ( V_52 == 0 )
memcpy ( V_2 -> V_6 . V_45 , V_61 -> V_63 , V_64 ) ;
return V_52 ;
}
static inline int F_30 ( int V_65 , int V_66 )
{
return V_65 == V_56 ||
V_66 == V_56 ||
V_65 == V_67 ||
V_66 == V_67 ||
( V_65 == V_68 && V_66 == V_69 ) ||
( V_65 == V_69 &&
( V_66 == V_69 ||
V_66 == V_68 ) ) ||
( V_65 == V_68 && V_66 == V_70 ) ||
( V_65 == V_70 &&
( V_66 == V_68 ||
V_66 == V_70 ) ) ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_1 * V_73 ;
F_32 () ;
F_16 (nsdata, &local->interfaces, list) {
if ( V_73 != V_2 && F_28 ( V_73 ) ) {
if ( V_72 == V_74 &&
V_73 -> V_6 . type == V_74 )
return - V_62 ;
if ( V_73 -> V_6 . V_75 )
return - V_62 ;
if ( ! F_33 ( V_2 -> V_6 . V_45 ,
V_73 -> V_6 . V_45 ) )
continue;
if ( ! F_30 ( V_72 ,
V_73 -> V_6 . type ) )
return - V_76 ;
if ( V_72 == V_70 &&
V_73 -> V_6 . type == V_68 )
V_2 -> V_77 = & V_73 -> V_57 . V_78 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_71 V_72 )
{
int V_79 = V_2 -> V_13 -> V_16 . V_80 ;
int V_81 ;
if ( V_72 != V_67 ) {
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
if ( F_35 ( V_2 -> V_6 . V_83 [ V_81 ] ==
V_84 ) )
return - V_43 ;
if ( F_35 ( V_2 -> V_6 . V_83 [ V_81 ] >=
V_79 ) )
return - V_43 ;
}
}
if ( ( V_72 != V_68 &&
V_72 != V_85 &&
V_72 != V_86 ) ||
! ( V_2 -> V_13 -> V_16 . V_18 & V_87 ) ) {
V_2 -> V_6 . V_88 = V_84 ;
return 0 ;
}
if ( F_35 ( V_2 -> V_6 . V_88 == V_84 ) )
return - V_43 ;
if ( F_35 ( V_2 -> V_6 . V_88 >= V_79 ) )
return - V_43 ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 ,
const int V_89 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
T_1 V_18 = V_2 -> V_57 . V_58 ;
#define F_37 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_37 ( V_90 , V_91 ) ;
F_37 ( V_92 , V_93 ) ;
F_37 ( V_94 , V_95 ) ;
F_37 ( V_94 , V_96 ) ;
F_37 ( V_97 , V_98 ) ;
#undef F_37
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
if ( V_13 -> V_16 . V_18 & V_87 )
V_2 -> V_6 . V_83 [ V_81 ] = V_84 ;
else if ( V_13 -> V_16 . V_80 >= V_82 )
V_2 -> V_6 . V_83 [ V_81 ] = V_81 ;
else
V_2 -> V_6 . V_83 [ V_81 ] = 0 ;
}
V_2 -> V_6 . V_88 = V_84 ;
}
int F_39 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
int V_52 ;
if ( ! ( V_13 -> V_16 . V_18 & V_99 ) )
return 0 ;
F_32 () ;
if ( V_13 -> V_100 )
return 0 ;
V_2 = F_40 ( sizeof( * V_2 ) + V_13 -> V_16 . V_101 , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 . type = V_56 ;
snprintf ( V_2 -> V_104 , V_105 , L_1 ,
F_41 ( V_13 -> V_16 . V_53 ) ) ;
F_38 ( V_2 ) ;
V_52 = F_42 ( V_13 , V_2 ) ;
if ( F_43 ( V_52 ) ) {
F_44 ( V_2 ) ;
return V_52 ;
}
V_52 = F_34 ( V_2 , V_56 ) ;
if ( V_52 ) {
F_44 ( V_2 ) ;
return V_52 ;
}
V_52 = F_45 ( V_2 , & V_13 -> V_106 ,
V_107 ) ;
if ( V_52 ) {
F_46 ( V_13 , V_2 ) ;
F_44 ( V_2 ) ;
return V_52 ;
}
F_24 ( & V_13 -> V_55 ) ;
F_47 ( V_13 -> V_100 , V_2 ) ;
F_25 ( & V_13 -> V_55 ) ;
return 0 ;
}
void F_48 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
if ( ! ( V_13 -> V_16 . V_18 & V_99 ) )
return;
F_32 () ;
F_24 ( & V_13 -> V_55 ) ;
V_2 = F_49 ( V_13 -> V_100 ,
F_50 ( & V_13 -> V_55 ) ) ;
if ( ! V_2 ) {
F_25 ( & V_13 -> V_55 ) ;
return;
}
F_47 ( V_13 -> V_100 , NULL ) ;
F_25 ( & V_13 -> V_55 ) ;
F_51 () ;
F_52 ( V_2 ) ;
F_46 ( V_13 , V_2 ) ;
F_44 ( V_2 ) ;
}
int F_53 ( struct V_108 * V_109 , bool V_110 )
{
struct V_1 * V_2 = F_54 ( V_109 ) ;
struct V_39 * V_40 = V_109 -> V_111 ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_112 * V_113 ;
T_1 V_114 = 0 ;
int V_115 ;
T_1 V_116 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_69 :
if ( ! F_55 ( V_2 -> V_57 . V_117 . V_118 ) )
return - V_119 ;
break;
case V_70 : {
struct V_1 * V_120 ;
if ( ! V_2 -> V_77 )
return - V_119 ;
F_56 ( & V_2 -> V_57 . V_121 . V_122 , & V_2 -> V_77 -> V_123 ) ;
V_120 = F_57 ( V_2 -> V_77 ,
struct V_1 , V_57 . V_78 ) ;
V_2 -> V_124 =
V_120 -> V_124 ;
V_2 -> V_125 =
V_120 -> V_125 ;
V_2 -> V_6 . V_88 = V_120 -> V_6 . V_88 ;
memcpy ( V_2 -> V_6 . V_83 , V_120 -> V_6 . V_83 ,
sizeof( V_2 -> V_6 . V_83 ) ) ;
break;
}
case V_68 :
V_2 -> V_77 = & V_2 -> V_57 . V_78 ;
break;
case V_86 :
case V_126 :
case V_56 :
case V_74 :
case V_67 :
break;
case V_127 :
case V_128 :
case V_129 :
case V_85 :
F_43 ( 1 ) ;
break;
}
if ( V_13 -> V_130 == 0 ) {
V_115 = F_58 ( V_13 ) ;
if ( V_115 )
goto V_131;
V_116 = ~ 0 ;
F_59 ( V_13 , true ) ;
F_18 ( V_13 ,
V_132 , 0 ) ;
}
if ( V_40 && F_23 ( V_40 -> V_133 ) ) {
memcpy ( V_40 -> V_133 ,
V_13 -> V_16 . V_53 -> V_134 ,
V_64 ) ;
memcpy ( V_40 -> V_134 , V_40 -> V_133 , V_64 ) ;
if ( ! F_55 ( V_40 -> V_133 ) ) {
V_115 = - V_135 ;
goto V_136;
}
}
switch ( V_2 -> V_6 . type ) {
case V_70 :
if ( F_60 ( V_2 -> V_77 -> V_137 ) ) {
F_61 ( V_2 ) ;
F_62 ( V_40 ) ;
} else {
F_63 ( V_40 ) ;
}
break;
case V_56 :
if ( V_2 -> V_57 . V_58 & V_138 ) {
V_13 -> V_139 ++ ;
break;
}
if ( V_2 -> V_57 . V_58 & V_59 ) {
V_115 = F_42 ( V_13 , V_2 ) ;
if ( V_115 )
goto V_136;
} else if ( V_13 -> V_31 == 0 && V_13 -> V_130 == 0 ) {
V_115 = F_39 ( V_13 ) ;
if ( V_115 )
goto V_136;
}
V_13 -> V_31 ++ ;
if ( V_13 -> V_31 == 1 ) {
V_13 -> V_16 . V_17 . V_18 |= V_140 ;
V_116 |= V_141 ;
}
F_36 ( V_2 , 1 ) ;
F_64 ( V_13 ) ;
F_24 ( & V_13 -> V_29 ) ;
F_20 ( V_13 ) ;
F_25 ( & V_13 -> V_29 ) ;
F_62 ( V_40 ) ;
break;
default:
if ( V_110 ) {
F_48 ( V_13 ) ;
V_115 = F_42 ( V_13 , V_2 ) ;
if ( V_115 )
goto V_136;
V_115 = F_34 ( V_2 ,
F_65 ( & V_2 -> V_6 ) ) ;
if ( V_115 )
goto V_142;
}
if ( V_2 -> V_6 . type == V_68 ) {
V_13 -> V_143 ++ ;
V_13 -> V_144 ++ ;
F_64 ( V_13 ) ;
} else if ( V_2 -> V_6 . type == V_74 ) {
V_13 -> V_144 ++ ;
}
if ( V_2 -> V_6 . type != V_67 )
V_114 |= F_66 ( V_2 ) ;
F_9 ( V_2 , V_114 ) ;
switch ( V_2 -> V_6 . type ) {
case V_126 :
case V_74 :
case V_68 :
case V_86 :
F_63 ( V_40 ) ;
break;
case V_69 :
case V_67 :
break;
default:
F_43 ( 1 ) ;
}
F_67 ( V_2 , true ) ;
}
F_68 ( V_145 , & V_2 -> V_146 ) ;
if ( V_2 -> V_6 . type == V_69 ) {
V_113 = F_69 ( V_2 , V_2 -> V_57 . V_117 . V_118 ,
V_102 ) ;
if ( ! V_113 ) {
V_115 = - V_103 ;
goto V_142;
}
F_70 ( V_113 , V_147 ) ;
F_70 ( V_113 , V_148 ) ;
F_70 ( V_113 , V_149 ) ;
V_115 = F_71 ( V_113 ) ;
if ( V_115 ) {
goto V_142;
}
F_72 ( V_113 ) ;
F_62 ( V_40 ) ;
} else if ( V_2 -> V_6 . type == V_67 ) {
F_47 ( V_13 -> V_150 , V_2 ) ;
}
if ( V_2 -> V_18 & V_151 )
F_73 ( & V_13 -> V_152 ) ;
if ( V_2 -> V_18 & V_153 )
F_73 ( & V_13 -> V_154 ) ;
if ( V_110 )
V_13 -> V_130 ++ ;
if ( V_116 )
F_7 ( V_13 , V_116 ) ;
F_74 ( V_13 , - 1 ) ;
if ( V_2 -> V_6 . type == V_56 ||
V_2 -> V_6 . type == V_70 ) {
F_75 ( V_40 ) ;
} else if ( V_40 ) {
unsigned long V_18 ;
int V_155 = V_82 ;
int V_156 ;
if ( V_13 -> V_16 . V_80 < V_82 )
V_155 = 1 ;
F_76 ( & V_13 -> V_157 , V_18 ) ;
if ( V_2 -> V_6 . V_88 == V_84 ||
( V_13 -> V_158 [ V_2 -> V_6 . V_88 ] == 0 &&
F_77 ( & V_13 -> V_159 [ V_2 -> V_6 . V_88 ] ) ) ) {
for ( V_156 = 0 ; V_156 < V_155 ; V_156 ++ ) {
int V_160 = V_2 -> V_6 . V_83 [ V_156 ] ;
if ( V_13 -> V_158 [ V_160 ] == 0 &&
F_77 ( & V_13 -> V_159 [ V_160 ] ) )
F_78 ( V_40 , V_156 ) ;
}
}
F_79 ( & V_13 -> V_157 , V_18 ) ;
}
return 0 ;
V_142:
F_46 ( V_13 , V_2 ) ;
V_136:
if ( ! V_13 -> V_130 )
F_80 ( V_13 ) ;
V_131:
V_2 -> V_77 = NULL ;
if ( V_2 -> V_6 . type == V_70 )
F_81 ( & V_2 -> V_57 . V_121 . V_122 ) ;
F_82 ( V_145 , & V_2 -> V_146 ) ;
return V_115 ;
}
static int F_83 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
int V_161 ;
if ( ! F_55 ( V_40 -> V_133 ) )
return - V_135 ;
V_161 = F_31 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_161 )
return V_161 ;
return F_53 ( & V_2 -> V_109 , true ) ;
}
static void F_84 ( struct V_1 * V_2 ,
bool V_162 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
unsigned long V_18 ;
struct V_163 * V_164 , * V_50 ;
T_1 V_116 = 0 ;
int V_81 , V_165 ;
struct V_166 * V_167 ;
F_82 ( V_145 , & V_2 -> V_146 ) ;
if ( F_85 ( V_13 -> V_168 ) == V_2 )
F_86 ( V_13 ) ;
if ( V_2 -> V_40 )
F_87 ( V_2 -> V_40 ) ;
F_88 ( V_13 , V_2 ) ;
if ( V_2 -> V_6 . type == V_126 )
F_89 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_74 )
F_90 ( V_2 ) ;
V_165 = F_91 ( V_2 ) ;
F_35 ( ( V_2 -> V_6 . type != V_69 && V_165 > 0 ) ||
( V_2 -> V_6 . type == V_69 && V_165 != 1 ) ) ;
if ( V_2 -> V_18 & V_151 )
F_92 ( & V_13 -> V_152 ) ;
if ( V_2 -> V_18 & V_153 )
F_92 ( & V_13 -> V_154 ) ;
if ( V_2 -> V_6 . type == V_68 ) {
V_13 -> V_143 -- ;
V_13 -> V_144 -- ;
} else if ( V_2 -> V_6 . type == V_74 ) {
V_13 -> V_144 -- ;
}
if ( V_2 -> V_40 ) {
F_93 ( V_2 -> V_40 ) ;
F_94 ( & V_13 -> V_169 ) ;
F_95 ( & V_13 -> V_170 , & V_2 -> V_40 -> V_171 ,
V_2 -> V_40 -> V_172 ) ;
F_96 ( & V_13 -> V_169 ) ;
F_97 ( V_2 -> V_40 ) ;
}
F_98 ( & V_13 -> V_173 ) ;
F_99 ( & V_13 -> V_174 ) ;
F_99 ( & V_2 -> V_175 ) ;
V_2 -> V_6 . V_75 = false ;
F_99 ( & V_2 -> V_176 ) ;
F_100 ( & V_2 -> V_177 ) ;
if ( V_2 -> V_109 . V_178 ) {
F_43 ( V_13 -> V_179 ) ;
F_24 ( & V_13 -> V_55 ) ;
F_52 ( V_2 ) ;
F_25 ( & V_13 -> V_55 ) ;
F_101 ( V_2 -> V_40 , V_180 ,
V_102 ) ;
}
if ( V_2 -> V_6 . type == V_68 ) {
struct V_1 * V_121 , * V_181 ;
F_102 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_103 ( V_121 -> V_40 ) ;
F_43 ( ! F_15 ( & V_2 -> V_57 . V_78 . V_123 ) ) ;
} else if ( V_2 -> V_6 . type == V_70 ) {
V_167 = & V_2 -> V_77 -> V_167 ;
F_76 ( & V_167 -> V_182 . V_183 , V_18 ) ;
F_104 (&ps->bc_buf, skb, tmp) {
if ( V_164 -> V_40 == V_2 -> V_40 ) {
F_105 ( V_164 , & V_167 -> V_182 ) ;
V_13 -> V_184 -- ;
F_106 ( & V_13 -> V_16 , V_164 ) ;
}
}
F_79 ( & V_167 -> V_182 . V_183 , V_18 ) ;
}
if ( V_162 )
V_13 -> V_130 -- ;
switch ( V_2 -> V_6 . type ) {
case V_70 :
F_81 ( & V_2 -> V_57 . V_121 . V_122 ) ;
F_47 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_56 :
if ( V_2 -> V_57 . V_58 & V_138 ) {
V_13 -> V_139 -- ;
break;
}
V_13 -> V_31 -- ;
if ( V_13 -> V_31 == 0 ) {
V_13 -> V_16 . V_17 . V_18 &= ~ V_140 ;
V_116 |= V_141 ;
}
F_36 ( V_2 , - 1 ) ;
break;
case V_67 :
F_47 ( V_13 -> V_150 , NULL ) ;
default:
F_99 ( & V_2 -> V_185 ) ;
F_107 () ;
F_108 () ;
F_109 ( V_2 ) ;
F_110 ( V_2 ) ;
case V_68 :
F_111 ( & V_2 -> V_186 ) ;
}
V_2 -> V_77 = NULL ;
F_76 ( & V_13 -> V_157 , V_18 ) ;
for ( V_81 = 0 ; V_81 < V_187 ; V_81 ++ ) {
F_104 (&local->pending[i], skb, tmp) {
struct V_188 * V_189 = F_112 ( V_164 ) ;
if ( V_189 -> V_95 . V_6 == & V_2 -> V_6 ) {
F_105 ( V_164 , & V_13 -> V_159 [ V_81 ] ) ;
F_106 ( & V_13 -> V_16 , V_164 ) ;
}
}
}
F_79 ( & V_13 -> V_157 , V_18 ) ;
if ( V_13 -> V_130 == 0 )
F_113 ( V_13 ) ;
if ( V_13 -> V_179 ) {
F_43 ( V_13 -> V_190 ) ;
F_43 ( F_60 ( V_13 -> V_100 ) ) ;
return;
}
switch ( V_2 -> V_6 . type ) {
case V_70 :
break;
case V_56 :
if ( V_13 -> V_31 == 0 )
F_48 ( V_13 ) ;
F_24 ( & V_13 -> V_29 ) ;
F_20 ( V_13 ) ;
F_25 ( & V_13 -> V_29 ) ;
if ( ! ( V_2 -> V_57 . V_58 & V_59 ) )
break;
default:
if ( V_162 )
F_46 ( V_13 , V_2 ) ;
}
F_74 ( V_13 , - 1 ) ;
if ( V_13 -> V_130 == 0 ) {
F_114 ( V_13 ) ;
return;
}
F_64 ( V_13 ) ;
F_7 ( V_13 , V_116 ) ;
if ( V_13 -> V_31 == V_13 -> V_130 )
F_39 ( V_13 ) ;
}
static int F_115 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
F_84 ( V_2 , true ) ;
return 0 ;
}
static void F_116 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
int V_191 , V_192 , V_193 , V_194 ;
V_191 = ! ! ( V_40 -> V_18 & V_195 ) ;
V_192 = ! ! ( V_40 -> V_18 & V_196 ) ;
V_193 = ! ! ( V_2 -> V_18 & V_151 ) ;
V_194 = ! ! ( V_2 -> V_18 & V_153 ) ;
if ( V_191 != V_193 ) {
if ( V_40 -> V_18 & V_195 )
F_73 ( & V_13 -> V_152 ) ;
else
F_92 ( & V_13 -> V_152 ) ;
V_2 -> V_18 ^= V_151 ;
}
if ( V_192 != V_194 ) {
if ( V_40 -> V_18 & V_196 )
F_73 ( & V_13 -> V_154 ) ;
else
F_92 ( & V_13 -> V_154 ) ;
V_2 -> V_18 ^= V_153 ;
}
if ( V_2 -> V_6 . type != V_56 &&
V_2 -> V_6 . type != V_70 &&
V_2 -> V_6 . type != V_68 )
F_117 ( V_13 , V_2 , & V_40 -> V_171 ) ;
F_94 ( & V_13 -> V_169 ) ;
F_118 ( & V_13 -> V_170 , & V_40 -> V_171 , V_40 -> V_172 ) ;
F_96 ( & V_13 -> V_169 ) ;
F_119 ( & V_13 -> V_16 , & V_13 -> V_197 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
int V_165 ;
int V_81 ;
F_110 ( V_2 ) ;
F_121 ( V_2 ) ;
for ( V_81 = 0 ; V_81 < V_198 ; V_81 ++ )
F_122 ( & V_2 -> V_199 [ V_81 ] . V_200 ) ;
V_2 -> V_201 = 0 ;
if ( F_123 ( & V_2 -> V_6 ) )
F_124 ( V_2 ) ;
V_165 = F_125 ( V_2 ) ;
F_43 ( V_165 ) ;
}
static void F_126 ( struct V_39 * V_40 )
{
F_120 ( F_27 ( V_40 ) ) ;
}
static T_6 F_127 ( struct V_39 * V_40 ,
struct V_163 * V_164 ,
void * V_202 )
{
return F_128 ( F_27 ( V_40 ) , V_164 ) ;
}
static T_6 F_129 ( struct V_39 * V_40 ,
struct V_163 * V_164 ,
void * V_202 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_203 * V_204 ;
struct V_205 * V_206 = ( void * ) V_164 -> V_207 ;
if ( V_13 -> V_16 . V_80 < V_82 )
return 0 ;
if ( V_164 -> V_208 < 4 ||
V_164 -> V_208 < F_130 ( V_206 -> V_209 ) + 2 )
return 0 ;
V_204 = ( void * ) ( ( T_2 * ) V_164 -> V_207 + F_130 ( V_206 -> V_209 ) ) ;
return F_131 ( V_2 , V_164 , V_204 ) ;
}
static void F_132 ( struct V_39 * V_40 )
{
F_133 ( V_40 ) ;
V_40 -> V_210 &= ~ V_211 ;
V_40 -> V_212 = & V_213 ;
V_40 -> V_214 = V_215 ;
}
static void F_134 ( struct V_216 * V_185 )
{
struct V_1 * V_2 =
F_57 ( V_185 , struct V_1 , V_185 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_163 * V_164 ;
struct V_112 * V_113 ;
struct V_217 * V_218 ;
if ( ! F_28 ( V_2 ) )
return;
if ( V_13 -> V_23 )
return;
if ( F_135 ( V_13 -> V_179 ,
L_2 ) )
return;
while ( ( V_164 = F_136 ( & V_2 -> V_186 ) ) ) {
struct V_219 * V_220 = ( void * ) V_164 -> V_207 ;
if ( V_164 -> V_221 == V_222 ) {
V_218 = ( void * ) & V_164 -> V_223 ;
F_137 ( & V_2 -> V_6 , V_218 -> V_224 ,
V_218 -> V_225 ) ;
} else if ( V_164 -> V_221 == V_226 ) {
V_218 = ( void * ) & V_164 -> V_223 ;
F_138 ( & V_2 -> V_6 , V_218 -> V_224 ,
V_218 -> V_225 ) ;
} else if ( F_139 ( V_220 -> V_227 ) &&
V_220 -> V_57 . V_228 . V_229 == V_230 ) {
int V_208 = V_164 -> V_208 ;
F_24 ( & V_13 -> V_231 ) ;
V_113 = F_140 ( V_2 , V_220 -> V_61 ) ;
if ( V_113 ) {
switch ( V_220 -> V_57 . V_228 . V_57 . V_232 . V_233 ) {
case V_234 :
F_141 (
V_13 , V_113 , V_220 , V_208 ) ;
break;
case V_235 :
F_142 ( V_13 , V_113 ,
V_220 , V_208 ) ;
break;
case V_236 :
F_143 ( V_2 , V_113 ,
V_220 , V_208 ) ;
break;
default:
F_43 ( 1 ) ;
break;
}
}
F_25 ( & V_13 -> V_231 ) ;
} else if ( F_144 ( V_220 -> V_227 ) ) {
struct V_203 * V_204 = ( void * ) V_220 ;
F_43 ( V_204 -> V_227 &
F_145 ( V_237 ) ) ;
F_43 ( ! ( V_204 -> V_238 &
F_145 ( V_239 ) ) ) ;
F_24 ( & V_13 -> V_231 ) ;
V_113 = F_140 ( V_2 , V_220 -> V_61 ) ;
if ( V_113 ) {
T_6 V_225 = * F_146 ( V_204 ) &
V_240 ;
F_147 (
V_113 , V_225 , V_241 ,
V_242 ,
true ) ;
}
F_25 ( & V_13 -> V_231 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_126 :
F_148 ( V_2 , V_164 ) ;
break;
case V_74 :
F_149 ( V_2 , V_164 ) ;
break;
case V_86 :
if ( ! F_123 ( & V_2 -> V_6 ) )
break;
F_150 ( V_2 , V_164 ) ;
break;
default:
F_135 ( 1 , L_3 ) ;
break;
}
F_151 ( V_164 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_126 :
F_152 ( V_2 ) ;
break;
case V_74 :
F_153 ( V_2 ) ;
break;
case V_86 :
if ( ! F_123 ( & V_2 -> V_6 ) )
break;
F_154 ( V_2 ) ;
break;
default:
break;
}
}
static void F_155 ( struct V_216 * V_185 )
{
struct V_1 * V_2 =
F_57 ( V_185 , struct V_1 , V_175 ) ;
F_156 ( V_2 ) ;
}
static void F_157 ( struct V_1 * V_2 ,
enum V_71 type )
{
memset ( & V_2 -> V_57 , 0 , sizeof( V_2 -> V_57 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_243 = false ;
V_2 -> V_109 . V_72 = type ;
V_2 -> V_124 = F_158 ( V_244 ) ;
V_2 -> V_125 = false ;
V_2 -> V_245 = 0 ;
if ( V_2 -> V_40 ) {
V_2 -> V_40 -> V_212 = & V_213 ;
V_2 -> V_40 -> type = V_246 ;
}
F_159 ( & V_2 -> V_186 ) ;
F_160 ( & V_2 -> V_185 , F_134 ) ;
F_160 ( & V_2 -> V_175 , F_155 ) ;
F_160 ( & V_2 -> V_176 , V_247 ) ;
switch ( type ) {
case V_85 :
type = V_68 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_243 = true ;
case V_68 :
F_159 ( & V_2 -> V_57 . V_78 . V_167 . V_182 ) ;
F_161 ( & V_2 -> V_57 . V_78 . V_123 ) ;
F_160 ( & V_2 -> V_57 . V_78 . V_248 ,
V_249 ) ;
V_2 -> V_6 . V_11 . V_250 = V_2 -> V_6 . V_45 ;
V_2 -> V_57 . V_78 . V_251 = V_252 ;
break;
case V_129 :
type = V_126 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_243 = true ;
case V_126 :
V_2 -> V_6 . V_11 . V_250 = V_2 -> V_57 . V_253 . V_250 ;
F_162 ( V_2 ) ;
break;
case V_74 :
V_2 -> V_6 . V_11 . V_250 = V_2 -> V_57 . V_254 . V_250 ;
F_163 ( V_2 ) ;
break;
case V_86 :
if ( F_123 ( & V_2 -> V_6 ) )
F_164 ( V_2 ) ;
break;
case V_56 :
V_2 -> V_40 -> type = V_255 ;
V_2 -> V_40 -> V_212 = & V_256 ;
V_2 -> V_57 . V_58 = V_257 |
V_258 ;
break;
case V_69 :
V_2 -> V_6 . V_11 . V_250 = NULL ;
break;
case V_70 :
case V_67 :
V_2 -> V_6 . V_11 . V_250 = V_2 -> V_6 . V_45 ;
break;
case V_127 :
case V_128 :
F_165 () ;
break;
}
F_166 ( V_2 ) ;
}
static int F_167 ( struct V_1 * V_2 ,
enum V_71 type )
{
struct V_15 * V_13 = V_2 -> V_13 ;
int V_52 , V_161 ;
enum V_71 V_259 = type ;
bool V_243 = false ;
F_32 () ;
if ( ! V_13 -> V_32 -> V_260 )
return - V_62 ;
switch ( V_2 -> V_6 . type ) {
case V_68 :
case V_126 :
case V_74 :
break;
default:
return - V_62 ;
}
switch ( type ) {
case V_68 :
case V_126 :
case V_74 :
break;
case V_129 :
V_243 = true ;
V_259 = V_126 ;
break;
case V_85 :
V_243 = true ;
V_259 = V_68 ;
break;
default:
return - V_62 ;
}
V_52 = F_31 ( V_2 , V_259 ) ;
if ( V_52 )
return V_52 ;
F_84 ( V_2 , false ) ;
F_120 ( V_2 ) ;
V_52 = F_168 ( V_13 , V_2 , V_259 , V_243 ) ;
if ( V_52 )
type = F_65 ( & V_2 -> V_6 ) ;
F_34 ( V_2 , type ) ;
F_157 ( V_2 , type ) ;
V_161 = F_53 ( & V_2 -> V_109 , false ) ;
F_135 ( V_161 , L_4 , V_161 ) ;
return V_52 ;
}
int F_169 ( struct V_1 * V_2 ,
enum V_71 type )
{
int V_52 ;
F_32 () ;
if ( type == F_65 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_28 ( V_2 ) ) {
V_52 = F_167 ( V_2 , type ) ;
if ( V_52 )
return V_52 ;
} else {
F_120 ( V_2 ) ;
F_157 ( V_2 , type ) ;
}
V_2 -> V_261 = 0 ;
if ( type == V_126 )
V_2 -> V_57 . V_253 . V_262 = false ;
return 0 ;
}
static void F_170 ( struct V_15 * V_13 ,
T_2 * V_134 , enum V_71 type )
{
struct V_1 * V_2 ;
T_3 V_49 , V_263 , V_45 , V_264 , V_265 ;
T_2 * V_51 ;
T_2 V_266 [ V_64 ] ;
int V_81 ;
memcpy ( V_134 , V_13 -> V_16 . V_53 -> V_134 , V_64 ) ;
if ( F_23 ( V_13 -> V_16 . V_53 -> V_54 ) &&
V_13 -> V_16 . V_53 -> V_267 <= 1 )
return;
F_24 ( & V_13 -> V_55 ) ;
switch ( type ) {
case V_56 :
break;
case V_69 :
case V_70 :
F_16 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_68 )
continue;
memcpy ( V_134 , V_2 -> V_6 . V_45 , V_64 ) ;
break;
}
break;
case V_129 :
case V_85 :
if ( V_13 -> V_16 . V_18 & V_268 ) {
F_16 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_67 )
continue;
if ( ! F_28 ( V_2 ) )
continue;
memcpy ( V_134 , V_2 -> V_6 . V_45 , V_64 ) ;
goto V_269;
}
}
default:
for ( V_81 = 0 ; V_81 < V_13 -> V_16 . V_53 -> V_267 ; V_81 ++ ) {
bool V_270 = false ;
F_16 (sdata, &local->interfaces, list) {
if ( memcmp ( V_13 -> V_16 . V_53 -> V_271 [ V_81 ] . V_45 ,
V_2 -> V_6 . V_45 , V_64 ) == 0 ) {
V_270 = true ;
break;
}
}
if ( ! V_270 ) {
memcpy ( V_134 ,
V_13 -> V_16 . V_53 -> V_271 [ V_81 ] . V_45 ,
V_64 ) ;
break;
}
}
if ( F_23 ( V_13 -> V_16 . V_53 -> V_54 ) )
break;
V_51 = V_13 -> V_16 . V_53 -> V_54 ;
V_49 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
if ( F_171 ( V_49 ) + F_172 ( V_49 ) != F_173 ( V_49 ) ) {
F_174 ( L_5 ) ;
break;
}
V_51 = V_13 -> V_16 . V_53 -> V_134 ;
F_16 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_56 )
continue;
V_51 = V_2 -> V_6 . V_45 ;
break;
}
V_263 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
V_265 = 1ULL << F_171 ( V_49 ) ;
V_264 = ( V_263 & V_49 ) ;
V_45 = ( V_263 & ~ V_49 ) | ( V_264 & V_49 ) ;
do {
bool V_270 = false ;
V_266 [ 5 ] = V_45 >> 0 * 8 ;
V_266 [ 4 ] = V_45 >> 1 * 8 ;
V_266 [ 3 ] = V_45 >> 2 * 8 ;
V_266 [ 2 ] = V_45 >> 3 * 8 ;
V_266 [ 1 ] = V_45 >> 4 * 8 ;
V_266 [ 0 ] = V_45 >> 5 * 8 ;
V_264 += V_265 ;
F_16 (sdata, &local->interfaces, list) {
if ( memcmp ( V_266 , V_2 -> V_6 . V_45 ,
V_64 ) == 0 ) {
V_270 = true ;
break;
}
}
if ( ! V_270 ) {
memcpy ( V_134 , V_266 , V_64 ) ;
break;
}
V_45 = ( V_263 & ~ V_49 ) | ( V_264 & V_49 ) ;
} while ( V_45 != V_263 );
break;
}
V_269:
F_25 ( & V_13 -> V_55 ) ;
}
static void F_175 ( struct V_216 * V_272 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( V_272 , struct V_1 , V_273 ) ;
F_176 ( V_2 ) ;
}
int F_177 ( struct V_15 * V_13 , const char * V_104 ,
struct V_108 * * V_274 , enum V_71 type ,
struct V_275 * V_276 )
{
struct V_39 * V_277 = NULL ;
struct V_1 * V_2 = NULL ;
int V_52 , V_81 ;
int V_278 = 1 ;
F_32 () ;
if ( type == V_67 ) {
struct V_108 * V_109 ;
V_2 = F_40 ( sizeof( * V_2 ) + V_13 -> V_16 . V_101 ,
V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_109 = & V_2 -> V_109 ;
V_2 -> V_40 = NULL ;
F_178 ( V_2 -> V_104 , V_104 , V_105 ) ;
F_170 ( V_13 , V_109 -> V_279 , type ) ;
memcpy ( V_2 -> V_6 . V_45 , V_109 -> V_279 , V_64 ) ;
} else {
if ( V_13 -> V_16 . V_80 >= V_82 )
V_278 = V_82 ;
V_277 = F_179 ( sizeof( * V_2 ) +
V_13 -> V_16 . V_101 ,
V_104 , F_132 , V_278 , 1 ) ;
if ( ! V_277 )
return - V_103 ;
F_180 ( V_277 , F_181 ( V_13 -> V_16 . V_53 ) ) ;
V_277 -> V_280 = V_13 -> V_281 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_282
+ V_283 ;
V_277 -> V_284 = V_285 ;
V_52 = F_182 ( V_277 , V_277 -> V_104 ) ;
if ( V_52 < 0 ) {
V_215 ( V_277 ) ;
return V_52 ;
}
F_170 ( V_13 , V_277 -> V_134 , type ) ;
memcpy ( V_277 -> V_133 , V_277 -> V_134 , V_64 ) ;
F_183 ( V_277 , F_184 ( V_13 -> V_16 . V_53 ) ) ;
V_2 = F_185 ( V_277 ) ;
V_277 -> V_286 = & V_2 -> V_109 ;
memcpy ( V_2 -> V_6 . V_45 , V_277 -> V_133 , V_64 ) ;
memcpy ( V_2 -> V_104 , V_277 -> V_104 , V_105 ) ;
V_2 -> V_40 = V_277 ;
}
V_2 -> V_109 . V_53 = V_13 -> V_16 . V_53 ;
V_2 -> V_13 = V_13 ;
for ( V_81 = 0 ; V_81 < V_198 ; V_81 ++ )
F_159 ( & V_2 -> V_199 [ V_81 ] . V_200 ) ;
F_161 ( & V_2 -> V_287 ) ;
F_186 ( & V_2 -> V_288 ) ;
F_161 ( & V_2 -> V_289 ) ;
F_160 ( & V_2 -> V_273 , F_175 ) ;
F_187 ( & V_2 -> V_177 ,
V_290 ) ;
F_187 ( & V_2 -> V_291 ,
V_292 ) ;
for ( V_81 = 0 ; V_81 < V_293 ; V_81 ++ ) {
struct V_294 * V_295 ;
V_295 = V_13 -> V_16 . V_53 -> V_296 [ V_81 ] ;
V_2 -> V_297 [ V_81 ] =
V_295 ? ( 1 << V_295 -> V_298 ) - 1 : 0 ;
if ( V_295 )
memcpy ( V_2 -> V_299 [ V_81 ] ,
V_295 -> V_300 . V_301 . V_302 ,
sizeof( V_2 -> V_299 [ V_81 ] ) ) ;
else
memset ( V_2 -> V_299 [ V_81 ] , 0 ,
sizeof( V_2 -> V_299 [ V_81 ] ) ) ;
}
F_38 ( V_2 ) ;
V_2 -> V_10 = V_9 ;
V_2 -> V_8 = V_13 -> V_8 ;
F_157 ( V_2 , type ) ;
if ( V_277 ) {
if ( V_276 ) {
V_277 -> V_286 -> V_262 = V_276 -> V_262 ;
if ( type == V_126 )
V_2 -> V_57 . V_253 . V_262 = V_276 -> V_262 ;
}
V_277 -> V_303 |= V_13 -> V_16 . V_304 ;
V_52 = F_188 ( V_277 ) ;
if ( V_52 ) {
V_215 ( V_277 ) ;
return V_52 ;
}
}
F_24 ( & V_13 -> V_55 ) ;
F_189 ( & V_2 -> V_122 , & V_13 -> V_305 ) ;
F_25 ( & V_13 -> V_55 ) ;
if ( V_274 )
* V_274 = & V_2 -> V_109 ;
return 0 ;
}
void F_190 ( struct V_1 * V_2 )
{
F_32 () ;
F_24 ( & V_2 -> V_13 -> V_55 ) ;
F_191 ( & V_2 -> V_122 ) ;
F_25 ( & V_2 -> V_13 -> V_55 ) ;
F_107 () ;
if ( V_2 -> V_40 ) {
F_192 ( V_2 -> V_40 ) ;
} else {
F_193 ( & V_2 -> V_109 ) ;
F_44 ( V_2 ) ;
}
}
void F_194 ( struct V_1 * V_2 )
{
if ( F_35 ( ! F_17 ( V_145 , & V_2 -> V_146 ) ) )
return;
F_84 ( V_2 , true ) ;
F_120 ( V_2 ) ;
}
void F_195 ( struct V_15 * V_13 )
{
struct V_1 * V_2 , * V_50 ;
F_196 ( V_306 ) ;
F_196 ( V_307 ) ;
F_32 () ;
F_16 (sdata, &local->interfaces, list)
if ( V_2 -> V_6 . type == V_70 )
F_103 ( V_2 -> V_40 ) ;
F_24 ( & V_13 -> V_55 ) ;
F_102 (sdata, tmp, &local->interfaces, list) {
F_81 ( & V_2 -> V_122 ) ;
if ( V_2 -> V_40 )
F_197 ( V_2 -> V_40 , & V_306 ) ;
else
F_56 ( & V_2 -> V_122 , & V_307 ) ;
}
F_25 ( & V_13 -> V_55 ) ;
F_198 ( & V_306 ) ;
F_81 ( & V_306 ) ;
F_102 (sdata, tmp, &wdev_list, list) {
F_81 ( & V_2 -> V_122 ) ;
F_193 ( & V_2 -> V_109 ) ;
F_44 ( V_2 ) ;
}
}
static int F_199 ( struct V_308 * V_309 ,
unsigned long V_146 , void * V_310 )
{
struct V_39 * V_40 = F_200 ( V_310 ) ;
struct V_1 * V_2 ;
if ( V_146 != V_311 )
return 0 ;
if ( ! V_40 -> V_286 || ! V_40 -> V_286 -> V_53 )
return 0 ;
if ( V_40 -> V_286 -> V_53 -> V_312 != V_313 )
return 0 ;
V_2 = F_27 ( V_40 ) ;
memcpy ( V_2 -> V_104 , V_40 -> V_104 , V_105 ) ;
F_201 ( V_2 ) ;
return 0 ;
}
int F_202 ( void )
{
return F_203 ( & V_314 ) ;
}
void F_204 ( void )
{
F_205 ( & V_314 ) ;
}
