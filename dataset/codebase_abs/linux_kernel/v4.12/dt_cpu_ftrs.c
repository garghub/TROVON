static void F_1 ( void )
{
unsigned long V_1 ;
unsigned int V_2 , V_3 ;
switch ( F_2 ( F_3 ( V_4 ) ) ) {
case V_5 :
case V_6 :
case V_7 :
V_3 = V_8 ;
break;
case V_9 :
V_3 = V_10 ;
break;
default:
V_3 = 1 ;
F_4 ( L_1 ) ;
break;
}
asm volatile("ptesync" : : : "memory");
V_1 = V_11 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
asm volatile("tlbiel %0" : : "r" (rb));
V_1 += 1 << V_12 ;
}
asm volatile("ptesync" : : : "memory");
}
static void F_5 ( void )
{
F_6 ( V_13 , V_14 . V_15 | F_3 ( V_13 ) ) ;
if ( V_16 ) {
F_6 ( V_17 , 0 ) ;
F_6 ( V_18 , V_14 . V_19 ) ;
}
F_6 ( V_20 , V_14 . V_21 ) ;
if ( V_22 )
V_22 () ;
F_1 () ;
}
static void T_1 F_7 ( void )
{
F_8 ( & V_23 ) ;
V_24 -> V_25 = - 1 ;
V_24 -> V_26 = F_3 ( V_4 ) ;
V_16 = ! ! ( F_9 () & V_27 ) ;
if ( V_16 ) {
V_24 -> V_28 |= V_29 ;
F_6 ( V_18 , 0 ) ;
}
F_6 ( V_20 , 0 ) ;
}
static int T_1 F_10 ( struct V_30 * V_31 )
{
if ( V_31 -> V_32 == V_33 ) {
} else if ( V_31 -> V_32 & V_34 ) {
T_2 V_19 = F_3 ( V_18 ) ;
V_19 |= 1UL << V_31 -> V_35 ;
F_6 ( V_18 , V_19 ) ;
} else {
return 0 ;
}
if ( V_31 -> V_36 == V_37 ) {
} else if ( V_31 -> V_36 & V_38 ) {
T_2 V_21 = F_3 ( V_20 ) ;
V_21 |= 1UL << V_31 -> V_39 ;
F_6 ( V_20 , V_21 ) ;
} else {
return 0 ;
}
if ( ( V_31 -> V_40 & V_41 ) && ( V_31 -> V_42 != - 1 ) ) {
T_3 V_43 = V_31 -> V_42 / 32 ;
T_3 V_44 = V_31 -> V_42 % 32 ;
if ( V_43 == 0 )
V_24 -> V_45 |= 1U << V_44 ;
else if ( V_43 == 1 )
V_24 -> V_46 |= 1U << V_44 ;
else
F_4 ( L_2 , V_31 -> V_47 ) ;
}
return 1 ;
}
static int T_1 F_11 ( struct V_30 * V_31 )
{
if ( V_31 -> V_32 != V_33 ) {
if ( V_31 -> V_35 != - 1 ) {
T_2 V_19 = F_3 ( V_18 ) ;
V_19 |= 1UL << V_31 -> V_35 ;
F_6 ( V_18 , V_19 ) ;
}
}
if ( V_31 -> V_36 != V_37 ) {
if ( V_31 -> V_39 != - 1 ) {
T_2 V_21 = F_3 ( V_20 ) ;
V_21 |= 1UL << V_31 -> V_39 ;
F_6 ( V_20 , V_21 ) ;
}
}
if ( ( V_31 -> V_40 & V_41 ) && ( V_31 -> V_42 != - 1 ) ) {
T_3 V_43 = V_31 -> V_42 / 32 ;
T_3 V_44 = V_31 -> V_42 % 32 ;
if ( V_43 == 0 )
V_24 -> V_45 |= 1U << V_44 ;
else if ( V_43 == 1 )
V_24 -> V_46 |= 1U << V_44 ;
else
F_4 ( L_3 , V_31 -> V_47 ) ;
}
return 1 ;
}
static int T_1 F_12 ( struct V_30 * V_31 )
{
return 0 ;
}
static int T_1 F_13 ( struct V_30 * V_31 )
{
T_2 V_15 ;
if ( ! V_16 ) {
F_4 ( L_4 ) ;
return 0 ;
}
F_6 ( V_17 , 0 ) ;
V_15 = F_3 ( V_13 ) ;
V_15 &= ~ V_48 ;
F_6 ( V_13 , V_15 ) ;
V_24 -> V_28 |= V_29 ;
return 1 ;
}
static int T_1 F_14 ( struct V_30 * V_31 )
{
V_24 -> V_45 |= V_49 ;
return 1 ;
}
static int T_1 F_15 ( struct V_30 * V_31 )
{
V_24 -> V_28 |= V_50 ;
V_24 -> V_45 |= V_51 ;
return 1 ;
}
static int T_1 F_16 ( struct V_30 * V_31 )
{
T_2 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 |= V_52 ;
V_15 |= V_53 ;
V_15 |= V_54 ;
F_6 ( V_13 , V_15 ) ;
return 1 ;
}
static int T_1 F_17 ( struct V_30 * V_31 )
{
V_24 -> V_28 &= ~ V_55 ;
return 1 ;
}
static int T_1 F_18 ( struct V_30 * V_31 )
{
T_2 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 |= V_52 ;
V_15 |= V_53 ;
V_15 |= V_54 ;
F_6 ( V_13 , V_15 ) ;
return 1 ;
}
static int T_1 F_19 ( struct V_30 * V_31 )
{
T_2 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 &= ~ V_56 ;
V_15 |= V_57 ;
V_15 &= ~ V_58 ;
V_15 |= 0x10UL << V_59 ;
F_6 ( V_13 , V_15 ) ;
V_24 -> V_60 |= V_61 ;
V_24 -> V_45 |= V_62 ;
return 1 ;
}
static int T_1 F_20 ( struct V_30 * V_31 )
{
T_2 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 &= ~ V_56 ;
F_6 ( V_13 , V_15 ) ;
V_24 -> V_60 |= V_61 ;
V_24 -> V_45 |= V_62 ;
return 1 ;
}
static int T_1 F_21 ( struct V_30 * V_31 )
{
#ifdef F_22
V_24 -> V_60 |= V_63 ;
V_24 -> V_60 |= V_61 ;
V_24 -> V_45 |= V_62 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_23 ( struct V_30 * V_31 )
{
T_2 V_15 ;
F_11 ( V_31 ) ;
V_15 = F_3 ( V_13 ) ;
V_15 &= ~ V_64 ;
V_15 |= ( 4UL << V_65 ) ;
F_6 ( V_13 , V_15 ) ;
return 1 ;
}
static void F_24 ( void )
{
T_2 V_19 = F_3 ( V_18 ) ;
V_19 |= F_25 ( 60 ) ;
F_6 ( V_18 , V_19 ) ;
}
static void F_26 ( void )
{
if ( V_16 ) {
F_6 ( V_66 , 0 ) ;
F_6 ( V_67 , 0 ) ;
}
F_6 ( V_68 , 0 ) ;
F_6 ( V_69 , 0 ) ;
F_6 ( V_70 , 0 ) ;
F_6 ( V_71 , 0 ) ;
F_6 ( V_72 , 0 ) ;
}
static int T_1 F_27 ( struct V_30 * V_31 )
{
V_24 -> V_73 = L_5 ;
V_24 -> V_74 = V_75 ;
V_24 -> V_76 = V_77 ;
return 1 ;
}
static int T_1 F_28 ( struct V_30 * V_31 )
{
F_24 () ;
F_26 () ;
V_22 = F_26 ;
V_24 -> V_28 |= V_78 ;
V_24 -> V_45 |= V_79 ;
if ( F_29 ( V_6 ) )
V_24 -> V_28 |= V_80 ;
V_24 -> V_81 = 6 ;
V_24 -> V_82 = V_83 ;
V_24 -> V_84 = L_6 ;
return 1 ;
}
static void F_30 ( void )
{
if ( V_16 )
F_6 ( V_66 , 0 ) ;
F_6 ( V_68 , 0 ) ;
F_6 ( V_69 , 0 ) ;
F_6 ( V_70 , 0 ) ;
F_6 ( V_71 , 0 ) ;
}
static int T_1 F_31 ( struct V_30 * V_31 )
{
V_24 -> V_73 = L_7 ;
V_24 -> V_74 = V_85 ;
V_24 -> V_76 = V_86 ;
return 1 ;
}
static int T_1 F_32 ( struct V_30 * V_31 )
{
F_24 () ;
F_30 () ;
V_22 = F_30 ;
V_24 -> V_28 |= V_78 ;
V_24 -> V_45 |= V_79 ;
V_24 -> V_81 = 6 ;
V_24 -> V_82 = V_83 ;
V_24 -> V_84 = L_8 ;
return 1 ;
}
static int T_1 F_33 ( struct V_30 * V_31 )
{
#ifdef F_34
F_11 ( V_31 ) ;
V_24 -> V_46 |= V_87 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_35 ( struct V_30 * V_31 )
{
F_11 ( V_31 ) ;
V_24 -> V_28 &= ~ V_88 ;
return 1 ;
}
static int T_1 F_36 ( struct V_30 * V_31 )
{
#ifdef F_37
F_11 ( V_31 ) ;
V_24 -> V_28 |= V_89 ;
V_24 -> V_28 |= V_90 ;
V_24 -> V_45 |= V_91 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_38 ( struct V_30 * V_31 )
{
#ifdef F_39
F_11 ( V_31 ) ;
V_24 -> V_28 |= V_92 ;
V_24 -> V_45 |= V_93 ;
return 1 ;
#endif
return 0 ;
}
static int T_1 F_40 ( struct V_30 * V_31 )
{
V_24 -> V_28 |= V_94 | V_95 ;
return 1 ;
}
static int T_1 F_41 ( struct V_30 * V_31 )
{
V_31 -> V_42 = - 1 ;
F_11 ( V_31 ) ;
return 1 ;
}
static int T_1 F_42 ( struct V_30 * V_31 )
{
T_2 V_15 ;
F_11 ( V_31 ) ;
V_24 -> V_28 |= V_96 ;
V_15 = F_3 ( V_13 ) ;
V_15 |= V_97 ;
F_6 ( V_13 , V_15 ) ;
return 1 ;
}
static int T_1 F_43 ( struct V_30 * V_31 )
{
T_2 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 |= V_98 ;
V_15 |= V_99 ;
V_15 |= V_100 ;
F_6 ( V_13 , V_15 ) ;
return 1 ;
}
static int T_1 F_44 ( struct V_30 * V_31 )
{
V_24 -> V_60 |= V_101 ;
return 1 ;
}
static int T_1 F_45 ( char * V_102 )
{
if ( ! V_102 )
return 0 ;
if ( ! strcmp ( V_102 , L_9 ) )
V_103 = false ;
else if ( ! strcmp ( V_102 , L_10 ) )
V_104 = false ;
else
return 1 ;
return 0 ;
}
static void T_1 F_46 ( T_4 V_105 )
{
F_47 ( L_11 , V_105 ) ;
if ( V_105 >= 3000 ) {
V_24 -> V_28 |= V_106 ;
V_24 -> V_46 |= V_107 ;
}
}
static bool T_1 F_48 ( struct V_30 * V_31 )
{
const struct V_108 * V_109 ;
bool V_110 = false ;
int V_2 ;
for ( V_2 = 0 ; V_2 < F_49 ( V_111 ) ; V_2 ++ ) {
V_109 = & V_111 [ V_2 ] ;
if ( ! strcmp ( V_31 -> V_47 , V_109 -> V_47 ) ) {
V_110 = true ;
if ( V_109 -> V_112 ( V_31 ) )
break;
F_47 ( L_12 ,
V_31 -> V_47 ) ;
return false ;
}
}
if ( ! V_110 && V_104 ) {
if ( ! F_10 ( V_31 ) ) {
F_47 ( L_13 ,
V_31 -> V_47 ) ;
return false ;
}
}
if ( V_109 -> V_113 )
V_24 -> V_28 |= V_109 -> V_113 ;
if ( V_110 )
F_50 ( L_14 , V_31 -> V_47 ) ;
else
F_50 ( L_15 , V_31 -> V_47 ) ;
return true ;
}
static T_1 void F_51 ( void )
{
int V_114 = F_3 ( V_4 ) ;
if ( ( V_114 & 0xffffff00 ) == 0x004e0100 )
V_24 -> V_28 |= V_115 ;
}
static void T_1 F_52 ( void )
{
F_51 () ;
if ( V_16 && ! ( V_24 -> V_28 & V_29 ) ) {
F_4 ( L_16 ) ;
V_24 -> V_28 |= V_29 ;
}
V_14 . V_15 = F_3 ( V_13 ) ;
V_14 . V_19 = F_3 ( V_18 ) ;
V_14 . V_21 = F_3 ( V_20 ) ;
F_1 () ;
F_47 ( L_17 ,
V_24 -> V_28 , V_24 -> V_60 ) ;
}
static int T_1 F_53 ( void )
{
unsigned long V_116 , V_117 ;
const char * V_118 ;
V_116 = F_54 () ;
V_117 = F_55 ( V_116 , L_18 ) ;
if ( V_117 == - V_119 )
return false ;
V_118 = F_56 ( V_117 , L_19 , NULL ) ;
if ( ! V_118 )
return false ;
if ( strstr ( V_118 , L_20 ) )
return true ;
return false ;
}
static int T_1 F_57 ( unsigned long V_120 , const char * V_121 ,
int V_122 , void * V_123 )
{
if ( F_58 ( V_120 , L_21 )
&& F_56 ( V_120 , L_22 , NULL ) )
return 1 ;
return 0 ;
}
bool T_1 F_59 ( void )
{
return V_103 ;
}
bool T_1 F_60 ( void * V_124 )
{
V_103 = false ;
if ( ! F_61 ( V_124 ) )
return false ;
if ( ! F_62 ( F_57 , NULL ) )
return false ;
if ( F_53 () )
return false ;
F_7 () ;
V_103 = true ;
return true ;
}
static int T_1 F_63 ( unsigned long V_120 ,
const char * V_121 , int V_2 )
{
const T_5 * V_125 ;
struct V_30 * V_31 ;
int V_126 ;
V_31 = & V_127 [ V_2 ] ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_120 = V_120 ;
V_31 -> V_47 = V_121 ;
V_125 = F_56 ( V_120 , L_22 , & V_126 ) ;
if ( ! V_125 ) {
F_64 ( L_23 , V_121 ) ;
return 0 ;
}
V_31 -> V_105 = F_65 ( V_125 ) ;
V_125 = F_56 ( V_120 , L_24 , & V_126 ) ;
if ( ! V_125 ) {
F_64 ( L_25 , V_121 ) ;
return 0 ;
}
V_31 -> V_40 = F_65 ( V_125 ) ;
V_125 = F_56 ( V_120 , L_26 , & V_126 ) ;
if ( V_125 )
V_31 -> V_32 = F_65 ( V_125 ) ;
else
V_31 -> V_32 = V_33 ;
V_125 = F_56 ( V_120 , L_27 , & V_126 ) ;
if ( V_125 )
V_31 -> V_36 = F_65 ( V_125 ) ;
else
V_31 -> V_36 = V_37 ;
V_125 = F_56 ( V_120 , L_28 , & V_126 ) ;
if ( V_125 )
V_31 -> V_35 = F_65 ( V_125 ) ;
else
V_31 -> V_35 = - 1 ;
V_125 = F_56 ( V_120 , L_29 , & V_126 ) ;
if ( V_125 )
V_31 -> V_39 = F_65 ( V_125 ) ;
else
V_31 -> V_39 = - 1 ;
V_125 = F_56 ( V_120 , L_30 , & V_126 ) ;
if ( V_125 )
V_31 -> V_42 = F_65 ( V_125 ) ;
else
V_31 -> V_42 = - 1 ;
if ( V_31 -> V_40 & V_128 ) {
if ( ! ( F_9 () & V_27 ) ) {
F_64 ( L_31 , V_121 ) ;
return 0 ;
}
if ( V_31 -> V_32 == V_33 && V_31 -> V_35 != - 1 ) {
F_64 ( L_32 , V_121 ) ;
return 0 ;
}
if ( V_31 -> V_32 == V_34 ) {
if ( V_31 -> V_35 == - 1 ) {
F_64 ( L_33 , V_121 ) ;
return 0 ;
}
}
} else {
if ( V_31 -> V_32 != V_33 || V_31 -> V_35 != - 1 ) {
F_64 ( L_34 , V_121 ) ;
return 0 ;
}
}
if ( V_31 -> V_40 & V_129 ) {
if ( V_31 -> V_36 == V_37 && V_31 -> V_39 != - 1 ) {
F_64 ( L_35 , V_121 ) ;
return 0 ;
}
if ( V_31 -> V_36 == V_38 ) {
if ( V_31 -> V_39 == - 1 ) {
F_64 ( L_36 , V_121 ) ;
return 0 ;
}
}
} else {
if ( V_31 -> V_36 != V_37 || V_31 -> V_39 != - 1 ) {
F_64 ( L_37 , V_121 ) ;
return 0 ;
}
}
if ( ! ( V_31 -> V_40 & V_41 ) ) {
if ( V_31 -> V_42 != - 1 ) {
F_64 ( L_38 , V_121 ) ;
return 0 ;
}
}
if ( ! F_56 ( V_120 , L_39 , & V_126 ) ) {
if ( F_48 ( V_31 ) )
V_31 -> V_130 = 1 ;
else
V_31 -> V_131 = 1 ;
}
return 0 ;
}
static void T_1 F_66 ( struct V_30 * V_31 )
{
const T_5 * V_125 ;
int V_126 ;
int V_132 ;
int V_2 ;
if ( V_31 -> V_130 || V_31 -> V_131 )
return;
V_125 = F_56 ( V_31 -> V_120 , L_39 , & V_126 ) ;
if ( ! V_125 ) {
F_64 ( L_40 , V_31 -> V_47 ) ;
return;
}
V_132 = V_126 / sizeof( int ) ;
for ( V_2 = 0 ; V_2 < V_132 ; V_2 ++ ) {
unsigned long V_133 = F_67 ( V_125 [ V_2 ] ) ;
int V_134 ;
for ( V_134 = 0 ; V_134 < V_135 ; V_134 ++ ) {
struct V_30 * V_136 = & V_127 [ V_134 ] ;
if ( F_68 ( V_136 -> V_120 ) == V_133 ) {
F_66 ( V_136 ) ;
if ( V_136 -> V_131 ) {
V_31 -> V_131 = 1 ;
return;
}
}
}
}
if ( F_48 ( V_31 ) )
V_31 -> V_130 = 1 ;
else
V_31 -> V_131 = 1 ;
}
static int T_1 F_69 ( unsigned long V_120 ,
const char * V_121 ,
void * V_123 )
{
int * V_137 = V_123 ;
F_63 ( V_120 , V_121 , * V_137 ) ;
( * V_137 ) ++ ;
return 0 ;
}
static int T_1 F_70 ( unsigned long V_120 ,
const char * V_121 ,
void * V_123 )
{
int * V_137 = V_123 ;
( * V_137 ) ++ ;
return 0 ;
}
static int T_1 F_71 ( unsigned long V_120 , const char
* V_121 , int V_122 , void * V_123 )
{
const T_5 * V_125 ;
int V_137 , V_2 ;
T_4 V_105 ;
if ( ! F_58 ( V_120 , L_21 ) )
return 0 ;
V_125 = F_56 ( V_120 , L_22 , NULL ) ;
if ( ! V_125 )
return 0 ;
V_105 = F_65 ( V_125 ) ;
F_72 ( V_120 , F_70 ,
& V_135 ) ;
V_127 = F_73 (
F_74 ( sizeof( struct V_30 ) *
V_135 , V_138 ) ) ;
F_46 ( V_105 ) ;
V_137 = 0 ;
F_72 ( V_120 , F_69 , & V_137 ) ;
for ( V_2 = 0 ; V_2 < V_135 ; V_2 ++ ) {
struct V_30 * V_31 = & V_127 [ V_2 ] ;
F_66 ( V_31 ) ;
}
V_125 = F_56 ( V_120 , L_41 , NULL ) ;
if ( V_125 && strlen ( ( char * ) V_125 ) != 0 ) {
F_75 ( V_139 , ( char * ) V_125 , sizeof( V_139 ) ) ;
V_24 -> V_140 = V_139 ;
}
F_52 () ;
F_76 ( F_77 ( V_127 ) ,
sizeof( struct V_30 ) * V_135 ) ;
return 0 ;
}
void T_1 F_78 ( void )
{
if ( ! V_103 )
return;
F_62 ( F_71 , NULL ) ;
}
