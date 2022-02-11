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
F_47 ( V_4 , V_122 ) ;
F_47 ( V_4 , V_123 ) ;
F_47 ( V_4 , V_124 ) ;
F_48 ( V_4 , V_125 ) ;
V_4 -> V_4 . V_126 = true ;
return V_4 ;
}
static struct V_3 *
F_49 ( struct V_1 * V_2 , T_4 * V_44 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_127 ||
V_2 -> V_6 . V_7 . V_128 & V_129 )
F_50 ( V_2 -> V_130 , V_44 ,
V_106 -> V_131 ,
V_106 -> V_132 ,
V_121 ) ;
else
V_4 = F_45 ( V_2 , V_44 ) ;
return V_4 ;
}
static struct V_3 *
F_51 ( struct V_1 * V_2 ,
T_4 * V_44 , struct V_105 * V_106 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_7 () ;
V_4 = F_52 ( V_2 , V_44 ) ;
if ( V_4 ) {
F_40 ( V_2 , V_4 , V_106 , false ) ;
} else {
F_9 () ;
V_4 = F_49 ( V_2 , V_44 , V_106 ) ;
if ( ! V_4 ) {
F_7 () ;
return NULL ;
}
F_40 ( V_2 , V_4 , V_106 , true ) ;
if ( F_53 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_54 ( struct V_1 * V_2 ,
T_4 * V_118 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 ;
T_2 V_27 = 0 ;
V_4 = F_51 ( V_2 , V_118 , V_106 ) ;
if ( ! V_4 )
goto V_31;
if ( F_55 ( V_106 ) &&
V_4 -> V_11 == V_12 &&
V_2 -> V_6 . V_7 . V_133 &&
V_2 -> V_6 . V_7 . V_8 . V_134 &&
F_1 ( V_2 , V_4 ) )
V_27 = F_56 ( V_4 ) ;
F_57 ( V_4 , V_106 ) ;
V_31:
F_9 () ;
F_58 ( V_2 , V_27 ) ;
}
static void F_59 ( unsigned long V_135 )
{
struct V_3 * V_4 ;
T_3 V_15 = 0 ;
struct V_1 * V_2 ;
struct V_136 * V_8 ;
enum V_68 V_69 = 0 ;
V_4 = (struct V_3 * ) V_135 ;
if ( V_4 -> V_2 -> V_18 -> V_137 )
return;
F_18 ( & V_4 -> V_65 ) ;
if ( V_4 -> V_138 ) {
V_4 -> V_138 = false ;
F_20 ( & V_4 -> V_65 ) ;
return;
}
F_10 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_44 , V_139 [ V_4 -> V_11 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_11 ) {
case V_140 :
case V_141 :
if ( V_4 -> V_16 < V_8 -> V_142 ) {
T_2 rand ;
F_10 ( V_4 -> V_2 ,
L_6 ,
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
F_62 ( & V_4 -> V_149 ) ;
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
static inline void F_63 ( struct V_3 * V_4 , int V_150 )
{
V_4 -> V_149 . V_151 = V_111 + ( V_152 * V_150 / 1000 ) ;
V_4 -> V_149 . V_135 = ( unsigned long ) V_4 ;
V_4 -> V_149 . V_153 = F_59 ;
V_4 -> V_143 = V_150 ;
F_64 ( & V_4 -> V_149 ) ;
}
static bool F_65 ( struct V_1 * V_2 ,
T_3 V_13 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
bool V_154 = false ;
struct V_3 * V_4 ;
F_7 () ;
F_8 (sta, &local->sta_list, list) {
if ( ! memcmp ( & V_4 -> V_13 , & V_13 , sizeof( V_13 ) ) ) {
V_154 = true ;
break;
}
}
F_9 () ;
return V_154 ;
}
static T_3 F_66 ( struct V_1 * V_2 )
{
T_3 V_13 ;
do {
F_60 ( & V_13 , sizeof( V_13 ) ) ;
V_13 = ( V_13 % V_155 ) + 1 ;
} while ( F_65 ( V_2 , V_13 ) );
return V_13 ;
}
T_2 F_56 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_27 ;
if ( ! F_67 ( V_4 , V_156 ) )
return 0 ;
F_18 ( & V_4 -> V_65 ) ;
V_4 -> V_13 = F_66 ( V_2 ) ;
if ( V_4 -> V_11 != V_12 &&
V_4 -> V_11 != V_63 ) {
F_20 ( & V_4 -> V_65 ) ;
return 0 ;
}
V_4 -> V_11 = V_141 ;
F_63 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_157 ) ;
F_20 ( & V_4 -> V_65 ) ;
F_10 ( V_2 ,
L_7 ,
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
enum V_158 V_159 )
{
struct V_136 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_15 = ( V_159 == V_160 ) ?
V_161 : V_162 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_11 = V_147 ;
F_61 ( V_4 , V_8 -> V_148 ) ;
}
static T_2 F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_136 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_27 = 0 ;
F_62 ( & V_4 -> V_149 ) ;
V_4 -> V_11 = V_38 ;
V_27 |= F_72 ( V_2 ) ;
V_27 |= F_11 ( V_2 ) ;
V_27 |= F_4 ( V_2 ) ;
F_10 ( V_2 , L_8 , V_4 -> V_4 . V_44 ) ;
F_15 ( V_4 ) ;
V_27 |= F_16 ( V_4 , V_8 -> V_163 ) ;
return V_27 ;
}
static T_2 F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_158 V_159 )
{
struct V_136 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_68 V_69 = 0 ;
T_2 V_27 = 0 ;
F_10 ( V_2 , L_9 , V_4 -> V_4 . V_44 ,
V_139 [ V_4 -> V_11 ] , V_164 [ V_159 ] ) ;
F_18 ( & V_4 -> V_65 ) ;
switch ( V_4 -> V_11 ) {
case V_12 :
switch ( V_159 ) {
case V_160 :
F_3 ( V_4 ) ;
break;
case V_165 :
V_4 -> V_11 = V_140 ;
V_4 -> V_13 = F_66 ( V_2 ) ;
F_63 ( V_4 ,
V_8 -> V_157 ) ;
V_27 |= F_68 ( V_2 ) ;
V_69 = V_102 ;
break;
default:
break;
}
break;
case V_141 :
switch ( V_159 ) {
case V_166 :
case V_167 :
case V_160 :
F_70 ( V_2 , V_4 , V_159 ) ;
V_69 = V_67 ;
break;
case V_165 :
V_4 -> V_11 = V_140 ;
V_69 = V_100 ;
break;
case V_168 :
V_4 -> V_11 = V_145 ;
if ( ! F_61 ( V_4 ,
V_8 -> V_169 ) )
V_4 -> V_138 = true ;
break;
default:
break;
}
break;
case V_140 :
switch ( V_159 ) {
case V_166 :
case V_167 :
case V_160 :
F_70 ( V_2 , V_4 , V_159 ) ;
V_69 = V_67 ;
break;
case V_165 :
V_69 = V_100 ;
break;
case V_168 :
V_27 |= F_71 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_145 :
switch ( V_159 ) {
case V_166 :
case V_167 :
case V_160 :
F_70 ( V_2 , V_4 , V_159 ) ;
V_69 = V_67 ;
break;
case V_165 :
V_27 |= F_71 ( V_2 , V_4 ) ;
V_69 = V_100 ;
break;
default:
break;
}
break;
case V_38 :
switch ( V_159 ) {
case V_160 :
V_27 |= F_12 ( V_4 ) ;
V_27 |= F_11 ( V_2 ) ;
V_27 |= F_4 ( V_2 ) ;
F_70 ( V_2 , V_4 , V_159 ) ;
V_69 = V_67 ;
break;
case V_165 :
V_69 = V_100 ;
break;
default:
break;
}
break;
case V_147 :
switch ( V_159 ) {
case V_160 :
if ( F_62 ( & V_4 -> V_149 ) )
V_4 -> V_138 = 1 ;
F_3 ( V_4 ) ;
break;
case V_165 :
case V_168 :
case V_166 :
case V_167 :
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
static enum V_158
F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_105 * V_106 ,
enum V_68 V_170 ,
T_3 V_13 , T_3 V_14 )
{
enum V_158 V_159 = V_171 ;
T_4 V_80 = V_106 -> V_172 ;
bool V_173 ;
V_173 = ( V_170 == V_67 ||
F_75 ( V_2 , V_106 ) ) ;
if ( ! V_173 && ! V_4 ) {
V_159 = V_166 ;
goto V_31;
}
if ( ! V_4 ) {
if ( V_170 != V_102 ) {
F_10 ( V_2 , L_10 ) ;
goto V_31;
}
if ( ! F_76 ( V_2 ) ) {
F_10 ( V_2 , L_11 ) ;
goto V_31;
}
} else {
if ( ! F_67 ( V_4 , V_156 ) ) {
F_10 ( V_2 , L_12 ) ;
goto V_31;
}
if ( V_4 -> V_11 == V_63 )
goto V_31;
}
if ( ! V_4 ) {
V_159 = V_165 ;
goto V_31;
}
switch ( V_170 ) {
case V_102 :
if ( ! V_173 )
V_159 = V_166 ;
if ( ! F_76 ( V_2 ) ||
( V_4 -> V_14 && V_4 -> V_14 != V_14 ) )
V_159 = V_174 ;
else
V_159 = V_165 ;
break;
case V_100 :
if ( ! V_173 )
V_159 = V_167 ;
if ( ! F_76 ( V_2 ) ||
( V_4 -> V_13 != V_13 || V_4 -> V_14 != V_14 ) )
V_159 = V_175 ;
else
V_159 = V_168 ;
break;
case V_67 :
if ( V_4 -> V_11 == V_38 )
V_159 = V_160 ;
else if ( V_4 -> V_14 != V_14 )
V_159 = V_176 ;
else if ( V_80 == 8 && V_4 -> V_13 != V_13 )
V_159 = V_176 ;
else
V_159 = V_160 ;
break;
default:
F_10 ( V_2 , L_13 ) ;
break;
}
V_31:
return V_159 ;
}
static void
F_77 ( struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 ;
enum V_158 V_159 ;
enum V_68 V_170 ;
T_2 V_27 = 0 ;
T_4 V_80 = V_106 -> V_172 ;
T_6 V_177 , V_178 ;
T_3 V_14 , V_13 = 0 ;
if ( ! V_106 -> V_179 ) {
F_10 ( V_2 ,
L_14 ) ;
return;
}
if ( V_106 -> V_180 &&
V_2 -> V_6 . V_7 . V_128 == V_181 ) {
F_10 ( V_2 ,
L_15 ) ;
return;
}
V_170 = V_76 -> V_6 . V_69 . V_6 . V_82 . V_99 ;
if ( ( V_170 == V_102 && V_80 != 4 ) ||
( V_170 == V_100 && V_80 != 6 ) ||
( V_170 == V_67 && V_80 != 6
&& V_80 != 8 ) ) {
F_10 ( V_2 ,
L_16 ,
V_170 , V_80 ) ;
return;
}
if ( V_170 != V_67 &&
( ! V_106 -> V_182 || ! V_106 -> V_136 ) ) {
F_10 ( V_2 , L_17 ) ;
return;
}
memcpy ( & V_177 , F_78 ( V_106 -> V_179 ) , sizeof( T_6 ) ) ;
V_14 = F_79 ( V_177 ) ;
if ( V_170 == V_100 ||
( V_170 == V_67 && V_80 == 8 ) ) {
memcpy ( & V_178 , F_80 ( V_106 -> V_179 ) , sizeof( T_6 ) ) ;
V_13 = F_79 ( V_178 ) ;
}
F_7 () ;
V_4 = F_52 ( V_2 , V_76 -> V_95 ) ;
if ( V_170 == V_102 &&
! F_1 ( V_2 , V_4 ) ) {
F_10 ( V_2 , L_18 ,
V_76 -> V_95 ) ;
goto V_183;
}
V_159 = F_74 ( V_2 , V_4 , V_106 , V_170 , V_13 , V_14 ) ;
if ( V_159 == V_165 ) {
F_9 () ;
V_4 = F_51 ( V_2 , V_76 -> V_95 , V_106 ) ;
if ( ! V_4 ) {
F_10 ( V_2 , L_19 ) ;
goto V_183;
}
V_4 -> V_14 = V_14 ;
} else if ( ! V_4 && V_159 == V_166 ) {
F_19 ( V_2 , V_67 ,
V_76 -> V_95 , 0 , V_14 ,
V_162 ) ;
goto V_183;
} else if ( ! V_4 || V_159 == V_171 ) {
goto V_183;
}
V_27 |= F_73 ( V_2 , V_4 , V_159 ) ;
V_183:
F_9 () ;
if ( V_27 )
F_58 ( V_2 , V_27 ) ;
}
void F_81 ( struct V_1 * V_2 ,
struct V_75 * V_76 , T_7 V_184 ,
struct V_185 * V_186 )
{
struct V_105 V_106 ;
T_7 V_187 ;
T_4 * V_188 ;
if ( V_184 < V_189 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_127 )
return;
if ( F_82 ( V_76 -> V_70 ) ) {
F_10 ( V_2 ,
L_20 ) ;
return;
}
V_188 = V_76 -> V_6 . V_69 . V_6 . V_82 . V_190 ;
V_187 = ( T_4 * ) V_76 -> V_6 . V_69 . V_6 . V_82 . V_190 - ( T_4 * ) V_76 ;
if ( V_76 -> V_6 . V_69 . V_6 . V_82 . V_99 ==
V_100 ) {
V_188 += 4 ;
V_187 += 4 ;
}
F_83 ( V_188 , V_184 - V_187 , true , & V_106 ) ;
F_77 ( V_2 , V_76 , & V_106 ) ;
}
