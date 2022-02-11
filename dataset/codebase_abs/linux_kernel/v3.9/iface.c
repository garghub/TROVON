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
F_11 ( V_15 , false ) ;
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
static int F_21 ( struct V_17 * V_15 , T_2 * V_47 )
{
struct V_1 * V_2 ;
T_3 V_48 , V_49 , V_50 ;
T_2 * V_51 ;
int V_52 = 0 ;
if ( F_22 ( V_15 -> V_18 . V_53 -> V_54 ) )
return 0 ;
V_51 = V_47 ;
V_48 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
V_51 = V_15 -> V_18 . V_53 -> V_54 ;
V_49 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
F_23 ( & V_15 -> V_55 ) ;
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_56 )
continue;
V_51 = V_2 -> V_6 . V_47 ;
V_50 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
if ( ( V_48 & ~ V_49 ) != ( V_50 & ~ V_49 ) ) {
V_52 = - V_45 ;
break;
}
}
F_24 ( & V_15 -> V_55 ) ;
return V_52 ;
}
static int F_25 ( struct V_41 * V_42 , void * V_47 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_57 * V_58 = V_47 ;
int V_52 ;
if ( F_27 ( V_2 ) )
return - V_59 ;
V_52 = F_21 ( V_2 -> V_15 , V_58 -> V_60 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_28 ( V_42 , V_58 ) ;
if ( V_52 == 0 )
memcpy ( V_2 -> V_6 . V_47 , V_58 -> V_60 , V_61 ) ;
return V_52 ;
}
static inline int F_29 ( int V_62 , int V_63 )
{
return V_62 == V_56 ||
V_63 == V_56 ||
V_62 == V_64 ||
V_63 == V_64 ||
( V_62 == V_65 && V_63 == V_66 ) ||
( V_62 == V_66 &&
( V_63 == V_66 ||
V_63 == V_65 ) ) ||
( V_62 == V_65 && V_63 == V_67 ) ||
( V_62 == V_67 &&
( V_63 == V_65 ||
V_63 == V_67 ) ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_68 V_69 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_1 * V_70 ;
F_31 () ;
F_15 (nsdata, &local->interfaces, list) {
if ( V_70 != V_2 && F_27 ( V_70 ) ) {
if ( V_69 == V_71 &&
V_70 -> V_6 . type == V_71 )
return - V_59 ;
if ( ! F_32 ( V_2 -> V_6 . V_47 ,
V_70 -> V_6 . V_47 ) )
continue;
if ( ! F_29 ( V_69 ,
V_70 -> V_6 . type ) )
return - V_72 ;
if ( V_69 == V_67 &&
V_70 -> V_6 . type == V_65 )
V_2 -> V_73 = & V_70 -> V_74 . V_75 ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_76 = V_2 -> V_15 -> V_18 . V_77 ;
int V_78 ;
if ( V_2 -> V_6 . type != V_64 ) {
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
if ( F_34 ( V_2 -> V_6 . V_80 [ V_78 ] ==
V_81 ) )
return - V_45 ;
if ( F_34 ( V_2 -> V_6 . V_80 [ V_78 ] >=
V_76 ) )
return - V_45 ;
}
}
if ( ( V_2 -> V_6 . type != V_65 &&
V_2 -> V_6 . type != V_82 ) ||
! ( V_2 -> V_15 -> V_18 . V_20 & V_83 ) ) {
V_2 -> V_6 . V_84 = V_81 ;
return 0 ;
}
if ( F_34 ( V_2 -> V_6 . V_84 == V_81 ) )
return - V_45 ;
if ( F_34 ( V_2 -> V_6 . V_84 >= V_76 ) )
return - V_45 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 ,
const int V_85 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
T_1 V_20 = V_2 -> V_74 . V_86 ;
#define F_36 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_36 ( V_87 , V_88 ) ;
F_36 ( V_89 , V_90 ) ;
F_36 ( V_91 , V_92 ) ;
F_36 ( V_91 , V_93 ) ;
F_36 ( V_94 , V_95 ) ;
#undef F_36
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
if ( V_15 -> V_18 . V_20 & V_83 )
V_2 -> V_6 . V_80 [ V_78 ] = V_81 ;
else if ( V_15 -> V_18 . V_77 >= V_79 )
V_2 -> V_6 . V_80 [ V_78 ] = V_78 ;
else
V_2 -> V_6 . V_80 [ V_78 ] = 0 ;
}
V_2 -> V_6 . V_84 = V_81 ;
}
static int F_38 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
int V_52 ;
if ( ! ( V_15 -> V_18 . V_20 & V_96 ) )
return 0 ;
F_31 () ;
if ( V_15 -> V_97 )
return 0 ;
V_2 = F_39 ( sizeof( * V_2 ) + V_15 -> V_18 . V_98 , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_6 . type = V_56 ;
snprintf ( V_2 -> V_101 , V_102 , L_1 ,
F_40 ( V_15 -> V_18 . V_53 ) ) ;
F_37 ( V_2 ) ;
V_52 = F_41 ( V_15 , V_2 ) ;
if ( F_42 ( V_52 ) ) {
F_43 ( V_2 ) ;
return V_52 ;
}
V_52 = F_33 ( V_2 ) ;
if ( V_52 ) {
F_43 ( V_2 ) ;
return V_52 ;
}
V_52 = F_44 ( V_2 , & V_15 -> V_103 ,
V_104 ) ;
if ( V_52 ) {
F_45 ( V_15 , V_2 ) ;
F_43 ( V_2 ) ;
return V_52 ;
}
F_23 ( & V_15 -> V_55 ) ;
F_46 ( V_15 -> V_97 , V_2 ) ;
F_24 ( & V_15 -> V_55 ) ;
return 0 ;
}
static void F_47 ( struct V_17 * V_15 )
{
struct V_1 * V_2 ;
if ( ! ( V_15 -> V_18 . V_20 & V_96 ) )
return;
F_31 () ;
F_23 ( & V_15 -> V_55 ) ;
V_2 = F_48 ( V_15 -> V_97 ,
F_49 ( & V_15 -> V_55 ) ) ;
if ( ! V_2 ) {
F_24 ( & V_15 -> V_55 ) ;
return;
}
F_46 ( V_15 -> V_97 , NULL ) ;
F_24 ( & V_15 -> V_55 ) ;
F_50 () ;
F_51 ( V_2 ) ;
F_45 ( V_15 , V_2 ) ;
F_43 ( V_2 ) ;
}
int F_52 ( struct V_105 * V_106 , bool V_107 )
{
struct V_1 * V_2 = F_53 ( V_106 ) ;
struct V_41 * V_42 = V_106 -> V_108 ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_109 * V_110 ;
T_1 V_111 = 0 ;
int V_112 ;
T_1 V_113 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_66 :
if ( ! F_54 ( V_2 -> V_74 . V_114 . V_115 ) )
return - V_116 ;
break;
case V_67 : {
struct V_1 * V_117 ;
if ( ! V_2 -> V_73 )
return - V_116 ;
F_55 ( & V_2 -> V_74 . V_118 . V_119 , & V_2 -> V_73 -> V_120 ) ;
V_117 = F_56 ( V_2 -> V_73 ,
struct V_1 , V_74 . V_75 ) ;
V_2 -> V_121 =
V_117 -> V_121 ;
V_2 -> V_122 =
V_117 -> V_122 ;
break;
}
case V_65 :
V_2 -> V_73 = & V_2 -> V_74 . V_75 ;
break;
case V_82 :
case V_123 :
case V_56 :
case V_71 :
case V_64 :
break;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
F_42 ( 1 ) ;
break;
}
if ( V_15 -> V_128 == 0 ) {
V_112 = F_57 ( V_15 ) ;
if ( V_112 )
goto V_129;
if ( V_15 -> V_34 -> V_130 )
F_58 ( & V_15 -> V_131 ) ;
V_113 = ~ 0 ;
F_59 ( V_15 , true ) ;
F_17 ( V_15 ,
V_132 , 0 ) ;
}
if ( V_42 && F_22 ( V_42 -> V_133 ) ) {
memcpy ( V_42 -> V_133 ,
V_15 -> V_18 . V_53 -> V_134 ,
V_61 ) ;
memcpy ( V_42 -> V_134 , V_42 -> V_133 , V_61 ) ;
if ( ! F_54 ( V_42 -> V_133 ) ) {
V_112 = - V_135 ;
goto V_136;
}
}
switch ( V_2 -> V_6 . type ) {
case V_67 :
if ( F_60 ( V_2 -> V_73 -> V_137 ) ) {
F_61 ( V_2 ) ;
F_62 ( V_42 ) ;
} else {
F_63 ( V_42 ) ;
}
break;
case V_56 :
if ( V_2 -> V_74 . V_86 & V_138 ) {
V_15 -> V_139 ++ ;
break;
}
if ( V_15 -> V_33 == 0 && V_15 -> V_128 == 0 ) {
V_112 = F_38 ( V_15 ) ;
if ( V_112 )
goto V_136;
}
V_15 -> V_33 ++ ;
if ( V_15 -> V_33 == 1 ) {
V_15 -> V_18 . V_19 . V_20 |= V_140 ;
V_113 |= V_141 ;
}
F_35 ( V_2 , 1 ) ;
F_64 ( V_15 ) ;
F_23 ( & V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
F_24 ( & V_15 -> V_31 ) ;
F_62 ( V_42 ) ;
break;
default:
if ( V_107 ) {
F_47 ( V_15 ) ;
V_112 = F_41 ( V_15 , V_2 ) ;
if ( V_112 )
goto V_136;
V_112 = F_33 ( V_2 ) ;
if ( V_112 )
goto V_142;
}
F_65 ( V_15 , V_2 ) ;
if ( V_2 -> V_6 . type == V_65 ) {
V_15 -> V_143 ++ ;
V_15 -> V_144 ++ ;
F_64 ( V_15 ) ;
} else if ( V_2 -> V_6 . type == V_71 ) {
V_15 -> V_144 ++ ;
}
if ( V_2 -> V_6 . type != V_64 )
V_111 |= F_66 ( V_2 ) ;
F_8 ( V_2 , V_111 ) ;
switch ( V_2 -> V_6 . type ) {
case V_123 :
case V_71 :
case V_65 :
case V_82 :
F_63 ( V_42 ) ;
break;
case V_66 :
case V_64 :
break;
default:
F_62 ( V_42 ) ;
}
F_67 ( V_2 , true ) ;
}
F_68 ( V_145 , & V_2 -> V_146 ) ;
if ( V_2 -> V_6 . type == V_66 ) {
V_110 = F_69 ( V_2 , V_2 -> V_74 . V_114 . V_115 ,
V_99 ) ;
if ( ! V_110 ) {
V_112 = - V_100 ;
goto V_142;
}
F_70 ( V_110 , V_147 ) ;
F_70 ( V_110 , V_148 ) ;
F_70 ( V_110 , V_149 ) ;
V_112 = F_71 ( V_110 ) ;
if ( V_112 ) {
goto V_142;
}
F_72 ( V_110 ) ;
F_62 ( V_42 ) ;
} else if ( V_2 -> V_6 . type == V_64 ) {
F_46 ( V_15 -> V_150 , V_2 ) ;
}
if ( V_2 -> V_20 & V_151 )
F_73 ( & V_15 -> V_152 ) ;
if ( V_2 -> V_20 & V_153 )
F_73 ( & V_15 -> V_154 ) ;
if ( V_107 )
V_15 -> V_128 ++ ;
if ( V_113 )
F_6 ( V_15 , V_113 ) ;
F_74 ( V_15 , - 1 ) ;
if ( V_42 )
F_75 ( V_42 ) ;
return 0 ;
V_142:
F_45 ( V_15 , V_2 ) ;
V_136:
if ( ! V_15 -> V_128 )
F_76 ( V_15 ) ;
V_129:
V_2 -> V_73 = NULL ;
if ( V_2 -> V_6 . type == V_67 )
F_77 ( & V_2 -> V_74 . V_118 . V_119 ) ;
F_78 ( V_145 , & V_2 -> V_146 ) ;
return V_112 ;
}
static int F_79 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
int V_155 ;
if ( ! F_54 ( V_42 -> V_133 ) )
return - V_135 ;
V_155 = F_30 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_155 )
return V_155 ;
return F_52 ( & V_2 -> V_106 , true ) ;
}
static void F_80 ( struct V_1 * V_2 ,
bool V_156 )
{
struct V_17 * V_15 = V_2 -> V_15 ;
unsigned long V_20 ;
struct V_157 * V_158 , * V_50 ;
T_1 V_113 = 0 ;
int V_78 , V_159 ;
struct V_160 * V_161 ;
F_78 ( V_145 , & V_2 -> V_146 ) ;
if ( F_81 ( V_15 -> V_162 ) == V_2 )
F_82 ( V_15 ) ;
if ( V_2 -> V_42 )
F_83 ( V_2 -> V_42 ) ;
F_84 ( V_2 ) ;
if ( V_2 -> V_6 . type == V_123 )
F_85 ( V_2 ) ;
V_159 = F_86 ( V_2 ) ;
F_34 ( ( V_2 -> V_6 . type != V_66 && V_159 > 0 ) ||
( V_2 -> V_6 . type == V_66 && V_159 != 1 ) ) ;
if ( V_2 -> V_20 & V_151 )
F_87 ( & V_15 -> V_152 ) ;
if ( V_2 -> V_20 & V_153 )
F_87 ( & V_15 -> V_154 ) ;
if ( V_2 -> V_6 . type == V_65 ) {
V_15 -> V_143 -- ;
V_15 -> V_144 -- ;
} else if ( V_2 -> V_6 . type == V_71 ) {
V_15 -> V_144 -- ;
}
if ( V_2 -> V_42 ) {
F_88 ( V_2 -> V_42 ) ;
F_89 ( & V_15 -> V_163 ) ;
F_90 ( & V_15 -> V_164 , & V_2 -> V_42 -> V_165 ,
V_2 -> V_42 -> V_166 ) ;
F_91 ( & V_15 -> V_163 ) ;
F_92 ( V_2 -> V_42 ) ;
F_64 ( V_15 ) ;
}
F_93 ( & V_15 -> V_167 ) ;
F_94 ( & V_15 -> V_168 ) ;
F_94 ( & V_2 -> V_169 ) ;
F_95 ( & V_2 -> V_170 ) ;
if ( V_2 -> V_106 . V_171 ) {
F_23 ( & V_15 -> V_55 ) ;
F_51 ( V_2 ) ;
F_24 ( & V_15 -> V_55 ) ;
F_96 ( V_2 -> V_42 , V_172 ,
V_99 ) ;
}
if ( V_2 -> V_6 . type == V_65 ) {
struct V_1 * V_118 , * V_173 ;
F_97 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_98 ( V_118 -> V_42 ) ;
F_42 ( ! F_14 ( & V_2 -> V_74 . V_75 . V_120 ) ) ;
} else if ( V_2 -> V_6 . type == V_67 ) {
V_161 = & V_2 -> V_73 -> V_161 ;
F_99 ( & V_161 -> V_174 . V_175 , V_20 ) ;
F_100 (&ps->bc_buf, skb, tmp) {
if ( V_158 -> V_42 == V_2 -> V_42 ) {
F_101 ( V_158 , & V_161 -> V_174 ) ;
V_15 -> V_176 -- ;
F_102 ( & V_15 -> V_18 , V_158 ) ;
}
}
F_103 ( & V_161 -> V_174 . V_175 , V_20 ) ;
}
if ( V_156 )
V_15 -> V_128 -- ;
switch ( V_2 -> V_6 . type ) {
case V_67 :
F_77 ( & V_2 -> V_74 . V_118 . V_119 ) ;
F_46 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_56 :
if ( V_2 -> V_74 . V_86 & V_138 ) {
V_15 -> V_139 -- ;
break;
}
V_15 -> V_33 -- ;
if ( V_15 -> V_33 == 0 ) {
V_15 -> V_18 . V_19 . V_20 &= ~ V_140 ;
V_113 |= V_141 ;
F_47 ( V_15 ) ;
}
F_35 ( V_2 , - 1 ) ;
F_64 ( V_15 ) ;
F_23 ( & V_15 -> V_31 ) ;
F_19 ( V_15 ) ;
F_24 ( & V_15 -> V_31 ) ;
break;
case V_64 :
F_46 ( V_15 -> V_150 , NULL ) ;
default:
F_94 ( & V_2 -> V_177 ) ;
F_104 () ;
F_105 ( V_2 ) ;
F_106 ( & V_2 -> V_178 ) ;
F_107 ( V_2 ) ;
F_108 ( V_15 , V_2 ) ;
if ( V_156 )
F_45 ( V_15 , V_2 ) ;
}
V_2 -> V_73 = NULL ;
F_74 ( V_15 , - 1 ) ;
if ( V_15 -> V_128 == 0 ) {
if ( V_15 -> V_34 -> V_130 )
F_109 ( & V_15 -> V_131 ) ;
F_110 ( V_15 ) ;
F_111 ( V_15 ) ;
V_113 = 0 ;
}
if ( V_113 )
F_6 ( V_15 , V_113 ) ;
F_99 ( & V_15 -> V_179 , V_20 ) ;
for ( V_78 = 0 ; V_78 < V_180 ; V_78 ++ ) {
F_100 (&local->pending[i], skb, tmp) {
struct V_181 * V_182 = F_112 ( V_158 ) ;
if ( V_182 -> V_92 . V_6 == & V_2 -> V_6 ) {
F_101 ( V_158 , & V_15 -> V_183 [ V_78 ] ) ;
F_102 ( & V_15 -> V_18 , V_158 ) ;
}
}
}
F_103 ( & V_15 -> V_179 , V_20 ) ;
if ( V_15 -> V_33 == V_15 -> V_128 && V_15 -> V_33 > 0 )
F_38 ( V_15 ) ;
}
static int F_113 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
F_80 ( V_2 , true ) ;
return 0 ;
}
static void F_114 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
int V_184 , V_185 , V_186 , V_187 ;
V_184 = ! ! ( V_42 -> V_20 & V_188 ) ;
V_185 = ! ! ( V_42 -> V_20 & V_189 ) ;
V_186 = ! ! ( V_2 -> V_20 & V_151 ) ;
V_187 = ! ! ( V_2 -> V_20 & V_153 ) ;
if ( V_184 != V_186 ) {
if ( V_42 -> V_20 & V_188 )
F_73 ( & V_15 -> V_152 ) ;
else
F_87 ( & V_15 -> V_152 ) ;
V_2 -> V_20 ^= V_151 ;
}
if ( V_185 != V_187 ) {
if ( V_42 -> V_20 & V_189 )
F_73 ( & V_15 -> V_154 ) ;
else
F_87 ( & V_15 -> V_154 ) ;
V_2 -> V_20 ^= V_153 ;
}
F_89 ( & V_15 -> V_163 ) ;
F_115 ( & V_15 -> V_164 , & V_42 -> V_165 , V_42 -> V_166 ) ;
F_91 ( & V_15 -> V_163 ) ;
F_116 ( & V_15 -> V_18 , & V_15 -> V_190 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
int V_159 ;
int V_78 ;
F_107 ( V_2 ) ;
F_118 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_191 ; V_78 ++ )
F_119 ( & V_2 -> V_192 [ V_78 ] . V_193 ) ;
V_2 -> V_194 = 0 ;
if ( F_120 ( & V_2 -> V_6 ) )
F_121 ( V_2 ) ;
V_159 = F_122 ( V_2 ) ;
F_42 ( V_159 ) ;
}
static void F_123 ( struct V_41 * V_42 )
{
F_117 ( F_26 ( V_42 ) ) ;
}
static T_6 F_124 ( struct V_41 * V_42 ,
struct V_157 * V_158 )
{
return F_125 ( F_26 ( V_42 ) , V_158 ) ;
}
static T_6 F_126 ( struct V_41 * V_42 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = F_26 ( V_42 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_195 * V_196 ;
struct V_197 * V_198 = ( void * ) V_158 -> V_199 ;
if ( V_15 -> V_18 . V_77 < V_79 )
return 0 ;
if ( V_158 -> V_200 < 4 ||
V_158 -> V_200 < F_127 ( V_198 -> V_201 ) + 2 )
return 0 ;
V_196 = ( void * ) ( ( T_2 * ) V_158 -> V_199 + F_127 ( V_198 -> V_201 ) ) ;
return F_128 ( V_2 , V_158 , V_196 ) ;
}
static void F_129 ( struct V_41 * V_42 )
{
F_130 ( V_42 ) ;
V_42 -> V_202 &= ~ V_203 ;
V_42 -> V_204 = & V_205 ;
V_42 -> V_206 = V_207 ;
}
static void F_131 ( struct V_208 * V_177 )
{
struct V_1 * V_2 =
F_56 ( V_177 , struct V_1 , V_177 ) ;
struct V_17 * V_15 = V_2 -> V_15 ;
struct V_157 * V_158 ;
struct V_109 * V_110 ;
struct V_209 * V_210 ;
if ( ! F_27 ( V_2 ) )
return;
if ( V_15 -> V_25 )
return;
if ( F_132 ( V_15 -> V_211 ,
L_2 ) )
return;
while ( ( V_158 = F_133 ( & V_2 -> V_178 ) ) ) {
struct V_212 * V_213 = ( void * ) V_158 -> V_199 ;
if ( V_158 -> V_214 == V_215 ) {
V_210 = ( void * ) & V_158 -> V_216 ;
F_134 ( & V_2 -> V_6 , V_210 -> V_217 ,
V_210 -> V_218 ) ;
} else if ( V_158 -> V_214 == V_219 ) {
V_210 = ( void * ) & V_158 -> V_216 ;
F_135 ( & V_2 -> V_6 , V_210 -> V_217 ,
V_210 -> V_218 ) ;
} else if ( F_136 ( V_213 -> V_220 ) &&
V_213 -> V_74 . V_221 . V_222 == V_223 ) {
int V_200 = V_158 -> V_200 ;
F_23 ( & V_15 -> V_224 ) ;
V_110 = F_137 ( V_2 , V_213 -> V_58 ) ;
if ( V_110 ) {
switch ( V_213 -> V_74 . V_221 . V_74 . V_225 . V_226 ) {
case V_227 :
F_138 (
V_15 , V_110 , V_213 , V_200 ) ;
break;
case V_228 :
F_139 ( V_15 , V_110 ,
V_213 , V_200 ) ;
break;
case V_229 :
F_140 ( V_2 , V_110 ,
V_213 , V_200 ) ;
break;
default:
F_42 ( 1 ) ;
break;
}
}
F_24 ( & V_15 -> V_224 ) ;
} else if ( F_141 ( V_213 -> V_220 ) ) {
struct V_195 * V_196 = ( void * ) V_213 ;
F_42 ( V_196 -> V_220 &
F_142 ( V_230 ) ) ;
F_42 ( ! ( V_196 -> V_231 &
F_142 ( V_232 ) ) ) ;
F_23 ( & V_15 -> V_224 ) ;
V_110 = F_137 ( V_2 , V_213 -> V_58 ) ;
if ( V_110 ) {
T_6 V_218 = * F_143 ( V_196 ) &
V_233 ;
F_144 (
V_110 , V_218 , V_234 ,
V_235 ,
true ) ;
}
F_24 ( & V_15 -> V_224 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_123 :
F_145 ( V_2 , V_158 ) ;
break;
case V_71 :
F_146 ( V_2 , V_158 ) ;
break;
case V_82 :
if ( ! F_120 ( & V_2 -> V_6 ) )
break;
F_147 ( V_2 , V_158 ) ;
break;
default:
F_132 ( 1 , L_3 ) ;
break;
}
F_148 ( V_158 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_123 :
F_149 ( V_2 ) ;
break;
case V_71 :
F_150 ( V_2 ) ;
break;
case V_82 :
if ( ! F_120 ( & V_2 -> V_6 ) )
break;
F_151 ( V_2 ) ;
break;
default:
break;
}
}
static void F_152 ( struct V_208 * V_177 )
{
struct V_1 * V_2 =
F_56 ( V_177 , struct V_1 , V_169 ) ;
F_153 ( V_2 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
enum V_68 type )
{
memset ( & V_2 -> V_74 , 0 , sizeof( V_2 -> V_74 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_236 = false ;
V_2 -> V_106 . V_69 = type ;
V_2 -> V_121 = F_155 ( V_237 ) ;
V_2 -> V_122 = false ;
V_2 -> V_238 = 0 ;
if ( V_2 -> V_42 ) {
V_2 -> V_42 -> V_204 = & V_205 ;
V_2 -> V_42 -> type = V_239 ;
}
F_156 ( & V_2 -> V_178 ) ;
F_157 ( & V_2 -> V_177 , F_131 ) ;
F_157 ( & V_2 -> V_169 , F_152 ) ;
switch ( type ) {
case V_127 :
type = V_65 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_236 = true ;
case V_65 :
F_156 ( & V_2 -> V_74 . V_75 . V_161 . V_174 ) ;
F_158 ( & V_2 -> V_74 . V_75 . V_120 ) ;
V_2 -> V_6 . V_13 . V_240 = V_2 -> V_6 . V_47 ;
break;
case V_126 :
type = V_123 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_236 = true ;
case V_123 :
V_2 -> V_6 . V_13 . V_240 = V_2 -> V_74 . V_241 . V_240 ;
F_159 ( V_2 ) ;
break;
case V_71 :
V_2 -> V_6 . V_13 . V_240 = V_2 -> V_74 . V_242 . V_240 ;
F_160 ( V_2 ) ;
break;
case V_82 :
if ( F_120 ( & V_2 -> V_6 ) )
F_161 ( V_2 ) ;
break;
case V_56 :
V_2 -> V_42 -> type = V_243 ;
V_2 -> V_42 -> V_204 = & V_244 ;
V_2 -> V_74 . V_86 = V_245 |
V_246 ;
break;
case V_66 :
V_2 -> V_6 . V_13 . V_240 = NULL ;
break;
case V_67 :
break;
case V_64 :
V_2 -> V_6 . V_13 . V_240 = V_2 -> V_6 . V_47 ;
break;
case V_124 :
case V_125 :
F_162 () ;
break;
}
F_163 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
enum V_68 type )
{
struct V_17 * V_15 = V_2 -> V_15 ;
int V_52 , V_155 ;
enum V_68 V_247 = type ;
bool V_236 = false ;
F_31 () ;
if ( ! V_15 -> V_34 -> V_248 )
return - V_59 ;
switch ( V_2 -> V_6 . type ) {
case V_65 :
case V_123 :
case V_71 :
break;
default:
return - V_59 ;
}
switch ( type ) {
case V_65 :
case V_123 :
case V_71 :
break;
case V_126 :
V_236 = true ;
V_247 = V_123 ;
break;
case V_127 :
V_236 = true ;
V_247 = V_65 ;
break;
default:
return - V_59 ;
}
V_52 = F_30 ( V_2 , V_247 ) ;
if ( V_52 )
return V_52 ;
F_80 ( V_2 , false ) ;
F_117 ( V_2 ) ;
V_52 = F_165 ( V_15 , V_2 , V_247 , V_236 ) ;
if ( V_52 )
type = V_2 -> V_6 . type ;
F_33 ( V_2 ) ;
F_154 ( V_2 , type ) ;
V_155 = F_52 ( & V_2 -> V_106 , false ) ;
F_132 ( V_155 , L_4 , V_155 ) ;
return V_52 ;
}
int F_166 ( struct V_1 * V_2 ,
enum V_68 type )
{
int V_52 ;
F_31 () ;
if ( type == F_167 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_27 ( V_2 ) ) {
V_52 = F_164 ( V_2 , type ) ;
if ( V_52 )
return V_52 ;
} else {
F_117 ( V_2 ) ;
F_154 ( V_2 , type ) ;
}
V_2 -> V_249 = 0 ;
if ( type == V_123 )
V_2 -> V_74 . V_241 . V_250 = false ;
return 0 ;
}
static void F_168 ( struct V_17 * V_15 ,
T_2 * V_134 , enum V_68 type )
{
struct V_1 * V_2 ;
T_3 V_49 , V_251 , V_47 , V_252 , V_253 ;
T_2 * V_51 ;
T_2 V_254 [ V_61 ] ;
int V_78 ;
memcpy ( V_134 , V_15 -> V_18 . V_53 -> V_134 , V_61 ) ;
if ( F_22 ( V_15 -> V_18 . V_53 -> V_54 ) &&
V_15 -> V_18 . V_53 -> V_255 <= 1 )
return;
F_23 ( & V_15 -> V_55 ) ;
switch ( type ) {
case V_56 :
break;
case V_66 :
case V_67 :
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_65 )
continue;
memcpy ( V_134 , V_2 -> V_6 . V_47 , V_61 ) ;
break;
}
break;
case V_126 :
case V_127 :
if ( V_15 -> V_18 . V_20 & V_256 ) {
F_15 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_64 )
continue;
if ( ! F_27 ( V_2 ) )
continue;
memcpy ( V_134 , V_2 -> V_6 . V_47 , V_61 ) ;
goto V_257;
}
}
default:
for ( V_78 = 0 ; V_78 < V_15 -> V_18 . V_53 -> V_255 ; V_78 ++ ) {
bool V_258 = false ;
F_15 (sdata, &local->interfaces, list) {
if ( memcmp ( V_15 -> V_18 . V_53 -> V_259 [ V_78 ] . V_47 ,
V_2 -> V_6 . V_47 , V_61 ) == 0 ) {
V_258 = true ;
break;
}
}
if ( ! V_258 ) {
memcpy ( V_134 ,
V_15 -> V_18 . V_53 -> V_259 [ V_78 ] . V_47 ,
V_61 ) ;
break;
}
}
if ( F_22 ( V_15 -> V_18 . V_53 -> V_54 ) )
break;
V_51 = V_15 -> V_18 . V_53 -> V_54 ;
V_49 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
if ( F_169 ( V_49 ) + F_170 ( V_49 ) != F_171 ( V_49 ) ) {
F_172 ( L_5 ) ;
break;
}
V_51 = V_15 -> V_18 . V_53 -> V_134 ;
V_251 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
V_253 = 1ULL << F_169 ( V_49 ) ;
V_252 = ( V_251 & V_49 ) ;
V_47 = ( V_251 & ~ V_49 ) | ( V_252 & V_49 ) ;
do {
bool V_258 = false ;
V_254 [ 5 ] = V_47 >> 0 * 8 ;
V_254 [ 4 ] = V_47 >> 1 * 8 ;
V_254 [ 3 ] = V_47 >> 2 * 8 ;
V_254 [ 2 ] = V_47 >> 3 * 8 ;
V_254 [ 1 ] = V_47 >> 4 * 8 ;
V_254 [ 0 ] = V_47 >> 5 * 8 ;
V_252 += V_253 ;
F_15 (sdata, &local->interfaces, list) {
if ( memcmp ( V_254 , V_2 -> V_6 . V_47 ,
V_61 ) == 0 ) {
V_258 = true ;
break;
}
}
if ( ! V_258 ) {
memcpy ( V_134 , V_254 , V_61 ) ;
break;
}
V_47 = ( V_251 & ~ V_49 ) | ( V_252 & V_49 ) ;
} while ( V_47 != V_251 );
break;
}
V_257:
F_24 ( & V_15 -> V_55 ) ;
}
static void F_173 ( struct V_208 * V_260 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_260 , struct V_1 , V_261 ) ;
F_174 ( V_2 ) ;
}
int F_175 ( struct V_17 * V_15 , const char * V_101 ,
struct V_105 * * V_262 , enum V_68 type ,
struct V_263 * V_264 )
{
struct V_41 * V_265 = NULL ;
struct V_1 * V_2 = NULL ;
int V_52 , V_78 ;
int V_266 = 1 ;
F_31 () ;
if ( type == V_64 ) {
struct V_105 * V_106 ;
V_2 = F_39 ( sizeof( * V_2 ) + V_15 -> V_18 . V_98 ,
V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_106 = & V_2 -> V_106 ;
V_2 -> V_42 = NULL ;
F_176 ( V_2 -> V_101 , V_101 , V_102 ) ;
F_168 ( V_15 , V_106 -> V_267 , type ) ;
memcpy ( V_2 -> V_6 . V_47 , V_106 -> V_267 , V_61 ) ;
} else {
if ( V_15 -> V_18 . V_77 >= V_79 )
V_266 = V_79 ;
V_265 = F_177 ( sizeof( * V_2 ) +
V_15 -> V_18 . V_98 ,
V_101 , F_129 , V_266 , 1 ) ;
if ( ! V_265 )
return - V_100 ;
F_178 ( V_265 , F_179 ( V_15 -> V_18 . V_53 ) ) ;
V_265 -> V_268 = V_15 -> V_269 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_270
+ V_271 ;
V_265 -> V_272 = V_273 ;
V_52 = F_180 ( V_265 , V_265 -> V_101 ) ;
if ( V_52 < 0 ) {
V_207 ( V_265 ) ;
return V_52 ;
}
F_168 ( V_15 , V_265 -> V_134 , type ) ;
memcpy ( V_265 -> V_133 , V_265 -> V_134 , V_61 ) ;
F_181 ( V_265 , F_182 ( V_15 -> V_18 . V_53 ) ) ;
V_2 = F_183 ( V_265 ) ;
V_265 -> V_274 = & V_2 -> V_106 ;
memcpy ( V_2 -> V_6 . V_47 , V_265 -> V_133 , V_61 ) ;
memcpy ( V_2 -> V_101 , V_265 -> V_101 , V_102 ) ;
V_2 -> V_42 = V_265 ;
}
V_2 -> V_106 . V_53 = V_15 -> V_18 . V_53 ;
V_2 -> V_15 = V_15 ;
for ( V_78 = 0 ; V_78 < V_191 ; V_78 ++ )
F_156 ( & V_2 -> V_192 [ V_78 ] . V_193 ) ;
F_158 ( & V_2 -> V_275 ) ;
F_184 ( & V_2 -> V_276 ) ;
F_158 ( & V_2 -> V_277 ) ;
F_157 ( & V_2 -> V_261 , F_173 ) ;
F_185 ( & V_2 -> V_170 ,
V_278 ) ;
for ( V_78 = 0 ; V_78 < V_279 ; V_78 ++ ) {
struct V_280 * V_281 ;
V_281 = V_15 -> V_18 . V_53 -> V_282 [ V_78 ] ;
V_2 -> V_283 [ V_78 ] =
V_281 ? ( 1 << V_281 -> V_284 ) - 1 : 0 ;
if ( V_281 )
memcpy ( V_2 -> V_285 [ V_78 ] ,
V_281 -> V_286 . V_287 . V_288 ,
sizeof( V_2 -> V_285 [ V_78 ] ) ) ;
else
memset ( V_2 -> V_285 [ V_78 ] , 0 ,
sizeof( V_2 -> V_285 [ V_78 ] ) ) ;
}
F_37 ( V_2 ) ;
V_2 -> V_12 = V_11 ;
V_2 -> V_10 = V_15 -> V_10 ;
F_154 ( V_2 , type ) ;
if ( V_265 ) {
if ( V_264 ) {
V_265 -> V_274 -> V_250 = V_264 -> V_250 ;
if ( type == V_123 )
V_2 -> V_74 . V_241 . V_250 = V_264 -> V_250 ;
}
V_265 -> V_289 |= V_15 -> V_18 . V_290 ;
V_52 = F_186 ( V_265 ) ;
if ( V_52 ) {
V_207 ( V_265 ) ;
return V_52 ;
}
}
F_23 ( & V_15 -> V_55 ) ;
F_187 ( & V_2 -> V_119 , & V_15 -> V_291 ) ;
F_24 ( & V_15 -> V_55 ) ;
if ( V_262 )
* V_262 = & V_2 -> V_106 ;
return 0 ;
}
void F_188 ( struct V_1 * V_2 )
{
F_31 () ;
F_23 ( & V_2 -> V_15 -> V_55 ) ;
F_189 ( & V_2 -> V_119 ) ;
F_24 ( & V_2 -> V_15 -> V_55 ) ;
F_190 () ;
if ( V_2 -> V_42 ) {
F_191 ( V_2 -> V_42 ) ;
} else {
F_192 ( & V_2 -> V_106 ) ;
F_43 ( V_2 ) ;
}
}
void F_193 ( struct V_1 * V_2 )
{
if ( F_34 ( ! F_16 ( V_145 , & V_2 -> V_146 ) ) )
return;
F_80 ( V_2 , true ) ;
F_117 ( V_2 ) ;
}
void F_194 ( struct V_17 * V_15 )
{
struct V_1 * V_2 , * V_50 ;
F_195 ( V_292 ) ;
F_195 ( V_293 ) ;
F_31 () ;
F_23 ( & V_15 -> V_55 ) ;
F_97 (sdata, tmp, &local->interfaces, list) {
F_77 ( & V_2 -> V_119 ) ;
if ( V_2 -> V_42 )
F_196 ( V_2 -> V_42 , & V_292 ) ;
else
F_55 ( & V_2 -> V_119 , & V_293 ) ;
}
F_24 ( & V_15 -> V_55 ) ;
F_197 ( & V_292 ) ;
F_77 ( & V_292 ) ;
F_97 (sdata, tmp, &wdev_list, list) {
F_77 ( & V_2 -> V_119 ) ;
F_192 ( & V_2 -> V_106 ) ;
F_43 ( V_2 ) ;
}
}
static int F_198 ( struct V_294 * V_295 ,
unsigned long V_146 ,
void * V_265 )
{
struct V_41 * V_42 = V_265 ;
struct V_1 * V_2 ;
if ( V_146 != V_296 )
return 0 ;
if ( ! V_42 -> V_274 || ! V_42 -> V_274 -> V_53 )
return 0 ;
if ( V_42 -> V_274 -> V_53 -> V_297 != V_298 )
return 0 ;
V_2 = F_26 ( V_42 ) ;
memcpy ( V_2 -> V_101 , V_42 -> V_101 , V_102 ) ;
F_199 ( V_2 ) ;
return 0 ;
}
int F_200 ( void )
{
return F_201 ( & V_299 ) ;
}
void F_202 ( void )
{
F_203 ( & V_299 ) ;
}
