static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 . V_7 . V_8 . V_5 ;
return V_5 == 0 ||
( V_4 && ( V_9 ) - F_2 ( & V_4 -> V_10 ) > V_5 ) ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_4 -> V_15 = V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
enum V_20 V_21 = F_6 ( V_2 ) ;
struct V_22 * V_23 = V_19 -> V_24 . V_25 -> V_26 [ V_21 ] ;
struct V_3 * V_4 ;
T_2 V_27 = 0 , V_28 = 0 ;
int V_29 ;
bool V_30 = false ;
if ( V_21 == V_31 ) {
V_30 = true ;
goto V_32;
} else if ( V_21 != V_33 )
goto V_32;
for ( V_29 = 0 ; V_29 < V_23 -> V_34 ; V_29 ++ )
if ( V_23 -> V_35 [ V_29 ] . V_36 & V_37 )
V_27 |= F_7 ( V_29 ) ;
if ( ! V_27 )
goto V_32;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_12 != V_38 )
continue;
V_30 = false ;
if ( V_27 & V_4 -> V_4 . V_39 [ V_21 ] )
V_30 = true ;
else
break;
}
F_10 () ;
V_32:
if ( V_2 -> V_40 . V_41 . V_42 != V_30 ) {
V_2 -> V_40 . V_41 . V_42 = V_30 ;
V_28 = V_43 ;
F_11 ( V_2 , L_1 ,
V_2 -> V_40 . V_44 , V_30 ) ;
}
return V_28 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
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
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_12 != V_38 )
continue;
if ( V_4 -> V_4 . V_53 > V_54 )
continue;
if ( ! V_4 -> V_4 . V_55 . V_56 ) {
F_11 ( V_2 , L_2 ,
V_4 -> V_4 . V_44 ) ;
V_46 = true ;
break;
}
F_11 ( V_2 , L_3 , V_4 -> V_4 . V_44 ) ;
V_47 = true ;
}
F_10 () ;
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
F_11 ( V_2 , L_4 , V_45 ) ;
return V_62 ;
}
static T_2 F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 = 0 ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_12 == V_38 )
V_28 = F_14 ( V_2 ) ;
V_4 -> V_12 = V_63 ;
F_15 ( V_4 ) ;
F_16 ( V_4 ) ;
V_28 |= F_17 ( V_4 ,
V_64 ) ;
return V_28 ;
}
T_2 F_18 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 ;
F_19 ( & V_4 -> V_11 ) ;
V_28 = F_13 ( V_4 ) ;
V_4 -> V_16 = V_65 ;
F_20 ( V_2 , V_66 ,
V_4 -> V_4 . V_44 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 ) ;
F_21 ( & V_4 -> V_11 ) ;
return V_28 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_67 V_68 ,
T_4 * V_69 , T_3 V_14 , T_3 V_15 , T_3 V_16 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
bool V_76 = false ;
T_3 V_77 = 0 ;
T_4 * V_78 , V_79 = 4 ;
int V_80 = F_22 ( struct V_74 , V_6 . V_68 . V_6 . V_81 ) +
sizeof( V_75 -> V_6 . V_68 . V_6 . V_81 ) ;
int V_82 = - V_83 ;
V_71 = F_23 ( V_19 -> V_84 +
V_80 +
2 +
2 +
2 + 8 +
2 + ( V_85 - 8 ) +
2 + V_2 -> V_6 . V_7 . V_86 +
2 + sizeof( struct V_87 ) +
2 + sizeof( struct V_88 ) +
2 + sizeof( struct V_89 ) +
2 + 8 +
V_2 -> V_6 . V_7 . V_79 ) ;
if ( ! V_71 )
return V_82 ;
V_73 = F_24 ( V_71 ) ;
F_25 ( V_71 , V_19 -> V_84 ) ;
V_75 = (struct V_74 * ) F_26 ( V_71 , V_80 ) ;
memset ( V_75 , 0 , V_80 ) ;
V_75 -> V_90 = F_27 ( V_91 |
V_92 ) ;
memcpy ( V_75 -> V_69 , V_69 , V_93 ) ;
memcpy ( V_75 -> V_94 , V_2 -> V_40 . V_44 , V_93 ) ;
memcpy ( V_75 -> V_95 , V_2 -> V_40 . V_44 , V_93 ) ;
V_75 -> V_6 . V_68 . V_96 = V_97 ;
V_75 -> V_6 . V_68 . V_6 . V_81 . V_98 = V_68 ;
if ( V_68 != V_66 ) {
enum V_20 V_21 = F_6 ( V_2 ) ;
V_78 = F_26 ( V_71 , 2 ) ;
memset ( V_78 , 0 , 2 ) ;
if ( V_68 == V_99 ) {
V_78 = F_26 ( V_71 , 2 ) ;
F_28 ( V_15 , V_78 ) ;
}
if ( F_29 ( V_2 , V_71 , true , V_21 ) ||
F_30 ( V_2 , V_71 , true , V_21 ) ||
F_31 ( V_2 , V_71 ) ||
F_32 ( V_2 , V_71 ) ||
F_33 ( V_2 , V_71 ) )
goto free;
} else {
V_73 -> V_36 |= V_100 ;
if ( F_32 ( V_2 , V_71 ) )
goto free;
}
switch ( V_68 ) {
case V_101 :
break;
case V_99 :
V_79 += 2 ;
V_76 = true ;
break;
case V_66 :
if ( V_15 ) {
V_79 += 2 ;
V_76 = true ;
}
V_79 += 2 ;
break;
default:
V_82 = - V_102 ;
goto free;
}
if ( F_34 ( F_35 ( V_71 ) < 2 + V_79 ) )
goto free;
V_78 = F_26 ( V_71 , 2 + V_79 ) ;
* V_78 ++ = V_103 ;
* V_78 ++ = V_79 ;
memcpy ( V_78 , & V_77 , 2 ) ;
V_78 += 2 ;
F_28 ( V_14 , V_78 ) ;
V_78 += 2 ;
if ( V_76 ) {
F_28 ( V_15 , V_78 ) ;
V_78 += 2 ;
}
if ( V_68 == V_66 ) {
F_28 ( V_16 , V_78 ) ;
V_78 += 2 ;
}
if ( V_68 != V_66 ) {
if ( F_36 ( V_2 , V_71 ) ||
F_37 ( V_2 , V_71 ) )
goto free;
}
if ( F_38 ( V_2 , V_71 ) )
goto free;
F_39 ( V_2 , V_71 ) ;
return 0 ;
free:
F_40 ( V_71 ) ;
return V_82 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_104 * V_105 , bool V_106 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
enum V_20 V_21 = F_6 ( V_2 ) ;
struct V_22 * V_23 ;
T_2 V_107 , V_108 = 0 , V_28 = 0 ;
enum V_109 V_110 = V_4 -> V_4 . V_53 ;
V_23 = V_19 -> V_24 . V_25 -> V_26 [ V_21 ] ;
V_107 = F_42 ( V_2 , V_105 , V_21 , & V_108 ) ;
F_19 ( & V_4 -> V_11 ) ;
V_4 -> V_111 = V_112 ;
if ( V_4 -> V_12 == V_38 && V_4 -> V_113 )
goto V_32;
V_4 -> V_113 = true ;
if ( V_4 -> V_4 . V_39 [ V_21 ] != V_107 )
V_28 |= V_114 ;
V_4 -> V_4 . V_39 [ V_21 ] = V_107 ;
if ( F_43 ( V_2 , V_23 ,
V_105 -> V_115 , V_4 ) )
V_28 |= V_116 ;
if ( V_110 != V_4 -> V_4 . V_53 )
V_28 |= V_116 ;
if ( V_105 -> V_117 &&
! ( V_105 -> V_117 -> V_118 &
V_119 ) ) {
if ( V_4 -> V_4 . V_53 != V_54 )
V_28 |= V_116 ;
V_4 -> V_4 . V_53 = V_54 ;
}
if ( V_106 )
F_44 ( V_4 ) ;
else
F_45 ( V_19 , V_23 , V_4 , V_28 ) ;
V_32:
F_21 ( & V_4 -> V_11 ) ;
}
static struct V_3 *
F_46 ( struct V_1 * V_2 , T_4 * V_120 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_19 -> V_121 >= V_122 )
return NULL ;
V_4 = F_47 ( V_2 , V_120 , V_123 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_12 = V_13 ;
V_4 -> V_4 . V_124 = true ;
F_48 ( V_4 , V_125 ) ;
F_48 ( V_4 , V_126 ) ;
F_48 ( V_4 , V_127 ) ;
return V_4 ;
}
static struct V_3 *
F_49 ( struct V_1 * V_2 , T_4 * V_44 ,
struct V_104 * V_105 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_128 ||
V_2 -> V_6 . V_7 . V_129 & V_130 )
F_50 ( V_2 -> V_131 , V_44 ,
V_105 -> V_132 ,
V_105 -> V_133 ,
V_123 ) ;
else
V_4 = F_46 ( V_2 , V_44 ) ;
return V_4 ;
}
static struct V_3 *
F_51 ( struct V_1 * V_2 ,
T_4 * V_44 , struct V_104 * V_105 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_8 () ;
V_4 = F_52 ( V_2 , V_44 ) ;
if ( V_4 ) {
F_41 ( V_2 , V_4 , V_105 , false ) ;
} else {
F_10 () ;
V_4 = F_49 ( V_2 , V_44 , V_105 ) ;
if ( ! V_4 ) {
F_8 () ;
return NULL ;
}
F_41 ( V_2 , V_4 , V_105 , true ) ;
if ( F_53 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_54 ( struct V_1 * V_2 ,
T_4 * V_120 ,
struct V_104 * V_105 )
{
struct V_3 * V_4 ;
T_2 V_28 = 0 ;
V_4 = F_51 ( V_2 , V_120 , V_105 ) ;
if ( ! V_4 )
goto V_32;
if ( F_55 ( V_105 ) &&
V_4 -> V_12 == V_13 &&
V_2 -> V_6 . V_7 . V_134 &&
V_2 -> V_6 . V_7 . V_8 . V_135 &&
F_1 ( V_2 , V_4 ) )
V_28 = F_56 ( V_4 ) ;
F_57 ( V_4 , V_105 ) ;
V_32:
F_10 () ;
F_58 ( V_2 , V_28 ) ;
}
static void F_59 ( unsigned long V_136 )
{
struct V_3 * V_4 ;
T_3 V_16 = 0 ;
struct V_1 * V_2 ;
struct V_137 * V_8 ;
enum V_67 V_68 = 0 ;
V_4 = (struct V_3 * ) V_136 ;
if ( V_4 -> V_2 -> V_19 -> V_138 )
return;
F_19 ( & V_4 -> V_11 ) ;
if ( F_60 ( V_112 , V_4 -> V_139 . V_140 ) ) {
F_11 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_44 , V_141 [ V_4 -> V_12 ] ) ;
F_21 ( & V_4 -> V_11 ) ;
return;
}
if ( V_4 -> V_12 == V_13 ||
V_4 -> V_12 == V_38 ) {
F_11 ( V_4 -> V_2 ,
L_6 ,
V_4 -> V_4 . V_44 , V_141 [ V_4 -> V_12 ] ) ;
F_21 ( & V_4 -> V_11 ) ;
return;
}
F_11 ( V_4 -> V_2 ,
L_7 ,
V_4 -> V_4 . V_44 , V_141 [ V_4 -> V_12 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_12 ) {
case V_142 :
case V_143 :
if ( V_4 -> V_17 < V_8 -> V_144 ) {
T_2 rand ;
F_11 ( V_4 -> V_2 ,
L_8 ,
V_4 -> V_4 . V_44 , V_4 -> V_17 ,
V_4 -> V_145 ) ;
F_61 ( & rand , sizeof( T_2 ) ) ;
V_4 -> V_145 = V_4 -> V_145 +
rand % V_4 -> V_145 ;
++ V_4 -> V_17 ;
F_62 ( V_4 , V_4 -> V_145 ) ;
V_68 = V_101 ;
break;
}
V_16 = V_146 ;
case V_147 :
if ( ! V_16 )
V_16 = V_148 ;
V_4 -> V_12 = V_149 ;
F_62 ( V_4 , V_8 -> V_150 ) ;
V_68 = V_66 ;
break;
case V_149 :
F_63 ( & V_4 -> V_139 ) ;
F_3 ( V_4 ) ;
break;
default:
break;
}
F_21 ( & V_4 -> V_11 ) ;
if ( V_68 )
F_20 ( V_2 , V_68 , V_4 -> V_4 . V_44 ,
V_4 -> V_14 , V_4 -> V_15 , V_16 ) ;
}
static inline void F_64 ( struct V_3 * V_4 , T_2 V_151 )
{
V_4 -> V_139 . V_140 = V_112 + F_65 ( V_151 ) ;
V_4 -> V_139 . V_136 = ( unsigned long ) V_4 ;
V_4 -> V_139 . V_152 = F_59 ;
V_4 -> V_145 = V_151 ;
F_66 ( & V_4 -> V_139 ) ;
}
static bool F_67 ( struct V_1 * V_2 ,
T_3 V_14 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
bool V_153 = false ;
struct V_3 * V_4 ;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( ! memcmp ( & V_4 -> V_14 , & V_14 , sizeof( V_14 ) ) ) {
V_153 = true ;
break;
}
}
F_10 () ;
return V_153 ;
}
static T_3 F_68 ( struct V_1 * V_2 )
{
T_3 V_14 ;
do {
F_61 ( & V_14 , sizeof( V_14 ) ) ;
V_14 = ( V_14 % V_154 ) + 1 ;
} while ( F_67 ( V_2 , V_14 ) );
return V_14 ;
}
T_2 F_56 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 ;
if ( ! F_69 ( V_4 , V_155 ) )
return 0 ;
F_19 ( & V_4 -> V_11 ) ;
V_4 -> V_14 = F_68 ( V_2 ) ;
if ( V_4 -> V_12 != V_13 &&
V_4 -> V_12 != V_63 ) {
F_21 ( & V_4 -> V_11 ) ;
return 0 ;
}
V_4 -> V_12 = V_143 ;
F_64 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_156 ) ;
F_21 ( & V_4 -> V_11 ) ;
F_11 ( V_2 ,
L_9 ,
V_4 -> V_4 . V_44 ) ;
V_28 = F_70 ( V_2 ) ;
F_20 ( V_2 , V_101 ,
V_4 -> V_4 . V_44 , V_4 -> V_14 , 0 , 0 ) ;
return V_28 ;
}
T_2 F_71 ( struct V_3 * V_4 )
{
T_2 V_28 ;
F_19 ( & V_4 -> V_11 ) ;
V_28 = F_13 ( V_4 ) ;
V_4 -> V_12 = V_63 ;
F_21 ( & V_4 -> V_11 ) ;
return V_28 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_157 V_158 )
{
struct V_137 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_16 = ( V_158 == V_159 ) ?
V_160 : V_161 ;
V_4 -> V_16 = V_16 ;
V_4 -> V_12 = V_149 ;
F_62 ( V_4 , V_8 -> V_150 ) ;
}
static T_2 F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_137 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_28 = 0 ;
F_63 ( & V_4 -> V_139 ) ;
V_4 -> V_12 = V_38 ;
V_28 |= F_74 ( V_2 ) ;
V_28 |= F_12 ( V_2 ) ;
V_28 |= F_5 ( V_2 ) ;
F_11 ( V_2 , L_10 , V_4 -> V_4 . V_44 ) ;
F_16 ( V_4 ) ;
V_28 |= F_17 ( V_4 , V_8 -> V_162 ) ;
return V_28 ;
}
static T_2 F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_157 V_158 )
{
struct V_137 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_67 V_68 = 0 ;
T_2 V_28 = 0 ;
F_11 ( V_2 , L_11 , V_4 -> V_4 . V_44 ,
V_141 [ V_4 -> V_12 ] , V_163 [ V_158 ] ) ;
F_19 ( & V_4 -> V_11 ) ;
switch ( V_4 -> V_12 ) {
case V_13 :
switch ( V_158 ) {
case V_159 :
F_3 ( V_4 ) ;
break;
case V_164 :
V_4 -> V_12 = V_142 ;
V_4 -> V_14 = F_68 ( V_2 ) ;
F_64 ( V_4 ,
V_8 -> V_156 ) ;
V_28 |= F_70 ( V_2 ) ;
V_68 = V_101 ;
break;
default:
break;
}
break;
case V_143 :
switch ( V_158 ) {
case V_165 :
case V_166 :
case V_159 :
F_72 ( V_2 , V_4 , V_158 ) ;
V_68 = V_66 ;
break;
case V_164 :
V_4 -> V_12 = V_142 ;
V_68 = V_99 ;
break;
case V_167 :
V_4 -> V_12 = V_147 ;
F_62 ( V_4 , V_8 -> V_168 ) ;
break;
default:
break;
}
break;
case V_142 :
switch ( V_158 ) {
case V_165 :
case V_166 :
case V_159 :
F_72 ( V_2 , V_4 , V_158 ) ;
V_68 = V_66 ;
break;
case V_164 :
V_68 = V_99 ;
break;
case V_167 :
V_28 |= F_73 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_147 :
switch ( V_158 ) {
case V_165 :
case V_166 :
case V_159 :
F_72 ( V_2 , V_4 , V_158 ) ;
V_68 = V_66 ;
break;
case V_164 :
V_28 |= F_73 ( V_2 , V_4 ) ;
V_68 = V_99 ;
break;
default:
break;
}
break;
case V_38 :
switch ( V_158 ) {
case V_159 :
V_28 |= F_13 ( V_4 ) ;
V_28 |= F_12 ( V_2 ) ;
V_28 |= F_5 ( V_2 ) ;
F_72 ( V_2 , V_4 , V_158 ) ;
V_68 = V_66 ;
break;
case V_164 :
V_68 = V_99 ;
break;
default:
break;
}
break;
case V_149 :
switch ( V_158 ) {
case V_159 :
F_63 ( & V_4 -> V_139 ) ;
F_3 ( V_4 ) ;
break;
case V_164 :
case V_167 :
case V_165 :
case V_166 :
V_68 = V_66 ;
break;
default:
break;
}
break;
default:
break;
}
F_21 ( & V_4 -> V_11 ) ;
if ( V_68 ) {
F_20 ( V_2 , V_68 , V_4 -> V_4 . V_44 ,
V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_16 ) ;
if ( V_68 == V_101 ) {
F_20 ( V_2 ,
V_99 ,
V_4 -> V_4 . V_44 , V_4 -> V_14 ,
V_4 -> V_15 , 0 ) ;
}
}
return V_28 ;
}
static enum V_157
F_76 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_104 * V_105 ,
enum V_67 V_169 ,
T_3 V_14 , T_3 V_15 )
{
enum V_157 V_158 = V_170 ;
T_4 V_79 = V_105 -> V_171 ;
bool V_172 ;
V_172 = ( V_169 == V_66 ||
F_77 ( V_2 , V_105 ) ) ;
if ( ! V_172 && ! V_4 ) {
V_158 = V_165 ;
goto V_32;
}
if ( ! V_4 ) {
if ( V_169 != V_101 ) {
F_11 ( V_2 , L_12 ) ;
goto V_32;
}
if ( ! F_78 ( V_2 ) ) {
F_11 ( V_2 , L_13 ) ;
goto V_32;
}
} else {
if ( ! F_69 ( V_4 , V_155 ) ) {
F_11 ( V_2 , L_14 ) ;
goto V_32;
}
if ( V_4 -> V_12 == V_63 )
goto V_32;
}
if ( ! V_4 ) {
V_158 = V_164 ;
goto V_32;
}
switch ( V_169 ) {
case V_101 :
if ( ! V_172 )
V_158 = V_165 ;
if ( ! F_78 ( V_2 ) ||
( V_4 -> V_15 && V_4 -> V_15 != V_15 ) )
V_158 = V_173 ;
else
V_158 = V_164 ;
break;
case V_99 :
if ( ! V_172 )
V_158 = V_166 ;
if ( ! F_78 ( V_2 ) ||
V_4 -> V_14 != V_14 ||
( V_4 -> V_15 && V_4 -> V_15 != V_15 ) )
V_158 = V_174 ;
else
V_158 = V_167 ;
break;
case V_66 :
if ( V_4 -> V_12 == V_38 )
V_158 = V_159 ;
else if ( V_4 -> V_15 != V_15 )
V_158 = V_175 ;
else if ( V_79 == 8 && V_4 -> V_14 != V_14 )
V_158 = V_175 ;
else
V_158 = V_159 ;
break;
default:
F_11 ( V_2 , L_15 ) ;
break;
}
V_32:
return V_158 ;
}
static void
F_79 ( struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_104 * V_105 )
{
struct V_3 * V_4 ;
enum V_157 V_158 ;
enum V_67 V_169 ;
T_2 V_28 = 0 ;
T_4 V_79 = V_105 -> V_171 ;
T_3 V_15 , V_14 = 0 ;
if ( ! V_105 -> V_176 ) {
F_11 ( V_2 ,
L_16 ) ;
return;
}
if ( V_105 -> V_177 &&
V_2 -> V_6 . V_7 . V_129 == V_178 ) {
F_11 ( V_2 ,
L_17 ) ;
return;
}
V_169 = V_75 -> V_6 . V_68 . V_6 . V_81 . V_98 ;
if ( ( V_169 == V_101 && V_79 != 4 ) ||
( V_169 == V_99 && V_79 != 6 ) ||
( V_169 == V_66 && V_79 != 6
&& V_79 != 8 ) ) {
F_11 ( V_2 ,
L_18 ,
V_169 , V_79 ) ;
return;
}
if ( V_169 != V_66 &&
( ! V_105 -> V_179 || ! V_105 -> V_137 ) ) {
F_11 ( V_2 , L_19 ) ;
return;
}
V_15 = F_80 ( F_81 ( V_105 -> V_176 ) ) ;
if ( V_169 == V_99 ||
( V_169 == V_66 && V_79 == 8 ) )
V_14 = F_80 ( F_82 ( V_105 -> V_176 ) ) ;
F_8 () ;
V_4 = F_52 ( V_2 , V_75 -> V_94 ) ;
if ( V_169 == V_101 &&
! F_1 ( V_2 , V_4 ) ) {
F_11 ( V_2 , L_20 ,
V_75 -> V_94 ) ;
goto V_180;
}
V_158 = F_76 ( V_2 , V_4 , V_105 , V_169 , V_14 , V_15 ) ;
if ( V_158 == V_164 ) {
F_10 () ;
V_4 = F_51 ( V_2 , V_75 -> V_94 , V_105 ) ;
if ( ! V_4 ) {
F_11 ( V_2 , L_21 ) ;
goto V_180;
}
V_4 -> V_15 = V_15 ;
} else if ( ! V_4 && V_158 == V_165 ) {
F_20 ( V_2 , V_66 ,
V_75 -> V_94 , 0 , V_15 ,
V_161 ) ;
goto V_180;
} else if ( ! V_4 || V_158 == V_170 ) {
goto V_180;
}
if ( ! V_4 -> V_15 && V_158 == V_167 )
V_4 -> V_15 = V_15 ;
V_28 |= F_75 ( V_2 , V_4 , V_158 ) ;
V_180:
F_10 () ;
if ( V_28 )
F_58 ( V_2 , V_28 ) ;
}
void F_83 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_6 V_181 ,
struct V_182 * V_183 )
{
struct V_104 V_105 ;
T_6 V_184 ;
T_4 * V_185 ;
if ( V_181 < V_186 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_128 )
return;
if ( F_84 ( V_75 -> V_69 ) ) {
F_11 ( V_2 ,
L_22 ) ;
return;
}
V_185 = V_75 -> V_6 . V_68 . V_6 . V_81 . V_187 ;
V_184 = ( T_4 * ) V_75 -> V_6 . V_68 . V_6 . V_81 . V_187 - ( T_4 * ) V_75 ;
if ( V_75 -> V_6 . V_68 . V_6 . V_81 . V_98 ==
V_99 ) {
V_185 += 4 ;
V_184 += 4 ;
if ( V_184 > V_181 )
return;
}
F_85 ( V_185 , V_181 - V_184 , true , & V_105 ) ;
F_79 ( V_2 , V_75 , & V_105 ) ;
}
