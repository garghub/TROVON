static void F_1 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
unsigned long V_4 = V_5 + F_2 ( 1000 ) ;
V_3 = F_3 ( V_1 -> V_6 , V_7 ) ;
if ( V_2 ) {
if ( V_1 -> V_8 -> V_9 == V_10 ) {
V_3 |= V_11 ;
F_4 ( V_1 -> V_6 , V_7 , V_3 ) ;
while ( F_3 ( V_1 -> V_6 , V_7 ) & 0x80 ) {
if ( F_5 ( V_5 , V_4 ) ) {
F_6 ( V_1 -> V_12 ,
L_1 ) ;
break;
}
}
} else {
V_1 -> V_13 = 1 ;
V_1 -> V_8 -> V_14 -> V_15 = 1 ;
V_1 -> V_8 -> V_9 = V_16 ;
V_3 |= V_11 ;
F_7 ( V_1 ) ;
}
} else {
V_1 -> V_13 = 0 ;
V_1 -> V_8 -> V_14 -> V_15 = 0 ;
V_3 &= ~ V_11 ;
F_8 ( V_1 ) ;
}
F_4 ( V_1 -> V_6 , V_7 , V_3 ) ;
if ( ! V_2 )
F_9 ( 200 ) ;
F_10 ( V_1 -> V_12 , L_2 ,
F_11 ( V_1 -> V_8 -> V_9 ) ,
F_3 ( V_1 -> V_6 , V_7 ) ) ;
}
static int F_12 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
struct V_1 * V_1 = F_13 ( V_18 , struct V_1 , V_18 ) ;
F_10 ( V_1 -> V_12 , L_3 ,
V_19 , F_11 ( V_1 -> V_8 -> V_9 ) ) ;
switch ( V_19 ) {
case V_21 :
F_10 ( V_1 -> V_12 , L_4 ) ;
F_1 ( V_1 , 1 ) ;
break;
case V_22 :
F_10 ( V_1 -> V_12 , L_5 ) ;
break;
case V_23 :
F_10 ( V_1 -> V_12 , L_6 ) ;
if ( F_14 ( V_1 ) )
F_1 ( V_1 , 0 ) ;
else
V_1 -> V_8 -> V_9 = V_24 ;
break;
default:
F_10 ( V_1 -> V_12 , L_7 ) ;
return V_25 ;
}
return V_26 ;
}
static T_2 F_15 ( int V_27 , void * V_28 )
{
unsigned long V_29 ;
T_2 V_30 = V_31 ;
struct V_1 * V_1 = V_28 ;
F_16 ( & V_1 -> V_32 , V_29 ) ;
V_1 -> V_33 = F_3 ( V_1 -> V_6 , V_34 ) ;
V_1 -> V_35 = F_17 ( V_1 -> V_6 , V_36 ) ;
V_1 -> V_37 = F_17 ( V_1 -> V_6 , V_38 ) ;
if ( V_1 -> V_33 || V_1 -> V_35 || V_1 -> V_37 )
V_30 = F_18 ( V_1 ) ;
F_19 ( & V_1 -> V_32 , V_29 ) ;
return V_30 ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_39 ;
V_1 -> V_8 = F_21 ( V_40 ) ;
if ( F_22 ( V_1 -> V_8 ) ) {
F_23 ( L_8 ) ;
return - V_41 ;
}
V_1 -> V_18 . V_42 = F_12 ;
V_39 = F_24 ( V_1 -> V_8 , & V_1 -> V_18 ) ;
if ( V_39 < 0 ) {
F_10 ( V_1 -> V_12 , L_9 ) ;
return V_39 ;
}
V_1 -> V_43 = F_15 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
F_26 ( V_1 -> V_8 , & V_1 -> V_18 ) ;
F_27 ( V_1 -> V_8 ) ;
return 0 ;
}
static int F_28 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_48 . V_49 ;
struct V_44 * V_1 ;
struct V_50 * V_51 ;
struct V_52 * V_52 ;
int V_53 = - V_54 ;
V_51 = F_29 ( sizeof( * V_51 ) , V_55 ) ;
if ( ! V_51 ) {
F_6 ( & V_45 -> V_48 , L_10 ) ;
goto V_56;
}
V_1 = F_30 ( L_11 , V_57 ) ;
if ( ! V_1 ) {
F_6 ( & V_45 -> V_48 , L_12 ) ;
goto V_58;
}
V_52 = F_31 ( & V_45 -> V_48 , L_13 ) ;
if ( F_32 ( V_52 ) ) {
F_6 ( & V_45 -> V_48 , L_14 ) ;
V_53 = F_33 ( V_52 ) ;
goto V_59;
}
V_53 = F_34 ( V_52 ) ;
if ( V_53 ) {
F_6 ( & V_45 -> V_48 , L_15 ) ;
goto V_60;
}
V_1 -> V_48 . V_61 = & V_45 -> V_48 ;
V_1 -> V_48 . V_62 = V_45 -> V_48 . V_62 ;
V_1 -> V_48 . V_63 = V_45 -> V_48 . V_63 ;
V_51 -> V_48 = & V_45 -> V_48 ;
V_51 -> V_1 = V_1 ;
V_51 -> V_52 = V_52 ;
V_47 -> V_64 = & V_65 ;
F_35 ( V_45 , V_51 ) ;
V_53 = F_36 ( V_1 , V_45 -> V_66 ,
V_45 -> V_67 ) ;
if ( V_53 ) {
F_6 ( & V_45 -> V_48 , L_16 ) ;
goto V_68;
}
V_53 = F_37 ( V_1 , V_47 , sizeof( * V_47 ) ) ;
if ( V_53 ) {
F_6 ( & V_45 -> V_48 , L_17 ) ;
goto V_68;
}
V_53 = F_38 ( V_1 ) ;
if ( V_53 ) {
F_6 ( & V_45 -> V_48 , L_18 ) ;
goto V_68;
}
return 0 ;
V_68:
F_39 ( V_52 ) ;
V_60:
F_40 ( V_52 ) ;
V_59:
F_41 ( V_1 ) ;
V_58:
F_42 ( V_51 ) ;
V_56:
return V_53 ;
}
static int F_43 ( struct V_44 * V_45 )
{
struct V_50 * V_51 = F_44 ( V_45 ) ;
F_45 ( V_51 -> V_1 ) ;
F_39 ( V_51 -> V_52 ) ;
F_40 ( V_51 -> V_52 ) ;
F_42 ( V_51 ) ;
return 0 ;
}
static int F_46 ( struct V_69 * V_48 )
{
struct V_50 * V_51 = F_47 ( V_48 ) ;
struct V_1 * V_1 = F_48 ( V_51 ) ;
F_49 ( V_1 -> V_8 , 1 ) ;
F_39 ( V_51 -> V_52 ) ;
return 0 ;
}
static int F_50 ( struct V_69 * V_48 )
{
struct V_50 * V_51 = F_47 ( V_48 ) ;
struct V_1 * V_1 = F_48 ( V_51 ) ;
int V_53 ;
V_53 = F_34 ( V_51 -> V_52 ) ;
if ( V_53 ) {
F_6 ( V_48 , L_15 ) ;
return V_53 ;
}
F_49 ( V_1 -> V_8 , 0 ) ;
return 0 ;
}
