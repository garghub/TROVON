static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_5 ) ;
if ( V_4 )
return V_4 ;
F_4 ( V_3 -> V_6 , F_5 ( 2 ) , V_7 ,
V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_4 ( V_3 -> V_6 , F_5 ( 2 ) , V_7 , 0 ) ;
F_7 ( V_3 -> V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_4 ;
V_4 = F_3 ( V_3 -> V_8 ) ;
if ( V_4 )
return V_4 ;
F_4 ( V_3 -> V_6 , F_5 ( 2 ) , V_9 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_4 ( V_3 -> V_6 , F_5 ( 2 ) , V_9 ,
V_9 ) ;
F_7 ( V_3 -> V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , enum V_10 V_11 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_12 ;
switch ( V_11 ) {
case V_13 :
V_12 = V_14 ;
break;
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
V_12 = V_18 ;
break;
default:
return - V_19 ;
}
F_4 ( V_3 -> V_6 , F_5 ( 2 ) , V_20 ,
V_12 ) ;
return 0 ;
}
static struct V_1 * F_11 ( struct V_21 * V_22 ,
struct V_23 * args )
{
struct V_2 * V_3 = F_12 ( V_22 ) ;
if ( ! V_3 )
return F_13 ( - V_24 ) ;
switch ( args -> args [ 0 ] ) {
case 0 :
return V_3 -> V_25 ;
case 1 :
return V_3 -> V_26 ;
default:
return F_13 ( - V_19 ) ;
}
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_21 * V_22 = & V_28 -> V_22 ;
struct V_29 * V_30 = V_22 -> V_31 ;
struct V_2 * V_3 ;
V_3 = F_15 ( V_22 , sizeof( * V_3 ) , V_32 ) ;
if ( ! V_3 )
return - V_33 ;
if ( V_30 )
V_3 -> V_6 = F_16 (
L_1 ) ;
else
V_3 -> V_6 = F_17 ( L_2 ) ;
if ( F_18 ( V_3 -> V_6 ) ) {
F_19 ( V_22 , L_3 ) ;
return F_20 ( V_3 -> V_6 ) ;
}
V_3 -> V_5 = F_21 ( V_22 , L_4 ) ;
if ( F_18 ( V_3 -> V_5 ) ) {
F_19 ( V_22 , L_5 ) ;
return F_20 ( V_3 -> V_5 ) ;
}
V_3 -> V_8 = F_21 ( V_22 , L_6 ) ;
if ( F_18 ( V_3 -> V_8 ) ) {
F_19 ( V_22 , L_7 ) ;
return F_20 ( V_3 -> V_8 ) ;
}
V_3 -> V_26 = F_22 ( V_22 , V_30 , & V_34 ) ;
if ( F_18 ( V_3 -> V_26 ) ) {
F_19 ( V_22 , L_8 ) ;
return F_20 ( V_3 -> V_26 ) ;
}
V_3 -> V_25 = F_22 ( V_22 , V_30 , & V_35 ) ;
if ( F_18 ( V_3 -> V_25 ) ) {
F_19 ( V_22 , L_9 ) ;
return F_20 ( V_3 -> V_25 ) ;
}
F_23 ( V_28 , V_3 ) ;
F_24 ( V_3 -> V_26 , V_3 ) ;
F_24 ( V_3 -> V_25 , V_3 ) ;
if ( V_30 ) {
V_3 -> V_36 = F_25 ( V_22 ,
F_11 ) ;
if ( F_18 ( V_3 -> V_36 ) ) {
F_19 ( V_22 , L_10 ) ;
return F_20 ( V_3 -> V_36 ) ;
}
} else {
int V_4 ;
V_4 = F_26 ( V_3 -> V_26 , L_11 ,
L_12 ) ;
if ( V_4 )
F_27 ( V_22 , L_13 ) ;
V_4 = F_26 ( V_3 -> V_25 , L_11 ,
L_14 ) ;
if ( V_4 )
F_27 ( V_22 , L_15 ) ;
}
F_4 ( V_3 -> V_6 , F_5 ( 2 ) ,
V_37 , V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = F_29 ( V_28 ) ;
if ( ! V_28 -> V_22 . V_31 ) {
F_30 ( V_3 -> V_25 , L_11 , L_14 ) ;
F_30 ( V_3 -> V_26 , L_11 , L_12 ) ;
}
return 0 ;
}
