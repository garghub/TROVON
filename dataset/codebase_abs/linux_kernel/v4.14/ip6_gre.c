static T_1 F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
return F_3 ( V_3 , V_4 ) ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 ,
const struct V_1 * V_8 , const struct V_1 * V_9 ,
T_2 V_10 , T_3 V_11 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
int V_13 = V_7 -> V_14 ;
unsigned int V_15 = F_1 ( V_8 ) ;
unsigned int V_16 = F_6 ( V_10 ) ;
struct V_5 * V_17 , * V_18 = NULL ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_22 = ( V_11 == F_8 ( V_23 ) ) ?
V_24 : V_25 ;
int V_26 , V_27 = 4 ;
F_9 (t, ign->tunnels_r_l[h0 ^ h1]) {
if ( ! F_10 ( V_9 , & V_17 -> V_28 . V_29 ) ||
! F_10 ( V_8 , & V_17 -> V_28 . V_30 ) ||
V_10 != V_17 -> V_28 . V_31 ||
! ( V_17 -> V_7 -> V_32 & V_33 ) )
continue;
if ( V_17 -> V_7 -> type != V_25 &&
V_17 -> V_7 -> type != V_22 )
continue;
V_26 = 0 ;
if ( V_17 -> V_28 . V_13 != V_13 )
V_26 |= 1 ;
if ( V_17 -> V_7 -> type != V_22 )
V_26 |= 2 ;
if ( V_26 == 0 )
return V_17 ;
if ( V_26 < V_27 ) {
V_18 = V_17 ;
V_27 = V_26 ;
}
}
F_9 (t, ign->tunnels_r[h0 ^ h1]) {
if ( ! F_10 ( V_8 , & V_17 -> V_28 . V_30 ) ||
V_10 != V_17 -> V_28 . V_31 ||
! ( V_17 -> V_7 -> V_32 & V_33 ) )
continue;
if ( V_17 -> V_7 -> type != V_25 &&
V_17 -> V_7 -> type != V_22 )
continue;
V_26 = 0 ;
if ( V_17 -> V_28 . V_13 != V_13 )
V_26 |= 1 ;
if ( V_17 -> V_7 -> type != V_22 )
V_26 |= 2 ;
if ( V_26 == 0 )
return V_17 ;
if ( V_26 < V_27 ) {
V_18 = V_17 ;
V_27 = V_26 ;
}
}
F_9 (t, ign->tunnels_l[h1]) {
if ( ( ! F_10 ( V_9 , & V_17 -> V_28 . V_29 ) &&
( ! F_10 ( V_9 , & V_17 -> V_28 . V_30 ) ||
! F_11 ( V_9 ) ) ) ||
V_10 != V_17 -> V_28 . V_31 ||
! ( V_17 -> V_7 -> V_32 & V_33 ) )
continue;
if ( V_17 -> V_7 -> type != V_25 &&
V_17 -> V_7 -> type != V_22 )
continue;
V_26 = 0 ;
if ( V_17 -> V_28 . V_13 != V_13 )
V_26 |= 1 ;
if ( V_17 -> V_7 -> type != V_22 )
V_26 |= 2 ;
if ( V_26 == 0 )
return V_17 ;
if ( V_26 < V_27 ) {
V_18 = V_17 ;
V_27 = V_26 ;
}
}
F_9 (t, ign->tunnels_wc[h1]) {
if ( V_17 -> V_28 . V_31 != V_10 ||
! ( V_17 -> V_7 -> V_32 & V_33 ) )
continue;
if ( V_17 -> V_7 -> type != V_25 &&
V_17 -> V_7 -> type != V_22 )
continue;
V_26 = 0 ;
if ( V_17 -> V_28 . V_13 != V_13 )
V_26 |= 1 ;
if ( V_17 -> V_7 -> type != V_22 )
V_26 |= 2 ;
if ( V_26 == 0 )
return V_17 ;
if ( V_26 < V_27 ) {
V_18 = V_17 ;
V_27 = V_26 ;
}
}
if ( V_18 )
return V_18 ;
V_7 = V_20 -> V_34 ;
if ( V_7 -> V_32 & V_33 )
return F_12 ( V_7 ) ;
return NULL ;
}
static struct V_5 T_4 * * F_13 ( struct V_19 * V_20 ,
const struct V_35 * V_36 )
{
const struct V_1 * V_8 = & V_36 -> V_30 ;
const struct V_1 * V_9 = & V_36 -> V_29 ;
unsigned int V_37 = F_6 ( V_36 -> V_31 ) ;
int V_38 = 0 ;
if ( ! F_14 ( V_9 ) )
V_38 |= 1 ;
if ( ! F_14 ( V_8 ) && ! F_11 ( V_8 ) ) {
V_38 |= 2 ;
V_37 ^= F_1 ( V_8 ) ;
}
return & V_20 -> V_39 [ V_38 ] [ V_37 ] ;
}
static inline struct V_5 T_4 * * F_15 ( struct V_19 * V_20 ,
const struct V_5 * V_17 )
{
return F_13 ( V_20 , & V_17 -> V_28 ) ;
}
static void F_16 ( struct V_19 * V_20 , struct V_5 * V_17 )
{
struct V_5 T_4 * * V_40 = F_15 ( V_20 , V_17 ) ;
F_17 ( V_17 -> V_41 , F_18 ( * V_40 ) ) ;
F_17 ( * V_40 , V_17 ) ;
}
static void F_19 ( struct V_19 * V_20 , struct V_5 * V_17 )
{
struct V_5 T_4 * * V_40 ;
struct V_5 * V_42 ;
for ( V_40 = F_15 ( V_20 , V_17 ) ;
( V_42 = F_18 ( * V_40 ) ) != NULL ;
V_40 = & V_42 -> V_41 ) {
if ( V_17 == V_42 ) {
F_17 ( * V_40 , V_17 -> V_41 ) ;
break;
}
}
}
static struct V_5 * F_20 ( struct V_12 * V_12 ,
const struct V_35 * V_28 ,
int type )
{
const struct V_1 * V_8 = & V_28 -> V_30 ;
const struct V_1 * V_9 = & V_28 -> V_29 ;
T_2 V_10 = V_28 -> V_31 ;
int V_13 = V_28 -> V_13 ;
struct V_5 * V_17 ;
struct V_5 T_4 * * V_40 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
for ( V_40 = F_13 ( V_20 , V_28 ) ;
( V_17 = F_18 ( * V_40 ) ) != NULL ;
V_40 = & V_17 -> V_41 )
if ( F_10 ( V_9 , & V_17 -> V_28 . V_29 ) &&
F_10 ( V_8 , & V_17 -> V_28 . V_30 ) &&
V_10 == V_17 -> V_28 . V_31 &&
V_13 == V_17 -> V_28 . V_13 &&
type == V_17 -> V_7 -> type )
break;
return V_17 ;
}
static struct V_5 * F_21 ( struct V_12 * V_12 ,
const struct V_35 * V_28 , int V_43 )
{
struct V_5 * V_17 , * V_44 ;
struct V_6 * V_7 ;
char V_45 [ V_46 ] ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
V_17 = F_20 ( V_12 , V_28 , V_25 ) ;
if ( V_17 && V_43 )
return NULL ;
if ( V_17 || ! V_43 )
return V_17 ;
if ( V_28 -> V_45 [ 0 ] )
F_22 ( V_45 , V_28 -> V_45 , V_46 ) ;
else
strcpy ( V_45 , L_1 ) ;
V_7 = F_23 ( sizeof( * V_17 ) , V_45 , V_47 ,
V_48 ) ;
if ( ! V_7 )
return NULL ;
F_24 ( V_7 , V_12 ) ;
V_44 = F_12 ( V_7 ) ;
V_44 -> V_28 = * V_28 ;
V_7 -> V_49 = & V_50 ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , 1 ) ;
if ( F_26 ( V_7 ) < 0 )
goto V_51;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) )
V_7 -> V_54 |= V_55 ;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
return V_44 ;
V_51:
F_28 ( V_7 ) ;
return NULL ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_17 -> V_12 , V_21 ) ;
F_19 ( V_20 , V_17 ) ;
F_30 ( & V_17 -> V_56 ) ;
F_31 ( V_7 ) ;
}
static void F_32 ( struct V_57 * V_58 , struct V_59 * V_60 ,
T_5 type , T_5 V_61 , int V_62 , T_2 V_63 )
{
const struct V_64 * V_65 ;
const struct V_66 * V_67 ;
int V_68 = sizeof( * V_65 ) ;
struct V_5 * V_17 ;
int V_69 = 0 ;
T_3 V_32 ;
T_2 V_10 ;
if ( ! F_33 ( V_58 , V_62 + V_68 ) )
return;
V_65 = ( const struct V_64 * ) ( V_58 -> V_70 + V_62 ) ;
V_32 = V_65 -> V_32 ;
if ( V_32 & ( V_71 | V_72 ) )
return;
if ( V_32 & V_73 )
V_68 += 4 ;
if ( V_32 & V_74 ) {
V_69 = V_68 + V_62 ;
V_68 += 4 ;
}
if ( ! F_33 ( V_58 , V_62 + V_68 ) )
return;
V_67 = ( const struct V_66 * ) V_58 -> V_70 ;
V_65 = ( const struct V_64 * ) ( V_58 -> V_70 + V_62 ) ;
V_10 = V_69 ? * ( T_2 * ) ( V_58 -> V_70 + V_69 ) : 0 ;
V_17 = F_4 ( V_58 -> V_7 , & V_67 -> V_75 , & V_67 -> V_76 ,
V_10 , V_65 -> V_77 ) ;
if ( ! V_17 )
return;
switch ( type ) {
T_6 V_78 ;
struct V_79 * V_80 ;
T_6 V_81 ;
case V_82 :
F_34 ( L_2 ,
V_17 -> V_28 . V_45 ) ;
if ( V_61 != V_83 )
break;
return;
case V_84 :
if ( V_61 == V_85 ) {
F_34 ( L_3 ,
V_17 -> V_28 . V_45 ) ;
break;
}
return;
case V_86 :
V_78 = 0 ;
if ( V_61 == V_87 )
V_78 = F_35 ( V_58 , V_58 -> V_70 ) ;
if ( V_78 && V_78 == F_36 ( V_63 ) - 2 ) {
V_80 = (struct V_79 * ) & V_58 -> V_70 [ V_78 ] ;
if ( V_80 -> V_88 == 0 ) {
F_34 ( L_4 ,
V_17 -> V_28 . V_45 ) ;
}
} else {
F_34 ( L_5 ,
V_17 -> V_28 . V_45 ) ;
}
return;
case V_89 :
V_81 = F_36 ( V_63 ) - V_62 - V_17 -> V_90 ;
if ( V_17 -> V_7 -> type == V_24 )
V_81 -= V_91 ;
if ( V_81 < V_92 )
V_81 = V_92 ;
V_17 -> V_7 -> V_81 = V_81 ;
return;
}
if ( F_37 ( V_93 , V_17 -> V_94 + V_95 ) )
V_17 -> V_96 ++ ;
else
V_17 -> V_96 = 1 ;
V_17 -> V_94 = V_93 ;
}
static int F_38 ( struct V_57 * V_58 , const struct V_97 * V_98 )
{
const struct V_66 * V_67 ;
struct V_5 * V_99 ;
V_67 = F_39 ( V_58 ) ;
V_99 = F_4 ( V_58 -> V_7 ,
& V_67 -> V_76 , & V_67 -> V_75 , V_98 -> V_10 ,
V_98 -> V_100 ) ;
if ( V_99 ) {
F_40 ( V_99 , V_58 , V_98 , NULL , false ) ;
return V_101 ;
}
return V_102 ;
}
static int F_41 ( struct V_57 * V_58 )
{
struct V_97 V_98 ;
bool V_103 = false ;
int V_104 ;
V_104 = F_42 ( V_58 , & V_98 , & V_103 , F_8 ( V_105 ) , 0 ) ;
if ( V_104 < 0 )
goto V_106;
if ( F_43 ( V_58 , V_104 , V_98 . V_100 , false ) )
goto V_106;
if ( F_38 ( V_58 , & V_98 ) == V_101 )
return 0 ;
F_44 ( V_58 , V_82 , V_83 , 0 ) ;
V_106:
F_45 ( V_58 ) ;
return 0 ;
}
static int F_46 ( struct V_57 * V_58 , bool V_107 )
{
return F_47 ( V_58 ,
V_107 ? V_108 : V_109 ) ;
}
static T_7 F_48 ( struct V_57 * V_58 ,
struct V_6 * V_7 , T_8 V_110 ,
struct V_111 * V_112 , int V_88 ,
T_6 * V_113 , T_3 V_100 )
{
struct V_5 * V_99 = F_12 ( V_7 ) ;
struct V_114 * V_115 = F_49 ( V_58 ) ;
T_3 V_77 ;
if ( V_7 -> type == V_24 )
F_50 ( V_58 ) -> V_32 = 0 ;
if ( V_7 -> V_116 && V_7 -> type == V_25 )
V_112 -> V_75 = ( (struct V_66 * ) V_58 -> V_70 ) -> V_75 ;
else
V_112 -> V_75 = V_99 -> V_28 . V_30 ;
if ( V_99 -> V_28 . V_52 & V_53 )
V_99 -> V_117 ++ ;
V_77 = ( V_7 -> type == V_24 ) ? F_8 ( V_23 ) : V_100 ;
F_51 ( V_58 , V_99 -> V_90 , V_99 -> V_28 . V_52 ,
V_77 , V_99 -> V_28 . V_118 , F_52 ( V_99 -> V_117 ) ) ;
if ( V_115 && F_53 ( V_115 ) > V_115 -> V_7 -> V_81 )
V_115 -> V_119 -> V_120 ( V_115 , NULL , V_58 , V_115 -> V_7 -> V_81 ) ;
return F_54 ( V_58 , V_7 , V_110 , V_112 , V_88 , V_113 ,
V_121 ) ;
}
static inline int F_55 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_122 * V_123 = F_56 ( V_58 ) ;
int V_88 = - 1 ;
struct V_111 V_112 ;
T_8 V_110 ;
T_6 V_81 ;
int V_124 ;
memset ( & ( F_50 ( V_58 ) -> V_60 ) , 0 , sizeof( F_50 ( V_58 ) -> V_60 ) ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_125 ) )
V_88 = V_17 -> V_28 . V_88 ;
memcpy ( & V_112 , & V_17 -> V_126 . V_127 . V_128 , sizeof( V_112 ) ) ;
if ( V_17 -> V_28 . V_32 & V_129 )
V_110 = F_57 ( V_123 ) ;
else
V_110 = F_58 ( V_17 -> V_28 . V_130 ) ;
if ( V_17 -> V_28 . V_32 & V_131 )
V_112 . V_132 = V_58 -> V_133 ;
else
V_112 . V_132 = V_17 -> V_28 . V_134 ;
V_112 . V_135 = F_59 ( F_5 ( V_7 ) , NULL ) ;
V_124 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_136 ) ) ;
if ( V_124 )
return - 1 ;
V_124 = F_48 ( V_58 , V_7 , V_110 , & V_112 , V_88 , & V_81 ,
V_58 -> V_77 ) ;
if ( V_124 != 0 ) {
if ( V_124 == - V_137 )
F_60 ( V_58 , V_138 , V_139 ,
F_52 ( V_81 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_61 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_66 * V_67 = F_39 ( V_58 ) ;
int V_88 = - 1 ;
T_9 V_62 ;
struct V_111 V_112 ;
T_8 V_110 ;
T_6 V_81 ;
int V_124 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_67 -> V_76 ) )
return - 1 ;
V_62 = F_35 ( V_58 , F_62 ( V_58 ) ) ;
V_67 = F_39 ( V_58 ) ;
if ( V_62 > 0 ) {
struct V_79 * V_80 ;
V_80 = (struct V_79 * ) & F_62 ( V_58 ) [ V_62 ] ;
if ( V_80 -> V_88 == 0 ) {
F_44 ( V_58 , V_86 ,
V_87 , V_62 + 2 ) ;
return - 1 ;
}
V_88 = V_80 -> V_88 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_125 ) )
V_88 = V_17 -> V_28 . V_88 ;
memcpy ( & V_112 , & V_17 -> V_126 . V_127 . V_128 , sizeof( V_112 ) ) ;
if ( V_17 -> V_28 . V_32 & V_129 )
V_110 = F_63 ( V_67 ) ;
else
V_110 = F_58 ( V_17 -> V_28 . V_130 ) ;
if ( V_17 -> V_28 . V_32 & V_140 )
V_112 . V_141 |= F_64 ( V_67 ) ;
if ( V_17 -> V_28 . V_32 & V_131 )
V_112 . V_132 = V_58 -> V_133 ;
else
V_112 . V_132 = V_17 -> V_28 . V_134 ;
V_112 . V_135 = F_59 ( F_5 ( V_7 ) , NULL ) ;
if ( F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_136 ) ) )
return - 1 ;
V_124 = F_48 ( V_58 , V_7 , V_110 , & V_112 , V_88 ,
& V_81 , V_58 -> V_77 ) ;
if ( V_124 != 0 ) {
if ( V_124 == - V_137 )
F_44 ( V_58 , V_89 , 0 , V_81 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_65 ( const struct V_5 * V_17 ,
const struct V_66 * V_142 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_142 -> V_76 ) ;
}
static int F_66 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_88 = - 1 ;
struct V_111 V_112 ;
T_6 V_81 ;
int V_124 ;
if ( ! ( V_17 -> V_28 . V_32 & V_125 ) )
V_88 = V_17 -> V_28 . V_88 ;
memcpy ( & V_112 , & V_17 -> V_126 . V_127 . V_128 , sizeof( V_112 ) ) ;
V_124 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_136 ) ) ;
if ( V_124 )
return V_124 ;
V_124 = F_48 ( V_58 , V_7 , 0 , & V_112 , V_88 , & V_81 , V_58 -> V_77 ) ;
return V_124 ;
}
static T_7 F_67 ( struct V_57 * V_58 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_143 * V_144 = & V_17 -> V_7 -> V_144 ;
int V_145 ;
if ( ! F_68 ( V_17 , & V_17 -> V_28 . V_29 , & V_17 -> V_28 . V_30 ) )
goto V_146;
switch ( V_58 -> V_77 ) {
case F_8 ( V_147 ) :
V_145 = F_55 ( V_58 , V_7 ) ;
break;
case F_8 ( V_105 ) :
V_145 = F_61 ( V_58 , V_7 ) ;
break;
default:
V_145 = F_66 ( V_58 , V_7 ) ;
break;
}
if ( V_145 < 0 )
goto V_146;
return V_148 ;
V_146:
V_144 -> V_149 ++ ;
V_144 -> V_150 ++ ;
F_45 ( V_58 ) ;
return V_148 ;
}
static void F_25 ( struct V_5 * V_17 , int V_151 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_111 * V_112 = & V_17 -> V_126 . V_127 . V_128 ;
int V_152 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_153 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_154 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_112 -> V_76 = V_36 -> V_29 ;
V_112 -> V_75 = V_36 -> V_30 ;
V_112 -> V_155 = V_36 -> V_13 ;
V_112 -> V_141 = 0 ;
V_112 -> V_156 = V_157 ;
if ( ! ( V_36 -> V_32 & V_129 ) )
V_112 -> V_141 |= V_158 & V_36 -> V_130 ;
if ( ! ( V_36 -> V_32 & V_140 ) )
V_112 -> V_141 |= V_159 & V_36 -> V_130 ;
V_36 -> V_32 &= ~ ( V_160 | V_161 | V_162 ) ;
V_36 -> V_32 |= F_69 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_160 &&
V_36 -> V_32 & V_161 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_163 ;
else
V_7 -> V_32 &= ~ V_163 ;
V_17 -> V_90 = F_70 ( V_17 -> V_28 . V_52 ) ;
V_17 -> V_164 = V_17 -> V_165 + V_17 -> V_90 ;
V_152 = V_17 -> V_164 + sizeof( struct V_66 ) ;
if ( V_36 -> V_32 & V_160 ) {
int V_166 = ( F_71 ( & V_36 -> V_30 ) &
( V_167 | V_168 ) ) ;
struct V_169 * V_170 = F_72 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_166 ) ;
if ( ! V_170 )
return;
if ( V_170 -> V_115 . V_7 ) {
V_7 -> V_171 = V_170 -> V_115 . V_7 -> V_171 +
V_152 ;
if ( V_151 ) {
V_7 -> V_81 = V_170 -> V_115 . V_7 -> V_81 - V_152 ;
if ( ! ( V_17 -> V_28 . V_32 & V_125 ) )
V_7 -> V_81 -= 8 ;
if ( V_7 -> type == V_24 )
V_7 -> V_81 -= V_91 ;
if ( V_7 -> V_81 < V_92 )
V_7 -> V_81 = V_92 ;
}
}
F_73 ( V_170 ) ;
}
}
static int F_74 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_151 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_172 = V_36 -> V_172 ;
V_17 -> V_28 . V_88 = V_36 -> V_88 ;
V_17 -> V_28 . V_130 = V_36 -> V_130 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_100 = V_36 -> V_100 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_118 = V_36 -> V_118 ;
V_17 -> V_28 . V_173 = V_36 -> V_173 ;
V_17 -> V_28 . V_52 = V_36 -> V_52 ;
V_17 -> V_28 . V_134 = V_36 -> V_134 ;
F_30 ( & V_17 -> V_56 ) ;
F_25 ( V_17 , V_151 ) ;
return 0 ;
}
static void F_75 ( struct V_35 * V_36 ,
const struct V_174 * V_127 )
{
V_36 -> V_29 = V_127 -> V_29 ;
V_36 -> V_30 = V_127 -> V_30 ;
V_36 -> V_32 = V_127 -> V_32 ;
V_36 -> V_172 = V_127 -> V_172 ;
V_36 -> V_88 = V_127 -> V_88 ;
V_36 -> V_130 = V_127 -> V_130 ;
V_36 -> V_13 = V_127 -> V_13 ;
V_36 -> V_31 = V_127 -> V_31 ;
V_36 -> V_118 = V_127 -> V_118 ;
V_36 -> V_173 = F_76 ( V_127 -> V_173 ) ;
V_36 -> V_52 = F_76 ( V_127 -> V_52 ) ;
memcpy ( V_36 -> V_45 , V_127 -> V_45 , sizeof( V_127 -> V_45 ) ) ;
}
static void F_77 ( struct V_174 * V_127 ,
const struct V_35 * V_36 )
{
V_127 -> V_100 = V_157 ;
V_127 -> V_29 = V_36 -> V_29 ;
V_127 -> V_30 = V_36 -> V_30 ;
V_127 -> V_32 = V_36 -> V_32 ;
V_127 -> V_172 = V_36 -> V_172 ;
V_127 -> V_88 = V_36 -> V_88 ;
V_127 -> V_130 = V_36 -> V_130 ;
V_127 -> V_13 = V_36 -> V_13 ;
V_127 -> V_31 = V_36 -> V_31 ;
V_127 -> V_118 = V_36 -> V_118 ;
V_127 -> V_173 = F_78 ( V_36 -> V_173 ) ;
V_127 -> V_52 = F_78 ( V_36 -> V_52 ) ;
memcpy ( V_127 -> V_45 , V_36 -> V_45 , sizeof( V_127 -> V_45 ) ) ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_175 * V_176 , int V_177 )
{
int V_124 = 0 ;
struct V_174 V_36 ;
struct V_35 V_178 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
switch ( V_177 ) {
case V_179 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_80 ( & V_36 , V_176 -> V_180 . V_181 , sizeof( V_36 ) ) ) {
V_124 = - V_182 ;
break;
}
F_75 ( & V_178 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_178 , 0 ) ;
if ( ! V_17 )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_77 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_81 ( V_176 -> V_180 . V_181 , & V_36 , sizeof( V_36 ) ) )
V_124 = - V_182 ;
break;
case V_183 :
case V_184 :
V_124 = - V_185 ;
if ( ! F_82 ( V_12 -> V_186 , V_187 ) )
goto V_188;
V_124 = - V_182 ;
if ( F_80 ( & V_36 , V_176 -> V_180 . V_181 , sizeof( V_36 ) ) )
goto V_188;
V_124 = - V_189 ;
if ( ( V_36 . V_173 | V_36 . V_52 ) & ( V_71 | V_72 ) )
goto V_188;
if ( ! ( V_36 . V_173 & V_74 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_52 & V_74 ) )
V_36 . V_118 = 0 ;
F_75 ( & V_178 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_178 , V_177 == V_183 ) ;
if ( V_7 != V_20 -> V_34 && V_177 == V_184 ) {
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 ) {
V_124 = - V_190 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_83 () ;
F_74 ( V_17 , & V_178 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_84 ( V_7 ) ;
}
}
if ( V_17 ) {
V_124 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_77 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_81 ( V_176 -> V_180 . V_181 , & V_36 , sizeof( V_36 ) ) )
V_124 = - V_182 ;
} else
V_124 = ( V_177 == V_183 ? - V_191 : - V_192 ) ;
break;
case V_193 :
V_124 = - V_185 ;
if ( ! F_82 ( V_12 -> V_186 , V_187 ) )
goto V_188;
if ( V_7 == V_20 -> V_34 ) {
V_124 = - V_182 ;
if ( F_80 ( & V_36 , V_176 -> V_180 . V_181 , sizeof( V_36 ) ) )
goto V_188;
V_124 = - V_192 ;
F_75 ( & V_178 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_178 , 0 ) ;
if ( ! V_17 )
goto V_188;
V_124 = - V_185 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_188;
V_7 = V_17 -> V_7 ;
}
F_85 ( V_7 ) ;
V_124 = 0 ;
break;
default:
V_124 = - V_189 ;
}
V_188:
return V_124 ;
}
static int F_86 ( struct V_57 * V_58 , struct V_6 * V_7 ,
unsigned short type , const void * V_75 ,
const void * V_76 , unsigned int V_194 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_66 * V_67 ;
T_3 * V_36 ;
V_67 = F_87 ( V_58 , V_17 -> V_164 + sizeof( * V_67 ) ) ;
F_88 ( V_67 , 0 , F_89 ( F_5 ( V_7 ) , V_58 ,
V_17 -> V_126 . V_127 . V_128 . V_141 ,
true , & V_17 -> V_126 . V_127 . V_128 ) ) ;
V_67 -> V_172 = V_17 -> V_28 . V_172 ;
V_67 -> V_195 = V_121 ;
V_67 -> V_76 = V_17 -> V_28 . V_29 ;
V_67 -> V_75 = V_17 -> V_28 . V_30 ;
V_36 = ( T_3 * ) ( V_67 + 1 ) ;
V_36 [ 0 ] = V_17 -> V_28 . V_52 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_76 )
memcpy ( & V_67 -> V_76 , V_76 , sizeof( struct V_1 ) ) ;
if ( V_75 )
memcpy ( & V_67 -> V_75 , V_75 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_67 -> V_75 ) )
return V_17 -> V_164 ;
return - V_17 -> V_164 ;
}
static void F_90 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
F_91 ( & V_17 -> V_56 ) ;
F_92 ( V_7 -> V_196 ) ;
}
static void V_48 ( struct V_6 * V_7 )
{
V_7 -> V_197 = & V_198 ;
V_7 -> V_199 = true ;
V_7 -> V_200 = F_90 ;
V_7 -> type = V_25 ;
V_7 -> V_32 |= V_201 ;
V_7 -> V_202 = sizeof( struct V_1 ) ;
F_93 ( V_7 ) ;
V_7 -> V_203 = V_204 ;
F_94 ( V_7 -> V_205 ) ;
}
static int F_95 ( struct V_6 * V_7 )
{
struct V_5 * V_99 ;
int V_145 ;
int V_152 ;
V_99 = F_12 ( V_7 ) ;
V_99 -> V_7 = V_7 ;
V_99 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_99 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_7 -> V_196 = F_96 ( struct V_206 ) ;
if ( ! V_7 -> V_196 )
return - V_207 ;
V_145 = F_97 ( & V_99 -> V_56 , V_208 ) ;
if ( V_145 ) {
F_92 ( V_7 -> V_196 ) ;
V_7 -> V_196 = NULL ;
return V_145 ;
}
V_99 -> V_90 = F_70 ( V_99 -> V_28 . V_52 ) ;
V_99 -> V_164 = V_99 -> V_90 + V_99 -> V_165 ;
V_152 = V_99 -> V_164 + sizeof( struct V_66 ) ;
V_7 -> V_171 = V_209 + V_152 ;
V_7 -> V_81 = V_210 - V_152 ;
if ( V_7 -> type == V_24 )
V_7 -> V_81 -= V_91 ;
if ( ! ( V_99 -> V_28 . V_32 & V_125 ) )
V_7 -> V_81 -= 8 ;
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
struct V_5 * V_99 ;
int V_145 ;
V_145 = F_95 ( V_7 ) ;
if ( V_145 )
return V_145 ;
V_99 = F_12 ( V_7 ) ;
memcpy ( V_7 -> V_153 , & V_99 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_154 , & V_99 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_99 -> V_28 . V_30 ) )
V_7 -> V_116 = & V_211 ;
return 0 ;
}
static void F_99 ( struct V_6 * V_7 )
{
struct V_5 * V_99 = F_12 ( V_7 ) ;
V_99 -> V_7 = V_7 ;
V_99 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_99 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_99 -> V_164 = sizeof( struct V_66 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_100 ( struct V_12 * V_12 , struct V_212 * V_213 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_214 ;
int V_38 ;
F_101 (net, dev, aux)
if ( V_7 -> V_49 == & V_50 ||
V_7 -> V_49 == & V_215 )
F_102 ( V_7 , V_213 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_216 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 ) {
if ( ! F_103 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_102 ( V_17 -> V_7 ,
V_213 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_10 F_104 ( struct V_12 * V_12 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_124 ;
V_20 -> V_34 = F_23 ( sizeof( struct V_5 ) , L_6 ,
V_47 ,
V_48 ) ;
if ( ! V_20 -> V_34 ) {
V_124 = - V_207 ;
goto V_217;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
V_20 -> V_34 -> V_54 |= V_218 ;
F_99 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_49 = & V_50 ;
V_124 = F_105 ( V_20 -> V_34 ) ;
if ( V_124 )
goto V_219;
F_17 ( V_20 -> V_220 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_219:
F_28 ( V_20 -> V_34 ) ;
V_217:
return V_124 ;
}
static void T_11 F_106 ( struct V_12 * V_12 )
{
F_107 ( V_221 ) ;
F_108 () ;
F_100 ( V_12 , & V_221 ) ;
F_109 ( & V_221 ) ;
F_110 () ;
}
static int F_111 ( struct V_222 * V_223 [] , struct V_222 * V_70 [] ,
struct V_224 * V_225 )
{
T_3 V_32 ;
if ( ! V_70 )
return 0 ;
V_32 = 0 ;
if ( V_70 [ V_226 ] )
V_32 |= F_112 ( V_70 [ V_226 ] ) ;
if ( V_70 [ V_227 ] )
V_32 |= F_112 ( V_70 [ V_227 ] ) ;
if ( V_32 & ( V_71 | V_72 ) )
return - V_189 ;
return 0 ;
}
static int F_113 ( struct V_222 * V_223 [] , struct V_222 * V_70 [] ,
struct V_224 * V_225 )
{
struct V_1 V_75 ;
if ( V_223 [ V_228 ] ) {
if ( F_114 ( V_223 [ V_228 ] ) != V_229 )
return - V_189 ;
if ( ! F_115 ( F_116 ( V_223 [ V_228 ] ) ) )
return - V_230 ;
}
if ( ! V_70 )
goto V_231;
if ( V_70 [ V_232 ] ) {
V_75 = F_117 ( V_70 [ V_232 ] ) ;
if ( F_14 ( & V_75 ) )
return - V_189 ;
}
V_231:
return F_111 ( V_223 , V_70 , V_225 ) ;
}
static void F_118 ( struct V_222 * V_70 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_70 )
return;
if ( V_70 [ V_233 ] )
V_28 -> V_13 = F_119 ( V_70 [ V_233 ] ) ;
if ( V_70 [ V_226 ] )
V_28 -> V_173 = F_76 (
F_112 ( V_70 [ V_226 ] ) ) ;
if ( V_70 [ V_227 ] )
V_28 -> V_52 = F_76 (
F_112 ( V_70 [ V_227 ] ) ) ;
if ( V_70 [ V_234 ] )
V_28 -> V_31 = F_120 ( V_70 [ V_234 ] ) ;
if ( V_70 [ V_235 ] )
V_28 -> V_118 = F_120 ( V_70 [ V_235 ] ) ;
if ( V_70 [ V_236 ] )
V_28 -> V_29 = F_117 ( V_70 [ V_236 ] ) ;
if ( V_70 [ V_232 ] )
V_28 -> V_30 = F_117 ( V_70 [ V_232 ] ) ;
if ( V_70 [ V_237 ] )
V_28 -> V_172 = F_121 ( V_70 [ V_237 ] ) ;
if ( V_70 [ V_238 ] )
V_28 -> V_88 = F_121 ( V_70 [ V_238 ] ) ;
if ( V_70 [ V_239 ] )
V_28 -> V_130 = F_120 ( V_70 [ V_239 ] ) ;
if ( V_70 [ V_240 ] )
V_28 -> V_32 = F_119 ( V_70 [ V_240 ] ) ;
if ( V_70 [ V_241 ] )
V_28 -> V_134 = F_119 ( V_70 [ V_241 ] ) ;
}
static int F_122 ( struct V_6 * V_7 )
{
struct V_5 * V_99 ;
int V_145 ;
V_145 = F_95 ( V_7 ) ;
if ( V_145 )
return V_145 ;
V_7 -> V_242 |= V_243 ;
V_99 = F_12 ( V_7 ) ;
F_25 ( V_99 , 1 ) ;
return 0 ;
}
static void F_123 ( struct V_6 * V_7 )
{
F_124 ( V_7 ) ;
V_7 -> V_197 = & V_244 ;
V_7 -> V_199 = true ;
V_7 -> V_200 = F_90 ;
V_7 -> V_54 |= V_218 ;
V_7 -> V_242 &= ~ V_245 ;
V_7 -> V_242 |= V_243 ;
F_93 ( V_7 ) ;
}
static bool F_125 ( struct V_222 * V_70 [] ,
struct V_246 * V_247 )
{
bool V_145 = false ;
memset ( V_247 , 0 , sizeof( * V_247 ) ) ;
if ( ! V_70 )
return V_145 ;
if ( V_70 [ V_248 ] ) {
V_145 = true ;
V_247 -> type = F_126 ( V_70 [ V_248 ] ) ;
}
if ( V_70 [ V_249 ] ) {
V_145 = true ;
V_247 -> V_32 = F_126 ( V_70 [ V_249 ] ) ;
}
if ( V_70 [ V_250 ] ) {
V_145 = true ;
V_247 -> V_251 = F_112 ( V_70 [ V_250 ] ) ;
}
if ( V_70 [ V_252 ] ) {
V_145 = true ;
V_247 -> V_253 = F_112 ( V_70 [ V_252 ] ) ;
}
return V_145 ;
}
static int F_127 ( struct V_12 * V_254 , struct V_6 * V_7 ,
struct V_222 * V_223 [] , struct V_222 * V_70 [] ,
struct V_224 * V_225 )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_246 V_247 ;
int V_124 ;
V_44 = F_12 ( V_7 ) ;
if ( F_125 ( V_70 , & V_247 ) ) {
int V_124 = F_128 ( V_44 , & V_247 ) ;
if ( V_124 < 0 )
return V_124 ;
}
F_118 ( V_70 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_190 ;
if ( V_7 -> type == V_24 && ! V_223 [ V_228 ] )
F_129 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_223 [ V_255 ] ) ;
V_7 -> V_54 |= V_256 ;
V_7 -> V_257 |= V_256 ;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) ) {
if ( ! ( V_44 -> V_28 . V_52 & V_136 ) ||
( V_44 -> V_258 . type == V_259 ) ) {
V_7 -> V_54 |= V_260 ;
V_7 -> V_257 |= V_260 ;
}
V_7 -> V_54 |= V_55 ;
}
V_124 = F_26 ( V_7 ) ;
if ( V_124 )
goto V_231;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_231:
return V_124 ;
}
static int F_130 ( struct V_6 * V_7 , struct V_222 * V_223 [] ,
struct V_222 * V_70 [] ,
struct V_224 * V_225 )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
struct V_246 V_247 ;
if ( V_7 == V_20 -> V_34 )
return - V_189 ;
if ( F_125 ( V_70 , & V_247 ) ) {
int V_124 = F_128 ( V_44 , & V_247 ) ;
if ( V_124 < 0 )
return V_124 ;
}
F_118 ( V_70 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_190 ;
} else {
V_17 = V_44 ;
}
F_19 ( V_20 , V_17 ) ;
F_74 ( V_17 , & V_36 , ! V_223 [ V_255 ] ) ;
F_16 ( V_20 , V_17 ) ;
return 0 ;
}
static void F_131 ( struct V_6 * V_7 , struct V_212 * V_213 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_102 ( V_7 , V_213 ) ;
}
static T_12 F_132 ( const struct V_6 * V_7 )
{
return
F_133 ( 4 ) +
F_133 ( 2 ) +
F_133 ( 2 ) +
F_133 ( 4 ) +
F_133 ( 4 ) +
F_133 ( sizeof( struct V_1 ) ) +
F_133 ( sizeof( struct V_1 ) ) +
F_133 ( 1 ) +
F_133 ( 1 ) +
F_133 ( 4 ) +
F_133 ( 4 ) +
F_133 ( 2 ) +
F_133 ( 2 ) +
F_133 ( 2 ) +
F_133 ( 2 ) +
F_133 ( 4 ) +
0 ;
}
static int F_134 ( struct V_57 * V_58 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_135 ( V_58 , V_233 , V_36 -> V_13 ) ||
F_136 ( V_58 , V_226 ,
F_78 ( V_36 -> V_173 ) ) ||
F_136 ( V_58 , V_227 ,
F_78 ( V_36 -> V_52 ) ) ||
F_137 ( V_58 , V_234 , V_36 -> V_31 ) ||
F_137 ( V_58 , V_235 , V_36 -> V_118 ) ||
F_138 ( V_58 , V_236 , & V_36 -> V_29 ) ||
F_138 ( V_58 , V_232 , & V_36 -> V_30 ) ||
F_139 ( V_58 , V_237 , V_36 -> V_172 ) ||
F_139 ( V_58 , V_238 , V_36 -> V_88 ) ||
F_137 ( V_58 , V_239 , V_36 -> V_130 ) ||
F_135 ( V_58 , V_240 , V_36 -> V_32 ) ||
F_135 ( V_58 , V_241 , V_36 -> V_134 ) )
goto V_261;
if ( F_140 ( V_58 , V_248 ,
V_17 -> V_258 . type ) ||
F_136 ( V_58 , V_250 ,
V_17 -> V_258 . V_251 ) ||
F_136 ( V_58 , V_252 ,
V_17 -> V_258 . V_253 ) ||
F_140 ( V_58 , V_249 ,
V_17 -> V_258 . V_32 ) )
goto V_261;
return 0 ;
V_261:
return - V_137 ;
}
static int T_13 F_141 ( void )
{
int V_124 ;
F_142 ( L_7 ) ;
V_124 = F_143 ( & V_262 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_144 ( & V_263 , V_157 ) ;
if ( V_124 < 0 ) {
F_142 ( L_8 , V_264 ) ;
goto V_265;
}
V_124 = F_145 ( & V_50 ) ;
if ( V_124 < 0 )
goto V_266;
V_124 = F_145 ( & V_215 ) ;
if ( V_124 < 0 )
goto V_267;
V_231:
return V_124 ;
V_267:
F_146 ( & V_50 ) ;
V_266:
F_147 ( & V_263 , V_157 ) ;
V_265:
F_148 ( & V_262 ) ;
goto V_231;
}
static void T_14 F_149 ( void )
{
F_146 ( & V_215 ) ;
F_146 ( & V_50 ) ;
F_147 ( & V_263 , V_157 ) ;
F_148 ( & V_262 ) ;
}
