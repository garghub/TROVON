static int F_1 ( unsigned long V_1 )
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
static void F_15 ( struct V_9 * V_10 )
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
if ( ! F_24 ( & V_10 -> V_10 ) ||
! ( V_10 -> V_13 & V_40 ) )
continue;
V_25 = F_25 ( short , V_41 , V_10 -> V_42 ) ;
if ( V_25 <= 0 || V_31 -> V_43 || V_31 -> V_44 )
continue;
if ( ! ( F_3 ( V_1 + 0x02 ) & ( 1 << V_10 -> V_11 ) ) )
continue;
F_26 ( L_4 ,
V_25 , V_10 -> V_11 + 1 ) ;
F_13 ( ( V_10 -> V_11 << V_33 [ V_5 ] . V_12 ) | V_25 ,
V_1 ) ;
V_27 = V_45 ;
V_26 = 0 ;
while ( 1 ) {
V_29 = F_25 ( int , V_25 , ( V_46
- V_10 -> V_47 ) ) ;
if ( V_27 == V_48 ) {
V_27 = V_45 ;
if ( V_29 > 0 ) {
V_26 |= ( V_10 -> V_10 . V_49 [ V_10 -> V_47 ]
<< 8 ) ;
V_10 -> V_47 = ( V_10 -> V_47 + 1 )
& ( V_46 - 1 ) ;
V_10 -> V_42 -- ;
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
F_27 ( V_1 , V_10 -> V_10 . V_49 + V_10 -> V_47 , V_28 ) ;
V_10 -> V_47 = ( V_10 -> V_47
+ ( V_28 << 1 ) ) & ( V_46 - 1 ) ;
V_25 -= ( V_28 << 1 ) ;
V_10 -> V_42 -= ( V_28 << 1 ) ;
if ( V_29 & 0x0001 ) {
V_27 = V_48 ;
V_26 = V_10 -> V_10 . V_49 [ V_10 -> V_47 ] ;
V_10 -> V_47 = ( V_10 -> V_47 + 1 )
& ( V_46 - 1 ) ;
V_10 -> V_42 -- ;
V_25 -- ;
}
}
F_14 ( V_1 ) ;
if ( V_10 -> V_42 <= 0 )
V_10 -> V_13 &= ~ V_40 ;
if ( V_10 -> V_42 <= V_50 )
F_28 ( V_31 ) ;
}
V_39:
F_29 ( V_31 ) ;
V_38:
F_9 ( & V_33 [ V_5 ] . V_7 , V_8 ) ;
V_35:
F_30 ( & V_51 , V_52 + F_31 ( 10 ) ) ;
}
static T_2 F_32 ( int V_53 , void * V_54 )
{
struct V_4 * V_5 = V_54 ;
struct V_9 * V_10 ;
struct V_30 * V_31 ;
unsigned long V_1 ;
T_1 V_55 , V_28 , V_2 , V_11 ;
short V_56 ;
unsigned char * V_57 ;
if ( ! V_5 || ! ( V_5 -> V_13 & V_58 ) )
return V_59 ;
V_1 = V_5 -> V_1 ;
if ( ! ( F_3 ( V_1 + 0x0e ) & 0x02 ) )
return V_59 ;
F_33 ( & V_5 -> V_7 ) ;
F_13 ( 0x8000 , V_1 + 0x04 ) ;
F_34 ( V_1 ) ;
F_3 ( V_1 ) ;
V_55 = F_3 ( V_1 ) ;
V_11 = ( V_55 & 0x7800 ) >> V_5 -> V_12 ;
V_56 = V_55 & 0xff ;
if ( V_11 + 1 > V_5 -> V_36 ) {
F_10 ( L_5 ,
V_60 , V_1 , V_11 + 1 ) ;
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_35 ( & V_5 -> V_7 ) ;
return V_61 ;
}
V_10 = V_5 -> V_37 + V_11 ;
if ( ! F_24 ( & V_10 -> V_10 ) ) {
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_35 ( & V_5 -> V_7 ) ;
return V_61 ;
}
V_31 = F_23 ( & V_10 -> V_10 ) ;
if ( V_31 == NULL ) {
V_28 = V_56 >> 1 ;
while ( V_56 > 1 ) {
F_3 ( V_1 ) ;
V_56 -= 2 ;
}
if ( V_56 & 0x01 )
F_3 ( V_1 ) ;
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_35 ( & V_5 -> V_7 ) ;
return V_61 ;
}
if ( V_55 & 0x8000 ) {
V_55 = F_3 ( V_1 ) ;
switch ( V_55 & 0xff ) {
case 0 :
if ( F_36 ( & V_10 -> V_10 ) ) {
if ( V_10 -> V_13 & V_62 ) {
if ( ! ( V_55 & V_62 ) ) {
F_26 ( L_6 ,
V_60 ) ;
V_10 -> V_13 &= ~ V_62 ;
F_37 ( V_31 ) ;
}
} else if ( V_55 & V_62 ) {
F_26 ( L_7 ,
V_60 ) ;
V_10 -> V_13 |= V_62 ;
F_38 ( & V_10 -> V_10 . V_63 ) ;
}
} else {
if ( V_55 & V_62 )
V_10 -> V_13 |= V_62 ;
else
V_10 -> V_13 &= ~ V_62 ;
}
if ( F_39 ( & V_10 -> V_10 ) ) {
if ( V_31 -> V_44 ) {
if ( V_55 & V_64 ) {
V_31 -> V_44 = 0 ;
V_10 -> V_13 |= ( V_40
| V_64 ) ;
F_28 ( V_31 ) ;
}
} else if ( ! ( V_55 & V_64 ) ) {
V_31 -> V_44 = 1 ;
V_10 -> V_13 &= ~ ( V_40 | V_64 ) ;
}
} else {
if ( V_55 & V_64 )
V_10 -> V_13 |= V_64 ;
else
V_10 -> V_13 &= ~ V_64 ;
}
if ( V_55 & V_65 )
V_10 -> V_13 |= V_65 ;
else
V_10 -> V_13 &= ~ V_65 ;
if ( V_55 & V_66 )
V_10 -> V_13 |= V_66 ;
else
V_10 -> V_13 &= ~ V_66 ;
break;
case 1 :
F_40 ( & V_10 -> V_10 , 0 , V_67 ) ;
if ( V_10 -> V_10 . V_8 & V_68 )
F_41 ( V_31 ) ;
F_42 ( & V_10 -> V_10 ) ;
break;
case 2 :
F_26 ( L_8 , V_60 ) ;
break;
default:
F_26 ( L_9 ,
V_60 ) ;
break;
}
} else {
V_2 = F_43 ( & V_10 -> V_10 , & V_57 ,
V_56 & ~ 1 ) ;
F_26 ( L_10 ,
V_60 , V_2 , V_56 ) ;
V_28 = V_2 >> 1 ;
F_44 ( V_1 , V_57 , V_28 ) ;
V_56 -= ( V_28 << 1 ) ;
if ( V_2 & 0x0001 ) {
F_40 ( & V_10 -> V_10 , F_3 ( V_1 ) & 0xff ,
V_69 ) ;
V_56 -= 2 ;
}
if ( V_56 > 0 ) {
F_26 ( L_11 ,
V_60 , V_1 , V_11 + 1 ) ;
while ( V_56 > 0 ) {
F_3 ( V_1 ) ;
V_56 -= 2 ;
}
}
F_42 ( & V_10 -> V_10 ) ;
}
F_13 ( 0x0000 , V_1 + 0x04 ) ;
F_35 ( & V_5 -> V_7 ) ;
F_29 ( V_31 ) ;
return V_61 ;
}
static void F_45 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_71 ;
unsigned long V_1 = V_5 -> V_1 ;
T_1 V_72 , V_11 = V_10 -> V_11 ,
V_12 = V_5 -> V_12 ;
unsigned char V_73 ;
V_71 = F_46 ( V_31 ) ;
if ( V_71 & V_74 ) {
V_71 &= ~ V_74 ;
if ( V_71 < 1 || V_71 > 4 )
V_31 -> V_75 . V_76 &= ~ V_74 ;
else
V_71 += 15 ;
}
if ( V_71 == 15 ) {
if ( ( V_10 -> V_10 . V_8 & V_77 ) == V_78 )
V_71 ++ ;
if ( ( V_10 -> V_10 . V_8 & V_77 ) == V_79 )
V_71 += 2 ;
if ( ( V_10 -> V_10 . V_8 & V_77 ) == V_80 )
V_71 += 3 ;
if ( ( V_10 -> V_10 . V_8 & V_77 ) == V_81 )
V_71 += 4 ;
}
if ( V_82 [ V_71 ] == - 1 ) {
F_15 ( V_10 ) ;
return;
} else
F_12 ( V_10 ) ;
if ( F_1 ( V_1 ) == 0 ) {
F_13 ( 0x8000 | ( V_11 << V_12 ) | 0x03 , V_1 ) ;
F_13 ( V_82 [ V_71 ] << 8 | 0x03 , V_1 ) ;
V_72 = 0 ;
switch ( F_47 ( V_31 ) ) {
case V_83 :
V_72 |= V_84 ;
break;
case V_85 :
V_72 |= V_86 ;
break;
case V_87 :
V_72 |= V_88 ;
break;
case V_89 :
V_72 |= V_90 ;
break;
}
if ( F_48 ( V_31 ) )
V_72 |= V_91 ;
if ( F_49 ( V_31 ) ) {
V_72 |= V_92 ;
if ( F_50 ( V_31 ) )
V_72 |= V_93 ;
}
F_13 ( V_72 , V_1 ) ;
F_14 ( V_1 ) ;
}
F_51 ( & V_10 -> V_10 , ! F_52 ( V_31 ) ) ;
V_73 = 0 ;
F_53 ( & V_10 -> V_10 , F_54 ( V_31 ) ) ;
if ( F_54 ( V_31 ) )
V_73 |= V_94 ;
if ( F_55 ( V_31 ) )
V_73 |= V_95 ;
if ( F_56 ( V_31 ) )
V_73 |= V_96 ;
if ( F_1 ( V_1 ) == 0 ) {
F_13 ( 0x8000 | ( V_11 << V_12 ) | 0x04 , V_1 ) ;
F_13 ( V_73 << 8 | 0x05 , V_1 ) ;
F_13 ( ( F_57 ( V_31 ) ) << 8 | ( F_58 ( V_31 ) ) , V_1 ) ;
F_14 ( V_1 ) ;
}
if ( F_59 ( V_31 ) ) {
V_5 -> V_97 |= ( 1 << V_11 ) ;
F_13 ( V_5 -> V_97 , V_1 + 0x02 ) ;
}
}
static inline void F_60 ( struct V_4 * V_98 )
{
int V_11 ;
struct V_9 * V_10 ;
V_98 -> V_2 ++ ;
if ( ! ( V_98 -> V_13 & V_99 ) ) {
V_10 = V_98 -> V_37 ;
for ( V_11 = 0 ; V_11 < V_98 -> V_36 ; V_11 ++ , V_10 ++ )
F_20 ( V_10 ) ;
}
V_98 -> V_13 |= V_34 | V_99 ;
}
static int F_61 ( struct V_16 * V_100 , struct V_30 * V_31 )
{
struct V_9 * V_10 = F_19 ( V_100 , struct V_9 , V_10 ) ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
if ( F_62 ( V_100 ) < 0 )
return - V_101 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
F_60 ( V_5 ) ;
V_10 -> V_42 = V_10 -> V_102 = V_10 -> V_47 = 0 ;
if ( F_1 ( V_5 -> V_1 ) == 0 ) {
F_13 ( 0x8000 | ( V_10 -> V_11 << V_5 -> V_12 ) | 0x02 ,
V_5 -> V_1 ) ;
F_13 ( ( ( V_103 | V_104 ) << 8 ) | 0x06 , V_5 -> V_1 ) ;
F_14 ( V_5 -> V_1 ) ;
}
F_45 ( V_31 ) ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
return 0 ;
}
static int F_63 ( struct V_16 * V_10 )
{
struct V_9 * V_18 = F_19 ( V_10 , struct V_9 , V_10 ) ;
return ( V_18 -> V_13 & V_62 ) ? 1 : 0 ;
}
static struct V_16 * F_64 ( struct V_30 * V_31 )
{
struct V_9 * V_10 ;
struct V_4 * V_5 ;
unsigned int V_105 ;
int line = V_31 -> V_106 ;
V_105 = F_65 ( line ) ;
V_5 = & V_33 [ V_105 ] ;
if ( ! ( V_5 -> V_13 & V_58 ) )
return NULL ;
if ( line > ( ( V_105 * 16 ) + V_5 -> V_36 - 1 ) )
return NULL ;
V_10 = & V_107 [ line ] ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_12 ) )
return NULL ;
return & V_10 -> V_10 ;
}
static int F_67 ( struct V_30 * V_31 , struct V_108 * V_109 )
{
struct V_9 * V_10 ;
struct V_16 * V_100 ;
V_100 = F_64 ( V_31 ) ;
if ( V_100 == NULL )
return - V_110 ;
V_10 = F_19 ( V_100 , struct V_9 , V_10 ) ;
V_31 -> V_70 = V_10 ;
return F_68 ( V_100 , V_31 , V_109 ) ;
}
static void F_69 ( struct V_9 * V_10 )
{
struct V_4 * V_5 = V_10 -> V_5 ;
if ( -- V_5 -> V_2 < 0 ) {
F_26 ( L_13 ,
V_60 , V_5 -> V_1 , V_5 -> V_2 ) ;
V_5 -> V_2 = 0 ;
}
if ( ! V_5 -> V_2 )
V_5 -> V_13 &= V_34 ;
}
static void F_70 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_14 ) )
return;
F_7 ( & V_5 -> V_7 , V_8 ) ;
V_10 -> V_42 = V_10 -> V_102 = V_10 -> V_47 = 0 ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
F_28 ( V_31 ) ;
}
static void F_71 ( struct V_16 * V_10 )
{
struct V_9 * V_18 = F_19 ( V_10 , struct V_9 , V_10 ) ;
struct V_4 * V_5 = V_18 -> V_5 ;
unsigned long V_8 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
V_5 -> V_97 &= ~ ( 1 << V_18 -> V_11 ) ;
F_13 ( V_5 -> V_97 , V_5 -> V_1 + 0x02 ) ;
F_69 ( V_18 ) ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
F_72 ( V_10 ) ;
}
static void F_73 ( struct V_30 * V_31 , struct V_108 * V_109 )
{
struct V_9 * V_18 = V_31 -> V_70 ;
struct V_16 * V_10 ;
if ( V_18 == NULL )
return;
V_10 = & V_18 -> V_10 ;
if ( F_66 ( V_18 , V_31 -> V_19 , L_15 ) )
return;
F_74 ( V_10 , V_31 , V_109 ) ;
}
static int F_75 ( struct V_30 * V_31 , const unsigned char * V_111 ,
int V_2 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
int V_29 , V_112 = 0 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_16 ) )
return 0 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
while ( 1 ) {
V_29 = F_25 ( int , V_2 , F_76 ( V_46 - V_10 -> V_42
- 1 , V_46 - V_10 -> V_102 ) ) ;
if ( V_29 <= 0 )
break;
memcpy ( V_10 -> V_10 . V_49 + V_10 -> V_102 , V_111 , V_29 ) ;
V_10 -> V_102 = ( V_10 -> V_102 + V_29 ) & ( V_46
- 1 ) ;
V_10 -> V_42 += V_29 ;
V_111 += V_29 ;
V_2 -= V_29 ;
V_112 += V_29 ;
}
if ( V_10 -> V_42 && ! V_31 -> V_43 && ! V_31 -> V_44 )
V_10 -> V_13 |= V_40 ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
return V_112 ;
}
static int F_77 ( struct V_30 * V_31 , unsigned char V_113 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_8 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_17 ) )
return 0 ;
F_7 ( & V_5 -> V_7 , V_8 ) ;
if ( V_10 -> V_42 >= V_46 - 1 ) {
F_9 ( & V_5 -> V_7 , V_8 ) ;
return 0 ;
}
V_10 -> V_10 . V_49 [ V_10 -> V_102 ++ ] = V_113 ;
V_10 -> V_102 &= ( V_46 - 1 ) ;
V_10 -> V_42 ++ ;
F_9 ( & V_5 -> V_7 , V_8 ) ;
return 1 ;
}
static void F_78 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_18 ) )
return;
if ( V_10 -> V_42 <= 0 || V_31 -> V_43 || V_31 -> V_44 ||
! V_10 -> V_10 . V_49 )
return;
V_10 -> V_13 |= V_40 ;
}
static int F_79 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
int free ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_19 ) )
return 0 ;
free = V_46 - V_10 -> V_42 - 1 ;
if ( free < 0 )
free = 0 ;
return free ;
}
static int F_80 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_20 ) )
return 0 ;
return V_10 -> V_42 ;
}
static int F_81 ( struct V_30 * V_31 , int V_114 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
unsigned long V_1 = V_5 -> V_1 ;
if ( V_114 == - 1 )
return - V_115 ;
if ( ! F_6 ( V_5 ) )
return - V_116 ;
F_13 ( 0x8000 | ( ( V_10 -> V_11 ) << ( V_5 -> V_12 ) ) | 0x3 , V_1 ) ;
F_13 ( ( V_114 & 0xff ) << 8 | 0x00 , V_1 ) ;
F_13 ( ( V_114 & 0xff00u ) , V_1 ) ;
F_14 ( V_1 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static int F_82 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
T_1 V_13 = V_10 -> V_13 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_21 ) )
return - V_110 ;
return ( ( V_13 & V_15 ) ? V_117 : 0 ) |
( ( V_13 & V_14 ) ? V_118 : 0 ) |
( ( V_13 & V_62 ) ? V_119 : 0 ) |
( ( V_13 & V_65 ) ? V_120 : 0 ) |
( ( V_13 & V_64 ) ? V_121 : 0 ) |
( ( V_13 & V_66 ) ? V_122 : 0 ) ;
}
static int F_83 ( struct V_30 * V_31 ,
unsigned int V_123 , unsigned int V_124 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
unsigned long V_8 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_21 ) )
return - V_110 ;
F_7 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
if ( V_123 & V_117 )
F_16 ( V_10 ) ;
if ( V_123 & V_118 )
F_12 ( V_10 ) ;
if ( V_124 & V_117 )
F_17 ( V_10 ) ;
if ( V_124 & V_118 )
F_15 ( V_10 ) ;
F_9 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
return 0 ;
}
static int F_84 ( struct V_30 * V_31 ,
struct V_125 T_3 * V_126 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_125 V_127 ;
int V_128 ;
if ( F_85 ( & V_127 , V_126 , sizeof( V_127 ) ) )
return - V_129 ;
F_86 ( & V_10 -> V_10 . V_130 ) ;
V_128 = ( ( V_10 -> V_10 . V_8 & V_77 ) !=
( V_127 . V_8 & V_77 ) ) ;
if ( ! F_87 ( V_131 ) ) {
if ( ( V_127 . V_132 != V_10 -> V_10 . V_132 ) ||
( V_127 . V_133 != V_10 -> V_10 . V_133 ) ||
( ( V_127 . V_8 & ~ V_134 ) !=
( V_10 -> V_10 . V_8 & ~ V_134 ) ) ) {
F_88 ( & V_10 -> V_10 . V_130 ) ;
return - V_135 ;
}
V_10 -> V_10 . V_8 = ( ( V_10 -> V_10 . V_8 & ~ V_134 ) |
( V_127 . V_8 & V_134 ) ) ;
} else {
V_10 -> V_10 . V_132 = V_127 . V_132 ;
V_10 -> V_10 . V_133 = V_127 . V_133 ;
V_10 -> V_10 . V_8 = ( ( V_10 -> V_10 . V_8 & ~ V_136 ) |
( V_127 . V_8 & V_136 ) ) ;
}
if ( V_128 ) {
unsigned long V_8 ;
F_7 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
F_45 ( V_31 ) ;
F_9 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
}
F_88 ( & V_10 -> V_10 . V_130 ) ;
return 0 ;
}
static int F_89 ( struct V_9 * V_10 ,
struct V_125 T_3 * V_126 )
{
struct V_125 V_137 ;
F_86 ( & V_10 -> V_10 . V_130 ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . line = V_10 - V_107 ;
V_137 . V_10 = V_10 -> V_5 -> V_1 ;
V_137 . V_53 = V_10 -> V_5 -> V_53 ;
V_137 . V_8 = V_10 -> V_10 . V_8 ;
V_137 . V_132 = V_10 -> V_10 . V_132 ;
V_137 . V_133 = V_10 -> V_10 . V_133 ;
F_88 ( & V_10 -> V_10 . V_130 ) ;
if ( F_90 ( V_126 , & V_137 , sizeof( V_137 ) ) )
return - V_129 ;
return 0 ;
}
static int F_91 ( struct V_30 * V_31 ,
unsigned int V_138 , unsigned long V_139 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
void T_3 * V_140 = ( void T_3 * ) V_139 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_21 ) )
return - V_110 ;
switch ( V_138 ) {
case V_141 :
return F_89 ( V_10 , V_140 ) ;
case V_142 :
return F_84 ( V_31 , V_140 ) ;
default:
return - V_143 ;
}
return 0 ;
}
static void F_92 ( struct V_30 * V_31 ,
struct V_144 * V_145 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
unsigned long V_8 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_22 ) )
return;
if ( V_31 -> V_75 . V_76 == V_145 -> V_76 &&
V_31 -> V_75 . V_146 == V_145 -> V_146 )
return;
F_7 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
F_45 ( V_31 ) ;
F_9 ( & V_10 -> V_5 -> V_7 , V_8 ) ;
if ( ( V_145 -> V_76 & V_147 ) && ! F_54 ( V_31 ) ) {
V_31 -> V_44 = 0 ;
F_93 ( V_31 ) ;
}
}
static void F_94 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_23 ) )
return;
V_5 -> V_97 &= ~ ( 1 << V_10 -> V_11 ) ;
F_13 ( V_5 -> V_97 , V_5 -> V_1 + 0x02 ) ;
}
static void F_95 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
struct V_4 * V_5 = V_10 -> V_5 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_24 ) )
return;
V_5 -> V_97 |= ( 1 << V_10 -> V_11 ) ;
F_13 ( V_5 -> V_97 , V_5 -> V_1 + 0x02 ) ;
}
static void F_96 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_25 ) )
return;
V_10 -> V_13 &= ~ V_40 ;
}
static void F_93 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_26 ) )
return;
V_10 -> V_13 |= V_40 ;
}
static void F_97 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_70 ;
if ( F_66 ( V_10 , V_31 -> V_19 , L_27 ) )
return;
F_98 ( & V_10 -> V_10 ) ;
}
static int F_99 ( struct V_148 * V_149 ,
const unsigned int V_5 , unsigned int * V_150 )
{
struct V_4 * V_105 = F_100 ( V_149 ) ;
unsigned long V_1 = V_105 -> V_1 ;
unsigned int V_151 , V_152 = 0 ;
int V_153 = 0 ;
F_101 ( & V_149 -> V_154 , L_28 , V_5 + 1 ,
V_1 ) ;
F_3 ( V_1 + 0x8 ) ;
F_5 ( 10 ) ;
F_13 ( 0 , V_1 + 0x8 ) ;
F_5 ( 1000 ) ;
V_151 = F_3 ( V_1 + 0x4 ) & 0xff ;
if ( V_151 != 0xa5 && V_151 != 0xbb && V_151 != 0xcc && V_151 != 0xdd &&
V_151 != 0xee ) {
F_102 ( & V_149 -> V_154 , L_29
L_30 , V_5 + 1 , V_1 ) ;
F_101 ( & V_149 -> V_154 , L_31 , V_151 ) ;
V_153 = - V_155 ;
goto V_156;
}
F_5 ( 10 ) ;
V_152 = F_3 ( V_1 + 0x2 ) ;
if ( ! ( F_3 ( V_1 + 0xe ) & 0x1 ) || ( V_152 != 0 && V_152 != 4 &&
V_152 != 8 && V_152 != 16 ) ) {
F_103 ( & V_149 -> V_154 , L_32 ,
V_5 + 1 ) ;
V_153 = - V_155 ;
goto V_156;
}
switch ( V_151 ) {
case 0xa5 :
case 0xbb :
case 0xdd :
V_105 -> V_36 = ( V_152 == 4 ) ? 4 : 8 ;
V_105 -> V_12 = 12 ;
break;
case 0xcc :
case 0xee :
V_105 -> V_36 = 16 ;
V_105 -> V_12 = 11 ;
break;
}
F_104 ( & V_149 -> V_154 , L_33 ) ;
* V_150 = V_151 ;
V_156:
return V_153 ;
}
static int F_105 ( struct V_148 * V_149 ,
const unsigned int V_106 , const unsigned int V_150 )
{
struct V_4 * V_105 = F_100 ( V_149 ) ;
const struct V_157 * V_158 ;
unsigned long V_1 = V_105 -> V_1 ;
unsigned int V_3 ;
T_1 V_28 , V_13 ;
int V_153 = - V_155 ;
char * V_19 ;
T_4 * V_159 ;
struct V_160 {
T_1 V_161 ;
T_1 V_2 ;
T_4 V_159 [ 0 ] ;
} * V_162 ;
switch ( V_150 ) {
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
F_103 ( & V_149 -> V_154 , L_39 ) ;
goto V_156;
}
V_153 = F_106 ( & V_158 , V_19 , & V_149 -> V_154 ) ;
if ( V_153 )
goto V_156;
V_153 = - V_155 ;
for ( V_162 = (struct V_160 * ) V_158 -> V_159 ;
V_162 < (struct V_160 * ) ( V_158 -> V_159 + V_158 -> V_163 ) ;
V_162 = (struct V_160 * ) ( ( T_4 * ) ( V_162 + 1 ) +
V_162 -> V_2 ) ) {
if ( F_1 ( V_1 ) )
goto V_164;
F_13 ( 0xf0 , V_1 ) ;
F_13 ( 0x00 , V_1 ) ;
F_13 ( V_162 -> V_161 , V_1 ) ;
V_28 = V_162 -> V_2 / 2 + V_162 -> V_2 % 2 ;
F_13 ( V_28 , V_1 ) ;
F_14 ( V_1 ) ;
F_8 ( 100 ) ;
if ( F_1 ( V_1 ) )
goto V_164;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_102 ( & V_149 -> V_154 , L_40
L_41
L_42
L_43 ,
V_106 + 1 , V_162 -> V_161 , V_162 -> V_2 , V_13 ) ;
goto V_164;
}
F_27 ( V_1 , V_162 -> V_159 , V_28 ) ;
F_14 ( V_1 ) ;
F_8 ( 50 ) ;
if ( F_1 ( V_1 ) )
goto V_164;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_103 ( & V_149 -> V_154 , L_44
L_43 , V_106 + 1 , V_13 ) ;
goto V_164;
}
}
for ( V_162 = (struct V_160 * ) V_158 -> V_159 ;
V_162 < (struct V_160 * ) ( V_158 -> V_159 + V_158 -> V_163 ) ;
V_162 = (struct V_160 * ) ( ( T_4 * ) ( V_162 + 1 ) +
V_162 -> V_2 ) ) {
if ( F_1 ( V_1 ) )
goto V_164;
F_13 ( 0xf1 , V_1 ) ;
F_13 ( 0x00 , V_1 ) ;
F_13 ( V_162 -> V_161 , V_1 ) ;
V_28 = ( V_162 -> V_2 >> 1 ) + V_162 -> V_2 % 2 ;
F_13 ( V_28 + 1 , V_1 ) ;
F_14 ( V_1 ) ;
F_8 ( 50 ) ;
if ( F_1 ( V_1 ) )
goto V_164;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_102 ( & V_149 -> V_154 , L_45
L_41
L_42
L_46 ,
V_106 + 1 , V_162 -> V_161 , V_162 -> V_2 , V_13 ) ;
goto V_164;
}
V_159 = F_107 ( V_28 * 2 , V_165 ) ;
if ( V_159 == NULL ) {
F_103 ( & V_149 -> V_154 , L_47
L_48 , V_106 + 1 ) ;
goto V_164;
}
F_3 ( V_1 ) ;
F_44 ( V_1 , V_159 , V_28 ) ;
F_14 ( V_1 ) ;
for ( V_3 = 0 ; V_3 < V_162 -> V_2 ; V_3 ++ )
if ( V_159 [ V_3 ] != V_162 -> V_159 [ V_3 ] ) {
F_108 ( V_159 ) ;
F_103 ( & V_149 -> V_154 , L_47
L_49 , V_106 + 1 ) ;
goto V_164;
}
F_108 ( V_159 ) ;
F_8 ( 50 ) ;
if ( F_1 ( V_1 ) )
goto V_164;
V_13 = F_3 ( V_1 + 0x4 ) ;
if ( V_13 != 0 ) {
F_103 ( & V_149 -> V_154 , L_50
L_51 , V_106 + 1 , V_13 ) ;
goto V_164;
}
}
if ( F_1 ( V_1 ) )
goto V_164;
F_13 ( 0xf2 , V_1 ) ;
F_13 ( 0x800 , V_1 ) ;
F_13 ( 0x0 , V_1 ) ;
F_13 ( 0x0 , V_1 ) ;
F_14 ( V_1 ) ;
F_13 ( 0x0 , V_1 + 0x4 ) ;
V_105 -> V_13 |= V_58 ;
V_153 = 0 ;
V_164:
F_109 ( V_158 ) ;
V_156:
return V_153 ;
}
static int F_110 ( struct V_148 * V_149 ,
const struct V_166 * V_167 )
{
unsigned int V_168 ( V_150 ) , V_106 ;
int V_153 = - V_135 ;
struct V_4 * V_105 = NULL ;
if ( V_169 >= V_24 )
goto V_170;
V_153 = F_111 ( V_149 ) ;
if ( V_153 ) {
F_103 ( & V_149 -> V_154 , L_52 ) ;
goto V_170;
}
F_104 ( & V_149 -> V_154 , L_53 , V_167 -> V_171 ) ;
for ( V_106 = 0 ; V_106 < V_24 ; V_106 ++ ) {
if ( V_33 [ V_106 ] . V_1 == 0 ) {
V_105 = & V_33 [ V_106 ] ;
break;
}
}
if ( V_106 == V_24 ) {
V_153 = - V_110 ;
goto V_172;
}
V_105 -> V_106 = V_106 ;
V_105 -> V_1 = F_112 ( V_149 , 3 ) ;
V_105 -> V_53 = V_149 -> V_53 ;
V_169 ++ ;
F_113 ( V_149 , V_105 ) ;
V_153 = F_114 ( V_149 , 3 , V_173 ) ;
if ( V_153 ) {
F_103 ( & V_149 -> V_154 , L_54
L_55 , V_105 -> V_1 , V_105 -> V_1 + 15 ,
V_106 + 1 ) ;
V_153 = - V_174 ;
goto V_175;
}
V_153 = F_115 ( V_105 -> V_53 , F_32 ,
V_176 , V_173 , V_105 ) ;
if ( V_153 < 0 ) {
F_103 ( & V_149 -> V_154 , L_56
L_57 , V_105 -> V_53 , V_106 + 1 ) ;
goto V_177;
}
V_153 = F_99 ( V_149 , V_106 , & V_150 ) ;
if ( V_153 < 0 )
goto V_178;
V_153 = F_105 ( V_149 , V_106 , V_150 ) ;
if ( V_153 < 0 )
goto V_178;
for ( V_106 = 0 ; V_106 < V_105 -> V_36 ; V_106 ++ ) {
struct V_16 * V_100 = & V_105 -> V_37 [ V_106 ] . V_10 ;
F_116 ( V_100 ) ;
V_100 -> V_179 = & V_180 ;
V_100 -> V_132 = 50 * V_181 / 100 ;
V_100 -> V_133 = 3000 * V_181 / 100 ;
F_117 ( V_100 , V_182 ,
V_105 -> V_106 * 16 + V_106 , & V_149 -> V_154 ) ;
}
return 0 ;
V_178:
F_118 ( V_105 -> V_53 , V_105 ) ;
V_177:
F_119 ( V_149 , 3 ) ;
V_175:
V_105 -> V_1 = 0 ;
V_169 -- ;
V_172:
F_120 ( V_149 ) ;
V_170:
return V_153 ;
}
static void F_121 ( struct V_148 * V_149 )
{
struct V_4 * V_105 = F_100 ( V_149 ) ;
unsigned int V_183 ;
for ( V_183 = 0 ; V_183 < V_105 -> V_36 ; V_183 ++ ) {
F_122 ( V_182 , V_105 -> V_106 * 16 + V_183 ) ;
F_123 ( & V_105 -> V_37 [ V_183 ] . V_10 ) ;
}
F_118 ( V_105 -> V_53 , V_105 ) ;
F_119 ( V_149 , 3 ) ;
V_105 -> V_1 = 0 ;
V_169 -- ;
F_120 ( V_149 ) ;
}
static int T_5 F_124 ( void )
{
int V_153 , V_184 , V_11 ;
struct V_9 * V_10 ;
for ( V_184 = 0 ; V_184 < V_24 ; V_184 ++ ) {
V_10 = & V_107 [ V_184 * 16 ] ;
V_33 [ V_184 ] . V_37 = V_10 ;
F_125 ( & V_33 [ V_184 ] . V_7 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ , V_10 ++ ) {
V_10 -> V_21 = V_22 ;
V_10 -> V_5 = & V_33 [ V_184 ] ;
V_10 -> V_11 = V_11 ;
V_10 -> V_13 = 0 ;
}
V_33 [ V_184 ] . V_1 = 0 ;
V_33 [ V_184 ] . V_53 = 0 ;
}
V_182 = F_126 ( V_185 ) ;
if ( ! V_182 ) {
V_153 = - V_101 ;
goto error;
}
V_182 -> V_19 = L_58 ;
V_182 -> V_186 = V_187 ;
V_182 -> V_188 = 0 ;
V_182 -> type = V_189 ;
V_182 -> V_190 = V_191 ;
V_182 -> V_192 = V_193 ;
V_182 -> V_192 . V_76 = V_194 | V_89 | V_195 | V_196 |
V_197 ;
V_182 -> V_8 = V_198 |
V_199 | V_200 ;
F_127 ( V_182 , & V_201 ) ;
V_153 = F_128 ( V_182 ) ;
if ( V_153 ) {
F_26 ( L_59 ) ;
goto V_202;
}
V_153 = F_129 ( & V_203 ) ;
if ( V_153 < 0 ) {
F_130 ( L_60 ) ;
goto V_204;
}
F_30 ( & V_51 , V_52 + 1 ) ;
return 0 ;
V_204:
F_131 ( V_182 ) ;
V_202:
F_132 ( V_182 ) ;
error:
return V_153 ;
}
static void T_6 F_133 ( void )
{
F_134 ( & V_51 ) ;
F_135 ( & V_203 ) ;
F_131 ( V_182 ) ;
F_132 ( V_182 ) ;
}
