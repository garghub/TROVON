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
#define F_79 ( T_5 ) dst->c = src->kstats.c - src->kstats0.c
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
F_81 ( struct V_109 * V_9 , struct V_100 * V_102 )
{
V_9 -> V_104 = ( V_110 ) V_102 -> V_104 ;
V_9 -> V_105 = ( V_110 ) V_102 -> V_105 ;
V_9 -> V_106 = ( V_110 ) V_102 -> V_106 ;
V_9 -> V_107 = V_102 -> V_107 ;
V_9 -> V_108 = V_102 -> V_108 ;
V_9 -> V_111 = ( V_110 ) V_102 -> V_111 ;
V_9 -> V_112 = ( V_110 ) V_102 -> V_112 ;
V_9 -> V_113 = ( V_110 ) V_102 -> V_113 ;
V_9 -> V_114 = ( V_110 ) V_102 -> V_114 ;
V_9 -> V_115 = ( V_110 ) V_102 -> V_115 ;
}
static void
F_82 ( struct V_101 * V_76 )
{
F_68 ( & V_76 -> V_103 ) ;
#define F_83 ( T_5 ) stats->kstats0.c = stats->kstats.c
F_83 ( V_104 ) ;
F_83 ( V_105 ) ;
F_83 ( V_106 ) ;
F_83 ( V_107 ) ;
F_83 ( V_108 ) ;
F_84 ( V_76 ) ;
F_72 ( & V_76 -> V_103 ) ;
}
static void
F_85 ( struct V_54 * V_55 , struct V_74 * V_75 ,
struct V_116 * V_117 , int V_118 )
{
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
struct V_54 * V_119 ;
struct V_120 * V_121 ;
int V_122 ;
F_86 ( ! V_118 && V_117 -> V_40 != V_75 -> V_40 ) ;
if ( V_118 && V_117 -> V_40 != V_55 -> V_40 )
V_15 -> V_123 ++ ;
F_9 ( & V_75 -> V_124 , V_117 -> V_124 ) ;
V_122 = V_117 -> V_122 & V_125 ;
V_122 |= V_126 ;
if ( ( V_122 & V_90 ) != V_91 ) {
V_122 |= V_127 ;
} else {
F_55 ( V_15 , V_75 ) ;
}
F_9 ( & V_75 -> V_122 , V_122 ) ;
V_119 = F_65 ( V_75 -> V_55 , 1 ) ;
if ( ! V_119 ) {
F_45 ( V_75 , V_55 ) ;
} else {
if ( V_119 != V_55 ) {
F_82 ( & V_75 -> V_76 ) ;
F_45 ( V_75 , V_55 ) ;
F_51 ( V_119 , true ) ;
}
}
V_75 -> V_12 |= V_128 ;
if ( V_117 -> V_129 == 0 || V_117 -> V_129 > V_75 -> V_129 )
V_75 -> V_12 &= ~ V_130 ;
V_75 -> V_129 = V_117 -> V_129 ;
V_75 -> V_131 = V_117 -> V_131 ;
V_75 -> V_40 = V_117 -> V_40 ;
F_68 ( & V_75 -> V_132 ) ;
F_64 ( V_75 ) ;
F_72 ( & V_75 -> V_132 ) ;
if ( V_118 ) {
F_87 ( V_55 -> V_2 , & V_75 -> V_76 ) ;
F_88 ( & V_75 -> V_133 , & V_55 -> V_134 ) ;
V_55 -> V_135 ++ ;
V_121 = F_65 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_137 )
V_121 -> V_137 ( V_55 , V_75 ) ;
} else {
V_121 = F_65 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_138 )
V_121 -> V_138 ( V_55 , V_75 ) ;
}
}
static int
F_89 ( struct V_54 * V_55 , struct V_116 * V_117 ,
struct V_74 * * V_139 )
{
struct V_74 * V_75 ;
unsigned int V_140 , V_17 ;
F_90 ( 2 ) ;
#ifdef F_24
if ( V_117 -> V_40 == V_48 ) {
V_140 = F_91 ( & V_117 -> V_4 . V_141 ) ;
if ( ( ! ( V_140 & V_142 ) ||
V_140 & V_143 ) &&
! F_2 ( V_55 -> V_2 , & V_117 -> V_4 . V_141 ) )
return - V_144 ;
} else
#endif
{
V_140 = F_92 ( V_55 -> V_2 , V_117 -> V_4 . V_46 ) ;
if ( V_140 != V_145 && V_140 != V_146 )
return - V_144 ;
}
V_75 = F_93 ( sizeof( struct V_74 ) , V_147 ) ;
if ( V_75 == NULL )
return - V_148 ;
V_75 -> V_76 . V_77 = F_94 ( struct V_149 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_150;
F_95 (i) {
struct V_149 * V_151 ;
V_151 = F_96 ( V_75 -> V_76 . V_77 , V_17 ) ;
F_97 ( & V_151 -> V_152 ) ;
}
V_75 -> V_40 = V_117 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_87 = V_55 -> V_53 ;
F_98 ( V_117 -> V_40 , & V_75 -> V_4 , & V_117 -> V_4 ) ;
V_75 -> V_43 = V_117 -> V_43 ;
F_9 ( & V_75 -> V_153 , 0 ) ;
F_9 ( & V_75 -> V_154 , 0 ) ;
F_9 ( & V_75 -> V_155 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_99 ( & V_75 -> V_84 ) ;
F_100 ( & V_75 -> V_132 ) ;
F_100 ( & V_75 -> V_76 . V_103 ) ;
F_85 ( V_55 , V_75 , V_117 , 1 ) ;
* V_139 = V_75 ;
F_101 ( 2 ) ;
return 0 ;
V_150:
F_49 ( V_75 ) ;
return - V_148 ;
}
static int
F_102 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_117 -> V_43 ;
int V_156 ;
F_90 ( 2 ) ;
if ( V_117 -> V_124 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_157 ;
}
if ( V_117 -> V_131 > V_117 -> V_129 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_157 ;
}
F_98 ( V_117 -> V_40 , & V_7 , & V_117 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 != NULL ) {
F_103 ( 1 , L_11 , V_58 ) ;
return - V_158 ;
}
V_75 = F_67 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
if ( V_75 != NULL ) {
F_42 ( 3 , L_12
L_13 ,
F_44 ( V_117 -> V_40 , & V_7 ) , F_23 ( V_86 ) ,
F_15 ( & V_75 -> V_64 ) ,
V_75 -> V_87 ,
F_44 ( V_55 -> V_40 , & V_75 -> V_65 ) ,
F_23 ( V_75 -> V_66 ) ) ;
F_85 ( V_55 , V_75 , V_117 , 1 ) ;
V_156 = 0 ;
} else {
V_156 = F_89 ( V_55 , V_117 , & V_75 ) ;
}
F_101 ( 2 ) ;
return V_156 ;
}
static int
F_104 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_117 -> V_43 ;
F_90 ( 2 ) ;
if ( V_117 -> V_124 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_157 ;
}
if ( V_117 -> V_131 > V_117 -> V_129 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_157 ;
}
F_98 ( V_117 -> V_40 , & V_7 , & V_117 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_103 ( 1 , L_14 , V_58 ) ;
return - V_159 ;
}
F_85 ( V_55 , V_75 , V_117 , 0 ) ;
F_101 ( 2 ) ;
return 0 ;
}
static void F_105 ( struct V_2 * V_2 , struct V_74 * V_75 ,
bool V_160 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_106 ( V_2 , & V_75 -> V_76 ) ;
F_56 ( V_75 ) ;
F_68 ( & V_15 -> V_96 ) ;
F_42 ( 3 , L_15 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_107 ( & V_15 -> V_161 ) && ! V_160 )
F_108 ( & V_15 -> V_99 ,
V_162 + ( V_163 >> 1 ) ) ;
F_109 ( & V_75 -> V_97 , & V_15 -> V_161 ) ;
V_75 -> V_164 = 0 ;
F_72 ( & V_15 -> V_96 ) ;
F_110 ( V_75 ) ;
}
static void F_111 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_165 )
{
V_75 -> V_12 &= ~ V_128 ;
F_112 ( & V_75 -> V_133 ) ;
V_55 -> V_135 -- ;
if ( V_75 -> V_40 != V_55 -> V_40 )
F_41 ( V_55 -> V_2 ) -> V_123 -- ;
if ( V_165 ) {
struct V_120 * V_121 ;
V_121 = F_65 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_166 )
V_121 -> V_166 ( V_55 , V_75 ) ;
}
}
static int
F_113 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
T_1 V_86 = V_117 -> V_43 ;
F_90 ( 2 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , V_117 -> V_40 , & V_117 -> V_4 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_103 ( 1 , L_16 , V_58 ) ;
return - V_159 ;
}
F_111 ( V_55 , V_75 , 1 ) ;
F_105 ( V_55 -> V_2 , V_75 , false ) ;
F_101 ( 2 ) ;
return 0 ;
}
static void F_114 ( unsigned long V_167 )
{
struct V_2 * V_2 = (struct V_2 * ) V_167 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_74 * V_75 , * V_168 ;
unsigned long V_169 = V_162 ;
F_8 ( & V_15 -> V_96 ) ;
F_77 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
if ( V_75 -> V_164 ) {
if ( F_115 ( V_169 , V_75 -> V_164 +
V_163 ) )
continue;
} else {
V_75 -> V_164 = F_116 ( 1UL , V_169 ) ;
continue;
}
F_42 ( 3 , L_17 ,
V_75 -> V_87 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_70 ( & V_75 -> V_97 ) ;
F_73 ( V_75 ) ;
}
if ( ! F_107 ( & V_15 -> V_161 ) )
F_108 ( & V_15 -> V_99 ,
V_162 + ( V_163 >> 1 ) ) ;
F_10 ( & V_15 -> V_96 ) ;
}
static int
F_117 ( struct V_2 * V_2 , struct V_170 * V_171 ,
struct V_54 * * V_172 )
{
int V_156 = 0 , V_17 ;
struct V_120 * V_121 = NULL ;
struct V_173 * V_174 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_18 () ;
if ( strcmp ( V_171 -> V_175 , L_18 ) ) {
V_121 = F_118 ( V_171 -> V_175 ) ;
if ( ! V_121 ) {
F_119 ( L_19 ,
V_171 -> V_175 ) ;
V_156 = - V_159 ;
goto V_176;
}
}
if ( V_171 -> V_177 && * V_171 -> V_177 ) {
V_174 = F_120 ( V_171 -> V_177 ) ;
if ( V_174 == NULL ) {
F_119 ( L_20
L_21 , V_171 -> V_177 ) ;
V_156 = - V_159 ;
goto V_176;
}
}
#ifdef F_24
if ( V_171 -> V_40 == V_48 ) {
T_3 V_178 = ( V_179 T_3 ) V_171 -> V_180 ;
if ( V_178 < 1 || V_178 > 128 ) {
V_156 = - V_144 ;
goto V_176;
}
}
#endif
V_55 = F_93 ( sizeof( struct V_54 ) , V_147 ) ;
if ( V_55 == NULL ) {
F_103 ( 1 , L_22 , V_58 ) ;
V_156 = - V_148 ;
goto V_176;
}
V_55 -> V_76 . V_77 = F_94 ( struct V_149 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_156 = - V_148 ;
goto V_176;
}
F_95 (i) {
struct V_149 * V_101 ;
V_101 = F_96 ( V_55 -> V_76 . V_77 , V_17 ) ;
F_97 ( & V_101 -> V_152 ) ;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_171 -> V_40 ;
V_55 -> V_59 = V_171 -> V_59 ;
F_98 ( V_55 -> V_40 , & V_55 -> V_4 , & V_171 -> V_4 ) ;
V_55 -> V_43 = V_171 -> V_43 ;
V_55 -> V_53 = V_171 -> V_53 ;
V_55 -> V_12 = V_171 -> V_12 ;
V_55 -> V_181 = V_171 -> V_181 * V_182 ;
V_55 -> V_180 = V_171 -> V_180 ;
V_55 -> V_2 = V_2 ;
F_121 ( & V_55 -> V_134 ) ;
F_100 ( & V_55 -> V_183 ) ;
F_100 ( & V_55 -> V_76 . V_103 ) ;
if ( V_121 ) {
V_156 = F_122 ( V_55 , V_121 ) ;
if ( V_156 )
goto V_176;
V_121 = NULL ;
}
F_66 ( V_55 -> V_174 , V_174 ) ;
V_174 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_87 ( V_2 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_184 )
V_15 -> V_185 ++ ;
F_27 ( V_55 ) ;
* V_172 = V_55 ;
V_15 -> V_186 = 1 ;
return 0 ;
V_176:
if ( V_55 != NULL ) {
F_123 ( V_55 , V_121 ) ;
F_47 ( V_55 ) ;
}
F_124 ( V_121 ) ;
F_125 ( V_174 ) ;
F_20 () ;
return V_156 ;
}
static int
F_126 ( struct V_54 * V_55 , struct V_170 * V_171 )
{
struct V_120 * V_121 = NULL , * V_187 ;
struct V_173 * V_174 = NULL , * V_188 = NULL ;
int V_156 = 0 ;
if ( strcmp ( V_171 -> V_175 , L_18 ) ) {
V_121 = F_118 ( V_171 -> V_175 ) ;
if ( ! V_121 ) {
F_119 ( L_19 ,
V_171 -> V_175 ) ;
return - V_159 ;
}
}
V_187 = V_121 ;
if ( V_171 -> V_177 && * V_171 -> V_177 ) {
V_174 = F_120 ( V_171 -> V_177 ) ;
if ( V_174 == NULL ) {
F_119 ( L_20
L_21 , V_171 -> V_177 ) ;
V_156 = - V_159 ;
goto V_67;
}
V_188 = V_174 ;
}
#ifdef F_24
if ( V_171 -> V_40 == V_48 ) {
T_3 V_178 = ( V_179 T_3 ) V_171 -> V_180 ;
if ( V_178 < 1 || V_178 > 128 ) {
V_156 = - V_144 ;
goto V_67;
}
}
#endif
V_187 = F_65 ( V_55 -> V_136 , 1 ) ;
if ( V_121 != V_187 ) {
if ( V_187 ) {
F_123 ( V_55 , V_187 ) ;
F_66 ( V_55 -> V_136 , NULL ) ;
F_127 () ;
}
if ( V_121 ) {
V_156 = F_122 ( V_55 , V_121 ) ;
if ( V_156 ) {
F_124 ( V_121 ) ;
goto V_67;
}
}
}
V_55 -> V_12 = V_171 -> V_12 | V_57 ;
V_55 -> V_181 = V_171 -> V_181 * V_182 ;
V_55 -> V_180 = V_171 -> V_180 ;
V_188 = F_65 ( V_55 -> V_174 , 1 ) ;
if ( V_174 != V_188 )
F_46 ( V_55 -> V_174 , V_174 ) ;
V_67:
F_124 ( V_187 ) ;
F_125 ( V_188 ) ;
return V_156 ;
}
static void F_128 ( struct V_54 * V_55 , bool V_160 )
{
struct V_74 * V_75 , * V_98 ;
struct V_120 * V_187 ;
struct V_173 * V_188 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_119 ( L_23 , V_58 ) ;
if ( V_55 -> V_40 == V_184 )
V_15 -> V_185 -- ;
F_106 ( V_55 -> V_2 , & V_55 -> V_76 ) ;
V_187 = F_65 ( V_55 -> V_136 , 1 ) ;
F_123 ( V_55 , V_187 ) ;
F_124 ( V_187 ) ;
V_188 = F_65 ( V_55 -> V_174 , 1 ) ;
F_125 ( V_188 ) ;
F_77 (dest, nxt, &svc->destinations, n_list) {
F_111 ( V_55 , V_75 , 0 ) ;
F_105 ( V_55 -> V_2 , V_75 , V_160 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
F_51 ( V_55 , true ) ;
F_20 () ;
}
static void F_129 ( struct V_54 * V_55 , bool V_160 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_128 ( V_55 , V_160 ) ;
}
static int F_130 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_158 ;
F_129 ( V_55 , false ) ;
return 0 ;
}
static int F_131 ( struct V_2 * V_2 , bool V_160 )
{
int V_189 ;
struct V_54 * V_55 ;
struct V_190 * V_191 ;
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_132 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_129 ( V_55 , V_160 ) ;
}
}
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_132 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_129 ( V_55 , V_160 ) ;
}
}
return 0 ;
}
void F_133 ( struct V_2 * V_2 )
{
F_90 ( 2 ) ;
F_134 ( & V_193 ) ;
F_131 ( V_2 , true ) ;
F_135 ( & V_193 ) ;
F_101 ( 2 ) ;
}
static inline void
F_136 ( struct V_74 * V_75 , struct V_194 * V_11 )
{
struct V_92 * V_93 ;
F_68 ( & V_75 -> V_132 ) ;
V_93 = F_65 ( V_75 -> V_93 , 1 ) ;
if ( V_93 && V_93 -> V_94 -> V_11 == V_11 ) {
F_42 ( 3 , L_24 ,
V_11 -> V_195 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_64 ( V_75 ) ;
}
F_72 ( & V_75 -> V_132 ) ;
}
static int F_137 ( struct V_196 * V_197 , unsigned long V_198 ,
void * V_199 )
{
struct V_194 * V_11 = F_138 ( V_199 ) ;
struct V_2 * V_2 = F_139 ( V_11 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_189 ;
if ( V_198 != V_200 || ! V_15 )
return V_201 ;
F_103 ( 3 , L_25 , V_58 , V_11 -> V_195 ) ;
F_90 ( 2 ) ;
F_134 ( & V_193 ) ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_140 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_136 ( V_75 , V_11 ) ;
}
}
}
F_140 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_136 ( V_75 , V_11 ) ;
}
}
}
}
F_68 ( & V_15 -> V_96 ) ;
F_69 (dest, &ipvs->dest_trash, t_list) {
F_136 ( V_75 , V_11 ) ;
}
F_72 ( & V_15 -> V_96 ) ;
F_135 ( & V_193 ) ;
F_101 ( 2 ) ;
return V_201 ;
}
static int F_141 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_69 (dest, &svc->destinations, n_list) {
F_82 ( & V_75 -> V_76 ) ;
}
F_82 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 )
{
int V_189 ;
struct V_54 * V_55 ;
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_140 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_141 ( V_55 ) ;
}
}
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_140 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_141 ( V_55 ) ;
}
}
F_82 ( & F_41 ( V_2 ) -> V_202 ) ;
return 0 ;
}
static int
F_143 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
struct V_2 * V_2 = V_209 -> V_210 -> V_211 ;
int * V_212 = V_204 -> V_167 ;
int V_213 = * V_212 ;
int V_214 ;
V_214 = F_144 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( * V_212 != V_213 ) ) {
if ( ( * V_212 < 0 ) || ( * V_212 > 3 ) ) {
* V_212 = V_213 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_214 ;
}
static int
F_145 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
int * V_212 = V_204 -> V_167 ;
int V_213 [ 2 ] ;
int V_214 ;
memcpy ( V_213 , V_212 , sizeof( V_213 ) ) ;
V_214 = F_144 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( V_212 [ 0 ] < 0 || V_212 [ 1 ] < 0 ||
( V_212 [ 0 ] >= V_212 [ 1 ] && V_212 [ 1 ] ) ) ) {
memcpy ( V_212 , V_213 , sizeof( V_213 ) ) ;
}
return V_214 ;
}
static int
F_146 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
int * V_212 = V_204 -> V_167 ;
int V_213 = * V_212 ;
int V_214 ;
V_214 = F_144 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( * V_212 != V_213 ) ) {
if ( ( * V_212 < 0 ) || ( * V_212 > 1 ) ) {
* V_212 = V_213 ;
}
}
return V_214 ;
}
static int
F_147 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
int * V_212 = V_204 -> V_167 ;
int V_213 = * V_212 ;
int V_214 ;
V_214 = F_144 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( * V_212 != V_213 ) ) {
if ( * V_212 < 1 || ! F_148 ( * V_212 ) ) {
* V_212 = V_213 ;
}
}
return V_214 ;
}
static inline const char * F_149 ( unsigned int V_12 )
{
switch ( V_12 & V_90 ) {
case V_215 :
return L_26 ;
case V_216 :
return L_27 ;
case V_217 :
return L_28 ;
default:
return L_29 ;
}
}
static struct V_54 * F_150 ( struct V_218 * V_219 , T_7 V_220 )
{
struct V_2 * V_2 = F_151 ( V_219 ) ;
struct V_221 * V_222 = V_219 -> V_223 ;
int V_189 ;
struct V_54 * V_55 ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_220 -- == 0 ) {
V_222 -> V_204 = V_61 ;
V_222 -> V_224 = V_189 ;
return V_55 ;
}
}
}
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_220 -- == 0 ) {
V_222 -> V_204 = V_63 ;
V_222 -> V_224 = V_189 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_152 ( struct V_218 * V_219 , T_7 * V_220 )
__acquires( T_8 )
{
F_58 () ;
return * V_220 ? F_150 ( V_219 , * V_220 - 1 ) : V_225 ;
}
static void * F_153 ( struct V_218 * V_219 , void * V_226 , T_7 * V_220 )
{
struct V_190 * V_227 ;
struct V_221 * V_222 ;
struct V_54 * V_55 ;
++ * V_220 ;
if ( V_226 == V_225 )
return F_150 ( V_219 , 0 ) ;
V_55 = V_226 ;
V_222 = V_219 -> V_223 ;
if ( V_222 -> V_204 == V_61 ) {
V_227 = F_154 ( F_155 ( & V_55 -> V_60 ) ) ;
if ( V_227 )
return F_156 ( V_227 , struct V_54 , V_60 ) ;
while ( ++ V_222 -> V_224 < V_192 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_222 -> V_204 = V_63 ;
V_222 -> V_224 = - 1 ;
goto V_228;
}
V_227 = F_154 ( F_155 ( & V_55 -> V_62 ) ) ;
if ( V_227 )
return F_156 ( V_227 , struct V_54 , V_62 ) ;
V_228:
while ( ++ V_222 -> V_224 < V_192 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_157 ( struct V_218 * V_219 , void * V_226 )
__releases( T_8 )
{
F_59 () ;
}
static int F_158 ( struct V_218 * V_219 , void * V_226 )
{
if ( V_226 == V_225 ) {
F_159 ( V_219 ,
L_30 ,
F_160 ( V_229 ) , V_230 ) ;
F_161 ( V_219 ,
L_31 ) ;
F_161 ( V_219 ,
L_32 ) ;
} else {
const struct V_54 * V_55 = V_226 ;
const struct V_221 * V_222 = V_219 -> V_223 ;
const struct V_74 * V_75 ;
struct V_120 * V_121 = F_154 ( V_55 -> V_136 ) ;
char * V_175 = V_121 ? V_121 -> V_195 : L_18 ;
if ( V_222 -> V_204 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_159 ( V_219 , L_33 ,
F_43 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_141 ,
F_23 ( V_55 -> V_43 ) ,
V_175 ) ;
else
#endif
F_159 ( V_219 , L_34 ,
F_43 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_175 ,
( V_55 -> V_12 & V_231 ) ? L_35 : L_36 ) ;
} else {
F_159 ( V_219 , L_37 ,
V_55 -> V_53 , V_175 ,
( V_55 -> V_12 & V_231 ) ? L_35 : L_36 ) ;
}
if ( V_55 -> V_12 & V_232 )
F_159 ( V_219 , L_38 ,
V_55 -> V_181 ,
F_25 ( V_55 -> V_180 ) ) ;
else
F_162 ( V_219 , '\n' ) ;
F_61 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_159 ( V_219 ,
L_39
L_40 ,
& V_75 -> V_4 . V_141 ,
F_23 ( V_75 -> V_43 ) ,
F_149 ( F_15 ( & V_75 -> V_122 ) ) ,
F_15 ( & V_75 -> V_124 ) ,
F_15 ( & V_75 -> V_153 ) ,
F_15 ( & V_75 -> V_154 ) ) ;
else
#endif
F_159 ( V_219 ,
L_41
L_42 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_149 ( F_15 ( & V_75 -> V_122 ) ) ,
F_15 ( & V_75 -> V_124 ) ,
F_15 ( & V_75 -> V_153 ) ,
F_15 ( & V_75 -> V_154 ) ) ;
}
}
return 0 ;
}
static int F_163 ( struct V_233 * V_233 , struct V_234 * V_234 )
{
return F_164 ( V_233 , V_234 , & V_235 ,
sizeof( struct V_221 ) ) ;
}
static int F_165 ( struct V_218 * V_219 , void * V_226 )
{
struct V_2 * V_2 = F_166 ( V_219 ) ;
struct V_100 V_236 ;
F_161 ( V_219 ,
L_43 ) ;
F_159 ( V_219 ,
L_44 ) ;
F_78 ( & V_236 , & F_41 ( V_2 ) -> V_202 ) ;
F_159 ( V_219 , L_45 ,
( unsigned long long ) V_236 . V_104 ,
( unsigned long long ) V_236 . V_105 ,
( unsigned long long ) V_236 . V_106 ,
( unsigned long long ) V_236 . V_107 ,
( unsigned long long ) V_236 . V_108 ) ;
F_161 ( V_219 ,
L_46 ) ;
F_159 ( V_219 , L_47 ,
( unsigned long long ) V_236 . V_111 ,
( unsigned long long ) V_236 . V_112 ,
( unsigned long long ) V_236 . V_113 ,
( unsigned long long ) V_236 . V_114 ,
( unsigned long long ) V_236 . V_115 ) ;
return 0 ;
}
static int F_167 ( struct V_233 * V_233 , struct V_234 * V_234 )
{
return F_168 ( V_233 , V_234 , F_165 ) ;
}
static int F_169 ( struct V_218 * V_219 , void * V_226 )
{
struct V_2 * V_2 = F_166 ( V_219 ) ;
struct V_101 * V_202 = & F_41 ( V_2 ) -> V_202 ;
struct V_149 T_9 * V_77 = V_202 -> V_77 ;
struct V_100 V_237 ;
int V_17 ;
F_161 ( V_219 ,
L_48 ) ;
F_159 ( V_219 ,
L_49 ) ;
F_95 (i) {
struct V_149 * V_171 = F_96 ( V_77 , V_17 ) ;
unsigned int V_238 ;
T_10 V_104 , V_105 , V_106 , V_107 , V_108 ;
do {
V_238 = F_170 ( & V_171 -> V_152 ) ;
V_104 = V_171 -> V_239 . V_104 ;
V_105 = V_171 -> V_239 . V_105 ;
V_106 = V_171 -> V_239 . V_106 ;
V_107 = V_171 -> V_239 . V_107 ;
V_108 = V_171 -> V_239 . V_108 ;
} while ( F_171 ( & V_171 -> V_152 , V_238 ) );
F_159 ( V_219 , L_50 ,
V_17 , ( T_10 ) V_104 , ( T_10 ) V_105 ,
( T_10 ) V_106 , ( T_10 ) V_107 ,
( T_10 ) V_108 ) ;
}
F_78 ( & V_237 , V_202 ) ;
F_159 ( V_219 , L_51 ,
( unsigned long long ) V_237 . V_104 ,
( unsigned long long ) V_237 . V_105 ,
( unsigned long long ) V_237 . V_106 ,
( unsigned long long ) V_237 . V_107 ,
( unsigned long long ) V_237 . V_108 ) ;
F_161 ( V_219 ,
L_52 ) ;
F_159 ( V_219 , L_53 ,
V_237 . V_111 ,
V_237 . V_112 ,
V_237 . V_113 ,
V_237 . V_114 ,
V_237 . V_115 ) ;
return 0 ;
}
static int F_172 ( struct V_233 * V_233 , struct V_234 * V_234 )
{
return F_168 ( V_233 , V_234 , F_169 ) ;
}
static int F_173 ( struct V_2 * V_2 , struct V_240 * V_171 )
{
#if F_174 ( V_241 ) || F_174 ( V_242 )
struct V_243 * V_244 ;
#endif
F_103 ( 2 , L_54 ,
V_171 -> V_245 ,
V_171 -> V_246 ,
V_171 -> V_247 ) ;
#ifdef V_241
if ( V_171 -> V_245 ) {
V_244 = F_175 ( V_2 , V_68 ) ;
V_244 -> V_248 [ V_249 ]
= V_171 -> V_245 * V_182 ;
}
if ( V_171 -> V_246 ) {
V_244 = F_175 ( V_2 , V_68 ) ;
V_244 -> V_248 [ V_250 ]
= V_171 -> V_246 * V_182 ;
}
#endif
#ifdef V_242
if ( V_171 -> V_247 ) {
V_244 = F_175 ( V_2 , V_251 ) ;
V_244 -> V_248 [ V_252 ]
= V_171 -> V_247 * V_182 ;
}
#endif
return 0 ;
}
static void F_176 ( struct V_170 * V_253 ,
struct V_254 * V_255 )
{
memset ( V_253 , 0 , sizeof( * V_253 ) ) ;
V_253 -> V_40 = V_184 ;
V_253 -> V_59 = V_255 -> V_59 ;
V_253 -> V_4 . V_46 = V_255 -> V_4 ;
V_253 -> V_43 = V_255 -> V_43 ;
V_253 -> V_53 = V_255 -> V_53 ;
V_253 -> V_175 = V_255 -> V_175 ;
V_253 -> V_12 = V_255 -> V_12 ;
V_253 -> V_181 = V_255 -> V_181 ;
V_253 -> V_180 = V_255 -> V_180 ;
}
static void F_177 ( struct V_116 * V_117 ,
struct V_256 * V_257 )
{
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
V_117 -> V_4 . V_46 = V_257 -> V_4 ;
V_117 -> V_43 = V_257 -> V_43 ;
V_117 -> V_122 = V_257 -> V_122 ;
V_117 -> V_124 = V_257 -> V_124 ;
V_117 -> V_129 = V_257 -> V_129 ;
V_117 -> V_131 = V_257 -> V_131 ;
V_117 -> V_40 = V_184 ;
}
static int
F_178 ( struct V_258 * V_259 , int V_260 , void T_6 * V_261 , unsigned int V_262 )
{
struct V_2 * V_2 = F_179 ( V_259 ) ;
int V_156 ;
unsigned char V_263 [ V_264 ] ;
struct V_254 * V_255 ;
struct V_170 V_253 ;
struct V_54 * V_55 ;
struct V_256 * V_257 ;
struct V_116 V_117 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_180 ( sizeof( V_263 ) > 255 ) ;
if ( ! F_181 ( F_179 ( V_259 ) -> V_265 , V_266 ) )
return - V_267 ;
if ( V_260 < V_268 || V_260 > V_269 )
return - V_144 ;
if ( V_262 != V_270 [ F_182 ( V_260 ) ] ) {
F_103 ( 1 , L_55 ,
V_262 , V_270 [ F_182 ( V_260 ) ] ) ;
return - V_144 ;
}
if ( F_183 ( V_263 , V_261 , V_262 ) != 0 )
return - V_271 ;
F_18 () ;
if ( V_260 == V_272 ||
V_260 == V_273 ) {
struct V_274 * V_275 = (struct V_274 * ) V_263 ;
F_134 ( & V_15 -> V_276 ) ;
if ( V_260 == V_272 )
V_156 = F_184 ( V_2 , V_275 -> V_277 , V_275 -> V_278 ,
V_275 -> V_279 ) ;
else
V_156 = F_185 ( V_2 , V_275 -> V_277 ) ;
F_135 ( & V_15 -> V_276 ) ;
goto V_280;
}
F_134 ( & V_193 ) ;
if ( V_260 == V_281 ) {
V_156 = F_131 ( V_2 , false ) ;
goto V_282;
} else if ( V_260 == V_283 ) {
V_156 = F_173 ( V_2 , (struct V_240 * ) V_263 ) ;
goto V_282;
}
V_255 = (struct V_254 * ) V_263 ;
V_257 = (struct V_256 * ) ( V_255 + 1 ) ;
F_176 ( & V_253 , V_255 ) ;
F_177 ( & V_117 , V_257 ) ;
if ( V_260 == V_284 ) {
if ( ! V_253 . V_53 && ! V_253 . V_4 . V_46 && ! V_253 . V_43 ) {
V_156 = F_142 ( V_2 ) ;
goto V_282;
}
}
if ( V_253 . V_59 != V_68 && V_253 . V_59 != V_251 &&
V_253 . V_59 != V_285 ) {
F_28 ( L_56 ,
V_253 . V_59 , & V_253 . V_4 . V_46 ,
F_23 ( V_253 . V_43 ) , V_253 . V_175 ) ;
V_156 = - V_271 ;
goto V_282;
}
F_58 () ;
if ( V_253 . V_53 == 0 )
V_55 = F_35 ( V_2 , V_253 . V_40 , V_253 . V_59 ,
& V_253 . V_4 , V_253 . V_43 ) ;
else
V_55 = F_39 ( V_2 , V_253 . V_40 , V_253 . V_53 ) ;
F_59 () ;
if ( V_260 != V_286
&& ( V_55 == NULL || V_55 -> V_59 != V_253 . V_59 ) ) {
V_156 = - V_287 ;
goto V_282;
}
switch ( V_260 ) {
case V_286 :
if ( V_55 != NULL )
V_156 = - V_158 ;
else
V_156 = F_117 ( V_2 , & V_253 , & V_55 ) ;
break;
case V_288 :
V_156 = F_126 ( V_55 , & V_253 ) ;
break;
case V_289 :
V_156 = F_130 ( V_55 ) ;
if ( ! V_156 )
goto V_282;
break;
case V_284 :
V_156 = F_141 ( V_55 ) ;
break;
case V_290 :
V_156 = F_102 ( V_55 , & V_117 ) ;
break;
case V_291 :
V_156 = F_104 ( V_55 , & V_117 ) ;
break;
case V_292 :
V_156 = F_113 ( V_55 , & V_117 ) ;
break;
default:
V_156 = - V_144 ;
}
V_282:
F_135 ( & V_193 ) ;
V_280:
F_20 () ;
return V_156 ;
}
static void
F_186 ( struct V_293 * V_9 , struct V_54 * V_102 )
{
struct V_120 * V_121 ;
struct V_100 V_237 ;
char * V_175 ;
V_121 = F_65 ( V_102 -> V_136 , 1 ) ;
V_175 = V_121 ? V_121 -> V_195 : L_18 ;
V_9 -> V_59 = V_102 -> V_59 ;
V_9 -> V_4 = V_102 -> V_4 . V_46 ;
V_9 -> V_43 = V_102 -> V_43 ;
V_9 -> V_53 = V_102 -> V_53 ;
F_187 ( V_9 -> V_175 , V_175 , sizeof( V_9 -> V_175 ) ) ;
V_9 -> V_12 = V_102 -> V_12 ;
V_9 -> V_181 = V_102 -> V_181 / V_182 ;
V_9 -> V_180 = V_102 -> V_180 ;
V_9 -> V_135 = V_102 -> V_135 ;
F_78 ( & V_237 , & V_102 -> V_76 ) ;
F_81 ( & V_9 -> V_76 , & V_237 ) ;
}
static inline int
F_188 ( struct V_2 * V_2 ,
const struct V_294 * V_295 ,
struct V_294 T_6 * V_296 )
{
int V_189 , V_297 = 0 ;
struct V_54 * V_55 ;
struct V_293 V_298 ;
int V_156 = 0 ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_140 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_184 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_297 >= V_295 -> V_185 )
goto V_67;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
F_186 ( & V_298 , V_55 ) ;
if ( F_189 ( & V_296 -> V_299 [ V_297 ] ,
& V_298 , sizeof( V_298 ) ) ) {
V_156 = - V_271 ;
goto V_67;
}
V_297 ++ ;
}
}
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_140 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_184 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_297 >= V_295 -> V_185 )
goto V_67;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
F_186 ( & V_298 , V_55 ) ;
if ( F_189 ( & V_296 -> V_299 [ V_297 ] ,
& V_298 , sizeof( V_298 ) ) ) {
V_156 = - V_271 ;
goto V_67;
}
V_297 ++ ;
}
}
V_67:
return V_156 ;
}
static inline int
F_190 ( struct V_2 * V_2 , const struct V_300 * V_295 ,
struct V_300 T_6 * V_296 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_295 -> V_4 } ;
int V_156 = 0 ;
F_58 () ;
if ( V_295 -> V_53 )
V_55 = F_39 ( V_2 , V_184 , V_295 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_184 , V_295 -> V_59 , & V_4 ,
V_295 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
int V_297 = 0 ;
struct V_74 * V_75 ;
struct V_301 V_298 ;
struct V_100 V_237 ;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
F_69 (dest, &svc->destinations, n_list) {
if ( V_297 >= V_295 -> V_135 )
break;
if ( V_75 -> V_40 != V_55 -> V_40 )
continue;
V_298 . V_4 = V_75 -> V_4 . V_46 ;
V_298 . V_43 = V_75 -> V_43 ;
V_298 . V_122 = F_15 ( & V_75 -> V_122 ) ;
V_298 . V_124 = F_15 ( & V_75 -> V_124 ) ;
V_298 . V_129 = V_75 -> V_129 ;
V_298 . V_131 = V_75 -> V_131 ;
V_298 . V_153 = F_15 ( & V_75 -> V_153 ) ;
V_298 . V_154 = F_15 ( & V_75 -> V_154 ) ;
V_298 . V_155 = F_15 ( & V_75 -> V_155 ) ;
F_78 ( & V_237 , & V_75 -> V_76 ) ;
F_81 ( & V_298 . V_76 , & V_237 ) ;
if ( F_189 ( & V_296 -> V_299 [ V_297 ] ,
& V_298 , sizeof( V_298 ) ) ) {
V_156 = - V_271 ;
break;
}
V_297 ++ ;
}
} else
V_156 = - V_287 ;
return V_156 ;
}
static inline void
F_191 ( struct V_2 * V_2 , struct V_240 * V_171 )
{
#if F_174 ( V_241 ) || F_174 ( V_242 )
struct V_243 * V_244 ;
#endif
memset ( V_171 , 0 , sizeof ( * V_171 ) ) ;
#ifdef V_241
V_244 = F_175 ( V_2 , V_68 ) ;
V_171 -> V_245 = V_244 -> V_248 [ V_249 ] / V_182 ;
V_171 -> V_246 = V_244 -> V_248 [ V_250 ] / V_182 ;
#endif
#ifdef V_242
V_244 = F_175 ( V_2 , V_251 ) ;
V_171 -> V_247 =
V_244 -> V_248 [ V_252 ] / V_182 ;
#endif
}
static int
F_192 ( struct V_258 * V_259 , int V_260 , void T_6 * V_261 , int * V_262 )
{
unsigned char V_263 [ V_302 ] ;
int V_156 = 0 ;
unsigned int V_303 ;
struct V_2 * V_2 = F_179 ( V_259 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_86 ( ! V_2 ) ;
F_180 ( sizeof( V_263 ) > 255 ) ;
if ( ! F_181 ( F_179 ( V_259 ) -> V_265 , V_266 ) )
return - V_267 ;
if ( V_260 < V_268 || V_260 > V_304 )
return - V_144 ;
V_303 = V_305 [ F_182 ( V_260 ) ] ;
if ( * V_262 < ( int ) V_303 ) {
F_103 ( 1 , L_57 , * V_262 , V_303 ) ;
return - V_144 ;
}
if ( F_183 ( V_263 , V_261 , V_303 ) != 0 )
return - V_271 ;
if ( V_260 == V_306 ) {
struct V_274 V_307 [ 2 ] ;
memset ( & V_307 , 0 , sizeof( V_307 ) ) ;
F_134 ( & V_15 -> V_276 ) ;
if ( V_15 -> V_308 & V_309 ) {
V_307 [ 0 ] . V_277 = V_309 ;
F_187 ( V_307 [ 0 ] . V_278 , V_15 -> V_310 ,
sizeof( V_307 [ 0 ] . V_278 ) ) ;
V_307 [ 0 ] . V_279 = V_15 -> V_311 ;
}
if ( V_15 -> V_308 & V_312 ) {
V_307 [ 1 ] . V_277 = V_312 ;
F_187 ( V_307 [ 1 ] . V_278 , V_15 -> V_313 ,
sizeof( V_307 [ 1 ] . V_278 ) ) ;
V_307 [ 1 ] . V_279 = V_15 -> V_314 ;
}
if ( F_189 ( V_261 , & V_307 , sizeof( V_307 ) ) != 0 )
V_156 = - V_271 ;
F_135 ( & V_15 -> V_276 ) ;
return V_156 ;
}
F_134 ( & V_193 ) ;
switch ( V_260 ) {
case V_315 :
{
char V_316 [ 64 ] ;
sprintf ( V_316 , L_58 ,
F_160 ( V_229 ) , V_230 ) ;
if ( F_189 ( V_261 , V_316 , strlen ( V_316 ) + 1 ) != 0 ) {
V_156 = - V_271 ;
goto V_67;
}
* V_262 = strlen ( V_316 ) + 1 ;
}
break;
case V_317 :
{
struct V_318 V_319 ;
V_319 . V_320 = V_229 ;
V_319 . V_321 = V_230 ;
V_319 . V_185 = V_15 -> V_185 ;
if ( F_189 ( V_261 , & V_319 , sizeof( V_319 ) ) != 0 )
V_156 = - V_271 ;
}
break;
case V_322 :
{
struct V_294 * V_295 ;
int V_321 ;
V_295 = (struct V_294 * ) V_263 ;
V_321 = sizeof( * V_295 ) +
sizeof( struct V_293 ) * V_295 -> V_185 ;
if ( * V_262 != V_321 ) {
F_28 ( L_59 , * V_262 , V_321 ) ;
V_156 = - V_144 ;
goto V_67;
}
V_156 = F_188 ( V_2 , V_295 , V_261 ) ;
}
break;
case V_323 :
{
struct V_293 * V_298 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_298 = (struct V_293 * ) V_263 ;
V_4 . V_46 = V_298 -> V_4 ;
F_58 () ;
if ( V_298 -> V_53 )
V_55 = F_39 ( V_2 , V_184 , V_298 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_184 ,
V_298 -> V_59 , & V_4 ,
V_298 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
F_186 ( V_298 , V_55 ) ;
if ( F_189 ( V_261 , V_298 , sizeof( * V_298 ) ) != 0 )
V_156 = - V_271 ;
} else
V_156 = - V_287 ;
}
break;
case V_324 :
{
struct V_300 * V_295 ;
int V_321 ;
V_295 = (struct V_300 * ) V_263 ;
V_321 = sizeof( * V_295 ) +
sizeof( struct V_301 ) * V_295 -> V_135 ;
if ( * V_262 != V_321 ) {
F_28 ( L_59 , * V_262 , V_321 ) ;
V_156 = - V_144 ;
goto V_67;
}
V_156 = F_190 ( V_2 , V_295 , V_261 ) ;
}
break;
case V_325 :
{
struct V_240 V_326 ;
F_191 ( V_2 , & V_326 ) ;
if ( F_189 ( V_261 , & V_326 , sizeof( V_326 ) ) != 0 )
V_156 = - V_271 ;
}
break;
default:
V_156 = - V_144 ;
}
V_67:
F_135 ( & V_193 ) ;
return V_156 ;
}
static int F_193 ( struct V_327 * V_328 , int V_329 ,
struct V_100 * V_237 )
{
struct V_330 * V_331 = F_194 ( V_328 , V_329 ) ;
if ( ! V_331 )
return - V_332 ;
if ( F_195 ( V_328 , V_333 , ( V_110 ) V_237 -> V_104 ) ||
F_195 ( V_328 , V_334 , ( V_110 ) V_237 -> V_105 ) ||
F_195 ( V_328 , V_335 , ( V_110 ) V_237 -> V_106 ) ||
F_196 ( V_328 , V_336 , V_237 -> V_107 ) ||
F_196 ( V_328 , V_337 , V_237 -> V_108 ) ||
F_195 ( V_328 , V_338 , ( V_110 ) V_237 -> V_111 ) ||
F_195 ( V_328 , V_339 , ( V_110 ) V_237 -> V_112 ) ||
F_195 ( V_328 , V_340 , ( V_110 ) V_237 -> V_113 ) ||
F_195 ( V_328 , V_341 , ( V_110 ) V_237 -> V_114 ) ||
F_195 ( V_328 , V_342 , ( V_110 ) V_237 -> V_115 ) )
goto V_343;
F_197 ( V_328 , V_331 ) ;
return 0 ;
V_343:
F_198 ( V_328 , V_331 ) ;
return - V_332 ;
}
static int F_199 ( struct V_327 * V_328 , int V_329 ,
struct V_100 * V_237 )
{
struct V_330 * V_331 = F_194 ( V_328 , V_329 ) ;
if ( ! V_331 )
return - V_332 ;
if ( F_196 ( V_328 , V_333 , V_237 -> V_104 ) ||
F_196 ( V_328 , V_334 , V_237 -> V_105 ) ||
F_196 ( V_328 , V_335 , V_237 -> V_106 ) ||
F_196 ( V_328 , V_336 , V_237 -> V_107 ) ||
F_196 ( V_328 , V_337 , V_237 -> V_108 ) ||
F_196 ( V_328 , V_338 , V_237 -> V_111 ) ||
F_196 ( V_328 , V_339 , V_237 -> V_112 ) ||
F_196 ( V_328 , V_340 , V_237 -> V_113 ) ||
F_196 ( V_328 , V_341 , V_237 -> V_114 ) ||
F_196 ( V_328 , V_342 , V_237 -> V_115 ) )
goto V_343;
F_197 ( V_328 , V_331 ) ;
return 0 ;
V_343:
F_198 ( V_328 , V_331 ) ;
return - V_332 ;
}
static int F_200 ( struct V_327 * V_328 ,
struct V_54 * V_55 )
{
struct V_120 * V_121 ;
struct V_173 * V_174 ;
struct V_330 * V_344 ;
struct V_345 V_12 = { . V_12 = V_55 -> V_12 ,
. V_346 = ~ 0 } ;
struct V_100 V_237 ;
char * V_175 ;
V_344 = F_194 ( V_328 , V_347 ) ;
if ( ! V_344 )
return - V_332 ;
if ( F_201 ( V_328 , V_348 , V_55 -> V_40 ) )
goto V_343;
if ( V_55 -> V_53 ) {
if ( F_195 ( V_328 , V_349 , V_55 -> V_53 ) )
goto V_343;
} else {
if ( F_201 ( V_328 , V_350 , V_55 -> V_59 ) ||
F_202 ( V_328 , V_351 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_203 ( V_328 , V_352 , V_55 -> V_43 ) )
goto V_343;
}
V_121 = F_65 ( V_55 -> V_136 , 1 ) ;
V_175 = V_121 ? V_121 -> V_195 : L_18 ;
V_174 = F_65 ( V_55 -> V_174 , 1 ) ;
if ( F_204 ( V_328 , V_353 , V_175 ) ||
( V_174 && F_204 ( V_328 , V_354 , V_174 -> V_195 ) ) ||
F_202 ( V_328 , V_355 , sizeof( V_12 ) , & V_12 ) ||
F_195 ( V_328 , V_356 , V_55 -> V_181 / V_182 ) ||
F_205 ( V_328 , V_357 , V_55 -> V_180 ) )
goto V_343;
F_78 ( & V_237 , & V_55 -> V_76 ) ;
if ( F_193 ( V_328 , V_358 , & V_237 ) )
goto V_343;
if ( F_199 ( V_328 , V_359 , & V_237 ) )
goto V_343;
F_197 ( V_328 , V_344 ) ;
return 0 ;
V_343:
F_198 ( V_328 , V_344 ) ;
return - V_332 ;
}
static int F_206 ( struct V_327 * V_328 ,
struct V_54 * V_55 ,
struct V_360 * V_361 )
{
void * V_362 ;
V_362 = F_207 ( V_328 , F_208 ( V_361 -> V_328 ) . V_363 , V_361 -> V_364 -> V_365 ,
& V_366 , V_367 ,
V_368 ) ;
if ( ! V_362 )
return - V_332 ;
if ( F_200 ( V_328 , V_55 ) < 0 )
goto V_343;
F_209 ( V_328 , V_362 ) ;
return 0 ;
V_343:
F_210 ( V_328 , V_362 ) ;
return - V_332 ;
}
static int F_211 ( struct V_327 * V_328 ,
struct V_360 * V_361 )
{
int V_189 = 0 , V_17 ;
int V_238 = V_361 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_212 ( V_328 ) ;
F_134 ( & V_193 ) ;
for ( V_17 = 0 ; V_17 < V_192 ; V_17 ++ ) {
F_140 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_189 <= V_238 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_206 ( V_328 , V_55 , V_361 ) < 0 ) {
V_189 -- ;
goto V_343;
}
}
}
for ( V_17 = 0 ; V_17 < V_192 ; V_17 ++ ) {
F_140 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_189 <= V_238 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_206 ( V_328 , V_55 , V_361 ) < 0 ) {
V_189 -- ;
goto V_343;
}
}
}
V_343:
F_135 ( & V_193 ) ;
V_361 -> args [ 0 ] = V_189 ;
return V_328 -> V_262 ;
}
static int F_213 ( struct V_2 * V_2 ,
struct V_170 * V_253 ,
struct V_330 * V_369 , int V_370 ,
struct V_54 * * V_371 )
{
struct V_330 * V_372 [ V_373 + 1 ] ;
struct V_330 * V_374 , * V_375 , * V_376 , * V_377 , * V_378 ;
struct V_54 * V_55 ;
if ( V_369 == NULL ||
F_214 ( V_372 , V_373 , V_369 , V_379 ) )
return - V_144 ;
V_374 = V_372 [ V_348 ] ;
V_377 = V_372 [ V_350 ] ;
V_378 = V_372 [ V_351 ] ;
V_375 = V_372 [ V_352 ] ;
V_376 = V_372 [ V_349 ] ;
if ( ! ( V_374 && ( V_376 || ( V_375 && V_377 && V_378 ) ) ) )
return - V_144 ;
memset ( V_253 , 0 , sizeof( * V_253 ) ) ;
V_253 -> V_40 = F_215 ( V_374 ) ;
#ifdef F_24
if ( V_253 -> V_40 != V_184 && V_253 -> V_40 != V_48 )
#else
if ( V_253 -> V_40 != V_184 )
#endif
return - V_380 ;
if ( V_376 ) {
V_253 -> V_59 = V_68 ;
V_253 -> V_53 = F_216 ( V_376 ) ;
} else {
V_253 -> V_59 = F_215 ( V_377 ) ;
F_217 ( & V_253 -> V_4 , V_378 , sizeof( V_253 -> V_4 ) ) ;
V_253 -> V_43 = F_218 ( V_375 ) ;
V_253 -> V_53 = 0 ;
}
F_58 () ;
if ( V_253 -> V_53 )
V_55 = F_39 ( V_2 , V_253 -> V_40 , V_253 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_253 -> V_40 , V_253 -> V_59 ,
& V_253 -> V_4 , V_253 -> V_43 ) ;
F_59 () ;
* V_371 = V_55 ;
if ( V_370 ) {
struct V_330 * V_381 , * V_382 , * V_383 , * V_384 ,
* V_385 ;
struct V_345 V_12 ;
V_381 = V_372 [ V_353 ] ;
V_383 = V_372 [ V_354 ] ;
V_382 = V_372 [ V_355 ] ;
V_384 = V_372 [ V_356 ] ;
V_385 = V_372 [ V_357 ] ;
if ( ! ( V_381 && V_382 && V_384 && V_385 ) )
return - V_144 ;
F_217 ( & V_12 , V_382 , sizeof( V_12 ) ) ;
if ( V_55 )
V_253 -> V_12 = V_55 -> V_12 ;
V_253 -> V_12 = ( V_253 -> V_12 & ~ V_12 . V_346 ) |
( V_12 . V_12 & V_12 . V_346 ) ;
V_253 -> V_175 = F_219 ( V_381 ) ;
V_253 -> V_177 = V_383 ? F_219 ( V_383 ) : NULL ;
V_253 -> V_181 = F_216 ( V_384 ) ;
V_253 -> V_180 = F_220 ( V_385 ) ;
}
return 0 ;
}
static struct V_54 * F_221 ( struct V_2 * V_2 ,
struct V_330 * V_369 )
{
struct V_170 V_253 ;
struct V_54 * V_55 ;
int V_156 ;
V_156 = F_213 ( V_2 , & V_253 , V_369 , 0 , & V_55 ) ;
return V_156 ? F_222 ( V_156 ) : V_55 ;
}
static int F_223 ( struct V_327 * V_328 , struct V_74 * V_75 )
{
struct V_330 * V_386 ;
struct V_100 V_237 ;
V_386 = F_194 ( V_328 , V_387 ) ;
if ( ! V_386 )
return - V_332 ;
if ( F_202 ( V_328 , V_388 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_203 ( V_328 , V_389 , V_75 -> V_43 ) ||
F_195 ( V_328 , V_390 ,
( F_15 ( & V_75 -> V_122 ) &
V_90 ) ) ||
F_195 ( V_328 , V_391 ,
F_15 ( & V_75 -> V_124 ) ) ||
F_195 ( V_328 , V_392 , V_75 -> V_129 ) ||
F_195 ( V_328 , V_393 , V_75 -> V_131 ) ||
F_195 ( V_328 , V_394 ,
F_15 ( & V_75 -> V_153 ) ) ||
F_195 ( V_328 , V_395 ,
F_15 ( & V_75 -> V_154 ) ) ||
F_195 ( V_328 , V_396 ,
F_15 ( & V_75 -> V_155 ) ) ||
F_201 ( V_328 , V_397 , V_75 -> V_40 ) )
goto V_343;
F_78 ( & V_237 , & V_75 -> V_76 ) ;
if ( F_193 ( V_328 , V_398 , & V_237 ) )
goto V_343;
if ( F_199 ( V_328 , V_399 , & V_237 ) )
goto V_343;
F_197 ( V_328 , V_386 ) ;
return 0 ;
V_343:
F_198 ( V_328 , V_386 ) ;
return - V_332 ;
}
static int F_224 ( struct V_327 * V_328 , struct V_74 * V_75 ,
struct V_360 * V_361 )
{
void * V_362 ;
V_362 = F_207 ( V_328 , F_208 ( V_361 -> V_328 ) . V_363 , V_361 -> V_364 -> V_365 ,
& V_366 , V_367 ,
V_400 ) ;
if ( ! V_362 )
return - V_332 ;
if ( F_223 ( V_328 , V_75 ) < 0 )
goto V_343;
F_209 ( V_328 , V_362 ) ;
return 0 ;
V_343:
F_210 ( V_328 , V_362 ) ;
return - V_332 ;
}
static int F_225 ( struct V_327 * V_328 ,
struct V_360 * V_361 )
{
int V_189 = 0 ;
int V_238 = V_361 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_330 * V_372 [ V_401 + 1 ] ;
struct V_2 * V_2 = F_212 ( V_328 ) ;
F_134 ( & V_193 ) ;
if ( F_226 ( V_361 -> V_364 , V_402 , V_372 ,
V_401 , V_403 ) )
goto V_176;
V_55 = F_221 ( V_2 , V_372 [ V_347 ] ) ;
if ( F_227 ( V_55 ) || V_55 == NULL )
goto V_176;
F_69 (dest, &svc->destinations, n_list) {
if ( ++ V_189 <= V_238 )
continue;
if ( F_224 ( V_328 , V_75 , V_361 ) < 0 ) {
V_189 -- ;
goto V_343;
}
}
V_343:
V_361 -> args [ 0 ] = V_189 ;
V_176:
F_135 ( & V_193 ) ;
return V_328 -> V_262 ;
}
static int F_228 ( struct V_116 * V_117 ,
struct V_330 * V_369 , int V_370 )
{
struct V_330 * V_372 [ V_404 + 1 ] ;
struct V_330 * V_378 , * V_375 ;
struct V_330 * V_405 ;
if ( V_369 == NULL ||
F_214 ( V_372 , V_404 , V_369 , V_406 ) )
return - V_144 ;
V_378 = V_372 [ V_388 ] ;
V_375 = V_372 [ V_389 ] ;
V_405 = V_372 [ V_397 ] ;
if ( ! ( V_378 && V_375 ) )
return - V_144 ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
F_217 ( & V_117 -> V_4 , V_378 , sizeof( V_117 -> V_4 ) ) ;
V_117 -> V_43 = F_218 ( V_375 ) ;
if ( V_405 )
V_117 -> V_40 = F_215 ( V_405 ) ;
else
V_117 -> V_40 = 0 ;
if ( V_370 ) {
struct V_330 * V_407 , * V_408 , * V_409 ,
* V_410 ;
V_407 = V_372 [ V_390 ] ;
V_408 = V_372 [ V_391 ] ;
V_409 = V_372 [ V_392 ] ;
V_410 = V_372 [ V_393 ] ;
if ( ! ( V_407 && V_408 && V_409 && V_410 ) )
return - V_144 ;
V_117 -> V_122 = F_216 ( V_407 )
& V_90 ;
V_117 -> V_124 = F_216 ( V_408 ) ;
V_117 -> V_129 = F_216 ( V_409 ) ;
V_117 -> V_131 = F_216 ( V_410 ) ;
}
return 0 ;
}
static int F_229 ( struct V_327 * V_328 , T_3 V_277 ,
const char * V_278 , T_3 V_279 )
{
struct V_330 * V_411 ;
V_411 = F_194 ( V_328 , V_412 ) ;
if ( ! V_411 )
return - V_332 ;
if ( F_195 ( V_328 , V_413 , V_277 ) ||
F_204 ( V_328 , V_414 , V_278 ) ||
F_195 ( V_328 , V_415 , V_279 ) )
goto V_343;
F_197 ( V_328 , V_411 ) ;
return 0 ;
V_343:
F_198 ( V_328 , V_411 ) ;
return - V_332 ;
}
static int F_230 ( struct V_327 * V_328 , T_3 V_277 ,
const char * V_278 , T_3 V_279 ,
struct V_360 * V_361 )
{
void * V_362 ;
V_362 = F_207 ( V_328 , F_208 ( V_361 -> V_328 ) . V_363 , V_361 -> V_364 -> V_365 ,
& V_366 , V_367 ,
V_416 ) ;
if ( ! V_362 )
return - V_332 ;
if ( F_229 ( V_328 , V_277 , V_278 , V_279 ) )
goto V_343;
F_209 ( V_328 , V_362 ) ;
return 0 ;
V_343:
F_210 ( V_328 , V_362 ) ;
return - V_332 ;
}
static int F_231 ( struct V_327 * V_328 ,
struct V_360 * V_361 )
{
struct V_2 * V_2 = F_212 ( V_328 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_134 ( & V_15 -> V_276 ) ;
if ( ( V_15 -> V_308 & V_309 ) && ! V_361 -> args [ 0 ] ) {
if ( F_230 ( V_328 , V_309 ,
V_15 -> V_310 ,
V_15 -> V_311 , V_361 ) < 0 )
goto V_343;
V_361 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_308 & V_312 ) && ! V_361 -> args [ 1 ] ) {
if ( F_230 ( V_328 , V_312 ,
V_15 -> V_313 ,
V_15 -> V_314 , V_361 ) < 0 )
goto V_343;
V_361 -> args [ 1 ] = 1 ;
}
V_343:
F_135 ( & V_15 -> V_276 ) ;
return V_328 -> V_262 ;
}
static int F_232 ( struct V_2 * V_2 , struct V_330 * * V_372 )
{
if ( ! ( V_372 [ V_413 ] &&
V_372 [ V_414 ] &&
V_372 [ V_415 ] ) )
return - V_144 ;
if ( F_41 ( V_2 ) -> V_123 > 0 )
return - V_144 ;
return F_184 ( V_2 ,
F_216 ( V_372 [ V_413 ] ) ,
F_219 ( V_372 [ V_414 ] ) ,
F_216 ( V_372 [ V_415 ] ) ) ;
}
static int F_233 ( struct V_2 * V_2 , struct V_330 * * V_372 )
{
if ( ! V_372 [ V_413 ] )
return - V_144 ;
return F_185 ( V_2 ,
F_216 ( V_372 [ V_413 ] ) ) ;
}
static int F_234 ( struct V_2 * V_2 , struct V_330 * * V_372 )
{
struct V_240 V_326 ;
F_191 ( V_2 , & V_326 ) ;
if ( V_372 [ V_417 ] )
V_326 . V_245 = F_216 ( V_372 [ V_417 ] ) ;
if ( V_372 [ V_418 ] )
V_326 . V_246 =
F_216 ( V_372 [ V_418 ] ) ;
if ( V_372 [ V_419 ] )
V_326 . V_247 = F_216 ( V_372 [ V_419 ] ) ;
return F_173 ( V_2 , & V_326 ) ;
}
static int F_235 ( struct V_327 * V_328 , struct V_420 * V_319 )
{
int V_156 = 0 , V_260 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_212 ( V_328 ) ;
V_15 = F_41 ( V_2 ) ;
V_260 = V_319 -> V_421 -> V_260 ;
if ( V_260 == V_416 || V_260 == V_422 ) {
struct V_330 * V_423 [ V_424 + 1 ] ;
F_134 ( & V_15 -> V_276 ) ;
if ( ! V_319 -> V_372 [ V_412 ] ||
F_214 ( V_423 , V_424 ,
V_319 -> V_372 [ V_412 ] ,
V_425 ) ) {
V_156 = - V_144 ;
goto V_67;
}
if ( V_260 == V_416 )
V_156 = F_232 ( V_2 , V_423 ) ;
else
V_156 = F_233 ( V_2 , V_423 ) ;
V_67:
F_135 ( & V_15 -> V_276 ) ;
}
return V_156 ;
}
static int F_236 ( struct V_327 * V_328 , struct V_420 * V_319 )
{
struct V_54 * V_55 = NULL ;
struct V_170 V_253 ;
struct V_116 V_117 ;
int V_156 = 0 , V_260 ;
int V_426 = 0 , V_427 = 0 ;
struct V_2 * V_2 ;
V_2 = F_212 ( V_328 ) ;
V_260 = V_319 -> V_421 -> V_260 ;
F_134 ( & V_193 ) ;
if ( V_260 == V_428 ) {
V_156 = F_131 ( V_2 , false ) ;
goto V_67;
} else if ( V_260 == V_429 ) {
V_156 = F_234 ( V_2 , V_319 -> V_372 ) ;
goto V_67;
} else if ( V_260 == V_430 &&
! V_319 -> V_372 [ V_347 ] ) {
V_156 = F_142 ( V_2 ) ;
goto V_67;
}
if ( V_260 == V_368 || V_260 == V_431 )
V_426 = 1 ;
V_156 = F_213 ( V_2 , & V_253 ,
V_319 -> V_372 [ V_347 ] ,
V_426 , & V_55 ) ;
if ( V_156 )
goto V_67;
if ( ( V_260 != V_368 ) && ( V_55 == NULL ) ) {
V_156 = - V_287 ;
goto V_67;
}
if ( V_260 == V_400 || V_260 == V_432 ||
V_260 == V_433 ) {
if ( V_260 != V_433 )
V_427 = 1 ;
V_156 = F_228 ( & V_117 ,
V_319 -> V_372 [ V_387 ] ,
V_427 ) ;
if ( V_156 )
goto V_67;
if ( V_117 . V_40 == 0 )
V_117 . V_40 = V_55 -> V_40 ;
if ( V_117 . V_40 != V_55 -> V_40 && V_260 != V_433 ) {
if ( F_41 ( V_2 ) -> V_308 ) {
V_156 = - V_144 ;
goto V_67;
}
switch ( V_117 . V_122 ) {
case V_216 :
break;
default:
V_156 = - V_144 ;
goto V_67;
}
}
}
switch ( V_260 ) {
case V_368 :
if ( V_55 == NULL )
V_156 = F_117 ( V_2 , & V_253 , & V_55 ) ;
else
V_156 = - V_158 ;
break;
case V_431 :
V_156 = F_126 ( V_55 , & V_253 ) ;
break;
case V_434 :
V_156 = F_130 ( V_55 ) ;
break;
case V_400 :
V_156 = F_102 ( V_55 , & V_117 ) ;
break;
case V_432 :
V_156 = F_104 ( V_55 , & V_117 ) ;
break;
case V_433 :
V_156 = F_113 ( V_55 , & V_117 ) ;
break;
case V_430 :
V_156 = F_141 ( V_55 ) ;
break;
default:
V_156 = - V_144 ;
}
V_67:
F_135 ( & V_193 ) ;
return V_156 ;
}
static int F_237 ( struct V_327 * V_328 , struct V_420 * V_319 )
{
struct V_327 * V_435 ;
void * V_436 ;
int V_156 , V_260 , V_437 ;
struct V_2 * V_2 ;
V_2 = F_212 ( V_328 ) ;
V_260 = V_319 -> V_421 -> V_260 ;
if ( V_260 == V_438 )
V_437 = V_368 ;
else if ( V_260 == V_439 )
V_437 = V_440 ;
else if ( V_260 == V_441 )
V_437 = V_429 ;
else {
F_28 ( L_60 ) ;
return - V_144 ;
}
V_435 = F_238 ( V_442 , V_147 ) ;
if ( ! V_435 )
return - V_148 ;
F_134 ( & V_193 ) ;
V_436 = F_239 ( V_435 , V_319 , & V_366 , 0 , V_437 ) ;
if ( V_436 == NULL )
goto V_343;
switch ( V_260 ) {
case V_438 :
{
struct V_54 * V_55 ;
V_55 = F_221 ( V_2 ,
V_319 -> V_372 [ V_347 ] ) ;
if ( F_227 ( V_55 ) ) {
V_156 = F_240 ( V_55 ) ;
goto V_176;
} else if ( V_55 ) {
V_156 = F_200 ( V_435 , V_55 ) ;
if ( V_156 )
goto V_343;
} else {
V_156 = - V_287 ;
goto V_176;
}
break;
}
case V_441 :
{
struct V_240 V_326 ;
F_191 ( V_2 , & V_326 ) ;
#ifdef V_241
if ( F_195 ( V_435 , V_417 ,
V_326 . V_245 ) ||
F_195 ( V_435 , V_418 ,
V_326 . V_246 ) )
goto V_343;
#endif
#ifdef V_242
if ( F_195 ( V_435 , V_419 , V_326 . V_247 ) )
goto V_343;
#endif
break;
}
case V_439 :
if ( F_195 ( V_435 , V_443 ,
V_229 ) ||
F_195 ( V_435 , V_444 ,
V_230 ) )
goto V_343;
break;
}
F_209 ( V_435 , V_436 ) ;
V_156 = F_241 ( V_435 , V_319 ) ;
goto V_67;
V_343:
F_28 ( L_61 ) ;
V_156 = - V_332 ;
V_176:
F_242 ( V_435 ) ;
V_67:
F_135 ( & V_193 ) ;
return V_156 ;
}
static int T_11 F_243 ( void )
{
return F_244 ( & V_366 ,
V_445 ) ;
}
static void F_245 ( void )
{
F_246 ( & V_366 ) ;
}
static int T_12 F_247 ( struct V_2 * V_2 )
{
int V_189 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_203 * V_446 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_100 ( & V_15 -> V_25 ) ;
F_100 ( & V_15 -> V_28 ) ;
F_100 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_447 ) ) {
V_446 = F_248 ( V_448 , sizeof( V_448 ) , V_147 ) ;
if ( V_446 == NULL )
return - V_148 ;
if ( V_2 -> V_265 != & V_449 )
V_446 [ 0 ] . V_450 = NULL ;
} else
V_446 = V_448 ;
V_189 = 0 ;
V_15 -> V_24 = 1024 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_32 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_26 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_29 ;
#ifdef F_249
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_451 ;
#endif
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_34 ;
V_15 -> V_452 = 1 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_452 ;
V_15 -> V_453 = 1 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_453 ;
V_15 -> V_454 = 1 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_454 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_455 ;
V_15 -> V_456 = F_250 () / 32 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_456 ;
V_15 -> V_457 = 0 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_457 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_458 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_459 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_460 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_461 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_462 ;
V_15 -> V_463 [ 0 ] = V_464 ;
V_15 -> V_463 [ 1 ] = V_465 ;
V_446 [ V_189 ] . V_167 = & V_15 -> V_463 ;
V_446 [ V_189 ++ ] . V_466 = sizeof( V_15 -> V_463 ) ;
V_15 -> V_467 = V_468 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_467 ;
V_15 -> V_469 = F_251 ( int , V_470 , 0 , 3 ) ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_469 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_471 ;
V_15 -> V_472 = 1 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_472 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_473 ;
V_15 -> V_474 = 1 ;
V_446 [ V_189 ++ ] . V_167 = & V_15 -> V_474 ;
V_15 -> V_475 = F_252 ( V_2 , L_62 , V_446 ) ;
if ( V_15 -> V_475 == NULL ) {
if ( ! F_38 ( V_2 , & V_447 ) )
F_49 ( V_446 ) ;
return - V_148 ;
}
F_87 ( V_2 , & V_15 -> V_202 ) ;
V_15 -> V_476 = V_446 ;
F_253 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_254 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_255 ( & V_15 -> V_37 ) ;
F_256 ( & V_15 -> V_37 . V_36 ) ;
F_257 ( V_15 -> V_475 ) ;
F_106 ( V_2 , & V_15 -> V_202 ) ;
if ( ! F_38 ( V_2 , & V_447 ) )
F_49 ( V_15 -> V_476 ) ;
}
static int T_12 F_247 ( struct V_2 * V_2 ) { return 0 ; }
static void T_13 F_254 ( struct V_2 * V_2 ) { }
int T_12 F_258 ( struct V_2 * V_2 )
{
int V_17 , V_189 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
for ( V_189 = 0 ; V_189 < V_477 ; V_189 ++ )
F_259 ( & V_15 -> V_85 [ V_189 ] ) ;
F_121 ( & V_15 -> V_161 ) ;
F_100 ( & V_15 -> V_96 ) ;
F_260 ( & V_15 -> V_99 , F_114 ,
( unsigned long ) V_2 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_202 . V_77 = F_94 ( struct V_149 ) ;
if ( ! V_15 -> V_202 . V_77 )
return - V_148 ;
F_95 (i) {
struct V_149 * V_478 ;
V_478 = F_96 ( V_15 -> V_202 . V_77 , V_17 ) ;
F_97 ( & V_478 -> V_152 ) ;
}
F_100 ( & V_15 -> V_202 . V_103 ) ;
F_261 ( L_63 , 0 , V_2 -> V_479 , & V_480 ) ;
F_261 ( L_64 , 0 , V_2 -> V_479 , & V_481 ) ;
F_261 ( L_65 , 0 , V_2 -> V_479 ,
& V_482 ) ;
if ( F_247 ( V_2 ) )
goto V_483;
return 0 ;
V_483:
F_48 ( V_15 -> V_202 . V_77 ) ;
return - V_148 ;
}
void T_13 F_262 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_75 ( V_2 ) ;
F_254 ( V_2 ) ;
F_263 ( L_65 , V_2 -> V_479 ) ;
F_263 ( L_64 , V_2 -> V_479 ) ;
F_263 ( L_63 , V_2 -> V_479 ) ;
F_48 ( V_15 -> V_202 . V_77 ) ;
}
int T_11 F_264 ( void )
{
int V_156 ;
V_156 = F_265 ( & V_484 ) ;
if ( V_156 ) {
F_28 ( L_66 ) ;
goto V_485;
}
V_156 = F_243 () ;
if ( V_156 ) {
F_28 ( L_67 ) ;
goto V_486;
}
return 0 ;
V_486:
F_266 ( & V_484 ) ;
V_485:
return V_156 ;
}
void F_267 ( void )
{
F_245 () ;
F_266 ( & V_484 ) ;
}
int T_11 F_268 ( void )
{
int V_189 ;
int V_156 ;
F_90 ( 2 ) ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_259 ( & V_61 [ V_189 ] ) ;
F_259 ( & V_63 [ V_189 ] ) ;
}
F_269 () ;
V_156 = F_270 ( & V_487 ) ;
if ( V_156 < 0 )
return V_156 ;
F_101 ( 2 ) ;
return 0 ;
}
void F_271 ( void )
{
F_90 ( 2 ) ;
F_272 ( & V_487 ) ;
F_101 ( 2 ) ;
}
