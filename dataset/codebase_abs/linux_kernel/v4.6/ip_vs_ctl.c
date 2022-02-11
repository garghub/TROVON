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
static struct V_74 *
F_58 ( struct V_54 * V_55 , int V_88 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_74 * V_75 ;
F_59 (dest, &svc->destinations, n_list) {
if ( ( V_75 -> V_40 == V_88 ) &&
F_37 ( V_88 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_43 == V_86 ) ) {
return V_75 ;
}
}
return NULL ;
}
struct V_74 * F_60 ( struct V_14 * V_15 , int V_89 , int V_88 ,
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
V_75 = F_58 ( V_55 , V_88 , V_7 , V_43 ) ;
if ( ! V_75 )
V_75 = F_58 ( V_55 , V_88 , V_7 , V_43 ^ V_86 ) ;
return V_75 ;
}
void F_61 ( struct V_78 * V_79 )
{
struct V_92 * V_93 = F_14 ( V_79 ,
struct V_92 ,
V_78 ) ;
F_4 ( V_93 -> V_94 ) ;
F_47 ( V_93 ) ;
}
static void F_62 ( struct V_74 * V_75 )
{
struct V_92 * V_95 ;
V_95 = F_63 ( V_75 -> V_93 , 1 ) ;
if ( V_95 ) {
F_64 ( V_75 -> V_93 , NULL ) ;
F_51 ( & V_95 -> V_78 , F_61 ) ;
}
}
static struct V_74 *
F_65 ( struct V_54 * V_55 , int V_88 ,
const union V_42 * V_7 , T_1 V_86 )
{
struct V_74 * V_75 ;
struct V_14 * V_15 = V_55 -> V_15 ;
F_66 ( & V_15 -> V_96 ) ;
F_67 (dest, &ipvs->dest_trash, t_list) {
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
F_68 ( & V_75 -> V_97 ) ;
F_69 ( V_75 ) ;
goto V_67;
}
}
V_75 = NULL ;
V_67:
F_70 ( & V_15 -> V_96 ) ;
return V_75 ;
}
static void F_71 ( struct V_74 * V_75 )
{
struct V_54 * V_55 = F_63 ( V_75 -> V_55 , 1 ) ;
F_62 ( V_75 ) ;
F_49 ( V_55 , false ) ;
F_46 ( V_75 -> V_76 . V_77 ) ;
F_72 ( V_75 ) ;
}
static void F_73 ( struct V_14 * V_15 )
{
struct V_74 * V_75 , * V_98 ;
F_74 ( & V_15 -> V_99 ) ;
F_75 (dest, nxt, &ipvs->dest_trash, t_list) {
F_68 ( & V_75 -> V_97 ) ;
F_71 ( V_75 ) ;
}
}
static void
F_76 ( struct V_100 * V_9 , struct V_101 * V_102 )
{
#define F_77 ( T_5 ) dst->c = src->kstats.c - src->kstats0.c
F_66 ( & V_102 -> V_103 ) ;
F_77 ( V_104 ) ;
F_77 ( V_105 ) ;
F_77 ( V_106 ) ;
F_77 ( V_107 ) ;
F_77 ( V_108 ) ;
F_78 ( V_9 , V_102 ) ;
F_70 ( & V_102 -> V_103 ) ;
}
static void
F_79 ( struct V_109 * V_9 , struct V_100 * V_102 )
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
F_80 ( struct V_101 * V_76 )
{
F_66 ( & V_76 -> V_103 ) ;
#define F_81 ( T_5 ) stats->kstats0.c = stats->kstats.c
F_81 ( V_104 ) ;
F_81 ( V_105 ) ;
F_81 ( V_106 ) ;
F_81 ( V_107 ) ;
F_81 ( V_108 ) ;
F_82 ( V_76 ) ;
F_70 ( & V_76 -> V_103 ) ;
}
static void
F_83 ( struct V_54 * V_55 , struct V_74 * V_75 ,
struct V_116 * V_117 , int V_118 )
{
struct V_14 * V_15 = V_55 -> V_15 ;
struct V_54 * V_119 ;
struct V_120 * V_121 ;
int V_122 ;
F_84 ( ! V_118 && V_117 -> V_40 != V_75 -> V_40 ) ;
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
V_119 = F_63 ( V_75 -> V_55 , 1 ) ;
if ( ! V_119 ) {
F_43 ( V_75 , V_55 ) ;
} else {
if ( V_119 != V_55 ) {
F_80 ( & V_75 -> V_76 ) ;
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
F_66 ( & V_75 -> V_132 ) ;
F_62 ( V_75 ) ;
F_70 ( & V_75 -> V_132 ) ;
if ( V_118 ) {
F_85 ( V_55 -> V_15 , & V_75 -> V_76 ) ;
F_86 ( & V_75 -> V_133 , & V_55 -> V_134 ) ;
V_55 -> V_135 ++ ;
V_121 = F_63 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_137 )
V_121 -> V_137 ( V_55 , V_75 ) ;
} else {
V_121 = F_63 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_138 )
V_121 -> V_138 ( V_55 , V_75 ) ;
}
}
static int
F_87 ( struct V_54 * V_55 , struct V_116 * V_117 ,
struct V_74 * * V_139 )
{
struct V_74 * V_75 ;
unsigned int V_140 , V_17 ;
F_88 ( 2 ) ;
#ifdef F_24
if ( V_117 -> V_40 == V_48 ) {
V_140 = F_89 ( & V_117 -> V_4 . V_141 ) ;
if ( ( ! ( V_140 & V_142 ) ||
V_140 & V_143 ) &&
! F_2 ( V_55 -> V_15 -> V_2 , & V_117 -> V_4 . V_141 ) )
return - V_144 ;
} else
#endif
{
V_140 = F_90 ( V_55 -> V_15 -> V_2 , V_117 -> V_4 . V_46 ) ;
if ( V_140 != V_145 && V_140 != V_146 )
return - V_144 ;
}
V_75 = F_91 ( sizeof( struct V_74 ) , V_147 ) ;
if ( V_75 == NULL )
return - V_148 ;
V_75 -> V_76 . V_77 = F_92 ( struct V_149 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_150;
F_93 (i) {
struct V_149 * V_151 ;
V_151 = F_94 ( V_75 -> V_76 . V_77 , V_17 ) ;
F_95 ( & V_151 -> V_152 ) ;
}
V_75 -> V_40 = V_117 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_87 = V_55 -> V_53 ;
F_96 ( V_117 -> V_40 , & V_75 -> V_4 , & V_117 -> V_4 ) ;
V_75 -> V_43 = V_117 -> V_43 ;
F_9 ( & V_75 -> V_153 , 0 ) ;
F_9 ( & V_75 -> V_154 , 0 ) ;
F_9 ( & V_75 -> V_155 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_97 ( & V_75 -> V_84 ) ;
F_98 ( & V_75 -> V_132 ) ;
F_98 ( & V_75 -> V_76 . V_103 ) ;
F_83 ( V_55 , V_75 , V_117 , 1 ) ;
* V_139 = V_75 ;
F_99 ( 2 ) ;
return 0 ;
V_150:
F_47 ( V_75 ) ;
return - V_148 ;
}
static int
F_100 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_117 -> V_43 ;
int V_156 ;
F_88 ( 2 ) ;
if ( V_117 -> V_124 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_157 ;
}
if ( V_117 -> V_131 > V_117 -> V_129 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_157 ;
}
F_96 ( V_117 -> V_40 , & V_7 , & V_117 -> V_4 ) ;
F_56 () ;
V_75 = F_58 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
F_57 () ;
if ( V_75 != NULL ) {
F_101 ( 1 , L_11 , V_58 ) ;
return - V_158 ;
}
V_75 = F_65 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
if ( V_75 != NULL ) {
F_40 ( 3 , L_12
L_13 ,
F_42 ( V_117 -> V_40 , & V_7 ) , F_23 ( V_86 ) ,
F_15 ( & V_75 -> V_64 ) ,
V_75 -> V_87 ,
F_42 ( V_55 -> V_40 , & V_75 -> V_65 ) ,
F_23 ( V_75 -> V_66 ) ) ;
F_83 ( V_55 , V_75 , V_117 , 1 ) ;
V_156 = 0 ;
} else {
V_156 = F_87 ( V_55 , V_117 , & V_75 ) ;
}
F_99 ( 2 ) ;
return V_156 ;
}
static int
F_102 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_117 -> V_43 ;
F_88 ( 2 ) ;
if ( V_117 -> V_124 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_157 ;
}
if ( V_117 -> V_131 > V_117 -> V_129 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_157 ;
}
F_96 ( V_117 -> V_40 , & V_7 , & V_117 -> V_4 ) ;
F_56 () ;
V_75 = F_58 ( V_55 , V_117 -> V_40 , & V_7 , V_86 ) ;
F_57 () ;
if ( V_75 == NULL ) {
F_101 ( 1 , L_14 , V_58 ) ;
return - V_159 ;
}
F_83 ( V_55 , V_75 , V_117 , 0 ) ;
F_99 ( 2 ) ;
return 0 ;
}
static void F_103 ( struct V_14 * V_15 , struct V_74 * V_75 ,
bool V_160 )
{
F_104 ( V_15 , & V_75 -> V_76 ) ;
F_54 ( V_75 ) ;
F_66 ( & V_15 -> V_96 ) ;
F_40 ( 3 , L_15 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_105 ( & V_15 -> V_161 ) && ! V_160 )
F_106 ( & V_15 -> V_99 ,
V_162 + ( V_163 >> 1 ) ) ;
F_107 ( & V_75 -> V_97 , & V_15 -> V_161 ) ;
V_75 -> V_164 = 0 ;
F_70 ( & V_15 -> V_96 ) ;
F_108 ( V_75 ) ;
}
static void F_109 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_165 )
{
V_75 -> V_12 &= ~ V_128 ;
F_110 ( & V_75 -> V_133 ) ;
V_55 -> V_135 -- ;
if ( V_75 -> V_40 != V_55 -> V_40 )
V_55 -> V_15 -> V_123 -- ;
if ( V_165 ) {
struct V_120 * V_121 ;
V_121 = F_63 ( V_55 -> V_136 , 1 ) ;
if ( V_121 && V_121 -> V_166 )
V_121 -> V_166 ( V_55 , V_75 ) ;
}
}
static int
F_111 ( struct V_54 * V_55 , struct V_116 * V_117 )
{
struct V_74 * V_75 ;
T_1 V_86 = V_117 -> V_43 ;
F_88 ( 2 ) ;
F_56 () ;
V_75 = F_58 ( V_55 , V_117 -> V_40 , & V_117 -> V_4 , V_86 ) ;
F_57 () ;
if ( V_75 == NULL ) {
F_101 ( 1 , L_16 , V_58 ) ;
return - V_159 ;
}
F_109 ( V_55 , V_75 , 1 ) ;
F_103 ( V_55 -> V_15 , V_75 , false ) ;
F_99 ( 2 ) ;
return 0 ;
}
static void F_112 ( unsigned long V_167 )
{
struct V_14 * V_15 = (struct V_14 * ) V_167 ;
struct V_74 * V_75 , * V_168 ;
unsigned long V_169 = V_162 ;
F_8 ( & V_15 -> V_96 ) ;
F_75 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
if ( V_75 -> V_164 ) {
if ( F_113 ( V_169 , V_75 -> V_164 +
V_163 ) )
continue;
} else {
V_75 -> V_164 = F_114 ( 1UL , V_169 ) ;
continue;
}
F_40 ( 3 , L_17 ,
V_75 -> V_87 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_68 ( & V_75 -> V_97 ) ;
F_71 ( V_75 ) ;
}
if ( ! F_105 ( & V_15 -> V_161 ) )
F_106 ( & V_15 -> V_99 ,
V_162 + ( V_163 >> 1 ) ) ;
F_10 ( & V_15 -> V_96 ) ;
}
static int
F_115 ( struct V_14 * V_15 , struct V_170 * V_171 ,
struct V_54 * * V_172 )
{
int V_156 = 0 , V_17 ;
struct V_120 * V_121 = NULL ;
struct V_173 * V_174 = NULL ;
struct V_54 * V_55 = NULL ;
F_18 () ;
if ( strcmp ( V_171 -> V_175 , L_18 ) ) {
V_121 = F_116 ( V_171 -> V_175 ) ;
if ( ! V_121 ) {
F_117 ( L_19 ,
V_171 -> V_175 ) ;
V_156 = - V_159 ;
goto V_176;
}
}
if ( V_171 -> V_177 && * V_171 -> V_177 ) {
V_174 = F_118 ( V_171 -> V_177 ) ;
if ( V_174 == NULL ) {
F_117 ( L_20
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
V_55 = F_91 ( sizeof( struct V_54 ) , V_147 ) ;
if ( V_55 == NULL ) {
F_101 ( 1 , L_22 , V_58 ) ;
V_156 = - V_148 ;
goto V_176;
}
V_55 -> V_76 . V_77 = F_92 ( struct V_149 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_156 = - V_148 ;
goto V_176;
}
F_93 (i) {
struct V_149 * V_101 ;
V_101 = F_94 ( V_55 -> V_76 . V_77 , V_17 ) ;
F_95 ( & V_101 -> V_152 ) ;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_171 -> V_40 ;
V_55 -> V_59 = V_171 -> V_59 ;
F_96 ( V_55 -> V_40 , & V_55 -> V_4 , & V_171 -> V_4 ) ;
V_55 -> V_43 = V_171 -> V_43 ;
V_55 -> V_53 = V_171 -> V_53 ;
V_55 -> V_12 = V_171 -> V_12 ;
V_55 -> V_181 = V_171 -> V_181 * V_182 ;
V_55 -> V_180 = V_171 -> V_180 ;
V_55 -> V_15 = V_15 ;
F_119 ( & V_55 -> V_134 ) ;
F_98 ( & V_55 -> V_183 ) ;
F_98 ( & V_55 -> V_76 . V_103 ) ;
if ( V_121 ) {
V_156 = F_120 ( V_55 , V_121 ) ;
if ( V_156 )
goto V_176;
V_121 = NULL ;
}
F_64 ( V_55 -> V_174 , V_174 ) ;
V_174 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_85 ( V_15 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_184 )
V_15 -> V_185 ++ ;
F_27 ( V_55 ) ;
* V_172 = V_55 ;
V_15 -> V_186 = 1 ;
return 0 ;
V_176:
if ( V_55 != NULL ) {
F_121 ( V_55 , V_121 ) ;
F_45 ( V_55 ) ;
}
F_122 ( V_121 ) ;
F_123 ( V_174 ) ;
F_20 () ;
return V_156 ;
}
static int
F_124 ( struct V_54 * V_55 , struct V_170 * V_171 )
{
struct V_120 * V_121 = NULL , * V_187 ;
struct V_173 * V_174 = NULL , * V_188 = NULL ;
int V_156 = 0 ;
if ( strcmp ( V_171 -> V_175 , L_18 ) ) {
V_121 = F_116 ( V_171 -> V_175 ) ;
if ( ! V_121 ) {
F_117 ( L_19 ,
V_171 -> V_175 ) ;
return - V_159 ;
}
}
V_187 = V_121 ;
if ( V_171 -> V_177 && * V_171 -> V_177 ) {
V_174 = F_118 ( V_171 -> V_177 ) ;
if ( V_174 == NULL ) {
F_117 ( L_20
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
V_187 = F_63 ( V_55 -> V_136 , 1 ) ;
if ( V_121 != V_187 ) {
if ( V_187 ) {
F_121 ( V_55 , V_187 ) ;
F_64 ( V_55 -> V_136 , NULL ) ;
F_125 () ;
}
if ( V_121 ) {
V_156 = F_120 ( V_55 , V_121 ) ;
if ( V_156 ) {
F_122 ( V_121 ) ;
goto V_67;
}
}
}
V_55 -> V_12 = V_171 -> V_12 | V_57 ;
V_55 -> V_181 = V_171 -> V_181 * V_182 ;
V_55 -> V_180 = V_171 -> V_180 ;
V_188 = F_63 ( V_55 -> V_174 , 1 ) ;
if ( V_174 != V_188 )
F_44 ( V_55 -> V_174 , V_174 ) ;
V_67:
F_122 ( V_187 ) ;
F_123 ( V_188 ) ;
return V_156 ;
}
static void F_126 ( struct V_54 * V_55 , bool V_160 )
{
struct V_74 * V_75 , * V_98 ;
struct V_120 * V_187 ;
struct V_173 * V_188 ;
struct V_14 * V_15 = V_55 -> V_15 ;
if ( V_55 -> V_40 == V_184 )
V_15 -> V_185 -- ;
F_104 ( V_55 -> V_15 , & V_55 -> V_76 ) ;
V_187 = F_63 ( V_55 -> V_136 , 1 ) ;
F_121 ( V_55 , V_187 ) ;
F_122 ( V_187 ) ;
V_188 = F_63 ( V_55 -> V_174 , 1 ) ;
F_123 ( V_188 ) ;
F_75 (dest, nxt, &svc->destinations, n_list) {
F_109 ( V_55 , V_75 , 0 ) ;
F_103 ( V_55 -> V_15 , V_75 , V_160 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
F_49 ( V_55 , true ) ;
F_20 () ;
}
static void F_127 ( struct V_54 * V_55 , bool V_160 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_126 ( V_55 , V_160 ) ;
}
static int F_128 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_158 ;
F_127 ( V_55 , false ) ;
return 0 ;
}
static int F_129 ( struct V_14 * V_15 , bool V_160 )
{
int V_189 ;
struct V_54 * V_55 ;
struct V_190 * V_191 ;
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_130 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( V_55 -> V_15 == V_15 )
F_127 ( V_55 , V_160 ) ;
}
}
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_130 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( V_55 -> V_15 == V_15 )
F_127 ( V_55 , V_160 ) ;
}
}
return 0 ;
}
void F_131 ( struct V_14 * V_15 )
{
F_88 ( 2 ) ;
F_132 ( & V_193 ) ;
F_129 ( V_15 , true ) ;
F_133 ( & V_193 ) ;
F_99 ( 2 ) ;
}
static inline void
F_134 ( struct V_74 * V_75 , struct V_194 * V_11 )
{
struct V_92 * V_93 ;
F_66 ( & V_75 -> V_132 ) ;
V_93 = F_63 ( V_75 -> V_93 , 1 ) ;
if ( V_93 && V_93 -> V_94 -> V_11 == V_11 ) {
F_40 ( 3 , L_23 ,
V_11 -> V_195 ,
F_42 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_62 ( V_75 ) ;
}
F_70 ( & V_75 -> V_132 ) ;
}
static int F_135 ( struct V_196 * V_197 , unsigned long V_198 ,
void * V_199 )
{
struct V_194 * V_11 = F_136 ( V_199 ) ;
struct V_2 * V_2 = F_137 ( V_11 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_189 ;
if ( V_198 != V_200 || ! V_15 )
return V_201 ;
F_101 ( 3 , L_24 , V_58 , V_11 -> V_195 ) ;
F_88 ( 2 ) ;
F_132 ( & V_193 ) ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_139 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_15 == V_15 ) {
F_67 (dest, &svc->destinations,
n_list) {
F_134 ( V_75 , V_11 ) ;
}
}
}
F_139 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_15 == V_15 ) {
F_67 (dest, &svc->destinations,
n_list) {
F_134 ( V_75 , V_11 ) ;
}
}
}
}
F_66 ( & V_15 -> V_96 ) ;
F_67 (dest, &ipvs->dest_trash, t_list) {
F_134 ( V_75 , V_11 ) ;
}
F_70 ( & V_15 -> V_96 ) ;
F_133 ( & V_193 ) ;
F_99 ( 2 ) ;
return V_201 ;
}
static int F_140 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_67 (dest, &svc->destinations, n_list) {
F_80 ( & V_75 -> V_76 ) ;
}
F_80 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_141 ( struct V_14 * V_15 )
{
int V_189 ;
struct V_54 * V_55 ;
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_139 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_15 == V_15 )
F_140 ( V_55 ) ;
}
}
for( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_139 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_15 == V_15 )
F_140 ( V_55 ) ;
}
}
F_80 ( & V_15 -> V_202 ) ;
return 0 ;
}
static int
F_142 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
struct V_14 * V_15 = V_204 -> V_209 ;
int * V_210 = V_204 -> V_167 ;
int V_211 = * V_210 ;
int V_212 ;
V_212 = F_143 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( * V_210 != V_211 ) ) {
if ( ( * V_210 < 0 ) || ( * V_210 > 3 ) ) {
* V_210 = V_211 ;
} else {
F_5 ( V_15 ) ;
}
}
return V_212 ;
}
static int
F_144 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
int * V_210 = V_204 -> V_167 ;
int V_211 [ 2 ] ;
int V_212 ;
memcpy ( V_211 , V_210 , sizeof( V_211 ) ) ;
V_212 = F_143 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( V_210 [ 0 ] < 0 || V_210 [ 1 ] < 0 ||
( V_210 [ 0 ] >= V_210 [ 1 ] && V_210 [ 1 ] ) ) ) {
memcpy ( V_210 , V_211 , sizeof( V_211 ) ) ;
}
return V_212 ;
}
static int
F_145 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
int * V_210 = V_204 -> V_167 ;
int V_211 = * V_210 ;
int V_212 ;
V_212 = F_143 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( * V_210 != V_211 ) ) {
if ( ( * V_210 < 0 ) || ( * V_210 > 1 ) ) {
* V_210 = V_211 ;
}
}
return V_212 ;
}
static int
F_146 ( struct V_203 * V_204 , int V_205 ,
void T_6 * V_206 , V_50 * V_207 , T_7 * V_208 )
{
int * V_210 = V_204 -> V_167 ;
int V_211 = * V_210 ;
int V_212 ;
V_212 = F_143 ( V_204 , V_205 , V_206 , V_207 , V_208 ) ;
if ( V_205 && ( * V_210 != V_211 ) ) {
if ( * V_210 < 1 || ! F_147 ( * V_210 ) ) {
* V_210 = V_211 ;
}
}
return V_212 ;
}
static inline const char * F_148 ( unsigned int V_12 )
{
switch ( V_12 & V_90 ) {
case V_213 :
return L_25 ;
case V_214 :
return L_26 ;
case V_215 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_149 ( struct V_216 * V_217 , T_7 V_218 )
{
struct V_2 * V_2 = F_150 ( V_217 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
struct V_219 * V_220 = V_217 -> V_221 ;
int V_189 ;
struct V_54 * V_55 ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( ( V_55 -> V_15 == V_15 ) && V_218 -- == 0 ) {
V_220 -> V_204 = V_61 ;
V_220 -> V_222 = V_189 ;
return V_55 ;
}
}
}
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( ( V_55 -> V_15 == V_15 ) && V_218 -- == 0 ) {
V_220 -> V_204 = V_63 ;
V_220 -> V_222 = V_189 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_151 ( struct V_216 * V_217 , T_7 * V_218 )
__acquires( T_8 )
{
F_56 () ;
return * V_218 ? F_149 ( V_217 , * V_218 - 1 ) : V_223 ;
}
static void * F_152 ( struct V_216 * V_217 , void * V_224 , T_7 * V_218 )
{
struct V_190 * V_225 ;
struct V_219 * V_220 ;
struct V_54 * V_55 ;
++ * V_218 ;
if ( V_224 == V_223 )
return F_149 ( V_217 , 0 ) ;
V_55 = V_224 ;
V_220 = V_217 -> V_221 ;
if ( V_220 -> V_204 == V_61 ) {
V_225 = F_153 ( F_154 ( & V_55 -> V_60 ) ) ;
if ( V_225 )
return F_155 ( V_225 , struct V_54 , V_60 ) ;
while ( ++ V_220 -> V_222 < V_192 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_220 -> V_204 = V_63 ;
V_220 -> V_222 = - 1 ;
goto V_226;
}
V_225 = F_153 ( F_154 ( & V_55 -> V_62 ) ) ;
if ( V_225 )
return F_155 ( V_225 , struct V_54 , V_62 ) ;
V_226:
while ( ++ V_220 -> V_222 < V_192 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_156 ( struct V_216 * V_217 , void * V_224 )
__releases( T_8 )
{
F_57 () ;
}
static int F_157 ( struct V_216 * V_217 , void * V_224 )
{
if ( V_224 == V_223 ) {
F_158 ( V_217 ,
L_29 ,
F_159 ( V_227 ) , V_228 ) ;
F_160 ( V_217 ,
L_30 ) ;
F_160 ( V_217 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_224 ;
const struct V_219 * V_220 = V_217 -> V_221 ;
const struct V_74 * V_75 ;
struct V_120 * V_121 = F_153 ( V_55 -> V_136 ) ;
char * V_175 = V_121 ? V_121 -> V_195 : L_18 ;
if ( V_220 -> V_204 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_158 ( V_217 , L_32 ,
F_41 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_141 ,
F_23 ( V_55 -> V_43 ) ,
V_175 ) ;
else
#endif
F_158 ( V_217 , L_33 ,
F_41 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_175 ,
( V_55 -> V_12 & V_229 ) ? L_34 : L_35 ) ;
} else {
F_158 ( V_217 , L_36 ,
V_55 -> V_53 , V_175 ,
( V_55 -> V_12 & V_229 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_230 )
F_158 ( V_217 , L_37 ,
V_55 -> V_181 ,
F_25 ( V_55 -> V_180 ) ) ;
else
F_161 ( V_217 , '\n' ) ;
F_59 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_158 ( V_217 ,
L_38
L_39 ,
& V_75 -> V_4 . V_141 ,
F_23 ( V_75 -> V_43 ) ,
F_148 ( F_15 ( & V_75 -> V_122 ) ) ,
F_15 ( & V_75 -> V_124 ) ,
F_15 ( & V_75 -> V_153 ) ,
F_15 ( & V_75 -> V_154 ) ) ;
else
#endif
F_158 ( V_217 ,
L_40
L_41 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_148 ( F_15 ( & V_75 -> V_122 ) ) ,
F_15 ( & V_75 -> V_124 ) ,
F_15 ( & V_75 -> V_153 ) ,
F_15 ( & V_75 -> V_154 ) ) ;
}
}
return 0 ;
}
static int F_162 ( struct V_231 * V_231 , struct V_232 * V_232 )
{
return F_163 ( V_231 , V_232 , & V_233 ,
sizeof( struct V_219 ) ) ;
}
static int F_164 ( struct V_216 * V_217 , void * V_224 )
{
struct V_2 * V_2 = F_165 ( V_217 ) ;
struct V_100 V_234 ;
F_160 ( V_217 ,
L_42 ) ;
F_158 ( V_217 ,
L_43 ) ;
F_76 ( & V_234 , & F_138 ( V_2 ) -> V_202 ) ;
F_158 ( V_217 , L_44 ,
( unsigned long long ) V_234 . V_104 ,
( unsigned long long ) V_234 . V_105 ,
( unsigned long long ) V_234 . V_106 ,
( unsigned long long ) V_234 . V_107 ,
( unsigned long long ) V_234 . V_108 ) ;
F_160 ( V_217 ,
L_45 ) ;
F_158 ( V_217 , L_46 ,
( unsigned long long ) V_234 . V_111 ,
( unsigned long long ) V_234 . V_112 ,
( unsigned long long ) V_234 . V_113 ,
( unsigned long long ) V_234 . V_114 ,
( unsigned long long ) V_234 . V_115 ) ;
return 0 ;
}
static int F_166 ( struct V_231 * V_231 , struct V_232 * V_232 )
{
return F_167 ( V_231 , V_232 , F_164 ) ;
}
static int F_168 ( struct V_216 * V_217 , void * V_224 )
{
struct V_2 * V_2 = F_165 ( V_217 ) ;
struct V_101 * V_202 = & F_138 ( V_2 ) -> V_202 ;
struct V_149 T_9 * V_77 = V_202 -> V_77 ;
struct V_100 V_235 ;
int V_17 ;
F_160 ( V_217 ,
L_47 ) ;
F_158 ( V_217 ,
L_48 ) ;
F_93 (i) {
struct V_149 * V_171 = F_94 ( V_77 , V_17 ) ;
unsigned int V_236 ;
T_10 V_104 , V_105 , V_106 , V_107 , V_108 ;
do {
V_236 = F_169 ( & V_171 -> V_152 ) ;
V_104 = V_171 -> V_237 . V_104 ;
V_105 = V_171 -> V_237 . V_105 ;
V_106 = V_171 -> V_237 . V_106 ;
V_107 = V_171 -> V_237 . V_107 ;
V_108 = V_171 -> V_237 . V_108 ;
} while ( F_170 ( & V_171 -> V_152 , V_236 ) );
F_158 ( V_217 , L_49 ,
V_17 , ( T_10 ) V_104 , ( T_10 ) V_105 ,
( T_10 ) V_106 , ( T_10 ) V_107 ,
( T_10 ) V_108 ) ;
}
F_76 ( & V_235 , V_202 ) ;
F_158 ( V_217 , L_50 ,
( unsigned long long ) V_235 . V_104 ,
( unsigned long long ) V_235 . V_105 ,
( unsigned long long ) V_235 . V_106 ,
( unsigned long long ) V_235 . V_107 ,
( unsigned long long ) V_235 . V_108 ) ;
F_160 ( V_217 ,
L_51 ) ;
F_158 ( V_217 , L_52 ,
V_235 . V_111 ,
V_235 . V_112 ,
V_235 . V_113 ,
V_235 . V_114 ,
V_235 . V_115 ) ;
return 0 ;
}
static int F_171 ( struct V_231 * V_231 , struct V_232 * V_232 )
{
return F_167 ( V_231 , V_232 , F_168 ) ;
}
static int F_172 ( struct V_14 * V_15 , struct V_238 * V_171 )
{
#if F_173 ( V_239 ) || F_173 ( V_240 )
struct V_241 * V_242 ;
#endif
F_101 ( 2 , L_53 ,
V_171 -> V_243 ,
V_171 -> V_244 ,
V_171 -> V_245 ) ;
#ifdef V_239
if ( V_171 -> V_243 ) {
V_242 = F_174 ( V_15 , V_68 ) ;
V_242 -> V_246 [ V_247 ]
= V_171 -> V_243 * V_182 ;
}
if ( V_171 -> V_244 ) {
V_242 = F_174 ( V_15 , V_68 ) ;
V_242 -> V_246 [ V_248 ]
= V_171 -> V_244 * V_182 ;
}
#endif
#ifdef V_240
if ( V_171 -> V_245 ) {
V_242 = F_174 ( V_15 , V_249 ) ;
V_242 -> V_246 [ V_250 ]
= V_171 -> V_245 * V_182 ;
}
#endif
return 0 ;
}
static void F_175 ( struct V_170 * V_251 ,
struct V_252 * V_253 )
{
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_40 = V_184 ;
V_251 -> V_59 = V_253 -> V_59 ;
V_251 -> V_4 . V_46 = V_253 -> V_4 ;
V_251 -> V_43 = V_253 -> V_43 ;
V_251 -> V_53 = V_253 -> V_53 ;
V_251 -> V_175 = V_253 -> V_175 ;
V_251 -> V_12 = V_253 -> V_12 ;
V_251 -> V_181 = V_253 -> V_181 ;
V_251 -> V_180 = V_253 -> V_180 ;
}
static void F_176 ( struct V_116 * V_117 ,
struct V_254 * V_255 )
{
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
V_117 -> V_4 . V_46 = V_255 -> V_4 ;
V_117 -> V_43 = V_255 -> V_43 ;
V_117 -> V_122 = V_255 -> V_122 ;
V_117 -> V_124 = V_255 -> V_124 ;
V_117 -> V_129 = V_255 -> V_129 ;
V_117 -> V_131 = V_255 -> V_131 ;
V_117 -> V_40 = V_184 ;
}
static int
F_177 ( struct V_256 * V_257 , int V_258 , void T_6 * V_259 , unsigned int V_260 )
{
struct V_2 * V_2 = F_178 ( V_257 ) ;
int V_156 ;
unsigned char V_261 [ V_262 ] ;
struct V_252 * V_253 ;
struct V_170 V_251 ;
struct V_54 * V_55 ;
struct V_254 * V_255 ;
struct V_116 V_117 ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
F_179 ( sizeof( V_261 ) > 255 ) ;
if ( ! F_180 ( F_178 ( V_257 ) -> V_263 , V_264 ) )
return - V_265 ;
if ( V_258 < V_266 || V_258 > V_267 )
return - V_144 ;
if ( V_260 != V_268 [ F_181 ( V_258 ) ] ) {
F_101 ( 1 , L_54 ,
V_260 , V_268 [ F_181 ( V_258 ) ] ) ;
return - V_144 ;
}
if ( F_182 ( V_261 , V_259 , V_260 ) != 0 )
return - V_269 ;
F_18 () ;
if ( V_258 == V_270 ||
V_258 == V_271 ) {
struct V_272 * V_273 = (struct V_272 * ) V_261 ;
if ( V_258 == V_270 ) {
struct V_274 V_275 ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
F_183 ( V_275 . V_276 , V_273 -> V_276 ,
sizeof( V_275 . V_276 ) ) ;
V_275 . V_277 = V_273 -> V_277 ;
F_184 () ;
F_132 ( & V_15 -> V_278 ) ;
V_156 = F_185 ( V_15 , & V_275 , V_273 -> V_279 ) ;
F_133 ( & V_15 -> V_278 ) ;
F_186 () ;
} else {
F_132 ( & V_15 -> V_278 ) ;
V_156 = F_187 ( V_15 , V_273 -> V_279 ) ;
F_133 ( & V_15 -> V_278 ) ;
}
goto V_280;
}
F_132 ( & V_193 ) ;
if ( V_258 == V_281 ) {
V_156 = F_129 ( V_15 , false ) ;
goto V_282;
} else if ( V_258 == V_283 ) {
V_156 = F_172 ( V_15 , (struct V_238 * ) V_261 ) ;
goto V_282;
}
V_253 = (struct V_252 * ) V_261 ;
V_255 = (struct V_254 * ) ( V_253 + 1 ) ;
F_175 ( & V_251 , V_253 ) ;
F_176 ( & V_117 , V_255 ) ;
if ( V_258 == V_284 ) {
if ( ! V_251 . V_53 && ! V_251 . V_4 . V_46 && ! V_251 . V_43 ) {
V_156 = F_141 ( V_15 ) ;
goto V_282;
}
}
if ( V_251 . V_59 != V_68 && V_251 . V_59 != V_249 &&
V_251 . V_59 != V_285 ) {
F_28 ( L_55 ,
V_251 . V_59 , & V_251 . V_4 . V_46 ,
F_23 ( V_251 . V_43 ) , V_251 . V_175 ) ;
V_156 = - V_269 ;
goto V_282;
}
F_56 () ;
if ( V_251 . V_53 == 0 )
V_55 = F_35 ( V_15 , V_251 . V_40 , V_251 . V_59 ,
& V_251 . V_4 , V_251 . V_43 ) ;
else
V_55 = F_38 ( V_15 , V_251 . V_40 , V_251 . V_53 ) ;
F_57 () ;
if ( V_258 != V_286
&& ( V_55 == NULL || V_55 -> V_59 != V_251 . V_59 ) ) {
V_156 = - V_287 ;
goto V_282;
}
switch ( V_258 ) {
case V_286 :
if ( V_55 != NULL )
V_156 = - V_158 ;
else
V_156 = F_115 ( V_15 , & V_251 , & V_55 ) ;
break;
case V_288 :
V_156 = F_124 ( V_55 , & V_251 ) ;
break;
case V_289 :
V_156 = F_128 ( V_55 ) ;
if ( ! V_156 )
goto V_282;
break;
case V_284 :
V_156 = F_140 ( V_55 ) ;
break;
case V_290 :
V_156 = F_100 ( V_55 , & V_117 ) ;
break;
case V_291 :
V_156 = F_102 ( V_55 , & V_117 ) ;
break;
case V_292 :
V_156 = F_111 ( V_55 , & V_117 ) ;
break;
default:
V_156 = - V_144 ;
}
V_282:
F_133 ( & V_193 ) ;
V_280:
F_20 () ;
return V_156 ;
}
static void
F_188 ( struct V_293 * V_9 , struct V_54 * V_102 )
{
struct V_120 * V_121 ;
struct V_100 V_235 ;
char * V_175 ;
V_121 = F_63 ( V_102 -> V_136 , 1 ) ;
V_175 = V_121 ? V_121 -> V_195 : L_18 ;
V_9 -> V_59 = V_102 -> V_59 ;
V_9 -> V_4 = V_102 -> V_4 . V_46 ;
V_9 -> V_43 = V_102 -> V_43 ;
V_9 -> V_53 = V_102 -> V_53 ;
F_183 ( V_9 -> V_175 , V_175 , sizeof( V_9 -> V_175 ) ) ;
V_9 -> V_12 = V_102 -> V_12 ;
V_9 -> V_181 = V_102 -> V_181 / V_182 ;
V_9 -> V_180 = V_102 -> V_180 ;
V_9 -> V_135 = V_102 -> V_135 ;
F_76 ( & V_235 , & V_102 -> V_76 ) ;
F_79 ( & V_9 -> V_76 , & V_235 ) ;
}
static inline int
F_189 ( struct V_14 * V_15 ,
const struct V_294 * V_295 ,
struct V_294 T_6 * V_296 )
{
int V_189 , V_297 = 0 ;
struct V_54 * V_55 ;
struct V_293 V_298 ;
int V_156 = 0 ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_139 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_184 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( V_297 >= V_295 -> V_185 )
goto V_67;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
F_188 ( & V_298 , V_55 ) ;
if ( F_190 ( & V_296 -> V_299 [ V_297 ] ,
& V_298 , sizeof( V_298 ) ) ) {
V_156 = - V_269 ;
goto V_67;
}
V_297 ++ ;
}
}
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_139 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_184 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( V_297 >= V_295 -> V_185 )
goto V_67;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
F_188 ( & V_298 , V_55 ) ;
if ( F_190 ( & V_296 -> V_299 [ V_297 ] ,
& V_298 , sizeof( V_298 ) ) ) {
V_156 = - V_269 ;
goto V_67;
}
V_297 ++ ;
}
}
V_67:
return V_156 ;
}
static inline int
F_191 ( struct V_14 * V_15 , const struct V_300 * V_295 ,
struct V_300 T_6 * V_296 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_295 -> V_4 } ;
int V_156 = 0 ;
F_56 () ;
if ( V_295 -> V_53 )
V_55 = F_38 ( V_15 , V_184 , V_295 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_184 , V_295 -> V_59 , & V_4 ,
V_295 -> V_43 ) ;
F_57 () ;
if ( V_55 ) {
int V_297 = 0 ;
struct V_74 * V_75 ;
struct V_301 V_298 ;
struct V_100 V_235 ;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
F_67 (dest, &svc->destinations, n_list) {
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
F_76 ( & V_235 , & V_75 -> V_76 ) ;
F_79 ( & V_298 . V_76 , & V_235 ) ;
if ( F_190 ( & V_296 -> V_299 [ V_297 ] ,
& V_298 , sizeof( V_298 ) ) ) {
V_156 = - V_269 ;
break;
}
V_297 ++ ;
}
} else
V_156 = - V_287 ;
return V_156 ;
}
static inline void
F_192 ( struct V_14 * V_15 , struct V_238 * V_171 )
{
#if F_173 ( V_239 ) || F_173 ( V_240 )
struct V_241 * V_242 ;
#endif
memset ( V_171 , 0 , sizeof ( * V_171 ) ) ;
#ifdef V_239
V_242 = F_174 ( V_15 , V_68 ) ;
V_171 -> V_243 = V_242 -> V_246 [ V_247 ] / V_182 ;
V_171 -> V_244 = V_242 -> V_246 [ V_248 ] / V_182 ;
#endif
#ifdef V_240
V_242 = F_174 ( V_15 , V_249 ) ;
V_171 -> V_245 =
V_242 -> V_246 [ V_250 ] / V_182 ;
#endif
}
static int
F_193 ( struct V_256 * V_257 , int V_258 , void T_6 * V_259 , int * V_260 )
{
unsigned char V_261 [ V_302 ] ;
int V_156 = 0 ;
unsigned int V_303 ;
struct V_2 * V_2 = F_178 ( V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
F_84 ( ! V_2 ) ;
F_179 ( sizeof( V_261 ) > 255 ) ;
if ( ! F_180 ( F_178 ( V_257 ) -> V_263 , V_264 ) )
return - V_265 ;
if ( V_258 < V_266 || V_258 > V_304 )
return - V_144 ;
V_303 = V_305 [ F_181 ( V_258 ) ] ;
if ( * V_260 < ( int ) V_303 ) {
F_101 ( 1 , L_56 , * V_260 , V_303 ) ;
return - V_144 ;
}
if ( F_182 ( V_261 , V_259 , V_303 ) != 0 )
return - V_269 ;
if ( V_258 == V_306 ) {
struct V_272 V_307 [ 2 ] ;
memset ( & V_307 , 0 , sizeof( V_307 ) ) ;
F_132 ( & V_15 -> V_278 ) ;
if ( V_15 -> V_308 & V_309 ) {
V_307 [ 0 ] . V_279 = V_309 ;
F_183 ( V_307 [ 0 ] . V_276 , V_15 -> V_310 . V_276 ,
sizeof( V_307 [ 0 ] . V_276 ) ) ;
V_307 [ 0 ] . V_277 = V_15 -> V_310 . V_277 ;
}
if ( V_15 -> V_308 & V_311 ) {
V_307 [ 1 ] . V_279 = V_311 ;
F_183 ( V_307 [ 1 ] . V_276 , V_15 -> V_312 . V_276 ,
sizeof( V_307 [ 1 ] . V_276 ) ) ;
V_307 [ 1 ] . V_277 = V_15 -> V_312 . V_277 ;
}
if ( F_190 ( V_259 , & V_307 , sizeof( V_307 ) ) != 0 )
V_156 = - V_269 ;
F_133 ( & V_15 -> V_278 ) ;
return V_156 ;
}
F_132 ( & V_193 ) ;
switch ( V_258 ) {
case V_313 :
{
char V_314 [ 64 ] ;
sprintf ( V_314 , L_57 ,
F_159 ( V_227 ) , V_228 ) ;
if ( F_190 ( V_259 , V_314 , strlen ( V_314 ) + 1 ) != 0 ) {
V_156 = - V_269 ;
goto V_67;
}
* V_260 = strlen ( V_314 ) + 1 ;
}
break;
case V_315 :
{
struct V_316 V_317 ;
V_317 . V_318 = V_227 ;
V_317 . V_319 = V_228 ;
V_317 . V_185 = V_15 -> V_185 ;
if ( F_190 ( V_259 , & V_317 , sizeof( V_317 ) ) != 0 )
V_156 = - V_269 ;
}
break;
case V_320 :
{
struct V_294 * V_295 ;
int V_319 ;
V_295 = (struct V_294 * ) V_261 ;
V_319 = sizeof( * V_295 ) +
sizeof( struct V_293 ) * V_295 -> V_185 ;
if ( * V_260 != V_319 ) {
F_28 ( L_58 , * V_260 , V_319 ) ;
V_156 = - V_144 ;
goto V_67;
}
V_156 = F_189 ( V_15 , V_295 , V_259 ) ;
}
break;
case V_321 :
{
struct V_293 * V_298 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_298 = (struct V_293 * ) V_261 ;
V_4 . V_46 = V_298 -> V_4 ;
F_56 () ;
if ( V_298 -> V_53 )
V_55 = F_38 ( V_15 , V_184 , V_298 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_184 ,
V_298 -> V_59 , & V_4 ,
V_298 -> V_43 ) ;
F_57 () ;
if ( V_55 ) {
F_188 ( V_298 , V_55 ) ;
if ( F_190 ( V_259 , V_298 , sizeof( * V_298 ) ) != 0 )
V_156 = - V_269 ;
} else
V_156 = - V_287 ;
}
break;
case V_322 :
{
struct V_300 * V_295 ;
int V_319 ;
V_295 = (struct V_300 * ) V_261 ;
V_319 = sizeof( * V_295 ) +
sizeof( struct V_301 ) * V_295 -> V_135 ;
if ( * V_260 != V_319 ) {
F_28 ( L_58 , * V_260 , V_319 ) ;
V_156 = - V_144 ;
goto V_67;
}
V_156 = F_191 ( V_15 , V_295 , V_259 ) ;
}
break;
case V_323 :
{
struct V_238 V_324 ;
F_192 ( V_15 , & V_324 ) ;
if ( F_190 ( V_259 , & V_324 , sizeof( V_324 ) ) != 0 )
V_156 = - V_269 ;
}
break;
default:
V_156 = - V_144 ;
}
V_67:
F_133 ( & V_193 ) ;
return V_156 ;
}
static int F_194 ( struct V_325 * V_326 , int V_327 ,
struct V_100 * V_235 )
{
struct V_328 * V_329 = F_195 ( V_326 , V_327 ) ;
if ( ! V_329 )
return - V_330 ;
if ( F_196 ( V_326 , V_331 , ( V_110 ) V_235 -> V_104 ) ||
F_196 ( V_326 , V_332 , ( V_110 ) V_235 -> V_105 ) ||
F_196 ( V_326 , V_333 , ( V_110 ) V_235 -> V_106 ) ||
F_197 ( V_326 , V_334 , V_235 -> V_107 ) ||
F_197 ( V_326 , V_335 , V_235 -> V_108 ) ||
F_196 ( V_326 , V_336 , ( V_110 ) V_235 -> V_111 ) ||
F_196 ( V_326 , V_337 , ( V_110 ) V_235 -> V_112 ) ||
F_196 ( V_326 , V_338 , ( V_110 ) V_235 -> V_113 ) ||
F_196 ( V_326 , V_339 , ( V_110 ) V_235 -> V_114 ) ||
F_196 ( V_326 , V_340 , ( V_110 ) V_235 -> V_115 ) )
goto V_341;
F_198 ( V_326 , V_329 ) ;
return 0 ;
V_341:
F_199 ( V_326 , V_329 ) ;
return - V_330 ;
}
static int F_200 ( struct V_325 * V_326 , int V_327 ,
struct V_100 * V_235 )
{
struct V_328 * V_329 = F_195 ( V_326 , V_327 ) ;
if ( ! V_329 )
return - V_330 ;
if ( F_197 ( V_326 , V_331 , V_235 -> V_104 ) ||
F_197 ( V_326 , V_332 , V_235 -> V_105 ) ||
F_197 ( V_326 , V_333 , V_235 -> V_106 ) ||
F_197 ( V_326 , V_334 , V_235 -> V_107 ) ||
F_197 ( V_326 , V_335 , V_235 -> V_108 ) ||
F_197 ( V_326 , V_336 , V_235 -> V_111 ) ||
F_197 ( V_326 , V_337 , V_235 -> V_112 ) ||
F_197 ( V_326 , V_338 , V_235 -> V_113 ) ||
F_197 ( V_326 , V_339 , V_235 -> V_114 ) ||
F_197 ( V_326 , V_340 , V_235 -> V_115 ) )
goto V_341;
F_198 ( V_326 , V_329 ) ;
return 0 ;
V_341:
F_199 ( V_326 , V_329 ) ;
return - V_330 ;
}
static int F_201 ( struct V_325 * V_326 ,
struct V_54 * V_55 )
{
struct V_120 * V_121 ;
struct V_173 * V_174 ;
struct V_328 * V_342 ;
struct V_343 V_12 = { . V_12 = V_55 -> V_12 ,
. V_344 = ~ 0 } ;
struct V_100 V_235 ;
char * V_175 ;
V_342 = F_195 ( V_326 , V_345 ) ;
if ( ! V_342 )
return - V_330 ;
if ( F_202 ( V_326 , V_346 , V_55 -> V_40 ) )
goto V_341;
if ( V_55 -> V_53 ) {
if ( F_196 ( V_326 , V_347 , V_55 -> V_53 ) )
goto V_341;
} else {
if ( F_202 ( V_326 , V_348 , V_55 -> V_59 ) ||
F_203 ( V_326 , V_349 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_204 ( V_326 , V_350 , V_55 -> V_43 ) )
goto V_341;
}
V_121 = F_63 ( V_55 -> V_136 , 1 ) ;
V_175 = V_121 ? V_121 -> V_195 : L_18 ;
V_174 = F_63 ( V_55 -> V_174 , 1 ) ;
if ( F_205 ( V_326 , V_351 , V_175 ) ||
( V_174 && F_205 ( V_326 , V_352 , V_174 -> V_195 ) ) ||
F_203 ( V_326 , V_353 , sizeof( V_12 ) , & V_12 ) ||
F_196 ( V_326 , V_354 , V_55 -> V_181 / V_182 ) ||
F_206 ( V_326 , V_355 , V_55 -> V_180 ) )
goto V_341;
F_76 ( & V_235 , & V_55 -> V_76 ) ;
if ( F_194 ( V_326 , V_356 , & V_235 ) )
goto V_341;
if ( F_200 ( V_326 , V_357 , & V_235 ) )
goto V_341;
F_198 ( V_326 , V_342 ) ;
return 0 ;
V_341:
F_199 ( V_326 , V_342 ) ;
return - V_330 ;
}
static int F_207 ( struct V_325 * V_326 ,
struct V_54 * V_55 ,
struct V_358 * V_359 )
{
void * V_360 ;
V_360 = F_208 ( V_326 , F_209 ( V_359 -> V_326 ) . V_361 , V_359 -> V_362 -> V_363 ,
& V_364 , V_365 ,
V_366 ) ;
if ( ! V_360 )
return - V_330 ;
if ( F_201 ( V_326 , V_55 ) < 0 )
goto V_341;
F_210 ( V_326 , V_360 ) ;
return 0 ;
V_341:
F_211 ( V_326 , V_360 ) ;
return - V_330 ;
}
static int F_212 ( struct V_325 * V_326 ,
struct V_358 * V_359 )
{
int V_189 = 0 , V_17 ;
int V_236 = V_359 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_178 ( V_326 -> V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
F_132 ( & V_193 ) ;
for ( V_17 = 0 ; V_17 < V_192 ; V_17 ++ ) {
F_139 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_189 <= V_236 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( F_207 ( V_326 , V_55 , V_359 ) < 0 ) {
V_189 -- ;
goto V_341;
}
}
}
for ( V_17 = 0 ; V_17 < V_192 ; V_17 ++ ) {
F_139 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_189 <= V_236 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( F_207 ( V_326 , V_55 , V_359 ) < 0 ) {
V_189 -- ;
goto V_341;
}
}
}
V_341:
F_133 ( & V_193 ) ;
V_359 -> args [ 0 ] = V_189 ;
return V_326 -> V_260 ;
}
static int F_213 ( struct V_14 * V_15 ,
struct V_170 * V_251 ,
struct V_328 * V_367 , int V_368 ,
struct V_54 * * V_369 )
{
struct V_328 * V_370 [ V_371 + 1 ] ;
struct V_328 * V_372 , * V_373 , * V_374 , * V_375 , * V_376 ;
struct V_54 * V_55 ;
if ( V_367 == NULL ||
F_214 ( V_370 , V_371 , V_367 , V_377 ) )
return - V_144 ;
V_372 = V_370 [ V_346 ] ;
V_375 = V_370 [ V_348 ] ;
V_376 = V_370 [ V_349 ] ;
V_373 = V_370 [ V_350 ] ;
V_374 = V_370 [ V_347 ] ;
if ( ! ( V_372 && ( V_374 || ( V_373 && V_375 && V_376 ) ) ) )
return - V_144 ;
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_40 = F_215 ( V_372 ) ;
#ifdef F_24
if ( V_251 -> V_40 != V_184 && V_251 -> V_40 != V_48 )
#else
if ( V_251 -> V_40 != V_184 )
#endif
return - V_378 ;
if ( V_374 ) {
V_251 -> V_59 = V_68 ;
V_251 -> V_53 = F_216 ( V_374 ) ;
} else {
V_251 -> V_59 = F_215 ( V_375 ) ;
F_217 ( & V_251 -> V_4 , V_376 , sizeof( V_251 -> V_4 ) ) ;
V_251 -> V_43 = F_218 ( V_373 ) ;
V_251 -> V_53 = 0 ;
}
F_56 () ;
if ( V_251 -> V_53 )
V_55 = F_38 ( V_15 , V_251 -> V_40 , V_251 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_251 -> V_40 , V_251 -> V_59 ,
& V_251 -> V_4 , V_251 -> V_43 ) ;
F_57 () ;
* V_369 = V_55 ;
if ( V_368 ) {
struct V_328 * V_379 , * V_380 , * V_381 , * V_382 ,
* V_383 ;
struct V_343 V_12 ;
V_379 = V_370 [ V_351 ] ;
V_381 = V_370 [ V_352 ] ;
V_380 = V_370 [ V_353 ] ;
V_382 = V_370 [ V_354 ] ;
V_383 = V_370 [ V_355 ] ;
if ( ! ( V_379 && V_380 && V_382 && V_383 ) )
return - V_144 ;
F_217 ( & V_12 , V_380 , sizeof( V_12 ) ) ;
if ( V_55 )
V_251 -> V_12 = V_55 -> V_12 ;
V_251 -> V_12 = ( V_251 -> V_12 & ~ V_12 . V_344 ) |
( V_12 . V_12 & V_12 . V_344 ) ;
V_251 -> V_175 = F_219 ( V_379 ) ;
V_251 -> V_177 = V_381 ? F_219 ( V_381 ) : NULL ;
V_251 -> V_181 = F_216 ( V_382 ) ;
V_251 -> V_180 = F_220 ( V_383 ) ;
}
return 0 ;
}
static struct V_54 * F_221 ( struct V_14 * V_15 ,
struct V_328 * V_367 )
{
struct V_170 V_251 ;
struct V_54 * V_55 ;
int V_156 ;
V_156 = F_213 ( V_15 , & V_251 , V_367 , 0 , & V_55 ) ;
return V_156 ? F_222 ( V_156 ) : V_55 ;
}
static int F_223 ( struct V_325 * V_326 , struct V_74 * V_75 )
{
struct V_328 * V_384 ;
struct V_100 V_235 ;
V_384 = F_195 ( V_326 , V_385 ) ;
if ( ! V_384 )
return - V_330 ;
if ( F_203 ( V_326 , V_386 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_204 ( V_326 , V_387 , V_75 -> V_43 ) ||
F_196 ( V_326 , V_388 ,
( F_15 ( & V_75 -> V_122 ) &
V_90 ) ) ||
F_196 ( V_326 , V_389 ,
F_15 ( & V_75 -> V_124 ) ) ||
F_196 ( V_326 , V_390 , V_75 -> V_129 ) ||
F_196 ( V_326 , V_391 , V_75 -> V_131 ) ||
F_196 ( V_326 , V_392 ,
F_15 ( & V_75 -> V_153 ) ) ||
F_196 ( V_326 , V_393 ,
F_15 ( & V_75 -> V_154 ) ) ||
F_196 ( V_326 , V_394 ,
F_15 ( & V_75 -> V_155 ) ) ||
F_202 ( V_326 , V_395 , V_75 -> V_40 ) )
goto V_341;
F_76 ( & V_235 , & V_75 -> V_76 ) ;
if ( F_194 ( V_326 , V_396 , & V_235 ) )
goto V_341;
if ( F_200 ( V_326 , V_397 , & V_235 ) )
goto V_341;
F_198 ( V_326 , V_384 ) ;
return 0 ;
V_341:
F_199 ( V_326 , V_384 ) ;
return - V_330 ;
}
static int F_224 ( struct V_325 * V_326 , struct V_74 * V_75 ,
struct V_358 * V_359 )
{
void * V_360 ;
V_360 = F_208 ( V_326 , F_209 ( V_359 -> V_326 ) . V_361 , V_359 -> V_362 -> V_363 ,
& V_364 , V_365 ,
V_398 ) ;
if ( ! V_360 )
return - V_330 ;
if ( F_223 ( V_326 , V_75 ) < 0 )
goto V_341;
F_210 ( V_326 , V_360 ) ;
return 0 ;
V_341:
F_211 ( V_326 , V_360 ) ;
return - V_330 ;
}
static int F_225 ( struct V_325 * V_326 ,
struct V_358 * V_359 )
{
int V_189 = 0 ;
int V_236 = V_359 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_328 * V_370 [ V_399 + 1 ] ;
struct V_2 * V_2 = F_178 ( V_326 -> V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
F_132 ( & V_193 ) ;
if ( F_226 ( V_359 -> V_362 , V_400 , V_370 ,
V_399 , V_401 ) )
goto V_176;
V_55 = F_221 ( V_15 , V_370 [ V_345 ] ) ;
if ( F_227 ( V_55 ) || V_55 == NULL )
goto V_176;
F_67 (dest, &svc->destinations, n_list) {
if ( ++ V_189 <= V_236 )
continue;
if ( F_224 ( V_326 , V_75 , V_359 ) < 0 ) {
V_189 -- ;
goto V_341;
}
}
V_341:
V_359 -> args [ 0 ] = V_189 ;
V_176:
F_133 ( & V_193 ) ;
return V_326 -> V_260 ;
}
static int F_228 ( struct V_116 * V_117 ,
struct V_328 * V_367 , int V_368 )
{
struct V_328 * V_370 [ V_402 + 1 ] ;
struct V_328 * V_376 , * V_373 ;
struct V_328 * V_403 ;
if ( V_367 == NULL ||
F_214 ( V_370 , V_402 , V_367 , V_404 ) )
return - V_144 ;
V_376 = V_370 [ V_386 ] ;
V_373 = V_370 [ V_387 ] ;
V_403 = V_370 [ V_395 ] ;
if ( ! ( V_376 && V_373 ) )
return - V_144 ;
memset ( V_117 , 0 , sizeof( * V_117 ) ) ;
F_217 ( & V_117 -> V_4 , V_376 , sizeof( V_117 -> V_4 ) ) ;
V_117 -> V_43 = F_218 ( V_373 ) ;
if ( V_403 )
V_117 -> V_40 = F_215 ( V_403 ) ;
else
V_117 -> V_40 = 0 ;
if ( V_368 ) {
struct V_328 * V_405 , * V_406 , * V_407 ,
* V_408 ;
V_405 = V_370 [ V_388 ] ;
V_406 = V_370 [ V_389 ] ;
V_407 = V_370 [ V_390 ] ;
V_408 = V_370 [ V_391 ] ;
if ( ! ( V_405 && V_406 && V_407 && V_408 ) )
return - V_144 ;
V_117 -> V_122 = F_216 ( V_405 )
& V_90 ;
V_117 -> V_124 = F_216 ( V_406 ) ;
V_117 -> V_129 = F_216 ( V_407 ) ;
V_117 -> V_131 = F_216 ( V_408 ) ;
}
return 0 ;
}
static int F_229 ( struct V_325 * V_326 , T_3 V_279 ,
struct V_274 * T_5 )
{
struct V_328 * V_409 ;
V_409 = F_195 ( V_326 , V_410 ) ;
if ( ! V_409 )
return - V_330 ;
if ( F_196 ( V_326 , V_411 , V_279 ) ||
F_205 ( V_326 , V_412 , T_5 -> V_276 ) ||
F_196 ( V_326 , V_413 , T_5 -> V_277 ) ||
F_202 ( V_326 , V_414 , T_5 -> V_415 ) ||
F_202 ( V_326 , V_416 , T_5 -> V_417 ) ||
F_230 ( V_326 , V_418 , T_5 -> V_419 ) )
goto V_341;
#ifdef F_24
if ( T_5 -> V_420 == V_48 ) {
if ( F_231 ( V_326 , V_421 ,
& T_5 -> V_422 . V_141 ) )
goto V_341;
} else
#endif
if ( T_5 -> V_420 == V_184 &&
F_232 ( V_326 , V_423 ,
T_5 -> V_422 . V_46 ) )
goto V_341;
F_198 ( V_326 , V_409 ) ;
return 0 ;
V_341:
F_199 ( V_326 , V_409 ) ;
return - V_330 ;
}
static int F_233 ( struct V_325 * V_326 , T_3 V_279 ,
struct V_274 * T_5 ,
struct V_358 * V_359 )
{
void * V_360 ;
V_360 = F_208 ( V_326 , F_209 ( V_359 -> V_326 ) . V_361 , V_359 -> V_362 -> V_363 ,
& V_364 , V_365 ,
V_424 ) ;
if ( ! V_360 )
return - V_330 ;
if ( F_229 ( V_326 , V_279 , T_5 ) )
goto V_341;
F_210 ( V_326 , V_360 ) ;
return 0 ;
V_341:
F_211 ( V_326 , V_360 ) ;
return - V_330 ;
}
static int F_234 ( struct V_325 * V_326 ,
struct V_358 * V_359 )
{
struct V_2 * V_2 = F_178 ( V_326 -> V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
F_132 ( & V_15 -> V_278 ) ;
if ( ( V_15 -> V_308 & V_309 ) && ! V_359 -> args [ 0 ] ) {
if ( F_233 ( V_326 , V_309 ,
& V_15 -> V_310 , V_359 ) < 0 )
goto V_341;
V_359 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_308 & V_311 ) && ! V_359 -> args [ 1 ] ) {
if ( F_233 ( V_326 , V_311 ,
& V_15 -> V_312 , V_359 ) < 0 )
goto V_341;
V_359 -> args [ 1 ] = 1 ;
}
V_341:
F_133 ( & V_15 -> V_278 ) ;
return V_326 -> V_260 ;
}
static int F_235 ( struct V_14 * V_15 , struct V_328 * * V_370 )
{
struct V_274 T_5 ;
struct V_328 * V_425 ;
int V_156 ;
memset ( & T_5 , 0 , sizeof( T_5 ) ) ;
if ( ! ( V_370 [ V_411 ] &&
V_370 [ V_412 ] &&
V_370 [ V_413 ] ) )
return - V_144 ;
F_183 ( T_5 . V_276 , F_219 ( V_370 [ V_412 ] ) ,
sizeof( T_5 . V_276 ) ) ;
T_5 . V_277 = F_216 ( V_370 [ V_413 ] ) ;
V_425 = V_370 [ V_414 ] ;
if ( V_425 )
T_5 . V_415 = F_215 ( V_425 ) ;
V_425 = V_370 [ V_423 ] ;
if ( V_425 ) {
T_5 . V_420 = V_184 ;
T_5 . V_422 . V_46 = F_236 ( V_425 ) ;
if ( ! F_237 ( T_5 . V_422 . V_46 ) )
return - V_144 ;
} else {
V_425 = V_370 [ V_421 ] ;
if ( V_425 ) {
#ifdef F_24
int V_426 ;
T_5 . V_420 = V_48 ;
T_5 . V_422 . V_141 = F_238 ( V_425 ) ;
V_426 = F_89 ( & T_5 . V_422 . V_141 ) ;
if ( ! ( V_426 & V_427 ) )
return - V_144 ;
#else
return - V_378 ;
#endif
}
}
V_425 = V_370 [ V_416 ] ;
if ( V_425 )
T_5 . V_417 = F_215 ( V_425 ) ;
V_425 = V_370 [ V_418 ] ;
if ( V_425 )
T_5 . V_419 = F_239 ( V_425 ) ;
if ( V_15 -> V_123 > 0 )
return - V_144 ;
F_184 () ;
F_132 ( & V_15 -> V_278 ) ;
V_156 = F_185 ( V_15 , & T_5 ,
F_216 ( V_370 [ V_411 ] ) ) ;
F_133 ( & V_15 -> V_278 ) ;
F_186 () ;
return V_156 ;
}
static int F_240 ( struct V_14 * V_15 , struct V_328 * * V_370 )
{
int V_156 ;
if ( ! V_370 [ V_411 ] )
return - V_144 ;
F_132 ( & V_15 -> V_278 ) ;
V_156 = F_187 ( V_15 ,
F_216 ( V_370 [ V_411 ] ) ) ;
F_133 ( & V_15 -> V_278 ) ;
return V_156 ;
}
static int F_241 ( struct V_14 * V_15 , struct V_328 * * V_370 )
{
struct V_238 V_324 ;
F_192 ( V_15 , & V_324 ) ;
if ( V_370 [ V_428 ] )
V_324 . V_243 = F_216 ( V_370 [ V_428 ] ) ;
if ( V_370 [ V_429 ] )
V_324 . V_244 =
F_216 ( V_370 [ V_429 ] ) ;
if ( V_370 [ V_430 ] )
V_324 . V_245 = F_216 ( V_370 [ V_430 ] ) ;
return F_172 ( V_15 , & V_324 ) ;
}
static int F_242 ( struct V_325 * V_326 , struct V_431 * V_317 )
{
int V_156 = - V_144 , V_258 ;
struct V_2 * V_2 = F_178 ( V_326 -> V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
V_258 = V_317 -> V_432 -> V_258 ;
if ( V_258 == V_424 || V_258 == V_433 ) {
struct V_328 * V_434 [ V_435 + 1 ] ;
if ( ! V_317 -> V_370 [ V_410 ] ||
F_214 ( V_434 , V_435 ,
V_317 -> V_370 [ V_410 ] ,
V_436 ) )
goto V_67;
if ( V_258 == V_424 )
V_156 = F_235 ( V_15 , V_434 ) ;
else
V_156 = F_240 ( V_15 , V_434 ) ;
}
V_67:
return V_156 ;
}
static int F_243 ( struct V_325 * V_326 , struct V_431 * V_317 )
{
struct V_54 * V_55 = NULL ;
struct V_170 V_251 ;
struct V_116 V_117 ;
int V_156 = 0 , V_258 ;
int V_437 = 0 , V_438 = 0 ;
struct V_2 * V_2 = F_178 ( V_326 -> V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
V_258 = V_317 -> V_432 -> V_258 ;
F_132 ( & V_193 ) ;
if ( V_258 == V_439 ) {
V_156 = F_129 ( V_15 , false ) ;
goto V_67;
} else if ( V_258 == V_440 ) {
V_156 = F_241 ( V_15 , V_317 -> V_370 ) ;
goto V_67;
} else if ( V_258 == V_441 &&
! V_317 -> V_370 [ V_345 ] ) {
V_156 = F_141 ( V_15 ) ;
goto V_67;
}
if ( V_258 == V_366 || V_258 == V_442 )
V_437 = 1 ;
V_156 = F_213 ( V_15 , & V_251 ,
V_317 -> V_370 [ V_345 ] ,
V_437 , & V_55 ) ;
if ( V_156 )
goto V_67;
if ( ( V_258 != V_366 ) && ( V_55 == NULL ) ) {
V_156 = - V_287 ;
goto V_67;
}
if ( V_258 == V_398 || V_258 == V_443 ||
V_258 == V_444 ) {
if ( V_258 != V_444 )
V_438 = 1 ;
V_156 = F_228 ( & V_117 ,
V_317 -> V_370 [ V_385 ] ,
V_438 ) ;
if ( V_156 )
goto V_67;
if ( V_117 . V_40 == 0 )
V_117 . V_40 = V_55 -> V_40 ;
if ( V_117 . V_40 != V_55 -> V_40 && V_258 != V_444 ) {
if ( V_15 -> V_308 ) {
V_156 = - V_144 ;
goto V_67;
}
switch ( V_117 . V_122 ) {
case V_214 :
break;
default:
V_156 = - V_144 ;
goto V_67;
}
}
}
switch ( V_258 ) {
case V_366 :
if ( V_55 == NULL )
V_156 = F_115 ( V_15 , & V_251 , & V_55 ) ;
else
V_156 = - V_158 ;
break;
case V_442 :
V_156 = F_124 ( V_55 , & V_251 ) ;
break;
case V_445 :
V_156 = F_128 ( V_55 ) ;
break;
case V_398 :
V_156 = F_100 ( V_55 , & V_117 ) ;
break;
case V_443 :
V_156 = F_102 ( V_55 , & V_117 ) ;
break;
case V_444 :
V_156 = F_111 ( V_55 , & V_117 ) ;
break;
case V_441 :
V_156 = F_140 ( V_55 ) ;
break;
default:
V_156 = - V_144 ;
}
V_67:
F_133 ( & V_193 ) ;
return V_156 ;
}
static int F_244 ( struct V_325 * V_326 , struct V_431 * V_317 )
{
struct V_325 * V_446 ;
void * V_447 ;
int V_156 , V_258 , V_448 ;
struct V_2 * V_2 = F_178 ( V_326 -> V_257 ) ;
struct V_14 * V_15 = F_138 ( V_2 ) ;
V_258 = V_317 -> V_432 -> V_258 ;
if ( V_258 == V_449 )
V_448 = V_366 ;
else if ( V_258 == V_450 )
V_448 = V_451 ;
else if ( V_258 == V_452 )
V_448 = V_440 ;
else {
F_28 ( L_59 ) ;
return - V_144 ;
}
V_446 = F_245 ( V_453 , V_147 ) ;
if ( ! V_446 )
return - V_148 ;
F_132 ( & V_193 ) ;
V_447 = F_246 ( V_446 , V_317 , & V_364 , 0 , V_448 ) ;
if ( V_447 == NULL )
goto V_341;
switch ( V_258 ) {
case V_449 :
{
struct V_54 * V_55 ;
V_55 = F_221 ( V_15 ,
V_317 -> V_370 [ V_345 ] ) ;
if ( F_227 ( V_55 ) ) {
V_156 = F_247 ( V_55 ) ;
goto V_176;
} else if ( V_55 ) {
V_156 = F_201 ( V_446 , V_55 ) ;
if ( V_156 )
goto V_341;
} else {
V_156 = - V_287 ;
goto V_176;
}
break;
}
case V_452 :
{
struct V_238 V_324 ;
F_192 ( V_15 , & V_324 ) ;
#ifdef V_239
if ( F_196 ( V_446 , V_428 ,
V_324 . V_243 ) ||
F_196 ( V_446 , V_429 ,
V_324 . V_244 ) )
goto V_341;
#endif
#ifdef V_240
if ( F_196 ( V_446 , V_430 , V_324 . V_245 ) )
goto V_341;
#endif
break;
}
case V_450 :
if ( F_196 ( V_446 , V_454 ,
V_227 ) ||
F_196 ( V_446 , V_455 ,
V_228 ) )
goto V_341;
break;
}
F_210 ( V_446 , V_447 ) ;
V_156 = F_248 ( V_446 , V_317 ) ;
goto V_67;
V_341:
F_28 ( L_60 ) ;
V_156 = - V_330 ;
V_176:
F_249 ( V_446 ) ;
V_67:
F_133 ( & V_193 ) ;
return V_156 ;
}
static int T_11 F_250 ( void )
{
return F_251 ( & V_364 ,
V_456 ) ;
}
static void F_252 ( void )
{
F_253 ( & V_364 ) ;
}
static int T_12 F_254 ( struct V_14 * V_15 )
{
struct V_2 * V_2 = V_15 -> V_2 ;
int V_189 ;
struct V_203 * V_457 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_98 ( & V_15 -> V_25 ) ;
F_98 ( & V_15 -> V_28 ) ;
F_98 ( & V_15 -> V_33 ) ;
if ( ! F_255 ( V_2 , & V_458 ) ) {
V_457 = F_256 ( V_459 , sizeof( V_459 ) , V_147 ) ;
if ( V_457 == NULL )
return - V_148 ;
if ( V_2 -> V_263 != & V_460 )
V_457 [ 0 ] . V_461 = NULL ;
} else
V_457 = V_459 ;
for ( V_189 = 0 ; V_189 < F_257 ( V_459 ) ; V_189 ++ ) {
if ( V_457 [ V_189 ] . V_462 == F_142 )
V_457 [ V_189 ] . V_209 = V_15 ;
}
V_189 = 0 ;
V_15 -> V_24 = 1024 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_32 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_26 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_29 ;
#ifdef F_258
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_463 ;
#endif
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_34 ;
V_15 -> V_464 = 1 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_464 ;
V_15 -> V_465 = 1 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_465 ;
V_15 -> V_466 = 1 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_466 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_467 ;
V_15 -> V_468 = F_259 () / 32 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_468 ;
V_15 -> V_469 = 0 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_469 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_470 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_471 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_472 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_473 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_474 ;
V_15 -> V_475 [ 0 ] = V_476 ;
V_15 -> V_475 [ 1 ] = V_477 ;
V_457 [ V_189 ] . V_167 = & V_15 -> V_475 ;
V_457 [ V_189 ++ ] . V_478 = sizeof( V_15 -> V_475 ) ;
V_15 -> V_479 = V_480 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_479 ;
V_15 -> V_481 = F_260 ( int , V_482 , 0 , 3 ) ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_481 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_483 ;
V_15 -> V_484 = 1 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_484 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_485 ;
V_15 -> V_486 = 1 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_486 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_487 ;
V_457 [ V_189 ++ ] . V_167 = & V_15 -> V_488 ;
V_15 -> V_489 = F_261 ( V_2 , L_61 , V_457 ) ;
if ( V_15 -> V_489 == NULL ) {
if ( ! F_255 ( V_2 , & V_458 ) )
F_47 ( V_457 ) ;
return - V_148 ;
}
F_85 ( V_15 , & V_15 -> V_202 ) ;
V_15 -> V_490 = V_457 ;
F_262 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_263 ( struct V_14 * V_15 )
{
struct V_2 * V_2 = V_15 -> V_2 ;
F_264 ( & V_15 -> V_37 ) ;
F_265 ( & V_15 -> V_37 . V_36 ) ;
F_266 ( V_15 -> V_489 ) ;
F_104 ( V_15 , & V_15 -> V_202 ) ;
if ( ! F_255 ( V_2 , & V_458 ) )
F_47 ( V_15 -> V_490 ) ;
}
static int T_12 F_254 ( struct V_14 * V_15 ) { return 0 ; }
static void T_13 F_263 ( struct V_14 * V_15 ) { }
int T_12 F_267 ( struct V_14 * V_15 )
{
int V_17 , V_189 ;
for ( V_189 = 0 ; V_189 < V_491 ; V_189 ++ )
F_268 ( & V_15 -> V_85 [ V_189 ] ) ;
F_119 ( & V_15 -> V_161 ) ;
F_98 ( & V_15 -> V_96 ) ;
F_269 ( & V_15 -> V_99 , F_112 ,
( unsigned long ) V_15 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_202 . V_77 = F_92 ( struct V_149 ) ;
if ( ! V_15 -> V_202 . V_77 )
return - V_148 ;
F_93 (i) {
struct V_149 * V_492 ;
V_492 = F_94 ( V_15 -> V_202 . V_77 , V_17 ) ;
F_95 ( & V_492 -> V_152 ) ;
}
F_98 ( & V_15 -> V_202 . V_103 ) ;
F_270 ( L_62 , 0 , V_15 -> V_2 -> V_493 , & V_494 ) ;
F_270 ( L_63 , 0 , V_15 -> V_2 -> V_493 , & V_495 ) ;
F_270 ( L_64 , 0 , V_15 -> V_2 -> V_493 ,
& V_496 ) ;
if ( F_254 ( V_15 ) )
goto V_497;
return 0 ;
V_497:
F_46 ( V_15 -> V_202 . V_77 ) ;
return - V_148 ;
}
void T_13 F_271 ( struct V_14 * V_15 )
{
F_73 ( V_15 ) ;
F_263 ( V_15 ) ;
F_272 ( L_64 , V_15 -> V_2 -> V_493 ) ;
F_272 ( L_63 , V_15 -> V_2 -> V_493 ) ;
F_272 ( L_62 , V_15 -> V_2 -> V_493 ) ;
F_46 ( V_15 -> V_202 . V_77 ) ;
}
int T_11 F_273 ( void )
{
int V_156 ;
V_156 = F_274 ( & V_498 ) ;
if ( V_156 ) {
F_28 ( L_65 ) ;
goto V_499;
}
V_156 = F_250 () ;
if ( V_156 ) {
F_28 ( L_66 ) ;
goto V_500;
}
return 0 ;
V_500:
F_275 ( & V_498 ) ;
V_499:
return V_156 ;
}
void F_276 ( void )
{
F_252 () ;
F_275 ( & V_498 ) ;
}
int T_11 F_277 ( void )
{
int V_189 ;
int V_156 ;
F_88 ( 2 ) ;
for ( V_189 = 0 ; V_189 < V_192 ; V_189 ++ ) {
F_268 ( & V_61 [ V_189 ] ) ;
F_268 ( & V_63 [ V_189 ] ) ;
}
F_278 () ;
V_156 = F_279 ( & V_501 ) ;
if ( V_156 < 0 )
return V_156 ;
F_99 ( 2 ) ;
return 0 ;
}
void F_280 ( void )
{
F_88 ( 2 ) ;
F_281 ( & V_501 ) ;
F_99 ( 2 ) ;
}
