static inline int F_1 ( unsigned long V_1 )
{
unsigned int V_2 = 0 ;
unsigned int V_3 = F_2 () ;
while ( ! ( F_3 ( V_1 + 0xe ) & 0x1 ) && V_2 ++ < 100 )
if ( V_3 )
F_4 ( 1 ) ;
else
F_5 ( 1 ) ;
return ! ( F_3 ( V_1 + 0xe ) & 0x1 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
unsigned long V_1 = V_5 -> V_1 ;
unsigned int V_6 , V_3 ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ ) {
F_7 ( & V_5 -> V_7 , V_5 -> V_8 ) ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
if ( F_3 ( V_1 + 0xe ) & 0x1 )
return 1 ;
F_8 ( 10 ) ;
}
F_9 ( & V_5 -> V_7 , V_5 -> V_8 ) ;
F_5 ( 10 ) ;
}
F_10 ( L_1 , V_5 -> V_1 ) ;
return 0 ;
}
static void F_11 ( struct V_4 * V_5 )
{
F_9 ( & V_5 -> V_7 , V_5 -> V_8 ) ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_11 = V_10 -> V_11 ;
if ( F_1 ( V_1 ) )
return;
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0504 , V_1 ) ;
F_14 ( V_1 ) ;
V_10 -> V_13 |= V_14 ;
}
static inline void F_15 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_11 = V_10 -> V_11 ;
if ( F_1 ( V_1 ) )
return;
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0404 , V_1 ) ;
F_14 ( V_1 ) ;
V_10 -> V_13 &= ~ V_14 ;
}
static inline void F_16 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_11 = V_10 -> V_11 ;
if ( F_1 ( V_1 ) )
return;
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0a04 , V_1 ) ;
F_14 ( V_1 ) ;
V_10 -> V_13 |= V_15 ;
}
static inline void F_17 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_11 = V_10 -> V_11 ;
if ( F_1 ( V_1 ) )
return;
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0804 , V_1 ) ;
F_14 ( V_1 ) ;
V_10 -> V_13 &= ~ V_15 ;
}
static void F_18 ( struct V_16 * V_10 , int V_17 )
{
struct V_9 * V_18 = F_19 ( V_10 , struct V_9 , V_10 ) ;
struct V_4 * V_5 = V_18 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_11 = V_18 -> V_11 ;
if ( ! F_6 ( V_5 ) )
return;
if ( V_17 ) {
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0f04 , V_1 ) ;
F_14 ( V_1 ) ;
V_18 -> V_13 |= ( V_14 | V_15 ) ;
} else {
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0C04 , V_1 ) ;
F_14 ( V_1 ) ;
V_18 -> V_13 &= ~ ( V_14 | V_15 ) ;
}
F_11 ( V_5 ) ;
}
static void F_20 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_11 = V_10 -> V_11 ;
if ( F_1 ( V_1 ) )
return;
F_13 ( 0x8000 | ( V_11 << V_5 -> V_12 ) | 0x02 , V_1 ) ;
F_13 ( 0x0c04 , V_1 ) ;
F_14 ( V_1 ) ;
V_10 -> V_13 &= ~ ( V_15 | V_14 ) ;
}
static inline int F_21 ( struct V_9 const * V_10 ,
char * V_19 , const char * V_20 )
{
if ( ! V_10 ) {
F_10 ( L_2 ,
V_19 , V_20 ) ;
return 1 ;
}
if ( V_10 -> V_21 != V_22 ) {
F_10 ( L_3 ,
V_19 , V_20 ) ;
return 1 ;
}
return 0 ;
}
static void F_22 ( unsigned long V_23 )
{
unsigned long V_8 , V_1 ;
unsigned int V_6 ;
short V_2 = ( V_24 - 1 ) , V_5 ;
short V_25 , V_26 , V_27 , V_28 , V_29 ;
struct V_9 * V_10 ;
struct V_30 * V_31 ;
V_5 = ( V_32 + 1 ) & 0x0003 ;
while ( V_2 -- > 0 ) {
if ( V_33 [ V_5 ] . V_13 & V_34 )
break;
V_5 = ( V_5 + 1 ) & 0x0003 ;
}
if ( ! ( V_33 [ V_5 ] . V_13 & V_34 ) )
goto V_35;
V_32 = V_5 ;
V_2 = V_33 [ V_5 ] . V_36 ;
V_10 = V_33 [ V_5 ] . V_37 ;
V_1 = V_33 [ V_5 ] . V_1 ;
F_7 ( & V_33 [ V_5 ] . V_7 , V_8 ) ;
for ( V_6 = 0 ; V_6 < 100 ; V_6 ++ ) {
if ( F_3 ( V_1 + 0xe ) & 0x1 )
break;
F_8 ( 2 ) ;
}
if ( V_6 >= 100 )
goto V_38;
V_31 = F_23 ( & V_10 -> V_10 ) ;
if ( V_31 == NULL )
goto V_39;
for (; V_2 > 0 ; V_2 -- , V_10 ++ ) {
if ( ! ( V_10 -> V_10 . V_8 & V_40 ) ||
! ( V_10 -> V_13 & V_41 ) )
continue;
V_25 = F_24 ( short , V_42 , V_10 -> V_43 ) ;
if ( V_25 <= 0 || V_31 -> V_44 || V_31 -> V_45 )
continue;
if ( ! ( F_3 ( V_1 + 0x02 ) & ( 1 << V_10 -> V_11 ) ) )
continue;
F_25 ( L_4 ,
V_25 , V_10 -> V_11 + 1 ) ;
F_13 ( ( V_10 -> V_11 << V_33 [ V_5 ] . V_12 ) | V_25 ,
V_1 ) ;
V_27 = V_46 ;
V_26 = 0 ;
while ( 1 ) {
V_29 = F_24 ( int , V_25 , ( V_47
- V_10 -> V_48 ) ) ;
if ( V_27 == V_49 ) {
V_27 = V_46 ;
if ( V_29 > 0 ) {
V_26 |= ( V_10 -> V_10 . V_50 [ V_10 -> V_48 ]
<< 8 ) ;
V_10 -> V_48 = ( V_10 -> V_48 + 1 )
& ( V_47 - 1 ) ;
V_10 -> V_43 -- ;
V_25 -- ;
V_29 -- ;
F_13 ( V_26 , V_1 ) ;
} else {
F_13 ( V_26 , V_1 ) ;
break;
}
}
if ( V_29 <= 0 )
break;
V_28 = V_29 >> 1 ;
F_26 ( V_1 , V_10 -> V_10 . V_50 + V_10 -> V_48 , V_28 ) ;
V_10 -> V_48 = ( V_10 -> V_48
+ ( V_28 << 1 ) ) & ( V_47 - 1 ) ;
V_25 -= ( V_28 << 1 ) ;
V_10 -> V_43 -= ( V_28 << 1 ) ;
if ( V_29 & 0x0001 ) {
V_27 = V_49 ;
V_26 = V_10 -> V_10 . V_50 [ V_10 -> V_48 ] ;
V_10 -> V_48 = ( V_10 -> V_48 + 1 )
& ( V_47 - 1 ) ;
V_10 -> V_43 -- ;
V_25 -- ;
}
}
F_14 ( V_1 ) ;
if ( V_10 -> V_43 <= 0 )
V_10 -> V_13 &= ~ V_41 ;
if ( V_10 -> V_43 <= V_51 )
F_27 ( V_31 ) ;
}
V_39:
F_28 ( V_31 ) ;
V_38:
F_9 ( & V_33 [ V_5 ] . V_7 , V_8 ) ;
V_35:
F_29 ( & V_52 , V_53 + F_30 ( 10 ) ) ;
}
static T_2 F_31 ( int V_54 , void * V_55 )
{
struct V_4 * V_5 = V_55 ;
struct V_9 * V_10 ;
struct V_30 * V_31 ;
unsigned long V_1 ;
T_1 V_56 , V_28 , V_2 , V_11 ;
short V_57 ;
unsigned char * V_58 ;
if ( ! V_5 || ! ( V_5 -> V_13 & V_59 ) )
return V_60 ;
V_1 = V_5 -> V_1 ;
if ( ! ( F_3 ( V_1 + 0x0e ) & 0x02 ) )
return V_60 ;
F_32 ( & V_5 -> V_7 ) ;
F_13 ( 0x8000 , V_1 + 0x04 ) ;
F_33 ( V_1 ) ;
F_3 ( V_1 ) ;
V_56 = F_3 ( V_1 ) ;
V_11 = ( V_56 & 0x7800 ) >> V_5 -> V_12 ;
V_57 = V_56 & 0xff ;
if ( V_11 + 1 > V_5 -> V_36 ) {
F_10 ( L_5 ,
V_61 , V_1 , V_11 + 1 ) ;
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_34 ( & V_5 -> V_7 ) ;
return V_62 ;
}
V_10 = V_5 -> V_37 + V_11 ;
if ( ! ( V_10 -> V_10 . V_8 & V_40 ) ) {
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_34 ( & V_5 -> V_7 ) ;
return V_62 ;
}
V_31 = F_23 ( & V_10 -> V_10 ) ;
if ( V_31 == NULL ) {
V_28 = V_57 >> 1 ;
while ( V_57 > 1 ) {
F_3 ( V_1 ) ;
V_57 -= 2 ;
}
if ( V_57 & 0x01 )
F_3 ( V_1 ) ;
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_34 ( & V_5 -> V_7 ) ;
return V_62 ;
}
if ( V_56 & 0x8000 ) {
V_56 = F_3 ( V_1 ) ;
switch ( V_56 & 0xff ) {
case 0 :
if ( V_10 -> V_10 . V_8 & V_63 ) {
if ( V_10 -> V_13 & V_64 ) {
if ( ! ( V_56 & V_64 ) ) {
F_25 ( L_6 ,
V_61 ) ;
V_10 -> V_13 &= ~ V_64 ;
F_35 ( V_31 ) ;
}
} else if ( V_56 & V_64 ) {
F_25 ( L_7 ,
V_61 ) ;
V_10 -> V_13 |= V_64 ;
F_36 ( & V_10 -> V_10 . V_65 ) ;
}
} else {
if ( V_56 & V_64 )
V_10 -> V_13 |= V_64 ;
else
V_10 -> V_13 &= ~ V_64 ;
}
if ( F_37 ( & V_10 -> V_10 ) ) {
if ( V_31 -> V_45 ) {
if ( V_56 & V_66 ) {
V_31 -> V_45 = 0 ;
V_10 -> V_13 |= ( V_41
| V_66 ) ;
F_27 ( V_31 ) ;
}
} else if ( ! ( V_56 & V_66 ) ) {
V_31 -> V_45 = 1 ;
V_10 -> V_13 &= ~ ( V_41 | V_66 ) ;
}
} else {
if ( V_56 & V_66 )
V_10 -> V_13 |= V_66 ;
else
V_10 -> V_13 &= ~ V_66 ;
}
if ( V_56 & V_67 )
V_10 -> V_13 |= V_67 ;
else
V_10 -> V_13 &= ~ V_67 ;
if ( V_56 & V_68 )
V_10 -> V_13 |= V_68 ;
else
V_10 -> V_13 &= ~ V_68 ;
break;
case 1 :
F_38 ( & V_10 -> V_10 , 0 , V_69 ) ;
if ( V_10 -> V_10 . V_8 & V_70 )
F_39 ( V_31 ) ;
F_40 ( & V_10 -> V_10 ) ;
break;
case 2 :
F_25 ( L_8 , V_61 ) ;
break;
default:
F_25 ( L_9 ,
V_61 ) ;
break;
}
} else {
V_2 = F_41 ( & V_10 -> V_10 , & V_58 ,
V_57 & ~ 1 ) ;
F_25 ( L_10 ,
V_61 , V_2 , V_57 ) ;
V_28 = V_2 >> 1 ;
F_42 ( V_1 , V_58 , V_28 ) ;
V_57 -= ( V_28 << 1 ) ;
if ( V_2 & 0x0001 ) {
F_38 ( & V_10 -> V_10 , F_3 ( V_1 ) & 0xff ,
V_71 ) ;
V_57 -= 2 ;
}
if ( V_57 > 0 ) {
F_25 ( L_11 ,
V_61 , V_1 , V_11 + 1 ) ;
while ( V_57 > 0 ) {
F_3 ( V_1 ) ;
V_57 -= 2 ;
}
}
F_40 ( & V_10 -> V_10 ) ;
}
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_34 ( & V_5 -> V_7 ) ;
F_28 ( V_31 ) ;
return V_62 ;
}
static void F_43 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_73 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_74 , V_11 = V_10 -> V_11 ,
V_12 = V_5 -> V_12 ;
unsigned char V_75 ;
V_73 = F_44 ( V_31 ) ;
if ( V_73 & V_76 ) {
V_73 &= ~ V_76 ;
if ( V_73 < 1 || V_73 > 4 )
V_31 -> V_77 . V_78 &= ~ V_76 ;
else
V_73 += 15 ;
}
if ( V_73 == 15 ) {
if ( ( V_10 -> V_10 . V_8 & V_79 ) == V_80 )
V_73 ++ ;
if ( ( V_10 -> V_10 . V_8 & V_79 ) == V_81 )
V_73 += 2 ;
if ( ( V_10 -> V_10 . V_8 & V_79 ) == V_82 )
V_73 += 3 ;
if ( ( V_10 -> V_10 . V_8 & V_79 ) == V_83 )
V_73 += 4 ;
}
if ( V_84 [ V_73 ] == - 1 ) {
F_15 ( V_10 ) ;
return;
} else
F_12 ( V_10 ) ;
if ( F_1 ( V_1 ) == 0 ) {
F_13 ( 0x8000 | ( V_11 << V_12 ) | 0x03 , V_1 ) ;
F_13 ( V_84 [ V_73 ] << 8 | 0x03 , V_1 ) ;
V_74 = 0 ;
switch ( F_45 ( V_31 ) ) {
case V_85 :
V_74 |= V_86 ;
break;
case V_87 :
V_74 |= V_88 ;
break;
case V_89 :
V_74 |= V_90 ;
break;
case V_91 :
V_74 |= V_92 ;
break;
}
if ( F_46 ( V_31 ) )
V_74 |= V_93 ;
if ( F_47 ( V_31 ) ) {
V_74 |= V_94 ;
if ( F_48 ( V_31 ) )
V_74 |= V_95 ;
}
F_13 ( V_74 , V_1 ) ;
F_14 ( V_1 ) ;
}
if ( F_49 ( V_31 ) )
V_10 -> V_10 . V_8 &= ~ V_63 ;
else
V_10 -> V_10 . V_8 |= V_63 ;
V_75 = 0 ;
V_10 -> V_10 . V_8 &= ~ V_96 ;
if ( F_50 ( V_31 ) ) {
V_10 -> V_10 . V_8 |= V_96 ;
V_75 |= V_97 ;
}
if ( F_51 ( V_31 ) )
V_75 |= V_98 ;
if ( F_52 ( V_31 ) )
V_75 |= V_99 ;
if ( F_1 ( V_1 ) == 0 ) {
F_13 ( 0x8000 | ( V_11 << V_12 ) | 0x04 , V_1 ) ;
F_13 ( V_75 << 8 | 0x05 , V_1 ) ;
F_13 ( ( F_53 ( V_31 ) ) << 8 | ( F_54 ( V_31 ) ) , V_1 ) ;
F_14 ( V_1 ) ;
}
if ( F_55 ( V_31 ) ) {
V_5 -> V_100 |= ( 1 << V_11 ) ;
F_13 ( V_5 -> V_100 , V_1 + 0x02 ) ;
}
}
static inline void F_56 ( struct V_4 * V_101 )
{
int V_11 ;
struct V_9 * V_10 ;
V_101 -> V_2 ++ ;
if ( ! ( V_101 -> V_13 & V_102 ) ) {
V_10 = V_101 -> V_37 ;
for ( V_11 = 0 ; V_11 < V_101 -> V_36 ; V_11 ++ , V_10 ++ )
F_20 ( V_10 ) ;
}
V_101 -> V_13 |= V_34 | V_102 ;
}
static int F_57 ( struct V_16 * V_103 , struct V_30 * V_31 )
{
struct V_9 * V_10 = F_19 ( V_103 , struct V_9 , V_10 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
if ( F_58 ( V_103 ) < 0 )
return - V_104 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
F_56 ( V_5 ) ;
V_10 -> V_43 = V_10 -> V_105 = V_10 -> V_48 = 0 ;
if ( F_1 ( V_5 -> V_1 ) == 0 ) {
F_13 ( 0x8000 | ( V_10 -> V_11 << V_5 -> V_12 ) | 0x02 ,
V_5 -> V_1 ) ;
F_13 ( ( ( V_106 | V_107 ) << 8 ) | 0x06 , V_5 -> V_1 ) ;
F_14 ( V_5 -> V_1 ) ;
}
F_43 ( V_31 ) ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
return 0 ;
}
static int F_59 ( struct V_16 * V_10 )
{
struct V_9 * V_18 = F_19 ( V_10 , struct V_9 , V_10 ) ;
return ( V_18 -> V_13 & V_64 ) ? 1 : 0 ;
}
static struct V_16 * F_60 ( struct V_30 * V_31 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
unsigned int V_108 ;
int line = V_31 -> V_109 ;
V_108 = F_61 ( line ) ;
V_5 = & V_33 [ V_108 ] ;
if ( ! ( V_5 -> V_13 & V_59 ) )
return NULL ;
if ( line > ( ( V_108 * 16 ) + V_5 -> V_36 - 1 ) )
return NULL ;
V_10 = & V_110 [ line ] ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_12 ) )
return NULL ;
return & V_10 -> V_10 ;
}
static int F_63 ( struct V_30 * V_31 , struct V_111 * V_112 )
{
struct V_9 * V_10 ;
struct V_16 * V_103 ;
V_103 = F_60 ( V_31 ) ;
if ( V_103 == NULL )
return - V_113 ;
V_10 = F_19 ( V_103 , struct V_9 , V_10 ) ;
V_31 -> V_72 = V_10 ;
return F_64 ( V_103 , V_31 , V_112 ) ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( -- V_5 -> V_2 < 0 ) {
F_25 ( L_13 ,
V_61 , V_5 -> V_1 , V_5 -> V_2 ) ;
V_5 -> V_2 = 0 ;
}
if ( ! V_5 -> V_2 )
V_5 -> V_13 &= V_34 ;
}
static void F_66 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_14 ) )
return;
F_7 ( & V_5 -> V_7 , V_8 ) ;
V_10 -> V_43 = V_10 -> V_105 = V_10 -> V_48 = 0 ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
F_27 ( V_31 ) ;
}
static void F_67 ( struct V_16 * V_10 )
{
struct V_9 * V_18 = F_19 ( V_10 , struct V_9 , V_10 ) ;
struct V_4 * V_5 = V_18 -> V_5 ;
unsigned long V_8 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
V_5 -> V_100 &= ~ ( 1 << V_18 -> V_11 ) ;
F_13 ( V_5 -> V_100 , V_5 -> V_1 + 0x02 ) ;
F_65 ( V_18 ) ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
F_68 ( V_10 ) ;
}
static void F_69 ( struct V_30 * V_31 , struct V_111 * V_112 )
{
struct V_9 * V_18 = V_31 -> V_72 ;
struct V_16 * V_10 ;
if ( V_18 == NULL )
return;
V_10 = & V_18 -> V_10 ;
if ( F_62 ( V_18 , V_31 -> V_19 , L_15 ) )
return;
F_70 ( V_10 , V_31 , V_112 ) ;
}
static int F_71 ( struct V_30 * V_31 , const unsigned char * V_114 ,
int V_2 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
int V_29 , V_115 = 0 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_16 ) )
return 0 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
while ( 1 ) {
V_29 = F_24 ( int , V_2 , F_72 ( V_47 - V_10 -> V_43
- 1 , V_47 - V_10 -> V_105 ) ) ;
if ( V_29 <= 0 )
break;
memcpy ( V_10 -> V_10 . V_50 + V_10 -> V_105 , V_114 , V_29 ) ;
V_10 -> V_105 = ( V_10 -> V_105 + V_29 ) & ( V_47
- 1 ) ;
V_10 -> V_43 += V_29 ;
V_114 += V_29 ;
V_2 -= V_29 ;
V_115 += V_29 ;
}
if ( V_10 -> V_43 && ! V_31 -> V_44 && ! V_31 -> V_45 )
V_10 -> V_13 |= V_41 ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
return V_115 ;
}
static int F_73 ( struct V_30 * V_31 , unsigned char V_116 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_17 ) )
return 0 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
if ( V_10 -> V_43 >= V_47 - 1 ) {
F_9 ( & V_5 -> V_7 , V_8 ) ;
return 0 ;
}
V_10 -> V_10 . V_50 [ V_10 -> V_105 ++ ] = V_116 ;
V_10 -> V_105 &= ( V_47 - 1 ) ;
V_10 -> V_43 ++ ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
return 1 ;
}
static void F_74 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_18 ) )
return;
if ( V_10 -> V_43 <= 0 || V_31 -> V_44 || V_31 -> V_45 ||
! V_10 -> V_10 . V_50 )
return;
V_10 -> V_13 |= V_41 ;
}
static int F_75 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
int free ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_19 ) )
return 0 ;
free = V_47 - V_10 -> V_43 - 1 ;
if ( free < 0 )
free = 0 ;
return free ;
}
static int F_76 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_20 ) )
return 0 ;
return V_10 -> V_43 ;
}
static int F_77 ( struct V_30 * V_31 , int V_117 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
if ( V_117 == - 1 )
return - V_118 ;
if ( ! F_6 ( V_5 ) )
return - V_119 ;
F_13 ( 0x8000 | ( ( V_10 -> V_11 ) << ( V_5 -> V_12 ) ) | 0x3 , V_1 ) ;
F_13 ( ( V_117 & 0xff ) << 8 | 0x00 , V_1 ) ;
F_13 ( ( V_117 & 0xff00u ) , V_1 ) ;
F_14 ( V_1 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static int F_78 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
T_1 V_13 = V_10 -> V_13 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_21 ) )
return - V_113 ;
return ( ( V_13 & V_15 ) ? V_120 : 0 ) |
( ( V_13 & V_14 ) ? V_121 : 0 ) |
( ( V_13 & V_64 ) ? V_122 : 0 ) |
( ( V_13 & V_67 ) ? V_123 : 0 ) |
( ( V_13 & V_66 ) ? V_124 : 0 ) |
( ( V_13 & V_68 ) ? V_125 : 0 ) ;
}
static int F_79 ( struct V_30 * V_31 ,
unsigned int V_126 , unsigned int V_127 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
unsigned long V_8 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_21 ) )
return - V_113 ;
F_7 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
if ( V_126 & V_120 )
F_16 ( V_10 ) ;
if ( V_126 & V_121 )
F_12 ( V_10 ) ;
if ( V_127 & V_120 )
F_17 ( V_10 ) ;
if ( V_127 & V_121 )
F_15 ( V_10 ) ;
F_9 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
return 0 ;
}
static int F_80 ( struct V_30 * V_31 ,
struct V_128 T_3 * V_129 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_128 V_130 ;
int V_131 ;
if ( F_81 ( & V_130 , V_129 , sizeof( V_130 ) ) )
return - V_132 ;
F_82 ( & V_10 -> V_10 . V_133 ) ;
V_131 = ( ( V_10 -> V_10 . V_8 & V_79 ) !=
( V_130 . V_8 & V_79 ) ) ;
if ( ! F_83 ( V_134 ) ) {
if ( ( V_130 . V_135 != V_10 -> V_10 . V_135 ) ||
( V_130 . V_136 != V_10 -> V_10 . V_136 ) ||
( ( V_130 . V_8 & ~ V_137 ) !=
( V_10 -> V_10 . V_8 & ~ V_137 ) ) ) {
F_84 ( & V_10 -> V_10 . V_133 ) ;
return - V_138 ;
}
V_10 -> V_10 . V_8 = ( ( V_10 -> V_10 . V_8 & ~ V_137 ) |
( V_130 . V_8 & V_137 ) ) ;
} else {
V_10 -> V_10 . V_135 = V_130 . V_135 ;
V_10 -> V_10 . V_136 = V_130 . V_136 ;
V_10 -> V_10 . V_8 = ( ( V_10 -> V_10 . V_8 & ~ V_139 ) |
( V_130 . V_8 & V_139 ) ) ;
}
if ( V_131 ) {
unsigned long V_8 ;
F_7 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
F_43 ( V_31 ) ;
F_9 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
}
F_84 ( & V_10 -> V_10 . V_133 ) ;
return 0 ;
}
static int F_85 ( struct V_9 * V_10 ,
struct V_128 T_3 * V_129 )
{
struct V_128 V_140 ;
F_82 ( & V_10 -> V_10 . V_133 ) ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . line = V_10 - V_110 ;
V_140 . V_10 = V_10 -> V_5 -> V_1 ;
V_140 . V_54 = V_10 -> V_5 -> V_54 ;
V_140 . V_8 = V_10 -> V_10 . V_8 ;
V_140 . V_135 = V_10 -> V_10 . V_135 ;
V_140 . V_136 = V_10 -> V_10 . V_136 ;
F_84 ( & V_10 -> V_10 . V_133 ) ;
if ( F_86 ( V_129 , & V_140 , sizeof( V_140 ) ) )
return - V_132 ;
return 0 ;
}
static int F_87 ( struct V_30 * V_31 ,
unsigned int V_141 , unsigned long V_142 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
void T_3 * V_143 = ( void T_3 * ) V_142 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_21 ) )
return - V_113 ;
switch ( V_141 ) {
case V_144 :
return F_85 ( V_10 , V_143 ) ;
case V_145 :
return F_80 ( V_31 , V_143 ) ;
default:
return - V_146 ;
}
return 0 ;
}
static void F_88 ( struct V_30 * V_31 ,
struct V_147 * V_148 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
unsigned long V_8 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_22 ) )
return;
if ( V_31 -> V_77 . V_78 == V_148 -> V_78 &&
V_31 -> V_77 . V_149 == V_148 -> V_149 )
return;
F_7 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
F_43 ( V_31 ) ;
F_9 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
if ( ( V_148 -> V_78 & V_150 ) &&
! ( V_31 -> V_77 . V_78 & V_150 ) ) {
V_31 -> V_45 = 0 ;
F_89 ( V_31 ) ;
}
}
static void F_90 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_23 ) )
return;
V_5 -> V_100 &= ~ ( 1 << V_10 -> V_11 ) ;
F_13 ( V_5 -> V_100 , V_5 -> V_1 + 0x02 ) ;
}
static void F_91 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_24 ) )
return;
V_5 -> V_100 |= ( 1 << V_10 -> V_11 ) ;
F_13 ( V_5 -> V_100 , V_5 -> V_1 + 0x02 ) ;
}
static void F_92 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_25 ) )
return;
V_10 -> V_13 &= ~ V_41 ;
}
static void F_89 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_26 ) )
return;
V_10 -> V_13 |= V_41 ;
}
static void F_93 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_72 ;
if ( F_62 ( V_10 , V_31 -> V_19 , L_27 ) )
return;
F_94 ( & V_10 -> V_10 ) ;
}
static int F_95 ( struct V_151 * V_152 ,
const unsigned int V_5 , unsigned int * V_153 )
{
struct V_4 * V_108 = F_96 ( V_152 ) ;
unsigned long V_1 = V_108 -> V_1 ;
unsigned int V_154 , V_155 = 0 ;
int V_156 = 0 ;
F_97 ( & V_152 -> V_157 , L_28 , V_5 + 1 ,
V_1 ) ;
F_3 ( V_1 + 0x8 ) ;
F_5 ( 10 ) ;
F_13 ( 0 , V_1 + 0x8 ) ;
F_5 ( 1000 ) ;
V_154 = F_3 ( V_1 + 0x4 ) & 0xff ;
if ( V_154 != 0xa5 && V_154 != 0xbb && V_154 != 0xcc && V_154 != 0xdd &&
V_154 != 0xee ) {
F_98 ( & V_152 -> V_157 , L_29
L_30 , V_5 + 1 , V_1 ) ;
F_97 ( & V_152 -> V_157 , L_31 , V_154 ) ;
V_156 = - V_158 ;
goto V_159;
}
F_5 ( 10 ) ;
V_155 = F_3 ( V_1 + 0x2 ) ;
if ( ! ( F_3 ( V_1 + 0xe ) & 0x1 ) || ( V_155 != 0 && V_155 != 4 &&
V_155 != 8 && V_155 != 16 ) ) {
F_99 ( & V_152 -> V_157 , L_32 ,
V_5 + 1 ) ;
V_156 = - V_158 ;
goto V_159;
}
switch ( V_154 ) {
case 0xa5 :
case 0xbb :
case 0xdd :
V_108 -> V_36 = ( V_155 == 4 ) ? 4 : 8 ;
V_108 -> V_12 = 12 ;
break;
case 0xcc :
case 0xee :
V_108 -> V_36 = 16 ;
V_108 -> V_12 = 11 ;
break;
}
F_100 ( & V_152 -> V_157 , L_33 ) ;
* V_153 = V_154 ;
V_159:
return V_156 ;
}
static int F_101 ( struct V_151 * V_152 ,
const unsigned int V_109 , const unsigned int V_153 )
{
struct V_4 * V_108 = F_96 ( V_152 ) ;
const struct V_160 * V_161 ;
unsigned long V_1 = V_108 -> V_1 ;
unsigned int V_3 ;
T_1 V_28 , V_13 ;
int V_156 = - V_158 ;
char * V_19 ;
T_4 * V_162 ;
struct V_163 {
T_1 V_164 ;
T_1 V_2 ;
T_4 V_162 [ 0 ] ;
} * V_165 ;
switch ( V_153 ) {
case 0xa5 :
V_19 = L_34 ;
break;
case 0xbb :
V_19 = L_35 ;
break;
case 0xcc :
V_19 = L_36 ;
break;
case 0xdd :
V_19 = L_37 ;
break;
case 0xee :
V_19 = L_38 ;
break;
default:
F_99 ( & V_152 -> V_157 , L_39 ) ;
goto V_159;
}
V_156 = F_102 ( & V_161 , V_19 , & V_152 -> V_157 ) ;
if ( V_156 )
goto V_159;
V_156 = - V_158 ;
for ( V_165 = (struct V_163 * ) V_161 -> V_162 ;
V_165 < (struct V_163 * ) ( V_161 -> V_162 + V_161 -> V_166 ) ;
V_165 = (struct V_163 * ) ( ( T_4 * ) ( V_165 + 1 ) +
V_165 -> V_2 ) ) {
if ( F_1 ( V_1 ) )
goto V_167;
F_13 ( 0xf0 , V_1 ) ;
F_13 ( 0x00 , V_1 ) ;
F_13 ( V_165 -> V_164 , V_1 ) ;
V_28 = V_165 -> V_2 / 2 + V_165 -> V_2 % 2 ;
F_13 ( V_28 , V_1 ) ;
F_14 ( V_1 ) ;
F_8 ( 100 ) ;
if ( F_1 ( V_1 ) )
goto V_167;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_98 ( & V_152 -> V_157 , L_40
L_41
L_42
L_43 ,
V_109 + 1 , V_165 -> V_164 , V_165 -> V_2 , V_13 ) ;
goto V_167;
}
F_26 ( V_1 , V_165 -> V_162 , V_28 ) ;
F_14 ( V_1 ) ;
F_8 ( 50 ) ;
if ( F_1 ( V_1 ) )
goto V_167;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_99 ( & V_152 -> V_157 , L_44
L_43 , V_109 + 1 , V_13 ) ;
goto V_167;
}
}
for ( V_165 = (struct V_163 * ) V_161 -> V_162 ;
V_165 < (struct V_163 * ) ( V_161 -> V_162 + V_161 -> V_166 ) ;
V_165 = (struct V_163 * ) ( ( T_4 * ) ( V_165 + 1 ) +
V_165 -> V_2 ) ) {
if ( F_1 ( V_1 ) )
goto V_167;
F_13 ( 0xf1 , V_1 ) ;
F_13 ( 0x00 , V_1 ) ;
F_13 ( V_165 -> V_164 , V_1 ) ;
V_28 = ( V_165 -> V_2 >> 1 ) + V_165 -> V_2 % 2 ;
F_13 ( V_28 + 1 , V_1 ) ;
F_14 ( V_1 ) ;
F_8 ( 50 ) ;
if ( F_1 ( V_1 ) )
goto V_167;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_98 ( & V_152 -> V_157 , L_45
L_41
L_42
L_46 ,
V_109 + 1 , V_165 -> V_164 , V_165 -> V_2 , V_13 ) ;
goto V_167;
}
V_162 = F_103 ( V_28 * 2 , V_168 ) ;
if ( V_162 == NULL ) {
F_99 ( & V_152 -> V_157 , L_47
L_48 , V_109 + 1 ) ;
goto V_167;
}
F_3 ( V_1 ) ;
F_42 ( V_1 , V_162 , V_28 ) ;
F_14 ( V_1 ) ;
for ( V_3 = 0 ; V_3 < V_165 -> V_2 ; V_3 ++ )
if ( V_162 [ V_3 ] != V_165 -> V_162 [ V_3 ] ) {
F_104 ( V_162 ) ;
F_99 ( & V_152 -> V_157 , L_47
L_49 , V_109 + 1 ) ;
goto V_167;
}
F_104 ( V_162 ) ;
F_8 ( 50 ) ;
if ( F_1 ( V_1 ) )
goto V_167;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_99 ( & V_152 -> V_157 , L_50
L_51 , V_109 + 1 , V_13 ) ;
goto V_167;
}
}
if ( F_1 ( V_1 ) )
goto V_167;
F_13 ( 0xf2 , V_1 ) ;
F_13 ( 0x800 , V_1 ) ;
F_13 ( 0x0 , V_1 ) ;
F_13 ( 0x0 , V_1 ) ;
F_14 ( V_1 ) ;
F_13 ( 0x0 , V_1 + 0x4 ) ;
V_108 -> V_13 |= V_59 ;
V_156 = 0 ;
V_167:
F_105 ( V_161 ) ;
V_159:
return V_156 ;
}
static int F_106 ( struct V_151 * V_152 ,
const struct V_169 * V_170 )
{
unsigned int V_171 ( V_153 ) , V_109 ;
int V_156 = - V_138 ;
struct V_4 * V_108 = NULL ;
if ( V_172 >= V_24 )
goto V_173;
V_156 = F_107 ( V_152 ) ;
if ( V_156 ) {
F_99 ( & V_152 -> V_157 , L_52 ) ;
goto V_173;
}
F_100 ( & V_152 -> V_157 , L_53 , V_170 -> V_174 ) ;
for ( V_109 = 0 ; V_109 < V_24 ; V_109 ++ ) {
if ( V_33 [ V_109 ] . V_1 == 0 ) {
V_108 = & V_33 [ V_109 ] ;
break;
}
}
if ( V_109 == V_24 ) {
V_156 = - V_113 ;
goto V_175;
}
V_108 -> V_109 = V_109 ;
V_108 -> V_1 = F_108 ( V_152 , 3 ) ;
V_108 -> V_54 = V_152 -> V_54 ;
V_172 ++ ;
F_109 ( V_152 , V_108 ) ;
V_156 = F_110 ( V_152 , 3 , V_176 ) ;
if ( V_156 ) {
F_99 ( & V_152 -> V_157 , L_54
L_55 , V_108 -> V_1 , V_108 -> V_1 + 15 ,
V_109 + 1 ) ;
V_156 = - V_177 ;
goto V_178;
}
V_156 = F_111 ( V_108 -> V_54 , F_31 ,
V_179 , V_176 , V_108 ) ;
if ( V_156 < 0 ) {
F_99 ( & V_152 -> V_157 , L_56
L_57 , V_108 -> V_54 , V_109 + 1 ) ;
goto V_180;
}
V_156 = F_95 ( V_152 , V_109 , & V_153 ) ;
if ( V_156 < 0 )
goto V_181;
V_156 = F_101 ( V_152 , V_109 , V_153 ) ;
if ( V_156 < 0 )
goto V_181;
for ( V_109 = 0 ; V_109 < V_108 -> V_36 ; V_109 ++ ) {
struct V_16 * V_103 = & V_108 -> V_37 [ V_109 ] . V_10 ;
F_112 ( V_103 ) ;
V_103 -> V_182 = & V_183 ;
V_103 -> V_135 = 50 * V_184 / 100 ;
V_103 -> V_136 = 3000 * V_184 / 100 ;
F_113 ( V_103 , V_185 ,
V_108 -> V_109 * 16 + V_109 , & V_152 -> V_157 ) ;
}
return 0 ;
V_181:
F_114 ( V_108 -> V_54 , V_108 ) ;
V_180:
F_115 ( V_152 , 3 ) ;
V_178:
V_108 -> V_1 = 0 ;
V_172 -- ;
V_175:
F_116 ( V_152 ) ;
V_173:
return V_156 ;
}
static void F_117 ( struct V_151 * V_152 )
{
struct V_4 * V_108 = F_96 ( V_152 ) ;
unsigned int V_186 ;
for ( V_186 = 0 ; V_186 < V_108 -> V_36 ; V_186 ++ ) {
F_118 ( V_185 , V_108 -> V_109 * 16 + V_186 ) ;
F_119 ( & V_108 -> V_37 [ V_186 ] . V_10 ) ;
}
F_114 ( V_108 -> V_54 , V_108 ) ;
F_115 ( V_152 , 3 ) ;
V_108 -> V_1 = 0 ;
V_172 -- ;
F_116 ( V_152 ) ;
}
static int T_5 F_120 ( void )
{
int V_156 , V_187 , V_11 ;
struct V_9 * V_10 ;
for ( V_187 = 0 ; V_187 < V_24 ; V_187 ++ ) {
V_10 = & V_110 [ V_187 * 16 ] ;
V_33 [ V_187 ] . V_37 = V_10 ;
F_121 ( & V_33 [ V_187 ] . V_7 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ , V_10 ++ ) {
V_10 -> V_21 = V_22 ;
V_10 -> V_5 = & V_33 [ V_187 ] ;
V_10 -> V_11 = V_11 ;
V_10 -> V_13 = 0 ;
}
V_33 [ V_187 ] . V_1 = 0 ;
V_33 [ V_187 ] . V_54 = 0 ;
}
V_185 = F_122 ( V_188 ) ;
if ( ! V_185 ) {
V_156 = - V_104 ;
goto error;
}
V_185 -> V_19 = L_58 ;
V_185 -> V_189 = V_190 ;
V_185 -> V_191 = 0 ;
V_185 -> type = V_192 ;
V_185 -> V_193 = V_194 ;
V_185 -> V_195 = V_196 ;
V_185 -> V_195 . V_78 = V_197 | V_91 | V_198 | V_199 |
V_200 ;
V_185 -> V_8 = V_201 |
V_202 | V_203 ;
F_123 ( V_185 , & V_204 ) ;
V_156 = F_124 ( V_185 ) ;
if ( V_156 ) {
F_25 ( L_59 ) ;
goto V_205;
}
V_156 = F_125 ( & V_206 ) ;
if ( V_156 < 0 ) {
F_126 ( L_60 ) ;
goto V_207;
}
F_29 ( & V_52 , V_53 + 1 ) ;
return 0 ;
V_207:
F_127 ( V_185 ) ;
V_205:
F_128 ( V_185 ) ;
error:
return V_156 ;
}
static void T_6 F_129 ( void )
{
F_130 ( & V_52 ) ;
F_131 ( & V_206 ) ;
F_127 ( V_185 ) ;
F_128 ( V_185 ) ;
}
