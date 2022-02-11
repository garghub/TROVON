static inline void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 ;
unsigned int V_5 ;
V_3 = F_2 ( V_6 ) ;
V_4 = F_2 ( V_7 ) ;
V_3 &= ~ V_4 ;
V_3 >>= ( V_1 - F_3 ( 0 ) ) ;
V_3 &= ( 1 << V_2 ) - 1 ;
V_5 = V_2 + V_1 ;
for (; V_1 < V_5 && V_3 ; V_1 ++ ) {
if ( V_3 & 1 )
F_4 ( V_1 ) ;
V_3 >>= 1 ;
}
}
static void F_5 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_10 , 4 ) ;
}
static void F_6 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_13 , V_14 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_13 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_13 , V_14 ) ;
}
static void F_12 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_15 , 4 ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_16 , V_17 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_16 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_16 , V_17 ) ;
}
static void F_16 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_18 , 6 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_19 , V_20 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_19 ) ;
}
static void F_19 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_19 , V_20 ) ;
}
static void F_20 ( unsigned int V_1 , struct V_8 * V_9 )
{
F_1 ( V_21 , 3 ) ;
}
static void F_21 ( struct V_11 * V_12 )
{
F_7 ( V_12 -> V_1 , V_22 , V_23 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_1 , V_22 ) ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_11 ( V_12 -> V_1 , V_22 , V_23 ) ;
}
static inline void F_24 ( struct V_11 * V_12 )
{
unsigned long V_24 = 1UL << ( V_12 -> V_1 - V_25 ) ;
F_25 ( V_24 , V_26 ) ;
F_25 ( V_24 , V_27 ) ;
}
static void F_26 ( struct V_11 * V_12 )
{
unsigned long V_24 = 1UL << ( V_12 -> V_1 - V_25 ) ;
unsigned long V_28 ;
V_28 = F_2 ( V_29 ) ;
V_28 |= V_24 ;
F_25 ( V_28 , V_29 ) ;
}
static void F_27 ( struct V_11 * V_12 )
{
unsigned long V_24 = 1UL << ( V_12 -> V_1 - V_25 ) ;
unsigned long V_28 ;
V_28 = F_2 ( V_29 ) ;
V_28 &= ~ V_24 ;
F_25 ( V_28 , V_29 ) ;
}
static int F_28 ( unsigned int V_30 ,
void (* F_29)( unsigned int ,
struct V_8 * ) ,
struct V_31 * V_32 ,
unsigned int V_33 , unsigned int V_5 )
{
unsigned int V_34 ;
F_30 ( V_30 , & V_35 , V_36 ) ;
F_31 ( V_30 , F_29 ) ;
for ( V_34 = V_33 ; V_34 <= V_5 ; V_34 ++ ) {
F_30 ( V_34 , V_32 , V_36 ) ;
F_32 ( V_34 , V_37 ) ;
}
return 0 ;
}
static void F_33 ( void )
{
unsigned long V_38 ;
unsigned long V_39 ;
int V_34 ;
int V_40 ;
V_39 = 0 ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
V_38 = F_2 ( V_27 ) ;
if ( V_38 == 0 || V_38 == V_39 )
break;
F_25 ( V_38 , V_26 ) ;
F_25 ( V_38 , V_27 ) ;
F_34 ( V_41 L_1 ,
( int ) V_38 ) ;
V_39 = V_38 ;
}
for ( V_34 = V_25 ; V_34 <= V_42 ; V_34 ++ ) {
switch ( V_34 ) {
case V_43 :
case V_44 :
break;
default:
F_30 ( V_34 , & V_45 ,
V_46 ) ;
F_32 ( V_34 , V_37 ) ;
}
}
}
static int F_35 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
F_34 ( V_41 L_2 ) ;
F_28 ( V_51 , F_12 , & V_52 ,
V_53 , V_54 ) ;
F_28 ( V_55 , F_16 ,
& V_56 , V_18 , V_57 ) ;
F_28 ( V_58 , F_20 ,
& V_59 ,
V_21 , V_60 ) ;
F_28 ( V_61 , F_5 ,
& V_62 ,
V_10 , V_63 ) ;
F_33 () ;
return 0 ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_64 ) ;
}
int F_38 ( void )
{
F_39 ( V_65 , F_40 ( V_65 ) ) ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( V_65 , F_40 ( V_65 ) ) ;
}
