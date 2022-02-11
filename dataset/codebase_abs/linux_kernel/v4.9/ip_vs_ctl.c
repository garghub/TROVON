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
F_16 ( V_15 ) ;
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
F_22 ( struct V_14 * V_15 , int V_40 , unsigned int V_41 ,
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
V_47 ^= ( ( V_50 ) V_15 >> 8 ) ;
return ( V_41 ^ V_47 ^ ( V_44 >> V_51 ) ^ V_44 ) &
V_52 ;
}
static inline unsigned int F_26 ( struct V_14 * V_15 , T_3 V_53 )
{
return ( ( ( V_50 ) V_15 >> 8 ) ^ V_53 ) & V_52 ;
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
V_56 = F_22 ( V_55 -> V_15 , V_55 -> V_40 , V_55 -> V_59 ,
& V_55 -> V_4 , V_55 -> V_43 ) ;
F_30 ( & V_55 -> V_60 , & V_61 [ V_56 ] ) ;
} else {
V_56 = F_26 ( V_55 -> V_15 , V_55 -> V_53 ) ;
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
F_35 ( struct V_14 * V_15 , int V_40 , T_4 V_59 ,
const union V_42 * V_65 , T_1 V_66 )
{
unsigned int V_56 ;
struct V_54 * V_55 ;
V_56 = F_22 ( V_15 , V_40 , V_59 , V_65 , V_66 ) ;
F_36 (svc, &ip_vs_svc_table[hash], s_list) {
if ( ( V_55 -> V_40 == V_40 )
&& F_37 ( V_40 , & V_55 -> V_4 , V_65 )
&& ( V_55 -> V_43 == V_66 )
&& ( V_55 -> V_59 == V_59 )
&& ( V_55 -> V_15 == V_15 ) ) {
return V_55 ;
}
}
return NULL ;
}
static inline struct V_54 *
F_38 ( struct V_14 * V_15 , int V_40 , T_3 V_53 )
{
unsigned int V_56 ;
struct V_54 * V_55 ;
V_56 = F_26 ( V_15 , V_53 ) ;
F_36 (svc, &ip_vs_svc_fwm_table[hash], f_list) {
if ( V_55 -> V_53 == V_53 && V_55 -> V_40 == V_40
&& ( V_55 -> V_15 == V_15 ) ) {
return V_55 ;
}
}
return NULL ;
}
struct V_54 *
F_39 ( struct V_14 * V_15 , int V_40 , T_3 V_53 , T_4 V_59 ,
const union V_42 * V_65 , T_1 V_66 )
{
struct V_54 * V_55 ;
if ( V_53 ) {
V_55 = F_38 ( V_15 , V_40 , V_53 ) ;
if ( V_55 )
goto V_67;
}
V_55 = F_35 ( V_15 , V_40 , V_59 , V_65 , V_66 ) ;
if ( V_55 == NULL
&& V_59 == V_68
&& F_15 ( & V_15 -> V_69 )
&& ( V_66 == V_70 || F_23 ( V_66 ) >= V_71 ) ) {
V_55 = F_35 ( V_15 , V_40 , V_59 , V_65 , V_72 ) ;
}
if ( V_55 == NULL
&& F_15 ( & V_15 -> V_73 ) ) {
V_55 = F_35 ( V_15 , V_40 , V_59 , V_65 , 0 ) ;
}
V_67:
F_40 ( 9 , L_3 ,
V_53 , F_41 ( V_59 ) ,
F_42 ( V_40 , V_65 ) , F_23 ( V_66 ) ,
V_55 ? L_4 : L_5 ) ;
return V_55 ;
}
static inline void
F_43 ( struct V_74 * V_75 , struct V_54 * V_55 )
{
F_31 ( & V_55 -> V_64 ) ;
F_44 ( V_75 -> V_55 , V_55 ) ;
}
static void F_45 ( struct V_54 * V_55 )
{
F_46 ( V_55 -> V_76 . V_77 ) ;
F_47 ( V_55 ) ;
}
static void F_48 ( struct V_78 * V_79 )
{
struct V_54 * V_55 ;
V_55 = F_14 ( V_79 , struct V_54 , V_78 ) ;
F_45 ( V_55 ) ;
}
static void F_49 ( struct V_54 * V_55 , bool V_80 )
{
if ( F_50 ( & V_55 -> V_64 ) ) {
F_40 ( 3 , L_6 ,
V_55 -> V_53 ,
F_42 ( V_55 -> V_40 , & V_55 -> V_4 ) ,
F_23 ( V_55 -> V_43 ) ) ;
if ( V_80 )
F_51 ( & V_55 -> V_78 , F_48 ) ;
else
F_45 ( V_55 ) ;
}
}
static inline unsigned int F_52 ( int V_40 ,
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
static void F_53 ( struct V_14 * V_15 , struct V_74 * V_75 )
{
unsigned int V_56 ;
if ( V_75 -> V_83 )
return;
V_56 = F_52 ( V_75 -> V_40 , & V_75 -> V_4 , V_75 -> V_43 ) ;
F_30 ( & V_75 -> V_84 , & V_15 -> V_85 [ V_56 ] ) ;
V_75 -> V_83 = 1 ;
}
static void F_54 ( struct V_74 * V_75 )
{
if ( V_75 -> V_83 ) {
F_33 ( & V_75 -> V_84 ) ;
V_75 -> V_83 = 0 ;
}
}
bool F_55 ( struct V_14 * V_15 , int V_40 , T_4 V_59 ,
const union V_42 * V_7 , T_1 V_86 )
{
unsigned int V_56 ;
struct V_74 * V_75 ;
V_56 = F_52 ( V_40 , V_7 , V_86 ) ;
F_56 () ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( V_75 -> V_43 == V_86 &&
V_75 -> V_40 == V_40 &&
F_37 ( V_40 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_59 == V_59 || V_75 -> V_87 ) ) {
F_57 () ;
return true ;
}
}
F_57 () ;
return false ;
}
struct V_74 * F_58 ( struct V_14 * V_15 , int V_40 ,
T_4 V_59 ,
const union V_42 * V_7 ,
T_1 V_86 )
{
unsigned int V_56 ;
struct V_74 * V_75 ;
V_56 = F_52 ( V_40 , V_7 , V_86 ) ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( V_75 -> V_43 == V_86 &&
V_75 -> V_40 == V_40 &&
F_37 ( V_40 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_59 == V_59 || V_75 -> V_87 ) ) {
return V_75 ;
}
}
return NULL ;
}
static struct V_74 *
F_59 ( struct V_54 * V_55 , int V_88 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_74 * V_75 ;
F_60 (dest, &svc->destinations, n_list) {
if ( ( V_75 -> V_40 == V_88 ) &&
F_37 ( V_88 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_43 == V_86 ) ) {
return V_75 ;
}
}
return NULL ;
}
struct V_74 * F_61 ( struct V_14 * V_15 , int V_89 , int V_88 ,
const union V_42 * V_7 ,
T_1 V_86 ,
const union V_42 * V_65 ,
T_1 V_66 , T_4 V_59 , T_3 V_53 ,
T_3 V_12 )
{
struct V_74 * V_75 ;
struct V_54 * V_55 ;
T_1 V_43 = V_86 ;
V_55 = F_39 ( V_15 , V_89 , V_53 , V_59 , V_65 , V_66 ) ;
if ( ! V_55 )
return NULL ;
if ( V_53 && ( V_12 & V_90 ) != V_91 )
V_43 = 0 ;
V_75 = F_59 ( V_55 , V_88 , V_7 , V_43 ) ;
if ( ! V_75 )
V_75 = F_59 ( V_55 , V_88 , V_7 , V_43 ^ V_86 ) ;
return V_75 ;
}
void F_62 ( struct V_78 * V_79 )
{
struct V_92 * V_93 = F_14 ( V_79 ,
struct V_92 ,
V_78 ) ;
F_4 ( V_93 -> V_94 ) ;
F_47 ( V_93 ) ;
}
static void F_63 ( struct V_74 * V_75 )
{
struct V_92 * V_95 ;
V_95 = F_64 ( V_75 -> V_93 , 1 ) ;
if ( V_95 ) {
F_65 ( V_75 -> V_93 , NULL ) ;
F_51 ( & V_95 -> V_78 , F_62 ) ;
}
}
static struct V_74 *
F_66 ( struct V_54 * V_55 , int V_88 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_74 * V_75 ;
struct V_14 * V_15 = V_55 -> V_15 ;
F_67 ( & V_15 -> V_96 ) ;
F_68 (dest, &ipvs->dest_trash, t_list) {
F_40 ( 3 , L_7
L_8 ,
V_75 -> V_87 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
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
F_69 ( & V_75 -> V_97 ) ;
F_70 ( V_75 ) ;
goto V_67;
}
}
V_75 = NULL ;
V_67:
F_71 ( & V_15 -> V_96 ) ;
return V_75 ;
}
static void F_72 ( struct V_74 * V_75 )
{
struct V_54 * V_55 = F_64 ( V_75 -> V_55 , 1 ) ;
F_63 ( V_75 ) ;
F_49 ( V_55 , false ) ;
F_46 ( V_75 -> V_76 . V_77 ) ;
F_73 ( V_75 ) ;
}
static void F_74 ( struct V_14 * V_15 )
{
struct V_74 * V_75 , * V_98 ;
F_75 ( & V_15 -> V_99 ) ;
F_76 (dest, nxt, &ipvs->dest_trash, t_list) {
F_69 ( & V_75 -> V_97 ) ;
F_72 ( V_75 ) ;
}
}
static void
F_77 ( struct V_100 * V_9 , struct V_101 * V_102 )
{
#define F_78 ( T_5 ) dst->c = src->kstats.c - src->kstats0.c
F_67 ( & V_102 -> V_103 ) ;
F_78 ( V_104 ) ;
F_78 ( V_105 ) ;
F_78 ( V_106 ) ;
F_78 ( V_107 ) ;
F_78 ( V_108 ) ;
F_79 ( V_9 , V_102 ) ;
F_71 ( & V_102 -> V_103 ) ;
}
static void
F_80 ( struct V_109 * V_9 , struct V_100 * V_102 )
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
F_81 ( struct V_101 * V_76 )
{
F_67 ( & V_76 -> V_103 ) ;
#define F_82 ( T_5 ) stats->kstats0.c = stats->kstats.c
F_82 ( V_104 ) ;
F_82 ( V_105 ) ;
F_82 ( V_106 ) ;
F_82 ( V_107 ) ;
F_82 ( V_108 ) ;
F_83 ( V_76 ) ;
F_71 ( & V_76 -> V_103 ) ;
}
static void
F_84 ( struct V_54 * V_55 , struct V_74 * V_75 ,
struct V_116 * V_117 , int V_118 )
{
struct V_14 * V_15 = V_55 -> V_15 ;
struct V_54 * V_119 ;
struct V_120 * V_121 ;
int V_122 ;
F_85 ( ! V_118 && V_117 -> V_40 != V_75 -> V_40 ) ;
if ( V_118 && V_117 -> V_40 != V_55 -> V_40 )
V_15 -> V_123 ++ ;
F_9 ( & V_75 -> V_124 , V_117 -> V_124 ) ;
V_122 = V_117 -> V_122 & V_125 ;
V_122 |= V_126 ;
if ( ( V_122 & V_90 ) != V_91 ) {
V_122 |= V_127 ;
} else {
F_53 ( V_15 , V_75 ) ;
}
F_9 ( & V_75 -> V_122 , V_122 ) ;
V_119 = F_64 ( V_75 -> V_55 , 1 ) ;
if ( ! V_119 ) {
F_43 ( V_75 , V_55 ) ;
} else {
if ( V_119 != V_55 ) {
F_81 ( & V_75 -> V_76 ) ;
F_43 ( V_75 , V_55 ) ;
F_49 ( V_119 , true ) ;
}
}
V_75 -> V_12 |= V_128 ;
if ( V_117 -> V_129 == 0 || V_117 -> V_129 > V_75 -> V_129 )
V_75 -> V_12 &= ~ V_130 ;
V_75 -> V_129 = V_117 -> V_129 ;
V_75 -> V_131 = V_117 -> V_131 ;
V_75 -> V_40 = V_117 -> V_40 ;
F_67 ( & V_75 -> V_132 ) ;
F_63 ( V_75 ) ;
F_71 ( & V_75 -> V_132 ) ;
if ( V_118 ) {
F_86 ( V_55 -> V_15 , & V_75 -> V_76 ) ;
F_87 ( & V_75 -> V_133 , & V_55 -> V_134 ) ;
V_55 -> V_135 ++ ;
V_121 = F_64 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_137 )
V_121 -> V_137 ( V_55 , V_75 ) ;
} else {
V_121 = F_64 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_138 )
V_121 -> V_138 ( V_55 , V_75 ) ;
}
}
static int
F_88 ( struct V_54 * V_55 , struct V_116 * V_117 ,
struct V_74 * * V_139 )
{
struct V_74 * V_75 ;
unsigned int V_140 , V_17 ;
F_89 ( 2 ) ;
#ifdef F_24
if ( V_117 -> V_40 == V_48 ) {
V_140 = F_90 ( & V_117 -> V_4 . V_141 ) ;
if ( ( ! ( V_140 & V_142 ) ||
V_140 & V_143 ) &&
! F_2 ( V_55 -> V_15 -> V_2 , & V_117 -> V_4 . V_141 ) )
return - V_144 ;
} else
#endif
{
V_140 = F_91 ( V_55 -> V_15 -> V_2 , V_117 -> V_4 . V_46 ) ;
if ( V_140 != V_145 && V_140 != V_146 )
return - V_144 ;
}
V_75 = F_92 ( sizeof( struct V_74 ) , V_147 ) ;
if ( V_75 == NULL )
return - V_148 ;
V_75 -> V_76 . V_77 = F_93 ( struct V_149 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_150;
F_94 (i) {
struct V_149 * V_151 ;
V_151 = F_95 ( V_75 -> V_76 . V_77 , V_17 ) ;
F_96 ( & V_151 -> V_152 ) ;
}
V_75 -> V_40 = V_117 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_87 = V_55 -> V_53 ;
F_97 ( V_117 -> V_40 , & V_75 -> V_4 , & V_117 -> V_4 ) ;
V_75 -> V_43 = V_117 -> V_43 ;
F_9 ( & V_75 -> V_153 , 0 ) ;
F_9 ( & V_75 -> V_154 , 0 ) ;
F_9 ( & V_75 -> V_155 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_98 ( & V_75 -> V_84 ) ;
F_99 ( & V_75 -> V_132 ) ;
F_99 ( & V_75 -> V_76 . V_103 ) ;
F_84 ( V_55 , V_75 , V_117 , 1 ) ;
* V_139 = V_75 ;
F_100 ( 2 ) ;
return 0 ;
V_150:
F_47 ( V_75 ) ;
return - V_148 ;
}
static int
F_101 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_117 -> V_43 ;
int V_156 ;
F_89 ( 2 ) ;
if ( V_117 -> V_124 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_157 ;
}
if ( V_117 -> V_131 > V_117 -> V_129 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_157 ;
}
F_97 ( V_117 -> V_40 , & V_7 , & V_117 -> V_4 ) ;
F_56 () ;
V_75 = F_59 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
F_57 () ;
if ( V_75 != NULL ) {
F_102 ( 1 , L_11 , V_58 ) ;
return - V_158 ;
}
V_75 = F_66 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
if ( V_75 != NULL ) {
F_40 ( 3 , L_12
L_13 ,
F_42 ( V_117 -> V_40 , & V_7 ) , F_23 ( V_86 ) ,
F_15 ( & V_75 -> V_64 ) ,
V_75 -> V_87 ,
F_42 ( V_55 -> V_40 , & V_75 -> V_65 ) ,
F_23 ( V_75 -> V_66 ) ) ;
F_84 ( V_55 , V_75 , V_117 , 1 ) ;
V_156 = 0 ;
} else {
V_156 = F_88 ( V_55 , V_117 , & V_75 ) ;
}
F_100 ( 2 ) ;
return V_156 ;
}
static int
F_103 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_117 -> V_43 ;
F_89 ( 2 ) ;
if ( V_117 -> V_124 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_157 ;
}
if ( V_117 -> V_131 > V_117 -> V_129 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_157 ;
}
F_97 ( V_117 -> V_40 , & V_7 , & V_117 -> V_4 ) ;
F_56 () ;
V_75 = F_59 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
F_57 () ;
if ( V_75 == NULL ) {
F_102 ( 1 , L_14 , V_58 ) ;
return - V_159 ;
}
F_84 ( V_55 , V_75 , V_117 , 0 ) ;
F_100 ( 2 ) ;
return 0 ;
}
static void F_104 ( struct V_14 * V_15 , struct V_74 * V_75 ,
bool V_160 )
{
F_105 ( V_15 , & V_75 -> V_76 ) ;
F_54 ( V_75 ) ;
F_67 ( & V_15 -> V_96 ) ;
F_40 ( 3 , L_15 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_106 ( & V_15 -> V_161 ) && ! V_160 )
F_107 ( & V_15 -> V_99 ,
V_162 + ( V_163 >> 1 ) ) ;
F_108 ( & V_75 -> V_97 , & V_15 -> V_161 ) ;
V_75 -> V_164 = 0 ;
F_71 ( & V_15 -> V_96 ) ;
F_109 ( V_75 ) ;
}
static void F_110 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_165 )
{
V_75 -> V_12 &= ~ V_128 ;
F_111 ( & V_75 -> V_133 ) ;
V_55 -> V_135 -- ;
if ( V_75 -> V_40 != V_55 -> V_40 )
V_55 -> V_15 -> V_123 -- ;
if ( V_165 ) {
struct V_120 * V_121 ;
V_121 = F_64 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_166 )
V_121 -> V_166 ( V_55 , V_75 ) ;
}
}
static int
F_112 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
T_1 V_86 = V_117 -> V_43 ;
F_89 ( 2 ) ;
F_56 () ;
V_75 = F_59 ( V_55 , V_117 -> V_40 , & V_117 -> V_4 , V_86 ) ;
F_57 () ;
if ( V_75 == NULL ) {
F_102 ( 1 , L_16 , V_58 ) ;
return - V_159 ;
}
F_110 ( V_55 , V_75 , 1 ) ;
F_104 ( V_55 -> V_15 , V_75 , false ) ;
F_100 ( 2 ) ;
return 0 ;
}
static void F_113 ( unsigned long V_167 )
{
struct V_14 * V_15 = (struct V_14 * ) V_167 ;
struct V_74 * V_75 , * V_168 ;
unsigned long V_169 = V_162 ;
F_8 ( & V_15 -> V_96 ) ;
F_76 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
if ( V_75 -> V_164 ) {
if ( F_114 ( V_169 , V_75 -> V_164 +
V_163 ) )
continue;
} else {
V_75 -> V_164 = F_115 ( 1UL , V_169 ) ;
continue;
}
F_40 ( 3 , L_17 ,
V_75 -> V_87 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_69 ( & V_75 -> V_97 ) ;
F_72 ( V_75 ) ;
}
if ( ! F_106 ( & V_15 -> V_161 ) )
F_107 ( & V_15 -> V_99 ,
V_162 + ( V_163 >> 1 ) ) ;
F_10 ( & V_15 -> V_96 ) ;
}
static int
F_116 ( struct V_14 * V_15 , struct V_170 * V_171 ,
struct V_54 * * V_172 )
{
int V_156 = 0 , V_17 ;
struct V_120 * V_121 = NULL ;
struct V_173 * V_174 = NULL ;
struct V_54 * V_55 = NULL ;
F_18 () ;
if ( strcmp ( V_171 -> V_175 , L_18 ) ) {
V_121 = F_117 ( V_171 -> V_175 ) ;
if ( ! V_121 ) {
F_118 ( L_19 ,
V_171 -> V_175 ) ;
V_156 = - V_159 ;
goto V_176;
}
}
if ( V_171 -> V_177 && * V_171 -> V_177 ) {
V_174 = F_119 ( V_171 -> V_177 ) ;
if ( V_174 == NULL ) {
F_118 ( L_20
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
V_55 = F_92 ( sizeof( struct V_54 ) , V_147 ) ;
if ( V_55 == NULL ) {
F_102 ( 1 , L_22 , V_58 ) ;
V_156 = - V_148 ;
goto V_176;
}
V_55 -> V_76 . V_77 = F_93 ( struct V_149 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_156 = - V_148 ;
goto V_176;
}
F_94 (i) {
struct V_149 * V_101 ;
V_101 = F_95 ( V_55 -> V_76 . V_77 , V_17 ) ;
F_96 ( & V_101 -> V_152 ) ;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_171 -> V_40 ;
V_55 -> V_59 = V_171 -> V_59 ;
F_97 ( V_55 -> V_40 , & V_55 -> V_4 , & V_171 -> V_4 ) ;
V_55 -> V_43 = V_171 -> V_43 ;
V_55 -> V_53 = V_171 -> V_53 ;
V_55 -> V_12 = V_171 -> V_12 ;
V_55 -> V_181 = V_171 -> V_181 * V_182 ;
V_55 -> V_180 = V_171 -> V_180 ;
V_55 -> V_15 = V_15 ;
F_120 ( & V_55 -> V_134 ) ;
F_99 ( & V_55 -> V_183 ) ;
F_99 ( & V_55 -> V_76 . V_103 ) ;
if ( V_121 ) {
V_156 = F_121 ( V_55 , V_121 ) ;
if ( V_156 )
goto V_176;
V_121 = NULL ;
}
F_65 ( V_55 -> V_174 , V_174 ) ;
V_174 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
if ( V_55 -> V_174 && V_55 -> V_174 -> V_184 )
F_31 ( & V_15 -> V_185 ) ;
F_86 ( V_15 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_186 )
V_15 -> V_187 ++ ;
F_27 ( V_55 ) ;
* V_172 = V_55 ;
V_15 -> V_188 = 1 ;
return 0 ;
V_176:
if ( V_55 != NULL ) {
F_122 ( V_55 , V_121 ) ;
F_45 ( V_55 ) ;
}
F_123 ( V_121 ) ;
F_124 ( V_174 ) ;
F_20 () ;
return V_156 ;
}
static int
F_125 ( struct V_54 * V_55 , struct V_170 * V_171 )
{
struct V_120 * V_121 = NULL , * V_189 ;
struct V_173 * V_174 = NULL , * V_190 = NULL ;
int V_156 = 0 ;
bool V_191 , V_192 ;
if ( strcmp ( V_171 -> V_175 , L_18 ) ) {
V_121 = F_117 ( V_171 -> V_175 ) ;
if ( ! V_121 ) {
F_118 ( L_19 ,
V_171 -> V_175 ) ;
return - V_159 ;
}
}
V_189 = V_121 ;
if ( V_171 -> V_177 && * V_171 -> V_177 ) {
V_174 = F_119 ( V_171 -> V_177 ) ;
if ( V_174 == NULL ) {
F_118 ( L_20
L_21 , V_171 -> V_177 ) ;
V_156 = - V_159 ;
goto V_67;
}
V_190 = V_174 ;
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
V_189 = F_64 ( V_55 -> V_136 , 1 ) ;
if ( V_121 != V_189 ) {
if ( V_189 ) {
F_122 ( V_55 , V_189 ) ;
F_65 ( V_55 -> V_136 , NULL ) ;
F_126 () ;
}
if ( V_121 ) {
V_156 = F_121 ( V_55 , V_121 ) ;
if ( V_156 ) {
F_123 ( V_121 ) ;
goto V_67;
}
}
}
V_55 -> V_12 = V_171 -> V_12 | V_57 ;
V_55 -> V_181 = V_171 -> V_181 * V_182 ;
V_55 -> V_180 = V_171 -> V_180 ;
V_190 = F_64 ( V_55 -> V_174 , 1 ) ;
if ( V_174 != V_190 ) {
F_44 ( V_55 -> V_174 , V_174 ) ;
V_191 = ( V_174 && V_174 -> V_184 ) ? true : false ;
V_192 = ( V_190 && V_190 -> V_184 ) ? true : false ;
if ( V_191 && ! V_192 )
F_31 ( & V_55 -> V_15 -> V_185 ) ;
if ( V_192 && ! V_191 )
F_34 ( & V_55 -> V_15 -> V_185 ) ;
}
V_67:
F_123 ( V_189 ) ;
F_124 ( V_190 ) ;
return V_156 ;
}
static void F_127 ( struct V_54 * V_55 , bool V_160 )
{
struct V_74 * V_75 , * V_98 ;
struct V_120 * V_189 ;
struct V_173 * V_190 ;
struct V_14 * V_15 = V_55 -> V_15 ;
if ( V_55 -> V_40 == V_186 )
V_15 -> V_187 -- ;
F_105 ( V_55 -> V_15 , & V_55 -> V_76 ) ;
V_189 = F_64 ( V_55 -> V_136 , 1 ) ;
F_122 ( V_55 , V_189 ) ;
F_123 ( V_189 ) ;
V_190 = F_64 ( V_55 -> V_174 , 1 ) ;
if ( V_190 && V_190 -> V_184 )
F_34 ( & V_15 -> V_185 ) ;
F_124 ( V_190 ) ;
F_76 (dest, nxt, &svc->destinations, n_list) {
F_110 ( V_55 , V_75 , 0 ) ;
F_104 ( V_55 -> V_15 , V_75 , V_160 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
F_49 ( V_55 , true ) ;
F_20 () ;
}
static void F_128 ( struct V_54 * V_55 , bool V_160 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_127 ( V_55 , V_160 ) ;
}
static int F_129 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_158 ;
F_128 ( V_55 , false ) ;
return 0 ;
}
static int F_130 ( struct V_14 * V_15 , bool V_160 )
{
int V_193 ;
struct V_54 * V_55 ;
struct V_194 * V_195 ;
for( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_131 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( V_55 -> V_15 == V_15 )
F_128 ( V_55 , V_160 ) ;
}
}
for( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_131 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( V_55 -> V_15 == V_15 )
F_128 ( V_55 , V_160 ) ;
}
}
return 0 ;
}
void F_132 ( struct V_14 * V_15 )
{
F_89 ( 2 ) ;
F_133 ( & V_197 ) ;
F_130 ( V_15 , true ) ;
F_134 ( & V_197 ) ;
F_100 ( 2 ) ;
}
static inline void
F_135 ( struct V_74 * V_75 , struct V_198 * V_11 )
{
struct V_92 * V_93 ;
F_67 ( & V_75 -> V_132 ) ;
V_93 = F_64 ( V_75 -> V_93 , 1 ) ;
if ( V_93 && V_93 -> V_94 -> V_11 == V_11 ) {
F_40 ( 3 , L_23 ,
V_11 -> V_199 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_63 ( V_75 ) ;
}
F_71 ( & V_75 -> V_132 ) ;
}
static int F_136 ( struct V_200 * V_201 , unsigned long V_202 ,
void * V_203 )
{
struct V_198 * V_11 = F_137 ( V_203 ) ;
struct V_2 * V_2 = F_138 ( V_11 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_193 ;
if ( V_202 != V_204 || ! V_15 )
return V_205 ;
F_102 ( 3 , L_24 , V_58 , V_11 -> V_199 ) ;
F_89 ( 2 ) ;
F_133 ( & V_197 ) ;
for ( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_140 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_15 == V_15 ) {
F_68 (dest, &svc->destinations,
n_list) {
F_135 ( V_75 , V_11 ) ;
}
}
}
F_140 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_15 == V_15 ) {
F_68 (dest, &svc->destinations,
n_list) {
F_135 ( V_75 , V_11 ) ;
}
}
}
}
F_67 ( & V_15 -> V_96 ) ;
F_68 (dest, &ipvs->dest_trash, t_list) {
F_135 ( V_75 , V_11 ) ;
}
F_71 ( & V_15 -> V_96 ) ;
F_134 ( & V_197 ) ;
F_100 ( 2 ) ;
return V_205 ;
}
static int F_141 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_68 (dest, &svc->destinations, n_list) {
F_81 ( & V_75 -> V_76 ) ;
}
F_81 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_142 ( struct V_14 * V_15 )
{
int V_193 ;
struct V_54 * V_55 ;
for( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_140 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_15 == V_15 )
F_141 ( V_55 ) ;
}
}
for( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_140 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_15 == V_15 )
F_141 ( V_55 ) ;
}
}
F_81 ( & V_15 -> V_206 ) ;
return 0 ;
}
static int
F_143 ( struct V_207 * V_208 , int V_209 ,
void T_6 * V_210 , V_50 * V_211 , T_7 * V_212 )
{
struct V_14 * V_15 = V_208 -> V_213 ;
int * V_214 = V_208 -> V_167 ;
int V_215 = * V_214 ;
int V_216 ;
V_216 = F_144 ( V_208 , V_209 , V_210 , V_211 , V_212 ) ;
if ( V_209 && ( * V_214 != V_215 ) ) {
if ( ( * V_214 < 0 ) || ( * V_214 > 3 ) ) {
* V_214 = V_215 ;
} else {
F_5 ( V_15 ) ;
}
}
return V_216 ;
}
static int
F_145 ( struct V_207 * V_208 , int V_209 ,
void T_6 * V_210 , V_50 * V_211 , T_7 * V_212 )
{
int * V_214 = V_208 -> V_167 ;
int V_215 [ 2 ] ;
int V_216 ;
memcpy ( V_215 , V_214 , sizeof( V_215 ) ) ;
V_216 = F_144 ( V_208 , V_209 , V_210 , V_211 , V_212 ) ;
if ( V_209 && ( V_214 [ 0 ] < 0 || V_214 [ 1 ] < 0 ||
( V_214 [ 0 ] >= V_214 [ 1 ] && V_214 [ 1 ] ) ) ) {
memcpy ( V_214 , V_215 , sizeof( V_215 ) ) ;
}
return V_216 ;
}
static int
F_146 ( struct V_207 * V_208 , int V_209 ,
void T_6 * V_210 , V_50 * V_211 , T_7 * V_212 )
{
int * V_214 = V_208 -> V_167 ;
int V_215 = * V_214 ;
int V_216 ;
V_216 = F_144 ( V_208 , V_209 , V_210 , V_211 , V_212 ) ;
if ( V_209 && ( * V_214 != V_215 ) ) {
if ( ( * V_214 < 0 ) || ( * V_214 > 1 ) ) {
* V_214 = V_215 ;
}
}
return V_216 ;
}
static int
F_147 ( struct V_207 * V_208 , int V_209 ,
void T_6 * V_210 , V_50 * V_211 , T_7 * V_212 )
{
int * V_214 = V_208 -> V_167 ;
int V_215 = * V_214 ;
int V_216 ;
V_216 = F_144 ( V_208 , V_209 , V_210 , V_211 , V_212 ) ;
if ( V_209 && ( * V_214 != V_215 ) ) {
if ( * V_214 < 1 || ! F_148 ( * V_214 ) ) {
* V_214 = V_215 ;
}
}
return V_216 ;
}
static inline const char * F_149 ( unsigned int V_12 )
{
switch ( V_12 & V_90 ) {
case V_217 :
return L_25 ;
case V_218 :
return L_26 ;
case V_219 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_150 ( struct V_220 * V_221 , T_7 V_222 )
{
struct V_2 * V_2 = F_151 ( V_221 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
struct V_223 * V_224 = V_221 -> V_225 ;
int V_193 ;
struct V_54 * V_55 ;
for ( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( ( V_55 -> V_15 == V_15 ) && V_222 -- == 0 ) {
V_224 -> V_208 = V_61 ;
V_224 -> V_226 = V_193 ;
return V_55 ;
}
}
}
for ( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( ( V_55 -> V_15 == V_15 ) && V_222 -- == 0 ) {
V_224 -> V_208 = V_63 ;
V_224 -> V_226 = V_193 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_152 ( struct V_220 * V_221 , T_7 * V_222 )
__acquires( T_8 )
{
F_56 () ;
return * V_222 ? F_150 ( V_221 , * V_222 - 1 ) : V_227 ;
}
static void * F_153 ( struct V_220 * V_221 , void * V_228 , T_7 * V_222 )
{
struct V_194 * V_229 ;
struct V_223 * V_224 ;
struct V_54 * V_55 ;
++ * V_222 ;
if ( V_228 == V_227 )
return F_150 ( V_221 , 0 ) ;
V_55 = V_228 ;
V_224 = V_221 -> V_225 ;
if ( V_224 -> V_208 == V_61 ) {
V_229 = F_154 ( F_155 ( & V_55 -> V_60 ) ) ;
if ( V_229 )
return F_156 ( V_229 , struct V_54 , V_60 ) ;
while ( ++ V_224 -> V_226 < V_196 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_224 -> V_208 = V_63 ;
V_224 -> V_226 = - 1 ;
goto V_230;
}
V_229 = F_154 ( F_155 ( & V_55 -> V_62 ) ) ;
if ( V_229 )
return F_156 ( V_229 , struct V_54 , V_62 ) ;
V_230:
while ( ++ V_224 -> V_226 < V_196 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_157 ( struct V_220 * V_221 , void * V_228 )
__releases( T_8 )
{
F_57 () ;
}
static int F_158 ( struct V_220 * V_221 , void * V_228 )
{
if ( V_228 == V_227 ) {
F_159 ( V_221 ,
L_29 ,
F_160 ( V_231 ) , V_232 ) ;
F_161 ( V_221 ,
L_30 ) ;
F_161 ( V_221 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_228 ;
const struct V_223 * V_224 = V_221 -> V_225 ;
const struct V_74 * V_75 ;
struct V_120 * V_121 = F_154 ( V_55 -> V_136 ) ;
char * V_175 = V_121 ? V_121 -> V_199 : L_18 ;
if ( V_224 -> V_208 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_159 ( V_221 , L_32 ,
F_41 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_141 ,
F_23 ( V_55 -> V_43 ) ,
V_175 ) ;
else
#endif
F_159 ( V_221 , L_33 ,
F_41 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_175 ,
( V_55 -> V_12 & V_233 ) ? L_34 : L_35 ) ;
} else {
F_159 ( V_221 , L_36 ,
V_55 -> V_53 , V_175 ,
( V_55 -> V_12 & V_233 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_234 )
F_159 ( V_221 , L_37 ,
V_55 -> V_181 ,
F_25 ( V_55 -> V_180 ) ) ;
else
F_162 ( V_221 , '\n' ) ;
F_60 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_159 ( V_221 ,
L_38
L_39 ,
& V_75 -> V_4 . V_141 ,
F_23 ( V_75 -> V_43 ) ,
F_149 ( F_15 ( & V_75 -> V_122 ) ) ,
F_15 ( & V_75 -> V_124 ) ,
F_15 ( & V_75 -> V_153 ) ,
F_15 ( & V_75 -> V_154 ) ) ;
else
#endif
F_159 ( V_221 ,
L_40
L_41 ,
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
static int F_163 ( struct V_235 * V_235 , struct V_236 * V_236 )
{
return F_164 ( V_235 , V_236 , & V_237 ,
sizeof( struct V_223 ) ) ;
}
static int F_165 ( struct V_220 * V_221 , void * V_228 )
{
struct V_2 * V_2 = F_166 ( V_221 ) ;
struct V_100 V_238 ;
F_161 ( V_221 ,
L_42 ) ;
F_159 ( V_221 ,
L_43 ) ;
F_77 ( & V_238 , & F_139 ( V_2 ) -> V_206 ) ;
F_159 ( V_221 , L_44 ,
( unsigned long long ) V_238 . V_104 ,
( unsigned long long ) V_238 . V_105 ,
( unsigned long long ) V_238 . V_106 ,
( unsigned long long ) V_238 . V_107 ,
( unsigned long long ) V_238 . V_108 ) ;
F_161 ( V_221 ,
L_45 ) ;
F_159 ( V_221 , L_46 ,
( unsigned long long ) V_238 . V_111 ,
( unsigned long long ) V_238 . V_112 ,
( unsigned long long ) V_238 . V_113 ,
( unsigned long long ) V_238 . V_114 ,
( unsigned long long ) V_238 . V_115 ) ;
return 0 ;
}
static int F_167 ( struct V_235 * V_235 , struct V_236 * V_236 )
{
return F_168 ( V_235 , V_236 , F_165 ) ;
}
static int F_169 ( struct V_220 * V_221 , void * V_228 )
{
struct V_2 * V_2 = F_166 ( V_221 ) ;
struct V_101 * V_206 = & F_139 ( V_2 ) -> V_206 ;
struct V_149 T_9 * V_77 = V_206 -> V_77 ;
struct V_100 V_239 ;
int V_17 ;
F_161 ( V_221 ,
L_47 ) ;
F_159 ( V_221 ,
L_48 ) ;
F_94 (i) {
struct V_149 * V_171 = F_95 ( V_77 , V_17 ) ;
unsigned int V_240 ;
T_10 V_104 , V_105 , V_106 , V_107 , V_108 ;
do {
V_240 = F_170 ( & V_171 -> V_152 ) ;
V_104 = V_171 -> V_241 . V_104 ;
V_105 = V_171 -> V_241 . V_105 ;
V_106 = V_171 -> V_241 . V_106 ;
V_107 = V_171 -> V_241 . V_107 ;
V_108 = V_171 -> V_241 . V_108 ;
} while ( F_171 ( & V_171 -> V_152 , V_240 ) );
F_159 ( V_221 , L_49 ,
V_17 , ( T_10 ) V_104 , ( T_10 ) V_105 ,
( T_10 ) V_106 , ( T_10 ) V_107 ,
( T_10 ) V_108 ) ;
}
F_77 ( & V_239 , V_206 ) ;
F_159 ( V_221 , L_50 ,
( unsigned long long ) V_239 . V_104 ,
( unsigned long long ) V_239 . V_105 ,
( unsigned long long ) V_239 . V_106 ,
( unsigned long long ) V_239 . V_107 ,
( unsigned long long ) V_239 . V_108 ) ;
F_161 ( V_221 ,
L_51 ) ;
F_159 ( V_221 , L_52 ,
V_239 . V_111 ,
V_239 . V_112 ,
V_239 . V_113 ,
V_239 . V_114 ,
V_239 . V_115 ) ;
return 0 ;
}
static int F_172 ( struct V_235 * V_235 , struct V_236 * V_236 )
{
return F_168 ( V_235 , V_236 , F_169 ) ;
}
static int F_173 ( struct V_14 * V_15 , struct V_242 * V_171 )
{
#if F_174 ( V_243 ) || F_174 ( V_244 )
struct V_245 * V_246 ;
#endif
F_102 ( 2 , L_53 ,
V_171 -> V_247 ,
V_171 -> V_248 ,
V_171 -> V_249 ) ;
#ifdef V_243
if ( V_171 -> V_247 ) {
V_246 = F_175 ( V_15 , V_68 ) ;
V_246 -> V_250 [ V_251 ]
= V_171 -> V_247 * V_182 ;
}
if ( V_171 -> V_248 ) {
V_246 = F_175 ( V_15 , V_68 ) ;
V_246 -> V_250 [ V_252 ]
= V_171 -> V_248 * V_182 ;
}
#endif
#ifdef V_244
if ( V_171 -> V_249 ) {
V_246 = F_175 ( V_15 , V_253 ) ;
V_246 -> V_250 [ V_254 ]
= V_171 -> V_249 * V_182 ;
}
#endif
return 0 ;
}
static void F_176 ( struct V_170 * V_255 ,
struct V_256 * V_257 )
{
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
V_255 -> V_40 = V_186 ;
V_255 -> V_59 = V_257 -> V_59 ;
V_255 -> V_4 . V_46 = V_257 -> V_4 ;
V_255 -> V_43 = V_257 -> V_43 ;
V_255 -> V_53 = V_257 -> V_53 ;
V_255 -> V_175 = V_257 -> V_175 ;
V_255 -> V_12 = V_257 -> V_12 ;
V_255 -> V_181 = V_257 -> V_181 ;
V_255 -> V_180 = V_257 -> V_180 ;
}
static void F_177 ( struct V_116 * V_117 ,
struct V_258 * V_259 )
{
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
V_117 -> V_4 . V_46 = V_259 -> V_4 ;
V_117 -> V_43 = V_259 -> V_43 ;
V_117 -> V_122 = V_259 -> V_122 ;
V_117 -> V_124 = V_259 -> V_124 ;
V_117 -> V_129 = V_259 -> V_129 ;
V_117 -> V_131 = V_259 -> V_131 ;
V_117 -> V_40 = V_186 ;
}
static int
F_178 ( struct V_260 * V_261 , int V_262 , void T_6 * V_263 , unsigned int V_264 )
{
struct V_2 * V_2 = F_179 ( V_261 ) ;
int V_156 ;
unsigned char V_265 [ V_266 ] ;
struct V_256 * V_257 ;
struct V_170 V_255 ;
struct V_54 * V_55 ;
struct V_258 * V_259 ;
struct V_116 V_117 ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
F_180 ( sizeof( V_265 ) > 255 ) ;
if ( ! F_181 ( F_179 ( V_261 ) -> V_267 , V_268 ) )
return - V_269 ;
if ( V_262 < V_270 || V_262 > V_271 )
return - V_144 ;
if ( V_264 != V_272 [ F_182 ( V_262 ) ] ) {
F_102 ( 1 , L_54 ,
V_264 , V_272 [ F_182 ( V_262 ) ] ) ;
return - V_144 ;
}
if ( F_183 ( V_265 , V_263 , V_264 ) != 0 )
return - V_273 ;
F_18 () ;
if ( V_262 == V_274 ||
V_262 == V_275 ) {
struct V_276 * V_277 = (struct V_276 * ) V_265 ;
if ( V_262 == V_274 ) {
struct V_278 V_279 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
F_184 ( V_279 . V_280 , V_277 -> V_280 ,
sizeof( V_279 . V_280 ) ) ;
V_279 . V_281 = V_277 -> V_281 ;
F_185 () ;
F_133 ( & V_15 -> V_282 ) ;
V_156 = F_186 ( V_15 , & V_279 , V_277 -> V_283 ) ;
F_134 ( & V_15 -> V_282 ) ;
F_187 () ;
} else {
F_133 ( & V_15 -> V_282 ) ;
V_156 = F_188 ( V_15 , V_277 -> V_283 ) ;
F_134 ( & V_15 -> V_282 ) ;
}
goto V_284;
}
F_133 ( & V_197 ) ;
if ( V_262 == V_285 ) {
V_156 = F_130 ( V_15 , false ) ;
goto V_286;
} else if ( V_262 == V_287 ) {
V_156 = F_173 ( V_15 , (struct V_242 * ) V_265 ) ;
goto V_286;
}
V_257 = (struct V_256 * ) V_265 ;
V_259 = (struct V_258 * ) ( V_257 + 1 ) ;
F_176 ( & V_255 , V_257 ) ;
F_177 ( & V_117 , V_259 ) ;
if ( V_262 == V_288 ) {
if ( ! V_255 . V_53 && ! V_255 . V_4 . V_46 && ! V_255 . V_43 ) {
V_156 = F_142 ( V_15 ) ;
goto V_286;
}
}
if ( V_255 . V_59 != V_68 && V_255 . V_59 != V_253 &&
V_255 . V_59 != V_289 ) {
F_28 ( L_55 ,
V_255 . V_59 , & V_255 . V_4 . V_46 ,
F_23 ( V_255 . V_43 ) , V_255 . V_175 ) ;
V_156 = - V_273 ;
goto V_286;
}
F_56 () ;
if ( V_255 . V_53 == 0 )
V_55 = F_35 ( V_15 , V_255 . V_40 , V_255 . V_59 ,
& V_255 . V_4 , V_255 . V_43 ) ;
else
V_55 = F_38 ( V_15 , V_255 . V_40 , V_255 . V_53 ) ;
F_57 () ;
if ( V_262 != V_290
&& ( V_55 == NULL || V_55 -> V_59 != V_255 . V_59 ) ) {
V_156 = - V_291 ;
goto V_286;
}
switch ( V_262 ) {
case V_290 :
if ( V_55 != NULL )
V_156 = - V_158 ;
else
V_156 = F_116 ( V_15 , & V_255 , & V_55 ) ;
break;
case V_292 :
V_156 = F_125 ( V_55 , & V_255 ) ;
break;
case V_293 :
V_156 = F_129 ( V_55 ) ;
if ( ! V_156 )
goto V_286;
break;
case V_288 :
V_156 = F_141 ( V_55 ) ;
break;
case V_294 :
V_156 = F_101 ( V_55 , & V_117 ) ;
break;
case V_295 :
V_156 = F_103 ( V_55 , & V_117 ) ;
break;
case V_296 :
V_156 = F_112 ( V_55 , & V_117 ) ;
break;
default:
V_156 = - V_144 ;
}
V_286:
F_134 ( & V_197 ) ;
V_284:
F_20 () ;
return V_156 ;
}
static void
F_189 ( struct V_297 * V_9 , struct V_54 * V_102 )
{
struct V_120 * V_121 ;
struct V_100 V_239 ;
char * V_175 ;
V_121 = F_64 ( V_102 -> V_136 , 1 ) ;
V_175 = V_121 ? V_121 -> V_199 : L_18 ;
V_9 -> V_59 = V_102 -> V_59 ;
V_9 -> V_4 = V_102 -> V_4 . V_46 ;
V_9 -> V_43 = V_102 -> V_43 ;
V_9 -> V_53 = V_102 -> V_53 ;
F_184 ( V_9 -> V_175 , V_175 , sizeof( V_9 -> V_175 ) ) ;
V_9 -> V_12 = V_102 -> V_12 ;
V_9 -> V_181 = V_102 -> V_181 / V_182 ;
V_9 -> V_180 = V_102 -> V_180 ;
V_9 -> V_135 = V_102 -> V_135 ;
F_77 ( & V_239 , & V_102 -> V_76 ) ;
F_80 ( & V_9 -> V_76 , & V_239 ) ;
}
static inline int
F_190 ( struct V_14 * V_15 ,
const struct V_298 * V_299 ,
struct V_298 T_6 * V_300 )
{
int V_193 , V_301 = 0 ;
struct V_54 * V_55 ;
struct V_297 V_302 ;
int V_156 = 0 ;
for ( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_140 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_186 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( V_301 >= V_299 -> V_187 )
goto V_67;
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
F_189 ( & V_302 , V_55 ) ;
if ( F_191 ( & V_300 -> V_303 [ V_301 ] ,
& V_302 , sizeof( V_302 ) ) ) {
V_156 = - V_273 ;
goto V_67;
}
V_301 ++ ;
}
}
for ( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_140 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_186 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( V_301 >= V_299 -> V_187 )
goto V_67;
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
F_189 ( & V_302 , V_55 ) ;
if ( F_191 ( & V_300 -> V_303 [ V_301 ] ,
& V_302 , sizeof( V_302 ) ) ) {
V_156 = - V_273 ;
goto V_67;
}
V_301 ++ ;
}
}
V_67:
return V_156 ;
}
static inline int
F_192 ( struct V_14 * V_15 , const struct V_304 * V_299 ,
struct V_304 T_6 * V_300 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_299 -> V_4 } ;
int V_156 = 0 ;
F_56 () ;
if ( V_299 -> V_53 )
V_55 = F_38 ( V_15 , V_186 , V_299 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_186 , V_299 -> V_59 , & V_4 ,
V_299 -> V_43 ) ;
F_57 () ;
if ( V_55 ) {
int V_301 = 0 ;
struct V_74 * V_75 ;
struct V_305 V_302 ;
struct V_100 V_239 ;
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
F_68 (dest, &svc->destinations, n_list) {
if ( V_301 >= V_299 -> V_135 )
break;
if ( V_75 -> V_40 != V_55 -> V_40 )
continue;
V_302 . V_4 = V_75 -> V_4 . V_46 ;
V_302 . V_43 = V_75 -> V_43 ;
V_302 . V_122 = F_15 ( & V_75 -> V_122 ) ;
V_302 . V_124 = F_15 ( & V_75 -> V_124 ) ;
V_302 . V_129 = V_75 -> V_129 ;
V_302 . V_131 = V_75 -> V_131 ;
V_302 . V_153 = F_15 ( & V_75 -> V_153 ) ;
V_302 . V_154 = F_15 ( & V_75 -> V_154 ) ;
V_302 . V_155 = F_15 ( & V_75 -> V_155 ) ;
F_77 ( & V_239 , & V_75 -> V_76 ) ;
F_80 ( & V_302 . V_76 , & V_239 ) ;
if ( F_191 ( & V_300 -> V_303 [ V_301 ] ,
& V_302 , sizeof( V_302 ) ) ) {
V_156 = - V_273 ;
break;
}
V_301 ++ ;
}
} else
V_156 = - V_291 ;
return V_156 ;
}
static inline void
F_193 ( struct V_14 * V_15 , struct V_242 * V_171 )
{
#if F_174 ( V_243 ) || F_174 ( V_244 )
struct V_245 * V_246 ;
#endif
memset ( V_171 , 0 , sizeof ( * V_171 ) ) ;
#ifdef V_243
V_246 = F_175 ( V_15 , V_68 ) ;
V_171 -> V_247 = V_246 -> V_250 [ V_251 ] / V_182 ;
V_171 -> V_248 = V_246 -> V_250 [ V_252 ] / V_182 ;
#endif
#ifdef V_244
V_246 = F_175 ( V_15 , V_253 ) ;
V_171 -> V_249 =
V_246 -> V_250 [ V_254 ] / V_182 ;
#endif
}
static int
F_194 ( struct V_260 * V_261 , int V_262 , void T_6 * V_263 , int * V_264 )
{
unsigned char V_265 [ V_306 ] ;
int V_156 = 0 ;
unsigned int V_307 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
F_85 ( ! V_2 ) ;
F_180 ( sizeof( V_265 ) > 255 ) ;
if ( ! F_181 ( F_179 ( V_261 ) -> V_267 , V_268 ) )
return - V_269 ;
if ( V_262 < V_270 || V_262 > V_308 )
return - V_144 ;
V_307 = V_309 [ F_182 ( V_262 ) ] ;
if ( * V_264 < ( int ) V_307 ) {
F_102 ( 1 , L_56 , * V_264 , V_307 ) ;
return - V_144 ;
}
if ( F_183 ( V_265 , V_263 , V_307 ) != 0 )
return - V_273 ;
if ( V_262 == V_310 ) {
struct V_276 V_311 [ 2 ] ;
memset ( & V_311 , 0 , sizeof( V_311 ) ) ;
F_133 ( & V_15 -> V_282 ) ;
if ( V_15 -> V_312 & V_313 ) {
V_311 [ 0 ] . V_283 = V_313 ;
F_184 ( V_311 [ 0 ] . V_280 , V_15 -> V_314 . V_280 ,
sizeof( V_311 [ 0 ] . V_280 ) ) ;
V_311 [ 0 ] . V_281 = V_15 -> V_314 . V_281 ;
}
if ( V_15 -> V_312 & V_315 ) {
V_311 [ 1 ] . V_283 = V_315 ;
F_184 ( V_311 [ 1 ] . V_280 , V_15 -> V_316 . V_280 ,
sizeof( V_311 [ 1 ] . V_280 ) ) ;
V_311 [ 1 ] . V_281 = V_15 -> V_316 . V_281 ;
}
if ( F_191 ( V_263 , & V_311 , sizeof( V_311 ) ) != 0 )
V_156 = - V_273 ;
F_134 ( & V_15 -> V_282 ) ;
return V_156 ;
}
F_133 ( & V_197 ) ;
switch ( V_262 ) {
case V_317 :
{
char V_318 [ 64 ] ;
sprintf ( V_318 , L_57 ,
F_160 ( V_231 ) , V_232 ) ;
if ( F_191 ( V_263 , V_318 , strlen ( V_318 ) + 1 ) != 0 ) {
V_156 = - V_273 ;
goto V_67;
}
* V_264 = strlen ( V_318 ) + 1 ;
}
break;
case V_319 :
{
struct V_320 V_321 ;
V_321 . V_322 = V_231 ;
V_321 . V_323 = V_232 ;
V_321 . V_187 = V_15 -> V_187 ;
if ( F_191 ( V_263 , & V_321 , sizeof( V_321 ) ) != 0 )
V_156 = - V_273 ;
}
break;
case V_324 :
{
struct V_298 * V_299 ;
int V_323 ;
V_299 = (struct V_298 * ) V_265 ;
V_323 = sizeof( * V_299 ) +
sizeof( struct V_297 ) * V_299 -> V_187 ;
if ( * V_264 != V_323 ) {
F_28 ( L_58 , * V_264 , V_323 ) ;
V_156 = - V_144 ;
goto V_67;
}
V_156 = F_190 ( V_15 , V_299 , V_263 ) ;
}
break;
case V_325 :
{
struct V_297 * V_302 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_302 = (struct V_297 * ) V_265 ;
V_4 . V_46 = V_302 -> V_4 ;
F_56 () ;
if ( V_302 -> V_53 )
V_55 = F_38 ( V_15 , V_186 , V_302 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_186 ,
V_302 -> V_59 , & V_4 ,
V_302 -> V_43 ) ;
F_57 () ;
if ( V_55 ) {
F_189 ( V_302 , V_55 ) ;
if ( F_191 ( V_263 , V_302 , sizeof( * V_302 ) ) != 0 )
V_156 = - V_273 ;
} else
V_156 = - V_291 ;
}
break;
case V_326 :
{
struct V_304 * V_299 ;
int V_323 ;
V_299 = (struct V_304 * ) V_265 ;
V_323 = sizeof( * V_299 ) +
sizeof( struct V_305 ) * V_299 -> V_135 ;
if ( * V_264 != V_323 ) {
F_28 ( L_58 , * V_264 , V_323 ) ;
V_156 = - V_144 ;
goto V_67;
}
V_156 = F_192 ( V_15 , V_299 , V_263 ) ;
}
break;
case V_327 :
{
struct V_242 V_328 ;
F_193 ( V_15 , & V_328 ) ;
if ( F_191 ( V_263 , & V_328 , sizeof( V_328 ) ) != 0 )
V_156 = - V_273 ;
}
break;
default:
V_156 = - V_144 ;
}
V_67:
F_134 ( & V_197 ) ;
return V_156 ;
}
static int F_195 ( struct V_329 * V_330 , int V_331 ,
struct V_100 * V_239 )
{
struct V_332 * V_333 = F_196 ( V_330 , V_331 ) ;
if ( ! V_333 )
return - V_334 ;
if ( F_197 ( V_330 , V_335 , ( V_110 ) V_239 -> V_104 ) ||
F_197 ( V_330 , V_336 , ( V_110 ) V_239 -> V_105 ) ||
F_197 ( V_330 , V_337 , ( V_110 ) V_239 -> V_106 ) ||
F_198 ( V_330 , V_338 , V_239 -> V_107 ,
V_339 ) ||
F_198 ( V_330 , V_340 , V_239 -> V_108 ,
V_339 ) ||
F_197 ( V_330 , V_341 , ( V_110 ) V_239 -> V_111 ) ||
F_197 ( V_330 , V_342 , ( V_110 ) V_239 -> V_112 ) ||
F_197 ( V_330 , V_343 , ( V_110 ) V_239 -> V_113 ) ||
F_197 ( V_330 , V_344 , ( V_110 ) V_239 -> V_114 ) ||
F_197 ( V_330 , V_345 , ( V_110 ) V_239 -> V_115 ) )
goto V_346;
F_199 ( V_330 , V_333 ) ;
return 0 ;
V_346:
F_200 ( V_330 , V_333 ) ;
return - V_334 ;
}
static int F_201 ( struct V_329 * V_330 , int V_331 ,
struct V_100 * V_239 )
{
struct V_332 * V_333 = F_196 ( V_330 , V_331 ) ;
if ( ! V_333 )
return - V_334 ;
if ( F_198 ( V_330 , V_335 , V_239 -> V_104 ,
V_339 ) ||
F_198 ( V_330 , V_336 , V_239 -> V_105 ,
V_339 ) ||
F_198 ( V_330 , V_337 , V_239 -> V_106 ,
V_339 ) ||
F_198 ( V_330 , V_338 , V_239 -> V_107 ,
V_339 ) ||
F_198 ( V_330 , V_340 , V_239 -> V_108 ,
V_339 ) ||
F_198 ( V_330 , V_341 , V_239 -> V_111 ,
V_339 ) ||
F_198 ( V_330 , V_342 , V_239 -> V_112 ,
V_339 ) ||
F_198 ( V_330 , V_343 , V_239 -> V_113 ,
V_339 ) ||
F_198 ( V_330 , V_344 , V_239 -> V_114 ,
V_339 ) ||
F_198 ( V_330 , V_345 , V_239 -> V_115 ,
V_339 ) )
goto V_346;
F_199 ( V_330 , V_333 ) ;
return 0 ;
V_346:
F_200 ( V_330 , V_333 ) ;
return - V_334 ;
}
static int F_202 ( struct V_329 * V_330 ,
struct V_54 * V_55 )
{
struct V_120 * V_121 ;
struct V_173 * V_174 ;
struct V_332 * V_347 ;
struct V_348 V_12 = { . V_12 = V_55 -> V_12 ,
. V_349 = ~ 0 } ;
struct V_100 V_239 ;
char * V_175 ;
V_347 = F_196 ( V_330 , V_350 ) ;
if ( ! V_347 )
return - V_334 ;
if ( F_203 ( V_330 , V_351 , V_55 -> V_40 ) )
goto V_346;
if ( V_55 -> V_53 ) {
if ( F_197 ( V_330 , V_352 , V_55 -> V_53 ) )
goto V_346;
} else {
if ( F_203 ( V_330 , V_353 , V_55 -> V_59 ) ||
F_204 ( V_330 , V_354 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_205 ( V_330 , V_355 , V_55 -> V_43 ) )
goto V_346;
}
V_121 = F_64 ( V_55 -> V_136 , 1 ) ;
V_175 = V_121 ? V_121 -> V_199 : L_18 ;
V_174 = F_64 ( V_55 -> V_174 , 1 ) ;
if ( F_206 ( V_330 , V_356 , V_175 ) ||
( V_174 && F_206 ( V_330 , V_357 , V_174 -> V_199 ) ) ||
F_204 ( V_330 , V_358 , sizeof( V_12 ) , & V_12 ) ||
F_197 ( V_330 , V_359 , V_55 -> V_181 / V_182 ) ||
F_207 ( V_330 , V_360 , V_55 -> V_180 ) )
goto V_346;
F_77 ( & V_239 , & V_55 -> V_76 ) ;
if ( F_195 ( V_330 , V_361 , & V_239 ) )
goto V_346;
if ( F_201 ( V_330 , V_362 , & V_239 ) )
goto V_346;
F_199 ( V_330 , V_347 ) ;
return 0 ;
V_346:
F_200 ( V_330 , V_347 ) ;
return - V_334 ;
}
static int F_208 ( struct V_329 * V_330 ,
struct V_54 * V_55 ,
struct V_363 * V_364 )
{
void * V_365 ;
V_365 = F_209 ( V_330 , F_210 ( V_364 -> V_330 ) . V_366 , V_364 -> V_367 -> V_368 ,
& V_369 , V_370 ,
V_371 ) ;
if ( ! V_365 )
return - V_334 ;
if ( F_202 ( V_330 , V_55 ) < 0 )
goto V_346;
F_211 ( V_330 , V_365 ) ;
return 0 ;
V_346:
F_212 ( V_330 , V_365 ) ;
return - V_334 ;
}
static int F_213 ( struct V_329 * V_330 ,
struct V_363 * V_364 )
{
int V_193 = 0 , V_17 ;
int V_240 = V_364 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_179 ( V_330 -> V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
F_133 ( & V_197 ) ;
for ( V_17 = 0 ; V_17 < V_196 ; V_17 ++ ) {
F_140 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_193 <= V_240 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( F_208 ( V_330 , V_55 , V_364 ) < 0 ) {
V_193 -- ;
goto V_346;
}
}
}
for ( V_17 = 0 ; V_17 < V_196 ; V_17 ++ ) {
F_140 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_193 <= V_240 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( F_208 ( V_330 , V_55 , V_364 ) < 0 ) {
V_193 -- ;
goto V_346;
}
}
}
V_346:
F_134 ( & V_197 ) ;
V_364 -> args [ 0 ] = V_193 ;
return V_330 -> V_264 ;
}
static int F_214 ( struct V_14 * V_15 ,
struct V_170 * V_255 ,
struct V_332 * V_372 , int V_373 ,
struct V_54 * * V_374 )
{
struct V_332 * V_375 [ V_376 + 1 ] ;
struct V_332 * V_377 , * V_378 , * V_379 , * V_380 , * V_381 ;
struct V_54 * V_55 ;
if ( V_372 == NULL ||
F_215 ( V_375 , V_376 , V_372 , V_382 ) )
return - V_144 ;
V_377 = V_375 [ V_351 ] ;
V_380 = V_375 [ V_353 ] ;
V_381 = V_375 [ V_354 ] ;
V_378 = V_375 [ V_355 ] ;
V_379 = V_375 [ V_352 ] ;
if ( ! ( V_377 && ( V_379 || ( V_378 && V_380 && V_381 ) ) ) )
return - V_144 ;
memset ( V_255 , 0 , sizeof( * V_255 ) ) ;
V_255 -> V_40 = F_216 ( V_377 ) ;
#ifdef F_24
if ( V_255 -> V_40 != V_186 && V_255 -> V_40 != V_48 )
#else
if ( V_255 -> V_40 != V_186 )
#endif
return - V_383 ;
if ( V_379 ) {
V_255 -> V_59 = V_68 ;
V_255 -> V_53 = F_217 ( V_379 ) ;
} else {
V_255 -> V_59 = F_216 ( V_380 ) ;
F_218 ( & V_255 -> V_4 , V_381 , sizeof( V_255 -> V_4 ) ) ;
V_255 -> V_43 = F_219 ( V_378 ) ;
V_255 -> V_53 = 0 ;
}
F_56 () ;
if ( V_255 -> V_53 )
V_55 = F_38 ( V_15 , V_255 -> V_40 , V_255 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_255 -> V_40 , V_255 -> V_59 ,
& V_255 -> V_4 , V_255 -> V_43 ) ;
F_57 () ;
* V_374 = V_55 ;
if ( V_373 ) {
struct V_332 * V_384 , * V_385 , * V_386 , * V_387 ,
* V_388 ;
struct V_348 V_12 ;
V_384 = V_375 [ V_356 ] ;
V_386 = V_375 [ V_357 ] ;
V_385 = V_375 [ V_358 ] ;
V_387 = V_375 [ V_359 ] ;
V_388 = V_375 [ V_360 ] ;
if ( ! ( V_384 && V_385 && V_387 && V_388 ) )
return - V_144 ;
F_218 ( & V_12 , V_385 , sizeof( V_12 ) ) ;
if ( V_55 )
V_255 -> V_12 = V_55 -> V_12 ;
V_255 -> V_12 = ( V_255 -> V_12 & ~ V_12 . V_349 ) |
( V_12 . V_12 & V_12 . V_349 ) ;
V_255 -> V_175 = F_220 ( V_384 ) ;
V_255 -> V_177 = V_386 ? F_220 ( V_386 ) : NULL ;
V_255 -> V_181 = F_217 ( V_387 ) ;
V_255 -> V_180 = F_221 ( V_388 ) ;
}
return 0 ;
}
static struct V_54 * F_222 ( struct V_14 * V_15 ,
struct V_332 * V_372 )
{
struct V_170 V_255 ;
struct V_54 * V_55 ;
int V_156 ;
V_156 = F_214 ( V_15 , & V_255 , V_372 , 0 , & V_55 ) ;
return V_156 ? F_223 ( V_156 ) : V_55 ;
}
static int F_224 ( struct V_329 * V_330 , struct V_74 * V_75 )
{
struct V_332 * V_389 ;
struct V_100 V_239 ;
V_389 = F_196 ( V_330 , V_390 ) ;
if ( ! V_389 )
return - V_334 ;
if ( F_204 ( V_330 , V_391 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_205 ( V_330 , V_392 , V_75 -> V_43 ) ||
F_197 ( V_330 , V_393 ,
( F_15 ( & V_75 -> V_122 ) &
V_90 ) ) ||
F_197 ( V_330 , V_394 ,
F_15 ( & V_75 -> V_124 ) ) ||
F_197 ( V_330 , V_395 , V_75 -> V_129 ) ||
F_197 ( V_330 , V_396 , V_75 -> V_131 ) ||
F_197 ( V_330 , V_397 ,
F_15 ( & V_75 -> V_153 ) ) ||
F_197 ( V_330 , V_398 ,
F_15 ( & V_75 -> V_154 ) ) ||
F_197 ( V_330 , V_399 ,
F_15 ( & V_75 -> V_155 ) ) ||
F_203 ( V_330 , V_400 , V_75 -> V_40 ) )
goto V_346;
F_77 ( & V_239 , & V_75 -> V_76 ) ;
if ( F_195 ( V_330 , V_401 , & V_239 ) )
goto V_346;
if ( F_201 ( V_330 , V_402 , & V_239 ) )
goto V_346;
F_199 ( V_330 , V_389 ) ;
return 0 ;
V_346:
F_200 ( V_330 , V_389 ) ;
return - V_334 ;
}
static int F_225 ( struct V_329 * V_330 , struct V_74 * V_75 ,
struct V_363 * V_364 )
{
void * V_365 ;
V_365 = F_209 ( V_330 , F_210 ( V_364 -> V_330 ) . V_366 , V_364 -> V_367 -> V_368 ,
& V_369 , V_370 ,
V_403 ) ;
if ( ! V_365 )
return - V_334 ;
if ( F_224 ( V_330 , V_75 ) < 0 )
goto V_346;
F_211 ( V_330 , V_365 ) ;
return 0 ;
V_346:
F_212 ( V_330 , V_365 ) ;
return - V_334 ;
}
static int F_226 ( struct V_329 * V_330 ,
struct V_363 * V_364 )
{
int V_193 = 0 ;
int V_240 = V_364 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_332 * V_375 [ V_404 + 1 ] ;
struct V_2 * V_2 = F_179 ( V_330 -> V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
F_133 ( & V_197 ) ;
if ( F_227 ( V_364 -> V_367 , V_405 , V_375 ,
V_404 , V_406 ) )
goto V_176;
V_55 = F_222 ( V_15 , V_375 [ V_350 ] ) ;
if ( F_228 ( V_55 ) || V_55 == NULL )
goto V_176;
F_68 (dest, &svc->destinations, n_list) {
if ( ++ V_193 <= V_240 )
continue;
if ( F_225 ( V_330 , V_75 , V_364 ) < 0 ) {
V_193 -- ;
goto V_346;
}
}
V_346:
V_364 -> args [ 0 ] = V_193 ;
V_176:
F_134 ( & V_197 ) ;
return V_330 -> V_264 ;
}
static int F_229 ( struct V_116 * V_117 ,
struct V_332 * V_372 , int V_373 )
{
struct V_332 * V_375 [ V_407 + 1 ] ;
struct V_332 * V_381 , * V_378 ;
struct V_332 * V_408 ;
if ( V_372 == NULL ||
F_215 ( V_375 , V_407 , V_372 , V_409 ) )
return - V_144 ;
V_381 = V_375 [ V_391 ] ;
V_378 = V_375 [ V_392 ] ;
V_408 = V_375 [ V_400 ] ;
if ( ! ( V_381 && V_378 ) )
return - V_144 ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
F_218 ( & V_117 -> V_4 , V_381 , sizeof( V_117 -> V_4 ) ) ;
V_117 -> V_43 = F_219 ( V_378 ) ;
if ( V_408 )
V_117 -> V_40 = F_216 ( V_408 ) ;
else
V_117 -> V_40 = 0 ;
if ( V_373 ) {
struct V_332 * V_410 , * V_411 , * V_412 ,
* V_413 ;
V_410 = V_375 [ V_393 ] ;
V_411 = V_375 [ V_394 ] ;
V_412 = V_375 [ V_395 ] ;
V_413 = V_375 [ V_396 ] ;
if ( ! ( V_410 && V_411 && V_412 && V_413 ) )
return - V_144 ;
V_117 -> V_122 = F_217 ( V_410 )
& V_90 ;
V_117 -> V_124 = F_217 ( V_411 ) ;
V_117 -> V_129 = F_217 ( V_412 ) ;
V_117 -> V_131 = F_217 ( V_413 ) ;
}
return 0 ;
}
static int F_230 ( struct V_329 * V_330 , T_3 V_283 ,
struct V_278 * T_5 )
{
struct V_332 * V_414 ;
V_414 = F_196 ( V_330 , V_415 ) ;
if ( ! V_414 )
return - V_334 ;
if ( F_197 ( V_330 , V_416 , V_283 ) ||
F_206 ( V_330 , V_417 , T_5 -> V_280 ) ||
F_197 ( V_330 , V_418 , T_5 -> V_281 ) ||
F_203 ( V_330 , V_419 , T_5 -> V_420 ) ||
F_203 ( V_330 , V_421 , T_5 -> V_422 ) ||
F_231 ( V_330 , V_423 , T_5 -> V_424 ) )
goto V_346;
#ifdef F_24
if ( T_5 -> V_425 == V_48 ) {
if ( F_232 ( V_330 , V_426 ,
& T_5 -> V_427 . V_141 ) )
goto V_346;
} else
#endif
if ( T_5 -> V_425 == V_186 &&
F_233 ( V_330 , V_428 ,
T_5 -> V_427 . V_46 ) )
goto V_346;
F_199 ( V_330 , V_414 ) ;
return 0 ;
V_346:
F_200 ( V_330 , V_414 ) ;
return - V_334 ;
}
static int F_234 ( struct V_329 * V_330 , T_3 V_283 ,
struct V_278 * T_5 ,
struct V_363 * V_364 )
{
void * V_365 ;
V_365 = F_209 ( V_330 , F_210 ( V_364 -> V_330 ) . V_366 , V_364 -> V_367 -> V_368 ,
& V_369 , V_370 ,
V_429 ) ;
if ( ! V_365 )
return - V_334 ;
if ( F_230 ( V_330 , V_283 , T_5 ) )
goto V_346;
F_211 ( V_330 , V_365 ) ;
return 0 ;
V_346:
F_212 ( V_330 , V_365 ) ;
return - V_334 ;
}
static int F_235 ( struct V_329 * V_330 ,
struct V_363 * V_364 )
{
struct V_2 * V_2 = F_179 ( V_330 -> V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
F_133 ( & V_15 -> V_282 ) ;
if ( ( V_15 -> V_312 & V_313 ) && ! V_364 -> args [ 0 ] ) {
if ( F_234 ( V_330 , V_313 ,
& V_15 -> V_314 , V_364 ) < 0 )
goto V_346;
V_364 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_312 & V_315 ) && ! V_364 -> args [ 1 ] ) {
if ( F_234 ( V_330 , V_315 ,
& V_15 -> V_316 , V_364 ) < 0 )
goto V_346;
V_364 -> args [ 1 ] = 1 ;
}
V_346:
F_134 ( & V_15 -> V_282 ) ;
return V_330 -> V_264 ;
}
static int F_236 ( struct V_14 * V_15 , struct V_332 * * V_375 )
{
struct V_278 T_5 ;
struct V_332 * V_430 ;
int V_156 ;
memset ( & T_5 , 0 , sizeof( T_5 ) ) ;
if ( ! ( V_375 [ V_416 ] &&
V_375 [ V_417 ] &&
V_375 [ V_418 ] ) )
return - V_144 ;
F_184 ( T_5 . V_280 , F_220 ( V_375 [ V_417 ] ) ,
sizeof( T_5 . V_280 ) ) ;
T_5 . V_281 = F_217 ( V_375 [ V_418 ] ) ;
V_430 = V_375 [ V_419 ] ;
if ( V_430 )
T_5 . V_420 = F_216 ( V_430 ) ;
V_430 = V_375 [ V_428 ] ;
if ( V_430 ) {
T_5 . V_425 = V_186 ;
T_5 . V_427 . V_46 = F_237 ( V_430 ) ;
if ( ! F_238 ( T_5 . V_427 . V_46 ) )
return - V_144 ;
} else {
V_430 = V_375 [ V_426 ] ;
if ( V_430 ) {
#ifdef F_24
int V_431 ;
T_5 . V_425 = V_48 ;
T_5 . V_427 . V_141 = F_239 ( V_430 ) ;
V_431 = F_90 ( & T_5 . V_427 . V_141 ) ;
if ( ! ( V_431 & V_432 ) )
return - V_144 ;
#else
return - V_383 ;
#endif
}
}
V_430 = V_375 [ V_421 ] ;
if ( V_430 )
T_5 . V_422 = F_216 ( V_430 ) ;
V_430 = V_375 [ V_423 ] ;
if ( V_430 )
T_5 . V_424 = F_240 ( V_430 ) ;
if ( V_15 -> V_123 > 0 )
return - V_144 ;
F_185 () ;
F_133 ( & V_15 -> V_282 ) ;
V_156 = F_186 ( V_15 , & T_5 ,
F_217 ( V_375 [ V_416 ] ) ) ;
F_134 ( & V_15 -> V_282 ) ;
F_187 () ;
return V_156 ;
}
static int F_241 ( struct V_14 * V_15 , struct V_332 * * V_375 )
{
int V_156 ;
if ( ! V_375 [ V_416 ] )
return - V_144 ;
F_133 ( & V_15 -> V_282 ) ;
V_156 = F_188 ( V_15 ,
F_217 ( V_375 [ V_416 ] ) ) ;
F_134 ( & V_15 -> V_282 ) ;
return V_156 ;
}
static int F_242 ( struct V_14 * V_15 , struct V_332 * * V_375 )
{
struct V_242 V_328 ;
F_193 ( V_15 , & V_328 ) ;
if ( V_375 [ V_433 ] )
V_328 . V_247 = F_217 ( V_375 [ V_433 ] ) ;
if ( V_375 [ V_434 ] )
V_328 . V_248 =
F_217 ( V_375 [ V_434 ] ) ;
if ( V_375 [ V_435 ] )
V_328 . V_249 = F_217 ( V_375 [ V_435 ] ) ;
return F_173 ( V_15 , & V_328 ) ;
}
static int F_243 ( struct V_329 * V_330 , struct V_436 * V_321 )
{
int V_156 = - V_144 , V_262 ;
struct V_2 * V_2 = F_179 ( V_330 -> V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
V_262 = V_321 -> V_437 -> V_262 ;
if ( V_262 == V_429 || V_262 == V_438 ) {
struct V_332 * V_439 [ V_440 + 1 ] ;
if ( ! V_321 -> V_375 [ V_415 ] ||
F_215 ( V_439 , V_440 ,
V_321 -> V_375 [ V_415 ] ,
V_441 ) )
goto V_67;
if ( V_262 == V_429 )
V_156 = F_236 ( V_15 , V_439 ) ;
else
V_156 = F_241 ( V_15 , V_439 ) ;
}
V_67:
return V_156 ;
}
static int F_244 ( struct V_329 * V_330 , struct V_436 * V_321 )
{
struct V_54 * V_55 = NULL ;
struct V_170 V_255 ;
struct V_116 V_117 ;
int V_156 = 0 , V_262 ;
int V_442 = 0 , V_443 = 0 ;
struct V_2 * V_2 = F_179 ( V_330 -> V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
V_262 = V_321 -> V_437 -> V_262 ;
F_133 ( & V_197 ) ;
if ( V_262 == V_444 ) {
V_156 = F_130 ( V_15 , false ) ;
goto V_67;
} else if ( V_262 == V_445 ) {
V_156 = F_242 ( V_15 , V_321 -> V_375 ) ;
goto V_67;
} else if ( V_262 == V_446 &&
! V_321 -> V_375 [ V_350 ] ) {
V_156 = F_142 ( V_15 ) ;
goto V_67;
}
if ( V_262 == V_371 || V_262 == V_447 )
V_442 = 1 ;
V_156 = F_214 ( V_15 , & V_255 ,
V_321 -> V_375 [ V_350 ] ,
V_442 , & V_55 ) ;
if ( V_156 )
goto V_67;
if ( ( V_262 != V_371 ) && ( V_55 == NULL ) ) {
V_156 = - V_291 ;
goto V_67;
}
if ( V_262 == V_403 || V_262 == V_448 ||
V_262 == V_449 ) {
if ( V_262 != V_449 )
V_443 = 1 ;
V_156 = F_229 ( & V_117 ,
V_321 -> V_375 [ V_390 ] ,
V_443 ) ;
if ( V_156 )
goto V_67;
if ( V_117 . V_40 == 0 )
V_117 . V_40 = V_55 -> V_40 ;
if ( V_117 . V_40 != V_55 -> V_40 && V_262 != V_449 ) {
if ( V_15 -> V_312 ) {
V_156 = - V_144 ;
goto V_67;
}
switch ( V_117 . V_122 ) {
case V_218 :
break;
default:
V_156 = - V_144 ;
goto V_67;
}
}
}
switch ( V_262 ) {
case V_371 :
if ( V_55 == NULL )
V_156 = F_116 ( V_15 , & V_255 , & V_55 ) ;
else
V_156 = - V_158 ;
break;
case V_447 :
V_156 = F_125 ( V_55 , & V_255 ) ;
break;
case V_450 :
V_156 = F_129 ( V_55 ) ;
break;
case V_403 :
V_156 = F_101 ( V_55 , & V_117 ) ;
break;
case V_448 :
V_156 = F_103 ( V_55 , & V_117 ) ;
break;
case V_449 :
V_156 = F_112 ( V_55 , & V_117 ) ;
break;
case V_446 :
V_156 = F_141 ( V_55 ) ;
break;
default:
V_156 = - V_144 ;
}
V_67:
F_134 ( & V_197 ) ;
return V_156 ;
}
static int F_245 ( struct V_329 * V_330 , struct V_436 * V_321 )
{
struct V_329 * V_451 ;
void * V_452 ;
int V_156 , V_262 , V_453 ;
struct V_2 * V_2 = F_179 ( V_330 -> V_261 ) ;
struct V_14 * V_15 = F_139 ( V_2 ) ;
V_262 = V_321 -> V_437 -> V_262 ;
if ( V_262 == V_454 )
V_453 = V_371 ;
else if ( V_262 == V_455 )
V_453 = V_456 ;
else if ( V_262 == V_457 )
V_453 = V_445 ;
else {
F_28 ( L_59 ) ;
return - V_144 ;
}
V_451 = F_246 ( V_458 , V_147 ) ;
if ( ! V_451 )
return - V_148 ;
F_133 ( & V_197 ) ;
V_452 = F_247 ( V_451 , V_321 , & V_369 , 0 , V_453 ) ;
if ( V_452 == NULL )
goto V_346;
switch ( V_262 ) {
case V_454 :
{
struct V_54 * V_55 ;
V_55 = F_222 ( V_15 ,
V_321 -> V_375 [ V_350 ] ) ;
if ( F_228 ( V_55 ) ) {
V_156 = F_248 ( V_55 ) ;
goto V_176;
} else if ( V_55 ) {
V_156 = F_202 ( V_451 , V_55 ) ;
if ( V_156 )
goto V_346;
} else {
V_156 = - V_291 ;
goto V_176;
}
break;
}
case V_457 :
{
struct V_242 V_328 ;
F_193 ( V_15 , & V_328 ) ;
#ifdef V_243
if ( F_197 ( V_451 , V_433 ,
V_328 . V_247 ) ||
F_197 ( V_451 , V_434 ,
V_328 . V_248 ) )
goto V_346;
#endif
#ifdef V_244
if ( F_197 ( V_451 , V_435 , V_328 . V_249 ) )
goto V_346;
#endif
break;
}
case V_455 :
if ( F_197 ( V_451 , V_459 ,
V_231 ) ||
F_197 ( V_451 , V_460 ,
V_232 ) )
goto V_346;
break;
}
F_211 ( V_451 , V_452 ) ;
V_156 = F_249 ( V_451 , V_321 ) ;
goto V_67;
V_346:
F_28 ( L_60 ) ;
V_156 = - V_334 ;
V_176:
F_250 ( V_451 ) ;
V_67:
F_134 ( & V_197 ) ;
return V_156 ;
}
static int T_11 F_251 ( void )
{
return F_252 ( & V_369 ,
V_461 ) ;
}
static void F_253 ( void )
{
F_254 ( & V_369 ) ;
}
static int T_12 F_255 ( struct V_14 * V_15 )
{
struct V_2 * V_2 = V_15 -> V_2 ;
int V_193 ;
struct V_207 * V_462 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_99 ( & V_15 -> V_25 ) ;
F_99 ( & V_15 -> V_28 ) ;
F_99 ( & V_15 -> V_33 ) ;
if ( ! F_256 ( V_2 , & V_463 ) ) {
V_462 = F_257 ( V_464 , sizeof( V_464 ) , V_147 ) ;
if ( V_462 == NULL )
return - V_148 ;
if ( V_2 -> V_267 != & V_465 )
V_462 [ 0 ] . V_466 = NULL ;
} else
V_462 = V_464 ;
for ( V_193 = 0 ; V_193 < F_258 ( V_464 ) ; V_193 ++ ) {
if ( V_462 [ V_193 ] . V_467 == F_143 )
V_462 [ V_193 ] . V_213 = V_15 ;
}
V_193 = 0 ;
V_15 -> V_24 = 1024 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_32 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_26 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_29 ;
#ifdef F_259
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_468 ;
#endif
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_34 ;
V_15 -> V_469 = 1 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_469 ;
V_15 -> V_470 = 1 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_470 ;
V_15 -> V_471 = 1 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_471 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_472 ;
V_15 -> V_473 = F_260 () / 32 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_473 ;
V_15 -> V_474 = 0 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_474 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_475 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_476 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_477 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_478 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_479 ;
V_15 -> V_480 [ 0 ] = V_481 ;
V_15 -> V_480 [ 1 ] = V_482 ;
V_462 [ V_193 ] . V_167 = & V_15 -> V_480 ;
V_462 [ V_193 ++ ] . V_483 = sizeof( V_15 -> V_480 ) ;
V_15 -> V_484 = V_485 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_484 ;
V_15 -> V_486 = F_261 ( int , V_487 , 0 , 3 ) ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_486 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_488 ;
V_15 -> V_489 = 1 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_489 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_490 ;
V_15 -> V_491 = 1 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_491 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_492 ;
V_462 [ V_193 ++ ] . V_167 = & V_15 -> V_493 ;
V_15 -> V_494 = F_262 ( V_2 , L_61 , V_462 ) ;
if ( V_15 -> V_494 == NULL ) {
if ( ! F_256 ( V_2 , & V_463 ) )
F_47 ( V_462 ) ;
return - V_148 ;
}
F_86 ( V_15 , & V_15 -> V_206 ) ;
V_15 -> V_495 = V_462 ;
F_263 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_264 ( struct V_14 * V_15 )
{
struct V_2 * V_2 = V_15 -> V_2 ;
F_265 ( & V_15 -> V_37 ) ;
F_266 ( & V_15 -> V_37 . V_36 ) ;
F_267 ( V_15 -> V_494 ) ;
F_105 ( V_15 , & V_15 -> V_206 ) ;
if ( ! F_256 ( V_2 , & V_463 ) )
F_47 ( V_15 -> V_495 ) ;
}
static int T_12 F_255 ( struct V_14 * V_15 ) { return 0 ; }
static void T_13 F_264 ( struct V_14 * V_15 ) { }
int T_12 F_268 ( struct V_14 * V_15 )
{
int V_17 , V_193 ;
for ( V_193 = 0 ; V_193 < V_496 ; V_193 ++ )
F_269 ( & V_15 -> V_85 [ V_193 ] ) ;
F_120 ( & V_15 -> V_161 ) ;
F_99 ( & V_15 -> V_96 ) ;
F_270 ( & V_15 -> V_99 , F_113 ,
( unsigned long ) V_15 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
F_9 ( & V_15 -> V_185 , 0 ) ;
V_15 -> V_206 . V_77 = F_93 ( struct V_149 ) ;
if ( ! V_15 -> V_206 . V_77 )
return - V_148 ;
F_94 (i) {
struct V_149 * V_497 ;
V_497 = F_95 ( V_15 -> V_206 . V_77 , V_17 ) ;
F_96 ( & V_497 -> V_152 ) ;
}
F_99 ( & V_15 -> V_206 . V_103 ) ;
F_271 ( L_62 , 0 , V_15 -> V_2 -> V_498 , & V_499 ) ;
F_271 ( L_63 , 0 , V_15 -> V_2 -> V_498 , & V_500 ) ;
F_271 ( L_64 , 0 , V_15 -> V_2 -> V_498 ,
& V_501 ) ;
if ( F_255 ( V_15 ) )
goto V_502;
return 0 ;
V_502:
F_46 ( V_15 -> V_206 . V_77 ) ;
return - V_148 ;
}
void T_13 F_272 ( struct V_14 * V_15 )
{
F_74 ( V_15 ) ;
F_264 ( V_15 ) ;
F_273 ( L_64 , V_15 -> V_2 -> V_498 ) ;
F_273 ( L_63 , V_15 -> V_2 -> V_498 ) ;
F_273 ( L_62 , V_15 -> V_2 -> V_498 ) ;
F_46 ( V_15 -> V_206 . V_77 ) ;
}
int T_11 F_274 ( void )
{
int V_156 ;
V_156 = F_275 ( & V_503 ) ;
if ( V_156 ) {
F_28 ( L_65 ) ;
goto V_504;
}
V_156 = F_251 () ;
if ( V_156 ) {
F_28 ( L_66 ) ;
goto V_505;
}
return 0 ;
V_505:
F_276 ( & V_503 ) ;
V_504:
return V_156 ;
}
void F_277 ( void )
{
F_253 () ;
F_276 ( & V_503 ) ;
}
int T_11 F_278 ( void )
{
int V_193 ;
int V_156 ;
F_89 ( 2 ) ;
for ( V_193 = 0 ; V_193 < V_196 ; V_193 ++ ) {
F_269 ( & V_61 [ V_193 ] ) ;
F_269 ( & V_63 [ V_193 ] ) ;
}
F_279 () ;
V_156 = F_280 ( & V_506 ) ;
if ( V_156 < 0 )
return V_156 ;
F_100 ( 2 ) ;
return 0 ;
}
void F_281 ( void )
{
F_89 ( 2 ) ;
F_282 ( & V_506 ) ;
F_100 ( 2 ) ;
}
