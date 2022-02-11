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
V_4 -> V_25 = V_3 -> V_15 . V_25 ;
return V_4 ;
}
static bool F_6 ( const struct V_26 * V_27 ,
T_2 V_28 , T_3 V_29 )
{
if ( V_27 -> V_30 & V_31 ) {
if ( V_28 & V_31 )
return V_29 == V_27 -> V_32 ;
else
return false ;
} else
return ! ( V_28 & V_31 ) ;
}
static struct V_33 * F_7 ( struct V_2 * V_3 ,
T_3 V_34 , T_3 V_35 ,
T_2 V_28 , T_3 V_29 ,
T_2 V_36 )
{
struct V_37 * V_37 = F_8 ( V_3 ) ;
int V_38 = V_3 -> V_39 ;
unsigned int V_40 = F_9 ( V_34 ) ;
unsigned int V_41 = F_9 ( V_29 ) ;
struct V_33 * V_42 , * V_43 = NULL ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
int V_47 = ( V_36 == F_11 ( V_48 ) ) ?
V_49 : V_50 ;
int V_51 , V_52 = 4 ;
F_12 (t, ign->tunnels_r_l[h0 ^ h1]) {
if ( V_35 != V_42 -> V_53 . V_54 . V_55 ||
V_34 != V_42 -> V_53 . V_54 . V_56 ||
! ( V_42 -> V_3 -> V_28 & V_57 ) )
continue;
if ( ! F_6 ( & V_42 -> V_53 , V_28 , V_29 ) )
continue;
if ( V_42 -> V_3 -> type != V_50 &&
V_42 -> V_3 -> type != V_47 )
continue;
V_51 = 0 ;
if ( V_42 -> V_53 . V_38 != V_38 )
V_51 |= 1 ;
if ( V_42 -> V_3 -> type != V_47 )
V_51 |= 2 ;
if ( V_51 == 0 )
return V_42 ;
if ( V_51 < V_52 ) {
V_43 = V_42 ;
V_52 = V_51 ;
}
}
F_12 (t, ign->tunnels_r[h0 ^ h1]) {
if ( V_34 != V_42 -> V_53 . V_54 . V_56 ||
! ( V_42 -> V_3 -> V_28 & V_57 ) )
continue;
if ( ! F_6 ( & V_42 -> V_53 , V_28 , V_29 ) )
continue;
if ( V_42 -> V_3 -> type != V_50 &&
V_42 -> V_3 -> type != V_47 )
continue;
V_51 = 0 ;
if ( V_42 -> V_53 . V_38 != V_38 )
V_51 |= 1 ;
if ( V_42 -> V_3 -> type != V_47 )
V_51 |= 2 ;
if ( V_51 == 0 )
return V_42 ;
if ( V_51 < V_52 ) {
V_43 = V_42 ;
V_52 = V_51 ;
}
}
F_12 (t, ign->tunnels_l[h1]) {
if ( ( V_35 != V_42 -> V_53 . V_54 . V_55 &&
( V_35 != V_42 -> V_53 . V_54 . V_56 ||
! F_13 ( V_35 ) ) ) ||
! ( V_42 -> V_3 -> V_28 & V_57 ) )
continue;
if ( ! F_6 ( & V_42 -> V_53 , V_28 , V_29 ) )
continue;
if ( V_42 -> V_3 -> type != V_50 &&
V_42 -> V_3 -> type != V_47 )
continue;
V_51 = 0 ;
if ( V_42 -> V_53 . V_38 != V_38 )
V_51 |= 1 ;
if ( V_42 -> V_3 -> type != V_47 )
V_51 |= 2 ;
if ( V_51 == 0 )
return V_42 ;
if ( V_51 < V_52 ) {
V_43 = V_42 ;
V_52 = V_51 ;
}
}
F_12 (t, ign->tunnels_wc[h1]) {
if ( V_42 -> V_53 . V_32 != V_29 ||
! ( V_42 -> V_3 -> V_28 & V_57 ) )
continue;
if ( V_42 -> V_3 -> type != V_50 &&
V_42 -> V_3 -> type != V_47 )
continue;
V_51 = 0 ;
if ( V_42 -> V_53 . V_38 != V_38 )
V_51 |= 1 ;
if ( V_42 -> V_3 -> type != V_47 )
V_51 |= 2 ;
if ( V_51 == 0 )
return V_42 ;
if ( V_51 < V_52 ) {
V_43 = V_42 ;
V_52 = V_51 ;
}
}
if ( V_43 != NULL )
return V_43 ;
V_3 = V_45 -> V_58 ;
if ( V_3 -> V_28 & V_57 )
return F_14 ( V_3 ) ;
return NULL ;
}
static struct V_33 T_4 * * F_15 ( struct V_44 * V_45 ,
struct V_26 * V_53 )
{
T_3 V_34 = V_53 -> V_54 . V_56 ;
T_3 V_35 = V_53 -> V_54 . V_55 ;
T_3 V_29 = V_53 -> V_32 ;
unsigned int V_59 = F_9 ( V_29 ) ;
int V_60 = 0 ;
if ( V_35 )
V_60 |= 1 ;
if ( V_34 && ! F_13 ( V_34 ) ) {
V_60 |= 2 ;
V_59 ^= F_9 ( V_34 ) ;
}
return & V_45 -> V_61 [ V_60 ] [ V_59 ] ;
}
static inline struct V_33 T_4 * * F_16 ( struct V_44 * V_45 ,
struct V_33 * V_42 )
{
return F_15 ( V_45 , & V_42 -> V_53 ) ;
}
static void F_17 ( struct V_44 * V_45 , struct V_33 * V_42 )
{
struct V_33 T_4 * * V_62 = F_16 ( V_45 , V_42 ) ;
F_18 ( V_42 -> V_63 , F_19 ( * V_62 ) ) ;
F_18 ( * V_62 , V_42 ) ;
}
static void F_20 ( struct V_44 * V_45 , struct V_33 * V_42 )
{
struct V_33 T_4 * * V_62 ;
struct V_33 * V_64 ;
for ( V_62 = F_16 ( V_45 , V_42 ) ;
( V_64 = F_19 ( * V_62 ) ) != NULL ;
V_62 = & V_64 -> V_63 ) {
if ( V_42 == V_64 ) {
F_18 ( * V_62 , V_42 -> V_63 ) ;
break;
}
}
}
static struct V_33 * F_21 ( struct V_37 * V_37 ,
struct V_26 * V_53 ,
int type )
{
T_3 V_34 = V_53 -> V_54 . V_56 ;
T_3 V_35 = V_53 -> V_54 . V_55 ;
T_3 V_29 = V_53 -> V_32 ;
int V_38 = V_53 -> V_38 ;
struct V_33 * V_42 ;
struct V_33 T_4 * * V_62 ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
for ( V_62 = F_15 ( V_45 , V_53 ) ;
( V_42 = F_19 ( * V_62 ) ) != NULL ;
V_62 = & V_42 -> V_63 )
if ( V_35 == V_42 -> V_53 . V_54 . V_55 &&
V_34 == V_42 -> V_53 . V_54 . V_56 &&
V_29 == V_42 -> V_53 . V_32 &&
V_38 == V_42 -> V_53 . V_38 &&
type == V_42 -> V_3 -> type )
break;
return V_42 ;
}
static struct V_33 * F_22 ( struct V_37 * V_37 ,
struct V_26 * V_53 , int V_65 )
{
struct V_33 * V_42 , * V_66 ;
struct V_2 * V_3 ;
char V_67 [ V_68 ] ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
V_42 = F_21 ( V_37 , V_53 , V_50 ) ;
if ( V_42 || ! V_65 )
return V_42 ;
if ( V_53 -> V_67 [ 0 ] )
F_23 ( V_67 , V_53 -> V_67 , V_68 ) ;
else
strcpy ( V_67 , L_1 ) ;
V_3 = F_24 ( sizeof( * V_42 ) , V_67 , V_69 ) ;
if ( ! V_3 )
return NULL ;
F_25 ( V_3 , V_37 ) ;
V_66 = F_14 ( V_3 ) ;
V_66 -> V_53 = * V_53 ;
V_3 -> V_70 = & V_71 ;
V_3 -> V_72 = F_26 ( V_3 ) ;
if ( F_27 ( V_3 ) < 0 )
goto V_73;
if ( ! ( V_66 -> V_53 . V_74 & V_75 ) )
V_3 -> V_76 |= V_77 ;
F_28 ( V_3 ) ;
F_17 ( V_45 , V_66 ) ;
return V_66 ;
V_73:
F_29 ( V_3 ) ;
return NULL ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
F_20 ( V_45 , F_14 ( V_3 ) ) ;
F_31 ( V_3 ) ;
}
static void F_32 ( struct V_78 * V_79 , T_5 V_80 )
{
const struct V_81 * V_54 = ( const struct V_81 * ) V_79 -> V_82 ;
T_2 * V_27 = ( T_2 * ) ( V_79 -> V_82 + ( V_54 -> V_83 << 2 ) ) ;
int V_84 = ( V_54 -> V_83 << 2 ) + 4 ;
const int type = F_33 ( V_79 ) -> type ;
const int V_85 = F_33 ( V_79 ) -> V_85 ;
struct V_33 * V_42 ;
T_2 V_28 ;
T_3 V_29 = 0 ;
V_28 = V_27 [ 0 ] ;
if ( V_28 & ( V_86 | V_31 | V_75 | V_87 | V_88 ) ) {
if ( V_28 & ( V_88 | V_87 ) )
return;
if ( V_28 & V_31 ) {
V_84 += 4 ;
if ( V_28 & V_86 )
V_84 += 4 ;
}
}
if ( F_34 ( V_79 ) < V_84 )
return;
if ( V_28 & V_31 )
V_29 = * ( ( ( T_3 * ) V_27 ) + ( V_84 / 4 ) - 1 ) ;
switch ( type ) {
default:
case V_89 :
return;
case V_90 :
switch ( V_85 ) {
case V_91 :
case V_92 :
return;
default:
break;
}
break;
case V_93 :
if ( V_85 != V_94 )
return;
break;
case V_95 :
break;
}
V_42 = F_7 ( V_79 -> V_3 , V_54 -> V_56 , V_54 -> V_55 ,
V_28 , V_29 , V_27 [ 1 ] ) ;
if ( V_42 == NULL )
return;
if ( type == V_90 && V_85 == V_96 ) {
F_35 ( V_79 , F_8 ( V_79 -> V_3 ) , V_80 ,
V_42 -> V_53 . V_38 , 0 , V_97 , 0 ) ;
return;
}
if ( type == V_95 ) {
F_36 ( V_79 , F_8 ( V_79 -> V_3 ) , V_42 -> V_53 . V_38 , 0 ,
V_97 , 0 ) ;
return;
}
if ( V_42 -> V_53 . V_54 . V_56 == 0 ||
F_13 ( V_42 -> V_53 . V_54 . V_56 ) )
return;
if ( V_42 -> V_53 . V_54 . V_98 == 0 && type == V_93 )
return;
if ( F_37 ( V_99 , V_42 -> V_100 + V_101 ) )
V_42 -> V_102 ++ ;
else
V_42 -> V_102 = 1 ;
V_42 -> V_100 = V_99 ;
}
static inline T_6
F_38 ( T_6 V_103 , const struct V_81 * V_104 , struct V_78 * V_79 )
{
T_6 V_105 = 0 ;
if ( V_79 -> V_106 == F_11 ( V_107 ) )
V_105 = V_104 -> V_103 ;
else if ( V_79 -> V_106 == F_11 ( V_108 ) )
V_105 = F_39 ( ( const struct V_109 * ) V_104 ) ;
return F_40 ( V_103 , V_105 ) ;
}
static int F_41 ( struct V_78 * V_79 )
{
const struct V_81 * V_54 ;
T_6 * V_59 ;
T_2 V_28 ;
T_7 V_110 = 0 ;
T_3 V_29 = 0 ;
T_5 V_111 = 0 ;
struct V_33 * V_112 ;
int V_113 = 4 ;
T_2 V_36 ;
int V_114 ;
if ( ! F_42 ( V_79 , 16 ) )
goto V_115;
V_54 = F_43 ( V_79 ) ;
V_59 = V_79 -> V_82 ;
V_28 = * ( T_2 * ) V_59 ;
if ( V_28 & ( V_86 | V_31 | V_87 | V_75 | V_88 ) ) {
if ( V_28 & ( V_88 | V_87 ) )
goto V_115;
if ( V_28 & V_86 ) {
switch ( V_79 -> V_116 ) {
case V_117 :
V_110 = F_44 ( V_79 -> V_110 ) ;
if ( ! V_110 )
break;
case V_118 :
V_79 -> V_110 = 0 ;
V_110 = F_45 ( V_79 ) ;
V_79 -> V_116 = V_117 ;
}
V_113 += 4 ;
}
if ( V_28 & V_31 ) {
V_29 = * ( T_3 * ) ( V_59 + V_113 ) ;
V_113 += 4 ;
}
if ( V_28 & V_75 ) {
V_111 = F_46 ( * ( T_3 * ) ( V_59 + V_113 ) ) ;
V_113 += 4 ;
}
}
V_36 = * ( T_2 * ) ( V_59 + 2 ) ;
V_112 = F_7 ( V_79 -> V_3 ,
V_54 -> V_55 , V_54 -> V_56 , V_28 , V_29 ,
V_36 ) ;
if ( V_112 ) {
struct V_6 * V_7 ;
F_47 ( V_79 ) ;
V_79 -> V_106 = V_36 ;
if ( V_28 == 0 && V_36 == F_11 ( V_119 ) ) {
V_79 -> V_106 = F_11 ( V_107 ) ;
if ( ( * ( V_59 + V_113 ) & 0xF0 ) != 0x40 )
V_113 += 4 ;
}
V_79 -> V_120 = V_79 -> V_121 ;
F_48 ( V_79 , V_113 ) ;
F_49 ( V_79 , F_50 ( V_79 ) , V_113 ) ;
V_79 -> V_122 = V_123 ;
#ifdef F_51
if ( F_13 ( V_54 -> V_56 ) ) {
if ( F_52 ( F_53 ( V_79 ) ) )
goto V_115;
V_112 -> V_3 -> V_15 . V_14 ++ ;
V_79 -> V_122 = V_124 ;
}
#endif
if ( ( ( V_28 & V_86 ) && V_110 ) ||
( ! ( V_28 & V_86 ) && V_112 -> V_53 . V_30 & V_86 ) ) {
V_112 -> V_3 -> V_15 . V_16 ++ ;
V_112 -> V_3 -> V_15 . V_20 ++ ;
goto V_115;
}
if ( V_112 -> V_53 . V_30 & V_75 ) {
if ( ! ( V_28 & V_75 ) ||
( V_112 -> V_125 && ( V_126 ) ( V_111 - V_112 -> V_125 ) < 0 ) ) {
V_112 -> V_3 -> V_15 . V_17 ++ ;
V_112 -> V_3 -> V_15 . V_20 ++ ;
goto V_115;
}
V_112 -> V_125 = V_111 + 1 ;
}
if ( V_112 -> V_3 -> type == V_49 ) {
if ( ! F_42 ( V_79 , V_127 ) ) {
V_112 -> V_3 -> V_15 . V_18 ++ ;
V_112 -> V_3 -> V_15 . V_20 ++ ;
goto V_115;
}
V_54 = F_43 ( V_79 ) ;
V_79 -> V_106 = F_54 ( V_79 , V_112 -> V_3 ) ;
F_49 ( V_79 , F_55 ( V_79 ) , V_127 ) ;
}
F_56 ( V_79 , V_112 -> V_3 ) ;
F_57 ( V_79 ) ;
V_114 = F_58 ( V_54 , V_79 ) ;
if ( F_59 ( V_114 ) ) {
if ( V_128 )
F_60 ( L_2 ,
& V_54 -> V_55 , V_54 -> V_103 ) ;
if ( V_114 > 1 ) {
++ V_112 -> V_3 -> V_15 . V_19 ;
++ V_112 -> V_3 -> V_15 . V_20 ;
goto V_115;
}
}
V_7 = F_61 ( V_112 -> V_3 -> V_7 ) ;
F_62 ( & V_7 -> V_13 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_79 -> V_129 ;
F_63 ( & V_7 -> V_13 ) ;
F_64 ( & V_112 -> V_130 , V_79 ) ;
return 0 ;
}
F_65 ( V_79 , V_90 , V_92 , 0 ) ;
V_115:
F_66 ( V_79 ) ;
return 0 ;
}
static struct V_78 * F_67 ( struct V_33 * V_112 , struct V_78 * V_79 )
{
int V_114 ;
if ( F_68 ( V_79 ) ) {
V_114 = F_69 ( V_79 , V_131 ) ;
if ( F_59 ( V_114 ) )
goto error;
F_70 ( V_79 ) -> V_132 |= V_133 ;
return V_79 ;
} else if ( V_79 -> V_116 == V_134 &&
V_112 -> V_53 . V_74 & V_86 ) {
V_114 = F_71 ( V_79 ) ;
if ( F_59 ( V_114 ) )
goto error;
} else if ( V_79 -> V_116 != V_134 )
V_79 -> V_116 = V_118 ;
return V_79 ;
error:
F_66 ( V_79 ) ;
return F_72 ( V_114 ) ;
}
static T_8 F_73 ( struct V_78 * V_79 , struct V_2 * V_3 )
{
struct V_6 * V_7 = F_61 ( V_3 -> V_7 ) ;
struct V_33 * V_112 = F_14 ( V_3 ) ;
const struct V_81 * V_104 ;
const struct V_81 * V_135 ;
struct V_136 V_137 ;
T_6 V_103 ;
T_2 V_138 ;
struct V_139 * V_140 ;
struct V_2 * V_141 ;
struct V_81 * V_54 ;
unsigned int V_142 ;
int V_143 ;
T_3 V_144 ;
int V_72 ;
T_6 V_98 ;
int V_114 ;
int V_145 ;
V_79 = F_67 ( V_112 , V_79 ) ;
if ( F_74 ( V_79 ) ) {
V_3 -> V_15 . V_23 ++ ;
return V_146 ;
}
if ( ! V_79 -> V_147 ) {
F_75 ( V_79 ) ;
V_79 -> V_147 = 1 ;
}
V_104 = F_43 ( V_79 ) ;
if ( V_3 -> type == V_49 )
F_76 ( V_79 ) -> V_28 = 0 ;
if ( V_3 -> V_148 && V_3 -> type == V_50 ) {
V_143 = 0 ;
V_135 = ( const struct V_81 * ) V_79 -> V_82 ;
} else {
V_143 = V_112 -> V_149 ;
V_135 = & V_112 -> V_53 . V_54 ;
}
if ( ( V_144 = V_135 -> V_56 ) == 0 ) {
if ( F_77 ( V_79 ) == NULL ) {
V_3 -> V_15 . V_21 ++ ;
goto V_150;
}
if ( V_79 -> V_106 == F_11 ( V_107 ) ) {
V_140 = F_53 ( V_79 ) ;
V_144 = F_78 ( V_140 , V_104 -> V_56 ) ;
}
#if F_79 ( V_151 )
else if ( V_79 -> V_106 == F_11 ( V_108 ) ) {
const struct V_152 * V_153 ;
struct V_154 * V_155 ;
bool V_156 ;
int V_157 ;
V_155 = F_80 ( F_77 ( V_79 ) , & F_81 ( V_79 ) -> V_56 ) ;
if ( V_155 == NULL )
goto V_150;
V_153 = ( const struct V_152 * ) & V_155 -> V_158 ;
V_157 = F_82 ( V_153 ) ;
if ( V_157 == V_159 ) {
V_153 = & F_81 ( V_79 ) -> V_56 ;
V_157 = F_82 ( V_153 ) ;
}
if ( ( V_157 & V_160 ) == 0 )
V_156 = true ;
else {
V_156 = false ;
V_144 = V_153 -> V_161 [ 3 ] ;
}
F_83 ( V_155 ) ;
if ( V_156 )
goto V_162;
}
#endif
else
goto V_150;
}
V_98 = V_135 -> V_98 ;
V_103 = V_135 -> V_103 ;
if ( V_103 & 0x1 ) {
V_103 &= ~ 0x1 ;
if ( V_79 -> V_106 == F_11 ( V_107 ) )
V_103 = V_104 -> V_103 ;
else if ( V_79 -> V_106 == F_11 ( V_108 ) )
V_103 = F_39 ( ( const struct V_109 * ) V_104 ) ;
}
V_140 = F_84 ( F_8 ( V_3 ) , & V_137 , V_144 , V_135 -> V_55 ,
V_112 -> V_53 . V_163 , F_85 ( V_103 ) ,
V_112 -> V_53 . V_38 ) ;
if ( F_74 ( V_140 ) ) {
V_3 -> V_15 . V_22 ++ ;
goto V_150;
}
V_141 = V_140 -> V_144 . V_3 ;
if ( V_141 == V_3 ) {
F_86 ( V_140 ) ;
V_3 -> V_15 . V_164 ++ ;
goto V_150;
}
V_138 = V_135 -> V_165 ;
if ( V_138 )
V_72 = F_87 ( & V_140 -> V_144 ) - V_3 -> V_166 - V_112 -> V_149 ;
else
V_72 = F_77 ( V_79 ) ? F_87 ( F_77 ( V_79 ) ) : V_3 -> V_72 ;
if ( F_77 ( V_79 ) )
F_77 ( V_79 ) -> V_167 -> V_168 ( F_77 ( V_79 ) , NULL , V_79 , V_72 ) ;
if ( V_79 -> V_106 == F_11 ( V_107 ) ) {
V_138 |= ( V_104 -> V_165 & F_11 ( V_169 ) ) ;
if ( ! F_68 ( V_79 ) &&
( V_104 -> V_165 & F_11 ( V_169 ) ) &&
V_72 < F_88 ( V_104 -> V_170 ) ) {
F_65 ( V_79 , V_90 , V_96 , F_89 ( V_72 ) ) ;
F_86 ( V_140 ) ;
goto V_150;
}
}
#if F_79 ( V_151 )
else if ( V_79 -> V_106 == F_11 ( V_108 ) ) {
struct V_171 * V_172 = (struct V_171 * ) F_77 ( V_79 ) ;
if ( V_172 && V_72 < F_87 ( F_77 ( V_79 ) ) && V_72 >= V_173 ) {
if ( ( V_112 -> V_53 . V_54 . V_56 &&
! F_13 ( V_112 -> V_53 . V_54 . V_56 ) ) ||
V_172 -> V_174 . V_175 == 128 ) {
V_172 -> V_176 |= V_177 ;
F_90 ( F_77 ( V_79 ) , V_178 , V_72 ) ;
}
}
if ( ! F_68 ( V_79 ) &&
V_72 >= V_173 &&
V_72 < V_79 -> V_129 - V_112 -> V_149 + V_143 ) {
F_91 ( V_79 , V_179 , 0 , V_72 ) ;
F_86 ( V_140 ) ;
goto V_150;
}
}
#endif
if ( V_112 -> V_102 > 0 ) {
if ( F_37 ( V_99 ,
V_112 -> V_100 + V_101 ) ) {
V_112 -> V_102 -- ;
F_92 ( V_79 ) ;
} else
V_112 -> V_102 = 0 ;
}
V_142 = F_93 ( V_141 ) + V_143 + V_140 -> V_144 . V_180 ;
if ( F_94 ( V_79 ) < V_142 || F_95 ( V_79 ) ||
( F_96 ( V_79 ) && ! F_97 ( V_79 , 0 ) ) ) {
struct V_78 * V_181 = F_98 ( V_79 , V_142 ) ;
if ( V_142 > V_3 -> V_182 )
V_3 -> V_182 = V_142 ;
if ( ! V_181 ) {
F_86 ( V_140 ) ;
V_3 -> V_15 . V_23 ++ ;
F_99 ( V_79 ) ;
return V_146 ;
}
if ( V_79 -> V_183 )
F_100 ( V_181 , V_79 -> V_183 ) ;
F_99 ( V_79 ) ;
V_79 = V_181 ;
V_104 = F_43 ( V_79 ) ;
}
F_101 ( V_79 , V_143 ) ;
F_57 ( V_79 ) ;
F_102 ( V_79 , sizeof( * V_54 ) ) ;
memset ( & ( F_76 ( V_79 ) -> V_184 ) , 0 , sizeof( F_76 ( V_79 ) -> V_184 ) ) ;
F_76 ( V_79 ) -> V_28 &= ~ ( V_185 | V_186 |
V_187 ) ;
F_103 ( V_79 ) ;
F_104 ( V_79 , & V_140 -> V_144 ) ;
V_54 = F_43 ( V_79 ) ;
V_54 -> V_188 = 4 ;
V_54 -> V_83 = sizeof( struct V_81 ) >> 2 ;
V_54 -> V_165 = V_138 ;
V_54 -> V_106 = V_97 ;
V_54 -> V_103 = F_38 ( V_103 , V_104 , V_79 ) ;
V_54 -> V_56 = V_137 . V_56 ;
V_54 -> V_55 = V_137 . V_55 ;
V_54 -> V_98 = V_98 ;
F_105 ( V_79 , V_104 , & V_140 -> V_144 ) ;
if ( V_98 == 0 ) {
if ( V_79 -> V_106 == F_11 ( V_107 ) )
V_54 -> V_98 = V_104 -> V_98 ;
#if F_79 ( V_151 )
else if ( V_79 -> V_106 == F_11 ( V_108 ) )
V_54 -> V_98 = ( ( const struct V_109 * ) V_104 ) -> V_189 ;
#endif
else
V_54 -> V_98 = F_106 ( & V_140 -> V_144 ) ;
}
( ( T_2 * ) ( V_54 + 1 ) ) [ 0 ] = V_112 -> V_53 . V_74 ;
( ( T_2 * ) ( V_54 + 1 ) ) [ 1 ] = ( V_3 -> type == V_49 ) ?
F_11 ( V_48 ) : V_79 -> V_106 ;
if ( V_112 -> V_53 . V_74 & ( V_31 | V_86 | V_75 ) ) {
T_3 * V_190 = ( T_3 * ) ( ( ( T_6 * ) V_54 ) + V_112 -> V_149 - 4 ) ;
if ( V_112 -> V_53 . V_74 & V_75 ) {
++ V_112 -> V_191 ;
* V_190 = F_89 ( V_112 -> V_191 ) ;
V_190 -- ;
}
if ( V_112 -> V_53 . V_74 & V_31 ) {
* V_190 = V_112 -> V_53 . V_163 ;
V_190 -- ;
}
if ( ! ( F_70 ( V_79 ) -> V_132 & V_133 ) &&
( V_112 -> V_53 . V_74 & V_86 ) ) {
int V_113 = F_107 ( V_79 ) ;
if ( F_108 ( V_79 ) ) {
V_114 = F_109 ( V_79 ) ;
if ( V_114 )
goto V_150;
}
* V_190 = 0 ;
* ( T_7 * ) V_190 = F_44 ( F_110 ( V_79 , V_113 ,
V_79 -> V_129 - V_113 ,
0 ) ) ;
}
}
F_111 ( V_79 ) ;
V_145 = V_79 -> V_129 - F_107 ( V_79 ) ;
V_114 = F_112 ( V_79 ) ;
if ( F_113 ( F_114 ( V_114 ) == 0 ) ) {
F_62 ( & V_7 -> V_13 ) ;
V_7 -> V_11 += V_145 ;
V_7 -> V_10 ++ ;
F_63 ( & V_7 -> V_13 ) ;
} else {
V_3 -> V_15 . V_25 ++ ;
V_3 -> V_15 . V_24 ++ ;
}
return V_146 ;
#if F_79 ( V_151 )
V_162:
F_92 ( V_79 ) ;
#endif
V_150:
V_3 -> V_15 . V_25 ++ ;
F_99 ( V_79 ) ;
return V_146 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_2 * V_141 = NULL ;
struct V_33 * V_112 ;
const struct V_81 * V_54 ;
int V_149 = V_192 ;
int V_72 = V_193 ;
int V_194 = sizeof( struct V_81 ) + 4 ;
V_112 = F_14 ( V_3 ) ;
V_54 = & V_112 -> V_53 . V_54 ;
if ( V_54 -> V_56 ) {
struct V_136 V_137 ;
struct V_139 * V_140 ;
V_140 = F_84 ( F_8 ( V_3 ) , & V_137 ,
V_54 -> V_56 , V_54 -> V_55 ,
V_112 -> V_53 . V_163 ,
F_85 ( V_54 -> V_103 ) ,
V_112 -> V_53 . V_38 ) ;
if ( ! F_74 ( V_140 ) ) {
V_141 = V_140 -> V_144 . V_3 ;
F_86 ( V_140 ) ;
}
if ( V_3 -> type != V_49 )
V_3 -> V_28 |= V_195 ;
}
if ( ! V_141 && V_112 -> V_53 . V_38 )
V_141 = F_115 ( F_8 ( V_3 ) , V_112 -> V_53 . V_38 ) ;
if ( V_141 ) {
V_149 = V_141 -> V_166 + V_141 -> V_182 ;
V_72 = V_141 -> V_72 ;
}
V_3 -> V_196 = V_112 -> V_53 . V_38 ;
if ( V_112 -> V_53 . V_74 & ( V_86 | V_31 | V_75 ) ) {
if ( V_112 -> V_53 . V_74 & V_86 )
V_194 += 4 ;
if ( V_112 -> V_53 . V_74 & V_31 )
V_194 += 4 ;
if ( V_112 -> V_53 . V_74 & V_75 )
V_194 += 4 ;
}
V_3 -> V_182 = V_194 + V_149 ;
V_72 -= V_3 -> V_166 + V_194 ;
if ( V_72 < 68 )
V_72 = 68 ;
V_112 -> V_149 = V_194 ;
if ( ! ( V_112 -> V_53 . V_74 & V_75 ) ) {
V_3 -> V_76 |= V_197 ;
V_3 -> V_198 |= V_197 ;
}
return V_72 ;
}
static int
F_116 ( struct V_2 * V_3 , struct V_199 * V_200 , int V_201 )
{
int V_114 = 0 ;
struct V_26 V_27 ;
struct V_33 * V_42 ;
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
switch ( V_201 ) {
case V_202 :
V_42 = NULL ;
if ( V_3 == V_45 -> V_58 ) {
if ( F_117 ( & V_27 , V_200 -> V_203 . V_204 , sizeof( V_27 ) ) ) {
V_114 = - V_205 ;
break;
}
V_42 = F_22 ( V_37 , & V_27 , 0 ) ;
}
if ( V_42 == NULL )
V_42 = F_14 ( V_3 ) ;
memcpy ( & V_27 , & V_42 -> V_53 , sizeof( V_27 ) ) ;
if ( F_118 ( V_200 -> V_203 . V_204 , & V_27 , sizeof( V_27 ) ) )
V_114 = - V_205 ;
break;
case V_206 :
case V_207 :
V_114 = - V_208 ;
if ( ! F_119 ( V_37 -> V_209 , V_210 ) )
goto V_211;
V_114 = - V_205 ;
if ( F_117 ( & V_27 , V_200 -> V_203 . V_204 , sizeof( V_27 ) ) )
goto V_211;
V_114 = - V_212 ;
if ( V_27 . V_54 . V_188 != 4 || V_27 . V_54 . V_106 != V_97 ||
V_27 . V_54 . V_83 != 5 || ( V_27 . V_54 . V_165 & F_11 ( ~ V_169 ) ) ||
( ( V_27 . V_30 | V_27 . V_74 ) & ( V_88 | V_87 ) ) )
goto V_211;
if ( V_27 . V_54 . V_98 )
V_27 . V_54 . V_165 |= F_11 ( V_169 ) ;
if ( ! ( V_27 . V_30 & V_31 ) )
V_27 . V_32 = 0 ;
if ( ! ( V_27 . V_74 & V_31 ) )
V_27 . V_163 = 0 ;
V_42 = F_22 ( V_37 , & V_27 , V_201 == V_206 ) ;
if ( V_3 != V_45 -> V_58 && V_201 == V_207 ) {
if ( V_42 != NULL ) {
if ( V_42 -> V_3 != V_3 ) {
V_114 = - V_213 ;
break;
}
} else {
unsigned int V_214 = 0 ;
V_42 = F_14 ( V_3 ) ;
if ( F_13 ( V_27 . V_54 . V_56 ) )
V_214 = V_215 ;
else if ( V_27 . V_54 . V_56 )
V_214 = V_195 ;
if ( ( V_3 -> V_28 ^ V_214 ) & ( V_195 | V_215 ) ) {
V_114 = - V_212 ;
break;
}
F_20 ( V_45 , V_42 ) ;
F_120 () ;
V_42 -> V_53 . V_54 . V_55 = V_27 . V_54 . V_55 ;
V_42 -> V_53 . V_54 . V_56 = V_27 . V_54 . V_56 ;
V_42 -> V_53 . V_32 = V_27 . V_32 ;
V_42 -> V_53 . V_163 = V_27 . V_163 ;
memcpy ( V_3 -> V_216 , & V_27 . V_54 . V_55 , 4 ) ;
memcpy ( V_3 -> V_217 , & V_27 . V_54 . V_56 , 4 ) ;
F_17 ( V_45 , V_42 ) ;
F_121 ( V_3 ) ;
}
}
if ( V_42 ) {
V_114 = 0 ;
if ( V_201 == V_207 ) {
V_42 -> V_53 . V_54 . V_98 = V_27 . V_54 . V_98 ;
V_42 -> V_53 . V_54 . V_103 = V_27 . V_54 . V_103 ;
V_42 -> V_53 . V_54 . V_165 = V_27 . V_54 . V_165 ;
if ( V_42 -> V_53 . V_38 != V_27 . V_38 ) {
V_42 -> V_53 . V_38 = V_27 . V_38 ;
V_3 -> V_72 = F_26 ( V_3 ) ;
F_121 ( V_3 ) ;
}
}
if ( F_118 ( V_200 -> V_203 . V_204 , & V_42 -> V_53 , sizeof( V_27 ) ) )
V_114 = - V_205 ;
} else
V_114 = ( V_201 == V_206 ? - V_218 : - V_219 ) ;
break;
case V_220 :
V_114 = - V_208 ;
if ( ! F_119 ( V_37 -> V_209 , V_210 ) )
goto V_211;
if ( V_3 == V_45 -> V_58 ) {
V_114 = - V_205 ;
if ( F_117 ( & V_27 , V_200 -> V_203 . V_204 , sizeof( V_27 ) ) )
goto V_211;
V_114 = - V_219 ;
if ( ( V_42 = F_22 ( V_37 , & V_27 , 0 ) ) == NULL )
goto V_211;
V_114 = - V_208 ;
if ( V_42 == F_14 ( V_45 -> V_58 ) )
goto V_211;
V_3 = V_42 -> V_3 ;
}
F_122 ( V_3 ) ;
V_114 = 0 ;
break;
default:
V_114 = - V_212 ;
}
V_211:
return V_114 ;
}
static int F_123 ( struct V_2 * V_3 , int V_221 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
if ( V_221 < 68 ||
V_221 > 0xFFF8 - V_3 -> V_166 - V_112 -> V_149 )
return - V_212 ;
V_3 -> V_72 = V_221 ;
return 0 ;
}
static int F_124 ( struct V_78 * V_79 , struct V_2 * V_3 ,
unsigned short type ,
const void * V_56 , const void * V_55 , unsigned int V_129 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
struct V_81 * V_54 = (struct V_81 * ) F_101 ( V_79 , V_42 -> V_149 ) ;
T_2 * V_27 = ( T_2 * ) ( V_54 + 1 ) ;
memcpy ( V_54 , & V_42 -> V_53 . V_54 , sizeof( struct V_81 ) ) ;
V_27 [ 0 ] = V_42 -> V_53 . V_74 ;
V_27 [ 1 ] = F_11 ( type ) ;
if ( V_55 )
memcpy ( & V_54 -> V_55 , V_55 , 4 ) ;
if ( V_56 )
memcpy ( & V_54 -> V_56 , V_56 , 4 ) ;
if ( V_54 -> V_56 )
return V_42 -> V_149 ;
return - V_42 -> V_149 ;
}
static int F_125 ( const struct V_78 * V_79 , unsigned char * V_222 )
{
const struct V_81 * V_54 = ( const struct V_81 * ) F_126 ( V_79 ) ;
memcpy ( V_222 , & V_54 -> V_55 , 4 ) ;
return 4 ;
}
static int F_127 ( struct V_2 * V_3 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
if ( F_13 ( V_42 -> V_53 . V_54 . V_56 ) ) {
struct V_136 V_137 ;
struct V_139 * V_140 ;
V_140 = F_84 ( F_8 ( V_3 ) , & V_137 ,
V_42 -> V_53 . V_54 . V_56 ,
V_42 -> V_53 . V_54 . V_55 ,
V_42 -> V_53 . V_163 ,
F_85 ( V_42 -> V_53 . V_54 . V_103 ) ,
V_42 -> V_53 . V_38 ) ;
if ( F_74 ( V_140 ) )
return - V_223 ;
V_3 = V_140 -> V_144 . V_3 ;
F_86 ( V_140 ) ;
if ( F_128 ( V_3 ) == NULL )
return - V_223 ;
V_42 -> V_224 = V_3 -> V_39 ;
F_129 ( F_128 ( V_3 ) , V_42 -> V_53 . V_54 . V_56 ) ;
}
return 0 ;
}
static int F_130 ( struct V_2 * V_3 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
if ( F_13 ( V_42 -> V_53 . V_54 . V_56 ) && V_42 -> V_224 ) {
struct V_225 * V_226 ;
V_226 = F_131 ( F_8 ( V_3 ) , V_42 -> V_224 ) ;
if ( V_226 )
F_132 ( V_226 , V_42 -> V_53 . V_54 . V_56 ) ;
}
return 0 ;
}
static void F_133 ( struct V_2 * V_3 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
F_134 ( & V_112 -> V_130 ) ;
F_135 ( V_3 -> V_7 ) ;
F_29 ( V_3 ) ;
}
static void V_69 ( struct V_2 * V_3 )
{
V_3 -> V_227 = & V_228 ;
V_3 -> V_229 = F_133 ;
V_3 -> type = V_50 ;
V_3 -> V_182 = V_192 + sizeof( struct V_81 ) + 4 ;
V_3 -> V_72 = V_193 - sizeof( struct V_81 ) - 4 ;
V_3 -> V_28 = V_230 ;
V_3 -> V_196 = 0 ;
V_3 -> V_231 = 4 ;
V_3 -> V_76 |= V_232 ;
V_3 -> V_233 &= ~ V_234 ;
V_3 -> V_76 |= V_235 ;
V_3 -> V_198 |= V_235 ;
}
static int F_136 ( struct V_2 * V_3 )
{
struct V_33 * V_112 ;
struct V_81 * V_54 ;
int V_114 ;
V_112 = F_14 ( V_3 ) ;
V_54 = & V_112 -> V_53 . V_54 ;
V_112 -> V_3 = V_3 ;
strcpy ( V_112 -> V_53 . V_67 , V_3 -> V_67 ) ;
memcpy ( V_3 -> V_216 , & V_112 -> V_53 . V_54 . V_55 , 4 ) ;
memcpy ( V_3 -> V_217 , & V_112 -> V_53 . V_54 . V_56 , 4 ) ;
if ( V_54 -> V_56 ) {
#ifdef F_51
if ( F_13 ( V_54 -> V_56 ) ) {
if ( ! V_54 -> V_55 )
return - V_212 ;
V_3 -> V_28 = V_215 ;
V_3 -> V_148 = & V_236 ;
}
#endif
} else
V_3 -> V_148 = & V_236 ;
V_3 -> V_7 = F_137 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_237 ;
V_114 = F_138 ( & V_112 -> V_130 , V_3 ) ;
if ( V_114 ) {
F_135 ( V_3 -> V_7 ) ;
return V_114 ;
}
return 0 ;
}
static void F_139 ( struct V_2 * V_3 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
struct V_81 * V_54 = & V_112 -> V_53 . V_54 ;
V_112 -> V_3 = V_3 ;
strcpy ( V_112 -> V_53 . V_67 , V_3 -> V_67 ) ;
V_54 -> V_188 = 4 ;
V_54 -> V_106 = V_97 ;
V_54 -> V_83 = 5 ;
V_112 -> V_149 = sizeof( struct V_81 ) + 4 ;
F_28 ( V_3 ) ;
}
static void F_140 ( struct V_44 * V_45 , struct V_238 * V_239 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_240 ; V_59 ++ ) {
struct V_33 * V_42 ;
V_42 = F_19 ( V_45 -> V_61 [ V_60 ] [ V_59 ] ) ;
while ( V_42 != NULL ) {
F_141 ( V_42 -> V_3 , V_239 ) ;
V_42 = F_19 ( V_42 -> V_63 ) ;
}
}
}
}
static int T_9 F_142 ( struct V_37 * V_37 )
{
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
int V_114 ;
V_45 -> V_58 = F_24 ( sizeof( struct V_33 ) , L_3 ,
V_69 ) ;
if ( ! V_45 -> V_58 ) {
V_114 = - V_237 ;
goto V_241;
}
F_25 ( V_45 -> V_58 , V_37 ) ;
F_139 ( V_45 -> V_58 ) ;
V_45 -> V_58 -> V_70 = & V_71 ;
if ( ( V_114 = F_143 ( V_45 -> V_58 ) ) )
goto V_242;
F_18 ( V_45 -> V_243 [ 0 ] ,
F_14 ( V_45 -> V_58 ) ) ;
return 0 ;
V_242:
F_133 ( V_45 -> V_58 ) ;
V_241:
return V_114 ;
}
static void T_10 F_144 ( struct V_37 * V_37 )
{
struct V_44 * V_45 ;
F_145 ( V_244 ) ;
V_45 = F_10 ( V_37 , V_46 ) ;
F_146 () ;
F_140 ( V_45 , & V_244 ) ;
F_147 ( & V_244 ) ;
F_148 () ;
}
static int F_149 ( struct V_245 * V_246 [] , struct V_245 * V_82 [] )
{
T_2 V_28 ;
if ( ! V_82 )
return 0 ;
V_28 = 0 ;
if ( V_82 [ V_247 ] )
V_28 |= F_150 ( V_82 [ V_247 ] ) ;
if ( V_82 [ V_248 ] )
V_28 |= F_150 ( V_82 [ V_248 ] ) ;
if ( V_28 & ( V_88 | V_87 ) )
return - V_212 ;
return 0 ;
}
static int F_151 ( struct V_245 * V_246 [] , struct V_245 * V_82 [] )
{
T_3 V_56 ;
if ( V_246 [ V_249 ] ) {
if ( F_152 ( V_246 [ V_249 ] ) != V_250 )
return - V_212 ;
if ( ! F_153 ( F_154 ( V_246 [ V_249 ] ) ) )
return - V_223 ;
}
if ( ! V_82 )
goto V_251;
if ( V_82 [ V_252 ] ) {
memcpy ( & V_56 , F_154 ( V_82 [ V_252 ] ) , 4 ) ;
if ( ! V_56 )
return - V_212 ;
}
V_251:
return F_149 ( V_246 , V_82 ) ;
}
static void F_155 ( struct V_245 * V_82 [] ,
struct V_26 * V_53 )
{
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_54 . V_106 = V_97 ;
if ( ! V_82 )
return;
if ( V_82 [ V_253 ] )
V_53 -> V_38 = F_156 ( V_82 [ V_253 ] ) ;
if ( V_82 [ V_247 ] )
V_53 -> V_30 = F_150 ( V_82 [ V_247 ] ) ;
if ( V_82 [ V_248 ] )
V_53 -> V_74 = F_150 ( V_82 [ V_248 ] ) ;
if ( V_82 [ V_254 ] )
V_53 -> V_32 = F_157 ( V_82 [ V_254 ] ) ;
if ( V_82 [ V_255 ] )
V_53 -> V_163 = F_157 ( V_82 [ V_255 ] ) ;
if ( V_82 [ V_256 ] )
V_53 -> V_54 . V_55 = F_157 ( V_82 [ V_256 ] ) ;
if ( V_82 [ V_252 ] )
V_53 -> V_54 . V_56 = F_157 ( V_82 [ V_252 ] ) ;
if ( V_82 [ V_257 ] )
V_53 -> V_54 . V_98 = F_158 ( V_82 [ V_257 ] ) ;
if ( V_82 [ V_258 ] )
V_53 -> V_54 . V_103 = F_158 ( V_82 [ V_258 ] ) ;
if ( ! V_82 [ V_259 ] || F_158 ( V_82 [ V_259 ] ) )
V_53 -> V_54 . V_165 = F_11 ( V_169 ) ;
}
static int F_159 ( struct V_2 * V_3 )
{
struct V_33 * V_112 ;
V_112 = F_14 ( V_3 ) ;
V_112 -> V_3 = V_3 ;
strcpy ( V_112 -> V_53 . V_67 , V_3 -> V_67 ) ;
F_26 ( V_3 ) ;
V_3 -> V_7 = F_137 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_237 ;
return 0 ;
}
static void F_160 ( struct V_2 * V_3 )
{
F_161 ( V_3 ) ;
V_3 -> V_227 = & V_260 ;
V_3 -> V_229 = F_133 ;
V_3 -> V_196 = 0 ;
V_3 -> V_76 |= V_232 ;
V_3 -> V_76 |= V_235 ;
V_3 -> V_198 |= V_235 ;
}
static int F_162 ( struct V_37 * V_261 , struct V_2 * V_3 , struct V_245 * V_246 [] ,
struct V_245 * V_82 [] )
{
struct V_33 * V_66 ;
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
int V_72 ;
int V_114 ;
V_66 = F_14 ( V_3 ) ;
F_155 ( V_82 , & V_66 -> V_53 ) ;
if ( F_21 ( V_37 , & V_66 -> V_53 , V_3 -> type ) )
return - V_213 ;
if ( V_3 -> type == V_49 && ! V_246 [ V_249 ] )
F_163 ( V_3 ) ;
V_72 = F_26 ( V_3 ) ;
if ( ! V_246 [ V_262 ] )
V_3 -> V_72 = V_72 ;
if ( ! ( V_66 -> V_53 . V_74 & V_75 ) )
V_3 -> V_76 |= V_77 ;
V_114 = F_27 ( V_3 ) ;
if ( V_114 )
goto V_251;
F_28 ( V_3 ) ;
F_17 ( V_45 , V_66 ) ;
V_251:
return V_114 ;
}
static int F_164 ( struct V_2 * V_3 , struct V_245 * V_246 [] ,
struct V_245 * V_82 [] )
{
struct V_33 * V_42 , * V_66 ;
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
struct V_26 V_27 ;
int V_72 ;
if ( V_3 == V_45 -> V_58 )
return - V_212 ;
V_66 = F_14 ( V_3 ) ;
F_155 ( V_82 , & V_27 ) ;
V_42 = F_22 ( V_37 , & V_27 , 0 ) ;
if ( V_42 ) {
if ( V_42 -> V_3 != V_3 )
return - V_213 ;
} else {
V_42 = V_66 ;
if ( V_3 -> type != V_49 ) {
unsigned int V_214 = 0 ;
if ( F_13 ( V_27 . V_54 . V_56 ) )
V_214 = V_215 ;
else if ( V_27 . V_54 . V_56 )
V_214 = V_195 ;
if ( ( V_3 -> V_28 ^ V_214 ) &
( V_195 | V_215 ) )
return - V_212 ;
}
F_20 ( V_45 , V_42 ) ;
V_42 -> V_53 . V_54 . V_55 = V_27 . V_54 . V_55 ;
V_42 -> V_53 . V_54 . V_56 = V_27 . V_54 . V_56 ;
V_42 -> V_53 . V_32 = V_27 . V_32 ;
if ( V_3 -> type != V_49 ) {
memcpy ( V_3 -> V_216 , & V_27 . V_54 . V_55 , 4 ) ;
memcpy ( V_3 -> V_217 , & V_27 . V_54 . V_56 , 4 ) ;
}
F_17 ( V_45 , V_42 ) ;
F_121 ( V_3 ) ;
}
V_42 -> V_53 . V_163 = V_27 . V_163 ;
V_42 -> V_53 . V_54 . V_98 = V_27 . V_54 . V_98 ;
V_42 -> V_53 . V_54 . V_103 = V_27 . V_54 . V_103 ;
V_42 -> V_53 . V_54 . V_165 = V_27 . V_54 . V_165 ;
if ( V_42 -> V_53 . V_38 != V_27 . V_38 ) {
V_42 -> V_53 . V_38 = V_27 . V_38 ;
V_72 = F_26 ( V_3 ) ;
if ( ! V_246 [ V_262 ] )
V_3 -> V_72 = V_72 ;
F_121 ( V_3 ) ;
}
return 0 ;
}
static T_11 F_165 ( const struct V_2 * V_3 )
{
return
F_166 ( 4 ) +
F_166 ( 2 ) +
F_166 ( 2 ) +
F_166 ( 4 ) +
F_166 ( 4 ) +
F_166 ( 4 ) +
F_166 ( 4 ) +
F_166 ( 1 ) +
F_166 ( 1 ) +
F_166 ( 1 ) +
0 ;
}
static int F_167 ( struct V_78 * V_79 , const struct V_2 * V_3 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
struct V_26 * V_27 = & V_42 -> V_53 ;
if ( F_168 ( V_79 , V_253 , V_27 -> V_38 ) ||
F_169 ( V_79 , V_247 , V_27 -> V_30 ) ||
F_169 ( V_79 , V_248 , V_27 -> V_74 ) ||
F_170 ( V_79 , V_254 , V_27 -> V_32 ) ||
F_170 ( V_79 , V_255 , V_27 -> V_163 ) ||
F_170 ( V_79 , V_256 , V_27 -> V_54 . V_55 ) ||
F_170 ( V_79 , V_252 , V_27 -> V_54 . V_56 ) ||
F_171 ( V_79 , V_257 , V_27 -> V_54 . V_98 ) ||
F_171 ( V_79 , V_258 , V_27 -> V_54 . V_103 ) ||
F_171 ( V_79 , V_259 ,
! ! ( V_27 -> V_54 . V_165 & F_11 ( V_169 ) ) ) )
goto V_263;
return 0 ;
V_263:
return - V_264 ;
}
static int T_12 F_172 ( void )
{
int V_114 ;
F_173 ( L_4 ) ;
V_114 = F_174 ( & V_265 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 = F_175 ( & V_266 , V_267 ) ;
if ( V_114 < 0 ) {
F_173 ( L_5 , V_268 ) ;
goto V_269;
}
V_114 = F_176 ( & V_71 ) ;
if ( V_114 < 0 )
goto V_270;
V_114 = F_176 ( & V_271 ) ;
if ( V_114 < 0 )
goto V_272;
V_251:
return V_114 ;
V_272:
F_177 ( & V_71 ) ;
V_270:
F_178 ( & V_266 , V_267 ) ;
V_269:
F_179 ( & V_265 ) ;
goto V_251;
}
static void T_13 F_180 ( void )
{
F_177 ( & V_271 ) ;
F_177 ( & V_71 ) ;
if ( F_178 ( & V_266 , V_267 ) < 0 )
F_173 ( L_6 , V_268 ) ;
F_179 ( & V_265 ) ;
}
