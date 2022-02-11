static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 . V_7 . V_8 . V_5 ;
return V_5 == 0 ||
( V_4 && ( V_9 ) - F_2 ( & V_4 -> V_10 ) > V_5 ) ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_4 -> V_14 = V_4 -> V_15 = 0 ;
V_4 -> V_16 = 0 ;
}
static T_2 F_4 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
enum V_19 V_20 = F_5 ( V_2 ) ;
struct V_21 * V_22 = V_18 -> V_23 . V_24 -> V_25 [ V_20 ] ;
struct V_3 * V_4 ;
T_2 V_26 = 0 , V_27 = 0 ;
int V_28 ;
bool V_29 = false ;
if ( V_20 == V_30 ) {
V_29 = true ;
goto V_31;
} else if ( V_20 != V_32 ||
( V_20 == V_32 &&
V_18 -> V_23 . V_33 & V_34 ) )
goto V_31;
for ( V_28 = 0 ; V_28 < V_22 -> V_35 ; V_28 ++ )
if ( V_22 -> V_36 [ V_28 ] . V_33 & V_37 )
V_26 |= F_6 ( V_28 ) ;
if ( ! V_26 )
goto V_31;
F_7 () ;
F_8 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_11 != V_38 )
continue;
V_29 = false ;
if ( V_26 & V_4 -> V_4 . V_39 [ V_20 ] )
V_29 = true ;
else
break;
}
F_9 () ;
V_31:
if ( V_2 -> V_40 . V_41 . V_42 != V_29 ) {
V_2 -> V_40 . V_41 . V_42 = V_29 ;
V_27 = V_43 ;
F_10 ( V_2 , L_1 ,
V_2 -> V_40 . V_44 , V_29 ) ;
}
return V_27 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_3 * V_4 ;
T_3 V_45 ;
bool V_46 = false , V_47 = false ;
switch ( V_2 -> V_40 . V_41 . V_48 . V_49 ) {
case V_50 :
case V_51 :
case V_52 :
return 0 ;
default:
break;
}
F_7 () ;
F_8 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_11 != V_38 )
continue;
if ( V_4 -> V_4 . V_53 > V_54 )
continue;
if ( ! V_4 -> V_4 . V_55 . V_56 ) {
F_10 ( V_2 , L_2 ,
V_4 -> V_4 . V_44 ) ;
V_46 = true ;
break;
}
F_10 ( V_2 , L_3 , V_4 -> V_4 . V_44 ) ;
V_47 = true ;
}
F_9 () ;
if ( V_46 )
V_45 = V_57 ;
else if ( V_47 &&
V_2 -> V_40 . V_41 . V_48 . V_49 > V_58 )
V_45 = V_59 ;
else
V_45 = V_60 ;
if ( V_2 -> V_40 . V_41 . V_61 == V_45 )
return 0 ;
V_2 -> V_40 . V_41 . V_61 = V_45 ;
V_2 -> V_6 . V_7 . V_8 . V_45 = V_45 ;
F_10 ( V_2 , L_4 , V_45 ) ;
return V_62 ;
}
static T_2 F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_27 = 0 ;
if ( V_4 -> V_11 == V_38 )
V_27 = F_13 ( V_2 ) ;
V_4 -> V_11 = V_63 ;
F_14 ( V_4 ) ;
F_15 ( V_4 ) ;
V_27 |= F_16 ( V_4 ,
V_64 ) ;
return V_27 ;
}
T_2 F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_27 ;
F_18 ( & V_4 -> V_65 ) ;
V_27 = F_12 ( V_4 ) ;
V_4 -> V_15 = V_66 ;
F_19 ( V_2 , V_67 ,
V_4 -> V_4 . V_44 , V_4 -> V_13 , V_4 -> V_14 ,
V_4 -> V_15 ) ;
F_20 ( & V_4 -> V_65 ) ;
return V_27 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_68 V_69 ,
T_4 * V_70 , T_3 V_13 , T_3 V_14 , T_3 V_15 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
bool V_77 = false ;
T_3 V_78 = 0 ;
T_4 * V_79 , V_80 = 4 ;
int V_81 = F_21 ( struct V_75 , V_6 . V_69 . V_6 . V_82 ) +
sizeof( V_76 -> V_6 . V_69 . V_6 . V_82 ) ;
int V_83 = - V_84 ;
V_72 = F_22 ( V_18 -> V_85 +
V_81 +
2 +
2 +
2 + 8 +
2 + ( V_86 - 8 ) +
2 + V_2 -> V_6 . V_7 . V_87 +
2 + sizeof( struct V_88 ) +
2 + sizeof( struct V_89 ) +
2 + sizeof( struct V_90 ) +
2 + 8 +
V_2 -> V_6 . V_7 . V_80 ) ;
if ( ! V_72 )
return V_83 ;
V_74 = F_23 ( V_72 ) ;
F_24 ( V_72 , V_18 -> V_85 ) ;
V_76 = (struct V_75 * ) F_25 ( V_72 , V_81 ) ;
memset ( V_76 , 0 , V_81 ) ;
V_76 -> V_91 = F_26 ( V_92 |
V_93 ) ;
memcpy ( V_76 -> V_70 , V_70 , V_94 ) ;
memcpy ( V_76 -> V_95 , V_2 -> V_40 . V_44 , V_94 ) ;
memcpy ( V_76 -> V_96 , V_2 -> V_40 . V_44 , V_94 ) ;
V_76 -> V_6 . V_69 . V_97 = V_98 ;
V_76 -> V_6 . V_69 . V_6 . V_82 . V_99 = V_69 ;
if ( V_69 != V_67 ) {
enum V_19 V_20 = F_5 ( V_2 ) ;
V_79 = F_25 ( V_72 , 2 ) ;
memset ( V_79 , 0 , 2 ) ;
if ( V_69 == V_100 ) {
V_79 = F_25 ( V_72 , 2 ) ;
F_27 ( V_14 , V_79 + 2 ) ;
}
if ( F_28 ( V_2 , V_72 , true , V_20 ) ||
F_29 ( V_2 , V_72 , true , V_20 ) ||
F_30 ( V_2 , V_72 ) ||
F_31 ( V_2 , V_72 ) ||
F_32 ( V_2 , V_72 ) )
goto free;
} else {
V_74 -> V_33 |= V_101 ;
if ( F_31 ( V_2 , V_72 ) )
goto free;
}
switch ( V_69 ) {
case V_102 :
break;
case V_100 :
V_80 += 2 ;
V_77 = true ;
break;
case V_67 :
if ( V_14 ) {
V_80 += 2 ;
V_77 = true ;
}
V_80 += 2 ;
break;
default:
V_83 = - V_103 ;
goto free;
}
if ( F_33 ( F_34 ( V_72 ) < 2 + V_80 ) )
goto free;
V_79 = F_25 ( V_72 , 2 + V_80 ) ;
* V_79 ++ = V_104 ;
* V_79 ++ = V_80 ;
memcpy ( V_79 , & V_78 , 2 ) ;
V_79 += 2 ;
F_27 ( V_13 , V_79 ) ;
V_79 += 2 ;
if ( V_77 ) {
F_27 ( V_14 , V_79 ) ;
V_79 += 2 ;
}
if ( V_69 == V_67 ) {
F_27 ( V_15 , V_79 ) ;
V_79 += 2 ;
}
if ( V_69 != V_67 ) {
if ( F_35 ( V_2 , V_72 ) ||
F_36 ( V_2 , V_72 ) )
goto free;
}
if ( F_37 ( V_2 , V_72 ) )
goto free;
F_38 ( V_2 , V_72 ) ;
return 0 ;
free:
F_39 ( V_72 ) ;
return V_83 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_105 * V_106 , bool V_107 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
enum V_19 V_20 = F_5 ( V_2 ) ;
struct V_21 * V_22 ;
T_2 V_108 , V_109 = 0 , V_27 = 0 ;
V_22 = V_18 -> V_23 . V_24 -> V_25 [ V_20 ] ;
V_108 = F_41 ( V_2 , V_106 , V_20 , & V_109 ) ;
F_18 ( & V_4 -> V_65 ) ;
V_4 -> V_110 = V_111 ;
if ( V_4 -> V_11 == V_38 )
goto V_31;
if ( V_4 -> V_4 . V_39 [ V_20 ] != V_108 )
V_27 |= V_112 ;
V_4 -> V_4 . V_39 [ V_20 ] = V_108 ;
if ( F_42 ( V_2 , V_22 ,
V_106 -> V_113 , V_4 ) )
V_27 |= V_114 ;
if ( V_106 -> V_115 &&
! ( V_106 -> V_115 -> V_116 &
V_117 ) ) {
if ( V_4 -> V_4 . V_53 != V_54 )
V_27 |= V_114 ;
V_4 -> V_4 . V_53 = V_54 ;
}
if ( V_107 )
F_43 ( V_4 ) ;
else
F_44 ( V_18 , V_22 , V_4 , V_27 ) ;
V_31:
F_20 ( & V_4 -> V_65 ) ;
}
static struct V_3 *
F_45 ( struct V_1 * V_2 , T_4 * V_118 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_18 -> V_119 >= V_120 )
return NULL ;
V_4 = F_46 ( V_2 , V_118 , V_121 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_11 = V_12 ;
V_4 -> V_4 . V_122 = true ;
F_47 ( V_4 , V_123 ) ;
F_47 ( V_4 , V_124 ) ;
F_47 ( V_4 , V_125 ) ;
return V_4 ;
}
static struct V_3 *
F_48 ( struct V_1 * V_2 , T_4 * V_44 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_126 ||
V_2 -> V_6 . V_7 . V_127 & V_128 )
F_49 ( V_2 -> V_129 , V_44 ,
V_106 -> V_130 ,
V_106 -> V_131 ,
V_121 ) ;
else
V_4 = F_45 ( V_2 , V_44 ) ;
return V_4 ;
}
static struct V_3 *
F_50 ( struct V_1 * V_2 ,
T_4 * V_44 , struct V_105 * V_106 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_7 () ;
V_4 = F_51 ( V_2 , V_44 ) ;
if ( V_4 ) {
F_40 ( V_2 , V_4 , V_106 , false ) ;
} else {
F_9 () ;
V_4 = F_48 ( V_2 , V_44 , V_106 ) ;
if ( ! V_4 ) {
F_7 () ;
return NULL ;
}
F_40 ( V_2 , V_4 , V_106 , true ) ;
if ( F_52 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_53 ( struct V_1 * V_2 ,
T_4 * V_118 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 ;
T_2 V_27 = 0 ;
V_4 = F_50 ( V_2 , V_118 , V_106 ) ;
if ( ! V_4 )
goto V_31;
if ( F_54 ( V_106 ) &&
V_4 -> V_11 == V_12 &&
V_2 -> V_6 . V_7 . V_132 &&
V_2 -> V_6 . V_7 . V_8 . V_133 &&
F_1 ( V_2 , V_4 ) )
V_27 = F_55 ( V_4 ) ;
F_56 ( V_4 , V_106 ) ;
V_31:
F_9 () ;
F_57 ( V_2 , V_27 ) ;
}
static void F_58 ( unsigned long V_134 )
{
struct V_3 * V_4 ;
T_3 V_15 = 0 ;
struct V_1 * V_2 ;
struct V_135 * V_8 ;
enum V_68 V_69 = 0 ;
V_4 = (struct V_3 * ) V_134 ;
if ( V_4 -> V_2 -> V_18 -> V_136 )
return;
F_18 ( & V_4 -> V_65 ) ;
if ( F_59 ( V_111 , V_4 -> V_137 . V_138 ) ) {
F_10 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_44 , V_139 [ V_4 -> V_11 ] ) ;
F_20 ( & V_4 -> V_65 ) ;
return;
}
if ( V_4 -> V_11 == V_12 ||
V_4 -> V_11 == V_38 ) {
F_10 ( V_4 -> V_2 ,
L_6 ,
V_4 -> V_4 . V_44 , V_139 [ V_4 -> V_11 ] ) ;
F_20 ( & V_4 -> V_65 ) ;
return;
}
F_10 ( V_4 -> V_2 ,
L_7 ,
V_4 -> V_4 . V_44 , V_139 [ V_4 -> V_11 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_11 ) {
case V_140 :
case V_141 :
if ( V_4 -> V_16 < V_8 -> V_142 ) {
T_2 rand ;
F_10 ( V_4 -> V_2 ,
L_8 ,
V_4 -> V_4 . V_44 , V_4 -> V_16 ,
V_4 -> V_143 ) ;
F_60 ( & rand , sizeof( T_2 ) ) ;
V_4 -> V_143 = V_4 -> V_143 +
rand % V_4 -> V_143 ;
++ V_4 -> V_16 ;
F_61 ( V_4 , V_4 -> V_143 ) ;
V_69 = V_102 ;
break;
}
V_15 = V_144 ;
case V_145 :
if ( ! V_15 )
V_15 = V_146 ;
V_4 -> V_11 = V_147 ;
F_61 ( V_4 , V_8 -> V_148 ) ;
V_69 = V_67 ;
break;
case V_147 :
F_62 ( & V_4 -> V_137 ) ;
F_3 ( V_4 ) ;
break;
default:
break;
}
F_20 ( & V_4 -> V_65 ) ;
if ( V_69 )
F_19 ( V_2 , V_69 , V_4 -> V_4 . V_44 ,
V_4 -> V_13 , V_4 -> V_14 , V_15 ) ;
}
static inline void F_63 ( struct V_3 * V_4 , int V_149 )
{
V_4 -> V_137 . V_138 = V_111 + ( V_150 * V_149 / 1000 ) ;
V_4 -> V_137 . V_134 = ( unsigned long ) V_4 ;
V_4 -> V_137 . V_151 = F_58 ;
V_4 -> V_143 = V_149 ;
F_64 ( & V_4 -> V_137 ) ;
}
static bool F_65 ( struct V_1 * V_2 ,
T_3 V_13 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
bool V_152 = false ;
struct V_3 * V_4 ;
F_7 () ;
F_8 (sta, &local->sta_list, list) {
if ( ! memcmp ( & V_4 -> V_13 , & V_13 , sizeof( V_13 ) ) ) {
V_152 = true ;
break;
}
}
F_9 () ;
return V_152 ;
}
static T_3 F_66 ( struct V_1 * V_2 )
{
T_3 V_13 ;
do {
F_60 ( & V_13 , sizeof( V_13 ) ) ;
V_13 = ( V_13 % V_153 ) + 1 ;
} while ( F_65 ( V_2 , V_13 ) );
return V_13 ;
}
T_2 F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_27 ;
if ( ! F_67 ( V_4 , V_154 ) )
return 0 ;
F_18 ( & V_4 -> V_65 ) ;
V_4 -> V_13 = F_66 ( V_2 ) ;
if ( V_4 -> V_11 != V_12 &&
V_4 -> V_11 != V_63 ) {
F_20 ( & V_4 -> V_65 ) ;
return 0 ;
}
V_4 -> V_11 = V_141 ;
F_63 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_155 ) ;
F_20 ( & V_4 -> V_65 ) ;
F_10 ( V_2 ,
L_9 ,
V_4 -> V_4 . V_44 ) ;
V_27 = F_68 ( V_2 ) ;
F_19 ( V_2 , V_102 ,
V_4 -> V_4 . V_44 , V_4 -> V_13 , 0 , 0 ) ;
return V_27 ;
}
T_2 F_69 ( struct V_3 * V_4 )
{
T_2 V_27 ;
F_18 ( & V_4 -> V_65 ) ;
V_27 = F_12 ( V_4 ) ;
V_4 -> V_11 = V_63 ;
F_20 ( & V_4 -> V_65 ) ;
return V_27 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_156 V_157 )
{
struct V_135 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_15 = ( V_157 == V_158 ) ?
V_159 : V_160 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_11 = V_147 ;
F_61 ( V_4 , V_8 -> V_148 ) ;
}
static T_2 F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_135 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_27 = 0 ;
F_62 ( & V_4 -> V_137 ) ;
V_4 -> V_11 = V_38 ;
V_27 |= F_72 ( V_2 ) ;
V_27 |= F_11 ( V_2 ) ;
V_27 |= F_4 ( V_2 ) ;
F_10 ( V_2 , L_10 , V_4 -> V_4 . V_44 ) ;
F_15 ( V_4 ) ;
V_27 |= F_16 ( V_4 , V_8 -> V_161 ) ;
return V_27 ;
}
static T_2 F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_156 V_157 )
{
struct V_135 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_68 V_69 = 0 ;
T_2 V_27 = 0 ;
F_10 ( V_2 , L_11 , V_4 -> V_4 . V_44 ,
V_139 [ V_4 -> V_11 ] , V_162 [ V_157 ] ) ;
F_18 ( & V_4 -> V_65 ) ;
switch ( V_4 -> V_11 ) {
case V_12 :
switch ( V_157 ) {
case V_158 :
F_3 ( V_4 ) ;
break;
case V_163 :
V_4 -> V_11 = V_140 ;
V_4 -> V_13 = F_66 ( V_2 ) ;
F_63 ( V_4 ,
V_8 -> V_155 ) ;
V_27 |= F_68 ( V_2 ) ;
V_69 = V_102 ;
break;
default:
break;
}
break;
case V_141 :
switch ( V_157 ) {
case V_164 :
case V_165 :
case V_158 :
F_70 ( V_2 , V_4 , V_157 ) ;
V_69 = V_67 ;
break;
case V_163 :
V_4 -> V_11 = V_140 ;
V_69 = V_100 ;
break;
case V_166 :
V_4 -> V_11 = V_145 ;
F_61 ( V_4 , V_8 -> V_167 ) ;
break;
default:
break;
}
break;
case V_140 :
switch ( V_157 ) {
case V_164 :
case V_165 :
case V_158 :
F_70 ( V_2 , V_4 , V_157 ) ;
V_69 = V_67 ;
break;
case V_163 :
V_69 = V_100 ;
break;
case V_166 :
V_27 |= F_71 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_145 :
switch ( V_157 ) {
case V_164 :
case V_165 :
case V_158 :
F_70 ( V_2 , V_4 , V_157 ) ;
V_69 = V_67 ;
break;
case V_163 :
V_27 |= F_71 ( V_2 , V_4 ) ;
V_69 = V_100 ;
break;
default:
break;
}
break;
case V_38 :
switch ( V_157 ) {
case V_158 :
V_27 |= F_12 ( V_4 ) ;
V_27 |= F_11 ( V_2 ) ;
V_27 |= F_4 ( V_2 ) ;
F_70 ( V_2 , V_4 , V_157 ) ;
V_69 = V_67 ;
break;
case V_163 :
V_69 = V_100 ;
break;
default:
break;
}
break;
case V_147 :
switch ( V_157 ) {
case V_158 :
F_62 ( & V_4 -> V_137 ) ;
F_3 ( V_4 ) ;
break;
case V_163 :
case V_166 :
case V_164 :
case V_165 :
V_69 = V_67 ;
break;
default:
break;
}
break;
default:
break;
}
F_20 ( & V_4 -> V_65 ) ;
if ( V_69 ) {
F_19 ( V_2 , V_69 , V_4 -> V_4 . V_44 ,
V_4 -> V_13 , V_4 -> V_14 , V_4 -> V_15 ) ;
if ( V_69 == V_102 ) {
F_19 ( V_2 ,
V_100 ,
V_4 -> V_4 . V_44 , V_4 -> V_13 ,
V_4 -> V_14 , 0 ) ;
}
}
return V_27 ;
}
static enum V_156
F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_105 * V_106 ,
enum V_68 V_168 ,
T_3 V_13 , T_3 V_14 )
{
enum V_156 V_157 = V_169 ;
T_4 V_80 = V_106 -> V_170 ;
bool V_171 ;
V_171 = ( V_168 == V_67 ||
F_75 ( V_2 , V_106 ) ) ;
if ( ! V_171 && ! V_4 ) {
V_157 = V_164 ;
goto V_31;
}
if ( ! V_4 ) {
if ( V_168 != V_102 ) {
F_10 ( V_2 , L_12 ) ;
goto V_31;
}
if ( ! F_76 ( V_2 ) ) {
F_10 ( V_2 , L_13 ) ;
goto V_31;
}
} else {
if ( ! F_67 ( V_4 , V_154 ) ) {
F_10 ( V_2 , L_14 ) ;
goto V_31;
}
if ( V_4 -> V_11 == V_63 )
goto V_31;
}
if ( ! V_4 ) {
V_157 = V_163 ;
goto V_31;
}
switch ( V_168 ) {
case V_102 :
if ( ! V_171 )
V_157 = V_164 ;
if ( ! F_76 ( V_2 ) ||
( V_4 -> V_14 && V_4 -> V_14 != V_14 ) )
V_157 = V_172 ;
else
V_157 = V_163 ;
break;
case V_100 :
if ( ! V_171 )
V_157 = V_165 ;
if ( ! F_76 ( V_2 ) ||
V_4 -> V_13 != V_13 ||
( V_4 -> V_14 && V_4 -> V_14 != V_14 ) )
V_157 = V_173 ;
else
V_157 = V_166 ;
break;
case V_67 :
if ( V_4 -> V_11 == V_38 )
V_157 = V_158 ;
else if ( V_4 -> V_14 != V_14 )
V_157 = V_174 ;
else if ( V_80 == 8 && V_4 -> V_13 != V_13 )
V_157 = V_174 ;
else
V_157 = V_158 ;
break;
default:
F_10 ( V_2 , L_15 ) ;
break;
}
V_31:
return V_157 ;
}
static void
F_77 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 ;
enum V_156 V_157 ;
enum V_68 V_168 ;
T_2 V_27 = 0 ;
T_4 V_80 = V_106 -> V_170 ;
T_3 V_14 , V_13 = 0 ;
if ( ! V_106 -> V_175 ) {
F_10 ( V_2 ,
L_16 ) ;
return;
}
if ( V_106 -> V_176 &&
V_2 -> V_6 . V_7 . V_127 == V_177 ) {
F_10 ( V_2 ,
L_17 ) ;
return;
}
V_168 = V_76 -> V_6 . V_69 . V_6 . V_82 . V_99 ;
if ( ( V_168 == V_102 && V_80 != 4 ) ||
( V_168 == V_100 && V_80 != 6 ) ||
( V_168 == V_67 && V_80 != 6
&& V_80 != 8 ) ) {
F_10 ( V_2 ,
L_18 ,
V_168 , V_80 ) ;
return;
}
if ( V_168 != V_67 &&
( ! V_106 -> V_178 || ! V_106 -> V_135 ) ) {
F_10 ( V_2 , L_19 ) ;
return;
}
V_14 = F_78 ( F_79 ( V_106 -> V_175 ) ) ;
if ( V_168 == V_100 ||
( V_168 == V_67 && V_80 == 8 ) )
V_13 = F_78 ( F_80 ( V_106 -> V_175 ) ) ;
F_7 () ;
V_4 = F_51 ( V_2 , V_76 -> V_95 ) ;
if ( V_168 == V_102 &&
! F_1 ( V_2 , V_4 ) ) {
F_10 ( V_2 , L_20 ,
V_76 -> V_95 ) ;
goto V_179;
}
V_157 = F_74 ( V_2 , V_4 , V_106 , V_168 , V_13 , V_14 ) ;
if ( V_157 == V_163 ) {
F_9 () ;
V_4 = F_50 ( V_2 , V_76 -> V_95 , V_106 ) ;
if ( ! V_4 ) {
F_10 ( V_2 , L_21 ) ;
goto V_179;
}
V_4 -> V_14 = V_14 ;
} else if ( ! V_4 && V_157 == V_164 ) {
F_19 ( V_2 , V_67 ,
V_76 -> V_95 , 0 , V_14 ,
V_160 ) ;
goto V_179;
} else if ( ! V_4 || V_157 == V_169 ) {
goto V_179;
}
if ( ! V_4 -> V_14 && V_157 == V_166 )
V_4 -> V_14 = V_14 ;
V_27 |= F_73 ( V_2 , V_4 , V_157 ) ;
V_179:
F_9 () ;
if ( V_27 )
F_57 ( V_2 , V_27 ) ;
}
void F_81 ( struct V_1 * V_2 ,
struct V_75 * V_76 , T_6 V_180 ,
struct V_181 * V_182 )
{
struct V_105 V_106 ;
T_6 V_183 ;
T_4 * V_184 ;
if ( V_180 < V_185 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_126 )
return;
if ( F_82 ( V_76 -> V_70 ) ) {
F_10 ( V_2 ,
L_22 ) ;
return;
}
V_184 = V_76 -> V_6 . V_69 . V_6 . V_82 . V_186 ;
V_183 = ( T_4 * ) V_76 -> V_6 . V_69 . V_6 . V_82 . V_186 - ( T_4 * ) V_76 ;
if ( V_76 -> V_6 . V_69 . V_6 . V_82 . V_99 ==
V_100 ) {
V_184 += 4 ;
V_183 += 4 ;
}
F_83 ( V_184 , V_180 - V_183 , true , & V_106 ) ;
F_77 ( V_2 , V_76 , & V_106 ) ;
}
