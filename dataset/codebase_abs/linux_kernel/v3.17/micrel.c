static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & V_5 ) {
V_3 = F_2 ( V_2 , V_6 ) ;
V_3 |= V_7 ;
return F_3 ( V_2 , V_6 , V_3 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_8 , T_2 V_9 )
{
F_3 ( V_2 , V_10 , V_11 | V_8 ) ;
return F_3 ( V_2 , V_12 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_8 )
{
F_3 ( V_2 , V_10 , V_8 ) ;
return F_2 ( V_2 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_2 ( V_2 , V_15 ) ;
return ( V_14 < 0 ) ? V_14 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = ( V_17 == V_2 -> V_18 ) ?
V_19 : 0 ;
return F_3 ( V_2 , V_15 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_16 , V_14 ;
V_16 = F_2 ( V_2 , V_6 ) ;
V_16 &= ~ V_20 ;
F_3 ( V_2 , V_6 , V_16 ) ;
V_14 = F_7 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_16 , V_14 ;
V_16 = F_2 ( V_2 , V_6 ) ;
V_16 &= ~ V_21 ;
F_3 ( V_2 , V_6 , V_16 ) ;
V_14 = F_7 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_16 , V_14 ;
V_16 = F_2 ( V_2 , V_6 ) ;
V_16 &= ~ V_22 ;
F_3 ( V_2 , V_6 , V_16 ) ;
V_14 = F_7 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_25 * V_26 = & V_2 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_28 ;
int V_14 , V_16 ;
T_1 V_9 ;
if ( ! V_28 && V_26 -> V_29 -> V_28 )
V_28 = V_26 -> V_29 -> V_28 ;
if ( F_12 ( V_28 , L_1 , & V_9 ) )
return 0 ;
V_16 = F_2 ( V_2 , V_23 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 &= ~ ( 3 << V_24 ) ;
V_16 |= V_9 << V_24 ;
V_14 = F_3 ( V_2 , V_23 , V_16 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , 0x1e , 14 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
const T_2 V_9 = V_30 | V_31 ;
int V_14 ;
V_14 = F_11 ( V_2 , 0x1f , 4 ) ;
if ( V_14 )
F_16 ( & V_2 -> V_26 , L_2 ) ;
F_3 ( V_2 , V_32 , V_9 ) ;
V_14 = F_1 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_11 ( V_2 , 0x1f , 4 ) ;
if ( V_14 )
F_16 ( & V_2 -> V_26 , L_2 ) ;
V_14 = F_1 ( V_2 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_2 V_23 ,
char * V_33 , char * V_34 ,
char * V_35 , char * V_36 )
{
int V_37 = - 1 ;
int V_38 = - 2 ;
int V_39 = - 3 ;
int V_40 = - 4 ;
int V_41 ;
int V_42 = 0 ;
if ( ! F_12 ( V_28 , V_33 , & V_37 ) )
V_42 ++ ;
if ( ! F_12 ( V_28 , V_34 , & V_38 ) )
V_42 ++ ;
if ( ! F_12 ( V_28 , V_35 , & V_39 ) )
V_42 ++ ;
if ( ! F_12 ( V_28 , V_36 , & V_40 ) )
V_42 ++ ;
if ( ! V_42 )
return 0 ;
if ( V_42 < 4 )
V_41 = F_5 ( V_2 , V_23 ) ;
else
V_41 = 0 ;
if ( V_37 != - 1 )
V_41 = ( ( V_41 & 0xfff0 ) | ( ( V_37 / V_43 ) & 0xf ) << 0 ) ;
if ( V_38 != - 2 )
V_41 = ( ( V_41 & 0xff0f ) | ( ( V_38 / V_43 ) & 0xf ) << 4 ) ;
if ( V_39 != - 3 )
V_41 = ( ( V_41 & 0xf0ff ) | ( ( V_39 / V_43 ) & 0xf ) << 8 ) ;
if ( V_40 != - 4 )
V_41 = ( ( V_41 & 0x0fff ) | ( ( V_40 / V_43 ) & 0xf ) << 12 ) ;
return F_4 ( V_2 , V_23 , V_41 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_28 ;
if ( ! V_28 && V_26 -> V_29 -> V_28 )
V_28 = V_26 -> V_29 -> V_28 ;
if ( V_28 ) {
F_18 ( V_2 , V_28 ,
V_44 ,
L_3 , L_4 ,
L_5 , L_6 ) ;
F_18 ( V_2 , V_28 ,
V_45 ,
L_7 , L_8 ,
L_9 , L_10 ) ;
F_18 ( V_2 , V_28 ,
V_46 ,
L_11 , L_12 ,
L_13 , L_14 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_47 , T_1 V_48 , T_1 V_8 , T_2 V_9 )
{
F_3 ( V_2 , V_49 , V_48 ) ;
F_3 ( V_2 , V_50 , V_8 ) ;
F_3 ( V_2 , V_49 , ( V_47 << 14 ) | V_48 ) ;
return F_3 ( V_2 , V_50 , V_9 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_47 , T_1 V_48 , T_1 V_8 )
{
F_3 ( V_2 , V_49 , V_48 ) ;
F_3 ( V_2 , V_50 , V_8 ) ;
F_3 ( V_2 , V_49 , ( V_47 << 14 ) | V_48 ) ;
return F_2 ( V_2 , V_50 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
T_2 V_23 , T_4 V_51 ,
char * V_52 [] , T_3 V_53 )
{
int V_9 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_42 = 0 ;
T_2 V_54 ;
T_2 V_55 ;
T_2 V_41 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_53 ; V_56 ++ )
if ( ! F_12 ( V_28 , V_52 [ V_56 ] , V_9 + V_56 ) )
V_42 ++ ;
if ( ! V_42 )
return 0 ;
if ( V_42 < V_53 )
V_41 = F_21 ( V_2 , V_57 , 2 , V_23 ) ;
else
V_41 = 0 ;
V_55 = ( V_51 == 4 ) ? 0xf : 0x1f ;
for ( V_56 = 0 ; V_56 < V_53 ; V_56 ++ )
if ( V_9 [ V_56 ] != - ( V_56 + 1 ) ) {
V_54 = 0xffff ;
V_54 ^= V_55 << ( V_51 * V_56 ) ;
V_41 = ( V_41 & V_54 ) |
( ( ( V_9 [ V_56 ] / V_58 ) & V_55 )
<< ( V_51 * V_56 ) ) ;
}
return F_20 ( V_2 , V_57 , 2 , V_23 , V_41 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_26 ;
struct V_27 * V_28 = V_26 -> V_28 ;
char * V_59 [ 2 ] = { L_6 , L_4 } ;
char * V_60 [ 4 ] = {
L_7 , L_8 ,
L_9 , L_10
} ;
char * V_61 [ 4 ] = {
L_11 , L_12 ,
L_13 , L_14
} ;
char * V_62 [ 2 ] = { L_3 , L_5 } ;
if ( ! V_28 && V_26 -> V_29 -> V_28 )
V_28 = V_26 -> V_29 -> V_28 ;
if ( V_28 ) {
F_22 ( V_2 , V_28 ,
V_63 , 5 ,
V_59 , 2 ) ;
F_22 ( V_2 , V_28 ,
V_64 , 4 ,
V_62 , 2 ) ;
F_22 ( V_2 , V_28 ,
V_65 , 4 ,
V_60 , 4 ) ;
F_22 ( V_2 , V_28 ,
V_66 , 4 ,
V_61 , 4 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_67 ) ;
V_3 = F_2 ( V_2 , V_67 ) ;
if ( V_3 & V_68 )
V_2 -> V_69 = V_70 ;
else
V_2 -> V_69 = V_71 ;
if ( V_3 & V_72 )
V_2 -> V_73 = V_74 ;
else
V_2 -> V_73 = V_75 ;
V_2 -> V_76 = 1 ;
V_2 -> V_77 = V_2 -> V_78 = 0 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , int V_79 , int V_80 ,
int V_8 )
{
return - 1 ;
}
static void
F_27 ( struct V_1 * V_2 , int V_79 , int V_80 ,
int V_8 , T_1 V_9 )
{
}
static int T_5 F_28 ( void )
{
return F_29 ( V_81 ,
F_30 ( V_81 ) ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( V_81 ,
F_30 ( V_81 ) ) ;
}
