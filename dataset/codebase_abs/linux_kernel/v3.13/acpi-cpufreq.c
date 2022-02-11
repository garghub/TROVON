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
static T_3 F_8 ( const char * V_20 , T_4 V_21 )
{
int V_22 ;
unsigned long V_23 = 0 ;
if ( ! V_24 )
return - V_25 ;
V_22 = F_9 ( V_20 , 10 , & V_23 ) ;
if ( V_22 || ( V_23 > 1 ) )
return - V_25 ;
if ( ( V_23 && V_26 ) || ( ! V_23 && ! V_26 ) )
return V_21 ;
F_10 () ;
F_3 ( V_23 , V_27 ) ;
F_11 () ;
V_26 = V_23 ;
F_12 ( L_1 , V_23 ? L_2 : L_3 ) ;
return V_21 ;
}
static T_3 F_13 ( struct V_28 * V_29 , struct V_30 * V_31 ,
const char * V_20 , T_4 V_21 )
{
return F_8 ( V_20 , V_21 ) ;
}
static T_3 F_14 ( struct V_28 * V_29 ,
struct V_30 * V_31 , char * V_20 )
{
return sprintf ( V_20 , L_4 , V_26 ) ;
}
static T_3 F_15 ( struct V_32 * V_33 , char * V_20 )
{
struct V_34 * V_35 = F_16 ( V_36 , V_33 -> V_1 ) ;
return F_17 ( V_35 -> V_37 , V_20 ) ;
}
static T_3 F_18 ( struct V_32 * V_33 , const char * V_20 ,
T_4 V_21 )
{
return F_8 ( V_20 , V_21 ) ;
}
static T_3 F_19 ( struct V_32 * V_33 , char * V_20 )
{
return sprintf ( V_20 , L_4 , V_26 ) ;
}
static int F_20 ( unsigned int V_38 )
{
struct V_39 * V_1 = & F_21 ( V_38 ) ;
return F_22 ( V_1 , V_40 ) ;
}
static int F_23 ( unsigned int V_38 )
{
struct V_39 * V_1 = & F_21 ( V_38 ) ;
return F_22 ( V_1 , V_41 ) ;
}
static unsigned F_24 ( T_1 V_42 , struct V_34 * V_35 )
{
struct V_43 * V_44 ;
int V_45 ;
V_44 = V_35 -> V_46 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
if ( V_42 == V_44 -> V_48 [ V_45 ] . V_49 )
return V_35 -> V_50 [ V_45 ] . V_51 ;
}
return 0 ;
}
static unsigned F_25 ( T_1 V_4 , struct V_34 * V_35 )
{
int V_45 ;
struct V_43 * V_44 ;
if ( V_5 . V_6 == V_10 )
V_4 &= V_52 ;
else
V_4 &= V_53 ;
V_44 = V_35 -> V_46 ;
for ( V_45 = 0 ; V_35 -> V_50 [ V_45 ] . V_51 != V_54 ; V_45 ++ ) {
if ( V_4 == V_44 -> V_48 [ V_35 -> V_50 [ V_45 ] . V_55 ] . V_49 )
return V_35 -> V_50 [ V_45 ] . V_51 ;
}
return V_35 -> V_50 [ 0 ] . V_51 ;
}
static unsigned F_26 ( T_1 V_23 , struct V_34 * V_35 )
{
switch ( V_35 -> V_56 ) {
case V_57 :
case V_58 :
return F_25 ( V_23 , V_35 ) ;
case V_59 :
return F_24 ( V_23 , V_35 ) ;
default:
return 0 ;
}
}
static void F_27 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
T_1 V_63 ;
switch ( V_62 -> type ) {
case V_57 :
case V_58 :
F_28 ( V_62 -> V_64 . V_4 . V_18 , V_62 -> V_23 , V_63 ) ;
break;
case V_59 :
F_29 ( ( V_65 ) V_62 -> V_64 . V_66 . V_67 ,
& V_62 -> V_23 ,
( T_1 ) V_62 -> V_64 . V_66 . V_68 ) ;
break;
default:
break;
}
}
static void F_30 ( void * V_60 )
{
struct V_61 * V_62 = V_60 ;
T_1 V_2 , V_3 ;
switch ( V_62 -> type ) {
case V_57 :
F_28 ( V_62 -> V_64 . V_4 . V_18 , V_2 , V_3 ) ;
V_2 = ( V_2 & ~ V_53 ) | ( V_62 -> V_23 & V_53 ) ;
F_31 ( V_62 -> V_64 . V_4 . V_18 , V_2 , V_3 ) ;
break;
case V_58 :
F_31 ( V_62 -> V_64 . V_4 . V_18 , V_62 -> V_23 , 0 ) ;
break;
case V_59 :
F_32 ( ( V_65 ) V_62 -> V_64 . V_66 . V_67 ,
V_62 -> V_23 ,
( T_1 ) V_62 -> V_64 . V_66 . V_68 ) ;
break;
default:
break;
}
}
static void F_33 ( struct V_61 * V_62 )
{
int V_69 ;
V_62 -> V_23 = 0 ;
V_69 = F_34 ( V_62 -> V_70 , F_27 , V_62 , 1 ) ;
F_35 ( V_69 ) ;
}
static void F_36 ( struct V_61 * V_62 )
{
int V_71 ;
V_71 = F_37 () ;
if ( F_38 ( V_71 , V_62 -> V_70 ) )
F_30 ( V_62 ) ;
F_39 ( V_62 -> V_70 , F_30 , V_62 , 1 ) ;
F_40 () ;
}
static T_1 F_41 ( const struct V_14 * V_70 )
{
struct V_43 * V_44 ;
struct V_61 V_62 ;
if ( F_42 ( F_43 ( V_70 ) ) )
return 0 ;
switch ( F_16 ( V_36 , F_44 ( V_70 ) ) -> V_56 ) {
case V_57 :
V_62 . type = V_57 ;
V_62 . V_64 . V_4 . V_18 = V_72 ;
break;
case V_58 :
V_62 . type = V_58 ;
V_62 . V_64 . V_4 . V_18 = V_73 ;
break;
case V_59 :
V_62 . type = V_59 ;
V_44 = F_16 ( V_36 , F_44 ( V_70 ) ) -> V_46 ;
V_62 . V_64 . V_66 . V_67 = V_44 -> V_74 . V_75 ;
V_62 . V_64 . V_66 . V_68 = V_44 -> V_74 . V_68 ;
break;
default:
return 0 ;
}
V_62 . V_70 = V_70 ;
F_33 ( & V_62 ) ;
F_12 ( L_5 , V_62 . V_23 ) ;
return V_62 . V_23 ;
}
static unsigned int F_45 ( unsigned int V_1 )
{
struct V_34 * V_35 = F_16 ( V_36 , V_1 ) ;
unsigned int V_76 ;
unsigned int V_77 ;
F_12 ( L_6 , V_1 ) ;
if ( F_42 ( V_35 == NULL ||
V_35 -> V_46 == NULL || V_35 -> V_50 == NULL ) ) {
return 0 ;
}
V_77 = V_35 -> V_50 [ V_35 -> V_46 -> V_78 ] . V_51 ;
V_76 = F_26 ( F_41 ( F_46 ( V_1 ) ) , V_35 ) ;
if ( V_76 != V_77 ) {
V_35 -> V_79 = 1 ;
}
F_12 ( L_7 , V_76 ) ;
return V_76 ;
}
static unsigned int F_47 ( const struct V_14 * V_70 , unsigned int V_76 ,
struct V_34 * V_35 )
{
unsigned int V_80 ;
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < 100 ; V_45 ++ ) {
V_80 = F_26 ( F_41 ( V_70 ) , V_35 ) ;
if ( V_80 == V_76 )
return 1 ;
F_48 ( 10 ) ;
}
return 0 ;
}
static int F_49 ( struct V_32 * V_33 ,
unsigned int V_81 )
{
struct V_34 * V_35 = F_16 ( V_36 , V_33 -> V_1 ) ;
struct V_43 * V_44 ;
struct V_61 V_62 ;
unsigned int V_82 = 0 ;
int V_83 = 0 ;
if ( F_42 ( V_35 == NULL ||
V_35 -> V_46 == NULL || V_35 -> V_50 == NULL ) ) {
return - V_84 ;
}
V_44 = V_35 -> V_46 ;
V_82 = V_35 -> V_50 [ V_81 ] . V_55 ;
if ( V_44 -> V_78 == V_82 ) {
if ( F_42 ( V_35 -> V_79 ) ) {
F_12 ( L_8 ,
V_82 ) ;
V_35 -> V_79 = 0 ;
} else {
F_12 ( L_9 ,
V_82 ) ;
goto V_85;
}
}
switch ( V_35 -> V_56 ) {
case V_57 :
V_62 . type = V_57 ;
V_62 . V_64 . V_4 . V_18 = V_72 ;
V_62 . V_23 = ( T_1 ) V_44 -> V_48 [ V_82 ] . V_86 ;
break;
case V_58 :
V_62 . type = V_58 ;
V_62 . V_64 . V_4 . V_18 = V_73 ;
V_62 . V_23 = ( T_1 ) V_44 -> V_48 [ V_82 ] . V_86 ;
break;
case V_59 :
V_62 . type = V_59 ;
V_62 . V_64 . V_66 . V_67 = V_44 -> V_74 . V_75 ;
V_62 . V_64 . V_66 . V_68 = V_44 -> V_74 . V_68 ;
V_62 . V_23 = ( T_1 ) V_44 -> V_48 [ V_82 ] . V_86 ;
break;
default:
V_83 = - V_84 ;
goto V_85;
}
if ( V_33 -> V_87 != V_88 )
V_62 . V_70 = V_33 -> V_89 ;
else
V_62 . V_70 = F_46 ( V_33 -> V_1 ) ;
F_36 ( & V_62 ) ;
if ( V_90 ) {
if ( ! F_47 ( V_62 . V_70 , V_35 -> V_50 [ V_81 ] . V_51 ,
V_35 ) ) {
F_12 ( L_10 ,
V_33 -> V_1 ) ;
V_83 = - V_91 ;
}
}
if ( ! V_83 )
V_44 -> V_78 = V_82 ;
V_85:
return V_83 ;
}
static unsigned long
F_50 ( struct V_34 * V_35 , unsigned int V_1 )
{
struct V_43 * V_44 = V_35 -> V_46 ;
if ( V_92 ) {
unsigned int V_45 ;
unsigned long V_76 ;
unsigned long V_93 = V_44 -> V_48 [ 0 ] . V_94 * 1000 ;
for ( V_45 = 0 ; V_45 < ( V_44 -> V_47 - 1 ) ; V_45 ++ ) {
V_76 = V_93 ;
V_93 = V_44 -> V_48 [ V_45 + 1 ] . V_94 * 1000 ;
if ( ( 2 * V_92 ) > ( V_93 + V_76 ) ) {
V_44 -> V_78 = V_45 ;
return V_76 ;
}
}
V_44 -> V_78 = V_44 -> V_47 - 1 ;
return V_93 ;
} else {
V_44 -> V_78 = 0 ;
return V_44 -> V_48 [ 0 ] . V_94 * 1000 ;
}
}
static void F_51 ( void )
{
unsigned int V_45 ;
F_52 (i)
F_53 ( F_6 ( V_95 , V_45 )
-> V_96 ) ;
F_54 ( V_95 ) ;
}
static int F_55 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
unsigned V_1 = ( long ) V_100 ;
const struct V_14 * V_14 ;
V_14 = F_56 ( V_1 ) ;
switch ( V_99 ) {
case V_101 :
case V_102 :
F_3 ( V_26 , V_14 ) ;
break;
case V_103 :
case V_104 :
F_3 ( 1 , V_14 ) ;
break;
default:
break;
}
return V_105 ;
}
static int T_5 F_57 ( void )
{
unsigned int V_45 ;
F_12 ( L_11 ) ;
V_95 = F_58 ( struct V_43 ) ;
if ( ! V_95 ) {
F_12 ( L_12 ) ;
return - V_106 ;
}
F_52 (i) {
if ( ! F_59 (
& F_6 ( V_95 , V_45 ) -> V_96 ,
V_107 , F_60 ( V_45 ) ) ) {
F_51 () ;
return - V_106 ;
}
}
F_61 ( V_95 ) ;
return 0 ;
}
static int F_62 ( const struct V_108 * V_109 )
{
V_110 = 1 ;
return 0 ;
}
static int F_63 ( struct V_39 * V_111 )
{
if ( V_111 -> V_6 == V_7 ) {
if ( ( V_111 -> V_112 == 15 ) &&
( V_111 -> V_113 == 6 ) &&
( V_111 -> V_114 == 8 ) ) {
F_64 ( V_115 L_13
L_14
L_15
L_16 ) ;
return - V_84 ;
}
}
return 0 ;
}
static int F_65 ( struct V_32 * V_33 )
{
unsigned int V_45 ;
unsigned int V_116 = 0 ;
unsigned int V_1 = V_33 -> V_1 ;
struct V_34 * V_35 ;
unsigned int V_83 = 0 ;
struct V_39 * V_111 = & F_21 ( V_33 -> V_1 ) ;
struct V_43 * V_44 ;
#ifdef F_66
static int V_117 ;
#endif
F_12 ( L_17 ) ;
#ifdef F_66
if ( V_117 )
return V_117 ;
V_117 = F_63 ( V_111 ) ;
if ( V_117 )
return V_117 ;
#endif
V_35 = F_67 ( sizeof( * V_35 ) , V_107 ) ;
if ( ! V_35 )
return - V_106 ;
if ( ! F_68 ( & V_35 -> V_37 , V_107 ) ) {
V_83 = - V_106 ;
goto V_118;
}
V_35 -> V_46 = F_6 ( V_95 , V_1 ) ;
F_16 ( V_36 , V_1 ) = V_35 ;
if ( F_22 ( V_111 , V_119 ) )
V_120 . V_121 |= V_122 ;
V_83 = F_69 ( V_35 -> V_46 , V_1 ) ;
if ( V_83 )
goto V_123;
V_44 = V_35 -> V_46 ;
V_33 -> V_87 = V_44 -> V_87 ;
if ( V_33 -> V_87 == V_124 ||
V_33 -> V_87 == V_88 ) {
F_70 ( V_33 -> V_89 , V_44 -> V_96 ) ;
}
F_70 ( V_35 -> V_37 , V_44 -> V_96 ) ;
#ifdef F_66
F_71 ( V_125 ) ;
if ( V_110 && ! F_72 ( V_33 ) ) {
V_33 -> V_87 = V_124 ;
F_70 ( V_33 -> V_89 , F_73 ( V_1 ) ) ;
}
if ( F_23 ( V_1 ) && ! V_90 ) {
F_74 ( V_33 -> V_89 ) ;
F_75 ( V_1 , V_33 -> V_89 ) ;
F_70 ( V_35 -> V_37 , F_76 ( V_1 ) ) ;
V_33 -> V_87 = V_126 ;
F_77 ( V_127 L_18 ) ;
}
#endif
if ( V_44 -> V_47 <= 1 ) {
F_12 ( L_19 ) ;
V_83 = - V_84 ;
goto V_128;
}
if ( V_44 -> V_74 . V_129 != V_44 -> V_130 . V_129 ) {
V_83 = - V_84 ;
goto V_128;
}
switch ( V_44 -> V_74 . V_129 ) {
case V_131 :
if ( V_5 . V_6 == V_10 &&
V_5 . V_112 == 0xf ) {
F_12 ( L_20 ) ;
V_83 = - V_84 ;
goto V_128;
}
F_12 ( L_21 ) ;
V_35 -> V_56 = V_59 ;
break;
case V_132 :
F_12 ( L_22 ) ;
if ( F_20 ( V_1 ) ) {
V_35 -> V_56 = V_57 ;
break;
}
if ( F_23 ( V_1 ) ) {
V_35 -> V_56 = V_58 ;
break;
}
V_83 = - V_84 ;
goto V_128;
default:
F_12 ( L_23 ,
( T_1 ) ( V_44 -> V_74 . V_129 ) ) ;
V_83 = - V_84 ;
goto V_128;
}
V_35 -> V_50 = F_78 ( sizeof( * V_35 -> V_50 ) *
( V_44 -> V_47 + 1 ) , V_107 ) ;
if ( ! V_35 -> V_50 ) {
V_83 = - V_106 ;
goto V_128;
}
V_33 -> V_133 . V_134 = 0 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
if ( ( V_44 -> V_48 [ V_45 ] . V_134 * 1000 ) >
V_33 -> V_133 . V_134 )
V_33 -> V_133 . V_134 =
V_44 -> V_48 [ V_45 ] . V_134 * 1000 ;
}
if ( V_44 -> V_74 . V_129 == V_132 &&
V_33 -> V_133 . V_134 > 20 * 1000 ) {
V_33 -> V_133 . V_134 = 20 * 1000 ;
F_79 ( V_115
L_24 ) ;
}
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ ) {
if ( V_45 > 0 && V_44 -> V_48 [ V_45 ] . V_94 >=
V_35 -> V_50 [ V_116 - 1 ] . V_51 / 1000 )
continue;
V_35 -> V_50 [ V_116 ] . V_55 = V_45 ;
V_35 -> V_50 [ V_116 ] . V_51 =
V_44 -> V_48 [ V_45 ] . V_94 * 1000 ;
V_116 ++ ;
}
V_35 -> V_50 [ V_116 ] . V_51 = V_54 ;
V_44 -> V_78 = 0 ;
V_83 = F_80 ( V_33 , V_35 -> V_50 ) ;
if ( V_83 )
goto V_135;
if ( V_44 -> V_48 [ 0 ] . V_94 * 1000 != V_33 -> V_133 . V_136 )
F_64 (KERN_WARNING FW_WARN L_25 ) ;
switch ( V_44 -> V_74 . V_129 ) {
case V_131 :
V_33 -> V_137 = F_50 ( V_35 , V_33 -> V_1 ) ;
break;
case V_132 :
V_120 . V_138 = F_45 ;
break;
default:
break;
}
F_81 ( V_139 ) ;
F_12 ( L_26 , V_1 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_47 ; V_45 ++ )
F_12 ( L_27 ,
( V_45 == V_44 -> V_78 ? '*' : ' ' ) , V_45 ,
( T_1 ) V_44 -> V_48 [ V_45 ] . V_94 ,
( T_1 ) V_44 -> V_48 [ V_45 ] . V_140 ,
( T_1 ) V_44 -> V_48 [ V_45 ] . V_134 ) ;
V_35 -> V_79 = 1 ;
return V_83 ;
V_135:
F_82 ( V_35 -> V_50 ) ;
V_128:
F_83 ( V_44 , V_1 ) ;
V_123:
F_53 ( V_35 -> V_37 ) ;
V_118:
F_82 ( V_35 ) ;
F_16 ( V_36 , V_1 ) = NULL ;
return V_83 ;
}
static int F_84 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_16 ( V_36 , V_33 -> V_1 ) ;
F_12 ( L_28 ) ;
if ( V_35 ) {
F_85 ( V_33 -> V_1 ) ;
F_16 ( V_36 , V_33 -> V_1 ) = NULL ;
F_83 ( V_35 -> V_46 ,
V_33 -> V_1 ) ;
F_53 ( V_35 -> V_37 ) ;
F_82 ( V_35 -> V_50 ) ;
F_82 ( V_35 ) ;
}
return 0 ;
}
static int F_86 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_16 ( V_36 , V_33 -> V_1 ) ;
F_12 ( L_29 ) ;
V_35 -> V_79 = 1 ;
return 0 ;
}
static void T_5 F_87 ( void )
{
if ( F_88 ( V_141 ) || F_88 ( V_142 ) ) {
V_17 = F_89 () ;
if ( ! V_17 )
return;
V_24 = true ;
V_26 = F_1 ( 0 ) ;
F_10 () ;
F_3 ( V_26 , V_27 ) ;
F_90 ( & V_143 ) ;
F_11 () ;
} else
V_144 . V_31 . V_145 = 0444 ;
if ( F_91 ( & ( V_144 . V_31 ) ) )
F_92 ( V_127 L_30 ) ;
else
F_12 ( L_31 ) ;
}
static void T_6 F_93 ( void )
{
F_94 ( & ( V_144 . V_31 ) ) ;
if ( V_17 ) {
F_95 ( & V_143 ) ;
F_96 ( V_17 ) ;
V_17 = NULL ;
}
}
static int T_5 F_97 ( void )
{
int V_22 ;
if ( V_146 )
return - V_84 ;
if ( F_98 () )
return - V_147 ;
F_12 ( L_32 ) ;
V_22 = F_57 () ;
if ( V_22 )
return V_22 ;
#ifdef F_99
if ( F_23 ( 0 ) ) {
struct V_148 * * V_149 ;
F_12 ( L_33 ) ;
for ( V_149 = V_150 ; * V_149 != NULL ; V_149 ++ )
;
if ( V_149 [ 1 ] == NULL )
* V_149 = & V_151 ;
}
#endif
V_22 = F_100 ( & V_120 ) ;
if ( V_22 )
F_51 () ;
else
F_87 () ;
return V_22 ;
}
static void T_6 F_101 ( void )
{
F_12 ( L_34 ) ;
F_93 () ;
F_102 ( & V_120 ) ;
F_51 () ;
}
