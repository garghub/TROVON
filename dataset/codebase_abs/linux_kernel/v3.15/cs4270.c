static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ( V_3 < V_4 ) || ( V_3 > V_5 ) )
return 1 ;
return V_3 == V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_10 , int V_11 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
V_15 -> V_16 = V_10 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 ,
unsigned int V_17 )
{
struct V_12 * V_13 = V_8 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
switch ( V_17 & V_18 ) {
case V_19 :
case V_20 :
V_15 -> V_21 = V_17 & V_18 ;
break;
default:
F_6 ( V_13 -> V_2 , L_1 ) ;
return - V_22 ;
}
switch ( V_17 & V_23 ) {
case V_24 :
V_15 -> V_25 = 1 ;
break;
case V_26 :
V_15 -> V_25 = 0 ;
break;
default:
F_6 ( V_13 -> V_2 , L_2 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_7 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
struct V_7 * V_31 )
{
struct V_12 * V_13 = V_31 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
unsigned int V_35 ;
int V_3 ;
V_34 = F_8 ( V_30 ) ;
V_35 = V_15 -> V_16 / V_34 ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
if ( V_37 [ V_33 ] . V_35 == V_35 )
break;
}
if ( V_33 == V_36 ) {
F_6 ( V_13 -> V_2 , L_3 ) ;
return - V_22 ;
}
V_3 = F_9 ( V_13 , V_38 ) ;
V_3 &= ~ ( V_39 | V_40 ) ;
V_3 |= V_37 [ V_33 ] . V_16 ;
if ( V_15 -> V_25 )
V_3 |= V_41 ;
else
V_3 |= V_37 [ V_33 ] . V_42 ;
V_32 = F_10 ( V_13 , V_38 , V_3 ) ;
if ( V_32 < 0 ) {
F_6 ( V_13 -> V_2 , L_4 ) ;
return V_32 ;
}
V_3 = F_9 ( V_13 , V_43 ) ;
V_3 &= ~ ( V_44 | V_45 ) ;
switch ( V_15 -> V_21 ) {
case V_19 :
V_3 |= V_46 | V_47 ;
break;
case V_20 :
V_3 |= V_48 | V_49 ;
break;
default:
F_6 ( V_13 -> V_2 , L_5 ) ;
return - V_22 ;
}
V_32 = F_10 ( V_13 , V_43 , V_3 ) ;
if ( V_32 < 0 ) {
F_6 ( V_13 -> V_2 , L_4 ) ;
return V_32 ;
}
return V_32 ;
}
static int F_11 ( struct V_7 * V_31 , int V_50 )
{
struct V_12 * V_13 = V_31 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_51 ;
V_51 = F_9 ( V_13 , V_52 ) ;
if ( V_50 )
V_51 |= V_53 | V_54 ;
else {
V_51 &= ~ ( V_53 | V_54 ) ;
V_51 |= V_15 -> V_55 ;
}
return F_10 ( V_13 , V_52 , V_51 ) ;
}
static int F_12 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_12 * V_13 = F_13 ( V_57 ) ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_60 = ! V_59 -> V_61 . integer . V_61 [ 0 ] ;
int V_62 = ! V_59 -> V_61 . integer . V_61 [ 1 ] ;
V_15 -> V_55 = ( V_60 ? V_53 : 0 ) |
( V_62 ? V_54 : 0 ) ;
return F_14 ( V_57 , V_59 ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_32 ;
V_32 = F_16 ( V_13 , V_52 , V_63 , 0 ) ;
if ( V_32 < 0 ) {
F_6 ( V_13 -> V_2 , L_4 ) ;
return V_32 ;
}
V_32 = F_16 ( V_13 , V_64 ,
V_65 | V_66 , 0 ) ;
if ( V_32 < 0 ) {
F_6 ( V_13 -> V_2 , L_4 ) ;
return V_32 ;
}
V_32 = F_17 ( F_18 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
return V_32 ;
}
static int F_19 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
F_20 ( F_18 ( V_15 -> V_67 ) , V_15 -> V_67 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_3 , V_32 ;
V_3 = F_9 ( V_13 , V_68 ) | V_69 ;
if ( V_3 < 0 )
return V_3 ;
V_32 = F_10 ( V_13 , V_68 , V_3 ) ;
if ( V_32 < 0 )
return V_32 ;
F_20 ( F_18 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
return 0 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_3 , V_32 ;
V_32 = F_17 ( F_18 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
if ( V_32 != 0 )
return V_32 ;
F_23 ( 500 ) ;
F_24 ( V_15 -> V_70 ) ;
V_3 = F_9 ( V_13 , V_68 ) ;
V_3 &= ~ V_69 ;
return F_10 ( V_13 , V_68 , V_3 ) ;
}
static int F_25 ( struct V_71 * V_71 ,
const struct V_72 * V_73 )
{
struct V_74 * V_75 = V_71 -> V_2 . V_76 ;
struct V_14 * V_15 ;
unsigned int V_77 ;
int V_32 , V_33 ;
V_15 = F_26 ( & V_71 -> V_2 , sizeof( struct V_14 ) ,
V_78 ) ;
if ( ! V_15 ) {
F_6 ( & V_71 -> V_2 , L_6 ) ;
return - V_79 ;
}
for ( V_33 = 0 ; V_33 < F_18 ( V_80 ) ; V_33 ++ )
V_15 -> V_67 [ V_33 ] . V_81 = V_80 [ V_33 ] ;
V_32 = F_27 ( & V_71 -> V_2 ,
F_18 ( V_15 -> V_67 ) ,
V_15 -> V_67 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_75 ) {
enum V_82 V_83 ;
int V_84 = F_28 ( V_75 , L_7 , 0 , & V_83 ) ;
if ( F_29 ( V_84 ) ) {
V_32 = F_30 ( & V_71 -> V_2 , V_84 ,
V_83 & V_85 ?
V_86 : V_87 ,
L_8 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
V_15 -> V_70 = F_31 ( V_71 , & V_88 ) ;
if ( F_32 ( V_15 -> V_70 ) )
return F_33 ( V_15 -> V_70 ) ;
V_32 = F_34 ( V_15 -> V_70 , V_6 , & V_77 ) ;
if ( V_32 < 0 ) {
F_6 ( & V_71 -> V_2 , L_9 ,
V_71 -> V_89 ) ;
return V_32 ;
}
if ( ( V_77 & 0xF0 ) != 0xC0 ) {
F_6 ( & V_71 -> V_2 , L_10 ,
V_71 -> V_89 ) ;
return - V_90 ;
}
F_35 ( & V_71 -> V_2 , L_11 ,
V_71 -> V_89 ) ;
F_35 ( & V_71 -> V_2 , L_12 , V_77 & 0xF ) ;
F_36 ( V_71 , V_15 ) ;
V_32 = F_37 ( & V_71 -> V_2 ,
& V_91 , & V_92 , 1 ) ;
return V_32 ;
}
static int F_38 ( struct V_71 * V_71 )
{
F_39 ( & V_71 -> V_2 ) ;
return 0 ;
}
