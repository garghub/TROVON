static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 . V_7 . V_8 . V_5 ;
return V_5 == 0 ||
( V_4 &&
( V_9 ) - F_2 ( & V_4 -> V_10 . signal ) >
V_5 ) ;
}
static inline void F_3 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_7 -> V_12 = V_13 ;
V_4 -> V_7 -> V_14 = V_4 -> V_7 -> V_15 = V_4 -> V_7 -> V_16 = 0 ;
V_4 -> V_7 -> V_17 = 0 ;
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
V_4 -> V_7 -> V_12 != V_38 )
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
V_4 -> V_7 -> V_12 != V_38 )
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
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_63 V_64 ,
T_4 * V_65 , T_3 V_14 , T_3 V_15 , T_3 V_16 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
bool V_72 = false ;
T_3 V_73 = 0 ;
T_4 * V_74 , V_75 = 4 ;
int V_76 = F_14 ( struct V_70 , V_6 . V_64 . V_6 . V_77 ) +
sizeof( V_71 -> V_6 . V_64 . V_6 . V_77 ) ;
int V_78 = - V_79 ;
V_67 = F_15 ( V_19 -> V_80 +
V_76 +
2 +
2 +
2 + 8 +
2 + ( V_81 - 8 ) +
2 + V_2 -> V_6 . V_7 . V_82 +
2 + sizeof( struct V_83 ) +
2 + sizeof( struct V_84 ) +
2 + sizeof( struct V_85 ) +
2 + sizeof( struct V_86 ) +
2 + sizeof( struct V_87 ) +
2 + 8 +
V_2 -> V_6 . V_7 . V_75 ) ;
if ( ! V_67 )
return V_78 ;
V_69 = F_16 ( V_67 ) ;
F_17 ( V_67 , V_19 -> V_80 ) ;
V_71 = (struct V_70 * ) F_18 ( V_67 , V_76 ) ;
memset ( V_71 , 0 , V_76 ) ;
V_71 -> V_88 = F_19 ( V_89 |
V_90 ) ;
memcpy ( V_71 -> V_65 , V_65 , V_91 ) ;
memcpy ( V_71 -> V_92 , V_2 -> V_40 . V_44 , V_91 ) ;
memcpy ( V_71 -> V_93 , V_2 -> V_40 . V_44 , V_91 ) ;
V_71 -> V_6 . V_64 . V_94 = V_95 ;
V_71 -> V_6 . V_64 . V_6 . V_77 . V_96 = V_64 ;
if ( V_64 != V_97 ) {
enum V_20 V_21 = F_6 ( V_2 ) ;
V_74 = F_18 ( V_67 , 2 ) ;
memset ( V_74 , 0 , 2 ) ;
if ( V_64 == V_98 ) {
V_74 = F_18 ( V_67 , 2 ) ;
F_20 ( V_4 -> V_4 . V_99 , V_74 ) ;
}
if ( F_21 ( V_2 , V_67 , true , V_21 ) ||
F_22 ( V_2 , V_67 , true , V_21 ) ||
F_23 ( V_2 , V_67 ) ||
F_24 ( V_2 , V_67 ) ||
F_25 ( V_2 , V_67 ) )
goto free;
} else {
V_69 -> V_36 |= V_100 ;
if ( F_24 ( V_2 , V_67 ) )
goto free;
}
switch ( V_64 ) {
case V_101 :
break;
case V_98 :
V_75 += 2 ;
V_72 = true ;
break;
case V_97 :
if ( V_15 ) {
V_75 += 2 ;
V_72 = true ;
}
V_75 += 2 ;
break;
default:
V_78 = - V_102 ;
goto free;
}
if ( F_26 ( F_27 ( V_67 ) < 2 + V_75 ) )
goto free;
V_74 = F_18 ( V_67 , 2 + V_75 ) ;
* V_74 ++ = V_103 ;
* V_74 ++ = V_75 ;
memcpy ( V_74 , & V_73 , 2 ) ;
V_74 += 2 ;
F_20 ( V_14 , V_74 ) ;
V_74 += 2 ;
if ( V_72 ) {
F_20 ( V_15 , V_74 ) ;
V_74 += 2 ;
}
if ( V_64 == V_97 ) {
F_20 ( V_16 , V_74 ) ;
V_74 += 2 ;
}
if ( V_64 != V_97 ) {
if ( F_28 ( V_2 , V_67 ) ||
F_29 ( V_2 , V_67 ) ||
F_30 ( V_2 , V_67 ) ||
F_31 ( V_2 , V_67 ) )
goto free;
}
if ( F_32 ( V_2 , V_67 ) )
goto free;
F_33 ( V_2 , V_67 ) ;
return 0 ;
free:
F_34 ( V_67 ) ;
return V_78 ;
}
static T_2 F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 = 0 ;
F_4 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_4 -> V_7 -> V_12 == V_38 )
V_28 = F_36 ( V_2 ) ;
V_4 -> V_7 -> V_12 = V_104 ;
F_37 ( V_4 ) ;
V_28 |= F_38 ( V_4 ,
V_105 ) ;
return V_28 ;
}
T_2 F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
V_28 = F_35 ( V_4 ) ;
if ( ! V_2 -> V_6 . V_7 . V_106 ) {
V_4 -> V_7 -> V_16 = V_107 ;
F_13 ( V_2 , V_4 , V_97 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_14 ,
V_4 -> V_7 -> V_15 , V_4 -> V_7 -> V_16 ) ;
}
F_41 ( & V_4 -> V_7 -> V_11 ) ;
if ( ! V_2 -> V_6 . V_7 . V_106 )
F_42 ( & V_4 -> V_7 -> V_108 ) ;
F_43 ( V_4 ) ;
F_44 () ;
return V_28 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_109 * V_110 , bool V_111 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
enum V_20 V_21 = F_6 ( V_2 ) ;
struct V_22 * V_23 ;
T_2 V_112 , V_113 = 0 , V_28 = 0 ;
enum V_114 V_115 = V_4 -> V_4 . V_53 ;
V_23 = V_19 -> V_24 . V_25 -> V_26 [ V_21 ] ;
V_112 = F_46 ( V_2 , V_110 , V_21 , & V_113 ) ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_116 . V_117 = V_118 ;
if ( V_4 -> V_7 -> V_12 == V_38 &&
V_4 -> V_7 -> V_119 )
goto V_32;
V_4 -> V_7 -> V_119 = true ;
if ( V_4 -> V_4 . V_39 [ V_21 ] != V_112 )
V_28 |= V_120 ;
V_4 -> V_4 . V_39 [ V_21 ] = V_112 ;
if ( F_47 ( V_2 , V_23 ,
V_110 -> V_121 , V_4 ) )
V_28 |= V_122 ;
F_48 ( V_2 , V_23 ,
V_110 -> V_123 , V_4 ) ;
if ( V_115 != V_4 -> V_4 . V_53 )
V_28 |= V_122 ;
if ( V_110 -> V_124 &&
! ( V_110 -> V_124 -> V_125 &
V_126 ) ) {
if ( V_4 -> V_4 . V_53 != V_54 )
V_28 |= V_122 ;
V_4 -> V_4 . V_53 = V_54 ;
}
if ( V_111 )
F_49 ( V_4 ) ;
else
F_50 ( V_19 , V_23 , V_4 , V_28 ) ;
V_32:
F_41 ( & V_4 -> V_7 -> V_11 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long * V_127 ;
int V_99 ;
V_127 = F_52 ( F_53 ( V_128 + 1 ) ,
sizeof( * V_127 ) , V_129 ) ;
if ( ! V_127 )
return - V_79 ;
F_54 ( 0 , V_127 ) ;
F_8 () ;
F_9 (sta, &sdata->local->sta_list, list)
F_54 ( V_4 -> V_4 . V_99 , V_127 ) ;
F_10 () ;
V_99 = F_55 ( V_127 , V_128 + 1 ) ;
F_56 ( V_127 ) ;
if ( V_99 > V_128 )
return - V_130 ;
return V_99 ;
}
static struct V_3 *
F_57 ( struct V_1 * V_2 , T_4 * V_131 )
{
struct V_3 * V_4 ;
int V_99 ;
if ( V_2 -> V_19 -> V_132 >= V_133 )
return NULL ;
V_99 = F_51 ( V_2 ) ;
if ( V_99 < 0 )
return NULL ;
V_4 = F_58 ( V_2 , V_131 , V_129 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 -> V_12 = V_13 ;
V_4 -> V_4 . V_134 = true ;
V_4 -> V_4 . V_99 = V_99 ;
F_59 ( V_4 , V_135 ) ;
F_59 ( V_4 , V_136 ) ;
F_59 ( V_4 , V_137 ) ;
return V_4 ;
}
static struct V_3 *
F_60 ( struct V_1 * V_2 , T_4 * V_44 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_106 ||
V_2 -> V_6 . V_7 . V_138 & V_139 )
F_61 ( V_2 -> V_140 , V_44 ,
V_110 -> V_141 ,
V_110 -> V_142 ,
V_129 ) ;
else
V_4 = F_57 ( V_2 , V_44 ) ;
return V_4 ;
}
static struct V_3 *
F_62 ( struct V_1 * V_2 ,
T_4 * V_44 , struct V_109 * V_110 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_8 () ;
V_4 = F_63 ( V_2 , V_44 ) ;
if ( V_4 ) {
F_45 ( V_2 , V_4 , V_110 , false ) ;
} else {
F_10 () ;
V_4 = F_60 ( V_2 , V_44 , V_110 ) ;
if ( ! V_4 ) {
F_8 () ;
return NULL ;
}
F_45 ( V_2 , V_4 , V_110 , true ) ;
if ( F_64 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_65 ( struct V_1 * V_2 ,
T_4 * V_131 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 ;
T_2 V_28 = 0 ;
V_4 = F_62 ( V_2 , V_131 , V_110 ) ;
if ( ! V_4 )
goto V_32;
if ( F_66 ( V_110 ) &&
V_4 -> V_7 -> V_12 == V_13 &&
V_2 -> V_6 . V_7 . V_143 &&
V_2 -> V_6 . V_7 . V_8 . V_144 &&
F_1 ( V_2 , V_4 ) )
V_28 = F_67 ( V_4 ) ;
F_68 ( V_4 , V_110 ) ;
V_32:
F_10 () ;
F_69 ( V_2 , V_28 ) ;
}
static void F_70 ( unsigned long V_145 )
{
struct V_3 * V_4 ;
T_3 V_16 = 0 ;
struct V_1 * V_2 ;
struct V_146 * V_8 ;
enum V_63 V_64 = 0 ;
V_4 = (struct V_3 * ) V_145 ;
if ( V_4 -> V_2 -> V_19 -> V_147 )
return;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
if ( F_71 ( V_118 , V_4 -> V_7 -> V_108 . V_148 ) ) {
F_11 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_44 , V_149 [ V_4 -> V_7 -> V_12 ] ) ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
return;
}
if ( V_4 -> V_7 -> V_12 == V_13 ||
V_4 -> V_7 -> V_12 == V_38 ) {
F_11 ( V_4 -> V_2 ,
L_6 ,
V_4 -> V_4 . V_44 , V_149 [ V_4 -> V_7 -> V_12 ] ) ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
return;
}
F_11 ( V_4 -> V_2 ,
L_7 ,
V_4 -> V_4 . V_44 , V_149 [ V_4 -> V_7 -> V_12 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_7 -> V_12 ) {
case V_150 :
case V_151 :
if ( V_4 -> V_7 -> V_17 < V_8 -> V_152 ) {
T_2 rand ;
F_11 ( V_4 -> V_2 ,
L_8 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_17 ,
V_4 -> V_7 -> V_153 ) ;
F_72 ( & rand , sizeof( T_2 ) ) ;
V_4 -> V_7 -> V_153 = V_4 -> V_7 -> V_153 +
rand % V_4 -> V_7 -> V_153 ;
++ V_4 -> V_7 -> V_17 ;
F_73 ( V_4 , V_4 -> V_7 -> V_153 ) ;
V_64 = V_101 ;
break;
}
V_16 = V_154 ;
case V_155 :
if ( ! V_16 )
V_16 = V_156 ;
V_4 -> V_7 -> V_12 = V_157 ;
F_73 ( V_4 , V_8 -> V_158 ) ;
V_64 = V_97 ;
break;
case V_157 :
F_74 ( & V_4 -> V_7 -> V_108 ) ;
F_3 ( V_4 ) ;
break;
default:
break;
}
F_41 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_64 )
F_13 ( V_2 , V_4 , V_64 , V_4 -> V_4 . V_44 ,
V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 , V_16 ) ;
}
static inline void F_75 ( struct V_3 * V_4 , T_2 V_159 )
{
V_4 -> V_7 -> V_108 . V_148 = V_118 + F_76 ( V_159 ) ;
V_4 -> V_7 -> V_108 . V_145 = ( unsigned long ) V_4 ;
V_4 -> V_7 -> V_108 . V_160 = F_70 ;
V_4 -> V_7 -> V_153 = V_159 ;
F_77 ( & V_4 -> V_7 -> V_108 ) ;
}
static bool F_78 ( struct V_1 * V_2 ,
T_3 V_14 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
bool V_161 = false ;
struct V_3 * V_4 ;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 )
continue;
if ( ! memcmp ( & V_4 -> V_7 -> V_14 , & V_14 , sizeof( V_14 ) ) ) {
V_161 = true ;
break;
}
}
F_10 () ;
return V_161 ;
}
static T_3 F_79 ( struct V_1 * V_2 )
{
T_3 V_14 ;
do {
F_72 ( & V_14 , sizeof( V_14 ) ) ;
} while ( F_78 ( V_2 , V_14 ) );
return V_14 ;
}
T_2 F_67 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 ;
if ( ! F_80 ( V_4 , V_162 ) )
return 0 ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_7 -> V_14 = F_79 ( V_2 ) ;
if ( V_4 -> V_7 -> V_12 != V_13 &&
V_4 -> V_7 -> V_12 != V_104 ) {
F_41 ( & V_4 -> V_7 -> V_11 ) ;
return 0 ;
}
V_4 -> V_7 -> V_12 = V_151 ;
F_75 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_163 ) ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
F_11 ( V_2 ,
L_9 ,
V_4 -> V_4 . V_44 ) ;
V_28 = F_81 ( V_2 ) ;
F_13 ( V_2 , V_4 , V_101 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_14 , 0 , 0 ) ;
return V_28 ;
}
T_2 F_82 ( struct V_3 * V_4 )
{
T_2 V_28 ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
V_28 = F_35 ( V_4 ) ;
V_4 -> V_7 -> V_12 = V_104 ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
F_43 ( V_4 ) ;
return V_28 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_164 V_165 )
{
struct V_146 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_16 = ( V_165 == V_166 ) ?
V_167 : V_168 ;
V_4 -> V_7 -> V_16 = V_16 ;
V_4 -> V_7 -> V_12 = V_157 ;
F_73 ( V_4 , V_8 -> V_158 ) ;
}
static T_2 F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_146 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_28 = 0 ;
F_74 ( & V_4 -> V_7 -> V_108 ) ;
V_4 -> V_7 -> V_12 = V_38 ;
V_28 |= F_85 ( V_2 ) ;
V_28 |= F_12 ( V_2 ) ;
V_28 |= F_5 ( V_2 ) ;
F_11 ( V_2 , L_10 , V_4 -> V_4 . V_44 ) ;
F_37 ( V_4 ) ;
V_28 |= F_38 ( V_4 , V_8 -> V_169 ) ;
return V_28 ;
}
static T_2 F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_164 V_165 )
{
struct V_146 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_63 V_64 = 0 ;
T_2 V_28 = 0 ;
bool V_170 = false ;
F_11 ( V_2 , L_11 , V_4 -> V_4 . V_44 ,
V_149 [ V_4 -> V_7 -> V_12 ] , V_171 [ V_165 ] ) ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
switch ( V_4 -> V_7 -> V_12 ) {
case V_13 :
switch ( V_165 ) {
case V_166 :
F_3 ( V_4 ) ;
break;
case V_172 :
V_4 -> V_7 -> V_12 = V_150 ;
V_4 -> V_7 -> V_14 = F_79 ( V_2 ) ;
F_75 ( V_4 ,
V_8 -> V_163 ) ;
V_28 |= F_81 ( V_2 ) ;
V_64 = V_101 ;
break;
default:
break;
}
break;
case V_151 :
switch ( V_165 ) {
case V_173 :
case V_174 :
case V_166 :
F_83 ( V_2 , V_4 , V_165 ) ;
V_64 = V_97 ;
break;
case V_172 :
V_4 -> V_7 -> V_12 = V_150 ;
V_64 = V_98 ;
break;
case V_175 :
V_4 -> V_7 -> V_12 = V_155 ;
F_73 ( V_4 , V_8 -> V_176 ) ;
break;
default:
break;
}
break;
case V_150 :
switch ( V_165 ) {
case V_173 :
case V_174 :
case V_166 :
F_83 ( V_2 , V_4 , V_165 ) ;
V_64 = V_97 ;
break;
case V_172 :
V_64 = V_98 ;
break;
case V_175 :
V_28 |= F_84 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_155 :
switch ( V_165 ) {
case V_173 :
case V_174 :
case V_166 :
F_83 ( V_2 , V_4 , V_165 ) ;
V_64 = V_97 ;
break;
case V_172 :
V_28 |= F_84 ( V_2 , V_4 ) ;
V_64 = V_98 ;
break;
default:
break;
}
break;
case V_38 :
switch ( V_165 ) {
case V_166 :
V_28 |= F_35 ( V_4 ) ;
V_28 |= F_12 ( V_2 ) ;
V_28 |= F_5 ( V_2 ) ;
F_83 ( V_2 , V_4 , V_165 ) ;
V_64 = V_97 ;
V_170 = true ;
break;
case V_172 :
V_64 = V_98 ;
break;
default:
break;
}
break;
case V_157 :
switch ( V_165 ) {
case V_166 :
F_74 ( & V_4 -> V_7 -> V_108 ) ;
F_3 ( V_4 ) ;
break;
case V_172 :
case V_175 :
case V_173 :
case V_174 :
V_64 = V_97 ;
break;
default:
break;
}
break;
default:
break;
}
F_41 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_170 )
F_43 ( V_4 ) ;
if ( V_64 ) {
F_13 ( V_2 , V_4 , V_64 , V_4 -> V_4 . V_44 ,
V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 ,
V_4 -> V_7 -> V_16 ) ;
if ( V_64 == V_101 ) {
F_13 ( V_2 , V_4 ,
V_98 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_14 ,
V_4 -> V_7 -> V_15 , 0 ) ;
}
}
return V_28 ;
}
static enum V_164
F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_109 * V_110 ,
enum V_63 V_177 ,
T_3 V_14 , T_3 V_15 )
{
enum V_164 V_165 = V_178 ;
T_4 V_75 = V_110 -> V_179 ;
bool V_180 ;
V_180 = ( V_177 == V_97 ||
F_88 ( V_2 , V_110 ) ) ;
if ( ! V_180 && ! V_4 ) {
V_165 = V_173 ;
goto V_32;
}
if ( ! V_4 ) {
if ( V_177 != V_101 ) {
F_11 ( V_2 , L_12 ) ;
goto V_32;
}
if ( ! F_89 ( V_2 ) ) {
F_11 ( V_2 , L_13 ) ;
goto V_32;
}
V_165 = V_172 ;
goto V_32;
} else {
if ( ! F_80 ( V_4 , V_162 ) ) {
F_11 ( V_2 , L_14 ) ;
goto V_32;
}
if ( V_4 -> V_7 -> V_12 == V_104 )
goto V_32;
}
switch ( V_177 ) {
case V_101 :
if ( ! V_180 )
V_165 = V_173 ;
if ( ! F_89 ( V_2 ) ||
( V_4 -> V_7 -> V_15 && V_4 -> V_7 -> V_15 != V_15 ) )
V_165 = V_181 ;
else
V_165 = V_172 ;
break;
case V_98 :
if ( ! V_180 )
V_165 = V_174 ;
if ( ! F_89 ( V_2 ) ||
V_4 -> V_7 -> V_14 != V_14 ||
( V_4 -> V_7 -> V_15 && V_4 -> V_7 -> V_15 != V_15 ) )
V_165 = V_182 ;
else
V_165 = V_175 ;
break;
case V_97 :
if ( V_4 -> V_7 -> V_12 == V_38 )
V_165 = V_166 ;
else if ( V_4 -> V_7 -> V_15 != V_15 )
V_165 = V_183 ;
else if ( V_75 == 8 && V_4 -> V_7 -> V_14 != V_14 )
V_165 = V_183 ;
else
V_165 = V_166 ;
break;
default:
F_11 ( V_2 , L_15 ) ;
break;
}
V_32:
return V_165 ;
}
static void
F_90 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 ;
enum V_164 V_165 ;
enum V_63 V_177 ;
T_2 V_28 = 0 ;
T_4 V_75 = V_110 -> V_179 ;
T_3 V_15 , V_14 = 0 ;
if ( ! V_110 -> V_184 ) {
F_11 ( V_2 ,
L_16 ) ;
return;
}
if ( V_110 -> V_185 &&
V_2 -> V_6 . V_7 . V_138 == V_186 ) {
F_11 ( V_2 ,
L_17 ) ;
return;
}
V_177 = V_71 -> V_6 . V_64 . V_6 . V_77 . V_96 ;
if ( ( V_177 == V_101 && V_75 != 4 ) ||
( V_177 == V_98 && V_75 != 6 ) ||
( V_177 == V_97 && V_75 != 6
&& V_75 != 8 ) ) {
F_11 ( V_2 ,
L_18 ,
V_177 , V_75 ) ;
return;
}
if ( V_177 != V_97 &&
( ! V_110 -> V_187 || ! V_110 -> V_146 ) ) {
F_11 ( V_2 , L_19 ) ;
return;
}
V_15 = F_91 ( F_92 ( V_110 -> V_184 ) ) ;
if ( V_177 == V_98 ||
( V_177 == V_97 && V_75 == 8 ) )
V_14 = F_91 ( F_93 ( V_110 -> V_184 ) ) ;
F_8 () ;
V_4 = F_63 ( V_2 , V_71 -> V_92 ) ;
if ( V_177 == V_101 &&
! F_1 ( V_2 , V_4 ) ) {
F_11 ( V_2 , L_20 ,
V_71 -> V_92 ) ;
goto V_188;
}
V_165 = F_87 ( V_2 , V_4 , V_110 , V_177 , V_14 , V_15 ) ;
if ( V_165 == V_172 ) {
F_10 () ;
V_4 = F_62 ( V_2 , V_71 -> V_92 , V_110 ) ;
if ( ! V_4 ) {
F_11 ( V_2 , L_21 ) ;
goto V_188;
}
V_4 -> V_7 -> V_15 = V_15 ;
} else if ( ! V_4 && V_165 == V_173 ) {
F_13 ( V_2 , NULL , V_97 ,
V_71 -> V_92 , 0 , V_15 ,
V_168 ) ;
goto V_188;
} else if ( ! V_4 || V_165 == V_178 ) {
goto V_188;
}
if ( V_165 == V_175 ) {
if ( ! V_4 -> V_7 -> V_15 )
V_4 -> V_7 -> V_15 = V_15 ;
V_4 -> V_7 -> V_99 = F_91 ( F_94 ( V_71 ) ) ;
}
V_28 |= F_86 ( V_2 , V_4 , V_165 ) ;
V_188:
F_10 () ;
if ( V_28 )
F_69 ( V_2 , V_28 ) ;
}
void F_95 ( struct V_1 * V_2 ,
struct V_70 * V_71 , T_6 V_189 ,
struct V_190 * V_191 )
{
struct V_109 V_110 ;
T_6 V_192 ;
T_4 * V_193 ;
if ( V_189 < V_194 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_106 )
return;
if ( F_96 ( V_71 -> V_65 ) ) {
F_11 ( V_2 ,
L_22 ) ;
return;
}
V_193 = V_71 -> V_6 . V_64 . V_6 . V_77 . V_195 ;
V_192 = ( T_4 * ) V_71 -> V_6 . V_64 . V_6 . V_77 . V_195 - ( T_4 * ) V_71 ;
if ( V_71 -> V_6 . V_64 . V_6 . V_77 . V_96 ==
V_98 ) {
V_193 += 4 ;
V_192 += 4 ;
if ( V_192 > V_189 )
return;
}
F_97 ( V_193 , V_189 - V_192 , true , & V_110 ) ;
F_90 ( V_2 , V_71 , & V_110 ) ;
}
