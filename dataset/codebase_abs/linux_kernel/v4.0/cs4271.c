static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
int V_7 , unsigned int V_8 , int V_9 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_14 = V_8 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
unsigned int V_15 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
unsigned int V_16 = 0 ;
int V_17 ;
switch ( V_15 & V_18 ) {
case V_19 :
V_13 -> V_20 = 0 ;
break;
case V_21 :
V_13 -> V_20 = 1 ;
V_16 |= V_22 ;
break;
default:
F_5 ( V_11 -> V_2 , L_1 ) ;
return - V_23 ;
}
switch ( V_15 & V_24 ) {
case V_25 :
V_16 |= V_26 ;
V_17 = F_6 ( V_13 -> V_27 , V_28 ,
V_29 , V_30 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
case V_31 :
V_16 |= V_32 ;
V_17 = F_6 ( V_13 -> V_27 , V_28 ,
V_29 , V_33 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
default:
F_5 ( V_11 -> V_2 , L_1 ) ;
return - V_23 ;
}
V_17 = F_6 ( V_13 -> V_27 , V_34 ,
V_35 | V_22 , V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_36 , V_17 ;
int V_16 = V_37 ;
if ( V_13 -> V_38 ) {
V_16 = 1 ;
for ( V_36 = 2 ; V_36 < F_8 ( V_39 ) ; V_36 ++ )
if ( abs ( V_39 [ V_36 ] - V_13 -> V_40 ) <
abs ( V_39 [ V_16 ] - V_13 -> V_40 ) )
V_16 = V_36 ;
V_16 <<= 4 ;
}
V_17 = F_6 ( V_13 -> V_27 , V_41 ,
V_42 , V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_9 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_10 * V_11 = F_10 ( V_44 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_46 -> V_47 . integer . V_47 [ 0 ] = V_13 -> V_38 ;
return 0 ;
}
static int F_11 ( struct V_43 * V_44 ,
struct V_45 * V_46 )
{
struct V_10 * V_11 = F_10 ( V_44 ) ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_38 = V_46 -> V_47 . integer . V_47 [ 0 ] ;
return F_7 ( V_11 ) ;
}
static int F_12 ( struct V_48 * V_49 ,
struct V_50 * V_51 ,
struct V_5 * V_52 )
{
struct V_10 * V_11 = V_52 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_36 , V_17 ;
unsigned int V_53 , V_16 ;
if ( V_13 -> V_54 ) {
if ( ( V_49 -> V_55 == V_56 &&
! V_52 -> V_57 ) ||
( V_49 -> V_55 == V_58 &&
! V_52 -> V_59 ) ) {
V_17 = F_6 ( V_13 -> V_27 , V_60 ,
V_61 ,
V_61 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_60 ,
V_61 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
}
}
V_13 -> V_40 = F_13 ( V_51 ) ;
if ( V_13 -> V_40 < 50000 )
V_16 = V_62 ;
else if ( V_13 -> V_40 < 100000 )
V_16 = V_63 ;
else
V_16 = V_64 ;
V_53 = V_13 -> V_14 / V_13 -> V_40 ;
for ( V_36 = 0 ; V_36 < V_65 ; V_36 ++ )
if ( ( V_66 [ V_36 ] . V_20 == V_13 -> V_20 ) &&
( V_66 [ V_36 ] . V_67 == V_16 ) &&
( V_66 [ V_36 ] . V_53 == V_53 ) )
break;
if ( V_36 == V_65 ) {
F_5 ( V_11 -> V_2 , L_2 ) ;
return - V_23 ;
}
V_16 |= V_66 [ V_36 ] . V_68 ;
V_17 = F_6 ( V_13 -> V_27 , V_34 ,
V_69 | V_70 , V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_7 ( V_11 ) ;
}
static int F_14 ( struct V_5 * V_52 , int V_71 , int V_55 )
{
struct V_10 * V_11 = V_52 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_17 ;
int V_72 = 0 ;
int V_73 = 0 ;
if ( V_55 != V_56 )
return 0 ;
if ( V_71 ) {
V_72 = V_74 ;
V_73 = V_75 ;
}
V_17 = F_6 ( V_13 -> V_27 , V_76 ,
V_74 , V_72 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_77 ,
V_75 , V_73 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
int V_17 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_17 = F_6 ( V_13 -> V_27 , V_60 ,
V_61 , V_61 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
int V_17 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_17 = F_17 ( V_13 -> V_27 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_60 ,
V_61 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
struct V_78 * V_79 = V_11 -> V_2 -> V_80 ;
int V_17 ;
bool V_81 = false ;
#ifdef F_19
if ( F_20 ( V_82 , V_11 -> V_2 ) ) {
if ( F_21 ( V_11 -> V_2 -> V_83 ,
L_3 , NULL ) )
V_81 = true ;
if ( F_21 ( V_11 -> V_2 -> V_83 ,
L_4 , NULL ) )
V_13 -> V_54 = true ;
}
#endif
if ( V_79 ) {
V_81 = V_79 -> V_81 ;
V_13 -> V_54 = V_79 -> V_54 ;
}
if ( F_22 ( V_13 -> V_84 ) ) {
F_23 ( V_13 -> V_84 , 0 ) ;
F_24 ( 1 ) ;
F_25 ( V_13 -> V_84 , 1 ) ;
F_24 ( 1 ) ;
}
V_17 = F_6 ( V_13 -> V_27 , V_60 ,
V_61 | V_85 ,
V_61 | V_85 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_6 ( V_13 -> V_27 , V_60 ,
V_61 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
F_24 ( 85 ) ;
if ( V_81 )
F_6 ( V_13 -> V_27 , V_60 ,
V_86 ,
V_86 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
if ( F_22 ( V_13 -> V_84 ) )
F_25 ( V_13 -> V_84 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_12 * * V_87 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
struct V_12 * V_13 ;
V_13 = F_28 ( V_2 , sizeof( * V_13 ) , V_88 ) ;
if ( ! V_13 )
return - V_89 ;
if ( F_20 ( V_82 , V_2 ) )
V_13 -> V_84 =
F_29 ( V_2 -> V_83 , L_5 , 0 ) ;
if ( V_79 )
V_13 -> V_84 = V_79 -> V_84 ;
if ( F_22 ( V_13 -> V_84 ) ) {
int V_17 ;
V_17 = F_30 ( V_2 , V_13 -> V_84 ,
L_6 ) ;
if ( V_17 < 0 )
return V_17 ;
}
* V_87 = V_13 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_27 * V_27 )
{
struct V_12 * V_13 ;
int V_17 ;
if ( F_32 ( V_27 ) )
return F_33 ( V_27 ) ;
V_17 = F_27 ( V_2 , & V_13 ) ;
if ( V_17 < 0 )
return V_17 ;
F_34 ( V_2 , V_13 ) ;
V_13 -> V_27 = V_27 ;
return F_35 ( V_2 , & V_90 , & V_91 ,
1 ) ;
}
