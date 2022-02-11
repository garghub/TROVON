static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 = V_4 ;
struct V_5 * V_6 = V_2 ;
unsigned int V_7 ;
if ( V_6 -> V_8 == V_9 ) {
F_2 ( V_6 -> V_10 , L_1 ) ;
return V_11 ;
}
V_7 = F_3 ( V_6 ) ;
F_4 ( V_6 , V_7 ) ;
if ( F_5 ( V_7 & F_6 ( V_6 ) ) ) {
F_7 ( V_6 -> V_10 , L_2 ) ;
F_8 ( V_6 -> V_12 ) ;
F_9 ( V_6 -> V_12 , V_13 ) ;
F_10 ( V_6 -> V_12 ) ;
return V_11 ;
}
return V_3 ;
}
static int F_11 ( struct V_14 * V_12 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_12 ( V_16 ) ;
struct V_5 * V_6 = V_18 -> V_19 . V_20 ;
struct V_21 * V_22 = V_12 -> V_22 ;
int V_23 , V_24 ;
int V_25 ;
int V_26 = 10 ;
if ( V_6 -> V_8 != V_9 ) {
F_7 ( V_6 -> V_10 , L_3 , V_27 ,
V_6 -> V_8 ) ;
return - V_28 ;
}
V_23 = V_22 -> V_29 * V_30 ;
if ( V_6 -> V_31 < V_32 )
V_24 = V_33 - V_23 ;
else
V_24 = V_23 ;
if ( ( ! V_24 % 2 ) ||
( V_24 != 1 && V_23 % 2 ) ||
( V_24 > F_13 ( V_6 ) ) ) {
F_7 ( V_6 -> V_10 , L_4 , V_24 ) ;
return - V_28 ;
}
F_14 ( V_6 , V_24 ) ;
switch ( V_6 -> V_34 & V_35 ) {
case V_36 :
case V_37 :
F_15 ( V_6 ) ;
break;
default:
F_16 ( V_6 ) ;
}
if ( ( V_6 -> V_34 & V_38 )
== V_39 ) {
V_25 = 32 ;
} else {
switch ( V_22 -> V_40 ) {
case V_41 :
V_25 = 16 ;
break;
default:
V_25 = 32 ;
break;
}
}
switch ( V_25 ) {
case 32 :
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
break;
case 16 :
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
break;
default:
F_7 ( V_6 -> V_10 , L_5 ) ;
return - V_28 ;
}
switch ( V_22 -> V_40 ) {
case V_41 :
F_21 ( V_6 ) ;
break;
case V_42 :
F_22 ( V_6 ) ;
break;
default:
F_7 ( V_6 -> V_10 , L_6 ) ;
return - V_28 ;
}
switch ( V_6 -> V_34 & V_38 ) {
case V_39 :
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
break;
case V_43 :
F_23 ( V_6 ) ;
F_25 ( V_6 ) ;
break;
case V_44 :
F_26 ( V_6 ) ;
F_25 ( V_6 ) ;
break;
default:
F_7 ( V_6 -> V_10 , L_6 ) ;
return - V_28 ;
}
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
if ( ( V_22 -> V_29 % 2 ) || ( V_22 -> V_29 < 2 ) ||
( V_22 -> V_29 > 10 ) ) {
F_7 ( V_6 -> V_10 , L_7 , V_27 ) ;
return - V_28 ;
}
F_29 ( V_6 , V_22 -> V_29 / 2 ) ;
F_4 ( V_6 , F_3 ( V_6 ) ) ;
F_30 ( V_6 , 0 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
if ( V_6 -> V_45 -> V_46 ) {
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_6 ) ;
while ( F_37 ( V_6 ) ) {
F_38 ( 5 ) ;
V_26 -- ;
}
if ( ! V_26 ) {
F_7 ( V_6 -> V_10 , L_8 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
if ( V_6 -> V_8 != V_9 ) {
F_7 ( V_6 -> V_10 , L_9 , V_27 ) ;
return - V_28 ;
}
F_40 ( V_6 ) ;
F_32 ( V_6 ) ;
F_41 ( V_6 ) ;
V_6 -> V_8 = V_48 ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
if ( V_6 -> V_8 == V_9 ) {
F_7 ( V_6 -> V_10 , L_9 , V_27 ) ;
return - V_28 ;
}
F_43 ( V_6 ) ;
F_44 ( V_6 , F_45 ( V_6 ) ) ;
V_6 -> V_8 = V_9 ;
return 0 ;
}
static int F_46 ( struct V_14 * V_12 ,
int V_49 , struct V_15 * V_16 )
{
struct V_17 * V_18 = F_12 ( V_16 ) ;
struct V_5 * V_6 = V_18 -> V_19 . V_20 ;
switch ( V_49 ) {
case V_50 :
return F_39 ( V_6 ) ;
case V_51 :
return F_42 ( V_6 ) ;
default:
return - V_28 ;
}
}
static void F_47 ( struct V_14 * V_12 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_12 ( V_16 ) ;
struct V_5 * V_6 = V_18 -> V_19 . V_20 ;
if ( V_6 -> V_8 != V_9 ) {
F_42 ( V_6 ) ;
}
}
static int F_48 ( struct V_52 * V_53 ,
struct V_5 * V_6 )
{
struct V_54 * V_45 ;
struct V_55 * V_56 = V_53 -> V_10 . V_57 ;
V_45 = F_49 ( & V_53 -> V_10 , sizeof( * V_45 ) , V_58 ) ;
if ( ! V_45 )
return - V_59 ;
if ( F_50 ( V_56 , L_10 , & V_6 -> V_31 ) ||
V_6 -> V_31 == V_60 ) {
F_7 ( & V_53 -> V_10 , L_11 ) ;
return - V_28 ;
}
V_6 -> V_45 = V_45 ;
return 0 ;
}
int F_51 ( struct V_52 * V_53 ,
struct V_5 * V_6 )
{
int V_3 = 0 ;
V_6 -> V_10 = & V_53 -> V_10 ;
V_6 -> V_8 = V_9 ;
V_6 -> V_61 = & V_62 ;
V_6 -> V_63 = & V_64 ;
V_3 = F_48 ( V_53 , V_6 ) ;
if ( V_3 < 0 ) {
F_7 ( V_6 -> V_10 , L_12 ) ;
return V_3 ;
}
V_3 = F_52 ( & V_53 -> V_10 , V_6 -> V_1 ,
F_1 , V_65 ,
F_53 ( & V_53 -> V_10 ) , V_6 ) ;
if ( V_3 < 0 ) {
F_7 ( & V_53 -> V_10 , L_13 ) ;
return - V_66 ;
}
return 0 ;
}
