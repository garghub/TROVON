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
F_28 ( ! V_14 -> V_15 ) ;
V_2 -> V_7 . V_8 [ V_6 -> V_30 ] = * F_10 ( V_2 , V_14 -> V_16 ) ;
if ( V_14 -> V_31 )
V_2 -> V_7 . V_8 [ V_6 -> V_30 + 1 ] = * F_10 ( V_2 , V_14 -> V_32 ) ;
return true ;
}
bool F_29 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
F_27 ( V_2 , V_14 , V_6 ) ;
if ( F_30 ( V_2 ) ) {
V_2 -> V_7 . V_33 &= ~ V_34 ;
F_31 ( V_2 -> V_21 ) ;
}
return true ;
}
static bool F_32 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_5 * V_6 )
{
if ( V_14 -> V_15 )
return F_9 ( V_2 , V_14 ) ;
else
return F_13 ( V_2 , V_14 ) ;
}
void F_33 ( struct V_35 * V_36 )
{
unsigned int V_37 ;
for ( V_37 = 1 ; V_37 < V_36 -> V_38 ; V_37 ++ )
F_28 ( F_34 ( & V_36 -> V_36 [ V_37 - 1 ] ,
& V_36 -> V_36 [ V_37 ] ) >= 0 ) ;
V_39 [ V_36 -> V_40 ] = V_36 ;
}
static const struct V_5 * F_35 ( unsigned V_40 , T_2 * V_38 )
{
struct V_35 * V_36 ;
V_36 = V_39 [ V_40 ] ;
* V_38 = V_36 -> V_38 ;
return V_36 -> V_36 ;
}
static const struct V_5 * F_36 ( const struct V_13 * V_41 ,
const struct V_5 V_36 [] ,
unsigned int V_38 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
const struct V_5 * V_6 = & V_36 [ V_37 ] ;
if ( V_41 -> V_31 != V_6 -> V_42 )
continue;
if ( V_41 -> V_43 != V_6 -> V_43 )
continue;
if ( V_41 -> V_29 != V_6 -> V_29 )
continue;
if ( V_41 -> V_44 != V_6 -> V_44 )
continue;
if ( V_41 -> V_45 != V_6 -> V_45 )
continue;
return V_6 ;
}
return NULL ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_13 * V_41 )
{
T_2 V_38 ;
const struct V_5 * V_36 , * V_6 ;
F_38 ( V_41 -> V_44 , V_41 -> V_16 , V_41 -> V_43 ,
V_41 -> V_29 , V_41 -> V_45 , V_41 -> V_15 ) ;
V_36 = F_35 ( V_2 -> V_7 . V_40 , & V_38 ) ;
V_6 = F_36 ( V_41 , V_36 , V_38 ) ;
if ( ! V_6 )
V_6 = F_36 ( V_41 , V_46 , F_39 ( V_46 ) ) ;
if ( F_40 ( V_6 ) ) {
F_28 ( ! V_6 -> V_47 ) ;
if ( F_40 ( V_6 -> V_47 ( V_2 , V_41 , V_6 ) ) ) {
F_41 ( V_2 , F_42 ( V_2 ) ) ;
return 1 ;
}
} else {
F_43 ( L_1 ,
* F_44 ( V_2 ) ) ;
F_45 ( V_41 ) ;
}
F_2 ( V_2 ) ;
return 1 ;
}
int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_13 V_41 ;
V_41 . V_43 = ( F_47 ( V_2 ) >> 1 ) & 0xf ;
V_41 . V_16 = ( F_47 ( V_2 ) >> 5 ) & 0xf ;
V_41 . V_15 = ( ( F_47 ( V_2 ) & 1 ) == 0 ) ;
V_41 . V_31 = true ;
V_41 . V_44 = ( F_47 ( V_2 ) >> 16 ) & 0xf ;
V_41 . V_45 = 0 ;
V_41 . V_32 = ( F_47 ( V_2 ) >> 10 ) & 0xf ;
V_41 . V_29 = 0 ;
return F_37 ( V_2 , & V_41 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_5 * V_36 , T_2 V_38 )
{
unsigned long V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_36 [ V_37 ] . V_48 )
V_36 [ V_37 ] . V_48 ( V_2 , & V_36 [ V_37 ] ) ;
}
int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_13 V_41 ;
V_41 . V_29 = ( F_47 ( V_2 ) >> 1 ) & 0xf ;
V_41 . V_16 = ( F_47 ( V_2 ) >> 5 ) & 0xf ;
V_41 . V_15 = ( ( F_47 ( V_2 ) & 1 ) == 0 ) ;
V_41 . V_31 = false ;
V_41 . V_43 = ( F_47 ( V_2 ) >> 10 ) & 0xf ;
V_41 . V_44 = ( F_47 ( V_2 ) >> 14 ) & 0x7 ;
V_41 . V_45 = ( F_47 ( V_2 ) >> 17 ) & 0x7 ;
V_41 . V_32 = 0 ;
return F_37 ( V_2 , & V_41 ) ;
}
static bool F_50 ( T_3 V_49 , struct V_13 * V_41 )
{
switch ( V_49 & V_50 ) {
case V_51 :
if ( V_49 & ~ ( V_52 | V_50
| V_53
| V_54
| V_55
| V_56
| V_57 ) )
return false ;
V_41 -> V_31 = false ;
V_41 -> V_43 = ( ( V_49 & V_54 )
>> V_58 ) ;
V_41 -> V_29 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_41 -> V_44 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_41 -> V_45 = ( ( V_49 & V_57 )
>> V_61 ) ;
return true ;
case V_62 :
if ( V_49 & ~ ( V_52 | V_50
| V_53
| V_55
| V_56 ) )
return false ;
V_41 -> V_31 = true ;
V_41 -> V_43 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_41 -> V_44 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_41 -> V_45 = 0 ;
V_41 -> V_29 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_5 * F_51 ( struct V_1 * V_2 ,
T_3 V_49 )
{
T_2 V_38 ;
const struct V_5 * V_36 , * V_6 ;
struct V_13 V_41 ;
if ( ( V_49 & V_53 ) >> V_63 != 15 )
return NULL ;
if ( ! F_50 ( V_49 , & V_41 ) )
return NULL ;
V_36 = F_35 ( V_2 -> V_7 . V_40 , & V_38 ) ;
V_6 = F_36 ( & V_41 , V_36 , V_38 ) ;
if ( ! V_6 )
V_6 = F_36 ( & V_41 , V_46 , F_39 ( V_46 ) ) ;
if ( V_6 && ! V_6 -> V_30 )
V_6 = NULL ;
return V_6 ;
}
static int F_52 ( void * V_24 , const void T_4 * V_64 , T_3 V_49 )
{
if ( F_53 ( V_24 , V_64 , F_54 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_55 ( void T_4 * V_64 , const void * V_24 , T_3 V_49 )
{
if ( F_56 ( V_64 , V_24 , F_54 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_57 ( T_3 V_49 , void T_4 * V_64 )
{
struct V_13 V_41 ;
const struct V_5 * V_6 ;
if ( ! F_50 ( V_49 , & V_41 ) )
return - V_66 ;
V_6 = F_36 ( & V_41 , V_67 , F_39 ( V_67 ) ) ;
if ( ! V_6 )
return - V_66 ;
return F_55 ( V_64 , & V_6 -> V_24 , V_49 ) ;
}
static int F_58 ( T_3 V_49 , void T_4 * V_64 )
{
struct V_13 V_41 ;
const struct V_5 * V_6 ;
int V_68 ;
T_3 V_24 = 0 ;
if ( ! F_50 ( V_49 , & V_41 ) )
return - V_66 ;
V_6 = F_36 ( & V_41 , V_67 , F_39 ( V_67 ) ) ;
if ( ! V_6 )
return - V_66 ;
V_68 = F_52 ( & V_24 , V_64 , V_49 ) ;
if ( V_68 )
return V_68 ;
if ( V_6 -> V_24 != V_24 )
return - V_69 ;
return 0 ;
}
static bool F_59 ( T_1 V_24 )
{
T_1 V_70 , V_71 ;
if ( V_24 >= V_72 )
return - V_66 ;
V_70 = ( V_24 >> 1 ) ;
V_71 = ( V_73 >> ( V_70 * 3 ) ) & 7 ;
switch ( V_71 ) {
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
static T_1 F_60 ( T_1 V_74 )
{
T_1 V_75 ;
F_61 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_62 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_63 () ;
return V_75 ;
}
static int F_64 ( T_3 V_49 , void T_4 * V_64 )
{
T_1 V_24 ;
T_1 T_4 * V_76 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_66 ;
switch ( V_49 & V_77 ) {
case V_78 :
if ( F_54 ( V_49 ) != 4 )
return - V_66 ;
V_24 = ( V_49 & V_79 )
>> V_80 ;
if ( ! F_59 ( V_24 ) )
return - V_66 ;
return F_65 ( F_60 ( V_24 ) , V_76 ) ;
default:
return - V_66 ;
}
}
static int F_66 ( T_3 V_49 , void T_4 * V_64 )
{
T_1 V_24 , V_81 ;
T_1 T_4 * V_76 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_66 ;
switch ( V_49 & V_77 ) {
case V_78 :
if ( F_54 ( V_49 ) != 4 )
return - V_66 ;
V_24 = ( V_49 & V_79 )
>> V_80 ;
if ( ! F_59 ( V_24 ) )
return - V_66 ;
if ( F_67 ( V_81 , V_76 ) )
return - V_65 ;
if ( V_81 != F_60 ( V_24 ) )
return - V_69 ;
return 0 ;
default:
return - V_66 ;
}
}
static unsigned int F_68 ( void )
{
if ( ( ( F_69 ( V_82 ) & V_83 ) >> V_84 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_70 ( void )
{
return F_68 () + F_39 ( V_85 ) ;
}
static int F_71 ( T_3 T_4 * V_86 )
{
unsigned int V_37 ;
const T_3 V_87 = V_88 | V_51 | V_89 ;
const T_3 V_90 = V_88 | V_62 | V_89 ;
for ( V_37 = 0 ; V_37 < F_68 () ; V_37 ++ ) {
if ( F_65 ( ( V_90 | V_91 ) + V_37 ,
V_86 ) )
return - V_65 ;
V_86 ++ ;
}
for ( V_37 = 0 ; V_37 < F_39 ( V_85 ) ; V_37 ++ ) {
if ( F_65 ( V_87 | V_85 [ V_37 ] , V_86 ) )
return - V_65 ;
V_86 ++ ;
}
return F_70 () ;
}
static int F_72 ( const struct V_1 * V_2 , T_3 V_49 , void T_4 * V_64 )
{
T_1 V_92 = ( V_49 & V_93 ) ;
T_1 V_24 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_66 ;
if ( V_92 < F_68 () ) {
if ( F_54 ( V_49 ) != 8 )
return - V_66 ;
return F_55 ( V_64 , & V_2 -> V_7 . V_94 . V_95 [ V_92 ] ,
V_49 ) ;
}
if ( F_54 ( V_49 ) != 4 )
return - V_66 ;
switch ( V_92 ) {
case V_96 :
return F_55 ( V_64 , & V_2 -> V_7 . V_94 . V_97 , V_49 ) ;
case V_98 :
return F_55 ( V_64 , & V_2 -> V_7 . V_94 . V_99 , V_49 ) ;
case V_100 :
return F_55 ( V_64 , & V_2 -> V_7 . V_94 . V_101 , V_49 ) ;
case V_102 :
return F_55 ( V_64 , & V_2 -> V_7 . V_94 . V_103 , V_49 ) ;
case V_104 :
V_24 = F_69 ( V_82 ) ;
return F_55 ( V_64 , & V_24 , V_49 ) ;
case V_105 :
V_24 = F_69 ( V_106 ) ;
return F_55 ( V_64 , & V_24 , V_49 ) ;
case V_107 :
V_24 = F_69 ( V_108 ) ;
return F_55 ( V_64 , & V_24 , V_49 ) ;
default:
return - V_66 ;
}
}
static int F_73 ( struct V_1 * V_2 , T_3 V_49 , const void T_4 * V_64 )
{
T_1 V_92 = ( V_49 & V_93 ) ;
T_1 V_24 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_66 ;
if ( V_92 < F_68 () ) {
if ( F_54 ( V_49 ) != 8 )
return - V_66 ;
return F_52 ( & V_2 -> V_7 . V_94 . V_95 [ V_92 ] ,
V_64 , V_49 ) ;
}
if ( F_54 ( V_49 ) != 4 )
return - V_66 ;
switch ( V_92 ) {
case V_96 :
return F_52 ( & V_2 -> V_7 . V_94 . V_97 , V_64 , V_49 ) ;
case V_98 :
return F_52 ( & V_2 -> V_7 . V_94 . V_99 , V_64 , V_49 ) ;
case V_100 :
return F_52 ( & V_2 -> V_7 . V_94 . V_101 , V_64 , V_49 ) ;
case V_102 :
return F_52 ( & V_2 -> V_7 . V_94 . V_103 , V_64 , V_49 ) ;
case V_104 :
if ( F_52 ( & V_24 , V_64 , V_49 ) )
return - V_65 ;
if ( V_24 != F_69 ( V_82 ) )
return - V_69 ;
return 0 ;
case V_105 :
if ( F_52 ( & V_24 , V_64 , V_49 ) )
return - V_65 ;
if ( V_24 != F_69 ( V_106 ) )
return - V_69 ;
return 0 ;
case V_107 :
if ( F_52 ( & V_24 , V_64 , V_49 ) )
return - V_65 ;
if ( V_24 != F_69 ( V_108 ) )
return - V_69 ;
return 0 ;
default:
return - V_66 ;
}
}
static unsigned int F_70 ( void )
{
return 0 ;
}
static int F_71 ( T_3 T_4 * V_86 )
{
return 0 ;
}
static int F_72 ( const struct V_1 * V_2 , T_3 V_49 , void T_4 * V_64 )
{
return - V_66 ;
}
static int F_73 ( struct V_1 * V_2 , T_3 V_49 , const void T_4 * V_64 )
{
return - V_66 ;
}
int F_74 ( struct V_1 * V_2 , const struct V_109 * V_30 )
{
const struct V_5 * V_6 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_30 -> V_110 ;
if ( ( V_30 -> V_49 & V_53 ) == V_111 )
return F_64 ( V_30 -> V_49 , V_64 ) ;
if ( ( V_30 -> V_49 & V_53 ) == V_89 )
return F_72 ( V_2 , V_30 -> V_49 , V_64 ) ;
V_6 = F_51 ( V_2 , V_30 -> V_49 ) ;
if ( ! V_6 )
return F_57 ( V_30 -> V_49 , V_64 ) ;
return F_55 ( V_64 , & V_2 -> V_7 . V_8 [ V_6 -> V_30 ] , V_30 -> V_49 ) ;
}
int F_75 ( struct V_1 * V_2 , const struct V_109 * V_30 )
{
const struct V_5 * V_6 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_30 -> V_110 ;
if ( ( V_30 -> V_49 & V_53 ) == V_111 )
return F_66 ( V_30 -> V_49 , V_64 ) ;
if ( ( V_30 -> V_49 & V_53 ) == V_89 )
return F_73 ( V_2 , V_30 -> V_49 , V_64 ) ;
V_6 = F_51 ( V_2 , V_30 -> V_49 ) ;
if ( ! V_6 )
return F_58 ( V_30 -> V_49 , V_64 ) ;
return F_52 ( & V_2 -> V_7 . V_8 [ V_6 -> V_30 ] , V_64 , V_30 -> V_49 ) ;
}
static unsigned int F_76 ( void )
{
unsigned int V_37 , V_112 = 0 ;
for ( V_37 = 0 ; V_37 < V_72 ; V_37 ++ )
if ( F_59 ( V_37 ) )
V_112 ++ ;
return V_112 ;
}
static int F_77 ( T_3 T_4 * V_86 )
{
T_3 V_24 = V_88 | V_51 | V_111 ;
unsigned int V_37 ;
V_24 |= V_78 ;
for ( V_37 = 0 ; V_37 < V_72 ; V_37 ++ ) {
if ( ! F_59 ( V_37 ) )
continue;
if ( F_65 ( V_24 | V_37 , V_86 ) )
return - V_65 ;
V_86 ++ ;
}
return 0 ;
}
static T_3 F_78 ( const struct V_5 * V_30 )
{
T_3 V_24 = V_88 | ( 15 << V_63 ) ;
if ( V_30 -> V_42 ) {
V_24 |= V_62 ;
V_24 |= ( V_30 -> V_44 << V_60 ) ;
V_24 |= ( V_30 -> V_43 << V_59 ) ;
} else {
V_24 |= V_51 ;
V_24 |= ( V_30 -> V_44 << V_60 ) ;
V_24 |= ( V_30 -> V_45 << V_61 ) ;
V_24 |= ( V_30 -> V_29 << V_59 ) ;
V_24 |= ( V_30 -> V_43 << V_58 ) ;
}
return V_24 ;
}
static bool F_79 ( const struct V_5 * V_30 , T_3 T_4 * * V_113 )
{
if ( ! * V_113 )
return true ;
if ( F_65 ( F_78 ( V_30 ) , * V_113 ) )
return false ;
( * V_113 ) ++ ;
return true ;
}
static int F_80 ( struct V_1 * V_2 , T_3 T_4 * V_113 )
{
const struct V_5 * V_114 , * V_115 , * V_116 , * V_117 ;
unsigned int V_118 = 0 ;
T_2 V_38 ;
V_114 = F_35 ( V_2 -> V_7 . V_40 , & V_38 ) ;
V_116 = V_114 + V_38 ;
V_115 = V_46 ;
V_117 = V_46 + F_39 ( V_46 ) ;
F_28 ( V_114 == V_116 || V_115 == V_117 ) ;
while ( V_114 || V_115 ) {
int V_119 = F_34 ( V_114 , V_115 ) ;
if ( V_119 <= 0 ) {
if ( V_114 -> V_30 ) {
if ( ! F_79 ( V_114 , & V_113 ) )
return - V_65 ;
V_118 ++ ;
}
} else {
if ( V_115 -> V_30 ) {
if ( ! F_79 ( V_115 , & V_113 ) )
return - V_65 ;
V_118 ++ ;
}
}
if ( V_119 <= 0 && ++ V_114 == V_116 )
V_114 = NULL ;
if ( V_119 >= 0 && ++ V_115 == V_117 )
V_115 = NULL ;
}
return V_118 ;
}
unsigned long F_81 ( struct V_1 * V_2 )
{
return F_39 ( V_67 )
+ F_76 ()
+ F_70 ()
+ F_80 ( V_2 , ( T_3 T_4 * ) NULL ) ;
}
int F_82 ( struct V_1 * V_2 , T_3 T_4 * V_86 )
{
unsigned int V_37 ;
int V_68 ;
for ( V_37 = 0 ; V_37 < F_39 ( V_67 ) ; V_37 ++ ) {
if ( F_65 ( F_78 ( & V_67 [ V_37 ] ) , V_86 ) )
return - V_65 ;
V_86 ++ ;
}
V_68 = F_80 ( V_2 , V_86 ) ;
if ( V_68 < 0 )
return V_68 ;
V_86 += V_68 ;
V_68 = F_71 ( V_86 ) ;
if ( V_68 < 0 )
return V_68 ;
V_86 += V_68 ;
return F_77 ( V_86 ) ;
}
void F_83 ( void )
{
unsigned int V_37 ;
for ( V_37 = 1 ; V_37 < F_39 ( V_46 ) ; V_37 ++ )
F_28 ( F_34 ( & V_46 [ V_37 - 1 ] , & V_46 [ V_37 ] ) >= 0 ) ;
for ( V_37 = 0 ; V_37 < F_39 ( V_67 ) ; V_37 ++ )
V_67 [ V_37 ] . V_48 ( NULL , & V_67 [ V_37 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_37 = 0 ; V_37 < 7 ; V_37 ++ )
if ( ( ( V_73 >> ( V_37 * 3 ) ) & 7 ) == 0 )
break;
V_73 &= ( 1 << ( V_37 * 3 ) ) - 1 ;
}
void F_84 ( struct V_1 * V_2 )
{
T_2 V_38 ;
const struct V_5 * V_36 ;
memset ( V_2 -> V_7 . V_8 , 0x42 , sizeof( V_2 -> V_7 . V_8 ) ) ;
F_48 ( V_2 , V_46 , F_39 ( V_46 ) ) ;
V_36 = F_35 ( V_2 -> V_7 . V_40 , & V_38 ) ;
F_48 ( V_2 , V_36 , V_38 ) ;
for ( V_38 = 1 ; V_38 < V_120 ; V_38 ++ )
if ( V_2 -> V_7 . V_8 [ V_38 ] == 0x42424242 )
F_85 ( L_2 , V_38 ) ;
}
