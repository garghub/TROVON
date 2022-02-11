static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_4 , V_3 -> V_5 ) ;
}
static bool F_3 ( unsigned int V_6 )
{
T_1 V_7 , V_8 ;
T_2 V_9 ;
switch ( V_10 . V_11 ) {
case V_12 :
F_4 ( V_6 , V_13 , & V_7 , & V_8 ) ;
V_9 = V_7 | ( ( T_2 ) V_8 << 32 ) ;
return ! ( V_9 & V_14 ) ;
case V_15 :
F_4 ( V_6 , V_16 , & V_7 , & V_8 ) ;
V_9 = V_7 | ( ( T_2 ) V_8 << 32 ) ;
return ! ( V_9 & V_17 ) ;
}
return false ;
}
static int F_5 ( bool V_18 )
{
T_1 V_19 ;
T_2 V_20 , V_21 ;
switch ( V_10 . V_11 ) {
case V_12 :
V_19 = V_13 ;
V_20 = V_14 ;
break;
case V_15 :
V_19 = V_16 ;
V_20 = V_17 ;
break;
default:
return - V_22 ;
}
F_6 ( V_19 , V_21 ) ;
if ( V_18 )
V_21 &= ~ V_20 ;
else
V_21 |= V_20 ;
F_7 ( V_19 , V_21 ) ;
return 0 ;
}
static void F_8 ( void * V_23 )
{
bool V_18 = ( bool ) V_23 ;
F_5 ( V_18 ) ;
}
static int F_9 ( int V_21 )
{
F_10 () ;
F_11 ( F_8 , ( void * ) ( long ) V_21 , 1 ) ;
F_12 () ;
F_13 ( L_1 , V_21 ? L_2 : L_3 ) ;
return 0 ;
}
static T_3 F_14 ( struct V_24 * V_25 , char * V_26 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
if ( F_15 ( ! V_3 ) )
return - V_28 ;
return F_16 ( V_3 -> V_29 , V_26 ) ;
}
static T_3 F_17 ( struct V_24 * V_25 , const char * V_26 ,
T_4 V_30 )
{
int V_31 ;
unsigned int V_21 = 0 ;
if ( ! V_32 . F_9 )
return - V_22 ;
V_31 = F_18 ( V_26 , 10 , & V_21 ) ;
if ( V_31 || V_21 > 1 )
return - V_22 ;
F_9 ( V_21 ) ;
return V_30 ;
}
static T_3 F_19 ( struct V_24 * V_25 , char * V_26 )
{
return sprintf ( V_26 , L_4 , V_32 . V_33 ) ;
}
static int F_20 ( unsigned int V_34 )
{
struct V_35 * V_6 = & F_21 ( V_34 ) ;
return F_22 ( V_6 , V_36 ) ;
}
static int F_23 ( unsigned int V_34 )
{
struct V_35 * V_6 = & F_21 ( V_34 ) ;
return F_22 ( V_6 , V_37 ) ;
}
static unsigned F_24 ( struct V_24 * V_25 , T_1 V_38 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
struct V_1 * V_39 ;
int V_40 ;
V_39 = F_1 ( V_3 ) ;
for ( V_40 = 0 ; V_40 < V_39 -> V_41 ; V_40 ++ ) {
if ( V_38 == V_39 -> V_42 [ V_40 ] . V_43 )
return V_25 -> V_44 [ V_40 ] . V_45 ;
}
return 0 ;
}
static unsigned F_25 ( struct V_24 * V_25 , T_1 V_9 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
struct V_46 * V_47 ;
struct V_1 * V_39 ;
if ( V_10 . V_11 == V_15 )
V_9 &= V_48 ;
else
V_9 &= V_49 ;
V_39 = F_1 ( V_3 ) ;
F_26 (pos, policy->freq_table)
if ( V_9 == V_39 -> V_42 [ V_47 -> V_27 ] . V_43 )
return V_47 -> V_45 ;
return V_25 -> V_44 [ 0 ] . V_45 ;
}
static unsigned F_27 ( struct V_24 * V_25 , T_1 V_21 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
switch ( V_3 -> V_50 ) {
case V_51 :
case V_52 :
return F_25 ( V_25 , V_21 ) ;
case V_53 :
return F_24 ( V_25 , V_21 ) ;
default:
return 0 ;
}
}
static T_1 F_28 ( struct V_54 * V_55 )
{
T_1 V_21 , V_56 ;
F_29 ( V_57 , V_21 , V_56 ) ;
return V_21 ;
}
static void F_30 ( struct V_54 * V_55 , T_1 V_21 )
{
T_1 V_7 , V_8 ;
F_29 ( V_57 , V_7 , V_8 ) ;
V_7 = ( V_7 & ~ V_49 ) | ( V_21 & V_49 ) ;
F_31 ( V_57 , V_7 , V_8 ) ;
}
static T_1 F_32 ( struct V_54 * V_55 )
{
T_1 V_21 , V_56 ;
F_29 ( V_58 , V_21 , V_56 ) ;
return V_21 ;
}
static void F_33 ( struct V_54 * V_55 , T_1 V_21 )
{
F_31 ( V_58 , V_21 , 0 ) ;
}
static T_1 F_34 ( struct V_54 * V_59 )
{
T_1 V_21 ;
F_35 ( V_59 -> V_60 , & V_21 , V_59 -> V_61 ) ;
return V_21 ;
}
static void F_36 ( struct V_54 * V_59 , T_1 V_21 )
{
F_37 ( V_59 -> V_60 , V_21 , V_59 -> V_61 ) ;
}
static void F_38 ( void * V_62 )
{
struct V_63 * V_64 = V_62 ;
V_64 -> V_21 = V_64 -> V_65 . V_66 ( V_64 -> V_59 ) ;
}
static T_1 F_39 ( struct V_2 * V_3 , const struct V_67 * V_68 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_63 V_64 = {
. V_59 = & V_39 -> V_69 ,
. V_65 . V_66 = V_3 -> V_70 ,
} ;
int V_71 ;
V_71 = F_40 ( V_68 , F_38 , & V_64 , 1 ) ;
F_41 ( V_71 ) ;
return V_64 . V_21 ;
}
static void F_42 ( void * V_62 )
{
struct V_63 * V_64 = V_62 ;
V_64 -> V_65 . V_72 ( V_64 -> V_59 , V_64 -> V_21 ) ;
}
static void F_43 ( struct V_2 * V_3 ,
const struct V_67 * V_68 , T_1 V_21 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_63 V_64 = {
. V_59 = & V_39 -> V_69 ,
. V_21 = V_21 ,
. V_65 . V_72 = V_3 -> V_73 ,
} ;
int V_74 ;
V_74 = F_44 () ;
if ( F_45 ( V_74 , V_68 ) )
F_42 ( & V_64 ) ;
F_46 ( V_68 , F_42 , & V_64 , 1 ) ;
F_47 () ;
}
static T_1 F_48 ( const struct V_67 * V_68 , struct V_2 * V_3 )
{
T_1 V_21 ;
if ( F_15 ( F_49 ( V_68 ) ) )
return 0 ;
V_21 = F_39 ( V_3 , V_68 ) ;
F_13 ( L_5 , V_21 ) ;
return V_21 ;
}
static unsigned int F_50 ( unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_24 * V_25 ;
unsigned int V_75 ;
unsigned int V_76 ;
F_13 ( L_6 , V_6 ) ;
V_25 = F_51 ( V_6 ) ;
if ( F_15 ( ! V_25 ) )
return 0 ;
V_3 = V_25 -> V_27 ;
if ( F_15 ( ! V_3 || ! V_25 -> V_44 ) )
return 0 ;
V_76 = V_25 -> V_44 [ F_1 ( V_3 ) -> V_77 ] . V_45 ;
V_75 = F_27 ( V_25 , F_48 ( F_52 ( V_6 ) , V_3 ) ) ;
if ( V_75 != V_76 ) {
V_3 -> V_78 = 1 ;
}
F_13 ( L_7 , V_75 ) ;
return V_75 ;
}
static unsigned int F_53 ( struct V_24 * V_25 ,
const struct V_67 * V_68 , unsigned int V_75 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
unsigned int V_79 ;
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < 100 ; V_40 ++ ) {
V_79 = F_27 ( V_25 , F_48 ( V_68 , V_3 ) ) ;
if ( V_79 == V_75 )
return 1 ;
F_54 ( 10 ) ;
}
return 0 ;
}
static int F_55 ( struct V_24 * V_25 ,
unsigned int V_80 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
struct V_1 * V_39 ;
const struct V_67 * V_68 ;
unsigned int V_81 = 0 ;
int V_82 = 0 ;
if ( F_15 ( ! V_3 ) ) {
return - V_28 ;
}
V_39 = F_1 ( V_3 ) ;
V_81 = V_25 -> V_44 [ V_80 ] . V_27 ;
if ( V_39 -> V_77 == V_81 ) {
if ( F_15 ( V_3 -> V_78 ) ) {
F_13 ( L_8 ,
V_81 ) ;
V_3 -> V_78 = 0 ;
} else {
F_13 ( L_9 ,
V_81 ) ;
return 0 ;
}
}
V_68 = V_25 -> V_83 == V_84 ?
F_52 ( V_25 -> V_6 ) : V_25 -> V_85 ;
F_43 ( V_3 , V_68 , V_39 -> V_42 [ V_81 ] . V_86 ) ;
if ( V_87 ) {
if ( ! F_53 ( V_25 , V_68 ,
V_25 -> V_44 [ V_80 ] . V_45 ) ) {
F_13 ( L_10 ,
V_25 -> V_6 ) ;
V_82 = - V_88 ;
}
}
if ( ! V_82 )
V_39 -> V_77 = V_81 ;
return V_82 ;
}
unsigned int F_56 ( struct V_24 * V_25 ,
unsigned int V_89 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
struct V_1 * V_39 ;
struct V_46 * V_90 ;
unsigned int V_81 , V_91 , V_80 ;
if ( V_25 -> V_92 == V_89 )
V_80 = V_25 -> V_93 ;
else
V_80 = F_57 ( V_25 , V_89 ) ;
V_90 = & V_25 -> V_44 [ V_80 ] ;
V_91 = V_90 -> V_45 ;
V_81 = V_90 -> V_27 ;
V_39 = F_1 ( V_3 ) ;
if ( V_39 -> V_77 == V_81 ) {
if ( F_15 ( V_3 -> V_78 ) )
V_3 -> V_78 = 0 ;
else
return V_91 ;
}
V_3 -> V_73 ( & V_39 -> V_69 ,
V_39 -> V_42 [ V_81 ] . V_86 ) ;
V_39 -> V_77 = V_81 ;
return V_91 ;
}
static unsigned long
F_58 ( struct V_2 * V_3 , unsigned int V_6 )
{
struct V_1 * V_39 ;
V_39 = F_1 ( V_3 ) ;
if ( V_94 ) {
unsigned int V_40 ;
unsigned long V_75 ;
unsigned long V_95 = V_39 -> V_42 [ 0 ] . V_96 * 1000 ;
for ( V_40 = 0 ; V_40 < ( V_39 -> V_41 - 1 ) ; V_40 ++ ) {
V_75 = V_95 ;
V_95 = V_39 -> V_42 [ V_40 + 1 ] . V_96 * 1000 ;
if ( ( 2 * V_94 ) > ( V_95 + V_75 ) ) {
V_39 -> V_77 = V_40 ;
return V_75 ;
}
}
V_39 -> V_77 = V_39 -> V_41 - 1 ;
return V_95 ;
} else {
V_39 -> V_77 = 0 ;
return V_39 -> V_42 [ 0 ] . V_96 * 1000 ;
}
}
static void F_59 ( void )
{
unsigned int V_40 ;
F_60 (i)
F_61 ( F_2 ( V_4 , V_40 )
-> V_97 ) ;
F_62 ( V_4 ) ;
}
static int F_63 ( unsigned int V_6 )
{
return F_5 ( V_32 . V_33 ) ;
}
static int F_64 ( unsigned int V_6 )
{
return F_5 ( 1 ) ;
}
static int T_5 F_65 ( void )
{
unsigned int V_40 ;
F_13 ( L_11 ) ;
V_4 = F_66 ( struct V_1 ) ;
if ( ! V_4 ) {
F_13 ( L_12 ) ;
return - V_98 ;
}
F_60 (i) {
if ( ! F_67 (
& F_2 ( V_4 , V_40 ) -> V_97 ,
V_99 , F_68 ( V_40 ) ) ) {
F_59 () ;
return - V_98 ;
}
}
F_69 ( V_4 ) ;
return 0 ;
}
static int F_70 ( const struct V_100 * V_101 )
{
V_102 = 1 ;
return 0 ;
}
static int F_71 ( struct V_35 * V_103 )
{
if ( V_103 -> V_11 == V_12 ) {
if ( ( V_103 -> V_104 == 15 ) &&
( V_103 -> V_105 == 6 ) &&
( V_103 -> V_106 == 8 ) ) {
F_72 ( L_13 ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_73 ( struct V_24 * V_25 )
{
unsigned int V_40 ;
unsigned int V_107 = 0 ;
unsigned int V_6 = V_25 -> V_6 ;
struct V_2 * V_3 ;
unsigned int V_82 = 0 ;
struct V_35 * V_103 = & F_21 ( V_25 -> V_6 ) ;
struct V_1 * V_39 ;
struct V_46 * V_44 ;
#ifdef F_74
static int V_108 ;
#endif
F_13 ( L_14 ) ;
#ifdef F_74
if ( V_108 )
return V_108 ;
V_108 = F_71 ( V_103 ) ;
if ( V_108 )
return V_108 ;
#endif
V_3 = F_75 ( sizeof( * V_3 ) , V_99 ) ;
if ( ! V_3 )
return - V_98 ;
if ( ! F_76 ( & V_3 -> V_29 , V_99 ) ) {
V_82 = - V_98 ;
goto V_109;
}
V_39 = F_2 ( V_4 , V_6 ) ;
V_3 -> V_5 = V_6 ;
V_25 -> V_27 = V_3 ;
if ( F_22 ( V_103 , V_110 ) )
V_32 . V_111 |= V_112 ;
V_82 = F_77 ( V_39 , V_6 ) ;
if ( V_82 )
goto V_113;
V_25 -> V_83 = V_39 -> V_83 ;
if ( V_25 -> V_83 == V_114 ||
V_25 -> V_83 == V_84 ) {
F_78 ( V_25 -> V_85 , V_39 -> V_97 ) ;
}
F_78 ( V_3 -> V_29 , V_39 -> V_97 ) ;
#ifdef F_74
F_79 ( V_115 ) ;
if ( V_102 && ! F_80 ( V_25 ) ) {
V_25 -> V_83 = V_114 ;
F_78 ( V_25 -> V_85 , F_81 ( V_6 ) ) ;
}
if ( F_23 ( V_6 ) && ! V_87 ) {
F_82 ( V_25 -> V_85 ) ;
F_83 ( V_6 , V_25 -> V_85 ) ;
F_78 ( V_3 -> V_29 ,
F_84 ( V_6 ) ) ;
V_25 -> V_83 = V_116 ;
F_85 ( L_15 ) ;
}
#endif
if ( V_39 -> V_41 <= 1 ) {
F_13 ( L_16 ) ;
V_82 = - V_28 ;
goto V_117;
}
if ( V_39 -> V_69 . V_118 != V_39 -> V_119 . V_118 ) {
V_82 = - V_28 ;
goto V_117;
}
switch ( V_39 -> V_69 . V_118 ) {
case V_120 :
if ( V_10 . V_11 == V_15 &&
V_10 . V_104 == 0xf ) {
F_13 ( L_17 ) ;
V_82 = - V_28 ;
goto V_117;
}
F_13 ( L_18 ) ;
V_3 -> V_50 = V_53 ;
V_3 -> V_70 = F_34 ;
V_3 -> V_73 = F_36 ;
break;
case V_121 :
F_13 ( L_19 ) ;
if ( F_20 ( V_6 ) ) {
V_3 -> V_50 = V_51 ;
V_3 -> V_70 = F_28 ;
V_3 -> V_73 = F_30 ;
break;
}
if ( F_23 ( V_6 ) ) {
V_3 -> V_50 = V_52 ;
V_3 -> V_70 = F_32 ;
V_3 -> V_73 = F_33 ;
break;
}
V_82 = - V_28 ;
goto V_117;
default:
F_13 ( L_20 ,
( T_1 ) ( V_39 -> V_69 . V_118 ) ) ;
V_82 = - V_28 ;
goto V_117;
}
V_44 = F_75 ( sizeof( * V_44 ) *
( V_39 -> V_41 + 1 ) , V_99 ) ;
if ( ! V_44 ) {
V_82 = - V_98 ;
goto V_117;
}
V_25 -> V_122 . V_123 = 0 ;
for ( V_40 = 0 ; V_40 < V_39 -> V_41 ; V_40 ++ ) {
if ( ( V_39 -> V_42 [ V_40 ] . V_123 * 1000 ) >
V_25 -> V_122 . V_123 )
V_25 -> V_122 . V_123 =
V_39 -> V_42 [ V_40 ] . V_123 * 1000 ;
}
if ( V_39 -> V_69 . V_118 == V_121 &&
V_25 -> V_122 . V_123 > 20 * 1000 ) {
V_25 -> V_122 . V_123 = 20 * 1000 ;
F_85 ( L_21 ) ;
}
for ( V_40 = 0 ; V_40 < V_39 -> V_41 ; V_40 ++ ) {
if ( V_40 > 0 && V_39 -> V_42 [ V_40 ] . V_96 >=
V_44 [ V_107 - 1 ] . V_45 / 1000 )
continue;
V_44 [ V_107 ] . V_27 = V_40 ;
V_44 [ V_107 ] . V_45 =
V_39 -> V_42 [ V_40 ] . V_96 * 1000 ;
V_107 ++ ;
}
V_44 [ V_107 ] . V_45 = V_124 ;
V_39 -> V_77 = 0 ;
V_82 = F_86 ( V_25 , V_44 ) ;
if ( V_82 )
goto V_125;
if ( V_39 -> V_42 [ 0 ] . V_96 * 1000 != V_25 -> V_122 . V_126 )
F_87 ( V_127 L_22 ) ;
switch ( V_39 -> V_69 . V_118 ) {
case V_120 :
V_25 -> V_128 = F_58 ( V_3 , V_25 -> V_6 ) ;
break;
case V_121 :
V_32 . V_129 = F_50 ;
break;
default:
break;
}
F_88 ( V_130 ) ;
F_13 ( L_23 , V_6 ) ;
for ( V_40 = 0 ; V_40 < V_39 -> V_41 ; V_40 ++ )
F_13 ( L_24 ,
( V_40 == V_39 -> V_77 ? '*' : ' ' ) , V_40 ,
( T_1 ) V_39 -> V_42 [ V_40 ] . V_96 ,
( T_1 ) V_39 -> V_42 [ V_40 ] . V_131 ,
( T_1 ) V_39 -> V_42 [ V_40 ] . V_123 ) ;
V_3 -> V_78 = 1 ;
V_25 -> V_132 = ! V_87 &&
! ( F_80 ( V_25 ) && V_25 -> V_83 != V_84 ) ;
return V_82 ;
V_125:
F_89 ( V_44 ) ;
V_117:
F_90 ( V_6 ) ;
V_113:
F_61 ( V_3 -> V_29 ) ;
V_109:
F_89 ( V_3 ) ;
V_25 -> V_27 = NULL ;
return V_82 ;
}
static int F_91 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
F_13 ( L_25 ) ;
V_25 -> V_132 = false ;
V_25 -> V_27 = NULL ;
F_90 ( V_3 -> V_5 ) ;
F_61 ( V_3 -> V_29 ) ;
F_89 ( V_25 -> V_44 ) ;
F_89 ( V_3 ) ;
return 0 ;
}
static int F_92 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = V_25 -> V_27 ;
F_13 ( L_26 ) ;
V_3 -> V_78 = 1 ;
return 0 ;
}
static void T_5 F_93 ( void )
{
int V_31 ;
if ( ! ( F_94 ( V_133 ) || F_94 ( V_134 ) ) )
return;
V_32 . F_9 = F_9 ;
V_32 . V_33 = F_3 ( 0 ) ;
V_31 = F_95 ( V_135 , L_27 ,
F_63 , F_64 ) ;
if ( V_31 < 0 ) {
F_96 ( L_28 ) ;
return;
}
V_136 = V_31 ;
}
static void F_97 ( void )
{
if ( V_136 > 0 )
F_98 ( V_136 ) ;
}
static int T_5 F_99 ( void )
{
int V_31 ;
if ( V_137 )
return - V_28 ;
if ( F_100 () )
return - V_138 ;
F_13 ( L_29 ) ;
V_31 = F_65 () ;
if ( V_31 )
return V_31 ;
#ifdef F_101
if ( ! F_23 ( 0 ) ) {
struct V_139 * * V_140 ;
F_13 ( L_30 ) ;
for ( V_140 = V_141 ; * V_140 ; V_140 ++ )
if ( * V_140 == & V_142 ) {
* V_140 = NULL ;
break;
}
}
#endif
F_93 () ;
V_31 = F_102 ( & V_32 ) ;
if ( V_31 ) {
F_59 () ;
F_97 () ;
}
return V_31 ;
}
static void T_6 F_103 ( void )
{
F_13 ( L_31 ) ;
F_97 () ;
F_104 ( & V_32 ) ;
F_59 () ;
}
