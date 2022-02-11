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
static void F_5 ( T_1 V_3 )
{
asm volatile("dc cisw, %x0" : : "r" (val));
F_6 ( V_4 ) ;
}
static void F_7 ( T_1 V_3 )
{
asm volatile("dc csw, %x0" : : "r" (val));
F_6 ( V_4 ) ;
}
static bool F_8 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
unsigned long V_3 ;
int V_11 ;
if ( ! V_8 -> V_12 )
return F_9 ( V_6 , V_8 ) ;
V_11 = F_10 () ;
F_11 ( & V_6 -> V_13 . V_14 ) ;
F_12 ( V_11 , & V_6 -> V_13 . V_14 ) ;
if ( V_11 != V_6 -> V_13 . V_15 ) {
F_13 () ;
goto V_16;
}
V_3 = * F_14 ( V_6 , V_8 -> V_17 ) ;
switch ( V_8 -> V_18 ) {
case 6 :
case 14 :
F_5 ( V_3 ) ;
break;
case 10 :
F_7 ( V_3 ) ;
break;
}
V_16:
F_15 () ;
return true ;
}
static bool F_16 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
unsigned long V_3 ;
F_17 ( ! V_8 -> V_12 ) ;
V_3 = * F_14 ( V_6 , V_8 -> V_17 ) ;
if ( ! V_8 -> V_19 ) {
F_18 ( V_6 , V_10 -> V_20 ) = V_3 ;
} else {
F_19 ( V_6 , V_10 -> V_20 ) = V_3 & 0xffffffffUL ;
if ( ! V_8 -> V_21 )
F_19 ( V_6 , V_10 -> V_20 + 1 ) = V_3 >> 32 ;
}
return true ;
}
static bool F_20 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
F_16 ( V_6 , V_8 , V_10 ) ;
if ( F_21 ( V_6 ) ) {
V_6 -> V_13 . V_22 &= ~ V_23 ;
F_22 ( V_6 -> V_24 ) ;
}
return true ;
}
static bool F_23 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 )
return F_24 ( V_6 , V_8 ) ;
else
return F_25 ( V_6 , V_8 ) ;
}
static void F_26 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
T_2 V_25 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_18 ( V_6 , V_26 ) = V_25 ;
}
static void F_27 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
F_18 ( V_6 , V_27 ) = ( 1UL << 31 ) | ( V_6 -> V_28 & 0xff ) ;
}
void F_28 ( unsigned int V_29 ,
struct V_30 * V_31 )
{
V_32 [ V_29 ] = V_31 ;
}
static const struct V_9 * F_29 ( unsigned V_29 ,
bool V_33 ,
T_3 * V_34 )
{
struct V_30 * V_31 ;
V_31 = V_32 [ V_29 ] ;
if ( V_33 ) {
* V_34 = V_31 -> V_35 . V_34 ;
return V_31 -> V_35 . V_31 ;
} else {
* V_34 = V_31 -> V_36 . V_34 ;
return V_31 -> V_36 . V_31 ;
}
}
static const struct V_9 * F_30 ( const struct V_7 * V_37 ,
const struct V_9 V_31 [] ,
unsigned int V_34 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ ) {
const struct V_9 * V_10 = & V_31 [ V_38 ] ;
if ( V_37 -> V_39 != V_10 -> V_39 )
continue;
if ( V_37 -> V_40 != V_10 -> V_40 )
continue;
if ( V_37 -> V_41 != V_10 -> V_41 )
continue;
if ( V_37 -> V_18 != V_10 -> V_18 )
continue;
if ( V_37 -> V_42 != V_10 -> V_42 )
continue;
return V_10 ;
}
return NULL ;
}
int F_31 ( struct V_5 * V_6 , struct V_43 * V_44 )
{
F_32 ( V_6 ) ;
return 1 ;
}
int F_33 ( struct V_5 * V_6 , struct V_43 * V_44 )
{
F_32 ( V_6 ) ;
return 1 ;
}
static void F_34 ( struct V_5 * V_6 ,
const struct V_7 * V_37 )
{
T_3 V_34 ;
const struct V_9 * V_31 , * V_10 ;
V_31 = F_29 ( V_6 -> V_13 . V_29 , false , & V_34 ) ;
V_10 = F_30 ( V_37 , V_31 , V_34 ) ;
if ( ! V_10 )
V_10 = F_30 ( V_37 , V_45 , F_35 ( V_45 ) ) ;
if ( F_36 ( V_10 ) ) {
F_17 ( ! V_10 -> V_46 ) ;
if ( F_36 ( V_10 -> V_46 ( V_6 , V_37 , V_10 ) ) ) {
F_37 ( V_6 , F_38 ( V_6 ) ) ;
return;
}
}
F_39 ( L_1 , * F_40 ( V_6 ) ) ;
F_41 ( V_37 ) ;
F_32 ( V_6 ) ;
}
int F_42 ( struct V_5 * V_6 , struct V_43 * V_44 )
{
struct V_7 V_37 ;
T_1 V_47 = F_43 ( V_6 ) ;
int V_48 = ( V_47 >> 10 ) & 0xf ;
V_37 . V_19 = true ;
V_37 . V_21 = false ;
V_37 . V_18 = ( V_47 >> 1 ) & 0xf ;
V_37 . V_17 = ( V_47 >> 5 ) & 0xf ;
V_37 . V_12 = ( ( V_47 & 1 ) == 0 ) ;
V_37 . V_39 = 0 ;
V_37 . V_40 = ( V_47 >> 16 ) & 0xf ;
V_37 . V_42 = 0 ;
V_37 . V_41 = 0 ;
if ( V_37 . V_12 ) {
T_2 V_3 = * F_14 ( V_6 , V_37 . V_17 ) ;
V_3 &= 0xffffffff ;
V_3 |= * F_14 ( V_6 , V_48 ) << 32 ;
* F_14 ( V_6 , V_37 . V_17 ) = V_3 ;
}
F_34 ( V_6 , & V_37 ) ;
if ( ! V_37 . V_12 ) {
T_2 V_3 = * F_14 ( V_6 , V_37 . V_17 ) ;
V_3 >>= 32 ;
* F_14 ( V_6 , V_48 ) = V_3 ;
}
return 1 ;
}
int F_44 ( struct V_5 * V_6 , struct V_43 * V_44 )
{
struct V_7 V_37 ;
T_1 V_47 = F_43 ( V_6 ) ;
V_37 . V_19 = true ;
V_37 . V_21 = true ;
V_37 . V_18 = ( V_47 >> 1 ) & 0xf ;
V_37 . V_17 = ( V_47 >> 5 ) & 0xf ;
V_37 . V_12 = ( ( V_47 & 1 ) == 0 ) ;
V_37 . V_41 = ( V_47 >> 10 ) & 0xf ;
V_37 . V_39 = 0 ;
V_37 . V_40 = ( V_47 >> 14 ) & 0x7 ;
V_37 . V_42 = ( V_47 >> 17 ) & 0x7 ;
F_34 ( V_6 , & V_37 ) ;
return 1 ;
}
static int F_45 ( struct V_5 * V_6 ,
const struct V_7 * V_37 )
{
T_3 V_34 ;
const struct V_9 * V_31 , * V_10 ;
V_31 = F_29 ( V_6 -> V_13 . V_29 , true , & V_34 ) ;
V_10 = F_30 ( V_37 , V_31 , V_34 ) ;
if ( ! V_10 )
V_10 = F_30 ( V_37 , V_49 , F_35 ( V_49 ) ) ;
if ( F_36 ( V_10 ) ) {
F_17 ( ! V_10 -> V_46 ) ;
if ( F_36 ( V_10 -> V_46 ( V_6 , V_37 , V_10 ) ) ) {
F_37 ( V_6 , F_38 ( V_6 ) ) ;
return 1 ;
}
} else {
F_39 ( L_2 ,
* F_40 ( V_6 ) ) ;
F_41 ( V_37 ) ;
}
F_32 ( V_6 ) ;
return 1 ;
}
static void F_46 ( struct V_5 * V_6 ,
const struct V_9 * V_31 , T_3 V_34 )
{
unsigned long V_38 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ )
if ( V_31 [ V_38 ] . V_50 )
V_31 [ V_38 ] . V_50 ( V_6 , & V_31 [ V_38 ] ) ;
}
int F_47 ( struct V_5 * V_6 , struct V_43 * V_44 )
{
struct V_7 V_37 ;
unsigned long V_51 = F_43 ( V_6 ) ;
V_37 . V_19 = false ;
V_37 . V_21 = false ;
V_37 . V_39 = ( V_51 >> 20 ) & 3 ;
V_37 . V_40 = ( V_51 >> 14 ) & 0x7 ;
V_37 . V_41 = ( V_51 >> 10 ) & 0xf ;
V_37 . V_18 = ( V_51 >> 1 ) & 0xf ;
V_37 . V_42 = ( V_51 >> 17 ) & 0x7 ;
V_37 . V_17 = ( V_51 >> 5 ) & 0x1f ;
V_37 . V_12 = ! ( V_51 & 1 ) ;
return F_45 ( V_6 , & V_37 ) ;
}
static bool F_48 ( T_2 V_52 , struct V_7 * V_37 )
{
switch ( V_52 & V_53 ) {
case V_54 :
if ( V_52 & ~ ( V_55 | V_53
| V_56
| V_57
| V_58
| V_59
| V_60
| V_61 ) )
return false ;
V_37 -> V_39 = ( ( V_52 & V_57 )
>> V_62 ) ;
V_37 -> V_40 = ( ( V_52 & V_58 )
>> V_63 ) ;
V_37 -> V_41 = ( ( V_52 & V_59 )
>> V_64 ) ;
V_37 -> V_18 = ( ( V_52 & V_60 )
>> V_65 ) ;
V_37 -> V_42 = ( ( V_52 & V_61 )
>> V_66 ) ;
return true ;
default:
return false ;
}
}
static const struct V_9 * F_49 ( struct V_5 * V_6 ,
T_2 V_52 )
{
T_3 V_34 ;
const struct V_9 * V_31 , * V_10 ;
struct V_7 V_37 ;
if ( ( V_52 & V_56 ) != V_67 )
return NULL ;
if ( ! F_48 ( V_52 , & V_37 ) )
return NULL ;
V_31 = F_29 ( V_6 -> V_13 . V_29 , true , & V_34 ) ;
V_10 = F_30 ( & V_37 , V_31 , V_34 ) ;
if ( ! V_10 )
V_10 = F_30 ( & V_37 , V_49 , F_35 ( V_49 ) ) ;
if ( V_10 && ! V_10 -> V_20 )
V_10 = NULL ;
return V_10 ;
}
static int F_50 ( void * V_3 , const void T_4 * V_68 , T_2 V_52 )
{
if ( F_51 ( V_3 , V_68 , F_52 ( V_52 ) ) != 0 )
return - V_69 ;
return 0 ;
}
static int F_53 ( void T_4 * V_68 , const void * V_3 , T_2 V_52 )
{
if ( F_54 ( V_68 , V_3 , F_52 ( V_52 ) ) != 0 )
return - V_69 ;
return 0 ;
}
static int F_55 ( T_2 V_52 , void T_4 * V_68 )
{
struct V_7 V_37 ;
const struct V_9 * V_10 ;
if ( ! F_48 ( V_52 , & V_37 ) )
return - V_70 ;
V_10 = F_30 ( & V_37 , V_71 , F_35 ( V_71 ) ) ;
if ( ! V_10 )
return - V_70 ;
return F_53 ( V_68 , & V_10 -> V_3 , V_52 ) ;
}
static int F_56 ( T_2 V_52 , void T_4 * V_68 )
{
struct V_7 V_37 ;
const struct V_9 * V_10 ;
int V_72 ;
T_2 V_3 = 0 ;
if ( ! F_48 ( V_52 , & V_37 ) )
return - V_70 ;
V_10 = F_30 ( & V_37 , V_71 , F_35 ( V_71 ) ) ;
if ( ! V_10 )
return - V_70 ;
V_72 = F_50 ( & V_3 , V_68 , V_52 ) ;
if ( V_72 )
return V_72 ;
if ( V_10 -> V_3 != V_3 )
return - V_73 ;
return 0 ;
}
static bool F_57 ( T_1 V_3 )
{
T_1 V_74 , V_75 ;
if ( V_3 >= V_76 )
return - V_70 ;
V_74 = ( V_3 >> 1 ) ;
V_75 = ( V_77 >> ( V_74 * 3 ) ) & 7 ;
switch ( V_75 ) {
case 0 :
return false ;
case 1 :
return ( V_3 & 1 ) ;
case 2 :
case 4 :
return ! ( V_3 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_58 ( T_2 V_52 , void T_4 * V_68 )
{
T_1 V_3 ;
T_1 T_4 * V_78 = V_68 ;
if ( V_52 & ~ ( V_55 | V_53 | V_56
| ( ( 1 << V_79 ) - 1 ) ) )
return - V_70 ;
switch ( V_52 & V_80 ) {
case V_81 :
if ( F_52 ( V_52 ) != 4 )
return - V_70 ;
V_3 = ( V_52 & V_82 )
>> V_83 ;
if ( ! F_57 ( V_3 ) )
return - V_70 ;
return F_59 ( F_1 ( V_3 ) , V_78 ) ;
default:
return - V_70 ;
}
}
static int F_60 ( T_2 V_52 , void T_4 * V_68 )
{
T_1 V_3 , V_84 ;
T_1 T_4 * V_78 = V_68 ;
if ( V_52 & ~ ( V_55 | V_53 | V_56
| ( ( 1 << V_79 ) - 1 ) ) )
return - V_70 ;
switch ( V_52 & V_80 ) {
case V_81 :
if ( F_52 ( V_52 ) != 4 )
return - V_70 ;
V_3 = ( V_52 & V_82 )
>> V_83 ;
if ( ! F_57 ( V_3 ) )
return - V_70 ;
if ( F_61 ( V_84 , V_78 ) )
return - V_69 ;
if ( V_84 != F_1 ( V_3 ) )
return - V_73 ;
return 0 ;
default:
return - V_70 ;
}
}
int F_62 ( struct V_5 * V_6 , const struct V_85 * V_20 )
{
const struct V_9 * V_10 ;
void T_4 * V_68 = ( void T_4 * ) ( unsigned long ) V_20 -> V_86 ;
if ( ( V_20 -> V_52 & V_56 ) == V_87 )
return F_58 ( V_20 -> V_52 , V_68 ) ;
if ( F_52 ( V_20 -> V_52 ) != sizeof( V_88 ) )
return - V_70 ;
V_10 = F_49 ( V_6 , V_20 -> V_52 ) ;
if ( ! V_10 )
return F_55 ( V_20 -> V_52 , V_68 ) ;
return F_53 ( V_68 , & F_18 ( V_6 , V_10 -> V_20 ) , V_20 -> V_52 ) ;
}
int F_63 ( struct V_5 * V_6 , const struct V_85 * V_20 )
{
const struct V_9 * V_10 ;
void T_4 * V_68 = ( void T_4 * ) ( unsigned long ) V_20 -> V_86 ;
if ( ( V_20 -> V_52 & V_56 ) == V_87 )
return F_60 ( V_20 -> V_52 , V_68 ) ;
if ( F_52 ( V_20 -> V_52 ) != sizeof( V_88 ) )
return - V_70 ;
V_10 = F_49 ( V_6 , V_20 -> V_52 ) ;
if ( ! V_10 )
return F_56 ( V_20 -> V_52 , V_68 ) ;
return F_50 ( & F_18 ( V_6 , V_10 -> V_20 ) , V_68 , V_20 -> V_52 ) ;
}
static unsigned int F_64 ( void )
{
unsigned int V_38 , V_89 = 0 ;
for ( V_38 = 0 ; V_38 < V_76 ; V_38 ++ )
if ( F_57 ( V_38 ) )
V_89 ++ ;
return V_89 ;
}
static int F_65 ( T_2 T_4 * V_90 )
{
T_2 V_3 = V_91 | V_92 | V_87 ;
unsigned int V_38 ;
V_3 |= V_81 ;
for ( V_38 = 0 ; V_38 < V_76 ; V_38 ++ ) {
if ( ! F_57 ( V_38 ) )
continue;
if ( F_59 ( V_3 | V_38 , V_90 ) )
return - V_69 ;
V_90 ++ ;
}
return 0 ;
}
static T_2 F_66 ( const struct V_9 * V_20 )
{
return ( V_93 | V_54 |
V_67 |
( V_20 -> V_39 << V_62 ) |
( V_20 -> V_40 << V_63 ) |
( V_20 -> V_41 << V_64 ) |
( V_20 -> V_18 << V_65 ) |
( V_20 -> V_42 << V_66 ) ) ;
}
static bool F_67 ( const struct V_9 * V_20 , T_2 T_4 * * V_94 )
{
if ( ! * V_94 )
return true ;
if ( F_59 ( F_66 ( V_20 ) , * V_94 ) )
return false ;
( * V_94 ) ++ ;
return true ;
}
static int F_68 ( struct V_5 * V_6 , T_2 T_4 * V_94 )
{
const struct V_9 * V_95 , * V_96 , * V_97 , * V_98 ;
unsigned int V_99 = 0 ;
T_3 V_34 ;
V_95 = F_29 ( V_6 -> V_13 . V_29 , true , & V_34 ) ;
V_97 = V_95 + V_34 ;
V_96 = V_49 ;
V_98 = V_49 + F_35 ( V_49 ) ;
F_17 ( V_95 == V_97 || V_96 == V_98 ) ;
while ( V_95 || V_96 ) {
int V_100 = F_69 ( V_95 , V_96 ) ;
if ( V_100 <= 0 ) {
if ( V_95 -> V_20 ) {
if ( ! F_67 ( V_95 , & V_94 ) )
return - V_69 ;
V_99 ++ ;
}
} else {
if ( V_96 -> V_20 ) {
if ( ! F_67 ( V_96 , & V_94 ) )
return - V_69 ;
V_99 ++ ;
}
}
if ( V_100 <= 0 && ++ V_95 == V_97 )
V_95 = NULL ;
if ( V_100 >= 0 && ++ V_96 == V_98 )
V_96 = NULL ;
}
return V_99 ;
}
unsigned long F_70 ( struct V_5 * V_6 )
{
return F_35 ( V_71 )
+ F_64 ()
+ F_68 ( V_6 , ( T_2 T_4 * ) NULL ) ;
}
int F_71 ( struct V_5 * V_6 , T_2 T_4 * V_90 )
{
unsigned int V_38 ;
int V_72 ;
for ( V_38 = 0 ; V_38 < F_35 ( V_71 ) ; V_38 ++ ) {
if ( F_59 ( F_66 ( & V_71 [ V_38 ] ) , V_90 ) )
return - V_69 ;
V_90 ++ ;
}
V_72 = F_68 ( V_6 , V_90 ) ;
if ( V_72 < 0 )
return V_72 ;
V_90 += V_72 ;
return F_65 ( V_90 ) ;
}
void F_72 ( void )
{
unsigned int V_38 ;
struct V_9 V_101 ;
for ( V_38 = 1 ; V_38 < F_35 ( V_49 ) ; V_38 ++ )
F_17 ( F_69 ( & V_49 [ V_38 - 1 ] , & V_49 [ V_38 ] ) >= 0 ) ;
for ( V_38 = 0 ; V_38 < F_35 ( V_71 ) ; V_38 ++ )
V_71 [ V_38 ] . V_50 ( NULL , & V_71 [ V_38 ] ) ;
F_73 ( NULL , & V_101 ) ;
V_77 = V_101 . V_3 ;
for ( V_38 = 0 ; V_38 < 7 ; V_38 ++ )
if ( ( ( V_77 >> ( V_38 * 3 ) ) & 7 ) == 0 )
break;
V_77 &= ( 1 << ( V_38 * 3 ) ) - 1 ;
}
void F_74 ( struct V_5 * V_6 )
{
T_3 V_34 ;
const struct V_9 * V_31 ;
memset ( & V_6 -> V_13 . V_102 . V_103 , 0x42 , sizeof( V_6 -> V_13 . V_102 . V_103 ) ) ;
F_46 ( V_6 , V_49 , F_35 ( V_49 ) ) ;
V_31 = F_29 ( V_6 -> V_13 . V_29 , true , & V_34 ) ;
F_46 ( V_6 , V_31 , V_34 ) ;
for ( V_34 = 1 ; V_34 < V_104 ; V_34 ++ )
if ( F_18 ( V_6 , V_34 ) == 0x4242424242424242 )
F_75 ( L_3 , V_34 ) ;
}
