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
V_129 = V_125 -> V_134 ;
}
#if F_67 ( V_135 )
else if ( V_63 -> V_89 == F_8 ( V_91 ) ) {
const struct V_136 * V_137 ;
struct V_138 * V_139 ;
bool V_140 ;
int V_141 ;
V_139 = F_68 ( F_66 ( V_63 ) , & F_40 ( V_63 ) -> V_37 ) ;
if ( V_139 == NULL )
goto V_133;
V_137 = ( const struct V_136 * ) & V_139 -> V_142 ;
V_141 = F_69 ( V_137 ) ;
if ( V_141 == V_143 ) {
V_137 = & F_40 ( V_63 ) -> V_37 ;
V_141 = F_69 ( V_137 ) ;
}
if ( ( V_141 & V_144 ) == 0 )
V_140 = true ;
else {
V_140 = false ;
V_129 = V_137 -> V_145 [ 3 ] ;
}
F_70 ( V_139 ) ;
if ( V_140 )
goto V_146;
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
V_125 = F_71 ( F_5 ( V_3 ) , & V_122 , V_129 , V_120 -> V_36 ,
V_97 -> V_34 . V_147 , F_72 ( V_88 ) ,
V_97 -> V_34 . V_19 ) ;
if ( F_73 ( V_125 ) ) {
V_3 -> V_12 . V_148 ++ ;
goto V_133;
}
V_126 = V_125 -> V_129 . V_3 ;
if ( V_126 == V_3 ) {
F_74 ( V_125 ) ;
V_3 -> V_12 . V_149 ++ ;
goto V_133;
}
V_123 = V_120 -> V_150 ;
if ( V_123 )
V_56 = F_75 ( & V_125 -> V_129 ) - V_3 -> V_151 - V_97 -> V_131 ;
else
V_56 = F_66 ( V_63 ) ? F_75 ( F_66 ( V_63 ) ) : V_3 -> V_56 ;
if ( F_66 ( V_63 ) )
F_66 ( V_63 ) -> V_152 -> V_153 ( F_66 ( V_63 ) , V_56 ) ;
if ( V_63 -> V_89 == F_8 ( V_90 ) ) {
V_123 |= ( V_92 -> V_150 & F_8 ( V_154 ) ) ;
if ( ( V_92 -> V_150 & F_8 ( V_154 ) ) &&
V_56 < F_76 ( V_92 -> V_155 ) ) {
F_62 ( V_63 , V_76 , V_79 , F_77 ( V_56 ) ) ;
F_74 ( V_125 ) ;
goto V_133;
}
}
#if F_67 ( V_135 )
else if ( V_63 -> V_89 == F_8 ( V_91 ) ) {
struct V_156 * V_157 = (struct V_156 * ) F_66 ( V_63 ) ;
if ( V_157 && V_56 < F_75 ( F_66 ( V_63 ) ) && V_56 >= V_158 ) {
if ( ( V_97 -> V_34 . V_35 . V_37 &&
! F_10 ( V_97 -> V_34 . V_35 . V_37 ) ) ||
V_157 -> V_159 . V_160 == 128 ) {
V_157 -> V_161 |= V_162 ;
F_78 ( F_66 ( V_63 ) , V_163 , V_56 ) ;
}
}
if ( V_56 >= V_158 && V_56 < V_63 -> V_119 - V_97 -> V_131 + V_128 ) {
F_79 ( V_63 , V_164 , 0 , V_56 ) ;
F_74 ( V_125 ) ;
goto V_133;
}
}
#endif
if ( V_97 -> V_87 > 0 ) {
if ( F_33 ( V_84 ,
V_97 -> V_85 + V_86 ) ) {
V_97 -> V_87 -- ;
F_80 ( V_63 ) ;
} else
V_97 -> V_87 = 0 ;
}
V_127 = F_81 ( V_126 ) + V_128 + V_125 -> V_129 . V_165 ;
if ( F_82 ( V_63 ) < V_127 || F_83 ( V_63 ) ||
( F_84 ( V_63 ) && ! F_85 ( V_63 , 0 ) ) ) {
struct V_62 * V_166 = F_86 ( V_63 , V_127 ) ;
if ( V_127 > V_3 -> V_167 )
V_3 -> V_167 = V_127 ;
if ( ! V_166 ) {
F_74 ( V_125 ) ;
V_3 -> V_12 . V_168 ++ ;
F_87 ( V_63 ) ;
return V_169 ;
}
if ( V_63 -> V_170 )
F_88 ( V_166 , V_63 -> V_170 ) ;
F_87 ( V_63 ) ;
V_63 = V_166 ;
V_92 = F_38 ( V_63 ) ;
}
F_89 ( V_63 ) ;
F_90 ( V_63 , V_128 ) ;
F_60 ( V_63 ) ;
memset ( & ( F_65 ( V_63 ) -> V_171 ) , 0 , sizeof( F_65 ( V_63 ) -> V_171 ) ) ;
F_65 ( V_63 ) -> V_39 &= ~ ( V_172 | V_173 |
V_174 ) ;
F_91 ( V_63 ) ;
F_92 ( V_63 , & V_125 -> V_129 ) ;
V_35 = F_38 ( V_63 ) ;
V_35 -> V_175 = 4 ;
V_35 -> V_68 = sizeof( struct V_65 ) >> 2 ;
V_35 -> V_150 = V_123 ;
V_35 -> V_89 = V_176 ;
V_35 -> V_88 = F_41 ( V_88 , V_92 , V_63 ) ;
V_35 -> V_37 = V_122 . V_37 ;
V_35 -> V_36 = V_122 . V_36 ;
if ( ( V_35 -> V_83 = V_120 -> V_83 ) == 0 ) {
if ( V_63 -> V_89 == F_8 ( V_90 ) )
V_35 -> V_83 = V_92 -> V_83 ;
#if F_67 ( V_135 )
else if ( V_63 -> V_89 == F_8 ( V_91 ) )
V_35 -> V_83 = ( ( const struct V_94 * ) V_92 ) -> V_177 ;
#endif
else
V_35 -> V_83 = F_93 ( & V_125 -> V_129 ) ;
}
( ( T_2 * ) ( V_35 + 1 ) ) [ 0 ] = V_97 -> V_34 . V_58 ;
( ( T_2 * ) ( V_35 + 1 ) ) [ 1 ] = ( V_3 -> type == V_30 ) ?
F_8 ( V_29 ) : V_63 -> V_89 ;
if ( V_97 -> V_34 . V_58 & ( V_72 | V_71 | V_59 ) ) {
T_1 * V_178 = ( T_1 * ) ( ( ( T_5 * ) V_35 ) + V_97 -> V_131 - 4 ) ;
if ( V_97 -> V_34 . V_58 & V_59 ) {
++ V_97 -> V_179 ;
* V_178 = F_77 ( V_97 -> V_179 ) ;
V_178 -- ;
}
if ( V_97 -> V_34 . V_58 & V_72 ) {
* V_178 = V_97 -> V_34 . V_147 ;
V_178 -- ;
}
if ( V_97 -> V_34 . V_58 & V_71 ) {
* V_178 = 0 ;
* ( T_6 * ) V_178 = F_94 ( ( void * ) ( V_35 + 1 ) , V_63 -> V_119 - sizeof( struct V_65 ) ) ;
}
}
F_95 ( V_63 ) ;
V_7 = F_58 ( V_3 -> V_7 ) ;
F_96 ( V_7 , & V_3 -> V_12 ) ;
return V_169 ;
#if F_67 ( V_135 )
V_146:
F_80 ( V_63 ) ;
#endif
V_133:
V_3 -> V_12 . V_180 ++ ;
F_87 ( V_63 ) ;
return V_169 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_2 * V_126 = NULL ;
struct V_13 * V_97 ;
const struct V_65 * V_35 ;
int V_131 = V_181 ;
int V_56 = V_182 ;
int V_183 = sizeof( struct V_65 ) + 4 ;
V_97 = F_11 ( V_3 ) ;
V_35 = & V_97 -> V_34 . V_35 ;
if ( V_35 -> V_37 ) {
struct V_121 V_122 ;
struct V_124 * V_125 ;
V_125 = F_71 ( F_5 ( V_3 ) , & V_122 ,
V_35 -> V_37 , V_35 -> V_36 ,
V_97 -> V_34 . V_147 ,
F_72 ( V_35 -> V_88 ) ,
V_97 -> V_34 . V_19 ) ;
if ( ! F_73 ( V_125 ) ) {
V_126 = V_125 -> V_129 . V_3 ;
F_74 ( V_125 ) ;
}
if ( V_3 -> type != V_30 )
V_3 -> V_39 |= V_184 ;
}
if ( ! V_126 && V_97 -> V_34 . V_19 )
V_126 = F_97 ( F_5 ( V_3 ) , V_97 -> V_34 . V_19 ) ;
if ( V_126 ) {
V_131 = V_126 -> V_151 + V_126 -> V_167 ;
V_56 = V_126 -> V_56 ;
}
V_3 -> V_185 = V_97 -> V_34 . V_19 ;
if ( V_97 -> V_34 . V_58 & ( V_71 | V_72 | V_59 ) ) {
if ( V_97 -> V_34 . V_58 & V_71 )
V_183 += 4 ;
if ( V_97 -> V_34 . V_58 & V_72 )
V_183 += 4 ;
if ( V_97 -> V_34 . V_58 & V_59 )
V_183 += 4 ;
}
V_3 -> V_167 = V_183 + V_131 ;
V_56 -= V_3 -> V_151 + V_183 ;
if ( V_56 < 68 )
V_56 = 68 ;
V_97 -> V_131 = V_183 ;
return V_56 ;
}
static int
F_98 ( struct V_2 * V_3 , struct V_186 * V_187 , int V_188 )
{
int V_189 = 0 ;
struct V_42 V_67 ;
struct V_13 * V_23 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
switch ( V_188 ) {
case V_190 :
V_23 = NULL ;
if ( V_3 == V_26 -> V_41 ) {
if ( F_99 ( & V_67 , V_187 -> V_191 . V_192 , sizeof( V_67 ) ) ) {
V_189 = - V_193 ;
break;
}
V_23 = F_19 ( V_18 , & V_67 , 0 ) ;
}
if ( V_23 == NULL )
V_23 = F_11 ( V_3 ) ;
memcpy ( & V_67 , & V_23 -> V_34 , sizeof( V_67 ) ) ;
if ( F_100 ( V_187 -> V_191 . V_192 , & V_67 , sizeof( V_67 ) ) )
V_189 = - V_193 ;
break;
case V_194 :
case V_195 :
V_189 = - V_196 ;
if ( ! F_101 ( V_197 ) )
goto V_198;
V_189 = - V_193 ;
if ( F_99 ( & V_67 , V_187 -> V_191 . V_192 , sizeof( V_67 ) ) )
goto V_198;
V_189 = - V_199 ;
if ( V_67 . V_35 . V_175 != 4 || V_67 . V_35 . V_89 != V_176 ||
V_67 . V_35 . V_68 != 5 || ( V_67 . V_35 . V_150 & F_8 ( ~ V_154 ) ) ||
( ( V_67 . V_111 | V_67 . V_58 ) & ( V_74 | V_73 ) ) )
goto V_198;
if ( V_67 . V_35 . V_83 )
V_67 . V_35 . V_150 |= F_8 ( V_154 ) ;
if ( ! ( V_67 . V_111 & V_72 ) )
V_67 . V_38 = 0 ;
if ( ! ( V_67 . V_58 & V_72 ) )
V_67 . V_147 = 0 ;
V_23 = F_19 ( V_18 , & V_67 , V_188 == V_194 ) ;
if ( V_3 != V_26 -> V_41 && V_188 == V_195 ) {
if ( V_23 != NULL ) {
if ( V_23 -> V_3 != V_3 ) {
V_189 = - V_200 ;
break;
}
} else {
unsigned int V_201 = 0 ;
V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_67 . V_35 . V_37 ) )
V_201 = V_202 ;
else if ( V_67 . V_35 . V_37 )
V_201 = V_184 ;
if ( ( V_3 -> V_39 ^ V_201 ) & ( V_184 | V_202 ) ) {
V_189 = - V_199 ;
break;
}
F_17 ( V_26 , V_23 ) ;
F_102 () ;
V_23 -> V_34 . V_35 . V_36 = V_67 . V_35 . V_36 ;
V_23 -> V_34 . V_35 . V_37 = V_67 . V_35 . V_37 ;
V_23 -> V_34 . V_38 = V_67 . V_38 ;
V_23 -> V_34 . V_147 = V_67 . V_147 ;
memcpy ( V_3 -> V_203 , & V_67 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_204 , & V_67 . V_35 . V_37 , 4 ) ;
F_14 ( V_26 , V_23 ) ;
F_103 ( V_3 ) ;
}
}
if ( V_23 ) {
V_189 = 0 ;
if ( V_188 == V_195 ) {
V_23 -> V_34 . V_35 . V_83 = V_67 . V_35 . V_83 ;
V_23 -> V_34 . V_35 . V_88 = V_67 . V_35 . V_88 ;
V_23 -> V_34 . V_35 . V_150 = V_67 . V_35 . V_150 ;
if ( V_23 -> V_34 . V_19 != V_67 . V_19 ) {
V_23 -> V_34 . V_19 = V_67 . V_19 ;
V_3 -> V_56 = F_23 ( V_3 ) ;
F_103 ( V_3 ) ;
}
}
if ( F_100 ( V_187 -> V_191 . V_192 , & V_23 -> V_34 , sizeof( V_67 ) ) )
V_189 = - V_193 ;
} else
V_189 = ( V_188 == V_194 ? - V_205 : - V_206 ) ;
break;
case V_207 :
V_189 = - V_196 ;
if ( ! F_101 ( V_197 ) )
goto V_198;
if ( V_3 == V_26 -> V_41 ) {
V_189 = - V_193 ;
if ( F_99 ( & V_67 , V_187 -> V_191 . V_192 , sizeof( V_67 ) ) )
goto V_198;
V_189 = - V_206 ;
if ( ( V_23 = F_19 ( V_18 , & V_67 , 0 ) ) == NULL )
goto V_198;
V_189 = - V_196 ;
if ( V_23 == F_11 ( V_26 -> V_41 ) )
goto V_198;
V_3 = V_23 -> V_3 ;
}
F_104 ( V_3 ) ;
V_189 = 0 ;
break;
default:
V_189 = - V_199 ;
}
V_198:
return V_189 ;
}
static int F_105 ( struct V_2 * V_3 , int V_208 )
{
struct V_13 * V_97 = F_11 ( V_3 ) ;
if ( V_208 < 68 ||
V_208 > 0xFFF8 - V_3 -> V_151 - V_97 -> V_131 )
return - V_199 ;
V_3 -> V_56 = V_208 ;
return 0 ;
}
static int F_106 ( struct V_62 * V_63 , struct V_2 * V_3 ,
unsigned short type ,
const void * V_37 , const void * V_36 , unsigned int V_119 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
struct V_65 * V_35 = (struct V_65 * ) F_90 ( V_63 , V_23 -> V_131 ) ;
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
static int F_107 ( const struct V_62 * V_63 , unsigned char * V_209 )
{
const struct V_65 * V_35 = ( const struct V_65 * ) F_108 ( V_63 ) ;
memcpy ( V_209 , & V_35 -> V_36 , 4 ) ;
return 4 ;
}
static int F_109 ( struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_23 -> V_34 . V_35 . V_37 ) ) {
struct V_121 V_122 ;
struct V_124 * V_125 ;
V_125 = F_71 ( F_5 ( V_3 ) , & V_122 ,
V_23 -> V_34 . V_35 . V_37 ,
V_23 -> V_34 . V_35 . V_36 ,
V_23 -> V_34 . V_147 ,
F_72 ( V_23 -> V_34 . V_35 . V_88 ) ,
V_23 -> V_34 . V_19 ) ;
if ( F_73 ( V_125 ) )
return - V_210 ;
V_3 = V_125 -> V_129 . V_3 ;
F_74 ( V_125 ) ;
if ( F_110 ( V_3 ) == NULL )
return - V_210 ;
V_23 -> V_211 = V_3 -> V_20 ;
F_111 ( F_110 ( V_3 ) , V_23 -> V_34 . V_35 . V_37 ) ;
}
return 0 ;
}
static int F_112 ( struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
if ( F_10 ( V_23 -> V_34 . V_35 . V_37 ) && V_23 -> V_211 ) {
struct V_212 * V_213 ;
V_213 = F_113 ( F_5 ( V_3 ) , V_23 -> V_211 ) ;
if ( V_213 )
F_114 ( V_213 , V_23 -> V_34 . V_35 . V_37 ) ;
}
return 0 ;
}
static void F_115 ( struct V_2 * V_3 )
{
F_116 ( V_3 -> V_7 ) ;
F_26 ( V_3 ) ;
}
static void V_53 ( struct V_2 * V_3 )
{
V_3 -> V_214 = & V_215 ;
V_3 -> V_216 = F_115 ;
V_3 -> type = V_31 ;
V_3 -> V_167 = V_181 + sizeof( struct V_65 ) + 4 ;
V_3 -> V_56 = V_182 - sizeof( struct V_65 ) - 4 ;
V_3 -> V_39 = V_217 ;
V_3 -> V_185 = 0 ;
V_3 -> V_218 = 4 ;
V_3 -> V_60 |= V_219 ;
V_3 -> V_220 &= ~ V_221 ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_13 * V_97 ;
struct V_65 * V_35 ;
V_97 = F_11 ( V_3 ) ;
V_35 = & V_97 -> V_34 . V_35 ;
V_97 -> V_3 = V_3 ;
strcpy ( V_97 -> V_34 . V_51 , V_3 -> V_51 ) ;
memcpy ( V_3 -> V_203 , & V_97 -> V_34 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_204 , & V_97 -> V_34 . V_35 . V_37 , 4 ) ;
if ( V_35 -> V_37 ) {
#ifdef F_53
if ( F_10 ( V_35 -> V_37 ) ) {
if ( ! V_35 -> V_36 )
return - V_199 ;
V_3 -> V_39 = V_202 ;
V_3 -> V_130 = & V_222 ;
}
#endif
} else
V_3 -> V_130 = & V_222 ;
V_3 -> V_7 = F_118 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_223 ;
return 0 ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_13 * V_97 = F_11 ( V_3 ) ;
struct V_65 * V_35 = & V_97 -> V_34 . V_35 ;
V_97 -> V_3 = V_3 ;
strcpy ( V_97 -> V_34 . V_51 , V_3 -> V_51 ) ;
V_35 -> V_175 = 4 ;
V_35 -> V_89 = V_176 ;
V_35 -> V_68 = 5 ;
V_97 -> V_131 = sizeof( struct V_65 ) + 4 ;
F_25 ( V_3 ) ;
}
static void F_120 ( struct V_25 * V_26 , struct V_224 * V_225 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 4 ; V_44 ++ ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_226 ; V_43 ++ ) {
struct V_13 * V_23 ;
V_23 = F_16 ( V_26 -> V_45 [ V_44 ] [ V_43 ] ) ;
while ( V_23 != NULL ) {
F_121 ( V_23 -> V_3 , V_225 ) ;
V_23 = F_16 ( V_23 -> V_47 ) ;
}
}
}
}
static int T_8 F_122 ( struct V_18 * V_18 )
{
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
int V_189 ;
V_26 -> V_41 = F_21 ( sizeof( struct V_13 ) , L_2 ,
V_53 ) ;
if ( ! V_26 -> V_41 ) {
V_189 = - V_223 ;
goto V_227;
}
F_22 ( V_26 -> V_41 , V_18 ) ;
F_119 ( V_26 -> V_41 ) ;
V_26 -> V_41 -> V_54 = & V_55 ;
if ( ( V_189 = F_123 ( V_26 -> V_41 ) ) )
goto V_228;
F_15 ( V_26 -> V_229 [ 0 ] ,
F_11 ( V_26 -> V_41 ) ) ;
return 0 ;
V_228:
F_115 ( V_26 -> V_41 ) ;
V_227:
return V_189 ;
}
static void T_9 F_124 ( struct V_18 * V_18 )
{
struct V_25 * V_26 ;
F_125 ( V_230 ) ;
V_26 = F_7 ( V_18 , V_27 ) ;
F_126 () ;
F_120 ( V_26 , & V_230 ) ;
F_127 ( & V_230 ) ;
F_128 () ;
}
static int F_129 ( struct V_231 * V_232 [] , struct V_231 * V_66 [] )
{
T_2 V_39 ;
if ( ! V_66 )
return 0 ;
V_39 = 0 ;
if ( V_66 [ V_233 ] )
V_39 |= F_130 ( V_66 [ V_233 ] ) ;
if ( V_66 [ V_234 ] )
V_39 |= F_130 ( V_66 [ V_234 ] ) ;
if ( V_39 & ( V_74 | V_73 ) )
return - V_199 ;
return 0 ;
}
static int F_131 ( struct V_231 * V_232 [] , struct V_231 * V_66 [] )
{
T_1 V_37 ;
if ( V_232 [ V_235 ] ) {
if ( F_132 ( V_232 [ V_235 ] ) != V_236 )
return - V_199 ;
if ( ! F_133 ( F_134 ( V_232 [ V_235 ] ) ) )
return - V_210 ;
}
if ( ! V_66 )
goto V_82;
if ( V_66 [ V_237 ] ) {
memcpy ( & V_37 , F_134 ( V_66 [ V_237 ] ) , 4 ) ;
if ( ! V_37 )
return - V_199 ;
}
V_82:
return F_129 ( V_232 , V_66 ) ;
}
static void F_135 ( struct V_231 * V_66 [] ,
struct V_42 * V_34 )
{
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_35 . V_89 = V_176 ;
if ( ! V_66 )
return;
if ( V_66 [ V_238 ] )
V_34 -> V_19 = F_136 ( V_66 [ V_238 ] ) ;
if ( V_66 [ V_233 ] )
V_34 -> V_111 = F_130 ( V_66 [ V_233 ] ) ;
if ( V_66 [ V_234 ] )
V_34 -> V_58 = F_130 ( V_66 [ V_234 ] ) ;
if ( V_66 [ V_239 ] )
V_34 -> V_38 = F_137 ( V_66 [ V_239 ] ) ;
if ( V_66 [ V_240 ] )
V_34 -> V_147 = F_137 ( V_66 [ V_240 ] ) ;
if ( V_66 [ V_241 ] )
V_34 -> V_35 . V_36 = F_137 ( V_66 [ V_241 ] ) ;
if ( V_66 [ V_237 ] )
V_34 -> V_35 . V_37 = F_137 ( V_66 [ V_237 ] ) ;
if ( V_66 [ V_242 ] )
V_34 -> V_35 . V_83 = F_138 ( V_66 [ V_242 ] ) ;
if ( V_66 [ V_243 ] )
V_34 -> V_35 . V_88 = F_138 ( V_66 [ V_243 ] ) ;
if ( ! V_66 [ V_244 ] || F_138 ( V_66 [ V_244 ] ) )
V_34 -> V_35 . V_150 = F_8 ( V_154 ) ;
}
static int F_139 ( struct V_2 * V_3 )
{
struct V_13 * V_97 ;
V_97 = F_11 ( V_3 ) ;
V_97 -> V_3 = V_3 ;
strcpy ( V_97 -> V_34 . V_51 , V_3 -> V_51 ) ;
F_23 ( V_3 ) ;
V_3 -> V_7 = F_118 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_223 ;
return 0 ;
}
static void F_140 ( struct V_2 * V_3 )
{
F_141 ( V_3 ) ;
V_3 -> V_214 = & V_245 ;
V_3 -> V_216 = F_115 ;
V_3 -> V_185 = 0 ;
V_3 -> V_60 |= V_219 ;
}
static int F_142 ( struct V_18 * V_246 , struct V_2 * V_3 , struct V_231 * V_232 [] ,
struct V_231 * V_66 [] )
{
struct V_13 * V_50 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
int V_56 ;
int V_189 ;
V_50 = F_11 ( V_3 ) ;
F_135 ( V_66 , & V_50 -> V_34 ) ;
if ( F_18 ( V_18 , & V_50 -> V_34 , V_3 -> type ) )
return - V_200 ;
if ( V_3 -> type == V_30 && ! V_232 [ V_235 ] )
F_143 ( V_3 ) ;
V_56 = F_23 ( V_3 ) ;
if ( ! V_232 [ V_247 ] )
V_3 -> V_56 = V_56 ;
if ( ! ( V_50 -> V_34 . V_58 & V_59 ) )
V_3 -> V_60 |= V_61 ;
V_189 = F_24 ( V_3 ) ;
if ( V_189 )
goto V_82;
F_25 ( V_3 ) ;
F_14 ( V_26 , V_50 ) ;
V_82:
return V_189 ;
}
static int F_144 ( struct V_2 * V_3 , struct V_231 * V_232 [] ,
struct V_231 * V_66 [] )
{
struct V_13 * V_23 , * V_50 ;
struct V_18 * V_18 = F_5 ( V_3 ) ;
struct V_25 * V_26 = F_7 ( V_18 , V_27 ) ;
struct V_42 V_67 ;
int V_56 ;
if ( V_3 == V_26 -> V_41 )
return - V_199 ;
V_50 = F_11 ( V_3 ) ;
F_135 ( V_66 , & V_67 ) ;
V_23 = F_19 ( V_18 , & V_67 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_3 != V_3 )
return - V_200 ;
} else {
V_23 = V_50 ;
if ( V_3 -> type != V_30 ) {
unsigned int V_201 = 0 ;
if ( F_10 ( V_67 . V_35 . V_37 ) )
V_201 = V_202 ;
else if ( V_67 . V_35 . V_37 )
V_201 = V_184 ;
if ( ( V_3 -> V_39 ^ V_201 ) &
( V_184 | V_202 ) )
return - V_199 ;
}
F_17 ( V_26 , V_23 ) ;
V_23 -> V_34 . V_35 . V_36 = V_67 . V_35 . V_36 ;
V_23 -> V_34 . V_35 . V_37 = V_67 . V_35 . V_37 ;
V_23 -> V_34 . V_38 = V_67 . V_38 ;
if ( V_3 -> type != V_30 ) {
memcpy ( V_3 -> V_203 , & V_67 . V_35 . V_36 , 4 ) ;
memcpy ( V_3 -> V_204 , & V_67 . V_35 . V_37 , 4 ) ;
}
F_14 ( V_26 , V_23 ) ;
F_103 ( V_3 ) ;
}
V_23 -> V_34 . V_147 = V_67 . V_147 ;
V_23 -> V_34 . V_35 . V_83 = V_67 . V_35 . V_83 ;
V_23 -> V_34 . V_35 . V_88 = V_67 . V_35 . V_88 ;
V_23 -> V_34 . V_35 . V_150 = V_67 . V_35 . V_150 ;
if ( V_23 -> V_34 . V_19 != V_67 . V_19 ) {
V_23 -> V_34 . V_19 = V_67 . V_19 ;
V_56 = F_23 ( V_3 ) ;
if ( ! V_232 [ V_247 ] )
V_3 -> V_56 = V_56 ;
F_103 ( V_3 ) ;
}
return 0 ;
}
static T_10 F_145 ( const struct V_2 * V_3 )
{
return
F_146 ( 4 ) +
F_146 ( 2 ) +
F_146 ( 2 ) +
F_146 ( 4 ) +
F_146 ( 4 ) +
F_146 ( 4 ) +
F_146 ( 4 ) +
F_146 ( 1 ) +
F_146 ( 1 ) +
F_146 ( 1 ) +
0 ;
}
static int F_147 ( struct V_62 * V_63 , const struct V_2 * V_3 )
{
struct V_13 * V_23 = F_11 ( V_3 ) ;
struct V_42 * V_67 = & V_23 -> V_34 ;
F_148 ( V_63 , V_238 , V_67 -> V_19 ) ;
F_149 ( V_63 , V_233 , V_67 -> V_111 ) ;
F_149 ( V_63 , V_234 , V_67 -> V_58 ) ;
F_150 ( V_63 , V_239 , V_67 -> V_38 ) ;
F_150 ( V_63 , V_240 , V_67 -> V_147 ) ;
F_150 ( V_63 , V_241 , V_67 -> V_35 . V_36 ) ;
F_150 ( V_63 , V_237 , V_67 -> V_35 . V_37 ) ;
F_151 ( V_63 , V_242 , V_67 -> V_35 . V_83 ) ;
F_151 ( V_63 , V_243 , V_67 -> V_35 . V_88 ) ;
F_151 ( V_63 , V_244 , ! ! ( V_67 -> V_35 . V_150 & F_8 ( V_154 ) ) ) ;
return 0 ;
V_248:
return - V_249 ;
}
static int T_11 F_152 ( void )
{
int V_189 ;
F_153 ( L_3 ) ;
V_189 = F_154 ( & V_250 ) ;
if ( V_189 < 0 )
return V_189 ;
V_189 = F_155 ( & V_251 , V_252 ) ;
if ( V_189 < 0 ) {
F_153 ( L_4 , V_253 ) ;
goto V_254;
}
V_189 = F_156 ( & V_55 ) ;
if ( V_189 < 0 )
goto V_255;
V_189 = F_156 ( & V_256 ) ;
if ( V_189 < 0 )
goto V_257;
V_82:
return V_189 ;
V_257:
F_157 ( & V_55 ) ;
V_255:
F_158 ( & V_251 , V_252 ) ;
V_254:
F_159 ( & V_250 ) ;
goto V_82;
}
static void T_12 F_160 ( void )
{
F_157 ( & V_256 ) ;
F_157 ( & V_55 ) ;
if ( F_158 ( & V_251 , V_252 ) < 0 )
F_153 ( L_5 , V_253 ) ;
F_159 ( & V_250 ) ;
}
