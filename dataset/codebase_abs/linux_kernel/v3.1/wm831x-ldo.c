static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
int V_7 ;
V_7 = F_4 ( V_5 , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & V_6 )
return 1 ;
else
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
return F_6 ( V_5 , V_8 , V_6 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
return F_6 ( V_5 , V_8 , V_6 , 0 ) ;
}
static T_1 F_8 ( int V_9 , void * V_10 )
{
struct V_3 * V_4 = V_10 ;
F_9 ( V_4 -> V_11 ,
V_12 ,
NULL ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
if ( V_14 <= V_15 )
return 900000 + ( V_14 * 50000 ) ;
if ( V_14 <= V_16 )
return 1600000 + ( ( V_14 - V_15 )
* 100000 ) ;
return - V_17 ;
}
static int F_11 ( struct V_1 * V_2 , int V_7 ,
int V_18 , int V_19 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_20 , V_21 ;
if ( V_18 < 900000 )
V_20 = 0 ;
else if ( V_18 < 1700000 )
V_20 = ( ( V_18 - 900000 ) / 50000 ) ;
else
V_20 = ( ( V_18 - 1700000 ) / 100000 )
+ V_15 + 1 ;
V_21 = F_10 ( V_2 , V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 < V_18 || V_21 > V_19 )
return - V_17 ;
* V_14 = V_20 ;
return F_6 ( V_5 , V_7 , V_22 , V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
int V_18 , int V_19 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = V_4 -> V_23 + V_24 ;
return F_11 ( V_2 , V_7 , V_18 , V_19 ,
V_14 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = V_4 -> V_23 + V_26 ;
unsigned int V_14 ;
return F_11 ( V_2 , V_7 , V_25 , V_25 , & V_14 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_7 = V_4 -> V_23 + V_24 ;
int V_21 ;
V_21 = F_4 ( V_5 , V_7 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 &= V_22 ;
return V_21 ;
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_27 = V_4 -> V_23 + V_28 ;
int V_29 = V_4 -> V_23 + V_24 ;
int V_21 ;
V_21 = F_4 ( V_5 , V_29 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_21 & V_30 ) )
return V_31 ;
V_21 = F_4 ( V_5 , V_27 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 & V_32 )
return V_33 ;
else
return V_34 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_27 = V_4 -> V_23 + V_28 ;
int V_29 = V_4 -> V_23 + V_24 ;
int V_21 ;
switch ( V_35 ) {
case V_31 :
V_21 = F_6 ( V_5 , V_29 ,
V_30 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
case V_34 :
V_21 = F_6 ( V_5 , V_27 ,
V_32 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_5 , V_29 ,
V_30 ,
V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
case V_33 :
V_21 = F_6 ( V_5 , V_27 ,
V_32 ,
V_32 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_6 ( V_5 , V_29 ,
V_30 ,
V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
int V_21 ;
V_21 = F_4 ( V_5 , V_36 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_21 & V_6 ) )
return V_37 ;
V_21 = F_4 ( V_5 , V_38 ) ;
if ( V_21 & V_6 )
return V_39 ;
V_21 = F_15 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
else
return F_18 ( V_21 ) ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
int V_40 ,
int V_41 , int V_42 )
{
if ( V_42 < 20000 )
return V_33 ;
if ( V_42 < 50000 )
return V_34 ;
return V_31 ;
}
static T_2 int F_20 ( struct V_43 * V_44 )
{
struct V_5 * V_5 = F_21 ( V_44 -> V_45 . V_46 ) ;
struct V_47 * V_48 = V_5 -> V_45 -> V_49 ;
int V_50 ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
int V_21 , V_9 ;
if ( V_48 && V_48 -> V_53 )
V_50 = ( V_48 -> V_53 * 10 ) + 1 ;
else
V_50 = 0 ;
V_50 = V_44 -> V_50 - V_50 ;
F_22 ( & V_44 -> V_45 , L_1 , V_50 + 1 ) ;
if ( V_48 == NULL || V_48 -> V_4 [ V_50 ] == NULL )
return - V_54 ;
V_4 = F_23 ( sizeof( struct V_3 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_24 ( & V_44 -> V_45 , L_2 ) ;
return - V_56 ;
}
V_4 -> V_5 = V_5 ;
V_52 = F_25 ( V_44 , V_57 , 0 ) ;
if ( V_52 == NULL ) {
F_24 ( & V_44 -> V_45 , L_3 ) ;
V_21 = - V_17 ;
goto V_58;
}
V_4 -> V_23 = V_52 -> V_59 ;
snprintf ( V_4 -> V_60 , sizeof( V_4 -> V_60 ) , L_4 , V_50 + 1 ) ;
V_4 -> V_61 . V_60 = V_4 -> V_60 ;
V_4 -> V_61 . V_50 = V_50 ;
V_4 -> V_61 . type = V_62 ;
V_4 -> V_61 . V_63 = V_16 + 1 ;
V_4 -> V_61 . V_64 = & V_65 ;
V_4 -> V_61 . V_66 = V_67 ;
V_4 -> V_11 = F_26 ( & V_4 -> V_61 , & V_44 -> V_45 ,
V_48 -> V_4 [ V_50 ] , V_4 ) ;
if ( F_27 ( V_4 -> V_11 ) ) {
V_21 = F_28 ( V_4 -> V_11 ) ;
F_24 ( V_5 -> V_45 , L_5 ,
V_50 + 1 , V_21 ) ;
goto V_58;
}
V_9 = F_29 ( V_44 , L_6 ) ;
V_21 = F_30 ( V_9 , NULL , F_8 ,
V_68 , V_4 -> V_60 ,
V_4 ) ;
if ( V_21 != 0 ) {
F_24 ( & V_44 -> V_45 , L_7 ,
V_9 , V_21 ) ;
goto V_69;
}
F_31 ( V_44 , V_4 ) ;
return 0 ;
V_69:
F_32 ( V_4 -> V_11 ) ;
V_58:
F_33 ( V_4 ) ;
return V_21 ;
}
static T_3 int F_34 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = F_35 ( V_44 ) ;
F_31 ( V_44 , NULL ) ;
F_36 ( F_29 ( V_44 , L_6 ) , V_4 ) ;
F_32 ( V_4 -> V_11 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
if ( V_14 <= V_70 )
return 1000000 + ( V_14 * 50000 ) ;
if ( V_14 <= V_71 )
return 1600000 + ( ( V_14 - V_70 )
* 100000 ) ;
return - V_17 ;
}
static int F_38 ( struct V_1 * V_2 , int V_7 ,
int V_18 , int V_19 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_20 , V_21 ;
if ( V_18 < 1000000 )
V_20 = 0 ;
else if ( V_18 < 1700000 )
V_20 = ( ( V_18 - 1000000 ) / 50000 ) ;
else
V_20 = ( ( V_18 - 1700000 ) / 100000 )
+ V_70 + 1 ;
V_21 = F_37 ( V_2 , V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 < V_18 || V_21 > V_19 )
return - V_17 ;
* V_14 = V_20 ;
return F_6 ( V_5 , V_7 , V_72 , V_20 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
int V_18 , int V_19 , unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = V_4 -> V_23 + V_24 ;
return F_38 ( V_2 , V_7 , V_18 , V_19 ,
V_14 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
int V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = V_4 -> V_23 + V_26 ;
unsigned int V_14 ;
return F_38 ( V_2 , V_7 , V_25 , V_25 , & V_14 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_7 = V_4 -> V_23 + V_24 ;
int V_21 ;
V_21 = F_4 ( V_5 , V_7 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 &= V_72 ;
return V_21 ;
}
static unsigned int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_29 = V_4 -> V_23 + V_24 ;
int V_21 ;
V_21 = F_4 ( V_5 , V_29 ) ;
if ( V_21 < 0 )
return 0 ;
if ( V_21 & V_73 )
return V_34 ;
else
return V_31 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_27 = V_4 -> V_23 + V_28 ;
int V_29 = V_4 -> V_23 + V_24 ;
int V_21 ;
switch ( V_35 ) {
case V_31 :
V_21 = F_6 ( V_5 , V_29 ,
V_73 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
case V_34 :
V_21 = F_6 ( V_5 , V_27 ,
V_73 ,
V_73 ) ;
if ( V_21 < 0 )
return V_21 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
int V_21 ;
V_21 = F_4 ( V_5 , V_36 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! ( V_21 & V_6 ) )
return V_37 ;
V_21 = F_4 ( V_5 , V_38 ) ;
if ( V_21 & V_6 )
return V_39 ;
V_21 = F_42 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
else
return F_18 ( V_21 ) ;
}
static T_2 int F_45 ( struct V_43 * V_44 )
{
struct V_5 * V_5 = F_21 ( V_44 -> V_45 . V_46 ) ;
struct V_47 * V_48 = V_5 -> V_45 -> V_49 ;
int V_50 ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
int V_21 , V_9 ;
if ( V_48 && V_48 -> V_53 )
V_50 = ( V_48 -> V_53 * 10 ) + 1 ;
else
V_50 = 0 ;
V_50 = V_44 -> V_50 - V_50 ;
F_22 ( & V_44 -> V_45 , L_1 , V_50 + 1 ) ;
if ( V_48 == NULL || V_48 -> V_4 [ V_50 ] == NULL )
return - V_54 ;
V_4 = F_23 ( sizeof( struct V_3 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_24 ( & V_44 -> V_45 , L_2 ) ;
return - V_56 ;
}
V_4 -> V_5 = V_5 ;
V_52 = F_25 ( V_44 , V_57 , 0 ) ;
if ( V_52 == NULL ) {
F_24 ( & V_44 -> V_45 , L_3 ) ;
V_21 = - V_17 ;
goto V_58;
}
V_4 -> V_23 = V_52 -> V_59 ;
snprintf ( V_4 -> V_60 , sizeof( V_4 -> V_60 ) , L_4 , V_50 + 1 ) ;
V_4 -> V_61 . V_60 = V_4 -> V_60 ;
V_4 -> V_61 . V_50 = V_50 ;
V_4 -> V_61 . type = V_62 ;
V_4 -> V_61 . V_63 = V_71 + 1 ;
V_4 -> V_61 . V_64 = & V_74 ;
V_4 -> V_61 . V_66 = V_67 ;
V_4 -> V_11 = F_26 ( & V_4 -> V_61 , & V_44 -> V_45 ,
V_48 -> V_4 [ V_50 ] , V_4 ) ;
if ( F_27 ( V_4 -> V_11 ) ) {
V_21 = F_28 ( V_4 -> V_11 ) ;
F_24 ( V_5 -> V_45 , L_5 ,
V_50 + 1 , V_21 ) ;
goto V_58;
}
V_9 = F_29 ( V_44 , L_6 ) ;
V_21 = F_30 ( V_9 , NULL , F_8 ,
V_68 , V_4 -> V_60 , V_4 ) ;
if ( V_21 != 0 ) {
F_24 ( & V_44 -> V_45 , L_7 ,
V_9 , V_21 ) ;
goto V_69;
}
F_31 ( V_44 , V_4 ) ;
return 0 ;
V_69:
F_32 ( V_4 -> V_11 ) ;
V_58:
F_33 ( V_4 ) ;
return V_21 ;
}
static T_3 int F_46 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = F_35 ( V_44 ) ;
F_36 ( F_29 ( V_44 , L_6 ) , V_4 ) ;
F_32 ( V_4 -> V_11 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
if ( V_14 <= V_75 )
return 800000 + ( V_14 * 50000 ) ;
return - V_17 ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_7 ,
int V_18 , int V_19 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_20 , V_21 ;
V_20 = ( V_18 - 800000 ) / 50000 ;
V_21 = F_47 ( V_2 , V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 < V_18 || V_21 > V_19 )
return - V_17 ;
* V_14 = V_20 ;
return F_6 ( V_5 , V_7 , V_76 , V_20 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
int V_18 , int V_19 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = V_4 -> V_23 + V_77 ;
return F_48 ( V_2 , V_7 , V_18 , V_19 ,
V_14 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 = V_4 -> V_23 + V_78 ;
unsigned V_14 ;
return F_48 ( V_2 , V_7 , V_25 , V_25 , & V_14 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_7 = V_4 -> V_23 + V_77 ;
int V_21 ;
V_21 = F_4 ( V_5 , V_7 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 &= V_76 ;
return V_21 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
int V_21 ;
V_21 = F_4 ( V_5 , V_36 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 & V_6 )
return V_79 ;
else
return V_37 ;
}
static T_2 int F_53 ( struct V_43 * V_44 )
{
struct V_5 * V_5 = F_21 ( V_44 -> V_45 . V_46 ) ;
struct V_47 * V_48 = V_5 -> V_45 -> V_49 ;
int V_50 ;
struct V_3 * V_4 ;
struct V_51 * V_52 ;
int V_21 ;
if ( V_48 && V_48 -> V_53 )
V_50 = ( V_48 -> V_53 * 10 ) + 1 ;
else
V_50 = 0 ;
V_50 = V_44 -> V_50 - V_50 ;
F_22 ( & V_44 -> V_45 , L_1 , V_50 + 1 ) ;
if ( V_48 == NULL || V_48 -> V_4 [ V_50 ] == NULL )
return - V_54 ;
V_4 = F_23 ( sizeof( struct V_3 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_24 ( & V_44 -> V_45 , L_2 ) ;
return - V_56 ;
}
V_4 -> V_5 = V_5 ;
V_52 = F_25 ( V_44 , V_57 , 0 ) ;
if ( V_52 == NULL ) {
F_24 ( & V_44 -> V_45 , L_3 ) ;
V_21 = - V_17 ;
goto V_58;
}
V_4 -> V_23 = V_52 -> V_59 ;
snprintf ( V_4 -> V_60 , sizeof( V_4 -> V_60 ) , L_4 , V_50 + 1 ) ;
V_4 -> V_61 . V_60 = V_4 -> V_60 ;
V_4 -> V_61 . V_50 = V_50 ;
V_4 -> V_61 . type = V_62 ;
V_4 -> V_61 . V_63 = V_75 + 1 ;
V_4 -> V_61 . V_64 = & V_80 ;
V_4 -> V_61 . V_66 = V_67 ;
V_4 -> V_11 = F_26 ( & V_4 -> V_61 , & V_44 -> V_45 ,
V_48 -> V_4 [ V_50 ] , V_4 ) ;
if ( F_27 ( V_4 -> V_11 ) ) {
V_21 = F_28 ( V_4 -> V_11 ) ;
F_24 ( V_5 -> V_45 , L_5 ,
V_50 + 1 , V_21 ) ;
goto V_58;
}
F_31 ( V_44 , V_4 ) ;
return 0 ;
V_58:
F_33 ( V_4 ) ;
return V_21 ;
}
static T_3 int F_54 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = F_35 ( V_44 ) ;
F_32 ( V_4 -> V_11 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
int V_21 ;
V_21 = F_56 ( & V_81 ) ;
if ( V_21 != 0 )
F_57 ( L_8 , V_21 ) ;
V_21 = F_56 ( & V_82 ) ;
if ( V_21 != 0 )
F_57 ( L_9 , V_21 ) ;
V_21 = F_56 ( & V_83 ) ;
if ( V_21 != 0 )
F_57 ( L_10 ,
V_21 ) ;
return 0 ;
}
static void T_5 F_58 ( void )
{
F_59 ( & V_83 ) ;
F_59 ( & V_82 ) ;
F_59 ( & V_81 ) ;
}
