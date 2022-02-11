static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_3 ( F_4 ( V_2 ) ) ;
F_2 ( V_2 ) = 0 ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) ) {
F_6 ( F_4 ( V_2 ) ) ;
F_2 ( V_2 ) = 1 ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( F_8 ( V_2 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static T_1 F_10 ( int V_3 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_2 . V_6 ;
unsigned int V_8 , V_9 , V_10 ;
V_8 = F_11 ( F_12 ( V_2 ) ) ;
while ( ! ( V_8 & V_11 ) ) {
V_9 = F_11 ( F_13 ( V_2 ) ) ;
V_2 -> V_12 . V_13 ++ ;
V_10 = V_14 ;
if ( F_14 ( V_9 & V_15 ) ) {
if ( V_9 & V_16 )
V_2 -> V_12 . V_17 ++ ;
else if ( V_9 & V_18 )
V_2 -> V_12 . V_19 ++ ;
if ( V_9 & V_20 )
V_2 -> V_12 . V_21 ++ ;
V_9 &= V_2 -> V_22 ;
if ( V_9 & V_16 )
V_10 = V_23 ;
else if ( V_9 & V_18 )
V_10 = V_24 ;
#ifdef F_15
V_2 -> V_25 = 0 ;
#endif
}
if ( F_16 ( V_2 , V_9 ) )
goto V_26;
F_17 ( V_2 , V_9 , V_20 , V_9 , V_10 ) ;
V_26:
V_8 = F_11 ( F_12 ( V_2 ) ) ;
}
F_18 ( V_6 ) ;
return V_27 ;
}
static T_1 F_19 ( int V_3 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
struct V_28 * V_29 = & V_2 -> V_7 -> V_29 ;
int V_30 ;
if ( V_2 -> V_31 ) {
F_20 ( V_2 -> V_31 , F_13 ( V_2 ) ) ;
V_2 -> V_12 . V_32 ++ ;
V_2 -> V_31 = 0 ;
return V_27 ;
}
if ( F_21 ( V_29 ) || F_22 ( V_2 ) )
goto V_33;
V_30 = V_2 -> V_34 >> 1 ;
do {
F_20 ( V_29 -> V_35 [ V_29 -> V_36 ] , F_13 ( V_2 ) ) ;
V_29 -> V_36 = ( V_29 -> V_36 + 1 ) & ( V_37 - 1 ) ;
V_2 -> V_12 . V_32 ++ ;
if ( F_21 ( V_29 ) )
break;
} while ( -- V_30 > 0 );
if ( F_23 ( V_29 ) < V_38 )
F_24 ( V_2 ) ;
if ( F_21 ( V_29 ) ) {
V_33:
F_25 ( F_4 ( V_2 ) ) ;
F_2 ( V_2 ) = 0 ;
}
return V_27 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
unsigned int V_8 = F_11 ( F_12 ( V_2 ) ) ;
return V_8 & V_39 ? 0 : V_40 ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
unsigned int V_41 ;
unsigned int V_42 = 0 ;
unsigned int V_8 ;
V_41 = F_12 ( V_2 ) ;
if ( V_41 == V_43 ) {
V_8 = F_11 ( V_43 ) ;
if ( V_8 & V_44 )
V_42 |= V_45 ;
if ( V_8 & V_46 )
V_42 |= V_47 ;
if ( V_8 & V_48 )
V_42 |= V_49 ;
}
return V_42 ;
}
static void
F_28 ( struct V_1 * V_2 , unsigned int V_50 )
{
}
static void F_29 ( struct V_1 * V_2 , int V_51 )
{
unsigned long V_52 ;
unsigned int V_53 ;
F_30 ( & V_2 -> V_54 , V_52 ) ;
V_53 = F_11 ( F_31 ( V_2 ) ) ;
if ( V_51 == - 1 )
V_53 |= V_55 ;
else
V_53 &= ~ V_55 ;
F_20 ( V_53 , F_31 ( V_2 ) ) ;
F_32 ( & V_2 -> V_54 , V_52 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
unsigned int V_56 ;
int V_57 ;
F_2 ( V_2 ) = 1 ;
V_57 = F_34 ( F_4 ( V_2 ) , F_19 , 0 ,
L_1 , V_2 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_34 ( F_8 ( V_2 ) , F_10 , 0 ,
L_2 , V_2 ) ;
if ( V_57 ) {
F_35 ( F_4 ( V_2 ) , V_2 ) ;
return V_57 ;
}
V_56 = F_11 ( F_36 ( V_2 ) ) ;
V_56 |= V_58 ;
F_20 ( V_56 , F_36 ( V_2 ) ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned int V_53 , V_56 ;
F_35 ( F_4 ( V_2 ) , V_2 ) ;
F_35 ( F_8 ( V_2 ) , V_2 ) ;
V_56 = F_11 ( F_36 ( V_2 ) ) ;
V_56 &= ~ V_58 ;
F_20 ( V_56 , F_36 ( V_2 ) ) ;
V_53 = F_11 ( F_31 ( V_2 ) ) ;
V_53 &= ~ ( V_59 | V_55 ) ;
F_20 ( V_53 , F_31 ( V_2 ) ) ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_60 * V_61 ,
struct V_60 * V_62 )
{
unsigned int V_53 , V_63 , V_64 ;
unsigned long V_52 ;
V_61 -> V_65 |= V_66 ;
V_63 = F_39 ( V_2 , V_61 , V_62 , 0 , V_2 -> V_67 / 16 ) ;
V_64 = F_40 ( V_2 , V_63 ) ;
switch ( V_61 -> V_65 & V_68 ) {
case V_69 :
V_53 = V_70 ;
break;
case V_71 :
V_53 = V_72 ;
break;
case V_73 :
V_53 = V_74 ;
break;
default:
V_53 = V_75 ;
break;
}
if ( V_61 -> V_65 & V_76 )
V_53 |= V_77 ;
if ( V_61 -> V_65 & V_78 ) {
V_53 |= V_79 ;
if ( ! ( V_61 -> V_65 & V_80 ) )
V_53 |= V_81 ;
}
if ( V_2 -> V_34 > 1 )
V_53 |= V_59 ;
F_30 ( & V_2 -> V_54 , V_52 ) ;
F_41 ( V_2 , V_61 -> V_65 , V_63 ) ;
V_2 -> V_22 = V_20 ;
if ( V_61 -> V_82 & V_83 )
V_2 -> V_22 |= V_16 | V_18 ;
V_2 -> V_84 = 0 ;
if ( V_61 -> V_82 & V_85 )
V_2 -> V_84 |= V_18 | V_16 ;
if ( V_61 -> V_82 & V_86 ) {
if ( V_61 -> V_82 & V_85 )
V_2 -> V_84 |= V_20 ;
}
V_64 -= 1 ;
F_20 ( V_53 | V_64 , F_31 ( V_2 ) ) ;
F_32 ( & V_2 -> V_54 , V_52 ) ;
}
static const char * F_42 ( struct V_1 * V_2 )
{
return V_2 -> type == V_87 ? L_3 : NULL ;
}
static void F_43 ( struct V_1 * V_2 , int V_52 )
{
if ( V_52 & V_88 )
V_2 -> type = V_87 ;
}
static void F_44 ( struct V_1 * V_2 )
{
}
static int F_45 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_9 )
{
while ( F_11 ( F_12 ( V_2 ) ) & V_89 )
F_47 () ;
F_20 ( V_9 , F_13 ( V_2 ) ) ;
}
static void
F_48 ( struct V_90 * V_91 , const char * V_92 ,
unsigned int V_30 )
{
struct V_1 * V_2 = V_93 + V_91 -> V_94 ;
unsigned int V_8 , V_56 ;
V_56 = F_11 ( F_36 ( V_2 ) ) ;
F_20 ( V_56 | V_58 , F_36 ( V_2 ) ) ;
F_49 ( V_2 , V_92 , V_30 , F_46 ) ;
do {
V_8 = F_11 ( F_12 ( V_2 ) ) ;
} while ( V_8 & V_39 );
F_20 ( V_56 , F_36 ( V_2 ) ) ;
}
static void T_2
F_50 ( struct V_1 * V_2 , int * V_63 ,
int * V_17 , int * V_95 )
{
if ( F_11 ( F_36 ( V_2 ) ) & V_58 ) {
unsigned int V_53 , V_64 ;
V_53 = F_11 ( F_31 ( V_2 ) ) ;
* V_17 = 'n' ;
if ( V_53 & V_79 ) {
if ( V_53 & V_81 )
* V_17 = 'e' ;
else
* V_17 = 'o' ;
}
if ( ( V_53 & V_96 ) == V_74 )
* V_95 = 7 ;
else
* V_95 = 8 ;
V_64 = V_53 & V_97 ;
* V_63 = V_2 -> V_67 / ( 16 * ( V_64 + 1 ) ) ;
}
}
static int T_2 F_51 ( struct V_90 * V_91 , char * V_98 )
{
struct V_1 * V_2 ;
int V_63 = 38400 ;
int V_95 = 8 ;
int V_17 = 'n' ;
int V_99 = 'n' ;
V_2 = F_52 ( V_93 , V_100 , V_91 ) ;
if ( V_98 )
F_53 ( V_98 , & V_63 , & V_17 , & V_95 , & V_99 ) ;
else
F_50 ( V_2 , & V_63 , & V_17 , & V_95 ) ;
return F_54 ( V_2 , V_91 , V_63 , V_17 , V_95 , V_99 ) ;
}
static int T_2 F_55 ( void )
{
F_56 ( & V_101 ) ;
return 0 ;
}
static int T_2 F_57 ( void )
{
int V_102 , V_103 ;
F_58 ( V_104 L_4 ) ;
V_102 = F_59 ( & V_105 ) ;
if ( V_102 )
return V_102 ;
for ( V_103 = 0 ; V_103 < V_100 ; V_103 ++ )
F_60 ( & V_105 , & V_93 [ V_103 ] ) ;
return 0 ;
}
static void T_3 F_61 ( void )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_100 ; V_103 ++ )
F_62 ( & V_105 , & V_93 [ V_103 ] ) ;
F_63 ( & V_105 ) ;
}
