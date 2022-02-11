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
static T_3 F_15 ( struct V_32 * V_33 , const char * V_20 ,
T_4 V_21 )
{
return F_8 ( V_20 , V_21 ) ;
}
static T_3 F_16 ( struct V_32 * V_33 , char * V_20 )
{
return sprintf ( V_20 , L_4 , V_26 ) ;
}
static int F_17 ( unsigned int V_34 )
{
struct V_35 * V_1 = & F_18 ( V_34 ) ;
return F_19 ( V_1 , V_36 ) ;
}
static int F_20 ( unsigned int V_34 )
{
struct V_35 * V_1 = & F_18 ( V_34 ) ;
return F_19 ( V_1 , V_37 ) ;
}
static unsigned F_21 ( T_1 V_38 , struct V_39 * V_40 )
{
struct V_41 * V_42 ;
int V_43 ;
V_42 = V_40 -> V_44 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
if ( V_38 == V_42 -> V_46 [ V_43 ] . V_47 )
return V_40 -> V_48 [ V_43 ] . V_49 ;
}
return 0 ;
}
static unsigned F_22 ( T_1 V_4 , struct V_39 * V_40 )
{
int V_43 ;
struct V_41 * V_42 ;
if ( V_5 . V_6 == V_10 )
V_4 &= V_50 ;
else
V_4 &= V_51 ;
V_42 = V_40 -> V_44 ;
for ( V_43 = 0 ; V_40 -> V_48 [ V_43 ] . V_49 != V_52 ; V_43 ++ ) {
if ( V_4 == V_42 -> V_46 [ V_40 -> V_48 [ V_43 ] . V_53 ] . V_47 )
return V_40 -> V_48 [ V_43 ] . V_49 ;
}
return V_40 -> V_48 [ 0 ] . V_49 ;
}
static unsigned F_23 ( T_1 V_23 , struct V_39 * V_40 )
{
switch ( V_40 -> V_54 ) {
case V_55 :
case V_56 :
return F_22 ( V_23 , V_40 ) ;
case V_57 :
return F_21 ( V_23 , V_40 ) ;
default:
return 0 ;
}
}
static void F_24 ( void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_1 V_61 ;
switch ( V_60 -> type ) {
case V_55 :
case V_56 :
F_25 ( V_60 -> V_62 . V_4 . V_18 , V_60 -> V_23 , V_61 ) ;
break;
case V_57 :
F_26 ( ( V_63 ) V_60 -> V_62 . V_64 . V_65 ,
& V_60 -> V_23 ,
( T_1 ) V_60 -> V_62 . V_64 . V_66 ) ;
break;
default:
break;
}
}
static void F_27 ( void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_1 V_2 , V_3 ;
switch ( V_60 -> type ) {
case V_55 :
F_25 ( V_60 -> V_62 . V_4 . V_18 , V_2 , V_3 ) ;
V_2 = ( V_2 & ~ V_51 ) | ( V_60 -> V_23 & V_51 ) ;
F_28 ( V_60 -> V_62 . V_4 . V_18 , V_2 , V_3 ) ;
break;
case V_56 :
F_28 ( V_60 -> V_62 . V_4 . V_18 , V_60 -> V_23 , 0 ) ;
break;
case V_57 :
F_29 ( ( V_63 ) V_60 -> V_62 . V_64 . V_65 ,
V_60 -> V_23 ,
( T_1 ) V_60 -> V_62 . V_64 . V_66 ) ;
break;
default:
break;
}
}
static void F_30 ( struct V_59 * V_60 )
{
int V_67 ;
V_60 -> V_23 = 0 ;
V_67 = F_31 ( V_60 -> V_68 , F_24 , V_60 , 1 ) ;
F_32 ( V_67 ) ;
}
static void F_33 ( struct V_59 * V_60 )
{
int V_69 ;
V_69 = F_34 () ;
if ( F_35 ( V_69 , V_60 -> V_68 ) )
F_27 ( V_60 ) ;
F_36 ( V_60 -> V_68 , F_27 , V_60 , 1 ) ;
F_37 () ;
}
static T_1 F_38 ( const struct V_14 * V_68 )
{
struct V_41 * V_42 ;
struct V_59 V_60 ;
if ( F_39 ( F_40 ( V_68 ) ) )
return 0 ;
switch ( F_41 ( V_70 , F_42 ( V_68 ) ) -> V_54 ) {
case V_55 :
V_60 . type = V_55 ;
V_60 . V_62 . V_4 . V_18 = V_71 ;
break;
case V_56 :
V_60 . type = V_56 ;
V_60 . V_62 . V_4 . V_18 = V_72 ;
break;
case V_57 :
V_60 . type = V_57 ;
V_42 = F_41 ( V_70 , F_42 ( V_68 ) ) -> V_44 ;
V_60 . V_62 . V_64 . V_65 = V_42 -> V_73 . V_74 ;
V_60 . V_62 . V_64 . V_66 = V_42 -> V_73 . V_66 ;
break;
default:
return 0 ;
}
V_60 . V_68 = V_68 ;
F_30 ( & V_60 ) ;
F_12 ( L_5 , V_60 . V_23 ) ;
return V_60 . V_23 ;
}
static unsigned int F_43 ( unsigned int V_1 )
{
struct V_39 * V_40 = F_41 ( V_70 , V_1 ) ;
unsigned int V_75 ;
unsigned int V_76 ;
F_12 ( L_6 , V_1 ) ;
if ( F_39 ( V_40 == NULL ||
V_40 -> V_44 == NULL || V_40 -> V_48 == NULL ) ) {
return 0 ;
}
V_76 = V_40 -> V_48 [ V_40 -> V_44 -> V_77 ] . V_49 ;
V_75 = F_23 ( F_38 ( F_44 ( V_1 ) ) , V_40 ) ;
if ( V_75 != V_76 ) {
V_40 -> V_78 = 1 ;
}
F_12 ( L_7 , V_75 ) ;
return V_75 ;
}
static unsigned int F_45 ( const struct V_14 * V_68 , unsigned int V_75 ,
struct V_39 * V_40 )
{
unsigned int V_79 ;
unsigned int V_43 ;
for ( V_43 = 0 ; V_43 < 100 ; V_43 ++ ) {
V_79 = F_23 ( F_38 ( V_68 ) , V_40 ) ;
if ( V_79 == V_75 )
return 1 ;
F_46 ( 10 ) ;
}
return 0 ;
}
static int F_47 ( struct V_32 * V_33 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_39 * V_40 = F_41 ( V_70 , V_33 -> V_1 ) ;
struct V_41 * V_42 ;
struct V_82 V_83 ;
struct V_59 V_60 ;
unsigned int V_84 = 0 ;
unsigned int V_85 = 0 ;
int V_86 = 0 ;
F_12 ( L_8 , V_80 , V_33 -> V_1 ) ;
if ( F_39 ( V_40 == NULL ||
V_40 -> V_44 == NULL || V_40 -> V_48 == NULL ) ) {
return - V_87 ;
}
V_42 = V_40 -> V_44 ;
V_86 = F_48 ( V_33 ,
V_40 -> V_48 ,
V_80 ,
V_81 , & V_84 ) ;
if ( F_39 ( V_86 ) ) {
V_86 = - V_87 ;
goto V_88;
}
V_85 = V_40 -> V_48 [ V_84 ] . V_53 ;
if ( V_42 -> V_77 == V_85 ) {
if ( F_39 ( V_40 -> V_78 ) ) {
F_12 ( L_9 ,
V_85 ) ;
V_40 -> V_78 = 0 ;
} else {
F_12 ( L_10 ,
V_85 ) ;
goto V_88;
}
}
switch ( V_40 -> V_54 ) {
case V_55 :
V_60 . type = V_55 ;
V_60 . V_62 . V_4 . V_18 = V_71 ;
V_60 . V_23 = ( T_1 ) V_42 -> V_46 [ V_85 ] . V_89 ;
break;
case V_56 :
V_60 . type = V_56 ;
V_60 . V_62 . V_4 . V_18 = V_72 ;
V_60 . V_23 = ( T_1 ) V_42 -> V_46 [ V_85 ] . V_89 ;
break;
case V_57 :
V_60 . type = V_57 ;
V_60 . V_62 . V_64 . V_65 = V_42 -> V_73 . V_74 ;
V_60 . V_62 . V_64 . V_66 = V_42 -> V_73 . V_66 ;
V_60 . V_23 = ( T_1 ) V_42 -> V_46 [ V_85 ] . V_89 ;
break;
default:
V_86 = - V_87 ;
goto V_88;
}
if ( V_33 -> V_90 != V_91 )
V_60 . V_68 = V_33 -> V_92 ;
else
V_60 . V_68 = F_44 ( V_33 -> V_1 ) ;
V_83 . V_93 = V_42 -> V_46 [ V_42 -> V_77 ] . V_94 * 1000 ;
V_83 . V_95 = V_40 -> V_48 [ V_84 ] . V_49 ;
F_49 ( V_33 , & V_83 , V_96 ) ;
F_33 ( & V_60 ) ;
if ( V_97 ) {
if ( ! F_45 ( V_60 . V_68 , V_83 . V_95 , V_40 ) ) {
F_12 ( L_11 ,
V_33 -> V_1 ) ;
V_86 = - V_98 ;
goto V_88;
}
}
F_49 ( V_33 , & V_83 , V_99 ) ;
V_42 -> V_77 = V_85 ;
V_88:
return V_86 ;
}
static int F_50 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = F_41 ( V_70 , V_33 -> V_1 ) ;
F_12 ( L_12 ) ;
return F_51 ( V_33 , V_40 -> V_48 ) ;
}
static unsigned long
F_52 ( struct V_39 * V_40 , unsigned int V_1 )
{
struct V_41 * V_42 = V_40 -> V_44 ;
if ( V_100 ) {
unsigned int V_43 ;
unsigned long V_75 ;
unsigned long V_101 = V_42 -> V_46 [ 0 ] . V_94 * 1000 ;
for ( V_43 = 0 ; V_43 < ( V_42 -> V_45 - 1 ) ; V_43 ++ ) {
V_75 = V_101 ;
V_101 = V_42 -> V_46 [ V_43 + 1 ] . V_94 * 1000 ;
if ( ( 2 * V_100 ) > ( V_101 + V_75 ) ) {
V_42 -> V_77 = V_43 ;
return V_75 ;
}
}
V_42 -> V_77 = V_42 -> V_45 - 1 ;
return V_101 ;
} else {
V_42 -> V_77 = 0 ;
return V_42 -> V_46 [ 0 ] . V_94 * 1000 ;
}
}
static void F_53 ( void )
{
unsigned int V_43 ;
F_54 (i)
F_55 ( F_6 ( V_102 , V_43 )
-> V_103 ) ;
F_56 ( V_102 ) ;
}
static int F_57 ( struct V_104 * V_105 , unsigned long V_106 ,
void * V_107 )
{
unsigned V_1 = ( long ) V_107 ;
const struct V_14 * V_14 ;
V_14 = F_58 ( V_1 ) ;
switch ( V_106 ) {
case V_108 :
case V_109 :
F_3 ( V_26 , V_14 ) ;
break;
case V_110 :
case V_111 :
F_3 ( 1 , V_14 ) ;
break;
default:
break;
}
return V_112 ;
}
static int T_5 F_59 ( void )
{
unsigned int V_43 ;
F_12 ( L_13 ) ;
V_102 = F_60 ( struct V_41 ) ;
if ( ! V_102 ) {
F_12 ( L_14 ) ;
return - V_113 ;
}
F_54 (i) {
if ( ! F_61 (
& F_6 ( V_102 , V_43 ) -> V_103 ,
V_114 , F_62 ( V_43 ) ) ) {
F_53 () ;
return - V_113 ;
}
}
F_63 ( V_102 ) ;
return 0 ;
}
static int F_64 ( const struct V_115 * V_116 )
{
V_117 = 1 ;
return 0 ;
}
static int F_65 ( struct V_35 * V_118 )
{
if ( V_118 -> V_6 == V_7 ) {
if ( ( V_118 -> V_119 == 15 ) &&
( V_118 -> V_120 == 6 ) &&
( V_118 -> V_121 == 8 ) ) {
F_66 ( V_122 L_15
L_16
L_17
L_18 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int F_67 ( struct V_32 * V_33 )
{
unsigned int V_43 ;
unsigned int V_123 = 0 ;
unsigned int V_1 = V_33 -> V_1 ;
struct V_39 * V_40 ;
unsigned int V_86 = 0 ;
struct V_35 * V_118 = & F_18 ( V_33 -> V_1 ) ;
struct V_41 * V_42 ;
#ifdef F_68
static int V_124 ;
#endif
F_12 ( L_19 ) ;
#ifdef F_68
if ( V_124 )
return V_124 ;
V_124 = F_65 ( V_118 ) ;
if ( V_124 )
return V_124 ;
#endif
V_40 = F_69 ( sizeof( struct V_39 ) , V_114 ) ;
if ( ! V_40 )
return - V_113 ;
V_40 -> V_44 = F_6 ( V_102 , V_1 ) ;
F_41 ( V_70 , V_1 ) = V_40 ;
if ( F_19 ( V_118 , V_125 ) )
V_126 . V_127 |= V_128 ;
V_86 = F_70 ( V_40 -> V_44 , V_1 ) ;
if ( V_86 )
goto V_129;
V_42 = V_40 -> V_44 ;
V_33 -> V_90 = V_42 -> V_90 ;
if ( V_33 -> V_90 == V_130 ||
V_33 -> V_90 == V_91 ) {
F_71 ( V_33 -> V_92 , V_42 -> V_103 ) ;
}
#ifdef F_68
F_72 ( V_131 ) ;
if ( V_117 && ! F_73 ( V_33 ) ) {
V_33 -> V_90 = V_130 ;
F_71 ( V_33 -> V_92 , F_74 ( V_1 ) ) ;
}
if ( F_20 ( V_1 ) && ! V_97 ) {
F_75 ( V_33 -> V_92 ) ;
F_76 ( V_1 , V_33 -> V_92 ) ;
V_33 -> V_90 = V_132 ;
F_77 ( V_133 L_20 ) ;
}
#endif
if ( V_42 -> V_45 <= 1 ) {
F_12 ( L_21 ) ;
V_86 = - V_87 ;
goto V_134;
}
if ( V_42 -> V_73 . V_135 != V_42 -> V_136 . V_135 ) {
V_86 = - V_87 ;
goto V_134;
}
switch ( V_42 -> V_73 . V_135 ) {
case V_137 :
if ( V_5 . V_6 == V_10 &&
V_5 . V_119 == 0xf ) {
F_12 ( L_22 ) ;
V_86 = - V_87 ;
goto V_134;
}
F_12 ( L_23 ) ;
V_40 -> V_54 = V_57 ;
break;
case V_138 :
F_12 ( L_24 ) ;
if ( F_17 ( V_1 ) ) {
V_40 -> V_54 = V_55 ;
break;
}
if ( F_20 ( V_1 ) ) {
V_40 -> V_54 = V_56 ;
break;
}
V_86 = - V_87 ;
goto V_134;
default:
F_12 ( L_25 ,
( T_1 ) ( V_42 -> V_73 . V_135 ) ) ;
V_86 = - V_87 ;
goto V_134;
}
V_40 -> V_48 = F_78 ( sizeof( struct V_139 ) *
( V_42 -> V_45 + 1 ) , V_114 ) ;
if ( ! V_40 -> V_48 ) {
V_86 = - V_113 ;
goto V_134;
}
V_33 -> V_140 . V_141 = 0 ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
if ( ( V_42 -> V_46 [ V_43 ] . V_141 * 1000 ) >
V_33 -> V_140 . V_141 )
V_33 -> V_140 . V_141 =
V_42 -> V_46 [ V_43 ] . V_141 * 1000 ;
}
if ( V_42 -> V_73 . V_135 == V_138 &&
V_33 -> V_140 . V_141 > 20 * 1000 ) {
V_33 -> V_140 . V_141 = 20 * 1000 ;
F_79 ( V_122
L_26 ) ;
}
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ ) {
if ( V_43 > 0 && V_42 -> V_46 [ V_43 ] . V_94 >=
V_40 -> V_48 [ V_123 - 1 ] . V_49 / 1000 )
continue;
V_40 -> V_48 [ V_123 ] . V_53 = V_43 ;
V_40 -> V_48 [ V_123 ] . V_49 =
V_42 -> V_46 [ V_43 ] . V_94 * 1000 ;
V_123 ++ ;
}
V_40 -> V_48 [ V_123 ] . V_49 = V_52 ;
V_42 -> V_77 = 0 ;
V_86 = F_80 ( V_33 , V_40 -> V_48 ) ;
if ( V_86 )
goto V_142;
if ( V_42 -> V_46 [ 0 ] . V_94 * 1000 != V_33 -> V_140 . V_143 )
F_66 (KERN_WARNING FW_WARN L_27 ) ;
switch ( V_42 -> V_73 . V_135 ) {
case V_137 :
V_33 -> V_144 = F_52 ( V_40 , V_33 -> V_1 ) ;
break;
case V_138 :
V_126 . V_145 = F_43 ;
V_33 -> V_144 = F_43 ( V_1 ) ;
break;
default:
break;
}
F_81 ( V_146 ) ;
if ( F_82 ( V_147 ) )
V_126 . V_148 = V_149 ;
F_12 ( L_28 , V_1 ) ;
for ( V_43 = 0 ; V_43 < V_42 -> V_45 ; V_43 ++ )
F_12 ( L_29 ,
( V_43 == V_42 -> V_77 ? '*' : ' ' ) , V_43 ,
( T_1 ) V_42 -> V_46 [ V_43 ] . V_94 ,
( T_1 ) V_42 -> V_46 [ V_43 ] . V_150 ,
( T_1 ) V_42 -> V_46 [ V_43 ] . V_141 ) ;
F_83 ( V_40 -> V_48 , V_33 -> V_1 ) ;
V_40 -> V_78 = 1 ;
return V_86 ;
V_142:
F_84 ( V_40 -> V_48 ) ;
V_134:
F_85 ( V_42 , V_1 ) ;
V_129:
F_84 ( V_40 ) ;
F_41 ( V_70 , V_1 ) = NULL ;
return V_86 ;
}
static int F_86 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = F_41 ( V_70 , V_33 -> V_1 ) ;
F_12 ( L_30 ) ;
if ( V_40 ) {
F_87 ( V_33 -> V_1 ) ;
F_41 ( V_70 , V_33 -> V_1 ) = NULL ;
F_85 ( V_40 -> V_44 ,
V_33 -> V_1 ) ;
F_84 ( V_40 -> V_48 ) ;
F_84 ( V_40 ) ;
}
return 0 ;
}
static int F_88 ( struct V_32 * V_33 )
{
struct V_39 * V_40 = F_41 ( V_70 , V_33 -> V_1 ) ;
F_12 ( L_31 ) ;
V_40 -> V_78 = 1 ;
return 0 ;
}
static void T_5 F_89 ( void )
{
if ( F_82 ( V_151 ) || F_82 ( V_152 ) ) {
V_17 = F_90 () ;
if ( ! V_17 )
return;
V_24 = true ;
V_26 = F_1 ( 0 ) ;
F_10 () ;
F_3 ( V_26 , V_27 ) ;
F_91 ( & V_153 ) ;
F_11 () ;
} else
V_154 . V_31 . V_155 = 0444 ;
if ( F_92 ( V_156 , & ( V_154 . V_31 ) ) )
F_93 ( V_133 L_32 ) ;
else
F_12 ( L_33 ) ;
}
static void T_6 F_94 ( void )
{
F_95 ( V_156 , & ( V_154 . V_31 ) ) ;
if ( V_17 ) {
F_96 ( & V_153 ) ;
F_97 ( V_17 ) ;
V_17 = NULL ;
}
}
static int T_5 F_98 ( void )
{
int V_22 ;
if ( V_157 )
return 0 ;
F_12 ( L_34 ) ;
V_22 = F_59 () ;
if ( V_22 )
return V_22 ;
#ifdef F_99
if ( F_20 ( 0 ) ) {
struct V_158 * * V_159 ;
F_12 ( L_35 ) ;
for ( V_159 = V_160 ; * V_159 != NULL ; V_159 ++ )
;
if ( V_159 [ 1 ] == NULL )
* V_159 = & V_161 ;
}
#endif
V_22 = F_100 ( & V_126 ) ;
if ( V_22 )
F_53 () ;
else
F_89 () ;
return V_22 ;
}
static void T_6 F_101 ( void )
{
F_12 ( L_36 ) ;
F_94 () ;
F_102 ( & V_126 ) ;
F_53 () ;
}
