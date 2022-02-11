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
V_6 -> V_34 |= V_37 ;
V_6 -> V_38 = L_1 ;
V_6 -> V_39 = 450 ;
V_6 -> V_40 = F_24 ( F_25 () ) ;
if ( V_41 ) {
V_6 -> V_25 = V_42 [ V_43 ] ;
V_6 -> V_44 = F_14 ;
V_6 -> F_18 = F_19 ;
} else {
V_6 -> V_25 = V_42 [ V_45 ] ;
V_6 -> V_44 = F_15 ;
V_6 -> F_18 = F_20 ;
}
} else {
V_6 -> V_38 = L_2 ;
V_6 -> V_39 = 400 ;
V_6 -> V_40 = V_46 ;
if ( V_47 ) {
V_6 -> V_44 = F_16 ;
V_6 -> F_18 =
F_21 ;
} else {
V_6 -> V_44 = F_17 ;
V_6 -> F_18 =
F_22 ;
}
}
V_6 -> V_44 ( V_31 , V_6 ) ;
F_26 ( V_6 , V_48 , 0xf , 0x7fffffff ) ;
}
static void F_27 ( void )
{
int V_49 , V_50 ;
V_49 = V_48 / V_51 ;
V_50 = F_28 ( V_49 ) ;
if ( V_50 > 1 && ! ( V_49 & ( 1 << ( V_50 - 2 ) ) ) )
V_50 -- ;
F_29 ( F_30 ( V_50 , 15 ) ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
F_23 ( V_36 , V_6 ) ;
if ( V_41 )
F_32 ( V_42 [ V_43 ] , 0 ) ;
else {
F_32 ( V_42 [ V_45 ] , 0 ) ;
if ( V_42 [ V_52 ] )
F_32 ( V_42 [ V_52 ] , 0 ) ;
}
F_33 () ;
if ( F_34 ( V_53 ) )
F_27 () ;
return 0 ;
}
static void
F_35 ( void T_4 * V_54 , struct V_55 * V_56 )
{
if ( V_48 )
return;
if ( F_36 ( V_56 , L_3 , & V_48 ) ) {
if ( V_54 )
V_48 = F_6 ( V_54 + V_57 ) ;
else
V_48 = F_37 () ;
}
if ( V_48 == 0 )
F_38 ( L_4 ) ;
}
static void F_39 ( unsigned type )
{
F_40 ( L_5 ,
type & V_36 ? L_6 : L_7 ,
type == ( V_36 | V_58 ) ? L_8 : L_7 ,
type & V_58 ? L_9 : L_7 ,
( unsigned long ) V_48 / 1000000 ,
( unsigned long ) ( V_48 / 10000 ) % 100 ,
type & V_36 ?
V_41 ? L_10 : L_11 :
L_7 ,
type == ( V_36 | V_58 ) ? L_12 : L_7 ,
type & V_58 ?
V_47 ? L_10 : L_11 :
L_7 ) ;
}
T_2 F_41 ( void )
{
return V_48 ;
}
static T_5 F_42 ( void )
{
T_2 V_59 , V_60 , V_61 ;
do {
V_60 = F_6 ( V_62 + V_63 ) ;
V_59 = F_6 ( V_62 + V_64 ) ;
V_61 = F_6 ( V_62 + V_63 ) ;
} while ( V_60 != V_61 );
return ( ( T_5 ) V_60 << 32 ) | V_59 ;
}
static T_6 F_43 ( struct V_65 * V_66 )
{
return F_44 () ;
}
static T_6 F_45 ( const struct V_67 * V_68 )
{
return F_44 () ;
}
struct V_69 * F_46 ( void )
{
return & V_69 ;
}
static void T_7 F_47 ( unsigned type )
{
T_5 V_70 ;
if ( type & V_36 )
F_44 = V_71 ;
else
F_44 = F_42 ;
V_70 = F_44 () ;
F_48 ( & V_72 , V_48 ) ;
V_67 . V_73 = V_72 . V_73 ;
V_67 . V_74 = V_72 . V_74 ;
F_49 ( & V_69 , & V_67 , V_70 ) ;
F_50 ( F_44 , 56 , V_48 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_52 ( L_13 ,
V_6 -> V_25 , F_25 () ) ;
if ( V_41 )
F_53 ( V_42 [ V_43 ] ) ;
else {
F_53 ( V_42 [ V_45 ] ) ;
if ( V_42 [ V_52 ] )
F_53 ( V_42 [ V_52 ] ) ;
}
V_6 -> V_44 ( V_30 , V_6 ) ;
}
static int F_54 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
switch ( V_77 & ~ V_79 ) {
case V_80 :
F_31 ( F_55 ( V_81 ) ) ;
break;
case V_82 :
F_51 ( F_55 ( V_81 ) ) ;
break;
}
return V_83 ;
}
static int F_56 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
if ( V_77 == V_84 )
V_85 = F_57 () ;
else if ( V_77 == V_86 || V_77 == V_87 )
F_58 ( V_85 ) ;
return V_83 ;
}
static int T_7 F_59 ( void )
{
return F_60 ( & V_88 ) ;
}
static int T_7 F_59 ( void )
{
return 0 ;
}
static int T_7 F_61 ( void )
{
int V_89 ;
int V_90 ;
V_81 = F_62 ( struct V_5 ) ;
if ( ! V_81 ) {
V_89 = - V_91 ;
goto V_92;
}
if ( V_41 ) {
V_90 = V_42 [ V_43 ] ;
V_89 = F_63 ( V_90 , F_9 ,
L_14 , V_81 ) ;
} else {
V_90 = V_42 [ V_45 ] ;
V_89 = F_63 ( V_90 , F_10 ,
L_14 , V_81 ) ;
if ( ! V_89 && V_42 [ V_52 ] ) {
V_90 = V_42 [ V_52 ] ;
V_89 = F_63 ( V_90 , F_10 ,
L_14 , V_81 ) ;
if ( V_89 )
F_64 ( V_42 [ V_45 ] ,
V_81 ) ;
}
}
if ( V_89 ) {
F_65 ( L_15 ,
V_90 , V_89 ) ;
goto V_93;
}
V_89 = F_66 ( & V_94 ) ;
if ( V_89 )
goto V_95;
V_89 = F_59 () ;
if ( V_89 )
goto V_96;
F_31 ( F_55 ( V_81 ) ) ;
return 0 ;
V_96:
F_67 ( & V_94 ) ;
V_95:
if ( V_41 )
F_64 ( V_42 [ V_43 ] , V_81 ) ;
else {
F_64 ( V_42 [ V_45 ] ,
V_81 ) ;
if ( V_42 [ V_52 ] )
F_64 ( V_42 [ V_52 ] ,
V_81 ) ;
}
V_93:
F_68 ( V_81 ) ;
V_92:
return V_89 ;
}
static int T_7 F_69 ( void T_4 * V_11 , unsigned int V_25 )
{
int V_97 ;
T_8 V_98 ;
struct V_8 * V_99 ;
V_99 = F_70 ( sizeof( * V_99 ) , V_100 ) ;
if ( ! V_99 )
return - V_91 ;
V_99 -> V_11 = V_11 ;
V_99 -> V_18 . V_25 = V_25 ;
F_23 ( V_58 , & V_99 -> V_18 ) ;
if ( V_47 )
V_98 = F_12 ;
else
V_98 = F_11 ;
V_97 = F_71 ( V_25 , V_98 , V_101 , L_2 , & V_99 -> V_18 ) ;
if ( V_97 ) {
F_65 ( L_16 ) ;
F_72 ( V_99 ) ;
}
return V_97 ;
}
static void T_7 F_73 ( void )
{
unsigned V_102 = V_36 | V_58 ;
if ( ( V_103 & V_102 ) != V_102 ) {
if ( F_74 ( NULL , V_104 ) &&
! ( V_103 & V_58 ) )
return;
if ( F_74 ( NULL , V_105 ) &&
! ( V_103 & V_36 ) )
return;
}
F_39 ( V_103 ) ;
F_47 ( V_103 ) ;
F_75 () ;
}
static void T_7 F_76 ( struct V_55 * V_56 )
{
int V_106 ;
if ( V_103 & V_36 ) {
F_38 ( L_17 ) ;
return;
}
V_103 |= V_36 ;
for ( V_106 = V_45 ; V_106 < V_107 ; V_106 ++ )
V_42 [ V_106 ] = F_77 ( V_56 , V_106 ) ;
F_35 ( NULL , V_56 ) ;
if ( F_78 () || ! V_42 [ V_43 ] ) {
V_41 = false ;
if ( ! V_42 [ V_45 ] ||
! V_42 [ V_52 ] ) {
F_38 ( L_18 ) ;
return;
}
}
F_61 () ;
F_73 () ;
}
static void T_7 F_79 ( struct V_55 * V_56 )
{
struct V_55 * V_108 , * V_109 = NULL ;
void T_4 * V_110 , * V_11 ;
unsigned int V_25 ;
T_2 V_111 ;
V_103 |= V_58 ;
V_110 = F_80 ( V_56 , 0 ) ;
if ( ! V_110 ) {
F_65 ( L_19 ) ;
return;
}
V_111 = F_6 ( V_110 + V_112 ) ;
F_81 ( V_110 ) ;
F_82 (np, frame) {
int V_113 ;
if ( F_36 ( V_108 , L_20 , & V_113 ) ) {
F_65 ( L_21 ) ;
F_83 ( V_109 ) ;
F_83 ( V_108 ) ;
return;
}
if ( V_111 & F_84 ( V_113 ) ) {
F_83 ( V_109 ) ;
V_109 = V_108 ;
V_47 = true ;
break;
}
F_83 ( V_109 ) ;
V_109 = F_85 ( V_108 ) ;
}
V_11 = V_62 = F_80 ( V_109 , 0 ) ;
if ( ! V_11 ) {
F_65 ( L_22 ) ;
F_83 ( V_109 ) ;
return;
}
if ( V_47 )
V_25 = F_77 ( V_109 , 1 ) ;
else
V_25 = F_77 ( V_109 , 0 ) ;
F_83 ( V_109 ) ;
if ( ! V_25 ) {
F_65 ( L_23 ,
V_47 ? L_10 : L_11 ) ;
return;
}
F_35 ( V_11 , V_56 ) ;
F_69 ( V_11 , V_25 ) ;
F_73 () ;
}
