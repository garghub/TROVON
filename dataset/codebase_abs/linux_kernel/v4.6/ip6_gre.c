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
if ( V_32 & ( V_68 | V_69 | V_53 | V_70 | V_71 ) ) {
if ( V_32 & ( V_71 | V_70 ) )
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
V_17 = F_4 ( V_58 -> V_7 , & V_65 -> V_72 , & V_65 -> V_73 ,
V_32 & V_69 ?
* ( ( ( T_2 * ) V_36 ) + ( V_67 / 4 ) - 1 ) : 0 ,
V_36 [ 1 ] ) ;
if ( ! V_17 )
return;
switch ( type ) {
T_6 V_74 ;
struct V_75 * V_76 ;
T_6 V_77 ;
case V_78 :
F_34 ( L_2 ,
V_17 -> V_28 . V_45 ) ;
break;
case V_79 :
if ( V_61 == V_80 ) {
F_34 ( L_3 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_81 :
V_74 = 0 ;
if ( V_61 == V_82 )
V_74 = F_35 ( V_58 , V_58 -> V_66 ) ;
if ( V_74 && V_74 == F_36 ( V_63 ) - 2 ) {
V_76 = (struct V_75 * ) & V_58 -> V_66 [ V_74 ] ;
if ( V_76 -> V_83 == 0 ) {
F_34 ( L_4 ,
V_17 -> V_28 . V_45 ) ;
}
} else {
F_34 ( L_5 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_84 :
V_77 = F_36 ( V_63 ) - V_62 ;
if ( V_77 < V_85 )
V_77 = V_85 ;
V_17 -> V_7 -> V_77 = V_77 ;
break;
}
if ( F_37 ( V_86 , V_17 -> V_87 + V_88 ) )
V_17 -> V_89 ++ ;
else
V_17 -> V_89 = 1 ;
V_17 -> V_87 = V_86 ;
}
static int F_38 ( struct V_57 * V_58 )
{
const struct V_64 * V_65 ;
T_5 * V_37 ;
T_3 V_32 ;
T_7 V_90 = 0 ;
T_2 V_10 = 0 ;
T_1 V_91 = 0 ;
struct V_5 * V_92 ;
int V_62 = 4 ;
T_3 V_11 ;
int V_93 ;
if ( ! F_33 ( V_58 , sizeof( struct V_1 ) ) )
goto V_94;
V_65 = F_39 ( V_58 ) ;
V_37 = V_58 -> V_66 ;
V_32 = * ( T_3 * ) V_37 ;
if ( V_32 & ( V_68 | V_69 | V_70 | V_53 | V_71 ) ) {
if ( V_32 & ( V_71 | V_70 ) )
goto V_94;
if ( V_32 & V_68 ) {
V_90 = F_40 ( V_58 ) ;
V_62 += 4 ;
}
if ( V_32 & V_69 ) {
V_10 = * ( T_2 * ) ( V_37 + V_62 ) ;
V_62 += 4 ;
}
if ( V_32 & V_53 ) {
V_91 = F_41 ( * ( T_2 * ) ( V_37 + V_62 ) ) ;
V_62 += 4 ;
}
}
V_11 = * ( T_3 * ) ( V_37 + 2 ) ;
V_92 = F_4 ( V_58 -> V_7 ,
& V_65 -> V_73 , & V_65 -> V_72 , V_10 ,
V_11 ) ;
if ( V_92 ) {
struct V_95 * V_96 ;
if ( ! F_42 ( NULL , V_97 , V_58 ) )
goto V_94;
if ( ! F_43 ( V_92 , & V_65 -> V_72 , & V_65 -> V_73 ) ) {
V_92 -> V_7 -> V_98 . V_99 ++ ;
goto V_94;
}
V_58 -> V_100 = V_11 ;
if ( V_32 == 0 && V_11 == F_8 ( V_101 ) ) {
V_58 -> V_100 = F_8 ( V_102 ) ;
if ( ( * ( V_37 + V_62 ) & 0xF0 ) != 0x40 )
V_62 += 4 ;
}
V_58 -> V_103 = V_58 -> V_104 ;
F_44 ( V_58 , V_62 ) ;
F_45 ( V_58 , F_46 ( V_58 ) , V_62 ) ;
if ( ( ( V_32 & V_68 ) && V_90 ) ||
( ! ( V_32 & V_68 ) && V_92 -> V_28 . V_105 & V_68 ) ) {
V_92 -> V_7 -> V_98 . V_106 ++ ;
V_92 -> V_7 -> V_98 . V_107 ++ ;
goto V_94;
}
if ( V_92 -> V_28 . V_105 & V_53 ) {
if ( ! ( V_32 & V_53 ) ||
( V_92 -> V_108 &&
( V_109 ) ( V_91 - V_92 -> V_108 ) < 0 ) ) {
V_92 -> V_7 -> V_98 . V_110 ++ ;
V_92 -> V_7 -> V_98 . V_107 ++ ;
goto V_94;
}
V_92 -> V_108 = V_91 + 1 ;
}
if ( V_92 -> V_7 -> type == V_24 ) {
if ( ! F_33 ( V_58 , V_111 ) ) {
V_92 -> V_7 -> V_98 . V_112 ++ ;
V_92 -> V_7 -> V_98 . V_107 ++ ;
goto V_94;
}
V_65 = F_39 ( V_58 ) ;
V_58 -> V_100 = F_47 ( V_58 , V_92 -> V_7 ) ;
F_45 ( V_58 , F_48 ( V_58 ) , V_111 ) ;
}
F_49 ( V_58 , V_92 -> V_7 , V_92 -> V_12 ) ;
F_50 ( V_58 ) ;
V_93 = F_51 ( V_65 , V_58 ) ;
if ( F_52 ( V_93 ) ) {
if ( V_113 )
F_53 ( L_6 ,
& V_65 -> V_73 ,
F_54 ( V_65 ) ) ;
if ( V_93 > 1 ) {
++ V_92 -> V_7 -> V_98 . V_114 ;
++ V_92 -> V_7 -> V_98 . V_107 ;
goto V_94;
}
}
V_96 = F_55 ( V_92 -> V_7 -> V_96 ) ;
F_56 ( & V_96 -> V_115 ) ;
V_96 -> V_116 ++ ;
V_96 -> V_117 += V_58 -> V_118 ;
F_57 ( & V_96 -> V_115 ) ;
F_58 ( V_58 ) ;
return 0 ;
}
F_59 ( V_58 , V_78 , V_119 , 0 ) ;
V_94:
F_60 ( V_58 ) ;
return 0 ;
}
static void F_61 ( struct V_120 * V_60 , T_8 V_83 )
{
memset ( V_60 , 0 , sizeof( struct V_120 ) ) ;
V_60 -> V_121 [ 2 ] = V_122 ;
V_60 -> V_121 [ 3 ] = 1 ;
V_60 -> V_121 [ 4 ] = V_83 ;
V_60 -> V_121 [ 5 ] = V_123 ;
V_60 -> V_121 [ 6 ] = 1 ;
V_60 -> V_124 . V_125 = (struct V_126 * ) V_60 -> V_121 ;
V_60 -> V_124 . V_127 = 8 ;
}
static T_9 F_62 ( struct V_57 * V_58 ,
struct V_6 * V_7 ,
T_8 V_128 ,
struct V_129 * V_130 ,
int V_83 ,
T_6 * V_131 )
{
struct V_5 * V_92 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_92 -> V_12 ;
struct V_6 * V_132 ;
struct V_64 * V_65 ;
unsigned int V_133 = 0 ;
int V_134 ;
struct V_120 V_60 ;
int V_77 ;
struct V_135 * V_136 = NULL , * V_137 = NULL ;
struct V_138 * V_98 = & V_92 -> V_7 -> V_98 ;
int V_93 = - 1 ;
T_5 V_139 ;
struct V_57 * V_140 ;
T_3 V_100 ;
if ( V_7 -> type == V_24 )
F_63 ( V_58 ) -> V_32 = 0 ;
if ( V_7 -> V_141 && V_7 -> type == V_25 ) {
V_134 = 0 ;
V_65 = (struct V_64 * ) V_58 -> V_66 ;
V_130 -> V_72 = V_65 -> V_72 ;
} else {
V_134 = V_92 -> V_142 ;
V_130 -> V_72 = V_92 -> V_28 . V_30 ;
}
if ( ! V_130 -> V_143 )
V_136 = F_64 ( & V_92 -> V_56 ) ;
if ( ! V_136 ) {
V_136 = F_65 ( V_12 , NULL , V_130 ) ;
if ( V_136 -> error )
goto V_144;
V_136 = F_66 ( V_12 , V_136 , F_67 ( V_130 ) , NULL , 0 ) ;
if ( F_68 ( V_136 ) ) {
V_93 = F_69 ( V_136 ) ;
V_136 = NULL ;
goto V_144;
}
V_137 = V_136 ;
}
V_132 = V_136 -> V_7 ;
if ( V_132 == V_7 ) {
V_98 -> V_145 ++ ;
F_70 ( L_7 ,
V_92 -> V_28 . V_45 ) ;
goto V_146;
}
V_77 = F_71 ( V_136 ) - sizeof( * V_65 ) ;
if ( V_83 >= 0 ) {
V_133 += 8 ;
V_77 -= 8 ;
}
if ( V_77 < V_85 )
V_77 = V_85 ;
if ( F_72 ( V_58 ) )
F_72 ( V_58 ) -> V_124 -> V_147 ( F_72 ( V_58 ) , NULL , V_58 , V_77 ) ;
if ( V_58 -> V_118 > V_77 ) {
* V_131 = V_77 ;
V_93 = - V_148 ;
goto V_146;
}
if ( V_92 -> V_89 > 0 ) {
if ( F_37 ( V_86 ,
V_92 -> V_87 + V_88 ) ) {
V_92 -> V_89 -- ;
F_73 ( V_58 ) ;
} else
V_92 -> V_89 = 0 ;
}
F_74 ( V_58 , ! F_75 ( V_92 -> V_12 , F_5 ( V_7 ) ) ) ;
V_133 += F_76 ( V_132 ) + V_134 + V_136 -> V_149 ;
if ( F_77 ( V_58 ) < V_133 || F_78 ( V_58 ) ||
( F_79 ( V_58 ) && ! F_80 ( V_58 , 0 ) ) ) {
V_140 = F_81 ( V_58 , V_133 ) ;
if ( V_133 > V_7 -> V_150 )
V_7 -> V_150 = V_133 ;
if ( ! V_140 )
goto V_146;
if ( V_58 -> V_151 )
F_82 ( V_140 , V_58 -> V_151 ) ;
F_83 ( V_58 ) ;
V_58 = V_140 ;
}
if ( ! V_130 -> V_143 && V_137 )
F_84 ( & V_92 -> V_56 , V_137 , & V_130 -> V_73 ) ;
F_85 ( V_58 , V_136 ) ;
V_139 = V_152 ;
if ( V_83 >= 0 ) {
F_61 ( & V_60 , V_83 ) ;
F_86 ( V_58 , & V_60 . V_124 , & V_139 , NULL ) ;
}
if ( F_87 ( ! V_58 -> V_153 ) ) {
F_88 ( V_58 ) ;
V_58 -> V_153 = 1 ;
}
F_89 ( V_58 , V_134 ) ;
F_50 ( V_58 ) ;
F_90 ( V_58 , sizeof( * V_65 ) ) ;
V_65 = F_39 ( V_58 ) ;
F_91 ( V_65 , F_92 ( 0 , V_128 ) ,
F_93 ( V_12 , V_58 , V_130 -> V_154 , true , V_130 ) ) ;
V_65 -> V_155 = V_92 -> V_28 . V_155 ;
V_65 -> V_156 = V_139 ;
V_65 -> V_73 = V_130 -> V_73 ;
V_65 -> V_72 = V_130 -> V_72 ;
( ( T_3 * ) ( V_65 + 1 ) ) [ 0 ] = V_92 -> V_28 . V_52 ;
V_100 = ( V_7 -> type == V_24 ) ?
F_8 ( V_23 ) : V_58 -> V_100 ;
( ( T_3 * ) ( V_65 + 1 ) ) [ 1 ] = V_100 ;
if ( V_92 -> V_28 . V_52 & ( V_69 | V_68 | V_53 ) ) {
T_2 * V_157 = ( T_2 * ) ( ( ( T_5 * ) V_65 ) + V_92 -> V_142 - 4 ) ;
if ( V_92 -> V_28 . V_52 & V_53 ) {
++ V_92 -> V_158 ;
* V_157 = F_94 ( V_92 -> V_158 ) ;
V_157 -- ;
}
if ( V_92 -> V_28 . V_52 & V_69 ) {
* V_157 = V_92 -> V_28 . V_159 ;
V_157 -- ;
}
if ( V_92 -> V_28 . V_52 & V_68 ) {
* V_157 = 0 ;
* ( T_7 * ) V_157 = F_95 ( ( void * ) ( V_65 + 1 ) ,
V_58 -> V_118 - sizeof( struct V_64 ) ) ;
}
}
F_96 ( V_58 , V_100 ) ;
F_97 ( NULL , V_58 , V_7 ) ;
return 0 ;
V_144:
V_98 -> V_160 ++ ;
F_73 ( V_58 ) ;
V_146:
F_98 ( V_136 ) ;
return V_93 ;
}
static inline int F_99 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_161 * V_162 = F_100 ( V_58 ) ;
int V_83 = - 1 ;
struct V_129 V_130 ;
T_8 V_128 ;
T_6 V_77 ;
int V_93 ;
memset ( & ( F_63 ( V_58 ) -> V_60 ) , 0 , sizeof( F_63 ( V_58 ) -> V_60 ) ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_163 ) )
V_83 = V_17 -> V_28 . V_83 ;
memcpy ( & V_130 , & V_17 -> V_164 . V_165 . V_166 , sizeof( V_130 ) ) ;
V_130 . V_167 = V_168 ;
V_128 = F_101 ( V_162 ) ;
if ( V_17 -> V_28 . V_32 & V_169 )
V_130 . V_154 |= F_94 ( ( T_6 ) V_162 -> V_170 << V_171 )
& V_172 ;
if ( V_17 -> V_28 . V_32 & V_173 )
V_130 . V_143 = V_58 -> V_174 ;
V_93 = F_62 ( V_58 , V_7 , V_128 , & V_130 , V_83 , & V_77 ) ;
if ( V_93 != 0 ) {
if ( V_93 == - V_148 )
F_102 ( V_58 , V_175 , V_176 ,
F_94 ( V_77 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_103 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_64 * V_65 = F_39 ( V_58 ) ;
int V_83 = - 1 ;
T_10 V_62 ;
struct V_129 V_130 ;
T_8 V_128 ;
T_6 V_77 ;
int V_93 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_65 -> V_73 ) )
return - 1 ;
V_62 = F_35 ( V_58 , F_104 ( V_58 ) ) ;
if ( V_62 > 0 ) {
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) & F_104 ( V_58 ) [ V_62 ] ;
if ( V_76 -> V_83 == 0 ) {
F_59 ( V_58 , V_81 ,
V_82 , V_62 + 2 ) ;
return - 1 ;
}
V_83 = V_76 -> V_83 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_163 ) )
V_83 = V_17 -> V_28 . V_83 ;
memcpy ( & V_130 , & V_17 -> V_164 . V_165 . V_166 , sizeof( V_130 ) ) ;
V_130 . V_167 = V_168 ;
V_128 = F_54 ( V_65 ) ;
if ( V_17 -> V_28 . V_32 & V_169 )
V_130 . V_154 |= ( * ( T_2 * ) V_65 & V_172 ) ;
if ( V_17 -> V_28 . V_32 & V_177 )
V_130 . V_154 |= F_105 ( V_65 ) ;
if ( V_17 -> V_28 . V_32 & V_173 )
V_130 . V_143 = V_58 -> V_174 ;
V_93 = F_62 ( V_58 , V_7 , V_128 , & V_130 , V_83 , & V_77 ) ;
if ( V_93 != 0 ) {
if ( V_93 == - V_148 )
F_59 ( V_58 , V_84 , 0 , V_77 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_106 ( const struct V_5 * V_17 ,
const struct V_64 * V_178 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_178 -> V_73 ) ;
}
static int F_107 ( struct V_57 * V_58 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_83 = - 1 ;
struct V_129 V_130 ;
T_6 V_77 ;
int V_93 ;
if ( ! ( V_17 -> V_28 . V_32 & V_163 ) )
V_83 = V_17 -> V_28 . V_83 ;
memcpy ( & V_130 , & V_17 -> V_164 . V_165 . V_166 , sizeof( V_130 ) ) ;
V_130 . V_167 = V_58 -> V_100 ;
V_93 = F_62 ( V_58 , V_7 , 0 , & V_130 , V_83 , & V_77 ) ;
return V_93 ;
}
static T_9 F_108 ( struct V_57 * V_58 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_138 * V_98 = & V_17 -> V_7 -> V_98 ;
int V_179 ;
if ( ! F_109 ( V_17 , & V_17 -> V_28 . V_29 , & V_17 -> V_28 . V_30 ) )
goto V_180;
switch ( V_58 -> V_100 ) {
case F_8 ( V_181 ) :
V_179 = F_99 ( V_58 , V_7 ) ;
break;
case F_8 ( V_102 ) :
V_179 = F_103 ( V_58 , V_7 ) ;
break;
default:
V_179 = F_107 ( V_58 , V_7 ) ;
break;
}
if ( V_179 < 0 )
goto V_180;
return V_182 ;
V_180:
V_98 -> V_183 ++ ;
V_98 -> V_184 ++ ;
F_60 ( V_58 ) ;
return V_182 ;
}
static void F_25 ( struct V_5 * V_17 , int V_185 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_129 * V_130 = & V_17 -> V_164 . V_165 . V_166 ;
int V_186 = sizeof( struct V_64 ) + 4 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_187 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_188 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_130 -> V_73 = V_36 -> V_29 ;
V_130 -> V_72 = V_36 -> V_30 ;
V_130 -> V_189 = V_36 -> V_13 ;
V_130 -> V_154 = 0 ;
if ( ! ( V_36 -> V_32 & V_169 ) )
V_130 -> V_154 |= V_172 & V_36 -> V_190 ;
if ( ! ( V_36 -> V_32 & V_177 ) )
V_130 -> V_154 |= V_191 & V_36 -> V_190 ;
V_36 -> V_32 &= ~ ( V_192 | V_193 | V_194 ) ;
V_36 -> V_32 |= F_110 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_192 &&
V_36 -> V_32 & V_193 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_195 ;
else
V_7 -> V_32 &= ~ V_195 ;
if ( V_17 -> V_28 . V_52 & ( V_68 | V_69 | V_53 ) ) {
if ( V_17 -> V_28 . V_52 & V_68 )
V_186 += 4 ;
if ( V_17 -> V_28 . V_52 & V_69 )
V_186 += 4 ;
if ( V_17 -> V_28 . V_52 & V_53 )
V_186 += 4 ;
}
V_17 -> V_142 = V_186 ;
if ( V_36 -> V_32 & V_192 ) {
int V_196 = ( F_111 ( & V_36 -> V_30 ) &
( V_197 | V_198 ) ) ;
struct V_199 * V_200 = F_112 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_196 ) ;
if ( ! V_200 )
return;
if ( V_200 -> V_136 . V_7 ) {
V_7 -> V_201 = V_200 -> V_136 . V_7 -> V_201 + V_186 ;
if ( V_185 ) {
V_7 -> V_77 = V_200 -> V_136 . V_7 -> V_77 - V_186 ;
if ( ! ( V_17 -> V_28 . V_32 & V_163 ) )
V_7 -> V_77 -= 8 ;
if ( V_7 -> V_77 < V_85 )
V_7 -> V_77 = V_85 ;
}
}
F_113 ( V_200 ) ;
}
}
static int F_114 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_185 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_155 = V_36 -> V_155 ;
V_17 -> V_28 . V_83 = V_36 -> V_83 ;
V_17 -> V_28 . V_190 = V_36 -> V_190 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_139 = V_36 -> V_139 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_159 = V_36 -> V_159 ;
V_17 -> V_28 . V_105 = V_36 -> V_105 ;
V_17 -> V_28 . V_52 = V_36 -> V_52 ;
F_30 ( & V_17 -> V_56 ) ;
F_25 ( V_17 , V_185 ) ;
return 0 ;
}
static void F_115 ( struct V_35 * V_36 ,
const struct V_202 * V_165 )
{
V_36 -> V_29 = V_165 -> V_29 ;
V_36 -> V_30 = V_165 -> V_30 ;
V_36 -> V_32 = V_165 -> V_32 ;
V_36 -> V_155 = V_165 -> V_155 ;
V_36 -> V_83 = V_165 -> V_83 ;
V_36 -> V_190 = V_165 -> V_190 ;
V_36 -> V_13 = V_165 -> V_13 ;
V_36 -> V_31 = V_165 -> V_31 ;
V_36 -> V_159 = V_165 -> V_159 ;
V_36 -> V_105 = V_165 -> V_105 ;
V_36 -> V_52 = V_165 -> V_52 ;
memcpy ( V_36 -> V_45 , V_165 -> V_45 , sizeof( V_165 -> V_45 ) ) ;
}
static void F_116 ( struct V_202 * V_165 ,
const struct V_35 * V_36 )
{
V_165 -> V_139 = V_168 ;
V_165 -> V_29 = V_36 -> V_29 ;
V_165 -> V_30 = V_36 -> V_30 ;
V_165 -> V_32 = V_36 -> V_32 ;
V_165 -> V_155 = V_36 -> V_155 ;
V_165 -> V_83 = V_36 -> V_83 ;
V_165 -> V_190 = V_36 -> V_190 ;
V_165 -> V_13 = V_36 -> V_13 ;
V_165 -> V_31 = V_36 -> V_31 ;
V_165 -> V_159 = V_36 -> V_159 ;
V_165 -> V_105 = V_36 -> V_105 ;
V_165 -> V_52 = V_36 -> V_52 ;
memcpy ( V_165 -> V_45 , V_36 -> V_45 , sizeof( V_165 -> V_45 ) ) ;
}
static int F_117 ( struct V_6 * V_7 ,
struct V_203 * V_204 , int V_205 )
{
int V_93 = 0 ;
struct V_202 V_36 ;
struct V_35 V_206 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
switch ( V_205 ) {
case V_207 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_118 ( & V_36 , V_204 -> V_208 . V_209 , sizeof( V_36 ) ) ) {
V_93 = - V_210 ;
break;
}
F_115 ( & V_206 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_206 , 0 ) ;
if ( ! V_17 )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_116 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_119 ( V_204 -> V_208 . V_209 , & V_36 , sizeof( V_36 ) ) )
V_93 = - V_210 ;
break;
case V_211 :
case V_212 :
V_93 = - V_213 ;
if ( ! F_120 ( V_12 -> V_214 , V_215 ) )
goto V_216;
V_93 = - V_210 ;
if ( F_118 ( & V_36 , V_204 -> V_208 . V_209 , sizeof( V_36 ) ) )
goto V_216;
V_93 = - V_217 ;
if ( ( V_36 . V_105 | V_36 . V_52 ) & ( V_71 | V_70 ) )
goto V_216;
if ( ! ( V_36 . V_105 & V_69 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_52 & V_69 ) )
V_36 . V_159 = 0 ;
F_115 ( & V_206 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_206 , V_205 == V_211 ) ;
if ( V_7 != V_20 -> V_34 && V_205 == V_212 ) {
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 ) {
V_93 = - V_218 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_121 () ;
F_114 ( V_17 , & V_206 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_122 ( V_7 ) ;
}
}
if ( V_17 ) {
V_93 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_116 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_119 ( V_204 -> V_208 . V_209 , & V_36 , sizeof( V_36 ) ) )
V_93 = - V_210 ;
} else
V_93 = ( V_205 == V_211 ? - V_219 : - V_220 ) ;
break;
case V_221 :
V_93 = - V_213 ;
if ( ! F_120 ( V_12 -> V_214 , V_215 ) )
goto V_216;
if ( V_7 == V_20 -> V_34 ) {
V_93 = - V_210 ;
if ( F_118 ( & V_36 , V_204 -> V_208 . V_209 , sizeof( V_36 ) ) )
goto V_216;
V_93 = - V_220 ;
F_115 ( & V_206 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_206 , 0 ) ;
if ( ! V_17 )
goto V_216;
V_93 = - V_213 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_216;
V_7 = V_17 -> V_7 ;
}
F_123 ( V_7 ) ;
V_93 = 0 ;
break;
default:
V_93 = - V_217 ;
}
V_216:
return V_93 ;
}
static int F_124 ( struct V_6 * V_7 , int V_222 )
{
if ( V_222 < 68 ||
V_222 > 0xFFF8 - V_7 -> V_201 )
return - V_217 ;
V_7 -> V_77 = V_222 ;
return 0 ;
}
static int F_125 ( struct V_57 * V_58 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_72 , const void * V_73 , unsigned int V_118 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_64 * V_65 = (struct V_64 * ) F_89 ( V_58 , V_17 -> V_142 ) ;
T_3 * V_36 = ( T_3 * ) ( V_65 + 1 ) ;
F_91 ( V_65 , 0 ,
F_93 ( F_5 ( V_7 ) , V_58 ,
V_17 -> V_164 . V_165 . V_166 . V_154 , true ,
& V_17 -> V_164 . V_165 . V_166 ) ) ;
V_65 -> V_155 = V_17 -> V_28 . V_155 ;
V_65 -> V_156 = V_152 ;
V_65 -> V_73 = V_17 -> V_28 . V_29 ;
V_65 -> V_72 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_52 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_73 )
memcpy ( & V_65 -> V_73 , V_73 , sizeof( struct V_1 ) ) ;
if ( V_72 )
memcpy ( & V_65 -> V_72 , V_72 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_65 -> V_72 ) )
return V_17 -> V_142 ;
return - V_17 -> V_142 ;
}
static void F_126 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
F_127 ( & V_17 -> V_56 ) ;
F_128 ( V_7 -> V_96 ) ;
F_28 ( V_7 ) ;
}
static void V_48 ( struct V_6 * V_7 )
{
struct V_5 * V_17 ;
V_7 -> V_223 = & V_224 ;
V_7 -> V_225 = F_126 ;
V_7 -> type = V_25 ;
V_7 -> V_201 = V_226 + sizeof( struct V_64 ) + 4 ;
V_7 -> V_77 = V_227 - sizeof( struct V_64 ) - 4 ;
V_17 = F_12 ( V_7 ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_163 ) )
V_7 -> V_77 -= 8 ;
V_7 -> V_32 |= V_228 ;
V_7 -> V_229 = sizeof( struct V_1 ) ;
F_129 ( V_7 ) ;
}
static int F_130 ( struct V_6 * V_7 )
{
struct V_5 * V_92 ;
int V_179 ;
V_92 = F_12 ( V_7 ) ;
V_92 -> V_7 = V_7 ;
V_92 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_92 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_7 -> V_96 = F_131 ( struct V_95 ) ;
if ( ! V_7 -> V_96 )
return - V_230 ;
V_179 = F_132 ( & V_92 -> V_56 , V_231 ) ;
if ( V_179 ) {
F_128 ( V_7 -> V_96 ) ;
V_7 -> V_96 = NULL ;
return V_179 ;
}
return 0 ;
}
static int F_133 ( struct V_6 * V_7 )
{
struct V_5 * V_92 ;
int V_179 ;
V_179 = F_130 ( V_7 ) ;
if ( V_179 )
return V_179 ;
V_92 = F_12 ( V_7 ) ;
memcpy ( V_7 -> V_187 , & V_92 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_188 , & V_92 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_92 -> V_28 . V_30 ) )
V_7 -> V_141 = & V_232 ;
return 0 ;
}
static void F_134 ( struct V_6 * V_7 )
{
struct V_5 * V_92 = F_12 ( V_7 ) ;
V_92 -> V_7 = V_7 ;
V_92 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_92 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_92 -> V_142 = sizeof( struct V_64 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_135 ( struct V_12 * V_12 , struct V_233 * V_234 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_235 ;
int V_38 ;
F_136 (net, dev, aux)
if ( V_7 -> V_49 == & V_50 ||
V_7 -> V_49 == & V_236 )
F_137 ( V_7 , V_234 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_237 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 ) {
if ( ! F_75 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_137 ( V_17 -> V_7 ,
V_234 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_11 F_138 ( struct V_12 * V_12 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_93 ;
V_20 -> V_34 = F_23 ( sizeof( struct V_5 ) , L_8 ,
V_47 ,
V_48 ) ;
if ( ! V_20 -> V_34 ) {
V_93 = - V_230 ;
goto V_238;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
V_20 -> V_34 -> V_54 |= V_239 ;
F_134 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_49 = & V_50 ;
V_93 = F_139 ( V_20 -> V_34 ) ;
if ( V_93 )
goto V_240;
F_17 ( V_20 -> V_241 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_240:
F_126 ( V_20 -> V_34 ) ;
V_238:
return V_93 ;
}
static void T_12 F_140 ( struct V_12 * V_12 )
{
F_141 ( V_242 ) ;
F_142 () ;
F_135 ( V_12 , & V_242 ) ;
F_143 ( & V_242 ) ;
F_144 () ;
}
static int F_145 ( struct V_243 * V_244 [] , struct V_243 * V_66 [] )
{
T_3 V_32 ;
if ( ! V_66 )
return 0 ;
V_32 = 0 ;
if ( V_66 [ V_245 ] )
V_32 |= F_146 ( V_66 [ V_245 ] ) ;
if ( V_66 [ V_246 ] )
V_32 |= F_146 ( V_66 [ V_246 ] ) ;
if ( V_32 & ( V_71 | V_70 ) )
return - V_217 ;
return 0 ;
}
static int F_147 ( struct V_243 * V_244 [] , struct V_243 * V_66 [] )
{
struct V_1 V_72 ;
if ( V_244 [ V_247 ] ) {
if ( F_148 ( V_244 [ V_247 ] ) != V_248 )
return - V_217 ;
if ( ! F_149 ( F_150 ( V_244 [ V_247 ] ) ) )
return - V_249 ;
}
if ( ! V_66 )
goto V_250;
if ( V_66 [ V_251 ] ) {
V_72 = F_151 ( V_66 [ V_251 ] ) ;
if ( F_14 ( & V_72 ) )
return - V_217 ;
}
V_250:
return F_145 ( V_244 , V_66 ) ;
}
static void F_152 ( struct V_243 * V_66 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_66 )
return;
if ( V_66 [ V_252 ] )
V_28 -> V_13 = F_153 ( V_66 [ V_252 ] ) ;
if ( V_66 [ V_245 ] )
V_28 -> V_105 = F_146 ( V_66 [ V_245 ] ) ;
if ( V_66 [ V_246 ] )
V_28 -> V_52 = F_146 ( V_66 [ V_246 ] ) ;
if ( V_66 [ V_253 ] )
V_28 -> V_31 = F_154 ( V_66 [ V_253 ] ) ;
if ( V_66 [ V_254 ] )
V_28 -> V_159 = F_154 ( V_66 [ V_254 ] ) ;
if ( V_66 [ V_255 ] )
V_28 -> V_29 = F_151 ( V_66 [ V_255 ] ) ;
if ( V_66 [ V_251 ] )
V_28 -> V_30 = F_151 ( V_66 [ V_251 ] ) ;
if ( V_66 [ V_256 ] )
V_28 -> V_155 = F_155 ( V_66 [ V_256 ] ) ;
if ( V_66 [ V_257 ] )
V_28 -> V_83 = F_155 ( V_66 [ V_257 ] ) ;
if ( V_66 [ V_258 ] )
V_28 -> V_190 = F_153 ( V_66 [ V_258 ] ) ;
if ( V_66 [ V_259 ] )
V_28 -> V_32 = F_153 ( V_66 [ V_259 ] ) ;
}
static int F_156 ( struct V_6 * V_7 )
{
struct V_5 * V_92 ;
int V_179 ;
V_179 = F_130 ( V_7 ) ;
if ( V_179 )
return V_179 ;
V_92 = F_12 ( V_7 ) ;
F_25 ( V_92 , 1 ) ;
return 0 ;
}
static void F_157 ( struct V_6 * V_7 )
{
F_158 ( V_7 ) ;
V_7 -> V_223 = & V_260 ;
V_7 -> V_225 = F_126 ;
V_7 -> V_54 |= V_239 ;
V_7 -> V_261 &= ~ V_262 ;
}
static int F_159 ( struct V_12 * V_263 , struct V_6 * V_7 ,
struct V_243 * V_244 [] , struct V_243 * V_66 [] )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_93 ;
V_44 = F_12 ( V_7 ) ;
F_152 ( V_66 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_218 ;
if ( V_7 -> type == V_24 && ! V_244 [ V_247 ] )
F_160 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_244 [ V_264 ] ) ;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) )
V_7 -> V_54 |= V_55 ;
V_93 = F_26 ( V_7 ) ;
if ( V_93 )
goto V_250;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_250:
return V_93 ;
}
static int F_161 ( struct V_6 * V_7 , struct V_243 * V_244 [] ,
struct V_243 * V_66 [] )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
if ( V_7 == V_20 -> V_34 )
return - V_217 ;
F_152 ( V_66 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_218 ;
} else {
V_17 = V_44 ;
}
F_19 ( V_20 , V_17 ) ;
F_114 ( V_17 , & V_36 , ! V_244 [ V_264 ] ) ;
F_16 ( V_20 , V_17 ) ;
return 0 ;
}
static void F_162 ( struct V_6 * V_7 , struct V_233 * V_234 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_137 ( V_7 , V_234 ) ;
}
static T_13 F_163 ( const struct V_6 * V_7 )
{
return
F_164 ( 4 ) +
F_164 ( 2 ) +
F_164 ( 2 ) +
F_164 ( 4 ) +
F_164 ( 4 ) +
F_164 ( sizeof( struct V_1 ) ) +
F_164 ( sizeof( struct V_1 ) ) +
F_164 ( 1 ) +
F_164 ( 1 ) +
F_164 ( 1 ) +
F_164 ( 4 ) +
F_164 ( 4 ) +
0 ;
}
static int F_165 ( struct V_57 * V_58 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_166 ( V_58 , V_252 , V_36 -> V_13 ) ||
F_167 ( V_58 , V_245 , V_36 -> V_105 ) ||
F_167 ( V_58 , V_246 , V_36 -> V_52 ) ||
F_168 ( V_58 , V_253 , V_36 -> V_31 ) ||
F_168 ( V_58 , V_254 , V_36 -> V_159 ) ||
F_169 ( V_58 , V_255 , & V_36 -> V_29 ) ||
F_169 ( V_58 , V_251 , & V_36 -> V_30 ) ||
F_170 ( V_58 , V_256 , V_36 -> V_155 ) ||
F_170 ( V_58 , V_257 , V_36 -> V_83 ) ||
F_168 ( V_58 , V_258 , V_36 -> V_190 ) ||
F_166 ( V_58 , V_259 , V_36 -> V_32 ) )
goto V_265;
return 0 ;
V_265:
return - V_148 ;
}
static int T_14 F_171 ( void )
{
int V_93 ;
F_172 ( L_9 ) ;
V_93 = F_173 ( & V_266 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = F_174 ( & V_267 , V_168 ) ;
if ( V_93 < 0 ) {
F_172 ( L_10 , V_268 ) ;
goto V_269;
}
V_93 = F_175 ( & V_50 ) ;
if ( V_93 < 0 )
goto V_270;
V_93 = F_175 ( & V_236 ) ;
if ( V_93 < 0 )
goto V_271;
V_250:
return V_93 ;
V_271:
F_176 ( & V_50 ) ;
V_270:
F_177 ( & V_267 , V_168 ) ;
V_269:
F_178 ( & V_266 ) ;
goto V_250;
}
static void T_15 F_179 ( void )
{
F_176 ( & V_236 ) ;
F_176 ( & V_50 ) ;
F_177 ( & V_267 , V_168 ) ;
F_178 ( & V_266 ) ;
}
