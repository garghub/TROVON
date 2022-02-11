static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 . V_7 . V_8 . V_5 ;
return V_5 == 0 ||
( V_4 && ( V_9 ) - F_2 ( & V_4 -> V_10 ) > V_5 ) ;
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
2 + 8 +
V_2 -> V_6 . V_7 . V_75 ) ;
if ( ! V_67 )
return V_78 ;
V_69 = F_16 ( V_67 ) ;
F_17 ( V_67 , V_19 -> V_80 ) ;
V_71 = (struct V_70 * ) F_18 ( V_67 , V_76 ) ;
memset ( V_71 , 0 , V_76 ) ;
V_71 -> V_86 = F_19 ( V_87 |
V_88 ) ;
memcpy ( V_71 -> V_65 , V_65 , V_89 ) ;
memcpy ( V_71 -> V_90 , V_2 -> V_40 . V_44 , V_89 ) ;
memcpy ( V_71 -> V_91 , V_2 -> V_40 . V_44 , V_89 ) ;
V_71 -> V_6 . V_64 . V_92 = V_93 ;
V_71 -> V_6 . V_64 . V_6 . V_77 . V_94 = V_64 ;
if ( V_64 != V_95 ) {
enum V_20 V_21 = F_6 ( V_2 ) ;
V_74 = F_18 ( V_67 , 2 ) ;
memset ( V_74 , 0 , 2 ) ;
if ( V_64 == V_96 ) {
V_74 = F_18 ( V_67 , 2 ) ;
F_20 ( V_4 -> V_4 . V_97 , V_74 ) ;
}
if ( F_21 ( V_2 , V_67 , true , V_21 ) ||
F_22 ( V_2 , V_67 , true , V_21 ) ||
F_23 ( V_2 , V_67 ) ||
F_24 ( V_2 , V_67 ) ||
F_25 ( V_2 , V_67 ) )
goto free;
} else {
V_69 -> V_36 |= V_98 ;
if ( F_24 ( V_2 , V_67 ) )
goto free;
}
switch ( V_64 ) {
case V_99 :
break;
case V_96 :
V_75 += 2 ;
V_72 = true ;
break;
case V_95 :
if ( V_15 ) {
V_75 += 2 ;
V_72 = true ;
}
V_75 += 2 ;
break;
default:
V_78 = - V_100 ;
goto free;
}
if ( F_26 ( F_27 ( V_67 ) < 2 + V_75 ) )
goto free;
V_74 = F_18 ( V_67 , 2 + V_75 ) ;
* V_74 ++ = V_101 ;
* V_74 ++ = V_75 ;
memcpy ( V_74 , & V_73 , 2 ) ;
V_74 += 2 ;
F_20 ( V_14 , V_74 ) ;
V_74 += 2 ;
if ( V_72 ) {
F_20 ( V_15 , V_74 ) ;
V_74 += 2 ;
}
if ( V_64 == V_95 ) {
F_20 ( V_16 , V_74 ) ;
V_74 += 2 ;
}
if ( V_64 != V_95 ) {
if ( F_28 ( V_2 , V_67 ) ||
F_29 ( V_2 , V_67 ) )
goto free;
}
if ( F_30 ( V_2 , V_67 ) )
goto free;
F_31 ( V_2 , V_67 ) ;
return 0 ;
free:
F_32 ( V_67 ) ;
return V_78 ;
}
static T_2 F_33 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 = 0 ;
F_4 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_4 -> V_7 -> V_12 == V_38 )
V_28 = F_34 ( V_2 ) ;
V_4 -> V_7 -> V_12 = V_102 ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
V_28 |= F_37 ( V_4 ,
V_103 ) ;
return V_28 ;
}
T_2 F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 ;
F_39 ( & V_4 -> V_7 -> V_11 ) ;
V_28 = F_33 ( V_4 ) ;
V_4 -> V_7 -> V_16 = V_104 ;
F_13 ( V_2 , V_4 , V_95 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 ,
V_4 -> V_7 -> V_16 ) ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
return V_28 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_105 * V_106 , bool V_107 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
enum V_20 V_21 = F_6 ( V_2 ) ;
struct V_22 * V_23 ;
T_2 V_108 , V_109 = 0 , V_28 = 0 ;
enum V_110 V_111 = V_4 -> V_4 . V_53 ;
V_23 = V_19 -> V_24 . V_25 -> V_26 [ V_21 ] ;
V_108 = F_42 ( V_2 , V_106 , V_21 , & V_109 ) ;
F_39 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_112 = V_113 ;
if ( V_4 -> V_7 -> V_12 == V_38 &&
V_4 -> V_7 -> V_114 )
goto V_32;
V_4 -> V_7 -> V_114 = true ;
if ( V_4 -> V_4 . V_39 [ V_21 ] != V_108 )
V_28 |= V_115 ;
V_4 -> V_4 . V_39 [ V_21 ] = V_108 ;
if ( F_43 ( V_2 , V_23 ,
V_106 -> V_116 , V_4 ) )
V_28 |= V_117 ;
if ( V_111 != V_4 -> V_4 . V_53 )
V_28 |= V_117 ;
if ( V_106 -> V_118 &&
! ( V_106 -> V_118 -> V_119 &
V_120 ) ) {
if ( V_4 -> V_4 . V_53 != V_54 )
V_28 |= V_117 ;
V_4 -> V_4 . V_53 = V_54 ;
}
if ( V_107 )
F_44 ( V_4 ) ;
else
F_45 ( V_19 , V_23 , V_4 , V_28 ) ;
V_32:
F_40 ( & V_4 -> V_7 -> V_11 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long * V_121 ;
int V_97 ;
V_121 = F_47 ( F_48 ( V_122 + 1 ) ,
sizeof( * V_121 ) , V_123 ) ;
if ( ! V_121 )
return - V_79 ;
F_49 ( 0 , V_121 ) ;
F_8 () ;
F_9 (sta, &sdata->local->sta_list, list)
F_49 ( V_4 -> V_4 . V_97 , V_121 ) ;
F_10 () ;
V_97 = F_50 ( V_121 , V_122 + 1 ) ;
F_51 ( V_121 ) ;
if ( V_97 > V_122 )
return - V_124 ;
return V_97 ;
}
static struct V_3 *
F_52 ( struct V_1 * V_2 , T_4 * V_125 )
{
struct V_3 * V_4 ;
int V_97 ;
if ( V_2 -> V_19 -> V_126 >= V_127 )
return NULL ;
V_97 = F_46 ( V_2 ) ;
if ( V_97 < 0 )
return NULL ;
V_4 = F_53 ( V_2 , V_125 , V_123 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 -> V_12 = V_13 ;
V_4 -> V_4 . V_128 = true ;
V_4 -> V_4 . V_97 = V_97 ;
F_54 ( V_4 , V_129 ) ;
F_54 ( V_4 , V_130 ) ;
F_54 ( V_4 , V_131 ) ;
return V_4 ;
}
static struct V_3 *
F_55 ( struct V_1 * V_2 , T_4 * V_44 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_132 ||
V_2 -> V_6 . V_7 . V_133 & V_134 )
F_56 ( V_2 -> V_135 , V_44 ,
V_106 -> V_136 ,
V_106 -> V_137 ,
V_123 ) ;
else
V_4 = F_52 ( V_2 , V_44 ) ;
return V_4 ;
}
static struct V_3 *
F_57 ( struct V_1 * V_2 ,
T_4 * V_44 , struct V_105 * V_106 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_8 () ;
V_4 = F_58 ( V_2 , V_44 ) ;
if ( V_4 ) {
F_41 ( V_2 , V_4 , V_106 , false ) ;
} else {
F_10 () ;
V_4 = F_55 ( V_2 , V_44 , V_106 ) ;
if ( ! V_4 ) {
F_8 () ;
return NULL ;
}
F_41 ( V_2 , V_4 , V_106 , true ) ;
if ( F_59 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_60 ( struct V_1 * V_2 ,
T_4 * V_125 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 ;
T_2 V_28 = 0 ;
V_4 = F_57 ( V_2 , V_125 , V_106 ) ;
if ( ! V_4 )
goto V_32;
if ( F_61 ( V_106 ) &&
V_4 -> V_7 -> V_12 == V_13 &&
V_2 -> V_6 . V_7 . V_138 &&
V_2 -> V_6 . V_7 . V_8 . V_139 &&
F_1 ( V_2 , V_4 ) )
V_28 = F_62 ( V_4 ) ;
F_63 ( V_4 , V_106 ) ;
V_32:
F_10 () ;
F_64 ( V_2 , V_28 ) ;
}
static void F_65 ( unsigned long V_140 )
{
struct V_3 * V_4 ;
T_3 V_16 = 0 ;
struct V_1 * V_2 ;
struct V_141 * V_8 ;
enum V_63 V_64 = 0 ;
V_4 = (struct V_3 * ) V_140 ;
if ( V_4 -> V_2 -> V_19 -> V_142 )
return;
F_39 ( & V_4 -> V_7 -> V_11 ) ;
if ( F_66 ( V_113 , V_4 -> V_7 -> V_143 . V_144 ) ) {
F_11 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_44 , V_145 [ V_4 -> V_7 -> V_12 ] ) ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
return;
}
if ( V_4 -> V_7 -> V_12 == V_13 ||
V_4 -> V_7 -> V_12 == V_38 ) {
F_11 ( V_4 -> V_2 ,
L_6 ,
V_4 -> V_4 . V_44 , V_145 [ V_4 -> V_7 -> V_12 ] ) ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
return;
}
F_11 ( V_4 -> V_2 ,
L_7 ,
V_4 -> V_4 . V_44 , V_145 [ V_4 -> V_7 -> V_12 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_7 -> V_12 ) {
case V_146 :
case V_147 :
if ( V_4 -> V_7 -> V_17 < V_8 -> V_148 ) {
T_2 rand ;
F_11 ( V_4 -> V_2 ,
L_8 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_17 ,
V_4 -> V_7 -> V_149 ) ;
F_67 ( & rand , sizeof( T_2 ) ) ;
V_4 -> V_7 -> V_149 = V_4 -> V_7 -> V_149 +
rand % V_4 -> V_7 -> V_149 ;
++ V_4 -> V_7 -> V_17 ;
F_68 ( V_4 , V_4 -> V_7 -> V_149 ) ;
V_64 = V_99 ;
break;
}
V_16 = V_150 ;
case V_151 :
if ( ! V_16 )
V_16 = V_152 ;
V_4 -> V_7 -> V_12 = V_153 ;
F_68 ( V_4 , V_8 -> V_154 ) ;
V_64 = V_95 ;
break;
case V_153 :
F_69 ( & V_4 -> V_7 -> V_143 ) ;
F_3 ( V_4 ) ;
break;
default:
break;
}
F_40 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_64 )
F_13 ( V_2 , V_4 , V_64 , V_4 -> V_4 . V_44 ,
V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 , V_16 ) ;
}
static inline void F_70 ( struct V_3 * V_4 , T_2 V_155 )
{
V_4 -> V_7 -> V_143 . V_144 = V_113 + F_71 ( V_155 ) ;
V_4 -> V_7 -> V_143 . V_140 = ( unsigned long ) V_4 ;
V_4 -> V_7 -> V_143 . V_156 = F_65 ;
V_4 -> V_7 -> V_149 = V_155 ;
F_72 ( & V_4 -> V_7 -> V_143 ) ;
}
static bool F_73 ( struct V_1 * V_2 ,
T_3 V_14 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
bool V_157 = false ;
struct V_3 * V_4 ;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( ! memcmp ( & V_4 -> V_7 -> V_14 , & V_14 , sizeof( V_14 ) ) ) {
V_157 = true ;
break;
}
}
F_10 () ;
return V_157 ;
}
static T_3 F_74 ( struct V_1 * V_2 )
{
T_3 V_14 ;
do {
F_67 ( & V_14 , sizeof( V_14 ) ) ;
} while ( F_73 ( V_2 , V_14 ) );
return V_14 ;
}
T_2 F_62 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_28 ;
if ( ! F_75 ( V_4 , V_158 ) )
return 0 ;
F_39 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_7 -> V_14 = F_74 ( V_2 ) ;
if ( V_4 -> V_7 -> V_12 != V_13 &&
V_4 -> V_7 -> V_12 != V_102 ) {
F_40 ( & V_4 -> V_7 -> V_11 ) ;
return 0 ;
}
V_4 -> V_7 -> V_12 = V_147 ;
F_70 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_159 ) ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
F_11 ( V_2 ,
L_9 ,
V_4 -> V_4 . V_44 ) ;
V_28 = F_76 ( V_2 ) ;
F_13 ( V_2 , V_4 , V_99 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_14 , 0 , 0 ) ;
return V_28 ;
}
T_2 F_77 ( struct V_3 * V_4 )
{
T_2 V_28 ;
F_39 ( & V_4 -> V_7 -> V_11 ) ;
V_28 = F_33 ( V_4 ) ;
V_4 -> V_7 -> V_12 = V_102 ;
F_40 ( & V_4 -> V_7 -> V_11 ) ;
return V_28 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_160 V_161 )
{
struct V_141 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_16 = ( V_161 == V_162 ) ?
V_163 : V_164 ;
V_4 -> V_7 -> V_16 = V_16 ;
V_4 -> V_7 -> V_12 = V_153 ;
F_68 ( V_4 , V_8 -> V_154 ) ;
}
static T_2 F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_141 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_28 = 0 ;
F_69 ( & V_4 -> V_7 -> V_143 ) ;
V_4 -> V_7 -> V_12 = V_38 ;
V_28 |= F_80 ( V_2 ) ;
V_28 |= F_12 ( V_2 ) ;
V_28 |= F_5 ( V_2 ) ;
F_11 ( V_2 , L_10 , V_4 -> V_4 . V_44 ) ;
F_36 ( V_4 ) ;
V_28 |= F_37 ( V_4 , V_8 -> V_165 ) ;
return V_28 ;
}
static T_2 F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_160 V_161 )
{
struct V_141 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_63 V_64 = 0 ;
T_2 V_28 = 0 ;
F_11 ( V_2 , L_11 , V_4 -> V_4 . V_44 ,
V_145 [ V_4 -> V_7 -> V_12 ] , V_166 [ V_161 ] ) ;
F_39 ( & V_4 -> V_7 -> V_11 ) ;
switch ( V_4 -> V_7 -> V_12 ) {
case V_13 :
switch ( V_161 ) {
case V_162 :
F_3 ( V_4 ) ;
break;
case V_167 :
V_4 -> V_7 -> V_12 = V_146 ;
V_4 -> V_7 -> V_14 = F_74 ( V_2 ) ;
F_70 ( V_4 ,
V_8 -> V_159 ) ;
V_28 |= F_76 ( V_2 ) ;
V_64 = V_99 ;
break;
default:
break;
}
break;
case V_147 :
switch ( V_161 ) {
case V_168 :
case V_169 :
case V_162 :
F_78 ( V_2 , V_4 , V_161 ) ;
V_64 = V_95 ;
break;
case V_167 :
V_4 -> V_7 -> V_12 = V_146 ;
V_64 = V_96 ;
break;
case V_170 :
V_4 -> V_7 -> V_12 = V_151 ;
F_68 ( V_4 , V_8 -> V_171 ) ;
break;
default:
break;
}
break;
case V_146 :
switch ( V_161 ) {
case V_168 :
case V_169 :
case V_162 :
F_78 ( V_2 , V_4 , V_161 ) ;
V_64 = V_95 ;
break;
case V_167 :
V_64 = V_96 ;
break;
case V_170 :
V_28 |= F_79 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_151 :
switch ( V_161 ) {
case V_168 :
case V_169 :
case V_162 :
F_78 ( V_2 , V_4 , V_161 ) ;
V_64 = V_95 ;
break;
case V_167 :
V_28 |= F_79 ( V_2 , V_4 ) ;
V_64 = V_96 ;
break;
default:
break;
}
break;
case V_38 :
switch ( V_161 ) {
case V_162 :
V_28 |= F_33 ( V_4 ) ;
V_28 |= F_12 ( V_2 ) ;
V_28 |= F_5 ( V_2 ) ;
F_78 ( V_2 , V_4 , V_161 ) ;
V_64 = V_95 ;
break;
case V_167 :
V_64 = V_96 ;
break;
default:
break;
}
break;
case V_153 :
switch ( V_161 ) {
case V_162 :
F_69 ( & V_4 -> V_7 -> V_143 ) ;
F_3 ( V_4 ) ;
break;
case V_167 :
case V_170 :
case V_168 :
case V_169 :
V_64 = V_95 ;
break;
default:
break;
}
break;
default:
break;
}
F_40 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_64 ) {
F_13 ( V_2 , V_4 , V_64 , V_4 -> V_4 . V_44 ,
V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 ,
V_4 -> V_7 -> V_16 ) ;
if ( V_64 == V_99 ) {
F_13 ( V_2 , V_4 ,
V_96 ,
V_4 -> V_4 . V_44 , V_4 -> V_7 -> V_14 ,
V_4 -> V_7 -> V_15 , 0 ) ;
}
}
return V_28 ;
}
static enum V_160
F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_105 * V_106 ,
enum V_63 V_172 ,
T_3 V_14 , T_3 V_15 )
{
enum V_160 V_161 = V_173 ;
T_4 V_75 = V_106 -> V_174 ;
bool V_175 ;
V_175 = ( V_172 == V_95 ||
F_83 ( V_2 , V_106 ) ) ;
if ( ! V_175 && ! V_4 ) {
V_161 = V_168 ;
goto V_32;
}
if ( ! V_4 ) {
if ( V_172 != V_99 ) {
F_11 ( V_2 , L_12 ) ;
goto V_32;
}
if ( ! F_84 ( V_2 ) ) {
F_11 ( V_2 , L_13 ) ;
goto V_32;
}
} else {
if ( ! F_75 ( V_4 , V_158 ) ) {
F_11 ( V_2 , L_14 ) ;
goto V_32;
}
if ( V_4 -> V_7 -> V_12 == V_102 )
goto V_32;
}
if ( ! V_4 ) {
V_161 = V_167 ;
goto V_32;
}
switch ( V_172 ) {
case V_99 :
if ( ! V_175 )
V_161 = V_168 ;
if ( ! F_84 ( V_2 ) ||
( V_4 -> V_7 -> V_15 && V_4 -> V_7 -> V_15 != V_15 ) )
V_161 = V_176 ;
else
V_161 = V_167 ;
break;
case V_96 :
if ( ! V_175 )
V_161 = V_169 ;
if ( ! F_84 ( V_2 ) ||
V_4 -> V_7 -> V_14 != V_14 ||
( V_4 -> V_7 -> V_15 && V_4 -> V_7 -> V_15 != V_15 ) )
V_161 = V_177 ;
else
V_161 = V_170 ;
break;
case V_95 :
if ( V_4 -> V_7 -> V_12 == V_38 )
V_161 = V_162 ;
else if ( V_4 -> V_7 -> V_15 != V_15 )
V_161 = V_178 ;
else if ( V_75 == 8 && V_4 -> V_7 -> V_14 != V_14 )
V_161 = V_178 ;
else
V_161 = V_162 ;
break;
default:
F_11 ( V_2 , L_15 ) ;
break;
}
V_32:
return V_161 ;
}
static void
F_85 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_105 * V_106 )
{
struct V_3 * V_4 ;
enum V_160 V_161 ;
enum V_63 V_172 ;
T_2 V_28 = 0 ;
T_4 V_75 = V_106 -> V_174 ;
T_3 V_15 , V_14 = 0 ;
if ( ! V_106 -> V_179 ) {
F_11 ( V_2 ,
L_16 ) ;
return;
}
if ( V_106 -> V_180 &&
V_2 -> V_6 . V_7 . V_133 == V_181 ) {
F_11 ( V_2 ,
L_17 ) ;
return;
}
V_172 = V_71 -> V_6 . V_64 . V_6 . V_77 . V_94 ;
if ( ( V_172 == V_99 && V_75 != 4 ) ||
( V_172 == V_96 && V_75 != 6 ) ||
( V_172 == V_95 && V_75 != 6
&& V_75 != 8 ) ) {
F_11 ( V_2 ,
L_18 ,
V_172 , V_75 ) ;
return;
}
if ( V_172 != V_95 &&
( ! V_106 -> V_182 || ! V_106 -> V_141 ) ) {
F_11 ( V_2 , L_19 ) ;
return;
}
V_15 = F_86 ( F_87 ( V_106 -> V_179 ) ) ;
if ( V_172 == V_96 ||
( V_172 == V_95 && V_75 == 8 ) )
V_14 = F_86 ( F_88 ( V_106 -> V_179 ) ) ;
F_8 () ;
V_4 = F_58 ( V_2 , V_71 -> V_90 ) ;
if ( V_172 == V_99 &&
! F_1 ( V_2 , V_4 ) ) {
F_11 ( V_2 , L_20 ,
V_71 -> V_90 ) ;
goto V_183;
}
V_161 = F_82 ( V_2 , V_4 , V_106 , V_172 , V_14 , V_15 ) ;
if ( V_161 == V_167 ) {
F_10 () ;
V_4 = F_57 ( V_2 , V_71 -> V_90 , V_106 ) ;
if ( ! V_4 ) {
F_11 ( V_2 , L_21 ) ;
goto V_183;
}
V_4 -> V_7 -> V_15 = V_15 ;
} else if ( ! V_4 && V_161 == V_168 ) {
F_13 ( V_2 , NULL , V_95 ,
V_71 -> V_90 , 0 , V_15 ,
V_164 ) ;
goto V_183;
} else if ( ! V_4 || V_161 == V_173 ) {
goto V_183;
}
if ( V_161 == V_170 ) {
if ( ! V_4 -> V_7 -> V_15 )
V_4 -> V_7 -> V_15 = V_15 ;
V_4 -> V_7 -> V_97 = F_86 ( F_89 ( V_71 ) ) ;
}
V_28 |= F_81 ( V_2 , V_4 , V_161 ) ;
V_183:
F_10 () ;
if ( V_28 )
F_64 ( V_2 , V_28 ) ;
}
void F_90 ( struct V_1 * V_2 ,
struct V_70 * V_71 , T_6 V_184 ,
struct V_185 * V_186 )
{
struct V_105 V_106 ;
T_6 V_187 ;
T_4 * V_188 ;
if ( V_184 < V_189 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_132 )
return;
if ( F_91 ( V_71 -> V_65 ) ) {
F_11 ( V_2 ,
L_22 ) ;
return;
}
V_188 = V_71 -> V_6 . V_64 . V_6 . V_77 . V_190 ;
V_187 = ( T_4 * ) V_71 -> V_6 . V_64 . V_6 . V_77 . V_190 - ( T_4 * ) V_71 ;
if ( V_71 -> V_6 . V_64 . V_6 . V_77 . V_94 ==
V_96 ) {
V_188 += 4 ;
V_187 += 4 ;
if ( V_187 > V_184 )
return;
}
F_92 ( V_188 , V_184 - V_187 , true , & V_106 ) ;
F_85 ( V_2 , V_71 , & V_106 ) ;
}
