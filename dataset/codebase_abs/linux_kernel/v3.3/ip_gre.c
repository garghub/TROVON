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
if ( ! ( V_50 -> V_34 . V_58 & V_59 ) )
V_3 -> V_60 |= V_61 ;
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
static void F_29 ( struct V_62 * V_63 , T_4 V_64 )
{
const struct V_65 * V_35 = ( const struct V_65 * ) V_63 -> V_66 ;
T_2 * V_67 = ( T_2 * ) ( V_63 -> V_66 + ( V_35 -> V_68 << 2 ) ) ;
int V_69 = ( V_35 -> V_68 << 2 ) + 4 ;
const int type = F_30 ( V_63 ) -> type ;
const int V_70 = F_30 ( V_63 ) -> V_70 ;
struct V_13 * V_23 ;
T_2 V_39 ;
V_39 = V_67 [ 0 ] ;
if ( V_39 & ( V_71 | V_72 | V_59 | V_73 | V_74 ) ) {
if ( V_39 & ( V_74 | V_73 ) )
return;
if ( V_39 & V_72 ) {
V_69 += 4 ;
if ( V_39 & V_71 )
V_69 += 4 ;
}
}
if ( F_31 ( V_63 ) < V_69 )
return;
switch ( type ) {
default:
case V_75 :
return;
case V_76 :
switch ( V_70 ) {
case V_77 :
case V_78 :
return;
case V_79 :
return;
default:
break;
}
break;
case V_80 :
if ( V_70 != V_81 )
return;
break;
}
F_32 () ;
V_23 = F_4 ( V_63 -> V_3 , V_35 -> V_37 , V_35 -> V_36 ,
V_39 & V_72 ?
* ( ( ( T_1 * ) V_67 ) + ( V_69 / 4 ) - 1 ) : 0 ,
V_67 [ 1 ] ) ;
if ( V_23 == NULL || V_23 -> V_34 . V_35 . V_37 == 0 ||
F_10 ( V_23 -> V_34 . V_35 . V_37 ) )
goto V_82;
if ( V_23 -> V_34 . V_35 . V_83 == 0 && type == V_80 )
goto V_82;
if ( F_33 ( V_84 , V_23 -> V_85 + V_86 ) )
V_23 -> V_87 ++ ;
else
V_23 -> V_87 = 1 ;
V_23 -> V_85 = V_84 ;
V_82:
F_34 () ;
}
static inline void F_35 ( const struct V_65 * V_35 , struct V_62 * V_63 )
{
if ( F_36 ( V_35 -> V_88 ) ) {
if ( V_63 -> V_89 == F_8 ( V_90 ) ) {
F_37 ( F_38 ( V_63 ) ) ;
} else if ( V_63 -> V_89 == F_8 ( V_91 ) ) {
F_39 ( F_40 ( V_63 ) ) ;
}
}
}
static inline T_5
F_41 ( T_5 V_88 , const struct V_65 * V_92 , struct V_62 * V_63 )
{
T_5 V_93 = 0 ;
if ( V_63 -> V_89 == F_8 ( V_90 ) )
V_93 = V_92 -> V_88 ;
else if ( V_63 -> V_89 == F_8 ( V_91 ) )
V_93 = F_42 ( ( const struct V_94 * ) V_92 ) ;
return F_43 ( V_88 , V_93 ) ;
}
static int F_44 ( struct V_62 * V_63 )
{
const struct V_65 * V_35 ;
T_5 * V_43 ;
T_2 V_39 ;
T_6 V_95 = 0 ;
T_1 V_16 = 0 ;
T_4 V_96 = 0 ;
struct V_13 * V_97 ;
int V_98 = 4 ;
T_2 V_17 ;
if ( ! F_45 ( V_63 , 16 ) )
goto V_99;
V_35 = F_38 ( V_63 ) ;
V_43 = V_63 -> V_66 ;
V_39 = * ( T_2 * ) V_43 ;
if ( V_39 & ( V_71 | V_72 | V_73 | V_59 | V_74 ) ) {
if ( V_39 & ( V_74 | V_73 ) )
goto V_99;
if ( V_39 & V_71 ) {
switch ( V_63 -> V_100 ) {
case V_101 :
V_95 = F_46 ( V_63 -> V_95 ) ;
if ( ! V_95 )
break;
case V_102 :
V_63 -> V_95 = 0 ;
V_95 = F_47 ( V_63 ) ;
V_63 -> V_100 = V_101 ;
}
V_98 += 4 ;
}
if ( V_39 & V_72 ) {
V_16 = * ( T_1 * ) ( V_43 + V_98 ) ;
V_98 += 4 ;
}
if ( V_39 & V_59 ) {
V_96 = F_48 ( * ( T_1 * ) ( V_43 + V_98 ) ) ;
V_98 += 4 ;
}
}
V_17 = * ( T_2 * ) ( V_43 + 2 ) ;
F_32 () ;
if ( ( V_97 = F_4 ( V_63 -> V_3 ,
V_35 -> V_36 , V_35 -> V_37 , V_16 ,
V_17 ) ) ) {
struct V_4 * V_7 ;
F_49 ( V_63 ) ;
V_63 -> V_89 = V_17 ;
if ( V_39 == 0 && V_17 == F_8 ( V_103 ) ) {
V_63 -> V_89 = F_8 ( V_90 ) ;
if ( ( * ( V_43 + V_98 ) & 0xF0 ) != 0x40 )
V_98 += 4 ;
}
V_63 -> V_104 = V_63 -> V_105 ;
F_50 ( V_63 , V_98 ) ;
F_51 ( V_63 , F_52 ( V_63 ) , V_98 ) ;
V_63 -> V_106 = V_107 ;
#ifdef F_53
if ( F_10 ( V_35 -> V_37 ) ) {
if ( F_54 ( F_55 ( V_63 ) ) )
goto V_108;
V_97 -> V_3 -> V_12 . V_109 ++ ;
V_63 -> V_106 = V_110 ;
}
#endif
if ( ( ( V_39 & V_71 ) && V_95 ) ||
( ! ( V_39 & V_71 ) && V_97 -> V_34 . V_111 & V_71 ) ) {
V_97 -> V_3 -> V_12 . V_112 ++ ;
V_97 -> V_3 -> V_12 . V_113 ++ ;
goto V_108;
}
if ( V_97 -> V_34 . V_111 & V_59 ) {
if ( ! ( V_39 & V_59 ) ||
( V_97 -> V_114 && ( V_115 ) ( V_96 - V_97 -> V_114 ) < 0 ) ) {
V_97 -> V_3 -> V_12 . V_116 ++ ;
V_97 -> V_3 -> V_12 . V_113 ++ ;
goto V_108;
}
V_97 -> V_114 = V_96 + 1 ;
}
if ( V_97 -> V_3 -> type == V_30 ) {
if ( ! F_45 ( V_63 , V_117 ) ) {
V_97 -> V_3 -> V_12 . V_118 ++ ;
V_97 -> V_3 -> V_12 . V_113 ++ ;
goto V_108;
}
V_35 = F_38 ( V_63 ) ;
V_63 -> V_89 = F_56 ( V_63 , V_97 -> V_3 ) ;
F_51 ( V_63 , F_57 ( V_63 ) , V_117 ) ;
}
V_7 = F_58 ( V_97 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_63 -> V_119 ;
F_59 ( V_63 , V_97 -> V_3 ) ;
F_60 ( V_63 ) ;
F_35 ( V_35 , V_63 ) ;
F_61 ( V_63 ) ;
F_34 () ;
return 0 ;
}
F_62 ( V_63 , V_76 , V_78 , 0 ) ;
V_108:
F_34 () ;
V_99:
F_63 ( V_63 ) ;
return 0 ;
}
static T_7 F_64 ( struct V_62 * V_63 , struct V_2 * V_3 )
{
struct V_13 * V_97 = F_11 ( V_3 ) ;
struct V_4 * V_7 ;
const struct V_65 * V_92 = F_38 ( V_63 ) ;
const struct V_65 * V_120 ;
struct V_121 V_122 ;
T_5 V_88 ;
T_2 V_123 ;
struct V_124 * V_125 ;
struct V_2 * V_126 ;
struct V_65 * V_35 ;
unsigned int V_127 ;
int V_128 ;
T_1 V_129 ;
int V_56 ;
if ( V_3 -> type == V_30 )
F_65 ( V_63 ) -> V_39 = 0 ;
if ( V_3 -> V_130 && V_3 -> type == V_31 ) {
V_128 = 0 ;
V_120 = ( const struct V_65 * ) V_63 -> V_66 ;
} else {
V_128 = V_97 -> V_131 ;
V_120 = & V_97 -> V_34 . V_35 ;
}
if ( ( V_129 = V_120 -> V_37 ) == 0 ) {
if ( F_66 ( V_63 ) == NULL ) {
V_3 -> V_12 . V_132 ++ ;
goto V_133;
}
if ( V_63 -> V_89 == F_8 ( V_90 ) ) {
V_125 = F_55 ( V_63 ) ;
if ( ( V_129 = V_125 -> V_134 ) == 0 )
goto V_135;
}
#if F_67 ( V_136 )
else if ( V_63 -> V_89 == F_8 ( V_91 ) ) {
struct V_137 * V_138 = F_68 ( F_66 ( V_63 ) ) ;
const struct V_139 * V_140 ;
int V_141 ;
if ( V_138 == NULL )
goto V_133;
V_140 = ( const struct V_139 * ) & V_138 -> V_142 ;
V_141 = F_69 ( V_140 ) ;
if ( V_141 == V_143 ) {
V_140 = & F_40 ( V_63 ) -> V_37 ;
V_141 = F_69 ( V_140 ) ;
}
if ( ( V_141 & V_144 ) == 0 )
goto V_135;
V_129 = V_140 -> V_145 [ 3 ] ;
}
#endif
else
goto V_133;
}
V_88 = V_120 -> V_88 ;
if ( V_88 == 1 ) {
V_88 = 0 ;
if ( V_63 -> V_89 == F_8 ( V_90 ) )
V_88 = V_92 -> V_88 ;
else if ( V_63 -> V_89 == F_8 ( V_91 ) )
V_88 = F_42 ( ( const struct V_94 * ) V_92 ) ;
}
V_125 = F_70 ( F_5 ( V_3 ) , & V_122 , V_129 , V_120 -> V_36 ,
V_97 -> V_34 . V_146 , F_71 ( V_88 ) ,
V_97 -> V_34 . V_19 ) ;
if ( F_72 ( V_125 ) ) {
V_3 -> V_12 . V_147 ++ ;
goto V_133;
}
V_126 = V_125 -> V_129 . V_3 ;
if ( V_126 == V_3 ) {
F_73 ( V_125 ) ;
V_3 -> V_12 . V_148 ++ ;
goto V_133;
}
V_123 = V_120 -> V_149 ;
if ( V_123 )
V_56 = F_74 ( & V_125 -> V_129 ) - V_3 -> V_150 - V_97 -> V_131 ;
else
V_56 = F_66 ( V_63 ) ? F_74 ( F_66 ( V_63 ) ) : V_3 -> V_56 ;
if ( F_66 ( V_63 ) )
F_66 ( V_63 ) -> V_151 -> V_152 ( F_66 ( V_63 ) , V_56 ) ;
if ( V_63 -> V_89 == F_8 ( V_90 ) ) {
V_123 |= ( V_92 -> V_149 & F_8 ( V_153 ) ) ;
if ( ( V_92 -> V_149 & F_8 ( V_153 ) ) &&
V_56 < F_75 ( V_92 -> V_154 ) ) {
F_62 ( V_63 , V_76 , V_79 , F_76 ( V_56 ) ) ;
F_73 ( V_125 ) ;
goto V_133;
}
}
#if F_67 ( V_136 )
else if ( V_63 -> V_89 == F_8 ( V_91 ) ) {
struct V_155 * V_156 = (struct V_155 * ) F_66 ( V_63 ) ;
if ( V_156 && V_56 < F_74 ( F_66 ( V_63 ) ) && V_56 >= V_157 ) {
if ( ( V_97 -> V_34 . V_35 . V_37 &&
! F_10 ( V_97 -> V_34 . V_35 . V_37 ) ) ||
V_156 -> V_158 . V_159 == 128 ) {
V_156 -> V_160 |= V_161 ;
F_77 ( F_66 ( V_63 ) , V_162 , V_56 ) ;
}
}
if ( V_56 >= V_157 && V_56 < V_63 -> V_119 - V_97 -> V_131 + V_128 ) {
F_78 ( V_63 , V_163 , 0 , V_56 ) ;
F_73 ( V_125 ) ;
goto V_133;
}
}
#endif
if ( V_97 -> V_87 > 0 ) {
if ( F_33 ( V_84 ,
V_97 -> V_85 + V_86 ) ) {
V_97 -> V_87 -- ;
F_79 ( V_63 ) ;
} else
V_97 -> V_87 = 0 ;
}
V_127 = F_80 ( V_126 ) + V_128 + V_125 -> V_129 . V_164 ;
if ( F_81 ( V_63 ) < V_127 || F_82 ( V_63 ) ||
( F_83 ( V_63 ) && ! F_84 ( V_63 , 0 ) ) ) {
struct V_62 * V_165 = F_85 ( V_63 , V_127 ) ;
if ( V_127 > V_3 -> V_166 )
V_3 -> V_166 = V_127 ;
if ( ! V_165 ) {
F_73 ( V_125 ) ;
V_3 -> V_12 . V_167 ++ ;
F_86 ( V_63 ) ;
return V_168 ;
}
if ( V_63 -> V_169 )
F_87 ( V_165 , V_63 -> V_169 ) ;
F_86 ( V_63 ) ;
V_63 = V_165 ;
V_92 = F_38 ( V_63 ) ;
}
F_88 ( V_63 ) ;
F_89 ( V_63 , V_128 ) ;
F_60 ( V_63 ) ;
memset ( & ( F_65 ( V_63 ) -> V_170 ) , 0 , sizeof( F_65 ( V_63 ) -> V_170 ) ) ;
F_65 ( V_63 ) -> V_39 &= ~ ( V_171 | V_172 |
V_173 ) ;
F_90 ( V_63 ) ;
F_91 ( V_63 , & V_125 -> V_129 ) ;
V_35 = F_38 ( V_63 ) ;
V_35 -> V_174 = 4 ;
V_35 -> V_68 = sizeof( struct V_65 ) >> 2 ;
V_35 -> V_149 = V_123 ;
V_35 -> V_89 = V_175 ;
V_35 -> V_88 = F_41 ( V_88 , V_92 , V_63 ) ;
V_35 -> V_37 = V_122 . V_37 ;
V_35 -> V_36 = V_122 . V_36 ;
if ( ( V_35 -> V_83 = V_120 -> V_83 ) == 0 ) {
if ( V_63 -> V_89 == F_8 ( V_90 ) )
V_35 -> V_83 = V_92 -> V_83 ;
#if F_67 ( V_136 )
else if ( V_63 -> V_89 == F_8 ( V_91 ) )
V_35 -> V_83 = ( ( const struct V_94 * ) V_92 ) -> V_176 ;
#endif
else
V_35 -> V_83 = F_92 ( & V_125 -> V_129 ) ;
}
( ( T_2 * ) ( V_35 + 1 ) ) [ 0 ] = V_97 -> V_34 . V_58 ;
( ( T_2 * ) ( V_35 + 1 ) ) [ 1 ] = ( V_3 -> type == V_30 ) ?
F_8 ( V_29 ) : V_63 -> V_89 ;
if ( V_97 -> V_34 . V_58 & ( V_72 | V_71 | V_59 ) ) {
T_1 * V_177 = ( T_1 * ) ( ( ( T_5 * ) V_35 ) + V_97 -> V_131 - 4 ) ;
if ( V_97 -> V_34 . V_58 & V_59 ) {
++ V_97 -> V_178 ;
* V_177 = F_76 ( V_97 -> V_178 ) ;
V_177 -- ;
}
if ( V_97 -> V_34 . V_58 & V_72 ) {
* V_177 = V_97 -> V_34 . V_146 ;
V_177 -- ;
}
if ( V_97 -> V_34 . V_58 & V_71 ) {
* V_177 = 0 ;
* ( T_6 * ) V_177 = F_93 ( ( void * ) ( V_35 + 1 ) , V_63 -> V_119 - sizeof( struct V_65 ) ) ;
}
}
F_94 ( V_63 ) ;
V_7 = F_58 ( V_3 -> V_7 ) ;
F_95 ( V_7 , & V_3 -> V_12 ) ;
return V_168 ;
V_135:
F_79 ( V_63 ) ;
V_133:
V_3 -> V_12 . V_179 ++ ;
F_86 ( V_63 ) ;
return V_168 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_2 * V_126 = NULL ;
struct V_13 * V_97 ;
const struct V_65 * V_35 ;
int V_131 = V_180 ;
int V_56 = V_181 ;
int V_182 = sizeof( struct V_65 ) + 4 ;
V_97 = F_11 ( V_3 ) ;
V_35 = & V_97 -> V_34 . V_35 ;
if ( V_35 -> V_37 ) {
struct V_121 V_122 ;
struct V_124 * V_125 ;
V_125 = F_70 ( F_5 ( V_3 ) , & V_122 ,
V_35 -> V_37 , V_35 -> V_36 ,
V_97 -> V_34 . V_146 ,
F_71 ( V_35 -> V_88 ) ,
V_97 -> V_34 . V_19 ) ;
if ( ! F_72 ( V_125 ) ) {
V_126 = V_125 -> V_129 . V_3 ;
F_73 ( V_125 ) ;
}
if ( V_3 -> type != V_30 )
V_3 -> V_39 |= V_183 ;
}
if ( ! V_126 && V_97 -> V_34 . V_19 )
V_126 = F_96 ( F_5 ( V_3 ) , V_97 -> V_34 . V_19 ) ;
if ( V_126 ) {
V_131 = V_126 -> V_150 + V_126 -> V_166 ;
V_56 = V_126 -> V_56 ;
}
V_3 -> V_184 = V_97 -> V_34 . V_19 ;
if ( V_97 -> V_34 . V_58 & ( V_71 | V_72 | V_59 ) ) {
if ( V_97 -> V_34 . V_58 & V_71 )
V_182 += 4 ;
if ( V_97 -> V_34 . V_58 & V_72 )
V_182 += 4 ;
if ( V_97 -> V_34 . V_58 & V_59 )
V_182 += 4 ;
}
V_3 -> V_166 = V_182 + V_131 ;
V_56 -= V_3 -> V_150 + V_182 ;
if ( V_56 < 68 )
V_56 = 68 ;
V_97 -> V_131 = V_182 ;
return V_56 ;
}
static int
F_97 ( struct V_2 * V_3 , struct V_185 * V_186 , int V_187 )
{
int V_188 = 0 ;
struct V_42 V_67 ;
struct V_13 * V_23 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
switch ( V_187 ) {
case V_189 :
V_23 = NULL ;
if ( V_3 == V_26 -> V_41 ) {
if ( F_98 ( & V_67 , V_186 -> V_190 . V_191 , sizeof( V_67 ) ) ) {
V_188 = - V_192 ;
break;
}
V_23 = F_19 ( V_18 , & V_67 , 0 ) ;
}
if ( V_23 == NULL )
V_23 = F_11 ( V_3 ) ;
memcpy ( & V_67 , & V_23 -> V_34 , sizeof( V_67 ) ) ;
if ( F_99 ( V_186 -> V_190 . V_191 , & V_67 , sizeof( V_67 ) ) )
V_188 = - V_192 ;
break;
case V_193 :
case V_194 :
V_188 = - V_195 ;
if ( ! F_100 ( V_196 ) )
goto V_197;
V_188 = - V_192 ;
if ( F_98 ( & V_67 , V_186 -> V_190 . V_191 , sizeof( V_67 ) ) )
goto V_197;
V_188 = - V_198 ;
if ( V_67 . V_35 . V_174 != 4 || V_67 . V_35 . V_89 != V_175 ||
V_67 . V_35 . V_68 != 5 || ( V_67 . V_35 . V_149 & F_8 ( ~ V_153 ) ) ||
( ( V_67 . V_111 | V_67 . V_58 ) & ( V_74 | V_73 ) ) )
goto V_197;
if ( V_67 . V_35 . V_83 )
V_67 . V_35 . V_149 |= F_8 ( V_153 ) ;
if ( ! ( V_67 . V_111 & V_72 ) )
V_67 . V_38 = 0 ;
if ( ! ( V_67 . V_58 & V_72 ) )
V_67 . V_146 = 0 ;
V_23 = F_19 ( V_18 , & V_67 , V_187 == V_193 ) ;
if ( V_3 != V_26 -> V_41 && V_187 == V_194 ) {
if ( V_23 != NULL ) {
if ( V_23 -> V_3 != V_3 ) {
V_188 = - V_199 ;
break;
}
} else {
unsigned int V_200 = 0 ;
V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_67 . V_35 . V_37 ) )
V_200 = V_201 ;
else if ( V_67 . V_35 . V_37 )
V_200 = V_183 ;
if ( ( V_3 -> V_39 ^ V_200 ) & ( V_183 | V_201 ) ) {
V_188 = - V_198 ;
break;
}
F_17 ( V_26 , V_23 ) ;
F_101 () ;
V_23 -> V_34 . V_35 . V_36 = V_67 . V_35 . V_36 ;
V_23 -> V_34 . V_35 . V_37 = V_67 . V_35 . V_37 ;
V_23 -> V_34 . V_38 = V_67 . V_38 ;
V_23 -> V_34 . V_146 = V_67 . V_146 ;
memcpy ( V_3 -> V_202 , & V_67 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_203 , & V_67 . V_35 . V_37 , 4 ) ;
F_14 ( V_26 , V_23 ) ;
F_102 ( V_3 ) ;
}
}
if ( V_23 ) {
V_188 = 0 ;
if ( V_187 == V_194 ) {
V_23 -> V_34 . V_35 . V_83 = V_67 . V_35 . V_83 ;
V_23 -> V_34 . V_35 . V_88 = V_67 . V_35 . V_88 ;
V_23 -> V_34 . V_35 . V_149 = V_67 . V_35 . V_149 ;
if ( V_23 -> V_34 . V_19 != V_67 . V_19 ) {
V_23 -> V_34 . V_19 = V_67 . V_19 ;
V_3 -> V_56 = F_23 ( V_3 ) ;
F_102 ( V_3 ) ;
}
}
if ( F_99 ( V_186 -> V_190 . V_191 , & V_23 -> V_34 , sizeof( V_67 ) ) )
V_188 = - V_192 ;
} else
V_188 = ( V_187 == V_193 ? - V_204 : - V_205 ) ;
break;
case V_206 :
V_188 = - V_195 ;
if ( ! F_100 ( V_196 ) )
goto V_197;
if ( V_3 == V_26 -> V_41 ) {
V_188 = - V_192 ;
if ( F_98 ( & V_67 , V_186 -> V_190 . V_191 , sizeof( V_67 ) ) )
goto V_197;
V_188 = - V_205 ;
if ( ( V_23 = F_19 ( V_18 , & V_67 , 0 ) ) == NULL )
goto V_197;
V_188 = - V_195 ;
if ( V_23 == F_11 ( V_26 -> V_41 ) )
goto V_197;
V_3 = V_23 -> V_3 ;
}
F_103 ( V_3 ) ;
V_188 = 0 ;
break;
default:
V_188 = - V_198 ;
}
V_197:
return V_188 ;
}
static int F_104 ( struct V_2 * V_3 , int V_207 )
{
struct V_13 * V_97 = F_11 ( V_3 ) ;
if ( V_207 < 68 ||
V_207 > 0xFFF8 - V_3 -> V_150 - V_97 -> V_131 )
return - V_198 ;
V_3 -> V_56 = V_207 ;
return 0 ;
}
static int F_105 ( struct V_62 * V_63 , struct V_2 * V_3 ,
unsigned short type ,
const void * V_37 , const void * V_36 , unsigned int V_119 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
struct V_65 * V_35 = (struct V_65 * ) F_89 ( V_63 , V_23 -> V_131 ) ;
T_2 * V_67 = ( T_2 * ) ( V_35 + 1 ) ;
memcpy ( V_35 , & V_23 -> V_34 . V_35 , sizeof( struct V_65 ) ) ;
V_67 [ 0 ] = V_23 -> V_34 . V_58 ;
V_67 [ 1 ] = F_8 ( type ) ;
if ( V_36 )
memcpy ( & V_35 -> V_36 , V_36 , 4 ) ;
if ( V_37 )
memcpy ( & V_35 -> V_37 , V_37 , 4 ) ;
if ( V_35 -> V_37 )
return V_23 -> V_131 ;
return - V_23 -> V_131 ;
}
static int F_106 ( const struct V_62 * V_63 , unsigned char * V_208 )
{
const struct V_65 * V_35 = ( const struct V_65 * ) F_107 ( V_63 ) ;
memcpy ( V_208 , & V_35 -> V_36 , 4 ) ;
return 4 ;
}
static int F_108 ( struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_23 -> V_34 . V_35 . V_37 ) ) {
struct V_121 V_122 ;
struct V_124 * V_125 ;
V_125 = F_70 ( F_5 ( V_3 ) , & V_122 ,
V_23 -> V_34 . V_35 . V_37 ,
V_23 -> V_34 . V_35 . V_36 ,
V_23 -> V_34 . V_146 ,
F_71 ( V_23 -> V_34 . V_35 . V_88 ) ,
V_23 -> V_34 . V_19 ) ;
if ( F_72 ( V_125 ) )
return - V_209 ;
V_3 = V_125 -> V_129 . V_3 ;
F_73 ( V_125 ) ;
if ( F_109 ( V_3 ) == NULL )
return - V_209 ;
V_23 -> V_210 = V_3 -> V_20 ;
F_110 ( F_109 ( V_3 ) , V_23 -> V_34 . V_35 . V_37 ) ;
}
return 0 ;
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_23 -> V_34 . V_35 . V_37 ) && V_23 -> V_210 ) {
struct V_211 * V_212 ;
V_212 = F_112 ( F_5 ( V_3 ) , V_23 -> V_210 ) ;
if ( V_212 )
F_113 ( V_212 , V_23 -> V_34 . V_35 . V_37 ) ;
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
V_3 -> V_213 = & V_214 ;
V_3 -> V_215 = F_114 ;
V_3 -> type = V_31 ;
V_3 -> V_166 = V_180 + sizeof( struct V_65 ) + 4 ;
V_3 -> V_56 = V_181 - sizeof( struct V_65 ) - 4 ;
V_3 -> V_39 = V_216 ;
V_3 -> V_184 = 0 ;
V_3 -> V_217 = 4 ;
V_3 -> V_60 |= V_218 ;
V_3 -> V_219 &= ~ V_220 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_13 * V_97 ;
struct V_65 * V_35 ;
V_97 = F_11 ( V_3 ) ;
V_35 = & V_97 -> V_34 . V_35 ;
V_97 -> V_3 = V_3 ;
strcpy ( V_97 -> V_34 . V_51 , V_3 -> V_51 ) ;
memcpy ( V_3 -> V_202 , & V_97 -> V_34 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_203 , & V_97 -> V_34 . V_35 . V_37 , 4 ) ;
if ( V_35 -> V_37 ) {
#ifdef F_53
if ( F_10 ( V_35 -> V_37 ) ) {
if ( ! V_35 -> V_36 )
return - V_198 ;
V_3 -> V_39 = V_201 ;
V_3 -> V_130 = & V_221 ;
}
#endif
} else
V_3 -> V_130 = & V_221 ;
V_3 -> V_7 = F_117 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_222 ;
return 0 ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_13 * V_97 = F_11 ( V_3 ) ;
struct V_65 * V_35 = & V_97 -> V_34 . V_35 ;
V_97 -> V_3 = V_3 ;
strcpy ( V_97 -> V_34 . V_51 , V_3 -> V_51 ) ;
V_35 -> V_174 = 4 ;
V_35 -> V_89 = V_175 ;
V_35 -> V_68 = 5 ;
V_97 -> V_131 = sizeof( struct V_65 ) + 4 ;
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
int V_188 ;
V_26 -> V_41 = F_21 ( sizeof( struct V_13 ) , L_2 ,
V_53 ) ;
if ( ! V_26 -> V_41 ) {
V_188 = - V_222 ;
goto V_226;
}
F_22 ( V_26 -> V_41 , V_18 ) ;
F_118 ( V_26 -> V_41 ) ;
V_26 -> V_41 -> V_54 = & V_55 ;
if ( ( V_188 = F_122 ( V_26 -> V_41 ) ) )
goto V_227;
F_15 ( V_26 -> V_228 [ 0 ] ,
F_11 ( V_26 -> V_41 ) ) ;
return 0 ;
V_227:
F_114 ( V_26 -> V_41 ) ;
V_226:
return V_188 ;
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
static int F_128 ( struct V_230 * V_231 [] , struct V_230 * V_66 [] )
{
T_2 V_39 ;
if ( ! V_66 )
return 0 ;
V_39 = 0 ;
if ( V_66 [ V_232 ] )
V_39 |= F_129 ( V_66 [ V_232 ] ) ;
if ( V_66 [ V_233 ] )
V_39 |= F_129 ( V_66 [ V_233 ] ) ;
if ( V_39 & ( V_74 | V_73 ) )
return - V_198 ;
return 0 ;
}
static int F_130 ( struct V_230 * V_231 [] , struct V_230 * V_66 [] )
{
T_1 V_37 ;
if ( V_231 [ V_234 ] ) {
if ( F_131 ( V_231 [ V_234 ] ) != V_235 )
return - V_198 ;
if ( ! F_132 ( F_133 ( V_231 [ V_234 ] ) ) )
return - V_209 ;
}
if ( ! V_66 )
goto V_82;
if ( V_66 [ V_236 ] ) {
memcpy ( & V_37 , F_133 ( V_66 [ V_236 ] ) , 4 ) ;
if ( ! V_37 )
return - V_198 ;
}
V_82:
return F_128 ( V_231 , V_66 ) ;
}
static void F_134 ( struct V_230 * V_66 [] ,
struct V_42 * V_34 )
{
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_35 . V_89 = V_175 ;
if ( ! V_66 )
return;
if ( V_66 [ V_237 ] )
V_34 -> V_19 = F_135 ( V_66 [ V_237 ] ) ;
if ( V_66 [ V_232 ] )
V_34 -> V_111 = F_129 ( V_66 [ V_232 ] ) ;
if ( V_66 [ V_233 ] )
V_34 -> V_58 = F_129 ( V_66 [ V_233 ] ) ;
if ( V_66 [ V_238 ] )
V_34 -> V_38 = F_136 ( V_66 [ V_238 ] ) ;
if ( V_66 [ V_239 ] )
V_34 -> V_146 = F_136 ( V_66 [ V_239 ] ) ;
if ( V_66 [ V_240 ] )
V_34 -> V_35 . V_36 = F_136 ( V_66 [ V_240 ] ) ;
if ( V_66 [ V_236 ] )
V_34 -> V_35 . V_37 = F_136 ( V_66 [ V_236 ] ) ;
if ( V_66 [ V_241 ] )
V_34 -> V_35 . V_83 = F_137 ( V_66 [ V_241 ] ) ;
if ( V_66 [ V_242 ] )
V_34 -> V_35 . V_88 = F_137 ( V_66 [ V_242 ] ) ;
if ( ! V_66 [ V_243 ] || F_137 ( V_66 [ V_243 ] ) )
V_34 -> V_35 . V_149 = F_8 ( V_153 ) ;
}
static int F_138 ( struct V_2 * V_3 )
{
struct V_13 * V_97 ;
V_97 = F_11 ( V_3 ) ;
V_97 -> V_3 = V_3 ;
strcpy ( V_97 -> V_34 . V_51 , V_3 -> V_51 ) ;
F_23 ( V_3 ) ;
V_3 -> V_7 = F_117 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_222 ;
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
F_140 ( V_3 ) ;
V_3 -> V_213 = & V_244 ;
V_3 -> V_215 = F_114 ;
V_3 -> V_184 = 0 ;
V_3 -> V_60 |= V_218 ;
}
static int F_141 ( struct V_18 * V_245 , struct V_2 * V_3 , struct V_230 * V_231 [] ,
struct V_230 * V_66 [] )
{
struct V_13 * V_50 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
int V_56 ;
int V_188 ;
V_50 = F_11 ( V_3 ) ;
F_134 ( V_66 , & V_50 -> V_34 ) ;
if ( F_18 ( V_18 , & V_50 -> V_34 , V_3 -> type ) )
return - V_199 ;
if ( V_3 -> type == V_30 && ! V_231 [ V_234 ] )
F_142 ( V_3 -> V_202 ) ;
V_56 = F_23 ( V_3 ) ;
if ( ! V_231 [ V_246 ] )
V_3 -> V_56 = V_56 ;
if ( ! ( V_50 -> V_34 . V_58 & V_59 ) )
V_3 -> V_60 |= V_61 ;
V_188 = F_24 ( V_3 ) ;
if ( V_188 )
goto V_82;
F_25 ( V_3 ) ;
F_14 ( V_26 , V_50 ) ;
V_82:
return V_188 ;
}
static int F_143 ( struct V_2 * V_3 , struct V_230 * V_231 [] ,
struct V_230 * V_66 [] )
{
struct V_13 * V_23 , * V_50 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
struct V_42 V_67 ;
int V_56 ;
if ( V_3 == V_26 -> V_41 )
return - V_198 ;
V_50 = F_11 ( V_3 ) ;
F_134 ( V_66 , & V_67 ) ;
V_23 = F_19 ( V_18 , & V_67 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_3 != V_3 )
return - V_199 ;
} else {
V_23 = V_50 ;
if ( V_3 -> type != V_30 ) {
unsigned int V_200 = 0 ;
if ( F_10 ( V_67 . V_35 . V_37 ) )
V_200 = V_201 ;
else if ( V_67 . V_35 . V_37 )
V_200 = V_183 ;
if ( ( V_3 -> V_39 ^ V_200 ) &
( V_183 | V_201 ) )
return - V_198 ;
}
F_17 ( V_26 , V_23 ) ;
V_23 -> V_34 . V_35 . V_36 = V_67 . V_35 . V_36 ;
V_23 -> V_34 . V_35 . V_37 = V_67 . V_35 . V_37 ;
V_23 -> V_34 . V_38 = V_67 . V_38 ;
if ( V_3 -> type != V_30 ) {
memcpy ( V_3 -> V_202 , & V_67 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_203 , & V_67 . V_35 . V_37 , 4 ) ;
}
F_14 ( V_26 , V_23 ) ;
F_102 ( V_3 ) ;
}
V_23 -> V_34 . V_146 = V_67 . V_146 ;
V_23 -> V_34 . V_35 . V_83 = V_67 . V_35 . V_83 ;
V_23 -> V_34 . V_35 . V_88 = V_67 . V_35 . V_88 ;
V_23 -> V_34 . V_35 . V_149 = V_67 . V_35 . V_149 ;
if ( V_23 -> V_34 . V_19 != V_67 . V_19 ) {
V_23 -> V_34 . V_19 = V_67 . V_19 ;
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
static int F_146 ( struct V_62 * V_63 , const struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
struct V_42 * V_67 = & V_23 -> V_34 ;
F_147 ( V_63 , V_237 , V_67 -> V_19 ) ;
F_148 ( V_63 , V_232 , V_67 -> V_111 ) ;
F_148 ( V_63 , V_233 , V_67 -> V_58 ) ;
F_149 ( V_63 , V_238 , V_67 -> V_38 ) ;
F_149 ( V_63 , V_239 , V_67 -> V_146 ) ;
F_149 ( V_63 , V_240 , V_67 -> V_35 . V_36 ) ;
F_149 ( V_63 , V_236 , V_67 -> V_35 . V_37 ) ;
F_150 ( V_63 , V_241 , V_67 -> V_35 . V_83 ) ;
F_150 ( V_63 , V_242 , V_67 -> V_35 . V_88 ) ;
F_150 ( V_63 , V_243 , ! ! ( V_67 -> V_35 . V_149 & F_8 ( V_153 ) ) ) ;
return 0 ;
V_247:
return - V_248 ;
}
static int T_11 F_151 ( void )
{
int V_188 ;
F_152 ( V_249 L_3 ) ;
V_188 = F_153 ( & V_250 ) ;
if ( V_188 < 0 )
return V_188 ;
V_188 = F_154 ( & V_251 , V_252 ) ;
if ( V_188 < 0 ) {
F_152 ( V_249 L_4 ) ;
goto V_253;
}
V_188 = F_155 ( & V_55 ) ;
if ( V_188 < 0 )
goto V_254;
V_188 = F_155 ( & V_255 ) ;
if ( V_188 < 0 )
goto V_256;
V_82:
return V_188 ;
V_256:
F_156 ( & V_55 ) ;
V_254:
F_157 ( & V_251 , V_252 ) ;
V_253:
F_158 ( & V_250 ) ;
goto V_82;
}
static void T_12 F_159 ( void )
{
F_156 ( & V_255 ) ;
F_156 ( & V_55 ) ;
if ( F_157 ( & V_251 , V_252 ) < 0 )
F_152 ( V_249 L_5 ) ;
F_158 ( & V_250 ) ;
}
