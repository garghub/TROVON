static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
F_3 ( V_3 ) ;
F_2 ( V_2 ) = 0 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) ) {
F_5 ( V_3 ) ;
F_2 ( V_2 ) = 1 ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 ) ) {
F_3 ( V_4 ) ;
F_7 ( V_2 ) = 0 ;
}
}
static T_1 F_8 ( int V_5 , void * V_6 )
{
struct V_1 * V_2 = V_6 ;
unsigned int V_7 , V_8 , V_9 , V_10 , V_11 = 256 ;
V_7 = * V_12 ;
while ( ! ( V_7 & 0x10 ) && V_11 -- ) {
V_8 = * V_13 ;
V_9 = V_14 ;
V_2 -> V_15 . V_16 ++ ;
V_10 = * V_17 | V_18 ;
if ( F_9 ( V_10 & V_19 ) ) {
if ( V_10 & V_20 )
V_2 -> V_15 . V_21 ++ ;
else if ( V_10 & V_22 )
V_2 -> V_15 . V_23 ++ ;
if ( V_10 & V_24 )
V_2 -> V_15 . V_25 ++ ;
V_10 &= V_2 -> V_26 ;
if ( V_10 & V_20 )
V_9 = V_27 ;
else if ( V_10 & V_22 )
V_9 = V_28 ;
}
F_10 ( V_2 , V_10 , V_24 , V_8 , V_9 ) ;
V_7 = * V_12 ;
}
F_11 ( & V_2 -> V_29 -> V_2 ) ;
return V_30 ;
}
static T_1 F_12 ( int V_5 , void * V_6 )
{
struct V_1 * V_2 = V_6 ;
struct V_31 * V_32 = & V_2 -> V_29 -> V_32 ;
int V_33 = 256 ;
if ( V_2 -> V_34 ) {
* V_13 = V_2 -> V_34 ;
V_2 -> V_15 . V_35 ++ ;
V_2 -> V_34 = 0 ;
goto V_36;
}
if ( F_13 ( V_32 ) || F_14 ( V_2 ) ) {
F_1 ( V_2 ) ;
goto V_36;
}
do {
* V_13 = V_32 -> V_37 [ V_32 -> V_38 ] ;
V_32 -> V_38 = ( V_32 -> V_38 + 1 ) & ( V_39 - 1 ) ;
V_2 -> V_15 . V_35 ++ ;
if ( F_13 ( V_32 ) )
break;
} while ( -- V_33 > 0 && ! ( * V_12 & 0x20 ) );
if ( F_15 ( V_32 ) < V_40 )
F_16 ( V_2 ) ;
if ( F_13 ( V_32 ) )
F_1 ( V_2 ) ;
V_36:
return V_30 ;
}
static unsigned int F_17 ( struct V_1 * V_2 )
{
return ( * V_12 & 8 ) ? 0 : V_41 ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
return V_42 | V_43 | V_44 ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_45 )
{
}
static void F_20 ( struct V_1 * V_2 , int V_46 )
{
unsigned long V_47 ;
unsigned int V_48 ;
F_21 ( & V_2 -> V_49 , V_47 ) ;
V_48 = * V_50 ;
if ( V_46 )
V_48 |= V_51 ;
else
V_48 &= ~ V_51 ;
* V_50 = V_48 ;
F_22 ( & V_2 -> V_49 , V_47 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_52 ;
F_2 ( V_2 ) = 1 ;
F_7 ( V_2 ) = 1 ;
V_52 = F_24 ( V_4 , F_8 , 0 ,
V_53 , V_2 ) ;
if ( V_52 == 0 ) {
V_52 = F_24 ( V_3 , F_12 , 0 ,
V_53 , V_2 ) ;
if ( V_52 )
F_25 ( V_4 , V_2 ) ;
}
return V_52 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_25 ( V_3 , V_2 ) ;
F_25 ( V_4 , V_2 ) ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_54 * V_55 ,
struct V_54 * V_56 )
{
unsigned long V_47 ;
unsigned int V_57 , V_58 , V_48 , V_59 ;
V_55 -> V_60 &= ~ ( V_61 | V_62 | V_63 ) ;
V_55 -> V_60 |= V_64 ;
V_55 -> V_65 &= ~ ( V_66 | V_67 ) ;
V_57 = F_28 ( V_2 , V_55 , V_56 , 0 , V_2 -> V_68 / 16 ) ;
V_58 = F_29 ( V_2 , V_57 ) ;
V_59 = V_2 -> V_68 / ( 16 * V_58 ) ;
F_30 ( V_55 , V_59 , V_59 ) ;
switch ( V_55 -> V_60 & V_69 ) {
case V_70 :
V_48 = 0x00 ;
break;
case V_71 :
V_48 = 0x20 ;
break;
case V_72 :
V_48 = 0x40 ;
break;
default:
V_48 = 0x60 ;
break;
}
if ( V_55 -> V_60 & V_73 )
V_48 |= V_74 ;
if ( V_55 -> V_60 & V_75 ) {
V_48 |= V_76 ;
if ( ! ( V_55 -> V_60 & V_77 ) )
V_48 |= V_78 ;
}
if ( V_2 -> V_79 )
V_48 |= V_80 ;
F_21 ( & V_2 -> V_49 , V_47 ) ;
F_31 ( V_2 , V_55 -> V_60 , V_57 ) ;
V_2 -> V_26 = V_24 ;
if ( V_55 -> V_65 & V_81 )
V_2 -> V_26 |= V_22 | V_20 ;
V_2 -> V_82 = 0 ;
if ( V_55 -> V_65 & V_83 )
V_2 -> V_82 |= V_22 | V_20 ;
if ( V_55 -> V_65 & V_66 && V_55 -> V_65 & V_83 )
V_2 -> V_82 |= V_24 ;
if ( ( V_55 -> V_60 & V_84 ) == 0 )
V_2 -> V_82 |= V_18 ;
V_58 -= 1 ;
* V_85 = 0 ;
* V_86 = V_58 & 0xff ;
* V_87 = ( V_58 >> 8 ) & 0x0f ;
* V_50 = V_48 ;
* V_85 = 1 ;
F_22 ( & V_2 -> V_49 , V_47 ) ;
}
static const char * F_32 ( struct V_1 * V_2 )
{
return V_2 -> type == V_88 ? L_1 : NULL ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_89 , 32 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_2 -> V_89 , 32 , V_53 )
!= NULL ? 0 : - V_90 ;
}
static void F_37 ( struct V_1 * V_2 , int V_47 )
{
if ( V_47 & V_91 && F_35 ( V_2 ) == 0 )
V_2 -> type = V_88 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
int V_52 = 0 ;
if ( V_93 -> type != V_94 && V_93 -> type != V_88 )
V_52 = - V_95 ;
if ( V_93 -> V_5 <= 0 )
V_52 = - V_95 ;
if ( V_93 -> V_96 != V_2 -> V_68 / 16 )
V_52 = - V_95 ;
return V_52 ;
}
static void F_39 ( void )
{
V_97 . V_68 = V_98 / 4 ;
}
static void F_40 ( struct V_1 * V_2 , int V_8 )
{
while ( * V_12 & 0x20 )
F_41 () ;
* V_13 = V_8 ;
}
static void
F_42 ( struct V_99 * V_100 , const char * V_101 ,
unsigned int V_33 )
{
F_43 ( & V_97 , V_101 , V_33 , F_40 ) ;
}
static void T_2
F_44 ( struct V_1 * V_2 , int * V_57 ,
int * V_21 , int * V_102 )
{
if ( * V_85 == 1 ) {
unsigned int V_103 ;
V_103 = * V_50 ;
switch ( V_103 & 0x60 ) {
case 0x00 :
* V_102 = 5 ;
break;
case 0x20 :
* V_102 = 6 ;
break;
case 0x40 :
* V_102 = 7 ;
break;
default:
case 0x60 :
* V_102 = 8 ;
break;
}
if ( V_103 & V_76 ) {
* V_21 = 'o' ;
if ( V_103 & V_78 )
* V_21 = 'e' ;
}
V_103 = * V_86 | ( * V_87 << 8 ) ;
* V_57 = V_2 -> V_68 / ( 16 * ( V_103 + 1 ) ) ;
}
}
static int T_2 F_45 ( struct V_99 * V_100 , char * V_104 )
{
struct V_1 * V_2 = & V_97 ;
int V_57 = 9600 ;
int V_102 = 8 ;
int V_21 = 'n' ;
int V_105 = 'n' ;
if ( F_46 () )
V_57 = 57600 ;
if ( V_104 )
F_47 ( V_104 , & V_57 , & V_21 , & V_102 , & V_105 ) ;
else
F_44 ( V_2 , & V_57 , & V_21 , & V_102 ) ;
return F_48 ( V_2 , V_100 , V_57 , V_21 , V_102 , V_105 ) ;
}
static int T_2 F_49 ( void )
{
F_39 () ;
F_50 ( & V_106 ) ;
return 0 ;
}
static int T_2 F_51 ( void )
{
int V_52 ;
F_52 ( V_107 L_2 ) ;
F_39 () ;
V_52 = F_53 ( & V_108 ) ;
if ( V_52 == 0 )
F_54 ( & V_108 , & V_97 ) ;
return V_52 ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_108 , & V_97 ) ;
F_57 ( & V_108 ) ;
}
