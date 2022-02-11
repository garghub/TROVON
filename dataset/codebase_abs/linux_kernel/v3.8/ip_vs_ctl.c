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
#ifdef F_24
if ( V_40 == V_47 )
V_45 = V_4 -> V_48 [ 0 ] ^ V_4 -> V_48 [ 1 ] ^
V_4 -> V_48 [ 2 ] ^ V_4 -> V_48 [ 3 ] ;
#endif
V_45 ^= ( ( V_49 ) V_2 >> 8 ) ;
return ( V_41 ^ F_25 ( V_45 ) ^ ( V_44 >> V_50 ) ^ V_44 )
& V_51 ;
}
static inline unsigned int F_26 ( struct V_2 * V_2 , T_3 V_52 )
{
return ( ( ( V_49 ) V_2 >> 8 ) ^ V_52 ) & V_51 ;
}
static int F_27 ( struct V_53 * V_54 )
{
unsigned int V_55 ;
if ( V_54 -> V_12 & V_56 ) {
F_28 ( L_1 ,
V_57 , F_29 ( 0 ) ) ;
return 0 ;
}
if ( V_54 -> V_52 == 0 ) {
V_55 = F_22 ( V_54 -> V_2 , V_54 -> V_40 , V_54 -> V_58 ,
& V_54 -> V_4 , V_54 -> V_43 ) ;
F_30 ( & V_54 -> V_59 , & V_60 [ V_55 ] ) ;
} else {
V_55 = F_26 ( V_54 -> V_2 , V_54 -> V_52 ) ;
F_30 ( & V_54 -> V_61 , & V_62 [ V_55 ] ) ;
}
V_54 -> V_12 |= V_56 ;
F_31 ( & V_54 -> V_63 ) ;
return 1 ;
}
static int F_32 ( struct V_53 * V_54 )
{
if ( ! ( V_54 -> V_12 & V_56 ) ) {
F_28 ( L_2 ,
V_57 , F_29 ( 0 ) ) ;
return 0 ;
}
if ( V_54 -> V_52 == 0 ) {
F_33 ( & V_54 -> V_59 ) ;
} else {
F_33 ( & V_54 -> V_61 ) ;
}
V_54 -> V_12 &= ~ V_56 ;
F_34 ( & V_54 -> V_63 ) ;
return 1 ;
}
static inline struct V_53 *
F_35 ( struct V_2 * V_2 , int V_40 , T_4 V_58 ,
const union V_42 * V_64 , T_1 V_65 )
{
unsigned int V_55 ;
struct V_53 * V_54 ;
V_55 = F_22 ( V_2 , V_40 , V_58 , V_64 , V_65 ) ;
F_36 (svc, &ip_vs_svc_table[hash], s_list) {
if ( ( V_54 -> V_40 == V_40 )
&& F_37 ( V_40 , & V_54 -> V_4 , V_64 )
&& ( V_54 -> V_43 == V_65 )
&& ( V_54 -> V_58 == V_58 )
&& F_38 ( V_54 -> V_2 , V_2 ) ) {
return V_54 ;
}
}
return NULL ;
}
static inline struct V_53 *
F_39 ( struct V_2 * V_2 , int V_40 , T_3 V_52 )
{
unsigned int V_55 ;
struct V_53 * V_54 ;
V_55 = F_26 ( V_2 , V_52 ) ;
F_36 (svc, &ip_vs_svc_fwm_table[hash], f_list) {
if ( V_54 -> V_52 == V_52 && V_54 -> V_40 == V_40
&& F_38 ( V_54 -> V_2 , V_2 ) ) {
return V_54 ;
}
}
return NULL ;
}
struct V_53 *
F_40 ( struct V_2 * V_2 , int V_40 , T_3 V_52 , T_4 V_58 ,
const union V_42 * V_64 , T_1 V_65 )
{
struct V_53 * V_54 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_42 ( & V_66 ) ;
if ( V_52 ) {
V_54 = F_39 ( V_2 , V_40 , V_52 ) ;
if ( V_54 )
goto V_67;
}
V_54 = F_35 ( V_2 , V_40 , V_58 , V_64 , V_65 ) ;
if ( V_54 == NULL
&& V_58 == V_68
&& F_15 ( & V_15 -> V_69 )
&& ( V_65 == V_70 || F_23 ( V_65 ) >= V_71 ) ) {
V_54 = F_35 ( V_2 , V_40 , V_58 , V_64 , V_72 ) ;
}
if ( V_54 == NULL
&& F_15 ( & V_15 -> V_73 ) ) {
V_54 = F_35 ( V_2 , V_40 , V_58 , V_64 , 0 ) ;
}
V_67:
if ( V_54 )
F_31 ( & V_54 -> V_74 ) ;
F_43 ( & V_66 ) ;
F_44 ( 9 , L_3 ,
V_52 , F_45 ( V_58 ) ,
F_46 ( V_40 , V_64 ) , F_23 ( V_65 ) ,
V_54 ? L_4 : L_5 ) ;
return V_54 ;
}
static inline void
F_47 ( struct V_75 * V_76 , struct V_53 * V_54 )
{
F_31 ( & V_54 -> V_63 ) ;
V_76 -> V_54 = V_54 ;
}
static void
F_48 ( struct V_75 * V_76 )
{
struct V_53 * V_54 = V_76 -> V_54 ;
V_76 -> V_54 = NULL ;
if ( F_49 ( & V_54 -> V_63 ) ) {
F_44 ( 3 , L_6 ,
V_54 -> V_52 ,
F_46 ( V_54 -> V_40 , & V_54 -> V_4 ) ,
F_23 ( V_54 -> V_43 ) , F_15 ( & V_54 -> V_74 ) ) ;
F_50 ( V_54 -> V_77 . V_78 ) ;
F_51 ( V_54 ) ;
}
}
static inline unsigned int F_52 ( int V_40 ,
const union V_42 * V_4 ,
T_1 V_43 )
{
register unsigned int V_44 = F_23 ( V_43 ) ;
T_2 V_45 = V_4 -> V_46 ;
#ifdef F_24
if ( V_40 == V_47 )
V_45 = V_4 -> V_48 [ 0 ] ^ V_4 -> V_48 [ 1 ] ^
V_4 -> V_48 [ 2 ] ^ V_4 -> V_48 [ 3 ] ;
#endif
return ( F_25 ( V_45 ) ^ ( V_44 >> V_79 ) ^ V_44 )
& V_80 ;
}
static int F_53 ( struct V_14 * V_15 , struct V_75 * V_76 )
{
unsigned int V_55 ;
if ( ! F_54 ( & V_76 -> V_81 ) ) {
return 0 ;
}
V_55 = F_52 ( V_76 -> V_40 , & V_76 -> V_4 , V_76 -> V_43 ) ;
F_30 ( & V_76 -> V_81 , & V_15 -> V_82 [ V_55 ] ) ;
return 1 ;
}
static int F_55 ( struct V_75 * V_76 )
{
if ( ! F_54 ( & V_76 -> V_81 ) ) {
F_56 ( & V_76 -> V_81 ) ;
}
return 1 ;
}
struct V_75 *
F_57 ( struct V_2 * V_2 , int V_40 , T_4 V_58 ,
const union V_42 * V_7 ,
T_1 V_83 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
unsigned int V_55 ;
struct V_75 * V_76 ;
V_55 = F_52 ( V_40 , V_7 , V_83 ) ;
F_42 ( & V_15 -> V_84 ) ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( ( V_76 -> V_40 == V_40 )
&& F_37 ( V_40 , & V_76 -> V_4 , V_7 )
&& ( V_76 -> V_43 == V_83 )
&& ( ( V_76 -> V_58 == V_58 ) ||
V_76 -> V_85 ) ) {
F_43 ( & V_15 -> V_84 ) ;
return V_76 ;
}
}
F_43 ( & V_15 -> V_84 ) ;
return NULL ;
}
static struct V_75 *
F_58 ( struct V_53 * V_54 , const union V_42 * V_7 ,
T_1 V_83 )
{
struct V_75 * V_76 ;
F_36 (dest, &svc->destinations, n_list) {
if ( ( V_76 -> V_40 == V_54 -> V_40 )
&& F_37 ( V_54 -> V_40 , & V_76 -> V_4 , V_7 )
&& ( V_76 -> V_43 == V_83 ) ) {
return V_76 ;
}
}
return NULL ;
}
struct V_75 * F_59 ( struct V_2 * V_2 , int V_40 ,
const union V_42 * V_7 ,
T_1 V_83 ,
const union V_42 * V_64 ,
T_1 V_65 , T_4 V_58 , T_3 V_52 ,
T_3 V_12 )
{
struct V_75 * V_76 ;
struct V_53 * V_54 ;
T_1 V_43 = V_83 ;
V_54 = F_40 ( V_2 , V_40 , V_52 , V_58 , V_64 , V_65 ) ;
if ( ! V_54 )
return NULL ;
if ( V_52 && ( V_12 & V_86 ) != V_87 )
V_43 = 0 ;
V_76 = F_58 ( V_54 , V_7 , V_43 ) ;
if ( ! V_76 )
V_76 = F_58 ( V_54 , V_7 , V_43 ^ V_83 ) ;
if ( V_76 )
F_31 ( & V_76 -> V_63 ) ;
F_60 ( V_54 ) ;
return V_76 ;
}
static struct V_75 *
F_61 ( struct V_53 * V_54 , const union V_42 * V_7 ,
T_1 V_83 )
{
struct V_75 * V_76 , * V_88 ;
struct V_14 * V_15 = F_41 ( V_54 -> V_2 ) ;
F_62 (dest, nxt, &ipvs->dest_trash, n_list) {
F_44 ( 3 , L_7
L_8 ,
V_76 -> V_85 ,
F_46 ( V_54 -> V_40 , & V_76 -> V_4 ) ,
F_23 ( V_76 -> V_43 ) ,
F_15 ( & V_76 -> V_63 ) ) ;
if ( V_76 -> V_40 == V_54 -> V_40 &&
F_37 ( V_54 -> V_40 , & V_76 -> V_4 , V_7 ) &&
V_76 -> V_43 == V_83 &&
V_76 -> V_85 == V_54 -> V_52 &&
V_76 -> V_58 == V_54 -> V_58 &&
( V_54 -> V_52 ||
( F_37 ( V_54 -> V_40 , & V_76 -> V_64 , & V_54 -> V_4 ) &&
V_76 -> V_65 == V_54 -> V_43 ) ) ) {
return V_76 ;
}
if ( F_15 ( & V_76 -> V_63 ) == 1 ) {
F_44 ( 3 , L_9
L_10 ,
V_76 -> V_85 ,
F_46 ( V_54 -> V_40 , & V_76 -> V_4 ) ,
F_23 ( V_76 -> V_43 ) ) ;
F_33 ( & V_76 -> V_89 ) ;
F_63 ( V_76 ) ;
F_48 ( V_76 ) ;
F_50 ( V_76 -> V_77 . V_78 ) ;
F_51 ( V_76 ) ;
}
}
return NULL ;
}
static void F_64 ( struct V_2 * V_2 )
{
struct V_75 * V_76 , * V_88 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_62 (dest, nxt, &ipvs->dest_trash, n_list) {
F_33 ( & V_76 -> V_89 ) ;
F_63 ( V_76 ) ;
F_48 ( V_76 ) ;
F_50 ( V_76 -> V_77 . V_78 ) ;
F_51 ( V_76 ) ;
}
}
static void
F_65 ( struct V_90 * V_9 , struct V_91 * V_92 )
{
#define F_66 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_67 ( & V_92 -> V_93 ) ;
F_66 ( V_94 ) ;
F_66 ( V_95 ) ;
F_66 ( V_96 ) ;
F_66 ( V_97 ) ;
F_66 ( V_98 ) ;
F_68 ( V_9 , V_92 ) ;
F_69 ( & V_92 -> V_93 ) ;
}
static void
F_70 ( struct V_91 * V_77 )
{
F_67 ( & V_77 -> V_93 ) ;
#define F_71 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_71 ( V_94 ) ;
F_71 ( V_95 ) ;
F_71 ( V_96 ) ;
F_71 ( V_97 ) ;
F_71 ( V_98 ) ;
F_72 ( V_77 ) ;
F_69 ( & V_77 -> V_93 ) ;
}
static void
F_73 ( struct V_53 * V_54 , struct V_75 * V_76 ,
struct V_99 * V_100 , int V_101 )
{
struct V_14 * V_15 = F_41 ( V_54 -> V_2 ) ;
int V_102 ;
F_9 ( & V_76 -> V_103 , V_100 -> V_103 ) ;
V_102 = V_100 -> V_102 & V_104 ;
V_102 |= V_105 ;
if ( ( V_102 & V_86 ) != V_87 ) {
V_102 |= V_106 ;
} else {
F_74 ( & V_15 -> V_84 ) ;
F_53 ( V_15 , V_76 ) ;
F_75 ( & V_15 -> V_84 ) ;
}
F_9 ( & V_76 -> V_102 , V_102 ) ;
if ( ! V_76 -> V_54 ) {
F_47 ( V_76 , V_54 ) ;
} else {
if ( V_76 -> V_54 != V_54 ) {
F_48 ( V_76 ) ;
F_70 ( & V_76 -> V_77 ) ;
F_47 ( V_76 , V_54 ) ;
}
}
V_76 -> V_12 |= V_107 ;
if ( V_100 -> V_108 == 0 || V_100 -> V_108 > V_76 -> V_108 )
V_76 -> V_12 &= ~ V_109 ;
V_76 -> V_108 = V_100 -> V_108 ;
V_76 -> V_110 = V_100 -> V_110 ;
F_67 ( & V_76 -> V_111 ) ;
F_63 ( V_76 ) ;
F_69 ( & V_76 -> V_111 ) ;
if ( V_101 )
F_76 ( V_54 -> V_2 , & V_76 -> V_77 ) ;
F_74 ( & V_66 ) ;
F_77 ( F_15 ( & V_54 -> V_74 ) > 0 ) ;
if ( V_101 ) {
F_30 ( & V_76 -> V_89 , & V_54 -> V_112 ) ;
V_54 -> V_113 ++ ;
}
if ( V_54 -> V_114 -> V_115 )
V_54 -> V_114 -> V_115 ( V_54 ) ;
F_75 ( & V_66 ) ;
}
static int
F_78 ( struct V_53 * V_54 , struct V_99 * V_100 ,
struct V_75 * * V_116 )
{
struct V_75 * V_76 ;
unsigned int V_117 ;
F_79 ( 2 ) ;
#ifdef F_24
if ( V_54 -> V_40 == V_47 ) {
V_117 = F_80 ( & V_100 -> V_4 . V_118 ) ;
if ( ( ! ( V_117 & V_119 ) ||
V_117 & V_120 ) &&
! F_2 ( V_54 -> V_2 , & V_100 -> V_4 . V_118 ) )
return - V_121 ;
} else
#endif
{
V_117 = F_81 ( V_54 -> V_2 , V_100 -> V_4 . V_46 ) ;
if ( V_117 != V_122 && V_117 != V_123 )
return - V_121 ;
}
V_76 = F_82 ( sizeof( struct V_75 ) , V_124 ) ;
if ( V_76 == NULL )
return - V_125 ;
V_76 -> V_77 . V_78 = F_83 ( struct V_126 ) ;
if ( ! V_76 -> V_77 . V_78 )
goto V_127;
V_76 -> V_40 = V_54 -> V_40 ;
V_76 -> V_58 = V_54 -> V_58 ;
V_76 -> V_64 = V_54 -> V_4 ;
V_76 -> V_65 = V_54 -> V_43 ;
V_76 -> V_85 = V_54 -> V_52 ;
F_84 ( V_54 -> V_40 , & V_76 -> V_4 , & V_100 -> V_4 ) ;
V_76 -> V_43 = V_100 -> V_43 ;
F_9 ( & V_76 -> V_128 , 0 ) ;
F_9 ( & V_76 -> V_129 , 0 ) ;
F_9 ( & V_76 -> V_130 , 0 ) ;
F_9 ( & V_76 -> V_63 , 1 ) ;
F_85 ( & V_76 -> V_81 ) ;
F_86 ( & V_76 -> V_111 ) ;
F_86 ( & V_76 -> V_77 . V_93 ) ;
F_73 ( V_54 , V_76 , V_100 , 1 ) ;
* V_116 = V_76 ;
F_87 ( 2 ) ;
return 0 ;
V_127:
F_51 ( V_76 ) ;
return - V_125 ;
}
static int
F_88 ( struct V_53 * V_54 , struct V_99 * V_100 )
{
struct V_75 * V_76 ;
union V_42 V_7 ;
T_1 V_83 = V_100 -> V_43 ;
int V_131 ;
F_79 ( 2 ) ;
if ( V_100 -> V_103 < 0 ) {
F_28 ( L_11 , V_57 ) ;
return - V_132 ;
}
if ( V_100 -> V_110 > V_100 -> V_108 ) {
F_28 ( L_12 ,
V_57 ) ;
return - V_132 ;
}
F_84 ( V_54 -> V_40 , & V_7 , & V_100 -> V_4 ) ;
V_76 = F_58 ( V_54 , & V_7 , V_83 ) ;
if ( V_76 != NULL ) {
F_89 ( 1 , L_13 , V_57 ) ;
return - V_133 ;
}
V_76 = F_61 ( V_54 , & V_7 , V_83 ) ;
if ( V_76 != NULL ) {
F_44 ( 3 , L_14
L_15 ,
F_46 ( V_54 -> V_40 , & V_7 ) , F_23 ( V_83 ) ,
F_15 ( & V_76 -> V_63 ) ,
V_76 -> V_85 ,
F_46 ( V_54 -> V_40 , & V_76 -> V_64 ) ,
F_23 ( V_76 -> V_65 ) ) ;
F_33 ( & V_76 -> V_89 ) ;
F_73 ( V_54 , V_76 , V_100 , 1 ) ;
V_131 = 0 ;
} else {
V_131 = F_78 ( V_54 , V_100 , & V_76 ) ;
}
F_87 ( 2 ) ;
return V_131 ;
}
static int
F_90 ( struct V_53 * V_54 , struct V_99 * V_100 )
{
struct V_75 * V_76 ;
union V_42 V_7 ;
T_1 V_83 = V_100 -> V_43 ;
F_79 ( 2 ) ;
if ( V_100 -> V_103 < 0 ) {
F_28 ( L_11 , V_57 ) ;
return - V_132 ;
}
if ( V_100 -> V_110 > V_100 -> V_108 ) {
F_28 ( L_12 ,
V_57 ) ;
return - V_132 ;
}
F_84 ( V_54 -> V_40 , & V_7 , & V_100 -> V_4 ) ;
V_76 = F_58 ( V_54 , & V_7 , V_83 ) ;
if ( V_76 == NULL ) {
F_89 ( 1 , L_16 , V_57 ) ;
return - V_134 ;
}
F_73 ( V_54 , V_76 , V_100 , 0 ) ;
F_87 ( 2 ) ;
return 0 ;
}
static void F_91 ( struct V_2 * V_2 , struct V_75 * V_76 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_92 ( V_2 , & V_76 -> V_77 ) ;
F_74 ( & V_15 -> V_84 ) ;
F_55 ( V_76 ) ;
F_75 ( & V_15 -> V_84 ) ;
if ( F_49 ( & V_76 -> V_63 ) ) {
F_44 ( 3 , L_17 ,
V_76 -> V_85 ,
F_46 ( V_76 -> V_40 , & V_76 -> V_4 ) ,
F_23 ( V_76 -> V_43 ) ) ;
F_63 ( V_76 ) ;
F_34 ( & V_76 -> V_54 -> V_63 ) ;
F_50 ( V_76 -> V_77 . V_78 ) ;
F_51 ( V_76 ) ;
} else {
F_44 ( 3 , L_18
L_8 ,
F_46 ( V_76 -> V_40 , & V_76 -> V_4 ) ,
F_23 ( V_76 -> V_43 ) ,
F_15 ( & V_76 -> V_63 ) ) ;
F_30 ( & V_76 -> V_89 , & V_15 -> V_135 ) ;
F_31 ( & V_76 -> V_63 ) ;
}
}
static void F_93 ( struct V_53 * V_54 ,
struct V_75 * V_76 ,
int V_136 )
{
V_76 -> V_12 &= ~ V_107 ;
F_33 ( & V_76 -> V_89 ) ;
V_54 -> V_113 -- ;
if ( V_136 && V_54 -> V_114 -> V_115 )
V_54 -> V_114 -> V_115 ( V_54 ) ;
}
static int
F_94 ( struct V_53 * V_54 , struct V_99 * V_100 )
{
struct V_75 * V_76 ;
T_1 V_83 = V_100 -> V_43 ;
F_79 ( 2 ) ;
V_76 = F_58 ( V_54 , & V_100 -> V_4 , V_83 ) ;
if ( V_76 == NULL ) {
F_89 ( 1 , L_19 , V_57 ) ;
return - V_134 ;
}
F_74 ( & V_66 ) ;
F_77 ( F_15 ( & V_54 -> V_74 ) > 0 ) ;
F_93 ( V_54 , V_76 , 1 ) ;
F_75 ( & V_66 ) ;
F_91 ( V_54 -> V_2 , V_76 ) ;
F_87 ( 2 ) ;
return 0 ;
}
static int
F_95 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_53 * * V_139 )
{
int V_131 = 0 ;
struct V_140 * V_141 = NULL ;
struct V_142 * V_143 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_18 () ;
V_141 = F_96 ( V_138 -> V_144 ) ;
if ( V_141 == NULL ) {
F_97 ( L_20 , V_138 -> V_144 ) ;
V_131 = - V_134 ;
goto V_145;
}
if ( V_138 -> V_146 && * V_138 -> V_146 ) {
V_143 = F_98 ( V_138 -> V_146 ) ;
if ( V_143 == NULL ) {
F_97 ( L_21
L_22 , V_138 -> V_146 ) ;
V_131 = - V_134 ;
goto V_145;
}
}
#ifdef F_24
if ( V_138 -> V_40 == V_47 && ( V_138 -> V_147 < 1 || V_138 -> V_147 > 128 ) ) {
V_131 = - V_121 ;
goto V_145;
}
#endif
V_54 = F_82 ( sizeof( struct V_53 ) , V_124 ) ;
if ( V_54 == NULL ) {
F_89 ( 1 , L_23 , V_57 ) ;
V_131 = - V_125 ;
goto V_145;
}
V_54 -> V_77 . V_78 = F_83 ( struct V_126 ) ;
if ( ! V_54 -> V_77 . V_78 ) {
V_131 = - V_125 ;
goto V_145;
}
F_9 ( & V_54 -> V_74 , 0 ) ;
F_9 ( & V_54 -> V_63 , 0 ) ;
V_54 -> V_40 = V_138 -> V_40 ;
V_54 -> V_58 = V_138 -> V_58 ;
F_84 ( V_54 -> V_40 , & V_54 -> V_4 , & V_138 -> V_4 ) ;
V_54 -> V_43 = V_138 -> V_43 ;
V_54 -> V_52 = V_138 -> V_52 ;
V_54 -> V_12 = V_138 -> V_12 ;
V_54 -> V_148 = V_138 -> V_148 * V_149 ;
V_54 -> V_147 = V_138 -> V_147 ;
V_54 -> V_2 = V_2 ;
F_85 ( & V_54 -> V_112 ) ;
F_99 ( & V_54 -> V_150 ) ;
F_86 ( & V_54 -> V_77 . V_93 ) ;
V_131 = F_100 ( V_54 , V_141 ) ;
if ( V_131 )
goto V_145;
V_141 = NULL ;
F_101 ( V_54 , V_143 ) ;
V_143 = NULL ;
if ( V_54 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_54 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_76 ( V_2 , & V_54 -> V_77 ) ;
if ( V_54 -> V_40 == V_151 )
V_15 -> V_152 ++ ;
F_74 ( & V_66 ) ;
F_27 ( V_54 ) ;
F_75 ( & V_66 ) ;
* V_139 = V_54 ;
V_15 -> V_153 = 1 ;
return 0 ;
V_145:
if ( V_54 != NULL ) {
F_102 ( V_54 ) ;
if ( V_54 -> V_154 ) {
F_7 () ;
F_103 ( V_54 -> V_154 ) ;
F_12 () ;
}
if ( V_54 -> V_77 . V_78 )
F_50 ( V_54 -> V_77 . V_78 ) ;
F_51 ( V_54 ) ;
}
F_104 ( V_141 ) ;
F_105 ( V_143 ) ;
F_20 () ;
return V_131 ;
}
static int
F_106 ( struct V_53 * V_54 , struct V_137 * V_138 )
{
struct V_140 * V_141 , * V_155 ;
struct V_142 * V_143 = NULL , * V_156 = NULL ;
int V_131 = 0 ;
V_141 = F_96 ( V_138 -> V_144 ) ;
if ( V_141 == NULL ) {
F_97 ( L_20 , V_138 -> V_144 ) ;
return - V_134 ;
}
V_155 = V_141 ;
if ( V_138 -> V_146 && * V_138 -> V_146 ) {
V_143 = F_98 ( V_138 -> V_146 ) ;
if ( V_143 == NULL ) {
F_97 ( L_21
L_22 , V_138 -> V_146 ) ;
V_131 = - V_134 ;
goto V_67;
}
V_156 = V_143 ;
}
#ifdef F_24
if ( V_138 -> V_40 == V_47 && ( V_138 -> V_147 < 1 || V_138 -> V_147 > 128 ) ) {
V_131 = - V_121 ;
goto V_67;
}
#endif
F_74 ( & V_66 ) ;
F_77 ( F_15 ( & V_54 -> V_74 ) > 0 ) ;
V_54 -> V_12 = V_138 -> V_12 | V_56 ;
V_54 -> V_148 = V_138 -> V_148 * V_149 ;
V_54 -> V_147 = V_138 -> V_147 ;
V_155 = V_54 -> V_114 ;
if ( V_141 != V_155 ) {
if ( ( V_131 = F_102 ( V_54 ) ) ) {
V_155 = V_141 ;
goto V_157;
}
if ( ( V_131 = F_100 ( V_54 , V_141 ) ) ) {
F_100 ( V_54 , V_155 ) ;
V_155 = V_141 ;
goto V_157;
}
}
V_156 = V_54 -> V_143 ;
if ( V_143 != V_156 ) {
F_107 ( V_54 ) ;
F_101 ( V_54 , V_143 ) ;
}
V_157:
F_75 ( & V_66 ) ;
V_67:
F_104 ( V_155 ) ;
F_105 ( V_156 ) ;
return V_131 ;
}
static void F_108 ( struct V_53 * V_54 )
{
struct V_75 * V_76 , * V_88 ;
struct V_140 * V_155 ;
struct V_142 * V_156 ;
struct V_14 * V_15 = F_41 ( V_54 -> V_2 ) ;
F_97 ( L_24 , V_57 ) ;
if ( V_54 -> V_40 == V_151 )
V_15 -> V_152 -- ;
F_92 ( V_54 -> V_2 , & V_54 -> V_77 ) ;
V_155 = V_54 -> V_114 ;
F_102 ( V_54 ) ;
F_104 ( V_155 ) ;
V_156 = V_54 -> V_143 ;
F_107 ( V_54 ) ;
F_105 ( V_156 ) ;
if ( V_54 -> V_154 ) {
F_103 ( V_54 -> V_154 ) ;
V_54 -> V_154 = NULL ;
}
F_62 (dest, nxt, &svc->destinations, n_list) {
F_93 ( V_54 , V_76 , 0 ) ;
F_91 ( V_54 -> V_2 , V_76 ) ;
}
if ( V_54 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_54 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
if ( F_15 ( & V_54 -> V_63 ) == 0 ) {
F_44 ( 3 , L_6 ,
V_54 -> V_52 ,
F_46 ( V_54 -> V_40 , & V_54 -> V_4 ) ,
F_23 ( V_54 -> V_43 ) , F_15 ( & V_54 -> V_74 ) ) ;
F_50 ( V_54 -> V_77 . V_78 ) ;
F_51 ( V_54 ) ;
}
F_20 () ;
}
static void F_109 ( struct V_53 * V_54 )
{
F_74 ( & V_66 ) ;
F_32 ( V_54 ) ;
F_77 ( F_15 ( & V_54 -> V_74 ) > 0 ) ;
F_108 ( V_54 ) ;
F_75 ( & V_66 ) ;
}
static int F_110 ( struct V_53 * V_54 )
{
if ( V_54 == NULL )
return - V_133 ;
F_109 ( V_54 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_53 * V_54 , * V_88 ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_62 (svc, nxt, &ip_vs_svc_table[idx],
s_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) )
F_109 ( V_54 ) ;
}
}
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_62 (svc, nxt,
&ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) )
F_109 ( V_54 ) ;
}
}
return 0 ;
}
void F_112 ( struct V_2 * V_2 )
{
F_79 ( 2 ) ;
F_113 ( & V_160 ) ;
F_111 ( V_2 ) ;
F_114 ( & V_160 ) ;
F_87 ( 2 ) ;
}
static inline void
F_115 ( struct V_75 * V_76 , struct V_161 * V_11 )
{
F_67 ( & V_76 -> V_111 ) ;
if ( V_76 -> V_162 && V_76 -> V_162 -> V_11 == V_11 ) {
F_44 ( 3 , L_25 ,
V_11 -> V_163 ,
F_46 ( V_76 -> V_40 , & V_76 -> V_4 ) ,
F_23 ( V_76 -> V_43 ) ,
F_15 ( & V_76 -> V_63 ) ) ;
F_63 ( V_76 ) ;
}
F_69 ( & V_76 -> V_111 ) ;
}
static int F_116 ( struct V_164 * V_165 , unsigned long V_166 ,
void * V_167 )
{
struct V_161 * V_11 = V_167 ;
struct V_2 * V_2 = F_117 ( V_11 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_53 * V_54 ;
struct V_75 * V_76 ;
unsigned int V_158 ;
if ( V_166 != V_168 || ! V_15 )
return V_169 ;
F_89 ( 3 , L_26 , V_57 , V_11 -> V_163 ) ;
F_79 ( 2 ) ;
F_113 ( & V_160 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) ) {
F_36 (dest, &svc->destinations,
n_list) {
F_115 ( V_76 , V_11 ) ;
}
}
}
F_36 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) ) {
F_36 (dest, &svc->destinations,
n_list) {
F_115 ( V_76 , V_11 ) ;
}
}
}
}
F_36 (dest, &ipvs->dest_trash, n_list) {
F_115 ( V_76 , V_11 ) ;
}
F_114 ( & V_160 ) ;
F_87 ( 2 ) ;
return V_169 ;
}
static int F_118 ( struct V_53 * V_54 )
{
struct V_75 * V_76 ;
F_74 ( & V_66 ) ;
F_36 (dest, &svc->destinations, n_list) {
F_70 ( & V_76 -> V_77 ) ;
}
F_70 ( & V_54 -> V_77 ) ;
F_75 ( & V_66 ) ;
return 0 ;
}
static int F_119 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_53 * V_54 ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) )
F_118 ( V_54 ) ;
}
}
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) )
F_118 ( V_54 ) ;
}
}
F_70 ( & F_41 ( V_2 ) -> V_170 ) ;
return 0 ;
}
static int
F_120 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
struct V_2 * V_2 = V_176 -> V_177 -> V_178 ;
int * V_179 = V_171 -> V_180 ;
int V_181 = * V_179 ;
int V_182 ;
V_182 = F_121 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( * V_179 != V_181 ) ) {
if ( ( * V_179 < 0 ) || ( * V_179 > 3 ) ) {
* V_179 = V_181 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_182 ;
}
static int
F_122 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
int * V_179 = V_171 -> V_180 ;
int V_181 [ 2 ] ;
int V_182 ;
memcpy ( V_181 , V_179 , sizeof( V_181 ) ) ;
V_182 = F_121 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( V_179 [ 0 ] < 0 || V_179 [ 1 ] < 0 ||
( V_179 [ 0 ] >= V_179 [ 1 ] && V_179 [ 1 ] ) ) ) {
memcpy ( V_179 , V_181 , sizeof( V_181 ) ) ;
}
return V_182 ;
}
static int
F_123 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
int * V_179 = V_171 -> V_180 ;
int V_181 = * V_179 ;
int V_182 ;
V_182 = F_121 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( * V_179 != V_181 ) ) {
if ( ( * V_179 < 0 ) || ( * V_179 > 1 ) ) {
* V_179 = V_181 ;
}
}
return V_182 ;
}
static int
F_124 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
int * V_179 = V_171 -> V_180 ;
int V_181 = * V_179 ;
int V_182 ;
V_182 = F_121 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( * V_179 != V_181 ) ) {
if ( * V_179 < 1 || ! F_125 ( * V_179 ) ) {
* V_179 = V_181 ;
}
}
return V_182 ;
}
static inline const char * F_126 ( unsigned int V_12 )
{
switch ( V_12 & V_86 ) {
case V_183 :
return L_27 ;
case V_184 :
return L_28 ;
case V_185 :
return L_29 ;
default:
return L_30 ;
}
}
static struct V_53 * F_127 ( struct V_186 * V_187 , T_8 V_188 )
{
struct V_2 * V_2 = F_128 ( V_187 ) ;
struct V_189 * V_190 = V_187 -> V_191 ;
int V_158 ;
struct V_53 * V_54 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) && V_188 -- == 0 ) {
V_190 -> V_171 = V_60 ;
V_190 -> V_192 = V_158 ;
return V_54 ;
}
}
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_54 -> V_2 , V_2 ) && V_188 -- == 0 ) {
V_190 -> V_171 = V_62 ;
V_190 -> V_192 = V_158 ;
return V_54 ;
}
}
}
return NULL ;
}
static void * F_129 ( struct V_186 * V_187 , T_8 * V_188 )
__acquires( V_66 )
{
F_130 ( & V_66 ) ;
return * V_188 ? F_127 ( V_187 , * V_188 - 1 ) : V_193 ;
}
static void * F_131 ( struct V_186 * V_187 , void * V_194 , T_8 * V_188 )
{
struct V_195 * V_196 ;
struct V_189 * V_190 ;
struct V_53 * V_54 ;
++ * V_188 ;
if ( V_194 == V_193 )
return F_127 ( V_187 , 0 ) ;
V_54 = V_194 ;
V_190 = V_187 -> V_191 ;
if ( V_190 -> V_171 == V_60 ) {
if ( ( V_196 = V_54 -> V_59 . V_197 ) != & V_60 [ V_190 -> V_192 ] )
return F_132 ( V_196 , struct V_53 , V_59 ) ;
while ( ++ V_190 -> V_192 < V_159 ) {
F_36 (svc,&ip_vs_svc_table[iter->bucket],
s_list) {
return V_54 ;
}
}
V_190 -> V_171 = V_62 ;
V_190 -> V_192 = - 1 ;
goto V_198;
}
if ( ( V_196 = V_54 -> V_61 . V_197 ) != & V_62 [ V_190 -> V_192 ] )
return F_132 ( V_196 , struct V_53 , V_61 ) ;
V_198:
while ( ++ V_190 -> V_192 < V_159 ) {
F_36 (svc, &ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_54 ;
}
return NULL ;
}
static void F_133 ( struct V_186 * V_187 , void * V_194 )
__releases( V_66 )
{
F_134 ( & V_66 ) ;
}
static int F_135 ( struct V_186 * V_187 , void * V_194 )
{
if ( V_194 == V_193 ) {
F_136 ( V_187 ,
L_31 ,
F_137 ( V_199 ) , V_200 ) ;
F_138 ( V_187 ,
L_32 ) ;
F_138 ( V_187 ,
L_33 ) ;
} else {
const struct V_53 * V_54 = V_194 ;
const struct V_189 * V_190 = V_187 -> V_191 ;
const struct V_75 * V_76 ;
if ( V_190 -> V_171 == V_60 ) {
#ifdef F_24
if ( V_54 -> V_40 == V_47 )
F_136 ( V_187 , L_34 ,
F_45 ( V_54 -> V_58 ) ,
& V_54 -> V_4 . V_118 ,
F_23 ( V_54 -> V_43 ) ,
V_54 -> V_114 -> V_163 ) ;
else
#endif
F_136 ( V_187 , L_35 ,
F_45 ( V_54 -> V_58 ) ,
F_25 ( V_54 -> V_4 . V_46 ) ,
F_23 ( V_54 -> V_43 ) ,
V_54 -> V_114 -> V_163 ,
( V_54 -> V_12 & V_201 ) ? L_36 : L_37 ) ;
} else {
F_136 ( V_187 , L_38 ,
V_54 -> V_52 , V_54 -> V_114 -> V_163 ,
( V_54 -> V_12 & V_201 ) ? L_36 : L_37 ) ;
}
if ( V_54 -> V_12 & V_202 )
F_136 ( V_187 , L_39 ,
V_54 -> V_148 ,
F_25 ( V_54 -> V_147 ) ) ;
else
F_139 ( V_187 , '\n' ) ;
F_36 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_76 -> V_40 == V_47 )
F_136 ( V_187 ,
L_40
L_41 ,
& V_76 -> V_4 . V_118 ,
F_23 ( V_76 -> V_43 ) ,
F_126 ( F_15 ( & V_76 -> V_102 ) ) ,
F_15 ( & V_76 -> V_103 ) ,
F_15 ( & V_76 -> V_128 ) ,
F_15 ( & V_76 -> V_129 ) ) ;
else
#endif
F_136 ( V_187 ,
L_42
L_43 ,
F_25 ( V_76 -> V_4 . V_46 ) ,
F_23 ( V_76 -> V_43 ) ,
F_126 ( F_15 ( & V_76 -> V_102 ) ) ,
F_15 ( & V_76 -> V_103 ) ,
F_15 ( & V_76 -> V_128 ) ,
F_15 ( & V_76 -> V_129 ) ) ;
}
}
return 0 ;
}
static int F_140 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_141 ( V_203 , V_204 , & V_205 ,
sizeof( struct V_189 ) ) ;
}
static int F_142 ( struct V_186 * V_187 , void * V_194 )
{
struct V_2 * V_2 = F_143 ( V_187 ) ;
struct V_90 V_206 ;
F_138 ( V_187 ,
L_44 ) ;
F_136 ( V_187 ,
L_45 ) ;
F_65 ( & V_206 , & F_41 ( V_2 ) -> V_170 ) ;
F_136 ( V_187 , L_46 , V_206 . V_94 ,
V_206 . V_95 , V_206 . V_96 ,
( unsigned long long ) V_206 . V_97 ,
( unsigned long long ) V_206 . V_98 ) ;
F_138 ( V_187 ,
L_47 ) ;
F_136 ( V_187 , L_48 ,
V_206 . V_207 , V_206 . V_208 , V_206 . V_209 ,
V_206 . V_210 , V_206 . V_211 ) ;
return 0 ;
}
static int F_144 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_145 ( V_203 , V_204 , F_142 ) ;
}
static int F_146 ( struct V_186 * V_187 , void * V_194 )
{
struct V_2 * V_2 = F_143 ( V_187 ) ;
struct V_91 * V_170 = & F_41 ( V_2 ) -> V_170 ;
struct V_126 * V_78 = V_170 -> V_78 ;
struct V_90 V_212 ;
int V_17 ;
F_138 ( V_187 ,
L_49 ) ;
F_136 ( V_187 ,
L_50 ) ;
F_147 (i) {
struct V_126 * V_138 = F_148 ( V_78 , V_17 ) ;
unsigned int V_213 ;
T_9 V_97 , V_98 ;
do {
V_213 = F_149 ( & V_138 -> V_214 ) ;
V_97 = V_138 -> V_215 . V_97 ;
V_98 = V_138 -> V_215 . V_98 ;
} while ( F_150 ( & V_138 -> V_214 , V_213 ) );
F_136 ( V_187 , L_51 ,
V_17 , V_138 -> V_215 . V_94 , V_138 -> V_215 . V_95 ,
V_138 -> V_215 . V_96 , ( T_9 ) V_97 ,
( T_9 ) V_98 ) ;
}
F_67 ( & V_170 -> V_93 ) ;
F_136 ( V_187 , L_52 ,
V_170 -> V_215 . V_94 , V_170 -> V_215 . V_95 ,
V_170 -> V_215 . V_96 ,
( unsigned long long ) V_170 -> V_215 . V_97 ,
( unsigned long long ) V_170 -> V_215 . V_98 ) ;
F_68 ( & V_212 , V_170 ) ;
F_69 ( & V_170 -> V_93 ) ;
F_138 ( V_187 ,
L_53 ) ;
F_136 ( V_187 , L_54 ,
V_212 . V_207 ,
V_212 . V_208 ,
V_212 . V_209 ,
V_212 . V_210 ,
V_212 . V_211 ) ;
return 0 ;
}
static int F_151 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_145 ( V_203 , V_204 , F_146 ) ;
}
static int F_152 ( struct V_2 * V_2 , struct V_216 * V_138 )
{
#if F_153 ( V_217 ) || F_153 ( V_218 )
struct V_219 * V_220 ;
#endif
F_89 ( 2 , L_55 ,
V_138 -> V_221 ,
V_138 -> V_222 ,
V_138 -> V_223 ) ;
#ifdef V_217
if ( V_138 -> V_221 ) {
V_220 = F_154 ( V_2 , V_68 ) ;
V_220 -> V_224 [ V_225 ]
= V_138 -> V_221 * V_149 ;
}
if ( V_138 -> V_222 ) {
V_220 = F_154 ( V_2 , V_68 ) ;
V_220 -> V_224 [ V_226 ]
= V_138 -> V_222 * V_149 ;
}
#endif
#ifdef V_218
if ( V_138 -> V_223 ) {
V_220 = F_154 ( V_2 , V_227 ) ;
V_220 -> V_224 [ V_228 ]
= V_138 -> V_223 * V_149 ;
}
#endif
return 0 ;
}
static void F_155 ( struct V_137 * V_229 ,
struct V_230 * V_231 )
{
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
V_229 -> V_40 = V_151 ;
V_229 -> V_58 = V_231 -> V_58 ;
V_229 -> V_4 . V_46 = V_231 -> V_4 ;
V_229 -> V_43 = V_231 -> V_43 ;
V_229 -> V_52 = V_231 -> V_52 ;
V_229 -> V_144 = V_231 -> V_144 ;
V_229 -> V_12 = V_231 -> V_12 ;
V_229 -> V_148 = V_231 -> V_148 ;
V_229 -> V_147 = V_231 -> V_147 ;
}
static void F_156 ( struct V_99 * V_100 ,
struct V_232 * V_233 )
{
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_4 . V_46 = V_233 -> V_4 ;
V_100 -> V_43 = V_233 -> V_43 ;
V_100 -> V_102 = V_233 -> V_102 ;
V_100 -> V_103 = V_233 -> V_103 ;
V_100 -> V_108 = V_233 -> V_108 ;
V_100 -> V_110 = V_233 -> V_110 ;
}
static int
F_157 ( struct V_234 * V_235 , int V_236 , void T_7 * V_237 , unsigned int V_238 )
{
struct V_2 * V_2 = F_158 ( V_235 ) ;
int V_131 ;
unsigned char V_239 [ V_240 ] ;
struct V_230 * V_231 ;
struct V_137 V_229 ;
struct V_53 * V_54 ;
struct V_232 * V_233 ;
struct V_99 V_100 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
if ( ! F_159 ( F_158 ( V_235 ) -> V_241 , V_242 ) )
return - V_243 ;
if ( V_236 < V_244 || V_236 > V_245 )
return - V_121 ;
if ( V_238 < 0 || V_238 > V_240 )
return - V_121 ;
if ( V_238 != V_246 [ F_160 ( V_236 ) ] ) {
F_28 ( L_56 ,
V_238 , V_246 [ F_160 ( V_236 ) ] ) ;
return - V_121 ;
}
if ( F_161 ( V_239 , V_237 , V_238 ) != 0 )
return - V_247 ;
F_18 () ;
if ( V_236 == V_248 ||
V_236 == V_249 ) {
struct V_250 * V_251 = (struct V_250 * ) V_239 ;
if ( F_162 ( & V_15 -> V_252 ) ) {
V_131 = - V_253 ;
goto V_254;
}
if ( V_236 == V_248 )
V_131 = F_163 ( V_2 , V_251 -> V_255 , V_251 -> V_256 ,
V_251 -> V_257 ) ;
else
V_131 = F_164 ( V_2 , V_251 -> V_255 ) ;
F_114 ( & V_15 -> V_252 ) ;
goto V_254;
}
if ( F_162 ( & V_160 ) ) {
V_131 = - V_253 ;
goto V_254;
}
if ( V_236 == V_258 ) {
V_131 = F_111 ( V_2 ) ;
goto V_157;
} else if ( V_236 == V_259 ) {
V_131 = F_152 ( V_2 , (struct V_216 * ) V_239 ) ;
goto V_157;
}
V_231 = (struct V_230 * ) V_239 ;
V_233 = (struct V_232 * ) ( V_231 + 1 ) ;
F_155 ( & V_229 , V_231 ) ;
F_156 ( & V_100 , V_233 ) ;
if ( V_236 == V_260 ) {
if ( ! V_229 . V_52 && ! V_229 . V_4 . V_46 && ! V_229 . V_43 ) {
V_131 = F_119 ( V_2 ) ;
goto V_157;
}
}
if ( V_229 . V_58 != V_68 && V_229 . V_58 != V_227 &&
V_229 . V_58 != V_261 ) {
F_28 ( L_57 ,
V_229 . V_58 , & V_229 . V_4 . V_46 ,
F_23 ( V_229 . V_43 ) , V_229 . V_144 ) ;
V_131 = - V_247 ;
goto V_157;
}
if ( V_229 . V_52 == 0 )
V_54 = F_35 ( V_2 , V_229 . V_40 , V_229 . V_58 ,
& V_229 . V_4 , V_229 . V_43 ) ;
else
V_54 = F_39 ( V_2 , V_229 . V_40 , V_229 . V_52 ) ;
if ( V_236 != V_262
&& ( V_54 == NULL || V_54 -> V_58 != V_229 . V_58 ) ) {
V_131 = - V_263 ;
goto V_157;
}
switch ( V_236 ) {
case V_262 :
if ( V_54 != NULL )
V_131 = - V_133 ;
else
V_131 = F_95 ( V_2 , & V_229 , & V_54 ) ;
break;
case V_264 :
V_131 = F_106 ( V_54 , & V_229 ) ;
break;
case V_265 :
V_131 = F_110 ( V_54 ) ;
if ( ! V_131 )
goto V_157;
break;
case V_260 :
V_131 = F_118 ( V_54 ) ;
break;
case V_266 :
V_131 = F_88 ( V_54 , & V_100 ) ;
break;
case V_267 :
V_131 = F_90 ( V_54 , & V_100 ) ;
break;
case V_268 :
V_131 = F_94 ( V_54 , & V_100 ) ;
break;
default:
V_131 = - V_121 ;
}
V_157:
F_114 ( & V_160 ) ;
V_254:
F_20 () ;
return V_131 ;
}
static void
F_165 ( struct V_269 * V_9 , struct V_53 * V_92 )
{
V_9 -> V_58 = V_92 -> V_58 ;
V_9 -> V_4 = V_92 -> V_4 . V_46 ;
V_9 -> V_43 = V_92 -> V_43 ;
V_9 -> V_52 = V_92 -> V_52 ;
F_166 ( V_9 -> V_144 , V_92 -> V_114 -> V_163 , sizeof( V_9 -> V_144 ) ) ;
V_9 -> V_12 = V_92 -> V_12 ;
V_9 -> V_148 = V_92 -> V_148 / V_149 ;
V_9 -> V_147 = V_92 -> V_147 ;
V_9 -> V_113 = V_92 -> V_113 ;
F_65 ( & V_9 -> V_77 , & V_92 -> V_77 ) ;
}
static inline int
F_167 ( struct V_2 * V_2 ,
const struct V_270 * V_271 ,
struct V_270 T_7 * V_272 )
{
int V_158 , V_273 = 0 ;
struct V_53 * V_54 ;
struct V_269 V_274 ;
int V_131 = 0 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_54 -> V_40 != V_151 || ! F_38 ( V_54 -> V_2 , V_2 ) )
continue;
if ( V_273 >= V_271 -> V_152 )
goto V_67;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
F_165 ( & V_274 , V_54 ) ;
if ( F_168 ( & V_272 -> V_275 [ V_273 ] ,
& V_274 , sizeof( V_274 ) ) ) {
V_131 = - V_247 ;
goto V_67;
}
V_273 ++ ;
}
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_54 -> V_40 != V_151 || ! F_38 ( V_54 -> V_2 , V_2 ) )
continue;
if ( V_273 >= V_271 -> V_152 )
goto V_67;
memset ( & V_274 , 0 , sizeof( V_274 ) ) ;
F_165 ( & V_274 , V_54 ) ;
if ( F_168 ( & V_272 -> V_275 [ V_273 ] ,
& V_274 , sizeof( V_274 ) ) ) {
V_131 = - V_247 ;
goto V_67;
}
V_273 ++ ;
}
}
V_67:
return V_131 ;
}
static inline int
F_169 ( struct V_2 * V_2 , const struct V_276 * V_271 ,
struct V_276 T_7 * V_272 )
{
struct V_53 * V_54 ;
union V_42 V_4 = { . V_46 = V_271 -> V_4 } ;
int V_131 = 0 ;
if ( V_271 -> V_52 )
V_54 = F_39 ( V_2 , V_151 , V_271 -> V_52 ) ;
else
V_54 = F_35 ( V_2 , V_151 , V_271 -> V_58 , & V_4 ,
V_271 -> V_43 ) ;
if ( V_54 ) {
int V_273 = 0 ;
struct V_75 * V_76 ;
struct V_277 V_274 ;
F_36 (dest, &svc->destinations, n_list) {
if ( V_273 >= V_271 -> V_113 )
break;
V_274 . V_4 = V_76 -> V_4 . V_46 ;
V_274 . V_43 = V_76 -> V_43 ;
V_274 . V_102 = F_15 ( & V_76 -> V_102 ) ;
V_274 . V_103 = F_15 ( & V_76 -> V_103 ) ;
V_274 . V_108 = V_76 -> V_108 ;
V_274 . V_110 = V_76 -> V_110 ;
V_274 . V_128 = F_15 ( & V_76 -> V_128 ) ;
V_274 . V_129 = F_15 ( & V_76 -> V_129 ) ;
V_274 . V_130 = F_15 ( & V_76 -> V_130 ) ;
F_65 ( & V_274 . V_77 , & V_76 -> V_77 ) ;
if ( F_168 ( & V_272 -> V_275 [ V_273 ] ,
& V_274 , sizeof( V_274 ) ) ) {
V_131 = - V_247 ;
break;
}
V_273 ++ ;
}
} else
V_131 = - V_263 ;
return V_131 ;
}
static inline void
F_170 ( struct V_2 * V_2 , struct V_216 * V_138 )
{
#if F_153 ( V_217 ) || F_153 ( V_218 )
struct V_219 * V_220 ;
#endif
memset ( V_138 , 0 , sizeof ( * V_138 ) ) ;
#ifdef V_217
V_220 = F_154 ( V_2 , V_68 ) ;
V_138 -> V_221 = V_220 -> V_224 [ V_225 ] / V_149 ;
V_138 -> V_222 = V_220 -> V_224 [ V_226 ] / V_149 ;
#endif
#ifdef V_218
V_220 = F_154 ( V_2 , V_227 ) ;
V_138 -> V_223 =
V_220 -> V_224 [ V_228 ] / V_149 ;
#endif
}
static int
F_171 ( struct V_234 * V_235 , int V_236 , void T_7 * V_237 , int * V_238 )
{
unsigned char V_239 [ 128 ] ;
int V_131 = 0 ;
unsigned int V_278 ;
struct V_2 * V_2 = F_158 ( V_235 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_172 ( ! V_2 ) ;
if ( ! F_159 ( F_158 ( V_235 ) -> V_241 , V_242 ) )
return - V_243 ;
if ( V_236 < V_244 || V_236 > V_279 )
return - V_121 ;
if ( * V_238 < V_280 [ F_173 ( V_236 ) ] ) {
F_28 ( L_58 ,
* V_238 , V_280 [ F_173 ( V_236 ) ] ) ;
return - V_121 ;
}
V_278 = V_280 [ F_173 ( V_236 ) ] ;
if ( V_278 > 128 )
return - V_121 ;
if ( F_161 ( V_239 , V_237 , V_278 ) != 0 )
return - V_247 ;
if ( V_236 == V_281 ) {
struct V_250 V_282 [ 2 ] ;
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
if ( F_162 ( & V_15 -> V_252 ) )
return - V_253 ;
if ( V_15 -> V_283 & V_284 ) {
V_282 [ 0 ] . V_255 = V_284 ;
F_166 ( V_282 [ 0 ] . V_256 , V_15 -> V_285 ,
sizeof( V_282 [ 0 ] . V_256 ) ) ;
V_282 [ 0 ] . V_257 = V_15 -> V_286 ;
}
if ( V_15 -> V_283 & V_287 ) {
V_282 [ 1 ] . V_255 = V_287 ;
F_166 ( V_282 [ 1 ] . V_256 , V_15 -> V_288 ,
sizeof( V_282 [ 1 ] . V_256 ) ) ;
V_282 [ 1 ] . V_257 = V_15 -> V_289 ;
}
if ( F_168 ( V_237 , & V_282 , sizeof( V_282 ) ) != 0 )
V_131 = - V_247 ;
F_114 ( & V_15 -> V_252 ) ;
return V_131 ;
}
if ( F_162 ( & V_160 ) )
return - V_253 ;
switch ( V_236 ) {
case V_290 :
{
char V_291 [ 64 ] ;
sprintf ( V_291 , L_59 ,
F_137 ( V_199 ) , V_200 ) ;
if ( F_168 ( V_237 , V_291 , strlen ( V_291 ) + 1 ) != 0 ) {
V_131 = - V_247 ;
goto V_67;
}
* V_238 = strlen ( V_291 ) + 1 ;
}
break;
case V_292 :
{
struct V_293 V_294 ;
V_294 . V_295 = V_199 ;
V_294 . V_296 = V_200 ;
V_294 . V_152 = V_15 -> V_152 ;
if ( F_168 ( V_237 , & V_294 , sizeof( V_294 ) ) != 0 )
V_131 = - V_247 ;
}
break;
case V_297 :
{
struct V_270 * V_271 ;
int V_296 ;
V_271 = (struct V_270 * ) V_239 ;
V_296 = sizeof( * V_271 ) +
sizeof( struct V_269 ) * V_271 -> V_152 ;
if ( * V_238 != V_296 ) {
F_28 ( L_60 , * V_238 , V_296 ) ;
V_131 = - V_121 ;
goto V_67;
}
V_131 = F_167 ( V_2 , V_271 , V_237 ) ;
}
break;
case V_298 :
{
struct V_269 * V_274 ;
struct V_53 * V_54 ;
union V_42 V_4 ;
V_274 = (struct V_269 * ) V_239 ;
V_4 . V_46 = V_274 -> V_4 ;
if ( V_274 -> V_52 )
V_54 = F_39 ( V_2 , V_151 , V_274 -> V_52 ) ;
else
V_54 = F_35 ( V_2 , V_151 ,
V_274 -> V_58 , & V_4 ,
V_274 -> V_43 ) ;
if ( V_54 ) {
F_165 ( V_274 , V_54 ) ;
if ( F_168 ( V_237 , V_274 , sizeof( * V_274 ) ) != 0 )
V_131 = - V_247 ;
} else
V_131 = - V_263 ;
}
break;
case V_299 :
{
struct V_276 * V_271 ;
int V_296 ;
V_271 = (struct V_276 * ) V_239 ;
V_296 = sizeof( * V_271 ) +
sizeof( struct V_277 ) * V_271 -> V_113 ;
if ( * V_238 != V_296 ) {
F_28 ( L_60 , * V_238 , V_296 ) ;
V_131 = - V_121 ;
goto V_67;
}
V_131 = F_169 ( V_2 , V_271 , V_237 ) ;
}
break;
case V_300 :
{
struct V_216 V_301 ;
F_170 ( V_2 , & V_301 ) ;
if ( F_168 ( V_237 , & V_301 , sizeof( V_301 ) ) != 0 )
V_131 = - V_247 ;
}
break;
default:
V_131 = - V_121 ;
}
V_67:
F_114 ( & V_160 ) ;
return V_131 ;
}
static int F_174 ( struct V_302 * V_303 , int V_304 ,
struct V_91 * V_77 )
{
struct V_90 V_215 ;
struct V_305 * V_306 = F_175 ( V_303 , V_304 ) ;
if ( ! V_306 )
return - V_307 ;
F_65 ( & V_215 , V_77 ) ;
if ( F_176 ( V_303 , V_308 , V_215 . V_94 ) ||
F_176 ( V_303 , V_309 , V_215 . V_95 ) ||
F_176 ( V_303 , V_310 , V_215 . V_96 ) ||
F_177 ( V_303 , V_311 , V_215 . V_97 ) ||
F_177 ( V_303 , V_312 , V_215 . V_98 ) ||
F_176 ( V_303 , V_313 , V_215 . V_207 ) ||
F_176 ( V_303 , V_314 , V_215 . V_208 ) ||
F_176 ( V_303 , V_315 , V_215 . V_209 ) ||
F_176 ( V_303 , V_316 , V_215 . V_210 ) ||
F_176 ( V_303 , V_317 , V_215 . V_211 ) )
goto V_318;
F_178 ( V_303 , V_306 ) ;
return 0 ;
V_318:
F_179 ( V_303 , V_306 ) ;
return - V_307 ;
}
static int F_180 ( struct V_302 * V_303 ,
struct V_53 * V_54 )
{
struct V_305 * V_319 ;
struct V_320 V_12 = { . V_12 = V_54 -> V_12 ,
. V_321 = ~ 0 } ;
V_319 = F_175 ( V_303 , V_322 ) ;
if ( ! V_319 )
return - V_307 ;
if ( F_181 ( V_303 , V_323 , V_54 -> V_40 ) )
goto V_318;
if ( V_54 -> V_52 ) {
if ( F_176 ( V_303 , V_324 , V_54 -> V_52 ) )
goto V_318;
} else {
if ( F_181 ( V_303 , V_325 , V_54 -> V_58 ) ||
F_182 ( V_303 , V_326 , sizeof( V_54 -> V_4 ) , & V_54 -> V_4 ) ||
F_181 ( V_303 , V_327 , V_54 -> V_43 ) )
goto V_318;
}
if ( F_183 ( V_303 , V_328 , V_54 -> V_114 -> V_163 ) ||
( V_54 -> V_143 &&
F_183 ( V_303 , V_329 , V_54 -> V_143 -> V_163 ) ) ||
F_182 ( V_303 , V_330 , sizeof( V_12 ) , & V_12 ) ||
F_176 ( V_303 , V_331 , V_54 -> V_148 / V_149 ) ||
F_176 ( V_303 , V_332 , V_54 -> V_147 ) )
goto V_318;
if ( F_174 ( V_303 , V_333 , & V_54 -> V_77 ) )
goto V_318;
F_178 ( V_303 , V_319 ) ;
return 0 ;
V_318:
F_179 ( V_303 , V_319 ) ;
return - V_307 ;
}
static int F_184 ( struct V_302 * V_303 ,
struct V_53 * V_54 ,
struct V_334 * V_335 )
{
void * V_336 ;
V_336 = F_185 ( V_303 , F_186 ( V_335 -> V_303 ) . V_337 , V_335 -> V_338 -> V_339 ,
& V_340 , V_341 ,
V_342 ) ;
if ( ! V_336 )
return - V_307 ;
if ( F_180 ( V_303 , V_54 ) < 0 )
goto V_318;
return F_187 ( V_303 , V_336 ) ;
V_318:
F_188 ( V_303 , V_336 ) ;
return - V_307 ;
}
static int F_189 ( struct V_302 * V_303 ,
struct V_334 * V_335 )
{
int V_158 = 0 , V_17 ;
int V_213 = V_335 -> args [ 0 ] ;
struct V_53 * V_54 ;
struct V_2 * V_2 = F_190 ( V_303 ) ;
F_113 ( & V_160 ) ;
for ( V_17 = 0 ; V_17 < V_159 ; V_17 ++ ) {
F_36 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_158 <= V_213 || ! F_38 ( V_54 -> V_2 , V_2 ) )
continue;
if ( F_184 ( V_303 , V_54 , V_335 ) < 0 ) {
V_158 -- ;
goto V_318;
}
}
}
for ( V_17 = 0 ; V_17 < V_159 ; V_17 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_158 <= V_213 || ! F_38 ( V_54 -> V_2 , V_2 ) )
continue;
if ( F_184 ( V_303 , V_54 , V_335 ) < 0 ) {
V_158 -- ;
goto V_318;
}
}
}
V_318:
F_114 ( & V_160 ) ;
V_335 -> args [ 0 ] = V_158 ;
return V_303 -> V_238 ;
}
static int F_191 ( struct V_2 * V_2 ,
struct V_137 * V_229 ,
struct V_305 * V_343 , int V_344 ,
struct V_53 * * V_345 )
{
struct V_305 * V_346 [ V_347 + 1 ] ;
struct V_305 * V_348 , * V_349 , * V_350 , * V_351 , * V_352 ;
struct V_53 * V_54 ;
if ( V_343 == NULL ||
F_192 ( V_346 , V_347 , V_343 , V_353 ) )
return - V_121 ;
V_348 = V_346 [ V_323 ] ;
V_351 = V_346 [ V_325 ] ;
V_352 = V_346 [ V_326 ] ;
V_349 = V_346 [ V_327 ] ;
V_350 = V_346 [ V_324 ] ;
if ( ! ( V_348 && ( V_350 || ( V_349 && V_351 && V_352 ) ) ) )
return - V_121 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
V_229 -> V_40 = F_193 ( V_348 ) ;
#ifdef F_24
if ( V_229 -> V_40 != V_151 && V_229 -> V_40 != V_47 )
#else
if ( V_229 -> V_40 != V_151 )
#endif
return - V_354 ;
if ( V_350 ) {
V_229 -> V_58 = V_68 ;
V_229 -> V_52 = F_194 ( V_350 ) ;
} else {
V_229 -> V_58 = F_193 ( V_351 ) ;
F_195 ( & V_229 -> V_4 , V_352 , sizeof( V_229 -> V_4 ) ) ;
V_229 -> V_43 = F_193 ( V_349 ) ;
V_229 -> V_52 = 0 ;
}
if ( V_229 -> V_52 )
V_54 = F_39 ( V_2 , V_229 -> V_40 , V_229 -> V_52 ) ;
else
V_54 = F_35 ( V_2 , V_229 -> V_40 , V_229 -> V_58 ,
& V_229 -> V_4 , V_229 -> V_43 ) ;
* V_345 = V_54 ;
if ( V_344 ) {
struct V_305 * V_355 , * V_356 , * V_357 , * V_358 ,
* V_359 ;
struct V_320 V_12 ;
V_355 = V_346 [ V_328 ] ;
V_357 = V_346 [ V_329 ] ;
V_356 = V_346 [ V_330 ] ;
V_358 = V_346 [ V_331 ] ;
V_359 = V_346 [ V_332 ] ;
if ( ! ( V_355 && V_356 && V_358 && V_359 ) )
return - V_121 ;
F_195 ( & V_12 , V_356 , sizeof( V_12 ) ) ;
if ( V_54 )
V_229 -> V_12 = V_54 -> V_12 ;
V_229 -> V_12 = ( V_229 -> V_12 & ~ V_12 . V_321 ) |
( V_12 . V_12 & V_12 . V_321 ) ;
V_229 -> V_144 = F_196 ( V_355 ) ;
V_229 -> V_146 = V_357 ? F_196 ( V_357 ) : NULL ;
V_229 -> V_148 = F_194 ( V_358 ) ;
V_229 -> V_147 = F_194 ( V_359 ) ;
}
return 0 ;
}
static struct V_53 * F_197 ( struct V_2 * V_2 ,
struct V_305 * V_343 )
{
struct V_137 V_229 ;
struct V_53 * V_54 ;
int V_131 ;
V_131 = F_191 ( V_2 , & V_229 , V_343 , 0 , & V_54 ) ;
return V_131 ? F_198 ( V_131 ) : V_54 ;
}
static int F_199 ( struct V_302 * V_303 , struct V_75 * V_76 )
{
struct V_305 * V_360 ;
V_360 = F_175 ( V_303 , V_361 ) ;
if ( ! V_360 )
return - V_307 ;
if ( F_182 ( V_303 , V_362 , sizeof( V_76 -> V_4 ) , & V_76 -> V_4 ) ||
F_181 ( V_303 , V_363 , V_76 -> V_43 ) ||
F_176 ( V_303 , V_364 ,
( F_15 ( & V_76 -> V_102 ) &
V_86 ) ) ||
F_176 ( V_303 , V_365 ,
F_15 ( & V_76 -> V_103 ) ) ||
F_176 ( V_303 , V_366 , V_76 -> V_108 ) ||
F_176 ( V_303 , V_367 , V_76 -> V_110 ) ||
F_176 ( V_303 , V_368 ,
F_15 ( & V_76 -> V_128 ) ) ||
F_176 ( V_303 , V_369 ,
F_15 ( & V_76 -> V_129 ) ) ||
F_176 ( V_303 , V_370 ,
F_15 ( & V_76 -> V_130 ) ) )
goto V_318;
if ( F_174 ( V_303 , V_371 , & V_76 -> V_77 ) )
goto V_318;
F_178 ( V_303 , V_360 ) ;
return 0 ;
V_318:
F_179 ( V_303 , V_360 ) ;
return - V_307 ;
}
static int F_200 ( struct V_302 * V_303 , struct V_75 * V_76 ,
struct V_334 * V_335 )
{
void * V_336 ;
V_336 = F_185 ( V_303 , F_186 ( V_335 -> V_303 ) . V_337 , V_335 -> V_338 -> V_339 ,
& V_340 , V_341 ,
V_372 ) ;
if ( ! V_336 )
return - V_307 ;
if ( F_199 ( V_303 , V_76 ) < 0 )
goto V_318;
return F_187 ( V_303 , V_336 ) ;
V_318:
F_188 ( V_303 , V_336 ) ;
return - V_307 ;
}
static int F_201 ( struct V_302 * V_303 ,
struct V_334 * V_335 )
{
int V_158 = 0 ;
int V_213 = V_335 -> args [ 0 ] ;
struct V_53 * V_54 ;
struct V_75 * V_76 ;
struct V_305 * V_346 [ V_373 + 1 ] ;
struct V_2 * V_2 = F_190 ( V_303 ) ;
F_113 ( & V_160 ) ;
if ( F_202 ( V_335 -> V_338 , V_374 , V_346 ,
V_373 , V_375 ) )
goto V_145;
V_54 = F_197 ( V_2 , V_346 [ V_322 ] ) ;
if ( F_203 ( V_54 ) || V_54 == NULL )
goto V_145;
F_36 (dest, &svc->destinations, n_list) {
if ( ++ V_158 <= V_213 )
continue;
if ( F_200 ( V_303 , V_76 , V_335 ) < 0 ) {
V_158 -- ;
goto V_318;
}
}
V_318:
V_335 -> args [ 0 ] = V_158 ;
V_145:
F_114 ( & V_160 ) ;
return V_303 -> V_238 ;
}
static int F_204 ( struct V_99 * V_100 ,
struct V_305 * V_343 , int V_344 )
{
struct V_305 * V_346 [ V_376 + 1 ] ;
struct V_305 * V_352 , * V_349 ;
if ( V_343 == NULL ||
F_192 ( V_346 , V_376 , V_343 , V_377 ) )
return - V_121 ;
V_352 = V_346 [ V_362 ] ;
V_349 = V_346 [ V_363 ] ;
if ( ! ( V_352 && V_349 ) )
return - V_121 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
F_195 ( & V_100 -> V_4 , V_352 , sizeof( V_100 -> V_4 ) ) ;
V_100 -> V_43 = F_193 ( V_349 ) ;
if ( V_344 ) {
struct V_305 * V_378 , * V_379 , * V_380 ,
* V_381 ;
V_378 = V_346 [ V_364 ] ;
V_379 = V_346 [ V_365 ] ;
V_380 = V_346 [ V_366 ] ;
V_381 = V_346 [ V_367 ] ;
if ( ! ( V_378 && V_379 && V_380 && V_381 ) )
return - V_121 ;
V_100 -> V_102 = F_194 ( V_378 )
& V_86 ;
V_100 -> V_103 = F_194 ( V_379 ) ;
V_100 -> V_108 = F_194 ( V_380 ) ;
V_100 -> V_110 = F_194 ( V_381 ) ;
}
return 0 ;
}
static int F_205 ( struct V_302 * V_303 , T_2 V_255 ,
const char * V_256 , T_2 V_257 )
{
struct V_305 * V_382 ;
V_382 = F_175 ( V_303 , V_383 ) ;
if ( ! V_382 )
return - V_307 ;
if ( F_176 ( V_303 , V_384 , V_255 ) ||
F_183 ( V_303 , V_385 , V_256 ) ||
F_176 ( V_303 , V_386 , V_257 ) )
goto V_318;
F_178 ( V_303 , V_382 ) ;
return 0 ;
V_318:
F_179 ( V_303 , V_382 ) ;
return - V_307 ;
}
static int F_206 ( struct V_302 * V_303 , T_2 V_255 ,
const char * V_256 , T_2 V_257 ,
struct V_334 * V_335 )
{
void * V_336 ;
V_336 = F_185 ( V_303 , F_186 ( V_335 -> V_303 ) . V_337 , V_335 -> V_338 -> V_339 ,
& V_340 , V_341 ,
V_387 ) ;
if ( ! V_336 )
return - V_307 ;
if ( F_205 ( V_303 , V_255 , V_256 , V_257 ) )
goto V_318;
return F_187 ( V_303 , V_336 ) ;
V_318:
F_188 ( V_303 , V_336 ) ;
return - V_307 ;
}
static int F_207 ( struct V_302 * V_303 ,
struct V_334 * V_335 )
{
struct V_2 * V_2 = F_190 ( V_303 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_113 ( & V_15 -> V_252 ) ;
if ( ( V_15 -> V_283 & V_284 ) && ! V_335 -> args [ 0 ] ) {
if ( F_206 ( V_303 , V_284 ,
V_15 -> V_285 ,
V_15 -> V_286 , V_335 ) < 0 )
goto V_318;
V_335 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_283 & V_287 ) && ! V_335 -> args [ 1 ] ) {
if ( F_206 ( V_303 , V_287 ,
V_15 -> V_288 ,
V_15 -> V_289 , V_335 ) < 0 )
goto V_318;
V_335 -> args [ 1 ] = 1 ;
}
V_318:
F_114 ( & V_15 -> V_252 ) ;
return V_303 -> V_238 ;
}
static int F_208 ( struct V_2 * V_2 , struct V_305 * * V_346 )
{
if ( ! ( V_346 [ V_384 ] &&
V_346 [ V_385 ] &&
V_346 [ V_386 ] ) )
return - V_121 ;
return F_163 ( V_2 ,
F_194 ( V_346 [ V_384 ] ) ,
F_196 ( V_346 [ V_385 ] ) ,
F_194 ( V_346 [ V_386 ] ) ) ;
}
static int F_209 ( struct V_2 * V_2 , struct V_305 * * V_346 )
{
if ( ! V_346 [ V_384 ] )
return - V_121 ;
return F_164 ( V_2 ,
F_194 ( V_346 [ V_384 ] ) ) ;
}
static int F_210 ( struct V_2 * V_2 , struct V_305 * * V_346 )
{
struct V_216 V_301 ;
F_170 ( V_2 , & V_301 ) ;
if ( V_346 [ V_388 ] )
V_301 . V_221 = F_194 ( V_346 [ V_388 ] ) ;
if ( V_346 [ V_389 ] )
V_301 . V_222 =
F_194 ( V_346 [ V_389 ] ) ;
if ( V_346 [ V_390 ] )
V_301 . V_223 = F_194 ( V_346 [ V_390 ] ) ;
return F_152 ( V_2 , & V_301 ) ;
}
static int F_211 ( struct V_302 * V_303 , struct V_391 * V_294 )
{
int V_131 = 0 , V_236 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_190 ( V_303 ) ;
V_15 = F_41 ( V_2 ) ;
V_236 = V_294 -> V_392 -> V_236 ;
if ( V_236 == V_387 || V_236 == V_393 ) {
struct V_305 * V_394 [ V_395 + 1 ] ;
F_113 ( & V_15 -> V_252 ) ;
if ( ! V_294 -> V_346 [ V_383 ] ||
F_192 ( V_394 , V_395 ,
V_294 -> V_346 [ V_383 ] ,
V_396 ) ) {
V_131 = - V_121 ;
goto V_67;
}
if ( V_236 == V_387 )
V_131 = F_208 ( V_2 , V_394 ) ;
else
V_131 = F_209 ( V_2 , V_394 ) ;
V_67:
F_114 ( & V_15 -> V_252 ) ;
}
return V_131 ;
}
static int F_212 ( struct V_302 * V_303 , struct V_391 * V_294 )
{
struct V_53 * V_54 = NULL ;
struct V_137 V_229 ;
struct V_99 V_100 ;
int V_131 = 0 , V_236 ;
int V_397 = 0 , V_398 = 0 ;
struct V_2 * V_2 ;
V_2 = F_190 ( V_303 ) ;
V_236 = V_294 -> V_392 -> V_236 ;
F_113 ( & V_160 ) ;
if ( V_236 == V_399 ) {
V_131 = F_111 ( V_2 ) ;
goto V_67;
} else if ( V_236 == V_400 ) {
V_131 = F_210 ( V_2 , V_294 -> V_346 ) ;
goto V_67;
} else if ( V_236 == V_401 &&
! V_294 -> V_346 [ V_322 ] ) {
V_131 = F_119 ( V_2 ) ;
goto V_67;
}
if ( V_236 == V_342 || V_236 == V_402 )
V_397 = 1 ;
V_131 = F_191 ( V_2 , & V_229 ,
V_294 -> V_346 [ V_322 ] ,
V_397 , & V_54 ) ;
if ( V_131 )
goto V_67;
if ( ( V_236 != V_342 ) && ( V_54 == NULL ) ) {
V_131 = - V_263 ;
goto V_67;
}
if ( V_236 == V_372 || V_236 == V_403 ||
V_236 == V_404 ) {
if ( V_236 != V_404 )
V_398 = 1 ;
V_131 = F_204 ( & V_100 ,
V_294 -> V_346 [ V_361 ] ,
V_398 ) ;
if ( V_131 )
goto V_67;
}
switch ( V_236 ) {
case V_342 :
if ( V_54 == NULL )
V_131 = F_95 ( V_2 , & V_229 , & V_54 ) ;
else
V_131 = - V_133 ;
break;
case V_402 :
V_131 = F_106 ( V_54 , & V_229 ) ;
break;
case V_405 :
V_131 = F_110 ( V_54 ) ;
break;
case V_372 :
V_131 = F_88 ( V_54 , & V_100 ) ;
break;
case V_403 :
V_131 = F_90 ( V_54 , & V_100 ) ;
break;
case V_404 :
V_131 = F_94 ( V_54 , & V_100 ) ;
break;
case V_401 :
V_131 = F_118 ( V_54 ) ;
break;
default:
V_131 = - V_121 ;
}
V_67:
F_114 ( & V_160 ) ;
return V_131 ;
}
static int F_213 ( struct V_302 * V_303 , struct V_391 * V_294 )
{
struct V_302 * V_406 ;
void * V_407 ;
int V_131 , V_236 , V_408 ;
struct V_2 * V_2 ;
V_2 = F_190 ( V_303 ) ;
V_236 = V_294 -> V_392 -> V_236 ;
if ( V_236 == V_409 )
V_408 = V_342 ;
else if ( V_236 == V_410 )
V_408 = V_411 ;
else if ( V_236 == V_412 )
V_408 = V_400 ;
else {
F_28 ( L_61 ) ;
return - V_121 ;
}
V_406 = F_214 ( V_413 , V_124 ) ;
if ( ! V_406 )
return - V_125 ;
F_113 ( & V_160 ) ;
V_407 = F_215 ( V_406 , V_294 , & V_340 , 0 , V_408 ) ;
if ( V_407 == NULL )
goto V_318;
switch ( V_236 ) {
case V_409 :
{
struct V_53 * V_54 ;
V_54 = F_197 ( V_2 ,
V_294 -> V_346 [ V_322 ] ) ;
if ( F_203 ( V_54 ) ) {
V_131 = F_216 ( V_54 ) ;
goto V_145;
} else if ( V_54 ) {
V_131 = F_180 ( V_406 , V_54 ) ;
if ( V_131 )
goto V_318;
} else {
V_131 = - V_263 ;
goto V_145;
}
break;
}
case V_412 :
{
struct V_216 V_301 ;
F_170 ( V_2 , & V_301 ) ;
#ifdef V_217
if ( F_176 ( V_406 , V_388 ,
V_301 . V_221 ) ||
F_176 ( V_406 , V_389 ,
V_301 . V_222 ) )
goto V_318;
#endif
#ifdef V_218
if ( F_176 ( V_406 , V_390 , V_301 . V_223 ) )
goto V_318;
#endif
break;
}
case V_410 :
if ( F_176 ( V_406 , V_414 ,
V_199 ) ||
F_176 ( V_406 , V_415 ,
V_200 ) )
goto V_318;
break;
}
F_187 ( V_406 , V_407 ) ;
V_131 = F_217 ( V_406 , V_294 ) ;
goto V_67;
V_318:
F_28 ( L_62 ) ;
V_131 = - V_307 ;
V_145:
F_218 ( V_406 ) ;
V_67:
F_114 ( & V_160 ) ;
return V_131 ;
}
static int T_10 F_219 ( void )
{
return F_220 ( & V_340 ,
V_416 , F_221 ( V_416 ) ) ;
}
static void F_222 ( void )
{
F_223 ( & V_340 ) ;
}
static int T_11 F_224 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct T_6 * V_417 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_86 ( & V_15 -> V_25 ) ;
F_86 ( & V_15 -> V_28 ) ;
F_86 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_418 ) ) {
V_417 = F_225 ( V_419 , sizeof( V_419 ) , V_124 ) ;
if ( V_417 == NULL )
return - V_125 ;
if ( V_2 -> V_241 != & V_420 )
V_417 [ 0 ] . V_421 = NULL ;
} else
V_417 = V_419 ;
V_158 = 0 ;
V_15 -> V_24 = 1024 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_32 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_26 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_29 ;
#ifdef F_226
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_422 ;
#endif
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_34 ;
V_15 -> V_423 = 1 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_423 ;
V_15 -> V_424 = 1 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_424 ;
V_15 -> V_425 = 1 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_425 ;
V_15 -> V_426 = F_227 () / 32 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_426 ;
V_15 -> V_427 = 0 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_427 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_428 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_429 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_430 ;
V_15 -> V_431 [ 0 ] = V_432 ;
V_15 -> V_431 [ 1 ] = V_433 ;
V_417 [ V_158 ] . V_180 = & V_15 -> V_431 ;
V_417 [ V_158 ++ ] . V_434 = sizeof( V_15 -> V_431 ) ;
V_15 -> V_435 = V_436 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_435 ;
V_15 -> V_437 = F_228 ( int , V_438 , 0 , 3 ) ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_437 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_439 ;
V_15 -> V_440 = 1 ;
V_417 [ V_158 ++ ] . V_180 = & V_15 -> V_440 ;
V_15 -> V_441 = F_229 ( V_2 , L_63 , V_417 ) ;
if ( V_15 -> V_441 == NULL ) {
if ( ! F_38 ( V_2 , & V_418 ) )
F_51 ( V_417 ) ;
return - V_125 ;
}
F_76 ( V_2 , & V_15 -> V_170 ) ;
V_15 -> V_442 = V_417 ;
F_230 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_12 F_231 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_232 ( & V_15 -> V_37 ) ;
F_233 ( & V_15 -> V_37 . V_36 ) ;
F_234 ( V_15 -> V_441 ) ;
}
static int T_11 F_224 ( struct V_2 * V_2 ) { return 0 ; }
static void T_12 F_231 ( struct V_2 * V_2 ) { }
int T_11 F_235 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_99 ( & V_15 -> V_84 ) ;
for ( V_158 = 0 ; V_158 < V_443 ; V_158 ++ )
F_85 ( & V_15 -> V_82 [ V_158 ] ) ;
F_85 ( & V_15 -> V_135 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_170 . V_78 = F_83 ( struct V_126 ) ;
if ( ! V_15 -> V_170 . V_78 )
return - V_125 ;
F_86 ( & V_15 -> V_170 . V_93 ) ;
F_236 ( V_2 , L_64 , 0 , & V_444 ) ;
F_236 ( V_2 , L_65 , 0 , & V_445 ) ;
F_236 ( V_2 , L_66 , 0 ,
& V_446 ) ;
if ( F_224 ( V_2 ) )
goto V_447;
return 0 ;
V_447:
F_50 ( V_15 -> V_170 . V_78 ) ;
return - V_125 ;
}
void T_12 F_237 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_64 ( V_2 ) ;
F_92 ( V_2 , & V_15 -> V_170 ) ;
F_231 ( V_2 ) ;
F_238 ( V_2 , L_66 ) ;
F_238 ( V_2 , L_65 ) ;
F_238 ( V_2 , L_64 ) ;
F_50 ( V_15 -> V_170 . V_78 ) ;
}
int T_10 F_239 ( void )
{
int V_131 ;
V_131 = F_240 ( & V_448 ) ;
if ( V_131 ) {
F_28 ( L_67 ) ;
goto V_449;
}
V_131 = F_219 () ;
if ( V_131 ) {
F_28 ( L_68 ) ;
goto V_450;
}
return 0 ;
V_450:
F_241 ( & V_448 ) ;
V_449:
return V_131 ;
}
void F_242 ( void )
{
F_222 () ;
F_241 ( & V_448 ) ;
}
int T_10 F_243 ( void )
{
int V_158 ;
int V_131 ;
F_79 ( 2 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_85 ( & V_60 [ V_158 ] ) ;
F_85 ( & V_62 [ V_158 ] ) ;
}
F_244 () ;
V_131 = F_245 ( & V_451 ) ;
if ( V_131 < 0 )
return V_131 ;
F_87 ( 2 ) ;
return 0 ;
}
void F_246 ( void )
{
F_79 ( 2 ) ;
F_247 ( & V_451 ) ;
F_87 ( 2 ) ;
}
