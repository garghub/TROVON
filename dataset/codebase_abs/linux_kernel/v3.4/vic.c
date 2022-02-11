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
static void T_2 F_11 ( void T_1 * V_1 , unsigned int V_26 ,
T_3 V_27 , struct V_28 * V_29 )
{
struct V_7 * V_30 ;
if ( V_22 >= F_12 ( V_23 ) ) {
F_4 ( V_31 L_3 , V_10 ) ;
return;
}
V_30 = & V_23 [ V_22 ] ;
V_30 -> V_1 = V_1 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_26 = V_26 ;
V_22 ++ ;
V_30 -> V_32 = F_13 ( V_29 , 32 , V_26 , 0 ,
& V_33 , V_30 ) ;
}
static void F_14 ( struct V_34 * V_35 )
{
void T_1 * V_1 = F_15 ( V_35 ) ;
unsigned int V_26 = V_35 -> V_36 ;
F_2 ( 1 << V_26 , V_1 + V_17 ) ;
F_2 ( 1 << V_26 , V_1 + V_20 ) ;
}
static void F_16 ( struct V_34 * V_35 )
{
void T_1 * V_1 = F_15 ( V_35 ) ;
unsigned int V_26 = V_35 -> V_36 ;
F_2 ( 1 << V_26 , V_1 + V_17 ) ;
}
static void F_17 ( struct V_34 * V_35 )
{
void T_1 * V_1 = F_15 ( V_35 ) ;
unsigned int V_26 = V_35 -> V_36 ;
F_2 ( 1 << V_26 , V_1 + V_16 ) ;
}
static struct V_7 * F_18 ( unsigned int V_26 )
{
struct V_7 * V_30 = V_23 ;
unsigned int V_37 = V_26 & ~ 31 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_30 ++ ) {
if ( V_30 -> V_26 == V_37 )
return V_30 ;
}
return NULL ;
}
static int F_19 ( struct V_34 * V_35 , unsigned int V_38 )
{
struct V_7 * V_30 = F_18 ( V_35 -> V_26 ) ;
unsigned int V_39 = V_35 -> V_36 ;
T_3 V_40 = 1 << V_39 ;
if ( ! V_30 )
return - V_41 ;
if ( ! ( V_40 & V_30 -> V_27 ) )
return - V_41 ;
if ( V_38 )
V_30 -> V_24 |= V_40 ;
else
V_30 -> V_24 &= ~ V_40 ;
return 0 ;
}
static void T_2 F_20 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
F_2 ( ~ 0 , V_1 + V_17 ) ;
F_2 ( 0 , V_1 + V_42 ) ;
F_2 ( ~ 0 , V_1 + V_20 ) ;
}
static void T_2 F_21 ( void T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( 0 , V_1 + V_43 ) ;
for ( V_2 = 0 ; V_2 < 19 ; V_2 ++ ) {
unsigned int V_44 ;
V_44 = F_7 ( V_1 + V_43 ) ;
F_2 ( V_44 , V_1 + V_43 ) ;
}
}
static void T_2 F_22 ( void T_1 * V_1 ,
unsigned int V_45 , T_3 V_46 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
if ( V_46 & ( 1 << V_2 ) ) {
unsigned int V_26 = V_45 + V_2 ;
F_23 ( V_26 , & V_47 ,
V_48 ) ;
F_24 ( V_26 , V_1 ) ;
F_25 ( V_26 , V_49 | V_50 ) ;
}
}
}
static void T_2 F_26 ( void T_1 * V_1 , unsigned int V_45 ,
T_3 V_46 , struct V_28 * V_29 )
{
unsigned int V_2 ;
int V_51 = ( ( unsigned long ) V_1 & ~ V_52 ) != 0 ;
F_20 ( V_1 ) ;
if ( V_51 ) {
F_21 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( 0 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
F_22 ( V_1 , V_45 , V_46 ) ;
F_11 ( V_1 , V_45 , 0 , V_29 ) ;
}
void T_2 F_27 ( void T_1 * V_1 , unsigned int V_45 ,
T_3 V_46 , T_3 V_27 ,
struct V_28 * V_29 )
{
unsigned int V_2 ;
T_3 V_53 = 0 ;
enum V_54 V_55 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
void T_1 * V_56 ;
V_56 = ( void T_1 * ) ( ( T_3 ) V_1 & V_52 ) + 0xfe0 + ( V_2 * 4 ) ;
V_53 |= ( F_7 ( V_56 ) & 0xff ) << ( 8 * V_2 ) ;
}
V_55 = ( V_53 >> 12 ) & 0xff ;
F_4 ( V_57 L_4 ,
V_1 , V_53 , V_55 ) ;
switch( V_55 ) {
case V_58 :
F_26 ( V_1 , V_45 , V_46 , V_29 ) ;
return;
default:
F_4 ( V_59 L_5 ) ;
case V_60 :
break;
}
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
F_1 ( V_1 ) ;
F_22 ( V_1 , V_45 , V_46 ) ;
F_11 ( V_1 , V_45 , V_27 , V_29 ) ;
}
void T_2 F_28 ( void T_1 * V_1 , unsigned int V_45 ,
T_3 V_46 , T_3 V_27 )
{
F_27 ( V_1 , V_45 , V_46 , V_27 , NULL ) ;
}
int T_2 F_29 ( struct V_28 * V_29 , struct V_28 * V_61 )
{
void T_1 * V_62 ;
int V_63 ;
if ( F_30 ( V_61 , L_6 ) )
return - V_41 ;
V_62 = F_31 ( V_29 , 0 ) ;
if ( F_32 ( ! V_62 ) )
return - V_64 ;
V_63 = F_33 ( - 1 , 0 , 32 , F_34 () ) ;
if ( F_32 ( V_63 < 0 ) )
goto V_65;
F_27 ( V_62 , V_63 , ~ 0 , ~ 0 , V_29 ) ;
return 0 ;
V_65:
F_35 ( V_62 ) ;
return - V_64 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_66 * V_62 )
{
T_3 V_67 , V_26 ;
int V_68 = 0 ;
while ( ( V_67 = F_37 ( V_8 -> V_1 + V_69 ) ) ) {
V_26 = F_38 ( V_67 ) - 1 ;
F_39 ( F_40 ( V_8 -> V_32 , V_26 ) , V_62 ) ;
V_68 = 1 ;
}
return V_68 ;
}
T_4 void T_5 F_41 ( struct V_66 * V_62 )
{
int V_2 , V_68 ;
do {
for ( V_2 = 0 , V_68 = 0 ; V_2 < V_22 ; ++ V_2 )
V_68 |= F_36 ( & V_23 [ V_2 ] , V_62 ) ;
} while ( V_68 );
}
