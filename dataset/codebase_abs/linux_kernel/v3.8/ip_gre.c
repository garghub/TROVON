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
static T_8 F_67 ( struct V_78 * V_79 , struct V_2 * V_3 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
const struct V_81 * V_104 = F_43 ( V_79 ) ;
const struct V_81 * V_131 ;
struct V_132 V_133 ;
T_6 V_103 ;
T_2 V_134 ;
struct V_135 * V_136 ;
struct V_2 * V_137 ;
struct V_81 * V_54 ;
unsigned int V_138 ;
int V_139 ;
T_3 V_140 ;
int V_72 ;
T_6 V_98 ;
if ( V_79 -> V_116 == V_141 &&
F_68 ( V_79 ) )
goto V_142;
if ( V_3 -> type == V_49 )
F_69 ( V_79 ) -> V_28 = 0 ;
if ( V_3 -> V_143 && V_3 -> type == V_50 ) {
V_139 = 0 ;
if ( V_79 -> V_106 == F_11 ( V_107 ) )
V_131 = ( const struct V_81 * ) V_79 -> V_82 ;
else
V_131 = & V_112 -> V_53 . V_54 ;
} else {
V_139 = V_112 -> V_144 ;
V_131 = & V_112 -> V_53 . V_54 ;
}
if ( ( V_140 = V_131 -> V_56 ) == 0 ) {
if ( F_70 ( V_79 ) == NULL ) {
V_3 -> V_15 . V_21 ++ ;
goto V_142;
}
if ( V_79 -> V_106 == F_11 ( V_107 ) ) {
V_136 = F_53 ( V_79 ) ;
V_140 = F_71 ( V_136 , V_104 -> V_56 ) ;
}
#if F_72 ( V_145 )
else if ( V_79 -> V_106 == F_11 ( V_108 ) ) {
const struct V_146 * V_147 ;
struct V_148 * V_149 ;
bool V_150 ;
int V_151 ;
V_149 = F_73 ( F_70 ( V_79 ) , & F_74 ( V_79 ) -> V_56 ) ;
if ( V_149 == NULL )
goto V_142;
V_147 = ( const struct V_146 * ) & V_149 -> V_152 ;
V_151 = F_75 ( V_147 ) ;
if ( V_151 == V_153 ) {
V_147 = & F_74 ( V_79 ) -> V_56 ;
V_151 = F_75 ( V_147 ) ;
}
if ( ( V_151 & V_154 ) == 0 )
V_150 = true ;
else {
V_150 = false ;
V_140 = V_147 -> V_155 [ 3 ] ;
}
F_76 ( V_149 ) ;
if ( V_150 )
goto V_156;
}
#endif
else
goto V_142;
}
V_98 = V_131 -> V_98 ;
V_103 = V_131 -> V_103 ;
if ( V_103 == 1 ) {
V_103 = 0 ;
if ( V_79 -> V_106 == F_11 ( V_107 ) )
V_103 = V_104 -> V_103 ;
else if ( V_79 -> V_106 == F_11 ( V_108 ) )
V_103 = F_39 ( ( const struct V_109 * ) V_104 ) ;
}
V_136 = F_77 ( F_8 ( V_3 ) , & V_133 , V_140 , V_131 -> V_55 ,
V_112 -> V_53 . V_157 , F_78 ( V_103 ) ,
V_112 -> V_53 . V_38 ) ;
if ( F_79 ( V_136 ) ) {
V_3 -> V_15 . V_22 ++ ;
goto V_142;
}
V_137 = V_136 -> V_140 . V_3 ;
if ( V_137 == V_3 ) {
F_80 ( V_136 ) ;
V_3 -> V_15 . V_158 ++ ;
goto V_142;
}
V_134 = V_131 -> V_159 ;
if ( V_134 )
V_72 = F_81 ( & V_136 -> V_140 ) - V_3 -> V_160 - V_112 -> V_144 ;
else
V_72 = F_70 ( V_79 ) ? F_81 ( F_70 ( V_79 ) ) : V_3 -> V_72 ;
if ( F_70 ( V_79 ) )
F_70 ( V_79 ) -> V_161 -> V_162 ( F_70 ( V_79 ) , NULL , V_79 , V_72 ) ;
if ( V_79 -> V_106 == F_11 ( V_107 ) ) {
V_134 |= ( V_104 -> V_159 & F_11 ( V_163 ) ) ;
if ( ( V_104 -> V_159 & F_11 ( V_163 ) ) &&
V_72 < F_82 ( V_104 -> V_164 ) ) {
F_65 ( V_79 , V_90 , V_96 , F_83 ( V_72 ) ) ;
F_80 ( V_136 ) ;
goto V_142;
}
}
#if F_72 ( V_145 )
else if ( V_79 -> V_106 == F_11 ( V_108 ) ) {
struct V_165 * V_166 = (struct V_165 * ) F_70 ( V_79 ) ;
if ( V_166 && V_72 < F_81 ( F_70 ( V_79 ) ) && V_72 >= V_167 ) {
if ( ( V_112 -> V_53 . V_54 . V_56 &&
! F_13 ( V_112 -> V_53 . V_54 . V_56 ) ) ||
V_166 -> V_168 . V_169 == 128 ) {
V_166 -> V_170 |= V_171 ;
F_84 ( F_70 ( V_79 ) , V_172 , V_72 ) ;
}
}
if ( V_72 >= V_167 && V_72 < V_79 -> V_129 - V_112 -> V_144 + V_139 ) {
F_85 ( V_79 , V_173 , 0 , V_72 ) ;
F_80 ( V_136 ) ;
goto V_142;
}
}
#endif
if ( V_112 -> V_102 > 0 ) {
if ( F_37 ( V_99 ,
V_112 -> V_100 + V_101 ) ) {
V_112 -> V_102 -- ;
F_86 ( V_79 ) ;
} else
V_112 -> V_102 = 0 ;
}
V_138 = F_87 ( V_137 ) + V_139 + V_136 -> V_140 . V_174 ;
if ( F_88 ( V_79 ) < V_138 || F_89 ( V_79 ) ||
( F_90 ( V_79 ) && ! F_91 ( V_79 , 0 ) ) ) {
struct V_78 * V_175 = F_92 ( V_79 , V_138 ) ;
if ( V_138 > V_3 -> V_176 )
V_3 -> V_176 = V_138 ;
if ( ! V_175 ) {
F_80 ( V_136 ) ;
V_3 -> V_15 . V_23 ++ ;
F_93 ( V_79 ) ;
return V_177 ;
}
if ( V_79 -> V_178 )
F_94 ( V_175 , V_79 -> V_178 ) ;
F_93 ( V_79 ) ;
V_79 = V_175 ;
V_104 = F_43 ( V_79 ) ;
}
F_95 ( V_79 , V_139 ) ;
F_57 ( V_79 ) ;
F_96 ( V_79 , sizeof( * V_54 ) ) ;
memset ( & ( F_69 ( V_79 ) -> V_179 ) , 0 , sizeof( F_69 ( V_79 ) -> V_179 ) ) ;
F_69 ( V_79 ) -> V_28 &= ~ ( V_180 | V_181 |
V_182 ) ;
F_97 ( V_79 ) ;
F_98 ( V_79 , & V_136 -> V_140 ) ;
V_54 = F_43 ( V_79 ) ;
V_54 -> V_183 = 4 ;
V_54 -> V_83 = sizeof( struct V_81 ) >> 2 ;
V_54 -> V_159 = V_134 ;
V_54 -> V_106 = V_97 ;
V_54 -> V_103 = F_38 ( V_103 , V_104 , V_79 ) ;
V_54 -> V_56 = V_133 . V_56 ;
V_54 -> V_55 = V_133 . V_55 ;
V_54 -> V_98 = V_98 ;
if ( V_98 == 0 ) {
if ( V_79 -> V_106 == F_11 ( V_107 ) )
V_54 -> V_98 = V_104 -> V_98 ;
#if F_72 ( V_145 )
else if ( V_79 -> V_106 == F_11 ( V_108 ) )
V_54 -> V_98 = ( ( const struct V_109 * ) V_104 ) -> V_184 ;
#endif
else
V_54 -> V_98 = F_99 ( & V_136 -> V_140 ) ;
}
( ( T_2 * ) ( V_54 + 1 ) ) [ 0 ] = V_112 -> V_53 . V_74 ;
( ( T_2 * ) ( V_54 + 1 ) ) [ 1 ] = ( V_3 -> type == V_49 ) ?
F_11 ( V_48 ) : V_79 -> V_106 ;
if ( V_112 -> V_53 . V_74 & ( V_31 | V_86 | V_75 ) ) {
T_3 * V_185 = ( T_3 * ) ( ( ( T_6 * ) V_54 ) + V_112 -> V_144 - 4 ) ;
if ( V_112 -> V_53 . V_74 & V_75 ) {
++ V_112 -> V_186 ;
* V_185 = F_83 ( V_112 -> V_186 ) ;
V_185 -- ;
}
if ( V_112 -> V_53 . V_74 & V_31 ) {
* V_185 = V_112 -> V_53 . V_157 ;
V_185 -- ;
}
if ( V_112 -> V_53 . V_74 & V_86 ) {
int V_113 = F_100 ( V_79 ) ;
* V_185 = 0 ;
* ( T_7 * ) V_185 = F_44 ( F_101 ( V_79 , V_113 ,
V_79 -> V_129 - V_113 ,
0 ) ) ;
}
}
F_102 ( V_79 , V_3 ) ;
return V_177 ;
#if F_72 ( V_145 )
V_156:
F_86 ( V_79 ) ;
#endif
V_142:
V_3 -> V_15 . V_25 ++ ;
F_93 ( V_79 ) ;
return V_177 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_2 * V_137 = NULL ;
struct V_33 * V_112 ;
const struct V_81 * V_54 ;
int V_144 = V_187 ;
int V_72 = V_188 ;
int V_189 = sizeof( struct V_81 ) + 4 ;
V_112 = F_14 ( V_3 ) ;
V_54 = & V_112 -> V_53 . V_54 ;
if ( V_54 -> V_56 ) {
struct V_132 V_133 ;
struct V_135 * V_136 ;
V_136 = F_77 ( F_8 ( V_3 ) , & V_133 ,
V_54 -> V_56 , V_54 -> V_55 ,
V_112 -> V_53 . V_157 ,
F_78 ( V_54 -> V_103 ) ,
V_112 -> V_53 . V_38 ) ;
if ( ! F_79 ( V_136 ) ) {
V_137 = V_136 -> V_140 . V_3 ;
F_80 ( V_136 ) ;
}
if ( V_3 -> type != V_49 )
V_3 -> V_28 |= V_190 ;
}
if ( ! V_137 && V_112 -> V_53 . V_38 )
V_137 = F_103 ( F_8 ( V_3 ) , V_112 -> V_53 . V_38 ) ;
if ( V_137 ) {
V_144 = V_137 -> V_160 + V_137 -> V_176 ;
V_72 = V_137 -> V_72 ;
}
V_3 -> V_191 = V_112 -> V_53 . V_38 ;
if ( V_112 -> V_53 . V_74 & ( V_86 | V_31 | V_75 ) ) {
if ( V_112 -> V_53 . V_74 & V_86 )
V_189 += 4 ;
if ( V_112 -> V_53 . V_74 & V_31 )
V_189 += 4 ;
if ( V_112 -> V_53 . V_74 & V_75 )
V_189 += 4 ;
}
V_3 -> V_176 = V_189 + V_144 ;
V_72 -= V_3 -> V_160 + V_189 ;
if ( V_72 < 68 )
V_72 = 68 ;
V_112 -> V_144 = V_189 ;
return V_72 ;
}
static int
F_104 ( struct V_2 * V_3 , struct V_192 * V_193 , int V_194 )
{
int V_114 = 0 ;
struct V_26 V_27 ;
struct V_33 * V_42 ;
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
switch ( V_194 ) {
case V_195 :
V_42 = NULL ;
if ( V_3 == V_45 -> V_58 ) {
if ( F_105 ( & V_27 , V_193 -> V_196 . V_197 , sizeof( V_27 ) ) ) {
V_114 = - V_198 ;
break;
}
V_42 = F_22 ( V_37 , & V_27 , 0 ) ;
}
if ( V_42 == NULL )
V_42 = F_14 ( V_3 ) ;
memcpy ( & V_27 , & V_42 -> V_53 , sizeof( V_27 ) ) ;
if ( F_106 ( V_193 -> V_196 . V_197 , & V_27 , sizeof( V_27 ) ) )
V_114 = - V_198 ;
break;
case V_199 :
case V_200 :
V_114 = - V_201 ;
if ( ! F_107 ( V_37 -> V_202 , V_203 ) )
goto V_204;
V_114 = - V_198 ;
if ( F_105 ( & V_27 , V_193 -> V_196 . V_197 , sizeof( V_27 ) ) )
goto V_204;
V_114 = - V_205 ;
if ( V_27 . V_54 . V_183 != 4 || V_27 . V_54 . V_106 != V_97 ||
V_27 . V_54 . V_83 != 5 || ( V_27 . V_54 . V_159 & F_11 ( ~ V_163 ) ) ||
( ( V_27 . V_30 | V_27 . V_74 ) & ( V_88 | V_87 ) ) )
goto V_204;
if ( V_27 . V_54 . V_98 )
V_27 . V_54 . V_159 |= F_11 ( V_163 ) ;
if ( ! ( V_27 . V_30 & V_31 ) )
V_27 . V_32 = 0 ;
if ( ! ( V_27 . V_74 & V_31 ) )
V_27 . V_157 = 0 ;
V_42 = F_22 ( V_37 , & V_27 , V_194 == V_199 ) ;
if ( V_3 != V_45 -> V_58 && V_194 == V_200 ) {
if ( V_42 != NULL ) {
if ( V_42 -> V_3 != V_3 ) {
V_114 = - V_206 ;
break;
}
} else {
unsigned int V_207 = 0 ;
V_42 = F_14 ( V_3 ) ;
if ( F_13 ( V_27 . V_54 . V_56 ) )
V_207 = V_208 ;
else if ( V_27 . V_54 . V_56 )
V_207 = V_190 ;
if ( ( V_3 -> V_28 ^ V_207 ) & ( V_190 | V_208 ) ) {
V_114 = - V_205 ;
break;
}
F_20 ( V_45 , V_42 ) ;
F_108 () ;
V_42 -> V_53 . V_54 . V_55 = V_27 . V_54 . V_55 ;
V_42 -> V_53 . V_54 . V_56 = V_27 . V_54 . V_56 ;
V_42 -> V_53 . V_32 = V_27 . V_32 ;
V_42 -> V_53 . V_157 = V_27 . V_157 ;
memcpy ( V_3 -> V_209 , & V_27 . V_54 . V_55 , 4 ) ;
memcpy ( V_3 -> V_210 , & V_27 . V_54 . V_56 , 4 ) ;
F_17 ( V_45 , V_42 ) ;
F_109 ( V_3 ) ;
}
}
if ( V_42 ) {
V_114 = 0 ;
if ( V_194 == V_200 ) {
V_42 -> V_53 . V_54 . V_98 = V_27 . V_54 . V_98 ;
V_42 -> V_53 . V_54 . V_103 = V_27 . V_54 . V_103 ;
V_42 -> V_53 . V_54 . V_159 = V_27 . V_54 . V_159 ;
if ( V_42 -> V_53 . V_38 != V_27 . V_38 ) {
V_42 -> V_53 . V_38 = V_27 . V_38 ;
V_3 -> V_72 = F_26 ( V_3 ) ;
F_109 ( V_3 ) ;
}
}
if ( F_106 ( V_193 -> V_196 . V_197 , & V_42 -> V_53 , sizeof( V_27 ) ) )
V_114 = - V_198 ;
} else
V_114 = ( V_194 == V_199 ? - V_211 : - V_212 ) ;
break;
case V_213 :
V_114 = - V_201 ;
if ( ! F_107 ( V_37 -> V_202 , V_203 ) )
goto V_204;
if ( V_3 == V_45 -> V_58 ) {
V_114 = - V_198 ;
if ( F_105 ( & V_27 , V_193 -> V_196 . V_197 , sizeof( V_27 ) ) )
goto V_204;
V_114 = - V_212 ;
if ( ( V_42 = F_22 ( V_37 , & V_27 , 0 ) ) == NULL )
goto V_204;
V_114 = - V_201 ;
if ( V_42 == F_14 ( V_45 -> V_58 ) )
goto V_204;
V_3 = V_42 -> V_3 ;
}
F_110 ( V_3 ) ;
V_114 = 0 ;
break;
default:
V_114 = - V_205 ;
}
V_204:
return V_114 ;
}
static int F_111 ( struct V_2 * V_3 , int V_214 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
if ( V_214 < 68 ||
V_214 > 0xFFF8 - V_3 -> V_160 - V_112 -> V_144 )
return - V_205 ;
V_3 -> V_72 = V_214 ;
return 0 ;
}
static int F_112 ( struct V_78 * V_79 , struct V_2 * V_3 ,
unsigned short type ,
const void * V_56 , const void * V_55 , unsigned int V_129 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
struct V_81 * V_54 = (struct V_81 * ) F_95 ( V_79 , V_42 -> V_144 ) ;
T_2 * V_27 = ( T_2 * ) ( V_54 + 1 ) ;
memcpy ( V_54 , & V_42 -> V_53 . V_54 , sizeof( struct V_81 ) ) ;
V_27 [ 0 ] = V_42 -> V_53 . V_74 ;
V_27 [ 1 ] = F_11 ( type ) ;
if ( V_55 )
memcpy ( & V_54 -> V_55 , V_55 , 4 ) ;
if ( V_56 )
memcpy ( & V_54 -> V_56 , V_56 , 4 ) ;
if ( V_54 -> V_56 )
return V_42 -> V_144 ;
return - V_42 -> V_144 ;
}
static int F_113 ( const struct V_78 * V_79 , unsigned char * V_215 )
{
const struct V_81 * V_54 = ( const struct V_81 * ) F_114 ( V_79 ) ;
memcpy ( V_215 , & V_54 -> V_55 , 4 ) ;
return 4 ;
}
static int F_115 ( struct V_2 * V_3 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
if ( F_13 ( V_42 -> V_53 . V_54 . V_56 ) ) {
struct V_132 V_133 ;
struct V_135 * V_136 ;
V_136 = F_77 ( F_8 ( V_3 ) , & V_133 ,
V_42 -> V_53 . V_54 . V_56 ,
V_42 -> V_53 . V_54 . V_55 ,
V_42 -> V_53 . V_157 ,
F_78 ( V_42 -> V_53 . V_54 . V_103 ) ,
V_42 -> V_53 . V_38 ) ;
if ( F_79 ( V_136 ) )
return - V_216 ;
V_3 = V_136 -> V_140 . V_3 ;
F_80 ( V_136 ) ;
if ( F_116 ( V_3 ) == NULL )
return - V_216 ;
V_42 -> V_217 = V_3 -> V_39 ;
F_117 ( F_116 ( V_3 ) , V_42 -> V_53 . V_54 . V_56 ) ;
}
return 0 ;
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
if ( F_13 ( V_42 -> V_53 . V_54 . V_56 ) && V_42 -> V_217 ) {
struct V_218 * V_219 ;
V_219 = F_119 ( F_8 ( V_3 ) , V_42 -> V_217 ) ;
if ( V_219 )
F_120 ( V_219 , V_42 -> V_53 . V_54 . V_56 ) ;
}
return 0 ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
F_122 ( & V_112 -> V_130 ) ;
F_123 ( V_3 -> V_7 ) ;
F_29 ( V_3 ) ;
}
static void V_69 ( struct V_2 * V_3 )
{
V_3 -> V_220 = & V_221 ;
V_3 -> V_222 = F_121 ;
V_3 -> type = V_50 ;
V_3 -> V_176 = V_187 + sizeof( struct V_81 ) + 4 ;
V_3 -> V_72 = V_188 - sizeof( struct V_81 ) - 4 ;
V_3 -> V_28 = V_223 ;
V_3 -> V_191 = 0 ;
V_3 -> V_224 = 4 ;
V_3 -> V_76 |= V_225 ;
V_3 -> V_226 &= ~ V_227 ;
V_3 -> V_76 |= V_228 ;
V_3 -> V_229 |= V_228 ;
}
static int F_124 ( struct V_2 * V_3 )
{
struct V_33 * V_112 ;
struct V_81 * V_54 ;
int V_114 ;
V_112 = F_14 ( V_3 ) ;
V_54 = & V_112 -> V_53 . V_54 ;
V_112 -> V_3 = V_3 ;
strcpy ( V_112 -> V_53 . V_67 , V_3 -> V_67 ) ;
memcpy ( V_3 -> V_209 , & V_112 -> V_53 . V_54 . V_55 , 4 ) ;
memcpy ( V_3 -> V_210 , & V_112 -> V_53 . V_54 . V_56 , 4 ) ;
if ( V_54 -> V_56 ) {
#ifdef F_51
if ( F_13 ( V_54 -> V_56 ) ) {
if ( ! V_54 -> V_55 )
return - V_205 ;
V_3 -> V_28 = V_208 ;
V_3 -> V_143 = & V_230 ;
}
#endif
} else
V_3 -> V_143 = & V_230 ;
V_3 -> V_7 = F_125 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_231 ;
V_114 = F_126 ( & V_112 -> V_130 , V_3 ) ;
if ( V_114 ) {
F_123 ( V_3 -> V_7 ) ;
return V_114 ;
}
return 0 ;
}
static void F_127 ( struct V_2 * V_3 )
{
struct V_33 * V_112 = F_14 ( V_3 ) ;
struct V_81 * V_54 = & V_112 -> V_53 . V_54 ;
V_112 -> V_3 = V_3 ;
strcpy ( V_112 -> V_53 . V_67 , V_3 -> V_67 ) ;
V_54 -> V_183 = 4 ;
V_54 -> V_106 = V_97 ;
V_54 -> V_83 = 5 ;
V_112 -> V_144 = sizeof( struct V_81 ) + 4 ;
F_28 ( V_3 ) ;
}
static void F_128 ( struct V_44 * V_45 , struct V_232 * V_233 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_234 ; V_59 ++ ) {
struct V_33 * V_42 ;
V_42 = F_19 ( V_45 -> V_61 [ V_60 ] [ V_59 ] ) ;
while ( V_42 != NULL ) {
F_129 ( V_42 -> V_3 , V_233 ) ;
V_42 = F_19 ( V_42 -> V_63 ) ;
}
}
}
}
static int T_9 F_130 ( struct V_37 * V_37 )
{
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
int V_114 ;
V_45 -> V_58 = F_24 ( sizeof( struct V_33 ) , L_3 ,
V_69 ) ;
if ( ! V_45 -> V_58 ) {
V_114 = - V_231 ;
goto V_235;
}
F_25 ( V_45 -> V_58 , V_37 ) ;
F_127 ( V_45 -> V_58 ) ;
V_45 -> V_58 -> V_70 = & V_71 ;
if ( ( V_114 = F_131 ( V_45 -> V_58 ) ) )
goto V_236;
F_18 ( V_45 -> V_237 [ 0 ] ,
F_14 ( V_45 -> V_58 ) ) ;
return 0 ;
V_236:
F_121 ( V_45 -> V_58 ) ;
V_235:
return V_114 ;
}
static void T_10 F_132 ( struct V_37 * V_37 )
{
struct V_44 * V_45 ;
F_133 ( V_238 ) ;
V_45 = F_10 ( V_37 , V_46 ) ;
F_134 () ;
F_128 ( V_45 , & V_238 ) ;
F_135 ( & V_238 ) ;
F_136 () ;
}
static int F_137 ( struct V_239 * V_240 [] , struct V_239 * V_82 [] )
{
T_2 V_28 ;
if ( ! V_82 )
return 0 ;
V_28 = 0 ;
if ( V_82 [ V_241 ] )
V_28 |= F_138 ( V_82 [ V_241 ] ) ;
if ( V_82 [ V_242 ] )
V_28 |= F_138 ( V_82 [ V_242 ] ) ;
if ( V_28 & ( V_88 | V_87 ) )
return - V_205 ;
return 0 ;
}
static int F_139 ( struct V_239 * V_240 [] , struct V_239 * V_82 [] )
{
T_3 V_56 ;
if ( V_240 [ V_243 ] ) {
if ( F_140 ( V_240 [ V_243 ] ) != V_244 )
return - V_205 ;
if ( ! F_141 ( F_142 ( V_240 [ V_243 ] ) ) )
return - V_216 ;
}
if ( ! V_82 )
goto V_245;
if ( V_82 [ V_246 ] ) {
memcpy ( & V_56 , F_142 ( V_82 [ V_246 ] ) , 4 ) ;
if ( ! V_56 )
return - V_205 ;
}
V_245:
return F_137 ( V_240 , V_82 ) ;
}
static void F_143 ( struct V_239 * V_82 [] ,
struct V_26 * V_53 )
{
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_54 . V_106 = V_97 ;
if ( ! V_82 )
return;
if ( V_82 [ V_247 ] )
V_53 -> V_38 = F_144 ( V_82 [ V_247 ] ) ;
if ( V_82 [ V_241 ] )
V_53 -> V_30 = F_138 ( V_82 [ V_241 ] ) ;
if ( V_82 [ V_242 ] )
V_53 -> V_74 = F_138 ( V_82 [ V_242 ] ) ;
if ( V_82 [ V_248 ] )
V_53 -> V_32 = F_145 ( V_82 [ V_248 ] ) ;
if ( V_82 [ V_249 ] )
V_53 -> V_157 = F_145 ( V_82 [ V_249 ] ) ;
if ( V_82 [ V_250 ] )
V_53 -> V_54 . V_55 = F_145 ( V_82 [ V_250 ] ) ;
if ( V_82 [ V_246 ] )
V_53 -> V_54 . V_56 = F_145 ( V_82 [ V_246 ] ) ;
if ( V_82 [ V_251 ] )
V_53 -> V_54 . V_98 = F_146 ( V_82 [ V_251 ] ) ;
if ( V_82 [ V_252 ] )
V_53 -> V_54 . V_103 = F_146 ( V_82 [ V_252 ] ) ;
if ( ! V_82 [ V_253 ] || F_146 ( V_82 [ V_253 ] ) )
V_53 -> V_54 . V_159 = F_11 ( V_163 ) ;
}
static int F_147 ( struct V_2 * V_3 )
{
struct V_33 * V_112 ;
V_112 = F_14 ( V_3 ) ;
V_112 -> V_3 = V_3 ;
strcpy ( V_112 -> V_53 . V_67 , V_3 -> V_67 ) ;
F_26 ( V_3 ) ;
V_3 -> V_7 = F_125 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_231 ;
return 0 ;
}
static void F_148 ( struct V_2 * V_3 )
{
F_149 ( V_3 ) ;
V_3 -> V_220 = & V_254 ;
V_3 -> V_222 = F_121 ;
V_3 -> V_191 = 0 ;
V_3 -> V_76 |= V_225 ;
}
static int F_150 ( struct V_37 * V_255 , struct V_2 * V_3 , struct V_239 * V_240 [] ,
struct V_239 * V_82 [] )
{
struct V_33 * V_66 ;
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
int V_72 ;
int V_114 ;
V_66 = F_14 ( V_3 ) ;
F_143 ( V_82 , & V_66 -> V_53 ) ;
if ( F_21 ( V_37 , & V_66 -> V_53 , V_3 -> type ) )
return - V_206 ;
if ( V_3 -> type == V_49 && ! V_240 [ V_243 ] )
F_151 ( V_3 ) ;
V_72 = F_26 ( V_3 ) ;
if ( ! V_240 [ V_256 ] )
V_3 -> V_72 = V_72 ;
if ( ! ( V_66 -> V_53 . V_74 & V_75 ) )
V_3 -> V_76 |= V_77 ;
V_114 = F_27 ( V_3 ) ;
if ( V_114 )
goto V_245;
F_28 ( V_3 ) ;
F_17 ( V_45 , V_66 ) ;
V_245:
return V_114 ;
}
static int F_152 ( struct V_2 * V_3 , struct V_239 * V_240 [] ,
struct V_239 * V_82 [] )
{
struct V_33 * V_42 , * V_66 ;
struct V_37 * V_37 = F_8 ( V_3 ) ;
struct V_44 * V_45 = F_10 ( V_37 , V_46 ) ;
struct V_26 V_27 ;
int V_72 ;
if ( V_3 == V_45 -> V_58 )
return - V_205 ;
V_66 = F_14 ( V_3 ) ;
F_143 ( V_82 , & V_27 ) ;
V_42 = F_22 ( V_37 , & V_27 , 0 ) ;
if ( V_42 ) {
if ( V_42 -> V_3 != V_3 )
return - V_206 ;
} else {
V_42 = V_66 ;
if ( V_3 -> type != V_49 ) {
unsigned int V_207 = 0 ;
if ( F_13 ( V_27 . V_54 . V_56 ) )
V_207 = V_208 ;
else if ( V_27 . V_54 . V_56 )
V_207 = V_190 ;
if ( ( V_3 -> V_28 ^ V_207 ) &
( V_190 | V_208 ) )
return - V_205 ;
}
F_20 ( V_45 , V_42 ) ;
V_42 -> V_53 . V_54 . V_55 = V_27 . V_54 . V_55 ;
V_42 -> V_53 . V_54 . V_56 = V_27 . V_54 . V_56 ;
V_42 -> V_53 . V_32 = V_27 . V_32 ;
if ( V_3 -> type != V_49 ) {
memcpy ( V_3 -> V_209 , & V_27 . V_54 . V_55 , 4 ) ;
memcpy ( V_3 -> V_210 , & V_27 . V_54 . V_56 , 4 ) ;
}
F_17 ( V_45 , V_42 ) ;
F_109 ( V_3 ) ;
}
V_42 -> V_53 . V_157 = V_27 . V_157 ;
V_42 -> V_53 . V_54 . V_98 = V_27 . V_54 . V_98 ;
V_42 -> V_53 . V_54 . V_103 = V_27 . V_54 . V_103 ;
V_42 -> V_53 . V_54 . V_159 = V_27 . V_54 . V_159 ;
if ( V_42 -> V_53 . V_38 != V_27 . V_38 ) {
V_42 -> V_53 . V_38 = V_27 . V_38 ;
V_72 = F_26 ( V_3 ) ;
if ( ! V_240 [ V_256 ] )
V_3 -> V_72 = V_72 ;
F_109 ( V_3 ) ;
}
return 0 ;
}
static T_11 F_153 ( const struct V_2 * V_3 )
{
return
F_154 ( 4 ) +
F_154 ( 2 ) +
F_154 ( 2 ) +
F_154 ( 4 ) +
F_154 ( 4 ) +
F_154 ( 4 ) +
F_154 ( 4 ) +
F_154 ( 1 ) +
F_154 ( 1 ) +
F_154 ( 1 ) +
0 ;
}
static int F_155 ( struct V_78 * V_79 , const struct V_2 * V_3 )
{
struct V_33 * V_42 = F_14 ( V_3 ) ;
struct V_26 * V_27 = & V_42 -> V_53 ;
if ( F_156 ( V_79 , V_247 , V_27 -> V_38 ) ||
F_157 ( V_79 , V_241 , V_27 -> V_30 ) ||
F_157 ( V_79 , V_242 , V_27 -> V_74 ) ||
F_158 ( V_79 , V_248 , V_27 -> V_32 ) ||
F_158 ( V_79 , V_249 , V_27 -> V_157 ) ||
F_158 ( V_79 , V_250 , V_27 -> V_54 . V_55 ) ||
F_158 ( V_79 , V_246 , V_27 -> V_54 . V_56 ) ||
F_159 ( V_79 , V_251 , V_27 -> V_54 . V_98 ) ||
F_159 ( V_79 , V_252 , V_27 -> V_54 . V_103 ) ||
F_159 ( V_79 , V_253 ,
! ! ( V_27 -> V_54 . V_159 & F_11 ( V_163 ) ) ) )
goto V_257;
return 0 ;
V_257:
return - V_258 ;
}
static int T_12 F_160 ( void )
{
int V_114 ;
F_161 ( L_4 ) ;
V_114 = F_162 ( & V_259 ) ;
if ( V_114 < 0 )
return V_114 ;
V_114 = F_163 ( & V_260 , V_261 ) ;
if ( V_114 < 0 ) {
F_161 ( L_5 , V_262 ) ;
goto V_263;
}
V_114 = F_164 ( & V_71 ) ;
if ( V_114 < 0 )
goto V_264;
V_114 = F_164 ( & V_265 ) ;
if ( V_114 < 0 )
goto V_266;
V_245:
return V_114 ;
V_266:
F_165 ( & V_71 ) ;
V_264:
F_166 ( & V_260 , V_261 ) ;
V_263:
F_167 ( & V_259 ) ;
goto V_245;
}
static void T_13 F_168 ( void )
{
F_165 ( & V_265 ) ;
F_165 ( & V_71 ) ;
if ( F_166 ( & V_260 , V_261 ) < 0 )
F_161 ( L_6 , V_262 ) ;
F_167 ( & V_259 ) ;
}
