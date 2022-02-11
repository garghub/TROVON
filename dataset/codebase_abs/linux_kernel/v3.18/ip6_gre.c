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
F_30 ( V_7 ) ;
}
static void F_31 ( struct V_56 * V_57 , struct V_58 * V_59 ,
T_5 type , T_5 V_60 , int V_61 , T_2 V_62 )
{
const struct V_63 * V_64 = ( const struct V_63 * ) V_57 -> V_65 ;
T_3 * V_36 = ( T_3 * ) ( V_57 -> V_65 + V_61 ) ;
int V_66 = V_61 + 4 ;
struct V_5 * V_17 ;
T_3 V_32 ;
V_32 = V_36 [ 0 ] ;
if ( V_32 & ( V_67 | V_68 | V_53 | V_69 | V_70 ) ) {
if ( V_32 & ( V_70 | V_69 ) )
return;
if ( V_32 & V_68 ) {
V_66 += 4 ;
if ( V_32 & V_67 )
V_66 += 4 ;
}
}
if ( ! F_32 ( V_57 , V_66 ) )
return;
V_64 = ( const struct V_63 * ) V_57 -> V_65 ;
V_36 = ( T_3 * ) ( V_57 -> V_65 + V_61 ) ;
V_17 = F_4 ( V_57 -> V_7 , & V_64 -> V_71 , & V_64 -> V_72 ,
V_32 & V_68 ?
* ( ( ( T_2 * ) V_36 ) + ( V_66 / 4 ) - 1 ) : 0 ,
V_36 [ 1 ] ) ;
if ( V_17 == NULL )
return;
switch ( type ) {
T_6 V_73 ;
struct V_74 * V_75 ;
T_6 V_76 ;
case V_77 :
F_33 ( L_2 ,
V_17 -> V_28 . V_45 ) ;
break;
case V_78 :
if ( V_60 == V_79 ) {
F_33 ( L_3 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_80 :
V_73 = 0 ;
if ( V_60 == V_81 )
V_73 = F_34 ( V_57 , V_57 -> V_65 ) ;
if ( V_73 && V_73 == V_62 - 2 ) {
V_75 = (struct V_74 * ) & V_57 -> V_65 [ V_73 ] ;
if ( V_75 -> V_82 == 0 ) {
F_33 ( L_4 ,
V_17 -> V_28 . V_45 ) ;
}
} else {
F_33 ( L_5 ,
V_17 -> V_28 . V_45 ) ;
}
break;
case V_83 :
V_76 = V_62 - V_61 ;
if ( V_76 < V_84 )
V_76 = V_84 ;
V_17 -> V_7 -> V_76 = V_76 ;
break;
}
if ( F_35 ( V_85 , V_17 -> V_86 + V_87 ) )
V_17 -> V_88 ++ ;
else
V_17 -> V_88 = 1 ;
V_17 -> V_86 = V_85 ;
}
static int F_36 ( struct V_56 * V_57 )
{
const struct V_63 * V_64 ;
T_5 * V_37 ;
T_3 V_32 ;
T_7 V_89 = 0 ;
T_2 V_10 = 0 ;
T_1 V_90 = 0 ;
struct V_5 * V_91 ;
int V_61 = 4 ;
T_3 V_11 ;
int V_92 ;
if ( ! F_32 ( V_57 , sizeof( struct V_1 ) ) )
goto V_93;
V_64 = F_37 ( V_57 ) ;
V_37 = V_57 -> V_65 ;
V_32 = * ( T_3 * ) V_37 ;
if ( V_32 & ( V_67 | V_68 | V_69 | V_53 | V_70 ) ) {
if ( V_32 & ( V_70 | V_69 ) )
goto V_93;
if ( V_32 & V_67 ) {
V_89 = F_38 ( V_57 ) ;
V_61 += 4 ;
}
if ( V_32 & V_68 ) {
V_10 = * ( T_2 * ) ( V_37 + V_61 ) ;
V_61 += 4 ;
}
if ( V_32 & V_53 ) {
V_90 = F_39 ( * ( T_2 * ) ( V_37 + V_61 ) ) ;
V_61 += 4 ;
}
}
V_11 = * ( T_3 * ) ( V_37 + 2 ) ;
V_91 = F_4 ( V_57 -> V_7 ,
& V_64 -> V_72 , & V_64 -> V_71 , V_10 ,
V_11 ) ;
if ( V_91 ) {
struct V_94 * V_95 ;
if ( ! F_40 ( NULL , V_96 , V_57 ) )
goto V_93;
if ( ! F_41 ( V_91 , & V_64 -> V_71 , & V_64 -> V_72 ) ) {
V_91 -> V_7 -> V_97 . V_98 ++ ;
goto V_93;
}
V_57 -> V_99 = V_11 ;
if ( V_32 == 0 && V_11 == F_8 ( V_100 ) ) {
V_57 -> V_99 = F_8 ( V_101 ) ;
if ( ( * ( V_37 + V_61 ) & 0xF0 ) != 0x40 )
V_61 += 4 ;
}
V_57 -> V_102 = V_57 -> V_103 ;
F_42 ( V_57 , V_61 ) ;
F_43 ( V_57 , F_44 ( V_57 ) , V_61 ) ;
if ( ( ( V_32 & V_67 ) && V_89 ) ||
( ! ( V_32 & V_67 ) && V_91 -> V_28 . V_104 & V_67 ) ) {
V_91 -> V_7 -> V_97 . V_105 ++ ;
V_91 -> V_7 -> V_97 . V_106 ++ ;
goto V_93;
}
if ( V_91 -> V_28 . V_104 & V_53 ) {
if ( ! ( V_32 & V_53 ) ||
( V_91 -> V_107 &&
( V_108 ) ( V_90 - V_91 -> V_107 ) < 0 ) ) {
V_91 -> V_7 -> V_97 . V_109 ++ ;
V_91 -> V_7 -> V_97 . V_106 ++ ;
goto V_93;
}
V_91 -> V_107 = V_90 + 1 ;
}
if ( V_91 -> V_7 -> type == V_24 ) {
if ( ! F_32 ( V_57 , V_110 ) ) {
V_91 -> V_7 -> V_97 . V_111 ++ ;
V_91 -> V_7 -> V_97 . V_106 ++ ;
goto V_93;
}
V_64 = F_37 ( V_57 ) ;
V_57 -> V_99 = F_45 ( V_57 , V_91 -> V_7 ) ;
F_43 ( V_57 , F_46 ( V_57 ) , V_110 ) ;
}
F_47 ( V_57 , V_91 -> V_7 , V_91 -> V_12 ) ;
F_48 ( V_57 ) ;
V_92 = F_49 ( V_64 , V_57 ) ;
if ( F_50 ( V_92 ) ) {
if ( V_112 )
F_51 ( L_6 ,
& V_64 -> V_72 ,
F_52 ( V_64 ) ) ;
if ( V_92 > 1 ) {
++ V_91 -> V_7 -> V_97 . V_113 ;
++ V_91 -> V_7 -> V_97 . V_106 ;
goto V_93;
}
}
V_95 = F_53 ( V_91 -> V_7 -> V_95 ) ;
F_54 ( & V_95 -> V_114 ) ;
V_95 -> V_115 ++ ;
V_95 -> V_116 += V_57 -> V_117 ;
F_55 ( & V_95 -> V_114 ) ;
F_56 ( V_57 ) ;
return 0 ;
}
F_57 ( V_57 , V_77 , V_118 , 0 ) ;
V_93:
F_58 ( V_57 ) ;
return 0 ;
}
static void F_59 ( struct V_119 * V_59 , T_8 V_82 )
{
memset ( V_59 , 0 , sizeof( struct V_119 ) ) ;
V_59 -> V_120 [ 2 ] = V_121 ;
V_59 -> V_120 [ 3 ] = 1 ;
V_59 -> V_120 [ 4 ] = V_82 ;
V_59 -> V_120 [ 5 ] = V_122 ;
V_59 -> V_120 [ 6 ] = 1 ;
V_59 -> V_123 . V_124 = (struct V_125 * ) V_59 -> V_120 ;
V_59 -> V_123 . V_126 = 8 ;
}
static T_9 F_60 ( struct V_56 * V_57 ,
struct V_6 * V_7 ,
T_8 V_127 ,
struct V_128 * V_129 ,
int V_82 ,
T_6 * V_130 )
{
struct V_5 * V_91 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_91 -> V_12 ;
struct V_6 * V_131 ;
struct V_63 * V_64 ;
unsigned int V_132 = 0 ;
int V_133 ;
struct V_119 V_59 ;
int V_76 ;
struct V_134 * V_135 = NULL , * V_136 = NULL ;
struct V_137 * V_97 = & V_91 -> V_7 -> V_97 ;
int V_92 = - 1 ;
T_5 V_138 ;
struct V_56 * V_139 ;
T_3 V_99 ;
if ( V_7 -> type == V_24 )
F_61 ( V_57 ) -> V_32 = 0 ;
if ( V_7 -> V_140 && V_7 -> type == V_25 ) {
V_133 = 0 ;
V_64 = (struct V_63 * ) V_57 -> V_65 ;
V_129 -> V_71 = V_64 -> V_71 ;
} else {
V_133 = V_91 -> V_141 ;
V_129 -> V_71 = V_91 -> V_28 . V_30 ;
}
if ( ! V_129 -> V_142 )
V_135 = F_62 ( V_91 ) ;
if ( ! V_135 ) {
V_136 = F_63 ( V_12 , NULL , V_129 ) ;
if ( V_136 -> error )
goto V_143;
V_136 = F_64 ( V_12 , V_136 , F_65 ( V_129 ) , NULL , 0 ) ;
if ( F_66 ( V_136 ) ) {
V_92 = F_67 ( V_136 ) ;
V_136 = NULL ;
goto V_143;
}
V_135 = V_136 ;
}
V_131 = V_135 -> V_7 ;
if ( V_131 == V_7 ) {
V_97 -> V_144 ++ ;
F_33 ( L_7 ,
V_91 -> V_28 . V_45 ) ;
goto V_145;
}
V_76 = F_68 ( V_135 ) - sizeof( * V_64 ) ;
if ( V_82 >= 0 ) {
V_132 += 8 ;
V_76 -= 8 ;
}
if ( V_76 < V_84 )
V_76 = V_84 ;
if ( F_69 ( V_57 ) )
F_69 ( V_57 ) -> V_123 -> V_146 ( F_69 ( V_57 ) , NULL , V_57 , V_76 ) ;
if ( V_57 -> V_117 > V_76 ) {
* V_130 = V_76 ;
V_92 = - V_147 ;
goto V_145;
}
if ( V_91 -> V_88 > 0 ) {
if ( F_35 ( V_85 ,
V_91 -> V_86 + V_87 ) ) {
V_91 -> V_88 -- ;
F_70 ( V_57 ) ;
} else
V_91 -> V_88 = 0 ;
}
F_71 ( V_57 , ! F_72 ( V_91 -> V_12 , F_5 ( V_7 ) ) ) ;
V_132 += F_73 ( V_131 ) + V_133 + V_135 -> V_148 ;
if ( F_74 ( V_57 ) < V_132 || F_75 ( V_57 ) ||
( F_76 ( V_57 ) && ! F_77 ( V_57 , 0 ) ) ) {
V_139 = F_78 ( V_57 , V_132 ) ;
if ( V_132 > V_7 -> V_149 )
V_7 -> V_149 = V_132 ;
if ( ! V_139 )
goto V_145;
if ( V_57 -> V_150 )
F_79 ( V_139 , V_57 -> V_150 ) ;
F_80 ( V_57 ) ;
V_57 = V_139 ;
}
if ( V_129 -> V_142 ) {
F_81 ( V_57 , V_135 ) ;
V_136 = NULL ;
} else {
F_82 ( V_57 , V_135 ) ;
}
V_138 = V_151 ;
if ( V_82 >= 0 ) {
F_59 ( & V_59 , V_82 ) ;
F_83 ( V_57 , & V_59 . V_123 , & V_138 , NULL ) ;
}
if ( F_84 ( ! V_57 -> V_152 ) ) {
F_85 ( V_57 ) ;
V_57 -> V_152 = 1 ;
}
F_86 ( V_57 , V_133 ) ;
F_48 ( V_57 ) ;
F_87 ( V_57 , sizeof( * V_64 ) ) ;
V_64 = F_37 ( V_57 ) ;
F_88 ( V_64 , F_89 ( 0 , V_127 ) ,
F_90 ( V_12 , V_57 , V_129 -> V_153 , false ) ) ;
V_64 -> V_154 = V_91 -> V_28 . V_154 ;
V_64 -> V_155 = V_138 ;
V_64 -> V_72 = V_129 -> V_72 ;
V_64 -> V_71 = V_129 -> V_71 ;
( ( T_3 * ) ( V_64 + 1 ) ) [ 0 ] = V_91 -> V_28 . V_52 ;
V_99 = ( V_7 -> type == V_24 ) ?
F_8 ( V_23 ) : V_57 -> V_99 ;
( ( T_3 * ) ( V_64 + 1 ) ) [ 1 ] = V_99 ;
if ( V_91 -> V_28 . V_52 & ( V_68 | V_67 | V_53 ) ) {
T_2 * V_156 = ( T_2 * ) ( ( ( T_5 * ) V_64 ) + V_91 -> V_141 - 4 ) ;
if ( V_91 -> V_28 . V_52 & V_53 ) {
++ V_91 -> V_157 ;
* V_156 = F_91 ( V_91 -> V_157 ) ;
V_156 -- ;
}
if ( V_91 -> V_28 . V_52 & V_68 ) {
* V_156 = V_91 -> V_28 . V_158 ;
V_156 -- ;
}
if ( V_91 -> V_28 . V_52 & V_67 ) {
* V_156 = 0 ;
* ( T_7 * ) V_156 = F_92 ( ( void * ) ( V_64 + 1 ) ,
V_57 -> V_117 - sizeof( struct V_63 ) ) ;
}
}
F_93 ( V_57 , V_99 ) ;
F_94 ( V_57 , V_7 ) ;
if ( V_136 )
F_95 ( V_91 , V_136 ) ;
return 0 ;
V_143:
V_97 -> V_159 ++ ;
F_70 ( V_57 ) ;
V_145:
F_96 ( V_136 ) ;
return V_92 ;
}
static inline int F_97 ( struct V_56 * V_57 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
const struct V_160 * V_161 = F_98 ( V_57 ) ;
int V_82 = - 1 ;
struct V_128 V_129 ;
T_8 V_127 ;
T_6 V_76 ;
int V_92 ;
if ( ! ( V_17 -> V_28 . V_32 & V_162 ) )
V_82 = V_17 -> V_28 . V_82 ;
memcpy ( & V_129 , & V_17 -> V_163 . V_164 . V_165 , sizeof( V_129 ) ) ;
V_129 . V_166 = V_167 ;
V_127 = F_99 ( V_161 ) ;
if ( V_17 -> V_28 . V_32 & V_168 )
V_129 . V_153 |= F_91 ( ( T_6 ) V_161 -> V_169 << V_170 )
& V_171 ;
if ( V_17 -> V_28 . V_32 & V_172 )
V_129 . V_142 = V_57 -> V_173 ;
V_92 = F_60 ( V_57 , V_7 , V_127 , & V_129 , V_82 , & V_76 ) ;
if ( V_92 != 0 ) {
if ( V_92 == - V_147 )
F_100 ( V_57 , V_174 , V_175 ,
F_91 ( V_76 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_101 ( struct V_56 * V_57 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_63 * V_64 = F_37 ( V_57 ) ;
int V_82 = - 1 ;
T_10 V_61 ;
struct V_128 V_129 ;
T_8 V_127 ;
T_6 V_76 ;
int V_92 ;
if ( F_10 ( & V_17 -> V_28 . V_30 , & V_64 -> V_72 ) )
return - 1 ;
V_61 = F_34 ( V_57 , F_102 ( V_57 ) ) ;
if ( V_61 > 0 ) {
struct V_74 * V_75 ;
V_75 = (struct V_74 * ) & F_102 ( V_57 ) [ V_61 ] ;
if ( V_75 -> V_82 == 0 ) {
F_57 ( V_57 , V_80 ,
V_81 , V_61 + 2 ) ;
return - 1 ;
}
V_82 = V_75 -> V_82 - 1 ;
} else if ( ! ( V_17 -> V_28 . V_32 & V_162 ) )
V_82 = V_17 -> V_28 . V_82 ;
memcpy ( & V_129 , & V_17 -> V_163 . V_164 . V_165 , sizeof( V_129 ) ) ;
V_129 . V_166 = V_167 ;
V_127 = F_52 ( V_64 ) ;
if ( V_17 -> V_28 . V_32 & V_168 )
V_129 . V_153 |= ( * ( T_2 * ) V_64 & V_171 ) ;
if ( V_17 -> V_28 . V_32 & V_176 )
V_129 . V_153 |= F_103 ( V_64 ) ;
if ( V_17 -> V_28 . V_32 & V_172 )
V_129 . V_142 = V_57 -> V_173 ;
V_92 = F_60 ( V_57 , V_7 , V_127 , & V_129 , V_82 , & V_76 ) ;
if ( V_92 != 0 ) {
if ( V_92 == - V_147 )
F_57 ( V_57 , V_83 , 0 , V_76 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_104 ( const struct V_5 * V_17 ,
const struct V_63 * V_177 )
{
return F_10 ( & V_17 -> V_28 . V_30 , & V_177 -> V_72 ) ;
}
static int F_105 ( struct V_56 * V_57 , struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
int V_82 = - 1 ;
struct V_128 V_129 ;
T_6 V_76 ;
int V_92 ;
if ( ! ( V_17 -> V_28 . V_32 & V_162 ) )
V_82 = V_17 -> V_28 . V_82 ;
memcpy ( & V_129 , & V_17 -> V_163 . V_164 . V_165 , sizeof( V_129 ) ) ;
V_129 . V_166 = V_57 -> V_99 ;
V_92 = F_60 ( V_57 , V_7 , 0 , & V_129 , V_82 , & V_76 ) ;
return V_92 ;
}
static T_9 F_106 ( struct V_56 * V_57 ,
struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_137 * V_97 = & V_17 -> V_7 -> V_97 ;
int V_178 ;
if ( ! F_107 ( V_17 ) )
goto V_179;
switch ( V_57 -> V_99 ) {
case F_8 ( V_180 ) :
V_178 = F_97 ( V_57 , V_7 ) ;
break;
case F_8 ( V_101 ) :
V_178 = F_101 ( V_57 , V_7 ) ;
break;
default:
V_178 = F_105 ( V_57 , V_7 ) ;
break;
}
if ( V_178 < 0 )
goto V_179;
return V_181 ;
V_179:
V_97 -> V_182 ++ ;
V_97 -> V_183 ++ ;
F_58 ( V_57 ) ;
return V_181 ;
}
static void F_25 ( struct V_5 * V_17 , int V_184 )
{
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_35 * V_36 = & V_17 -> V_28 ;
struct V_128 * V_129 = & V_17 -> V_163 . V_164 . V_165 ;
int V_185 = sizeof( struct V_63 ) + 4 ;
if ( V_7 -> type != V_24 ) {
memcpy ( V_7 -> V_186 , & V_36 -> V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_187 , & V_36 -> V_30 , sizeof( struct V_1 ) ) ;
}
V_129 -> V_72 = V_36 -> V_29 ;
V_129 -> V_71 = V_36 -> V_30 ;
V_129 -> V_188 = V_36 -> V_13 ;
V_129 -> V_153 = 0 ;
if ( ! ( V_36 -> V_32 & V_168 ) )
V_129 -> V_153 |= V_171 & V_36 -> V_189 ;
if ( ! ( V_36 -> V_32 & V_176 ) )
V_129 -> V_153 |= V_190 & V_36 -> V_189 ;
V_36 -> V_32 &= ~ ( V_191 | V_192 | V_193 ) ;
V_36 -> V_32 |= F_108 ( V_17 , & V_36 -> V_29 , & V_36 -> V_30 ) ;
if ( V_36 -> V_32 & V_191 &&
V_36 -> V_32 & V_192 && V_7 -> type != V_24 )
V_7 -> V_32 |= V_194 ;
else
V_7 -> V_32 &= ~ V_194 ;
if ( V_17 -> V_28 . V_52 & ( V_67 | V_68 | V_53 ) ) {
if ( V_17 -> V_28 . V_52 & V_67 )
V_185 += 4 ;
if ( V_17 -> V_28 . V_52 & V_68 )
V_185 += 4 ;
if ( V_17 -> V_28 . V_52 & V_53 )
V_185 += 4 ;
}
V_17 -> V_141 = V_185 ;
if ( V_36 -> V_32 & V_191 ) {
int V_195 = ( F_109 ( & V_36 -> V_30 ) &
( V_196 | V_197 ) ) ;
struct V_198 * V_199 = F_110 ( V_17 -> V_12 ,
& V_36 -> V_30 , & V_36 -> V_29 ,
V_36 -> V_13 , V_195 ) ;
if ( V_199 == NULL )
return;
if ( V_199 -> V_135 . V_7 ) {
V_7 -> V_200 = V_199 -> V_135 . V_7 -> V_200 + V_185 ;
if ( V_184 ) {
V_7 -> V_76 = V_199 -> V_135 . V_7 -> V_76 - V_185 ;
if ( ! ( V_17 -> V_28 . V_32 & V_162 ) )
V_7 -> V_76 -= 8 ;
if ( V_7 -> V_76 < V_84 )
V_7 -> V_76 = V_84 ;
}
}
F_111 ( V_199 ) ;
}
}
static int F_112 ( struct V_5 * V_17 ,
const struct V_35 * V_36 , int V_184 )
{
V_17 -> V_28 . V_29 = V_36 -> V_29 ;
V_17 -> V_28 . V_30 = V_36 -> V_30 ;
V_17 -> V_28 . V_32 = V_36 -> V_32 ;
V_17 -> V_28 . V_154 = V_36 -> V_154 ;
V_17 -> V_28 . V_82 = V_36 -> V_82 ;
V_17 -> V_28 . V_189 = V_36 -> V_189 ;
V_17 -> V_28 . V_13 = V_36 -> V_13 ;
V_17 -> V_28 . V_138 = V_36 -> V_138 ;
V_17 -> V_28 . V_31 = V_36 -> V_31 ;
V_17 -> V_28 . V_158 = V_36 -> V_158 ;
V_17 -> V_28 . V_104 = V_36 -> V_104 ;
V_17 -> V_28 . V_52 = V_36 -> V_52 ;
F_113 ( V_17 ) ;
F_25 ( V_17 , V_184 ) ;
return 0 ;
}
static void F_114 ( struct V_35 * V_36 ,
const struct V_201 * V_164 )
{
V_36 -> V_29 = V_164 -> V_29 ;
V_36 -> V_30 = V_164 -> V_30 ;
V_36 -> V_32 = V_164 -> V_32 ;
V_36 -> V_154 = V_164 -> V_154 ;
V_36 -> V_82 = V_164 -> V_82 ;
V_36 -> V_189 = V_164 -> V_189 ;
V_36 -> V_13 = V_164 -> V_13 ;
V_36 -> V_31 = V_164 -> V_31 ;
V_36 -> V_158 = V_164 -> V_158 ;
V_36 -> V_104 = V_164 -> V_104 ;
V_36 -> V_52 = V_164 -> V_52 ;
memcpy ( V_36 -> V_45 , V_164 -> V_45 , sizeof( V_164 -> V_45 ) ) ;
}
static void F_115 ( struct V_201 * V_164 ,
const struct V_35 * V_36 )
{
V_164 -> V_138 = V_167 ;
V_164 -> V_29 = V_36 -> V_29 ;
V_164 -> V_30 = V_36 -> V_30 ;
V_164 -> V_32 = V_36 -> V_32 ;
V_164 -> V_154 = V_36 -> V_154 ;
V_164 -> V_82 = V_36 -> V_82 ;
V_164 -> V_189 = V_36 -> V_189 ;
V_164 -> V_13 = V_36 -> V_13 ;
V_164 -> V_31 = V_36 -> V_31 ;
V_164 -> V_158 = V_36 -> V_158 ;
V_164 -> V_104 = V_36 -> V_104 ;
V_164 -> V_52 = V_36 -> V_52 ;
memcpy ( V_164 -> V_45 , V_36 -> V_45 , sizeof( V_164 -> V_45 ) ) ;
}
static int F_116 ( struct V_6 * V_7 ,
struct V_202 * V_203 , int V_204 )
{
int V_92 = 0 ;
struct V_201 V_36 ;
struct V_35 V_205 ;
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_17 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
switch ( V_204 ) {
case V_206 :
if ( V_7 == V_20 -> V_34 ) {
if ( F_117 ( & V_36 , V_203 -> V_207 . V_208 , sizeof( V_36 ) ) ) {
V_92 = - V_209 ;
break;
}
F_114 ( & V_205 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_205 , 0 ) ;
if ( V_17 == NULL )
V_17 = F_12 ( V_7 ) ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_115 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_118 ( V_203 -> V_207 . V_208 , & V_36 , sizeof( V_36 ) ) )
V_92 = - V_209 ;
break;
case V_210 :
case V_211 :
V_92 = - V_212 ;
if ( ! F_119 ( V_12 -> V_213 , V_214 ) )
goto V_215;
V_92 = - V_209 ;
if ( F_117 ( & V_36 , V_203 -> V_207 . V_208 , sizeof( V_36 ) ) )
goto V_215;
V_92 = - V_216 ;
if ( ( V_36 . V_104 | V_36 . V_52 ) & ( V_70 | V_69 ) )
goto V_215;
if ( ! ( V_36 . V_104 & V_68 ) )
V_36 . V_31 = 0 ;
if ( ! ( V_36 . V_52 & V_68 ) )
V_36 . V_158 = 0 ;
F_114 ( & V_205 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_205 , V_204 == V_210 ) ;
if ( V_7 != V_20 -> V_34 && V_204 == V_211 ) {
if ( V_17 != NULL ) {
if ( V_17 -> V_7 != V_7 ) {
V_92 = - V_217 ;
break;
}
} else {
V_17 = F_12 ( V_7 ) ;
F_19 ( V_20 , V_17 ) ;
F_120 () ;
F_112 ( V_17 , & V_205 , 1 ) ;
F_16 ( V_20 , V_17 ) ;
F_121 ( V_7 ) ;
}
}
if ( V_17 ) {
V_92 = 0 ;
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_115 ( & V_36 , & V_17 -> V_28 ) ;
if ( F_118 ( V_203 -> V_207 . V_208 , & V_36 , sizeof( V_36 ) ) )
V_92 = - V_209 ;
} else
V_92 = ( V_204 == V_210 ? - V_218 : - V_219 ) ;
break;
case V_220 :
V_92 = - V_212 ;
if ( ! F_119 ( V_12 -> V_213 , V_214 ) )
goto V_215;
if ( V_7 == V_20 -> V_34 ) {
V_92 = - V_209 ;
if ( F_117 ( & V_36 , V_203 -> V_207 . V_208 , sizeof( V_36 ) ) )
goto V_215;
V_92 = - V_219 ;
F_114 ( & V_205 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_205 , 0 ) ;
if ( V_17 == NULL )
goto V_215;
V_92 = - V_212 ;
if ( V_17 == F_12 ( V_20 -> V_34 ) )
goto V_215;
V_7 = V_17 -> V_7 ;
}
F_122 ( V_7 ) ;
V_92 = 0 ;
break;
default:
V_92 = - V_216 ;
}
V_215:
return V_92 ;
}
static int F_123 ( struct V_6 * V_7 , int V_221 )
{
if ( V_221 < 68 ||
V_221 > 0xFFF8 - V_7 -> V_200 )
return - V_216 ;
V_7 -> V_76 = V_221 ;
return 0 ;
}
static int F_124 ( struct V_56 * V_57 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_71 , const void * V_72 , unsigned int V_117 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_63 * V_64 = (struct V_63 * ) F_86 ( V_57 , V_17 -> V_141 ) ;
T_3 * V_36 = ( T_3 * ) ( V_64 + 1 ) ;
F_88 ( V_64 , 0 ,
F_90 ( F_5 ( V_7 ) , V_57 ,
V_17 -> V_163 . V_164 . V_165 . V_153 , false ) ) ;
V_64 -> V_154 = V_17 -> V_28 . V_154 ;
V_64 -> V_155 = V_151 ;
V_64 -> V_72 = V_17 -> V_28 . V_29 ;
V_64 -> V_71 = V_17 -> V_28 . V_30 ;
V_36 [ 0 ] = V_17 -> V_28 . V_52 ;
V_36 [ 1 ] = F_8 ( type ) ;
if ( V_72 )
memcpy ( & V_64 -> V_72 , V_72 , sizeof( struct V_1 ) ) ;
if ( V_71 )
memcpy ( & V_64 -> V_71 , V_71 , sizeof( struct V_1 ) ) ;
if ( ! F_14 ( & V_64 -> V_71 ) )
return V_17 -> V_141 ;
return - V_17 -> V_141 ;
}
static void F_125 ( struct V_6 * V_7 )
{
F_126 ( V_7 -> V_95 ) ;
F_28 ( V_7 ) ;
}
static void V_48 ( struct V_6 * V_7 )
{
struct V_5 * V_17 ;
V_7 -> V_222 = & V_223 ;
V_7 -> V_224 = F_125 ;
V_7 -> type = V_25 ;
V_7 -> V_200 = V_225 + sizeof( struct V_63 ) + 4 ;
V_7 -> V_76 = V_226 - sizeof( struct V_63 ) - 4 ;
V_17 = F_12 ( V_7 ) ;
if ( ! ( V_17 -> V_28 . V_32 & V_162 ) )
V_7 -> V_76 -= 8 ;
V_7 -> V_32 |= V_227 ;
V_7 -> V_228 = 0 ;
V_7 -> V_229 = sizeof( struct V_1 ) ;
F_127 ( V_7 ) ;
}
static int F_128 ( struct V_6 * V_7 )
{
struct V_5 * V_91 ;
int V_230 ;
V_91 = F_12 ( V_7 ) ;
V_91 -> V_7 = V_7 ;
V_91 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_91 -> V_28 . V_45 , V_7 -> V_45 ) ;
memcpy ( V_7 -> V_186 , & V_91 -> V_28 . V_29 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_187 , & V_91 -> V_28 . V_30 , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_91 -> V_28 . V_30 ) )
V_7 -> V_140 = & V_231 ;
V_7 -> V_95 = F_129 ( struct V_94 ) ;
if ( ! V_7 -> V_95 )
return - V_232 ;
F_130 (i) {
struct V_94 * V_233 ;
V_233 = F_131 ( V_7 -> V_95 , V_230 ) ;
F_132 ( & V_233 -> V_114 ) ;
}
V_7 -> V_228 = V_91 -> V_28 . V_13 ;
return 0 ;
}
static void F_133 ( struct V_6 * V_7 )
{
struct V_5 * V_91 = F_12 ( V_7 ) ;
V_91 -> V_7 = V_7 ;
V_91 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_91 -> V_28 . V_45 , V_7 -> V_45 ) ;
V_91 -> V_141 = sizeof( struct V_63 ) + 4 ;
F_27 ( V_7 ) ;
}
static void F_134 ( struct V_12 * V_12 , struct V_234 * V_235 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_6 * V_7 , * V_236 ;
int V_38 ;
F_135 (net, dev, aux)
if ( V_7 -> V_49 == & V_50 ||
V_7 -> V_49 == & V_237 )
F_136 ( V_7 , V_235 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
int V_37 ;
for ( V_37 = 0 ; V_37 < V_238 ; V_37 ++ ) {
struct V_5 * V_17 ;
V_17 = F_18 ( V_20 -> V_39 [ V_38 ] [ V_37 ] ) ;
while ( V_17 != NULL ) {
if ( ! F_72 ( F_5 ( V_17 -> V_7 ) , V_12 ) )
F_136 ( V_17 -> V_7 ,
V_235 ) ;
V_17 = F_18 ( V_17 -> V_41 ) ;
}
}
}
}
static int T_11 F_137 ( struct V_12 * V_12 )
{
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_92 ;
V_20 -> V_34 = F_23 ( sizeof( struct V_5 ) , L_8 ,
V_47 ,
V_48 ) ;
if ( ! V_20 -> V_34 ) {
V_92 = - V_232 ;
goto V_239;
}
F_24 ( V_20 -> V_34 , V_12 ) ;
V_20 -> V_34 -> V_54 |= V_240 ;
F_133 ( V_20 -> V_34 ) ;
V_20 -> V_34 -> V_49 = & V_50 ;
V_92 = F_138 ( V_20 -> V_34 ) ;
if ( V_92 )
goto V_241;
F_17 ( V_20 -> V_242 [ 0 ] ,
F_12 ( V_20 -> V_34 ) ) ;
return 0 ;
V_241:
F_125 ( V_20 -> V_34 ) ;
V_239:
return V_92 ;
}
static void T_12 F_139 ( struct V_12 * V_12 )
{
F_140 ( V_243 ) ;
F_141 () ;
F_134 ( V_12 , & V_243 ) ;
F_142 ( & V_243 ) ;
F_143 () ;
}
static int F_144 ( struct V_244 * V_245 [] , struct V_244 * V_65 [] )
{
T_3 V_32 ;
if ( ! V_65 )
return 0 ;
V_32 = 0 ;
if ( V_65 [ V_246 ] )
V_32 |= F_145 ( V_65 [ V_246 ] ) ;
if ( V_65 [ V_247 ] )
V_32 |= F_145 ( V_65 [ V_247 ] ) ;
if ( V_32 & ( V_70 | V_69 ) )
return - V_216 ;
return 0 ;
}
static int F_146 ( struct V_244 * V_245 [] , struct V_244 * V_65 [] )
{
struct V_1 V_71 ;
if ( V_245 [ V_248 ] ) {
if ( F_147 ( V_245 [ V_248 ] ) != V_249 )
return - V_216 ;
if ( ! F_148 ( F_149 ( V_245 [ V_248 ] ) ) )
return - V_250 ;
}
if ( ! V_65 )
goto V_251;
if ( V_65 [ V_252 ] ) {
F_150 ( & V_71 , V_65 [ V_252 ] , sizeof( struct V_1 ) ) ;
if ( F_14 ( & V_71 ) )
return - V_216 ;
}
V_251:
return F_144 ( V_245 , V_65 ) ;
}
static void F_151 ( struct V_244 * V_65 [] ,
struct V_35 * V_28 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
if ( ! V_65 )
return;
if ( V_65 [ V_253 ] )
V_28 -> V_13 = F_152 ( V_65 [ V_253 ] ) ;
if ( V_65 [ V_246 ] )
V_28 -> V_104 = F_145 ( V_65 [ V_246 ] ) ;
if ( V_65 [ V_247 ] )
V_28 -> V_52 = F_145 ( V_65 [ V_247 ] ) ;
if ( V_65 [ V_254 ] )
V_28 -> V_31 = F_153 ( V_65 [ V_254 ] ) ;
if ( V_65 [ V_255 ] )
V_28 -> V_158 = F_153 ( V_65 [ V_255 ] ) ;
if ( V_65 [ V_256 ] )
F_150 ( & V_28 -> V_29 , V_65 [ V_256 ] , sizeof( struct V_1 ) ) ;
if ( V_65 [ V_252 ] )
F_150 ( & V_28 -> V_30 , V_65 [ V_252 ] , sizeof( struct V_1 ) ) ;
if ( V_65 [ V_257 ] )
V_28 -> V_154 = F_154 ( V_65 [ V_257 ] ) ;
if ( V_65 [ V_258 ] )
V_28 -> V_82 = F_154 ( V_65 [ V_258 ] ) ;
if ( V_65 [ V_259 ] )
V_28 -> V_189 = F_152 ( V_65 [ V_259 ] ) ;
if ( V_65 [ V_260 ] )
V_28 -> V_32 = F_152 ( V_65 [ V_260 ] ) ;
}
static int F_155 ( struct V_6 * V_7 )
{
struct V_5 * V_91 ;
V_91 = F_12 ( V_7 ) ;
V_91 -> V_7 = V_7 ;
V_91 -> V_12 = F_5 ( V_7 ) ;
strcpy ( V_91 -> V_28 . V_45 , V_7 -> V_45 ) ;
F_25 ( V_91 , 1 ) ;
V_7 -> V_95 = F_156 ( struct V_94 ) ;
if ( ! V_7 -> V_95 )
return - V_232 ;
V_7 -> V_228 = V_91 -> V_28 . V_13 ;
return 0 ;
}
static void F_157 ( struct V_6 * V_7 )
{
F_158 ( V_7 ) ;
V_7 -> V_222 = & V_261 ;
V_7 -> V_224 = F_125 ;
V_7 -> V_228 = 0 ;
V_7 -> V_54 |= V_240 ;
}
static int F_159 ( struct V_12 * V_262 , struct V_6 * V_7 ,
struct V_244 * V_245 [] , struct V_244 * V_65 [] )
{
struct V_5 * V_44 ;
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
int V_92 ;
V_44 = F_12 ( V_7 ) ;
F_151 ( V_65 , & V_44 -> V_28 ) ;
if ( F_20 ( V_12 , & V_44 -> V_28 , V_7 -> type ) )
return - V_217 ;
if ( V_7 -> type == V_24 && ! V_245 [ V_248 ] )
F_160 ( V_7 ) ;
V_44 -> V_7 = V_7 ;
V_44 -> V_12 = F_5 ( V_7 ) ;
F_25 ( V_44 , ! V_245 [ V_263 ] ) ;
if ( ! ( V_44 -> V_28 . V_52 & V_53 ) )
V_7 -> V_54 |= V_55 ;
V_92 = F_26 ( V_7 ) ;
if ( V_92 )
goto V_251;
F_27 ( V_7 ) ;
F_16 ( V_20 , V_44 ) ;
V_251:
return V_92 ;
}
static int F_161 ( struct V_6 * V_7 , struct V_244 * V_245 [] ,
struct V_244 * V_65 [] )
{
struct V_5 * V_17 , * V_44 = F_12 ( V_7 ) ;
struct V_12 * V_12 = V_44 -> V_12 ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
struct V_35 V_36 ;
if ( V_7 == V_20 -> V_34 )
return - V_216 ;
F_151 ( V_65 , & V_36 ) ;
V_17 = F_21 ( V_12 , & V_36 , 0 ) ;
if ( V_17 ) {
if ( V_17 -> V_7 != V_7 )
return - V_217 ;
} else {
V_17 = V_44 ;
F_19 ( V_20 , V_17 ) ;
F_112 ( V_17 , & V_36 , ! V_245 [ V_263 ] ) ;
F_16 ( V_20 , V_17 ) ;
F_121 ( V_7 ) ;
}
return 0 ;
}
static void F_162 ( struct V_6 * V_7 , struct V_234 * V_235 )
{
struct V_12 * V_12 = F_5 ( V_7 ) ;
struct V_19 * V_20 = F_7 ( V_12 , V_21 ) ;
if ( V_7 != V_20 -> V_34 )
F_136 ( V_7 , V_235 ) ;
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
static int F_165 ( struct V_56 * V_57 , const struct V_6 * V_7 )
{
struct V_5 * V_17 = F_12 ( V_7 ) ;
struct V_35 * V_36 = & V_17 -> V_28 ;
if ( F_166 ( V_57 , V_253 , V_36 -> V_13 ) ||
F_167 ( V_57 , V_246 , V_36 -> V_104 ) ||
F_167 ( V_57 , V_247 , V_36 -> V_52 ) ||
F_168 ( V_57 , V_254 , V_36 -> V_31 ) ||
F_168 ( V_57 , V_255 , V_36 -> V_158 ) ||
F_169 ( V_57 , V_256 , sizeof( struct V_1 ) , & V_36 -> V_29 ) ||
F_169 ( V_57 , V_252 , sizeof( struct V_1 ) , & V_36 -> V_30 ) ||
F_170 ( V_57 , V_257 , V_36 -> V_154 ) ||
F_170 ( V_57 , V_258 , V_36 -> V_82 ) ||
F_168 ( V_57 , V_259 , V_36 -> V_189 ) ||
F_166 ( V_57 , V_260 , V_36 -> V_32 ) )
goto V_264;
return 0 ;
V_264:
return - V_147 ;
}
static int T_14 F_171 ( void )
{
int V_92 ;
F_172 ( L_9 ) ;
V_92 = F_173 ( & V_265 ) ;
if ( V_92 < 0 )
return V_92 ;
V_92 = F_174 ( & V_266 , V_167 ) ;
if ( V_92 < 0 ) {
F_172 ( L_10 , V_267 ) ;
goto V_268;
}
V_92 = F_175 ( & V_50 ) ;
if ( V_92 < 0 )
goto V_269;
V_92 = F_175 ( & V_237 ) ;
if ( V_92 < 0 )
goto V_270;
V_251:
return V_92 ;
V_270:
F_176 ( & V_50 ) ;
V_269:
F_177 ( & V_266 , V_167 ) ;
V_268:
F_178 ( & V_265 ) ;
goto V_251;
}
static void T_15 F_179 ( void )
{
F_176 ( & V_237 ) ;
F_176 ( & V_50 ) ;
F_177 ( & V_266 , V_167 ) ;
F_178 ( & V_265 ) ;
}
