static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
int V_4 = 0 ;
unsigned long V_5 ;
V_4 = F_2 ( V_1 , 10 , & V_5 ) ;
if ( V_4 )
goto exit;
if ( V_5 > 25 || V_5 < 6 ) {
F_3 ( L_1 ,
V_5 ) ;
V_4 = - V_6 ;
}
V_7 = F_4 ( V_5 , 6ul , 25ul ) ;
F_5 () ;
exit:
return V_4 ;
}
static int F_6 ( const char * V_1 , const struct V_2 * V_3 )
{
int V_4 = 0 ;
unsigned long V_8 ;
V_4 = F_2 ( V_1 , 10 , & V_8 ) ;
if ( V_4 )
goto V_9;
if ( V_8 > 10 || V_8 < 2 ) {
F_3 ( L_2 ,
V_8 ) ;
V_4 = - V_6 ;
}
V_10 = F_4 ( V_8 , 2ul , 10ul ) ;
F_5 () ;
V_9:
return V_4 ;
}
static void F_7 ( void )
{
unsigned int V_11 , V_12 , V_13 , V_14 ;
unsigned int V_15 = 0 ;
unsigned int V_16 = 0 ;
int V_17 ;
if ( V_18 . V_19 < V_20 )
return;
F_8 ( V_20 , & V_11 , & V_12 , & V_13 , & V_14 ) ;
if ( ! ( V_13 & V_21 ) ||
! ( V_13 & V_22 ) )
return;
V_14 >>= V_23 ;
for ( V_17 = 0 ; V_17 < 7 && V_14 ; V_17 ++ , V_14 >>= V_23 ) {
if ( V_14 & V_24 ) {
V_15 = V_17 ;
V_16 = V_14 & V_24 ;
}
}
V_25 = ( V_15 << V_23 ) |
( V_16 - 1 ) ;
}
static T_1 F_9 ( void )
{
T_1 V_26 ;
T_1 V_27 = 0 ;
static bool V_28 ;
static bool V_29 ;
static bool V_30 ;
static bool V_31 ;
if ( ! V_28 ) {
if ( ! F_10 ( V_32 , & V_26 ) )
V_27 += V_26 ;
else
V_28 = true ;
}
if ( ! V_29 ) {
if ( ! F_10 ( V_33 , & V_26 ) )
V_27 += V_26 ;
else
V_29 = true ;
}
if ( ! V_30 ) {
if ( ! F_10 ( V_34 , & V_26 ) )
V_27 += V_26 ;
else
V_30 = true ;
}
if ( ! V_31 ) {
if ( ! F_10 ( V_35 , & V_26 ) )
V_27 += V_26 ;
else
V_31 = true ;
}
return V_27 ;
}
static void F_11 ( unsigned long V_36 )
{
}
static unsigned int F_12 ( int V_37 )
{
unsigned int V_38 = 0 ;
if ( V_37 == 1 &&
V_39 [ V_37 ] . V_40 >= V_41 &&
V_39 [ V_37 + 1 ] . V_40 >= V_41 &&
V_39 [ V_37 + 2 ] . V_40 >= V_41 ) {
V_38 = ( V_39 [ V_37 ] . V_42 +
V_39 [ V_37 + 1 ] . V_42 +
V_39 [ V_37 + 2 ] . V_42 ) / 3 ;
} else if ( V_37 == V_43 - 1 &&
V_39 [ V_37 ] . V_40 >= V_41 &&
V_39 [ V_37 - 1 ] . V_40 >= V_41 &&
V_39 [ V_37 - 2 ] . V_40 >= V_41 ) {
V_38 = ( V_39 [ V_37 ] . V_42 +
V_39 [ V_37 - 1 ] . V_42 +
V_39 [ V_37 - 2 ] . V_42 ) / 3 ;
} else if ( V_39 [ V_37 ] . V_40 >= V_41 &&
V_39 [ V_37 - 1 ] . V_40 >= V_41 &&
V_39 [ V_37 + 1 ] . V_40 >= V_41 ) {
V_38 = ( V_39 [ V_37 ] . V_42 +
V_39 [ V_37 - 1 ] . V_42 +
V_39 [ V_37 + 1 ] . V_42 ) / 3 ;
}
if ( V_44 )
V_38 = V_37 ;
if ( V_38 + V_37 >= V_43 )
V_38 = V_43 - V_37 - 1 ;
return V_38 ;
}
static void F_13 ( int V_45 , unsigned int V_46 )
{
int V_47 ;
struct V_48 * V_49 = & V_39 [ V_45 ] ;
if ( V_49 -> V_40 >= V_41 ||
F_14 ( & V_50 ) >
V_46 * F_15 () )
return;
V_47 = V_51 - V_52 ;
if ( V_47 >= 0 && V_47 <= ( 1 + V_45 / 10 ) ) {
if ( V_49 -> V_42 )
V_49 -> V_42 =
F_16 ( V_47 + V_49 -> V_42 , 2 ) / 2 ;
else
V_49 -> V_42 = V_47 ;
V_49 -> V_40 ++ ;
}
}
static bool F_17 ( unsigned int V_45 ,
unsigned int V_53 , unsigned int V_46 )
{
static T_1 V_54 , V_55 ;
T_1 V_56 , V_57 ;
T_1 V_58 ;
V_56 = F_9 () ;
F_18 ( V_57 ) ;
if ( ! V_54 || ! V_55 )
V_52 = 1 ;
else if ( V_57 - V_55 ) {
V_58 = 100 * ( V_56 - V_54 ) ;
F_19 ( V_58 , ( V_57 - V_55 ) ) ;
V_52 = V_58 ;
}
V_54 = V_56 ;
V_55 = V_57 ;
F_13 ( V_45 , V_46 ) ;
V_44 = F_14 ( & V_50 ) >=
2 * V_46 * F_15 () ;
F_20 ( & V_50 , 0 ) ;
return V_51 + V_53 <= V_52 ;
}
static int F_21 ( void * V_1 )
{
int V_59 = ( unsigned long ) V_1 ;
F_22 ( V_60 , F_11 , 0 , 0 ) ;
static const struct V_61 V_62 = {
. V_63 = V_64 / 2 ,
} ;
unsigned int V_27 = 0 ;
unsigned int V_45 ;
F_23 ( V_59 , V_65 ) ;
F_24 () ;
F_25 ( & V_60 ) ;
F_26 ( V_66 , V_67 , & V_62 ) ;
while ( true == V_68 && ! F_27 () &&
F_28 ( V_59 ) ) {
int V_69 ;
unsigned long V_70 ;
unsigned int V_53 ;
unsigned int V_71 = 0 ;
int V_72 ;
unsigned int V_73 = F_29 ( V_7 ) ;
unsigned int V_74 ;
F_30 () ;
V_45 = V_51 ;
V_53 = 1 + V_45 / 20 ;
V_74 = V_10 ;
V_27 ++ ;
V_71 = F_12 ( V_45 ) ;
V_72 = V_73 * 100 / ( V_45 + V_71 ) ;
V_70 = F_16 ( V_75 , V_72 ) ;
V_69 = V_70 - V_75 ;
if ( V_69 <= 0 )
V_69 = 1 ;
F_31 ( V_69 ) ;
if ( V_59 == V_76 && ! ( V_27 % V_74 ) ) {
V_77 =
F_17 ( V_45 ,
V_53 , V_74 ) ;
F_5 () ;
}
if ( V_77 )
continue;
V_70 = V_75 + V_73 ;
F_32 ( & V_60 , V_70 ) ;
if ( F_33 ( F_34 () ) )
continue;
F_35 () ;
F_36 () ;
while ( F_37 ( V_75 , V_70 ) ) {
unsigned long V_13 = 1 ;
unsigned long V_11 = V_25 ;
F_38 () ;
F_39 () ;
F_40 ( ( void * ) & F_41 () -> V_78 , 0 , 0 ) ;
F_42 () ;
F_43 ( V_11 , V_13 ) ;
F_44 () ;
F_45 ( & V_50 ) ;
}
F_46 () ;
F_47 () ;
}
F_48 ( & V_60 ) ;
F_49 ( V_59 , V_65 ) ;
return 0 ;
}
static void F_50 ( struct V_79 * V_80 )
{
static T_1 V_54 ;
static T_1 V_55 ;
static unsigned long V_81 ;
T_1 V_56 ;
unsigned long V_82 ;
T_1 V_57 ;
T_1 V_58 ;
V_56 = F_9 () ;
F_18 ( V_57 ) ;
V_82 = V_75 ;
if ( ! V_54 || ! V_55 )
V_83 = 1 ;
else {
if ( V_57 - V_55 ) {
V_58 = 100 * ( V_56 - V_54 ) ;
F_19 ( V_58 , ( V_57 - V_55 ) ) ;
V_83 = V_58 ;
}
}
V_54 = V_56 ;
V_81 = V_82 ;
V_55 = V_57 ;
if ( true == V_68 )
F_51 ( & V_84 , V_85 ) ;
}
static int F_52 ( void )
{
unsigned long V_86 ;
struct V_87 * V_88 ;
if ( ! F_9 () ) {
F_3 ( L_3 ) ;
return - V_6 ;
}
V_51 = F_4 ( V_51 , 0U , V_43 - 1 ) ;
F_53 () ;
V_76 = 0 ;
if ( ! F_28 ( V_76 ) )
V_76 = F_54 () ;
V_68 = true ;
F_51 ( & V_84 , 0 ) ;
F_55 (cpu) {
struct V_87 * * V_89 =
F_56 ( V_90 , V_86 ) ;
V_88 = F_57 ( F_21 ,
( void * ) V_86 ,
F_58 ( V_86 ) ,
L_4 , V_86 ) ;
if ( F_59 ( ! F_60 ( V_88 ) ) ) {
F_61 ( V_88 , V_86 ) ;
F_62 ( V_88 ) ;
* V_89 = V_88 ;
}
}
F_63 () ;
return 0 ;
}
static void F_64 ( void )
{
int V_17 ;
struct V_87 * V_88 ;
V_68 = false ;
F_5 () ;
F_65 ( 20 ) ;
if ( F_66 ( V_65 , F_67 () ) ) {
F_68 (i, cpu_clamping_mask, num_possible_cpus()) {
F_69 ( L_5 , V_17 ) ;
V_88 = * F_56 ( V_90 , V_17 ) ;
F_70 ( V_88 ) ;
}
}
}
static int F_71 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
unsigned long V_86 = ( unsigned long ) V_94 ;
struct V_87 * V_88 ;
struct V_87 * * V_95 =
F_56 ( V_90 , V_86 ) ;
if ( false == V_68 )
goto V_96;
switch ( V_93 ) {
case V_97 :
V_88 = F_57 ( F_21 ,
( void * ) V_86 ,
F_58 ( V_86 ) ,
L_6 , V_86 ) ;
if ( F_59 ( ! F_60 ( V_88 ) ) ) {
F_61 ( V_88 , V_86 ) ;
F_62 ( V_88 ) ;
* V_95 = V_88 ;
}
if ( V_86 == 0 ) {
V_76 = 0 ;
F_5 () ;
}
break;
case V_98 :
if ( F_72 ( V_86 , V_65 ) ) {
F_3 ( L_7 ,
V_86 ) ;
F_70 ( * V_95 ) ;
}
if ( V_86 == V_76 ) {
V_76 = F_54 () ;
F_5 () ;
}
}
V_96:
return V_99 ;
}
static int F_73 ( struct V_100 * V_101 ,
unsigned long * V_102 )
{
* V_102 = V_43 ;
return 0 ;
}
static int F_74 ( struct V_100 * V_101 ,
unsigned long * V_102 )
{
if ( true == V_68 )
* V_102 = V_83 ;
else
* V_102 = - 1 ;
return 0 ;
}
static int F_75 ( struct V_100 * V_101 ,
unsigned long V_103 )
{
int V_4 = 0 ;
V_103 = F_4 ( V_103 , 0UL ,
( unsigned long ) ( V_43 - 1 ) ) ;
if ( V_51 == 0 && V_103 > 0 ) {
F_76 ( L_8 ) ;
V_51 = V_103 ;
V_4 = F_52 () ;
goto V_104;
} else if ( V_51 > 0 && V_103 == 0 ) {
F_76 ( L_9 ) ;
V_51 = 0 ;
F_64 () ;
} else {
V_51 = V_103 ;
F_5 () ;
}
V_104:
return V_4 ;
}
static int F_77 ( void )
{
if ( ! F_78 ( V_105 ) ) {
F_3 ( L_10 ,
V_18 . V_106 , V_18 . V_107 ) ;
return - V_108 ;
}
if ( ! F_79 ( V_109 ) ||
! F_79 ( V_110 ) ||
! F_79 ( V_111 ) ||
! F_79 ( V_112 ) )
return - V_108 ;
F_7 () ;
return 0 ;
}
static int F_80 ( struct V_113 * V_114 , void * V_115 )
{
int V_17 = 0 ;
F_81 ( V_114 , L_11 , V_76 ) ;
F_81 ( V_114 , L_12 ) ;
for ( V_17 = 0 ; V_17 < V_43 ; V_17 ++ ) {
F_81 ( V_114 , L_13 ,
V_17 ,
V_39 [ V_17 ] . V_40 ,
V_39 [ V_17 ] . V_42 ,
V_39 [ V_17 ] . V_116 ) ;
}
return 0 ;
}
static int F_82 ( struct V_117 * V_117 ,
struct V_118 * V_118 )
{
return F_83 ( V_118 , F_80 , V_117 -> V_119 ) ;
}
static inline void F_84 ( void )
{
V_120 = F_85 ( L_14 , NULL ) ;
if ( ! V_120 )
return;
if ( ! F_86 ( L_15 , V_121 , V_120 ,
V_39 , & V_122 ) )
goto V_123;
return;
V_123:
F_87 ( V_120 ) ;
}
static int F_88 ( void )
{
int V_124 ;
int V_125 ;
V_125 = F_89 ( F_67 () ) * sizeof( long ) ;
V_65 = F_90 ( V_125 , V_126 ) ;
if ( ! V_65 )
return - V_127 ;
V_124 = F_77 () ;
if ( V_124 )
return V_124 ;
V_10 = 2 ;
F_91 ( & V_128 ) ;
V_90 = F_92 ( struct V_87 * ) ;
V_129 = F_93 ( L_14 , NULL ,
& V_130 ) ;
if ( F_60 ( V_129 ) )
return - V_108 ;
if ( ! V_7 )
V_7 = F_94 ( V_131 ) ;
F_84 () ;
return 0 ;
}
static void F_95 ( void )
{
F_96 ( & V_128 ) ;
F_64 () ;
F_97 ( V_90 ) ;
F_98 ( V_129 ) ;
F_99 ( V_65 ) ;
F_100 ( & V_84 ) ;
F_87 ( V_120 ) ;
}
