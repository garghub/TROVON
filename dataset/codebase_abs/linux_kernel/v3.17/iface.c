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
bool V_22 , V_23 , V_24 ;
unsigned int V_25 = 0 , V_26 = 0 ;
F_14 ( & V_13 -> V_27 ) ;
V_24 = V_21 ||
! F_15 ( & V_13 -> V_28 ) ||
V_13 -> V_29 ;
V_22 = ! V_13 -> V_30 -> V_31 &&
! F_15 ( & V_13 -> V_32 ) ;
V_23 = F_16 ( V_33 , & V_13 -> V_23 ) ||
F_16 ( V_34 , & V_13 -> V_23 ) ;
if ( V_22 || V_23 )
V_25 |= V_35 ;
else
V_26 |= V_35 ;
if ( V_24 )
V_25 |= V_36 ;
else
V_26 |= V_36 ;
F_17 ( V_13 , V_25 , V_26 ) ;
if ( V_22 || V_23 || V_24 )
return F_10 ( V_13 ) ;
return F_11 ( V_13 ) ;
}
T_1 F_18 ( struct V_15 * V_13 )
{
return F_13 ( V_13 , true ) ;
}
void F_19 ( struct V_15 * V_13 )
{
T_1 V_37 = F_13 ( V_13 , false ) ;
if ( V_37 )
F_7 ( V_13 , V_37 ) ;
}
static int F_20 ( struct V_38 * V_39 , int V_40 )
{
if ( V_40 < 256 || V_40 > V_41 )
return - V_42 ;
V_39 -> V_43 = V_40 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 * V_44 ,
bool V_45 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_1 * V_46 ;
T_3 V_47 , V_48 , V_49 ;
T_2 * V_50 ;
int V_51 = 0 ;
if ( F_22 ( V_13 -> V_16 . V_52 -> V_53 ) )
return 0 ;
V_50 = V_44 ;
V_47 = ( ( T_3 ) V_50 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_50 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_50 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_50 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_50 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_50 [ 5 ] << 0 * 8 ) ;
V_50 = V_13 -> V_16 . V_52 -> V_53 ;
V_48 = ( ( T_3 ) V_50 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_50 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_50 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_50 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_50 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_50 [ 5 ] << 0 * 8 ) ;
if ( ! V_45 )
return V_51 ;
F_23 ( & V_13 -> V_54 ) ;
F_24 (iter, &local->interfaces, list) {
if ( V_46 == V_2 )
continue;
if ( V_46 -> V_6 . type == V_55 &&
! ( V_46 -> V_56 . V_57 & V_58 ) )
continue;
V_50 = V_46 -> V_6 . V_44 ;
V_49 = ( ( T_3 ) V_50 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_50 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_50 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_50 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_50 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_50 [ 5 ] << 0 * 8 ) ;
if ( ( V_47 & ~ V_48 ) != ( V_49 & ~ V_48 ) ) {
V_51 = - V_42 ;
break;
}
}
F_25 ( & V_13 -> V_54 ) ;
return V_51 ;
}
static int F_26 ( struct V_38 * V_39 , void * V_44 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
struct V_59 * V_60 = V_44 ;
bool V_45 = true ;
int V_51 ;
if ( F_28 ( V_2 ) )
return - V_61 ;
if ( V_2 -> V_6 . type == V_55 &&
! ( V_2 -> V_56 . V_57 & V_58 ) )
V_45 = false ;
V_51 = F_21 ( V_2 , V_60 -> V_62 , V_45 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_29 ( V_39 , V_60 ) ;
if ( V_51 == 0 )
memcpy ( V_2 -> V_6 . V_44 , V_60 -> V_62 , V_63 ) ;
return V_51 ;
}
static inline int F_30 ( int V_64 , int V_65 )
{
return V_64 == V_55 ||
V_65 == V_55 ||
V_64 == V_66 ||
V_65 == V_66 ||
( V_64 == V_67 && V_65 == V_68 ) ||
( V_64 == V_68 &&
( V_65 == V_68 ||
V_65 == V_67 ) ) ||
( V_64 == V_67 && V_65 == V_69 ) ||
( V_64 == V_69 &&
( V_65 == V_67 ||
V_65 == V_69 ) ) ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_1 * V_72 ;
int V_51 ;
F_32 () ;
F_24 (nsdata, &local->interfaces, list) {
if ( V_72 != V_2 && F_28 ( V_72 ) ) {
if ( V_71 == V_73 &&
V_72 -> V_6 . type == V_73 )
return - V_61 ;
if ( V_72 -> V_6 . V_74 )
return - V_61 ;
if ( ! F_33 ( V_2 -> V_6 . V_44 ,
V_72 -> V_6 . V_44 ) )
continue;
if ( ! F_30 ( V_71 ,
V_72 -> V_6 . type ) )
return - V_75 ;
if ( V_71 == V_69 &&
V_72 -> V_6 . type == V_67 )
V_2 -> V_76 = & V_72 -> V_56 . V_77 ;
}
}
F_23 ( & V_13 -> V_78 ) ;
V_51 = F_34 ( V_2 , NULL , 0 , 0 ) ;
F_25 ( & V_13 -> V_78 ) ;
return V_51 ;
}
static int F_35 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
int V_79 = V_2 -> V_13 -> V_16 . V_80 ;
int V_81 ;
if ( V_71 != V_66 ) {
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ ) {
if ( F_36 ( V_2 -> V_6 . V_83 [ V_81 ] ==
V_84 ) )
return - V_42 ;
if ( F_36 ( V_2 -> V_6 . V_83 [ V_81 ] >=
V_79 ) )
return - V_42 ;
}
}
if ( ( V_71 != V_67 &&
V_71 != V_85 &&
V_71 != V_86 ) ||
! ( V_2 -> V_13 -> V_16 . V_18 & V_87 ) ) {
V_2 -> V_6 . V_88 = V_84 ;
return 0 ;
}
if ( F_36 ( V_2 -> V_6 . V_88 == V_84 ) )
return - V_42 ;
if ( F_36 ( V_2 -> V_6 . V_88 >= V_79 ) )
return - V_42 ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 ,
const int V_89 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
T_1 V_18 = V_2 -> V_56 . V_57 ;
#define F_38 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_38 ( V_90 , V_91 ) ;
F_38 ( V_92 , V_93 ) ;
F_38 ( V_94 , V_95 ) ;
F_38 ( V_94 , V_96 ) ;
F_38 ( V_97 , V_98 ) ;
#undef F_38
}
static void F_39 ( struct V_1 * V_2 )
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
int F_40 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
int V_51 ;
if ( ! ( V_13 -> V_16 . V_18 & V_99 ) )
return 0 ;
F_32 () ;
if ( V_13 -> V_100 )
return 0 ;
V_2 = F_41 ( sizeof( * V_2 ) + V_13 -> V_16 . V_101 , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 . type = V_55 ;
snprintf ( V_2 -> V_104 , V_105 , L_1 ,
F_42 ( V_13 -> V_16 . V_52 ) ) ;
V_2 -> V_106 . V_71 = V_55 ;
V_2 -> V_107 = V_108 ;
F_39 ( V_2 ) ;
V_51 = F_43 ( V_13 , V_2 ) ;
if ( F_44 ( V_51 ) ) {
F_45 ( V_2 ) ;
return V_51 ;
}
V_51 = F_35 ( V_2 , V_55 ) ;
if ( V_51 ) {
F_45 ( V_2 ) ;
return V_51 ;
}
F_23 ( & V_13 -> V_54 ) ;
F_46 ( V_13 -> V_100 , V_2 ) ;
F_25 ( & V_13 -> V_54 ) ;
F_23 ( & V_13 -> V_27 ) ;
V_51 = F_47 ( V_2 , & V_13 -> V_109 ,
V_110 ) ;
F_25 ( & V_13 -> V_27 ) ;
if ( V_51 ) {
F_23 ( & V_13 -> V_54 ) ;
F_48 ( V_13 -> V_100 , NULL ) ;
F_25 ( & V_13 -> V_54 ) ;
F_49 () ;
F_50 ( V_13 , V_2 ) ;
F_45 ( V_2 ) ;
return V_51 ;
}
return 0 ;
}
void F_51 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
if ( ! ( V_13 -> V_16 . V_18 & V_99 ) )
return;
F_32 () ;
F_23 ( & V_13 -> V_54 ) ;
V_2 = F_52 ( V_13 -> V_100 ,
F_53 ( & V_13 -> V_54 ) ) ;
if ( ! V_2 ) {
F_25 ( & V_13 -> V_54 ) ;
return;
}
F_48 ( V_13 -> V_100 , NULL ) ;
F_25 ( & V_13 -> V_54 ) ;
F_49 () ;
F_23 ( & V_13 -> V_27 ) ;
F_54 ( V_2 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_50 ( V_13 , V_2 ) ;
F_45 ( V_2 ) ;
}
int F_55 ( struct V_111 * V_106 , bool V_112 )
{
struct V_1 * V_2 = F_56 ( V_106 ) ;
struct V_38 * V_39 = V_106 -> V_113 ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_114 * V_115 ;
T_1 V_116 = 0 ;
int V_117 ;
T_1 V_118 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_68 :
if ( ! F_57 ( V_2 -> V_56 . V_119 . V_120 ) )
return - V_121 ;
break;
case V_69 : {
struct V_1 * V_122 ;
if ( ! V_2 -> V_76 )
return - V_121 ;
F_23 ( & V_13 -> V_27 ) ;
F_58 ( & V_2 -> V_56 . V_123 . V_124 , & V_2 -> V_76 -> V_125 ) ;
F_25 ( & V_13 -> V_27 ) ;
V_122 = F_59 ( V_2 -> V_76 ,
struct V_1 , V_56 . V_77 ) ;
V_2 -> V_126 =
V_122 -> V_126 ;
V_2 -> V_127 =
V_122 -> V_127 ;
V_2 -> V_6 . V_88 = V_122 -> V_6 . V_88 ;
memcpy ( V_2 -> V_6 . V_83 , V_122 -> V_6 . V_83 ,
sizeof( V_2 -> V_6 . V_83 ) ) ;
break;
}
case V_67 :
V_2 -> V_76 = & V_2 -> V_56 . V_77 ;
break;
case V_86 :
case V_128 :
case V_55 :
case V_73 :
case V_66 :
break;
case V_129 :
case V_130 :
case V_131 :
case V_85 :
F_44 ( 1 ) ;
break;
}
if ( V_13 -> V_132 == 0 ) {
V_117 = F_60 ( V_13 ) ;
if ( V_117 )
goto V_133;
V_118 = ~ 0 ;
F_61 ( V_13 , true ) ;
F_17 ( V_13 ,
V_134 , 0 ) ;
}
if ( V_39 && F_22 ( V_39 -> V_135 ) ) {
memcpy ( V_39 -> V_135 ,
V_13 -> V_16 . V_52 -> V_136 ,
V_63 ) ;
memcpy ( V_39 -> V_136 , V_39 -> V_135 , V_63 ) ;
if ( ! F_57 ( V_39 -> V_135 ) ) {
V_117 = - V_137 ;
goto V_138;
}
}
switch ( V_2 -> V_6 . type ) {
case V_69 :
if ( F_62 ( V_2 -> V_76 -> V_139 ) ) {
F_63 ( V_2 ) ;
F_64 ( V_39 ) ;
} else {
F_65 ( V_39 ) ;
}
break;
case V_55 :
if ( V_2 -> V_56 . V_57 & V_140 ) {
V_13 -> V_141 ++ ;
break;
}
if ( V_2 -> V_56 . V_57 & V_58 ) {
V_117 = F_43 ( V_13 , V_2 ) ;
if ( V_117 )
goto V_138;
} else if ( V_13 -> V_29 == 0 && V_13 -> V_132 == 0 ) {
V_117 = F_40 ( V_13 ) ;
if ( V_117 )
goto V_138;
}
V_13 -> V_29 ++ ;
if ( V_13 -> V_29 == 1 ) {
V_13 -> V_16 . V_17 . V_18 |= V_142 ;
V_118 |= V_143 ;
}
F_37 ( V_2 , 1 ) ;
F_66 ( V_13 ) ;
F_23 ( & V_13 -> V_27 ) ;
F_19 ( V_13 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_64 ( V_39 ) ;
break;
default:
if ( V_112 ) {
F_51 ( V_13 ) ;
V_117 = F_43 ( V_13 , V_2 ) ;
if ( V_117 )
goto V_138;
V_117 = F_35 ( V_2 ,
F_67 ( & V_2 -> V_6 ) ) ;
if ( V_117 )
goto V_144;
}
if ( V_2 -> V_6 . type == V_67 ) {
V_13 -> V_145 ++ ;
V_13 -> V_146 ++ ;
F_66 ( V_13 ) ;
} else if ( V_2 -> V_6 . type == V_73 ) {
V_13 -> V_146 ++ ;
}
if ( V_2 -> V_6 . type != V_66 )
V_116 |= F_68 ( V_2 ) ;
F_9 ( V_2 , V_116 ) ;
switch ( V_2 -> V_6 . type ) {
case V_128 :
case V_73 :
case V_67 :
case V_86 :
F_65 ( V_39 ) ;
break;
case V_68 :
case V_66 :
break;
default:
F_44 ( 1 ) ;
}
F_69 ( V_2 , true ) ;
}
F_70 ( V_147 , & V_2 -> V_148 ) ;
if ( V_2 -> V_6 . type == V_68 ) {
V_115 = F_71 ( V_2 , V_2 -> V_56 . V_119 . V_120 ,
V_102 ) ;
if ( ! V_115 ) {
V_117 = - V_103 ;
goto V_144;
}
F_72 ( V_115 , V_149 ) ;
F_72 ( V_115 , V_150 ) ;
F_72 ( V_115 , V_151 ) ;
V_117 = F_73 ( V_115 ) ;
if ( V_117 ) {
goto V_144;
}
F_74 ( V_115 ) ;
F_64 ( V_39 ) ;
} else if ( V_2 -> V_6 . type == V_66 ) {
F_46 ( V_13 -> V_152 , V_2 ) ;
}
if ( V_2 -> V_18 & V_153 )
F_75 ( & V_13 -> V_154 ) ;
if ( V_2 -> V_18 & V_155 )
F_75 ( & V_13 -> V_156 ) ;
if ( V_112 )
V_13 -> V_132 ++ ;
if ( V_118 )
F_7 ( V_13 , V_118 ) ;
F_76 ( V_13 , - 1 ) ;
if ( V_2 -> V_6 . type == V_55 ||
V_2 -> V_6 . type == V_69 ) {
F_77 ( V_39 ) ;
} else if ( V_39 ) {
unsigned long V_18 ;
int V_157 = V_82 ;
int V_158 ;
if ( V_13 -> V_16 . V_80 < V_82 )
V_157 = 1 ;
F_78 ( & V_13 -> V_159 , V_18 ) ;
if ( V_2 -> V_6 . V_88 == V_84 ||
( V_13 -> V_160 [ V_2 -> V_6 . V_88 ] == 0 &&
F_79 ( & V_13 -> V_161 [ V_2 -> V_6 . V_88 ] ) ) ) {
for ( V_158 = 0 ; V_158 < V_157 ; V_158 ++ ) {
int V_162 = V_2 -> V_6 . V_83 [ V_158 ] ;
if ( V_13 -> V_160 [ V_162 ] == 0 &&
F_79 ( & V_13 -> V_161 [ V_162 ] ) )
F_80 ( V_39 , V_158 ) ;
}
}
F_81 ( & V_13 -> V_159 , V_18 ) ;
}
return 0 ;
V_144:
F_50 ( V_13 , V_2 ) ;
V_138:
if ( ! V_13 -> V_132 )
F_82 ( V_13 ) ;
V_133:
V_2 -> V_76 = NULL ;
if ( V_2 -> V_6 . type == V_69 ) {
F_23 ( & V_13 -> V_27 ) ;
F_83 ( & V_2 -> V_56 . V_123 . V_124 ) ;
F_25 ( & V_13 -> V_27 ) ;
}
F_84 ( V_147 , & V_2 -> V_148 ) ;
return V_117 ;
}
static int F_85 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
int V_163 ;
if ( ! F_57 ( V_39 -> V_135 ) )
return - V_137 ;
V_163 = F_31 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_163 )
return V_163 ;
return F_55 ( & V_2 -> V_106 , true ) ;
}
static void F_86 ( struct V_1 * V_2 ,
bool V_164 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
unsigned long V_18 ;
struct V_165 * V_166 , * V_49 ;
T_1 V_118 = 0 ;
int V_81 , V_167 ;
struct V_168 * V_169 ;
struct V_170 V_171 ;
F_84 ( V_147 , & V_2 -> V_148 ) ;
if ( F_87 ( V_13 -> V_172 ) == V_2 )
F_88 ( V_13 ) ;
if ( V_2 -> V_39 )
F_89 ( V_2 -> V_39 ) ;
F_90 ( V_13 , V_2 ) ;
switch ( V_2 -> V_6 . type ) {
case V_128 :
F_91 ( V_2 ) ;
break;
case V_73 :
F_92 ( V_2 ) ;
break;
case V_67 :
F_93 ( & V_2 -> V_56 . V_77 . V_173 ) ;
break;
default:
break;
}
V_167 = F_94 ( V_2 ) ;
F_36 ( ( V_2 -> V_6 . type != V_68 && V_167 > 0 ) ||
( V_2 -> V_6 . type == V_68 && V_167 != 1 ) ) ;
if ( V_2 -> V_18 & V_153 )
F_95 ( & V_13 -> V_154 ) ;
if ( V_2 -> V_18 & V_155 )
F_95 ( & V_13 -> V_156 ) ;
if ( V_2 -> V_6 . type == V_67 ) {
V_13 -> V_145 -- ;
V_13 -> V_146 -- ;
} else if ( V_2 -> V_6 . type == V_73 ) {
V_13 -> V_146 -- ;
}
if ( V_2 -> V_39 ) {
F_96 ( V_2 -> V_39 ) ;
F_97 ( & V_13 -> V_174 ) ;
F_98 ( & V_13 -> V_175 , & V_2 -> V_39 -> V_176 ,
V_2 -> V_39 -> V_177 ) ;
F_99 ( & V_13 -> V_174 ) ;
F_100 ( V_2 -> V_39 ) ;
}
F_101 ( & V_13 -> V_178 ) ;
F_93 ( & V_13 -> V_179 ) ;
F_93 ( & V_2 -> V_180 ) ;
F_102 ( V_2 ) ;
F_23 ( & V_13 -> V_27 ) ;
V_2 -> V_6 . V_74 = false ;
if ( V_2 -> V_181 ) {
F_103 ( V_13 , V_2 ,
V_182 ) ;
V_2 -> V_181 = false ;
}
F_25 ( & V_13 -> V_27 ) ;
F_104 ( V_2 ) ;
F_93 ( & V_2 -> V_183 ) ;
F_105 ( & V_2 -> V_184 ) ;
if ( V_2 -> V_106 . V_185 ) {
V_171 = V_2 -> V_6 . V_11 . V_171 ;
F_44 ( V_13 -> V_186 ) ;
F_23 ( & V_13 -> V_27 ) ;
F_54 ( V_2 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_106 ( V_2 -> V_39 , & V_171 ,
V_187 ,
V_102 ) ;
}
if ( V_2 -> V_6 . type == V_67 ) {
struct V_1 * V_123 , * V_188 ;
F_107 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_108 ( V_123 -> V_39 ) ;
F_44 ( ! F_15 ( & V_2 -> V_56 . V_77 . V_125 ) ) ;
} else if ( V_2 -> V_6 . type == V_69 ) {
V_169 = & V_2 -> V_76 -> V_169 ;
F_78 ( & V_169 -> V_189 . V_190 , V_18 ) ;
F_109 (&ps->bc_buf, skb, tmp) {
if ( V_166 -> V_39 == V_2 -> V_39 ) {
F_110 ( V_166 , & V_169 -> V_189 ) ;
V_13 -> V_191 -- ;
F_111 ( & V_13 -> V_16 , V_166 ) ;
}
}
F_81 ( & V_169 -> V_189 . V_190 , V_18 ) ;
}
if ( V_164 )
V_13 -> V_132 -- ;
switch ( V_2 -> V_6 . type ) {
case V_69 :
F_23 ( & V_13 -> V_27 ) ;
F_83 ( & V_2 -> V_56 . V_123 . V_124 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_48 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_55 :
if ( V_2 -> V_56 . V_57 & V_140 ) {
V_13 -> V_141 -- ;
break;
}
V_13 -> V_29 -- ;
if ( V_13 -> V_29 == 0 ) {
V_13 -> V_16 . V_17 . V_18 &= ~ V_142 ;
V_118 |= V_143 ;
}
F_37 ( V_2 , - 1 ) ;
break;
case V_66 :
F_48 ( V_13 -> V_152 , NULL ) ;
default:
F_93 ( & V_2 -> V_192 ) ;
F_112 ( V_2 , true ) ;
case V_67 :
F_113 ( & V_2 -> V_193 ) ;
}
V_2 -> V_76 = NULL ;
F_78 ( & V_13 -> V_159 , V_18 ) ;
for ( V_81 = 0 ; V_81 < V_194 ; V_81 ++ ) {
F_109 (&local->pending[i], skb, tmp) {
struct V_195 * V_196 = F_114 ( V_166 ) ;
if ( V_196 -> V_95 . V_6 == & V_2 -> V_6 ) {
F_110 ( V_166 , & V_13 -> V_161 [ V_81 ] ) ;
F_111 ( & V_13 -> V_16 , V_166 ) ;
}
}
}
F_81 ( & V_13 -> V_159 , V_18 ) ;
if ( V_13 -> V_132 == 0 )
F_115 ( V_13 ) ;
if ( V_13 -> V_186 ) {
F_44 ( V_13 -> V_197 ) ;
F_44 ( F_62 ( V_13 -> V_100 ) ) ;
return;
}
switch ( V_2 -> V_6 . type ) {
case V_69 :
break;
case V_55 :
if ( V_13 -> V_29 == 0 )
F_51 ( V_13 ) ;
F_23 ( & V_13 -> V_27 ) ;
F_19 ( V_13 ) ;
F_25 ( & V_13 -> V_27 ) ;
if ( ! ( V_2 -> V_56 . V_57 & V_58 ) )
break;
default:
if ( V_164 )
F_50 ( V_13 , V_2 ) ;
}
F_76 ( V_13 , - 1 ) ;
if ( V_13 -> V_132 == 0 ) {
F_116 ( V_13 ) ;
return;
}
F_66 ( V_13 ) ;
F_7 ( V_13 , V_118 ) ;
if ( V_13 -> V_29 == V_13 -> V_132 )
F_40 ( V_13 ) ;
}
static int F_117 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
F_86 ( V_2 , true ) ;
return 0 ;
}
static void F_118 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
int V_198 , V_199 , V_200 , V_201 ;
V_198 = ! ! ( V_39 -> V_18 & V_202 ) ;
V_199 = ! ! ( V_39 -> V_18 & V_203 ) ;
V_200 = ! ! ( V_2 -> V_18 & V_153 ) ;
V_201 = ! ! ( V_2 -> V_18 & V_155 ) ;
if ( V_198 != V_200 ) {
if ( V_39 -> V_18 & V_202 )
F_75 ( & V_13 -> V_154 ) ;
else
F_95 ( & V_13 -> V_154 ) ;
V_2 -> V_18 ^= V_153 ;
}
if ( V_199 != V_201 ) {
if ( V_39 -> V_18 & V_203 )
F_75 ( & V_13 -> V_156 ) ;
else
F_95 ( & V_13 -> V_156 ) ;
V_2 -> V_18 ^= V_155 ;
}
F_97 ( & V_13 -> V_174 ) ;
F_119 ( & V_13 -> V_175 , & V_39 -> V_176 , V_39 -> V_177 ) ;
F_99 ( & V_13 -> V_174 ) ;
F_120 ( & V_13 -> V_16 , & V_13 -> V_204 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
int V_81 ;
F_112 ( V_2 , false ) ;
F_122 ( V_2 ) ;
for ( V_81 = 0 ; V_81 < V_205 ; V_81 ++ )
F_123 ( & V_2 -> V_206 [ V_81 ] . V_207 ) ;
V_2 -> V_208 = 0 ;
if ( F_124 ( & V_2 -> V_6 ) )
F_125 ( V_2 ) ;
}
static void F_126 ( struct V_38 * V_39 )
{
F_121 ( F_27 ( V_39 ) ) ;
}
static T_6 F_127 ( struct V_38 * V_39 ,
struct V_165 * V_166 ,
void * V_209 ,
T_7 V_210 )
{
return F_128 ( F_27 ( V_39 ) , V_166 ) ;
}
static T_6 F_129 ( struct V_38 * V_39 ,
struct V_165 * V_166 ,
void * V_209 ,
T_7 V_210 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_211 * V_212 ;
struct V_213 * V_214 = ( void * ) V_166 -> V_215 ;
if ( V_13 -> V_16 . V_80 < V_82 )
return 0 ;
if ( V_166 -> V_216 < 4 ||
V_166 -> V_216 < F_130 ( V_214 -> V_217 ) + 2 )
return 0 ;
V_212 = ( void * ) ( ( T_2 * ) V_166 -> V_215 + F_130 ( V_214 -> V_217 ) ) ;
return F_131 ( V_2 , V_166 , V_212 ) ;
}
static void F_132 ( struct V_38 * V_39 )
{
F_133 ( V_39 ) ;
V_39 -> V_218 &= ~ V_219 ;
V_39 -> V_220 = & V_221 ;
V_39 -> V_222 = V_223 ;
}
static void F_134 ( struct V_224 * V_192 )
{
struct V_1 * V_2 =
F_59 ( V_192 , struct V_1 , V_192 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_165 * V_166 ;
struct V_114 * V_115 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
if ( ! F_28 ( V_2 ) )
return;
if ( V_13 -> V_23 )
return;
if ( F_135 ( V_13 -> V_186 ,
L_2 ) )
return;
while ( ( V_166 = F_136 ( & V_2 -> V_193 ) ) ) {
struct V_229 * V_230 = ( void * ) V_166 -> V_215 ;
if ( V_166 -> V_231 == V_232 ) {
V_226 = ( void * ) & V_166 -> V_233 ;
F_137 ( & V_2 -> V_6 , V_226 -> V_234 ,
V_226 -> V_235 ) ;
} else if ( V_166 -> V_231 == V_236 ) {
V_226 = ( void * ) & V_166 -> V_233 ;
F_138 ( & V_2 -> V_6 , V_226 -> V_234 ,
V_226 -> V_235 ) ;
} else if ( V_166 -> V_231 == V_237 ) {
V_228 = ( void * ) & V_166 -> V_233 ;
F_23 ( & V_13 -> V_238 ) ;
V_115 = F_139 ( V_2 , V_228 -> V_44 ) ;
if ( V_115 ) {
T_6 V_239 ;
V_239 = F_140 ( F_130 (
V_115 -> V_240 [ V_228 -> V_235 ] ) ) ;
F_141 ( V_115 ,
0 , 0 ,
F_142 ( V_239 ) ,
1 , V_228 -> V_235 ,
V_241 ,
false ) ;
}
F_25 ( & V_13 -> V_238 ) ;
} else if ( V_166 -> V_231 == V_242 ) {
V_228 = ( void * ) & V_166 -> V_233 ;
F_23 ( & V_13 -> V_238 ) ;
V_115 = F_139 ( V_2 , V_228 -> V_44 ) ;
if ( V_115 )
F_143 ( V_115 ,
V_228 -> V_235 ,
V_243 , 0 ,
false ) ;
F_25 ( & V_13 -> V_238 ) ;
} else if ( F_144 ( V_230 -> V_244 ) &&
V_230 -> V_56 . V_245 . V_246 == V_247 ) {
int V_216 = V_166 -> V_216 ;
F_23 ( & V_13 -> V_238 ) ;
V_115 = F_139 ( V_2 , V_230 -> V_60 ) ;
if ( V_115 ) {
switch ( V_230 -> V_56 . V_245 . V_56 . V_248 . V_249 ) {
case V_250 :
F_145 (
V_13 , V_115 , V_230 , V_216 ) ;
break;
case V_251 :
F_146 ( V_13 , V_115 ,
V_230 , V_216 ) ;
break;
case V_252 :
F_147 ( V_2 , V_115 ,
V_230 , V_216 ) ;
break;
default:
F_44 ( 1 ) ;
break;
}
}
F_25 ( & V_13 -> V_238 ) ;
} else if ( F_148 ( V_230 -> V_244 ) ) {
struct V_211 * V_212 = ( void * ) V_230 ;
F_44 ( V_212 -> V_244 &
F_149 ( V_253 ) ) ;
F_44 ( ! ( V_212 -> V_254 &
F_149 ( V_255 ) ) ) ;
F_23 ( & V_13 -> V_238 ) ;
V_115 = F_139 ( V_2 , V_230 -> V_60 ) ;
if ( V_115 ) {
T_6 V_235 = * F_150 ( V_212 ) &
V_256 ;
F_143 (
V_115 , V_235 , V_243 ,
V_257 ,
true ) ;
}
F_25 ( & V_13 -> V_238 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_128 :
F_151 ( V_2 , V_166 ) ;
break;
case V_73 :
F_152 ( V_2 , V_166 ) ;
break;
case V_86 :
if ( ! F_124 ( & V_2 -> V_6 ) )
break;
F_153 ( V_2 , V_166 ) ;
break;
default:
F_135 ( 1 , L_3 ) ;
break;
}
F_154 ( V_166 ) ;
}
switch ( V_2 -> V_6 . type ) {
case V_128 :
F_155 ( V_2 ) ;
break;
case V_73 :
F_156 ( V_2 ) ;
break;
case V_86 :
if ( ! F_124 ( & V_2 -> V_6 ) )
break;
F_157 ( V_2 ) ;
break;
default:
break;
}
}
static void F_158 ( struct V_224 * V_192 )
{
struct V_1 * V_2 =
F_59 ( V_192 , struct V_1 , V_180 ) ;
F_159 ( V_2 ) ;
}
static void F_160 ( struct V_1 * V_2 ,
enum V_70 type )
{
memset ( & V_2 -> V_56 , 0 , sizeof( V_2 -> V_56 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_258 = false ;
V_2 -> V_106 . V_71 = type ;
V_2 -> V_126 = F_161 ( V_259 ) ;
V_2 -> V_127 = false ;
V_2 -> V_107 = V_108 ;
V_2 -> V_6 . V_11 . V_260 = true ;
V_2 -> V_261 = 0 ;
if ( V_2 -> V_39 ) {
V_2 -> V_39 -> V_220 = & V_221 ;
V_2 -> V_39 -> type = V_262 ;
}
F_162 ( & V_2 -> V_193 ) ;
F_163 ( & V_2 -> V_192 , F_134 ) ;
F_163 ( & V_2 -> V_180 , F_158 ) ;
F_163 ( & V_2 -> V_183 , V_263 ) ;
F_164 ( & V_2 -> V_264 ) ;
F_164 ( & V_2 -> V_265 ) ;
switch ( type ) {
case V_85 :
type = V_67 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_258 = true ;
case V_67 :
F_162 ( & V_2 -> V_56 . V_77 . V_169 . V_189 ) ;
F_164 ( & V_2 -> V_56 . V_77 . V_125 ) ;
F_163 ( & V_2 -> V_56 . V_77 . V_173 ,
V_266 ) ;
V_2 -> V_6 . V_11 . V_267 = V_2 -> V_6 . V_44 ;
V_2 -> V_56 . V_77 . V_268 = V_269 ;
break;
case V_131 :
type = V_128 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_258 = true ;
case V_128 :
V_2 -> V_6 . V_11 . V_267 = V_2 -> V_56 . V_270 . V_267 ;
F_165 ( V_2 ) ;
break;
case V_73 :
V_2 -> V_6 . V_11 . V_267 = V_2 -> V_56 . V_271 . V_267 ;
F_166 ( V_2 ) ;
break;
case V_86 :
if ( F_124 ( & V_2 -> V_6 ) )
F_167 ( V_2 ) ;
break;
case V_55 :
V_2 -> V_39 -> type = V_272 ;
V_2 -> V_39 -> V_220 = & V_273 ;
V_2 -> V_56 . V_57 = V_274 |
V_275 ;
break;
case V_68 :
V_2 -> V_6 . V_11 . V_267 = NULL ;
break;
case V_69 :
case V_66 :
V_2 -> V_6 . V_11 . V_267 = V_2 -> V_6 . V_44 ;
break;
case V_129 :
case V_130 :
F_168 () ;
break;
}
F_169 ( V_2 ) ;
}
static int F_170 ( struct V_1 * V_2 ,
enum V_70 type )
{
struct V_15 * V_13 = V_2 -> V_13 ;
int V_51 , V_163 ;
enum V_70 V_276 = type ;
bool V_258 = false ;
F_32 () ;
if ( ! V_13 -> V_30 -> V_277 )
return - V_61 ;
switch ( V_2 -> V_6 . type ) {
case V_67 :
case V_128 :
case V_73 :
break;
default:
return - V_61 ;
}
switch ( type ) {
case V_67 :
case V_128 :
case V_73 :
break;
case V_131 :
V_258 = true ;
V_276 = V_128 ;
break;
case V_85 :
V_258 = true ;
V_276 = V_67 ;
break;
default:
return - V_61 ;
}
V_51 = F_31 ( V_2 , V_276 ) ;
if ( V_51 )
return V_51 ;
F_86 ( V_2 , false ) ;
F_121 ( V_2 ) ;
V_51 = F_171 ( V_13 , V_2 , V_276 , V_258 ) ;
if ( V_51 )
type = F_67 ( & V_2 -> V_6 ) ;
F_35 ( V_2 , type ) ;
F_160 ( V_2 , type ) ;
V_163 = F_55 ( & V_2 -> V_106 , false ) ;
F_135 ( V_163 , L_4 , V_163 ) ;
return V_51 ;
}
int F_172 ( struct V_1 * V_2 ,
enum V_70 type )
{
int V_51 ;
F_32 () ;
if ( type == F_67 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_28 ( V_2 ) ) {
V_51 = F_170 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
} else {
F_121 ( V_2 ) ;
F_160 ( V_2 , type ) ;
}
V_2 -> V_278 = 0 ;
if ( type == V_128 )
V_2 -> V_56 . V_270 . V_279 = false ;
return 0 ;
}
static void F_173 ( struct V_15 * V_13 ,
T_2 * V_136 , enum V_70 type )
{
struct V_1 * V_2 ;
T_3 V_48 , V_280 , V_44 , V_281 , V_282 ;
T_2 * V_50 ;
T_2 V_283 [ V_63 ] ;
int V_81 ;
memcpy ( V_136 , V_13 -> V_16 . V_52 -> V_136 , V_63 ) ;
if ( F_22 ( V_13 -> V_16 . V_52 -> V_53 ) &&
V_13 -> V_16 . V_52 -> V_284 <= 1 )
return;
F_23 ( & V_13 -> V_54 ) ;
switch ( type ) {
case V_55 :
break;
case V_68 :
case V_69 :
F_24 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_67 )
continue;
memcpy ( V_136 , V_2 -> V_6 . V_44 , V_63 ) ;
break;
}
break;
case V_131 :
case V_85 :
if ( V_13 -> V_16 . V_18 & V_285 ) {
F_24 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_66 )
continue;
if ( ! F_28 ( V_2 ) )
continue;
memcpy ( V_136 , V_2 -> V_6 . V_44 , V_63 ) ;
goto V_286;
}
}
default:
for ( V_81 = 0 ; V_81 < V_13 -> V_16 . V_52 -> V_284 ; V_81 ++ ) {
bool V_287 = false ;
F_24 (sdata, &local->interfaces, list) {
if ( F_33 ( V_13 -> V_16 . V_52 -> V_288 [ V_81 ] . V_44 ,
V_2 -> V_6 . V_44 ) ) {
V_287 = true ;
break;
}
}
if ( ! V_287 ) {
memcpy ( V_136 ,
V_13 -> V_16 . V_52 -> V_288 [ V_81 ] . V_44 ,
V_63 ) ;
break;
}
}
if ( F_22 ( V_13 -> V_16 . V_52 -> V_53 ) )
break;
V_50 = V_13 -> V_16 . V_52 -> V_53 ;
V_48 = ( ( T_3 ) V_50 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_50 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_50 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_50 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_50 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_50 [ 5 ] << 0 * 8 ) ;
if ( F_174 ( V_48 ) + F_175 ( V_48 ) != F_176 ( V_48 ) ) {
F_177 ( L_5 ) ;
break;
}
V_50 = V_13 -> V_16 . V_52 -> V_136 ;
F_24 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_55 )
continue;
V_50 = V_2 -> V_6 . V_44 ;
break;
}
V_280 = ( ( T_3 ) V_50 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_50 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_50 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_50 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_50 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_50 [ 5 ] << 0 * 8 ) ;
V_282 = 1ULL << F_174 ( V_48 ) ;
V_281 = ( V_280 & V_48 ) ;
V_44 = ( V_280 & ~ V_48 ) | ( V_281 & V_48 ) ;
do {
bool V_287 = false ;
V_283 [ 5 ] = V_44 >> 0 * 8 ;
V_283 [ 4 ] = V_44 >> 1 * 8 ;
V_283 [ 3 ] = V_44 >> 2 * 8 ;
V_283 [ 2 ] = V_44 >> 3 * 8 ;
V_283 [ 1 ] = V_44 >> 4 * 8 ;
V_283 [ 0 ] = V_44 >> 5 * 8 ;
V_281 += V_282 ;
F_24 (sdata, &local->interfaces, list) {
if ( F_33 ( V_283 , V_2 -> V_6 . V_44 ) ) {
V_287 = true ;
break;
}
}
if ( ! V_287 ) {
memcpy ( V_136 , V_283 , V_63 ) ;
break;
}
V_44 = ( V_280 & ~ V_48 ) | ( V_281 & V_48 ) ;
} while ( V_44 != V_280 );
break;
}
V_286:
F_25 ( & V_13 -> V_54 ) ;
}
int F_178 ( struct V_15 * V_13 , const char * V_104 ,
struct V_111 * * V_289 , enum V_70 type ,
struct V_290 * V_291 )
{
struct V_38 * V_292 = NULL ;
struct V_1 * V_2 = NULL ;
int V_51 , V_81 ;
int V_293 = 1 ;
F_32 () ;
if ( type == V_66 ) {
struct V_111 * V_106 ;
V_2 = F_41 ( sizeof( * V_2 ) + V_13 -> V_16 . V_101 ,
V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_106 = & V_2 -> V_106 ;
V_2 -> V_39 = NULL ;
F_179 ( V_2 -> V_104 , V_104 , V_105 ) ;
F_173 ( V_13 , V_106 -> V_294 , type ) ;
memcpy ( V_2 -> V_6 . V_44 , V_106 -> V_294 , V_63 ) ;
} else {
if ( V_13 -> V_16 . V_80 >= V_82 )
V_293 = V_82 ;
V_292 = F_180 ( sizeof( * V_2 ) + V_13 -> V_16 . V_101 ,
V_104 , V_295 ,
F_132 , V_293 , 1 ) ;
if ( ! V_292 )
return - V_103 ;
F_181 ( V_292 , F_182 ( V_13 -> V_16 . V_52 ) ) ;
V_292 -> V_296 = V_13 -> V_297 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_298
+ V_108 ;
V_292 -> V_299 = V_300 ;
V_51 = F_183 ( V_292 , V_292 -> V_104 ) ;
if ( V_51 < 0 ) {
V_223 ( V_292 ) ;
return V_51 ;
}
F_173 ( V_13 , V_292 -> V_136 , type ) ;
memcpy ( V_292 -> V_135 , V_292 -> V_136 , V_63 ) ;
F_184 ( V_292 , F_185 ( V_13 -> V_16 . V_52 ) ) ;
V_2 = F_186 ( V_292 ) ;
V_292 -> V_301 = & V_2 -> V_106 ;
memcpy ( V_2 -> V_6 . V_44 , V_292 -> V_135 , V_63 ) ;
memcpy ( V_2 -> V_104 , V_292 -> V_104 , V_105 ) ;
V_2 -> V_39 = V_292 ;
}
V_2 -> V_106 . V_52 = V_13 -> V_16 . V_52 ;
V_2 -> V_13 = V_13 ;
for ( V_81 = 0 ; V_81 < V_205 ; V_81 ++ )
F_162 ( & V_2 -> V_206 [ V_81 ] . V_207 ) ;
F_164 ( & V_2 -> V_302 ) ;
F_187 ( & V_2 -> V_184 ,
V_303 ) ;
F_187 ( & V_2 -> V_304 ,
V_305 ) ;
for ( V_81 = 0 ; V_81 < V_306 ; V_81 ++ ) {
struct V_307 * V_308 ;
V_308 = V_13 -> V_16 . V_52 -> V_309 [ V_81 ] ;
V_2 -> V_310 [ V_81 ] =
V_308 ? ( 1 << V_308 -> V_311 ) - 1 : 0 ;
if ( V_308 )
memcpy ( V_2 -> V_312 [ V_81 ] ,
V_308 -> V_313 . V_314 . V_315 ,
sizeof( V_2 -> V_312 [ V_81 ] ) ) ;
else
memset ( V_2 -> V_312 [ V_81 ] , 0 ,
sizeof( V_2 -> V_312 [ V_81 ] ) ) ;
}
F_39 ( V_2 ) ;
V_2 -> V_10 = V_9 ;
V_2 -> V_8 = V_13 -> V_8 ;
V_2 -> V_107 = V_108 ;
F_160 ( V_2 , type ) ;
if ( V_292 ) {
if ( V_291 ) {
V_292 -> V_301 -> V_279 = V_291 -> V_279 ;
if ( type == V_128 )
V_2 -> V_56 . V_270 . V_279 = V_291 -> V_279 ;
}
V_292 -> V_316 |= V_13 -> V_16 . V_317 ;
F_188 ( V_292 , & V_318 ) ;
V_51 = F_189 ( V_292 ) ;
if ( V_51 ) {
V_223 ( V_292 ) ;
return V_51 ;
}
}
F_23 ( & V_13 -> V_54 ) ;
F_190 ( & V_2 -> V_124 , & V_13 -> V_319 ) ;
F_25 ( & V_13 -> V_54 ) ;
if ( V_289 )
* V_289 = & V_2 -> V_106 ;
return 0 ;
}
void F_191 ( struct V_1 * V_2 )
{
F_32 () ;
F_23 ( & V_2 -> V_13 -> V_54 ) ;
F_192 ( & V_2 -> V_124 ) ;
F_25 ( & V_2 -> V_13 -> V_54 ) ;
F_193 () ;
if ( V_2 -> V_39 ) {
F_194 ( V_2 -> V_39 ) ;
} else {
F_195 ( & V_2 -> V_106 ) ;
F_45 ( V_2 ) ;
}
}
void F_196 ( struct V_1 * V_2 )
{
if ( F_36 ( ! F_16 ( V_147 , & V_2 -> V_148 ) ) )
return;
F_86 ( V_2 , true ) ;
F_121 ( V_2 ) ;
}
void F_197 ( struct V_15 * V_13 )
{
struct V_1 * V_2 , * V_49 ;
F_198 ( V_320 ) ;
F_198 ( V_321 ) ;
F_32 () ;
F_24 (sdata, &local->interfaces, list)
if ( V_2 -> V_6 . type == V_69 )
F_108 ( V_2 -> V_39 ) ;
F_23 ( & V_13 -> V_54 ) ;
F_107 (sdata, tmp, &local->interfaces, list) {
F_83 ( & V_2 -> V_124 ) ;
if ( V_2 -> V_39 )
F_199 ( V_2 -> V_39 , & V_320 ) ;
else
F_58 ( & V_2 -> V_124 , & V_321 ) ;
}
F_25 ( & V_13 -> V_54 ) ;
F_200 ( & V_320 ) ;
F_107 (sdata, tmp, &wdev_list, list) {
F_83 ( & V_2 -> V_124 ) ;
F_195 ( & V_2 -> V_106 ) ;
F_45 ( V_2 ) ;
}
}
static int F_201 ( struct V_322 * V_323 ,
unsigned long V_148 , void * V_324 )
{
struct V_38 * V_39 = F_202 ( V_324 ) ;
struct V_1 * V_2 ;
if ( V_148 != V_325 )
return V_326 ;
if ( ! V_39 -> V_301 || ! V_39 -> V_301 -> V_52 )
return V_326 ;
if ( V_39 -> V_301 -> V_52 -> V_327 != V_328 )
return V_326 ;
V_2 = F_27 ( V_39 ) ;
memcpy ( V_2 -> V_104 , V_39 -> V_104 , V_105 ) ;
F_203 ( V_2 ) ;
return V_329 ;
}
int F_204 ( void )
{
return F_205 ( & V_330 ) ;
}
void F_206 ( void )
{
F_207 ( & V_330 ) ;
}
