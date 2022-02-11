static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
F_2 () ;
asm volatile("msr csselr_el1, %x0" : : "r" (csselr));
F_3 () ;
asm volatile("mrs %0, ccsidr_el1" : "=r" (ccsidr));
F_4 () ;
return V_2 ;
}
static bool F_5 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
F_7 ( V_4 ) ;
return true ;
}
static bool F_8 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
unsigned long V_10 ;
bool V_11 = F_9 ( V_4 ) ;
F_10 ( ! V_6 -> V_9 ) ;
V_10 = * F_11 ( V_4 , V_6 -> V_12 ) ;
if ( ! V_6 -> V_13 ) {
F_12 ( V_4 , V_8 -> V_14 ) = V_10 ;
} else {
if ( ! V_6 -> V_15 )
F_13 ( V_4 , V_8 -> V_14 ) = V_10 >> 32 ;
F_14 ( V_4 , V_8 -> V_14 ) = V_10 & 0xffffffffUL ;
}
F_15 ( V_4 , V_11 ) ;
return true ;
}
static bool F_16 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 )
return F_17 ( V_4 , V_6 ) ;
else
return F_18 ( V_4 , V_6 ) ;
}
static bool F_19 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_17 ( V_4 , V_6 ) ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = ( 1 << 3 ) ;
return true ;
}
}
static bool F_20 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_17 ( V_4 , V_6 ) ;
} else {
T_1 V_10 ;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
* F_11 ( V_4 , V_6 -> V_12 ) = V_10 ;
return true ;
}
}
static bool F_21 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_12 ( V_4 , V_8 -> V_14 ) = * F_11 ( V_4 , V_6 -> V_12 ) ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = F_12 ( V_4 , V_8 -> V_14 ) ;
}
return true ;
}
static void F_22 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_19 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_12 ( V_4 , V_20 ) = V_19 ;
}
static void F_23 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
F_12 ( V_4 , V_21 ) = ( 1UL << 31 ) | ( V_4 -> V_22 & 0xff ) ;
}
static bool F_24 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_17 ( V_4 , V_6 ) ;
} else {
T_2 V_23 = F_25 ( V_24 ) ;
T_2 V_25 = F_25 ( V_26 ) ;
T_1 V_27 = ! ! ( ( V_25 >> 12 ) & 0xf ) ;
* F_11 ( V_4 , V_6 -> V_12 ) = ( ( ( ( V_23 >> 20 ) & 0xf ) << 28 ) |
( ( ( V_23 >> 12 ) & 0xf ) << 24 ) |
( ( ( V_23 >> 28 ) & 0xf ) << 20 ) |
( 6 << 16 ) | ( V_27 << 14 ) | ( V_27 << 12 ) ) ;
return true ;
}
}
static bool F_26 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_27 ( V_4 , V_8 -> V_14 ) = * F_11 ( V_4 , V_6 -> V_12 ) ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = F_27 ( V_4 , V_8 -> V_14 ) ;
}
return true ;
}
void F_28 ( unsigned int V_28 ,
struct V_29 * V_30 )
{
V_31 [ V_28 ] = V_30 ;
}
static const struct V_7 * F_29 ( unsigned V_28 ,
bool V_32 ,
T_3 * V_33 )
{
struct V_29 * V_30 ;
V_30 = V_31 [ V_28 ] ;
if ( V_32 ) {
* V_33 = V_30 -> V_34 . V_33 ;
return V_30 -> V_34 . V_30 ;
} else {
* V_33 = V_30 -> V_35 . V_33 ;
return V_30 -> V_35 . V_30 ;
}
}
static const struct V_7 * F_30 ( const struct V_5 * V_36 ,
const struct V_7 V_30 [] ,
unsigned int V_33 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
const struct V_7 * V_8 = & V_30 [ V_37 ] ;
if ( V_36 -> V_38 != V_8 -> V_38 )
continue;
if ( V_36 -> V_39 != V_8 -> V_39 )
continue;
if ( V_36 -> V_40 != V_8 -> V_40 )
continue;
if ( V_36 -> V_41 != V_8 -> V_41 )
continue;
if ( V_36 -> V_42 != V_8 -> V_42 )
continue;
return V_8 ;
}
return NULL ;
}
int F_31 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
F_32 ( V_4 ) ;
return 1 ;
}
static int F_33 ( struct V_3 * V_4 ,
const struct V_5 * V_36 ,
const struct V_7 * V_30 ,
T_3 V_33 )
{
const struct V_7 * V_8 ;
if ( ! V_30 )
return - 1 ;
V_8 = F_30 ( V_36 , V_30 , V_33 ) ;
if ( V_8 ) {
F_10 ( ! V_8 -> V_45 ) ;
if ( F_34 ( V_8 -> V_45 ( V_4 , V_36 , V_8 ) ) ) {
F_35 ( V_4 , F_36 ( V_4 ) ) ;
}
return 0 ;
}
return - 1 ;
}
static void F_37 ( struct V_3 * V_4 ,
struct V_5 * V_36 )
{
T_4 V_46 = F_38 ( V_4 ) ;
int V_47 ;
switch( V_46 ) {
case V_48 :
case V_49 :
V_47 = 15 ;
break;
case V_50 :
case V_51 :
V_47 = 14 ;
break;
default:
F_39 ( ( V_47 = - 1 ) ) ;
}
F_40 ( L_1 ,
V_47 , * F_41 ( V_4 ) ) ;
F_42 ( V_36 ) ;
F_32 ( V_4 ) ;
}
static int F_43 ( struct V_3 * V_4 ,
const struct V_7 * V_52 ,
T_3 V_53 ,
const struct V_7 * V_54 ,
T_3 V_55 )
{
struct V_5 V_36 ;
T_1 V_56 = F_44 ( V_4 ) ;
int V_57 = ( V_56 >> 10 ) & 0xf ;
V_36 . V_13 = true ;
V_36 . V_15 = false ;
V_36 . V_41 = ( V_56 >> 1 ) & 0xf ;
V_36 . V_12 = ( V_56 >> 5 ) & 0xf ;
V_36 . V_9 = ( ( V_56 & 1 ) == 0 ) ;
V_36 . V_38 = 0 ;
V_36 . V_39 = ( V_56 >> 16 ) & 0xf ;
V_36 . V_42 = 0 ;
V_36 . V_40 = 0 ;
if ( V_36 . V_9 ) {
T_2 V_10 = * F_11 ( V_4 , V_36 . V_12 ) ;
V_10 &= 0xffffffff ;
V_10 |= * F_11 ( V_4 , V_57 ) << 32 ;
* F_11 ( V_4 , V_36 . V_12 ) = V_10 ;
}
if ( ! F_33 ( V_4 , & V_36 , V_54 , V_55 ) )
goto V_58;
if ( ! F_33 ( V_4 , & V_36 , V_52 , V_53 ) )
goto V_58;
F_37 ( V_4 , & V_36 ) ;
V_58:
if ( ! V_36 . V_9 ) {
T_2 V_10 = * F_11 ( V_4 , V_36 . V_12 ) ;
V_10 >>= 32 ;
* F_11 ( V_4 , V_57 ) = V_10 ;
}
return 1 ;
}
static int F_45 ( struct V_3 * V_4 ,
const struct V_7 * V_52 ,
T_3 V_53 ,
const struct V_7 * V_54 ,
T_3 V_55 )
{
struct V_5 V_36 ;
T_1 V_56 = F_44 ( V_4 ) ;
V_36 . V_13 = true ;
V_36 . V_15 = true ;
V_36 . V_41 = ( V_56 >> 1 ) & 0xf ;
V_36 . V_12 = ( V_56 >> 5 ) & 0xf ;
V_36 . V_9 = ( ( V_56 & 1 ) == 0 ) ;
V_36 . V_40 = ( V_56 >> 10 ) & 0xf ;
V_36 . V_38 = 0 ;
V_36 . V_39 = ( V_56 >> 14 ) & 0x7 ;
V_36 . V_42 = ( V_56 >> 17 ) & 0x7 ;
if ( ! F_33 ( V_4 , & V_36 , V_54 , V_55 ) )
return 1 ;
if ( ! F_33 ( V_4 , & V_36 , V_52 , V_53 ) )
return 1 ;
F_37 ( V_4 , & V_36 ) ;
return 1 ;
}
int F_46 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
const struct V_7 * V_54 ;
T_3 V_33 ;
V_54 = F_29 ( V_4 -> V_16 . V_28 , false , & V_33 ) ;
return F_43 ( V_4 ,
V_59 , F_47 ( V_59 ) ,
V_54 , V_33 ) ;
}
int F_48 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
const struct V_7 * V_54 ;
T_3 V_33 ;
V_54 = F_29 ( V_4 -> V_16 . V_28 , false , & V_33 ) ;
return F_45 ( V_4 ,
V_60 , F_47 ( V_60 ) ,
V_54 , V_33 ) ;
}
int F_49 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
return F_43 ( V_4 ,
V_61 , F_47 ( V_61 ) ,
NULL , 0 ) ;
}
int F_50 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
return F_45 ( V_4 ,
V_62 , F_47 ( V_62 ) ,
NULL , 0 ) ;
}
static int F_51 ( struct V_3 * V_4 ,
const struct V_5 * V_36 )
{
T_3 V_33 ;
const struct V_7 * V_30 , * V_8 ;
V_30 = F_29 ( V_4 -> V_16 . V_28 , true , & V_33 ) ;
V_8 = F_30 ( V_36 , V_30 , V_33 ) ;
if ( ! V_8 )
V_8 = F_30 ( V_36 , V_63 , F_47 ( V_63 ) ) ;
if ( F_34 ( V_8 ) ) {
F_10 ( ! V_8 -> V_45 ) ;
if ( F_34 ( V_8 -> V_45 ( V_4 , V_36 , V_8 ) ) ) {
F_35 ( V_4 , F_36 ( V_4 ) ) ;
return 1 ;
}
} else {
F_40 ( L_2 ,
* F_41 ( V_4 ) ) ;
F_42 ( V_36 ) ;
}
F_32 ( V_4 ) ;
return 1 ;
}
static void F_52 ( struct V_3 * V_4 ,
const struct V_7 * V_30 , T_3 V_33 )
{
unsigned long V_37 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
if ( V_30 [ V_37 ] . V_64 )
V_30 [ V_37 ] . V_64 ( V_4 , & V_30 [ V_37 ] ) ;
}
int F_53 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
struct V_5 V_36 ;
unsigned long V_65 = F_44 ( V_4 ) ;
V_36 . V_13 = false ;
V_36 . V_15 = false ;
V_36 . V_38 = ( V_65 >> 20 ) & 3 ;
V_36 . V_39 = ( V_65 >> 14 ) & 0x7 ;
V_36 . V_40 = ( V_65 >> 10 ) & 0xf ;
V_36 . V_41 = ( V_65 >> 1 ) & 0xf ;
V_36 . V_42 = ( V_65 >> 17 ) & 0x7 ;
V_36 . V_12 = ( V_65 >> 5 ) & 0x1f ;
V_36 . V_9 = ! ( V_65 & 1 ) ;
return F_51 ( V_4 , & V_36 ) ;
}
static bool F_54 ( T_2 V_66 , struct V_5 * V_36 )
{
switch ( V_66 & V_67 ) {
case V_68 :
if ( V_66 & ~ ( V_69 | V_67
| V_70
| V_71
| V_72
| V_73
| V_74
| V_75 ) )
return false ;
V_36 -> V_38 = ( ( V_66 & V_71 )
>> V_76 ) ;
V_36 -> V_39 = ( ( V_66 & V_72 )
>> V_77 ) ;
V_36 -> V_40 = ( ( V_66 & V_73 )
>> V_78 ) ;
V_36 -> V_41 = ( ( V_66 & V_74 )
>> V_79 ) ;
V_36 -> V_42 = ( ( V_66 & V_75 )
>> V_80 ) ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_55 ( struct V_3 * V_4 ,
T_2 V_66 )
{
T_3 V_33 ;
const struct V_7 * V_30 , * V_8 ;
struct V_5 V_36 ;
if ( ( V_66 & V_70 ) != V_81 )
return NULL ;
if ( ! F_54 ( V_66 , & V_36 ) )
return NULL ;
V_30 = F_29 ( V_4 -> V_16 . V_28 , true , & V_33 ) ;
V_8 = F_30 ( & V_36 , V_30 , V_33 ) ;
if ( ! V_8 )
V_8 = F_30 ( & V_36 , V_63 , F_47 ( V_63 ) ) ;
if ( V_8 && ! V_8 -> V_14 )
V_8 = NULL ;
return V_8 ;
}
static int F_56 ( T_2 * V_10 , const void T_5 * V_82 , T_2 V_66 )
{
if ( F_57 ( V_10 , V_82 , F_58 ( V_66 ) ) != 0 )
return - V_83 ;
return 0 ;
}
static int F_59 ( void T_5 * V_82 , const T_2 * V_10 , T_2 V_66 )
{
if ( F_60 ( V_82 , V_10 , F_58 ( V_66 ) ) != 0 )
return - V_83 ;
return 0 ;
}
static int F_61 ( T_2 V_66 , void T_5 * V_82 )
{
struct V_5 V_36 ;
const struct V_7 * V_8 ;
if ( ! F_54 ( V_66 , & V_36 ) )
return - V_84 ;
V_8 = F_30 ( & V_36 , V_85 , F_47 ( V_85 ) ) ;
if ( ! V_8 )
return - V_84 ;
return F_59 ( V_82 , & V_8 -> V_10 , V_66 ) ;
}
static int F_62 ( T_2 V_66 , void T_5 * V_82 )
{
struct V_5 V_36 ;
const struct V_7 * V_8 ;
int V_86 ;
T_2 V_10 = 0 ;
if ( ! F_54 ( V_66 , & V_36 ) )
return - V_84 ;
V_8 = F_30 ( & V_36 , V_85 , F_47 ( V_85 ) ) ;
if ( ! V_8 )
return - V_84 ;
V_86 = F_56 ( & V_10 , V_82 , V_66 ) ;
if ( V_86 )
return V_86 ;
if ( V_8 -> V_10 != V_10 )
return - V_87 ;
return 0 ;
}
static bool F_63 ( T_1 V_10 )
{
T_1 V_88 , V_89 ;
if ( V_10 >= V_90 )
return false ;
V_88 = ( V_10 >> 1 ) ;
V_89 = ( V_91 >> ( V_88 * 3 ) ) & 7 ;
switch ( V_89 ) {
case 0 :
return false ;
case 1 :
return ( V_10 & 1 ) ;
case 2 :
case 4 :
return ! ( V_10 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_64 ( T_2 V_66 , void T_5 * V_82 )
{
T_1 V_10 ;
T_1 T_5 * V_92 = V_82 ;
if ( V_66 & ~ ( V_69 | V_67 | V_70
| ( ( 1 << V_93 ) - 1 ) ) )
return - V_84 ;
switch ( V_66 & V_94 ) {
case V_95 :
if ( F_58 ( V_66 ) != 4 )
return - V_84 ;
V_10 = ( V_66 & V_96 )
>> V_97 ;
if ( ! F_63 ( V_10 ) )
return - V_84 ;
return F_65 ( F_1 ( V_10 ) , V_92 ) ;
default:
return - V_84 ;
}
}
static int F_66 ( T_2 V_66 , void T_5 * V_82 )
{
T_1 V_10 , V_98 ;
T_1 T_5 * V_92 = V_82 ;
if ( V_66 & ~ ( V_69 | V_67 | V_70
| ( ( 1 << V_93 ) - 1 ) ) )
return - V_84 ;
switch ( V_66 & V_94 ) {
case V_95 :
if ( F_58 ( V_66 ) != 4 )
return - V_84 ;
V_10 = ( V_66 & V_96 )
>> V_97 ;
if ( ! F_63 ( V_10 ) )
return - V_84 ;
if ( F_67 ( V_98 , V_92 ) )
return - V_83 ;
if ( V_98 != F_1 ( V_10 ) )
return - V_87 ;
return 0 ;
default:
return - V_84 ;
}
}
int F_68 ( struct V_3 * V_4 , const struct V_99 * V_14 )
{
const struct V_7 * V_8 ;
void T_5 * V_82 = ( void T_5 * ) ( unsigned long ) V_14 -> V_100 ;
if ( ( V_14 -> V_66 & V_70 ) == V_101 )
return F_64 ( V_14 -> V_66 , V_82 ) ;
if ( F_58 ( V_14 -> V_66 ) != sizeof( V_102 ) )
return - V_84 ;
V_8 = F_55 ( V_4 , V_14 -> V_66 ) ;
if ( ! V_8 )
return F_61 ( V_14 -> V_66 , V_82 ) ;
return F_59 ( V_82 , & F_12 ( V_4 , V_8 -> V_14 ) , V_14 -> V_66 ) ;
}
int F_69 ( struct V_3 * V_4 , const struct V_99 * V_14 )
{
const struct V_7 * V_8 ;
void T_5 * V_82 = ( void T_5 * ) ( unsigned long ) V_14 -> V_100 ;
if ( ( V_14 -> V_66 & V_70 ) == V_101 )
return F_66 ( V_14 -> V_66 , V_82 ) ;
if ( F_58 ( V_14 -> V_66 ) != sizeof( V_102 ) )
return - V_84 ;
V_8 = F_55 ( V_4 , V_14 -> V_66 ) ;
if ( ! V_8 )
return F_62 ( V_14 -> V_66 , V_82 ) ;
return F_56 ( & F_12 ( V_4 , V_8 -> V_14 ) , V_82 , V_14 -> V_66 ) ;
}
static unsigned int F_70 ( void )
{
unsigned int V_37 , V_103 = 0 ;
for ( V_37 = 0 ; V_37 < V_90 ; V_37 ++ )
if ( F_63 ( V_37 ) )
V_103 ++ ;
return V_103 ;
}
static int F_71 ( T_2 T_5 * V_104 )
{
T_2 V_10 = V_105 | V_106 | V_101 ;
unsigned int V_37 ;
V_10 |= V_95 ;
for ( V_37 = 0 ; V_37 < V_90 ; V_37 ++ ) {
if ( ! F_63 ( V_37 ) )
continue;
if ( F_65 ( V_10 | V_37 , V_104 ) )
return - V_83 ;
V_104 ++ ;
}
return 0 ;
}
static T_2 F_72 ( const struct V_7 * V_14 )
{
return ( V_105 | V_68 |
V_81 |
( V_14 -> V_38 << V_76 ) |
( V_14 -> V_39 << V_77 ) |
( V_14 -> V_40 << V_78 ) |
( V_14 -> V_41 << V_79 ) |
( V_14 -> V_42 << V_80 ) ) ;
}
static bool F_73 ( const struct V_7 * V_14 , T_2 T_5 * * V_107 )
{
if ( ! * V_107 )
return true ;
if ( F_65 ( F_72 ( V_14 ) , * V_107 ) )
return false ;
( * V_107 ) ++ ;
return true ;
}
static int F_74 ( struct V_3 * V_4 , T_2 T_5 * V_107 )
{
const struct V_7 * V_108 , * V_109 , * V_110 , * V_111 ;
unsigned int V_112 = 0 ;
T_3 V_33 ;
V_108 = F_29 ( V_4 -> V_16 . V_28 , true , & V_33 ) ;
V_110 = V_108 + V_33 ;
V_109 = V_63 ;
V_111 = V_63 + F_47 ( V_63 ) ;
F_10 ( V_108 == V_110 || V_109 == V_111 ) ;
while ( V_108 || V_109 ) {
int V_113 = F_75 ( V_108 , V_109 ) ;
if ( V_113 <= 0 ) {
if ( V_108 -> V_14 ) {
if ( ! F_73 ( V_108 , & V_107 ) )
return - V_83 ;
V_112 ++ ;
}
} else {
if ( V_109 -> V_14 ) {
if ( ! F_73 ( V_109 , & V_107 ) )
return - V_83 ;
V_112 ++ ;
}
}
if ( V_113 <= 0 && ++ V_108 == V_110 )
V_108 = NULL ;
if ( V_113 >= 0 && ++ V_109 == V_111 )
V_109 = NULL ;
}
return V_112 ;
}
unsigned long F_76 ( struct V_3 * V_4 )
{
return F_47 ( V_85 )
+ F_70 ()
+ F_74 ( V_4 , ( T_2 T_5 * ) NULL ) ;
}
int F_77 ( struct V_3 * V_4 , T_2 T_5 * V_104 )
{
unsigned int V_37 ;
int V_86 ;
for ( V_37 = 0 ; V_37 < F_47 ( V_85 ) ; V_37 ++ ) {
if ( F_65 ( F_72 ( & V_85 [ V_37 ] ) , V_104 ) )
return - V_83 ;
V_104 ++ ;
}
V_86 = F_74 ( V_4 , V_104 ) ;
if ( V_86 < 0 )
return V_86 ;
V_104 += V_86 ;
return F_71 ( V_104 ) ;
}
static int F_78 ( const struct V_7 * V_30 , unsigned int V_114 )
{
unsigned int V_37 ;
for ( V_37 = 1 ; V_37 < V_114 ; V_37 ++ ) {
if ( F_75 ( & V_30 [ V_37 - 1 ] , & V_30 [ V_37 ] ) >= 0 ) {
F_40 ( L_3 , V_30 , V_37 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_79 ( void )
{
unsigned int V_37 ;
struct V_7 V_115 ;
F_10 ( F_78 ( V_63 , F_47 ( V_63 ) ) ) ;
F_10 ( F_78 ( V_62 , F_47 ( V_62 ) ) ) ;
F_10 ( F_78 ( V_61 , F_47 ( V_61 ) ) ) ;
F_10 ( F_78 ( V_60 , F_47 ( V_60 ) ) ) ;
F_10 ( F_78 ( V_59 , F_47 ( V_59 ) ) ) ;
F_10 ( F_78 ( V_85 , F_47 ( V_85 ) ) ) ;
for ( V_37 = 0 ; V_37 < F_47 ( V_85 ) ; V_37 ++ )
V_85 [ V_37 ] . V_64 ( NULL , & V_85 [ V_37 ] ) ;
F_80 ( NULL , & V_115 ) ;
V_91 = V_115 . V_10 ;
for ( V_37 = 0 ; V_37 < 7 ; V_37 ++ )
if ( ( ( V_91 >> ( V_37 * 3 ) ) & 7 ) == 0 )
break;
V_91 &= ( 1 << ( V_37 * 3 ) ) - 1 ;
}
void F_81 ( struct V_3 * V_4 )
{
T_3 V_33 ;
const struct V_7 * V_30 ;
memset ( & V_4 -> V_16 . V_116 . V_117 , 0x42 , sizeof( V_4 -> V_16 . V_116 . V_117 ) ) ;
F_52 ( V_4 , V_63 , F_47 ( V_63 ) ) ;
V_30 = F_29 ( V_4 -> V_16 . V_28 , true , & V_33 ) ;
F_52 ( V_4 , V_30 , V_33 ) ;
for ( V_33 = 1 ; V_33 < V_118 ; V_33 ++ )
if ( F_12 ( V_4 , V_33 ) == 0x4242424242424242 )
F_82 ( L_4 , V_33 ) ;
}
