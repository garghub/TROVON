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
switch ( V_15 & V_16 ) {
case V_17 :
case V_18 :
V_13 -> V_19 = V_15 & V_16 ;
break;
default:
F_6 ( V_2 -> V_20 , L_1 ) ;
return - V_21 ;
}
switch ( V_15 & V_22 ) {
case V_23 :
V_13 -> V_24 = 1 ;
break;
case V_25 :
V_13 -> V_24 = 0 ;
break;
default:
F_6 ( V_2 -> V_20 , L_2 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_7 * V_30 )
{
struct V_31 * V_32 = V_27 -> V_33 ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
int V_3 ;
V_36 = F_8 ( V_29 ) ;
V_37 = V_13 -> V_14 / V_36 ;
for ( V_35 = 0 ; V_35 < V_38 ; V_35 ++ ) {
if ( V_39 [ V_35 ] . V_37 == V_37 )
break;
}
if ( V_35 == V_38 ) {
F_6 ( V_2 -> V_20 , L_3 ) ;
return - V_21 ;
}
V_3 = F_9 ( V_2 , V_40 ) ;
V_3 &= ~ ( V_41 | V_42 ) ;
V_3 |= V_39 [ V_35 ] . V_14 ;
if ( V_13 -> V_24 )
V_3 |= V_43 ;
else
V_3 |= V_39 [ V_35 ] . V_44 ;
V_34 = F_10 ( V_2 , V_40 , V_3 ) ;
if ( V_34 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_34 ;
}
V_3 = F_9 ( V_2 , V_45 ) ;
V_3 &= ~ ( V_46 | V_47 ) ;
switch ( V_13 -> V_19 ) {
case V_17 :
V_3 |= V_48 | V_49 ;
break;
case V_18 :
V_3 |= V_50 | V_51 ;
break;
default:
F_6 ( V_2 -> V_20 , L_5 ) ;
return - V_21 ;
}
V_34 = F_10 ( V_2 , V_45 , V_3 ) ;
if ( V_34 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_34 ;
}
return V_34 ;
}
static int F_11 ( struct V_7 * V_30 , int V_52 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
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
int V_35 , V_34 ;
V_34 = F_16 ( V_2 , 8 , 8 , V_13 -> V_65 ) ;
if ( V_34 < 0 ) {
F_6 ( V_2 -> V_20 , L_6 , V_34 ) ;
return V_34 ;
}
V_34 = F_17 ( V_2 , V_54 , V_66 , 0 ) ;
if ( V_34 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_34 ;
}
V_34 = F_17 ( V_2 , V_67 ,
V_68 | V_69 , 0 ) ;
if ( V_34 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_34 ;
}
V_34 = F_18 ( V_2 , V_70 ,
F_19 ( V_70 ) ) ;
if ( V_34 < 0 ) {
F_6 ( V_2 -> V_20 , L_7 ) ;
return V_34 ;
}
for ( V_35 = 0 ; V_35 < F_19 ( V_71 ) ; V_35 ++ )
V_13 -> V_72 [ V_35 ] . V_73 = V_71 [ V_35 ] ;
V_34 = F_20 ( V_2 -> V_20 , F_19 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_21 ( F_19 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
if ( V_34 < 0 )
goto V_74;
return 0 ;
V_74:
F_22 ( F_19 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
return V_34 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
F_24 ( F_19 ( V_13 -> V_72 ) , V_13 -> V_72 ) ;
F_22 ( F_19 ( V_13 -> V_72 ) , V_13 -> V_72 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_3 , V_34 ;
V_3 = F_9 ( V_2 , V_75 ) | V_76 ;
if ( V_3 < 0 )
return V_3 ;
V_34 = F_10 ( V_2 , V_75 , V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
F_24 ( F_19 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_3 ;
F_21 ( F_19 ( V_13 -> V_72 ) ,
V_13 -> V_72 ) ;
F_27 ( 500 ) ;
F_28 ( V_2 ) ;
V_3 = F_9 ( V_2 , V_75 ) ;
V_3 &= ~ V_76 ;
return F_10 ( V_2 , V_75 , V_3 ) ;
}
static int F_29 ( struct V_77 * V_77 ,
const struct V_78 * V_79 )
{
struct V_12 * V_13 ;
int V_34 ;
V_34 = F_30 ( V_77 , V_6 ) ;
if ( V_34 < 0 ) {
F_6 ( & V_77 -> V_20 , L_8 ,
V_77 -> V_80 ) ;
return V_34 ;
}
if ( ( V_34 & 0xF0 ) != 0xC0 ) {
F_6 ( & V_77 -> V_20 , L_9 ,
V_77 -> V_80 ) ;
return - V_81 ;
}
F_31 ( & V_77 -> V_20 , L_10 ,
V_77 -> V_80 ) ;
F_31 ( & V_77 -> V_20 , L_11 , V_34 & 0xF ) ;
V_13 = F_32 ( & V_77 -> V_20 , sizeof( struct V_12 ) ,
V_82 ) ;
if ( ! V_13 ) {
F_6 ( & V_77 -> V_20 , L_12 ) ;
return - V_83 ;
}
F_33 ( V_77 , V_13 ) ;
V_13 -> V_65 = V_84 ;
V_34 = F_34 ( & V_77 -> V_20 ,
& V_85 , & V_86 , 1 ) ;
return V_34 ;
}
static int F_35 ( struct V_77 * V_77 )
{
F_36 ( & V_77 -> V_20 ) ;
return 0 ;
}
static int T_1 F_37 ( void )
{
return F_38 ( & V_87 ) ;
}
static void T_2 F_39 ( void )
{
F_40 ( & V_87 ) ;
}
