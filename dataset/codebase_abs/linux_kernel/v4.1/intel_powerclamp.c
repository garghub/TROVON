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
struct V_27 * V_28 = V_29 ;
while ( V_28 -> V_30 ) {
if ( ! F_10 ( V_28 -> V_30 , & V_26 ) )
return true ;
V_28 ++ ;
}
return false ;
}
static T_1 F_11 ( void )
{
T_1 V_26 ;
T_1 V_31 = 0 ;
struct V_27 * V_28 = V_29 ;
while ( V_28 -> V_30 ) {
if ( ! V_28 -> V_32 ) {
if ( ! F_10 ( V_28 -> V_30 , & V_26 ) )
V_31 += V_26 ;
else
V_28 -> V_32 = true ;
}
V_28 ++ ;
}
return V_31 ;
}
static void F_12 ( unsigned long V_33 )
{
}
static unsigned int F_13 ( int V_34 )
{
unsigned int V_35 = 0 ;
if ( V_34 == 1 &&
V_36 [ V_34 ] . V_37 >= V_38 &&
V_36 [ V_34 + 1 ] . V_37 >= V_38 &&
V_36 [ V_34 + 2 ] . V_37 >= V_38 ) {
V_35 = ( V_36 [ V_34 ] . V_39 +
V_36 [ V_34 + 1 ] . V_39 +
V_36 [ V_34 + 2 ] . V_39 ) / 3 ;
} else if ( V_34 == V_40 - 1 &&
V_36 [ V_34 ] . V_37 >= V_38 &&
V_36 [ V_34 - 1 ] . V_37 >= V_38 &&
V_36 [ V_34 - 2 ] . V_37 >= V_38 ) {
V_35 = ( V_36 [ V_34 ] . V_39 +
V_36 [ V_34 - 1 ] . V_39 +
V_36 [ V_34 - 2 ] . V_39 ) / 3 ;
} else if ( V_36 [ V_34 ] . V_37 >= V_38 &&
V_36 [ V_34 - 1 ] . V_37 >= V_38 &&
V_36 [ V_34 + 1 ] . V_37 >= V_38 ) {
V_35 = ( V_36 [ V_34 ] . V_39 +
V_36 [ V_34 - 1 ] . V_39 +
V_36 [ V_34 + 1 ] . V_39 ) / 3 ;
}
if ( V_41 )
V_35 = V_34 ;
if ( V_35 + V_34 >= V_40 )
V_35 = V_40 - V_34 - 1 ;
return V_35 ;
}
static void F_14 ( int V_42 , unsigned int V_43 )
{
int V_44 ;
struct V_45 * V_46 = & V_36 [ V_42 ] ;
if ( V_46 -> V_37 >= V_38 ||
F_15 ( & V_47 ) >
V_43 * F_16 () )
return;
V_44 = V_48 - V_49 ;
if ( V_44 >= 0 && V_44 <= ( 1 + V_42 / 10 ) ) {
if ( V_46 -> V_39 )
V_46 -> V_39 =
F_17 ( V_44 + V_46 -> V_39 , 2 ) / 2 ;
else
V_46 -> V_39 = V_44 ;
V_46 -> V_37 ++ ;
}
}
static bool F_18 ( unsigned int V_42 ,
unsigned int V_50 , unsigned int V_43 )
{
static T_1 V_51 , V_52 ;
T_1 V_53 , V_54 ;
T_1 V_55 ;
V_53 = F_11 () ;
F_19 ( V_54 ) ;
if ( ! V_51 || ! V_52 )
V_49 = 1 ;
else if ( V_54 - V_52 ) {
V_55 = 100 * ( V_53 - V_51 ) ;
F_20 ( V_55 , ( V_54 - V_52 ) ) ;
V_49 = V_55 ;
}
V_51 = V_53 ;
V_52 = V_54 ;
F_14 ( V_42 , V_43 ) ;
V_41 = F_15 ( & V_47 ) >=
2 * V_43 * F_16 () ;
F_21 ( & V_47 , 0 ) ;
return V_48 + V_50 <= V_49 ;
}
static int F_22 ( void * V_1 )
{
int V_56 = ( unsigned long ) V_1 ;
F_23 ( V_57 , F_12 , 0 , 0 ) ;
static const struct V_58 V_59 = {
. V_60 = V_61 / 2 ,
} ;
unsigned int V_31 = 0 ;
unsigned int V_42 ;
F_24 ( V_56 , V_62 ) ;
F_25 () ;
F_26 ( & V_57 ) ;
F_27 ( V_63 , V_64 , & V_59 ) ;
while ( true == V_65 && ! F_28 () &&
F_29 ( V_56 ) ) {
int V_66 ;
unsigned long V_67 ;
unsigned int V_50 ;
unsigned int V_68 = 0 ;
int V_69 ;
unsigned int V_70 = F_30 ( V_7 ) ;
unsigned int V_71 ;
F_31 () ;
V_42 = V_48 ;
V_50 = 1 + V_42 / 20 ;
V_71 = V_10 ;
V_31 ++ ;
V_68 = F_13 ( V_42 ) ;
V_69 = V_70 * 100 / ( V_42 + V_68 ) ;
V_67 = F_17 ( V_72 , V_69 ) ;
V_66 = V_67 - V_72 ;
if ( V_66 <= 0 )
V_66 = 1 ;
F_32 ( V_66 ) ;
if ( V_56 == V_73 && ! ( V_31 % V_71 ) ) {
V_74 =
F_18 ( V_42 ,
V_50 , V_71 ) ;
F_5 () ;
}
if ( V_74 )
continue;
V_67 = V_72 + V_70 ;
F_33 ( & V_57 , V_67 ) ;
if ( F_34 ( F_35 () ) )
continue;
F_36 () ;
while ( F_37 ( V_72 , V_67 ) ) {
unsigned long V_13 = 1 ;
unsigned long V_11 = V_25 ;
F_38 () ;
F_39 () ;
F_40 ( V_11 , V_13 ) ;
F_41 () ;
F_42 ( & V_47 ) ;
}
F_43 () ;
}
F_44 ( & V_57 ) ;
F_45 ( V_56 , V_62 ) ;
return 0 ;
}
static void F_46 ( struct V_75 * V_76 )
{
static T_1 V_51 ;
static T_1 V_52 ;
static unsigned long V_77 ;
T_1 V_53 ;
unsigned long V_78 ;
T_1 V_54 ;
T_1 V_55 ;
V_53 = F_11 () ;
F_19 ( V_54 ) ;
V_78 = V_72 ;
if ( ! V_51 || ! V_52 )
V_79 = 1 ;
else {
if ( V_54 - V_52 ) {
V_55 = 100 * ( V_53 - V_51 ) ;
F_20 ( V_55 , ( V_54 - V_52 ) ) ;
V_79 = V_55 ;
}
}
V_51 = V_53 ;
V_77 = V_78 ;
V_52 = V_54 ;
if ( true == V_65 )
F_47 ( & V_80 , V_81 ) ;
}
static int F_48 ( void )
{
unsigned long V_82 ;
struct V_83 * V_84 ;
if ( ! F_9 () ) {
F_3 ( L_3 ) ;
return - V_6 ;
}
V_48 = F_4 ( V_48 , 0U , V_40 - 1 ) ;
F_49 () ;
V_73 = 0 ;
if ( ! F_29 ( V_73 ) )
V_73 = F_50 () ;
V_65 = true ;
F_47 ( & V_80 , 0 ) ;
F_51 (cpu) {
struct V_83 * * V_85 =
F_52 ( V_86 , V_82 ) ;
V_84 = F_53 ( F_22 ,
( void * ) V_82 ,
F_54 ( V_82 ) ,
L_4 , V_82 ) ;
if ( F_55 ( ! F_56 ( V_84 ) ) ) {
F_57 ( V_84 , V_82 ) ;
F_58 ( V_84 ) ;
* V_85 = V_84 ;
}
}
F_59 () ;
return 0 ;
}
static void F_60 ( void )
{
int V_17 ;
struct V_83 * V_84 ;
V_65 = false ;
F_5 () ;
F_61 ( 20 ) ;
if ( F_62 ( V_62 , F_63 () ) ) {
F_64 (i, cpu_clamping_mask, num_possible_cpus()) {
F_65 ( L_5 , V_17 ) ;
V_84 = * F_52 ( V_86 , V_17 ) ;
F_66 ( V_84 ) ;
}
}
}
static int F_67 ( struct V_87 * V_88 ,
unsigned long V_89 , void * V_90 )
{
unsigned long V_82 = ( unsigned long ) V_90 ;
struct V_83 * V_84 ;
struct V_83 * * V_91 =
F_52 ( V_86 , V_82 ) ;
if ( false == V_65 )
goto V_92;
switch ( V_89 ) {
case V_93 :
V_84 = F_53 ( F_22 ,
( void * ) V_82 ,
F_54 ( V_82 ) ,
L_6 , V_82 ) ;
if ( F_55 ( ! F_56 ( V_84 ) ) ) {
F_57 ( V_84 , V_82 ) ;
F_58 ( V_84 ) ;
* V_91 = V_84 ;
}
if ( V_82 == 0 ) {
V_73 = 0 ;
F_5 () ;
}
break;
case V_94 :
if ( F_68 ( V_82 , V_62 ) ) {
F_3 ( L_7 ,
V_82 ) ;
F_66 ( * V_91 ) ;
}
if ( V_82 == V_73 ) {
V_73 = F_50 () ;
F_5 () ;
}
}
V_92:
return V_95 ;
}
static int F_69 ( struct V_96 * V_97 ,
unsigned long * V_98 )
{
* V_98 = V_40 ;
return 0 ;
}
static int F_70 ( struct V_96 * V_97 ,
unsigned long * V_98 )
{
if ( true == V_65 )
* V_98 = V_79 ;
else
* V_98 = - 1 ;
return 0 ;
}
static int F_71 ( struct V_96 * V_97 ,
unsigned long V_99 )
{
int V_4 = 0 ;
V_99 = F_4 ( V_99 , 0UL ,
( unsigned long ) ( V_40 - 1 ) ) ;
if ( V_48 == 0 && V_99 > 0 ) {
F_72 ( L_8 ) ;
V_48 = V_99 ;
V_4 = F_48 () ;
goto V_100;
} else if ( V_48 > 0 && V_99 == 0 ) {
F_72 ( L_9 ) ;
V_48 = 0 ;
F_60 () ;
} else {
V_48 = V_99 ;
F_5 () ;
}
V_100:
return V_4 ;
}
static int T_2 F_73 ( void )
{
if ( ! F_74 ( V_101 ) ) {
F_3 ( L_10 ,
V_18 . V_102 , V_18 . V_103 ) ;
return - V_104 ;
}
if ( ! F_75 ( V_105 ) ||
! F_75 ( V_106 ) ||
! F_75 ( V_107 ) ||
! F_75 ( V_108 ) )
return - V_104 ;
F_7 () ;
return 0 ;
}
static int F_76 ( struct V_109 * V_110 , void * V_111 )
{
int V_17 = 0 ;
F_77 ( V_110 , L_11 , V_73 ) ;
F_77 ( V_110 , L_12 ) ;
for ( V_17 = 0 ; V_17 < V_40 ; V_17 ++ ) {
F_77 ( V_110 , L_13 ,
V_17 ,
V_36 [ V_17 ] . V_37 ,
V_36 [ V_17 ] . V_39 ,
V_36 [ V_17 ] . V_112 ) ;
}
return 0 ;
}
static int F_78 ( struct V_113 * V_113 ,
struct V_114 * V_114 )
{
return F_79 ( V_114 , F_76 , V_113 -> V_115 ) ;
}
static inline void F_80 ( void )
{
V_116 = F_81 ( L_14 , NULL ) ;
if ( ! V_116 )
return;
if ( ! F_82 ( L_15 , V_117 , V_116 ,
V_36 , & V_118 ) )
goto V_119;
return;
V_119:
F_83 ( V_116 ) ;
}
static int T_2 F_84 ( void )
{
int V_120 ;
int V_121 ;
V_121 = F_85 ( F_63 () ) * sizeof( long ) ;
V_62 = F_86 ( V_121 , V_122 ) ;
if ( ! V_62 )
return - V_123 ;
V_120 = F_73 () ;
if ( V_120 )
goto V_124;
V_10 = 2 ;
F_87 ( & V_125 ) ;
V_86 = F_88 ( struct V_83 * ) ;
if ( ! V_86 ) {
V_120 = - V_123 ;
goto V_126;
}
V_127 = F_89 ( L_14 , NULL ,
& V_128 ) ;
if ( F_56 ( V_127 ) ) {
V_120 = - V_104 ;
goto V_129;
}
if ( ! V_7 )
V_7 = F_90 ( V_130 ) ;
F_80 () ;
return 0 ;
V_129:
F_91 ( V_86 ) ;
V_126:
F_92 ( & V_125 ) ;
V_124:
F_93 ( V_62 ) ;
return V_120 ;
}
static void T_3 F_94 ( void )
{
F_92 ( & V_125 ) ;
F_60 () ;
F_91 ( V_86 ) ;
F_95 ( V_127 ) ;
F_93 ( V_62 ) ;
F_96 ( & V_80 ) ;
F_83 ( V_116 ) ;
}
