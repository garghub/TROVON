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
static T_1 F_9 ( struct V_17 * V_15 ,
const char * V_18 )
{
if ( ! ( V_15 -> V_19 . V_20 . V_21 & V_22 ) )
return 0 ;
V_15 -> V_19 . V_20 . V_21 &= ~ V_22 ;
return V_23 ;
}
static T_1 F_10 ( struct V_17 * V_15 )
{
if ( V_15 -> V_19 . V_20 . V_21 & V_22 )
return 0 ;
F_11 ( V_15 , false ) ;
V_15 -> V_19 . V_20 . V_21 |= V_22 ;
return V_23 ;
}
static T_1 F_12 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
bool V_25 = false , V_26 = false ;
unsigned int V_27 = 0 , V_28 = 0 ;
struct V_29 * V_30 ;
#ifdef F_13
F_14 ( V_31 && ! F_15 () &&
! F_16 ( & V_15 -> V_32 ) ) ;
#endif
F_17 ( & V_15 -> V_33 ) ;
F_18 (sdata, &local->interfaces, list) {
if ( ! F_19 ( V_2 ) ) {
V_2 -> V_6 . V_13 . V_34 = true ;
continue;
}
V_2 -> V_35 = V_2 -> V_6 . V_13 . V_34 ;
if ( V_2 -> V_6 . type == V_36 &&
! V_2 -> V_37 . V_38 . V_39 &&
! V_2 -> V_37 . V_38 . V_40 &&
! V_2 -> V_37 . V_38 . V_41 ) {
V_2 -> V_6 . V_13 . V_34 = true ;
continue;
}
if ( V_2 -> V_6 . type == V_42 &&
! V_2 -> V_37 . V_43 . V_44 ) {
V_2 -> V_6 . V_13 . V_34 = true ;
continue;
}
if ( V_2 -> V_6 . type == V_45 )
continue;
V_2 -> V_6 . V_13 . V_34 = false ;
V_24 ++ ;
}
if ( ! V_15 -> V_46 -> V_47 ) {
F_18 (roc, &local->roc_list, list) {
V_25 = true ;
V_30 -> V_2 -> V_6 . V_13 . V_34 = false ;
}
}
V_2 = F_20 ( V_15 -> V_48 ,
F_16 ( & V_15 -> V_33 ) ) ;
if ( V_2 && ! ( V_15 -> V_19 . V_21 & V_49 ) ) {
V_26 = true ;
V_2 -> V_6 . V_13 . V_34 = false ;
}
F_18 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_50 ||
V_2 -> V_6 . type == V_51 ||
V_2 -> V_6 . type == V_45 )
continue;
if ( V_2 -> V_35 == V_2 -> V_6 . V_13 . V_34 )
continue;
if ( ! F_19 ( V_2 ) )
continue;
F_8 ( V_2 , V_52 ) ;
}
if ( V_25 || V_26 )
V_27 |= V_53 ;
else
V_28 |= V_53 ;
if ( V_24 )
V_27 |= V_54 ;
else
V_28 |= V_54 ;
F_21 ( V_15 , V_27 , V_28 ) ;
if ( V_25 )
return F_9 ( V_15 , L_1 ) ;
if ( V_26 )
return F_9 ( V_15 , L_2 ) ;
if ( ! V_24 )
return F_10 ( V_15 ) ;
else
return F_9 ( V_15 , L_3 ) ;
return 0 ;
}
void F_22 ( struct V_17 * V_15 )
{
T_1 V_55 ;
F_23 ( & V_15 -> V_32 ) ;
V_55 = F_12 ( V_15 ) ;
F_24 ( & V_15 -> V_32 ) ;
if ( V_55 )
F_6 ( V_15 , V_55 ) ;
}
static int F_25 ( struct V_56 * V_57 , int V_58 )
{
if ( V_58 < 256 || V_58 > V_59 )
return - V_60 ;
V_57 -> V_61 = V_58 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_15 , T_2 * V_62 )
{
struct V_1 * V_2 ;
T_3 V_63 , V_64 , V_65 ;
T_2 * V_66 ;
int V_67 = 0 ;
if ( F_27 ( V_15 -> V_19 . V_68 -> V_69 ) )
return 0 ;
V_66 = V_62 ;
V_63 = ( ( T_3 ) V_66 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_66 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_66 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_66 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_66 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_66 [ 5 ] << 0 * 8 ) ;
V_66 = V_15 -> V_19 . V_68 -> V_69 ;
V_64 = ( ( T_3 ) V_66 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_66 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_66 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_66 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_66 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_66 [ 5 ] << 0 * 8 ) ;
F_23 ( & V_15 -> V_32 ) ;
F_18 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_50 )
continue;
V_66 = V_2 -> V_6 . V_62 ;
V_65 = ( ( T_3 ) V_66 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_66 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_66 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_66 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_66 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_66 [ 5 ] << 0 * 8 ) ;
if ( ( V_63 & ~ V_64 ) != ( V_65 & ~ V_64 ) ) {
V_67 = - V_60 ;
break;
}
}
F_24 ( & V_15 -> V_32 ) ;
return V_67 ;
}
static int F_28 ( struct V_56 * V_57 , void * V_62 )
{
struct V_1 * V_2 = F_29 ( V_57 ) ;
struct V_70 * V_71 = V_62 ;
int V_67 ;
if ( F_19 ( V_2 ) )
return - V_72 ;
V_67 = F_26 ( V_2 -> V_15 , V_71 -> V_73 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_30 ( V_57 , V_71 ) ;
if ( V_67 == 0 )
memcpy ( V_2 -> V_6 . V_62 , V_71 -> V_73 , V_74 ) ;
return V_67 ;
}
static inline int F_31 ( int V_75 , int V_76 )
{
return V_75 == V_50 ||
V_76 == V_50 ||
V_75 == V_45 ||
V_76 == V_45 ||
( V_75 == V_77 && V_76 == V_78 ) ||
( V_75 == V_78 &&
( V_76 == V_78 ||
V_76 == V_77 ) ) ||
( V_75 == V_77 && V_76 == V_51 ) ||
( V_75 == V_51 &&
( V_76 == V_77 ||
V_76 == V_51 ) ) ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_1 * V_81 ;
F_33 () ;
F_18 (nsdata, &local->interfaces, list) {
if ( V_81 != V_2 && F_19 ( V_81 ) ) {
if ( V_80 == V_42 &&
V_81 -> V_6 . type == V_42 )
return - V_72 ;
if ( ! F_34 ( V_2 -> V_6 . V_62 ,
V_81 -> V_6 . V_62 ) )
continue;
if ( ! F_31 ( V_80 ,
V_81 -> V_6 . type ) )
return - V_82 ;
if ( V_80 == V_51 &&
V_81 -> V_6 . type == V_77 )
V_2 -> V_83 = & V_81 -> V_37 . V_84 ;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_85 = V_2 -> V_15 -> V_19 . V_86 ;
int V_87 ;
if ( V_2 -> V_6 . type != V_45 ) {
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
if ( F_36 ( V_2 -> V_6 . V_89 [ V_87 ] ==
V_90 ) )
return - V_60 ;
if ( F_36 ( V_2 -> V_6 . V_89 [ V_87 ] >=
V_85 ) )
return - V_60 ;
}
}
if ( ( V_2 -> V_6 . type != V_77 ) ||
! ( V_2 -> V_15 -> V_19 . V_21 & V_91 ) ) {
V_2 -> V_6 . V_92 = V_90 ;
return 0 ;
}
if ( F_36 ( V_2 -> V_6 . V_92 == V_90 ) )
return - V_60 ;
if ( F_36 ( V_2 -> V_6 . V_92 >= V_85 ) )
return - V_60 ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 ,
const int V_93 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
T_1 V_21 = V_2 -> V_37 . V_94 ;
#define F_38 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_38 ( V_95 , V_96 ) ;
F_38 ( V_97 , V_98 ) ;
F_38 ( V_99 , V_100 ) ;
F_38 ( V_99 , V_101 ) ;
F_38 ( V_102 , V_103 ) ;
#undef F_38
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
if ( V_15 -> V_19 . V_21 & V_91 )
V_2 -> V_6 . V_89 [ V_87 ] = V_90 ;
else if ( V_15 -> V_19 . V_86 >= V_88 )
V_2 -> V_6 . V_89 [ V_87 ] = V_87 ;
else
V_2 -> V_6 . V_89 [ V_87 ] = 0 ;
}
V_2 -> V_6 . V_92 = V_90 ;
}
static int F_40 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
int V_67 = 0 ;
if ( ! ( V_15 -> V_19 . V_21 & V_104 ) )
return 0 ;
F_23 ( & V_15 -> V_32 ) ;
if ( V_15 -> V_105 )
goto V_106;
V_2 = F_41 ( sizeof( * V_2 ) + V_15 -> V_19 . V_107 , V_108 ) ;
if ( ! V_2 ) {
V_67 = - V_109 ;
goto V_106;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_6 . type = V_50 ;
snprintf ( V_2 -> V_110 , V_111 , L_4 ,
F_42 ( V_15 -> V_19 . V_68 ) ) ;
F_39 ( V_2 ) ;
V_67 = F_43 ( V_15 , V_2 ) ;
if ( F_14 ( V_67 ) ) {
F_44 ( V_2 ) ;
goto V_106;
}
V_67 = F_35 ( V_2 ) ;
if ( V_67 ) {
F_44 ( V_2 ) ;
goto V_106;
}
V_67 = F_45 ( V_2 , & V_15 -> V_112 ,
V_113 ) ;
if ( V_67 ) {
F_46 ( V_15 , V_2 ) ;
F_44 ( V_2 ) ;
goto V_106;
}
F_47 ( V_15 -> V_105 , V_2 ) ;
V_106:
F_24 ( & V_15 -> V_32 ) ;
return V_67 ;
}
static void F_48 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
if ( ! ( V_15 -> V_19 . V_21 & V_104 ) )
return;
F_23 ( & V_15 -> V_32 ) ;
V_2 = F_20 ( V_15 -> V_105 ,
F_16 ( & V_15 -> V_32 ) ) ;
if ( ! V_2 )
goto V_106;
F_47 ( V_15 -> V_105 , NULL ) ;
F_49 () ;
F_50 ( V_2 ) ;
F_46 ( V_15 , V_2 ) ;
F_44 ( V_2 ) ;
V_106:
F_24 ( & V_15 -> V_32 ) ;
}
int F_51 ( struct V_114 * V_115 , bool V_116 )
{
struct V_1 * V_2 = F_52 ( V_115 ) ;
struct V_56 * V_57 = V_115 -> V_117 ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_118 * V_119 ;
T_1 V_120 = 0 ;
int V_121 ;
T_1 V_122 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_78 :
if ( ! F_53 ( V_2 -> V_37 . V_123 . V_124 ) )
return - V_125 ;
break;
case V_51 : {
struct V_1 * V_126 ;
if ( ! V_2 -> V_83 )
return - V_125 ;
F_54 ( & V_2 -> V_37 . V_127 . V_128 , & V_2 -> V_83 -> V_129 ) ;
V_126 = F_55 ( V_2 -> V_83 ,
struct V_1 , V_37 . V_84 ) ;
V_2 -> V_130 =
V_126 -> V_130 ;
V_2 -> V_131 =
V_126 -> V_131 ;
break;
}
case V_77 :
V_2 -> V_83 = & V_2 -> V_37 . V_84 ;
break;
case V_132 :
case V_36 :
case V_50 :
case V_42 :
case V_45 :
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
F_14 ( 1 ) ;
break;
}
if ( V_15 -> V_137 == 0 ) {
V_121 = F_56 ( V_15 ) ;
if ( V_121 )
goto V_138;
if ( V_15 -> V_46 -> V_139 )
F_57 ( & V_15 -> V_140 ) ;
V_122 = ~ 0 ;
F_58 ( V_15 , true ) ;
F_21 ( V_15 ,
V_141 , 0 ) ;
}
if ( V_57 && F_27 ( V_57 -> V_142 ) ) {
memcpy ( V_57 -> V_142 ,
V_15 -> V_19 . V_68 -> V_143 ,
V_74 ) ;
memcpy ( V_57 -> V_143 , V_57 -> V_142 , V_74 ) ;
if ( ! F_53 ( V_57 -> V_142 ) ) {
V_121 = - V_144 ;
goto V_145;
}
}
switch ( V_2 -> V_6 . type ) {
case V_51 :
if ( F_59 ( V_2 -> V_83 -> V_146 ) ) {
F_60 ( V_2 ) ;
F_61 ( V_57 ) ;
} else {
F_62 ( V_57 ) ;
}
break;
case V_50 :
if ( V_2 -> V_37 . V_94 & V_147 ) {
V_15 -> V_148 ++ ;
break;
}
if ( V_15 -> V_149 == 0 && V_15 -> V_137 == 0 ) {
V_121 = F_40 ( V_15 ) ;
if ( V_121 )
goto V_145;
}
V_15 -> V_149 ++ ;
if ( V_15 -> V_149 == 1 ) {
V_15 -> V_19 . V_20 . V_21 |= V_150 ;
V_122 |= V_151 ;
}
F_37 ( V_2 , 1 ) ;
F_63 ( V_15 ) ;
F_61 ( V_57 ) ;
break;
default:
if ( V_116 ) {
F_48 ( V_15 ) ;
V_121 = F_43 ( V_15 , V_2 ) ;
if ( V_121 )
goto V_145;
V_121 = F_35 ( V_2 ) ;
if ( V_121 )
goto V_152;
}
if ( V_2 -> V_6 . type == V_77 ) {
V_15 -> V_153 ++ ;
V_15 -> V_154 ++ ;
F_63 ( V_15 ) ;
} else if ( V_2 -> V_6 . type == V_42 ) {
V_15 -> V_154 ++ ;
}
if ( V_2 -> V_6 . type != V_45 )
V_120 |= F_64 ( V_2 ) ;
F_8 ( V_2 , V_120 ) ;
switch ( V_2 -> V_6 . type ) {
case V_36 :
case V_42 :
case V_77 :
case V_132 :
F_62 ( V_57 ) ;
break;
case V_78 :
case V_45 :
break;
default:
F_61 ( V_57 ) ;
}
F_65 ( V_2 , true ) ;
}
F_66 ( V_155 , & V_2 -> V_156 ) ;
if ( V_2 -> V_6 . type == V_78 ) {
V_119 = F_67 ( V_2 , V_2 -> V_37 . V_123 . V_124 ,
V_108 ) ;
if ( ! V_119 ) {
V_121 = - V_109 ;
goto V_152;
}
F_68 ( V_119 , V_157 ) ;
F_68 ( V_119 , V_158 ) ;
F_68 ( V_119 , V_159 ) ;
V_121 = F_69 ( V_119 ) ;
if ( V_121 ) {
goto V_152;
}
F_70 ( V_119 ) ;
F_61 ( V_57 ) ;
} else if ( V_2 -> V_6 . type == V_45 ) {
F_47 ( V_15 -> V_160 , V_2 ) ;
}
if ( V_2 -> V_21 & V_161 )
F_71 ( & V_15 -> V_162 ) ;
if ( V_2 -> V_21 & V_163 )
F_71 ( & V_15 -> V_164 ) ;
F_23 ( & V_15 -> V_33 ) ;
V_122 |= F_12 ( V_15 ) ;
F_24 ( & V_15 -> V_33 ) ;
if ( V_116 )
V_15 -> V_137 ++ ;
if ( V_122 )
F_6 ( V_15 , V_122 ) ;
F_72 ( V_15 , - 1 ) ;
if ( V_57 )
F_73 ( V_57 ) ;
return 0 ;
V_152:
F_46 ( V_15 , V_2 ) ;
V_145:
if ( ! V_15 -> V_137 )
F_74 ( V_15 ) ;
V_138:
V_2 -> V_83 = NULL ;
if ( V_2 -> V_6 . type == V_51 )
F_75 ( & V_2 -> V_37 . V_127 . V_128 ) ;
F_76 ( V_155 , & V_2 -> V_156 ) ;
return V_121 ;
}
static int F_77 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_29 ( V_57 ) ;
int V_165 ;
if ( ! F_53 ( V_57 -> V_142 ) )
return - V_144 ;
V_165 = F_32 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_165 )
return V_165 ;
return F_51 ( & V_2 -> V_115 , true ) ;
}
static void F_78 ( struct V_1 * V_2 ,
bool V_166 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
unsigned long V_21 ;
struct V_167 * V_168 , * V_65 ;
T_1 V_122 = 0 ;
int V_87 ;
F_76 ( V_155 , & V_2 -> V_156 ) ;
if ( F_79 ( V_15 -> V_48 ) == V_2 )
F_80 ( V_15 ) ;
if ( V_2 -> V_57 )
F_81 ( V_2 -> V_57 ) ;
F_82 ( V_2 ) ;
F_83 ( V_15 , V_2 ) ;
if ( V_2 -> V_21 & V_161 )
F_84 ( & V_15 -> V_162 ) ;
if ( V_2 -> V_21 & V_163 )
F_84 ( & V_15 -> V_164 ) ;
if ( V_2 -> V_6 . type == V_77 ) {
V_15 -> V_153 -- ;
V_15 -> V_154 -- ;
} else if ( V_2 -> V_6 . type == V_42 ) {
V_15 -> V_154 -- ;
}
if ( V_2 -> V_57 ) {
F_85 ( V_2 -> V_57 ) ;
F_86 ( & V_15 -> V_169 ) ;
F_87 ( & V_15 -> V_170 , & V_2 -> V_57 -> V_171 ,
V_2 -> V_57 -> V_172 ) ;
F_88 ( & V_15 -> V_169 ) ;
F_89 ( V_2 -> V_57 ) ;
F_63 ( V_15 ) ;
}
F_90 ( & V_15 -> V_173 ) ;
F_91 ( & V_15 -> V_174 ) ;
F_91 ( & V_2 -> V_175 ) ;
if ( V_2 -> V_6 . type == V_77 ) {
struct V_1 * V_127 , * V_176 ;
F_92 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_93 ( V_127 -> V_57 ) ;
F_14 ( ! F_94 ( & V_2 -> V_37 . V_84 . V_129 ) ) ;
} else if ( V_2 -> V_6 . type == V_36 ) {
F_95 ( V_2 ) ;
}
if ( V_166 )
V_15 -> V_137 -- ;
switch ( V_2 -> V_6 . type ) {
case V_51 :
F_75 ( & V_2 -> V_37 . V_127 . V_128 ) ;
F_47 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_50 :
if ( V_2 -> V_37 . V_94 & V_147 ) {
V_15 -> V_148 -- ;
break;
}
V_15 -> V_149 -- ;
if ( V_15 -> V_149 == 0 ) {
V_15 -> V_19 . V_20 . V_21 &= ~ V_150 ;
V_122 |= V_151 ;
F_48 ( V_15 ) ;
}
F_37 ( V_2 , - 1 ) ;
F_63 ( V_15 ) ;
break;
case V_45 :
F_47 ( V_15 -> V_160 , NULL ) ;
default:
F_91 ( & V_2 -> V_177 ) ;
F_96 () ;
F_97 ( & V_2 -> V_178 ) ;
F_98 ( V_2 ) ;
if ( V_166 )
F_46 ( V_15 , V_2 ) ;
}
V_2 -> V_83 = NULL ;
F_23 ( & V_15 -> V_33 ) ;
V_122 |= F_12 ( V_15 ) ;
F_24 ( & V_15 -> V_33 ) ;
F_72 ( V_15 , - 1 ) ;
if ( V_15 -> V_137 == 0 ) {
if ( V_15 -> V_46 -> V_139 )
F_99 ( & V_15 -> V_140 ) ;
F_100 ( V_15 ) ;
F_101 ( V_15 ) ;
V_122 = 0 ;
}
if ( V_122 )
F_6 ( V_15 , V_122 ) ;
F_102 ( & V_15 -> V_179 , V_21 ) ;
for ( V_87 = 0 ; V_87 < V_180 ; V_87 ++ ) {
F_103 (&local->pending[i], skb, tmp) {
struct V_181 * V_182 = F_104 ( V_168 ) ;
if ( V_182 -> V_100 . V_6 == & V_2 -> V_6 ) {
F_105 ( V_168 , & V_15 -> V_183 [ V_87 ] ) ;
F_106 ( & V_15 -> V_19 , V_168 ) ;
}
}
}
F_107 ( & V_15 -> V_179 , V_21 ) ;
if ( V_15 -> V_149 == V_15 -> V_137 && V_15 -> V_149 > 0 )
F_40 ( V_15 ) ;
}
static int F_108 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_29 ( V_57 ) ;
F_78 ( V_2 , true ) ;
return 0 ;
}
static void F_109 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_29 ( V_57 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
int V_184 , V_185 , V_186 , V_187 ;
V_184 = ! ! ( V_57 -> V_21 & V_188 ) ;
V_185 = ! ! ( V_57 -> V_21 & V_189 ) ;
V_186 = ! ! ( V_2 -> V_21 & V_161 ) ;
V_187 = ! ! ( V_2 -> V_21 & V_163 ) ;
if ( V_184 != V_186 ) {
if ( V_57 -> V_21 & V_188 )
F_71 ( & V_15 -> V_162 ) ;
else
F_84 ( & V_15 -> V_162 ) ;
V_2 -> V_21 ^= V_161 ;
}
if ( V_185 != V_187 ) {
if ( V_57 -> V_21 & V_189 )
F_71 ( & V_15 -> V_164 ) ;
else
F_84 ( & V_15 -> V_164 ) ;
V_2 -> V_21 ^= V_163 ;
}
F_86 ( & V_15 -> V_169 ) ;
F_110 ( & V_15 -> V_170 , & V_57 -> V_171 , V_57 -> V_172 ) ;
F_88 ( & V_15 -> V_169 ) ;
F_111 ( & V_15 -> V_19 , & V_15 -> V_190 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_191 ;
int V_87 ;
F_98 ( V_2 ) ;
F_113 ( V_2 ) ;
for ( V_87 = 0 ; V_87 < V_192 ; V_87 ++ )
F_114 ( & V_2 -> V_193 [ V_87 ] . V_194 ) ;
V_2 -> V_195 = 0 ;
if ( F_115 ( & V_2 -> V_6 ) )
F_116 ( V_2 ) ;
V_191 = F_83 ( V_15 , V_2 ) ;
F_14 ( V_191 ) ;
}
static void F_117 ( struct V_56 * V_57 )
{
F_112 ( F_29 ( V_57 ) ) ;
}
static T_6 F_118 ( struct V_56 * V_57 ,
struct V_167 * V_168 )
{
return F_119 ( F_29 ( V_57 ) , V_168 ) ;
}
static T_6 F_120 ( struct V_56 * V_57 ,
struct V_167 * V_168 )
{
struct V_1 * V_2 = F_29 ( V_57 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_196 * V_197 ;
struct V_198 * V_199 = ( void * ) V_168 -> V_200 ;
if ( V_15 -> V_19 . V_86 < V_88 )
return 0 ;
if ( V_168 -> V_201 < 4 ||
V_168 -> V_201 < F_121 ( V_199 -> V_202 ) + 2 )
return 0 ;
V_197 = ( void * ) ( ( T_2 * ) V_168 -> V_200 + F_121 ( V_199 -> V_202 ) ) ;
return F_122 ( V_2 , V_168 , V_197 ) ;
}
static void F_123 ( struct V_56 * V_57 )
{
F_124 ( V_57 ) ;
V_57 -> V_203 &= ~ V_204 ;
V_57 -> V_205 = & V_206 ;
V_57 -> V_207 = V_208 ;
}
static void F_125 ( struct V_209 * V_177 )
{
struct V_1 * V_2 =
F_55 ( V_177 , struct V_1 , V_177 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_167 * V_168 ;
struct V_118 * V_119 ;
struct V_210 * V_211 ;
if ( ! F_19 ( V_2 ) )
return;
if ( V_15 -> V_26 )
return;
if ( F_126 ( V_15 -> V_212 ,
L_5 ) )
return;
while ( ( V_168 = F_127 ( & V_2 -> V_178 ) ) ) {
struct V_213 * V_214 = ( void * ) V_168 -> V_200 ;
if ( V_168 -> V_215 == V_216 ) {
V_211 = ( void * ) & V_168 -> V_217 ;
F_128 ( & V_2 -> V_6 , V_211 -> V_218 ,
V_211 -> V_219 ) ;
} else if ( V_168 -> V_215 == V_220 ) {
V_211 = ( void * ) & V_168 -> V_217 ;
F_129 ( & V_2 -> V_6 , V_211 -> V_218 ,
V_211 -> V_219 ) ;
} else if ( F_130 ( V_214 -> V_221 ) &&
V_214 -> V_37 . V_222 . V_223 == V_224 ) {
int V_201 = V_168 -> V_201 ;
F_23 ( & V_15 -> V_225 ) ;
V_119 = F_131 ( V_2 , V_214 -> V_71 ) ;
if ( V_119 ) {
switch ( V_214 -> V_37 . V_222 . V_37 . V_226 . V_227 ) {
case V_228 :
F_132 (
V_15 , V_119 , V_214 , V_201 ) ;
break;
case V_229 :
F_133 ( V_15 , V_119 ,
V_214 , V_201 ) ;
break;
case V_230 :
F_134 ( V_2 , V_119 ,
V_214 , V_201 ) ;
break;
default:
F_14 ( 1 ) ;
break;
}
}
F_24 ( & V_15 -> V_225 ) ;
} else if ( F_135 ( V_214 -> V_221 ) ) {
struct V_196 * V_197 = ( void * ) V_214 ;
F_14 ( V_197 -> V_221 &
F_136 ( V_231 ) ) ;
F_14 ( ! ( V_197 -> V_232 &
F_136 ( V_233 ) ) ) ;
F_23 ( & V_15 -> V_225 ) ;
V_119 = F_131 ( V_2 , V_214 -> V_71 ) ;
if ( V_119 ) {
T_6 V_219 = * F_137 ( V_197 ) &
V_234 ;
F_138 (
V_119 , V_219 , V_235 ,
V_236 ,
true ) ;
}
F_24 ( & V_15 -> V_225 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_36 :
F_139 ( V_2 , V_168 ) ;
break;
case V_42 :
F_140 ( V_2 , V_168 ) ;
break;
case V_132 :
if ( ! F_115 ( & V_2 -> V_6 ) )
break;
F_141 ( V_2 , V_168 ) ;
break;
default:
F_126 ( 1 , L_6 ) ;
break;
}
F_142 ( V_168 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_36 :
F_143 ( V_2 ) ;
break;
case V_42 :
F_144 ( V_2 ) ;
break;
case V_132 :
if ( ! F_115 ( & V_2 -> V_6 ) )
break;
F_145 ( V_2 ) ;
break;
default:
break;
}
}
static void F_146 ( struct V_209 * V_177 )
{
struct V_1 * V_2 =
F_55 ( V_177 , struct V_1 , V_175 ) ;
F_147 ( V_2 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
enum V_79 type )
{
memset ( & V_2 -> V_37 , 0 , sizeof( V_2 -> V_37 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_237 = false ;
V_2 -> V_115 . V_80 = type ;
V_2 -> V_130 = F_149 ( V_238 ) ;
V_2 -> V_131 = false ;
V_2 -> V_239 = 0 ;
if ( V_2 -> V_57 ) {
V_2 -> V_57 -> V_205 = & V_206 ;
V_2 -> V_57 -> type = V_240 ;
}
F_150 ( & V_2 -> V_178 ) ;
F_151 ( & V_2 -> V_177 , F_125 ) ;
F_151 ( & V_2 -> V_175 , F_146 ) ;
switch ( type ) {
case V_136 :
type = V_77 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_237 = true ;
case V_77 :
F_150 ( & V_2 -> V_37 . V_84 . V_241 . V_242 ) ;
F_152 ( & V_2 -> V_37 . V_84 . V_129 ) ;
break;
case V_135 :
type = V_36 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_237 = true ;
case V_36 :
F_153 ( V_2 ) ;
break;
case V_42 :
F_154 ( V_2 ) ;
break;
case V_132 :
if ( F_115 ( & V_2 -> V_6 ) )
F_155 ( V_2 ) ;
break;
case V_50 :
V_2 -> V_57 -> type = V_243 ;
V_2 -> V_57 -> V_205 = & V_244 ;
V_2 -> V_37 . V_94 = V_245 |
V_246 ;
break;
case V_78 :
case V_51 :
case V_45 :
break;
case V_133 :
case V_134 :
F_156 () ;
break;
}
F_157 ( V_2 ) ;
}
static int F_158 ( struct V_1 * V_2 ,
enum V_79 type )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_67 , V_165 ;
enum V_79 V_247 = type ;
bool V_237 = false ;
F_33 () ;
if ( ! V_15 -> V_46 -> V_248 )
return - V_72 ;
switch ( V_2 -> V_6 . type ) {
case V_77 :
case V_36 :
case V_42 :
break;
default:
return - V_72 ;
}
switch ( type ) {
case V_77 :
case V_36 :
case V_42 :
break;
case V_135 :
V_237 = true ;
V_247 = V_36 ;
break;
case V_136 :
V_237 = true ;
V_247 = V_77 ;
break;
default:
return - V_72 ;
}
V_67 = F_32 ( V_2 , V_247 ) ;
if ( V_67 )
return V_67 ;
F_78 ( V_2 , false ) ;
F_112 ( V_2 ) ;
V_67 = F_159 ( V_15 , V_2 , V_247 , V_237 ) ;
if ( V_67 )
type = V_2 -> V_6 . type ;
F_35 ( V_2 ) ;
F_148 ( V_2 , type ) ;
V_165 = F_51 ( & V_2 -> V_115 , false ) ;
F_126 ( V_165 , L_7 , V_165 ) ;
return V_67 ;
}
int F_160 ( struct V_1 * V_2 ,
enum V_79 type )
{
int V_67 ;
F_33 () ;
if ( type == F_161 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_19 ( V_2 ) ) {
V_67 = F_158 ( V_2 , type ) ;
if ( V_67 )
return V_67 ;
} else {
F_112 ( V_2 ) ;
F_148 ( V_2 , type ) ;
}
V_2 -> V_249 = 0 ;
if ( type == V_36 )
V_2 -> V_37 . V_38 . V_250 = false ;
return 0 ;
}
static void F_162 ( struct V_17 * V_15 ,
T_2 * V_143 , enum V_79 type )
{
struct V_1 * V_2 ;
T_3 V_64 , V_251 , V_62 , V_252 , V_253 ;
T_2 * V_66 ;
T_2 V_254 [ V_74 ] ;
int V_87 ;
memcpy ( V_143 , V_15 -> V_19 . V_68 -> V_143 , V_74 ) ;
if ( F_27 ( V_15 -> V_19 . V_68 -> V_69 ) &&
V_15 -> V_19 . V_68 -> V_255 <= 1 )
return;
F_23 ( & V_15 -> V_32 ) ;
switch ( type ) {
case V_50 :
break;
case V_78 :
case V_51 :
F_18 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_77 )
continue;
memcpy ( V_143 , V_2 -> V_6 . V_62 , V_74 ) ;
break;
}
break;
case V_135 :
case V_136 :
if ( V_15 -> V_19 . V_21 & V_256 ) {
F_18 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_45 )
continue;
if ( ! F_19 ( V_2 ) )
continue;
memcpy ( V_143 , V_2 -> V_6 . V_62 , V_74 ) ;
goto V_106;
}
}
default:
for ( V_87 = 0 ; V_87 < V_15 -> V_19 . V_68 -> V_255 ; V_87 ++ ) {
bool V_257 = false ;
F_18 (sdata, &local->interfaces, list) {
if ( memcmp ( V_15 -> V_19 . V_68 -> V_258 [ V_87 ] . V_62 ,
V_2 -> V_6 . V_62 , V_74 ) == 0 ) {
V_257 = true ;
break;
}
}
if ( ! V_257 ) {
memcpy ( V_143 ,
V_15 -> V_19 . V_68 -> V_258 [ V_87 ] . V_62 ,
V_74 ) ;
break;
}
}
if ( F_27 ( V_15 -> V_19 . V_68 -> V_69 ) )
break;
V_66 = V_15 -> V_19 . V_68 -> V_69 ;
V_64 = ( ( T_3 ) V_66 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_66 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_66 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_66 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_66 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_66 [ 5 ] << 0 * 8 ) ;
if ( F_163 ( V_64 ) + F_164 ( V_64 ) != F_165 ( V_64 ) ) {
F_166 ( L_8 ) ;
break;
}
V_66 = V_15 -> V_19 . V_68 -> V_143 ;
V_251 = ( ( T_3 ) V_66 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_66 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_66 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_66 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_66 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_66 [ 5 ] << 0 * 8 ) ;
V_253 = 1ULL << F_163 ( V_64 ) ;
V_252 = ( V_251 & V_64 ) ;
V_62 = ( V_251 & ~ V_64 ) | ( V_252 & V_64 ) ;
do {
bool V_257 = false ;
V_254 [ 5 ] = V_62 >> 0 * 8 ;
V_254 [ 4 ] = V_62 >> 1 * 8 ;
V_254 [ 3 ] = V_62 >> 2 * 8 ;
V_254 [ 2 ] = V_62 >> 3 * 8 ;
V_254 [ 1 ] = V_62 >> 4 * 8 ;
V_254 [ 0 ] = V_62 >> 5 * 8 ;
V_252 += V_253 ;
F_18 (sdata, &local->interfaces, list) {
if ( memcmp ( V_254 , V_2 -> V_6 . V_62 ,
V_74 ) == 0 ) {
V_257 = true ;
break;
}
}
if ( ! V_257 ) {
memcpy ( V_143 , V_254 , V_74 ) ;
break;
}
V_62 = ( V_251 & ~ V_64 ) | ( V_252 & V_64 ) ;
} while ( V_62 != V_251 );
break;
}
V_106:
F_24 ( & V_15 -> V_32 ) ;
}
static void F_167 ( struct V_209 * V_259 )
{
struct V_1 * V_2 ;
V_2 = F_55 ( V_259 , struct V_1 , V_260 ) ;
F_168 ( V_2 ) ;
}
int F_169 ( struct V_17 * V_15 , const char * V_110 ,
struct V_114 * * V_261 , enum V_79 type ,
struct V_262 * V_263 )
{
struct V_56 * V_264 = NULL ;
struct V_1 * V_2 = NULL ;
int V_67 , V_87 ;
int V_265 = 1 ;
F_33 () ;
if ( type == V_45 ) {
struct V_114 * V_115 ;
V_2 = F_41 ( sizeof( * V_2 ) + V_15 -> V_19 . V_107 ,
V_108 ) ;
if ( ! V_2 )
return - V_109 ;
V_115 = & V_2 -> V_115 ;
V_2 -> V_57 = NULL ;
F_170 ( V_2 -> V_110 , V_110 , V_111 ) ;
F_162 ( V_15 , V_115 -> V_266 , type ) ;
memcpy ( V_2 -> V_6 . V_62 , V_115 -> V_266 , V_74 ) ;
} else {
if ( V_15 -> V_19 . V_86 >= V_88 )
V_265 = V_88 ;
V_264 = F_171 ( sizeof( * V_2 ) +
V_15 -> V_19 . V_107 ,
V_110 , F_123 , V_265 , 1 ) ;
if ( ! V_264 )
return - V_109 ;
F_172 ( V_264 , F_173 ( V_15 -> V_19 . V_68 ) ) ;
V_264 -> V_267 = V_15 -> V_268 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_269
+ V_270 ;
V_264 -> V_271 = V_272 ;
V_67 = F_174 ( V_264 , V_264 -> V_110 ) ;
if ( V_67 < 0 ) {
V_208 ( V_264 ) ;
return V_67 ;
}
F_162 ( V_15 , V_264 -> V_143 , type ) ;
memcpy ( V_264 -> V_142 , V_264 -> V_143 , V_74 ) ;
F_175 ( V_264 , F_176 ( V_15 -> V_19 . V_68 ) ) ;
V_2 = F_177 ( V_264 ) ;
V_264 -> V_273 = & V_2 -> V_115 ;
memcpy ( V_2 -> V_6 . V_62 , V_264 -> V_142 , V_74 ) ;
memcpy ( V_2 -> V_110 , V_264 -> V_110 , V_111 ) ;
V_2 -> V_57 = V_264 ;
}
V_2 -> V_115 . V_68 = V_15 -> V_19 . V_68 ;
V_2 -> V_15 = V_15 ;
#ifdef F_178
V_2 -> V_274 = true ;
#endif
for ( V_87 = 0 ; V_87 < V_192 ; V_87 ++ )
F_150 ( & V_2 -> V_193 [ V_87 ] . V_194 ) ;
F_152 ( & V_2 -> V_275 ) ;
F_179 ( & V_2 -> V_276 ) ;
F_152 ( & V_2 -> V_277 ) ;
F_151 ( & V_2 -> V_260 , F_167 ) ;
for ( V_87 = 0 ; V_87 < V_278 ; V_87 ++ ) {
struct V_279 * V_280 ;
V_280 = V_15 -> V_19 . V_68 -> V_281 [ V_87 ] ;
V_2 -> V_282 [ V_87 ] =
V_280 ? ( 1 << V_280 -> V_283 ) - 1 : 0 ;
if ( V_280 )
memcpy ( V_2 -> V_284 [ V_87 ] ,
V_280 -> V_285 . V_286 . V_287 ,
sizeof( V_2 -> V_284 [ V_87 ] ) ) ;
else
memset ( V_2 -> V_284 [ V_87 ] , 0 ,
sizeof( V_2 -> V_284 [ V_87 ] ) ) ;
}
F_39 ( V_2 ) ;
V_2 -> V_12 = V_11 ;
V_2 -> V_10 = V_15 -> V_10 ;
F_148 ( V_2 , type ) ;
if ( V_264 ) {
if ( V_263 ) {
V_264 -> V_273 -> V_250 = V_263 -> V_250 ;
if ( type == V_36 )
V_2 -> V_37 . V_38 . V_250 = V_263 -> V_250 ;
}
V_264 -> V_288 |= V_15 -> V_19 . V_289 ;
V_67 = F_180 ( V_264 ) ;
if ( V_67 ) {
V_208 ( V_264 ) ;
return V_67 ;
}
}
F_23 ( & V_15 -> V_32 ) ;
F_181 ( & V_2 -> V_128 , & V_15 -> V_290 ) ;
F_24 ( & V_15 -> V_32 ) ;
if ( V_261 )
* V_261 = & V_2 -> V_115 ;
return 0 ;
}
void F_182 ( struct V_1 * V_2 )
{
F_33 () ;
F_23 ( & V_2 -> V_15 -> V_32 ) ;
F_183 ( & V_2 -> V_128 ) ;
F_24 ( & V_2 -> V_15 -> V_32 ) ;
F_96 () ;
if ( V_2 -> V_57 ) {
F_184 ( V_2 -> V_57 ) ;
} else {
F_185 ( & V_2 -> V_115 ) ;
F_44 ( V_2 ) ;
}
}
void F_186 ( struct V_1 * V_2 )
{
if ( F_36 ( ! F_187 ( V_155 , & V_2 -> V_156 ) ) )
return;
F_78 ( V_2 , true ) ;
F_112 ( V_2 ) ;
}
void F_188 ( struct V_17 * V_15 )
{
struct V_1 * V_2 , * V_65 ;
F_189 ( V_291 ) ;
F_189 ( V_292 ) ;
F_33 () ;
F_23 ( & V_15 -> V_32 ) ;
F_92 (sdata, tmp, &local->interfaces, list) {
F_75 ( & V_2 -> V_128 ) ;
if ( V_2 -> V_57 )
F_190 ( V_2 -> V_57 , & V_291 ) ;
else
F_54 ( & V_2 -> V_128 , & V_292 ) ;
}
F_24 ( & V_15 -> V_32 ) ;
F_191 ( & V_291 ) ;
F_75 ( & V_291 ) ;
F_92 (sdata, tmp, &wdev_list, list) {
F_75 ( & V_2 -> V_128 ) ;
F_185 ( & V_2 -> V_115 ) ;
F_44 ( V_2 ) ;
}
}
static int F_192 ( struct V_293 * V_294 ,
unsigned long V_156 ,
void * V_264 )
{
struct V_56 * V_57 = V_264 ;
struct V_1 * V_2 ;
if ( V_156 != V_295 )
return 0 ;
if ( ! V_57 -> V_273 || ! V_57 -> V_273 -> V_68 )
return 0 ;
if ( V_57 -> V_273 -> V_68 -> V_296 != V_297 )
return 0 ;
V_2 = F_29 ( V_57 ) ;
memcpy ( V_2 -> V_110 , V_57 -> V_110 , V_111 ) ;
F_193 ( V_2 ) ;
return 0 ;
}
int F_194 ( void )
{
return F_195 ( & V_298 ) ;
}
void F_196 ( void )
{
F_197 ( & V_298 ) ;
}
