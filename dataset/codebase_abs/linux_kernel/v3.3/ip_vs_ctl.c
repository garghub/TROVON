int F_1 ( void )
{
return V_1 ;
}
static int F_2 ( struct V_2 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 V_8 = {
. V_9 = * V_4 ,
} ;
V_6 = (struct V_5 * ) F_3 ( V_2 , NULL , & V_8 ) ;
if ( V_6 && V_6 -> V_10 . V_11 && ( V_6 -> V_10 . V_11 -> V_12 & V_13 ) )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_14 * V_15 )
{
struct V_16 V_17 ;
static int V_18 = 0 ;
int V_19 ;
int V_20 ;
int V_21 = - 1 ;
F_5 ( & V_17 ) ;
V_19 = V_17 . V_22 + V_17 . V_23 ;
V_20 = ( V_19 < V_15 -> V_24 ) ;
F_6 () ;
F_7 ( & V_15 -> V_25 ) ;
switch ( V_15 -> V_26 ) {
case 0 :
F_8 ( & V_15 -> V_27 , 0 ) ;
break;
case 1 :
if ( V_20 ) {
F_8 ( & V_15 -> V_27 , 1 ) ;
V_15 -> V_26 = 2 ;
} else {
F_8 ( & V_15 -> V_27 , 0 ) ;
}
break;
case 2 :
if ( V_20 ) {
F_8 ( & V_15 -> V_27 , 1 ) ;
} else {
F_8 ( & V_15 -> V_27 , 0 ) ;
V_15 -> V_26 = 1 ;
} ;
break;
case 3 :
F_8 ( & V_15 -> V_27 , 1 ) ;
break;
}
F_9 ( & V_15 -> V_25 ) ;
F_7 ( & V_15 -> V_28 ) ;
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
F_9 ( & V_15 -> V_28 ) ;
F_7 ( & V_15 -> V_33 ) ;
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
F_10 ( V_15 ,
V_15 -> V_34 > 1 ) ;
F_9 ( & V_15 -> V_33 ) ;
F_11 () ;
}
static void F_12 ( struct V_35 * V_36 )
{
struct V_14 * V_15 =
F_13 ( V_36 , struct V_14 , V_37 . V_36 ) ;
F_4 ( V_15 ) ;
if ( F_14 ( & V_15 -> V_27 ) )
F_15 ( V_15 -> V_2 ) ;
F_16 ( & V_15 -> V_37 , V_38 ) ;
}
int
F_17 ( void )
{
return F_18 ( V_39 ) ;
}
void
F_19 ( void )
{
F_20 ( V_39 ) ;
}
static inline unsigned
F_21 ( struct V_2 * V_2 , int V_40 , unsigned V_41 ,
const union V_42 * V_4 , T_1 V_43 )
{
register unsigned V_44 = F_22 ( V_43 ) ;
T_2 V_45 = V_4 -> V_46 ;
#ifdef F_23
if ( V_40 == V_47 )
V_45 = V_4 -> V_48 [ 0 ] ^ V_4 -> V_48 [ 1 ] ^
V_4 -> V_48 [ 2 ] ^ V_4 -> V_48 [ 3 ] ;
#endif
V_45 ^= ( ( V_49 ) V_2 >> 8 ) ;
return ( V_41 ^ F_24 ( V_45 ) ^ ( V_44 >> V_50 ) ^ V_44 )
& V_51 ;
}
static inline unsigned F_25 ( struct V_2 * V_2 , T_3 V_52 )
{
return ( ( ( V_49 ) V_2 >> 8 ) ^ V_52 ) & V_51 ;
}
static int F_26 ( struct V_53 * V_54 )
{
unsigned V_55 ;
if ( V_54 -> V_12 & V_56 ) {
F_27 ( L_1 ,
V_57 , F_28 ( 0 ) ) ;
return 0 ;
}
if ( V_54 -> V_52 == 0 ) {
V_55 = F_21 ( V_54 -> V_2 , V_54 -> V_40 , V_54 -> V_58 ,
& V_54 -> V_4 , V_54 -> V_43 ) ;
F_29 ( & V_54 -> V_59 , & V_60 [ V_55 ] ) ;
} else {
V_55 = F_25 ( V_54 -> V_2 , V_54 -> V_52 ) ;
F_29 ( & V_54 -> V_61 , & V_62 [ V_55 ] ) ;
}
V_54 -> V_12 |= V_56 ;
F_30 ( & V_54 -> V_63 ) ;
return 1 ;
}
static int F_31 ( struct V_53 * V_54 )
{
if ( ! ( V_54 -> V_12 & V_56 ) ) {
F_27 ( L_2 ,
V_57 , F_28 ( 0 ) ) ;
return 0 ;
}
if ( V_54 -> V_52 == 0 ) {
F_32 ( & V_54 -> V_59 ) ;
} else {
F_32 ( & V_54 -> V_61 ) ;
}
V_54 -> V_12 &= ~ V_56 ;
F_33 ( & V_54 -> V_63 ) ;
return 1 ;
}
static inline struct V_53 *
F_34 ( struct V_2 * V_2 , int V_40 , T_4 V_58 ,
const union V_42 * V_64 , T_1 V_65 )
{
unsigned V_55 ;
struct V_53 * V_54 ;
V_55 = F_21 ( V_2 , V_40 , V_58 , V_64 , V_65 ) ;
F_35 (svc, &ip_vs_svc_table[hash], s_list) {
if ( ( V_54 -> V_40 == V_40 )
&& F_36 ( V_40 , & V_54 -> V_4 , V_64 )
&& ( V_54 -> V_43 == V_65 )
&& ( V_54 -> V_58 == V_58 )
&& F_37 ( V_54 -> V_2 , V_2 ) ) {
return V_54 ;
}
}
return NULL ;
}
static inline struct V_53 *
F_38 ( struct V_2 * V_2 , int V_40 , T_3 V_52 )
{
unsigned V_55 ;
struct V_53 * V_54 ;
V_55 = F_25 ( V_2 , V_52 ) ;
F_35 (svc, &ip_vs_svc_fwm_table[hash], f_list) {
if ( V_54 -> V_52 == V_52 && V_54 -> V_40 == V_40
&& F_37 ( V_54 -> V_2 , V_2 ) ) {
return V_54 ;
}
}
return NULL ;
}
struct V_53 *
F_39 ( struct V_2 * V_2 , int V_40 , T_3 V_52 , T_4 V_58 ,
const union V_42 * V_64 , T_1 V_65 )
{
struct V_53 * V_54 ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_41 ( & V_66 ) ;
if ( V_52 ) {
V_54 = F_38 ( V_2 , V_40 , V_52 ) ;
if ( V_54 )
goto V_67;
}
V_54 = F_34 ( V_2 , V_40 , V_58 , V_64 , V_65 ) ;
if ( V_54 == NULL
&& V_58 == V_68
&& F_14 ( & V_15 -> V_69 )
&& ( V_65 == V_70 || F_22 ( V_65 ) >= V_71 ) ) {
V_54 = F_34 ( V_2 , V_40 , V_58 , V_64 , V_72 ) ;
}
if ( V_54 == NULL
&& F_14 ( & V_15 -> V_73 ) ) {
V_54 = F_34 ( V_2 , V_40 , V_58 , V_64 , 0 ) ;
}
V_67:
if ( V_54 )
F_30 ( & V_54 -> V_74 ) ;
F_42 ( & V_66 ) ;
F_43 ( 9 , L_3 ,
V_52 , F_44 ( V_58 ) ,
F_45 ( V_40 , V_64 ) , F_22 ( V_65 ) ,
V_54 ? L_4 : L_5 ) ;
return V_54 ;
}
static inline void
F_46 ( struct V_75 * V_76 , struct V_53 * V_54 )
{
F_30 ( & V_54 -> V_63 ) ;
V_76 -> V_54 = V_54 ;
}
static void
F_47 ( struct V_75 * V_76 )
{
struct V_53 * V_54 = V_76 -> V_54 ;
V_76 -> V_54 = NULL ;
if ( F_48 ( & V_54 -> V_63 ) ) {
F_43 ( 3 , L_6 ,
V_54 -> V_52 ,
F_45 ( V_54 -> V_40 , & V_54 -> V_4 ) ,
F_22 ( V_54 -> V_43 ) , F_14 ( & V_54 -> V_74 ) ) ;
F_49 ( V_54 -> V_77 . V_78 ) ;
F_50 ( V_54 ) ;
}
}
static inline unsigned F_51 ( int V_40 ,
const union V_42 * V_4 ,
T_1 V_43 )
{
register unsigned V_44 = F_22 ( V_43 ) ;
T_2 V_45 = V_4 -> V_46 ;
#ifdef F_23
if ( V_40 == V_47 )
V_45 = V_4 -> V_48 [ 0 ] ^ V_4 -> V_48 [ 1 ] ^
V_4 -> V_48 [ 2 ] ^ V_4 -> V_48 [ 3 ] ;
#endif
return ( F_24 ( V_45 ) ^ ( V_44 >> V_79 ) ^ V_44 )
& V_80 ;
}
static int F_52 ( struct V_14 * V_15 , struct V_75 * V_76 )
{
unsigned V_55 ;
if ( ! F_53 ( & V_76 -> V_81 ) ) {
return 0 ;
}
V_55 = F_51 ( V_76 -> V_40 , & V_76 -> V_4 , V_76 -> V_43 ) ;
F_29 ( & V_76 -> V_81 , & V_15 -> V_82 [ V_55 ] ) ;
return 1 ;
}
static int F_54 ( struct V_75 * V_76 )
{
if ( ! F_53 ( & V_76 -> V_81 ) ) {
F_32 ( & V_76 -> V_81 ) ;
F_55 ( & V_76 -> V_81 ) ;
}
return 1 ;
}
struct V_75 *
F_56 ( struct V_2 * V_2 , int V_40 , T_4 V_58 ,
const union V_42 * V_9 ,
T_1 V_83 )
{
struct V_14 * V_15 = F_40 ( V_2 ) ;
unsigned V_55 ;
struct V_75 * V_76 ;
V_55 = F_51 ( V_40 , V_9 , V_83 ) ;
F_41 ( & V_15 -> V_84 ) ;
F_35 (dest, &ipvs->rs_table[hash], d_list) {
if ( ( V_76 -> V_40 == V_40 )
&& F_36 ( V_40 , & V_76 -> V_4 , V_9 )
&& ( V_76 -> V_43 == V_83 )
&& ( ( V_76 -> V_58 == V_58 ) ||
V_76 -> V_85 ) ) {
F_42 ( & V_15 -> V_84 ) ;
return V_76 ;
}
}
F_42 ( & V_15 -> V_84 ) ;
return NULL ;
}
static struct V_75 *
F_57 ( struct V_53 * V_54 , const union V_42 * V_9 ,
T_1 V_83 )
{
struct V_75 * V_76 ;
F_35 (dest, &svc->destinations, n_list) {
if ( ( V_76 -> V_40 == V_54 -> V_40 )
&& F_36 ( V_54 -> V_40 , & V_76 -> V_4 , V_9 )
&& ( V_76 -> V_43 == V_83 ) ) {
return V_76 ;
}
}
return NULL ;
}
struct V_75 * F_58 ( struct V_2 * V_2 , int V_40 ,
const union V_42 * V_9 ,
T_1 V_83 ,
const union V_42 * V_64 ,
T_1 V_65 , T_4 V_58 , T_3 V_52 ,
T_3 V_12 )
{
struct V_75 * V_76 ;
struct V_53 * V_54 ;
T_1 V_43 = V_83 ;
V_54 = F_39 ( V_2 , V_40 , V_52 , V_58 , V_64 , V_65 ) ;
if ( ! V_54 )
return NULL ;
if ( V_52 && ( V_12 & V_86 ) != V_87 )
V_43 = 0 ;
V_76 = F_57 ( V_54 , V_9 , V_43 ) ;
if ( ! V_76 )
V_76 = F_57 ( V_54 , V_9 , V_43 ^ V_83 ) ;
if ( V_76 )
F_30 ( & V_76 -> V_63 ) ;
F_59 ( V_54 ) ;
return V_76 ;
}
static struct V_75 *
F_60 ( struct V_53 * V_54 , const union V_42 * V_9 ,
T_1 V_83 )
{
struct V_75 * V_76 , * V_88 ;
struct V_14 * V_15 = F_40 ( V_54 -> V_2 ) ;
F_61 (dest, nxt, &ipvs->dest_trash, n_list) {
F_43 ( 3 , L_7
L_8 ,
V_76 -> V_85 ,
F_45 ( V_54 -> V_40 , & V_76 -> V_4 ) ,
F_22 ( V_76 -> V_43 ) ,
F_14 ( & V_76 -> V_63 ) ) ;
if ( V_76 -> V_40 == V_54 -> V_40 &&
F_36 ( V_54 -> V_40 , & V_76 -> V_4 , V_9 ) &&
V_76 -> V_43 == V_83 &&
V_76 -> V_85 == V_54 -> V_52 &&
V_76 -> V_58 == V_54 -> V_58 &&
( V_54 -> V_52 ||
( F_36 ( V_54 -> V_40 , & V_76 -> V_64 , & V_54 -> V_4 ) &&
V_76 -> V_65 == V_54 -> V_43 ) ) ) {
return V_76 ;
}
if ( F_14 ( & V_76 -> V_63 ) == 1 ) {
F_43 ( 3 , L_9
L_10 ,
V_76 -> V_85 ,
F_45 ( V_54 -> V_40 , & V_76 -> V_4 ) ,
F_22 ( V_76 -> V_43 ) ) ;
F_32 ( & V_76 -> V_89 ) ;
F_62 ( V_76 ) ;
F_47 ( V_76 ) ;
F_49 ( V_76 -> V_77 . V_78 ) ;
F_50 ( V_76 ) ;
}
}
return NULL ;
}
static void F_63 ( struct V_2 * V_2 )
{
struct V_75 * V_76 , * V_88 ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_61 (dest, nxt, &ipvs->dest_trash, n_list) {
F_32 ( & V_76 -> V_89 ) ;
F_62 ( V_76 ) ;
F_47 ( V_76 ) ;
F_49 ( V_76 -> V_77 . V_78 ) ;
F_50 ( V_76 ) ;
}
}
static void
F_64 ( struct V_90 * V_10 , struct V_91 * V_92 )
{
#define F_65 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_66 ( & V_92 -> V_93 ) ;
F_65 ( V_94 ) ;
F_65 ( V_95 ) ;
F_65 ( V_96 ) ;
F_65 ( V_97 ) ;
F_65 ( V_98 ) ;
F_67 ( V_10 , V_92 ) ;
F_68 ( & V_92 -> V_93 ) ;
}
static void
F_69 ( struct V_91 * V_77 )
{
F_66 ( & V_77 -> V_93 ) ;
#define F_70 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_70 ( V_94 ) ;
F_70 ( V_95 ) ;
F_70 ( V_96 ) ;
F_70 ( V_97 ) ;
F_70 ( V_98 ) ;
F_71 ( V_77 ) ;
F_68 ( & V_77 -> V_93 ) ;
}
static void
F_72 ( struct V_53 * V_54 , struct V_75 * V_76 ,
struct V_99 * V_100 , int V_101 )
{
struct V_14 * V_15 = F_40 ( V_54 -> V_2 ) ;
int V_102 ;
F_8 ( & V_76 -> V_103 , V_100 -> V_103 ) ;
V_102 = V_100 -> V_102 & V_104 ;
V_102 |= V_105 ;
if ( ( V_102 & V_86 ) != V_87 ) {
V_102 |= V_106 ;
} else {
F_73 ( & V_15 -> V_84 ) ;
F_52 ( V_15 , V_76 ) ;
F_74 ( & V_15 -> V_84 ) ;
}
F_8 ( & V_76 -> V_102 , V_102 ) ;
if ( ! V_76 -> V_54 ) {
F_46 ( V_76 , V_54 ) ;
} else {
if ( V_76 -> V_54 != V_54 ) {
F_47 ( V_76 ) ;
F_69 ( & V_76 -> V_77 ) ;
F_46 ( V_76 , V_54 ) ;
}
}
V_76 -> V_12 |= V_107 ;
if ( V_100 -> V_108 == 0 || V_100 -> V_108 > V_76 -> V_108 )
V_76 -> V_12 &= ~ V_109 ;
V_76 -> V_108 = V_100 -> V_108 ;
V_76 -> V_110 = V_100 -> V_110 ;
F_66 ( & V_76 -> V_111 ) ;
F_62 ( V_76 ) ;
F_68 ( & V_76 -> V_111 ) ;
if ( V_101 )
F_75 ( V_54 -> V_2 , & V_76 -> V_77 ) ;
F_73 ( & V_66 ) ;
F_76 ( F_14 ( & V_54 -> V_74 ) > 0 ) ;
if ( V_101 ) {
F_29 ( & V_76 -> V_89 , & V_54 -> V_112 ) ;
V_54 -> V_113 ++ ;
}
if ( V_54 -> V_114 -> V_115 )
V_54 -> V_114 -> V_115 ( V_54 ) ;
F_74 ( & V_66 ) ;
}
static int
F_77 ( struct V_53 * V_54 , struct V_99 * V_100 ,
struct V_75 * * V_116 )
{
struct V_75 * V_76 ;
unsigned V_117 ;
F_78 ( 2 ) ;
#ifdef F_23
if ( V_54 -> V_40 == V_47 ) {
V_117 = F_79 ( & V_100 -> V_4 . V_118 ) ;
if ( ( ! ( V_117 & V_119 ) ||
V_117 & V_120 ) &&
! F_2 ( V_54 -> V_2 , & V_100 -> V_4 . V_118 ) )
return - V_121 ;
} else
#endif
{
V_117 = F_80 ( V_54 -> V_2 , V_100 -> V_4 . V_46 ) ;
if ( V_117 != V_122 && V_117 != V_123 )
return - V_121 ;
}
V_76 = F_81 ( sizeof( struct V_75 ) , V_124 ) ;
if ( V_76 == NULL )
return - V_125 ;
V_76 -> V_77 . V_78 = F_82 ( struct V_126 ) ;
if ( ! V_76 -> V_77 . V_78 )
goto V_127;
V_76 -> V_40 = V_54 -> V_40 ;
V_76 -> V_58 = V_54 -> V_58 ;
V_76 -> V_64 = V_54 -> V_4 ;
V_76 -> V_65 = V_54 -> V_43 ;
V_76 -> V_85 = V_54 -> V_52 ;
F_83 ( V_54 -> V_40 , & V_76 -> V_4 , & V_100 -> V_4 ) ;
V_76 -> V_43 = V_100 -> V_43 ;
F_8 ( & V_76 -> V_128 , 0 ) ;
F_8 ( & V_76 -> V_129 , 0 ) ;
F_8 ( & V_76 -> V_130 , 0 ) ;
F_8 ( & V_76 -> V_63 , 1 ) ;
F_55 ( & V_76 -> V_81 ) ;
F_84 ( & V_76 -> V_111 ) ;
F_84 ( & V_76 -> V_77 . V_93 ) ;
F_72 ( V_54 , V_76 , V_100 , 1 ) ;
* V_116 = V_76 ;
F_85 ( 2 ) ;
return 0 ;
V_127:
F_50 ( V_76 ) ;
return - V_125 ;
}
static int
F_86 ( struct V_53 * V_54 , struct V_99 * V_100 )
{
struct V_75 * V_76 ;
union V_42 V_9 ;
T_1 V_83 = V_100 -> V_43 ;
int V_131 ;
F_78 ( 2 ) ;
if ( V_100 -> V_103 < 0 ) {
F_27 ( L_11 , V_57 ) ;
return - V_132 ;
}
if ( V_100 -> V_110 > V_100 -> V_108 ) {
F_27 ( L_12 ,
V_57 ) ;
return - V_132 ;
}
F_83 ( V_54 -> V_40 , & V_9 , & V_100 -> V_4 ) ;
V_76 = F_57 ( V_54 , & V_9 , V_83 ) ;
if ( V_76 != NULL ) {
F_87 ( 1 , L_13 , V_57 ) ;
return - V_133 ;
}
V_76 = F_60 ( V_54 , & V_9 , V_83 ) ;
if ( V_76 != NULL ) {
F_43 ( 3 , L_14
L_15 ,
F_45 ( V_54 -> V_40 , & V_9 ) , F_22 ( V_83 ) ,
F_14 ( & V_76 -> V_63 ) ,
V_76 -> V_85 ,
F_45 ( V_54 -> V_40 , & V_76 -> V_64 ) ,
F_22 ( V_76 -> V_65 ) ) ;
F_32 ( & V_76 -> V_89 ) ;
F_72 ( V_54 , V_76 , V_100 , 1 ) ;
V_131 = 0 ;
} else {
V_131 = F_77 ( V_54 , V_100 , & V_76 ) ;
}
F_85 ( 2 ) ;
return V_131 ;
}
static int
F_88 ( struct V_53 * V_54 , struct V_99 * V_100 )
{
struct V_75 * V_76 ;
union V_42 V_9 ;
T_1 V_83 = V_100 -> V_43 ;
F_78 ( 2 ) ;
if ( V_100 -> V_103 < 0 ) {
F_27 ( L_11 , V_57 ) ;
return - V_132 ;
}
if ( V_100 -> V_110 > V_100 -> V_108 ) {
F_27 ( L_12 ,
V_57 ) ;
return - V_132 ;
}
F_83 ( V_54 -> V_40 , & V_9 , & V_100 -> V_4 ) ;
V_76 = F_57 ( V_54 , & V_9 , V_83 ) ;
if ( V_76 == NULL ) {
F_87 ( 1 , L_16 , V_57 ) ;
return - V_134 ;
}
F_72 ( V_54 , V_76 , V_100 , 0 ) ;
F_85 ( 2 ) ;
return 0 ;
}
static void F_89 ( struct V_2 * V_2 , struct V_75 * V_76 )
{
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_90 ( V_2 , & V_76 -> V_77 ) ;
F_73 ( & V_15 -> V_84 ) ;
F_54 ( V_76 ) ;
F_74 ( & V_15 -> V_84 ) ;
if ( F_48 ( & V_76 -> V_63 ) ) {
F_43 ( 3 , L_17 ,
V_76 -> V_85 ,
F_45 ( V_76 -> V_40 , & V_76 -> V_4 ) ,
F_22 ( V_76 -> V_43 ) ) ;
F_62 ( V_76 ) ;
F_33 ( & V_76 -> V_54 -> V_63 ) ;
F_49 ( V_76 -> V_77 . V_78 ) ;
F_50 ( V_76 ) ;
} else {
F_43 ( 3 , L_18
L_8 ,
F_45 ( V_76 -> V_40 , & V_76 -> V_4 ) ,
F_22 ( V_76 -> V_43 ) ,
F_14 ( & V_76 -> V_63 ) ) ;
F_29 ( & V_76 -> V_89 , & V_15 -> V_135 ) ;
F_30 ( & V_76 -> V_63 ) ;
}
}
static void F_91 ( struct V_53 * V_54 ,
struct V_75 * V_76 ,
int V_136 )
{
V_76 -> V_12 &= ~ V_107 ;
F_32 ( & V_76 -> V_89 ) ;
V_54 -> V_113 -- ;
if ( V_136 && V_54 -> V_114 -> V_115 )
V_54 -> V_114 -> V_115 ( V_54 ) ;
}
static int
F_92 ( struct V_53 * V_54 , struct V_99 * V_100 )
{
struct V_75 * V_76 ;
T_1 V_83 = V_100 -> V_43 ;
F_78 ( 2 ) ;
V_76 = F_57 ( V_54 , & V_100 -> V_4 , V_83 ) ;
if ( V_76 == NULL ) {
F_87 ( 1 , L_19 , V_57 ) ;
return - V_134 ;
}
F_73 ( & V_66 ) ;
F_76 ( F_14 ( & V_54 -> V_74 ) > 0 ) ;
F_91 ( V_54 , V_76 , 1 ) ;
F_74 ( & V_66 ) ;
F_89 ( V_54 -> V_2 , V_76 ) ;
F_85 ( 2 ) ;
return 0 ;
}
static int
F_93 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_53 * * V_139 )
{
int V_131 = 0 ;
struct V_140 * V_141 = NULL ;
struct V_142 * V_143 = NULL ;
struct V_53 * V_54 = NULL ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_17 () ;
V_141 = F_94 ( V_138 -> V_144 ) ;
if ( V_141 == NULL ) {
F_95 ( L_20 , V_138 -> V_144 ) ;
V_131 = - V_134 ;
goto V_145;
}
if ( V_138 -> V_146 && * V_138 -> V_146 ) {
V_143 = F_96 ( V_138 -> V_146 ) ;
if ( V_143 == NULL ) {
F_95 ( L_21
L_22 , V_138 -> V_146 ) ;
V_131 = - V_134 ;
goto V_145;
}
}
#ifdef F_23
if ( V_138 -> V_40 == V_47 && ( V_138 -> V_147 < 1 || V_138 -> V_147 > 128 ) ) {
V_131 = - V_121 ;
goto V_145;
}
#endif
V_54 = F_81 ( sizeof( struct V_53 ) , V_124 ) ;
if ( V_54 == NULL ) {
F_87 ( 1 , L_23 , V_57 ) ;
V_131 = - V_125 ;
goto V_145;
}
V_54 -> V_77 . V_78 = F_82 ( struct V_126 ) ;
if ( ! V_54 -> V_77 . V_78 )
goto V_145;
F_8 ( & V_54 -> V_74 , 0 ) ;
F_8 ( & V_54 -> V_63 , 0 ) ;
V_54 -> V_40 = V_138 -> V_40 ;
V_54 -> V_58 = V_138 -> V_58 ;
F_83 ( V_54 -> V_40 , & V_54 -> V_4 , & V_138 -> V_4 ) ;
V_54 -> V_43 = V_138 -> V_43 ;
V_54 -> V_52 = V_138 -> V_52 ;
V_54 -> V_12 = V_138 -> V_12 ;
V_54 -> V_148 = V_138 -> V_148 * V_149 ;
V_54 -> V_147 = V_138 -> V_147 ;
V_54 -> V_2 = V_2 ;
F_55 ( & V_54 -> V_112 ) ;
F_97 ( & V_54 -> V_150 ) ;
F_84 ( & V_54 -> V_77 . V_93 ) ;
V_131 = F_98 ( V_54 , V_141 ) ;
if ( V_131 )
goto V_145;
V_141 = NULL ;
F_99 ( V_54 , V_143 ) ;
V_143 = NULL ;
if ( V_54 -> V_43 == V_72 )
F_30 ( & V_15 -> V_69 ) ;
else if ( V_54 -> V_43 == 0 )
F_30 ( & V_15 -> V_73 ) ;
F_75 ( V_2 , & V_54 -> V_77 ) ;
if ( V_54 -> V_40 == V_151 )
V_15 -> V_152 ++ ;
F_73 ( & V_66 ) ;
F_26 ( V_54 ) ;
F_74 ( & V_66 ) ;
* V_139 = V_54 ;
V_15 -> V_153 = 1 ;
return 0 ;
V_145:
if ( V_54 != NULL ) {
F_100 ( V_54 ) ;
if ( V_54 -> V_154 ) {
F_6 () ;
F_101 ( V_54 -> V_154 ) ;
F_11 () ;
}
if ( V_54 -> V_77 . V_78 )
F_49 ( V_54 -> V_77 . V_78 ) ;
F_50 ( V_54 ) ;
}
F_102 ( V_141 ) ;
F_103 ( V_143 ) ;
F_19 () ;
return V_131 ;
}
static int
F_104 ( struct V_53 * V_54 , struct V_137 * V_138 )
{
struct V_140 * V_141 , * V_155 ;
struct V_142 * V_143 = NULL , * V_156 = NULL ;
int V_131 = 0 ;
V_141 = F_94 ( V_138 -> V_144 ) ;
if ( V_141 == NULL ) {
F_95 ( L_20 , V_138 -> V_144 ) ;
return - V_134 ;
}
V_155 = V_141 ;
if ( V_138 -> V_146 && * V_138 -> V_146 ) {
V_143 = F_96 ( V_138 -> V_146 ) ;
if ( V_143 == NULL ) {
F_95 ( L_21
L_22 , V_138 -> V_146 ) ;
V_131 = - V_134 ;
goto V_67;
}
V_156 = V_143 ;
}
#ifdef F_23
if ( V_138 -> V_40 == V_47 && ( V_138 -> V_147 < 1 || V_138 -> V_147 > 128 ) ) {
V_131 = - V_121 ;
goto V_67;
}
#endif
F_73 ( & V_66 ) ;
F_76 ( F_14 ( & V_54 -> V_74 ) > 0 ) ;
V_54 -> V_12 = V_138 -> V_12 | V_56 ;
V_54 -> V_148 = V_138 -> V_148 * V_149 ;
V_54 -> V_147 = V_138 -> V_147 ;
V_155 = V_54 -> V_114 ;
if ( V_141 != V_155 ) {
if ( ( V_131 = F_100 ( V_54 ) ) ) {
V_155 = V_141 ;
goto V_157;
}
if ( ( V_131 = F_98 ( V_54 , V_141 ) ) ) {
F_98 ( V_54 , V_155 ) ;
V_155 = V_141 ;
goto V_157;
}
}
V_156 = V_54 -> V_143 ;
if ( V_143 != V_156 ) {
F_105 ( V_54 ) ;
F_99 ( V_54 , V_143 ) ;
}
V_157:
F_74 ( & V_66 ) ;
V_67:
F_102 ( V_155 ) ;
F_103 ( V_156 ) ;
return V_131 ;
}
static void F_106 ( struct V_53 * V_54 )
{
struct V_75 * V_76 , * V_88 ;
struct V_140 * V_155 ;
struct V_142 * V_156 ;
struct V_14 * V_15 = F_40 ( V_54 -> V_2 ) ;
F_95 ( L_24 , V_57 ) ;
if ( V_54 -> V_40 == V_151 )
V_15 -> V_152 -- ;
F_90 ( V_54 -> V_2 , & V_54 -> V_77 ) ;
V_155 = V_54 -> V_114 ;
F_100 ( V_54 ) ;
F_102 ( V_155 ) ;
V_156 = V_54 -> V_143 ;
F_105 ( V_54 ) ;
F_103 ( V_156 ) ;
if ( V_54 -> V_154 ) {
F_101 ( V_54 -> V_154 ) ;
V_54 -> V_154 = NULL ;
}
F_61 (dest, nxt, &svc->destinations, n_list) {
F_91 ( V_54 , V_76 , 0 ) ;
F_89 ( V_54 -> V_2 , V_76 ) ;
}
if ( V_54 -> V_43 == V_72 )
F_33 ( & V_15 -> V_69 ) ;
else if ( V_54 -> V_43 == 0 )
F_33 ( & V_15 -> V_73 ) ;
if ( F_14 ( & V_54 -> V_63 ) == 0 ) {
F_43 ( 3 , L_6 ,
V_54 -> V_52 ,
F_45 ( V_54 -> V_40 , & V_54 -> V_4 ) ,
F_22 ( V_54 -> V_43 ) , F_14 ( & V_54 -> V_74 ) ) ;
F_49 ( V_54 -> V_77 . V_78 ) ;
F_50 ( V_54 ) ;
}
F_19 () ;
}
static void F_107 ( struct V_53 * V_54 )
{
F_73 ( & V_66 ) ;
F_31 ( V_54 ) ;
F_76 ( F_14 ( & V_54 -> V_74 ) > 0 ) ;
F_106 ( V_54 ) ;
F_74 ( & V_66 ) ;
}
static int F_108 ( struct V_53 * V_54 )
{
if ( V_54 == NULL )
return - V_133 ;
F_107 ( V_54 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_53 * V_54 , * V_88 ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_61 (svc, nxt, &ip_vs_svc_table[idx],
s_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) )
F_107 ( V_54 ) ;
}
}
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_61 (svc, nxt,
&ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) )
F_107 ( V_54 ) ;
}
}
return 0 ;
}
void F_110 ( struct V_2 * V_2 )
{
F_78 ( 2 ) ;
F_111 ( & V_160 ) ;
F_109 ( V_2 ) ;
F_112 ( & V_160 ) ;
F_85 ( 2 ) ;
}
static inline void
F_113 ( struct V_75 * V_76 , struct V_161 * V_11 )
{
F_66 ( & V_76 -> V_111 ) ;
if ( V_76 -> V_162 && V_76 -> V_162 -> V_11 == V_11 ) {
F_43 ( 3 , L_25 ,
V_11 -> V_163 ,
F_45 ( V_76 -> V_40 , & V_76 -> V_4 ) ,
F_22 ( V_76 -> V_43 ) ,
F_14 ( & V_76 -> V_63 ) ) ;
F_62 ( V_76 ) ;
}
F_68 ( & V_76 -> V_111 ) ;
}
static int F_114 ( struct V_164 * V_165 , unsigned long V_166 ,
void * V_167 )
{
struct V_161 * V_11 = V_167 ;
struct V_2 * V_2 = F_115 ( V_11 ) ;
struct V_53 * V_54 ;
struct V_75 * V_76 ;
unsigned int V_158 ;
if ( V_166 != V_168 )
return V_169 ;
F_87 ( 3 , L_26 , V_57 , V_11 -> V_163 ) ;
F_78 ( 2 ) ;
F_111 ( & V_160 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) ) {
F_35 (dest, &svc->destinations,
n_list) {
F_113 ( V_76 , V_11 ) ;
}
}
}
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) ) {
F_35 (dest, &svc->destinations,
n_list) {
F_113 ( V_76 , V_11 ) ;
}
}
}
}
F_35 (dest, &net_ipvs(net)->dest_trash, n_list) {
F_113 ( V_76 , V_11 ) ;
}
F_112 ( & V_160 ) ;
F_85 ( 2 ) ;
return V_169 ;
}
static int F_116 ( struct V_53 * V_54 )
{
struct V_75 * V_76 ;
F_73 ( & V_66 ) ;
F_35 (dest, &svc->destinations, n_list) {
F_69 ( & V_76 -> V_77 ) ;
}
F_69 ( & V_54 -> V_77 ) ;
F_74 ( & V_66 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_53 * V_54 ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) )
F_116 ( V_54 ) ;
}
}
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) )
F_116 ( V_54 ) ;
}
}
F_69 ( & F_40 ( V_2 ) -> V_170 ) ;
return 0 ;
}
static int
F_118 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
struct V_2 * V_2 = V_176 -> V_177 -> V_178 ;
int * V_179 = V_171 -> V_180 ;
int V_181 = * V_179 ;
int V_182 ;
V_182 = F_119 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( * V_179 != V_181 ) ) {
if ( ( * V_179 < 0 ) || ( * V_179 > 3 ) ) {
* V_179 = V_181 ;
} else {
F_4 ( F_40 ( V_2 ) ) ;
}
}
return V_182 ;
}
static int
F_120 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
int * V_179 = V_171 -> V_180 ;
int V_181 [ 2 ] ;
int V_182 ;
memcpy ( V_181 , V_179 , sizeof( V_181 ) ) ;
V_182 = F_119 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( V_179 [ 0 ] < 0 || V_179 [ 1 ] < 0 || V_179 [ 0 ] >= V_179 [ 1 ] ) ) {
memcpy ( V_179 , V_181 , sizeof( V_181 ) ) ;
}
return V_182 ;
}
static int
F_121 ( T_6 * V_171 , int V_172 ,
void T_7 * V_173 , V_49 * V_174 , T_8 * V_175 )
{
int * V_179 = V_171 -> V_180 ;
int V_181 = * V_179 ;
int V_182 ;
V_182 = F_119 ( V_171 , V_172 , V_173 , V_174 , V_175 ) ;
if ( V_172 && ( * V_179 != V_181 ) ) {
if ( ( * V_179 < 0 ) || ( * V_179 > 1 ) ) {
* V_179 = V_181 ;
} else {
struct V_2 * V_2 = V_176 -> V_177 -> V_178 ;
F_122 ( V_2 , V_181 ) ;
}
}
return V_182 ;
}
static inline const char * F_123 ( unsigned V_12 )
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
static struct V_53 * F_124 ( struct V_186 * V_187 , T_8 V_188 )
{
struct V_2 * V_2 = F_125 ( V_187 ) ;
struct V_189 * V_190 = V_187 -> V_191 ;
int V_158 ;
struct V_53 * V_54 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) && V_188 -- == 0 ) {
V_190 -> V_171 = V_60 ;
V_190 -> V_192 = V_158 ;
return V_54 ;
}
}
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_54 -> V_2 , V_2 ) && V_188 -- == 0 ) {
V_190 -> V_171 = V_62 ;
V_190 -> V_192 = V_158 ;
return V_54 ;
}
}
}
return NULL ;
}
static void * F_126 ( struct V_186 * V_187 , T_8 * V_188 )
__acquires( V_66 )
{
F_127 ( & V_66 ) ;
return * V_188 ? F_124 ( V_187 , * V_188 - 1 ) : V_193 ;
}
static void * F_128 ( struct V_186 * V_187 , void * V_194 , T_8 * V_188 )
{
struct V_195 * V_196 ;
struct V_189 * V_190 ;
struct V_53 * V_54 ;
++ * V_188 ;
if ( V_194 == V_193 )
return F_124 ( V_187 , 0 ) ;
V_54 = V_194 ;
V_190 = V_187 -> V_191 ;
if ( V_190 -> V_171 == V_60 ) {
if ( ( V_196 = V_54 -> V_59 . V_197 ) != & V_60 [ V_190 -> V_192 ] )
return F_129 ( V_196 , struct V_53 , V_59 ) ;
while ( ++ V_190 -> V_192 < V_159 ) {
F_35 (svc,&ip_vs_svc_table[iter->bucket],
s_list) {
return V_54 ;
}
}
V_190 -> V_171 = V_62 ;
V_190 -> V_192 = - 1 ;
goto V_198;
}
if ( ( V_196 = V_54 -> V_61 . V_197 ) != & V_62 [ V_190 -> V_192 ] )
return F_129 ( V_196 , struct V_53 , V_61 ) ;
V_198:
while ( ++ V_190 -> V_192 < V_159 ) {
F_35 (svc, &ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_54 ;
}
return NULL ;
}
static void F_130 ( struct V_186 * V_187 , void * V_194 )
__releases( V_66 )
{
F_131 ( & V_66 ) ;
}
static int F_132 ( struct V_186 * V_187 , void * V_194 )
{
if ( V_194 == V_193 ) {
F_133 ( V_187 ,
L_31 ,
F_134 ( V_199 ) , V_200 ) ;
F_135 ( V_187 ,
L_32 ) ;
F_135 ( V_187 ,
L_33 ) ;
} else {
const struct V_53 * V_54 = V_194 ;
const struct V_189 * V_190 = V_187 -> V_191 ;
const struct V_75 * V_76 ;
if ( V_190 -> V_171 == V_60 ) {
#ifdef F_23
if ( V_54 -> V_40 == V_47 )
F_133 ( V_187 , L_34 ,
F_44 ( V_54 -> V_58 ) ,
& V_54 -> V_4 . V_118 ,
F_22 ( V_54 -> V_43 ) ,
V_54 -> V_114 -> V_163 ) ;
else
#endif
F_133 ( V_187 , L_35 ,
F_44 ( V_54 -> V_58 ) ,
F_24 ( V_54 -> V_4 . V_46 ) ,
F_22 ( V_54 -> V_43 ) ,
V_54 -> V_114 -> V_163 ,
( V_54 -> V_12 & V_201 ) ? L_36 : L_37 ) ;
} else {
F_133 ( V_187 , L_38 ,
V_54 -> V_52 , V_54 -> V_114 -> V_163 ,
( V_54 -> V_12 & V_201 ) ? L_36 : L_37 ) ;
}
if ( V_54 -> V_12 & V_202 )
F_133 ( V_187 , L_39 ,
V_54 -> V_148 ,
F_24 ( V_54 -> V_147 ) ) ;
else
F_136 ( V_187 , '\n' ) ;
F_35 (dest, &svc->destinations, n_list) {
#ifdef F_23
if ( V_76 -> V_40 == V_47 )
F_133 ( V_187 ,
L_40
L_41 ,
& V_76 -> V_4 . V_118 ,
F_22 ( V_76 -> V_43 ) ,
F_123 ( F_14 ( & V_76 -> V_102 ) ) ,
F_14 ( & V_76 -> V_103 ) ,
F_14 ( & V_76 -> V_128 ) ,
F_14 ( & V_76 -> V_129 ) ) ;
else
#endif
F_133 ( V_187 ,
L_42
L_43 ,
F_24 ( V_76 -> V_4 . V_46 ) ,
F_22 ( V_76 -> V_43 ) ,
F_123 ( F_14 ( & V_76 -> V_102 ) ) ,
F_14 ( & V_76 -> V_103 ) ,
F_14 ( & V_76 -> V_128 ) ,
F_14 ( & V_76 -> V_129 ) ) ;
}
}
return 0 ;
}
static int F_137 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_138 ( V_203 , V_204 , & V_205 ,
sizeof( struct V_189 ) ) ;
}
static int F_139 ( struct V_186 * V_187 , void * V_194 )
{
struct V_2 * V_2 = F_140 ( V_187 ) ;
struct V_90 V_206 ;
F_135 ( V_187 ,
L_44 ) ;
F_133 ( V_187 ,
L_45 ) ;
F_64 ( & V_206 , & F_40 ( V_2 ) -> V_170 ) ;
F_133 ( V_187 , L_46 , V_206 . V_94 ,
V_206 . V_95 , V_206 . V_96 ,
( unsigned long long ) V_206 . V_97 ,
( unsigned long long ) V_206 . V_98 ) ;
F_135 ( V_187 ,
L_47 ) ;
F_133 ( V_187 , L_48 ,
V_206 . V_207 , V_206 . V_208 , V_206 . V_209 ,
V_206 . V_210 , V_206 . V_211 ) ;
return 0 ;
}
static int F_141 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_142 ( V_203 , V_204 , F_139 ) ;
}
static int F_143 ( struct V_186 * V_187 , void * V_194 )
{
struct V_2 * V_2 = F_140 ( V_187 ) ;
struct V_91 * V_170 = & F_40 ( V_2 ) -> V_170 ;
struct V_126 * V_78 = V_170 -> V_78 ;
struct V_90 V_212 ;
int V_17 ;
F_135 ( V_187 ,
L_49 ) ;
F_133 ( V_187 ,
L_50 ) ;
F_144 (i) {
struct V_126 * V_138 = F_145 ( V_78 , V_17 ) ;
unsigned int V_213 ;
T_9 V_97 , V_98 ;
do {
V_213 = F_146 ( & V_138 -> V_214 ) ;
V_97 = V_138 -> V_215 . V_97 ;
V_98 = V_138 -> V_215 . V_98 ;
} while ( F_147 ( & V_138 -> V_214 , V_213 ) );
F_133 ( V_187 , L_51 ,
V_17 , V_138 -> V_215 . V_94 , V_138 -> V_215 . V_95 ,
V_138 -> V_215 . V_96 , ( T_9 ) V_97 ,
( T_9 ) V_98 ) ;
}
F_66 ( & V_170 -> V_93 ) ;
F_133 ( V_187 , L_52 ,
V_170 -> V_215 . V_94 , V_170 -> V_215 . V_95 ,
V_170 -> V_215 . V_96 ,
( unsigned long long ) V_170 -> V_215 . V_97 ,
( unsigned long long ) V_170 -> V_215 . V_98 ) ;
F_67 ( & V_212 , V_170 ) ;
F_68 ( & V_170 -> V_93 ) ;
F_135 ( V_187 ,
L_53 ) ;
F_133 ( V_187 , L_54 ,
V_212 . V_207 ,
V_212 . V_208 ,
V_212 . V_209 ,
V_212 . V_210 ,
V_212 . V_211 ) ;
return 0 ;
}
static int F_148 ( struct V_203 * V_203 , struct V_204 * V_204 )
{
return F_142 ( V_203 , V_204 , F_143 ) ;
}
static int F_149 ( struct V_2 * V_2 , struct V_216 * V_138 )
{
#if F_150 ( V_217 ) || F_150 ( V_218 )
struct V_219 * V_220 ;
#endif
F_87 ( 2 , L_55 ,
V_138 -> V_221 ,
V_138 -> V_222 ,
V_138 -> V_223 ) ;
#ifdef V_217
if ( V_138 -> V_221 ) {
V_220 = F_151 ( V_2 , V_68 ) ;
V_220 -> V_224 [ V_225 ]
= V_138 -> V_221 * V_149 ;
}
if ( V_138 -> V_222 ) {
V_220 = F_151 ( V_2 , V_68 ) ;
V_220 -> V_224 [ V_226 ]
= V_138 -> V_222 * V_149 ;
}
#endif
#ifdef V_218
if ( V_138 -> V_223 ) {
V_220 = F_151 ( V_2 , V_227 ) ;
V_220 -> V_224 [ V_228 ]
= V_138 -> V_223 * V_149 ;
}
#endif
return 0 ;
}
static void F_152 ( struct V_137 * V_229 ,
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
static void F_153 ( struct V_99 * V_100 ,
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
F_154 ( struct V_234 * V_235 , int V_236 , void T_7 * V_237 , unsigned int V_238 )
{
struct V_2 * V_2 = F_155 ( V_235 ) ;
int V_131 ;
unsigned char V_239 [ V_240 ] ;
struct V_230 * V_231 ;
struct V_137 V_229 ;
struct V_53 * V_54 ;
struct V_232 * V_233 ;
struct V_99 V_100 ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
if ( ! F_156 ( V_241 ) )
return - V_242 ;
if ( V_236 < V_243 || V_236 > V_244 )
return - V_121 ;
if ( V_238 < 0 || V_238 > V_240 )
return - V_121 ;
if ( V_238 != V_245 [ F_157 ( V_236 ) ] ) {
F_27 ( L_56 ,
V_238 , V_245 [ F_157 ( V_236 ) ] ) ;
return - V_121 ;
}
if ( F_158 ( V_239 , V_237 , V_238 ) != 0 )
return - V_246 ;
F_17 () ;
if ( V_236 == V_247 ||
V_236 == V_248 ) {
struct V_249 * V_250 = (struct V_249 * ) V_239 ;
if ( F_159 ( & V_15 -> V_251 ) ) {
V_131 = - V_252 ;
goto V_253;
}
if ( V_236 == V_247 )
V_131 = F_160 ( V_2 , V_250 -> V_254 , V_250 -> V_255 ,
V_250 -> V_256 ) ;
else
V_131 = F_161 ( V_2 , V_250 -> V_254 ) ;
F_112 ( & V_15 -> V_251 ) ;
goto V_253;
}
if ( F_159 ( & V_160 ) ) {
V_131 = - V_252 ;
goto V_253;
}
if ( V_236 == V_257 ) {
V_131 = F_109 ( V_2 ) ;
goto V_157;
} else if ( V_236 == V_258 ) {
V_131 = F_149 ( V_2 , (struct V_216 * ) V_239 ) ;
goto V_157;
}
V_231 = (struct V_230 * ) V_239 ;
V_233 = (struct V_232 * ) ( V_231 + 1 ) ;
F_152 ( & V_229 , V_231 ) ;
F_153 ( & V_100 , V_233 ) ;
if ( V_236 == V_259 ) {
if ( ! V_229 . V_52 && ! V_229 . V_4 . V_46 && ! V_229 . V_43 ) {
V_131 = F_117 ( V_2 ) ;
goto V_157;
}
}
if ( V_229 . V_58 != V_68 && V_229 . V_58 != V_227 &&
V_229 . V_58 != V_260 ) {
F_27 ( L_57 ,
V_229 . V_58 , & V_229 . V_4 . V_46 ,
F_22 ( V_229 . V_43 ) , V_229 . V_144 ) ;
V_131 = - V_246 ;
goto V_157;
}
if ( V_229 . V_52 == 0 )
V_54 = F_34 ( V_2 , V_229 . V_40 , V_229 . V_58 ,
& V_229 . V_4 , V_229 . V_43 ) ;
else
V_54 = F_38 ( V_2 , V_229 . V_40 , V_229 . V_52 ) ;
if ( V_236 != V_261
&& ( V_54 == NULL || V_54 -> V_58 != V_229 . V_58 ) ) {
V_131 = - V_262 ;
goto V_157;
}
switch ( V_236 ) {
case V_261 :
if ( V_54 != NULL )
V_131 = - V_133 ;
else
V_131 = F_93 ( V_2 , & V_229 , & V_54 ) ;
break;
case V_263 :
V_131 = F_104 ( V_54 , & V_229 ) ;
break;
case V_264 :
V_131 = F_108 ( V_54 ) ;
if ( ! V_131 )
goto V_157;
break;
case V_259 :
V_131 = F_116 ( V_54 ) ;
break;
case V_265 :
V_131 = F_86 ( V_54 , & V_100 ) ;
break;
case V_266 :
V_131 = F_88 ( V_54 , & V_100 ) ;
break;
case V_267 :
V_131 = F_92 ( V_54 , & V_100 ) ;
break;
default:
V_131 = - V_121 ;
}
V_157:
F_112 ( & V_160 ) ;
V_253:
F_19 () ;
return V_131 ;
}
static void
F_162 ( struct V_268 * V_10 , struct V_53 * V_92 )
{
V_10 -> V_58 = V_92 -> V_58 ;
V_10 -> V_4 = V_92 -> V_4 . V_46 ;
V_10 -> V_43 = V_92 -> V_43 ;
V_10 -> V_52 = V_92 -> V_52 ;
F_163 ( V_10 -> V_144 , V_92 -> V_114 -> V_163 , sizeof( V_10 -> V_144 ) ) ;
V_10 -> V_12 = V_92 -> V_12 ;
V_10 -> V_148 = V_92 -> V_148 / V_149 ;
V_10 -> V_147 = V_92 -> V_147 ;
V_10 -> V_113 = V_92 -> V_113 ;
F_64 ( & V_10 -> V_77 , & V_92 -> V_77 ) ;
}
static inline int
F_164 ( struct V_2 * V_2 ,
const struct V_269 * V_270 ,
struct V_269 T_7 * V_271 )
{
int V_158 , V_272 = 0 ;
struct V_53 * V_54 ;
struct V_268 V_273 ;
int V_131 = 0 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_54 -> V_40 != V_151 || ! F_37 ( V_54 -> V_2 , V_2 ) )
continue;
if ( V_272 >= V_270 -> V_152 )
goto V_67;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
F_162 ( & V_273 , V_54 ) ;
if ( F_165 ( & V_271 -> V_274 [ V_272 ] ,
& V_273 , sizeof( V_273 ) ) ) {
V_131 = - V_246 ;
goto V_67;
}
V_272 ++ ;
}
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_54 -> V_40 != V_151 || ! F_37 ( V_54 -> V_2 , V_2 ) )
continue;
if ( V_272 >= V_270 -> V_152 )
goto V_67;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
F_162 ( & V_273 , V_54 ) ;
if ( F_165 ( & V_271 -> V_274 [ V_272 ] ,
& V_273 , sizeof( V_273 ) ) ) {
V_131 = - V_246 ;
goto V_67;
}
V_272 ++ ;
}
}
V_67:
return V_131 ;
}
static inline int
F_166 ( struct V_2 * V_2 , const struct V_275 * V_270 ,
struct V_275 T_7 * V_271 )
{
struct V_53 * V_54 ;
union V_42 V_4 = { . V_46 = V_270 -> V_4 } ;
int V_131 = 0 ;
if ( V_270 -> V_52 )
V_54 = F_38 ( V_2 , V_151 , V_270 -> V_52 ) ;
else
V_54 = F_34 ( V_2 , V_151 , V_270 -> V_58 , & V_4 ,
V_270 -> V_43 ) ;
if ( V_54 ) {
int V_272 = 0 ;
struct V_75 * V_76 ;
struct V_276 V_273 ;
F_35 (dest, &svc->destinations, n_list) {
if ( V_272 >= V_270 -> V_113 )
break;
V_273 . V_4 = V_76 -> V_4 . V_46 ;
V_273 . V_43 = V_76 -> V_43 ;
V_273 . V_102 = F_14 ( & V_76 -> V_102 ) ;
V_273 . V_103 = F_14 ( & V_76 -> V_103 ) ;
V_273 . V_108 = V_76 -> V_108 ;
V_273 . V_110 = V_76 -> V_110 ;
V_273 . V_128 = F_14 ( & V_76 -> V_128 ) ;
V_273 . V_129 = F_14 ( & V_76 -> V_129 ) ;
V_273 . V_130 = F_14 ( & V_76 -> V_130 ) ;
F_64 ( & V_273 . V_77 , & V_76 -> V_77 ) ;
if ( F_165 ( & V_271 -> V_274 [ V_272 ] ,
& V_273 , sizeof( V_273 ) ) ) {
V_131 = - V_246 ;
break;
}
V_272 ++ ;
}
} else
V_131 = - V_262 ;
return V_131 ;
}
static inline void
F_167 ( struct V_2 * V_2 , struct V_216 * V_138 )
{
#if F_150 ( V_217 ) || F_150 ( V_218 )
struct V_219 * V_220 ;
#endif
#ifdef V_217
V_220 = F_151 ( V_2 , V_68 ) ;
V_138 -> V_221 = V_220 -> V_224 [ V_225 ] / V_149 ;
V_138 -> V_222 = V_220 -> V_224 [ V_226 ] / V_149 ;
#endif
#ifdef V_218
V_220 = F_151 ( V_2 , V_227 ) ;
V_138 -> V_223 =
V_220 -> V_224 [ V_228 ] / V_149 ;
#endif
}
static int
F_168 ( struct V_234 * V_235 , int V_236 , void T_7 * V_237 , int * V_238 )
{
unsigned char V_239 [ 128 ] ;
int V_131 = 0 ;
unsigned int V_277 ;
struct V_2 * V_2 = F_155 ( V_235 ) ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_169 ( ! V_2 ) ;
if ( ! F_156 ( V_241 ) )
return - V_242 ;
if ( V_236 < V_243 || V_236 > V_278 )
return - V_121 ;
if ( * V_238 < V_279 [ F_170 ( V_236 ) ] ) {
F_27 ( L_58 ,
* V_238 , V_279 [ F_170 ( V_236 ) ] ) ;
return - V_121 ;
}
V_277 = V_279 [ F_170 ( V_236 ) ] ;
if ( V_277 > 128 )
return - V_121 ;
if ( F_158 ( V_239 , V_237 , V_277 ) != 0 )
return - V_246 ;
if ( V_236 == V_280 ) {
struct V_249 V_281 [ 2 ] ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
if ( F_159 ( & V_15 -> V_251 ) )
return - V_252 ;
if ( V_15 -> V_282 & V_283 ) {
V_281 [ 0 ] . V_254 = V_283 ;
F_163 ( V_281 [ 0 ] . V_255 , V_15 -> V_284 ,
sizeof( V_281 [ 0 ] . V_255 ) ) ;
V_281 [ 0 ] . V_256 = V_15 -> V_285 ;
}
if ( V_15 -> V_282 & V_286 ) {
V_281 [ 1 ] . V_254 = V_286 ;
F_163 ( V_281 [ 1 ] . V_255 , V_15 -> V_287 ,
sizeof( V_281 [ 1 ] . V_255 ) ) ;
V_281 [ 1 ] . V_256 = V_15 -> V_288 ;
}
if ( F_165 ( V_237 , & V_281 , sizeof( V_281 ) ) != 0 )
V_131 = - V_246 ;
F_112 ( & V_15 -> V_251 ) ;
return V_131 ;
}
if ( F_159 ( & V_160 ) )
return - V_252 ;
switch ( V_236 ) {
case V_289 :
{
char V_290 [ 64 ] ;
sprintf ( V_290 , L_59 ,
F_134 ( V_199 ) , V_200 ) ;
if ( F_165 ( V_237 , V_290 , strlen ( V_290 ) + 1 ) != 0 ) {
V_131 = - V_246 ;
goto V_67;
}
* V_238 = strlen ( V_290 ) + 1 ;
}
break;
case V_291 :
{
struct V_292 V_293 ;
V_293 . V_294 = V_199 ;
V_293 . V_295 = V_200 ;
V_293 . V_152 = V_15 -> V_152 ;
if ( F_165 ( V_237 , & V_293 , sizeof( V_293 ) ) != 0 )
V_131 = - V_246 ;
}
break;
case V_296 :
{
struct V_269 * V_270 ;
int V_295 ;
V_270 = (struct V_269 * ) V_239 ;
V_295 = sizeof( * V_270 ) +
sizeof( struct V_268 ) * V_270 -> V_152 ;
if ( * V_238 != V_295 ) {
F_27 ( L_60 , * V_238 , V_295 ) ;
V_131 = - V_121 ;
goto V_67;
}
V_131 = F_164 ( V_2 , V_270 , V_237 ) ;
}
break;
case V_297 :
{
struct V_268 * V_273 ;
struct V_53 * V_54 ;
union V_42 V_4 ;
V_273 = (struct V_268 * ) V_239 ;
V_4 . V_46 = V_273 -> V_4 ;
if ( V_273 -> V_52 )
V_54 = F_38 ( V_2 , V_151 , V_273 -> V_52 ) ;
else
V_54 = F_34 ( V_2 , V_151 ,
V_273 -> V_58 , & V_4 ,
V_273 -> V_43 ) ;
if ( V_54 ) {
F_162 ( V_273 , V_54 ) ;
if ( F_165 ( V_237 , V_273 , sizeof( * V_273 ) ) != 0 )
V_131 = - V_246 ;
} else
V_131 = - V_262 ;
}
break;
case V_298 :
{
struct V_275 * V_270 ;
int V_295 ;
V_270 = (struct V_275 * ) V_239 ;
V_295 = sizeof( * V_270 ) +
sizeof( struct V_276 ) * V_270 -> V_113 ;
if ( * V_238 != V_295 ) {
F_27 ( L_60 , * V_238 , V_295 ) ;
V_131 = - V_121 ;
goto V_67;
}
V_131 = F_166 ( V_2 , V_270 , V_237 ) ;
}
break;
case V_299 :
{
struct V_216 V_300 ;
F_167 ( V_2 , & V_300 ) ;
if ( F_165 ( V_237 , & V_300 , sizeof( V_300 ) ) != 0 )
V_131 = - V_246 ;
}
break;
default:
V_131 = - V_121 ;
}
V_67:
F_112 ( & V_160 ) ;
return V_131 ;
}
static int F_171 ( struct V_301 * V_302 , int V_303 ,
struct V_91 * V_77 )
{
struct V_90 V_215 ;
struct V_304 * V_305 = F_172 ( V_302 , V_303 ) ;
if ( ! V_305 )
return - V_306 ;
F_64 ( & V_215 , V_77 ) ;
F_173 ( V_302 , V_307 , V_215 . V_94 ) ;
F_173 ( V_302 , V_308 , V_215 . V_95 ) ;
F_173 ( V_302 , V_309 , V_215 . V_96 ) ;
F_174 ( V_302 , V_310 , V_215 . V_97 ) ;
F_174 ( V_302 , V_311 , V_215 . V_98 ) ;
F_173 ( V_302 , V_312 , V_215 . V_207 ) ;
F_173 ( V_302 , V_313 , V_215 . V_208 ) ;
F_173 ( V_302 , V_314 , V_215 . V_209 ) ;
F_173 ( V_302 , V_315 , V_215 . V_210 ) ;
F_173 ( V_302 , V_316 , V_215 . V_211 ) ;
F_175 ( V_302 , V_305 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_305 ) ;
return - V_306 ;
}
static int F_177 ( struct V_301 * V_302 ,
struct V_53 * V_54 )
{
struct V_304 * V_318 ;
struct V_319 V_12 = { . V_12 = V_54 -> V_12 ,
. V_320 = ~ 0 } ;
V_318 = F_172 ( V_302 , V_321 ) ;
if ( ! V_318 )
return - V_306 ;
F_178 ( V_302 , V_322 , V_54 -> V_40 ) ;
if ( V_54 -> V_52 ) {
F_173 ( V_302 , V_323 , V_54 -> V_52 ) ;
} else {
F_178 ( V_302 , V_324 , V_54 -> V_58 ) ;
F_179 ( V_302 , V_325 , sizeof( V_54 -> V_4 ) , & V_54 -> V_4 ) ;
F_178 ( V_302 , V_326 , V_54 -> V_43 ) ;
}
F_180 ( V_302 , V_327 , V_54 -> V_114 -> V_163 ) ;
if ( V_54 -> V_143 )
F_180 ( V_302 , V_328 , V_54 -> V_143 -> V_163 ) ;
F_179 ( V_302 , V_329 , sizeof( V_12 ) , & V_12 ) ;
F_173 ( V_302 , V_330 , V_54 -> V_148 / V_149 ) ;
F_173 ( V_302 , V_331 , V_54 -> V_147 ) ;
if ( F_171 ( V_302 , V_332 , & V_54 -> V_77 ) )
goto V_317;
F_175 ( V_302 , V_318 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_318 ) ;
return - V_306 ;
}
static int F_181 ( struct V_301 * V_302 ,
struct V_53 * V_54 ,
struct V_333 * V_334 )
{
void * V_335 ;
V_335 = F_182 ( V_302 , F_183 ( V_334 -> V_302 ) . V_336 , V_334 -> V_337 -> V_338 ,
& V_339 , V_340 ,
V_341 ) ;
if ( ! V_335 )
return - V_306 ;
if ( F_177 ( V_302 , V_54 ) < 0 )
goto V_317;
return F_184 ( V_302 , V_335 ) ;
V_317:
F_185 ( V_302 , V_335 ) ;
return - V_306 ;
}
static int F_186 ( struct V_301 * V_302 ,
struct V_333 * V_334 )
{
int V_158 = 0 , V_17 ;
int V_213 = V_334 -> args [ 0 ] ;
struct V_53 * V_54 ;
struct V_2 * V_2 = F_187 ( V_302 ) ;
F_111 ( & V_160 ) ;
for ( V_17 = 0 ; V_17 < V_159 ; V_17 ++ ) {
F_35 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_158 <= V_213 || ! F_37 ( V_54 -> V_2 , V_2 ) )
continue;
if ( F_181 ( V_302 , V_54 , V_334 ) < 0 ) {
V_158 -- ;
goto V_317;
}
}
}
for ( V_17 = 0 ; V_17 < V_159 ; V_17 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_158 <= V_213 || ! F_37 ( V_54 -> V_2 , V_2 ) )
continue;
if ( F_181 ( V_302 , V_54 , V_334 ) < 0 ) {
V_158 -- ;
goto V_317;
}
}
}
V_317:
F_112 ( & V_160 ) ;
V_334 -> args [ 0 ] = V_158 ;
return V_302 -> V_238 ;
}
static int F_188 ( struct V_2 * V_2 ,
struct V_137 * V_229 ,
struct V_304 * V_342 , int V_343 ,
struct V_53 * * V_344 )
{
struct V_304 * V_345 [ V_346 + 1 ] ;
struct V_304 * V_347 , * V_348 , * V_349 , * V_350 , * V_351 ;
struct V_53 * V_54 ;
if ( V_342 == NULL ||
F_189 ( V_345 , V_346 , V_342 , V_352 ) )
return - V_121 ;
V_347 = V_345 [ V_322 ] ;
V_350 = V_345 [ V_324 ] ;
V_351 = V_345 [ V_325 ] ;
V_348 = V_345 [ V_326 ] ;
V_349 = V_345 [ V_323 ] ;
if ( ! ( V_347 && ( V_349 || ( V_348 && V_350 && V_351 ) ) ) )
return - V_121 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
V_229 -> V_40 = F_190 ( V_347 ) ;
#ifdef F_23
if ( V_229 -> V_40 != V_151 && V_229 -> V_40 != V_47 )
#else
if ( V_229 -> V_40 != V_151 )
#endif
return - V_353 ;
if ( V_349 ) {
V_229 -> V_58 = V_68 ;
V_229 -> V_52 = F_191 ( V_349 ) ;
} else {
V_229 -> V_58 = F_190 ( V_350 ) ;
F_192 ( & V_229 -> V_4 , V_351 , sizeof( V_229 -> V_4 ) ) ;
V_229 -> V_43 = F_190 ( V_348 ) ;
V_229 -> V_52 = 0 ;
}
if ( V_229 -> V_52 )
V_54 = F_38 ( V_2 , V_229 -> V_40 , V_229 -> V_52 ) ;
else
V_54 = F_34 ( V_2 , V_229 -> V_40 , V_229 -> V_58 ,
& V_229 -> V_4 , V_229 -> V_43 ) ;
* V_344 = V_54 ;
if ( V_343 ) {
struct V_304 * V_354 , * V_355 , * V_356 , * V_357 ,
* V_358 ;
struct V_319 V_12 ;
V_354 = V_345 [ V_327 ] ;
V_356 = V_345 [ V_328 ] ;
V_355 = V_345 [ V_329 ] ;
V_357 = V_345 [ V_330 ] ;
V_358 = V_345 [ V_331 ] ;
if ( ! ( V_354 && V_355 && V_357 && V_358 ) )
return - V_121 ;
F_192 ( & V_12 , V_355 , sizeof( V_12 ) ) ;
if ( V_54 )
V_229 -> V_12 = V_54 -> V_12 ;
V_229 -> V_12 = ( V_229 -> V_12 & ~ V_12 . V_320 ) |
( V_12 . V_12 & V_12 . V_320 ) ;
V_229 -> V_144 = F_193 ( V_354 ) ;
V_229 -> V_146 = V_356 ? F_193 ( V_356 ) : NULL ;
V_229 -> V_148 = F_191 ( V_357 ) ;
V_229 -> V_147 = F_191 ( V_358 ) ;
}
return 0 ;
}
static struct V_53 * F_194 ( struct V_2 * V_2 ,
struct V_304 * V_342 )
{
struct V_137 V_229 ;
struct V_53 * V_54 ;
int V_131 ;
V_131 = F_188 ( V_2 , & V_229 , V_342 , 0 , & V_54 ) ;
return V_131 ? F_195 ( V_131 ) : V_54 ;
}
static int F_196 ( struct V_301 * V_302 , struct V_75 * V_76 )
{
struct V_304 * V_359 ;
V_359 = F_172 ( V_302 , V_360 ) ;
if ( ! V_359 )
return - V_306 ;
F_179 ( V_302 , V_361 , sizeof( V_76 -> V_4 ) , & V_76 -> V_4 ) ;
F_178 ( V_302 , V_362 , V_76 -> V_43 ) ;
F_173 ( V_302 , V_363 ,
F_14 ( & V_76 -> V_102 ) & V_86 ) ;
F_173 ( V_302 , V_364 , F_14 ( & V_76 -> V_103 ) ) ;
F_173 ( V_302 , V_365 , V_76 -> V_108 ) ;
F_173 ( V_302 , V_366 , V_76 -> V_110 ) ;
F_173 ( V_302 , V_367 ,
F_14 ( & V_76 -> V_128 ) ) ;
F_173 ( V_302 , V_368 ,
F_14 ( & V_76 -> V_129 ) ) ;
F_173 ( V_302 , V_369 ,
F_14 ( & V_76 -> V_130 ) ) ;
if ( F_171 ( V_302 , V_370 , & V_76 -> V_77 ) )
goto V_317;
F_175 ( V_302 , V_359 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_359 ) ;
return - V_306 ;
}
static int F_197 ( struct V_301 * V_302 , struct V_75 * V_76 ,
struct V_333 * V_334 )
{
void * V_335 ;
V_335 = F_182 ( V_302 , F_183 ( V_334 -> V_302 ) . V_336 , V_334 -> V_337 -> V_338 ,
& V_339 , V_340 ,
V_371 ) ;
if ( ! V_335 )
return - V_306 ;
if ( F_196 ( V_302 , V_76 ) < 0 )
goto V_317;
return F_184 ( V_302 , V_335 ) ;
V_317:
F_185 ( V_302 , V_335 ) ;
return - V_306 ;
}
static int F_198 ( struct V_301 * V_302 ,
struct V_333 * V_334 )
{
int V_158 = 0 ;
int V_213 = V_334 -> args [ 0 ] ;
struct V_53 * V_54 ;
struct V_75 * V_76 ;
struct V_304 * V_345 [ V_372 + 1 ] ;
struct V_2 * V_2 = F_187 ( V_302 ) ;
F_111 ( & V_160 ) ;
if ( F_199 ( V_334 -> V_337 , V_373 , V_345 ,
V_372 , V_374 ) )
goto V_145;
V_54 = F_194 ( V_2 , V_345 [ V_321 ] ) ;
if ( F_200 ( V_54 ) || V_54 == NULL )
goto V_145;
F_35 (dest, &svc->destinations, n_list) {
if ( ++ V_158 <= V_213 )
continue;
if ( F_197 ( V_302 , V_76 , V_334 ) < 0 ) {
V_158 -- ;
goto V_317;
}
}
V_317:
V_334 -> args [ 0 ] = V_158 ;
V_145:
F_112 ( & V_160 ) ;
return V_302 -> V_238 ;
}
static int F_201 ( struct V_99 * V_100 ,
struct V_304 * V_342 , int V_343 )
{
struct V_304 * V_345 [ V_375 + 1 ] ;
struct V_304 * V_351 , * V_348 ;
if ( V_342 == NULL ||
F_189 ( V_345 , V_375 , V_342 , V_376 ) )
return - V_121 ;
V_351 = V_345 [ V_361 ] ;
V_348 = V_345 [ V_362 ] ;
if ( ! ( V_351 && V_348 ) )
return - V_121 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
F_192 ( & V_100 -> V_4 , V_351 , sizeof( V_100 -> V_4 ) ) ;
V_100 -> V_43 = F_190 ( V_348 ) ;
if ( V_343 ) {
struct V_304 * V_377 , * V_378 , * V_379 ,
* V_380 ;
V_377 = V_345 [ V_363 ] ;
V_378 = V_345 [ V_364 ] ;
V_379 = V_345 [ V_365 ] ;
V_380 = V_345 [ V_366 ] ;
if ( ! ( V_377 && V_378 && V_379 && V_380 ) )
return - V_121 ;
V_100 -> V_102 = F_191 ( V_377 )
& V_86 ;
V_100 -> V_103 = F_191 ( V_378 ) ;
V_100 -> V_108 = F_191 ( V_379 ) ;
V_100 -> V_110 = F_191 ( V_380 ) ;
}
return 0 ;
}
static int F_202 ( struct V_301 * V_302 , T_2 V_254 ,
const char * V_255 , T_2 V_256 )
{
struct V_304 * V_381 ;
V_381 = F_172 ( V_302 , V_382 ) ;
if ( ! V_381 )
return - V_306 ;
F_173 ( V_302 , V_383 , V_254 ) ;
F_180 ( V_302 , V_384 , V_255 ) ;
F_173 ( V_302 , V_385 , V_256 ) ;
F_175 ( V_302 , V_381 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_381 ) ;
return - V_306 ;
}
static int F_203 ( struct V_301 * V_302 , T_2 V_254 ,
const char * V_255 , T_2 V_256 ,
struct V_333 * V_334 )
{
void * V_335 ;
V_335 = F_182 ( V_302 , F_183 ( V_334 -> V_302 ) . V_336 , V_334 -> V_337 -> V_338 ,
& V_339 , V_340 ,
V_386 ) ;
if ( ! V_335 )
return - V_306 ;
if ( F_202 ( V_302 , V_254 , V_255 , V_256 ) )
goto V_317;
return F_184 ( V_302 , V_335 ) ;
V_317:
F_185 ( V_302 , V_335 ) ;
return - V_306 ;
}
static int F_204 ( struct V_301 * V_302 ,
struct V_333 * V_334 )
{
struct V_2 * V_2 = F_187 ( V_302 ) ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_111 ( & V_15 -> V_251 ) ;
if ( ( V_15 -> V_282 & V_283 ) && ! V_334 -> args [ 0 ] ) {
if ( F_203 ( V_302 , V_283 ,
V_15 -> V_284 ,
V_15 -> V_285 , V_334 ) < 0 )
goto V_317;
V_334 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_282 & V_286 ) && ! V_334 -> args [ 1 ] ) {
if ( F_203 ( V_302 , V_286 ,
V_15 -> V_287 ,
V_15 -> V_288 , V_334 ) < 0 )
goto V_317;
V_334 -> args [ 1 ] = 1 ;
}
V_317:
F_112 ( & V_15 -> V_251 ) ;
return V_302 -> V_238 ;
}
static int F_205 ( struct V_2 * V_2 , struct V_304 * * V_345 )
{
if ( ! ( V_345 [ V_383 ] &&
V_345 [ V_384 ] &&
V_345 [ V_385 ] ) )
return - V_121 ;
return F_160 ( V_2 ,
F_191 ( V_345 [ V_383 ] ) ,
F_193 ( V_345 [ V_384 ] ) ,
F_191 ( V_345 [ V_385 ] ) ) ;
}
static int F_206 ( struct V_2 * V_2 , struct V_304 * * V_345 )
{
if ( ! V_345 [ V_383 ] )
return - V_121 ;
return F_161 ( V_2 ,
F_191 ( V_345 [ V_383 ] ) ) ;
}
static int F_207 ( struct V_2 * V_2 , struct V_304 * * V_345 )
{
struct V_216 V_300 ;
F_167 ( V_2 , & V_300 ) ;
if ( V_345 [ V_387 ] )
V_300 . V_221 = F_191 ( V_345 [ V_387 ] ) ;
if ( V_345 [ V_388 ] )
V_300 . V_222 =
F_191 ( V_345 [ V_388 ] ) ;
if ( V_345 [ V_389 ] )
V_300 . V_223 = F_191 ( V_345 [ V_389 ] ) ;
return F_149 ( V_2 , & V_300 ) ;
}
static int F_208 ( struct V_301 * V_302 , struct V_390 * V_293 )
{
int V_131 = 0 , V_236 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_187 ( V_302 ) ;
V_15 = F_40 ( V_2 ) ;
V_236 = V_293 -> V_391 -> V_236 ;
if ( V_236 == V_386 || V_236 == V_392 ) {
struct V_304 * V_393 [ V_394 + 1 ] ;
F_111 ( & V_15 -> V_251 ) ;
if ( ! V_293 -> V_345 [ V_382 ] ||
F_189 ( V_393 , V_394 ,
V_293 -> V_345 [ V_382 ] ,
V_395 ) ) {
V_131 = - V_121 ;
goto V_67;
}
if ( V_236 == V_386 )
V_131 = F_205 ( V_2 , V_393 ) ;
else
V_131 = F_206 ( V_2 , V_393 ) ;
V_67:
F_112 ( & V_15 -> V_251 ) ;
}
return V_131 ;
}
static int F_209 ( struct V_301 * V_302 , struct V_390 * V_293 )
{
struct V_53 * V_54 = NULL ;
struct V_137 V_229 ;
struct V_99 V_100 ;
int V_131 = 0 , V_236 ;
int V_396 = 0 , V_397 = 0 ;
struct V_2 * V_2 ;
V_2 = F_187 ( V_302 ) ;
V_236 = V_293 -> V_391 -> V_236 ;
F_111 ( & V_160 ) ;
if ( V_236 == V_398 ) {
V_131 = F_109 ( V_2 ) ;
goto V_67;
} else if ( V_236 == V_399 ) {
V_131 = F_207 ( V_2 , V_293 -> V_345 ) ;
goto V_67;
} else if ( V_236 == V_400 &&
! V_293 -> V_345 [ V_321 ] ) {
V_131 = F_117 ( V_2 ) ;
goto V_67;
}
if ( V_236 == V_341 || V_236 == V_401 )
V_396 = 1 ;
V_131 = F_188 ( V_2 , & V_229 ,
V_293 -> V_345 [ V_321 ] ,
V_396 , & V_54 ) ;
if ( V_131 )
goto V_67;
if ( ( V_236 != V_341 ) && ( V_54 == NULL ) ) {
V_131 = - V_262 ;
goto V_67;
}
if ( V_236 == V_371 || V_236 == V_402 ||
V_236 == V_403 ) {
if ( V_236 != V_403 )
V_397 = 1 ;
V_131 = F_201 ( & V_100 ,
V_293 -> V_345 [ V_360 ] ,
V_397 ) ;
if ( V_131 )
goto V_67;
}
switch ( V_236 ) {
case V_341 :
if ( V_54 == NULL )
V_131 = F_93 ( V_2 , & V_229 , & V_54 ) ;
else
V_131 = - V_133 ;
break;
case V_401 :
V_131 = F_104 ( V_54 , & V_229 ) ;
break;
case V_404 :
V_131 = F_108 ( V_54 ) ;
break;
case V_371 :
V_131 = F_86 ( V_54 , & V_100 ) ;
break;
case V_402 :
V_131 = F_88 ( V_54 , & V_100 ) ;
break;
case V_403 :
V_131 = F_92 ( V_54 , & V_100 ) ;
break;
case V_400 :
V_131 = F_116 ( V_54 ) ;
break;
default:
V_131 = - V_121 ;
}
V_67:
F_112 ( & V_160 ) ;
return V_131 ;
}
static int F_210 ( struct V_301 * V_302 , struct V_390 * V_293 )
{
struct V_301 * V_405 ;
void * V_406 ;
int V_131 , V_236 , V_407 ;
struct V_2 * V_2 ;
V_2 = F_187 ( V_302 ) ;
V_236 = V_293 -> V_391 -> V_236 ;
if ( V_236 == V_408 )
V_407 = V_341 ;
else if ( V_236 == V_409 )
V_407 = V_410 ;
else if ( V_236 == V_411 )
V_407 = V_399 ;
else {
F_27 ( L_61 ) ;
return - V_121 ;
}
V_405 = F_211 ( V_412 , V_124 ) ;
if ( ! V_405 )
return - V_125 ;
F_111 ( & V_160 ) ;
V_406 = F_212 ( V_405 , V_293 , & V_339 , 0 , V_407 ) ;
if ( V_406 == NULL )
goto V_317;
switch ( V_236 ) {
case V_408 :
{
struct V_53 * V_54 ;
V_54 = F_194 ( V_2 ,
V_293 -> V_345 [ V_321 ] ) ;
if ( F_200 ( V_54 ) ) {
V_131 = F_213 ( V_54 ) ;
goto V_145;
} else if ( V_54 ) {
V_131 = F_177 ( V_405 , V_54 ) ;
if ( V_131 )
goto V_317;
} else {
V_131 = - V_262 ;
goto V_145;
}
break;
}
case V_411 :
{
struct V_216 V_300 ;
F_167 ( V_2 , & V_300 ) ;
#ifdef V_217
F_173 ( V_405 , V_387 , V_300 . V_221 ) ;
F_173 ( V_405 , V_388 ,
V_300 . V_222 ) ;
#endif
#ifdef V_218
F_173 ( V_405 , V_389 , V_300 . V_223 ) ;
#endif
break;
}
case V_409 :
F_173 ( V_405 , V_413 , V_199 ) ;
F_173 ( V_405 , V_414 ,
V_200 ) ;
break;
}
F_184 ( V_405 , V_406 ) ;
V_131 = F_214 ( V_405 , V_293 ) ;
goto V_67;
V_317:
F_27 ( L_62 ) ;
V_131 = - V_306 ;
V_145:
F_215 ( V_405 ) ;
V_67:
F_112 ( & V_160 ) ;
return V_131 ;
}
static int T_10 F_216 ( void )
{
return F_217 ( & V_339 ,
V_415 , F_218 ( V_415 ) ) ;
}
static void F_219 ( void )
{
F_220 ( & V_339 ) ;
}
int T_11 F_221 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
struct T_6 * V_416 ;
F_8 ( & V_15 -> V_27 , 0 ) ;
F_84 ( & V_15 -> V_25 ) ;
F_84 ( & V_15 -> V_28 ) ;
F_84 ( & V_15 -> V_33 ) ;
if ( ! F_37 ( V_2 , & V_417 ) ) {
V_416 = F_222 ( V_418 , sizeof( V_418 ) , V_124 ) ;
if ( V_416 == NULL )
return - V_125 ;
} else
V_416 = V_418 ;
V_158 = 0 ;
V_15 -> V_24 = 1024 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_32 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_26 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_29 ;
#ifdef F_223
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_419 ;
#endif
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_34 ;
V_15 -> V_420 = 1 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_420 ;
V_15 -> V_421 = 1 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_421 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_422 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_423 ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_424 ;
V_15 -> V_425 [ 0 ] = V_426 ;
V_15 -> V_425 [ 1 ] = V_427 ;
V_416 [ V_158 ] . V_180 = & V_15 -> V_425 ;
V_416 [ V_158 ++ ] . V_428 = sizeof( V_15 -> V_425 ) ;
V_416 [ V_158 ++ ] . V_180 = & V_15 -> V_429 ;
V_15 -> V_430 = F_224 ( V_2 , V_431 ,
V_416 ) ;
if ( V_15 -> V_430 == NULL ) {
if ( ! F_37 ( V_2 , & V_417 ) )
F_50 ( V_416 ) ;
return - V_125 ;
}
F_75 ( V_2 , & V_15 -> V_170 ) ;
V_15 -> V_432 = V_416 ;
F_225 ( & V_15 -> V_37 , F_12 ) ;
F_16 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
void T_11 F_226 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_227 ( & V_15 -> V_37 ) ;
F_228 ( & V_15 -> V_37 . V_36 ) ;
F_229 ( V_15 -> V_430 ) ;
}
int T_11 F_221 ( struct V_2 * V_2 ) { return 0 ; }
void T_11 F_226 ( struct V_2 * V_2 ) { }
int T_11 F_230 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_97 ( & V_15 -> V_84 ) ;
for ( V_158 = 0 ; V_158 < V_433 ; V_158 ++ )
F_55 ( & V_15 -> V_82 [ V_158 ] ) ;
F_55 ( & V_15 -> V_135 ) ;
F_8 ( & V_15 -> V_69 , 0 ) ;
F_8 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_170 . V_78 = F_82 ( struct V_126 ) ;
if ( ! V_15 -> V_170 . V_78 )
return - V_125 ;
F_84 ( & V_15 -> V_170 . V_93 ) ;
F_231 ( V_2 , L_63 , 0 , & V_434 ) ;
F_231 ( V_2 , L_64 , 0 , & V_435 ) ;
F_231 ( V_2 , L_65 , 0 ,
& V_436 ) ;
if ( F_221 ( V_2 ) )
goto V_437;
return 0 ;
V_437:
F_49 ( V_15 -> V_170 . V_78 ) ;
return - V_125 ;
}
void T_12 F_232 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_40 ( V_2 ) ;
F_63 ( V_2 ) ;
F_90 ( V_2 , & V_15 -> V_170 ) ;
F_226 ( V_2 ) ;
F_233 ( V_2 , L_65 ) ;
F_233 ( V_2 , L_64 ) ;
F_233 ( V_2 , L_63 ) ;
F_49 ( V_15 -> V_170 . V_78 ) ;
}
int T_10 F_234 ( void )
{
int V_158 ;
int V_131 ;
F_78 ( 2 ) ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_55 ( & V_60 [ V_158 ] ) ;
F_55 ( & V_62 [ V_158 ] ) ;
}
F_235 () ;
V_131 = F_236 ( & V_438 ) ;
if ( V_131 ) {
F_27 ( L_66 ) ;
goto V_439;
}
V_131 = F_216 () ;
if ( V_131 ) {
F_27 ( L_67 ) ;
goto V_440;
}
V_131 = F_237 ( & V_441 ) ;
if ( V_131 < 0 )
goto V_442;
F_85 ( 2 ) ;
return 0 ;
V_442:
F_219 () ;
V_440:
F_238 ( & V_438 ) ;
V_439:
return V_131 ;
}
void F_239 ( void )
{
F_78 ( 2 ) ;
F_240 ( & V_441 ) ;
F_219 () ;
F_238 ( & V_438 ) ;
F_85 ( 2 ) ;
}
