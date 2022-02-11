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
static int F_27 ( struct V_5 * V_6 )
{
F_23 ( V_36 , V_6 ) ;
if ( V_41 )
F_28 ( V_42 [ V_43 ] , 0 ) ;
else {
F_28 ( V_42 [ V_45 ] , 0 ) ;
if ( V_42 [ V_49 ] )
F_28 ( V_42 [ V_49 ] , 0 ) ;
}
F_29 () ;
return 0 ;
}
static void
F_30 ( void T_4 * V_50 , struct V_51 * V_52 )
{
if ( V_48 )
return;
if ( F_31 ( V_52 , L_3 , & V_48 ) ) {
if ( V_50 )
V_48 = F_6 ( V_50 + V_53 ) ;
else
V_48 = F_32 () ;
}
if ( V_48 == 0 )
F_33 ( L_4 ) ;
}
static void F_34 ( unsigned type )
{
F_35 ( L_5 ,
type & V_36 ? L_6 : L_7 ,
type == ( V_36 | V_54 ) ? L_8 : L_7 ,
type & V_54 ? L_9 : L_7 ,
( unsigned long ) V_48 / 1000000 ,
( unsigned long ) ( V_48 / 10000 ) % 100 ,
type & V_36 ?
V_41 ? L_10 : L_11 :
L_7 ,
type == ( V_36 | V_54 ) ? L_12 : L_7 ,
type & V_54 ?
V_47 ? L_10 : L_11 :
L_7 ) ;
}
T_2 F_36 ( void )
{
return V_48 ;
}
static T_5 F_37 ( void )
{
T_2 V_55 , V_56 , V_57 ;
do {
V_56 = F_6 ( V_58 + V_59 ) ;
V_55 = F_6 ( V_58 + V_60 ) ;
V_57 = F_6 ( V_58 + V_59 ) ;
} while ( V_56 != V_57 );
return ( ( T_5 ) V_56 << 32 ) | V_55 ;
}
static T_6 F_38 ( struct V_61 * V_62 )
{
return F_39 () ;
}
static T_6 F_40 ( const struct V_63 * V_64 )
{
return F_39 () ;
}
struct V_65 * F_41 ( void )
{
return & V_65 ;
}
static void T_7 F_42 ( unsigned type )
{
T_5 V_66 ;
if ( type & V_36 )
F_39 = V_67 ;
else
F_39 = F_37 ;
V_66 = F_39 () ;
F_43 ( & V_68 , V_48 ) ;
V_63 . V_69 = V_68 . V_69 ;
V_63 . V_70 = V_68 . V_70 ;
F_44 ( & V_65 , & V_63 , V_66 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
F_46 ( L_13 ,
V_6 -> V_25 , F_25 () ) ;
if ( V_41 )
F_47 ( V_42 [ V_43 ] ) ;
else {
F_47 ( V_42 [ V_45 ] ) ;
if ( V_42 [ V_49 ] )
F_47 ( V_42 [ V_49 ] ) ;
}
V_6 -> V_44 ( V_30 , V_6 ) ;
}
static int F_48 ( struct V_71 * V_72 ,
unsigned long V_73 , void * V_74 )
{
switch ( V_73 & ~ V_75 ) {
case V_76 :
F_27 ( F_49 ( V_77 ) ) ;
break;
case V_78 :
F_45 ( F_49 ( V_77 ) ) ;
break;
}
return V_79 ;
}
static int T_7 F_50 ( void )
{
int V_80 ;
int V_81 ;
V_77 = F_51 ( struct V_5 ) ;
if ( ! V_77 ) {
V_80 = - V_82 ;
goto V_83;
}
if ( V_41 ) {
V_81 = V_42 [ V_43 ] ;
V_80 = F_52 ( V_81 , F_9 ,
L_14 , V_77 ) ;
} else {
V_81 = V_42 [ V_45 ] ;
V_80 = F_52 ( V_81 , F_10 ,
L_14 , V_77 ) ;
if ( ! V_80 && V_42 [ V_49 ] ) {
V_81 = V_42 [ V_49 ] ;
V_80 = F_52 ( V_81 , F_10 ,
L_14 , V_77 ) ;
if ( V_80 )
F_53 ( V_42 [ V_45 ] ,
V_77 ) ;
}
}
if ( V_80 ) {
F_54 ( L_15 ,
V_81 , V_80 ) ;
goto V_84;
}
V_80 = F_55 ( & V_85 ) ;
if ( V_80 )
goto V_86;
F_27 ( F_49 ( V_77 ) ) ;
return 0 ;
V_86:
if ( V_41 )
F_53 ( V_42 [ V_43 ] , V_77 ) ;
else {
F_53 ( V_42 [ V_45 ] ,
V_77 ) ;
if ( V_42 [ V_49 ] )
F_53 ( V_42 [ V_49 ] ,
V_77 ) ;
}
V_84:
F_56 ( V_77 ) ;
V_83:
return V_80 ;
}
static int T_7 F_57 ( void T_4 * V_11 , unsigned int V_25 )
{
int V_87 ;
T_8 V_88 ;
struct V_8 * V_89 ;
V_89 = F_58 ( sizeof( * V_89 ) , V_90 ) ;
if ( ! V_89 )
return - V_82 ;
V_89 -> V_11 = V_11 ;
V_89 -> V_18 . V_25 = V_25 ;
F_23 ( V_54 , & V_89 -> V_18 ) ;
if ( V_47 )
V_88 = F_12 ;
else
V_88 = F_11 ;
V_87 = F_59 ( V_25 , V_88 , V_91 , L_2 , & V_89 -> V_18 ) ;
if ( V_87 ) {
F_54 ( L_16 ) ;
F_60 ( V_89 ) ;
}
return V_87 ;
}
static void T_7 F_61 ( void )
{
unsigned V_92 = V_36 | V_54 ;
if ( ( V_93 & V_92 ) != V_92 ) {
if ( F_62 ( NULL , V_94 ) &&
! ( V_93 & V_54 ) )
return;
if ( F_62 ( NULL , V_95 ) &&
! ( V_93 & V_36 ) )
return;
}
F_34 ( V_93 ) ;
F_42 ( V_93 ) ;
F_63 () ;
}
static void T_7 F_64 ( struct V_51 * V_52 )
{
int V_96 ;
if ( V_93 & V_36 ) {
F_33 ( L_17 ) ;
return;
}
V_93 |= V_36 ;
for ( V_96 = V_45 ; V_96 < V_97 ; V_96 ++ )
V_42 [ V_96 ] = F_65 ( V_52 , V_96 ) ;
F_30 ( NULL , V_52 ) ;
if ( F_66 () || ! V_42 [ V_43 ] ) {
V_41 = false ;
if ( ! V_42 [ V_45 ] ||
! V_42 [ V_49 ] ) {
F_33 ( L_18 ) ;
return;
}
}
F_50 () ;
F_61 () ;
}
static void T_7 F_67 ( struct V_51 * V_52 )
{
struct V_51 * V_98 , * V_99 = NULL ;
void T_4 * V_100 , * V_11 ;
unsigned int V_25 ;
T_2 V_101 ;
V_93 |= V_54 ;
V_100 = F_68 ( V_52 , 0 ) ;
if ( ! V_100 ) {
F_54 ( L_19 ) ;
return;
}
V_101 = F_6 ( V_100 + V_102 ) ;
F_69 ( V_100 ) ;
F_70 (np, frame) {
int V_103 ;
if ( F_31 ( V_98 , L_20 , & V_103 ) ) {
F_54 ( L_21 ) ;
F_71 ( V_99 ) ;
F_71 ( V_98 ) ;
return;
}
if ( V_101 & F_72 ( V_103 ) ) {
F_71 ( V_99 ) ;
V_99 = V_98 ;
V_47 = true ;
break;
}
F_71 ( V_99 ) ;
V_99 = F_73 ( V_98 ) ;
}
V_11 = V_58 = F_68 ( V_99 , 0 ) ;
if ( ! V_11 ) {
F_54 ( L_22 ) ;
F_71 ( V_99 ) ;
return;
}
if ( V_47 )
V_25 = F_65 ( V_99 , 1 ) ;
else
V_25 = F_65 ( V_99 , 0 ) ;
F_71 ( V_99 ) ;
if ( ! V_25 ) {
F_54 ( L_23 ,
V_47 ? L_10 : L_11 ) ;
return;
}
F_30 ( V_11 , V_52 ) ;
F_57 ( V_11 , V_25 ) ;
F_61 () ;
}
