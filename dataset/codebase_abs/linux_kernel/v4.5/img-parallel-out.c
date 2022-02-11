static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_5 ( V_4 -> V_5 ) ;
if ( V_6 ) {
F_6 ( V_2 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static inline void F_7 ( struct V_3 * V_4 ,
T_1 V_7 , T_1 V_8 )
{
F_8 ( V_7 , V_4 -> V_9 + V_8 ) ;
}
static inline T_1 F_9 ( struct V_3 * V_4 , T_1 V_8 )
{
return F_10 ( V_4 -> V_9 + V_8 ) ;
}
static void F_11 ( struct V_3 * V_4 )
{
T_1 V_10 ;
V_10 = F_9 ( V_4 , V_11 ) &
~ V_12 ;
F_12 ( V_4 -> V_13 ) ;
F_13 ( V_4 -> V_13 ) ;
F_7 ( V_4 , V_10 , V_11 ) ;
}
static int F_14 ( struct V_14 * V_15 , int V_16 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = F_15 ( V_18 ) ;
T_1 V_8 ;
switch ( V_16 ) {
case V_19 :
case V_20 :
case V_21 :
V_8 = F_9 ( V_4 , V_11 ) ;
V_8 |= V_12 ;
F_7 ( V_4 , V_8 , V_11 ) ;
break;
case V_22 :
case V_23 :
case V_24 :
F_11 ( V_4 ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_16 ( struct V_14 * V_15 ,
struct V_26 * V_27 , struct V_17 * V_18 )
{
struct V_3 * V_4 = F_15 ( V_18 ) ;
unsigned int V_28 , V_29 ;
T_1 V_8 , V_30 = 0 ;
T_2 V_31 ;
V_28 = F_17 ( V_27 ) ;
V_31 = F_18 ( V_27 ) ;
V_29 = F_19 ( V_27 ) ;
switch ( F_18 ( V_27 ) ) {
case V_32 :
V_30 |= V_33 ;
break;
case V_34 :
break;
default:
return - V_25 ;
}
if ( V_29 != 2 )
return - V_25 ;
F_20 ( V_4 -> V_5 , V_28 * 256 ) ;
V_8 = F_9 ( V_4 , V_11 ) ;
V_8 = ( V_8 & ~ V_33 ) | V_30 ;
F_7 ( V_4 , V_8 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 , unsigned int V_35 )
{
struct V_3 * V_4 = F_15 ( V_18 ) ;
T_1 V_8 , V_30 = 0 ;
switch ( V_35 & V_36 ) {
case V_37 :
break;
case V_38 :
V_30 |= V_39 ;
break;
default:
return - V_25 ;
}
V_8 = F_9 ( V_4 , V_11 ) ;
V_8 = ( V_8 & ~ V_39 ) | V_30 ;
F_7 ( V_4 , V_8 , V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_15 ( V_18 ) ;
F_23 ( V_18 , & V_4 -> V_40 , NULL ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_3 * V_4 ;
struct V_43 * V_44 ;
void T_3 * V_9 ;
int V_6 ;
struct V_1 * V_2 = & V_42 -> V_2 ;
V_4 = F_25 ( & V_42 -> V_2 , sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
F_26 ( V_42 , V_4 ) ;
V_4 -> V_2 = & V_42 -> V_2 ;
V_44 = F_27 ( V_42 , V_47 , 0 ) ;
V_9 = F_28 ( & V_42 -> V_2 , V_44 ) ;
if ( F_29 ( V_9 ) )
return F_30 ( V_9 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_13 = F_31 ( & V_42 -> V_2 , L_2 ) ;
if ( F_29 ( V_4 -> V_13 ) ) {
if ( F_30 ( V_4 -> V_13 ) != - V_48 )
F_6 ( & V_42 -> V_2 , L_3 ) ;
return F_30 ( V_4 -> V_13 ) ;
}
V_4 -> V_49 = F_32 ( & V_42 -> V_2 , L_4 ) ;
if ( F_29 ( V_4 -> V_49 ) ) {
if ( F_30 ( V_4 -> V_49 ) != - V_48 )
F_6 ( V_2 , L_5 ) ;
return F_30 ( V_4 -> V_49 ) ;
}
V_4 -> V_5 = F_32 ( & V_42 -> V_2 , L_6 ) ;
if ( F_29 ( V_4 -> V_5 ) ) {
if ( F_30 ( V_4 -> V_5 ) != - V_48 )
F_6 ( V_2 , L_7 ) ;
return F_30 ( V_4 -> V_5 ) ;
}
V_6 = F_5 ( V_4 -> V_49 ) ;
if ( V_6 )
return V_6 ;
F_7 ( V_4 , V_39 , V_11 ) ;
F_11 ( V_4 ) ;
F_33 ( & V_42 -> V_2 ) ;
if ( ! F_34 ( & V_42 -> V_2 ) ) {
V_6 = F_4 ( & V_42 -> V_2 ) ;
if ( V_6 )
goto V_50;
}
V_4 -> V_40 . V_51 = V_44 -> V_52 + V_53 ;
V_4 -> V_40 . V_54 = 4 ;
V_4 -> V_40 . V_55 = 4 ;
V_6 = F_35 ( & V_42 -> V_2 ,
& V_56 ,
& V_57 , 1 ) ;
if ( V_6 )
goto V_58;
V_6 = F_36 ( & V_42 -> V_2 , NULL , 0 ) ;
if ( V_6 )
goto V_58;
return 0 ;
V_58:
if ( ! F_37 ( & V_42 -> V_2 ) )
F_1 ( & V_42 -> V_2 ) ;
V_50:
F_38 ( & V_42 -> V_2 ) ;
F_3 ( V_4 -> V_49 ) ;
return V_6 ;
}
static int F_39 ( struct V_41 * V_42 )
{
struct V_3 * V_4 = F_40 ( V_42 ) ;
F_38 ( & V_42 -> V_2 ) ;
if ( ! F_37 ( & V_42 -> V_2 ) )
F_1 ( & V_42 -> V_2 ) ;
F_3 ( V_4 -> V_49 ) ;
return 0 ;
}
