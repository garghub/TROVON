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
static bool F_9 ( void )
{
T_1 V_26 ;
return ! F_10 ( V_27 , & V_26 ) ||
! F_10 ( V_28 , & V_26 ) ||
! F_10 ( V_29 , & V_26 ) ||
! F_10 ( V_30 , & V_26 ) ;
}
static T_1 F_11 ( void )
{
T_1 V_31 ;
T_1 V_32 = 0 ;
static bool V_33 ;
static bool V_34 ;
static bool V_35 ;
static bool V_36 ;
if ( ! V_33 ) {
if ( ! F_10 ( V_27 , & V_31 ) )
V_32 += V_31 ;
else
V_33 = true ;
}
if ( ! V_34 ) {
if ( ! F_10 ( V_28 , & V_31 ) )
V_32 += V_31 ;
else
V_34 = true ;
}
if ( ! V_35 ) {
if ( ! F_10 ( V_29 , & V_31 ) )
V_32 += V_31 ;
else
V_35 = true ;
}
if ( ! V_36 ) {
if ( ! F_10 ( V_30 , & V_31 ) )
V_32 += V_31 ;
else
V_36 = true ;
}
return V_32 ;
}
static void F_12 ( unsigned long V_37 )
{
}
static unsigned int F_13 ( int V_38 )
{
unsigned int V_39 = 0 ;
if ( V_38 == 1 &&
V_40 [ V_38 ] . V_41 >= V_42 &&
V_40 [ V_38 + 1 ] . V_41 >= V_42 &&
V_40 [ V_38 + 2 ] . V_41 >= V_42 ) {
V_39 = ( V_40 [ V_38 ] . V_43 +
V_40 [ V_38 + 1 ] . V_43 +
V_40 [ V_38 + 2 ] . V_43 ) / 3 ;
} else if ( V_38 == V_44 - 1 &&
V_40 [ V_38 ] . V_41 >= V_42 &&
V_40 [ V_38 - 1 ] . V_41 >= V_42 &&
V_40 [ V_38 - 2 ] . V_41 >= V_42 ) {
V_39 = ( V_40 [ V_38 ] . V_43 +
V_40 [ V_38 - 1 ] . V_43 +
V_40 [ V_38 - 2 ] . V_43 ) / 3 ;
} else if ( V_40 [ V_38 ] . V_41 >= V_42 &&
V_40 [ V_38 - 1 ] . V_41 >= V_42 &&
V_40 [ V_38 + 1 ] . V_41 >= V_42 ) {
V_39 = ( V_40 [ V_38 ] . V_43 +
V_40 [ V_38 - 1 ] . V_43 +
V_40 [ V_38 + 1 ] . V_43 ) / 3 ;
}
if ( V_45 )
V_39 = V_38 ;
if ( V_39 + V_38 >= V_44 )
V_39 = V_44 - V_38 - 1 ;
return V_39 ;
}
static void F_14 ( int V_46 , unsigned int V_47 )
{
int V_48 ;
struct V_49 * V_50 = & V_40 [ V_46 ] ;
if ( V_50 -> V_41 >= V_42 ||
F_15 ( & V_51 ) >
V_47 * F_16 () )
return;
V_48 = V_52 - V_53 ;
if ( V_48 >= 0 && V_48 <= ( 1 + V_46 / 10 ) ) {
if ( V_50 -> V_43 )
V_50 -> V_43 =
F_17 ( V_48 + V_50 -> V_43 , 2 ) / 2 ;
else
V_50 -> V_43 = V_48 ;
V_50 -> V_41 ++ ;
}
}
static bool F_18 ( unsigned int V_46 ,
unsigned int V_54 , unsigned int V_47 )
{
static T_1 V_55 , V_56 ;
T_1 V_57 , V_58 ;
T_1 V_59 ;
V_57 = F_11 () ;
F_19 ( V_58 ) ;
if ( ! V_55 || ! V_56 )
V_53 = 1 ;
else if ( V_58 - V_56 ) {
V_59 = 100 * ( V_57 - V_55 ) ;
F_20 ( V_59 , ( V_58 - V_56 ) ) ;
V_53 = V_59 ;
}
V_55 = V_57 ;
V_56 = V_58 ;
F_14 ( V_46 , V_47 ) ;
V_45 = F_15 ( & V_51 ) >=
2 * V_47 * F_16 () ;
F_21 ( & V_51 , 0 ) ;
return V_52 + V_54 <= V_53 ;
}
static int F_22 ( void * V_1 )
{
int V_60 = ( unsigned long ) V_1 ;
F_23 ( V_61 , F_12 , 0 , 0 ) ;
static const struct V_62 V_63 = {
. V_64 = V_65 / 2 ,
} ;
unsigned int V_32 = 0 ;
unsigned int V_46 ;
F_24 ( V_60 , V_66 ) ;
F_25 () ;
F_26 ( & V_61 ) ;
F_27 ( V_67 , V_68 , & V_63 ) ;
while ( true == V_69 && ! F_28 () &&
F_29 ( V_60 ) ) {
int V_70 ;
unsigned long V_71 ;
unsigned int V_54 ;
unsigned int V_72 = 0 ;
int V_73 ;
unsigned int V_74 = F_30 ( V_7 ) ;
unsigned int V_75 ;
F_31 () ;
V_46 = V_52 ;
V_54 = 1 + V_46 / 20 ;
V_75 = V_10 ;
V_32 ++ ;
V_72 = F_13 ( V_46 ) ;
V_73 = V_74 * 100 / ( V_46 + V_72 ) ;
V_71 = F_17 ( V_76 , V_73 ) ;
V_70 = V_71 - V_76 ;
if ( V_70 <= 0 )
V_70 = 1 ;
F_32 ( V_70 ) ;
if ( V_60 == V_77 && ! ( V_32 % V_75 ) ) {
V_78 =
F_18 ( V_46 ,
V_54 , V_75 ) ;
F_5 () ;
}
if ( V_78 )
continue;
V_71 = V_76 + V_74 ;
F_33 ( & V_61 , V_71 ) ;
if ( F_34 ( F_35 () ) )
continue;
F_36 () ;
F_37 () ;
while ( F_38 ( V_76 , V_71 ) ) {
unsigned long V_13 = 1 ;
unsigned long V_11 = V_25 ;
F_39 () ;
F_40 () ;
F_41 ( V_11 , V_13 ) ;
F_42 () ;
F_43 ( & V_51 ) ;
}
F_44 () ;
F_45 () ;
}
F_46 ( & V_61 ) ;
F_47 ( V_60 , V_66 ) ;
return 0 ;
}
static void F_48 ( struct V_79 * V_80 )
{
static T_1 V_55 ;
static T_1 V_56 ;
static unsigned long V_81 ;
T_1 V_57 ;
unsigned long V_82 ;
T_1 V_58 ;
T_1 V_59 ;
V_57 = F_11 () ;
F_19 ( V_58 ) ;
V_82 = V_76 ;
if ( ! V_55 || ! V_56 )
V_83 = 1 ;
else {
if ( V_58 - V_56 ) {
V_59 = 100 * ( V_57 - V_55 ) ;
F_20 ( V_59 , ( V_58 - V_56 ) ) ;
V_83 = V_59 ;
}
}
V_55 = V_57 ;
V_81 = V_82 ;
V_56 = V_58 ;
if ( true == V_69 )
F_49 ( & V_84 , V_85 ) ;
}
static int F_50 ( void )
{
unsigned long V_86 ;
struct V_87 * V_88 ;
if ( ! F_9 () ) {
F_3 ( L_3 ) ;
return - V_6 ;
}
V_52 = F_4 ( V_52 , 0U , V_44 - 1 ) ;
F_51 () ;
V_77 = 0 ;
if ( ! F_29 ( V_77 ) )
V_77 = F_52 () ;
V_69 = true ;
F_49 ( & V_84 , 0 ) ;
F_53 (cpu) {
struct V_87 * * V_89 =
F_54 ( V_90 , V_86 ) ;
V_88 = F_55 ( F_22 ,
( void * ) V_86 ,
F_56 ( V_86 ) ,
L_4 , V_86 ) ;
if ( F_57 ( ! F_58 ( V_88 ) ) ) {
F_59 ( V_88 , V_86 ) ;
F_60 ( V_88 ) ;
* V_89 = V_88 ;
}
}
F_61 () ;
return 0 ;
}
static void F_62 ( void )
{
int V_17 ;
struct V_87 * V_88 ;
V_69 = false ;
F_5 () ;
F_63 ( 20 ) ;
if ( F_64 ( V_66 , F_65 () ) ) {
F_66 (i, cpu_clamping_mask, num_possible_cpus()) {
F_67 ( L_5 , V_17 ) ;
V_88 = * F_54 ( V_90 , V_17 ) ;
F_68 ( V_88 ) ;
}
}
}
static int F_69 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
unsigned long V_86 = ( unsigned long ) V_94 ;
struct V_87 * V_88 ;
struct V_87 * * V_95 =
F_54 ( V_90 , V_86 ) ;
if ( false == V_69 )
goto V_96;
switch ( V_93 ) {
case V_97 :
V_88 = F_55 ( F_22 ,
( void * ) V_86 ,
F_56 ( V_86 ) ,
L_6 , V_86 ) ;
if ( F_57 ( ! F_58 ( V_88 ) ) ) {
F_59 ( V_88 , V_86 ) ;
F_60 ( V_88 ) ;
* V_95 = V_88 ;
}
if ( V_86 == 0 ) {
V_77 = 0 ;
F_5 () ;
}
break;
case V_98 :
if ( F_70 ( V_86 , V_66 ) ) {
F_3 ( L_7 ,
V_86 ) ;
F_68 ( * V_95 ) ;
}
if ( V_86 == V_77 ) {
V_77 = F_52 () ;
F_5 () ;
}
}
V_96:
return V_99 ;
}
static int F_71 ( struct V_100 * V_101 ,
unsigned long * V_102 )
{
* V_102 = V_44 ;
return 0 ;
}
static int F_72 ( struct V_100 * V_101 ,
unsigned long * V_102 )
{
if ( true == V_69 )
* V_102 = V_83 ;
else
* V_102 = - 1 ;
return 0 ;
}
static int F_73 ( struct V_100 * V_101 ,
unsigned long V_103 )
{
int V_4 = 0 ;
V_103 = F_4 ( V_103 , 0UL ,
( unsigned long ) ( V_44 - 1 ) ) ;
if ( V_52 == 0 && V_103 > 0 ) {
F_74 ( L_8 ) ;
V_52 = V_103 ;
V_4 = F_50 () ;
goto V_104;
} else if ( V_52 > 0 && V_103 == 0 ) {
F_74 ( L_9 ) ;
V_52 = 0 ;
F_62 () ;
} else {
V_52 = V_103 ;
F_5 () ;
}
V_104:
return V_4 ;
}
static int F_75 ( void )
{
if ( ! F_76 ( V_105 ) ) {
F_3 ( L_10 ,
V_18 . V_106 , V_18 . V_107 ) ;
return - V_108 ;
}
if ( ! F_77 ( V_109 ) ||
! F_77 ( V_110 ) ||
! F_77 ( V_111 ) ||
! F_77 ( V_112 ) )
return - V_108 ;
F_7 () ;
return 0 ;
}
static int F_78 ( struct V_113 * V_114 , void * V_115 )
{
int V_17 = 0 ;
F_79 ( V_114 , L_11 , V_77 ) ;
F_79 ( V_114 , L_12 ) ;
for ( V_17 = 0 ; V_17 < V_44 ; V_17 ++ ) {
F_79 ( V_114 , L_13 ,
V_17 ,
V_40 [ V_17 ] . V_41 ,
V_40 [ V_17 ] . V_43 ,
V_40 [ V_17 ] . V_116 ) ;
}
return 0 ;
}
static int F_80 ( struct V_117 * V_117 ,
struct V_118 * V_118 )
{
return F_81 ( V_118 , F_78 , V_117 -> V_119 ) ;
}
static inline void F_82 ( void )
{
V_120 = F_83 ( L_14 , NULL ) ;
if ( ! V_120 )
return;
if ( ! F_84 ( L_15 , V_121 , V_120 ,
V_40 , & V_122 ) )
goto V_123;
return;
V_123:
F_85 ( V_120 ) ;
}
static int F_86 ( void )
{
int V_124 ;
int V_125 ;
V_125 = F_87 ( F_65 () ) * sizeof( long ) ;
V_66 = F_88 ( V_125 , V_126 ) ;
if ( ! V_66 )
return - V_127 ;
V_124 = F_75 () ;
if ( V_124 )
goto V_128;
V_10 = 2 ;
F_89 ( & V_129 ) ;
V_90 = F_90 ( struct V_87 * ) ;
if ( ! V_90 ) {
V_124 = - V_127 ;
goto V_130;
}
V_131 = F_91 ( L_14 , NULL ,
& V_132 ) ;
if ( F_58 ( V_131 ) ) {
V_124 = - V_108 ;
goto V_133;
}
if ( ! V_7 )
V_7 = F_92 ( V_134 ) ;
F_82 () ;
return 0 ;
V_133:
F_93 ( V_90 ) ;
V_130:
F_94 ( & V_129 ) ;
V_128:
F_95 ( V_66 ) ;
return V_124 ;
}
static void F_96 ( void )
{
F_94 ( & V_129 ) ;
F_62 () ;
F_93 ( V_90 ) ;
F_97 ( V_131 ) ;
F_95 ( V_66 ) ;
F_98 ( & V_84 ) ;
F_85 ( V_120 ) ;
}
