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
static void F_27 ( void )
{
int V_51 , V_52 ;
V_51 = V_50 / V_53 ;
V_52 = F_28 ( V_51 ) ;
if ( V_52 > 1 && ! ( V_51 & ( 1 << ( V_52 - 2 ) ) ) )
V_52 -- ;
F_29 ( F_30 ( V_52 , 15 ) ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
F_23 ( V_36 , V_6 ) ;
if ( V_42 )
F_32 ( V_43 [ V_44 ] , 0 ) ;
else {
F_32 ( V_43 [ V_46 ] , 0 ) ;
if ( V_43 [ V_54 ] )
F_32 ( V_43 [ V_54 ] , 0 ) ;
}
F_33 () ;
if ( F_34 ( V_55 ) )
F_27 () ;
return 0 ;
}
static void
F_35 ( void T_4 * V_56 , struct V_57 * V_58 )
{
if ( V_50 )
return;
if ( F_36 ( V_58 , L_3 , & V_50 ) ) {
if ( V_56 )
V_50 = F_6 ( V_56 + V_59 ) ;
else
V_50 = F_37 () ;
}
if ( V_50 == 0 )
F_38 ( L_4 ) ;
}
static void F_39 ( unsigned type )
{
F_40 ( L_5 ,
type & V_36 ? L_6 : L_7 ,
type == ( V_36 | V_60 ) ? L_8 : L_7 ,
type & V_60 ? L_9 : L_7 ,
( unsigned long ) V_50 / 1000000 ,
( unsigned long ) ( V_50 / 10000 ) % 100 ,
type & V_36 ?
V_42 ? L_10 : L_11 :
L_7 ,
type == ( V_36 | V_60 ) ? L_12 : L_7 ,
type & V_60 ?
V_49 ? L_10 : L_11 :
L_7 ) ;
}
T_2 F_41 ( void )
{
return V_50 ;
}
static T_5 F_42 ( void )
{
T_2 V_61 , V_62 , V_63 ;
do {
V_62 = F_6 ( V_64 + V_65 ) ;
V_61 = F_6 ( V_64 + V_66 ) ;
V_63 = F_6 ( V_64 + V_65 ) ;
} while ( V_62 != V_63 );
return ( ( T_5 ) V_62 << 32 ) | V_61 ;
}
static T_6 F_43 ( struct V_67 * V_68 )
{
return F_44 () ;
}
static T_6 F_45 ( const struct V_69 * V_70 )
{
return F_44 () ;
}
struct V_71 * F_46 ( void )
{
return & V_71 ;
}
static void T_7 F_47 ( unsigned type )
{
T_5 V_72 ;
if ( type & V_36 )
F_44 = V_73 ;
else
F_44 = F_42 ;
V_72 = F_44 () ;
F_48 ( & V_74 , V_50 ) ;
V_69 . V_75 = V_74 . V_75 ;
V_69 . V_76 = V_74 . V_76 ;
F_49 ( & V_71 , & V_69 , V_72 ) ;
F_50 ( F_44 , 56 , V_50 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_52 ( L_13 ,
V_6 -> V_25 , F_25 () ) ;
if ( V_42 )
F_53 ( V_43 [ V_44 ] ) ;
else {
F_53 ( V_43 [ V_46 ] ) ;
if ( V_43 [ V_54 ] )
F_53 ( V_43 [ V_54 ] ) ;
}
V_6 -> V_45 ( V_30 , V_6 ) ;
}
static int F_54 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
switch ( V_79 & ~ V_81 ) {
case V_82 :
F_31 ( F_55 ( V_83 ) ) ;
break;
case V_84 :
F_51 ( F_55 ( V_83 ) ) ;
break;
}
return V_85 ;
}
static int F_56 ( struct V_77 * V_78 ,
unsigned long V_79 , void * V_80 )
{
if ( V_79 == V_86 )
V_87 = F_57 () ;
else if ( V_79 == V_88 || V_79 == V_89 )
F_58 ( V_87 ) ;
return V_85 ;
}
static int T_7 F_59 ( void )
{
return F_60 ( & V_90 ) ;
}
static int T_7 F_59 ( void )
{
return 0 ;
}
static int T_7 F_61 ( void )
{
int V_91 ;
int V_92 ;
V_83 = F_62 ( struct V_5 ) ;
if ( ! V_83 ) {
V_91 = - V_93 ;
goto V_94;
}
if ( V_42 ) {
V_92 = V_43 [ V_44 ] ;
V_91 = F_63 ( V_92 , F_9 ,
L_14 , V_83 ) ;
} else {
V_92 = V_43 [ V_46 ] ;
V_91 = F_63 ( V_92 , F_10 ,
L_14 , V_83 ) ;
if ( ! V_91 && V_43 [ V_54 ] ) {
V_92 = V_43 [ V_54 ] ;
V_91 = F_63 ( V_92 , F_10 ,
L_14 , V_83 ) ;
if ( V_91 )
F_64 ( V_43 [ V_46 ] ,
V_83 ) ;
}
}
if ( V_91 ) {
F_65 ( L_15 ,
V_92 , V_91 ) ;
goto V_95;
}
V_91 = F_66 ( & V_96 ) ;
if ( V_91 )
goto V_97;
V_91 = F_59 () ;
if ( V_91 )
goto V_98;
F_31 ( F_55 ( V_83 ) ) ;
return 0 ;
V_98:
F_67 ( & V_96 ) ;
V_97:
if ( V_42 )
F_64 ( V_43 [ V_44 ] , V_83 ) ;
else {
F_64 ( V_43 [ V_46 ] ,
V_83 ) ;
if ( V_43 [ V_54 ] )
F_64 ( V_43 [ V_54 ] ,
V_83 ) ;
}
V_95:
F_68 ( V_83 ) ;
V_94:
return V_91 ;
}
static int T_7 F_69 ( void T_4 * V_11 , unsigned int V_25 )
{
int V_99 ;
T_8 V_100 ;
struct V_8 * V_101 ;
V_101 = F_70 ( sizeof( * V_101 ) , V_102 ) ;
if ( ! V_101 )
return - V_93 ;
V_101 -> V_11 = V_11 ;
V_101 -> V_18 . V_25 = V_25 ;
F_23 ( V_60 , & V_101 -> V_18 ) ;
if ( V_49 )
V_100 = F_12 ;
else
V_100 = F_11 ;
V_99 = F_71 ( V_25 , V_100 , V_103 , L_2 , & V_101 -> V_18 ) ;
if ( V_99 ) {
F_65 ( L_16 ) ;
F_72 ( V_101 ) ;
}
return V_99 ;
}
static void T_7 F_73 ( void )
{
unsigned V_104 = V_36 | V_60 ;
if ( ( V_105 & V_104 ) != V_104 ) {
if ( F_74 ( NULL , V_106 ) &&
! ( V_105 & V_60 ) )
return;
if ( F_74 ( NULL , V_107 ) &&
! ( V_105 & V_36 ) )
return;
}
F_39 ( V_105 ) ;
F_47 ( V_105 ) ;
F_75 () ;
}
static void T_7 F_76 ( struct V_57 * V_58 )
{
int V_108 ;
if ( V_105 & V_36 ) {
F_38 ( L_17 ) ;
return;
}
V_105 |= V_36 ;
for ( V_108 = V_46 ; V_108 < V_109 ; V_108 ++ )
V_43 [ V_108 ] = F_77 ( V_58 , V_108 ) ;
F_35 ( NULL , V_58 ) ;
if ( F_78 () || ! V_43 [ V_44 ] ) {
V_42 = false ;
if ( ! V_43 [ V_46 ] ||
! V_43 [ V_54 ] ) {
F_38 ( L_18 ) ;
return;
}
}
V_37 = ! F_79 ( V_58 , L_19 ) ;
F_61 () ;
F_73 () ;
}
static void T_7 F_80 ( struct V_57 * V_58 )
{
struct V_57 * V_110 , * V_111 = NULL ;
void T_4 * V_112 , * V_11 ;
unsigned int V_25 ;
T_2 V_113 ;
V_105 |= V_60 ;
V_112 = F_81 ( V_58 , 0 ) ;
if ( ! V_112 ) {
F_65 ( L_20 ) ;
return;
}
V_113 = F_6 ( V_112 + V_114 ) ;
F_82 ( V_112 ) ;
F_83 (np, frame) {
int V_115 ;
if ( F_36 ( V_110 , L_21 , & V_115 ) ) {
F_65 ( L_22 ) ;
F_84 ( V_111 ) ;
F_84 ( V_110 ) ;
return;
}
if ( V_113 & F_85 ( V_115 ) ) {
F_84 ( V_111 ) ;
V_111 = V_110 ;
V_49 = true ;
break;
}
F_84 ( V_111 ) ;
V_111 = F_86 ( V_110 ) ;
}
V_11 = V_64 = F_81 ( V_111 , 0 ) ;
if ( ! V_11 ) {
F_65 ( L_23 ) ;
F_84 ( V_111 ) ;
return;
}
if ( V_49 )
V_25 = F_77 ( V_111 , 1 ) ;
else
V_25 = F_77 ( V_111 , 0 ) ;
F_84 ( V_111 ) ;
if ( ! V_25 ) {
F_65 ( L_24 ,
V_49 ? L_10 : L_11 ) ;
return;
}
F_35 ( V_11 , V_58 ) ;
F_69 ( V_11 , V_25 ) ;
F_73 () ;
}
