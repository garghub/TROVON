static unsigned char F_1 ( void * V_1 , unsigned char V_2 )
{
struct V_3 * V_4 = V_1 ;
unsigned long V_5 ;
unsigned long V_6 ;
unsigned char V_7 ;
F_2 ( & V_4 -> V_8 , V_6 ) ;
V_5 = 1000 ;
while ( F_3 ( V_4 , V_9 ) & V_10 ) {
F_4 ( 5 ) ;
if ( -- V_5 == 0 ) {
F_5 ( & V_4 -> V_8 , V_6 ) ;
F_6 ( V_11 L_1 ) ;
return 0 ;
}
}
F_7 ( V_4 , V_12 , ( V_13 ) V_2 << 8 ) ;
V_5 = 1000 ;
while ( F_3 ( V_4 , V_9 ) & V_10 ) {
F_4 ( 5 ) ;
if ( -- V_5 == 0 ) {
F_5 ( & V_4 -> V_8 , V_6 ) ;
F_6 ( V_11 L_2 ) ;
return 0 ;
}
}
V_7 = ( unsigned char ) F_3 ( V_4 , V_12 ) ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
return V_7 ;
}
static void F_8 ( void * V_1 , unsigned char V_2 , unsigned char V_14 )
{
struct V_3 * V_4 = V_1 ;
unsigned long V_5 ;
unsigned long V_6 ;
F_2 ( & V_4 -> V_8 , V_6 ) ;
V_5 = 1000 ;
while ( F_9 ( V_4 -> V_15 + V_9 ) & V_10 ) {
F_4 ( 5 ) ;
if ( -- V_5 == 0 ) {
F_5 ( & V_4 -> V_8 , V_6 ) ;
F_6 ( V_11 L_3 ) ;
return;
}
}
F_10 ( ( V_13 ) V_2 << 8 | V_14 | ( 1 << 13 ) , V_4 -> V_15 + V_12 ) ;
F_5 ( & V_4 -> V_8 , V_6 ) ;
}
static int F_11 ( struct V_3 * V_4 , int V_16 )
{
V_13 V_14 ;
V_14 = F_3 ( V_4 , V_9 ) ;
V_14 |= V_17 ;
V_14 &= ~ V_18 ;
F_7 ( V_4 , V_9 , V_14 ) ;
F_4 ( 5 ) ;
V_14 |= V_19 ;
F_7 ( V_4 , V_9 , V_14 ) ;
F_4 ( 200 ) ;
V_14 &= ~ V_19 ;
F_7 ( V_4 , V_9 , V_14 ) ;
F_4 ( 5 ) ;
if ( ! V_16 ) {
V_14 &= ~ V_17 ;
F_7 ( V_4 , V_9 , V_14 ) ;
F_4 ( 200 ) ;
}
return 0 ;
}
void F_12 ( struct V_3 * V_4 , int V_20 )
{
F_11 ( V_4 , 0 ) ;
if ( V_20 )
F_7 ( V_4 , V_9 , V_4 -> V_21 ) ;
F_13 ( V_4 -> V_22 ) ;
F_7 ( V_4 , V_23 , V_4 -> V_24 [ V_23 >> 1 ] ) ;
F_7 ( V_4 , V_25 , V_4 -> V_24 [ V_25 >> 1 ] ) ;
}
static void F_14 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = V_27 -> V_1 ;
V_13 V_30 ;
F_15 ( V_29 , L_4 ) ;
V_30 = F_3 ( V_4 , V_9 ) ;
F_15 ( V_29 , L_5 , F_16 ( V_30 ) ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_26 * V_27 ;
if ( ! F_18 ( V_4 -> V_31 , L_6 , & V_27 ) )
F_19 ( V_27 , V_4 , F_14 ) ;
}
struct V_3 * F_20 ( struct V_32 * V_31 )
{
struct V_3 * V_4 ;
V_4 = F_21 ( sizeof( * V_4 ) , V_33 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_31 = V_31 ;
F_22 ( & V_4 -> V_34 ) ;
F_22 ( & V_4 -> V_8 ) ;
F_23 ( & V_4 -> V_35 , V_36 , ( unsigned long ) V_4 ) ;
V_31 -> V_1 = V_4 ;
F_17 ( V_4 ) ;
return V_4 ;
}
static void F_24 ( struct V_22 * V_22 , unsigned char V_37 , unsigned char V_38 )
{
struct V_3 * V_4 = V_22 -> V_39 ;
unsigned long V_6 ;
V_13 V_14 ;
if ( ! ( V_37 & V_40 ) )
return;
F_2 ( & V_4 -> V_34 , V_6 ) ;
V_14 = V_4 -> V_24 [ V_9 >> 1 ] ;
if ( V_22 -> V_41 & V_40 )
V_14 |= V_42 ;
else
V_14 &= ~ V_42 ;
F_7 ( V_4 , V_9 , V_14 ) ;
F_5 ( & V_4 -> V_34 , V_6 ) ;
}
int F_25 ( struct V_3 * V_4 )
{
int V_43 ;
V_13 V_14 ;
static unsigned char V_44 [ 5 ] = {
V_45 | V_46 ,
V_47 | V_48 | V_49 ,
V_50 | V_51 | V_52 ,
0xff ,
V_53 | V_54 | V_55 | V_56 | V_57 ,
} ;
V_43 = F_11 ( V_4 , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_26 ( V_4 -> V_31 , F_1 , F_8 , V_44 , V_4 , & V_4 -> V_22 ) ;
if ( V_43 < 0 )
return V_43 ;
V_14 = F_3 ( V_4 , V_23 ) ;
#if 1
V_14 &= ~ ( V_58 | V_59 ) ;
#else
V_14 |= V_58 ;
V_14 &= ~ V_59 ;
#endif
F_7 ( V_4 , V_23 , V_14 ) ;
V_14 = F_3 ( V_4 , V_9 ) ;
V_14 &= ~ ( V_60 | V_61 ) ;
V_14 &= ~ ( V_62 | V_42 ) ;
V_14 |= V_63 | V_64 ;
F_7 ( V_4 , V_9 , V_14 ) ;
V_14 = F_3 ( V_4 , V_25 ) ;
V_14 &= ~ ( V_65 | V_66 ) ;
V_14 &= ~ ( V_67 | V_68 | V_69 ) ;
V_14 |= V_70 | V_71 ;
V_14 |= V_72 | V_73 ;
F_7 ( V_4 , V_25 , V_14 ) ;
V_4 -> V_22 -> V_39 = V_4 ;
V_4 -> V_22 -> V_74 = F_24 ;
F_24 ( V_4 -> V_22 , V_40 , 0 ) ;
return 0 ;
}
void F_27 ( struct V_3 * V_4 )
{
V_13 V_14 ;
V_14 = F_3 ( V_4 , V_9 ) ;
V_4 -> V_21 = V_14 ;
V_14 |= V_62 | V_42 ;
F_7 ( V_4 , V_9 , V_14 ) ;
V_14 = F_9 ( V_4 -> V_15 + V_25 ) ;
V_14 &= ~ ( V_72 | V_73 | V_65 | V_66 ) ;
F_10 ( V_14 , V_4 -> V_15 + V_25 ) ;
F_11 ( V_4 , 1 ) ;
}
int F_28 ( struct V_3 * V_4 )
{
V_13 V_14 ;
F_29 ( V_4 -> V_31 , V_75 ) ;
F_30 ( V_4 -> V_76 ) ;
V_14 = F_9 ( V_4 -> V_15 + V_25 ) ;
V_14 &= ~ ( V_72 | V_73 | V_65 | V_66 ) ;
F_10 ( V_14 , V_4 -> V_15 + V_25 ) ;
V_4 -> V_77 |= V_78 ;
F_27 ( V_4 ) ;
return 0 ;
}
static inline int F_31 ( struct V_3 * V_4 )
{
return ( V_4 -> V_22 -> V_41 & V_40 ) == 0 ;
}
int F_32 ( struct V_3 * V_4 )
{
int V_5 = 40 ;
F_12 ( V_4 , 1 ) ;
while ( V_5 -- > 0 &&
( F_33 ( V_4 -> V_22 ) <= 0 || ! F_31 ( V_4 ) ) )
F_34 ( 1 ) ;
V_4 -> V_77 &= ~ V_78 ;
F_29 ( V_4 -> V_31 , V_79 ) ;
return 0 ;
}
