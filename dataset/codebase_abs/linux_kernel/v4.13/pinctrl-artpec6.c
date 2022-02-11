static unsigned int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ ) {
if ( V_1 <= V_3 [ V_2 ] . V_4 ) {
return ( V_1 - V_3 [ V_2 ] . V_5 ) * 4 +
V_3 [ V_2 ] . V_6 ;
}
}
F_3 ( L_1 , V_7 , V_1 ) ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_10 ) ;
}
static const char * F_5 ( struct V_8 * V_9 ,
unsigned int V_11 )
{
return V_10 [ V_11 ] . V_12 ;
}
static int F_6 ( struct V_8 * V_9 ,
unsigned int V_11 ,
const unsigned int * * V_13 ,
unsigned int * V_14 )
{
* V_13 = ( unsigned int * ) V_10 [ V_11 ] . V_13 ;
* V_14 = V_10 [ V_11 ] . V_14 ;
return 0 ;
}
static int F_7 ( unsigned int V_15 )
{
switch ( V_15 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
default:
return - V_24 ;
}
}
static unsigned int F_8 ( int V_25 )
{
switch ( V_25 ) {
case V_17 :
return V_16 ;
case V_19 :
return V_18 ;
case V_21 :
return V_20 ;
case V_23 :
return V_22 ;
default:
return 0 ;
}
}
static int F_9 ( struct V_8 * V_9 )
{
return F_2 ( V_26 ) ;
}
static const char * F_10 ( struct V_8 * V_9 ,
unsigned int V_27 )
{
return V_26 [ V_27 ] . V_12 ;
}
static int F_11 ( struct V_8 * V_9 ,
unsigned int V_27 ,
const char * const * * V_28 ,
unsigned int * const V_29 )
{
* V_28 = V_26 [ V_27 ] . V_28 ;
* V_29 = V_26 [ V_27 ] . V_29 ;
return 0 ;
}
static void F_12 ( struct V_8 * V_9 ,
unsigned int V_27 , unsigned int V_11 ,
bool V_30 )
{
unsigned int V_31 , V_32 ;
unsigned int V_33 ;
int V_2 ;
struct V_34 * V_35 = F_13 ( V_9 ) ;
for ( V_2 = 0 ; V_2 < V_10 [ V_11 ] . V_14 ; V_2 ++ ) {
if ( V_10 [ V_11 ] . V_13 [ V_2 ] > V_36 )
continue;
if ( ! strcmp ( F_10 ( V_9 , V_27 ) , L_2 ) ) {
V_32 = V_37 << V_38 ;
} else {
if ( V_30 )
V_32 = V_10 [ V_11 ] . V_39
<< V_38 ;
else
V_32 = V_37
<< V_38 ;
}
V_33 = F_1 ( V_10 [ V_11 ] . V_13 [ V_2 ] ) ;
V_31 = F_14 ( V_35 -> V_40 + V_33 ) ;
V_31 &= ~ V_41 ;
V_31 |= V_32 ;
F_15 ( V_31 , V_35 -> V_40 + V_33 ) ;
}
}
int F_16 ( struct V_8 * V_9 , unsigned int V_27 ,
unsigned int V_11 )
{
struct V_34 * V_35 = F_13 ( V_9 ) ;
F_17 ( V_35 -> V_42 , L_3 ,
F_10 ( V_9 , V_27 ) ,
F_5 ( V_9 , V_11 ) ) ;
F_12 ( V_9 , V_27 , V_11 , true ) ;
return 0 ;
}
void F_18 ( struct V_8 * V_9 , unsigned int V_27 ,
unsigned int V_11 )
{
struct V_34 * V_35 = F_13 ( V_9 ) ;
F_17 ( V_35 -> V_42 , L_4 ,
F_10 ( V_9 , V_27 ) ,
F_5 ( V_9 , V_11 ) ) ;
F_12 ( V_9 , V_27 , V_11 , false ) ;
}
static int F_19 ( struct V_8 * V_9 ,
struct V_43 * V_44 ,
unsigned int V_1 )
{
struct V_34 * V_35 = F_13 ( V_9 ) ;
unsigned int V_33 = F_1 ( V_1 ) ;
T_1 V_32 ;
if ( V_1 >= 32 )
return - V_24 ;
V_32 = F_20 ( V_35 -> V_40 + V_33 ) ;
V_32 &= ~ V_41 ;
V_32 |= V_37 << V_38 ;
F_21 ( V_32 , V_35 -> V_40 + V_33 ) ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 , unsigned int V_1 ,
unsigned long * V_39 )
{
struct V_34 * V_35 = F_13 ( V_9 ) ;
enum V_45 V_46 = F_23 ( * V_39 ) ;
unsigned int V_31 ;
if ( V_1 >= V_35 -> V_14 ) {
F_17 ( V_35 -> V_42 , L_5 ,
V_35 -> V_13 [ V_1 ] . V_12 ) ;
return - V_47 ;
}
F_17 ( V_35 -> V_42 , L_6 ,
V_35 -> V_13 [ V_1 ] . V_12 ) ;
V_31 = F_14 ( V_35 -> V_40 + F_1 ( V_1 ) ) ;
switch ( V_46 ) {
case V_48 :
if ( ! ( V_31 & V_49 ) )
return - V_24 ;
break;
case V_50 :
case V_51 :
if ( V_31 & V_49 )
return - V_24 ;
V_31 = V_31 & V_52 ;
if ( ( V_46 == V_50 && ! V_31 ) ||
( V_46 == V_51 && V_31 ) )
return - V_24 ;
break;
case V_53 :
V_31 = ( V_31 & V_54 )
>> V_55 ;
V_31 = F_8 ( V_31 ) ;
* V_39 = F_24 ( V_46 , V_31 ) ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_25 ( struct V_8 * V_9 , unsigned int V_1 ,
unsigned long * V_56 , unsigned int V_57 )
{
struct V_34 * V_35 = F_13 ( V_9 ) ;
enum V_45 V_46 ;
unsigned int V_58 ;
unsigned int V_31 ;
unsigned int * V_33 ;
int V_2 ;
if ( V_1 >= V_35 -> V_14 ) {
F_17 ( V_35 -> V_42 , L_5 ,
V_35 -> V_13 [ V_1 ] . V_12 ) ;
return - V_47 ;
}
F_17 ( V_35 -> V_42 , L_7 ,
V_35 -> V_13 [ V_1 ] . V_12 ) ;
V_33 = V_35 -> V_40 + F_1 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_57 ; V_2 ++ ) {
int V_59 ;
V_46 = F_23 ( V_56 [ V_2 ] ) ;
V_58 = F_26 ( V_56 [ V_2 ] ) ;
switch ( V_46 ) {
case V_48 :
V_31 = F_14 ( V_33 ) ;
V_31 |= ( 1 << V_60 ) ;
F_15 ( V_31 , V_33 ) ;
break;
case V_50 :
if ( V_58 != 1 ) {
F_17 ( V_9 -> V_42 , L_8 ,
V_7 , V_58 ) ;
return - V_24 ;
}
V_31 = F_14 ( V_33 ) ;
V_31 |= ( V_58 << V_61 ) ;
V_31 &= ~ V_49 ;
F_15 ( V_31 , V_33 ) ;
break;
case V_51 :
if ( V_58 != 1 ) {
F_17 ( V_9 -> V_42 , L_8 ,
V_7 , V_58 ) ;
return - V_24 ;
}
V_31 = F_14 ( V_33 ) ;
V_31 &= ~ ( V_58 << V_61 ) ;
V_31 &= ~ V_49 ;
F_15 ( V_31 , V_33 ) ;
break;
case V_53 :
V_59 = F_7 ( V_58 ) ;
if ( V_59 < 0 ) {
F_17 ( V_9 -> V_42 , L_8 ,
V_7 , V_58 ) ;
return - V_24 ;
}
V_31 = F_14 ( V_33 ) ;
V_31 &= ~ V_54 ;
V_31 |= ( V_59 << V_55 ) ;
F_15 ( V_31 , V_33 ) ;
break;
default:
F_17 ( V_35 -> V_42 , L_9 ) ;
return - V_47 ;
}
}
return 0 ;
}
static int F_27 ( struct V_8 * V_9 ,
unsigned int V_11 , unsigned long * V_56 ,
unsigned int V_57 )
{
unsigned int V_14 , V_62 ;
int V_63 ;
F_17 ( V_9 -> V_42 , L_10 ,
F_5 ( V_9 , V_11 ) ) ;
V_14 = V_10 [ V_11 ] . V_14 ;
for ( V_62 = 0 ; V_62 < V_14 ; V_62 ++ ) {
V_63 = F_25 ( V_9 ,
V_10 [ V_11 ] . V_13 [ V_62 ] ,
V_56 , V_57 ) ;
if ( V_63 < 0 )
return V_63 ;
}
return 0 ;
}
static void F_28 ( struct V_34 * V_35 )
{
void T_2 * V_40 = V_35 -> V_40 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_64 ; V_2 ++ ) {
T_1 V_32 ;
V_32 = F_20 ( V_40 + F_1 ( V_2 ) ) ;
V_32 &= ~ V_54 ;
V_32 |= V_21 << V_55 ;
F_21 ( V_32 , V_40 + F_1 ( V_2 ) ) ;
}
}
static int F_29 ( struct V_65 * V_66 )
{
struct V_34 * V_35 ;
struct V_67 * V_68 ;
V_35 = F_30 ( & V_66 -> V_42 , sizeof( * V_35 ) , V_69 ) ;
if ( ! V_35 )
return - V_70 ;
V_35 -> V_42 = & V_66 -> V_42 ;
V_68 = F_31 ( V_66 , V_71 , 0 ) ;
V_35 -> V_40 = F_32 ( & V_66 -> V_42 , V_68 ) ;
if ( F_33 ( V_35 -> V_40 ) )
return F_34 ( V_35 -> V_40 ) ;
F_28 ( V_35 ) ;
V_35 -> V_13 = V_72 ;
V_35 -> V_14 = F_2 ( V_72 ) ;
V_35 -> V_73 = V_26 ;
V_35 -> V_74 = F_2 ( V_26 ) ;
V_35 -> V_75 = V_10 ;
V_35 -> V_76 = F_2 ( V_10 ) ;
V_35 -> V_77 = F_35 ( & V_78 , & V_66 -> V_42 , V_35 ) ;
if ( F_33 ( V_35 -> V_77 ) ) {
F_36 ( & V_66 -> V_42 , L_11 ) ;
return F_34 ( V_35 -> V_77 ) ;
}
F_37 ( V_66 , V_35 ) ;
F_38 ( & V_66 -> V_42 , L_12 ) ;
return 0 ;
}
static int F_39 ( struct V_65 * V_66 )
{
struct V_34 * V_35 = F_40 ( V_66 ) ;
F_41 ( V_35 -> V_77 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_79 ) ;
}
