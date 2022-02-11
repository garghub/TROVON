static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 -> V_9 , V_5 -> V_10 [ V_3 ] . V_11 , & V_7 ) ;
if ( V_6 ) {
F_4 ( V_5 -> V_12 , L_1 , V_3 ) ;
return V_6 ;
}
return ! ! ( V_7 & V_5 -> V_10 [ V_3 ] . V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_6 ( V_5 -> V_8 -> V_9 ,
V_5 -> V_10 [ V_3 ] . V_11 ,
V_5 -> V_10 [ V_3 ] . V_13 ,
V_14 ? V_5 -> V_10 [ V_3 ] . V_13 : 0 ) ;
if ( V_6 )
F_4 ( V_5 -> V_12 , L_2 ,
V_3 , V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_8 ( V_2 -> V_15 + V_3 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_14 )
{
F_5 ( V_2 , V_3 , V_14 ) ;
return F_10 ( V_2 -> V_15 + V_3 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_6 ;
if ( ! V_5 -> V_10 [ V_3 ] . V_16 )
return 0 ;
V_6 = F_3 ( V_5 -> V_8 -> V_9 ,
V_5 -> V_10 [ V_3 ] . V_11 ,
& V_7 ) ;
if ( V_6 ) {
F_4 ( V_5 -> V_12 , L_3 , V_3 ) ;
return V_6 ;
}
return ! ( V_7 & V_5 -> V_10 [ V_3 ] . V_16 ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
return V_5 -> V_19 ;
}
static const char * F_14 ( struct V_17 * V_18 ,
unsigned int V_20 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
return V_5 -> V_21 [ V_20 ] . V_22 ;
}
static int F_15 ( struct V_17 * V_18 ,
unsigned int V_20 ,
const unsigned int * * V_23 ,
unsigned int * V_24 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
* V_23 = V_5 -> V_21 [ V_20 ] . V_23 ;
* V_24 = V_5 -> V_21 [ V_20 ] . V_25 ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
return V_5 -> V_26 ;
}
static const char * F_17 ( struct V_17 * V_18 ,
unsigned int V_27 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
return V_5 -> V_28 [ V_27 ] . V_22 ;
}
static int F_18 ( struct V_17 * V_18 ,
unsigned int V_27 ,
const char * const * * V_21 ,
unsigned int * const V_29 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
* V_21 = V_5 -> V_28 [ V_27 ] . V_21 ;
* V_29 = V_5 -> V_28 [ V_27 ] . V_30 ;
return 0 ;
}
static int F_19 ( struct V_17 * V_18 ,
unsigned int V_3 ,
int V_31 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
int V_6 ;
if ( ! V_5 -> V_10 [ V_3 ] . V_32 )
return 0 ;
if ( V_31 == V_33 ) {
V_6 = F_6 ( V_5 -> V_8 -> V_9 ,
V_5 -> V_10 [ V_3 ] . V_11 ,
V_5 -> V_10 [ V_3 ] . V_32 ,
V_5 -> V_10 [ V_3 ] . V_32 ) ;
if ( V_6 ) {
F_4 ( V_5 -> V_12 , L_4 , V_3 ) ;
return V_6 ;
}
} else {
F_4 ( V_5 -> V_12 , L_5 , V_31 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
unsigned int V_27 ,
unsigned int V_20 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
int V_31 = V_5 -> V_28 [ V_27 ] . V_35 ;
int V_3 = V_20 ;
return F_19 ( V_18 , V_3 , V_31 ) ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_36 * V_37 ,
unsigned int V_3 , bool V_38 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
int V_6 ;
V_6 = F_19 ( V_18 , V_3 , V_33 ) ;
if ( V_6 ) {
F_4 ( V_5 -> V_12 , L_6 , V_3 ) ;
return V_6 ;
}
if ( ! V_5 -> V_10 [ V_3 ] . V_16 )
return 0 ;
V_6 = F_6 ( V_5 -> V_8 -> V_9 ,
V_5 -> V_10 [ V_3 ] . V_11 ,
V_5 -> V_10 [ V_3 ] . V_16 ,
V_38 ? 0 : V_5 -> V_10 [ V_3 ] . V_16 ) ;
if ( V_6 ) {
F_4 ( V_5 -> V_12 , L_7 , V_3 ) ;
return V_6 ;
}
return V_6 ;
}
static int F_22 ( struct V_17 * V_18 ,
unsigned int V_39 , unsigned long * V_40 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
enum V_41 V_42 = F_23 ( * V_40 ) ;
T_1 V_43 = 0 ;
switch ( V_42 ) {
case V_44 :
V_43 = F_1 ( & V_5 -> V_1 , V_39 ) ;
break;
default:
F_4 ( V_5 -> V_12 , L_8 ) ;
return - V_45 ;
}
* V_40 = F_24 ( V_42 , ( V_46 ) V_43 ) ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 ,
unsigned int V_39 , unsigned long * V_47 ,
unsigned int V_48 )
{
struct V_4 * V_5 = F_13 ( V_18 ) ;
enum V_41 V_42 ;
T_1 V_49 , V_43 = 0 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
V_42 = F_23 ( V_47 [ V_49 ] ) ;
V_43 = F_26 ( V_47 [ V_49 ] ) ;
switch ( V_42 ) {
case V_44 :
F_5 ( & V_5 -> V_1 , V_39 , V_43 ) ;
F_21 ( V_18 , NULL , V_39 , false ) ;
break;
default:
F_4 ( V_5 -> V_12 , L_8 ) ;
return - V_45 ;
}
}
return 0 ;
}
static int F_27 ( struct V_50 * V_51 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_28 ( & V_51 -> V_12 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
V_5 -> V_12 = & V_51 -> V_12 ;
V_5 -> V_12 -> V_54 = V_51 -> V_12 . V_55 -> V_54 ;
V_5 -> V_8 = F_29 ( V_51 -> V_12 . V_55 ) ;
V_5 -> V_56 = V_57 ;
V_5 -> V_1 = V_58 ;
V_5 -> V_1 . V_55 = & V_51 -> V_12 ;
V_5 -> V_1 . V_54 = V_51 -> V_12 . V_55 -> V_54 ;
F_30 ( V_51 , V_5 ) ;
switch ( V_5 -> V_8 -> V_59 ) {
case V_60 :
V_5 -> V_23 = V_61 ;
V_5 -> V_24 = F_31 ( V_61 ) ;
V_5 -> V_28 = V_62 ;
V_5 -> V_26 = F_31 ( V_62 ) ;
V_5 -> V_21 = V_63 ;
V_5 -> V_19 = F_31 ( V_63 ) ;
V_5 -> V_56 . V_23 = V_61 ;
V_5 -> V_56 . V_25 = F_31 ( V_61 ) ;
V_5 -> V_10 = V_64 ;
V_5 -> V_1 . V_65 = F_31 ( V_64 ) ;
break;
default:
F_4 ( & V_51 -> V_12 , L_9 ,
V_5 -> V_8 -> V_59 ) ;
return - V_34 ;
}
V_6 = F_32 ( & V_51 -> V_12 , & V_5 -> V_1 , V_5 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_51 -> V_12 , L_10 ) ;
return V_6 ;
}
V_5 -> V_66 = F_33 ( & V_51 -> V_12 , & V_5 -> V_56 , V_5 ) ;
if ( F_34 ( V_5 -> V_66 ) ) {
F_4 ( & V_51 -> V_12 , L_11 ) ;
return F_35 ( V_5 -> V_66 ) ;
}
V_6 = F_36 ( & V_5 -> V_1 , F_37 ( & V_51 -> V_12 ) ,
0 , 0 , V_5 -> V_1 . V_65 ) ;
if ( V_6 < 0 ) {
F_4 ( & V_51 -> V_12 , L_12 ) ;
return V_6 ;
}
return 0 ;
}
