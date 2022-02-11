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
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_31 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
int V_3 ;
V_33 = F_8 ( V_29 ) ;
V_34 = V_13 -> V_14 / V_33 ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
if ( V_36 [ V_32 ] . V_34 == V_34 )
break;
}
if ( V_32 == V_35 ) {
F_6 ( V_2 -> V_20 , L_3 ) ;
return - V_21 ;
}
V_3 = F_9 ( V_2 , V_37 ) ;
V_3 &= ~ ( V_38 | V_39 ) ;
V_3 |= V_36 [ V_32 ] . V_14 ;
if ( V_13 -> V_24 )
V_3 |= V_40 ;
else
V_3 |= V_36 [ V_32 ] . V_41 ;
V_31 = F_10 ( V_2 , V_37 , V_3 ) ;
if ( V_31 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_31 ;
}
V_3 = F_9 ( V_2 , V_42 ) ;
V_3 &= ~ ( V_43 | V_44 ) ;
switch ( V_13 -> V_19 ) {
case V_17 :
V_3 |= V_45 | V_46 ;
break;
case V_18 :
V_3 |= V_47 | V_48 ;
break;
default:
F_6 ( V_2 -> V_20 , L_5 ) ;
return - V_21 ;
}
V_31 = F_10 ( V_2 , V_42 , V_3 ) ;
if ( V_31 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_31 ;
}
return V_31 ;
}
static int F_11 ( struct V_7 * V_30 , int V_49 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_50 ;
V_50 = F_9 ( V_2 , V_51 ) ;
if ( V_49 )
V_50 |= V_52 | V_53 ;
else {
V_50 &= ~ ( V_52 | V_53 ) ;
V_50 |= V_13 -> V_54 ;
}
return F_10 ( V_2 , V_51 , V_50 ) ;
}
static int F_12 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_59 = ! V_58 -> V_60 . integer . V_60 [ 0 ] ;
int V_61 = ! V_58 -> V_60 . integer . V_60 [ 1 ] ;
V_13 -> V_54 = ( V_59 ? V_52 : 0 ) |
( V_61 ? V_53 : 0 ) ;
return F_14 ( V_56 , V_58 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_32 , V_31 ;
V_31 = F_16 ( V_2 , 8 , 8 , V_13 -> V_62 ) ;
if ( V_31 < 0 ) {
F_6 ( V_2 -> V_20 , L_6 , V_31 ) ;
return V_31 ;
}
V_31 = F_17 ( V_2 , V_51 , V_63 , 0 ) ;
if ( V_31 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_31 ;
}
V_31 = F_17 ( V_2 , V_64 ,
V_65 | V_66 , 0 ) ;
if ( V_31 < 0 ) {
F_6 ( V_2 -> V_20 , L_4 ) ;
return V_31 ;
}
V_31 = F_18 ( V_2 , V_67 ,
F_19 ( V_67 ) ) ;
if ( V_31 < 0 ) {
F_6 ( V_2 -> V_20 , L_7 ) ;
return V_31 ;
}
for ( V_32 = 0 ; V_32 < F_19 ( V_68 ) ; V_32 ++ )
V_13 -> V_69 [ V_32 ] . V_70 = V_68 [ V_32 ] ;
V_31 = F_20 ( V_2 -> V_20 , F_19 ( V_13 -> V_69 ) ,
V_13 -> V_69 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_21 ( F_19 ( V_13 -> V_69 ) ,
V_13 -> V_69 ) ;
if ( V_31 < 0 )
goto V_71;
return 0 ;
V_71:
F_22 ( F_19 ( V_13 -> V_69 ) ,
V_13 -> V_69 ) ;
return V_31 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
F_24 ( F_19 ( V_13 -> V_69 ) , V_13 -> V_69 ) ;
F_22 ( F_19 ( V_13 -> V_69 ) , V_13 -> V_69 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_3 , V_31 ;
V_3 = F_9 ( V_2 , V_72 ) | V_73 ;
if ( V_3 < 0 )
return V_3 ;
V_31 = F_10 ( V_2 , V_72 , V_3 ) ;
if ( V_31 < 0 )
return V_31 ;
F_24 ( F_19 ( V_13 -> V_69 ) ,
V_13 -> V_69 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_4 ( V_2 ) ;
int V_3 , V_31 ;
V_31 = F_21 ( F_19 ( V_13 -> V_69 ) ,
V_13 -> V_69 ) ;
if ( V_31 != 0 )
return V_31 ;
F_27 ( 500 ) ;
F_28 ( V_2 ) ;
V_3 = F_9 ( V_2 , V_72 ) ;
V_3 &= ~ V_73 ;
return F_10 ( V_2 , V_72 , V_3 ) ;
}
static int F_29 ( struct V_74 * V_74 ,
const struct V_75 * V_76 )
{
struct V_12 * V_13 ;
int V_31 ;
V_31 = F_30 ( V_74 , V_6 ) ;
if ( V_31 < 0 ) {
F_6 ( & V_74 -> V_20 , L_8 ,
V_74 -> V_77 ) ;
return V_31 ;
}
if ( ( V_31 & 0xF0 ) != 0xC0 ) {
F_6 ( & V_74 -> V_20 , L_9 ,
V_74 -> V_77 ) ;
return - V_78 ;
}
F_31 ( & V_74 -> V_20 , L_10 ,
V_74 -> V_77 ) ;
F_31 ( & V_74 -> V_20 , L_11 , V_31 & 0xF ) ;
V_13 = F_32 ( & V_74 -> V_20 , sizeof( struct V_12 ) ,
V_79 ) ;
if ( ! V_13 ) {
F_6 ( & V_74 -> V_20 , L_12 ) ;
return - V_80 ;
}
F_33 ( V_74 , V_13 ) ;
V_13 -> V_62 = V_81 ;
V_31 = F_34 ( & V_74 -> V_20 ,
& V_82 , & V_83 , 1 ) ;
return V_31 ;
}
static int F_35 ( struct V_74 * V_74 )
{
F_36 ( & V_74 -> V_20 ) ;
return 0 ;
}
static int T_1 F_37 ( void )
{
return F_38 ( & V_84 ) ;
}
static void T_2 F_39 ( void )
{
F_40 ( & V_84 ) ;
}
