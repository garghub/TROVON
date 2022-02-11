static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_5 = V_2 -> V_5 ;
const struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
V_2 -> V_9 = F_2 ( V_4 , V_5 ,
V_7 [ V_10 ] ) ;
V_2 -> V_11 = F_2 ( V_4 , V_5 ,
V_7 [ V_12 ] ) ;
V_2 -> V_13 = F_2 ( V_4 , V_5 ,
V_7 [ V_14 ] ) ;
if ( F_3 ( V_2 -> V_9 ) ||
F_3 ( V_2 -> V_11 ) ||
F_3 ( V_2 -> V_13 ) ) {
F_4 ( V_4 , L_1 ) ;
return - V_15 ;
}
return V_2 -> V_16 -> V_17 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_18 = F_6 ( V_2 -> V_19 ) ;
if ( V_18 ) {
F_4 ( V_4 , L_2 ) ;
return V_18 ;
}
V_18 = V_2 -> V_16 -> V_20 ( V_2 , V_21 ) ;
if ( V_18 ) {
F_4 ( V_4 , L_3 ) ;
F_7 ( V_2 -> V_19 ) ;
}
return V_18 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = V_2 -> V_16 -> V_20 ( V_2 , V_22 ) ;
if ( V_18 )
return V_18 ;
F_7 ( V_2 -> V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_18 ;
unsigned int V_23 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_18 = F_10 ( V_2 -> V_9 , & V_23 ) ;
if ( V_18 ) {
F_4 ( V_4 , L_4 ) ;
return V_18 ;
}
if ( ! V_23 ) {
V_18 = F_11 ( V_2 -> V_9 ,
V_2 -> V_8 -> V_24 ) ;
if ( V_18 )
F_4 ( V_4 , L_5 ) ;
}
return V_18 ;
}
static int F_12 ( struct V_25 * V_26 ,
unsigned long * V_27 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_29 ;
unsigned int V_11 ;
int V_18 ;
V_18 = F_10 ( V_2 -> V_11 , & V_11 ) ;
if ( V_18 )
return V_18 ;
if ( V_11 )
return - V_30 ;
V_18 = F_10 ( V_2 -> V_13 , & V_29 ) ;
if ( V_18 )
return V_18 ;
V_29 += V_2 -> V_8 -> V_31 ;
V_29 = F_13 ( V_29 ) ;
F_14 ( V_4 , L_6 , V_29 ) ;
* V_27 = V_29 ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 ,
int V_32 , enum V_33 * type )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
switch ( V_32 ) {
case 0 :
* type = V_34 ;
break;
default:
F_4 ( V_4 , L_7 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_16 ( struct V_25 * V_26 ,
int V_32 , unsigned long * V_29 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
switch ( V_32 ) {
case 0 :
* V_29 = F_13 ( V_2 -> V_8 -> V_35 ) ;
break;
default:
F_4 ( V_4 , L_8 ) ;
return - V_15 ;
}
return 0 ;
}
int F_17 ( struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_37 -> V_4 ;
struct V_40 * V_41 = V_4 -> V_42 ;
const struct V_38 * V_43 ;
int V_44 ;
int V_18 ;
if ( ! V_41 ) {
F_4 ( V_4 , L_9 ) ;
return - V_15 ;
}
V_2 = F_18 ( V_4 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_4 = V_4 ;
V_43 = F_19 ( V_39 , V_4 ) ;
if ( ! ( V_43 && V_43 -> V_47 ) )
return - V_15 ;
V_2 -> V_8 = V_43 -> V_47 ;
if ( ! V_2 -> V_8 -> V_16 )
return - V_15 ;
V_2 -> V_16 = V_2 -> V_8 -> V_16 ;
V_18 = V_2 -> V_16 -> V_48 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_19 = F_20 ( V_4 , L_10 ) ;
if ( F_3 ( V_2 -> V_19 ) ) {
F_4 ( V_4 , L_11 ) ;
return F_21 ( V_2 -> V_19 ) ;
}
if ( V_2 -> V_16 -> V_49 ) {
V_18 = V_2 -> V_16 -> V_49 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
V_18 = F_5 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 )
goto V_50;
V_44 = V_2 -> V_16 -> V_49 ? 0 : 1000 ;
V_2 -> V_51 =
F_22 ( F_23 ( V_4 ) , 1 , 0 , V_2 ,
& V_52 , NULL , 0 , V_44 ) ;
if ( F_3 ( V_2 -> V_51 ) ) {
F_4 ( V_4 , L_12 ) ;
V_18 = F_21 ( V_2 -> V_51 ) ;
goto V_50;
}
F_24 ( V_37 , V_2 ) ;
return 0 ;
V_50:
F_8 ( V_2 ) ;
return V_18 ;
}
int F_25 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_26 ( V_37 ) ;
F_8 ( V_2 ) ;
F_27 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = F_29 ( V_4 ) ;
struct V_1 * V_2 = F_26 ( V_37 ) ;
return F_8 ( V_2 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
int V_18 ;
struct V_36 * V_37 = F_29 ( V_4 ) ;
struct V_1 * V_2 = F_26 ( V_37 ) ;
V_18 = F_5 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_2 -> V_16 -> V_53 ) {
V_18 = V_2 -> V_16 -> V_53 ( V_2 ) ;
if ( V_18 )
return V_18 ;
}
return 0 ;
}
