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
static T_3 F_16 ( const char * V_29 , T_4 V_33 )
{
int V_34 ;
unsigned long V_25 = 0 ;
if ( ! V_35 . V_36 )
return - V_37 ;
V_34 = F_17 ( V_29 , 10 , & V_25 ) ;
if ( V_34 || ( V_25 > 1 ) )
return - V_37 ;
F_9 ( ( int ) V_25 ) ;
return V_33 ;
}
static T_3 F_18 ( struct V_27 * V_28 , const char * V_29 ,
T_4 V_33 )
{
return F_16 ( V_29 , V_33 ) ;
}
static T_3 F_19 ( struct V_27 * V_28 , char * V_29 )
{
return sprintf ( V_29 , L_4 , V_35 . V_38 ) ;
}
static int F_20 ( unsigned int V_39 )
{
struct V_40 * V_6 = & F_21 ( V_39 ) ;
return F_22 ( V_6 , V_41 ) ;
}
static int F_23 ( unsigned int V_39 )
{
struct V_40 * V_6 = & F_21 ( V_39 ) ;
return F_22 ( V_6 , V_42 ) ;
}
static unsigned F_24 ( T_1 V_43 , struct V_2 * V_3 )
{
struct V_1 * V_44 ;
int V_45 ;
V_44 = F_1 ( V_3 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_46 ; V_45 ++ ) {
if ( V_43 == V_44 -> V_47 [ V_45 ] . V_48 )
return V_3 -> V_49 [ V_45 ] . V_50 ;
}
return 0 ;
}
static unsigned F_25 ( T_1 V_9 , struct V_2 * V_3 )
{
struct V_51 * V_52 ;
struct V_1 * V_44 ;
if ( V_10 . V_11 == V_15 )
V_9 &= V_53 ;
else
V_9 &= V_54 ;
V_44 = F_1 ( V_3 ) ;
F_26 (pos, data->freq_table)
if ( V_9 == V_44 -> V_47 [ V_52 -> V_30 ] . V_48 )
return V_52 -> V_50 ;
return V_3 -> V_49 [ 0 ] . V_50 ;
}
static unsigned F_27 ( T_1 V_25 , struct V_2 * V_3 )
{
switch ( V_3 -> V_55 ) {
case V_56 :
case V_57 :
return F_25 ( V_25 , V_3 ) ;
case V_58 :
return F_24 ( V_25 , V_3 ) ;
default:
return 0 ;
}
}
static void F_28 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
T_1 V_62 ;
switch ( V_61 -> type ) {
case V_56 :
case V_57 :
F_29 ( V_61 -> V_63 . V_9 . V_23 , V_61 -> V_25 , V_62 ) ;
break;
case V_58 :
F_30 ( ( V_64 ) V_61 -> V_63 . V_65 . V_66 ,
& V_61 -> V_25 ,
( T_1 ) V_61 -> V_63 . V_65 . V_67 ) ;
break;
default:
break;
}
}
static void F_31 ( void * V_59 )
{
struct V_60 * V_61 = V_59 ;
T_1 V_7 , V_8 ;
switch ( V_61 -> type ) {
case V_56 :
F_29 ( V_61 -> V_63 . V_9 . V_23 , V_7 , V_8 ) ;
V_7 = ( V_7 & ~ V_54 ) | ( V_61 -> V_25 & V_54 ) ;
F_32 ( V_61 -> V_63 . V_9 . V_23 , V_7 , V_8 ) ;
break;
case V_57 :
F_32 ( V_61 -> V_63 . V_9 . V_23 , V_61 -> V_25 , 0 ) ;
break;
case V_58 :
F_33 ( ( V_64 ) V_61 -> V_63 . V_65 . V_66 ,
V_61 -> V_25 ,
( T_1 ) V_61 -> V_63 . V_65 . V_67 ) ;
break;
default:
break;
}
}
static void F_34 ( struct V_60 * V_61 )
{
int V_68 ;
V_61 -> V_25 = 0 ;
V_68 = F_35 ( V_61 -> V_69 , F_28 , V_61 , 1 ) ;
F_36 ( V_68 ) ;
}
static void F_37 ( struct V_60 * V_61 )
{
int V_70 ;
V_70 = F_38 () ;
if ( F_39 ( V_70 , V_61 -> V_69 ) )
F_31 ( V_61 ) ;
F_40 ( V_61 -> V_69 , F_31 , V_61 , 1 ) ;
F_41 () ;
}
static T_1
F_42 ( const struct V_19 * V_69 , struct V_2 * V_3 )
{
struct V_1 * V_44 ;
struct V_60 V_61 ;
if ( F_14 ( F_43 ( V_69 ) ) )
return 0 ;
switch ( V_3 -> V_55 ) {
case V_56 :
V_61 . type = V_56 ;
V_61 . V_63 . V_9 . V_23 = V_71 ;
break;
case V_57 :
V_61 . type = V_57 ;
V_61 . V_63 . V_9 . V_23 = V_72 ;
break;
case V_58 :
V_61 . type = V_58 ;
V_44 = F_1 ( V_3 ) ;
V_61 . V_63 . V_65 . V_66 = V_44 -> V_73 . V_74 ;
V_61 . V_63 . V_65 . V_67 = V_44 -> V_73 . V_67 ;
break;
default:
return 0 ;
}
V_61 . V_69 = V_69 ;
F_34 ( & V_61 ) ;
F_12 ( L_5 , V_61 . V_25 ) ;
return V_61 . V_25 ;
}
static unsigned int F_44 ( unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_27 * V_28 ;
unsigned int V_75 ;
unsigned int V_76 ;
F_12 ( L_6 , V_6 ) ;
V_28 = F_45 ( V_6 ) ;
if ( F_14 ( ! V_28 ) )
return 0 ;
V_3 = V_28 -> V_30 ;
if ( F_14 ( ! V_3 || ! V_3 -> V_49 ) )
return 0 ;
V_76 = V_3 -> V_49 [ F_1 ( V_3 ) -> V_77 ] . V_50 ;
V_75 = F_27 ( F_42 ( F_46 ( V_6 ) , V_3 ) , V_3 ) ;
if ( V_75 != V_76 ) {
V_3 -> V_78 = 1 ;
}
F_12 ( L_7 , V_75 ) ;
return V_75 ;
}
static unsigned int F_47 ( const struct V_19 * V_69 , unsigned int V_75 ,
struct V_2 * V_3 )
{
unsigned int V_79 ;
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < 100 ; V_45 ++ ) {
V_79 = F_27 ( F_42 ( V_69 , V_3 ) , V_3 ) ;
if ( V_79 == V_75 )
return 1 ;
F_48 ( 10 ) ;
}
return 0 ;
}
static int F_49 ( struct V_27 * V_28 ,
unsigned int V_80 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
struct V_1 * V_44 ;
struct V_60 V_61 ;
unsigned int V_81 = 0 ;
int V_82 = 0 ;
if ( F_14 ( V_3 == NULL || V_3 -> V_49 == NULL ) ) {
return - V_31 ;
}
V_44 = F_1 ( V_3 ) ;
V_81 = V_3 -> V_49 [ V_80 ] . V_30 ;
if ( V_44 -> V_77 == V_81 ) {
if ( F_14 ( V_3 -> V_78 ) ) {
F_12 ( L_8 ,
V_81 ) ;
V_3 -> V_78 = 0 ;
} else {
F_12 ( L_9 ,
V_81 ) ;
goto V_83;
}
}
switch ( V_3 -> V_55 ) {
case V_56 :
V_61 . type = V_56 ;
V_61 . V_63 . V_9 . V_23 = V_71 ;
V_61 . V_25 = ( T_1 ) V_44 -> V_47 [ V_81 ] . V_84 ;
break;
case V_57 :
V_61 . type = V_57 ;
V_61 . V_63 . V_9 . V_23 = V_72 ;
V_61 . V_25 = ( T_1 ) V_44 -> V_47 [ V_81 ] . V_84 ;
break;
case V_58 :
V_61 . type = V_58 ;
V_61 . V_63 . V_65 . V_66 = V_44 -> V_73 . V_74 ;
V_61 . V_63 . V_65 . V_67 = V_44 -> V_73 . V_67 ;
V_61 . V_25 = ( T_1 ) V_44 -> V_47 [ V_81 ] . V_84 ;
break;
default:
V_82 = - V_31 ;
goto V_83;
}
if ( V_28 -> V_85 != V_86 )
V_61 . V_69 = V_28 -> V_87 ;
else
V_61 . V_69 = F_46 ( V_28 -> V_6 ) ;
F_37 ( & V_61 ) ;
if ( V_88 ) {
if ( ! F_47 ( V_61 . V_69 , V_3 -> V_49 [ V_80 ] . V_50 ,
V_3 ) ) {
F_12 ( L_10 ,
V_28 -> V_6 ) ;
V_82 = - V_89 ;
}
}
if ( ! V_82 )
V_44 -> V_77 = V_81 ;
V_83:
return V_82 ;
}
static unsigned long
F_50 ( struct V_2 * V_3 , unsigned int V_6 )
{
struct V_1 * V_44 ;
V_44 = F_1 ( V_3 ) ;
if ( V_90 ) {
unsigned int V_45 ;
unsigned long V_75 ;
unsigned long V_91 = V_44 -> V_47 [ 0 ] . V_92 * 1000 ;
for ( V_45 = 0 ; V_45 < ( V_44 -> V_46 - 1 ) ; V_45 ++ ) {
V_75 = V_91 ;
V_91 = V_44 -> V_47 [ V_45 + 1 ] . V_92 * 1000 ;
if ( ( 2 * V_90 ) > ( V_91 + V_75 ) ) {
V_44 -> V_77 = V_45 ;
return V_75 ;
}
}
V_44 -> V_77 = V_44 -> V_46 - 1 ;
return V_91 ;
} else {
V_44 -> V_77 = 0 ;
return V_44 -> V_47 [ 0 ] . V_92 * 1000 ;
}
}
static void F_51 ( void )
{
unsigned int V_45 ;
F_52 (i)
F_53 ( F_2 ( V_4 , V_45 )
-> V_93 ) ;
F_54 ( V_4 ) ;
}
static int F_55 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
unsigned V_6 = ( long ) V_97 ;
const struct V_19 * V_19 ;
V_19 = F_56 ( V_6 ) ;
switch ( V_96 ) {
case V_98 :
case V_99 :
F_5 ( V_35 . V_38 , V_19 ) ;
break;
case V_100 :
case V_101 :
F_5 ( 1 , V_19 ) ;
break;
default:
break;
}
return V_102 ;
}
static int T_5 F_57 ( void )
{
unsigned int V_45 ;
F_12 ( L_11 ) ;
V_4 = F_58 ( struct V_1 ) ;
if ( ! V_4 ) {
F_12 ( L_12 ) ;
return - V_103 ;
}
F_52 (i) {
if ( ! F_59 (
& F_2 ( V_4 , V_45 ) -> V_93 ,
V_104 , F_60 ( V_45 ) ) ) {
F_51 () ;
return - V_103 ;
}
}
F_61 ( V_4 ) ;
return 0 ;
}
static int F_62 ( const struct V_105 * V_106 )
{
V_107 = 1 ;
return 0 ;
}
static int F_63 ( struct V_40 * V_108 )
{
if ( V_108 -> V_11 == V_12 ) {
if ( ( V_108 -> V_109 == 15 ) &&
( V_108 -> V_110 == 6 ) &&
( V_108 -> V_111 == 8 ) ) {
F_64 ( V_112 L_13
L_14
L_15
L_16 ) ;
return - V_31 ;
}
}
return 0 ;
}
static int F_65 ( struct V_27 * V_28 )
{
unsigned int V_45 ;
unsigned int V_113 = 0 ;
unsigned int V_6 = V_28 -> V_6 ;
struct V_2 * V_3 ;
unsigned int V_82 = 0 ;
struct V_40 * V_108 = & F_21 ( V_28 -> V_6 ) ;
struct V_1 * V_44 ;
#ifdef F_66
static int V_114 ;
#endif
F_12 ( L_17 ) ;
#ifdef F_66
if ( V_114 )
return V_114 ;
V_114 = F_63 ( V_108 ) ;
if ( V_114 )
return V_114 ;
#endif
V_3 = F_67 ( sizeof( * V_3 ) , V_104 ) ;
if ( ! V_3 )
return - V_103 ;
if ( ! F_68 ( & V_3 -> V_32 , V_104 ) ) {
V_82 = - V_103 ;
goto V_115;
}
V_44 = F_2 ( V_4 , V_6 ) ;
V_3 -> V_5 = V_6 ;
V_28 -> V_30 = V_3 ;
if ( F_22 ( V_108 , V_116 ) )
V_35 . V_117 |= V_118 ;
V_82 = F_69 ( V_44 , V_6 ) ;
if ( V_82 )
goto V_119;
V_28 -> V_85 = V_44 -> V_85 ;
if ( V_28 -> V_85 == V_120 ||
V_28 -> V_85 == V_86 ) {
F_70 ( V_28 -> V_87 , V_44 -> V_93 ) ;
}
F_70 ( V_3 -> V_32 , V_44 -> V_93 ) ;
#ifdef F_66
F_71 ( V_121 ) ;
if ( V_107 && ! F_72 ( V_28 ) ) {
V_28 -> V_85 = V_120 ;
F_70 ( V_28 -> V_87 , F_73 ( V_6 ) ) ;
}
if ( F_23 ( V_6 ) && ! V_88 ) {
F_74 ( V_28 -> V_87 ) ;
F_75 ( V_6 , V_28 -> V_87 ) ;
F_70 ( V_3 -> V_32 ,
F_76 ( V_6 ) ) ;
V_28 -> V_85 = V_122 ;
F_77 ( V_123 L_18 ) ;
}
#endif
if ( V_44 -> V_46 <= 1 ) {
F_12 ( L_19 ) ;
V_82 = - V_31 ;
goto V_124;
}
if ( V_44 -> V_73 . V_125 != V_44 -> V_126 . V_125 ) {
V_82 = - V_31 ;
goto V_124;
}
switch ( V_44 -> V_73 . V_125 ) {
case V_127 :
if ( V_10 . V_11 == V_15 &&
V_10 . V_109 == 0xf ) {
F_12 ( L_20 ) ;
V_82 = - V_31 ;
goto V_124;
}
F_12 ( L_21 ) ;
V_3 -> V_55 = V_58 ;
break;
case V_128 :
F_12 ( L_22 ) ;
if ( F_20 ( V_6 ) ) {
V_3 -> V_55 = V_56 ;
break;
}
if ( F_23 ( V_6 ) ) {
V_3 -> V_55 = V_57 ;
break;
}
V_82 = - V_31 ;
goto V_124;
default:
F_12 ( L_23 ,
( T_1 ) ( V_44 -> V_73 . V_125 ) ) ;
V_82 = - V_31 ;
goto V_124;
}
V_3 -> V_49 = F_67 ( sizeof( * V_3 -> V_49 ) *
( V_44 -> V_46 + 1 ) , V_104 ) ;
if ( ! V_3 -> V_49 ) {
V_82 = - V_103 ;
goto V_124;
}
V_28 -> V_129 . V_130 = 0 ;
for ( V_45 = 0 ; V_45 < V_44 -> V_46 ; V_45 ++ ) {
if ( ( V_44 -> V_47 [ V_45 ] . V_130 * 1000 ) >
V_28 -> V_129 . V_130 )
V_28 -> V_129 . V_130 =
V_44 -> V_47 [ V_45 ] . V_130 * 1000 ;
}
if ( V_44 -> V_73 . V_125 == V_128 &&
V_28 -> V_129 . V_130 > 20 * 1000 ) {
V_28 -> V_129 . V_130 = 20 * 1000 ;
F_78 ( V_112
L_24 ) ;
}
for ( V_45 = 0 ; V_45 < V_44 -> V_46 ; V_45 ++ ) {
if ( V_45 > 0 && V_44 -> V_47 [ V_45 ] . V_92 >=
V_3 -> V_49 [ V_113 - 1 ] . V_50 / 1000 )
continue;
V_3 -> V_49 [ V_113 ] . V_30 = V_45 ;
V_3 -> V_49 [ V_113 ] . V_50 =
V_44 -> V_47 [ V_45 ] . V_92 * 1000 ;
V_113 ++ ;
}
V_3 -> V_49 [ V_113 ] . V_50 = V_131 ;
V_44 -> V_77 = 0 ;
V_82 = F_79 ( V_28 , V_3 -> V_49 ) ;
if ( V_82 )
goto V_132;
if ( V_44 -> V_47 [ 0 ] . V_92 * 1000 != V_28 -> V_129 . V_133 )
F_64 (KERN_WARNING FW_WARN L_25 ) ;
switch ( V_44 -> V_73 . V_125 ) {
case V_127 :
V_28 -> V_134 = F_50 ( V_3 , V_28 -> V_6 ) ;
break;
case V_128 :
V_35 . V_135 = F_44 ;
break;
default:
break;
}
F_80 ( V_136 ) ;
F_12 ( L_26 , V_6 ) ;
for ( V_45 = 0 ; V_45 < V_44 -> V_46 ; V_45 ++ )
F_12 ( L_27 ,
( V_45 == V_44 -> V_77 ? '*' : ' ' ) , V_45 ,
( T_1 ) V_44 -> V_47 [ V_45 ] . V_92 ,
( T_1 ) V_44 -> V_47 [ V_45 ] . V_137 ,
( T_1 ) V_44 -> V_47 [ V_45 ] . V_130 ) ;
V_3 -> V_78 = 1 ;
return V_82 ;
V_132:
F_81 ( V_3 -> V_49 ) ;
V_124:
F_82 ( V_6 ) ;
V_119:
F_53 ( V_3 -> V_32 ) ;
V_115:
F_81 ( V_3 ) ;
V_28 -> V_30 = NULL ;
return V_82 ;
}
static int F_83 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
F_12 ( L_28 ) ;
if ( V_3 ) {
V_28 -> V_30 = NULL ;
F_82 ( V_3 -> V_5 ) ;
F_53 ( V_3 -> V_32 ) ;
F_81 ( V_3 -> V_49 ) ;
F_81 ( V_3 ) ;
}
return 0 ;
}
static int F_84 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
F_12 ( L_29 ) ;
V_3 -> V_78 = 1 ;
return 0 ;
}
static void T_5 F_85 ( void )
{
if ( F_86 ( V_138 ) || F_86 ( V_139 ) ) {
V_22 = F_87 () ;
if ( ! V_22 )
return;
V_35 . V_36 = true ;
V_35 . V_38 = F_3 ( 0 ) ;
F_88 () ;
F_5 ( V_35 . V_38 ,
V_26 ) ;
F_89 ( & V_140 ) ;
F_90 () ;
}
}
static void F_91 ( void )
{
if ( V_22 ) {
F_92 ( & V_140 ) ;
F_93 ( V_22 ) ;
V_22 = NULL ;
}
}
static int T_5 F_94 ( void )
{
int V_34 ;
if ( V_141 )
return - V_31 ;
if ( F_95 () )
return - V_142 ;
F_12 ( L_30 ) ;
V_34 = F_57 () ;
if ( V_34 )
return V_34 ;
#ifdef F_96
if ( ! F_23 ( 0 ) ) {
struct V_143 * * V_144 ;
F_12 ( L_31 ) ;
for ( V_144 = V_145 ; * V_144 ; V_144 ++ )
if ( * V_144 == & V_146 ) {
* V_144 = NULL ;
break;
}
}
#endif
F_85 () ;
V_34 = F_97 ( & V_35 ) ;
if ( V_34 ) {
F_51 () ;
F_91 () ;
}
return V_34 ;
}
static void T_6 F_98 ( void )
{
F_12 ( L_32 ) ;
F_91 () ;
F_99 ( & V_35 ) ;
F_51 () ;
}
