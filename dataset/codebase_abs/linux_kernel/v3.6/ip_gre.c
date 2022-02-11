static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_5 ;
F_2 (i) {
const struct V_6 * V_7 = F_3 ( V_3 -> V_7 , V_5 ) ;
T_1 V_8 , V_9 , V_10 , V_11 ;
unsigned int V_12 ;
do {
V_12 = F_4 ( & V_7 -> V_13 ) ;
V_8 = V_7 -> V_8 ;
V_10 = V_7 -> V_10 ;
V_9 = V_7 -> V_9 ;
V_11 = V_7 -> V_11 ;
} while ( F_5 ( & V_7 -> V_13 , V_12 ) );
V_4 -> V_8 += V_8 ;
V_4 -> V_10 += V_10 ;
V_4 -> V_9 += V_9 ;
V_4 -> V_11 += V_11 ;
}
V_4 -> V_14 = V_3 -> V_15 . V_14 ;
V_4 -> V_16 = V_3 -> V_15 . V_16 ;
V_4 -> V_17 = V_3 -> V_15 . V_17 ;
V_4 -> V_18 = V_3 -> V_15 . V_18 ;
V_4 -> V_19 = V_3 -> V_15 . V_19 ;
V_4 -> V_20 = V_3 -> V_15 . V_20 ;
V_4 -> V_21 = V_3 -> V_15 . V_21 ;
V_4 -> V_22 = V_3 -> V_15 . V_22 ;
V_4 -> V_23 = V_3 -> V_15 . V_23 ;
V_4 -> V_24 = V_3 -> V_15 . V_24 ;
return V_4 ;
}
static struct V_25 * F_6 ( struct V_2 * V_3 ,
T_2 V_26 , T_2 V_27 ,
T_2 V_28 , T_3 V_29 )
{
struct V_30 * V_30 = F_7 ( V_3 ) ;
int V_31 = V_3 -> V_32 ;
unsigned int V_33 = F_8 ( V_26 ) ;
unsigned int V_34 = F_8 ( V_28 ) ;
struct V_25 * V_35 , * V_36 = NULL ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
int V_40 = ( V_29 == F_10 ( V_41 ) ) ?
V_42 : V_43 ;
int V_44 , V_45 = 4 ;
F_11 (ign->tunnels_r_l[h0 ^ h1]) {
if ( V_27 != V_35 -> V_46 . V_47 . V_48 ||
V_26 != V_35 -> V_46 . V_47 . V_49 ||
V_28 != V_35 -> V_46 . V_50 ||
! ( V_35 -> V_3 -> V_51 & V_52 ) )
continue;
if ( V_35 -> V_3 -> type != V_43 &&
V_35 -> V_3 -> type != V_40 )
continue;
V_44 = 0 ;
if ( V_35 -> V_46 . V_31 != V_31 )
V_44 |= 1 ;
if ( V_35 -> V_3 -> type != V_40 )
V_44 |= 2 ;
if ( V_44 == 0 )
return V_35 ;
if ( V_44 < V_45 ) {
V_36 = V_35 ;
V_45 = V_44 ;
}
}
F_11 (ign->tunnels_r[h0 ^ h1]) {
if ( V_26 != V_35 -> V_46 . V_47 . V_49 ||
V_28 != V_35 -> V_46 . V_50 ||
! ( V_35 -> V_3 -> V_51 & V_52 ) )
continue;
if ( V_35 -> V_3 -> type != V_43 &&
V_35 -> V_3 -> type != V_40 )
continue;
V_44 = 0 ;
if ( V_35 -> V_46 . V_31 != V_31 )
V_44 |= 1 ;
if ( V_35 -> V_3 -> type != V_40 )
V_44 |= 2 ;
if ( V_44 == 0 )
return V_35 ;
if ( V_44 < V_45 ) {
V_36 = V_35 ;
V_45 = V_44 ;
}
}
F_11 (ign->tunnels_l[h1]) {
if ( ( V_27 != V_35 -> V_46 . V_47 . V_48 &&
( V_27 != V_35 -> V_46 . V_47 . V_49 ||
! F_12 ( V_27 ) ) ) ||
V_28 != V_35 -> V_46 . V_50 ||
! ( V_35 -> V_3 -> V_51 & V_52 ) )
continue;
if ( V_35 -> V_3 -> type != V_43 &&
V_35 -> V_3 -> type != V_40 )
continue;
V_44 = 0 ;
if ( V_35 -> V_46 . V_31 != V_31 )
V_44 |= 1 ;
if ( V_35 -> V_3 -> type != V_40 )
V_44 |= 2 ;
if ( V_44 == 0 )
return V_35 ;
if ( V_44 < V_45 ) {
V_36 = V_35 ;
V_45 = V_44 ;
}
}
F_11 (ign->tunnels_wc[h1]) {
if ( V_35 -> V_46 . V_50 != V_28 ||
! ( V_35 -> V_3 -> V_51 & V_52 ) )
continue;
if ( V_35 -> V_3 -> type != V_43 &&
V_35 -> V_3 -> type != V_40 )
continue;
V_44 = 0 ;
if ( V_35 -> V_46 . V_31 != V_31 )
V_44 |= 1 ;
if ( V_35 -> V_3 -> type != V_40 )
V_44 |= 2 ;
if ( V_44 == 0 )
return V_35 ;
if ( V_44 < V_45 ) {
V_36 = V_35 ;
V_45 = V_44 ;
}
}
if ( V_36 != NULL )
return V_36 ;
V_3 = V_38 -> V_53 ;
if ( V_3 -> V_51 & V_52 )
return F_13 ( V_3 ) ;
return NULL ;
}
static struct V_25 T_4 * * F_14 ( struct V_37 * V_38 ,
struct V_54 * V_46 )
{
T_2 V_26 = V_46 -> V_47 . V_49 ;
T_2 V_27 = V_46 -> V_47 . V_48 ;
T_2 V_28 = V_46 -> V_50 ;
unsigned int V_55 = F_8 ( V_28 ) ;
int V_56 = 0 ;
if ( V_27 )
V_56 |= 1 ;
if ( V_26 && ! F_12 ( V_26 ) ) {
V_56 |= 2 ;
V_55 ^= F_8 ( V_26 ) ;
}
return & V_38 -> V_57 [ V_56 ] [ V_55 ] ;
}
static inline struct V_25 T_4 * * F_15 ( struct V_37 * V_38 ,
struct V_25 * V_35 )
{
return F_14 ( V_38 , & V_35 -> V_46 ) ;
}
static void F_16 ( struct V_37 * V_38 , struct V_25 * V_35 )
{
struct V_25 T_4 * * V_58 = F_15 ( V_38 , V_35 ) ;
F_17 ( V_35 -> V_59 , F_18 ( * V_58 ) ) ;
F_17 ( * V_58 , V_35 ) ;
}
static void F_19 ( struct V_37 * V_38 , struct V_25 * V_35 )
{
struct V_25 T_4 * * V_58 ;
struct V_25 * V_60 ;
for ( V_58 = F_15 ( V_38 , V_35 ) ;
( V_60 = F_18 ( * V_58 ) ) != NULL ;
V_58 = & V_60 -> V_59 ) {
if ( V_35 == V_60 ) {
F_17 ( * V_58 , V_35 -> V_59 ) ;
break;
}
}
}
static struct V_25 * F_20 ( struct V_30 * V_30 ,
struct V_54 * V_46 ,
int type )
{
T_2 V_26 = V_46 -> V_47 . V_49 ;
T_2 V_27 = V_46 -> V_47 . V_48 ;
T_2 V_28 = V_46 -> V_50 ;
int V_31 = V_46 -> V_31 ;
struct V_25 * V_35 ;
struct V_25 T_4 * * V_58 ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
for ( V_58 = F_14 ( V_38 , V_46 ) ;
( V_35 = F_18 ( * V_58 ) ) != NULL ;
V_58 = & V_35 -> V_59 )
if ( V_27 == V_35 -> V_46 . V_47 . V_48 &&
V_26 == V_35 -> V_46 . V_47 . V_49 &&
V_28 == V_35 -> V_46 . V_50 &&
V_31 == V_35 -> V_46 . V_31 &&
type == V_35 -> V_3 -> type )
break;
return V_35 ;
}
static struct V_25 * F_21 ( struct V_30 * V_30 ,
struct V_54 * V_46 , int V_61 )
{
struct V_25 * V_35 , * V_62 ;
struct V_2 * V_3 ;
char V_63 [ V_64 ] ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
V_35 = F_20 ( V_30 , V_46 , V_43 ) ;
if ( V_35 || ! V_61 )
return V_35 ;
if ( V_46 -> V_63 [ 0 ] )
F_22 ( V_63 , V_46 -> V_63 , V_64 ) ;
else
strcpy ( V_63 , L_1 ) ;
V_3 = F_23 ( sizeof( * V_35 ) , V_63 , V_65 ) ;
if ( ! V_3 )
return NULL ;
F_24 ( V_3 , V_30 ) ;
V_62 = F_13 ( V_3 ) ;
V_62 -> V_46 = * V_46 ;
V_3 -> V_66 = & V_67 ;
V_3 -> V_68 = F_25 ( V_3 ) ;
if ( F_26 ( V_3 ) < 0 )
goto V_69;
if ( ! ( V_62 -> V_46 . V_70 & V_71 ) )
V_3 -> V_72 |= V_73 ;
F_27 ( V_3 ) ;
F_16 ( V_38 , V_62 ) ;
return V_62 ;
V_69:
F_28 ( V_3 ) ;
return NULL ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_30 * V_30 = F_7 ( V_3 ) ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
F_19 ( V_38 , F_13 ( V_3 ) ) ;
F_30 ( V_3 ) ;
}
static void F_31 ( struct V_74 * V_75 , T_5 V_76 )
{
const struct V_77 * V_47 = ( const struct V_77 * ) V_75 -> V_78 ;
T_3 * V_79 = ( T_3 * ) ( V_75 -> V_78 + ( V_47 -> V_80 << 2 ) ) ;
int V_81 = ( V_47 -> V_80 << 2 ) + 4 ;
const int type = F_32 ( V_75 ) -> type ;
const int V_82 = F_32 ( V_75 ) -> V_82 ;
struct V_25 * V_35 ;
T_3 V_51 ;
V_51 = V_79 [ 0 ] ;
if ( V_51 & ( V_83 | V_84 | V_71 | V_85 | V_86 ) ) {
if ( V_51 & ( V_86 | V_85 ) )
return;
if ( V_51 & V_84 ) {
V_81 += 4 ;
if ( V_51 & V_83 )
V_81 += 4 ;
}
}
if ( F_33 ( V_75 ) < V_81 )
return;
switch ( type ) {
default:
case V_87 :
return;
case V_88 :
switch ( V_82 ) {
case V_89 :
case V_90 :
return;
default:
break;
}
break;
case V_91 :
if ( V_82 != V_92 )
return;
break;
case V_93 :
break;
}
F_34 () ;
V_35 = F_6 ( V_75 -> V_3 , V_47 -> V_49 , V_47 -> V_48 ,
V_51 & V_84 ?
* ( ( ( T_2 * ) V_79 ) + ( V_81 / 4 ) - 1 ) : 0 ,
V_79 [ 1 ] ) ;
if ( V_35 == NULL )
goto V_94;
if ( type == V_88 && V_82 == V_95 ) {
F_35 ( V_75 , F_7 ( V_75 -> V_3 ) , V_76 ,
V_35 -> V_46 . V_31 , 0 , V_96 , 0 ) ;
goto V_94;
}
if ( type == V_93 ) {
F_36 ( V_75 , F_7 ( V_75 -> V_3 ) , V_35 -> V_46 . V_31 , 0 ,
V_96 , 0 ) ;
goto V_94;
}
if ( V_35 -> V_46 . V_47 . V_49 == 0 ||
F_12 ( V_35 -> V_46 . V_47 . V_49 ) )
goto V_94;
if ( V_35 -> V_46 . V_47 . V_97 == 0 && type == V_91 )
goto V_94;
if ( F_37 ( V_98 , V_35 -> V_99 + V_100 ) )
V_35 -> V_101 ++ ;
else
V_35 -> V_101 = 1 ;
V_35 -> V_99 = V_98 ;
V_94:
F_38 () ;
}
static inline void F_39 ( const struct V_77 * V_47 , struct V_74 * V_75 )
{
if ( F_40 ( V_47 -> V_102 ) ) {
if ( V_75 -> V_103 == F_10 ( V_104 ) ) {
F_41 ( F_42 ( V_75 ) ) ;
} else if ( V_75 -> V_103 == F_10 ( V_105 ) ) {
F_43 ( F_44 ( V_75 ) ) ;
}
}
}
static inline T_6
F_45 ( T_6 V_102 , const struct V_77 * V_106 , struct V_74 * V_75 )
{
T_6 V_107 = 0 ;
if ( V_75 -> V_103 == F_10 ( V_104 ) )
V_107 = V_106 -> V_102 ;
else if ( V_75 -> V_103 == F_10 ( V_105 ) )
V_107 = F_46 ( ( const struct V_108 * ) V_106 ) ;
return F_47 ( V_102 , V_107 ) ;
}
static int F_48 ( struct V_74 * V_75 )
{
const struct V_77 * V_47 ;
T_6 * V_55 ;
T_3 V_51 ;
T_7 V_109 = 0 ;
T_2 V_28 = 0 ;
T_5 V_110 = 0 ;
struct V_25 * V_111 ;
int V_112 = 4 ;
T_3 V_29 ;
if ( ! F_49 ( V_75 , 16 ) )
goto V_113;
V_47 = F_42 ( V_75 ) ;
V_55 = V_75 -> V_78 ;
V_51 = * ( T_3 * ) V_55 ;
if ( V_51 & ( V_83 | V_84 | V_85 | V_71 | V_86 ) ) {
if ( V_51 & ( V_86 | V_85 ) )
goto V_113;
if ( V_51 & V_83 ) {
switch ( V_75 -> V_114 ) {
case V_115 :
V_109 = F_50 ( V_75 -> V_109 ) ;
if ( ! V_109 )
break;
case V_116 :
V_75 -> V_109 = 0 ;
V_109 = F_51 ( V_75 ) ;
V_75 -> V_114 = V_115 ;
}
V_112 += 4 ;
}
if ( V_51 & V_84 ) {
V_28 = * ( T_2 * ) ( V_55 + V_112 ) ;
V_112 += 4 ;
}
if ( V_51 & V_71 ) {
V_110 = F_52 ( * ( T_2 * ) ( V_55 + V_112 ) ) ;
V_112 += 4 ;
}
}
V_29 = * ( T_3 * ) ( V_55 + 2 ) ;
F_34 () ;
if ( ( V_111 = F_6 ( V_75 -> V_3 ,
V_47 -> V_48 , V_47 -> V_49 , V_28 ,
V_29 ) ) ) {
struct V_6 * V_7 ;
F_53 ( V_75 ) ;
V_75 -> V_103 = V_29 ;
if ( V_51 == 0 && V_29 == F_10 ( V_117 ) ) {
V_75 -> V_103 = F_10 ( V_104 ) ;
if ( ( * ( V_55 + V_112 ) & 0xF0 ) != 0x40 )
V_112 += 4 ;
}
V_75 -> V_118 = V_75 -> V_119 ;
F_54 ( V_75 , V_112 ) ;
F_55 ( V_75 , F_56 ( V_75 ) , V_112 ) ;
V_75 -> V_120 = V_121 ;
#ifdef F_57
if ( F_12 ( V_47 -> V_49 ) ) {
if ( F_58 ( F_59 ( V_75 ) ) )
goto V_122;
V_111 -> V_3 -> V_15 . V_14 ++ ;
V_75 -> V_120 = V_123 ;
}
#endif
if ( ( ( V_51 & V_83 ) && V_109 ) ||
( ! ( V_51 & V_83 ) && V_111 -> V_46 . V_124 & V_83 ) ) {
V_111 -> V_3 -> V_15 . V_16 ++ ;
V_111 -> V_3 -> V_15 . V_19 ++ ;
goto V_122;
}
if ( V_111 -> V_46 . V_124 & V_71 ) {
if ( ! ( V_51 & V_71 ) ||
( V_111 -> V_125 && ( V_126 ) ( V_110 - V_111 -> V_125 ) < 0 ) ) {
V_111 -> V_3 -> V_15 . V_17 ++ ;
V_111 -> V_3 -> V_15 . V_19 ++ ;
goto V_122;
}
V_111 -> V_125 = V_110 + 1 ;
}
if ( V_111 -> V_3 -> type == V_42 ) {
if ( ! F_49 ( V_75 , V_127 ) ) {
V_111 -> V_3 -> V_15 . V_18 ++ ;
V_111 -> V_3 -> V_15 . V_19 ++ ;
goto V_122;
}
V_47 = F_42 ( V_75 ) ;
V_75 -> V_103 = F_60 ( V_75 , V_111 -> V_3 ) ;
F_55 ( V_75 , F_61 ( V_75 ) , V_127 ) ;
}
V_7 = F_62 ( V_111 -> V_3 -> V_7 ) ;
F_63 ( & V_7 -> V_13 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_75 -> V_128 ;
F_64 ( & V_7 -> V_13 ) ;
F_65 ( V_75 , V_111 -> V_3 ) ;
F_66 ( V_75 ) ;
F_39 ( V_47 , V_75 ) ;
F_67 ( V_75 ) ;
F_38 () ;
return 0 ;
}
F_68 ( V_75 , V_88 , V_90 , 0 ) ;
V_122:
F_38 () ;
V_113:
F_69 ( V_75 ) ;
return 0 ;
}
static T_8 F_70 ( struct V_74 * V_75 , struct V_2 * V_3 )
{
struct V_25 * V_111 = F_13 ( V_3 ) ;
struct V_6 * V_7 ;
const struct V_77 * V_106 = F_42 ( V_75 ) ;
const struct V_77 * V_129 ;
struct V_130 V_131 ;
T_6 V_102 ;
T_3 V_132 ;
struct V_133 * V_134 ;
struct V_2 * V_135 ;
struct V_77 * V_47 ;
unsigned int V_136 ;
int V_137 ;
T_2 V_138 ;
int V_68 ;
if ( V_3 -> type == V_42 )
F_71 ( V_75 ) -> V_51 = 0 ;
if ( V_3 -> V_139 && V_3 -> type == V_43 ) {
V_137 = 0 ;
V_129 = ( const struct V_77 * ) V_75 -> V_78 ;
} else {
V_137 = V_111 -> V_140 ;
V_129 = & V_111 -> V_46 . V_47 ;
}
if ( ( V_138 = V_129 -> V_49 ) == 0 ) {
if ( F_72 ( V_75 ) == NULL ) {
V_3 -> V_15 . V_20 ++ ;
goto V_141;
}
if ( V_75 -> V_103 == F_10 ( V_104 ) ) {
V_134 = F_59 ( V_75 ) ;
V_138 = F_73 ( V_134 , V_106 -> V_49 ) ;
}
#if F_74 ( V_142 )
else if ( V_75 -> V_103 == F_10 ( V_105 ) ) {
const struct V_143 * V_144 ;
struct V_145 * V_146 ;
bool V_147 ;
int V_148 ;
V_146 = F_75 ( F_72 ( V_75 ) , & F_44 ( V_75 ) -> V_49 ) ;
if ( V_146 == NULL )
goto V_141;
V_144 = ( const struct V_143 * ) & V_146 -> V_149 ;
V_148 = F_76 ( V_144 ) ;
if ( V_148 == V_150 ) {
V_144 = & F_44 ( V_75 ) -> V_49 ;
V_148 = F_76 ( V_144 ) ;
}
if ( ( V_148 & V_151 ) == 0 )
V_147 = true ;
else {
V_147 = false ;
V_138 = V_144 -> V_152 [ 3 ] ;
}
F_77 ( V_146 ) ;
if ( V_147 )
goto V_153;
}
#endif
else
goto V_141;
}
V_102 = V_129 -> V_102 ;
if ( V_102 == 1 ) {
V_102 = 0 ;
if ( V_75 -> V_103 == F_10 ( V_104 ) )
V_102 = V_106 -> V_102 ;
else if ( V_75 -> V_103 == F_10 ( V_105 ) )
V_102 = F_46 ( ( const struct V_108 * ) V_106 ) ;
}
V_134 = F_78 ( F_7 ( V_3 ) , & V_131 , V_138 , V_129 -> V_48 ,
V_111 -> V_46 . V_154 , F_79 ( V_102 ) ,
V_111 -> V_46 . V_31 ) ;
if ( F_80 ( V_134 ) ) {
V_3 -> V_15 . V_21 ++ ;
goto V_141;
}
V_135 = V_134 -> V_138 . V_3 ;
if ( V_135 == V_3 ) {
F_81 ( V_134 ) ;
V_3 -> V_15 . V_155 ++ ;
goto V_141;
}
V_132 = V_129 -> V_156 ;
if ( V_132 )
V_68 = F_82 ( & V_134 -> V_138 ) - V_3 -> V_157 - V_111 -> V_140 ;
else
V_68 = F_72 ( V_75 ) ? F_82 ( F_72 ( V_75 ) ) : V_3 -> V_68 ;
if ( F_72 ( V_75 ) )
F_72 ( V_75 ) -> V_158 -> V_159 ( F_72 ( V_75 ) , NULL , V_75 , V_68 ) ;
if ( V_75 -> V_103 == F_10 ( V_104 ) ) {
V_132 |= ( V_106 -> V_156 & F_10 ( V_160 ) ) ;
if ( ( V_106 -> V_156 & F_10 ( V_160 ) ) &&
V_68 < F_83 ( V_106 -> V_161 ) ) {
F_68 ( V_75 , V_88 , V_95 , F_84 ( V_68 ) ) ;
F_81 ( V_134 ) ;
goto V_141;
}
}
#if F_74 ( V_142 )
else if ( V_75 -> V_103 == F_10 ( V_105 ) ) {
struct V_162 * V_163 = (struct V_162 * ) F_72 ( V_75 ) ;
if ( V_163 && V_68 < F_82 ( F_72 ( V_75 ) ) && V_68 >= V_164 ) {
if ( ( V_111 -> V_46 . V_47 . V_49 &&
! F_12 ( V_111 -> V_46 . V_47 . V_49 ) ) ||
V_163 -> V_165 . V_166 == 128 ) {
V_163 -> V_167 |= V_168 ;
F_85 ( F_72 ( V_75 ) , V_169 , V_68 ) ;
}
}
if ( V_68 >= V_164 && V_68 < V_75 -> V_128 - V_111 -> V_140 + V_137 ) {
F_86 ( V_75 , V_170 , 0 , V_68 ) ;
F_81 ( V_134 ) ;
goto V_141;
}
}
#endif
if ( V_111 -> V_101 > 0 ) {
if ( F_37 ( V_98 ,
V_111 -> V_99 + V_100 ) ) {
V_111 -> V_101 -- ;
F_87 ( V_75 ) ;
} else
V_111 -> V_101 = 0 ;
}
V_136 = F_88 ( V_135 ) + V_137 + V_134 -> V_138 . V_171 ;
if ( F_89 ( V_75 ) < V_136 || F_90 ( V_75 ) ||
( F_91 ( V_75 ) && ! F_92 ( V_75 , 0 ) ) ) {
struct V_74 * V_172 = F_93 ( V_75 , V_136 ) ;
if ( V_136 > V_3 -> V_173 )
V_3 -> V_173 = V_136 ;
if ( ! V_172 ) {
F_81 ( V_134 ) ;
V_3 -> V_15 . V_22 ++ ;
F_94 ( V_75 ) ;
return V_174 ;
}
if ( V_75 -> V_175 )
F_95 ( V_172 , V_75 -> V_175 ) ;
F_94 ( V_75 ) ;
V_75 = V_172 ;
V_106 = F_42 ( V_75 ) ;
}
F_96 ( V_75 ) ;
F_97 ( V_75 , V_137 ) ;
F_66 ( V_75 ) ;
memset ( & ( F_71 ( V_75 ) -> V_176 ) , 0 , sizeof( F_71 ( V_75 ) -> V_176 ) ) ;
F_71 ( V_75 ) -> V_51 &= ~ ( V_177 | V_178 |
V_179 ) ;
F_98 ( V_75 ) ;
F_99 ( V_75 , & V_134 -> V_138 ) ;
V_47 = F_42 ( V_75 ) ;
V_47 -> V_180 = 4 ;
V_47 -> V_80 = sizeof( struct V_77 ) >> 2 ;
V_47 -> V_156 = V_132 ;
V_47 -> V_103 = V_96 ;
V_47 -> V_102 = F_45 ( V_102 , V_106 , V_75 ) ;
V_47 -> V_49 = V_131 . V_49 ;
V_47 -> V_48 = V_131 . V_48 ;
if ( ( V_47 -> V_97 = V_129 -> V_97 ) == 0 ) {
if ( V_75 -> V_103 == F_10 ( V_104 ) )
V_47 -> V_97 = V_106 -> V_97 ;
#if F_74 ( V_142 )
else if ( V_75 -> V_103 == F_10 ( V_105 ) )
V_47 -> V_97 = ( ( const struct V_108 * ) V_106 ) -> V_181 ;
#endif
else
V_47 -> V_97 = F_100 ( & V_134 -> V_138 ) ;
}
( ( T_3 * ) ( V_47 + 1 ) ) [ 0 ] = V_111 -> V_46 . V_70 ;
( ( T_3 * ) ( V_47 + 1 ) ) [ 1 ] = ( V_3 -> type == V_42 ) ?
F_10 ( V_41 ) : V_75 -> V_103 ;
if ( V_111 -> V_46 . V_70 & ( V_84 | V_83 | V_71 ) ) {
T_2 * V_182 = ( T_2 * ) ( ( ( T_6 * ) V_47 ) + V_111 -> V_140 - 4 ) ;
if ( V_111 -> V_46 . V_70 & V_71 ) {
++ V_111 -> V_183 ;
* V_182 = F_84 ( V_111 -> V_183 ) ;
V_182 -- ;
}
if ( V_111 -> V_46 . V_70 & V_84 ) {
* V_182 = V_111 -> V_46 . V_154 ;
V_182 -- ;
}
if ( V_111 -> V_46 . V_70 & V_83 ) {
* V_182 = 0 ;
* ( T_7 * ) V_182 = F_101 ( ( void * ) ( V_47 + 1 ) , V_75 -> V_128 - sizeof( struct V_77 ) ) ;
}
}
F_102 ( V_75 ) ;
V_7 = F_62 ( V_3 -> V_7 ) ;
F_103 ( V_7 , & V_3 -> V_15 ) ;
return V_174 ;
#if F_74 ( V_142 )
V_153:
F_87 ( V_75 ) ;
#endif
V_141:
V_3 -> V_15 . V_24 ++ ;
F_94 ( V_75 ) ;
return V_174 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_2 * V_135 = NULL ;
struct V_25 * V_111 ;
const struct V_77 * V_47 ;
int V_140 = V_184 ;
int V_68 = V_185 ;
int V_186 = sizeof( struct V_77 ) + 4 ;
V_111 = F_13 ( V_3 ) ;
V_47 = & V_111 -> V_46 . V_47 ;
if ( V_47 -> V_49 ) {
struct V_130 V_131 ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_7 ( V_3 ) , & V_131 ,
V_47 -> V_49 , V_47 -> V_48 ,
V_111 -> V_46 . V_154 ,
F_79 ( V_47 -> V_102 ) ,
V_111 -> V_46 . V_31 ) ;
if ( ! F_80 ( V_134 ) ) {
V_135 = V_134 -> V_138 . V_3 ;
F_81 ( V_134 ) ;
}
if ( V_3 -> type != V_42 )
V_3 -> V_51 |= V_187 ;
}
if ( ! V_135 && V_111 -> V_46 . V_31 )
V_135 = F_104 ( F_7 ( V_3 ) , V_111 -> V_46 . V_31 ) ;
if ( V_135 ) {
V_140 = V_135 -> V_157 + V_135 -> V_173 ;
V_68 = V_135 -> V_68 ;
}
V_3 -> V_188 = V_111 -> V_46 . V_31 ;
if ( V_111 -> V_46 . V_70 & ( V_83 | V_84 | V_71 ) ) {
if ( V_111 -> V_46 . V_70 & V_83 )
V_186 += 4 ;
if ( V_111 -> V_46 . V_70 & V_84 )
V_186 += 4 ;
if ( V_111 -> V_46 . V_70 & V_71 )
V_186 += 4 ;
}
V_3 -> V_173 = V_186 + V_140 ;
V_68 -= V_3 -> V_157 + V_186 ;
if ( V_68 < 68 )
V_68 = 68 ;
V_111 -> V_140 = V_186 ;
return V_68 ;
}
static int
F_105 ( struct V_2 * V_3 , struct V_189 * V_190 , int V_191 )
{
int V_192 = 0 ;
struct V_54 V_79 ;
struct V_25 * V_35 ;
struct V_30 * V_30 = F_7 ( V_3 ) ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
switch ( V_191 ) {
case V_193 :
V_35 = NULL ;
if ( V_3 == V_38 -> V_53 ) {
if ( F_106 ( & V_79 , V_190 -> V_194 . V_195 , sizeof( V_79 ) ) ) {
V_192 = - V_196 ;
break;
}
V_35 = F_21 ( V_30 , & V_79 , 0 ) ;
}
if ( V_35 == NULL )
V_35 = F_13 ( V_3 ) ;
memcpy ( & V_79 , & V_35 -> V_46 , sizeof( V_79 ) ) ;
if ( F_107 ( V_190 -> V_194 . V_195 , & V_79 , sizeof( V_79 ) ) )
V_192 = - V_196 ;
break;
case V_197 :
case V_198 :
V_192 = - V_199 ;
if ( ! F_108 ( V_200 ) )
goto V_201;
V_192 = - V_196 ;
if ( F_106 ( & V_79 , V_190 -> V_194 . V_195 , sizeof( V_79 ) ) )
goto V_201;
V_192 = - V_202 ;
if ( V_79 . V_47 . V_180 != 4 || V_79 . V_47 . V_103 != V_96 ||
V_79 . V_47 . V_80 != 5 || ( V_79 . V_47 . V_156 & F_10 ( ~ V_160 ) ) ||
( ( V_79 . V_124 | V_79 . V_70 ) & ( V_86 | V_85 ) ) )
goto V_201;
if ( V_79 . V_47 . V_97 )
V_79 . V_47 . V_156 |= F_10 ( V_160 ) ;
if ( ! ( V_79 . V_124 & V_84 ) )
V_79 . V_50 = 0 ;
if ( ! ( V_79 . V_70 & V_84 ) )
V_79 . V_154 = 0 ;
V_35 = F_21 ( V_30 , & V_79 , V_191 == V_197 ) ;
if ( V_3 != V_38 -> V_53 && V_191 == V_198 ) {
if ( V_35 != NULL ) {
if ( V_35 -> V_3 != V_3 ) {
V_192 = - V_203 ;
break;
}
} else {
unsigned int V_204 = 0 ;
V_35 = F_13 ( V_3 ) ;
if ( F_12 ( V_79 . V_47 . V_49 ) )
V_204 = V_205 ;
else if ( V_79 . V_47 . V_49 )
V_204 = V_187 ;
if ( ( V_3 -> V_51 ^ V_204 ) & ( V_187 | V_205 ) ) {
V_192 = - V_202 ;
break;
}
F_19 ( V_38 , V_35 ) ;
F_109 () ;
V_35 -> V_46 . V_47 . V_48 = V_79 . V_47 . V_48 ;
V_35 -> V_46 . V_47 . V_49 = V_79 . V_47 . V_49 ;
V_35 -> V_46 . V_50 = V_79 . V_50 ;
V_35 -> V_46 . V_154 = V_79 . V_154 ;
memcpy ( V_3 -> V_206 , & V_79 . V_47 . V_48 , 4 ) ;
memcpy ( V_3 -> V_207 , & V_79 . V_47 . V_49 , 4 ) ;
F_16 ( V_38 , V_35 ) ;
F_110 ( V_3 ) ;
}
}
if ( V_35 ) {
V_192 = 0 ;
if ( V_191 == V_198 ) {
V_35 -> V_46 . V_47 . V_97 = V_79 . V_47 . V_97 ;
V_35 -> V_46 . V_47 . V_102 = V_79 . V_47 . V_102 ;
V_35 -> V_46 . V_47 . V_156 = V_79 . V_47 . V_156 ;
if ( V_35 -> V_46 . V_31 != V_79 . V_31 ) {
V_35 -> V_46 . V_31 = V_79 . V_31 ;
V_3 -> V_68 = F_25 ( V_3 ) ;
F_110 ( V_3 ) ;
}
}
if ( F_107 ( V_190 -> V_194 . V_195 , & V_35 -> V_46 , sizeof( V_79 ) ) )
V_192 = - V_196 ;
} else
V_192 = ( V_191 == V_197 ? - V_208 : - V_209 ) ;
break;
case V_210 :
V_192 = - V_199 ;
if ( ! F_108 ( V_200 ) )
goto V_201;
if ( V_3 == V_38 -> V_53 ) {
V_192 = - V_196 ;
if ( F_106 ( & V_79 , V_190 -> V_194 . V_195 , sizeof( V_79 ) ) )
goto V_201;
V_192 = - V_209 ;
if ( ( V_35 = F_21 ( V_30 , & V_79 , 0 ) ) == NULL )
goto V_201;
V_192 = - V_199 ;
if ( V_35 == F_13 ( V_38 -> V_53 ) )
goto V_201;
V_3 = V_35 -> V_3 ;
}
F_111 ( V_3 ) ;
V_192 = 0 ;
break;
default:
V_192 = - V_202 ;
}
V_201:
return V_192 ;
}
static int F_112 ( struct V_2 * V_3 , int V_211 )
{
struct V_25 * V_111 = F_13 ( V_3 ) ;
if ( V_211 < 68 ||
V_211 > 0xFFF8 - V_3 -> V_157 - V_111 -> V_140 )
return - V_202 ;
V_3 -> V_68 = V_211 ;
return 0 ;
}
static int F_113 ( struct V_74 * V_75 , struct V_2 * V_3 ,
unsigned short type ,
const void * V_49 , const void * V_48 , unsigned int V_128 )
{
struct V_25 * V_35 = F_13 ( V_3 ) ;
struct V_77 * V_47 = (struct V_77 * ) F_97 ( V_75 , V_35 -> V_140 ) ;
T_3 * V_79 = ( T_3 * ) ( V_47 + 1 ) ;
memcpy ( V_47 , & V_35 -> V_46 . V_47 , sizeof( struct V_77 ) ) ;
V_79 [ 0 ] = V_35 -> V_46 . V_70 ;
V_79 [ 1 ] = F_10 ( type ) ;
if ( V_48 )
memcpy ( & V_47 -> V_48 , V_48 , 4 ) ;
if ( V_49 )
memcpy ( & V_47 -> V_49 , V_49 , 4 ) ;
if ( V_47 -> V_49 )
return V_35 -> V_140 ;
return - V_35 -> V_140 ;
}
static int F_114 ( const struct V_74 * V_75 , unsigned char * V_212 )
{
const struct V_77 * V_47 = ( const struct V_77 * ) F_115 ( V_75 ) ;
memcpy ( V_212 , & V_47 -> V_48 , 4 ) ;
return 4 ;
}
static int F_116 ( struct V_2 * V_3 )
{
struct V_25 * V_35 = F_13 ( V_3 ) ;
if ( F_12 ( V_35 -> V_46 . V_47 . V_49 ) ) {
struct V_130 V_131 ;
struct V_133 * V_134 ;
V_134 = F_78 ( F_7 ( V_3 ) , & V_131 ,
V_35 -> V_46 . V_47 . V_49 ,
V_35 -> V_46 . V_47 . V_48 ,
V_35 -> V_46 . V_154 ,
F_79 ( V_35 -> V_46 . V_47 . V_102 ) ,
V_35 -> V_46 . V_31 ) ;
if ( F_80 ( V_134 ) )
return - V_213 ;
V_3 = V_134 -> V_138 . V_3 ;
F_81 ( V_134 ) ;
if ( F_117 ( V_3 ) == NULL )
return - V_213 ;
V_35 -> V_214 = V_3 -> V_32 ;
F_118 ( F_117 ( V_3 ) , V_35 -> V_46 . V_47 . V_49 ) ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 )
{
struct V_25 * V_35 = F_13 ( V_3 ) ;
if ( F_12 ( V_35 -> V_46 . V_47 . V_49 ) && V_35 -> V_214 ) {
struct V_215 * V_216 ;
V_216 = F_120 ( F_7 ( V_3 ) , V_35 -> V_214 ) ;
if ( V_216 )
F_121 ( V_216 , V_35 -> V_46 . V_47 . V_49 ) ;
}
return 0 ;
}
static void F_122 ( struct V_2 * V_3 )
{
F_123 ( V_3 -> V_7 ) ;
F_28 ( V_3 ) ;
}
static void V_65 ( struct V_2 * V_3 )
{
V_3 -> V_217 = & V_218 ;
V_3 -> V_219 = F_122 ;
V_3 -> type = V_43 ;
V_3 -> V_173 = V_184 + sizeof( struct V_77 ) + 4 ;
V_3 -> V_68 = V_185 - sizeof( struct V_77 ) - 4 ;
V_3 -> V_51 = V_220 ;
V_3 -> V_188 = 0 ;
V_3 -> V_221 = 4 ;
V_3 -> V_72 |= V_222 ;
V_3 -> V_223 &= ~ V_224 ;
}
static int F_124 ( struct V_2 * V_3 )
{
struct V_25 * V_111 ;
struct V_77 * V_47 ;
V_111 = F_13 ( V_3 ) ;
V_47 = & V_111 -> V_46 . V_47 ;
V_111 -> V_3 = V_3 ;
strcpy ( V_111 -> V_46 . V_63 , V_3 -> V_63 ) ;
memcpy ( V_3 -> V_206 , & V_111 -> V_46 . V_47 . V_48 , 4 ) ;
memcpy ( V_3 -> V_207 , & V_111 -> V_46 . V_47 . V_49 , 4 ) ;
if ( V_47 -> V_49 ) {
#ifdef F_57
if ( F_12 ( V_47 -> V_49 ) ) {
if ( ! V_47 -> V_48 )
return - V_202 ;
V_3 -> V_51 = V_205 ;
V_3 -> V_139 = & V_225 ;
}
#endif
} else
V_3 -> V_139 = & V_225 ;
V_3 -> V_7 = F_125 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_226 ;
return 0 ;
}
static void F_126 ( struct V_2 * V_3 )
{
struct V_25 * V_111 = F_13 ( V_3 ) ;
struct V_77 * V_47 = & V_111 -> V_46 . V_47 ;
V_111 -> V_3 = V_3 ;
strcpy ( V_111 -> V_46 . V_63 , V_3 -> V_63 ) ;
V_47 -> V_180 = 4 ;
V_47 -> V_103 = V_96 ;
V_47 -> V_80 = 5 ;
V_111 -> V_140 = sizeof( struct V_77 ) + 4 ;
F_27 ( V_3 ) ;
}
static void F_127 ( struct V_37 * V_38 , struct V_227 * V_228 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_229 ; V_55 ++ ) {
struct V_25 * V_35 ;
V_35 = F_18 ( V_38 -> V_57 [ V_56 ] [ V_55 ] ) ;
while ( V_35 != NULL ) {
F_128 ( V_35 -> V_3 , V_228 ) ;
V_35 = F_18 ( V_35 -> V_59 ) ;
}
}
}
}
static int T_9 F_129 ( struct V_30 * V_30 )
{
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
int V_192 ;
V_38 -> V_53 = F_23 ( sizeof( struct V_25 ) , L_2 ,
V_65 ) ;
if ( ! V_38 -> V_53 ) {
V_192 = - V_226 ;
goto V_230;
}
F_24 ( V_38 -> V_53 , V_30 ) ;
F_126 ( V_38 -> V_53 ) ;
V_38 -> V_53 -> V_66 = & V_67 ;
if ( ( V_192 = F_130 ( V_38 -> V_53 ) ) )
goto V_231;
F_17 ( V_38 -> V_232 [ 0 ] ,
F_13 ( V_38 -> V_53 ) ) ;
return 0 ;
V_231:
F_122 ( V_38 -> V_53 ) ;
V_230:
return V_192 ;
}
static void T_10 F_131 ( struct V_30 * V_30 )
{
struct V_37 * V_38 ;
F_132 ( V_233 ) ;
V_38 = F_9 ( V_30 , V_39 ) ;
F_133 () ;
F_127 ( V_38 , & V_233 ) ;
F_134 ( & V_233 ) ;
F_135 () ;
}
static int F_136 ( struct V_234 * V_235 [] , struct V_234 * V_78 [] )
{
T_3 V_51 ;
if ( ! V_78 )
return 0 ;
V_51 = 0 ;
if ( V_78 [ V_236 ] )
V_51 |= F_137 ( V_78 [ V_236 ] ) ;
if ( V_78 [ V_237 ] )
V_51 |= F_137 ( V_78 [ V_237 ] ) ;
if ( V_51 & ( V_86 | V_85 ) )
return - V_202 ;
return 0 ;
}
static int F_138 ( struct V_234 * V_235 [] , struct V_234 * V_78 [] )
{
T_2 V_49 ;
if ( V_235 [ V_238 ] ) {
if ( F_139 ( V_235 [ V_238 ] ) != V_239 )
return - V_202 ;
if ( ! F_140 ( F_141 ( V_235 [ V_238 ] ) ) )
return - V_213 ;
}
if ( ! V_78 )
goto V_94;
if ( V_78 [ V_240 ] ) {
memcpy ( & V_49 , F_141 ( V_78 [ V_240 ] ) , 4 ) ;
if ( ! V_49 )
return - V_202 ;
}
V_94:
return F_136 ( V_235 , V_78 ) ;
}
static void F_142 ( struct V_234 * V_78 [] ,
struct V_54 * V_46 )
{
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_46 -> V_47 . V_103 = V_96 ;
if ( ! V_78 )
return;
if ( V_78 [ V_241 ] )
V_46 -> V_31 = F_143 ( V_78 [ V_241 ] ) ;
if ( V_78 [ V_236 ] )
V_46 -> V_124 = F_137 ( V_78 [ V_236 ] ) ;
if ( V_78 [ V_237 ] )
V_46 -> V_70 = F_137 ( V_78 [ V_237 ] ) ;
if ( V_78 [ V_242 ] )
V_46 -> V_50 = F_144 ( V_78 [ V_242 ] ) ;
if ( V_78 [ V_243 ] )
V_46 -> V_154 = F_144 ( V_78 [ V_243 ] ) ;
if ( V_78 [ V_244 ] )
V_46 -> V_47 . V_48 = F_144 ( V_78 [ V_244 ] ) ;
if ( V_78 [ V_240 ] )
V_46 -> V_47 . V_49 = F_144 ( V_78 [ V_240 ] ) ;
if ( V_78 [ V_245 ] )
V_46 -> V_47 . V_97 = F_145 ( V_78 [ V_245 ] ) ;
if ( V_78 [ V_246 ] )
V_46 -> V_47 . V_102 = F_145 ( V_78 [ V_246 ] ) ;
if ( ! V_78 [ V_247 ] || F_145 ( V_78 [ V_247 ] ) )
V_46 -> V_47 . V_156 = F_10 ( V_160 ) ;
}
static int F_146 ( struct V_2 * V_3 )
{
struct V_25 * V_111 ;
V_111 = F_13 ( V_3 ) ;
V_111 -> V_3 = V_3 ;
strcpy ( V_111 -> V_46 . V_63 , V_3 -> V_63 ) ;
F_25 ( V_3 ) ;
V_3 -> V_7 = F_125 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_226 ;
return 0 ;
}
static void F_147 ( struct V_2 * V_3 )
{
F_148 ( V_3 ) ;
V_3 -> V_217 = & V_248 ;
V_3 -> V_219 = F_122 ;
V_3 -> V_188 = 0 ;
V_3 -> V_72 |= V_222 ;
}
static int F_149 ( struct V_30 * V_249 , struct V_2 * V_3 , struct V_234 * V_235 [] ,
struct V_234 * V_78 [] )
{
struct V_25 * V_62 ;
struct V_30 * V_30 = F_7 ( V_3 ) ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
int V_68 ;
int V_192 ;
V_62 = F_13 ( V_3 ) ;
F_142 ( V_78 , & V_62 -> V_46 ) ;
if ( F_20 ( V_30 , & V_62 -> V_46 , V_3 -> type ) )
return - V_203 ;
if ( V_3 -> type == V_42 && ! V_235 [ V_238 ] )
F_150 ( V_3 ) ;
V_68 = F_25 ( V_3 ) ;
if ( ! V_235 [ V_250 ] )
V_3 -> V_68 = V_68 ;
if ( ! ( V_62 -> V_46 . V_70 & V_71 ) )
V_3 -> V_72 |= V_73 ;
V_192 = F_26 ( V_3 ) ;
if ( V_192 )
goto V_94;
F_27 ( V_3 ) ;
F_16 ( V_38 , V_62 ) ;
V_94:
return V_192 ;
}
static int F_151 ( struct V_2 * V_3 , struct V_234 * V_235 [] ,
struct V_234 * V_78 [] )
{
struct V_25 * V_35 , * V_62 ;
struct V_30 * V_30 = F_7 ( V_3 ) ;
struct V_37 * V_38 = F_9 ( V_30 , V_39 ) ;
struct V_54 V_79 ;
int V_68 ;
if ( V_3 == V_38 -> V_53 )
return - V_202 ;
V_62 = F_13 ( V_3 ) ;
F_142 ( V_78 , & V_79 ) ;
V_35 = F_21 ( V_30 , & V_79 , 0 ) ;
if ( V_35 ) {
if ( V_35 -> V_3 != V_3 )
return - V_203 ;
} else {
V_35 = V_62 ;
if ( V_3 -> type != V_42 ) {
unsigned int V_204 = 0 ;
if ( F_12 ( V_79 . V_47 . V_49 ) )
V_204 = V_205 ;
else if ( V_79 . V_47 . V_49 )
V_204 = V_187 ;
if ( ( V_3 -> V_51 ^ V_204 ) &
( V_187 | V_205 ) )
return - V_202 ;
}
F_19 ( V_38 , V_35 ) ;
V_35 -> V_46 . V_47 . V_48 = V_79 . V_47 . V_48 ;
V_35 -> V_46 . V_47 . V_49 = V_79 . V_47 . V_49 ;
V_35 -> V_46 . V_50 = V_79 . V_50 ;
if ( V_3 -> type != V_42 ) {
memcpy ( V_3 -> V_206 , & V_79 . V_47 . V_48 , 4 ) ;
memcpy ( V_3 -> V_207 , & V_79 . V_47 . V_49 , 4 ) ;
}
F_16 ( V_38 , V_35 ) ;
F_110 ( V_3 ) ;
}
V_35 -> V_46 . V_154 = V_79 . V_154 ;
V_35 -> V_46 . V_47 . V_97 = V_79 . V_47 . V_97 ;
V_35 -> V_46 . V_47 . V_102 = V_79 . V_47 . V_102 ;
V_35 -> V_46 . V_47 . V_156 = V_79 . V_47 . V_156 ;
if ( V_35 -> V_46 . V_31 != V_79 . V_31 ) {
V_35 -> V_46 . V_31 = V_79 . V_31 ;
V_68 = F_25 ( V_3 ) ;
if ( ! V_235 [ V_250 ] )
V_3 -> V_68 = V_68 ;
F_110 ( V_3 ) ;
}
return 0 ;
}
static T_11 F_152 ( const struct V_2 * V_3 )
{
return
F_153 ( 4 ) +
F_153 ( 2 ) +
F_153 ( 2 ) +
F_153 ( 4 ) +
F_153 ( 4 ) +
F_153 ( 4 ) +
F_153 ( 4 ) +
F_153 ( 1 ) +
F_153 ( 1 ) +
F_153 ( 1 ) +
0 ;
}
static int F_154 ( struct V_74 * V_75 , const struct V_2 * V_3 )
{
struct V_25 * V_35 = F_13 ( V_3 ) ;
struct V_54 * V_79 = & V_35 -> V_46 ;
if ( F_155 ( V_75 , V_241 , V_79 -> V_31 ) ||
F_156 ( V_75 , V_236 , V_79 -> V_124 ) ||
F_156 ( V_75 , V_237 , V_79 -> V_70 ) ||
F_157 ( V_75 , V_242 , V_79 -> V_50 ) ||
F_157 ( V_75 , V_243 , V_79 -> V_154 ) ||
F_157 ( V_75 , V_244 , V_79 -> V_47 . V_48 ) ||
F_157 ( V_75 , V_240 , V_79 -> V_47 . V_49 ) ||
F_158 ( V_75 , V_245 , V_79 -> V_47 . V_97 ) ||
F_158 ( V_75 , V_246 , V_79 -> V_47 . V_102 ) ||
F_158 ( V_75 , V_247 ,
! ! ( V_79 -> V_47 . V_156 & F_10 ( V_160 ) ) ) )
goto V_251;
return 0 ;
V_251:
return - V_252 ;
}
static int T_12 F_159 ( void )
{
int V_192 ;
F_160 ( L_3 ) ;
V_192 = F_161 ( & V_253 ) ;
if ( V_192 < 0 )
return V_192 ;
V_192 = F_162 ( & V_254 , V_255 ) ;
if ( V_192 < 0 ) {
F_160 ( L_4 , V_256 ) ;
goto V_257;
}
V_192 = F_163 ( & V_67 ) ;
if ( V_192 < 0 )
goto V_258;
V_192 = F_163 ( & V_259 ) ;
if ( V_192 < 0 )
goto V_260;
V_94:
return V_192 ;
V_260:
F_164 ( & V_67 ) ;
V_258:
F_165 ( & V_254 , V_255 ) ;
V_257:
F_166 ( & V_253 ) ;
goto V_94;
}
static void T_13 F_167 ( void )
{
F_164 ( & V_259 ) ;
F_164 ( & V_67 ) ;
if ( F_165 ( & V_254 , V_255 ) < 0 )
F_160 ( L_5 , V_256 ) ;
F_166 ( & V_253 ) ;
}
