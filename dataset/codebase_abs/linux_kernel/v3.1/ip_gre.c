static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
int V_6 ;
F_2 (i) {
const struct V_4 * V_7 = F_3 ( V_3 -> V_7 , V_6 ) ;
V_5 . V_8 += V_7 -> V_8 ;
V_5 . V_9 += V_7 -> V_9 ;
V_5 . V_10 += V_7 -> V_10 ;
V_5 . V_11 += V_7 -> V_11 ;
}
V_3 -> V_12 . V_8 = V_5 . V_8 ;
V_3 -> V_12 . V_9 = V_5 . V_9 ;
V_3 -> V_12 . V_10 = V_5 . V_10 ;
V_3 -> V_12 . V_11 = V_5 . V_11 ;
return & V_3 -> V_12 ;
}
static struct V_13 * F_4 ( struct V_2 * V_3 ,
T_1 V_14 , T_1 V_15 ,
T_1 V_16 , T_2 V_17 )
{
struct V_18 * V_18 = F_5 ( V_3 ) ;
int V_19 = V_3 -> V_20 ;
unsigned int V_21 = F_6 ( V_14 ) ;
unsigned int V_22 = F_6 ( V_16 ) ;
struct V_13 * V_23 , * V_24 = NULL ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
int V_28 = ( V_17 == F_8 ( V_29 ) ) ?
V_30 : V_31 ;
int V_32 , V_33 = 4 ;
F_9 (ign->tunnels_r_l[h0 ^ h1]) {
if ( V_15 != V_23 -> V_34 . V_35 . V_36 ||
V_14 != V_23 -> V_34 . V_35 . V_37 ||
V_16 != V_23 -> V_34 . V_38 ||
! ( V_23 -> V_3 -> V_39 & V_40 ) )
continue;
if ( V_23 -> V_3 -> type != V_31 &&
V_23 -> V_3 -> type != V_28 )
continue;
V_32 = 0 ;
if ( V_23 -> V_34 . V_19 != V_19 )
V_32 |= 1 ;
if ( V_23 -> V_3 -> type != V_28 )
V_32 |= 2 ;
if ( V_32 == 0 )
return V_23 ;
if ( V_32 < V_33 ) {
V_24 = V_23 ;
V_33 = V_32 ;
}
}
F_9 (ign->tunnels_r[h0 ^ h1]) {
if ( V_14 != V_23 -> V_34 . V_35 . V_37 ||
V_16 != V_23 -> V_34 . V_38 ||
! ( V_23 -> V_3 -> V_39 & V_40 ) )
continue;
if ( V_23 -> V_3 -> type != V_31 &&
V_23 -> V_3 -> type != V_28 )
continue;
V_32 = 0 ;
if ( V_23 -> V_34 . V_19 != V_19 )
V_32 |= 1 ;
if ( V_23 -> V_3 -> type != V_28 )
V_32 |= 2 ;
if ( V_32 == 0 )
return V_23 ;
if ( V_32 < V_33 ) {
V_24 = V_23 ;
V_33 = V_32 ;
}
}
F_9 (ign->tunnels_l[h1]) {
if ( ( V_15 != V_23 -> V_34 . V_35 . V_36 &&
( V_15 != V_23 -> V_34 . V_35 . V_37 ||
! F_10 ( V_15 ) ) ) ||
V_16 != V_23 -> V_34 . V_38 ||
! ( V_23 -> V_3 -> V_39 & V_40 ) )
continue;
if ( V_23 -> V_3 -> type != V_31 &&
V_23 -> V_3 -> type != V_28 )
continue;
V_32 = 0 ;
if ( V_23 -> V_34 . V_19 != V_19 )
V_32 |= 1 ;
if ( V_23 -> V_3 -> type != V_28 )
V_32 |= 2 ;
if ( V_32 == 0 )
return V_23 ;
if ( V_32 < V_33 ) {
V_24 = V_23 ;
V_33 = V_32 ;
}
}
F_9 (ign->tunnels_wc[h1]) {
if ( V_23 -> V_34 . V_38 != V_16 ||
! ( V_23 -> V_3 -> V_39 & V_40 ) )
continue;
if ( V_23 -> V_3 -> type != V_31 &&
V_23 -> V_3 -> type != V_28 )
continue;
V_32 = 0 ;
if ( V_23 -> V_34 . V_19 != V_19 )
V_32 |= 1 ;
if ( V_23 -> V_3 -> type != V_28 )
V_32 |= 2 ;
if ( V_32 == 0 )
return V_23 ;
if ( V_32 < V_33 ) {
V_24 = V_23 ;
V_33 = V_32 ;
}
}
if ( V_24 != NULL )
return V_24 ;
V_3 = V_26 -> V_41 ;
if ( V_3 -> V_39 & V_40 )
return F_11 ( V_3 ) ;
return NULL ;
}
static struct V_13 T_3 * * F_12 ( struct V_25 * V_26 ,
struct V_42 * V_34 )
{
T_1 V_14 = V_34 -> V_35 . V_37 ;
T_1 V_15 = V_34 -> V_35 . V_36 ;
T_1 V_16 = V_34 -> V_38 ;
unsigned int V_43 = F_6 ( V_16 ) ;
int V_44 = 0 ;
if ( V_15 )
V_44 |= 1 ;
if ( V_14 && ! F_10 ( V_14 ) ) {
V_44 |= 2 ;
V_43 ^= F_6 ( V_14 ) ;
}
return & V_26 -> V_45 [ V_44 ] [ V_43 ] ;
}
static inline struct V_13 T_3 * * F_13 ( struct V_25 * V_26 ,
struct V_13 * V_23 )
{
return F_12 ( V_26 , & V_23 -> V_34 ) ;
}
static void F_14 ( struct V_25 * V_26 , struct V_13 * V_23 )
{
struct V_13 T_3 * * V_46 = F_13 ( V_26 , V_23 ) ;
F_15 ( V_23 -> V_47 , F_16 ( * V_46 ) ) ;
F_15 ( * V_46 , V_23 ) ;
}
static void F_17 ( struct V_25 * V_26 , struct V_13 * V_23 )
{
struct V_13 T_3 * * V_46 ;
struct V_13 * V_48 ;
for ( V_46 = F_13 ( V_26 , V_23 ) ;
( V_48 = F_16 ( * V_46 ) ) != NULL ;
V_46 = & V_48 -> V_47 ) {
if ( V_23 == V_48 ) {
F_15 ( * V_46 , V_23 -> V_47 ) ;
break;
}
}
}
static struct V_13 * F_18 ( struct V_18 * V_18 ,
struct V_42 * V_34 ,
int type )
{
T_1 V_14 = V_34 -> V_35 . V_37 ;
T_1 V_15 = V_34 -> V_35 . V_36 ;
T_1 V_16 = V_34 -> V_38 ;
int V_19 = V_34 -> V_19 ;
struct V_13 * V_23 ;
struct V_13 T_3 * * V_46 ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
for ( V_46 = F_12 ( V_26 , V_34 ) ;
( V_23 = F_16 ( * V_46 ) ) != NULL ;
V_46 = & V_23 -> V_47 )
if ( V_15 == V_23 -> V_34 . V_35 . V_36 &&
V_14 == V_23 -> V_34 . V_35 . V_37 &&
V_16 == V_23 -> V_34 . V_38 &&
V_19 == V_23 -> V_34 . V_19 &&
type == V_23 -> V_3 -> type )
break;
return V_23 ;
}
static struct V_13 * F_19 ( struct V_18 * V_18 ,
struct V_42 * V_34 , int V_49 )
{
struct V_13 * V_23 , * V_50 ;
struct V_2 * V_3 ;
char V_51 [ V_52 ] ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
V_23 = F_18 ( V_18 , V_34 , V_31 ) ;
if ( V_23 || ! V_49 )
return V_23 ;
if ( V_34 -> V_51 [ 0 ] )
F_20 ( V_51 , V_34 -> V_51 , V_52 ) ;
else
strcpy ( V_51 , L_1 ) ;
V_3 = F_21 ( sizeof( * V_23 ) , V_51 , V_53 ) ;
if ( ! V_3 )
return NULL ;
F_22 ( V_3 , V_18 ) ;
V_50 = F_11 ( V_3 ) ;
V_50 -> V_34 = * V_34 ;
V_3 -> V_54 = & V_55 ;
V_3 -> V_56 = F_23 ( V_3 ) ;
if ( F_24 ( V_3 ) < 0 )
goto V_57;
F_25 ( V_3 ) ;
F_14 ( V_26 , V_50 ) ;
return V_50 ;
V_57:
F_26 ( V_3 ) ;
return NULL ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
F_17 ( V_26 , F_11 ( V_3 ) ) ;
F_28 ( V_3 ) ;
}
static void F_29 ( struct V_58 * V_59 , T_4 V_60 )
{
const struct V_61 * V_35 = ( const struct V_61 * ) V_59 -> V_62 ;
T_2 * V_63 = ( T_2 * ) ( V_59 -> V_62 + ( V_35 -> V_64 << 2 ) ) ;
int V_65 = ( V_35 -> V_64 << 2 ) + 4 ;
const int type = F_30 ( V_59 ) -> type ;
const int V_66 = F_30 ( V_59 ) -> V_66 ;
struct V_13 * V_23 ;
T_2 V_39 ;
V_39 = V_63 [ 0 ] ;
if ( V_39 & ( V_67 | V_68 | V_69 | V_70 | V_71 ) ) {
if ( V_39 & ( V_71 | V_70 ) )
return;
if ( V_39 & V_68 ) {
V_65 += 4 ;
if ( V_39 & V_67 )
V_65 += 4 ;
}
}
if ( F_31 ( V_59 ) < V_65 )
return;
switch ( type ) {
default:
case V_72 :
return;
case V_73 :
switch ( V_66 ) {
case V_74 :
case V_75 :
return;
case V_76 :
return;
default:
break;
}
break;
case V_77 :
if ( V_66 != V_78 )
return;
break;
}
F_32 () ;
V_23 = F_4 ( V_59 -> V_3 , V_35 -> V_37 , V_35 -> V_36 ,
V_39 & V_68 ?
* ( ( ( T_1 * ) V_63 ) + ( V_65 / 4 ) - 1 ) : 0 ,
V_63 [ 1 ] ) ;
if ( V_23 == NULL || V_23 -> V_34 . V_35 . V_37 == 0 ||
F_10 ( V_23 -> V_34 . V_35 . V_37 ) )
goto V_79;
if ( V_23 -> V_34 . V_35 . V_80 == 0 && type == V_77 )
goto V_79;
if ( F_33 ( V_81 , V_23 -> V_82 + V_83 ) )
V_23 -> V_84 ++ ;
else
V_23 -> V_84 = 1 ;
V_23 -> V_82 = V_81 ;
V_79:
F_34 () ;
}
static inline void F_35 ( const struct V_61 * V_35 , struct V_58 * V_59 )
{
if ( F_36 ( V_35 -> V_85 ) ) {
if ( V_59 -> V_86 == F_8 ( V_87 ) ) {
F_37 ( F_38 ( V_59 ) ) ;
} else if ( V_59 -> V_86 == F_8 ( V_88 ) ) {
F_39 ( F_40 ( V_59 ) ) ;
}
}
}
static inline T_5
F_41 ( T_5 V_85 , const struct V_61 * V_89 , struct V_58 * V_59 )
{
T_5 V_90 = 0 ;
if ( V_59 -> V_86 == F_8 ( V_87 ) )
V_90 = V_89 -> V_85 ;
else if ( V_59 -> V_86 == F_8 ( V_88 ) )
V_90 = F_42 ( ( const struct V_91 * ) V_89 ) ;
return F_43 ( V_85 , V_90 ) ;
}
static int F_44 ( struct V_58 * V_59 )
{
const struct V_61 * V_35 ;
T_5 * V_43 ;
T_2 V_39 ;
T_6 V_92 = 0 ;
T_1 V_16 = 0 ;
T_4 V_93 = 0 ;
struct V_13 * V_94 ;
int V_95 = 4 ;
T_2 V_17 ;
if ( ! F_45 ( V_59 , 16 ) )
goto V_96;
V_35 = F_38 ( V_59 ) ;
V_43 = V_59 -> V_62 ;
V_39 = * ( T_2 * ) V_43 ;
if ( V_39 & ( V_67 | V_68 | V_70 | V_69 | V_71 ) ) {
if ( V_39 & ( V_71 | V_70 ) )
goto V_96;
if ( V_39 & V_67 ) {
switch ( V_59 -> V_97 ) {
case V_98 :
V_92 = F_46 ( V_59 -> V_92 ) ;
if ( ! V_92 )
break;
case V_99 :
V_59 -> V_92 = 0 ;
V_92 = F_47 ( V_59 ) ;
V_59 -> V_97 = V_98 ;
}
V_95 += 4 ;
}
if ( V_39 & V_68 ) {
V_16 = * ( T_1 * ) ( V_43 + V_95 ) ;
V_95 += 4 ;
}
if ( V_39 & V_69 ) {
V_93 = F_48 ( * ( T_1 * ) ( V_43 + V_95 ) ) ;
V_95 += 4 ;
}
}
V_17 = * ( T_2 * ) ( V_43 + 2 ) ;
F_32 () ;
if ( ( V_94 = F_4 ( V_59 -> V_3 ,
V_35 -> V_36 , V_35 -> V_37 , V_16 ,
V_17 ) ) ) {
struct V_4 * V_7 ;
F_49 ( V_59 ) ;
V_59 -> V_86 = V_17 ;
if ( V_39 == 0 && V_17 == F_8 ( V_100 ) ) {
V_59 -> V_86 = F_8 ( V_87 ) ;
if ( ( * ( V_43 + V_95 ) & 0xF0 ) != 0x40 )
V_95 += 4 ;
}
V_59 -> V_101 = V_59 -> V_102 ;
F_50 ( V_59 , V_95 ) ;
F_51 ( V_59 , F_52 ( V_59 ) , V_95 ) ;
V_59 -> V_103 = V_104 ;
#ifdef F_53
if ( F_10 ( V_35 -> V_37 ) ) {
if ( F_54 ( F_55 ( V_59 ) ) )
goto V_105;
V_94 -> V_3 -> V_12 . V_106 ++ ;
V_59 -> V_103 = V_107 ;
}
#endif
if ( ( ( V_39 & V_67 ) && V_92 ) ||
( ! ( V_39 & V_67 ) && V_94 -> V_34 . V_108 & V_67 ) ) {
V_94 -> V_3 -> V_12 . V_109 ++ ;
V_94 -> V_3 -> V_12 . V_110 ++ ;
goto V_105;
}
if ( V_94 -> V_34 . V_108 & V_69 ) {
if ( ! ( V_39 & V_69 ) ||
( V_94 -> V_111 && ( V_112 ) ( V_93 - V_94 -> V_111 ) < 0 ) ) {
V_94 -> V_3 -> V_12 . V_113 ++ ;
V_94 -> V_3 -> V_12 . V_110 ++ ;
goto V_105;
}
V_94 -> V_111 = V_93 + 1 ;
}
if ( V_94 -> V_3 -> type == V_30 ) {
if ( ! F_45 ( V_59 , V_114 ) ) {
V_94 -> V_3 -> V_12 . V_115 ++ ;
V_94 -> V_3 -> V_12 . V_110 ++ ;
goto V_105;
}
V_35 = F_38 ( V_59 ) ;
V_59 -> V_86 = F_56 ( V_59 , V_94 -> V_3 ) ;
F_51 ( V_59 , F_57 ( V_59 ) , V_114 ) ;
}
V_7 = F_58 ( V_94 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_59 -> V_116 ;
F_59 ( V_59 , V_94 -> V_3 ) ;
F_60 ( V_59 ) ;
F_35 ( V_35 , V_59 ) ;
F_61 ( V_59 ) ;
F_34 () ;
return 0 ;
}
F_62 ( V_59 , V_73 , V_75 , 0 ) ;
V_105:
F_34 () ;
V_96:
F_63 ( V_59 ) ;
return 0 ;
}
static T_7 F_64 ( struct V_58 * V_59 , struct V_2 * V_3 )
{
struct V_13 * V_94 = F_11 ( V_3 ) ;
struct V_4 * V_7 ;
const struct V_61 * V_89 = F_38 ( V_59 ) ;
const struct V_61 * V_117 ;
struct V_118 V_119 ;
T_5 V_85 ;
T_2 V_120 ;
struct V_121 * V_122 ;
struct V_2 * V_123 ;
struct V_61 * V_35 ;
unsigned int V_124 ;
int V_125 ;
T_1 V_126 ;
int V_56 ;
if ( V_3 -> type == V_30 )
F_65 ( V_59 ) -> V_39 = 0 ;
if ( V_3 -> V_127 && V_3 -> type == V_31 ) {
V_125 = 0 ;
V_117 = ( const struct V_61 * ) V_59 -> V_62 ;
} else {
V_125 = V_94 -> V_128 ;
V_117 = & V_94 -> V_34 . V_35 ;
}
if ( ( V_126 = V_117 -> V_37 ) == 0 ) {
if ( F_66 ( V_59 ) == NULL ) {
V_3 -> V_12 . V_129 ++ ;
goto V_130;
}
if ( V_59 -> V_86 == F_8 ( V_87 ) ) {
V_122 = F_55 ( V_59 ) ;
if ( ( V_126 = V_122 -> V_131 ) == 0 )
goto V_132;
}
#if F_67 ( V_133 ) || F_67 ( V_134 )
else if ( V_59 -> V_86 == F_8 ( V_88 ) ) {
struct V_135 * V_136 = F_68 ( F_66 ( V_59 ) ) ;
const struct V_137 * V_138 ;
int V_139 ;
if ( V_136 == NULL )
goto V_130;
V_138 = ( const struct V_137 * ) & V_136 -> V_140 ;
V_139 = F_69 ( V_138 ) ;
if ( V_139 == V_141 ) {
V_138 = & F_40 ( V_59 ) -> V_37 ;
V_139 = F_69 ( V_138 ) ;
}
if ( ( V_139 & V_142 ) == 0 )
goto V_132;
V_126 = V_138 -> V_143 [ 3 ] ;
}
#endif
else
goto V_130;
}
V_85 = V_117 -> V_85 ;
if ( V_85 == 1 ) {
V_85 = 0 ;
if ( V_59 -> V_86 == F_8 ( V_87 ) )
V_85 = V_89 -> V_85 ;
else if ( V_59 -> V_86 == F_8 ( V_88 ) )
V_85 = F_42 ( ( const struct V_91 * ) V_89 ) ;
}
V_122 = F_70 ( F_5 ( V_3 ) , & V_119 , V_126 , V_117 -> V_36 ,
V_94 -> V_34 . V_144 , F_71 ( V_85 ) ,
V_94 -> V_34 . V_19 ) ;
if ( F_72 ( V_122 ) ) {
V_3 -> V_12 . V_145 ++ ;
goto V_130;
}
V_123 = V_122 -> V_126 . V_3 ;
if ( V_123 == V_3 ) {
F_73 ( V_122 ) ;
V_3 -> V_12 . V_146 ++ ;
goto V_130;
}
V_120 = V_117 -> V_147 ;
if ( V_120 )
V_56 = F_74 ( & V_122 -> V_126 ) - V_3 -> V_148 - V_94 -> V_128 ;
else
V_56 = F_66 ( V_59 ) ? F_74 ( F_66 ( V_59 ) ) : V_3 -> V_56 ;
if ( F_66 ( V_59 ) )
F_66 ( V_59 ) -> V_149 -> V_150 ( F_66 ( V_59 ) , V_56 ) ;
if ( V_59 -> V_86 == F_8 ( V_87 ) ) {
V_120 |= ( V_89 -> V_147 & F_8 ( V_151 ) ) ;
if ( ( V_89 -> V_147 & F_8 ( V_151 ) ) &&
V_56 < F_75 ( V_89 -> V_152 ) ) {
F_62 ( V_59 , V_73 , V_76 , F_76 ( V_56 ) ) ;
F_73 ( V_122 ) ;
goto V_130;
}
}
#if F_67 ( V_133 ) || F_67 ( V_134 )
else if ( V_59 -> V_86 == F_8 ( V_88 ) ) {
struct V_153 * V_154 = (struct V_153 * ) F_66 ( V_59 ) ;
if ( V_154 && V_56 < F_74 ( F_66 ( V_59 ) ) && V_56 >= V_155 ) {
if ( ( V_94 -> V_34 . V_35 . V_37 &&
! F_10 ( V_94 -> V_34 . V_35 . V_37 ) ) ||
V_154 -> V_156 . V_157 == 128 ) {
V_154 -> V_158 |= V_159 ;
F_77 ( F_66 ( V_59 ) , V_160 , V_56 ) ;
}
}
if ( V_56 >= V_155 && V_56 < V_59 -> V_116 - V_94 -> V_128 + V_125 ) {
F_78 ( V_59 , V_161 , 0 , V_56 ) ;
F_73 ( V_122 ) ;
goto V_130;
}
}
#endif
if ( V_94 -> V_84 > 0 ) {
if ( F_33 ( V_81 ,
V_94 -> V_82 + V_83 ) ) {
V_94 -> V_84 -- ;
F_79 ( V_59 ) ;
} else
V_94 -> V_84 = 0 ;
}
V_124 = F_80 ( V_123 ) + V_125 + V_122 -> V_126 . V_162 ;
if ( F_81 ( V_59 ) < V_124 || F_82 ( V_59 ) ||
( F_83 ( V_59 ) && ! F_84 ( V_59 , 0 ) ) ) {
struct V_58 * V_163 = F_85 ( V_59 , V_124 ) ;
if ( V_124 > V_3 -> V_164 )
V_3 -> V_164 = V_124 ;
if ( ! V_163 ) {
F_73 ( V_122 ) ;
V_3 -> V_12 . V_165 ++ ;
F_86 ( V_59 ) ;
return V_166 ;
}
if ( V_59 -> V_167 )
F_87 ( V_163 , V_59 -> V_167 ) ;
F_86 ( V_59 ) ;
V_59 = V_163 ;
V_89 = F_38 ( V_59 ) ;
}
F_88 ( V_59 ) ;
F_89 ( V_59 , V_125 ) ;
F_60 ( V_59 ) ;
memset ( & ( F_65 ( V_59 ) -> V_168 ) , 0 , sizeof( F_65 ( V_59 ) -> V_168 ) ) ;
F_65 ( V_59 ) -> V_39 &= ~ ( V_169 | V_170 |
V_171 ) ;
F_90 ( V_59 ) ;
F_91 ( V_59 , & V_122 -> V_126 ) ;
V_35 = F_38 ( V_59 ) ;
V_35 -> V_172 = 4 ;
V_35 -> V_64 = sizeof( struct V_61 ) >> 2 ;
V_35 -> V_147 = V_120 ;
V_35 -> V_86 = V_173 ;
V_35 -> V_85 = F_41 ( V_85 , V_89 , V_59 ) ;
V_35 -> V_37 = V_119 . V_37 ;
V_35 -> V_36 = V_119 . V_36 ;
if ( ( V_35 -> V_80 = V_117 -> V_80 ) == 0 ) {
if ( V_59 -> V_86 == F_8 ( V_87 ) )
V_35 -> V_80 = V_89 -> V_80 ;
#if F_67 ( V_133 ) || F_67 ( V_134 )
else if ( V_59 -> V_86 == F_8 ( V_88 ) )
V_35 -> V_80 = ( ( const struct V_91 * ) V_89 ) -> V_174 ;
#endif
else
V_35 -> V_80 = F_92 ( & V_122 -> V_126 ) ;
}
( ( T_2 * ) ( V_35 + 1 ) ) [ 0 ] = V_94 -> V_34 . V_175 ;
( ( T_2 * ) ( V_35 + 1 ) ) [ 1 ] = ( V_3 -> type == V_30 ) ?
F_8 ( V_29 ) : V_59 -> V_86 ;
if ( V_94 -> V_34 . V_175 & ( V_68 | V_67 | V_69 ) ) {
T_1 * V_176 = ( T_1 * ) ( ( ( T_5 * ) V_35 ) + V_94 -> V_128 - 4 ) ;
if ( V_94 -> V_34 . V_175 & V_69 ) {
++ V_94 -> V_177 ;
* V_176 = F_76 ( V_94 -> V_177 ) ;
V_176 -- ;
}
if ( V_94 -> V_34 . V_175 & V_68 ) {
* V_176 = V_94 -> V_34 . V_144 ;
V_176 -- ;
}
if ( V_94 -> V_34 . V_175 & V_67 ) {
* V_176 = 0 ;
* ( T_6 * ) V_176 = F_93 ( ( void * ) ( V_35 + 1 ) , V_59 -> V_116 - sizeof( struct V_61 ) ) ;
}
}
F_94 ( V_59 ) ;
V_7 = F_58 ( V_3 -> V_7 ) ;
F_95 ( V_7 , & V_3 -> V_12 ) ;
return V_166 ;
V_132:
F_79 ( V_59 ) ;
V_130:
V_3 -> V_12 . V_178 ++ ;
F_86 ( V_59 ) ;
return V_166 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_2 * V_123 = NULL ;
struct V_13 * V_94 ;
const struct V_61 * V_35 ;
int V_128 = V_179 ;
int V_56 = V_180 ;
int V_181 = sizeof( struct V_61 ) + 4 ;
V_94 = F_11 ( V_3 ) ;
V_35 = & V_94 -> V_34 . V_35 ;
if ( V_35 -> V_37 ) {
struct V_118 V_119 ;
struct V_121 * V_122 ;
V_122 = F_70 ( F_5 ( V_3 ) , & V_119 ,
V_35 -> V_37 , V_35 -> V_36 ,
V_94 -> V_34 . V_144 ,
F_71 ( V_35 -> V_85 ) ,
V_94 -> V_34 . V_19 ) ;
if ( ! F_72 ( V_122 ) ) {
V_123 = V_122 -> V_126 . V_3 ;
F_73 ( V_122 ) ;
}
if ( V_3 -> type != V_30 )
V_3 -> V_39 |= V_182 ;
}
if ( ! V_123 && V_94 -> V_34 . V_19 )
V_123 = F_96 ( F_5 ( V_3 ) , V_94 -> V_34 . V_19 ) ;
if ( V_123 ) {
V_128 = V_123 -> V_148 + V_123 -> V_164 ;
V_56 = V_123 -> V_56 ;
}
V_3 -> V_183 = V_94 -> V_34 . V_19 ;
if ( V_94 -> V_34 . V_175 & ( V_67 | V_68 | V_69 ) ) {
if ( V_94 -> V_34 . V_175 & V_67 )
V_181 += 4 ;
if ( V_94 -> V_34 . V_175 & V_68 )
V_181 += 4 ;
if ( V_94 -> V_34 . V_175 & V_69 )
V_181 += 4 ;
}
V_3 -> V_164 = V_181 + V_128 ;
V_56 -= V_3 -> V_148 + V_181 ;
if ( V_56 < 68 )
V_56 = 68 ;
V_94 -> V_128 = V_181 ;
return V_56 ;
}
static int
F_97 ( struct V_2 * V_3 , struct V_184 * V_185 , int V_186 )
{
int V_187 = 0 ;
struct V_42 V_63 ;
struct V_13 * V_23 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
switch ( V_186 ) {
case V_188 :
V_23 = NULL ;
if ( V_3 == V_26 -> V_41 ) {
if ( F_98 ( & V_63 , V_185 -> V_189 . V_190 , sizeof( V_63 ) ) ) {
V_187 = - V_191 ;
break;
}
V_23 = F_19 ( V_18 , & V_63 , 0 ) ;
}
if ( V_23 == NULL )
V_23 = F_11 ( V_3 ) ;
memcpy ( & V_63 , & V_23 -> V_34 , sizeof( V_63 ) ) ;
if ( F_99 ( V_185 -> V_189 . V_190 , & V_63 , sizeof( V_63 ) ) )
V_187 = - V_191 ;
break;
case V_192 :
case V_193 :
V_187 = - V_194 ;
if ( ! F_100 ( V_195 ) )
goto V_196;
V_187 = - V_191 ;
if ( F_98 ( & V_63 , V_185 -> V_189 . V_190 , sizeof( V_63 ) ) )
goto V_196;
V_187 = - V_197 ;
if ( V_63 . V_35 . V_172 != 4 || V_63 . V_35 . V_86 != V_173 ||
V_63 . V_35 . V_64 != 5 || ( V_63 . V_35 . V_147 & F_8 ( ~ V_151 ) ) ||
( ( V_63 . V_108 | V_63 . V_175 ) & ( V_71 | V_70 ) ) )
goto V_196;
if ( V_63 . V_35 . V_80 )
V_63 . V_35 . V_147 |= F_8 ( V_151 ) ;
if ( ! ( V_63 . V_108 & V_68 ) )
V_63 . V_38 = 0 ;
if ( ! ( V_63 . V_175 & V_68 ) )
V_63 . V_144 = 0 ;
V_23 = F_19 ( V_18 , & V_63 , V_186 == V_192 ) ;
if ( V_3 != V_26 -> V_41 && V_186 == V_193 ) {
if ( V_23 != NULL ) {
if ( V_23 -> V_3 != V_3 ) {
V_187 = - V_198 ;
break;
}
} else {
unsigned int V_199 = 0 ;
V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_63 . V_35 . V_37 ) )
V_199 = V_200 ;
else if ( V_63 . V_35 . V_37 )
V_199 = V_182 ;
if ( ( V_3 -> V_39 ^ V_199 ) & ( V_182 | V_200 ) ) {
V_187 = - V_197 ;
break;
}
F_17 ( V_26 , V_23 ) ;
F_101 () ;
V_23 -> V_34 . V_35 . V_36 = V_63 . V_35 . V_36 ;
V_23 -> V_34 . V_35 . V_37 = V_63 . V_35 . V_37 ;
V_23 -> V_34 . V_38 = V_63 . V_38 ;
V_23 -> V_34 . V_144 = V_63 . V_144 ;
memcpy ( V_3 -> V_201 , & V_63 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_202 , & V_63 . V_35 . V_37 , 4 ) ;
F_14 ( V_26 , V_23 ) ;
F_102 ( V_3 ) ;
}
}
if ( V_23 ) {
V_187 = 0 ;
if ( V_186 == V_193 ) {
V_23 -> V_34 . V_35 . V_80 = V_63 . V_35 . V_80 ;
V_23 -> V_34 . V_35 . V_85 = V_63 . V_35 . V_85 ;
V_23 -> V_34 . V_35 . V_147 = V_63 . V_35 . V_147 ;
if ( V_23 -> V_34 . V_19 != V_63 . V_19 ) {
V_23 -> V_34 . V_19 = V_63 . V_19 ;
V_3 -> V_56 = F_23 ( V_3 ) ;
F_102 ( V_3 ) ;
}
}
if ( F_99 ( V_185 -> V_189 . V_190 , & V_23 -> V_34 , sizeof( V_63 ) ) )
V_187 = - V_191 ;
} else
V_187 = ( V_186 == V_192 ? - V_203 : - V_204 ) ;
break;
case V_205 :
V_187 = - V_194 ;
if ( ! F_100 ( V_195 ) )
goto V_196;
if ( V_3 == V_26 -> V_41 ) {
V_187 = - V_191 ;
if ( F_98 ( & V_63 , V_185 -> V_189 . V_190 , sizeof( V_63 ) ) )
goto V_196;
V_187 = - V_204 ;
if ( ( V_23 = F_19 ( V_18 , & V_63 , 0 ) ) == NULL )
goto V_196;
V_187 = - V_194 ;
if ( V_23 == F_11 ( V_26 -> V_41 ) )
goto V_196;
V_3 = V_23 -> V_3 ;
}
F_103 ( V_3 ) ;
V_187 = 0 ;
break;
default:
V_187 = - V_197 ;
}
V_196:
return V_187 ;
}
static int F_104 ( struct V_2 * V_3 , int V_206 )
{
struct V_13 * V_94 = F_11 ( V_3 ) ;
if ( V_206 < 68 ||
V_206 > 0xFFF8 - V_3 -> V_148 - V_94 -> V_128 )
return - V_197 ;
V_3 -> V_56 = V_206 ;
return 0 ;
}
static int F_105 ( struct V_58 * V_59 , struct V_2 * V_3 ,
unsigned short type ,
const void * V_37 , const void * V_36 , unsigned int V_116 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
struct V_61 * V_35 = (struct V_61 * ) F_89 ( V_59 , V_23 -> V_128 ) ;
T_2 * V_63 = ( T_2 * ) ( V_35 + 1 ) ;
memcpy ( V_35 , & V_23 -> V_34 . V_35 , sizeof( struct V_61 ) ) ;
V_63 [ 0 ] = V_23 -> V_34 . V_175 ;
V_63 [ 1 ] = F_8 ( type ) ;
if ( V_36 )
memcpy ( & V_35 -> V_36 , V_36 , 4 ) ;
if ( V_37 )
memcpy ( & V_35 -> V_37 , V_37 , 4 ) ;
if ( V_35 -> V_37 )
return V_23 -> V_128 ;
return - V_23 -> V_128 ;
}
static int F_106 ( const struct V_58 * V_59 , unsigned char * V_207 )
{
const struct V_61 * V_35 = ( const struct V_61 * ) F_107 ( V_59 ) ;
memcpy ( V_207 , & V_35 -> V_36 , 4 ) ;
return 4 ;
}
static int F_108 ( struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_23 -> V_34 . V_35 . V_37 ) ) {
struct V_118 V_119 ;
struct V_121 * V_122 ;
V_122 = F_70 ( F_5 ( V_3 ) , & V_119 ,
V_23 -> V_34 . V_35 . V_37 ,
V_23 -> V_34 . V_35 . V_36 ,
V_23 -> V_34 . V_144 ,
F_71 ( V_23 -> V_34 . V_35 . V_85 ) ,
V_23 -> V_34 . V_19 ) ;
if ( F_72 ( V_122 ) )
return - V_208 ;
V_3 = V_122 -> V_126 . V_3 ;
F_73 ( V_122 ) ;
if ( F_109 ( V_3 ) == NULL )
return - V_208 ;
V_23 -> V_209 = V_3 -> V_20 ;
F_110 ( F_109 ( V_3 ) , V_23 -> V_34 . V_35 . V_37 ) ;
}
return 0 ;
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_23 -> V_34 . V_35 . V_37 ) && V_23 -> V_209 ) {
struct V_210 * V_211 ;
V_211 = F_112 ( F_5 ( V_3 ) , V_23 -> V_209 ) ;
if ( V_211 )
F_113 ( V_211 , V_23 -> V_34 . V_35 . V_37 ) ;
}
return 0 ;
}
static void F_114 ( struct V_2 * V_3 )
{
F_115 ( V_3 -> V_7 ) ;
F_26 ( V_3 ) ;
}
static void V_53 ( struct V_2 * V_3 )
{
V_3 -> V_212 = & V_213 ;
V_3 -> V_214 = F_114 ;
V_3 -> type = V_31 ;
V_3 -> V_164 = V_179 + sizeof( struct V_61 ) + 4 ;
V_3 -> V_56 = V_180 - sizeof( struct V_61 ) - 4 ;
V_3 -> V_39 = V_215 ;
V_3 -> V_183 = 0 ;
V_3 -> V_216 = 4 ;
V_3 -> V_217 |= V_218 ;
V_3 -> V_219 &= ~ V_220 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_13 * V_94 ;
struct V_61 * V_35 ;
V_94 = F_11 ( V_3 ) ;
V_35 = & V_94 -> V_34 . V_35 ;
V_94 -> V_3 = V_3 ;
strcpy ( V_94 -> V_34 . V_51 , V_3 -> V_51 ) ;
memcpy ( V_3 -> V_201 , & V_94 -> V_34 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_202 , & V_94 -> V_34 . V_35 . V_37 , 4 ) ;
if ( V_35 -> V_37 ) {
#ifdef F_53
if ( F_10 ( V_35 -> V_37 ) ) {
if ( ! V_35 -> V_36 )
return - V_197 ;
V_3 -> V_39 = V_200 ;
V_3 -> V_127 = & V_221 ;
}
#endif
} else
V_3 -> V_127 = & V_221 ;
V_3 -> V_7 = F_117 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_222 ;
return 0 ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_13 * V_94 = F_11 ( V_3 ) ;
struct V_61 * V_35 = & V_94 -> V_34 . V_35 ;
V_94 -> V_3 = V_3 ;
strcpy ( V_94 -> V_34 . V_51 , V_3 -> V_51 ) ;
V_35 -> V_172 = 4 ;
V_35 -> V_86 = V_173 ;
V_35 -> V_64 = 5 ;
V_94 -> V_128 = sizeof( struct V_61 ) + 4 ;
F_25 ( V_3 ) ;
}
static void F_119 ( struct V_25 * V_26 , struct V_223 * V_224 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_225 ; V_43 ++ ) {
struct V_13 * V_23 ;
V_23 = F_16 ( V_26 -> V_45 [ V_44 ] [ V_43 ] ) ;
while ( V_23 != NULL ) {
F_120 ( V_23 -> V_3 , V_224 ) ;
V_23 = F_16 ( V_23 -> V_47 ) ;
}
}
}
}
static int T_8 F_121 ( struct V_18 * V_18 )
{
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
int V_187 ;
V_26 -> V_41 = F_21 ( sizeof( struct V_13 ) , L_2 ,
V_53 ) ;
if ( ! V_26 -> V_41 ) {
V_187 = - V_222 ;
goto V_226;
}
F_22 ( V_26 -> V_41 , V_18 ) ;
F_118 ( V_26 -> V_41 ) ;
V_26 -> V_41 -> V_54 = & V_55 ;
if ( ( V_187 = F_122 ( V_26 -> V_41 ) ) )
goto V_227;
F_15 ( V_26 -> V_228 [ 0 ] ,
F_11 ( V_26 -> V_41 ) ) ;
return 0 ;
V_227:
F_114 ( V_26 -> V_41 ) ;
V_226:
return V_187 ;
}
static void T_9 F_123 ( struct V_18 * V_18 )
{
struct V_25 * V_26 ;
F_124 ( V_229 ) ;
V_26 = F_7 ( V_18 , V_27 ) ;
F_125 () ;
F_119 ( V_26 , & V_229 ) ;
F_126 ( & V_229 ) ;
F_127 () ;
}
static int F_128 ( struct V_230 * V_231 [] , struct V_230 * V_62 [] )
{
T_2 V_39 ;
if ( ! V_62 )
return 0 ;
V_39 = 0 ;
if ( V_62 [ V_232 ] )
V_39 |= F_129 ( V_62 [ V_232 ] ) ;
if ( V_62 [ V_233 ] )
V_39 |= F_129 ( V_62 [ V_233 ] ) ;
if ( V_39 & ( V_71 | V_70 ) )
return - V_197 ;
return 0 ;
}
static int F_130 ( struct V_230 * V_231 [] , struct V_230 * V_62 [] )
{
T_1 V_37 ;
if ( V_231 [ V_234 ] ) {
if ( F_131 ( V_231 [ V_234 ] ) != V_235 )
return - V_197 ;
if ( ! F_132 ( F_133 ( V_231 [ V_234 ] ) ) )
return - V_208 ;
}
if ( ! V_62 )
goto V_79;
if ( V_62 [ V_236 ] ) {
memcpy ( & V_37 , F_133 ( V_62 [ V_236 ] ) , 4 ) ;
if ( ! V_37 )
return - V_197 ;
}
V_79:
return F_128 ( V_231 , V_62 ) ;
}
static void F_134 ( struct V_230 * V_62 [] ,
struct V_42 * V_34 )
{
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_35 . V_86 = V_173 ;
if ( ! V_62 )
return;
if ( V_62 [ V_237 ] )
V_34 -> V_19 = F_135 ( V_62 [ V_237 ] ) ;
if ( V_62 [ V_232 ] )
V_34 -> V_108 = F_129 ( V_62 [ V_232 ] ) ;
if ( V_62 [ V_233 ] )
V_34 -> V_175 = F_129 ( V_62 [ V_233 ] ) ;
if ( V_62 [ V_238 ] )
V_34 -> V_38 = F_136 ( V_62 [ V_238 ] ) ;
if ( V_62 [ V_239 ] )
V_34 -> V_144 = F_136 ( V_62 [ V_239 ] ) ;
if ( V_62 [ V_240 ] )
V_34 -> V_35 . V_36 = F_136 ( V_62 [ V_240 ] ) ;
if ( V_62 [ V_236 ] )
V_34 -> V_35 . V_37 = F_136 ( V_62 [ V_236 ] ) ;
if ( V_62 [ V_241 ] )
V_34 -> V_35 . V_80 = F_137 ( V_62 [ V_241 ] ) ;
if ( V_62 [ V_242 ] )
V_34 -> V_35 . V_85 = F_137 ( V_62 [ V_242 ] ) ;
if ( ! V_62 [ V_243 ] || F_137 ( V_62 [ V_243 ] ) )
V_34 -> V_35 . V_147 = F_8 ( V_151 ) ;
}
static int F_138 ( struct V_2 * V_3 )
{
struct V_13 * V_94 ;
V_94 = F_11 ( V_3 ) ;
V_94 -> V_3 = V_3 ;
strcpy ( V_94 -> V_34 . V_51 , V_3 -> V_51 ) ;
F_23 ( V_3 ) ;
V_3 -> V_7 = F_117 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_222 ;
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
F_140 ( V_3 ) ;
V_3 -> V_212 = & V_244 ;
V_3 -> V_214 = F_114 ;
V_3 -> V_183 = 0 ;
V_3 -> V_217 |= V_218 ;
}
static int F_141 ( struct V_18 * V_245 , struct V_2 * V_3 , struct V_230 * V_231 [] ,
struct V_230 * V_62 [] )
{
struct V_13 * V_50 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
int V_56 ;
int V_187 ;
V_50 = F_11 ( V_3 ) ;
F_134 ( V_62 , & V_50 -> V_34 ) ;
if ( F_18 ( V_18 , & V_50 -> V_34 , V_3 -> type ) )
return - V_198 ;
if ( V_3 -> type == V_30 && ! V_231 [ V_234 ] )
F_142 ( V_3 -> V_201 ) ;
V_56 = F_23 ( V_3 ) ;
if ( ! V_231 [ V_246 ] )
V_3 -> V_56 = V_56 ;
if ( ! ( V_50 -> V_34 . V_175 & V_69 ) )
V_3 -> V_217 |= V_247 ;
V_187 = F_24 ( V_3 ) ;
if ( V_187 )
goto V_79;
F_25 ( V_3 ) ;
F_14 ( V_26 , V_50 ) ;
V_79:
return V_187 ;
}
static int F_143 ( struct V_2 * V_3 , struct V_230 * V_231 [] ,
struct V_230 * V_62 [] )
{
struct V_13 * V_23 , * V_50 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
struct V_42 V_63 ;
int V_56 ;
if ( V_3 == V_26 -> V_41 )
return - V_197 ;
V_50 = F_11 ( V_3 ) ;
F_134 ( V_62 , & V_63 ) ;
V_23 = F_19 ( V_18 , & V_63 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_3 != V_3 )
return - V_198 ;
} else {
V_23 = V_50 ;
if ( V_3 -> type != V_30 ) {
unsigned int V_199 = 0 ;
if ( F_10 ( V_63 . V_35 . V_37 ) )
V_199 = V_200 ;
else if ( V_63 . V_35 . V_37 )
V_199 = V_182 ;
if ( ( V_3 -> V_39 ^ V_199 ) &
( V_182 | V_200 ) )
return - V_197 ;
}
F_17 ( V_26 , V_23 ) ;
V_23 -> V_34 . V_35 . V_36 = V_63 . V_35 . V_36 ;
V_23 -> V_34 . V_35 . V_37 = V_63 . V_35 . V_37 ;
V_23 -> V_34 . V_38 = V_63 . V_38 ;
if ( V_3 -> type != V_30 ) {
memcpy ( V_3 -> V_201 , & V_63 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_202 , & V_63 . V_35 . V_37 , 4 ) ;
}
F_14 ( V_26 , V_23 ) ;
F_102 ( V_3 ) ;
}
V_23 -> V_34 . V_144 = V_63 . V_144 ;
V_23 -> V_34 . V_35 . V_80 = V_63 . V_35 . V_80 ;
V_23 -> V_34 . V_35 . V_85 = V_63 . V_35 . V_85 ;
V_23 -> V_34 . V_35 . V_147 = V_63 . V_35 . V_147 ;
if ( V_23 -> V_34 . V_19 != V_63 . V_19 ) {
V_23 -> V_34 . V_19 = V_63 . V_19 ;
V_56 = F_23 ( V_3 ) ;
if ( ! V_231 [ V_246 ] )
V_3 -> V_56 = V_56 ;
F_102 ( V_3 ) ;
}
return 0 ;
}
static T_10 F_144 ( const struct V_2 * V_3 )
{
return
F_145 ( 4 ) +
F_145 ( 2 ) +
F_145 ( 2 ) +
F_145 ( 4 ) +
F_145 ( 4 ) +
F_145 ( 4 ) +
F_145 ( 4 ) +
F_145 ( 1 ) +
F_145 ( 1 ) +
F_145 ( 1 ) +
0 ;
}
static int F_146 ( struct V_58 * V_59 , const struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
struct V_42 * V_63 = & V_23 -> V_34 ;
F_147 ( V_59 , V_237 , V_63 -> V_19 ) ;
F_148 ( V_59 , V_232 , V_63 -> V_108 ) ;
F_148 ( V_59 , V_233 , V_63 -> V_175 ) ;
F_149 ( V_59 , V_238 , V_63 -> V_38 ) ;
F_149 ( V_59 , V_239 , V_63 -> V_144 ) ;
F_149 ( V_59 , V_240 , V_63 -> V_35 . V_36 ) ;
F_149 ( V_59 , V_236 , V_63 -> V_35 . V_37 ) ;
F_150 ( V_59 , V_241 , V_63 -> V_35 . V_80 ) ;
F_150 ( V_59 , V_242 , V_63 -> V_35 . V_85 ) ;
F_150 ( V_59 , V_243 , ! ! ( V_63 -> V_35 . V_147 & F_8 ( V_151 ) ) ) ;
return 0 ;
V_248:
return - V_249 ;
}
static int T_11 F_151 ( void )
{
int V_187 ;
F_152 ( V_250 L_3 ) ;
V_187 = F_153 ( & V_251 ) ;
if ( V_187 < 0 )
return V_187 ;
V_187 = F_154 ( & V_252 , V_253 ) ;
if ( V_187 < 0 ) {
F_152 ( V_250 L_4 ) ;
goto V_254;
}
V_187 = F_155 ( & V_55 ) ;
if ( V_187 < 0 )
goto V_255;
V_187 = F_155 ( & V_256 ) ;
if ( V_187 < 0 )
goto V_257;
V_79:
return V_187 ;
V_257:
F_156 ( & V_55 ) ;
V_255:
F_157 ( & V_252 , V_253 ) ;
V_254:
F_158 ( & V_251 ) ;
goto V_79;
}
static void T_12 F_159 ( void )
{
F_156 ( & V_256 ) ;
F_156 ( & V_55 ) ;
if ( F_157 ( & V_252 , V_253 ) < 0 )
F_152 ( V_250 L_5 ) ;
F_158 ( & V_251 ) ;
}
