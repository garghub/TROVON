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
V_30 -> V_32 . V_33 = V_26 ;
V_30 -> V_32 . V_34 = 32 ;
#ifdef F_13
V_30 -> V_32 . V_35 = F_14 ( V_29 ) ;
#endif
V_30 -> V_32 . V_36 = & V_37 ;
F_15 ( & V_30 -> V_32 ) ;
}
static void F_16 ( struct V_38 * V_39 )
{
void T_1 * V_1 = F_17 ( V_39 ) ;
unsigned int V_26 = V_39 -> V_40 ;
F_2 ( 1 << V_26 , V_1 + V_17 ) ;
F_2 ( 1 << V_26 , V_1 + V_20 ) ;
}
static void F_18 ( struct V_38 * V_39 )
{
void T_1 * V_1 = F_17 ( V_39 ) ;
unsigned int V_26 = V_39 -> V_40 ;
F_2 ( 1 << V_26 , V_1 + V_17 ) ;
}
static void F_19 ( struct V_38 * V_39 )
{
void T_1 * V_1 = F_17 ( V_39 ) ;
unsigned int V_26 = V_39 -> V_40 ;
F_2 ( 1 << V_26 , V_1 + V_16 ) ;
}
static struct V_7 * F_20 ( unsigned int V_26 )
{
struct V_7 * V_30 = V_23 ;
unsigned int V_41 = V_26 & ~ 31 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_30 ++ ) {
if ( V_30 -> V_26 == V_41 )
return V_30 ;
}
return NULL ;
}
static int F_21 ( struct V_38 * V_39 , unsigned int V_42 )
{
struct V_7 * V_30 = F_20 ( V_39 -> V_26 ) ;
unsigned int V_43 = V_39 -> V_40 ;
T_3 V_44 = 1 << V_43 ;
if ( ! V_30 )
return - V_45 ;
if ( ! ( V_44 & V_30 -> V_27 ) )
return - V_45 ;
if ( V_42 )
V_30 -> V_24 |= V_44 ;
else
V_30 -> V_24 &= ~ V_44 ;
return 0 ;
}
static void T_2 F_22 ( void T_1 * V_1 )
{
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
F_2 ( ~ 0 , V_1 + V_17 ) ;
F_2 ( 0 , V_1 + V_46 ) ;
F_2 ( ~ 0 , V_1 + V_20 ) ;
}
static void T_2 F_23 ( void T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( 0 , V_1 + V_47 ) ;
for ( V_2 = 0 ; V_2 < 19 ; V_2 ++ ) {
unsigned int V_48 ;
V_48 = F_7 ( V_1 + V_47 ) ;
F_2 ( V_48 , V_1 + V_47 ) ;
}
}
static void T_2 F_24 ( void T_1 * V_1 ,
unsigned int V_49 , T_3 V_50 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
if ( V_50 & ( 1 << V_2 ) ) {
unsigned int V_26 = V_49 + V_2 ;
F_25 ( V_26 , & V_51 ,
V_52 ) ;
F_26 ( V_26 , V_1 ) ;
F_27 ( V_26 , V_53 | V_54 ) ;
}
}
}
static void T_2 F_28 ( void T_1 * V_1 , unsigned int V_49 ,
T_3 V_50 , struct V_28 * V_29 )
{
unsigned int V_2 ;
int V_55 = ( ( unsigned long ) V_1 & ~ V_56 ) != 0 ;
F_22 ( V_1 ) ;
if ( V_55 ) {
F_23 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 16 ; V_2 ++ ) {
void T_1 * V_3 = V_1 + V_4 + ( V_2 * 4 ) ;
F_2 ( 0 , V_3 ) ;
}
F_2 ( 32 , V_1 + V_6 ) ;
}
F_24 ( V_1 , V_49 , V_50 ) ;
F_11 ( V_1 , V_49 , 0 , V_29 ) ;
}
static void T_2 F_29 ( void T_1 * V_1 , unsigned int V_49 ,
T_3 V_50 , T_3 V_27 ,
struct V_28 * V_29 )
{
unsigned int V_2 ;
T_3 V_57 = 0 ;
enum V_58 V_59 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
void T_1 * V_60 ;
V_60 = ( void T_1 * ) ( ( T_3 ) V_1 & V_56 ) + 0xfe0 + ( V_2 * 4 ) ;
V_57 |= ( F_7 ( V_60 ) & 0xff ) << ( 8 * V_2 ) ;
}
V_59 = ( V_57 >> 12 ) & 0xff ;
F_4 ( V_61 L_4 ,
V_1 , V_57 , V_59 ) ;
switch( V_59 ) {
case V_62 :
F_28 ( V_1 , V_49 , V_50 , V_29 ) ;
return;
default:
F_4 ( V_63 L_5 ) ;
case V_64 :
break;
}
F_22 ( V_1 ) ;
F_23 ( V_1 ) ;
F_1 ( V_1 ) ;
F_24 ( V_1 , V_49 , V_50 ) ;
F_11 ( V_1 , V_49 , V_27 , V_29 ) ;
}
void T_2 F_30 ( void T_1 * V_1 , unsigned int V_49 ,
T_3 V_50 , T_3 V_27 )
{
F_29 ( V_1 , V_49 , V_50 , V_27 , NULL ) ;
}
int T_2 F_31 ( struct V_28 * V_29 , struct V_28 * V_65 )
{
void T_1 * V_66 ;
int V_33 ;
if ( F_32 ( V_65 , L_6 ) )
return - V_45 ;
V_66 = F_33 ( V_29 , 0 ) ;
if ( F_34 ( ! V_66 ) )
return - V_67 ;
V_33 = F_35 ( - 1 , 0 , 32 , F_36 () ) ;
if ( F_34 ( V_33 < 0 ) )
goto V_68;
F_29 ( V_66 , V_33 , ~ 0 , ~ 0 , V_29 ) ;
return 0 ;
V_68:
F_37 ( V_66 ) ;
return - V_67 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_69 * V_66 )
{
T_3 V_70 , V_26 ;
int V_71 = 0 ;
V_70 = F_39 ( V_8 -> V_1 + V_72 ) ;
while ( V_70 ) {
V_26 = F_40 ( V_70 ) - 1 ;
F_41 ( F_42 ( & V_8 -> V_32 , V_26 ) , V_66 ) ;
V_70 &= ~ ( 1 << V_26 ) ;
V_71 = 1 ;
}
return V_71 ;
}
T_4 void T_5 F_43 ( struct V_69 * V_66 )
{
int V_2 , V_71 ;
do {
for ( V_2 = 0 , V_71 = 0 ; V_2 < V_22 ; ++ V_2 )
V_71 |= F_38 ( & V_23 [ V_2 ] , V_66 ) ;
} while ( V_71 );
}
