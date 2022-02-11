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
V_75 -> V_55 = V_55 ;
}
static void F_46 ( struct V_54 * V_55 )
{
if ( V_55 -> V_76 . V_77 )
F_47 ( V_55 -> V_76 . V_77 ) ;
F_48 ( V_55 ) ;
}
static void
F_49 ( struct V_74 * V_75 )
{
struct V_54 * V_55 = V_75 -> V_55 ;
V_75 -> V_55 = NULL ;
if ( F_50 ( & V_55 -> V_64 ) ) {
F_42 ( 3 , L_6 ,
V_55 -> V_53 ,
F_44 ( V_55 -> V_40 , & V_55 -> V_4 ) ,
F_23 ( V_55 -> V_43 ) ) ;
F_46 ( V_55 ) ;
}
}
static inline unsigned int F_51 ( int V_40 ,
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
return ( F_25 ( V_45 ) ^ ( V_44 >> V_78 ) ^ V_44 )
& V_79 ;
}
static void F_52 ( struct V_14 * V_15 , struct V_74 * V_75 )
{
unsigned int V_56 ;
if ( V_75 -> V_80 )
return;
V_56 = F_51 ( V_75 -> V_40 , & V_75 -> V_4 , V_75 -> V_43 ) ;
F_30 ( & V_75 -> V_81 , & V_15 -> V_82 [ V_56 ] ) ;
V_75 -> V_80 = 1 ;
}
static void F_53 ( struct V_74 * V_75 )
{
if ( V_75 -> V_80 ) {
F_33 ( & V_75 -> V_81 ) ;
V_75 -> V_80 = 0 ;
}
}
bool F_54 ( struct V_2 * V_2 , int V_40 , T_4 V_59 ,
const union V_42 * V_7 , T_1 V_83 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
unsigned int V_56 ;
struct V_74 * V_75 ;
V_56 = F_51 ( V_40 , V_7 , V_83 ) ;
F_55 () ;
F_36 (dest, &ipvs->rs_table[hash], d_list) {
if ( V_75 -> V_43 == V_83 &&
V_75 -> V_40 == V_40 &&
F_37 ( V_40 , & V_75 -> V_4 , V_7 ) &&
( V_75 -> V_59 == V_59 || V_75 -> V_84 ) ) {
F_56 () ;
return true ;
}
}
F_56 () ;
return false ;
}
static struct V_74 *
F_57 ( struct V_54 * V_55 , const union V_42 * V_7 ,
T_1 V_83 )
{
struct V_74 * V_75 ;
F_58 (dest, &svc->destinations, n_list) {
if ( ( V_75 -> V_40 == V_55 -> V_40 )
&& F_37 ( V_55 -> V_40 , & V_75 -> V_4 , V_7 )
&& ( V_75 -> V_43 == V_83 ) ) {
return V_75 ;
}
}
return NULL ;
}
struct V_74 * F_59 ( struct V_2 * V_2 , int V_40 ,
const union V_42 * V_7 ,
T_1 V_83 ,
const union V_42 * V_65 ,
T_1 V_66 , T_4 V_59 , T_3 V_53 ,
T_3 V_12 )
{
struct V_74 * V_75 ;
struct V_54 * V_55 ;
T_1 V_43 = V_83 ;
V_55 = F_40 ( V_2 , V_40 , V_53 , V_59 , V_65 , V_66 ) ;
if ( ! V_55 )
return NULL ;
if ( V_53 && ( V_12 & V_85 ) != V_86 )
V_43 = 0 ;
V_75 = F_57 ( V_55 , V_7 , V_43 ) ;
if ( ! V_75 )
V_75 = F_57 ( V_55 , V_7 , V_43 ^ V_83 ) ;
return V_75 ;
}
void F_60 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_14 ( V_88 ,
struct V_89 ,
V_87 ) ;
F_4 ( V_90 -> V_91 ) ;
F_48 ( V_90 ) ;
}
static void F_61 ( struct V_74 * V_75 )
{
struct V_89 * V_92 ;
V_92 = F_62 ( V_75 -> V_90 , 1 ) ;
if ( V_92 ) {
F_63 ( V_75 -> V_90 , NULL ) ;
F_64 ( & V_92 -> V_87 , F_60 ) ;
}
}
static struct V_74 *
F_65 ( struct V_54 * V_55 , const union V_42 * V_7 ,
T_1 V_83 )
{
struct V_74 * V_75 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_66 ( & V_15 -> V_93 ) ;
F_67 (dest, &ipvs->dest_trash, t_list) {
F_42 ( 3 , L_7
L_8 ,
V_75 -> V_84 ,
F_44 ( V_55 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_68 ( V_94 , & V_75 -> V_95 ) )
continue;
if ( V_75 -> V_40 == V_55 -> V_40 &&
F_37 ( V_55 -> V_40 , & V_75 -> V_4 , V_7 ) &&
V_75 -> V_43 == V_83 &&
V_75 -> V_84 == V_55 -> V_53 &&
V_75 -> V_59 == V_55 -> V_59 &&
( V_55 -> V_53 ||
( F_37 ( V_55 -> V_40 , & V_75 -> V_65 , & V_55 -> V_4 ) &&
V_75 -> V_66 == V_55 -> V_43 ) ) ) {
F_69 ( & V_75 -> V_96 ) ;
F_70 ( V_75 ) ;
goto V_67;
}
}
V_75 = NULL ;
V_67:
F_71 ( & V_15 -> V_93 ) ;
return V_75 ;
}
static void F_72 ( struct V_74 * V_75 )
{
F_61 ( V_75 ) ;
F_49 ( V_75 ) ;
F_47 ( V_75 -> V_76 . V_77 ) ;
F_48 ( V_75 ) ;
}
static void F_73 ( struct V_2 * V_2 )
{
struct V_74 * V_75 , * V_97 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_74 ( & V_15 -> V_98 ) ;
F_75 (dest, nxt, &ipvs->dest_trash, t_list) {
F_69 ( & V_75 -> V_96 ) ;
F_72 ( V_75 ) ;
}
}
static void
F_76 ( struct V_99 * V_9 , struct V_100 * V_101 )
{
#define F_77 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_66 ( & V_101 -> V_102 ) ;
F_77 ( V_103 ) ;
F_77 ( V_104 ) ;
F_77 ( V_105 ) ;
F_77 ( V_106 ) ;
F_77 ( V_107 ) ;
F_78 ( V_9 , V_101 ) ;
F_71 ( & V_101 -> V_102 ) ;
}
static void
F_79 ( struct V_100 * V_76 )
{
F_66 ( & V_76 -> V_102 ) ;
#define F_80 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_80 ( V_103 ) ;
F_80 ( V_104 ) ;
F_80 ( V_105 ) ;
F_80 ( V_106 ) ;
F_80 ( V_107 ) ;
F_81 ( V_76 ) ;
F_71 ( & V_76 -> V_102 ) ;
}
static void
F_82 ( struct V_54 * V_55 , struct V_74 * V_75 ,
struct V_108 * V_109 , int V_110 )
{
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
struct V_111 * V_112 ;
int V_113 ;
F_9 ( & V_75 -> V_114 , V_109 -> V_114 ) ;
V_113 = V_109 -> V_113 & V_115 ;
V_113 |= V_116 ;
if ( ( V_113 & V_85 ) != V_86 ) {
V_113 |= V_117 ;
} else {
F_52 ( V_15 , V_75 ) ;
}
F_9 ( & V_75 -> V_113 , V_113 ) ;
if ( ! V_75 -> V_55 ) {
F_45 ( V_75 , V_55 ) ;
} else {
if ( V_75 -> V_55 != V_55 ) {
F_49 ( V_75 ) ;
F_79 ( & V_75 -> V_76 ) ;
F_45 ( V_75 , V_55 ) ;
}
}
V_75 -> V_12 |= V_118 ;
if ( V_109 -> V_119 == 0 || V_109 -> V_119 > V_75 -> V_119 )
V_75 -> V_12 &= ~ V_120 ;
V_75 -> V_119 = V_109 -> V_119 ;
V_75 -> V_121 = V_109 -> V_121 ;
F_66 ( & V_75 -> V_122 ) ;
F_61 ( V_75 ) ;
F_71 ( & V_75 -> V_122 ) ;
V_112 = F_62 ( V_55 -> V_123 , 1 ) ;
if ( V_110 ) {
F_83 ( V_55 -> V_2 , & V_75 -> V_76 ) ;
F_84 ( & V_75 -> V_124 , & V_55 -> V_125 ) ;
V_55 -> V_126 ++ ;
if ( V_112 -> V_127 )
V_112 -> V_127 ( V_55 , V_75 ) ;
} else {
if ( V_112 -> V_128 )
V_112 -> V_128 ( V_55 , V_75 ) ;
}
}
static int
F_85 ( struct V_54 * V_55 , struct V_108 * V_109 ,
struct V_74 * * V_129 )
{
struct V_74 * V_75 ;
unsigned int V_130 ;
F_86 ( 2 ) ;
#ifdef F_24
if ( V_55 -> V_40 == V_48 ) {
V_130 = F_87 ( & V_109 -> V_4 . V_131 ) ;
if ( ( ! ( V_130 & V_132 ) ||
V_130 & V_133 ) &&
! F_2 ( V_55 -> V_2 , & V_109 -> V_4 . V_131 ) )
return - V_134 ;
} else
#endif
{
V_130 = F_88 ( V_55 -> V_2 , V_109 -> V_4 . V_46 ) ;
if ( V_130 != V_135 && V_130 != V_136 )
return - V_134 ;
}
V_75 = F_89 ( sizeof( struct V_74 ) , V_137 ) ;
if ( V_75 == NULL )
return - V_138 ;
V_75 -> V_76 . V_77 = F_90 ( struct V_139 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_140;
V_75 -> V_40 = V_55 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_84 = V_55 -> V_53 ;
F_91 ( V_55 -> V_40 , & V_75 -> V_4 , & V_109 -> V_4 ) ;
V_75 -> V_43 = V_109 -> V_43 ;
F_9 ( & V_75 -> V_141 , 0 ) ;
F_9 ( & V_75 -> V_142 , 0 ) ;
F_9 ( & V_75 -> V_143 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_92 ( & V_75 -> V_81 ) ;
F_93 ( & V_75 -> V_122 ) ;
F_93 ( & V_75 -> V_76 . V_102 ) ;
F_82 ( V_55 , V_75 , V_109 , 1 ) ;
* V_129 = V_75 ;
F_94 ( 2 ) ;
return 0 ;
V_140:
F_48 ( V_75 ) ;
return - V_138 ;
}
static int
F_95 ( struct V_54 * V_55 , struct V_108 * V_109 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_83 = V_109 -> V_43 ;
int V_144 ;
F_86 ( 2 ) ;
if ( V_109 -> V_114 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_145 ;
}
if ( V_109 -> V_121 > V_109 -> V_119 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_145 ;
}
F_91 ( V_55 -> V_40 , & V_7 , & V_109 -> V_4 ) ;
F_55 () ;
V_75 = F_57 ( V_55 , & V_7 , V_83 ) ;
F_56 () ;
if ( V_75 != NULL ) {
F_96 ( 1 , L_11 , V_58 ) ;
return - V_146 ;
}
V_75 = F_65 ( V_55 , & V_7 , V_83 ) ;
if ( V_75 != NULL ) {
F_42 ( 3 , L_12
L_13 ,
F_44 ( V_55 -> V_40 , & V_7 ) , F_23 ( V_83 ) ,
F_15 ( & V_75 -> V_64 ) ,
V_75 -> V_84 ,
F_44 ( V_55 -> V_40 , & V_75 -> V_65 ) ,
F_23 ( V_75 -> V_66 ) ) ;
F_82 ( V_55 , V_75 , V_109 , 1 ) ;
V_144 = 0 ;
} else {
V_144 = F_85 ( V_55 , V_109 , & V_75 ) ;
}
F_94 ( 2 ) ;
return V_144 ;
}
static int
F_97 ( struct V_54 * V_55 , struct V_108 * V_109 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_83 = V_109 -> V_43 ;
F_86 ( 2 ) ;
if ( V_109 -> V_114 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_145 ;
}
if ( V_109 -> V_121 > V_109 -> V_119 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_145 ;
}
F_91 ( V_55 -> V_40 , & V_7 , & V_109 -> V_4 ) ;
F_55 () ;
V_75 = F_57 ( V_55 , & V_7 , V_83 ) ;
F_56 () ;
if ( V_75 == NULL ) {
F_96 ( 1 , L_14 , V_58 ) ;
return - V_147 ;
}
F_82 ( V_55 , V_75 , V_109 , 0 ) ;
F_94 ( 2 ) ;
return 0 ;
}
static void F_98 ( struct V_87 * V_88 )
{
struct V_74 * V_75 = F_14 ( V_88 , struct V_74 ,
V_87 ) ;
F_99 ( V_94 , & V_75 -> V_95 ) ;
}
static void F_100 ( struct V_2 * V_2 , struct V_74 * V_75 ,
bool V_148 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_101 ( V_2 , & V_75 -> V_76 ) ;
F_53 ( V_75 ) ;
if ( ! V_148 ) {
F_102 ( V_94 , & V_75 -> V_95 ) ;
F_64 ( & V_75 -> V_87 , F_98 ) ;
}
F_66 ( & V_15 -> V_93 ) ;
F_42 ( 3 , L_15 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_103 ( & V_15 -> V_149 ) && ! V_148 )
F_104 ( & V_15 -> V_98 ,
V_150 + V_151 ) ;
F_105 ( & V_75 -> V_96 , & V_15 -> V_149 ) ;
F_71 ( & V_15 -> V_93 ) ;
F_106 ( V_75 ) ;
}
static void F_107 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_152 )
{
V_75 -> V_12 &= ~ V_118 ;
F_108 ( & V_75 -> V_124 ) ;
V_55 -> V_126 -- ;
if ( V_152 ) {
struct V_111 * V_112 ;
V_112 = F_62 ( V_55 -> V_123 , 1 ) ;
if ( V_112 -> V_153 )
V_112 -> V_153 ( V_55 , V_75 ) ;
}
}
static int
F_109 ( struct V_54 * V_55 , struct V_108 * V_109 )
{
struct V_74 * V_75 ;
T_1 V_83 = V_109 -> V_43 ;
F_86 ( 2 ) ;
F_55 () ;
V_75 = F_57 ( V_55 , & V_109 -> V_4 , V_83 ) ;
F_56 () ;
if ( V_75 == NULL ) {
F_96 ( 1 , L_16 , V_58 ) ;
return - V_147 ;
}
F_107 ( V_55 , V_75 , 1 ) ;
F_100 ( V_55 -> V_2 , V_75 , false ) ;
F_94 ( 2 ) ;
return 0 ;
}
static void F_110 ( unsigned long V_154 )
{
struct V_2 * V_2 = (struct V_2 * ) V_154 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_74 * V_75 , * V_155 ;
F_8 ( & V_15 -> V_93 ) ;
F_75 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_68 ( V_94 , & V_75 -> V_95 ) )
continue;
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
F_42 ( 3 , L_17 ,
V_75 -> V_84 ,
F_44 ( V_75 -> V_55 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_69 ( & V_75 -> V_96 ) ;
F_72 ( V_75 ) ;
}
if ( ! F_103 ( & V_15 -> V_149 ) )
F_104 ( & V_15 -> V_98 ,
V_150 + V_151 ) ;
F_10 ( & V_15 -> V_93 ) ;
}
static int
F_111 ( struct V_2 * V_2 , struct V_156 * V_157 ,
struct V_54 * * V_158 )
{
int V_144 = 0 ;
struct V_111 * V_112 = NULL ;
struct V_159 * V_160 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_18 () ;
V_112 = F_112 ( V_157 -> V_161 ) ;
if ( V_112 == NULL ) {
F_113 ( L_18 , V_157 -> V_161 ) ;
V_144 = - V_147 ;
goto V_162;
}
if ( V_157 -> V_163 && * V_157 -> V_163 ) {
V_160 = F_114 ( V_157 -> V_163 ) ;
if ( V_160 == NULL ) {
F_113 ( L_19
L_20 , V_157 -> V_163 ) ;
V_144 = - V_147 ;
goto V_162;
}
}
#ifdef F_24
if ( V_157 -> V_40 == V_48 ) {
T_3 V_164 = ( V_165 T_3 ) V_157 -> V_166 ;
if ( V_164 < 1 || V_164 > 128 ) {
V_144 = - V_134 ;
goto V_162;
}
}
#endif
V_55 = F_89 ( sizeof( struct V_54 ) , V_137 ) ;
if ( V_55 == NULL ) {
F_96 ( 1 , L_21 , V_58 ) ;
V_144 = - V_138 ;
goto V_162;
}
V_55 -> V_76 . V_77 = F_90 ( struct V_139 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_144 = - V_138 ;
goto V_162;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_157 -> V_40 ;
V_55 -> V_59 = V_157 -> V_59 ;
F_91 ( V_55 -> V_40 , & V_55 -> V_4 , & V_157 -> V_4 ) ;
V_55 -> V_43 = V_157 -> V_43 ;
V_55 -> V_53 = V_157 -> V_53 ;
V_55 -> V_12 = V_157 -> V_12 ;
V_55 -> V_167 = V_157 -> V_167 * V_168 ;
V_55 -> V_166 = V_157 -> V_166 ;
V_55 -> V_2 = V_2 ;
F_115 ( & V_55 -> V_125 ) ;
F_93 ( & V_55 -> V_169 ) ;
F_93 ( & V_55 -> V_76 . V_102 ) ;
V_144 = F_116 ( V_55 , V_112 ) ;
if ( V_144 )
goto V_162;
V_112 = NULL ;
F_63 ( V_55 -> V_160 , V_160 ) ;
V_160 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_83 ( V_2 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_170 )
V_15 -> V_171 ++ ;
F_27 ( V_55 ) ;
* V_158 = V_55 ;
V_15 -> V_172 = 1 ;
return 0 ;
V_162:
if ( V_55 != NULL ) {
F_117 ( V_55 , V_112 ) ;
F_46 ( V_55 ) ;
}
F_118 ( V_112 ) ;
F_119 ( V_160 ) ;
F_20 () ;
return V_144 ;
}
static int
F_120 ( struct V_54 * V_55 , struct V_156 * V_157 )
{
struct V_111 * V_112 , * V_173 ;
struct V_159 * V_160 = NULL , * V_174 = NULL ;
int V_144 = 0 ;
V_112 = F_112 ( V_157 -> V_161 ) ;
if ( V_112 == NULL ) {
F_113 ( L_18 , V_157 -> V_161 ) ;
return - V_147 ;
}
V_173 = V_112 ;
if ( V_157 -> V_163 && * V_157 -> V_163 ) {
V_160 = F_114 ( V_157 -> V_163 ) ;
if ( V_160 == NULL ) {
F_113 ( L_19
L_20 , V_157 -> V_163 ) ;
V_144 = - V_147 ;
goto V_67;
}
V_174 = V_160 ;
}
#ifdef F_24
if ( V_157 -> V_40 == V_48 ) {
T_3 V_164 = ( V_165 T_3 ) V_157 -> V_166 ;
if ( V_164 < 1 || V_164 > 128 ) {
V_144 = - V_134 ;
goto V_67;
}
}
#endif
V_173 = F_62 ( V_55 -> V_123 , 1 ) ;
if ( V_112 != V_173 ) {
V_144 = F_116 ( V_55 , V_112 ) ;
if ( V_144 ) {
V_173 = V_112 ;
goto V_67;
}
F_117 ( V_55 , V_173 ) ;
}
V_55 -> V_12 = V_157 -> V_12 | V_57 ;
V_55 -> V_167 = V_157 -> V_167 * V_168 ;
V_55 -> V_166 = V_157 -> V_166 ;
V_174 = F_62 ( V_55 -> V_160 , 1 ) ;
if ( V_160 != V_174 )
F_121 ( V_55 -> V_160 , V_160 ) ;
V_67:
F_118 ( V_173 ) ;
F_119 ( V_174 ) ;
return V_144 ;
}
static void F_122 ( struct V_87 * V_88 )
{
struct V_54 * V_55 ;
V_55 = F_14 ( V_88 , struct V_54 , V_87 ) ;
F_46 ( V_55 ) ;
}
static void F_123 ( struct V_54 * V_55 , bool V_148 )
{
struct V_74 * V_75 , * V_97 ;
struct V_111 * V_173 ;
struct V_159 * V_174 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_113 ( L_22 , V_58 ) ;
if ( V_55 -> V_40 == V_170 )
V_15 -> V_171 -- ;
F_101 ( V_55 -> V_2 , & V_55 -> V_76 ) ;
V_173 = F_62 ( V_55 -> V_123 , 1 ) ;
F_117 ( V_55 , V_173 ) ;
F_118 ( V_173 ) ;
V_174 = F_62 ( V_55 -> V_160 , 1 ) ;
F_119 ( V_174 ) ;
F_75 (dest, nxt, &svc->destinations, n_list) {
F_107 ( V_55 , V_75 , 0 ) ;
F_100 ( V_55 -> V_2 , V_75 , V_148 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
if ( F_50 ( & V_55 -> V_64 ) ) {
F_42 ( 3 , L_6 ,
V_55 -> V_53 ,
F_44 ( V_55 -> V_40 , & V_55 -> V_4 ) ,
F_23 ( V_55 -> V_43 ) ) ;
F_64 ( & V_55 -> V_87 , F_122 ) ;
}
F_20 () ;
}
static void F_124 ( struct V_54 * V_55 , bool V_148 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_123 ( V_55 , V_148 ) ;
}
static int F_125 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_146 ;
F_124 ( V_55 , false ) ;
return 0 ;
}
static int F_126 ( struct V_2 * V_2 , bool V_148 )
{
int V_175 ;
struct V_54 * V_55 ;
struct V_176 * V_177 ;
for( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_127 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_124 ( V_55 , V_148 ) ;
}
}
for( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_127 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_124 ( V_55 , V_148 ) ;
}
}
return 0 ;
}
void F_128 ( struct V_2 * V_2 )
{
F_86 ( 2 ) ;
F_129 ( & V_179 ) ;
F_126 ( V_2 , true ) ;
F_130 ( & V_179 ) ;
F_94 ( 2 ) ;
}
static inline void
F_131 ( struct V_74 * V_75 , struct V_180 * V_11 )
{
struct V_89 * V_90 ;
F_66 ( & V_75 -> V_122 ) ;
V_90 = F_62 ( V_75 -> V_90 , 1 ) ;
if ( V_90 && V_90 -> V_91 -> V_11 == V_11 ) {
F_42 ( 3 , L_23 ,
V_11 -> V_181 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_61 ( V_75 ) ;
}
F_71 ( & V_75 -> V_122 ) ;
}
static int F_132 ( struct V_182 * V_183 , unsigned long V_184 ,
void * V_185 )
{
struct V_180 * V_11 = V_185 ;
struct V_2 * V_2 = F_133 ( V_11 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_175 ;
if ( V_184 != V_186 || ! V_15 )
return V_187 ;
F_96 ( 3 , L_24 , V_58 , V_11 -> V_181 ) ;
F_86 ( 2 ) ;
F_129 ( & V_179 ) ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_134 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_67 (dest, &svc->destinations,
n_list) {
F_131 ( V_75 , V_11 ) ;
}
}
}
F_134 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_67 (dest, &svc->destinations,
n_list) {
F_131 ( V_75 , V_11 ) ;
}
}
}
}
F_66 ( & V_15 -> V_93 ) ;
F_67 (dest, &ipvs->dest_trash, t_list) {
F_131 ( V_75 , V_11 ) ;
}
F_71 ( & V_15 -> V_93 ) ;
F_130 ( & V_179 ) ;
F_94 ( 2 ) ;
return V_187 ;
}
static int F_135 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_67 (dest, &svc->destinations, n_list) {
F_79 ( & V_75 -> V_76 ) ;
}
F_79 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_136 ( struct V_2 * V_2 )
{
int V_175 ;
struct V_54 * V_55 ;
for( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_134 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_135 ( V_55 ) ;
}
}
for( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_134 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_135 ( V_55 ) ;
}
}
F_79 ( & F_41 ( V_2 ) -> V_188 ) ;
return 0 ;
}
static int
F_137 ( T_6 * V_189 , int V_190 ,
void T_7 * V_191 , V_50 * V_192 , T_8 * V_193 )
{
struct V_2 * V_2 = V_194 -> V_195 -> V_196 ;
int * V_197 = V_189 -> V_154 ;
int V_198 = * V_197 ;
int V_199 ;
V_199 = F_138 ( V_189 , V_190 , V_191 , V_192 , V_193 ) ;
if ( V_190 && ( * V_197 != V_198 ) ) {
if ( ( * V_197 < 0 ) || ( * V_197 > 3 ) ) {
* V_197 = V_198 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_199 ;
}
static int
F_139 ( T_6 * V_189 , int V_190 ,
void T_7 * V_191 , V_50 * V_192 , T_8 * V_193 )
{
int * V_197 = V_189 -> V_154 ;
int V_198 [ 2 ] ;
int V_199 ;
memcpy ( V_198 , V_197 , sizeof( V_198 ) ) ;
V_199 = F_138 ( V_189 , V_190 , V_191 , V_192 , V_193 ) ;
if ( V_190 && ( V_197 [ 0 ] < 0 || V_197 [ 1 ] < 0 ||
( V_197 [ 0 ] >= V_197 [ 1 ] && V_197 [ 1 ] ) ) ) {
memcpy ( V_197 , V_198 , sizeof( V_198 ) ) ;
}
return V_199 ;
}
static int
F_140 ( T_6 * V_189 , int V_190 ,
void T_7 * V_191 , V_50 * V_192 , T_8 * V_193 )
{
int * V_197 = V_189 -> V_154 ;
int V_198 = * V_197 ;
int V_199 ;
V_199 = F_138 ( V_189 , V_190 , V_191 , V_192 , V_193 ) ;
if ( V_190 && ( * V_197 != V_198 ) ) {
if ( ( * V_197 < 0 ) || ( * V_197 > 1 ) ) {
* V_197 = V_198 ;
}
}
return V_199 ;
}
static int
F_141 ( T_6 * V_189 , int V_190 ,
void T_7 * V_191 , V_50 * V_192 , T_8 * V_193 )
{
int * V_197 = V_189 -> V_154 ;
int V_198 = * V_197 ;
int V_199 ;
V_199 = F_138 ( V_189 , V_190 , V_191 , V_192 , V_193 ) ;
if ( V_190 && ( * V_197 != V_198 ) ) {
if ( * V_197 < 1 || ! F_142 ( * V_197 ) ) {
* V_197 = V_198 ;
}
}
return V_199 ;
}
static inline const char * F_143 ( unsigned int V_12 )
{
switch ( V_12 & V_85 ) {
case V_200 :
return L_25 ;
case V_201 :
return L_26 ;
case V_202 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_144 ( struct V_203 * V_204 , T_8 V_205 )
{
struct V_2 * V_2 = F_145 ( V_204 ) ;
struct V_206 * V_207 = V_204 -> V_208 ;
int V_175 ;
struct V_54 * V_55 ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_205 -- == 0 ) {
V_207 -> V_189 = V_61 ;
V_207 -> V_209 = V_175 ;
return V_55 ;
}
}
}
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_205 -- == 0 ) {
V_207 -> V_189 = V_63 ;
V_207 -> V_209 = V_175 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_146 ( struct V_203 * V_204 , T_8 * V_205 )
__acquires( T_9 )
{
F_55 () ;
return * V_205 ? F_144 ( V_204 , * V_205 - 1 ) : V_210 ;
}
static void * F_147 ( struct V_203 * V_204 , void * V_211 , T_8 * V_205 )
{
struct V_176 * V_212 ;
struct V_206 * V_207 ;
struct V_54 * V_55 ;
++ * V_205 ;
if ( V_211 == V_210 )
return F_144 ( V_204 , 0 ) ;
V_55 = V_211 ;
V_207 = V_204 -> V_208 ;
if ( V_207 -> V_189 == V_61 ) {
V_212 = F_148 ( F_149 ( & V_55 -> V_60 ) ) ;
if ( V_212 )
return F_150 ( V_212 , struct V_54 , V_60 ) ;
while ( ++ V_207 -> V_209 < V_178 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_207 -> V_189 = V_63 ;
V_207 -> V_209 = - 1 ;
goto V_213;
}
V_212 = F_148 ( F_149 ( & V_55 -> V_62 ) ) ;
if ( V_212 )
return F_150 ( V_212 , struct V_54 , V_62 ) ;
V_213:
while ( ++ V_207 -> V_209 < V_178 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_151 ( struct V_203 * V_204 , void * V_211 )
__releases( T_9 )
{
F_56 () ;
}
static int F_152 ( struct V_203 * V_204 , void * V_211 )
{
if ( V_211 == V_210 ) {
F_153 ( V_204 ,
L_29 ,
F_154 ( V_214 ) , V_215 ) ;
F_155 ( V_204 ,
L_30 ) ;
F_155 ( V_204 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_211 ;
const struct V_206 * V_207 = V_204 -> V_208 ;
const struct V_74 * V_75 ;
struct V_111 * V_112 = F_148 ( V_55 -> V_123 ) ;
if ( V_207 -> V_189 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_153 ( V_204 , L_32 ,
F_43 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_131 ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_181 ) ;
else
#endif
F_153 ( V_204 , L_33 ,
F_43 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_181 ,
( V_55 -> V_12 & V_216 ) ? L_34 : L_35 ) ;
} else {
F_153 ( V_204 , L_36 ,
V_55 -> V_53 , V_112 -> V_181 ,
( V_55 -> V_12 & V_216 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_217 )
F_153 ( V_204 , L_37 ,
V_55 -> V_167 ,
F_25 ( V_55 -> V_166 ) ) ;
else
F_156 ( V_204 , '\n' ) ;
F_58 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_153 ( V_204 ,
L_38
L_39 ,
& V_75 -> V_4 . V_131 ,
F_23 ( V_75 -> V_43 ) ,
F_143 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_141 ) ,
F_15 ( & V_75 -> V_142 ) ) ;
else
#endif
F_153 ( V_204 ,
L_40
L_41 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_143 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_141 ) ,
F_15 ( & V_75 -> V_142 ) ) ;
}
}
return 0 ;
}
static int F_157 ( struct V_218 * V_218 , struct V_219 * V_219 )
{
return F_158 ( V_218 , V_219 , & V_220 ,
sizeof( struct V_206 ) ) ;
}
static int F_159 ( struct V_203 * V_204 , void * V_211 )
{
struct V_2 * V_2 = F_160 ( V_204 ) ;
struct V_99 V_221 ;
F_155 ( V_204 ,
L_42 ) ;
F_153 ( V_204 ,
L_43 ) ;
F_76 ( & V_221 , & F_41 ( V_2 ) -> V_188 ) ;
F_153 ( V_204 , L_44 , V_221 . V_103 ,
V_221 . V_104 , V_221 . V_105 ,
( unsigned long long ) V_221 . V_106 ,
( unsigned long long ) V_221 . V_107 ) ;
F_155 ( V_204 ,
L_45 ) ;
F_153 ( V_204 , L_46 ,
V_221 . V_222 , V_221 . V_223 , V_221 . V_224 ,
V_221 . V_225 , V_221 . V_226 ) ;
return 0 ;
}
static int F_161 ( struct V_218 * V_218 , struct V_219 * V_219 )
{
return F_162 ( V_218 , V_219 , F_159 ) ;
}
static int F_163 ( struct V_203 * V_204 , void * V_211 )
{
struct V_2 * V_2 = F_160 ( V_204 ) ;
struct V_100 * V_188 = & F_41 ( V_2 ) -> V_188 ;
struct V_139 T_10 * V_77 = V_188 -> V_77 ;
struct V_99 V_227 ;
int V_17 ;
F_155 ( V_204 ,
L_47 ) ;
F_153 ( V_204 ,
L_48 ) ;
F_164 (i) {
struct V_139 * V_157 = F_165 ( V_77 , V_17 ) ;
unsigned int V_228 ;
T_11 V_106 , V_107 ;
do {
V_228 = F_166 ( & V_157 -> V_229 ) ;
V_106 = V_157 -> V_230 . V_106 ;
V_107 = V_157 -> V_230 . V_107 ;
} while ( F_167 ( & V_157 -> V_229 , V_228 ) );
F_153 ( V_204 , L_49 ,
V_17 , V_157 -> V_230 . V_103 , V_157 -> V_230 . V_104 ,
V_157 -> V_230 . V_105 , ( T_11 ) V_106 ,
( T_11 ) V_107 ) ;
}
F_66 ( & V_188 -> V_102 ) ;
F_153 ( V_204 , L_50 ,
V_188 -> V_230 . V_103 , V_188 -> V_230 . V_104 ,
V_188 -> V_230 . V_105 ,
( unsigned long long ) V_188 -> V_230 . V_106 ,
( unsigned long long ) V_188 -> V_230 . V_107 ) ;
F_78 ( & V_227 , V_188 ) ;
F_71 ( & V_188 -> V_102 ) ;
F_155 ( V_204 ,
L_51 ) ;
F_153 ( V_204 , L_52 ,
V_227 . V_222 ,
V_227 . V_223 ,
V_227 . V_224 ,
V_227 . V_225 ,
V_227 . V_226 ) ;
return 0 ;
}
static int F_168 ( struct V_218 * V_218 , struct V_219 * V_219 )
{
return F_162 ( V_218 , V_219 , F_163 ) ;
}
static int F_169 ( struct V_2 * V_2 , struct V_231 * V_157 )
{
#if F_170 ( V_232 ) || F_170 ( V_233 )
struct V_234 * V_235 ;
#endif
F_96 ( 2 , L_53 ,
V_157 -> V_236 ,
V_157 -> V_237 ,
V_157 -> V_238 ) ;
#ifdef V_232
if ( V_157 -> V_236 ) {
V_235 = F_171 ( V_2 , V_68 ) ;
V_235 -> V_239 [ V_240 ]
= V_157 -> V_236 * V_168 ;
}
if ( V_157 -> V_237 ) {
V_235 = F_171 ( V_2 , V_68 ) ;
V_235 -> V_239 [ V_241 ]
= V_157 -> V_237 * V_168 ;
}
#endif
#ifdef V_233
if ( V_157 -> V_238 ) {
V_235 = F_171 ( V_2 , V_242 ) ;
V_235 -> V_239 [ V_243 ]
= V_157 -> V_238 * V_168 ;
}
#endif
return 0 ;
}
static void F_172 ( struct V_156 * V_244 ,
struct V_245 * V_246 )
{
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
V_244 -> V_40 = V_170 ;
V_244 -> V_59 = V_246 -> V_59 ;
V_244 -> V_4 . V_46 = V_246 -> V_4 ;
V_244 -> V_43 = V_246 -> V_43 ;
V_244 -> V_53 = V_246 -> V_53 ;
V_244 -> V_161 = V_246 -> V_161 ;
V_244 -> V_12 = V_246 -> V_12 ;
V_244 -> V_167 = V_246 -> V_167 ;
V_244 -> V_166 = V_246 -> V_166 ;
}
static void F_173 ( struct V_108 * V_109 ,
struct V_247 * V_248 )
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_4 . V_46 = V_248 -> V_4 ;
V_109 -> V_43 = V_248 -> V_43 ;
V_109 -> V_113 = V_248 -> V_113 ;
V_109 -> V_114 = V_248 -> V_114 ;
V_109 -> V_119 = V_248 -> V_119 ;
V_109 -> V_121 = V_248 -> V_121 ;
}
static int
F_174 ( struct V_249 * V_250 , int V_251 , void T_7 * V_252 , unsigned int V_253 )
{
struct V_2 * V_2 = F_175 ( V_250 ) ;
int V_144 ;
unsigned char V_254 [ V_255 ] ;
struct V_245 * V_246 ;
struct V_156 V_244 ;
struct V_54 * V_55 ;
struct V_247 * V_248 ;
struct V_108 V_109 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
if ( ! F_176 ( F_175 ( V_250 ) -> V_256 , V_257 ) )
return - V_258 ;
if ( V_251 < V_259 || V_251 > V_260 )
return - V_134 ;
if ( V_253 < 0 || V_253 > V_255 )
return - V_134 ;
if ( V_253 != V_261 [ F_177 ( V_251 ) ] ) {
F_28 ( L_54 ,
V_253 , V_261 [ F_177 ( V_251 ) ] ) ;
return - V_134 ;
}
if ( F_178 ( V_254 , V_252 , V_253 ) != 0 )
return - V_262 ;
F_18 () ;
if ( V_251 == V_263 ||
V_251 == V_264 ) {
struct V_265 * V_266 = (struct V_265 * ) V_254 ;
if ( F_179 ( & V_15 -> V_267 ) ) {
V_144 = - V_268 ;
goto V_269;
}
if ( V_251 == V_263 )
V_144 = F_180 ( V_2 , V_266 -> V_95 , V_266 -> V_270 ,
V_266 -> V_271 ) ;
else
V_144 = F_181 ( V_2 , V_266 -> V_95 ) ;
F_130 ( & V_15 -> V_267 ) ;
goto V_269;
}
if ( F_179 ( & V_179 ) ) {
V_144 = - V_268 ;
goto V_269;
}
if ( V_251 == V_272 ) {
V_144 = F_126 ( V_2 , false ) ;
goto V_273;
} else if ( V_251 == V_274 ) {
V_144 = F_169 ( V_2 , (struct V_231 * ) V_254 ) ;
goto V_273;
}
V_246 = (struct V_245 * ) V_254 ;
V_248 = (struct V_247 * ) ( V_246 + 1 ) ;
F_172 ( & V_244 , V_246 ) ;
F_173 ( & V_109 , V_248 ) ;
if ( V_251 == V_275 ) {
if ( ! V_244 . V_53 && ! V_244 . V_4 . V_46 && ! V_244 . V_43 ) {
V_144 = F_136 ( V_2 ) ;
goto V_273;
}
}
if ( V_244 . V_59 != V_68 && V_244 . V_59 != V_242 &&
V_244 . V_59 != V_276 ) {
F_28 ( L_55 ,
V_244 . V_59 , & V_244 . V_4 . V_46 ,
F_23 ( V_244 . V_43 ) , V_244 . V_161 ) ;
V_144 = - V_262 ;
goto V_273;
}
F_55 () ;
if ( V_244 . V_53 == 0 )
V_55 = F_35 ( V_2 , V_244 . V_40 , V_244 . V_59 ,
& V_244 . V_4 , V_244 . V_43 ) ;
else
V_55 = F_39 ( V_2 , V_244 . V_40 , V_244 . V_53 ) ;
F_56 () ;
if ( V_251 != V_277
&& ( V_55 == NULL || V_55 -> V_59 != V_244 . V_59 ) ) {
V_144 = - V_278 ;
goto V_273;
}
switch ( V_251 ) {
case V_277 :
if ( V_55 != NULL )
V_144 = - V_146 ;
else
V_144 = F_111 ( V_2 , & V_244 , & V_55 ) ;
break;
case V_279 :
V_144 = F_120 ( V_55 , & V_244 ) ;
break;
case V_280 :
V_144 = F_125 ( V_55 ) ;
if ( ! V_144 )
goto V_273;
break;
case V_275 :
V_144 = F_135 ( V_55 ) ;
break;
case V_281 :
V_144 = F_95 ( V_55 , & V_109 ) ;
break;
case V_282 :
V_144 = F_97 ( V_55 , & V_109 ) ;
break;
case V_283 :
V_144 = F_109 ( V_55 , & V_109 ) ;
break;
default:
V_144 = - V_134 ;
}
V_273:
F_130 ( & V_179 ) ;
V_269:
F_20 () ;
return V_144 ;
}
static void
F_182 ( struct V_284 * V_9 , struct V_54 * V_101 )
{
struct V_111 * V_112 ;
V_112 = F_62 ( V_101 -> V_123 , 1 ) ;
V_9 -> V_59 = V_101 -> V_59 ;
V_9 -> V_4 = V_101 -> V_4 . V_46 ;
V_9 -> V_43 = V_101 -> V_43 ;
V_9 -> V_53 = V_101 -> V_53 ;
F_183 ( V_9 -> V_161 , V_112 -> V_181 , sizeof( V_9 -> V_161 ) ) ;
V_9 -> V_12 = V_101 -> V_12 ;
V_9 -> V_167 = V_101 -> V_167 / V_168 ;
V_9 -> V_166 = V_101 -> V_166 ;
V_9 -> V_126 = V_101 -> V_126 ;
F_76 ( & V_9 -> V_76 , & V_101 -> V_76 ) ;
}
static inline int
F_184 ( struct V_2 * V_2 ,
const struct V_285 * V_286 ,
struct V_285 T_7 * V_287 )
{
int V_175 , V_288 = 0 ;
struct V_54 * V_55 ;
struct V_284 V_289 ;
int V_144 = 0 ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_134 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_170 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_288 >= V_286 -> V_171 )
goto V_67;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
F_182 ( & V_289 , V_55 ) ;
if ( F_185 ( & V_287 -> V_290 [ V_288 ] ,
& V_289 , sizeof( V_289 ) ) ) {
V_144 = - V_262 ;
goto V_67;
}
V_288 ++ ;
}
}
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_134 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_170 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_288 >= V_286 -> V_171 )
goto V_67;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
F_182 ( & V_289 , V_55 ) ;
if ( F_185 ( & V_287 -> V_290 [ V_288 ] ,
& V_289 , sizeof( V_289 ) ) ) {
V_144 = - V_262 ;
goto V_67;
}
V_288 ++ ;
}
}
V_67:
return V_144 ;
}
static inline int
F_186 ( struct V_2 * V_2 , const struct V_291 * V_286 ,
struct V_291 T_7 * V_287 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_286 -> V_4 } ;
int V_144 = 0 ;
F_55 () ;
if ( V_286 -> V_53 )
V_55 = F_39 ( V_2 , V_170 , V_286 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_170 , V_286 -> V_59 , & V_4 ,
V_286 -> V_43 ) ;
F_56 () ;
if ( V_55 ) {
int V_288 = 0 ;
struct V_74 * V_75 ;
struct V_292 V_289 ;
memset ( & V_289 , 0 , sizeof( V_289 ) ) ;
F_67 (dest, &svc->destinations, n_list) {
if ( V_288 >= V_286 -> V_126 )
break;
V_289 . V_4 = V_75 -> V_4 . V_46 ;
V_289 . V_43 = V_75 -> V_43 ;
V_289 . V_113 = F_15 ( & V_75 -> V_113 ) ;
V_289 . V_114 = F_15 ( & V_75 -> V_114 ) ;
V_289 . V_119 = V_75 -> V_119 ;
V_289 . V_121 = V_75 -> V_121 ;
V_289 . V_141 = F_15 ( & V_75 -> V_141 ) ;
V_289 . V_142 = F_15 ( & V_75 -> V_142 ) ;
V_289 . V_143 = F_15 ( & V_75 -> V_143 ) ;
F_76 ( & V_289 . V_76 , & V_75 -> V_76 ) ;
if ( F_185 ( & V_287 -> V_290 [ V_288 ] ,
& V_289 , sizeof( V_289 ) ) ) {
V_144 = - V_262 ;
break;
}
V_288 ++ ;
}
} else
V_144 = - V_278 ;
return V_144 ;
}
static inline void
F_187 ( struct V_2 * V_2 , struct V_231 * V_157 )
{
#if F_170 ( V_232 ) || F_170 ( V_233 )
struct V_234 * V_235 ;
#endif
memset ( V_157 , 0 , sizeof ( * V_157 ) ) ;
#ifdef V_232
V_235 = F_171 ( V_2 , V_68 ) ;
V_157 -> V_236 = V_235 -> V_239 [ V_240 ] / V_168 ;
V_157 -> V_237 = V_235 -> V_239 [ V_241 ] / V_168 ;
#endif
#ifdef V_233
V_235 = F_171 ( V_2 , V_242 ) ;
V_157 -> V_238 =
V_235 -> V_239 [ V_243 ] / V_168 ;
#endif
}
static int
F_188 ( struct V_249 * V_250 , int V_251 , void T_7 * V_252 , int * V_253 )
{
unsigned char V_254 [ 128 ] ;
int V_144 = 0 ;
unsigned int V_293 ;
struct V_2 * V_2 = F_175 ( V_250 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_189 ( ! V_2 ) ;
if ( ! F_176 ( F_175 ( V_250 ) -> V_256 , V_257 ) )
return - V_258 ;
if ( V_251 < V_259 || V_251 > V_294 )
return - V_134 ;
if ( * V_253 < V_295 [ F_190 ( V_251 ) ] ) {
F_28 ( L_56 ,
* V_253 , V_295 [ F_190 ( V_251 ) ] ) ;
return - V_134 ;
}
V_293 = V_295 [ F_190 ( V_251 ) ] ;
if ( V_293 > 128 )
return - V_134 ;
if ( F_178 ( V_254 , V_252 , V_293 ) != 0 )
return - V_262 ;
if ( V_251 == V_296 ) {
struct V_265 V_297 [ 2 ] ;
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
if ( F_179 ( & V_15 -> V_267 ) )
return - V_268 ;
if ( V_15 -> V_298 & V_299 ) {
V_297 [ 0 ] . V_95 = V_299 ;
F_183 ( V_297 [ 0 ] . V_270 , V_15 -> V_300 ,
sizeof( V_297 [ 0 ] . V_270 ) ) ;
V_297 [ 0 ] . V_271 = V_15 -> V_301 ;
}
if ( V_15 -> V_298 & V_302 ) {
V_297 [ 1 ] . V_95 = V_302 ;
F_183 ( V_297 [ 1 ] . V_270 , V_15 -> V_303 ,
sizeof( V_297 [ 1 ] . V_270 ) ) ;
V_297 [ 1 ] . V_271 = V_15 -> V_304 ;
}
if ( F_185 ( V_252 , & V_297 , sizeof( V_297 ) ) != 0 )
V_144 = - V_262 ;
F_130 ( & V_15 -> V_267 ) ;
return V_144 ;
}
if ( F_179 ( & V_179 ) )
return - V_268 ;
switch ( V_251 ) {
case V_305 :
{
char V_306 [ 64 ] ;
sprintf ( V_306 , L_57 ,
F_154 ( V_214 ) , V_215 ) ;
if ( F_185 ( V_252 , V_306 , strlen ( V_306 ) + 1 ) != 0 ) {
V_144 = - V_262 ;
goto V_67;
}
* V_253 = strlen ( V_306 ) + 1 ;
}
break;
case V_307 :
{
struct V_308 V_309 ;
V_309 . V_310 = V_214 ;
V_309 . V_311 = V_215 ;
V_309 . V_171 = V_15 -> V_171 ;
if ( F_185 ( V_252 , & V_309 , sizeof( V_309 ) ) != 0 )
V_144 = - V_262 ;
}
break;
case V_312 :
{
struct V_285 * V_286 ;
int V_311 ;
V_286 = (struct V_285 * ) V_254 ;
V_311 = sizeof( * V_286 ) +
sizeof( struct V_284 ) * V_286 -> V_171 ;
if ( * V_253 != V_311 ) {
F_28 ( L_58 , * V_253 , V_311 ) ;
V_144 = - V_134 ;
goto V_67;
}
V_144 = F_184 ( V_2 , V_286 , V_252 ) ;
}
break;
case V_313 :
{
struct V_284 * V_289 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_289 = (struct V_284 * ) V_254 ;
V_4 . V_46 = V_289 -> V_4 ;
F_55 () ;
if ( V_289 -> V_53 )
V_55 = F_39 ( V_2 , V_170 , V_289 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_170 ,
V_289 -> V_59 , & V_4 ,
V_289 -> V_43 ) ;
F_56 () ;
if ( V_55 ) {
F_182 ( V_289 , V_55 ) ;
if ( F_185 ( V_252 , V_289 , sizeof( * V_289 ) ) != 0 )
V_144 = - V_262 ;
} else
V_144 = - V_278 ;
}
break;
case V_314 :
{
struct V_291 * V_286 ;
int V_311 ;
V_286 = (struct V_291 * ) V_254 ;
V_311 = sizeof( * V_286 ) +
sizeof( struct V_292 ) * V_286 -> V_126 ;
if ( * V_253 != V_311 ) {
F_28 ( L_58 , * V_253 , V_311 ) ;
V_144 = - V_134 ;
goto V_67;
}
V_144 = F_186 ( V_2 , V_286 , V_252 ) ;
}
break;
case V_315 :
{
struct V_231 V_316 ;
F_187 ( V_2 , & V_316 ) ;
if ( F_185 ( V_252 , & V_316 , sizeof( V_316 ) ) != 0 )
V_144 = - V_262 ;
}
break;
default:
V_144 = - V_134 ;
}
V_67:
F_130 ( & V_179 ) ;
return V_144 ;
}
static int F_191 ( struct V_317 * V_318 , int V_319 ,
struct V_100 * V_76 )
{
struct V_99 V_230 ;
struct V_320 * V_321 = F_192 ( V_318 , V_319 ) ;
if ( ! V_321 )
return - V_322 ;
F_76 ( & V_230 , V_76 ) ;
if ( F_193 ( V_318 , V_323 , V_230 . V_103 ) ||
F_193 ( V_318 , V_324 , V_230 . V_104 ) ||
F_193 ( V_318 , V_325 , V_230 . V_105 ) ||
F_194 ( V_318 , V_326 , V_230 . V_106 ) ||
F_194 ( V_318 , V_327 , V_230 . V_107 ) ||
F_193 ( V_318 , V_328 , V_230 . V_222 ) ||
F_193 ( V_318 , V_329 , V_230 . V_223 ) ||
F_193 ( V_318 , V_330 , V_230 . V_224 ) ||
F_193 ( V_318 , V_331 , V_230 . V_225 ) ||
F_193 ( V_318 , V_332 , V_230 . V_226 ) )
goto V_333;
F_195 ( V_318 , V_321 ) ;
return 0 ;
V_333:
F_196 ( V_318 , V_321 ) ;
return - V_322 ;
}
static int F_197 ( struct V_317 * V_318 ,
struct V_54 * V_55 )
{
struct V_111 * V_112 ;
struct V_159 * V_160 ;
struct V_320 * V_334 ;
struct V_335 V_12 = { . V_12 = V_55 -> V_12 ,
. V_336 = ~ 0 } ;
V_334 = F_192 ( V_318 , V_337 ) ;
if ( ! V_334 )
return - V_322 ;
if ( F_198 ( V_318 , V_338 , V_55 -> V_40 ) )
goto V_333;
if ( V_55 -> V_53 ) {
if ( F_193 ( V_318 , V_339 , V_55 -> V_53 ) )
goto V_333;
} else {
if ( F_198 ( V_318 , V_340 , V_55 -> V_59 ) ||
F_199 ( V_318 , V_341 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_200 ( V_318 , V_342 , V_55 -> V_43 ) )
goto V_333;
}
V_112 = F_62 ( V_55 -> V_123 , 1 ) ;
V_160 = F_62 ( V_55 -> V_160 , 1 ) ;
if ( F_201 ( V_318 , V_343 , V_112 -> V_181 ) ||
( V_160 && F_201 ( V_318 , V_344 , V_160 -> V_181 ) ) ||
F_199 ( V_318 , V_345 , sizeof( V_12 ) , & V_12 ) ||
F_193 ( V_318 , V_346 , V_55 -> V_167 / V_168 ) ||
F_202 ( V_318 , V_347 , V_55 -> V_166 ) )
goto V_333;
if ( F_191 ( V_318 , V_348 , & V_55 -> V_76 ) )
goto V_333;
F_195 ( V_318 , V_334 ) ;
return 0 ;
V_333:
F_196 ( V_318 , V_334 ) ;
return - V_322 ;
}
static int F_203 ( struct V_317 * V_318 ,
struct V_54 * V_55 ,
struct V_349 * V_350 )
{
void * V_351 ;
V_351 = F_204 ( V_318 , F_205 ( V_350 -> V_318 ) . V_352 , V_350 -> V_353 -> V_354 ,
& V_355 , V_356 ,
V_357 ) ;
if ( ! V_351 )
return - V_322 ;
if ( F_197 ( V_318 , V_55 ) < 0 )
goto V_333;
return F_206 ( V_318 , V_351 ) ;
V_333:
F_207 ( V_318 , V_351 ) ;
return - V_322 ;
}
static int F_208 ( struct V_317 * V_318 ,
struct V_349 * V_350 )
{
int V_175 = 0 , V_17 ;
int V_228 = V_350 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_209 ( V_318 ) ;
F_129 ( & V_179 ) ;
for ( V_17 = 0 ; V_17 < V_178 ; V_17 ++ ) {
F_134 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_175 <= V_228 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_203 ( V_318 , V_55 , V_350 ) < 0 ) {
V_175 -- ;
goto V_333;
}
}
}
for ( V_17 = 0 ; V_17 < V_178 ; V_17 ++ ) {
F_134 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_175 <= V_228 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_203 ( V_318 , V_55 , V_350 ) < 0 ) {
V_175 -- ;
goto V_333;
}
}
}
V_333:
F_130 ( & V_179 ) ;
V_350 -> args [ 0 ] = V_175 ;
return V_318 -> V_253 ;
}
static int F_210 ( struct V_2 * V_2 ,
struct V_156 * V_244 ,
struct V_320 * V_358 , int V_359 ,
struct V_54 * * V_360 )
{
struct V_320 * V_361 [ V_362 + 1 ] ;
struct V_320 * V_363 , * V_364 , * V_365 , * V_366 , * V_367 ;
struct V_54 * V_55 ;
if ( V_358 == NULL ||
F_211 ( V_361 , V_362 , V_358 , V_368 ) )
return - V_134 ;
V_363 = V_361 [ V_338 ] ;
V_366 = V_361 [ V_340 ] ;
V_367 = V_361 [ V_341 ] ;
V_364 = V_361 [ V_342 ] ;
V_365 = V_361 [ V_339 ] ;
if ( ! ( V_363 && ( V_365 || ( V_364 && V_366 && V_367 ) ) ) )
return - V_134 ;
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
V_244 -> V_40 = F_212 ( V_363 ) ;
#ifdef F_24
if ( V_244 -> V_40 != V_170 && V_244 -> V_40 != V_48 )
#else
if ( V_244 -> V_40 != V_170 )
#endif
return - V_369 ;
if ( V_365 ) {
V_244 -> V_59 = V_68 ;
V_244 -> V_53 = F_213 ( V_365 ) ;
} else {
V_244 -> V_59 = F_212 ( V_366 ) ;
F_214 ( & V_244 -> V_4 , V_367 , sizeof( V_244 -> V_4 ) ) ;
V_244 -> V_43 = F_215 ( V_364 ) ;
V_244 -> V_53 = 0 ;
}
F_55 () ;
if ( V_244 -> V_53 )
V_55 = F_39 ( V_2 , V_244 -> V_40 , V_244 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_244 -> V_40 , V_244 -> V_59 ,
& V_244 -> V_4 , V_244 -> V_43 ) ;
F_56 () ;
* V_360 = V_55 ;
if ( V_359 ) {
struct V_320 * V_370 , * V_371 , * V_372 , * V_373 ,
* V_374 ;
struct V_335 V_12 ;
V_370 = V_361 [ V_343 ] ;
V_372 = V_361 [ V_344 ] ;
V_371 = V_361 [ V_345 ] ;
V_373 = V_361 [ V_346 ] ;
V_374 = V_361 [ V_347 ] ;
if ( ! ( V_370 && V_371 && V_373 && V_374 ) )
return - V_134 ;
F_214 ( & V_12 , V_371 , sizeof( V_12 ) ) ;
if ( V_55 )
V_244 -> V_12 = V_55 -> V_12 ;
V_244 -> V_12 = ( V_244 -> V_12 & ~ V_12 . V_336 ) |
( V_12 . V_12 & V_12 . V_336 ) ;
V_244 -> V_161 = F_216 ( V_370 ) ;
V_244 -> V_163 = V_372 ? F_216 ( V_372 ) : NULL ;
V_244 -> V_167 = F_213 ( V_373 ) ;
V_244 -> V_166 = F_217 ( V_374 ) ;
}
return 0 ;
}
static struct V_54 * F_218 ( struct V_2 * V_2 ,
struct V_320 * V_358 )
{
struct V_156 V_244 ;
struct V_54 * V_55 ;
int V_144 ;
V_144 = F_210 ( V_2 , & V_244 , V_358 , 0 , & V_55 ) ;
return V_144 ? F_219 ( V_144 ) : V_55 ;
}
static int F_220 ( struct V_317 * V_318 , struct V_74 * V_75 )
{
struct V_320 * V_375 ;
V_375 = F_192 ( V_318 , V_376 ) ;
if ( ! V_375 )
return - V_322 ;
if ( F_199 ( V_318 , V_377 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_200 ( V_318 , V_378 , V_75 -> V_43 ) ||
F_193 ( V_318 , V_379 ,
( F_15 ( & V_75 -> V_113 ) &
V_85 ) ) ||
F_193 ( V_318 , V_380 ,
F_15 ( & V_75 -> V_114 ) ) ||
F_193 ( V_318 , V_381 , V_75 -> V_119 ) ||
F_193 ( V_318 , V_382 , V_75 -> V_121 ) ||
F_193 ( V_318 , V_383 ,
F_15 ( & V_75 -> V_141 ) ) ||
F_193 ( V_318 , V_384 ,
F_15 ( & V_75 -> V_142 ) ) ||
F_193 ( V_318 , V_385 ,
F_15 ( & V_75 -> V_143 ) ) )
goto V_333;
if ( F_191 ( V_318 , V_386 , & V_75 -> V_76 ) )
goto V_333;
F_195 ( V_318 , V_375 ) ;
return 0 ;
V_333:
F_196 ( V_318 , V_375 ) ;
return - V_322 ;
}
static int F_221 ( struct V_317 * V_318 , struct V_74 * V_75 ,
struct V_349 * V_350 )
{
void * V_351 ;
V_351 = F_204 ( V_318 , F_205 ( V_350 -> V_318 ) . V_352 , V_350 -> V_353 -> V_354 ,
& V_355 , V_356 ,
V_387 ) ;
if ( ! V_351 )
return - V_322 ;
if ( F_220 ( V_318 , V_75 ) < 0 )
goto V_333;
return F_206 ( V_318 , V_351 ) ;
V_333:
F_207 ( V_318 , V_351 ) ;
return - V_322 ;
}
static int F_222 ( struct V_317 * V_318 ,
struct V_349 * V_350 )
{
int V_175 = 0 ;
int V_228 = V_350 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_320 * V_361 [ V_388 + 1 ] ;
struct V_2 * V_2 = F_209 ( V_318 ) ;
F_129 ( & V_179 ) ;
if ( F_223 ( V_350 -> V_353 , V_389 , V_361 ,
V_388 , V_390 ) )
goto V_162;
V_55 = F_218 ( V_2 , V_361 [ V_337 ] ) ;
if ( F_224 ( V_55 ) || V_55 == NULL )
goto V_162;
F_67 (dest, &svc->destinations, n_list) {
if ( ++ V_175 <= V_228 )
continue;
if ( F_221 ( V_318 , V_75 , V_350 ) < 0 ) {
V_175 -- ;
goto V_333;
}
}
V_333:
V_350 -> args [ 0 ] = V_175 ;
V_162:
F_130 ( & V_179 ) ;
return V_318 -> V_253 ;
}
static int F_225 ( struct V_108 * V_109 ,
struct V_320 * V_358 , int V_359 )
{
struct V_320 * V_361 [ V_391 + 1 ] ;
struct V_320 * V_367 , * V_364 ;
if ( V_358 == NULL ||
F_211 ( V_361 , V_391 , V_358 , V_392 ) )
return - V_134 ;
V_367 = V_361 [ V_377 ] ;
V_364 = V_361 [ V_378 ] ;
if ( ! ( V_367 && V_364 ) )
return - V_134 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_214 ( & V_109 -> V_4 , V_367 , sizeof( V_109 -> V_4 ) ) ;
V_109 -> V_43 = F_215 ( V_364 ) ;
if ( V_359 ) {
struct V_320 * V_393 , * V_394 , * V_395 ,
* V_396 ;
V_393 = V_361 [ V_379 ] ;
V_394 = V_361 [ V_380 ] ;
V_395 = V_361 [ V_381 ] ;
V_396 = V_361 [ V_382 ] ;
if ( ! ( V_393 && V_394 && V_395 && V_396 ) )
return - V_134 ;
V_109 -> V_113 = F_213 ( V_393 )
& V_85 ;
V_109 -> V_114 = F_213 ( V_394 ) ;
V_109 -> V_119 = F_213 ( V_395 ) ;
V_109 -> V_121 = F_213 ( V_396 ) ;
}
return 0 ;
}
static int F_226 ( struct V_317 * V_318 , T_3 V_95 ,
const char * V_270 , T_3 V_271 )
{
struct V_320 * V_397 ;
V_397 = F_192 ( V_318 , V_398 ) ;
if ( ! V_397 )
return - V_322 ;
if ( F_193 ( V_318 , V_399 , V_95 ) ||
F_201 ( V_318 , V_400 , V_270 ) ||
F_193 ( V_318 , V_401 , V_271 ) )
goto V_333;
F_195 ( V_318 , V_397 ) ;
return 0 ;
V_333:
F_196 ( V_318 , V_397 ) ;
return - V_322 ;
}
static int F_227 ( struct V_317 * V_318 , T_3 V_95 ,
const char * V_270 , T_3 V_271 ,
struct V_349 * V_350 )
{
void * V_351 ;
V_351 = F_204 ( V_318 , F_205 ( V_350 -> V_318 ) . V_352 , V_350 -> V_353 -> V_354 ,
& V_355 , V_356 ,
V_402 ) ;
if ( ! V_351 )
return - V_322 ;
if ( F_226 ( V_318 , V_95 , V_270 , V_271 ) )
goto V_333;
return F_206 ( V_318 , V_351 ) ;
V_333:
F_207 ( V_318 , V_351 ) ;
return - V_322 ;
}
static int F_228 ( struct V_317 * V_318 ,
struct V_349 * V_350 )
{
struct V_2 * V_2 = F_209 ( V_318 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_129 ( & V_15 -> V_267 ) ;
if ( ( V_15 -> V_298 & V_299 ) && ! V_350 -> args [ 0 ] ) {
if ( F_227 ( V_318 , V_299 ,
V_15 -> V_300 ,
V_15 -> V_301 , V_350 ) < 0 )
goto V_333;
V_350 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_298 & V_302 ) && ! V_350 -> args [ 1 ] ) {
if ( F_227 ( V_318 , V_302 ,
V_15 -> V_303 ,
V_15 -> V_304 , V_350 ) < 0 )
goto V_333;
V_350 -> args [ 1 ] = 1 ;
}
V_333:
F_130 ( & V_15 -> V_267 ) ;
return V_318 -> V_253 ;
}
static int F_229 ( struct V_2 * V_2 , struct V_320 * * V_361 )
{
if ( ! ( V_361 [ V_399 ] &&
V_361 [ V_400 ] &&
V_361 [ V_401 ] ) )
return - V_134 ;
return F_180 ( V_2 ,
F_213 ( V_361 [ V_399 ] ) ,
F_216 ( V_361 [ V_400 ] ) ,
F_213 ( V_361 [ V_401 ] ) ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_320 * * V_361 )
{
if ( ! V_361 [ V_399 ] )
return - V_134 ;
return F_181 ( V_2 ,
F_213 ( V_361 [ V_399 ] ) ) ;
}
static int F_231 ( struct V_2 * V_2 , struct V_320 * * V_361 )
{
struct V_231 V_316 ;
F_187 ( V_2 , & V_316 ) ;
if ( V_361 [ V_403 ] )
V_316 . V_236 = F_213 ( V_361 [ V_403 ] ) ;
if ( V_361 [ V_404 ] )
V_316 . V_237 =
F_213 ( V_361 [ V_404 ] ) ;
if ( V_361 [ V_405 ] )
V_316 . V_238 = F_213 ( V_361 [ V_405 ] ) ;
return F_169 ( V_2 , & V_316 ) ;
}
static int F_232 ( struct V_317 * V_318 , struct V_406 * V_309 )
{
int V_144 = 0 , V_251 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_209 ( V_318 ) ;
V_15 = F_41 ( V_2 ) ;
V_251 = V_309 -> V_407 -> V_251 ;
if ( V_251 == V_402 || V_251 == V_408 ) {
struct V_320 * V_409 [ V_410 + 1 ] ;
F_129 ( & V_15 -> V_267 ) ;
if ( ! V_309 -> V_361 [ V_398 ] ||
F_211 ( V_409 , V_410 ,
V_309 -> V_361 [ V_398 ] ,
V_411 ) ) {
V_144 = - V_134 ;
goto V_67;
}
if ( V_251 == V_402 )
V_144 = F_229 ( V_2 , V_409 ) ;
else
V_144 = F_230 ( V_2 , V_409 ) ;
V_67:
F_130 ( & V_15 -> V_267 ) ;
}
return V_144 ;
}
static int F_233 ( struct V_317 * V_318 , struct V_406 * V_309 )
{
struct V_54 * V_55 = NULL ;
struct V_156 V_244 ;
struct V_108 V_109 ;
int V_144 = 0 , V_251 ;
int V_412 = 0 , V_413 = 0 ;
struct V_2 * V_2 ;
V_2 = F_209 ( V_318 ) ;
V_251 = V_309 -> V_407 -> V_251 ;
F_129 ( & V_179 ) ;
if ( V_251 == V_414 ) {
V_144 = F_126 ( V_2 , false ) ;
goto V_67;
} else if ( V_251 == V_415 ) {
V_144 = F_231 ( V_2 , V_309 -> V_361 ) ;
goto V_67;
} else if ( V_251 == V_416 &&
! V_309 -> V_361 [ V_337 ] ) {
V_144 = F_136 ( V_2 ) ;
goto V_67;
}
if ( V_251 == V_357 || V_251 == V_417 )
V_412 = 1 ;
V_144 = F_210 ( V_2 , & V_244 ,
V_309 -> V_361 [ V_337 ] ,
V_412 , & V_55 ) ;
if ( V_144 )
goto V_67;
if ( ( V_251 != V_357 ) && ( V_55 == NULL ) ) {
V_144 = - V_278 ;
goto V_67;
}
if ( V_251 == V_387 || V_251 == V_418 ||
V_251 == V_419 ) {
if ( V_251 != V_419 )
V_413 = 1 ;
V_144 = F_225 ( & V_109 ,
V_309 -> V_361 [ V_376 ] ,
V_413 ) ;
if ( V_144 )
goto V_67;
}
switch ( V_251 ) {
case V_357 :
if ( V_55 == NULL )
V_144 = F_111 ( V_2 , & V_244 , & V_55 ) ;
else
V_144 = - V_146 ;
break;
case V_417 :
V_144 = F_120 ( V_55 , & V_244 ) ;
break;
case V_420 :
V_144 = F_125 ( V_55 ) ;
break;
case V_387 :
V_144 = F_95 ( V_55 , & V_109 ) ;
break;
case V_418 :
V_144 = F_97 ( V_55 , & V_109 ) ;
break;
case V_419 :
V_144 = F_109 ( V_55 , & V_109 ) ;
break;
case V_416 :
V_144 = F_135 ( V_55 ) ;
break;
default:
V_144 = - V_134 ;
}
V_67:
F_130 ( & V_179 ) ;
return V_144 ;
}
static int F_234 ( struct V_317 * V_318 , struct V_406 * V_309 )
{
struct V_317 * V_421 ;
void * V_422 ;
int V_144 , V_251 , V_423 ;
struct V_2 * V_2 ;
V_2 = F_209 ( V_318 ) ;
V_251 = V_309 -> V_407 -> V_251 ;
if ( V_251 == V_424 )
V_423 = V_357 ;
else if ( V_251 == V_425 )
V_423 = V_426 ;
else if ( V_251 == V_427 )
V_423 = V_415 ;
else {
F_28 ( L_59 ) ;
return - V_134 ;
}
V_421 = F_235 ( V_428 , V_137 ) ;
if ( ! V_421 )
return - V_138 ;
F_129 ( & V_179 ) ;
V_422 = F_236 ( V_421 , V_309 , & V_355 , 0 , V_423 ) ;
if ( V_422 == NULL )
goto V_333;
switch ( V_251 ) {
case V_424 :
{
struct V_54 * V_55 ;
V_55 = F_218 ( V_2 ,
V_309 -> V_361 [ V_337 ] ) ;
if ( F_224 ( V_55 ) ) {
V_144 = F_237 ( V_55 ) ;
goto V_162;
} else if ( V_55 ) {
V_144 = F_197 ( V_421 , V_55 ) ;
if ( V_144 )
goto V_333;
} else {
V_144 = - V_278 ;
goto V_162;
}
break;
}
case V_427 :
{
struct V_231 V_316 ;
F_187 ( V_2 , & V_316 ) ;
#ifdef V_232
if ( F_193 ( V_421 , V_403 ,
V_316 . V_236 ) ||
F_193 ( V_421 , V_404 ,
V_316 . V_237 ) )
goto V_333;
#endif
#ifdef V_233
if ( F_193 ( V_421 , V_405 , V_316 . V_238 ) )
goto V_333;
#endif
break;
}
case V_425 :
if ( F_193 ( V_421 , V_429 ,
V_214 ) ||
F_193 ( V_421 , V_430 ,
V_215 ) )
goto V_333;
break;
}
F_206 ( V_421 , V_422 ) ;
V_144 = F_238 ( V_421 , V_309 ) ;
goto V_67;
V_333:
F_28 ( L_60 ) ;
V_144 = - V_322 ;
V_162:
F_239 ( V_421 ) ;
V_67:
F_130 ( & V_179 ) ;
return V_144 ;
}
static int T_12 F_240 ( void )
{
return F_241 ( & V_355 ,
V_431 , F_242 ( V_431 ) ) ;
}
static void F_243 ( void )
{
F_244 ( & V_355 ) ;
}
static int T_13 F_245 ( struct V_2 * V_2 )
{
int V_175 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct T_6 * V_432 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_93 ( & V_15 -> V_25 ) ;
F_93 ( & V_15 -> V_28 ) ;
F_93 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_433 ) ) {
V_432 = F_246 ( V_434 , sizeof( V_434 ) , V_137 ) ;
if ( V_432 == NULL )
return - V_138 ;
if ( V_2 -> V_256 != & V_435 )
V_432 [ 0 ] . V_436 = NULL ;
} else
V_432 = V_434 ;
V_175 = 0 ;
V_15 -> V_24 = 1024 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_32 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_26 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_29 ;
#ifdef F_247
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_437 ;
#endif
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_34 ;
V_15 -> V_438 = 1 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_438 ;
V_15 -> V_439 = 1 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_439 ;
V_15 -> V_440 = 1 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_440 ;
V_15 -> V_441 = F_248 () / 32 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_441 ;
V_15 -> V_442 = 0 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_442 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_443 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_444 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_445 ;
V_15 -> V_446 [ 0 ] = V_447 ;
V_15 -> V_446 [ 1 ] = V_448 ;
V_432 [ V_175 ] . V_154 = & V_15 -> V_446 ;
V_432 [ V_175 ++ ] . V_449 = sizeof( V_15 -> V_446 ) ;
V_15 -> V_450 = V_451 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_450 ;
V_15 -> V_452 = F_249 ( int , V_453 , 0 , 3 ) ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_452 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_454 ;
V_15 -> V_455 = 1 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_455 ;
V_432 [ V_175 ++ ] . V_154 = & V_15 -> V_456 ;
V_15 -> V_457 = F_250 ( V_2 , L_61 , V_432 ) ;
if ( V_15 -> V_457 == NULL ) {
if ( ! F_38 ( V_2 , & V_433 ) )
F_48 ( V_432 ) ;
return - V_138 ;
}
F_83 ( V_2 , & V_15 -> V_188 ) ;
V_15 -> V_458 = V_432 ;
F_251 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_14 F_252 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_253 ( & V_15 -> V_37 ) ;
F_254 ( & V_15 -> V_37 . V_36 ) ;
F_255 ( V_15 -> V_457 ) ;
}
static int T_13 F_245 ( struct V_2 * V_2 ) { return 0 ; }
static void T_14 F_252 ( struct V_2 * V_2 ) { }
int T_13 F_256 ( struct V_2 * V_2 )
{
int V_175 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
for ( V_175 = 0 ; V_175 < V_459 ; V_175 ++ )
F_257 ( & V_15 -> V_82 [ V_175 ] ) ;
F_115 ( & V_15 -> V_149 ) ;
F_93 ( & V_15 -> V_93 ) ;
F_258 ( & V_15 -> V_98 , F_110 ,
( unsigned long ) V_2 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_188 . V_77 = F_90 ( struct V_139 ) ;
if ( ! V_15 -> V_188 . V_77 )
return - V_138 ;
F_93 ( & V_15 -> V_188 . V_102 ) ;
F_259 ( L_62 , 0 , V_2 -> V_460 , & V_461 ) ;
F_259 ( L_63 , 0 , V_2 -> V_460 , & V_462 ) ;
F_259 ( L_64 , 0 , V_2 -> V_460 ,
& V_463 ) ;
if ( F_245 ( V_2 ) )
goto V_464;
return 0 ;
V_464:
F_47 ( V_15 -> V_188 . V_77 ) ;
return - V_138 ;
}
void T_14 F_260 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_261 () ;
F_73 ( V_2 ) ;
F_101 ( V_2 , & V_15 -> V_188 ) ;
F_252 ( V_2 ) ;
F_262 ( L_64 , V_2 -> V_460 ) ;
F_262 ( L_63 , V_2 -> V_460 ) ;
F_262 ( L_62 , V_2 -> V_460 ) ;
F_47 ( V_15 -> V_188 . V_77 ) ;
}
int T_12 F_263 ( void )
{
int V_144 ;
V_144 = F_264 ( & V_465 ) ;
if ( V_144 ) {
F_28 ( L_65 ) ;
goto V_466;
}
V_144 = F_240 () ;
if ( V_144 ) {
F_28 ( L_66 ) ;
goto V_467;
}
return 0 ;
V_467:
F_265 ( & V_465 ) ;
V_466:
return V_144 ;
}
void F_266 ( void )
{
F_243 () ;
F_265 ( & V_465 ) ;
}
int T_12 F_267 ( void )
{
int V_175 ;
int V_144 ;
F_86 ( 2 ) ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_257 ( & V_61 [ V_175 ] ) ;
F_257 ( & V_63 [ V_175 ] ) ;
}
F_268 () ;
V_144 = F_269 ( & V_468 ) ;
if ( V_144 < 0 )
return V_144 ;
F_94 ( 2 ) ;
return 0 ;
}
void F_270 ( void )
{
F_86 ( 2 ) ;
F_271 ( & V_468 ) ;
F_94 ( 2 ) ;
}
