static void F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
case V_3 :
case V_4 :
F_4 ( V_5 ) ;
break;
case V_6 :
F_5 ( V_5 ) ;
break;
default:
F_6 ( L_1 ) ;
break;
}
}
static void F_7 ( void )
{
F_8 ( V_7 , V_8 . V_9 | F_3 ( V_7 ) ) ;
if ( V_10 ) {
F_8 ( V_11 , 0 ) ;
F_8 ( V_12 , V_8 . V_13 ) ;
}
F_8 ( V_14 , V_8 . V_15 ) ;
if ( V_16 )
V_16 () ;
F_1 () ;
}
static void T_1 F_9 ( void )
{
F_10 ( & V_17 ) ;
V_18 -> V_19 = - 1 ;
V_18 -> V_20 = F_3 ( V_1 ) ;
V_10 = ! ! ( F_11 () & V_21 ) ;
if ( V_10 ) {
V_18 -> V_22 |= V_23 ;
F_8 ( V_12 , 0 ) ;
}
F_8 ( V_14 , 0 ) ;
}
static int T_1 F_12 ( struct V_24 * V_25 )
{
if ( V_25 -> V_26 == V_27 ) {
} else if ( V_25 -> V_26 & V_28 ) {
T_2 V_13 = F_3 ( V_12 ) ;
V_13 |= 1UL << V_25 -> V_29 ;
F_8 ( V_12 , V_13 ) ;
} else {
return 0 ;
}
if ( V_25 -> V_30 == V_31 ) {
} else if ( V_25 -> V_30 & V_32 ) {
T_2 V_15 = F_3 ( V_14 ) ;
V_15 |= 1UL << V_25 -> V_33 ;
F_8 ( V_14 , V_15 ) ;
} else {
return 0 ;
}
if ( ( V_25 -> V_34 & V_35 ) && ( V_25 -> V_36 != - 1 ) ) {
T_3 V_37 = V_25 -> V_36 / 32 ;
T_3 V_38 = V_25 -> V_36 % 32 ;
if ( V_37 == 0 )
V_18 -> V_39 |= 1U << V_38 ;
else if ( V_37 == 1 )
V_18 -> V_40 |= 1U << V_38 ;
else
F_6 ( L_2 , V_25 -> V_41 ) ;
}
return 1 ;
}
static int T_1 F_13 ( struct V_24 * V_25 )
{
if ( V_25 -> V_26 != V_27 ) {
if ( V_25 -> V_29 != - 1 ) {
T_2 V_13 = F_3 ( V_12 ) ;
V_13 |= 1UL << V_25 -> V_29 ;
F_8 ( V_12 , V_13 ) ;
}
}
if ( V_25 -> V_30 != V_31 ) {
if ( V_25 -> V_33 != - 1 ) {
T_2 V_15 = F_3 ( V_14 ) ;
V_15 |= 1UL << V_25 -> V_33 ;
F_8 ( V_14 , V_15 ) ;
}
}
if ( ( V_25 -> V_34 & V_35 ) && ( V_25 -> V_36 != - 1 ) ) {
T_3 V_37 = V_25 -> V_36 / 32 ;
T_3 V_38 = V_25 -> V_36 % 32 ;
if ( V_37 == 0 )
V_18 -> V_39 |= 1U << V_38 ;
else if ( V_37 == 1 )
V_18 -> V_40 |= 1U << V_38 ;
else
F_6 ( L_3 , V_25 -> V_41 ) ;
}
return 1 ;
}
static int T_1 F_14 ( struct V_24 * V_25 )
{
return 0 ;
}
static int T_1 F_15 ( struct V_24 * V_25 )
{
T_2 V_9 ;
if ( ! V_10 ) {
F_6 ( L_4 ) ;
return 0 ;
}
F_8 ( V_11 , 0 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 &= ~ V_42 ;
F_8 ( V_7 , V_9 ) ;
V_18 -> V_22 |= V_23 ;
return 1 ;
}
static int T_1 F_16 ( struct V_24 * V_25 )
{
V_18 -> V_39 |= V_43 ;
return 1 ;
}
static int T_1 F_17 ( struct V_24 * V_25 )
{
V_18 -> V_22 |= V_44 ;
V_18 -> V_39 |= V_45 ;
return 1 ;
}
static int T_1 F_18 ( struct V_24 * V_25 )
{
T_2 V_9 ;
V_9 = F_3 ( V_7 ) ;
V_9 |= V_46 ;
V_9 |= V_47 ;
V_9 |= V_48 ;
F_8 ( V_7 , V_9 ) ;
return 1 ;
}
static int T_1 F_19 ( struct V_24 * V_25 )
{
V_18 -> V_22 &= ~ V_49 ;
return 1 ;
}
static int T_1 F_20 ( struct V_24 * V_25 )
{
T_2 V_9 ;
V_9 = F_3 ( V_7 ) ;
V_9 |= V_46 ;
V_9 |= V_47 ;
V_9 |= V_48 ;
F_8 ( V_7 , V_9 ) ;
return 1 ;
}
static int T_1 F_21 ( struct V_24 * V_25 )
{
T_2 V_9 ;
V_9 = F_3 ( V_7 ) ;
V_9 &= ~ V_50 ;
V_9 |= V_51 ;
V_9 &= ~ V_52 ;
V_9 |= 0x10UL << V_53 ;
F_8 ( V_7 , V_9 ) ;
V_18 -> V_54 |= V_55 ;
V_18 -> V_39 |= V_56 ;
return 1 ;
}
static int T_1 F_22 ( struct V_24 * V_25 )
{
T_2 V_9 ;
V_9 = F_3 ( V_7 ) ;
V_9 &= ~ V_50 ;
F_8 ( V_7 , V_9 ) ;
V_18 -> V_54 |= V_55 ;
V_18 -> V_39 |= V_56 ;
return 1 ;
}
static int T_1 F_23 ( struct V_24 * V_25 )
{
#ifdef F_24
V_18 -> V_54 |= V_57 ;
V_18 -> V_54 |= V_55 ;
V_18 -> V_39 |= V_56 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_25 ( struct V_24 * V_25 )
{
T_2 V_9 ;
F_13 ( V_25 ) ;
V_9 = F_3 ( V_7 ) ;
V_9 &= ~ V_58 ;
V_9 |= ( 4UL << V_59 ) ;
F_8 ( V_7 , V_9 ) ;
return 1 ;
}
static void F_26 ( void )
{
T_2 V_13 = F_3 ( V_12 ) ;
V_13 |= F_27 ( 60 ) ;
F_8 ( V_12 , V_13 ) ;
}
static void F_28 ( void )
{
if ( V_10 ) {
F_8 ( V_60 , 0 ) ;
F_8 ( V_61 , 0 ) ;
}
F_8 ( V_62 , 0 ) ;
F_8 ( V_63 , 0 ) ;
F_8 ( V_64 , 0 ) ;
F_8 ( V_65 , 0 ) ;
F_8 ( V_66 , 0 ) ;
}
static int T_1 F_29 ( struct V_24 * V_25 )
{
V_18 -> V_67 = L_5 ;
V_18 -> V_68 = F_4 ;
V_18 -> V_69 = V_70 ;
return 1 ;
}
static int T_1 F_30 ( struct V_24 * V_25 )
{
F_26 () ;
F_28 () ;
V_16 = F_28 ;
V_18 -> V_22 |= V_71 ;
V_18 -> V_39 |= V_72 ;
if ( F_31 ( V_3 ) )
V_18 -> V_22 |= V_73 ;
V_18 -> V_74 = 6 ;
V_18 -> V_75 = V_76 ;
V_18 -> V_77 = L_6 ;
return 1 ;
}
static void F_32 ( void )
{
if ( V_10 )
F_8 ( V_60 , 0 ) ;
F_8 ( V_62 , 0 ) ;
F_8 ( V_63 , 0 ) ;
F_8 ( V_64 , 0 ) ;
F_8 ( V_65 , 0 ) ;
}
static int T_1 F_33 ( struct V_24 * V_25 )
{
V_18 -> V_67 = L_7 ;
V_18 -> V_68 = F_5 ;
V_18 -> V_69 = V_78 ;
return 1 ;
}
static int T_1 F_34 ( struct V_24 * V_25 )
{
F_26 () ;
F_32 () ;
V_16 = F_32 ;
V_18 -> V_22 |= V_71 ;
V_18 -> V_39 |= V_72 ;
V_18 -> V_74 = 6 ;
V_18 -> V_75 = V_76 ;
V_18 -> V_77 = L_8 ;
return 1 ;
}
static int T_1 F_35 ( struct V_24 * V_25 )
{
#ifdef F_36
F_13 ( V_25 ) ;
V_18 -> V_40 |= V_79 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_37 ( struct V_24 * V_25 )
{
F_13 ( V_25 ) ;
V_18 -> V_22 &= ~ V_80 ;
return 1 ;
}
static int T_1 F_38 ( struct V_24 * V_25 )
{
#ifdef F_39
F_13 ( V_25 ) ;
V_18 -> V_22 |= V_81 ;
V_18 -> V_22 |= V_82 ;
V_18 -> V_39 |= V_83 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_40 ( struct V_24 * V_25 )
{
#ifdef F_41
F_13 ( V_25 ) ;
V_18 -> V_22 |= V_84 ;
V_18 -> V_39 |= V_85 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_42 ( struct V_24 * V_25 )
{
V_18 -> V_22 |= V_86 | V_87 ;
return 1 ;
}
static int T_1 F_43 ( struct V_24 * V_25 )
{
V_25 -> V_36 = - 1 ;
F_13 ( V_25 ) ;
return 1 ;
}
static int T_1 F_44 ( struct V_24 * V_25 )
{
T_2 V_9 ;
F_13 ( V_25 ) ;
V_18 -> V_22 |= V_88 ;
V_9 = F_3 ( V_7 ) ;
V_9 |= V_89 ;
F_8 ( V_7 , V_9 ) ;
return 1 ;
}
static int T_1 F_45 ( struct V_24 * V_25 )
{
T_2 V_9 ;
V_9 = F_3 ( V_7 ) ;
V_9 |= V_90 ;
V_9 |= V_91 ;
V_9 |= V_92 ;
F_8 ( V_7 , V_9 ) ;
return 1 ;
}
static int T_1 F_46 ( struct V_24 * V_25 )
{
V_18 -> V_54 |= V_93 ;
return 1 ;
}
static int T_1 F_47 ( char * V_94 )
{
if ( ! V_94 )
return 0 ;
if ( ! strcmp ( V_94 , L_9 ) )
V_95 = false ;
else if ( ! strcmp ( V_94 , L_10 ) )
V_96 = false ;
else
return 1 ;
return 0 ;
}
static void T_1 F_48 ( T_4 V_97 )
{
F_49 ( L_11 , V_97 ) ;
if ( V_97 >= 3000 ) {
V_18 -> V_22 |= V_98 ;
V_18 -> V_40 |= V_99 ;
}
}
static bool T_1 F_50 ( struct V_24 * V_25 )
{
const struct V_100 * V_101 ;
bool V_102 = false ;
int V_103 ;
for ( V_103 = 0 ; V_103 < F_51 ( V_104 ) ; V_103 ++ ) {
V_101 = & V_104 [ V_103 ] ;
if ( ! strcmp ( V_25 -> V_41 , V_101 -> V_41 ) ) {
V_102 = true ;
if ( V_101 -> V_105 ( V_25 ) )
break;
F_49 ( L_12 ,
V_25 -> V_41 ) ;
return false ;
}
}
if ( ! V_102 && V_96 ) {
if ( ! F_12 ( V_25 ) ) {
F_49 ( L_13 ,
V_25 -> V_41 ) ;
return false ;
}
}
if ( V_101 -> V_106 )
V_18 -> V_22 |= V_101 -> V_106 ;
if ( V_102 )
F_52 ( L_14 , V_25 -> V_41 ) ;
else
F_52 ( L_15 , V_25 -> V_41 ) ;
return true ;
}
static T_1 void F_53 ( void )
{
int V_107 = F_3 ( V_1 ) ;
if ( ( V_107 & 0xffffff00 ) == 0x004e0100 )
V_18 -> V_22 |= V_108 ;
}
static void T_1 F_54 ( void )
{
F_53 () ;
if ( V_10 && ! ( V_18 -> V_22 & V_23 ) ) {
F_6 ( L_16 ) ;
V_18 -> V_22 |= V_23 ;
}
V_8 . V_9 = F_3 ( V_7 ) ;
V_8 . V_13 = F_3 ( V_12 ) ;
V_8 . V_15 = F_3 ( V_14 ) ;
F_1 () ;
F_49 ( L_17 ,
V_18 -> V_22 , V_18 -> V_54 ) ;
}
static int T_1 F_55 ( void )
{
unsigned long V_109 , V_110 ;
const char * V_111 ;
V_109 = F_56 () ;
V_110 = F_57 ( V_109 , L_18 ) ;
if ( V_110 == - V_112 )
return false ;
V_111 = F_58 ( V_110 , L_19 , NULL ) ;
if ( ! V_111 )
return false ;
if ( strstr ( V_111 , L_20 ) )
return true ;
return false ;
}
static int T_1 F_59 ( unsigned long V_113 , const char * V_114 ,
int V_115 , void * V_116 )
{
if ( F_60 ( V_113 , L_21 )
&& F_58 ( V_113 , L_22 , NULL ) )
return 1 ;
return 0 ;
}
bool T_1 F_61 ( void )
{
return V_95 ;
}
bool T_1 F_62 ( void * V_117 )
{
V_95 = false ;
if ( ! F_63 ( V_117 ) )
return false ;
if ( ! F_64 ( F_59 , NULL ) )
return false ;
if ( F_55 () )
return false ;
F_9 () ;
V_95 = true ;
return true ;
}
static int T_1 F_65 ( unsigned long V_113 ,
const char * V_114 , int V_103 )
{
const T_5 * V_118 ;
struct V_24 * V_25 ;
int V_119 ;
V_25 = & V_120 [ V_103 ] ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 -> V_113 = V_113 ;
V_25 -> V_41 = V_114 ;
V_118 = F_58 ( V_113 , L_22 , & V_119 ) ;
if ( ! V_118 ) {
F_66 ( L_23 , V_114 ) ;
return 0 ;
}
V_25 -> V_97 = F_67 ( V_118 ) ;
V_118 = F_58 ( V_113 , L_24 , & V_119 ) ;
if ( ! V_118 ) {
F_66 ( L_25 , V_114 ) ;
return 0 ;
}
V_25 -> V_34 = F_67 ( V_118 ) ;
V_118 = F_58 ( V_113 , L_26 , & V_119 ) ;
if ( V_118 )
V_25 -> V_26 = F_67 ( V_118 ) ;
else
V_25 -> V_26 = V_27 ;
V_118 = F_58 ( V_113 , L_27 , & V_119 ) ;
if ( V_118 )
V_25 -> V_30 = F_67 ( V_118 ) ;
else
V_25 -> V_30 = V_31 ;
V_118 = F_58 ( V_113 , L_28 , & V_119 ) ;
if ( V_118 )
V_25 -> V_29 = F_67 ( V_118 ) ;
else
V_25 -> V_29 = - 1 ;
V_118 = F_58 ( V_113 , L_29 , & V_119 ) ;
if ( V_118 )
V_25 -> V_33 = F_67 ( V_118 ) ;
else
V_25 -> V_33 = - 1 ;
V_118 = F_58 ( V_113 , L_30 , & V_119 ) ;
if ( V_118 )
V_25 -> V_36 = F_67 ( V_118 ) ;
else
V_25 -> V_36 = - 1 ;
if ( V_25 -> V_34 & V_121 ) {
if ( ! ( F_11 () & V_21 ) ) {
F_66 ( L_31 , V_114 ) ;
return 0 ;
}
if ( V_25 -> V_26 == V_27 && V_25 -> V_29 != - 1 ) {
F_66 ( L_32 , V_114 ) ;
return 0 ;
}
if ( V_25 -> V_26 == V_28 ) {
if ( V_25 -> V_29 == - 1 ) {
F_66 ( L_33 , V_114 ) ;
return 0 ;
}
}
} else {
if ( V_25 -> V_26 != V_27 || V_25 -> V_29 != - 1 ) {
F_66 ( L_34 , V_114 ) ;
return 0 ;
}
}
if ( V_25 -> V_34 & V_122 ) {
if ( V_25 -> V_30 == V_31 && V_25 -> V_33 != - 1 ) {
F_66 ( L_35 , V_114 ) ;
return 0 ;
}
if ( V_25 -> V_30 == V_32 ) {
if ( V_25 -> V_33 == - 1 ) {
F_66 ( L_36 , V_114 ) ;
return 0 ;
}
}
} else {
if ( V_25 -> V_30 != V_31 || V_25 -> V_33 != - 1 ) {
F_66 ( L_37 , V_114 ) ;
return 0 ;
}
}
if ( ! ( V_25 -> V_34 & V_35 ) ) {
if ( V_25 -> V_36 != - 1 ) {
F_66 ( L_38 , V_114 ) ;
return 0 ;
}
}
if ( ! F_58 ( V_113 , L_39 , & V_119 ) ) {
if ( F_50 ( V_25 ) )
V_25 -> V_123 = 1 ;
else
V_25 -> V_124 = 1 ;
}
return 0 ;
}
static void T_1 F_68 ( struct V_24 * V_25 )
{
const T_5 * V_118 ;
int V_119 ;
int V_125 ;
int V_103 ;
if ( V_25 -> V_123 || V_25 -> V_124 )
return;
V_118 = F_58 ( V_25 -> V_113 , L_39 , & V_119 ) ;
if ( ! V_118 ) {
F_66 ( L_40 , V_25 -> V_41 ) ;
return;
}
V_125 = V_119 / sizeof( int ) ;
for ( V_103 = 0 ; V_103 < V_125 ; V_103 ++ ) {
unsigned long V_126 = F_69 ( V_118 [ V_103 ] ) ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
struct V_24 * V_129 = & V_120 [ V_127 ] ;
if ( F_70 ( V_129 -> V_113 ) == V_126 ) {
F_68 ( V_129 ) ;
if ( V_129 -> V_124 ) {
V_25 -> V_124 = 1 ;
return;
}
}
}
}
if ( F_50 ( V_25 ) )
V_25 -> V_123 = 1 ;
else
V_25 -> V_124 = 1 ;
}
static int T_1 F_71 ( unsigned long V_113 ,
const char * V_114 ,
void * V_116 )
{
int * V_130 = V_116 ;
F_65 ( V_113 , V_114 , * V_130 ) ;
( * V_130 ) ++ ;
return 0 ;
}
static int T_1 F_72 ( unsigned long V_113 ,
const char * V_114 ,
void * V_116 )
{
int * V_130 = V_116 ;
( * V_130 ) ++ ;
return 0 ;
}
static int T_1 F_73 ( unsigned long V_113 , const char
* V_114 , int V_115 , void * V_116 )
{
const T_5 * V_118 ;
int V_130 , V_103 ;
T_4 V_97 ;
if ( ! F_60 ( V_113 , L_21 ) )
return 0 ;
V_118 = F_58 ( V_113 , L_22 , NULL ) ;
if ( ! V_118 )
return 0 ;
V_97 = F_67 ( V_118 ) ;
F_74 ( V_113 , F_72 ,
& V_128 ) ;
V_120 = F_75 (
F_76 ( sizeof( struct V_24 ) *
V_128 , V_131 ) ) ;
F_48 ( V_97 ) ;
V_130 = 0 ;
F_74 ( V_113 , F_71 , & V_130 ) ;
for ( V_103 = 0 ; V_103 < V_128 ; V_103 ++ ) {
struct V_24 * V_25 = & V_120 [ V_103 ] ;
F_68 ( V_25 ) ;
}
V_118 = F_58 ( V_113 , L_41 , NULL ) ;
if ( V_118 && strlen ( ( char * ) V_118 ) != 0 ) {
F_77 ( V_132 , ( char * ) V_118 , sizeof( V_132 ) ) ;
V_18 -> V_133 = V_132 ;
}
F_54 () ;
F_78 ( F_79 ( V_120 ) ,
sizeof( struct V_24 ) * V_128 ) ;
return 0 ;
}
void T_1 F_80 ( void )
{
if ( ! V_95 )
return;
F_64 ( F_73 , NULL ) ;
}
