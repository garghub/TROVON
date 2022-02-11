static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) & V_6 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_6 , F_6 ( V_4 -> V_5 ) ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_6 , F_8 ( V_4 -> V_5 ) ) ;
}
static unsigned long F_9 ( unsigned long V_7 ,
unsigned long V_8 ,
T_1 V_9 ,
T_1 V_10 )
{
unsigned long V_11 , V_12 , V_13 ;
unsigned long div , V_14 ;
div = V_8 / V_7 ;
div = F_10 ( div , V_10 , V_9 ) ;
V_14 = F_10 ( div + 1 , V_10 , V_9 ) ;
V_11 = V_8 / div ;
V_12 = V_8 / V_14 ;
if ( abs ( V_7 - V_12 ) < abs ( V_7 - V_11 ) )
V_13 = V_12 ;
else
V_13 = V_11 ;
return V_13 ;
}
static inline T_1 F_11 ( struct V_3 * V_4 )
{
return ( ( F_3 ( V_4 -> V_5 ) >> V_15 ) & V_16 ) + 1 ;
}
static unsigned long F_12 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_8 / F_11 ( V_4 ) ;
}
static long F_13 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long * V_8 )
{
return F_9 ( V_7 , * V_8 ,
V_17 , V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_19 ;
T_1 V_20 , div ;
int V_21 ;
V_21 = F_15 ( V_4 -> V_5 , V_20 , V_20 & V_22 ,
1 , V_23 ) ;
if ( V_21 )
return V_21 ;
div = F_16 ( V_8 , V_7 ) ;
F_17 ( & V_4 -> V_24 -> V_25 , V_19 ) ;
V_20 = F_3 ( V_4 -> V_5 ) ;
V_20 &= ~ V_16 ;
V_20 |= ( div - 1 ) ;
F_18 () ;
F_5 ( V_20 , V_4 -> V_5 ) ;
F_19 ( & V_4 -> V_24 -> V_25 , V_19 ) ;
V_21 = F_15 ( V_4 -> V_5 , V_20 , V_20 & V_22 ,
1 , V_23 ) ;
if ( V_21 )
return V_21 ;
return ( F_11 ( V_4 ) == div ) ? 0 : - V_26 ;
}
struct V_27 * F_20 ( const struct V_28 * V_29 ,
struct V_30 * V_24 )
{
struct V_3 * V_31 ;
struct V_27 * V_27 ;
V_31 = F_21 ( V_24 -> V_32 , sizeof( * V_31 ) , V_33 ) ;
if ( ! V_31 )
return F_22 ( - V_34 ) ;
V_31 -> V_2 . V_35 = & V_29 -> V_36 ;
V_31 -> V_24 = V_24 ;
V_31 -> V_5 = V_29 -> V_5 + V_24 -> V_37 ;
V_27 = F_23 ( V_24 -> V_32 , & V_31 -> V_2 ) ;
if ( F_24 ( V_27 ) ) {
F_25 ( V_24 -> V_32 , L_1 , V_38 ) ;
F_26 ( V_24 -> V_32 , V_31 ) ;
}
return V_27 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
return F_3 ( V_40 -> V_5 ) & V_41 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
F_5 ( V_41 | V_42 , F_6 ( V_40 -> V_5 ) ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
F_5 ( V_41 | V_42 , F_8 ( V_40 -> V_5 ) ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
T_1 V_20 , V_43 ;
V_20 = ( F_3 ( V_40 -> V_5 ) >> V_44 ) & V_45 ;
if ( ! V_40 -> V_46 )
return V_20 ;
for ( V_43 = 0 ; V_43 < F_33 ( V_2 ) ; V_43 ++ )
if ( V_40 -> V_46 [ V_43 ] == V_20 )
return V_43 ;
return - V_47 ;
}
static unsigned long F_34 ( unsigned long V_8 ,
T_1 V_48 , T_1 V_49 )
{
T_3 V_50 ;
if ( V_49 ) {
V_48 = ( V_48 << 9 ) + V_49 ;
V_50 = V_8 ;
V_50 <<= 8 ;
F_35 ( V_50 , V_48 ) ;
} else if ( V_48 ) {
V_50 = V_8 / ( V_48 << 1 ) ;
} else {
V_50 = V_8 ;
}
return V_50 ;
}
static void F_36 ( unsigned long V_7 ,
unsigned long V_8 ,
T_1 * V_51 , T_1 * V_52 )
{
T_1 div , V_49 , V_48 ;
T_3 V_53 ;
if ( V_8 <= V_7 ) {
div = 0 ;
V_53 = 0 ;
V_48 = 0 ;
V_49 = 0 ;
} else {
div = V_8 / ( V_7 << 1 ) ;
V_53 = V_8 ;
V_53 <<= 8 ;
F_35 ( V_53 , V_7 ) ;
V_53 -= ( T_3 ) ( div << 9 ) ;
V_48 = ( div > V_54 ) ? V_54 : div ;
V_49 = ( V_53 >= V_55 ) ? V_55 : V_53 ;
}
if ( V_51 )
* V_51 = V_48 ;
if ( V_52 )
* V_52 = V_49 ;
}
static unsigned long F_37 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
T_1 V_20 , V_48 , V_49 ;
V_20 = F_3 ( V_40 -> V_5 ) ;
V_48 = ( V_20 >> V_56 ) & V_54 ;
V_20 = F_3 ( V_40 -> V_5 + V_57 ) ;
V_49 = ( V_20 >> V_58 ) & V_59 ;
return F_34 ( V_8 , V_48 , V_49 ) ;
}
static long F_38 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long * V_8 )
{
T_1 V_49 , V_48 ;
F_36 ( V_7 , * V_8 , & V_48 , & V_49 ) ;
return F_34 ( * V_8 , V_48 , V_49 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_1 * V_62 , * V_63 = NULL ;
unsigned int V_43 , V_64 , V_65 = - 1 ;
unsigned long V_8 , V_66 = 0 ;
unsigned long V_67 = 0 , V_68 ;
for ( V_43 = 0 ; V_43 < F_33 ( V_2 ) ; V_43 ++ ) {
V_62 = F_40 ( V_2 , V_43 ) ;
if ( ! V_62 )
continue;
V_8 = F_41 ( V_62 ) ;
if ( V_61 -> V_7 > V_8 )
continue;
V_68 = F_38 ( V_2 , V_61 -> V_7 , & V_8 ) ;
V_64 = abs ( V_68 - V_61 -> V_7 ) ;
if ( ( V_68 >= V_61 -> V_7 ) && ( V_64 < V_65 ) ) {
V_63 = V_62 ;
V_66 = V_8 ;
V_67 = V_68 ;
V_65 = V_64 ;
if ( V_64 == 0 )
break;
}
}
if ( ! V_63 ) {
F_42 ( L_2 ,
V_38 , F_43 ( V_2 ) , V_61 -> V_7 ) ;
return F_41 ( V_2 ) ;
}
F_44 ( L_3 ,
F_43 ( V_2 ) , V_61 -> V_7 ,
F_43 ( V_63 ) , V_66 ,
V_67 , V_65 ) ;
if ( V_61 -> V_66 )
V_61 -> V_66 = V_66 ;
if ( V_61 -> V_69 )
V_61 -> V_69 = V_63 ;
return V_67 ;
}
static int F_45 ( struct V_1 * V_2 , T_2 V_70 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
unsigned long V_19 ;
T_1 V_20 ;
int V_21 ;
if ( V_40 -> V_46 )
V_70 = V_40 -> V_46 [ V_70 ] ;
V_21 = F_15 ( V_40 -> V_5 , V_20 , ! ( V_20 & V_71 ) ,
1 , V_23 ) ;
if ( V_21 ) {
F_42 ( L_4 , F_43 ( V_2 ) ) ;
return V_21 ;
}
F_17 ( & V_40 -> V_24 -> V_25 , V_19 ) ;
F_18 () ;
V_20 = F_3 ( V_40 -> V_5 ) ;
V_20 &= ~ ( V_45 << V_44 ) ;
V_20 |= V_70 << V_44 ;
F_5 ( V_20 , V_40 -> V_5 ) ;
F_19 ( & V_40 -> V_24 -> V_25 , V_19 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned long V_7 ,
unsigned long V_8 ,
T_2 V_70 )
{
struct V_39 * V_40 = F_28 ( V_2 ) ;
unsigned long V_19 ;
T_1 V_72 , V_48 , V_20 ;
int V_21 ;
F_36 ( V_7 , V_8 , & V_48 , & V_72 ) ;
F_44 ( L_5 ,
V_8 , V_7 , V_48 , V_72 ) ;
V_21 = F_15 ( V_40 -> V_5 , V_20 ,
! ( V_20 & ( V_71 | V_73 ) ) ,
1 , V_23 ) ;
if ( V_21 ) {
F_42 ( L_6 , V_38 ) ;
return V_21 ;
}
F_17 ( & V_40 -> V_24 -> V_25 , V_19 ) ;
V_20 = F_3 ( V_40 -> V_5 ) ;
F_18 () ;
if ( V_40 -> V_46 )
V_70 = V_40 -> V_46 [ V_70 ] ;
V_20 &= ~ ( V_45 << V_44 ) ;
V_20 |= V_70 << V_44 ;
V_20 &= ~ ( V_54 << V_56 ) ;
V_20 |= V_48 << V_56 ;
F_5 ( V_20 , V_40 -> V_5 ) ;
V_20 = F_3 ( V_40 -> V_5 + V_57 ) ;
V_20 &= ~ ( V_59 << V_58 ) ;
V_20 |= V_72 << V_58 ;
F_5 ( V_20 , V_40 -> V_5 + V_57 ) ;
F_5 ( V_41 | V_73 , F_6 ( V_40 -> V_5 ) ) ;
V_21 = F_47 ( V_40 -> V_5 , V_20 , ! ( V_20 & V_73 ) ,
1 , V_23 ) ;
F_5 ( V_41 , F_8 ( V_40 -> V_5 ) ) ;
F_19 ( & V_40 -> V_24 -> V_25 , V_19 ) ;
return V_21 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_8 )
{
T_2 V_70 = F_32 ( V_2 ) ;
return F_46 ( V_2 , V_7 , V_8 , V_70 ) ;
}
struct V_27 * F_49 ( const struct V_74 * V_75 ,
struct V_30 * V_24 )
{
struct V_39 * V_40 ;
struct V_27 * V_27 ;
V_40 = F_21 ( V_24 -> V_32 , sizeof( * V_40 ) , V_33 ) ;
if ( ! V_40 )
return F_22 ( - V_34 ) ;
V_40 -> V_24 = V_24 ;
V_40 -> V_2 . V_35 = & V_75 -> V_36 ;
V_40 -> V_5 = V_75 -> V_5 + V_24 -> V_37 ;
V_40 -> V_46 = V_75 -> V_46 ;
V_27 = F_23 ( V_24 -> V_32 , & V_40 -> V_2 ) ;
if ( F_24 ( V_27 ) )
F_25 ( V_24 -> V_32 , L_1 , V_38 ) ;
return V_27 ;
}
static inline T_1 F_50 ( T_1 V_76 )
{
V_76 = F_10 ( V_76 , V_77 , V_78 ) ;
return 1 << V_76 ;
}
static unsigned long F_51 ( struct V_79 * V_80 ,
unsigned long V_7 ,
unsigned long V_8 ,
T_1 * V_81 , T_1 * V_82 )
{
T_1 V_83 , div , V_84 = 1 , V_85 = 1 ;
unsigned long V_86 , V_13 = V_7 ;
unsigned int V_65 = - 1 , V_64 , V_87 = 0 ;
T_3 V_50 ;
V_8 /= V_80 -> V_88 ;
for ( V_83 = 1 ; V_83 <= V_89 ; V_83 ++ ) {
for ( div = V_77 ; div <= V_78 ; div ++ ) {
V_50 = V_8 ;
V_50 *= V_83 ;
F_35 ( V_50 , 1 << div ) ;
V_86 = V_50 ;
V_64 = abs ( V_7 - V_86 ) ;
if ( ( V_86 >= V_7 ) && ( V_64 < V_65 ) ) {
V_65 = V_64 ;
V_13 = V_86 ;
V_84 = V_83 ;
V_85 = div ;
V_87 = 1 ;
}
}
}
if ( ! V_87 ) {
F_52 ( L_7 ) ;
return 0 ;
}
F_44 ( L_8 ,
V_7 , V_8 , V_84 , V_85 , V_13 ) ;
if ( V_81 )
* V_81 = V_84 - 1 ;
if ( V_82 )
* V_82 = V_85 ;
return V_13 ;
}
static unsigned long F_53 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
struct V_79 * V_80 = F_54 ( V_2 ) ;
unsigned long V_90 ;
T_1 V_91 , V_76 , div , V_20 ;
T_3 V_50 ;
V_20 = F_3 ( V_80 -> V_5 ) ;
V_76 = ( ( V_20 >> V_92 ) & V_93 ) ;
V_91 = ( ( V_20 >> V_94 ) & V_95 ) + 1 ;
div = F_50 ( V_76 ) ;
V_90 = V_8 / V_80 -> V_88 ;
V_50 = V_90 ;
V_50 *= V_91 ;
F_35 ( V_50 , div ) ;
return V_50 ;
}
static long F_55 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long * V_8 )
{
struct V_79 * V_80 = F_54 ( V_2 ) ;
return F_51 ( V_80 , V_7 , * V_8 , NULL , NULL ) ;
}
static int F_56 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long V_8 )
{
struct V_79 * V_80 = F_54 ( V_2 ) ;
unsigned long V_96 , V_19 ;
T_1 V_91 , V_76 , V_20 ;
int V_21 ;
V_96 = F_51 ( V_80 , V_7 , V_8 , & V_91 , & V_76 ) ;
if ( ! V_96 )
return - V_47 ;
if ( F_57 ( F_58 ( V_97 ) == V_2 ) ) {
F_42 ( L_9 , V_38 ) ;
return - V_26 ;
}
F_17 ( & V_80 -> V_24 -> V_25 , V_19 ) ;
V_20 = F_3 ( V_80 -> V_5 ) ;
V_20 &= ~ ( V_95 << V_94 ) ;
V_20 &= ~ ( V_93 << V_92 ) ;
V_20 |= ( V_91 << V_94 ) | ( V_76 << V_92 ) ;
F_18 () ;
F_5 ( V_20 , V_80 -> V_5 ) ;
F_59 () ;
F_60 () ;
F_60 () ;
V_21 = F_47 ( V_80 -> V_98 , V_20 ,
V_20 & V_80 -> V_99 , 1 , 100 ) ;
F_19 ( & V_80 -> V_24 -> V_25 , V_19 ) ;
return V_21 ;
}
struct V_27 * F_61 ( const struct V_100 * V_75 ,
struct V_30 * V_24 )
{
struct V_79 * V_101 ;
struct V_27 * V_27 ;
V_101 = F_21 ( V_24 -> V_32 , sizeof( * V_101 ) , V_33 ) ;
if ( ! V_101 )
return F_22 ( - V_34 ) ;
V_101 -> V_24 = V_24 ;
V_101 -> V_2 . V_35 = & V_75 -> V_36 ;
V_101 -> V_5 = V_75 -> V_5 + V_24 -> V_37 ;
V_101 -> V_98 = V_75 -> V_98 + V_24 -> V_37 ;
V_101 -> V_99 = V_75 -> V_99 ;
V_101 -> V_88 = ( F_3 ( V_101 -> V_5 ) >> V_102 ) & V_103 ;
V_101 -> V_88 += 1 ;
V_27 = F_23 ( V_24 -> V_32 , & V_101 -> V_2 ) ;
if ( F_24 ( V_27 ) )
F_25 ( V_24 -> V_32 , L_10 ) ;
return V_27 ;
}
static unsigned long F_62 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_104 * V_105 = F_63 ( V_2 ) ;
T_1 div ;
div = ( F_3 ( V_105 -> V_106 ) >> V_107 ) & V_108 ;
div += 1 ;
return V_8 / div ;
}
static long F_64 ( struct V_1 * V_2 , unsigned long V_7 ,
unsigned long * V_8 )
{
return F_9 ( V_7 , * V_8 , V_108 , 1 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
unsigned long V_7 , unsigned long V_8 )
{
struct V_104 * V_105 = F_63 ( V_2 ) ;
unsigned long V_19 ;
T_1 V_20 , div ;
int V_21 ;
div = V_8 / V_7 ;
F_17 ( & V_105 -> V_24 -> V_25 , V_19 ) ;
V_20 = F_3 ( V_105 -> V_106 ) ;
V_20 &= ~ ( V_108 << V_107 ) ;
V_20 |= ( div - 1 ) << V_107 ;
F_18 () ;
F_5 ( V_20 , V_105 -> V_106 ) ;
V_21 = F_47 ( V_105 -> V_106 , V_20 ,
! ( V_20 & V_109 ) , 1 , V_23 ) ;
F_19 ( & V_105 -> V_24 -> V_25 , V_19 ) ;
return V_21 ;
}
static T_2 F_66 ( struct V_1 * V_2 )
{
struct V_104 * V_105 = F_63 ( V_2 ) ;
T_1 V_43 , V_20 ;
V_20 = ( F_3 ( V_105 -> V_110 ) >> V_111 ) & V_112 ;
if ( ! V_105 -> V_46 )
return V_20 ;
for ( V_43 = 0 ; V_43 < F_33 ( V_2 ) ; V_43 ++ )
if ( V_105 -> V_46 [ V_43 ] == V_20 )
return V_43 ;
return - V_47 ;
}
static int F_67 ( struct V_1 * V_2 , T_2 V_70 )
{
struct V_104 * V_105 = F_63 ( V_2 ) ;
unsigned long V_19 ;
T_1 V_113 , V_114 , V_20 ;
int V_21 ;
F_17 ( & V_105 -> V_24 -> V_25 , V_19 ) ;
V_113 = V_105 -> V_46 ? V_105 -> V_46 [ V_70 ] : V_70 ;
V_20 = F_3 ( V_105 -> V_110 ) ;
V_20 &= ~ ( V_115 << V_116 ) ;
V_20 |= V_113 << V_116 ;
F_18 () ;
F_5 ( V_20 , V_105 -> V_110 ) ;
F_5 ( V_117 , F_6 ( V_105 -> V_110 ) ) ;
F_59 () ;
F_60 () ;
V_21 = F_47 ( V_105 -> V_106 , V_20 ,
! ( V_20 & V_117 ) , 1 , V_23 ) ;
F_19 ( & V_105 -> V_24 -> V_25 , V_19 ) ;
V_114 = ( F_3 ( V_105 -> V_110 ) >> V_111 ) & V_112 ;
if ( V_114 != V_113 ) {
F_42 ( L_11 ,
F_43 ( V_2 ) , V_113 , V_114 ) ;
V_21 = - V_26 ;
}
return V_21 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_104 * V_105 = F_63 ( V_2 ) ;
unsigned long V_19 ;
T_1 V_20 ;
V_97 = V_2 ;
if ( V_105 -> V_118 ) {
F_17 ( & V_105 -> V_24 -> V_25 , V_19 ) ;
V_20 = F_3 ( V_105 -> V_106 ) ;
V_20 &= ~ ( V_119 << V_120 ) ;
V_20 |= V_105 -> V_118 << V_120 ;
V_20 |= V_121 | V_122 ;
F_5 ( V_20 , V_105 -> V_106 ) ;
F_19 ( & V_105 -> V_24 -> V_25 , V_19 ) ;
}
}
struct V_27 * F_69 ( const struct V_123 * V_75 ,
struct V_30 * V_24 )
{
struct V_104 * V_105 ;
struct V_27 * V_27 ;
V_105 = F_21 ( V_24 -> V_32 , sizeof( * V_105 ) , V_33 ) ;
if ( ! V_105 )
return F_22 ( - V_34 ) ;
V_105 -> V_24 = V_24 ;
V_105 -> V_2 . V_35 = & V_75 -> V_36 ;
V_105 -> V_110 = V_75 -> V_110 + V_24 -> V_37 ;
V_105 -> V_106 = V_75 -> V_106 + V_24 -> V_37 ;
V_105 -> V_118 = V_75 -> V_118 ;
V_105 -> V_46 = V_75 -> V_46 ;
V_27 = F_23 ( V_24 -> V_32 , & V_105 -> V_2 ) ;
if ( F_24 ( V_27 ) )
F_25 ( V_24 -> V_32 , L_12 , V_38 ) ;
return V_27 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = F_71 ( V_2 ) ;
T_1 V_20 ;
F_18 () ;
F_5 ( V_125 -> V_126 , F_6 ( V_125 -> V_127 ) ) ;
return F_47 ( V_125 -> V_98 , V_20 ,
V_20 & V_125 -> V_128 , 1 , 100 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = F_71 ( V_2 ) ;
F_18 () ;
F_5 ( V_125 -> V_126 , F_8 ( V_125 -> V_127 ) ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = F_71 ( V_2 ) ;
T_1 V_129 , V_130 ;
V_129 = F_3 ( V_125 -> V_127 ) & V_125 -> V_126 ;
V_130 = F_3 ( V_125 -> V_98 ) & V_125 -> V_128 ;
return V_129 && V_130 ;
}
static unsigned long F_74 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
return F_71 ( V_2 ) -> V_131 ;
}
struct V_27 * F_75 ( const struct V_132 * V_75 ,
struct V_30 * V_24 )
{
struct V_124 * V_125 ;
V_125 = F_21 ( V_24 -> V_32 , sizeof( * V_125 ) , V_33 ) ;
if ( ! V_125 )
return F_22 ( - V_34 ) ;
V_125 -> V_24 = V_24 ;
V_125 -> V_2 . V_35 = & V_75 -> V_36 ;
V_125 -> V_131 = V_75 -> V_131 ;
V_125 -> V_126 = V_75 -> V_126 ;
V_125 -> V_128 = V_75 -> V_128 ;
V_125 -> V_127 = V_75 -> V_127 + V_24 -> V_37 ;
V_125 -> V_98 = V_75 -> V_98 + V_24 -> V_37 ;
return F_23 ( V_24 -> V_32 , & V_125 -> V_2 ) ;
}
