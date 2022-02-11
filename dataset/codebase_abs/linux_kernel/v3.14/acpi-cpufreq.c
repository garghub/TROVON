static bool F_1 ( unsigned int V_1 )
{
T_1 V_2 , V_3 ;
T_2 V_4 ;
switch ( V_5 . V_6 ) {
case V_7 :
F_2 ( V_1 , V_8 , & V_2 , & V_3 ) ;
V_4 = V_2 | ( ( T_2 ) V_3 << 32 ) ;
return ! ( V_4 & V_9 ) ;
case V_10 :
F_2 ( V_1 , V_11 , & V_2 , & V_3 ) ;
V_4 = V_2 | ( ( T_2 ) V_3 << 32 ) ;
return ! ( V_4 & V_12 ) ;
}
return false ;
}
static void F_3 ( bool V_13 , const struct V_14 * V_14 )
{
T_1 V_1 ;
T_1 V_15 ;
T_2 V_16 ;
switch ( V_5 . V_6 ) {
case V_7 :
V_15 = V_8 ;
V_16 = V_9 ;
break;
case V_10 :
V_15 = V_11 ;
V_16 = V_12 ;
break;
default:
return;
}
F_4 ( V_14 , V_15 , V_17 ) ;
F_5 (cpu, cpumask) {
struct V_4 * V_18 = F_6 ( V_17 , V_1 ) ;
if ( V_13 )
V_18 -> V_19 &= ~ V_16 ;
else
V_18 -> V_19 |= V_16 ;
}
F_7 ( V_14 , V_15 , V_17 ) ;
}
static int F_8 ( int V_20 )
{
F_9 () ;
F_3 ( V_20 , V_21 ) ;
F_10 () ;
F_11 ( L_1 , V_20 ? L_2 : L_3 ) ;
return 0 ;
}
static T_3 F_12 ( struct V_22 * V_23 , char * V_24 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
return F_14 ( V_26 -> V_28 , V_24 ) ;
}
static T_3 F_15 ( const char * V_24 , T_4 V_29 )
{
int V_30 ;
unsigned long V_20 = 0 ;
if ( ! V_31 . V_32 )
return - V_33 ;
V_30 = F_16 ( V_24 , 10 , & V_20 ) ;
if ( V_30 || ( V_20 > 1 ) )
return - V_33 ;
F_8 ( ( int ) V_20 ) ;
return V_29 ;
}
static T_3 F_17 ( struct V_22 * V_23 , const char * V_24 ,
T_4 V_29 )
{
return F_15 ( V_24 , V_29 ) ;
}
static T_3 F_18 ( struct V_22 * V_23 , char * V_24 )
{
return sprintf ( V_24 , L_4 , V_31 . V_34 ) ;
}
static int F_19 ( unsigned int V_35 )
{
struct V_36 * V_1 = & F_20 ( V_35 ) ;
return F_21 ( V_1 , V_37 ) ;
}
static int F_22 ( unsigned int V_35 )
{
struct V_36 * V_1 = & F_20 ( V_35 ) ;
return F_21 ( V_1 , V_38 ) ;
}
static unsigned F_23 ( T_1 V_39 , struct V_25 * V_26 )
{
struct V_40 * V_41 ;
int V_42 ;
V_41 = V_26 -> V_43 ;
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ ) {
if ( V_39 == V_41 -> V_45 [ V_42 ] . V_46 )
return V_26 -> V_47 [ V_42 ] . V_48 ;
}
return 0 ;
}
static unsigned F_24 ( T_1 V_4 , struct V_25 * V_26 )
{
int V_42 ;
struct V_40 * V_41 ;
if ( V_5 . V_6 == V_10 )
V_4 &= V_49 ;
else
V_4 &= V_50 ;
V_41 = V_26 -> V_43 ;
for ( V_42 = 0 ; V_26 -> V_47 [ V_42 ] . V_48 != V_51 ; V_42 ++ ) {
if ( V_4 == V_41 -> V_45 [ V_26 -> V_47 [ V_42 ] . V_52 ] . V_46 )
return V_26 -> V_47 [ V_42 ] . V_48 ;
}
return V_26 -> V_47 [ 0 ] . V_48 ;
}
static unsigned F_25 ( T_1 V_20 , struct V_25 * V_26 )
{
switch ( V_26 -> V_53 ) {
case V_54 :
case V_55 :
return F_24 ( V_20 , V_26 ) ;
case V_56 :
return F_23 ( V_20 , V_26 ) ;
default:
return 0 ;
}
}
static void F_26 ( void * V_57 )
{
struct V_58 * V_59 = V_57 ;
T_1 V_60 ;
switch ( V_59 -> type ) {
case V_54 :
case V_55 :
F_27 ( V_59 -> V_61 . V_4 . V_18 , V_59 -> V_20 , V_60 ) ;
break;
case V_56 :
F_28 ( ( V_62 ) V_59 -> V_61 . V_63 . V_64 ,
& V_59 -> V_20 ,
( T_1 ) V_59 -> V_61 . V_63 . V_65 ) ;
break;
default:
break;
}
}
static void F_29 ( void * V_57 )
{
struct V_58 * V_59 = V_57 ;
T_1 V_2 , V_3 ;
switch ( V_59 -> type ) {
case V_54 :
F_27 ( V_59 -> V_61 . V_4 . V_18 , V_2 , V_3 ) ;
V_2 = ( V_2 & ~ V_50 ) | ( V_59 -> V_20 & V_50 ) ;
F_30 ( V_59 -> V_61 . V_4 . V_18 , V_2 , V_3 ) ;
break;
case V_55 :
F_30 ( V_59 -> V_61 . V_4 . V_18 , V_59 -> V_20 , 0 ) ;
break;
case V_56 :
F_31 ( ( V_62 ) V_59 -> V_61 . V_63 . V_64 ,
V_59 -> V_20 ,
( T_1 ) V_59 -> V_61 . V_63 . V_65 ) ;
break;
default:
break;
}
}
static void F_32 ( struct V_58 * V_59 )
{
int V_66 ;
V_59 -> V_20 = 0 ;
V_66 = F_33 ( V_59 -> V_67 , F_26 , V_59 , 1 ) ;
F_34 ( V_66 ) ;
}
static void F_35 ( struct V_58 * V_59 )
{
int V_68 ;
V_68 = F_36 () ;
if ( F_37 ( V_68 , V_59 -> V_67 ) )
F_29 ( V_59 ) ;
F_38 ( V_59 -> V_67 , F_29 , V_59 , 1 ) ;
F_39 () ;
}
static T_1 F_40 ( const struct V_14 * V_67 )
{
struct V_40 * V_41 ;
struct V_58 V_59 ;
if ( F_41 ( F_42 ( V_67 ) ) )
return 0 ;
switch ( F_13 ( V_27 , F_43 ( V_67 ) ) -> V_53 ) {
case V_54 :
V_59 . type = V_54 ;
V_59 . V_61 . V_4 . V_18 = V_69 ;
break;
case V_55 :
V_59 . type = V_55 ;
V_59 . V_61 . V_4 . V_18 = V_70 ;
break;
case V_56 :
V_59 . type = V_56 ;
V_41 = F_13 ( V_27 , F_43 ( V_67 ) ) -> V_43 ;
V_59 . V_61 . V_63 . V_64 = V_41 -> V_71 . V_72 ;
V_59 . V_61 . V_63 . V_65 = V_41 -> V_71 . V_65 ;
break;
default:
return 0 ;
}
V_59 . V_67 = V_67 ;
F_32 ( & V_59 ) ;
F_11 ( L_5 , V_59 . V_20 ) ;
return V_59 . V_20 ;
}
static unsigned int F_44 ( unsigned int V_1 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_1 ) ;
unsigned int V_73 ;
unsigned int V_74 ;
F_11 ( L_6 , V_1 ) ;
if ( F_41 ( V_26 == NULL ||
V_26 -> V_43 == NULL || V_26 -> V_47 == NULL ) ) {
return 0 ;
}
V_74 = V_26 -> V_47 [ V_26 -> V_43 -> V_75 ] . V_48 ;
V_73 = F_25 ( F_40 ( F_45 ( V_1 ) ) , V_26 ) ;
if ( V_73 != V_74 ) {
V_26 -> V_76 = 1 ;
}
F_11 ( L_7 , V_73 ) ;
return V_73 ;
}
static unsigned int F_46 ( const struct V_14 * V_67 , unsigned int V_73 ,
struct V_25 * V_26 )
{
unsigned int V_77 ;
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_77 = F_25 ( F_40 ( V_67 ) , V_26 ) ;
if ( V_77 == V_73 )
return 1 ;
F_47 ( 10 ) ;
}
return 0 ;
}
static int F_48 ( struct V_22 * V_23 ,
unsigned int V_78 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
struct V_40 * V_41 ;
struct V_58 V_59 ;
unsigned int V_79 = 0 ;
int V_80 = 0 ;
if ( F_41 ( V_26 == NULL ||
V_26 -> V_43 == NULL || V_26 -> V_47 == NULL ) ) {
return - V_81 ;
}
V_41 = V_26 -> V_43 ;
V_79 = V_26 -> V_47 [ V_78 ] . V_52 ;
if ( V_41 -> V_75 == V_79 ) {
if ( F_41 ( V_26 -> V_76 ) ) {
F_11 ( L_8 ,
V_79 ) ;
V_26 -> V_76 = 0 ;
} else {
F_11 ( L_9 ,
V_79 ) ;
goto V_82;
}
}
switch ( V_26 -> V_53 ) {
case V_54 :
V_59 . type = V_54 ;
V_59 . V_61 . V_4 . V_18 = V_69 ;
V_59 . V_20 = ( T_1 ) V_41 -> V_45 [ V_79 ] . V_83 ;
break;
case V_55 :
V_59 . type = V_55 ;
V_59 . V_61 . V_4 . V_18 = V_70 ;
V_59 . V_20 = ( T_1 ) V_41 -> V_45 [ V_79 ] . V_83 ;
break;
case V_56 :
V_59 . type = V_56 ;
V_59 . V_61 . V_63 . V_64 = V_41 -> V_71 . V_72 ;
V_59 . V_61 . V_63 . V_65 = V_41 -> V_71 . V_65 ;
V_59 . V_20 = ( T_1 ) V_41 -> V_45 [ V_79 ] . V_83 ;
break;
default:
V_80 = - V_81 ;
goto V_82;
}
if ( V_23 -> V_84 != V_85 )
V_59 . V_67 = V_23 -> V_86 ;
else
V_59 . V_67 = F_45 ( V_23 -> V_1 ) ;
F_35 ( & V_59 ) ;
if ( V_87 ) {
if ( ! F_46 ( V_59 . V_67 , V_26 -> V_47 [ V_78 ] . V_48 ,
V_26 ) ) {
F_11 ( L_10 ,
V_23 -> V_1 ) ;
V_80 = - V_88 ;
}
}
if ( ! V_80 )
V_41 -> V_75 = V_79 ;
V_82:
return V_80 ;
}
static unsigned long
F_49 ( struct V_25 * V_26 , unsigned int V_1 )
{
struct V_40 * V_41 = V_26 -> V_43 ;
if ( V_89 ) {
unsigned int V_42 ;
unsigned long V_73 ;
unsigned long V_90 = V_41 -> V_45 [ 0 ] . V_91 * 1000 ;
for ( V_42 = 0 ; V_42 < ( V_41 -> V_44 - 1 ) ; V_42 ++ ) {
V_73 = V_90 ;
V_90 = V_41 -> V_45 [ V_42 + 1 ] . V_91 * 1000 ;
if ( ( 2 * V_89 ) > ( V_90 + V_73 ) ) {
V_41 -> V_75 = V_42 ;
return V_73 ;
}
}
V_41 -> V_75 = V_41 -> V_44 - 1 ;
return V_90 ;
} else {
V_41 -> V_75 = 0 ;
return V_41 -> V_45 [ 0 ] . V_91 * 1000 ;
}
}
static void F_50 ( void )
{
unsigned int V_42 ;
F_51 (i)
F_52 ( F_6 ( V_92 , V_42 )
-> V_93 ) ;
F_53 ( V_92 ) ;
}
static int F_54 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
unsigned V_1 = ( long ) V_97 ;
const struct V_14 * V_14 ;
V_14 = F_55 ( V_1 ) ;
switch ( V_96 ) {
case V_98 :
case V_99 :
F_3 ( V_31 . V_34 , V_14 ) ;
break;
case V_100 :
case V_101 :
F_3 ( 1 , V_14 ) ;
break;
default:
break;
}
return V_102 ;
}
static int T_5 F_56 ( void )
{
unsigned int V_42 ;
F_11 ( L_11 ) ;
V_92 = F_57 ( struct V_40 ) ;
if ( ! V_92 ) {
F_11 ( L_12 ) ;
return - V_103 ;
}
F_51 (i) {
if ( ! F_58 (
& F_6 ( V_92 , V_42 ) -> V_93 ,
V_104 , F_59 ( V_42 ) ) ) {
F_50 () ;
return - V_103 ;
}
}
F_60 ( V_92 ) ;
return 0 ;
}
static int F_61 ( const struct V_105 * V_106 )
{
V_107 = 1 ;
return 0 ;
}
static int F_62 ( struct V_36 * V_108 )
{
if ( V_108 -> V_6 == V_7 ) {
if ( ( V_108 -> V_109 == 15 ) &&
( V_108 -> V_110 == 6 ) &&
( V_108 -> V_111 == 8 ) ) {
F_63 ( V_112 L_13
L_14
L_15
L_16 ) ;
return - V_81 ;
}
}
return 0 ;
}
static int F_64 ( struct V_22 * V_23 )
{
unsigned int V_42 ;
unsigned int V_113 = 0 ;
unsigned int V_1 = V_23 -> V_1 ;
struct V_25 * V_26 ;
unsigned int V_80 = 0 ;
struct V_36 * V_108 = & F_20 ( V_23 -> V_1 ) ;
struct V_40 * V_41 ;
#ifdef F_65
static int V_114 ;
#endif
F_11 ( L_17 ) ;
#ifdef F_65
if ( V_114 )
return V_114 ;
V_114 = F_62 ( V_108 ) ;
if ( V_114 )
return V_114 ;
#endif
V_26 = F_66 ( sizeof( * V_26 ) , V_104 ) ;
if ( ! V_26 )
return - V_103 ;
if ( ! F_67 ( & V_26 -> V_28 , V_104 ) ) {
V_80 = - V_103 ;
goto V_115;
}
V_26 -> V_43 = F_6 ( V_92 , V_1 ) ;
F_13 ( V_27 , V_1 ) = V_26 ;
if ( F_21 ( V_108 , V_116 ) )
V_31 . V_117 |= V_118 ;
V_80 = F_68 ( V_26 -> V_43 , V_1 ) ;
if ( V_80 )
goto V_119;
V_41 = V_26 -> V_43 ;
V_23 -> V_84 = V_41 -> V_84 ;
if ( V_23 -> V_84 == V_120 ||
V_23 -> V_84 == V_85 ) {
F_69 ( V_23 -> V_86 , V_41 -> V_93 ) ;
}
F_69 ( V_26 -> V_28 , V_41 -> V_93 ) ;
#ifdef F_65
F_70 ( V_121 ) ;
if ( V_107 && ! F_71 ( V_23 ) ) {
V_23 -> V_84 = V_120 ;
F_69 ( V_23 -> V_86 , F_72 ( V_1 ) ) ;
}
if ( F_22 ( V_1 ) && ! V_87 ) {
F_73 ( V_23 -> V_86 ) ;
F_74 ( V_1 , V_23 -> V_86 ) ;
F_69 ( V_26 -> V_28 , F_75 ( V_1 ) ) ;
V_23 -> V_84 = V_122 ;
F_76 ( V_123 L_18 ) ;
}
#endif
if ( V_41 -> V_44 <= 1 ) {
F_11 ( L_19 ) ;
V_80 = - V_81 ;
goto V_124;
}
if ( V_41 -> V_71 . V_125 != V_41 -> V_126 . V_125 ) {
V_80 = - V_81 ;
goto V_124;
}
switch ( V_41 -> V_71 . V_125 ) {
case V_127 :
if ( V_5 . V_6 == V_10 &&
V_5 . V_109 == 0xf ) {
F_11 ( L_20 ) ;
V_80 = - V_81 ;
goto V_124;
}
F_11 ( L_21 ) ;
V_26 -> V_53 = V_56 ;
break;
case V_128 :
F_11 ( L_22 ) ;
if ( F_19 ( V_1 ) ) {
V_26 -> V_53 = V_54 ;
break;
}
if ( F_22 ( V_1 ) ) {
V_26 -> V_53 = V_55 ;
break;
}
V_80 = - V_81 ;
goto V_124;
default:
F_11 ( L_23 ,
( T_1 ) ( V_41 -> V_71 . V_125 ) ) ;
V_80 = - V_81 ;
goto V_124;
}
V_26 -> V_47 = F_77 ( sizeof( * V_26 -> V_47 ) *
( V_41 -> V_44 + 1 ) , V_104 ) ;
if ( ! V_26 -> V_47 ) {
V_80 = - V_103 ;
goto V_124;
}
V_23 -> V_129 . V_130 = 0 ;
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ ) {
if ( ( V_41 -> V_45 [ V_42 ] . V_130 * 1000 ) >
V_23 -> V_129 . V_130 )
V_23 -> V_129 . V_130 =
V_41 -> V_45 [ V_42 ] . V_130 * 1000 ;
}
if ( V_41 -> V_71 . V_125 == V_128 &&
V_23 -> V_129 . V_130 > 20 * 1000 ) {
V_23 -> V_129 . V_130 = 20 * 1000 ;
F_78 ( V_112
L_24 ) ;
}
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ ) {
if ( V_42 > 0 && V_41 -> V_45 [ V_42 ] . V_91 >=
V_26 -> V_47 [ V_113 - 1 ] . V_48 / 1000 )
continue;
V_26 -> V_47 [ V_113 ] . V_52 = V_42 ;
V_26 -> V_47 [ V_113 ] . V_48 =
V_41 -> V_45 [ V_42 ] . V_91 * 1000 ;
V_113 ++ ;
}
V_26 -> V_47 [ V_113 ] . V_48 = V_51 ;
V_41 -> V_75 = 0 ;
V_80 = F_79 ( V_23 , V_26 -> V_47 ) ;
if ( V_80 )
goto V_131;
if ( V_41 -> V_45 [ 0 ] . V_91 * 1000 != V_23 -> V_129 . V_132 )
F_63 (KERN_WARNING FW_WARN L_25 ) ;
switch ( V_41 -> V_71 . V_125 ) {
case V_127 :
V_23 -> V_133 = F_49 ( V_26 , V_23 -> V_1 ) ;
break;
case V_128 :
V_31 . V_134 = F_44 ;
break;
default:
break;
}
F_80 ( V_135 ) ;
F_11 ( L_26 , V_1 ) ;
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ )
F_11 ( L_27 ,
( V_42 == V_41 -> V_75 ? '*' : ' ' ) , V_42 ,
( T_1 ) V_41 -> V_45 [ V_42 ] . V_91 ,
( T_1 ) V_41 -> V_45 [ V_42 ] . V_136 ,
( T_1 ) V_41 -> V_45 [ V_42 ] . V_130 ) ;
V_26 -> V_76 = 1 ;
return V_80 ;
V_131:
F_81 ( V_26 -> V_47 ) ;
V_124:
F_82 ( V_41 , V_1 ) ;
V_119:
F_52 ( V_26 -> V_28 ) ;
V_115:
F_81 ( V_26 ) ;
F_13 ( V_27 , V_1 ) = NULL ;
return V_80 ;
}
static int F_83 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
F_11 ( L_28 ) ;
if ( V_26 ) {
F_84 ( V_23 -> V_1 ) ;
F_13 ( V_27 , V_23 -> V_1 ) = NULL ;
F_82 ( V_26 -> V_43 ,
V_23 -> V_1 ) ;
F_52 ( V_26 -> V_28 ) ;
F_81 ( V_26 -> V_47 ) ;
F_81 ( V_26 ) ;
}
return 0 ;
}
static int F_85 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
F_11 ( L_29 ) ;
V_26 -> V_76 = 1 ;
return 0 ;
}
static void T_5 F_86 ( void )
{
if ( F_87 ( V_137 ) || F_87 ( V_138 ) ) {
V_17 = F_88 () ;
if ( ! V_17 )
return;
V_31 . V_32 = true ;
V_31 . V_34 = F_1 ( 0 ) ;
F_9 () ;
F_3 ( V_31 . V_34 ,
V_21 ) ;
F_89 ( & V_139 ) ;
F_10 () ;
}
}
static void F_90 ( void )
{
if ( V_17 ) {
F_91 ( & V_139 ) ;
F_92 ( V_17 ) ;
V_17 = NULL ;
}
}
static int T_5 F_93 ( void )
{
int V_30 ;
if ( V_140 )
return - V_81 ;
if ( F_94 () )
return - V_141 ;
F_11 ( L_30 ) ;
V_30 = F_56 () ;
if ( V_30 )
return V_30 ;
#ifdef F_95
if ( F_22 ( 0 ) ) {
struct V_142 * * V_143 ;
F_11 ( L_31 ) ;
for ( V_143 = V_144 ; * V_143 != NULL ; V_143 ++ )
;
if ( V_143 [ 1 ] == NULL )
* V_143 = & V_145 ;
}
#endif
F_86 () ;
V_30 = F_96 ( & V_31 ) ;
if ( V_30 ) {
F_50 () ;
F_90 () ;
}
return V_30 ;
}
static void T_6 F_97 ( void )
{
F_11 ( L_32 ) ;
F_90 () ;
F_98 ( & V_31 ) ;
F_50 () ;
}
