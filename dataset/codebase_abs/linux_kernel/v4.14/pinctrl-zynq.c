static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_6 ,
const unsigned int * * V_9 ,
unsigned int * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_11 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_12 ;
}
static const char * F_6 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_13 [ V_6 ] . V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_6 ,
const char * const * * V_7 ,
unsigned * const V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_7 = V_4 -> V_13 [ V_6 ] . V_7 ;
* V_14 = V_4 -> V_13 [ V_6 ] . V_5 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_15 ,
unsigned int V_16 )
{
int V_17 , V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_19 * V_20 = & V_4 -> V_7 [ V_16 ] ;
const struct V_21 * V_22 = & V_4 -> V_13 [ V_15 ] ;
if ( V_15 == V_23 || V_15 == V_24 ||
V_15 == V_25 ||
V_15 == V_26 ) {
T_1 V_27 ;
V_18 = F_9 ( V_4 -> V_28 ,
V_4 -> V_29 + V_22 -> V_30 , & V_27 ) ;
if ( V_18 )
return V_18 ;
V_27 &= ~ V_22 -> V_31 ;
V_27 |= V_20 -> V_9 [ 0 ] << V_22 -> V_32 ;
V_18 = F_10 ( V_4 -> V_28 ,
V_4 -> V_29 + V_22 -> V_30 , V_27 ) ;
if ( V_18 )
return V_18 ;
} else {
for ( V_17 = 0 ; V_17 < V_20 -> V_11 ; V_17 ++ ) {
unsigned int V_33 = V_20 -> V_9 [ V_17 ] ;
T_1 V_27 , V_34 = V_4 -> V_29 + ( 4 * V_33 ) ;
V_18 = F_9 ( V_4 -> V_28 , V_34 , & V_27 ) ;
if ( V_18 )
return V_18 ;
V_27 &= ~ V_35 ;
V_27 |= V_22 -> V_36 << V_37 ;
V_18 = F_10 ( V_4 -> V_28 , V_34 , V_27 ) ;
if ( V_18 )
return V_18 ;
}
}
return 0 ;
}
static unsigned int F_11 ( T_1 V_27 )
{
return ( V_27 & V_38 ) >> V_39 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_33 ,
unsigned long * V_40 )
{
T_1 V_27 ;
int V_18 ;
unsigned int V_41 = 0 ;
unsigned int V_42 = F_13 ( * V_40 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_33 >= V_43 )
return - V_44 ;
V_18 = F_9 ( V_4 -> V_28 , V_4 -> V_29 + ( 4 * V_33 ) , & V_27 ) ;
if ( V_18 )
return - V_45 ;
switch ( V_42 ) {
case V_46 :
if ( ! ( V_27 & V_47 ) )
return - V_48 ;
V_41 = 1 ;
break;
case V_49 :
if ( ! ( V_27 & V_50 ) )
return - V_48 ;
V_41 = 1 ;
break;
case V_51 :
if ( V_27 & V_47 || V_27 & V_50 )
return - V_48 ;
break;
case V_52 :
V_41 = ! ! ( V_27 & V_53 ) ;
break;
case V_54 :
{
enum V_55 V_56 = F_11 ( V_27 ) ;
if ( V_56 != V_57 )
return - V_48 ;
if ( ! ( V_27 & V_58 ) )
return - V_48 ;
V_41 = ! ! ( V_27 & V_58 ) ;
break;
}
case V_59 :
V_41 = F_11 ( V_27 ) ;
break;
default:
return - V_44 ;
}
* V_40 = F_14 ( V_42 , V_41 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_33 ,
unsigned long * V_60 ,
unsigned int V_61 )
{
int V_17 , V_18 ;
T_1 V_27 ;
T_1 V_62 = 0 ;
T_1 V_63 = 0 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_33 >= V_43 )
return - V_44 ;
V_18 = F_9 ( V_4 -> V_28 , V_4 -> V_29 + ( 4 * V_33 ) , & V_27 ) ;
if ( V_18 )
return - V_45 ;
for ( V_17 = 0 ; V_17 < V_61 ; V_17 ++ ) {
unsigned int V_42 = F_13 ( V_60 [ V_17 ] ) ;
unsigned int V_41 = F_16 ( V_60 [ V_17 ] ) ;
switch ( V_42 ) {
case V_46 :
V_62 = V_47 ;
break;
case V_49 :
V_63 = V_50 ;
break;
case V_51 :
V_27 &= ~ ( V_47 | V_50 ) ;
break;
case V_52 :
if ( V_41 )
V_27 |= V_53 ;
else
V_27 &= ~ V_53 ;
break;
case V_59 :
if ( V_41 <= V_64 || V_41 >= V_65 ) {
F_17 ( V_2 -> V_66 ,
L_1 ,
V_42 ) ;
break;
}
V_27 &= ~ V_38 ;
V_27 |= V_41 << V_39 ;
break;
case V_54 :
if ( V_41 )
V_27 |= V_58 ;
else
V_27 &= ~ V_58 ;
break;
default:
F_17 ( V_2 -> V_66 ,
L_2 ,
V_42 ) ;
continue;
}
}
if ( V_63 || V_62 ) {
V_27 &= ~ ( V_47 | V_50 ) ;
V_27 |= V_63 | V_62 ;
}
V_18 = F_10 ( V_4 -> V_28 , V_4 -> V_29 + ( 4 * V_33 ) , V_27 ) ;
if ( V_18 )
return - V_45 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_6 ,
unsigned long * V_60 ,
unsigned int V_61 )
{
int V_17 , V_18 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_19 * V_20 = & V_4 -> V_7 [ V_6 ] ;
for ( V_17 = 0 ; V_17 < V_20 -> V_11 ; V_17 ++ ) {
V_18 = F_15 ( V_2 , V_20 -> V_9 [ V_17 ] , V_60 ,
V_61 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
static int F_19 ( struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_3 * V_4 ;
V_4 = F_20 ( & V_68 -> V_66 , sizeof( * V_4 ) , V_71 ) ;
if ( ! V_4 )
return - V_72 ;
V_4 -> V_28 = F_21 ( V_68 -> V_66 . V_73 ,
L_3 ) ;
if ( F_22 ( V_4 -> V_28 ) ) {
F_23 ( & V_68 -> V_66 , L_4 ) ;
return F_24 ( V_4 -> V_28 ) ;
}
V_70 = F_25 ( V_68 , V_74 , 0 ) ;
if ( ! V_70 ) {
F_23 ( & V_68 -> V_66 , L_5 ) ;
return - V_75 ;
}
V_4 -> V_29 = V_70 -> V_76 ;
V_4 -> V_7 = V_77 ;
V_4 -> V_5 = F_26 ( V_77 ) ;
V_4 -> V_13 = V_78 ;
V_4 -> V_12 = F_26 ( V_78 ) ;
V_4 -> V_4 = F_27 ( & V_68 -> V_66 , & V_79 , V_4 ) ;
if ( F_22 ( V_4 -> V_4 ) )
return F_24 ( V_4 -> V_4 ) ;
F_28 ( V_68 , V_4 ) ;
F_29 ( & V_68 -> V_66 , L_6 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_80 ) ;
}
