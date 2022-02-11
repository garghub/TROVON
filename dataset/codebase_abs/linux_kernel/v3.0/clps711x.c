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
if ( F_21 ( V_29 ) || F_22 ( V_2 ) ) {
F_1 ( V_2 ) ;
return V_27 ;
}
V_30 = V_2 -> V_33 >> 1 ;
do {
F_20 ( V_29 -> V_34 [ V_29 -> V_35 ] , F_13 ( V_2 ) ) ;
V_29 -> V_35 = ( V_29 -> V_35 + 1 ) & ( V_36 - 1 ) ;
V_2 -> V_12 . V_32 ++ ;
if ( F_21 ( V_29 ) )
break;
} while ( -- V_30 > 0 );
if ( F_23 ( V_29 ) < V_37 )
F_24 ( V_2 ) ;
if ( F_21 ( V_29 ) )
F_1 ( V_2 ) ;
return V_27 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
unsigned int V_8 = F_11 ( F_12 ( V_2 ) ) ;
return V_8 & V_38 ? 0 : V_39 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
unsigned int V_40 ;
unsigned int V_41 = 0 ;
unsigned int V_8 ;
V_40 = F_12 ( V_2 ) ;
if ( V_40 == V_42 ) {
V_8 = F_11 ( V_42 ) ;
if ( V_8 & V_43 )
V_41 |= V_44 ;
if ( V_8 & V_45 )
V_41 |= V_46 ;
if ( V_8 & V_47 )
V_41 |= V_48 ;
}
return V_41 ;
}
static void
F_27 ( struct V_1 * V_2 , unsigned int V_49 )
{
}
static void F_28 ( struct V_1 * V_2 , int V_50 )
{
unsigned long V_51 ;
unsigned int V_52 ;
F_29 ( & V_2 -> V_53 , V_51 ) ;
V_52 = F_11 ( F_30 ( V_2 ) ) ;
if ( V_50 == - 1 )
V_52 |= V_54 ;
else
V_52 &= ~ V_54 ;
F_20 ( V_52 , F_30 ( V_2 ) ) ;
F_31 ( & V_2 -> V_53 , V_51 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
unsigned int V_55 ;
int V_56 ;
F_2 ( V_2 ) = 1 ;
V_56 = F_33 ( F_4 ( V_2 ) , F_19 , 0 ,
L_1 , V_2 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_33 ( F_8 ( V_2 ) , F_10 , 0 ,
L_2 , V_2 ) ;
if ( V_56 ) {
F_34 ( F_4 ( V_2 ) , V_2 ) ;
return V_56 ;
}
V_55 = F_11 ( F_35 ( V_2 ) ) ;
V_55 |= V_57 ;
F_20 ( V_55 , F_35 ( V_2 ) ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned int V_52 , V_55 ;
F_34 ( F_4 ( V_2 ) , V_2 ) ;
F_34 ( F_8 ( V_2 ) , V_2 ) ;
V_55 = F_11 ( F_35 ( V_2 ) ) ;
V_55 &= ~ V_57 ;
F_20 ( V_55 , F_35 ( V_2 ) ) ;
V_52 = F_11 ( F_30 ( V_2 ) ) ;
V_52 &= ~ ( V_58 | V_54 ) ;
F_20 ( V_52 , F_30 ( V_2 ) ) ;
}
static void
F_37 ( struct V_1 * V_2 , struct V_59 * V_60 ,
struct V_59 * V_61 )
{
unsigned int V_52 , V_62 , V_63 ;
unsigned long V_51 ;
V_60 -> V_64 |= V_65 ;
V_62 = F_38 ( V_2 , V_60 , V_61 , 0 , V_2 -> V_66 / 16 ) ;
V_63 = F_39 ( V_2 , V_62 ) ;
switch ( V_60 -> V_64 & V_67 ) {
case V_68 :
V_52 = V_69 ;
break;
case V_70 :
V_52 = V_71 ;
break;
case V_72 :
V_52 = V_73 ;
break;
default:
V_52 = V_74 ;
break;
}
if ( V_60 -> V_64 & V_75 )
V_52 |= V_76 ;
if ( V_60 -> V_64 & V_77 ) {
V_52 |= V_78 ;
if ( ! ( V_60 -> V_64 & V_79 ) )
V_52 |= V_80 ;
}
if ( V_2 -> V_33 > 1 )
V_52 |= V_58 ;
F_29 ( & V_2 -> V_53 , V_51 ) ;
F_40 ( V_2 , V_60 -> V_64 , V_62 ) ;
V_2 -> V_22 = V_20 ;
if ( V_60 -> V_81 & V_82 )
V_2 -> V_22 |= V_16 | V_18 ;
V_2 -> V_83 = 0 ;
if ( V_60 -> V_81 & V_84 )
V_2 -> V_83 |= V_18 | V_16 ;
if ( V_60 -> V_81 & V_85 ) {
if ( V_60 -> V_81 & V_84 )
V_2 -> V_83 |= V_20 ;
}
V_63 -= 1 ;
F_20 ( V_52 | V_63 , F_30 ( V_2 ) ) ;
F_31 ( & V_2 -> V_53 , V_51 ) ;
}
static const char * F_41 ( struct V_1 * V_2 )
{
return V_2 -> type == V_86 ? L_3 : NULL ;
}
static void F_42 ( struct V_1 * V_2 , int V_51 )
{
if ( V_51 & V_87 )
V_2 -> type = V_86 ;
}
static void F_43 ( struct V_1 * V_2 )
{
}
static int F_44 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , int V_9 )
{
while ( F_11 ( F_12 ( V_2 ) ) & V_88 )
F_46 () ;
F_20 ( V_9 , F_13 ( V_2 ) ) ;
}
static void
F_47 ( struct V_89 * V_90 , const char * V_91 ,
unsigned int V_30 )
{
struct V_1 * V_2 = V_92 + V_90 -> V_93 ;
unsigned int V_8 , V_55 ;
V_55 = F_11 ( F_35 ( V_2 ) ) ;
F_20 ( V_55 | V_57 , F_35 ( V_2 ) ) ;
F_48 ( V_2 , V_91 , V_30 , F_45 ) ;
do {
V_8 = F_11 ( F_12 ( V_2 ) ) ;
} while ( V_8 & V_38 );
F_20 ( V_55 , F_35 ( V_2 ) ) ;
}
static void T_2
F_49 ( struct V_1 * V_2 , int * V_62 ,
int * V_17 , int * V_94 )
{
if ( F_11 ( F_35 ( V_2 ) ) & V_57 ) {
unsigned int V_52 , V_63 ;
V_52 = F_11 ( F_30 ( V_2 ) ) ;
* V_17 = 'n' ;
if ( V_52 & V_78 ) {
if ( V_52 & V_80 )
* V_17 = 'e' ;
else
* V_17 = 'o' ;
}
if ( ( V_52 & V_95 ) == V_73 )
* V_94 = 7 ;
else
* V_94 = 8 ;
V_63 = V_52 & V_96 ;
* V_62 = V_2 -> V_66 / ( 16 * ( V_63 + 1 ) ) ;
}
}
static int T_2 F_50 ( struct V_89 * V_90 , char * V_97 )
{
struct V_1 * V_2 ;
int V_62 = 38400 ;
int V_94 = 8 ;
int V_17 = 'n' ;
int V_98 = 'n' ;
V_2 = F_51 ( V_92 , V_99 , V_90 ) ;
if ( V_97 )
F_52 ( V_97 , & V_62 , & V_17 , & V_94 , & V_98 ) ;
else
F_49 ( V_2 , & V_62 , & V_17 , & V_94 ) ;
return F_53 ( V_2 , V_90 , V_62 , V_17 , V_94 , V_98 ) ;
}
static int T_2 F_54 ( void )
{
F_55 ( & V_100 ) ;
return 0 ;
}
static int T_2 F_56 ( void )
{
int V_101 , V_102 ;
F_57 ( V_103 L_4 ) ;
V_101 = F_58 ( & V_104 ) ;
if ( V_101 )
return V_101 ;
for ( V_102 = 0 ; V_102 < V_99 ; V_102 ++ )
F_59 ( & V_104 , & V_92 [ V_102 ] ) ;
return 0 ;
}
static void T_3 F_60 ( void )
{
int V_102 ;
for ( V_102 = 0 ; V_102 < V_99 ; V_102 ++ )
F_61 ( & V_104 , & V_92 [ V_102 ] ) ;
F_62 ( & V_104 ) ;
}
