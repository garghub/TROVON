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
const struct V_64 * V_65 = ( const struct V_64 * ) V_58 -> V_66 ;
T_3 * V_36 = ( T_3 * ) ( V_58 -> V_66 + V_62 ) ;
int V_67 = V_62 + 4 ;
struct V_5 * V_17 ;
T_3 V_32 ;
V_32 = V_36 [ 0 ] ;
if ( V_32 & ( V_68 | V_69 | V_70 | V_71 | V_72 ) ) {
if ( V_32 & ( V_72 | V_71 ) )
return;
if ( V_32 & V_69 ) {
V_67 += 4 ;
if ( V_32 & V_68 )
V_67 += 4 ;
}
}
if ( ! F_33 ( V_58 , V_67 ) )
return;
V_65 = ( const struct V_64 * ) V_58 -> V_66 ;
V_36 = ( T_3 * ) ( V_58 -> V_66 + V_62 ) ;
V_17 = F_4 ( V_58 -> V_7 , & V_65 -> V_73 , & V_65 -> V_74 ,
V_32 & V_69 ?
* ( ( ( T_2 * ) V_36 ) + ( V_67 / 4 ) - 1 ) : 0 ,
V_36 [ 1 ] ) ;
if ( ! V_17 )
return;
switch ( type ) {
T_6 V_75 ;
struct V_76 * V_77 ;
T_6 V_78 ;
case V_79 :
F_34 ( L_2 ,
V_17 -> V_28 . V_45 ) ;
break;
case V_80 :
if ( V_61 == V_81 ) {
F_34 ( L_3 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_82 :
V_75 = 0 ;
if ( V_61 == V_83 )
V_75 = F_35 ( V_58 , V_58 -> V_66 ) ;
if ( V_75 && V_75 == F_36 ( V_63 ) - 2 ) {
V_77 = (struct V_76 * ) & V_58 -> V_66 [ V_75 ] ;
if ( V_77 -> V_84 == 0 ) {
F_34 ( L_4 ,
V_17 -> V_28 . V_45 ) ;
}
} else {
F_34 ( L_5 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_85 :
V_78 = F_36 ( V_63 ) - V_62 ;
if ( V_78 < V_86 )
V_78 = V_86 ;
V_17 -> V_7 -> V_78 = V_78 ;
break;
}
if ( F_37 ( V_87 , V_17 -> V_88 + V_89 ) )
V_17 -> V_90 ++ ;
else
V_17 -> V_90 = 1 ;
V_17 -> V_88 = V_87 ;
}
static int F_38 ( struct V_57 * V_58 , const struct V_91 * V_92 )
{
const struct V_64 * V_65 ;
struct V_5 * V_93 ;
V_65 = F_39 ( V_58 ) ;
V_93 = F_4 ( V_58 -> V_7 ,
& V_65 -> V_74 , & V_65 -> V_73 , V_92 -> V_10 ,
V_92 -> V_94 ) ;
if ( V_93 ) {
F_40 ( V_93 , V_58 , V_92 , NULL , false ) ;
return V_95 ;
}
return V_96 ;
}
static int F_41 ( struct V_57 * V_58 )
{
struct V_91 V_92 ;
bool V_97 = false ;
int V_98 ;
V_98 = F_42 ( V_58 , & V_92 , & V_97 , F_8 ( V_99 ) , 0 ) ;
if ( V_98 < 0 )
goto V_100;
if ( F_43 ( V_58 , V_98 , V_92 . V_94 , false ) )
goto V_100;
if ( F_38 ( V_58 , & V_92 ) == V_95 )
return 0 ;
F_44 ( V_58 , V_79 , V_101 , 0 ) ;
V_100:
F_45 ( V_58 ) ;
return 0 ;
}
static int F_46 ( struct V_57 * V_58 , bool V_102 )
{
return F_47 ( V_58 ,
V_102 ? V_103 : V_104 ) ;
}
static T_7 F_48 ( struct V_57 * V_58 ,
struct V_6 * V_7 , T_8 V_105 ,
struct V_106 * V_107 , int V_84 ,
T_6 * V_108 , T_3 V_94 )
{
struct V_5 * V_93 = F_12 ( V_7 ) ;
T_3 V_109 = ( V_7 -> type == V_24 ) ?
F_8 ( V_23 ) : V_94 ;
if ( V_7 -> type == V_24 )
F_49 ( V_58 ) -> V_32 = 0 ;
if ( V_7 -> V_110 && V_7 -> type == V_25 )
V_107 -> V_73 = ( (struct V_64 * ) V_58 -> V_66 ) -> V_73 ;
else
V_107 -> V_73 = V_93 -> V_28 . V_30 ;
if ( V_93 -> V_28 . V_52 & V_53 )
V_93 -> V_111 ++ ;
F_50 ( V_58 , V_93 -> V_112 , V_93 -> V_28 . V_52 ,
V_109 , V_93 -> V_28 . V_113 , F_51 ( V_93 -> V_111 ) ) ;
return F_52 ( V_58 , V_7 , V_105 , V_107 , V_84 , V_108 ,
V_114 ) ;
}
static inline int F_53 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_115 * V_116 = F_54 ( V_58 ) ;
int V_84 = - 1 ;
struct V_106 V_107 ;
T_8 V_105 ;
T_6 V_78 ;
int V_117 ;
memset ( & ( F_49 ( V_58 ) -> V_60 ) , 0 , sizeof( F_49 ( V_58 ) -> V_60 ) ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_118 ) )
V_84 = V_17 -> V_28 . V_84 ;
memcpy ( & V_107 , & V_17 -> V_119 . V_120 . V_121 , sizeof( V_107 ) ) ;
V_105 = F_55 ( V_116 ) ;
if ( V_17 -> V_28 . V_32 & V_122 )
V_107 . V_123 |= F_51 ( ( T_6 ) V_116 -> V_124 << V_125 )
& V_126 ;
if ( V_17 -> V_28 . V_32 & V_127 )
V_107 . V_128 = V_58 -> V_129 ;
V_117 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_130 ) ) ;
if ( V_117 )
return - 1 ;
V_117 = F_48 ( V_58 , V_7 , V_105 , & V_107 , V_84 , & V_78 ,
V_58 -> V_109 ) ;
if ( V_117 != 0 ) {
if ( V_117 == - V_131 )
F_56 ( V_58 , V_132 , V_133 ,
F_51 ( V_78 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_57 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_64 * V_65 = F_39 ( V_58 ) ;
int V_84 = - 1 ;
T_9 V_62 ;
struct V_106 V_107 ;
T_8 V_105 ;
T_6 V_78 ;
int V_117 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_65 -> V_74 ) )
return - 1 ;
V_62 = F_35 ( V_58 , F_58 ( V_58 ) ) ;
if ( V_62 > 0 ) {
struct V_76 * V_77 ;
V_77 = (struct V_76 * ) & F_58 ( V_58 ) [ V_62 ] ;
if ( V_77 -> V_84 == 0 ) {
F_44 ( V_58 , V_82 ,
V_83 , V_62 + 2 ) ;
return - 1 ;
}
V_84 = V_77 -> V_84 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_118 ) )
V_84 = V_17 -> V_28 . V_84 ;
memcpy ( & V_107 , & V_17 -> V_119 . V_120 . V_121 , sizeof( V_107 ) ) ;
V_105 = F_59 ( V_65 ) ;
if ( V_17 -> V_28 . V_32 & V_122 )
V_107 . V_123 |= ( * ( T_2 * ) V_65 & V_126 ) ;
if ( V_17 -> V_28 . V_32 & V_134 )
V_107 . V_123 |= F_60 ( V_65 ) ;
if ( V_17 -> V_28 . V_32 & V_127 )
V_107 . V_128 = V_58 -> V_129 ;
if ( F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_130 ) ) )
return - 1 ;
V_117 = F_48 ( V_58 , V_7 , V_105 , & V_107 , V_84 ,
& V_78 , V_58 -> V_109 ) ;
if ( V_117 != 0 ) {
if ( V_117 == - V_131 )
F_44 ( V_58 , V_85 , 0 , V_78 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_61 ( const struct V_5 * V_17 ,
const struct V_64 * V_135 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_135 -> V_74 ) ;
}
static int F_62 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_84 = - 1 ;
struct V_106 V_107 ;
T_6 V_78 ;
int V_117 ;
if ( ! ( V_17 -> V_28 . V_32 & V_118 ) )
V_84 = V_17 -> V_28 . V_84 ;
memcpy ( & V_107 , & V_17 -> V_119 . V_120 . V_121 , sizeof( V_107 ) ) ;
V_117 = F_46 ( V_58 , ! ! ( V_17 -> V_28 . V_52 & V_130 ) ) ;
if ( V_117 )
return V_117 ;
V_117 = F_48 ( V_58 , V_7 , 0 , & V_107 , V_84 , & V_78 , V_58 -> V_109 ) ;
return V_117 ;
}
static T_7 F_63 ( struct V_57 * V_58 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_136 * V_137 = & V_17 -> V_7 -> V_137 ;
int V_138 ;
if ( ! F_64 ( V_17 , & V_17 -> V_28 . V_29 , & V_17 -> V_28 . V_30 ) )
goto V_139;
switch ( V_58 -> V_109 ) {
case F_8 ( V_140 ) :
V_138 = F_53 ( V_58 , V_7 ) ;
break;
case F_8 ( V_99 ) :
V_138 = F_57 ( V_58 , V_7 ) ;
break;
default:
V_138 = F_62 ( V_58 , V_7 ) ;
break;
}
if ( V_138 < 0 )
goto V_139;
return V_141 ;
V_139:
V_137 -> V_142 ++ ;
V_137 -> V_143 ++ ;
F_45 ( V_58 ) ;
return V_141 ;
}
static void F_25 ( struct V_5 * V_17 , int V_144 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_106 * V_107 = & V_17 -> V_119 . V_120 . V_121 ;
int V_145 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_146 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_147 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_107 -> V_74 = V_36 -> V_29 ;
V_107 -> V_73 = V_36 -> V_30 ;
V_107 -> V_148 = V_36 -> V_13 ;
V_107 -> V_123 = 0 ;
V_107 -> V_149 = V_150 ;
if ( ! ( V_36 -> V_32 & V_122 ) )
V_107 -> V_123 |= V_126 & V_36 -> V_151 ;
if ( ! ( V_36 -> V_32 & V_134 ) )
V_107 -> V_123 |= V_152 & V_36 -> V_151 ;
V_36 -> V_32 &= ~ ( V_153 | V_154 | V_155 ) ;
V_36 -> V_32 |= F_65 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_153 &&
V_36 -> V_32 & V_154 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_156 ;
else
V_7 -> V_32 &= ~ V_156 ;
V_17 -> V_112 = F_66 ( V_17 -> V_28 . V_52 ) ;
V_17 -> V_157 = V_17 -> V_158 + V_17 -> V_112 ;
V_145 = V_17 -> V_157 + sizeof( struct V_64 ) ;
if ( V_36 -> V_32 & V_153 ) {
int V_159 = ( F_67 ( & V_36 -> V_30 ) &
( V_160 | V_161 ) ) ;
struct V_162 * V_163 = F_68 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_159 ) ;
if ( ! V_163 )
return;
if ( V_163 -> V_164 . V_7 ) {
V_7 -> V_165 = V_163 -> V_164 . V_7 -> V_165 +
V_145 ;
if ( V_144 ) {
V_7 -> V_78 = V_163 -> V_164 . V_7 -> V_78 - V_145 ;
if ( ! ( V_17 -> V_28 . V_32 & V_118 ) )
V_7 -> V_78 -= 8 ;
if ( V_7 -> type == V_24 )
V_7 -> V_78 -= V_166 ;
if ( V_7 -> V_78 < V_86 )
V_7 -> V_78 = V_86 ;
}
}
F_69 ( V_163 ) ;
}
}
static int F_70 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_144 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_167 = V_36 -> V_167 ;
V_17 -> V_28 . V_84 = V_36 -> V_84 ;
V_17 -> V_28 . V_151 = V_36 -> V_151 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_94 = V_36 -> V_94 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_113 = V_36 -> V_113 ;
V_17 -> V_28 . V_168 = V_36 -> V_168 ;
V_17 -> V_28 . V_52 = V_36 -> V_52 ;
F_30 ( & V_17 -> V_56 ) ;
F_25 ( V_17 , V_144 ) ;
return 0 ;
}
static void F_71 ( struct V_35 * V_36 ,
const struct V_169 * V_120 )
{
V_36 -> V_29 = V_120 -> V_29 ;
V_36 -> V_30 = V_120 -> V_30 ;
V_36 -> V_32 = V_120 -> V_32 ;
V_36 -> V_167 = V_120 -> V_167 ;
V_36 -> V_84 = V_120 -> V_84 ;
V_36 -> V_151 = V_120 -> V_151 ;
V_36 -> V_13 = V_120 -> V_13 ;
V_36 -> V_31 = V_120 -> V_31 ;
V_36 -> V_113 = V_120 -> V_113 ;
V_36 -> V_168 = F_72 ( V_120 -> V_168 ) ;
V_36 -> V_52 = F_72 ( V_120 -> V_52 ) ;
memcpy ( V_36 -> V_45 , V_120 -> V_45 , sizeof( V_120 -> V_45 ) ) ;
}
static void F_73 ( struct V_169 * V_120 ,
const struct V_35 * V_36 )
{
V_120 -> V_94 = V_150 ;
V_120 -> V_29 = V_36 -> V_29 ;
V_120 -> V_30 = V_36 -> V_30 ;
V_120 -> V_32 = V_36 -> V_32 ;
V_120 -> V_167 = V_36 -> V_167 ;
V_120 -> V_84 = V_36 -> V_84 ;
V_120 -> V_151 = V_36 -> V_151 ;
V_120 -> V_13 = V_36 -> V_13 ;
V_120 -> V_31 = V_36 -> V_31 ;
V_120 -> V_113 = V_36 -> V_113 ;
V_120 -> V_168 = F_74 ( V_36 -> V_168 ) ;
V_120 -> V_52 = F_74 ( V_36 -> V_52 ) ;
memcpy ( V_120 -> V_45 , V_36 -> V_45 , sizeof( V_120 -> V_45 ) ) ;
}
static int F_75 ( struct V_6 * V_7 ,
struct V_170 * V_171 , int V_172 )
{
int V_117 = 0 ;
struct V_169 V_36 ;
struct V_35 V_173 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
switch ( V_172 ) {
case V_174 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_76 ( & V_36 , V_171 -> V_175 . V_176 , sizeof( V_36 ) ) ) {
V_117 = - V_177 ;
break;
}
F_71 ( & V_173 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_173 , 0 ) ;
if ( ! V_17 )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_73 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_77 ( V_171 -> V_175 . V_176 , & V_36 , sizeof( V_36 ) ) )
V_117 = - V_177 ;
break;
case V_178 :
case V_179 :
V_117 = - V_180 ;
if ( ! F_78 ( V_12 -> V_181 , V_182 ) )
goto V_183;
V_117 = - V_177 ;
if ( F_76 ( & V_36 , V_171 -> V_175 . V_176 , sizeof( V_36 ) ) )
goto V_183;
V_117 = - V_184 ;
if ( ( V_36 . V_168 | V_36 . V_52 ) & ( V_72 | V_71 ) )
goto V_183;
if ( ! ( V_36 . V_168 & V_69 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_52 & V_69 ) )
V_36 . V_113 = 0 ;
F_71 ( & V_173 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_173 , V_172 == V_178 ) ;
if ( V_7 != V_20 -> V_34 && V_172 == V_179 ) {
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 ) {
V_117 = - V_185 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_79 () ;
F_70 ( V_17 , & V_173 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_80 ( V_7 ) ;
}
}
if ( V_17 ) {
V_117 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_73 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_77 ( V_171 -> V_175 . V_176 , & V_36 , sizeof( V_36 ) ) )
V_117 = - V_177 ;
} else
V_117 = ( V_172 == V_178 ? - V_186 : - V_187 ) ;
break;
case V_188 :
V_117 = - V_180 ;
if ( ! F_78 ( V_12 -> V_181 , V_182 ) )
goto V_183;
if ( V_7 == V_20 -> V_34 ) {
V_117 = - V_177 ;
if ( F_76 ( & V_36 , V_171 -> V_175 . V_176 , sizeof( V_36 ) ) )
goto V_183;
V_117 = - V_187 ;
F_71 ( & V_173 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_173 , 0 ) ;
if ( ! V_17 )
goto V_183;
V_117 = - V_180 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_183;
V_7 = V_17 -> V_7 ;
}
F_81 ( V_7 ) ;
V_117 = 0 ;
break;
default:
V_117 = - V_184 ;
}
V_183:
return V_117 ;
}
static int F_82 ( struct V_57 * V_58 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_73 , const void * V_74 , unsigned int V_189 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_64 * V_65 = (struct V_64 * ) F_83 ( V_58 , V_17 -> V_157 ) ;
T_3 * V_36 = ( T_3 * ) ( V_65 + 1 ) ;
F_84 ( V_65 , 0 ,
F_85 ( F_5 ( V_7 ) , V_58 ,
V_17 -> V_119 . V_120 . V_121 . V_123 , true ,
& V_17 -> V_119 . V_120 . V_121 ) ) ;
V_65 -> V_167 = V_17 -> V_28 . V_167 ;
V_65 -> V_190 = V_114 ;
V_65 -> V_74 = V_17 -> V_28 . V_29 ;
V_65 -> V_73 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_52 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_74 )
memcpy ( & V_65 -> V_74 , V_74 , sizeof( struct V_1 ) ) ;
if ( V_73 )
memcpy ( & V_65 -> V_73 , V_73 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_65 -> V_73 ) )
return V_17 -> V_157 ;
return - V_17 -> V_157 ;
}
static void F_86 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
F_87 ( & V_17 -> V_56 ) ;
F_88 ( V_7 -> V_191 ) ;
F_28 ( V_7 ) ;
}
static void V_48 ( struct V_6 * V_7 )
{
V_7 -> V_192 = & V_193 ;
V_7 -> V_194 = F_86 ;
V_7 -> type = V_25 ;
V_7 -> V_32 |= V_195 ;
V_7 -> V_196 = sizeof( struct V_1 ) ;
F_89 ( V_7 ) ;
}
static int F_90 ( struct V_6 * V_7 )
{
struct V_5 * V_93 ;
int V_138 ;
int V_145 ;
V_93 = F_12 ( V_7 ) ;
V_93 -> V_7 = V_7 ;
V_93 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_93 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_7 -> V_191 = F_91 ( struct V_197 ) ;
if ( ! V_7 -> V_191 )
return - V_198 ;
V_138 = F_92 ( & V_93 -> V_56 , V_199 ) ;
if ( V_138 ) {
F_88 ( V_7 -> V_191 ) ;
V_7 -> V_191 = NULL ;
return V_138 ;
}
V_93 -> V_112 = F_66 ( V_93 -> V_28 . V_52 ) ;
V_93 -> V_157 = V_93 -> V_112 + V_93 -> V_158 ;
V_145 = V_93 -> V_157 + sizeof( struct V_64 ) ;
V_7 -> V_165 = V_200 + V_145 ;
V_7 -> V_78 = V_201 - V_145 ;
if ( V_7 -> type == V_24 )
V_7 -> V_78 -= V_166 ;
if ( ! ( V_93 -> V_28 . V_32 & V_118 ) )
V_7 -> V_78 -= 8 ;
return 0 ;
}
static int F_93 ( struct V_6 * V_7 )
{
struct V_5 * V_93 ;
int V_138 ;
V_138 = F_90 ( V_7 ) ;
if ( V_138 )
return V_138 ;
V_93 = F_12 ( V_7 ) ;
memcpy ( V_7 -> V_146 , & V_93 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_147 , & V_93 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_93 -> V_28 . V_30 ) )
V_7 -> V_110 = & V_202 ;
return 0 ;
}
static void F_94 ( struct V_6 * V_7 )
{
struct V_5 * V_93 = F_12 ( V_7 ) ;
V_93 -> V_7 = V_7 ;
V_93 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_93 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_93 -> V_157 = sizeof( struct V_64 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_95 ( struct V_12 * V_12 , struct V_203 * V_204 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_205 ;
int V_38 ;
F_96 (net, dev, aux)
if ( V_7 -> V_49 == & V_50 ||
V_7 -> V_49 == & V_206 )
F_97 ( V_7 , V_204 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_207 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 ) {
if ( ! F_98 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_97 ( V_17 -> V_7 ,
V_204 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_10 F_99 ( struct V_12 * V_12 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_117 ;
V_20 -> V_34 = F_23 ( sizeof( struct V_5 ) , L_6 ,
V_47 ,
V_48 ) ;
if ( ! V_20 -> V_34 ) {
V_117 = - V_198 ;
goto V_208;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
V_20 -> V_34 -> V_54 |= V_209 ;
F_94 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_49 = & V_50 ;
V_117 = F_100 ( V_20 -> V_34 ) ;
if ( V_117 )
goto V_210;
F_17 ( V_20 -> V_211 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_210:
F_86 ( V_20 -> V_34 ) ;
V_208:
return V_117 ;
}
static void T_11 F_101 ( struct V_12 * V_12 )
{
F_102 ( V_212 ) ;
F_103 () ;
F_95 ( V_12 , & V_212 ) ;
F_104 ( & V_212 ) ;
F_105 () ;
}
static int F_106 ( struct V_213 * V_214 [] , struct V_213 * V_66 [] )
{
T_3 V_32 ;
if ( ! V_66 )
return 0 ;
V_32 = 0 ;
if ( V_66 [ V_215 ] )
V_32 |= F_107 ( V_66 [ V_215 ] ) ;
if ( V_66 [ V_216 ] )
V_32 |= F_107 ( V_66 [ V_216 ] ) ;
if ( V_32 & ( V_72 | V_71 ) )
return - V_184 ;
return 0 ;
}
static int F_108 ( struct V_213 * V_214 [] , struct V_213 * V_66 [] )
{
struct V_1 V_73 ;
if ( V_214 [ V_217 ] ) {
if ( F_109 ( V_214 [ V_217 ] ) != V_218 )
return - V_184 ;
if ( ! F_110 ( F_111 ( V_214 [ V_217 ] ) ) )
return - V_219 ;
}
if ( ! V_66 )
goto V_220;
if ( V_66 [ V_221 ] ) {
V_73 = F_112 ( V_66 [ V_221 ] ) ;
if ( F_14 ( & V_73 ) )
return - V_184 ;
}
V_220:
return F_106 ( V_214 , V_66 ) ;
}
static void F_113 ( struct V_213 * V_66 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_66 )
return;
if ( V_66 [ V_222 ] )
V_28 -> V_13 = F_114 ( V_66 [ V_222 ] ) ;
if ( V_66 [ V_215 ] )
V_28 -> V_168 = F_72 (
F_107 ( V_66 [ V_215 ] ) ) ;
if ( V_66 [ V_216 ] )
V_28 -> V_52 = F_72 (
F_107 ( V_66 [ V_216 ] ) ) ;
if ( V_66 [ V_223 ] )
V_28 -> V_31 = F_115 ( V_66 [ V_223 ] ) ;
if ( V_66 [ V_224 ] )
V_28 -> V_113 = F_115 ( V_66 [ V_224 ] ) ;
if ( V_66 [ V_225 ] )
V_28 -> V_29 = F_112 ( V_66 [ V_225 ] ) ;
if ( V_66 [ V_221 ] )
V_28 -> V_30 = F_112 ( V_66 [ V_221 ] ) ;
if ( V_66 [ V_226 ] )
V_28 -> V_167 = F_116 ( V_66 [ V_226 ] ) ;
if ( V_66 [ V_227 ] )
V_28 -> V_84 = F_116 ( V_66 [ V_227 ] ) ;
if ( V_66 [ V_228 ] )
V_28 -> V_151 = F_114 ( V_66 [ V_228 ] ) ;
if ( V_66 [ V_229 ] )
V_28 -> V_32 = F_114 ( V_66 [ V_229 ] ) ;
}
static int F_117 ( struct V_6 * V_7 )
{
struct V_5 * V_93 ;
int V_138 ;
V_138 = F_90 ( V_7 ) ;
if ( V_138 )
return V_138 ;
V_7 -> V_230 |= V_231 ;
V_93 = F_12 ( V_7 ) ;
F_25 ( V_93 , 1 ) ;
return 0 ;
}
static void F_118 ( struct V_6 * V_7 )
{
F_119 ( V_7 ) ;
V_7 -> V_192 = & V_232 ;
V_7 -> V_194 = F_86 ;
V_7 -> V_54 |= V_209 ;
V_7 -> V_230 &= ~ V_233 ;
V_7 -> V_230 |= V_231 ;
}
static bool F_120 ( struct V_213 * V_66 [] ,
struct V_234 * V_235 )
{
bool V_138 = false ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
if ( ! V_66 )
return V_138 ;
if ( V_66 [ V_236 ] ) {
V_138 = true ;
V_235 -> type = F_121 ( V_66 [ V_236 ] ) ;
}
if ( V_66 [ V_237 ] ) {
V_138 = true ;
V_235 -> V_32 = F_121 ( V_66 [ V_237 ] ) ;
}
if ( V_66 [ V_238 ] ) {
V_138 = true ;
V_235 -> V_239 = F_107 ( V_66 [ V_238 ] ) ;
}
if ( V_66 [ V_240 ] ) {
V_138 = true ;
V_235 -> V_241 = F_107 ( V_66 [ V_240 ] ) ;
}
return V_138 ;
}
static int F_122 ( struct V_12 * V_242 , struct V_6 * V_7 ,
struct V_213 * V_214 [] , struct V_213 * V_66 [] )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_234 V_235 ;
int V_117 ;
V_44 = F_12 ( V_7 ) ;
if ( F_120 ( V_66 , & V_235 ) ) {
int V_117 = F_123 ( V_44 , & V_235 ) ;
if ( V_117 < 0 )
return V_117 ;
}
F_113 ( V_66 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_185 ;
if ( V_7 -> type == V_24 && ! V_214 [ V_217 ] )
F_124 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_214 [ V_243 ] ) ;
V_7 -> V_54 |= V_244 ;
V_7 -> V_245 |= V_244 ;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) ) {
if ( ! ( V_44 -> V_28 . V_52 & V_130 ) ||
( V_44 -> V_246 . type == V_247 ) ) {
V_7 -> V_54 |= V_248 ;
V_7 -> V_245 |= V_248 ;
}
V_7 -> V_54 |= V_55 ;
}
V_117 = F_26 ( V_7 ) ;
if ( V_117 )
goto V_220;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_220:
return V_117 ;
}
static int F_125 ( struct V_6 * V_7 , struct V_213 * V_214 [] ,
struct V_213 * V_66 [] )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
struct V_234 V_235 ;
if ( V_7 == V_20 -> V_34 )
return - V_184 ;
if ( F_120 ( V_66 , & V_235 ) ) {
int V_117 = F_123 ( V_44 , & V_235 ) ;
if ( V_117 < 0 )
return V_117 ;
}
F_113 ( V_66 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_185 ;
} else {
V_17 = V_44 ;
}
F_19 ( V_20 , V_17 ) ;
F_70 ( V_17 , & V_36 , ! V_214 [ V_243 ] ) ;
F_16 ( V_20 , V_17 ) ;
return 0 ;
}
static void F_126 ( struct V_6 * V_7 , struct V_203 * V_204 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_97 ( V_7 , V_204 ) ;
}
static T_12 F_127 ( const struct V_6 * V_7 )
{
return
F_128 ( 4 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 4 ) +
F_128 ( 4 ) +
F_128 ( sizeof( struct V_1 ) ) +
F_128 ( sizeof( struct V_1 ) ) +
F_128 ( 1 ) +
F_128 ( 1 ) +
F_128 ( 4 ) +
F_128 ( 4 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
0 ;
}
static int F_129 ( struct V_57 * V_58 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_130 ( V_58 , V_222 , V_36 -> V_13 ) ||
F_131 ( V_58 , V_215 ,
F_74 ( V_36 -> V_168 ) ) ||
F_131 ( V_58 , V_216 ,
F_74 ( V_36 -> V_52 ) ) ||
F_132 ( V_58 , V_223 , V_36 -> V_31 ) ||
F_132 ( V_58 , V_224 , V_36 -> V_113 ) ||
F_133 ( V_58 , V_225 , & V_36 -> V_29 ) ||
F_133 ( V_58 , V_221 , & V_36 -> V_30 ) ||
F_134 ( V_58 , V_226 , V_36 -> V_167 ) ||
F_134 ( V_58 , V_227 , V_36 -> V_84 ) ||
F_132 ( V_58 , V_228 , V_36 -> V_151 ) ||
F_130 ( V_58 , V_229 , V_36 -> V_32 ) )
goto V_249;
if ( F_135 ( V_58 , V_236 ,
V_17 -> V_246 . type ) ||
F_131 ( V_58 , V_238 ,
V_17 -> V_246 . V_239 ) ||
F_131 ( V_58 , V_240 ,
V_17 -> V_246 . V_241 ) ||
F_135 ( V_58 , V_237 ,
V_17 -> V_246 . V_32 ) )
goto V_249;
return 0 ;
V_249:
return - V_131 ;
}
static int T_13 F_136 ( void )
{
int V_117 ;
F_137 ( L_7 ) ;
V_117 = F_138 ( & V_250 ) ;
if ( V_117 < 0 )
return V_117 ;
V_117 = F_139 ( & V_251 , V_150 ) ;
if ( V_117 < 0 ) {
F_137 ( L_8 , V_252 ) ;
goto V_253;
}
V_117 = F_140 ( & V_50 ) ;
if ( V_117 < 0 )
goto V_254;
V_117 = F_140 ( & V_206 ) ;
if ( V_117 < 0 )
goto V_255;
V_220:
return V_117 ;
V_255:
F_141 ( & V_50 ) ;
V_254:
F_142 ( & V_251 , V_150 ) ;
V_253:
F_143 ( & V_250 ) ;
goto V_220;
}
static void T_14 F_144 ( void )
{
F_141 ( & V_206 ) ;
F_141 ( & V_50 ) ;
F_142 ( & V_251 , V_150 ) ;
F_143 ( & V_250 ) ;
}
