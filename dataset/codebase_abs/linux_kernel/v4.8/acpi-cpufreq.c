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
static void F_5 ( bool V_18 , const struct V_19 * V_19 )
{
T_1 V_6 ;
T_1 V_20 ;
T_2 V_21 ;
switch ( V_10 . V_11 ) {
case V_12 :
V_20 = V_13 ;
V_21 = V_14 ;
break;
case V_15 :
V_20 = V_16 ;
V_21 = V_17 ;
break;
default:
return;
}
F_6 ( V_19 , V_20 , V_22 ) ;
F_7 (cpu, cpumask) {
struct V_9 * V_23 = F_2 ( V_22 , V_6 ) ;
if ( V_18 )
V_23 -> V_24 &= ~ V_21 ;
else
V_23 -> V_24 |= V_21 ;
}
F_8 ( V_19 , V_20 , V_22 ) ;
}
static int F_9 ( int V_25 )
{
F_10 () ;
F_5 ( V_25 , V_26 ) ;
F_11 () ;
F_12 ( L_1 , V_25 ? L_2 : L_3 ) ;
return 0 ;
}
static T_3 F_13 ( struct V_27 * V_28 , char * V_29 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
if ( F_14 ( ! V_3 ) )
return - V_31 ;
return F_15 ( V_3 -> V_32 , V_29 ) ;
}
static T_3 F_16 ( struct V_27 * V_28 , const char * V_29 ,
T_4 V_33 )
{
int V_34 ;
unsigned int V_25 = 0 ;
if ( ! V_35 . F_9 )
return - V_36 ;
V_34 = F_17 ( V_29 , 10 , & V_25 ) ;
if ( V_34 || V_25 > 1 )
return - V_36 ;
F_9 ( V_25 ) ;
return V_33 ;
}
static T_3 F_18 ( struct V_27 * V_28 , char * V_29 )
{
return sprintf ( V_29 , L_4 , V_35 . V_37 ) ;
}
static int F_19 ( unsigned int V_38 )
{
struct V_39 * V_6 = & F_20 ( V_38 ) ;
return F_21 ( V_6 , V_40 ) ;
}
static int F_22 ( unsigned int V_38 )
{
struct V_39 * V_6 = & F_20 ( V_38 ) ;
return F_21 ( V_6 , V_41 ) ;
}
static unsigned F_23 ( struct V_27 * V_28 , T_1 V_42 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
struct V_1 * V_43 ;
int V_44 ;
V_43 = F_1 ( V_3 ) ;
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ ) {
if ( V_42 == V_43 -> V_46 [ V_44 ] . V_47 )
return V_28 -> V_48 [ V_44 ] . V_49 ;
}
return 0 ;
}
static unsigned F_24 ( struct V_27 * V_28 , T_1 V_9 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
struct V_50 * V_51 ;
struct V_1 * V_43 ;
if ( V_10 . V_11 == V_15 )
V_9 &= V_52 ;
else
V_9 &= V_53 ;
V_43 = F_1 ( V_3 ) ;
F_25 (pos, policy->freq_table)
if ( V_9 == V_43 -> V_46 [ V_51 -> V_30 ] . V_47 )
return V_51 -> V_49 ;
return V_28 -> V_48 [ 0 ] . V_49 ;
}
static unsigned F_26 ( struct V_27 * V_28 , T_1 V_25 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
switch ( V_3 -> V_54 ) {
case V_55 :
case V_56 :
return F_24 ( V_28 , V_25 ) ;
case V_57 :
return F_23 ( V_28 , V_25 ) ;
default:
return 0 ;
}
}
static T_1 F_27 ( struct V_58 * V_59 )
{
T_1 V_25 , V_60 ;
F_28 ( V_61 , V_25 , V_60 ) ;
return V_25 ;
}
static void F_29 ( struct V_58 * V_59 , T_1 V_25 )
{
T_1 V_7 , V_8 ;
F_28 ( V_61 , V_7 , V_8 ) ;
V_7 = ( V_7 & ~ V_53 ) | ( V_25 & V_53 ) ;
F_30 ( V_61 , V_7 , V_8 ) ;
}
static T_1 F_31 ( struct V_58 * V_59 )
{
T_1 V_25 , V_60 ;
F_28 ( V_62 , V_25 , V_60 ) ;
return V_25 ;
}
static void F_32 ( struct V_58 * V_59 , T_1 V_25 )
{
F_30 ( V_62 , V_25 , 0 ) ;
}
static T_1 F_33 ( struct V_58 * V_23 )
{
T_1 V_25 ;
F_34 ( V_23 -> V_63 , & V_25 , V_23 -> V_64 ) ;
return V_25 ;
}
static void F_35 ( struct V_58 * V_23 , T_1 V_25 )
{
F_36 ( V_23 -> V_63 , V_25 , V_23 -> V_64 ) ;
}
static void F_37 ( void * V_65 )
{
struct V_66 * V_67 = V_65 ;
V_67 -> V_25 = V_67 -> V_68 . V_69 ( V_67 -> V_23 ) ;
}
static T_1 F_38 ( struct V_2 * V_3 , const struct V_19 * V_70 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_66 V_67 = {
. V_23 = & V_43 -> V_71 ,
. V_68 . V_69 = V_3 -> V_72 ,
} ;
int V_73 ;
V_73 = F_39 ( V_70 , F_37 , & V_67 , 1 ) ;
F_40 ( V_73 ) ;
return V_67 . V_25 ;
}
static void F_41 ( void * V_65 )
{
struct V_66 * V_67 = V_65 ;
V_67 -> V_68 . V_74 ( V_67 -> V_23 , V_67 -> V_25 ) ;
}
static void F_42 ( struct V_2 * V_3 ,
const struct V_19 * V_70 , T_1 V_25 )
{
struct V_1 * V_43 = F_1 ( V_3 ) ;
struct V_66 V_67 = {
. V_23 = & V_43 -> V_71 ,
. V_25 = V_25 ,
. V_68 . V_74 = V_3 -> V_75 ,
} ;
int V_76 ;
V_76 = F_43 () ;
if ( F_44 ( V_76 , V_70 ) )
F_41 ( & V_67 ) ;
F_45 ( V_70 , F_41 , & V_67 , 1 ) ;
F_46 () ;
}
static T_1 F_47 ( const struct V_19 * V_70 , struct V_2 * V_3 )
{
T_1 V_25 ;
if ( F_14 ( F_48 ( V_70 ) ) )
return 0 ;
V_25 = F_38 ( V_3 , V_70 ) ;
F_12 ( L_5 , V_25 ) ;
return V_25 ;
}
static unsigned int F_49 ( unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_27 * V_28 ;
unsigned int V_77 ;
unsigned int V_78 ;
F_12 ( L_6 , V_6 ) ;
V_28 = F_50 ( V_6 ) ;
if ( F_14 ( ! V_28 ) )
return 0 ;
V_3 = V_28 -> V_30 ;
if ( F_14 ( ! V_3 || ! V_28 -> V_48 ) )
return 0 ;
V_78 = V_28 -> V_48 [ F_1 ( V_3 ) -> V_79 ] . V_49 ;
V_77 = F_26 ( V_28 , F_47 ( F_51 ( V_6 ) , V_3 ) ) ;
if ( V_77 != V_78 ) {
V_3 -> V_80 = 1 ;
}
F_12 ( L_7 , V_77 ) ;
return V_77 ;
}
static unsigned int F_52 ( struct V_27 * V_28 ,
const struct V_19 * V_70 , unsigned int V_77 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
unsigned int V_81 ;
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < 100 ; V_44 ++ ) {
V_81 = F_26 ( V_28 , F_47 ( V_70 , V_3 ) ) ;
if ( V_81 == V_77 )
return 1 ;
F_53 ( 10 ) ;
}
return 0 ;
}
static int F_54 ( struct V_27 * V_28 ,
unsigned int V_82 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
struct V_1 * V_43 ;
const struct V_19 * V_70 ;
unsigned int V_83 = 0 ;
int V_84 = 0 ;
if ( F_14 ( ! V_3 ) ) {
return - V_31 ;
}
V_43 = F_1 ( V_3 ) ;
V_83 = V_28 -> V_48 [ V_82 ] . V_30 ;
if ( V_43 -> V_79 == V_83 ) {
if ( F_14 ( V_3 -> V_80 ) ) {
F_12 ( L_8 ,
V_83 ) ;
V_3 -> V_80 = 0 ;
} else {
F_12 ( L_9 ,
V_83 ) ;
return 0 ;
}
}
V_70 = V_28 -> V_85 == V_86 ?
F_51 ( V_28 -> V_6 ) : V_28 -> V_87 ;
F_42 ( V_3 , V_70 , V_43 -> V_46 [ V_83 ] . V_88 ) ;
if ( V_89 ) {
if ( ! F_52 ( V_28 , V_70 ,
V_28 -> V_48 [ V_82 ] . V_49 ) ) {
F_12 ( L_10 ,
V_28 -> V_6 ) ;
V_84 = - V_90 ;
}
}
if ( ! V_84 )
V_43 -> V_79 = V_83 ;
return V_84 ;
}
unsigned int F_55 ( struct V_27 * V_28 ,
unsigned int V_91 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
struct V_1 * V_43 ;
struct V_50 * V_92 ;
unsigned int V_83 , V_93 , V_82 ;
if ( V_28 -> V_94 == V_91 )
V_82 = V_28 -> V_95 ;
else
V_82 = F_56 ( V_28 , V_91 ) ;
V_92 = & V_28 -> V_48 [ V_82 ] ;
V_93 = V_92 -> V_49 ;
V_83 = V_92 -> V_30 ;
V_43 = F_1 ( V_3 ) ;
if ( V_43 -> V_79 == V_83 ) {
if ( F_14 ( V_3 -> V_80 ) )
V_3 -> V_80 = 0 ;
else
return V_93 ;
}
V_3 -> V_75 ( & V_43 -> V_71 ,
V_43 -> V_46 [ V_83 ] . V_88 ) ;
V_43 -> V_79 = V_83 ;
return V_93 ;
}
static unsigned long
F_57 ( struct V_2 * V_3 , unsigned int V_6 )
{
struct V_1 * V_43 ;
V_43 = F_1 ( V_3 ) ;
if ( V_96 ) {
unsigned int V_44 ;
unsigned long V_77 ;
unsigned long V_97 = V_43 -> V_46 [ 0 ] . V_98 * 1000 ;
for ( V_44 = 0 ; V_44 < ( V_43 -> V_45 - 1 ) ; V_44 ++ ) {
V_77 = V_97 ;
V_97 = V_43 -> V_46 [ V_44 + 1 ] . V_98 * 1000 ;
if ( ( 2 * V_96 ) > ( V_97 + V_77 ) ) {
V_43 -> V_79 = V_44 ;
return V_77 ;
}
}
V_43 -> V_79 = V_43 -> V_45 - 1 ;
return V_97 ;
} else {
V_43 -> V_79 = 0 ;
return V_43 -> V_46 [ 0 ] . V_98 * 1000 ;
}
}
static void F_58 ( void )
{
unsigned int V_44 ;
F_59 (i)
F_60 ( F_2 ( V_4 , V_44 )
-> V_99 ) ;
F_61 ( V_4 ) ;
}
static int F_62 ( struct V_100 * V_101 , unsigned long V_102 ,
void * V_103 )
{
unsigned V_6 = ( long ) V_103 ;
const struct V_19 * V_19 ;
V_19 = F_63 ( V_6 ) ;
switch ( V_102 ) {
case V_104 :
case V_105 :
case V_106 :
case V_107 :
F_5 ( V_35 . V_37 , V_19 ) ;
break;
case V_108 :
case V_109 :
F_5 ( 1 , V_19 ) ;
break;
default:
break;
}
return V_110 ;
}
static int T_5 F_64 ( void )
{
unsigned int V_44 ;
F_12 ( L_11 ) ;
V_4 = F_65 ( struct V_1 ) ;
if ( ! V_4 ) {
F_12 ( L_12 ) ;
return - V_111 ;
}
F_59 (i) {
if ( ! F_66 (
& F_2 ( V_4 , V_44 ) -> V_99 ,
V_112 , F_67 ( V_44 ) ) ) {
F_58 () ;
return - V_111 ;
}
}
F_68 ( V_4 ) ;
return 0 ;
}
static int F_69 ( const struct V_113 * V_114 )
{
V_115 = 1 ;
return 0 ;
}
static int F_70 ( struct V_39 * V_116 )
{
if ( V_116 -> V_11 == V_12 ) {
if ( ( V_116 -> V_117 == 15 ) &&
( V_116 -> V_118 == 6 ) &&
( V_116 -> V_119 == 8 ) ) {
F_71 ( L_13 ) ;
return - V_31 ;
}
}
return 0 ;
}
static int F_72 ( struct V_27 * V_28 )
{
unsigned int V_44 ;
unsigned int V_120 = 0 ;
unsigned int V_6 = V_28 -> V_6 ;
struct V_2 * V_3 ;
unsigned int V_84 = 0 ;
struct V_39 * V_116 = & F_20 ( V_28 -> V_6 ) ;
struct V_1 * V_43 ;
struct V_50 * V_48 ;
#ifdef F_73
static int V_121 ;
#endif
F_12 ( L_14 ) ;
#ifdef F_73
if ( V_121 )
return V_121 ;
V_121 = F_70 ( V_116 ) ;
if ( V_121 )
return V_121 ;
#endif
V_3 = F_74 ( sizeof( * V_3 ) , V_112 ) ;
if ( ! V_3 )
return - V_111 ;
if ( ! F_75 ( & V_3 -> V_32 , V_112 ) ) {
V_84 = - V_111 ;
goto V_122;
}
V_43 = F_2 ( V_4 , V_6 ) ;
V_3 -> V_5 = V_6 ;
V_28 -> V_30 = V_3 ;
if ( F_21 ( V_116 , V_123 ) )
V_35 . V_124 |= V_125 ;
V_84 = F_76 ( V_43 , V_6 ) ;
if ( V_84 )
goto V_126;
V_28 -> V_85 = V_43 -> V_85 ;
if ( V_28 -> V_85 == V_127 ||
V_28 -> V_85 == V_86 ) {
F_77 ( V_28 -> V_87 , V_43 -> V_99 ) ;
}
F_77 ( V_3 -> V_32 , V_43 -> V_99 ) ;
#ifdef F_73
F_78 ( V_128 ) ;
if ( V_115 && ! F_79 ( V_28 ) ) {
V_28 -> V_85 = V_127 ;
F_77 ( V_28 -> V_87 , F_80 ( V_6 ) ) ;
}
if ( F_22 ( V_6 ) && ! V_89 ) {
F_81 ( V_28 -> V_87 ) ;
F_82 ( V_6 , V_28 -> V_87 ) ;
F_77 ( V_3 -> V_32 ,
F_83 ( V_6 ) ) ;
V_28 -> V_85 = V_129 ;
F_84 ( L_15 ) ;
}
#endif
if ( V_43 -> V_45 <= 1 ) {
F_12 ( L_16 ) ;
V_84 = - V_31 ;
goto V_130;
}
if ( V_43 -> V_71 . V_131 != V_43 -> V_132 . V_131 ) {
V_84 = - V_31 ;
goto V_130;
}
switch ( V_43 -> V_71 . V_131 ) {
case V_133 :
if ( V_10 . V_11 == V_15 &&
V_10 . V_117 == 0xf ) {
F_12 ( L_17 ) ;
V_84 = - V_31 ;
goto V_130;
}
F_12 ( L_18 ) ;
V_3 -> V_54 = V_57 ;
V_3 -> V_72 = F_33 ;
V_3 -> V_75 = F_35 ;
break;
case V_134 :
F_12 ( L_19 ) ;
if ( F_19 ( V_6 ) ) {
V_3 -> V_54 = V_55 ;
V_3 -> V_72 = F_27 ;
V_3 -> V_75 = F_29 ;
break;
}
if ( F_22 ( V_6 ) ) {
V_3 -> V_54 = V_56 ;
V_3 -> V_72 = F_31 ;
V_3 -> V_75 = F_32 ;
break;
}
V_84 = - V_31 ;
goto V_130;
default:
F_12 ( L_20 ,
( T_1 ) ( V_43 -> V_71 . V_131 ) ) ;
V_84 = - V_31 ;
goto V_130;
}
V_48 = F_74 ( sizeof( * V_48 ) *
( V_43 -> V_45 + 1 ) , V_112 ) ;
if ( ! V_48 ) {
V_84 = - V_111 ;
goto V_130;
}
V_28 -> V_135 . V_136 = 0 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ ) {
if ( ( V_43 -> V_46 [ V_44 ] . V_136 * 1000 ) >
V_28 -> V_135 . V_136 )
V_28 -> V_135 . V_136 =
V_43 -> V_46 [ V_44 ] . V_136 * 1000 ;
}
if ( V_43 -> V_71 . V_131 == V_134 &&
V_28 -> V_135 . V_136 > 20 * 1000 ) {
V_28 -> V_135 . V_136 = 20 * 1000 ;
F_84 ( L_21 ) ;
}
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ ) {
if ( V_44 > 0 && V_43 -> V_46 [ V_44 ] . V_98 >=
V_48 [ V_120 - 1 ] . V_49 / 1000 )
continue;
V_48 [ V_120 ] . V_30 = V_44 ;
V_48 [ V_120 ] . V_49 =
V_43 -> V_46 [ V_44 ] . V_98 * 1000 ;
V_120 ++ ;
}
V_48 [ V_120 ] . V_49 = V_137 ;
V_43 -> V_79 = 0 ;
V_84 = F_85 ( V_28 , V_48 ) ;
if ( V_84 )
goto V_138;
if ( V_43 -> V_46 [ 0 ] . V_98 * 1000 != V_28 -> V_135 . V_139 )
F_86 ( V_140 L_22 ) ;
switch ( V_43 -> V_71 . V_131 ) {
case V_133 :
V_28 -> V_141 = F_57 ( V_3 , V_28 -> V_6 ) ;
break;
case V_134 :
V_35 . V_142 = F_49 ;
break;
default:
break;
}
F_87 ( V_143 ) ;
F_12 ( L_23 , V_6 ) ;
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ )
F_12 ( L_24 ,
( V_44 == V_43 -> V_79 ? '*' : ' ' ) , V_44 ,
( T_1 ) V_43 -> V_46 [ V_44 ] . V_98 ,
( T_1 ) V_43 -> V_46 [ V_44 ] . V_144 ,
( T_1 ) V_43 -> V_46 [ V_44 ] . V_136 ) ;
V_3 -> V_80 = 1 ;
V_28 -> V_145 = ! V_89 &&
! ( F_79 ( V_28 ) && V_28 -> V_85 != V_86 ) ;
return V_84 ;
V_138:
F_88 ( V_48 ) ;
V_130:
F_89 ( V_6 ) ;
V_126:
F_60 ( V_3 -> V_32 ) ;
V_122:
F_88 ( V_3 ) ;
V_28 -> V_30 = NULL ;
return V_84 ;
}
static int F_90 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
F_12 ( L_25 ) ;
V_28 -> V_145 = false ;
V_28 -> V_30 = NULL ;
F_89 ( V_3 -> V_5 ) ;
F_60 ( V_3 -> V_32 ) ;
F_88 ( V_28 -> V_48 ) ;
F_88 ( V_3 ) ;
return 0 ;
}
static int F_91 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
F_12 ( L_26 ) ;
V_3 -> V_80 = 1 ;
return 0 ;
}
static void T_5 F_92 ( void )
{
if ( F_93 ( V_146 ) || F_93 ( V_147 ) ) {
V_22 = F_94 () ;
if ( ! V_22 )
return;
V_35 . F_9 = F_9 ;
V_35 . V_37 = F_3 ( 0 ) ;
F_95 () ;
F_5 ( V_35 . V_37 ,
V_26 ) ;
F_96 ( & V_148 ) ;
F_97 () ;
}
}
static void F_98 ( void )
{
if ( V_22 ) {
F_99 ( & V_148 ) ;
F_100 ( V_22 ) ;
V_22 = NULL ;
}
}
static int T_5 F_101 ( void )
{
int V_34 ;
if ( V_149 )
return - V_31 ;
if ( F_102 () )
return - V_150 ;
F_12 ( L_27 ) ;
V_34 = F_64 () ;
if ( V_34 )
return V_34 ;
#ifdef F_103
if ( ! F_22 ( 0 ) ) {
struct V_151 * * V_152 ;
F_12 ( L_28 ) ;
for ( V_152 = V_153 ; * V_152 ; V_152 ++ )
if ( * V_152 == & V_154 ) {
* V_152 = NULL ;
break;
}
}
#endif
F_92 () ;
V_34 = F_104 ( & V_35 ) ;
if ( V_34 ) {
F_58 () ;
F_98 () ;
}
return V_34 ;
}
static void T_6 F_105 ( void )
{
F_12 ( L_29 ) ;
F_98 () ;
F_106 ( & V_35 ) ;
F_58 () ;
}
