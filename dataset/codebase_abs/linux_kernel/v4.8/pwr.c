static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + F_3 ( V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_5 ( V_5 , V_2 -> V_4 + F_6 ( V_3 ) ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_5 ( V_5 , V_2 -> V_4 + F_8 ( V_3 ) ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 ( ~ V_6 , V_2 -> V_4 + V_7 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_4 + V_8 ) & V_9 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned int V_10 = 500000 ;
bool V_11 ;
do {
V_11 = F_10 ( V_2 ) ;
if ( ! V_11 )
return 0 ;
F_12 ( 1 ) ;
} while ( -- V_10 );
return - V_12 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_13 )
{
F_5 ( F_14 ( V_13 ) , V_2 -> V_4 + V_14 ) ;
return F_11 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 , int V_15 , int V_16 )
{
int V_17 ;
T_1 V_18 ;
int V_19 ;
V_18 = F_1 ( V_2 , V_3 ) ;
V_17 = ( V_18 >> V_15 ) & 3 ;
if ( V_17 == V_16 )
return 0 ;
F_4 ( V_2 , V_3 , ( V_18 & ~ ( 3 << V_15 ) ) | ( V_16 << V_15 ) ) ;
V_19 = F_13 ( V_2 , V_20 ) ;
if ( V_19 )
return V_19 ;
V_18 = F_1 ( V_2 , V_3 ) ;
V_17 = ( V_18 >> V_15 ) & 3 ;
if ( V_17 != V_16 )
return - V_21 ;
return 0 ;
}
static T_3 F_16 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
T_3 V_26 )
{
T_3 V_27 = V_28 ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
if ( V_23 [ V_29 ] . V_25 == V_25 || ! V_23 [ V_29 ] . V_25 )
break;
}
if ( V_29 < V_30 ) {
V_23 [ V_29 ] . V_25 = V_25 ;
V_23 [ V_29 ] . V_26 = V_26 ;
} else {
F_17 ( & V_25 -> V_31 , L_1 ) ;
V_27 = V_26 ;
}
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
if ( V_23 [ V_29 ] . V_26 < V_27 )
V_27 = V_23 [ V_29 ] . V_26 ;
}
return V_27 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_24 * V_25 ,
T_3 V_26 , int V_32 , int V_3 , int V_15 )
{
const char * V_33 ;
int V_19 ;
V_26 = F_16 ( V_2 -> V_23 [ V_32 ] , V_25 , V_26 ) ;
V_33 = F_19 ( V_26 ) ;
V_19 = F_15 ( V_2 , V_3 , V_15 , ( V_34 int ) V_26 ) ;
if ( V_19 ) {
F_20 ( & V_25 -> V_31 , L_2 , V_33 , V_19 ) ;
return V_19 ;
}
F_21 ( & V_25 -> V_31 , L_3 , V_33 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_24 * V_25 ,
T_3 V_26 )
{
int V_32 , V_3 , V_15 ;
int V_19 ;
V_32 = F_23 ( V_25 ) ;
if ( V_32 < 0 )
return V_32 ;
V_3 = ( V_32 * V_35 ) / 32 ;
V_15 = ( V_32 * V_35 ) % 32 ;
if ( V_26 < V_36 )
V_26 = V_36 ;
if ( V_26 > V_28 )
V_26 = V_28 ;
F_24 ( & V_2 -> V_37 ) ;
V_19 = F_18 ( V_2 , V_25 , V_26 , V_32 , V_3 , V_15 ) ;
F_25 ( & V_2 -> V_37 ) ;
return V_19 ;
}
int F_26 ( struct V_24 * V_25 , T_3 V_26 )
{
struct V_1 * V_2 = V_38 ;
int V_19 = 0 ;
F_27 () ;
if ( V_2 && V_2 -> V_39 )
V_19 = F_22 ( V_2 , V_25 , V_26 ) ;
F_21 ( & V_25 -> V_31 , L_4 , V_19 ) ;
return 0 ;
}
int F_23 ( struct V_24 * V_25 )
{
int V_40 ;
T_2 V_32 ;
V_40 = F_28 ( V_25 , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
F_29 ( V_25 , V_40 + V_43 , & V_32 ) ;
if ( ! ( V_32 & V_44 ) )
return - V_45 ;
V_32 &= ~ V_44 ;
if ( V_32 >= V_46 )
return - V_47 ;
return V_32 ;
}
static T_4 F_30 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_1 V_50 ;
V_50 = F_2 ( V_2 -> V_4 + V_7 ) ;
if ( ! ( V_50 & V_51 ) )
return V_52 ;
F_5 ( V_50 | V_51 , V_2 -> V_4 + V_7 ) ;
F_20 ( V_2 -> V_31 , L_5 , F_31 ( V_50 ) ) ;
return V_53 ;
}
static int F_32 ( struct V_24 * V_25 , const struct V_54 * V_32 )
{
struct V_55 * V_56 = ( void * ) V_32 -> V_57 ;
struct V_58 * V_31 = & V_25 -> V_31 ;
struct V_1 * V_2 ;
int V_19 ;
V_19 = F_33 ( V_25 ) ;
if ( V_19 < 0 ) {
F_34 ( & V_25 -> V_31 , L_6 ) ;
return V_19 ;
}
V_19 = F_35 ( V_25 , 1 << 0 , F_36 ( V_25 ) ) ;
if ( V_19 ) {
F_34 ( & V_25 -> V_31 , L_7 ) ;
return V_19 ;
}
V_2 = F_37 ( V_31 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_4 = F_38 ( V_25 ) [ 0 ] ;
V_2 -> V_48 = V_25 -> V_48 ;
F_39 ( & V_2 -> V_37 ) ;
F_9 ( V_2 ) ;
if ( V_56 && V_56 -> V_61 ) {
V_19 = V_56 -> V_61 ( V_2 ) ;
if ( V_19 )
F_20 ( V_31 , L_8 , V_19 ) ;
}
V_19 = F_40 ( V_31 , V_25 -> V_48 , F_30 ,
V_62 , F_36 ( V_25 ) , V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_39 = true ;
V_38 = V_2 ;
F_41 ( V_25 , V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned int V_63 , V_29 ;
int V_19 ;
F_7 ( V_2 , 0 , 0xffffffff ) ;
F_7 ( V_2 , 1 , 0xffffffff ) ;
F_4 ( V_2 , 0 , 0xffffffff ) ;
F_4 ( V_2 , 1 , 0xffffffff ) ;
F_4 ( V_2 , 2 , 0xffffffff ) ;
F_4 ( V_2 , 3 , 0xffffffff ) ;
V_19 = F_13 ( V_2 , V_20 ) ;
if ( V_19 )
return V_19 ;
for ( V_63 = 0 ; V_63 < V_46 ; V_63 ++ ) {
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
V_2 -> V_23 [ V_63 ] [ V_29 ] . V_26 = V_28 ;
}
return 0 ;
}
