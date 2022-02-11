static void F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
unsigned char V_5 = 0 ;
if ( V_3 != 0xff )
V_5 = F_2 ( F_3 ( V_2 ) ) ;
F_4 ( V_6 L_1 ,
V_3 , V_4 , V_5 , ( V_5 & ~ V_3 ) ^ V_4 ) ;
F_5 ( ( V_5 & ~ V_3 ) ^ V_4 , F_3 ( V_2 ) ) ;
}
static inline void F_6 ( struct V_1 * V_7 , int V_8 )
{
F_1 ( V_7 , V_9 , V_8 << 5 ) ;
}
static int F_7 ( struct V_1 * V_7 , int V_3 )
{
const struct V_10 * V_11 = V_7 -> V_12 -> V_13 ;
unsigned char V_14 ;
int V_8 ;
F_4 ( V_15 L_2 , V_3 ) ;
if ( ! V_11 -> V_16 ) {
F_8 ( V_6 L_3 ) ;
return 0 ;
}
V_14 = F_2 ( F_3 ( V_7 ) ) ;
V_8 = ( V_14 >> 5 ) & 0x7 ;
if ( V_8 == V_3 )
return 0 ;
if ( V_8 >= 2 && ! ( V_11 -> V_17 & 0x20 ) ) {
unsigned long V_18 = V_19 + V_7 -> V_12 -> V_20 -> V_21 ;
int V_22 ;
switch ( V_8 ) {
case V_23 :
case V_24 :
for ( V_22 = 0 ; V_22 < 40 ; V_22 ++ ) {
if ( F_2 ( F_3 ( V_7 ) ) & 0x01 )
break;
if ( F_9 ( V_25 ) )
break;
F_10 ( 5 ) ;
}
while ( ! ( F_2 ( F_3 ( V_7 ) ) & 0x01 ) ) {
if ( F_11 ( V_19 , V_18 ) )
return - V_26 ;
F_12 (
F_13 ( 10 ) ) ;
if ( F_9 ( V_25 ) )
break;
}
}
}
if ( V_8 >= 2 && V_3 >= 2 ) {
V_14 &= ~ ( 7 << 5 ) ;
V_14 |= V_27 << 5 ;
F_14 ( V_7 , V_14 ) ;
}
V_14 &= ~ ( 7 << 5 ) ;
V_14 |= V_3 << 5 ;
F_14 ( V_7 , V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned char V_28 ;
if ( ! ( F_16 ( V_2 ) & 0x01 ) )
return 1 ;
F_16 ( V_2 ) ;
V_28 = F_16 ( V_2 ) ;
F_5 ( V_28 | 0x01 , F_17 ( V_2 ) ) ;
F_5 ( V_28 & 0xfe , F_17 ( V_2 ) ) ;
V_28 = F_16 ( V_2 ) ;
return ! ( V_28 & 0x01 ) ;
}
static void F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> V_33 . V_34 . V_17 = 0xc ;
if ( V_30 -> V_35 &&
V_30 -> V_36 -> V_37 != V_38 )
V_32 -> V_33 . V_34 . V_17 |= 0x10 ;
V_32 -> V_33 . V_34 . V_16 = 0x34 ;
}
static void F_19 ( struct V_1 * V_7 , struct V_31 * V_32 )
{
const struct V_10 * V_11 = V_7 -> V_12 -> V_13 ;
V_32 -> V_33 . V_34 . V_17 = V_11 -> V_17 ;
if ( V_11 -> V_16 )
V_32 -> V_33 . V_34 . V_16 = F_2 ( F_3 ( V_7 ) ) ;
}
static void F_20 ( struct V_1 * V_7 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = V_7 -> V_12 -> V_13 ;
register unsigned char V_39 = V_32 -> V_33 . V_34 . V_17 & V_11 -> V_40 ;
F_5 ( V_39 , F_21 ( V_7 ) ) ;
V_11 -> V_17 = V_39 ;
if ( V_11 -> V_16 )
F_14 ( V_7 , V_32 -> V_33 . V_34 . V_16 ) ;
}
static T_1 F_22 ( struct V_1 * V_36 , void * V_41 ,
T_1 V_42 , int V_43 )
{
T_1 V_44 = 0 ;
if ( V_43 & V_45 ) {
unsigned char V_46 ;
T_1 V_47 = V_42 ;
V_46 = F_2 ( F_17 ( V_36 ) ) ;
while ( ! ( V_46 & 0x08 ) && V_44 < V_42 ) {
if ( V_47 >= 16 && ( V_46 & 0x20 ) && ! ( V_46 & 0x08 ) ) {
if ( ! ( ( long ) V_41 & 0x03 ) )
F_23 ( F_24 ( V_36 ) , V_41 , 4 ) ;
else
F_25 ( F_24 ( V_36 ) , V_41 , 16 ) ;
V_41 += 16 ;
V_44 += 16 ;
V_47 -= 16 ;
} else {
* ( ( char * ) V_41 ) = F_2 ( F_24 ( V_36 ) ) ;
V_41 ++ ;
V_44 ++ ;
V_47 -- ;
}
V_46 = F_2 ( F_17 ( V_36 ) ) ;
if ( V_46 & 0x01 ) {
F_8 ( V_6
L_4 , V_36 -> V_48 ) ;
F_15 ( V_36 ) ;
}
}
return V_44 ;
}
if ( ( V_43 & V_49 ) && ( V_42 > 1 ) ) {
if ( ! ( ( ( long ) V_41 | V_42 ) & 0x03 ) )
F_23 ( F_24 ( V_36 ) , V_41 , ( V_42 >> 2 ) ) ;
else
F_25 ( F_24 ( V_36 ) , V_41 , V_42 ) ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
return - V_50 ;
}
return V_42 ;
}
for (; V_44 < V_42 ; V_44 ++ ) {
* ( ( char * ) V_41 ) = F_2 ( F_24 ( V_36 ) ) ;
V_41 ++ ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
break;
}
}
return V_44 ;
}
static T_1 F_26 ( struct V_1 * V_36 , const void * V_41 ,
T_1 V_42 , int V_43 )
{
T_1 V_51 = 0 ;
if ( ( V_43 & V_49 ) && ( V_42 > 1 ) ) {
if ( ! ( ( ( long ) V_41 | V_42 ) & 0x03 ) )
F_27 ( F_24 ( V_36 ) , V_41 , ( V_42 >> 2 ) ) ;
else
F_28 ( F_24 ( V_36 ) , V_41 , V_42 ) ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
return - V_50 ;
}
return V_42 ;
}
for (; V_51 < V_42 ; V_51 ++ ) {
F_5 ( * ( ( char * ) V_41 ) , F_24 ( V_36 ) ) ;
V_41 ++ ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
break;
}
}
return V_51 ;
}
static T_1 F_29 ( struct V_1 * V_36 , void * V_41 ,
T_1 V_42 , int V_43 )
{
T_1 V_44 = 0 ;
if ( ( V_43 & V_49 ) && ( V_42 > 1 ) ) {
F_25 ( F_30 ( V_36 ) , V_41 , V_42 ) ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
return - V_50 ;
}
return V_42 ;
}
for (; V_44 < V_42 ; V_44 ++ ) {
* ( ( char * ) V_41 ) = F_2 ( F_30 ( V_36 ) ) ;
V_41 ++ ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
break;
}
}
return V_44 ;
}
static T_1 F_31 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 ,
int V_43 )
{
T_1 V_51 = 0 ;
if ( ( V_43 & V_49 ) && ( V_42 > 1 ) ) {
F_28 ( F_30 ( V_36 ) , V_41 , V_42 ) ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
return - V_50 ;
}
return V_42 ;
}
for (; V_51 < V_42 ; V_51 ++ ) {
F_5 ( * ( ( char * ) V_41 ) , F_30 ( V_36 ) ) ;
V_41 ++ ;
if ( F_2 ( F_17 ( V_36 ) ) & 0x01 ) {
F_15 ( V_36 ) ;
break;
}
}
return V_51 ;
}
static T_1 F_32 ( struct V_1 * V_36 , void * V_41 ,
T_1 V_42 , int V_43 )
{
T_1 V_44 ;
F_6 ( V_36 , V_52 ) ;
F_33 ( V_36 ) ;
F_34 ( V_36 , 0x4 ) ;
V_44 = F_22 ( V_36 , V_41 , V_42 , V_43 ) ;
F_6 ( V_36 , V_27 ) ;
return V_44 ;
}
static T_1 F_35 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 ,
int V_43 )
{
T_1 V_51 ;
F_6 ( V_36 , V_52 ) ;
F_34 ( V_36 , 0x4 ) ;
F_36 ( V_36 ) ;
V_51 = F_26 ( V_36 , V_41 , V_42 , V_43 ) ;
F_6 ( V_36 , V_27 ) ;
return V_51 ;
}
static T_1 F_37 ( struct V_1 * V_36 , void * V_41 ,
T_1 V_42 , int V_43 )
{
T_1 V_44 ;
F_6 ( V_36 , V_52 ) ;
F_33 ( V_36 ) ;
F_34 ( V_36 , 0x4 ) ;
V_44 = F_29 ( V_36 , V_41 , V_42 , V_43 ) ;
F_6 ( V_36 , V_27 ) ;
return V_44 ;
}
static T_1 F_38 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 ,
int V_43 )
{
T_1 V_51 ;
F_6 ( V_36 , V_52 ) ;
F_34 ( V_36 , 0x4 ) ;
F_36 ( V_36 ) ;
V_51 = F_31 ( V_36 , V_41 , V_42 , V_43 ) ;
F_6 ( V_36 , V_27 ) ;
return V_51 ;
}
static T_1 F_39 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 )
{
int V_53 = 0 ;
const unsigned char * V_54 = V_41 ;
T_1 V_47 = V_42 ;
unsigned long V_18 = V_19 + V_36 -> V_12 -> V_20 -> V_21 ;
const int V_55 = F_40 ( V_36 ) ;
int V_56 = 8 ;
const struct V_10 * V_11 = V_36 -> V_12 -> V_13 ;
const int V_57 = V_11 -> V_57 ;
V_36 = V_36 -> V_12 ;
F_41 ( V_36 ) ;
F_1 ( V_36 , ( 1 << 4 ) | ( 1 << 2 ) , ( 1 << 4 ) | ( 1 << 2 ) ) ;
F_36 ( V_36 ) ;
while ( V_47 ) {
unsigned char V_58 ;
unsigned char V_59 = F_2 ( F_3 ( V_36 ) ) ;
int V_60 = 0 ;
if ( F_42 () && F_43 ( V_19 , V_18 ) )
F_44 () ;
if ( V_36 -> V_61 ) {
F_8 ( V_6 L_5 ) ;
break;
}
if ( V_59 & 0x02 ) {
F_14 ( V_36 , V_59 & ~ ( 1 << 2 ) ) ;
V_62:
V_53 = F_45 ( V_36 , V_63 ) ;
if ( V_53 < 0 )
break;
V_53 = 0 ;
if ( ! F_43 ( V_19 , V_18 ) ) {
F_8 ( V_6 L_6 ) ;
break;
}
V_59 = F_2 ( F_3 ( V_36 ) ) ;
if ( ! ( V_59 & ( 1 << 2 ) ) ) {
if ( F_42 () &&
F_43 ( V_19 , V_18 ) )
F_44 () ;
goto V_62;
}
continue;
}
V_18 = V_19 + V_36 -> V_20 -> V_21 ;
V_64:
if ( F_9 ( V_25 ) )
break;
if ( V_59 & 0x01 ) {
const int V_65 = V_47 < V_57 ? V_47 : V_57 ;
F_28 ( V_55 , V_54 , V_65 ) ;
V_54 += V_65 ;
V_47 -= V_65 ;
if ( V_60 < ( V_56 - 2 ) )
V_56 -- ;
continue;
} else if ( V_60 ++ < V_56 ) {
F_10 ( 10 ) ;
V_59 = F_2 ( F_3 ( V_36 ) ) ;
goto V_64;
}
V_58 = * V_54 ++ ;
F_5 ( V_58 , V_55 ) ;
V_47 -- ;
}
F_46 ( L_7 , V_36 ) ;
return V_42 - V_47 ;
}
static T_1 F_47 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 )
{
int V_53 = 0 ;
unsigned long V_66 ;
T_1 V_47 = V_42 ;
const struct V_10 * V_11 = V_36 -> V_12 -> V_13 ;
struct V_67 * V_30 = V_36 -> V_12 -> V_30 ;
T_2 V_68 , V_69 ;
T_1 V_70 = 0x10000 ;
unsigned long V_71 = ( unsigned long ) V_41 ;
unsigned long V_72 = ( unsigned long ) V_41 + V_42 - 1 ;
F_46 ( L_8 , V_36 ) ;
if ( V_72 < V_73 ) {
if ( ( V_71 ^ V_72 ) & ~ 0xffffUL )
V_70 = 0x10000 - ( V_71 & 0xffff ) ;
V_68 = V_69 = F_48 ( V_30 , ( void * ) V_41 , V_42 ,
V_74 ) ;
} else {
V_70 = V_75 ;
V_68 = V_11 -> V_69 ;
V_69 = 0 ;
}
V_36 = V_36 -> V_12 ;
F_41 ( V_36 ) ;
F_1 ( V_36 , ( 1 << 4 ) | ( 1 << 2 ) , ( 1 << 4 ) | ( 1 << 2 ) ) ;
F_36 ( V_36 ) ;
while ( V_47 ) {
unsigned long V_18 = V_19 + V_36 -> V_12 -> V_20 -> V_21 ;
T_1 V_76 = V_47 ;
if ( V_76 > V_70 )
V_76 = V_70 ;
if ( ! V_69 )
memcpy ( V_11 -> V_77 , V_41 , V_76 ) ;
V_66 = F_49 () ;
F_50 ( V_36 -> V_78 ) ;
F_51 ( V_36 -> V_78 ) ;
F_52 ( V_36 -> V_78 , V_79 ) ;
F_53 ( V_36 -> V_78 , V_68 ) ;
F_54 ( V_36 -> V_78 , V_76 ) ;
F_1 ( V_36 , 1 << 3 , 1 << 3 ) ;
F_1 ( V_36 , 1 << 2 , 0 ) ;
F_55 ( V_36 -> V_78 ) ;
F_56 ( V_66 ) ;
V_47 -= V_76 ;
V_41 += V_76 ;
if ( V_69 )
V_68 += V_76 ;
V_62:
V_53 = F_45 ( V_36 , V_63 ) ;
if ( V_53 < 0 )
break;
V_53 = 0 ;
if ( ! F_43 ( V_19 , V_18 ) ) {
F_8 ( V_6 L_9 ) ;
break;
}
if ( ! ( F_2 ( F_3 ( V_36 ) ) & ( 1 << 2 ) ) ) {
F_57 () ;
goto V_62;
}
V_66 = F_49 () ;
F_50 ( V_36 -> V_78 ) ;
F_51 ( V_36 -> V_78 ) ;
V_76 = F_58 ( V_36 -> V_78 ) ;
F_56 ( V_66 ) ;
F_57 () ;
if ( V_36 -> V_61 ) {
F_8 ( V_6 L_5 ) ;
break;
}
V_41 -= V_76 ;
V_47 += V_76 ;
if ( V_69 )
V_68 -= V_76 ;
}
V_66 = F_49 () ;
F_50 ( V_36 -> V_78 ) ;
F_51 ( V_36 -> V_78 ) ;
V_47 += F_58 ( V_36 -> V_78 ) ;
F_56 ( V_66 ) ;
F_1 ( V_36 , 1 << 3 , 0 ) ;
if ( V_69 )
F_59 ( V_30 , V_69 , V_42 , V_74 ) ;
F_46 ( L_10 , V_36 ) ;
return V_42 - V_47 ;
}
static inline T_1 F_60 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 )
{
#ifdef F_61
if ( V_36 -> V_78 != V_80 )
return F_47 ( V_36 , V_41 , V_42 ) ;
#endif
return F_39 ( V_36 , V_41 , V_42 ) ;
}
static T_1 F_62 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 ,
int V_43 )
{
T_1 V_51 ;
int V_28 ;
unsigned long V_18 ;
const struct V_10 * V_11 = V_36 -> V_12 -> V_13 ;
if ( V_36 -> V_12 -> V_20 -> V_21 <= V_81 )
return F_63 ( V_36 , V_41 ,
V_42 , V_43 ) ;
F_36 ( V_36 ) ;
F_64 ( V_36 , V_82 , 0 ) ;
V_28 = F_7 ( V_36 , V_23 ) ;
if ( V_28 )
F_8 ( V_6 L_11 ,
V_36 -> V_48 ) ;
V_36 -> V_12 -> V_83 . V_84 = V_85 ;
V_51 = F_60 ( V_36 , V_41 , V_42 ) ;
V_18 = V_19 + ( V_11 -> V_57 * V_63 * 4 ) ;
do {
V_28 = F_7 ( V_36 , V_27 ) ;
if ( V_28 != - V_26 )
break;
} while ( F_43 ( V_19 , V_18 ) );
if ( V_28 == - V_26 ) {
F_8 ( V_6 L_12 , V_36 -> V_48 ) ;
F_6 ( V_36 , V_86 ) ;
for ( V_51 -= V_11 -> V_57 ; ; V_51 ++ ) {
if ( F_2 ( F_3 ( V_36 ) ) & 0x2 ) {
break;
}
F_5 ( 0 , F_40 ( V_36 ) ) ;
}
F_6 ( V_36 , V_27 ) ;
}
V_28 = F_65 ( V_36 ,
V_87 ,
V_87 ) ;
if ( V_28 )
F_8 ( V_6
L_13 ,
V_36 -> V_48 , V_28 ) ;
V_36 -> V_12 -> V_83 . V_84 = V_88 ;
return V_51 ;
}
static T_1 F_66 ( struct V_1 * V_36 ,
const void * V_41 , T_1 V_42 ,
int V_43 )
{
T_1 V_51 ;
int V_28 ;
unsigned long V_18 ;
const struct V_10 * V_11 = V_36 -> V_12 -> V_13 ;
if ( V_36 -> V_12 -> V_20 -> V_21 <= V_81 )
return F_67 ( V_36 , V_41 ,
V_42 , V_43 ) ;
if ( V_36 -> V_12 -> V_83 . V_84 != V_88 ) {
F_68 ( V_36 ,
V_89
| V_90 ,
V_89
| V_90 ) ;
V_28 = F_65 ( V_36 ,
V_91 ,
V_91 ) ;
if ( V_28 ) {
F_8 ( V_6 L_14
L_15 , V_36 -> V_48 , V_28 ) ;
}
}
F_36 ( V_36 ) ;
F_64 ( V_36 ,
V_82 |
V_90 ,
0 ) ;
V_28 = F_7 ( V_36 , V_24 ) ;
if ( V_28 )
F_8 ( V_6 L_16 ,
V_36 -> V_48 ) ;
V_36 -> V_12 -> V_83 . V_84 = V_85 ;
V_51 = F_60 ( V_36 , V_41 , V_42 ) ;
V_18 = V_19 + ( V_11 -> V_57 * ( V_63 * 4 ) ) ;
do {
V_28 = F_7 ( V_36 , V_27 ) ;
if ( V_28 != - V_26 )
break;
} while ( F_43 ( V_19 , V_18 ) );
if ( V_28 == - V_26 ) {
F_8 ( V_6 L_12 , V_36 -> V_48 ) ;
F_6 ( V_36 , V_86 ) ;
for ( V_51 -= V_11 -> V_57 ; ; V_51 ++ ) {
if ( F_2 ( F_3 ( V_36 ) ) & 0x2 ) {
break;
}
F_5 ( 0 , F_40 ( V_36 ) ) ;
}
F_6 ( V_36 , V_27 ) ;
F_33 ( V_36 ) ;
F_10 ( 5 ) ;
F_68 ( V_36 , V_89 , 0 ) ;
V_28 = F_65 ( V_36 , V_91 , 0 ) ;
if ( V_28 )
F_8 ( V_6 L_17
L_15 , V_36 -> V_48 , V_28 ) ;
F_68 ( V_36 ,
V_89 ,
V_89 ) ;
V_28 = F_65 ( V_36 ,
V_91 ,
V_91 ) ;
if ( V_28 )
F_8 ( V_6 L_18
L_15 , V_36 -> V_48 , V_28 ) ;
}
V_28 = F_65 ( V_36 ,
V_87 ,
V_87 ) ;
if ( V_28 )
F_8 ( V_6
L_19 ,
V_36 -> V_48 , V_28 ) ;
V_36 -> V_12 -> V_83 . V_84 = V_88 ;
return V_51 ;
}
static struct V_92 * F_69 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_93 ; V_60 ++ )
if ( V_94 [ V_60 ] . V_95 == 0 )
return & V_94 [ V_60 ] ;
return NULL ;
}
static void T_3 F_70 ( int V_95 , int V_96 )
{
int V_97 , V_98 , V_99 , V_100 , V_101 , V_102 ;
struct V_92 * V_32 ;
static const char * const V_103 [] = {
L_20 ,
L_21 ,
L_22 ,
L_23 } ;
F_5 ( V_96 , V_95 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( 1 , V_95 ) ;
V_97 = F_2 ( V_95 + 1 ) ;
F_5 ( 4 , V_95 ) ;
V_98 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x0a , V_95 ) ;
V_99 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x23 , V_95 ) ;
V_100 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x26 , V_95 ) ;
V_101 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x27 , V_95 ) ;
V_102 = F_2 ( V_95 + 1 ) ;
F_5 ( 0xaa , V_95 ) ;
if ( V_104 ) {
F_8 ( V_15
L_24
L_25 ,
V_97 , V_98 , V_99 , V_100 , V_101 , V_102 ) ;
F_8 ( V_15
L_26 ,
V_100 * 4 ,
( V_102 & 0x0f ) ? 'A' - 1 + ( V_102 & 0x0f ) : '-' ,
( V_101 & 0x0f ) ? 'A' - 1 + ( V_101 & 0x0f ) : '-' ,
V_99 & 0x0f ) ;
F_8 ( V_15 L_27 ,
( V_100 * 4 >= 0x100 ) ? L_28 : L_29 ,
( V_97 & 4 ) ? L_28 : L_29 ) ;
F_8 ( V_15
L_30 ,
( V_97 & 0x08 ) ? L_31
: V_103 [ V_98 & 0x03 ] ,
( V_98 & 0x40 ) ? L_32 : L_33 ) ;
}
if ( V_100 * 4 >= 0x100 ) {
V_32 = F_69 () ;
if ( V_32 == NULL )
F_8 ( V_15 L_34 ) ;
else {
int V_105 ;
switch ( V_100 * 4 ) {
case 0x3bc :
V_32 -> V_95 = 0x3bc ;
V_32 -> V_37 = 7 ;
break;
case 0x378 :
V_32 -> V_95 = 0x378 ;
V_32 -> V_37 = 7 ;
break;
case 0x278 :
V_32 -> V_95 = 0x278 ;
V_32 -> V_37 = 5 ;
}
V_105 = ( V_101 & 0x0f ) ;
if ( V_105 == 1 || V_105 == 3 )
V_32 -> V_78 = V_105 ;
else
V_32 -> V_78 = V_80 ;
}
}
}
static void T_3 F_71 ( int V_95 , int V_96 )
{
int V_106 , V_107 , V_108 , V_109 , V_110 , V_111 ;
struct V_92 * V_32 ;
static const char * const V_103 [] = {
L_35 ,
L_36 ,
L_22 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 } ;
static char * const V_112 [] = {
L_42 ,
L_43 } ;
F_5 ( V_96 , V_95 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( 0x07 , V_95 ) ;
F_5 ( 0x01 , V_95 + 1 ) ;
F_5 ( 0x30 , V_95 ) ;
V_106 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x60 , V_95 ) ;
V_107 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x61 , V_95 ) ;
V_108 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x70 , V_95 ) ;
V_109 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x74 , V_95 ) ;
V_110 = F_2 ( V_95 + 1 ) ;
F_5 ( 0xf0 , V_95 ) ;
V_111 = F_2 ( V_95 + 1 ) ;
F_5 ( 0xaa , V_95 ) ;
if ( V_104 ) {
F_8 ( V_15
L_44 ,
V_106 , V_107 , V_108 , V_109 , V_110 , V_111 ) ;
F_8 ( V_15 L_45 ,
( V_106 & 0x01 ) ? L_28 : L_29 , V_107 , V_108 , V_109 & 0x0f ) ;
if ( ( V_110 & 0x07 ) > 3 )
F_8 ( L_46 ) ;
else
F_8 ( L_47 , V_110 & 0x07 ) ;
F_8 ( V_15
L_48 ,
V_112 [ V_111 >> 7 ] , ( V_111 >> 3 ) & 0x0f ) ;
F_8 ( V_15 L_49 ,
V_103 [ V_111 & 0x07 ] ) ;
}
if ( V_106 & 0x01 ) {
V_32 = F_69 () ;
if ( V_32 == NULL )
F_8 ( V_15 L_34 ) ;
else {
V_32 -> V_95 = ( V_107 << 8 ) | V_108 ;
V_32 -> V_37 = V_109 & 0x0f ;
V_32 -> V_78 = ( ( ( V_110 & 0x07 ) > 3 ) ?
V_80 : ( V_110 & 0x07 ) ) ;
}
}
}
static void T_3 F_72 ( int V_113 , int V_96 , int V_114 ,
int V_115 , int V_116 )
{
const char * type = L_50 ;
int V_117 , V_118 = 2 ;
if ( V_114 == V_115 )
return;
V_117 = ( V_114 << 8 ) | V_115 ;
if ( V_117 == 0x9771 )
type = L_51 ;
else if ( V_117 == 0x9773 )
type = L_52 ;
else if ( V_117 == 0x9774 )
type = L_53 ;
else if ( ( V_117 & ~ 0x0f ) == 0x5270 )
type = L_54 ;
else if ( ( V_117 & ~ 0x0f ) == 0x52f0 )
type = L_55 ;
else if ( ( V_117 & ~ 0x0f ) == 0x5210 )
type = L_56 ;
else if ( ( V_117 & ~ 0x0f ) == 0x6010 )
type = L_57 ;
else if ( ( V_116 & 0x0f ) == 0x0a ) {
type = L_58 ;
V_118 = 1 ;
} else if ( ( V_116 & 0x0f ) == 0x0b ) {
type = L_59 ;
V_118 = 1 ;
} else if ( ( V_116 & 0x0f ) == 0x0c ) {
type = L_60 ;
V_118 = 1 ;
} else if ( ( V_116 & 0x0f ) == 0x0d ) {
type = L_61 ;
V_118 = 1 ;
} else
V_118 = 0 ;
if ( V_104 )
F_8 ( V_15 L_62
L_63 ,
V_113 , V_96 , V_114 , V_115 , V_116 , type ) ;
if ( V_118 == 2 )
F_71 ( V_113 , V_96 ) ;
}
static void T_3 F_73 ( int V_113 , int V_96 , int V_114 , int V_115 )
{
const char * type = L_50 ;
void (* F_74)( int V_95 , int V_96 );
int V_117 ;
if ( V_114 == V_115 )
return;
F_74 = NULL ;
V_117 = ( V_114 << 8 ) | V_115 ;
if ( V_117 == 0x0302 ) {
type = L_64 ;
F_74 = F_70 ;
} else if ( V_117 == 0x6582 )
type = L_65 ;
else if ( V_114 == 0x65 )
type = L_66 ;
else if ( V_114 == 0x66 )
type = L_67 ;
if ( V_104 )
F_8 ( V_15 L_68
L_69 ,
V_113 , V_96 , V_114 , V_115 , type ) ;
if ( F_74 )
F_74 ( V_113 , V_96 ) ;
}
static void T_3 F_75 ( int V_95 , int V_96 )
{
int V_119 , V_114 , V_115 , V_116 , V_120 , V_121 , V_122 ;
if ( ! F_76 ( V_95 , 3 , V_123 ) )
return;
V_119 = F_2 ( V_95 ) ;
F_5 ( 0x20 , V_95 ) ;
V_120 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x21 , V_95 ) ;
V_121 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x09 , V_95 ) ;
V_122 = F_2 ( V_95 + 1 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( 0x20 , V_95 ) ;
V_114 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x21 , V_95 ) ;
V_115 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x09 , V_95 ) ;
V_116 = F_2 ( V_95 + 1 ) ;
F_5 ( 0xaa , V_95 ) ;
F_5 ( V_119 , V_95 ) ;
if ( ( V_120 == V_114 ) && ( V_121 == V_115 ) && ( V_122 == V_116 ) )
goto V_124;
F_72 ( V_95 , V_96 , V_114 , V_115 , V_116 ) ;
V_124:
F_77 ( V_95 , 3 ) ;
}
static void T_3 F_78 ( int V_95 , int V_96 )
{
int V_119 [ 3 ] , V_114 , V_115 , V_116 , V_120 , V_121 , V_122 ;
if ( ! F_76 ( V_95 , 3 , V_123 ) )
return;
V_119 [ 0 ] = F_2 ( V_95 ) ;
V_119 [ 1 ] = F_2 ( V_95 + 1 ) ;
V_119 [ 2 ] = F_2 ( V_95 + 2 ) ;
F_5 ( 0x20 , V_95 + 2 ) ;
V_120 = F_2 ( V_95 + 2 ) ;
F_5 ( 0x21 , V_95 + 1 ) ;
V_121 = F_2 ( V_95 + 2 ) ;
F_5 ( 0x09 , V_95 + 1 ) ;
V_122 = F_2 ( V_95 + 2 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( 0x20 , V_95 + 2 ) ;
V_114 = F_2 ( V_95 + 2 ) ;
F_5 ( 0x21 , V_95 + 1 ) ;
V_115 = F_2 ( V_95 + 2 ) ;
F_5 ( 0x09 , V_95 + 1 ) ;
V_116 = F_2 ( V_95 + 2 ) ;
F_5 ( 0xaa , V_95 ) ;
F_5 ( V_119 [ 0 ] , V_95 ) ;
F_5 ( V_119 [ 1 ] , V_95 + 1 ) ;
F_5 ( V_119 [ 2 ] , V_95 + 2 ) ;
if ( V_120 == V_114 && V_121 == V_115 && V_122 == V_116 )
goto V_124;
F_72 ( V_95 , V_96 , V_114 , V_115 , V_116 ) ;
V_124:
F_77 ( V_95 , 3 ) ;
}
static void T_3 F_79 ( int V_95 , int V_96 )
{
int V_119 , V_117 , V_125 , V_116 , V_126 , V_127 , V_128 , V_122 , V_129 ;
if ( ! F_76 ( V_95 , 3 , V_123 ) )
return;
V_119 = F_2 ( V_95 ) ;
F_5 ( 0x0d , V_95 ) ;
V_122 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x0e , V_95 ) ;
V_129 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x20 , V_95 ) ;
V_127 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x21 , V_95 ) ;
V_128 = F_2 ( V_95 + 1 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( V_96 , V_95 ) ;
F_5 ( 0x0d , V_95 ) ;
V_116 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x0e , V_95 ) ;
V_126 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x20 , V_95 ) ;
V_117 = F_2 ( V_95 + 1 ) ;
F_5 ( 0x21 , V_95 ) ;
V_125 = F_2 ( V_95 + 1 ) ;
F_5 ( 0xaa , V_95 ) ;
F_5 ( V_119 , V_95 ) ;
if ( V_127 == V_117 && V_129 == V_126 &&
V_122 == V_116 && V_128 == V_125 )
goto V_124;
F_73 ( V_95 , V_96 , V_116 , V_126 ) ;
V_124:
F_77 ( V_95 , 3 ) ;
}
static void T_3 F_80 ( void )
{
if ( V_104 )
F_8 ( V_6 L_70 ) ;
F_75 ( 0x3f0 , 0x87 ) ;
F_75 ( 0x370 , 0x87 ) ;
F_75 ( 0x2e , 0x87 ) ;
F_75 ( 0x4e , 0x87 ) ;
F_75 ( 0x3f0 , 0x86 ) ;
F_78 ( 0x250 , 0x88 ) ;
F_78 ( 0x250 , 0x89 ) ;
}
static void T_3 F_81 ( void )
{
if ( V_104 )
F_8 ( V_6 L_71 ) ;
F_79 ( 0x3f0 , 0x55 ) ;
F_79 ( 0x370 , 0x55 ) ;
F_79 ( 0x3f0 , 0x44 ) ;
F_79 ( 0x370 , 0x44 ) ;
}
static void T_3 F_82 ( void )
{
T_4 V_30 ;
T_5 V_119 , V_28 ;
if ( V_104 )
F_8 ( V_6 L_72 ) ;
if ( ! F_83 ( 0x2e , 2 , V_123 ) )
return;
V_119 = F_2 ( 0x2e ) ;
F_5 ( 0x87 , 0x2e ) ;
F_5 ( 0x01 , 0x2e ) ;
F_5 ( 0x55 , 0x2e ) ;
F_5 ( 0x55 , 0x2e ) ;
F_5 ( 0x20 , 0x2e ) ;
V_30 = F_2 ( 0x2f ) << 8 ;
F_5 ( 0x21 , 0x2e ) ;
V_30 |= F_2 ( 0x2f ) ;
if ( V_30 == 0x8712 || V_30 == 0x8705 || V_30 == 0x8715 ||
V_30 == 0x8716 || V_30 == 0x8718 || V_30 == 0x8726 ) {
F_8 ( V_15 L_73 , V_30 ) ;
F_5 ( 0x07 , 0x2E ) ;
F_5 ( 0x03 , 0x2F ) ;
F_5 ( 0xF0 , 0x2E ) ;
V_28 = F_2 ( 0x2f ) ;
F_5 ( 0xF0 , 0x2E ) ;
F_5 ( V_28 | 8 , 0x2F ) ;
F_5 ( 0x02 , 0x2E ) ;
F_5 ( 0x02 , 0x2F ) ;
} else {
F_5 ( V_119 , 0x2e ) ;
}
F_77 ( 0x2e , 2 ) ;
}
static struct V_92 * F_84 ( struct V_1 * V_7 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_93 ; V_60 ++ )
if ( V_94 [ V_60 ] . V_95 != V_7 -> V_130 )
return & V_94 [ V_60 ] ;
return NULL ;
}
static int F_85 ( struct V_1 * V_7 )
{
struct V_92 * V_32 = F_84 ( V_7 ) ;
if ( V_32 )
return V_32 -> V_78 ;
return V_80 ;
}
static int F_86 ( struct V_1 * V_7 )
{
struct V_92 * V_32 = F_84 ( V_7 ) ;
if ( V_32 )
return V_32 -> V_37 ;
return V_38 ;
}
static int F_87 ( struct V_1 * V_2 )
{
unsigned char V_28 , V_131 ;
F_15 ( V_2 ) ;
V_131 = 0xc ;
F_5 ( V_131 , F_21 ( V_2 ) ) ;
V_28 = F_2 ( F_21 ( V_2 ) ) ;
if ( ( V_28 & 0xf ) == V_131 ) {
V_131 = 0xe ;
F_5 ( V_131 , F_21 ( V_2 ) ) ;
V_28 = F_2 ( F_21 ( V_2 ) ) ;
F_5 ( 0xc , F_21 ( V_2 ) ) ;
if ( ( V_28 & 0xf ) == V_131 )
return V_132 ;
}
if ( V_133 )
F_8 ( V_15 L_74
L_75 , V_2 -> V_130 , V_131 , V_28 ) ;
V_131 = 0xaa ;
F_88 ( V_2 , V_131 ) ;
V_28 = F_89 ( V_2 ) ;
if ( V_28 == V_131 ) {
V_131 = 0x55 ;
F_88 ( V_2 , V_131 ) ;
V_28 = F_89 ( V_2 ) ;
if ( V_28 == V_131 )
return V_132 ;
}
if ( V_133 ) {
F_8 ( V_15 L_76
L_75 , V_2 -> V_130 , V_131 , V_28 ) ;
F_8 ( V_15 L_77
L_78 ,
V_2 -> V_130 ) ;
}
if ( V_133 )
return V_132 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_13 ;
unsigned char V_28 = 0xc ;
F_5 ( V_28 , F_21 ( V_2 ) ) ;
if ( ( F_2 ( F_3 ( V_2 ) ) & 0x3 ) == ( V_28 & 0x3 ) ) {
F_5 ( V_28 ^ 0x2 , F_21 ( V_2 ) ) ;
V_28 = F_2 ( F_21 ( V_2 ) ) ;
if ( ( F_2 ( F_3 ( V_2 ) ) & 0x2 ) == ( V_28 & 0x2 ) )
goto V_134;
}
if ( ( F_2 ( F_3 ( V_2 ) ) & 0x3 ) != 0x1 )
goto V_134;
F_14 ( V_2 , 0x34 ) ;
if ( F_2 ( F_3 ( V_2 ) ) != 0x35 )
goto V_134;
V_11 -> V_16 = 1 ;
F_5 ( 0xc , F_21 ( V_2 ) ) ;
F_6 ( V_2 , V_135 ) ;
return 1 ;
V_134:
F_5 ( 0xc , F_21 ( V_2 ) ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_136 = 0 ;
F_15 ( V_2 ) ;
F_33 ( V_2 ) ;
F_88 ( V_2 , 0x55 ) ;
if ( F_89 ( V_2 ) != 0x55 )
V_136 ++ ;
F_88 ( V_2 , 0xaa ) ;
if ( F_89 ( V_2 ) != 0xaa )
V_136 ++ ;
F_36 ( V_2 ) ;
if ( V_136 ) {
V_2 -> V_103 |= V_137 ;
} else {
struct V_10 * V_11 = V_2 -> V_13 ;
V_11 -> V_40 &= ~ 0x20 ;
}
return V_136 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_60 ;
int V_138 , V_139 ;
int V_140 ;
struct V_10 * V_11 = V_2 -> V_13 ;
static const int V_141 [] = { 0 , 7 , 9 , 10 , 11 , 14 , 15 , 5 } ;
if ( ! V_11 -> V_16 )
return 0 ;
F_14 ( V_2 , V_135 << 5 ) ;
F_14 ( V_2 , V_86 << 5 ) ;
for ( V_60 = 0 ; V_60 < 1024 && ! ( F_2 ( F_3 ( V_2 ) ) & 0x02 ) ; V_60 ++ )
F_5 ( 0xaa , F_40 ( V_2 ) ) ;
if ( V_60 == 1024 ) {
F_14 ( V_2 , V_135 << 5 ) ;
return 0 ;
}
V_11 -> V_57 = V_60 ;
if ( V_104 )
F_8 ( V_6 L_79 , V_2 -> V_130 , V_60 ) ;
F_1 ( V_2 , 1 << 2 , 1 << 2 ) ;
F_1 ( V_2 , 1 << 2 , 0 ) ;
for ( V_60 = 1 ; V_60 <= V_11 -> V_57 ; V_60 ++ ) {
F_2 ( F_40 ( V_2 ) ) ;
F_10 ( 50 ) ;
if ( F_2 ( F_3 ( V_2 ) ) & ( 1 << 2 ) )
break;
}
if ( V_60 <= V_11 -> V_57 ) {
if ( V_104 )
F_8 ( V_6 L_80 ,
V_2 -> V_130 , V_60 ) ;
} else
V_60 = 0 ;
V_11 -> V_142 = V_60 ;
F_6 ( V_2 , V_27 ) ;
F_33 ( V_2 ) ;
F_6 ( V_2 , V_86 ) ;
F_1 ( V_2 , 1 << 2 , 1 << 2 ) ;
F_1 ( V_2 , 1 << 2 , 0 ) ;
for ( V_60 = 1 ; V_60 <= V_11 -> V_57 ; V_60 ++ ) {
F_5 ( 0xaa , F_40 ( V_2 ) ) ;
if ( F_2 ( F_3 ( V_2 ) ) & ( 1 << 2 ) )
break;
}
if ( V_60 <= V_11 -> V_57 ) {
if ( V_104 )
F_8 ( V_15 L_81 ,
V_2 -> V_130 , V_60 ) ;
} else
V_60 = 0 ;
V_11 -> V_143 = V_60 ;
F_14 ( V_2 , V_135 << 5 ) ;
F_14 ( V_2 , 0xf4 ) ;
V_138 = F_2 ( F_93 ( V_2 ) ) ;
V_140 = ( V_138 >> 4 ) & 0x7 ;
switch ( V_140 ) {
case 0 :
V_140 = 2 ;
F_8 ( V_144 L_82 ,
V_2 -> V_130 ) ;
break;
case 2 :
V_140 = 4 ;
F_8 ( V_144 L_82 ,
V_2 -> V_130 ) ;
break;
default:
F_8 ( V_144 L_83 ,
V_2 -> V_130 ) ;
case 1 :
V_140 = 1 ;
}
V_11 -> V_140 = V_140 ;
if ( V_104 ) {
F_8 ( V_6 L_84 ,
V_2 -> V_130 , 8 * V_140 ) ;
F_8 ( V_6 L_85 , V_2 -> V_130 ,
V_138 & 0x80 ? L_86 : L_87 ) ;
V_139 = F_2 ( F_94 ( V_2 ) ) ;
F_8 ( V_6 L_88 ,
V_2 -> V_130 , V_138 , V_139 ) ;
F_8 ( V_6 L_89 , V_2 -> V_130 ) ;
if ( ( V_139 >> 3 ) & 0x07 )
F_8 ( L_90 , V_141 [ ( V_139 >> 3 ) & 0x07 ] ) ;
else
F_8 ( L_91 ) ;
F_8 ( L_92 ) ;
if ( ( V_139 & 0x03 ) == 0x00 )
F_8 ( L_93 ) ;
else
F_8 ( L_94 , V_139 & 0x07 ) ;
}
F_6 ( V_2 , V_135 ) ;
return 1 ;
}
static int F_95 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = V_2 -> V_13 ;
int V_145 ;
unsigned char V_14 ;
if ( ! V_11 -> V_16 )
return 0 ;
V_14 = F_2 ( F_3 ( V_2 ) ) ;
F_14 ( V_2 , V_27 << 5 ) ;
V_145 = F_91 ( V_2 ) ;
F_14 ( V_2 , V_14 ) ;
return V_145 ;
}
static int F_96 ( struct V_1 * V_2 )
{
const struct V_10 * V_11 = V_2 -> V_13 ;
if ( ! F_15 ( V_2 ) )
return 0 ;
if ( V_11 -> V_16 ) {
unsigned char V_60 ;
for ( V_60 = 0x00 ; V_60 < 0x80 ; V_60 += 0x20 ) {
F_14 ( V_2 , V_60 ) ;
if ( F_15 ( V_2 ) ) {
return 0 ;
}
}
}
V_2 -> V_103 |= V_146 ;
V_2 -> V_147 -> V_148 = F_22 ;
V_2 -> V_147 -> V_149 = F_26 ;
V_2 -> V_147 -> V_150 = F_29 ;
V_2 -> V_147 -> V_151 = F_31 ;
return 1 ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_13 ;
int V_145 ;
unsigned char V_14 ;
if ( ! V_11 -> V_16 )
return 0 ;
V_14 = F_2 ( F_3 ( V_2 ) ) ;
F_14 ( V_2 , 0x80 ) ;
F_5 ( 0x04 , F_21 ( V_2 ) ) ;
V_145 = F_96 ( V_2 ) ;
F_14 ( V_2 , V_14 ) ;
if ( V_145 ) {
V_2 -> V_147 -> V_148 = F_32 ;
V_2 -> V_147 -> V_149 = F_35 ;
V_2 -> V_147 -> V_150 = F_37 ;
V_2 -> V_147 -> V_151 = F_38 ;
}
return V_145 ;
}
static int T_3 F_91 ( struct V_1 * V_2 ) { return 0 ; }
static int F_92 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_96 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_97 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_3 F_95 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_37 , V_152 ;
unsigned char V_14 = F_2 ( F_3 ( V_2 ) ) ;
static const int V_153 [ 8 ] = {
V_38 , 7 , 9 , 10 , 11 , 14 , 15 , 5
} ;
F_14 ( V_2 , V_154 << 5 ) ;
V_152 = ( F_2 ( F_94 ( V_2 ) ) >> 3 ) & 0x07 ;
V_37 = V_153 [ V_152 ] ;
F_14 ( V_2 , V_14 ) ;
return V_37 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_60 ;
unsigned long V_155 ;
V_155 = F_100 () ;
F_14 ( V_2 , V_135 << 5 ) ;
F_14 ( V_2 , ( V_86 << 5 ) | 0x04 ) ;
F_14 ( V_2 , V_86 << 5 ) ;
for ( V_60 = 0 ; V_60 < 1024 && ! ( F_2 ( F_3 ( V_2 ) ) & 0x02 ) ; V_60 ++ )
F_5 ( 0xaa , F_40 ( V_2 ) ) ;
V_2 -> V_37 = F_101 ( V_155 ) ;
F_14 ( V_2 , V_135 << 5 ) ;
if ( V_2 -> V_37 <= 0 )
V_2 -> V_37 = V_38 ;
return V_2 -> V_37 ;
}
static int F_102 ( struct V_1 * V_2 )
{
#ifndef F_103
return V_38 ;
#else
int V_155 ;
unsigned char V_14 ;
if ( V_2 -> V_103 & V_156 )
V_14 = F_2 ( F_3 ( V_2 ) ) ;
V_155 = F_100 () ;
if ( V_2 -> V_103 & V_156 )
F_1 ( V_2 , 0x10 , 0x10 ) ;
F_15 ( V_2 ) ;
F_64 ( V_2 , 0x20 , 0x20 ) ;
F_64 ( V_2 , 0x10 , 0x10 ) ;
F_15 ( V_2 ) ;
F_104 ( V_2 ) ;
F_10 ( 20 ) ;
V_2 -> V_37 = F_101 ( V_155 ) ;
if ( V_2 -> V_103 & V_156 )
F_14 ( V_2 , V_14 ) ;
F_34 ( V_2 , 0xc ) ;
if ( V_2 -> V_37 <= 0 )
V_2 -> V_37 = V_38 ;
return V_2 -> V_37 ;
#endif
}
static int F_105 ( struct V_1 * V_2 )
{
return V_38 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_13 ;
if ( V_11 -> V_16 ) {
V_2 -> V_37 = F_98 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_37 = F_99 ( V_2 ) ;
}
if ( ( V_2 -> V_37 == V_38 ) && V_11 -> V_16 &&
( V_2 -> V_103 & V_146 ) )
V_2 -> V_37 = F_102 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 && ( V_2 -> V_103 & V_146 ) )
V_2 -> V_37 = F_102 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_37 = F_105 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_37 = F_86 ( V_2 ) ;
return V_2 -> V_37 ;
}
static int F_107 ( struct V_1 * V_7 )
{
unsigned char V_14 = F_2 ( F_3 ( V_7 ) ) ;
int V_78 ;
F_6 ( V_7 , V_154 ) ;
V_78 = F_2 ( F_94 ( V_7 ) ) & 0x07 ;
if ( ( V_78 & 0x03 ) == 0 )
V_78 = V_80 ;
F_14 ( V_7 , V_14 ) ;
return V_78 ;
}
static int F_108 ( struct V_1 * V_7 )
{
const struct V_10 * V_11 = V_7 -> V_13 ;
if ( V_11 -> V_16 )
V_7 -> V_78 = F_107 ( V_7 ) ;
if ( V_7 -> V_78 == V_80 ) {
V_7 -> V_78 = F_85 ( V_7 ) ;
}
return V_7 -> V_78 ;
}
struct V_1 * F_109 ( unsigned long int V_130 ,
unsigned long int V_157 ,
int V_37 , int V_78 ,
struct V_67 * V_30 ,
int V_158 )
{
struct V_10 * V_11 ;
struct V_159 * V_147 ;
struct V_1 * V_7 ;
int V_160 = V_38 ;
struct V_161 * V_162 ;
struct V_161 * V_163 = NULL ;
struct V_161 * V_164 = NULL ;
struct V_165 * V_166 = NULL ;
if ( ! V_30 ) {
V_166 = F_110 ( L_95 ,
V_130 , NULL , 0 ) ;
if ( F_111 ( V_166 ) )
return NULL ;
V_30 = & V_166 -> V_30 ;
V_30 -> V_167 = F_112 ( 24 ) ;
V_30 -> V_168 = & V_30 -> V_167 ;
}
V_147 = F_113 ( sizeof( struct V_159 ) , V_169 ) ;
if ( ! V_147 )
goto V_170;
V_11 = F_113 ( sizeof( struct V_10 ) , V_169 ) ;
if ( ! V_11 )
goto V_171;
V_7 = F_114 ( V_130 , V_37 , V_78 , V_147 ) ;
if ( ! V_7 )
goto V_172;
V_162 = F_76 ( V_130 , 3 , V_7 -> V_48 ) ;
if ( ! V_162 )
goto V_173;
memcpy ( V_147 , & V_174 , sizeof( struct V_159 ) ) ;
V_11 -> V_17 = 0xc ;
V_11 -> V_40 = ~ 0x10 ;
V_11 -> V_16 = 0 ;
V_11 -> V_57 = 0 ;
V_11 -> V_77 = NULL ;
V_11 -> V_69 = 0 ;
F_115 ( & V_11 -> V_175 ) ;
V_11 -> V_36 = V_7 ;
V_7 -> V_30 = V_30 ;
V_7 -> V_157 = V_157 ;
V_7 -> V_103 = V_132 | V_176 ;
V_7 -> V_13 = V_11 ;
if ( V_157 ) {
V_163 = F_76 ( V_157 , 3 , V_7 -> V_48 ) ;
if ( V_163 )
F_90 ( V_7 ) ;
}
if ( V_130 != 0x3bc ) {
V_164 = F_76 ( V_130 + 0x3 , 5 , V_7 -> V_48 ) ;
if ( V_164 )
if ( ! F_96 ( V_7 ) )
F_97 ( V_7 ) ;
}
if ( ! F_87 ( V_7 ) )
goto V_177;
if ( V_11 -> V_16 )
F_95 ( V_7 ) ;
else
F_91 ( V_7 ) ;
V_7 -> V_178 = ( V_7 -> V_103 & V_146 ) ? 8 : 3 ;
F_8 ( V_15 L_96 , V_7 -> V_48 , V_7 -> V_130 ) ;
if ( V_7 -> V_157 && V_11 -> V_16 )
F_8 ( L_97 , V_7 -> V_157 ) ;
if ( V_7 -> V_37 == V_179 ) {
V_7 -> V_37 = V_38 ;
F_106 ( V_7 ) ;
} else if ( V_7 -> V_37 == V_180 ) {
V_7 -> V_37 = V_38 ;
F_106 ( V_7 ) ;
V_160 = V_7 -> V_37 ;
V_7 -> V_37 = V_38 ;
}
if ( V_7 -> V_37 != V_38 ) {
F_8 ( L_98 , V_7 -> V_37 ) ;
V_11 -> V_40 |= 0x10 ;
if ( V_7 -> V_78 == V_181 ) {
V_7 -> V_78 = V_80 ;
F_108 ( V_7 ) ;
}
}
if ( V_7 -> V_78 == V_181 )
V_7 -> V_78 = V_80 ;
#ifdef F_116
if ( F_92 ( V_7 ) &&
V_7 -> V_78 != V_182 &&
V_11 -> V_57 > 0 && V_7 -> V_37 != V_38 ) {
V_7 -> V_103 |= V_183 | V_184 ;
V_7 -> V_147 -> V_185 = F_62 ;
#ifdef F_117
V_7 -> V_147 -> V_186 = F_66 ;
#endif
if ( V_7 -> V_78 != V_80 ) {
F_8 ( L_99 , V_7 -> V_78 ) ;
V_7 -> V_103 |= V_187 ;
} else
F_8 ( L_100 ) ;
} else
V_7 -> V_78 = V_80 ;
#endif
F_8 ( L_101 ) ;
#define F_118 ( T_6 ) \
{\
if (p->modes & PARPORT_MODE_##x) {\
printk("%s%s", f ? "," : "", #x);\
f++;\
} \
}
{
int V_188 = 0 ;
F_118 ( V_189 ) ;
F_118 ( V_190 ) ;
F_118 (COMPAT)
F_118 ( V_191 ) ;
F_118 ( V_192 ) ;
F_118 ( V_193 ) ;
}
#undef F_118
#ifndef F_117
F_8 ( L_102 ) ;
#endif
F_8 ( L_103 ) ;
if ( V_160 != V_38 )
F_8 ( V_15 L_104 , V_7 -> V_48 , V_160 ) ;
if ( V_163 && ( V_7 -> V_103 & V_183 ) == 0 ) {
F_77 ( V_157 , 3 ) ;
V_163 = NULL ;
}
if ( V_164 && ( V_7 -> V_103 & V_146 ) == 0 ) {
F_77 ( V_130 + 3 , 5 ) ;
V_164 = NULL ;
}
if ( V_7 -> V_37 != V_38 ) {
if ( F_119 ( V_7 -> V_37 , V_194 ,
V_158 , V_7 -> V_48 , V_7 ) ) {
F_8 ( V_144 L_105
L_106 ,
V_7 -> V_48 , V_7 -> V_37 ) ;
V_7 -> V_37 = V_38 ;
V_7 -> V_78 = V_80 ;
}
#ifdef F_116
#ifdef F_61
if ( V_7 -> V_78 != V_80 ) {
if ( F_120 ( V_7 -> V_78 , V_7 -> V_48 ) ) {
F_8 ( V_144 L_107
L_108 ,
V_7 -> V_48 , V_7 -> V_78 ) ;
V_7 -> V_78 = V_80 ;
} else {
V_11 -> V_77 =
F_121 ( V_30 ,
V_75 ,
& V_11 -> V_69 ,
V_169 ) ;
if ( ! V_11 -> V_77 ) {
F_8 ( V_144 L_109
L_110
L_108 ,
V_7 -> V_48 ) ;
F_122 ( V_7 -> V_78 ) ;
V_7 -> V_78 = V_80 ;
}
}
}
#endif
#endif
}
if ( V_11 -> V_16 )
F_14 ( V_7 , 0x34 ) ;
F_88 ( V_7 , 0 ) ;
F_36 ( V_7 ) ;
F_123 ( & V_195 ) ;
F_124 ( & V_11 -> V_175 , & V_196 ) ;
F_125 ( & V_195 ) ;
F_126 ( V_7 ) ;
return V_7 ;
V_177:
if ( V_163 )
F_77 ( V_157 , 3 ) ;
if ( V_164 )
F_77 ( V_130 + 0x3 , 5 ) ;
F_77 ( V_130 , 3 ) ;
V_173:
F_127 ( V_7 ) ;
V_172:
F_128 ( V_11 ) ;
V_171:
F_128 ( V_147 ) ;
V_170:
if ( V_166 )
F_129 ( V_166 ) ;
return NULL ;
}
void F_130 ( struct V_1 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_13 ;
struct V_159 * V_147 = V_7 -> V_147 ;
F_131 ( V_7 ) ;
F_123 ( & V_195 ) ;
F_132 ( & V_11 -> V_175 ) ;
F_125 ( & V_195 ) ;
#if F_133 ( F_116 ) && F_133 ( F_61 )
if ( V_7 -> V_78 != V_80 )
F_122 ( V_7 -> V_78 ) ;
#endif
if ( V_7 -> V_37 != V_38 )
F_134 ( V_7 -> V_37 , V_7 ) ;
F_77 ( V_7 -> V_130 , 3 ) ;
if ( V_7 -> V_178 > 3 )
F_77 ( V_7 -> V_130 + 3 , V_7 -> V_178 - 3 ) ;
if ( V_7 -> V_103 & V_183 )
F_77 ( V_7 -> V_157 , 3 ) ;
#if F_133 ( F_116 ) && F_133 ( F_61 )
if ( V_11 -> V_77 )
F_135 ( V_7 -> V_12 -> V_30 , V_75 ,
V_11 -> V_77 ,
V_11 -> V_69 ) ;
#endif
F_128 ( V_7 -> V_13 ) ;
F_127 ( V_7 ) ;
F_128 ( V_147 ) ;
}
static int T_3 F_136 ( struct V_197 * V_166 , int V_198 ,
int V_199 ,
const struct V_200 * V_201 )
{
short V_202 [ 6 ] = { 0x2A0 , 0x2C0 , 0x220 , 0x240 , 0x1E0 } ;
T_7 V_203 ;
T_7 V_204 , V_205 ;
T_5 V_206 , type ;
int V_37 ;
int V_60 ;
F_4 ( V_6 L_111 ) ;
for ( V_60 = 0 ; V_60 < 5 ; V_60 ++ ) {
if ( F_76 ( V_202 [ V_60 ] , 32 , L_112 ) ) {
int V_207 ;
F_137 ( V_166 , 0x60 ,
0xe5000000 | V_202 [ V_60 ] ) ;
F_137 ( V_166 , 0x78 ,
0x00000000 | V_202 [ V_60 ] ) ;
V_207 = F_2 ( V_202 [ V_60 ] ) ;
if ( V_207 != 0xff )
break;
F_77 ( V_202 [ V_60 ] , 32 ) ;
}
}
if ( V_60 >= 5 ) {
F_8 ( V_15 L_113 ) ;
return 0 ;
}
type = F_2 ( V_202 [ V_60 ] + 0x18 ) ;
type &= 0x0f ;
switch ( type ) {
case 0x2 :
F_8 ( V_15 L_114 ) ;
V_203 = 0x64200000 ;
break;
case 0xa :
F_8 ( V_15 L_115 ) ;
V_203 = 0x64200000 ;
break;
case 0xe :
F_8 ( V_15 L_116 ) ;
V_203 = 0x64e00000 ;
break;
case 0x6 :
F_8 ( V_15 L_117 ) ;
return 0 ;
case 0x8 :
F_8 ( V_15 L_118 ) ;
return 0 ;
default:
F_8 ( V_15 L_119 ) ;
F_8 ( V_15 L_120
L_121 ) ;
return 0 ;
}
F_138 ( V_166 , 0x3c , & V_206 ) ;
F_139 ( V_166 , 0x1c , & V_204 ) ;
V_204 &= 0x0000ff00 ;
F_139 ( V_166 , 0x20 , & V_205 ) ;
V_205 &= 0x0000ff00 ;
F_137 ( V_166 , 0x6c , 0xe3000000 | V_204 ) ;
F_137 ( V_166 , 0x70 , 0xe3000000 | V_205 ) ;
F_137 ( V_166 , 0x80 , ( V_205 << 16 ) | V_204 ) ;
F_137 ( V_166 , 0x9c ,
V_203 | ( V_206 * 0x11111 ) ) ;
F_4 ( V_6 L_122 , V_206 ) ;
F_4 ( V_6 L_123 ,
V_204 ) ;
F_4 ( V_6 L_124 ,
V_205 ) ;
V_37 = V_206 ;
if ( V_198 != V_179 )
V_37 = V_38 ;
F_77 ( V_202 [ V_60 ] , 32 ) ;
if ( F_109 ( V_204 , V_205 ,
V_37 , V_80 , & V_166 -> V_30 , 0 ) ) {
F_8 ( V_15
L_125 ,
V_204 ) ;
if ( V_37 != V_38 )
F_8 ( L_126 , V_37 ) ;
F_8 ( L_127 ) ;
return 1 ;
}
return 0 ;
}
static int T_3 F_140 ( struct V_197 * V_166 , int V_198 ,
int V_199 ,
const struct V_200 * V_201 )
{
T_5 V_208 , V_209 , V_210 ;
T_5 V_211 = 0 ;
int V_78 , V_37 ;
unsigned V_212 , V_213 ;
unsigned V_214 = 0 ;
F_8 ( V_6 L_128 ) ;
switch ( V_215 ) {
case 1 :
F_8 ( V_6 L_129 ) ;
V_210 = V_216 ;
break;
case 2 :
F_8 ( V_6 L_130 ) ;
V_210 = V_216 ;
V_211 = V_217 ;
break;
case 3 :
F_8 ( V_6 L_131 ) ;
V_210 = V_218 ;
V_211 = V_217 ;
V_214 = 1 ;
break;
case 4 :
F_8 ( V_6 L_132 ) ;
V_210 = V_219 ;
V_211 = V_217 ;
break;
case 5 :
F_8 ( V_6 L_133 ) ;
V_210 = V_219 ;
V_211 = V_217 | V_220 ;
V_214 = 1 ;
break;
default:
F_8 ( V_6
L_134 ) ;
V_210 = V_221 ;
break;
}
F_138 ( V_166 , V_201 -> V_222 , & V_208 ) ;
V_208 |= V_201 -> V_223 ;
F_141 ( V_166 , V_201 -> V_222 , V_208 ) ;
F_5 ( V_201 -> V_224 , V_225 ) ;
V_208 = F_2 ( V_226 ) ;
F_5 ( V_201 -> V_227 , V_225 ) ;
V_209 = F_2 ( V_226 ) ;
if ( V_210 == V_221 ) {
V_210 = V_208 & V_228 ;
V_211 = V_209 ;
} else {
V_208 &= ~ V_228 ;
V_208 |= V_210 ;
F_5 ( V_201 -> V_224 , V_225 ) ;
F_5 ( V_208 , V_226 ) ;
V_209 &= ~ ( V_217 | V_220 ) ;
V_209 |= V_211 ;
F_5 ( V_201 -> V_227 , V_225 ) ;
F_5 ( V_209 , V_226 ) ;
}
F_5 ( V_201 -> V_229 , V_225 ) ;
V_212 = F_2 ( V_226 ) << 2 ;
F_8 ( V_6 L_135 ,
V_212 ) ;
if ( V_212 == 0x3BC && V_214 ) {
F_5 ( V_201 -> V_229 , V_225 ) ;
F_5 ( ( 0x378 >> 2 ) , V_226 ) ;
F_8 ( V_6
L_136 ) ;
V_212 = 0x378 ;
}
F_138 ( V_166 , V_201 -> V_222 , & V_208 ) ;
V_208 &= ~ V_201 -> V_223 ;
F_141 ( V_166 , V_201 -> V_222 , V_208 ) ;
if ( V_210 == V_228 ) {
F_8 ( V_15 L_137 ) ;
return 0 ;
}
F_138 ( V_166 , V_201 -> V_230 , & V_208 ) ;
V_37 = ( ( V_208 & V_231 ) >> 4 ) ;
if ( V_210 == V_219 ) {
F_138 ( V_166 , V_201 -> V_232 , & V_208 ) ;
V_78 = ( ( V_208 & V_233 ) >> 2 ) ;
} else
V_78 = V_80 ;
if ( V_198 == V_38 ) {
V_37 = V_38 ;
V_78 = V_80 ;
}
if ( V_199 == V_80 )
V_78 = V_80 ;
switch ( V_212 ) {
case 0x3bc :
V_213 = 0x7bc ; break;
case 0x378 :
V_213 = 0x778 ; break;
case 0x278 :
V_213 = 0x678 ; break;
default:
F_8 ( V_15
L_138 ,
V_212 ) ;
return 0 ;
}
switch ( V_37 ) {
case 0 :
case 2 :
case 8 :
case 13 :
V_37 = V_38 ;
break;
default:
break;
}
if ( F_109 ( V_212 , V_213 , V_37 , V_78 , & V_166 -> V_30 , 0 ) ) {
F_8 ( V_15
L_139 , V_212 ) ;
if ( V_37 != V_38 )
F_8 ( L_126 , V_37 ) ;
if ( V_78 != V_80 )
F_8 ( L_140 , V_78 ) ;
F_8 ( L_127 ) ;
return 1 ;
}
F_8 ( V_144 L_141 ,
V_212 , V_37 , V_78 ) ;
return 0 ;
}
static int F_142 ( struct V_197 * V_30 ,
const struct V_234 * V_117 )
{
int V_235 , V_76 , V_65 , V_60 = V_117 -> V_236 ;
struct V_237 * V_238 ;
if ( V_60 < V_239 )
return 0 ;
V_60 -= V_239 ;
V_76 = 0 ;
V_235 = F_143 ( V_30 ) ;
if ( V_235 )
return V_235 ;
V_238 = F_113 ( sizeof( struct V_237 ) , V_169 ) ;
if ( ! V_238 )
return - V_240 ;
if ( V_241 [ V_60 ] . V_242 &&
V_241 [ V_60 ] . V_242 ( V_30 , V_38 , V_80 ) ) {
F_128 ( V_238 ) ;
return - V_243 ;
}
for ( V_65 = 0 ; V_65 < V_241 [ V_60 ] . V_244 ; V_65 ++ ) {
int V_245 = V_241 [ V_60 ] . V_246 [ V_65 ] . V_245 ;
int V_247 = V_241 [ V_60 ] . V_246 [ V_65 ] . V_247 ;
int V_37 ;
unsigned long V_248 , V_249 ;
V_248 = F_144 ( V_30 , V_245 ) ;
V_249 = 0 ;
if ( ( V_247 >= 0 ) && ( V_247 <= 6 ) )
V_249 = F_144 ( V_30 , V_247 ) ;
else if ( V_247 > 6 )
V_248 += V_247 ;
V_37 = V_30 -> V_37 ;
if ( V_37 == V_250 ) {
F_8 ( V_6
L_142 ,
V_251 [ V_60 + V_239 ] . V_252 ,
V_251 [ V_60 + V_239 ] . V_67 ,
V_248 , V_249 ) ;
V_37 = V_38 ;
} else {
F_8 ( V_6
L_143 ,
V_251 [ V_60 + V_239 ] . V_252 ,
V_251 [ V_60 + V_239 ] . V_67 ,
V_248 , V_249 , V_37 ) ;
}
V_238 -> V_253 [ V_76 ] =
F_109 ( V_248 , V_249 , V_37 ,
V_80 , & V_30 -> V_30 ,
V_254 ) ;
if ( V_238 -> V_253 [ V_76 ] )
V_76 ++ ;
}
V_238 -> V_255 = V_76 ;
if ( V_241 [ V_60 ] . V_256 )
V_241 [ V_60 ] . V_256 ( V_30 , V_76 == 0 ) ;
if ( V_76 ) {
F_145 ( V_30 , V_238 ) ;
return 0 ;
}
F_128 ( V_238 ) ;
return - V_243 ;
}
static void T_8 F_146 ( struct V_197 * V_30 )
{
struct V_237 * V_238 = F_147 ( V_30 ) ;
int V_60 ;
F_145 ( V_30 , NULL ) ;
if ( V_238 ) {
for ( V_60 = V_238 -> V_255 - 1 ; V_60 >= 0 ; V_60 -- )
F_130 ( V_238 -> V_253 [ V_60 ] ) ;
F_128 ( V_238 ) ;
}
}
static int T_9 F_148 ( int V_198 , int V_199 )
{
const struct V_234 * V_117 ;
struct V_197 * V_166 = NULL ;
int V_53 = 0 ;
F_149 (pdev) {
V_117 = F_150 ( V_251 , V_166 ) ;
if ( V_117 == NULL || V_117 -> V_236 >= V_239 )
continue;
if ( V_257 [ V_117 -> V_236 ] . F_151 (
V_166 , V_198 , V_199 ,
V_257 [ V_117 -> V_236 ] . V_201 ) ) {
V_53 ++ ;
}
}
return V_53 ;
}
static int T_9 F_148 ( int V_198 , int V_199 )
{
return 0 ;
}
static int F_152 ( struct V_258 * V_30 ,
const struct V_259 * V_117 )
{
struct V_1 * V_260 ;
unsigned long V_248 , V_249 ;
int V_78 , V_37 ;
if ( F_153 ( V_30 , 0 ) &&
! ( F_154 ( V_30 , 0 ) & V_261 ) ) {
V_248 = F_155 ( V_30 , 0 ) ;
} else
return - V_262 ;
if ( F_153 ( V_30 , 1 ) &&
! ( F_154 ( V_30 , 1 ) & V_261 ) ) {
V_249 = F_155 ( V_30 , 1 ) ;
} else
V_249 = 0 ;
if ( F_156 ( V_30 , 0 ) &&
! ( F_157 ( V_30 , 0 ) & V_261 ) ) {
V_37 = F_158 ( V_30 , 0 ) ;
} else
V_37 = V_38 ;
if ( F_159 ( V_30 , 0 ) &&
! ( F_160 ( V_30 , 0 ) & V_261 ) ) {
V_78 = F_161 ( V_30 , 0 ) ;
} else
V_78 = V_80 ;
F_162 ( & V_30 -> V_30 , L_144 , V_30 -> V_263 -> V_48 ) ;
V_260 = F_109 ( V_248 , V_249 , V_37 , V_78 , & V_30 -> V_30 , 0 ) ;
if ( V_260 == NULL )
return - V_243 ;
F_163 ( V_30 , V_260 ) ;
return 0 ;
}
static void F_164 ( struct V_258 * V_30 )
{
struct V_1 * V_260 = (struct V_1 * ) F_165 ( V_30 ) ;
if ( ! V_260 )
return;
F_130 ( V_260 ) ;
}
static int T_3 F_166 ( struct V_165 * V_166 )
{
return 0 ;
}
static void T_9 F_167 ( int V_198 , int V_199 )
{
int V_76 = 0 , V_235 ;
#ifdef F_168
F_82 () ;
F_80 () ;
F_81 () ;
#endif
V_76 += F_148 ( V_198 , V_199 ) ;
if ( ! V_76 ) {
V_235 = F_169 ( & V_264 ) ;
if ( ! V_235 )
V_265 = 1 ;
}
F_170 ( V_198 , V_199 ) ;
V_235 = F_171 ( & V_266 ) ;
if ( ! V_235 )
V_267 = 1 ;
}
static int T_9 F_172 ( const char * V_32 , int * V_268 ,
int V_269 , int V_270 , int V_271 )
{
if ( ! V_32 )
return 0 ;
if ( ! strncmp ( V_32 , L_145 , 4 ) )
* V_268 = V_269 ;
else if ( ! strncmp ( V_32 , L_146 , 4 ) )
* V_268 = V_270 ;
else if ( V_271 && ! strncmp ( V_32 , L_147 , 6 ) )
* V_268 = V_271 ;
else {
char * V_272 ;
unsigned long V_28 = F_173 ( V_32 , & V_272 , 0 ) ;
if ( V_272 != V_32 )
* V_268 = V_28 ;
else {
F_8 ( V_273 L_148 , V_32 ) ;
return - 1 ;
}
}
return 0 ;
}
static int T_9 F_174 ( const char * V_274 , int * V_268 )
{
return F_172 ( V_274 , V_268 , V_179 ,
V_38 , 0 ) ;
}
static int T_9 F_175 ( const char * V_275 , int * V_268 )
{
return F_172 ( V_275 , V_268 , V_181 ,
V_80 , V_182 ) ;
}
static int T_9 F_176 ( char * V_276 )
{
F_8 ( V_6
L_149 , V_276 ) ;
if ( ! strcmp ( V_276 , L_150 ) )
V_215 = 1 ;
if ( ! strcmp ( V_276 , L_151 ) )
V_215 = 2 ;
if ( ! strcmp ( V_276 , L_152 ) )
V_215 = 3 ;
if ( ! strcmp ( V_276 , L_153 ) )
V_215 = 4 ;
if ( ! strcmp ( V_276 , L_154 ) )
V_215 = 5 ;
return 1 ;
}
static int T_9 F_177 ( void )
{
unsigned int V_60 ;
int V_268 ;
#ifdef F_178
if ( V_277 )
F_176 ( V_277 ) ;
#endif
for ( V_60 = 0 ; V_60 < V_278 && V_95 [ V_60 ] ; V_60 ++ ) {
if ( F_174 ( V_37 [ V_60 ] , & V_268 ) )
return 1 ;
V_279 [ V_60 ] = V_268 ;
if ( F_175 ( V_78 [ V_60 ] , & V_268 ) )
return 1 ;
V_280 [ V_60 ] = V_268 ;
}
if ( ! V_95 [ 0 ] ) {
if ( V_37 [ 0 ] && ! F_174 ( V_37 [ 0 ] , & V_268 ) )
switch ( V_268 ) {
case V_38 :
case V_179 :
V_279 [ 0 ] = V_268 ;
break;
default:
F_8 ( V_144
L_155
L_156
L_157 ) ;
}
if ( V_78 [ 0 ] && ! F_175 ( V_78 [ 0 ] , & V_268 ) )
switch ( V_268 ) {
case V_80 :
case V_181 :
V_280 [ 0 ] = V_268 ;
break;
default:
F_8 ( V_144
L_158
L_156
L_157 ) ;
}
}
return 0 ;
}
static int T_9 F_179 ( char * V_276 )
{
char * V_281 ;
char * V_282 ;
int V_268 ;
if ( ! V_276 || ! * V_276 || ( * V_276 == '0' && ! * ( V_276 + 1 ) ) ) {
V_95 [ 0 ] = V_283 ;
return 1 ;
}
if ( ! strncmp ( V_276 , L_145 , 4 ) ) {
V_279 [ 0 ] = V_179 ;
V_280 [ 0 ] = V_181 ;
return 1 ;
}
V_268 = F_173 ( V_276 , & V_281 , 0 ) ;
if ( V_281 == V_276 ) {
F_8 ( V_144 L_159 , V_276 ) ;
return 1 ;
}
if ( V_284 == V_278 ) {
F_8 ( V_273 L_160 , V_276 ) ;
return 1 ;
}
V_95 [ V_284 ] = V_268 ;
V_279 [ V_284 ] = V_38 ;
V_280 [ V_284 ] = V_80 ;
V_282 = strchr ( V_276 , ',' ) ;
if ( V_282 ++ ) {
if ( F_174 ( V_282 , & V_268 ) )
return 1 ;
V_279 [ V_284 ] = V_268 ;
V_282 = strchr ( V_282 , ',' ) ;
if ( V_282 ++ ) {
if ( F_175 ( V_282 , & V_268 ) )
return 1 ;
V_280 [ V_284 ] = V_268 ;
}
}
V_284 ++ ;
return 1 ;
}
static int T_9 F_177 ( void )
{
return V_95 [ 0 ] == V_283 ;
}
static int T_9 F_180 ( void )
{
int V_235 ;
if ( F_177 () )
return - V_262 ;
V_235 = F_181 ( & V_285 ) ;
if ( V_235 )
return V_235 ;
if ( V_95 [ 0 ] ) {
int V_60 ;
V_133 = 1 ;
for ( V_60 = 0 ; V_60 < V_278 ; V_60 ++ ) {
if ( ! V_95 [ V_60 ] )
break;
if ( V_249 [ V_60 ] == V_286 )
V_249 [ V_60 ] = 0x400 + V_95 [ V_60 ] ;
F_109 ( V_95 [ V_60 ] , V_249 [ V_60 ] ,
V_279 [ V_60 ] , V_280 [ V_60 ] , NULL , 0 ) ;
}
} else
F_167 ( V_279 [ 0 ] , V_280 [ 0 ] ) ;
return 0 ;
}
static void T_10 F_182 ( void )
{
if ( V_267 )
F_183 ( & V_266 ) ;
if ( V_265 )
F_184 ( & V_264 ) ;
F_185 ( & V_285 ) ;
while ( ! F_186 ( & V_196 ) ) {
struct V_10 * V_11 ;
struct V_1 * V_36 ;
V_11 = F_187 ( V_196 . V_287 ,
struct V_10 , V_175 ) ;
V_36 = V_11 -> V_36 ;
if ( V_36 -> V_30 && V_36 -> V_30 -> V_288 == & V_289 )
F_129 (
F_188 ( V_36 -> V_30 ) ) ;
F_130 ( V_36 ) ;
}
}
