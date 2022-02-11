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
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_70 V_71 )
{
int V_78 = V_2 -> V_13 -> V_16 . V_79 ;
int V_80 ;
if ( V_71 != V_66 ) {
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
if ( F_35 ( V_2 -> V_6 . V_82 [ V_80 ] ==
V_83 ) )
return - V_42 ;
if ( F_35 ( V_2 -> V_6 . V_82 [ V_80 ] >=
V_78 ) )
return - V_42 ;
}
}
if ( ( V_71 != V_67 &&
V_71 != V_84 &&
V_71 != V_85 ) ||
! ( V_2 -> V_13 -> V_16 . V_18 & V_86 ) ) {
V_2 -> V_6 . V_87 = V_83 ;
return 0 ;
}
if ( F_35 ( V_2 -> V_6 . V_87 == V_83 ) )
return - V_42 ;
if ( F_35 ( V_2 -> V_6 . V_87 >= V_78 ) )
return - V_42 ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 ,
const int V_88 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
T_1 V_18 = V_2 -> V_56 . V_57 ;
#define F_37 ( T_4 , T_5 ) do { \
if (flags & MONITOR_FLAG_##_f) \
local->fif_##_s += offset; \
} while (0)
F_37 ( V_89 , V_90 ) ;
F_37 ( V_91 , V_92 ) ;
F_37 ( V_93 , V_94 ) ;
F_37 ( V_93 , V_95 ) ;
F_37 ( V_96 , V_97 ) ;
#undef F_37
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
if ( V_13 -> V_16 . V_18 & V_86 )
V_2 -> V_6 . V_82 [ V_80 ] = V_83 ;
else if ( V_13 -> V_16 . V_79 >= V_81 )
V_2 -> V_6 . V_82 [ V_80 ] = V_80 ;
else
V_2 -> V_6 . V_82 [ V_80 ] = 0 ;
}
V_2 -> V_6 . V_87 = V_83 ;
}
int F_39 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
int V_51 ;
if ( ! ( V_13 -> V_16 . V_18 & V_98 ) )
return 0 ;
F_32 () ;
if ( V_13 -> V_99 )
return 0 ;
V_2 = F_40 ( sizeof( * V_2 ) + V_13 -> V_16 . V_100 , V_101 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 . type = V_55 ;
snprintf ( V_2 -> V_103 , V_104 , L_1 ,
F_41 ( V_13 -> V_16 . V_52 ) ) ;
V_2 -> V_105 = V_106 ;
F_38 ( V_2 ) ;
V_51 = F_42 ( V_13 , V_2 ) ;
if ( F_43 ( V_51 ) ) {
F_44 ( V_2 ) ;
return V_51 ;
}
V_51 = F_34 ( V_2 , V_55 ) ;
if ( V_51 ) {
F_44 ( V_2 ) ;
return V_51 ;
}
F_23 ( & V_13 -> V_54 ) ;
F_45 ( V_13 -> V_99 , V_2 ) ;
F_25 ( & V_13 -> V_54 ) ;
F_23 ( & V_13 -> V_27 ) ;
V_51 = F_46 ( V_2 , & V_13 -> V_107 ,
V_108 ) ;
F_25 ( & V_13 -> V_27 ) ;
if ( V_51 ) {
F_23 ( & V_13 -> V_54 ) ;
F_45 ( V_13 -> V_99 , NULL ) ;
F_25 ( & V_13 -> V_54 ) ;
F_47 () ;
F_48 ( V_13 , V_2 ) ;
F_44 ( V_2 ) ;
return V_51 ;
}
return 0 ;
}
void F_49 ( struct V_15 * V_13 )
{
struct V_1 * V_2 ;
if ( ! ( V_13 -> V_16 . V_18 & V_98 ) )
return;
F_32 () ;
F_23 ( & V_13 -> V_54 ) ;
V_2 = F_50 ( V_13 -> V_99 ,
F_51 ( & V_13 -> V_54 ) ) ;
if ( ! V_2 ) {
F_25 ( & V_13 -> V_54 ) ;
return;
}
F_45 ( V_13 -> V_99 , NULL ) ;
F_25 ( & V_13 -> V_54 ) ;
F_47 () ;
F_23 ( & V_13 -> V_27 ) ;
F_52 ( V_2 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_48 ( V_13 , V_2 ) ;
F_44 ( V_2 ) ;
}
int F_53 ( struct V_109 * V_110 , bool V_111 )
{
struct V_1 * V_2 = F_54 ( V_110 ) ;
struct V_38 * V_39 = V_110 -> V_112 ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_113 * V_114 ;
T_1 V_115 = 0 ;
int V_116 ;
T_1 V_117 = 0 ;
switch ( V_2 -> V_6 . type ) {
case V_68 :
if ( ! F_55 ( V_2 -> V_56 . V_118 . V_119 ) )
return - V_120 ;
break;
case V_69 : {
struct V_1 * V_121 ;
if ( ! V_2 -> V_76 )
return - V_120 ;
F_56 ( & V_2 -> V_56 . V_122 . V_123 , & V_2 -> V_76 -> V_124 ) ;
V_121 = F_57 ( V_2 -> V_76 ,
struct V_1 , V_56 . V_77 ) ;
V_2 -> V_125 =
V_121 -> V_125 ;
V_2 -> V_126 =
V_121 -> V_126 ;
V_2 -> V_6 . V_87 = V_121 -> V_6 . V_87 ;
memcpy ( V_2 -> V_6 . V_82 , V_121 -> V_6 . V_82 ,
sizeof( V_2 -> V_6 . V_82 ) ) ;
break;
}
case V_67 :
V_2 -> V_76 = & V_2 -> V_56 . V_77 ;
break;
case V_85 :
case V_127 :
case V_55 :
case V_73 :
case V_66 :
break;
case V_128 :
case V_129 :
case V_130 :
case V_84 :
F_43 ( 1 ) ;
break;
}
if ( V_13 -> V_131 == 0 ) {
V_116 = F_58 ( V_13 ) ;
if ( V_116 )
goto V_132;
V_117 = ~ 0 ;
F_59 ( V_13 , true ) ;
F_17 ( V_13 ,
V_133 , 0 ) ;
}
if ( V_39 && F_22 ( V_39 -> V_134 ) ) {
memcpy ( V_39 -> V_134 ,
V_13 -> V_16 . V_52 -> V_135 ,
V_63 ) ;
memcpy ( V_39 -> V_135 , V_39 -> V_134 , V_63 ) ;
if ( ! F_55 ( V_39 -> V_134 ) ) {
V_116 = - V_136 ;
goto V_137;
}
}
switch ( V_2 -> V_6 . type ) {
case V_69 :
if ( F_60 ( V_2 -> V_76 -> V_138 ) ) {
F_61 ( V_2 ) ;
F_62 ( V_39 ) ;
} else {
F_63 ( V_39 ) ;
}
break;
case V_55 :
if ( V_2 -> V_56 . V_57 & V_139 ) {
V_13 -> V_140 ++ ;
break;
}
if ( V_2 -> V_56 . V_57 & V_58 ) {
V_116 = F_42 ( V_13 , V_2 ) ;
if ( V_116 )
goto V_137;
} else if ( V_13 -> V_29 == 0 && V_13 -> V_131 == 0 ) {
V_116 = F_39 ( V_13 ) ;
if ( V_116 )
goto V_137;
}
V_13 -> V_29 ++ ;
if ( V_13 -> V_29 == 1 ) {
V_13 -> V_16 . V_17 . V_18 |= V_141 ;
V_117 |= V_142 ;
}
F_36 ( V_2 , 1 ) ;
F_64 ( V_13 ) ;
F_23 ( & V_13 -> V_27 ) ;
F_19 ( V_13 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_62 ( V_39 ) ;
break;
default:
if ( V_111 ) {
F_49 ( V_13 ) ;
V_116 = F_42 ( V_13 , V_2 ) ;
if ( V_116 )
goto V_137;
V_116 = F_34 ( V_2 ,
F_65 ( & V_2 -> V_6 ) ) ;
if ( V_116 )
goto V_143;
}
if ( V_2 -> V_6 . type == V_67 ) {
V_13 -> V_144 ++ ;
V_13 -> V_145 ++ ;
F_64 ( V_13 ) ;
} else if ( V_2 -> V_6 . type == V_73 ) {
V_13 -> V_145 ++ ;
}
if ( V_2 -> V_6 . type != V_66 )
V_115 |= F_66 ( V_2 ) ;
F_9 ( V_2 , V_115 ) ;
switch ( V_2 -> V_6 . type ) {
case V_127 :
case V_73 :
case V_67 :
case V_85 :
F_63 ( V_39 ) ;
break;
case V_68 :
case V_66 :
break;
default:
F_43 ( 1 ) ;
}
F_67 ( V_2 , true ) ;
}
F_68 ( V_146 , & V_2 -> V_147 ) ;
if ( V_2 -> V_6 . type == V_68 ) {
V_114 = F_69 ( V_2 , V_2 -> V_56 . V_118 . V_119 ,
V_101 ) ;
if ( ! V_114 ) {
V_116 = - V_102 ;
goto V_143;
}
F_70 ( V_114 , V_148 ) ;
F_70 ( V_114 , V_149 ) ;
F_70 ( V_114 , V_150 ) ;
V_116 = F_71 ( V_114 ) ;
if ( V_116 ) {
goto V_143;
}
F_72 ( V_114 ) ;
F_62 ( V_39 ) ;
} else if ( V_2 -> V_6 . type == V_66 ) {
F_45 ( V_13 -> V_151 , V_2 ) ;
}
if ( V_2 -> V_18 & V_152 )
F_73 ( & V_13 -> V_153 ) ;
if ( V_2 -> V_18 & V_154 )
F_73 ( & V_13 -> V_155 ) ;
if ( V_111 )
V_13 -> V_131 ++ ;
if ( V_117 )
F_7 ( V_13 , V_117 ) ;
F_74 ( V_13 , - 1 ) ;
if ( V_2 -> V_6 . type == V_55 ||
V_2 -> V_6 . type == V_69 ) {
F_75 ( V_39 ) ;
} else if ( V_39 ) {
unsigned long V_18 ;
int V_156 = V_81 ;
int V_157 ;
if ( V_13 -> V_16 . V_79 < V_81 )
V_156 = 1 ;
F_76 ( & V_13 -> V_158 , V_18 ) ;
if ( V_2 -> V_6 . V_87 == V_83 ||
( V_13 -> V_159 [ V_2 -> V_6 . V_87 ] == 0 &&
F_77 ( & V_13 -> V_160 [ V_2 -> V_6 . V_87 ] ) ) ) {
for ( V_157 = 0 ; V_157 < V_156 ; V_157 ++ ) {
int V_161 = V_2 -> V_6 . V_82 [ V_157 ] ;
if ( V_13 -> V_159 [ V_161 ] == 0 &&
F_77 ( & V_13 -> V_160 [ V_161 ] ) )
F_78 ( V_39 , V_157 ) ;
}
}
F_79 ( & V_13 -> V_158 , V_18 ) ;
}
return 0 ;
V_143:
F_48 ( V_13 , V_2 ) ;
V_137:
if ( ! V_13 -> V_131 )
F_80 ( V_13 ) ;
V_132:
V_2 -> V_76 = NULL ;
if ( V_2 -> V_6 . type == V_69 )
F_81 ( & V_2 -> V_56 . V_122 . V_123 ) ;
F_82 ( V_146 , & V_2 -> V_147 ) ;
return V_116 ;
}
static int F_83 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
int V_162 ;
if ( ! F_55 ( V_39 -> V_134 ) )
return - V_136 ;
V_162 = F_31 ( V_2 , V_2 -> V_6 . type ) ;
if ( V_162 )
return V_162 ;
return F_53 ( & V_2 -> V_110 , true ) ;
}
static void F_84 ( struct V_1 * V_2 ,
bool V_163 )
{
struct V_15 * V_13 = V_2 -> V_13 ;
unsigned long V_18 ;
struct V_164 * V_165 , * V_49 ;
T_1 V_117 = 0 ;
int V_80 , V_166 ;
struct V_167 * V_168 ;
struct V_169 V_170 ;
F_82 ( V_146 , & V_2 -> V_147 ) ;
if ( F_85 ( V_13 -> V_171 ) == V_2 )
F_86 ( V_13 ) ;
if ( V_2 -> V_39 )
F_87 ( V_2 -> V_39 ) ;
F_88 ( V_13 , V_2 ) ;
switch ( V_2 -> V_6 . type ) {
case V_127 :
F_89 ( V_2 ) ;
break;
case V_73 :
F_90 ( V_2 ) ;
break;
case V_67 :
F_91 ( & V_2 -> V_56 . V_77 . V_172 ) ;
break;
default:
break;
}
V_166 = F_92 ( V_2 ) ;
F_35 ( ( V_2 -> V_6 . type != V_68 && V_166 > 0 ) ||
( V_2 -> V_6 . type == V_68 && V_166 != 1 ) ) ;
if ( V_2 -> V_18 & V_152 )
F_93 ( & V_13 -> V_153 ) ;
if ( V_2 -> V_18 & V_154 )
F_93 ( & V_13 -> V_155 ) ;
if ( V_2 -> V_6 . type == V_67 ) {
V_13 -> V_144 -- ;
V_13 -> V_145 -- ;
} else if ( V_2 -> V_6 . type == V_73 ) {
V_13 -> V_145 -- ;
}
if ( V_2 -> V_39 ) {
F_94 ( V_2 -> V_39 ) ;
F_95 ( & V_13 -> V_173 ) ;
F_96 ( & V_13 -> V_174 , & V_2 -> V_39 -> V_175 ,
V_2 -> V_39 -> V_176 ) ;
F_97 ( & V_13 -> V_173 ) ;
F_98 ( V_2 -> V_39 ) ;
}
F_99 ( & V_13 -> V_177 ) ;
F_91 ( & V_13 -> V_178 ) ;
F_91 ( & V_2 -> V_179 ) ;
F_100 ( V_2 ) ;
V_2 -> V_6 . V_74 = false ;
F_101 ( V_2 ) ;
F_91 ( & V_2 -> V_180 ) ;
F_102 ( & V_2 -> V_181 ) ;
if ( V_2 -> V_110 . V_182 ) {
V_170 = V_2 -> V_6 . V_11 . V_170 ;
F_43 ( V_13 -> V_183 ) ;
F_23 ( & V_13 -> V_27 ) ;
F_52 ( V_2 ) ;
F_25 ( & V_13 -> V_27 ) ;
F_103 ( V_2 -> V_39 , & V_170 ,
V_184 ,
V_101 ) ;
}
if ( V_2 -> V_6 . type == V_67 ) {
struct V_1 * V_122 , * V_185 ;
F_104 (vlan, tmpsdata, &sdata->u.ap.vlans,
u.vlan.list)
F_105 ( V_122 -> V_39 ) ;
F_43 ( ! F_15 ( & V_2 -> V_56 . V_77 . V_124 ) ) ;
} else if ( V_2 -> V_6 . type == V_69 ) {
V_168 = & V_2 -> V_76 -> V_168 ;
F_76 ( & V_168 -> V_186 . V_187 , V_18 ) ;
F_106 (&ps->bc_buf, skb, tmp) {
if ( V_165 -> V_39 == V_2 -> V_39 ) {
F_107 ( V_165 , & V_168 -> V_186 ) ;
V_13 -> V_188 -- ;
F_108 ( & V_13 -> V_16 , V_165 ) ;
}
}
F_79 ( & V_168 -> V_186 . V_187 , V_18 ) ;
}
if ( V_163 )
V_13 -> V_131 -- ;
switch ( V_2 -> V_6 . type ) {
case V_69 :
F_81 ( & V_2 -> V_56 . V_122 . V_123 ) ;
F_45 ( V_2 -> V_6 . V_4 , NULL ) ;
break;
case V_55 :
if ( V_2 -> V_56 . V_57 & V_139 ) {
V_13 -> V_140 -- ;
break;
}
V_13 -> V_29 -- ;
if ( V_13 -> V_29 == 0 ) {
V_13 -> V_16 . V_17 . V_18 &= ~ V_141 ;
V_117 |= V_142 ;
}
F_36 ( V_2 , - 1 ) ;
break;
case V_66 :
F_45 ( V_13 -> V_151 , NULL ) ;
default:
F_91 ( & V_2 -> V_189 ) ;
F_109 ( V_2 , true ) ;
case V_67 :
F_110 ( & V_2 -> V_190 ) ;
}
V_2 -> V_76 = NULL ;
F_76 ( & V_13 -> V_158 , V_18 ) ;
for ( V_80 = 0 ; V_80 < V_191 ; V_80 ++ ) {
F_106 (&local->pending[i], skb, tmp) {
struct V_192 * V_193 = F_111 ( V_165 ) ;
if ( V_193 -> V_94 . V_6 == & V_2 -> V_6 ) {
F_107 ( V_165 , & V_13 -> V_160 [ V_80 ] ) ;
F_108 ( & V_13 -> V_16 , V_165 ) ;
}
}
}
F_79 ( & V_13 -> V_158 , V_18 ) ;
if ( V_13 -> V_131 == 0 )
F_112 ( V_13 ) ;
if ( V_13 -> V_183 ) {
F_43 ( V_13 -> V_194 ) ;
F_43 ( F_60 ( V_13 -> V_99 ) ) ;
return;
}
switch ( V_2 -> V_6 . type ) {
case V_69 :
break;
case V_55 :
if ( V_13 -> V_29 == 0 )
F_49 ( V_13 ) ;
F_23 ( & V_13 -> V_27 ) ;
F_19 ( V_13 ) ;
F_25 ( & V_13 -> V_27 ) ;
if ( ! ( V_2 -> V_56 . V_57 & V_58 ) )
break;
default:
if ( V_163 )
F_48 ( V_13 , V_2 ) ;
}
F_74 ( V_13 , - 1 ) ;
if ( V_13 -> V_131 == 0 ) {
F_113 ( V_13 ) ;
return;
}
F_64 ( V_13 ) ;
F_7 ( V_13 , V_117 ) ;
if ( V_13 -> V_29 == V_13 -> V_131 )
F_39 ( V_13 ) ;
}
static int F_114 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
F_84 ( V_2 , true ) ;
return 0 ;
}
static void F_115 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
int V_195 , V_196 , V_197 , V_198 ;
V_195 = ! ! ( V_39 -> V_18 & V_199 ) ;
V_196 = ! ! ( V_39 -> V_18 & V_200 ) ;
V_197 = ! ! ( V_2 -> V_18 & V_152 ) ;
V_198 = ! ! ( V_2 -> V_18 & V_154 ) ;
if ( V_195 != V_197 ) {
if ( V_39 -> V_18 & V_199 )
F_73 ( & V_13 -> V_153 ) ;
else
F_93 ( & V_13 -> V_153 ) ;
V_2 -> V_18 ^= V_152 ;
}
if ( V_196 != V_198 ) {
if ( V_39 -> V_18 & V_200 )
F_73 ( & V_13 -> V_155 ) ;
else
F_93 ( & V_13 -> V_155 ) ;
V_2 -> V_18 ^= V_154 ;
}
F_95 ( & V_13 -> V_173 ) ;
F_116 ( & V_13 -> V_174 , & V_39 -> V_175 , V_39 -> V_176 ) ;
F_97 ( & V_13 -> V_173 ) ;
F_117 ( & V_13 -> V_16 , & V_13 -> V_201 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
int V_80 ;
F_109 ( V_2 , false ) ;
F_119 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_202 ; V_80 ++ )
F_120 ( & V_2 -> V_203 [ V_80 ] . V_204 ) ;
V_2 -> V_205 = 0 ;
if ( F_121 ( & V_2 -> V_6 ) )
F_122 ( V_2 ) ;
}
static void F_123 ( struct V_38 * V_39 )
{
F_118 ( F_27 ( V_39 ) ) ;
}
static T_6 F_124 ( struct V_38 * V_39 ,
struct V_164 * V_165 ,
void * V_206 ,
T_7 V_207 )
{
return F_125 ( F_27 ( V_39 ) , V_165 ) ;
}
static T_6 F_126 ( struct V_38 * V_39 ,
struct V_164 * V_165 ,
void * V_206 ,
T_7 V_207 )
{
struct V_1 * V_2 = F_27 ( V_39 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_208 * V_209 ;
struct V_210 * V_211 = ( void * ) V_165 -> V_212 ;
if ( V_13 -> V_16 . V_79 < V_81 )
return 0 ;
if ( V_165 -> V_213 < 4 ||
V_165 -> V_213 < F_127 ( V_211 -> V_214 ) + 2 )
return 0 ;
V_209 = ( void * ) ( ( T_2 * ) V_165 -> V_212 + F_127 ( V_211 -> V_214 ) ) ;
return F_128 ( V_2 , V_165 , V_209 ) ;
}
static void F_129 ( struct V_38 * V_39 )
{
F_130 ( V_39 ) ;
V_39 -> V_215 &= ~ V_216 ;
V_39 -> V_217 = & V_218 ;
V_39 -> V_219 = V_220 ;
}
static void F_131 ( struct V_221 * V_189 )
{
struct V_1 * V_2 =
F_57 ( V_189 , struct V_1 , V_189 ) ;
struct V_15 * V_13 = V_2 -> V_13 ;
struct V_164 * V_165 ;
struct V_113 * V_114 ;
struct V_222 * V_223 ;
if ( ! F_28 ( V_2 ) )
return;
if ( V_13 -> V_23 )
return;
if ( F_132 ( V_13 -> V_183 ,
L_2 ) )
return;
while ( ( V_165 = F_133 ( & V_2 -> V_190 ) ) ) {
struct V_224 * V_225 = ( void * ) V_165 -> V_212 ;
if ( V_165 -> V_226 == V_227 ) {
V_223 = ( void * ) & V_165 -> V_228 ;
F_134 ( & V_2 -> V_6 , V_223 -> V_229 ,
V_223 -> V_230 ) ;
} else if ( V_165 -> V_226 == V_231 ) {
V_223 = ( void * ) & V_165 -> V_228 ;
F_135 ( & V_2 -> V_6 , V_223 -> V_229 ,
V_223 -> V_230 ) ;
} else if ( F_136 ( V_225 -> V_232 ) &&
V_225 -> V_56 . V_233 . V_234 == V_235 ) {
int V_213 = V_165 -> V_213 ;
F_23 ( & V_13 -> V_236 ) ;
V_114 = F_137 ( V_2 , V_225 -> V_60 ) ;
if ( V_114 ) {
switch ( V_225 -> V_56 . V_233 . V_56 . V_237 . V_238 ) {
case V_239 :
F_138 (
V_13 , V_114 , V_225 , V_213 ) ;
break;
case V_240 :
F_139 ( V_13 , V_114 ,
V_225 , V_213 ) ;
break;
case V_241 :
F_140 ( V_2 , V_114 ,
V_225 , V_213 ) ;
break;
default:
F_43 ( 1 ) ;
break;
}
}
F_25 ( & V_13 -> V_236 ) ;
} else if ( F_141 ( V_225 -> V_232 ) ) {
struct V_208 * V_209 = ( void * ) V_225 ;
F_43 ( V_209 -> V_232 &
F_142 ( V_242 ) ) ;
F_43 ( ! ( V_209 -> V_243 &
F_142 ( V_244 ) ) ) ;
F_23 ( & V_13 -> V_236 ) ;
V_114 = F_137 ( V_2 , V_225 -> V_60 ) ;
if ( V_114 ) {
T_6 V_230 = * F_143 ( V_209 ) &
V_245 ;
F_144 (
V_114 , V_230 , V_246 ,
V_247 ,
true ) ;
}
F_25 ( & V_13 -> V_236 ) ;
} else switch ( V_2 -> V_6 . type ) {
case V_127 :
F_145 ( V_2 , V_165 ) ;
break;
case V_73 :
F_146 ( V_2 , V_165 ) ;
break;
case V_85 :
if ( ! F_121 ( & V_2 -> V_6 ) )
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
case V_127 :
F_149 ( V_2 ) ;
break;
case V_73 :
F_150 ( V_2 ) ;
break;
case V_85 :
if ( ! F_121 ( & V_2 -> V_6 ) )
break;
F_151 ( V_2 ) ;
break;
default:
break;
}
}
static void F_152 ( struct V_221 * V_189 )
{
struct V_1 * V_2 =
F_57 ( V_189 , struct V_1 , V_179 ) ;
F_153 ( V_2 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
enum V_70 type )
{
memset ( & V_2 -> V_56 , 0 , sizeof( V_2 -> V_56 ) ) ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_248 = false ;
V_2 -> V_110 . V_71 = type ;
V_2 -> V_125 = F_155 ( V_249 ) ;
V_2 -> V_126 = false ;
V_2 -> V_105 = V_106 ;
V_2 -> V_250 = 0 ;
if ( V_2 -> V_39 ) {
V_2 -> V_39 -> V_217 = & V_218 ;
V_2 -> V_39 -> type = V_251 ;
}
F_156 ( & V_2 -> V_190 ) ;
F_157 ( & V_2 -> V_189 , F_131 ) ;
F_157 ( & V_2 -> V_179 , F_152 ) ;
F_157 ( & V_2 -> V_180 , V_252 ) ;
switch ( type ) {
case V_84 :
type = V_67 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_248 = true ;
case V_67 :
F_156 ( & V_2 -> V_56 . V_77 . V_168 . V_186 ) ;
F_158 ( & V_2 -> V_56 . V_77 . V_124 ) ;
F_157 ( & V_2 -> V_56 . V_77 . V_172 ,
V_253 ) ;
V_2 -> V_6 . V_11 . V_254 = V_2 -> V_6 . V_44 ;
V_2 -> V_56 . V_77 . V_255 = V_256 ;
break;
case V_130 :
type = V_127 ;
V_2 -> V_6 . type = type ;
V_2 -> V_6 . V_248 = true ;
case V_127 :
V_2 -> V_6 . V_11 . V_254 = V_2 -> V_56 . V_257 . V_254 ;
F_159 ( V_2 ) ;
break;
case V_73 :
V_2 -> V_6 . V_11 . V_254 = V_2 -> V_56 . V_258 . V_254 ;
F_160 ( V_2 ) ;
break;
case V_85 :
if ( F_121 ( & V_2 -> V_6 ) )
F_161 ( V_2 ) ;
break;
case V_55 :
V_2 -> V_39 -> type = V_259 ;
V_2 -> V_39 -> V_217 = & V_260 ;
V_2 -> V_56 . V_57 = V_261 |
V_262 ;
break;
case V_68 :
V_2 -> V_6 . V_11 . V_254 = NULL ;
break;
case V_69 :
case V_66 :
V_2 -> V_6 . V_11 . V_254 = V_2 -> V_6 . V_44 ;
break;
case V_128 :
case V_129 :
F_162 () ;
break;
}
F_163 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 ,
enum V_70 type )
{
struct V_15 * V_13 = V_2 -> V_13 ;
int V_51 , V_162 ;
enum V_70 V_263 = type ;
bool V_248 = false ;
F_32 () ;
if ( ! V_13 -> V_30 -> V_264 )
return - V_61 ;
switch ( V_2 -> V_6 . type ) {
case V_67 :
case V_127 :
case V_73 :
break;
default:
return - V_61 ;
}
switch ( type ) {
case V_67 :
case V_127 :
case V_73 :
break;
case V_130 :
V_248 = true ;
V_263 = V_127 ;
break;
case V_84 :
V_248 = true ;
V_263 = V_67 ;
break;
default:
return - V_61 ;
}
V_51 = F_31 ( V_2 , V_263 ) ;
if ( V_51 )
return V_51 ;
F_84 ( V_2 , false ) ;
F_118 ( V_2 ) ;
V_51 = F_165 ( V_13 , V_2 , V_263 , V_248 ) ;
if ( V_51 )
type = F_65 ( & V_2 -> V_6 ) ;
F_34 ( V_2 , type ) ;
F_154 ( V_2 , type ) ;
V_162 = F_53 ( & V_2 -> V_110 , false ) ;
F_132 ( V_162 , L_4 , V_162 ) ;
return V_51 ;
}
int F_166 ( struct V_1 * V_2 ,
enum V_70 type )
{
int V_51 ;
F_32 () ;
if ( type == F_65 ( & V_2 -> V_6 ) )
return 0 ;
if ( F_28 ( V_2 ) ) {
V_51 = F_164 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
} else {
F_118 ( V_2 ) ;
F_154 ( V_2 , type ) ;
}
V_2 -> V_265 = 0 ;
if ( type == V_127 )
V_2 -> V_56 . V_257 . V_266 = false ;
return 0 ;
}
static void F_167 ( struct V_15 * V_13 ,
T_2 * V_135 , enum V_70 type )
{
struct V_1 * V_2 ;
T_3 V_48 , V_267 , V_44 , V_268 , V_269 ;
T_2 * V_50 ;
T_2 V_270 [ V_63 ] ;
int V_80 ;
memcpy ( V_135 , V_13 -> V_16 . V_52 -> V_135 , V_63 ) ;
if ( F_22 ( V_13 -> V_16 . V_52 -> V_53 ) &&
V_13 -> V_16 . V_52 -> V_271 <= 1 )
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
memcpy ( V_135 , V_2 -> V_6 . V_44 , V_63 ) ;
break;
}
break;
case V_130 :
case V_84 :
if ( V_13 -> V_16 . V_18 & V_272 ) {
F_24 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type != V_66 )
continue;
if ( ! F_28 ( V_2 ) )
continue;
memcpy ( V_135 , V_2 -> V_6 . V_44 , V_63 ) ;
goto V_273;
}
}
default:
for ( V_80 = 0 ; V_80 < V_13 -> V_16 . V_52 -> V_271 ; V_80 ++ ) {
bool V_274 = false ;
F_24 (sdata, &local->interfaces, list) {
if ( F_33 ( V_13 -> V_16 . V_52 -> V_275 [ V_80 ] . V_44 ,
V_2 -> V_6 . V_44 ) ) {
V_274 = true ;
break;
}
}
if ( ! V_274 ) {
memcpy ( V_135 ,
V_13 -> V_16 . V_52 -> V_275 [ V_80 ] . V_44 ,
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
if ( F_168 ( V_48 ) + F_169 ( V_48 ) != F_170 ( V_48 ) ) {
F_171 ( L_5 ) ;
break;
}
V_50 = V_13 -> V_16 . V_52 -> V_135 ;
F_24 (sdata, &local->interfaces, list) {
if ( V_2 -> V_6 . type == V_55 )
continue;
V_50 = V_2 -> V_6 . V_44 ;
break;
}
V_267 = ( ( T_3 ) V_50 [ 0 ] << 5 * 8 ) | ( ( T_3 ) V_50 [ 1 ] << 4 * 8 ) |
( ( T_3 ) V_50 [ 2 ] << 3 * 8 ) | ( ( T_3 ) V_50 [ 3 ] << 2 * 8 ) |
( ( T_3 ) V_50 [ 4 ] << 1 * 8 ) | ( ( T_3 ) V_50 [ 5 ] << 0 * 8 ) ;
V_269 = 1ULL << F_168 ( V_48 ) ;
V_268 = ( V_267 & V_48 ) ;
V_44 = ( V_267 & ~ V_48 ) | ( V_268 & V_48 ) ;
do {
bool V_274 = false ;
V_270 [ 5 ] = V_44 >> 0 * 8 ;
V_270 [ 4 ] = V_44 >> 1 * 8 ;
V_270 [ 3 ] = V_44 >> 2 * 8 ;
V_270 [ 2 ] = V_44 >> 3 * 8 ;
V_270 [ 1 ] = V_44 >> 4 * 8 ;
V_270 [ 0 ] = V_44 >> 5 * 8 ;
V_268 += V_269 ;
F_24 (sdata, &local->interfaces, list) {
if ( F_33 ( V_270 , V_2 -> V_6 . V_44 ) ) {
V_274 = true ;
break;
}
}
if ( ! V_274 ) {
memcpy ( V_135 , V_270 , V_63 ) ;
break;
}
V_44 = ( V_267 & ~ V_48 ) | ( V_268 & V_48 ) ;
} while ( V_44 != V_267 );
break;
}
V_273:
F_25 ( & V_13 -> V_54 ) ;
}
int F_172 ( struct V_15 * V_13 , const char * V_103 ,
struct V_109 * * V_276 , enum V_70 type ,
struct V_277 * V_278 )
{
struct V_38 * V_279 = NULL ;
struct V_1 * V_2 = NULL ;
int V_51 , V_80 ;
int V_280 = 1 ;
F_32 () ;
if ( type == V_66 ) {
struct V_109 * V_110 ;
V_2 = F_40 ( sizeof( * V_2 ) + V_13 -> V_16 . V_100 ,
V_101 ) ;
if ( ! V_2 )
return - V_102 ;
V_110 = & V_2 -> V_110 ;
V_2 -> V_39 = NULL ;
F_173 ( V_2 -> V_103 , V_103 , V_104 ) ;
F_167 ( V_13 , V_110 -> V_281 , type ) ;
memcpy ( V_2 -> V_6 . V_44 , V_110 -> V_281 , V_63 ) ;
} else {
if ( V_13 -> V_16 . V_79 >= V_81 )
V_280 = V_81 ;
V_279 = F_174 ( sizeof( * V_2 ) +
V_13 -> V_16 . V_100 ,
V_103 , F_129 , V_280 , 1 ) ;
if ( ! V_279 )
return - V_102 ;
F_175 ( V_279 , F_176 ( V_13 -> V_16 . V_52 ) ) ;
V_279 -> V_282 = V_13 -> V_283 +
4 * 6
+ 2 + 2 + 2 + 2
+ 6
+ 8
- V_284
+ V_106 ;
V_279 -> V_285 = V_286 ;
V_51 = F_177 ( V_279 , V_279 -> V_103 ) ;
if ( V_51 < 0 ) {
V_220 ( V_279 ) ;
return V_51 ;
}
F_167 ( V_13 , V_279 -> V_135 , type ) ;
memcpy ( V_279 -> V_134 , V_279 -> V_135 , V_63 ) ;
F_178 ( V_279 , F_179 ( V_13 -> V_16 . V_52 ) ) ;
V_2 = F_180 ( V_279 ) ;
V_279 -> V_287 = & V_2 -> V_110 ;
memcpy ( V_2 -> V_6 . V_44 , V_279 -> V_134 , V_63 ) ;
memcpy ( V_2 -> V_103 , V_279 -> V_103 , V_104 ) ;
V_2 -> V_39 = V_279 ;
}
V_2 -> V_110 . V_52 = V_13 -> V_16 . V_52 ;
V_2 -> V_13 = V_13 ;
for ( V_80 = 0 ; V_80 < V_202 ; V_80 ++ )
F_156 ( & V_2 -> V_203 [ V_80 ] . V_204 ) ;
F_158 ( & V_2 -> V_288 ) ;
F_181 ( & V_2 -> V_181 ,
V_289 ) ;
F_181 ( & V_2 -> V_290 ,
V_291 ) ;
for ( V_80 = 0 ; V_80 < V_292 ; V_80 ++ ) {
struct V_293 * V_294 ;
V_294 = V_13 -> V_16 . V_52 -> V_295 [ V_80 ] ;
V_2 -> V_296 [ V_80 ] =
V_294 ? ( 1 << V_294 -> V_297 ) - 1 : 0 ;
if ( V_294 )
memcpy ( V_2 -> V_298 [ V_80 ] ,
V_294 -> V_299 . V_300 . V_301 ,
sizeof( V_2 -> V_298 [ V_80 ] ) ) ;
else
memset ( V_2 -> V_298 [ V_80 ] , 0 ,
sizeof( V_2 -> V_298 [ V_80 ] ) ) ;
}
F_38 ( V_2 ) ;
V_2 -> V_10 = V_9 ;
V_2 -> V_8 = V_13 -> V_8 ;
V_2 -> V_105 = V_106 ;
F_154 ( V_2 , type ) ;
if ( V_279 ) {
if ( V_278 ) {
V_279 -> V_287 -> V_266 = V_278 -> V_266 ;
if ( type == V_127 )
V_2 -> V_56 . V_257 . V_266 = V_278 -> V_266 ;
}
V_279 -> V_302 |= V_13 -> V_16 . V_303 ;
V_51 = F_182 ( V_279 ) ;
if ( V_51 ) {
V_220 ( V_279 ) ;
return V_51 ;
}
}
F_23 ( & V_13 -> V_54 ) ;
F_183 ( & V_2 -> V_123 , & V_13 -> V_304 ) ;
F_25 ( & V_13 -> V_54 ) ;
if ( V_276 )
* V_276 = & V_2 -> V_110 ;
return 0 ;
}
void F_184 ( struct V_1 * V_2 )
{
F_32 () ;
F_23 ( & V_2 -> V_13 -> V_54 ) ;
F_185 ( & V_2 -> V_123 ) ;
F_25 ( & V_2 -> V_13 -> V_54 ) ;
F_186 () ;
if ( V_2 -> V_39 ) {
F_187 ( V_2 -> V_39 ) ;
} else {
F_188 ( & V_2 -> V_110 ) ;
F_44 ( V_2 ) ;
}
}
void F_189 ( struct V_1 * V_2 )
{
if ( F_35 ( ! F_16 ( V_146 , & V_2 -> V_147 ) ) )
return;
F_84 ( V_2 , true ) ;
F_118 ( V_2 ) ;
}
void F_190 ( struct V_15 * V_13 )
{
struct V_1 * V_2 , * V_49 ;
F_191 ( V_305 ) ;
F_191 ( V_306 ) ;
F_32 () ;
F_24 (sdata, &local->interfaces, list)
if ( V_2 -> V_6 . type == V_69 )
F_105 ( V_2 -> V_39 ) ;
F_23 ( & V_13 -> V_54 ) ;
F_104 (sdata, tmp, &local->interfaces, list) {
F_81 ( & V_2 -> V_123 ) ;
if ( V_2 -> V_39 )
F_192 ( V_2 -> V_39 , & V_305 ) ;
else
F_56 ( & V_2 -> V_123 , & V_306 ) ;
}
F_25 ( & V_13 -> V_54 ) ;
F_193 ( & V_305 ) ;
F_81 ( & V_305 ) ;
F_104 (sdata, tmp, &wdev_list, list) {
F_81 ( & V_2 -> V_123 ) ;
F_188 ( & V_2 -> V_110 ) ;
F_44 ( V_2 ) ;
}
}
static int F_194 ( struct V_307 * V_308 ,
unsigned long V_147 , void * V_309 )
{
struct V_38 * V_39 = F_195 ( V_309 ) ;
struct V_1 * V_2 ;
if ( V_147 != V_310 )
return 0 ;
if ( ! V_39 -> V_287 || ! V_39 -> V_287 -> V_52 )
return 0 ;
if ( V_39 -> V_287 -> V_52 -> V_311 != V_312 )
return 0 ;
V_2 = F_27 ( V_39 ) ;
memcpy ( V_2 -> V_103 , V_39 -> V_103 , V_104 ) ;
F_196 ( V_2 ) ;
return 0 ;
}
int F_197 ( void )
{
return F_198 ( & V_313 ) ;
}
void F_199 ( void )
{
F_200 ( & V_313 ) ;
}
