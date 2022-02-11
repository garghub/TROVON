int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
static void F_6 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
V_2 -> V_7 . V_8 [ V_9 ] = ( ( F_7 () & V_10 ) |
( ( V_2 -> V_11 >> 2 ) << V_12 ) |
( V_2 -> V_11 & 3 ) ) ;
}
static bool F_8 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
if ( V_14 -> V_15 )
return F_9 ( V_2 , V_14 ) ;
* F_10 ( V_2 , V_14 -> V_16 ) = V_2 -> V_7 . V_8 [ V_17 ] ;
return true ;
}
static bool F_11 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
return F_13 ( V_2 , V_14 ) ;
}
static bool F_14 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
if ( V_14 -> V_15 )
return F_9 ( V_2 , V_14 ) ;
* F_10 ( V_2 , V_14 -> V_16 ) = V_2 -> V_7 . V_8 [ V_18 ] ;
return true ;
}
static void F_15 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
T_1 V_19 , V_20 ;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
V_19 &= ~ ( 3 << 24 ) ;
V_20 = F_16 ( & V_2 -> V_21 -> V_22 ) - 1 ;
V_20 -= ( V_2 -> V_11 & ~ 3 ) ;
V_20 = F_17 ( V_20 , 3U ) ;
V_19 |= ( V_20 & 3 ) << 24 ;
V_2 -> V_7 . V_8 [ V_18 ] = V_19 ;
}
static void F_18 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
T_1 V_23 ;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if ( F_16 ( & V_2 -> V_21 -> V_22 ) > 1 )
V_23 |= 1U << 6 ;
else
V_23 &= ~ ( 1U << 6 ) ;
V_2 -> V_7 . V_8 [ V_17 ] = V_23 ;
}
static bool F_19 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
if ( V_14 -> V_15 )
return F_9 ( V_2 , V_14 ) ;
* F_10 ( V_2 , V_14 -> V_16 ) = 0 ;
return true ;
}
static bool F_20 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
unsigned long V_24 ;
int V_25 ;
if ( ! V_14 -> V_15 )
return F_21 ( V_2 , V_14 ) ;
V_25 = F_22 () ;
F_23 ( & V_2 -> V_7 . V_26 ) ;
F_24 ( V_25 , & V_2 -> V_7 . V_26 ) ;
if ( V_25 != V_2 -> V_7 . V_27 ) {
F_25 () ;
goto V_28;
}
V_24 = * F_10 ( V_2 , V_14 -> V_16 ) ;
switch ( V_14 -> V_29 ) {
case 6 :
case 14 :
asm volatile("mcr p15, 0, %0, c7, c14, 2" : : "r" (val));
break;
case 10 :
asm volatile("mcr p15, 0, %0, c7, c10, 2" : : "r" (val));
break;
}
V_28:
F_26 () ;
return true ;
}
static bool F_27 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
if ( V_14 -> V_15 )
return F_9 ( V_2 , V_14 ) ;
else
return F_13 ( V_2 , V_14 ) ;
}
void F_28 ( struct V_30 * V_31 )
{
unsigned int V_32 ;
for ( V_32 = 1 ; V_32 < V_31 -> V_33 ; V_32 ++ )
F_29 ( F_30 ( & V_31 -> V_31 [ V_32 - 1 ] ,
& V_31 -> V_31 [ V_32 ] ) >= 0 ) ;
V_34 [ V_31 -> V_35 ] = V_31 ;
}
static const struct V_5 * F_31 ( unsigned V_35 , T_2 * V_33 )
{
struct V_30 * V_31 ;
V_31 = V_34 [ V_35 ] ;
* V_33 = V_31 -> V_33 ;
return V_31 -> V_31 ;
}
static const struct V_5 * F_32 ( const struct V_13 * V_36 ,
const struct V_5 V_31 [] ,
unsigned int V_33 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
const struct V_5 * V_6 = & V_31 [ V_32 ] ;
if ( V_36 -> V_37 != V_6 -> V_38 )
continue;
if ( V_36 -> V_39 != V_6 -> V_39 )
continue;
if ( V_36 -> V_29 != V_6 -> V_29 )
continue;
if ( V_36 -> V_40 != V_6 -> V_40 )
continue;
if ( V_36 -> V_41 != V_6 -> V_41 )
continue;
return V_6 ;
}
return NULL ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_13 * V_36 )
{
T_2 V_33 ;
const struct V_5 * V_31 , * V_6 ;
F_34 ( V_36 -> V_40 , V_36 -> V_16 , V_36 -> V_39 ,
V_36 -> V_29 , V_36 -> V_41 , V_36 -> V_15 ) ;
V_31 = F_31 ( V_2 -> V_7 . V_35 , & V_33 ) ;
V_6 = F_32 ( V_36 , V_31 , V_33 ) ;
if ( ! V_6 )
V_6 = F_32 ( V_36 , V_42 , F_35 ( V_42 ) ) ;
if ( F_36 ( V_6 ) ) {
F_29 ( ! V_6 -> V_43 ) ;
if ( F_36 ( V_6 -> V_43 ( V_2 , V_36 , V_6 ) ) ) {
F_37 ( V_2 , F_38 ( V_2 ) ) ;
return 1 ;
}
} else {
F_39 ( L_1 ,
* F_40 ( V_2 ) ) ;
F_41 ( V_36 ) ;
}
F_2 ( V_2 ) ;
return 1 ;
}
int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_13 V_36 ;
V_36 . V_29 = ( F_43 ( V_2 ) >> 1 ) & 0xf ;
V_36 . V_16 = ( F_43 ( V_2 ) >> 5 ) & 0xf ;
V_36 . V_15 = ( ( F_43 ( V_2 ) & 1 ) == 0 ) ;
V_36 . V_37 = true ;
V_36 . V_40 = ( F_43 ( V_2 ) >> 16 ) & 0xf ;
V_36 . V_41 = 0 ;
V_36 . V_44 = ( F_43 ( V_2 ) >> 10 ) & 0xf ;
V_36 . V_39 = 0 ;
return F_33 ( V_2 , & V_36 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
const struct V_5 * V_31 , T_2 V_33 )
{
unsigned long V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
if ( V_31 [ V_32 ] . V_45 )
V_31 [ V_32 ] . V_45 ( V_2 , & V_31 [ V_32 ] ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_13 V_36 ;
V_36 . V_29 = ( F_43 ( V_2 ) >> 1 ) & 0xf ;
V_36 . V_16 = ( F_43 ( V_2 ) >> 5 ) & 0xf ;
V_36 . V_15 = ( ( F_43 ( V_2 ) & 1 ) == 0 ) ;
V_36 . V_37 = false ;
V_36 . V_39 = ( F_43 ( V_2 ) >> 10 ) & 0xf ;
V_36 . V_40 = ( F_43 ( V_2 ) >> 14 ) & 0x7 ;
V_36 . V_41 = ( F_43 ( V_2 ) >> 17 ) & 0x7 ;
V_36 . V_44 = 0 ;
return F_33 ( V_2 , & V_36 ) ;
}
static bool F_46 ( T_3 V_46 , struct V_13 * V_36 )
{
switch ( V_46 & V_47 ) {
case V_48 :
if ( V_46 & ~ ( V_49 | V_47
| V_50
| V_51
| V_52
| V_53
| V_54 ) )
return false ;
V_36 -> V_37 = false ;
V_36 -> V_39 = ( ( V_46 & V_51 )
>> V_55 ) ;
V_36 -> V_29 = ( ( V_46 & V_52 )
>> V_56 ) ;
V_36 -> V_40 = ( ( V_46 & V_53 )
>> V_57 ) ;
V_36 -> V_41 = ( ( V_46 & V_54 )
>> V_58 ) ;
return true ;
case V_59 :
if ( V_46 & ~ ( V_49 | V_47
| V_50
| V_52
| V_53 ) )
return false ;
V_36 -> V_37 = true ;
V_36 -> V_39 = ( ( V_46 & V_52 )
>> V_56 ) ;
V_36 -> V_40 = ( ( V_46 & V_53 )
>> V_57 ) ;
V_36 -> V_41 = 0 ;
V_36 -> V_29 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_5 * F_47 ( struct V_1 * V_2 ,
T_3 V_46 )
{
T_2 V_33 ;
const struct V_5 * V_31 , * V_6 ;
struct V_13 V_36 ;
if ( ( V_46 & V_50 ) >> V_60 != 15 )
return NULL ;
if ( ! F_46 ( V_46 , & V_36 ) )
return NULL ;
V_31 = F_31 ( V_2 -> V_7 . V_35 , & V_33 ) ;
V_6 = F_32 ( & V_36 , V_31 , V_33 ) ;
if ( ! V_6 )
V_6 = F_32 ( & V_36 , V_42 , F_35 ( V_42 ) ) ;
if ( V_6 && ! V_6 -> V_61 )
V_6 = NULL ;
return V_6 ;
}
static int F_48 ( void * V_24 , const void T_4 * V_62 , T_3 V_46 )
{
if ( F_49 ( V_24 , V_62 , F_50 ( V_46 ) ) != 0 )
return - V_63 ;
return 0 ;
}
static int F_51 ( void T_4 * V_62 , const void * V_24 , T_3 V_46 )
{
if ( F_52 ( V_62 , V_24 , F_50 ( V_46 ) ) != 0 )
return - V_63 ;
return 0 ;
}
static int F_53 ( T_3 V_46 , void T_4 * V_62 )
{
struct V_13 V_36 ;
const struct V_5 * V_6 ;
if ( ! F_46 ( V_46 , & V_36 ) )
return - V_64 ;
V_6 = F_32 ( & V_36 , V_65 , F_35 ( V_65 ) ) ;
if ( ! V_6 )
return - V_64 ;
return F_51 ( V_62 , & V_6 -> V_24 , V_46 ) ;
}
static int F_54 ( T_3 V_46 , void T_4 * V_62 )
{
struct V_13 V_36 ;
const struct V_5 * V_6 ;
int V_66 ;
T_3 V_24 = 0 ;
if ( ! F_46 ( V_46 , & V_36 ) )
return - V_64 ;
V_6 = F_32 ( & V_36 , V_65 , F_35 ( V_65 ) ) ;
if ( ! V_6 )
return - V_64 ;
V_66 = F_48 ( & V_24 , V_62 , V_46 ) ;
if ( V_66 )
return V_66 ;
if ( V_6 -> V_24 != V_24 )
return - V_67 ;
return 0 ;
}
static bool F_55 ( T_1 V_24 )
{
T_1 V_68 , V_69 ;
if ( V_24 >= V_70 )
return - V_64 ;
V_68 = ( V_24 >> 1 ) ;
V_69 = ( V_71 >> ( V_68 * 3 ) ) & 7 ;
switch ( V_69 ) {
case 0 :
return false ;
case 1 :
return ( V_24 & 1 ) ;
case 2 :
case 4 :
return ! ( V_24 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static T_1 F_56 ( T_1 V_72 )
{
T_1 V_73 ;
F_57 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_58 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_59 () ;
return V_73 ;
}
static int F_60 ( T_3 V_46 , void T_4 * V_62 )
{
T_1 V_24 ;
T_1 T_4 * V_74 = V_62 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
switch ( V_46 & V_75 ) {
case V_76 :
if ( F_50 ( V_46 ) != 4 )
return - V_64 ;
V_24 = ( V_46 & V_77 )
>> V_78 ;
if ( ! F_55 ( V_24 ) )
return - V_64 ;
return F_61 ( F_56 ( V_24 ) , V_74 ) ;
default:
return - V_64 ;
}
}
static int F_62 ( T_3 V_46 , void T_4 * V_62 )
{
T_1 V_24 , V_79 ;
T_1 T_4 * V_74 = V_62 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
switch ( V_46 & V_75 ) {
case V_76 :
if ( F_50 ( V_46 ) != 4 )
return - V_64 ;
V_24 = ( V_46 & V_77 )
>> V_78 ;
if ( ! F_55 ( V_24 ) )
return - V_64 ;
if ( F_63 ( V_79 , V_74 ) )
return - V_63 ;
if ( V_79 != F_56 ( V_24 ) )
return - V_67 ;
return 0 ;
default:
return - V_64 ;
}
}
static unsigned int F_64 ( void )
{
if ( ( ( F_65 ( V_80 ) & V_81 ) >> V_82 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_66 ( void )
{
return F_64 () + F_35 ( V_83 ) ;
}
static int F_67 ( T_3 T_4 * V_84 )
{
unsigned int V_32 ;
const T_3 V_85 = V_86 | V_48 | V_87 ;
const T_3 V_88 = V_86 | V_59 | V_87 ;
for ( V_32 = 0 ; V_32 < F_64 () ; V_32 ++ ) {
if ( F_61 ( ( V_88 | V_89 ) + V_32 ,
V_84 ) )
return - V_63 ;
V_84 ++ ;
}
for ( V_32 = 0 ; V_32 < F_35 ( V_83 ) ; V_32 ++ ) {
if ( F_61 ( V_85 | V_83 [ V_32 ] , V_84 ) )
return - V_63 ;
V_84 ++ ;
}
return F_66 () ;
}
static int F_68 ( const struct V_1 * V_2 , T_3 V_46 , void T_4 * V_62 )
{
T_1 V_90 = ( V_46 & V_91 ) ;
T_1 V_24 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
if ( V_90 < F_64 () ) {
if ( F_50 ( V_46 ) != 8 )
return - V_64 ;
return F_51 ( V_62 , & V_2 -> V_7 . V_92 . V_93 [ V_90 ] ,
V_46 ) ;
}
if ( F_50 ( V_46 ) != 4 )
return - V_64 ;
switch ( V_90 ) {
case V_94 :
return F_51 ( V_62 , & V_2 -> V_7 . V_92 . V_95 , V_46 ) ;
case V_96 :
return F_51 ( V_62 , & V_2 -> V_7 . V_92 . V_97 , V_46 ) ;
case V_98 :
return F_51 ( V_62 , & V_2 -> V_7 . V_92 . V_99 , V_46 ) ;
case V_100 :
return F_51 ( V_62 , & V_2 -> V_7 . V_92 . V_101 , V_46 ) ;
case V_102 :
V_24 = F_65 ( V_80 ) ;
return F_51 ( V_62 , & V_24 , V_46 ) ;
case V_103 :
V_24 = F_65 ( V_104 ) ;
return F_51 ( V_62 , & V_24 , V_46 ) ;
case V_105 :
V_24 = F_65 ( V_106 ) ;
return F_51 ( V_62 , & V_24 , V_46 ) ;
default:
return - V_64 ;
}
}
static int F_69 ( struct V_1 * V_2 , T_3 V_46 , const void T_4 * V_62 )
{
T_1 V_90 = ( V_46 & V_91 ) ;
T_1 V_24 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
if ( V_90 < F_64 () ) {
if ( F_50 ( V_46 ) != 8 )
return - V_64 ;
return F_48 ( & V_2 -> V_7 . V_92 . V_93 [ V_90 ] ,
V_62 , V_46 ) ;
}
if ( F_50 ( V_46 ) != 4 )
return - V_64 ;
switch ( V_90 ) {
case V_94 :
return F_48 ( & V_2 -> V_7 . V_92 . V_95 , V_62 , V_46 ) ;
case V_96 :
return F_48 ( & V_2 -> V_7 . V_92 . V_97 , V_62 , V_46 ) ;
case V_98 :
return F_48 ( & V_2 -> V_7 . V_92 . V_99 , V_62 , V_46 ) ;
case V_100 :
return F_48 ( & V_2 -> V_7 . V_92 . V_101 , V_62 , V_46 ) ;
case V_102 :
if ( F_48 ( & V_24 , V_62 , V_46 ) )
return - V_63 ;
if ( V_24 != F_65 ( V_80 ) )
return - V_67 ;
return 0 ;
case V_103 :
if ( F_48 ( & V_24 , V_62 , V_46 ) )
return - V_63 ;
if ( V_24 != F_65 ( V_104 ) )
return - V_67 ;
return 0 ;
case V_105 :
if ( F_48 ( & V_24 , V_62 , V_46 ) )
return - V_63 ;
if ( V_24 != F_65 ( V_106 ) )
return - V_67 ;
return 0 ;
default:
return - V_64 ;
}
}
static unsigned int F_66 ( void )
{
return 0 ;
}
static int F_67 ( T_3 T_4 * V_84 )
{
return 0 ;
}
static int F_68 ( const struct V_1 * V_2 , T_3 V_46 , void T_4 * V_62 )
{
return - V_64 ;
}
static int F_69 ( struct V_1 * V_2 , T_3 V_46 , const void T_4 * V_62 )
{
return - V_64 ;
}
int F_70 ( struct V_1 * V_2 , const struct V_107 * V_61 )
{
const struct V_5 * V_6 ;
void T_4 * V_62 = ( void T_4 * ) ( long ) V_61 -> V_108 ;
if ( ( V_61 -> V_46 & V_50 ) == V_109 )
return F_60 ( V_61 -> V_46 , V_62 ) ;
if ( ( V_61 -> V_46 & V_50 ) == V_87 )
return F_68 ( V_2 , V_61 -> V_46 , V_62 ) ;
V_6 = F_47 ( V_2 , V_61 -> V_46 ) ;
if ( ! V_6 )
return F_53 ( V_61 -> V_46 , V_62 ) ;
return F_51 ( V_62 , & V_2 -> V_7 . V_8 [ V_6 -> V_61 ] , V_61 -> V_46 ) ;
}
int F_71 ( struct V_1 * V_2 , const struct V_107 * V_61 )
{
const struct V_5 * V_6 ;
void T_4 * V_62 = ( void T_4 * ) ( long ) V_61 -> V_108 ;
if ( ( V_61 -> V_46 & V_50 ) == V_109 )
return F_62 ( V_61 -> V_46 , V_62 ) ;
if ( ( V_61 -> V_46 & V_50 ) == V_87 )
return F_69 ( V_2 , V_61 -> V_46 , V_62 ) ;
V_6 = F_47 ( V_2 , V_61 -> V_46 ) ;
if ( ! V_6 )
return F_54 ( V_61 -> V_46 , V_62 ) ;
return F_48 ( & V_2 -> V_7 . V_8 [ V_6 -> V_61 ] , V_62 , V_61 -> V_46 ) ;
}
static unsigned int F_72 ( void )
{
unsigned int V_32 , V_110 = 0 ;
for ( V_32 = 0 ; V_32 < V_70 ; V_32 ++ )
if ( F_55 ( V_32 ) )
V_110 ++ ;
return V_110 ;
}
static int F_73 ( T_3 T_4 * V_84 )
{
T_3 V_24 = V_86 | V_48 | V_109 ;
unsigned int V_32 ;
V_24 |= V_76 ;
for ( V_32 = 0 ; V_32 < V_70 ; V_32 ++ ) {
if ( ! F_55 ( V_32 ) )
continue;
if ( F_61 ( V_24 | V_32 , V_84 ) )
return - V_63 ;
V_84 ++ ;
}
return 0 ;
}
static T_3 F_74 ( const struct V_5 * V_61 )
{
T_3 V_24 = V_86 | ( 15 << V_60 ) ;
if ( V_61 -> V_38 ) {
V_24 |= V_59 ;
V_24 |= ( V_61 -> V_40 << V_57 ) ;
V_24 |= ( V_61 -> V_39 << V_56 ) ;
} else {
V_24 |= V_48 ;
V_24 |= ( V_61 -> V_40 << V_57 ) ;
V_24 |= ( V_61 -> V_41 << V_58 ) ;
V_24 |= ( V_61 -> V_29 << V_56 ) ;
V_24 |= ( V_61 -> V_39 << V_55 ) ;
}
return V_24 ;
}
static bool F_75 ( const struct V_5 * V_61 , T_3 T_4 * * V_111 )
{
if ( ! * V_111 )
return true ;
if ( F_61 ( F_74 ( V_61 ) , * V_111 ) )
return false ;
( * V_111 ) ++ ;
return true ;
}
static int F_76 ( struct V_1 * V_2 , T_3 T_4 * V_111 )
{
const struct V_5 * V_112 , * V_113 , * V_114 , * V_115 ;
unsigned int V_116 = 0 ;
T_2 V_33 ;
V_112 = F_31 ( V_2 -> V_7 . V_35 , & V_33 ) ;
V_114 = V_112 + V_33 ;
V_113 = V_42 ;
V_115 = V_42 + F_35 ( V_42 ) ;
F_29 ( V_112 == V_114 || V_113 == V_115 ) ;
while ( V_112 || V_113 ) {
int V_117 = F_30 ( V_112 , V_113 ) ;
if ( V_117 <= 0 ) {
if ( V_112 -> V_61 ) {
if ( ! F_75 ( V_112 , & V_111 ) )
return - V_63 ;
V_116 ++ ;
}
} else {
if ( V_113 -> V_61 ) {
if ( ! F_75 ( V_113 , & V_111 ) )
return - V_63 ;
V_116 ++ ;
}
}
if ( V_117 <= 0 && ++ V_112 == V_114 )
V_112 = NULL ;
if ( V_117 >= 0 && ++ V_113 == V_115 )
V_113 = NULL ;
}
return V_116 ;
}
unsigned long F_77 ( struct V_1 * V_2 )
{
return F_35 ( V_65 )
+ F_72 ()
+ F_66 ()
+ F_76 ( V_2 , ( T_3 T_4 * ) NULL ) ;
}
int F_78 ( struct V_1 * V_2 , T_3 T_4 * V_84 )
{
unsigned int V_32 ;
int V_66 ;
for ( V_32 = 0 ; V_32 < F_35 ( V_65 ) ; V_32 ++ ) {
if ( F_61 ( F_74 ( & V_65 [ V_32 ] ) , V_84 ) )
return - V_63 ;
V_84 ++ ;
}
V_66 = F_76 ( V_2 , V_84 ) ;
if ( V_66 < 0 )
return V_66 ;
V_84 += V_66 ;
V_66 = F_67 ( V_84 ) ;
if ( V_66 < 0 )
return V_66 ;
V_84 += V_66 ;
return F_73 ( V_84 ) ;
}
void F_79 ( void )
{
unsigned int V_32 ;
for ( V_32 = 1 ; V_32 < F_35 ( V_42 ) ; V_32 ++ )
F_29 ( F_30 ( & V_42 [ V_32 - 1 ] , & V_42 [ V_32 ] ) >= 0 ) ;
for ( V_32 = 0 ; V_32 < F_35 ( V_65 ) ; V_32 ++ )
V_65 [ V_32 ] . V_45 ( NULL , & V_65 [ V_32 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_32 = 0 ; V_32 < 7 ; V_32 ++ )
if ( ( ( V_71 >> ( V_32 * 3 ) ) & 7 ) == 0 )
break;
V_71 &= ( 1 << ( V_32 * 3 ) ) - 1 ;
}
void F_80 ( struct V_1 * V_2 )
{
T_2 V_33 ;
const struct V_5 * V_31 ;
memset ( V_2 -> V_7 . V_8 , 0x42 , sizeof( V_2 -> V_7 . V_8 ) ) ;
F_44 ( V_2 , V_42 , F_35 ( V_42 ) ) ;
V_31 = F_31 ( V_2 -> V_7 . V_35 , & V_33 ) ;
F_44 ( V_2 , V_31 , V_33 ) ;
for ( V_33 = 1 ; V_33 < V_118 ; V_33 ++ )
if ( V_2 -> V_7 . V_8 [ V_33 ] == 0x42424242 )
F_81 ( L_2 , V_33 ) ;
}
