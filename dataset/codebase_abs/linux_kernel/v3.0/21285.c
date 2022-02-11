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
static void F_8 ( struct V_1 * V_2 )
{
}
static T_1 F_9 ( int V_5 , void * V_6 )
{
struct V_1 * V_2 = V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_2 . V_8 ;
unsigned int V_10 , V_11 , V_12 , V_13 , V_14 = 256 ;
V_10 = * V_15 ;
while ( ! ( V_10 & 0x10 ) && V_14 -- ) {
V_11 = * V_16 ;
V_12 = V_17 ;
V_2 -> V_18 . V_19 ++ ;
V_13 = * V_20 | V_21 ;
if ( F_10 ( V_13 & V_22 ) ) {
if ( V_13 & V_23 )
V_2 -> V_18 . V_24 ++ ;
else if ( V_13 & V_25 )
V_2 -> V_18 . V_26 ++ ;
if ( V_13 & V_27 )
V_2 -> V_18 . V_28 ++ ;
V_13 &= V_2 -> V_29 ;
if ( V_13 & V_23 )
V_12 = V_30 ;
else if ( V_13 & V_25 )
V_12 = V_31 ;
}
F_11 ( V_2 , V_13 , V_27 , V_11 , V_12 ) ;
V_10 = * V_15 ;
}
F_12 ( V_8 ) ;
return V_32 ;
}
static T_1 F_13 ( int V_5 , void * V_6 )
{
struct V_1 * V_2 = V_6 ;
struct V_33 * V_34 = & V_2 -> V_9 -> V_34 ;
int V_35 = 256 ;
if ( V_2 -> V_36 ) {
* V_16 = V_2 -> V_36 ;
V_2 -> V_18 . V_37 ++ ;
V_2 -> V_36 = 0 ;
goto V_38;
}
if ( F_14 ( V_34 ) || F_15 ( V_2 ) ) {
F_1 ( V_2 ) ;
goto V_38;
}
do {
* V_16 = V_34 -> V_39 [ V_34 -> V_40 ] ;
V_34 -> V_40 = ( V_34 -> V_40 + 1 ) & ( V_41 - 1 ) ;
V_2 -> V_18 . V_37 ++ ;
if ( F_14 ( V_34 ) )
break;
} while ( -- V_35 > 0 && ! ( * V_15 & 0x20 ) );
if ( F_16 ( V_34 ) < V_42 )
F_17 ( V_2 ) ;
if ( F_14 ( V_34 ) )
F_1 ( V_2 ) ;
V_38:
return V_32 ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
return ( * V_15 & 8 ) ? 0 : V_43 ;
}
static unsigned int F_19 ( struct V_1 * V_2 )
{
return V_44 | V_45 | V_46 ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_47 )
{
}
static void F_21 ( struct V_1 * V_2 , int V_48 )
{
unsigned long V_49 ;
unsigned int V_50 ;
F_22 ( & V_2 -> V_51 , V_49 ) ;
V_50 = * V_52 ;
if ( V_48 )
V_50 |= V_53 ;
else
V_50 &= ~ V_53 ;
* V_52 = V_50 ;
F_23 ( & V_2 -> V_51 , V_49 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_54 ;
F_2 ( V_2 ) = 1 ;
F_7 ( V_2 ) = 1 ;
V_54 = F_25 ( V_4 , F_9 , 0 ,
V_55 , V_2 ) ;
if ( V_54 == 0 ) {
V_54 = F_25 ( V_3 , F_13 , 0 ,
V_55 , V_2 ) ;
if ( V_54 )
F_26 ( V_4 , V_2 ) ;
}
return V_54 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_3 , V_2 ) ;
F_26 ( V_4 , V_2 ) ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_56 * V_57 ,
struct V_56 * V_58 )
{
unsigned long V_49 ;
unsigned int V_59 , V_60 , V_50 , V_61 ;
V_57 -> V_62 &= ~ ( V_63 | V_64 | V_65 ) ;
V_57 -> V_62 |= V_66 ;
V_57 -> V_67 &= ~ ( V_68 | V_69 ) ;
V_59 = F_29 ( V_2 , V_57 , V_58 , 0 , V_2 -> V_70 / 16 ) ;
V_60 = F_30 ( V_2 , V_59 ) ;
V_61 = V_2 -> V_70 / ( 16 * V_60 ) ;
F_31 ( V_57 , V_61 , V_61 ) ;
switch ( V_57 -> V_62 & V_71 ) {
case V_72 :
V_50 = 0x00 ;
break;
case V_73 :
V_50 = 0x20 ;
break;
case V_74 :
V_50 = 0x40 ;
break;
default:
V_50 = 0x60 ;
break;
}
if ( V_57 -> V_62 & V_75 )
V_50 |= V_76 ;
if ( V_57 -> V_62 & V_77 ) {
V_50 |= V_78 ;
if ( ! ( V_57 -> V_62 & V_79 ) )
V_50 |= V_80 ;
}
if ( V_2 -> V_81 )
V_50 |= V_82 ;
F_22 ( & V_2 -> V_51 , V_49 ) ;
F_32 ( V_2 , V_57 -> V_62 , V_59 ) ;
V_2 -> V_29 = V_27 ;
if ( V_57 -> V_67 & V_83 )
V_2 -> V_29 |= V_25 | V_23 ;
V_2 -> V_84 = 0 ;
if ( V_57 -> V_67 & V_85 )
V_2 -> V_84 |= V_25 | V_23 ;
if ( V_57 -> V_67 & V_68 && V_57 -> V_67 & V_85 )
V_2 -> V_84 |= V_27 ;
if ( ( V_57 -> V_62 & V_86 ) == 0 )
V_2 -> V_84 |= V_21 ;
V_60 -= 1 ;
* V_87 = 0 ;
* V_88 = V_60 & 0xff ;
* V_89 = ( V_60 >> 8 ) & 0x0f ;
* V_52 = V_50 ;
* V_87 = 1 ;
F_23 ( & V_2 -> V_51 , V_49 ) ;
}
static const char * F_33 ( struct V_1 * V_2 )
{
return V_2 -> type == V_90 ? L_1 : NULL ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_91 , 32 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
return F_37 ( V_2 -> V_91 , 32 , V_55 )
!= NULL ? 0 : - V_92 ;
}
static void F_38 ( struct V_1 * V_2 , int V_49 )
{
if ( V_49 & V_93 && F_36 ( V_2 ) == 0 )
V_2 -> type = V_90 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_94 * V_95 )
{
int V_54 = 0 ;
if ( V_95 -> type != V_96 && V_95 -> type != V_90 )
V_54 = - V_97 ;
if ( V_95 -> V_5 != V_98 )
V_54 = - V_97 ;
if ( V_95 -> V_99 != V_2 -> V_70 / 16 )
V_54 = - V_97 ;
return V_54 ;
}
static void F_40 ( void )
{
V_100 . V_70 = V_101 / 4 ;
}
static void F_41 ( struct V_1 * V_2 , int V_11 )
{
while ( * V_15 & 0x20 )
F_42 () ;
* V_16 = V_11 ;
}
static void
F_43 ( struct V_102 * V_103 , const char * V_104 ,
unsigned int V_35 )
{
F_44 ( & V_100 , V_104 , V_35 , F_41 ) ;
}
static void T_2
F_45 ( struct V_1 * V_2 , int * V_59 ,
int * V_24 , int * V_105 )
{
if ( * V_87 == 1 ) {
unsigned int V_106 ;
V_106 = * V_52 ;
switch ( V_106 & 0x60 ) {
case 0x00 :
* V_105 = 5 ;
break;
case 0x20 :
* V_105 = 6 ;
break;
case 0x40 :
* V_105 = 7 ;
break;
default:
case 0x60 :
* V_105 = 8 ;
break;
}
if ( V_106 & V_78 ) {
* V_24 = 'o' ;
if ( V_106 & V_80 )
* V_24 = 'e' ;
}
V_106 = * V_88 | ( * V_89 << 8 ) ;
* V_59 = V_2 -> V_70 / ( 16 * ( V_106 + 1 ) ) ;
}
}
static int T_2 F_46 ( struct V_102 * V_103 , char * V_107 )
{
struct V_1 * V_2 = & V_100 ;
int V_59 = 9600 ;
int V_105 = 8 ;
int V_24 = 'n' ;
int V_108 = 'n' ;
if ( F_47 () )
V_59 = 57600 ;
if ( V_107 )
F_48 ( V_107 , & V_59 , & V_24 , & V_105 , & V_108 ) ;
else
F_45 ( V_2 , & V_59 , & V_24 , & V_105 ) ;
return F_49 ( V_2 , V_103 , V_59 , V_24 , V_105 , V_108 ) ;
}
static int T_2 F_50 ( void )
{
F_40 () ;
F_51 ( & V_109 ) ;
return 0 ;
}
static int T_2 F_52 ( void )
{
int V_54 ;
F_53 ( V_110 L_2 ) ;
F_40 () ;
V_54 = F_54 ( & V_111 ) ;
if ( V_54 == 0 )
F_55 ( & V_111 , & V_100 ) ;
return V_54 ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_111 , & V_100 ) ;
F_58 ( & V_111 ) ;
}
