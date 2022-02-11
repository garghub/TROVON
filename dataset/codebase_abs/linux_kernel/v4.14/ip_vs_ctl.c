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
if ( ! V_55 && V_59 == V_68 &&
F_15 ( & V_15 -> V_69 ) &&
( V_66 == V_70 || F_23 ( V_66 ) >= F_40 ( V_15 -> V_2 ) ) ) {
V_55 = F_35 ( V_15 , V_40 , V_59 , V_65 , V_71 ) ;
}
if ( V_55 == NULL
&& F_15 ( & V_15 -> V_72 ) ) {
V_55 = F_35 ( V_15 , V_40 , V_59 , V_65 , 0 ) ;
}
V_67:
F_41 ( 9 , L_3 ,
V_53 , F_42 ( V_59 ) ,
F_43 ( V_40 , V_65 ) , F_23 ( V_66 ) ,
V_55 ? L_4 : L_5 ) ;
return V_55 ;
}
static inline void
F_44 ( struct V_73 * V_74 , struct V_54 * V_55 )
{
F_31 ( & V_55 -> V_64 ) ;
F_45 ( V_74 -> V_55 , V_55 ) ;
}
static void F_46 ( struct V_54 * V_55 )
{
F_47 ( V_55 -> V_75 . V_76 ) ;
F_48 ( V_55 ) ;
}
static void F_49 ( struct V_77 * V_78 )
{
struct V_54 * V_55 ;
V_55 = F_14 ( V_78 , struct V_54 , V_77 ) ;
F_46 ( V_55 ) ;
}
static void F_50 ( struct V_54 * V_55 , bool V_79 )
{
if ( F_51 ( & V_55 -> V_64 ) ) {
F_41 ( 3 , L_6 ,
V_55 -> V_53 ,
F_43 ( V_55 -> V_40 , & V_55 -> V_4 ) ,
F_23 ( V_55 -> V_43 ) ) ;
if ( V_79 )
F_52 ( & V_55 -> V_77 , F_49 ) ;
else
F_46 ( V_55 ) ;
}
}
static inline unsigned int F_53 ( int V_40 ,
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
return ( F_25 ( V_45 ) ^ ( V_44 >> V_80 ) ^ V_44 )
& V_81 ;
}
static void F_54 ( struct V_14 * V_15 , struct V_73 * V_74 )
{
unsigned int V_56 ;
if ( V_74 -> V_82 )
return;
V_56 = F_53 ( V_74 -> V_40 , & V_74 -> V_4 , V_74 -> V_43 ) ;
F_30 ( & V_74 -> V_83 , & V_15 -> V_84 [ V_56 ] ) ;
V_74 -> V_82 = 1 ;
}
static void F_55 ( struct V_73 * V_74 )
{
if ( V_74 -> V_82 ) {
F_33 ( & V_74 -> V_83 ) ;
V_74 -> V_82 = 0 ;
}
}
bool F_56 ( struct V_14 * V_15 , int V_40 , T_4 V_59 ,
const union V_42 * V_7 , T_1 V_85 )
{
unsigned int V_56 ;
struct V_73 * V_74 ;
V_56 = F_53 ( V_40 , V_7 , V_85 ) ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( V_74 -> V_43 == V_85 &&
V_74 -> V_40 == V_40 &&
F_37 ( V_40 , & V_74 -> V_4 , V_7 ) &&
( V_74 -> V_59 == V_59 || V_74 -> V_86 ) ) {
return true ;
}
}
return false ;
}
struct V_73 * F_57 ( struct V_14 * V_15 , int V_40 ,
T_4 V_59 ,
const union V_42 * V_7 ,
T_1 V_85 )
{
unsigned int V_56 ;
struct V_73 * V_74 ;
V_56 = F_53 ( V_40 , V_7 , V_85 ) ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( V_74 -> V_43 == V_85 &&
V_74 -> V_40 == V_40 &&
F_37 ( V_40 , & V_74 -> V_4 , V_7 ) &&
( V_74 -> V_59 == V_59 || V_74 -> V_86 ) ) {
return V_74 ;
}
}
return NULL ;
}
static struct V_73 *
F_58 ( struct V_54 * V_55 , int V_87 ,
const union V_42 * V_7 , T_1 V_85 )
{
struct V_73 * V_74 ;
F_59 (dest, &svc->destinations, n_list) {
if ( ( V_74 -> V_40 == V_87 ) &&
F_37 ( V_87 , & V_74 -> V_4 , V_7 ) &&
( V_74 -> V_43 == V_85 ) ) {
return V_74 ;
}
}
return NULL ;
}
struct V_73 * F_60 ( struct V_14 * V_15 , int V_88 , int V_87 ,
const union V_42 * V_7 ,
T_1 V_85 ,
const union V_42 * V_65 ,
T_1 V_66 , T_4 V_59 , T_3 V_53 ,
T_3 V_12 )
{
struct V_73 * V_74 ;
struct V_54 * V_55 ;
T_1 V_43 = V_85 ;
V_55 = F_39 ( V_15 , V_88 , V_53 , V_59 , V_65 , V_66 ) ;
if ( ! V_55 )
return NULL ;
if ( V_53 && ( V_12 & V_89 ) != V_90 )
V_43 = 0 ;
V_74 = F_58 ( V_55 , V_87 , V_7 , V_43 ) ;
if ( ! V_74 )
V_74 = F_58 ( V_55 , V_87 , V_7 , V_43 ^ V_85 ) ;
return V_74 ;
}
void F_61 ( struct V_77 * V_78 )
{
struct V_91 * V_92 = F_14 ( V_78 ,
struct V_91 ,
V_77 ) ;
F_4 ( V_92 -> V_93 ) ;
F_48 ( V_92 ) ;
}
static void F_62 ( struct V_73 * V_74 )
{
struct V_91 * V_94 ;
V_94 = F_63 ( V_74 -> V_92 , 1 ) ;
if ( V_94 ) {
F_64 ( V_74 -> V_92 , NULL ) ;
F_52 ( & V_94 -> V_77 , F_61 ) ;
}
}
static struct V_73 *
F_65 ( struct V_54 * V_55 , int V_87 ,
const union V_42 * V_7 , T_1 V_85 )
{
struct V_73 * V_74 ;
struct V_14 * V_15 = V_55 -> V_15 ;
F_66 ( & V_15 -> V_95 ) ;
F_67 (dest, &ipvs->dest_trash, t_list) {
F_41 ( 3 , L_7
L_8 ,
V_74 -> V_86 ,
F_43 ( V_74 -> V_40 , & V_74 -> V_4 ) ,
F_23 ( V_74 -> V_43 ) ,
F_68 ( & V_74 -> V_64 ) ) ;
if ( V_74 -> V_40 == V_87 &&
F_37 ( V_87 , & V_74 -> V_4 , V_7 ) &&
V_74 -> V_43 == V_85 &&
V_74 -> V_86 == V_55 -> V_53 &&
V_74 -> V_59 == V_55 -> V_59 &&
( V_55 -> V_53 ||
( F_37 ( V_55 -> V_40 , & V_74 -> V_65 , & V_55 -> V_4 ) &&
V_74 -> V_66 == V_55 -> V_43 ) ) ) {
F_69 ( & V_74 -> V_96 ) ;
goto V_67;
}
}
V_74 = NULL ;
V_67:
F_70 ( & V_15 -> V_95 ) ;
return V_74 ;
}
static void F_71 ( struct V_73 * V_74 )
{
struct V_54 * V_55 = F_63 ( V_74 -> V_55 , 1 ) ;
F_62 ( V_74 ) ;
F_50 ( V_55 , false ) ;
F_47 ( V_74 -> V_75 . V_76 ) ;
F_72 ( V_74 ) ;
}
static void F_73 ( struct V_14 * V_15 )
{
struct V_73 * V_74 , * V_97 ;
F_74 ( & V_15 -> V_98 ) ;
F_75 (dest, nxt, &ipvs->dest_trash, t_list) {
F_69 ( & V_74 -> V_96 ) ;
F_71 ( V_74 ) ;
}
}
static void
F_76 ( struct V_99 * V_9 , struct V_100 * V_101 )
{
#define F_77 ( T_5 ) dst->c = src->kstats.c - src->kstats0.c
F_66 ( & V_101 -> V_102 ) ;
F_77 ( V_103 ) ;
F_77 ( V_104 ) ;
F_77 ( V_105 ) ;
F_77 ( V_106 ) ;
F_77 ( V_107 ) ;
F_78 ( V_9 , V_101 ) ;
F_70 ( & V_101 -> V_102 ) ;
}
static void
F_79 ( struct V_108 * V_9 , struct V_99 * V_101 )
{
V_9 -> V_103 = ( V_109 ) V_101 -> V_103 ;
V_9 -> V_104 = ( V_109 ) V_101 -> V_104 ;
V_9 -> V_105 = ( V_109 ) V_101 -> V_105 ;
V_9 -> V_106 = V_101 -> V_106 ;
V_9 -> V_107 = V_101 -> V_107 ;
V_9 -> V_110 = ( V_109 ) V_101 -> V_110 ;
V_9 -> V_111 = ( V_109 ) V_101 -> V_111 ;
V_9 -> V_112 = ( V_109 ) V_101 -> V_112 ;
V_9 -> V_113 = ( V_109 ) V_101 -> V_113 ;
V_9 -> V_114 = ( V_109 ) V_101 -> V_114 ;
}
static void
F_80 ( struct V_100 * V_75 )
{
F_66 ( & V_75 -> V_102 ) ;
#define F_81 ( T_5 ) stats->kstats0.c = stats->kstats.c
F_81 ( V_103 ) ;
F_81 ( V_104 ) ;
F_81 ( V_105 ) ;
F_81 ( V_106 ) ;
F_81 ( V_107 ) ;
F_82 ( V_75 ) ;
F_70 ( & V_75 -> V_102 ) ;
}
static void
F_83 ( struct V_54 * V_55 , struct V_73 * V_74 ,
struct V_115 * V_116 , int V_117 )
{
struct V_14 * V_15 = V_55 -> V_15 ;
struct V_54 * V_118 ;
struct V_119 * V_120 ;
int V_121 ;
F_84 ( ! V_117 && V_116 -> V_40 != V_74 -> V_40 ) ;
if ( V_117 && V_116 -> V_40 != V_55 -> V_40 )
V_15 -> V_122 ++ ;
F_9 ( & V_74 -> V_123 , V_116 -> V_123 ) ;
V_121 = V_116 -> V_121 & V_124 ;
V_121 |= V_125 ;
if ( ( V_121 & V_89 ) != V_90 ) {
V_121 |= V_126 ;
} else {
F_54 ( V_15 , V_74 ) ;
}
F_9 ( & V_74 -> V_121 , V_121 ) ;
V_118 = F_63 ( V_74 -> V_55 , 1 ) ;
if ( ! V_118 ) {
F_44 ( V_74 , V_55 ) ;
} else {
if ( V_118 != V_55 ) {
F_80 ( & V_74 -> V_75 ) ;
F_44 ( V_74 , V_55 ) ;
F_50 ( V_118 , true ) ;
}
}
V_74 -> V_12 |= V_127 ;
if ( V_116 -> V_128 == 0 || V_116 -> V_128 > V_74 -> V_128 )
V_74 -> V_12 &= ~ V_129 ;
V_74 -> V_128 = V_116 -> V_128 ;
V_74 -> V_130 = V_116 -> V_130 ;
V_74 -> V_40 = V_116 -> V_40 ;
F_66 ( & V_74 -> V_131 ) ;
F_62 ( V_74 ) ;
F_70 ( & V_74 -> V_131 ) ;
if ( V_117 ) {
F_85 ( V_55 -> V_15 , & V_74 -> V_75 ) ;
F_86 ( & V_74 -> V_132 , & V_55 -> V_133 ) ;
V_55 -> V_134 ++ ;
V_120 = F_63 ( V_55 -> V_135 , 1 ) ;
if ( V_120 && V_120 -> V_136 )
V_120 -> V_136 ( V_55 , V_74 ) ;
} else {
V_120 = F_63 ( V_55 -> V_135 , 1 ) ;
if ( V_120 && V_120 -> V_137 )
V_120 -> V_137 ( V_55 , V_74 ) ;
}
}
static int
F_87 ( struct V_54 * V_55 , struct V_115 * V_116 ,
struct V_73 * * V_138 )
{
struct V_73 * V_74 ;
unsigned int V_139 , V_17 ;
F_88 ( 2 ) ;
#ifdef F_24
if ( V_116 -> V_40 == V_48 ) {
V_139 = F_89 ( & V_116 -> V_4 . V_140 ) ;
if ( ( ! ( V_139 & V_141 ) ||
V_139 & V_142 ) &&
! F_2 ( V_55 -> V_15 -> V_2 , & V_116 -> V_4 . V_140 ) )
return - V_143 ;
} else
#endif
{
V_139 = F_90 ( V_55 -> V_15 -> V_2 , V_116 -> V_4 . V_46 ) ;
if ( V_139 != V_144 && V_139 != V_145 )
return - V_143 ;
}
V_74 = F_91 ( sizeof( struct V_73 ) , V_146 ) ;
if ( V_74 == NULL )
return - V_147 ;
V_74 -> V_75 . V_76 = F_92 ( struct V_148 ) ;
if ( ! V_74 -> V_75 . V_76 )
goto V_149;
F_93 (i) {
struct V_148 * V_150 ;
V_150 = F_94 ( V_74 -> V_75 . V_76 , V_17 ) ;
F_95 ( & V_150 -> V_151 ) ;
}
V_74 -> V_40 = V_116 -> V_40 ;
V_74 -> V_59 = V_55 -> V_59 ;
V_74 -> V_65 = V_55 -> V_4 ;
V_74 -> V_66 = V_55 -> V_43 ;
V_74 -> V_86 = V_55 -> V_53 ;
F_96 ( V_116 -> V_40 , & V_74 -> V_4 , & V_116 -> V_4 ) ;
V_74 -> V_43 = V_116 -> V_43 ;
F_9 ( & V_74 -> V_152 , 0 ) ;
F_9 ( & V_74 -> V_153 , 0 ) ;
F_9 ( & V_74 -> V_154 , 0 ) ;
F_97 ( & V_74 -> V_64 , 1 ) ;
F_98 ( & V_74 -> V_83 ) ;
F_99 ( & V_74 -> V_131 ) ;
F_99 ( & V_74 -> V_75 . V_102 ) ;
F_83 ( V_55 , V_74 , V_116 , 1 ) ;
* V_138 = V_74 ;
F_100 ( 2 ) ;
return 0 ;
V_149:
F_48 ( V_74 ) ;
return - V_147 ;
}
static int
F_101 ( struct V_54 * V_55 , struct V_115 * V_116 )
{
struct V_73 * V_74 ;
union V_42 V_7 ;
T_1 V_85 = V_116 -> V_43 ;
int V_155 ;
F_88 ( 2 ) ;
if ( V_116 -> V_123 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_156 ;
}
if ( V_116 -> V_130 > V_116 -> V_128 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_156 ;
}
F_96 ( V_116 -> V_40 , & V_7 , & V_116 -> V_4 ) ;
F_102 () ;
V_74 = F_58 ( V_55 , V_116 -> V_40 , & V_7 , V_85 ) ;
F_103 () ;
if ( V_74 != NULL ) {
F_104 ( 1 , L_11 , V_58 ) ;
return - V_157 ;
}
V_74 = F_65 ( V_55 , V_116 -> V_40 , & V_7 , V_85 ) ;
if ( V_74 != NULL ) {
F_41 ( 3 , L_12
L_13 ,
F_43 ( V_116 -> V_40 , & V_7 ) , F_23 ( V_85 ) ,
F_68 ( & V_74 -> V_64 ) ,
V_74 -> V_86 ,
F_43 ( V_55 -> V_40 , & V_74 -> V_65 ) ,
F_23 ( V_74 -> V_66 ) ) ;
F_83 ( V_55 , V_74 , V_116 , 1 ) ;
V_155 = 0 ;
} else {
V_155 = F_87 ( V_55 , V_116 , & V_74 ) ;
}
F_100 ( 2 ) ;
return V_155 ;
}
static int
F_105 ( struct V_54 * V_55 , struct V_115 * V_116 )
{
struct V_73 * V_74 ;
union V_42 V_7 ;
T_1 V_85 = V_116 -> V_43 ;
F_88 ( 2 ) ;
if ( V_116 -> V_123 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_156 ;
}
if ( V_116 -> V_130 > V_116 -> V_128 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_156 ;
}
F_96 ( V_116 -> V_40 , & V_7 , & V_116 -> V_4 ) ;
F_102 () ;
V_74 = F_58 ( V_55 , V_116 -> V_40 , & V_7 , V_85 ) ;
F_103 () ;
if ( V_74 == NULL ) {
F_104 ( 1 , L_14 , V_58 ) ;
return - V_158 ;
}
F_83 ( V_55 , V_74 , V_116 , 0 ) ;
F_100 ( 2 ) ;
return 0 ;
}
static void F_106 ( struct V_14 * V_15 , struct V_73 * V_74 ,
bool V_159 )
{
F_107 ( V_15 , & V_74 -> V_75 ) ;
F_55 ( V_74 ) ;
F_66 ( & V_15 -> V_95 ) ;
F_41 ( 3 , L_15 ,
F_43 ( V_74 -> V_40 , & V_74 -> V_4 ) , F_23 ( V_74 -> V_43 ) ,
F_68 ( & V_74 -> V_64 ) ) ;
if ( F_108 ( & V_15 -> V_160 ) && ! V_159 )
F_109 ( & V_15 -> V_98 ,
V_161 + ( V_162 >> 1 ) ) ;
F_110 ( & V_74 -> V_96 , & V_15 -> V_160 ) ;
V_74 -> V_163 = 0 ;
F_70 ( & V_15 -> V_95 ) ;
}
static void F_111 ( struct V_54 * V_55 ,
struct V_73 * V_74 ,
int V_164 )
{
V_74 -> V_12 &= ~ V_127 ;
F_112 ( & V_74 -> V_132 ) ;
V_55 -> V_134 -- ;
if ( V_74 -> V_40 != V_55 -> V_40 )
V_55 -> V_15 -> V_122 -- ;
if ( V_164 ) {
struct V_119 * V_120 ;
V_120 = F_63 ( V_55 -> V_135 , 1 ) ;
if ( V_120 && V_120 -> V_165 )
V_120 -> V_165 ( V_55 , V_74 ) ;
}
}
static int
F_113 ( struct V_54 * V_55 , struct V_115 * V_116 )
{
struct V_73 * V_74 ;
T_1 V_85 = V_116 -> V_43 ;
F_88 ( 2 ) ;
F_102 () ;
V_74 = F_58 ( V_55 , V_116 -> V_40 , & V_116 -> V_4 , V_85 ) ;
F_103 () ;
if ( V_74 == NULL ) {
F_104 ( 1 , L_16 , V_58 ) ;
return - V_158 ;
}
F_111 ( V_55 , V_74 , 1 ) ;
F_106 ( V_55 -> V_15 , V_74 , false ) ;
F_100 ( 2 ) ;
return 0 ;
}
static void F_114 ( unsigned long V_166 )
{
struct V_14 * V_15 = (struct V_14 * ) V_166 ;
struct V_73 * V_74 , * V_167 ;
unsigned long V_168 = V_161 ;
F_8 ( & V_15 -> V_95 ) ;
F_75 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_68 ( & V_74 -> V_64 ) > 1 )
continue;
if ( V_74 -> V_163 ) {
if ( F_115 ( V_168 , V_74 -> V_163 +
V_162 ) )
continue;
} else {
V_74 -> V_163 = F_116 ( 1UL , V_168 ) ;
continue;
}
F_41 ( 3 , L_17 ,
V_74 -> V_86 ,
F_43 ( V_74 -> V_40 , & V_74 -> V_4 ) ,
F_23 ( V_74 -> V_43 ) ) ;
F_69 ( & V_74 -> V_96 ) ;
F_71 ( V_74 ) ;
}
if ( ! F_108 ( & V_15 -> V_160 ) )
F_109 ( & V_15 -> V_98 ,
V_161 + ( V_162 >> 1 ) ) ;
F_10 ( & V_15 -> V_95 ) ;
}
static int
F_117 ( struct V_14 * V_15 , struct V_169 * V_170 ,
struct V_54 * * V_171 )
{
int V_155 = 0 , V_17 ;
struct V_119 * V_120 = NULL ;
struct V_172 * V_173 = NULL ;
struct V_54 * V_55 = NULL ;
F_18 () ;
if ( strcmp ( V_170 -> V_174 , L_18 ) ) {
V_120 = F_118 ( V_170 -> V_174 ) ;
if ( ! V_120 ) {
F_119 ( L_19 ,
V_170 -> V_174 ) ;
V_155 = - V_158 ;
goto V_175;
}
}
if ( V_170 -> V_176 && * V_170 -> V_176 ) {
V_173 = F_120 ( V_170 -> V_176 ) ;
if ( V_173 == NULL ) {
F_119 ( L_20
L_21 , V_170 -> V_176 ) ;
V_155 = - V_158 ;
goto V_175;
}
}
#ifdef F_24
if ( V_170 -> V_40 == V_48 ) {
T_3 V_177 = ( V_178 T_3 ) V_170 -> V_179 ;
if ( V_177 < 1 || V_177 > 128 ) {
V_155 = - V_143 ;
goto V_175;
}
}
#endif
V_55 = F_91 ( sizeof( struct V_54 ) , V_146 ) ;
if ( V_55 == NULL ) {
F_104 ( 1 , L_22 , V_58 ) ;
V_155 = - V_147 ;
goto V_175;
}
V_55 -> V_75 . V_76 = F_92 ( struct V_148 ) ;
if ( ! V_55 -> V_75 . V_76 ) {
V_155 = - V_147 ;
goto V_175;
}
F_93 (i) {
struct V_148 * V_100 ;
V_100 = F_94 ( V_55 -> V_75 . V_76 , V_17 ) ;
F_95 ( & V_100 -> V_151 ) ;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_170 -> V_40 ;
V_55 -> V_59 = V_170 -> V_59 ;
F_96 ( V_55 -> V_40 , & V_55 -> V_4 , & V_170 -> V_4 ) ;
V_55 -> V_43 = V_170 -> V_43 ;
V_55 -> V_53 = V_170 -> V_53 ;
V_55 -> V_12 = V_170 -> V_12 ;
V_55 -> V_180 = V_170 -> V_180 * V_181 ;
V_55 -> V_179 = V_170 -> V_179 ;
V_55 -> V_15 = V_15 ;
F_121 ( & V_55 -> V_133 ) ;
F_99 ( & V_55 -> V_182 ) ;
F_99 ( & V_55 -> V_75 . V_102 ) ;
if ( V_120 ) {
V_155 = F_122 ( V_55 , V_120 ) ;
if ( V_155 )
goto V_175;
V_120 = NULL ;
}
F_64 ( V_55 -> V_173 , V_173 ) ;
V_173 = NULL ;
if ( V_55 -> V_43 == V_71 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_72 ) ;
if ( V_55 -> V_173 && V_55 -> V_173 -> V_183 )
F_31 ( & V_15 -> V_184 ) ;
F_85 ( V_15 , & V_55 -> V_75 ) ;
if ( V_55 -> V_40 == V_185 )
V_15 -> V_186 ++ ;
F_27 ( V_55 ) ;
* V_171 = V_55 ;
V_15 -> V_187 = 1 ;
return 0 ;
V_175:
if ( V_55 != NULL ) {
F_123 ( V_55 , V_120 ) ;
F_46 ( V_55 ) ;
}
F_124 ( V_120 ) ;
F_125 ( V_173 ) ;
F_20 () ;
return V_155 ;
}
static int
F_126 ( struct V_54 * V_55 , struct V_169 * V_170 )
{
struct V_119 * V_120 = NULL , * V_188 ;
struct V_172 * V_173 = NULL , * V_189 = NULL ;
int V_155 = 0 ;
bool V_190 , V_191 ;
if ( strcmp ( V_170 -> V_174 , L_18 ) ) {
V_120 = F_118 ( V_170 -> V_174 ) ;
if ( ! V_120 ) {
F_119 ( L_19 ,
V_170 -> V_174 ) ;
return - V_158 ;
}
}
V_188 = V_120 ;
if ( V_170 -> V_176 && * V_170 -> V_176 ) {
V_173 = F_120 ( V_170 -> V_176 ) ;
if ( V_173 == NULL ) {
F_119 ( L_20
L_21 , V_170 -> V_176 ) ;
V_155 = - V_158 ;
goto V_67;
}
V_189 = V_173 ;
}
#ifdef F_24
if ( V_170 -> V_40 == V_48 ) {
T_3 V_177 = ( V_178 T_3 ) V_170 -> V_179 ;
if ( V_177 < 1 || V_177 > 128 ) {
V_155 = - V_143 ;
goto V_67;
}
}
#endif
V_188 = F_63 ( V_55 -> V_135 , 1 ) ;
if ( V_120 != V_188 ) {
if ( V_188 ) {
F_123 ( V_55 , V_188 ) ;
F_64 ( V_55 -> V_135 , NULL ) ;
F_127 () ;
}
if ( V_120 ) {
V_155 = F_122 ( V_55 , V_120 ) ;
if ( V_155 ) {
F_124 ( V_120 ) ;
goto V_67;
}
}
}
V_55 -> V_12 = V_170 -> V_12 | V_57 ;
V_55 -> V_180 = V_170 -> V_180 * V_181 ;
V_55 -> V_179 = V_170 -> V_179 ;
V_189 = F_63 ( V_55 -> V_173 , 1 ) ;
if ( V_173 != V_189 ) {
F_45 ( V_55 -> V_173 , V_173 ) ;
V_190 = ( V_173 && V_173 -> V_183 ) ? true : false ;
V_191 = ( V_189 && V_189 -> V_183 ) ? true : false ;
if ( V_190 && ! V_191 )
F_31 ( & V_55 -> V_15 -> V_184 ) ;
if ( V_191 && ! V_190 )
F_34 ( & V_55 -> V_15 -> V_184 ) ;
}
V_67:
F_124 ( V_188 ) ;
F_125 ( V_189 ) ;
return V_155 ;
}
static void F_128 ( struct V_54 * V_55 , bool V_159 )
{
struct V_73 * V_74 , * V_97 ;
struct V_119 * V_188 ;
struct V_172 * V_189 ;
struct V_14 * V_15 = V_55 -> V_15 ;
if ( V_55 -> V_40 == V_185 )
V_15 -> V_186 -- ;
F_107 ( V_55 -> V_15 , & V_55 -> V_75 ) ;
V_188 = F_63 ( V_55 -> V_135 , 1 ) ;
F_123 ( V_55 , V_188 ) ;
F_124 ( V_188 ) ;
V_189 = F_63 ( V_55 -> V_173 , 1 ) ;
if ( V_189 && V_189 -> V_183 )
F_34 ( & V_15 -> V_184 ) ;
F_125 ( V_189 ) ;
F_75 (dest, nxt, &svc->destinations, n_list) {
F_111 ( V_55 , V_74 , 0 ) ;
F_106 ( V_55 -> V_15 , V_74 , V_159 ) ;
}
if ( V_55 -> V_43 == V_71 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_72 ) ;
F_50 ( V_55 , true ) ;
F_20 () ;
}
static void F_129 ( struct V_54 * V_55 , bool V_159 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_128 ( V_55 , V_159 ) ;
}
static int F_130 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_157 ;
F_129 ( V_55 , false ) ;
return 0 ;
}
static int F_131 ( struct V_14 * V_15 , bool V_159 )
{
int V_192 ;
struct V_54 * V_55 ;
struct V_193 * V_194 ;
for( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_132 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( V_55 -> V_15 == V_15 )
F_129 ( V_55 , V_159 ) ;
}
}
for( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_132 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( V_55 -> V_15 == V_15 )
F_129 ( V_55 , V_159 ) ;
}
}
return 0 ;
}
void F_133 ( struct V_14 * V_15 )
{
F_88 ( 2 ) ;
F_134 ( & V_196 ) ;
F_131 ( V_15 , true ) ;
F_135 ( & V_196 ) ;
F_100 ( 2 ) ;
}
static inline void
F_136 ( struct V_73 * V_74 , struct V_197 * V_11 )
{
struct V_91 * V_92 ;
F_66 ( & V_74 -> V_131 ) ;
V_92 = F_63 ( V_74 -> V_92 , 1 ) ;
if ( V_92 && V_92 -> V_93 -> V_11 == V_11 ) {
F_41 ( 3 , L_23 ,
V_11 -> V_198 ,
F_43 ( V_74 -> V_40 , & V_74 -> V_4 ) ,
F_23 ( V_74 -> V_43 ) ,
F_68 ( & V_74 -> V_64 ) ) ;
F_62 ( V_74 ) ;
}
F_70 ( & V_74 -> V_131 ) ;
}
static int F_137 ( struct V_199 * V_200 , unsigned long V_201 ,
void * V_202 )
{
struct V_197 * V_11 = F_138 ( V_202 ) ;
struct V_2 * V_2 = F_139 ( V_11 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_73 * V_74 ;
unsigned int V_192 ;
if ( V_201 != V_203 || ! V_15 )
return V_204 ;
F_104 ( 3 , L_24 , V_58 , V_11 -> V_198 ) ;
F_88 ( 2 ) ;
F_134 ( & V_196 ) ;
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_141 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_15 == V_15 ) {
F_67 (dest, &svc->destinations,
n_list) {
F_136 ( V_74 , V_11 ) ;
}
}
}
F_141 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_15 == V_15 ) {
F_67 (dest, &svc->destinations,
n_list) {
F_136 ( V_74 , V_11 ) ;
}
}
}
}
F_66 ( & V_15 -> V_95 ) ;
F_67 (dest, &ipvs->dest_trash, t_list) {
F_136 ( V_74 , V_11 ) ;
}
F_70 ( & V_15 -> V_95 ) ;
F_135 ( & V_196 ) ;
F_100 ( 2 ) ;
return V_204 ;
}
static int F_142 ( struct V_54 * V_55 )
{
struct V_73 * V_74 ;
F_67 (dest, &svc->destinations, n_list) {
F_80 ( & V_74 -> V_75 ) ;
}
F_80 ( & V_55 -> V_75 ) ;
return 0 ;
}
static int F_143 ( struct V_14 * V_15 )
{
int V_192 ;
struct V_54 * V_55 ;
for( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_141 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_15 == V_15 )
F_142 ( V_55 ) ;
}
}
for( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_141 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_15 == V_15 )
F_142 ( V_55 ) ;
}
}
F_80 ( & V_15 -> V_205 ) ;
return 0 ;
}
static int
F_144 ( struct V_206 * V_207 , int V_208 ,
void T_6 * V_209 , V_50 * V_210 , T_7 * V_211 )
{
struct V_14 * V_15 = V_207 -> V_212 ;
int * V_213 = V_207 -> V_166 ;
int V_214 = * V_213 ;
int V_215 ;
V_215 = F_145 ( V_207 , V_208 , V_209 , V_210 , V_211 ) ;
if ( V_208 && ( * V_213 != V_214 ) ) {
if ( ( * V_213 < 0 ) || ( * V_213 > 3 ) ) {
* V_213 = V_214 ;
} else {
F_5 ( V_15 ) ;
}
}
return V_215 ;
}
static int
F_146 ( struct V_206 * V_207 , int V_208 ,
void T_6 * V_209 , V_50 * V_210 , T_7 * V_211 )
{
int * V_213 = V_207 -> V_166 ;
int V_214 [ 2 ] ;
int V_215 ;
memcpy ( V_214 , V_213 , sizeof( V_214 ) ) ;
V_215 = F_145 ( V_207 , V_208 , V_209 , V_210 , V_211 ) ;
if ( V_208 && ( V_213 [ 0 ] < 0 || V_213 [ 1 ] < 0 ||
( V_213 [ 0 ] >= V_213 [ 1 ] && V_213 [ 1 ] ) ) ) {
memcpy ( V_213 , V_214 , sizeof( V_214 ) ) ;
}
return V_215 ;
}
static int
F_147 ( struct V_206 * V_207 , int V_208 ,
void T_6 * V_209 , V_50 * V_210 , T_7 * V_211 )
{
int * V_213 = V_207 -> V_166 ;
int V_214 = * V_213 ;
int V_215 ;
V_215 = F_145 ( V_207 , V_208 , V_209 , V_210 , V_211 ) ;
if ( V_208 && ( * V_213 != V_214 ) ) {
if ( ( * V_213 < 0 ) || ( * V_213 > 1 ) ) {
* V_213 = V_214 ;
}
}
return V_215 ;
}
static int
F_148 ( struct V_206 * V_207 , int V_208 ,
void T_6 * V_209 , V_50 * V_210 , T_7 * V_211 )
{
int * V_213 = V_207 -> V_166 ;
int V_214 = * V_213 ;
int V_215 ;
V_215 = F_145 ( V_207 , V_208 , V_209 , V_210 , V_211 ) ;
if ( V_208 && ( * V_213 != V_214 ) ) {
if ( * V_213 < 1 || ! F_149 ( * V_213 ) ) {
* V_213 = V_214 ;
}
}
return V_215 ;
}
static inline const char * F_150 ( unsigned int V_12 )
{
switch ( V_12 & V_89 ) {
case V_216 :
return L_25 ;
case V_217 :
return L_26 ;
case V_218 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_151 ( struct V_219 * V_220 , T_7 V_221 )
{
struct V_2 * V_2 = F_152 ( V_220 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
struct V_222 * V_223 = V_220 -> V_224 ;
int V_192 ;
struct V_54 * V_55 ;
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( ( V_55 -> V_15 == V_15 ) && V_221 -- == 0 ) {
V_223 -> V_207 = V_61 ;
V_223 -> V_225 = V_192 ;
return V_55 ;
}
}
}
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( ( V_55 -> V_15 == V_15 ) && V_221 -- == 0 ) {
V_223 -> V_207 = V_63 ;
V_223 -> V_225 = V_192 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_153 ( struct V_219 * V_220 , T_7 * V_221 )
__acquires( T_8 )
{
F_102 () ;
return * V_221 ? F_151 ( V_220 , * V_221 - 1 ) : V_226 ;
}
static void * F_154 ( struct V_219 * V_220 , void * V_227 , T_7 * V_221 )
{
struct V_193 * V_228 ;
struct V_222 * V_223 ;
struct V_54 * V_55 ;
++ * V_221 ;
if ( V_227 == V_226 )
return F_151 ( V_220 , 0 ) ;
V_55 = V_227 ;
V_223 = V_220 -> V_224 ;
if ( V_223 -> V_207 == V_61 ) {
V_228 = F_155 ( F_156 ( & V_55 -> V_60 ) ) ;
if ( V_228 )
return F_157 ( V_228 , struct V_54 , V_60 ) ;
while ( ++ V_223 -> V_225 < V_195 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_223 -> V_207 = V_63 ;
V_223 -> V_225 = - 1 ;
goto V_229;
}
V_228 = F_155 ( F_156 ( & V_55 -> V_62 ) ) ;
if ( V_228 )
return F_157 ( V_228 , struct V_54 , V_62 ) ;
V_229:
while ( ++ V_223 -> V_225 < V_195 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_158 ( struct V_219 * V_220 , void * V_227 )
__releases( T_8 )
{
F_103 () ;
}
static int F_159 ( struct V_219 * V_220 , void * V_227 )
{
if ( V_227 == V_226 ) {
F_160 ( V_220 ,
L_29 ,
F_161 ( V_230 ) , V_231 ) ;
F_162 ( V_220 ,
L_30 ) ;
F_162 ( V_220 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_227 ;
const struct V_222 * V_223 = V_220 -> V_224 ;
const struct V_73 * V_74 ;
struct V_119 * V_120 = F_155 ( V_55 -> V_135 ) ;
char * V_174 = V_120 ? V_120 -> V_198 : L_18 ;
if ( V_223 -> V_207 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_160 ( V_220 , L_32 ,
F_42 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_140 ,
F_23 ( V_55 -> V_43 ) ,
V_174 ) ;
else
#endif
F_160 ( V_220 , L_33 ,
F_42 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_174 ,
( V_55 -> V_12 & V_232 ) ? L_34 : L_35 ) ;
} else {
F_160 ( V_220 , L_36 ,
V_55 -> V_53 , V_174 ,
( V_55 -> V_12 & V_232 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_233 )
F_160 ( V_220 , L_37 ,
V_55 -> V_180 ,
F_25 ( V_55 -> V_179 ) ) ;
else
F_163 ( V_220 , '\n' ) ;
F_59 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_74 -> V_40 == V_48 )
F_160 ( V_220 ,
L_38
L_39 ,
& V_74 -> V_4 . V_140 ,
F_23 ( V_74 -> V_43 ) ,
F_150 ( F_15 ( & V_74 -> V_121 ) ) ,
F_15 ( & V_74 -> V_123 ) ,
F_15 ( & V_74 -> V_152 ) ,
F_15 ( & V_74 -> V_153 ) ) ;
else
#endif
F_160 ( V_220 ,
L_40
L_41 ,
F_25 ( V_74 -> V_4 . V_46 ) ,
F_23 ( V_74 -> V_43 ) ,
F_150 ( F_15 ( & V_74 -> V_121 ) ) ,
F_15 ( & V_74 -> V_123 ) ,
F_15 ( & V_74 -> V_152 ) ,
F_15 ( & V_74 -> V_153 ) ) ;
}
}
return 0 ;
}
static int F_164 ( struct V_234 * V_234 , struct V_235 * V_235 )
{
return F_165 ( V_234 , V_235 , & V_236 ,
sizeof( struct V_222 ) ) ;
}
static int F_166 ( struct V_219 * V_220 , void * V_227 )
{
struct V_2 * V_2 = F_167 ( V_220 ) ;
struct V_99 V_237 ;
F_162 ( V_220 ,
L_42 ) ;
F_162 ( V_220 ,
L_43 ) ;
F_76 ( & V_237 , & F_140 ( V_2 ) -> V_205 ) ;
F_160 ( V_220 , L_44 ,
( unsigned long long ) V_237 . V_103 ,
( unsigned long long ) V_237 . V_104 ,
( unsigned long long ) V_237 . V_105 ,
( unsigned long long ) V_237 . V_106 ,
( unsigned long long ) V_237 . V_107 ) ;
F_162 ( V_220 ,
L_45 ) ;
F_160 ( V_220 , L_46 ,
( unsigned long long ) V_237 . V_110 ,
( unsigned long long ) V_237 . V_111 ,
( unsigned long long ) V_237 . V_112 ,
( unsigned long long ) V_237 . V_113 ,
( unsigned long long ) V_237 . V_114 ) ;
return 0 ;
}
static int F_168 ( struct V_234 * V_234 , struct V_235 * V_235 )
{
return F_169 ( V_234 , V_235 , F_166 ) ;
}
static int F_170 ( struct V_219 * V_220 , void * V_227 )
{
struct V_2 * V_2 = F_167 ( V_220 ) ;
struct V_100 * V_205 = & F_140 ( V_2 ) -> V_205 ;
struct V_148 T_9 * V_76 = V_205 -> V_76 ;
struct V_99 V_238 ;
int V_17 ;
F_162 ( V_220 ,
L_47 ) ;
F_162 ( V_220 ,
L_48 ) ;
F_93 (i) {
struct V_148 * V_170 = F_94 ( V_76 , V_17 ) ;
unsigned int V_239 ;
T_10 V_103 , V_104 , V_105 , V_106 , V_107 ;
do {
V_239 = F_171 ( & V_170 -> V_151 ) ;
V_103 = V_170 -> V_240 . V_103 ;
V_104 = V_170 -> V_240 . V_104 ;
V_105 = V_170 -> V_240 . V_105 ;
V_106 = V_170 -> V_240 . V_106 ;
V_107 = V_170 -> V_240 . V_107 ;
} while ( F_172 ( & V_170 -> V_151 , V_239 ) );
F_160 ( V_220 , L_49 ,
V_17 , ( T_10 ) V_103 , ( T_10 ) V_104 ,
( T_10 ) V_105 , ( T_10 ) V_106 ,
( T_10 ) V_107 ) ;
}
F_76 ( & V_238 , V_205 ) ;
F_160 ( V_220 , L_50 ,
( unsigned long long ) V_238 . V_103 ,
( unsigned long long ) V_238 . V_104 ,
( unsigned long long ) V_238 . V_105 ,
( unsigned long long ) V_238 . V_106 ,
( unsigned long long ) V_238 . V_107 ) ;
F_162 ( V_220 ,
L_51 ) ;
F_160 ( V_220 , L_52 ,
V_238 . V_110 ,
V_238 . V_111 ,
V_238 . V_112 ,
V_238 . V_113 ,
V_238 . V_114 ) ;
return 0 ;
}
static int F_173 ( struct V_234 * V_234 , struct V_235 * V_235 )
{
return F_169 ( V_234 , V_235 , F_170 ) ;
}
static int F_174 ( struct V_14 * V_15 , struct V_241 * V_170 )
{
#if F_175 ( V_242 ) || F_175 ( V_243 )
struct V_244 * V_245 ;
#endif
F_104 ( 2 , L_53 ,
V_170 -> V_246 ,
V_170 -> V_247 ,
V_170 -> V_248 ) ;
#ifdef V_242
if ( V_170 -> V_246 ) {
V_245 = F_176 ( V_15 , V_68 ) ;
V_245 -> V_249 [ V_250 ]
= V_170 -> V_246 * V_181 ;
}
if ( V_170 -> V_247 ) {
V_245 = F_176 ( V_15 , V_68 ) ;
V_245 -> V_249 [ V_251 ]
= V_170 -> V_247 * V_181 ;
}
#endif
#ifdef V_243
if ( V_170 -> V_248 ) {
V_245 = F_176 ( V_15 , V_252 ) ;
V_245 -> V_249 [ V_253 ]
= V_170 -> V_248 * V_181 ;
}
#endif
return 0 ;
}
static void F_177 ( struct V_169 * V_254 ,
struct V_255 * V_256 )
{
memset ( V_254 , 0 , sizeof( * V_254 ) ) ;
V_254 -> V_40 = V_185 ;
V_254 -> V_59 = V_256 -> V_59 ;
V_254 -> V_4 . V_46 = V_256 -> V_4 ;
V_254 -> V_43 = V_256 -> V_43 ;
V_254 -> V_53 = V_256 -> V_53 ;
V_254 -> V_174 = V_256 -> V_174 ;
V_254 -> V_12 = V_256 -> V_12 ;
V_254 -> V_180 = V_256 -> V_180 ;
V_254 -> V_179 = V_256 -> V_179 ;
}
static void F_178 ( struct V_115 * V_116 ,
struct V_257 * V_258 )
{
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
V_116 -> V_4 . V_46 = V_258 -> V_4 ;
V_116 -> V_43 = V_258 -> V_43 ;
V_116 -> V_121 = V_258 -> V_121 ;
V_116 -> V_123 = V_258 -> V_123 ;
V_116 -> V_128 = V_258 -> V_128 ;
V_116 -> V_130 = V_258 -> V_130 ;
V_116 -> V_40 = V_185 ;
}
static int
F_179 ( struct V_259 * V_260 , int V_261 , void T_6 * V_262 , unsigned int V_263 )
{
struct V_2 * V_2 = F_180 ( V_260 ) ;
int V_155 ;
unsigned char V_264 [ V_265 ] ;
struct V_255 * V_256 ;
struct V_169 V_254 ;
struct V_54 * V_55 ;
struct V_257 * V_258 ;
struct V_115 V_116 ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
F_181 ( sizeof( V_264 ) > 255 ) ;
if ( ! F_182 ( F_180 ( V_260 ) -> V_266 , V_267 ) )
return - V_268 ;
if ( V_261 < V_269 || V_261 > V_270 )
return - V_143 ;
if ( V_263 != V_271 [ F_183 ( V_261 ) ] ) {
F_104 ( 1 , L_54 ,
V_263 , V_271 [ F_183 ( V_261 ) ] ) ;
return - V_143 ;
}
if ( F_184 ( V_264 , V_262 , V_263 ) != 0 )
return - V_272 ;
F_18 () ;
if ( V_261 == V_273 ||
V_261 == V_274 ) {
struct V_275 * V_276 = (struct V_275 * ) V_264 ;
if ( V_261 == V_273 ) {
struct V_277 V_278 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
F_185 ( V_278 . V_279 , V_276 -> V_279 ,
sizeof( V_278 . V_279 ) ) ;
V_278 . V_280 = V_276 -> V_280 ;
F_186 () ;
F_134 ( & V_15 -> V_281 ) ;
V_155 = F_187 ( V_15 , & V_278 , V_276 -> V_282 ) ;
F_135 ( & V_15 -> V_281 ) ;
F_188 () ;
} else {
F_134 ( & V_15 -> V_281 ) ;
V_155 = F_189 ( V_15 , V_276 -> V_282 ) ;
F_135 ( & V_15 -> V_281 ) ;
}
goto V_283;
}
F_134 ( & V_196 ) ;
if ( V_261 == V_284 ) {
V_155 = F_131 ( V_15 , false ) ;
goto V_285;
} else if ( V_261 == V_286 ) {
V_155 = F_174 ( V_15 , (struct V_241 * ) V_264 ) ;
goto V_285;
}
V_256 = (struct V_255 * ) V_264 ;
V_258 = (struct V_257 * ) ( V_256 + 1 ) ;
F_177 ( & V_254 , V_256 ) ;
F_178 ( & V_116 , V_258 ) ;
if ( V_261 == V_287 ) {
if ( ! V_254 . V_53 && ! V_254 . V_4 . V_46 && ! V_254 . V_43 ) {
V_155 = F_143 ( V_15 ) ;
goto V_285;
}
}
if ( V_254 . V_59 != V_68 && V_254 . V_59 != V_252 &&
V_254 . V_59 != V_288 ) {
F_28 ( L_55 ,
V_254 . V_59 , & V_254 . V_4 . V_46 ,
F_23 ( V_254 . V_43 ) , V_254 . V_174 ) ;
V_155 = - V_272 ;
goto V_285;
}
F_102 () ;
if ( V_254 . V_53 == 0 )
V_55 = F_35 ( V_15 , V_254 . V_40 , V_254 . V_59 ,
& V_254 . V_4 , V_254 . V_43 ) ;
else
V_55 = F_38 ( V_15 , V_254 . V_40 , V_254 . V_53 ) ;
F_103 () ;
if ( V_261 != V_289
&& ( V_55 == NULL || V_55 -> V_59 != V_254 . V_59 ) ) {
V_155 = - V_290 ;
goto V_285;
}
switch ( V_261 ) {
case V_289 :
if ( V_55 != NULL )
V_155 = - V_157 ;
else
V_155 = F_117 ( V_15 , & V_254 , & V_55 ) ;
break;
case V_291 :
V_155 = F_126 ( V_55 , & V_254 ) ;
break;
case V_292 :
V_155 = F_130 ( V_55 ) ;
if ( ! V_155 )
goto V_285;
break;
case V_287 :
V_155 = F_142 ( V_55 ) ;
break;
case V_293 :
V_155 = F_101 ( V_55 , & V_116 ) ;
break;
case V_294 :
V_155 = F_105 ( V_55 , & V_116 ) ;
break;
case V_295 :
V_155 = F_113 ( V_55 , & V_116 ) ;
break;
default:
V_155 = - V_143 ;
}
V_285:
F_135 ( & V_196 ) ;
V_283:
F_20 () ;
return V_155 ;
}
static void
F_190 ( struct V_296 * V_9 , struct V_54 * V_101 )
{
struct V_119 * V_120 ;
struct V_99 V_238 ;
char * V_174 ;
V_120 = F_63 ( V_101 -> V_135 , 1 ) ;
V_174 = V_120 ? V_120 -> V_198 : L_18 ;
V_9 -> V_59 = V_101 -> V_59 ;
V_9 -> V_4 = V_101 -> V_4 . V_46 ;
V_9 -> V_43 = V_101 -> V_43 ;
V_9 -> V_53 = V_101 -> V_53 ;
F_185 ( V_9 -> V_174 , V_174 , sizeof( V_9 -> V_174 ) ) ;
V_9 -> V_12 = V_101 -> V_12 ;
V_9 -> V_180 = V_101 -> V_180 / V_181 ;
V_9 -> V_179 = V_101 -> V_179 ;
V_9 -> V_134 = V_101 -> V_134 ;
F_76 ( & V_238 , & V_101 -> V_75 ) ;
F_79 ( & V_9 -> V_75 , & V_238 ) ;
}
static inline int
F_191 ( struct V_14 * V_15 ,
const struct V_297 * V_298 ,
struct V_297 T_6 * V_299 )
{
int V_192 , V_300 = 0 ;
struct V_54 * V_55 ;
struct V_296 V_301 ;
int V_155 = 0 ;
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_141 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_185 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( V_300 >= V_298 -> V_186 )
goto V_67;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
F_190 ( & V_301 , V_55 ) ;
if ( F_192 ( & V_299 -> V_302 [ V_300 ] ,
& V_301 , sizeof( V_301 ) ) ) {
V_155 = - V_272 ;
goto V_67;
}
V_300 ++ ;
}
}
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_141 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_185 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( V_300 >= V_298 -> V_186 )
goto V_67;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
F_190 ( & V_301 , V_55 ) ;
if ( F_192 ( & V_299 -> V_302 [ V_300 ] ,
& V_301 , sizeof( V_301 ) ) ) {
V_155 = - V_272 ;
goto V_67;
}
V_300 ++ ;
}
}
V_67:
return V_155 ;
}
static inline int
F_193 ( struct V_14 * V_15 , const struct V_303 * V_298 ,
struct V_303 T_6 * V_299 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_298 -> V_4 } ;
int V_155 = 0 ;
F_102 () ;
if ( V_298 -> V_53 )
V_55 = F_38 ( V_15 , V_185 , V_298 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_185 , V_298 -> V_59 , & V_4 ,
V_298 -> V_43 ) ;
F_103 () ;
if ( V_55 ) {
int V_300 = 0 ;
struct V_73 * V_74 ;
struct V_304 V_301 ;
struct V_99 V_238 ;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
F_67 (dest, &svc->destinations, n_list) {
if ( V_300 >= V_298 -> V_134 )
break;
if ( V_74 -> V_40 != V_55 -> V_40 )
continue;
V_301 . V_4 = V_74 -> V_4 . V_46 ;
V_301 . V_43 = V_74 -> V_43 ;
V_301 . V_121 = F_15 ( & V_74 -> V_121 ) ;
V_301 . V_123 = F_15 ( & V_74 -> V_123 ) ;
V_301 . V_128 = V_74 -> V_128 ;
V_301 . V_130 = V_74 -> V_130 ;
V_301 . V_152 = F_15 ( & V_74 -> V_152 ) ;
V_301 . V_153 = F_15 ( & V_74 -> V_153 ) ;
V_301 . V_154 = F_15 ( & V_74 -> V_154 ) ;
F_76 ( & V_238 , & V_74 -> V_75 ) ;
F_79 ( & V_301 . V_75 , & V_238 ) ;
if ( F_192 ( & V_299 -> V_302 [ V_300 ] ,
& V_301 , sizeof( V_301 ) ) ) {
V_155 = - V_272 ;
break;
}
V_300 ++ ;
}
} else
V_155 = - V_290 ;
return V_155 ;
}
static inline void
F_194 ( struct V_14 * V_15 , struct V_241 * V_170 )
{
#if F_175 ( V_242 ) || F_175 ( V_243 )
struct V_244 * V_245 ;
#endif
memset ( V_170 , 0 , sizeof ( * V_170 ) ) ;
#ifdef V_242
V_245 = F_176 ( V_15 , V_68 ) ;
V_170 -> V_246 = V_245 -> V_249 [ V_250 ] / V_181 ;
V_170 -> V_247 = V_245 -> V_249 [ V_251 ] / V_181 ;
#endif
#ifdef V_243
V_245 = F_176 ( V_15 , V_252 ) ;
V_170 -> V_248 =
V_245 -> V_249 [ V_253 ] / V_181 ;
#endif
}
static int
F_195 ( struct V_259 * V_260 , int V_261 , void T_6 * V_262 , int * V_263 )
{
unsigned char V_264 [ V_305 ] ;
int V_155 = 0 ;
unsigned int V_306 ;
struct V_2 * V_2 = F_180 ( V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
F_84 ( ! V_2 ) ;
F_181 ( sizeof( V_264 ) > 255 ) ;
if ( ! F_182 ( F_180 ( V_260 ) -> V_266 , V_267 ) )
return - V_268 ;
if ( V_261 < V_269 || V_261 > V_307 )
return - V_143 ;
V_306 = V_308 [ F_183 ( V_261 ) ] ;
if ( * V_263 < ( int ) V_306 ) {
F_104 ( 1 , L_56 , * V_263 , V_306 ) ;
return - V_143 ;
}
if ( F_184 ( V_264 , V_262 , V_306 ) != 0 )
return - V_272 ;
if ( V_261 == V_309 ) {
struct V_275 V_310 [ 2 ] ;
memset ( & V_310 , 0 , sizeof( V_310 ) ) ;
F_134 ( & V_15 -> V_281 ) ;
if ( V_15 -> V_311 & V_312 ) {
V_310 [ 0 ] . V_282 = V_312 ;
F_185 ( V_310 [ 0 ] . V_279 , V_15 -> V_313 . V_279 ,
sizeof( V_310 [ 0 ] . V_279 ) ) ;
V_310 [ 0 ] . V_280 = V_15 -> V_313 . V_280 ;
}
if ( V_15 -> V_311 & V_314 ) {
V_310 [ 1 ] . V_282 = V_314 ;
F_185 ( V_310 [ 1 ] . V_279 , V_15 -> V_315 . V_279 ,
sizeof( V_310 [ 1 ] . V_279 ) ) ;
V_310 [ 1 ] . V_280 = V_15 -> V_315 . V_280 ;
}
if ( F_192 ( V_262 , & V_310 , sizeof( V_310 ) ) != 0 )
V_155 = - V_272 ;
F_135 ( & V_15 -> V_281 ) ;
return V_155 ;
}
F_134 ( & V_196 ) ;
switch ( V_261 ) {
case V_316 :
{
char V_317 [ 64 ] ;
sprintf ( V_317 , L_57 ,
F_161 ( V_230 ) , V_231 ) ;
if ( F_192 ( V_262 , V_317 , strlen ( V_317 ) + 1 ) != 0 ) {
V_155 = - V_272 ;
goto V_67;
}
* V_263 = strlen ( V_317 ) + 1 ;
}
break;
case V_318 :
{
struct V_319 V_320 ;
V_320 . V_321 = V_230 ;
V_320 . V_322 = V_231 ;
V_320 . V_186 = V_15 -> V_186 ;
if ( F_192 ( V_262 , & V_320 , sizeof( V_320 ) ) != 0 )
V_155 = - V_272 ;
}
break;
case V_323 :
{
struct V_297 * V_298 ;
int V_322 ;
V_298 = (struct V_297 * ) V_264 ;
V_322 = sizeof( * V_298 ) +
sizeof( struct V_296 ) * V_298 -> V_186 ;
if ( * V_263 != V_322 ) {
F_28 ( L_58 , * V_263 , V_322 ) ;
V_155 = - V_143 ;
goto V_67;
}
V_155 = F_191 ( V_15 , V_298 , V_262 ) ;
}
break;
case V_324 :
{
struct V_296 * V_301 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_301 = (struct V_296 * ) V_264 ;
V_4 . V_46 = V_301 -> V_4 ;
F_102 () ;
if ( V_301 -> V_53 )
V_55 = F_38 ( V_15 , V_185 , V_301 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_185 ,
V_301 -> V_59 , & V_4 ,
V_301 -> V_43 ) ;
F_103 () ;
if ( V_55 ) {
F_190 ( V_301 , V_55 ) ;
if ( F_192 ( V_262 , V_301 , sizeof( * V_301 ) ) != 0 )
V_155 = - V_272 ;
} else
V_155 = - V_290 ;
}
break;
case V_325 :
{
struct V_303 * V_298 ;
int V_322 ;
V_298 = (struct V_303 * ) V_264 ;
V_322 = sizeof( * V_298 ) +
sizeof( struct V_304 ) * V_298 -> V_134 ;
if ( * V_263 != V_322 ) {
F_28 ( L_58 , * V_263 , V_322 ) ;
V_155 = - V_143 ;
goto V_67;
}
V_155 = F_193 ( V_15 , V_298 , V_262 ) ;
}
break;
case V_326 :
{
struct V_241 V_327 ;
F_194 ( V_15 , & V_327 ) ;
if ( F_192 ( V_262 , & V_327 , sizeof( V_327 ) ) != 0 )
V_155 = - V_272 ;
}
break;
default:
V_155 = - V_143 ;
}
V_67:
F_135 ( & V_196 ) ;
return V_155 ;
}
static int F_196 ( struct V_328 * V_329 , int V_330 ,
struct V_99 * V_238 )
{
struct V_331 * V_332 = F_197 ( V_329 , V_330 ) ;
if ( ! V_332 )
return - V_333 ;
if ( F_198 ( V_329 , V_334 , ( V_109 ) V_238 -> V_103 ) ||
F_198 ( V_329 , V_335 , ( V_109 ) V_238 -> V_104 ) ||
F_198 ( V_329 , V_336 , ( V_109 ) V_238 -> V_105 ) ||
F_199 ( V_329 , V_337 , V_238 -> V_106 ,
V_338 ) ||
F_199 ( V_329 , V_339 , V_238 -> V_107 ,
V_338 ) ||
F_198 ( V_329 , V_340 , ( V_109 ) V_238 -> V_110 ) ||
F_198 ( V_329 , V_341 , ( V_109 ) V_238 -> V_111 ) ||
F_198 ( V_329 , V_342 , ( V_109 ) V_238 -> V_112 ) ||
F_198 ( V_329 , V_343 , ( V_109 ) V_238 -> V_113 ) ||
F_198 ( V_329 , V_344 , ( V_109 ) V_238 -> V_114 ) )
goto V_345;
F_200 ( V_329 , V_332 ) ;
return 0 ;
V_345:
F_201 ( V_329 , V_332 ) ;
return - V_333 ;
}
static int F_202 ( struct V_328 * V_329 , int V_330 ,
struct V_99 * V_238 )
{
struct V_331 * V_332 = F_197 ( V_329 , V_330 ) ;
if ( ! V_332 )
return - V_333 ;
if ( F_199 ( V_329 , V_334 , V_238 -> V_103 ,
V_338 ) ||
F_199 ( V_329 , V_335 , V_238 -> V_104 ,
V_338 ) ||
F_199 ( V_329 , V_336 , V_238 -> V_105 ,
V_338 ) ||
F_199 ( V_329 , V_337 , V_238 -> V_106 ,
V_338 ) ||
F_199 ( V_329 , V_339 , V_238 -> V_107 ,
V_338 ) ||
F_199 ( V_329 , V_340 , V_238 -> V_110 ,
V_338 ) ||
F_199 ( V_329 , V_341 , V_238 -> V_111 ,
V_338 ) ||
F_199 ( V_329 , V_342 , V_238 -> V_112 ,
V_338 ) ||
F_199 ( V_329 , V_343 , V_238 -> V_113 ,
V_338 ) ||
F_199 ( V_329 , V_344 , V_238 -> V_114 ,
V_338 ) )
goto V_345;
F_200 ( V_329 , V_332 ) ;
return 0 ;
V_345:
F_201 ( V_329 , V_332 ) ;
return - V_333 ;
}
static int F_203 ( struct V_328 * V_329 ,
struct V_54 * V_55 )
{
struct V_119 * V_120 ;
struct V_172 * V_173 ;
struct V_331 * V_346 ;
struct V_347 V_12 = { . V_12 = V_55 -> V_12 ,
. V_348 = ~ 0 } ;
struct V_99 V_238 ;
char * V_174 ;
V_346 = F_197 ( V_329 , V_349 ) ;
if ( ! V_346 )
return - V_333 ;
if ( F_204 ( V_329 , V_350 , V_55 -> V_40 ) )
goto V_345;
if ( V_55 -> V_53 ) {
if ( F_198 ( V_329 , V_351 , V_55 -> V_53 ) )
goto V_345;
} else {
if ( F_204 ( V_329 , V_352 , V_55 -> V_59 ) ||
F_205 ( V_329 , V_353 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_206 ( V_329 , V_354 , V_55 -> V_43 ) )
goto V_345;
}
V_120 = F_63 ( V_55 -> V_135 , 1 ) ;
V_174 = V_120 ? V_120 -> V_198 : L_18 ;
V_173 = F_63 ( V_55 -> V_173 , 1 ) ;
if ( F_207 ( V_329 , V_355 , V_174 ) ||
( V_173 && F_207 ( V_329 , V_356 , V_173 -> V_198 ) ) ||
F_205 ( V_329 , V_357 , sizeof( V_12 ) , & V_12 ) ||
F_198 ( V_329 , V_358 , V_55 -> V_180 / V_181 ) ||
F_208 ( V_329 , V_359 , V_55 -> V_179 ) )
goto V_345;
F_76 ( & V_238 , & V_55 -> V_75 ) ;
if ( F_196 ( V_329 , V_360 , & V_238 ) )
goto V_345;
if ( F_202 ( V_329 , V_361 , & V_238 ) )
goto V_345;
F_200 ( V_329 , V_346 ) ;
return 0 ;
V_345:
F_201 ( V_329 , V_346 ) ;
return - V_333 ;
}
static int F_209 ( struct V_328 * V_329 ,
struct V_54 * V_55 ,
struct V_362 * V_363 )
{
void * V_364 ;
V_364 = F_210 ( V_329 , F_211 ( V_363 -> V_329 ) . V_365 , V_363 -> V_366 -> V_367 ,
& V_368 , V_369 ,
V_370 ) ;
if ( ! V_364 )
return - V_333 ;
if ( F_203 ( V_329 , V_55 ) < 0 )
goto V_345;
F_212 ( V_329 , V_364 ) ;
return 0 ;
V_345:
F_213 ( V_329 , V_364 ) ;
return - V_333 ;
}
static int F_214 ( struct V_328 * V_329 ,
struct V_362 * V_363 )
{
int V_192 = 0 , V_17 ;
int V_239 = V_363 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_180 ( V_329 -> V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
F_134 ( & V_196 ) ;
for ( V_17 = 0 ; V_17 < V_195 ; V_17 ++ ) {
F_141 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_192 <= V_239 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( F_209 ( V_329 , V_55 , V_363 ) < 0 ) {
V_192 -- ;
goto V_345;
}
}
}
for ( V_17 = 0 ; V_17 < V_195 ; V_17 ++ ) {
F_141 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_192 <= V_239 || ( V_55 -> V_15 != V_15 ) )
continue;
if ( F_209 ( V_329 , V_55 , V_363 ) < 0 ) {
V_192 -- ;
goto V_345;
}
}
}
V_345:
F_135 ( & V_196 ) ;
V_363 -> args [ 0 ] = V_192 ;
return V_329 -> V_263 ;
}
static bool F_215 ( int V_40 )
{
if ( V_40 == V_185 )
return true ;
#ifdef F_24
if ( V_40 == V_48 && F_216 () )
return true ;
#endif
return false ;
}
static int F_217 ( struct V_14 * V_15 ,
struct V_169 * V_254 ,
struct V_331 * V_371 , int V_372 ,
struct V_54 * * V_373 )
{
struct V_331 * V_374 [ V_375 + 1 ] ;
struct V_331 * V_376 , * V_377 , * V_378 , * V_379 , * V_380 ;
struct V_54 * V_55 ;
if ( V_371 == NULL ||
F_218 ( V_374 , V_375 , V_371 ,
V_381 , NULL ) )
return - V_143 ;
V_376 = V_374 [ V_350 ] ;
V_379 = V_374 [ V_352 ] ;
V_380 = V_374 [ V_353 ] ;
V_377 = V_374 [ V_354 ] ;
V_378 = V_374 [ V_351 ] ;
if ( ! ( V_376 && ( V_378 || ( V_377 && V_379 && V_380 ) ) ) )
return - V_143 ;
memset ( V_254 , 0 , sizeof( * V_254 ) ) ;
V_254 -> V_40 = F_219 ( V_376 ) ;
if ( ! F_215 ( V_254 -> V_40 ) )
return - V_382 ;
if ( V_378 ) {
V_254 -> V_59 = V_68 ;
V_254 -> V_53 = F_220 ( V_378 ) ;
} else {
V_254 -> V_59 = F_219 ( V_379 ) ;
F_221 ( & V_254 -> V_4 , V_380 , sizeof( V_254 -> V_4 ) ) ;
V_254 -> V_43 = F_222 ( V_377 ) ;
V_254 -> V_53 = 0 ;
}
F_102 () ;
if ( V_254 -> V_53 )
V_55 = F_38 ( V_15 , V_254 -> V_40 , V_254 -> V_53 ) ;
else
V_55 = F_35 ( V_15 , V_254 -> V_40 , V_254 -> V_59 ,
& V_254 -> V_4 , V_254 -> V_43 ) ;
F_103 () ;
* V_373 = V_55 ;
if ( V_372 ) {
struct V_331 * V_383 , * V_384 , * V_385 , * V_386 ,
* V_387 ;
struct V_347 V_12 ;
V_383 = V_374 [ V_355 ] ;
V_385 = V_374 [ V_356 ] ;
V_384 = V_374 [ V_357 ] ;
V_386 = V_374 [ V_358 ] ;
V_387 = V_374 [ V_359 ] ;
if ( ! ( V_383 && V_384 && V_386 && V_387 ) )
return - V_143 ;
F_221 ( & V_12 , V_384 , sizeof( V_12 ) ) ;
if ( V_55 )
V_254 -> V_12 = V_55 -> V_12 ;
V_254 -> V_12 = ( V_254 -> V_12 & ~ V_12 . V_348 ) |
( V_12 . V_12 & V_12 . V_348 ) ;
V_254 -> V_174 = F_223 ( V_383 ) ;
V_254 -> V_176 = V_385 ? F_223 ( V_385 ) : NULL ;
V_254 -> V_180 = F_220 ( V_386 ) ;
V_254 -> V_179 = F_224 ( V_387 ) ;
}
return 0 ;
}
static struct V_54 * F_225 ( struct V_14 * V_15 ,
struct V_331 * V_371 )
{
struct V_169 V_254 ;
struct V_54 * V_55 ;
int V_155 ;
V_155 = F_217 ( V_15 , & V_254 , V_371 , 0 , & V_55 ) ;
return V_155 ? F_226 ( V_155 ) : V_55 ;
}
static int F_227 ( struct V_328 * V_329 , struct V_73 * V_74 )
{
struct V_331 * V_388 ;
struct V_99 V_238 ;
V_388 = F_197 ( V_329 , V_389 ) ;
if ( ! V_388 )
return - V_333 ;
if ( F_205 ( V_329 , V_390 , sizeof( V_74 -> V_4 ) , & V_74 -> V_4 ) ||
F_206 ( V_329 , V_391 , V_74 -> V_43 ) ||
F_198 ( V_329 , V_392 ,
( F_15 ( & V_74 -> V_121 ) &
V_89 ) ) ||
F_198 ( V_329 , V_393 ,
F_15 ( & V_74 -> V_123 ) ) ||
F_198 ( V_329 , V_394 , V_74 -> V_128 ) ||
F_198 ( V_329 , V_395 , V_74 -> V_130 ) ||
F_198 ( V_329 , V_396 ,
F_15 ( & V_74 -> V_152 ) ) ||
F_198 ( V_329 , V_397 ,
F_15 ( & V_74 -> V_153 ) ) ||
F_198 ( V_329 , V_398 ,
F_15 ( & V_74 -> V_154 ) ) ||
F_204 ( V_329 , V_399 , V_74 -> V_40 ) )
goto V_345;
F_76 ( & V_238 , & V_74 -> V_75 ) ;
if ( F_196 ( V_329 , V_400 , & V_238 ) )
goto V_345;
if ( F_202 ( V_329 , V_401 , & V_238 ) )
goto V_345;
F_200 ( V_329 , V_388 ) ;
return 0 ;
V_345:
F_201 ( V_329 , V_388 ) ;
return - V_333 ;
}
static int F_228 ( struct V_328 * V_329 , struct V_73 * V_74 ,
struct V_362 * V_363 )
{
void * V_364 ;
V_364 = F_210 ( V_329 , F_211 ( V_363 -> V_329 ) . V_365 , V_363 -> V_366 -> V_367 ,
& V_368 , V_369 ,
V_402 ) ;
if ( ! V_364 )
return - V_333 ;
if ( F_227 ( V_329 , V_74 ) < 0 )
goto V_345;
F_212 ( V_329 , V_364 ) ;
return 0 ;
V_345:
F_213 ( V_329 , V_364 ) ;
return - V_333 ;
}
static int F_229 ( struct V_328 * V_329 ,
struct V_362 * V_363 )
{
int V_192 = 0 ;
int V_239 = V_363 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_73 * V_74 ;
struct V_331 * V_374 [ V_403 + 1 ] ;
struct V_2 * V_2 = F_180 ( V_329 -> V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
F_134 ( & V_196 ) ;
if ( F_230 ( V_363 -> V_366 , V_404 , V_374 , V_403 ,
V_405 , NULL ) )
goto V_175;
V_55 = F_225 ( V_15 , V_374 [ V_349 ] ) ;
if ( F_231 ( V_55 ) )
goto V_175;
F_67 (dest, &svc->destinations, n_list) {
if ( ++ V_192 <= V_239 )
continue;
if ( F_228 ( V_329 , V_74 , V_363 ) < 0 ) {
V_192 -- ;
goto V_345;
}
}
V_345:
V_363 -> args [ 0 ] = V_192 ;
V_175:
F_135 ( & V_196 ) ;
return V_329 -> V_263 ;
}
static int F_232 ( struct V_115 * V_116 ,
struct V_331 * V_371 , int V_372 )
{
struct V_331 * V_374 [ V_406 + 1 ] ;
struct V_331 * V_380 , * V_377 ;
struct V_331 * V_407 ;
if ( V_371 == NULL ||
F_218 ( V_374 , V_406 , V_371 ,
V_408 , NULL ) )
return - V_143 ;
V_380 = V_374 [ V_390 ] ;
V_377 = V_374 [ V_391 ] ;
V_407 = V_374 [ V_399 ] ;
if ( ! ( V_380 && V_377 ) )
return - V_143 ;
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
F_221 ( & V_116 -> V_4 , V_380 , sizeof( V_116 -> V_4 ) ) ;
V_116 -> V_43 = F_222 ( V_377 ) ;
if ( V_407 )
V_116 -> V_40 = F_219 ( V_407 ) ;
else
V_116 -> V_40 = 0 ;
if ( V_372 ) {
struct V_331 * V_409 , * V_410 , * V_411 ,
* V_412 ;
V_409 = V_374 [ V_392 ] ;
V_410 = V_374 [ V_393 ] ;
V_411 = V_374 [ V_394 ] ;
V_412 = V_374 [ V_395 ] ;
if ( ! ( V_409 && V_410 && V_411 && V_412 ) )
return - V_143 ;
V_116 -> V_121 = F_220 ( V_409 )
& V_89 ;
V_116 -> V_123 = F_220 ( V_410 ) ;
V_116 -> V_128 = F_220 ( V_411 ) ;
V_116 -> V_130 = F_220 ( V_412 ) ;
}
return 0 ;
}
static int F_233 ( struct V_328 * V_329 , T_3 V_282 ,
struct V_277 * T_5 )
{
struct V_331 * V_413 ;
V_413 = F_197 ( V_329 , V_414 ) ;
if ( ! V_413 )
return - V_333 ;
if ( F_198 ( V_329 , V_415 , V_282 ) ||
F_207 ( V_329 , V_416 , T_5 -> V_279 ) ||
F_198 ( V_329 , V_417 , T_5 -> V_280 ) ||
F_204 ( V_329 , V_418 , T_5 -> V_419 ) ||
F_204 ( V_329 , V_420 , T_5 -> V_421 ) ||
F_234 ( V_329 , V_422 , T_5 -> V_423 ) )
goto V_345;
#ifdef F_24
if ( T_5 -> V_424 == V_48 ) {
if ( F_235 ( V_329 , V_425 ,
& T_5 -> V_426 . V_140 ) )
goto V_345;
} else
#endif
if ( T_5 -> V_424 == V_185 &&
F_236 ( V_329 , V_427 ,
T_5 -> V_426 . V_46 ) )
goto V_345;
F_200 ( V_329 , V_413 ) ;
return 0 ;
V_345:
F_201 ( V_329 , V_413 ) ;
return - V_333 ;
}
static int F_237 ( struct V_328 * V_329 , T_3 V_282 ,
struct V_277 * T_5 ,
struct V_362 * V_363 )
{
void * V_364 ;
V_364 = F_210 ( V_329 , F_211 ( V_363 -> V_329 ) . V_365 , V_363 -> V_366 -> V_367 ,
& V_368 , V_369 ,
V_428 ) ;
if ( ! V_364 )
return - V_333 ;
if ( F_233 ( V_329 , V_282 , T_5 ) )
goto V_345;
F_212 ( V_329 , V_364 ) ;
return 0 ;
V_345:
F_213 ( V_329 , V_364 ) ;
return - V_333 ;
}
static int F_238 ( struct V_328 * V_329 ,
struct V_362 * V_363 )
{
struct V_2 * V_2 = F_180 ( V_329 -> V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
F_134 ( & V_15 -> V_281 ) ;
if ( ( V_15 -> V_311 & V_312 ) && ! V_363 -> args [ 0 ] ) {
if ( F_237 ( V_329 , V_312 ,
& V_15 -> V_313 , V_363 ) < 0 )
goto V_345;
V_363 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_311 & V_314 ) && ! V_363 -> args [ 1 ] ) {
if ( F_237 ( V_329 , V_314 ,
& V_15 -> V_315 , V_363 ) < 0 )
goto V_345;
V_363 -> args [ 1 ] = 1 ;
}
V_345:
F_135 ( & V_15 -> V_281 ) ;
return V_329 -> V_263 ;
}
static int F_239 ( struct V_14 * V_15 , struct V_331 * * V_374 )
{
struct V_277 T_5 ;
struct V_331 * V_429 ;
int V_155 ;
memset ( & T_5 , 0 , sizeof( T_5 ) ) ;
if ( ! ( V_374 [ V_415 ] &&
V_374 [ V_416 ] &&
V_374 [ V_417 ] ) )
return - V_143 ;
F_185 ( T_5 . V_279 , F_223 ( V_374 [ V_416 ] ) ,
sizeof( T_5 . V_279 ) ) ;
T_5 . V_280 = F_220 ( V_374 [ V_417 ] ) ;
V_429 = V_374 [ V_418 ] ;
if ( V_429 )
T_5 . V_419 = F_219 ( V_429 ) ;
V_429 = V_374 [ V_427 ] ;
if ( V_429 ) {
T_5 . V_424 = V_185 ;
T_5 . V_426 . V_46 = F_240 ( V_429 ) ;
if ( ! F_241 ( T_5 . V_426 . V_46 ) )
return - V_143 ;
} else {
V_429 = V_374 [ V_425 ] ;
if ( V_429 ) {
#ifdef F_24
int V_430 ;
T_5 . V_424 = V_48 ;
T_5 . V_426 . V_140 = F_242 ( V_429 ) ;
V_430 = F_89 ( & T_5 . V_426 . V_140 ) ;
if ( ! ( V_430 & V_431 ) )
return - V_143 ;
#else
return - V_382 ;
#endif
}
}
V_429 = V_374 [ V_420 ] ;
if ( V_429 )
T_5 . V_421 = F_219 ( V_429 ) ;
V_429 = V_374 [ V_422 ] ;
if ( V_429 )
T_5 . V_423 = F_243 ( V_429 ) ;
if ( V_15 -> V_122 > 0 )
return - V_143 ;
F_186 () ;
F_134 ( & V_15 -> V_281 ) ;
V_155 = F_187 ( V_15 , & T_5 ,
F_220 ( V_374 [ V_415 ] ) ) ;
F_135 ( & V_15 -> V_281 ) ;
F_188 () ;
return V_155 ;
}
static int F_244 ( struct V_14 * V_15 , struct V_331 * * V_374 )
{
int V_155 ;
if ( ! V_374 [ V_415 ] )
return - V_143 ;
F_134 ( & V_15 -> V_281 ) ;
V_155 = F_189 ( V_15 ,
F_220 ( V_374 [ V_415 ] ) ) ;
F_135 ( & V_15 -> V_281 ) ;
return V_155 ;
}
static int F_245 ( struct V_14 * V_15 , struct V_331 * * V_374 )
{
struct V_241 V_327 ;
F_194 ( V_15 , & V_327 ) ;
if ( V_374 [ V_432 ] )
V_327 . V_246 = F_220 ( V_374 [ V_432 ] ) ;
if ( V_374 [ V_433 ] )
V_327 . V_247 =
F_220 ( V_374 [ V_433 ] ) ;
if ( V_374 [ V_434 ] )
V_327 . V_248 = F_220 ( V_374 [ V_434 ] ) ;
return F_174 ( V_15 , & V_327 ) ;
}
static int F_246 ( struct V_328 * V_329 , struct V_435 * V_320 )
{
int V_155 = - V_143 , V_261 ;
struct V_2 * V_2 = F_180 ( V_329 -> V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
V_261 = V_320 -> V_436 -> V_261 ;
if ( V_261 == V_428 || V_261 == V_437 ) {
struct V_331 * V_438 [ V_439 + 1 ] ;
if ( ! V_320 -> V_374 [ V_414 ] ||
F_218 ( V_438 , V_439 ,
V_320 -> V_374 [ V_414 ] ,
V_440 , V_320 -> V_441 ) )
goto V_67;
if ( V_261 == V_428 )
V_155 = F_239 ( V_15 , V_438 ) ;
else
V_155 = F_244 ( V_15 , V_438 ) ;
}
V_67:
return V_155 ;
}
static int F_247 ( struct V_328 * V_329 , struct V_435 * V_320 )
{
struct V_54 * V_55 = NULL ;
struct V_169 V_254 ;
struct V_115 V_116 ;
int V_155 = 0 , V_261 ;
int V_442 = 0 , V_443 = 0 ;
struct V_2 * V_2 = F_180 ( V_329 -> V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
V_261 = V_320 -> V_436 -> V_261 ;
F_134 ( & V_196 ) ;
if ( V_261 == V_444 ) {
V_155 = F_131 ( V_15 , false ) ;
goto V_67;
} else if ( V_261 == V_445 ) {
V_155 = F_245 ( V_15 , V_320 -> V_374 ) ;
goto V_67;
} else if ( V_261 == V_446 &&
! V_320 -> V_374 [ V_349 ] ) {
V_155 = F_143 ( V_15 ) ;
goto V_67;
}
if ( V_261 == V_370 || V_261 == V_447 )
V_442 = 1 ;
V_155 = F_217 ( V_15 , & V_254 ,
V_320 -> V_374 [ V_349 ] ,
V_442 , & V_55 ) ;
if ( V_155 )
goto V_67;
if ( ( V_261 != V_370 ) && ( V_55 == NULL ) ) {
V_155 = - V_290 ;
goto V_67;
}
if ( V_261 == V_402 || V_261 == V_448 ||
V_261 == V_449 ) {
if ( V_261 != V_449 )
V_443 = 1 ;
V_155 = F_232 ( & V_116 ,
V_320 -> V_374 [ V_389 ] ,
V_443 ) ;
if ( V_155 )
goto V_67;
if ( V_116 . V_40 == 0 )
V_116 . V_40 = V_55 -> V_40 ;
if ( ! F_215 ( V_116 . V_40 ) ) {
V_155 = - V_382 ;
goto V_67;
}
if ( V_116 . V_40 != V_55 -> V_40 && V_261 != V_449 ) {
if ( V_15 -> V_311 ) {
V_155 = - V_143 ;
goto V_67;
}
switch ( V_116 . V_121 ) {
case V_217 :
break;
default:
V_155 = - V_143 ;
goto V_67;
}
}
}
switch ( V_261 ) {
case V_370 :
if ( V_55 == NULL )
V_155 = F_117 ( V_15 , & V_254 , & V_55 ) ;
else
V_155 = - V_157 ;
break;
case V_447 :
V_155 = F_126 ( V_55 , & V_254 ) ;
break;
case V_450 :
V_155 = F_130 ( V_55 ) ;
break;
case V_402 :
V_155 = F_101 ( V_55 , & V_116 ) ;
break;
case V_448 :
V_155 = F_105 ( V_55 , & V_116 ) ;
break;
case V_449 :
V_155 = F_113 ( V_55 , & V_116 ) ;
break;
case V_446 :
V_155 = F_142 ( V_55 ) ;
break;
default:
V_155 = - V_143 ;
}
V_67:
F_135 ( & V_196 ) ;
return V_155 ;
}
static int F_248 ( struct V_328 * V_329 , struct V_435 * V_320 )
{
struct V_328 * V_451 ;
void * V_452 ;
int V_155 , V_261 , V_453 ;
struct V_2 * V_2 = F_180 ( V_329 -> V_260 ) ;
struct V_14 * V_15 = F_140 ( V_2 ) ;
V_261 = V_320 -> V_436 -> V_261 ;
if ( V_261 == V_454 )
V_453 = V_370 ;
else if ( V_261 == V_455 )
V_453 = V_456 ;
else if ( V_261 == V_457 )
V_453 = V_445 ;
else {
F_28 ( L_59 ) ;
return - V_143 ;
}
V_451 = F_249 ( V_458 , V_146 ) ;
if ( ! V_451 )
return - V_147 ;
F_134 ( & V_196 ) ;
V_452 = F_250 ( V_451 , V_320 , & V_368 , 0 , V_453 ) ;
if ( V_452 == NULL )
goto V_345;
switch ( V_261 ) {
case V_454 :
{
struct V_54 * V_55 ;
V_55 = F_225 ( V_15 ,
V_320 -> V_374 [ V_349 ] ) ;
if ( F_251 ( V_55 ) ) {
V_155 = F_252 ( V_55 ) ;
goto V_175;
} else if ( V_55 ) {
V_155 = F_203 ( V_451 , V_55 ) ;
if ( V_155 )
goto V_345;
} else {
V_155 = - V_290 ;
goto V_175;
}
break;
}
case V_457 :
{
struct V_241 V_327 ;
F_194 ( V_15 , & V_327 ) ;
#ifdef V_242
if ( F_198 ( V_451 , V_432 ,
V_327 . V_246 ) ||
F_198 ( V_451 , V_433 ,
V_327 . V_247 ) )
goto V_345;
#endif
#ifdef V_243
if ( F_198 ( V_451 , V_434 , V_327 . V_248 ) )
goto V_345;
#endif
break;
}
case V_455 :
if ( F_198 ( V_451 , V_459 ,
V_230 ) ||
F_198 ( V_451 , V_460 ,
V_231 ) )
goto V_345;
break;
}
F_212 ( V_451 , V_452 ) ;
V_155 = F_253 ( V_451 , V_320 ) ;
goto V_67;
V_345:
F_28 ( L_60 ) ;
V_155 = - V_333 ;
V_175:
F_254 ( V_451 ) ;
V_67:
F_135 ( & V_196 ) ;
return V_155 ;
}
static int T_11 F_255 ( void )
{
return F_256 ( & V_368 ) ;
}
static void F_257 ( void )
{
F_258 ( & V_368 ) ;
}
static int T_12 F_259 ( struct V_14 * V_15 )
{
struct V_2 * V_2 = V_15 -> V_2 ;
int V_192 ;
struct V_206 * V_461 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_99 ( & V_15 -> V_25 ) ;
F_99 ( & V_15 -> V_28 ) ;
F_99 ( & V_15 -> V_33 ) ;
if ( ! F_260 ( V_2 , & V_462 ) ) {
V_461 = F_261 ( V_463 , sizeof( V_463 ) , V_146 ) ;
if ( V_461 == NULL )
return - V_147 ;
if ( V_2 -> V_266 != & V_464 )
V_461 [ 0 ] . V_465 = NULL ;
} else
V_461 = V_463 ;
for ( V_192 = 0 ; V_192 < F_262 ( V_463 ) ; V_192 ++ ) {
if ( V_461 [ V_192 ] . V_466 == F_144 )
V_461 [ V_192 ] . V_212 = V_15 ;
}
V_192 = 0 ;
V_15 -> V_24 = 1024 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_32 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_26 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_29 ;
#ifdef F_263
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_467 ;
#endif
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_34 ;
V_15 -> V_468 = 1 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_468 ;
V_15 -> V_469 = 1 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_469 ;
V_15 -> V_470 = 1 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_470 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_471 ;
V_15 -> V_472 = F_264 () / 32 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_472 ;
V_15 -> V_473 = 0 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_473 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_474 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_475 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_476 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_477 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_478 ;
V_15 -> V_479 [ 0 ] = V_480 ;
V_15 -> V_479 [ 1 ] = V_481 ;
V_461 [ V_192 ] . V_166 = & V_15 -> V_479 ;
V_461 [ V_192 ++ ] . V_482 = sizeof( V_15 -> V_479 ) ;
V_15 -> V_483 = V_484 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_483 ;
V_15 -> V_485 = F_265 ( int , V_486 , 0 , 3 ) ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_485 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_487 ;
V_15 -> V_488 = 1 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_488 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_489 ;
V_15 -> V_490 = 1 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_490 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_491 ;
V_461 [ V_192 ++ ] . V_166 = & V_15 -> V_492 ;
V_15 -> V_493 = F_266 ( V_2 , L_61 , V_461 ) ;
if ( V_15 -> V_493 == NULL ) {
if ( ! F_260 ( V_2 , & V_462 ) )
F_48 ( V_461 ) ;
return - V_147 ;
}
F_85 ( V_15 , & V_15 -> V_205 ) ;
V_15 -> V_494 = V_461 ;
F_267 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_268 ( struct V_14 * V_15 )
{
struct V_2 * V_2 = V_15 -> V_2 ;
F_269 ( & V_15 -> V_37 ) ;
F_270 ( & V_15 -> V_37 . V_36 ) ;
F_271 ( V_15 -> V_493 ) ;
F_107 ( V_15 , & V_15 -> V_205 ) ;
if ( ! F_260 ( V_2 , & V_462 ) )
F_48 ( V_15 -> V_494 ) ;
}
static int T_12 F_259 ( struct V_14 * V_15 ) { return 0 ; }
static void T_13 F_268 ( struct V_14 * V_15 ) { }
int T_12 F_272 ( struct V_14 * V_15 )
{
int V_17 , V_192 ;
for ( V_192 = 0 ; V_192 < V_495 ; V_192 ++ )
F_273 ( & V_15 -> V_84 [ V_192 ] ) ;
F_121 ( & V_15 -> V_160 ) ;
F_99 ( & V_15 -> V_95 ) ;
F_274 ( & V_15 -> V_98 , F_114 ,
( unsigned long ) V_15 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_72 , 0 ) ;
F_9 ( & V_15 -> V_184 , 0 ) ;
V_15 -> V_205 . V_76 = F_92 ( struct V_148 ) ;
if ( ! V_15 -> V_205 . V_76 )
return - V_147 ;
F_93 (i) {
struct V_148 * V_496 ;
V_496 = F_94 ( V_15 -> V_205 . V_76 , V_17 ) ;
F_95 ( & V_496 -> V_151 ) ;
}
F_99 ( & V_15 -> V_205 . V_102 ) ;
F_275 ( L_62 , 0 , V_15 -> V_2 -> V_497 , & V_498 ) ;
F_275 ( L_63 , 0 , V_15 -> V_2 -> V_497 , & V_499 ) ;
F_275 ( L_64 , 0 , V_15 -> V_2 -> V_497 ,
& V_500 ) ;
if ( F_259 ( V_15 ) )
goto V_501;
return 0 ;
V_501:
F_47 ( V_15 -> V_205 . V_76 ) ;
return - V_147 ;
}
void T_13 F_276 ( struct V_14 * V_15 )
{
F_73 ( V_15 ) ;
F_268 ( V_15 ) ;
F_277 ( L_64 , V_15 -> V_2 -> V_497 ) ;
F_277 ( L_63 , V_15 -> V_2 -> V_497 ) ;
F_277 ( L_62 , V_15 -> V_2 -> V_497 ) ;
F_47 ( V_15 -> V_205 . V_76 ) ;
}
int T_11 F_278 ( void )
{
int V_155 ;
V_155 = F_279 ( & V_502 ) ;
if ( V_155 ) {
F_28 ( L_65 ) ;
goto V_503;
}
V_155 = F_255 () ;
if ( V_155 ) {
F_28 ( L_66 ) ;
goto V_504;
}
return 0 ;
V_504:
F_280 ( & V_502 ) ;
V_503:
return V_155 ;
}
void F_281 ( void )
{
F_257 () ;
F_280 ( & V_502 ) ;
}
int T_11 F_282 ( void )
{
int V_192 ;
int V_155 ;
F_88 ( 2 ) ;
for ( V_192 = 0 ; V_192 < V_195 ; V_192 ++ ) {
F_273 ( & V_61 [ V_192 ] ) ;
F_273 ( & V_63 [ V_192 ] ) ;
}
F_283 () ;
V_155 = F_284 ( & V_505 ) ;
if ( V_155 < 0 )
return V_155 ;
F_100 ( 2 ) ;
return 0 ;
}
void F_285 ( void )
{
F_88 ( 2 ) ;
F_286 ( & V_505 ) ;
F_100 ( 2 ) ;
}
