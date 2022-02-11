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
if ( V_6 && V_6 -> V_10 && ( V_6 -> V_10 -> V_11 & V_12 ) )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_15 V_16 ;
static int V_17 = 0 ;
int V_18 ;
int V_19 ;
int V_20 = - 1 ;
F_5 ( & V_16 ) ;
V_18 = V_16 . V_21 + V_16 . V_22 ;
V_19 = ( V_18 < V_14 -> V_23 ) ;
F_6 () ;
F_7 ( & V_14 -> V_24 ) ;
switch ( V_14 -> V_25 ) {
case 0 :
F_8 ( & V_14 -> V_26 , 0 ) ;
break;
case 1 :
if ( V_19 ) {
F_8 ( & V_14 -> V_26 , 1 ) ;
V_14 -> V_25 = 2 ;
} else {
F_8 ( & V_14 -> V_26 , 0 ) ;
}
break;
case 2 :
if ( V_19 ) {
F_8 ( & V_14 -> V_26 , 1 ) ;
} else {
F_8 ( & V_14 -> V_26 , 0 ) ;
V_14 -> V_25 = 1 ;
} ;
break;
case 3 :
F_8 ( & V_14 -> V_26 , 1 ) ;
break;
}
F_9 ( & V_14 -> V_24 ) ;
F_7 ( & V_14 -> V_27 ) ;
switch ( V_14 -> V_28 ) {
case 0 :
V_14 -> V_29 = 0 ;
break;
case 1 :
if ( V_19 ) {
V_14 -> V_29 = V_14 -> V_30
= V_14 -> V_23 /
( V_14 -> V_23 - V_18 ) ;
V_14 -> V_28 = 2 ;
} else {
V_14 -> V_29 = 0 ;
}
break;
case 2 :
if ( V_19 ) {
V_14 -> V_29 = V_14 -> V_30
= V_14 -> V_23 /
( V_14 -> V_23 - V_18 ) ;
} else {
V_14 -> V_29 = 0 ;
V_14 -> V_28 = 1 ;
}
break;
case 3 :
V_14 -> V_29 = V_14 -> V_31 ;
break;
}
F_9 ( & V_14 -> V_27 ) ;
F_7 ( & V_14 -> V_32 ) ;
switch ( V_14 -> V_33 ) {
case 0 :
if ( V_17 >= 2 )
V_20 = 0 ;
break;
case 1 :
if ( V_19 ) {
if ( V_17 < 2 )
V_20 = 1 ;
V_14 -> V_33 = 2 ;
} else {
if ( V_17 >= 2 )
V_20 = 0 ;
}
break;
case 2 :
if ( V_19 ) {
if ( V_17 < 2 )
V_20 = 1 ;
} else {
if ( V_17 >= 2 )
V_20 = 0 ;
V_14 -> V_33 = 1 ;
}
break;
case 3 :
if ( V_17 < 2 )
V_20 = 1 ;
break;
}
V_17 = V_14 -> V_33 ;
if ( V_20 >= 0 )
F_10 ( V_14 ,
V_14 -> V_33 > 1 ) ;
F_9 ( & V_14 -> V_32 ) ;
F_11 () ;
}
static void F_12 ( struct V_34 * V_35 )
{
struct V_13 * V_14 =
F_13 ( V_35 , struct V_13 , V_36 . V_35 ) ;
F_4 ( V_14 ) ;
if ( F_14 ( & V_14 -> V_26 ) )
F_15 ( V_14 -> V_2 ) ;
F_16 ( & V_14 -> V_36 , V_37 ) ;
}
int
F_17 ( void )
{
return F_18 ( V_38 ) ;
}
void
F_19 ( void )
{
F_20 ( V_38 ) ;
}
static inline unsigned
F_21 ( struct V_2 * V_2 , int V_39 , unsigned V_40 ,
const union V_41 * V_4 , T_1 V_42 )
{
register unsigned V_43 = F_22 ( V_42 ) ;
T_2 V_44 = V_4 -> V_45 ;
#ifdef F_23
if ( V_39 == V_46 )
V_44 = V_4 -> V_47 [ 0 ] ^ V_4 -> V_47 [ 1 ] ^
V_4 -> V_47 [ 2 ] ^ V_4 -> V_47 [ 3 ] ;
#endif
V_44 ^= ( ( V_48 ) V_2 >> 8 ) ;
return ( V_40 ^ F_24 ( V_44 ) ^ ( V_43 >> V_49 ) ^ V_43 )
& V_50 ;
}
static inline unsigned F_25 ( struct V_2 * V_2 , T_3 V_51 )
{
return ( ( ( V_48 ) V_2 >> 8 ) ^ V_51 ) & V_50 ;
}
static int F_26 ( struct V_52 * V_53 )
{
unsigned V_54 ;
if ( V_53 -> V_11 & V_55 ) {
F_27 ( L_1 ,
V_56 , F_28 ( 0 ) ) ;
return 0 ;
}
if ( V_53 -> V_51 == 0 ) {
V_54 = F_21 ( V_53 -> V_2 , V_53 -> V_39 , V_53 -> V_57 ,
& V_53 -> V_4 , V_53 -> V_42 ) ;
F_29 ( & V_53 -> V_58 , & V_59 [ V_54 ] ) ;
} else {
V_54 = F_25 ( V_53 -> V_2 , V_53 -> V_51 ) ;
F_29 ( & V_53 -> V_60 , & V_61 [ V_54 ] ) ;
}
V_53 -> V_11 |= V_55 ;
F_30 ( & V_53 -> V_62 ) ;
return 1 ;
}
static int F_31 ( struct V_52 * V_53 )
{
if ( ! ( V_53 -> V_11 & V_55 ) ) {
F_27 ( L_2 ,
V_56 , F_28 ( 0 ) ) ;
return 0 ;
}
if ( V_53 -> V_51 == 0 ) {
F_32 ( & V_53 -> V_58 ) ;
} else {
F_32 ( & V_53 -> V_60 ) ;
}
V_53 -> V_11 &= ~ V_55 ;
F_33 ( & V_53 -> V_62 ) ;
return 1 ;
}
static inline struct V_52 *
F_34 ( struct V_2 * V_2 , int V_39 , T_4 V_57 ,
const union V_41 * V_63 , T_1 V_64 )
{
unsigned V_54 ;
struct V_52 * V_53 ;
V_54 = F_21 ( V_2 , V_39 , V_57 , V_63 , V_64 ) ;
F_35 (svc, &ip_vs_svc_table[hash], s_list) {
if ( ( V_53 -> V_39 == V_39 )
&& F_36 ( V_39 , & V_53 -> V_4 , V_63 )
&& ( V_53 -> V_42 == V_64 )
&& ( V_53 -> V_57 == V_57 )
&& F_37 ( V_53 -> V_2 , V_2 ) ) {
return V_53 ;
}
}
return NULL ;
}
static inline struct V_52 *
F_38 ( struct V_2 * V_2 , int V_39 , T_3 V_51 )
{
unsigned V_54 ;
struct V_52 * V_53 ;
V_54 = F_25 ( V_2 , V_51 ) ;
F_35 (svc, &ip_vs_svc_fwm_table[hash], f_list) {
if ( V_53 -> V_51 == V_51 && V_53 -> V_39 == V_39
&& F_37 ( V_53 -> V_2 , V_2 ) ) {
return V_53 ;
}
}
return NULL ;
}
struct V_52 *
F_39 ( struct V_2 * V_2 , int V_39 , T_3 V_51 , T_4 V_57 ,
const union V_41 * V_63 , T_1 V_64 )
{
struct V_52 * V_53 ;
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_41 ( & V_65 ) ;
if ( V_51 ) {
V_53 = F_38 ( V_2 , V_39 , V_51 ) ;
if ( V_53 )
goto V_66;
}
V_53 = F_34 ( V_2 , V_39 , V_57 , V_63 , V_64 ) ;
if ( V_53 == NULL
&& V_57 == V_67
&& F_14 ( & V_14 -> V_68 )
&& ( V_64 == V_69 || F_22 ( V_64 ) >= V_70 ) ) {
V_53 = F_34 ( V_2 , V_39 , V_57 , V_63 , V_71 ) ;
}
if ( V_53 == NULL
&& F_14 ( & V_14 -> V_72 ) ) {
V_53 = F_34 ( V_2 , V_39 , V_57 , V_63 , 0 ) ;
}
V_66:
if ( V_53 )
F_30 ( & V_53 -> V_73 ) ;
F_42 ( & V_65 ) ;
F_43 ( 9 , L_3 ,
V_51 , F_44 ( V_57 ) ,
F_45 ( V_39 , V_63 ) , F_22 ( V_64 ) ,
V_53 ? L_4 : L_5 ) ;
return V_53 ;
}
static inline void
F_46 ( struct V_74 * V_75 , struct V_52 * V_53 )
{
F_30 ( & V_53 -> V_62 ) ;
V_75 -> V_53 = V_53 ;
}
static void
F_47 ( struct V_74 * V_75 )
{
struct V_52 * V_53 = V_75 -> V_53 ;
V_75 -> V_53 = NULL ;
if ( F_48 ( & V_53 -> V_62 ) ) {
F_43 ( 3 , L_6 ,
V_53 -> V_51 ,
F_45 ( V_53 -> V_39 , & V_53 -> V_4 ) ,
F_22 ( V_53 -> V_42 ) , F_14 ( & V_53 -> V_73 ) ) ;
F_49 ( V_53 -> V_76 . V_77 ) ;
F_50 ( V_53 ) ;
}
}
static inline unsigned F_51 ( int V_39 ,
const union V_41 * V_4 ,
T_1 V_42 )
{
register unsigned V_43 = F_22 ( V_42 ) ;
T_2 V_44 = V_4 -> V_45 ;
#ifdef F_23
if ( V_39 == V_46 )
V_44 = V_4 -> V_47 [ 0 ] ^ V_4 -> V_47 [ 1 ] ^
V_4 -> V_47 [ 2 ] ^ V_4 -> V_47 [ 3 ] ;
#endif
return ( F_24 ( V_44 ) ^ ( V_43 >> V_78 ) ^ V_43 )
& V_79 ;
}
static int F_52 ( struct V_13 * V_14 , struct V_74 * V_75 )
{
unsigned V_54 ;
if ( ! F_53 ( & V_75 -> V_80 ) ) {
return 0 ;
}
V_54 = F_51 ( V_75 -> V_39 , & V_75 -> V_4 , V_75 -> V_42 ) ;
F_29 ( & V_75 -> V_80 , & V_14 -> V_81 [ V_54 ] ) ;
return 1 ;
}
static int F_54 ( struct V_74 * V_75 )
{
if ( ! F_53 ( & V_75 -> V_80 ) ) {
F_32 ( & V_75 -> V_80 ) ;
F_55 ( & V_75 -> V_80 ) ;
}
return 1 ;
}
struct V_74 *
F_56 ( struct V_2 * V_2 , int V_39 , T_4 V_57 ,
const union V_41 * V_9 ,
T_1 V_82 )
{
struct V_13 * V_14 = F_40 ( V_2 ) ;
unsigned V_54 ;
struct V_74 * V_75 ;
V_54 = F_51 ( V_39 , V_9 , V_82 ) ;
F_41 ( & V_14 -> V_83 ) ;
F_35 (dest, &ipvs->rs_table[hash], d_list) {
if ( ( V_75 -> V_39 == V_39 )
&& F_36 ( V_39 , & V_75 -> V_4 , V_9 )
&& ( V_75 -> V_42 == V_82 )
&& ( ( V_75 -> V_57 == V_57 ) ||
V_75 -> V_84 ) ) {
F_42 ( & V_14 -> V_83 ) ;
return V_75 ;
}
}
F_42 ( & V_14 -> V_83 ) ;
return NULL ;
}
static struct V_74 *
F_57 ( struct V_52 * V_53 , const union V_41 * V_9 ,
T_1 V_82 )
{
struct V_74 * V_75 ;
F_35 (dest, &svc->destinations, n_list) {
if ( ( V_75 -> V_39 == V_53 -> V_39 )
&& F_36 ( V_53 -> V_39 , & V_75 -> V_4 , V_9 )
&& ( V_75 -> V_42 == V_82 ) ) {
return V_75 ;
}
}
return NULL ;
}
struct V_74 * F_58 ( struct V_2 * V_2 , int V_39 ,
const union V_41 * V_9 ,
T_1 V_82 ,
const union V_41 * V_63 ,
T_1 V_64 , T_4 V_57 , T_3 V_51 )
{
struct V_74 * V_75 ;
struct V_52 * V_53 ;
V_53 = F_39 ( V_2 , V_39 , V_51 , V_57 , V_63 , V_64 ) ;
if ( ! V_53 )
return NULL ;
V_75 = F_57 ( V_53 , V_9 , V_82 ) ;
if ( V_75 )
F_30 ( & V_75 -> V_62 ) ;
F_59 ( V_53 ) ;
return V_75 ;
}
static struct V_74 *
F_60 ( struct V_52 * V_53 , const union V_41 * V_9 ,
T_1 V_82 )
{
struct V_74 * V_75 , * V_85 ;
struct V_13 * V_14 = F_40 ( V_53 -> V_2 ) ;
F_61 (dest, nxt, &ipvs->dest_trash, n_list) {
F_43 ( 3 , L_7
L_8 ,
V_75 -> V_84 ,
F_45 ( V_53 -> V_39 , & V_75 -> V_4 ) ,
F_22 ( V_75 -> V_42 ) ,
F_14 ( & V_75 -> V_62 ) ) ;
if ( V_75 -> V_39 == V_53 -> V_39 &&
F_36 ( V_53 -> V_39 , & V_75 -> V_4 , V_9 ) &&
V_75 -> V_42 == V_82 &&
V_75 -> V_84 == V_53 -> V_51 &&
V_75 -> V_57 == V_53 -> V_57 &&
( V_53 -> V_51 ||
( F_36 ( V_53 -> V_39 , & V_75 -> V_63 , & V_53 -> V_4 ) &&
V_75 -> V_64 == V_53 -> V_42 ) ) ) {
return V_75 ;
}
if ( F_14 ( & V_75 -> V_62 ) == 1 ) {
F_43 ( 3 , L_9
L_10 ,
V_75 -> V_84 ,
F_45 ( V_53 -> V_39 , & V_75 -> V_4 ) ,
F_22 ( V_75 -> V_42 ) ) ;
F_32 ( & V_75 -> V_86 ) ;
F_62 ( V_75 ) ;
F_47 ( V_75 ) ;
F_49 ( V_75 -> V_76 . V_77 ) ;
F_50 ( V_75 ) ;
}
}
return NULL ;
}
static void F_63 ( struct V_2 * V_2 )
{
struct V_74 * V_75 , * V_85 ;
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_61 (dest, nxt, &ipvs->dest_trash, n_list) {
F_32 ( & V_75 -> V_86 ) ;
F_62 ( V_75 ) ;
F_47 ( V_75 ) ;
F_49 ( V_75 -> V_76 . V_77 ) ;
F_50 ( V_75 ) ;
}
}
static void
F_64 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
#define F_65 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_66 ( & V_90 -> V_91 ) ;
F_65 ( V_92 ) ;
F_65 ( V_93 ) ;
F_65 ( V_94 ) ;
F_65 ( V_95 ) ;
F_65 ( V_96 ) ;
F_67 ( V_88 , V_90 ) ;
F_68 ( & V_90 -> V_91 ) ;
}
static void
F_69 ( struct V_89 * V_76 )
{
F_66 ( & V_76 -> V_91 ) ;
#define F_70 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_70 ( V_92 ) ;
F_70 ( V_93 ) ;
F_70 ( V_94 ) ;
F_70 ( V_95 ) ;
F_70 ( V_96 ) ;
F_71 ( V_76 ) ;
F_68 ( & V_76 -> V_91 ) ;
}
static void
F_72 ( struct V_52 * V_53 , struct V_74 * V_75 ,
struct V_97 * V_98 , int V_99 )
{
struct V_13 * V_14 = F_40 ( V_53 -> V_2 ) ;
int V_100 ;
F_8 ( & V_75 -> V_101 , V_98 -> V_101 ) ;
V_100 = V_98 -> V_100 & V_102 ;
V_100 |= V_103 ;
if ( ( V_100 & V_104 ) != V_105 ) {
V_100 |= V_106 ;
} else {
F_73 ( & V_14 -> V_83 ) ;
F_52 ( V_14 , V_75 ) ;
F_74 ( & V_14 -> V_83 ) ;
}
F_8 ( & V_75 -> V_100 , V_100 ) ;
if ( ! V_75 -> V_53 ) {
F_46 ( V_75 , V_53 ) ;
} else {
if ( V_75 -> V_53 != V_53 ) {
F_47 ( V_75 ) ;
F_69 ( & V_75 -> V_76 ) ;
F_46 ( V_75 , V_53 ) ;
}
}
V_75 -> V_11 |= V_107 ;
if ( V_98 -> V_108 == 0 || V_98 -> V_108 > V_75 -> V_108 )
V_75 -> V_11 &= ~ V_109 ;
V_75 -> V_108 = V_98 -> V_108 ;
V_75 -> V_110 = V_98 -> V_110 ;
F_66 ( & V_75 -> V_111 ) ;
F_62 ( V_75 ) ;
F_68 ( & V_75 -> V_111 ) ;
if ( V_99 )
F_75 ( V_53 -> V_2 , & V_75 -> V_76 ) ;
F_73 ( & V_65 ) ;
F_76 ( F_14 ( & V_53 -> V_73 ) > 0 ) ;
if ( V_99 ) {
F_29 ( & V_75 -> V_86 , & V_53 -> V_112 ) ;
V_53 -> V_113 ++ ;
}
if ( V_53 -> V_114 -> V_115 )
V_53 -> V_114 -> V_115 ( V_53 ) ;
F_74 ( & V_65 ) ;
}
static int
F_77 ( struct V_52 * V_53 , struct V_97 * V_98 ,
struct V_74 * * V_116 )
{
struct V_74 * V_75 ;
unsigned V_117 ;
F_78 ( 2 ) ;
#ifdef F_23
if ( V_53 -> V_39 == V_46 ) {
V_117 = F_79 ( & V_98 -> V_4 . V_118 ) ;
if ( ( ! ( V_117 & V_119 ) ||
V_117 & V_120 ) &&
! F_2 ( V_53 -> V_2 , & V_98 -> V_4 . V_118 ) )
return - V_121 ;
} else
#endif
{
V_117 = F_80 ( V_53 -> V_2 , V_98 -> V_4 . V_45 ) ;
if ( V_117 != V_122 && V_117 != V_123 )
return - V_121 ;
}
V_75 = F_81 ( sizeof( struct V_74 ) , V_124 ) ;
if ( V_75 == NULL ) {
F_27 ( L_11 , V_56 ) ;
return - V_125 ;
}
V_75 -> V_76 . V_77 = F_82 ( struct V_126 ) ;
if ( ! V_75 -> V_76 . V_77 ) {
F_27 ( L_12 , V_56 ) ;
goto V_127;
}
V_75 -> V_39 = V_53 -> V_39 ;
V_75 -> V_57 = V_53 -> V_57 ;
V_75 -> V_63 = V_53 -> V_4 ;
V_75 -> V_64 = V_53 -> V_42 ;
V_75 -> V_84 = V_53 -> V_51 ;
F_83 ( V_53 -> V_39 , & V_75 -> V_4 , & V_98 -> V_4 ) ;
V_75 -> V_42 = V_98 -> V_42 ;
F_8 ( & V_75 -> V_128 , 0 ) ;
F_8 ( & V_75 -> V_129 , 0 ) ;
F_8 ( & V_75 -> V_130 , 0 ) ;
F_8 ( & V_75 -> V_62 , 1 ) ;
F_55 ( & V_75 -> V_80 ) ;
F_84 ( & V_75 -> V_111 ) ;
F_84 ( & V_75 -> V_76 . V_91 ) ;
F_72 ( V_53 , V_75 , V_98 , 1 ) ;
* V_116 = V_75 ;
F_85 ( 2 ) ;
return 0 ;
V_127:
F_50 ( V_75 ) ;
return - V_125 ;
}
static int
F_86 ( struct V_52 * V_53 , struct V_97 * V_98 )
{
struct V_74 * V_75 ;
union V_41 V_9 ;
T_1 V_82 = V_98 -> V_42 ;
int V_131 ;
F_78 ( 2 ) ;
if ( V_98 -> V_101 < 0 ) {
F_27 ( L_13 , V_56 ) ;
return - V_132 ;
}
if ( V_98 -> V_110 > V_98 -> V_108 ) {
F_27 ( L_14 ,
V_56 ) ;
return - V_132 ;
}
F_83 ( V_53 -> V_39 , & V_9 , & V_98 -> V_4 ) ;
V_75 = F_57 ( V_53 , & V_9 , V_82 ) ;
if ( V_75 != NULL ) {
F_87 ( 1 , L_15 , V_56 ) ;
return - V_133 ;
}
V_75 = F_60 ( V_53 , & V_9 , V_82 ) ;
if ( V_75 != NULL ) {
F_43 ( 3 , L_16
L_17 ,
F_45 ( V_53 -> V_39 , & V_9 ) , F_22 ( V_82 ) ,
F_14 ( & V_75 -> V_62 ) ,
V_75 -> V_84 ,
F_45 ( V_53 -> V_39 , & V_75 -> V_63 ) ,
F_22 ( V_75 -> V_64 ) ) ;
F_32 ( & V_75 -> V_86 ) ;
F_72 ( V_53 , V_75 , V_98 , 1 ) ;
V_131 = 0 ;
} else {
V_131 = F_77 ( V_53 , V_98 , & V_75 ) ;
}
F_85 ( 2 ) ;
return V_131 ;
}
static int
F_88 ( struct V_52 * V_53 , struct V_97 * V_98 )
{
struct V_74 * V_75 ;
union V_41 V_9 ;
T_1 V_82 = V_98 -> V_42 ;
F_78 ( 2 ) ;
if ( V_98 -> V_101 < 0 ) {
F_27 ( L_13 , V_56 ) ;
return - V_132 ;
}
if ( V_98 -> V_110 > V_98 -> V_108 ) {
F_27 ( L_14 ,
V_56 ) ;
return - V_132 ;
}
F_83 ( V_53 -> V_39 , & V_9 , & V_98 -> V_4 ) ;
V_75 = F_57 ( V_53 , & V_9 , V_82 ) ;
if ( V_75 == NULL ) {
F_87 ( 1 , L_18 , V_56 ) ;
return - V_134 ;
}
F_72 ( V_53 , V_75 , V_98 , 0 ) ;
F_85 ( 2 ) ;
return 0 ;
}
static void F_89 ( struct V_2 * V_2 , struct V_74 * V_75 )
{
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_90 ( V_2 , & V_75 -> V_76 ) ;
F_73 ( & V_14 -> V_83 ) ;
F_54 ( V_75 ) ;
F_74 ( & V_14 -> V_83 ) ;
if ( F_48 ( & V_75 -> V_62 ) ) {
F_43 ( 3 , L_19 ,
V_75 -> V_84 ,
F_45 ( V_75 -> V_39 , & V_75 -> V_4 ) ,
F_22 ( V_75 -> V_42 ) ) ;
F_62 ( V_75 ) ;
F_33 ( & V_75 -> V_53 -> V_62 ) ;
F_49 ( V_75 -> V_76 . V_77 ) ;
F_50 ( V_75 ) ;
} else {
F_43 ( 3 , L_20
L_8 ,
F_45 ( V_75 -> V_39 , & V_75 -> V_4 ) ,
F_22 ( V_75 -> V_42 ) ,
F_14 ( & V_75 -> V_62 ) ) ;
F_29 ( & V_75 -> V_86 , & V_14 -> V_135 ) ;
F_30 ( & V_75 -> V_62 ) ;
}
}
static void F_91 ( struct V_52 * V_53 ,
struct V_74 * V_75 ,
int V_136 )
{
V_75 -> V_11 &= ~ V_107 ;
F_32 ( & V_75 -> V_86 ) ;
V_53 -> V_113 -- ;
if ( V_136 && V_53 -> V_114 -> V_115 )
V_53 -> V_114 -> V_115 ( V_53 ) ;
}
static int
F_92 ( struct V_52 * V_53 , struct V_97 * V_98 )
{
struct V_74 * V_75 ;
T_1 V_82 = V_98 -> V_42 ;
F_78 ( 2 ) ;
V_75 = F_57 ( V_53 , & V_98 -> V_4 , V_82 ) ;
if ( V_75 == NULL ) {
F_87 ( 1 , L_21 , V_56 ) ;
return - V_134 ;
}
F_73 ( & V_65 ) ;
F_76 ( F_14 ( & V_53 -> V_73 ) > 0 ) ;
F_91 ( V_53 , V_75 , 1 ) ;
F_74 ( & V_65 ) ;
F_89 ( V_53 -> V_2 , V_75 ) ;
F_85 ( 2 ) ;
return 0 ;
}
static int
F_93 ( struct V_2 * V_2 , struct V_137 * V_138 ,
struct V_52 * * V_139 )
{
int V_131 = 0 ;
struct V_140 * V_141 = NULL ;
struct V_142 * V_143 = NULL ;
struct V_52 * V_53 = NULL ;
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_17 () ;
V_141 = F_94 ( V_138 -> V_144 ) ;
if ( V_141 == NULL ) {
F_95 ( L_22 , V_138 -> V_144 ) ;
V_131 = - V_134 ;
goto V_145;
}
if ( V_138 -> V_146 && * V_138 -> V_146 ) {
V_143 = F_96 ( V_138 -> V_146 ) ;
if ( V_143 == NULL ) {
F_95 ( L_23
L_24 , V_138 -> V_146 ) ;
V_131 = - V_134 ;
goto V_145;
}
}
#ifdef F_23
if ( V_138 -> V_39 == V_46 && ( V_138 -> V_147 < 1 || V_138 -> V_147 > 128 ) ) {
V_131 = - V_121 ;
goto V_145;
}
#endif
V_53 = F_81 ( sizeof( struct V_52 ) , V_124 ) ;
if ( V_53 == NULL ) {
F_87 ( 1 , L_25 , V_56 ) ;
V_131 = - V_125 ;
goto V_145;
}
V_53 -> V_76 . V_77 = F_82 ( struct V_126 ) ;
if ( ! V_53 -> V_76 . V_77 ) {
F_27 ( L_12 , V_56 ) ;
goto V_145;
}
F_8 ( & V_53 -> V_73 , 0 ) ;
F_8 ( & V_53 -> V_62 , 0 ) ;
V_53 -> V_39 = V_138 -> V_39 ;
V_53 -> V_57 = V_138 -> V_57 ;
F_83 ( V_53 -> V_39 , & V_53 -> V_4 , & V_138 -> V_4 ) ;
V_53 -> V_42 = V_138 -> V_42 ;
V_53 -> V_51 = V_138 -> V_51 ;
V_53 -> V_11 = V_138 -> V_11 ;
V_53 -> V_148 = V_138 -> V_148 * V_149 ;
V_53 -> V_147 = V_138 -> V_147 ;
V_53 -> V_2 = V_2 ;
F_55 ( & V_53 -> V_112 ) ;
F_97 ( & V_53 -> V_150 ) ;
F_84 ( & V_53 -> V_76 . V_91 ) ;
V_131 = F_98 ( V_53 , V_141 ) ;
if ( V_131 )
goto V_145;
V_141 = NULL ;
F_99 ( V_53 , V_143 ) ;
V_143 = NULL ;
if ( V_53 -> V_42 == V_71 )
F_30 ( & V_14 -> V_68 ) ;
else if ( V_53 -> V_42 == 0 )
F_30 ( & V_14 -> V_72 ) ;
F_75 ( V_2 , & V_53 -> V_76 ) ;
if ( V_53 -> V_39 == V_151 )
V_14 -> V_152 ++ ;
F_73 ( & V_65 ) ;
F_26 ( V_53 ) ;
F_74 ( & V_65 ) ;
* V_139 = V_53 ;
V_14 -> V_153 = 1 ;
return 0 ;
V_145:
if ( V_53 != NULL ) {
F_100 ( V_53 ) ;
if ( V_53 -> V_154 ) {
F_6 () ;
F_101 ( V_53 -> V_154 ) ;
F_11 () ;
}
if ( V_53 -> V_76 . V_77 )
F_49 ( V_53 -> V_76 . V_77 ) ;
F_50 ( V_53 ) ;
}
F_102 ( V_141 ) ;
F_103 ( V_143 ) ;
F_19 () ;
return V_131 ;
}
static int
F_104 ( struct V_52 * V_53 , struct V_137 * V_138 )
{
struct V_140 * V_141 , * V_155 ;
struct V_142 * V_143 = NULL , * V_156 = NULL ;
int V_131 = 0 ;
V_141 = F_94 ( V_138 -> V_144 ) ;
if ( V_141 == NULL ) {
F_95 ( L_22 , V_138 -> V_144 ) ;
return - V_134 ;
}
V_155 = V_141 ;
if ( V_138 -> V_146 && * V_138 -> V_146 ) {
V_143 = F_96 ( V_138 -> V_146 ) ;
if ( V_143 == NULL ) {
F_95 ( L_23
L_24 , V_138 -> V_146 ) ;
V_131 = - V_134 ;
goto V_66;
}
V_156 = V_143 ;
}
#ifdef F_23
if ( V_138 -> V_39 == V_46 && ( V_138 -> V_147 < 1 || V_138 -> V_147 > 128 ) ) {
V_131 = - V_121 ;
goto V_66;
}
#endif
F_73 ( & V_65 ) ;
F_76 ( F_14 ( & V_53 -> V_73 ) > 0 ) ;
V_53 -> V_11 = V_138 -> V_11 | V_55 ;
V_53 -> V_148 = V_138 -> V_148 * V_149 ;
V_53 -> V_147 = V_138 -> V_147 ;
V_155 = V_53 -> V_114 ;
if ( V_141 != V_155 ) {
if ( ( V_131 = F_100 ( V_53 ) ) ) {
V_155 = V_141 ;
goto V_157;
}
if ( ( V_131 = F_98 ( V_53 , V_141 ) ) ) {
F_98 ( V_53 , V_155 ) ;
V_155 = V_141 ;
goto V_157;
}
}
V_156 = V_53 -> V_143 ;
if ( V_143 != V_156 ) {
F_105 ( V_53 ) ;
F_99 ( V_53 , V_143 ) ;
}
V_157:
F_74 ( & V_65 ) ;
V_66:
F_102 ( V_155 ) ;
F_103 ( V_156 ) ;
return V_131 ;
}
static void F_106 ( struct V_52 * V_53 )
{
struct V_74 * V_75 , * V_85 ;
struct V_140 * V_155 ;
struct V_142 * V_156 ;
struct V_13 * V_14 = F_40 ( V_53 -> V_2 ) ;
F_95 ( L_26 , V_56 ) ;
if ( V_53 -> V_39 == V_151 )
V_14 -> V_152 -- ;
F_90 ( V_53 -> V_2 , & V_53 -> V_76 ) ;
V_155 = V_53 -> V_114 ;
F_100 ( V_53 ) ;
F_102 ( V_155 ) ;
V_156 = V_53 -> V_143 ;
F_105 ( V_53 ) ;
F_103 ( V_156 ) ;
if ( V_53 -> V_154 ) {
F_101 ( V_53 -> V_154 ) ;
V_53 -> V_154 = NULL ;
}
F_61 (dest, nxt, &svc->destinations, n_list) {
F_91 ( V_53 , V_75 , 0 ) ;
F_89 ( V_53 -> V_2 , V_75 ) ;
}
if ( V_53 -> V_42 == V_71 )
F_33 ( & V_14 -> V_68 ) ;
else if ( V_53 -> V_42 == 0 )
F_33 ( & V_14 -> V_72 ) ;
if ( F_14 ( & V_53 -> V_62 ) == 0 ) {
F_43 ( 3 , L_6 ,
V_53 -> V_51 ,
F_45 ( V_53 -> V_39 , & V_53 -> V_4 ) ,
F_22 ( V_53 -> V_42 ) , F_14 ( & V_53 -> V_73 ) ) ;
F_49 ( V_53 -> V_76 . V_77 ) ;
F_50 ( V_53 ) ;
}
F_19 () ;
}
static void F_107 ( struct V_52 * V_53 )
{
F_73 ( & V_65 ) ;
F_31 ( V_53 ) ;
F_76 ( F_14 ( & V_53 -> V_73 ) > 0 ) ;
F_106 ( V_53 ) ;
F_74 ( & V_65 ) ;
}
static int F_108 ( struct V_52 * V_53 )
{
if ( V_53 == NULL )
return - V_133 ;
F_107 ( V_53 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_52 * V_53 , * V_85 ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_61 (svc, nxt, &ip_vs_svc_table[idx],
s_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) )
F_107 ( V_53 ) ;
}
}
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_61 (svc, nxt,
&ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) )
F_107 ( V_53 ) ;
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
F_113 ( struct V_74 * V_75 , struct V_161 * V_162 )
{
F_66 ( & V_75 -> V_111 ) ;
if ( V_75 -> V_163 && V_75 -> V_163 -> V_162 == V_162 ) {
F_43 ( 3 , L_27 ,
V_162 -> V_164 ,
F_45 ( V_75 -> V_39 , & V_75 -> V_4 ) ,
F_22 ( V_75 -> V_42 ) ,
F_14 ( & V_75 -> V_62 ) ) ;
F_62 ( V_75 ) ;
}
F_68 ( & V_75 -> V_111 ) ;
}
static int F_114 ( struct V_165 * V_166 , unsigned long V_167 ,
void * V_168 )
{
struct V_161 * V_162 = V_168 ;
struct V_2 * V_2 = F_115 ( V_162 ) ;
struct V_52 * V_53 ;
struct V_74 * V_75 ;
unsigned int V_158 ;
if ( V_167 != V_169 )
return V_170 ;
F_87 ( 3 , L_28 , V_56 , V_162 -> V_164 ) ;
F_78 ( 2 ) ;
F_111 ( & V_160 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) ) {
F_35 (dest, &svc->destinations,
n_list) {
F_113 ( V_75 , V_162 ) ;
}
}
}
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) ) {
F_35 (dest, &svc->destinations,
n_list) {
F_113 ( V_75 , V_162 ) ;
}
}
}
}
F_35 (dest, &net_ipvs(net)->dest_trash, n_list) {
F_113 ( V_75 , V_162 ) ;
}
F_112 ( & V_160 ) ;
F_85 ( 2 ) ;
return V_170 ;
}
static int F_116 ( struct V_52 * V_53 )
{
struct V_74 * V_75 ;
F_73 ( & V_65 ) ;
F_35 (dest, &svc->destinations, n_list) {
F_69 ( & V_75 -> V_76 ) ;
}
F_69 ( & V_53 -> V_76 ) ;
F_74 ( & V_65 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_52 * V_53 ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) )
F_116 ( V_53 ) ;
}
}
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) )
F_116 ( V_53 ) ;
}
}
F_69 ( & F_40 ( V_2 ) -> V_171 ) ;
return 0 ;
}
static int
F_118 ( T_6 * V_172 , int V_173 ,
void T_7 * V_174 , V_48 * V_175 , T_8 * V_176 )
{
struct V_2 * V_2 = V_177 -> V_178 -> V_179 ;
int * V_180 = V_172 -> V_181 ;
int V_182 = * V_180 ;
int V_183 ;
V_183 = F_119 ( V_172 , V_173 , V_174 , V_175 , V_176 ) ;
if ( V_173 && ( * V_180 != V_182 ) ) {
if ( ( * V_180 < 0 ) || ( * V_180 > 3 ) ) {
* V_180 = V_182 ;
} else {
F_4 ( F_40 ( V_2 ) ) ;
}
}
return V_183 ;
}
static int
F_120 ( T_6 * V_172 , int V_173 ,
void T_7 * V_174 , V_48 * V_175 , T_8 * V_176 )
{
int * V_180 = V_172 -> V_181 ;
int V_182 [ 2 ] ;
int V_183 ;
memcpy ( V_182 , V_180 , sizeof( V_182 ) ) ;
V_183 = F_119 ( V_172 , V_173 , V_174 , V_175 , V_176 ) ;
if ( V_173 && ( V_180 [ 0 ] < 0 || V_180 [ 1 ] < 0 || V_180 [ 0 ] >= V_180 [ 1 ] ) ) {
memcpy ( V_180 , V_182 , sizeof( V_182 ) ) ;
}
return V_183 ;
}
static int
F_121 ( T_6 * V_172 , int V_173 ,
void T_7 * V_174 , V_48 * V_175 , T_8 * V_176 )
{
int * V_180 = V_172 -> V_181 ;
int V_182 = * V_180 ;
int V_183 ;
V_183 = F_119 ( V_172 , V_173 , V_174 , V_175 , V_176 ) ;
if ( V_173 && ( * V_180 != V_182 ) ) {
if ( ( * V_180 < 0 ) || ( * V_180 > 1 ) ) {
* V_180 = V_182 ;
} else {
struct V_2 * V_2 = V_177 -> V_178 -> V_179 ;
F_122 ( V_2 , V_182 ) ;
}
}
return V_183 ;
}
static inline const char * F_123 ( unsigned V_11 )
{
switch ( V_11 & V_104 ) {
case V_184 :
return L_29 ;
case V_185 :
return L_30 ;
case V_186 :
return L_31 ;
default:
return L_32 ;
}
}
static struct V_52 * F_124 ( struct V_187 * V_188 , T_8 V_189 )
{
struct V_2 * V_2 = F_125 ( V_188 ) ;
struct V_190 * V_191 = V_188 -> V_192 ;
int V_158 ;
struct V_52 * V_53 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) && V_189 -- == 0 ) {
V_191 -> V_172 = V_59 ;
V_191 -> V_193 = V_158 ;
return V_53 ;
}
}
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_37 ( V_53 -> V_2 , V_2 ) && V_189 -- == 0 ) {
V_191 -> V_172 = V_61 ;
V_191 -> V_193 = V_158 ;
return V_53 ;
}
}
}
return NULL ;
}
static void * F_126 ( struct V_187 * V_188 , T_8 * V_189 )
__acquires( V_65 )
{
F_127 ( & V_65 ) ;
return * V_189 ? F_124 ( V_188 , * V_189 - 1 ) : V_194 ;
}
static void * F_128 ( struct V_187 * V_188 , void * V_195 , T_8 * V_189 )
{
struct V_196 * V_197 ;
struct V_190 * V_191 ;
struct V_52 * V_53 ;
++ * V_189 ;
if ( V_195 == V_194 )
return F_124 ( V_188 , 0 ) ;
V_53 = V_195 ;
V_191 = V_188 -> V_192 ;
if ( V_191 -> V_172 == V_59 ) {
if ( ( V_197 = V_53 -> V_58 . V_198 ) != & V_59 [ V_191 -> V_193 ] )
return F_129 ( V_197 , struct V_52 , V_58 ) ;
while ( ++ V_191 -> V_193 < V_159 ) {
F_35 (svc,&ip_vs_svc_table[iter->bucket],
s_list) {
return V_53 ;
}
}
V_191 -> V_172 = V_61 ;
V_191 -> V_193 = - 1 ;
goto V_199;
}
if ( ( V_197 = V_53 -> V_60 . V_198 ) != & V_61 [ V_191 -> V_193 ] )
return F_129 ( V_197 , struct V_52 , V_60 ) ;
V_199:
while ( ++ V_191 -> V_193 < V_159 ) {
F_35 (svc, &ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_53 ;
}
return NULL ;
}
static void F_130 ( struct V_187 * V_188 , void * V_195 )
__releases( V_65 )
{
F_131 ( & V_65 ) ;
}
static int F_132 ( struct V_187 * V_188 , void * V_195 )
{
if ( V_195 == V_194 ) {
F_133 ( V_188 ,
L_33 ,
F_134 ( V_200 ) , V_201 ) ;
F_135 ( V_188 ,
L_34 ) ;
F_135 ( V_188 ,
L_35 ) ;
} else {
const struct V_52 * V_53 = V_195 ;
const struct V_190 * V_191 = V_188 -> V_192 ;
const struct V_74 * V_75 ;
if ( V_191 -> V_172 == V_59 ) {
#ifdef F_23
if ( V_53 -> V_39 == V_46 )
F_133 ( V_188 , L_36 ,
F_44 ( V_53 -> V_57 ) ,
& V_53 -> V_4 . V_118 ,
F_22 ( V_53 -> V_42 ) ,
V_53 -> V_114 -> V_164 ) ;
else
#endif
F_133 ( V_188 , L_37 ,
F_44 ( V_53 -> V_57 ) ,
F_24 ( V_53 -> V_4 . V_45 ) ,
F_22 ( V_53 -> V_42 ) ,
V_53 -> V_114 -> V_164 ,
( V_53 -> V_11 & V_202 ) ? L_38 : L_39 ) ;
} else {
F_133 ( V_188 , L_40 ,
V_53 -> V_51 , V_53 -> V_114 -> V_164 ,
( V_53 -> V_11 & V_202 ) ? L_38 : L_39 ) ;
}
if ( V_53 -> V_11 & V_203 )
F_133 ( V_188 , L_41 ,
V_53 -> V_148 ,
F_24 ( V_53 -> V_147 ) ) ;
else
F_136 ( V_188 , '\n' ) ;
F_35 (dest, &svc->destinations, n_list) {
#ifdef F_23
if ( V_75 -> V_39 == V_46 )
F_133 ( V_188 ,
L_42
L_43 ,
& V_75 -> V_4 . V_118 ,
F_22 ( V_75 -> V_42 ) ,
F_123 ( F_14 ( & V_75 -> V_100 ) ) ,
F_14 ( & V_75 -> V_101 ) ,
F_14 ( & V_75 -> V_128 ) ,
F_14 ( & V_75 -> V_129 ) ) ;
else
#endif
F_133 ( V_188 ,
L_44
L_45 ,
F_24 ( V_75 -> V_4 . V_45 ) ,
F_22 ( V_75 -> V_42 ) ,
F_123 ( F_14 ( & V_75 -> V_100 ) ) ,
F_14 ( & V_75 -> V_101 ) ,
F_14 ( & V_75 -> V_128 ) ,
F_14 ( & V_75 -> V_129 ) ) ;
}
}
return 0 ;
}
static int F_137 ( struct V_204 * V_204 , struct V_205 * V_205 )
{
return F_138 ( V_204 , V_205 , & V_206 ,
sizeof( struct V_190 ) ) ;
}
static int F_139 ( struct V_187 * V_188 , void * V_195 )
{
struct V_2 * V_2 = F_140 ( V_188 ) ;
struct V_87 V_207 ;
F_135 ( V_188 ,
L_46 ) ;
F_133 ( V_188 ,
L_47 ) ;
F_64 ( & V_207 , & F_40 ( V_2 ) -> V_171 ) ;
F_133 ( V_188 , L_48 , V_207 . V_92 ,
V_207 . V_93 , V_207 . V_94 ,
( unsigned long long ) V_207 . V_95 ,
( unsigned long long ) V_207 . V_96 ) ;
F_135 ( V_188 ,
L_49 ) ;
F_133 ( V_188 , L_50 ,
V_207 . V_208 , V_207 . V_209 , V_207 . V_210 ,
V_207 . V_211 , V_207 . V_212 ) ;
return 0 ;
}
static int F_141 ( struct V_204 * V_204 , struct V_205 * V_205 )
{
return F_142 ( V_204 , V_205 , F_139 ) ;
}
static int F_143 ( struct V_187 * V_188 , void * V_195 )
{
struct V_2 * V_2 = F_140 ( V_188 ) ;
struct V_89 * V_171 = & F_40 ( V_2 ) -> V_171 ;
struct V_126 * V_77 = V_171 -> V_77 ;
struct V_87 V_213 ;
int V_16 ;
F_135 ( V_188 ,
L_51 ) ;
F_133 ( V_188 ,
L_52 ) ;
F_144 (i) {
struct V_126 * V_138 = F_145 ( V_77 , V_16 ) ;
unsigned int V_214 ;
T_9 V_95 , V_96 ;
do {
V_214 = F_146 ( & V_138 -> V_215 ) ;
V_95 = V_138 -> V_216 . V_95 ;
V_96 = V_138 -> V_216 . V_96 ;
} while ( F_147 ( & V_138 -> V_215 , V_214 ) );
F_133 ( V_188 , L_53 ,
V_16 , V_138 -> V_216 . V_92 , V_138 -> V_216 . V_93 ,
V_138 -> V_216 . V_94 , ( T_9 ) V_95 ,
( T_9 ) V_96 ) ;
}
F_66 ( & V_171 -> V_91 ) ;
F_133 ( V_188 , L_54 ,
V_171 -> V_216 . V_92 , V_171 -> V_216 . V_93 ,
V_171 -> V_216 . V_94 ,
( unsigned long long ) V_171 -> V_216 . V_95 ,
( unsigned long long ) V_171 -> V_216 . V_96 ) ;
F_67 ( & V_213 , V_171 ) ;
F_68 ( & V_171 -> V_91 ) ;
F_135 ( V_188 ,
L_55 ) ;
F_133 ( V_188 , L_56 ,
V_213 . V_208 ,
V_213 . V_209 ,
V_213 . V_210 ,
V_213 . V_211 ,
V_213 . V_212 ) ;
return 0 ;
}
static int F_148 ( struct V_204 * V_204 , struct V_205 * V_205 )
{
return F_142 ( V_204 , V_205 , F_143 ) ;
}
static int F_149 ( struct V_2 * V_2 , struct V_217 * V_138 )
{
#if F_150 ( V_218 ) || F_150 ( V_219 )
struct V_220 * V_221 ;
#endif
F_87 ( 2 , L_57 ,
V_138 -> V_222 ,
V_138 -> V_223 ,
V_138 -> V_224 ) ;
#ifdef V_218
if ( V_138 -> V_222 ) {
V_221 = F_151 ( V_2 , V_67 ) ;
V_221 -> V_225 [ V_226 ]
= V_138 -> V_222 * V_149 ;
}
if ( V_138 -> V_223 ) {
V_221 = F_151 ( V_2 , V_67 ) ;
V_221 -> V_225 [ V_227 ]
= V_138 -> V_223 * V_149 ;
}
#endif
#ifdef V_219
if ( V_138 -> V_224 ) {
V_221 = F_151 ( V_2 , V_228 ) ;
V_221 -> V_225 [ V_229 ]
= V_138 -> V_224 * V_149 ;
}
#endif
return 0 ;
}
static void F_152 ( struct V_137 * V_230 ,
struct V_231 * V_232 )
{
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
V_230 -> V_39 = V_151 ;
V_230 -> V_57 = V_232 -> V_57 ;
V_230 -> V_4 . V_45 = V_232 -> V_4 ;
V_230 -> V_42 = V_232 -> V_42 ;
V_230 -> V_51 = V_232 -> V_51 ;
V_230 -> V_144 = V_232 -> V_144 ;
V_230 -> V_11 = V_232 -> V_11 ;
V_230 -> V_148 = V_232 -> V_148 ;
V_230 -> V_147 = V_232 -> V_147 ;
}
static void F_153 ( struct V_97 * V_98 ,
struct V_233 * V_234 )
{
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_98 -> V_4 . V_45 = V_234 -> V_4 ;
V_98 -> V_42 = V_234 -> V_42 ;
V_98 -> V_100 = V_234 -> V_100 ;
V_98 -> V_101 = V_234 -> V_101 ;
V_98 -> V_108 = V_234 -> V_108 ;
V_98 -> V_110 = V_234 -> V_110 ;
}
static int
F_154 ( struct V_235 * V_236 , int V_237 , void T_7 * V_238 , unsigned int V_239 )
{
struct V_2 * V_2 = F_155 ( V_236 ) ;
int V_131 ;
unsigned char V_240 [ V_241 ] ;
struct V_231 * V_232 ;
struct V_137 V_230 ;
struct V_52 * V_53 ;
struct V_233 * V_234 ;
struct V_97 V_98 ;
if ( ! F_156 ( V_242 ) )
return - V_243 ;
if ( V_237 < V_244 || V_237 > V_245 )
return - V_121 ;
if ( V_239 < 0 || V_239 > V_241 )
return - V_121 ;
if ( V_239 != V_246 [ F_157 ( V_237 ) ] ) {
F_27 ( L_58 ,
V_239 , V_246 [ F_157 ( V_237 ) ] ) ;
return - V_121 ;
}
if ( F_158 ( V_240 , V_238 , V_239 ) != 0 )
return - V_247 ;
F_17 () ;
if ( F_159 ( & V_160 ) ) {
V_131 = - V_248 ;
goto V_249;
}
if ( V_237 == V_250 ) {
V_131 = F_109 ( V_2 ) ;
goto V_157;
} else if ( V_237 == V_251 ) {
V_131 = F_149 ( V_2 , (struct V_217 * ) V_240 ) ;
goto V_157;
} else if ( V_237 == V_252 ) {
struct V_253 * V_254 = (struct V_253 * ) V_240 ;
V_131 = F_160 ( V_2 , V_254 -> V_255 , V_254 -> V_256 ,
V_254 -> V_257 ) ;
goto V_157;
} else if ( V_237 == V_258 ) {
struct V_253 * V_254 = (struct V_253 * ) V_240 ;
V_131 = F_161 ( V_2 , V_254 -> V_255 ) ;
goto V_157;
}
V_232 = (struct V_231 * ) V_240 ;
V_234 = (struct V_233 * ) ( V_232 + 1 ) ;
F_152 ( & V_230 , V_232 ) ;
F_153 ( & V_98 , V_234 ) ;
if ( V_237 == V_259 ) {
if ( ! V_230 . V_51 && ! V_230 . V_4 . V_45 && ! V_230 . V_42 ) {
V_131 = F_117 ( V_2 ) ;
goto V_157;
}
}
if ( V_230 . V_57 != V_67 && V_230 . V_57 != V_228 &&
V_230 . V_57 != V_260 ) {
F_27 ( L_59 ,
V_230 . V_57 , & V_230 . V_4 . V_45 ,
F_22 ( V_230 . V_42 ) , V_230 . V_144 ) ;
V_131 = - V_247 ;
goto V_157;
}
if ( V_230 . V_51 == 0 )
V_53 = F_34 ( V_2 , V_230 . V_39 , V_230 . V_57 ,
& V_230 . V_4 , V_230 . V_42 ) ;
else
V_53 = F_38 ( V_2 , V_230 . V_39 , V_230 . V_51 ) ;
if ( V_237 != V_261
&& ( V_53 == NULL || V_53 -> V_57 != V_230 . V_57 ) ) {
V_131 = - V_262 ;
goto V_157;
}
switch ( V_237 ) {
case V_261 :
if ( V_53 != NULL )
V_131 = - V_133 ;
else
V_131 = F_93 ( V_2 , & V_230 , & V_53 ) ;
break;
case V_263 :
V_131 = F_104 ( V_53 , & V_230 ) ;
break;
case V_264 :
V_131 = F_108 ( V_53 ) ;
if ( ! V_131 )
goto V_157;
break;
case V_259 :
V_131 = F_116 ( V_53 ) ;
break;
case V_265 :
V_131 = F_86 ( V_53 , & V_98 ) ;
break;
case V_266 :
V_131 = F_88 ( V_53 , & V_98 ) ;
break;
case V_267 :
V_131 = F_92 ( V_53 , & V_98 ) ;
break;
default:
V_131 = - V_121 ;
}
V_157:
F_112 ( & V_160 ) ;
V_249:
F_19 () ;
return V_131 ;
}
static void
F_162 ( struct V_268 * V_88 , struct V_52 * V_90 )
{
V_88 -> V_57 = V_90 -> V_57 ;
V_88 -> V_4 = V_90 -> V_4 . V_45 ;
V_88 -> V_42 = V_90 -> V_42 ;
V_88 -> V_51 = V_90 -> V_51 ;
F_163 ( V_88 -> V_144 , V_90 -> V_114 -> V_164 , sizeof( V_88 -> V_144 ) ) ;
V_88 -> V_11 = V_90 -> V_11 ;
V_88 -> V_148 = V_90 -> V_148 / V_149 ;
V_88 -> V_147 = V_90 -> V_147 ;
V_88 -> V_113 = V_90 -> V_113 ;
F_64 ( & V_88 -> V_76 , & V_90 -> V_76 ) ;
}
static inline int
F_164 ( struct V_2 * V_2 ,
const struct V_269 * V_270 ,
struct V_269 T_7 * V_271 )
{
int V_158 , V_272 = 0 ;
struct V_52 * V_53 ;
struct V_268 V_273 ;
int V_131 = 0 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_53 -> V_39 != V_151 || ! F_37 ( V_53 -> V_2 , V_2 ) )
continue;
if ( V_272 >= V_270 -> V_152 )
goto V_66;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
F_162 ( & V_273 , V_53 ) ;
if ( F_165 ( & V_271 -> V_274 [ V_272 ] ,
& V_273 , sizeof( V_273 ) ) ) {
V_131 = - V_247 ;
goto V_66;
}
V_272 ++ ;
}
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_53 -> V_39 != V_151 || ! F_37 ( V_53 -> V_2 , V_2 ) )
continue;
if ( V_272 >= V_270 -> V_152 )
goto V_66;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
F_162 ( & V_273 , V_53 ) ;
if ( F_165 ( & V_271 -> V_274 [ V_272 ] ,
& V_273 , sizeof( V_273 ) ) ) {
V_131 = - V_247 ;
goto V_66;
}
V_272 ++ ;
}
}
V_66:
return V_131 ;
}
static inline int
F_166 ( struct V_2 * V_2 , const struct V_275 * V_270 ,
struct V_275 T_7 * V_271 )
{
struct V_52 * V_53 ;
union V_41 V_4 = { . V_45 = V_270 -> V_4 } ;
int V_131 = 0 ;
if ( V_270 -> V_51 )
V_53 = F_38 ( V_2 , V_151 , V_270 -> V_51 ) ;
else
V_53 = F_34 ( V_2 , V_151 , V_270 -> V_57 , & V_4 ,
V_270 -> V_42 ) ;
if ( V_53 ) {
int V_272 = 0 ;
struct V_74 * V_75 ;
struct V_276 V_273 ;
F_35 (dest, &svc->destinations, n_list) {
if ( V_272 >= V_270 -> V_113 )
break;
V_273 . V_4 = V_75 -> V_4 . V_45 ;
V_273 . V_42 = V_75 -> V_42 ;
V_273 . V_100 = F_14 ( & V_75 -> V_100 ) ;
V_273 . V_101 = F_14 ( & V_75 -> V_101 ) ;
V_273 . V_108 = V_75 -> V_108 ;
V_273 . V_110 = V_75 -> V_110 ;
V_273 . V_128 = F_14 ( & V_75 -> V_128 ) ;
V_273 . V_129 = F_14 ( & V_75 -> V_129 ) ;
V_273 . V_130 = F_14 ( & V_75 -> V_130 ) ;
F_64 ( & V_273 . V_76 , & V_75 -> V_76 ) ;
if ( F_165 ( & V_271 -> V_274 [ V_272 ] ,
& V_273 , sizeof( V_273 ) ) ) {
V_131 = - V_247 ;
break;
}
V_272 ++ ;
}
} else
V_131 = - V_262 ;
return V_131 ;
}
static inline void
F_167 ( struct V_2 * V_2 , struct V_217 * V_138 )
{
#if F_150 ( V_218 ) || F_150 ( V_219 )
struct V_220 * V_221 ;
#endif
#ifdef V_218
V_221 = F_151 ( V_2 , V_67 ) ;
V_138 -> V_222 = V_221 -> V_225 [ V_226 ] / V_149 ;
V_138 -> V_223 = V_221 -> V_225 [ V_227 ] / V_149 ;
#endif
#ifdef V_219
V_221 = F_151 ( V_2 , V_228 ) ;
V_138 -> V_224 =
V_221 -> V_225 [ V_229 ] / V_149 ;
#endif
}
static int
F_168 ( struct V_235 * V_236 , int V_237 , void T_7 * V_238 , int * V_239 )
{
unsigned char V_240 [ 128 ] ;
int V_131 = 0 ;
unsigned int V_277 ;
struct V_2 * V_2 = F_155 ( V_236 ) ;
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_169 ( ! V_2 ) ;
if ( ! F_156 ( V_242 ) )
return - V_243 ;
if ( V_237 < V_244 || V_237 > V_278 )
return - V_121 ;
if ( * V_239 < V_279 [ F_170 ( V_237 ) ] ) {
F_27 ( L_60 ,
* V_239 , V_279 [ F_170 ( V_237 ) ] ) ;
return - V_121 ;
}
V_277 = V_279 [ F_170 ( V_237 ) ] ;
if ( V_277 > 128 )
return - V_121 ;
if ( F_158 ( V_240 , V_238 , V_277 ) != 0 )
return - V_247 ;
if ( F_159 ( & V_160 ) )
return - V_248 ;
switch ( V_237 ) {
case V_280 :
{
char V_281 [ 64 ] ;
sprintf ( V_281 , L_61 ,
F_134 ( V_200 ) , V_201 ) ;
if ( F_165 ( V_238 , V_281 , strlen ( V_281 ) + 1 ) != 0 ) {
V_131 = - V_247 ;
goto V_66;
}
* V_239 = strlen ( V_281 ) + 1 ;
}
break;
case V_282 :
{
struct V_283 V_284 ;
V_284 . V_285 = V_200 ;
V_284 . V_286 = V_201 ;
V_284 . V_152 = V_14 -> V_152 ;
if ( F_165 ( V_238 , & V_284 , sizeof( V_284 ) ) != 0 )
V_131 = - V_247 ;
}
break;
case V_287 :
{
struct V_269 * V_270 ;
int V_286 ;
V_270 = (struct V_269 * ) V_240 ;
V_286 = sizeof( * V_270 ) +
sizeof( struct V_268 ) * V_270 -> V_152 ;
if ( * V_239 != V_286 ) {
F_27 ( L_62 , * V_239 , V_286 ) ;
V_131 = - V_121 ;
goto V_66;
}
V_131 = F_164 ( V_2 , V_270 , V_238 ) ;
}
break;
case V_288 :
{
struct V_268 * V_273 ;
struct V_52 * V_53 ;
union V_41 V_4 ;
V_273 = (struct V_268 * ) V_240 ;
V_4 . V_45 = V_273 -> V_4 ;
if ( V_273 -> V_51 )
V_53 = F_38 ( V_2 , V_151 , V_273 -> V_51 ) ;
else
V_53 = F_34 ( V_2 , V_151 ,
V_273 -> V_57 , & V_4 ,
V_273 -> V_42 ) ;
if ( V_53 ) {
F_162 ( V_273 , V_53 ) ;
if ( F_165 ( V_238 , V_273 , sizeof( * V_273 ) ) != 0 )
V_131 = - V_247 ;
} else
V_131 = - V_262 ;
}
break;
case V_289 :
{
struct V_275 * V_270 ;
int V_286 ;
V_270 = (struct V_275 * ) V_240 ;
V_286 = sizeof( * V_270 ) +
sizeof( struct V_276 ) * V_270 -> V_113 ;
if ( * V_239 != V_286 ) {
F_27 ( L_62 , * V_239 , V_286 ) ;
V_131 = - V_121 ;
goto V_66;
}
V_131 = F_166 ( V_2 , V_270 , V_238 ) ;
}
break;
case V_290 :
{
struct V_217 V_291 ;
F_167 ( V_2 , & V_291 ) ;
if ( F_165 ( V_238 , & V_291 , sizeof( V_291 ) ) != 0 )
V_131 = - V_247 ;
}
break;
case V_292 :
{
struct V_253 V_293 [ 2 ] ;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
if ( V_14 -> V_294 & V_295 ) {
V_293 [ 0 ] . V_255 = V_295 ;
F_163 ( V_293 [ 0 ] . V_256 , V_14 -> V_296 ,
sizeof( V_293 [ 0 ] . V_256 ) ) ;
V_293 [ 0 ] . V_257 = V_14 -> V_297 ;
}
if ( V_14 -> V_294 & V_298 ) {
V_293 [ 1 ] . V_255 = V_298 ;
F_163 ( V_293 [ 1 ] . V_256 , V_14 -> V_299 ,
sizeof( V_293 [ 1 ] . V_256 ) ) ;
V_293 [ 1 ] . V_257 = V_14 -> V_300 ;
}
if ( F_165 ( V_238 , & V_293 , sizeof( V_293 ) ) != 0 )
V_131 = - V_247 ;
}
break;
default:
V_131 = - V_121 ;
}
V_66:
F_112 ( & V_160 ) ;
return V_131 ;
}
static int F_171 ( struct V_301 * V_302 , int V_303 ,
struct V_89 * V_76 )
{
struct V_87 V_216 ;
struct V_304 * V_305 = F_172 ( V_302 , V_303 ) ;
if ( ! V_305 )
return - V_306 ;
F_64 ( & V_216 , V_76 ) ;
F_173 ( V_302 , V_307 , V_216 . V_92 ) ;
F_173 ( V_302 , V_308 , V_216 . V_93 ) ;
F_173 ( V_302 , V_309 , V_216 . V_94 ) ;
F_174 ( V_302 , V_310 , V_216 . V_95 ) ;
F_174 ( V_302 , V_311 , V_216 . V_96 ) ;
F_173 ( V_302 , V_312 , V_216 . V_208 ) ;
F_173 ( V_302 , V_313 , V_216 . V_209 ) ;
F_173 ( V_302 , V_314 , V_216 . V_210 ) ;
F_173 ( V_302 , V_315 , V_216 . V_211 ) ;
F_173 ( V_302 , V_316 , V_216 . V_212 ) ;
F_175 ( V_302 , V_305 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_305 ) ;
return - V_306 ;
}
static int F_177 ( struct V_301 * V_302 ,
struct V_52 * V_53 )
{
struct V_304 * V_318 ;
struct V_319 V_11 = { . V_11 = V_53 -> V_11 ,
. V_320 = ~ 0 } ;
V_318 = F_172 ( V_302 , V_321 ) ;
if ( ! V_318 )
return - V_306 ;
F_178 ( V_302 , V_322 , V_53 -> V_39 ) ;
if ( V_53 -> V_51 ) {
F_173 ( V_302 , V_323 , V_53 -> V_51 ) ;
} else {
F_178 ( V_302 , V_324 , V_53 -> V_57 ) ;
F_179 ( V_302 , V_325 , sizeof( V_53 -> V_4 ) , & V_53 -> V_4 ) ;
F_178 ( V_302 , V_326 , V_53 -> V_42 ) ;
}
F_180 ( V_302 , V_327 , V_53 -> V_114 -> V_164 ) ;
if ( V_53 -> V_143 )
F_180 ( V_302 , V_328 , V_53 -> V_143 -> V_164 ) ;
F_179 ( V_302 , V_329 , sizeof( V_11 ) , & V_11 ) ;
F_173 ( V_302 , V_330 , V_53 -> V_148 / V_149 ) ;
F_173 ( V_302 , V_331 , V_53 -> V_147 ) ;
if ( F_171 ( V_302 , V_332 , & V_53 -> V_76 ) )
goto V_317;
F_175 ( V_302 , V_318 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_318 ) ;
return - V_306 ;
}
static int F_181 ( struct V_301 * V_302 ,
struct V_52 * V_53 ,
struct V_333 * V_334 )
{
void * V_335 ;
V_335 = F_182 ( V_302 , F_183 ( V_334 -> V_302 ) . V_336 , V_334 -> V_337 -> V_338 ,
& V_339 , V_340 ,
V_341 ) ;
if ( ! V_335 )
return - V_306 ;
if ( F_177 ( V_302 , V_53 ) < 0 )
goto V_317;
return F_184 ( V_302 , V_335 ) ;
V_317:
F_185 ( V_302 , V_335 ) ;
return - V_306 ;
}
static int F_186 ( struct V_301 * V_302 ,
struct V_333 * V_334 )
{
int V_158 = 0 , V_16 ;
int V_214 = V_334 -> args [ 0 ] ;
struct V_52 * V_53 ;
struct V_2 * V_2 = F_187 ( V_302 ) ;
F_111 ( & V_160 ) ;
for ( V_16 = 0 ; V_16 < V_159 ; V_16 ++ ) {
F_35 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_158 <= V_214 || ! F_37 ( V_53 -> V_2 , V_2 ) )
continue;
if ( F_181 ( V_302 , V_53 , V_334 ) < 0 ) {
V_158 -- ;
goto V_317;
}
}
}
for ( V_16 = 0 ; V_16 < V_159 ; V_16 ++ ) {
F_35 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_158 <= V_214 || ! F_37 ( V_53 -> V_2 , V_2 ) )
continue;
if ( F_181 ( V_302 , V_53 , V_334 ) < 0 ) {
V_158 -- ;
goto V_317;
}
}
}
V_317:
F_112 ( & V_160 ) ;
V_334 -> args [ 0 ] = V_158 ;
return V_302 -> V_239 ;
}
static int F_188 ( struct V_2 * V_2 ,
struct V_137 * V_230 ,
struct V_304 * V_342 , int V_343 ,
struct V_52 * * V_344 )
{
struct V_304 * V_345 [ V_346 + 1 ] ;
struct V_304 * V_347 , * V_348 , * V_349 , * V_350 , * V_351 ;
struct V_52 * V_53 ;
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
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
V_230 -> V_39 = F_190 ( V_347 ) ;
#ifdef F_23
if ( V_230 -> V_39 != V_151 && V_230 -> V_39 != V_46 )
#else
if ( V_230 -> V_39 != V_151 )
#endif
return - V_353 ;
if ( V_349 ) {
V_230 -> V_57 = V_67 ;
V_230 -> V_51 = F_191 ( V_349 ) ;
} else {
V_230 -> V_57 = F_190 ( V_350 ) ;
F_192 ( & V_230 -> V_4 , V_351 , sizeof( V_230 -> V_4 ) ) ;
V_230 -> V_42 = F_190 ( V_348 ) ;
V_230 -> V_51 = 0 ;
}
if ( V_230 -> V_51 )
V_53 = F_38 ( V_2 , V_230 -> V_39 , V_230 -> V_51 ) ;
else
V_53 = F_34 ( V_2 , V_230 -> V_39 , V_230 -> V_57 ,
& V_230 -> V_4 , V_230 -> V_42 ) ;
* V_344 = V_53 ;
if ( V_343 ) {
struct V_304 * V_354 , * V_355 , * V_356 , * V_357 ,
* V_358 ;
struct V_319 V_11 ;
V_354 = V_345 [ V_327 ] ;
V_356 = V_345 [ V_328 ] ;
V_355 = V_345 [ V_329 ] ;
V_357 = V_345 [ V_330 ] ;
V_358 = V_345 [ V_331 ] ;
if ( ! ( V_354 && V_355 && V_357 && V_358 ) )
return - V_121 ;
F_192 ( & V_11 , V_355 , sizeof( V_11 ) ) ;
if ( V_53 )
V_230 -> V_11 = V_53 -> V_11 ;
V_230 -> V_11 = ( V_230 -> V_11 & ~ V_11 . V_320 ) |
( V_11 . V_11 & V_11 . V_320 ) ;
V_230 -> V_144 = F_193 ( V_354 ) ;
V_230 -> V_146 = V_356 ? F_193 ( V_356 ) : NULL ;
V_230 -> V_148 = F_191 ( V_357 ) ;
V_230 -> V_147 = F_191 ( V_358 ) ;
}
return 0 ;
}
static struct V_52 * F_194 ( struct V_2 * V_2 ,
struct V_304 * V_342 )
{
struct V_137 V_230 ;
struct V_52 * V_53 ;
int V_131 ;
V_131 = F_188 ( V_2 , & V_230 , V_342 , 0 , & V_53 ) ;
return V_131 ? F_195 ( V_131 ) : V_53 ;
}
static int F_196 ( struct V_301 * V_302 , struct V_74 * V_75 )
{
struct V_304 * V_359 ;
V_359 = F_172 ( V_302 , V_360 ) ;
if ( ! V_359 )
return - V_306 ;
F_179 ( V_302 , V_361 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ;
F_178 ( V_302 , V_362 , V_75 -> V_42 ) ;
F_173 ( V_302 , V_363 ,
F_14 ( & V_75 -> V_100 ) & V_104 ) ;
F_173 ( V_302 , V_364 , F_14 ( & V_75 -> V_101 ) ) ;
F_173 ( V_302 , V_365 , V_75 -> V_108 ) ;
F_173 ( V_302 , V_366 , V_75 -> V_110 ) ;
F_173 ( V_302 , V_367 ,
F_14 ( & V_75 -> V_128 ) ) ;
F_173 ( V_302 , V_368 ,
F_14 ( & V_75 -> V_129 ) ) ;
F_173 ( V_302 , V_369 ,
F_14 ( & V_75 -> V_130 ) ) ;
if ( F_171 ( V_302 , V_370 , & V_75 -> V_76 ) )
goto V_317;
F_175 ( V_302 , V_359 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_359 ) ;
return - V_306 ;
}
static int F_197 ( struct V_301 * V_302 , struct V_74 * V_75 ,
struct V_333 * V_334 )
{
void * V_335 ;
V_335 = F_182 ( V_302 , F_183 ( V_334 -> V_302 ) . V_336 , V_334 -> V_337 -> V_338 ,
& V_339 , V_340 ,
V_371 ) ;
if ( ! V_335 )
return - V_306 ;
if ( F_196 ( V_302 , V_75 ) < 0 )
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
int V_214 = V_334 -> args [ 0 ] ;
struct V_52 * V_53 ;
struct V_74 * V_75 ;
struct V_304 * V_345 [ V_372 + 1 ] ;
struct V_2 * V_2 = F_187 ( V_302 ) ;
F_111 ( & V_160 ) ;
if ( F_199 ( V_334 -> V_337 , V_373 , V_345 ,
V_372 , V_374 ) )
goto V_145;
V_53 = F_194 ( V_2 , V_345 [ V_321 ] ) ;
if ( F_200 ( V_53 ) || V_53 == NULL )
goto V_145;
F_35 (dest, &svc->destinations, n_list) {
if ( ++ V_158 <= V_214 )
continue;
if ( F_197 ( V_302 , V_75 , V_334 ) < 0 ) {
V_158 -- ;
goto V_317;
}
}
V_317:
V_334 -> args [ 0 ] = V_158 ;
V_145:
F_112 ( & V_160 ) ;
return V_302 -> V_239 ;
}
static int F_201 ( struct V_97 * V_98 ,
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
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
F_192 ( & V_98 -> V_4 , V_351 , sizeof( V_98 -> V_4 ) ) ;
V_98 -> V_42 = F_190 ( V_348 ) ;
if ( V_343 ) {
struct V_304 * V_377 , * V_378 , * V_379 ,
* V_380 ;
V_377 = V_345 [ V_363 ] ;
V_378 = V_345 [ V_364 ] ;
V_379 = V_345 [ V_365 ] ;
V_380 = V_345 [ V_366 ] ;
if ( ! ( V_377 && V_378 && V_379 && V_380 ) )
return - V_121 ;
V_98 -> V_100 = F_191 ( V_377 )
& V_104 ;
V_98 -> V_101 = F_191 ( V_378 ) ;
V_98 -> V_108 = F_191 ( V_379 ) ;
V_98 -> V_110 = F_191 ( V_380 ) ;
}
return 0 ;
}
static int F_202 ( struct V_301 * V_302 , T_2 V_255 ,
const char * V_256 , T_2 V_257 )
{
struct V_304 * V_381 ;
V_381 = F_172 ( V_302 , V_382 ) ;
if ( ! V_381 )
return - V_306 ;
F_173 ( V_302 , V_383 , V_255 ) ;
F_180 ( V_302 , V_384 , V_256 ) ;
F_173 ( V_302 , V_385 , V_257 ) ;
F_175 ( V_302 , V_381 ) ;
return 0 ;
V_317:
F_176 ( V_302 , V_381 ) ;
return - V_306 ;
}
static int F_203 ( struct V_301 * V_302 , T_2 V_255 ,
const char * V_256 , T_2 V_257 ,
struct V_333 * V_334 )
{
void * V_335 ;
V_335 = F_182 ( V_302 , F_183 ( V_334 -> V_302 ) . V_336 , V_334 -> V_337 -> V_338 ,
& V_339 , V_340 ,
V_386 ) ;
if ( ! V_335 )
return - V_306 ;
if ( F_202 ( V_302 , V_255 , V_256 , V_257 ) )
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
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_111 ( & V_160 ) ;
if ( ( V_14 -> V_294 & V_295 ) && ! V_334 -> args [ 0 ] ) {
if ( F_203 ( V_302 , V_295 ,
V_14 -> V_296 ,
V_14 -> V_297 , V_334 ) < 0 )
goto V_317;
V_334 -> args [ 0 ] = 1 ;
}
if ( ( V_14 -> V_294 & V_298 ) && ! V_334 -> args [ 1 ] ) {
if ( F_203 ( V_302 , V_298 ,
V_14 -> V_299 ,
V_14 -> V_300 , V_334 ) < 0 )
goto V_317;
V_334 -> args [ 1 ] = 1 ;
}
V_317:
F_112 ( & V_160 ) ;
return V_302 -> V_239 ;
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
struct V_217 V_291 ;
F_167 ( V_2 , & V_291 ) ;
if ( V_345 [ V_387 ] )
V_291 . V_222 = F_191 ( V_345 [ V_387 ] ) ;
if ( V_345 [ V_388 ] )
V_291 . V_223 =
F_191 ( V_345 [ V_388 ] ) ;
if ( V_345 [ V_389 ] )
V_291 . V_224 = F_191 ( V_345 [ V_389 ] ) ;
return F_149 ( V_2 , & V_291 ) ;
}
static int F_208 ( struct V_301 * V_302 , struct V_390 * V_284 )
{
struct V_52 * V_53 = NULL ;
struct V_137 V_230 ;
struct V_97 V_98 ;
int V_131 = 0 , V_237 ;
int V_391 = 0 , V_392 = 0 ;
struct V_2 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_187 ( V_302 ) ;
V_14 = F_40 ( V_2 ) ;
V_237 = V_284 -> V_393 -> V_237 ;
F_111 ( & V_160 ) ;
if ( V_237 == V_394 ) {
V_131 = F_109 ( V_2 ) ;
goto V_66;
} else if ( V_237 == V_395 ) {
V_131 = F_207 ( V_2 , V_284 -> V_345 ) ;
goto V_66;
} else if ( V_237 == V_386 ||
V_237 == V_396 ) {
struct V_304 * V_397 [ V_398 + 1 ] ;
if ( ! V_284 -> V_345 [ V_382 ] ||
F_189 ( V_397 , V_398 ,
V_284 -> V_345 [ V_382 ] ,
V_399 ) ) {
V_131 = - V_121 ;
goto V_66;
}
if ( V_237 == V_386 )
V_131 = F_205 ( V_2 , V_397 ) ;
else
V_131 = F_206 ( V_2 , V_397 ) ;
goto V_66;
} else if ( V_237 == V_400 &&
! V_284 -> V_345 [ V_321 ] ) {
V_131 = F_117 ( V_2 ) ;
goto V_66;
}
if ( V_237 == V_341 || V_237 == V_401 )
V_391 = 1 ;
V_131 = F_188 ( V_2 , & V_230 ,
V_284 -> V_345 [ V_321 ] ,
V_391 , & V_53 ) ;
if ( V_131 )
goto V_66;
if ( ( V_237 != V_341 ) && ( V_53 == NULL ) ) {
V_131 = - V_262 ;
goto V_66;
}
if ( V_237 == V_371 || V_237 == V_402 ||
V_237 == V_403 ) {
if ( V_237 != V_403 )
V_392 = 1 ;
V_131 = F_201 ( & V_98 ,
V_284 -> V_345 [ V_360 ] ,
V_392 ) ;
if ( V_131 )
goto V_66;
}
switch ( V_237 ) {
case V_341 :
if ( V_53 == NULL )
V_131 = F_93 ( V_2 , & V_230 , & V_53 ) ;
else
V_131 = - V_133 ;
break;
case V_401 :
V_131 = F_104 ( V_53 , & V_230 ) ;
break;
case V_404 :
V_131 = F_108 ( V_53 ) ;
break;
case V_371 :
V_131 = F_86 ( V_53 , & V_98 ) ;
break;
case V_402 :
V_131 = F_88 ( V_53 , & V_98 ) ;
break;
case V_403 :
V_131 = F_92 ( V_53 , & V_98 ) ;
break;
case V_400 :
V_131 = F_116 ( V_53 ) ;
break;
default:
V_131 = - V_121 ;
}
V_66:
F_112 ( & V_160 ) ;
return V_131 ;
}
static int F_209 ( struct V_301 * V_302 , struct V_390 * V_284 )
{
struct V_301 * V_405 ;
void * V_406 ;
int V_131 , V_237 , V_407 ;
struct V_2 * V_2 ;
struct V_13 * V_14 ;
V_2 = F_187 ( V_302 ) ;
V_14 = F_40 ( V_2 ) ;
V_237 = V_284 -> V_393 -> V_237 ;
if ( V_237 == V_408 )
V_407 = V_341 ;
else if ( V_237 == V_409 )
V_407 = V_410 ;
else if ( V_237 == V_411 )
V_407 = V_395 ;
else {
F_27 ( L_63 ) ;
return - V_121 ;
}
V_405 = F_210 ( V_412 , V_124 ) ;
if ( ! V_405 )
return - V_125 ;
F_111 ( & V_160 ) ;
V_406 = F_211 ( V_405 , V_284 , & V_339 , 0 , V_407 ) ;
if ( V_406 == NULL )
goto V_317;
switch ( V_237 ) {
case V_408 :
{
struct V_52 * V_53 ;
V_53 = F_194 ( V_2 ,
V_284 -> V_345 [ V_321 ] ) ;
if ( F_200 ( V_53 ) ) {
V_131 = F_212 ( V_53 ) ;
goto V_145;
} else if ( V_53 ) {
V_131 = F_177 ( V_405 , V_53 ) ;
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
struct V_217 V_291 ;
F_167 ( V_2 , & V_291 ) ;
#ifdef V_218
F_173 ( V_405 , V_387 , V_291 . V_222 ) ;
F_173 ( V_405 , V_388 ,
V_291 . V_223 ) ;
#endif
#ifdef V_219
F_173 ( V_405 , V_389 , V_291 . V_224 ) ;
#endif
break;
}
case V_409 :
F_173 ( V_405 , V_413 , V_200 ) ;
F_173 ( V_405 , V_414 ,
V_201 ) ;
break;
}
F_184 ( V_405 , V_406 ) ;
V_131 = F_213 ( V_405 , V_284 ) ;
goto V_66;
V_317:
F_27 ( L_64 ) ;
V_131 = - V_306 ;
V_145:
F_214 ( V_405 ) ;
V_66:
F_112 ( & V_160 ) ;
return V_131 ;
}
static int T_10 F_215 ( void )
{
return F_216 ( & V_339 ,
V_415 , F_217 ( V_415 ) ) ;
}
static void F_218 ( void )
{
F_219 ( & V_339 ) ;
}
int T_11 F_220 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_13 * V_14 = F_40 ( V_2 ) ;
struct T_6 * V_416 ;
F_8 ( & V_14 -> V_26 , 0 ) ;
F_84 ( & V_14 -> V_24 ) ;
F_84 ( & V_14 -> V_27 ) ;
F_84 ( & V_14 -> V_32 ) ;
if ( ! F_37 ( V_2 , & V_417 ) ) {
V_416 = F_221 ( V_418 , sizeof( V_418 ) , V_124 ) ;
if ( V_416 == NULL )
return - V_125 ;
} else
V_416 = V_418 ;
V_158 = 0 ;
V_14 -> V_23 = 1024 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_23 ;
V_14 -> V_31 = 10 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_31 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_25 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_28 ;
#ifdef F_222
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_419 ;
#endif
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_33 ;
V_14 -> V_420 = 1 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_420 ;
V_14 -> V_421 = 1 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_421 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_422 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_423 ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_424 ;
V_14 -> V_425 [ 0 ] = V_426 ;
V_14 -> V_425 [ 1 ] = V_427 ;
V_416 [ V_158 ] . V_181 = & V_14 -> V_425 ;
V_416 [ V_158 ++ ] . V_428 = sizeof( V_14 -> V_425 ) ;
V_416 [ V_158 ++ ] . V_181 = & V_14 -> V_429 ;
V_14 -> V_430 = F_223 ( V_2 , V_431 ,
V_416 ) ;
if ( V_14 -> V_430 == NULL ) {
if ( ! F_37 ( V_2 , & V_417 ) )
F_50 ( V_416 ) ;
return - V_125 ;
}
F_75 ( V_2 , & V_14 -> V_171 ) ;
V_14 -> V_432 = V_416 ;
F_224 ( & V_14 -> V_36 , F_12 ) ;
F_16 ( & V_14 -> V_36 , V_37 ) ;
return 0 ;
}
void T_11 F_225 ( struct V_2 * V_2 )
{
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_226 ( & V_14 -> V_36 ) ;
F_227 ( & V_14 -> V_36 . V_35 ) ;
F_228 ( V_14 -> V_430 ) ;
}
int T_11 F_220 ( struct V_2 * V_2 ) { return 0 ; }
void T_11 F_225 ( struct V_2 * V_2 ) { }
int T_11 F_229 ( struct V_2 * V_2 )
{
int V_158 ;
struct V_13 * V_14 = F_40 ( V_2 ) ;
V_14 -> V_83 = F_230 ( V_14 -> V_83 ) ;
for ( V_158 = 0 ; V_158 < V_433 ; V_158 ++ )
F_55 ( & V_14 -> V_81 [ V_158 ] ) ;
F_55 ( & V_14 -> V_135 ) ;
F_8 ( & V_14 -> V_68 , 0 ) ;
F_8 ( & V_14 -> V_72 , 0 ) ;
V_14 -> V_171 . V_77 = F_82 ( struct V_126 ) ;
if ( ! V_14 -> V_171 . V_77 ) {
F_27 ( L_65 , V_56 ) ;
return - V_125 ;
}
F_84 ( & V_14 -> V_171 . V_91 ) ;
F_231 ( V_2 , L_66 , 0 , & V_434 ) ;
F_231 ( V_2 , L_67 , 0 , & V_435 ) ;
F_231 ( V_2 , L_68 , 0 ,
& V_436 ) ;
if ( F_220 ( V_2 ) )
goto V_437;
return 0 ;
V_437:
F_49 ( V_14 -> V_171 . V_77 ) ;
return - V_125 ;
}
void T_12 F_232 ( struct V_2 * V_2 )
{
struct V_13 * V_14 = F_40 ( V_2 ) ;
F_63 ( V_2 ) ;
F_90 ( V_2 , & V_14 -> V_171 ) ;
F_225 ( V_2 ) ;
F_233 ( V_2 , L_68 ) ;
F_233 ( V_2 , L_67 ) ;
F_233 ( V_2 , L_66 ) ;
F_49 ( V_14 -> V_171 . V_77 ) ;
}
int T_10 F_234 ( void )
{
int V_158 ;
int V_131 ;
F_78 ( 2 ) ;
for( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
F_55 ( & V_59 [ V_158 ] ) ;
F_55 ( & V_61 [ V_158 ] ) ;
}
F_235 () ;
V_131 = F_236 ( & V_438 ) ;
if ( V_131 ) {
F_27 ( L_69 ) ;
goto V_439;
}
V_131 = F_215 () ;
if ( V_131 ) {
F_27 ( L_70 ) ;
goto V_440;
}
V_131 = F_237 ( & V_441 ) ;
if ( V_131 < 0 )
goto V_442;
F_85 ( 2 ) ;
return 0 ;
V_442:
F_218 () ;
V_440:
F_238 ( & V_438 ) ;
V_439:
return V_131 ;
}
void F_239 ( void )
{
F_78 ( 2 ) ;
F_218 () ;
F_238 ( & V_438 ) ;
F_85 ( 2 ) ;
}
