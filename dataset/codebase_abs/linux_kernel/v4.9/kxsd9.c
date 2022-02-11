static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
bool V_8 = false ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ )
if ( V_3 == V_9 [ V_5 ] ) {
V_8 = true ;
break;
}
if ( ! V_8 )
return - V_10 ;
V_4 = F_3 ( V_7 -> V_11 ,
V_12 ,
V_13 ,
V_5 ) ;
if ( V_4 < 0 )
goto V_14;
V_7 -> V_15 = V_5 ;
V_14:
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_16 const * V_17 ,
int V_18 ,
int V_19 ,
long V_20 )
{
int V_4 = - V_10 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_5 ( V_7 -> V_21 ) ;
if ( V_20 == V_22 ) {
if ( V_18 )
return - V_10 ;
V_4 = F_1 ( V_2 , V_19 ) ;
}
F_6 ( V_7 -> V_21 ) ;
F_7 ( V_7 -> V_21 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 const * V_17 ,
int * V_18 , int * V_19 , long V_20 )
{
int V_4 = - V_10 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_23 ;
T_1 V_24 ;
T_2 V_25 ;
F_5 ( V_7 -> V_21 ) ;
switch ( V_20 ) {
case V_26 :
V_4 = F_9 ( V_7 -> V_11 , V_17 -> V_27 , & V_24 ,
sizeof( V_24 ) ) ;
if ( V_4 )
goto V_14;
V_25 = F_10 ( V_24 ) ;
V_25 >>= 4 ;
* V_18 = V_25 ;
V_4 = V_28 ;
break;
case V_29 :
* V_18 = V_30 ;
V_4 = V_28 ;
break;
case V_22 :
V_4 = F_11 ( V_7 -> V_11 ,
V_12 ,
& V_23 ) ;
if ( V_4 < 0 )
goto V_14;
* V_18 = 0 ;
* V_19 = V_9 [ V_23 & V_13 ] ;
V_4 = V_31 ;
break;
}
V_14:
F_6 ( V_7 -> V_21 ) ;
F_7 ( V_7 -> V_21 ) ;
return V_4 ;
}
static T_3 F_12 ( int V_32 , void * V_33 )
{
const struct V_34 * V_35 = V_33 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_4 ;
T_1 V_36 [ 8 ] ;
V_4 = F_9 ( V_7 -> V_11 ,
V_37 ,
& V_36 ,
8 ) ;
if ( V_4 ) {
F_13 ( V_7 -> V_21 ,
L_1 ) ;
return V_4 ;
}
F_14 ( V_2 ,
V_36 ,
F_15 ( V_2 ) ) ;
F_16 ( V_2 -> V_38 ) ;
return V_39 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_5 ( V_7 -> V_21 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_6 ( V_7 -> V_21 ) ;
F_7 ( V_7 -> V_21 ) ;
return 0 ;
}
static const struct V_40 *
F_19 ( const struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return & V_7 -> V_41 ;
}
static int F_20 ( struct V_6 * V_7 )
{
int V_4 ;
V_4 = F_21 ( F_22 ( V_7 -> V_42 ) , V_7 -> V_42 ) ;
if ( V_4 ) {
F_13 ( V_7 -> V_21 , L_2 ) ;
return V_4 ;
}
V_4 = F_23 ( V_7 -> V_11 ,
V_43 ,
V_44 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_23 ( V_7 -> V_11 ,
V_12 ,
V_45 |
V_46 |
V_47 |
V_7 -> V_15 ) ;
if ( V_4 )
return V_4 ;
F_24 ( 20 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
int V_4 ;
V_4 = F_3 ( V_7 -> V_11 ,
V_43 ,
V_44 ,
0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_26 ( F_22 ( V_7 -> V_42 ) , V_7 -> V_42 ) ;
if ( V_4 ) {
F_13 ( V_7 -> V_21 , L_3 ) ;
return V_4 ;
}
return 0 ;
}
int F_27 ( struct V_48 * V_21 ,
struct V_49 * V_11 ,
const char * V_50 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_4 ;
V_2 = F_28 ( V_21 , sizeof( * V_7 ) ) ;
if ( ! V_2 )
return - V_51 ;
V_7 = F_2 ( V_2 ) ;
V_7 -> V_21 = V_21 ;
V_7 -> V_11 = V_11 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_54 = F_22 ( V_53 ) ;
V_2 -> V_50 = V_50 ;
V_2 -> V_21 . V_55 = V_21 ;
V_2 -> V_56 = & V_57 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_60 = V_61 ;
V_4 = F_29 ( V_21 ,
L_4 ,
& V_7 -> V_41 ) ;
if ( V_4 )
return V_4 ;
V_7 -> V_42 [ 0 ] . V_62 = V_63 ;
V_7 -> V_42 [ 1 ] . V_62 = V_64 ;
V_4 = F_30 ( V_21 ,
F_22 ( V_7 -> V_42 ) ,
V_7 -> V_42 ) ;
if ( V_4 ) {
F_13 ( V_21 , L_5 ) ;
return V_4 ;
}
V_7 -> V_15 = V_65 ;
F_20 ( V_7 ) ;
V_4 = F_31 ( V_2 ,
V_66 ,
F_12 ,
& V_67 ) ;
if ( V_4 ) {
F_13 ( V_21 , L_6 ) ;
goto V_68;
}
V_4 = F_32 ( V_2 ) ;
if ( V_4 )
goto V_69;
F_33 ( V_21 , V_2 ) ;
F_34 ( V_21 ) ;
F_35 ( V_21 ) ;
F_36 ( V_21 ) ;
F_37 ( V_21 , 2000 ) ;
F_38 ( V_21 ) ;
F_39 ( V_21 ) ;
return 0 ;
V_69:
F_40 ( V_2 ) ;
V_68:
F_25 ( V_7 ) ;
return V_4 ;
}
int F_41 ( struct V_48 * V_21 )
{
struct V_1 * V_2 = F_42 ( V_21 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_40 ( V_2 ) ;
F_43 ( V_2 ) ;
F_5 ( V_21 ) ;
F_44 ( V_21 ) ;
F_45 ( V_21 ) ;
F_25 ( V_7 ) ;
return 0 ;
}
static int F_46 ( struct V_48 * V_21 )
{
struct V_1 * V_2 = F_42 ( V_21 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_25 ( V_7 ) ;
}
static int F_47 ( struct V_48 * V_21 )
{
struct V_1 * V_2 = F_42 ( V_21 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_20 ( V_7 ) ;
}
