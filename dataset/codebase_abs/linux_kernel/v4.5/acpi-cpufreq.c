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
static unsigned F_23 ( T_1 V_42 , struct V_2 * V_3 )
{
struct V_1 * V_43 ;
int V_44 ;
V_43 = F_1 ( V_3 ) ;
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ ) {
if ( V_42 == V_43 -> V_46 [ V_44 ] . V_47 )
return V_3 -> V_48 [ V_44 ] . V_49 ;
}
return 0 ;
}
static unsigned F_24 ( T_1 V_9 , struct V_2 * V_3 )
{
struct V_50 * V_51 ;
struct V_1 * V_43 ;
if ( V_10 . V_11 == V_15 )
V_9 &= V_52 ;
else
V_9 &= V_53 ;
V_43 = F_1 ( V_3 ) ;
F_25 (pos, data->freq_table)
if ( V_9 == V_43 -> V_46 [ V_51 -> V_30 ] . V_47 )
return V_51 -> V_49 ;
return V_3 -> V_48 [ 0 ] . V_49 ;
}
static unsigned F_26 ( T_1 V_25 , struct V_2 * V_3 )
{
switch ( V_3 -> V_54 ) {
case V_55 :
case V_56 :
return F_24 ( V_25 , V_3 ) ;
case V_57 :
return F_23 ( V_25 , V_3 ) ;
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
F_28 ( V_60 -> V_62 . V_9 . V_23 , V_60 -> V_25 , V_61 ) ;
break;
case V_57 :
F_29 ( ( V_63 ) V_60 -> V_62 . V_64 . V_65 ,
& V_60 -> V_25 ,
( T_1 ) V_60 -> V_62 . V_64 . V_66 ) ;
break;
default:
break;
}
}
static void F_30 ( void * V_58 )
{
struct V_59 * V_60 = V_58 ;
T_1 V_7 , V_8 ;
switch ( V_60 -> type ) {
case V_55 :
F_28 ( V_60 -> V_62 . V_9 . V_23 , V_7 , V_8 ) ;
V_7 = ( V_7 & ~ V_53 ) | ( V_60 -> V_25 & V_53 ) ;
F_31 ( V_60 -> V_62 . V_9 . V_23 , V_7 , V_8 ) ;
break;
case V_56 :
F_31 ( V_60 -> V_62 . V_9 . V_23 , V_60 -> V_25 , 0 ) ;
break;
case V_57 :
F_32 ( ( V_63 ) V_60 -> V_62 . V_64 . V_65 ,
V_60 -> V_25 ,
( T_1 ) V_60 -> V_62 . V_64 . V_66 ) ;
break;
default:
break;
}
}
static void F_33 ( struct V_59 * V_60 )
{
int V_67 ;
V_60 -> V_25 = 0 ;
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
static T_1
F_41 ( const struct V_19 * V_68 , struct V_2 * V_3 )
{
struct V_1 * V_43 ;
struct V_59 V_60 ;
if ( F_14 ( F_42 ( V_68 ) ) )
return 0 ;
switch ( V_3 -> V_54 ) {
case V_55 :
V_60 . type = V_55 ;
V_60 . V_62 . V_9 . V_23 = V_70 ;
break;
case V_56 :
V_60 . type = V_56 ;
V_60 . V_62 . V_9 . V_23 = V_71 ;
break;
case V_57 :
V_60 . type = V_57 ;
V_43 = F_1 ( V_3 ) ;
V_60 . V_62 . V_64 . V_65 = V_43 -> V_72 . V_73 ;
V_60 . V_62 . V_64 . V_66 = V_43 -> V_72 . V_66 ;
break;
default:
return 0 ;
}
V_60 . V_68 = V_68 ;
F_33 ( & V_60 ) ;
F_12 ( L_5 , V_60 . V_25 ) ;
return V_60 . V_25 ;
}
static unsigned int F_43 ( unsigned int V_6 )
{
struct V_2 * V_3 ;
struct V_27 * V_28 ;
unsigned int V_74 ;
unsigned int V_75 ;
F_12 ( L_6 , V_6 ) ;
V_28 = F_44 ( V_6 ) ;
if ( F_14 ( ! V_28 ) )
return 0 ;
V_3 = V_28 -> V_30 ;
if ( F_14 ( ! V_3 || ! V_3 -> V_48 ) )
return 0 ;
V_75 = V_3 -> V_48 [ F_1 ( V_3 ) -> V_76 ] . V_49 ;
V_74 = F_26 ( F_41 ( F_45 ( V_6 ) , V_3 ) , V_3 ) ;
if ( V_74 != V_75 ) {
V_3 -> V_77 = 1 ;
}
F_12 ( L_7 , V_74 ) ;
return V_74 ;
}
static unsigned int F_46 ( const struct V_19 * V_68 , unsigned int V_74 ,
struct V_2 * V_3 )
{
unsigned int V_78 ;
unsigned int V_44 ;
for ( V_44 = 0 ; V_44 < 100 ; V_44 ++ ) {
V_78 = F_26 ( F_41 ( V_68 , V_3 ) , V_3 ) ;
if ( V_78 == V_74 )
return 1 ;
F_47 ( 10 ) ;
}
return 0 ;
}
static int F_48 ( struct V_27 * V_28 ,
unsigned int V_79 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
struct V_1 * V_43 ;
struct V_59 V_60 ;
unsigned int V_80 = 0 ;
int V_81 = 0 ;
if ( F_14 ( V_3 == NULL || V_3 -> V_48 == NULL ) ) {
return - V_31 ;
}
V_43 = F_1 ( V_3 ) ;
V_80 = V_3 -> V_48 [ V_79 ] . V_30 ;
if ( V_43 -> V_76 == V_80 ) {
if ( F_14 ( V_3 -> V_77 ) ) {
F_12 ( L_8 ,
V_80 ) ;
V_3 -> V_77 = 0 ;
} else {
F_12 ( L_9 ,
V_80 ) ;
goto V_82;
}
}
switch ( V_3 -> V_54 ) {
case V_55 :
V_60 . type = V_55 ;
V_60 . V_62 . V_9 . V_23 = V_70 ;
V_60 . V_25 = ( T_1 ) V_43 -> V_46 [ V_80 ] . V_83 ;
break;
case V_56 :
V_60 . type = V_56 ;
V_60 . V_62 . V_9 . V_23 = V_71 ;
V_60 . V_25 = ( T_1 ) V_43 -> V_46 [ V_80 ] . V_83 ;
break;
case V_57 :
V_60 . type = V_57 ;
V_60 . V_62 . V_64 . V_65 = V_43 -> V_72 . V_73 ;
V_60 . V_62 . V_64 . V_66 = V_43 -> V_72 . V_66 ;
V_60 . V_25 = ( T_1 ) V_43 -> V_46 [ V_80 ] . V_83 ;
break;
default:
V_81 = - V_31 ;
goto V_82;
}
if ( V_28 -> V_84 != V_85 )
V_60 . V_68 = V_28 -> V_86 ;
else
V_60 . V_68 = F_45 ( V_28 -> V_6 ) ;
F_36 ( & V_60 ) ;
if ( V_87 ) {
if ( ! F_46 ( V_60 . V_68 , V_3 -> V_48 [ V_79 ] . V_49 ,
V_3 ) ) {
F_12 ( L_10 ,
V_28 -> V_6 ) ;
V_81 = - V_88 ;
}
}
if ( ! V_81 )
V_43 -> V_76 = V_80 ;
V_82:
return V_81 ;
}
static unsigned long
F_49 ( struct V_2 * V_3 , unsigned int V_6 )
{
struct V_1 * V_43 ;
V_43 = F_1 ( V_3 ) ;
if ( V_89 ) {
unsigned int V_44 ;
unsigned long V_74 ;
unsigned long V_90 = V_43 -> V_46 [ 0 ] . V_91 * 1000 ;
for ( V_44 = 0 ; V_44 < ( V_43 -> V_45 - 1 ) ; V_44 ++ ) {
V_74 = V_90 ;
V_90 = V_43 -> V_46 [ V_44 + 1 ] . V_91 * 1000 ;
if ( ( 2 * V_89 ) > ( V_90 + V_74 ) ) {
V_43 -> V_76 = V_44 ;
return V_74 ;
}
}
V_43 -> V_76 = V_43 -> V_45 - 1 ;
return V_90 ;
} else {
V_43 -> V_76 = 0 ;
return V_43 -> V_46 [ 0 ] . V_91 * 1000 ;
}
}
static void F_50 ( void )
{
unsigned int V_44 ;
F_51 (i)
F_52 ( F_2 ( V_4 , V_44 )
-> V_92 ) ;
F_53 ( V_4 ) ;
}
static int F_54 ( struct V_93 * V_94 , unsigned long V_95 ,
void * V_96 )
{
unsigned V_6 = ( long ) V_96 ;
const struct V_19 * V_19 ;
V_19 = F_55 ( V_6 ) ;
switch ( V_95 ) {
case V_97 :
case V_98 :
F_5 ( V_35 . V_37 , V_19 ) ;
break;
case V_99 :
case V_100 :
F_5 ( 1 , V_19 ) ;
break;
default:
break;
}
return V_101 ;
}
static int T_5 F_56 ( void )
{
unsigned int V_44 ;
F_12 ( L_11 ) ;
V_4 = F_57 ( struct V_1 ) ;
if ( ! V_4 ) {
F_12 ( L_12 ) ;
return - V_102 ;
}
F_51 (i) {
if ( ! F_58 (
& F_2 ( V_4 , V_44 ) -> V_92 ,
V_103 , F_59 ( V_44 ) ) ) {
F_50 () ;
return - V_102 ;
}
}
F_60 ( V_4 ) ;
return 0 ;
}
static int F_61 ( const struct V_104 * V_105 )
{
V_106 = 1 ;
return 0 ;
}
static int F_62 ( struct V_39 * V_107 )
{
if ( V_107 -> V_11 == V_12 ) {
if ( ( V_107 -> V_108 == 15 ) &&
( V_107 -> V_109 == 6 ) &&
( V_107 -> V_110 == 8 ) ) {
F_63 ( V_111 L_13
L_14
L_15
L_16 ) ;
return - V_31 ;
}
}
return 0 ;
}
static int F_64 ( struct V_27 * V_28 )
{
unsigned int V_44 ;
unsigned int V_112 = 0 ;
unsigned int V_6 = V_28 -> V_6 ;
struct V_2 * V_3 ;
unsigned int V_81 = 0 ;
struct V_39 * V_107 = & F_20 ( V_28 -> V_6 ) ;
struct V_1 * V_43 ;
#ifdef F_65
static int V_113 ;
#endif
F_12 ( L_17 ) ;
#ifdef F_65
if ( V_113 )
return V_113 ;
V_113 = F_62 ( V_107 ) ;
if ( V_113 )
return V_113 ;
#endif
V_3 = F_66 ( sizeof( * V_3 ) , V_103 ) ;
if ( ! V_3 )
return - V_102 ;
if ( ! F_67 ( & V_3 -> V_32 , V_103 ) ) {
V_81 = - V_102 ;
goto V_114;
}
V_43 = F_2 ( V_4 , V_6 ) ;
V_3 -> V_5 = V_6 ;
V_28 -> V_30 = V_3 ;
if ( F_21 ( V_107 , V_115 ) )
V_35 . V_116 |= V_117 ;
V_81 = F_68 ( V_43 , V_6 ) ;
if ( V_81 )
goto V_118;
V_28 -> V_84 = V_43 -> V_84 ;
if ( V_28 -> V_84 == V_119 ||
V_28 -> V_84 == V_85 ) {
F_69 ( V_28 -> V_86 , V_43 -> V_92 ) ;
}
F_69 ( V_3 -> V_32 , V_43 -> V_92 ) ;
#ifdef F_65
F_70 ( V_120 ) ;
if ( V_106 && ! F_71 ( V_28 ) ) {
V_28 -> V_84 = V_119 ;
F_69 ( V_28 -> V_86 , F_72 ( V_6 ) ) ;
}
if ( F_22 ( V_6 ) && ! V_87 ) {
F_73 ( V_28 -> V_86 ) ;
F_74 ( V_6 , V_28 -> V_86 ) ;
F_69 ( V_3 -> V_32 ,
F_75 ( V_6 ) ) ;
V_28 -> V_84 = V_121 ;
F_76 ( V_122 L_18 ) ;
}
#endif
if ( V_43 -> V_45 <= 1 ) {
F_12 ( L_19 ) ;
V_81 = - V_31 ;
goto V_123;
}
if ( V_43 -> V_72 . V_124 != V_43 -> V_125 . V_124 ) {
V_81 = - V_31 ;
goto V_123;
}
switch ( V_43 -> V_72 . V_124 ) {
case V_126 :
if ( V_10 . V_11 == V_15 &&
V_10 . V_108 == 0xf ) {
F_12 ( L_20 ) ;
V_81 = - V_31 ;
goto V_123;
}
F_12 ( L_21 ) ;
V_3 -> V_54 = V_57 ;
break;
case V_127 :
F_12 ( L_22 ) ;
if ( F_19 ( V_6 ) ) {
V_3 -> V_54 = V_55 ;
break;
}
if ( F_22 ( V_6 ) ) {
V_3 -> V_54 = V_56 ;
break;
}
V_81 = - V_31 ;
goto V_123;
default:
F_12 ( L_23 ,
( T_1 ) ( V_43 -> V_72 . V_124 ) ) ;
V_81 = - V_31 ;
goto V_123;
}
V_3 -> V_48 = F_66 ( sizeof( * V_3 -> V_48 ) *
( V_43 -> V_45 + 1 ) , V_103 ) ;
if ( ! V_3 -> V_48 ) {
V_81 = - V_102 ;
goto V_123;
}
V_28 -> V_128 . V_129 = 0 ;
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ ) {
if ( ( V_43 -> V_46 [ V_44 ] . V_129 * 1000 ) >
V_28 -> V_128 . V_129 )
V_28 -> V_128 . V_129 =
V_43 -> V_46 [ V_44 ] . V_129 * 1000 ;
}
if ( V_43 -> V_72 . V_124 == V_127 &&
V_28 -> V_128 . V_129 > 20 * 1000 ) {
V_28 -> V_128 . V_129 = 20 * 1000 ;
F_77 ( V_111
L_24 ) ;
}
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ ) {
if ( V_44 > 0 && V_43 -> V_46 [ V_44 ] . V_91 >=
V_3 -> V_48 [ V_112 - 1 ] . V_49 / 1000 )
continue;
V_3 -> V_48 [ V_112 ] . V_30 = V_44 ;
V_3 -> V_48 [ V_112 ] . V_49 =
V_43 -> V_46 [ V_44 ] . V_91 * 1000 ;
V_112 ++ ;
}
V_3 -> V_48 [ V_112 ] . V_49 = V_130 ;
V_43 -> V_76 = 0 ;
V_81 = F_78 ( V_28 , V_3 -> V_48 ) ;
if ( V_81 )
goto V_131;
if ( V_43 -> V_46 [ 0 ] . V_91 * 1000 != V_28 -> V_128 . V_132 )
F_63 (KERN_WARNING FW_WARN L_25 ) ;
switch ( V_43 -> V_72 . V_124 ) {
case V_126 :
V_28 -> V_133 = F_49 ( V_3 , V_28 -> V_6 ) ;
break;
case V_127 :
V_35 . V_134 = F_43 ;
break;
default:
break;
}
F_79 ( V_135 ) ;
F_12 ( L_26 , V_6 ) ;
for ( V_44 = 0 ; V_44 < V_43 -> V_45 ; V_44 ++ )
F_12 ( L_27 ,
( V_44 == V_43 -> V_76 ? '*' : ' ' ) , V_44 ,
( T_1 ) V_43 -> V_46 [ V_44 ] . V_91 ,
( T_1 ) V_43 -> V_46 [ V_44 ] . V_136 ,
( T_1 ) V_43 -> V_46 [ V_44 ] . V_129 ) ;
V_3 -> V_77 = 1 ;
return V_81 ;
V_131:
F_80 ( V_3 -> V_48 ) ;
V_123:
F_81 ( V_6 ) ;
V_118:
F_52 ( V_3 -> V_32 ) ;
V_114:
F_80 ( V_3 ) ;
V_28 -> V_30 = NULL ;
return V_81 ;
}
static int F_82 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
F_12 ( L_28 ) ;
if ( V_3 ) {
V_28 -> V_30 = NULL ;
F_81 ( V_3 -> V_5 ) ;
F_52 ( V_3 -> V_32 ) ;
F_80 ( V_3 -> V_48 ) ;
F_80 ( V_3 ) ;
}
return 0 ;
}
static int F_83 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = V_28 -> V_30 ;
F_12 ( L_29 ) ;
V_3 -> V_77 = 1 ;
return 0 ;
}
static void T_5 F_84 ( void )
{
if ( F_85 ( V_137 ) || F_85 ( V_138 ) ) {
V_22 = F_86 () ;
if ( ! V_22 )
return;
V_35 . F_9 = F_9 ;
V_35 . V_37 = F_3 ( 0 ) ;
F_87 () ;
F_5 ( V_35 . V_37 ,
V_26 ) ;
F_88 ( & V_139 ) ;
F_89 () ;
}
}
static void F_90 ( void )
{
if ( V_22 ) {
F_91 ( & V_139 ) ;
F_92 ( V_22 ) ;
V_22 = NULL ;
}
}
static int T_5 F_93 ( void )
{
int V_34 ;
if ( V_140 )
return - V_31 ;
if ( F_94 () )
return - V_141 ;
F_12 ( L_30 ) ;
V_34 = F_56 () ;
if ( V_34 )
return V_34 ;
#ifdef F_95
if ( ! F_22 ( 0 ) ) {
struct V_142 * * V_143 ;
F_12 ( L_31 ) ;
for ( V_143 = V_144 ; * V_143 ; V_143 ++ )
if ( * V_143 == & V_145 ) {
* V_143 = NULL ;
break;
}
}
#endif
F_84 () ;
V_34 = F_96 ( & V_35 ) ;
if ( V_34 ) {
F_50 () ;
F_90 () ;
}
return V_34 ;
}
static void T_6 F_97 ( void )
{
F_12 ( L_32 ) ;
F_90 () ;
F_98 ( & V_35 ) ;
F_50 () ;
}
