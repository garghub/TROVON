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
static int F_15 ( struct V_7 * V_8 , struct V_38 * V_39 )
{
T_4 V_40 , V_28 ;
int V_41 = 0 ;
while ( ( V_40 = F_16 ( V_8 -> V_1 + V_42 ) ) ) {
V_28 = F_17 ( V_40 ) - 1 ;
F_18 ( V_8 -> V_43 , V_28 , V_39 ) ;
V_41 = 1 ;
}
return V_41 ;
}
static void F_19 ( unsigned int V_28 , struct V_44 * V_45 )
{
T_4 V_40 , V_29 ;
struct V_46 * V_47 = F_20 ( V_45 ) ;
struct V_7 * V_8 = F_21 ( V_45 ) ;
F_22 ( V_47 , V_45 ) ;
while ( ( V_40 = F_16 ( V_8 -> V_1 + V_42 ) ) ) {
V_29 = F_17 ( V_40 ) - 1 ;
F_23 ( F_24 ( V_8 -> V_43 , V_29 ) ) ;
}
F_25 ( V_47 , V_45 ) ;
}
static void T_5 F_26 ( struct V_38 * V_39 )
{
int V_2 , V_41 ;
do {
for ( V_2 = 0 , V_41 = 0 ; V_2 < V_22 ; ++ V_2 )
V_41 |= F_15 ( & V_23 [ V_2 ] , V_39 ) ;
} while ( V_41 );
}
static void T_2 F_27 ( void T_1 * V_1 , unsigned int V_48 ,
unsigned int V_28 ,
T_4 V_32 , T_4 V_49 ,
struct V_50 * V_51 )
{
struct V_7 * V_30 ;
int V_2 ;
if ( V_22 >= F_28 ( V_23 ) ) {
F_4 ( V_52 L_3 , V_10 ) ;
return;
}
V_30 = & V_23 [ V_22 ] ;
V_30 -> V_1 = V_1 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_49 = V_49 ;
F_29 ( F_26 ) ;
V_22 ++ ;
if ( V_48 ) {
F_30 ( V_48 , V_30 ) ;
F_31 ( V_48 , F_19 ) ;
}
V_30 -> V_43 = F_32 ( V_51 , F_33 ( V_32 ) , V_28 ,
& V_53 , V_30 ) ;
for ( V_2 = 0 ; V_2 < F_33 ( V_32 ) ; V_2 ++ )
if ( V_32 & ( 1 << V_2 ) )
F_34 ( V_30 -> V_43 , V_2 ) ;
if ( V_28 )
V_30 -> V_28 = V_28 ;
else
V_30 -> V_28 = F_24 ( V_30 -> V_43 , 0 ) ;
}
static void F_35 ( struct V_54 * V_27 )
{
void T_1 * V_1 = F_36 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_17 ) ;
F_2 ( 1 << V_28 , V_1 + V_20 ) ;
}
static void F_37 ( struct V_54 * V_27 )
{
void T_1 * V_1 = F_36 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_17 ) ;
}
static void F_38 ( struct V_54 * V_27 )
{
void T_1 * V_1 = F_36 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_16 ) ;
}
static struct V_7 * F_39 ( unsigned int V_28 )
{
struct V_7 * V_30 = V_23 ;
unsigned int V_55 = V_28 & ~ 31 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_30 ++ ) {
if ( V_30 -> V_28 == V_55 )
return V_30 ;
}
return NULL ;
}
static int F_40 ( struct V_54 * V_27 , unsigned int V_56 )
{
struct V_7 * V_30 = F_39 ( V_27 -> V_28 ) ;
unsigned int V_57 = V_27 -> V_29 ;
T_4 V_58 = 1 << V_57 ;
if ( ! V_30 )
return - V_59 ;
if ( ! ( V_58 & V_30 -> V_49 ) )
return - V_59 ;
if ( V_56 )
V_30 -> V_24 |= V_58 ;
else
V_30 -> V_24 &= ~ V_58 ;
return 0 ;
}
static void T_2 F_41 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
F_2 ( ~ 0 , V_1 + V_17 ) ;
F_2 ( 0 , V_1 + V_60 ) ;
F_2 ( ~ 0 , V_1 + V_20 ) ;
}
static void T_2 F_42 ( void T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( 0 , V_1 + V_61 ) ;
for ( V_2 = 0 ; V_2 < 19 ; V_2 ++ ) {
unsigned int V_62 ;
V_62 = F_7 ( V_1 + V_61 ) ;
F_2 ( V_62 , V_1 + V_61 ) ;
}
}
static void T_2 F_43 ( void T_1 * V_1 , unsigned int V_63 ,
T_4 V_64 , struct V_50 * V_51 )
{
unsigned int V_2 ;
int V_65 = ( ( unsigned long ) V_1 & ~ V_66 ) != 0 ;
F_41 ( V_1 ) ;
if ( V_65 ) {
F_42 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( 0 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
F_27 ( V_1 , 0 , V_63 , V_64 , 0 , V_51 ) ;
}
void T_2 F_44 ( void T_1 * V_1 , int V_48 , int V_63 ,
T_4 V_64 , T_4 V_49 ,
struct V_50 * V_51 )
{
unsigned int V_2 ;
T_4 V_67 = 0 ;
enum V_68 V_69 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
void T_1 * V_70 ;
V_70 = ( void T_1 * ) ( ( T_4 ) V_1 & V_66 ) + 0xfe0 + ( V_2 * 4 ) ;
V_67 |= ( F_7 ( V_70 ) & 0xff ) << ( 8 * V_2 ) ;
}
V_69 = ( V_67 >> 12 ) & 0xff ;
F_4 ( V_71 L_4 ,
V_1 , V_67 , V_69 ) ;
switch( V_69 ) {
case V_72 :
F_43 ( V_1 , V_63 , V_64 , V_51 ) ;
return;
default:
F_4 ( V_73 L_5 ) ;
case V_74 :
break;
}
F_41 ( V_1 ) ;
F_42 ( V_1 ) ;
F_1 ( V_1 ) ;
F_27 ( V_1 , V_48 , V_63 , V_64 , V_49 , V_51 ) ;
}
void T_2 F_45 ( void T_1 * V_1 , unsigned int V_63 ,
T_4 V_64 , T_4 V_49 )
{
F_44 ( V_1 , 0 , V_63 , V_64 , V_49 , NULL ) ;
}
int T_2 F_46 ( void T_1 * V_1 , unsigned int V_48 ,
T_4 V_64 , T_4 V_49 )
{
struct V_7 * V_30 ;
V_30 = & V_23 [ V_22 ] ;
F_44 ( V_1 , V_48 , 0 , V_64 , V_49 , NULL ) ;
return V_30 -> V_28 ;
}
int T_2 F_47 ( struct V_50 * V_51 , struct V_50 * V_75 )
{
void T_1 * V_39 ;
T_4 V_76 = ~ 0 ;
T_4 V_77 = ~ 0 ;
if ( F_48 ( V_75 , L_6 ) )
return - V_59 ;
V_39 = F_49 ( V_51 , 0 ) ;
if ( F_50 ( ! V_39 ) )
return - V_78 ;
F_51 ( V_51 , L_7 , & V_76 ) ;
F_51 ( V_51 , L_8 , & V_77 ) ;
F_44 ( V_39 , 0 , 0 , V_76 , V_77 , V_51 ) ;
return 0 ;
}
