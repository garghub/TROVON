static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
* V_3 = 0 ;
if ( V_6 & F_2 ( V_2 -> V_7 + V_8 ) )
goto V_9;
V_4 = F_2 ( V_2 -> V_7 + V_10 ) ;
if ( V_4 & V_11 ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
F_4 ( V_4 | V_15 , V_2 -> V_7 + V_10 ) ;
if ( ! ( V_6 & F_2 ( V_2 -> V_7 + V_8 ) ) ) {
F_3 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
V_9:
V_2 -> V_16 = - 1 ;
V_5 = F_5 ( V_2 -> V_7 + V_17 ) ;
V_5 &= 0x1FF ;
if ( V_5 ) {
V_2 -> V_18 = V_5 * 1000 / 2 - 50000 ;
V_2 -> V_16 = 0 ;
++ ( * V_3 ) ;
}
V_2 -> V_19 = - 1 ;
V_5 = F_5 ( V_2 -> V_7 + V_20 ) ;
V_5 &= 0x1FF ;
if ( V_5 ) {
V_2 -> V_21 = V_5 * 1000 / 2 - 50000 ;
V_2 -> V_19 = * V_3 ;
++ ( * V_3 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int * V_22 )
{
T_1 V_23 ;
V_23 = V_24 & F_7 ( V_2 -> V_7 + V_25 ) ;
* V_22 = ( V_23 * 1000 / 2 - 50000 ) ;
return 0 ;
}
static int F_8 ( struct V_26 * V_27 , int * V_22 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
return V_2 -> V_29 -> V_30 ( V_2 , V_22 ) ;
}
static int F_9 ( struct V_26 * V_27 , int V_31 ,
enum V_32 * type )
{
struct V_1 * V_2 = V_27 -> V_28 ;
if ( V_2 -> V_16 == V_31 )
* type = V_33 ;
else if ( V_2 -> V_19 == V_31 )
* type = V_34 ;
else
return - V_35 ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 , int V_31 , int * V_22 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
if ( V_2 -> V_16 == V_31 )
* V_22 = V_2 -> V_18 ;
else if ( V_2 -> V_19 == V_31 )
* V_22 = V_2 -> V_21 ;
else
return - V_35 ;
return 0 ;
}
static int F_11 ( struct V_36 * V_12 ,
const struct V_37 * V_38 )
{
struct V_1 * V_2 ;
int V_39 ;
int V_3 ;
char * V_40 ;
V_2 = F_12 ( & V_12 -> V_13 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
switch ( V_12 -> V_43 ) {
case V_44 :
V_2 -> V_29 = & V_45 ;
V_40 = L_2 ;
break;
case V_46 :
V_2 -> V_29 = & V_45 ;
V_40 = L_3 ;
break;
default:
F_3 ( & V_12 -> V_13 , L_4 ) ;
return - V_14 ;
}
F_13 ( V_12 , V_2 ) ;
V_2 -> V_12 = V_12 ;
V_39 = F_14 ( V_12 ) ;
if ( V_39 ) {
F_3 ( & V_12 -> V_13 , L_5 ) ;
return V_39 ;
}
V_39 = F_15 ( V_12 , V_47 ) ;
if ( V_39 ) {
F_3 ( & V_12 -> V_13 , L_6 ) ;
goto V_48;
}
V_2 -> V_7 = F_16 ( V_12 , 0 ) ;
if ( ! V_2 -> V_7 ) {
V_39 = - V_42 ;
F_3 ( & V_12 -> V_13 , L_7 ) ;
goto V_49;
}
V_39 = V_2 -> V_29 -> V_50 ( V_2 , & V_3 ) ;
if ( V_39 )
goto V_51;
V_2 -> V_27 = F_17 ( V_40 , V_3 , 0 , V_2 ,
& V_52 , NULL , 0 , 0 ) ;
if ( F_18 ( V_2 -> V_27 ) ) {
F_3 ( & V_12 -> V_13 , L_8 ,
V_40 ) ;
V_39 = F_19 ( V_2 -> V_27 ) ;
goto V_51;
}
return 0 ;
V_51:
F_20 ( V_2 -> V_7 ) ;
V_49:
F_21 ( V_12 ) ;
V_48:
F_22 ( V_12 ) ;
F_3 ( & V_12 -> V_13 , L_9 ) ;
return V_39 ;
}
static void F_23 ( struct V_36 * V_12 )
{
struct V_1 * V_2 = F_24 ( V_12 ) ;
F_25 ( V_2 -> V_27 ) ;
F_20 ( V_2 -> V_7 ) ;
F_13 ( V_12 , NULL ) ;
F_26 ( V_12 , 0 ) ;
F_22 ( V_12 ) ;
}
