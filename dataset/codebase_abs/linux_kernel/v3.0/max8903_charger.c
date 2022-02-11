static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_2 ) ;
switch ( V_4 ) {
case V_9 :
V_6 -> V_10 = V_11 ;
if ( V_8 -> V_12 -> V_13 ) {
if ( F_3 ( V_8 -> V_12 -> V_13 ) == 0 )
V_6 -> V_10 = V_14 ;
else if ( V_8 -> V_15 || V_8 -> V_16 )
V_6 -> V_10 = V_17 ;
else
V_6 -> V_10 = V_18 ;
}
break;
case V_19 :
V_6 -> V_10 = 0 ;
if ( V_8 -> V_15 || V_8 -> V_16 )
V_6 -> V_10 = 1 ;
break;
case V_20 :
V_6 -> V_10 = V_21 ;
if ( V_8 -> V_22 )
V_6 -> V_10 = V_23 ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static T_1 F_4 ( int V_25 , void * V_26 )
{
struct V_7 * V_8 = V_26 ;
struct V_27 * V_12 = V_8 -> V_12 ;
bool V_16 ;
enum V_28 V_29 ;
V_16 = F_3 ( V_12 -> V_30 ) ? false : true ;
if ( V_16 == V_8 -> V_16 )
return V_31 ;
V_8 -> V_16 = V_16 ;
if ( V_12 -> V_32 )
F_5 ( V_12 -> V_32 , V_16 ? 1 : 0 ) ;
if ( V_12 -> V_33 )
F_5 ( V_12 -> V_33 , V_16 ? 0 :
( V_8 -> V_15 ? 0 : 1 ) ) ;
F_6 ( V_8 -> V_34 , L_1 , V_16 ?
L_2 : L_3 ) ;
V_29 = V_8 -> V_2 . type ;
if ( V_8 -> V_16 )
V_8 -> V_2 . type = V_35 ;
else if ( V_8 -> V_15 )
V_8 -> V_2 . type = V_36 ;
else
V_8 -> V_2 . type = V_37 ;
if ( V_29 != V_8 -> V_2 . type )
F_7 ( & V_8 -> V_2 ) ;
return V_31 ;
}
static T_1 F_8 ( int V_25 , void * V_26 )
{
struct V_7 * V_8 = V_26 ;
struct V_27 * V_12 = V_8 -> V_12 ;
bool V_15 ;
enum V_28 V_29 ;
V_15 = F_3 ( V_12 -> V_38 ) ? false : true ;
if ( V_15 == V_8 -> V_15 )
return V_31 ;
V_8 -> V_15 = V_15 ;
if ( V_12 -> V_33 )
F_5 ( V_12 -> V_33 , V_15 ? 0 :
( V_8 -> V_16 ? 0 : 1 ) ) ;
F_6 ( V_8 -> V_34 , L_4 , V_15 ?
L_2 : L_3 ) ;
V_29 = V_8 -> V_2 . type ;
if ( V_8 -> V_16 )
V_8 -> V_2 . type = V_35 ;
else if ( V_8 -> V_15 )
V_8 -> V_2 . type = V_36 ;
else
V_8 -> V_2 . type = V_37 ;
if ( V_29 != V_8 -> V_2 . type )
F_7 ( & V_8 -> V_2 ) ;
return V_31 ;
}
static T_1 F_9 ( int V_25 , void * V_26 )
{
struct V_7 * V_8 = V_26 ;
struct V_27 * V_12 = V_8 -> V_12 ;
bool V_22 ;
V_22 = F_3 ( V_12 -> V_39 ) ? false : true ;
if ( V_22 == V_8 -> V_22 )
return V_31 ;
V_8 -> V_22 = V_22 ;
if ( V_22 )
F_10 ( V_8 -> V_34 , L_5 ) ;
else
F_10 ( V_8 -> V_34 , L_6 ) ;
return V_31 ;
}
static T_2 int F_11 ( struct V_40 * V_41 )
{
struct V_7 * V_8 ;
struct V_42 * V_34 = & V_41 -> V_34 ;
struct V_27 * V_12 = V_41 -> V_34 . V_43 ;
int V_44 = 0 ;
int V_45 ;
int V_16 = 0 ;
int V_15 = 0 ;
V_8 = F_12 ( sizeof( struct V_7 ) , V_46 ) ;
if ( V_8 == NULL ) {
F_10 ( V_34 , L_7 ) ;
return - V_47 ;
}
V_8 -> V_12 = V_12 ;
V_8 -> V_34 = V_34 ;
F_13 ( V_41 , V_8 ) ;
if ( V_12 -> V_48 == false && V_12 -> V_49 == false ) {
F_10 ( V_34 , L_8 ) ;
V_44 = - V_24 ;
goto V_50;
}
if ( V_12 -> V_48 ) {
if ( V_12 -> V_30 && F_14 ( V_12 -> V_30 ) &&
V_12 -> V_32 && F_14 ( V_12 -> V_32 ) ) {
V_45 = V_12 -> V_30 ;
V_16 = F_3 ( V_45 ) ? 0 : 1 ;
V_45 = V_12 -> V_32 ;
F_5 ( V_45 , V_16 ) ;
} else {
F_10 ( V_34 , L_9
L_10 ) ;
V_44 = - V_24 ;
goto V_50;
}
} else {
if ( V_12 -> V_32 ) {
if ( F_14 ( V_12 -> V_32 ) )
F_5 ( V_12 -> V_32 , 0 ) ;
else {
F_10 ( V_34 , L_11 ) ;
V_44 = - V_24 ;
goto V_50;
}
}
}
if ( V_12 -> V_49 ) {
if ( V_12 -> V_38 && F_14 ( V_12 -> V_38 ) ) {
V_45 = V_12 -> V_38 ;
V_15 = F_3 ( V_45 ) ? 0 : 1 ;
} else {
F_10 ( V_34 , L_12
L_13 ) ;
V_44 = - V_24 ;
goto V_50;
}
}
if ( V_12 -> V_33 ) {
if ( F_14 ( V_12 -> V_33 ) ) {
F_5 ( V_12 -> V_33 , ( V_16 || V_15 ) ? 0 : 1 ) ;
} else {
F_10 ( V_34 , L_14 ) ;
V_44 = - V_24 ;
goto V_50;
}
}
if ( V_12 -> V_13 ) {
if ( ! F_14 ( V_12 -> V_13 ) ) {
F_10 ( V_34 , L_15 ) ;
V_44 = - V_24 ;
goto V_50;
}
}
if ( V_12 -> V_39 ) {
if ( ! F_14 ( V_12 -> V_39 ) ) {
F_10 ( V_34 , L_16 ) ;
V_44 = - V_24 ;
goto V_50;
}
}
if ( V_12 -> V_51 ) {
if ( ! F_14 ( V_12 -> V_51 ) ) {
F_10 ( V_34 , L_17 ) ;
V_44 = - V_24 ;
goto V_50;
}
}
V_8 -> V_22 = false ;
V_8 -> V_16 = V_16 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_2 . V_52 = L_18 ;
V_8 -> V_2 . type = ( V_16 ) ? V_35 :
( ( V_15 ) ? V_36 :
V_37 ) ;
V_8 -> V_2 . V_53 = F_1 ;
V_8 -> V_2 . V_54 = V_55 ;
V_8 -> V_2 . V_56 = F_15 ( V_55 ) ;
V_44 = F_16 ( V_34 , & V_8 -> V_2 ) ;
if ( V_44 ) {
F_10 ( V_34 , L_19 ) ;
goto V_50;
}
if ( V_12 -> V_48 ) {
V_44 = F_17 ( F_18 ( V_12 -> V_30 ) ,
NULL , F_4 ,
V_57 | V_58 ,
L_20 , V_8 ) ;
if ( V_44 ) {
F_10 ( V_34 , L_21 ,
F_18 ( V_12 -> V_30 ) , V_44 ) ;
goto V_59;
}
}
if ( V_12 -> V_49 ) {
V_44 = F_17 ( F_18 ( V_12 -> V_38 ) ,
NULL , F_8 ,
V_57 | V_58 ,
L_22 , V_8 ) ;
if ( V_44 ) {
F_10 ( V_34 , L_23 ,
F_18 ( V_12 -> V_38 ) , V_44 ) ;
goto V_60;
}
}
if ( V_12 -> V_39 ) {
V_44 = F_17 ( F_18 ( V_12 -> V_39 ) ,
NULL , F_9 ,
V_57 | V_58 ,
L_24 , V_8 ) ;
if ( V_44 ) {
F_10 ( V_34 , L_25 ,
F_18 ( V_12 -> V_39 ) , V_44 ) ;
goto V_61;
}
}
return 0 ;
V_61:
if ( V_12 -> V_49 )
F_19 ( F_18 ( V_12 -> V_38 ) , V_8 ) ;
V_60:
if ( V_12 -> V_48 )
F_19 ( F_18 ( V_12 -> V_30 ) , V_8 ) ;
V_59:
F_20 ( & V_8 -> V_2 ) ;
V_50:
F_21 ( V_8 ) ;
return V_44 ;
}
static T_3 int F_22 ( struct V_40 * V_41 )
{
struct V_7 * V_8 = F_23 ( V_41 ) ;
if ( V_8 ) {
struct V_27 * V_12 = V_8 -> V_12 ;
if ( V_12 -> V_39 )
F_19 ( F_18 ( V_12 -> V_39 ) , V_8 ) ;
if ( V_12 -> V_49 )
F_19 ( F_18 ( V_12 -> V_38 ) , V_8 ) ;
if ( V_12 -> V_48 )
F_19 ( F_18 ( V_12 -> V_30 ) , V_8 ) ;
F_20 ( & V_8 -> V_2 ) ;
F_21 ( V_8 ) ;
}
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_62 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_62 ) ;
}
