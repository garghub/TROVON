static void F_1 ( void T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( V_5 | V_2 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
void T_1 * V_1 = V_8 -> V_1 ;
F_4 ( V_9 L_1 , V_10 , V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( V_8 -> V_11 , V_1 + V_12 ) ;
F_2 ( V_8 -> V_13 , V_1 + V_14 ) ;
F_2 ( V_8 -> V_15 , V_1 + V_16 ) ;
F_2 ( ~ V_8 -> V_15 , V_1 + V_17 ) ;
F_2 ( V_8 -> V_18 , V_1 + V_19 ) ;
F_2 ( ~ V_8 -> V_18 , V_1 + V_20 ) ;
}
static void F_5 ( void )
{
int V_21 ;
for ( V_21 = V_22 - 1 ; V_21 >= 0 ; V_21 -- )
F_3 ( V_23 + V_21 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
void T_1 * V_1 = V_8 -> V_1 ;
F_4 ( V_9 L_2 , V_10 , V_1 ) ;
V_8 -> V_11 = F_7 ( V_1 + V_12 ) ;
V_8 -> V_15 = F_7 ( V_1 + V_16 ) ;
V_8 -> V_18 = F_7 ( V_1 + V_19 ) ;
V_8 -> V_13 = F_7 ( V_1 + V_14 ) ;
F_2 ( V_8 -> V_24 , V_1 + V_16 ) ;
F_2 ( ~ V_8 -> V_24 , V_1 + V_17 ) ;
}
static int F_8 ( void )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ )
F_6 ( V_23 + V_21 ) ;
return 0 ;
}
static int T_2 F_9 ( void )
{
if ( V_22 > 0 )
F_10 ( & V_25 ) ;
return 0 ;
}
static void T_2 F_11 ( void T_1 * V_1 , unsigned int V_26 , T_3 V_27 )
{
struct V_7 * V_28 ;
if ( V_22 >= F_12 ( V_23 ) )
F_4 ( V_29 L_3 , V_10 ) ;
else {
V_28 = & V_23 [ V_22 ] ;
V_28 -> V_1 = V_1 ;
V_28 -> V_27 = V_27 ;
V_28 -> V_26 = V_26 ;
V_22 ++ ;
}
}
static inline void F_11 ( void T_1 * V_1 , unsigned int V_26 , T_3 V_30 ) { }
static void F_13 ( struct V_31 * V_32 )
{
void T_1 * V_1 = F_14 ( V_32 ) ;
unsigned int V_26 = V_32 -> V_26 & 31 ;
F_2 ( 1 << V_26 , V_1 + V_17 ) ;
F_2 ( 1 << V_26 , V_1 + V_20 ) ;
}
static void F_15 ( struct V_31 * V_32 )
{
void T_1 * V_1 = F_14 ( V_32 ) ;
unsigned int V_26 = V_32 -> V_26 & 31 ;
F_2 ( 1 << V_26 , V_1 + V_17 ) ;
}
static void F_16 ( struct V_31 * V_32 )
{
void T_1 * V_1 = F_14 ( V_32 ) ;
unsigned int V_26 = V_32 -> V_26 & 31 ;
F_2 ( 1 << V_26 , V_1 + V_16 ) ;
}
static struct V_7 * F_17 ( unsigned int V_26 )
{
struct V_7 * V_28 = V_23 ;
unsigned int V_33 = V_26 & ~ 31 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_28 ++ ) {
if ( V_28 -> V_26 == V_33 )
return V_28 ;
}
return NULL ;
}
static int F_18 ( struct V_31 * V_32 , unsigned int V_34 )
{
struct V_7 * V_28 = F_17 ( V_32 -> V_26 ) ;
unsigned int V_35 = V_32 -> V_26 & 31 ;
T_3 V_36 = 1 << V_35 ;
if ( ! V_28 )
return - V_37 ;
if ( ! ( V_36 & V_28 -> V_27 ) )
return - V_37 ;
if ( V_34 )
V_28 -> V_24 |= V_36 ;
else
V_28 -> V_24 &= ~ V_36 ;
return 0 ;
}
static void T_2 F_19 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
F_2 ( ~ 0 , V_1 + V_17 ) ;
F_2 ( 0 , V_1 + V_38 ) ;
F_2 ( 0 , V_1 + V_39 ) ;
F_2 ( ~ 0 , V_1 + V_20 ) ;
}
static void T_2 F_20 ( void T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( 0 , V_1 + V_40 ) ;
for ( V_2 = 0 ; V_2 < 19 ; V_2 ++ ) {
unsigned int V_41 ;
V_41 = F_7 ( V_1 + V_40 ) ;
F_2 ( V_41 , V_1 + V_40 ) ;
}
}
static void T_2 F_21 ( void T_1 * V_1 ,
unsigned int V_42 , T_3 V_43 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
if ( V_43 & ( 1 << V_2 ) ) {
unsigned int V_26 = V_42 + V_2 ;
F_22 ( V_26 , & V_44 ,
V_45 ) ;
F_23 ( V_26 , V_1 ) ;
F_24 ( V_26 , V_46 | V_47 ) ;
}
}
}
static void T_2 F_25 ( void T_1 * V_1 , unsigned int V_42 ,
T_3 V_43 )
{
unsigned int V_2 ;
int V_48 = ( ( unsigned long ) V_1 & ~ V_49 ) != 0 ;
F_19 ( V_1 ) ;
if ( V_48 ) {
F_20 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( 0 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
F_21 ( V_1 , V_42 , V_43 ) ;
}
void T_2 F_26 ( void T_1 * V_1 , unsigned int V_42 ,
T_3 V_43 , T_3 V_27 )
{
unsigned int V_2 ;
T_3 V_50 = 0 ;
enum V_51 V_52 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
T_3 V_53 = ( ( T_3 ) V_1 & V_49 ) + 0xfe0 + ( V_2 * 4 ) ;
V_50 |= ( F_7 ( V_53 ) & 0xff ) << ( 8 * V_2 ) ;
}
V_52 = ( V_50 >> 12 ) & 0xff ;
F_4 ( V_54 L_4 ,
V_1 , V_50 , V_52 ) ;
switch( V_52 ) {
case V_55 :
F_25 ( V_1 , V_42 , V_43 ) ;
return;
default:
F_4 ( V_56 L_5 ) ;
case V_57 :
break;
}
F_19 ( V_1 ) ;
F_20 ( V_1 ) ;
F_1 ( V_1 ) ;
F_21 ( V_1 , V_42 , V_43 ) ;
F_11 ( V_1 , V_42 , V_27 ) ;
}
