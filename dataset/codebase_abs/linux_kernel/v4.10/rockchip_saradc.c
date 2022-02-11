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
* V_6 = V_9 -> V_28 -> V_29 ;
return V_30 ;
default:
return - V_31 ;
}
}
static T_1 F_11 ( int V_32 , void * V_33 )
{
struct V_8 * V_9 = (struct V_8 * ) V_33 ;
V_9 -> V_23 = F_12 ( V_9 -> V_14 + V_34 ) ;
V_9 -> V_23 &= F_13 ( V_9 -> V_28 -> V_29 - 1 , 0 ) ;
F_5 ( 0 , V_9 -> V_14 + V_20 ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_35 ;
}
static void F_15 ( struct V_36 * V_37 )
{
F_16 ( V_37 ) ;
F_17 ( 10 , 20 ) ;
F_18 ( V_37 ) ;
}
static int F_19 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = NULL ;
struct V_40 * V_41 = V_39 -> V_27 . V_42 ;
struct V_1 * V_2 = NULL ;
struct V_43 * V_44 ;
const struct V_45 * V_46 ;
int V_10 ;
int V_32 ;
if ( ! V_41 )
return - V_47 ;
V_2 = F_20 ( & V_39 -> V_27 , sizeof( * V_9 ) ) ;
if ( ! V_2 ) {
F_10 ( & V_39 -> V_27 , L_2 ) ;
return - V_48 ;
}
V_9 = F_2 ( V_2 ) ;
V_46 = F_21 ( V_49 , & V_39 -> V_27 ) ;
V_9 -> V_28 = V_46 -> V_28 ;
V_44 = F_22 ( V_39 , V_50 , 0 ) ;
V_9 -> V_14 = F_23 ( & V_39 -> V_27 , V_44 ) ;
if ( F_24 ( V_9 -> V_14 ) )
return F_25 ( V_9 -> V_14 ) ;
V_9 -> V_37 = F_26 ( & V_39 -> V_27 , L_3 ) ;
if ( F_24 ( V_9 -> V_37 ) ) {
V_10 = F_25 ( V_9 -> V_37 ) ;
if ( V_10 != - V_51 )
return V_10 ;
F_27 ( & V_39 -> V_27 , L_4 ) ;
V_9 -> V_37 = NULL ;
}
F_28 ( & V_9 -> V_13 ) ;
V_32 = F_29 ( V_39 , 0 ) ;
if ( V_32 < 0 ) {
F_10 ( & V_39 -> V_27 , L_5 ) ;
return V_32 ;
}
V_10 = F_30 ( & V_39 -> V_27 , V_32 , F_11 ,
0 , F_31 ( & V_39 -> V_27 ) , V_9 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_39 -> V_27 , L_6 , V_32 ) ;
return V_10 ;
}
V_9 -> V_52 = F_32 ( & V_39 -> V_27 , L_7 ) ;
if ( F_24 ( V_9 -> V_52 ) ) {
F_10 ( & V_39 -> V_27 , L_8 ) ;
return F_25 ( V_9 -> V_52 ) ;
}
V_9 -> V_53 = F_32 ( & V_39 -> V_27 , L_9 ) ;
if ( F_24 ( V_9 -> V_53 ) ) {
F_10 ( & V_39 -> V_27 , L_10 ) ;
return F_25 ( V_9 -> V_53 ) ;
}
V_9 -> V_26 = F_33 ( & V_39 -> V_27 , L_11 ) ;
if ( F_24 ( V_9 -> V_26 ) ) {
F_10 ( & V_39 -> V_27 , L_12 ,
F_25 ( V_9 -> V_26 ) ) ;
return F_25 ( V_9 -> V_26 ) ;
}
if ( V_9 -> V_37 )
F_15 ( V_9 -> V_37 ) ;
V_10 = F_34 ( V_9 -> V_53 , V_9 -> V_28 -> V_54 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_39 -> V_27 , L_13 , V_10 ) ;
return V_10 ;
}
V_10 = F_35 ( V_9 -> V_26 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_39 -> V_27 , L_14 ) ;
return V_10 ;
}
V_10 = F_36 ( V_9 -> V_52 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_39 -> V_27 , L_15 ) ;
goto V_55;
}
V_10 = F_36 ( V_9 -> V_53 ) ;
if ( V_10 < 0 ) {
F_10 ( & V_39 -> V_27 , L_16 ) ;
goto V_56;
}
F_37 ( V_39 , V_2 ) ;
V_2 -> V_57 = F_31 ( & V_39 -> V_27 ) ;
V_2 -> V_27 . V_58 = & V_39 -> V_27 ;
V_2 -> V_27 . V_42 = V_39 -> V_27 . V_42 ;
V_2 -> V_9 = & V_59 ;
V_2 -> V_60 = V_61 ;
V_2 -> V_62 = V_9 -> V_28 -> V_62 ;
V_2 -> V_63 = V_9 -> V_28 -> V_63 ;
V_10 = F_38 ( V_2 ) ;
if ( V_10 )
goto V_64;
return 0 ;
V_64:
F_39 ( V_9 -> V_53 ) ;
V_56:
F_39 ( V_9 -> V_52 ) ;
V_55:
F_40 ( V_9 -> V_26 ) ;
return V_10 ;
}
static int F_41 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_42 ( V_39 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_43 ( V_2 ) ;
F_39 ( V_9 -> V_53 ) ;
F_39 ( V_9 -> V_52 ) ;
F_40 ( V_9 -> V_26 ) ;
return 0 ;
}
static int F_44 ( struct V_65 * V_27 )
{
struct V_1 * V_2 = F_45 ( V_27 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_39 ( V_9 -> V_53 ) ;
F_39 ( V_9 -> V_52 ) ;
F_40 ( V_9 -> V_26 ) ;
return 0 ;
}
static int F_46 ( struct V_65 * V_27 )
{
struct V_1 * V_2 = F_45 ( V_27 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_35 ( V_9 -> V_26 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_36 ( V_9 -> V_52 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_36 ( V_9 -> V_53 ) ;
if ( V_10 )
return V_10 ;
return V_10 ;
}
