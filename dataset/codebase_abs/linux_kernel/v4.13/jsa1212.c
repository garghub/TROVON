static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_8 = ! ! V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_9 ,
V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_10 = ! ! V_3 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int * V_11 )
{
int V_4 ;
T_2 V_12 ;
V_4 = F_1 ( V_2 , V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
F_5 ( V_14 ) ;
V_4 = F_6 ( V_2 -> V_5 , V_15 , & V_12 , 2 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_2 -> V_16 -> V_17 , L_1 ) ;
goto V_18;
}
* V_11 = F_8 ( V_12 ) ;
V_18:
return F_1 ( V_2 , V_19 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int * V_11 )
{
int V_4 ;
unsigned int V_20 ;
V_4 = F_3 ( V_2 , V_21 ) ;
if ( V_4 < 0 )
return V_4 ;
F_5 ( V_22 ) ;
V_4 = F_10 ( V_2 -> V_5 , V_23 , & V_20 ) ;
if ( V_4 < 0 ) {
F_7 ( & V_2 -> V_16 -> V_17 , L_2 ) ;
goto V_24;
}
* V_11 = V_20 & V_25 ;
V_24:
return F_3 ( V_2 , V_26 ) ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_29 const * V_30 ,
int * V_11 , int * V_31 , long V_32 )
{
int V_4 ;
struct V_1 * V_2 = F_12 ( V_28 ) ;
switch ( V_32 ) {
case V_33 :
F_13 ( & V_2 -> V_34 ) ;
switch ( V_30 -> type ) {
case V_35 :
V_4 = F_4 ( V_2 , V_11 ) ;
break;
case V_36 :
V_4 = F_9 ( V_2 , V_11 ) ;
break;
default:
V_4 = - V_37 ;
break;
}
F_14 ( & V_2 -> V_34 ) ;
return V_4 < 0 ? V_4 : V_38 ;
case V_39 :
switch ( V_30 -> type ) {
case V_35 :
* V_11 = V_40 [ V_2 -> V_41 ] ;
* V_31 = F_15 ( 12 ) ;
return V_42 ;
default:
break;
}
break;
default:
break;
}
return - V_37 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_17 ( V_2 -> V_5 , V_6 ,
( V_43 |
V_44 ) ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_17 ( V_2 -> V_5 , V_45 ,
V_46 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_41 = V_47 ;
return 0 ;
}
static bool F_18 ( struct V_48 * V_17 , unsigned int V_49 )
{
switch ( V_49 ) {
case V_23 :
case V_15 :
case V_50 :
case V_45 :
return true ;
default:
return false ;
}
}
static int F_19 ( struct V_51 * V_16 ,
const struct V_52 * V_53 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_5 * V_5 ;
int V_4 ;
V_28 = F_20 ( & V_16 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_28 )
return - V_54 ;
V_5 = F_21 ( V_16 , & V_55 ) ;
if ( F_22 ( V_5 ) ) {
F_7 ( & V_16 -> V_17 , L_3 ) ;
return F_23 ( V_5 ) ;
}
V_2 = F_12 ( V_28 ) ;
F_24 ( V_16 , V_28 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_5 = V_5 ;
F_25 ( & V_2 -> V_34 ) ;
V_4 = F_16 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_28 -> V_17 . V_56 = & V_16 -> V_17 ;
V_28 -> V_57 = V_58 ;
V_28 -> V_59 = F_26 ( V_58 ) ;
V_28 -> V_60 = V_61 ;
V_28 -> V_62 = V_63 ;
V_28 -> V_64 = & V_65 ;
V_4 = F_27 ( V_28 ) ;
if ( V_4 < 0 )
F_7 ( & V_16 -> V_17 , L_4 , V_66 ) ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_4 ;
F_13 ( & V_2 -> V_34 ) ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 |
V_9 ,
V_19 |
V_26 ) ;
if ( V_4 < 0 )
F_7 ( & V_2 -> V_16 -> V_17 , L_5 ) ;
F_14 ( & V_2 -> V_34 ) ;
return V_4 ;
}
static int F_29 ( struct V_51 * V_16 )
{
struct V_27 * V_28 = F_30 ( V_16 ) ;
struct V_1 * V_2 = F_12 ( V_28 ) ;
F_31 ( V_28 ) ;
return F_28 ( V_2 ) ;
}
static int F_32 ( struct V_48 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_12 ( F_30 ( F_33 ( V_17 ) ) ) ;
return F_28 ( V_2 ) ;
}
static int F_34 ( struct V_48 * V_17 )
{
int V_4 = 0 ;
struct V_1 * V_2 ;
V_2 = F_12 ( F_30 ( F_33 ( V_17 ) ) ) ;
F_13 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_8 ) {
V_4 = F_1 ( V_2 , V_13 ) ;
if ( V_4 < 0 ) {
F_7 ( V_17 , L_6 ) ;
goto V_67;
}
}
if ( V_2 -> V_10 ) {
V_4 = F_3 ( V_2 , V_21 ) ;
if ( V_4 < 0 )
F_7 ( V_17 , L_7 ) ;
}
V_67:
F_14 ( & V_2 -> V_34 ) ;
return V_4 ;
}
