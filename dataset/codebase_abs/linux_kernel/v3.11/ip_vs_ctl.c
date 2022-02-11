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
struct V_180 * V_11 = F_133 ( V_185 ) ;
struct V_2 * V_2 = F_134 ( V_11 ) ;
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
F_135 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_67 (dest, &svc->destinations,
n_list) {
F_131 ( V_75 , V_11 ) ;
}
}
}
F_135 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
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
static int F_136 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_67 (dest, &svc->destinations, n_list) {
F_79 ( & V_75 -> V_76 ) ;
}
F_79 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_137 ( struct V_2 * V_2 )
{
int V_175 ;
struct V_54 * V_55 ;
for( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_135 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_136 ( V_55 ) ;
}
}
for( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_135 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_136 ( V_55 ) ;
}
}
F_79 ( & F_41 ( V_2 ) -> V_188 ) ;
return 0 ;
}
static int
F_138 ( struct V_189 * V_190 , int V_191 ,
void T_6 * V_192 , V_50 * V_193 , T_7 * V_194 )
{
struct V_2 * V_2 = V_195 -> V_196 -> V_197 ;
int * V_198 = V_190 -> V_154 ;
int V_199 = * V_198 ;
int V_200 ;
V_200 = F_139 ( V_190 , V_191 , V_192 , V_193 , V_194 ) ;
if ( V_191 && ( * V_198 != V_199 ) ) {
if ( ( * V_198 < 0 ) || ( * V_198 > 3 ) ) {
* V_198 = V_199 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_200 ;
}
static int
F_140 ( struct V_189 * V_190 , int V_191 ,
void T_6 * V_192 , V_50 * V_193 , T_7 * V_194 )
{
int * V_198 = V_190 -> V_154 ;
int V_199 [ 2 ] ;
int V_200 ;
memcpy ( V_199 , V_198 , sizeof( V_199 ) ) ;
V_200 = F_139 ( V_190 , V_191 , V_192 , V_193 , V_194 ) ;
if ( V_191 && ( V_198 [ 0 ] < 0 || V_198 [ 1 ] < 0 ||
( V_198 [ 0 ] >= V_198 [ 1 ] && V_198 [ 1 ] ) ) ) {
memcpy ( V_198 , V_199 , sizeof( V_199 ) ) ;
}
return V_200 ;
}
static int
F_141 ( struct V_189 * V_190 , int V_191 ,
void T_6 * V_192 , V_50 * V_193 , T_7 * V_194 )
{
int * V_198 = V_190 -> V_154 ;
int V_199 = * V_198 ;
int V_200 ;
V_200 = F_139 ( V_190 , V_191 , V_192 , V_193 , V_194 ) ;
if ( V_191 && ( * V_198 != V_199 ) ) {
if ( ( * V_198 < 0 ) || ( * V_198 > 1 ) ) {
* V_198 = V_199 ;
}
}
return V_200 ;
}
static int
F_142 ( struct V_189 * V_190 , int V_191 ,
void T_6 * V_192 , V_50 * V_193 , T_7 * V_194 )
{
int * V_198 = V_190 -> V_154 ;
int V_199 = * V_198 ;
int V_200 ;
V_200 = F_139 ( V_190 , V_191 , V_192 , V_193 , V_194 ) ;
if ( V_191 && ( * V_198 != V_199 ) ) {
if ( * V_198 < 1 || ! F_143 ( * V_198 ) ) {
* V_198 = V_199 ;
}
}
return V_200 ;
}
static inline const char * F_144 ( unsigned int V_12 )
{
switch ( V_12 & V_85 ) {
case V_201 :
return L_25 ;
case V_202 :
return L_26 ;
case V_203 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_145 ( struct V_204 * V_205 , T_7 V_206 )
{
struct V_2 * V_2 = F_146 ( V_205 ) ;
struct V_207 * V_208 = V_205 -> V_209 ;
int V_175 ;
struct V_54 * V_55 ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_206 -- == 0 ) {
V_208 -> V_190 = V_61 ;
V_208 -> V_210 = V_175 ;
return V_55 ;
}
}
}
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_206 -- == 0 ) {
V_208 -> V_190 = V_63 ;
V_208 -> V_210 = V_175 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_147 ( struct V_204 * V_205 , T_7 * V_206 )
__acquires( T_8 )
{
F_55 () ;
return * V_206 ? F_145 ( V_205 , * V_206 - 1 ) : V_211 ;
}
static void * F_148 ( struct V_204 * V_205 , void * V_212 , T_7 * V_206 )
{
struct V_176 * V_213 ;
struct V_207 * V_208 ;
struct V_54 * V_55 ;
++ * V_206 ;
if ( V_212 == V_211 )
return F_145 ( V_205 , 0 ) ;
V_55 = V_212 ;
V_208 = V_205 -> V_209 ;
if ( V_208 -> V_190 == V_61 ) {
V_213 = F_149 ( F_150 ( & V_55 -> V_60 ) ) ;
if ( V_213 )
return F_151 ( V_213 , struct V_54 , V_60 ) ;
while ( ++ V_208 -> V_210 < V_178 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_208 -> V_190 = V_63 ;
V_208 -> V_210 = - 1 ;
goto V_214;
}
V_213 = F_149 ( F_150 ( & V_55 -> V_62 ) ) ;
if ( V_213 )
return F_151 ( V_213 , struct V_54 , V_62 ) ;
V_214:
while ( ++ V_208 -> V_210 < V_178 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_152 ( struct V_204 * V_205 , void * V_212 )
__releases( T_8 )
{
F_56 () ;
}
static int F_153 ( struct V_204 * V_205 , void * V_212 )
{
if ( V_212 == V_211 ) {
F_154 ( V_205 ,
L_29 ,
F_155 ( V_215 ) , V_216 ) ;
F_156 ( V_205 ,
L_30 ) ;
F_156 ( V_205 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_212 ;
const struct V_207 * V_208 = V_205 -> V_209 ;
const struct V_74 * V_75 ;
struct V_111 * V_112 = F_149 ( V_55 -> V_123 ) ;
if ( V_208 -> V_190 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_154 ( V_205 , L_32 ,
F_43 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_131 ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_181 ) ;
else
#endif
F_154 ( V_205 , L_33 ,
F_43 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_181 ,
( V_55 -> V_12 & V_217 ) ? L_34 : L_35 ) ;
} else {
F_154 ( V_205 , L_36 ,
V_55 -> V_53 , V_112 -> V_181 ,
( V_55 -> V_12 & V_217 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_218 )
F_154 ( V_205 , L_37 ,
V_55 -> V_167 ,
F_25 ( V_55 -> V_166 ) ) ;
else
F_157 ( V_205 , '\n' ) ;
F_58 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_154 ( V_205 ,
L_38
L_39 ,
& V_75 -> V_4 . V_131 ,
F_23 ( V_75 -> V_43 ) ,
F_144 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_141 ) ,
F_15 ( & V_75 -> V_142 ) ) ;
else
#endif
F_154 ( V_205 ,
L_40
L_41 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_144 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_141 ) ,
F_15 ( & V_75 -> V_142 ) ) ;
}
}
return 0 ;
}
static int F_158 ( struct V_219 * V_219 , struct V_220 * V_220 )
{
return F_159 ( V_219 , V_220 , & V_221 ,
sizeof( struct V_207 ) ) ;
}
static int F_160 ( struct V_204 * V_205 , void * V_212 )
{
struct V_2 * V_2 = F_161 ( V_205 ) ;
struct V_99 V_222 ;
F_156 ( V_205 ,
L_42 ) ;
F_154 ( V_205 ,
L_43 ) ;
F_76 ( & V_222 , & F_41 ( V_2 ) -> V_188 ) ;
F_154 ( V_205 , L_44 , V_222 . V_103 ,
V_222 . V_104 , V_222 . V_105 ,
( unsigned long long ) V_222 . V_106 ,
( unsigned long long ) V_222 . V_107 ) ;
F_156 ( V_205 ,
L_45 ) ;
F_154 ( V_205 , L_46 ,
V_222 . V_223 , V_222 . V_224 , V_222 . V_225 ,
V_222 . V_226 , V_222 . V_227 ) ;
return 0 ;
}
static int F_162 ( struct V_219 * V_219 , struct V_220 * V_220 )
{
return F_163 ( V_219 , V_220 , F_160 ) ;
}
static int F_164 ( struct V_204 * V_205 , void * V_212 )
{
struct V_2 * V_2 = F_161 ( V_205 ) ;
struct V_100 * V_188 = & F_41 ( V_2 ) -> V_188 ;
struct V_139 T_9 * V_77 = V_188 -> V_77 ;
struct V_99 V_228 ;
int V_17 ;
F_156 ( V_205 ,
L_47 ) ;
F_154 ( V_205 ,
L_48 ) ;
F_165 (i) {
struct V_139 * V_157 = F_166 ( V_77 , V_17 ) ;
unsigned int V_229 ;
T_10 V_106 , V_107 ;
do {
V_229 = F_167 ( & V_157 -> V_230 ) ;
V_106 = V_157 -> V_231 . V_106 ;
V_107 = V_157 -> V_231 . V_107 ;
} while ( F_168 ( & V_157 -> V_230 , V_229 ) );
F_154 ( V_205 , L_49 ,
V_17 , V_157 -> V_231 . V_103 , V_157 -> V_231 . V_104 ,
V_157 -> V_231 . V_105 , ( T_10 ) V_106 ,
( T_10 ) V_107 ) ;
}
F_66 ( & V_188 -> V_102 ) ;
F_154 ( V_205 , L_50 ,
V_188 -> V_231 . V_103 , V_188 -> V_231 . V_104 ,
V_188 -> V_231 . V_105 ,
( unsigned long long ) V_188 -> V_231 . V_106 ,
( unsigned long long ) V_188 -> V_231 . V_107 ) ;
F_78 ( & V_228 , V_188 ) ;
F_71 ( & V_188 -> V_102 ) ;
F_156 ( V_205 ,
L_51 ) ;
F_154 ( V_205 , L_52 ,
V_228 . V_223 ,
V_228 . V_224 ,
V_228 . V_225 ,
V_228 . V_226 ,
V_228 . V_227 ) ;
return 0 ;
}
static int F_169 ( struct V_219 * V_219 , struct V_220 * V_220 )
{
return F_163 ( V_219 , V_220 , F_164 ) ;
}
static int F_170 ( struct V_2 * V_2 , struct V_232 * V_157 )
{
#if F_171 ( V_233 ) || F_171 ( V_234 )
struct V_235 * V_236 ;
#endif
F_96 ( 2 , L_53 ,
V_157 -> V_237 ,
V_157 -> V_238 ,
V_157 -> V_239 ) ;
#ifdef V_233
if ( V_157 -> V_237 ) {
V_236 = F_172 ( V_2 , V_68 ) ;
V_236 -> V_240 [ V_241 ]
= V_157 -> V_237 * V_168 ;
}
if ( V_157 -> V_238 ) {
V_236 = F_172 ( V_2 , V_68 ) ;
V_236 -> V_240 [ V_242 ]
= V_157 -> V_238 * V_168 ;
}
#endif
#ifdef V_234
if ( V_157 -> V_239 ) {
V_236 = F_172 ( V_2 , V_243 ) ;
V_236 -> V_240 [ V_244 ]
= V_157 -> V_239 * V_168 ;
}
#endif
return 0 ;
}
static void F_173 ( struct V_156 * V_245 ,
struct V_246 * V_247 )
{
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_40 = V_170 ;
V_245 -> V_59 = V_247 -> V_59 ;
V_245 -> V_4 . V_46 = V_247 -> V_4 ;
V_245 -> V_43 = V_247 -> V_43 ;
V_245 -> V_53 = V_247 -> V_53 ;
V_245 -> V_161 = V_247 -> V_161 ;
V_245 -> V_12 = V_247 -> V_12 ;
V_245 -> V_167 = V_247 -> V_167 ;
V_245 -> V_166 = V_247 -> V_166 ;
}
static void F_174 ( struct V_108 * V_109 ,
struct V_248 * V_249 )
{
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
V_109 -> V_4 . V_46 = V_249 -> V_4 ;
V_109 -> V_43 = V_249 -> V_43 ;
V_109 -> V_113 = V_249 -> V_113 ;
V_109 -> V_114 = V_249 -> V_114 ;
V_109 -> V_119 = V_249 -> V_119 ;
V_109 -> V_121 = V_249 -> V_121 ;
}
static int
F_175 ( struct V_250 * V_251 , int V_252 , void T_6 * V_253 , unsigned int V_254 )
{
struct V_2 * V_2 = F_176 ( V_251 ) ;
int V_144 ;
unsigned char V_255 [ V_256 ] ;
struct V_246 * V_247 ;
struct V_156 V_245 ;
struct V_54 * V_55 ;
struct V_248 * V_249 ;
struct V_108 V_109 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
if ( ! F_177 ( F_176 ( V_251 ) -> V_257 , V_258 ) )
return - V_259 ;
if ( V_252 < V_260 || V_252 > V_261 )
return - V_134 ;
if ( V_254 < 0 || V_254 > V_256 )
return - V_134 ;
if ( V_254 != V_262 [ F_178 ( V_252 ) ] ) {
F_28 ( L_54 ,
V_254 , V_262 [ F_178 ( V_252 ) ] ) ;
return - V_134 ;
}
if ( F_179 ( V_255 , V_253 , V_254 ) != 0 )
return - V_263 ;
F_18 () ;
if ( V_252 == V_264 ||
V_252 == V_265 ) {
struct V_266 * V_267 = (struct V_266 * ) V_255 ;
if ( F_180 ( & V_15 -> V_268 ) ) {
V_144 = - V_269 ;
goto V_270;
}
if ( V_252 == V_264 )
V_144 = F_181 ( V_2 , V_267 -> V_95 , V_267 -> V_271 ,
V_267 -> V_272 ) ;
else
V_144 = F_182 ( V_2 , V_267 -> V_95 ) ;
F_130 ( & V_15 -> V_268 ) ;
goto V_270;
}
if ( F_180 ( & V_179 ) ) {
V_144 = - V_269 ;
goto V_270;
}
if ( V_252 == V_273 ) {
V_144 = F_126 ( V_2 , false ) ;
goto V_274;
} else if ( V_252 == V_275 ) {
V_144 = F_170 ( V_2 , (struct V_232 * ) V_255 ) ;
goto V_274;
}
V_247 = (struct V_246 * ) V_255 ;
V_249 = (struct V_248 * ) ( V_247 + 1 ) ;
F_173 ( & V_245 , V_247 ) ;
F_174 ( & V_109 , V_249 ) ;
if ( V_252 == V_276 ) {
if ( ! V_245 . V_53 && ! V_245 . V_4 . V_46 && ! V_245 . V_43 ) {
V_144 = F_137 ( V_2 ) ;
goto V_274;
}
}
if ( V_245 . V_59 != V_68 && V_245 . V_59 != V_243 &&
V_245 . V_59 != V_277 ) {
F_28 ( L_55 ,
V_245 . V_59 , & V_245 . V_4 . V_46 ,
F_23 ( V_245 . V_43 ) , V_245 . V_161 ) ;
V_144 = - V_263 ;
goto V_274;
}
F_55 () ;
if ( V_245 . V_53 == 0 )
V_55 = F_35 ( V_2 , V_245 . V_40 , V_245 . V_59 ,
& V_245 . V_4 , V_245 . V_43 ) ;
else
V_55 = F_39 ( V_2 , V_245 . V_40 , V_245 . V_53 ) ;
F_56 () ;
if ( V_252 != V_278
&& ( V_55 == NULL || V_55 -> V_59 != V_245 . V_59 ) ) {
V_144 = - V_279 ;
goto V_274;
}
switch ( V_252 ) {
case V_278 :
if ( V_55 != NULL )
V_144 = - V_146 ;
else
V_144 = F_111 ( V_2 , & V_245 , & V_55 ) ;
break;
case V_280 :
V_144 = F_120 ( V_55 , & V_245 ) ;
break;
case V_281 :
V_144 = F_125 ( V_55 ) ;
if ( ! V_144 )
goto V_274;
break;
case V_276 :
V_144 = F_136 ( V_55 ) ;
break;
case V_282 :
V_144 = F_95 ( V_55 , & V_109 ) ;
break;
case V_283 :
V_144 = F_97 ( V_55 , & V_109 ) ;
break;
case V_284 :
V_144 = F_109 ( V_55 , & V_109 ) ;
break;
default:
V_144 = - V_134 ;
}
V_274:
F_130 ( & V_179 ) ;
V_270:
F_20 () ;
return V_144 ;
}
static void
F_183 ( struct V_285 * V_9 , struct V_54 * V_101 )
{
struct V_111 * V_112 ;
V_112 = F_62 ( V_101 -> V_123 , 1 ) ;
V_9 -> V_59 = V_101 -> V_59 ;
V_9 -> V_4 = V_101 -> V_4 . V_46 ;
V_9 -> V_43 = V_101 -> V_43 ;
V_9 -> V_53 = V_101 -> V_53 ;
F_184 ( V_9 -> V_161 , V_112 -> V_181 , sizeof( V_9 -> V_161 ) ) ;
V_9 -> V_12 = V_101 -> V_12 ;
V_9 -> V_167 = V_101 -> V_167 / V_168 ;
V_9 -> V_166 = V_101 -> V_166 ;
V_9 -> V_126 = V_101 -> V_126 ;
F_76 ( & V_9 -> V_76 , & V_101 -> V_76 ) ;
}
static inline int
F_185 ( struct V_2 * V_2 ,
const struct V_286 * V_287 ,
struct V_286 T_6 * V_288 )
{
int V_175 , V_289 = 0 ;
struct V_54 * V_55 ;
struct V_285 V_290 ;
int V_144 = 0 ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_135 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_170 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_289 >= V_287 -> V_171 )
goto V_67;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
F_183 ( & V_290 , V_55 ) ;
if ( F_186 ( & V_288 -> V_291 [ V_289 ] ,
& V_290 , sizeof( V_290 ) ) ) {
V_144 = - V_263 ;
goto V_67;
}
V_289 ++ ;
}
}
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_135 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_170 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_289 >= V_287 -> V_171 )
goto V_67;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
F_183 ( & V_290 , V_55 ) ;
if ( F_186 ( & V_288 -> V_291 [ V_289 ] ,
& V_290 , sizeof( V_290 ) ) ) {
V_144 = - V_263 ;
goto V_67;
}
V_289 ++ ;
}
}
V_67:
return V_144 ;
}
static inline int
F_187 ( struct V_2 * V_2 , const struct V_292 * V_287 ,
struct V_292 T_6 * V_288 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_287 -> V_4 } ;
int V_144 = 0 ;
F_55 () ;
if ( V_287 -> V_53 )
V_55 = F_39 ( V_2 , V_170 , V_287 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_170 , V_287 -> V_59 , & V_4 ,
V_287 -> V_43 ) ;
F_56 () ;
if ( V_55 ) {
int V_289 = 0 ;
struct V_74 * V_75 ;
struct V_293 V_290 ;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
F_67 (dest, &svc->destinations, n_list) {
if ( V_289 >= V_287 -> V_126 )
break;
V_290 . V_4 = V_75 -> V_4 . V_46 ;
V_290 . V_43 = V_75 -> V_43 ;
V_290 . V_113 = F_15 ( & V_75 -> V_113 ) ;
V_290 . V_114 = F_15 ( & V_75 -> V_114 ) ;
V_290 . V_119 = V_75 -> V_119 ;
V_290 . V_121 = V_75 -> V_121 ;
V_290 . V_141 = F_15 ( & V_75 -> V_141 ) ;
V_290 . V_142 = F_15 ( & V_75 -> V_142 ) ;
V_290 . V_143 = F_15 ( & V_75 -> V_143 ) ;
F_76 ( & V_290 . V_76 , & V_75 -> V_76 ) ;
if ( F_186 ( & V_288 -> V_291 [ V_289 ] ,
& V_290 , sizeof( V_290 ) ) ) {
V_144 = - V_263 ;
break;
}
V_289 ++ ;
}
} else
V_144 = - V_279 ;
return V_144 ;
}
static inline void
F_188 ( struct V_2 * V_2 , struct V_232 * V_157 )
{
#if F_171 ( V_233 ) || F_171 ( V_234 )
struct V_235 * V_236 ;
#endif
memset ( V_157 , 0 , sizeof ( * V_157 ) ) ;
#ifdef V_233
V_236 = F_172 ( V_2 , V_68 ) ;
V_157 -> V_237 = V_236 -> V_240 [ V_241 ] / V_168 ;
V_157 -> V_238 = V_236 -> V_240 [ V_242 ] / V_168 ;
#endif
#ifdef V_234
V_236 = F_172 ( V_2 , V_243 ) ;
V_157 -> V_239 =
V_236 -> V_240 [ V_244 ] / V_168 ;
#endif
}
static int
F_189 ( struct V_250 * V_251 , int V_252 , void T_6 * V_253 , int * V_254 )
{
unsigned char V_255 [ 128 ] ;
int V_144 = 0 ;
unsigned int V_294 ;
struct V_2 * V_2 = F_176 ( V_251 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_190 ( ! V_2 ) ;
if ( ! F_177 ( F_176 ( V_251 ) -> V_257 , V_258 ) )
return - V_259 ;
if ( V_252 < V_260 || V_252 > V_295 )
return - V_134 ;
if ( * V_254 < V_296 [ F_191 ( V_252 ) ] ) {
F_28 ( L_56 ,
* V_254 , V_296 [ F_191 ( V_252 ) ] ) ;
return - V_134 ;
}
V_294 = V_296 [ F_191 ( V_252 ) ] ;
if ( V_294 > 128 )
return - V_134 ;
if ( F_179 ( V_255 , V_253 , V_294 ) != 0 )
return - V_263 ;
if ( V_252 == V_297 ) {
struct V_266 V_298 [ 2 ] ;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
if ( F_180 ( & V_15 -> V_268 ) )
return - V_269 ;
if ( V_15 -> V_299 & V_300 ) {
V_298 [ 0 ] . V_95 = V_300 ;
F_184 ( V_298 [ 0 ] . V_271 , V_15 -> V_301 ,
sizeof( V_298 [ 0 ] . V_271 ) ) ;
V_298 [ 0 ] . V_272 = V_15 -> V_302 ;
}
if ( V_15 -> V_299 & V_303 ) {
V_298 [ 1 ] . V_95 = V_303 ;
F_184 ( V_298 [ 1 ] . V_271 , V_15 -> V_304 ,
sizeof( V_298 [ 1 ] . V_271 ) ) ;
V_298 [ 1 ] . V_272 = V_15 -> V_305 ;
}
if ( F_186 ( V_253 , & V_298 , sizeof( V_298 ) ) != 0 )
V_144 = - V_263 ;
F_130 ( & V_15 -> V_268 ) ;
return V_144 ;
}
if ( F_180 ( & V_179 ) )
return - V_269 ;
switch ( V_252 ) {
case V_306 :
{
char V_307 [ 64 ] ;
sprintf ( V_307 , L_57 ,
F_155 ( V_215 ) , V_216 ) ;
if ( F_186 ( V_253 , V_307 , strlen ( V_307 ) + 1 ) != 0 ) {
V_144 = - V_263 ;
goto V_67;
}
* V_254 = strlen ( V_307 ) + 1 ;
}
break;
case V_308 :
{
struct V_309 V_310 ;
V_310 . V_311 = V_215 ;
V_310 . V_312 = V_216 ;
V_310 . V_171 = V_15 -> V_171 ;
if ( F_186 ( V_253 , & V_310 , sizeof( V_310 ) ) != 0 )
V_144 = - V_263 ;
}
break;
case V_313 :
{
struct V_286 * V_287 ;
int V_312 ;
V_287 = (struct V_286 * ) V_255 ;
V_312 = sizeof( * V_287 ) +
sizeof( struct V_285 ) * V_287 -> V_171 ;
if ( * V_254 != V_312 ) {
F_28 ( L_58 , * V_254 , V_312 ) ;
V_144 = - V_134 ;
goto V_67;
}
V_144 = F_185 ( V_2 , V_287 , V_253 ) ;
}
break;
case V_314 :
{
struct V_285 * V_290 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_290 = (struct V_285 * ) V_255 ;
V_4 . V_46 = V_290 -> V_4 ;
F_55 () ;
if ( V_290 -> V_53 )
V_55 = F_39 ( V_2 , V_170 , V_290 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_170 ,
V_290 -> V_59 , & V_4 ,
V_290 -> V_43 ) ;
F_56 () ;
if ( V_55 ) {
F_183 ( V_290 , V_55 ) ;
if ( F_186 ( V_253 , V_290 , sizeof( * V_290 ) ) != 0 )
V_144 = - V_263 ;
} else
V_144 = - V_279 ;
}
break;
case V_315 :
{
struct V_292 * V_287 ;
int V_312 ;
V_287 = (struct V_292 * ) V_255 ;
V_312 = sizeof( * V_287 ) +
sizeof( struct V_293 ) * V_287 -> V_126 ;
if ( * V_254 != V_312 ) {
F_28 ( L_58 , * V_254 , V_312 ) ;
V_144 = - V_134 ;
goto V_67;
}
V_144 = F_187 ( V_2 , V_287 , V_253 ) ;
}
break;
case V_316 :
{
struct V_232 V_317 ;
F_188 ( V_2 , & V_317 ) ;
if ( F_186 ( V_253 , & V_317 , sizeof( V_317 ) ) != 0 )
V_144 = - V_263 ;
}
break;
default:
V_144 = - V_134 ;
}
V_67:
F_130 ( & V_179 ) ;
return V_144 ;
}
static int F_192 ( struct V_318 * V_319 , int V_320 ,
struct V_100 * V_76 )
{
struct V_99 V_231 ;
struct V_321 * V_322 = F_193 ( V_319 , V_320 ) ;
if ( ! V_322 )
return - V_323 ;
F_76 ( & V_231 , V_76 ) ;
if ( F_194 ( V_319 , V_324 , V_231 . V_103 ) ||
F_194 ( V_319 , V_325 , V_231 . V_104 ) ||
F_194 ( V_319 , V_326 , V_231 . V_105 ) ||
F_195 ( V_319 , V_327 , V_231 . V_106 ) ||
F_195 ( V_319 , V_328 , V_231 . V_107 ) ||
F_194 ( V_319 , V_329 , V_231 . V_223 ) ||
F_194 ( V_319 , V_330 , V_231 . V_224 ) ||
F_194 ( V_319 , V_331 , V_231 . V_225 ) ||
F_194 ( V_319 , V_332 , V_231 . V_226 ) ||
F_194 ( V_319 , V_333 , V_231 . V_227 ) )
goto V_334;
F_196 ( V_319 , V_322 ) ;
return 0 ;
V_334:
F_197 ( V_319 , V_322 ) ;
return - V_323 ;
}
static int F_198 ( struct V_318 * V_319 ,
struct V_54 * V_55 )
{
struct V_111 * V_112 ;
struct V_159 * V_160 ;
struct V_321 * V_335 ;
struct V_336 V_12 = { . V_12 = V_55 -> V_12 ,
. V_337 = ~ 0 } ;
V_335 = F_193 ( V_319 , V_338 ) ;
if ( ! V_335 )
return - V_323 ;
if ( F_199 ( V_319 , V_339 , V_55 -> V_40 ) )
goto V_334;
if ( V_55 -> V_53 ) {
if ( F_194 ( V_319 , V_340 , V_55 -> V_53 ) )
goto V_334;
} else {
if ( F_199 ( V_319 , V_341 , V_55 -> V_59 ) ||
F_200 ( V_319 , V_342 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_201 ( V_319 , V_343 , V_55 -> V_43 ) )
goto V_334;
}
V_112 = F_62 ( V_55 -> V_123 , 1 ) ;
V_160 = F_62 ( V_55 -> V_160 , 1 ) ;
if ( F_202 ( V_319 , V_344 , V_112 -> V_181 ) ||
( V_160 && F_202 ( V_319 , V_345 , V_160 -> V_181 ) ) ||
F_200 ( V_319 , V_346 , sizeof( V_12 ) , & V_12 ) ||
F_194 ( V_319 , V_347 , V_55 -> V_167 / V_168 ) ||
F_203 ( V_319 , V_348 , V_55 -> V_166 ) )
goto V_334;
if ( F_192 ( V_319 , V_349 , & V_55 -> V_76 ) )
goto V_334;
F_196 ( V_319 , V_335 ) ;
return 0 ;
V_334:
F_197 ( V_319 , V_335 ) ;
return - V_323 ;
}
static int F_204 ( struct V_318 * V_319 ,
struct V_54 * V_55 ,
struct V_350 * V_351 )
{
void * V_352 ;
V_352 = F_205 ( V_319 , F_206 ( V_351 -> V_319 ) . V_353 , V_351 -> V_354 -> V_355 ,
& V_356 , V_357 ,
V_358 ) ;
if ( ! V_352 )
return - V_323 ;
if ( F_198 ( V_319 , V_55 ) < 0 )
goto V_334;
return F_207 ( V_319 , V_352 ) ;
V_334:
F_208 ( V_319 , V_352 ) ;
return - V_323 ;
}
static int F_209 ( struct V_318 * V_319 ,
struct V_350 * V_351 )
{
int V_175 = 0 , V_17 ;
int V_229 = V_351 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_210 ( V_319 ) ;
F_129 ( & V_179 ) ;
for ( V_17 = 0 ; V_17 < V_178 ; V_17 ++ ) {
F_135 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_175 <= V_229 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_204 ( V_319 , V_55 , V_351 ) < 0 ) {
V_175 -- ;
goto V_334;
}
}
}
for ( V_17 = 0 ; V_17 < V_178 ; V_17 ++ ) {
F_135 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_175 <= V_229 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_204 ( V_319 , V_55 , V_351 ) < 0 ) {
V_175 -- ;
goto V_334;
}
}
}
V_334:
F_130 ( & V_179 ) ;
V_351 -> args [ 0 ] = V_175 ;
return V_319 -> V_254 ;
}
static int F_211 ( struct V_2 * V_2 ,
struct V_156 * V_245 ,
struct V_321 * V_359 , int V_360 ,
struct V_54 * * V_361 )
{
struct V_321 * V_362 [ V_363 + 1 ] ;
struct V_321 * V_364 , * V_365 , * V_366 , * V_367 , * V_368 ;
struct V_54 * V_55 ;
if ( V_359 == NULL ||
F_212 ( V_362 , V_363 , V_359 , V_369 ) )
return - V_134 ;
V_364 = V_362 [ V_339 ] ;
V_367 = V_362 [ V_341 ] ;
V_368 = V_362 [ V_342 ] ;
V_365 = V_362 [ V_343 ] ;
V_366 = V_362 [ V_340 ] ;
if ( ! ( V_364 && ( V_366 || ( V_365 && V_367 && V_368 ) ) ) )
return - V_134 ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_40 = F_213 ( V_364 ) ;
#ifdef F_24
if ( V_245 -> V_40 != V_170 && V_245 -> V_40 != V_48 )
#else
if ( V_245 -> V_40 != V_170 )
#endif
return - V_370 ;
if ( V_366 ) {
V_245 -> V_59 = V_68 ;
V_245 -> V_53 = F_214 ( V_366 ) ;
} else {
V_245 -> V_59 = F_213 ( V_367 ) ;
F_215 ( & V_245 -> V_4 , V_368 , sizeof( V_245 -> V_4 ) ) ;
V_245 -> V_43 = F_216 ( V_365 ) ;
V_245 -> V_53 = 0 ;
}
F_55 () ;
if ( V_245 -> V_53 )
V_55 = F_39 ( V_2 , V_245 -> V_40 , V_245 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_245 -> V_40 , V_245 -> V_59 ,
& V_245 -> V_4 , V_245 -> V_43 ) ;
F_56 () ;
* V_361 = V_55 ;
if ( V_360 ) {
struct V_321 * V_371 , * V_372 , * V_373 , * V_374 ,
* V_375 ;
struct V_336 V_12 ;
V_371 = V_362 [ V_344 ] ;
V_373 = V_362 [ V_345 ] ;
V_372 = V_362 [ V_346 ] ;
V_374 = V_362 [ V_347 ] ;
V_375 = V_362 [ V_348 ] ;
if ( ! ( V_371 && V_372 && V_374 && V_375 ) )
return - V_134 ;
F_215 ( & V_12 , V_372 , sizeof( V_12 ) ) ;
if ( V_55 )
V_245 -> V_12 = V_55 -> V_12 ;
V_245 -> V_12 = ( V_245 -> V_12 & ~ V_12 . V_337 ) |
( V_12 . V_12 & V_12 . V_337 ) ;
V_245 -> V_161 = F_217 ( V_371 ) ;
V_245 -> V_163 = V_373 ? F_217 ( V_373 ) : NULL ;
V_245 -> V_167 = F_214 ( V_374 ) ;
V_245 -> V_166 = F_218 ( V_375 ) ;
}
return 0 ;
}
static struct V_54 * F_219 ( struct V_2 * V_2 ,
struct V_321 * V_359 )
{
struct V_156 V_245 ;
struct V_54 * V_55 ;
int V_144 ;
V_144 = F_211 ( V_2 , & V_245 , V_359 , 0 , & V_55 ) ;
return V_144 ? F_220 ( V_144 ) : V_55 ;
}
static int F_221 ( struct V_318 * V_319 , struct V_74 * V_75 )
{
struct V_321 * V_376 ;
V_376 = F_193 ( V_319 , V_377 ) ;
if ( ! V_376 )
return - V_323 ;
if ( F_200 ( V_319 , V_378 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_201 ( V_319 , V_379 , V_75 -> V_43 ) ||
F_194 ( V_319 , V_380 ,
( F_15 ( & V_75 -> V_113 ) &
V_85 ) ) ||
F_194 ( V_319 , V_381 ,
F_15 ( & V_75 -> V_114 ) ) ||
F_194 ( V_319 , V_382 , V_75 -> V_119 ) ||
F_194 ( V_319 , V_383 , V_75 -> V_121 ) ||
F_194 ( V_319 , V_384 ,
F_15 ( & V_75 -> V_141 ) ) ||
F_194 ( V_319 , V_385 ,
F_15 ( & V_75 -> V_142 ) ) ||
F_194 ( V_319 , V_386 ,
F_15 ( & V_75 -> V_143 ) ) )
goto V_334;
if ( F_192 ( V_319 , V_387 , & V_75 -> V_76 ) )
goto V_334;
F_196 ( V_319 , V_376 ) ;
return 0 ;
V_334:
F_197 ( V_319 , V_376 ) ;
return - V_323 ;
}
static int F_222 ( struct V_318 * V_319 , struct V_74 * V_75 ,
struct V_350 * V_351 )
{
void * V_352 ;
V_352 = F_205 ( V_319 , F_206 ( V_351 -> V_319 ) . V_353 , V_351 -> V_354 -> V_355 ,
& V_356 , V_357 ,
V_388 ) ;
if ( ! V_352 )
return - V_323 ;
if ( F_221 ( V_319 , V_75 ) < 0 )
goto V_334;
return F_207 ( V_319 , V_352 ) ;
V_334:
F_208 ( V_319 , V_352 ) ;
return - V_323 ;
}
static int F_223 ( struct V_318 * V_319 ,
struct V_350 * V_351 )
{
int V_175 = 0 ;
int V_229 = V_351 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_321 * V_362 [ V_389 + 1 ] ;
struct V_2 * V_2 = F_210 ( V_319 ) ;
F_129 ( & V_179 ) ;
if ( F_224 ( V_351 -> V_354 , V_390 , V_362 ,
V_389 , V_391 ) )
goto V_162;
V_55 = F_219 ( V_2 , V_362 [ V_338 ] ) ;
if ( F_225 ( V_55 ) || V_55 == NULL )
goto V_162;
F_67 (dest, &svc->destinations, n_list) {
if ( ++ V_175 <= V_229 )
continue;
if ( F_222 ( V_319 , V_75 , V_351 ) < 0 ) {
V_175 -- ;
goto V_334;
}
}
V_334:
V_351 -> args [ 0 ] = V_175 ;
V_162:
F_130 ( & V_179 ) ;
return V_319 -> V_254 ;
}
static int F_226 ( struct V_108 * V_109 ,
struct V_321 * V_359 , int V_360 )
{
struct V_321 * V_362 [ V_392 + 1 ] ;
struct V_321 * V_368 , * V_365 ;
if ( V_359 == NULL ||
F_212 ( V_362 , V_392 , V_359 , V_393 ) )
return - V_134 ;
V_368 = V_362 [ V_378 ] ;
V_365 = V_362 [ V_379 ] ;
if ( ! ( V_368 && V_365 ) )
return - V_134 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
F_215 ( & V_109 -> V_4 , V_368 , sizeof( V_109 -> V_4 ) ) ;
V_109 -> V_43 = F_216 ( V_365 ) ;
if ( V_360 ) {
struct V_321 * V_394 , * V_395 , * V_396 ,
* V_397 ;
V_394 = V_362 [ V_380 ] ;
V_395 = V_362 [ V_381 ] ;
V_396 = V_362 [ V_382 ] ;
V_397 = V_362 [ V_383 ] ;
if ( ! ( V_394 && V_395 && V_396 && V_397 ) )
return - V_134 ;
V_109 -> V_113 = F_214 ( V_394 )
& V_85 ;
V_109 -> V_114 = F_214 ( V_395 ) ;
V_109 -> V_119 = F_214 ( V_396 ) ;
V_109 -> V_121 = F_214 ( V_397 ) ;
}
return 0 ;
}
static int F_227 ( struct V_318 * V_319 , T_3 V_95 ,
const char * V_271 , T_3 V_272 )
{
struct V_321 * V_398 ;
V_398 = F_193 ( V_319 , V_399 ) ;
if ( ! V_398 )
return - V_323 ;
if ( F_194 ( V_319 , V_400 , V_95 ) ||
F_202 ( V_319 , V_401 , V_271 ) ||
F_194 ( V_319 , V_402 , V_272 ) )
goto V_334;
F_196 ( V_319 , V_398 ) ;
return 0 ;
V_334:
F_197 ( V_319 , V_398 ) ;
return - V_323 ;
}
static int F_228 ( struct V_318 * V_319 , T_3 V_95 ,
const char * V_271 , T_3 V_272 ,
struct V_350 * V_351 )
{
void * V_352 ;
V_352 = F_205 ( V_319 , F_206 ( V_351 -> V_319 ) . V_353 , V_351 -> V_354 -> V_355 ,
& V_356 , V_357 ,
V_403 ) ;
if ( ! V_352 )
return - V_323 ;
if ( F_227 ( V_319 , V_95 , V_271 , V_272 ) )
goto V_334;
return F_207 ( V_319 , V_352 ) ;
V_334:
F_208 ( V_319 , V_352 ) ;
return - V_323 ;
}
static int F_229 ( struct V_318 * V_319 ,
struct V_350 * V_351 )
{
struct V_2 * V_2 = F_210 ( V_319 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_129 ( & V_15 -> V_268 ) ;
if ( ( V_15 -> V_299 & V_300 ) && ! V_351 -> args [ 0 ] ) {
if ( F_228 ( V_319 , V_300 ,
V_15 -> V_301 ,
V_15 -> V_302 , V_351 ) < 0 )
goto V_334;
V_351 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_299 & V_303 ) && ! V_351 -> args [ 1 ] ) {
if ( F_228 ( V_319 , V_303 ,
V_15 -> V_304 ,
V_15 -> V_305 , V_351 ) < 0 )
goto V_334;
V_351 -> args [ 1 ] = 1 ;
}
V_334:
F_130 ( & V_15 -> V_268 ) ;
return V_319 -> V_254 ;
}
static int F_230 ( struct V_2 * V_2 , struct V_321 * * V_362 )
{
if ( ! ( V_362 [ V_400 ] &&
V_362 [ V_401 ] &&
V_362 [ V_402 ] ) )
return - V_134 ;
return F_181 ( V_2 ,
F_214 ( V_362 [ V_400 ] ) ,
F_217 ( V_362 [ V_401 ] ) ,
F_214 ( V_362 [ V_402 ] ) ) ;
}
static int F_231 ( struct V_2 * V_2 , struct V_321 * * V_362 )
{
if ( ! V_362 [ V_400 ] )
return - V_134 ;
return F_182 ( V_2 ,
F_214 ( V_362 [ V_400 ] ) ) ;
}
static int F_232 ( struct V_2 * V_2 , struct V_321 * * V_362 )
{
struct V_232 V_317 ;
F_188 ( V_2 , & V_317 ) ;
if ( V_362 [ V_404 ] )
V_317 . V_237 = F_214 ( V_362 [ V_404 ] ) ;
if ( V_362 [ V_405 ] )
V_317 . V_238 =
F_214 ( V_362 [ V_405 ] ) ;
if ( V_362 [ V_406 ] )
V_317 . V_239 = F_214 ( V_362 [ V_406 ] ) ;
return F_170 ( V_2 , & V_317 ) ;
}
static int F_233 ( struct V_318 * V_319 , struct V_407 * V_310 )
{
int V_144 = 0 , V_252 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_210 ( V_319 ) ;
V_15 = F_41 ( V_2 ) ;
V_252 = V_310 -> V_408 -> V_252 ;
if ( V_252 == V_403 || V_252 == V_409 ) {
struct V_321 * V_410 [ V_411 + 1 ] ;
F_129 ( & V_15 -> V_268 ) ;
if ( ! V_310 -> V_362 [ V_399 ] ||
F_212 ( V_410 , V_411 ,
V_310 -> V_362 [ V_399 ] ,
V_412 ) ) {
V_144 = - V_134 ;
goto V_67;
}
if ( V_252 == V_403 )
V_144 = F_230 ( V_2 , V_410 ) ;
else
V_144 = F_231 ( V_2 , V_410 ) ;
V_67:
F_130 ( & V_15 -> V_268 ) ;
}
return V_144 ;
}
static int F_234 ( struct V_318 * V_319 , struct V_407 * V_310 )
{
struct V_54 * V_55 = NULL ;
struct V_156 V_245 ;
struct V_108 V_109 ;
int V_144 = 0 , V_252 ;
int V_413 = 0 , V_414 = 0 ;
struct V_2 * V_2 ;
V_2 = F_210 ( V_319 ) ;
V_252 = V_310 -> V_408 -> V_252 ;
F_129 ( & V_179 ) ;
if ( V_252 == V_415 ) {
V_144 = F_126 ( V_2 , false ) ;
goto V_67;
} else if ( V_252 == V_416 ) {
V_144 = F_232 ( V_2 , V_310 -> V_362 ) ;
goto V_67;
} else if ( V_252 == V_417 &&
! V_310 -> V_362 [ V_338 ] ) {
V_144 = F_137 ( V_2 ) ;
goto V_67;
}
if ( V_252 == V_358 || V_252 == V_418 )
V_413 = 1 ;
V_144 = F_211 ( V_2 , & V_245 ,
V_310 -> V_362 [ V_338 ] ,
V_413 , & V_55 ) ;
if ( V_144 )
goto V_67;
if ( ( V_252 != V_358 ) && ( V_55 == NULL ) ) {
V_144 = - V_279 ;
goto V_67;
}
if ( V_252 == V_388 || V_252 == V_419 ||
V_252 == V_420 ) {
if ( V_252 != V_420 )
V_414 = 1 ;
V_144 = F_226 ( & V_109 ,
V_310 -> V_362 [ V_377 ] ,
V_414 ) ;
if ( V_144 )
goto V_67;
}
switch ( V_252 ) {
case V_358 :
if ( V_55 == NULL )
V_144 = F_111 ( V_2 , & V_245 , & V_55 ) ;
else
V_144 = - V_146 ;
break;
case V_418 :
V_144 = F_120 ( V_55 , & V_245 ) ;
break;
case V_421 :
V_144 = F_125 ( V_55 ) ;
break;
case V_388 :
V_144 = F_95 ( V_55 , & V_109 ) ;
break;
case V_419 :
V_144 = F_97 ( V_55 , & V_109 ) ;
break;
case V_420 :
V_144 = F_109 ( V_55 , & V_109 ) ;
break;
case V_417 :
V_144 = F_136 ( V_55 ) ;
break;
default:
V_144 = - V_134 ;
}
V_67:
F_130 ( & V_179 ) ;
return V_144 ;
}
static int F_235 ( struct V_318 * V_319 , struct V_407 * V_310 )
{
struct V_318 * V_422 ;
void * V_423 ;
int V_144 , V_252 , V_424 ;
struct V_2 * V_2 ;
V_2 = F_210 ( V_319 ) ;
V_252 = V_310 -> V_408 -> V_252 ;
if ( V_252 == V_425 )
V_424 = V_358 ;
else if ( V_252 == V_426 )
V_424 = V_427 ;
else if ( V_252 == V_428 )
V_424 = V_416 ;
else {
F_28 ( L_59 ) ;
return - V_134 ;
}
V_422 = F_236 ( V_429 , V_137 ) ;
if ( ! V_422 )
return - V_138 ;
F_129 ( & V_179 ) ;
V_423 = F_237 ( V_422 , V_310 , & V_356 , 0 , V_424 ) ;
if ( V_423 == NULL )
goto V_334;
switch ( V_252 ) {
case V_425 :
{
struct V_54 * V_55 ;
V_55 = F_219 ( V_2 ,
V_310 -> V_362 [ V_338 ] ) ;
if ( F_225 ( V_55 ) ) {
V_144 = F_238 ( V_55 ) ;
goto V_162;
} else if ( V_55 ) {
V_144 = F_198 ( V_422 , V_55 ) ;
if ( V_144 )
goto V_334;
} else {
V_144 = - V_279 ;
goto V_162;
}
break;
}
case V_428 :
{
struct V_232 V_317 ;
F_188 ( V_2 , & V_317 ) ;
#ifdef V_233
if ( F_194 ( V_422 , V_404 ,
V_317 . V_237 ) ||
F_194 ( V_422 , V_405 ,
V_317 . V_238 ) )
goto V_334;
#endif
#ifdef V_234
if ( F_194 ( V_422 , V_406 , V_317 . V_239 ) )
goto V_334;
#endif
break;
}
case V_426 :
if ( F_194 ( V_422 , V_430 ,
V_215 ) ||
F_194 ( V_422 , V_431 ,
V_216 ) )
goto V_334;
break;
}
F_207 ( V_422 , V_423 ) ;
V_144 = F_239 ( V_422 , V_310 ) ;
goto V_67;
V_334:
F_28 ( L_60 ) ;
V_144 = - V_323 ;
V_162:
F_240 ( V_422 ) ;
V_67:
F_130 ( & V_179 ) ;
return V_144 ;
}
static int T_11 F_241 ( void )
{
return F_242 ( & V_356 ,
V_432 , F_243 ( V_432 ) ) ;
}
static void F_244 ( void )
{
F_245 ( & V_356 ) ;
}
static int T_12 F_246 ( struct V_2 * V_2 )
{
int V_175 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_189 * V_433 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_93 ( & V_15 -> V_25 ) ;
F_93 ( & V_15 -> V_28 ) ;
F_93 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_434 ) ) {
V_433 = F_247 ( V_435 , sizeof( V_435 ) , V_137 ) ;
if ( V_433 == NULL )
return - V_138 ;
if ( V_2 -> V_257 != & V_436 )
V_433 [ 0 ] . V_437 = NULL ;
} else
V_433 = V_435 ;
V_175 = 0 ;
V_15 -> V_24 = 1024 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_32 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_26 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_29 ;
#ifdef F_248
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_438 ;
#endif
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_34 ;
V_15 -> V_439 = 1 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_439 ;
V_15 -> V_440 = 1 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_440 ;
V_15 -> V_441 = 1 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_441 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_442 ;
V_15 -> V_443 = F_249 () / 32 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_443 ;
V_15 -> V_444 = 0 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_444 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_445 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_446 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_447 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_448 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_449 ;
V_15 -> V_450 [ 0 ] = V_451 ;
V_15 -> V_450 [ 1 ] = V_452 ;
V_433 [ V_175 ] . V_154 = & V_15 -> V_450 ;
V_433 [ V_175 ++ ] . V_453 = sizeof( V_15 -> V_450 ) ;
V_15 -> V_454 = V_455 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_454 ;
V_15 -> V_456 = F_250 ( int , V_457 , 0 , 3 ) ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_456 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_458 ;
V_15 -> V_459 = 1 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_459 ;
V_433 [ V_175 ++ ] . V_154 = & V_15 -> V_460 ;
V_15 -> V_461 = F_251 ( V_2 , L_61 , V_433 ) ;
if ( V_15 -> V_461 == NULL ) {
if ( ! F_38 ( V_2 , & V_434 ) )
F_48 ( V_433 ) ;
return - V_138 ;
}
F_83 ( V_2 , & V_15 -> V_188 ) ;
V_15 -> V_462 = V_433 ;
F_252 ( & V_15 -> V_37 , F_13 ) ;
F_17 ( & V_15 -> V_37 , V_38 ) ;
return 0 ;
}
static void T_13 F_253 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_254 ( & V_15 -> V_37 ) ;
F_255 ( & V_15 -> V_37 . V_36 ) ;
F_256 ( V_15 -> V_461 ) ;
}
static int T_12 F_246 ( struct V_2 * V_2 ) { return 0 ; }
static void T_13 F_253 ( struct V_2 * V_2 ) { }
int T_12 F_257 ( struct V_2 * V_2 )
{
int V_175 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
for ( V_175 = 0 ; V_175 < V_463 ; V_175 ++ )
F_258 ( & V_15 -> V_82 [ V_175 ] ) ;
F_115 ( & V_15 -> V_149 ) ;
F_93 ( & V_15 -> V_93 ) ;
F_259 ( & V_15 -> V_98 , F_110 ,
( unsigned long ) V_2 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_188 . V_77 = F_90 ( struct V_139 ) ;
if ( ! V_15 -> V_188 . V_77 )
return - V_138 ;
F_93 ( & V_15 -> V_188 . V_102 ) ;
F_260 ( L_62 , 0 , V_2 -> V_464 , & V_465 ) ;
F_260 ( L_63 , 0 , V_2 -> V_464 , & V_466 ) ;
F_260 ( L_64 , 0 , V_2 -> V_464 ,
& V_467 ) ;
if ( F_246 ( V_2 ) )
goto V_468;
return 0 ;
V_468:
F_47 ( V_15 -> V_188 . V_77 ) ;
return - V_138 ;
}
void T_13 F_261 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_262 () ;
F_73 ( V_2 ) ;
F_101 ( V_2 , & V_15 -> V_188 ) ;
F_253 ( V_2 ) ;
F_263 ( L_64 , V_2 -> V_464 ) ;
F_263 ( L_63 , V_2 -> V_464 ) ;
F_263 ( L_62 , V_2 -> V_464 ) ;
F_47 ( V_15 -> V_188 . V_77 ) ;
}
int T_11 F_264 ( void )
{
int V_144 ;
V_144 = F_265 ( & V_469 ) ;
if ( V_144 ) {
F_28 ( L_65 ) ;
goto V_470;
}
V_144 = F_241 () ;
if ( V_144 ) {
F_28 ( L_66 ) ;
goto V_471;
}
return 0 ;
V_471:
F_266 ( & V_469 ) ;
V_470:
return V_144 ;
}
void F_267 ( void )
{
F_244 () ;
F_266 ( & V_469 ) ;
}
int T_11 F_268 ( void )
{
int V_175 ;
int V_144 ;
F_86 ( 2 ) ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
F_258 ( & V_61 [ V_175 ] ) ;
F_258 ( & V_63 [ V_175 ] ) ;
}
F_269 () ;
V_144 = F_270 ( & V_472 ) ;
if ( V_144 < 0 )
return V_144 ;
F_94 ( 2 ) ;
return 0 ;
}
void F_271 ( void )
{
F_86 ( 2 ) ;
F_272 ( & V_472 ) ;
F_94 ( 2 ) ;
}
