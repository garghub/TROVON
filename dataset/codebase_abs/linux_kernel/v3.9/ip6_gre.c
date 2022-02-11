static T_1 F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
return F_3 ( V_3 , V_4 ) ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 ,
struct V_5 * V_8 )
{
int V_9 ;
F_5 (i) {
const struct V_10 * V_11 = F_6 ( V_7 -> V_11 , V_9 ) ;
T_2 V_12 , V_13 , V_14 , V_15 ;
unsigned int V_16 ;
do {
V_16 = F_7 ( & V_11 -> V_17 ) ;
V_12 = V_11 -> V_12 ;
V_14 = V_11 -> V_14 ;
V_13 = V_11 -> V_13 ;
V_15 = V_11 -> V_15 ;
} while ( F_8 ( & V_11 -> V_17 , V_16 ) );
V_8 -> V_12 += V_12 ;
V_8 -> V_14 += V_14 ;
V_8 -> V_13 += V_13 ;
V_8 -> V_15 += V_15 ;
}
V_8 -> V_18 = V_7 -> V_19 . V_18 ;
V_8 -> V_20 = V_7 -> V_19 . V_20 ;
V_8 -> V_21 = V_7 -> V_19 . V_21 ;
V_8 -> V_22 = V_7 -> V_19 . V_22 ;
V_8 -> V_23 = V_7 -> V_19 . V_23 ;
V_8 -> V_24 = V_7 -> V_19 . V_24 ;
V_8 -> V_25 = V_7 -> V_19 . V_25 ;
V_8 -> V_26 = V_7 -> V_19 . V_26 ;
V_8 -> V_27 = V_7 -> V_19 . V_27 ;
V_8 -> V_28 = V_7 -> V_19 . V_28 ;
V_8 -> V_29 = V_7 -> V_19 . V_29 ;
return V_8 ;
}
static struct V_30 * F_9 ( struct V_6 * V_7 ,
const struct V_1 * V_31 , const struct V_1 * V_32 ,
T_3 V_33 , T_4 V_34 )
{
struct V_35 * V_35 = F_10 ( V_7 ) ;
int V_36 = V_7 -> V_37 ;
unsigned int V_38 = F_1 ( V_31 ) ;
unsigned int V_39 = F_11 ( V_33 ) ;
struct V_30 * V_40 , * V_41 = NULL ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
int V_45 = ( V_34 == F_13 ( V_46 ) ) ?
V_47 : V_48 ;
int V_49 , V_50 = 4 ;
F_14 (t, ign->tunnels_r_l[h0 ^ h1]) {
if ( ! F_15 ( V_32 , & V_40 -> V_51 . V_52 ) ||
! F_15 ( V_31 , & V_40 -> V_51 . V_53 ) ||
V_33 != V_40 -> V_51 . V_54 ||
! ( V_40 -> V_7 -> V_55 & V_56 ) )
continue;
if ( V_40 -> V_7 -> type != V_48 &&
V_40 -> V_7 -> type != V_45 )
continue;
V_49 = 0 ;
if ( V_40 -> V_51 . V_36 != V_36 )
V_49 |= 1 ;
if ( V_40 -> V_7 -> type != V_45 )
V_49 |= 2 ;
if ( V_49 == 0 )
return V_40 ;
if ( V_49 < V_50 ) {
V_41 = V_40 ;
V_50 = V_49 ;
}
}
F_14 (t, ign->tunnels_r[h0 ^ h1]) {
if ( ! F_15 ( V_31 , & V_40 -> V_51 . V_53 ) ||
V_33 != V_40 -> V_51 . V_54 ||
! ( V_40 -> V_7 -> V_55 & V_56 ) )
continue;
if ( V_40 -> V_7 -> type != V_48 &&
V_40 -> V_7 -> type != V_45 )
continue;
V_49 = 0 ;
if ( V_40 -> V_51 . V_36 != V_36 )
V_49 |= 1 ;
if ( V_40 -> V_7 -> type != V_45 )
V_49 |= 2 ;
if ( V_49 == 0 )
return V_40 ;
if ( V_49 < V_50 ) {
V_41 = V_40 ;
V_50 = V_49 ;
}
}
F_14 (t, ign->tunnels_l[h1]) {
if ( ( ! F_15 ( V_32 , & V_40 -> V_51 . V_52 ) &&
( ! F_15 ( V_32 , & V_40 -> V_51 . V_53 ) ||
! F_16 ( V_32 ) ) ) ||
V_33 != V_40 -> V_51 . V_54 ||
! ( V_40 -> V_7 -> V_55 & V_56 ) )
continue;
if ( V_40 -> V_7 -> type != V_48 &&
V_40 -> V_7 -> type != V_45 )
continue;
V_49 = 0 ;
if ( V_40 -> V_51 . V_36 != V_36 )
V_49 |= 1 ;
if ( V_40 -> V_7 -> type != V_45 )
V_49 |= 2 ;
if ( V_49 == 0 )
return V_40 ;
if ( V_49 < V_50 ) {
V_41 = V_40 ;
V_50 = V_49 ;
}
}
F_14 (t, ign->tunnels_wc[h1]) {
if ( V_40 -> V_51 . V_54 != V_33 ||
! ( V_40 -> V_7 -> V_55 & V_56 ) )
continue;
if ( V_40 -> V_7 -> type != V_48 &&
V_40 -> V_7 -> type != V_45 )
continue;
V_49 = 0 ;
if ( V_40 -> V_51 . V_36 != V_36 )
V_49 |= 1 ;
if ( V_40 -> V_7 -> type != V_45 )
V_49 |= 2 ;
if ( V_49 == 0 )
return V_40 ;
if ( V_49 < V_50 ) {
V_41 = V_40 ;
V_50 = V_49 ;
}
}
if ( V_41 != NULL )
return V_41 ;
V_7 = V_43 -> V_57 ;
if ( V_7 -> V_55 & V_56 )
return F_17 ( V_7 ) ;
return NULL ;
}
static struct V_30 T_5 * * F_18 ( struct V_42 * V_43 ,
const struct V_58 * V_59 )
{
const struct V_1 * V_31 = & V_59 -> V_53 ;
const struct V_1 * V_32 = & V_59 -> V_52 ;
unsigned int V_60 = F_11 ( V_59 -> V_54 ) ;
int V_61 = 0 ;
if ( ! F_19 ( V_32 ) )
V_61 |= 1 ;
if ( ! F_19 ( V_31 ) && ! F_16 ( V_31 ) ) {
V_61 |= 2 ;
V_60 ^= F_1 ( V_31 ) ;
}
return & V_43 -> V_62 [ V_61 ] [ V_60 ] ;
}
static inline struct V_30 T_5 * * F_20 ( struct V_42 * V_43 ,
const struct V_30 * V_40 )
{
return F_18 ( V_43 , & V_40 -> V_51 ) ;
}
static void F_21 ( struct V_42 * V_43 , struct V_30 * V_40 )
{
struct V_30 T_5 * * V_63 = F_20 ( V_43 , V_40 ) ;
F_22 ( V_40 -> V_64 , F_23 ( * V_63 ) ) ;
F_22 ( * V_63 , V_40 ) ;
}
static void F_24 ( struct V_42 * V_43 , struct V_30 * V_40 )
{
struct V_30 T_5 * * V_63 ;
struct V_30 * V_65 ;
for ( V_63 = F_20 ( V_43 , V_40 ) ;
( V_65 = F_23 ( * V_63 ) ) != NULL ;
V_63 = & V_65 -> V_64 ) {
if ( V_40 == V_65 ) {
F_22 ( * V_63 , V_40 -> V_64 ) ;
break;
}
}
}
static struct V_30 * F_25 ( struct V_35 * V_35 ,
const struct V_58 * V_51 ,
int type )
{
const struct V_1 * V_31 = & V_51 -> V_53 ;
const struct V_1 * V_32 = & V_51 -> V_52 ;
T_3 V_33 = V_51 -> V_54 ;
int V_36 = V_51 -> V_36 ;
struct V_30 * V_40 ;
struct V_30 T_5 * * V_63 ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
for ( V_63 = F_18 ( V_43 , V_51 ) ;
( V_40 = F_23 ( * V_63 ) ) != NULL ;
V_63 = & V_40 -> V_64 )
if ( F_15 ( V_32 , & V_40 -> V_51 . V_52 ) &&
F_15 ( V_31 , & V_40 -> V_51 . V_53 ) &&
V_33 == V_40 -> V_51 . V_54 &&
V_36 == V_40 -> V_51 . V_36 &&
type == V_40 -> V_7 -> type )
break;
return V_40 ;
}
static struct V_30 * F_26 ( struct V_35 * V_35 ,
const struct V_58 * V_51 , int V_66 )
{
struct V_30 * V_40 , * V_67 ;
struct V_6 * V_7 ;
char V_68 [ V_69 ] ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
V_40 = F_25 ( V_35 , V_51 , V_48 ) ;
if ( V_40 || ! V_66 )
return V_40 ;
if ( V_51 -> V_68 [ 0 ] )
F_27 ( V_68 , V_51 -> V_68 , V_69 ) ;
else
strcpy ( V_68 , L_1 ) ;
V_7 = F_28 ( sizeof( * V_40 ) , V_68 , V_70 ) ;
if ( ! V_7 )
return NULL ;
F_29 ( V_7 , V_35 ) ;
V_67 = F_17 ( V_7 ) ;
V_67 -> V_51 = * V_51 ;
V_7 -> V_71 = & V_72 ;
V_67 -> V_7 = V_7 ;
F_30 ( V_67 , 1 ) ;
if ( F_31 ( V_7 ) < 0 )
goto V_73;
if ( ! ( V_67 -> V_51 . V_74 & V_75 ) )
V_7 -> V_76 |= V_77 ;
F_32 ( V_7 ) ;
F_21 ( V_43 , V_67 ) ;
return V_67 ;
V_73:
F_33 ( V_7 ) ;
return NULL ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_35 * V_35 = F_10 ( V_7 ) ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
F_24 ( V_43 , F_17 ( V_7 ) ) ;
F_35 ( V_7 ) ;
}
static void F_36 ( struct V_78 * V_79 , struct V_80 * V_81 ,
T_6 type , T_6 V_82 , int V_83 , T_3 V_84 )
{
const struct V_85 * V_86 = ( const struct V_85 * ) V_79 -> V_87 ;
T_4 * V_59 = ( T_4 * ) ( V_79 -> V_87 + V_83 ) ;
int V_88 = V_83 + 4 ;
struct V_30 * V_40 ;
T_4 V_55 ;
V_55 = V_59 [ 0 ] ;
if ( V_55 & ( V_89 | V_90 | V_75 | V_91 | V_92 ) ) {
if ( V_55 & ( V_92 | V_91 ) )
return;
if ( V_55 & V_90 ) {
V_88 += 4 ;
if ( V_55 & V_89 )
V_88 += 4 ;
}
}
if ( ! F_37 ( V_79 , V_88 ) )
return;
V_86 = ( const struct V_85 * ) V_79 -> V_87 ;
V_59 = ( T_4 * ) ( V_79 -> V_87 + V_83 ) ;
V_40 = F_9 ( V_79 -> V_7 , & V_86 -> V_93 , & V_86 -> V_94 ,
V_55 & V_90 ?
* ( ( ( T_3 * ) V_59 ) + ( V_88 / 4 ) - 1 ) : 0 ,
V_59 [ 1 ] ) ;
if ( V_40 == NULL )
return;
switch ( type ) {
T_7 V_95 ;
struct V_96 * V_97 ;
T_7 V_98 ;
case V_99 :
F_38 ( L_2 ,
V_40 -> V_51 . V_68 ) ;
break;
case V_100 :
if ( V_82 == V_101 ) {
F_38 ( L_3 ,
V_40 -> V_51 . V_68 ) ;
}
break;
case V_102 :
V_95 = 0 ;
if ( V_82 == V_103 )
V_95 = F_39 ( V_79 , V_79 -> V_87 ) ;
if ( V_95 && V_95 == V_84 - 2 ) {
V_97 = (struct V_96 * ) & V_79 -> V_87 [ V_95 ] ;
if ( V_97 -> V_104 == 0 ) {
F_38 ( L_4 ,
V_40 -> V_51 . V_68 ) ;
}
} else {
F_38 ( L_5 ,
V_40 -> V_51 . V_68 ) ;
}
break;
case V_105 :
V_98 = V_84 - V_83 ;
if ( V_98 < V_106 )
V_98 = V_106 ;
V_40 -> V_7 -> V_98 = V_98 ;
break;
}
if ( F_40 ( V_107 , V_40 -> V_108 + V_109 ) )
V_40 -> V_110 ++ ;
else
V_40 -> V_110 = 1 ;
V_40 -> V_108 = V_107 ;
}
static int F_41 ( struct V_78 * V_79 )
{
const struct V_85 * V_86 ;
T_6 * V_60 ;
T_4 V_55 ;
T_8 V_111 = 0 ;
T_3 V_33 = 0 ;
T_1 V_112 = 0 ;
struct V_30 * V_113 ;
int V_83 = 4 ;
T_4 V_34 ;
int V_114 ;
if ( ! F_37 ( V_79 , sizeof( struct V_1 ) ) )
goto V_115;
V_86 = F_42 ( V_79 ) ;
V_60 = V_79 -> V_87 ;
V_55 = * ( T_4 * ) V_60 ;
if ( V_55 & ( V_89 | V_90 | V_91 | V_75 | V_92 ) ) {
if ( V_55 & ( V_92 | V_91 ) )
goto V_115;
if ( V_55 & V_89 ) {
switch ( V_79 -> V_116 ) {
case V_117 :
V_111 = F_43 ( V_79 -> V_111 ) ;
if ( ! V_111 )
break;
case V_118 :
V_79 -> V_111 = 0 ;
V_111 = F_44 ( V_79 ) ;
V_79 -> V_116 = V_117 ;
}
V_83 += 4 ;
}
if ( V_55 & V_90 ) {
V_33 = * ( T_3 * ) ( V_60 + V_83 ) ;
V_83 += 4 ;
}
if ( V_55 & V_75 ) {
V_112 = F_45 ( * ( T_3 * ) ( V_60 + V_83 ) ) ;
V_83 += 4 ;
}
}
V_34 = * ( T_4 * ) ( V_60 + 2 ) ;
V_113 = F_9 ( V_79 -> V_7 ,
& V_86 -> V_94 , & V_86 -> V_93 , V_33 ,
V_34 ) ;
if ( V_113 ) {
struct V_10 * V_11 ;
if ( ! F_46 ( NULL , V_119 , V_79 ) )
goto V_115;
if ( ! F_47 ( V_113 , & V_86 -> V_93 , & V_86 -> V_94 ) ) {
V_113 -> V_7 -> V_19 . V_120 ++ ;
goto V_115;
}
F_48 ( V_79 ) ;
V_79 -> V_121 = V_34 ;
if ( V_55 == 0 && V_34 == F_13 ( V_122 ) ) {
V_79 -> V_121 = F_13 ( V_123 ) ;
if ( ( * ( V_60 + V_83 ) & 0xF0 ) != 0x40 )
V_83 += 4 ;
}
V_79 -> V_124 = V_79 -> V_125 ;
F_49 ( V_79 , V_83 ) ;
F_50 ( V_79 , F_51 ( V_79 ) , V_83 ) ;
V_79 -> V_126 = V_127 ;
if ( ( ( V_55 & V_89 ) && V_111 ) ||
( ! ( V_55 & V_89 ) && V_113 -> V_51 . V_128 & V_89 ) ) {
V_113 -> V_7 -> V_19 . V_20 ++ ;
V_113 -> V_7 -> V_19 . V_24 ++ ;
goto V_115;
}
if ( V_113 -> V_51 . V_128 & V_75 ) {
if ( ! ( V_55 & V_75 ) ||
( V_113 -> V_129 &&
( V_130 ) ( V_112 - V_113 -> V_129 ) < 0 ) ) {
V_113 -> V_7 -> V_19 . V_21 ++ ;
V_113 -> V_7 -> V_19 . V_24 ++ ;
goto V_115;
}
V_113 -> V_129 = V_112 + 1 ;
}
if ( V_113 -> V_7 -> type == V_47 ) {
if ( ! F_37 ( V_79 , V_131 ) ) {
V_113 -> V_7 -> V_19 . V_22 ++ ;
V_113 -> V_7 -> V_19 . V_24 ++ ;
goto V_115;
}
V_86 = F_42 ( V_79 ) ;
V_79 -> V_121 = F_52 ( V_79 , V_113 -> V_7 ) ;
F_50 ( V_79 , F_53 ( V_79 ) , V_131 ) ;
}
F_54 ( V_79 , V_113 -> V_7 ) ;
F_55 ( V_79 ) ;
V_114 = F_56 ( V_86 , V_79 ) ;
if ( F_57 ( V_114 ) ) {
if ( V_132 )
F_58 ( L_6 ,
& V_86 -> V_94 ,
F_59 ( V_86 ) ) ;
if ( V_114 > 1 ) {
++ V_113 -> V_7 -> V_19 . V_23 ;
++ V_113 -> V_7 -> V_19 . V_24 ;
goto V_115;
}
}
V_11 = F_60 ( V_113 -> V_7 -> V_11 ) ;
F_61 ( & V_11 -> V_17 ) ;
V_11 -> V_12 ++ ;
V_11 -> V_13 += V_79 -> V_133 ;
F_62 ( & V_11 -> V_17 ) ;
F_63 ( V_79 ) ;
return 0 ;
}
F_64 ( V_79 , V_99 , V_134 , 0 ) ;
V_115:
F_65 ( V_79 ) ;
return 0 ;
}
static void F_66 ( struct V_135 * V_81 , T_9 V_104 )
{
memset ( V_81 , 0 , sizeof( struct V_135 ) ) ;
V_81 -> V_136 [ 2 ] = V_137 ;
V_81 -> V_136 [ 3 ] = 1 ;
V_81 -> V_136 [ 4 ] = V_104 ;
V_81 -> V_136 [ 5 ] = V_138 ;
V_81 -> V_136 [ 6 ] = 1 ;
V_81 -> V_139 . V_140 = (struct V_141 * ) V_81 -> V_136 ;
V_81 -> V_139 . V_142 = 8 ;
}
static T_10 F_67 ( struct V_78 * V_79 ,
struct V_6 * V_7 ,
T_9 V_143 ,
struct V_144 * V_145 ,
int V_104 ,
T_7 * V_146 )
{
struct V_35 * V_35 = F_10 ( V_7 ) ;
struct V_30 * V_113 = F_17 ( V_7 ) ;
struct V_6 * V_147 ;
struct V_85 * V_86 ;
unsigned int V_148 ;
int V_149 ;
struct V_135 V_81 ;
int V_98 ;
struct V_150 * V_151 = NULL , * V_152 = NULL ;
struct V_153 * V_19 = & V_113 -> V_7 -> V_19 ;
int V_114 = - 1 ;
T_6 V_154 ;
int V_155 ;
struct V_78 * V_156 ;
if ( V_7 -> type == V_47 )
F_68 ( V_79 ) -> V_55 = 0 ;
if ( V_7 -> V_157 && V_7 -> type == V_48 ) {
V_149 = 0 ;
V_86 = (struct V_85 * ) V_79 -> V_87 ;
V_145 -> V_93 = V_86 -> V_93 ;
} else {
V_149 = V_113 -> V_158 ;
V_145 -> V_93 = V_113 -> V_51 . V_53 ;
}
if ( ! V_145 -> V_159 )
V_151 = F_69 ( V_113 ) ;
if ( ! V_151 ) {
V_152 = F_70 ( V_35 , NULL , V_145 ) ;
if ( V_152 -> error )
goto V_160;
V_152 = F_71 ( V_35 , V_152 , F_72 ( V_145 ) , NULL , 0 ) ;
if ( F_73 ( V_152 ) ) {
V_114 = F_74 ( V_152 ) ;
V_152 = NULL ;
goto V_160;
}
V_151 = V_152 ;
}
V_147 = V_151 -> V_7 ;
if ( V_147 == V_7 ) {
V_19 -> V_161 ++ ;
F_38 ( L_7 ,
V_113 -> V_51 . V_68 ) ;
goto V_162;
}
V_98 = F_75 ( V_151 ) - sizeof( * V_86 ) ;
if ( V_104 >= 0 ) {
V_148 += 8 ;
V_98 -= 8 ;
}
if ( V_98 < V_106 )
V_98 = V_106 ;
if ( F_76 ( V_79 ) )
F_76 ( V_79 ) -> V_139 -> V_163 ( F_76 ( V_79 ) , NULL , V_79 , V_98 ) ;
if ( V_79 -> V_133 > V_98 ) {
* V_146 = V_98 ;
V_114 = - V_164 ;
goto V_162;
}
if ( V_113 -> V_110 > 0 ) {
if ( F_40 ( V_107 ,
V_113 -> V_108 + V_109 ) ) {
V_113 -> V_110 -- ;
F_77 ( V_79 ) ;
} else
V_113 -> V_110 = 0 ;
}
V_148 = F_78 ( V_147 ) + V_149 + V_151 -> V_165 ;
if ( F_79 ( V_79 ) < V_148 || F_80 ( V_79 ) ||
( F_81 ( V_79 ) && ! F_82 ( V_79 , 0 ) ) ) {
V_156 = F_83 ( V_79 , V_148 ) ;
if ( V_148 > V_7 -> V_166 )
V_7 -> V_166 = V_148 ;
if ( ! V_156 )
goto V_162;
if ( V_79 -> V_167 )
F_84 ( V_156 , V_79 -> V_167 ) ;
F_85 ( V_79 ) ;
V_79 = V_156 ;
}
F_86 ( V_79 ) ;
if ( V_145 -> V_159 ) {
F_87 ( V_79 , V_151 ) ;
V_152 = NULL ;
} else {
F_88 ( V_79 , V_151 ) ;
}
V_154 = V_168 ;
if ( V_104 >= 0 ) {
F_66 ( & V_81 , V_104 ) ;
F_89 ( V_79 , & V_81 . V_139 , & V_154 , NULL ) ;
}
F_90 ( V_79 , V_149 ) ;
F_55 ( V_79 ) ;
F_91 ( V_79 , sizeof( * V_86 ) ) ;
V_86 = F_42 ( V_79 ) ;
F_92 ( V_86 , F_93 ( 0 , V_143 ) , V_145 -> V_169 ) ;
V_86 -> V_170 = V_113 -> V_51 . V_170 ;
V_86 -> V_171 = V_154 ;
V_86 -> V_94 = V_145 -> V_94 ;
V_86 -> V_93 = V_145 -> V_93 ;
( ( T_4 * ) ( V_86 + 1 ) ) [ 0 ] = V_113 -> V_51 . V_74 ;
( ( T_4 * ) ( V_86 + 1 ) ) [ 1 ] = ( V_7 -> type == V_47 ) ?
F_13 ( V_46 ) : V_79 -> V_121 ;
if ( V_113 -> V_51 . V_74 & ( V_90 | V_89 | V_75 ) ) {
T_3 * V_172 = ( T_3 * ) ( ( ( T_6 * ) V_86 ) + V_113 -> V_158 - 4 ) ;
if ( V_113 -> V_51 . V_74 & V_75 ) {
++ V_113 -> V_173 ;
* V_172 = F_94 ( V_113 -> V_173 ) ;
V_172 -- ;
}
if ( V_113 -> V_51 . V_74 & V_90 ) {
* V_172 = V_113 -> V_51 . V_174 ;
V_172 -- ;
}
if ( V_113 -> V_51 . V_74 & V_89 ) {
* V_172 = 0 ;
* ( T_8 * ) V_172 = F_95 ( ( void * ) ( V_86 + 1 ) ,
V_79 -> V_133 - sizeof( struct V_85 ) ) ;
}
}
F_96 ( V_79 ) ;
V_155 = V_79 -> V_133 ;
V_114 = F_97 ( V_79 ) ;
if ( F_98 ( V_114 ) == 0 ) {
struct V_10 * V_11 = F_60 ( V_113 -> V_7 -> V_11 ) ;
V_11 -> V_15 += V_155 ;
V_11 -> V_14 ++ ;
} else {
V_19 -> V_29 ++ ;
V_19 -> V_28 ++ ;
}
if ( V_152 )
F_99 ( V_113 , V_152 ) ;
return 0 ;
V_160:
V_19 -> V_26 ++ ;
F_77 ( V_79 ) ;
V_162:
F_100 ( V_152 ) ;
return V_114 ;
}
static inline int F_101 ( struct V_78 * V_79 , struct V_6 * V_7 )
{
struct V_30 * V_40 = F_17 ( V_7 ) ;
const struct V_175 * V_176 = F_102 ( V_79 ) ;
int V_104 = - 1 ;
struct V_144 V_145 ;
T_9 V_143 ;
T_7 V_98 ;
int V_114 ;
if ( ! ( V_40 -> V_51 . V_55 & V_177 ) )
V_104 = V_40 -> V_51 . V_104 ;
memcpy ( & V_145 , & V_40 -> V_178 . V_179 . V_180 , sizeof( V_145 ) ) ;
V_145 . V_181 = V_182 ;
V_143 = F_103 ( V_176 ) ;
if ( V_40 -> V_51 . V_55 & V_183 )
V_145 . V_169 |= F_94 ( ( T_7 ) V_176 -> V_184 << V_185 )
& V_186 ;
if ( V_40 -> V_51 . V_55 & V_187 )
V_145 . V_159 = V_79 -> V_188 ;
V_114 = F_67 ( V_79 , V_7 , V_143 , & V_145 , V_104 , & V_98 ) ;
if ( V_114 != 0 ) {
if ( V_114 == - V_164 )
F_104 ( V_79 , V_189 , V_190 ,
F_94 ( V_98 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_105 ( struct V_78 * V_79 , struct V_6 * V_7 )
{
struct V_30 * V_40 = F_17 ( V_7 ) ;
struct V_85 * V_86 = F_42 ( V_79 ) ;
int V_104 = - 1 ;
T_11 V_83 ;
struct V_144 V_145 ;
T_9 V_143 ;
T_7 V_98 ;
int V_114 ;
if ( F_15 ( & V_40 -> V_51 . V_53 , & V_86 -> V_94 ) )
return - 1 ;
V_83 = F_39 ( V_79 , F_106 ( V_79 ) ) ;
if ( V_83 > 0 ) {
struct V_96 * V_97 ;
V_97 = (struct V_96 * ) & F_106 ( V_79 ) [ V_83 ] ;
if ( V_97 -> V_104 == 0 ) {
F_64 ( V_79 , V_102 ,
V_103 , V_83 + 2 ) ;
return - 1 ;
}
V_104 = V_97 -> V_104 - 1 ;
} else if ( ! ( V_40 -> V_51 . V_55 & V_177 ) )
V_104 = V_40 -> V_51 . V_104 ;
memcpy ( & V_145 , & V_40 -> V_178 . V_179 . V_180 , sizeof( V_145 ) ) ;
V_145 . V_181 = V_191 ;
V_143 = F_59 ( V_86 ) ;
if ( V_40 -> V_51 . V_55 & V_183 )
V_145 . V_169 |= ( * ( T_3 * ) V_86 & V_186 ) ;
if ( V_40 -> V_51 . V_55 & V_192 )
V_145 . V_169 |= ( * ( T_3 * ) V_86 & V_193 ) ;
if ( V_40 -> V_51 . V_55 & V_187 )
V_145 . V_159 = V_79 -> V_188 ;
V_114 = F_67 ( V_79 , V_7 , V_143 , & V_145 , V_104 , & V_98 ) ;
if ( V_114 != 0 ) {
if ( V_114 == - V_164 )
F_64 ( V_79 , V_105 , 0 , V_98 ) ;
return - 1 ;
}
return 0 ;
}
static inline bool F_107 ( const struct V_30 * V_40 ,
const struct V_85 * V_194 )
{
return F_15 ( & V_40 -> V_51 . V_53 , & V_194 -> V_94 ) ;
}
static int F_108 ( struct V_78 * V_79 , struct V_6 * V_7 )
{
struct V_30 * V_40 = F_17 ( V_7 ) ;
int V_104 = - 1 ;
struct V_144 V_145 ;
T_7 V_98 ;
int V_114 ;
if ( ! ( V_40 -> V_51 . V_55 & V_177 ) )
V_104 = V_40 -> V_51 . V_104 ;
memcpy ( & V_145 , & V_40 -> V_178 . V_179 . V_180 , sizeof( V_145 ) ) ;
V_145 . V_181 = V_79 -> V_121 ;
V_114 = F_67 ( V_79 , V_7 , 0 , & V_145 , V_104 , & V_98 ) ;
return V_114 ;
}
static T_10 F_109 ( struct V_78 * V_79 ,
struct V_6 * V_7 )
{
struct V_30 * V_40 = F_17 ( V_7 ) ;
struct V_153 * V_19 = & V_40 -> V_7 -> V_19 ;
int V_195 ;
if ( ! F_110 ( V_40 ) )
goto V_196;
switch ( V_79 -> V_121 ) {
case F_13 ( V_123 ) :
V_195 = F_101 ( V_79 , V_7 ) ;
break;
case F_13 ( V_197 ) :
V_195 = F_105 ( V_79 , V_7 ) ;
break;
default:
V_195 = F_108 ( V_79 , V_7 ) ;
break;
}
if ( V_195 < 0 )
goto V_196;
return V_198 ;
V_196:
V_19 -> V_29 ++ ;
V_19 -> V_27 ++ ;
F_65 ( V_79 ) ;
return V_198 ;
}
static void F_30 ( struct V_30 * V_40 , int V_199 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_58 * V_59 = & V_40 -> V_51 ;
struct V_144 * V_145 = & V_40 -> V_178 . V_179 . V_180 ;
int V_200 = sizeof( struct V_85 ) + 4 ;
if ( V_7 -> type != V_47 ) {
memcpy ( V_7 -> V_201 , & V_59 -> V_52 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_202 , & V_59 -> V_53 , sizeof( struct V_1 ) ) ;
}
V_145 -> V_94 = V_59 -> V_52 ;
V_145 -> V_93 = V_59 -> V_53 ;
V_145 -> V_203 = V_59 -> V_36 ;
V_145 -> V_169 = 0 ;
if ( ! ( V_59 -> V_55 & V_183 ) )
V_145 -> V_169 |= V_186 & V_59 -> V_204 ;
if ( ! ( V_59 -> V_55 & V_192 ) )
V_145 -> V_169 |= V_193 & V_59 -> V_204 ;
V_59 -> V_55 &= ~ ( V_205 | V_206 | V_207 ) ;
V_59 -> V_55 |= F_111 ( V_40 , & V_59 -> V_52 , & V_59 -> V_53 ) ;
if ( V_59 -> V_55 & V_205 &&
V_59 -> V_55 & V_206 && V_7 -> type != V_47 )
V_7 -> V_55 |= V_208 ;
else
V_7 -> V_55 &= ~ V_208 ;
V_7 -> V_209 = V_59 -> V_36 ;
if ( V_40 -> V_51 . V_74 & ( V_89 | V_90 | V_75 ) ) {
if ( V_40 -> V_51 . V_74 & V_89 )
V_200 += 4 ;
if ( V_40 -> V_51 . V_74 & V_90 )
V_200 += 4 ;
if ( V_40 -> V_51 . V_74 & V_75 )
V_200 += 4 ;
}
if ( V_59 -> V_55 & V_205 ) {
int V_210 = ( F_112 ( & V_59 -> V_53 ) &
( V_211 | V_212 ) ) ;
struct V_213 * V_214 = F_113 ( F_10 ( V_7 ) ,
& V_59 -> V_53 , & V_59 -> V_52 ,
V_59 -> V_36 , V_210 ) ;
if ( V_214 == NULL )
return;
if ( V_214 -> V_151 . V_7 ) {
V_7 -> V_215 = V_214 -> V_151 . V_7 -> V_215 + V_200 ;
if ( V_199 ) {
V_7 -> V_98 = V_214 -> V_151 . V_7 -> V_98 - V_200 ;
if ( ! ( V_40 -> V_51 . V_55 & V_177 ) )
V_7 -> V_98 -= 8 ;
if ( V_7 -> V_98 < V_106 )
V_7 -> V_98 = V_106 ;
}
}
F_114 ( V_214 ) ;
}
V_40 -> V_158 = V_200 ;
}
static int F_115 ( struct V_30 * V_40 ,
const struct V_58 * V_59 , int V_199 )
{
V_40 -> V_51 . V_52 = V_59 -> V_52 ;
V_40 -> V_51 . V_53 = V_59 -> V_53 ;
V_40 -> V_51 . V_55 = V_59 -> V_55 ;
V_40 -> V_51 . V_170 = V_59 -> V_170 ;
V_40 -> V_51 . V_104 = V_59 -> V_104 ;
V_40 -> V_51 . V_204 = V_59 -> V_204 ;
V_40 -> V_51 . V_36 = V_59 -> V_36 ;
V_40 -> V_51 . V_154 = V_59 -> V_154 ;
V_40 -> V_51 . V_54 = V_59 -> V_54 ;
V_40 -> V_51 . V_174 = V_59 -> V_174 ;
V_40 -> V_51 . V_128 = V_59 -> V_128 ;
V_40 -> V_51 . V_74 = V_59 -> V_74 ;
F_116 ( V_40 ) ;
F_30 ( V_40 , V_199 ) ;
return 0 ;
}
static void F_117 ( struct V_58 * V_59 ,
const struct V_216 * V_179 )
{
V_59 -> V_52 = V_179 -> V_52 ;
V_59 -> V_53 = V_179 -> V_53 ;
V_59 -> V_55 = V_179 -> V_55 ;
V_59 -> V_170 = V_179 -> V_170 ;
V_59 -> V_104 = V_179 -> V_104 ;
V_59 -> V_204 = V_179 -> V_204 ;
V_59 -> V_36 = V_179 -> V_36 ;
V_59 -> V_54 = V_179 -> V_54 ;
V_59 -> V_174 = V_179 -> V_174 ;
V_59 -> V_128 = V_179 -> V_128 ;
V_59 -> V_74 = V_179 -> V_74 ;
memcpy ( V_59 -> V_68 , V_179 -> V_68 , sizeof( V_179 -> V_68 ) ) ;
}
static void F_118 ( struct V_216 * V_179 ,
const struct V_58 * V_59 )
{
V_179 -> V_154 = V_217 ;
V_179 -> V_52 = V_59 -> V_52 ;
V_179 -> V_53 = V_59 -> V_53 ;
V_179 -> V_55 = V_59 -> V_55 ;
V_179 -> V_170 = V_59 -> V_170 ;
V_179 -> V_104 = V_59 -> V_104 ;
V_179 -> V_204 = V_59 -> V_204 ;
V_179 -> V_36 = V_59 -> V_36 ;
V_179 -> V_54 = V_59 -> V_54 ;
V_179 -> V_174 = V_59 -> V_174 ;
V_179 -> V_128 = V_59 -> V_128 ;
V_179 -> V_74 = V_59 -> V_74 ;
memcpy ( V_179 -> V_68 , V_59 -> V_68 , sizeof( V_179 -> V_68 ) ) ;
}
static int F_119 ( struct V_6 * V_7 ,
struct V_218 * V_219 , int V_220 )
{
int V_114 = 0 ;
struct V_216 V_59 ;
struct V_58 V_221 ;
struct V_30 * V_40 ;
struct V_35 * V_35 = F_10 ( V_7 ) ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
switch ( V_220 ) {
case V_222 :
V_40 = NULL ;
if ( V_7 == V_43 -> V_57 ) {
if ( F_120 ( & V_59 , V_219 -> V_223 . V_224 , sizeof( V_59 ) ) ) {
V_114 = - V_225 ;
break;
}
F_117 ( & V_221 , & V_59 ) ;
V_40 = F_26 ( V_35 , & V_221 , 0 ) ;
}
if ( V_40 == NULL )
V_40 = F_17 ( V_7 ) ;
F_118 ( & V_59 , & V_40 -> V_51 ) ;
if ( F_121 ( V_219 -> V_223 . V_224 , & V_59 , sizeof( V_59 ) ) )
V_114 = - V_225 ;
break;
case V_226 :
case V_227 :
V_114 = - V_228 ;
if ( ! F_122 ( V_35 -> V_229 , V_230 ) )
goto V_231;
V_114 = - V_225 ;
if ( F_120 ( & V_59 , V_219 -> V_223 . V_224 , sizeof( V_59 ) ) )
goto V_231;
V_114 = - V_232 ;
if ( ( V_59 . V_128 | V_59 . V_74 ) & ( V_92 | V_91 ) )
goto V_231;
if ( ! ( V_59 . V_128 & V_90 ) )
V_59 . V_54 = 0 ;
if ( ! ( V_59 . V_74 & V_90 ) )
V_59 . V_174 = 0 ;
F_117 ( & V_221 , & V_59 ) ;
V_40 = F_26 ( V_35 , & V_221 , V_220 == V_226 ) ;
if ( V_7 != V_43 -> V_57 && V_220 == V_227 ) {
if ( V_40 != NULL ) {
if ( V_40 -> V_7 != V_7 ) {
V_114 = - V_233 ;
break;
}
} else {
V_40 = F_17 ( V_7 ) ;
F_24 ( V_43 , V_40 ) ;
F_123 () ;
F_115 ( V_40 , & V_221 , 1 ) ;
F_21 ( V_43 , V_40 ) ;
F_124 ( V_7 ) ;
}
}
if ( V_40 ) {
V_114 = 0 ;
F_118 ( & V_59 , & V_40 -> V_51 ) ;
if ( F_121 ( V_219 -> V_223 . V_224 , & V_59 , sizeof( V_59 ) ) )
V_114 = - V_225 ;
} else
V_114 = ( V_220 == V_226 ? - V_234 : - V_235 ) ;
break;
case V_236 :
V_114 = - V_228 ;
if ( ! F_122 ( V_35 -> V_229 , V_230 ) )
goto V_231;
if ( V_7 == V_43 -> V_57 ) {
V_114 = - V_225 ;
if ( F_120 ( & V_59 , V_219 -> V_223 . V_224 , sizeof( V_59 ) ) )
goto V_231;
V_114 = - V_235 ;
F_117 ( & V_221 , & V_59 ) ;
V_40 = F_26 ( V_35 , & V_221 , 0 ) ;
if ( V_40 == NULL )
goto V_231;
V_114 = - V_228 ;
if ( V_40 == F_17 ( V_43 -> V_57 ) )
goto V_231;
V_7 = V_40 -> V_7 ;
}
F_125 ( V_7 ) ;
V_114 = 0 ;
break;
default:
V_114 = - V_232 ;
}
V_231:
return V_114 ;
}
static int F_126 ( struct V_6 * V_7 , int V_237 )
{
struct V_30 * V_113 = F_17 ( V_7 ) ;
if ( V_237 < 68 ||
V_237 > 0xFFF8 - V_7 -> V_215 - V_113 -> V_158 )
return - V_232 ;
V_7 -> V_98 = V_237 ;
return 0 ;
}
static int F_127 ( struct V_78 * V_79 , struct V_6 * V_7 ,
unsigned short type ,
const void * V_93 , const void * V_94 , unsigned int V_133 )
{
struct V_30 * V_40 = F_17 ( V_7 ) ;
struct V_85 * V_86 = (struct V_85 * ) F_90 ( V_79 , V_40 -> V_158 ) ;
T_4 * V_59 = ( T_4 * ) ( V_86 + 1 ) ;
F_92 ( V_86 , 0 , V_40 -> V_178 . V_179 . V_180 . V_169 ) ;
V_86 -> V_170 = V_40 -> V_51 . V_170 ;
V_86 -> V_171 = V_168 ;
V_86 -> V_94 = V_40 -> V_51 . V_52 ;
V_86 -> V_93 = V_40 -> V_51 . V_53 ;
V_59 [ 0 ] = V_40 -> V_51 . V_74 ;
V_59 [ 1 ] = F_13 ( type ) ;
if ( V_94 )
memcpy ( & V_86 -> V_94 , V_94 , sizeof( struct V_1 ) ) ;
if ( V_93 )
memcpy ( & V_86 -> V_93 , V_93 , sizeof( struct V_1 ) ) ;
if ( ! F_19 ( & V_86 -> V_93 ) )
return V_40 -> V_158 ;
return - V_40 -> V_158 ;
}
static void F_128 ( struct V_6 * V_7 )
{
F_129 ( V_7 -> V_11 ) ;
F_33 ( V_7 ) ;
}
static void V_70 ( struct V_6 * V_7 )
{
struct V_30 * V_40 ;
V_7 -> V_238 = & V_239 ;
V_7 -> V_240 = F_128 ;
V_7 -> type = V_48 ;
V_7 -> V_215 = V_241 + sizeof( struct V_85 ) + 4 ;
V_7 -> V_98 = V_242 - sizeof( struct V_85 ) - 4 ;
V_40 = F_17 ( V_7 ) ;
if ( ! ( V_40 -> V_51 . V_55 & V_177 ) )
V_7 -> V_98 -= 8 ;
V_7 -> V_55 |= V_243 ;
V_7 -> V_209 = 0 ;
V_7 -> V_244 = sizeof( struct V_1 ) ;
V_7 -> V_76 |= V_245 ;
V_7 -> V_246 &= ~ V_247 ;
}
static int F_130 ( struct V_6 * V_7 )
{
struct V_30 * V_113 ;
V_113 = F_17 ( V_7 ) ;
V_113 -> V_7 = V_7 ;
strcpy ( V_113 -> V_51 . V_68 , V_7 -> V_68 ) ;
memcpy ( V_7 -> V_201 , & V_113 -> V_51 . V_52 , sizeof( struct V_1 ) ) ;
memcpy ( V_7 -> V_202 , & V_113 -> V_51 . V_53 , sizeof( struct V_1 ) ) ;
if ( F_19 ( & V_113 -> V_51 . V_53 ) )
V_7 -> V_157 = & V_248 ;
V_7 -> V_11 = F_131 ( struct V_10 ) ;
if ( ! V_7 -> V_11 )
return - V_249 ;
return 0 ;
}
static void F_132 ( struct V_6 * V_7 )
{
struct V_30 * V_113 = F_17 ( V_7 ) ;
V_113 -> V_7 = V_7 ;
strcpy ( V_113 -> V_51 . V_68 , V_7 -> V_68 ) ;
V_113 -> V_158 = sizeof( struct V_85 ) + 4 ;
F_32 ( V_7 ) ;
}
static void F_133 ( struct V_42 * V_43 ,
struct V_250 * V_251 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < V_252 ; V_60 ++ ) {
struct V_30 * V_40 ;
V_40 = F_23 ( V_43 -> V_62 [ V_61 ] [ V_60 ] ) ;
while ( V_40 != NULL ) {
F_134 ( V_40 -> V_7 , V_251 ) ;
V_40 = F_23 ( V_40 -> V_64 ) ;
}
}
}
}
static int T_12 F_135 ( struct V_35 * V_35 )
{
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
int V_114 ;
V_43 -> V_57 = F_28 ( sizeof( struct V_30 ) , L_8 ,
V_70 ) ;
if ( ! V_43 -> V_57 ) {
V_114 = - V_249 ;
goto V_253;
}
F_29 ( V_43 -> V_57 , V_35 ) ;
F_132 ( V_43 -> V_57 ) ;
V_43 -> V_57 -> V_71 = & V_72 ;
V_114 = F_136 ( V_43 -> V_57 ) ;
if ( V_114 )
goto V_254;
F_22 ( V_43 -> V_255 [ 0 ] ,
F_17 ( V_43 -> V_57 ) ) ;
return 0 ;
V_254:
F_128 ( V_43 -> V_57 ) ;
V_253:
return V_114 ;
}
static void T_13 F_137 ( struct V_35 * V_35 )
{
struct V_42 * V_43 ;
F_138 ( V_256 ) ;
V_43 = F_12 ( V_35 , V_44 ) ;
F_139 () ;
F_133 ( V_43 , & V_256 ) ;
F_140 ( & V_256 ) ;
F_141 () ;
}
static int F_142 ( struct V_257 * V_258 [] , struct V_257 * V_87 [] )
{
T_4 V_55 ;
if ( ! V_87 )
return 0 ;
V_55 = 0 ;
if ( V_87 [ V_259 ] )
V_55 |= F_143 ( V_87 [ V_259 ] ) ;
if ( V_87 [ V_260 ] )
V_55 |= F_143 ( V_87 [ V_260 ] ) ;
if ( V_55 & ( V_92 | V_91 ) )
return - V_232 ;
return 0 ;
}
static int F_144 ( struct V_257 * V_258 [] , struct V_257 * V_87 [] )
{
struct V_1 V_93 ;
if ( V_258 [ V_261 ] ) {
if ( F_145 ( V_258 [ V_261 ] ) != V_262 )
return - V_232 ;
if ( ! F_146 ( F_147 ( V_258 [ V_261 ] ) ) )
return - V_263 ;
}
if ( ! V_87 )
goto V_264;
if ( V_87 [ V_265 ] ) {
F_148 ( & V_93 , V_87 [ V_265 ] , sizeof( struct V_1 ) ) ;
if ( F_19 ( & V_93 ) )
return - V_232 ;
}
V_264:
return F_142 ( V_258 , V_87 ) ;
}
static void F_149 ( struct V_257 * V_87 [] ,
struct V_58 * V_51 )
{
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
if ( ! V_87 )
return;
if ( V_87 [ V_266 ] )
V_51 -> V_36 = F_150 ( V_87 [ V_266 ] ) ;
if ( V_87 [ V_259 ] )
V_51 -> V_128 = F_143 ( V_87 [ V_259 ] ) ;
if ( V_87 [ V_260 ] )
V_51 -> V_74 = F_143 ( V_87 [ V_260 ] ) ;
if ( V_87 [ V_267 ] )
V_51 -> V_54 = F_151 ( V_87 [ V_267 ] ) ;
if ( V_87 [ V_268 ] )
V_51 -> V_174 = F_151 ( V_87 [ V_268 ] ) ;
if ( V_87 [ V_269 ] )
F_148 ( & V_51 -> V_52 , V_87 [ V_269 ] , sizeof( struct V_1 ) ) ;
if ( V_87 [ V_265 ] )
F_148 ( & V_51 -> V_53 , V_87 [ V_265 ] , sizeof( struct V_1 ) ) ;
if ( V_87 [ V_270 ] )
V_51 -> V_170 = F_152 ( V_87 [ V_270 ] ) ;
if ( V_87 [ V_271 ] )
V_51 -> V_104 = F_152 ( V_87 [ V_271 ] ) ;
if ( V_87 [ V_272 ] )
V_51 -> V_204 = F_150 ( V_87 [ V_272 ] ) ;
if ( V_87 [ V_273 ] )
V_51 -> V_55 = F_150 ( V_87 [ V_273 ] ) ;
}
static int F_153 ( struct V_6 * V_7 )
{
struct V_30 * V_113 ;
V_113 = F_17 ( V_7 ) ;
V_113 -> V_7 = V_7 ;
strcpy ( V_113 -> V_51 . V_68 , V_7 -> V_68 ) ;
F_30 ( V_113 , 1 ) ;
V_7 -> V_11 = F_131 ( struct V_10 ) ;
if ( ! V_7 -> V_11 )
return - V_249 ;
return 0 ;
}
static void F_154 ( struct V_6 * V_7 )
{
F_155 ( V_7 ) ;
V_7 -> V_238 = & V_274 ;
V_7 -> V_240 = F_128 ;
V_7 -> V_209 = 0 ;
V_7 -> V_76 |= V_245 ;
}
static int F_156 ( struct V_35 * V_275 , struct V_6 * V_7 ,
struct V_257 * V_258 [] , struct V_257 * V_87 [] )
{
struct V_30 * V_67 ;
struct V_35 * V_35 = F_10 ( V_7 ) ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
int V_114 ;
V_67 = F_17 ( V_7 ) ;
F_149 ( V_87 , & V_67 -> V_51 ) ;
if ( F_25 ( V_35 , & V_67 -> V_51 , V_7 -> type ) )
return - V_233 ;
if ( V_7 -> type == V_47 && ! V_258 [ V_261 ] )
F_157 ( V_7 ) ;
V_67 -> V_7 = V_7 ;
F_30 ( V_67 , ! V_258 [ V_276 ] ) ;
if ( ! ( V_67 -> V_51 . V_74 & V_75 ) )
V_7 -> V_76 |= V_77 ;
V_114 = F_31 ( V_7 ) ;
if ( V_114 )
goto V_264;
F_32 ( V_7 ) ;
F_21 ( V_43 , V_67 ) ;
V_264:
return V_114 ;
}
static int F_158 ( struct V_6 * V_7 , struct V_257 * V_258 [] ,
struct V_257 * V_87 [] )
{
struct V_30 * V_40 , * V_67 ;
struct V_35 * V_35 = F_10 ( V_7 ) ;
struct V_42 * V_43 = F_12 ( V_35 , V_44 ) ;
struct V_58 V_59 ;
if ( V_7 == V_43 -> V_57 )
return - V_232 ;
V_67 = F_17 ( V_7 ) ;
F_149 ( V_87 , & V_59 ) ;
V_40 = F_26 ( V_35 , & V_59 , 0 ) ;
if ( V_40 ) {
if ( V_40 -> V_7 != V_7 )
return - V_233 ;
} else {
V_40 = V_67 ;
F_24 ( V_43 , V_40 ) ;
F_115 ( V_40 , & V_59 , ! V_258 [ V_276 ] ) ;
F_21 ( V_43 , V_40 ) ;
F_124 ( V_7 ) ;
}
return 0 ;
}
static T_14 F_159 ( const struct V_6 * V_7 )
{
return
F_160 ( 4 ) +
F_160 ( 2 ) +
F_160 ( 2 ) +
F_160 ( 4 ) +
F_160 ( 4 ) +
F_160 ( sizeof( struct V_1 ) ) +
F_160 ( sizeof( struct V_1 ) ) +
F_160 ( 1 ) +
F_160 ( 1 ) +
F_160 ( 1 ) +
F_160 ( 4 ) +
F_160 ( 4 ) +
0 ;
}
static int F_161 ( struct V_78 * V_79 , const struct V_6 * V_7 )
{
struct V_30 * V_40 = F_17 ( V_7 ) ;
struct V_58 * V_59 = & V_40 -> V_51 ;
if ( F_162 ( V_79 , V_266 , V_59 -> V_36 ) ||
F_163 ( V_79 , V_259 , V_59 -> V_128 ) ||
F_163 ( V_79 , V_260 , V_59 -> V_74 ) ||
F_164 ( V_79 , V_267 , V_59 -> V_54 ) ||
F_164 ( V_79 , V_268 , V_59 -> V_174 ) ||
F_165 ( V_79 , V_269 , sizeof( struct V_1 ) , & V_59 -> V_52 ) ||
F_165 ( V_79 , V_265 , sizeof( struct V_1 ) , & V_59 -> V_53 ) ||
F_166 ( V_79 , V_270 , V_59 -> V_170 ) ||
F_166 ( V_79 , V_271 , V_59 -> V_104 ) ||
F_164 ( V_79 , V_272 , V_59 -> V_204 ) ||
F_162 ( V_79 , V_273 , V_59 -> V_55 ) )
goto V_277;
return 0 ;
V_277:
return - V_164 ;
}
static int T_15 F_167 ( void )
{
int V_114 ;
F_168 ( L_9 ) ;
V_114 = F_169 ( & V_278 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 = F_170 ( & V_279 , V_217 ) ;
if ( V_114 < 0 ) {
F_168 ( L_10 , V_280 ) ;
goto V_281;
}
V_114 = F_171 ( & V_72 ) ;
if ( V_114 < 0 )
goto V_282;
V_114 = F_171 ( & V_283 ) ;
if ( V_114 < 0 )
goto V_284;
V_264:
return V_114 ;
V_284:
F_172 ( & V_72 ) ;
V_282:
F_173 ( & V_279 , V_217 ) ;
V_281:
F_174 ( & V_278 ) ;
goto V_264;
}
static void T_16 F_175 ( void )
{
F_172 ( & V_283 ) ;
F_172 ( & V_72 ) ;
F_173 ( & V_279 , V_217 ) ;
F_174 ( & V_278 ) ;
}
