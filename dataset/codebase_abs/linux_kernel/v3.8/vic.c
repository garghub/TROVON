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
static int F_11 ( struct V_26 * V_27 , unsigned int V_28 ,
T_3 V_29 )
{
struct V_7 * V_30 = V_27 -> V_31 ;
if ( ! ( V_30 -> V_32 & ( 1 << V_29 ) ) )
return - V_33 ;
F_12 ( V_28 , & V_34 , V_35 ) ;
F_13 ( V_28 , V_30 -> V_1 ) ;
F_14 ( V_28 , V_36 | V_37 ) ;
return 0 ;
}
static void T_2 F_15 ( void T_1 * V_1 , unsigned int V_28 ,
T_4 V_32 , T_4 V_38 ,
struct V_39 * V_40 )
{
struct V_7 * V_30 ;
int V_2 ;
if ( V_22 >= F_16 ( V_23 ) ) {
F_4 ( V_41 L_3 , V_10 ) ;
return;
}
V_30 = & V_23 [ V_22 ] ;
V_30 -> V_1 = V_1 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_38 = V_38 ;
V_30 -> V_28 = V_28 ;
V_22 ++ ;
V_30 -> V_42 = F_17 ( V_40 , F_18 ( V_32 ) , V_28 ,
& V_43 , V_30 ) ;
for ( V_2 = 0 ; V_2 < F_18 ( V_32 ) ; V_2 ++ )
if ( V_32 & ( 1 << V_2 ) )
F_19 ( V_30 -> V_42 , V_2 ) ;
}
static void F_20 ( struct V_44 * V_27 )
{
void T_1 * V_1 = F_21 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_17 ) ;
F_2 ( 1 << V_28 , V_1 + V_20 ) ;
}
static void F_22 ( struct V_44 * V_27 )
{
void T_1 * V_1 = F_21 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_17 ) ;
}
static void F_23 ( struct V_44 * V_27 )
{
void T_1 * V_1 = F_21 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_16 ) ;
}
static struct V_7 * F_24 ( unsigned int V_28 )
{
struct V_7 * V_30 = V_23 ;
unsigned int V_45 = V_28 & ~ 31 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_30 ++ ) {
if ( V_30 -> V_28 == V_45 )
return V_30 ;
}
return NULL ;
}
static int F_25 ( struct V_44 * V_27 , unsigned int V_46 )
{
struct V_7 * V_30 = F_24 ( V_27 -> V_28 ) ;
unsigned int V_47 = V_27 -> V_29 ;
T_4 V_48 = 1 << V_47 ;
if ( ! V_30 )
return - V_49 ;
if ( ! ( V_48 & V_30 -> V_38 ) )
return - V_49 ;
if ( V_46 )
V_30 -> V_24 |= V_48 ;
else
V_30 -> V_24 &= ~ V_48 ;
return 0 ;
}
static void T_2 F_26 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
F_2 ( ~ 0 , V_1 + V_17 ) ;
F_2 ( 0 , V_1 + V_50 ) ;
F_2 ( ~ 0 , V_1 + V_20 ) ;
}
static void T_2 F_27 ( void T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( 0 , V_1 + V_51 ) ;
for ( V_2 = 0 ; V_2 < 19 ; V_2 ++ ) {
unsigned int V_52 ;
V_52 = F_7 ( V_1 + V_51 ) ;
F_2 ( V_52 , V_1 + V_51 ) ;
}
}
static void T_2 F_28 ( void T_1 * V_1 , unsigned int V_53 ,
T_4 V_54 , struct V_39 * V_40 )
{
unsigned int V_2 ;
int V_55 = ( ( unsigned long ) V_1 & ~ V_56 ) != 0 ;
F_26 ( V_1 ) ;
if ( V_55 ) {
F_27 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( 0 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
F_15 ( V_1 , V_53 , V_54 , 0 , V_40 ) ;
}
void T_2 F_29 ( void T_1 * V_1 , int V_53 ,
T_4 V_54 , T_4 V_38 ,
struct V_39 * V_40 )
{
unsigned int V_2 ;
T_4 V_57 = 0 ;
enum V_58 V_59 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
void T_1 * V_60 ;
V_60 = ( void T_1 * ) ( ( T_4 ) V_1 & V_56 ) + 0xfe0 + ( V_2 * 4 ) ;
V_57 |= ( F_7 ( V_60 ) & 0xff ) << ( 8 * V_2 ) ;
}
V_59 = ( V_57 >> 12 ) & 0xff ;
F_4 ( V_61 L_4 ,
V_1 , V_57 , V_59 ) ;
switch( V_59 ) {
case V_62 :
F_28 ( V_1 , V_53 , V_54 , V_40 ) ;
return;
default:
F_4 ( V_63 L_5 ) ;
case V_64 :
break;
}
F_26 ( V_1 ) ;
F_27 ( V_1 ) ;
F_1 ( V_1 ) ;
F_15 ( V_1 , V_53 , V_54 , V_38 , V_40 ) ;
}
void T_2 F_30 ( void T_1 * V_1 , unsigned int V_53 ,
T_4 V_54 , T_4 V_38 )
{
F_29 ( V_1 , V_53 , V_54 , V_38 , NULL ) ;
}
int T_2 F_31 ( struct V_39 * V_40 , struct V_39 * V_65 )
{
void T_1 * V_66 ;
if ( F_32 ( V_65 , L_6 ) )
return - V_49 ;
V_66 = F_33 ( V_40 , 0 ) ;
if ( F_34 ( ! V_66 ) )
return - V_67 ;
F_29 ( V_66 , 0 , ~ 0 , ~ 0 , V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , struct V_68 * V_66 )
{
T_4 V_69 , V_28 ;
int V_70 = 0 ;
while ( ( V_69 = F_36 ( V_8 -> V_1 + V_71 ) ) ) {
V_28 = F_37 ( V_69 ) - 1 ;
F_38 ( F_39 ( V_8 -> V_42 , V_28 ) , V_66 ) ;
V_70 = 1 ;
}
return V_70 ;
}
T_5 void T_6 F_40 ( struct V_68 * V_66 )
{
int V_2 , V_70 ;
do {
for ( V_2 = 0 , V_70 = 0 ; V_2 < V_22 ; ++ V_2 )
V_70 |= F_35 ( & V_23 [ V_2 ] , V_66 ) ;
} while ( V_70 );
}
