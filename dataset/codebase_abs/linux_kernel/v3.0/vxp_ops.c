static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
return V_5 -> V_6 + V_7 [ V_3 ] ;
}
static unsigned char F_2 ( struct V_1 * V_5 , int V_8 )
{
return F_3 ( F_1 ( V_5 , V_8 ) ) ;
}
static void F_4 ( struct V_1 * V_5 , int V_8 , unsigned char V_9 )
{
F_5 ( V_9 , F_1 ( V_5 , V_8 ) ) ;
}
static int F_6 ( struct V_1 * V_5 )
{
unsigned long V_10 = V_11 + V_12 / 5 ;
int V_13 ;
do {
V_13 = F_7 ( V_5 , V_14 ) ;
if ( V_13 == V_15 )
return 0 ;
F_8 ( 10 ) ;
} while ( F_9 ( V_10 , V_11 ) );
F_10 ( V_16 L_1 , V_13 ) ;
return - V_17 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 | V_19 ) ;
F_7 ( V_5 , V_14 ) ;
F_13 ( V_20 ) ;
V_5 -> V_18 &= ~ V_19 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
F_7 ( V_5 , V_14 ) ;
F_13 ( V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 | V_21 ) ;
F_7 ( V_5 , V_14 ) ;
F_8 ( 10 ) ;
V_5 -> V_18 &= ~ V_21 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
F_7 ( V_5 , V_14 ) ;
F_8 ( 1 ) ;
}
static int F_15 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
unsigned int V_24 ;
int V_13 ;
int V_25 , V_26 ;
const unsigned char * V_27 ;
unsigned char V_28 ;
V_5 -> V_29 |= V_30 ;
F_12 ( V_5 , V_31 , V_5 -> V_29 ) ;
V_25 = F_7 ( V_5 , V_32 ) ;
V_26 = F_7 ( V_5 , V_33 ) ;
F_12 ( V_5 , V_34 , 0 ) ;
F_16 ( V_35 L_2 ) ;
if ( F_17 ( V_2 , V_36 , V_36 , 20 ) < 0 )
goto V_37;
F_12 ( V_5 , V_34 , V_38 ) ;
V_27 = V_23 -> V_28 ;
for ( V_24 = 0 ; V_24 < V_23 -> V_39 ; V_24 ++ , V_27 ++ ) {
V_28 = * V_27 ;
if ( F_18 ( V_2 , V_40 ) < 0 )
goto V_37;
F_12 ( V_5 , V_41 , V_28 ) ;
if ( F_19 ( V_2 ) < 0 )
goto V_37;
V_13 = F_7 ( V_5 , V_42 ) ;
if ( V_13 != ( int ) V_28 )
F_10 ( V_16 L_3 , V_24 , V_13 , ( int ) V_28 ) ;
}
F_12 ( V_5 , V_34 , 0 ) ;
if ( F_17 ( V_2 , V_43 , V_43 , 20 ) < 0 )
goto V_37;
if ( F_19 ( V_2 ) < 0 )
goto V_37;
V_13 = ( int ) F_7 ( V_5 , V_44 ) << 16 ;
V_13 |= ( int ) F_7 ( V_5 , V_45 ) << 8 ;
V_13 |= F_7 ( V_5 , V_42 ) ;
F_16 ( V_35 L_4 , V_13 , V_23 -> V_39 ) ;
F_12 ( V_5 , V_34 , V_46 ) ;
F_8 ( 300 ) ;
if ( F_6 ( V_2 ) < 0 )
goto V_37;
F_12 ( V_5 , V_32 , V_25 ) ;
F_12 ( V_5 , V_33 , V_26 ) ;
V_5 -> V_29 |= V_30 ;
F_12 ( V_5 , V_31 , V_5 -> V_29 ) ;
F_7 ( V_5 , V_31 ) ;
F_8 ( 10 ) ;
V_5 -> V_29 &= ~ V_30 ;
F_12 ( V_5 , V_31 , V_5 -> V_29 ) ;
F_7 ( V_5 , V_31 ) ;
F_14 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
V_37:
F_12 ( V_5 , V_32 , V_25 ) ;
F_12 ( V_5 , V_33 , V_26 ) ;
V_5 -> V_29 &= ~ V_30 ;
F_12 ( V_5 , V_31 , V_5 -> V_29 ) ;
return - V_17 ;
}
static int F_21 ( struct V_1 * V_47 , int V_48 , const struct V_22 * V_23 )
{
int V_49 ;
switch ( V_48 ) {
case 0 :
if ( ( V_49 = F_6 ( V_47 ) ) < 0 )
return V_49 ;
if ( ( V_49 = F_22 ( V_47 , V_23 ) ) < 0 )
return V_49 ;
return 0 ;
case 1 :
return F_15 ( V_47 , V_23 ) ;
case 2 :
return F_23 ( V_47 , V_23 ) ;
case 3 :
return F_24 ( V_47 , V_23 ) ;
default:
F_25 () ;
return - V_50 ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( ! ( V_2 -> V_51 & V_52 ) )
return - V_53 ;
if ( ! ( F_7 ( V_5 , V_31 ) & V_54 ) )
return - V_17 ;
F_12 ( V_5 , V_31 , V_5 -> V_29 | V_55 ) ;
F_7 ( V_5 , V_31 ) ;
F_12 ( V_5 , V_31 , V_5 -> V_29 & ~ V_55 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , int V_56 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( V_56 )
V_5 -> V_18 |= V_57 ;
else
V_5 -> V_18 &= ~ V_57 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_58 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
F_12 ( V_5 , V_34 , V_58 ? V_59 : V_60 ) ;
F_7 ( V_5 , V_61 ) ;
F_12 ( V_5 , V_61 , 0 ) ;
V_5 -> V_29 |= V_62 ;
V_5 -> V_29 |= V_58 ? V_63 : V_64 ;
F_12 ( V_5 , V_31 , V_5 -> V_29 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
V_5 -> V_29 &= ~ ( V_63 |
V_64 |
V_62 ) ;
F_12 ( V_5 , V_31 , V_5 -> V_29 ) ;
F_12 ( V_5 , V_34 , 0 ) ;
}
static void F_30 ( struct V_1 * V_5 , struct V_65 * V_66 ,
struct V_67 * V_68 , int V_69 )
{
long V_6 = F_1 ( V_5 , V_70 ) ;
int V_8 = V_68 -> V_71 ;
unsigned short * V_72 = ( unsigned short * ) ( V_66 -> V_73 + V_8 ) ;
F_28 ( V_5 , 1 ) ;
if ( V_8 + V_69 > V_68 -> V_74 ) {
int V_75 = V_68 -> V_74 - V_8 ;
V_69 -= V_75 ;
V_75 >>= 1 ;
while ( V_75 -- > 0 ) {
F_31 ( F_32 ( * V_72 ) , V_6 ) ;
V_72 ++ ;
}
V_72 = ( unsigned short * ) V_66 -> V_73 ;
V_68 -> V_71 = 0 ;
}
V_68 -> V_71 += V_69 ;
V_69 >>= 1 ;
while ( V_69 -- > 0 ) {
F_31 ( F_32 ( * V_72 ) , V_6 ) ;
V_72 ++ ;
}
F_29 ( V_5 ) ;
}
static void F_33 ( struct V_1 * V_5 , struct V_65 * V_66 ,
struct V_67 * V_68 , int V_69 )
{
struct V_4 * V_76 = (struct V_4 * ) V_5 ;
long V_6 = F_1 ( V_5 , V_70 ) ;
int V_8 = V_68 -> V_71 ;
unsigned short * V_72 = ( unsigned short * ) ( V_66 -> V_73 + V_8 ) ;
if ( F_34 ( V_69 % 2 ) )
return;
F_28 ( V_5 , 0 ) ;
if ( V_8 + V_69 > V_68 -> V_74 ) {
int V_75 = V_68 -> V_74 - V_8 ;
V_69 -= V_75 ;
V_75 >>= 1 ;
while ( V_75 -- > 0 )
* V_72 ++ = F_35 ( F_36 ( V_6 ) ) ;
V_72 = ( unsigned short * ) V_66 -> V_73 ;
V_68 -> V_71 = 0 ;
}
V_68 -> V_71 += V_69 ;
V_69 >>= 1 ;
while ( V_69 -- > 1 )
* V_72 ++ = F_35 ( F_36 ( V_6 ) ) ;
V_76 -> V_29 &= ~ V_64 ;
F_12 ( V_5 , V_31 , V_76 -> V_29 ) ;
* V_72 = F_35 ( F_36 ( V_6 ) ) ;
V_76 -> V_29 &= ~ V_62 ;
F_12 ( V_5 , V_31 , V_76 -> V_29 ) ;
F_12 ( V_5 , V_34 , 0 ) ;
}
static void F_37 ( struct V_1 * V_5 , int V_77 , unsigned int V_28 )
{
int V_24 ;
if ( ! V_77 )
F_7 ( V_5 , V_78 ) ;
else
F_7 ( V_5 , V_79 ) ;
for ( V_24 = 0 ; V_24 < 24 ; V_24 ++ , V_28 <<= 1 )
F_12 ( V_5 , V_80 , ( ( V_28 & 0x800000 ) ? V_81 : 0 ) ) ;
F_7 ( V_5 , V_82 ) ;
}
void F_38 ( struct V_1 * V_5 , int V_83 )
{
struct V_4 * V_76 = (struct V_4 * ) V_5 ;
unsigned long V_84 ;
if ( V_5 -> V_51 & V_85 )
return;
F_39 ( & V_5 -> V_86 , V_84 ) ;
if ( V_76 -> V_18 & V_87 ) {
if ( V_83 ) {
V_76 -> V_18 &= ~ V_88 ;
V_76 -> V_18 |= V_89 ;
} else {
V_76 -> V_18 |= V_88 ;
V_76 -> V_18 &= ~ V_89 ;
}
F_12 ( V_5 , V_14 , V_76 -> V_18 ) ;
}
F_40 ( & V_5 -> V_86 , V_84 ) ;
}
static int F_41 ( int V_90 )
{
switch ( V_90 ) {
case 5 : V_90 = 6 ; break;
case 6 : V_90 = 8 ; break;
case 7 : V_90 = 11 ; break;
case 8 : V_90 = 15 ; break;
default: break ;
}
return V_90 ;
}
void F_42 ( struct V_1 * V_5 , int V_90 )
{
struct V_4 * V_76 = (struct V_4 * ) V_5 ;
unsigned long V_84 ;
if ( V_5 -> V_51 & V_85 )
return;
F_39 ( & V_5 -> V_86 , V_84 ) ;
if ( V_76 -> V_18 & V_91 ) {
V_90 = F_41 ( V_90 ) ;
F_12 ( V_5 , V_92 , V_90 ) ;
}
F_40 ( & V_5 -> V_86 , V_84 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_93 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
switch ( V_93 ) {
case V_94 :
V_5 -> V_18 |= V_95 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
break;
case V_96 :
V_5 -> V_18 &= ~ V_95 ;
if ( V_2 -> type == V_97 )
V_5 -> V_18 &= ~ V_87 ;
else
V_5 -> V_18 &= ~ V_91 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
break;
case V_98 :
V_5 -> V_18 &= ~ V_95 ;
if ( V_2 -> type == V_97 ) {
V_5 -> V_18 &= ~ V_87 ;
if ( V_5 -> V_99 )
V_5 -> V_18 |= V_89 ;
else
V_5 -> V_18 |= V_88 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
} else {
V_5 -> V_18 |= V_91 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
F_12 ( V_5 , V_92 , F_41 ( V_5 -> V_99 ) ) ;
}
break;
}
}
static void F_44 ( struct V_1 * V_2 , int V_100 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
if ( V_100 == V_101 )
V_5 -> V_18 &= ~ V_102 ;
else
V_5 -> V_18 |= V_102 ;
F_12 ( V_5 , V_14 , V_5 -> V_18 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_103 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 ;
V_5 -> V_18 = 0 ;
V_5 -> V_29 = 0 ;
}
