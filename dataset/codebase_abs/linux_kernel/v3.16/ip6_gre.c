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
if ( V_18 != NULL )
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
if ( V_17 || ! V_43 )
return V_17 ;
if ( V_28 -> V_45 [ 0 ] )
F_22 ( V_45 , V_28 -> V_45 , V_46 ) ;
else
strcpy ( V_45 , L_1 ) ;
V_7 = F_23 ( sizeof( * V_17 ) , V_45 , V_47 ) ;
if ( ! V_7 )
return NULL ;
F_24 ( V_7 , V_12 ) ;
V_44 = F_12 ( V_7 ) ;
V_44 -> V_28 = * V_28 ;
V_7 -> V_48 = & V_49 ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , 1 ) ;
if ( F_26 ( V_7 ) < 0 )
goto V_50;
if ( ! ( V_44 -> V_28 . V_51 & V_52 ) )
V_7 -> V_53 |= V_54 ;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
return V_44 ;
V_50:
F_28 ( V_7 ) ;
return NULL ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_17 -> V_12 , V_21 ) ;
F_19 ( V_20 , V_17 ) ;
F_30 ( V_7 ) ;
}
static void F_31 ( struct V_55 * V_56 , struct V_57 * V_58 ,
T_5 type , T_5 V_59 , int V_60 , T_2 V_61 )
{
const struct V_62 * V_63 = ( const struct V_62 * ) V_56 -> V_64 ;
T_3 * V_36 = ( T_3 * ) ( V_56 -> V_64 + V_60 ) ;
int V_65 = V_60 + 4 ;
struct V_5 * V_17 ;
T_3 V_32 ;
V_32 = V_36 [ 0 ] ;
if ( V_32 & ( V_66 | V_67 | V_52 | V_68 | V_69 ) ) {
if ( V_32 & ( V_69 | V_68 ) )
return;
if ( V_32 & V_67 ) {
V_65 += 4 ;
if ( V_32 & V_66 )
V_65 += 4 ;
}
}
if ( ! F_32 ( V_56 , V_65 ) )
return;
V_63 = ( const struct V_62 * ) V_56 -> V_64 ;
V_36 = ( T_3 * ) ( V_56 -> V_64 + V_60 ) ;
V_17 = F_4 ( V_56 -> V_7 , & V_63 -> V_70 , & V_63 -> V_71 ,
V_32 & V_67 ?
* ( ( ( T_2 * ) V_36 ) + ( V_65 / 4 ) - 1 ) : 0 ,
V_36 [ 1 ] ) ;
if ( V_17 == NULL )
return;
switch ( type ) {
T_6 V_72 ;
struct V_73 * V_74 ;
T_6 V_75 ;
case V_76 :
F_33 ( L_2 ,
V_17 -> V_28 . V_45 ) ;
break;
case V_77 :
if ( V_59 == V_78 ) {
F_33 ( L_3 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_79 :
V_72 = 0 ;
if ( V_59 == V_80 )
V_72 = F_34 ( V_56 , V_56 -> V_64 ) ;
if ( V_72 && V_72 == V_61 - 2 ) {
V_74 = (struct V_73 * ) & V_56 -> V_64 [ V_72 ] ;
if ( V_74 -> V_81 == 0 ) {
F_33 ( L_4 ,
V_17 -> V_28 . V_45 ) ;
}
} else {
F_33 ( L_5 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_82 :
V_75 = V_61 - V_60 ;
if ( V_75 < V_83 )
V_75 = V_83 ;
V_17 -> V_7 -> V_75 = V_75 ;
break;
}
if ( F_35 ( V_84 , V_17 -> V_85 + V_86 ) )
V_17 -> V_87 ++ ;
else
V_17 -> V_87 = 1 ;
V_17 -> V_85 = V_84 ;
}
static int F_36 ( struct V_55 * V_56 )
{
const struct V_62 * V_63 ;
T_5 * V_37 ;
T_3 V_32 ;
T_7 V_88 = 0 ;
T_2 V_10 = 0 ;
T_1 V_89 = 0 ;
struct V_5 * V_90 ;
int V_60 = 4 ;
T_3 V_11 ;
int V_91 ;
if ( ! F_32 ( V_56 , sizeof( struct V_1 ) ) )
goto V_92;
V_63 = F_37 ( V_56 ) ;
V_37 = V_56 -> V_64 ;
V_32 = * ( T_3 * ) V_37 ;
if ( V_32 & ( V_66 | V_67 | V_68 | V_52 | V_69 ) ) {
if ( V_32 & ( V_69 | V_68 ) )
goto V_92;
if ( V_32 & V_66 ) {
V_88 = F_38 ( V_56 ) ;
V_60 += 4 ;
}
if ( V_32 & V_67 ) {
V_10 = * ( T_2 * ) ( V_37 + V_60 ) ;
V_60 += 4 ;
}
if ( V_32 & V_52 ) {
V_89 = F_39 ( * ( T_2 * ) ( V_37 + V_60 ) ) ;
V_60 += 4 ;
}
}
V_11 = * ( T_3 * ) ( V_37 + 2 ) ;
V_90 = F_4 ( V_56 -> V_7 ,
& V_63 -> V_71 , & V_63 -> V_70 , V_10 ,
V_11 ) ;
if ( V_90 ) {
struct V_93 * V_94 ;
if ( ! F_40 ( NULL , V_95 , V_56 ) )
goto V_92;
if ( ! F_41 ( V_90 , & V_63 -> V_70 , & V_63 -> V_71 ) ) {
V_90 -> V_7 -> V_96 . V_97 ++ ;
goto V_92;
}
V_56 -> V_98 = V_11 ;
if ( V_32 == 0 && V_11 == F_8 ( V_99 ) ) {
V_56 -> V_98 = F_8 ( V_100 ) ;
if ( ( * ( V_37 + V_60 ) & 0xF0 ) != 0x40 )
V_60 += 4 ;
}
V_56 -> V_101 = V_56 -> V_102 ;
F_42 ( V_56 , V_60 ) ;
F_43 ( V_56 , F_44 ( V_56 ) , V_60 ) ;
if ( ( ( V_32 & V_66 ) && V_88 ) ||
( ! ( V_32 & V_66 ) && V_90 -> V_28 . V_103 & V_66 ) ) {
V_90 -> V_7 -> V_96 . V_104 ++ ;
V_90 -> V_7 -> V_96 . V_105 ++ ;
goto V_92;
}
if ( V_90 -> V_28 . V_103 & V_52 ) {
if ( ! ( V_32 & V_52 ) ||
( V_90 -> V_106 &&
( V_107 ) ( V_89 - V_90 -> V_106 ) < 0 ) ) {
V_90 -> V_7 -> V_96 . V_108 ++ ;
V_90 -> V_7 -> V_96 . V_105 ++ ;
goto V_92;
}
V_90 -> V_106 = V_89 + 1 ;
}
if ( V_90 -> V_7 -> type == V_24 ) {
if ( ! F_32 ( V_56 , V_109 ) ) {
V_90 -> V_7 -> V_96 . V_110 ++ ;
V_90 -> V_7 -> V_96 . V_105 ++ ;
goto V_92;
}
V_63 = F_37 ( V_56 ) ;
V_56 -> V_98 = F_45 ( V_56 , V_90 -> V_7 ) ;
F_43 ( V_56 , F_46 ( V_56 ) , V_109 ) ;
}
F_47 ( V_56 , V_90 -> V_7 , V_90 -> V_12 ) ;
F_48 ( V_56 ) ;
V_91 = F_49 ( V_63 , V_56 ) ;
if ( F_50 ( V_91 ) ) {
if ( V_111 )
F_51 ( L_6 ,
& V_63 -> V_71 ,
F_52 ( V_63 ) ) ;
if ( V_91 > 1 ) {
++ V_90 -> V_7 -> V_96 . V_112 ;
++ V_90 -> V_7 -> V_96 . V_105 ;
goto V_92;
}
}
V_94 = F_53 ( V_90 -> V_7 -> V_94 ) ;
F_54 ( & V_94 -> V_113 ) ;
V_94 -> V_114 ++ ;
V_94 -> V_115 += V_56 -> V_116 ;
F_55 ( & V_94 -> V_113 ) ;
F_56 ( V_56 ) ;
return 0 ;
}
F_57 ( V_56 , V_76 , V_117 , 0 ) ;
V_92:
F_58 ( V_56 ) ;
return 0 ;
}
static void F_59 ( struct V_118 * V_58 , T_8 V_81 )
{
memset ( V_58 , 0 , sizeof( struct V_118 ) ) ;
V_58 -> V_119 [ 2 ] = V_120 ;
V_58 -> V_119 [ 3 ] = 1 ;
V_58 -> V_119 [ 4 ] = V_81 ;
V_58 -> V_119 [ 5 ] = V_121 ;
V_58 -> V_119 [ 6 ] = 1 ;
V_58 -> V_122 . V_123 = (struct V_124 * ) V_58 -> V_119 ;
V_58 -> V_122 . V_125 = 8 ;
}
static T_9 F_60 ( struct V_55 * V_56 ,
struct V_6 * V_7 ,
T_8 V_126 ,
struct V_127 * V_128 ,
int V_81 ,
T_6 * V_129 )
{
struct V_5 * V_90 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_90 -> V_12 ;
struct V_6 * V_130 ;
struct V_62 * V_63 ;
unsigned int V_131 = 0 ;
int V_132 ;
struct V_118 V_58 ;
int V_75 ;
struct V_133 * V_134 = NULL , * V_135 = NULL ;
struct V_136 * V_96 = & V_90 -> V_7 -> V_96 ;
int V_91 = - 1 ;
T_5 V_137 ;
struct V_55 * V_138 ;
if ( V_7 -> type == V_24 )
F_61 ( V_56 ) -> V_32 = 0 ;
if ( V_7 -> V_139 && V_7 -> type == V_25 ) {
V_132 = 0 ;
V_63 = (struct V_62 * ) V_56 -> V_64 ;
V_128 -> V_70 = V_63 -> V_70 ;
} else {
V_132 = V_90 -> V_140 ;
V_128 -> V_70 = V_90 -> V_28 . V_30 ;
}
if ( ! V_128 -> V_141 )
V_134 = F_62 ( V_90 ) ;
if ( ! V_134 ) {
V_135 = F_63 ( V_12 , NULL , V_128 ) ;
if ( V_135 -> error )
goto V_142;
V_135 = F_64 ( V_12 , V_135 , F_65 ( V_128 ) , NULL , 0 ) ;
if ( F_66 ( V_135 ) ) {
V_91 = F_67 ( V_135 ) ;
V_135 = NULL ;
goto V_142;
}
V_134 = V_135 ;
}
V_130 = V_134 -> V_7 ;
if ( V_130 == V_7 ) {
V_96 -> V_143 ++ ;
F_33 ( L_7 ,
V_90 -> V_28 . V_45 ) ;
goto V_144;
}
V_75 = F_68 ( V_134 ) - sizeof( * V_63 ) ;
if ( V_81 >= 0 ) {
V_131 += 8 ;
V_75 -= 8 ;
}
if ( V_75 < V_83 )
V_75 = V_83 ;
if ( F_69 ( V_56 ) )
F_69 ( V_56 ) -> V_122 -> V_145 ( F_69 ( V_56 ) , NULL , V_56 , V_75 ) ;
if ( V_56 -> V_116 > V_75 ) {
* V_129 = V_75 ;
V_91 = - V_146 ;
goto V_144;
}
if ( V_90 -> V_87 > 0 ) {
if ( F_35 ( V_84 ,
V_90 -> V_85 + V_86 ) ) {
V_90 -> V_87 -- ;
F_70 ( V_56 ) ;
} else
V_90 -> V_87 = 0 ;
}
F_71 ( V_56 , ! F_72 ( V_90 -> V_12 , F_5 ( V_7 ) ) ) ;
V_131 += F_73 ( V_130 ) + V_132 + V_134 -> V_147 ;
if ( F_74 ( V_56 ) < V_131 || F_75 ( V_56 ) ||
( F_76 ( V_56 ) && ! F_77 ( V_56 , 0 ) ) ) {
V_138 = F_78 ( V_56 , V_131 ) ;
if ( V_131 > V_7 -> V_148 )
V_7 -> V_148 = V_131 ;
if ( ! V_138 )
goto V_144;
if ( V_56 -> V_149 )
F_79 ( V_138 , V_56 -> V_149 ) ;
F_80 ( V_56 ) ;
V_56 = V_138 ;
}
if ( V_128 -> V_141 ) {
F_81 ( V_56 , V_134 ) ;
V_135 = NULL ;
} else {
F_82 ( V_56 , V_134 ) ;
}
V_137 = V_150 ;
if ( V_81 >= 0 ) {
F_59 ( & V_58 , V_81 ) ;
F_83 ( V_56 , & V_58 . V_122 , & V_137 , NULL ) ;
}
if ( F_84 ( ! V_56 -> V_151 ) ) {
F_85 ( V_56 ) ;
V_56 -> V_151 = 1 ;
}
F_86 ( V_56 , V_132 ) ;
F_48 ( V_56 ) ;
F_87 ( V_56 , sizeof( * V_63 ) ) ;
V_63 = F_37 ( V_56 ) ;
F_88 ( V_63 , F_89 ( 0 , V_126 ) , V_128 -> V_152 ) ;
V_63 -> V_153 = V_90 -> V_28 . V_153 ;
V_63 -> V_154 = V_137 ;
V_63 -> V_71 = V_128 -> V_71 ;
V_63 -> V_70 = V_128 -> V_70 ;
( ( T_3 * ) ( V_63 + 1 ) ) [ 0 ] = V_90 -> V_28 . V_51 ;
( ( T_3 * ) ( V_63 + 1 ) ) [ 1 ] = ( V_7 -> type == V_24 ) ?
F_8 ( V_23 ) : V_56 -> V_98 ;
if ( V_90 -> V_28 . V_51 & ( V_67 | V_66 | V_52 ) ) {
T_2 * V_155 = ( T_2 * ) ( ( ( T_5 * ) V_63 ) + V_90 -> V_140 - 4 ) ;
if ( V_90 -> V_28 . V_51 & V_52 ) {
++ V_90 -> V_156 ;
* V_155 = F_90 ( V_90 -> V_156 ) ;
V_155 -- ;
}
if ( V_90 -> V_28 . V_51 & V_67 ) {
* V_155 = V_90 -> V_28 . V_157 ;
V_155 -- ;
}
if ( V_90 -> V_28 . V_51 & V_66 ) {
* V_155 = 0 ;
* ( T_7 * ) V_155 = F_91 ( ( void * ) ( V_63 + 1 ) ,
V_56 -> V_116 - sizeof( struct V_62 ) ) ;
}
}
F_92 ( V_56 , V_7 ) ;
if ( V_135 )
F_93 ( V_90 , V_135 ) ;
return 0 ;
V_142:
V_96 -> V_158 ++ ;
F_70 ( V_56 ) ;
V_144:
F_94 ( V_135 ) ;
return V_91 ;
}
static inline int F_95 ( struct V_55 * V_56 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_159 * V_160 = F_96 ( V_56 ) ;
int V_81 = - 1 ;
struct V_127 V_128 ;
T_8 V_126 ;
T_6 V_75 ;
int V_91 ;
if ( ! ( V_17 -> V_28 . V_32 & V_161 ) )
V_81 = V_17 -> V_28 . V_81 ;
memcpy ( & V_128 , & V_17 -> V_162 . V_163 . V_164 , sizeof( V_128 ) ) ;
V_128 . V_165 = V_166 ;
V_126 = F_97 ( V_160 ) ;
if ( V_17 -> V_28 . V_32 & V_167 )
V_128 . V_152 |= F_90 ( ( T_6 ) V_160 -> V_168 << V_169 )
& V_170 ;
if ( V_17 -> V_28 . V_32 & V_171 )
V_128 . V_141 = V_56 -> V_172 ;
V_91 = F_60 ( V_56 , V_7 , V_126 , & V_128 , V_81 , & V_75 ) ;
if ( V_91 != 0 ) {
if ( V_91 == - V_146 )
F_98 ( V_56 , V_173 , V_174 ,
F_90 ( V_75 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_99 ( struct V_55 * V_56 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_62 * V_63 = F_37 ( V_56 ) ;
int V_81 = - 1 ;
T_10 V_60 ;
struct V_127 V_128 ;
T_8 V_126 ;
T_6 V_75 ;
int V_91 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_63 -> V_71 ) )
return - 1 ;
V_60 = F_34 ( V_56 , F_100 ( V_56 ) ) ;
if ( V_60 > 0 ) {
struct V_73 * V_74 ;
V_74 = (struct V_73 * ) & F_100 ( V_56 ) [ V_60 ] ;
if ( V_74 -> V_81 == 0 ) {
F_57 ( V_56 , V_79 ,
V_80 , V_60 + 2 ) ;
return - 1 ;
}
V_81 = V_74 -> V_81 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_161 ) )
V_81 = V_17 -> V_28 . V_81 ;
memcpy ( & V_128 , & V_17 -> V_162 . V_163 . V_164 , sizeof( V_128 ) ) ;
V_128 . V_165 = V_175 ;
V_126 = F_52 ( V_63 ) ;
if ( V_17 -> V_28 . V_32 & V_167 )
V_128 . V_152 |= ( * ( T_2 * ) V_63 & V_170 ) ;
if ( V_17 -> V_28 . V_32 & V_176 )
V_128 . V_152 |= F_101 ( V_63 ) ;
if ( V_17 -> V_28 . V_32 & V_171 )
V_128 . V_141 = V_56 -> V_172 ;
V_91 = F_60 ( V_56 , V_7 , V_126 , & V_128 , V_81 , & V_75 ) ;
if ( V_91 != 0 ) {
if ( V_91 == - V_146 )
F_57 ( V_56 , V_82 , 0 , V_75 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_102 ( const struct V_5 * V_17 ,
const struct V_62 * V_177 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_177 -> V_71 ) ;
}
static int F_103 ( struct V_55 * V_56 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_81 = - 1 ;
struct V_127 V_128 ;
T_6 V_75 ;
int V_91 ;
if ( ! ( V_17 -> V_28 . V_32 & V_161 ) )
V_81 = V_17 -> V_28 . V_81 ;
memcpy ( & V_128 , & V_17 -> V_162 . V_163 . V_164 , sizeof( V_128 ) ) ;
V_128 . V_165 = V_56 -> V_98 ;
V_91 = F_60 ( V_56 , V_7 , 0 , & V_128 , V_81 , & V_75 ) ;
return V_91 ;
}
static T_9 F_104 ( struct V_55 * V_56 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_136 * V_96 = & V_17 -> V_7 -> V_96 ;
int V_178 ;
if ( ! F_105 ( V_17 ) )
goto V_179;
switch ( V_56 -> V_98 ) {
case F_8 ( V_100 ) :
V_178 = F_95 ( V_56 , V_7 ) ;
break;
case F_8 ( V_180 ) :
V_178 = F_99 ( V_56 , V_7 ) ;
break;
default:
V_178 = F_103 ( V_56 , V_7 ) ;
break;
}
if ( V_178 < 0 )
goto V_179;
return V_181 ;
V_179:
V_96 -> V_182 ++ ;
V_96 -> V_183 ++ ;
F_58 ( V_56 ) ;
return V_181 ;
}
static void F_25 ( struct V_5 * V_17 , int V_184 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_127 * V_128 = & V_17 -> V_162 . V_163 . V_164 ;
int V_185 = sizeof( struct V_62 ) + 4 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_186 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_187 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_128 -> V_71 = V_36 -> V_29 ;
V_128 -> V_70 = V_36 -> V_30 ;
V_128 -> V_188 = V_36 -> V_13 ;
V_128 -> V_152 = 0 ;
if ( ! ( V_36 -> V_32 & V_167 ) )
V_128 -> V_152 |= V_170 & V_36 -> V_189 ;
if ( ! ( V_36 -> V_32 & V_176 ) )
V_128 -> V_152 |= V_190 & V_36 -> V_189 ;
V_36 -> V_32 &= ~ ( V_191 | V_192 | V_193 ) ;
V_36 -> V_32 |= F_106 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_191 &&
V_36 -> V_32 & V_192 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_194 ;
else
V_7 -> V_32 &= ~ V_194 ;
V_7 -> V_195 = V_36 -> V_13 ;
if ( V_17 -> V_28 . V_51 & ( V_66 | V_67 | V_52 ) ) {
if ( V_17 -> V_28 . V_51 & V_66 )
V_185 += 4 ;
if ( V_17 -> V_28 . V_51 & V_67 )
V_185 += 4 ;
if ( V_17 -> V_28 . V_51 & V_52 )
V_185 += 4 ;
}
V_17 -> V_140 = V_185 ;
if ( V_36 -> V_32 & V_191 ) {
int V_196 = ( F_107 ( & V_36 -> V_30 ) &
( V_197 | V_198 ) ) ;
struct V_199 * V_200 = F_108 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_196 ) ;
if ( V_200 == NULL )
return;
if ( V_200 -> V_134 . V_7 ) {
V_7 -> V_201 = V_200 -> V_134 . V_7 -> V_201 + V_185 ;
if ( V_184 ) {
V_7 -> V_75 = V_200 -> V_134 . V_7 -> V_75 - V_185 ;
if ( ! ( V_17 -> V_28 . V_32 & V_161 ) )
V_7 -> V_75 -= 8 ;
if ( V_7 -> V_75 < V_83 )
V_7 -> V_75 = V_83 ;
}
}
F_109 ( V_200 ) ;
}
}
static int F_110 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_184 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_153 = V_36 -> V_153 ;
V_17 -> V_28 . V_81 = V_36 -> V_81 ;
V_17 -> V_28 . V_189 = V_36 -> V_189 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_137 = V_36 -> V_137 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_157 = V_36 -> V_157 ;
V_17 -> V_28 . V_103 = V_36 -> V_103 ;
V_17 -> V_28 . V_51 = V_36 -> V_51 ;
F_111 ( V_17 ) ;
F_25 ( V_17 , V_184 ) ;
return 0 ;
}
static void F_112 ( struct V_35 * V_36 ,
const struct V_202 * V_163 )
{
V_36 -> V_29 = V_163 -> V_29 ;
V_36 -> V_30 = V_163 -> V_30 ;
V_36 -> V_32 = V_163 -> V_32 ;
V_36 -> V_153 = V_163 -> V_153 ;
V_36 -> V_81 = V_163 -> V_81 ;
V_36 -> V_189 = V_163 -> V_189 ;
V_36 -> V_13 = V_163 -> V_13 ;
V_36 -> V_31 = V_163 -> V_31 ;
V_36 -> V_157 = V_163 -> V_157 ;
V_36 -> V_103 = V_163 -> V_103 ;
V_36 -> V_51 = V_163 -> V_51 ;
memcpy ( V_36 -> V_45 , V_163 -> V_45 , sizeof( V_163 -> V_45 ) ) ;
}
static void F_113 ( struct V_202 * V_163 ,
const struct V_35 * V_36 )
{
V_163 -> V_137 = V_203 ;
V_163 -> V_29 = V_36 -> V_29 ;
V_163 -> V_30 = V_36 -> V_30 ;
V_163 -> V_32 = V_36 -> V_32 ;
V_163 -> V_153 = V_36 -> V_153 ;
V_163 -> V_81 = V_36 -> V_81 ;
V_163 -> V_189 = V_36 -> V_189 ;
V_163 -> V_13 = V_36 -> V_13 ;
V_163 -> V_31 = V_36 -> V_31 ;
V_163 -> V_157 = V_36 -> V_157 ;
V_163 -> V_103 = V_36 -> V_103 ;
V_163 -> V_51 = V_36 -> V_51 ;
memcpy ( V_163 -> V_45 , V_36 -> V_45 , sizeof( V_163 -> V_45 ) ) ;
}
static int F_114 ( struct V_6 * V_7 ,
struct V_204 * V_205 , int V_206 )
{
int V_91 = 0 ;
struct V_202 V_36 ;
struct V_35 V_207 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
switch ( V_206 ) {
case V_208 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_115 ( & V_36 , V_205 -> V_209 . V_210 , sizeof( V_36 ) ) ) {
V_91 = - V_211 ;
break;
}
F_112 ( & V_207 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_207 , 0 ) ;
if ( V_17 == NULL )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_113 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_116 ( V_205 -> V_209 . V_210 , & V_36 , sizeof( V_36 ) ) )
V_91 = - V_211 ;
break;
case V_212 :
case V_213 :
V_91 = - V_214 ;
if ( ! F_117 ( V_12 -> V_215 , V_216 ) )
goto V_217;
V_91 = - V_211 ;
if ( F_115 ( & V_36 , V_205 -> V_209 . V_210 , sizeof( V_36 ) ) )
goto V_217;
V_91 = - V_218 ;
if ( ( V_36 . V_103 | V_36 . V_51 ) & ( V_69 | V_68 ) )
goto V_217;
if ( ! ( V_36 . V_103 & V_67 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_51 & V_67 ) )
V_36 . V_157 = 0 ;
F_112 ( & V_207 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_207 , V_206 == V_212 ) ;
if ( V_7 != V_20 -> V_34 && V_206 == V_213 ) {
if ( V_17 != NULL ) {
if ( V_17 -> V_7 != V_7 ) {
V_91 = - V_219 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_118 () ;
F_110 ( V_17 , & V_207 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_119 ( V_7 ) ;
}
}
if ( V_17 ) {
V_91 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_113 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_116 ( V_205 -> V_209 . V_210 , & V_36 , sizeof( V_36 ) ) )
V_91 = - V_211 ;
} else
V_91 = ( V_206 == V_212 ? - V_220 : - V_221 ) ;
break;
case V_222 :
V_91 = - V_214 ;
if ( ! F_117 ( V_12 -> V_215 , V_216 ) )
goto V_217;
if ( V_7 == V_20 -> V_34 ) {
V_91 = - V_211 ;
if ( F_115 ( & V_36 , V_205 -> V_209 . V_210 , sizeof( V_36 ) ) )
goto V_217;
V_91 = - V_221 ;
F_112 ( & V_207 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_207 , 0 ) ;
if ( V_17 == NULL )
goto V_217;
V_91 = - V_214 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_217;
V_7 = V_17 -> V_7 ;
}
F_120 ( V_7 ) ;
V_91 = 0 ;
break;
default:
V_91 = - V_218 ;
}
V_217:
return V_91 ;
}
static int F_121 ( struct V_6 * V_7 , int V_223 )
{
if ( V_223 < 68 ||
V_223 > 0xFFF8 - V_7 -> V_201 )
return - V_218 ;
V_7 -> V_75 = V_223 ;
return 0 ;
}
static int F_122 ( struct V_55 * V_56 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_70 , const void * V_71 , unsigned int V_116 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_62 * V_63 = (struct V_62 * ) F_86 ( V_56 , V_17 -> V_140 ) ;
T_3 * V_36 = ( T_3 * ) ( V_63 + 1 ) ;
F_88 ( V_63 , 0 , V_17 -> V_162 . V_163 . V_164 . V_152 ) ;
V_63 -> V_153 = V_17 -> V_28 . V_153 ;
V_63 -> V_154 = V_150 ;
V_63 -> V_71 = V_17 -> V_28 . V_29 ;
V_63 -> V_70 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_51 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_71 )
memcpy ( & V_63 -> V_71 , V_71 , sizeof( struct V_1 ) ) ;
if ( V_70 )
memcpy ( & V_63 -> V_70 , V_70 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_63 -> V_70 ) )
return V_17 -> V_140 ;
return - V_17 -> V_140 ;
}
static void F_123 ( struct V_6 * V_7 )
{
F_124 ( V_7 -> V_94 ) ;
F_28 ( V_7 ) ;
}
static void V_47 ( struct V_6 * V_7 )
{
struct V_5 * V_17 ;
V_7 -> V_224 = & V_225 ;
V_7 -> V_226 = F_123 ;
V_7 -> type = V_25 ;
V_7 -> V_201 = V_227 + sizeof( struct V_62 ) + 4 ;
V_7 -> V_75 = V_228 - sizeof( struct V_62 ) - 4 ;
V_17 = F_12 ( V_7 ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_161 ) )
V_7 -> V_75 -= 8 ;
V_7 -> V_32 |= V_229 ;
V_7 -> V_195 = 0 ;
V_7 -> V_230 = sizeof( struct V_1 ) ;
V_7 -> V_231 &= ~ V_232 ;
}
static int F_125 ( struct V_6 * V_7 )
{
struct V_5 * V_90 ;
int V_233 ;
V_90 = F_12 ( V_7 ) ;
V_90 -> V_7 = V_7 ;
V_90 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_90 -> V_28 . V_45 , V_7 -> V_45 ) ;
memcpy ( V_7 -> V_186 , & V_90 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_187 , & V_90 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_90 -> V_28 . V_30 ) )
V_7 -> V_139 = & V_234 ;
V_7 -> V_94 = F_126 ( struct V_93 ) ;
if ( ! V_7 -> V_94 )
return - V_235 ;
F_127 (i) {
struct V_93 * V_236 ;
V_236 = F_128 ( V_7 -> V_94 , V_233 ) ;
F_129 ( & V_236 -> V_113 ) ;
}
return 0 ;
}
static void F_130 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_12 ( V_7 ) ;
V_90 -> V_7 = V_7 ;
V_90 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_90 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_90 -> V_140 = sizeof( struct V_62 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_131 ( struct V_12 * V_12 , struct V_237 * V_238 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_239 ;
int V_38 ;
F_132 (net, dev, aux)
if ( V_7 -> V_48 == & V_49 ||
V_7 -> V_48 == & V_240 )
F_133 ( V_7 , V_238 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_241 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 != NULL ) {
if ( ! F_72 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_133 ( V_17 -> V_7 ,
V_238 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_11 F_134 ( struct V_12 * V_12 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_91 ;
V_20 -> V_34 = F_23 ( sizeof( struct V_5 ) , L_8 ,
V_47 ) ;
if ( ! V_20 -> V_34 ) {
V_91 = - V_235 ;
goto V_242;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
V_20 -> V_34 -> V_53 |= V_243 ;
F_130 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_48 = & V_49 ;
V_91 = F_135 ( V_20 -> V_34 ) ;
if ( V_91 )
goto V_244;
F_17 ( V_20 -> V_245 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_244:
F_123 ( V_20 -> V_34 ) ;
V_242:
return V_91 ;
}
static void T_12 F_136 ( struct V_12 * V_12 )
{
F_137 ( V_246 ) ;
F_138 () ;
F_131 ( V_12 , & V_246 ) ;
F_139 ( & V_246 ) ;
F_140 () ;
}
static int F_141 ( struct V_247 * V_248 [] , struct V_247 * V_64 [] )
{
T_3 V_32 ;
if ( ! V_64 )
return 0 ;
V_32 = 0 ;
if ( V_64 [ V_249 ] )
V_32 |= F_142 ( V_64 [ V_249 ] ) ;
if ( V_64 [ V_250 ] )
V_32 |= F_142 ( V_64 [ V_250 ] ) ;
if ( V_32 & ( V_69 | V_68 ) )
return - V_218 ;
return 0 ;
}
static int F_143 ( struct V_247 * V_248 [] , struct V_247 * V_64 [] )
{
struct V_1 V_70 ;
if ( V_248 [ V_251 ] ) {
if ( F_144 ( V_248 [ V_251 ] ) != V_252 )
return - V_218 ;
if ( ! F_145 ( F_146 ( V_248 [ V_251 ] ) ) )
return - V_253 ;
}
if ( ! V_64 )
goto V_254;
if ( V_64 [ V_255 ] ) {
F_147 ( & V_70 , V_64 [ V_255 ] , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_70 ) )
return - V_218 ;
}
V_254:
return F_141 ( V_248 , V_64 ) ;
}
static void F_148 ( struct V_247 * V_64 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_64 )
return;
if ( V_64 [ V_256 ] )
V_28 -> V_13 = F_149 ( V_64 [ V_256 ] ) ;
if ( V_64 [ V_249 ] )
V_28 -> V_103 = F_142 ( V_64 [ V_249 ] ) ;
if ( V_64 [ V_250 ] )
V_28 -> V_51 = F_142 ( V_64 [ V_250 ] ) ;
if ( V_64 [ V_257 ] )
V_28 -> V_31 = F_150 ( V_64 [ V_257 ] ) ;
if ( V_64 [ V_258 ] )
V_28 -> V_157 = F_150 ( V_64 [ V_258 ] ) ;
if ( V_64 [ V_259 ] )
F_147 ( & V_28 -> V_29 , V_64 [ V_259 ] , sizeof( struct V_1 ) ) ;
if ( V_64 [ V_255 ] )
F_147 ( & V_28 -> V_30 , V_64 [ V_255 ] , sizeof( struct V_1 ) ) ;
if ( V_64 [ V_260 ] )
V_28 -> V_153 = F_151 ( V_64 [ V_260 ] ) ;
if ( V_64 [ V_261 ] )
V_28 -> V_81 = F_151 ( V_64 [ V_261 ] ) ;
if ( V_64 [ V_262 ] )
V_28 -> V_189 = F_149 ( V_64 [ V_262 ] ) ;
if ( V_64 [ V_263 ] )
V_28 -> V_32 = F_149 ( V_64 [ V_263 ] ) ;
}
static int F_152 ( struct V_6 * V_7 )
{
struct V_5 * V_90 ;
V_90 = F_12 ( V_7 ) ;
V_90 -> V_7 = V_7 ;
V_90 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_90 -> V_28 . V_45 , V_7 -> V_45 ) ;
F_25 ( V_90 , 1 ) ;
V_7 -> V_94 = F_153 ( struct V_93 ) ;
if ( ! V_7 -> V_94 )
return - V_235 ;
return 0 ;
}
static void F_154 ( struct V_6 * V_7 )
{
F_155 ( V_7 ) ;
V_7 -> V_224 = & V_264 ;
V_7 -> V_226 = F_123 ;
V_7 -> V_195 = 0 ;
V_7 -> V_53 |= V_243 ;
}
static int F_156 ( struct V_12 * V_265 , struct V_6 * V_7 ,
struct V_247 * V_248 [] , struct V_247 * V_64 [] )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_91 ;
V_44 = F_12 ( V_7 ) ;
F_148 ( V_64 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_219 ;
if ( V_7 -> type == V_24 && ! V_248 [ V_251 ] )
F_157 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_248 [ V_266 ] ) ;
if ( ! ( V_44 -> V_28 . V_51 & V_52 ) )
V_7 -> V_53 |= V_54 ;
V_91 = F_26 ( V_7 ) ;
if ( V_91 )
goto V_254;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_254:
return V_91 ;
}
static int F_158 ( struct V_6 * V_7 , struct V_247 * V_248 [] ,
struct V_247 * V_64 [] )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
if ( V_7 == V_20 -> V_34 )
return - V_218 ;
F_148 ( V_64 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_219 ;
} else {
V_17 = V_44 ;
F_19 ( V_20 , V_17 ) ;
F_110 ( V_17 , & V_36 , ! V_248 [ V_266 ] ) ;
F_16 ( V_20 , V_17 ) ;
F_119 ( V_7 ) ;
}
return 0 ;
}
static void F_159 ( struct V_6 * V_7 , struct V_237 * V_238 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_133 ( V_7 , V_238 ) ;
}
static T_13 F_160 ( const struct V_6 * V_7 )
{
return
F_161 ( 4 ) +
F_161 ( 2 ) +
F_161 ( 2 ) +
F_161 ( 4 ) +
F_161 ( 4 ) +
F_161 ( sizeof( struct V_1 ) ) +
F_161 ( sizeof( struct V_1 ) ) +
F_161 ( 1 ) +
F_161 ( 1 ) +
F_161 ( 1 ) +
F_161 ( 4 ) +
F_161 ( 4 ) +
0 ;
}
static int F_162 ( struct V_55 * V_56 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_163 ( V_56 , V_256 , V_36 -> V_13 ) ||
F_164 ( V_56 , V_249 , V_36 -> V_103 ) ||
F_164 ( V_56 , V_250 , V_36 -> V_51 ) ||
F_165 ( V_56 , V_257 , V_36 -> V_31 ) ||
F_165 ( V_56 , V_258 , V_36 -> V_157 ) ||
F_166 ( V_56 , V_259 , sizeof( struct V_1 ) , & V_36 -> V_29 ) ||
F_166 ( V_56 , V_255 , sizeof( struct V_1 ) , & V_36 -> V_30 ) ||
F_167 ( V_56 , V_260 , V_36 -> V_153 ) ||
F_167 ( V_56 , V_261 , V_36 -> V_81 ) ||
F_165 ( V_56 , V_262 , V_36 -> V_189 ) ||
F_163 ( V_56 , V_263 , V_36 -> V_32 ) )
goto V_267;
return 0 ;
V_267:
return - V_146 ;
}
static int T_14 F_168 ( void )
{
int V_91 ;
F_169 ( L_9 ) ;
V_91 = F_170 ( & V_268 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_171 ( & V_269 , V_203 ) ;
if ( V_91 < 0 ) {
F_169 ( L_10 , V_270 ) ;
goto V_271;
}
V_91 = F_172 ( & V_49 ) ;
if ( V_91 < 0 )
goto V_272;
V_91 = F_172 ( & V_240 ) ;
if ( V_91 < 0 )
goto V_273;
V_254:
return V_91 ;
V_273:
F_173 ( & V_49 ) ;
V_272:
F_174 ( & V_269 , V_203 ) ;
V_271:
F_175 ( & V_268 ) ;
goto V_254;
}
static void T_15 F_176 ( void )
{
F_173 ( & V_240 ) ;
F_173 ( & V_49 ) ;
F_174 ( & V_269 , V_203 ) ;
F_175 ( & V_268 ) ;
}
