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
F_5 ( F_14 ( V_13 ) | V_14 , V_2 -> V_4 + V_15 ) ;
return F_11 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 , int V_16 , int V_17 )
{
int V_18 ;
T_1 V_19 ;
int V_20 ;
V_19 = F_1 ( V_2 , V_3 ) ;
V_18 = ( V_19 >> V_16 ) & 3 ;
if ( V_18 == V_17 )
return 0 ;
F_4 ( V_2 , V_3 , ( V_19 & ~ ( 3 << V_16 ) ) | ( V_17 << V_16 ) ) ;
V_20 = F_13 ( V_2 , V_21 ) ;
if ( V_20 )
return V_20 ;
V_19 = F_1 ( V_2 , V_3 ) ;
V_18 = ( V_19 >> V_16 ) & 3 ;
if ( V_18 != V_17 )
return - V_22 ;
return 0 ;
}
static T_3 F_16 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
T_3 V_27 )
{
T_3 V_28 = V_29 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( V_24 [ V_30 ] . V_26 == V_26 || ! V_24 [ V_30 ] . V_26 )
break;
}
if ( V_30 < V_31 ) {
V_24 [ V_30 ] . V_26 = V_26 ;
V_24 [ V_30 ] . V_27 = V_27 ;
} else {
F_17 ( & V_26 -> V_32 , L_1 ) ;
V_28 = V_27 ;
}
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( V_24 [ V_30 ] . V_27 < V_28 )
V_28 = V_24 [ V_30 ] . V_27 ;
}
return V_28 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_25 * V_26 ,
T_3 V_27 , int V_33 , int V_3 , int V_16 )
{
const char * V_34 ;
int V_20 ;
V_27 = F_16 ( V_2 -> V_24 [ V_33 ] , V_26 , V_27 ) ;
V_34 = F_19 ( V_27 ) ;
V_20 = F_15 ( V_2 , V_3 , V_16 , ( V_35 int ) V_27 ) ;
if ( V_20 ) {
F_20 ( & V_26 -> V_32 , L_2 , V_34 , V_20 ) ;
return V_20 ;
}
F_21 ( & V_26 -> V_32 , L_3 , V_34 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_25 * V_26 ,
T_3 V_27 )
{
int V_33 , V_3 , V_16 ;
int V_20 ;
V_33 = F_23 ( V_26 ) ;
if ( V_33 < 0 )
return V_33 ;
V_3 = ( V_33 * V_36 ) / 32 ;
V_16 = ( V_33 * V_36 ) % 32 ;
if ( V_27 < V_37 )
V_27 = V_37 ;
if ( V_27 > V_29 )
V_27 = V_29 ;
F_24 ( & V_2 -> V_38 ) ;
V_20 = F_18 ( V_2 , V_26 , V_27 , V_33 , V_3 , V_16 ) ;
F_25 ( & V_2 -> V_38 ) ;
return V_20 ;
}
int F_26 ( struct V_25 * V_26 , T_3 V_27 )
{
struct V_1 * V_2 = V_39 ;
int V_20 = 0 ;
F_27 () ;
if ( V_2 && V_2 -> V_40 )
V_20 = F_22 ( V_2 , V_26 , V_27 ) ;
F_21 ( & V_26 -> V_32 , L_4 , V_20 ) ;
return 0 ;
}
T_3 F_28 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_39 ;
int V_33 , V_3 , V_16 ;
T_1 V_19 ;
if ( ! V_2 || ! V_2 -> V_40 )
return V_41 ;
V_33 = F_23 ( V_26 ) ;
if ( V_33 < 0 )
return V_41 ;
V_3 = ( V_33 * V_36 ) / 32 ;
V_16 = ( V_33 * V_36 ) % 32 ;
V_19 = F_1 ( V_2 , V_3 ) ;
return ( V_35 T_3 ) ( ( V_19 >> V_16 ) & 3 ) ;
}
void F_29 ( void )
{
struct V_1 * V_2 = V_39 ;
T_1 V_13 = V_42 |
F_14 ( V_21 ) |
V_43 |
V_44 |
V_45 ;
F_5 ( V_13 , V_2 -> V_4 + V_15 ) ;
F_11 ( V_2 ) ;
}
int F_23 ( struct V_25 * V_26 )
{
int V_46 ;
T_2 V_33 ;
V_46 = F_30 ( V_26 , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
F_31 ( V_26 , V_46 + V_49 , & V_33 ) ;
if ( ! ( V_33 & V_50 ) )
return - V_51 ;
V_33 &= ~ V_50 ;
if ( V_33 >= V_52 )
return - V_53 ;
return V_33 ;
}
static T_4 F_32 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
T_1 V_56 ;
V_56 = F_2 ( V_2 -> V_4 + V_7 ) ;
if ( ! ( V_56 & V_57 ) )
return V_58 ;
F_5 ( V_56 | V_57 , V_2 -> V_4 + V_7 ) ;
F_20 ( V_2 -> V_32 , L_5 , F_33 ( V_56 ) ) ;
return V_59 ;
}
static int F_34 ( struct V_25 * V_26 , const struct V_60 * V_33 )
{
struct V_61 * V_62 = ( void * ) V_33 -> V_63 ;
struct V_64 * V_32 = & V_26 -> V_32 ;
struct V_1 * V_2 ;
int V_20 ;
V_20 = F_35 ( V_26 ) ;
if ( V_20 < 0 ) {
F_36 ( & V_26 -> V_32 , L_6 ) ;
return V_20 ;
}
V_20 = F_37 ( V_26 , 1 << 0 , F_38 ( V_26 ) ) ;
if ( V_20 ) {
F_36 ( & V_26 -> V_32 , L_7 ) ;
return V_20 ;
}
V_2 = F_39 ( V_32 , sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 )
return - V_66 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_4 = F_40 ( V_26 ) [ 0 ] ;
V_2 -> V_54 = V_26 -> V_54 ;
F_41 ( & V_2 -> V_38 ) ;
F_9 ( V_2 ) ;
if ( V_62 && V_62 -> V_67 ) {
V_20 = V_62 -> V_67 ( V_2 ) ;
if ( V_20 )
F_20 ( V_32 , L_8 , V_20 ) ;
}
V_20 = F_42 ( V_32 , V_26 -> V_54 , F_32 ,
V_68 , F_38 ( V_26 ) , V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_40 = true ;
V_39 = V_2 ;
F_43 ( V_26 , V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , const T_1 * V_69 )
{
unsigned int V_70 , V_30 ;
int V_20 ;
F_7 ( V_2 , 0 , 0xffffffff ) ;
F_7 ( V_2 , 1 , 0xffffffff ) ;
F_4 ( V_2 , 0 , V_69 [ 0 ] ) ;
F_4 ( V_2 , 1 , V_69 [ 1 ] ) ;
F_4 ( V_2 , 2 , V_69 [ 2 ] ) ;
F_4 ( V_2 , 3 , V_69 [ 3 ] ) ;
V_20 = F_13 ( V_2 , V_21 ) ;
if ( V_20 )
return V_20 ;
for ( V_70 = 0 ; V_70 < V_52 ; V_70 ++ ) {
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_2 -> V_24 [ V_70 ] [ V_30 ] . V_27 = V_29 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
static const T_1 V_69 [] = {
0xf00fffff ,
0xffffffff ,
0xffffffff ,
0xffffffff ,
} ;
return F_44 ( V_2 , V_69 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
static const T_1 V_69 [] = {
0xffffffff ,
0xffffffff ,
0xffffffff ,
0xffffffff ,
} ;
return F_44 ( V_2 , V_69 ) ;
}
