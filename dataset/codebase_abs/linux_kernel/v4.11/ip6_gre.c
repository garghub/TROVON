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
V_108 = F_55 ( V_118 ) ;
if ( V_17 -> V_28 . V_32 & V_124 )
V_110 . V_125 |= F_51 ( ( T_6 ) V_118 -> V_126 << V_127 )
& V_128 ;
if ( V_17 -> V_28 . V_32 & V_129 )
V_110 . V_130 = V_58 -> V_131 ;
V_110 . V_132 = F_56 ( F_5 ( V_7 ) , NULL ) ;
V_119 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_133 ) ) ;
if ( V_119 )
return - 1 ;
V_119 = F_48 ( V_58 , V_7 , V_108 , & V_110 , V_87 , & V_81 ,
V_58 -> V_77 ) ;
if ( V_119 != 0 ) {
if ( V_119 == - V_134 )
F_57 ( V_58 , V_135 , V_136 ,
F_51 ( V_81 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_58 ( struct V_57 * V_58 , struct V_6 * V_7 )
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
V_62 = F_35 ( V_58 , F_59 ( V_58 ) ) ;
V_67 = F_39 ( V_58 ) ;
if ( V_62 > 0 ) {
struct V_79 * V_80 ;
V_80 = (struct V_79 * ) & F_59 ( V_58 ) [ V_62 ] ;
if ( V_80 -> V_87 == 0 ) {
F_44 ( V_58 , V_85 ,
V_86 , V_62 + 2 ) ;
return - 1 ;
}
V_87 = V_80 -> V_87 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_87 = V_17 -> V_28 . V_87 ;
memcpy ( & V_110 , & V_17 -> V_121 . V_122 . V_123 , sizeof( V_110 ) ) ;
V_108 = F_60 ( V_67 ) ;
if ( V_17 -> V_28 . V_32 & V_124 )
V_110 . V_125 |= ( * ( T_2 * ) V_67 & V_128 ) ;
if ( V_17 -> V_28 . V_32 & V_137 )
V_110 . V_125 |= F_61 ( V_67 ) ;
if ( V_17 -> V_28 . V_32 & V_129 )
V_110 . V_130 = V_58 -> V_131 ;
V_110 . V_132 = F_56 ( F_5 ( V_7 ) , NULL ) ;
if ( F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_133 ) ) )
return - 1 ;
V_119 = F_48 ( V_58 , V_7 , V_108 , & V_110 , V_87 ,
& V_81 , V_58 -> V_77 ) ;
if ( V_119 != 0 ) {
if ( V_119 == - V_134 )
F_44 ( V_58 , V_88 , 0 , V_81 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_62 ( const struct V_5 * V_17 ,
const struct V_66 * V_138 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_138 -> V_76 ) ;
}
static int F_63 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_87 = - 1 ;
struct V_109 V_110 ;
T_6 V_81 ;
int V_119 ;
if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_87 = V_17 -> V_28 . V_87 ;
memcpy ( & V_110 , & V_17 -> V_121 . V_122 . V_123 , sizeof( V_110 ) ) ;
V_119 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_133 ) ) ;
if ( V_119 )
return V_119 ;
V_119 = F_48 ( V_58 , V_7 , 0 , & V_110 , V_87 , & V_81 , V_58 -> V_77 ) ;
return V_119 ;
}
static T_7 F_64 ( struct V_57 * V_58 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_139 * V_140 = & V_17 -> V_7 -> V_140 ;
int V_141 ;
if ( ! F_65 ( V_17 , & V_17 -> V_28 . V_29 , & V_17 -> V_28 . V_30 ) )
goto V_142;
switch ( V_58 -> V_77 ) {
case F_8 ( V_143 ) :
V_141 = F_53 ( V_58 , V_7 ) ;
break;
case F_8 ( V_102 ) :
V_141 = F_58 ( V_58 , V_7 ) ;
break;
default:
V_141 = F_63 ( V_58 , V_7 ) ;
break;
}
if ( V_141 < 0 )
goto V_142;
return V_144 ;
V_142:
V_140 -> V_145 ++ ;
V_140 -> V_146 ++ ;
F_45 ( V_58 ) ;
return V_144 ;
}
static void F_25 ( struct V_5 * V_17 , int V_147 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_109 * V_110 = & V_17 -> V_121 . V_122 . V_123 ;
int V_148 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_149 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_150 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_110 -> V_76 = V_36 -> V_29 ;
V_110 -> V_75 = V_36 -> V_30 ;
V_110 -> V_151 = V_36 -> V_13 ;
V_110 -> V_125 = 0 ;
V_110 -> V_152 = V_153 ;
if ( ! ( V_36 -> V_32 & V_124 ) )
V_110 -> V_125 |= V_128 & V_36 -> V_154 ;
if ( ! ( V_36 -> V_32 & V_137 ) )
V_110 -> V_125 |= V_155 & V_36 -> V_154 ;
V_36 -> V_32 &= ~ ( V_156 | V_157 | V_158 ) ;
V_36 -> V_32 |= F_66 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_156 &&
V_36 -> V_32 & V_157 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_159 ;
else
V_7 -> V_32 &= ~ V_159 ;
V_17 -> V_114 = F_67 ( V_17 -> V_28 . V_52 ) ;
V_17 -> V_160 = V_17 -> V_161 + V_17 -> V_114 ;
V_148 = V_17 -> V_160 + sizeof( struct V_66 ) ;
if ( V_36 -> V_32 & V_156 ) {
int V_162 = ( F_68 ( & V_36 -> V_30 ) &
( V_163 | V_164 ) ) ;
struct V_165 * V_166 = F_69 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_162 ) ;
if ( ! V_166 )
return;
if ( V_166 -> V_167 . V_7 ) {
V_7 -> V_168 = V_166 -> V_167 . V_7 -> V_168 +
V_148 ;
if ( V_147 ) {
V_7 -> V_81 = V_166 -> V_167 . V_7 -> V_81 - V_148 ;
if ( ! ( V_17 -> V_28 . V_32 & V_120 ) )
V_7 -> V_81 -= 8 ;
if ( V_7 -> type == V_24 )
V_7 -> V_81 -= V_169 ;
if ( V_7 -> V_81 < V_89 )
V_7 -> V_81 = V_89 ;
}
}
F_70 ( V_166 ) ;
}
}
static int F_71 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_147 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_170 = V_36 -> V_170 ;
V_17 -> V_28 . V_87 = V_36 -> V_87 ;
V_17 -> V_28 . V_154 = V_36 -> V_154 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_97 = V_36 -> V_97 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_115 = V_36 -> V_115 ;
V_17 -> V_28 . V_171 = V_36 -> V_171 ;
V_17 -> V_28 . V_52 = V_36 -> V_52 ;
F_30 ( & V_17 -> V_56 ) ;
F_25 ( V_17 , V_147 ) ;
return 0 ;
}
static void F_72 ( struct V_35 * V_36 ,
const struct V_172 * V_122 )
{
V_36 -> V_29 = V_122 -> V_29 ;
V_36 -> V_30 = V_122 -> V_30 ;
V_36 -> V_32 = V_122 -> V_32 ;
V_36 -> V_170 = V_122 -> V_170 ;
V_36 -> V_87 = V_122 -> V_87 ;
V_36 -> V_154 = V_122 -> V_154 ;
V_36 -> V_13 = V_122 -> V_13 ;
V_36 -> V_31 = V_122 -> V_31 ;
V_36 -> V_115 = V_122 -> V_115 ;
V_36 -> V_171 = F_73 ( V_122 -> V_171 ) ;
V_36 -> V_52 = F_73 ( V_122 -> V_52 ) ;
memcpy ( V_36 -> V_45 , V_122 -> V_45 , sizeof( V_122 -> V_45 ) ) ;
}
static void F_74 ( struct V_172 * V_122 ,
const struct V_35 * V_36 )
{
V_122 -> V_97 = V_153 ;
V_122 -> V_29 = V_36 -> V_29 ;
V_122 -> V_30 = V_36 -> V_30 ;
V_122 -> V_32 = V_36 -> V_32 ;
V_122 -> V_170 = V_36 -> V_170 ;
V_122 -> V_87 = V_36 -> V_87 ;
V_122 -> V_154 = V_36 -> V_154 ;
V_122 -> V_13 = V_36 -> V_13 ;
V_122 -> V_31 = V_36 -> V_31 ;
V_122 -> V_115 = V_36 -> V_115 ;
V_122 -> V_171 = F_75 ( V_36 -> V_171 ) ;
V_122 -> V_52 = F_75 ( V_36 -> V_52 ) ;
memcpy ( V_122 -> V_45 , V_36 -> V_45 , sizeof( V_122 -> V_45 ) ) ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_173 * V_174 , int V_175 )
{
int V_119 = 0 ;
struct V_172 V_36 ;
struct V_35 V_176 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
switch ( V_175 ) {
case V_177 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_77 ( & V_36 , V_174 -> V_178 . V_179 , sizeof( V_36 ) ) ) {
V_119 = - V_180 ;
break;
}
F_72 ( & V_176 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_176 , 0 ) ;
if ( ! V_17 )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_74 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_78 ( V_174 -> V_178 . V_179 , & V_36 , sizeof( V_36 ) ) )
V_119 = - V_180 ;
break;
case V_181 :
case V_182 :
V_119 = - V_183 ;
if ( ! F_79 ( V_12 -> V_184 , V_185 ) )
goto V_186;
V_119 = - V_180 ;
if ( F_77 ( & V_36 , V_174 -> V_178 . V_179 , sizeof( V_36 ) ) )
goto V_186;
V_119 = - V_187 ;
if ( ( V_36 . V_171 | V_36 . V_52 ) & ( V_71 | V_72 ) )
goto V_186;
if ( ! ( V_36 . V_171 & V_74 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_52 & V_74 ) )
V_36 . V_115 = 0 ;
F_72 ( & V_176 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_176 , V_175 == V_181 ) ;
if ( V_7 != V_20 -> V_34 && V_175 == V_182 ) {
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 ) {
V_119 = - V_188 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_80 () ;
F_71 ( V_17 , & V_176 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_81 ( V_7 ) ;
}
}
if ( V_17 ) {
V_119 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_74 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_78 ( V_174 -> V_178 . V_179 , & V_36 , sizeof( V_36 ) ) )
V_119 = - V_180 ;
} else
V_119 = ( V_175 == V_181 ? - V_189 : - V_190 ) ;
break;
case V_191 :
V_119 = - V_183 ;
if ( ! F_79 ( V_12 -> V_184 , V_185 ) )
goto V_186;
if ( V_7 == V_20 -> V_34 ) {
V_119 = - V_180 ;
if ( F_77 ( & V_36 , V_174 -> V_178 . V_179 , sizeof( V_36 ) ) )
goto V_186;
V_119 = - V_190 ;
F_72 ( & V_176 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_176 , 0 ) ;
if ( ! V_17 )
goto V_186;
V_119 = - V_183 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_186;
V_7 = V_17 -> V_7 ;
}
F_82 ( V_7 ) ;
V_119 = 0 ;
break;
default:
V_119 = - V_187 ;
}
V_186:
return V_119 ;
}
static int F_83 ( struct V_57 * V_58 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_75 , const void * V_76 , unsigned int V_192 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_66 * V_67 = (struct V_66 * ) F_84 ( V_58 , V_17 -> V_160 ) ;
T_3 * V_36 = ( T_3 * ) ( V_67 + 1 ) ;
F_85 ( V_67 , 0 ,
F_86 ( F_5 ( V_7 ) , V_58 ,
V_17 -> V_121 . V_122 . V_123 . V_125 , true ,
& V_17 -> V_121 . V_122 . V_123 ) ) ;
V_67 -> V_170 = V_17 -> V_28 . V_170 ;
V_67 -> V_193 = V_116 ;
V_67 -> V_76 = V_17 -> V_28 . V_29 ;
V_67 -> V_75 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_52 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_76 )
memcpy ( & V_67 -> V_76 , V_76 , sizeof( struct V_1 ) ) ;
if ( V_75 )
memcpy ( & V_67 -> V_75 , V_75 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_67 -> V_75 ) )
return V_17 -> V_160 ;
return - V_17 -> V_160 ;
}
static void F_87 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
F_88 ( & V_17 -> V_56 ) ;
F_89 ( V_7 -> V_194 ) ;
F_28 ( V_7 ) ;
}
static void V_48 ( struct V_6 * V_7 )
{
V_7 -> V_195 = & V_196 ;
V_7 -> V_197 = F_87 ;
V_7 -> type = V_25 ;
V_7 -> V_32 |= V_198 ;
V_7 -> V_199 = sizeof( struct V_1 ) ;
F_90 ( V_7 ) ;
V_7 -> V_200 = V_201 ;
F_91 ( V_7 -> V_202 ) ;
}
static int F_92 ( struct V_6 * V_7 )
{
struct V_5 * V_96 ;
int V_141 ;
int V_148 ;
V_96 = F_12 ( V_7 ) ;
V_96 -> V_7 = V_7 ;
V_96 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_96 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_7 -> V_194 = F_93 ( struct V_203 ) ;
if ( ! V_7 -> V_194 )
return - V_204 ;
V_141 = F_94 ( & V_96 -> V_56 , V_205 ) ;
if ( V_141 ) {
F_89 ( V_7 -> V_194 ) ;
V_7 -> V_194 = NULL ;
return V_141 ;
}
V_96 -> V_114 = F_67 ( V_96 -> V_28 . V_52 ) ;
V_96 -> V_160 = V_96 -> V_114 + V_96 -> V_161 ;
V_148 = V_96 -> V_160 + sizeof( struct V_66 ) ;
V_7 -> V_168 = V_206 + V_148 ;
V_7 -> V_81 = V_207 - V_148 ;
if ( V_7 -> type == V_24 )
V_7 -> V_81 -= V_169 ;
if ( ! ( V_96 -> V_28 . V_32 & V_120 ) )
V_7 -> V_81 -= 8 ;
return 0 ;
}
static int F_95 ( struct V_6 * V_7 )
{
struct V_5 * V_96 ;
int V_141 ;
V_141 = F_92 ( V_7 ) ;
if ( V_141 )
return V_141 ;
V_96 = F_12 ( V_7 ) ;
memcpy ( V_7 -> V_149 , & V_96 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_150 , & V_96 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_96 -> V_28 . V_30 ) )
V_7 -> V_112 = & V_208 ;
return 0 ;
}
static void F_96 ( struct V_6 * V_7 )
{
struct V_5 * V_96 = F_12 ( V_7 ) ;
V_96 -> V_7 = V_7 ;
V_96 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_96 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_96 -> V_160 = sizeof( struct V_66 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_97 ( struct V_12 * V_12 , struct V_209 * V_210 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_211 ;
int V_38 ;
F_98 (net, dev, aux)
if ( V_7 -> V_49 == & V_50 ||
V_7 -> V_49 == & V_212 )
F_99 ( V_7 , V_210 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_213 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 ) {
if ( ! F_100 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_99 ( V_17 -> V_7 ,
V_210 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_10 F_101 ( struct V_12 * V_12 )
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
F_96 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_49 = & V_50 ;
V_119 = F_102 ( V_20 -> V_34 ) ;
if ( V_119 )
goto V_216;
F_17 ( V_20 -> V_217 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_216:
F_87 ( V_20 -> V_34 ) ;
V_214:
return V_119 ;
}
static void T_11 F_103 ( struct V_12 * V_12 )
{
F_104 ( V_218 ) ;
F_105 () ;
F_97 ( V_12 , & V_218 ) ;
F_106 ( & V_218 ) ;
F_107 () ;
}
static int F_108 ( struct V_219 * V_220 [] , struct V_219 * V_70 [] )
{
T_3 V_32 ;
if ( ! V_70 )
return 0 ;
V_32 = 0 ;
if ( V_70 [ V_221 ] )
V_32 |= F_109 ( V_70 [ V_221 ] ) ;
if ( V_70 [ V_222 ] )
V_32 |= F_109 ( V_70 [ V_222 ] ) ;
if ( V_32 & ( V_71 | V_72 ) )
return - V_187 ;
return 0 ;
}
static int F_110 ( struct V_219 * V_220 [] , struct V_219 * V_70 [] )
{
struct V_1 V_75 ;
if ( V_220 [ V_223 ] ) {
if ( F_111 ( V_220 [ V_223 ] ) != V_224 )
return - V_187 ;
if ( ! F_112 ( F_113 ( V_220 [ V_223 ] ) ) )
return - V_225 ;
}
if ( ! V_70 )
goto V_226;
if ( V_70 [ V_227 ] ) {
V_75 = F_114 ( V_70 [ V_227 ] ) ;
if ( F_14 ( & V_75 ) )
return - V_187 ;
}
V_226:
return F_108 ( V_220 , V_70 ) ;
}
static void F_115 ( struct V_219 * V_70 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_70 )
return;
if ( V_70 [ V_228 ] )
V_28 -> V_13 = F_116 ( V_70 [ V_228 ] ) ;
if ( V_70 [ V_221 ] )
V_28 -> V_171 = F_73 (
F_109 ( V_70 [ V_221 ] ) ) ;
if ( V_70 [ V_222 ] )
V_28 -> V_52 = F_73 (
F_109 ( V_70 [ V_222 ] ) ) ;
if ( V_70 [ V_229 ] )
V_28 -> V_31 = F_117 ( V_70 [ V_229 ] ) ;
if ( V_70 [ V_230 ] )
V_28 -> V_115 = F_117 ( V_70 [ V_230 ] ) ;
if ( V_70 [ V_231 ] )
V_28 -> V_29 = F_114 ( V_70 [ V_231 ] ) ;
if ( V_70 [ V_227 ] )
V_28 -> V_30 = F_114 ( V_70 [ V_227 ] ) ;
if ( V_70 [ V_232 ] )
V_28 -> V_170 = F_118 ( V_70 [ V_232 ] ) ;
if ( V_70 [ V_233 ] )
V_28 -> V_87 = F_118 ( V_70 [ V_233 ] ) ;
if ( V_70 [ V_234 ] )
V_28 -> V_154 = F_117 ( V_70 [ V_234 ] ) ;
if ( V_70 [ V_235 ] )
V_28 -> V_32 = F_116 ( V_70 [ V_235 ] ) ;
}
static int F_119 ( struct V_6 * V_7 )
{
struct V_5 * V_96 ;
int V_141 ;
V_141 = F_92 ( V_7 ) ;
if ( V_141 )
return V_141 ;
V_7 -> V_236 |= V_237 ;
V_96 = F_12 ( V_7 ) ;
F_25 ( V_96 , 1 ) ;
return 0 ;
}
static void F_120 ( struct V_6 * V_7 )
{
F_121 ( V_7 ) ;
V_7 -> V_195 = & V_238 ;
V_7 -> V_197 = F_87 ;
V_7 -> V_54 |= V_215 ;
V_7 -> V_236 &= ~ V_239 ;
V_7 -> V_236 |= V_237 ;
}
static bool F_122 ( struct V_219 * V_70 [] ,
struct V_240 * V_241 )
{
bool V_141 = false ;
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
if ( ! V_70 )
return V_141 ;
if ( V_70 [ V_242 ] ) {
V_141 = true ;
V_241 -> type = F_123 ( V_70 [ V_242 ] ) ;
}
if ( V_70 [ V_243 ] ) {
V_141 = true ;
V_241 -> V_32 = F_123 ( V_70 [ V_243 ] ) ;
}
if ( V_70 [ V_244 ] ) {
V_141 = true ;
V_241 -> V_245 = F_109 ( V_70 [ V_244 ] ) ;
}
if ( V_70 [ V_246 ] ) {
V_141 = true ;
V_241 -> V_247 = F_109 ( V_70 [ V_246 ] ) ;
}
return V_141 ;
}
static int F_124 ( struct V_12 * V_248 , struct V_6 * V_7 ,
struct V_219 * V_220 [] , struct V_219 * V_70 [] )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_240 V_241 ;
int V_119 ;
V_44 = F_12 ( V_7 ) ;
if ( F_122 ( V_70 , & V_241 ) ) {
int V_119 = F_125 ( V_44 , & V_241 ) ;
if ( V_119 < 0 )
return V_119 ;
}
F_115 ( V_70 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_188 ;
if ( V_7 -> type == V_24 && ! V_220 [ V_223 ] )
F_126 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_220 [ V_249 ] ) ;
V_7 -> V_54 |= V_250 ;
V_7 -> V_251 |= V_250 ;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) ) {
if ( ! ( V_44 -> V_28 . V_52 & V_133 ) ||
( V_44 -> V_252 . type == V_253 ) ) {
V_7 -> V_54 |= V_254 ;
V_7 -> V_251 |= V_254 ;
}
V_7 -> V_54 |= V_55 ;
}
V_119 = F_26 ( V_7 ) ;
if ( V_119 )
goto V_226;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_226:
return V_119 ;
}
static int F_127 ( struct V_6 * V_7 , struct V_219 * V_220 [] ,
struct V_219 * V_70 [] )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
struct V_240 V_241 ;
if ( V_7 == V_20 -> V_34 )
return - V_187 ;
if ( F_122 ( V_70 , & V_241 ) ) {
int V_119 = F_125 ( V_44 , & V_241 ) ;
if ( V_119 < 0 )
return V_119 ;
}
F_115 ( V_70 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_188 ;
} else {
V_17 = V_44 ;
}
F_19 ( V_20 , V_17 ) ;
F_71 ( V_17 , & V_36 , ! V_220 [ V_249 ] ) ;
F_16 ( V_20 , V_17 ) ;
return 0 ;
}
static void F_128 ( struct V_6 * V_7 , struct V_209 * V_210 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_99 ( V_7 , V_210 ) ;
}
static T_12 F_129 ( const struct V_6 * V_7 )
{
return
F_130 ( 4 ) +
F_130 ( 2 ) +
F_130 ( 2 ) +
F_130 ( 4 ) +
F_130 ( 4 ) +
F_130 ( sizeof( struct V_1 ) ) +
F_130 ( sizeof( struct V_1 ) ) +
F_130 ( 1 ) +
F_130 ( 1 ) +
F_130 ( 4 ) +
F_130 ( 4 ) +
F_130 ( 2 ) +
F_130 ( 2 ) +
F_130 ( 2 ) +
F_130 ( 2 ) +
0 ;
}
static int F_131 ( struct V_57 * V_58 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_132 ( V_58 , V_228 , V_36 -> V_13 ) ||
F_133 ( V_58 , V_221 ,
F_75 ( V_36 -> V_171 ) ) ||
F_133 ( V_58 , V_222 ,
F_75 ( V_36 -> V_52 ) ) ||
F_134 ( V_58 , V_229 , V_36 -> V_31 ) ||
F_134 ( V_58 , V_230 , V_36 -> V_115 ) ||
F_135 ( V_58 , V_231 , & V_36 -> V_29 ) ||
F_135 ( V_58 , V_227 , & V_36 -> V_30 ) ||
F_136 ( V_58 , V_232 , V_36 -> V_170 ) ||
F_136 ( V_58 , V_233 , V_36 -> V_87 ) ||
F_134 ( V_58 , V_234 , V_36 -> V_154 ) ||
F_132 ( V_58 , V_235 , V_36 -> V_32 ) )
goto V_255;
if ( F_137 ( V_58 , V_242 ,
V_17 -> V_252 . type ) ||
F_133 ( V_58 , V_244 ,
V_17 -> V_252 . V_245 ) ||
F_133 ( V_58 , V_246 ,
V_17 -> V_252 . V_247 ) ||
F_137 ( V_58 , V_243 ,
V_17 -> V_252 . V_32 ) )
goto V_255;
return 0 ;
V_255:
return - V_134 ;
}
static int T_13 F_138 ( void )
{
int V_119 ;
F_139 ( L_7 ) ;
V_119 = F_140 ( & V_256 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_141 ( & V_257 , V_153 ) ;
if ( V_119 < 0 ) {
F_139 ( L_8 , V_258 ) ;
goto V_259;
}
V_119 = F_142 ( & V_50 ) ;
if ( V_119 < 0 )
goto V_260;
V_119 = F_142 ( & V_212 ) ;
if ( V_119 < 0 )
goto V_261;
V_226:
return V_119 ;
V_261:
F_143 ( & V_50 ) ;
V_260:
F_144 ( & V_257 , V_153 ) ;
V_259:
F_145 ( & V_256 ) ;
goto V_226;
}
static void T_14 F_146 ( void )
{
F_143 ( & V_212 ) ;
F_143 ( & V_50 ) ;
F_144 ( & V_257 , V_153 ) ;
F_145 ( & V_256 ) ;
}
