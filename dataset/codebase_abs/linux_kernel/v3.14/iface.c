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
V_2 -> V_106 = V_107 ;
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
F_24 ( & V_13 -> V_55 ) ;
F_45 ( V_13 -> V_100 , V_2 ) ;
F_25 ( & V_13 -> V_55 ) ;
F_24 ( & V_13 -> V_29 ) ;
V_52 = F_46 ( V_2 , & V_13 -> V_108 ,
V_109 ) ;
F_25 ( & V_13 -> V_29 ) ;
if ( V_52 ) {
F_24 ( & V_13 -> V_55 ) ;
F_45 ( V_13 -> V_100 , NULL ) ;
F_25 ( & V_13 -> V_55 ) ;
F_47 () ;
F_48 ( V_13 , V_2 ) ;
F_44 ( V_2 ) ;
return V_52 ;
}
return 0 ;
}
void F_49 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
if ( ! ( V_13 -> V_16 . V_18 & V_99 ) )
return;
F_32 () ;
F_24 ( & V_13 -> V_55 ) ;
V_2 = F_50 ( V_13 -> V_100 ,
F_51 ( & V_13 -> V_55 ) ) ;
if ( ! V_2 ) {
F_25 ( & V_13 -> V_55 ) ;
return;
}
F_45 ( V_13 -> V_100 , NULL ) ;
F_25 ( & V_13 -> V_55 ) ;
F_47 () ;
F_24 ( & V_13 -> V_29 ) ;
F_52 ( V_2 ) ;
F_25 ( & V_13 -> V_29 ) ;
F_48 ( V_13 , V_2 ) ;
F_44 ( V_2 ) ;
}
int F_53 ( struct V_110 * V_111 , bool V_112 )
{
struct V_1 * V_2 = F_54 ( V_111 ) ;
struct V_39 * V_40 = V_111 -> V_113 ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_114 * V_115 ;
T_1 V_116 = 0 ;
int V_117 ;
T_1 V_118 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_69 :
if ( ! F_55 ( V_2 -> V_57 . V_119 . V_120 ) )
return - V_121 ;
break;
case V_70 : {
struct V_1 * V_122 ;
if ( ! V_2 -> V_77 )
return - V_121 ;
F_56 ( & V_2 -> V_57 . V_123 . V_124 , & V_2 -> V_77 -> V_125 ) ;
V_122 = F_57 ( V_2 -> V_77 ,
struct V_1 , V_57 . V_78 ) ;
V_2 -> V_126 =
V_122 -> V_126 ;
V_2 -> V_127 =
V_122 -> V_127 ;
V_2 -> V_6 . V_88 = V_122 -> V_6 . V_88 ;
memcpy ( V_2 -> V_6 . V_83 , V_122 -> V_6 . V_83 ,
sizeof( V_2 -> V_6 . V_83 ) ) ;
break;
}
case V_68 :
V_2 -> V_77 = & V_2 -> V_57 . V_78 ;
break;
case V_86 :
case V_128 :
case V_56 :
case V_74 :
case V_67 :
break;
case V_129 :
case V_130 :
case V_131 :
case V_85 :
F_43 ( 1 ) ;
break;
}
if ( V_13 -> V_132 == 0 ) {
V_117 = F_58 ( V_13 ) ;
if ( V_117 )
goto V_133;
V_118 = ~ 0 ;
F_59 ( V_13 , true ) ;
F_18 ( V_13 ,
V_134 , 0 ) ;
}
if ( V_40 && F_23 ( V_40 -> V_135 ) ) {
memcpy ( V_40 -> V_135 ,
V_13 -> V_16 . V_53 -> V_136 ,
V_64 ) ;
memcpy ( V_40 -> V_136 , V_40 -> V_135 , V_64 ) ;
if ( ! F_55 ( V_40 -> V_135 ) ) {
V_117 = - V_137 ;
goto V_138;
}
}
switch ( V_2 -> V_6 . type ) {
case V_70 :
if ( F_60 ( V_2 -> V_77 -> V_139 ) ) {
F_61 ( V_2 ) ;
F_62 ( V_40 ) ;
} else {
F_63 ( V_40 ) ;
}
break;
case V_56 :
if ( V_2 -> V_57 . V_58 & V_140 ) {
V_13 -> V_141 ++ ;
break;
}
if ( V_2 -> V_57 . V_58 & V_59 ) {
V_117 = F_42 ( V_13 , V_2 ) ;
if ( V_117 )
goto V_138;
} else if ( V_13 -> V_31 == 0 && V_13 -> V_132 == 0 ) {
V_117 = F_39 ( V_13 ) ;
if ( V_117 )
goto V_138;
}
V_13 -> V_31 ++ ;
if ( V_13 -> V_31 == 1 ) {
V_13 -> V_16 . V_17 . V_18 |= V_142 ;
V_118 |= V_143 ;
}
F_36 ( V_2 , 1 ) ;
F_64 ( V_13 ) ;
F_24 ( & V_13 -> V_29 ) ;
F_20 ( V_13 ) ;
F_25 ( & V_13 -> V_29 ) ;
F_62 ( V_40 ) ;
break;
default:
if ( V_112 ) {
F_49 ( V_13 ) ;
V_117 = F_42 ( V_13 , V_2 ) ;
if ( V_117 )
goto V_138;
V_117 = F_34 ( V_2 ,
F_65 ( & V_2 -> V_6 ) ) ;
if ( V_117 )
goto V_144;
}
if ( V_2 -> V_6 . type == V_68 ) {
V_13 -> V_145 ++ ;
V_13 -> V_146 ++ ;
F_64 ( V_13 ) ;
} else if ( V_2 -> V_6 . type == V_74 ) {
V_13 -> V_146 ++ ;
}
if ( V_2 -> V_6 . type != V_67 )
V_116 |= F_66 ( V_2 ) ;
F_9 ( V_2 , V_116 ) ;
switch ( V_2 -> V_6 . type ) {
case V_128 :
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
F_68 ( V_147 , & V_2 -> V_148 ) ;
if ( V_2 -> V_6 . type == V_69 ) {
V_115 = F_69 ( V_2 , V_2 -> V_57 . V_119 . V_120 ,
V_102 ) ;
if ( ! V_115 ) {
V_117 = - V_103 ;
goto V_144;
}
F_70 ( V_115 , V_149 ) ;
F_70 ( V_115 , V_150 ) ;
F_70 ( V_115 , V_151 ) ;
V_117 = F_71 ( V_115 ) ;
if ( V_117 ) {
goto V_144;
}
F_72 ( V_115 ) ;
F_62 ( V_40 ) ;
} else if ( V_2 -> V_6 . type == V_67 ) {
F_45 ( V_13 -> V_152 , V_2 ) ;
}
if ( V_2 -> V_18 & V_153 )
F_73 ( & V_13 -> V_154 ) ;
if ( V_2 -> V_18 & V_155 )
F_73 ( & V_13 -> V_156 ) ;
if ( V_112 )
V_13 -> V_132 ++ ;
if ( V_118 )
F_7 ( V_13 , V_118 ) ;
F_74 ( V_13 , - 1 ) ;
if ( V_2 -> V_6 . type == V_56 ||
V_2 -> V_6 . type == V_70 ) {
F_75 ( V_40 ) ;
} else if ( V_40 ) {
unsigned long V_18 ;
int V_157 = V_82 ;
int V_158 ;
if ( V_13 -> V_16 . V_80 < V_82 )
V_157 = 1 ;
F_76 ( & V_13 -> V_159 , V_18 ) ;
if ( V_2 -> V_6 . V_88 == V_84 ||
( V_13 -> V_160 [ V_2 -> V_6 . V_88 ] == 0 &&
F_77 ( & V_13 -> V_161 [ V_2 -> V_6 . V_88 ] ) ) ) {
for ( V_158 = 0 ; V_158 < V_157 ; V_158 ++ ) {
int V_162 = V_2 -> V_6 . V_83 [ V_158 ] ;
if ( V_13 -> V_160 [ V_162 ] == 0 &&
F_77 ( & V_13 -> V_161 [ V_162 ] ) )
F_78 ( V_40 , V_158 ) ;
}
}
F_79 ( & V_13 -> V_159 , V_18 ) ;
}
return 0 ;
V_144:
F_48 ( V_13 , V_2 ) ;
V_138:
if ( ! V_13 -> V_132 )
F_80 ( V_13 ) ;
V_133:
V_2 -> V_77 = NULL ;
if ( V_2 -> V_6 . type == V_70 )
F_81 ( & V_2 -> V_57 . V_123 . V_124 ) ;
F_82 ( V_147 , & V_2 -> V_148 ) ;
return V_117 ;
}
static int F_83 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
int V_163 ;
if ( ! F_55 ( V_40 -> V_135 ) )
return - V_137 ;
V_163 = F_31 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_163 )
return V_163 ;
return F_53 ( & V_2 -> V_111 , true ) ;
}
static void F_84 ( struct V_1 * V_2 ,
bool V_164 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
unsigned long V_18 ;
struct V_165 * V_166 , * V_50 ;
T_1 V_118 = 0 ;
int V_81 , V_167 ;
struct V_168 * V_169 ;
struct V_170 V_171 ;
F_82 ( V_147 , & V_2 -> V_148 ) ;
if ( F_85 ( V_13 -> V_172 ) == V_2 )
F_86 ( V_13 ) ;
if ( V_2 -> V_40 )
F_87 ( V_2 -> V_40 ) ;
F_88 ( V_13 , V_2 ) ;
switch ( V_2 -> V_6 . type ) {
case V_128 :
F_89 ( V_2 ) ;
break;
case V_74 :
F_90 ( V_2 ) ;
break;
case V_68 :
F_91 ( & V_2 -> V_57 . V_78 . V_173 ) ;
break;
default:
break;
}
V_167 = F_92 ( V_2 ) ;
F_35 ( ( V_2 -> V_6 . type != V_69 && V_167 > 0 ) ||
( V_2 -> V_6 . type == V_69 && V_167 != 1 ) ) ;
if ( V_2 -> V_18 & V_153 )
F_93 ( & V_13 -> V_154 ) ;
if ( V_2 -> V_18 & V_155 )
F_93 ( & V_13 -> V_156 ) ;
if ( V_2 -> V_6 . type == V_68 ) {
V_13 -> V_145 -- ;
V_13 -> V_146 -- ;
} else if ( V_2 -> V_6 . type == V_74 ) {
V_13 -> V_146 -- ;
}
if ( V_2 -> V_40 ) {
F_94 ( V_2 -> V_40 ) ;
F_95 ( & V_13 -> V_174 ) ;
F_96 ( & V_13 -> V_175 , & V_2 -> V_40 -> V_176 ,
V_2 -> V_40 -> V_177 ) ;
F_97 ( & V_13 -> V_174 ) ;
F_98 ( V_2 -> V_40 ) ;
}
F_99 ( & V_13 -> V_178 ) ;
F_91 ( & V_13 -> V_179 ) ;
F_91 ( & V_2 -> V_180 ) ;
V_2 -> V_6 . V_75 = false ;
F_91 ( & V_2 -> V_181 ) ;
F_100 ( & V_2 -> V_182 ) ;
if ( V_2 -> V_111 . V_183 ) {
V_171 = V_2 -> V_6 . V_11 . V_171 ;
F_43 ( V_13 -> V_184 ) ;
F_24 ( & V_13 -> V_29 ) ;
F_52 ( V_2 ) ;
F_25 ( & V_13 -> V_29 ) ;
F_101 ( V_2 -> V_40 , & V_171 ,
V_185 ,
V_102 ) ;
}
if ( V_2 -> V_6 . type == V_68 ) {
struct V_1 * V_123 , * V_186 ;
F_102 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_103 ( V_123 -> V_40 ) ;
F_43 ( ! F_15 ( & V_2 -> V_57 . V_78 . V_125 ) ) ;
} else if ( V_2 -> V_6 . type == V_70 ) {
V_169 = & V_2 -> V_77 -> V_169 ;
F_76 ( & V_169 -> V_187 . V_188 , V_18 ) ;
F_104 (&ps->bc_buf, skb, tmp) {
if ( V_166 -> V_40 == V_2 -> V_40 ) {
F_105 ( V_166 , & V_169 -> V_187 ) ;
V_13 -> V_189 -- ;
F_106 ( & V_13 -> V_16 , V_166 ) ;
}
}
F_79 ( & V_169 -> V_187 . V_188 , V_18 ) ;
}
if ( V_164 )
V_13 -> V_132 -- ;
switch ( V_2 -> V_6 . type ) {
case V_70 :
F_81 ( & V_2 -> V_57 . V_123 . V_124 ) ;
F_45 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_56 :
if ( V_2 -> V_57 . V_58 & V_140 ) {
V_13 -> V_141 -- ;
break;
}
V_13 -> V_31 -- ;
if ( V_13 -> V_31 == 0 ) {
V_13 -> V_16 . V_17 . V_18 &= ~ V_142 ;
V_118 |= V_143 ;
}
F_36 ( V_2 , - 1 ) ;
break;
case V_67 :
F_45 ( V_13 -> V_152 , NULL ) ;
default:
F_91 ( & V_2 -> V_190 ) ;
F_107 ( V_2 , true ) ;
case V_68 :
F_108 ( & V_2 -> V_191 ) ;
}
V_2 -> V_77 = NULL ;
F_76 ( & V_13 -> V_159 , V_18 ) ;
for ( V_81 = 0 ; V_81 < V_192 ; V_81 ++ ) {
F_104 (&local->pending[i], skb, tmp) {
struct V_193 * V_194 = F_109 ( V_166 ) ;
if ( V_194 -> V_95 . V_6 == & V_2 -> V_6 ) {
F_105 ( V_166 , & V_13 -> V_161 [ V_81 ] ) ;
F_106 ( & V_13 -> V_16 , V_166 ) ;
}
}
}
F_79 ( & V_13 -> V_159 , V_18 ) ;
if ( V_13 -> V_132 == 0 )
F_110 ( V_13 ) ;
if ( V_13 -> V_184 ) {
F_43 ( V_13 -> V_195 ) ;
F_43 ( F_60 ( V_13 -> V_100 ) ) ;
return;
}
switch ( V_2 -> V_6 . type ) {
case V_70 :
break;
case V_56 :
if ( V_13 -> V_31 == 0 )
F_49 ( V_13 ) ;
F_24 ( & V_13 -> V_29 ) ;
F_20 ( V_13 ) ;
F_25 ( & V_13 -> V_29 ) ;
if ( ! ( V_2 -> V_57 . V_58 & V_59 ) )
break;
default:
if ( V_164 )
F_48 ( V_13 , V_2 ) ;
}
F_74 ( V_13 , - 1 ) ;
if ( V_13 -> V_132 == 0 ) {
F_111 ( V_13 ) ;
return;
}
F_64 ( V_13 ) ;
F_7 ( V_13 , V_118 ) ;
if ( V_13 -> V_31 == V_13 -> V_132 )
F_39 ( V_13 ) ;
}
static int F_112 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
F_84 ( V_2 , true ) ;
return 0 ;
}
static void F_113 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
int V_196 , V_197 , V_198 , V_199 ;
V_196 = ! ! ( V_40 -> V_18 & V_200 ) ;
V_197 = ! ! ( V_40 -> V_18 & V_201 ) ;
V_198 = ! ! ( V_2 -> V_18 & V_153 ) ;
V_199 = ! ! ( V_2 -> V_18 & V_155 ) ;
if ( V_196 != V_198 ) {
if ( V_40 -> V_18 & V_200 )
F_73 ( & V_13 -> V_154 ) ;
else
F_93 ( & V_13 -> V_154 ) ;
V_2 -> V_18 ^= V_153 ;
}
if ( V_197 != V_199 ) {
if ( V_40 -> V_18 & V_201 )
F_73 ( & V_13 -> V_156 ) ;
else
F_93 ( & V_13 -> V_156 ) ;
V_2 -> V_18 ^= V_155 ;
}
F_95 ( & V_13 -> V_174 ) ;
F_114 ( & V_13 -> V_175 , & V_40 -> V_176 , V_40 -> V_177 ) ;
F_97 ( & V_13 -> V_174 ) ;
F_115 ( & V_13 -> V_16 , & V_13 -> V_202 ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
int V_81 ;
F_107 ( V_2 , false ) ;
F_117 ( V_2 ) ;
for ( V_81 = 0 ; V_81 < V_203 ; V_81 ++ )
F_118 ( & V_2 -> V_204 [ V_81 ] . V_205 ) ;
V_2 -> V_206 = 0 ;
if ( F_119 ( & V_2 -> V_6 ) )
F_120 ( V_2 ) ;
}
static void F_121 ( struct V_39 * V_40 )
{
F_116 ( F_27 ( V_40 ) ) ;
}
static T_6 F_122 ( struct V_39 * V_40 ,
struct V_165 * V_166 ,
void * V_207 ,
T_7 V_208 )
{
return F_123 ( F_27 ( V_40 ) , V_166 ) ;
}
static T_6 F_124 ( struct V_39 * V_40 ,
struct V_165 * V_166 ,
void * V_207 ,
T_7 V_208 )
{
struct V_1 * V_2 = F_27 ( V_40 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_209 * V_210 ;
struct V_211 * V_212 = ( void * ) V_166 -> V_213 ;
if ( V_13 -> V_16 . V_80 < V_82 )
return 0 ;
if ( V_166 -> V_214 < 4 ||
V_166 -> V_214 < F_125 ( V_212 -> V_215 ) + 2 )
return 0 ;
V_210 = ( void * ) ( ( T_2 * ) V_166 -> V_213 + F_125 ( V_212 -> V_215 ) ) ;
return F_126 ( V_2 , V_166 , V_210 ) ;
}
static void F_127 ( struct V_39 * V_40 )
{
F_128 ( V_40 ) ;
V_40 -> V_216 &= ~ V_217 ;
V_40 -> V_218 = & V_219 ;
V_40 -> V_220 = V_221 ;
}
static void F_129 ( struct V_222 * V_190 )
{
struct V_1 * V_2 =
F_57 ( V_190 , struct V_1 , V_190 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_165 * V_166 ;
struct V_114 * V_115 ;
struct V_223 * V_224 ;
if ( ! F_28 ( V_2 ) )
return;
if ( V_13 -> V_23 )
return;
if ( F_130 ( V_13 -> V_184 ,
L_2 ) )
return;
while ( ( V_166 = F_131 ( & V_2 -> V_191 ) ) ) {
struct V_225 * V_226 = ( void * ) V_166 -> V_213 ;
if ( V_166 -> V_227 == V_228 ) {
V_224 = ( void * ) & V_166 -> V_229 ;
F_132 ( & V_2 -> V_6 , V_224 -> V_230 ,
V_224 -> V_231 ) ;
} else if ( V_166 -> V_227 == V_232 ) {
V_224 = ( void * ) & V_166 -> V_229 ;
F_133 ( & V_2 -> V_6 , V_224 -> V_230 ,
V_224 -> V_231 ) ;
} else if ( F_134 ( V_226 -> V_233 ) &&
V_226 -> V_57 . V_234 . V_235 == V_236 ) {
int V_214 = V_166 -> V_214 ;
F_24 ( & V_13 -> V_237 ) ;
V_115 = F_135 ( V_2 , V_226 -> V_61 ) ;
if ( V_115 ) {
switch ( V_226 -> V_57 . V_234 . V_57 . V_238 . V_239 ) {
case V_240 :
F_136 (
V_13 , V_115 , V_226 , V_214 ) ;
break;
case V_241 :
F_137 ( V_13 , V_115 ,
V_226 , V_214 ) ;
break;
case V_242 :
F_138 ( V_2 , V_115 ,
V_226 , V_214 ) ;
break;
default:
F_43 ( 1 ) ;
break;
}
}
F_25 ( & V_13 -> V_237 ) ;
} else if ( F_139 ( V_226 -> V_233 ) ) {
struct V_209 * V_210 = ( void * ) V_226 ;
F_43 ( V_210 -> V_233 &
F_140 ( V_243 ) ) ;
F_43 ( ! ( V_210 -> V_244 &
F_140 ( V_245 ) ) ) ;
F_24 ( & V_13 -> V_237 ) ;
V_115 = F_135 ( V_2 , V_226 -> V_61 ) ;
if ( V_115 ) {
T_6 V_231 = * F_141 ( V_210 ) &
V_246 ;
F_142 (
V_115 , V_231 , V_247 ,
V_248 ,
true ) ;
}
F_25 ( & V_13 -> V_237 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_128 :
F_143 ( V_2 , V_166 ) ;
break;
case V_74 :
F_144 ( V_2 , V_166 ) ;
break;
case V_86 :
if ( ! F_119 ( & V_2 -> V_6 ) )
break;
F_145 ( V_2 , V_166 ) ;
break;
default:
F_130 ( 1 , L_3 ) ;
break;
}
F_146 ( V_166 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_128 :
F_147 ( V_2 ) ;
break;
case V_74 :
F_148 ( V_2 ) ;
break;
case V_86 :
if ( ! F_119 ( & V_2 -> V_6 ) )
break;
F_149 ( V_2 ) ;
break;
default:
break;
}
}
static void F_150 ( struct V_222 * V_190 )
{
struct V_1 * V_2 =
F_57 ( V_190 , struct V_1 , V_180 ) ;
F_151 ( V_2 ) ;
}
static void F_152 ( struct V_1 * V_2 ,
enum V_71 type )
{
memset ( & V_2 -> V_57 , 0 , sizeof( V_2 -> V_57 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_249 = false ;
V_2 -> V_111 . V_72 = type ;
V_2 -> V_126 = F_153 ( V_250 ) ;
V_2 -> V_127 = false ;
V_2 -> V_106 = V_107 ;
V_2 -> V_251 = 0 ;
if ( V_2 -> V_40 ) {
V_2 -> V_40 -> V_218 = & V_219 ;
V_2 -> V_40 -> type = V_252 ;
}
F_154 ( & V_2 -> V_191 ) ;
F_155 ( & V_2 -> V_190 , F_129 ) ;
F_155 ( & V_2 -> V_180 , F_150 ) ;
F_155 ( & V_2 -> V_181 , V_253 ) ;
switch ( type ) {
case V_85 :
type = V_68 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_249 = true ;
case V_68 :
F_154 ( & V_2 -> V_57 . V_78 . V_169 . V_187 ) ;
F_156 ( & V_2 -> V_57 . V_78 . V_125 ) ;
F_155 ( & V_2 -> V_57 . V_78 . V_173 ,
V_254 ) ;
V_2 -> V_6 . V_11 . V_255 = V_2 -> V_6 . V_45 ;
V_2 -> V_57 . V_78 . V_256 = V_257 ;
break;
case V_131 :
type = V_128 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_249 = true ;
case V_128 :
V_2 -> V_6 . V_11 . V_255 = V_2 -> V_57 . V_258 . V_255 ;
F_157 ( V_2 ) ;
break;
case V_74 :
V_2 -> V_6 . V_11 . V_255 = V_2 -> V_57 . V_259 . V_255 ;
F_158 ( V_2 ) ;
break;
case V_86 :
if ( F_119 ( & V_2 -> V_6 ) )
F_159 ( V_2 ) ;
break;
case V_56 :
V_2 -> V_40 -> type = V_260 ;
V_2 -> V_40 -> V_218 = & V_261 ;
V_2 -> V_57 . V_58 = V_262 |
V_263 ;
break;
case V_69 :
V_2 -> V_6 . V_11 . V_255 = NULL ;
break;
case V_70 :
case V_67 :
V_2 -> V_6 . V_11 . V_255 = V_2 -> V_6 . V_45 ;
break;
case V_129 :
case V_130 :
F_160 () ;
break;
}
F_161 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 ,
enum V_71 type )
{
struct V_15 * V_13 = V_2 -> V_13 ;
int V_52 , V_163 ;
enum V_71 V_264 = type ;
bool V_249 = false ;
F_32 () ;
if ( ! V_13 -> V_32 -> V_265 )
return - V_62 ;
switch ( V_2 -> V_6 . type ) {
case V_68 :
case V_128 :
case V_74 :
break;
default:
return - V_62 ;
}
switch ( type ) {
case V_68 :
case V_128 :
case V_74 :
break;
case V_131 :
V_249 = true ;
V_264 = V_128 ;
break;
case V_85 :
V_249 = true ;
V_264 = V_68 ;
break;
default:
return - V_62 ;
}
V_52 = F_31 ( V_2 , V_264 ) ;
if ( V_52 )
return V_52 ;
F_84 ( V_2 , false ) ;
F_116 ( V_2 ) ;
V_52 = F_163 ( V_13 , V_2 , V_264 , V_249 ) ;
if ( V_52 )
type = F_65 ( & V_2 -> V_6 ) ;
F_34 ( V_2 , type ) ;
F_152 ( V_2 , type ) ;
V_163 = F_53 ( & V_2 -> V_111 , false ) ;
F_130 ( V_163 , L_4 , V_163 ) ;
return V_52 ;
}
int F_164 ( struct V_1 * V_2 ,
enum V_71 type )
{
int V_52 ;
F_32 () ;
if ( type == F_65 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_28 ( V_2 ) ) {
V_52 = F_162 ( V_2 , type ) ;
if ( V_52 )
return V_52 ;
} else {
F_116 ( V_2 ) ;
F_152 ( V_2 , type ) ;
}
V_2 -> V_266 = 0 ;
if ( type == V_128 )
V_2 -> V_57 . V_258 . V_267 = false ;
return 0 ;
}
static void F_165 ( struct V_15 * V_13 ,
T_2 * V_136 , enum V_71 type )
{
struct V_1 * V_2 ;
T_3 V_49 , V_268 , V_45 , V_269 , V_270 ;
T_2 * V_51 ;
T_2 V_271 [ V_64 ] ;
int V_81 ;
memcpy ( V_136 , V_13 -> V_16 . V_53 -> V_136 , V_64 ) ;
if ( F_23 ( V_13 -> V_16 . V_53 -> V_54 ) &&
V_13 -> V_16 . V_53 -> V_272 <= 1 )
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
memcpy ( V_136 , V_2 -> V_6 . V_45 , V_64 ) ;
break;
}
break;
case V_131 :
case V_85 :
if ( V_13 -> V_16 . V_18 & V_273 ) {
F_16 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_67 )
continue;
if ( ! F_28 ( V_2 ) )
continue;
memcpy ( V_136 , V_2 -> V_6 . V_45 , V_64 ) ;
goto V_274;
}
}
default:
for ( V_81 = 0 ; V_81 < V_13 -> V_16 . V_53 -> V_272 ; V_81 ++ ) {
bool V_275 = false ;
F_16 (sdata, &local->interfaces, list) {
if ( F_33 ( V_13 -> V_16 . V_53 -> V_276 [ V_81 ] . V_45 ,
V_2 -> V_6 . V_45 ) ) {
V_275 = true ;
break;
}
}
if ( ! V_275 ) {
memcpy ( V_136 ,
V_13 -> V_16 . V_53 -> V_276 [ V_81 ] . V_45 ,
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
if ( F_166 ( V_49 ) + F_167 ( V_49 ) != F_168 ( V_49 ) ) {
F_169 ( L_5 ) ;
break;
}
V_51 = V_13 -> V_16 . V_53 -> V_136 ;
F_16 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_56 )
continue;
V_51 = V_2 -> V_6 . V_45 ;
break;
}
V_268 = ( ( T_3 ) V_51 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_51 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_51 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_51 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_51 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_51 [ 5 ] << 0 * 8 ) ;
V_270 = 1ULL << F_166 ( V_49 ) ;
V_269 = ( V_268 & V_49 ) ;
V_45 = ( V_268 & ~ V_49 ) | ( V_269 & V_49 ) ;
do {
bool V_275 = false ;
V_271 [ 5 ] = V_45 >> 0 * 8 ;
V_271 [ 4 ] = V_45 >> 1 * 8 ;
V_271 [ 3 ] = V_45 >> 2 * 8 ;
V_271 [ 2 ] = V_45 >> 3 * 8 ;
V_271 [ 1 ] = V_45 >> 4 * 8 ;
V_271 [ 0 ] = V_45 >> 5 * 8 ;
V_269 += V_270 ;
F_16 (sdata, &local->interfaces, list) {
if ( F_33 ( V_271 , V_2 -> V_6 . V_45 ) ) {
V_275 = true ;
break;
}
}
if ( ! V_275 ) {
memcpy ( V_136 , V_271 , V_64 ) ;
break;
}
V_45 = ( V_268 & ~ V_49 ) | ( V_269 & V_49 ) ;
} while ( V_45 != V_268 );
break;
}
V_274:
F_25 ( & V_13 -> V_55 ) ;
}
int F_170 ( struct V_15 * V_13 , const char * V_104 ,
struct V_110 * * V_277 , enum V_71 type ,
struct V_278 * V_279 )
{
struct V_39 * V_280 = NULL ;
struct V_1 * V_2 = NULL ;
int V_52 , V_81 ;
int V_281 = 1 ;
F_32 () ;
if ( type == V_67 ) {
struct V_110 * V_111 ;
V_2 = F_40 ( sizeof( * V_2 ) + V_13 -> V_16 . V_101 ,
V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_111 = & V_2 -> V_111 ;
V_2 -> V_40 = NULL ;
F_171 ( V_2 -> V_104 , V_104 , V_105 ) ;
F_165 ( V_13 , V_111 -> V_282 , type ) ;
memcpy ( V_2 -> V_6 . V_45 , V_111 -> V_282 , V_64 ) ;
} else {
if ( V_13 -> V_16 . V_80 >= V_82 )
V_281 = V_82 ;
V_280 = F_172 ( sizeof( * V_2 ) +
V_13 -> V_16 . V_101 ,
V_104 , F_127 , V_281 , 1 ) ;
if ( ! V_280 )
return - V_103 ;
F_173 ( V_280 , F_174 ( V_13 -> V_16 . V_53 ) ) ;
V_280 -> V_283 = V_13 -> V_284 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_285
+ V_107 ;
V_280 -> V_286 = V_287 ;
V_52 = F_175 ( V_280 , V_280 -> V_104 ) ;
if ( V_52 < 0 ) {
V_221 ( V_280 ) ;
return V_52 ;
}
F_165 ( V_13 , V_280 -> V_136 , type ) ;
memcpy ( V_280 -> V_135 , V_280 -> V_136 , V_64 ) ;
F_176 ( V_280 , F_177 ( V_13 -> V_16 . V_53 ) ) ;
V_2 = F_178 ( V_280 ) ;
V_280 -> V_288 = & V_2 -> V_111 ;
memcpy ( V_2 -> V_6 . V_45 , V_280 -> V_135 , V_64 ) ;
memcpy ( V_2 -> V_104 , V_280 -> V_104 , V_105 ) ;
V_2 -> V_40 = V_280 ;
}
V_2 -> V_111 . V_53 = V_13 -> V_16 . V_53 ;
V_2 -> V_13 = V_13 ;
for ( V_81 = 0 ; V_81 < V_203 ; V_81 ++ )
F_154 ( & V_2 -> V_204 [ V_81 ] . V_205 ) ;
F_156 ( & V_2 -> V_289 ) ;
F_179 ( & V_2 -> V_182 ,
V_290 ) ;
F_179 ( & V_2 -> V_291 ,
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
V_2 -> V_106 = V_107 ;
F_152 ( V_2 , type ) ;
if ( V_280 ) {
if ( V_279 ) {
V_280 -> V_288 -> V_267 = V_279 -> V_267 ;
if ( type == V_128 )
V_2 -> V_57 . V_258 . V_267 = V_279 -> V_267 ;
}
V_280 -> V_303 |= V_13 -> V_16 . V_304 ;
V_52 = F_180 ( V_280 ) ;
if ( V_52 ) {
V_221 ( V_280 ) ;
return V_52 ;
}
}
F_24 ( & V_13 -> V_55 ) ;
F_181 ( & V_2 -> V_124 , & V_13 -> V_305 ) ;
F_25 ( & V_13 -> V_55 ) ;
if ( V_277 )
* V_277 = & V_2 -> V_111 ;
return 0 ;
}
void F_182 ( struct V_1 * V_2 )
{
F_32 () ;
F_24 ( & V_2 -> V_13 -> V_55 ) ;
F_183 ( & V_2 -> V_124 ) ;
F_25 ( & V_2 -> V_13 -> V_55 ) ;
F_184 () ;
if ( V_2 -> V_40 ) {
F_185 ( V_2 -> V_40 ) ;
} else {
F_186 ( & V_2 -> V_111 ) ;
F_44 ( V_2 ) ;
}
}
void F_187 ( struct V_1 * V_2 )
{
if ( F_35 ( ! F_17 ( V_147 , & V_2 -> V_148 ) ) )
return;
F_84 ( V_2 , true ) ;
F_116 ( V_2 ) ;
}
void F_188 ( struct V_15 * V_13 )
{
struct V_1 * V_2 , * V_50 ;
F_189 ( V_306 ) ;
F_189 ( V_307 ) ;
F_32 () ;
F_16 (sdata, &local->interfaces, list)
if ( V_2 -> V_6 . type == V_70 )
F_103 ( V_2 -> V_40 ) ;
F_24 ( & V_13 -> V_55 ) ;
F_102 (sdata, tmp, &local->interfaces, list) {
F_81 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_40 )
F_190 ( V_2 -> V_40 , & V_306 ) ;
else
F_56 ( & V_2 -> V_124 , & V_307 ) ;
}
F_25 ( & V_13 -> V_55 ) ;
F_191 ( & V_306 ) ;
F_81 ( & V_306 ) ;
F_102 (sdata, tmp, &wdev_list, list) {
F_81 ( & V_2 -> V_124 ) ;
F_186 ( & V_2 -> V_111 ) ;
F_44 ( V_2 ) ;
}
}
static int F_192 ( struct V_308 * V_309 ,
unsigned long V_148 , void * V_310 )
{
struct V_39 * V_40 = F_193 ( V_310 ) ;
struct V_1 * V_2 ;
if ( V_148 != V_311 )
return 0 ;
if ( ! V_40 -> V_288 || ! V_40 -> V_288 -> V_53 )
return 0 ;
if ( V_40 -> V_288 -> V_53 -> V_312 != V_313 )
return 0 ;
V_2 = F_27 ( V_40 ) ;
memcpy ( V_2 -> V_104 , V_40 -> V_104 , V_105 ) ;
F_194 ( V_2 ) ;
return 0 ;
}
int F_195 ( void )
{
return F_196 ( & V_314 ) ;
}
void F_197 ( void )
{
F_198 ( & V_314 ) ;
}
