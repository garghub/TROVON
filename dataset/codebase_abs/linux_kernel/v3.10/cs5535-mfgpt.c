int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
T_1 V_6 , V_7 , V_8 , V_9 ;
int V_10 = ( V_3 == V_11 ) ? 0 : 8 ;
if ( ! V_2 ) {
F_2 ( 1 ) ;
return - V_12 ;
}
switch ( V_4 ) {
case V_13 :
V_6 = V_14 ;
V_7 = 1 << ( V_2 -> V_15 + 24 ) ;
break;
case V_16 :
V_6 = V_14 ;
V_7 = 1 << ( V_2 -> V_15 + V_10 ) ;
break;
case V_17 :
V_6 = V_18 ;
V_7 = 1 << ( V_2 -> V_15 + V_10 ) ;
break;
default:
return - V_12 ;
}
F_3 ( V_6 , V_8 , V_9 ) ;
if ( V_5 )
V_8 |= V_7 ;
else
V_8 &= ~ V_7 ;
F_4 ( V_6 , V_8 , V_9 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , int * V_19 ,
int V_5 )
{
T_1 V_20 , V_21 , V_9 ;
int V_10 ;
if ( ! V_2 ) {
F_2 ( 1 ) ;
return - V_12 ;
}
F_3 ( V_22 , V_20 , V_9 ) ;
V_10 = ( ( V_3 == V_11 ? 0 : 4 ) + V_2 -> V_15 % 4 ) * 4 ;
if ( ( ( V_20 >> V_10 ) & 0xF ) == 2 )
return - V_12 ;
if ( ! * V_19 )
* V_19 = ( V_20 >> V_10 ) & 0xF ;
if ( ! * V_19 )
* V_19 = V_23 ;
if ( * V_19 < 1 || * V_19 == 2 || * V_19 > 15 )
return - V_12 ;
F_3 ( V_24 , V_21 , V_9 ) ;
if ( V_21 & ( 1 << * V_19 ) )
return - V_12 ;
if ( F_1 ( V_2 , V_3 , V_17 , V_5 ) )
return - V_12 ;
if ( V_5 ) {
V_20 = ( V_20 & ~ ( 0xF << V_10 ) ) | ( * V_19 << V_10 ) ;
F_4 ( V_22 , V_20 , V_9 ) ;
}
return 0 ;
}
struct V_1 * F_6 ( int V_25 , int V_26 )
{
struct V_27 * V_28 = & V_27 ;
struct V_1 * V_2 = NULL ;
unsigned long V_29 ;
int V_30 ;
if ( ! V_28 -> V_31 )
goto V_32;
if ( V_26 == V_33 )
V_30 = 6 ;
else
V_30 = V_34 ;
if ( V_25 >= V_30 ) {
F_2 ( 1 ) ;
goto V_32;
}
F_7 ( & V_28 -> V_35 , V_29 ) ;
if ( V_25 < 0 ) {
unsigned long V_36 ;
V_36 = F_8 ( V_28 -> V_37 , V_30 ) ;
V_25 = V_36 < V_30 ? ( int ) V_36 : - 1 ;
} else {
if ( ! F_9 ( V_25 , V_28 -> V_37 ) )
V_25 = - 1 ;
}
if ( V_25 >= 0 )
F_10 ( V_25 , V_28 -> V_37 ) ;
F_11 ( & V_28 -> V_35 , V_29 ) ;
if ( V_25 < 0 )
goto V_32;
V_2 = F_12 ( sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 ) {
F_7 ( & V_28 -> V_35 , V_29 ) ;
F_13 ( V_25 , V_28 -> V_37 ) ;
F_11 ( & V_28 -> V_35 , V_29 ) ;
goto V_32;
}
V_2 -> V_39 = V_28 ;
V_2 -> V_15 = V_25 ;
F_14 ( & V_28 -> V_40 -> V_41 , L_1 , V_25 ) ;
V_32:
return V_2 ;
}
void F_15 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
T_2 V_42 ;
V_42 = F_16 ( V_2 , V_43 ) ;
if ( ! ( V_42 & V_44 ) ) {
F_7 ( & V_2 -> V_39 -> V_35 , V_29 ) ;
F_13 ( V_2 -> V_15 , V_2 -> V_39 -> V_37 ) ;
F_11 ( & V_2 -> V_39 -> V_35 , V_29 ) ;
}
F_17 ( V_2 ) ;
}
T_2 F_16 ( struct V_1 * V_2 , T_2 V_45 )
{
return F_18 ( V_2 -> V_39 -> V_46 + V_45 + ( V_2 -> V_15 * 8 ) ) ;
}
void F_19 ( struct V_1 * V_2 , T_2 V_45 ,
T_2 V_8 )
{
F_20 ( V_8 , V_2 -> V_39 -> V_46 + V_45 + ( V_2 -> V_15 * 8 ) ) ;
}
static void F_21 ( void )
{
T_1 V_42 , V_9 ;
V_42 = 0xFF ; V_9 = 0 ;
F_4 ( V_47 , V_42 , V_9 ) ;
}
static void F_22 ( void )
{
int V_48 ;
struct V_1 V_36 ;
for ( V_48 = 0 ; V_48 < V_34 ; V_48 ++ ) {
V_36 . V_15 = V_48 ;
F_1 ( & V_36 , V_11 , V_13 , 0 ) ;
F_1 ( & V_36 , V_49 , V_13 , 0 ) ;
F_1 ( & V_36 , V_11 , V_16 , 0 ) ;
F_1 ( & V_36 , V_49 , V_16 , 0 ) ;
F_1 ( & V_36 , V_11 , V_17 , 0 ) ;
F_1 ( & V_36 , V_49 , V_17 , 0 ) ;
}
}
static int F_23 ( struct V_27 * V_28 )
{
struct V_1 V_2 = { . V_39 = V_28 } ;
unsigned long V_29 ;
int V_50 = 0 ;
T_2 V_42 ;
int V_48 ;
if ( V_51 == 1 )
F_21 () ;
else if ( V_51 == 2 )
F_22 () ;
F_7 ( & V_28 -> V_35 , V_29 ) ;
for ( V_48 = 0 ; V_48 < V_34 ; V_48 ++ ) {
V_2 . V_15 = V_48 ;
V_42 = F_16 ( & V_2 , V_43 ) ;
if ( ! ( V_42 & V_44 ) || V_51 == 2 ) {
F_13 ( V_48 , V_28 -> V_37 ) ;
V_50 ++ ;
}
}
F_11 ( & V_28 -> V_35 , V_29 ) ;
return V_50 ;
}
static int F_24 ( struct V_52 * V_40 )
{
struct V_53 * V_54 ;
int V_55 = - V_12 , V_36 ;
if ( V_51 < 0 || V_51 > 2 ) {
F_25 ( & V_40 -> V_41 , L_2 ,
V_51 ) ;
goto V_32;
}
V_54 = F_26 ( V_40 , V_56 , 0 ) ;
if ( ! V_54 ) {
F_25 ( & V_40 -> V_41 , L_3 ) ;
goto V_32;
}
if ( ! F_27 ( V_54 -> V_57 , F_28 ( V_54 ) , V_40 -> V_58 ) ) {
F_25 ( & V_40 -> V_41 , L_4 ) ;
goto V_32;
}
V_27 . V_46 = V_54 -> V_57 ;
V_27 . V_40 = V_40 ;
F_29 ( & V_27 . V_35 ) ;
F_14 ( & V_40 -> V_41 , L_5 , V_54 ) ;
V_36 = F_23 ( & V_27 ) ;
F_14 ( & V_40 -> V_41 , L_6 , V_36 ) ;
V_27 . V_31 = 1 ;
return 0 ;
V_32:
return V_55 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_59 ) ;
}
