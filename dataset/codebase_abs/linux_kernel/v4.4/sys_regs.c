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
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
F_7 ( V_4 ) ;
return true ;
}
static bool F_8 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
bool V_10 = F_9 ( V_4 ) ;
F_10 ( ! V_6 -> V_9 ) ;
if ( ! V_6 -> V_11 ) {
F_11 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
} else {
if ( ! V_6 -> V_14 )
F_12 ( V_4 , V_8 -> V_12 ) = F_13 ( V_6 -> V_13 ) ;
F_14 ( V_4 , V_8 -> V_12 ) = F_15 ( V_6 -> V_13 ) ;
}
F_16 ( V_4 , V_10 ) ;
return true ;
}
static bool F_17 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
F_18 ( V_4 , V_6 -> V_13 ) ;
return true ;
}
static bool F_19 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 )
return F_20 ( V_4 , V_6 ) ;
else
return F_21 ( V_4 , V_6 ) ;
}
static bool F_22 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
V_6 -> V_13 = ( 1 << 3 ) ;
return true ;
}
}
static bool F_23 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
T_1 V_15 ;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
V_6 -> V_13 = V_15 ;
return true ;
}
}
static bool F_24 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_11 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
V_6 -> V_13 = F_11 ( V_4 , V_8 -> V_12 ) ;
}
F_25 ( V_19 , V_8 -> V_12 , V_6 -> V_9 , V_6 -> V_13 ) ;
return true ;
}
static inline void F_26 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_2 * V_20 )
{
T_2 V_15 = V_6 -> V_13 ;
if ( V_6 -> V_14 ) {
V_15 &= 0xffffffffUL ;
V_15 |= ( ( * V_20 >> 32 ) << 32 ) ;
}
* V_20 = V_15 ;
V_4 -> V_16 . V_17 |= V_18 ;
}
static inline void F_27 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_2 * V_20 )
{
V_6 -> V_13 = * V_20 ;
if ( V_6 -> V_14 )
V_6 -> V_13 &= 0xffffffffUL ;
}
static inline bool F_28 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_29 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_34 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static inline bool F_35 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_36 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_38 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static inline bool F_39 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 ,
V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ) ;
return true ;
}
static int F_40 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_42 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static inline bool F_43 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 )
F_26 ( V_4 , V_6 , V_20 ) ;
else
F_27 ( V_4 , V_6 , V_20 ) ;
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_44 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] ;
if ( F_30 ( V_8 , V_25 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_12 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] ;
if ( F_33 ( V_25 , V_8 , F_31 ( V_12 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_46 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_12 ] = V_21 -> V_15 ;
}
static void F_47 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_31 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_11 ( V_4 , V_32 ) = V_31 ;
}
static void F_48 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_33 ;
V_33 = ( V_4 -> V_34 & 0x0f ) << F_49 ( 0 ) ;
V_33 |= ( ( V_4 -> V_34 >> 4 ) & 0xff ) << F_49 ( 1 ) ;
V_33 |= ( ( V_4 -> V_34 >> 12 ) & 0xff ) << F_49 ( 2 ) ;
F_11 ( V_4 , V_35 ) = ( 1ULL << 31 ) | V_33 ;
}
static bool F_50 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_20 ( V_4 , V_6 ) ;
} else {
T_2 V_36 = F_51 ( V_37 ) ;
T_2 V_38 = F_51 ( V_39 ) ;
T_1 V_40 = ! ! F_52 ( V_38 , V_41 ) ;
V_6 -> V_13 = ( ( ( ( V_36 >> V_42 ) & 0xf ) << 28 ) |
( ( ( V_36 >> V_43 ) & 0xf ) << 24 ) |
( ( ( V_36 >> V_44 ) & 0xf ) << 20 )
| ( 6 << 16 ) | ( V_40 << 14 ) | ( V_40 << 12 ) ) ;
return true ;
}
}
static bool F_53 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_54 ( V_4 , V_8 -> V_12 ) = V_6 -> V_13 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
V_6 -> V_13 = F_54 ( V_4 , V_8 -> V_12 ) ;
}
return true ;
}
static inline bool F_55 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_12 ] ;
if ( V_6 -> V_9 ) {
T_2 V_15 = * V_20 ;
V_15 &= 0xffffffffUL ;
V_15 |= V_6 -> V_13 << 32 ;
* V_20 = V_15 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
V_6 -> V_13 = * V_20 >> 32 ;
}
F_25 ( V_19 , V_21 -> V_12 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
void F_56 ( unsigned int V_45 ,
struct V_46 * V_47 )
{
V_48 [ V_45 ] = V_47 ;
}
static const struct V_7 * F_57 ( unsigned V_45 ,
bool V_49 ,
T_5 * V_50 )
{
struct V_46 * V_47 ;
V_47 = V_48 [ V_45 ] ;
if ( V_49 ) {
* V_50 = V_47 -> V_51 . V_50 ;
return V_47 -> V_51 . V_47 ;
} else {
* V_50 = V_47 -> V_52 . V_50 ;
return V_47 -> V_52 . V_47 ;
}
}
static const struct V_7 * F_58 ( const struct V_5 * V_53 ,
const struct V_7 V_47 [] ,
unsigned int V_50 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_50 ; V_54 ++ ) {
const struct V_7 * V_8 = & V_47 [ V_54 ] ;
if ( V_53 -> V_55 != V_8 -> V_55 )
continue;
if ( V_53 -> V_56 != V_8 -> V_56 )
continue;
if ( V_53 -> V_57 != V_8 -> V_57 )
continue;
if ( V_53 -> V_58 != V_8 -> V_58 )
continue;
if ( V_53 -> V_59 != V_8 -> V_59 )
continue;
return V_8 ;
}
return NULL ;
}
int F_59 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
F_60 ( V_4 ) ;
return 1 ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_5 * V_53 ,
const struct V_7 * V_47 ,
T_5 V_50 )
{
const struct V_7 * V_8 ;
if ( ! V_47 )
return - 1 ;
V_8 = F_58 ( V_53 , V_47 , V_50 ) ;
if ( V_8 ) {
F_10 ( ! V_8 -> V_62 ) ;
if ( F_62 ( V_8 -> V_62 ( V_4 , V_53 , V_8 ) ) ) {
F_63 ( V_4 , F_64 ( V_4 ) ) ;
}
return 0 ;
}
return - 1 ;
}
static void F_65 ( struct V_3 * V_4 ,
struct V_5 * V_53 )
{
T_6 V_63 = F_66 ( V_4 ) ;
int V_64 ;
switch( V_63 ) {
case V_65 :
case V_66 :
V_64 = 15 ;
break;
case V_67 :
case V_68 :
V_64 = 14 ;
break;
default:
F_67 ( ( V_64 = - 1 ) ) ;
}
F_68 ( L_1 ,
V_64 , * F_69 ( V_4 ) ) ;
F_70 ( V_53 ) ;
F_60 ( V_4 ) ;
}
static int F_71 ( struct V_3 * V_4 ,
const struct V_7 * V_69 ,
T_5 V_70 ,
const struct V_7 * V_71 ,
T_5 V_72 )
{
struct V_5 V_53 ;
T_1 V_73 = F_72 ( V_4 ) ;
int V_74 = ( V_73 >> 5 ) & 0xf ;
int V_75 = ( V_73 >> 10 ) & 0xf ;
V_53 . V_11 = true ;
V_53 . V_14 = false ;
V_53 . V_58 = ( V_73 >> 1 ) & 0xf ;
V_53 . V_9 = ( ( V_73 & 1 ) == 0 ) ;
V_53 . V_55 = 0 ;
V_53 . V_56 = ( V_73 >> 16 ) & 0xf ;
V_53 . V_59 = 0 ;
V_53 . V_57 = 0 ;
if ( V_53 . V_9 ) {
V_53 . V_13 = F_73 ( V_4 , V_74 ) & 0xffffffff ;
V_53 . V_13 |= F_73 ( V_4 , V_75 ) << 32 ;
}
if ( ! F_61 ( V_4 , & V_53 , V_71 , V_72 ) )
goto V_76;
if ( ! F_61 ( V_4 , & V_53 , V_69 , V_70 ) )
goto V_76;
F_65 ( V_4 , & V_53 ) ;
V_76:
if ( ! V_53 . V_9 ) {
F_74 ( V_4 , V_74 , F_15 ( V_53 . V_13 ) ) ;
F_74 ( V_4 , V_75 , F_13 ( V_53 . V_13 ) ) ;
}
return 1 ;
}
static int F_75 ( struct V_3 * V_4 ,
const struct V_7 * V_69 ,
T_5 V_70 ,
const struct V_7 * V_71 ,
T_5 V_72 )
{
struct V_5 V_53 ;
T_1 V_73 = F_72 ( V_4 ) ;
int V_74 = ( V_73 >> 5 ) & 0xf ;
V_53 . V_11 = true ;
V_53 . V_14 = true ;
V_53 . V_58 = ( V_73 >> 1 ) & 0xf ;
V_53 . V_13 = F_73 ( V_4 , V_74 ) ;
V_53 . V_9 = ( ( V_73 & 1 ) == 0 ) ;
V_53 . V_57 = ( V_73 >> 10 ) & 0xf ;
V_53 . V_55 = 0 ;
V_53 . V_56 = ( V_73 >> 14 ) & 0x7 ;
V_53 . V_59 = ( V_73 >> 17 ) & 0x7 ;
if ( ! F_61 ( V_4 , & V_53 , V_71 , V_72 ) ||
! F_61 ( V_4 , & V_53 , V_69 , V_70 ) ) {
if ( ! V_53 . V_9 )
F_74 ( V_4 , V_74 , V_53 . V_13 ) ;
return 1 ;
}
F_65 ( V_4 , & V_53 ) ;
return 1 ;
}
int F_76 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
const struct V_7 * V_71 ;
T_5 V_50 ;
V_71 = F_57 ( V_4 -> V_16 . V_45 , false , & V_50 ) ;
return F_71 ( V_4 ,
V_77 , F_77 ( V_77 ) ,
V_71 , V_50 ) ;
}
int F_78 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
const struct V_7 * V_71 ;
T_5 V_50 ;
V_71 = F_57 ( V_4 -> V_16 . V_45 , false , & V_50 ) ;
return F_75 ( V_4 ,
V_78 , F_77 ( V_78 ) ,
V_71 , V_50 ) ;
}
int F_79 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
return F_71 ( V_4 ,
V_79 , F_77 ( V_79 ) ,
NULL , 0 ) ;
}
int F_80 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
return F_75 ( V_4 ,
V_80 , F_77 ( V_80 ) ,
NULL , 0 ) ;
}
static int F_81 ( struct V_3 * V_4 ,
struct V_5 * V_53 )
{
T_5 V_50 ;
const struct V_7 * V_47 , * V_8 ;
V_47 = F_57 ( V_4 -> V_16 . V_45 , true , & V_50 ) ;
V_8 = F_58 ( V_53 , V_47 , V_50 ) ;
if ( ! V_8 )
V_8 = F_58 ( V_53 , V_81 , F_77 ( V_81 ) ) ;
if ( F_62 ( V_8 ) ) {
F_10 ( ! V_8 -> V_62 ) ;
if ( F_62 ( V_8 -> V_62 ( V_4 , V_53 , V_8 ) ) ) {
F_63 ( V_4 , F_64 ( V_4 ) ) ;
return 1 ;
}
} else {
F_68 ( L_2 ,
* F_69 ( V_4 ) ) ;
F_70 ( V_53 ) ;
}
F_60 ( V_4 ) ;
return 1 ;
}
static void F_82 ( struct V_3 * V_4 ,
const struct V_7 * V_47 , T_5 V_50 )
{
unsigned long V_54 ;
for ( V_54 = 0 ; V_54 < V_50 ; V_54 ++ )
if ( V_47 [ V_54 ] . V_82 )
V_47 [ V_54 ] . V_82 ( V_4 , & V_47 [ V_54 ] ) ;
}
int F_83 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
struct V_5 V_53 ;
unsigned long V_83 = F_72 ( V_4 ) ;
int V_74 = ( V_83 >> 5 ) & 0x1f ;
int V_84 ;
F_84 ( V_83 ) ;
V_53 . V_11 = false ;
V_53 . V_14 = false ;
V_53 . V_55 = ( V_83 >> 20 ) & 3 ;
V_53 . V_56 = ( V_83 >> 14 ) & 0x7 ;
V_53 . V_57 = ( V_83 >> 10 ) & 0xf ;
V_53 . V_58 = ( V_83 >> 1 ) & 0xf ;
V_53 . V_59 = ( V_83 >> 17 ) & 0x7 ;
V_53 . V_13 = F_73 ( V_4 , V_74 ) ;
V_53 . V_9 = ! ( V_83 & 1 ) ;
V_84 = F_81 ( V_4 , & V_53 ) ;
if ( ! V_53 . V_9 )
F_74 ( V_4 , V_74 , V_53 . V_13 ) ;
return V_84 ;
}
static bool F_85 ( T_2 V_26 , struct V_5 * V_53 )
{
switch ( V_26 & V_85 ) {
case V_86 :
if ( V_26 & ~ ( V_87 | V_85
| V_88
| V_89
| V_90
| V_91
| V_92
| V_93 ) )
return false ;
V_53 -> V_55 = ( ( V_26 & V_89 )
>> V_94 ) ;
V_53 -> V_56 = ( ( V_26 & V_90 )
>> V_95 ) ;
V_53 -> V_57 = ( ( V_26 & V_91 )
>> V_96 ) ;
V_53 -> V_58 = ( ( V_26 & V_92 )
>> V_97 ) ;
V_53 -> V_59 = ( ( V_26 & V_93 )
>> V_98 ) ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_86 ( struct V_3 * V_4 ,
T_2 V_26 )
{
T_5 V_50 ;
const struct V_7 * V_47 , * V_8 ;
struct V_5 V_53 ;
if ( ( V_26 & V_88 ) != V_99 )
return NULL ;
if ( ! F_85 ( V_26 , & V_53 ) )
return NULL ;
V_47 = F_57 ( V_4 -> V_16 . V_45 , true , & V_50 ) ;
V_8 = F_58 ( & V_53 , V_47 , V_50 ) ;
if ( ! V_8 )
V_8 = F_58 ( & V_53 , V_81 , F_77 ( V_81 ) ) ;
if ( V_8 && ! V_8 -> V_12 )
V_8 = NULL ;
return V_8 ;
}
static int F_87 ( T_2 * V_15 , const void T_3 * V_25 , T_2 V_26 )
{
if ( F_30 ( V_15 , V_25 , F_31 ( V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_88 ( void T_3 * V_25 , const T_2 * V_15 , T_2 V_26 )
{
if ( F_33 ( V_25 , V_15 , F_31 ( V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_89 ( T_2 V_26 , void T_3 * V_25 )
{
struct V_5 V_53 ;
const struct V_7 * V_8 ;
if ( ! F_85 ( V_26 , & V_53 ) )
return - V_100 ;
V_8 = F_58 ( & V_53 , V_101 , F_77 ( V_101 ) ) ;
if ( ! V_8 )
return - V_100 ;
return F_88 ( V_25 , & V_8 -> V_15 , V_26 ) ;
}
static int F_90 ( T_2 V_26 , void T_3 * V_25 )
{
struct V_5 V_53 ;
const struct V_7 * V_8 ;
int V_102 ;
T_2 V_15 = 0 ;
if ( ! F_85 ( V_26 , & V_53 ) )
return - V_100 ;
V_8 = F_58 ( & V_53 , V_101 , F_77 ( V_101 ) ) ;
if ( ! V_8 )
return - V_100 ;
V_102 = F_87 ( & V_15 , V_25 , V_26 ) ;
if ( V_102 )
return V_102 ;
if ( V_8 -> V_15 != V_15 )
return - V_103 ;
return 0 ;
}
static bool F_91 ( T_1 V_15 )
{
T_1 V_104 , V_105 ;
if ( V_15 >= V_106 )
return false ;
V_104 = ( V_15 >> 1 ) ;
V_105 = ( V_107 >> ( V_104 * 3 ) ) & 7 ;
switch ( V_105 ) {
case 0 :
return false ;
case 1 :
return ( V_15 & 1 ) ;
case 2 :
case 4 :
return ! ( V_15 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_92 ( T_2 V_26 , void T_3 * V_25 )
{
T_1 V_15 ;
T_1 T_3 * V_108 = V_25 ;
if ( V_26 & ~ ( V_87 | V_85 | V_88
| ( ( 1 << V_109 ) - 1 ) ) )
return - V_100 ;
switch ( V_26 & V_110 ) {
case V_111 :
if ( F_31 ( V_26 ) != 4 )
return - V_100 ;
V_15 = ( V_26 & V_112 )
>> V_113 ;
if ( ! F_91 ( V_15 ) )
return - V_100 ;
return F_93 ( F_1 ( V_15 ) , V_108 ) ;
default:
return - V_100 ;
}
}
static int F_94 ( T_2 V_26 , void T_3 * V_25 )
{
T_1 V_15 , V_114 ;
T_1 T_3 * V_108 = V_25 ;
if ( V_26 & ~ ( V_87 | V_85 | V_88
| ( ( 1 << V_109 ) - 1 ) ) )
return - V_100 ;
switch ( V_26 & V_110 ) {
case V_111 :
if ( F_31 ( V_26 ) != 4 )
return - V_100 ;
V_15 = ( V_26 & V_112 )
>> V_113 ;
if ( ! F_91 ( V_15 ) )
return - V_100 ;
if ( F_95 ( V_114 , V_108 ) )
return - V_27 ;
if ( V_114 != F_1 ( V_15 ) )
return - V_103 ;
return 0 ;
default:
return - V_100 ;
}
}
int F_96 ( struct V_3 * V_4 , const struct V_24 * V_12 )
{
const struct V_7 * V_8 ;
void T_3 * V_25 = ( void T_3 * ) ( unsigned long ) V_12 -> V_115 ;
if ( ( V_12 -> V_26 & V_88 ) == V_116 )
return F_92 ( V_12 -> V_26 , V_25 ) ;
if ( F_31 ( V_12 -> V_26 ) != sizeof( T_4 ) )
return - V_100 ;
V_8 = F_86 ( V_4 , V_12 -> V_26 ) ;
if ( ! V_8 )
return F_89 ( V_12 -> V_26 , V_25 ) ;
if ( V_8 -> F_95 )
return ( V_8 -> F_95 ) ( V_4 , V_8 , V_12 , V_25 ) ;
return F_88 ( V_25 , & F_11 ( V_4 , V_8 -> V_12 ) , V_12 -> V_26 ) ;
}
int F_97 ( struct V_3 * V_4 , const struct V_24 * V_12 )
{
const struct V_7 * V_8 ;
void T_3 * V_25 = ( void T_3 * ) ( unsigned long ) V_12 -> V_115 ;
if ( ( V_12 -> V_26 & V_88 ) == V_116 )
return F_94 ( V_12 -> V_26 , V_25 ) ;
if ( F_31 ( V_12 -> V_26 ) != sizeof( T_4 ) )
return - V_100 ;
V_8 = F_86 ( V_4 , V_12 -> V_26 ) ;
if ( ! V_8 )
return F_90 ( V_12 -> V_26 , V_25 ) ;
if ( V_8 -> V_117 )
return ( V_8 -> V_117 ) ( V_4 , V_8 , V_12 , V_25 ) ;
return F_87 ( & F_11 ( V_4 , V_8 -> V_12 ) , V_25 , V_12 -> V_26 ) ;
}
static unsigned int F_98 ( void )
{
unsigned int V_54 , V_118 = 0 ;
for ( V_54 = 0 ; V_54 < V_106 ; V_54 ++ )
if ( F_91 ( V_54 ) )
V_118 ++ ;
return V_118 ;
}
static int F_99 ( T_2 T_3 * V_119 )
{
T_2 V_15 = V_120 | V_121 | V_116 ;
unsigned int V_54 ;
V_15 |= V_111 ;
for ( V_54 = 0 ; V_54 < V_106 ; V_54 ++ ) {
if ( ! F_91 ( V_54 ) )
continue;
if ( F_93 ( V_15 | V_54 , V_119 ) )
return - V_27 ;
V_119 ++ ;
}
return 0 ;
}
static T_2 F_100 ( const struct V_7 * V_12 )
{
return ( V_120 | V_86 |
V_99 |
( V_12 -> V_55 << V_94 ) |
( V_12 -> V_56 << V_95 ) |
( V_12 -> V_57 << V_96 ) |
( V_12 -> V_58 << V_97 ) |
( V_12 -> V_59 << V_98 ) ) ;
}
static bool F_101 ( const struct V_7 * V_12 , T_2 T_3 * * V_122 )
{
if ( ! * V_122 )
return true ;
if ( F_93 ( F_100 ( V_12 ) , * V_122 ) )
return false ;
( * V_122 ) ++ ;
return true ;
}
static int F_102 ( struct V_3 * V_4 , T_2 T_3 * V_122 )
{
const struct V_7 * V_123 , * V_124 , * V_125 , * V_126 ;
unsigned int V_127 = 0 ;
T_5 V_50 ;
V_123 = F_57 ( V_4 -> V_16 . V_45 , true , & V_50 ) ;
V_125 = V_123 + V_50 ;
V_124 = V_81 ;
V_126 = V_81 + F_77 ( V_81 ) ;
F_10 ( V_123 == V_125 || V_124 == V_126 ) ;
while ( V_123 || V_124 ) {
int V_128 = F_103 ( V_123 , V_124 ) ;
if ( V_128 <= 0 ) {
if ( V_123 -> V_12 ) {
if ( ! F_101 ( V_123 , & V_122 ) )
return - V_27 ;
V_127 ++ ;
}
} else {
if ( V_124 -> V_12 ) {
if ( ! F_101 ( V_124 , & V_122 ) )
return - V_27 ;
V_127 ++ ;
}
}
if ( V_128 <= 0 && ++ V_123 == V_125 )
V_123 = NULL ;
if ( V_128 >= 0 && ++ V_124 == V_126 )
V_124 = NULL ;
}
return V_127 ;
}
unsigned long F_104 ( struct V_3 * V_4 )
{
return F_77 ( V_101 )
+ F_98 ()
+ F_102 ( V_4 , ( T_2 T_3 * ) NULL ) ;
}
int F_105 ( struct V_3 * V_4 , T_2 T_3 * V_119 )
{
unsigned int V_54 ;
int V_102 ;
for ( V_54 = 0 ; V_54 < F_77 ( V_101 ) ; V_54 ++ ) {
if ( F_93 ( F_100 ( & V_101 [ V_54 ] ) , V_119 ) )
return - V_27 ;
V_119 ++ ;
}
V_102 = F_102 ( V_4 , V_119 ) ;
if ( V_102 < 0 )
return V_102 ;
V_119 += V_102 ;
return F_99 ( V_119 ) ;
}
static int F_106 ( const struct V_7 * V_47 , unsigned int V_129 )
{
unsigned int V_54 ;
for ( V_54 = 1 ; V_54 < V_129 ; V_54 ++ ) {
if ( F_103 ( & V_47 [ V_54 - 1 ] , & V_47 [ V_54 ] ) >= 0 ) {
F_68 ( L_3 , V_47 , V_54 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_107 ( void )
{
unsigned int V_54 ;
struct V_7 V_130 ;
F_10 ( F_106 ( V_81 , F_77 ( V_81 ) ) ) ;
F_10 ( F_106 ( V_80 , F_77 ( V_80 ) ) ) ;
F_10 ( F_106 ( V_79 , F_77 ( V_79 ) ) ) ;
F_10 ( F_106 ( V_78 , F_77 ( V_78 ) ) ) ;
F_10 ( F_106 ( V_77 , F_77 ( V_77 ) ) ) ;
F_10 ( F_106 ( V_101 , F_77 ( V_101 ) ) ) ;
for ( V_54 = 0 ; V_54 < F_77 ( V_101 ) ; V_54 ++ )
V_101 [ V_54 ] . V_82 ( NULL , & V_101 [ V_54 ] ) ;
F_108 ( NULL , & V_130 ) ;
V_107 = V_130 . V_15 ;
for ( V_54 = 0 ; V_54 < 7 ; V_54 ++ )
if ( ( ( V_107 >> ( V_54 * 3 ) ) & 7 ) == 0 )
break;
V_107 &= ( 1 << ( V_54 * 3 ) ) - 1 ;
}
void F_109 ( struct V_3 * V_4 )
{
T_5 V_50 ;
const struct V_7 * V_47 ;
memset ( & V_4 -> V_16 . V_131 . V_132 , 0x42 , sizeof( V_4 -> V_16 . V_131 . V_132 ) ) ;
F_82 ( V_4 , V_81 , F_77 ( V_81 ) ) ;
V_47 = F_57 ( V_4 -> V_16 . V_45 , true , & V_50 ) ;
F_82 ( V_4 , V_47 , V_50 ) ;
for ( V_50 = 1 ; V_50 < V_133 ; V_50 ++ )
if ( F_11 ( V_4 , V_50 ) == 0x4242424242424242 )
F_110 ( L_4 , V_50 ) ;
}
