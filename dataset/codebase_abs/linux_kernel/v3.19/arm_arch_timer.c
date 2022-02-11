static T_1
void F_1 ( int V_1 , enum V_2 V_3 , T_2 V_4 ,
struct V_5 * V_6 )
{
if ( V_1 == V_7 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
F_3 ( V_4 , V_9 -> V_11 + V_12 ) ;
break;
case V_13 :
F_3 ( V_4 , V_9 -> V_11 + V_14 ) ;
break;
}
} else if ( V_1 == V_15 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
F_3 ( V_4 , V_9 -> V_11 + V_16 ) ;
break;
case V_13 :
F_3 ( V_4 , V_9 -> V_11 + V_17 ) ;
break;
}
} else {
F_4 ( V_1 , V_3 , V_4 ) ;
}
}
static T_1
T_2 F_5 ( int V_1 , enum V_2 V_3 ,
struct V_5 * V_6 )
{
T_2 V_4 ;
if ( V_1 == V_7 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
V_4 = F_6 ( V_9 -> V_11 + V_12 ) ;
break;
case V_13 :
V_4 = F_6 ( V_9 -> V_11 + V_14 ) ;
break;
}
} else if ( V_1 == V_15 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
V_4 = F_6 ( V_9 -> V_11 + V_16 ) ;
break;
case V_13 :
V_4 = F_6 ( V_9 -> V_11 + V_17 ) ;
break;
}
} else {
V_4 = F_7 ( V_1 , V_3 ) ;
}
return V_4 ;
}
static T_1 T_3 F_8 ( const int V_1 ,
struct V_5 * V_18 )
{
unsigned long V_19 ;
V_19 = F_5 ( V_1 , V_10 , V_18 ) ;
if ( V_19 & V_20 ) {
V_19 |= V_21 ;
F_1 ( V_1 , V_10 , V_19 , V_18 ) ;
V_18 -> V_22 ( V_18 ) ;
return V_23 ;
}
return V_24 ;
}
static T_3 F_9 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_27 , V_18 ) ;
}
static T_3 F_10 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_28 , V_18 ) ;
}
static T_3 F_11 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_7 , V_18 ) ;
}
static T_3 F_12 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_15 , V_18 ) ;
}
static T_1 void F_13 ( const int V_1 , int V_29 ,
struct V_5 * V_6 )
{
unsigned long V_19 ;
switch ( V_29 ) {
case V_30 :
case V_31 :
V_19 = F_5 ( V_1 , V_10 , V_6 ) ;
V_19 &= ~ V_32 ;
F_1 ( V_1 , V_10 , V_19 , V_6 ) ;
break;
default:
break;
}
}
static void F_14 ( enum V_33 V_29 ,
struct V_5 * V_6 )
{
F_13 ( V_27 , V_29 , V_6 ) ;
}
static void F_15 ( enum V_33 V_29 ,
struct V_5 * V_6 )
{
F_13 ( V_28 , V_29 , V_6 ) ;
}
static void F_16 ( enum V_33 V_29 ,
struct V_5 * V_6 )
{
F_13 ( V_15 , V_29 , V_6 ) ;
}
static void F_17 ( enum V_33 V_29 ,
struct V_5 * V_6 )
{
F_13 ( V_7 , V_29 , V_6 ) ;
}
static T_1 void F_18 ( const int V_1 , unsigned long V_18 ,
struct V_5 * V_6 )
{
unsigned long V_19 ;
V_19 = F_5 ( V_1 , V_10 , V_6 ) ;
V_19 |= V_32 ;
V_19 &= ~ V_21 ;
F_1 ( V_1 , V_13 , V_18 , V_6 ) ;
F_1 ( V_1 , V_10 , V_19 , V_6 ) ;
}
static int F_19 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_27 , V_18 , V_6 ) ;
return 0 ;
}
static int F_20 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_28 , V_18 , V_6 ) ;
return 0 ;
}
static int F_21 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_15 , V_18 , V_6 ) ;
return 0 ;
}
static int F_22 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_7 , V_18 , V_6 ) ;
return 0 ;
}
static void F_23 ( unsigned type ,
struct V_5 * V_6 )
{
V_6 -> V_34 = V_35 ;
if ( type == V_36 ) {
if ( V_37 )
V_6 -> V_34 |= V_38 ;
V_6 -> V_39 = L_1 ;
V_6 -> V_40 = 450 ;
V_6 -> V_41 = F_24 ( F_25 () ) ;
if ( V_42 ) {
V_6 -> V_25 = V_43 [ V_44 ] ;
V_6 -> V_45 = F_14 ;
V_6 -> F_18 = F_19 ;
} else {
V_6 -> V_25 = V_43 [ V_46 ] ;
V_6 -> V_45 = F_15 ;
V_6 -> F_18 = F_20 ;
}
} else {
V_6 -> V_34 |= V_47 ;
V_6 -> V_39 = L_2 ;
V_6 -> V_40 = 400 ;
V_6 -> V_41 = V_48 ;
if ( V_49 ) {
V_6 -> V_45 = F_16 ;
V_6 -> F_18 =
F_21 ;
} else {
V_6 -> V_45 = F_17 ;
V_6 -> F_18 =
F_22 ;
}
}
V_6 -> V_45 ( V_31 , V_6 ) ;
F_26 ( V_6 , V_50 , 0xf , 0x7fffffff ) ;
}
static void F_27 ( int V_51 )
{
T_2 V_52 = F_28 () ;
V_52 &= ~ V_53 ;
V_52 |= ( V_51 << V_54 )
| V_55 ;
F_29 ( V_52 ) ;
V_56 |= V_57 ;
#ifdef F_30
V_58 |= V_59 ;
#endif
}
static void F_31 ( void )
{
int V_60 , V_61 ;
V_60 = V_50 / V_62 ;
V_61 = F_32 ( V_60 ) ;
if ( V_61 > 1 && ! ( V_60 & ( 1 << ( V_61 - 2 ) ) ) )
V_61 -- ;
F_27 ( F_33 ( V_61 , 15 ) ) ;
}
static void F_34 ( void )
{
T_2 V_52 = F_28 () ;
V_52 &= ~ ( V_63
| V_64
| V_55
| V_65 ) ;
V_52 |= V_66 ;
F_29 ( V_52 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
F_23 ( V_36 , V_6 ) ;
if ( V_42 )
F_36 ( V_43 [ V_44 ] , 0 ) ;
else {
F_36 ( V_43 [ V_46 ] , 0 ) ;
if ( V_43 [ V_67 ] )
F_36 ( V_43 [ V_67 ] , 0 ) ;
}
F_34 () ;
if ( F_37 ( V_68 ) )
F_31 () ;
return 0 ;
}
static void
F_38 ( void T_4 * V_69 , struct V_70 * V_71 )
{
if ( V_50 )
return;
if ( F_39 ( V_71 , L_3 , & V_50 ) ) {
if ( V_69 )
V_50 = F_6 ( V_69 + V_72 ) ;
else
V_50 = F_40 () ;
}
if ( V_50 == 0 )
F_41 ( L_4 ) ;
}
static void F_42 ( unsigned type )
{
F_43 ( L_5 ,
type & V_36 ? L_6 : L_7 ,
type == ( V_36 | V_73 ) ? L_8 : L_7 ,
type & V_73 ? L_9 : L_7 ,
( unsigned long ) V_50 / 1000000 ,
( unsigned long ) ( V_50 / 10000 ) % 100 ,
type & V_36 ?
V_42 ? L_10 : L_11 :
L_7 ,
type == ( V_36 | V_73 ) ? L_12 : L_7 ,
type & V_73 ?
V_49 ? L_10 : L_11 :
L_7 ) ;
}
T_2 F_44 ( void )
{
return V_50 ;
}
static T_5 F_45 ( void )
{
T_2 V_74 , V_75 , V_76 ;
do {
V_75 = F_6 ( V_77 + V_78 ) ;
V_74 = F_6 ( V_77 + V_79 ) ;
V_76 = F_6 ( V_77 + V_78 ) ;
} while ( V_75 != V_76 );
return ( ( T_5 ) V_75 << 32 ) | V_74 ;
}
static T_6 F_46 ( struct V_80 * V_81 )
{
return F_47 () ;
}
static T_6 F_48 ( const struct V_82 * V_83 )
{
return F_47 () ;
}
struct V_84 * F_49 ( void )
{
return & V_84 ;
}
static void T_7 F_50 ( unsigned type )
{
T_5 V_85 ;
if ( type & V_36 ) {
if ( F_37 ( V_86 ) || V_42 )
F_47 = V_87 ;
else
F_47 = V_88 ;
} else {
F_47 = F_45 ;
V_89 . V_39 = L_13 ;
}
V_85 = F_47 () ;
F_51 ( & V_89 , V_50 ) ;
V_82 . V_90 = V_89 . V_90 ;
V_82 . V_91 = V_89 . V_91 ;
F_52 ( & V_84 , & V_82 , V_85 ) ;
F_53 ( F_47 , 56 , V_50 ) ;
}
static void F_54 ( struct V_5 * V_6 )
{
F_55 ( L_14 ,
V_6 -> V_25 , F_25 () ) ;
if ( V_42 )
F_56 ( V_43 [ V_44 ] ) ;
else {
F_56 ( V_43 [ V_46 ] ) ;
if ( V_43 [ V_67 ] )
F_56 ( V_43 [ V_67 ] ) ;
}
V_6 -> V_45 ( V_30 , V_6 ) ;
}
static int F_57 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
switch ( V_94 & ~ V_96 ) {
case V_97 :
F_35 ( F_58 ( V_98 ) ) ;
break;
case V_99 :
F_54 ( F_58 ( V_98 ) ) ;
break;
}
return V_100 ;
}
static int F_59 ( struct V_92 * V_93 ,
unsigned long V_94 , void * V_95 )
{
if ( V_94 == V_101 )
V_102 = F_28 () ;
else if ( V_94 == V_103 || V_94 == V_104 )
F_29 ( V_102 ) ;
return V_100 ;
}
static int T_7 F_60 ( void )
{
return F_61 ( & V_105 ) ;
}
static int T_7 F_60 ( void )
{
return 0 ;
}
static int T_7 F_62 ( void )
{
int V_106 ;
int V_107 ;
V_98 = F_63 ( struct V_5 ) ;
if ( ! V_98 ) {
V_106 = - V_108 ;
goto V_109;
}
if ( V_42 ) {
V_107 = V_43 [ V_44 ] ;
V_106 = F_64 ( V_107 , F_9 ,
L_15 , V_98 ) ;
} else {
V_107 = V_43 [ V_46 ] ;
V_106 = F_64 ( V_107 , F_10 ,
L_15 , V_98 ) ;
if ( ! V_106 && V_43 [ V_67 ] ) {
V_107 = V_43 [ V_67 ] ;
V_106 = F_64 ( V_107 , F_10 ,
L_15 , V_98 ) ;
if ( V_106 )
F_65 ( V_43 [ V_46 ] ,
V_98 ) ;
}
}
if ( V_106 ) {
F_66 ( L_16 ,
V_107 , V_106 ) ;
goto V_110;
}
V_106 = F_67 ( & V_111 ) ;
if ( V_106 )
goto V_112;
V_106 = F_60 () ;
if ( V_106 )
goto V_113;
F_35 ( F_58 ( V_98 ) ) ;
return 0 ;
V_113:
F_68 ( & V_111 ) ;
V_112:
if ( V_42 )
F_65 ( V_43 [ V_44 ] , V_98 ) ;
else {
F_65 ( V_43 [ V_46 ] ,
V_98 ) ;
if ( V_43 [ V_67 ] )
F_65 ( V_43 [ V_67 ] ,
V_98 ) ;
}
V_110:
F_69 ( V_98 ) ;
V_109:
return V_106 ;
}
static int T_7 F_70 ( void T_4 * V_11 , unsigned int V_25 )
{
int V_114 ;
T_8 V_115 ;
struct V_8 * V_116 ;
V_116 = F_71 ( sizeof( * V_116 ) , V_117 ) ;
if ( ! V_116 )
return - V_108 ;
V_116 -> V_11 = V_11 ;
V_116 -> V_18 . V_25 = V_25 ;
F_23 ( V_73 , & V_116 -> V_18 ) ;
if ( V_49 )
V_115 = F_12 ;
else
V_115 = F_11 ;
V_114 = F_72 ( V_25 , V_115 , V_118 , L_2 , & V_116 -> V_18 ) ;
if ( V_114 ) {
F_66 ( L_17 ) ;
F_73 ( V_116 ) ;
}
return V_114 ;
}
static bool T_7
F_74 ( int type , const struct V_119 * V_120 )
{
struct V_70 * V_121 ;
bool V_122 = true ;
V_121 = F_75 ( NULL , V_120 ) ;
if ( V_121 && F_76 ( V_121 ) && ! ( V_123 & type ) )
V_122 = false ;
F_77 ( V_121 ) ;
return V_122 ;
}
static void T_7 F_78 ( void )
{
unsigned V_124 = V_36 | V_73 ;
if ( ( V_123 & V_124 ) != V_124 ) {
if ( ! F_74 ( V_73 , V_125 ) )
return;
if ( ! F_74 ( V_36 , V_126 ) )
return;
}
F_42 ( V_123 ) ;
F_50 ( V_123 ) ;
F_79 () ;
}
static void T_7 F_80 ( struct V_70 * V_71 )
{
int V_127 ;
if ( V_123 & V_36 ) {
F_41 ( L_18 ) ;
return;
}
V_123 |= V_36 ;
for ( V_127 = V_46 ; V_127 < V_128 ; V_127 ++ )
V_43 [ V_127 ] = F_81 ( V_71 , V_127 ) ;
F_38 ( NULL , V_71 ) ;
if ( F_37 ( V_129 ) &&
F_82 ( V_71 , L_19 ) )
V_42 = false ;
if ( F_83 () || ! V_43 [ V_44 ] ) {
V_42 = false ;
if ( ! V_43 [ V_46 ] ||
! V_43 [ V_67 ] ) {
F_41 ( L_20 ) ;
return;
}
}
V_37 = ! F_82 ( V_71 , L_21 ) ;
F_62 () ;
F_78 () ;
}
static void T_7 F_84 ( struct V_70 * V_71 )
{
struct V_70 * V_130 , * V_131 = NULL ;
void T_4 * V_132 , * V_11 ;
unsigned int V_25 ;
T_2 V_133 ;
V_123 |= V_73 ;
V_132 = F_85 ( V_71 , 0 ) ;
if ( ! V_132 ) {
F_66 ( L_22 ) ;
return;
}
V_133 = F_6 ( V_132 + V_134 ) ;
F_86 ( V_132 ) ;
F_87 (np, frame) {
int V_135 ;
if ( F_39 ( V_130 , L_23 , & V_135 ) ) {
F_66 ( L_24 ) ;
F_77 ( V_131 ) ;
F_77 ( V_130 ) ;
return;
}
if ( V_133 & F_88 ( V_135 ) ) {
F_77 ( V_131 ) ;
V_131 = V_130 ;
V_49 = true ;
break;
}
F_77 ( V_131 ) ;
V_131 = F_89 ( V_130 ) ;
}
V_11 = V_77 = F_85 ( V_131 , 0 ) ;
if ( ! V_11 ) {
F_66 ( L_25 ) ;
F_77 ( V_131 ) ;
return;
}
if ( V_49 )
V_25 = F_81 ( V_131 , 1 ) ;
else
V_25 = F_81 ( V_131 , 0 ) ;
F_77 ( V_131 ) ;
if ( ! V_25 ) {
F_66 ( L_26 ,
V_49 ? L_10 : L_11 ) ;
return;
}
F_38 ( V_11 , V_71 ) ;
F_70 ( V_11 , V_25 ) ;
F_78 () ;
}
