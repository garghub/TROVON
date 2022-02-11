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
F_6 () ;
}
static void F_7 ( T_1 V_3 )
{
asm volatile("dc csw, %x0" : : "r" (val));
F_6 () ;
}
static bool F_8 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
unsigned long V_3 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return F_9 ( V_5 , V_7 ) ;
V_10 = F_10 () ;
F_11 ( & V_5 -> V_12 . V_13 ) ;
F_12 ( V_10 , & V_5 -> V_12 . V_13 ) ;
if ( V_10 != V_5 -> V_12 . V_14 ) {
F_13 () ;
goto V_15;
}
V_3 = * F_14 ( V_5 , V_7 -> V_16 ) ;
switch ( V_7 -> V_17 ) {
case 6 :
case 14 :
F_5 ( V_3 ) ;
break;
case 10 :
F_7 ( V_3 ) ;
break;
}
V_15:
F_15 () ;
return true ;
}
static bool F_16 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
unsigned long V_3 ;
F_17 ( ! V_7 -> V_11 ) ;
V_3 = * F_14 ( V_5 , V_7 -> V_16 ) ;
if ( ! V_7 -> V_18 ) {
F_18 ( V_5 , V_9 -> V_19 ) = V_3 ;
} else {
F_19 ( V_5 , V_9 -> V_19 ) = V_3 & 0xffffffffUL ;
if ( ! V_7 -> V_20 )
F_19 ( V_5 , V_9 -> V_19 + 1 ) = V_3 >> 32 ;
}
return true ;
}
static bool F_20 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
F_16 ( V_5 , V_7 , V_9 ) ;
if ( F_21 ( V_5 ) ) {
V_5 -> V_12 . V_21 &= ~ V_22 ;
F_22 ( V_5 -> V_23 ) ;
}
return true ;
}
static bool F_23 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
if ( V_7 -> V_11 )
return F_24 ( V_5 , V_7 ) ;
else
return F_25 ( V_5 , V_7 ) ;
}
static void F_26 ( struct V_4 * V_5 , const struct V_8 * V_9 )
{
T_2 V_24 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_18 ( V_5 , V_25 ) = V_24 ;
}
static void F_27 ( struct V_4 * V_5 , const struct V_8 * V_9 )
{
F_18 ( V_5 , V_26 ) = ( 1UL << 31 ) | ( V_5 -> V_27 & 0xff ) ;
}
void F_28 ( unsigned int V_28 ,
struct V_29 * V_30 )
{
V_31 [ V_28 ] = V_30 ;
}
static const struct V_8 * F_29 ( unsigned V_28 ,
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
static const struct V_8 * F_30 ( const struct V_6 * V_36 ,
const struct V_8 V_30 [] ,
unsigned int V_33 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ ) {
const struct V_8 * V_9 = & V_30 [ V_37 ] ;
if ( V_36 -> V_38 != V_9 -> V_38 )
continue;
if ( V_36 -> V_39 != V_9 -> V_39 )
continue;
if ( V_36 -> V_40 != V_9 -> V_40 )
continue;
if ( V_36 -> V_17 != V_9 -> V_17 )
continue;
if ( V_36 -> V_41 != V_9 -> V_41 )
continue;
return V_9 ;
}
return NULL ;
}
int F_31 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
F_32 ( V_5 ) ;
return 1 ;
}
int F_33 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
F_32 ( V_5 ) ;
return 1 ;
}
static void F_34 ( struct V_4 * V_5 ,
const struct V_6 * V_36 )
{
T_3 V_33 ;
const struct V_8 * V_30 , * V_9 ;
V_30 = F_29 ( V_5 -> V_12 . V_28 , false , & V_33 ) ;
V_9 = F_30 ( V_36 , V_30 , V_33 ) ;
if ( ! V_9 )
V_9 = F_30 ( V_36 , V_44 , F_35 ( V_44 ) ) ;
if ( F_36 ( V_9 ) ) {
F_17 ( ! V_9 -> V_45 ) ;
if ( F_36 ( V_9 -> V_45 ( V_5 , V_36 , V_9 ) ) ) {
F_37 ( V_5 , F_38 ( V_5 ) ) ;
return;
}
}
F_39 ( L_1 , * F_40 ( V_5 ) ) ;
F_41 ( V_36 ) ;
F_32 ( V_5 ) ;
}
int F_42 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
struct V_6 V_36 ;
T_1 V_46 = F_43 ( V_5 ) ;
int V_47 = ( V_46 >> 10 ) & 0xf ;
V_36 . V_18 = true ;
V_36 . V_20 = false ;
V_36 . V_17 = ( V_46 >> 1 ) & 0xf ;
V_36 . V_16 = ( V_46 >> 5 ) & 0xf ;
V_36 . V_11 = ( ( V_46 & 1 ) == 0 ) ;
V_36 . V_38 = 0 ;
V_36 . V_39 = ( V_46 >> 16 ) & 0xf ;
V_36 . V_41 = 0 ;
V_36 . V_40 = 0 ;
if ( V_36 . V_11 ) {
T_2 V_3 = * F_14 ( V_5 , V_36 . V_16 ) ;
V_3 &= 0xffffffff ;
V_3 |= * F_14 ( V_5 , V_47 ) << 32 ;
* F_14 ( V_5 , V_36 . V_16 ) = V_3 ;
}
F_34 ( V_5 , & V_36 ) ;
if ( ! V_36 . V_11 ) {
T_2 V_3 = * F_14 ( V_5 , V_36 . V_16 ) ;
V_3 >>= 32 ;
* F_14 ( V_5 , V_47 ) = V_3 ;
}
return 1 ;
}
int F_44 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
struct V_6 V_36 ;
T_1 V_46 = F_43 ( V_5 ) ;
V_36 . V_18 = true ;
V_36 . V_20 = true ;
V_36 . V_17 = ( V_46 >> 1 ) & 0xf ;
V_36 . V_16 = ( V_46 >> 5 ) & 0xf ;
V_36 . V_11 = ( ( V_46 & 1 ) == 0 ) ;
V_36 . V_40 = ( V_46 >> 10 ) & 0xf ;
V_36 . V_38 = 0 ;
V_36 . V_39 = ( V_46 >> 14 ) & 0x7 ;
V_36 . V_41 = ( V_46 >> 17 ) & 0x7 ;
F_34 ( V_5 , & V_36 ) ;
return 1 ;
}
static int F_45 ( struct V_4 * V_5 ,
const struct V_6 * V_36 )
{
T_3 V_33 ;
const struct V_8 * V_30 , * V_9 ;
V_30 = F_29 ( V_5 -> V_12 . V_28 , true , & V_33 ) ;
V_9 = F_30 ( V_36 , V_30 , V_33 ) ;
if ( ! V_9 )
V_9 = F_30 ( V_36 , V_48 , F_35 ( V_48 ) ) ;
if ( F_36 ( V_9 ) ) {
F_17 ( ! V_9 -> V_45 ) ;
if ( F_36 ( V_9 -> V_45 ( V_5 , V_36 , V_9 ) ) ) {
F_37 ( V_5 , F_38 ( V_5 ) ) ;
return 1 ;
}
} else {
F_39 ( L_2 ,
* F_40 ( V_5 ) ) ;
F_41 ( V_36 ) ;
}
F_32 ( V_5 ) ;
return 1 ;
}
static void F_46 ( struct V_4 * V_5 ,
const struct V_8 * V_30 , T_3 V_33 )
{
unsigned long V_37 ;
for ( V_37 = 0 ; V_37 < V_33 ; V_37 ++ )
if ( V_30 [ V_37 ] . V_49 )
V_30 [ V_37 ] . V_49 ( V_5 , & V_30 [ V_37 ] ) ;
}
int F_47 ( struct V_4 * V_5 , struct V_42 * V_43 )
{
struct V_6 V_36 ;
unsigned long V_50 = F_43 ( V_5 ) ;
V_36 . V_18 = false ;
V_36 . V_20 = false ;
V_36 . V_38 = ( V_50 >> 20 ) & 3 ;
V_36 . V_39 = ( V_50 >> 14 ) & 0x7 ;
V_36 . V_40 = ( V_50 >> 10 ) & 0xf ;
V_36 . V_17 = ( V_50 >> 1 ) & 0xf ;
V_36 . V_41 = ( V_50 >> 17 ) & 0x7 ;
V_36 . V_16 = ( V_50 >> 5 ) & 0x1f ;
V_36 . V_11 = ! ( V_50 & 1 ) ;
return F_45 ( V_5 , & V_36 ) ;
}
static bool F_48 ( T_2 V_51 , struct V_6 * V_36 )
{
switch ( V_51 & V_52 ) {
case V_53 :
if ( V_51 & ~ ( V_54 | V_52
| V_55
| V_56
| V_57
| V_58
| V_59
| V_60 ) )
return false ;
V_36 -> V_38 = ( ( V_51 & V_56 )
>> V_61 ) ;
V_36 -> V_39 = ( ( V_51 & V_57 )
>> V_62 ) ;
V_36 -> V_40 = ( ( V_51 & V_58 )
>> V_63 ) ;
V_36 -> V_17 = ( ( V_51 & V_59 )
>> V_64 ) ;
V_36 -> V_41 = ( ( V_51 & V_60 )
>> V_65 ) ;
return true ;
default:
return false ;
}
}
static const struct V_8 * F_49 ( struct V_4 * V_5 ,
T_2 V_51 )
{
T_3 V_33 ;
const struct V_8 * V_30 , * V_9 ;
struct V_6 V_36 ;
if ( ( V_51 & V_55 ) != V_66 )
return NULL ;
if ( ! F_48 ( V_51 , & V_36 ) )
return NULL ;
V_30 = F_29 ( V_5 -> V_12 . V_28 , true , & V_33 ) ;
V_9 = F_30 ( & V_36 , V_30 , V_33 ) ;
if ( ! V_9 )
V_9 = F_30 ( & V_36 , V_48 , F_35 ( V_48 ) ) ;
if ( V_9 && ! V_9 -> V_19 )
V_9 = NULL ;
return V_9 ;
}
static int F_50 ( void * V_3 , const void T_4 * V_67 , T_2 V_51 )
{
if ( F_51 ( V_3 , V_67 , F_52 ( V_51 ) ) != 0 )
return - V_68 ;
return 0 ;
}
static int F_53 ( void T_4 * V_67 , const void * V_3 , T_2 V_51 )
{
if ( F_54 ( V_67 , V_3 , F_52 ( V_51 ) ) != 0 )
return - V_68 ;
return 0 ;
}
static int F_55 ( T_2 V_51 , void T_4 * V_67 )
{
struct V_6 V_36 ;
const struct V_8 * V_9 ;
if ( ! F_48 ( V_51 , & V_36 ) )
return - V_69 ;
V_9 = F_30 ( & V_36 , V_70 , F_35 ( V_70 ) ) ;
if ( ! V_9 )
return - V_69 ;
return F_53 ( V_67 , & V_9 -> V_3 , V_51 ) ;
}
static int F_56 ( T_2 V_51 , void T_4 * V_67 )
{
struct V_6 V_36 ;
const struct V_8 * V_9 ;
int V_71 ;
T_2 V_3 = 0 ;
if ( ! F_48 ( V_51 , & V_36 ) )
return - V_69 ;
V_9 = F_30 ( & V_36 , V_70 , F_35 ( V_70 ) ) ;
if ( ! V_9 )
return - V_69 ;
V_71 = F_50 ( & V_3 , V_67 , V_51 ) ;
if ( V_71 )
return V_71 ;
if ( V_9 -> V_3 != V_3 )
return - V_72 ;
return 0 ;
}
static bool F_57 ( T_1 V_3 )
{
T_1 V_73 , V_74 ;
if ( V_3 >= V_75 )
return - V_69 ;
V_73 = ( V_3 >> 1 ) ;
V_74 = ( V_76 >> ( V_73 * 3 ) ) & 7 ;
switch ( V_74 ) {
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
static int F_58 ( T_2 V_51 , void T_4 * V_67 )
{
T_1 V_3 ;
T_1 T_4 * V_77 = V_67 ;
if ( V_51 & ~ ( V_54 | V_52 | V_55
| ( ( 1 << V_78 ) - 1 ) ) )
return - V_69 ;
switch ( V_51 & V_79 ) {
case V_80 :
if ( F_52 ( V_51 ) != 4 )
return - V_69 ;
V_3 = ( V_51 & V_81 )
>> V_82 ;
if ( ! F_57 ( V_3 ) )
return - V_69 ;
return F_59 ( F_1 ( V_3 ) , V_77 ) ;
default:
return - V_69 ;
}
}
static int F_60 ( T_2 V_51 , void T_4 * V_67 )
{
T_1 V_3 , V_83 ;
T_1 T_4 * V_77 = V_67 ;
if ( V_51 & ~ ( V_54 | V_52 | V_55
| ( ( 1 << V_78 ) - 1 ) ) )
return - V_69 ;
switch ( V_51 & V_79 ) {
case V_80 :
if ( F_52 ( V_51 ) != 4 )
return - V_69 ;
V_3 = ( V_51 & V_81 )
>> V_82 ;
if ( ! F_57 ( V_3 ) )
return - V_69 ;
if ( F_61 ( V_83 , V_77 ) )
return - V_68 ;
if ( V_83 != F_1 ( V_3 ) )
return - V_72 ;
return 0 ;
default:
return - V_69 ;
}
}
int F_62 ( struct V_4 * V_5 , const struct V_84 * V_19 )
{
const struct V_8 * V_9 ;
void T_4 * V_67 = ( void T_4 * ) ( unsigned long ) V_19 -> V_85 ;
if ( ( V_19 -> V_51 & V_55 ) == V_86 )
return F_58 ( V_19 -> V_51 , V_67 ) ;
if ( F_52 ( V_19 -> V_51 ) != sizeof( V_87 ) )
return - V_69 ;
V_9 = F_49 ( V_5 , V_19 -> V_51 ) ;
if ( ! V_9 )
return F_55 ( V_19 -> V_51 , V_67 ) ;
return F_53 ( V_67 , & F_18 ( V_5 , V_9 -> V_19 ) , V_19 -> V_51 ) ;
}
int F_63 ( struct V_4 * V_5 , const struct V_84 * V_19 )
{
const struct V_8 * V_9 ;
void T_4 * V_67 = ( void T_4 * ) ( unsigned long ) V_19 -> V_85 ;
if ( ( V_19 -> V_51 & V_55 ) == V_86 )
return F_60 ( V_19 -> V_51 , V_67 ) ;
if ( F_52 ( V_19 -> V_51 ) != sizeof( V_87 ) )
return - V_69 ;
V_9 = F_49 ( V_5 , V_19 -> V_51 ) ;
if ( ! V_9 )
return F_56 ( V_19 -> V_51 , V_67 ) ;
return F_50 ( & F_18 ( V_5 , V_9 -> V_19 ) , V_67 , V_19 -> V_51 ) ;
}
static unsigned int F_64 ( void )
{
unsigned int V_37 , V_88 = 0 ;
for ( V_37 = 0 ; V_37 < V_75 ; V_37 ++ )
if ( F_57 ( V_37 ) )
V_88 ++ ;
return V_88 ;
}
static int F_65 ( T_2 T_4 * V_89 )
{
T_2 V_3 = V_90 | V_91 | V_86 ;
unsigned int V_37 ;
V_3 |= V_80 ;
for ( V_37 = 0 ; V_37 < V_75 ; V_37 ++ ) {
if ( ! F_57 ( V_37 ) )
continue;
if ( F_59 ( V_3 | V_37 , V_89 ) )
return - V_68 ;
V_89 ++ ;
}
return 0 ;
}
static T_2 F_66 ( const struct V_8 * V_19 )
{
return ( V_92 | V_53 |
V_66 |
( V_19 -> V_38 << V_61 ) |
( V_19 -> V_39 << V_62 ) |
( V_19 -> V_40 << V_63 ) |
( V_19 -> V_17 << V_64 ) |
( V_19 -> V_41 << V_65 ) ) ;
}
static bool F_67 ( const struct V_8 * V_19 , T_2 T_4 * * V_93 )
{
if ( ! * V_93 )
return true ;
if ( F_59 ( F_66 ( V_19 ) , * V_93 ) )
return false ;
( * V_93 ) ++ ;
return true ;
}
static int F_68 ( struct V_4 * V_5 , T_2 T_4 * V_93 )
{
const struct V_8 * V_94 , * V_95 , * V_96 , * V_97 ;
unsigned int V_98 = 0 ;
T_3 V_33 ;
V_94 = F_29 ( V_5 -> V_12 . V_28 , true , & V_33 ) ;
V_96 = V_94 + V_33 ;
V_95 = V_48 ;
V_97 = V_48 + F_35 ( V_48 ) ;
F_17 ( V_94 == V_96 || V_95 == V_97 ) ;
while ( V_94 || V_95 ) {
int V_99 = F_69 ( V_94 , V_95 ) ;
if ( V_99 <= 0 ) {
if ( V_94 -> V_19 ) {
if ( ! F_67 ( V_94 , & V_93 ) )
return - V_68 ;
V_98 ++ ;
}
} else {
if ( V_95 -> V_19 ) {
if ( ! F_67 ( V_95 , & V_93 ) )
return - V_68 ;
V_98 ++ ;
}
}
if ( V_99 <= 0 && ++ V_94 == V_96 )
V_94 = NULL ;
if ( V_99 >= 0 && ++ V_95 == V_97 )
V_95 = NULL ;
}
return V_98 ;
}
unsigned long F_70 ( struct V_4 * V_5 )
{
return F_35 ( V_70 )
+ F_64 ()
+ F_68 ( V_5 , ( T_2 T_4 * ) NULL ) ;
}
int F_71 ( struct V_4 * V_5 , T_2 T_4 * V_89 )
{
unsigned int V_37 ;
int V_71 ;
for ( V_37 = 0 ; V_37 < F_35 ( V_70 ) ; V_37 ++ ) {
if ( F_59 ( F_66 ( & V_70 [ V_37 ] ) , V_89 ) )
return - V_68 ;
V_89 ++ ;
}
V_71 = F_68 ( V_5 , V_89 ) ;
if ( V_71 < 0 )
return V_71 ;
V_89 += V_71 ;
return F_65 ( V_89 ) ;
}
void F_72 ( void )
{
unsigned int V_37 ;
struct V_8 V_100 ;
for ( V_37 = 1 ; V_37 < F_35 ( V_48 ) ; V_37 ++ )
F_17 ( F_69 ( & V_48 [ V_37 - 1 ] , & V_48 [ V_37 ] ) >= 0 ) ;
for ( V_37 = 0 ; V_37 < F_35 ( V_70 ) ; V_37 ++ )
V_70 [ V_37 ] . V_49 ( NULL , & V_70 [ V_37 ] ) ;
F_73 ( NULL , & V_100 ) ;
V_76 = V_100 . V_3 ;
for ( V_37 = 0 ; V_37 < 7 ; V_37 ++ )
if ( ( ( V_76 >> ( V_37 * 3 ) ) & 7 ) == 0 )
break;
V_76 &= ( 1 << ( V_37 * 3 ) ) - 1 ;
}
void F_74 ( struct V_4 * V_5 )
{
T_3 V_33 ;
const struct V_8 * V_30 ;
memset ( & V_5 -> V_12 . V_101 . V_102 , 0x42 , sizeof( V_5 -> V_12 . V_101 . V_102 ) ) ;
F_46 ( V_5 , V_48 , F_35 ( V_48 ) ) ;
V_30 = F_29 ( V_5 -> V_12 . V_28 , true , & V_33 ) ;
F_46 ( V_5 , V_30 , V_33 ) ;
for ( V_33 = 1 ; V_33 < V_103 ; V_33 ++ )
if ( F_18 ( V_5 , V_33 ) == 0x4242424242424242 )
F_75 ( L_3 , V_33 ) ;
}
