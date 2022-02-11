static void F_1 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
if ( V_2 == V_5 && V_4 )
F_2 ( V_4 ) ;
}
static void F_3 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_6 * V_6 = V_3 ;
if ( V_2 == V_5 && V_6 ) {
if ( V_6 -> V_7 )
V_6 -> V_7 = false ;
F_4 ( V_6 ) ;
F_5 ( V_6 ) ;
F_6 ( & V_6 -> V_8 ) ;
if ( V_6 -> V_9 )
F_2 ( V_6 -> V_9 ) ;
}
}
static T_3 F_7 ( struct V_10 * V_8 ,
T_4 V_11 ,
void * V_3 )
{
T_3 V_12 = V_13 ;
F_8 ( & V_14 ) ;
if ( V_8 -> V_15 . V_16 . V_17 )
goto V_18;
V_12 = F_9 ( V_8 -> V_1 ,
V_19 ,
V_11 , V_3 ) ;
if ( F_10 ( V_12 ) )
goto V_18;
V_8 -> V_15 . V_16 . V_17 = true ;
V_18:
F_11 ( & V_14 ) ;
return V_12 ;
}
static T_3 F_12 ( struct V_10 * V_8 ,
T_4 V_11 )
{
T_3 V_12 = V_20 ;
F_8 ( & V_14 ) ;
if ( ! V_8 -> V_15 . V_16 . V_17 )
goto V_18;
V_12 = F_13 ( V_8 -> V_1 ,
V_19 ,
V_11 ) ;
if ( F_10 ( V_12 ) )
goto V_18;
V_8 -> V_15 . V_16 . V_17 = false ;
V_18:
F_11 ( & V_14 ) ;
return V_12 ;
}
T_3 F_14 ( struct V_10 * V_8 ,
struct V_4 * V_4 )
{
return F_7 ( V_8 , F_1 , V_4 ) ;
}
T_3 F_15 ( struct V_10 * V_8 )
{
return F_12 ( V_8 , F_1 ) ;
}
T_3 F_16 ( struct V_10 * V_8 ,
struct V_6 * V_6 )
{
return F_7 ( V_8 , F_3 , V_6 ) ;
}
T_3 F_17 ( struct V_10 * V_8 )
{
return F_12 ( V_8 , F_3 ) ;
}
static T_5 F_18 ( struct V_6 * V_21 )
{
int V_22 ;
V_22 = F_19 ( & V_21 -> V_8 , NULL ) ;
if ( V_22 < 0 )
return V_23 ;
switch ( V_22 ) {
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
}
return V_23 ;
}
static bool F_20 ( struct V_6 * V_8 )
{
T_1 V_1 = F_21 ( & V_8 -> V_8 ) ;
return V_1 ? F_22 ( V_1 ) : false ;
}
static int F_23 ( struct V_6 * V_8 , T_5 V_34 )
{
T_1 V_1 = F_21 ( & V_8 -> V_8 ) ;
T_1 V_35 ;
static const T_6 V_36 [] = {
[ V_25 ] = V_24 ,
[ V_27 ] = V_26 ,
[ V_29 ] = V_28 ,
[ V_31 ] = V_30 ,
[ V_33 ] = V_30
} ;
int error = - V_37 ;
if ( ! V_1 || F_24 ( F_25 ( V_1 , L_1 , & V_35 ) ) )
return - V_38 ;
switch ( V_34 ) {
case V_25 :
case V_27 :
case V_29 :
case V_31 :
case V_33 :
error = F_26 ( V_1 , V_36 [ V_34 ] ) ;
}
if ( ! error )
F_27 ( V_39 , & V_8 -> V_8 ,
L_2 , V_34 ) ;
return error ;
}
static bool F_28 ( struct V_6 * V_8 )
{
T_1 V_1 = F_21 ( & V_8 -> V_8 ) ;
return V_1 ? F_29 ( V_1 ) : false ;
}
static void F_30 ( struct V_4 * V_40 , bool V_41 )
{
while ( V_40 -> V_42 ) {
if ( ! F_31 ( & V_40 -> V_43 -> V_8 , V_41 ) )
return;
V_40 = V_40 -> V_42 ;
}
if ( V_40 -> V_44 )
F_31 ( V_40 -> V_44 , V_41 ) ;
}
static int F_32 ( struct V_6 * V_8 , bool V_41 )
{
if ( F_28 ( V_8 ) )
return F_31 ( & V_8 -> V_8 , V_41 ) ;
F_30 ( V_8 -> V_40 , V_41 ) ;
return 0 ;
}
static int F_33 ( struct V_45 * V_46 , bool V_41 )
{
struct V_10 * V_8 ;
T_1 V_1 ;
if ( ! F_34 ( V_46 ) )
return - V_37 ;
V_1 = F_21 ( V_46 ) ;
if ( ! V_1 || F_10 ( F_35 ( V_1 , & V_8 ) ) ) {
F_36 ( V_46 , L_3 ,
V_47 ) ;
return - V_38 ;
}
if ( V_41 ) {
F_37 ( V_8 , V_48 ) ;
F_38 ( V_8 -> V_15 . V_49 , V_8 -> V_15 . V_50 ) ;
} else {
F_39 ( V_8 -> V_15 . V_49 , V_8 -> V_15 . V_50 ) ;
F_40 ( V_8 ) ;
}
return 0 ;
}
static void F_41 ( struct V_4 * V_40 , bool V_41 )
{
while ( V_40 -> V_42 ) {
struct V_6 * V_44 = V_40 -> V_43 ;
if ( V_44 -> V_51 )
return;
if ( ! F_33 ( & V_44 -> V_8 , V_41 ) )
return;
V_40 = V_40 -> V_42 ;
}
if ( V_40 -> V_44 )
F_33 ( V_40 -> V_44 , V_41 ) ;
}
static int F_42 ( struct V_6 * V_8 , bool V_41 )
{
if ( V_8 -> V_51 )
return 0 ;
if ( ! F_33 ( & V_8 -> V_8 , V_41 ) )
return 0 ;
F_41 ( V_8 -> V_40 , V_41 ) ;
return 0 ;
}
static int F_43 ( struct V_45 * V_8 , T_1 * V_1 )
{
struct V_6 * V_6 ;
T_7 V_52 ;
V_6 = F_44 ( V_8 ) ;
V_52 = ( F_45 ( V_6 -> V_53 ) << 16 ) | F_46 ( V_6 -> V_53 ) ;
* V_1 = F_47 ( F_21 ( V_8 -> V_42 ) , V_52 ) ;
if ( ! * V_1 )
return - V_38 ;
return 0 ;
}
static int F_48 ( struct V_45 * V_8 , T_1 * V_1 )
{
int V_54 ;
unsigned int V_55 , V_40 ;
V_54 = sscanf ( F_49 ( V_8 ) , L_4 , & V_55 , & V_40 ) ;
if ( V_54 != 2 )
return - V_38 ;
* V_1 = F_50 ( V_55 , V_40 ) ;
if ( ! * V_1 )
return - V_38 ;
return 0 ;
}
static int T_8 F_51 ( void )
{
int V_56 ;
if ( V_57 . V_58 & V_59 ) {
F_52 ( V_39 L_5 ) ;
F_53 () ;
}
if ( V_57 . V_58 & V_60 ) {
F_52 ( V_39 L_6 ) ;
F_54 () ;
F_55 () ;
}
V_56 = F_56 ( & V_61 ) ;
if ( V_56 )
return 0 ;
F_57 ( & V_62 ) ;
return 0 ;
}
