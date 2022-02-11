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
struct V_49 * V_50 ;
struct V_40 * V_41 ;
if ( V_5 . V_6 == V_10 )
V_4 &= V_51 ;
else
V_4 &= V_52 ;
V_41 = V_26 -> V_43 ;
F_25 (pos, data->freq_table)
if ( V_4 == V_41 -> V_45 [ V_50 -> V_53 ] . V_46 )
return V_50 -> V_48 ;
return V_26 -> V_47 [ 0 ] . V_48 ;
}
static unsigned F_26 ( T_1 V_20 , struct V_25 * V_26 )
{
switch ( V_26 -> V_54 ) {
case V_55 :
case V_56 :
return F_24 ( V_20 , V_26 ) ;
case V_57 :
return F_23 ( V_20 , V_26 ) ;
default:
return 0 ;
}
}
static void F_27 ( void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_1 V_61 ;
switch ( V_60 -> type ) {
case V_55 :
case V_56 :
F_28 ( V_60 -> V_62 . V_4 . V_18 , V_60 -> V_20 , V_61 ) ;
break;
case V_57 :
F_29 ( ( V_63 ) V_60 -> V_62 . V_64 . V_65 ,
& V_60 -> V_20 ,
( T_1 ) V_60 -> V_62 . V_64 . V_66 ) ;
break;
default:
break;
}
}
static void F_30 ( void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_1 V_2 , V_3 ;
switch ( V_60 -> type ) {
case V_55 :
F_28 ( V_60 -> V_62 . V_4 . V_18 , V_2 , V_3 ) ;
V_2 = ( V_2 & ~ V_52 ) | ( V_60 -> V_20 & V_52 ) ;
F_31 ( V_60 -> V_62 . V_4 . V_18 , V_2 , V_3 ) ;
break;
case V_56 :
F_31 ( V_60 -> V_62 . V_4 . V_18 , V_60 -> V_20 , 0 ) ;
break;
case V_57 :
F_32 ( ( V_63 ) V_60 -> V_62 . V_64 . V_65 ,
V_60 -> V_20 ,
( T_1 ) V_60 -> V_62 . V_64 . V_66 ) ;
break;
default:
break;
}
}
static void F_33 ( struct V_59 * V_60 )
{
int V_67 ;
V_60 -> V_20 = 0 ;
V_67 = F_34 ( V_60 -> V_68 , F_27 , V_60 , 1 ) ;
F_35 ( V_67 ) ;
}
static void F_36 ( struct V_59 * V_60 )
{
int V_69 ;
V_69 = F_37 () ;
if ( F_38 ( V_69 , V_60 -> V_68 ) )
F_30 ( V_60 ) ;
F_39 ( V_60 -> V_68 , F_30 , V_60 , 1 ) ;
F_40 () ;
}
static T_1 F_41 ( const struct V_14 * V_68 )
{
struct V_40 * V_41 ;
struct V_59 V_60 ;
if ( F_42 ( F_43 ( V_68 ) ) )
return 0 ;
switch ( F_13 ( V_27 , F_44 ( V_68 ) ) -> V_54 ) {
case V_55 :
V_60 . type = V_55 ;
V_60 . V_62 . V_4 . V_18 = V_70 ;
break;
case V_56 :
V_60 . type = V_56 ;
V_60 . V_62 . V_4 . V_18 = V_71 ;
break;
case V_57 :
V_60 . type = V_57 ;
V_41 = F_13 ( V_27 , F_44 ( V_68 ) ) -> V_43 ;
V_60 . V_62 . V_64 . V_65 = V_41 -> V_72 . V_73 ;
V_60 . V_62 . V_64 . V_66 = V_41 -> V_72 . V_66 ;
break;
default:
return 0 ;
}
V_60 . V_68 = V_68 ;
F_33 ( & V_60 ) ;
F_11 ( L_5 , V_60 . V_20 ) ;
return V_60 . V_20 ;
}
static unsigned int F_45 ( unsigned int V_1 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_1 ) ;
unsigned int V_74 ;
unsigned int V_75 ;
F_11 ( L_6 , V_1 ) ;
if ( F_42 ( V_26 == NULL ||
V_26 -> V_43 == NULL || V_26 -> V_47 == NULL ) ) {
return 0 ;
}
V_75 = V_26 -> V_47 [ V_26 -> V_43 -> V_76 ] . V_48 ;
V_74 = F_26 ( F_41 ( F_46 ( V_1 ) ) , V_26 ) ;
if ( V_74 != V_75 ) {
V_26 -> V_77 = 1 ;
}
F_11 ( L_7 , V_74 ) ;
return V_74 ;
}
static unsigned int F_47 ( const struct V_14 * V_68 , unsigned int V_74 ,
struct V_25 * V_26 )
{
unsigned int V_78 ;
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < 100 ; V_42 ++ ) {
V_78 = F_26 ( F_41 ( V_68 ) , V_26 ) ;
if ( V_78 == V_74 )
return 1 ;
F_48 ( 10 ) ;
}
return 0 ;
}
static int F_49 ( struct V_22 * V_23 ,
unsigned int V_79 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
struct V_40 * V_41 ;
struct V_59 V_60 ;
unsigned int V_80 = 0 ;
int V_81 = 0 ;
if ( F_42 ( V_26 == NULL ||
V_26 -> V_43 == NULL || V_26 -> V_47 == NULL ) ) {
return - V_82 ;
}
V_41 = V_26 -> V_43 ;
V_80 = V_26 -> V_47 [ V_79 ] . V_53 ;
if ( V_41 -> V_76 == V_80 ) {
if ( F_42 ( V_26 -> V_77 ) ) {
F_11 ( L_8 ,
V_80 ) ;
V_26 -> V_77 = 0 ;
} else {
F_11 ( L_9 ,
V_80 ) ;
goto V_83;
}
}
switch ( V_26 -> V_54 ) {
case V_55 :
V_60 . type = V_55 ;
V_60 . V_62 . V_4 . V_18 = V_70 ;
V_60 . V_20 = ( T_1 ) V_41 -> V_45 [ V_80 ] . V_84 ;
break;
case V_56 :
V_60 . type = V_56 ;
V_60 . V_62 . V_4 . V_18 = V_71 ;
V_60 . V_20 = ( T_1 ) V_41 -> V_45 [ V_80 ] . V_84 ;
break;
case V_57 :
V_60 . type = V_57 ;
V_60 . V_62 . V_64 . V_65 = V_41 -> V_72 . V_73 ;
V_60 . V_62 . V_64 . V_66 = V_41 -> V_72 . V_66 ;
V_60 . V_20 = ( T_1 ) V_41 -> V_45 [ V_80 ] . V_84 ;
break;
default:
V_81 = - V_82 ;
goto V_83;
}
if ( V_23 -> V_85 != V_86 )
V_60 . V_68 = V_23 -> V_87 ;
else
V_60 . V_68 = F_46 ( V_23 -> V_1 ) ;
F_36 ( & V_60 ) ;
if ( V_88 ) {
if ( ! F_47 ( V_60 . V_68 , V_26 -> V_47 [ V_79 ] . V_48 ,
V_26 ) ) {
F_11 ( L_10 ,
V_23 -> V_1 ) ;
V_81 = - V_89 ;
}
}
if ( ! V_81 )
V_41 -> V_76 = V_80 ;
V_83:
return V_81 ;
}
static unsigned long
F_50 ( struct V_25 * V_26 , unsigned int V_1 )
{
struct V_40 * V_41 = V_26 -> V_43 ;
if ( V_90 ) {
unsigned int V_42 ;
unsigned long V_74 ;
unsigned long V_91 = V_41 -> V_45 [ 0 ] . V_92 * 1000 ;
for ( V_42 = 0 ; V_42 < ( V_41 -> V_44 - 1 ) ; V_42 ++ ) {
V_74 = V_91 ;
V_91 = V_41 -> V_45 [ V_42 + 1 ] . V_92 * 1000 ;
if ( ( 2 * V_90 ) > ( V_91 + V_74 ) ) {
V_41 -> V_76 = V_42 ;
return V_74 ;
}
}
V_41 -> V_76 = V_41 -> V_44 - 1 ;
return V_91 ;
} else {
V_41 -> V_76 = 0 ;
return V_41 -> V_45 [ 0 ] . V_92 * 1000 ;
}
}
static void F_51 ( void )
{
unsigned int V_42 ;
F_52 (i)
F_53 ( F_6 ( V_93 , V_42 )
-> V_94 ) ;
F_54 ( V_93 ) ;
}
static int F_55 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
unsigned V_1 = ( long ) V_98 ;
const struct V_14 * V_14 ;
V_14 = F_56 ( V_1 ) ;
switch ( V_97 ) {
case V_99 :
case V_100 :
F_3 ( V_31 . V_34 , V_14 ) ;
break;
case V_101 :
case V_102 :
F_3 ( 1 , V_14 ) ;
break;
default:
break;
}
return V_103 ;
}
static int T_5 F_57 ( void )
{
unsigned int V_42 ;
F_11 ( L_11 ) ;
V_93 = F_58 ( struct V_40 ) ;
if ( ! V_93 ) {
F_11 ( L_12 ) ;
return - V_104 ;
}
F_52 (i) {
if ( ! F_59 (
& F_6 ( V_93 , V_42 ) -> V_94 ,
V_105 , F_60 ( V_42 ) ) ) {
F_51 () ;
return - V_104 ;
}
}
F_61 ( V_93 ) ;
return 0 ;
}
static int F_62 ( const struct V_106 * V_107 )
{
V_108 = 1 ;
return 0 ;
}
static int F_63 ( struct V_36 * V_109 )
{
if ( V_109 -> V_6 == V_7 ) {
if ( ( V_109 -> V_110 == 15 ) &&
( V_109 -> V_111 == 6 ) &&
( V_109 -> V_112 == 8 ) ) {
F_64 ( V_113 L_13
L_14
L_15
L_16 ) ;
return - V_82 ;
}
}
return 0 ;
}
static int F_65 ( struct V_22 * V_23 )
{
unsigned int V_42 ;
unsigned int V_114 = 0 ;
unsigned int V_1 = V_23 -> V_1 ;
struct V_25 * V_26 ;
unsigned int V_81 = 0 ;
struct V_36 * V_109 = & F_20 ( V_23 -> V_1 ) ;
struct V_40 * V_41 ;
#ifdef F_66
static int V_115 ;
#endif
F_11 ( L_17 ) ;
#ifdef F_66
if ( V_115 )
return V_115 ;
V_115 = F_63 ( V_109 ) ;
if ( V_115 )
return V_115 ;
#endif
V_26 = F_67 ( sizeof( * V_26 ) , V_105 ) ;
if ( ! V_26 )
return - V_104 ;
if ( ! F_68 ( & V_26 -> V_28 , V_105 ) ) {
V_81 = - V_104 ;
goto V_116;
}
V_26 -> V_43 = F_6 ( V_93 , V_1 ) ;
F_13 ( V_27 , V_1 ) = V_26 ;
if ( F_21 ( V_109 , V_117 ) )
V_31 . V_118 |= V_119 ;
V_81 = F_69 ( V_26 -> V_43 , V_1 ) ;
if ( V_81 )
goto V_120;
V_41 = V_26 -> V_43 ;
V_23 -> V_85 = V_41 -> V_85 ;
if ( V_23 -> V_85 == V_121 ||
V_23 -> V_85 == V_86 ) {
F_70 ( V_23 -> V_87 , V_41 -> V_94 ) ;
}
F_70 ( V_26 -> V_28 , V_41 -> V_94 ) ;
#ifdef F_66
F_71 ( V_122 ) ;
if ( V_108 && ! F_72 ( V_23 ) ) {
V_23 -> V_85 = V_121 ;
F_70 ( V_23 -> V_87 , F_73 ( V_1 ) ) ;
}
if ( F_22 ( V_1 ) && ! V_88 ) {
F_74 ( V_23 -> V_87 ) ;
F_75 ( V_1 , V_23 -> V_87 ) ;
F_70 ( V_26 -> V_28 , F_76 ( V_1 ) ) ;
V_23 -> V_85 = V_123 ;
F_77 ( V_124 L_18 ) ;
}
#endif
if ( V_41 -> V_44 <= 1 ) {
F_11 ( L_19 ) ;
V_81 = - V_82 ;
goto V_125;
}
if ( V_41 -> V_72 . V_126 != V_41 -> V_127 . V_126 ) {
V_81 = - V_82 ;
goto V_125;
}
switch ( V_41 -> V_72 . V_126 ) {
case V_128 :
if ( V_5 . V_6 == V_10 &&
V_5 . V_110 == 0xf ) {
F_11 ( L_20 ) ;
V_81 = - V_82 ;
goto V_125;
}
F_11 ( L_21 ) ;
V_26 -> V_54 = V_57 ;
break;
case V_129 :
F_11 ( L_22 ) ;
if ( F_19 ( V_1 ) ) {
V_26 -> V_54 = V_55 ;
break;
}
if ( F_22 ( V_1 ) ) {
V_26 -> V_54 = V_56 ;
break;
}
V_81 = - V_82 ;
goto V_125;
default:
F_11 ( L_23 ,
( T_1 ) ( V_41 -> V_72 . V_126 ) ) ;
V_81 = - V_82 ;
goto V_125;
}
V_26 -> V_47 = F_67 ( sizeof( * V_26 -> V_47 ) *
( V_41 -> V_44 + 1 ) , V_105 ) ;
if ( ! V_26 -> V_47 ) {
V_81 = - V_104 ;
goto V_125;
}
V_23 -> V_130 . V_131 = 0 ;
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ ) {
if ( ( V_41 -> V_45 [ V_42 ] . V_131 * 1000 ) >
V_23 -> V_130 . V_131 )
V_23 -> V_130 . V_131 =
V_41 -> V_45 [ V_42 ] . V_131 * 1000 ;
}
if ( V_41 -> V_72 . V_126 == V_129 &&
V_23 -> V_130 . V_131 > 20 * 1000 ) {
V_23 -> V_130 . V_131 = 20 * 1000 ;
F_78 ( V_113
L_24 ) ;
}
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ ) {
if ( V_42 > 0 && V_41 -> V_45 [ V_42 ] . V_92 >=
V_26 -> V_47 [ V_114 - 1 ] . V_48 / 1000 )
continue;
V_26 -> V_47 [ V_114 ] . V_53 = V_42 ;
V_26 -> V_47 [ V_114 ] . V_48 =
V_41 -> V_45 [ V_42 ] . V_92 * 1000 ;
V_114 ++ ;
}
V_26 -> V_47 [ V_114 ] . V_48 = V_132 ;
V_41 -> V_76 = 0 ;
V_81 = F_79 ( V_23 , V_26 -> V_47 ) ;
if ( V_81 )
goto V_133;
if ( V_41 -> V_45 [ 0 ] . V_92 * 1000 != V_23 -> V_130 . V_134 )
F_64 (KERN_WARNING FW_WARN L_25 ) ;
switch ( V_41 -> V_72 . V_126 ) {
case V_128 :
V_23 -> V_135 = F_50 ( V_26 , V_23 -> V_1 ) ;
break;
case V_129 :
V_31 . V_136 = F_45 ;
break;
default:
break;
}
F_80 ( V_137 ) ;
F_11 ( L_26 , V_1 ) ;
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ )
F_11 ( L_27 ,
( V_42 == V_41 -> V_76 ? '*' : ' ' ) , V_42 ,
( T_1 ) V_41 -> V_45 [ V_42 ] . V_92 ,
( T_1 ) V_41 -> V_45 [ V_42 ] . V_138 ,
( T_1 ) V_41 -> V_45 [ V_42 ] . V_131 ) ;
V_26 -> V_77 = 1 ;
return V_81 ;
V_133:
F_81 ( V_26 -> V_47 ) ;
V_125:
F_82 ( V_41 , V_1 ) ;
V_120:
F_53 ( V_26 -> V_28 ) ;
V_116:
F_81 ( V_26 ) ;
F_13 ( V_27 , V_1 ) = NULL ;
return V_81 ;
}
static int F_83 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
F_11 ( L_28 ) ;
if ( V_26 ) {
F_13 ( V_27 , V_23 -> V_1 ) = NULL ;
F_82 ( V_26 -> V_43 ,
V_23 -> V_1 ) ;
F_53 ( V_26 -> V_28 ) ;
F_81 ( V_26 -> V_47 ) ;
F_81 ( V_26 ) ;
}
return 0 ;
}
static int F_84 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_13 ( V_27 , V_23 -> V_1 ) ;
F_11 ( L_29 ) ;
V_26 -> V_77 = 1 ;
return 0 ;
}
static void T_5 F_85 ( void )
{
if ( F_86 ( V_139 ) || F_86 ( V_140 ) ) {
V_17 = F_87 () ;
if ( ! V_17 )
return;
V_31 . V_32 = true ;
V_31 . V_34 = F_1 ( 0 ) ;
F_88 () ;
F_3 ( V_31 . V_34 ,
V_21 ) ;
F_89 ( & V_141 ) ;
F_90 () ;
}
}
static void F_91 ( void )
{
if ( V_17 ) {
F_92 ( & V_141 ) ;
F_93 ( V_17 ) ;
V_17 = NULL ;
}
}
static int T_5 F_94 ( void )
{
int V_30 ;
if ( V_142 )
return - V_82 ;
if ( F_95 () )
return - V_143 ;
F_11 ( L_30 ) ;
V_30 = F_57 () ;
if ( V_30 )
return V_30 ;
#ifdef F_96
if ( F_22 ( 0 ) ) {
struct V_144 * * V_145 ;
F_11 ( L_31 ) ;
for ( V_145 = V_146 ; * V_145 != NULL ; V_145 ++ )
;
if ( V_145 [ 1 ] == NULL )
* V_145 = & V_147 ;
}
#endif
F_85 () ;
V_30 = F_97 ( & V_31 ) ;
if ( V_30 ) {
F_51 () ;
F_91 () ;
}
return V_30 ;
}
static void T_6 F_98 ( void )
{
F_11 ( L_32 ) ;
F_91 () ;
F_99 ( & V_31 ) ;
F_51 () ;
}
