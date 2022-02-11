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
F_60 ( struct V_54 * V_55 , const union V_42 * V_7 ,
T_1 V_86 )
{
struct V_74 * V_75 ;
F_61 (dest, &svc->destinations, n_list) {
if ( ( V_75 -> V_40 == V_55 -> V_40 )
&& F_37 ( V_55 -> V_40 , & V_75 -> V_4 , V_7 )
&& ( V_75 -> V_43 == V_86 ) ) {
return V_75 ;
}
}
return NULL ;
}
struct V_74 * F_62 ( struct V_2 * V_2 , int V_40 ,
const union V_42 * V_7 ,
T_1 V_86 ,
const union V_42 * V_65 ,
T_1 V_66 , T_4 V_59 , T_3 V_53 ,
T_3 V_12 )
{
struct V_74 * V_75 ;
struct V_54 * V_55 ;
T_1 V_43 = V_86 ;
V_55 = F_40 ( V_2 , V_40 , V_53 , V_59 , V_65 , V_66 ) ;
if ( ! V_55 )
return NULL ;
if ( V_53 && ( V_12 & V_88 ) != V_89 )
V_43 = 0 ;
V_75 = F_60 ( V_55 , V_7 , V_43 ) ;
if ( ! V_75 )
V_75 = F_60 ( V_55 , V_7 , V_43 ^ V_86 ) ;
return V_75 ;
}
void F_63 ( struct V_78 * V_79 )
{
struct V_90 * V_91 = F_14 ( V_79 ,
struct V_90 ,
V_78 ) ;
F_4 ( V_91 -> V_92 ) ;
F_49 ( V_91 ) ;
}
static void F_64 ( struct V_74 * V_75 )
{
struct V_90 * V_93 ;
V_93 = F_65 ( V_75 -> V_91 , 1 ) ;
if ( V_93 ) {
F_66 ( V_75 -> V_91 , NULL ) ;
F_53 ( & V_93 -> V_78 , F_63 ) ;
}
}
static struct V_74 *
F_67 ( struct V_54 * V_55 , const union V_42 * V_7 ,
T_1 V_86 )
{
struct V_74 * V_75 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_68 ( & V_15 -> V_94 ) ;
F_69 (dest, &ipvs->dest_trash, t_list) {
F_42 ( 3 , L_7
L_8 ,
V_75 -> V_87 ,
F_44 ( V_55 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( V_75 -> V_40 == V_55 -> V_40 &&
F_37 ( V_55 -> V_40 , & V_75 -> V_4 , V_7 ) &&
V_75 -> V_43 == V_86 &&
V_75 -> V_87 == V_55 -> V_53 &&
V_75 -> V_59 == V_55 -> V_59 &&
( V_55 -> V_53 ||
( F_37 ( V_55 -> V_40 , & V_75 -> V_65 , & V_55 -> V_4 ) &&
V_75 -> V_66 == V_55 -> V_43 ) ) ) {
F_70 ( & V_75 -> V_95 ) ;
F_71 ( V_75 ) ;
goto V_67;
}
}
V_75 = NULL ;
V_67:
F_72 ( & V_15 -> V_94 ) ;
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
struct V_74 * V_75 , * V_96 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_76 ( & V_15 -> V_97 ) ;
F_77 (dest, nxt, &ipvs->dest_trash, t_list) {
F_70 ( & V_75 -> V_95 ) ;
F_73 ( V_75 ) ;
}
}
static void
F_78 ( struct V_98 * V_9 , struct V_99 * V_100 )
{
#define F_79 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_68 ( & V_100 -> V_101 ) ;
F_79 ( V_102 ) ;
F_79 ( V_103 ) ;
F_79 ( V_104 ) ;
F_79 ( V_105 ) ;
F_79 ( V_106 ) ;
F_80 ( V_9 , V_100 ) ;
F_72 ( & V_100 -> V_101 ) ;
}
static void
F_81 ( struct V_99 * V_76 )
{
F_68 ( & V_76 -> V_101 ) ;
#define F_82 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_82 ( V_102 ) ;
F_82 ( V_103 ) ;
F_82 ( V_104 ) ;
F_82 ( V_105 ) ;
F_82 ( V_106 ) ;
F_83 ( V_76 ) ;
F_72 ( & V_76 -> V_101 ) ;
}
static void
F_84 ( struct V_54 * V_55 , struct V_74 * V_75 ,
struct V_107 * V_108 , int V_109 )
{
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
struct V_54 * V_110 ;
struct V_111 * V_112 ;
int V_113 ;
F_9 ( & V_75 -> V_114 , V_108 -> V_114 ) ;
V_113 = V_108 -> V_113 & V_115 ;
V_113 |= V_116 ;
if ( ( V_113 & V_88 ) != V_89 ) {
V_113 |= V_117 ;
} else {
F_55 ( V_15 , V_75 ) ;
}
F_9 ( & V_75 -> V_113 , V_113 ) ;
V_110 = F_65 ( V_75 -> V_55 , 1 ) ;
if ( ! V_110 ) {
F_45 ( V_75 , V_55 ) ;
} else {
if ( V_110 != V_55 ) {
F_81 ( & V_75 -> V_76 ) ;
F_45 ( V_75 , V_55 ) ;
F_51 ( V_110 , true ) ;
}
}
V_75 -> V_12 |= V_118 ;
if ( V_108 -> V_119 == 0 || V_108 -> V_119 > V_75 -> V_119 )
V_75 -> V_12 &= ~ V_120 ;
V_75 -> V_119 = V_108 -> V_119 ;
V_75 -> V_121 = V_108 -> V_121 ;
F_68 ( & V_75 -> V_122 ) ;
F_64 ( V_75 ) ;
F_72 ( & V_75 -> V_122 ) ;
V_112 = F_65 ( V_55 -> V_123 , 1 ) ;
if ( V_109 ) {
F_85 ( V_55 -> V_2 , & V_75 -> V_76 ) ;
F_86 ( & V_75 -> V_124 , & V_55 -> V_125 ) ;
V_55 -> V_126 ++ ;
if ( V_112 -> V_127 )
V_112 -> V_127 ( V_55 , V_75 ) ;
} else {
if ( V_112 -> V_128 )
V_112 -> V_128 ( V_55 , V_75 ) ;
}
}
static int
F_87 ( struct V_54 * V_55 , struct V_107 * V_108 ,
struct V_74 * * V_129 )
{
struct V_74 * V_75 ;
unsigned int V_130 , V_17 ;
F_88 ( 2 ) ;
#ifdef F_24
if ( V_55 -> V_40 == V_48 ) {
V_130 = F_89 ( & V_108 -> V_4 . V_131 ) ;
if ( ( ! ( V_130 & V_132 ) ||
V_130 & V_133 ) &&
! F_2 ( V_55 -> V_2 , & V_108 -> V_4 . V_131 ) )
return - V_134 ;
} else
#endif
{
V_130 = F_90 ( V_55 -> V_2 , V_108 -> V_4 . V_46 ) ;
if ( V_130 != V_135 && V_130 != V_136 )
return - V_134 ;
}
V_75 = F_91 ( sizeof( struct V_74 ) , V_137 ) ;
if ( V_75 == NULL )
return - V_138 ;
V_75 -> V_76 . V_77 = F_92 ( struct V_139 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_140;
F_93 (i) {
struct V_139 * V_141 ;
V_141 = F_94 ( V_75 -> V_76 . V_77 , V_17 ) ;
F_95 ( & V_141 -> V_142 ) ;
}
V_75 -> V_40 = V_55 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_87 = V_55 -> V_53 ;
F_96 ( V_55 -> V_40 , & V_75 -> V_4 , & V_108 -> V_4 ) ;
V_75 -> V_43 = V_108 -> V_43 ;
F_9 ( & V_75 -> V_143 , 0 ) ;
F_9 ( & V_75 -> V_144 , 0 ) ;
F_9 ( & V_75 -> V_145 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_97 ( & V_75 -> V_84 ) ;
F_98 ( & V_75 -> V_122 ) ;
F_98 ( & V_75 -> V_76 . V_101 ) ;
F_84 ( V_55 , V_75 , V_108 , 1 ) ;
* V_129 = V_75 ;
F_99 ( 2 ) ;
return 0 ;
V_140:
F_49 ( V_75 ) ;
return - V_138 ;
}
static int
F_100 ( struct V_54 * V_55 , struct V_107 * V_108 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_108 -> V_43 ;
int V_146 ;
F_88 ( 2 ) ;
if ( V_108 -> V_114 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_147 ;
}
if ( V_108 -> V_121 > V_108 -> V_119 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_147 ;
}
F_96 ( V_55 -> V_40 , & V_7 , & V_108 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 != NULL ) {
F_101 ( 1 , L_11 , V_58 ) ;
return - V_148 ;
}
V_75 = F_67 ( V_55 , & V_7 , V_86 ) ;
if ( V_75 != NULL ) {
F_42 ( 3 , L_12
L_13 ,
F_44 ( V_55 -> V_40 , & V_7 ) , F_23 ( V_86 ) ,
F_15 ( & V_75 -> V_64 ) ,
V_75 -> V_87 ,
F_44 ( V_55 -> V_40 , & V_75 -> V_65 ) ,
F_23 ( V_75 -> V_66 ) ) ;
F_84 ( V_55 , V_75 , V_108 , 1 ) ;
V_146 = 0 ;
} else {
V_146 = F_87 ( V_55 , V_108 , & V_75 ) ;
}
F_99 ( 2 ) ;
return V_146 ;
}
static int
F_102 ( struct V_54 * V_55 , struct V_107 * V_108 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_108 -> V_43 ;
F_88 ( 2 ) ;
if ( V_108 -> V_114 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_147 ;
}
if ( V_108 -> V_121 > V_108 -> V_119 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_147 ;
}
F_96 ( V_55 -> V_40 , & V_7 , & V_108 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_101 ( 1 , L_14 , V_58 ) ;
return - V_149 ;
}
F_84 ( V_55 , V_75 , V_108 , 0 ) ;
F_99 ( 2 ) ;
return 0 ;
}
static void F_103 ( struct V_2 * V_2 , struct V_74 * V_75 ,
bool V_150 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_104 ( V_2 , & V_75 -> V_76 ) ;
F_56 ( V_75 ) ;
F_68 ( & V_15 -> V_94 ) ;
F_42 ( 3 , L_15 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_105 ( & V_15 -> V_151 ) && ! V_150 )
F_106 ( & V_15 -> V_97 ,
V_152 + ( V_153 >> 1 ) ) ;
F_107 ( & V_75 -> V_95 , & V_15 -> V_151 ) ;
V_75 -> V_154 = 0 ;
F_72 ( & V_15 -> V_94 ) ;
F_108 ( V_75 ) ;
}
static void F_109 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_155 )
{
V_75 -> V_12 &= ~ V_118 ;
F_110 ( & V_75 -> V_124 ) ;
V_55 -> V_126 -- ;
if ( V_155 ) {
struct V_111 * V_112 ;
V_112 = F_65 ( V_55 -> V_123 , 1 ) ;
if ( V_112 -> V_156 )
V_112 -> V_156 ( V_55 , V_75 ) ;
}
}
static int
F_111 ( struct V_54 * V_55 , struct V_107 * V_108 )
{
struct V_74 * V_75 ;
T_1 V_86 = V_108 -> V_43 ;
F_88 ( 2 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , & V_108 -> V_4 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_101 ( 1 , L_16 , V_58 ) ;
return - V_149 ;
}
F_109 ( V_55 , V_75 , 1 ) ;
F_103 ( V_55 -> V_2 , V_75 , false ) ;
F_99 ( 2 ) ;
return 0 ;
}
static void F_112 ( unsigned long V_157 )
{
struct V_2 * V_2 = (struct V_2 * ) V_157 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_74 * V_75 , * V_158 ;
unsigned long V_159 = V_152 ;
F_8 ( & V_15 -> V_94 ) ;
F_77 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
if ( V_75 -> V_154 ) {
if ( F_113 ( V_159 , V_75 -> V_154 +
V_153 ) )
continue;
} else {
V_75 -> V_154 = F_114 ( 1UL , V_159 ) ;
continue;
}
F_42 ( 3 , L_17 ,
V_75 -> V_87 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_70 ( & V_75 -> V_95 ) ;
F_73 ( V_75 ) ;
}
if ( ! F_105 ( & V_15 -> V_151 ) )
F_106 ( & V_15 -> V_97 ,
V_152 + ( V_153 >> 1 ) ) ;
F_10 ( & V_15 -> V_94 ) ;
}
static int
F_115 ( struct V_2 * V_2 , struct V_160 * V_161 ,
struct V_54 * * V_162 )
{
int V_146 = 0 , V_17 ;
struct V_111 * V_112 = NULL ;
struct V_163 * V_164 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_18 () ;
V_112 = F_116 ( V_161 -> V_165 ) ;
if ( V_112 == NULL ) {
F_117 ( L_18 , V_161 -> V_165 ) ;
V_146 = - V_149 ;
goto V_166;
}
if ( V_161 -> V_167 && * V_161 -> V_167 ) {
V_164 = F_118 ( V_161 -> V_167 ) ;
if ( V_164 == NULL ) {
F_117 ( L_19
L_20 , V_161 -> V_167 ) ;
V_146 = - V_149 ;
goto V_166;
}
}
#ifdef F_24
if ( V_161 -> V_40 == V_48 ) {
T_3 V_168 = ( V_169 T_3 ) V_161 -> V_170 ;
if ( V_168 < 1 || V_168 > 128 ) {
V_146 = - V_134 ;
goto V_166;
}
}
#endif
V_55 = F_91 ( sizeof( struct V_54 ) , V_137 ) ;
if ( V_55 == NULL ) {
F_101 ( 1 , L_21 , V_58 ) ;
V_146 = - V_138 ;
goto V_166;
}
V_55 -> V_76 . V_77 = F_92 ( struct V_139 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_146 = - V_138 ;
goto V_166;
}
F_93 (i) {
struct V_139 * V_99 ;
V_99 = F_94 ( V_55 -> V_76 . V_77 , V_17 ) ;
F_95 ( & V_99 -> V_142 ) ;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_161 -> V_40 ;
V_55 -> V_59 = V_161 -> V_59 ;
F_96 ( V_55 -> V_40 , & V_55 -> V_4 , & V_161 -> V_4 ) ;
V_55 -> V_43 = V_161 -> V_43 ;
V_55 -> V_53 = V_161 -> V_53 ;
V_55 -> V_12 = V_161 -> V_12 ;
V_55 -> V_171 = V_161 -> V_171 * V_172 ;
V_55 -> V_170 = V_161 -> V_170 ;
V_55 -> V_2 = V_2 ;
F_119 ( & V_55 -> V_125 ) ;
F_98 ( & V_55 -> V_173 ) ;
F_98 ( & V_55 -> V_76 . V_101 ) ;
V_146 = F_120 ( V_55 , V_112 ) ;
if ( V_146 )
goto V_166;
V_112 = NULL ;
F_66 ( V_55 -> V_164 , V_164 ) ;
V_164 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_85 ( V_2 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_174 )
V_15 -> V_175 ++ ;
F_27 ( V_55 ) ;
* V_162 = V_55 ;
V_15 -> V_176 = 1 ;
return 0 ;
V_166:
if ( V_55 != NULL ) {
F_121 ( V_55 , V_112 ) ;
F_47 ( V_55 ) ;
}
F_122 ( V_112 ) ;
F_123 ( V_164 ) ;
F_20 () ;
return V_146 ;
}
static int
F_124 ( struct V_54 * V_55 , struct V_160 * V_161 )
{
struct V_111 * V_112 , * V_177 ;
struct V_163 * V_164 = NULL , * V_178 = NULL ;
int V_146 = 0 ;
V_112 = F_116 ( V_161 -> V_165 ) ;
if ( V_112 == NULL ) {
F_117 ( L_18 , V_161 -> V_165 ) ;
return - V_149 ;
}
V_177 = V_112 ;
if ( V_161 -> V_167 && * V_161 -> V_167 ) {
V_164 = F_118 ( V_161 -> V_167 ) ;
if ( V_164 == NULL ) {
F_117 ( L_19
L_20 , V_161 -> V_167 ) ;
V_146 = - V_149 ;
goto V_67;
}
V_178 = V_164 ;
}
#ifdef F_24
if ( V_161 -> V_40 == V_48 ) {
T_3 V_168 = ( V_169 T_3 ) V_161 -> V_170 ;
if ( V_168 < 1 || V_168 > 128 ) {
V_146 = - V_134 ;
goto V_67;
}
}
#endif
V_177 = F_65 ( V_55 -> V_123 , 1 ) ;
if ( V_112 != V_177 ) {
V_146 = F_120 ( V_55 , V_112 ) ;
if ( V_146 ) {
V_177 = V_112 ;
goto V_67;
}
F_121 ( V_55 , V_177 ) ;
}
V_55 -> V_12 = V_161 -> V_12 | V_57 ;
V_55 -> V_171 = V_161 -> V_171 * V_172 ;
V_55 -> V_170 = V_161 -> V_170 ;
V_178 = F_65 ( V_55 -> V_164 , 1 ) ;
if ( V_164 != V_178 )
F_46 ( V_55 -> V_164 , V_164 ) ;
V_67:
F_122 ( V_177 ) ;
F_123 ( V_178 ) ;
return V_146 ;
}
static void F_125 ( struct V_54 * V_55 , bool V_150 )
{
struct V_74 * V_75 , * V_96 ;
struct V_111 * V_177 ;
struct V_163 * V_178 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_117 ( L_22 , V_58 ) ;
if ( V_55 -> V_40 == V_174 )
V_15 -> V_175 -- ;
F_104 ( V_55 -> V_2 , & V_55 -> V_76 ) ;
V_177 = F_65 ( V_55 -> V_123 , 1 ) ;
F_121 ( V_55 , V_177 ) ;
F_122 ( V_177 ) ;
V_178 = F_65 ( V_55 -> V_164 , 1 ) ;
F_123 ( V_178 ) ;
F_77 (dest, nxt, &svc->destinations, n_list) {
F_109 ( V_55 , V_75 , 0 ) ;
F_103 ( V_55 -> V_2 , V_75 , V_150 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
F_51 ( V_55 , true ) ;
F_20 () ;
}
static void F_126 ( struct V_54 * V_55 , bool V_150 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_125 ( V_55 , V_150 ) ;
}
static int F_127 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_148 ;
F_126 ( V_55 , false ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_2 , bool V_150 )
{
int V_179 ;
struct V_54 * V_55 ;
struct V_180 * V_181 ;
for( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_129 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_126 ( V_55 , V_150 ) ;
}
}
for( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_129 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_126 ( V_55 , V_150 ) ;
}
}
return 0 ;
}
void F_130 ( struct V_2 * V_2 )
{
F_88 ( 2 ) ;
F_131 ( & V_183 ) ;
F_128 ( V_2 , true ) ;
F_132 ( & V_183 ) ;
F_99 ( 2 ) ;
}
static inline void
F_133 ( struct V_74 * V_75 , struct V_184 * V_11 )
{
struct V_90 * V_91 ;
F_68 ( & V_75 -> V_122 ) ;
V_91 = F_65 ( V_75 -> V_91 , 1 ) ;
if ( V_91 && V_91 -> V_92 -> V_11 == V_11 ) {
F_42 ( 3 , L_23 ,
V_11 -> V_185 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_64 ( V_75 ) ;
}
F_72 ( & V_75 -> V_122 ) ;
}
static int F_134 ( struct V_186 * V_187 , unsigned long V_188 ,
void * V_189 )
{
struct V_184 * V_11 = F_135 ( V_189 ) ;
struct V_2 * V_2 = F_136 ( V_11 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_179 ;
if ( V_188 != V_190 || ! V_15 )
return V_191 ;
F_101 ( 3 , L_24 , V_58 , V_11 -> V_185 ) ;
F_88 ( 2 ) ;
F_131 ( & V_183 ) ;
for ( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_137 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_133 ( V_75 , V_11 ) ;
}
}
}
F_137 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_133 ( V_75 , V_11 ) ;
}
}
}
}
F_68 ( & V_15 -> V_94 ) ;
F_69 (dest, &ipvs->dest_trash, t_list) {
F_133 ( V_75 , V_11 ) ;
}
F_72 ( & V_15 -> V_94 ) ;
F_132 ( & V_183 ) ;
F_99 ( 2 ) ;
return V_191 ;
}
static int F_138 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_69 (dest, &svc->destinations, n_list) {
F_81 ( & V_75 -> V_76 ) ;
}
F_81 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_139 ( struct V_2 * V_2 )
{
int V_179 ;
struct V_54 * V_55 ;
for( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_137 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_138 ( V_55 ) ;
}
}
for( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_137 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_138 ( V_55 ) ;
}
}
F_81 ( & F_41 ( V_2 ) -> V_192 ) ;
return 0 ;
}
static int
F_140 ( struct V_193 * V_194 , int V_195 ,
void T_6 * V_196 , V_50 * V_197 , T_7 * V_198 )
{
struct V_2 * V_2 = V_199 -> V_200 -> V_201 ;
int * V_202 = V_194 -> V_157 ;
int V_203 = * V_202 ;
int V_204 ;
V_204 = F_141 ( V_194 , V_195 , V_196 , V_197 , V_198 ) ;
if ( V_195 && ( * V_202 != V_203 ) ) {
if ( ( * V_202 < 0 ) || ( * V_202 > 3 ) ) {
* V_202 = V_203 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_204 ;
}
static int
F_142 ( struct V_193 * V_194 , int V_195 ,
void T_6 * V_196 , V_50 * V_197 , T_7 * V_198 )
{
int * V_202 = V_194 -> V_157 ;
int V_203 [ 2 ] ;
int V_204 ;
memcpy ( V_203 , V_202 , sizeof( V_203 ) ) ;
V_204 = F_141 ( V_194 , V_195 , V_196 , V_197 , V_198 ) ;
if ( V_195 && ( V_202 [ 0 ] < 0 || V_202 [ 1 ] < 0 ||
( V_202 [ 0 ] >= V_202 [ 1 ] && V_202 [ 1 ] ) ) ) {
memcpy ( V_202 , V_203 , sizeof( V_203 ) ) ;
}
return V_204 ;
}
static int
F_143 ( struct V_193 * V_194 , int V_195 ,
void T_6 * V_196 , V_50 * V_197 , T_7 * V_198 )
{
int * V_202 = V_194 -> V_157 ;
int V_203 = * V_202 ;
int V_204 ;
V_204 = F_141 ( V_194 , V_195 , V_196 , V_197 , V_198 ) ;
if ( V_195 && ( * V_202 != V_203 ) ) {
if ( ( * V_202 < 0 ) || ( * V_202 > 1 ) ) {
* V_202 = V_203 ;
}
}
return V_204 ;
}
static int
F_144 ( struct V_193 * V_194 , int V_195 ,
void T_6 * V_196 , V_50 * V_197 , T_7 * V_198 )
{
int * V_202 = V_194 -> V_157 ;
int V_203 = * V_202 ;
int V_204 ;
V_204 = F_141 ( V_194 , V_195 , V_196 , V_197 , V_198 ) ;
if ( V_195 && ( * V_202 != V_203 ) ) {
if ( * V_202 < 1 || ! F_145 ( * V_202 ) ) {
* V_202 = V_203 ;
}
}
return V_204 ;
}
static inline const char * F_146 ( unsigned int V_12 )
{
switch ( V_12 & V_88 ) {
case V_205 :
return L_25 ;
case V_206 :
return L_26 ;
case V_207 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_147 ( struct V_208 * V_209 , T_7 V_210 )
{
struct V_2 * V_2 = F_148 ( V_209 ) ;
struct V_211 * V_212 = V_209 -> V_213 ;
int V_179 ;
struct V_54 * V_55 ;
for ( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_210 -- == 0 ) {
V_212 -> V_194 = V_61 ;
V_212 -> V_214 = V_179 ;
return V_55 ;
}
}
}
for ( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_210 -- == 0 ) {
V_212 -> V_194 = V_63 ;
V_212 -> V_214 = V_179 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_149 ( struct V_208 * V_209 , T_7 * V_210 )
__acquires( T_8 )
{
F_58 () ;
return * V_210 ? F_147 ( V_209 , * V_210 - 1 ) : V_215 ;
}
static void * F_150 ( struct V_208 * V_209 , void * V_216 , T_7 * V_210 )
{
struct V_180 * V_217 ;
struct V_211 * V_212 ;
struct V_54 * V_55 ;
++ * V_210 ;
if ( V_216 == V_215 )
return F_147 ( V_209 , 0 ) ;
V_55 = V_216 ;
V_212 = V_209 -> V_213 ;
if ( V_212 -> V_194 == V_61 ) {
V_217 = F_151 ( F_152 ( & V_55 -> V_60 ) ) ;
if ( V_217 )
return F_153 ( V_217 , struct V_54 , V_60 ) ;
while ( ++ V_212 -> V_214 < V_182 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_212 -> V_194 = V_63 ;
V_212 -> V_214 = - 1 ;
goto V_218;
}
V_217 = F_151 ( F_152 ( & V_55 -> V_62 ) ) ;
if ( V_217 )
return F_153 ( V_217 , struct V_54 , V_62 ) ;
V_218:
while ( ++ V_212 -> V_214 < V_182 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_154 ( struct V_208 * V_209 , void * V_216 )
__releases( T_8 )
{
F_59 () ;
}
static int F_155 ( struct V_208 * V_209 , void * V_216 )
{
if ( V_216 == V_215 ) {
F_156 ( V_209 ,
L_29 ,
F_157 ( V_219 ) , V_220 ) ;
F_158 ( V_209 ,
L_30 ) ;
F_158 ( V_209 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_216 ;
const struct V_211 * V_212 = V_209 -> V_213 ;
const struct V_74 * V_75 ;
struct V_111 * V_112 = F_151 ( V_55 -> V_123 ) ;
if ( V_212 -> V_194 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_156 ( V_209 , L_32 ,
F_43 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_131 ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_185 ) ;
else
#endif
F_156 ( V_209 , L_33 ,
F_43 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_185 ,
( V_55 -> V_12 & V_221 ) ? L_34 : L_35 ) ;
} else {
F_156 ( V_209 , L_36 ,
V_55 -> V_53 , V_112 -> V_185 ,
( V_55 -> V_12 & V_221 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_222 )
F_156 ( V_209 , L_37 ,
V_55 -> V_171 ,
F_25 ( V_55 -> V_170 ) ) ;
else
F_159 ( V_209 , '\n' ) ;
F_61 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_156 ( V_209 ,
L_38
L_39 ,
& V_75 -> V_4 . V_131 ,
F_23 ( V_75 -> V_43 ) ,
F_146 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_143 ) ,
F_15 ( & V_75 -> V_144 ) ) ;
else
#endif
F_156 ( V_209 ,
L_40
L_41 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_146 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_143 ) ,
F_15 ( & V_75 -> V_144 ) ) ;
}
}
return 0 ;
}
static int F_160 ( struct V_223 * V_223 , struct V_224 * V_224 )
{
return F_161 ( V_223 , V_224 , & V_225 ,
sizeof( struct V_211 ) ) ;
}
static int F_162 ( struct V_208 * V_209 , void * V_216 )
{
struct V_2 * V_2 = F_163 ( V_209 ) ;
struct V_98 V_226 ;
F_158 ( V_209 ,
L_42 ) ;
F_156 ( V_209 ,
L_43 ) ;
F_78 ( & V_226 , & F_41 ( V_2 ) -> V_192 ) ;
F_156 ( V_209 , L_44 , V_226 . V_102 ,
V_226 . V_103 , V_226 . V_104 ,
( unsigned long long ) V_226 . V_105 ,
( unsigned long long ) V_226 . V_106 ) ;
F_158 ( V_209 ,
L_45 ) ;
F_156 ( V_209 , L_46 ,
V_226 . V_227 , V_226 . V_228 , V_226 . V_229 ,
V_226 . V_230 , V_226 . V_231 ) ;
return 0 ;
}
static int F_164 ( struct V_223 * V_223 , struct V_224 * V_224 )
{
return F_165 ( V_223 , V_224 , F_162 ) ;
}
static int F_166 ( struct V_208 * V_209 , void * V_216 )
{
struct V_2 * V_2 = F_163 ( V_209 ) ;
struct V_99 * V_192 = & F_41 ( V_2 ) -> V_192 ;
struct V_139 T_9 * V_77 = V_192 -> V_77 ;
struct V_98 V_232 ;
int V_17 ;
F_158 ( V_209 ,
L_47 ) ;
F_156 ( V_209 ,
L_48 ) ;
F_93 (i) {
struct V_139 * V_161 = F_94 ( V_77 , V_17 ) ;
unsigned int V_233 ;
T_10 V_105 , V_106 ;
do {
V_233 = F_167 ( & V_161 -> V_142 ) ;
V_105 = V_161 -> V_234 . V_105 ;
V_106 = V_161 -> V_234 . V_106 ;
} while ( F_168 ( & V_161 -> V_142 , V_233 ) );
F_156 ( V_209 , L_49 ,
V_17 , V_161 -> V_234 . V_102 , V_161 -> V_234 . V_103 ,
V_161 -> V_234 . V_104 , ( T_10 ) V_105 ,
( T_10 ) V_106 ) ;
}
F_68 ( & V_192 -> V_101 ) ;
F_156 ( V_209 , L_50 ,
V_192 -> V_234 . V_102 , V_192 -> V_234 . V_103 ,
V_192 -> V_234 . V_104 ,
( unsigned long long ) V_192 -> V_234 . V_105 ,
( unsigned long long ) V_192 -> V_234 . V_106 ) ;
F_80 ( & V_232 , V_192 ) ;
F_72 ( & V_192 -> V_101 ) ;
F_158 ( V_209 ,
L_51 ) ;
F_156 ( V_209 , L_52 ,
V_232 . V_227 ,
V_232 . V_228 ,
V_232 . V_229 ,
V_232 . V_230 ,
V_232 . V_231 ) ;
return 0 ;
}
static int F_169 ( struct V_223 * V_223 , struct V_224 * V_224 )
{
return F_165 ( V_223 , V_224 , F_166 ) ;
}
static int F_170 ( struct V_2 * V_2 , struct V_235 * V_161 )
{
#if F_171 ( V_236 ) || F_171 ( V_237 )
struct V_238 * V_239 ;
#endif
F_101 ( 2 , L_53 ,
V_161 -> V_240 ,
V_161 -> V_241 ,
V_161 -> V_242 ) ;
#ifdef V_236
if ( V_161 -> V_240 ) {
V_239 = F_172 ( V_2 , V_68 ) ;
V_239 -> V_243 [ V_244 ]
= V_161 -> V_240 * V_172 ;
}
if ( V_161 -> V_241 ) {
V_239 = F_172 ( V_2 , V_68 ) ;
V_239 -> V_243 [ V_245 ]
= V_161 -> V_241 * V_172 ;
}
#endif
#ifdef V_237
if ( V_161 -> V_242 ) {
V_239 = F_172 ( V_2 , V_246 ) ;
V_239 -> V_243 [ V_247 ]
= V_161 -> V_242 * V_172 ;
}
#endif
return 0 ;
}
static void F_173 ( struct V_160 * V_248 ,
struct V_249 * V_250 )
{
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_40 = V_174 ;
V_248 -> V_59 = V_250 -> V_59 ;
V_248 -> V_4 . V_46 = V_250 -> V_4 ;
V_248 -> V_43 = V_250 -> V_43 ;
V_248 -> V_53 = V_250 -> V_53 ;
V_248 -> V_165 = V_250 -> V_165 ;
V_248 -> V_12 = V_250 -> V_12 ;
V_248 -> V_171 = V_250 -> V_171 ;
V_248 -> V_170 = V_250 -> V_170 ;
}
static void F_174 ( struct V_107 * V_108 ,
struct V_251 * V_252 )
{
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_4 . V_46 = V_252 -> V_4 ;
V_108 -> V_43 = V_252 -> V_43 ;
V_108 -> V_113 = V_252 -> V_113 ;
V_108 -> V_114 = V_252 -> V_114 ;
V_108 -> V_119 = V_252 -> V_119 ;
V_108 -> V_121 = V_252 -> V_121 ;
}
static int
F_175 ( struct V_253 * V_254 , int V_255 , void T_6 * V_256 , unsigned int V_257 )
{
struct V_2 * V_2 = F_176 ( V_254 ) ;
int V_146 ;
unsigned char V_258 [ V_259 ] ;
struct V_249 * V_250 ;
struct V_160 V_248 ;
struct V_54 * V_55 ;
struct V_251 * V_252 ;
struct V_107 V_108 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
if ( ! F_177 ( F_176 ( V_254 ) -> V_260 , V_261 ) )
return - V_262 ;
if ( V_255 < V_263 || V_255 > V_264 )
return - V_134 ;
if ( V_257 < 0 || V_257 > V_259 )
return - V_134 ;
if ( V_257 != V_265 [ F_178 ( V_255 ) ] ) {
F_28 ( L_54 ,
V_257 , V_265 [ F_178 ( V_255 ) ] ) ;
return - V_134 ;
}
if ( F_179 ( V_258 , V_256 , V_257 ) != 0 )
return - V_266 ;
F_18 () ;
if ( V_255 == V_267 ||
V_255 == V_268 ) {
struct V_269 * V_270 = (struct V_269 * ) V_258 ;
F_131 ( & V_15 -> V_271 ) ;
if ( V_255 == V_267 )
V_146 = F_180 ( V_2 , V_270 -> V_272 , V_270 -> V_273 ,
V_270 -> V_274 ) ;
else
V_146 = F_181 ( V_2 , V_270 -> V_272 ) ;
F_132 ( & V_15 -> V_271 ) ;
goto V_275;
}
F_131 ( & V_183 ) ;
if ( V_255 == V_276 ) {
V_146 = F_128 ( V_2 , false ) ;
goto V_277;
} else if ( V_255 == V_278 ) {
V_146 = F_170 ( V_2 , (struct V_235 * ) V_258 ) ;
goto V_277;
}
V_250 = (struct V_249 * ) V_258 ;
V_252 = (struct V_251 * ) ( V_250 + 1 ) ;
F_173 ( & V_248 , V_250 ) ;
F_174 ( & V_108 , V_252 ) ;
if ( V_255 == V_279 ) {
if ( ! V_248 . V_53 && ! V_248 . V_4 . V_46 && ! V_248 . V_43 ) {
V_146 = F_139 ( V_2 ) ;
goto V_277;
}
}
if ( V_248 . V_59 != V_68 && V_248 . V_59 != V_246 &&
V_248 . V_59 != V_280 ) {
F_28 ( L_55 ,
V_248 . V_59 , & V_248 . V_4 . V_46 ,
F_23 ( V_248 . V_43 ) , V_248 . V_165 ) ;
V_146 = - V_266 ;
goto V_277;
}
F_58 () ;
if ( V_248 . V_53 == 0 )
V_55 = F_35 ( V_2 , V_248 . V_40 , V_248 . V_59 ,
& V_248 . V_4 , V_248 . V_43 ) ;
else
V_55 = F_39 ( V_2 , V_248 . V_40 , V_248 . V_53 ) ;
F_59 () ;
if ( V_255 != V_281
&& ( V_55 == NULL || V_55 -> V_59 != V_248 . V_59 ) ) {
V_146 = - V_282 ;
goto V_277;
}
switch ( V_255 ) {
case V_281 :
if ( V_55 != NULL )
V_146 = - V_148 ;
else
V_146 = F_115 ( V_2 , & V_248 , & V_55 ) ;
break;
case V_283 :
V_146 = F_124 ( V_55 , & V_248 ) ;
break;
case V_284 :
V_146 = F_127 ( V_55 ) ;
if ( ! V_146 )
goto V_277;
break;
case V_279 :
V_146 = F_138 ( V_55 ) ;
break;
case V_285 :
V_146 = F_100 ( V_55 , & V_108 ) ;
break;
case V_286 :
V_146 = F_102 ( V_55 , & V_108 ) ;
break;
case V_287 :
V_146 = F_111 ( V_55 , & V_108 ) ;
break;
default:
V_146 = - V_134 ;
}
V_277:
F_132 ( & V_183 ) ;
V_275:
F_20 () ;
return V_146 ;
}
static void
F_182 ( struct V_288 * V_9 , struct V_54 * V_100 )
{
struct V_111 * V_112 ;
V_112 = F_65 ( V_100 -> V_123 , 1 ) ;
V_9 -> V_59 = V_100 -> V_59 ;
V_9 -> V_4 = V_100 -> V_4 . V_46 ;
V_9 -> V_43 = V_100 -> V_43 ;
V_9 -> V_53 = V_100 -> V_53 ;
F_183 ( V_9 -> V_165 , V_112 -> V_185 , sizeof( V_9 -> V_165 ) ) ;
V_9 -> V_12 = V_100 -> V_12 ;
V_9 -> V_171 = V_100 -> V_171 / V_172 ;
V_9 -> V_170 = V_100 -> V_170 ;
V_9 -> V_126 = V_100 -> V_126 ;
F_78 ( & V_9 -> V_76 , & V_100 -> V_76 ) ;
}
static inline int
F_184 ( struct V_2 * V_2 ,
const struct V_289 * V_290 ,
struct V_289 T_6 * V_291 )
{
int V_179 , V_292 = 0 ;
struct V_54 * V_55 ;
struct V_288 V_293 ;
int V_146 = 0 ;
for ( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_137 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_174 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_292 >= V_290 -> V_175 )
goto V_67;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
F_182 ( & V_293 , V_55 ) ;
if ( F_185 ( & V_291 -> V_294 [ V_292 ] ,
& V_293 , sizeof( V_293 ) ) ) {
V_146 = - V_266 ;
goto V_67;
}
V_292 ++ ;
}
}
for ( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_137 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_174 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_292 >= V_290 -> V_175 )
goto V_67;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
F_182 ( & V_293 , V_55 ) ;
if ( F_185 ( & V_291 -> V_294 [ V_292 ] ,
& V_293 , sizeof( V_293 ) ) ) {
V_146 = - V_266 ;
goto V_67;
}
V_292 ++ ;
}
}
V_67:
return V_146 ;
}
static inline int
F_186 ( struct V_2 * V_2 , const struct V_295 * V_290 ,
struct V_295 T_6 * V_291 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_290 -> V_4 } ;
int V_146 = 0 ;
F_58 () ;
if ( V_290 -> V_53 )
V_55 = F_39 ( V_2 , V_174 , V_290 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_174 , V_290 -> V_59 , & V_4 ,
V_290 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
int V_292 = 0 ;
struct V_74 * V_75 ;
struct V_296 V_293 ;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
F_69 (dest, &svc->destinations, n_list) {
if ( V_292 >= V_290 -> V_126 )
break;
V_293 . V_4 = V_75 -> V_4 . V_46 ;
V_293 . V_43 = V_75 -> V_43 ;
V_293 . V_113 = F_15 ( & V_75 -> V_113 ) ;
V_293 . V_114 = F_15 ( & V_75 -> V_114 ) ;
V_293 . V_119 = V_75 -> V_119 ;
V_293 . V_121 = V_75 -> V_121 ;
V_293 . V_143 = F_15 ( & V_75 -> V_143 ) ;
V_293 . V_144 = F_15 ( & V_75 -> V_144 ) ;
V_293 . V_145 = F_15 ( & V_75 -> V_145 ) ;
F_78 ( & V_293 . V_76 , & V_75 -> V_76 ) ;
if ( F_185 ( & V_291 -> V_294 [ V_292 ] ,
& V_293 , sizeof( V_293 ) ) ) {
V_146 = - V_266 ;
break;
}
V_292 ++ ;
}
} else
V_146 = - V_282 ;
return V_146 ;
}
static inline void
F_187 ( struct V_2 * V_2 , struct V_235 * V_161 )
{
#if F_171 ( V_236 ) || F_171 ( V_237 )
struct V_238 * V_239 ;
#endif
memset ( V_161 , 0 , sizeof ( * V_161 ) ) ;
#ifdef V_236
V_239 = F_172 ( V_2 , V_68 ) ;
V_161 -> V_240 = V_239 -> V_243 [ V_244 ] / V_172 ;
V_161 -> V_241 = V_239 -> V_243 [ V_245 ] / V_172 ;
#endif
#ifdef V_237
V_239 = F_172 ( V_2 , V_246 ) ;
V_161 -> V_242 =
V_239 -> V_243 [ V_247 ] / V_172 ;
#endif
}
static int
F_188 ( struct V_253 * V_254 , int V_255 , void T_6 * V_256 , int * V_257 )
{
unsigned char V_258 [ 128 ] ;
int V_146 = 0 ;
unsigned int V_297 ;
struct V_2 * V_2 = F_176 ( V_254 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_189 ( ! V_2 ) ;
if ( ! F_177 ( F_176 ( V_254 ) -> V_260 , V_261 ) )
return - V_262 ;
if ( V_255 < V_263 || V_255 > V_298 )
return - V_134 ;
if ( * V_257 < V_299 [ F_190 ( V_255 ) ] ) {
F_28 ( L_56 ,
* V_257 , V_299 [ F_190 ( V_255 ) ] ) ;
return - V_134 ;
}
V_297 = V_299 [ F_190 ( V_255 ) ] ;
if ( V_297 > 128 )
return - V_134 ;
if ( F_179 ( V_258 , V_256 , V_297 ) != 0 )
return - V_266 ;
if ( V_255 == V_300 ) {
struct V_269 V_301 [ 2 ] ;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
F_131 ( & V_15 -> V_271 ) ;
if ( V_15 -> V_302 & V_303 ) {
V_301 [ 0 ] . V_272 = V_303 ;
F_183 ( V_301 [ 0 ] . V_273 , V_15 -> V_304 ,
sizeof( V_301 [ 0 ] . V_273 ) ) ;
V_301 [ 0 ] . V_274 = V_15 -> V_305 ;
}
if ( V_15 -> V_302 & V_306 ) {
V_301 [ 1 ] . V_272 = V_306 ;
F_183 ( V_301 [ 1 ] . V_273 , V_15 -> V_307 ,
sizeof( V_301 [ 1 ] . V_273 ) ) ;
V_301 [ 1 ] . V_274 = V_15 -> V_308 ;
}
if ( F_185 ( V_256 , & V_301 , sizeof( V_301 ) ) != 0 )
V_146 = - V_266 ;
F_132 ( & V_15 -> V_271 ) ;
return V_146 ;
}
F_131 ( & V_183 ) ;
switch ( V_255 ) {
case V_309 :
{
char V_310 [ 64 ] ;
sprintf ( V_310 , L_57 ,
F_157 ( V_219 ) , V_220 ) ;
if ( F_185 ( V_256 , V_310 , strlen ( V_310 ) + 1 ) != 0 ) {
V_146 = - V_266 ;
goto V_67;
}
* V_257 = strlen ( V_310 ) + 1 ;
}
break;
case V_311 :
{
struct V_312 V_313 ;
V_313 . V_314 = V_219 ;
V_313 . V_315 = V_220 ;
V_313 . V_175 = V_15 -> V_175 ;
if ( F_185 ( V_256 , & V_313 , sizeof( V_313 ) ) != 0 )
V_146 = - V_266 ;
}
break;
case V_316 :
{
struct V_289 * V_290 ;
int V_315 ;
V_290 = (struct V_289 * ) V_258 ;
V_315 = sizeof( * V_290 ) +
sizeof( struct V_288 ) * V_290 -> V_175 ;
if ( * V_257 != V_315 ) {
F_28 ( L_58 , * V_257 , V_315 ) ;
V_146 = - V_134 ;
goto V_67;
}
V_146 = F_184 ( V_2 , V_290 , V_256 ) ;
}
break;
case V_317 :
{
struct V_288 * V_293 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_293 = (struct V_288 * ) V_258 ;
V_4 . V_46 = V_293 -> V_4 ;
F_58 () ;
if ( V_293 -> V_53 )
V_55 = F_39 ( V_2 , V_174 , V_293 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_174 ,
V_293 -> V_59 , & V_4 ,
V_293 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
F_182 ( V_293 , V_55 ) ;
if ( F_185 ( V_256 , V_293 , sizeof( * V_293 ) ) != 0 )
V_146 = - V_266 ;
} else
V_146 = - V_282 ;
}
break;
case V_318 :
{
struct V_295 * V_290 ;
int V_315 ;
V_290 = (struct V_295 * ) V_258 ;
V_315 = sizeof( * V_290 ) +
sizeof( struct V_296 ) * V_290 -> V_126 ;
if ( * V_257 != V_315 ) {
F_28 ( L_58 , * V_257 , V_315 ) ;
V_146 = - V_134 ;
goto V_67;
}
V_146 = F_186 ( V_2 , V_290 , V_256 ) ;
}
break;
case V_319 :
{
struct V_235 V_320 ;
F_187 ( V_2 , & V_320 ) ;
if ( F_185 ( V_256 , & V_320 , sizeof( V_320 ) ) != 0 )
V_146 = - V_266 ;
}
break;
default:
V_146 = - V_134 ;
}
V_67:
F_132 ( & V_183 ) ;
return V_146 ;
}
static int F_191 ( struct V_321 * V_322 , int V_323 ,
struct V_99 * V_76 )
{
struct V_98 V_234 ;
struct V_324 * V_325 = F_192 ( V_322 , V_323 ) ;
if ( ! V_325 )
return - V_326 ;
F_78 ( & V_234 , V_76 ) ;
if ( F_193 ( V_322 , V_327 , V_234 . V_102 ) ||
F_193 ( V_322 , V_328 , V_234 . V_103 ) ||
F_193 ( V_322 , V_329 , V_234 . V_104 ) ||
F_194 ( V_322 , V_330 , V_234 . V_105 ) ||
F_194 ( V_322 , V_331 , V_234 . V_106 ) ||
F_193 ( V_322 , V_332 , V_234 . V_227 ) ||
F_193 ( V_322 , V_333 , V_234 . V_228 ) ||
F_193 ( V_322 , V_334 , V_234 . V_229 ) ||
F_193 ( V_322 , V_335 , V_234 . V_230 ) ||
F_193 ( V_322 , V_336 , V_234 . V_231 ) )
goto V_337;
F_195 ( V_322 , V_325 ) ;
return 0 ;
V_337:
F_196 ( V_322 , V_325 ) ;
return - V_326 ;
}
static int F_197 ( struct V_321 * V_322 ,
struct V_54 * V_55 )
{
struct V_111 * V_112 ;
struct V_163 * V_164 ;
struct V_324 * V_338 ;
struct V_339 V_12 = { . V_12 = V_55 -> V_12 ,
. V_340 = ~ 0 } ;
V_338 = F_192 ( V_322 , V_341 ) ;
if ( ! V_338 )
return - V_326 ;
if ( F_198 ( V_322 , V_342 , V_55 -> V_40 ) )
goto V_337;
if ( V_55 -> V_53 ) {
if ( F_193 ( V_322 , V_343 , V_55 -> V_53 ) )
goto V_337;
} else {
if ( F_198 ( V_322 , V_344 , V_55 -> V_59 ) ||
F_199 ( V_322 , V_345 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_200 ( V_322 , V_346 , V_55 -> V_43 ) )
goto V_337;
}
V_112 = F_65 ( V_55 -> V_123 , 1 ) ;
V_164 = F_65 ( V_55 -> V_164 , 1 ) ;
if ( F_201 ( V_322 , V_347 , V_112 -> V_185 ) ||
( V_164 && F_201 ( V_322 , V_348 , V_164 -> V_185 ) ) ||
F_199 ( V_322 , V_349 , sizeof( V_12 ) , & V_12 ) ||
F_193 ( V_322 , V_350 , V_55 -> V_171 / V_172 ) ||
F_202 ( V_322 , V_351 , V_55 -> V_170 ) )
goto V_337;
if ( F_191 ( V_322 , V_352 , & V_55 -> V_76 ) )
goto V_337;
F_195 ( V_322 , V_338 ) ;
return 0 ;
V_337:
F_196 ( V_322 , V_338 ) ;
return - V_326 ;
}
static int F_203 ( struct V_321 * V_322 ,
struct V_54 * V_55 ,
struct V_353 * V_354 )
{
void * V_355 ;
V_355 = F_204 ( V_322 , F_205 ( V_354 -> V_322 ) . V_356 , V_354 -> V_357 -> V_358 ,
& V_359 , V_360 ,
V_361 ) ;
if ( ! V_355 )
return - V_326 ;
if ( F_197 ( V_322 , V_55 ) < 0 )
goto V_337;
return F_206 ( V_322 , V_355 ) ;
V_337:
F_207 ( V_322 , V_355 ) ;
return - V_326 ;
}
static int F_208 ( struct V_321 * V_322 ,
struct V_353 * V_354 )
{
int V_179 = 0 , V_17 ;
int V_233 = V_354 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_209 ( V_322 ) ;
F_131 ( & V_183 ) ;
for ( V_17 = 0 ; V_17 < V_182 ; V_17 ++ ) {
F_137 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_179 <= V_233 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_203 ( V_322 , V_55 , V_354 ) < 0 ) {
V_179 -- ;
goto V_337;
}
}
}
for ( V_17 = 0 ; V_17 < V_182 ; V_17 ++ ) {
F_137 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_179 <= V_233 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_203 ( V_322 , V_55 , V_354 ) < 0 ) {
V_179 -- ;
goto V_337;
}
}
}
V_337:
F_132 ( & V_183 ) ;
V_354 -> args [ 0 ] = V_179 ;
return V_322 -> V_257 ;
}
static int F_210 ( struct V_2 * V_2 ,
struct V_160 * V_248 ,
struct V_324 * V_362 , int V_363 ,
struct V_54 * * V_364 )
{
struct V_324 * V_365 [ V_366 + 1 ] ;
struct V_324 * V_367 , * V_368 , * V_369 , * V_370 , * V_371 ;
struct V_54 * V_55 ;
if ( V_362 == NULL ||
F_211 ( V_365 , V_366 , V_362 , V_372 ) )
return - V_134 ;
V_367 = V_365 [ V_342 ] ;
V_370 = V_365 [ V_344 ] ;
V_371 = V_365 [ V_345 ] ;
V_368 = V_365 [ V_346 ] ;
V_369 = V_365 [ V_343 ] ;
if ( ! ( V_367 && ( V_369 || ( V_368 && V_370 && V_371 ) ) ) )
return - V_134 ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_40 = F_212 ( V_367 ) ;
#ifdef F_24
if ( V_248 -> V_40 != V_174 && V_248 -> V_40 != V_48 )
#else
if ( V_248 -> V_40 != V_174 )
#endif
return - V_373 ;
if ( V_369 ) {
V_248 -> V_59 = V_68 ;
V_248 -> V_53 = F_213 ( V_369 ) ;
} else {
V_248 -> V_59 = F_212 ( V_370 ) ;
F_214 ( & V_248 -> V_4 , V_371 , sizeof( V_248 -> V_4 ) ) ;
V_248 -> V_43 = F_215 ( V_368 ) ;
V_248 -> V_53 = 0 ;
}
F_58 () ;
if ( V_248 -> V_53 )
V_55 = F_39 ( V_2 , V_248 -> V_40 , V_248 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_248 -> V_40 , V_248 -> V_59 ,
& V_248 -> V_4 , V_248 -> V_43 ) ;
F_59 () ;
* V_364 = V_55 ;
if ( V_363 ) {
struct V_324 * V_374 , * V_375 , * V_376 , * V_377 ,
* V_378 ;
struct V_339 V_12 ;
V_374 = V_365 [ V_347 ] ;
V_376 = V_365 [ V_348 ] ;
V_375 = V_365 [ V_349 ] ;
V_377 = V_365 [ V_350 ] ;
V_378 = V_365 [ V_351 ] ;
if ( ! ( V_374 && V_375 && V_377 && V_378 ) )
return - V_134 ;
F_214 ( & V_12 , V_375 , sizeof( V_12 ) ) ;
if ( V_55 )
V_248 -> V_12 = V_55 -> V_12 ;
V_248 -> V_12 = ( V_248 -> V_12 & ~ V_12 . V_340 ) |
( V_12 . V_12 & V_12 . V_340 ) ;
V_248 -> V_165 = F_216 ( V_374 ) ;
V_248 -> V_167 = V_376 ? F_216 ( V_376 ) : NULL ;
V_248 -> V_171 = F_213 ( V_377 ) ;
V_248 -> V_170 = F_217 ( V_378 ) ;
}
return 0 ;
}
static struct V_54 * F_218 ( struct V_2 * V_2 ,
struct V_324 * V_362 )
{
struct V_160 V_248 ;
struct V_54 * V_55 ;
int V_146 ;
V_146 = F_210 ( V_2 , & V_248 , V_362 , 0 , & V_55 ) ;
return V_146 ? F_219 ( V_146 ) : V_55 ;
}
static int F_220 ( struct V_321 * V_322 , struct V_74 * V_75 )
{
struct V_324 * V_379 ;
V_379 = F_192 ( V_322 , V_380 ) ;
if ( ! V_379 )
return - V_326 ;
if ( F_199 ( V_322 , V_381 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_200 ( V_322 , V_382 , V_75 -> V_43 ) ||
F_193 ( V_322 , V_383 ,
( F_15 ( & V_75 -> V_113 ) &
V_88 ) ) ||
F_193 ( V_322 , V_384 ,
F_15 ( & V_75 -> V_114 ) ) ||
F_193 ( V_322 , V_385 , V_75 -> V_119 ) ||
F_193 ( V_322 , V_386 , V_75 -> V_121 ) ||
F_193 ( V_322 , V_387 ,
F_15 ( & V_75 -> V_143 ) ) ||
F_193 ( V_322 , V_388 ,
F_15 ( & V_75 -> V_144 ) ) ||
F_193 ( V_322 , V_389 ,
F_15 ( & V_75 -> V_145 ) ) )
goto V_337;
if ( F_191 ( V_322 , V_390 , & V_75 -> V_76 ) )
goto V_337;
F_195 ( V_322 , V_379 ) ;
return 0 ;
V_337:
F_196 ( V_322 , V_379 ) ;
return - V_326 ;
}
static int F_221 ( struct V_321 * V_322 , struct V_74 * V_75 ,
struct V_353 * V_354 )
{
void * V_355 ;
V_355 = F_204 ( V_322 , F_205 ( V_354 -> V_322 ) . V_356 , V_354 -> V_357 -> V_358 ,
& V_359 , V_360 ,
V_391 ) ;
if ( ! V_355 )
return - V_326 ;
if ( F_220 ( V_322 , V_75 ) < 0 )
goto V_337;
return F_206 ( V_322 , V_355 ) ;
V_337:
F_207 ( V_322 , V_355 ) ;
return - V_326 ;
}
static int F_222 ( struct V_321 * V_322 ,
struct V_353 * V_354 )
{
int V_179 = 0 ;
int V_233 = V_354 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_324 * V_365 [ V_392 + 1 ] ;
struct V_2 * V_2 = F_209 ( V_322 ) ;
F_131 ( & V_183 ) ;
if ( F_223 ( V_354 -> V_357 , V_393 , V_365 ,
V_392 , V_394 ) )
goto V_166;
V_55 = F_218 ( V_2 , V_365 [ V_341 ] ) ;
if ( F_224 ( V_55 ) || V_55 == NULL )
goto V_166;
F_69 (dest, &svc->destinations, n_list) {
if ( ++ V_179 <= V_233 )
continue;
if ( F_221 ( V_322 , V_75 , V_354 ) < 0 ) {
V_179 -- ;
goto V_337;
}
}
V_337:
V_354 -> args [ 0 ] = V_179 ;
V_166:
F_132 ( & V_183 ) ;
return V_322 -> V_257 ;
}
static int F_225 ( struct V_107 * V_108 ,
struct V_324 * V_362 , int V_363 )
{
struct V_324 * V_365 [ V_395 + 1 ] ;
struct V_324 * V_371 , * V_368 ;
if ( V_362 == NULL ||
F_211 ( V_365 , V_395 , V_362 , V_396 ) )
return - V_134 ;
V_371 = V_365 [ V_381 ] ;
V_368 = V_365 [ V_382 ] ;
if ( ! ( V_371 && V_368 ) )
return - V_134 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
F_214 ( & V_108 -> V_4 , V_371 , sizeof( V_108 -> V_4 ) ) ;
V_108 -> V_43 = F_215 ( V_368 ) ;
if ( V_363 ) {
struct V_324 * V_397 , * V_398 , * V_399 ,
* V_400 ;
V_397 = V_365 [ V_383 ] ;
V_398 = V_365 [ V_384 ] ;
V_399 = V_365 [ V_385 ] ;
V_400 = V_365 [ V_386 ] ;
if ( ! ( V_397 && V_398 && V_399 && V_400 ) )
return - V_134 ;
V_108 -> V_113 = F_213 ( V_397 )
& V_88 ;
V_108 -> V_114 = F_213 ( V_398 ) ;
V_108 -> V_119 = F_213 ( V_399 ) ;
V_108 -> V_121 = F_213 ( V_400 ) ;
}
return 0 ;
}
static int F_226 ( struct V_321 * V_322 , T_3 V_272 ,
const char * V_273 , T_3 V_274 )
{
struct V_324 * V_401 ;
V_401 = F_192 ( V_322 , V_402 ) ;
if ( ! V_401 )
return - V_326 ;
if ( F_193 ( V_322 , V_403 , V_272 ) ||
F_201 ( V_322 , V_404 , V_273 ) ||
F_193 ( V_322 , V_405 , V_274 ) )
goto V_337;
F_195 ( V_322 , V_401 ) ;
return 0 ;
V_337:
F_196 ( V_322 , V_401 ) ;
return - V_326 ;
}
static int F_227 ( struct V_321 * V_322 , T_3 V_272 ,
const char * V_273 , T_3 V_274 ,
struct V_353 * V_354 )
{
void * V_355 ;
V_355 = F_204 ( V_322 , F_205 ( V_354 -> V_322 ) . V_356 , V_354 -> V_357 -> V_358 ,
& V_359 , V_360 ,
V_406 ) ;
if ( ! V_355 )
return - V_326 ;
if ( F_226 ( V_322 , V_272 , V_273 , V_274 ) )
goto V_337;
return F_206 ( V_322 , V_355 ) ;
V_337:
F_207 ( V_322 , V_355 ) ;
return - V_326 ;
}
static int F_228 ( struct V_321 * V_322 ,
struct V_353 * V_354 )
{
struct V_2 * V_2 = F_209 ( V_322 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_131 ( & V_15 -> V_271 ) ;
if ( ( V_15 -> V_302 & V_303 ) && ! V_354 -> args [ 0 ] ) {
if ( F_227 ( V_322 , V_303 ,
V_15 -> V_304 ,
V_15 -> V_305 , V_354 ) < 0 )
goto V_337;
V_354 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_302 & V_306 ) && ! V_354 -> args [ 1 ] ) {
if ( F_227 ( V_322 , V_306 ,
V_15 -> V_307 ,
V_15 -> V_308 , V_354 ) < 0 )
goto V_337;
V_354 -> args [ 1 ] = 1 ;
}
V_337:
F_132 ( & V_15 -> V_271 ) ;
return V_322 -> V_257 ;
}
static int F_229 ( struct V_2 * V_2 , struct V_324 * * V_365 )
{
if ( ! ( V_365 [ V_403 ] &&
V_365 [ V_404 ] &&
V_365 [ V_405 ] ) )
return - V_134 ;
return F_180 ( V_2 ,
F_213 ( V_365 [ V_403 ] ) ,
F_216 ( V_365 [ V_404 ] ) ,
F_213 ( V_365 [ V_405 ] ) ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_324 * * V_365 )
{
if ( ! V_365 [ V_403 ] )
return - V_134 ;
return F_181 ( V_2 ,
F_213 ( V_365 [ V_403 ] ) ) ;
}
static int F_231 ( struct V_2 * V_2 , struct V_324 * * V_365 )
{
struct V_235 V_320 ;
F_187 ( V_2 , & V_320 ) ;
if ( V_365 [ V_407 ] )
V_320 . V_240 = F_213 ( V_365 [ V_407 ] ) ;
if ( V_365 [ V_408 ] )
V_320 . V_241 =
F_213 ( V_365 [ V_408 ] ) ;
if ( V_365 [ V_409 ] )
V_320 . V_242 = F_213 ( V_365 [ V_409 ] ) ;
return F_170 ( V_2 , & V_320 ) ;
}
static int F_232 ( struct V_321 * V_322 , struct V_410 * V_313 )
{
int V_146 = 0 , V_255 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_209 ( V_322 ) ;
V_15 = F_41 ( V_2 ) ;
V_255 = V_313 -> V_411 -> V_255 ;
if ( V_255 == V_406 || V_255 == V_412 ) {
struct V_324 * V_413 [ V_414 + 1 ] ;
F_131 ( & V_15 -> V_271 ) ;
if ( ! V_313 -> V_365 [ V_402 ] ||
F_211 ( V_413 , V_414 ,
V_313 -> V_365 [ V_402 ] ,
V_415 ) ) {
V_146 = - V_134 ;
goto V_67;
}
if ( V_255 == V_406 )
V_146 = F_229 ( V_2 , V_413 ) ;
else
V_146 = F_230 ( V_2 , V_413 ) ;
V_67:
F_132 ( & V_15 -> V_271 ) ;
}
return V_146 ;
}
static int F_233 ( struct V_321 * V_322 , struct V_410 * V_313 )
{
struct V_54 * V_55 = NULL ;
struct V_160 V_248 ;
struct V_107 V_108 ;
int V_146 = 0 , V_255 ;
int V_416 = 0 , V_417 = 0 ;
struct V_2 * V_2 ;
V_2 = F_209 ( V_322 ) ;
V_255 = V_313 -> V_411 -> V_255 ;
F_131 ( & V_183 ) ;
if ( V_255 == V_418 ) {
V_146 = F_128 ( V_2 , false ) ;
goto V_67;
} else if ( V_255 == V_419 ) {
V_146 = F_231 ( V_2 , V_313 -> V_365 ) ;
goto V_67;
} else if ( V_255 == V_420 &&
! V_313 -> V_365 [ V_341 ] ) {
V_146 = F_139 ( V_2 ) ;
goto V_67;
}
if ( V_255 == V_361 || V_255 == V_421 )
V_416 = 1 ;
V_146 = F_210 ( V_2 , & V_248 ,
V_313 -> V_365 [ V_341 ] ,
V_416 , & V_55 ) ;
if ( V_146 )
goto V_67;
if ( ( V_255 != V_361 ) && ( V_55 == NULL ) ) {
V_146 = - V_282 ;
goto V_67;
}
if ( V_255 == V_391 || V_255 == V_422 ||
V_255 == V_423 ) {
if ( V_255 != V_423 )
V_417 = 1 ;
V_146 = F_225 ( & V_108 ,
V_313 -> V_365 [ V_380 ] ,
V_417 ) ;
if ( V_146 )
goto V_67;
}
switch ( V_255 ) {
case V_361 :
if ( V_55 == NULL )
V_146 = F_115 ( V_2 , & V_248 , & V_55 ) ;
else
V_146 = - V_148 ;
break;
case V_421 :
V_146 = F_124 ( V_55 , & V_248 ) ;
break;
case V_424 :
V_146 = F_127 ( V_55 ) ;
break;
case V_391 :
V_146 = F_100 ( V_55 , & V_108 ) ;
break;
case V_422 :
V_146 = F_102 ( V_55 , & V_108 ) ;
break;
case V_423 :
V_146 = F_111 ( V_55 , & V_108 ) ;
break;
case V_420 :
V_146 = F_138 ( V_55 ) ;
break;
default:
V_146 = - V_134 ;
}
V_67:
F_132 ( & V_183 ) ;
return V_146 ;
}
static int F_234 ( struct V_321 * V_322 , struct V_410 * V_313 )
{
struct V_321 * V_425 ;
void * V_426 ;
int V_146 , V_255 , V_427 ;
struct V_2 * V_2 ;
V_2 = F_209 ( V_322 ) ;
V_255 = V_313 -> V_411 -> V_255 ;
if ( V_255 == V_428 )
V_427 = V_361 ;
else if ( V_255 == V_429 )
V_427 = V_430 ;
else if ( V_255 == V_431 )
V_427 = V_419 ;
else {
F_28 ( L_59 ) ;
return - V_134 ;
}
V_425 = F_235 ( V_432 , V_137 ) ;
if ( ! V_425 )
return - V_138 ;
F_131 ( & V_183 ) ;
V_426 = F_236 ( V_425 , V_313 , & V_359 , 0 , V_427 ) ;
if ( V_426 == NULL )
goto V_337;
switch ( V_255 ) {
case V_428 :
{
struct V_54 * V_55 ;
V_55 = F_218 ( V_2 ,
V_313 -> V_365 [ V_341 ] ) ;
if ( F_224 ( V_55 ) ) {
V_146 = F_237 ( V_55 ) ;
goto V_166;
} else if ( V_55 ) {
V_146 = F_197 ( V_425 , V_55 ) ;
if ( V_146 )
goto V_337;
} else {
V_146 = - V_282 ;
goto V_166;
}
break;
}
case V_431 :
{
struct V_235 V_320 ;
F_187 ( V_2 , & V_320 ) ;
#ifdef V_236
if ( F_193 ( V_425 , V_407 ,
V_320 . V_240 ) ||
F_193 ( V_425 , V_408 ,
V_320 . V_241 ) )
goto V_337;
#endif
#ifdef V_237
if ( F_193 ( V_425 , V_409 , V_320 . V_242 ) )
goto V_337;
#endif
break;
}
case V_429 :
if ( F_193 ( V_425 , V_433 ,
V_219 ) ||
F_193 ( V_425 , V_434 ,
V_220 ) )
goto V_337;
break;
}
F_206 ( V_425 , V_426 ) ;
V_146 = F_238 ( V_425 , V_313 ) ;
goto V_67;
V_337:
F_28 ( L_60 ) ;
V_146 = - V_326 ;
V_166:
F_239 ( V_425 ) ;
V_67:
F_132 ( & V_183 ) ;
return V_146 ;
}
static int T_11 F_240 ( void )
{
return F_241 ( & V_359 ,
V_435 ) ;
}
static void F_242 ( void )
{
F_243 ( & V_359 ) ;
}
static int T_12 F_244 ( struct V_2 * V_2 )
{
int V_179 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_193 * V_436 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_98 ( & V_15 -> V_25 ) ;
F_98 ( & V_15 -> V_28 ) ;
F_98 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_437 ) ) {
V_436 = F_245 ( V_438 , sizeof( V_438 ) , V_137 ) ;
if ( V_436 == NULL )
return - V_138 ;
if ( V_2 -> V_260 != & V_439 )
V_436 [ 0 ] . V_440 = NULL ;
} else
V_436 = V_438 ;
V_179 = 0 ;
V_15 -> V_24 = 1024 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_32 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_26 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_29 ;
#ifdef F_246
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_441 ;
#endif
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_34 ;
V_15 -> V_442 = 1 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_442 ;
V_15 -> V_443 = 1 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_443 ;
V_15 -> V_444 = 1 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_444 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_445 ;
V_15 -> V_446 = F_247 () / 32 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_446 ;
V_15 -> V_447 = 0 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_447 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_448 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_449 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_450 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_451 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_452 ;
V_15 -> V_453 [ 0 ] = V_454 ;
V_15 -> V_453 [ 1 ] = V_455 ;
V_436 [ V_179 ] . V_157 = & V_15 -> V_453 ;
V_436 [ V_179 ++ ] . V_456 = sizeof( V_15 -> V_453 ) ;
V_15 -> V_457 = V_458 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_457 ;
V_15 -> V_459 = F_248 ( int , V_460 , 0 , 3 ) ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_459 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_461 ;
V_15 -> V_462 = 1 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_462 ;
V_436 [ V_179 ++ ] . V_157 = & V_15 -> V_463 ;
V_15 -> V_464 = F_249 ( V_2 , L_61 , V_436 ) ;
if ( V_15 -> V_464 == NULL ) {
if ( ! F_38 ( V_2 , & V_437 ) )
F_49 ( V_436 ) ;
return - V_138 ;
}
F_85 ( V_2 , & V_15 -> V_192 ) ;
V_15 -> V_465 = V_436 ;
F_250 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_251 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_252 ( & V_15 -> V_37 ) ;
F_253 ( & V_15 -> V_37 . V_36 ) ;
F_254 ( V_15 -> V_464 ) ;
F_104 ( V_2 , & V_15 -> V_192 ) ;
}
static int T_12 F_244 ( struct V_2 * V_2 ) { return 0 ; }
static void T_13 F_251 ( struct V_2 * V_2 ) { }
int T_12 F_255 ( struct V_2 * V_2 )
{
int V_17 , V_179 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
for ( V_179 = 0 ; V_179 < V_466 ; V_179 ++ )
F_256 ( & V_15 -> V_85 [ V_179 ] ) ;
F_119 ( & V_15 -> V_151 ) ;
F_98 ( & V_15 -> V_94 ) ;
F_257 ( & V_15 -> V_97 , F_112 ,
( unsigned long ) V_2 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_192 . V_77 = F_92 ( struct V_139 ) ;
if ( ! V_15 -> V_192 . V_77 )
return - V_138 ;
F_93 (i) {
struct V_139 * V_467 ;
V_467 = F_94 ( V_15 -> V_192 . V_77 , V_17 ) ;
F_95 ( & V_467 -> V_142 ) ;
}
F_98 ( & V_15 -> V_192 . V_101 ) ;
F_258 ( L_62 , 0 , V_2 -> V_468 , & V_469 ) ;
F_258 ( L_63 , 0 , V_2 -> V_468 , & V_470 ) ;
F_258 ( L_64 , 0 , V_2 -> V_468 ,
& V_471 ) ;
if ( F_244 ( V_2 ) )
goto V_472;
return 0 ;
V_472:
F_48 ( V_15 -> V_192 . V_77 ) ;
return - V_138 ;
}
void T_13 F_259 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_75 ( V_2 ) ;
F_251 ( V_2 ) ;
F_260 ( L_64 , V_2 -> V_468 ) ;
F_260 ( L_63 , V_2 -> V_468 ) ;
F_260 ( L_62 , V_2 -> V_468 ) ;
F_48 ( V_15 -> V_192 . V_77 ) ;
}
int T_11 F_261 ( void )
{
int V_146 ;
V_146 = F_262 ( & V_473 ) ;
if ( V_146 ) {
F_28 ( L_65 ) ;
goto V_474;
}
V_146 = F_240 () ;
if ( V_146 ) {
F_28 ( L_66 ) ;
goto V_475;
}
return 0 ;
V_475:
F_263 ( & V_473 ) ;
V_474:
return V_146 ;
}
void F_264 ( void )
{
F_242 () ;
F_263 ( & V_473 ) ;
}
int T_11 F_265 ( void )
{
int V_179 ;
int V_146 ;
F_88 ( 2 ) ;
for ( V_179 = 0 ; V_179 < V_182 ; V_179 ++ ) {
F_256 ( & V_61 [ V_179 ] ) ;
F_256 ( & V_63 [ V_179 ] ) ;
}
F_266 () ;
V_146 = F_267 ( & V_476 ) ;
if ( V_146 < 0 )
return V_146 ;
F_99 ( 2 ) ;
return 0 ;
}
void F_268 ( void )
{
F_88 ( 2 ) ;
F_269 ( & V_476 ) ;
F_99 ( 2 ) ;
}
