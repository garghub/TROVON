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
if ( ! V_8 -> V_21 )
F_19 ( V_6 , V_10 -> V_20 ) = V_3 >> 32 ;
F_20 ( V_6 , V_10 -> V_20 ) = V_3 & 0xffffffffUL ;
}
return true ;
}
static bool F_21 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
F_16 ( V_6 , V_8 , V_10 ) ;
if ( F_22 ( V_6 ) ) {
V_6 -> V_13 . V_22 &= ~ V_23 ;
F_23 ( V_6 -> V_24 ) ;
}
return true ;
}
static bool F_24 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 )
return F_25 ( V_6 , V_8 ) ;
else
return F_26 ( V_6 , V_8 ) ;
}
static bool F_27 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 ) {
return F_25 ( V_6 , V_8 ) ;
} else {
* F_14 ( V_6 , V_8 -> V_17 ) = ( 1 << 3 ) ;
return true ;
}
}
static bool F_28 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 ) {
return F_25 ( V_6 , V_8 ) ;
} else {
T_1 V_3 ;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
* F_14 ( V_6 , V_8 -> V_17 ) = V_3 ;
return true ;
}
}
static bool F_29 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 ) {
F_18 ( V_6 , V_10 -> V_20 ) = * F_14 ( V_6 , V_8 -> V_17 ) ;
V_6 -> V_13 . V_25 |= V_26 ;
} else {
* F_14 ( V_6 , V_8 -> V_17 ) = F_18 ( V_6 , V_10 -> V_20 ) ;
}
return true ;
}
static void F_30 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
T_2 V_27 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_18 ( V_6 , V_28 ) = V_27 ;
}
static void F_31 ( struct V_5 * V_6 , const struct V_9 * V_10 )
{
F_18 ( V_6 , V_29 ) = ( 1UL << 31 ) | ( V_6 -> V_30 & 0xff ) ;
}
static bool F_32 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 ) {
return F_25 ( V_6 , V_8 ) ;
} else {
T_2 V_31 = F_33 ( V_32 ) ;
T_2 V_33 = F_33 ( V_34 ) ;
T_1 V_35 = ! ! ( ( V_33 >> 12 ) & 0xf ) ;
* F_14 ( V_6 , V_8 -> V_17 ) = ( ( ( ( V_31 >> 20 ) & 0xf ) << 28 ) |
( ( ( V_31 >> 12 ) & 0xf ) << 24 ) |
( ( ( V_31 >> 28 ) & 0xf ) << 20 ) |
( 6 << 16 ) | ( V_35 << 14 ) | ( V_35 << 12 ) ) ;
return true ;
}
}
static bool F_34 ( struct V_5 * V_6 ,
const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
if ( V_8 -> V_12 ) {
F_35 ( V_6 , V_10 -> V_20 ) = * F_14 ( V_6 , V_8 -> V_17 ) ;
V_6 -> V_13 . V_25 |= V_26 ;
} else {
* F_14 ( V_6 , V_8 -> V_17 ) = F_35 ( V_6 , V_10 -> V_20 ) ;
}
return true ;
}
void F_36 ( unsigned int V_36 ,
struct V_37 * V_38 )
{
V_39 [ V_36 ] = V_38 ;
}
static const struct V_9 * F_37 ( unsigned V_36 ,
bool V_40 ,
T_3 * V_41 )
{
struct V_37 * V_38 ;
V_38 = V_39 [ V_36 ] ;
if ( V_40 ) {
* V_41 = V_38 -> V_42 . V_41 ;
return V_38 -> V_42 . V_38 ;
} else {
* V_41 = V_38 -> V_43 . V_41 ;
return V_38 -> V_43 . V_38 ;
}
}
static const struct V_9 * F_38 ( const struct V_7 * V_44 ,
const struct V_9 V_38 [] ,
unsigned int V_41 )
{
unsigned int V_45 ;
for ( V_45 = 0 ; V_45 < V_41 ; V_45 ++ ) {
const struct V_9 * V_10 = & V_38 [ V_45 ] ;
if ( V_44 -> V_46 != V_10 -> V_46 )
continue;
if ( V_44 -> V_47 != V_10 -> V_47 )
continue;
if ( V_44 -> V_48 != V_10 -> V_48 )
continue;
if ( V_44 -> V_18 != V_10 -> V_18 )
continue;
if ( V_44 -> V_49 != V_10 -> V_49 )
continue;
return V_10 ;
}
return NULL ;
}
int F_39 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
F_40 ( V_6 ) ;
return 1 ;
}
static int F_41 ( struct V_5 * V_6 ,
const struct V_7 * V_44 ,
const struct V_9 * V_38 ,
T_3 V_41 )
{
const struct V_9 * V_10 ;
if ( ! V_38 )
return - 1 ;
V_10 = F_38 ( V_44 , V_38 , V_41 ) ;
if ( V_10 ) {
F_17 ( ! V_10 -> V_52 ) ;
if ( F_42 ( V_10 -> V_52 ( V_6 , V_44 , V_10 ) ) ) {
F_43 ( V_6 , F_44 ( V_6 ) ) ;
}
return 0 ;
}
return - 1 ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_7 * V_44 )
{
T_4 V_53 = F_46 ( V_6 ) ;
int V_54 ;
switch( V_53 ) {
case V_55 :
case V_56 :
V_54 = 15 ;
break;
case V_57 :
case V_58 :
V_54 = 14 ;
break;
default:
F_47 ( ( V_54 = - 1 ) ) ;
}
F_48 ( L_1 ,
V_54 , * F_49 ( V_6 ) ) ;
F_50 ( V_44 ) ;
F_40 ( V_6 ) ;
}
static int F_51 ( struct V_5 * V_6 ,
const struct V_9 * V_59 ,
T_3 V_60 ,
const struct V_9 * V_61 ,
T_3 V_62 )
{
struct V_7 V_44 ;
T_1 V_63 = F_52 ( V_6 ) ;
int V_64 = ( V_63 >> 10 ) & 0xf ;
V_44 . V_19 = true ;
V_44 . V_21 = false ;
V_44 . V_18 = ( V_63 >> 1 ) & 0xf ;
V_44 . V_17 = ( V_63 >> 5 ) & 0xf ;
V_44 . V_12 = ( ( V_63 & 1 ) == 0 ) ;
V_44 . V_46 = 0 ;
V_44 . V_47 = ( V_63 >> 16 ) & 0xf ;
V_44 . V_49 = 0 ;
V_44 . V_48 = 0 ;
if ( V_44 . V_12 ) {
T_2 V_3 = * F_14 ( V_6 , V_44 . V_17 ) ;
V_3 &= 0xffffffff ;
V_3 |= * F_14 ( V_6 , V_64 ) << 32 ;
* F_14 ( V_6 , V_44 . V_17 ) = V_3 ;
}
if ( ! F_41 ( V_6 , & V_44 , V_61 , V_62 ) )
goto V_65;
if ( ! F_41 ( V_6 , & V_44 , V_59 , V_60 ) )
goto V_65;
F_45 ( V_6 , & V_44 ) ;
V_65:
if ( ! V_44 . V_12 ) {
T_2 V_3 = * F_14 ( V_6 , V_44 . V_17 ) ;
V_3 >>= 32 ;
* F_14 ( V_6 , V_64 ) = V_3 ;
}
return 1 ;
}
static int F_53 ( struct V_5 * V_6 ,
const struct V_9 * V_59 ,
T_3 V_60 ,
const struct V_9 * V_61 ,
T_3 V_62 )
{
struct V_7 V_44 ;
T_1 V_63 = F_52 ( V_6 ) ;
V_44 . V_19 = true ;
V_44 . V_21 = true ;
V_44 . V_18 = ( V_63 >> 1 ) & 0xf ;
V_44 . V_17 = ( V_63 >> 5 ) & 0xf ;
V_44 . V_12 = ( ( V_63 & 1 ) == 0 ) ;
V_44 . V_48 = ( V_63 >> 10 ) & 0xf ;
V_44 . V_46 = 0 ;
V_44 . V_47 = ( V_63 >> 14 ) & 0x7 ;
V_44 . V_49 = ( V_63 >> 17 ) & 0x7 ;
if ( ! F_41 ( V_6 , & V_44 , V_61 , V_62 ) )
return 1 ;
if ( ! F_41 ( V_6 , & V_44 , V_59 , V_60 ) )
return 1 ;
F_45 ( V_6 , & V_44 ) ;
return 1 ;
}
int F_54 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
const struct V_9 * V_61 ;
T_3 V_41 ;
V_61 = F_37 ( V_6 -> V_13 . V_36 , false , & V_41 ) ;
return F_51 ( V_6 ,
V_66 , F_55 ( V_66 ) ,
V_61 , V_41 ) ;
}
int F_56 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
const struct V_9 * V_61 ;
T_3 V_41 ;
V_61 = F_37 ( V_6 -> V_13 . V_36 , false , & V_41 ) ;
return F_53 ( V_6 ,
V_67 , F_55 ( V_67 ) ,
V_61 , V_41 ) ;
}
int F_57 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
return F_51 ( V_6 ,
V_68 , F_55 ( V_68 ) ,
NULL , 0 ) ;
}
int F_58 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
return F_53 ( V_6 ,
V_69 , F_55 ( V_69 ) ,
NULL , 0 ) ;
}
static int F_59 ( struct V_5 * V_6 ,
const struct V_7 * V_44 )
{
T_3 V_41 ;
const struct V_9 * V_38 , * V_10 ;
V_38 = F_37 ( V_6 -> V_13 . V_36 , true , & V_41 ) ;
V_10 = F_38 ( V_44 , V_38 , V_41 ) ;
if ( ! V_10 )
V_10 = F_38 ( V_44 , V_70 , F_55 ( V_70 ) ) ;
if ( F_42 ( V_10 ) ) {
F_17 ( ! V_10 -> V_52 ) ;
if ( F_42 ( V_10 -> V_52 ( V_6 , V_44 , V_10 ) ) ) {
F_43 ( V_6 , F_44 ( V_6 ) ) ;
return 1 ;
}
} else {
F_48 ( L_2 ,
* F_49 ( V_6 ) ) ;
F_50 ( V_44 ) ;
}
F_40 ( V_6 ) ;
return 1 ;
}
static void F_60 ( struct V_5 * V_6 ,
const struct V_9 * V_38 , T_3 V_41 )
{
unsigned long V_45 ;
for ( V_45 = 0 ; V_45 < V_41 ; V_45 ++ )
if ( V_38 [ V_45 ] . V_71 )
V_38 [ V_45 ] . V_71 ( V_6 , & V_38 [ V_45 ] ) ;
}
int F_61 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_7 V_44 ;
unsigned long V_72 = F_52 ( V_6 ) ;
V_44 . V_19 = false ;
V_44 . V_21 = false ;
V_44 . V_46 = ( V_72 >> 20 ) & 3 ;
V_44 . V_47 = ( V_72 >> 14 ) & 0x7 ;
V_44 . V_48 = ( V_72 >> 10 ) & 0xf ;
V_44 . V_18 = ( V_72 >> 1 ) & 0xf ;
V_44 . V_49 = ( V_72 >> 17 ) & 0x7 ;
V_44 . V_17 = ( V_72 >> 5 ) & 0x1f ;
V_44 . V_12 = ! ( V_72 & 1 ) ;
return F_59 ( V_6 , & V_44 ) ;
}
static bool F_62 ( T_2 V_73 , struct V_7 * V_44 )
{
switch ( V_73 & V_74 ) {
case V_75 :
if ( V_73 & ~ ( V_76 | V_74
| V_77
| V_78
| V_79
| V_80
| V_81
| V_82 ) )
return false ;
V_44 -> V_46 = ( ( V_73 & V_78 )
>> V_83 ) ;
V_44 -> V_47 = ( ( V_73 & V_79 )
>> V_84 ) ;
V_44 -> V_48 = ( ( V_73 & V_80 )
>> V_85 ) ;
V_44 -> V_18 = ( ( V_73 & V_81 )
>> V_86 ) ;
V_44 -> V_49 = ( ( V_73 & V_82 )
>> V_87 ) ;
return true ;
default:
return false ;
}
}
static const struct V_9 * F_63 ( struct V_5 * V_6 ,
T_2 V_73 )
{
T_3 V_41 ;
const struct V_9 * V_38 , * V_10 ;
struct V_7 V_44 ;
if ( ( V_73 & V_77 ) != V_88 )
return NULL ;
if ( ! F_62 ( V_73 , & V_44 ) )
return NULL ;
V_38 = F_37 ( V_6 -> V_13 . V_36 , true , & V_41 ) ;
V_10 = F_38 ( & V_44 , V_38 , V_41 ) ;
if ( ! V_10 )
V_10 = F_38 ( & V_44 , V_70 , F_55 ( V_70 ) ) ;
if ( V_10 && ! V_10 -> V_20 )
V_10 = NULL ;
return V_10 ;
}
static int F_64 ( T_2 * V_3 , const void T_5 * V_89 , T_2 V_73 )
{
if ( F_65 ( V_3 , V_89 , F_66 ( V_73 ) ) != 0 )
return - V_90 ;
return 0 ;
}
static int F_67 ( void T_5 * V_89 , const T_2 * V_3 , T_2 V_73 )
{
if ( F_68 ( V_89 , V_3 , F_66 ( V_73 ) ) != 0 )
return - V_90 ;
return 0 ;
}
static int F_69 ( T_2 V_73 , void T_5 * V_89 )
{
struct V_7 V_44 ;
const struct V_9 * V_10 ;
if ( ! F_62 ( V_73 , & V_44 ) )
return - V_91 ;
V_10 = F_38 ( & V_44 , V_92 , F_55 ( V_92 ) ) ;
if ( ! V_10 )
return - V_91 ;
return F_67 ( V_89 , & V_10 -> V_3 , V_73 ) ;
}
static int F_70 ( T_2 V_73 , void T_5 * V_89 )
{
struct V_7 V_44 ;
const struct V_9 * V_10 ;
int V_93 ;
T_2 V_3 = 0 ;
if ( ! F_62 ( V_73 , & V_44 ) )
return - V_91 ;
V_10 = F_38 ( & V_44 , V_92 , F_55 ( V_92 ) ) ;
if ( ! V_10 )
return - V_91 ;
V_93 = F_64 ( & V_3 , V_89 , V_73 ) ;
if ( V_93 )
return V_93 ;
if ( V_10 -> V_3 != V_3 )
return - V_94 ;
return 0 ;
}
static bool F_71 ( T_1 V_3 )
{
T_1 V_95 , V_96 ;
if ( V_3 >= V_97 )
return false ;
V_95 = ( V_3 >> 1 ) ;
V_96 = ( V_98 >> ( V_95 * 3 ) ) & 7 ;
switch ( V_96 ) {
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
static int F_72 ( T_2 V_73 , void T_5 * V_89 )
{
T_1 V_3 ;
T_1 T_5 * V_99 = V_89 ;
if ( V_73 & ~ ( V_76 | V_74 | V_77
| ( ( 1 << V_100 ) - 1 ) ) )
return - V_91 ;
switch ( V_73 & V_101 ) {
case V_102 :
if ( F_66 ( V_73 ) != 4 )
return - V_91 ;
V_3 = ( V_73 & V_103 )
>> V_104 ;
if ( ! F_71 ( V_3 ) )
return - V_91 ;
return F_73 ( F_1 ( V_3 ) , V_99 ) ;
default:
return - V_91 ;
}
}
static int F_74 ( T_2 V_73 , void T_5 * V_89 )
{
T_1 V_3 , V_105 ;
T_1 T_5 * V_99 = V_89 ;
if ( V_73 & ~ ( V_76 | V_74 | V_77
| ( ( 1 << V_100 ) - 1 ) ) )
return - V_91 ;
switch ( V_73 & V_101 ) {
case V_102 :
if ( F_66 ( V_73 ) != 4 )
return - V_91 ;
V_3 = ( V_73 & V_103 )
>> V_104 ;
if ( ! F_71 ( V_3 ) )
return - V_91 ;
if ( F_75 ( V_105 , V_99 ) )
return - V_90 ;
if ( V_105 != F_1 ( V_3 ) )
return - V_94 ;
return 0 ;
default:
return - V_91 ;
}
}
int F_76 ( struct V_5 * V_6 , const struct V_106 * V_20 )
{
const struct V_9 * V_10 ;
void T_5 * V_89 = ( void T_5 * ) ( unsigned long ) V_20 -> V_107 ;
if ( ( V_20 -> V_73 & V_77 ) == V_108 )
return F_72 ( V_20 -> V_73 , V_89 ) ;
if ( F_66 ( V_20 -> V_73 ) != sizeof( V_109 ) )
return - V_91 ;
V_10 = F_63 ( V_6 , V_20 -> V_73 ) ;
if ( ! V_10 )
return F_69 ( V_20 -> V_73 , V_89 ) ;
return F_67 ( V_89 , & F_18 ( V_6 , V_10 -> V_20 ) , V_20 -> V_73 ) ;
}
int F_77 ( struct V_5 * V_6 , const struct V_106 * V_20 )
{
const struct V_9 * V_10 ;
void T_5 * V_89 = ( void T_5 * ) ( unsigned long ) V_20 -> V_107 ;
if ( ( V_20 -> V_73 & V_77 ) == V_108 )
return F_74 ( V_20 -> V_73 , V_89 ) ;
if ( F_66 ( V_20 -> V_73 ) != sizeof( V_109 ) )
return - V_91 ;
V_10 = F_63 ( V_6 , V_20 -> V_73 ) ;
if ( ! V_10 )
return F_70 ( V_20 -> V_73 , V_89 ) ;
return F_64 ( & F_18 ( V_6 , V_10 -> V_20 ) , V_89 , V_20 -> V_73 ) ;
}
static unsigned int F_78 ( void )
{
unsigned int V_45 , V_110 = 0 ;
for ( V_45 = 0 ; V_45 < V_97 ; V_45 ++ )
if ( F_71 ( V_45 ) )
V_110 ++ ;
return V_110 ;
}
static int F_79 ( T_2 T_5 * V_111 )
{
T_2 V_3 = V_112 | V_113 | V_108 ;
unsigned int V_45 ;
V_3 |= V_102 ;
for ( V_45 = 0 ; V_45 < V_97 ; V_45 ++ ) {
if ( ! F_71 ( V_45 ) )
continue;
if ( F_73 ( V_3 | V_45 , V_111 ) )
return - V_90 ;
V_111 ++ ;
}
return 0 ;
}
static T_2 F_80 ( const struct V_9 * V_20 )
{
return ( V_112 | V_75 |
V_88 |
( V_20 -> V_46 << V_83 ) |
( V_20 -> V_47 << V_84 ) |
( V_20 -> V_48 << V_85 ) |
( V_20 -> V_18 << V_86 ) |
( V_20 -> V_49 << V_87 ) ) ;
}
static bool F_81 ( const struct V_9 * V_20 , T_2 T_5 * * V_114 )
{
if ( ! * V_114 )
return true ;
if ( F_73 ( F_80 ( V_20 ) , * V_114 ) )
return false ;
( * V_114 ) ++ ;
return true ;
}
static int F_82 ( struct V_5 * V_6 , T_2 T_5 * V_114 )
{
const struct V_9 * V_115 , * V_116 , * V_117 , * V_118 ;
unsigned int V_119 = 0 ;
T_3 V_41 ;
V_115 = F_37 ( V_6 -> V_13 . V_36 , true , & V_41 ) ;
V_117 = V_115 + V_41 ;
V_116 = V_70 ;
V_118 = V_70 + F_55 ( V_70 ) ;
F_17 ( V_115 == V_117 || V_116 == V_118 ) ;
while ( V_115 || V_116 ) {
int V_120 = F_83 ( V_115 , V_116 ) ;
if ( V_120 <= 0 ) {
if ( V_115 -> V_20 ) {
if ( ! F_81 ( V_115 , & V_114 ) )
return - V_90 ;
V_119 ++ ;
}
} else {
if ( V_116 -> V_20 ) {
if ( ! F_81 ( V_116 , & V_114 ) )
return - V_90 ;
V_119 ++ ;
}
}
if ( V_120 <= 0 && ++ V_115 == V_117 )
V_115 = NULL ;
if ( V_120 >= 0 && ++ V_116 == V_118 )
V_116 = NULL ;
}
return V_119 ;
}
unsigned long F_84 ( struct V_5 * V_6 )
{
return F_55 ( V_92 )
+ F_78 ()
+ F_82 ( V_6 , ( T_2 T_5 * ) NULL ) ;
}
int F_85 ( struct V_5 * V_6 , T_2 T_5 * V_111 )
{
unsigned int V_45 ;
int V_93 ;
for ( V_45 = 0 ; V_45 < F_55 ( V_92 ) ; V_45 ++ ) {
if ( F_73 ( F_80 ( & V_92 [ V_45 ] ) , V_111 ) )
return - V_90 ;
V_111 ++ ;
}
V_93 = F_82 ( V_6 , V_111 ) ;
if ( V_93 < 0 )
return V_93 ;
V_111 += V_93 ;
return F_79 ( V_111 ) ;
}
static int F_86 ( const struct V_9 * V_38 , unsigned int V_121 )
{
unsigned int V_45 ;
for ( V_45 = 1 ; V_45 < V_121 ; V_45 ++ ) {
if ( F_83 ( & V_38 [ V_45 - 1 ] , & V_38 [ V_45 ] ) >= 0 ) {
F_48 ( L_3 , V_38 , V_45 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_87 ( void )
{
unsigned int V_45 ;
struct V_9 V_122 ;
F_17 ( F_86 ( V_70 , F_55 ( V_70 ) ) ) ;
F_17 ( F_86 ( V_69 , F_55 ( V_69 ) ) ) ;
F_17 ( F_86 ( V_68 , F_55 ( V_68 ) ) ) ;
F_17 ( F_86 ( V_67 , F_55 ( V_67 ) ) ) ;
F_17 ( F_86 ( V_66 , F_55 ( V_66 ) ) ) ;
F_17 ( F_86 ( V_92 , F_55 ( V_92 ) ) ) ;
for ( V_45 = 0 ; V_45 < F_55 ( V_92 ) ; V_45 ++ )
V_92 [ V_45 ] . V_71 ( NULL , & V_92 [ V_45 ] ) ;
F_88 ( NULL , & V_122 ) ;
V_98 = V_122 . V_3 ;
for ( V_45 = 0 ; V_45 < 7 ; V_45 ++ )
if ( ( ( V_98 >> ( V_45 * 3 ) ) & 7 ) == 0 )
break;
V_98 &= ( 1 << ( V_45 * 3 ) ) - 1 ;
}
void F_89 ( struct V_5 * V_6 )
{
T_3 V_41 ;
const struct V_9 * V_38 ;
memset ( & V_6 -> V_13 . V_123 . V_124 , 0x42 , sizeof( V_6 -> V_13 . V_123 . V_124 ) ) ;
F_60 ( V_6 , V_70 , F_55 ( V_70 ) ) ;
V_38 = F_37 ( V_6 -> V_13 . V_36 , true , & V_41 ) ;
F_60 ( V_6 , V_38 , V_41 ) ;
for ( V_41 = 1 ; V_41 < V_125 ; V_41 ++ )
if ( F_18 ( V_6 , V_41 ) == 0x4242424242424242 )
F_90 ( L_4 , V_41 ) ;
}
