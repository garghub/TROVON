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
F_49 ( V_75 ) ;
}
static void F_74 ( struct V_2 * V_2 )
{
struct V_74 * V_75 , * V_96 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_75 ( & V_15 -> V_97 ) ;
F_76 (dest, nxt, &ipvs->dest_trash, t_list) {
F_70 ( & V_75 -> V_95 ) ;
F_73 ( V_75 ) ;
}
}
static void
F_77 ( struct V_98 * V_9 , struct V_99 * V_100 )
{
#define F_78 ( T_5 ) dst->c = src->ustats.c - src->ustats0.c
F_68 ( & V_100 -> V_101 ) ;
F_78 ( V_102 ) ;
F_78 ( V_103 ) ;
F_78 ( V_104 ) ;
F_78 ( V_105 ) ;
F_78 ( V_106 ) ;
F_79 ( V_9 , V_100 ) ;
F_72 ( & V_100 -> V_101 ) ;
}
static void
F_80 ( struct V_99 * V_76 )
{
F_68 ( & V_76 -> V_101 ) ;
#define F_81 ( T_5 ) stats->ustats0.c = stats->ustats.c
F_81 ( V_102 ) ;
F_81 ( V_103 ) ;
F_81 ( V_104 ) ;
F_81 ( V_105 ) ;
F_81 ( V_106 ) ;
F_82 ( V_76 ) ;
F_72 ( & V_76 -> V_101 ) ;
}
static void
F_83 ( struct V_54 * V_55 , struct V_74 * V_75 ,
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
F_80 ( & V_75 -> V_76 ) ;
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
F_84 ( V_55 -> V_2 , & V_75 -> V_76 ) ;
F_85 ( & V_75 -> V_124 , & V_55 -> V_125 ) ;
V_55 -> V_126 ++ ;
if ( V_112 -> V_127 )
V_112 -> V_127 ( V_55 , V_75 ) ;
} else {
if ( V_112 -> V_128 )
V_112 -> V_128 ( V_55 , V_75 ) ;
}
}
static int
F_86 ( struct V_54 * V_55 , struct V_107 * V_108 ,
struct V_74 * * V_129 )
{
struct V_74 * V_75 ;
unsigned int V_130 ;
F_87 ( 2 ) ;
#ifdef F_24
if ( V_55 -> V_40 == V_48 ) {
V_130 = F_88 ( & V_108 -> V_4 . V_131 ) ;
if ( ( ! ( V_130 & V_132 ) ||
V_130 & V_133 ) &&
! F_2 ( V_55 -> V_2 , & V_108 -> V_4 . V_131 ) )
return - V_134 ;
} else
#endif
{
V_130 = F_89 ( V_55 -> V_2 , V_108 -> V_4 . V_46 ) ;
if ( V_130 != V_135 && V_130 != V_136 )
return - V_134 ;
}
V_75 = F_90 ( sizeof( struct V_74 ) , V_137 ) ;
if ( V_75 == NULL )
return - V_138 ;
V_75 -> V_76 . V_77 = F_91 ( struct V_139 ) ;
if ( ! V_75 -> V_76 . V_77 )
goto V_140;
V_75 -> V_40 = V_55 -> V_40 ;
V_75 -> V_59 = V_55 -> V_59 ;
V_75 -> V_65 = V_55 -> V_4 ;
V_75 -> V_66 = V_55 -> V_43 ;
V_75 -> V_87 = V_55 -> V_53 ;
F_92 ( V_55 -> V_40 , & V_75 -> V_4 , & V_108 -> V_4 ) ;
V_75 -> V_43 = V_108 -> V_43 ;
F_9 ( & V_75 -> V_141 , 0 ) ;
F_9 ( & V_75 -> V_142 , 0 ) ;
F_9 ( & V_75 -> V_143 , 0 ) ;
F_9 ( & V_75 -> V_64 , 1 ) ;
F_93 ( & V_75 -> V_84 ) ;
F_94 ( & V_75 -> V_122 ) ;
F_94 ( & V_75 -> V_76 . V_101 ) ;
F_83 ( V_55 , V_75 , V_108 , 1 ) ;
* V_129 = V_75 ;
F_95 ( 2 ) ;
return 0 ;
V_140:
F_49 ( V_75 ) ;
return - V_138 ;
}
static int
F_96 ( struct V_54 * V_55 , struct V_107 * V_108 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_108 -> V_43 ;
int V_144 ;
F_87 ( 2 ) ;
if ( V_108 -> V_114 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_145 ;
}
if ( V_108 -> V_121 > V_108 -> V_119 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_145 ;
}
F_92 ( V_55 -> V_40 , & V_7 , & V_108 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 != NULL ) {
F_97 ( 1 , L_11 , V_58 ) ;
return - V_146 ;
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
F_83 ( V_55 , V_75 , V_108 , 1 ) ;
V_144 = 0 ;
} else {
V_144 = F_86 ( V_55 , V_108 , & V_75 ) ;
}
F_95 ( 2 ) ;
return V_144 ;
}
static int
F_98 ( struct V_54 * V_55 , struct V_107 * V_108 )
{
struct V_74 * V_75 ;
union V_42 V_7 ;
T_1 V_86 = V_108 -> V_43 ;
F_87 ( 2 ) ;
if ( V_108 -> V_114 < 0 ) {
F_28 ( L_9 , V_58 ) ;
return - V_145 ;
}
if ( V_108 -> V_121 > V_108 -> V_119 ) {
F_28 ( L_10 ,
V_58 ) ;
return - V_145 ;
}
F_92 ( V_55 -> V_40 , & V_7 , & V_108 -> V_4 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , & V_7 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_97 ( 1 , L_14 , V_58 ) ;
return - V_147 ;
}
F_83 ( V_55 , V_75 , V_108 , 0 ) ;
F_95 ( 2 ) ;
return 0 ;
}
static void F_99 ( struct V_2 * V_2 , struct V_74 * V_75 ,
bool V_148 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_100 ( V_2 , & V_75 -> V_76 ) ;
F_56 ( V_75 ) ;
F_68 ( & V_15 -> V_94 ) ;
F_42 ( 3 , L_15 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) , F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
if ( F_101 ( & V_15 -> V_149 ) && ! V_148 )
F_102 ( & V_15 -> V_97 ,
V_150 + ( V_151 >> 1 ) ) ;
F_103 ( & V_75 -> V_95 , & V_15 -> V_149 ) ;
V_75 -> V_152 = 0 ;
F_72 ( & V_15 -> V_94 ) ;
F_104 ( V_75 ) ;
}
static void F_105 ( struct V_54 * V_55 ,
struct V_74 * V_75 ,
int V_153 )
{
V_75 -> V_12 &= ~ V_118 ;
F_106 ( & V_75 -> V_124 ) ;
V_55 -> V_126 -- ;
if ( V_153 ) {
struct V_111 * V_112 ;
V_112 = F_65 ( V_55 -> V_123 , 1 ) ;
if ( V_112 -> V_154 )
V_112 -> V_154 ( V_55 , V_75 ) ;
}
}
static int
F_107 ( struct V_54 * V_55 , struct V_107 * V_108 )
{
struct V_74 * V_75 ;
T_1 V_86 = V_108 -> V_43 ;
F_87 ( 2 ) ;
F_58 () ;
V_75 = F_60 ( V_55 , & V_108 -> V_4 , V_86 ) ;
F_59 () ;
if ( V_75 == NULL ) {
F_97 ( 1 , L_16 , V_58 ) ;
return - V_147 ;
}
F_105 ( V_55 , V_75 , 1 ) ;
F_99 ( V_55 -> V_2 , V_75 , false ) ;
F_95 ( 2 ) ;
return 0 ;
}
static void F_108 ( unsigned long V_155 )
{
struct V_2 * V_2 = (struct V_2 * ) V_155 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_74 * V_75 , * V_156 ;
unsigned long V_157 = V_150 ;
F_8 ( & V_15 -> V_94 ) ;
F_76 (dest, next, &ipvs->dest_trash, t_list) {
if ( F_15 ( & V_75 -> V_64 ) > 0 )
continue;
if ( V_75 -> V_152 ) {
if ( F_109 ( V_157 , V_75 -> V_152 +
V_151 ) )
continue;
} else {
V_75 -> V_152 = F_110 ( 1UL , V_157 ) ;
continue;
}
F_42 ( 3 , L_17 ,
V_75 -> V_87 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ) ;
F_70 ( & V_75 -> V_95 ) ;
F_73 ( V_75 ) ;
}
if ( ! F_101 ( & V_15 -> V_149 ) )
F_102 ( & V_15 -> V_97 ,
V_150 + ( V_151 >> 1 ) ) ;
F_10 ( & V_15 -> V_94 ) ;
}
static int
F_111 ( struct V_2 * V_2 , struct V_158 * V_159 ,
struct V_54 * * V_160 )
{
int V_144 = 0 ;
struct V_111 * V_112 = NULL ;
struct V_161 * V_162 = NULL ;
struct V_54 * V_55 = NULL ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_18 () ;
V_112 = F_112 ( V_159 -> V_163 ) ;
if ( V_112 == NULL ) {
F_113 ( L_18 , V_159 -> V_163 ) ;
V_144 = - V_147 ;
goto V_164;
}
if ( V_159 -> V_165 && * V_159 -> V_165 ) {
V_162 = F_114 ( V_159 -> V_165 ) ;
if ( V_162 == NULL ) {
F_113 ( L_19
L_20 , V_159 -> V_165 ) ;
V_144 = - V_147 ;
goto V_164;
}
}
#ifdef F_24
if ( V_159 -> V_40 == V_48 ) {
T_3 V_166 = ( V_167 T_3 ) V_159 -> V_168 ;
if ( V_166 < 1 || V_166 > 128 ) {
V_144 = - V_134 ;
goto V_164;
}
}
#endif
V_55 = F_90 ( sizeof( struct V_54 ) , V_137 ) ;
if ( V_55 == NULL ) {
F_97 ( 1 , L_21 , V_58 ) ;
V_144 = - V_138 ;
goto V_164;
}
V_55 -> V_76 . V_77 = F_91 ( struct V_139 ) ;
if ( ! V_55 -> V_76 . V_77 ) {
V_144 = - V_138 ;
goto V_164;
}
F_9 ( & V_55 -> V_64 , 0 ) ;
V_55 -> V_40 = V_159 -> V_40 ;
V_55 -> V_59 = V_159 -> V_59 ;
F_92 ( V_55 -> V_40 , & V_55 -> V_4 , & V_159 -> V_4 ) ;
V_55 -> V_43 = V_159 -> V_43 ;
V_55 -> V_53 = V_159 -> V_53 ;
V_55 -> V_12 = V_159 -> V_12 ;
V_55 -> V_169 = V_159 -> V_169 * V_170 ;
V_55 -> V_168 = V_159 -> V_168 ;
V_55 -> V_2 = V_2 ;
F_115 ( & V_55 -> V_125 ) ;
F_94 ( & V_55 -> V_171 ) ;
F_94 ( & V_55 -> V_76 . V_101 ) ;
V_144 = F_116 ( V_55 , V_112 ) ;
if ( V_144 )
goto V_164;
V_112 = NULL ;
F_66 ( V_55 -> V_162 , V_162 ) ;
V_162 = NULL ;
if ( V_55 -> V_43 == V_72 )
F_31 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_31 ( & V_15 -> V_73 ) ;
F_84 ( V_2 , & V_55 -> V_76 ) ;
if ( V_55 -> V_40 == V_172 )
V_15 -> V_173 ++ ;
F_27 ( V_55 ) ;
* V_160 = V_55 ;
V_15 -> V_174 = 1 ;
return 0 ;
V_164:
if ( V_55 != NULL ) {
F_117 ( V_55 , V_112 ) ;
F_47 ( V_55 ) ;
}
F_118 ( V_112 ) ;
F_119 ( V_162 ) ;
F_20 () ;
return V_144 ;
}
static int
F_120 ( struct V_54 * V_55 , struct V_158 * V_159 )
{
struct V_111 * V_112 , * V_175 ;
struct V_161 * V_162 = NULL , * V_176 = NULL ;
int V_144 = 0 ;
V_112 = F_112 ( V_159 -> V_163 ) ;
if ( V_112 == NULL ) {
F_113 ( L_18 , V_159 -> V_163 ) ;
return - V_147 ;
}
V_175 = V_112 ;
if ( V_159 -> V_165 && * V_159 -> V_165 ) {
V_162 = F_114 ( V_159 -> V_165 ) ;
if ( V_162 == NULL ) {
F_113 ( L_19
L_20 , V_159 -> V_165 ) ;
V_144 = - V_147 ;
goto V_67;
}
V_176 = V_162 ;
}
#ifdef F_24
if ( V_159 -> V_40 == V_48 ) {
T_3 V_166 = ( V_167 T_3 ) V_159 -> V_168 ;
if ( V_166 < 1 || V_166 > 128 ) {
V_144 = - V_134 ;
goto V_67;
}
}
#endif
V_175 = F_65 ( V_55 -> V_123 , 1 ) ;
if ( V_112 != V_175 ) {
V_144 = F_116 ( V_55 , V_112 ) ;
if ( V_144 ) {
V_175 = V_112 ;
goto V_67;
}
F_117 ( V_55 , V_175 ) ;
}
V_55 -> V_12 = V_159 -> V_12 | V_57 ;
V_55 -> V_169 = V_159 -> V_169 * V_170 ;
V_55 -> V_168 = V_159 -> V_168 ;
V_176 = F_65 ( V_55 -> V_162 , 1 ) ;
if ( V_162 != V_176 )
F_46 ( V_55 -> V_162 , V_162 ) ;
V_67:
F_118 ( V_175 ) ;
F_119 ( V_176 ) ;
return V_144 ;
}
static void F_121 ( struct V_54 * V_55 , bool V_148 )
{
struct V_74 * V_75 , * V_96 ;
struct V_111 * V_175 ;
struct V_161 * V_176 ;
struct V_14 * V_15 = F_41 ( V_55 -> V_2 ) ;
F_113 ( L_22 , V_58 ) ;
if ( V_55 -> V_40 == V_172 )
V_15 -> V_173 -- ;
F_100 ( V_55 -> V_2 , & V_55 -> V_76 ) ;
V_175 = F_65 ( V_55 -> V_123 , 1 ) ;
F_117 ( V_55 , V_175 ) ;
F_118 ( V_175 ) ;
V_176 = F_65 ( V_55 -> V_162 , 1 ) ;
F_119 ( V_176 ) ;
F_76 (dest, nxt, &svc->destinations, n_list) {
F_105 ( V_55 , V_75 , 0 ) ;
F_99 ( V_55 -> V_2 , V_75 , V_148 ) ;
}
if ( V_55 -> V_43 == V_72 )
F_34 ( & V_15 -> V_69 ) ;
else if ( V_55 -> V_43 == 0 )
F_34 ( & V_15 -> V_73 ) ;
F_51 ( V_55 , true ) ;
F_20 () ;
}
static void F_122 ( struct V_54 * V_55 , bool V_148 )
{
F_31 ( & V_55 -> V_64 ) ;
F_32 ( V_55 ) ;
F_121 ( V_55 , V_148 ) ;
}
static int F_123 ( struct V_54 * V_55 )
{
if ( V_55 == NULL )
return - V_146 ;
F_122 ( V_55 , false ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_2 , bool V_148 )
{
int V_177 ;
struct V_54 * V_55 ;
struct V_178 * V_179 ;
for( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_125 (svc, n, &ip_vs_svc_table[idx],
s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_122 ( V_55 , V_148 ) ;
}
}
for( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_125 (svc, n, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_122 ( V_55 , V_148 ) ;
}
}
return 0 ;
}
void F_126 ( struct V_2 * V_2 )
{
F_87 ( 2 ) ;
F_127 ( & V_181 ) ;
F_124 ( V_2 , true ) ;
F_128 ( & V_181 ) ;
F_95 ( 2 ) ;
}
static inline void
F_129 ( struct V_74 * V_75 , struct V_182 * V_11 )
{
struct V_90 * V_91 ;
F_68 ( & V_75 -> V_122 ) ;
V_91 = F_65 ( V_75 -> V_91 , 1 ) ;
if ( V_91 && V_91 -> V_92 -> V_11 == V_11 ) {
F_42 ( 3 , L_23 ,
V_11 -> V_183 ,
F_44 ( V_75 -> V_40 , & V_75 -> V_4 ) ,
F_23 ( V_75 -> V_43 ) ,
F_15 ( & V_75 -> V_64 ) ) ;
F_64 ( V_75 ) ;
}
F_72 ( & V_75 -> V_122 ) ;
}
static int F_130 ( struct V_184 * V_185 , unsigned long V_186 ,
void * V_187 )
{
struct V_182 * V_11 = F_131 ( V_187 ) ;
struct V_2 * V_2 = F_132 ( V_11 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
unsigned int V_177 ;
if ( V_186 != V_188 || ! V_15 )
return V_189 ;
F_97 ( 3 , L_24 , V_58 , V_11 -> V_183 ) ;
F_87 ( 2 ) ;
F_127 ( & V_181 ) ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_133 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_129 ( V_75 , V_11 ) ;
}
}
}
F_133 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) ) {
F_69 (dest, &svc->destinations,
n_list) {
F_129 ( V_75 , V_11 ) ;
}
}
}
}
F_68 ( & V_15 -> V_94 ) ;
F_69 (dest, &ipvs->dest_trash, t_list) {
F_129 ( V_75 , V_11 ) ;
}
F_72 ( & V_15 -> V_94 ) ;
F_128 ( & V_181 ) ;
F_95 ( 2 ) ;
return V_189 ;
}
static int F_134 ( struct V_54 * V_55 )
{
struct V_74 * V_75 ;
F_69 (dest, &svc->destinations, n_list) {
F_80 ( & V_75 -> V_76 ) ;
}
F_80 ( & V_55 -> V_76 ) ;
return 0 ;
}
static int F_135 ( struct V_2 * V_2 )
{
int V_177 ;
struct V_54 * V_55 ;
for( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_133 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_134 ( V_55 ) ;
}
}
for( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_133 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) )
F_134 ( V_55 ) ;
}
}
F_80 ( & F_41 ( V_2 ) -> V_190 ) ;
return 0 ;
}
static int
F_136 ( struct V_191 * V_192 , int V_193 ,
void T_6 * V_194 , V_50 * V_195 , T_7 * V_196 )
{
struct V_2 * V_2 = V_197 -> V_198 -> V_199 ;
int * V_200 = V_192 -> V_155 ;
int V_201 = * V_200 ;
int V_202 ;
V_202 = F_137 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_193 && ( * V_200 != V_201 ) ) {
if ( ( * V_200 < 0 ) || ( * V_200 > 3 ) ) {
* V_200 = V_201 ;
} else {
F_5 ( F_41 ( V_2 ) ) ;
}
}
return V_202 ;
}
static int
F_138 ( struct V_191 * V_192 , int V_193 ,
void T_6 * V_194 , V_50 * V_195 , T_7 * V_196 )
{
int * V_200 = V_192 -> V_155 ;
int V_201 [ 2 ] ;
int V_202 ;
memcpy ( V_201 , V_200 , sizeof( V_201 ) ) ;
V_202 = F_137 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_193 && ( V_200 [ 0 ] < 0 || V_200 [ 1 ] < 0 ||
( V_200 [ 0 ] >= V_200 [ 1 ] && V_200 [ 1 ] ) ) ) {
memcpy ( V_200 , V_201 , sizeof( V_201 ) ) ;
}
return V_202 ;
}
static int
F_139 ( struct V_191 * V_192 , int V_193 ,
void T_6 * V_194 , V_50 * V_195 , T_7 * V_196 )
{
int * V_200 = V_192 -> V_155 ;
int V_201 = * V_200 ;
int V_202 ;
V_202 = F_137 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_193 && ( * V_200 != V_201 ) ) {
if ( ( * V_200 < 0 ) || ( * V_200 > 1 ) ) {
* V_200 = V_201 ;
}
}
return V_202 ;
}
static int
F_140 ( struct V_191 * V_192 , int V_193 ,
void T_6 * V_194 , V_50 * V_195 , T_7 * V_196 )
{
int * V_200 = V_192 -> V_155 ;
int V_201 = * V_200 ;
int V_202 ;
V_202 = F_137 ( V_192 , V_193 , V_194 , V_195 , V_196 ) ;
if ( V_193 && ( * V_200 != V_201 ) ) {
if ( * V_200 < 1 || ! F_141 ( * V_200 ) ) {
* V_200 = V_201 ;
}
}
return V_202 ;
}
static inline const char * F_142 ( unsigned int V_12 )
{
switch ( V_12 & V_88 ) {
case V_203 :
return L_25 ;
case V_204 :
return L_26 ;
case V_205 :
return L_27 ;
default:
return L_28 ;
}
}
static struct V_54 * F_143 ( struct V_206 * V_207 , T_7 V_208 )
{
struct V_2 * V_2 = F_144 ( V_207 ) ;
struct V_209 * V_210 = V_207 -> V_211 ;
int V_177 ;
struct V_54 * V_55 ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_36 (svc, &ip_vs_svc_table[idx], s_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_208 -- == 0 ) {
V_210 -> V_192 = V_61 ;
V_210 -> V_212 = V_177 ;
return V_55 ;
}
}
}
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_36 (svc, &ip_vs_svc_fwm_table[idx],
f_list) {
if ( F_38 ( V_55 -> V_2 , V_2 ) && V_208 -- == 0 ) {
V_210 -> V_192 = V_63 ;
V_210 -> V_212 = V_177 ;
return V_55 ;
}
}
}
return NULL ;
}
static void * F_145 ( struct V_206 * V_207 , T_7 * V_208 )
__acquires( T_8 )
{
F_58 () ;
return * V_208 ? F_143 ( V_207 , * V_208 - 1 ) : V_213 ;
}
static void * F_146 ( struct V_206 * V_207 , void * V_214 , T_7 * V_208 )
{
struct V_178 * V_215 ;
struct V_209 * V_210 ;
struct V_54 * V_55 ;
++ * V_208 ;
if ( V_214 == V_213 )
return F_143 ( V_207 , 0 ) ;
V_55 = V_214 ;
V_210 = V_207 -> V_211 ;
if ( V_210 -> V_192 == V_61 ) {
V_215 = F_147 ( F_148 ( & V_55 -> V_60 ) ) ;
if ( V_215 )
return F_149 ( V_215 , struct V_54 , V_60 ) ;
while ( ++ V_210 -> V_212 < V_180 ) {
F_36 (svc,
&ip_vs_svc_table[iter->bucket],
s_list) {
return V_55 ;
}
}
V_210 -> V_192 = V_63 ;
V_210 -> V_212 = - 1 ;
goto V_216;
}
V_215 = F_147 ( F_148 ( & V_55 -> V_62 ) ) ;
if ( V_215 )
return F_149 ( V_215 , struct V_54 , V_62 ) ;
V_216:
while ( ++ V_210 -> V_212 < V_180 ) {
F_36 (svc,
&ip_vs_svc_fwm_table[iter->bucket],
f_list)
return V_55 ;
}
return NULL ;
}
static void F_150 ( struct V_206 * V_207 , void * V_214 )
__releases( T_8 )
{
F_59 () ;
}
static int F_151 ( struct V_206 * V_207 , void * V_214 )
{
if ( V_214 == V_213 ) {
F_152 ( V_207 ,
L_29 ,
F_153 ( V_217 ) , V_218 ) ;
F_154 ( V_207 ,
L_30 ) ;
F_154 ( V_207 ,
L_31 ) ;
} else {
const struct V_54 * V_55 = V_214 ;
const struct V_209 * V_210 = V_207 -> V_211 ;
const struct V_74 * V_75 ;
struct V_111 * V_112 = F_147 ( V_55 -> V_123 ) ;
if ( V_210 -> V_192 == V_61 ) {
#ifdef F_24
if ( V_55 -> V_40 == V_48 )
F_152 ( V_207 , L_32 ,
F_43 ( V_55 -> V_59 ) ,
& V_55 -> V_4 . V_131 ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_183 ) ;
else
#endif
F_152 ( V_207 , L_33 ,
F_43 ( V_55 -> V_59 ) ,
F_25 ( V_55 -> V_4 . V_46 ) ,
F_23 ( V_55 -> V_43 ) ,
V_112 -> V_183 ,
( V_55 -> V_12 & V_219 ) ? L_34 : L_35 ) ;
} else {
F_152 ( V_207 , L_36 ,
V_55 -> V_53 , V_112 -> V_183 ,
( V_55 -> V_12 & V_219 ) ? L_34 : L_35 ) ;
}
if ( V_55 -> V_12 & V_220 )
F_152 ( V_207 , L_37 ,
V_55 -> V_169 ,
F_25 ( V_55 -> V_168 ) ) ;
else
F_155 ( V_207 , '\n' ) ;
F_61 (dest, &svc->destinations, n_list) {
#ifdef F_24
if ( V_75 -> V_40 == V_48 )
F_152 ( V_207 ,
L_38
L_39 ,
& V_75 -> V_4 . V_131 ,
F_23 ( V_75 -> V_43 ) ,
F_142 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_141 ) ,
F_15 ( & V_75 -> V_142 ) ) ;
else
#endif
F_152 ( V_207 ,
L_40
L_41 ,
F_25 ( V_75 -> V_4 . V_46 ) ,
F_23 ( V_75 -> V_43 ) ,
F_142 ( F_15 ( & V_75 -> V_113 ) ) ,
F_15 ( & V_75 -> V_114 ) ,
F_15 ( & V_75 -> V_141 ) ,
F_15 ( & V_75 -> V_142 ) ) ;
}
}
return 0 ;
}
static int F_156 ( struct V_221 * V_221 , struct V_222 * V_222 )
{
return F_157 ( V_221 , V_222 , & V_223 ,
sizeof( struct V_209 ) ) ;
}
static int F_158 ( struct V_206 * V_207 , void * V_214 )
{
struct V_2 * V_2 = F_159 ( V_207 ) ;
struct V_98 V_224 ;
F_154 ( V_207 ,
L_42 ) ;
F_152 ( V_207 ,
L_43 ) ;
F_77 ( & V_224 , & F_41 ( V_2 ) -> V_190 ) ;
F_152 ( V_207 , L_44 , V_224 . V_102 ,
V_224 . V_103 , V_224 . V_104 ,
( unsigned long long ) V_224 . V_105 ,
( unsigned long long ) V_224 . V_106 ) ;
F_154 ( V_207 ,
L_45 ) ;
F_152 ( V_207 , L_46 ,
V_224 . V_225 , V_224 . V_226 , V_224 . V_227 ,
V_224 . V_228 , V_224 . V_229 ) ;
return 0 ;
}
static int F_160 ( struct V_221 * V_221 , struct V_222 * V_222 )
{
return F_161 ( V_221 , V_222 , F_158 ) ;
}
static int F_162 ( struct V_206 * V_207 , void * V_214 )
{
struct V_2 * V_2 = F_159 ( V_207 ) ;
struct V_99 * V_190 = & F_41 ( V_2 ) -> V_190 ;
struct V_139 T_9 * V_77 = V_190 -> V_77 ;
struct V_98 V_230 ;
int V_17 ;
F_154 ( V_207 ,
L_47 ) ;
F_152 ( V_207 ,
L_48 ) ;
F_163 (i) {
struct V_139 * V_159 = F_164 ( V_77 , V_17 ) ;
unsigned int V_231 ;
T_10 V_105 , V_106 ;
do {
V_231 = F_165 ( & V_159 -> V_232 ) ;
V_105 = V_159 -> V_233 . V_105 ;
V_106 = V_159 -> V_233 . V_106 ;
} while ( F_166 ( & V_159 -> V_232 , V_231 ) );
F_152 ( V_207 , L_49 ,
V_17 , V_159 -> V_233 . V_102 , V_159 -> V_233 . V_103 ,
V_159 -> V_233 . V_104 , ( T_10 ) V_105 ,
( T_10 ) V_106 ) ;
}
F_68 ( & V_190 -> V_101 ) ;
F_152 ( V_207 , L_50 ,
V_190 -> V_233 . V_102 , V_190 -> V_233 . V_103 ,
V_190 -> V_233 . V_104 ,
( unsigned long long ) V_190 -> V_233 . V_105 ,
( unsigned long long ) V_190 -> V_233 . V_106 ) ;
F_79 ( & V_230 , V_190 ) ;
F_72 ( & V_190 -> V_101 ) ;
F_154 ( V_207 ,
L_51 ) ;
F_152 ( V_207 , L_52 ,
V_230 . V_225 ,
V_230 . V_226 ,
V_230 . V_227 ,
V_230 . V_228 ,
V_230 . V_229 ) ;
return 0 ;
}
static int F_167 ( struct V_221 * V_221 , struct V_222 * V_222 )
{
return F_161 ( V_221 , V_222 , F_162 ) ;
}
static int F_168 ( struct V_2 * V_2 , struct V_234 * V_159 )
{
#if F_169 ( V_235 ) || F_169 ( V_236 )
struct V_237 * V_238 ;
#endif
F_97 ( 2 , L_53 ,
V_159 -> V_239 ,
V_159 -> V_240 ,
V_159 -> V_241 ) ;
#ifdef V_235
if ( V_159 -> V_239 ) {
V_238 = F_170 ( V_2 , V_68 ) ;
V_238 -> V_242 [ V_243 ]
= V_159 -> V_239 * V_170 ;
}
if ( V_159 -> V_240 ) {
V_238 = F_170 ( V_2 , V_68 ) ;
V_238 -> V_242 [ V_244 ]
= V_159 -> V_240 * V_170 ;
}
#endif
#ifdef V_236
if ( V_159 -> V_241 ) {
V_238 = F_170 ( V_2 , V_245 ) ;
V_238 -> V_242 [ V_246 ]
= V_159 -> V_241 * V_170 ;
}
#endif
return 0 ;
}
static void F_171 ( struct V_158 * V_247 ,
struct V_248 * V_249 )
{
memset ( V_247 , 0 , sizeof( * V_247 ) ) ;
V_247 -> V_40 = V_172 ;
V_247 -> V_59 = V_249 -> V_59 ;
V_247 -> V_4 . V_46 = V_249 -> V_4 ;
V_247 -> V_43 = V_249 -> V_43 ;
V_247 -> V_53 = V_249 -> V_53 ;
V_247 -> V_163 = V_249 -> V_163 ;
V_247 -> V_12 = V_249 -> V_12 ;
V_247 -> V_169 = V_249 -> V_169 ;
V_247 -> V_168 = V_249 -> V_168 ;
}
static void F_172 ( struct V_107 * V_108 ,
struct V_250 * V_251 )
{
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_4 . V_46 = V_251 -> V_4 ;
V_108 -> V_43 = V_251 -> V_43 ;
V_108 -> V_113 = V_251 -> V_113 ;
V_108 -> V_114 = V_251 -> V_114 ;
V_108 -> V_119 = V_251 -> V_119 ;
V_108 -> V_121 = V_251 -> V_121 ;
}
static int
F_173 ( struct V_252 * V_253 , int V_254 , void T_6 * V_255 , unsigned int V_256 )
{
struct V_2 * V_2 = F_174 ( V_253 ) ;
int V_144 ;
unsigned char V_257 [ V_258 ] ;
struct V_248 * V_249 ;
struct V_158 V_247 ;
struct V_54 * V_55 ;
struct V_250 * V_251 ;
struct V_107 V_108 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
if ( ! F_175 ( F_174 ( V_253 ) -> V_259 , V_260 ) )
return - V_261 ;
if ( V_254 < V_262 || V_254 > V_263 )
return - V_134 ;
if ( V_256 < 0 || V_256 > V_258 )
return - V_134 ;
if ( V_256 != V_264 [ F_176 ( V_254 ) ] ) {
F_28 ( L_54 ,
V_256 , V_264 [ F_176 ( V_254 ) ] ) ;
return - V_134 ;
}
if ( F_177 ( V_257 , V_255 , V_256 ) != 0 )
return - V_265 ;
F_18 () ;
if ( V_254 == V_266 ||
V_254 == V_267 ) {
struct V_268 * V_269 = (struct V_268 * ) V_257 ;
if ( F_178 ( & V_15 -> V_270 ) ) {
V_144 = - V_271 ;
goto V_272;
}
if ( V_254 == V_266 )
V_144 = F_179 ( V_2 , V_269 -> V_273 , V_269 -> V_274 ,
V_269 -> V_275 ) ;
else
V_144 = F_180 ( V_2 , V_269 -> V_273 ) ;
F_128 ( & V_15 -> V_270 ) ;
goto V_272;
}
if ( F_178 ( & V_181 ) ) {
V_144 = - V_271 ;
goto V_272;
}
if ( V_254 == V_276 ) {
V_144 = F_124 ( V_2 , false ) ;
goto V_277;
} else if ( V_254 == V_278 ) {
V_144 = F_168 ( V_2 , (struct V_234 * ) V_257 ) ;
goto V_277;
}
V_249 = (struct V_248 * ) V_257 ;
V_251 = (struct V_250 * ) ( V_249 + 1 ) ;
F_171 ( & V_247 , V_249 ) ;
F_172 ( & V_108 , V_251 ) ;
if ( V_254 == V_279 ) {
if ( ! V_247 . V_53 && ! V_247 . V_4 . V_46 && ! V_247 . V_43 ) {
V_144 = F_135 ( V_2 ) ;
goto V_277;
}
}
if ( V_247 . V_59 != V_68 && V_247 . V_59 != V_245 &&
V_247 . V_59 != V_280 ) {
F_28 ( L_55 ,
V_247 . V_59 , & V_247 . V_4 . V_46 ,
F_23 ( V_247 . V_43 ) , V_247 . V_163 ) ;
V_144 = - V_265 ;
goto V_277;
}
F_58 () ;
if ( V_247 . V_53 == 0 )
V_55 = F_35 ( V_2 , V_247 . V_40 , V_247 . V_59 ,
& V_247 . V_4 , V_247 . V_43 ) ;
else
V_55 = F_39 ( V_2 , V_247 . V_40 , V_247 . V_53 ) ;
F_59 () ;
if ( V_254 != V_281
&& ( V_55 == NULL || V_55 -> V_59 != V_247 . V_59 ) ) {
V_144 = - V_282 ;
goto V_277;
}
switch ( V_254 ) {
case V_281 :
if ( V_55 != NULL )
V_144 = - V_146 ;
else
V_144 = F_111 ( V_2 , & V_247 , & V_55 ) ;
break;
case V_283 :
V_144 = F_120 ( V_55 , & V_247 ) ;
break;
case V_284 :
V_144 = F_123 ( V_55 ) ;
if ( ! V_144 )
goto V_277;
break;
case V_279 :
V_144 = F_134 ( V_55 ) ;
break;
case V_285 :
V_144 = F_96 ( V_55 , & V_108 ) ;
break;
case V_286 :
V_144 = F_98 ( V_55 , & V_108 ) ;
break;
case V_287 :
V_144 = F_107 ( V_55 , & V_108 ) ;
break;
default:
V_144 = - V_134 ;
}
V_277:
F_128 ( & V_181 ) ;
V_272:
F_20 () ;
return V_144 ;
}
static void
F_181 ( struct V_288 * V_9 , struct V_54 * V_100 )
{
struct V_111 * V_112 ;
V_112 = F_65 ( V_100 -> V_123 , 1 ) ;
V_9 -> V_59 = V_100 -> V_59 ;
V_9 -> V_4 = V_100 -> V_4 . V_46 ;
V_9 -> V_43 = V_100 -> V_43 ;
V_9 -> V_53 = V_100 -> V_53 ;
F_182 ( V_9 -> V_163 , V_112 -> V_183 , sizeof( V_9 -> V_163 ) ) ;
V_9 -> V_12 = V_100 -> V_12 ;
V_9 -> V_169 = V_100 -> V_169 / V_170 ;
V_9 -> V_168 = V_100 -> V_168 ;
V_9 -> V_126 = V_100 -> V_126 ;
F_77 ( & V_9 -> V_76 , & V_100 -> V_76 ) ;
}
static inline int
F_183 ( struct V_2 * V_2 ,
const struct V_289 * V_290 ,
struct V_289 T_6 * V_291 )
{
int V_177 , V_292 = 0 ;
struct V_54 * V_55 ;
struct V_288 V_293 ;
int V_144 = 0 ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_133 (svc, &ip_vs_svc_table[idx], s_list) {
if ( V_55 -> V_40 != V_172 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_292 >= V_290 -> V_173 )
goto V_67;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
F_181 ( & V_293 , V_55 ) ;
if ( F_184 ( & V_291 -> V_294 [ V_292 ] ,
& V_293 , sizeof( V_293 ) ) ) {
V_144 = - V_265 ;
goto V_67;
}
V_292 ++ ;
}
}
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_133 (svc, &ip_vs_svc_fwm_table[idx], f_list) {
if ( V_55 -> V_40 != V_172 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( V_292 >= V_290 -> V_173 )
goto V_67;
memset ( & V_293 , 0 , sizeof( V_293 ) ) ;
F_181 ( & V_293 , V_55 ) ;
if ( F_184 ( & V_291 -> V_294 [ V_292 ] ,
& V_293 , sizeof( V_293 ) ) ) {
V_144 = - V_265 ;
goto V_67;
}
V_292 ++ ;
}
}
V_67:
return V_144 ;
}
static inline int
F_185 ( struct V_2 * V_2 , const struct V_295 * V_290 ,
struct V_295 T_6 * V_291 )
{
struct V_54 * V_55 ;
union V_42 V_4 = { . V_46 = V_290 -> V_4 } ;
int V_144 = 0 ;
F_58 () ;
if ( V_290 -> V_53 )
V_55 = F_39 ( V_2 , V_172 , V_290 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_172 , V_290 -> V_59 , & V_4 ,
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
V_293 . V_141 = F_15 ( & V_75 -> V_141 ) ;
V_293 . V_142 = F_15 ( & V_75 -> V_142 ) ;
V_293 . V_143 = F_15 ( & V_75 -> V_143 ) ;
F_77 ( & V_293 . V_76 , & V_75 -> V_76 ) ;
if ( F_184 ( & V_291 -> V_294 [ V_292 ] ,
& V_293 , sizeof( V_293 ) ) ) {
V_144 = - V_265 ;
break;
}
V_292 ++ ;
}
} else
V_144 = - V_282 ;
return V_144 ;
}
static inline void
F_186 ( struct V_2 * V_2 , struct V_234 * V_159 )
{
#if F_169 ( V_235 ) || F_169 ( V_236 )
struct V_237 * V_238 ;
#endif
memset ( V_159 , 0 , sizeof ( * V_159 ) ) ;
#ifdef V_235
V_238 = F_170 ( V_2 , V_68 ) ;
V_159 -> V_239 = V_238 -> V_242 [ V_243 ] / V_170 ;
V_159 -> V_240 = V_238 -> V_242 [ V_244 ] / V_170 ;
#endif
#ifdef V_236
V_238 = F_170 ( V_2 , V_245 ) ;
V_159 -> V_241 =
V_238 -> V_242 [ V_246 ] / V_170 ;
#endif
}
static int
F_187 ( struct V_252 * V_253 , int V_254 , void T_6 * V_255 , int * V_256 )
{
unsigned char V_257 [ 128 ] ;
int V_144 = 0 ;
unsigned int V_297 ;
struct V_2 * V_2 = F_174 ( V_253 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_188 ( ! V_2 ) ;
if ( ! F_175 ( F_174 ( V_253 ) -> V_259 , V_260 ) )
return - V_261 ;
if ( V_254 < V_262 || V_254 > V_298 )
return - V_134 ;
if ( * V_256 < V_299 [ F_189 ( V_254 ) ] ) {
F_28 ( L_56 ,
* V_256 , V_299 [ F_189 ( V_254 ) ] ) ;
return - V_134 ;
}
V_297 = V_299 [ F_189 ( V_254 ) ] ;
if ( V_297 > 128 )
return - V_134 ;
if ( F_177 ( V_257 , V_255 , V_297 ) != 0 )
return - V_265 ;
if ( V_254 == V_300 ) {
struct V_268 V_301 [ 2 ] ;
memset ( & V_301 , 0 , sizeof( V_301 ) ) ;
if ( F_178 ( & V_15 -> V_270 ) )
return - V_271 ;
if ( V_15 -> V_302 & V_303 ) {
V_301 [ 0 ] . V_273 = V_303 ;
F_182 ( V_301 [ 0 ] . V_274 , V_15 -> V_304 ,
sizeof( V_301 [ 0 ] . V_274 ) ) ;
V_301 [ 0 ] . V_275 = V_15 -> V_305 ;
}
if ( V_15 -> V_302 & V_306 ) {
V_301 [ 1 ] . V_273 = V_306 ;
F_182 ( V_301 [ 1 ] . V_274 , V_15 -> V_307 ,
sizeof( V_301 [ 1 ] . V_274 ) ) ;
V_301 [ 1 ] . V_275 = V_15 -> V_308 ;
}
if ( F_184 ( V_255 , & V_301 , sizeof( V_301 ) ) != 0 )
V_144 = - V_265 ;
F_128 ( & V_15 -> V_270 ) ;
return V_144 ;
}
if ( F_178 ( & V_181 ) )
return - V_271 ;
switch ( V_254 ) {
case V_309 :
{
char V_310 [ 64 ] ;
sprintf ( V_310 , L_57 ,
F_153 ( V_217 ) , V_218 ) ;
if ( F_184 ( V_255 , V_310 , strlen ( V_310 ) + 1 ) != 0 ) {
V_144 = - V_265 ;
goto V_67;
}
* V_256 = strlen ( V_310 ) + 1 ;
}
break;
case V_311 :
{
struct V_312 V_313 ;
V_313 . V_314 = V_217 ;
V_313 . V_315 = V_218 ;
V_313 . V_173 = V_15 -> V_173 ;
if ( F_184 ( V_255 , & V_313 , sizeof( V_313 ) ) != 0 )
V_144 = - V_265 ;
}
break;
case V_316 :
{
struct V_289 * V_290 ;
int V_315 ;
V_290 = (struct V_289 * ) V_257 ;
V_315 = sizeof( * V_290 ) +
sizeof( struct V_288 ) * V_290 -> V_173 ;
if ( * V_256 != V_315 ) {
F_28 ( L_58 , * V_256 , V_315 ) ;
V_144 = - V_134 ;
goto V_67;
}
V_144 = F_183 ( V_2 , V_290 , V_255 ) ;
}
break;
case V_317 :
{
struct V_288 * V_293 ;
struct V_54 * V_55 ;
union V_42 V_4 ;
V_293 = (struct V_288 * ) V_257 ;
V_4 . V_46 = V_293 -> V_4 ;
F_58 () ;
if ( V_293 -> V_53 )
V_55 = F_39 ( V_2 , V_172 , V_293 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_172 ,
V_293 -> V_59 , & V_4 ,
V_293 -> V_43 ) ;
F_59 () ;
if ( V_55 ) {
F_181 ( V_293 , V_55 ) ;
if ( F_184 ( V_255 , V_293 , sizeof( * V_293 ) ) != 0 )
V_144 = - V_265 ;
} else
V_144 = - V_282 ;
}
break;
case V_318 :
{
struct V_295 * V_290 ;
int V_315 ;
V_290 = (struct V_295 * ) V_257 ;
V_315 = sizeof( * V_290 ) +
sizeof( struct V_296 ) * V_290 -> V_126 ;
if ( * V_256 != V_315 ) {
F_28 ( L_58 , * V_256 , V_315 ) ;
V_144 = - V_134 ;
goto V_67;
}
V_144 = F_185 ( V_2 , V_290 , V_255 ) ;
}
break;
case V_319 :
{
struct V_234 V_320 ;
F_186 ( V_2 , & V_320 ) ;
if ( F_184 ( V_255 , & V_320 , sizeof( V_320 ) ) != 0 )
V_144 = - V_265 ;
}
break;
default:
V_144 = - V_134 ;
}
V_67:
F_128 ( & V_181 ) ;
return V_144 ;
}
static int F_190 ( struct V_321 * V_322 , int V_323 ,
struct V_99 * V_76 )
{
struct V_98 V_233 ;
struct V_324 * V_325 = F_191 ( V_322 , V_323 ) ;
if ( ! V_325 )
return - V_326 ;
F_77 ( & V_233 , V_76 ) ;
if ( F_192 ( V_322 , V_327 , V_233 . V_102 ) ||
F_192 ( V_322 , V_328 , V_233 . V_103 ) ||
F_192 ( V_322 , V_329 , V_233 . V_104 ) ||
F_193 ( V_322 , V_330 , V_233 . V_105 ) ||
F_193 ( V_322 , V_331 , V_233 . V_106 ) ||
F_192 ( V_322 , V_332 , V_233 . V_225 ) ||
F_192 ( V_322 , V_333 , V_233 . V_226 ) ||
F_192 ( V_322 , V_334 , V_233 . V_227 ) ||
F_192 ( V_322 , V_335 , V_233 . V_228 ) ||
F_192 ( V_322 , V_336 , V_233 . V_229 ) )
goto V_337;
F_194 ( V_322 , V_325 ) ;
return 0 ;
V_337:
F_195 ( V_322 , V_325 ) ;
return - V_326 ;
}
static int F_196 ( struct V_321 * V_322 ,
struct V_54 * V_55 )
{
struct V_111 * V_112 ;
struct V_161 * V_162 ;
struct V_324 * V_338 ;
struct V_339 V_12 = { . V_12 = V_55 -> V_12 ,
. V_340 = ~ 0 } ;
V_338 = F_191 ( V_322 , V_341 ) ;
if ( ! V_338 )
return - V_326 ;
if ( F_197 ( V_322 , V_342 , V_55 -> V_40 ) )
goto V_337;
if ( V_55 -> V_53 ) {
if ( F_192 ( V_322 , V_343 , V_55 -> V_53 ) )
goto V_337;
} else {
if ( F_197 ( V_322 , V_344 , V_55 -> V_59 ) ||
F_198 ( V_322 , V_345 , sizeof( V_55 -> V_4 ) , & V_55 -> V_4 ) ||
F_199 ( V_322 , V_346 , V_55 -> V_43 ) )
goto V_337;
}
V_112 = F_65 ( V_55 -> V_123 , 1 ) ;
V_162 = F_65 ( V_55 -> V_162 , 1 ) ;
if ( F_200 ( V_322 , V_347 , V_112 -> V_183 ) ||
( V_162 && F_200 ( V_322 , V_348 , V_162 -> V_183 ) ) ||
F_198 ( V_322 , V_349 , sizeof( V_12 ) , & V_12 ) ||
F_192 ( V_322 , V_350 , V_55 -> V_169 / V_170 ) ||
F_201 ( V_322 , V_351 , V_55 -> V_168 ) )
goto V_337;
if ( F_190 ( V_322 , V_352 , & V_55 -> V_76 ) )
goto V_337;
F_194 ( V_322 , V_338 ) ;
return 0 ;
V_337:
F_195 ( V_322 , V_338 ) ;
return - V_326 ;
}
static int F_202 ( struct V_321 * V_322 ,
struct V_54 * V_55 ,
struct V_353 * V_354 )
{
void * V_355 ;
V_355 = F_203 ( V_322 , F_204 ( V_354 -> V_322 ) . V_356 , V_354 -> V_357 -> V_358 ,
& V_359 , V_360 ,
V_361 ) ;
if ( ! V_355 )
return - V_326 ;
if ( F_196 ( V_322 , V_55 ) < 0 )
goto V_337;
return F_205 ( V_322 , V_355 ) ;
V_337:
F_206 ( V_322 , V_355 ) ;
return - V_326 ;
}
static int F_207 ( struct V_321 * V_322 ,
struct V_353 * V_354 )
{
int V_177 = 0 , V_17 ;
int V_231 = V_354 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_2 * V_2 = F_208 ( V_322 ) ;
F_127 ( & V_181 ) ;
for ( V_17 = 0 ; V_17 < V_180 ; V_17 ++ ) {
F_133 (svc, &ip_vs_svc_table[i], s_list) {
if ( ++ V_177 <= V_231 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_202 ( V_322 , V_55 , V_354 ) < 0 ) {
V_177 -- ;
goto V_337;
}
}
}
for ( V_17 = 0 ; V_17 < V_180 ; V_17 ++ ) {
F_133 (svc, &ip_vs_svc_fwm_table[i], f_list) {
if ( ++ V_177 <= V_231 || ! F_38 ( V_55 -> V_2 , V_2 ) )
continue;
if ( F_202 ( V_322 , V_55 , V_354 ) < 0 ) {
V_177 -- ;
goto V_337;
}
}
}
V_337:
F_128 ( & V_181 ) ;
V_354 -> args [ 0 ] = V_177 ;
return V_322 -> V_256 ;
}
static int F_209 ( struct V_2 * V_2 ,
struct V_158 * V_247 ,
struct V_324 * V_362 , int V_363 ,
struct V_54 * * V_364 )
{
struct V_324 * V_365 [ V_366 + 1 ] ;
struct V_324 * V_367 , * V_368 , * V_369 , * V_370 , * V_371 ;
struct V_54 * V_55 ;
if ( V_362 == NULL ||
F_210 ( V_365 , V_366 , V_362 , V_372 ) )
return - V_134 ;
V_367 = V_365 [ V_342 ] ;
V_370 = V_365 [ V_344 ] ;
V_371 = V_365 [ V_345 ] ;
V_368 = V_365 [ V_346 ] ;
V_369 = V_365 [ V_343 ] ;
if ( ! ( V_367 && ( V_369 || ( V_368 && V_370 && V_371 ) ) ) )
return - V_134 ;
memset ( V_247 , 0 , sizeof( * V_247 ) ) ;
V_247 -> V_40 = F_211 ( V_367 ) ;
#ifdef F_24
if ( V_247 -> V_40 != V_172 && V_247 -> V_40 != V_48 )
#else
if ( V_247 -> V_40 != V_172 )
#endif
return - V_373 ;
if ( V_369 ) {
V_247 -> V_59 = V_68 ;
V_247 -> V_53 = F_212 ( V_369 ) ;
} else {
V_247 -> V_59 = F_211 ( V_370 ) ;
F_213 ( & V_247 -> V_4 , V_371 , sizeof( V_247 -> V_4 ) ) ;
V_247 -> V_43 = F_214 ( V_368 ) ;
V_247 -> V_53 = 0 ;
}
F_58 () ;
if ( V_247 -> V_53 )
V_55 = F_39 ( V_2 , V_247 -> V_40 , V_247 -> V_53 ) ;
else
V_55 = F_35 ( V_2 , V_247 -> V_40 , V_247 -> V_59 ,
& V_247 -> V_4 , V_247 -> V_43 ) ;
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
F_213 ( & V_12 , V_375 , sizeof( V_12 ) ) ;
if ( V_55 )
V_247 -> V_12 = V_55 -> V_12 ;
V_247 -> V_12 = ( V_247 -> V_12 & ~ V_12 . V_340 ) |
( V_12 . V_12 & V_12 . V_340 ) ;
V_247 -> V_163 = F_215 ( V_374 ) ;
V_247 -> V_165 = V_376 ? F_215 ( V_376 ) : NULL ;
V_247 -> V_169 = F_212 ( V_377 ) ;
V_247 -> V_168 = F_216 ( V_378 ) ;
}
return 0 ;
}
static struct V_54 * F_217 ( struct V_2 * V_2 ,
struct V_324 * V_362 )
{
struct V_158 V_247 ;
struct V_54 * V_55 ;
int V_144 ;
V_144 = F_209 ( V_2 , & V_247 , V_362 , 0 , & V_55 ) ;
return V_144 ? F_218 ( V_144 ) : V_55 ;
}
static int F_219 ( struct V_321 * V_322 , struct V_74 * V_75 )
{
struct V_324 * V_379 ;
V_379 = F_191 ( V_322 , V_380 ) ;
if ( ! V_379 )
return - V_326 ;
if ( F_198 ( V_322 , V_381 , sizeof( V_75 -> V_4 ) , & V_75 -> V_4 ) ||
F_199 ( V_322 , V_382 , V_75 -> V_43 ) ||
F_192 ( V_322 , V_383 ,
( F_15 ( & V_75 -> V_113 ) &
V_88 ) ) ||
F_192 ( V_322 , V_384 ,
F_15 ( & V_75 -> V_114 ) ) ||
F_192 ( V_322 , V_385 , V_75 -> V_119 ) ||
F_192 ( V_322 , V_386 , V_75 -> V_121 ) ||
F_192 ( V_322 , V_387 ,
F_15 ( & V_75 -> V_141 ) ) ||
F_192 ( V_322 , V_388 ,
F_15 ( & V_75 -> V_142 ) ) ||
F_192 ( V_322 , V_389 ,
F_15 ( & V_75 -> V_143 ) ) )
goto V_337;
if ( F_190 ( V_322 , V_390 , & V_75 -> V_76 ) )
goto V_337;
F_194 ( V_322 , V_379 ) ;
return 0 ;
V_337:
F_195 ( V_322 , V_379 ) ;
return - V_326 ;
}
static int F_220 ( struct V_321 * V_322 , struct V_74 * V_75 ,
struct V_353 * V_354 )
{
void * V_355 ;
V_355 = F_203 ( V_322 , F_204 ( V_354 -> V_322 ) . V_356 , V_354 -> V_357 -> V_358 ,
& V_359 , V_360 ,
V_391 ) ;
if ( ! V_355 )
return - V_326 ;
if ( F_219 ( V_322 , V_75 ) < 0 )
goto V_337;
return F_205 ( V_322 , V_355 ) ;
V_337:
F_206 ( V_322 , V_355 ) ;
return - V_326 ;
}
static int F_221 ( struct V_321 * V_322 ,
struct V_353 * V_354 )
{
int V_177 = 0 ;
int V_231 = V_354 -> args [ 0 ] ;
struct V_54 * V_55 ;
struct V_74 * V_75 ;
struct V_324 * V_365 [ V_392 + 1 ] ;
struct V_2 * V_2 = F_208 ( V_322 ) ;
F_127 ( & V_181 ) ;
if ( F_222 ( V_354 -> V_357 , V_393 , V_365 ,
V_392 , V_394 ) )
goto V_164;
V_55 = F_217 ( V_2 , V_365 [ V_341 ] ) ;
if ( F_223 ( V_55 ) || V_55 == NULL )
goto V_164;
F_69 (dest, &svc->destinations, n_list) {
if ( ++ V_177 <= V_231 )
continue;
if ( F_220 ( V_322 , V_75 , V_354 ) < 0 ) {
V_177 -- ;
goto V_337;
}
}
V_337:
V_354 -> args [ 0 ] = V_177 ;
V_164:
F_128 ( & V_181 ) ;
return V_322 -> V_256 ;
}
static int F_224 ( struct V_107 * V_108 ,
struct V_324 * V_362 , int V_363 )
{
struct V_324 * V_365 [ V_395 + 1 ] ;
struct V_324 * V_371 , * V_368 ;
if ( V_362 == NULL ||
F_210 ( V_365 , V_395 , V_362 , V_396 ) )
return - V_134 ;
V_371 = V_365 [ V_381 ] ;
V_368 = V_365 [ V_382 ] ;
if ( ! ( V_371 && V_368 ) )
return - V_134 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
F_213 ( & V_108 -> V_4 , V_371 , sizeof( V_108 -> V_4 ) ) ;
V_108 -> V_43 = F_214 ( V_368 ) ;
if ( V_363 ) {
struct V_324 * V_397 , * V_398 , * V_399 ,
* V_400 ;
V_397 = V_365 [ V_383 ] ;
V_398 = V_365 [ V_384 ] ;
V_399 = V_365 [ V_385 ] ;
V_400 = V_365 [ V_386 ] ;
if ( ! ( V_397 && V_398 && V_399 && V_400 ) )
return - V_134 ;
V_108 -> V_113 = F_212 ( V_397 )
& V_88 ;
V_108 -> V_114 = F_212 ( V_398 ) ;
V_108 -> V_119 = F_212 ( V_399 ) ;
V_108 -> V_121 = F_212 ( V_400 ) ;
}
return 0 ;
}
static int F_225 ( struct V_321 * V_322 , T_3 V_273 ,
const char * V_274 , T_3 V_275 )
{
struct V_324 * V_401 ;
V_401 = F_191 ( V_322 , V_402 ) ;
if ( ! V_401 )
return - V_326 ;
if ( F_192 ( V_322 , V_403 , V_273 ) ||
F_200 ( V_322 , V_404 , V_274 ) ||
F_192 ( V_322 , V_405 , V_275 ) )
goto V_337;
F_194 ( V_322 , V_401 ) ;
return 0 ;
V_337:
F_195 ( V_322 , V_401 ) ;
return - V_326 ;
}
static int F_226 ( struct V_321 * V_322 , T_3 V_273 ,
const char * V_274 , T_3 V_275 ,
struct V_353 * V_354 )
{
void * V_355 ;
V_355 = F_203 ( V_322 , F_204 ( V_354 -> V_322 ) . V_356 , V_354 -> V_357 -> V_358 ,
& V_359 , V_360 ,
V_406 ) ;
if ( ! V_355 )
return - V_326 ;
if ( F_225 ( V_322 , V_273 , V_274 , V_275 ) )
goto V_337;
return F_205 ( V_322 , V_355 ) ;
V_337:
F_206 ( V_322 , V_355 ) ;
return - V_326 ;
}
static int F_227 ( struct V_321 * V_322 ,
struct V_353 * V_354 )
{
struct V_2 * V_2 = F_208 ( V_322 ) ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_127 ( & V_15 -> V_270 ) ;
if ( ( V_15 -> V_302 & V_303 ) && ! V_354 -> args [ 0 ] ) {
if ( F_226 ( V_322 , V_303 ,
V_15 -> V_304 ,
V_15 -> V_305 , V_354 ) < 0 )
goto V_337;
V_354 -> args [ 0 ] = 1 ;
}
if ( ( V_15 -> V_302 & V_306 ) && ! V_354 -> args [ 1 ] ) {
if ( F_226 ( V_322 , V_306 ,
V_15 -> V_307 ,
V_15 -> V_308 , V_354 ) < 0 )
goto V_337;
V_354 -> args [ 1 ] = 1 ;
}
V_337:
F_128 ( & V_15 -> V_270 ) ;
return V_322 -> V_256 ;
}
static int F_228 ( struct V_2 * V_2 , struct V_324 * * V_365 )
{
if ( ! ( V_365 [ V_403 ] &&
V_365 [ V_404 ] &&
V_365 [ V_405 ] ) )
return - V_134 ;
return F_179 ( V_2 ,
F_212 ( V_365 [ V_403 ] ) ,
F_215 ( V_365 [ V_404 ] ) ,
F_212 ( V_365 [ V_405 ] ) ) ;
}
static int F_229 ( struct V_2 * V_2 , struct V_324 * * V_365 )
{
if ( ! V_365 [ V_403 ] )
return - V_134 ;
return F_180 ( V_2 ,
F_212 ( V_365 [ V_403 ] ) ) ;
}
static int F_230 ( struct V_2 * V_2 , struct V_324 * * V_365 )
{
struct V_234 V_320 ;
F_186 ( V_2 , & V_320 ) ;
if ( V_365 [ V_407 ] )
V_320 . V_239 = F_212 ( V_365 [ V_407 ] ) ;
if ( V_365 [ V_408 ] )
V_320 . V_240 =
F_212 ( V_365 [ V_408 ] ) ;
if ( V_365 [ V_409 ] )
V_320 . V_241 = F_212 ( V_365 [ V_409 ] ) ;
return F_168 ( V_2 , & V_320 ) ;
}
static int F_231 ( struct V_321 * V_322 , struct V_410 * V_313 )
{
int V_144 = 0 , V_254 ;
struct V_2 * V_2 ;
struct V_14 * V_15 ;
V_2 = F_208 ( V_322 ) ;
V_15 = F_41 ( V_2 ) ;
V_254 = V_313 -> V_411 -> V_254 ;
if ( V_254 == V_406 || V_254 == V_412 ) {
struct V_324 * V_413 [ V_414 + 1 ] ;
F_127 ( & V_15 -> V_270 ) ;
if ( ! V_313 -> V_365 [ V_402 ] ||
F_210 ( V_413 , V_414 ,
V_313 -> V_365 [ V_402 ] ,
V_415 ) ) {
V_144 = - V_134 ;
goto V_67;
}
if ( V_254 == V_406 )
V_144 = F_228 ( V_2 , V_413 ) ;
else
V_144 = F_229 ( V_2 , V_413 ) ;
V_67:
F_128 ( & V_15 -> V_270 ) ;
}
return V_144 ;
}
static int F_232 ( struct V_321 * V_322 , struct V_410 * V_313 )
{
struct V_54 * V_55 = NULL ;
struct V_158 V_247 ;
struct V_107 V_108 ;
int V_144 = 0 , V_254 ;
int V_416 = 0 , V_417 = 0 ;
struct V_2 * V_2 ;
V_2 = F_208 ( V_322 ) ;
V_254 = V_313 -> V_411 -> V_254 ;
F_127 ( & V_181 ) ;
if ( V_254 == V_418 ) {
V_144 = F_124 ( V_2 , false ) ;
goto V_67;
} else if ( V_254 == V_419 ) {
V_144 = F_230 ( V_2 , V_313 -> V_365 ) ;
goto V_67;
} else if ( V_254 == V_420 &&
! V_313 -> V_365 [ V_341 ] ) {
V_144 = F_135 ( V_2 ) ;
goto V_67;
}
if ( V_254 == V_361 || V_254 == V_421 )
V_416 = 1 ;
V_144 = F_209 ( V_2 , & V_247 ,
V_313 -> V_365 [ V_341 ] ,
V_416 , & V_55 ) ;
if ( V_144 )
goto V_67;
if ( ( V_254 != V_361 ) && ( V_55 == NULL ) ) {
V_144 = - V_282 ;
goto V_67;
}
if ( V_254 == V_391 || V_254 == V_422 ||
V_254 == V_423 ) {
if ( V_254 != V_423 )
V_417 = 1 ;
V_144 = F_224 ( & V_108 ,
V_313 -> V_365 [ V_380 ] ,
V_417 ) ;
if ( V_144 )
goto V_67;
}
switch ( V_254 ) {
case V_361 :
if ( V_55 == NULL )
V_144 = F_111 ( V_2 , & V_247 , & V_55 ) ;
else
V_144 = - V_146 ;
break;
case V_421 :
V_144 = F_120 ( V_55 , & V_247 ) ;
break;
case V_424 :
V_144 = F_123 ( V_55 ) ;
break;
case V_391 :
V_144 = F_96 ( V_55 , & V_108 ) ;
break;
case V_422 :
V_144 = F_98 ( V_55 , & V_108 ) ;
break;
case V_423 :
V_144 = F_107 ( V_55 , & V_108 ) ;
break;
case V_420 :
V_144 = F_134 ( V_55 ) ;
break;
default:
V_144 = - V_134 ;
}
V_67:
F_128 ( & V_181 ) ;
return V_144 ;
}
static int F_233 ( struct V_321 * V_322 , struct V_410 * V_313 )
{
struct V_321 * V_425 ;
void * V_426 ;
int V_144 , V_254 , V_427 ;
struct V_2 * V_2 ;
V_2 = F_208 ( V_322 ) ;
V_254 = V_313 -> V_411 -> V_254 ;
if ( V_254 == V_428 )
V_427 = V_361 ;
else if ( V_254 == V_429 )
V_427 = V_430 ;
else if ( V_254 == V_431 )
V_427 = V_419 ;
else {
F_28 ( L_59 ) ;
return - V_134 ;
}
V_425 = F_234 ( V_432 , V_137 ) ;
if ( ! V_425 )
return - V_138 ;
F_127 ( & V_181 ) ;
V_426 = F_235 ( V_425 , V_313 , & V_359 , 0 , V_427 ) ;
if ( V_426 == NULL )
goto V_337;
switch ( V_254 ) {
case V_428 :
{
struct V_54 * V_55 ;
V_55 = F_217 ( V_2 ,
V_313 -> V_365 [ V_341 ] ) ;
if ( F_223 ( V_55 ) ) {
V_144 = F_236 ( V_55 ) ;
goto V_164;
} else if ( V_55 ) {
V_144 = F_196 ( V_425 , V_55 ) ;
if ( V_144 )
goto V_337;
} else {
V_144 = - V_282 ;
goto V_164;
}
break;
}
case V_431 :
{
struct V_234 V_320 ;
F_186 ( V_2 , & V_320 ) ;
#ifdef V_235
if ( F_192 ( V_425 , V_407 ,
V_320 . V_239 ) ||
F_192 ( V_425 , V_408 ,
V_320 . V_240 ) )
goto V_337;
#endif
#ifdef V_236
if ( F_192 ( V_425 , V_409 , V_320 . V_241 ) )
goto V_337;
#endif
break;
}
case V_429 :
if ( F_192 ( V_425 , V_433 ,
V_217 ) ||
F_192 ( V_425 , V_434 ,
V_218 ) )
goto V_337;
break;
}
F_205 ( V_425 , V_426 ) ;
V_144 = F_237 ( V_425 , V_313 ) ;
goto V_67;
V_337:
F_28 ( L_60 ) ;
V_144 = - V_326 ;
V_164:
F_238 ( V_425 ) ;
V_67:
F_128 ( & V_181 ) ;
return V_144 ;
}
static int T_11 F_239 ( void )
{
return F_240 ( & V_359 ,
V_435 , F_241 ( V_435 ) ) ;
}
static void F_242 ( void )
{
F_243 ( & V_359 ) ;
}
static int T_12 F_244 ( struct V_2 * V_2 )
{
int V_177 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
struct V_191 * V_436 ;
F_9 ( & V_15 -> V_27 , 0 ) ;
F_94 ( & V_15 -> V_25 ) ;
F_94 ( & V_15 -> V_28 ) ;
F_94 ( & V_15 -> V_33 ) ;
if ( ! F_38 ( V_2 , & V_437 ) ) {
V_436 = F_245 ( V_438 , sizeof( V_438 ) , V_137 ) ;
if ( V_436 == NULL )
return - V_138 ;
if ( V_2 -> V_259 != & V_439 )
V_436 [ 0 ] . V_440 = NULL ;
} else
V_436 = V_438 ;
V_177 = 0 ;
V_15 -> V_24 = 1024 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_24 ;
V_15 -> V_32 = 10 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_32 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_26 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_29 ;
#ifdef F_246
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_441 ;
#endif
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_34 ;
V_15 -> V_442 = 1 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_442 ;
V_15 -> V_443 = 1 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_443 ;
V_15 -> V_444 = 1 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_444 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_445 ;
V_15 -> V_446 = F_247 () / 32 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_446 ;
V_15 -> V_447 = 0 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_447 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_448 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_449 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_450 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_451 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_452 ;
V_15 -> V_453 [ 0 ] = V_454 ;
V_15 -> V_453 [ 1 ] = V_455 ;
V_436 [ V_177 ] . V_155 = & V_15 -> V_453 ;
V_436 [ V_177 ++ ] . V_456 = sizeof( V_15 -> V_453 ) ;
V_15 -> V_457 = V_458 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_457 ;
V_15 -> V_459 = F_248 ( int , V_460 , 0 , 3 ) ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_459 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_461 ;
V_15 -> V_462 = 1 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_462 ;
V_436 [ V_177 ++ ] . V_155 = & V_15 -> V_463 ;
V_15 -> V_464 = F_249 ( V_2 , L_61 , V_436 ) ;
if ( V_15 -> V_464 == NULL ) {
if ( ! F_38 ( V_2 , & V_437 ) )
F_49 ( V_436 ) ;
return - V_138 ;
}
F_84 ( V_2 , & V_15 -> V_190 ) ;
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
}
static int T_12 F_244 ( struct V_2 * V_2 ) { return 0 ; }
static void T_13 F_251 ( struct V_2 * V_2 ) { }
int T_12 F_255 ( struct V_2 * V_2 )
{
int V_177 ;
struct V_14 * V_15 = F_41 ( V_2 ) ;
for ( V_177 = 0 ; V_177 < V_466 ; V_177 ++ )
F_256 ( & V_15 -> V_85 [ V_177 ] ) ;
F_115 ( & V_15 -> V_149 ) ;
F_94 ( & V_15 -> V_94 ) ;
F_257 ( & V_15 -> V_97 , F_108 ,
( unsigned long ) V_2 ) ;
F_9 ( & V_15 -> V_69 , 0 ) ;
F_9 ( & V_15 -> V_73 , 0 ) ;
V_15 -> V_190 . V_77 = F_91 ( struct V_139 ) ;
if ( ! V_15 -> V_190 . V_77 )
return - V_138 ;
F_94 ( & V_15 -> V_190 . V_101 ) ;
F_258 ( L_62 , 0 , V_2 -> V_467 , & V_468 ) ;
F_258 ( L_63 , 0 , V_2 -> V_467 , & V_469 ) ;
F_258 ( L_64 , 0 , V_2 -> V_467 ,
& V_470 ) ;
if ( F_244 ( V_2 ) )
goto V_471;
return 0 ;
V_471:
F_48 ( V_15 -> V_190 . V_77 ) ;
return - V_138 ;
}
void T_13 F_259 ( struct V_2 * V_2 )
{
struct V_14 * V_15 = F_41 ( V_2 ) ;
F_260 () ;
F_74 ( V_2 ) ;
F_100 ( V_2 , & V_15 -> V_190 ) ;
F_251 ( V_2 ) ;
F_261 ( L_64 , V_2 -> V_467 ) ;
F_261 ( L_63 , V_2 -> V_467 ) ;
F_261 ( L_62 , V_2 -> V_467 ) ;
F_48 ( V_15 -> V_190 . V_77 ) ;
}
int T_11 F_262 ( void )
{
int V_144 ;
V_144 = F_263 ( & V_472 ) ;
if ( V_144 ) {
F_28 ( L_65 ) ;
goto V_473;
}
V_144 = F_239 () ;
if ( V_144 ) {
F_28 ( L_66 ) ;
goto V_474;
}
return 0 ;
V_474:
F_264 ( & V_472 ) ;
V_473:
return V_144 ;
}
void F_265 ( void )
{
F_242 () ;
F_264 ( & V_472 ) ;
}
int T_11 F_266 ( void )
{
int V_177 ;
int V_144 ;
F_87 ( 2 ) ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
F_256 ( & V_61 [ V_177 ] ) ;
F_256 ( & V_63 [ V_177 ] ) ;
}
F_267 () ;
V_144 = F_268 ( & V_475 ) ;
if ( V_144 < 0 )
return V_144 ;
F_95 ( 2 ) ;
return 0 ;
}
void F_269 ( void )
{
F_87 ( 2 ) ;
F_270 ( & V_475 ) ;
F_95 ( 2 ) ;
}
