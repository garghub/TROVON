static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ( V_3 < V_4 ) || ( V_3 > V_5 ) )
return 1 ;
return V_3 == V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
V_13 -> V_14 = V_10 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 ,
unsigned int V_15 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_16 = 0 ;
switch ( V_15 & V_17 ) {
case V_18 :
case V_19 :
V_13 -> V_20 = V_15 & V_17 ;
break;
default:
F_6 ( V_2 -> V_21 , L_1 ) ;
V_16 = - V_22 ;
}
switch ( V_15 & V_23 ) {
case V_24 :
V_13 -> V_25 = 1 ;
break;
case V_26 :
V_13 -> V_25 = 0 ;
break;
default:
V_16 = - V_22 ;
}
return V_16 ;
}
static int F_7 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_7 * V_31 )
{
struct V_32 * V_33 = V_28 -> V_34 ;
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_16 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
int V_3 ;
V_36 = F_8 ( V_30 ) ;
V_37 = V_13 -> V_14 / V_36 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
if ( V_39 [ V_35 ] . V_37 == V_37 )
break;
}
if ( V_35 == V_38 ) {
F_6 ( V_2 -> V_21 , L_2 ) ;
return - V_22 ;
}
V_3 = F_9 ( V_2 , V_40 ) ;
V_3 &= ~ ( V_41 | V_42 ) ;
V_3 |= V_39 [ V_35 ] . V_14 ;
if ( V_13 -> V_25 )
V_3 |= V_43 ;
else
V_3 |= V_39 [ V_35 ] . V_44 ;
V_16 = F_10 ( V_2 , V_40 , V_3 ) ;
if ( V_16 < 0 ) {
F_6 ( V_2 -> V_21 , L_3 ) ;
return V_16 ;
}
V_3 = F_9 ( V_2 , V_45 ) ;
V_3 &= ~ ( V_46 | V_47 ) ;
switch ( V_13 -> V_20 ) {
case V_18 :
V_3 |= V_48 | V_49 ;
break;
case V_19 :
V_3 |= V_50 | V_51 ;
break;
default:
F_6 ( V_2 -> V_21 , L_4 ) ;
return - V_22 ;
}
V_16 = F_10 ( V_2 , V_45 , V_3 ) ;
if ( V_16 < 0 ) {
F_6 ( V_2 -> V_21 , L_3 ) ;
return V_16 ;
}
return V_16 ;
}
static int F_11 ( struct V_7 * V_31 , int V_52 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_53 ;
V_53 = F_9 ( V_2 , V_54 ) ;
if ( V_52 )
V_53 |= V_55 | V_56 ;
else {
V_53 &= ~ ( V_55 | V_56 ) ;
V_53 |= V_13 -> V_57 ;
}
return F_10 ( V_2 , V_54 , V_53 ) ;
}
static int F_12 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_13 ( V_59 ) ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_62 = ! V_61 -> V_63 . integer . V_63 [ 0 ] ;
int V_64 = ! V_61 -> V_63 . integer . V_63 [ 1 ] ;
V_13 -> V_57 = ( V_62 ? V_55 : 0 ) |
( V_64 ? V_56 : 0 ) ;
return F_14 ( V_59 , V_61 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_35 , V_16 ;
V_2 -> V_65 = V_13 -> V_65 ;
V_16 = F_16 ( V_2 , 8 , 8 , V_13 -> V_66 ) ;
if ( V_16 < 0 ) {
F_6 ( V_2 -> V_21 , L_5 , V_16 ) ;
return V_16 ;
}
V_16 = F_17 ( V_2 , V_54 , V_67 , 0 ) ;
if ( V_16 < 0 ) {
F_6 ( V_2 -> V_21 , L_3 ) ;
return V_16 ;
}
V_16 = F_17 ( V_2 , V_68 ,
V_69 | V_70 , 0 ) ;
if ( V_16 < 0 ) {
F_6 ( V_2 -> V_21 , L_3 ) ;
return V_16 ;
}
V_16 = F_18 ( V_2 , V_71 ,
F_19 ( V_71 ) ) ;
if ( V_16 < 0 ) {
F_6 ( V_2 -> V_21 , L_6 ) ;
return V_16 ;
}
for ( V_35 = 0 ; V_35 < F_19 ( V_72 ) ; V_35 ++ )
V_13 -> V_73 [ V_35 ] . V_74 = V_72 [ V_35 ] ;
V_16 = F_20 ( V_2 -> V_21 , F_19 ( V_13 -> V_73 ) ,
V_13 -> V_73 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_21 ( F_19 ( V_13 -> V_73 ) ,
V_13 -> V_73 ) ;
if ( V_16 < 0 )
goto V_75;
return 0 ;
V_75:
F_22 ( F_19 ( V_13 -> V_73 ) ,
V_13 -> V_73 ) ;
return V_16 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
F_24 ( F_19 ( V_13 -> V_73 ) , V_13 -> V_73 ) ;
F_22 ( F_19 ( V_13 -> V_73 ) , V_13 -> V_73 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_76 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_3 , V_16 ;
V_3 = F_9 ( V_2 , V_77 ) | V_78 ;
if ( V_3 < 0 )
return V_3 ;
V_16 = F_10 ( V_2 , V_77 , V_3 ) ;
if ( V_16 < 0 )
return V_16 ;
F_24 ( F_19 ( V_13 -> V_73 ) ,
V_13 -> V_73 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
struct V_79 * V_79 = V_2 -> V_65 ;
int V_3 ;
F_21 ( F_19 ( V_13 -> V_73 ) ,
V_13 -> V_73 ) ;
F_27 ( 500 ) ;
for ( V_3 = V_4 ; V_3 <= V_5 ; V_3 ++ ) {
T_2 V_80 = F_9 ( V_2 , V_3 ) ;
if ( F_28 ( V_79 , V_3 , V_80 ) ) {
F_6 ( V_2 -> V_21 , L_3 ) ;
return - V_81 ;
}
}
V_3 = F_9 ( V_2 , V_77 ) ;
V_3 &= ~ V_78 ;
return F_10 ( V_2 , V_77 , V_3 ) ;
}
static int F_29 ( struct V_79 * V_79 ,
const struct V_82 * V_83 )
{
struct V_12 * V_13 ;
int V_16 ;
V_16 = F_30 ( V_79 , V_6 ) ;
if ( V_16 < 0 ) {
F_6 ( & V_79 -> V_21 , L_7 ,
V_79 -> V_84 ) ;
return V_16 ;
}
if ( ( V_16 & 0xF0 ) != 0xC0 ) {
F_6 ( & V_79 -> V_21 , L_8 ,
V_79 -> V_84 ) ;
return - V_85 ;
}
F_31 ( & V_79 -> V_21 , L_9 ,
V_79 -> V_84 ) ;
F_31 ( & V_79 -> V_21 , L_10 , V_16 & 0xF ) ;
V_13 = F_32 ( sizeof( struct V_12 ) , V_86 ) ;
if ( ! V_13 ) {
F_6 ( & V_79 -> V_21 , L_11 ) ;
return - V_87 ;
}
F_33 ( V_79 , V_13 ) ;
V_13 -> V_65 = V_79 ;
V_13 -> V_66 = V_88 ;
V_16 = F_34 ( & V_79 -> V_21 ,
& V_89 , & V_90 , 1 ) ;
if ( V_16 < 0 )
F_35 ( V_13 ) ;
return V_16 ;
}
static int F_36 ( struct V_79 * V_79 )
{
F_37 ( & V_79 -> V_21 ) ;
F_35 ( F_38 ( V_79 ) ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_91 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_91 ) ;
}
