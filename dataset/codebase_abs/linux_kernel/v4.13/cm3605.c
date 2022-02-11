static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
T_2 V_6 ;
V_6 = F_3 ( V_7 , V_8 ,
V_9 , V_5 -> V_10 ) ;
F_4 ( V_4 , V_6 , F_5 ( V_4 ) ) ;
if ( V_5 -> V_10 == V_11 )
V_5 -> V_10 = V_12 ;
else
V_5 -> V_10 = V_11 ;
return V_13 ;
}
static int F_6 ( struct V_5 * V_5 )
{
int V_14 , V_15 ;
T_3 V_16 ;
V_14 = F_7 ( V_5 -> V_17 , & V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
F_8 ( V_5 -> V_18 , L_1 , V_15 ) ;
if ( V_15 < 30 )
return 0 ;
if ( V_15 > V_19 )
F_9 ( V_5 -> V_18 , L_2 ) ;
V_16 = V_15 - 30 ;
V_16 *= V_5 -> V_20 ;
V_16 = F_10 ( V_16 , V_21 ) ;
return V_16 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_22 const * V_23 ,
int * V_24 , int * V_25 , long V_26 )
{
struct V_5 * V_5 = F_2 ( V_4 ) ;
int V_14 ;
switch ( V_26 ) {
case V_27 :
switch ( V_23 -> type ) {
case V_28 :
V_14 = F_6 ( V_5 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_24 = V_14 ;
return V_29 ;
default:
return - V_30 ;
}
default:
return - V_30 ;
}
}
static int F_12 ( struct V_31 * V_32 )
{
struct V_5 * V_5 ;
struct V_3 * V_4 ;
struct V_33 * V_18 = & V_32 -> V_18 ;
struct V_34 * V_35 = V_18 -> V_36 ;
enum V_37 V_38 ;
T_4 V_39 ;
int V_14 ;
V_4 = F_13 ( V_18 , sizeof( * V_5 ) ) ;
if ( ! V_4 )
return - V_40 ;
F_14 ( V_32 , V_4 ) ;
V_5 = F_2 ( V_4 ) ;
V_5 -> V_18 = V_18 ;
V_5 -> V_10 = V_12 ;
V_14 = F_15 ( V_35 , L_3 , & V_39 ) ;
if ( V_14 ) {
F_16 ( V_18 , L_4 ) ;
V_39 = 100000 ;
}
switch ( V_39 ) {
case 50000 :
V_5 -> V_20 = 650 ;
break;
case 100000 :
V_5 -> V_20 = 300 ;
break;
case 300000 :
V_5 -> V_20 = 100 ;
break;
case 600000 :
V_5 -> V_20 = 50 ;
break;
default:
F_16 ( V_18 , L_5 ) ;
return - V_30 ;
}
V_5 -> V_17 = F_17 ( V_18 , L_6 ) ;
if ( F_18 ( V_5 -> V_17 ) ) {
if ( F_19 ( V_5 -> V_17 ) == - V_41 ) {
F_9 ( V_18 , L_7 ) ;
return - V_42 ;
}
F_9 ( V_18 , L_8 ) ;
return F_19 ( V_5 -> V_17 ) ;
}
V_14 = F_20 ( V_5 -> V_17 , & V_38 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_38 != V_43 ) {
F_9 ( V_18 , L_9 ) ;
return - V_30 ;
}
V_5 -> V_44 = F_21 ( V_18 , L_10 ) ;
if ( F_18 ( V_5 -> V_44 ) ) {
F_9 ( V_18 , L_11 ) ;
return F_19 ( V_5 -> V_44 ) ;
}
V_14 = F_22 ( V_5 -> V_44 ) ;
if ( V_14 ) {
F_9 ( V_18 , L_12 ) ;
return V_14 ;
}
V_5 -> V_45 = F_23 ( V_18 , L_13 , V_46 ) ;
if ( F_18 ( V_5 -> V_45 ) ) {
F_9 ( V_18 , L_14 ) ;
V_14 = F_19 ( V_5 -> V_45 ) ;
goto V_47;
}
V_14 = F_24 ( V_18 , F_25 ( V_32 , 0 ) ,
F_1 , NULL , 0 , L_15 , V_4 ) ;
if ( V_14 ) {
F_9 ( V_18 , L_16 ) ;
goto V_48;
}
F_26 ( L_15 , & V_5 -> V_49 ) ;
F_27 ( V_5 -> V_49 , V_50 ) ;
V_4 -> V_18 . V_51 = V_18 ;
V_4 -> V_52 = & V_53 ;
V_4 -> V_54 = L_15 ;
V_4 -> V_55 = V_56 ;
V_4 -> V_57 = F_28 ( V_56 ) ;
V_4 -> V_58 = V_59 ;
V_14 = F_29 ( V_4 ) ;
if ( V_14 )
goto V_60;
F_16 ( V_18 , L_17 ,
V_5 -> V_20 ) ;
return 0 ;
V_60:
F_27 ( V_5 -> V_49 , V_61 ) ;
F_30 ( V_5 -> V_49 ) ;
V_48:
F_31 ( V_5 -> V_45 , 0 ) ;
V_47:
F_32 ( V_5 -> V_44 ) ;
return V_14 ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_34 ( V_32 ) ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
F_27 ( V_5 -> V_49 , V_61 ) ;
F_30 ( V_5 -> V_49 ) ;
F_31 ( V_5 -> V_45 , 0 ) ;
F_35 ( V_4 ) ;
F_32 ( V_5 -> V_44 ) ;
return 0 ;
}
static int T_5 F_36 ( struct V_33 * V_18 )
{
struct V_3 * V_4 = F_37 ( V_18 ) ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
F_27 ( V_5 -> V_49 , V_61 ) ;
F_32 ( V_5 -> V_44 ) ;
return 0 ;
}
static int T_5 F_38 ( struct V_33 * V_18 )
{
struct V_3 * V_4 = F_37 ( V_18 ) ;
struct V_5 * V_5 = F_2 ( V_4 ) ;
int V_14 ;
V_14 = F_22 ( V_5 -> V_44 ) ;
if ( V_14 )
F_9 ( V_18 , L_18 ) ;
F_27 ( V_5 -> V_49 , V_50 ) ;
return 0 ;
}
