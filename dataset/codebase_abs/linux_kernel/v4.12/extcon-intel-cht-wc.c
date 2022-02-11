static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 & V_4 )
return V_5 ;
if ( V_3 & V_6 )
return V_7 ;
return V_7 ;
}
static int F_2 ( struct V_1 * V_2 ,
bool V_8 )
{
int V_9 , V_10 , V_11 ;
unsigned long V_12 ;
V_12 = V_13 + F_3 ( 800 ) ;
do {
V_9 = F_4 ( V_2 -> V_14 , V_15 , & V_10 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_1 , V_9 ) ;
return V_9 ;
}
V_11 = V_10 & V_17 ;
if ( V_11 == V_18 ||
V_11 == V_19 )
break;
F_6 ( 50 ) ;
} while ( F_7 ( V_13 , V_12 ) );
if ( V_11 != V_18 ) {
if ( V_8 )
return V_20 ;
if ( V_11 == V_19 )
F_8 ( V_2 -> V_16 , L_2 ) ;
else
F_8 ( V_2 -> V_16 , L_3 ) ;
return V_20 ;
}
V_10 = ( V_10 & V_21 ) >> V_22 ;
switch ( V_10 ) {
default:
F_8 ( V_2 -> V_16 ,
L_4 ,
V_9 ) ;
case V_23 :
case V_24 :
case V_25 :
return V_20 ;
case V_26 :
return V_27 ;
case V_28 :
case V_29 :
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 V_34 )
{
int V_9 ;
V_9 = F_10 ( V_2 -> V_14 , V_35 , V_34 ) ;
if ( V_9 )
F_5 ( V_2 -> V_16 , L_5 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
bool V_36 )
{
int V_9 , V_37 ;
V_37 = V_36 ? V_38 : 0 ;
V_9 = F_12 ( V_2 -> V_14 , V_39 ,
V_38 , V_37 ) ;
if ( V_9 )
F_5 ( V_2 -> V_16 , L_6 , V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_40 , bool V_34 )
{
F_14 ( V_2 -> V_41 , V_40 , V_34 ) ;
if ( V_40 == V_20 )
F_14 ( V_2 -> V_41 , V_42 , V_34 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_9 , V_3 , V_43 ;
unsigned int V_40 = V_44 ;
bool V_45 = V_2 -> V_46 ;
V_9 = F_4 ( V_2 -> V_14 , V_47 , & V_3 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_7 , V_9 ) ;
return;
}
V_43 = F_1 ( V_2 , V_3 ) ;
if ( V_43 == V_5 ) {
goto V_48;
}
if ( ! ( V_3 & V_49 ) ) {
F_9 ( V_2 , V_50 ) ;
goto V_51;
}
V_9 = F_2 ( V_2 , V_45 ) ;
if ( V_9 >= 0 )
V_40 = V_9 ;
V_48:
F_9 ( V_2 , V_52 ) ;
V_51:
if ( V_40 != V_2 -> V_53 ) {
F_13 ( V_2 , V_40 , true ) ;
F_13 ( V_2 , V_2 -> V_53 , false ) ;
V_2 -> V_53 = V_40 ;
}
V_2 -> V_46 = ( ( V_43 == V_5 ) || ( V_43 == V_54 ) ) ;
F_14 ( V_2 -> V_41 , V_55 , V_2 -> V_46 ) ;
}
static T_2 F_16 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
int V_9 , V_58 ;
V_9 = F_4 ( V_2 -> V_14 , V_59 , & V_58 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_8 , V_9 ) ;
return V_60 ;
}
F_15 ( V_2 ) ;
V_9 = F_10 ( V_2 -> V_14 , V_59 , V_58 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_9 , V_9 ) ;
return V_60 ;
}
return V_61 ;
}
static int F_17 ( struct V_1 * V_2 , bool V_36 )
{
int V_9 , V_62 , V_37 ;
V_62 = V_63 | V_64 ;
V_37 = V_36 ? V_62 : 0 ;
V_9 = F_12 ( V_2 -> V_14 , V_65 , V_62 , V_37 ) ;
if ( V_9 )
F_5 ( V_2 -> V_16 , L_10 , V_9 ) ;
return V_9 ;
}
static int F_18 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = F_19 ( V_67 -> V_16 . V_70 ) ;
struct V_1 * V_2 ;
int V_56 , V_9 ;
V_56 = F_20 ( V_67 , 0 ) ;
if ( V_56 < 0 )
return V_56 ;
V_2 = F_21 ( & V_67 -> V_16 , sizeof( * V_2 ) , V_71 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_16 = & V_67 -> V_16 ;
V_2 -> V_14 = V_69 -> V_14 ;
V_2 -> V_53 = V_44 ;
V_2 -> V_41 = F_22 ( V_2 -> V_16 , V_73 ) ;
if ( F_23 ( V_2 -> V_41 ) )
return F_24 ( V_2 -> V_41 ) ;
F_11 ( V_2 , false ) ;
V_9 = F_17 ( V_2 , true ) ;
if ( V_9 )
return V_9 ;
V_9 = F_25 ( V_2 -> V_16 , V_2 -> V_41 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_11 , V_9 ) ;
goto V_74;
}
F_9 ( V_2 , V_50 ) ;
F_15 ( V_2 ) ;
V_9 = F_26 ( V_2 -> V_16 , V_56 , NULL , F_16 ,
V_75 , V_67 -> V_76 , V_2 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_12 , V_9 ) ;
goto V_74;
}
V_9 = F_10 ( V_2 -> V_14 , V_77 ,
( int ) ~ ( V_49 | V_4 |
V_6 ) ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_16 , L_13 , V_9 ) ;
goto V_74;
}
F_27 ( V_67 , V_2 ) ;
return 0 ;
V_74:
F_17 ( V_2 , false ) ;
return V_9 ;
}
static int F_28 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_29 ( V_67 ) ;
F_17 ( V_2 , false ) ;
return 0 ;
}
