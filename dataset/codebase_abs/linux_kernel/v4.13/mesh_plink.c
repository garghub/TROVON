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
struct V_20 * V_21 ;
struct V_3 * V_4 ;
T_2 V_22 = 0 , V_23 = 0 ;
int V_24 ;
bool V_25 = false ;
V_21 = F_6 ( V_2 ) ;
if ( ! V_21 )
return V_23 ;
if ( V_21 -> V_26 == V_27 ) {
V_25 = true ;
goto V_28;
} else if ( V_21 -> V_26 != V_29 ) {
goto V_28;
}
for ( V_24 = 0 ; V_24 < V_21 -> V_30 ; V_24 ++ )
if ( V_21 -> V_31 [ V_24 ] . V_32 & V_33 )
V_22 |= F_7 ( V_24 ) ;
if ( ! V_22 )
goto V_28;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_7 -> V_12 != V_34 )
continue;
V_25 = false ;
if ( V_22 & V_4 -> V_4 . V_35 [ V_21 -> V_26 ] )
V_25 = true ;
else
break;
}
F_10 () ;
V_28:
if ( V_2 -> V_36 . V_37 . V_38 != V_25 ) {
V_2 -> V_36 . V_37 . V_38 = V_25 ;
V_23 = V_39 ;
F_11 ( V_2 , L_1 ,
V_2 -> V_36 . V_40 , V_25 ) ;
}
return V_23 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_3 * V_4 ;
T_3 V_41 ;
bool V_42 = false , V_43 = false ;
switch ( V_2 -> V_36 . V_37 . V_44 . V_45 ) {
case V_46 :
case V_47 :
case V_48 :
return 0 ;
default:
break;
}
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 ||
V_4 -> V_7 -> V_12 != V_34 )
continue;
if ( V_4 -> V_4 . V_49 > V_50 )
continue;
if ( ! V_4 -> V_4 . V_51 . V_52 ) {
F_11 ( V_2 , L_2 ,
V_4 -> V_4 . V_40 ) ;
V_42 = true ;
break;
}
F_11 ( V_2 , L_3 , V_4 -> V_4 . V_40 ) ;
V_43 = true ;
}
F_10 () ;
if ( V_42 )
V_41 = V_53 ;
else if ( V_43 &&
V_2 -> V_36 . V_37 . V_44 . V_45 > V_54 )
V_41 = V_55 ;
else
V_41 = V_56 ;
if ( V_2 -> V_36 . V_37 . V_57 == V_41 )
return 0 ;
V_2 -> V_36 . V_37 . V_57 = V_41 ;
V_2 -> V_6 . V_7 . V_8 . V_41 = V_41 ;
F_11 ( V_2 , L_4 , V_41 ) ;
return V_58 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_59 V_60 ,
T_4 * V_61 , T_3 V_14 , T_3 V_15 , T_3 V_16 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
bool V_68 = false ;
T_3 V_69 = 0 ;
T_4 * V_70 , V_71 = 4 ;
int V_72 = F_14 ( struct V_66 , V_6 . V_60 . V_6 . V_73 ) +
sizeof( V_67 -> V_6 . V_60 . V_6 . V_73 ) ;
int V_74 = - V_75 ;
V_63 = F_15 ( V_19 -> V_76 +
V_72 +
2 +
2 +
2 + 8 +
2 + ( V_77 - 8 ) +
2 + V_2 -> V_6 . V_7 . V_78 +
2 + sizeof( struct V_79 ) +
2 + sizeof( struct V_80 ) +
2 + sizeof( struct V_81 ) +
2 + sizeof( struct V_82 ) +
2 + sizeof( struct V_83 ) +
2 + 8 +
V_2 -> V_6 . V_7 . V_71 ) ;
if ( ! V_63 )
return V_74 ;
V_65 = F_16 ( V_63 ) ;
F_17 ( V_63 , V_19 -> V_76 ) ;
V_67 = F_18 ( V_63 , V_72 ) ;
V_67 -> V_84 = F_19 ( V_85 |
V_86 ) ;
memcpy ( V_67 -> V_61 , V_61 , V_87 ) ;
memcpy ( V_67 -> V_88 , V_2 -> V_36 . V_40 , V_87 ) ;
memcpy ( V_67 -> V_89 , V_2 -> V_36 . V_40 , V_87 ) ;
V_67 -> V_6 . V_60 . V_90 = V_91 ;
V_67 -> V_6 . V_60 . V_6 . V_73 . V_92 = V_60 ;
if ( V_60 != V_93 ) {
struct V_20 * V_21 ;
enum V_94 V_26 ;
V_21 = F_6 ( V_2 ) ;
if ( ! V_21 ) {
V_74 = - V_95 ;
goto free;
}
V_26 = V_21 -> V_26 ;
V_70 = F_18 ( V_63 , 2 ) ;
if ( V_60 == V_96 ) {
V_70 = F_20 ( V_63 , 2 ) ;
F_21 ( V_4 -> V_4 . V_97 , V_70 ) ;
}
if ( F_22 ( V_2 , V_63 , true , V_26 ) ||
F_23 ( V_2 , V_63 , true , V_26 ) ||
F_24 ( V_2 , V_63 ) ||
F_25 ( V_2 , V_63 ) ||
F_26 ( V_2 , V_63 ) )
goto free;
} else {
V_65 -> V_32 |= V_98 ;
if ( F_25 ( V_2 , V_63 ) )
goto free;
}
switch ( V_60 ) {
case V_99 :
break;
case V_96 :
V_71 += 2 ;
V_68 = true ;
break;
case V_93 :
if ( V_15 ) {
V_71 += 2 ;
V_68 = true ;
}
V_71 += 2 ;
break;
default:
V_74 = - V_95 ;
goto free;
}
if ( F_27 ( F_28 ( V_63 ) < 2 + V_71 ) )
goto free;
V_70 = F_20 ( V_63 , 2 + V_71 ) ;
* V_70 ++ = V_100 ;
* V_70 ++ = V_71 ;
memcpy ( V_70 , & V_69 , 2 ) ;
V_70 += 2 ;
F_21 ( V_14 , V_70 ) ;
V_70 += 2 ;
if ( V_68 ) {
F_21 ( V_15 , V_70 ) ;
V_70 += 2 ;
}
if ( V_60 == V_93 ) {
F_21 ( V_16 , V_70 ) ;
V_70 += 2 ;
}
if ( V_60 != V_93 ) {
if ( F_29 ( V_2 , V_63 ) ||
F_30 ( V_2 , V_63 ) ||
F_31 ( V_2 , V_63 ) ||
F_32 ( V_2 , V_63 ) )
goto free;
}
if ( F_33 ( V_2 , V_63 ) )
goto free;
F_34 ( V_2 , V_63 ) ;
return 0 ;
free:
F_35 ( V_63 ) ;
return V_74 ;
}
static T_2 F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_23 = 0 ;
F_4 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_4 -> V_7 -> V_12 == V_34 )
V_23 = F_37 ( V_2 ) ;
V_4 -> V_7 -> V_12 = V_101 ;
F_38 ( V_4 ) ;
V_23 |= F_39 ( V_4 ,
V_102 ) ;
return V_23 ;
}
T_2 F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_23 ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
V_23 = F_36 ( V_4 ) ;
if ( ! V_2 -> V_6 . V_7 . V_103 ) {
V_4 -> V_7 -> V_16 = V_104 ;
F_13 ( V_2 , V_4 , V_93 ,
V_4 -> V_4 . V_40 , V_4 -> V_7 -> V_14 ,
V_4 -> V_7 -> V_15 , V_4 -> V_7 -> V_16 ) ;
}
F_42 ( & V_4 -> V_7 -> V_11 ) ;
if ( ! V_2 -> V_6 . V_7 . V_103 )
F_43 ( & V_4 -> V_7 -> V_105 ) ;
F_44 ( V_4 ) ;
F_45 () ;
return V_23 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_106 * V_107 , bool V_108 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_20 * V_21 ;
T_2 V_109 , V_110 = 0 , V_23 = 0 ;
enum V_111 V_112 = V_4 -> V_4 . V_49 ;
V_21 = F_6 ( V_2 ) ;
if ( ! V_21 )
return;
V_109 = F_47 ( V_2 , V_107 , V_21 -> V_26 ,
& V_110 ) ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_113 . V_114 = V_115 ;
if ( V_4 -> V_7 -> V_12 == V_34 &&
V_4 -> V_7 -> V_116 )
goto V_28;
V_4 -> V_7 -> V_116 = true ;
if ( V_4 -> V_4 . V_35 [ V_21 -> V_26 ] != V_109 )
V_23 |= V_117 ;
V_4 -> V_4 . V_35 [ V_21 -> V_26 ] = V_109 ;
if ( F_48 ( V_2 , V_21 ,
V_107 -> V_118 , V_4 ) )
V_23 |= V_119 ;
F_49 ( V_2 , V_21 ,
V_107 -> V_120 , V_4 ) ;
if ( V_112 != V_4 -> V_4 . V_49 )
V_23 |= V_119 ;
if ( V_107 -> V_121 &&
! ( V_107 -> V_121 -> V_122 &
V_123 ) ) {
if ( V_4 -> V_4 . V_49 != V_50 )
V_23 |= V_119 ;
V_4 -> V_4 . V_49 = V_50 ;
}
if ( V_108 )
F_50 ( V_4 ) ;
else
F_51 ( V_19 , V_21 , V_4 , V_23 ) ;
V_28:
F_42 ( & V_4 -> V_7 -> V_11 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long * V_124 ;
int V_97 ;
V_124 = F_53 ( F_54 ( V_125 + 1 ) ,
sizeof( * V_124 ) , V_126 ) ;
if ( ! V_124 )
return - V_75 ;
F_55 ( 0 , V_124 ) ;
F_8 () ;
F_9 (sta, &sdata->local->sta_list, list)
F_55 ( V_4 -> V_4 . V_97 , V_124 ) ;
F_10 () ;
V_97 = F_56 ( V_124 , V_125 + 1 ) ;
F_57 ( V_124 ) ;
if ( V_97 > V_125 )
return - V_127 ;
return V_97 ;
}
static struct V_3 *
F_58 ( struct V_1 * V_2 , T_4 * V_128 )
{
struct V_3 * V_4 ;
int V_97 ;
if ( V_2 -> V_19 -> V_129 >= V_130 )
return NULL ;
V_97 = F_52 ( V_2 ) ;
if ( V_97 < 0 )
return NULL ;
V_4 = F_59 ( V_2 , V_128 , V_126 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 -> V_12 = V_13 ;
V_4 -> V_4 . V_131 = true ;
V_4 -> V_4 . V_97 = V_97 ;
F_60 ( V_4 , V_132 ) ;
F_60 ( V_4 , V_133 ) ;
F_60 ( V_4 , V_134 ) ;
return V_4 ;
}
static struct V_3 *
F_61 ( struct V_1 * V_2 , T_4 * V_40 ,
struct V_106 * V_107 )
{
struct V_3 * V_4 = NULL ;
if ( V_2 -> V_6 . V_7 . V_103 ||
V_2 -> V_6 . V_7 . V_135 & V_136 ) {
if ( F_62 ( V_107 ) &&
F_63 ( V_2 ) )
F_64 ( V_2 -> V_137 , V_40 ,
V_107 -> V_138 ,
V_107 -> V_139 ,
V_126 ) ;
} else
V_4 = F_58 ( V_2 , V_40 ) ;
return V_4 ;
}
static struct V_3 *
F_65 ( struct V_1 * V_2 ,
T_4 * V_40 , struct V_106 * V_107 ) __acquires( T_5 )
{
struct V_3 * V_4 = NULL ;
F_8 () ;
V_4 = F_66 ( V_2 , V_40 ) ;
if ( V_4 ) {
F_46 ( V_2 , V_4 , V_107 , false ) ;
} else {
F_10 () ;
V_4 = F_61 ( V_2 , V_40 , V_107 ) ;
if ( ! V_4 ) {
F_8 () ;
return NULL ;
}
F_46 ( V_2 , V_4 , V_107 , true ) ;
if ( F_67 ( V_4 ) )
return NULL ;
}
return V_4 ;
}
void F_68 ( struct V_1 * V_2 ,
T_4 * V_128 ,
struct V_106 * V_107 )
{
struct V_3 * V_4 ;
T_2 V_23 = 0 ;
V_4 = F_65 ( V_2 , V_128 , V_107 ) ;
if ( ! V_4 )
goto V_28;
if ( F_62 ( V_107 ) &&
V_4 -> V_7 -> V_12 == V_13 &&
V_2 -> V_6 . V_7 . V_140 &&
V_2 -> V_6 . V_7 . V_8 . V_141 &&
F_1 ( V_2 , V_4 ) )
V_23 = F_69 ( V_4 ) ;
F_70 ( V_4 , V_107 ) ;
V_28:
F_10 () ;
F_71 ( V_2 , V_23 ) ;
}
static void F_72 ( unsigned long V_142 )
{
struct V_3 * V_4 ;
T_3 V_16 = 0 ;
struct V_1 * V_2 ;
struct V_143 * V_8 ;
enum V_59 V_60 = 0 ;
V_4 = (struct V_3 * ) V_142 ;
if ( V_4 -> V_2 -> V_19 -> V_144 )
return;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
if ( F_73 ( V_115 , V_4 -> V_7 -> V_105 . V_145 ) ) {
F_11 ( V_4 -> V_2 ,
L_5 ,
V_4 -> V_4 . V_40 , V_146 [ V_4 -> V_7 -> V_12 ] ) ;
F_42 ( & V_4 -> V_7 -> V_11 ) ;
return;
}
if ( V_4 -> V_7 -> V_12 == V_13 ||
V_4 -> V_7 -> V_12 == V_34 ) {
F_11 ( V_4 -> V_2 ,
L_6 ,
V_4 -> V_4 . V_40 , V_146 [ V_4 -> V_7 -> V_12 ] ) ;
F_42 ( & V_4 -> V_7 -> V_11 ) ;
return;
}
F_11 ( V_4 -> V_2 ,
L_7 ,
V_4 -> V_4 . V_40 , V_146 [ V_4 -> V_7 -> V_12 ] ) ;
V_2 = V_4 -> V_2 ;
V_8 = & V_2 -> V_6 . V_7 . V_8 ;
switch ( V_4 -> V_7 -> V_12 ) {
case V_147 :
case V_148 :
if ( V_4 -> V_7 -> V_17 < V_8 -> V_149 ) {
T_2 rand ;
F_11 ( V_4 -> V_2 ,
L_8 ,
V_4 -> V_4 . V_40 , V_4 -> V_7 -> V_17 ,
V_4 -> V_7 -> V_150 ) ;
F_74 ( & rand , sizeof( T_2 ) ) ;
V_4 -> V_7 -> V_150 = V_4 -> V_7 -> V_150 +
rand % V_4 -> V_7 -> V_150 ;
++ V_4 -> V_7 -> V_17 ;
F_75 ( V_4 , V_4 -> V_7 -> V_150 ) ;
V_60 = V_99 ;
break;
}
V_16 = V_151 ;
case V_152 :
if ( ! V_16 )
V_16 = V_153 ;
V_4 -> V_7 -> V_12 = V_154 ;
F_75 ( V_4 , V_8 -> V_155 ) ;
V_60 = V_93 ;
break;
case V_154 :
F_76 ( & V_4 -> V_7 -> V_105 ) ;
F_3 ( V_4 ) ;
break;
default:
break;
}
F_42 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_60 )
F_13 ( V_2 , V_4 , V_60 , V_4 -> V_4 . V_40 ,
V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 , V_16 ) ;
}
static inline void F_77 ( struct V_3 * V_4 , T_2 V_156 )
{
V_4 -> V_7 -> V_105 . V_145 = V_115 + F_78 ( V_156 ) ;
V_4 -> V_7 -> V_105 . V_142 = ( unsigned long ) V_4 ;
V_4 -> V_7 -> V_105 . V_157 = F_72 ;
V_4 -> V_7 -> V_150 = V_156 ;
F_79 ( & V_4 -> V_7 -> V_105 ) ;
}
static bool F_80 ( struct V_1 * V_2 ,
T_3 V_14 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
bool V_158 = false ;
struct V_3 * V_4 ;
F_8 () ;
F_9 (sta, &local->sta_list, list) {
if ( V_2 != V_4 -> V_2 )
continue;
if ( ! memcmp ( & V_4 -> V_7 -> V_14 , & V_14 , sizeof( V_14 ) ) ) {
V_158 = true ;
break;
}
}
F_10 () ;
return V_158 ;
}
static T_3 F_81 ( struct V_1 * V_2 )
{
T_3 V_14 ;
do {
F_74 ( & V_14 , sizeof( V_14 ) ) ;
} while ( F_80 ( V_2 , V_14 ) );
return V_14 ;
}
T_2 F_69 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 V_23 ;
if ( ! F_82 ( V_4 , V_159 ) )
return 0 ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
V_4 -> V_7 -> V_14 = F_81 ( V_2 ) ;
if ( V_4 -> V_7 -> V_12 != V_13 &&
V_4 -> V_7 -> V_12 != V_101 ) {
F_42 ( & V_4 -> V_7 -> V_11 ) ;
return 0 ;
}
V_4 -> V_7 -> V_12 = V_148 ;
F_77 ( V_4 , V_2 -> V_6 . V_7 . V_8 . V_160 ) ;
F_42 ( & V_4 -> V_7 -> V_11 ) ;
F_11 ( V_2 ,
L_9 ,
V_4 -> V_4 . V_40 ) ;
V_23 = F_83 ( V_2 ) ;
F_13 ( V_2 , V_4 , V_99 ,
V_4 -> V_4 . V_40 , V_4 -> V_7 -> V_14 , 0 , 0 ) ;
return V_23 ;
}
T_2 F_84 ( struct V_3 * V_4 )
{
T_2 V_23 ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
V_23 = F_36 ( V_4 ) ;
V_4 -> V_7 -> V_12 = V_101 ;
F_42 ( & V_4 -> V_7 -> V_11 ) ;
F_44 ( V_4 ) ;
return V_23 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_161 V_162 )
{
struct V_143 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_3 V_16 = ( V_162 == V_163 ) ?
V_164 : V_165 ;
V_4 -> V_7 -> V_16 = V_16 ;
V_4 -> V_7 -> V_12 = V_154 ;
F_75 ( V_4 , V_8 -> V_155 ) ;
}
static T_2 F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_143 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
T_2 V_23 = 0 ;
F_76 ( & V_4 -> V_7 -> V_105 ) ;
V_4 -> V_7 -> V_12 = V_34 ;
V_23 |= F_87 ( V_2 ) ;
V_23 |= F_12 ( V_2 ) ;
V_23 |= F_5 ( V_2 ) ;
F_11 ( V_2 , L_10 , V_4 -> V_4 . V_40 ) ;
F_38 ( V_4 ) ;
V_23 |= F_39 ( V_4 , V_8 -> V_166 ) ;
return V_23 ;
}
static T_2 F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_161 V_162 )
{
struct V_143 * V_8 = & V_2 -> V_6 . V_7 . V_8 ;
enum V_59 V_60 = 0 ;
T_2 V_23 = 0 ;
bool V_167 = false ;
F_11 ( V_2 , L_11 , V_4 -> V_4 . V_40 ,
V_146 [ V_4 -> V_7 -> V_12 ] , V_168 [ V_162 ] ) ;
F_41 ( & V_4 -> V_7 -> V_11 ) ;
switch ( V_4 -> V_7 -> V_12 ) {
case V_13 :
switch ( V_162 ) {
case V_163 :
F_3 ( V_4 ) ;
break;
case V_169 :
V_4 -> V_7 -> V_12 = V_147 ;
V_4 -> V_7 -> V_14 = F_81 ( V_2 ) ;
F_77 ( V_4 ,
V_8 -> V_160 ) ;
V_23 |= F_83 ( V_2 ) ;
V_60 = V_99 ;
break;
default:
break;
}
break;
case V_148 :
switch ( V_162 ) {
case V_170 :
case V_171 :
case V_163 :
F_85 ( V_2 , V_4 , V_162 ) ;
V_60 = V_93 ;
break;
case V_169 :
V_4 -> V_7 -> V_12 = V_147 ;
V_60 = V_96 ;
break;
case V_172 :
V_4 -> V_7 -> V_12 = V_152 ;
F_75 ( V_4 , V_8 -> V_173 ) ;
break;
default:
break;
}
break;
case V_147 :
switch ( V_162 ) {
case V_170 :
case V_171 :
case V_163 :
F_85 ( V_2 , V_4 , V_162 ) ;
V_60 = V_93 ;
break;
case V_169 :
V_60 = V_96 ;
break;
case V_172 :
V_23 |= F_86 ( V_2 , V_4 ) ;
break;
default:
break;
}
break;
case V_152 :
switch ( V_162 ) {
case V_170 :
case V_171 :
case V_163 :
F_85 ( V_2 , V_4 , V_162 ) ;
V_60 = V_93 ;
break;
case V_169 :
V_23 |= F_86 ( V_2 , V_4 ) ;
V_60 = V_96 ;
break;
default:
break;
}
break;
case V_34 :
switch ( V_162 ) {
case V_163 :
V_23 |= F_36 ( V_4 ) ;
V_23 |= F_12 ( V_2 ) ;
V_23 |= F_5 ( V_2 ) ;
F_85 ( V_2 , V_4 , V_162 ) ;
V_60 = V_93 ;
V_167 = true ;
break;
case V_169 :
V_60 = V_96 ;
break;
default:
break;
}
break;
case V_154 :
switch ( V_162 ) {
case V_163 :
F_76 ( & V_4 -> V_7 -> V_105 ) ;
F_3 ( V_4 ) ;
break;
case V_169 :
case V_172 :
case V_170 :
case V_171 :
V_60 = V_93 ;
break;
default:
break;
}
break;
default:
break;
}
F_42 ( & V_4 -> V_7 -> V_11 ) ;
if ( V_167 )
F_44 ( V_4 ) ;
if ( V_60 ) {
F_13 ( V_2 , V_4 , V_60 , V_4 -> V_4 . V_40 ,
V_4 -> V_7 -> V_14 , V_4 -> V_7 -> V_15 ,
V_4 -> V_7 -> V_16 ) ;
if ( V_60 == V_99 ) {
F_13 ( V_2 , V_4 ,
V_96 ,
V_4 -> V_4 . V_40 , V_4 -> V_7 -> V_14 ,
V_4 -> V_7 -> V_15 , 0 ) ;
}
}
return V_23 ;
}
static enum V_161
F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_106 * V_107 ,
enum V_59 V_174 ,
T_3 V_14 , T_3 V_15 )
{
enum V_161 V_162 = V_175 ;
T_4 V_71 = V_107 -> V_176 ;
bool V_177 ;
V_177 = ( V_174 == V_93 ||
F_90 ( V_2 , V_107 ) ) ;
if ( ! V_177 && ! V_4 ) {
V_162 = V_170 ;
goto V_28;
}
if ( ! V_4 ) {
if ( V_174 != V_99 ) {
F_11 ( V_2 , L_12 ) ;
goto V_28;
}
if ( ! F_91 ( V_2 ) ) {
F_11 ( V_2 , L_13 ) ;
goto V_28;
}
V_162 = V_169 ;
goto V_28;
} else {
if ( ! F_82 ( V_4 , V_159 ) ) {
F_11 ( V_2 , L_14 ) ;
goto V_28;
}
if ( V_4 -> V_7 -> V_12 == V_101 )
goto V_28;
}
switch ( V_174 ) {
case V_99 :
if ( ! V_177 )
V_162 = V_170 ;
if ( ! F_91 ( V_2 ) ||
( V_4 -> V_7 -> V_15 && V_4 -> V_7 -> V_15 != V_15 ) )
V_162 = V_178 ;
else
V_162 = V_169 ;
break;
case V_96 :
if ( ! V_177 )
V_162 = V_171 ;
if ( ! F_91 ( V_2 ) ||
V_4 -> V_7 -> V_14 != V_14 ||
( V_4 -> V_7 -> V_15 && V_4 -> V_7 -> V_15 != V_15 ) )
V_162 = V_179 ;
else
V_162 = V_172 ;
break;
case V_93 :
if ( V_4 -> V_7 -> V_12 == V_34 )
V_162 = V_163 ;
else if ( V_4 -> V_7 -> V_15 != V_15 )
V_162 = V_180 ;
else if ( V_71 == 8 && V_4 -> V_7 -> V_14 != V_14 )
V_162 = V_180 ;
else
V_162 = V_163 ;
break;
default:
F_11 ( V_2 , L_15 ) ;
break;
}
V_28:
return V_162 ;
}
static void
F_92 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_106 * V_107 )
{
struct V_3 * V_4 ;
enum V_161 V_162 ;
enum V_59 V_174 ;
T_2 V_23 = 0 ;
T_4 V_71 = V_107 -> V_176 ;
T_3 V_15 , V_14 = 0 ;
if ( ! V_107 -> V_181 ) {
F_11 ( V_2 ,
L_16 ) ;
return;
}
if ( V_107 -> V_182 &&
V_2 -> V_6 . V_7 . V_135 == V_183 ) {
F_11 ( V_2 ,
L_17 ) ;
return;
}
V_174 = V_67 -> V_6 . V_60 . V_6 . V_73 . V_92 ;
if ( ( V_174 == V_99 && V_71 != 4 ) ||
( V_174 == V_96 && V_71 != 6 ) ||
( V_174 == V_93 && V_71 != 6
&& V_71 != 8 ) ) {
F_11 ( V_2 ,
L_18 ,
V_174 , V_71 ) ;
return;
}
if ( V_174 != V_93 &&
( ! V_107 -> V_184 || ! V_107 -> V_143 ) ) {
F_11 ( V_2 , L_19 ) ;
return;
}
V_15 = F_93 ( F_94 ( V_107 -> V_181 ) ) ;
if ( V_174 == V_96 ||
( V_174 == V_93 && V_71 == 8 ) )
V_14 = F_93 ( F_95 ( V_107 -> V_181 ) ) ;
F_8 () ;
V_4 = F_66 ( V_2 , V_67 -> V_88 ) ;
if ( V_174 == V_99 &&
! F_1 ( V_2 , V_4 ) ) {
F_11 ( V_2 , L_20 ,
V_67 -> V_88 ) ;
goto V_185;
}
V_162 = F_89 ( V_2 , V_4 , V_107 , V_174 , V_14 , V_15 ) ;
if ( V_162 == V_169 ) {
F_10 () ;
V_4 = F_65 ( V_2 , V_67 -> V_88 , V_107 ) ;
if ( ! V_4 ) {
F_11 ( V_2 , L_21 ) ;
goto V_185;
}
V_4 -> V_7 -> V_15 = V_15 ;
} else if ( ! V_4 && V_162 == V_170 ) {
F_13 ( V_2 , NULL , V_93 ,
V_67 -> V_88 , 0 , V_15 ,
V_165 ) ;
goto V_185;
} else if ( ! V_4 || V_162 == V_175 ) {
goto V_185;
}
if ( V_162 == V_172 ) {
if ( ! V_4 -> V_7 -> V_15 )
V_4 -> V_7 -> V_15 = V_15 ;
V_4 -> V_7 -> V_97 = F_93 ( F_96 ( V_67 ) ) ;
}
V_23 |= F_88 ( V_2 , V_4 , V_162 ) ;
V_185:
F_10 () ;
if ( V_23 )
F_71 ( V_2 , V_23 ) ;
}
void F_97 ( struct V_1 * V_2 ,
struct V_66 * V_67 , T_6 V_186 ,
struct V_187 * V_188 )
{
struct V_106 V_107 ;
T_6 V_189 ;
T_4 * V_190 ;
if ( V_186 < V_191 + 3 )
return;
if ( V_2 -> V_6 . V_7 . V_103 )
return;
if ( F_98 ( V_67 -> V_61 ) ) {
F_11 ( V_2 ,
L_22 ) ;
return;
}
V_190 = V_67 -> V_6 . V_60 . V_6 . V_73 . V_192 ;
V_189 = ( T_4 * ) V_67 -> V_6 . V_60 . V_6 . V_73 . V_192 - ( T_4 * ) V_67 ;
if ( V_67 -> V_6 . V_60 . V_6 . V_73 . V_92 ==
V_96 ) {
V_190 += 4 ;
V_189 += 4 ;
if ( V_189 > V_186 )
return;
}
F_99 ( V_190 , V_186 - V_189 , true , & V_107 ) ;
F_92 ( V_2 , V_67 , & V_107 ) ;
}
