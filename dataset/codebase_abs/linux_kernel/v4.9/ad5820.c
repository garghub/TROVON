static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
struct V_7 V_8 ;
int V_9 ;
if ( ! V_5 -> V_10 )
return - V_11 ;
V_3 = F_3 ( V_3 ) ;
V_8 . V_12 = V_5 -> V_12 ;
V_8 . V_13 = 0 ;
V_8 . V_14 = 2 ;
V_8 . V_15 = ( V_16 * ) & V_3 ;
V_9 = F_4 ( V_5 -> V_10 , & V_8 , 1 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_5 -> V_17 , L_1 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = F_7 ( V_2 -> V_19 ) ;
V_18 |= V_2 -> V_20
? V_21 : V_22 ;
V_18 |= V_2 -> V_23 << V_24 ;
if ( V_2 -> V_25 )
V_18 |= V_26 ;
return F_1 ( V_2 , V_18 ) ;
}
static int F_8 ( struct V_1 * V_2 , bool V_25 )
{
int V_27 = 0 , V_28 ;
if ( V_25 ) {
V_2 -> V_25 = true ;
V_27 = F_6 ( V_2 ) ;
}
V_28 = F_9 ( V_2 -> V_29 ) ;
if ( V_27 )
return V_27 ;
return V_28 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_30 )
{
int V_27 ;
V_27 = F_11 ( V_2 -> V_29 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_30 ) {
V_2 -> V_25 = false ;
V_27 = F_6 ( V_2 ) ;
if ( V_27 )
goto V_31;
}
return 0 ;
V_31:
V_2 -> V_25 = true ;
F_9 ( V_2 -> V_29 ) ;
return V_27 ;
}
static int F_12 ( struct V_32 * V_33 )
{
struct V_1 * V_2 =
F_13 ( V_33 -> V_34 , struct V_1 , V_35 ) ;
switch ( V_33 -> V_36 ) {
case V_37 :
V_2 -> V_23 = V_33 -> V_38 ;
return F_6 ( V_2 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_35 , 1 ) ;
F_16 ( & V_2 -> V_35 , & V_39 ,
V_37 , 0 , 1023 , 1 , 0 ) ;
if ( V_2 -> V_35 . error )
return V_2 -> V_35 . error ;
V_2 -> V_23 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_6 . V_40 = & V_2 -> V_35 ;
return 0 ;
}
static int F_17 ( struct V_41 * V_6 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
return F_14 ( V_2 ) ;
}
static int
F_19 ( struct V_41 * V_6 , int V_42 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
int V_27 = 0 ;
F_20 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_44 == ! V_42 ) {
V_27 = V_42 ? F_10 ( V_2 , true ) :
F_8 ( V_2 , true ) ;
if ( V_27 < 0 )
goto V_45;
}
V_2 -> V_44 += V_42 ? 1 : - 1 ;
F_21 ( V_2 -> V_44 < 0 ) ;
V_45:
F_22 ( & V_2 -> V_43 ) ;
return V_27 ;
}
static int F_23 ( struct V_41 * V_46 , struct V_47 * V_48 )
{
return F_19 ( V_46 , 1 ) ;
}
static int F_24 ( struct V_41 * V_46 , struct V_47 * V_48 )
{
return F_19 ( V_46 , 0 ) ;
}
static int T_2 F_25 ( struct V_49 * V_17 )
{
struct V_4 * V_5 = F_13 ( V_17 , struct V_4 , V_17 ) ;
struct V_41 * V_6 = F_26 ( V_5 ) ;
struct V_1 * V_2 = F_18 ( V_6 ) ;
if ( ! V_2 -> V_44 )
return 0 ;
return F_8 ( V_2 , false ) ;
}
static int T_2 F_27 ( struct V_49 * V_17 )
{
struct V_4 * V_5 = F_13 ( V_17 , struct V_4 , V_17 ) ;
struct V_41 * V_6 = F_26 ( V_5 ) ;
struct V_1 * V_2 = F_18 ( V_6 ) ;
if ( ! V_2 -> V_44 )
return 0 ;
return F_10 ( V_2 , true ) ;
}
static int F_28 ( struct V_4 * V_5 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_29 ( & V_5 -> V_17 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_29 = F_30 ( & V_5 -> V_17 , L_2 ) ;
if ( F_31 ( V_2 -> V_29 ) ) {
V_27 = F_32 ( V_2 -> V_29 ) ;
if ( V_27 != - V_54 )
F_5 ( & V_5 -> V_17 , L_3 ) ;
return V_27 ;
}
F_33 ( & V_2 -> V_43 ) ;
F_34 ( & V_2 -> V_6 , V_5 , & V_55 ) ;
V_2 -> V_6 . V_13 |= V_56 ;
V_2 -> V_6 . V_57 = & V_58 ;
strcpy ( V_2 -> V_6 . V_59 , L_4 ) ;
V_27 = F_35 ( & V_2 -> V_6 . V_60 , 0 , NULL ) ;
if ( V_27 < 0 )
goto V_61;
V_27 = F_36 ( & V_2 -> V_6 ) ;
if ( V_27 < 0 )
goto V_62;
return V_27 ;
V_61:
F_37 ( & V_2 -> V_43 ) ;
V_62:
F_38 ( & V_2 -> V_6 . V_60 ) ;
return V_27 ;
}
static int T_3 F_39 ( struct V_4 * V_5 )
{
struct V_41 * V_6 = F_26 ( V_5 ) ;
struct V_1 * V_2 = F_18 ( V_6 ) ;
F_40 ( & V_2 -> V_6 ) ;
F_41 ( & V_2 -> V_35 ) ;
F_38 ( & V_2 -> V_6 . V_60 ) ;
F_37 ( & V_2 -> V_43 ) ;
return 0 ;
}
