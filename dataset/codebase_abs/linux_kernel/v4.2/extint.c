static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_4 , 1 << ( V_2 -> V_5 - V_3 -> V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_7 , 1 << ( V_2 -> V_5 - V_3 -> V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_4 , 1 << ( V_2 -> V_5 - V_3 -> V_6 ) ) ;
F_3 ( V_3 , V_7 , 1 << ( V_2 -> V_5 - V_3 -> V_6 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_3 ( V_3 , V_8 , 1 << ( V_2 -> V_5 - V_3 -> V_6 ) ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned int V_5 = V_2 -> V_5 ;
unsigned int V_10 = V_5 - V_3 -> V_6 ;
T_1 V_11 , V_12 , V_13 ;
V_9 &= V_14 ;
if ( V_9 == V_15 )
V_9 = V_16 ;
V_11 = F_8 ( V_3 , V_17 ) ;
V_12 = F_8 ( V_3 , V_18 ) ;
V_13 = F_8 ( V_3 , V_19 ) ;
switch ( V_9 ) {
case V_16 :
V_11 |= 1 << V_10 ;
V_13 &= ~ ( 1 << V_10 ) ;
break;
case V_20 :
V_11 |= 1 << V_10 ;
V_13 |= 1 << V_10 ;
break;
case V_21 :
V_11 &= ~ ( 1 << V_10 ) ;
V_12 |= 1 << V_10 ;
break;
case V_22 :
V_11 &= ~ ( 1 << V_10 ) ;
V_12 &= ~ ( 1 << V_10 ) ;
break;
default:
return - V_23 ;
}
F_3 ( V_3 , V_17 , V_11 ) ;
F_3 ( V_3 , V_18 , V_12 ) ;
F_3 ( V_3 , V_19 , V_13 ) ;
F_9 ( V_2 , V_9 ) ;
if ( V_9 & ( V_16 | V_20 ) )
F_10 ( V_5 , V_24 ) ;
else
F_10 ( V_5 , V_25 ) ;
return V_26 ;
}
static void F_11 ( unsigned int V_5 , struct V_27 * V_28 )
{
struct V_3 * V_3 = F_12 ( V_28 ) ;
unsigned long V_29 , V_30 ;
unsigned int V_10 ;
V_29 = F_8 ( V_3 , V_31 ) ;
V_30 = V_29 & F_8 ( V_3 , V_32 ) ;
while ( V_30 ) {
V_10 = F_13 ( V_30 ) - 1 ;
V_30 &= ~ ( 1 << V_10 ) ;
F_14 ( V_10 + V_3 -> V_6 ) ;
}
}
int F_15 ( void )
{
V_33 = true ;
if ( V_34 )
F_3 ( V_34 , V_35 , V_36 ) ;
return 0 ;
}
void F_16 ( void )
{
if ( V_34 )
F_3 ( V_34 , V_35 , 0 ) ;
V_33 = false ;
}
static int T_2 F_17 ( struct V_37 * V_38 )
{
struct V_3 * V_3 ;
struct V_39 * V_40 ;
unsigned int V_10 ;
unsigned int V_41 ;
unsigned int V_42 ;
int V_43 ;
T_1 V_44 ;
V_40 = F_18 ( V_38 , V_45 , 0 ) ;
V_42 = F_19 ( V_38 , 0 ) ;
if ( ! V_40 || ( int ) V_42 <= 0 ) {
F_20 ( & V_38 -> V_46 , L_1 ) ;
return - V_47 ;
}
V_43 = - V_48 ;
V_3 = F_21 ( sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_3 ) {
F_20 ( & V_38 -> V_46 , L_2 ) ;
goto V_50;
}
V_3 -> V_6 = V_51 + 32 * V_38 -> V_52 ;
V_3 -> V_40 = F_22 ( V_40 -> V_53 , F_23 ( V_40 ) ) ;
if ( ! V_3 -> V_40 ) {
F_20 ( & V_38 -> V_46 , L_3 ) ;
goto V_54;
}
F_3 ( V_3 , V_7 , ~ 0UL ) ;
F_3 ( V_3 , V_17 , ~ 0UL ) ;
V_44 = F_8 ( V_3 , V_17 ) ;
V_41 = F_13 ( V_44 ) ;
F_3 ( V_3 , V_18 , 0UL ) ;
F_3 ( V_3 , V_19 , 0UL ) ;
V_3 -> V_55 = & V_56 ;
for ( V_10 = 0 ; V_10 < V_41 ; V_10 ++ ) {
F_24 ( V_3 -> V_6 + V_10 , & V_56 ,
V_24 ) ;
F_25 ( V_3 -> V_6 + V_10 , V_3 ) ;
}
F_26 ( V_42 , F_11 , V_3 ) ;
if ( V_38 -> V_52 == 0 ) {
V_34 = V_3 ;
if ( V_33 )
F_15 () ;
}
F_27 ( & V_38 -> V_46 ,
L_4 ,
V_3 -> V_40 , V_42 ) ;
F_27 ( & V_38 -> V_46 ,
L_5 ,
V_41 , V_3 -> V_6 ) ;
return 0 ;
V_54:
F_28 ( V_3 ) ;
V_50:
return V_43 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_57 , F_17 ) ;
}
