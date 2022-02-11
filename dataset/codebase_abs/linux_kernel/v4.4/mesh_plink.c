static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 . V_7 . V_8 . V_5 ;
return V_5 == 0 ||
( V_4 &&
( V_9 ) - F_2 ( & V_4 -> V_10 . V_11 ) >
V_5 ) ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_7 -> V_12 ) ;
V_4 -> V_7 -> V_13 = V_14 ;
V_4 -> V_7 -> V_15 = V_4 -> V_7 -> V_16 = V_4 -> V_7 -> V_17 = 0 ;
V_4 -> V_7 -> V_18 = 0 ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
enum V_21 V_22 = F_6 ( V_2 ) ;
struct V_23 * V_24 = V_20 -> V_25 . V_26 -> V_27 [ V_22 ] ;
struct V_3 * V_4 ;
T_2 V_28 = 0 , V_29 = 0 ;
int V_30 ;
bool V_31 = false ;
if ( V_22 == V_32 ) {
V_31 = true ;
goto V_33;
} else if ( V_22 != V_34 )
goto V_33;
for ( V_30 = 0 ; V_30 < V_24 -> V_35 ; V_30 ++ )
if ( V_24 -> V_36 [ V_30 ] . V_37 & V_38 )
V_28 |= F_7 ( V_30 ) ;
if ( ! V_28 )
goto V_33;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_7 -> V_13 != V_39 )
continue;
V_31 = false ;
if ( V_28 & V_4 -> V_4 . V_40 [ V_22 ] )
V_31 = true ;
else
break;
}
F_10 () ;
V_33:
if ( V_2 -> V_41 . V_42 . V_43 != V_31 ) {
V_2 -> V_41 . V_42 . V_43 = V_31 ;
V_29 = V_44 ;
F_11 ( V_2 , L_1 ,
V_2 -> V_41 . V_45 , V_31 ) ;
}
return V_29 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
T_3 V_46 ;
bool V_47 = false , V_48 = false ;
switch ( V_2 -> V_41 . V_42 . V_49 . V_50 ) {
case V_51 :
case V_52 :
case V_53 :
return 0 ;
default:
break;
}
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_7 -> V_13 != V_39 )
continue;
if ( V_4 -> V_4 . V_54 > V_55 )
continue;
if ( ! V_4 -> V_4 . V_56 . V_57 ) {
F_11 ( V_2 , L_2 ,
V_4 -> V_4 . V_45 ) ;
V_47 = true ;
break;
}
F_11 ( V_2 , L_3 , V_4 -> V_4 . V_45 ) ;
V_48 = true ;
}
F_10 () ;
if ( V_47 )
V_46 = V_58 ;
else if ( V_48 &&
V_2 -> V_41 . V_42 . V_49 . V_50 > V_59 )
V_46 = V_60 ;
else
V_46 = V_61 ;
if ( V_2 -> V_41 . V_42 . V_62 == V_46 )
return 0 ;
V_2 -> V_41 . V_42 . V_62 = V_46 ;
V_2 -> V_6 . V_7 . V_8 . V_46 = V_46 ;
F_11 ( V_2 , L_4 , V_46 ) ;
return V_63 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_64 V_65 ,
T_4 * V_66 , T_3 V_15 , T_3 V_16 , T_3 V_17 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_67 * V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
bool V_73 = false ;
T_3 V_74 = 0 ;
T_4 * V_75 , V_76 = 4 ;
int V_77 = F_14 ( struct V_71 , V_6 . V_65 . V_6 . V_78 ) +
sizeof( V_72 -> V_6 . V_65 . V_6 . V_78 ) ;
int V_79 = - V_80 ;
V_68 = F_15 ( V_20 -> V_81 +
V_77 +
2 +
2 +
2 + 8 +
2 + ( V_82 - 8 ) +
2 + V_2 -> V_6 . V_7 . V_83 +
2 + sizeof( struct V_84 ) +
2 + sizeof( struct V_85 ) +
2 + sizeof( struct V_86 ) +
2 + sizeof( struct V_87 ) +
2 + sizeof( struct V_88 ) +
2 + 8 +
V_2 -> V_6 . V_7 . V_76 ) ;
if ( ! V_68 )
return V_79 ;
V_70 = F_16 ( V_68 ) ;
F_17 ( V_68 , V_20 -> V_81 ) ;
V_72 = (struct V_71 * ) F_18 ( V_68 , V_77 ) ;
memset ( V_72 , 0 , V_77 ) ;
V_72 -> V_89 = F_19 ( V_90 |
V_91 ) ;
memcpy ( V_72 -> V_66 , V_66 , V_92 ) ;
memcpy ( V_72 -> V_93 , V_2 -> V_41 . V_45 , V_92 ) ;
memcpy ( V_72 -> V_94 , V_2 -> V_41 . V_45 , V_92 ) ;
V_72 -> V_6 . V_65 . V_95 = V_96 ;
V_72 -> V_6 . V_65 . V_6 . V_78 . V_97 = V_65 ;
if ( V_65 != V_98 ) {
enum V_21 V_22 = F_6 ( V_2 ) ;
V_75 = F_18 ( V_68 , 2 ) ;
memset ( V_75 , 0 , 2 ) ;
if ( V_65 == V_99 ) {
V_75 = F_18 ( V_68 , 2 ) ;
F_20 ( V_4 -> V_4 . V_100 , V_75 ) ;
}
if ( F_21 ( V_2 , V_68 , true , V_22 ) ||
F_22 ( V_2 , V_68 , true , V_22 ) ||
F_23 ( V_2 , V_68 ) ||
F_24 ( V_2 , V_68 ) ||
F_25 ( V_2 , V_68 ) )
goto free;
} else {
V_70 -> V_37 |= V_101 ;
if ( F_24 ( V_2 , V_68 ) )
goto free;
}
switch ( V_65 ) {
case V_102 :
break;
case V_99 :
V_76 += 2 ;
V_73 = true ;
break;
case V_98 :
if ( V_16 ) {
V_76 += 2 ;
V_73 = true ;
}
V_76 += 2 ;
break;
default:
V_79 = - V_103 ;
goto free;
}
if ( F_26 ( F_27 ( V_68 ) < 2 + V_76 ) )
goto free;
V_75 = F_18 ( V_68 , 2 + V_76 ) ;
* V_75 ++ = V_104 ;
* V_75 ++ = V_76 ;
memcpy ( V_75 , & V_74 , 2 ) ;
V_75 += 2 ;
F_20 ( V_15 , V_75 ) ;
V_75 += 2 ;
if ( V_73 ) {
F_20 ( V_16 , V_75 ) ;
V_75 += 2 ;
}
if ( V_65 == V_98 ) {
F_20 ( V_17 , V_75 ) ;
V_75 += 2 ;
}
if ( V_65 != V_98 ) {
if ( F_28 ( V_2 , V_68 ) ||
F_29 ( V_2 , V_68 ) ||
F_30 ( V_2 , V_68 ) ||
F_31 ( V_2 , V_68 ) )
goto free;
}
if ( F_32 ( V_2 , V_68 ) )
goto free;
F_33 ( V_2 , V_68 ) ;
return 0 ;
free:
F_34 ( V_68 ) ;
return V_79 ;
}
static T_2 F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_29 = 0 ;
F_4 ( & V_4 -> V_7 -> V_12 ) ;
if ( V_4 -> V_7 -> V_13 == V_39 )
V_29 = F_36 ( V_2 ) ;
V_4 -> V_7 -> V_13 = V_105 ;
F_37 ( V_4 ) ;
F_38 ( V_4 ) ;
V_29 |= F_39 ( V_4 ,
V_106 ) ;
return V_29 ;
}
T_2 F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_29 ;
F_41 ( & V_4 -> V_7 -> V_12 ) ;
V_29 = F_35 ( V_4 ) ;
V_4 -> V_7 -> V_17 = V_107 ;
F_13 ( V_2 , V_4 , V_98 ,
V_4 -> V_4 . V_45 , V_4 -> V_7 -> V_15 , V_4 -> V_7 -> V_16 ,
V_4 -> V_7 -> V_17 ) ;
F_42 ( & V_4 -> V_7 -> V_12 ) ;
return V_29 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_109 , bool V_110 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
enum V_21 V_22 = F_6 ( V_2 ) ;
struct V_23 * V_24 ;
T_2 V_111 , V_112 = 0 , V_29 = 0 ;
enum V_113 V_114 = V_4 -> V_4 . V_54 ;
V_24 = V_20 -> V_25 . V_26 -> V_27 [ V_22 ] ;
V_111 = F_44 ( V_2 , V_109 , V_22 , & V_112 ) ;
F_41 ( & V_4 -> V_7 -> V_12 ) ;
V_4 -> V_10 . V_115 = V_116 ;
if ( V_4 -> V_7 -> V_13 == V_39 &&
V_4 -> V_7 -> V_117 )
goto V_33;
V_4 -> V_7 -> V_117 = true ;
if ( V_4 -> V_4 . V_40 [ V_22 ] != V_111 )
V_29 |= V_118 ;
V_4 -> V_4 . V_40 [ V_22 ] = V_111 ;
if ( F_45 ( V_2 , V_24 ,
V_109 -> V_119 , V_4 ) )
V_29 |= V_120 ;
F_46 ( V_2 , V_24 ,
V_109 -> V_121 , V_4 ) ;
if ( V_114 != V_4 -> V_4 . V_54 )
V_29 |= V_120 ;
if ( V_109 -> V_122 &&
! ( V_109 -> V_122 -> V_123 &
V_124 ) ) {
if ( V_4 -> V_4 . V_54 != V_55 )
V_29 |= V_120 ;
V_4 -> V_4 . V_54 = V_55 ;
}
if ( V_110 )
F_47 ( V_4 ) ;
else
F_48 ( V_20 , V_24 , V_4 , V_29 ) ;
V_33:
F_42 ( & V_4 -> V_7 -> V_12 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long * V_125 ;
int V_100 ;
V_125 = F_50 ( F_51 ( V_126 + 1 ) ,
sizeof( * V_125 ) , V_127 ) ;
if ( ! V_125 )
return - V_80 ;
F_52 ( 0 , V_125 ) ;
F_8 () ;
F_9 (sta, &sdata->local->sta_list, list)
F_52 ( V_4 -> V_4 . V_100 , V_125 ) ;
F_10 () ;
V_100 = F_53 ( V_125 , V_126 + 1 ) ;
F_54 ( V_125 ) ;
if ( V_100 > V_126 )
return - V_128 ;
return V_100 ;
}
static struct V_3 *
F_55 ( struct V_1 * V_2 , T_4 * V_129 )
{
struct V_3 * V_4 ;
int V_100 ;
if ( V_2 -> V_20 -> V_130 >= V_131 )
return NULL ;
V_100 = F_49 ( V_2 ) ;
if ( V_100 < 0 )
return NULL ;
V_4 = F_56 ( V_2 , V_129 , V_127 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 -> V_13 = V_14 ;
V_4 -> V_4 . V_132 = true ;
V_4 -> V_4 . V_100 = V_100 ;
F_57 ( V_4 , V_133 ) ;
F_57 ( V_4 , V_134 ) ;
F_57 ( V_4 , V_135 ) ;
return V_4 ;
}
static struct V_3 *
F_58 ( struct V_1 * V_2 , T_4 * V_45 ,
struct V_108 * V_109 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_136 ||
V_2 -> V_6 . V_7 . V_137 & V_138 )
F_59 ( V_2 -> V_139 , V_45 ,
V_109 -> V_140 ,
V_109 -> V_141 ,
V_127 ) ;
else
V_4 = F_55 ( V_2 , V_45 ) ;
return V_4 ;
}
static struct V_3 *
F_60 ( struct V_1 * V_2 ,
T_4 * V_45 , struct V_108 * V_109 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_8 () ;
V_4 = F_61 ( V_2 , V_45 ) ;
if ( V_4 ) {
F_43 ( V_2 , V_4 , V_109 , false ) ;
} else {
F_10 () ;
V_4 = F_58 ( V_2 , V_45 , V_109 ) ;
if ( ! V_4 ) {
F_8 () ;
return NULL ;
}
F_43 ( V_2 , V_4 , V_109 , true ) ;
if ( F_62 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_63 ( struct V_1 * V_2 ,
T_4 * V_129 ,
struct V_108 * V_109 )
{
struct V_3 * V_4 ;
T_2 V_29 = 0 ;
V_4 = F_60 ( V_2 , V_129 , V_109 ) ;
if ( ! V_4 )
goto V_33;
if ( F_64 ( V_109 ) &&
V_4 -> V_7 -> V_13 == V_14 &&
V_2 -> V_6 . V_7 . V_142 &&
V_2 -> V_6 . V_7 . V_8 . V_143 &&
F_1 ( V_2 , V_4 ) )
V_29 = F_65 ( V_4 ) ;
F_66 ( V_4 , V_109 ) ;
V_33:
F_10 () ;
F_67 ( V_2 , V_29 ) ;
}
static void F_68 ( unsigned long V_144 )
{
struct V_3 * V_4 ;
T_3 V_17 = 0 ;
struct V_1 * V_2 ;
struct V_145 * V_8 ;
enum V_64 V_65 = 0 ;
V_4 = (struct V_3 * ) V_144 ;
if ( V_4 -> V_2 -> V_20 -> V_146 )
return;
F_41 ( & V_4 -> V_7 -> V_12 ) ;
if ( F_69 ( V_116 , V_4 -> V_7 -> V_147 . V_148 ) ) {
F_11 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_45 , V_149 [ V_4 -> V_7 -> V_13 ] ) ;
F_42 ( & V_4 -> V_7 -> V_12 ) ;
return;
}
if ( V_4 -> V_7 -> V_13 == V_14 ||
V_4 -> V_7 -> V_13 == V_39 ) {
F_11 ( V_4 -> V_2 ,
L_6 ,
V_4 -> V_4 . V_45 , V_149 [ V_4 -> V_7 -> V_13 ] ) ;
F_42 ( & V_4 -> V_7 -> V_12 ) ;
return;
}
F_11 ( V_4 -> V_2 ,
L_7 ,
V_4 -> V_4 . V_45 , V_149 [ V_4 -> V_7 -> V_13 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_7 -> V_13 ) {
case V_150 :
case V_151 :
if ( V_4 -> V_7 -> V_18 < V_8 -> V_152 ) {
T_2 rand ;
F_11 ( V_4 -> V_2 ,
L_8 ,
V_4 -> V_4 . V_45 , V_4 -> V_7 -> V_18 ,
V_4 -> V_7 -> V_153 ) ;
F_70 ( & rand , sizeof( T_2 ) ) ;
V_4 -> V_7 -> V_153 = V_4 -> V_7 -> V_153 +
rand % V_4 -> V_7 -> V_153 ;
++ V_4 -> V_7 -> V_18 ;
F_71 ( V_4 , V_4 -> V_7 -> V_153 ) ;
V_65 = V_102 ;
break;
}
V_17 = V_154 ;
case V_155 :
if ( ! V_17 )
V_17 = V_156 ;
V_4 -> V_7 -> V_13 = V_157 ;
F_71 ( V_4 , V_8 -> V_158 ) ;
V_65 = V_98 ;
break;
case V_157 :
F_72 ( & V_4 -> V_7 -> V_147 ) ;
F_3 ( V_4 ) ;
break;
default:
break;
}
F_42 ( & V_4 -> V_7 -> V_12 ) ;
if ( V_65 )
F_13 ( V_2 , V_4 , V_65 , V_4 -> V_4 . V_45 ,
V_4 -> V_7 -> V_15 , V_4 -> V_7 -> V_16 , V_17 ) ;
}
static inline void F_73 ( struct V_3 * V_4 , T_2 V_159 )
{
V_4 -> V_7 -> V_147 . V_148 = V_116 + F_74 ( V_159 ) ;
V_4 -> V_7 -> V_147 . V_144 = ( unsigned long ) V_4 ;
V_4 -> V_7 -> V_147 . V_160 = F_68 ;
V_4 -> V_7 -> V_153 = V_159 ;
F_75 ( & V_4 -> V_7 -> V_147 ) ;
}
static bool F_76 ( struct V_1 * V_2 ,
T_3 V_15 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
bool V_161 = false ;
struct V_3 * V_4 ;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 )
continue;
if ( ! memcmp ( & V_4 -> V_7 -> V_15 , & V_15 , sizeof( V_15 ) ) ) {
V_161 = true ;
break;
}
}
F_10 () ;
return V_161 ;
}
static T_3 F_77 ( struct V_1 * V_2 )
{
T_3 V_15 ;
do {
F_70 ( & V_15 , sizeof( V_15 ) ) ;
} while ( F_76 ( V_2 , V_15 ) );
return V_15 ;
}
T_2 F_65 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_29 ;
if ( ! F_78 ( V_4 , V_162 ) )
return 0 ;
F_41 ( & V_4 -> V_7 -> V_12 ) ;
V_4 -> V_7 -> V_15 = F_77 ( V_2 ) ;
if ( V_4 -> V_7 -> V_13 != V_14 &&
V_4 -> V_7 -> V_13 != V_105 ) {
F_42 ( & V_4 -> V_7 -> V_12 ) ;
return 0 ;
}
V_4 -> V_7 -> V_13 = V_151 ;
F_73 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_163 ) ;
F_42 ( & V_4 -> V_7 -> V_12 ) ;
F_11 ( V_2 ,
L_9 ,
V_4 -> V_4 . V_45 ) ;
V_29 = F_79 ( V_2 ) ;
F_13 ( V_2 , V_4 , V_102 ,
V_4 -> V_4 . V_45 , V_4 -> V_7 -> V_15 , 0 , 0 ) ;
return V_29 ;
}
T_2 F_80 ( struct V_3 * V_4 )
{
T_2 V_29 ;
F_41 ( & V_4 -> V_7 -> V_12 ) ;
V_29 = F_35 ( V_4 ) ;
V_4 -> V_7 -> V_13 = V_105 ;
F_42 ( & V_4 -> V_7 -> V_12 ) ;
return V_29 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_164 V_165 )
{
struct V_145 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_17 = ( V_165 == V_166 ) ?
V_167 : V_168 ;
V_4 -> V_7 -> V_17 = V_17 ;
V_4 -> V_7 -> V_13 = V_157 ;
F_71 ( V_4 , V_8 -> V_158 ) ;
}
static T_2 F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_145 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_29 = 0 ;
F_72 ( & V_4 -> V_7 -> V_147 ) ;
V_4 -> V_7 -> V_13 = V_39 ;
V_29 |= F_83 ( V_2 ) ;
V_29 |= F_12 ( V_2 ) ;
V_29 |= F_5 ( V_2 ) ;
F_11 ( V_2 , L_10 , V_4 -> V_4 . V_45 ) ;
F_38 ( V_4 ) ;
V_29 |= F_39 ( V_4 , V_8 -> V_169 ) ;
return V_29 ;
}
static T_2 F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_164 V_165 )
{
struct V_145 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_64 V_65 = 0 ;
T_2 V_29 = 0 ;
F_11 ( V_2 , L_11 , V_4 -> V_4 . V_45 ,
V_149 [ V_4 -> V_7 -> V_13 ] , V_170 [ V_165 ] ) ;
F_41 ( & V_4 -> V_7 -> V_12 ) ;
switch ( V_4 -> V_7 -> V_13 ) {
case V_14 :
switch ( V_165 ) {
case V_166 :
F_3 ( V_4 ) ;
break;
case V_171 :
V_4 -> V_7 -> V_13 = V_150 ;
V_4 -> V_7 -> V_15 = F_77 ( V_2 ) ;
F_73 ( V_4 ,
V_8 -> V_163 ) ;
V_29 |= F_79 ( V_2 ) ;
V_65 = V_102 ;
break;
default:
break;
}
break;
case V_151 :
switch ( V_165 ) {
case V_172 :
case V_173 :
case V_166 :
F_81 ( V_2 , V_4 , V_165 ) ;
V_65 = V_98 ;
break;
case V_171 :
V_4 -> V_7 -> V_13 = V_150 ;
V_65 = V_99 ;
break;
case V_174 :
V_4 -> V_7 -> V_13 = V_155 ;
F_71 ( V_4 , V_8 -> V_175 ) ;
break;
default:
break;
}
break;
case V_150 :
switch ( V_165 ) {
case V_172 :
case V_173 :
case V_166 :
F_81 ( V_2 , V_4 , V_165 ) ;
V_65 = V_98 ;
break;
case V_171 :
V_65 = V_99 ;
break;
case V_174 :
V_29 |= F_82 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_155 :
switch ( V_165 ) {
case V_172 :
case V_173 :
case V_166 :
F_81 ( V_2 , V_4 , V_165 ) ;
V_65 = V_98 ;
break;
case V_171 :
V_29 |= F_82 ( V_2 , V_4 ) ;
V_65 = V_99 ;
break;
default:
break;
}
break;
case V_39 :
switch ( V_165 ) {
case V_166 :
V_29 |= F_35 ( V_4 ) ;
V_29 |= F_12 ( V_2 ) ;
V_29 |= F_5 ( V_2 ) ;
F_81 ( V_2 , V_4 , V_165 ) ;
V_65 = V_98 ;
break;
case V_171 :
V_65 = V_99 ;
break;
default:
break;
}
break;
case V_157 :
switch ( V_165 ) {
case V_166 :
F_72 ( & V_4 -> V_7 -> V_147 ) ;
F_3 ( V_4 ) ;
break;
case V_171 :
case V_174 :
case V_172 :
case V_173 :
V_65 = V_98 ;
break;
default:
break;
}
break;
default:
break;
}
F_42 ( & V_4 -> V_7 -> V_12 ) ;
if ( V_65 ) {
F_13 ( V_2 , V_4 , V_65 , V_4 -> V_4 . V_45 ,
V_4 -> V_7 -> V_15 , V_4 -> V_7 -> V_16 ,
V_4 -> V_7 -> V_17 ) ;
if ( V_65 == V_102 ) {
F_13 ( V_2 , V_4 ,
V_99 ,
V_4 -> V_4 . V_45 , V_4 -> V_7 -> V_15 ,
V_4 -> V_7 -> V_16 , 0 ) ;
}
}
return V_29 ;
}
static enum V_164
F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_108 * V_109 ,
enum V_64 V_176 ,
T_3 V_15 , T_3 V_16 )
{
enum V_164 V_165 = V_177 ;
T_4 V_76 = V_109 -> V_178 ;
bool V_179 ;
V_179 = ( V_176 == V_98 ||
F_86 ( V_2 , V_109 ) ) ;
if ( ! V_179 && ! V_4 ) {
V_165 = V_172 ;
goto V_33;
}
if ( ! V_4 ) {
if ( V_176 != V_102 ) {
F_11 ( V_2 , L_12 ) ;
goto V_33;
}
if ( ! F_87 ( V_2 ) ) {
F_11 ( V_2 , L_13 ) ;
goto V_33;
}
} else {
if ( ! F_78 ( V_4 , V_162 ) ) {
F_11 ( V_2 , L_14 ) ;
goto V_33;
}
if ( V_4 -> V_7 -> V_13 == V_105 )
goto V_33;
}
if ( ! V_4 ) {
V_165 = V_171 ;
goto V_33;
}
switch ( V_176 ) {
case V_102 :
if ( ! V_179 )
V_165 = V_172 ;
if ( ! F_87 ( V_2 ) ||
( V_4 -> V_7 -> V_16 && V_4 -> V_7 -> V_16 != V_16 ) )
V_165 = V_180 ;
else
V_165 = V_171 ;
break;
case V_99 :
if ( ! V_179 )
V_165 = V_173 ;
if ( ! F_87 ( V_2 ) ||
V_4 -> V_7 -> V_15 != V_15 ||
( V_4 -> V_7 -> V_16 && V_4 -> V_7 -> V_16 != V_16 ) )
V_165 = V_181 ;
else
V_165 = V_174 ;
break;
case V_98 :
if ( V_4 -> V_7 -> V_13 == V_39 )
V_165 = V_166 ;
else if ( V_4 -> V_7 -> V_16 != V_16 )
V_165 = V_182 ;
else if ( V_76 == 8 && V_4 -> V_7 -> V_15 != V_15 )
V_165 = V_182 ;
else
V_165 = V_166 ;
break;
default:
F_11 ( V_2 , L_15 ) ;
break;
}
V_33:
return V_165 ;
}
static void
F_88 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_108 * V_109 )
{
struct V_3 * V_4 ;
enum V_164 V_165 ;
enum V_64 V_176 ;
T_2 V_29 = 0 ;
T_4 V_76 = V_109 -> V_178 ;
T_3 V_16 , V_15 = 0 ;
if ( ! V_109 -> V_183 ) {
F_11 ( V_2 ,
L_16 ) ;
return;
}
if ( V_109 -> V_184 &&
V_2 -> V_6 . V_7 . V_137 == V_185 ) {
F_11 ( V_2 ,
L_17 ) ;
return;
}
V_176 = V_72 -> V_6 . V_65 . V_6 . V_78 . V_97 ;
if ( ( V_176 == V_102 && V_76 != 4 ) ||
( V_176 == V_99 && V_76 != 6 ) ||
( V_176 == V_98 && V_76 != 6
&& V_76 != 8 ) ) {
F_11 ( V_2 ,
L_18 ,
V_176 , V_76 ) ;
return;
}
if ( V_176 != V_98 &&
( ! V_109 -> V_186 || ! V_109 -> V_145 ) ) {
F_11 ( V_2 , L_19 ) ;
return;
}
V_16 = F_89 ( F_90 ( V_109 -> V_183 ) ) ;
if ( V_176 == V_99 ||
( V_176 == V_98 && V_76 == 8 ) )
V_15 = F_89 ( F_91 ( V_109 -> V_183 ) ) ;
F_8 () ;
V_4 = F_61 ( V_2 , V_72 -> V_93 ) ;
if ( V_176 == V_102 &&
! F_1 ( V_2 , V_4 ) ) {
F_11 ( V_2 , L_20 ,
V_72 -> V_93 ) ;
goto V_187;
}
V_165 = F_85 ( V_2 , V_4 , V_109 , V_176 , V_15 , V_16 ) ;
if ( V_165 == V_171 ) {
F_10 () ;
V_4 = F_60 ( V_2 , V_72 -> V_93 , V_109 ) ;
if ( ! V_4 ) {
F_11 ( V_2 , L_21 ) ;
goto V_187;
}
V_4 -> V_7 -> V_16 = V_16 ;
} else if ( ! V_4 && V_165 == V_172 ) {
F_13 ( V_2 , NULL , V_98 ,
V_72 -> V_93 , 0 , V_16 ,
V_168 ) ;
goto V_187;
} else if ( ! V_4 || V_165 == V_177 ) {
goto V_187;
}
if ( V_165 == V_174 ) {
if ( ! V_4 -> V_7 -> V_16 )
V_4 -> V_7 -> V_16 = V_16 ;
V_4 -> V_7 -> V_100 = F_89 ( F_92 ( V_72 ) ) ;
}
V_29 |= F_84 ( V_2 , V_4 , V_165 ) ;
V_187:
F_10 () ;
if ( V_29 )
F_67 ( V_2 , V_29 ) ;
}
void F_93 ( struct V_1 * V_2 ,
struct V_71 * V_72 , T_6 V_188 ,
struct V_189 * V_190 )
{
struct V_108 V_109 ;
T_6 V_191 ;
T_4 * V_192 ;
if ( V_188 < V_193 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_136 )
return;
if ( F_94 ( V_72 -> V_66 ) ) {
F_11 ( V_2 ,
L_22 ) ;
return;
}
V_192 = V_72 -> V_6 . V_65 . V_6 . V_78 . V_194 ;
V_191 = ( T_4 * ) V_72 -> V_6 . V_65 . V_6 . V_78 . V_194 - ( T_4 * ) V_72 ;
if ( V_72 -> V_6 . V_65 . V_6 . V_78 . V_97 ==
V_99 ) {
V_192 += 4 ;
V_191 += 4 ;
if ( V_191 > V_188 )
return;
}
F_95 ( V_192 , V_188 - V_191 , true , & V_109 ) ;
F_88 ( V_2 , V_72 , & V_109 ) ;
}
