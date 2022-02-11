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
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
F_19 ( V_20 , F_12 ( V_7 ) ) ;
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
switch ( V_56 -> V_93 ) {
case V_94 :
V_88 = F_38 ( V_56 -> V_88 ) ;
if ( ! V_88 )
break;
case V_95 :
V_56 -> V_88 = 0 ;
V_88 = F_39 ( V_56 ) ;
V_56 -> V_93 = V_94 ;
}
V_60 += 4 ;
}
if ( V_32 & V_67 ) {
V_10 = * ( T_2 * ) ( V_37 + V_60 ) ;
V_60 += 4 ;
}
if ( V_32 & V_52 ) {
V_89 = F_40 ( * ( T_2 * ) ( V_37 + V_60 ) ) ;
V_60 += 4 ;
}
}
V_11 = * ( T_3 * ) ( V_37 + 2 ) ;
V_90 = F_4 ( V_56 -> V_7 ,
& V_63 -> V_71 , & V_63 -> V_70 , V_10 ,
V_11 ) ;
if ( V_90 ) {
struct V_96 * V_97 ;
if ( ! F_41 ( NULL , V_98 , V_56 ) )
goto V_92;
if ( ! F_42 ( V_90 , & V_63 -> V_70 , & V_63 -> V_71 ) ) {
V_90 -> V_7 -> V_99 . V_100 ++ ;
goto V_92;
}
V_56 -> V_101 = V_11 ;
if ( V_32 == 0 && V_11 == F_8 ( V_102 ) ) {
V_56 -> V_101 = F_8 ( V_103 ) ;
if ( ( * ( V_37 + V_60 ) & 0xF0 ) != 0x40 )
V_60 += 4 ;
}
V_56 -> V_104 = V_56 -> V_105 ;
F_43 ( V_56 , V_60 ) ;
F_44 ( V_56 , F_45 ( V_56 ) , V_60 ) ;
if ( ( ( V_32 & V_66 ) && V_88 ) ||
( ! ( V_32 & V_66 ) && V_90 -> V_28 . V_106 & V_66 ) ) {
V_90 -> V_7 -> V_99 . V_107 ++ ;
V_90 -> V_7 -> V_99 . V_108 ++ ;
goto V_92;
}
if ( V_90 -> V_28 . V_106 & V_52 ) {
if ( ! ( V_32 & V_52 ) ||
( V_90 -> V_109 &&
( V_110 ) ( V_89 - V_90 -> V_109 ) < 0 ) ) {
V_90 -> V_7 -> V_99 . V_111 ++ ;
V_90 -> V_7 -> V_99 . V_108 ++ ;
goto V_92;
}
V_90 -> V_109 = V_89 + 1 ;
}
if ( V_90 -> V_7 -> type == V_24 ) {
if ( ! F_32 ( V_56 , V_112 ) ) {
V_90 -> V_7 -> V_99 . V_113 ++ ;
V_90 -> V_7 -> V_99 . V_108 ++ ;
goto V_92;
}
V_63 = F_37 ( V_56 ) ;
V_56 -> V_101 = F_46 ( V_56 , V_90 -> V_7 ) ;
F_44 ( V_56 , F_47 ( V_56 ) , V_112 ) ;
}
F_48 ( V_56 , V_90 -> V_7 , V_90 -> V_12 ) ;
F_49 ( V_56 ) ;
V_91 = F_50 ( V_63 , V_56 ) ;
if ( F_51 ( V_91 ) ) {
if ( V_114 )
F_52 ( L_6 ,
& V_63 -> V_71 ,
F_53 ( V_63 ) ) ;
if ( V_91 > 1 ) {
++ V_90 -> V_7 -> V_99 . V_115 ;
++ V_90 -> V_7 -> V_99 . V_108 ;
goto V_92;
}
}
V_97 = F_54 ( V_90 -> V_7 -> V_97 ) ;
F_55 ( & V_97 -> V_116 ) ;
V_97 -> V_117 ++ ;
V_97 -> V_118 += V_56 -> V_119 ;
F_56 ( & V_97 -> V_116 ) ;
F_57 ( V_56 ) ;
return 0 ;
}
F_58 ( V_56 , V_76 , V_120 , 0 ) ;
V_92:
F_59 ( V_56 ) ;
return 0 ;
}
static void F_60 ( struct V_121 * V_58 , T_8 V_81 )
{
memset ( V_58 , 0 , sizeof( struct V_121 ) ) ;
V_58 -> V_122 [ 2 ] = V_123 ;
V_58 -> V_122 [ 3 ] = 1 ;
V_58 -> V_122 [ 4 ] = V_81 ;
V_58 -> V_122 [ 5 ] = V_124 ;
V_58 -> V_122 [ 6 ] = 1 ;
V_58 -> V_125 . V_126 = (struct V_127 * ) V_58 -> V_122 ;
V_58 -> V_125 . V_128 = 8 ;
}
static T_9 F_61 ( struct V_55 * V_56 ,
struct V_6 * V_7 ,
T_8 V_129 ,
struct V_130 * V_131 ,
int V_81 ,
T_6 * V_132 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_5 * V_90 = F_12 ( V_7 ) ;
struct V_6 * V_133 ;
struct V_62 * V_63 ;
unsigned int V_134 = 0 ;
int V_135 ;
struct V_121 V_58 ;
int V_75 ;
struct V_136 * V_137 = NULL , * V_138 = NULL ;
struct V_139 * V_99 = & V_90 -> V_7 -> V_99 ;
int V_91 = - 1 ;
T_5 V_140 ;
struct V_55 * V_141 ;
if ( V_7 -> type == V_24 )
F_62 ( V_56 ) -> V_32 = 0 ;
if ( V_7 -> V_142 && V_7 -> type == V_25 ) {
V_135 = 0 ;
V_63 = (struct V_62 * ) V_56 -> V_64 ;
V_131 -> V_70 = V_63 -> V_70 ;
} else {
V_135 = V_90 -> V_143 ;
V_131 -> V_70 = V_90 -> V_28 . V_30 ;
}
if ( ! V_131 -> V_144 )
V_137 = F_63 ( V_90 ) ;
if ( ! V_137 ) {
V_138 = F_64 ( V_12 , NULL , V_131 ) ;
if ( V_138 -> error )
goto V_145;
V_138 = F_65 ( V_12 , V_138 , F_66 ( V_131 ) , NULL , 0 ) ;
if ( F_67 ( V_138 ) ) {
V_91 = F_68 ( V_138 ) ;
V_138 = NULL ;
goto V_145;
}
V_137 = V_138 ;
}
V_133 = V_137 -> V_7 ;
if ( V_133 == V_7 ) {
V_99 -> V_146 ++ ;
F_33 ( L_7 ,
V_90 -> V_28 . V_45 ) ;
goto V_147;
}
V_75 = F_69 ( V_137 ) - sizeof( * V_63 ) ;
if ( V_81 >= 0 ) {
V_134 += 8 ;
V_75 -= 8 ;
}
if ( V_75 < V_83 )
V_75 = V_83 ;
if ( F_70 ( V_56 ) )
F_70 ( V_56 ) -> V_125 -> V_148 ( F_70 ( V_56 ) , NULL , V_56 , V_75 ) ;
if ( V_56 -> V_119 > V_75 ) {
* V_132 = V_75 ;
V_91 = - V_149 ;
goto V_147;
}
if ( V_90 -> V_87 > 0 ) {
if ( F_35 ( V_84 ,
V_90 -> V_85 + V_86 ) ) {
V_90 -> V_87 -- ;
F_71 ( V_56 ) ;
} else
V_90 -> V_87 = 0 ;
}
F_72 ( V_56 , ! F_73 ( V_90 -> V_12 , F_5 ( V_7 ) ) ) ;
V_134 += F_74 ( V_133 ) + V_135 + V_137 -> V_150 ;
if ( F_75 ( V_56 ) < V_134 || F_76 ( V_56 ) ||
( F_77 ( V_56 ) && ! F_78 ( V_56 , 0 ) ) ) {
V_141 = F_79 ( V_56 , V_134 ) ;
if ( V_134 > V_7 -> V_151 )
V_7 -> V_151 = V_134 ;
if ( ! V_141 )
goto V_147;
if ( V_56 -> V_152 )
F_80 ( V_141 , V_56 -> V_152 ) ;
F_81 ( V_56 ) ;
V_56 = V_141 ;
}
if ( V_131 -> V_144 ) {
F_82 ( V_56 , V_137 ) ;
V_138 = NULL ;
} else {
F_83 ( V_56 , V_137 ) ;
}
V_140 = V_153 ;
if ( V_81 >= 0 ) {
F_60 ( & V_58 , V_81 ) ;
F_84 ( V_56 , & V_58 . V_125 , & V_140 , NULL ) ;
}
if ( F_85 ( ! V_56 -> V_154 ) ) {
F_86 ( V_56 ) ;
V_56 -> V_154 = 1 ;
}
F_87 ( V_56 , V_135 ) ;
F_49 ( V_56 ) ;
F_88 ( V_56 , sizeof( * V_63 ) ) ;
V_63 = F_37 ( V_56 ) ;
F_89 ( V_63 , F_90 ( 0 , V_129 ) , V_131 -> V_155 ) ;
V_63 -> V_156 = V_90 -> V_28 . V_156 ;
V_63 -> V_157 = V_140 ;
V_63 -> V_71 = V_131 -> V_71 ;
V_63 -> V_70 = V_131 -> V_70 ;
( ( T_3 * ) ( V_63 + 1 ) ) [ 0 ] = V_90 -> V_28 . V_51 ;
( ( T_3 * ) ( V_63 + 1 ) ) [ 1 ] = ( V_7 -> type == V_24 ) ?
F_8 ( V_23 ) : V_56 -> V_101 ;
if ( V_90 -> V_28 . V_51 & ( V_67 | V_66 | V_52 ) ) {
T_2 * V_158 = ( T_2 * ) ( ( ( T_5 * ) V_63 ) + V_90 -> V_143 - 4 ) ;
if ( V_90 -> V_28 . V_51 & V_52 ) {
++ V_90 -> V_159 ;
* V_158 = F_91 ( V_90 -> V_159 ) ;
V_158 -- ;
}
if ( V_90 -> V_28 . V_51 & V_67 ) {
* V_158 = V_90 -> V_28 . V_160 ;
V_158 -- ;
}
if ( V_90 -> V_28 . V_51 & V_66 ) {
* V_158 = 0 ;
* ( T_7 * ) V_158 = F_92 ( ( void * ) ( V_63 + 1 ) ,
V_56 -> V_119 - sizeof( struct V_62 ) ) ;
}
}
F_93 ( V_56 , V_7 ) ;
if ( V_138 )
F_94 ( V_90 , V_138 ) ;
return 0 ;
V_145:
V_99 -> V_161 ++ ;
F_71 ( V_56 ) ;
V_147:
F_95 ( V_138 ) ;
return V_91 ;
}
static inline int F_96 ( struct V_55 * V_56 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_162 * V_163 = F_97 ( V_56 ) ;
int V_81 = - 1 ;
struct V_130 V_131 ;
T_8 V_129 ;
T_6 V_75 ;
int V_91 ;
if ( ! ( V_17 -> V_28 . V_32 & V_164 ) )
V_81 = V_17 -> V_28 . V_81 ;
memcpy ( & V_131 , & V_17 -> V_165 . V_166 . V_167 , sizeof( V_131 ) ) ;
V_131 . V_168 = V_169 ;
V_129 = F_98 ( V_163 ) ;
if ( V_17 -> V_28 . V_32 & V_170 )
V_131 . V_155 |= F_91 ( ( T_6 ) V_163 -> V_171 << V_172 )
& V_173 ;
if ( V_17 -> V_28 . V_32 & V_174 )
V_131 . V_144 = V_56 -> V_175 ;
V_91 = F_61 ( V_56 , V_7 , V_129 , & V_131 , V_81 , & V_75 ) ;
if ( V_91 != 0 ) {
if ( V_91 == - V_149 )
F_99 ( V_56 , V_176 , V_177 ,
F_91 ( V_75 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_100 ( struct V_55 * V_56 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_62 * V_63 = F_37 ( V_56 ) ;
int V_81 = - 1 ;
T_10 V_60 ;
struct V_130 V_131 ;
T_8 V_129 ;
T_6 V_75 ;
int V_91 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_63 -> V_71 ) )
return - 1 ;
V_60 = F_34 ( V_56 , F_101 ( V_56 ) ) ;
if ( V_60 > 0 ) {
struct V_73 * V_74 ;
V_74 = (struct V_73 * ) & F_101 ( V_56 ) [ V_60 ] ;
if ( V_74 -> V_81 == 0 ) {
F_58 ( V_56 , V_79 ,
V_80 , V_60 + 2 ) ;
return - 1 ;
}
V_81 = V_74 -> V_81 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_164 ) )
V_81 = V_17 -> V_28 . V_81 ;
memcpy ( & V_131 , & V_17 -> V_165 . V_166 . V_167 , sizeof( V_131 ) ) ;
V_131 . V_168 = V_178 ;
V_129 = F_53 ( V_63 ) ;
if ( V_17 -> V_28 . V_32 & V_170 )
V_131 . V_155 |= ( * ( T_2 * ) V_63 & V_173 ) ;
if ( V_17 -> V_28 . V_32 & V_179 )
V_131 . V_155 |= F_102 ( V_63 ) ;
if ( V_17 -> V_28 . V_32 & V_174 )
V_131 . V_144 = V_56 -> V_175 ;
V_91 = F_61 ( V_56 , V_7 , V_129 , & V_131 , V_81 , & V_75 ) ;
if ( V_91 != 0 ) {
if ( V_91 == - V_149 )
F_58 ( V_56 , V_82 , 0 , V_75 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_103 ( const struct V_5 * V_17 ,
const struct V_62 * V_180 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_180 -> V_71 ) ;
}
static int F_104 ( struct V_55 * V_56 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_81 = - 1 ;
struct V_130 V_131 ;
T_6 V_75 ;
int V_91 ;
if ( ! ( V_17 -> V_28 . V_32 & V_164 ) )
V_81 = V_17 -> V_28 . V_81 ;
memcpy ( & V_131 , & V_17 -> V_165 . V_166 . V_167 , sizeof( V_131 ) ) ;
V_131 . V_168 = V_56 -> V_101 ;
V_91 = F_61 ( V_56 , V_7 , 0 , & V_131 , V_81 , & V_75 ) ;
return V_91 ;
}
static T_9 F_105 ( struct V_55 * V_56 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_139 * V_99 = & V_17 -> V_7 -> V_99 ;
int V_181 ;
if ( ! F_106 ( V_17 ) )
goto V_182;
switch ( V_56 -> V_101 ) {
case F_8 ( V_103 ) :
V_181 = F_96 ( V_56 , V_7 ) ;
break;
case F_8 ( V_183 ) :
V_181 = F_100 ( V_56 , V_7 ) ;
break;
default:
V_181 = F_104 ( V_56 , V_7 ) ;
break;
}
if ( V_181 < 0 )
goto V_182;
return V_184 ;
V_182:
V_99 -> V_185 ++ ;
V_99 -> V_186 ++ ;
F_59 ( V_56 ) ;
return V_184 ;
}
static void F_25 ( struct V_5 * V_17 , int V_187 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_130 * V_131 = & V_17 -> V_165 . V_166 . V_167 ;
int V_188 = sizeof( struct V_62 ) + 4 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_189 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_190 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_131 -> V_71 = V_36 -> V_29 ;
V_131 -> V_70 = V_36 -> V_30 ;
V_131 -> V_191 = V_36 -> V_13 ;
V_131 -> V_155 = 0 ;
if ( ! ( V_36 -> V_32 & V_170 ) )
V_131 -> V_155 |= V_173 & V_36 -> V_192 ;
if ( ! ( V_36 -> V_32 & V_179 ) )
V_131 -> V_155 |= V_193 & V_36 -> V_192 ;
V_36 -> V_32 &= ~ ( V_194 | V_195 | V_196 ) ;
V_36 -> V_32 |= F_107 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_194 &&
V_36 -> V_32 & V_195 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_197 ;
else
V_7 -> V_32 &= ~ V_197 ;
V_7 -> V_198 = V_36 -> V_13 ;
if ( V_17 -> V_28 . V_51 & ( V_66 | V_67 | V_52 ) ) {
if ( V_17 -> V_28 . V_51 & V_66 )
V_188 += 4 ;
if ( V_17 -> V_28 . V_51 & V_67 )
V_188 += 4 ;
if ( V_17 -> V_28 . V_51 & V_52 )
V_188 += 4 ;
}
V_17 -> V_143 = V_188 ;
if ( V_36 -> V_32 & V_194 ) {
int V_199 = ( F_108 ( & V_36 -> V_30 ) &
( V_200 | V_201 ) ) ;
struct V_202 * V_203 = F_109 ( F_5 ( V_7 ) ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_199 ) ;
if ( V_203 == NULL )
return;
if ( V_203 -> V_137 . V_7 ) {
V_7 -> V_204 = V_203 -> V_137 . V_7 -> V_204 + V_188 ;
if ( V_187 ) {
V_7 -> V_75 = V_203 -> V_137 . V_7 -> V_75 - V_188 ;
if ( ! ( V_17 -> V_28 . V_32 & V_164 ) )
V_7 -> V_75 -= 8 ;
if ( V_7 -> V_75 < V_83 )
V_7 -> V_75 = V_83 ;
}
}
F_110 ( V_203 ) ;
}
}
static int F_111 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_187 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_156 = V_36 -> V_156 ;
V_17 -> V_28 . V_81 = V_36 -> V_81 ;
V_17 -> V_28 . V_192 = V_36 -> V_192 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_140 = V_36 -> V_140 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_160 = V_36 -> V_160 ;
V_17 -> V_28 . V_106 = V_36 -> V_106 ;
V_17 -> V_28 . V_51 = V_36 -> V_51 ;
F_112 ( V_17 ) ;
F_25 ( V_17 , V_187 ) ;
return 0 ;
}
static void F_113 ( struct V_35 * V_36 ,
const struct V_205 * V_166 )
{
V_36 -> V_29 = V_166 -> V_29 ;
V_36 -> V_30 = V_166 -> V_30 ;
V_36 -> V_32 = V_166 -> V_32 ;
V_36 -> V_156 = V_166 -> V_156 ;
V_36 -> V_81 = V_166 -> V_81 ;
V_36 -> V_192 = V_166 -> V_192 ;
V_36 -> V_13 = V_166 -> V_13 ;
V_36 -> V_31 = V_166 -> V_31 ;
V_36 -> V_160 = V_166 -> V_160 ;
V_36 -> V_106 = V_166 -> V_106 ;
V_36 -> V_51 = V_166 -> V_51 ;
memcpy ( V_36 -> V_45 , V_166 -> V_45 , sizeof( V_166 -> V_45 ) ) ;
}
static void F_114 ( struct V_205 * V_166 ,
const struct V_35 * V_36 )
{
V_166 -> V_140 = V_206 ;
V_166 -> V_29 = V_36 -> V_29 ;
V_166 -> V_30 = V_36 -> V_30 ;
V_166 -> V_32 = V_36 -> V_32 ;
V_166 -> V_156 = V_36 -> V_156 ;
V_166 -> V_81 = V_36 -> V_81 ;
V_166 -> V_192 = V_36 -> V_192 ;
V_166 -> V_13 = V_36 -> V_13 ;
V_166 -> V_31 = V_36 -> V_31 ;
V_166 -> V_160 = V_36 -> V_160 ;
V_166 -> V_106 = V_36 -> V_106 ;
V_166 -> V_51 = V_36 -> V_51 ;
memcpy ( V_166 -> V_45 , V_36 -> V_45 , sizeof( V_166 -> V_45 ) ) ;
}
static int F_115 ( struct V_6 * V_7 ,
struct V_207 * V_208 , int V_209 )
{
int V_91 = 0 ;
struct V_205 V_36 ;
struct V_35 V_210 ;
struct V_5 * V_17 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
switch ( V_209 ) {
case V_211 :
V_17 = NULL ;
if ( V_7 == V_20 -> V_34 ) {
if ( F_116 ( & V_36 , V_208 -> V_212 . V_213 , sizeof( V_36 ) ) ) {
V_91 = - V_214 ;
break;
}
F_113 ( & V_210 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_210 , 0 ) ;
}
if ( V_17 == NULL )
V_17 = F_12 ( V_7 ) ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_114 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_117 ( V_208 -> V_212 . V_213 , & V_36 , sizeof( V_36 ) ) )
V_91 = - V_214 ;
break;
case V_215 :
case V_216 :
V_91 = - V_217 ;
if ( ! F_118 ( V_12 -> V_218 , V_219 ) )
goto V_220;
V_91 = - V_214 ;
if ( F_116 ( & V_36 , V_208 -> V_212 . V_213 , sizeof( V_36 ) ) )
goto V_220;
V_91 = - V_221 ;
if ( ( V_36 . V_106 | V_36 . V_51 ) & ( V_69 | V_68 ) )
goto V_220;
if ( ! ( V_36 . V_106 & V_67 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_51 & V_67 ) )
V_36 . V_160 = 0 ;
F_113 ( & V_210 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_210 , V_209 == V_215 ) ;
if ( V_7 != V_20 -> V_34 && V_209 == V_216 ) {
if ( V_17 != NULL ) {
if ( V_17 -> V_7 != V_7 ) {
V_91 = - V_222 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_119 () ;
F_111 ( V_17 , & V_210 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_120 ( V_7 ) ;
}
}
if ( V_17 ) {
V_91 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_114 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_117 ( V_208 -> V_212 . V_213 , & V_36 , sizeof( V_36 ) ) )
V_91 = - V_214 ;
} else
V_91 = ( V_209 == V_215 ? - V_223 : - V_224 ) ;
break;
case V_225 :
V_91 = - V_217 ;
if ( ! F_118 ( V_12 -> V_218 , V_219 ) )
goto V_220;
if ( V_7 == V_20 -> V_34 ) {
V_91 = - V_214 ;
if ( F_116 ( & V_36 , V_208 -> V_212 . V_213 , sizeof( V_36 ) ) )
goto V_220;
V_91 = - V_224 ;
F_113 ( & V_210 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_210 , 0 ) ;
if ( V_17 == NULL )
goto V_220;
V_91 = - V_217 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_220;
V_7 = V_17 -> V_7 ;
}
F_121 ( V_7 ) ;
V_91 = 0 ;
break;
default:
V_91 = - V_221 ;
}
V_220:
return V_91 ;
}
static int F_122 ( struct V_6 * V_7 , int V_226 )
{
if ( V_226 < 68 ||
V_226 > 0xFFF8 - V_7 -> V_204 )
return - V_221 ;
V_7 -> V_75 = V_226 ;
return 0 ;
}
static int F_123 ( struct V_55 * V_56 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_70 , const void * V_71 , unsigned int V_119 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_62 * V_63 = (struct V_62 * ) F_87 ( V_56 , V_17 -> V_143 ) ;
T_3 * V_36 = ( T_3 * ) ( V_63 + 1 ) ;
F_89 ( V_63 , 0 , V_17 -> V_165 . V_166 . V_167 . V_155 ) ;
V_63 -> V_156 = V_17 -> V_28 . V_156 ;
V_63 -> V_157 = V_153 ;
V_63 -> V_71 = V_17 -> V_28 . V_29 ;
V_63 -> V_70 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_51 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_71 )
memcpy ( & V_63 -> V_71 , V_71 , sizeof( struct V_1 ) ) ;
if ( V_70 )
memcpy ( & V_63 -> V_70 , V_70 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_63 -> V_70 ) )
return V_17 -> V_143 ;
return - V_17 -> V_143 ;
}
static void F_124 ( struct V_6 * V_7 )
{
F_125 ( V_7 -> V_97 ) ;
F_28 ( V_7 ) ;
}
static void V_47 ( struct V_6 * V_7 )
{
struct V_5 * V_17 ;
V_7 -> V_227 = & V_228 ;
V_7 -> V_229 = F_124 ;
V_7 -> type = V_25 ;
V_7 -> V_204 = V_230 + sizeof( struct V_62 ) + 4 ;
V_7 -> V_75 = V_231 - sizeof( struct V_62 ) - 4 ;
V_17 = F_12 ( V_7 ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_164 ) )
V_7 -> V_75 -= 8 ;
V_7 -> V_32 |= V_232 ;
V_7 -> V_198 = 0 ;
V_7 -> V_233 = sizeof( struct V_1 ) ;
V_7 -> V_53 |= V_234 ;
V_7 -> V_235 &= ~ V_236 ;
}
static int F_126 ( struct V_6 * V_7 )
{
struct V_5 * V_90 ;
int V_237 ;
V_90 = F_12 ( V_7 ) ;
V_90 -> V_7 = V_7 ;
V_90 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_90 -> V_28 . V_45 , V_7 -> V_45 ) ;
memcpy ( V_7 -> V_189 , & V_90 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_190 , & V_90 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_90 -> V_28 . V_30 ) )
V_7 -> V_142 = & V_238 ;
V_7 -> V_97 = F_127 ( struct V_96 ) ;
if ( ! V_7 -> V_97 )
return - V_239 ;
F_128 (i) {
struct V_96 * V_240 ;
V_240 = F_129 ( V_7 -> V_97 , V_237 ) ;
F_130 ( & V_240 -> V_116 ) ;
}
return 0 ;
}
static void F_131 ( struct V_6 * V_7 )
{
struct V_5 * V_90 = F_12 ( V_7 ) ;
V_90 -> V_7 = V_7 ;
V_90 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_90 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_90 -> V_143 = sizeof( struct V_62 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_132 ( struct V_19 * V_20 ,
struct V_241 * V_242 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_243 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 != NULL ) {
F_133 ( V_17 -> V_7 , V_242 ) ;
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
V_91 = - V_239 ;
goto V_244;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
F_131 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_48 = & V_49 ;
V_91 = F_135 ( V_20 -> V_34 ) ;
if ( V_91 )
goto V_245;
F_17 ( V_20 -> V_246 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_245:
F_124 ( V_20 -> V_34 ) ;
V_244:
return V_91 ;
}
static void T_12 F_136 ( struct V_12 * V_12 )
{
struct V_19 * V_20 ;
F_137 ( V_247 ) ;
V_20 = F_7 ( V_12 , V_21 ) ;
F_138 () ;
F_132 ( V_20 , & V_247 ) ;
F_139 ( & V_247 ) ;
F_140 () ;
}
static int F_141 ( struct V_248 * V_249 [] , struct V_248 * V_64 [] )
{
T_3 V_32 ;
if ( ! V_64 )
return 0 ;
V_32 = 0 ;
if ( V_64 [ V_250 ] )
V_32 |= F_142 ( V_64 [ V_250 ] ) ;
if ( V_64 [ V_251 ] )
V_32 |= F_142 ( V_64 [ V_251 ] ) ;
if ( V_32 & ( V_69 | V_68 ) )
return - V_221 ;
return 0 ;
}
static int F_143 ( struct V_248 * V_249 [] , struct V_248 * V_64 [] )
{
struct V_1 V_70 ;
if ( V_249 [ V_252 ] ) {
if ( F_144 ( V_249 [ V_252 ] ) != V_253 )
return - V_221 ;
if ( ! F_145 ( F_146 ( V_249 [ V_252 ] ) ) )
return - V_254 ;
}
if ( ! V_64 )
goto V_255;
if ( V_64 [ V_256 ] ) {
F_147 ( & V_70 , V_64 [ V_256 ] , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_70 ) )
return - V_221 ;
}
V_255:
return F_141 ( V_249 , V_64 ) ;
}
static void F_148 ( struct V_248 * V_64 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_64 )
return;
if ( V_64 [ V_257 ] )
V_28 -> V_13 = F_149 ( V_64 [ V_257 ] ) ;
if ( V_64 [ V_250 ] )
V_28 -> V_106 = F_142 ( V_64 [ V_250 ] ) ;
if ( V_64 [ V_251 ] )
V_28 -> V_51 = F_142 ( V_64 [ V_251 ] ) ;
if ( V_64 [ V_258 ] )
V_28 -> V_31 = F_150 ( V_64 [ V_258 ] ) ;
if ( V_64 [ V_259 ] )
V_28 -> V_160 = F_150 ( V_64 [ V_259 ] ) ;
if ( V_64 [ V_260 ] )
F_147 ( & V_28 -> V_29 , V_64 [ V_260 ] , sizeof( struct V_1 ) ) ;
if ( V_64 [ V_256 ] )
F_147 ( & V_28 -> V_30 , V_64 [ V_256 ] , sizeof( struct V_1 ) ) ;
if ( V_64 [ V_261 ] )
V_28 -> V_156 = F_151 ( V_64 [ V_261 ] ) ;
if ( V_64 [ V_262 ] )
V_28 -> V_81 = F_151 ( V_64 [ V_262 ] ) ;
if ( V_64 [ V_263 ] )
V_28 -> V_192 = F_149 ( V_64 [ V_263 ] ) ;
if ( V_64 [ V_264 ] )
V_28 -> V_32 = F_149 ( V_64 [ V_264 ] ) ;
}
static int F_152 ( struct V_6 * V_7 )
{
struct V_5 * V_90 ;
V_90 = F_12 ( V_7 ) ;
V_90 -> V_7 = V_7 ;
V_90 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_90 -> V_28 . V_45 , V_7 -> V_45 ) ;
F_25 ( V_90 , 1 ) ;
V_7 -> V_97 = F_153 ( struct V_96 ) ;
if ( ! V_7 -> V_97 )
return - V_239 ;
return 0 ;
}
static void F_154 ( struct V_6 * V_7 )
{
F_155 ( V_7 ) ;
V_7 -> V_227 = & V_265 ;
V_7 -> V_229 = F_124 ;
V_7 -> V_198 = 0 ;
V_7 -> V_53 |= V_234 ;
}
static int F_156 ( struct V_12 * V_266 , struct V_6 * V_7 ,
struct V_248 * V_249 [] , struct V_248 * V_64 [] )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_91 ;
V_44 = F_12 ( V_7 ) ;
F_148 ( V_64 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_222 ;
if ( V_7 -> type == V_24 && ! V_249 [ V_252 ] )
F_157 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_249 [ V_267 ] ) ;
if ( ! ( V_44 -> V_28 . V_51 & V_52 ) )
V_7 -> V_53 |= V_54 ;
V_91 = F_26 ( V_7 ) ;
if ( V_91 )
goto V_255;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_255:
return V_91 ;
}
static int F_158 ( struct V_6 * V_7 , struct V_248 * V_249 [] ,
struct V_248 * V_64 [] )
{
struct V_5 * V_17 , * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
if ( V_7 == V_20 -> V_34 )
return - V_221 ;
V_44 = F_12 ( V_7 ) ;
F_148 ( V_64 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_222 ;
} else {
V_17 = V_44 ;
F_19 ( V_20 , V_17 ) ;
F_111 ( V_17 , & V_36 , ! V_249 [ V_267 ] ) ;
F_16 ( V_20 , V_17 ) ;
F_120 ( V_7 ) ;
}
return 0 ;
}
static void F_159 ( struct V_6 * V_7 , struct V_241 * V_242 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_133 ( V_7 , V_242 ) ;
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
if ( F_163 ( V_56 , V_257 , V_36 -> V_13 ) ||
F_164 ( V_56 , V_250 , V_36 -> V_106 ) ||
F_164 ( V_56 , V_251 , V_36 -> V_51 ) ||
F_165 ( V_56 , V_258 , V_36 -> V_31 ) ||
F_165 ( V_56 , V_259 , V_36 -> V_160 ) ||
F_166 ( V_56 , V_260 , sizeof( struct V_1 ) , & V_36 -> V_29 ) ||
F_166 ( V_56 , V_256 , sizeof( struct V_1 ) , & V_36 -> V_30 ) ||
F_167 ( V_56 , V_261 , V_36 -> V_156 ) ||
F_167 ( V_56 , V_262 , V_36 -> V_81 ) ||
F_165 ( V_56 , V_263 , V_36 -> V_192 ) ||
F_163 ( V_56 , V_264 , V_36 -> V_32 ) )
goto V_268;
return 0 ;
V_268:
return - V_149 ;
}
static int T_14 F_168 ( void )
{
int V_91 ;
F_169 ( L_9 ) ;
V_91 = F_170 ( & V_269 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_171 ( & V_270 , V_206 ) ;
if ( V_91 < 0 ) {
F_169 ( L_10 , V_271 ) ;
goto V_272;
}
V_91 = F_172 ( & V_49 ) ;
if ( V_91 < 0 )
goto V_273;
V_91 = F_172 ( & V_274 ) ;
if ( V_91 < 0 )
goto V_275;
V_255:
return V_91 ;
V_275:
F_173 ( & V_49 ) ;
V_273:
F_174 ( & V_270 , V_206 ) ;
V_272:
F_175 ( & V_269 ) ;
goto V_255;
}
static void T_15 F_176 ( void )
{
F_173 ( & V_274 ) ;
F_173 ( & V_49 ) ;
F_174 ( & V_270 , V_206 ) ;
F_175 ( & V_269 ) ;
}
