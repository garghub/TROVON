static void F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
case V_3 :
case V_4 :
F_4 ( V_5 ) ;
break;
case V_6 :
F_5 ( V_7 ) ;
break;
default:
F_6 ( L_1 ) ;
break;
}
}
static void F_7 ( void )
{
F_8 ( V_8 , V_9 . V_10 | F_3 ( V_8 ) ) ;
if ( V_11 ) {
F_8 ( V_12 , 0 ) ;
F_8 ( V_13 , V_9 . V_14 ) ;
}
F_8 ( V_15 , V_9 . V_16 ) ;
if ( V_17 )
V_17 () ;
F_1 () ;
}
static void T_1 F_9 ( void )
{
F_10 ( & V_18 ) ;
V_19 -> V_20 = - 1 ;
V_19 -> V_21 = F_3 ( V_1 ) ;
V_11 = ! ! ( F_11 () & V_22 ) ;
if ( V_11 ) {
V_19 -> V_23 |= V_24 ;
F_8 ( V_13 , 0 ) ;
}
F_8 ( V_15 , 0 ) ;
}
static int T_1 F_12 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 == V_28 ) {
} else if ( V_26 -> V_27 & V_29 ) {
T_2 V_14 = F_3 ( V_13 ) ;
V_14 |= 1UL << V_26 -> V_30 ;
F_8 ( V_13 , V_14 ) ;
} else {
return 0 ;
}
if ( V_26 -> V_31 == V_32 ) {
} else if ( V_26 -> V_31 & V_33 ) {
T_2 V_16 = F_3 ( V_15 ) ;
V_16 |= 1UL << V_26 -> V_34 ;
F_8 ( V_15 , V_16 ) ;
} else {
return 0 ;
}
if ( ( V_26 -> V_35 & V_36 ) && ( V_26 -> V_37 != - 1 ) ) {
T_3 V_38 = V_26 -> V_37 / 32 ;
T_3 V_39 = V_26 -> V_37 % 32 ;
if ( V_38 == 0 )
V_19 -> V_40 |= 1U << V_39 ;
else if ( V_38 == 1 )
V_19 -> V_41 |= 1U << V_39 ;
else
F_6 ( L_2 , V_26 -> V_42 ) ;
}
return 1 ;
}
static int T_1 F_13 ( struct V_25 * V_26 )
{
if ( V_26 -> V_27 != V_28 ) {
if ( V_26 -> V_30 != - 1 ) {
T_2 V_14 = F_3 ( V_13 ) ;
V_14 |= 1UL << V_26 -> V_30 ;
F_8 ( V_13 , V_14 ) ;
}
}
if ( V_26 -> V_31 != V_32 ) {
if ( V_26 -> V_34 != - 1 ) {
T_2 V_16 = F_3 ( V_15 ) ;
V_16 |= 1UL << V_26 -> V_34 ;
F_8 ( V_15 , V_16 ) ;
}
}
if ( ( V_26 -> V_35 & V_36 ) && ( V_26 -> V_37 != - 1 ) ) {
T_3 V_38 = V_26 -> V_37 / 32 ;
T_3 V_39 = V_26 -> V_37 % 32 ;
if ( V_38 == 0 )
V_19 -> V_40 |= 1U << V_39 ;
else if ( V_38 == 1 )
V_19 -> V_41 |= 1U << V_39 ;
else
F_6 ( L_3 , V_26 -> V_42 ) ;
}
return 1 ;
}
static int T_1 F_14 ( struct V_25 * V_26 )
{
return 0 ;
}
static int T_1 F_15 ( struct V_25 * V_26 )
{
T_2 V_10 ;
if ( ! V_11 ) {
F_6 ( L_4 ) ;
return 0 ;
}
F_8 ( V_12 , 0 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_43 ;
F_8 ( V_8 , V_10 ) ;
V_19 -> V_23 |= V_24 ;
return 1 ;
}
static int T_1 F_16 ( struct V_25 * V_26 )
{
V_19 -> V_40 |= V_44 ;
return 1 ;
}
static int T_1 F_17 ( struct V_25 * V_26 )
{
V_19 -> V_23 |= V_45 ;
V_19 -> V_40 |= V_46 ;
return 1 ;
}
static int T_1 F_18 ( struct V_25 * V_26 )
{
T_2 V_10 ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_47 ;
V_10 |= V_48 ;
V_10 |= V_49 ;
F_8 ( V_8 , V_10 ) ;
return 1 ;
}
static int T_1 F_19 ( struct V_25 * V_26 )
{
V_19 -> V_23 &= ~ V_50 ;
return 1 ;
}
static int T_1 F_20 ( struct V_25 * V_26 )
{
T_2 V_10 ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_47 ;
V_10 |= V_48 ;
V_10 |= V_49 ;
F_8 ( V_8 , V_10 ) ;
return 1 ;
}
static int T_1 F_21 ( struct V_25 * V_26 )
{
T_2 V_10 ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_51 ;
V_10 |= V_52 ;
V_10 &= ~ V_53 ;
V_10 |= 0x10UL << V_54 ;
F_8 ( V_8 , V_10 ) ;
V_19 -> V_55 |= V_56 ;
V_19 -> V_40 |= V_57 ;
return 1 ;
}
static int T_1 F_22 ( struct V_25 * V_26 )
{
T_2 V_10 ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_51 ;
F_8 ( V_8 , V_10 ) ;
V_19 -> V_55 |= V_56 ;
V_19 -> V_40 |= V_57 ;
return 1 ;
}
static int T_1 F_23 ( struct V_25 * V_26 )
{
#ifdef F_24
V_19 -> V_55 |= V_58 ;
V_19 -> V_55 |= V_56 ;
V_19 -> V_40 |= V_57 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_25 ( struct V_25 * V_26 )
{
T_2 V_10 ;
F_13 ( V_26 ) ;
V_10 = F_3 ( V_8 ) ;
V_10 &= ~ V_59 ;
V_10 |= ( 4UL << V_60 ) ;
F_8 ( V_8 , V_10 ) ;
return 1 ;
}
static void F_26 ( void )
{
T_2 V_14 = F_3 ( V_13 ) ;
V_14 |= F_27 ( 60 ) ;
F_8 ( V_13 , V_14 ) ;
}
static void F_28 ( void )
{
if ( V_11 ) {
F_8 ( V_61 , 0 ) ;
F_8 ( V_62 , 0 ) ;
}
F_8 ( V_63 , 0 ) ;
F_8 ( V_64 , 0 ) ;
F_8 ( V_65 , 0 ) ;
F_8 ( V_66 , 0 ) ;
F_8 ( V_67 , 0 ) ;
}
static int T_1 F_29 ( struct V_25 * V_26 )
{
V_19 -> V_68 = L_5 ;
V_19 -> V_69 = F_4 ;
V_19 -> V_70 = V_71 ;
return 1 ;
}
static int T_1 F_30 ( struct V_25 * V_26 )
{
F_26 () ;
F_28 () ;
V_17 = F_28 ;
V_19 -> V_23 |= V_72 ;
V_19 -> V_40 |= V_73 ;
if ( F_31 ( V_3 ) )
V_19 -> V_23 |= V_74 ;
V_19 -> V_75 = 6 ;
V_19 -> V_76 = V_77 ;
V_19 -> V_78 = L_6 ;
return 1 ;
}
static void F_32 ( void )
{
if ( V_11 )
F_8 ( V_61 , 0 ) ;
F_8 ( V_63 , 0 ) ;
F_8 ( V_64 , 0 ) ;
F_8 ( V_65 , 0 ) ;
F_8 ( V_66 , 0 ) ;
}
static int T_1 F_33 ( struct V_25 * V_26 )
{
V_19 -> V_68 = L_7 ;
V_19 -> V_69 = F_5 ;
V_19 -> V_70 = V_79 ;
return 1 ;
}
static int T_1 F_34 ( struct V_25 * V_26 )
{
F_26 () ;
F_32 () ;
V_17 = F_32 ;
V_19 -> V_23 |= V_72 ;
V_19 -> V_40 |= V_73 ;
V_19 -> V_75 = 6 ;
V_19 -> V_76 = V_77 ;
V_19 -> V_78 = L_8 ;
return 1 ;
}
static int T_1 F_35 ( struct V_25 * V_26 )
{
#ifdef F_36
F_13 ( V_26 ) ;
V_19 -> V_41 |= V_80 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_37 ( struct V_25 * V_26 )
{
F_13 ( V_26 ) ;
V_19 -> V_23 &= ~ V_81 ;
return 1 ;
}
static int T_1 F_38 ( struct V_25 * V_26 )
{
#ifdef F_39
F_13 ( V_26 ) ;
V_19 -> V_23 |= V_82 ;
V_19 -> V_23 |= V_83 ;
V_19 -> V_40 |= V_84 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_40 ( struct V_25 * V_26 )
{
#ifdef F_41
F_13 ( V_26 ) ;
V_19 -> V_23 |= V_85 ;
V_19 -> V_40 |= V_86 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_42 ( struct V_25 * V_26 )
{
V_19 -> V_23 |= V_87 | V_88 ;
return 1 ;
}
static int T_1 F_43 ( struct V_25 * V_26 )
{
V_26 -> V_37 = - 1 ;
F_13 ( V_26 ) ;
return 1 ;
}
static int T_1 F_44 ( struct V_25 * V_26 )
{
T_2 V_10 ;
F_13 ( V_26 ) ;
V_19 -> V_23 |= V_89 ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_90 ;
F_8 ( V_8 , V_10 ) ;
return 1 ;
}
static int T_1 F_45 ( struct V_25 * V_26 )
{
T_2 V_10 ;
V_10 = F_3 ( V_8 ) ;
V_10 |= V_91 ;
V_10 |= V_92 ;
V_10 |= V_93 ;
F_8 ( V_8 , V_10 ) ;
return 1 ;
}
static int T_1 F_46 ( struct V_25 * V_26 )
{
V_19 -> V_55 |= V_94 ;
return 1 ;
}
static int T_1 F_47 ( char * V_95 )
{
if ( ! V_95 )
return 0 ;
if ( ! strcmp ( V_95 , L_9 ) )
V_96 = false ;
else if ( ! strcmp ( V_95 , L_10 ) )
V_97 = false ;
else
return 1 ;
return 0 ;
}
static void T_1 F_48 ( T_4 V_98 )
{
F_49 ( L_11 , V_98 ) ;
if ( V_98 >= 3000 ) {
V_19 -> V_23 |= V_99 ;
V_19 -> V_41 |= V_100 ;
}
}
static bool T_1 F_50 ( struct V_25 * V_26 )
{
const struct V_101 * V_102 ;
bool V_103 = false ;
int V_104 ;
for ( V_104 = 0 ; V_104 < F_51 ( V_105 ) ; V_104 ++ ) {
V_102 = & V_105 [ V_104 ] ;
if ( ! strcmp ( V_26 -> V_42 , V_102 -> V_42 ) ) {
V_103 = true ;
if ( V_102 -> V_106 ( V_26 ) )
break;
F_49 ( L_12 ,
V_26 -> V_42 ) ;
return false ;
}
}
if ( ! V_103 && V_97 ) {
if ( ! F_12 ( V_26 ) ) {
F_49 ( L_13 ,
V_26 -> V_42 ) ;
return false ;
}
}
if ( V_102 -> V_107 )
V_19 -> V_23 |= V_102 -> V_107 ;
if ( V_103 )
F_52 ( L_14 , V_26 -> V_42 ) ;
else
F_52 ( L_15 , V_26 -> V_42 ) ;
return true ;
}
static T_1 void F_53 ( void )
{
int V_108 = F_3 ( V_1 ) ;
if ( ( V_108 & 0xffffff00 ) == 0x004e0100 )
V_19 -> V_23 |= V_109 ;
}
static void T_1 F_54 ( void )
{
F_53 () ;
if ( V_11 && ! ( V_19 -> V_23 & V_24 ) ) {
F_6 ( L_16 ) ;
V_19 -> V_23 |= V_24 ;
}
V_9 . V_10 = F_3 ( V_8 ) ;
V_9 . V_14 = F_3 ( V_13 ) ;
V_9 . V_16 = F_3 ( V_15 ) ;
F_1 () ;
F_49 ( L_17 ,
V_19 -> V_23 , V_19 -> V_55 ) ;
}
static int T_1 F_55 ( void )
{
unsigned long V_110 , V_111 ;
const char * V_112 ;
V_110 = F_56 () ;
V_111 = F_57 ( V_110 , L_18 ) ;
if ( V_111 == - V_113 )
return false ;
V_112 = F_58 ( V_111 , L_19 , NULL ) ;
if ( ! V_112 )
return false ;
if ( strstr ( V_112 , L_20 ) )
return true ;
return false ;
}
static int T_1 F_59 ( unsigned long V_114 , const char * V_115 ,
int V_116 , void * V_117 )
{
if ( F_60 ( V_114 , L_21 )
&& F_58 ( V_114 , L_22 , NULL ) )
return 1 ;
return 0 ;
}
bool T_1 F_61 ( void )
{
return V_96 ;
}
bool T_1 F_62 ( void * V_118 )
{
V_96 = false ;
if ( ! F_63 ( V_118 ) )
return false ;
if ( ! F_64 ( F_59 , NULL ) )
return false ;
if ( F_55 () )
return false ;
F_9 () ;
V_96 = true ;
return true ;
}
static int T_1 F_65 ( unsigned long V_114 ,
const char * V_115 , int V_104 )
{
const T_5 * V_119 ;
struct V_25 * V_26 ;
int V_120 ;
V_26 = & V_121 [ V_104 ] ;
memset ( V_26 , 0 , sizeof( struct V_25 ) ) ;
V_26 -> V_114 = V_114 ;
V_26 -> V_42 = V_115 ;
V_119 = F_58 ( V_114 , L_22 , & V_120 ) ;
if ( ! V_119 ) {
F_66 ( L_23 , V_115 ) ;
return 0 ;
}
V_26 -> V_98 = F_67 ( V_119 ) ;
V_119 = F_58 ( V_114 , L_24 , & V_120 ) ;
if ( ! V_119 ) {
F_66 ( L_25 , V_115 ) ;
return 0 ;
}
V_26 -> V_35 = F_67 ( V_119 ) ;
V_119 = F_58 ( V_114 , L_26 , & V_120 ) ;
if ( V_119 )
V_26 -> V_27 = F_67 ( V_119 ) ;
else
V_26 -> V_27 = V_28 ;
V_119 = F_58 ( V_114 , L_27 , & V_120 ) ;
if ( V_119 )
V_26 -> V_31 = F_67 ( V_119 ) ;
else
V_26 -> V_31 = V_32 ;
V_119 = F_58 ( V_114 , L_28 , & V_120 ) ;
if ( V_119 )
V_26 -> V_30 = F_67 ( V_119 ) ;
else
V_26 -> V_30 = - 1 ;
V_119 = F_58 ( V_114 , L_29 , & V_120 ) ;
if ( V_119 )
V_26 -> V_34 = F_67 ( V_119 ) ;
else
V_26 -> V_34 = - 1 ;
V_119 = F_58 ( V_114 , L_30 , & V_120 ) ;
if ( V_119 )
V_26 -> V_37 = F_67 ( V_119 ) ;
else
V_26 -> V_37 = - 1 ;
if ( V_26 -> V_35 & V_122 ) {
if ( ! ( F_11 () & V_22 ) ) {
F_66 ( L_31 , V_115 ) ;
return 0 ;
}
if ( V_26 -> V_27 == V_28 && V_26 -> V_30 != - 1 ) {
F_66 ( L_32 , V_115 ) ;
return 0 ;
}
if ( V_26 -> V_27 == V_29 ) {
if ( V_26 -> V_30 == - 1 ) {
F_66 ( L_33 , V_115 ) ;
return 0 ;
}
}
} else {
if ( V_26 -> V_27 != V_28 || V_26 -> V_30 != - 1 ) {
F_66 ( L_34 , V_115 ) ;
return 0 ;
}
}
if ( V_26 -> V_35 & V_123 ) {
if ( V_26 -> V_31 == V_32 && V_26 -> V_34 != - 1 ) {
F_66 ( L_35 , V_115 ) ;
return 0 ;
}
if ( V_26 -> V_31 == V_33 ) {
if ( V_26 -> V_34 == - 1 ) {
F_66 ( L_36 , V_115 ) ;
return 0 ;
}
}
} else {
if ( V_26 -> V_31 != V_32 || V_26 -> V_34 != - 1 ) {
F_66 ( L_37 , V_115 ) ;
return 0 ;
}
}
if ( ! ( V_26 -> V_35 & V_36 ) ) {
if ( V_26 -> V_37 != - 1 ) {
F_66 ( L_38 , V_115 ) ;
return 0 ;
}
}
if ( ! F_58 ( V_114 , L_39 , & V_120 ) ) {
if ( F_50 ( V_26 ) )
V_26 -> V_124 = 1 ;
else
V_26 -> V_125 = 1 ;
}
return 0 ;
}
static void T_1 F_68 ( struct V_25 * V_26 )
{
const T_5 * V_119 ;
int V_120 ;
int V_126 ;
int V_104 ;
if ( V_26 -> V_124 || V_26 -> V_125 )
return;
V_119 = F_58 ( V_26 -> V_114 , L_39 , & V_120 ) ;
if ( ! V_119 ) {
F_66 ( L_40 , V_26 -> V_42 ) ;
return;
}
V_126 = V_120 / sizeof( int ) ;
for ( V_104 = 0 ; V_104 < V_126 ; V_104 ++ ) {
unsigned long V_127 = F_69 ( V_119 [ V_104 ] ) ;
int V_128 ;
for ( V_128 = 0 ; V_128 < V_129 ; V_128 ++ ) {
struct V_25 * V_130 = & V_121 [ V_128 ] ;
if ( F_70 ( V_130 -> V_114 ) == V_127 ) {
F_68 ( V_130 ) ;
if ( V_130 -> V_125 ) {
V_26 -> V_125 = 1 ;
return;
}
}
}
}
if ( F_50 ( V_26 ) )
V_26 -> V_124 = 1 ;
else
V_26 -> V_125 = 1 ;
}
static int T_1 F_71 ( unsigned long V_114 ,
const char * V_115 ,
void * V_117 )
{
int * V_131 = V_117 ;
F_65 ( V_114 , V_115 , * V_131 ) ;
( * V_131 ) ++ ;
return 0 ;
}
static int T_1 F_72 ( unsigned long V_114 ,
const char * V_115 ,
void * V_117 )
{
int * V_131 = V_117 ;
( * V_131 ) ++ ;
return 0 ;
}
static int T_1 F_73 ( unsigned long V_114 , const char
* V_115 , int V_116 , void * V_117 )
{
const T_5 * V_119 ;
int V_131 , V_104 ;
T_4 V_98 ;
if ( ! F_60 ( V_114 , L_21 ) )
return 0 ;
V_119 = F_58 ( V_114 , L_22 , NULL ) ;
if ( ! V_119 )
return 0 ;
V_98 = F_67 ( V_119 ) ;
F_74 ( V_114 , F_72 ,
& V_129 ) ;
V_121 = F_75 (
F_76 ( sizeof( struct V_25 ) *
V_129 , V_132 ) ) ;
F_48 ( V_98 ) ;
V_131 = 0 ;
F_74 ( V_114 , F_71 , & V_131 ) ;
for ( V_104 = 0 ; V_104 < V_129 ; V_104 ++ ) {
struct V_25 * V_26 = & V_121 [ V_104 ] ;
F_68 ( V_26 ) ;
}
V_119 = F_58 ( V_114 , L_41 , NULL ) ;
if ( V_119 && strlen ( ( char * ) V_119 ) != 0 ) {
F_77 ( V_133 , ( char * ) V_119 , sizeof( V_133 ) ) ;
V_19 -> V_134 = V_133 ;
}
F_54 () ;
F_78 ( F_79 ( V_121 ) ,
sizeof( struct V_25 ) * V_129 ) ;
return 0 ;
}
void T_1 F_80 ( void )
{
if ( ! V_96 )
return;
F_64 ( F_73 , NULL ) ;
}
