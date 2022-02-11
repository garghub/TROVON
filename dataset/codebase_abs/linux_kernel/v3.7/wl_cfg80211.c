static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_3 ( V_4 , & V_3 -> V_5 ) ) {
F_4 ( L_1 ,
( int ) V_3 -> V_5 ) ;
return false ;
}
return true ;
}
static T_1 F_5 ( T_2 V_6 )
{
T_3 V_7 = 1 ;
int V_8 = V_6 - V_9 ;
if ( V_8 >= V_10 )
return 0xFFFF ;
while ( V_8 < 0 ) {
V_8 += 40 ;
V_7 *= 10 ;
}
return ( V_11 [ V_8 ] + V_7 / 2 ) / V_7 ;
}
static T_2 F_6 ( T_1 V_12 )
{
T_2 V_6 ;
int V_13 ;
T_3 V_14 = V_12 ;
T_3 V_15 ;
if ( V_14 <= 1 )
return 0 ;
V_13 = V_9 ;
while ( V_14 < V_16 ) {
V_14 *= 10 ;
V_13 -= 40 ;
}
for ( V_6 = 0 ; V_6 < V_10 - 1 ; V_6 ++ ) {
V_15 = V_11 [ V_6 ] + ( V_11 [ V_6 + 1 ] -
V_11 [ V_6 ] ) / 2 ;
if ( V_14 < V_15 )
break;
}
V_6 += ( T_2 ) V_13 ;
return V_6 ;
}
static int
F_7 ( struct V_17 * V_18 , T_4 V_19 , T_4 * V_20 )
{
int V_21 ;
T_5 V_22 = F_8 ( * V_20 ) ;
V_21 = F_9 ( V_18 , V_19 , & V_22 , sizeof( T_5 ) ) ;
* V_20 = F_10 ( V_22 ) ;
return V_21 ;
}
static T_6
F_11 ( struct V_17 * V_18 , T_7 * V_23 ,
void * V_24 , T_6 V_25 ,
void * V_26 , T_6 V_27 , T_6 V_28 )
{
T_6 V_21 = - V_29 ;
T_4 V_30 ;
V_30 = F_12 ( V_23 , V_24 , V_25 ,
V_26 , V_27 , V_28 ) ;
F_13 ( ! V_30 ) ;
if ( V_30 > 0 )
V_21 = F_9 ( V_18 , V_31 , V_26 , V_30 ) ;
if ( V_21 )
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
static T_6
F_15 ( struct V_17 * V_18 , T_7 * V_23 ,
void * V_24 , T_6 V_25 ,
void * V_26 , T_6 V_27 , T_6 V_28 )
{
T_6 V_21 = - V_29 ;
T_4 V_30 ;
V_30 = F_12 ( V_23 , V_24 , V_25 ,
V_26 , V_27 , V_28 ) ;
F_13 ( ! V_30 ) ;
if ( V_30 > 0 )
V_21 = F_9 ( V_18 , V_32 , V_26 , V_30 ) ;
if ( V_21 )
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
static void F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_37 = F_8 ( V_34 -> V_37 ) ;
V_36 -> V_30 = F_8 ( V_34 -> V_30 ) ;
V_36 -> V_38 = F_8 ( V_34 -> V_38 ) ;
V_36 -> V_39 = F_8 ( V_34 -> V_39 ) ;
V_36 -> V_40 . V_41 = F_8 ( V_34 -> V_40 . V_41 ) ;
V_36 -> V_40 . V_42 = F_17 ( V_34 -> V_40 . V_42 ) ;
V_36 -> V_43 = F_8 ( V_34 -> V_43 ) ;
memcpy ( V_36 -> V_44 , V_34 -> V_44 , sizeof( V_34 -> V_44 ) ) ;
memcpy ( V_36 -> V_45 , V_34 -> V_45 , sizeof( V_34 -> V_45 ) ) ;
}
static int
F_18 ( struct V_2 * V_3 , T_6 V_28 ,
struct V_17 * V_18 , struct V_33 * V_34 )
{
int V_21 ;
struct V_35 V_36 ;
F_16 ( V_34 , & V_36 ) ;
V_21 = F_11 ( V_18 , L_3 , & V_36 ,
sizeof( V_36 ) ,
V_3 -> V_46 ,
V_47 , V_28 ) ;
if ( V_21 )
F_14 ( L_4 , V_21 ) ;
return V_21 ;
}
static T_6
F_19 ( struct V_1 * V_1 , struct V_17 * V_18 ,
enum V_48 type , T_4 * V_39 ,
struct V_49 * V_50 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_6 V_51 = 0 ;
T_6 V_52 = 0 ;
T_6 V_21 = 0 ;
F_20 ( L_5 , V_18 , type ) ;
switch ( type ) {
case V_53 :
case V_54 :
F_14 ( L_6 ,
type ) ;
return - V_55 ;
case V_56 :
V_3 -> V_57 -> V_58 = V_59 ;
V_51 = 0 ;
break;
case V_60 :
V_3 -> V_57 -> V_58 = V_61 ;
V_51 = 1 ;
break;
case V_62 :
V_3 -> V_57 -> V_58 = V_63 ;
V_52 = 1 ;
break;
default:
V_21 = - V_64 ;
goto V_65;
}
if ( V_52 ) {
F_21 ( V_66 , & V_3 -> V_5 ) ;
if ( ! V_3 -> V_67 )
V_3 -> V_67 = F_22 ( sizeof( * V_3 -> V_67 ) ,
V_68 ) ;
if ( ! V_3 -> V_67 ) {
V_21 = - V_29 ;
goto V_65;
}
F_4 ( L_7 ) ;
} else {
V_21 = F_7 ( V_18 , V_69 , & V_51 ) ;
if ( V_21 ) {
F_14 ( L_8 , V_21 ) ;
V_21 = - V_70 ;
goto V_65;
}
F_4 ( L_9 ,
( V_3 -> V_57 -> V_58 == V_59 ) ?
L_10 : L_11 ) ;
}
V_18 -> V_71 -> V_72 = type ;
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6 F_23 ( struct V_17 * V_18 , T_7 * V_23 , T_6 V_73 )
{
T_7 V_26 [ V_74 ] ;
T_4 V_30 ;
T_6 V_21 = 0 ;
T_5 V_75 ;
V_75 = F_8 ( V_73 ) ;
V_30 = F_24 ( V_23 , ( char * ) ( & V_75 ) , sizeof( V_75 ) , V_26 ,
sizeof( V_26 ) ) ;
F_13 ( ! V_30 ) ;
V_21 = F_9 ( V_18 , V_31 , V_26 , V_30 ) ;
if ( V_21 )
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
static T_6
F_25 ( struct V_17 * V_18 , T_7 * V_23 , T_6 * V_76 )
{
union {
T_7 V_26 [ V_74 ] ;
T_5 V_73 ;
} V_77 ;
T_4 V_30 ;
T_4 V_78 ;
T_6 V_21 = 0 ;
V_30 =
F_24 ( V_23 , ( char * ) ( & V_78 ) , 0 , ( char * ) ( & V_77 ) ,
sizeof( V_77 . V_26 ) ) ;
F_13 ( ! V_30 ) ;
V_21 = F_9 ( V_18 , V_32 , & V_77 , V_30 ) ;
if ( V_21 )
F_14 ( L_2 , V_21 ) ;
* V_76 = F_10 ( V_77 . V_73 ) ;
return V_21 ;
}
static T_6
F_26 ( struct V_17 * V_18 , T_7 * V_23 , T_4 V_73 ,
T_6 V_28 )
{
T_7 V_26 [ V_74 ] ;
T_5 V_75 ;
V_75 = F_8 ( V_73 ) ;
return F_11 ( V_18 , V_23 , & V_75 ,
sizeof( V_75 ) , V_26 , sizeof( V_26 ) ,
V_28 ) ;
}
static T_6
F_27 ( struct V_17 * V_18 , T_7 * V_23 , T_6 * V_73 ,
T_6 V_28 )
{
T_7 V_26 [ V_74 ] ;
T_6 V_21 ;
T_5 V_75 ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
V_21 = F_15 ( V_18 , V_23 , V_73 , sizeof( * V_73 ) , V_26 ,
sizeof( V_26 ) , V_28 ) ;
if ( V_21 == 0 ) {
memcpy ( & V_75 , V_26 , sizeof( V_75 ) ) ;
* V_73 = F_10 ( V_75 ) ;
}
return V_21 ;
}
static T_6
F_28 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
return 0 ;
}
static void F_29 ( struct V_17 * V_18 , int V_79 )
{
T_6 V_21 = 0 ;
struct V_2 * V_3 = F_30 ( V_18 ) ;
if ( F_3 ( V_4 , & V_3 -> V_5 ) ) {
V_21 = F_23 ( V_18 , L_13 , V_79 ) ;
if ( V_21 ) {
F_14 ( L_14 ) ;
return;
}
F_4 ( L_15 , V_79 ) ;
}
}
static void F_31 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
memcpy ( V_81 -> V_84 , V_85 , V_86 ) ;
V_81 -> V_87 = V_88 ;
V_81 -> V_89 = 0 ;
V_81 -> V_90 = 0 ;
V_81 -> V_91 = F_8 ( - 1 ) ;
V_81 -> V_92 = F_8 ( - 1 ) ;
V_81 -> V_93 = F_8 ( - 1 ) ;
V_81 -> V_94 = F_8 ( - 1 ) ;
if ( V_83 && V_83 -> V_95 ) {
V_81 -> V_96 . V_95 = F_8 ( V_83 -> V_95 ) ;
memcpy ( & V_81 -> V_96 . V_97 , V_83 -> V_97 , V_83 -> V_95 ) ;
}
}
static T_6
F_32 ( struct V_17 * V_18 , T_7 * V_98 , void * V_24 ,
T_6 V_25 , void * V_99 , T_6 V_27 )
{
T_6 V_100 ;
V_100 = F_24 ( V_98 , V_24 , V_25 , V_99 , V_27 ) ;
F_13 ( ! V_100 ) ;
return F_9 ( V_18 , V_31 , V_99 , V_100 ) ;
}
static T_6
F_33 ( struct V_17 * V_18 , T_7 * V_98 , void * V_24 ,
T_6 V_25 , void * V_99 , T_6 V_27 )
{
T_6 V_100 ;
V_100 = F_24 ( V_98 , V_24 , V_25 , V_99 , V_27 ) ;
F_13 ( ! V_100 ) ;
return F_9 ( V_18 , V_32 , V_99 , V_27 ) ;
}
static T_6
F_34 ( struct V_101 * V_102 ,
struct V_82 * V_83 , T_1 V_103 )
{
T_6 V_104 = V_105 +
F_35 ( struct V_106 , V_81 ) ;
struct V_106 * V_50 ;
T_6 V_21 = 0 ;
if ( V_83 && V_83 -> V_95 )
V_104 += sizeof( struct V_82 ) ;
V_50 = F_22 ( V_104 , V_68 ) ;
if ( ! V_50 )
return - V_29 ;
F_13 ( V_104 >= V_74 ) ;
F_31 ( & V_50 -> V_81 , V_83 ) ;
V_50 -> V_107 = F_8 ( V_108 ) ;
V_50 -> V_103 = F_17 ( V_103 ) ;
V_50 -> V_109 = F_17 ( 0 ) ;
V_21 = F_32 ( V_102 -> V_18 , L_16 , V_50 , V_104 ,
V_102 -> V_110 , V_74 ) ;
if ( V_21 ) {
if ( V_21 == - V_111 )
F_4 ( L_17 ) ;
else
F_14 ( L_2 , V_21 ) ;
}
F_36 ( V_50 ) ;
return V_21 ;
}
static T_6 F_37 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = F_38 ( V_3 ) ;
struct V_17 * V_18 = F_39 ( V_3 ) ;
struct V_82 V_83 ;
T_5 V_112 ;
T_6 V_21 = 0 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_102 -> V_113 = V_114 ;
V_112 = V_3 -> V_115 ? 0 : F_8 ( 1 ) ;
V_21 = F_9 ( F_39 ( V_3 ) , V_116 ,
& V_112 , sizeof( V_112 ) ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
F_29 ( V_18 , 0 ) ;
V_3 -> V_117 = true ;
V_21 = F_34 ( V_102 , & V_83 , V_118 ) ;
if ( V_21 ) {
F_29 ( V_18 , 1 ) ;
V_3 -> V_117 = false ;
return V_21 ;
}
F_40 ( & V_102 -> V_119 , V_120 + V_102 -> V_121 * V_122 / 1000 ) ;
V_102 -> V_123 = 1 ;
return V_21 ;
}
static T_6
F_41 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_124 * V_125 ,
struct V_126 * V_127 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_126 * V_128 ;
struct V_129 * V_130 = V_3 -> V_131 ;
T_5 V_112 ;
bool V_132 ;
bool V_133 ;
T_6 V_21 = 0 ;
T_4 V_95 ;
if ( F_3 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_18 , V_3 -> V_5 ) ;
return - V_70 ;
}
if ( F_3 ( V_135 , & V_3 -> V_5 ) ) {
F_14 ( L_19 ,
V_3 -> V_5 ) ;
return - V_70 ;
}
if ( F_3 ( V_136 , & V_3 -> V_5 ) ) {
F_14 ( L_20 ,
V_3 -> V_5 ) ;
return - V_70 ;
}
V_132 = false ;
V_133 = false ;
if ( V_125 ) {
V_128 = V_125 -> V_128 ;
if ( V_3 -> V_137 && ( ! V_128 || ! V_128 -> V_138 ) )
V_132 = true ;
} else {
V_128 = V_127 ;
}
V_3 -> V_139 = V_125 ;
F_21 ( V_134 , & V_3 -> V_5 ) ;
if ( V_132 ) {
V_21 = F_37 ( V_3 ) ;
if ( ! V_21 )
return V_21 ;
else
goto V_140;
} else {
F_42 ( L_21 ,
V_128 -> V_83 , V_128 -> V_138 ) ;
memset ( & V_130 -> V_96 , 0 , sizeof( V_130 -> V_96 ) ) ;
V_95 = F_43 ( T_2 , sizeof( V_130 -> V_96 . V_97 ) , V_128 -> V_138 ) ;
V_130 -> V_96 . V_95 = F_8 ( 0 ) ;
if ( V_95 ) {
memcpy ( V_130 -> V_96 . V_97 , V_128 -> V_83 , V_95 ) ;
V_130 -> V_96 . V_95 = F_8 ( V_95 ) ;
V_133 = true ;
} else {
F_42 ( L_22 ) ;
}
V_112 = V_3 -> V_115 ? 0 : F_8 ( 1 ) ;
V_21 = F_9 ( V_18 , V_116 ,
& V_112 , sizeof( V_112 ) ) ;
if ( V_21 ) {
F_14 ( L_23 , V_21 ) ;
goto V_140;
}
F_29 ( V_18 , 0 ) ;
V_21 = F_9 ( V_18 , V_141 , & V_130 -> V_96 ,
sizeof( V_130 -> V_96 ) ) ;
if ( V_21 ) {
if ( V_21 == - V_111 )
F_4 ( L_24
L_25 , V_130 -> V_96 . V_97 ) ;
else
F_14 ( L_26 , V_21 ) ;
F_29 ( V_18 , 1 ) ;
goto V_140;
}
}
return 0 ;
V_140:
F_44 ( V_134 , & V_3 -> V_5 ) ;
V_3 -> V_139 = NULL ;
return V_21 ;
}
static void F_45 ( struct V_80 * V_81 ,
struct V_124 * V_125 )
{
T_4 V_142 ;
T_4 V_143 ;
T_6 V_144 ;
T_6 V_13 ;
T_1 V_145 ;
T_1 V_146 ;
struct V_147 * V_148 ;
char * V_149 ;
struct V_150 V_96 ;
memcpy ( V_81 -> V_84 , V_85 , V_86 ) ;
V_81 -> V_87 = V_88 ;
V_81 -> V_89 = 0 ;
V_81 -> V_90 = 0 ;
V_81 -> V_91 = F_8 ( - 1 ) ;
V_81 -> V_92 = F_8 ( - 1 ) ;
V_81 -> V_93 = F_8 ( - 1 ) ;
V_81 -> V_94 = F_8 ( - 1 ) ;
memset ( & V_81 -> V_96 , 0 , sizeof( V_81 -> V_96 ) ) ;
if ( ! V_125 )
return;
V_142 = V_125 -> V_142 ;
V_143 = V_125 -> V_143 ;
F_42 ( L_27 , V_143 ) ;
if ( V_143 > 0 ) {
for ( V_144 = 0 ; V_144 < V_143 ; V_144 ++ ) {
V_145 = 0 ;
V_148 = V_125 -> V_151 [ V_144 ] ;
V_146 = F_46 (
V_148 -> V_152 ) ;
if ( V_148 -> V_153 == V_154 )
V_145 |= V_155 ;
else
V_145 |= V_156 ;
if ( V_148 -> V_39 & V_157 ) {
V_145 |= V_158 ;
V_145 |= V_159 ;
} else {
V_145 |= V_160 ;
if ( V_148 -> V_39 &
V_161 )
V_145 |= V_162 ;
else
V_145 |= V_163 ;
}
V_145 |= ( V_146 & V_164 ) ;
F_42 ( L_28 ,
V_146 , V_145 ) ;
V_81 -> V_165 [ V_144 ] = F_17 ( V_145 ) ;
}
} else {
F_42 ( L_29 ) ;
}
F_42 ( L_30 , V_142 ) ;
if ( V_142 > 0 ) {
V_13 = F_35 ( struct V_80 , V_165 ) +
V_143 * sizeof( T_1 ) ;
V_13 = F_47 ( V_13 , sizeof( T_4 ) ) ;
V_149 = ( char * ) V_81 + V_13 ;
for ( V_144 = 0 ; V_144 < V_142 ; V_144 ++ ) {
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_95 =
F_8 ( V_125 -> V_128 [ V_144 ] . V_138 ) ;
memcpy ( V_96 . V_97 , V_125 -> V_128 [ V_144 ] . V_83 ,
V_125 -> V_128 [ V_144 ] . V_138 ) ;
if ( ! V_96 . V_95 )
F_42 ( L_31 , V_144 ) ;
else
F_42 ( L_32 , V_144 ,
V_96 . V_97 , V_96 . V_95 ) ;
memcpy ( V_149 , & V_96 , sizeof( V_96 ) ) ;
V_149 += sizeof( V_96 ) ;
}
} else {
F_42 ( L_33 , V_125 -> V_128 ) ;
if ( ( V_125 -> V_128 ) && V_125 -> V_128 -> V_138 ) {
F_42 ( L_34 , V_81 -> V_96 . V_97 ,
V_125 -> V_128 -> V_138 ) ;
V_81 -> V_96 . V_95 =
F_8 ( V_125 -> V_128 -> V_138 ) ;
memcpy ( & V_81 -> V_96 . V_97 , V_125 -> V_128 -> V_83 ,
V_125 -> V_128 -> V_138 ) ;
}
}
V_81 -> V_90 =
F_8 ( ( V_142 << V_166 ) |
( V_143 & V_167 ) ) ;
}
static T_6
F_48 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
bool V_168 , bool V_169 )
{
struct V_80 V_81 ;
struct V_124 * V_139 ;
T_6 V_21 = 0 ;
F_42 ( L_35 ) ;
V_139 = V_3 -> V_139 ;
V_3 -> V_139 = NULL ;
if ( F_49 ( & V_3 -> V_170 ) )
F_50 ( & V_3 -> V_170 ) ;
if ( V_169 ) {
F_42 ( L_36 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
memcpy ( V_81 . V_84 , V_85 , V_86 ) ;
V_81 . V_87 = V_88 ;
V_81 . V_89 = 0 ;
V_81 . V_90 = F_8 ( 1 ) ;
V_81 . V_91 = F_8 ( 1 ) ;
V_81 . V_92 = F_8 ( - 1 ) ;
V_81 . V_93 = F_8 ( - 1 ) ;
V_81 . V_94 = F_8 ( - 1 ) ;
V_81 . V_165 [ 0 ] = F_17 ( - 1 ) ;
V_21 = F_9 ( V_18 , V_141 , & V_81 ,
sizeof( V_81 ) ) ;
if ( V_21 )
F_14 ( L_37 ) ;
}
if ( V_3 -> V_171 ) {
F_42 ( L_38 ) ;
V_3 -> V_171 = false ;
if ( ! V_168 )
F_51 ( F_52 ( V_3 ) ) ;
F_29 ( V_18 , 1 ) ;
} else if ( V_139 ) {
F_42 ( L_39 ,
V_168 ? L_40 : L_41 ) ;
F_53 ( V_139 , V_168 ) ;
F_29 ( V_18 , 1 ) ;
}
if ( ! F_54 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_42 ) ;
return - V_172 ;
}
return V_21 ;
}
static T_6
F_55 ( struct V_2 * V_3 , struct V_17 * V_18 ,
struct V_124 * V_125 , T_1 V_103 )
{
T_6 V_104 = V_105 +
F_35 ( struct V_173 , V_81 ) ;
struct V_173 * V_50 ;
T_6 V_21 = 0 ;
F_42 ( L_43 ) ;
if ( V_125 != NULL ) {
V_104 += sizeof( T_4 ) * ( ( V_125 -> V_143 + 1 ) / 2 ) ;
V_104 += sizeof( struct V_82 ) * V_125 -> V_142 ;
}
V_50 = F_22 ( V_104 , V_68 ) ;
if ( ! V_50 ) {
V_21 = - V_29 ;
goto exit;
}
F_13 ( V_104 + sizeof( L_44 ) >= V_174 ) ;
F_45 ( & V_50 -> V_81 , V_125 ) ;
V_50 -> V_107 = F_8 ( V_175 ) ;
V_50 -> V_103 = F_17 ( V_103 ) ;
V_50 -> V_176 = F_17 ( 0x1234 ) ;
V_21 = F_32 ( V_18 , L_44 , V_50 , V_104 ,
V_3 -> V_177 , V_174 ) ;
if ( V_21 ) {
if ( V_21 == - V_111 )
F_4 ( L_45 ) ;
else
F_14 ( L_2 , V_21 ) ;
}
F_36 ( V_50 ) ;
exit:
return V_21 ;
}
static T_6
F_56 ( struct V_2 * V_3 , struct V_1 * V_1 ,
struct V_17 * V_18 , struct V_124 * V_125 )
{
T_6 V_21 ;
T_5 V_112 ;
struct V_178 * V_179 ;
F_42 ( L_35 ) ;
V_3 -> V_180 . V_18 = V_18 ;
V_3 -> V_180 . V_1 = V_1 ;
V_3 -> V_180 . V_181 = V_182 ;
V_112 = V_3 -> V_115 ? 0 : F_8 ( 1 ) ;
V_21 = F_9 ( V_18 , V_116 ,
& V_112 , sizeof( V_112 ) ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
F_29 ( V_18 , 0 ) ;
V_179 = (struct V_178 * ) V_3 -> V_180 . V_183 ;
V_179 -> V_107 = 0 ;
V_179 -> V_184 = 0 ;
V_179 -> V_27 = V_185 ;
V_21 = F_55 ( V_3 , V_18 , V_125 , V_186 ) ;
if ( V_21 )
F_29 ( V_18 , 1 ) ;
return V_21 ;
}
static T_6
F_57 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_124 * V_125 ,
struct V_126 * V_127 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_126 * V_128 ;
struct V_129 * V_130 = V_3 -> V_131 ;
T_5 V_112 ;
bool V_187 ;
bool V_133 ;
T_6 V_21 ;
T_4 V_95 ;
F_42 ( L_46 ) ;
if ( F_3 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_18 , V_3 -> V_5 ) ;
return - V_70 ;
}
if ( F_3 ( V_135 , & V_3 -> V_5 ) ) {
F_14 ( L_19 ,
V_3 -> V_5 ) ;
return - V_70 ;
}
if ( F_3 ( V_136 , & V_3 -> V_5 ) ) {
F_14 ( L_20 ,
V_3 -> V_5 ) ;
return - V_70 ;
}
F_40 ( & V_3 -> V_170 , V_120 +
V_188 * V_122 / 1000 ) ;
V_187 = false ;
if ( V_125 ) {
V_128 = V_125 -> V_128 ;
V_187 = true ;
} else {
V_128 = V_127 ;
}
V_3 -> V_139 = V_125 ;
F_21 ( V_134 , & V_3 -> V_5 ) ;
if ( V_187 ) {
V_21 = F_56 ( V_3 , V_1 , V_18 , V_125 ) ;
if ( ! V_21 )
return V_21 ;
else
goto V_140;
} else {
F_42 ( L_21 ,
V_128 -> V_83 , V_128 -> V_138 ) ;
memset ( & V_130 -> V_96 , 0 , sizeof( V_130 -> V_96 ) ) ;
V_95 = F_43 ( T_2 , sizeof( V_130 -> V_96 . V_97 ) , V_128 -> V_138 ) ;
V_130 -> V_96 . V_95 = F_8 ( 0 ) ;
V_133 = false ;
if ( V_95 ) {
memcpy ( V_130 -> V_96 . V_97 , V_128 -> V_83 , V_95 ) ;
V_130 -> V_96 . V_95 = F_8 ( V_95 ) ;
V_133 = true ;
} else
F_42 ( L_22 ) ;
V_112 = V_3 -> V_115 ? 0 : F_8 ( 1 ) ;
V_21 = F_9 ( V_18 , V_116 ,
& V_112 , sizeof( V_112 ) ) ;
if ( V_21 ) {
F_14 ( L_23 , V_21 ) ;
goto V_140;
}
F_29 ( V_18 , 0 ) ;
V_21 = F_9 ( V_18 , V_141 , & V_130 -> V_96 ,
sizeof( V_130 -> V_96 ) ) ;
if ( V_21 ) {
if ( V_21 == - V_111 )
F_4 ( L_47 ,
V_130 -> V_96 . V_97 ) ;
else
F_14 ( L_26 , V_21 ) ;
F_29 ( V_18 , 1 ) ;
goto V_140;
}
}
return 0 ;
V_140:
F_44 ( V_134 , & V_3 -> V_5 ) ;
if ( F_49 ( & V_3 -> V_170 ) )
F_50 ( & V_3 -> V_170 ) ;
V_3 -> V_139 = NULL ;
return V_21 ;
}
static T_6
F_58 ( struct V_1 * V_1 ,
struct V_124 * V_125 )
{
struct V_17 * V_18 = V_125 -> V_189 -> V_190 ;
struct V_2 * V_3 = F_30 ( V_18 ) ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
if ( V_3 -> V_137 )
V_21 = F_41 ( V_1 , V_18 , V_125 , NULL ) ;
else if ( V_3 -> V_192 )
V_21 = F_57 ( V_1 , V_18 , V_125 , NULL ) ;
if ( V_21 )
F_14 ( L_48 , V_21 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6 F_59 ( struct V_17 * V_18 , T_4 V_193 )
{
T_6 V_21 = 0 ;
V_21 = F_23 ( V_18 , L_49 , V_193 ) ;
if ( V_21 )
F_14 ( L_50 , V_21 ) ;
return V_21 ;
}
static T_6 F_60 ( struct V_17 * V_18 , T_4 V_194 )
{
T_6 V_21 = 0 ;
V_21 = F_23 ( V_18 , L_51 , V_194 ) ;
if ( V_21 )
F_14 ( L_50 , V_21 ) ;
return V_21 ;
}
static T_6 F_61 ( struct V_17 * V_18 , T_4 V_195 , bool V_196 )
{
T_6 V_21 = 0 ;
T_4 V_19 = ( V_196 ? V_197 : V_198 ) ;
V_21 = F_7 ( V_18 , V_19 , & V_195 ) ;
if ( V_21 ) {
F_14 ( L_52 , V_19 , V_21 ) ;
return V_21 ;
}
return V_21 ;
}
static T_6 F_62 ( struct V_1 * V_1 , T_4 V_199 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_17 * V_18 = F_39 ( V_3 ) ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
if ( V_199 & V_200 &&
( V_3 -> V_57 -> V_193 != V_1 -> V_193 ) ) {
V_3 -> V_57 -> V_193 = V_1 -> V_193 ;
V_21 = F_59 ( V_18 , V_3 -> V_57 -> V_193 ) ;
if ( ! V_21 )
goto V_65;
}
if ( V_199 & V_201 &&
( V_3 -> V_57 -> V_194 != V_1 -> V_194 ) ) {
V_3 -> V_57 -> V_194 = V_1 -> V_194 ;
V_21 = F_60 ( V_18 , V_3 -> V_57 -> V_194 ) ;
if ( ! V_21 )
goto V_65;
}
if ( V_199 & V_202
&& ( V_3 -> V_57 -> V_203 != V_1 -> V_203 ) ) {
V_3 -> V_57 -> V_203 = V_1 -> V_203 ;
V_21 = F_61 ( V_18 , V_3 -> V_57 -> V_203 , true ) ;
if ( ! V_21 )
goto V_65;
}
if ( V_199 & V_204
&& ( V_3 -> V_57 -> V_205 != V_1 -> V_205 ) ) {
V_3 -> V_57 -> V_205 = V_1 -> V_205 ;
V_21 = F_61 ( V_18 , V_3 -> V_57 -> V_205 , false ) ;
if ( ! V_21 )
goto V_65;
}
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static void F_63 ( struct V_206 * V_207 )
{
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
}
static void F_64 ( int V_208 , struct V_209 * V_210 ,
T_8 * V_211 )
{
T_1 V_145 = 0 ;
if ( V_208 != 0 ) {
if ( V_208 <= V_212 )
V_145 |= V_155 ;
else
V_145 |= V_156 ;
V_145 |= V_158 ;
V_145 |= V_159 ;
* V_211 += V_213 +
sizeof( T_1 ) ;
V_145 |= ( V_208 & V_164 ) ;
V_210 -> V_81 . V_214 [ 0 ] = F_17 ( V_145 ) ;
V_210 -> V_81 . V_215 = F_8 ( 1 ) ;
F_65 ( L_53
L_54 ,
V_145 , V_208 , V_145 ) ;
}
}
static void F_66 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = NULL ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( V_3 -> V_216 ) {
V_18 = F_39 ( V_3 ) ;
F_4 ( L_55 ) ;
V_21 = F_9 ( V_18 , V_217 , NULL , 0 ) ;
if ( V_21 )
F_14 ( L_56 , V_21 ) ;
V_3 -> V_216 = false ;
}
F_20 ( L_12 ) ;
}
static T_6
F_67 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_218 * V_50 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_209 V_210 ;
T_8 V_211 = 0 ;
T_6 V_21 = 0 ;
T_6 V_220 = 0 ;
T_6 V_221 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
if ( V_50 -> V_83 )
F_65 ( L_57 , V_50 -> V_83 ) ;
else {
F_65 ( L_58 ) ;
return - V_55 ;
}
F_21 ( V_136 , & V_3 -> V_5 ) ;
if ( V_50 -> V_84 )
F_65 ( L_59 , V_50 -> V_84 ) ;
else
F_65 ( L_60 ) ;
if ( V_50 -> V_146 )
F_65 ( L_61 , V_50 -> V_146 -> V_152 ) ;
else
F_65 ( L_62 ) ;
if ( V_50 -> V_222 )
F_65 ( L_63 ) ;
else
F_65 ( L_64 ) ;
if ( V_50 -> V_223 && V_50 -> V_224 )
F_65 ( L_65 , V_50 -> V_224 ) ;
else
F_65 ( L_66 ) ;
if ( V_50 -> V_225 )
F_65 ( L_67 , V_50 -> V_225 ) ;
else
F_65 ( L_68 ) ;
if ( V_50 -> V_226 )
F_65 ( L_69 , V_50 -> V_226 ) ;
else
F_65 ( L_70 ) ;
if ( V_50 -> V_227 )
F_65 ( L_71 ) ;
else
F_65 ( L_72 ) ;
if ( V_50 -> V_227 )
V_220 |= V_228 ;
V_21 = F_23 ( V_18 , L_73 , V_220 ) ;
if ( V_21 ) {
F_14 ( L_74 , V_21 ) ;
goto V_65;
}
if ( V_50 -> V_225 )
V_221 = V_50 -> V_225 ;
else
V_221 = 100 ;
V_21 = F_7 ( V_18 , V_229 , & V_221 ) ;
if ( V_21 ) {
F_14 ( L_75 , V_21 ) ;
goto V_65;
}
memset ( & V_210 , 0 , sizeof( struct V_209 ) ) ;
V_219 -> V_83 . V_95 = F_43 ( T_4 , V_50 -> V_138 , 32 ) ;
memcpy ( V_219 -> V_83 . V_97 , V_50 -> V_83 , V_219 -> V_83 . V_95 ) ;
memcpy ( V_210 . V_96 . V_97 , V_50 -> V_83 , V_219 -> V_83 . V_95 ) ;
V_210 . V_96 . V_95 = F_8 ( V_219 -> V_83 . V_95 ) ;
V_211 = sizeof( V_210 . V_96 ) ;
if ( V_50 -> V_84 ) {
memcpy ( V_210 . V_81 . V_84 , V_50 -> V_84 , V_86 ) ;
V_211 = sizeof( V_210 . V_96 ) +
V_213 ;
memcpy ( V_219 -> V_84 , V_50 -> V_84 , V_86 ) ;
} else {
memcpy ( V_210 . V_81 . V_84 , V_85 , V_86 ) ;
memset ( V_219 -> V_84 , 0 , V_86 ) ;
}
if ( V_50 -> V_146 ) {
T_4 V_230 ;
V_3 -> V_146 =
F_46 (
V_50 -> V_146 -> V_152 ) ;
if ( V_50 -> V_222 ) {
F_64 ( V_3 -> V_146 ,
& V_210 , & V_211 ) ;
}
V_230 = V_3 -> V_146 ;
V_21 = F_7 ( V_18 , V_231 ,
& V_230 ) ;
if ( V_21 ) {
F_14 ( L_76 , V_21 ) ;
goto V_65;
}
} else
V_3 -> V_146 = 0 ;
V_3 -> V_232 = false ;
V_21 = F_9 ( V_18 , V_233 ,
& V_210 , V_211 ) ;
if ( V_21 ) {
F_14 ( L_77 , V_21 ) ;
goto V_65;
}
V_65:
if ( V_21 )
F_44 ( V_136 , & V_3 -> V_5 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_68 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
F_66 ( V_3 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6 F_69 ( struct V_17 * V_18 ,
struct V_234 * V_235 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_236 * V_237 ;
T_6 V_73 = 0 ;
T_6 V_21 = 0 ;
if ( V_235 -> V_238 . V_239 & V_240 )
V_73 = V_241 | V_242 ;
else if ( V_235 -> V_238 . V_239 & V_243 )
V_73 = V_244 | V_245 ;
else
V_73 = V_246 ;
F_65 ( L_78 , V_73 ) ;
V_21 = F_23 ( V_18 , L_79 , V_73 ) ;
if ( V_21 ) {
F_14 ( L_80 , V_21 ) ;
return V_21 ;
}
V_237 = & V_219 -> V_237 ;
V_237 -> V_239 = V_235 -> V_238 . V_239 ;
return V_21 ;
}
static T_6 F_70 ( struct V_17 * V_18 ,
struct V_234 * V_235 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_236 * V_237 ;
T_6 V_73 = 0 ;
T_6 V_21 = 0 ;
switch ( V_235 -> V_247 ) {
case V_248 :
V_73 = 0 ;
F_65 ( L_81 ) ;
break;
case V_249 :
V_73 = 1 ;
F_65 ( L_82 ) ;
break;
case V_250 :
V_73 = 2 ;
F_65 ( L_83 ) ;
break;
case V_251 :
F_65 ( L_84 ) ;
default:
V_73 = 2 ;
F_14 ( L_85 , V_235 -> V_247 ) ;
break;
}
V_21 = F_23 ( V_18 , L_86 , V_73 ) ;
if ( V_21 ) {
F_14 ( L_87 , V_21 ) ;
return V_21 ;
}
V_237 = & V_219 -> V_237 ;
V_237 -> V_247 = V_235 -> V_247 ;
return V_21 ;
}
static T_6
F_71 ( struct V_17 * V_18 ,
struct V_234 * V_235 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_236 * V_237 ;
T_6 V_252 = 0 ;
T_6 V_253 = 0 ;
T_6 V_21 = 0 ;
if ( V_235 -> V_238 . V_254 ) {
switch ( V_235 -> V_238 . V_255 [ 0 ] ) {
case V_256 :
case V_257 :
V_252 = V_228 ;
break;
case V_258 :
V_252 = V_259 ;
break;
case V_260 :
V_252 = V_261 ;
break;
case V_262 :
V_252 = V_261 ;
break;
default:
F_14 ( L_88 ,
V_235 -> V_238 . V_255 [ 0 ] ) ;
return - V_64 ;
}
}
if ( V_235 -> V_238 . V_263 ) {
switch ( V_235 -> V_238 . V_263 ) {
case V_256 :
case V_257 :
V_253 = V_228 ;
break;
case V_258 :
V_253 = V_259 ;
break;
case V_260 :
V_253 = V_261 ;
break;
case V_262 :
V_253 = V_261 ;
break;
default:
F_14 ( L_89 ,
V_235 -> V_238 . V_263 ) ;
return - V_64 ;
}
}
F_65 ( L_90 , V_252 , V_253 ) ;
V_21 = F_23 ( V_18 , L_73 , V_252 | V_253 ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
V_237 = & V_219 -> V_237 ;
V_237 -> V_264 = V_235 -> V_238 . V_255 [ 0 ] ;
V_237 -> V_263 = V_235 -> V_238 . V_263 ;
return V_21 ;
}
static T_6
F_72 ( struct V_17 * V_18 , struct V_234 * V_235 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_236 * V_237 ;
T_6 V_73 = 0 ;
T_6 V_21 = 0 ;
if ( V_235 -> V_238 . V_265 ) {
V_21 = F_25 ( V_18 , L_79 , & V_73 ) ;
if ( V_21 ) {
F_14 ( L_91 , V_21 ) ;
return V_21 ;
}
if ( V_73 & ( V_241 | V_242 ) ) {
switch ( V_235 -> V_238 . V_266 [ 0 ] ) {
case V_267 :
V_73 = V_242 ;
break;
case V_268 :
V_73 = V_241 ;
break;
default:
F_14 ( L_89 ,
V_235 -> V_238 . V_263 ) ;
return - V_64 ;
}
} else if ( V_73 & ( V_244 | V_245 ) ) {
switch ( V_235 -> V_238 . V_266 [ 0 ] ) {
case V_267 :
V_73 = V_245 ;
break;
case V_268 :
V_73 = V_244 ;
break;
default:
F_14 ( L_89 ,
V_235 -> V_238 . V_263 ) ;
return - V_64 ;
}
}
F_65 ( L_92 , V_73 ) ;
V_21 = F_23 ( V_18 , L_79 , V_73 ) ;
if ( V_21 ) {
F_14 ( L_93 , V_21 ) ;
return V_21 ;
}
}
V_237 = & V_219 -> V_237 ;
V_237 -> V_269 = V_235 -> V_238 . V_266 [ 0 ] ;
return V_21 ;
}
static T_6
F_73 ( struct V_17 * V_18 ,
struct V_234 * V_235 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_236 * V_237 ;
struct V_33 V_34 ;
T_6 V_73 ;
T_6 V_21 = 0 ;
T_6 V_28 ;
F_65 ( L_94 , V_235 -> V_270 ) ;
if ( V_235 -> V_270 == 0 )
return 0 ;
V_237 = & V_219 -> V_237 ;
F_65 ( L_95 ,
V_237 -> V_239 , V_237 -> V_264 ) ;
if ( V_237 -> V_239 & ( V_240 | V_243 ) )
return 0 ;
if ( ! ( V_237 -> V_264 &
( V_256 | V_257 ) ) )
return 0 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_30 = ( T_4 ) V_235 -> V_270 ;
V_34 . V_37 = ( T_4 ) V_235 -> V_271 ;
if ( V_34 . V_30 > sizeof( V_34 . V_44 ) ) {
F_14 ( L_96 , V_34 . V_30 ) ;
return - V_64 ;
}
memcpy ( V_34 . V_44 , V_235 -> V_34 , V_34 . V_30 ) ;
V_34 . V_39 = V_272 ;
switch ( V_237 -> V_264 ) {
case V_256 :
V_34 . V_38 = V_273 ;
break;
case V_257 :
V_34 . V_38 = V_274 ;
break;
default:
F_14 ( L_97 ,
V_235 -> V_238 . V_255 [ 0 ] ) ;
return - V_64 ;
}
F_65 ( L_98 ,
V_34 . V_30 , V_34 . V_37 , V_34 . V_38 ) ;
F_65 ( L_99 , V_34 . V_44 ) ;
V_28 = F_28 ( V_3 , V_18 ) ;
V_21 = F_18 ( V_3 , V_28 , V_18 , & V_34 ) ;
if ( V_21 )
return V_21 ;
if ( V_237 -> V_247 == V_249 ) {
F_65 ( L_100 ) ;
V_73 = V_275 ;
V_21 = F_26 ( V_18 , L_86 , V_73 , V_28 ) ;
if ( V_21 )
F_14 ( L_87 , V_21 ) ;
}
return V_21 ;
}
static T_6
F_74 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_234 * V_235 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_147 * V_276 = V_235 -> V_146 ;
struct V_209 V_210 ;
T_8 V_211 ;
struct V_82 V_83 ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
if ( ! V_235 -> V_83 ) {
F_14 ( L_101 ) ;
return - V_55 ;
}
F_21 ( V_136 , & V_3 -> V_5 ) ;
if ( V_276 ) {
V_3 -> V_146 =
F_46 ( V_276 -> V_152 ) ;
F_65 ( L_102 ,
V_3 -> V_146 , V_276 -> V_152 ) ;
} else
V_3 -> V_146 = 0 ;
F_4 ( L_103 , V_235 -> V_223 , V_235 -> V_224 ) ;
V_21 = F_69 ( V_18 , V_235 ) ;
if ( V_21 ) {
F_14 ( L_104 , V_21 ) ;
goto V_65;
}
V_21 = F_70 ( V_18 , V_235 ) ;
if ( V_21 ) {
F_14 ( L_105 , V_21 ) ;
goto V_65;
}
V_21 = F_71 ( V_18 , V_235 ) ;
if ( V_21 ) {
F_14 ( L_106 , V_21 ) ;
goto V_65;
}
V_21 = F_72 ( V_18 , V_235 ) ;
if ( V_21 ) {
F_14 ( L_107 , V_21 ) ;
goto V_65;
}
V_21 = F_73 ( V_18 , V_235 ) ;
if ( V_21 ) {
F_14 ( L_108 , V_21 ) ;
goto V_65;
}
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_211 = sizeof( V_210 . V_96 ) ;
V_219 -> V_83 . V_95 = F_43 ( T_4 ,
sizeof( V_83 . V_97 ) , ( T_4 ) V_235 -> V_138 ) ;
memcpy ( & V_210 . V_96 . V_97 , V_235 -> V_83 , V_219 -> V_83 . V_95 ) ;
memcpy ( & V_219 -> V_83 . V_97 , V_235 -> V_83 , V_219 -> V_83 . V_95 ) ;
V_210 . V_96 . V_95 = F_8 ( V_219 -> V_83 . V_95 ) ;
memcpy ( V_210 . V_81 . V_84 , V_85 , V_86 ) ;
if ( V_83 . V_95 < V_277 )
F_65 ( L_109 ,
V_83 . V_97 , V_83 . V_95 ) ;
F_64 ( V_3 -> V_146 ,
& V_210 , & V_211 ) ;
V_21 = F_9 ( V_18 , V_233 ,
& V_210 , V_211 ) ;
if ( V_21 )
F_14 ( L_77 , V_21 ) ;
V_65:
if ( V_21 )
F_44 ( V_136 , & V_3 -> V_5 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_75 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_1 V_278 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_279 V_280 ;
T_6 V_21 = 0 ;
F_20 ( L_110 , V_278 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
F_44 ( V_281 , & V_3 -> V_5 ) ;
memcpy ( & V_280 . V_45 , & V_219 -> V_84 , V_86 ) ;
V_280 . V_73 = F_8 ( V_278 ) ;
V_21 = F_9 ( V_18 , V_217 , & V_280 ,
sizeof( struct V_279 ) ) ;
if ( V_21 )
F_14 ( L_2 , V_21 ) ;
V_3 -> V_216 = false ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_76 ( struct V_1 * V_1 ,
enum V_282 type , T_6 V_283 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_17 * V_18 = F_39 ( V_3 ) ;
T_1 V_284 ;
T_6 V_21 = 0 ;
T_6 V_285 = 0 ;
T_6 V_286 = F_77 ( V_283 ) ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
switch ( type ) {
case V_287 :
break;
case V_288 :
case V_289 :
if ( V_286 < 0 ) {
F_14 ( L_111 ) ;
V_21 = - V_64 ;
goto V_65;
}
break;
}
V_285 = V_290 << 16 ;
V_21 = F_7 ( V_18 , V_291 , & V_285 ) ;
if ( V_21 )
F_14 ( L_112 , V_21 ) ;
if ( V_286 > 0xffff )
V_284 = 0xffff ;
else
V_284 = ( T_1 ) V_286 ;
V_21 = F_23 ( V_18 , L_113 ,
( T_6 ) ( F_6 ( V_284 ) ) ) ;
if ( V_21 )
F_14 ( L_114 , V_21 ) ;
V_3 -> V_57 -> V_292 = V_286 ;
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6 F_78 ( struct V_1 * V_1 , T_6 * V_286 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_17 * V_18 = F_39 ( V_3 ) ;
T_6 V_293 ;
T_2 V_294 ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
V_21 = F_25 ( V_18 , L_113 , & V_293 ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
goto V_65;
}
V_294 = ( T_2 ) ( V_293 & ~ V_295 ) ;
* V_286 = ( T_6 ) F_5 ( V_294 ) ;
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_79 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 V_271 , bool V_296 , bool V_297 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_4 V_37 ;
T_4 V_220 ;
T_6 V_21 = 0 ;
T_6 V_28 ;
F_20 ( L_35 ) ;
F_65 ( L_115 , V_271 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
V_28 = F_28 ( V_3 , V_18 ) ;
V_21 = F_27 ( V_18 , L_73 , & V_220 , V_28 ) ;
if ( V_21 ) {
F_14 ( L_116 , V_21 ) ;
goto V_65;
}
if ( V_220 & V_228 ) {
V_37 = V_271 ;
V_21 = F_7 ( V_18 , V_298 ,
& V_37 ) ;
if ( V_21 )
F_14 ( L_2 , V_21 ) ;
}
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_80 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 V_271 , const T_2 * V_299 , struct V_300 * V_50 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_33 V_34 ;
struct V_35 V_36 ;
T_6 V_21 = 0 ;
T_6 V_28 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_37 = ( T_4 ) V_271 ;
if ( ! F_81 ( V_299 ) )
memcpy ( ( char * ) & V_34 . V_45 , ( void * ) V_299 , V_86 ) ;
V_34 . V_30 = ( T_4 ) V_50 -> V_270 ;
V_28 = F_28 ( V_3 , V_18 ) ;
if ( V_34 . V_30 == 0 ) {
V_21 = F_18 ( V_3 , V_28 , V_18 , & V_34 ) ;
if ( V_21 )
F_14 ( L_117 , V_21 ) ;
} else {
if ( V_34 . V_30 > sizeof( V_34 . V_44 ) ) {
F_14 ( L_118 , V_34 . V_30 ) ;
return - V_64 ;
}
F_65 ( L_119 , V_34 . V_37 ) ;
memcpy ( V_34 . V_44 , V_50 -> V_34 , V_34 . V_30 ) ;
if ( V_50 -> V_301 == V_258 ) {
T_2 V_302 [ 8 ] ;
memcpy ( V_302 , & V_34 . V_44 [ 24 ] , sizeof( V_302 ) ) ;
memcpy ( & V_34 . V_44 [ 24 ] , & V_34 . V_44 [ 16 ] , sizeof( V_302 ) ) ;
memcpy ( & V_34 . V_44 [ 16 ] , V_302 , sizeof( V_302 ) ) ;
}
if ( V_50 -> V_303 && V_50 -> V_304 == 6 ) {
T_2 * V_305 ;
V_305 = ( T_2 * ) V_50 -> V_303 ;
V_34 . V_40 . V_41 = ( V_305 [ 5 ] << 24 ) | ( V_305 [ 4 ] << 16 ) |
( V_305 [ 3 ] << 8 ) | V_305 [ 2 ] ;
V_34 . V_40 . V_42 = ( V_305 [ 1 ] << 8 ) | V_305 [ 0 ] ;
V_34 . V_43 = true ;
}
switch ( V_50 -> V_301 ) {
case V_256 :
V_34 . V_38 = V_273 ;
F_65 ( L_120 ) ;
break;
case V_257 :
V_34 . V_38 = V_274 ;
F_65 ( L_121 ) ;
break;
case V_258 :
V_34 . V_38 = V_306 ;
F_65 ( L_122 ) ;
break;
case V_262 :
V_34 . V_38 = V_307 ;
F_65 ( L_123 ) ;
break;
case V_260 :
V_34 . V_38 = V_307 ;
F_65 ( L_124 ) ;
break;
default:
F_14 ( L_125 , V_50 -> V_301 ) ;
return - V_64 ;
}
F_16 ( & V_34 , & V_36 ) ;
F_82 ( V_18 ) ;
V_21 = F_11 ( V_18 , L_3 , & V_36 ,
sizeof( V_36 ) ,
V_3 -> V_46 ,
V_47 , V_28 ) ;
if ( V_21 )
F_14 ( L_4 , V_21 ) ;
}
return V_21 ;
}
static T_6
F_83 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 V_271 , bool V_308 , const T_2 * V_299 ,
struct V_300 * V_50 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_33 V_34 ;
T_6 V_73 ;
T_6 V_220 ;
T_6 V_21 = 0 ;
T_2 V_302 [ 8 ] ;
T_6 V_28 ;
F_20 ( L_35 ) ;
F_65 ( L_115 , V_271 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
if ( V_299 ) {
F_20 ( L_126 ) ;
return F_80 ( V_1 , V_18 , V_271 , V_299 , V_50 ) ;
}
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_30 = ( T_4 ) V_50 -> V_270 ;
V_34 . V_37 = ( T_4 ) V_271 ;
if ( V_34 . V_30 > sizeof( V_34 . V_44 ) ) {
F_14 ( L_96 , V_34 . V_30 ) ;
V_21 = - V_64 ;
goto V_65;
}
memcpy ( V_34 . V_44 , V_50 -> V_34 , V_34 . V_30 ) ;
V_34 . V_39 = V_272 ;
switch ( V_50 -> V_301 ) {
case V_256 :
V_34 . V_38 = V_273 ;
V_73 = V_228 ;
F_65 ( L_120 ) ;
break;
case V_257 :
V_34 . V_38 = V_274 ;
V_73 = V_228 ;
F_65 ( L_121 ) ;
break;
case V_258 :
if ( V_3 -> V_57 -> V_58 != V_63 ) {
F_65 ( L_127 ) ;
memcpy ( V_302 , & V_34 . V_44 [ 24 ] , sizeof( V_302 ) ) ;
memcpy ( & V_34 . V_44 [ 24 ] , & V_34 . V_44 [ 16 ] , sizeof( V_302 ) ) ;
memcpy ( & V_34 . V_44 [ 16 ] , V_302 , sizeof( V_302 ) ) ;
}
V_34 . V_38 = V_306 ;
V_73 = V_259 ;
F_65 ( L_122 ) ;
break;
case V_262 :
V_34 . V_38 = V_307 ;
V_73 = V_261 ;
F_65 ( L_123 ) ;
break;
case V_260 :
V_34 . V_38 = V_307 ;
V_73 = V_261 ;
F_65 ( L_124 ) ;
break;
default:
F_14 ( L_125 , V_50 -> V_301 ) ;
V_21 = - V_64 ;
goto V_65;
}
V_28 = F_28 ( V_3 , V_18 ) ;
V_21 = F_18 ( V_3 , V_28 , V_18 , & V_34 ) ;
if ( V_21 )
goto V_65;
V_21 = F_27 ( V_18 , L_73 , & V_220 , V_28 ) ;
if ( V_21 ) {
F_14 ( L_128 , V_21 ) ;
goto V_65;
}
V_220 |= V_73 ;
V_21 = F_26 ( V_18 , L_73 , V_220 , V_28 ) ;
if ( V_21 ) {
F_14 ( L_129 , V_21 ) ;
goto V_65;
}
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_84 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 V_271 , bool V_308 , const T_2 * V_299 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_33 V_34 ;
T_6 V_21 = 0 ;
T_6 V_28 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_37 = ( T_4 ) V_271 ;
V_34 . V_39 = V_272 ;
V_34 . V_38 = V_309 ;
F_65 ( L_115 , V_271 ) ;
V_28 = F_28 ( V_3 , V_18 ) ;
V_21 = F_18 ( V_3 , V_28 , V_18 , & V_34 ) ;
if ( V_21 ) {
if ( V_21 == - V_64 ) {
if ( V_34 . V_37 >= V_310 )
F_14 ( L_130 , V_271 ) ;
}
V_21 = - V_70 ;
}
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_85 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 V_271 , bool V_308 , const T_2 * V_299 , void * V_311 ,
void (* F_86) ( void * V_311 , struct V_300 * V_50 ) )
{
struct V_300 V_50 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_236 * V_237 ;
T_6 V_220 ;
T_6 V_21 = 0 ;
T_6 V_28 ;
F_20 ( L_35 ) ;
F_65 ( L_115 , V_271 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_28 = F_28 ( V_3 , V_18 ) ;
V_21 = F_27 ( V_18 , L_73 , & V_220 , V_28 ) ;
if ( V_21 ) {
F_14 ( L_116 , V_21 ) ;
V_21 = - V_70 ;
goto V_65;
}
switch ( V_220 & ~ V_312 ) {
case V_228 :
V_237 = & V_219 -> V_237 ;
if ( V_237 -> V_264 & V_256 ) {
V_50 . V_301 = V_256 ;
F_65 ( L_120 ) ;
} else if ( V_237 -> V_264 & V_257 ) {
V_50 . V_301 = V_257 ;
F_65 ( L_121 ) ;
}
break;
case V_259 :
V_50 . V_301 = V_258 ;
F_65 ( L_122 ) ;
break;
case V_261 :
V_50 . V_301 = V_262 ;
F_65 ( L_123 ) ;
break;
default:
F_14 ( L_131 , V_220 ) ;
V_21 = - V_64 ;
goto V_65;
}
F_86 ( V_311 , & V_50 ) ;
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_87 ( struct V_1 * V_1 ,
struct V_17 * V_18 , T_2 V_271 )
{
F_4 ( L_132 ) ;
return - V_55 ;
}
static T_6
F_88 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 * V_313 , struct V_314 * V_315 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_279 V_316 ;
int V_317 ;
T_6 V_318 ;
T_6 V_21 = 0 ;
T_2 * V_84 = V_219 -> V_84 ;
struct V_319 * V_320 ;
F_20 ( L_133 , V_313 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
if ( V_3 -> V_57 -> V_58 == V_63 ) {
V_21 = F_33 ( V_18 , L_134 , V_313 , V_86 ,
V_3 -> V_110 ,
V_321 ) ;
if ( V_21 < 0 ) {
F_14 ( L_135 , V_21 ) ;
goto V_65;
}
V_320 = (struct V_319 * ) V_3 -> V_110 ;
V_315 -> V_322 = V_323 ;
V_315 -> V_324 = F_10 ( V_320 -> V_325 ) * 1000 ;
if ( F_10 ( V_320 -> V_39 ) & V_326 ) {
V_315 -> V_322 |= V_327 ;
V_315 -> V_328 = F_10 ( V_320 -> V_329 ) ;
}
F_20 ( L_136 ,
V_315 -> V_324 , V_315 -> V_328 ) ;
} else if ( V_3 -> V_57 -> V_58 == V_61 ) {
if ( memcmp ( V_313 , V_84 , V_86 ) ) {
F_14 ( L_137 ,
V_313 , V_84 ) ;
V_21 = - V_330 ;
goto V_65;
}
V_21 = F_7 ( V_18 , V_331 , & V_318 ) ;
if ( V_21 ) {
F_14 ( L_138 , V_21 ) ;
goto V_65;
} else {
V_315 -> V_322 |= V_332 ;
V_315 -> V_333 . V_334 = V_318 * 5 ;
F_65 ( L_139 , V_318 / 2 ) ;
}
if ( F_3 ( V_281 , & V_3 -> V_5 ) ) {
memset ( & V_316 , 0 , sizeof( V_316 ) ) ;
V_21 = F_9 ( V_18 , V_335 , & V_316 ,
sizeof( V_316 ) ) ;
if ( V_21 ) {
F_14 ( L_140 , V_21 ) ;
goto V_65;
} else {
V_317 = F_10 ( V_316 . V_73 ) ;
V_315 -> V_322 |= V_336 ;
V_315 -> signal = V_317 ;
F_65 ( L_141 , V_317 ) ;
}
}
} else
V_21 = - V_172 ;
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_89 ( struct V_1 * V_1 , struct V_17 * V_18 ,
bool V_337 , T_6 V_338 )
{
T_6 V_339 ;
T_6 V_21 = 0 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_20 ( L_35 ) ;
V_3 -> V_340 = V_337 ;
if ( ! F_3 ( V_4 , & V_3 -> V_5 ) ) {
F_4 ( L_142 ) ;
goto V_65;
}
V_339 = V_337 ? V_341 : V_342 ;
F_4 ( L_143 , ( V_339 ? L_144 : L_145 ) ) ;
V_21 = F_7 ( V_18 , V_343 , & V_339 ) ;
if ( V_21 ) {
if ( V_21 == - V_344 )
F_14 ( L_146 ) ;
else
F_14 ( L_2 , V_21 ) ;
}
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_90 ( struct V_1 * V_1 , struct V_17 * V_18 ,
const T_2 * V_345 ,
const struct V_346 * V_347 )
{
struct V_348 V_349 ;
T_6 V_318 ;
T_6 V_73 ;
T_6 V_350 ;
T_6 V_351 ;
T_4 V_334 ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
V_21 = F_9 ( V_18 , V_352 , & V_349 ,
sizeof( V_349 ) ) ;
if ( V_21 ) {
F_14 ( L_147 , V_21 ) ;
goto V_65;
}
V_334 = F_91 ( V_347 -> V_353 [ V_154 ] . V_334 & 0xFFFF ) ;
if ( ! V_334 )
V_334 = F_91 ( V_347 -> V_353 [ V_354 ] . V_334 &
0xFFFF ) ;
V_73 = V_355 [ V_334 - 1 ] . V_356 * 100000 ;
if ( V_73 < F_10 ( V_349 . V_184 ) )
V_318 = V_349 . V_357 [ V_73 ] & 0x7f ;
else
V_318 = V_73 / 500000 ;
F_65 ( L_148 , V_318 / 2 ) ;
V_350 = F_23 ( V_18 , L_149 , V_318 ) ;
V_351 = F_23 ( V_18 , L_150 , V_318 ) ;
if ( V_350 && V_351 ) {
F_14 ( L_151 , V_350 , V_351 ) ;
V_21 = V_350 | V_351 ;
}
V_65:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6 F_92 ( struct V_2 * V_3 ,
struct V_358 * V_359 )
{
struct V_1 * V_1 = F_52 ( V_3 ) ;
struct V_147 * V_360 ;
struct V_361 * V_362 ;
struct V_363 * V_153 ;
T_6 V_21 = 0 ;
T_1 V_146 ;
T_4 V_364 ;
T_1 V_365 ;
T_1 V_366 ;
T_2 * V_367 ;
T_8 V_368 ;
T_6 V_369 ;
if ( F_10 ( V_359 -> V_370 ) > V_371 ) {
F_14 ( L_152 ) ;
return 0 ;
}
V_146 = V_359 -> V_372 ? V_359 -> V_372 :
F_93 ( F_94 ( V_359 -> V_145 ) ) ;
if ( V_146 <= V_212 )
V_153 = V_1 -> V_373 [ V_154 ] ;
else
V_153 = V_1 -> V_373 [ V_354 ] ;
V_364 = F_95 ( V_146 , V_153 -> V_153 ) ;
V_360 = F_96 ( V_1 , V_364 ) ;
V_365 = F_94 ( V_359 -> V_374 ) ;
V_366 = F_94 ( V_359 -> V_375 ) ;
V_367 = ( T_2 * ) V_359 + F_94 ( V_359 -> V_376 ) ;
V_368 = F_10 ( V_359 -> V_377 ) ;
V_369 = ( V_378 ) F_94 ( V_359 -> V_379 ) * 100 ;
F_65 ( L_153 ,
V_359 -> V_380 [ 0 ] , V_359 -> V_380 [ 1 ] , V_359 -> V_380 [ 2 ] ,
V_359 -> V_380 [ 3 ] , V_359 -> V_380 [ 4 ] , V_359 -> V_380 [ 5 ] ) ;
F_65 ( L_154 , V_146 , V_364 ) ;
F_65 ( L_155 , V_365 ) ;
F_65 ( L_156 , V_366 ) ;
F_65 ( L_157 , V_369 ) ;
V_362 = F_97 ( V_1 , V_360 , ( const T_2 * ) V_359 -> V_380 ,
0 , V_365 , V_366 , V_367 ,
V_368 , V_369 , V_68 ) ;
if ( ! V_362 )
return - V_29 ;
F_98 ( V_362 ) ;
return V_21 ;
}
static struct V_358 *
F_99 ( struct V_178 * V_381 , struct V_358 * V_362 )
{
if ( V_362 == NULL )
return V_381 -> V_382 ;
return (struct V_358 * ) ( ( unsigned long ) V_362 +
F_10 ( V_362 -> V_370 ) ) ;
}
static T_6 F_100 ( struct V_2 * V_3 )
{
struct V_178 * V_383 ;
struct V_358 * V_359 = NULL ;
T_6 V_21 = 0 ;
int V_144 ;
V_383 = V_3 -> V_383 ;
if ( V_383 -> V_107 != V_384 ) {
F_14 ( L_158 ,
V_383 -> V_107 ) ;
return - V_55 ;
}
F_42 ( L_159 , V_383 -> V_184 ) ;
for ( V_144 = 0 ; V_144 < V_383 -> V_184 && V_144 < V_385 ; V_144 ++ ) {
V_359 = F_99 ( V_383 , V_359 ) ;
V_21 = F_92 ( V_3 , V_359 ) ;
if ( V_21 )
break;
}
return V_21 ;
}
static T_6 F_101 ( struct V_2 * V_3 ,
struct V_17 * V_18 , const T_2 * V_84 )
{
struct V_1 * V_1 = F_52 ( V_3 ) ;
struct V_147 * V_360 ;
struct V_358 * V_359 = NULL ;
struct V_363 * V_153 ;
struct V_361 * V_362 ;
T_2 * V_26 = NULL ;
T_6 V_21 = 0 ;
T_1 V_146 ;
T_4 V_364 ;
T_1 V_365 ;
T_1 V_366 ;
T_2 * V_367 ;
T_8 V_368 ;
T_6 V_369 ;
F_20 ( L_35 ) ;
V_26 = F_22 ( V_371 , V_68 ) ;
if ( V_26 == NULL ) {
V_21 = - V_29 ;
goto V_386;
}
* ( T_5 * ) V_26 = F_8 ( V_371 ) ;
V_21 = F_9 ( V_18 , V_387 , V_26 , V_371 ) ;
if ( V_21 ) {
F_14 ( L_160 , V_21 ) ;
goto V_386;
}
V_359 = (struct V_358 * ) ( V_26 + 4 ) ;
V_146 = V_359 -> V_372 ? V_359 -> V_372 :
F_93 ( F_94 ( V_359 -> V_145 ) ) ;
if ( V_146 <= V_212 )
V_153 = V_1 -> V_373 [ V_154 ] ;
else
V_153 = V_1 -> V_373 [ V_354 ] ;
V_364 = F_95 ( V_146 , V_153 -> V_153 ) ;
V_360 = F_96 ( V_1 , V_364 ) ;
V_365 = F_94 ( V_359 -> V_374 ) ;
V_366 = F_94 ( V_359 -> V_375 ) ;
V_367 = ( T_2 * ) V_359 + F_94 ( V_359 -> V_376 ) ;
V_368 = F_10 ( V_359 -> V_377 ) ;
V_369 = ( V_378 ) F_94 ( V_359 -> V_379 ) * 100 ;
F_65 ( L_161 , V_146 , V_364 ) ;
F_65 ( L_162 , V_365 ) ;
F_65 ( L_67 , V_366 ) ;
F_65 ( L_163 , V_369 ) ;
V_362 = F_97 ( V_1 , V_360 , V_84 ,
0 , V_365 , V_366 ,
V_367 , V_368 , V_369 , V_68 ) ;
if ( ! V_362 ) {
V_21 = - V_29 ;
goto V_386;
}
F_98 ( V_362 ) ;
V_386:
F_36 ( V_26 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static bool F_102 ( struct V_2 * V_3 )
{
return V_3 -> V_57 -> V_58 == V_59 ;
}
static struct V_388 * F_103 ( void * V_26 , int V_27 , T_3 V_34 )
{
struct V_388 * V_389 ;
int V_390 ;
V_389 = (struct V_388 * ) V_26 ;
V_390 = V_27 ;
while ( V_390 >= V_391 ) {
int V_30 = V_389 -> V_30 ;
if ( ( V_389 -> V_392 == V_34 ) && ( V_390 >= ( V_30 + V_391 ) ) )
return V_389 ;
V_389 = (struct V_388 * ) ( ( T_2 * ) V_389 + ( V_30 + V_391 ) ) ;
V_390 -= ( V_30 + V_391 ) ;
}
return NULL ;
}
static bool
F_104 ( T_2 * V_223 , T_2 * * V_393 , T_4 * V_394 ,
T_2 * V_395 , T_4 V_396 , T_2 type )
{
if ( V_223 [ V_397 ] >= V_396 + 1 &&
! memcmp ( & V_223 [ V_398 ] , V_395 , V_396 ) &&
type == V_223 [ V_398 + V_396 ] ) {
return true ;
}
if ( V_393 == NULL )
return false ;
V_223 += V_223 [ V_397 ] + V_391 ;
* V_394 -= ( int ) ( V_223 - * V_393 ) ;
* V_393 = V_223 ;
return false ;
}
struct V_399 *
F_105 ( T_2 * V_400 , T_4 V_30 )
{
struct V_388 * V_223 ;
while ( ( V_223 = F_103 ( V_400 , V_30 , V_401 ) ) ) {
if ( F_104 ( ( T_2 * ) V_223 , & V_400 , & V_30 ,
V_402 , V_403 , V_404 ) )
return (struct V_399 * ) V_223 ;
}
return NULL ;
}
static T_6 F_106 ( struct V_2 * V_3 )
{
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_358 * V_359 ;
struct V_82 * V_83 ;
struct V_388 * V_405 ;
T_1 V_225 ;
T_2 V_406 ;
T_8 V_224 ;
T_2 * V_223 ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( F_102 ( V_3 ) )
return V_21 ;
V_83 = & V_219 -> V_83 ;
* ( T_5 * ) V_3 -> V_46 = F_8 ( V_47 ) ;
V_21 = F_9 ( F_39 ( V_3 ) , V_387 ,
V_3 -> V_46 , V_47 ) ;
if ( V_21 ) {
F_14 ( L_164 , V_21 ) ;
goto V_407;
}
V_359 = (struct V_358 * ) ( V_3 -> V_46 + 4 ) ;
V_21 = F_92 ( V_3 , V_359 ) ;
if ( V_21 )
goto V_407;
V_223 = ( ( T_2 * ) V_359 ) + F_94 ( V_359 -> V_376 ) ;
V_224 = F_10 ( V_359 -> V_377 ) ;
V_225 = F_94 ( V_359 -> V_375 ) ;
V_405 = F_103 ( V_223 , V_224 , V_408 ) ;
if ( V_405 )
V_406 = V_405 -> V_44 [ 1 ] ;
else {
T_4 V_77 ;
V_21 = F_25 ( F_39 ( V_3 ) ,
L_165 , & V_77 ) ;
if ( V_21 ) {
F_14 ( L_166 , V_21 ) ;
goto V_407;
}
V_406 = ( T_2 ) V_77 ;
}
V_219 -> V_225 = V_225 ;
V_219 -> V_406 = V_406 ;
V_407:
F_20 ( L_126 ) ;
return V_21 ;
}
static void F_107 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = F_38 ( V_3 ) ;
struct V_180 * V_409 = & V_3 -> V_180 ;
struct V_82 V_83 ;
F_21 ( V_135 , & V_3 -> V_5 ) ;
if ( V_3 -> V_137 ) {
V_102 -> V_113 = V_410 ;
if ( V_102 -> V_123 ) {
F_50 ( & V_102 -> V_119 ) ;
V_102 -> V_123 = 0 ;
}
F_108 ( & V_102 -> V_411 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
F_34 ( V_102 , & V_83 , V_412 ) ;
if ( V_3 -> V_139 ) {
F_4 ( L_167 ) ;
F_53 ( V_3 -> V_139 , true ) ;
V_3 -> V_139 = NULL ;
}
}
if ( V_3 -> V_192 && V_3 -> V_139 ) {
V_409 -> V_181 = V_413 ;
F_48 ( V_3 , V_409 -> V_18 , true , true ) ;
}
F_44 ( V_134 , & V_3 -> V_5 ) ;
F_44 ( V_135 , & V_3 -> V_5 ) ;
}
static void F_109 ( struct V_101 * V_102 ,
bool V_168 )
{
struct V_2 * V_3 = F_110 ( V_102 ) ;
struct V_17 * V_18 = F_39 ( V_3 ) ;
if ( ! F_54 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_42 ) ;
return;
}
if ( V_3 -> V_139 ) {
F_42 ( L_168 ,
V_168 ? L_40 : L_41 ) ;
F_53 ( V_3 -> V_139 , V_168 ) ;
F_29 ( V_18 , 1 ) ;
V_3 -> V_139 = NULL ;
}
V_3 -> V_117 = false ;
}
static T_6 F_111 ( struct V_101 * V_102 )
{
if ( V_102 -> V_113 != V_410 ) {
F_42 ( L_169 ) ;
F_112 ( & V_102 -> V_411 ) ;
return 0 ;
}
return - V_191 ;
}
static T_6
F_113 ( struct V_101 * V_102 , T_4 * V_5 ,
struct V_178 * * V_383 )
{
struct V_414 V_381 ;
struct V_178 * V_179 ;
struct V_415 * V_416 ;
struct V_414 * V_417 ;
T_6 V_21 = 0 ;
memset ( V_102 -> V_418 , 0 , V_419 ) ;
V_417 = (struct V_414 * ) V_102 -> V_418 ;
V_179 = & V_417 -> V_179 ;
V_416 = & V_417 -> V_416 ;
V_179 -> V_27 = V_420 ;
V_179 -> V_107 = 0 ;
V_179 -> V_184 = 0 ;
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_381 . V_416 . V_27 = F_8 ( V_419 ) ;
V_21 = F_33 ( V_102 -> V_18 , L_170 , & V_381 ,
V_420 ,
V_102 -> V_418 , V_419 ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
V_179 -> V_27 = F_10 ( V_416 -> V_27 ) ;
V_179 -> V_107 = F_10 ( V_416 -> V_107 ) ;
V_179 -> V_184 = F_10 ( V_416 -> V_184 ) ;
F_42 ( L_171 , V_416 -> V_184 ) ;
F_42 ( L_172 , V_416 -> V_27 ) ;
* V_5 = F_10 ( V_417 -> V_421 ) ;
F_42 ( L_173 , * V_5 ) ;
* V_383 = V_179 ;
return V_21 ;
}
static T_6 F_114 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = V_3 -> V_102 ;
T_6 V_21 = 0 ;
V_102 -> V_113 = V_410 ;
F_100 ( V_3 ) ;
F_109 ( V_102 , false ) ;
return V_21 ;
}
static T_6 F_115 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = V_3 -> V_102 ;
T_6 V_21 = 0 ;
F_40 ( & V_102 -> V_119 , V_120 + V_102 -> V_121 * V_122 / 1000 ) ;
V_102 -> V_123 = 1 ;
return V_21 ;
}
static T_6 F_116 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = V_3 -> V_102 ;
T_6 V_21 = 0 ;
F_100 ( V_3 ) ;
F_34 ( V_102 , NULL , V_422 ) ;
F_40 ( & V_102 -> V_119 , V_120 + V_102 -> V_121 * V_122 / 1000 ) ;
V_102 -> V_123 = 1 ;
return V_21 ;
}
static T_6 F_117 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = V_3 -> V_102 ;
T_6 V_21 = 0 ;
V_102 -> V_113 = V_410 ;
F_109 ( V_102 , true ) ;
return V_21 ;
}
static void F_118 ( struct V_423 * V_411 )
{
struct V_101 * V_102 =
F_119 ( V_411 , struct V_101 ,
V_411 ) ;
struct V_2 * V_3 = F_110 ( V_102 ) ;
struct V_424 * V_425 = & V_102 -> V_425 ;
T_4 V_5 = V_426 ;
if ( V_102 -> V_123 ) {
F_50 ( & V_102 -> V_119 ) ;
V_102 -> V_123 = 0 ;
}
if ( F_113 ( V_102 , & V_5 , & V_3 -> V_383 ) ) {
V_5 = V_427 ;
F_14 ( L_174 ) ;
}
V_425 -> V_428 [ V_5 ] ( V_3 ) ;
}
static void F_120 ( unsigned long V_44 )
{
struct V_101 * V_102 =
(struct V_101 * ) V_44 ;
if ( V_102 ) {
V_102 -> V_123 = 0 ;
F_42 ( L_175 ) ;
F_111 ( V_102 ) ;
}
}
static T_6 F_121 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = F_38 ( V_3 ) ;
if ( V_3 -> V_137 ) {
V_102 -> V_113 = V_410 ;
F_122 ( & V_102 -> V_411 , F_118 ) ;
}
return 0 ;
}
static void F_123 ( struct V_424 * V_425 )
{
memset ( V_425 , 0 , sizeof( * V_425 ) ) ;
V_425 -> V_428 [ V_429 ] = F_114 ;
V_425 -> V_428 [ V_426 ] = F_116 ;
V_425 -> V_428 [ V_430 ] = F_115 ;
V_425 -> V_428 [ V_427 ] = F_117 ;
V_425 -> V_428 [ V_431 ] = F_117 ;
}
static T_6 F_124 ( struct V_2 * V_3 )
{
struct V_101 * V_102 = F_38 ( V_3 ) ;
int V_21 = 0 ;
if ( V_3 -> V_137 ) {
V_102 -> V_18 = F_39 ( V_3 ) ;
F_123 ( & V_102 -> V_425 ) ;
V_102 -> V_121 = V_432 ;
F_125 ( & V_102 -> V_119 ) ;
V_102 -> V_119 . V_44 = ( unsigned long ) V_102 ;
V_102 -> V_119 . V_433 = F_120 ;
V_21 = F_121 ( V_3 ) ;
if ( ! V_21 )
V_102 -> V_44 = V_3 ;
}
return V_21 ;
}
static void F_126 ( struct V_423 * V_411 )
{
struct V_2 * V_3 =
F_119 ( V_411 , struct V_2 ,
V_434 ) ;
F_48 ( V_3 ,
V_3 -> V_180 . V_18 , true , true ) ;
}
static void F_127 ( unsigned long V_44 )
{
struct V_2 * V_3 =
(struct V_2 * ) V_44 ;
if ( V_3 -> V_139 ) {
F_14 ( L_175 ) ;
if ( V_3 -> V_192 )
F_112 ( & V_3 -> V_434 ) ;
}
}
static T_6
F_128 ( struct V_358 * V_362 ,
struct V_358 * V_382 )
{
if ( ! memcmp ( & V_382 -> V_380 , & V_362 -> V_380 , V_86 ) &&
( F_129 ( F_94 ( V_382 -> V_145 ) ) ==
F_129 ( F_94 ( V_362 -> V_145 ) ) ) &&
V_382 -> V_95 == V_362 -> V_95 &&
! memcmp ( V_382 -> V_97 , V_362 -> V_97 , V_382 -> V_95 ) ) {
if ( ( V_362 -> V_39 & V_435 ) ==
( V_382 -> V_39 & V_435 ) ) {
V_378 V_436 = F_94 ( V_362 -> V_379 ) ;
V_378 V_437 = F_94 ( V_382 -> V_379 ) ;
if ( V_437 > V_436 )
V_362 -> V_379 = V_382 -> V_379 ;
} else if ( ( V_362 -> V_39 & V_435 ) &&
( V_382 -> V_39 & V_435 ) == 0 ) {
V_362 -> V_379 = V_382 -> V_379 ;
V_362 -> V_39 |= V_435 ;
}
return 1 ;
}
return 0 ;
}
static T_6
F_130 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
T_6 V_5 ;
T_6 V_21 = 0 ;
struct V_440 * V_441 ;
struct V_358 * V_382 ;
struct V_358 * V_362 = NULL ;
T_4 V_442 ;
struct V_178 * V_381 ;
T_4 V_144 ;
bool V_168 ;
V_5 = F_131 ( V_439 -> V_5 ) ;
if ( ! V_18 || ! V_3 -> V_192 ||
! F_3 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_176 ,
V_18 , V_3 -> V_192 ,
! F_3 ( V_134 , & V_3 -> V_5 ) ) ;
return - V_172 ;
}
if ( V_5 == V_443 ) {
F_42 ( L_177 ) ;
V_441 = (struct V_440 * ) V_44 ;
if ( ! V_441 ) {
F_14 ( L_178 ) ;
goto exit;
}
if ( ! V_3 -> V_139 ) {
F_42 ( L_179 ) ;
goto exit;
}
if ( F_94 ( V_441 -> V_444 ) != 1 ) {
F_14 ( L_180 ,
V_441 -> V_444 ) ;
goto exit;
}
V_382 = & V_441 -> V_382 ;
V_442 = F_10 ( V_382 -> V_370 ) ;
if ( V_442 != ( F_10 ( V_441 -> V_27 ) -
V_185 ) ) {
F_14 ( L_181 ,
V_442 ) ;
goto exit;
}
if ( ! ( F_52 ( V_3 ) -> V_445 &
F_132 ( V_56 ) ) ) {
if ( F_94 ( V_382 -> V_374 ) &
V_446 ) {
F_14 ( L_182 ) ;
goto exit;
}
}
V_381 = (struct V_178 * )
V_3 -> V_180 . V_183 ;
if ( V_442 > V_447 - V_381 -> V_27 ) {
F_14 ( L_183 ) ;
goto exit;
}
for ( V_144 = 0 ; V_144 < V_381 -> V_184 ; V_144 ++ ) {
V_362 = V_362 ? (struct V_358 * )
( ( unsigned char * ) V_362 +
F_10 ( V_362 -> V_370 ) ) : V_381 -> V_382 ;
if ( F_128 ( V_362 , V_382 ) )
goto exit;
}
memcpy ( & ( V_3 -> V_180 . V_183 [ V_381 -> V_27 ] ) ,
V_382 , V_442 ) ;
V_381 -> V_107 = F_10 ( V_382 -> V_107 ) ;
V_381 -> V_27 += V_442 ;
V_381 -> V_184 ++ ;
} else {
V_3 -> V_180 . V_181 = V_413 ;
if ( V_3 -> V_139 ) {
V_3 -> V_383 = (struct V_178 * )
V_3 -> V_180 . V_183 ;
F_100 ( V_3 ) ;
V_168 = V_5 != V_448 ;
F_48 ( V_3 , V_18 , V_168 ,
false ) ;
} else
F_14 ( L_184 , V_5 ) ;
}
exit:
return V_21 ;
}
static void F_133 ( struct V_2 * V_3 )
{
if ( V_3 -> V_192 ) {
V_3 -> V_425 . V_428 [ V_449 ] =
F_130 ;
V_3 -> V_180 . V_181 = V_413 ;
F_125 ( & V_3 -> V_170 ) ;
V_3 -> V_170 . V_44 = ( unsigned long ) V_3 ;
V_3 -> V_170 . V_433 = F_127 ;
F_122 ( & V_3 -> V_434 ,
F_126 ) ;
}
}
static T_9 void F_134 ( T_4 V_450 )
{
if ( V_450 < 1000 / V_122 ) {
F_135 () ;
F_136 ( V_450 ) ;
} else {
F_137 ( V_450 ) ;
}
}
static T_6 F_138 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_20 ( L_35 ) ;
if ( F_3 ( V_4 , & V_3 -> V_5 ) )
F_121 ( F_2 ( V_1 ) ) ;
F_20 ( L_12 ) ;
return 0 ;
}
static T_6 F_139 ( struct V_1 * V_1 ,
struct V_451 * V_452 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_17 * V_18 = F_39 ( V_3 ) ;
F_20 ( L_35 ) ;
if ( ( F_3 ( V_281 , & V_3 -> V_5 ) ||
F_3 ( V_136 , & V_3 -> V_5 ) ) &&
F_3 ( V_4 , & V_3 -> V_5 ) ) {
F_4 ( L_185
L_186 ) ;
F_66 ( V_3 ) ;
F_134 ( 500 ) ;
}
if ( F_3 ( V_4 , & V_3 -> V_5 ) )
F_107 ( V_3 ) ;
else
F_44 ( V_134 , & V_3 -> V_5 ) ;
if ( F_3 ( V_4 , & V_3 -> V_5 ) )
F_29 ( V_18 , 1 ) ;
F_20 ( L_12 ) ;
return 0 ;
}
static T_10 T_6
F_140 ( struct V_17 * V_18 , T_7 * V_23 , T_7 * V_26 , T_6 V_30 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
T_4 V_27 ;
V_27 = F_24 ( V_23 , V_26 , V_30 , V_3 -> V_110 ,
V_321 ) ;
F_13 ( ! V_27 ) ;
return F_9 ( V_18 , V_31 , V_3 -> V_110 ,
V_27 ) ;
}
static T_6
F_141 ( struct V_17 * V_18 , T_7 * V_23 , T_7 * V_26 ,
T_6 V_453 )
{
struct V_2 * V_3 = F_30 ( V_18 ) ;
T_4 V_30 ;
T_6 V_21 = 0 ;
V_30 = F_24 ( V_23 , NULL , 0 , V_3 -> V_110 ,
V_321 ) ;
F_13 ( ! V_30 ) ;
V_21 = F_9 ( V_18 , V_32 , V_3 -> V_110 ,
V_321 ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
memcpy ( V_26 , V_3 -> V_110 , V_453 ) ;
return V_21 ;
}
static T_10 T_6
F_142 ( struct V_17 * V_18 ,
struct V_454 * V_455 , T_6 V_21 )
{
int V_144 , V_456 ;
int V_457 ;
V_457 = F_10 ( V_455 -> V_458 . V_459 ) ;
F_65 ( L_187 , V_457 ) ;
for ( V_144 = 0 ; V_144 < V_457 ; V_144 ++ ) {
F_65 ( L_188 , V_144 ,
& V_455 -> V_458 . V_460 [ V_144 ] . V_380 ) ;
for ( V_456 = 0 ; V_456 < V_461 ; V_456 ++ )
F_65 ( L_189 , V_455 -> V_458 . V_460 [ V_144 ] . V_462 [ V_456 ] ) ;
}
if ( ! V_21 )
F_140 ( V_18 , L_190 , ( char * ) V_455 ,
sizeof( * V_455 ) ) ;
return V_21 ;
}
static T_6
F_143 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_463 * V_464 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_465 * V_458 = & V_3 -> V_455 -> V_458 ;
T_6 V_21 = 0 ;
int V_144 ;
int V_457 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
V_457 = F_10 ( V_458 -> V_459 ) ;
for ( V_144 = 0 ; V_144 < V_457 ; V_144 ++ )
if ( ! memcmp ( V_464 -> V_84 , V_458 -> V_460 [ V_144 ] . V_380 , V_86 ) )
break;
if ( V_144 < V_466 ) {
memcpy ( V_458 -> V_460 [ V_144 ] . V_380 , V_464 -> V_84 , V_86 ) ;
memcpy ( V_458 -> V_460 [ V_144 ] . V_462 , V_464 -> V_460 , V_461 ) ;
if ( V_144 == V_457 ) {
V_457 ++ ;
V_458 -> V_459 = F_8 ( V_457 ) ;
}
} else
V_21 = - V_64 ;
F_65 ( L_191 ,
V_458 -> V_460 [ V_457 ] . V_380 ) ;
for ( V_144 = 0 ; V_144 < V_461 ; V_144 ++ )
F_65 ( L_189 , V_458 -> V_460 [ V_457 ] . V_462 [ V_144 ] ) ;
V_21 = F_142 ( V_18 , V_3 -> V_455 , V_21 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_144 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_463 * V_464 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_465 V_460 ;
T_6 V_21 = 0 ;
int V_144 , V_457 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
memcpy ( & V_460 . V_460 [ 0 ] . V_380 , V_464 -> V_84 , V_86 ) ;
memcpy ( & V_460 . V_460 [ 0 ] . V_462 , V_464 -> V_460 , V_461 ) ;
F_65 ( L_192 ,
& V_460 . V_460 [ 0 ] . V_380 ) ;
for ( V_144 = 0 ; V_144 < V_461 ; V_144 ++ )
F_65 ( L_189 , V_460 . V_460 [ 0 ] . V_462 [ V_144 ] ) ;
V_457 = F_10 ( V_3 -> V_455 -> V_458 . V_459 ) ;
for ( V_144 = 0 ; V_144 < V_457 ; V_144 ++ )
if ( ! memcmp
( V_464 -> V_84 , & V_3 -> V_455 -> V_458 . V_460 [ V_144 ] . V_380 ,
V_86 ) )
break;
if ( ( V_457 > 0 )
&& ( V_144 < V_457 ) ) {
memset ( & V_3 -> V_455 -> V_458 . V_460 [ V_144 ] , 0 ,
sizeof( struct V_460 ) ) ;
for (; V_144 < ( V_457 - 1 ) ; V_144 ++ ) {
memcpy ( & V_3 -> V_455 -> V_458 . V_460 [ V_144 ] . V_380 ,
& V_3 -> V_455 -> V_458 . V_460 [ V_144 + 1 ] . V_380 ,
V_86 ) ;
memcpy ( & V_3 -> V_455 -> V_458 . V_460 [ V_144 ] . V_462 ,
& V_3 -> V_455 -> V_458 . V_460 [ V_144 + 1 ] . V_462 ,
V_461 ) ;
}
V_3 -> V_455 -> V_458 . V_459 = F_8 ( V_457 - 1 ) ;
} else
V_21 = - V_64 ;
V_21 = F_142 ( V_18 , V_3 -> V_455 , V_21 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_145 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
memset ( V_3 -> V_455 , 0 , sizeof( * V_3 -> V_455 ) ) ;
V_21 = F_142 ( V_18 , V_3 -> V_455 , V_21 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_146 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
struct V_467 * V_468 , * V_469 ;
struct V_124 * V_125 = NULL ;
struct V_126 * V_83 = NULL ;
struct V_147 * V_146 = NULL ;
struct V_1 * V_1 = F_52 ( V_3 ) ;
int V_21 = 0 ;
int V_470 = 0 ;
int V_153 = 0 ;
struct V_471 * V_472 ;
T_4 V_473 ;
T_4 V_5 ;
F_42 ( L_35 ) ;
if ( V_439 -> V_474 == F_147 ( V_475 ) ) {
F_42 ( L_193 ) ;
return 0 ;
}
V_472 = (struct V_471 * ) V_44 ;
V_473 = F_10 ( V_472 -> V_184 ) ;
V_5 = F_10 ( V_472 -> V_5 ) ;
F_148 ( V_5 != V_476 ) ;
F_42 ( L_194 , V_473 ) ;
if ( V_473 > 0 ) {
int V_144 ;
V_125 = F_22 ( sizeof( * V_125 ) , V_68 ) ;
V_83 = F_149 ( V_473 , sizeof( * V_83 ) , V_68 ) ;
V_146 = F_149 ( V_473 , sizeof( * V_146 ) , V_68 ) ;
if ( ! V_125 || ! V_83 || ! V_146 ) {
V_21 = - V_29 ;
goto V_477;
}
V_125 -> V_1 = V_1 ;
V_44 += sizeof( struct V_471 ) ;
V_469 = (struct V_467 * ) V_44 ;
for ( V_144 = 0 ; V_144 < V_473 ; V_144 ++ ) {
V_468 = & V_469 [ V_144 ] ;
if ( ! V_468 ) {
F_14 ( L_195 , V_144 ) ;
V_21 = - V_64 ;
goto V_477;
}
F_42 ( L_196 ,
V_468 -> V_97 , V_468 -> V_146 ) ;
memcpy ( V_83 [ V_144 ] . V_83 , V_468 -> V_97 , V_468 -> V_95 ) ;
V_83 [ V_144 ] . V_138 = V_468 -> V_95 ;
V_125 -> V_142 ++ ;
V_470 = V_468 -> V_146 ;
if ( V_470 <= V_212 )
V_153 = V_478 ;
else
V_153 = V_479 ;
V_146 [ V_144 ] . V_152 =
F_95 ( V_470 ,
V_153 ) ;
V_146 [ V_144 ] . V_153 = V_153 ;
V_146 [ V_144 ] . V_39 |= V_157 ;
V_125 -> V_151 [ V_144 ] = & V_146 [ V_144 ] ;
V_125 -> V_143 ++ ;
}
if ( V_125 -> V_142 )
V_125 -> V_128 = & V_83 [ 0 ] ;
if ( F_3 ( V_134 , & V_3 -> V_5 ) ) {
F_107 ( V_3 ) ;
}
F_21 ( V_134 , & V_3 -> V_5 ) ;
V_21 = F_56 ( V_3 , V_1 , V_18 , V_125 ) ;
if ( V_21 ) {
F_44 ( V_134 , & V_3 -> V_5 ) ;
goto V_477;
}
V_3 -> V_171 = true ;
V_3 -> V_139 = V_125 ;
} else {
F_14 ( L_197 ) ;
goto V_477;
}
F_36 ( V_83 ) ;
F_36 ( V_146 ) ;
F_36 ( V_125 ) ;
return 0 ;
V_477:
F_36 ( V_83 ) ;
F_36 ( V_146 ) ;
F_36 ( V_125 ) ;
F_150 ( V_1 ) ;
return V_21 ;
}
static int F_151 ( struct V_17 * V_18 )
{
char V_480 [ 128 ] ;
int V_481 ;
V_481 = F_23 ( V_18 , L_198 , 0 ) ;
if ( V_481 == 0 ) {
V_481 = F_32 ( V_18 , L_199 , NULL , 0 ,
V_480 , sizeof( V_480 ) ) ;
}
if ( V_481 < 0 )
F_14 ( L_200 , V_481 ) ;
return V_481 ;
}
static int F_152 ( struct V_17 * V_18 )
{
struct V_482 V_483 ;
char V_480 [ 128 ] ;
memset ( & V_483 , 0 , sizeof( V_483 ) ) ;
V_483 . V_107 = F_8 ( V_484 ) ;
V_483 . V_39 = F_17 ( 1 << V_485 ) ;
V_483 . V_486 = V_487 ;
V_483 . exp = V_488 ;
V_483 . V_489 = F_8 ( V_490 ) ;
return F_32 ( V_18 , L_201 ,
& V_483 , sizeof( V_483 ) ,
V_480 , sizeof( V_480 ) ) ;
}
static int
F_153 ( struct V_1 * V_1 ,
struct V_17 * V_18 ,
struct V_491 * V_125 )
{
char V_480 [ 128 ] ;
struct V_2 * V_3 = F_154 ( V_1 ) ;
struct V_492 V_493 ;
int V_144 ;
int V_481 = 0 ;
F_42 ( L_202 ,
V_125 -> V_494 , V_125 -> V_142 ) ;
if ( F_3 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_18 , V_3 -> V_5 ) ;
return - V_70 ;
}
if ( ! V_125 || ! V_125 -> V_142 || ! V_125 -> V_494 ) {
F_14 ( L_203 ,
V_125 ? V_125 -> V_142 : 0 ) ;
return - V_64 ;
}
if ( V_125 -> V_142 > 0 ) {
for ( V_144 = 0 ; V_144 < V_125 -> V_142 ; V_144 ++ ) {
F_42 ( L_204 ,
V_125 -> V_128 [ V_144 ] . V_83 ) ;
}
}
if ( V_125 -> V_494 > 0 ) {
V_481 = F_151 ( V_18 ) ;
if ( V_481 < 0 ) {
F_14 ( L_205 , V_481 ) ;
return V_481 ;
}
V_481 = F_152 ( V_18 ) ;
if ( V_481 < 0 ) {
F_14 ( L_206 , V_481 ) ;
return - V_64 ;
}
for ( V_144 = 0 ; V_144 < V_125 -> V_494 ; V_144 ++ ) {
struct V_126 * V_83 ;
T_4 V_138 ;
V_83 = & V_125 -> V_495 [ V_144 ] . V_83 ;
V_138 = V_83 -> V_138 ;
if ( ! V_138 ) {
F_14 ( L_207 ) ;
continue;
}
V_493 . V_496 = F_8 ( V_497 ) ;
V_493 . V_269 = F_8 ( V_498 ) ;
V_493 . V_220 = F_8 ( 0 ) ;
V_493 . V_51 = F_8 ( 1 ) ;
V_493 . V_39 = F_8 ( 1 << V_499 ) ;
V_493 . V_83 . V_95 = F_8 ( V_138 ) ;
memcpy ( V_493 . V_83 . V_97 , V_83 -> V_83 , V_138 ) ;
V_481 = F_32 ( V_18 , L_208 ,
& V_493 , sizeof( V_493 ) ,
V_480 , sizeof( V_480 ) ) ;
F_42 ( L_209 ,
V_481 == 0 ? L_210 : L_211 ,
V_83 -> V_83 ) ;
}
if ( F_23 ( V_18 , L_198 , 1 ) < 0 ) {
F_14 ( L_212 , V_481 ) ;
return - V_64 ;
}
} else {
return - V_64 ;
}
return 0 ;
}
static int F_155 ( struct V_1 * V_1 ,
struct V_17 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_42 ( L_213 ) ;
F_151 ( V_18 ) ;
if ( V_3 -> V_171 )
F_48 ( V_3 , V_18 , true , true ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_1 , void * V_44 , int V_30 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_17 * V_18 = V_3 -> V_189 -> V_190 ;
struct V_500 * V_501 = V_44 ;
struct V_502 * V_503 ;
int V_481 ;
V_481 = F_157 ( V_18 , V_501 ) ;
if ( V_481 == 0 ) {
V_503 = F_158 ( V_1 , sizeof( * V_501 ) ) ;
F_159 ( V_503 , V_504 , sizeof( * V_501 ) , V_501 ) ;
V_481 = F_160 ( V_503 ) ;
}
return V_481 ;
}
static T_6 F_161 ( struct V_17 * V_18 , T_6 V_28 )
{
T_6 V_21 ;
V_21 = F_26 ( V_18 , L_86 , 0 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_214 , V_21 ) ;
return V_21 ;
}
V_21 = F_26 ( V_18 , L_73 , 0 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_215 , V_21 ) ;
return V_21 ;
}
V_21 = F_26 ( V_18 , L_79 ,
V_505 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_216 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static bool F_162 ( T_2 * V_395 , bool V_506 )
{
if ( V_506 )
return ( memcmp ( V_395 , V_507 , V_403 ) == 0 ) ;
return ( memcmp ( V_395 , V_402 , V_403 ) == 0 ) ;
}
static T_6
F_163 ( struct V_17 * V_18 , struct V_399 * V_508 ,
bool V_506 , T_6 V_28 )
{
T_4 V_496 = 0 ;
T_1 V_184 ;
T_6 V_21 = 0 ;
T_6 V_30 = 0 ;
T_4 V_144 ;
T_4 V_220 ;
T_4 V_252 = 0 ;
T_4 V_253 = 0 ;
T_4 V_269 = 0 ;
T_4 V_13 ;
T_2 * V_44 ;
T_1 V_509 ;
T_4 V_510 ;
F_20 ( L_35 ) ;
if ( V_508 == NULL )
goto exit;
V_30 = V_508 -> V_30 + V_391 ;
V_44 = ( T_2 * ) V_508 ;
V_13 = 0 ;
if ( ! V_506 )
V_13 += V_511 ;
V_13 += V_512 ;
if ( V_13 + V_513 > V_30 ) {
V_21 = - V_64 ;
F_14 ( L_217 ) ;
goto exit;
}
if ( ! F_162 ( & V_44 [ V_13 ] , V_506 ) ) {
V_21 = - V_64 ;
F_14 ( L_218 ) ;
goto exit;
}
V_13 += V_403 ;
switch ( V_44 [ V_13 ] ) {
case V_514 :
V_253 = 0 ;
break;
case V_515 :
case V_516 :
V_253 = V_228 ;
break;
case V_517 :
V_253 = V_259 ;
break;
case V_518 :
V_253 = V_261 ;
break;
default:
V_21 = - V_64 ;
F_14 ( L_219 ) ;
goto exit;
}
V_13 ++ ;
V_184 = V_44 [ V_13 ] + ( V_44 [ V_13 + 1 ] << 8 ) ;
V_13 += V_519 ;
if ( V_13 + ( V_513 * V_184 ) > V_30 ) {
V_21 = - V_64 ;
F_14 ( L_220 ) ;
goto exit;
}
for ( V_144 = 0 ; V_144 < V_184 ; V_144 ++ ) {
if ( ! F_162 ( & V_44 [ V_13 ] , V_506 ) ) {
V_21 = - V_64 ;
F_14 ( L_218 ) ;
goto exit;
}
V_13 += V_403 ;
switch ( V_44 [ V_13 ] ) {
case V_514 :
break;
case V_515 :
case V_516 :
V_252 |= V_228 ;
break;
case V_517 :
V_252 |= V_259 ;
break;
case V_518 :
V_252 |= V_261 ;
break;
default:
F_14 ( L_221 ) ;
}
V_13 ++ ;
}
V_184 = V_44 [ V_13 ] + ( V_44 [ V_13 + 1 ] << 8 ) ;
V_13 += V_519 ;
if ( V_13 + ( V_513 * V_184 ) > V_30 ) {
V_21 = - V_64 ;
F_14 ( L_222 ) ;
goto exit;
}
for ( V_144 = 0 ; V_144 < V_184 ; V_144 ++ ) {
if ( ! F_162 ( & V_44 [ V_13 ] , V_506 ) ) {
V_21 = - V_64 ;
F_14 ( L_218 ) ;
goto exit;
}
V_13 += V_403 ;
switch ( V_44 [ V_13 ] ) {
case V_520 :
F_20 ( L_223 ) ;
V_269 |= V_505 ;
break;
case V_521 :
F_20 ( L_224 ) ;
V_506 ? ( V_269 |= V_245 ) :
( V_269 |= V_242 ) ;
break;
case V_522 :
F_20 ( L_225 ) ;
V_506 ? ( V_269 |= V_244 ) :
( V_269 |= V_241 ) ;
break;
default:
F_14 ( L_226 ) ;
}
V_13 ++ ;
}
if ( V_506 ) {
V_510 = 1 ;
if ( ( V_13 + V_523 ) <= V_30 ) {
V_509 = V_44 [ V_13 ] + ( V_44 [ V_13 + 1 ] << 8 ) ;
if ( V_509 & V_524 )
V_510 = 0 ;
}
V_21 = F_26 ( V_18 , L_227 ,
V_510 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_228 , V_21 ) ;
goto exit;
}
}
V_220 = ( V_252 | V_253 | V_312 ) ;
V_21 = F_26 ( V_18 , L_86 , V_496 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_214 , V_21 ) ;
goto exit;
}
V_21 = F_26 ( V_18 , L_73 , V_220 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_215 , V_21 ) ;
goto exit;
}
V_21 = F_26 ( V_18 , L_79 , V_269 , V_28 ) ;
if ( V_21 < 0 ) {
F_14 ( L_216 , V_21 ) ;
goto exit;
}
exit:
return V_21 ;
}
static T_6
F_164 ( T_2 * V_525 , T_4 V_526 ,
struct V_527 * V_528 )
{
T_6 V_21 = 0 ;
struct V_399 * V_529 ;
struct V_388 * V_223 ;
struct V_530 * V_531 ;
T_6 V_532 ;
V_532 = ( T_6 ) V_526 ;
memset ( V_528 , 0 , sizeof( * V_528 ) ) ;
V_223 = (struct V_388 * ) V_525 ;
while ( V_223 ) {
if ( V_223 -> V_392 != V_533 )
goto V_534;
V_529 = (struct V_399 * ) V_223 ;
if ( V_529 -> V_30 < ( V_511 - V_391 + 1 ) ) {
F_14 ( L_229 ,
V_529 -> V_30 ) ;
goto V_534;
}
if ( ! memcmp ( V_529 -> V_395 , ( T_2 * ) V_402 , V_403 ) &&
( ( V_529 -> V_535 == V_404 ) ||
( V_529 -> V_535 == V_536 ) ) ) {
F_20 ( L_230 ) ;
goto V_534;
}
V_531 = & V_528 -> V_537 [ V_528 -> V_184 ] ;
V_531 -> V_538 = ( char * ) V_529 ;
V_531 -> V_224 = V_529 -> V_30 + V_391 ;
memcpy ( & V_531 -> V_529 , V_529 , sizeof( * V_529 ) ) ;
V_528 -> V_184 ++ ;
F_20 ( L_231 ,
V_531 -> V_529 . V_395 [ 0 ] ,
V_531 -> V_529 . V_395 [ 1 ] ,
V_531 -> V_529 . V_395 [ 2 ] ,
V_531 -> V_529 . V_535 ) ;
if ( V_528 -> V_184 >= V_539 )
break;
V_534:
V_532 -= V_223 -> V_30 ;
if ( V_532 <= 2 )
V_223 = NULL ;
else
V_223 = (struct V_388 * ) ( ( ( T_2 * ) V_223 ) + V_223 -> V_30 ) ;
}
return V_21 ;
}
static T_4
F_165 ( T_2 * V_540 , T_6 V_541 , T_2 * V_538 , T_4 V_224 , T_7 * V_542 )
{
T_5 V_543 ;
T_5 V_544 ;
strncpy ( V_540 , V_542 , V_545 - 1 ) ;
V_540 [ V_545 - 1 ] = '\0' ;
V_543 = F_8 ( 1 ) ;
memcpy ( & V_540 [ V_546 ] , & V_543 , sizeof( V_543 ) ) ;
V_544 = F_8 ( V_541 ) ;
memcpy ( & V_540 [ V_547 ] , & V_544 , sizeof( V_544 ) ) ;
memcpy ( & V_540 [ V_548 ] , V_538 , V_224 ) ;
return V_224 + V_549 ;
}
T_6
F_166 ( struct V_2 * V_3 ,
struct V_17 * V_18 , T_6 V_28 , T_6 V_541 ,
T_2 * V_525 , T_4 V_526 )
{
T_6 V_21 = 0 ;
T_2 * V_550 ;
T_2 * V_551 ;
T_2 * V_552 = NULL ;
int V_553 ;
T_4 * V_554 = 0 ;
T_4 V_555 = 0 ;
T_4 V_556 = 0 ;
T_4 V_557 = 0 ;
struct V_527 V_558 ;
struct V_527 V_559 ;
struct V_530 * V_560 ;
T_6 V_144 ;
T_2 * V_149 ;
int V_561 ;
F_20 ( L_232 , V_28 , V_541 ) ;
V_550 = F_22 ( V_47 , V_68 ) ;
if ( ! V_550 )
return - V_29 ;
V_551 = V_550 ;
if ( F_3 ( V_66 , & V_3 -> V_5 ) ||
F_3 ( V_562 , & V_3 -> V_5 ) ) {
switch ( V_541 ) {
case V_563 :
V_552 = V_3 -> V_67 -> V_564 ;
V_554 = & V_3 -> V_67 -> V_565 ;
V_553 =
sizeof( V_3 -> V_67 -> V_564 ) ;
break;
case V_566 :
V_552 = V_3 -> V_67 -> V_567 ;
V_554 = & V_3 -> V_67 -> V_568 ;
V_553 = sizeof( V_3 -> V_67 -> V_567 ) ;
break;
default:
V_21 = - V_172 ;
F_14 ( L_233 ) ;
goto exit;
}
V_28 = 0 ;
} else {
V_21 = - V_172 ;
F_14 ( L_233 ) ;
goto exit;
}
if ( V_526 > V_553 ) {
V_21 = - V_29 ;
F_14 ( L_234 ) ;
goto exit;
}
if ( V_525 && V_526 && V_551 ) {
V_149 = V_551 ;
F_164 ( V_525 , V_526 , & V_559 ) ;
for ( V_144 = 0 ; V_144 < V_559 . V_184 ; V_144 ++ ) {
V_560 = & V_559 . V_537 [ V_144 ] ;
memcpy ( V_149 + V_557 , V_560 -> V_538 ,
V_560 -> V_224 ) ;
V_557 += V_560 -> V_224 ;
}
}
if ( V_552 != NULL ) {
if ( V_557 && ( V_557 == * V_554 ) &&
( memcmp ( V_552 , V_551 ,
V_557 ) == 0 ) ) {
F_20 ( L_235 ) ;
goto exit;
}
F_164 ( V_552 , * V_554 , & V_558 ) ;
for ( V_144 = 0 ; V_144 < V_558 . V_184 ; V_144 ++ ) {
V_560 = & V_558 . V_537 [ V_144 ] ;
F_20 ( L_236 ,
V_560 -> V_529 . V_392 ,
V_560 -> V_529 . V_30 ,
V_560 -> V_529 . V_395 [ 0 ] ,
V_560 -> V_529 . V_395 [ 1 ] ,
V_560 -> V_529 . V_395 [ 2 ] ) ;
V_555 = F_165 ( V_551 , V_541 ,
V_560 -> V_538 ,
V_560 -> V_224 ,
L_237 ) ;
V_551 += V_555 ;
V_556 += V_555 ;
}
}
* V_554 = 0 ;
if ( V_552 && V_557 ) {
V_149 = V_552 ;
V_561 = V_553 ;
for ( V_144 = 0 ; V_144 < V_559 . V_184 ; V_144 ++ ) {
V_560 = & V_559 . V_537 [ V_144 ] ;
F_20 ( L_238 ,
V_560 -> V_529 . V_392 ,
V_560 -> V_529 . V_30 ,
V_560 -> V_529 . V_395 [ 0 ] ,
V_560 -> V_529 . V_395 [ 1 ] ,
V_560 -> V_529 . V_395 [ 2 ] ) ;
V_555 = F_165 ( V_551 , V_541 ,
V_560 -> V_538 ,
V_560 -> V_224 ,
L_239 ) ;
V_561 -= V_560 -> V_224 ;
if ( V_561 < 0 ) {
F_14 ( L_240 ,
V_561 ) ;
break;
}
memcpy ( V_149 + ( * V_554 ) , V_560 -> V_538 ,
V_560 -> V_224 ) ;
* V_554 += V_560 -> V_224 ;
V_551 += V_555 ;
V_556 += V_555 ;
}
}
if ( V_556 ) {
V_21 = F_11 ( V_18 , L_241 ,
V_550 ,
V_556 ,
V_3 -> V_46 ,
V_47 , V_28 ) ;
if ( V_21 )
F_14 ( L_242 , V_21 ) ;
}
exit:
F_36 ( V_550 ) ;
return V_21 ;
}
static T_6
F_167 ( struct V_1 * V_1 , struct V_17 * V_18 ,
struct V_569 * V_570 )
{
T_6 V_376 ;
struct V_388 * V_571 ;
struct V_150 V_96 ;
T_6 V_572 ;
T_6 V_21 = - V_172 ;
struct V_388 * V_573 ;
struct V_399 * V_508 ;
struct V_209 V_210 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_6 V_28 = 0 ;
F_20 ( L_243 ,
V_570 -> V_574 , V_570 -> V_225 ,
V_570 -> V_406 ) ;
F_20 ( L_244 ,
V_570 -> V_83 , V_570 -> V_138 , V_570 -> V_247 ,
V_570 -> V_575 ) ;
if ( ! F_3 ( V_66 , & V_3 -> V_5 ) ) {
F_14 ( L_245 ) ;
return - V_172 ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
if ( V_570 -> V_83 == NULL || V_570 -> V_138 == 0 ) {
V_376 = V_576 + V_577 ;
V_571 = F_103 (
( T_2 * ) & V_570 -> V_578 . V_579 [ V_376 ] ,
V_570 -> V_578 . V_580 - V_376 ,
V_581 ) ;
if ( ! V_571 )
return - V_64 ;
memcpy ( V_96 . V_97 , V_571 -> V_44 , V_571 -> V_30 ) ;
V_96 . V_95 = F_8 ( V_571 -> V_30 ) ;
F_20 ( L_246 , V_96 . V_97 ) ;
} else {
memcpy ( V_96 . V_97 , V_570 -> V_83 , V_570 -> V_138 ) ;
V_96 . V_95 = F_8 ( ( T_4 ) V_570 -> V_138 ) ;
}
F_29 ( V_18 , 0 ) ;
V_572 = 1 ;
V_21 = F_7 ( V_18 , V_582 , & V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_247 , V_21 ) ;
goto exit;
}
V_572 = 1 ;
V_21 = F_7 ( V_18 , V_69 , & V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_248 , V_21 ) ;
goto exit;
}
V_572 = 1 ;
V_21 = F_7 ( V_18 , V_583 , & V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_249 , V_21 ) ;
goto exit;
}
V_573 = F_103 ( ( T_2 * ) V_570 -> V_578 . V_584 ,
V_570 -> V_578 . V_585 , V_586 ) ;
V_508 = F_105 ( ( T_2 * ) V_570 -> V_578 . V_584 ,
V_570 -> V_578 . V_585 ) ;
F_36 ( V_3 -> V_67 -> V_573 ) ;
V_3 -> V_67 -> V_573 = NULL ;
F_36 ( V_3 -> V_67 -> V_508 ) ;
V_3 -> V_67 -> V_508 = NULL ;
if ( ( V_508 != NULL || V_573 != NULL ) ) {
F_20 ( L_250 ) ;
if ( V_508 != NULL ) {
V_21 = F_163 ( V_18 , V_508 , false ,
V_28 ) ;
if ( V_21 < 0 )
goto exit;
V_3 -> V_67 -> V_508 = F_168 ( V_508 ,
V_508 -> V_30 +
V_391 ,
V_68 ) ;
} else {
V_21 = F_163 ( V_18 ,
(struct V_399 * ) V_573 , true , V_28 ) ;
if ( V_21 < 0 )
goto exit;
V_3 -> V_67 -> V_573 = F_168 ( V_573 ,
V_573 -> V_30 +
V_391 ,
V_68 ) ;
}
V_3 -> V_67 -> V_587 = true ;
} else {
F_20 ( L_251 ) ;
F_161 ( V_18 , V_28 ) ;
V_3 -> V_67 -> V_587 = false ;
}
V_21 = F_166 ( V_3 , V_18 , V_28 ,
V_566 ,
( T_2 * ) V_570 -> V_578 . V_584 ,
V_570 -> V_578 . V_585 ) ;
if ( V_21 )
F_14 ( L_252 ) ;
else
F_20 ( L_253 ) ;
V_21 = F_166 ( V_3 , V_18 , V_28 ,
V_563 ,
( T_2 * ) V_570 -> V_578 . V_588 ,
V_570 -> V_578 . V_589 ) ;
if ( V_21 )
F_14 ( L_254 ) ;
else
F_20 ( L_255 ) ;
if ( V_570 -> V_225 ) {
V_572 = V_570 -> V_225 ;
V_21 = F_7 ( V_18 , V_590 ,
& V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_256 , V_21 ) ;
goto exit;
}
}
if ( V_570 -> V_406 ) {
V_572 = V_570 -> V_406 ;
V_21 = F_7 ( V_18 , V_591 ,
& V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_257 , V_21 ) ;
goto exit;
}
}
V_572 = 1 ;
V_21 = F_7 ( V_18 , V_592 , & V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_258 , V_21 ) ;
goto exit;
}
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
memcpy ( & V_210 . V_96 , & V_96 , sizeof( V_96 ) ) ;
V_21 = F_9 ( V_18 , V_233 , & V_210 ,
sizeof( V_210 ) ) ;
if ( V_21 < 0 ) {
F_14 ( L_259 , V_21 ) ;
goto exit;
}
F_44 ( V_66 , & V_3 -> V_5 ) ;
F_21 ( V_562 , & V_3 -> V_5 ) ;
exit:
if ( V_21 )
F_29 ( V_18 , 1 ) ;
return V_21 ;
}
static int F_169 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_6 V_572 ;
T_6 V_21 = - V_172 ;
F_20 ( L_35 ) ;
if ( V_3 -> V_57 -> V_58 == V_63 ) {
F_137 ( 400 ) ;
V_572 = 0 ;
V_21 = F_7 ( V_18 , V_583 , & V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_249 , V_21 ) ;
goto exit;
}
V_572 = 0 ;
V_21 = F_7 ( V_18 , V_592 , & V_572 ) ;
if ( V_21 < 0 ) {
F_14 ( L_260 , V_21 ) ;
goto exit;
}
F_29 ( V_18 , 1 ) ;
F_44 ( V_66 , & V_3 -> V_5 ) ;
F_44 ( V_562 , & V_3 -> V_5 ) ;
}
exit:
return V_21 ;
}
static int
F_170 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_2 * V_313 )
{
struct V_279 V_280 ;
T_6 V_21 ;
if ( ! V_313 )
return - V_593 ;
F_20 ( L_261 , V_313 ) ;
if ( ! F_1 ( V_1 ) )
return - V_191 ;
memcpy ( & V_280 . V_45 , V_313 , V_86 ) ;
V_280 . V_73 = F_8 ( V_594 ) ;
V_21 = F_9 ( V_18 , V_595 ,
& V_280 , sizeof( V_280 ) ) ;
if ( V_21 )
F_14 ( L_262 , V_21 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6 F_171 ( T_6 V_58 )
{
T_6 V_21 = 0 ;
switch ( V_58 ) {
case V_61 :
return V_60 ;
case V_59 :
return V_56 ;
default:
return V_596 ;
}
return V_21 ;
}
static void F_172 ( struct V_1 * V_1 )
{
#ifndef F_173
V_1 -> V_597 = V_598 ;
V_1 -> V_599 = V_598 ;
V_1 -> V_600 = V_601 ;
V_1 -> V_39 |= V_602 ;
#endif
}
static struct V_603 * F_174 ( struct V_604 * V_18 )
{
struct V_603 * V_189 ;
T_6 V_21 = 0 ;
V_189 = F_22 ( sizeof( * V_189 ) , V_68 ) ;
if ( ! V_189 )
return F_175 ( - V_29 ) ;
V_189 -> V_1 = F_176 ( & V_605 ,
sizeof( struct V_2 ) ) ;
if ( ! V_189 -> V_1 ) {
F_14 ( L_263 ) ;
V_21 = - V_29 ;
goto V_606;
}
F_177 ( V_189 -> V_1 , V_18 ) ;
V_189 -> V_1 -> V_607 = V_608 ;
V_189 -> V_1 -> V_609 = V_466 ;
V_189 -> V_1 -> V_445 = F_132 ( V_60 ) |
F_132 ( V_56 ) |
F_132 ( V_62 ) ;
V_189 -> V_1 -> V_373 [ V_154 ] = & V_610 ;
V_189 -> V_1 -> V_373 [ V_354 ] = & V_611 ;
V_189 -> V_1 -> V_612 = V_613 ;
V_189 -> V_1 -> V_614 = V_615 ;
V_189 -> V_1 -> V_616 = F_178 ( V_615 ) ;
V_189 -> V_1 -> V_39 |= V_617 ;
F_172 ( V_189 -> V_1 ) ;
V_21 = F_179 ( V_189 -> V_1 ) ;
if ( V_21 < 0 ) {
F_14 ( L_264 , V_21 ) ;
goto V_618;
}
return V_189 ;
V_618:
F_180 ( V_189 -> V_1 ) ;
V_606:
F_36 ( V_189 ) ;
return F_175 ( V_21 ) ;
}
static void F_181 ( struct V_2 * V_3 )
{
struct V_603 * V_189 = V_3 -> V_189 ;
if ( ! V_189 ) {
F_14 ( L_265 ) ;
return;
}
F_182 ( V_189 -> V_1 ) ;
F_180 ( V_189 -> V_1 ) ;
F_36 ( V_189 ) ;
V_3 -> V_189 = NULL ;
}
static bool F_183 ( struct V_2 * V_3 ,
const struct V_438 * V_439 )
{
T_4 V_619 = F_131 ( V_439 -> V_474 ) ;
T_4 V_5 = F_131 ( V_439 -> V_5 ) ;
if ( V_619 == V_620 && V_5 == V_448 ) {
F_65 ( L_266 ) ;
V_3 -> V_216 = true ;
return true ;
}
return false ;
}
static bool F_184 ( struct V_2 * V_3 ,
const struct V_438 * V_439 )
{
T_4 V_619 = F_131 ( V_439 -> V_474 ) ;
T_1 V_39 = F_185 ( V_439 -> V_39 ) ;
if ( V_619 == V_621 && ( ! ( V_39 & V_622 ) ) ) {
F_65 ( L_267 ) ;
return true ;
}
return false ;
}
static bool F_186 ( struct V_2 * V_3 ,
const struct V_438 * V_439 )
{
T_4 V_619 = F_131 ( V_439 -> V_474 ) ;
T_4 V_5 = F_131 ( V_439 -> V_5 ) ;
if ( V_619 == V_621 && V_5 == V_623 ) {
F_65 ( L_268 ,
F_185 ( V_439 -> V_39 ) & V_622 ?
L_269 : L_270 ) ;
return true ;
}
if ( V_619 == V_620 && V_5 != V_448 ) {
F_65 ( L_271 ) ;
return true ;
}
return false ;
}
static void F_187 ( struct V_2 * V_3 )
{
struct V_624 * V_625 = F_188 ( V_3 ) ;
F_36 ( V_625 -> V_626 ) ;
V_625 -> V_626 = NULL ;
V_625 -> V_627 = 0 ;
F_36 ( V_625 -> V_628 ) ;
V_625 -> V_628 = NULL ;
V_625 -> V_629 = 0 ;
}
static T_6 F_189 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_39 ( V_3 ) ;
struct V_630 * V_631 ;
struct V_624 * V_625 = F_188 ( V_3 ) ;
T_4 V_632 ;
T_4 V_633 ;
T_6 V_21 = 0 ;
F_187 ( V_3 ) ;
V_21 = F_141 ( V_18 , L_272 , V_3 -> V_46 ,
V_634 ) ;
if ( V_21 ) {
F_14 ( L_273 , V_21 ) ;
return V_21 ;
}
V_631 =
(struct V_630 * ) V_3 -> V_46 ;
V_632 = F_10 ( V_631 -> V_632 ) ;
V_633 = F_10 ( V_631 -> V_633 ) ;
if ( V_632 ) {
V_21 = F_141 ( V_18 , L_274 ,
V_3 -> V_46 ,
V_634 ) ;
if ( V_21 ) {
F_14 ( L_275 , V_21 ) ;
return V_21 ;
}
V_625 -> V_627 = V_632 ;
V_625 -> V_626 =
F_168 ( V_3 -> V_46 , V_625 -> V_627 ,
V_68 ) ;
} else {
V_625 -> V_627 = 0 ;
V_625 -> V_626 = NULL ;
}
if ( V_633 ) {
V_21 = F_141 ( V_18 , L_276 ,
V_3 -> V_46 ,
V_634 ) ;
if ( V_21 ) {
F_14 ( L_277 , V_21 ) ;
return V_21 ;
}
V_625 -> V_629 = V_633 ;
V_625 -> V_628 =
F_168 ( V_3 -> V_46 , V_625 -> V_629 ,
V_68 ) ;
} else {
V_625 -> V_629 = 0 ;
V_625 -> V_628 = NULL ;
}
F_65 ( L_278 ,
V_625 -> V_627 , V_625 -> V_629 ) ;
return V_21 ;
}
static T_6
F_190 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 )
{
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_624 * V_625 = F_188 ( V_3 ) ;
struct V_1 * V_1 = F_52 ( V_3 ) ;
struct V_147 * V_360 = NULL ;
struct V_363 * V_153 ;
struct V_358 * V_359 ;
T_4 V_364 ;
T_6 V_21 = 0 ;
T_4 V_230 ;
T_2 * V_26 ;
F_20 ( L_35 ) ;
F_189 ( V_3 ) ;
memcpy ( V_219 -> V_84 , V_439 -> V_345 , V_86 ) ;
F_106 ( V_3 ) ;
V_26 = F_22 ( V_371 , V_68 ) ;
if ( V_26 == NULL ) {
V_21 = - V_29 ;
goto V_65;
}
* ( T_5 * ) V_26 = F_8 ( V_371 ) ;
V_21 = F_9 ( V_18 , V_387 , V_26 , V_371 ) ;
if ( V_21 )
goto V_65;
V_359 = (struct V_358 * ) ( V_26 + 4 ) ;
V_230 = V_359 -> V_372 ? V_359 -> V_372 :
F_93 ( F_94 ( V_359 -> V_145 ) ) ;
if ( V_230 <= V_212 )
V_153 = V_1 -> V_373 [ V_154 ] ;
else
V_153 = V_1 -> V_373 [ V_354 ] ;
V_364 = F_95 ( V_230 , V_153 -> V_153 ) ;
V_360 = F_96 ( V_1 , V_364 ) ;
V_65:
F_36 ( V_26 ) ;
F_191 ( V_18 , V_360 , ( T_2 * ) V_219 -> V_84 ,
V_625 -> V_626 , V_625 -> V_627 ,
V_625 -> V_628 , V_625 -> V_629 , V_68 ) ;
F_65 ( L_279 ) ;
F_21 ( V_281 , & V_3 -> V_5 ) ;
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_192 ( struct V_2 * V_3 ,
struct V_17 * V_18 , const struct V_438 * V_439 ,
bool V_635 )
{
struct V_206 * V_219 = V_3 -> V_219 ;
struct V_624 * V_625 = F_188 ( V_3 ) ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
if ( F_54 ( V_136 , & V_3 -> V_5 ) ) {
if ( V_635 ) {
F_189 ( V_3 ) ;
memcpy ( V_219 -> V_84 , V_439 -> V_345 , V_86 ) ;
F_106 ( V_3 ) ;
}
F_193 ( V_18 ,
( T_2 * ) V_219 -> V_84 ,
V_625 -> V_626 ,
V_625 -> V_627 ,
V_625 -> V_628 ,
V_625 -> V_629 ,
V_635 ? V_636 :
V_637 ,
V_68 ) ;
if ( V_635 )
F_21 ( V_281 , & V_3 -> V_5 ) ;
F_65 ( L_280 ,
V_635 ? L_281 : L_211 ) ;
}
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_194 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
T_6 V_21 = 0 ;
T_4 V_619 = F_131 ( V_439 -> V_474 ) ;
T_4 V_638 = F_131 ( V_439 -> V_638 ) ;
T_4 V_30 = F_131 ( V_439 -> V_639 ) ;
static int V_640 ;
struct V_314 V_315 ;
F_65 ( L_282 , V_619 , V_638 ) ;
memset ( & V_315 , 0 , sizeof( V_315 ) ) ;
V_315 . V_322 = 0 ;
if ( ( ( V_619 == V_641 ) || ( V_619 == V_642 ) ) &&
V_638 == V_448 ) {
V_315 . V_322 = V_643 ;
if ( ! V_44 ) {
F_14 ( L_283 ) ;
return - V_64 ;
}
V_315 . V_644 = V_44 ;
V_315 . V_645 = V_30 ;
V_640 ++ ;
V_315 . V_640 = V_640 ;
F_195 ( V_18 , V_439 -> V_345 , & V_315 , V_646 ) ;
} else if ( ( V_619 == V_647 ) ||
( V_619 == V_648 ) ||
( V_619 == V_649 ) ) {
V_640 ++ ;
V_315 . V_640 = V_640 ;
F_196 ( V_18 , V_439 -> V_345 , V_646 ) ;
}
return V_21 ;
}
static T_6
F_197 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
struct V_206 * V_219 = V_3 -> V_219 ;
T_6 V_21 = 0 ;
if ( V_3 -> V_57 -> V_58 == V_63 ) {
V_21 = F_194 ( V_3 , V_18 , V_439 , V_44 ) ;
} else if ( F_183 ( V_3 , V_439 ) ) {
F_65 ( L_284 ) ;
if ( F_102 ( V_3 ) ) {
memcpy ( V_219 -> V_84 , V_439 -> V_345 , V_86 ) ;
F_101 ( V_3 , V_18 , V_439 -> V_345 ) ;
F_198 ( V_18 , V_439 -> V_345 , V_68 ) ;
F_44 ( V_136 , & V_3 -> V_5 ) ;
F_21 ( V_281 , & V_3 -> V_5 ) ;
} else
F_192 ( V_3 , V_18 , V_439 , true ) ;
} else if ( F_184 ( V_3 , V_439 ) ) {
F_65 ( L_285 ) ;
if ( F_102 ( V_3 ) ) {
F_44 ( V_136 , & V_3 -> V_5 ) ;
if ( F_54 ( V_281 ,
& V_3 -> V_5 ) )
F_66 ( V_3 ) ;
} else {
F_192 ( V_3 , V_18 , V_439 , false ) ;
if ( F_54 ( V_281 ,
& V_3 -> V_5 ) ) {
F_199 ( V_18 , 0 , NULL , 0 ,
V_68 ) ;
F_66 ( V_3 ) ;
}
}
F_63 ( V_3 -> V_219 ) ;
} else if ( F_186 ( V_3 , V_439 ) ) {
if ( F_102 ( V_3 ) )
F_44 ( V_136 , & V_3 -> V_5 ) ;
else
F_192 ( V_3 , V_18 , V_439 , false ) ;
}
return V_21 ;
}
static T_6
F_200 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
T_6 V_21 = 0 ;
T_4 V_619 = F_131 ( V_439 -> V_474 ) ;
T_4 V_5 = F_131 ( V_439 -> V_5 ) ;
if ( V_619 == V_650 && V_5 == V_448 ) {
if ( F_3 ( V_281 , & V_3 -> V_5 ) )
F_190 ( V_3 , V_18 , V_439 ) ;
else
F_192 ( V_3 , V_18 , V_439 , true ) ;
}
return V_21 ;
}
static T_6
F_201 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
T_1 V_39 = F_185 ( V_439 -> V_39 ) ;
enum V_651 V_652 ;
if ( V_39 & V_653 )
V_652 = V_654 ;
else
V_652 = V_655 ;
F_202 ( V_18 , ( T_2 * ) & V_439 -> V_345 , V_652 , - 1 ,
NULL , V_68 ) ;
return 0 ;
}
static T_6
F_203 ( struct V_2 * V_3 ,
struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
struct V_656 V_657 ;
struct V_415 * V_658 ;
T_4 V_30 = V_659 ;
T_6 V_21 = 0 ;
bool V_660 = false ;
T_4 V_661 ;
F_20 ( L_35 ) ;
if ( V_3 -> V_137 && V_3 -> V_117 ) {
F_20 ( L_12 ) ;
return F_111 ( F_38 ( V_3 ) ) ;
}
if ( ! F_54 ( V_134 , & V_3 -> V_5 ) ) {
F_14 ( L_42 ) ;
V_660 = true ;
V_21 = - V_64 ;
goto V_662;
}
V_21 = F_9 ( V_18 , V_663 , & V_657 ,
sizeof( V_657 ) ) ;
if ( V_21 ) {
F_14 ( L_286 , V_21 ) ;
V_660 = true ;
goto V_662;
}
V_661 = F_10 ( V_657 . V_661 ) ;
if ( V_661 )
F_65 ( L_287 , V_661 ) ;
V_3 -> V_383 = V_3 -> V_664 ;
V_658 = (struct V_415 * ) V_3 -> V_383 ;
memset ( V_3 -> V_664 , 0 , V_30 ) ;
V_658 -> V_27 = F_8 ( V_30 ) ;
V_21 = F_9 ( V_18 , V_665 ,
V_3 -> V_664 , V_30 ) ;
if ( V_21 ) {
F_14 ( L_288 , V_18 -> V_23 , V_21 ) ;
V_21 = - V_64 ;
V_660 = true ;
goto V_662;
}
V_3 -> V_664 -> V_27 = F_10 ( V_658 -> V_27 ) ;
V_3 -> V_664 -> V_107 = F_10 ( V_658 -> V_107 ) ;
V_3 -> V_664 -> V_184 = F_10 ( V_658 -> V_184 ) ;
V_21 = F_100 ( V_3 ) ;
if ( V_21 )
V_660 = true ;
V_662:
if ( V_3 -> V_139 ) {
F_42 ( L_289 ) ;
F_53 ( V_3 -> V_139 , V_660 ) ;
F_29 ( V_18 , 1 ) ;
V_3 -> V_139 = NULL ;
}
F_20 ( L_12 ) ;
return V_21 ;
}
static void F_204 ( struct V_666 * V_57 )
{
V_57 -> V_58 = ( T_4 ) - 1 ;
V_57 -> V_194 = ( T_4 ) - 1 ;
V_57 -> V_193 = ( T_4 ) - 1 ;
V_57 -> V_205 = ( T_4 ) - 1 ;
V_57 -> V_203 = ( T_4 ) - 1 ;
V_57 -> V_292 = - 1 ;
}
static void F_205 ( struct V_667 * V_425 )
{
memset ( V_425 , 0 , sizeof( * V_425 ) ) ;
V_425 -> V_428 [ V_668 ] = F_203 ;
V_425 -> V_428 [ V_621 ] = F_197 ;
V_425 -> V_428 [ V_648 ] = F_197 ;
V_425 -> V_428 [ V_649 ] = F_197 ;
V_425 -> V_428 [ V_647 ] = F_197 ;
V_425 -> V_428 [ V_641 ] = F_197 ;
V_425 -> V_428 [ V_642 ] = F_197 ;
V_425 -> V_428 [ V_650 ] = F_200 ;
V_425 -> V_428 [ V_669 ] = F_201 ;
V_425 -> V_428 [ V_620 ] = F_197 ;
V_425 -> V_428 [ V_670 ] = F_146 ;
}
static void F_206 ( struct V_2 * V_3 )
{
F_36 ( V_3 -> V_664 ) ;
V_3 -> V_664 = NULL ;
F_36 ( V_3 -> V_671 ) ;
V_3 -> V_671 = NULL ;
F_36 ( V_3 -> V_57 ) ;
V_3 -> V_57 = NULL ;
F_36 ( V_3 -> V_219 ) ;
V_3 -> V_219 = NULL ;
F_36 ( V_3 -> V_131 ) ;
V_3 -> V_131 = NULL ;
F_36 ( V_3 -> V_177 ) ;
V_3 -> V_177 = NULL ;
F_36 ( V_3 -> V_110 ) ;
V_3 -> V_110 = NULL ;
F_36 ( V_3 -> V_46 ) ;
V_3 -> V_46 = NULL ;
F_36 ( V_3 -> V_102 ) ;
V_3 -> V_102 = NULL ;
F_36 ( V_3 -> V_455 ) ;
V_3 -> V_455 = NULL ;
if ( V_3 -> V_67 ) {
F_36 ( V_3 -> V_67 -> V_508 ) ;
F_36 ( V_3 -> V_67 -> V_573 ) ;
F_36 ( V_3 -> V_67 ) ;
V_3 -> V_67 = NULL ;
}
}
static T_6 F_207 ( struct V_2 * V_3 )
{
V_3 -> V_664 = F_22 ( V_659 , V_68 ) ;
if ( ! V_3 -> V_664 )
goto V_672;
V_3 -> V_57 = F_22 ( sizeof( * V_3 -> V_57 ) , V_68 ) ;
if ( ! V_3 -> V_57 )
goto V_672;
V_3 -> V_219 = F_22 ( sizeof( * V_3 -> V_219 ) , V_68 ) ;
if ( ! V_3 -> V_219 )
goto V_672;
V_3 -> V_671 = F_22 ( V_371 , V_68 ) ;
if ( ! V_3 -> V_671 )
goto V_672;
V_3 -> V_131 = F_22 ( sizeof( * V_3 -> V_131 ) ,
V_68 ) ;
if ( ! V_3 -> V_131 )
goto V_672;
V_3 -> V_177 = F_22 ( V_174 , V_68 ) ;
if ( ! V_3 -> V_177 )
goto V_672;
V_3 -> V_110 = F_22 ( V_321 , V_68 ) ;
if ( ! V_3 -> V_110 )
goto V_672;
V_3 -> V_46 = F_22 ( V_47 , V_68 ) ;
if ( ! V_3 -> V_46 )
goto V_672;
V_3 -> V_102 = F_22 ( sizeof( * V_3 -> V_102 ) , V_68 ) ;
if ( ! V_3 -> V_102 )
goto V_672;
V_3 -> V_455 = F_22 ( sizeof( * V_3 -> V_455 ) , V_68 ) ;
if ( ! V_3 -> V_455 )
goto V_672;
return 0 ;
V_672:
F_206 ( V_3 ) ;
return - V_29 ;
}
static struct V_673 * F_208 (
struct V_2 * V_3 )
{
struct V_673 * V_439 = NULL ;
F_209 ( & V_3 -> V_674 ) ;
if ( ! F_210 ( & V_3 -> V_675 ) ) {
V_439 = F_211 ( & V_3 -> V_675 ,
struct V_673 , V_675 ) ;
F_212 ( & V_439 -> V_675 ) ;
}
F_213 ( & V_3 -> V_674 ) ;
return V_439 ;
}
static T_6
F_214 ( struct V_2 * V_3 , T_4 V_619 ,
const struct V_438 * V_676 , void * V_44 )
{
struct V_673 * V_439 ;
T_6 V_21 = 0 ;
T_11 V_39 ;
T_4 V_677 ;
T_4 V_678 ;
V_678 = sizeof( struct V_673 ) ;
if ( V_44 )
V_677 = F_131 ( V_676 -> V_639 ) ;
else
V_677 = 0 ;
V_678 += V_677 ;
V_439 = F_22 ( V_678 , V_646 ) ;
if ( ! V_439 )
return - V_29 ;
V_439 -> V_679 = V_619 ;
memcpy ( & V_439 -> V_680 , V_676 , sizeof( struct V_438 ) ) ;
if ( V_44 )
memcpy ( & V_439 -> V_681 , V_44 , V_677 ) ;
F_215 ( & V_3 -> V_674 , V_39 ) ;
F_216 ( & V_439 -> V_675 , & V_3 -> V_675 ) ;
F_217 ( & V_3 -> V_674 , V_39 ) ;
return V_21 ;
}
static void F_218 ( struct V_673 * V_439 )
{
F_36 ( V_439 ) ;
}
static void F_219 ( struct V_423 * V_411 )
{
struct V_2 * V_3 =
F_119 ( V_411 , struct V_2 ,
V_682 ) ;
struct V_673 * V_439 ;
V_439 = F_208 ( V_3 ) ;
if ( F_220 ( ! V_439 ) ) {
F_14 ( L_290 ) ;
return;
}
do {
F_4 ( L_291 , V_439 -> V_679 ) ;
if ( V_3 -> V_425 . V_428 [ V_439 -> V_679 ] )
V_3 -> V_425 . V_428 [ V_439 -> V_679 ] ( V_3 ,
F_39 ( V_3 ) ,
& V_439 -> V_680 , V_439 -> V_681 ) ;
else
F_4 ( L_292 , V_439 -> V_679 ) ;
F_218 ( V_439 ) ;
} while ( ( V_439 = F_208 ( V_3 ) ) );
}
static void F_221 ( struct V_2 * V_3 )
{
F_222 ( & V_3 -> V_674 ) ;
F_223 ( & V_3 -> V_675 ) ;
}
static void F_224 ( struct V_2 * V_3 )
{
struct V_673 * V_439 ;
F_209 ( & V_3 -> V_674 ) ;
while ( ! F_210 ( & V_3 -> V_675 ) ) {
V_439 = F_211 ( & V_3 -> V_675 ,
struct V_673 , V_675 ) ;
F_212 ( & V_439 -> V_675 ) ;
F_36 ( V_439 ) ;
}
F_213 ( & V_3 -> V_674 ) ;
}
static T_6 F_225 ( struct V_2 * V_3 )
{
T_6 V_21 = 0 ;
V_3 -> V_139 = NULL ;
V_3 -> V_340 = true ;
#ifdef F_173
V_3 -> V_137 = true ;
V_3 -> V_192 = false ;
#else
V_3 -> V_137 = false ;
V_3 -> V_192 = true ;
#endif
V_3 -> V_683 = true ;
V_3 -> V_117 = false ;
V_3 -> V_115 = true ;
V_3 -> V_684 = false ;
F_221 ( V_3 ) ;
V_21 = F_207 ( V_3 ) ;
if ( V_21 )
return V_21 ;
F_122 ( & V_3 -> V_682 , F_219 ) ;
F_205 ( & V_3 -> V_425 ) ;
F_226 ( & V_3 -> V_685 ) ;
V_21 = F_124 ( V_3 ) ;
if ( V_21 )
return V_21 ;
F_133 ( V_3 ) ;
F_204 ( V_3 -> V_57 ) ;
F_63 ( V_3 -> V_219 ) ;
F_66 ( V_3 ) ;
return V_21 ;
}
static void F_227 ( struct V_2 * V_3 )
{
F_108 ( & V_3 -> V_682 ) ;
V_3 -> V_684 = false ;
F_224 ( V_3 ) ;
F_66 ( V_3 ) ;
F_107 ( V_3 ) ;
F_206 ( V_3 ) ;
}
struct V_2 * F_228 ( struct V_17 * V_18 ,
struct V_604 * V_686 ,
struct V_687 * V_688 )
{
struct V_603 * V_189 ;
struct V_2 * V_3 ;
T_6 V_21 = 0 ;
if ( ! V_18 ) {
F_14 ( L_293 ) ;
return NULL ;
}
V_189 = F_174 ( V_686 ) ;
if ( F_229 ( V_189 ) ) {
return NULL ;
}
V_189 -> V_72 = F_171 ( V_61 ) ;
V_3 = F_230 ( V_189 ) ;
V_3 -> V_189 = V_189 ;
V_3 -> V_689 = V_688 ;
V_18 -> V_71 = V_189 ;
F_231 ( V_18 , F_232 ( V_189 -> V_1 ) ) ;
V_189 -> V_190 = V_18 ;
V_21 = F_225 ( V_3 ) ;
if ( V_21 ) {
F_14 ( L_294 , V_21 ) ;
goto V_690;
}
return V_3 ;
V_690:
F_181 ( V_3 ) ;
return NULL ;
}
void F_233 ( struct V_2 * V_3 )
{
F_227 ( V_3 ) ;
F_181 ( V_3 ) ;
}
void
F_234 ( struct V_17 * V_18 ,
const struct V_438 * V_439 , void * V_44 )
{
T_4 V_474 = F_131 ( V_439 -> V_474 ) ;
struct V_2 * V_3 = F_30 ( V_18 ) ;
if ( ! F_214 ( V_3 , V_474 , V_439 , V_44 ) )
F_112 ( & V_3 -> V_682 ) ;
}
static T_6 F_235 ( struct V_17 * V_18 )
{
T_7 V_480 [ V_691 + 12 ] ;
T_7 V_692 [ V_691 ] ;
T_6 V_21 = 0 ;
F_20 ( L_35 ) ;
F_24 ( L_295 , V_692 , V_691 ,
V_480 , sizeof( V_480 ) ) ;
V_21 = F_9 ( V_18 , V_32 , V_480 , sizeof( V_480 ) ) ;
if ( V_21 ) {
F_14 ( L_296 , V_21 ) ;
goto V_693;
}
memcpy ( V_692 , V_480 , V_691 ) ;
F_236 ( V_692 , V_620 ) ;
F_236 ( V_692 , V_650 ) ;
F_236 ( V_692 , V_694 ) ;
F_236 ( V_692 , V_695 ) ;
F_236 ( V_692 , V_696 ) ;
F_236 ( V_692 , V_642 ) ;
F_236 ( V_692 , V_648 ) ;
F_236 ( V_692 , V_647 ) ;
F_236 ( V_692 , V_697 ) ;
F_236 ( V_692 , V_698 ) ;
F_236 ( V_692 , V_641 ) ;
F_236 ( V_692 , V_699 ) ;
F_236 ( V_692 , V_621 ) ;
F_236 ( V_692 , V_700 ) ;
F_236 ( V_692 , V_669 ) ;
F_236 ( V_692 , V_701 ) ;
F_236 ( V_692 , V_702 ) ;
F_236 ( V_692 , V_703 ) ;
F_236 ( V_692 , V_668 ) ;
F_236 ( V_692 , V_449 ) ;
F_236 ( V_692 , V_670 ) ;
F_24 ( L_295 , V_692 , V_691 ,
V_480 , sizeof( V_480 ) ) ;
V_21 = F_9 ( V_18 , V_31 , V_480 , sizeof( V_480 ) ) ;
if ( V_21 ) {
F_14 ( L_297 , V_21 ) ;
goto V_693;
}
V_693:
F_20 ( L_12 ) ;
return V_21 ;
}
static T_6
F_237 ( struct V_17 * V_18 , T_4 V_704 , T_4 V_705 )
{
T_7 V_480 [ 32 ] ;
T_6 V_21 = 0 ;
T_5 V_706 [ 2 ] ;
T_5 V_707 [ 2 ] ;
T_5 V_708 ;
T_5 V_709 ;
if ( V_704 ) {
V_708 = F_8 ( V_705 ) ;
F_24 ( L_298 , ( char * ) & V_708 ,
sizeof( V_708 ) , V_480 , sizeof( V_480 ) ) ;
V_21 = F_9 ( V_18 , V_31 ,
V_480 , sizeof( V_480 ) ) ;
if ( V_21 ) {
F_14 ( L_299 , V_21 ) ;
goto V_710;
}
}
F_4 ( L_300 , V_704 ? L_301 : L_302 ) ;
V_709 = F_8 ( V_704 ) ;
F_24 ( L_303 , ( char * ) & V_709 ,
sizeof( V_709 ) , V_480 , sizeof( V_480 ) ) ;
V_21 = F_9 ( V_18 , V_31 , V_480 , sizeof( V_480 ) ) ;
if ( V_21 ) {
F_14 ( L_304 , V_21 ) ;
goto V_710;
}
V_706 [ 0 ] = F_8 ( V_711 ) ;
V_706 [ 1 ] = F_8 ( V_712 ) ;
V_21 = F_9 ( V_18 , V_713 ,
( void * ) V_706 , sizeof( V_706 ) ) ;
if ( V_21 ) {
F_14 ( L_305 , V_21 ) ;
goto V_710;
}
V_707 [ 0 ] = F_8 ( V_714 ) ;
V_707 [ 1 ] = F_8 ( V_712 ) ;
V_21 = F_9 ( V_18 , V_715 ,
( void * ) V_707 , sizeof( V_707 ) ) ;
if ( V_21 ) {
F_14 ( L_306 , V_21 ) ;
goto V_710;
}
V_710:
return V_21 ;
}
static T_6
F_238 ( struct V_17 * V_18 , T_6 V_716 ,
T_6 V_717 , T_6 V_718 )
{
T_6 V_21 = 0 ;
T_5 V_719 = F_8 ( V_716 ) ;
T_5 V_720 = F_8 ( V_717 ) ;
T_5 V_721 = F_8 ( V_718 ) ;
V_21 = F_9 ( V_18 , V_722 ,
& V_719 , sizeof( V_719 ) ) ;
if ( V_21 ) {
if ( V_21 == - V_55 )
F_4 ( L_307 ) ;
else
F_14 ( L_308 , V_21 ) ;
goto V_723;
}
V_21 = F_9 ( V_18 , V_724 ,
& V_720 , sizeof( V_720 ) ) ;
if ( V_21 ) {
if ( V_21 == - V_55 )
F_4 ( L_309 ) ;
else
F_14 ( L_310 , V_21 ) ;
goto V_723;
}
V_21 = F_9 ( V_18 , V_725 ,
& V_721 , sizeof( V_721 ) ) ;
if ( V_21 ) {
if ( V_21 == - V_55 )
F_4 ( L_311 ) ;
else
F_14 ( L_312 , V_21 ) ;
goto V_723;
}
V_723:
return V_21 ;
}
static T_6 F_239 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
T_6 V_726 ;
T_7 V_727 ;
T_6 V_21 = 0 ;
V_21 = F_9 ( F_39 ( V_3 ) , V_728 ,
& V_726 , sizeof( V_726 ) ) ;
if ( V_21 ) {
F_14 ( L_2 , V_21 ) ;
return V_21 ;
}
V_727 = ( ( char * ) & V_726 ) [ 0 ] ;
F_4 ( L_313 , V_727 ) ;
if ( V_727 == 'n' || V_727 == 'a' ) {
V_1 = F_52 ( V_3 ) ;
V_1 -> V_373 [ V_354 ] = & V_729 ;
}
return V_21 ;
}
static T_6 F_240 ( struct V_2 * V_3 )
{
return F_239 ( V_3 ) ;
}
static T_6 F_241 ( struct V_2 * V_3 )
{
struct V_17 * V_18 ;
struct V_603 * V_189 ;
T_6 V_730 ;
T_6 V_21 = 0 ;
if ( V_3 -> V_684 )
return V_21 ;
V_18 = F_39 ( V_3 ) ;
V_189 = V_18 -> V_71 ;
F_238 ( V_18 , V_731 ,
V_732 , V_733 ) ;
V_21 = F_235 ( V_18 ) ;
if ( V_21 )
goto V_734;
V_730 = V_3 -> V_340 ? V_341 : V_342 ;
V_21 = F_7 ( V_18 , V_343 , & V_730 ) ;
if ( V_21 )
goto V_734;
F_4 ( L_314 ,
( V_730 ? L_144 : L_145 ) ) ;
V_21 = F_237 ( V_18 , ( V_3 -> V_683 ? 0 : 1 ) ,
V_735 ) ;
if ( V_21 )
goto V_734;
V_21 = F_19 ( V_189 -> V_1 , V_18 , V_189 -> V_72 ,
NULL , NULL ) ;
if ( V_21 && V_21 != - V_736 )
goto V_734;
V_21 = F_240 ( V_3 ) ;
if ( V_21 )
goto V_734;
V_734:
V_3 -> V_684 = true ;
return V_21 ;
}
static int F_242 ( struct V_2 * V_3 )
{
char V_26 [ 10 + V_737 ] ;
struct V_738 * V_739 ;
T_6 V_21 = 0 ;
sprintf ( V_26 , L_315 , F_39 ( V_3 ) -> V_23 ) ;
V_3 -> V_740 = F_243 ( V_26 ,
F_52 ( V_3 ) -> V_740 ) ;
V_739 = F_244 ( L_316 , V_741 , V_3 -> V_740 ,
( T_1 * ) & V_3 -> V_219 -> V_225 ) ;
if ( ! V_739 ) {
V_21 = - V_29 ;
goto V_742;
}
V_739 = F_245 ( L_317 , V_741 , V_3 -> V_740 ,
( T_2 * ) & V_3 -> V_219 -> V_406 ) ;
if ( ! V_739 ) {
V_21 = - V_29 ;
goto V_742;
}
V_742:
return V_21 ;
}
static void F_246 ( struct V_2 * V_3 )
{
F_247 ( V_3 -> V_740 ) ;
V_3 -> V_740 = NULL ;
}
static T_6 F_248 ( struct V_2 * V_3 )
{
T_6 V_21 = 0 ;
F_21 ( V_4 , & V_3 -> V_5 ) ;
F_242 ( V_3 ) ;
V_21 = F_241 ( V_3 ) ;
if ( V_21 )
return V_21 ;
F_121 ( V_3 ) ;
return V_21 ;
}
static T_6 F_249 ( struct V_2 * V_3 )
{
if ( ( F_3 ( V_281 , & V_3 -> V_5 ) ||
F_3 ( V_136 , & V_3 -> V_5 ) ) &&
F_3 ( V_4 , & V_3 -> V_5 ) ) {
F_4 ( L_185 ) ;
F_66 ( V_3 ) ;
F_134 ( 500 ) ;
}
F_107 ( V_3 ) ;
F_44 ( V_4 , & V_3 -> V_5 ) ;
F_246 ( V_3 ) ;
return 0 ;
}
T_6 F_250 ( struct V_2 * V_3 )
{
T_6 V_21 = 0 ;
F_251 ( & V_3 -> V_685 ) ;
V_21 = F_248 ( V_3 ) ;
F_252 ( & V_3 -> V_685 ) ;
return V_21 ;
}
T_6 F_253 ( struct V_2 * V_3 )
{
T_6 V_21 = 0 ;
F_251 ( & V_3 -> V_685 ) ;
V_21 = F_249 ( V_3 ) ;
F_252 ( & V_3 -> V_685 ) ;
return V_21 ;
}
