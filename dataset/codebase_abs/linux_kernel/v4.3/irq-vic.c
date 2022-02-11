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
F_14 ( V_28 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
T_4 V_38 , V_28 ;
int V_39 = 0 ;
while ( ( V_38 = F_16 ( V_8 -> V_1 + V_40 ) ) ) {
V_28 = F_17 ( V_38 ) - 1 ;
F_18 ( V_8 -> V_41 , V_28 , V_37 ) ;
V_39 = 1 ;
}
return V_39 ;
}
static void F_19 ( struct V_42 * V_43 )
{
T_4 V_38 , V_29 ;
struct V_44 * V_45 = F_20 ( V_43 ) ;
struct V_7 * V_8 = F_21 ( V_43 ) ;
F_22 ( V_45 , V_43 ) ;
while ( ( V_38 = F_16 ( V_8 -> V_1 + V_40 ) ) ) {
V_29 = F_17 ( V_38 ) - 1 ;
F_23 ( F_24 ( V_8 -> V_41 , V_29 ) ) ;
}
F_25 ( V_45 , V_43 ) ;
}
static void T_5 F_26 ( struct V_36 * V_37 )
{
int V_2 , V_39 ;
do {
for ( V_2 = 0 , V_39 = 0 ; V_2 < V_22 ; ++ V_2 )
V_39 |= F_15 ( & V_23 [ V_2 ] , V_37 ) ;
} while ( V_39 );
}
static void T_2 F_27 ( void T_1 * V_1 , unsigned int V_46 ,
unsigned int V_28 ,
T_4 V_32 , T_4 V_47 ,
struct V_48 * V_49 )
{
struct V_7 * V_30 ;
int V_2 ;
if ( V_22 >= F_28 ( V_23 ) ) {
F_4 ( V_50 L_3 , V_10 ) ;
return;
}
V_30 = & V_23 [ V_22 ] ;
V_30 -> V_1 = V_1 ;
V_30 -> V_32 = V_32 ;
V_30 -> V_47 = V_47 ;
F_29 ( F_26 ) ;
V_22 ++ ;
if ( V_46 ) {
F_30 ( V_46 ,
F_19 , V_30 ) ;
}
V_30 -> V_41 = F_31 ( V_49 , F_32 ( V_32 ) , V_28 ,
& V_51 , V_30 ) ;
for ( V_2 = 0 ; V_2 < F_32 ( V_32 ) ; V_2 ++ )
if ( V_32 & ( 1 << V_2 ) )
F_33 ( V_30 -> V_41 , V_2 ) ;
if ( V_28 )
V_30 -> V_28 = V_28 ;
else
V_30 -> V_28 = F_24 ( V_30 -> V_41 , 0 ) ;
}
static void F_34 ( struct V_52 * V_27 )
{
void T_1 * V_1 = F_35 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_17 ) ;
F_2 ( 1 << V_28 , V_1 + V_20 ) ;
}
static void F_36 ( struct V_52 * V_27 )
{
void T_1 * V_1 = F_35 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_17 ) ;
}
static void F_37 ( struct V_52 * V_27 )
{
void T_1 * V_1 = F_35 ( V_27 ) ;
unsigned int V_28 = V_27 -> V_29 ;
F_2 ( 1 << V_28 , V_1 + V_16 ) ;
}
static struct V_7 * F_38 ( unsigned int V_28 )
{
struct V_7 * V_30 = V_23 ;
unsigned int V_53 = V_28 & ~ 31 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_30 ++ ) {
if ( V_30 -> V_28 == V_53 )
return V_30 ;
}
return NULL ;
}
static int F_39 ( struct V_52 * V_27 , unsigned int V_54 )
{
struct V_7 * V_30 = F_38 ( V_27 -> V_28 ) ;
unsigned int V_55 = V_27 -> V_29 ;
T_4 V_56 = 1 << V_55 ;
if ( ! V_30 )
return - V_57 ;
if ( ! ( V_56 & V_30 -> V_47 ) )
return - V_57 ;
if ( V_54 )
V_30 -> V_24 |= V_56 ;
else
V_30 -> V_24 &= ~ V_56 ;
return 0 ;
}
static void T_2 F_40 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
F_2 ( ~ 0 , V_1 + V_17 ) ;
F_2 ( 0 , V_1 + V_58 ) ;
F_2 ( ~ 0 , V_1 + V_20 ) ;
}
static void T_2 F_41 ( void T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( 0 , V_1 + V_59 ) ;
for ( V_2 = 0 ; V_2 < 19 ; V_2 ++ ) {
unsigned int V_60 ;
V_60 = F_7 ( V_1 + V_59 ) ;
F_2 ( V_60 , V_1 + V_59 ) ;
}
}
static void T_2 F_42 ( void T_1 * V_1 , unsigned int V_61 ,
T_4 V_62 , struct V_48 * V_49 )
{
unsigned int V_2 ;
int V_63 = ( ( unsigned long ) V_1 & ~ V_64 ) != 0 ;
F_40 ( V_1 ) ;
if ( V_63 ) {
F_41 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( 0 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
F_27 ( V_1 , 0 , V_61 , V_62 , 0 , V_49 ) ;
}
void T_2 F_43 ( void T_1 * V_1 , int V_46 , int V_61 ,
T_4 V_62 , T_4 V_47 ,
struct V_48 * V_49 )
{
unsigned int V_2 ;
T_4 V_65 = 0 ;
enum V_66 V_67 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
void T_1 * V_68 ;
V_68 = ( void T_1 * ) ( ( T_4 ) V_1 & V_64 ) + 0xfe0 + ( V_2 * 4 ) ;
V_65 |= ( F_7 ( V_68 ) & 0xff ) << ( 8 * V_2 ) ;
}
V_67 = ( V_65 >> 12 ) & 0xff ;
F_4 ( V_69 L_4 ,
V_1 , V_65 , V_67 ) ;
switch( V_67 ) {
case V_70 :
F_42 ( V_1 , V_61 , V_62 , V_49 ) ;
return;
default:
F_4 ( V_71 L_5 ) ;
case V_72 :
break;
}
F_40 ( V_1 ) ;
F_41 ( V_1 ) ;
F_1 ( V_1 ) ;
F_27 ( V_1 , V_46 , V_61 , V_62 , V_47 , V_49 ) ;
}
void T_2 F_44 ( void T_1 * V_1 , unsigned int V_61 ,
T_4 V_62 , T_4 V_47 )
{
F_43 ( V_1 , 0 , V_61 , V_62 , V_47 , NULL ) ;
}
int T_2 F_45 ( void T_1 * V_1 , unsigned int V_46 ,
T_4 V_62 , T_4 V_47 )
{
struct V_7 * V_30 ;
V_30 = & V_23 [ V_22 ] ;
F_43 ( V_1 , V_46 , 0 , V_62 , V_47 , NULL ) ;
return V_30 -> V_28 ;
}
int T_2 F_46 ( struct V_48 * V_49 , struct V_48 * V_73 )
{
void T_1 * V_37 ;
T_4 V_74 = ~ 0 ;
T_4 V_75 = ~ 0 ;
if ( F_47 ( V_73 , L_6 ) )
return - V_57 ;
V_37 = F_48 ( V_49 , 0 ) ;
if ( F_49 ( ! V_37 ) )
return - V_76 ;
F_50 ( V_49 , L_7 , & V_74 ) ;
F_50 ( V_49 , L_8 , & V_75 ) ;
F_43 ( V_37 , 0 , 0 , V_74 , V_75 , V_49 ) ;
return 0 ;
}
