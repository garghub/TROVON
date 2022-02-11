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
static unsigned int F_12 ( int V_33 )
{
unsigned int V_34 = 0 ;
if ( V_33 == 1 &&
V_35 [ V_33 ] . V_36 >= V_37 &&
V_35 [ V_33 + 1 ] . V_36 >= V_37 &&
V_35 [ V_33 + 2 ] . V_36 >= V_37 ) {
V_34 = ( V_35 [ V_33 ] . V_38 +
V_35 [ V_33 + 1 ] . V_38 +
V_35 [ V_33 + 2 ] . V_38 ) / 3 ;
} else if ( V_33 == V_39 - 1 &&
V_35 [ V_33 ] . V_36 >= V_37 &&
V_35 [ V_33 - 1 ] . V_36 >= V_37 &&
V_35 [ V_33 - 2 ] . V_36 >= V_37 ) {
V_34 = ( V_35 [ V_33 ] . V_38 +
V_35 [ V_33 - 1 ] . V_38 +
V_35 [ V_33 - 2 ] . V_38 ) / 3 ;
} else if ( V_35 [ V_33 ] . V_36 >= V_37 &&
V_35 [ V_33 - 1 ] . V_36 >= V_37 &&
V_35 [ V_33 + 1 ] . V_36 >= V_37 ) {
V_34 = ( V_35 [ V_33 ] . V_38 +
V_35 [ V_33 - 1 ] . V_38 +
V_35 [ V_33 + 1 ] . V_38 ) / 3 ;
}
if ( V_40 )
V_34 = V_33 ;
if ( V_34 + V_33 >= V_39 )
V_34 = V_39 - V_33 - 1 ;
return V_34 ;
}
static void F_13 ( int V_41 , unsigned int V_42 )
{
int V_43 ;
struct V_44 * V_45 = & V_35 [ V_41 ] ;
if ( V_45 -> V_36 >= V_37 ||
F_14 ( & V_46 ) >
V_42 * F_15 () )
return;
V_43 = V_47 - V_48 ;
if ( V_43 >= 0 && V_43 <= ( 1 + V_41 / 10 ) ) {
if ( V_45 -> V_38 )
V_45 -> V_38 =
F_16 ( V_43 + V_45 -> V_38 , 2 ) / 2 ;
else
V_45 -> V_38 = V_43 ;
V_45 -> V_36 ++ ;
}
}
static bool F_17 ( unsigned int V_41 ,
unsigned int V_49 , unsigned int V_42 )
{
static T_1 V_50 , V_51 ;
T_1 V_52 , V_53 ;
T_1 V_54 ;
V_52 = F_11 () ;
V_53 = F_18 () ;
if ( ! V_50 || ! V_51 )
V_48 = 1 ;
else if ( V_53 - V_51 ) {
V_54 = 100 * ( V_52 - V_50 ) ;
F_19 ( V_54 , ( V_53 - V_51 ) ) ;
V_48 = V_54 ;
}
V_50 = V_52 ;
V_51 = V_53 ;
F_13 ( V_41 , V_42 ) ;
V_40 = F_14 ( & V_46 ) >=
2 * V_42 * F_15 () ;
F_20 ( & V_46 , 0 ) ;
return V_47 + V_49 <= V_48 ;
}
static void F_21 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_59 ;
unsigned long V_60 ;
unsigned int V_61 ;
int V_62 ;
V_58 = F_22 ( V_56 , struct V_57 ,
V_63 ) ;
V_58 -> V_41 = F_23 ( V_47 ) ;
V_58 -> V_49 = 1 + V_58 -> V_41 / 20 ;
V_58 -> V_64 = V_10 ;
V_58 -> V_65 = F_24 ( V_7 ) ;
V_58 -> V_31 ++ ;
V_61 = V_58 -> V_41 +
F_12 ( V_58 -> V_41 ) ;
if ( V_61 <= 0 )
V_61 = 1 ;
V_62 = V_58 -> V_65 * 100 / V_61 ;
V_60 = F_16 ( V_66 , V_62 ) ;
V_59 = V_60 - V_66 ;
if ( V_59 <= 0 )
V_59 = 1 ;
if ( V_67 && V_58 -> V_67 && F_25 ( V_58 -> V_68 ) )
F_26 ( V_58 -> V_69 ,
& V_58 -> V_70 ,
V_59 ) ;
}
static void F_27 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
V_58 = F_22 ( V_56 , struct V_57 ,
V_70 . V_56 ) ;
if ( V_58 -> V_68 == V_71 &&
! ( V_58 -> V_31 % V_58 -> V_64 ) ) {
V_72 =
F_17 ( V_58 -> V_41 ,
V_58 -> V_49 ,
V_58 -> V_64 ) ;
F_5 () ;
}
if ( V_72 )
goto V_73;
F_28 ( F_29 ( V_58 -> V_65 ) ) ;
V_73:
if ( V_67 && V_58 -> V_67 && F_25 ( V_58 -> V_68 ) )
F_30 ( V_58 -> V_69 , & V_58 -> V_63 ) ;
}
static void F_31 ( struct V_74 * V_75 )
{
static T_1 V_50 ;
static T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_54 ;
V_52 = F_11 () ;
V_53 = F_18 () ;
if ( ! V_50 || ! V_51 )
V_76 = 1 ;
else {
if ( V_53 - V_51 ) {
V_54 = 100 * ( V_52 - V_50 ) ;
F_19 ( V_54 , ( V_53 - V_51 ) ) ;
V_76 = V_54 ;
}
}
V_50 = V_52 ;
V_51 = V_53 ;
if ( true == V_67 )
F_32 ( & V_77 , V_78 ) ;
}
static void F_33 ( unsigned long V_68 )
{
struct V_57 * V_58 = F_34 ( V_79 , V_68 ) ;
struct V_80 * V_69 ;
V_69 = F_35 ( V_68 , 0 , L_3 , V_68 ) ;
if ( F_36 ( V_69 ) )
return;
V_58 -> V_69 = V_69 ;
V_58 -> V_31 = 0 ;
V_58 -> V_68 = V_68 ;
V_58 -> V_67 = true ;
F_37 ( V_68 , V_81 ) ;
F_38 ( V_69 -> V_82 , V_83 , & V_84 ) ;
F_39 ( & V_58 -> V_63 , F_21 ) ;
F_40 ( & V_58 -> V_70 ,
F_27 ) ;
F_30 ( V_58 -> V_69 , & V_58 -> V_63 ) ;
}
static void F_41 ( unsigned long V_68 )
{
struct V_57 * V_58 = F_34 ( V_79 , V_68 ) ;
if ( ! V_58 -> V_69 )
return;
V_58 -> V_67 = false ;
F_42 () ;
F_43 ( & V_58 -> V_63 ) ;
F_44 ( & V_58 -> V_70 ) ;
F_45 ( V_58 -> V_68 , V_81 ) ;
F_46 ( V_58 -> V_69 ) ;
V_58 -> V_69 = NULL ;
}
static int F_47 ( void )
{
unsigned long V_68 ;
V_47 = F_4 ( V_47 , 0U , V_39 - 1 ) ;
F_48 () ;
V_71 = 0 ;
if ( ! F_25 ( V_71 ) )
V_71 = F_49 () ;
V_67 = true ;
F_32 ( & V_77 , 0 ) ;
F_50 (cpu) {
F_33 ( V_68 ) ;
}
F_51 () ;
return 0 ;
}
static void F_52 ( void )
{
int V_17 ;
V_67 = false ;
if ( F_53 ( V_81 , F_54 () ) ) {
F_55 (i, cpu_clamping_mask, num_possible_cpus()) {
F_56 ( L_4 ,
V_17 ) ;
F_41 ( V_17 ) ;
}
}
}
static int F_57 ( unsigned int V_68 )
{
if ( V_67 == false )
return 0 ;
F_33 ( V_68 ) ;
if ( V_68 == 0 ) {
V_71 = 0 ;
F_5 () ;
}
return 0 ;
}
static int F_58 ( unsigned int V_68 )
{
if ( V_67 == false )
return 0 ;
F_41 ( V_68 ) ;
if ( V_68 != V_71 )
return 0 ;
V_71 = F_59 ( V_85 ) ;
if ( V_71 == V_68 )
V_71 = F_60 ( V_68 , V_85 ) ;
F_5 () ;
return 0 ;
}
static int F_61 ( struct V_86 * V_87 ,
unsigned long * V_88 )
{
* V_88 = V_39 ;
return 0 ;
}
static int F_62 ( struct V_86 * V_87 ,
unsigned long * V_88 )
{
if ( true == V_67 )
* V_88 = V_76 ;
else
* V_88 = - 1 ;
return 0 ;
}
static int F_63 ( struct V_86 * V_87 ,
unsigned long V_89 )
{
int V_4 = 0 ;
V_89 = F_4 ( V_89 , 0UL ,
( unsigned long ) ( V_39 - 1 ) ) ;
if ( V_47 == 0 && V_89 > 0 ) {
F_64 ( L_5 ) ;
V_47 = V_89 ;
V_4 = F_47 () ;
goto V_90;
} else if ( V_47 > 0 && V_89 == 0 ) {
F_64 ( L_6 ) ;
F_52 () ;
V_47 = 0 ;
} else {
V_47 = V_89 ;
F_5 () ;
}
V_90:
return V_4 ;
}
static int T_2 F_65 ( void )
{
if ( ! F_66 ( V_91 ) ) {
F_3 ( L_7 ) ;
return - V_92 ;
}
if ( ! F_9 () ) {
F_64 ( L_8 ) ;
return - V_92 ;
}
F_7 () ;
return 0 ;
}
static int F_67 ( struct V_93 * V_94 , void * V_95 )
{
int V_17 = 0 ;
F_68 ( V_94 , L_9 , V_71 ) ;
F_68 ( V_94 , L_10 ) ;
for ( V_17 = 0 ; V_17 < V_39 ; V_17 ++ ) {
F_68 ( V_94 , L_11 ,
V_17 ,
V_35 [ V_17 ] . V_36 ,
V_35 [ V_17 ] . V_38 ,
V_35 [ V_17 ] . V_96 ) ;
}
return 0 ;
}
static int F_69 ( struct V_97 * V_97 ,
struct V_98 * V_98 )
{
return F_70 ( V_98 , F_67 , V_97 -> V_99 ) ;
}
static inline void F_71 ( void )
{
V_100 = F_72 ( L_12 , NULL ) ;
if ( ! V_100 )
return;
if ( ! F_73 ( L_13 , V_101 , V_100 ,
V_35 , & V_102 ) )
goto V_103;
return;
V_103:
F_74 ( V_100 ) ;
}
static int T_2 F_75 ( void )
{
int V_104 ;
int V_105 ;
V_105 = F_76 ( F_54 () ) * sizeof( long ) ;
V_81 = F_77 ( V_105 , V_106 ) ;
if ( ! V_81 )
return - V_107 ;
V_104 = F_65 () ;
if ( V_104 )
goto V_108;
V_10 = 2 ;
V_104 = F_78 ( V_109 ,
L_14 ,
F_57 ,
F_58 ) ;
if ( V_104 < 0 )
goto V_108;
V_110 = V_104 ;
V_79 = F_79 ( struct V_57 ) ;
if ( ! V_79 ) {
V_104 = - V_107 ;
goto V_111;
}
V_112 = F_80 ( L_12 , NULL ,
& V_113 ) ;
if ( F_36 ( V_112 ) ) {
V_104 = - V_92 ;
goto V_114;
}
if ( ! V_7 )
V_7 = F_29 ( V_115 ) ;
F_71 () ;
return 0 ;
V_114:
F_81 ( V_79 ) ;
V_111:
F_82 ( V_110 ) ;
V_108:
F_83 ( V_81 ) ;
return V_104 ;
}
static void T_3 F_84 ( void )
{
F_52 () ;
F_82 ( V_110 ) ;
F_81 ( V_79 ) ;
F_85 ( V_112 ) ;
F_83 ( V_81 ) ;
F_86 ( & V_77 ) ;
F_74 ( V_100 ) ;
}
