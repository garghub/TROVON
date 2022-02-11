static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
* V_3 = 0 ;
if ( V_6 & F_2 ( V_2 -> V_7 + V_8 ) ) {
V_2 -> V_9 = true ;
goto V_10;
}
V_4 = F_2 ( V_2 -> V_7 + V_11 ) ;
if ( V_4 & V_12 ) {
F_3 ( & V_2 -> V_13 -> V_14 , L_1 ) ;
return - V_15 ;
}
F_4 ( V_4 | V_16 , V_2 -> V_7 + V_11 ) ;
if ( ! ( V_6 & F_2 ( V_2 -> V_7 + V_8 ) ) ) {
F_3 ( & V_2 -> V_13 -> V_14 , L_1 ) ;
return - V_15 ;
}
V_10:
V_2 -> V_17 = - 1 ;
V_5 = F_5 ( V_2 -> V_7 + V_18 ) ;
V_5 &= 0x1FF ;
if ( V_5 ) {
V_2 -> V_19 = V_5 * 1000 / 2 - 50000 ;
V_2 -> V_17 = 0 ;
++ ( * V_3 ) ;
}
V_2 -> V_20 = - 1 ;
V_5 = F_5 ( V_2 -> V_7 + V_21 ) ;
V_5 &= 0x1FF ;
if ( V_5 ) {
V_2 -> V_22 = V_5 * 1000 / 2 - 50000 ;
V_2 -> V_20 = * V_3 ;
++ ( * V_3 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int * V_23 )
{
T_1 V_24 ;
V_24 = V_25 & F_7 ( V_2 -> V_7 + V_26 ) ;
* V_23 = ( V_24 * 1000 / 2 - 50000 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( V_2 -> V_9 )
return 0 ;
V_4 = F_2 ( V_2 -> V_7 + V_11 ) ;
F_4 ( V_4 & 0xFE , V_2 -> V_7 + V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( V_2 -> V_9 )
return 0 ;
V_4 = F_2 ( V_2 -> V_7 + V_11 ) ;
F_4 ( V_4 | V_16 , V_2 -> V_7 + V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_27 * V_28 , int * V_23 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
return V_2 -> V_30 -> V_31 ( V_2 , V_23 ) ;
}
static int F_11 ( struct V_27 * V_28 , int V_32 ,
enum V_33 * type )
{
struct V_1 * V_2 = V_28 -> V_29 ;
if ( V_2 -> V_17 == V_32 )
* type = V_34 ;
else if ( V_2 -> V_20 == V_32 )
* type = V_35 ;
else
return - V_36 ;
return 0 ;
}
static int F_12 ( struct V_27 * V_28 , int V_32 , int * V_23 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
if ( V_2 -> V_17 == V_32 )
* V_23 = V_2 -> V_19 ;
else if ( V_2 -> V_20 == V_32 )
* V_23 = V_2 -> V_22 ;
else
return - V_36 ;
return 0 ;
}
static int F_13 ( struct V_37 * V_13 ,
const struct V_38 * V_39 )
{
struct V_1 * V_2 ;
int V_40 ;
int V_3 ;
char * V_41 ;
V_2 = F_14 ( & V_13 -> V_14 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
switch ( V_13 -> V_44 ) {
case V_45 :
V_2 -> V_30 = & V_46 ;
V_41 = L_2 ;
break;
case V_47 :
V_2 -> V_30 = & V_46 ;
V_41 = L_3 ;
break;
default:
F_3 ( & V_13 -> V_14 , L_4 ) ;
return - V_15 ;
}
F_15 ( V_13 , V_2 ) ;
V_2 -> V_13 = V_13 ;
V_40 = F_16 ( V_13 ) ;
if ( V_40 ) {
F_3 ( & V_13 -> V_14 , L_5 ) ;
return V_40 ;
}
V_40 = F_17 ( V_13 , V_48 ) ;
if ( V_40 ) {
F_3 ( & V_13 -> V_14 , L_6 ) ;
goto V_49;
}
V_2 -> V_7 = F_18 ( V_13 , 0 ) ;
if ( ! V_2 -> V_7 ) {
V_40 = - V_43 ;
F_3 ( & V_13 -> V_14 , L_7 ) ;
goto V_50;
}
V_40 = V_2 -> V_30 -> V_51 ( V_2 , & V_3 ) ;
if ( V_40 )
goto V_52;
V_2 -> V_28 = F_19 ( V_41 , V_3 , 0 , V_2 ,
& V_53 , NULL , 0 , 0 ) ;
if ( F_20 ( V_2 -> V_28 ) ) {
F_3 ( & V_13 -> V_14 , L_8 ,
V_41 ) ;
V_40 = F_21 ( V_2 -> V_28 ) ;
goto V_52;
}
return 0 ;
V_52:
F_22 ( V_2 -> V_7 ) ;
V_50:
F_23 ( V_13 ) ;
V_49:
F_24 ( V_13 ) ;
F_3 ( & V_13 -> V_14 , L_9 ) ;
return V_40 ;
}
static void F_25 ( struct V_37 * V_13 )
{
struct V_1 * V_2 = F_26 ( V_13 ) ;
F_27 ( V_2 -> V_28 ) ;
F_22 ( V_2 -> V_7 ) ;
F_15 ( V_13 , NULL ) ;
F_28 ( V_13 , 0 ) ;
F_24 ( V_13 ) ;
}
static int F_29 ( struct V_44 * V_44 )
{
struct V_37 * V_13 = F_30 ( V_44 ) ;
struct V_1 * V_2 = F_26 ( V_13 ) ;
return V_2 -> V_30 -> V_54 ( V_2 ) ;
}
static int F_31 ( struct V_44 * V_44 )
{
struct V_37 * V_13 = F_30 ( V_44 ) ;
struct V_1 * V_2 = F_26 ( V_13 ) ;
return V_2 -> V_30 -> V_55 ( V_2 ) ;
}
