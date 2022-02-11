static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
struct V_7 V_8 ;
T_2 V_9 ;
int V_10 ;
if ( ! V_5 -> V_11 )
return - V_12 ;
V_9 = F_3 ( V_3 ) ;
V_8 . V_13 = V_5 -> V_13 ;
V_8 . V_14 = 0 ;
V_8 . V_15 = 2 ;
V_8 . V_16 = ( V_17 * ) & V_9 ;
V_10 = F_4 ( V_5 -> V_11 , & V_8 , 1 ) ;
if ( V_10 < 0 ) {
F_5 ( & V_5 -> V_18 , L_1 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_19 ;
V_19 = F_7 ( V_2 -> V_20 ) ;
V_19 |= V_2 -> V_21
? V_22 : V_23 ;
V_19 |= V_2 -> V_24 << V_25 ;
if ( V_2 -> V_26 )
V_19 |= V_27 ;
return F_1 ( V_2 , V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 , bool V_26 )
{
int V_28 = 0 , V_29 ;
if ( V_26 ) {
V_2 -> V_26 = true ;
V_28 = F_6 ( V_2 ) ;
}
V_29 = F_9 ( V_2 -> V_30 ) ;
if ( V_28 )
return V_28 ;
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_31 )
{
int V_28 ;
V_28 = F_11 ( V_2 -> V_30 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_31 ) {
V_2 -> V_26 = false ;
V_28 = F_6 ( V_2 ) ;
if ( V_28 )
goto V_32;
}
return 0 ;
V_32:
V_2 -> V_26 = true ;
F_9 ( V_2 -> V_30 ) ;
return V_28 ;
}
static int F_12 ( struct V_33 * V_34 )
{
struct V_1 * V_2 =
F_13 ( V_34 -> V_35 , struct V_1 , V_36 ) ;
switch ( V_34 -> V_37 ) {
case V_38 :
V_2 -> V_24 = V_34 -> V_39 ;
return F_6 ( V_2 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_36 , 1 ) ;
F_16 ( & V_2 -> V_36 , & V_40 ,
V_38 , 0 , 1023 , 1 , 0 ) ;
if ( V_2 -> V_36 . error )
return V_2 -> V_36 . error ;
V_2 -> V_24 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_6 . V_41 = & V_2 -> V_36 ;
return 0 ;
}
static int F_17 ( struct V_42 * V_6 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
return F_14 ( V_2 ) ;
}
static int
F_19 ( struct V_42 * V_6 , int V_43 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
int V_28 = 0 ;
F_20 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_45 == ! V_43 ) {
V_28 = V_43 ? F_10 ( V_2 , true ) :
F_8 ( V_2 , true ) ;
if ( V_28 < 0 )
goto V_46;
}
V_2 -> V_45 += V_43 ? 1 : - 1 ;
F_21 ( V_2 -> V_45 < 0 ) ;
V_46:
F_22 ( & V_2 -> V_44 ) ;
return V_28 ;
}
static int F_23 ( struct V_42 * V_47 , struct V_48 * V_49 )
{
return F_19 ( V_47 , 1 ) ;
}
static int F_24 ( struct V_42 * V_47 , struct V_48 * V_49 )
{
return F_19 ( V_47 , 0 ) ;
}
static int T_3 F_25 ( struct V_50 * V_18 )
{
struct V_4 * V_5 = F_13 ( V_18 , struct V_4 , V_18 ) ;
struct V_42 * V_6 = F_26 ( V_5 ) ;
struct V_1 * V_2 = F_18 ( V_6 ) ;
if ( ! V_2 -> V_45 )
return 0 ;
return F_8 ( V_2 , false ) ;
}
static int T_3 F_27 ( struct V_50 * V_18 )
{
struct V_4 * V_5 = F_13 ( V_18 , struct V_4 , V_18 ) ;
struct V_42 * V_6 = F_26 ( V_5 ) ;
struct V_1 * V_2 = F_18 ( V_6 ) ;
if ( ! V_2 -> V_45 )
return 0 ;
return F_10 ( V_2 , true ) ;
}
static int F_28 ( struct V_4 * V_5 ,
const struct V_51 * V_52 )
{
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_29 ( & V_5 -> V_18 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_30 = F_30 ( & V_5 -> V_18 , L_2 ) ;
if ( F_31 ( V_2 -> V_30 ) ) {
V_28 = F_32 ( V_2 -> V_30 ) ;
if ( V_28 != - V_55 )
F_5 ( & V_5 -> V_18 , L_3 ) ;
return V_28 ;
}
F_33 ( & V_2 -> V_44 ) ;
F_34 ( & V_2 -> V_6 , V_5 , & V_56 ) ;
V_2 -> V_6 . V_14 |= V_57 ;
V_2 -> V_6 . V_58 = & V_59 ;
strcpy ( V_2 -> V_6 . V_60 , L_4 ) ;
V_28 = F_35 ( & V_2 -> V_6 . V_61 , 0 , NULL ) ;
if ( V_28 < 0 )
goto V_62;
V_28 = F_36 ( & V_2 -> V_6 ) ;
if ( V_28 < 0 )
goto V_63;
return V_28 ;
V_62:
F_37 ( & V_2 -> V_44 ) ;
V_63:
F_38 ( & V_2 -> V_6 . V_61 ) ;
return V_28 ;
}
static int F_39 ( struct V_4 * V_5 )
{
struct V_42 * V_6 = F_26 ( V_5 ) ;
struct V_1 * V_2 = F_18 ( V_6 ) ;
F_40 ( & V_2 -> V_6 ) ;
F_41 ( & V_2 -> V_36 ) ;
F_38 ( & V_2 -> V_6 . V_61 ) ;
F_37 ( & V_2 -> V_44 ) ;
return 0 ;
}
