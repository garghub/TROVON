int F_1 ( void )
{
return V_1 ;
}
static bool F_2 ( struct V_2 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 = {
. V_7 = * V_4 ,
} ;
struct V_8 * V_9 = F_3 ( V_2 , NULL , & V_6 ) ;
bool V_10 ;
V_10 = ! V_9 -> error && V_9 -> V_11 && ( V_9 -> V_11 -> V_12 & V_13 ) ;
F_4 ( V_9 ) ;
return V_10 ;
}
static void F_5 ( struct V_14 * V_15 )
{
struct V_16 V_17 ;
static int V_18 = 0 ;
int V_19 ;
int V_20 ;
int V_21 = - 1 ;
F_6 ( & V_17 ) ;
V_19 = V_17 . V_22 + V_17 . V_23 ;
V_20 = ( V_19 < V_15 -> V_24 ) ;
F_7 () ;
F_8 ( & V_15 -> V_25 ) ;
switch ( V_15 -> V_26 ) {
case 0 :
F_9 ( & V_15 -> V_27 , 0 ) ;
break;
case 1 :
if ( V_20 ) {
F_9 ( & V_15 -> V_27 , 1 ) ;
V_15 -> V_26 = 2 ;
} else {
F_9 ( & V_15 -> V_27 , 0 ) ;
}
break;
case 2 :
if ( V_20 ) {
F_9 ( & V_15 -> V_27 , 1 ) ;
} else {
F_9 ( & V_15 -> V_27 , 0 ) ;
V_15 -> V_26 = 1 ;
} ;
break;
case 3 :
F_9 ( & V_15 -> V_27 , 1 ) ;
break;
}
F_10 ( & V_15 -> V_25 ) ;
F_8 ( & V_15 -> V_28 ) ;
switch ( V_15 -> V_29 ) {
case 0 :
V_15 -> V_30 = 0 ;
break;
case 1 :
if ( V_20 ) {
V_15 -> V_30 = V_15 -> V_31
= V_15 -> V_24 /
( V_15 -> V_24 - V_19 ) ;
V_15 -> V_29 = 2 ;
} else {
V_15 -> V_30 = 0 ;
}
break;
case 2 :
if ( V_20 ) {
V_15 -> V_30 = V_15 -> V_31
= V_15 -> V_24 /
( V_15 -> V_24 - V_19 ) ;
} else {
V_15 -> V_30 = 0 ;
V_15 -> V_29 = 1 ;
}
break;
case 3 :
V_15 -> V_30 = V_15 -> V_32 ;
break;
}
F_10 ( & V_15 -> V_28 ) ;
F_8 ( & V_15 -> V_33 ) ;
switch ( V_15 -> V_34 ) {
case 0 :
if ( V_18 >= 2 )
V_21 = 0 ;
break;
case 1 :
if ( V_20 ) {
if ( V_18 < 2 )
V_21 = 1 ;
V_15 -> V_34 = 2 ;
} else {
if ( V_18 >= 2 )
V_21 = 0 ;
}
break;
case 2 :
if ( V_20 ) {
if ( V_18 < 2 )
V_21 = 1 ;
} else {
if ( V_18 >= 2 )
V_21 = 0 ;
V_15 -> V_34 = 1 ;
}
break;
case 3 :
if ( V_18 < 2 )
V_21 = 1 ;
break;
}
V_18 = V_15 -> V_34 ;
if ( V_21 >= 0 )
F_11 ( V_15 ,
V_15 -> V_34 > 1 ) ;
F_10 ( & V_15 -> V_33 ) ;
F_12 () ;
}
static void F_13 ( struct V_35 * V_36 )
{
struct V_14 * V_15 =
F_14 ( V_36 , struct V_14 , V_37 . V_36 ) ;
F_5 ( V_15 ) ;
if ( F_15 ( & V_15 -> V_27 ) )
F_16 ( V_15 -> V_2 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
}
int
F_18 ( void )
{
return F_19 ( V_39 ) ;
}
void
F_20 ( void )
{
F_21 ( V_39 ) ;
}
static inline unsigned int
F_22 ( struct V_2 * V_2 , int V_40 , unsigned int V_41 ,
const union V_42 * V_4 , T_1 V_43 )
{
register unsigned int V_44 = F_23 ( V_43 ) ;
T_2 V_45 = V_4 -> V_46 ;
T_3 V_47 ;
#ifdef F_24
if ( V_40 == V_48 )
V_45 = V_4 -> V_49 [ 0 ] ^ V_4 -> V_49 [ 1 ] ^
V_4 -> V_49 [ 2 ] ^ V_4 -> V_49 [ 3 ] ;
#endif
V_47 = F_25 ( V_45 ) ;
V_47 ^= ( ( V_50 ) V_2 >> 8 ) ;
return ( V_41 ^ V_47 ^ ( V_44 >> V_51 ) ^ V_44 ) &
V_52 ;
}
static inline unsigned int F_26 ( struct V_2 * V_2 , T_3 V_53 )
{
return ( ( ( V_50 ) V_2 >> 8 ) ^ V_53 ) & V_52 ;
}
static int F_27 ( struct V_54 * V_55 )
{
unsigned int V_56 ;
if ( V_55 -> V_12 & V_57 ) {
F_28 ( L_1 ,
V_58 , F_29 ( 0 ) ) ;
return 0 ;
}
if ( V_55 -> V_53 == 0 ) {
V_56 = F_22 ( V_55 -> V_2 , V_55 -> V_40 , V_55 -> V_59 ,
& V_55 -> V_4 , V_55 -> V_43 ) ;
F_30 ( & V_55 -> V_60 , & V_61 [ V_56 ] ) ;
} else {
V_56 = F_26 ( V_55 -> V_2 , V_55 -> V_53 ) ;
F_30 ( & V_55 -> V_62 , & V_63 [ V_56 ] ) ;
}
V_55 -> V_12 |= V_57 ;
F_31 ( & V_55 -> V_64 ) ;
return 1 ;
}
static int F_32 ( struct V_54 * V_55 )
{
if ( ! ( V_55 -> V_12 & V_57 ) ) {
F_28 ( L_2 ,
V_58 , F_29 ( 0 ) ) ;
return 0 ;
}
if ( V_55 -> V_53 == 0 ) {
F_33 ( & V_55 -> V_60 ) ;
} else {
F_33 ( & V_55 -> V_62 ) ;
}
V_55 -> V_12 &= ~ V_57 ;
F_34 ( & V_55 -> V_64 ) ;
return 1 ;
}
static inline struct V_54 *
F_35 ( struct V_2 * V_2 , int V_40 , T_4 V_59 ,
const union V_42 * V_65 , T_1 V_66 )
{
unsigned int V_56 ;
struct V_54 * V_55 ;
V_56 = F_22 ( V_2 , V_40 , V_59 , V_65 , V_66 ) ;
F_36 (svc, &ip_vs_svc_table[hash], s_list) {
if ( ( V_55 -> V_40 == V_40 )
&& F_37 ( V_40 , & V_55 -> V_4 , V_65 )
&& ( V_55 -> V_43 == V_66 )
&& ( V_55 -> V_59 == V_59 )
&& F_38 ( V_55 -> V_2 , V_2 ) ) {
return V_55 ;
}
}
return NULL ;
}
static inline struct V_54 *
F_39 ( struct V_2 * V_2 , int V_40 , T_3 V_53 )
{
unsigned int V_56 ;
struct V_54 * V_55 ;
V_56 = F_26 ( V_2 , V_53 ) ;
F_36 (svc, &ip_vs_svc_fwm_table[hash], f_list) {
if ( V_55 -> V_53 == V_53 && V_55 -> V_40 == V_40
&& F_38 ( V_55 -> V_2 , V_2 ) ) {
return V_55 ;
}
}
return NULL ;
}
struct V_54 *
F_40 ( struct V_2 * V_2 , int V_40 , T_3 V_53 , T_4 V_59 ,
const union V_42 * V_65 , T_1 V_66 )
{
struct V_54 * V_55 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
if ( V_53 ) {
V_55 = F_39 ( V_2 , V_40 , V_53 ) ;
if ( V_55 )
goto V_67;
}
V_55 = F_35 ( V_2 , V_40 , V_59 , V_65 , V_66 ) ;
if ( V_55 == NULL
&& V_59 == V_68
&& F_15 ( & V_15 -> V_69 )
&& ( V_66 == V_70 || F_23 ( V_66 ) >= V_71 ) ) {
V_55 = F_35 ( V_2 , V_40 , V_59 , V_65 , V_72 ) ;
}
if ( V_55 == NULL
&& F_15 ( & V_15 -> V_73 ) ) {
V_55 = F_35 ( V_2 , V_40 , V_59 , V_65 , 0 ) ;
}
V_67:
F_42 ( 9 , L_3 ,
V_53 , F_43 ( V_59 ) ,
F_44 ( V_40 , V_65 ) , F_23 ( V_66 ) ,
V_55 ? L_4 : L_5 ) ;
return V_55 ;
}
static inline void
F_45 ( struct V_74 * V_75 , struct V_54 * V_55 )
{
F_31 ( & V_55 -> V_64 ) ;
F_46 ( V_75 -> V_55 , V_55 ) ;
}
static void F_47 ( struct V_54 * V_55 )
{
if ( V_55 -> V_76 . V_77 )
F_48 ( V_55 -> V_76 . V_77 ) ;
F_49 ( V_55 ) ;
}
static void F_50 ( struct V_78 * V_79 )
{
struct V_54 * V_55 ;
V_55 = F_14 ( V_79 , struct V_54 , V_78 ) ;
F_47 ( V_55 ) ;
}
static void F_51 ( struct V_54 * V_55 , bool V_80 )
{
if ( F_52 ( & V_55 -> V_64 ) ) {
F_42 ( 3 , L_6 ,
V_55 -> V_53 ,
F_44 ( V_55 -> V_40 , & V_55 -> V_4 ) ,
F_23 ( V_55 -> V_43 ) ) ;
if ( V_80 )
F_53 ( & V_55 -> V_78 , F_50 ) ;
else
F_47 ( V_55 ) ;
}
}
static inline unsigned int F_54 ( int V_40 ,
const union V_42 * V_4 ,
T_1 V_43 )
{
register unsigned int V_44 = F_23 ( V_43 ) ;
T_2 V_45 = V_4 -> V_46 ;
#ifdef F_24
if ( V_40 == V_48 )
V_45 = V_4 -> V_49 [ 0 ] ^ V_4 -> V_49 [ 1 ] ^
V_4 -> V_49 [ 2 ] ^ V_4 -> V_49 [ 3 ] ;
#endif
return ( F_25 ( V_45 ) ^ ( V_44 >> V_81 ) ^ V_44 )
& V_82 ;
}
static void F_55 ( struct V_14 * V_15 , struct V_74 * V_75 )
{
unsigned int V_56 ;
if ( V_75 -> V_83 )
return;
V_56 = F_54 ( V_75 -> V_40 , & V_75 -> V_4 , V_75 -> V_43 ) ;
F_30 ( & V_75 -> V_84 , & V_15 -> V_85 [ V_56 ] ) ;
V_75 -> V_83 = 1 ;
}
static void F_56 ( struct V_74 * V_75 )
{
if ( V_75 -> V_83 ) {
F_33 ( & V_75 -> V_84 ) ;
V_75 -> V_83 = 0 ;
}
}
bool F_57 ( struct V_2 * V_2 , int V_40 , T_4 V_59 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
unsigned int V_56 ;
struct V_74 * V_75 ;
V_56 = F_54 ( V_40 , V_7 , V_86 ) ;
F_58 () ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( V_75 -> V_43 == V_86 &&
V_75 -> V_40 == V_40 &&
F_37 ( V_40 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_59 == V_59 || V_75 -> V_87 ) ) {
F_59 () ;
return true ;
}
}
F_59 () ;
return false ;
}
static struct V_74 *
F_60 ( struct V_54 * V_55 , int V_88 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_74 * V_75 ;
F_61 (dest, &svc->destinations, n_list) {
if ( ( V_75 -> V_40 == V_88 ) &&
F_37 ( V_88 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_43 == V_86 ) ) {
return V_75 ;
}
}
return NULL ;
}
struct V_74 * F_62 ( struct V_2 * V_2 , int V_89 , int V_88 ,
const union V_42 * V_7 ,
T_1 V_86 ,
const union V_42 * V_65 ,
T_1 V_66 , T_4 V_59 , T_3 V_53 ,
T_3 V_12 )
{
struct V_74 * V_75 ;
struct V_54 * V_55 ;
T_1 V_43 = V_86 ;
V_55 = F_40 ( V_2 , V_89 , V_53 , V_59 , V_65 , V_66 ) ;
if ( ! V_55 )
return NULL ;
if ( V_53 && ( V_12 & V_90 ) != V_91 )
V_43 = 0 ;
V_75 = F_60 ( V_55 , V_88 , V_7 , V_43 ) ;
if ( ! V_75 )
V_75 = F_60 ( V_55 , V_88 , V_7 , V_43 ^ V_86 ) ;
return V_75 ;
}
void F_63 ( struct V_78 * V_79 )
{
struct V_92 * V_93 = F_14 ( V_79 ,
struct V_92 ,
V_78 ) ;
F_4 ( V_93 -> V_94 ) ;
F_49 ( V_93 ) ;
}
static void F_64 ( struct V_74 * V_75 )
{
struct V_92 * V_95 ;
V_95 = F_65 ( V_75 -> V_93 , 1 ) ;
if ( V_95 ) {
F_66 ( V_75 -> V_93 , NULL ) ;
F_53 ( & V_95 -> V_78 , F_63 ) ;
}
}
static struct V_74 *
F_67 ( struct V_54 * V_55 , int V_88 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_74 * V_75 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_68 ( & V_15 -> V_96 ) ;
F_69 (dest, &ipvs->dest_trash, t_list) {
F_42 ( 3 , L_7
L_8 ,
V_75 -> V_87 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( V_75 -> V_40 == V_88 &&
F_37 ( V_88 , & V_75 -> V_4 , V_7 ) &&
V_75 -> V_43 == V_86 &&
V_75 -> V_87 == V_55 -> V_53 &&
V_75 -> V_59 == V_55 -> V_59 &&
( V_55 -> V_53 ||
( F_37 ( V_55 -> V_40 , & V_75 -> V_65 , & V_55 -> V_4 ) &&
V_75 -> V_66 == V_55 -> V_43 ) ) ) {
F_70 ( & V_75 -> V_97 ) ;
F_71 ( V_75 ) ;
goto V_67;
}
}
V_75 = NULL ;
V_67:
F_72 ( & V_15 -> V_96 ) ;
return V_75 ;
}
static void F_73 ( struct V_74 * V_75 )
{
struct V_54 * V_55 = F_65 ( V_75 -> V_55 , 1 ) ;
F_64 ( V_75 ) ;
F_51 ( V_55 , false ) ;
F_48 ( V_75 -> V_76 . V_77 ) ;
F_74 ( V_75 ) ;
}
static void F_75 ( struct V_2 * V_2 )
{
struct V_74 * V_75 , * V_98 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_76 ( & V_15 -> V_99 ) ;
F_77 (dest, nxt, &ipvs->dest_trash, t_list) {
F_70 ( & V_75 -> V_97 ) ;
F_73 ( V_75 ) ;
}
}
static void
F_78 ( struct V_100 * V_9 , struct V_101 * V_102 )
{
#define F_79 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_68 ( & V_102 -> V_103 ) ;
F_79 ( V_104 ) ;
F_79 ( V_105 ) ;
F_79 ( V_106 ) ;
F_79 ( V_107 ) ;
F_79 ( V_108 ) ;
F_80 ( V_9 , V_102 ) ;
F_72 ( & V_102 -> V_103 ) ;
}
static void
F_81 ( struct V_101 * V_76 )
{
F_68 ( & V_76 -> V_103 ) ;
#define F_82 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_82 ( V_104 ) ;
F_82 ( V_105 ) ;
F_82 ( V_106 ) ;
F_82 ( V_107 ) ;
F_82 ( V_108 ) ;
F_83 ( V_76 ) ;
F_72 ( & V_76 -> V_103 ) ;
}
static void
F_84 ( struct V_54 * V_55 , struct V_74 * V_75 ,
struct V_109 * V_110 , int V_111 )
{
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
struct V_54 * V_112 ;
struct V_113 * V_114 ;
int V_115 ;
F_85 ( ! V_111 && V_110 -> V_40 != V_75 -> V_40 ) ;
if ( V_111 && V_110 -> V_40 != V_55 -> V_40 )
V_15 -> V_116 ++ ;
F_9 ( & V_75 -> V_117 , V_110 -> V_117 ) ;
V_115 = V_110 -> V_115 & V_118 ;
V_115 |= V_119 ;
if ( ( V_115 & V_90 ) != V_91 ) {
V_115 |= V_120 ;
} else {
F_55 ( V_15 , V_75 ) ;
}
F_9 ( & V_75 -> V_115 , V_115 ) ;
V_112 = F_65 ( V_75 -> V_55 , 1 ) ;
if ( ! V_112 ) {
F_45 ( V_75 , V_55 ) ;
} else {
if ( V_112 != V_55 ) {
F_81 ( & V_75 -> V_76 ) ;
F_45 ( V_75 , V_55 ) ;
F_51 ( V_112 , true ) ;
}
}
V_75 -> V_12 |= V_121 ;
if ( V_110 -> V_122 == 0 || V_110 -> V_122 > V_75 -> V_122 )
V_75 -> V_12 &= ~ V_123 ;
V_75 -> V_122 = V_110 -> V_122 ;
V_75 -> V_124 = V_110 -> V_124 ;
V_75 -> V_40 = V_110 -> V_40 ;
F_68 ( & V_75 -> V_125 ) ;
F_64 ( V_75 ) ;
F_72 ( & V_75 -> V_125 ) ;
V_114 = F_65 ( V_55 -> V_126 , 1 ) ;
if ( V_111 ) {
F_86 ( V_55 -> V_2 , & V_75 -> V_76 ) ;
F_87 ( & V_75 -> V_127 , & V_55 -> V_128 ) ;
V_55 -> V_129 ++ ;
if ( V_114 -> V_130 )
V_114 -> V_130 ( V_55 , V_75 ) ;
} else {
if ( V_114 -> V_131 )
V_114 -> V_131 ( V_55 , V_75 ) ;
}
}
static int
F_88 ( struct V_54 * V_55 , struct V_109 * V_110 ,
struct V_74 * * V_132 )
{
struct V_74 * V_75 ;
unsigned int V_133 , V_17 ;
F_89 ( 2 ) ;
#ifdef F_24
if ( V_110 -> V_40 == V_48 ) {
V_133 = F_90 ( & V_110 -> V_4 . V_134 ) ;
if ( ( ! ( V_133 & V_135 ) ||
V_133 & V_136 ) &&
! F_2 ( V_55 -> V_2 , & V_110 -> V_4 . V_134 ) )
return - V_137 ;
} else
#endif
{
V_133 = F_91 ( V_55 -> V_2 , V_110 -> V_4 . V_46 ) ;
if ( V_133 != V_138 && V_133 != V_139 )
return - V_137 ;
}
V_75 = F_92 ( sizeof( struct V_74 ) , V_140 ) ;
if ( V_75 == NULL )
return - V_141 ;
V_75 -> V_76 . V_77 = F_93 ( struct V_142 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_143;
F_94 (i) {
struct V_142 * V_144 ;
V_144 = F_95 ( V_75 -> V_76 . V_77 , V_17 ) ;
F_96 ( & V_144 -> V_145 ) ;
}
V_75 -> V_40 = V_110 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_87 = V_55 -> V_53 ;
F_97 ( V_110 -> V_40 , & V_75 -> V_4 , & V_110 -> V_4 ) ;
V_75 -> V_43 = V_110 -> V_43 ;
F_9 ( & V_75 -> V_146 , 0 ) ;
F_9 ( & V_75 -> V_147 , 0 ) ;
F_9 ( & V_75 -> V_148 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_98 ( & V_75 -> V_84 ) ;
F_99 ( & V_75 -> V_125 ) ;
F_99 ( & V_75 -> V_76 . V_103 ) ;
F_84 ( V_55 , V_75 , V_110 , 1 ) ;
* V_132 = V_75 ;
F_100 ( 2 ) ;
return 0 ;
V_143:
F_49 ( V_75 ) ;
return - V_141 ;
}
static int
F_101 ( struct V_54 * V_55 , struct V_109 * V_110 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_110 -> V_43 ;
int V_149 ;
F_89 ( 2 ) ;
if ( V_110 -> V_117 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_150 ;
}
if ( V_110 -> V_124 > V_110 -> V_122 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_150 ;
}
F_97 ( V_110 -> V_40 , & V_7 , & V_110 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , V_110 -> V_40 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 != NULL ) {
F_102 ( 1 , L_11 , V_58 ) ;
return - V_151 ;
}
V_75 = F_67 ( V_55 , V_110 -> V_40 , & V_7 , V_86 ) ;
if ( V_75 != NULL ) {
F_42 ( 3 , L_12
L_13 ,
F_44 ( V_110 -> V_40 , & V_7 ) , F_23 ( V_86 ) ,
F_15 ( & V_75 -> V_64 ) ,
V_75 -> V_87 ,
F_44 ( V_55 -> V_40 , & V_75 -> V_65 ) ,
F_23 ( V_75 -> V_66 ) ) ;
F_84 ( V_55 , V_75 , V_110 , 1 ) ;
V_149 = 0 ;
} else {
V_149 = F_88 ( V_55 , V_110 , & V_75 ) ;
}
F_100 ( 2 ) ;
return V_149 ;
}
static int
F_103 ( struct V_54 * V_55 , struct V_109 * V_110 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_110 -> V_43 ;
F_89 ( 2 ) ;
if ( V_110 -> V_117 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_150 ;
}
if ( V_110 -> V_124 > V_110 -> V_122 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_150 ;
}
F_97 ( V_110 -> V_40 , & V_7 , & V_110 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , V_110 -> V_40 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_102 ( 1 , L_14 , V_58 ) ;
return - V_152 ;
}
F_84 ( V_55 , V_75 , V_110 , 0 ) ;
F_100 ( 2 ) ;
return 0 ;
}
static void F_104 ( struct V_2 * V_2 , struct V_74 * V_75 ,
bool V_153 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_105 ( V_2 , & V_75 -> V_76 ) ;
F_56 ( V_75 ) ;
F_68 ( & V_15 -> V_96 ) ;
F_42 ( 3 , L_15 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_106 ( & V_15 -> V_154 ) && ! V_153 )
F_107 ( & V_15 -> V_99 ,
V_155 + ( V_156 >> 1 ) ) ;
F_108 ( & V_75 -> V_97 , & V_15 -> V_154 ) ;
V_75 -> V_157 = 0 ;
F_72 ( & V_15 -> V_96 ) ;
F_109 ( V_75 ) ;
}
static void F_110 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_158 )
{
V_75 -> V_12 &= ~ V_121 ;
F_111 ( & V_75 -> V_127 ) ;
V_55 -> V_129 -- ;
if ( V_75 -> V_40 != V_55 -> V_40 )
F_41 ( V_55 -> V_2 ) -> V_116 -- ;
if ( V_158 ) {
struct V_113 * V_114 ;
V_114 = F_65 ( V_55 -> V_126 , 1 ) ;
if ( V_114 -> V_159 )
V_114 -> V_159 ( V_55 , V_75 ) ;
}
}
static int
F_112 ( struct V_54 * V_55 , struct V_109 * V_110 )
{
struct V_74 * V_75 ;
T_1 V_86 = V_110 -> V_43 ;
F_89 ( 2 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , V_110 -> V_40 , & V_110 -> V_4 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_102 ( 1 , L_16 , V_58 ) ;
return - V_152 ;
}
F_110 ( V_55 , V_75 , 1 ) ;
F_104 ( V_55 -> V_2 , V_75 , false ) ;
F_100 ( 2 ) ;
return 0 ;
}
static void F_113 ( unsigned long V_160 )
{
struct V_2 * V_2 = (struct V_2 * ) V_160 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_74 * V_75 , * V_161 ;
unsigned long V_162 = V_155 ;
F_8 ( & V_15 -> V_96 ) ;
F_77 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
if ( V_75 -> V_157 ) {
if ( F_114 ( V_162 , V_75 -> V_157 +
V_156 ) )
continue;
} else {
V_75 -> V_157 = F_115 ( 1UL , V_162 ) ;
continue;
}
F_42 ( 3 , L_17 ,
V_75 -> V_87 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_70 ( & V_75 -> V_97 ) ;
F_73 ( V_75 ) ;
}
if ( ! F_106 ( & V_15 -> V_154 ) )
F_107 ( & V_15 -> V_99 ,
V_155 + ( V_156 >> 1 ) ) ;
F_10 ( & V_15 -> V_96 ) ;
}
static int
F_116 ( struct V_2 * V_2 , struct V_163 * V_164 ,
struct V_54 * * V_165 )
{
int V_149 = 0 , V_17 ;
struct V_113 * V_114 = NULL ;
struct V_166 * V_167 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_18 () ;
V_114 = F_117 ( V_164 -> V_168 ) ;
if ( V_114 == NULL ) {
F_118 ( L_18 , V_164 -> V_168 ) ;
V_149 = - V_152 ;
goto V_169;
}
if ( V_164 -> V_170 && * V_164 -> V_170 ) {
V_167 = F_119 ( V_164 -> V_170 ) ;
if ( V_167 == NULL ) {
F_118 ( L_19
L_20 , V_164 -> V_170 ) ;
V_149 = - V_152 ;
goto V_169;
}
}
#ifdef F_24
if ( V_164 -> V_40 == V_48 ) {
T_3 V_171 = ( V_172 T_3 ) V_164 -> V_173 ;
if ( V_171 < 1 || V_171 > 128 ) {
V_149 = - V_137 ;
goto V_169;
}
}
#endif
V_55 = F_92 ( sizeof( struct V_54 ) , V_140 ) ;
if ( V_55 == NULL ) {
F_102 ( 1 , L_21 , V_58 ) ;
V_149 = - V_141 ;
goto V_169;
}
V_55 -> V_76 . V_77 = F_93 ( struct V_142 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_149 = - V_141 ;
goto V_169;
}
F_94 (i) {
struct V_142 * V_101 ;
V_101 = F_95 ( V_55 -> V_76 . V_77 , V_17 ) ;
F_96 ( & V_101 -> V_145 ) ;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_164 -> V_40 ;
V_55 -> V_59 = V_164 -> V_59 ;
F_97 ( V_55 -> V_40 , & V_55 -> V_4 , & V_164 -> V_4 ) ;
V_55 -> V_43 = V_164 -> V_43 ;
V_55 -> V_53 = V_164 -> V_53 ;
V_55 -> V_12 = V_164 -> V_12 ;
V_55 -> V_174 = V_164 -> V_174 * V_175 ;
V_55 -> V_173 = V_164 -> V_173 ;
V_55 -> V_2 = V_2 ;
F_120 ( & V_55 -> V_128 ) ;
F_99 ( & V_55 -> V_176 ) ;
F_99 ( & V_55 -> V_76 . V_103 ) ;
V_149 = F_121 ( V_55 , V_114 ) ;
if ( V_149 )
goto V_169;
V_114 = NULL ;
F_66 ( V_55 -> V_167 , V_167 ) ;
V_167 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_86 ( V_2 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_177 )
V_15 -> V_178 ++ ;
F_27 ( V_55 ) ;
* V_165 = V_55 ;
V_15 -> V_179 = 1 ;
return 0 ;
V_169:
if ( V_55 != NULL ) {
F_122 ( V_55 , V_114 ) ;
F_47 ( V_55 ) ;
}
F_123 ( V_114 ) ;
F_124 ( V_167 ) ;
F_20 () ;
return V_149 ;
}
static int
F_125 ( struct V_54 * V_55 , struct V_163 * V_164 )
{
struct V_113 * V_114 , * V_180 ;
struct V_166 * V_167 = NULL , * V_181 = NULL ;
int V_149 = 0 ;
V_114 = F_117 ( V_164 -> V_168 ) ;
if ( V_114 == NULL ) {
F_118 ( L_18 , V_164 -> V_168 ) ;
return - V_152 ;
}
V_180 = V_114 ;
if ( V_164 -> V_170 && * V_164 -> V_170 ) {
V_167 = F_119 ( V_164 -> V_170 ) ;
if ( V_167 == NULL ) {
F_118 ( L_19
L_20 , V_164 -> V_170 ) ;
V_149 = - V_152 ;
goto V_67;
}
V_181 = V_167 ;
}
#ifdef F_24
if ( V_164 -> V_40 == V_48 ) {
T_3 V_171 = ( V_172 T_3 ) V_164 -> V_173 ;
if ( V_171 < 1 || V_171 > 128 ) {
V_149 = - V_137 ;
goto V_67;
}
}
#endif
V_180 = F_65 ( V_55 -> V_126 , 1 ) ;
if ( V_114 != V_180 ) {
V_149 = F_121 ( V_55 , V_114 ) ;
if ( V_149 ) {
V_180 = V_114 ;
goto V_67;
}
F_122 ( V_55 , V_180 ) ;
}
V_55 -> V_12 = V_164 -> V_12 | V_57 ;
V_55 -> V_174 = V_164 -> V_174 * V_175 ;
V_55 -> V_173 = V_164 -> V_173 ;
V_181 = F_65 ( V_55 -> V_167 , 1 ) ;
if ( V_167 != V_181 )
F_46 ( V_55 -> V_167 , V_167 ) ;
V_67:
F_123 ( V_180 ) ;
F_124 ( V_181 ) ;
return V_149 ;
}
static void F_126 ( struct V_54 * V_55 , bool V_153 )
{
struct V_74 * V_75 , * V_98 ;
struct V_113 * V_180 ;
struct V_166 * V_181 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_118 ( L_22 , V_58 ) ;
if ( V_55 -> V_40 == V_177 )
V_15 -> V_178 -- ;
F_105 ( V_55 -> V_2 , & V_55 -> V_76 ) ;
V_180 = F_65 ( V_55 -> V_126 , 1 ) ;
F_122 ( V_55 , V_180 ) ;
F_123 ( V_180 ) ;
V_181 = F_65 ( V_55 -> V_167 , 1 ) ;
F_124 ( V_181 ) ;
F_77 (dest, nxt, &svc->destinations, n_list) {
F_110 ( V_55 , V_75 , 0 ) ;
F_104 ( V_55 -> V_2 , V_75 , V_153 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
F_51 ( V_55 , true ) ;
F_20 () ;
}
static void F_127 ( struct V_54 * V_55 , bool V_153 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_126 ( V_55 , V_153 ) ;
}
static int F_128 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_151 ;
F_127 ( V_55 , false ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_2 , bool V_153 )
{
int V_182 ;
struct V_54 * V_55 ;
struct V_183 * V_184 ;
for( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_130 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_127 ( V_55 , V_153 ) ;
}
}
for( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_130 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_127 ( V_55 , V_153 ) ;
}
}
return 0 ;
}
void F_131 ( struct V_2 * V_2 )
{
F_89 ( 2 ) ;
F_132 ( & V_186 ) ;
F_129 ( V_2 , true ) ;
F_133 ( & V_186 ) ;
F_100 ( 2 ) ;
}
static inline void
F_134 ( struct V_74 * V_75 , struct V_187 * V_11 )
{
struct V_92 * V_93 ;
F_68 ( & V_75 -> V_125 ) ;
V_93 = F_65 ( V_75 -> V_93 , 1 ) ;
if ( V_93 && V_93 -> V_94 -> V_11 == V_11 ) {
F_42 ( 3 , L_23 ,
V_11 -> V_188 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_64 ( V_75 ) ;
}
F_72 ( & V_75 -> V_125 ) ;
}
static int F_135 ( struct V_189 * V_190 , unsigned long V_191 ,
void * V_192 )
{
struct V_187 * V_11 = F_136 ( V_192 ) ;
struct V_2 * V_2 = F_137 ( V_11 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_182 ;
if ( V_191 != V_193 || ! V_15 )
return V_194 ;
F_102 ( 3 , L_24 , V_58 , V_11 -> V_188 ) ;
F_89 ( 2 ) ;
F_132 ( & V_186 ) ;
for ( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_138 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_134 ( V_75 , V_11 ) ;
}
}
}
F_138 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_134 ( V_75 , V_11 ) ;
}
}
}
}
F_68 ( & V_15 -> V_96 ) ;
F_69 (dest, &ipvs->dest_trash, t_list) {
F_134 ( V_75 , V_11 ) ;
}
F_72 ( & V_15 -> V_96 ) ;
F_133 ( & V_186 ) ;
F_100 ( 2 ) ;
return V_194 ;
}
static int F_139 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_69 (dest, &svc->destinations, n_list) {
F_81 ( & V_75 -> V_76 ) ;
}
F_81 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_2 )
{
int V_182 ;
struct V_54 * V_55 ;
for( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_138 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_139 ( V_55 ) ;
}
}
for( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_138 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_139 ( V_55 ) ;
}
}
F_81 ( & F_41 ( V_2 ) -> V_195 ) ;
return 0 ;
}
static int
F_141 ( struct V_196 * V_197 , int V_198 ,
void T_6 * V_199 , V_50 * V_200 , T_7 * V_201 )
{
struct V_2 * V_2 = V_202 -> V_203 -> V_204 ;
int * V_205 = V_197 -> V_160 ;
int V_206 = * V_205 ;
int V_207 ;
V_207 = F_142 ( V_197 , V_198 , V_199 , V_200 , V_201 ) ;
if ( V_198 && ( * V_205 != V_206 ) ) {
if ( ( * V_205 < 0 ) || ( * V_205 > 3 ) ) {
* V_205 = V_206 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_207 ;
}
static int
F_143 ( struct V_196 * V_197 , int V_198 ,
void T_6 * V_199 , V_50 * V_200 , T_7 * V_201 )
{
int * V_205 = V_197 -> V_160 ;
int V_206 [ 2 ] ;
int V_207 ;
memcpy ( V_206 , V_205 , sizeof( V_206 ) ) ;
V_207 = F_142 ( V_197 , V_198 , V_199 , V_200 , V_201 ) ;
if ( V_198 && ( V_205 [ 0 ] < 0 || V_205 [ 1 ] < 0 ||
( V_205 [ 0 ] >= V_205 [ 1 ] && V_205 [ 1 ] ) ) ) {
memcpy ( V_205 , V_206 , sizeof( V_206 ) ) ;
}
return V_207 ;
}
static int
F_144 ( struct V_196 * V_197 , int V_198 ,
void T_6 * V_199 , V_50 * V_200 , T_7 * V_201 )
{
int * V_205 = V_197 -> V_160 ;
int V_206 = * V_205 ;
int V_207 ;
V_207 = F_142 ( V_197 , V_198 , V_199 , V_200 , V_201 ) ;
if ( V_198 && ( * V_205 != V_206 ) ) {
if ( ( * V_205 < 0 ) || ( * V_205 > 1 ) ) {
* V_205 = V_206 ;
}
}
return V_207 ;
}
static int
F_145 ( struct V_196 * V_197 , int V_198 ,
void T_6 * V_199 , V_50 * V_200 , T_7 * V_201 )
{
int * V_205 = V_197 -> V_160 ;
int V_206 = * V_205 ;
int V_207 ;
V_207 = F_142 ( V_197 , V_198 , V_199 , V_200 , V_201 ) ;
if ( V_198 && ( * V_205 != V_206 ) ) {
if ( * V_205 < 1 || ! F_146 ( * V_205 ) ) {
* V_205 = V_206 ;
}
}
return V_207 ;
}
static inline const char * F_147 ( unsigned int V_12 )
{
switch ( V_12 & V_90 ) {
case V_208 :
return L_25 ;
case V_209 :
return L_26 ;
case V_210 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_148 ( struct V_211 * V_212 , T_7 V_213 )
{
struct V_2 * V_2 = F_149 ( V_212 ) ;
struct V_214 * V_215 = V_212 -> V_216 ;
int V_182 ;
struct V_54 * V_55 ;
for ( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_213 -- == 0 ) {
V_215 -> V_197 = V_61 ;
V_215 -> V_217 = V_182 ;
return V_55 ;
}
}
}
for ( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_213 -- == 0 ) {
V_215 -> V_197 = V_63 ;
V_215 -> V_217 = V_182 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_150 ( struct V_211 * V_212 , T_7 * V_213 )
__acquires( T_8 )
{
F_58 () ;
return * V_213 ? F_148 ( V_212 , * V_213 - 1 ) : V_218 ;
}
static void * F_151 ( struct V_211 * V_212 , void * V_219 , T_7 * V_213 )
{
struct V_183 * V_220 ;
struct V_214 * V_215 ;
struct V_54 * V_55 ;
++ * V_213 ;
if ( V_219 == V_218 )
return F_148 ( V_212 , 0 ) ;
V_55 = V_219 ;
V_215 = V_212 -> V_216 ;
if ( V_215 -> V_197 == V_61 ) {
V_220 = F_152 ( F_153 ( & V_55 -> V_60 ) ) ;
if ( V_220 )
return F_154 ( V_220 , struct V_54 , V_60 ) ;
while ( ++ V_215 -> V_217 < V_185 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_215 -> V_197 = V_63 ;
V_215 -> V_217 = - 1 ;
goto V_221;
}
V_220 = F_152 ( F_153 ( & V_55 -> V_62 ) ) ;
if ( V_220 )
return F_154 ( V_220 , struct V_54 , V_62 ) ;
V_221:
while ( ++ V_215 -> V_217 < V_185 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_155 ( struct V_211 * V_212 , void * V_219 )
__releases( T_8 )
{
F_59 () ;
}
static int F_156 ( struct V_211 * V_212 , void * V_219 )
{
if ( V_219 == V_218 ) {
F_157 ( V_212 ,
L_29 ,
F_158 ( V_222 ) , V_223 ) ;
F_159 ( V_212 ,
L_30 ) ;
F_159 ( V_212 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_219 ;
const struct V_214 * V_215 = V_212 -> V_216 ;
const struct V_74 * V_75 ;
struct V_113 * V_114 = F_152 ( V_55 -> V_126 ) ;
if ( V_215 -> V_197 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_157 ( V_212 , L_32 ,
F_43 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_134 ,
F_23 ( V_55 -> V_43 ) ,
V_114 -> V_188 ) ;
else
#endif
F_157 ( V_212 , L_33 ,
F_43 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_114 -> V_188 ,
( V_55 -> V_12 & V_224 ) ? L_34 : L_35 ) ;
} else {
F_157 ( V_212 , L_36 ,
V_55 -> V_53 , V_114 -> V_188 ,
( V_55 -> V_12 & V_224 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_225 )
F_157 ( V_212 , L_37 ,
V_55 -> V_174 ,
F_25 ( V_55 -> V_173 ) ) ;
else
F_160 ( V_212 , '\n' ) ;
F_61 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_157 ( V_212 ,
L_38
L_39 ,
& V_75 -> V_4 . V_134 ,
F_23 ( V_75 -> V_43 ) ,
F_147 ( F_15 ( & V_75 -> V_115 ) ) ,
F_15 ( & V_75 -> V_117 ) ,
F_15 ( & V_75 -> V_146 ) ,
F_15 ( & V_75 -> V_147 ) ) ;
else
#endif
F_157 ( V_212 ,
L_40
L_41 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_147 ( F_15 ( & V_75 -> V_115 ) ) ,
F_15 ( & V_75 -> V_117 ) ,
F_15 ( & V_75 -> V_146 ) ,
F_15 ( & V_75 -> V_147 ) ) ;
}
}
return 0 ;
}
static int F_161 ( struct V_226 * V_226 , struct V_227 * V_227 )
{
return F_162 ( V_226 , V_227 , & V_228 ,
sizeof( struct V_214 ) ) ;
}
static int F_163 ( struct V_211 * V_212 , void * V_219 )
{
struct V_2 * V_2 = F_164 ( V_212 ) ;
struct V_100 V_229 ;
F_159 ( V_212 ,
L_42 ) ;
F_157 ( V_212 ,
L_43 ) ;
F_78 ( & V_229 , & F_41 ( V_2 ) -> V_195 ) ;
F_157 ( V_212 , L_44 , V_229 . V_104 ,
V_229 . V_105 , V_229 . V_106 ,
( unsigned long long ) V_229 . V_107 ,
( unsigned long long ) V_229 . V_108 ) ;
F_159 ( V_212 ,
L_45 ) ;
F_157 ( V_212 , L_46 ,
V_229 . V_230 , V_229 . V_231 , V_229 . V_232 ,
V_229 . V_233 , V_229 . V_234 ) ;
return 0 ;
}
static int F_165 ( struct V_226 * V_226 , struct V_227 * V_227 )
{
return F_166 ( V_226 , V_227 , F_163 ) ;
}
static int F_167 ( struct V_211 * V_212 , void * V_219 )
{
struct V_2 * V_2 = F_164 ( V_212 ) ;
struct V_101 * V_195 = & F_41 ( V_2 ) -> V_195 ;
struct V_142 T_9 * V_77 = V_195 -> V_77 ;
struct V_100 V_235 ;
int V_17 ;
F_159 ( V_212 ,
L_47 ) ;
F_157 ( V_212 ,
L_48 ) ;
F_94 (i) {
struct V_142 * V_164 = F_95 ( V_77 , V_17 ) ;
unsigned int V_236 ;
T_10 V_107 , V_108 ;
do {
V_236 = F_168 ( & V_164 -> V_145 ) ;
V_107 = V_164 -> V_237 . V_107 ;
V_108 = V_164 -> V_237 . V_108 ;
} while ( F_169 ( & V_164 -> V_145 , V_236 ) );
F_157 ( V_212 , L_49 ,
V_17 , V_164 -> V_237 . V_104 , V_164 -> V_237 . V_105 ,
V_164 -> V_237 . V_106 , ( T_10 ) V_107 ,
( T_10 ) V_108 ) ;
}
F_68 ( & V_195 -> V_103 ) ;
F_157 ( V_212 , L_50 ,
V_195 -> V_237 . V_104 , V_195 -> V_237 . V_105 ,
V_195 -> V_237 . V_106 ,
( unsigned long long ) V_195 -> V_237 . V_107 ,
( unsigned long long ) V_195 -> V_237 . V_108 ) ;
F_80 ( & V_235 , V_195 ) ;
F_72 ( & V_195 -> V_103 ) ;
F_159 ( V_212 ,
L_51 ) ;
F_157 ( V_212 , L_52 ,
V_235 . V_230 ,
V_235 . V_231 ,
V_235 . V_232 ,
V_235 . V_233 ,
V_235 . V_234 ) ;
return 0 ;
}
static int F_170 ( struct V_226 * V_226 , struct V_227 * V_227 )
{
return F_166 ( V_226 , V_227 , F_167 ) ;
}
static int F_171 ( struct V_2 * V_2 , struct V_238 * V_164 )
{
#if F_172 ( V_239 ) || F_172 ( V_240 )
struct V_241 * V_242 ;
#endif
F_102 ( 2 , L_53 ,
V_164 -> V_243 ,
V_164 -> V_244 ,
V_164 -> V_245 ) ;
#ifdef V_239
if ( V_164 -> V_243 ) {
V_242 = F_173 ( V_2 , V_68 ) ;
V_242 -> V_246 [ V_247 ]
= V_164 -> V_243 * V_175 ;
}
if ( V_164 -> V_244 ) {
V_242 = F_173 ( V_2 , V_68 ) ;
V_242 -> V_246 [ V_248 ]
= V_164 -> V_244 * V_175 ;
}
#endif
#ifdef V_240
if ( V_164 -> V_245 ) {
V_242 = F_173 ( V_2 , V_249 ) ;
V_242 -> V_246 [ V_250 ]
= V_164 -> V_245 * V_175 ;
}
#endif
return 0 ;
}
static void F_174 ( struct V_163 * V_251 ,
struct V_252 * V_253 )
{
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_40 = V_177 ;
V_251 -> V_59 = V_253 -> V_59 ;
V_251 -> V_4 . V_46 = V_253 -> V_4 ;
V_251 -> V_43 = V_253 -> V_43 ;
V_251 -> V_53 = V_253 -> V_53 ;
V_251 -> V_168 = V_253 -> V_168 ;
V_251 -> V_12 = V_253 -> V_12 ;
V_251 -> V_174 = V_253 -> V_174 ;
V_251 -> V_173 = V_253 -> V_173 ;
}
static void F_175 ( struct V_109 * V_110 ,
struct V_254 * V_255 )
{
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_4 . V_46 = V_255 -> V_4 ;
V_110 -> V_43 = V_255 -> V_43 ;
V_110 -> V_115 = V_255 -> V_115 ;
V_110 -> V_117 = V_255 -> V_117 ;
V_110 -> V_122 = V_255 -> V_122 ;
V_110 -> V_124 = V_255 -> V_124 ;
V_110 -> V_40 = V_177 ;
}
static int
F_176 ( struct V_256 * V_257 , int V_258 , void T_6 * V_259 , unsigned int V_260 )
{
struct V_2 * V_2 = F_177 ( V_257 ) ;
int V_149 ;
unsigned char V_261 [ V_262 ] ;
struct V_252 * V_253 ;
struct V_163 V_251 ;
struct V_54 * V_55 ;
struct V_254 * V_255 ;
struct V_109 V_110 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_178 ( sizeof( V_261 ) > 255 ) ;
if ( ! F_179 ( F_177 ( V_257 ) -> V_263 , V_264 ) )
return - V_265 ;
if ( V_258 < V_266 || V_258 > V_267 )
return - V_137 ;
if ( V_260 != V_268 [ F_180 ( V_258 ) ] ) {
F_102 ( 1 , L_54 ,
V_260 , V_268 [ F_180 ( V_258 ) ] ) ;
return - V_137 ;
}
if ( F_181 ( V_261 , V_259 , V_260 ) != 0 )
return - V_269 ;
F_18 () ;
if ( V_258 == V_270 ||
V_258 == V_271 ) {
struct V_272 * V_273 = (struct V_272 * ) V_261 ;
F_132 ( & V_15 -> V_274 ) ;
if ( V_258 == V_270 )
V_149 = F_182 ( V_2 , V_273 -> V_275 , V_273 -> V_276 ,
V_273 -> V_277 ) ;
else
V_149 = F_183 ( V_2 , V_273 -> V_275 ) ;
F_133 ( & V_15 -> V_274 ) ;
goto V_278;
}
F_132 ( & V_186 ) ;
if ( V_258 == V_279 ) {
V_149 = F_129 ( V_2 , false ) ;
goto V_280;
} else if ( V_258 == V_281 ) {
V_149 = F_171 ( V_2 , (struct V_238 * ) V_261 ) ;
goto V_280;
}
V_253 = (struct V_252 * ) V_261 ;
V_255 = (struct V_254 * ) ( V_253 + 1 ) ;
F_174 ( & V_251 , V_253 ) ;
F_175 ( & V_110 , V_255 ) ;
if ( V_258 == V_282 ) {
if ( ! V_251 . V_53 && ! V_251 . V_4 . V_46 && ! V_251 . V_43 ) {
V_149 = F_140 ( V_2 ) ;
goto V_280;
}
}
if ( V_251 . V_59 != V_68 && V_251 . V_59 != V_249 &&
V_251 . V_59 != V_283 ) {
F_28 ( L_55 ,
V_251 . V_59 , & V_251 . V_4 . V_46 ,
F_23 ( V_251 . V_43 ) , V_251 . V_168 ) ;
V_149 = - V_269 ;
goto V_280;
}
F_58 () ;
if ( V_251 . V_53 == 0 )
V_55 = F_35 ( V_2 , V_251 . V_40 , V_251 . V_59 ,
& V_251 . V_4 , V_251 . V_43 ) ;
else
V_55 = F_39 ( V_2 , V_251 . V_40 , V_251 . V_53 ) ;
F_59 () ;
if ( V_258 != V_284
&& ( V_55 == NULL || V_55 -> V_59 != V_251 . V_59 ) ) {
V_149 = - V_285 ;
goto V_280;
}
switch ( V_258 ) {
case V_284 :
if ( V_55 != NULL )
V_149 = - V_151 ;
else
V_149 = F_116 ( V_2 , & V_251 , & V_55 ) ;
break;
case V_286 :
V_149 = F_125 ( V_55 , & V_251 ) ;
break;
case V_287 :
V_149 = F_128 ( V_55 ) ;
if ( ! V_149 )
goto V_280;
break;
case V_282 :
V_149 = F_139 ( V_55 ) ;
break;
case V_288 :
V_149 = F_101 ( V_55 , & V_110 ) ;
break;
case V_289 :
V_149 = F_103 ( V_55 , & V_110 ) ;
break;
case V_290 :
V_149 = F_112 ( V_55 , & V_110 ) ;
break;
default:
V_149 = - V_137 ;
}
V_280:
F_133 ( & V_186 ) ;
V_278:
F_20 () ;
return V_149 ;
}
static void
F_184 ( struct V_291 * V_9 , struct V_54 * V_102 )
{
struct V_113 * V_114 ;
V_114 = F_65 ( V_102 -> V_126 , 1 ) ;
V_9 -> V_59 = V_102 -> V_59 ;
V_9 -> V_4 = V_102 -> V_4 . V_46 ;
V_9 -> V_43 = V_102 -> V_43 ;
V_9 -> V_53 = V_102 -> V_53 ;
F_185 ( V_9 -> V_168 , V_114 -> V_188 , sizeof( V_9 -> V_168 ) ) ;
V_9 -> V_12 = V_102 -> V_12 ;
V_9 -> V_174 = V_102 -> V_174 / V_175 ;
V_9 -> V_173 = V_102 -> V_173 ;
V_9 -> V_129 = V_102 -> V_129 ;
F_78 ( & V_9 -> V_76 , & V_102 -> V_76 ) ;
}
static inline int
F_186 ( struct V_2 * V_2 ,
const struct V_292 * V_293 ,
struct V_292 T_6 * V_294 )
{
int V_182 , V_295 = 0 ;
struct V_54 * V_55 ;
struct V_291 V_296 ;
int V_149 = 0 ;
for ( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_138 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_177 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_295 >= V_293 -> V_178 )
goto V_67;
memset ( & V_296 , 0 , sizeof( V_296 ) ) ;
F_184 ( & V_296 , V_55 ) ;
if ( F_187 ( & V_294 -> V_297 [ V_295 ] ,
& V_296 , sizeof( V_296 ) ) ) {
V_149 = - V_269 ;
goto V_67;
}
V_295 ++ ;
}
}
for ( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_138 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_177 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_295 >= V_293 -> V_178 )
goto V_67;
memset ( & V_296 , 0 , sizeof( V_296 ) ) ;
F_184 ( & V_296 , V_55 ) ;
if ( F_187 ( & V_294 -> V_297 [ V_295 ] ,
& V_296 , sizeof( V_296 ) ) ) {
V_149 = - V_269 ;
goto V_67;
}
V_295 ++ ;
}
}
V_67:
return V_149 ;
}
static inline int
F_188 ( struct V_2 * V_2 , const struct V_298 * V_293 ,
struct V_298 T_6 * V_294 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_293 -> V_4 } ;
int V_149 = 0 ;
F_58 () ;
if ( V_293 -> V_53 )
V_55 = F_39 ( V_2 , V_177 , V_293 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_177 , V_293 -> V_59 , & V_4 ,
V_293 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
int V_295 = 0 ;
struct V_74 * V_75 ;
struct V_299 V_296 ;
memset ( & V_296 , 0 , sizeof( V_296 ) ) ;
F_69 (dest, &svc->destinations, n_list) {
if ( V_295 >= V_293 -> V_129 )
break;
if ( V_75 -> V_40 != V_55 -> V_40 )
continue;
V_296 . V_4 = V_75 -> V_4 . V_46 ;
V_296 . V_43 = V_75 -> V_43 ;
V_296 . V_115 = F_15 ( & V_75 -> V_115 ) ;
V_296 . V_117 = F_15 ( & V_75 -> V_117 ) ;
V_296 . V_122 = V_75 -> V_122 ;
V_296 . V_124 = V_75 -> V_124 ;
V_296 . V_146 = F_15 ( & V_75 -> V_146 ) ;
V_296 . V_147 = F_15 ( & V_75 -> V_147 ) ;
V_296 . V_148 = F_15 ( & V_75 -> V_148 ) ;
F_78 ( & V_296 . V_76 , & V_75 -> V_76 ) ;
if ( F_187 ( & V_294 -> V_297 [ V_295 ] ,
& V_296 , sizeof( V_296 ) ) ) {
V_149 = - V_269 ;
break;
}
V_295 ++ ;
}
} else
V_149 = - V_285 ;
return V_149 ;
}
static inline void
F_189 ( struct V_2 * V_2 , struct V_238 * V_164 )
{
#if F_172 ( V_239 ) || F_172 ( V_240 )
struct V_241 * V_242 ;
#endif
memset ( V_164 , 0 , sizeof ( * V_164 ) ) ;
#ifdef V_239
V_242 = F_173 ( V_2 , V_68 ) ;
V_164 -> V_243 = V_242 -> V_246 [ V_247 ] / V_175 ;
V_164 -> V_244 = V_242 -> V_246 [ V_248 ] / V_175 ;
#endif
#ifdef V_240
V_242 = F_173 ( V_2 , V_249 ) ;
V_164 -> V_245 =
V_242 -> V_246 [ V_250 ] / V_175 ;
#endif
}
static int
F_190 ( struct V_256 * V_257 , int V_258 , void T_6 * V_259 , int * V_260 )
{
unsigned char V_261 [ V_300 ] ;
int V_149 = 0 ;
unsigned int V_301 ;
struct V_2 * V_2 = F_177 ( V_257 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_85 ( ! V_2 ) ;
F_178 ( sizeof( V_261 ) > 255 ) ;
if ( ! F_179 ( F_177 ( V_257 ) -> V_263 , V_264 ) )
return - V_265 ;
if ( V_258 < V_266 || V_258 > V_302 )
return - V_137 ;
V_301 = V_303 [ F_180 ( V_258 ) ] ;
if ( * V_260 < ( int ) V_301 ) {
F_102 ( 1 , L_56 , * V_260 , V_301 ) ;
return - V_137 ;
}
if ( F_181 ( V_261 , V_259 , V_301 ) != 0 )
return - V_269 ;
if ( V_258 == V_304 ) {
struct V_272 V_305 [ 2 ] ;
memset ( & V_305 , 0 , sizeof( V_305 ) ) ;
F_132 ( & V_15 -> V_274 ) ;
if ( V_15 -> V_306 & V_307 ) {
V_305 [ 0 ] . V_275 = V_307 ;
F_185 ( V_305 [ 0 ] . V_276 , V_15 -> V_308 ,
sizeof( V_305 [ 0 ] . V_276 ) ) ;
V_305 [ 0 ] . V_277 = V_15 -> V_309 ;
}
if ( V_15 -> V_306 & V_310 ) {
V_305 [ 1 ] . V_275 = V_310 ;
F_185 ( V_305 [ 1 ] . V_276 , V_15 -> V_311 ,
sizeof( V_305 [ 1 ] . V_276 ) ) ;
V_305 [ 1 ] . V_277 = V_15 -> V_312 ;
}
if ( F_187 ( V_259 , & V_305 , sizeof( V_305 ) ) != 0 )
V_149 = - V_269 ;
F_133 ( & V_15 -> V_274 ) ;
return V_149 ;
}
F_132 ( & V_186 ) ;
switch ( V_258 ) {
case V_313 :
{
char V_314 [ 64 ] ;
sprintf ( V_314 , L_57 ,
F_158 ( V_222 ) , V_223 ) ;
if ( F_187 ( V_259 , V_314 , strlen ( V_314 ) + 1 ) != 0 ) {
V_149 = - V_269 ;
goto V_67;
}
* V_260 = strlen ( V_314 ) + 1 ;
}
break;
case V_315 :
{
struct V_316 V_317 ;
V_317 . V_318 = V_222 ;
V_317 . V_319 = V_223 ;
V_317 . V_178 = V_15 -> V_178 ;
if ( F_187 ( V_259 , & V_317 , sizeof( V_317 ) ) != 0 )
V_149 = - V_269 ;
}
break;
case V_320 :
{
struct V_292 * V_293 ;
int V_319 ;
V_293 = (struct V_292 * ) V_261 ;
V_319 = sizeof( * V_293 ) +
sizeof( struct V_291 ) * V_293 -> V_178 ;
if ( * V_260 != V_319 ) {
F_28 ( L_58 , * V_260 , V_319 ) ;
V_149 = - V_137 ;
goto V_67;
}
V_149 = F_186 ( V_2 , V_293 , V_259 ) ;
}
break;
case V_321 :
{
struct V_291 * V_296 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_296 = (struct V_291 * ) V_261 ;
V_4 . V_46 = V_296 -> V_4 ;
F_58 () ;
if ( V_296 -> V_53 )
V_55 = F_39 ( V_2 , V_177 , V_296 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_177 ,
V_296 -> V_59 , & V_4 ,
V_296 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
F_184 ( V_296 , V_55 ) ;
if ( F_187 ( V_259 , V_296 , sizeof( * V_296 ) ) != 0 )
V_149 = - V_269 ;
} else
V_149 = - V_285 ;
}
break;
case V_322 :
{
struct V_298 * V_293 ;
int V_319 ;
V_293 = (struct V_298 * ) V_261 ;
V_319 = sizeof( * V_293 ) +
sizeof( struct V_299 ) * V_293 -> V_129 ;
if ( * V_260 != V_319 ) {
F_28 ( L_58 , * V_260 , V_319 ) ;
V_149 = - V_137 ;
goto V_67;
}
V_149 = F_188 ( V_2 , V_293 , V_259 ) ;
}
break;
case V_323 :
{
struct V_238 V_324 ;
F_189 ( V_2 , & V_324 ) ;
if ( F_187 ( V_259 , & V_324 , sizeof( V_324 ) ) != 0 )
V_149 = - V_269 ;
}
break;
default:
V_149 = - V_137 ;
}
V_67:
F_133 ( & V_186 ) ;
return V_149 ;
}
static int F_191 ( struct V_325 * V_326 , int V_327 ,
struct V_101 * V_76 )
{
struct V_100 V_237 ;
struct V_328 * V_329 = F_192 ( V_326 , V_327 ) ;
if ( ! V_329 )
return - V_330 ;
F_78 ( & V_237 , V_76 ) ;
if ( F_193 ( V_326 , V_331 , V_237 . V_104 ) ||
F_193 ( V_326 , V_332 , V_237 . V_105 ) ||
F_193 ( V_326 , V_333 , V_237 . V_106 ) ||
F_194 ( V_326 , V_334 , V_237 . V_107 ) ||
F_194 ( V_326 , V_335 , V_237 . V_108 ) ||
F_193 ( V_326 , V_336 , V_237 . V_230 ) ||
F_193 ( V_326 , V_337 , V_237 . V_231 ) ||
F_193 ( V_326 , V_338 , V_237 . V_232 ) ||
F_193 ( V_326 , V_339 , V_237 . V_233 ) ||
F_193 ( V_326 , V_340 , V_237 . V_234 ) )
goto V_341;
F_195 ( V_326 , V_329 ) ;
return 0 ;
V_341:
F_196 ( V_326 , V_329 ) ;
return - V_330 ;
}
static int F_197 ( struct V_325 * V_326 ,
struct V_54 * V_55 )
{
struct V_113 * V_114 ;
struct V_166 * V_167 ;
struct V_328 * V_342 ;
struct V_343 V_12 = { . V_12 = V_55 -> V_12 ,
. V_344 = ~ 0 } ;
V_342 = F_192 ( V_326 , V_345 ) ;
if ( ! V_342 )
return - V_330 ;
if ( F_198 ( V_326 , V_346 , V_55 -> V_40 ) )
goto V_341;
if ( V_55 -> V_53 ) {
if ( F_193 ( V_326 , V_347 , V_55 -> V_53 ) )
goto V_341;
} else {
if ( F_198 ( V_326 , V_348 , V_55 -> V_59 ) ||
F_199 ( V_326 , V_349 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_200 ( V_326 , V_350 , V_55 -> V_43 ) )
goto V_341;
}
V_114 = F_65 ( V_55 -> V_126 , 1 ) ;
V_167 = F_65 ( V_55 -> V_167 , 1 ) ;
if ( F_201 ( V_326 , V_351 , V_114 -> V_188 ) ||
( V_167 && F_201 ( V_326 , V_352 , V_167 -> V_188 ) ) ||
F_199 ( V_326 , V_353 , sizeof( V_12 ) , & V_12 ) ||
F_193 ( V_326 , V_354 , V_55 -> V_174 / V_175 ) ||
F_202 ( V_326 , V_355 , V_55 -> V_173 ) )
goto V_341;
if ( F_191 ( V_326 , V_356 , & V_55 -> V_76 ) )
goto V_341;
F_195 ( V_326 , V_342 ) ;
return 0 ;
V_341:
F_196 ( V_326 , V_342 ) ;
return - V_330 ;
}
static int F_203 ( struct V_325 * V_326 ,
struct V_54 * V_55 ,
struct V_357 * V_358 )
{
void * V_359 ;
V_359 = F_204 ( V_326 , F_205 ( V_358 -> V_326 ) . V_360 , V_358 -> V_361 -> V_362 ,
& V_363 , V_364 ,
V_365 ) ;
if ( ! V_359 )
return - V_330 ;
if ( F_197 ( V_326 , V_55 ) < 0 )
goto V_341;
return F_206 ( V_326 , V_359 ) ;
V_341:
F_207 ( V_326 , V_359 ) ;
return - V_330 ;
}
static int F_208 ( struct V_325 * V_326 ,
struct V_357 * V_358 )
{
int V_182 = 0 , V_17 ;
int V_236 = V_358 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_209 ( V_326 ) ;
F_132 ( & V_186 ) ;
for ( V_17 = 0 ; V_17 < V_185 ; V_17 ++ ) {
F_138 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_182 <= V_236 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_203 ( V_326 , V_55 , V_358 ) < 0 ) {
V_182 -- ;
goto V_341;
}
}
}
for ( V_17 = 0 ; V_17 < V_185 ; V_17 ++ ) {
F_138 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_182 <= V_236 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_203 ( V_326 , V_55 , V_358 ) < 0 ) {
V_182 -- ;
goto V_341;
}
}
}
V_341:
F_133 ( & V_186 ) ;
V_358 -> args [ 0 ] = V_182 ;
return V_326 -> V_260 ;
}
static int F_210 ( struct V_2 * V_2 ,
struct V_163 * V_251 ,
struct V_328 * V_366 , int V_367 ,
struct V_54 * * V_368 )
{
struct V_328 * V_369 [ V_370 + 1 ] ;
struct V_328 * V_371 , * V_372 , * V_373 , * V_374 , * V_375 ;
struct V_54 * V_55 ;
if ( V_366 == NULL ||
F_211 ( V_369 , V_370 , V_366 , V_376 ) )
return - V_137 ;
V_371 = V_369 [ V_346 ] ;
V_374 = V_369 [ V_348 ] ;
V_375 = V_369 [ V_349 ] ;
V_372 = V_369 [ V_350 ] ;
V_373 = V_369 [ V_347 ] ;
if ( ! ( V_371 && ( V_373 || ( V_372 && V_374 && V_375 ) ) ) )
return - V_137 ;
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_40 = F_212 ( V_371 ) ;
#ifdef F_24
if ( V_251 -> V_40 != V_177 && V_251 -> V_40 != V_48 )
#else
if ( V_251 -> V_40 != V_177 )
#endif
return - V_377 ;
if ( V_373 ) {
V_251 -> V_59 = V_68 ;
V_251 -> V_53 = F_213 ( V_373 ) ;
} else {
V_251 -> V_59 = F_212 ( V_374 ) ;
F_214 ( & V_251 -> V_4 , V_375 , sizeof( V_251 -> V_4 ) ) ;
V_251 -> V_43 = F_215 ( V_372 ) ;
V_251 -> V_53 = 0 ;
}
F_58 () ;
if ( V_251 -> V_53 )
V_55 = F_39 ( V_2 , V_251 -> V_40 , V_251 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_251 -> V_40 , V_251 -> V_59 ,
& V_251 -> V_4 , V_251 -> V_43 ) ;
F_59 () ;
* V_368 = V_55 ;
if ( V_367 ) {
struct V_328 * V_378 , * V_379 , * V_380 , * V_381 ,
* V_382 ;
struct V_343 V_12 ;
V_378 = V_369 [ V_351 ] ;
V_380 = V_369 [ V_352 ] ;
V_379 = V_369 [ V_353 ] ;
V_381 = V_369 [ V_354 ] ;
V_382 = V_369 [ V_355 ] ;
if ( ! ( V_378 && V_379 && V_381 && V_382 ) )
return - V_137 ;
F_214 ( & V_12 , V_379 , sizeof( V_12 ) ) ;
if ( V_55 )
V_251 -> V_12 = V_55 -> V_12 ;
V_251 -> V_12 = ( V_251 -> V_12 & ~ V_12 . V_344 ) |
( V_12 . V_12 & V_12 . V_344 ) ;
V_251 -> V_168 = F_216 ( V_378 ) ;
V_251 -> V_170 = V_380 ? F_216 ( V_380 ) : NULL ;
V_251 -> V_174 = F_213 ( V_381 ) ;
V_251 -> V_173 = F_217 ( V_382 ) ;
}
return 0 ;
}
static struct V_54 * F_218 ( struct V_2 * V_2 ,
struct V_328 * V_366 )
{
struct V_163 V_251 ;
struct V_54 * V_55 ;
int V_149 ;
V_149 = F_210 ( V_2 , & V_251 , V_366 , 0 , & V_55 ) ;
return V_149 ? F_219 ( V_149 ) : V_55 ;
}
static int F_220 ( struct V_325 * V_326 , struct V_74 * V_75 )
{
struct V_328 * V_383 ;
V_383 = F_192 ( V_326 , V_384 ) ;
if ( ! V_383 )
return - V_330 ;
if ( F_199 ( V_326 , V_385 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_200 ( V_326 , V_386 , V_75 -> V_43 ) ||
F_193 ( V_326 , V_387 ,
( F_15 ( & V_75 -> V_115 ) &
V_90 ) ) ||
F_193 ( V_326 , V_388 ,
F_15 ( & V_75 -> V_117 ) ) ||
F_193 ( V_326 , V_389 , V_75 -> V_122 ) ||
F_193 ( V_326 , V_390 , V_75 -> V_124 ) ||
F_193 ( V_326 , V_391 ,
F_15 ( & V_75 -> V_146 ) ) ||
F_193 ( V_326 , V_392 ,
F_15 ( & V_75 -> V_147 ) ) ||
F_193 ( V_326 , V_393 ,
F_15 ( & V_75 -> V_148 ) ) ||
F_198 ( V_326 , V_394 , V_75 -> V_40 ) )
goto V_341;
if ( F_191 ( V_326 , V_395 , & V_75 -> V_76 ) )
goto V_341;
F_195 ( V_326 , V_383 ) ;
return 0 ;
V_341:
F_196 ( V_326 , V_383 ) ;
return - V_330 ;
}
static int F_221 ( struct V_325 * V_326 , struct V_74 * V_75 ,
struct V_357 * V_358 )
{
void * V_359 ;
V_359 = F_204 ( V_326 , F_205 ( V_358 -> V_326 ) . V_360 , V_358 -> V_361 -> V_362 ,
& V_363 , V_364 ,
V_396 ) ;
if ( ! V_359 )
return - V_330 ;
if ( F_220 ( V_326 , V_75 ) < 0 )
goto V_341;
return F_206 ( V_326 , V_359 ) ;
V_341:
F_207 ( V_326 , V_359 ) ;
return - V_330 ;
}
static int F_222 ( struct V_325 * V_326 ,
struct V_357 * V_358 )
{
int V_182 = 0 ;
int V_236 = V_358 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_328 * V_369 [ V_397 + 1 ] ;
struct V_2 * V_2 = F_209 ( V_326 ) ;
F_132 ( & V_186 ) ;
if ( F_223 ( V_358 -> V_361 , V_398 , V_369 ,
V_397 , V_399 ) )
goto V_169;
V_55 = F_218 ( V_2 , V_369 [ V_345 ] ) ;
if ( F_224 ( V_55 ) || V_55 == NULL )
goto V_169;
F_69 (dest, &svc->destinations, n_list) {
if ( ++ V_182 <= V_236 )
continue;
if ( F_221 ( V_326 , V_75 , V_358 ) < 0 ) {
V_182 -- ;
goto V_341;
}
}
V_341:
V_358 -> args [ 0 ] = V_182 ;
V_169:
F_133 ( & V_186 ) ;
return V_326 -> V_260 ;
}
static int F_225 ( struct V_109 * V_110 ,
struct V_328 * V_366 , int V_367 )
{
struct V_328 * V_369 [ V_400 + 1 ] ;
struct V_328 * V_375 , * V_372 ;
struct V_328 * V_401 ;
if ( V_366 == NULL ||
F_211 ( V_369 , V_400 , V_366 , V_402 ) )
return - V_137 ;
V_375 = V_369 [ V_385 ] ;
V_372 = V_369 [ V_386 ] ;
V_401 = V_369 [ V_394 ] ;
if ( ! ( V_375 && V_372 ) )
return - V_137 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_214 ( & V_110 -> V_4 , V_375 , sizeof( V_110 -> V_4 ) ) ;
V_110 -> V_43 = F_215 ( V_372 ) ;
if ( V_401 )
V_110 -> V_40 = F_212 ( V_401 ) ;
else
V_110 -> V_40 = 0 ;
if ( V_367 ) {
struct V_328 * V_403 , * V_404 , * V_405 ,
* V_406 ;
V_403 = V_369 [ V_387 ] ;
V_404 = V_369 [ V_388 ] ;
V_405 = V_369 [ V_389 ] ;
V_406 = V_369 [ V_390 ] ;
if ( ! ( V_403 && V_404 && V_405 && V_406 ) )
return - V_137 ;
V_110 -> V_115 = F_213 ( V_403 )
& V_90 ;
V_110 -> V_117 = F_213 ( V_404 ) ;
V_110 -> V_122 = F_213 ( V_405 ) ;
V_110 -> V_124 = F_213 ( V_406 ) ;
}
return 0 ;
}
static int F_226 ( struct V_325 * V_326 , T_3 V_275 ,
const char * V_276 , T_3 V_277 )
{
struct V_328 * V_407 ;
V_407 = F_192 ( V_326 , V_408 ) ;
if ( ! V_407 )
return - V_330 ;
if ( F_193 ( V_326 , V_409 , V_275 ) ||
F_201 ( V_326 , V_410 , V_276 ) ||
F_193 ( V_326 , V_411 , V_277 ) )
goto V_341;
F_195 ( V_326 , V_407 ) ;
return 0 ;
V_341:
F_196 ( V_326 , V_407 ) ;
return - V_330 ;
}
static int F_227 ( struct V_325 * V_326 , T_3 V_275 ,
const char * V_276 , T_3 V_277 ,
struct V_357 * V_358 )
{
void * V_359 ;
V_359 = F_204 ( V_326 , F_205 ( V_358 -> V_326 ) . V_360 , V_358 -> V_361 -> V_362 ,
& V_363 , V_364 ,
V_412 ) ;
if ( ! V_359 )
return - V_330 ;
if ( F_226 ( V_326 , V_275 , V_276 , V_277 ) )
goto V_341;
return F_206 ( V_326 , V_359 ) ;
V_341:
F_207 ( V_326 , V_359 ) ;
return - V_330 ;
}
static int F_228 ( struct V_325 * V_326 ,
struct V_357 * V_358 )
{
struct V_2 * V_2 = F_209 ( V_326 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_132 ( & V_15 -> V_274 ) ;
if ( ( V_15 -> V_306 & V_307 ) && ! V_358 -> args [ 0 ] ) {
if ( F_227 ( V_326 , V_307 ,
V_15 -> V_308 ,
V_15 -> V_309 , V_358 ) < 0 )
goto V_341;
V_358 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_306 & V_310 ) && ! V_358 -> args [ 1 ] ) {
if ( F_227 ( V_326 , V_310 ,
V_15 -> V_311 ,
V_15 -> V_312 , V_358 ) < 0 )
goto V_341;
V_358 -> args [ 1 ] = 1 ;
}
V_341:
F_133 ( & V_15 -> V_274 ) ;
return V_326 -> V_260 ;
}
static int F_229 ( struct V_2 * V_2 , struct V_328 * * V_369 )
{
if ( ! ( V_369 [ V_409 ] &&
V_369 [ V_410 ] &&
V_369 [ V_411 ] ) )
return - V_137 ;
if ( F_41 ( V_2 ) -> V_116 > 0 )
return - V_137 ;
return F_182 ( V_2 ,
F_213 ( V_369 [ V_409 ] ) ,
F_216 ( V_369 [ V_410 ] ) ,
F_213 ( V_369 [ V_411 ] ) ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_328 * * V_369 )
{
if ( ! V_369 [ V_409 ] )
return - V_137 ;
return F_183 ( V_2 ,
F_213 ( V_369 [ V_409 ] ) ) ;
}
static int F_231 ( struct V_2 * V_2 , struct V_328 * * V_369 )
{
struct V_238 V_324 ;
F_189 ( V_2 , & V_324 ) ;
if ( V_369 [ V_413 ] )
V_324 . V_243 = F_213 ( V_369 [ V_413 ] ) ;
if ( V_369 [ V_414 ] )
V_324 . V_244 =
F_213 ( V_369 [ V_414 ] ) ;
if ( V_369 [ V_415 ] )
V_324 . V_245 = F_213 ( V_369 [ V_415 ] ) ;
return F_171 ( V_2 , & V_324 ) ;
}
static int F_232 ( struct V_325 * V_326 , struct V_416 * V_317 )
{
int V_149 = 0 , V_258 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_209 ( V_326 ) ;
V_15 = F_41 ( V_2 ) ;
V_258 = V_317 -> V_417 -> V_258 ;
if ( V_258 == V_412 || V_258 == V_418 ) {
struct V_328 * V_419 [ V_420 + 1 ] ;
F_132 ( & V_15 -> V_274 ) ;
if ( ! V_317 -> V_369 [ V_408 ] ||
F_211 ( V_419 , V_420 ,
V_317 -> V_369 [ V_408 ] ,
V_421 ) ) {
V_149 = - V_137 ;
goto V_67;
}
if ( V_258 == V_412 )
V_149 = F_229 ( V_2 , V_419 ) ;
else
V_149 = F_230 ( V_2 , V_419 ) ;
V_67:
F_133 ( & V_15 -> V_274 ) ;
}
return V_149 ;
}
static int F_233 ( struct V_325 * V_326 , struct V_416 * V_317 )
{
struct V_54 * V_55 = NULL ;
struct V_163 V_251 ;
struct V_109 V_110 ;
int V_149 = 0 , V_258 ;
int V_422 = 0 , V_423 = 0 ;
struct V_2 * V_2 ;
V_2 = F_209 ( V_326 ) ;
V_258 = V_317 -> V_417 -> V_258 ;
F_132 ( & V_186 ) ;
if ( V_258 == V_424 ) {
V_149 = F_129 ( V_2 , false ) ;
goto V_67;
} else if ( V_258 == V_425 ) {
V_149 = F_231 ( V_2 , V_317 -> V_369 ) ;
goto V_67;
} else if ( V_258 == V_426 &&
! V_317 -> V_369 [ V_345 ] ) {
V_149 = F_140 ( V_2 ) ;
goto V_67;
}
if ( V_258 == V_365 || V_258 == V_427 )
V_422 = 1 ;
V_149 = F_210 ( V_2 , & V_251 ,
V_317 -> V_369 [ V_345 ] ,
V_422 , & V_55 ) ;
if ( V_149 )
goto V_67;
if ( ( V_258 != V_365 ) && ( V_55 == NULL ) ) {
V_149 = - V_285 ;
goto V_67;
}
if ( V_258 == V_396 || V_258 == V_428 ||
V_258 == V_429 ) {
if ( V_258 != V_429 )
V_423 = 1 ;
V_149 = F_225 ( & V_110 ,
V_317 -> V_369 [ V_384 ] ,
V_423 ) ;
if ( V_149 )
goto V_67;
if ( V_110 . V_40 == 0 )
V_110 . V_40 = V_55 -> V_40 ;
if ( V_110 . V_40 != V_55 -> V_40 ) {
if ( F_41 ( V_2 ) -> V_306 ) {
V_149 = - V_137 ;
goto V_67;
}
switch ( V_110 . V_115 ) {
case V_209 :
break;
default:
V_149 = - V_137 ;
goto V_67;
}
}
}
switch ( V_258 ) {
case V_365 :
if ( V_55 == NULL )
V_149 = F_116 ( V_2 , & V_251 , & V_55 ) ;
else
V_149 = - V_151 ;
break;
case V_427 :
V_149 = F_125 ( V_55 , & V_251 ) ;
break;
case V_430 :
V_149 = F_128 ( V_55 ) ;
break;
case V_396 :
V_149 = F_101 ( V_55 , & V_110 ) ;
break;
case V_428 :
V_149 = F_103 ( V_55 , & V_110 ) ;
break;
case V_429 :
V_149 = F_112 ( V_55 , & V_110 ) ;
break;
case V_426 :
V_149 = F_139 ( V_55 ) ;
break;
default:
V_149 = - V_137 ;
}
V_67:
F_133 ( & V_186 ) ;
return V_149 ;
}
static int F_234 ( struct V_325 * V_326 , struct V_416 * V_317 )
{
struct V_325 * V_431 ;
void * V_432 ;
int V_149 , V_258 , V_433 ;
struct V_2 * V_2 ;
V_2 = F_209 ( V_326 ) ;
V_258 = V_317 -> V_417 -> V_258 ;
if ( V_258 == V_434 )
V_433 = V_365 ;
else if ( V_258 == V_435 )
V_433 = V_436 ;
else if ( V_258 == V_437 )
V_433 = V_425 ;
else {
F_28 ( L_59 ) ;
return - V_137 ;
}
V_431 = F_235 ( V_438 , V_140 ) ;
if ( ! V_431 )
return - V_141 ;
F_132 ( & V_186 ) ;
V_432 = F_236 ( V_431 , V_317 , & V_363 , 0 , V_433 ) ;
if ( V_432 == NULL )
goto V_341;
switch ( V_258 ) {
case V_434 :
{
struct V_54 * V_55 ;
V_55 = F_218 ( V_2 ,
V_317 -> V_369 [ V_345 ] ) ;
if ( F_224 ( V_55 ) ) {
V_149 = F_237 ( V_55 ) ;
goto V_169;
} else if ( V_55 ) {
V_149 = F_197 ( V_431 , V_55 ) ;
if ( V_149 )
goto V_341;
} else {
V_149 = - V_285 ;
goto V_169;
}
break;
}
case V_437 :
{
struct V_238 V_324 ;
F_189 ( V_2 , & V_324 ) ;
#ifdef V_239
if ( F_193 ( V_431 , V_413 ,
V_324 . V_243 ) ||
F_193 ( V_431 , V_414 ,
V_324 . V_244 ) )
goto V_341;
#endif
#ifdef V_240
if ( F_193 ( V_431 , V_415 , V_324 . V_245 ) )
goto V_341;
#endif
break;
}
case V_435 :
if ( F_193 ( V_431 , V_439 ,
V_222 ) ||
F_193 ( V_431 , V_440 ,
V_223 ) )
goto V_341;
break;
}
F_206 ( V_431 , V_432 ) ;
V_149 = F_238 ( V_431 , V_317 ) ;
goto V_67;
V_341:
F_28 ( L_60 ) ;
V_149 = - V_330 ;
V_169:
F_239 ( V_431 ) ;
V_67:
F_133 ( & V_186 ) ;
return V_149 ;
}
static int T_11 F_240 ( void )
{
return F_241 ( & V_363 ,
V_441 ) ;
}
static void F_242 ( void )
{
F_243 ( & V_363 ) ;
}
static int T_12 F_244 ( struct V_2 * V_2 )
{
int V_182 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_196 * V_442 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_99 ( & V_15 -> V_25 ) ;
F_99 ( & V_15 -> V_28 ) ;
F_99 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_443 ) ) {
V_442 = F_245 ( V_444 , sizeof( V_444 ) , V_140 ) ;
if ( V_442 == NULL )
return - V_141 ;
if ( V_2 -> V_263 != & V_445 )
V_442 [ 0 ] . V_446 = NULL ;
} else
V_442 = V_444 ;
V_182 = 0 ;
V_15 -> V_24 = 1024 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_32 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_26 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_29 ;
#ifdef F_246
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_447 ;
#endif
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_34 ;
V_15 -> V_448 = 1 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_448 ;
V_15 -> V_449 = 1 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_449 ;
V_15 -> V_450 = 1 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_450 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_451 ;
V_15 -> V_452 = F_247 () / 32 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_452 ;
V_15 -> V_453 = 0 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_453 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_454 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_455 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_456 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_457 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_458 ;
V_15 -> V_459 [ 0 ] = V_460 ;
V_15 -> V_459 [ 1 ] = V_461 ;
V_442 [ V_182 ] . V_160 = & V_15 -> V_459 ;
V_442 [ V_182 ++ ] . V_462 = sizeof( V_15 -> V_459 ) ;
V_15 -> V_463 = V_464 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_463 ;
V_15 -> V_465 = F_248 ( int , V_466 , 0 , 3 ) ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_465 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_467 ;
V_15 -> V_468 = 1 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_468 ;
V_442 [ V_182 ++ ] . V_160 = & V_15 -> V_469 ;
V_15 -> V_470 = F_249 ( V_2 , L_61 , V_442 ) ;
if ( V_15 -> V_470 == NULL ) {
if ( ! F_38 ( V_2 , & V_443 ) )
F_49 ( V_442 ) ;
return - V_141 ;
}
F_86 ( V_2 , & V_15 -> V_195 ) ;
V_15 -> V_471 = V_442 ;
F_250 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_251 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_252 ( & V_15 -> V_37 ) ;
F_253 ( & V_15 -> V_37 . V_36 ) ;
F_254 ( V_15 -> V_470 ) ;
F_105 ( V_2 , & V_15 -> V_195 ) ;
}
static int T_12 F_244 ( struct V_2 * V_2 ) { return 0 ; }
static void T_13 F_251 ( struct V_2 * V_2 ) { }
int T_12 F_255 ( struct V_2 * V_2 )
{
int V_17 , V_182 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
for ( V_182 = 0 ; V_182 < V_472 ; V_182 ++ )
F_256 ( & V_15 -> V_85 [ V_182 ] ) ;
F_120 ( & V_15 -> V_154 ) ;
F_99 ( & V_15 -> V_96 ) ;
F_257 ( & V_15 -> V_99 , F_113 ,
( unsigned long ) V_2 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_195 . V_77 = F_93 ( struct V_142 ) ;
if ( ! V_15 -> V_195 . V_77 )
return - V_141 ;
F_94 (i) {
struct V_142 * V_473 ;
V_473 = F_95 ( V_15 -> V_195 . V_77 , V_17 ) ;
F_96 ( & V_473 -> V_145 ) ;
}
F_99 ( & V_15 -> V_195 . V_103 ) ;
F_258 ( L_62 , 0 , V_2 -> V_474 , & V_475 ) ;
F_258 ( L_63 , 0 , V_2 -> V_474 , & V_476 ) ;
F_258 ( L_64 , 0 , V_2 -> V_474 ,
& V_477 ) ;
if ( F_244 ( V_2 ) )
goto V_478;
return 0 ;
V_478:
F_48 ( V_15 -> V_195 . V_77 ) ;
return - V_141 ;
}
void T_13 F_259 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_75 ( V_2 ) ;
F_251 ( V_2 ) ;
F_260 ( L_64 , V_2 -> V_474 ) ;
F_260 ( L_63 , V_2 -> V_474 ) ;
F_260 ( L_62 , V_2 -> V_474 ) ;
F_48 ( V_15 -> V_195 . V_77 ) ;
}
int T_11 F_261 ( void )
{
int V_149 ;
V_149 = F_262 ( & V_479 ) ;
if ( V_149 ) {
F_28 ( L_65 ) ;
goto V_480;
}
V_149 = F_240 () ;
if ( V_149 ) {
F_28 ( L_66 ) ;
goto V_481;
}
return 0 ;
V_481:
F_263 ( & V_479 ) ;
V_480:
return V_149 ;
}
void F_264 ( void )
{
F_242 () ;
F_263 ( & V_479 ) ;
}
int T_11 F_265 ( void )
{
int V_182 ;
int V_149 ;
F_89 ( 2 ) ;
for ( V_182 = 0 ; V_182 < V_185 ; V_182 ++ ) {
F_256 ( & V_61 [ V_182 ] ) ;
F_256 ( & V_63 [ V_182 ] ) ;
}
F_266 () ;
V_149 = F_267 ( & V_482 ) ;
if ( V_149 < 0 )
return V_149 ;
F_100 ( 2 ) ;
return 0 ;
}
void F_268 ( void )
{
F_89 ( 2 ) ;
F_269 ( & V_482 ) ;
F_100 ( 2 ) ;
}
