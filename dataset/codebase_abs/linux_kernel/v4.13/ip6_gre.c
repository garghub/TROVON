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
break;
case V_83 :
if ( V_61 == V_84 ) {
F_34 ( L_3 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_85 :
V_78 = 0 ;
if ( V_61 == V_86 )
V_78 = F_35 ( V_58 , V_58 -> V_70 ) ;
if ( V_78 && V_78 == F_36 ( V_63 ) - 2 ) {
V_80 = (struct V_79 * ) & V_58 -> V_70 [ V_78 ] ;
if ( V_80 -> V_87 == 0 ) {
F_34 ( L_4 ,
V_17 -> V_28 . V_45 ) ;
}
} else {
F_34 ( L_5 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_88 :
V_81 = F_36 ( V_63 ) - V_62 ;
if ( V_81 < V_89 )
V_81 = V_89 ;
V_17 -> V_7 -> V_81 = V_81 ;
break;
}
if ( F_37 ( V_90 , V_17 -> V_91 + V_92 ) )
V_17 -> V_93 ++ ;
else
V_17 -> V_93 = 1 ;
V_17 -> V_91 = V_90 ;
}
static int F_38 ( struct V_57 * V_58 , const struct V_94 * V_95 )
{
const struct V_66 * V_67 ;
struct V_5 * V_96 ;
V_67 = F_39 ( V_58 ) ;
V_96 = F_4 ( V_58 -> V_7 ,
& V_67 -> V_76 , & V_67 -> V_75 , V_95 -> V_10 ,
V_95 -> V_97 ) ;
if ( V_96 ) {
F_40 ( V_96 , V_58 , V_95 , NULL , false ) ;
return V_98 ;
}
return V_99 ;
}
static int F_41 ( struct V_57 * V_58 )
{
struct V_94 V_95 ;
bool V_100 = false ;
int V_101 ;
V_101 = F_42 ( V_58 , & V_95 , & V_100 , F_8 ( V_102 ) , 0 ) ;
if ( V_101 < 0 )
goto V_103;
if ( F_43 ( V_58 , V_101 , V_95 . V_97 , false ) )
goto V_103;
if ( F_38 ( V_58 , & V_95 ) == V_98 )
return 0 ;
F_44 ( V_58 , V_82 , V_104 , 0 ) ;
V_103:
F_45 ( V_58 ) ;
return 0 ;
}
static int F_46 ( struct V_57 * V_58 , bool V_105 )
{
return F_47 ( V_58 ,
V_105 ? V_106 : V_107 ) ;
}
static T_7 F_48 ( struct V_57 * V_58 ,
struct V_6 * V_7 , T_8 V_108 ,
struct V_109 * V_110 , int V_87 ,
T_6 * V_111 , T_3 V_97 )
{
struct V_5 * V_96 = F_12 ( V_7 ) ;
T_3 V_77 = ( V_7 -> type == V_24 ) ?
F_8 ( V_23 ) : V_97 ;
if ( V_7 -> type == V_24 )
F_49 ( V_58 ) -> V_32 = 0 ;
if ( V_7 -> V_112 && V_7 -> type == V_25 )
V_110 -> V_75 = ( (struct V_66 * ) V_58 -> V_70 ) -> V_75 ;
else
V_110 -> V_75 = V_96 -> V_28 . V_30 ;
if ( V_96 -> V_28 . V_52 & V_53 )
V_96 -> V_113 ++ ;
F_50 ( V_58 , V_96 -> V_114 , V_96 -> V_28 . V_52 ,
V_77 , V_96 -> V_28 . V_115 , F_51 ( V_96 -> V_113 ) ) ;
return F_52 ( V_58 , V_7 , V_108 , V_110 , V_87 , V_111 ,
V_116 ) ;
}
static inline int F_53 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_117 * V_118 = F_54 ( V_58 ) ;
int V_87 = - 1 ;
struct V_109 V_110 ;
T_8 V_108 ;
T_6 V_81 ;
int V_119 ;
memset ( & ( F_49 ( V_58 ) -> V_60 ) , 0 , sizeof( F_49 ( V_58 ) -> V_60 ) ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_87 = V_17 -> V_28 . V_87 ;
memcpy ( & V_110 , & V_17 -> V_121 . V_122 . V_123 , sizeof( V_110 ) ) ;
if ( V_17 -> V_28 . V_32 & V_124 )
V_108 = F_55 ( V_118 ) ;
else
V_108 = F_56 ( V_17 -> V_28 . V_125 ) ;
if ( V_17 -> V_28 . V_32 & V_126 )
V_110 . V_127 = V_58 -> V_128 ;
else
V_110 . V_127 = V_17 -> V_28 . V_129 ;
V_110 . V_130 = F_57 ( F_5 ( V_7 ) , NULL ) ;
V_119 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_131 ) ) ;
if ( V_119 )
return - 1 ;
V_119 = F_48 ( V_58 , V_7 , V_108 , & V_110 , V_87 , & V_81 ,
V_58 -> V_77 ) ;
if ( V_119 != 0 ) {
if ( V_119 == - V_132 )
F_58 ( V_58 , V_133 , V_134 ,
F_51 ( V_81 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_59 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_66 * V_67 = F_39 ( V_58 ) ;
int V_87 = - 1 ;
T_9 V_62 ;
struct V_109 V_110 ;
T_8 V_108 ;
T_6 V_81 ;
int V_119 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_67 -> V_76 ) )
return - 1 ;
V_62 = F_35 ( V_58 , F_60 ( V_58 ) ) ;
V_67 = F_39 ( V_58 ) ;
if ( V_62 > 0 ) {
struct V_79 * V_80 ;
V_80 = (struct V_79 * ) & F_60 ( V_58 ) [ V_62 ] ;
if ( V_80 -> V_87 == 0 ) {
F_44 ( V_58 , V_85 ,
V_86 , V_62 + 2 ) ;
return - 1 ;
}
V_87 = V_80 -> V_87 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_87 = V_17 -> V_28 . V_87 ;
memcpy ( & V_110 , & V_17 -> V_121 . V_122 . V_123 , sizeof( V_110 ) ) ;
if ( V_17 -> V_28 . V_32 & V_124 )
V_108 = F_61 ( V_67 ) ;
else
V_108 = F_56 ( V_17 -> V_28 . V_125 ) ;
if ( V_17 -> V_28 . V_32 & V_135 )
V_110 . V_136 |= F_62 ( V_67 ) ;
if ( V_17 -> V_28 . V_32 & V_126 )
V_110 . V_127 = V_58 -> V_128 ;
else
V_110 . V_127 = V_17 -> V_28 . V_129 ;
V_110 . V_130 = F_57 ( F_5 ( V_7 ) , NULL ) ;
if ( F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_131 ) ) )
return - 1 ;
V_119 = F_48 ( V_58 , V_7 , V_108 , & V_110 , V_87 ,
& V_81 , V_58 -> V_77 ) ;
if ( V_119 != 0 ) {
if ( V_119 == - V_132 )
F_44 ( V_58 , V_88 , 0 , V_81 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_63 ( const struct V_5 * V_17 ,
const struct V_66 * V_137 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_137 -> V_76 ) ;
}
static int F_64 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_87 = - 1 ;
struct V_109 V_110 ;
T_6 V_81 ;
int V_119 ;
if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_87 = V_17 -> V_28 . V_87 ;
memcpy ( & V_110 , & V_17 -> V_121 . V_122 . V_123 , sizeof( V_110 ) ) ;
V_119 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_131 ) ) ;
if ( V_119 )
return V_119 ;
V_119 = F_48 ( V_58 , V_7 , 0 , & V_110 , V_87 , & V_81 , V_58 -> V_77 ) ;
return V_119 ;
}
static T_7 F_65 ( struct V_57 * V_58 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_138 * V_139 = & V_17 -> V_7 -> V_139 ;
int V_140 ;
if ( ! F_66 ( V_17 , & V_17 -> V_28 . V_29 , & V_17 -> V_28 . V_30 ) )
goto V_141;
switch ( V_58 -> V_77 ) {
case F_8 ( V_142 ) :
V_140 = F_53 ( V_58 , V_7 ) ;
break;
case F_8 ( V_102 ) :
V_140 = F_59 ( V_58 , V_7 ) ;
break;
default:
V_140 = F_64 ( V_58 , V_7 ) ;
break;
}
if ( V_140 < 0 )
goto V_141;
return V_143 ;
V_141:
V_139 -> V_144 ++ ;
V_139 -> V_145 ++ ;
F_45 ( V_58 ) ;
return V_143 ;
}
static void F_25 ( struct V_5 * V_17 , int V_146 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_109 * V_110 = & V_17 -> V_121 . V_122 . V_123 ;
int V_147 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_148 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_149 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_110 -> V_76 = V_36 -> V_29 ;
V_110 -> V_75 = V_36 -> V_30 ;
V_110 -> V_150 = V_36 -> V_13 ;
V_110 -> V_136 = 0 ;
V_110 -> V_151 = V_152 ;
if ( ! ( V_36 -> V_32 & V_124 ) )
V_110 -> V_136 |= V_153 & V_36 -> V_125 ;
if ( ! ( V_36 -> V_32 & V_135 ) )
V_110 -> V_136 |= V_154 & V_36 -> V_125 ;
V_36 -> V_32 &= ~ ( V_155 | V_156 | V_157 ) ;
V_36 -> V_32 |= F_67 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_155 &&
V_36 -> V_32 & V_156 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_158 ;
else
V_7 -> V_32 &= ~ V_158 ;
V_17 -> V_114 = F_68 ( V_17 -> V_28 . V_52 ) ;
V_17 -> V_159 = V_17 -> V_160 + V_17 -> V_114 ;
V_147 = V_17 -> V_159 + sizeof( struct V_66 ) ;
if ( V_36 -> V_32 & V_155 ) {
int V_161 = ( F_69 ( & V_36 -> V_30 ) &
( V_162 | V_163 ) ) ;
struct V_164 * V_165 = F_70 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_161 ) ;
if ( ! V_165 )
return;
if ( V_165 -> V_166 . V_7 ) {
V_7 -> V_167 = V_165 -> V_166 . V_7 -> V_167 +
V_147 ;
if ( V_146 ) {
V_7 -> V_81 = V_165 -> V_166 . V_7 -> V_81 - V_147 ;
if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_7 -> V_81 -= 8 ;
if ( V_7 -> type == V_24 )
V_7 -> V_81 -= V_168 ;
if ( V_7 -> V_81 < V_89 )
V_7 -> V_81 = V_89 ;
}
}
F_71 ( V_165 ) ;
}
}
static int F_72 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_146 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_169 = V_36 -> V_169 ;
V_17 -> V_28 . V_87 = V_36 -> V_87 ;
V_17 -> V_28 . V_125 = V_36 -> V_125 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_97 = V_36 -> V_97 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_115 = V_36 -> V_115 ;
V_17 -> V_28 . V_170 = V_36 -> V_170 ;
V_17 -> V_28 . V_52 = V_36 -> V_52 ;
V_17 -> V_28 . V_129 = V_36 -> V_129 ;
F_30 ( & V_17 -> V_56 ) ;
F_25 ( V_17 , V_146 ) ;
return 0 ;
}
static void F_73 ( struct V_35 * V_36 ,
const struct V_171 * V_122 )
{
V_36 -> V_29 = V_122 -> V_29 ;
V_36 -> V_30 = V_122 -> V_30 ;
V_36 -> V_32 = V_122 -> V_32 ;
V_36 -> V_169 = V_122 -> V_169 ;
V_36 -> V_87 = V_122 -> V_87 ;
V_36 -> V_125 = V_122 -> V_125 ;
V_36 -> V_13 = V_122 -> V_13 ;
V_36 -> V_31 = V_122 -> V_31 ;
V_36 -> V_115 = V_122 -> V_115 ;
V_36 -> V_170 = F_74 ( V_122 -> V_170 ) ;
V_36 -> V_52 = F_74 ( V_122 -> V_52 ) ;
memcpy ( V_36 -> V_45 , V_122 -> V_45 , sizeof( V_122 -> V_45 ) ) ;
}
static void F_75 ( struct V_171 * V_122 ,
const struct V_35 * V_36 )
{
V_122 -> V_97 = V_152 ;
V_122 -> V_29 = V_36 -> V_29 ;
V_122 -> V_30 = V_36 -> V_30 ;
V_122 -> V_32 = V_36 -> V_32 ;
V_122 -> V_169 = V_36 -> V_169 ;
V_122 -> V_87 = V_36 -> V_87 ;
V_122 -> V_125 = V_36 -> V_125 ;
V_122 -> V_13 = V_36 -> V_13 ;
V_122 -> V_31 = V_36 -> V_31 ;
V_122 -> V_115 = V_36 -> V_115 ;
V_122 -> V_170 = F_76 ( V_36 -> V_170 ) ;
V_122 -> V_52 = F_76 ( V_36 -> V_52 ) ;
memcpy ( V_122 -> V_45 , V_36 -> V_45 , sizeof( V_122 -> V_45 ) ) ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_172 * V_173 , int V_174 )
{
int V_119 = 0 ;
struct V_171 V_36 ;
struct V_35 V_175 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
switch ( V_174 ) {
case V_176 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_78 ( & V_36 , V_173 -> V_177 . V_178 , sizeof( V_36 ) ) ) {
V_119 = - V_179 ;
break;
}
F_73 ( & V_175 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_175 , 0 ) ;
if ( ! V_17 )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_75 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_79 ( V_173 -> V_177 . V_178 , & V_36 , sizeof( V_36 ) ) )
V_119 = - V_179 ;
break;
case V_180 :
case V_181 :
V_119 = - V_182 ;
if ( ! F_80 ( V_12 -> V_183 , V_184 ) )
goto V_185;
V_119 = - V_179 ;
if ( F_78 ( & V_36 , V_173 -> V_177 . V_178 , sizeof( V_36 ) ) )
goto V_185;
V_119 = - V_186 ;
if ( ( V_36 . V_170 | V_36 . V_52 ) & ( V_71 | V_72 ) )
goto V_185;
if ( ! ( V_36 . V_170 & V_74 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_52 & V_74 ) )
V_36 . V_115 = 0 ;
F_73 ( & V_175 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_175 , V_174 == V_180 ) ;
if ( V_7 != V_20 -> V_34 && V_174 == V_181 ) {
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 ) {
V_119 = - V_187 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_81 () ;
F_72 ( V_17 , & V_175 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_82 ( V_7 ) ;
}
}
if ( V_17 ) {
V_119 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_75 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_79 ( V_173 -> V_177 . V_178 , & V_36 , sizeof( V_36 ) ) )
V_119 = - V_179 ;
} else
V_119 = ( V_174 == V_180 ? - V_188 : - V_189 ) ;
break;
case V_190 :
V_119 = - V_182 ;
if ( ! F_80 ( V_12 -> V_183 , V_184 ) )
goto V_185;
if ( V_7 == V_20 -> V_34 ) {
V_119 = - V_179 ;
if ( F_78 ( & V_36 , V_173 -> V_177 . V_178 , sizeof( V_36 ) ) )
goto V_185;
V_119 = - V_189 ;
F_73 ( & V_175 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_175 , 0 ) ;
if ( ! V_17 )
goto V_185;
V_119 = - V_182 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_185;
V_7 = V_17 -> V_7 ;
}
F_83 ( V_7 ) ;
V_119 = 0 ;
break;
default:
V_119 = - V_186 ;
}
V_185:
return V_119 ;
}
static int F_84 ( struct V_57 * V_58 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_75 , const void * V_76 , unsigned int V_191 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_66 * V_67 = F_85 ( V_58 , V_17 -> V_159 ) ;
T_3 * V_36 = ( T_3 * ) ( V_67 + 1 ) ;
F_86 ( V_67 , 0 ,
F_87 ( F_5 ( V_7 ) , V_58 ,
V_17 -> V_121 . V_122 . V_123 . V_136 , true ,
& V_17 -> V_121 . V_122 . V_123 ) ) ;
V_67 -> V_169 = V_17 -> V_28 . V_169 ;
V_67 -> V_192 = V_116 ;
V_67 -> V_76 = V_17 -> V_28 . V_29 ;
V_67 -> V_75 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_52 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_76 )
memcpy ( & V_67 -> V_76 , V_76 , sizeof( struct V_1 ) ) ;
if ( V_75 )
memcpy ( & V_67 -> V_75 , V_75 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_67 -> V_75 ) )
return V_17 -> V_159 ;
return - V_17 -> V_159 ;
}
static void F_88 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
F_89 ( & V_17 -> V_56 ) ;
F_90 ( V_7 -> V_193 ) ;
}
static void V_48 ( struct V_6 * V_7 )
{
V_7 -> V_194 = & V_195 ;
V_7 -> V_196 = true ;
V_7 -> V_197 = F_88 ;
V_7 -> type = V_25 ;
V_7 -> V_32 |= V_198 ;
V_7 -> V_199 = sizeof( struct V_1 ) ;
F_91 ( V_7 ) ;
V_7 -> V_200 = V_201 ;
F_92 ( V_7 -> V_202 ) ;
}
static int F_93 ( struct V_6 * V_7 )
{
struct V_5 * V_96 ;
int V_140 ;
int V_147 ;
V_96 = F_12 ( V_7 ) ;
V_96 -> V_7 = V_7 ;
V_96 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_96 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_7 -> V_193 = F_94 ( struct V_203 ) ;
if ( ! V_7 -> V_193 )
return - V_204 ;
V_140 = F_95 ( & V_96 -> V_56 , V_205 ) ;
if ( V_140 ) {
F_90 ( V_7 -> V_193 ) ;
V_7 -> V_193 = NULL ;
return V_140 ;
}
V_96 -> V_114 = F_68 ( V_96 -> V_28 . V_52 ) ;
V_96 -> V_159 = V_96 -> V_114 + V_96 -> V_160 ;
V_147 = V_96 -> V_159 + sizeof( struct V_66 ) ;
V_7 -> V_167 = V_206 + V_147 ;
V_7 -> V_81 = V_207 - V_147 ;
if ( V_7 -> type == V_24 )
V_7 -> V_81 -= V_168 ;
if ( ! ( V_96 -> V_28 . V_32 & V_120 ) )
V_7 -> V_81 -= 8 ;
return 0 ;
}
static int F_96 ( struct V_6 * V_7 )
{
struct V_5 * V_96 ;
int V_140 ;
V_140 = F_93 ( V_7 ) ;
if ( V_140 )
return V_140 ;
V_96 = F_12 ( V_7 ) ;
memcpy ( V_7 -> V_148 , & V_96 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_149 , & V_96 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_96 -> V_28 . V_30 ) )
V_7 -> V_112 = & V_208 ;
return 0 ;
}
static void F_97 ( struct V_6 * V_7 )
{
struct V_5 * V_96 = F_12 ( V_7 ) ;
V_96 -> V_7 = V_7 ;
V_96 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_96 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_96 -> V_159 = sizeof( struct V_66 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_98 ( struct V_12 * V_12 , struct V_209 * V_210 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_211 ;
int V_38 ;
F_99 (net, dev, aux)
if ( V_7 -> V_49 == & V_50 ||
V_7 -> V_49 == & V_212 )
F_100 ( V_7 , V_210 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_213 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 ) {
if ( ! F_101 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_100 ( V_17 -> V_7 ,
V_210 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_10 F_102 ( struct V_12 * V_12 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_119 ;
V_20 -> V_34 = F_23 ( sizeof( struct V_5 ) , L_6 ,
V_47 ,
V_48 ) ;
if ( ! V_20 -> V_34 ) {
V_119 = - V_204 ;
goto V_214;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
V_20 -> V_34 -> V_54 |= V_215 ;
F_97 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_49 = & V_50 ;
V_119 = F_103 ( V_20 -> V_34 ) ;
if ( V_119 )
goto V_216;
F_17 ( V_20 -> V_217 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_216:
F_28 ( V_20 -> V_34 ) ;
V_214:
return V_119 ;
}
static void T_11 F_104 ( struct V_12 * V_12 )
{
F_105 ( V_218 ) ;
F_106 () ;
F_98 ( V_12 , & V_218 ) ;
F_107 ( & V_218 ) ;
F_108 () ;
}
static int F_109 ( struct V_219 * V_220 [] , struct V_219 * V_70 [] ,
struct V_221 * V_222 )
{
T_3 V_32 ;
if ( ! V_70 )
return 0 ;
V_32 = 0 ;
if ( V_70 [ V_223 ] )
V_32 |= F_110 ( V_70 [ V_223 ] ) ;
if ( V_70 [ V_224 ] )
V_32 |= F_110 ( V_70 [ V_224 ] ) ;
if ( V_32 & ( V_71 | V_72 ) )
return - V_186 ;
return 0 ;
}
static int F_111 ( struct V_219 * V_220 [] , struct V_219 * V_70 [] ,
struct V_221 * V_222 )
{
struct V_1 V_75 ;
if ( V_220 [ V_225 ] ) {
if ( F_112 ( V_220 [ V_225 ] ) != V_226 )
return - V_186 ;
if ( ! F_113 ( F_114 ( V_220 [ V_225 ] ) ) )
return - V_227 ;
}
if ( ! V_70 )
goto V_228;
if ( V_70 [ V_229 ] ) {
V_75 = F_115 ( V_70 [ V_229 ] ) ;
if ( F_14 ( & V_75 ) )
return - V_186 ;
}
V_228:
return F_109 ( V_220 , V_70 , V_222 ) ;
}
static void F_116 ( struct V_219 * V_70 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_70 )
return;
if ( V_70 [ V_230 ] )
V_28 -> V_13 = F_117 ( V_70 [ V_230 ] ) ;
if ( V_70 [ V_223 ] )
V_28 -> V_170 = F_74 (
F_110 ( V_70 [ V_223 ] ) ) ;
if ( V_70 [ V_224 ] )
V_28 -> V_52 = F_74 (
F_110 ( V_70 [ V_224 ] ) ) ;
if ( V_70 [ V_231 ] )
V_28 -> V_31 = F_118 ( V_70 [ V_231 ] ) ;
if ( V_70 [ V_232 ] )
V_28 -> V_115 = F_118 ( V_70 [ V_232 ] ) ;
if ( V_70 [ V_233 ] )
V_28 -> V_29 = F_115 ( V_70 [ V_233 ] ) ;
if ( V_70 [ V_229 ] )
V_28 -> V_30 = F_115 ( V_70 [ V_229 ] ) ;
if ( V_70 [ V_234 ] )
V_28 -> V_169 = F_119 ( V_70 [ V_234 ] ) ;
if ( V_70 [ V_235 ] )
V_28 -> V_87 = F_119 ( V_70 [ V_235 ] ) ;
if ( V_70 [ V_236 ] )
V_28 -> V_125 = F_118 ( V_70 [ V_236 ] ) ;
if ( V_70 [ V_237 ] )
V_28 -> V_32 = F_117 ( V_70 [ V_237 ] ) ;
if ( V_70 [ V_238 ] )
V_28 -> V_129 = F_117 ( V_70 [ V_238 ] ) ;
}
static int F_120 ( struct V_6 * V_7 )
{
struct V_5 * V_96 ;
int V_140 ;
V_140 = F_93 ( V_7 ) ;
if ( V_140 )
return V_140 ;
V_7 -> V_239 |= V_240 ;
V_96 = F_12 ( V_7 ) ;
F_25 ( V_96 , 1 ) ;
return 0 ;
}
static void F_121 ( struct V_6 * V_7 )
{
F_122 ( V_7 ) ;
V_7 -> V_194 = & V_241 ;
V_7 -> V_196 = true ;
V_7 -> V_197 = F_88 ;
V_7 -> V_54 |= V_215 ;
V_7 -> V_239 &= ~ V_242 ;
V_7 -> V_239 |= V_240 ;
}
static bool F_123 ( struct V_219 * V_70 [] ,
struct V_243 * V_244 )
{
bool V_140 = false ;
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
if ( ! V_70 )
return V_140 ;
if ( V_70 [ V_245 ] ) {
V_140 = true ;
V_244 -> type = F_124 ( V_70 [ V_245 ] ) ;
}
if ( V_70 [ V_246 ] ) {
V_140 = true ;
V_244 -> V_32 = F_124 ( V_70 [ V_246 ] ) ;
}
if ( V_70 [ V_247 ] ) {
V_140 = true ;
V_244 -> V_248 = F_110 ( V_70 [ V_247 ] ) ;
}
if ( V_70 [ V_249 ] ) {
V_140 = true ;
V_244 -> V_250 = F_110 ( V_70 [ V_249 ] ) ;
}
return V_140 ;
}
static int F_125 ( struct V_12 * V_251 , struct V_6 * V_7 ,
struct V_219 * V_220 [] , struct V_219 * V_70 [] ,
struct V_221 * V_222 )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_243 V_244 ;
int V_119 ;
V_44 = F_12 ( V_7 ) ;
if ( F_123 ( V_70 , & V_244 ) ) {
int V_119 = F_126 ( V_44 , & V_244 ) ;
if ( V_119 < 0 )
return V_119 ;
}
F_116 ( V_70 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_187 ;
if ( V_7 -> type == V_24 && ! V_220 [ V_225 ] )
F_127 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_220 [ V_252 ] ) ;
V_7 -> V_54 |= V_253 ;
V_7 -> V_254 |= V_253 ;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) ) {
if ( ! ( V_44 -> V_28 . V_52 & V_131 ) ||
( V_44 -> V_255 . type == V_256 ) ) {
V_7 -> V_54 |= V_257 ;
V_7 -> V_254 |= V_257 ;
}
V_7 -> V_54 |= V_55 ;
}
V_119 = F_26 ( V_7 ) ;
if ( V_119 )
goto V_228;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_228:
return V_119 ;
}
static int F_128 ( struct V_6 * V_7 , struct V_219 * V_220 [] ,
struct V_219 * V_70 [] ,
struct V_221 * V_222 )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
struct V_243 V_244 ;
if ( V_7 == V_20 -> V_34 )
return - V_186 ;
if ( F_123 ( V_70 , & V_244 ) ) {
int V_119 = F_126 ( V_44 , & V_244 ) ;
if ( V_119 < 0 )
return V_119 ;
}
F_116 ( V_70 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_187 ;
} else {
V_17 = V_44 ;
}
F_19 ( V_20 , V_17 ) ;
F_72 ( V_17 , & V_36 , ! V_220 [ V_252 ] ) ;
F_16 ( V_20 , V_17 ) ;
return 0 ;
}
static void F_129 ( struct V_6 * V_7 , struct V_209 * V_210 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_100 ( V_7 , V_210 ) ;
}
static T_12 F_130 ( const struct V_6 * V_7 )
{
return
F_131 ( 4 ) +
F_131 ( 2 ) +
F_131 ( 2 ) +
F_131 ( 4 ) +
F_131 ( 4 ) +
F_131 ( sizeof( struct V_1 ) ) +
F_131 ( sizeof( struct V_1 ) ) +
F_131 ( 1 ) +
F_131 ( 1 ) +
F_131 ( 4 ) +
F_131 ( 4 ) +
F_131 ( 2 ) +
F_131 ( 2 ) +
F_131 ( 2 ) +
F_131 ( 2 ) +
F_131 ( 4 ) +
0 ;
}
static int F_132 ( struct V_57 * V_58 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_133 ( V_58 , V_230 , V_36 -> V_13 ) ||
F_134 ( V_58 , V_223 ,
F_76 ( V_36 -> V_170 ) ) ||
F_134 ( V_58 , V_224 ,
F_76 ( V_36 -> V_52 ) ) ||
F_135 ( V_58 , V_231 , V_36 -> V_31 ) ||
F_135 ( V_58 , V_232 , V_36 -> V_115 ) ||
F_136 ( V_58 , V_233 , & V_36 -> V_29 ) ||
F_136 ( V_58 , V_229 , & V_36 -> V_30 ) ||
F_137 ( V_58 , V_234 , V_36 -> V_169 ) ||
F_137 ( V_58 , V_235 , V_36 -> V_87 ) ||
F_135 ( V_58 , V_236 , V_36 -> V_125 ) ||
F_133 ( V_58 , V_237 , V_36 -> V_32 ) ||
F_133 ( V_58 , V_238 , V_36 -> V_129 ) )
goto V_258;
if ( F_138 ( V_58 , V_245 ,
V_17 -> V_255 . type ) ||
F_134 ( V_58 , V_247 ,
V_17 -> V_255 . V_248 ) ||
F_134 ( V_58 , V_249 ,
V_17 -> V_255 . V_250 ) ||
F_138 ( V_58 , V_246 ,
V_17 -> V_255 . V_32 ) )
goto V_258;
return 0 ;
V_258:
return - V_132 ;
}
static int T_13 F_139 ( void )
{
int V_119 ;
F_140 ( L_7 ) ;
V_119 = F_141 ( & V_259 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_142 ( & V_260 , V_152 ) ;
if ( V_119 < 0 ) {
F_140 ( L_8 , V_261 ) ;
goto V_262;
}
V_119 = F_143 ( & V_50 ) ;
if ( V_119 < 0 )
goto V_263;
V_119 = F_143 ( & V_212 ) ;
if ( V_119 < 0 )
goto V_264;
V_228:
return V_119 ;
V_264:
F_144 ( & V_50 ) ;
V_263:
F_145 ( & V_260 , V_152 ) ;
V_262:
F_146 ( & V_259 ) ;
goto V_228;
}
static void T_14 F_147 ( void )
{
F_144 ( & V_212 ) ;
F_144 ( & V_50 ) ;
F_145 ( & V_260 , V_152 ) ;
F_146 ( & V_259 ) ;
}
