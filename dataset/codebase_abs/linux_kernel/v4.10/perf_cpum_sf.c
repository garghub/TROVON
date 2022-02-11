static inline int F_1 ( const void * V_1 )
{
return ( ( unsigned long ) V_1 & ~ V_2 ) == V_3 ;
}
static int F_2 ( void )
{
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
return F_3 ( & V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 )
{
return ! ! V_7 -> V_8 . V_1 ;
}
static void F_5 ( struct V_9 * V_8 )
{
unsigned long * V_1 , * V_10 ;
if ( ! V_8 -> V_1 )
return;
V_1 = V_8 -> V_1 ;
V_10 = V_1 ;
while ( 1 ) {
if ( ! * V_10 || ! V_1 )
break;
if ( F_6 ( V_10 ) ) {
V_10 = F_7 ( V_10 ) ;
if ( V_1 )
F_8 ( ( unsigned long ) V_1 ) ;
if ( V_10 == V_8 -> V_1 )
break;
else
V_1 = V_10 ;
} else {
if ( * V_10 ) {
F_8 ( * V_10 ) ;
V_10 ++ ;
}
}
}
F_9 ( V_11 , 5 ,
L_1 , V_8 -> V_1 ) ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
}
static int F_10 ( unsigned long * V_1 , T_1 V_12 )
{
unsigned long V_13 , * V_14 ;
V_13 = F_11 ( V_12 ) ;
if ( ! V_13 )
return - V_15 ;
V_14 = F_12 ( V_13 ) ;
* V_14 = V_16 ;
* V_1 = V_13 ;
return 0 ;
}
static int F_13 ( struct V_9 * V_8 ,
unsigned long V_17 , T_1 V_12 )
{
int V_18 , V_19 ;
unsigned long * V_20 , * V_21 ;
if ( ! V_8 -> V_1 || ! V_8 -> V_21 )
return - V_22 ;
if ( ! F_6 ( V_8 -> V_21 ) )
return - V_22 ;
V_21 = V_8 -> V_21 ;
if ( V_8 -> V_1 != F_7 ( V_21 ) ) {
F_9 ( V_11 , 3 , L_2
L_3
L_4 ,
( void * ) V_8 -> V_1 , ( void * ) V_21 ) ;
return - V_22 ;
}
V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
if ( F_1 ( V_21 ) ) {
V_20 = ( unsigned long * ) F_11 ( V_12 ) ;
if ( ! V_20 ) {
V_19 = - V_15 ;
break;
}
V_8 -> V_23 ++ ;
* V_21 = ( unsigned long ) ( void * ) V_20 + 1 ;
V_21 = V_20 ;
}
V_19 = F_10 ( V_21 , V_12 ) ;
if ( V_19 )
break;
V_8 -> V_17 ++ ;
V_21 ++ ;
}
* V_21 = ( unsigned long ) V_8 -> V_1 + 1 ;
V_8 -> V_21 = V_21 ;
F_9 ( V_11 , 4 , L_5
L_6 ,
V_8 -> V_23 , V_8 -> V_17 ) ;
return V_19 ;
}
static int F_14 ( struct V_9 * V_8 , unsigned long V_17 )
{
int V_19 ;
if ( V_8 -> V_1 )
return - V_22 ;
V_8 -> V_1 = ( unsigned long * ) F_11 ( V_24 ) ;
if ( ! V_8 -> V_1 )
return - V_15 ;
V_8 -> V_17 = 0 ;
V_8 -> V_23 = 1 ;
V_8 -> V_21 = V_8 -> V_1 ;
* V_8 -> V_21 = ( unsigned long ) ( void * ) V_8 -> V_1 + 1 ;
V_19 = F_13 ( V_8 , V_17 , V_24 ) ;
if ( V_19 ) {
F_5 ( V_8 ) ;
F_9 ( V_11 , 4 , L_7
L_8 , V_19 ) ;
} else
F_9 ( V_11 , 4 ,
L_9 ,
V_8 -> V_1 , ( void * ) * V_8 -> V_1 ) ;
return V_19 ;
}
static void F_15 ( unsigned long V_25 , unsigned long V_26 )
{
struct V_27 V_28 ;
V_29 = V_25 ;
V_30 = V_26 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
if ( ! F_16 ( & V_28 ) )
V_31 = F_17 ( V_28 . V_32 , V_28 . V_33 ) ;
}
static unsigned long F_18 ( struct V_34 * V_35 )
{
return F_19 ( V_35 ) ? V_30 * V_31
: V_30 ;
}
static unsigned long F_20 ( struct V_9 * V_8 ,
struct V_34 * V_35 )
{
if ( ! V_8 -> V_1 )
return F_21 ( V_35 ) ;
if ( F_21 ( V_35 ) > V_8 -> V_17 )
return F_21 ( V_35 ) - V_8 -> V_17 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_8 ,
struct V_34 * V_35 )
{
return F_20 ( V_8 , V_35 ) > 0 ;
}
static void F_23 ( unsigned long V_36 , struct V_34 * V_35 )
{
V_36 = F_24 (unsigned long, num, sfb_max_limit(hwc) - SFB_ALLOC_REG(hwc)) ;
if ( V_36 )
F_21 ( V_35 ) += V_36 ;
}
static void F_25 ( unsigned long V_36 , struct V_34 * V_35 )
{
F_21 ( V_35 ) = 0 ;
F_23 ( V_36 , V_35 ) ;
}
static T_2 F_26 ( struct V_34 * V_35 )
{
struct V_37 * V_38 = (struct V_37 * ) F_27 ( V_35 ) ;
T_2 V_39 ;
V_39 = V_38 -> V_33 ;
if ( F_19 ( V_35 ) )
V_39 += V_38 -> V_32 ;
return V_39 ;
}
static void F_28 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 . V_1 )
F_5 ( & V_7 -> V_8 ) ;
}
static int F_29 ( struct V_6 * V_7 , struct V_34 * V_35 )
{
unsigned long V_40 , V_41 , V_42 ;
T_2 V_43 , V_39 ;
struct V_37 * V_38 ;
V_43 = F_30 ( ( sizeof( * V_38 ) - sizeof( V_38 -> V_44 ) + V_7 -> F_16 . V_32 ) +
sizeof( V_45 ) , sizeof( V_46 ) ) ;
V_43 -= sizeof( V_45 ) ;
V_38 = F_31 ( V_43 , V_24 ) ;
if ( ! V_38 )
return - V_15 ;
V_38 -> V_47 = V_43 ;
V_38 -> V_33 = V_7 -> F_16 . V_33 ;
V_38 -> V_32 = V_7 -> F_16 . V_32 ;
F_27 ( V_35 ) = ( unsigned long ) V_38 ;
V_39 = F_26 ( V_35 ) ;
V_41 = F_32 ( & V_7 -> F_16 , F_33 ( V_35 ) ) ;
V_42 = 1 ;
V_40 = F_17 ( V_41 , V_42 * ( ( V_48 - 64 ) / V_39 ) ) ;
if ( V_40 < V_29 )
V_40 = V_29 ;
F_25 ( V_40 , V_35 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
F_9 ( V_11 , 3 ,
L_10
L_11 ,
F_33 ( V_35 ) , V_41 , V_40 , F_18 ( V_35 ) ,
V_39 , V_7 ) ;
return F_14 ( & V_7 -> V_8 ,
F_20 ( & V_7 -> V_8 , V_35 ) ) ;
}
static unsigned long F_34 ( unsigned int V_49 , unsigned long V_50 ,
unsigned long V_25 )
{
return F_24 (unsigned long, min, DIV_ROUND_UP(percent * base, 100)) ;
}
static unsigned long F_35 ( unsigned long V_51 , unsigned long V_50 )
{
if ( V_51 <= 5 )
return 0 ;
if ( V_51 <= 25 )
return F_34 ( 1 , V_50 , 1 ) ;
if ( V_51 <= 50 )
return F_34 ( 1 , V_50 , 1 ) ;
if ( V_51 <= 75 )
return F_34 ( 2 , V_50 , 2 ) ;
if ( V_51 <= 100 )
return F_34 ( 3 , V_50 , 3 ) ;
if ( V_51 <= 250 )
return F_34 ( 4 , V_50 , 4 ) ;
return F_34 ( 5 , V_50 , 8 ) ;
}
static void F_36 ( struct V_6 * V_7 ,
struct V_34 * V_35 )
{
unsigned long V_51 , V_36 ;
if ( ! F_37 ( V_35 ) )
return;
V_51 = F_17 ( 100 * F_37 ( V_35 ) * V_7 -> V_8 . V_17 ,
F_32 ( & V_7 -> F_16 , F_33 ( V_35 ) ) ) ;
V_36 = F_35 ( V_51 , V_7 -> V_8 . V_17 ) ;
if ( V_36 )
F_23 ( V_36 , V_35 ) ;
F_9 ( V_11 , 5 , L_12
L_13 , F_37 ( V_35 ) , V_51 , V_36 ) ;
F_37 ( V_35 ) = 0 ;
}
static void F_38 ( struct V_9 * V_8 ,
struct V_34 * V_35 )
{
unsigned long V_36 , V_52 ;
int V_19 ;
V_36 = F_20 ( V_8 , V_35 ) ;
if ( ! V_36 )
return;
V_52 = V_8 -> V_17 ;
F_2 () ;
V_19 = F_13 ( V_8 , V_36 , V_53 ) ;
if ( V_19 )
F_9 ( V_11 , 5 , L_14
L_15 , V_19 ) ;
if ( F_22 ( V_8 , V_35 ) )
F_9 ( V_11 , 5 , L_16
L_17 ,
V_36 , V_8 -> V_17 - V_52 ,
F_20 ( V_8 , V_35 ) ) ;
}
static void F_39 ( void * V_54 )
{
int V_55 ;
struct V_6 * V_56 = F_40 ( & V_6 ) ;
V_55 = 0 ;
switch ( * ( ( int * ) V_54 ) ) {
case V_57 :
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_55 = F_16 ( & V_56 -> F_16 ) ;
if ( V_55 )
break;
V_56 -> V_54 |= V_58 ;
V_55 = F_2 () ;
if ( V_55 )
F_41 ( L_18
L_19 , V_55 ) ;
F_9 ( V_11 , 5 ,
L_20 , V_56 ) ;
break;
case V_59 :
V_56 -> V_54 &= ~ V_58 ;
V_55 = F_2 () ;
if ( V_55 ) {
F_41 ( L_18
L_19 , V_55 ) ;
} else
F_28 ( V_56 ) ;
F_9 ( V_11 , 5 ,
L_21 , V_56 ) ;
break;
}
if ( V_55 )
* ( ( int * ) V_54 ) |= V_60 ;
}
static void F_42 ( void )
{
int V_54 = V_59 ;
F_43 ( V_61 ) ;
F_44 ( F_39 , & V_54 , 1 ) ;
}
static int F_45 ( void )
{
int V_54 = V_57 ;
F_44 ( F_39 , & V_54 , 1 ) ;
if ( V_54 & V_60 ) {
F_42 () ;
return - V_62 ;
}
F_46 ( V_61 ) ;
return 0 ;
}
static void F_47 ( struct V_63 * V_64 )
{
if ( F_27 ( & V_64 -> V_65 ) )
F_48 ( ( void * ) F_27 ( & V_64 -> V_65 ) ) ;
if ( ! F_49 ( & V_66 , - 1 , 1 ) ) {
F_50 ( & V_67 ) ;
if ( F_51 ( & V_66 ) == 0 )
F_42 () ;
F_52 ( & V_67 ) ;
}
}
static void F_53 ( struct V_34 * V_35 , V_46 V_68 )
{
V_35 -> V_69 = V_68 ;
V_35 -> V_70 = V_35 -> V_69 ;
F_54 ( & V_35 -> V_71 , V_35 -> V_69 ) ;
}
static void F_55 ( struct V_34 * V_35 ,
unsigned long * V_72 )
{
struct V_37 * V_38 ;
F_56 ( V_35 ) = ( unsigned long ) V_72 ;
V_38 = (struct V_37 * ) F_27 ( V_35 ) ;
memset ( & V_38 -> V_73 , 0 , sizeof( V_38 -> V_73 ) ) ;
memset ( & V_38 -> V_44 , 0 , V_38 -> V_32 ) ;
}
static unsigned long F_57 ( const struct V_27 * V_28 ,
unsigned long V_74 )
{
return F_58 (unsigned long, rate,
si->min_sampl_rate, si->max_sampl_rate) ;
}
static int F_59 ( struct V_63 * V_64 )
{
struct V_6 * V_7 ;
struct V_27 V_28 ;
struct V_75 * V_76 = & V_64 -> V_76 ;
struct V_34 * V_35 = & V_64 -> V_65 ;
unsigned long V_74 ;
int V_77 , V_55 ;
V_55 = 0 ;
if ( ! F_60 ( & V_66 ) ) {
F_50 ( & V_67 ) ;
if ( F_61 ( & V_66 ) == 0 && F_45 () )
V_55 = - V_78 ;
else
F_62 ( & V_66 ) ;
F_52 ( & V_67 ) ;
}
V_64 -> V_79 = F_47 ;
if ( V_55 )
goto V_80;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_7 = NULL ;
if ( V_64 -> V_77 == - 1 )
F_16 ( & V_28 ) ;
else {
V_7 = & F_63 ( V_6 , V_64 -> V_77 ) ;
V_28 = V_7 -> F_16 ;
}
if ( ! V_28 . V_81 ) {
V_55 = - V_82 ;
goto V_80;
}
F_64 ( V_35 ) = V_83 ;
if ( V_76 -> V_84 == V_85 ) {
if ( ! V_28 . V_86 ) {
V_55 = - V_87 ;
goto V_80;
}
F_64 ( V_35 ) |= V_88 ;
}
if ( V_76 -> V_89 & V_90 )
F_64 ( V_35 ) |= V_90 ;
V_74 = 0 ;
if ( V_76 -> V_41 ) {
V_74 = F_65 ( & V_28 , V_76 -> V_91 ) ;
V_74 = F_57 ( & V_28 , V_74 ) ;
V_76 -> V_41 = 0 ;
V_76 -> V_69 = V_74 ;
} else {
V_74 = F_57 ( & V_28 , V_35 -> V_69 ) ;
if ( F_32 ( & V_28 , V_74 ) >
V_92 ) {
V_55 = - V_22 ;
F_9 ( V_11 , 1 , L_22 ) ;
goto V_80;
}
}
F_33 ( V_35 ) = V_74 ;
F_53 ( V_35 , F_33 ( V_35 ) ) ;
V_35 -> V_93 . V_94 = V_95 ;
F_37 ( V_35 ) = 0 ;
if ( V_7 )
V_55 = F_29 ( V_7 , V_35 ) ;
else {
F_66 (cpu) {
V_7 = & F_63 ( V_6 , V_77 ) ;
V_55 = F_29 ( V_7 , V_35 ) ;
if ( V_55 )
break;
}
}
V_80:
return V_55 ;
}
static int F_67 ( struct V_63 * V_64 )
{
int V_55 ;
if ( F_68 ( V_64 ) )
return - V_96 ;
switch ( V_64 -> V_76 . type ) {
case V_97 :
if ( ( V_64 -> V_76 . V_84 != V_98 ) &&
( V_64 -> V_76 . V_84 != V_85 ) )
return - V_82 ;
break;
case V_99 :
if ( V_64 -> V_76 . V_84 != V_100 )
return - V_82 ;
if ( ! F_69 ( V_64 ) )
return - V_82 ;
break;
default:
return - V_82 ;
}
if ( V_64 -> V_77 >= V_101 ||
( V_64 -> V_77 >= 0 && ! F_70 ( V_64 -> V_77 ) ) )
return - V_62 ;
if ( V_64 -> V_76 . V_102 )
V_64 -> V_76 . V_102 = 0 ;
if ( V_64 -> V_76 . V_103 )
V_64 -> V_76 . V_103 = 0 ;
V_55 = F_59 ( V_64 ) ;
if ( F_71 ( V_55 ) )
if ( V_64 -> V_79 )
V_64 -> V_79 ( V_64 ) ;
return V_55 ;
}
static void F_72 ( struct V_104 * V_104 )
{
struct V_6 * V_7 = F_40 ( & V_6 ) ;
struct V_34 * V_35 ;
int V_55 ;
if ( V_7 -> V_54 & V_105 )
return;
if ( V_7 -> V_54 & V_106 )
return;
if ( V_7 -> V_64 ) {
V_35 = & V_7 -> V_64 -> V_65 ;
F_36 ( V_7 , V_35 ) ;
if ( F_22 ( & V_7 -> V_8 , V_35 ) )
F_38 ( & V_7 -> V_8 , V_35 ) ;
}
V_7 -> V_54 |= V_105 ;
F_73 () ;
V_55 = F_3 ( & V_7 -> F_3 ) ;
if ( V_55 ) {
V_7 -> V_54 &= ~ V_105 ;
F_41 ( L_23 ,
1 , V_55 ) ;
return;
}
F_9 ( V_11 , 6 , L_24
L_25 , V_7 -> F_3 . V_107 , V_7 -> F_3 . V_108 ,
V_7 -> F_3 . V_109 , V_7 -> F_3 . V_110 ,
( void * ) V_7 -> F_3 . V_111 , ( void * ) V_7 -> F_3 . V_112 ) ;
}
static void F_74 ( struct V_104 * V_104 )
{
struct V_6 * V_7 = F_40 ( & V_6 ) ;
struct V_4 V_113 ;
struct V_27 V_28 ;
int V_55 ;
if ( ! ( V_7 -> V_54 & V_105 ) )
return;
if ( V_7 -> V_54 & V_106 )
return;
V_113 = V_7 -> F_3 ;
V_113 . V_108 = 0 ;
V_113 . V_110 = 0 ;
V_55 = F_3 ( & V_113 ) ;
if ( V_55 ) {
F_41 ( L_23 ,
2 , V_55 ) ;
return;
}
if ( ! F_16 ( & V_28 ) ) {
if ( V_28 . V_107 ) {
V_7 -> F_3 . V_111 = V_28 . V_111 ;
V_7 -> F_3 . V_112 = V_28 . V_112 ;
}
} else
F_9 ( V_11 , 3 , L_26
L_27 , V_55 ) ;
V_7 -> V_54 &= ~ V_105 ;
}
static int F_75 ( struct V_63 * V_64 , struct V_114 * V_115 ,
struct V_116 * V_117 )
{
if ( V_64 -> V_76 . V_118 && F_76 ( V_115 ) )
return 1 ;
if ( V_64 -> V_76 . V_119 && ! F_76 ( V_115 ) )
return 1 ;
if ( V_64 -> V_76 . V_120 && V_117 -> V_121 )
return 1 ;
if ( V_64 -> V_76 . V_122 && ! V_117 -> V_121 )
return 1 ;
return 0 ;
}
static int F_77 ( struct V_63 * V_64 , struct V_37 * V_38 )
{
int V_123 ;
struct V_114 V_115 ;
struct V_116 * V_117 ;
struct V_124 V_125 ;
struct V_126 V_127 = {
. V_128 = {
. V_47 = V_38 -> V_47 ,
. V_125 = V_38 ,
} ,
} ;
F_78 ( & V_125 , 0 , V_64 -> V_65 . V_70 ) ;
V_125 . V_127 = & V_127 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_129 = 0x1407 ;
V_115 . V_130 = V_131 ;
V_117 = (struct V_116 * ) & V_115 . V_132 ;
F_79 ( V_115 . V_133 ) . V_134 = V_38 -> V_73 . V_134 ;
F_79 ( V_115 . V_133 ) . V_135 = V_38 -> V_73 . V_136 ;
F_79 ( V_115 . V_133 ) . V_137 = V_38 -> V_73 . V_138 ;
F_79 ( V_115 . V_133 ) . V_139 = V_38 -> V_73 . V_140 ;
F_79 ( V_115 . V_133 ) . V_81 = V_38 -> V_73 . V_141 ;
switch ( V_38 -> V_73 . V_142 ) {
case 1 :
V_117 -> V_121 = 0 ;
break;
case 2 :
V_117 -> V_121 = 1 ;
break;
default:
if ( V_38 -> V_73 . V_143 ||
V_38 -> V_73 . V_144 != ( V_145 ) V_38 -> V_73 . V_146 )
V_117 -> V_121 = 1 ;
break;
}
V_123 = 0 ;
if ( F_75 ( V_64 , & V_115 , V_117 ) )
goto V_80;
if ( F_80 ( V_64 , & V_125 , & V_115 ) ) {
V_123 = 1 ;
V_64 -> V_104 -> V_147 ( V_64 , 0 ) ;
}
F_81 ( V_64 ) ;
V_80:
return V_123 ;
}
static void F_82 ( struct V_63 * V_64 , V_46 V_148 )
{
F_83 ( V_148 , & V_64 -> V_148 ) ;
}
static int F_84 ( struct V_149 * V_150 ,
unsigned int V_54 )
{
if ( F_85 ( V_54 & V_83 ) )
if ( V_150 -> V_73 . V_151 != 0x0001 )
return 0 ;
if ( V_54 & V_88 )
if ( V_150 -> V_44 . V_151 < 0x8001 )
return 0 ;
return 1 ;
}
static int F_86 ( struct V_149 * V_150 ,
unsigned long V_54 )
{
if ( F_71 ( ! ( V_54 & V_83 ) ) )
return 0 ;
if ( V_150 -> V_73 . V_152 || V_150 -> V_73 . V_138 )
return 0 ;
return 1 ;
}
static void F_87 ( struct V_149 * V_150 ,
unsigned long V_54 )
{
if ( F_85 ( V_54 & V_83 ) )
V_150 -> V_73 . V_151 = 0 ;
if ( V_54 & V_88 )
V_150 -> V_44 . V_151 = 0 ;
}
static void F_88 ( struct V_37 * V_38 ,
struct V_149 * V_150 )
{
if ( F_85 ( V_38 -> V_153 & V_83 ) )
V_38 -> V_73 = V_150 -> V_73 ;
if ( V_38 -> V_153 & V_88 )
memcpy ( & V_38 -> V_44 , & V_150 -> V_44 , V_38 -> V_32 ) ;
}
static void F_89 ( struct V_149 * V_150 ,
struct V_154 * V_155 ,
unsigned long V_54 )
{
F_9 ( V_11 , 4 , L_28
L_29
L_30 , V_155 -> V_156 ,
V_150 -> V_73 . V_151 , & V_150 -> V_73 ,
( V_54 & V_88 )
? V_150 -> V_44 . V_151 : 0xFFFF ,
( V_54 & V_88 )
? & V_150 -> V_44 : NULL ) ;
}
static void F_90 ( struct V_63 * V_64 , unsigned long * V_1 ,
unsigned long long * V_123 )
{
unsigned long V_54 = F_64 ( & V_64 -> V_65 ) ;
struct V_149 * V_150 ;
struct V_154 * V_155 ;
struct V_37 * V_38 ;
T_2 V_39 ;
V_38 = (struct V_37 * ) F_27 ( & V_64 -> V_65 ) ;
V_38 -> V_153 = V_54 & V_157 ;
V_39 = F_26 ( & V_64 -> V_65 ) ;
V_155 = (struct V_154 * ) F_12 ( * V_1 ) ;
V_150 = (struct V_149 * ) * V_1 ;
while ( ( unsigned long * ) V_150 < ( unsigned long * ) V_155 ) {
if ( ! V_150 -> V_73 . V_151 )
break;
F_82 ( V_64 , F_33 ( & V_64 -> V_65 ) ) ;
if ( F_84 ( V_150 , V_54 ) ) {
if ( ! * V_123 ) {
if ( F_86 ( V_150 , V_54 ) ) {
F_88 ( V_38 , V_150 ) ;
* V_123 = F_77 ( V_64 , V_38 ) ;
}
} else
* V_123 += 1 ;
} else {
F_89 ( V_150 , V_155 , V_54 ) ;
if ( ! V_155 -> V_156 )
break;
}
F_87 ( V_150 , V_54 ) ;
V_150 += V_39 ;
}
}
static void F_91 ( struct V_63 * V_64 , int V_158 )
{
struct V_34 * V_35 = & V_64 -> V_65 ;
struct V_154 * V_155 ;
unsigned long * V_1 ;
unsigned long long V_159 , V_160 , V_17 , V_161 ;
int V_162 ;
if ( V_158 && F_92 ( V_35 ) )
V_158 = 0 ;
V_1 = ( unsigned long * ) F_56 ( V_35 ) ;
V_162 = V_159 = V_160 = V_17 = 0 ;
while ( ! V_162 ) {
V_155 = (struct V_154 * ) F_12 ( * V_1 ) ;
if ( ! V_155 -> V_156 ) {
V_162 = 1 ;
if ( ! V_158 )
break;
}
if ( V_155 -> V_123 )
V_160 += V_155 -> V_123 ;
F_9 ( V_11 , 6 , L_31
L_32 ,
V_1 , V_155 -> V_123 ,
( V_155 -> V_156 ) ? F_93 ( V_155 ) : 0ULL ) ;
F_90 ( V_64 , V_1 , & V_159 ) ;
V_17 ++ ;
do {
V_161 = V_155 -> V_54 & ~ V_163 ;
V_161 |= V_16 ;
} while ( ! F_94 ( & V_155 -> V_54 , & V_155 -> V_123 ,
V_155 -> V_54 , V_155 -> V_123 ,
V_161 , 0ULL ) );
V_1 ++ ;
if ( F_6 ( V_1 ) )
V_1 = F_7 ( V_1 ) ;
F_56 ( V_35 ) = ( unsigned long ) V_1 ;
if ( V_158 && V_162 )
break;
if ( V_159 )
V_158 = 1 ;
}
if ( V_160 )
F_37 ( V_35 ) = F_17 ( F_37 ( V_35 ) +
V_160 , 1 + V_17 ) ;
if ( V_160 || V_159 )
F_9 ( V_11 , 4 , L_33
L_34 ,
V_160 , V_159 ) ;
}
static void F_95 ( struct V_63 * V_64 )
{
}
static void F_96 ( struct V_63 * V_64 , int V_54 )
{
struct V_6 * V_7 = F_40 ( & V_6 ) ;
if ( F_97 ( ! ( V_64 -> V_65 . V_164 & V_165 ) ) )
return;
if ( V_54 & V_166 )
F_97 ( ! ( V_64 -> V_65 . V_164 & V_167 ) ) ;
F_98 ( V_64 -> V_104 ) ;
V_64 -> V_65 . V_164 = 0 ;
V_7 -> F_3 . V_108 = 1 ;
if ( F_19 ( & V_64 -> V_65 ) )
V_7 -> F_3 . V_110 = 1 ;
F_99 ( V_64 -> V_104 ) ;
}
static void F_100 ( struct V_63 * V_64 , int V_54 )
{
struct V_6 * V_7 = F_40 ( & V_6 ) ;
if ( V_64 -> V_65 . V_164 & V_165 )
return;
F_98 ( V_64 -> V_104 ) ;
V_7 -> F_3 . V_108 = 0 ;
V_7 -> F_3 . V_110 = 0 ;
V_64 -> V_65 . V_164 |= V_165 ;
if ( ( V_54 & V_168 ) && ! ( V_64 -> V_65 . V_164 & V_167 ) ) {
F_91 ( V_64 , 1 ) ;
V_64 -> V_65 . V_164 |= V_167 ;
}
F_99 ( V_64 -> V_104 ) ;
}
static int F_101 ( struct V_63 * V_64 , int V_54 )
{
struct V_6 * V_7 = F_40 ( & V_6 ) ;
int V_55 ;
if ( V_7 -> V_54 & V_169 )
return - V_170 ;
if ( ! V_7 -> V_8 . V_1 )
return - V_22 ;
V_55 = 0 ;
F_98 ( V_64 -> V_104 ) ;
V_64 -> V_65 . V_164 = V_167 | V_165 ;
V_7 -> F_3 . V_171 = 0 ;
V_7 -> F_3 . V_172 = 1 ;
V_7 -> F_3 . V_111 = ( unsigned long ) V_7 -> V_8 . V_1 ;
V_7 -> F_3 . V_112 = * ( unsigned long * ) V_7 -> V_8 . V_1 ;
V_7 -> F_3 . V_173 = F_33 ( & V_64 -> V_65 ) ;
F_55 ( & V_64 -> V_65 , V_7 -> V_8 . V_1 ) ;
if ( F_97 ( V_7 -> F_3 . V_107 == 1 || V_7 -> F_3 . V_109 == 1 ) ) {
V_55 = - V_170 ;
goto V_80;
}
V_7 -> F_3 . V_107 = 1 ;
if ( F_19 ( & V_64 -> V_65 ) )
V_7 -> F_3 . V_109 = 1 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_54 |= V_169 ;
if ( V_54 & V_174 )
F_96 ( V_64 , V_166 ) ;
V_80:
F_81 ( V_64 ) ;
F_99 ( V_64 -> V_104 ) ;
return V_55 ;
}
static void F_102 ( struct V_63 * V_64 , int V_54 )
{
struct V_6 * V_7 = F_40 ( & V_6 ) ;
F_98 ( V_64 -> V_104 ) ;
F_100 ( V_64 , V_168 ) ;
V_7 -> F_3 . V_107 = 0 ;
V_7 -> F_3 . V_109 = 0 ;
V_7 -> V_54 &= ~ V_169 ;
V_7 -> V_64 = NULL ;
F_81 ( V_64 ) ;
F_99 ( V_64 -> V_104 ) ;
}
static void F_103 ( struct V_175 V_175 ,
unsigned int V_176 , unsigned long V_177 )
{
struct V_6 * V_7 ;
if ( ! ( V_176 & V_178 ) )
return;
F_104 ( V_179 ) ;
V_7 = F_40 ( & V_6 ) ;
if ( ! ( V_7 -> V_54 & V_58 ) )
return;
if ( V_176 & V_131 ) {
if ( V_7 -> V_54 & V_169 )
F_91 ( V_7 -> V_64 , 0 ) ;
else
F_97 ( ! ( V_7 -> V_54 & V_169 ) ) ;
}
if ( V_176 != V_131 )
F_9 ( V_11 , 6 , L_35 , V_176 ) ;
if ( V_176 & V_180 )
F_16 ( & V_7 -> F_16 ) ;
if ( V_176 & V_181 ) {
F_41 ( L_36 ) ;
V_7 -> V_54 |= V_182 ;
F_2 () ;
}
if ( V_176 & ( V_183 | V_184 ) ) {
F_41 ( L_37 ,
V_176 ) ;
V_7 -> V_54 |= V_185 ;
F_2 () ;
}
}
static int F_105 ( unsigned int V_77 , int V_54 )
{
if ( ! F_61 ( & V_66 ) )
return 0 ;
F_106 () ;
F_39 ( & V_54 ) ;
F_107 () ;
return 0 ;
}
static int F_108 ( unsigned int V_77 )
{
return F_105 ( V_77 , V_57 ) ;
}
static int F_109 ( unsigned int V_77 )
{
return F_105 ( V_77 , V_59 ) ;
}
static int F_110 ( char * V_186 , const struct V_187 * V_188 )
{
if ( ! F_111 () )
return - V_62 ;
return sprintf ( V_186 , L_38 , V_29 , V_30 ) ;
}
static int F_112 ( const char * V_189 , const struct V_187 * V_188 )
{
int V_19 ;
unsigned long V_25 , V_26 ;
if ( ! F_111 () )
return - V_62 ;
if ( ! V_189 || ! strlen ( V_189 ) )
return - V_22 ;
V_25 = V_29 ;
V_26 = V_30 ;
if ( strchr ( V_189 , ',' ) )
V_19 = ( sscanf ( V_189 , L_38 , & V_25 , & V_26 ) == 2 ) ? 0 : - V_22 ;
else
V_19 = F_113 ( V_189 , 10 , & V_26 ) ;
if ( V_25 < 2 || V_25 >= V_26 || V_26 > F_114 () )
V_19 = - V_22 ;
if ( V_19 )
return V_19 ;
F_15 ( V_25 , V_26 ) ;
F_115 ( L_39
L_40 ,
V_29 , V_30 , V_31 ) ;
return 0 ;
}
static void T_3 F_116 ( unsigned int V_190 )
{
F_41 ( L_41
L_42 , V_190 ) ;
}
static int T_3 F_117 ( void )
{
struct V_27 V_28 ;
int V_55 ;
if ( ! F_111 () )
return - V_62 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
if ( F_16 ( & V_28 ) ) {
F_116 ( V_191 ) ;
return - V_62 ;
}
if ( V_28 . V_33 != sizeof( struct V_192 ) ) {
F_116 ( V_193 ) ;
return - V_22 ;
}
if ( V_28 . V_86 ) {
F_15 ( V_29 , V_30 ) ;
V_194 [ 1 ] =
F_118 ( V_195 , V_196 ) ;
}
V_11 = F_119 ( V_197 , 2 , 1 , 80 ) ;
if ( ! V_11 )
F_41 ( L_43 ) ;
F_120 ( V_11 , & V_198 ) ;
V_55 = F_121 ( V_199 ,
F_103 ) ;
if ( V_55 ) {
F_116 ( V_200 ) ;
goto V_80;
}
V_55 = F_122 ( & V_201 , L_44 , V_97 ) ;
if ( V_55 ) {
F_116 ( V_202 ) ;
F_123 ( V_199 ,
F_103 ) ;
goto V_80;
}
F_124 ( V_203 , L_45 ,
F_108 , F_109 ) ;
V_80:
return V_55 ;
}
