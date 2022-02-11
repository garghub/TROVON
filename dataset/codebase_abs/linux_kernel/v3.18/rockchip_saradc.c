static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
switch ( V_7 ) {
case V_11 :
F_3 ( & V_2 -> V_12 ) ;
F_4 ( & V_9 -> V_13 ) ;
F_5 ( 8 , V_9 -> V_14 + V_15 ) ;
F_6 ( V_16
| ( V_4 -> V_17 & V_18 )
| V_19 ,
V_9 -> V_14 + V_20 ) ;
if ( ! F_7 ( & V_9 -> V_13 ,
V_21 ) ) {
F_5 ( 0 , V_9 -> V_14 + V_20 ) ;
F_8 ( & V_2 -> V_12 ) ;
return - V_22 ;
}
* V_5 = V_9 -> V_23 ;
F_8 ( & V_2 -> V_12 ) ;
return V_24 ;
case V_25 :
V_10 = F_9 ( V_9 -> V_26 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_2 -> V_27 , L_1 ) ;
return V_10 ;
}
* V_5 = V_10 / 1000 ;
* V_6 = V_28 ;
return V_29 ;
default:
return - V_30 ;
}
}
static T_1 F_11 ( int V_31 , void * V_32 )
{
struct V_8 * V_9 = (struct V_8 * ) V_32 ;
V_9 -> V_23 = F_12 ( V_9 -> V_14 + V_33 ) ;
V_9 -> V_23 &= V_34 ;
F_5 ( 0 , V_9 -> V_14 + V_20 ) ;
F_13 ( & V_9 -> V_13 ) ;
return V_35 ;
}
static int F_14 ( struct V_36 * V_37 )
{
struct V_8 * V_9 = NULL ;
struct V_38 * V_39 = V_37 -> V_27 . V_40 ;
struct V_1 * V_2 = NULL ;
struct V_41 * V_42 ;
int V_10 ;
int V_31 ;
if ( ! V_39 )
return - V_43 ;
V_2 = F_15 ( & V_37 -> V_27 , sizeof( * V_9 ) ) ;
if ( ! V_2 ) {
F_10 ( & V_37 -> V_27 , L_2 ) ;
return - V_44 ;
}
V_9 = F_2 ( V_2 ) ;
V_42 = F_16 ( V_37 , V_45 , 0 ) ;
V_9 -> V_14 = F_17 ( & V_37 -> V_27 , V_42 ) ;
if ( F_18 ( V_9 -> V_14 ) )
return F_19 ( V_9 -> V_14 ) ;
F_20 ( & V_9 -> V_13 ) ;
V_31 = F_21 ( V_37 , 0 ) ;
if ( V_31 < 0 ) {
F_10 ( & V_37 -> V_27 , L_3 ) ;
return V_31 ;
}
V_10 = F_22 ( & V_37 -> V_27 , V_31 , F_11 ,
0 , F_23 ( & V_37 -> V_27 ) , V_9 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_37 -> V_27 , L_4 , V_31 ) ;
return V_10 ;
}
V_9 -> V_46 = F_24 ( & V_37 -> V_27 , L_5 ) ;
if ( F_18 ( V_9 -> V_46 ) ) {
F_10 ( & V_37 -> V_27 , L_6 ) ;
return F_19 ( V_9 -> V_46 ) ;
}
V_9 -> V_47 = F_24 ( & V_37 -> V_27 , L_7 ) ;
if ( F_18 ( V_9 -> V_47 ) ) {
F_10 ( & V_37 -> V_27 , L_8 ) ;
return F_19 ( V_9 -> V_47 ) ;
}
V_9 -> V_26 = F_25 ( & V_37 -> V_27 , L_9 ) ;
if ( F_18 ( V_9 -> V_26 ) ) {
F_10 ( & V_37 -> V_27 , L_10 ,
F_19 ( V_9 -> V_26 ) ) ;
return F_19 ( V_9 -> V_26 ) ;
}
V_10 = F_26 ( V_9 -> V_47 , 1000000 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_37 -> V_27 , L_11 , V_10 ) ;
return V_10 ;
}
V_10 = F_27 ( V_9 -> V_26 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_37 -> V_27 , L_12 ) ;
return V_10 ;
}
V_10 = F_28 ( V_9 -> V_46 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_37 -> V_27 , L_13 ) ;
goto V_48;
}
V_10 = F_28 ( V_9 -> V_47 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_37 -> V_27 , L_14 ) ;
goto V_49;
}
F_29 ( V_37 , V_2 ) ;
V_2 -> V_50 = F_23 ( & V_37 -> V_27 ) ;
V_2 -> V_27 . V_51 = & V_37 -> V_27 ;
V_2 -> V_27 . V_40 = V_37 -> V_27 . V_40 ;
V_2 -> V_9 = & V_52 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = F_30 ( V_56 ) ;
V_10 = F_31 ( V_2 ) ;
if ( V_10 )
goto V_58;
return 0 ;
V_58:
F_32 ( V_9 -> V_47 ) ;
V_49:
F_32 ( V_9 -> V_46 ) ;
V_48:
F_33 ( V_9 -> V_26 ) ;
return V_10 ;
}
static int F_34 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_35 ( V_37 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_36 ( V_2 ) ;
F_32 ( V_9 -> V_47 ) ;
F_32 ( V_9 -> V_46 ) ;
F_33 ( V_9 -> V_26 ) ;
return 0 ;
}
static int F_37 ( struct V_59 * V_27 )
{
struct V_1 * V_2 = F_38 ( V_27 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_32 ( V_9 -> V_47 ) ;
F_32 ( V_9 -> V_46 ) ;
F_33 ( V_9 -> V_26 ) ;
return 0 ;
}
static int F_39 ( struct V_59 * V_27 )
{
struct V_1 * V_2 = F_38 ( V_27 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_27 ( V_9 -> V_26 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_28 ( V_9 -> V_46 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_28 ( V_9 -> V_47 ) ;
if ( V_10 )
return V_10 ;
return V_10 ;
}
