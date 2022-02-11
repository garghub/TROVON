static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & ( V_5 | V_6 ) ) {
V_3 = F_2 ( V_2 , V_7 ) ;
if ( V_2 -> V_4 & V_5 )
V_3 |= V_8 ;
else
V_3 &= ~ V_8 ;
return F_3 ( V_2 , V_7 , V_3 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_9 , T_2 V_10 )
{
F_3 ( V_2 , V_11 , V_12 | V_9 ) ;
return F_3 ( V_2 , V_13 , V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_9 )
{
F_3 ( V_2 , V_11 , V_9 ) ;
return F_2 ( V_2 , V_14 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_2 ( V_2 , V_16 ) ;
return ( V_15 < 0 ) ? V_15 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = ( V_18 == V_2 -> V_19 ) ?
V_20 : 0 ;
return F_3 ( V_2 , V_16 , V_17 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_17 , V_15 ;
V_17 = F_2 ( V_2 , V_7 ) ;
V_17 &= ~ V_21 ;
F_3 ( V_2 , V_7 , V_17 ) ;
V_15 = F_7 ( V_2 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_17 , V_15 ;
V_17 = F_2 ( V_2 , V_7 ) ;
V_17 &= ~ V_22 ;
F_3 ( V_2 , V_7 , V_17 ) ;
V_15 = F_7 ( V_2 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_17 , V_15 ;
V_17 = F_2 ( V_2 , V_7 ) ;
V_17 &= ~ V_23 ;
F_3 ( V_2 , V_7 , V_17 ) ;
V_15 = F_7 ( V_2 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_24 , unsigned int V_25 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_28 * V_29 = V_27 -> V_29 ;
int V_15 , V_17 ;
T_1 V_10 ;
if ( ! V_29 && V_27 -> V_30 -> V_29 )
V_29 = V_27 -> V_30 -> V_29 ;
if ( F_12 ( V_29 , L_1 , & V_10 ) )
return 0 ;
V_17 = F_2 ( V_2 , V_24 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 &= ~ ( 3 << V_25 ) ;
V_17 |= V_10 << V_25 ;
V_15 = F_3 ( V_2 , V_24 , V_17 ) ;
return V_15 < 0 ? V_15 : 0 ;
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
const T_2 V_10 = V_31 | V_32 ;
int V_15 ;
V_15 = F_11 ( V_2 , 0x1f , 4 ) ;
if ( V_15 )
F_16 ( & V_2 -> V_27 , L_2 ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_3 ( V_2 , V_33 , V_10 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_11 ( V_2 , 0x1f , 4 ) ;
if ( V_15 )
F_16 ( & V_2 -> V_27 , L_2 ) ;
V_15 = F_1 ( V_2 ) ;
return V_15 < 0 ? V_15 : 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_28 * V_29 , T_2 V_24 ,
char * V_34 , char * V_35 ,
char * V_36 , char * V_37 )
{
int V_38 = - 1 ;
int V_39 = - 2 ;
int V_40 = - 3 ;
int V_41 = - 4 ;
int V_42 ;
int V_43 = 0 ;
if ( ! F_12 ( V_29 , V_34 , & V_38 ) )
V_43 ++ ;
if ( ! F_12 ( V_29 , V_35 , & V_39 ) )
V_43 ++ ;
if ( ! F_12 ( V_29 , V_36 , & V_40 ) )
V_43 ++ ;
if ( ! F_12 ( V_29 , V_37 , & V_41 ) )
V_43 ++ ;
if ( ! V_43 )
return 0 ;
if ( V_43 < 4 )
V_42 = F_5 ( V_2 , V_24 ) ;
else
V_42 = 0 ;
if ( V_38 != - 1 )
V_42 = ( ( V_42 & 0xfff0 ) | ( ( V_38 / V_44 ) & 0xf ) << 0 ) ;
if ( V_39 != - 2 )
V_42 = ( ( V_42 & 0xff0f ) | ( ( V_39 / V_44 ) & 0xf ) << 4 ) ;
if ( V_40 != - 3 )
V_42 = ( ( V_42 & 0xf0ff ) | ( ( V_40 / V_44 ) & 0xf ) << 8 ) ;
if ( V_41 != - 4 )
V_42 = ( ( V_42 & 0x0fff ) | ( ( V_41 / V_44 ) & 0xf ) << 12 ) ;
return F_4 ( V_2 , V_24 , V_42 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_28 * V_29 = V_27 -> V_29 ;
if ( ! V_29 && V_27 -> V_30 -> V_29 )
V_29 = V_27 -> V_30 -> V_29 ;
if ( V_29 ) {
F_18 ( V_2 , V_29 ,
V_45 ,
L_3 , L_4 ,
L_5 , L_6 ) ;
F_18 ( V_2 , V_29 ,
V_46 ,
L_7 , L_8 ,
L_9 , L_10 ) ;
F_18 ( V_2 , V_29 ,
V_47 ,
L_11 , L_12 ,
L_13 , L_14 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_3 V_48 , T_1 V_49 , T_1 V_9 , T_2 V_10 )
{
F_3 ( V_2 , V_50 , V_49 ) ;
F_3 ( V_2 , V_51 , V_9 ) ;
F_3 ( V_2 , V_50 , ( V_48 << 14 ) | V_49 ) ;
return F_3 ( V_2 , V_51 , V_10 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_48 , T_1 V_49 , T_1 V_9 )
{
F_3 ( V_2 , V_50 , V_49 ) ;
F_3 ( V_2 , V_51 , V_9 ) ;
F_3 ( V_2 , V_50 , ( V_48 << 14 ) | V_49 ) ;
return F_2 ( V_2 , V_51 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
T_2 V_24 , T_4 V_52 ,
char * V_53 [] , T_3 V_54 )
{
int V_10 [ 4 ] = { - 1 , - 2 , - 3 , - 4 } ;
int V_43 = 0 ;
T_2 V_55 ;
T_2 V_56 ;
T_2 V_42 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_54 ; V_57 ++ )
if ( ! F_12 ( V_29 , V_53 [ V_57 ] , V_10 + V_57 ) )
V_43 ++ ;
if ( ! V_43 )
return 0 ;
if ( V_43 < V_54 )
V_42 = F_21 ( V_2 , V_58 , 2 , V_24 ) ;
else
V_42 = 0 ;
V_56 = ( V_52 == 4 ) ? 0xf : 0x1f ;
for ( V_57 = 0 ; V_57 < V_54 ; V_57 ++ )
if ( V_10 [ V_57 ] != - ( V_57 + 1 ) ) {
V_55 = 0xffff ;
V_55 ^= V_56 << ( V_52 * V_57 ) ;
V_42 = ( V_42 & V_55 ) |
( ( ( V_10 [ V_57 ] / V_59 ) & V_56 )
<< ( V_52 * V_57 ) ) ;
}
return F_20 ( V_2 , V_58 , 2 , V_24 , V_42 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_28 * V_29 = V_27 -> V_29 ;
char * V_60 [ 2 ] = { L_6 , L_4 } ;
char * V_61 [ 4 ] = {
L_7 , L_8 ,
L_9 , L_10
} ;
char * V_62 [ 4 ] = {
L_11 , L_12 ,
L_13 , L_14
} ;
char * V_63 [ 2 ] = { L_3 , L_5 } ;
if ( ! V_29 && V_27 -> V_30 -> V_29 )
V_29 = V_27 -> V_30 -> V_29 ;
if ( V_29 ) {
F_22 ( V_2 , V_29 ,
V_64 , 5 ,
V_60 , 2 ) ;
F_22 ( V_2 , V_29 ,
V_65 , 4 ,
V_63 , 2 ) ;
F_22 ( V_2 , V_29 ,
V_66 , 4 ,
V_61 , 4 ) ;
F_22 ( V_2 , V_29 ,
V_67 , 4 ,
V_62 , 4 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_68 ) ;
V_3 = F_2 ( V_2 , V_68 ) ;
if ( V_3 & V_69 )
V_2 -> V_70 = V_71 ;
else
V_2 -> V_70 = V_72 ;
if ( V_3 & V_73 )
V_2 -> V_74 = V_75 ;
else
V_2 -> V_74 = V_76 ;
V_2 -> V_77 = 1 ;
V_2 -> V_78 = V_2 -> V_79 = 0 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , int V_80 , int V_81 ,
int V_9 )
{
return - 1 ;
}
static void
F_27 ( struct V_1 * V_2 , int V_80 , int V_81 ,
int V_9 , T_1 V_10 )
{
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_82 * V_82 ;
V_82 = F_29 ( & V_2 -> V_27 , L_15 ) ;
if ( ! F_30 ( V_82 ) ) {
unsigned long V_83 = F_31 ( V_82 ) ;
if ( V_83 > 24500000 && V_83 < 25500000 ) {
V_2 -> V_4 |= V_6 ;
} else if ( V_83 > 49500000 && V_83 < 50500000 ) {
V_2 -> V_4 |= V_5 ;
} else {
F_16 ( & V_2 -> V_27 , L_16 , V_83 ) ;
return - V_84 ;
}
}
return 0 ;
}
static int T_5 F_32 ( void )
{
return F_33 ( V_85 ,
F_34 ( V_85 ) ) ;
}
static void T_6 F_35 ( void )
{
F_36 ( V_85 ,
F_34 ( V_85 ) ) ;
}
