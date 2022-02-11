static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_2 . V_2 ) ;
unsigned long V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_3 ( V_4 -> V_8 -> V_9 ,
V_10 ,
V_11 ) ;
if ( V_7 < 0 ) {
F_4 ( V_4 -> V_12 ,
L_1 ) ;
goto V_13;
}
V_7 = F_5 ( V_4 -> V_8 -> V_9 ,
V_10 ,
& V_6 ) ;
if ( V_7 < 0 ) {
F_4 ( V_4 -> V_12 ,
L_2 ) ;
goto V_13;
}
if ( V_6 & V_11 ) {
F_6 ( & V_4 -> V_14 ) ;
V_4 -> V_15 = F_7 ( 125 ) ;
F_8 ( & V_4 -> V_14 ) ;
F_9 ( V_4 -> V_16 ,
V_17 ) ;
V_5 = F_10 ( V_4 -> V_16 -> V_18 ) ;
F_11 ( & V_4 -> V_2 , V_5 ) ;
return;
}
F_6 ( & V_4 -> V_14 ) ;
V_4 -> V_15 = F_7 ( 0 ) ;
F_8 ( & V_4 -> V_14 ) ;
F_9 ( V_4 -> V_16 ,
V_17 ) ;
V_13:
F_12 ( V_4 -> V_19 ) ;
}
static T_1 F_13 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
F_14 ( V_4 -> V_19 ) ;
F_11 ( & V_4 -> V_2 , 0 ) ;
return V_21 ;
}
static int F_15 ( struct V_22 * V_23 ,
enum V_24 * V_25 )
{
struct V_3 * V_4 = V_23 -> V_26 ;
* V_25 = V_4 -> V_25 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
int V_27 ,
enum V_28 * type )
{
struct V_3 * V_4 = V_23 -> V_26 ;
switch ( V_27 ) {
case 0 :
* type = V_29 ;
break;
default:
F_4 ( V_4 -> V_12 ,
L_3 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_17 ( struct V_22 * V_23 ,
int V_27 ,
int * V_31 )
{
struct V_3 * V_4 = V_23 -> V_26 ;
switch ( V_27 ) {
case 0 :
* V_31 = F_7 ( 125 ) ;
break;
default:
F_4 ( V_4 -> V_12 ,
L_3 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_18 ( struct V_22 * V_23 ,
int * V_31 )
{
struct V_3 * V_4 = V_23 -> V_26 ;
F_6 ( & V_4 -> V_14 ) ;
* V_31 = V_4 -> V_15 ;
F_8 ( & V_4 -> V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_20 ( V_33 -> V_12 . V_36 ) ;
struct V_3 * V_4 ;
unsigned int V_37 = V_38 ;
const struct V_39 * V_40 ;
int V_7 = 0 ;
V_40 = F_21 ( V_41 ,
V_33 -> V_12 . V_42 ) ;
if ( ! V_40 )
return - V_43 ;
if ( V_33 -> V_12 . V_42 ) {
if ( ! F_22 ( V_33 -> V_12 . V_42 ,
L_4 ,
& V_37 ) ) {
if ( V_37 < V_44 ||
V_37 > V_45 ) {
F_23 ( & V_33 -> V_12 ,
L_5 ,
V_37 ) ;
V_37 = V_38 ;
}
}
}
V_4 = F_24 ( & V_33 -> V_12 , sizeof( struct V_3 ) ,
V_46 ) ;
if ( ! V_4 ) {
V_7 = - V_47 ;
goto V_48;
}
V_4 -> V_49 = V_40 -> V_20 ;
V_4 -> V_8 = V_35 ;
V_4 -> V_25 = V_50 ;
V_4 -> V_12 = & V_33 -> V_12 ;
F_25 ( & V_4 -> V_2 , F_1 ) ;
F_26 ( & V_4 -> V_14 ) ;
V_4 -> V_16 = F_27 ( V_4 -> V_49 -> V_51 ,
1 , 0 , V_4 ,
& V_52 , NULL , V_37 ,
0 ) ;
if ( F_28 ( V_4 -> V_16 ) ) {
F_4 ( & V_33 -> V_12 , L_6 ) ;
V_7 = F_29 ( V_4 -> V_16 ) ;
goto V_48;
}
F_30 ( & V_33 -> V_12 ,
L_7 ,
V_4 -> V_16 -> V_18 ) ;
V_7 = F_31 ( V_33 , L_8 ) ;
if ( V_7 < 0 ) {
F_4 ( & V_33 -> V_12 , L_9 ) ;
goto V_53;
}
V_4 -> V_19 = V_7 ;
V_7 = F_32 ( V_4 -> V_19 , NULL ,
F_13 ,
V_54 | V_55 ,
L_8 , V_4 ) ;
if ( V_7 ) {
F_4 ( & V_33 -> V_12 ,
L_10 ) ;
goto V_53;
}
F_33 ( V_33 , V_4 ) ;
return 0 ;
V_53:
F_34 ( V_4 -> V_16 ) ;
V_48:
return V_7 ;
}
static int F_35 ( struct V_32 * V_33 )
{
struct V_3 * V_4 = F_36 ( V_33 ) ;
F_37 ( V_4 -> V_19 , V_4 ) ;
F_38 ( & V_4 -> V_2 ) ;
F_34 ( V_4 -> V_16 ) ;
return 0 ;
}
