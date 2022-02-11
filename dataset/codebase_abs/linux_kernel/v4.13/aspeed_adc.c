static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 =
F_3 ( V_9 -> V_12 ) ;
switch ( V_7 ) {
case V_13 :
* V_5 = F_4 ( V_9 -> V_14 + V_4 -> V_15 ) ;
return V_16 ;
case V_17 :
* V_5 = V_11 -> V_18 ;
* V_6 = V_19 ;
return V_20 ;
case V_21 :
* V_5 = F_5 ( V_9 -> V_22 -> V_23 ) /
V_24 ;
return V_16 ;
default:
return - V_25 ;
}
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 =
F_3 ( V_9 -> V_12 ) ;
switch ( V_7 ) {
case V_21 :
if ( V_5 < V_11 -> V_26 ||
V_5 > V_11 -> V_27 )
return - V_25 ;
F_7 ( V_9 -> V_22 -> V_23 ,
V_5 * V_24 ) ;
return 0 ;
case V_17 :
case V_13 :
return - V_28 ;
default:
return - V_25 ;
}
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_29 , unsigned int V_30 ,
unsigned int * V_31 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_31 || V_29 % 4 || V_29 > V_32 )
return - V_25 ;
* V_31 = F_9 ( V_9 -> V_14 + V_29 ) ;
return 0 ;
}
static int F_10 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
struct V_35 * V_36 ;
const char * V_37 ;
int V_38 ;
T_1 V_39 ;
V_2 = F_11 ( & V_34 -> V_12 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_40 ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_12 = & V_34 -> V_12 ;
V_36 = F_12 ( V_34 , V_41 , 0 ) ;
V_9 -> V_14 = F_13 ( & V_34 -> V_12 , V_36 ) ;
if ( F_14 ( V_9 -> V_14 ) )
return F_15 ( V_9 -> V_14 ) ;
F_16 ( & V_9 -> V_42 ) ;
V_37 = F_17 ( V_34 -> V_12 . V_43 , 0 ) ;
V_9 -> V_44 = F_18 (
& V_34 -> V_12 , L_1 , V_37 , 0 ,
V_9 -> V_14 + V_45 ,
17 , 15 , 0 , & V_9 -> V_42 ) ;
if ( F_14 ( V_9 -> V_44 ) )
return F_15 ( V_9 -> V_44 ) ;
V_9 -> V_22 = F_18 (
& V_34 -> V_12 , L_2 , L_1 ,
V_46 ,
V_9 -> V_14 + V_45 ,
0 , 10 , 0 , & V_9 -> V_42 ) ;
if ( F_14 ( V_9 -> V_22 ) ) {
V_38 = F_15 ( V_9 -> V_22 ) ;
goto V_47;
}
V_11 = F_3 ( & V_34 -> V_12 ) ;
if ( V_11 -> V_48 ) {
F_19 ( V_49 | V_50 ,
V_9 -> V_14 + V_51 ) ;
V_38 = F_20 ( V_9 -> V_14 + V_51 ,
V_39 ,
V_39 &
V_52 ,
V_53 ,
V_54 ) ;
if ( V_38 )
goto V_47;
}
V_38 = F_21 ( V_9 -> V_22 -> V_23 ) ;
if ( V_38 )
goto V_55;
V_39 = F_22 ( 31 , 16 ) |
V_49 | V_50 ;
F_19 ( V_39 ,
V_9 -> V_14 + V_51 ) ;
V_11 = F_3 ( & V_34 -> V_12 ) ;
V_2 -> V_56 = V_11 -> V_57 ;
V_2 -> V_12 . V_58 = & V_34 -> V_12 ;
V_2 -> V_59 = & V_60 ;
V_2 -> V_61 = V_62 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = F_23 ( V_64 ) ;
V_38 = F_24 ( V_2 ) ;
if ( V_38 )
goto V_66;
return 0 ;
V_66:
F_19 ( V_67 ,
V_9 -> V_14 + V_51 ) ;
F_25 ( V_9 -> V_22 -> V_23 ) ;
V_55:
F_26 ( V_9 -> V_22 ) ;
V_47:
F_26 ( V_9 -> V_44 ) ;
return V_38 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_28 ( V_34 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_29 ( V_2 ) ;
F_19 ( V_67 ,
V_9 -> V_14 + V_51 ) ;
F_25 ( V_9 -> V_22 -> V_23 ) ;
F_26 ( V_9 -> V_22 ) ;
F_26 ( V_9 -> V_44 ) ;
return 0 ;
}
