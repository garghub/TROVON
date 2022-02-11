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
F_4 ( V_6 ) ;
F_5 ( V_6 ) ;
F_6 ( & V_6 -> V_7 ) ;
if ( V_6 -> V_8 )
F_2 ( V_6 -> V_8 ) ;
}
}
static T_3 F_7 ( struct V_9 * V_7 ,
T_4 V_10 ,
void * V_3 )
{
T_3 V_11 = V_12 ;
F_8 ( & V_13 ) ;
if ( V_7 -> V_14 . V_15 . V_16 )
goto V_17;
V_11 = F_9 ( V_7 -> V_1 ,
V_18 ,
V_10 , V_3 ) ;
if ( F_10 ( V_11 ) )
goto V_17;
V_7 -> V_14 . V_15 . V_16 = true ;
V_17:
F_11 ( & V_13 ) ;
return V_11 ;
}
static T_3 F_12 ( struct V_9 * V_7 ,
T_4 V_10 )
{
T_3 V_11 = V_19 ;
F_8 ( & V_13 ) ;
if ( ! V_7 -> V_14 . V_15 . V_16 )
goto V_17;
V_11 = F_13 ( V_7 -> V_1 ,
V_18 ,
V_10 ) ;
if ( F_10 ( V_11 ) )
goto V_17;
V_7 -> V_14 . V_15 . V_16 = false ;
V_17:
F_11 ( & V_13 ) ;
return V_11 ;
}
T_3 F_14 ( struct V_9 * V_7 ,
struct V_4 * V_4 )
{
return F_7 ( V_7 , F_1 , V_4 ) ;
}
T_3 F_15 ( struct V_9 * V_7 )
{
return F_12 ( V_7 , F_1 ) ;
}
T_3 F_16 ( struct V_9 * V_7 ,
struct V_6 * V_6 )
{
return F_7 ( V_7 , F_3 , V_6 ) ;
}
T_3 F_17 ( struct V_9 * V_7 )
{
return F_12 ( V_7 , F_3 ) ;
}
static T_5 F_18 ( struct V_6 * V_20 )
{
int V_21 ;
V_21 = F_19 ( & V_20 -> V_7 , NULL ) ;
if ( V_21 < 0 )
return V_22 ;
switch ( V_21 ) {
case V_23 :
return V_24 ;
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
}
return V_22 ;
}
static bool F_20 ( struct V_6 * V_7 )
{
T_1 V_1 = F_21 ( & V_7 -> V_7 ) ;
return V_1 ? F_22 ( V_1 ) : false ;
}
static int F_23 ( struct V_6 * V_7 , T_5 V_33 )
{
T_1 V_1 = F_21 ( & V_7 -> V_7 ) ;
T_1 V_34 ;
static const T_6 V_35 [] = {
[ V_24 ] = V_23 ,
[ V_26 ] = V_25 ,
[ V_28 ] = V_27 ,
[ V_30 ] = V_29 ,
[ V_32 ] = V_29
} ;
int error = - V_36 ;
if ( ! V_1 || F_24 ( F_25 ( V_1 , L_1 , & V_34 ) ) )
return - V_37 ;
switch ( V_33 ) {
case V_24 :
case V_26 :
case V_28 :
case V_30 :
case V_32 :
error = F_26 ( V_1 , V_35 [ V_33 ] ) ;
}
if ( ! error )
F_27 ( V_38 , & V_7 -> V_7 ,
L_2 , V_33 ) ;
return error ;
}
static bool F_28 ( struct V_6 * V_7 )
{
T_1 V_1 = F_21 ( & V_7 -> V_7 ) ;
return V_1 ? F_29 ( V_1 ) : false ;
}
static void F_30 ( struct V_4 * V_39 , bool V_40 )
{
while ( V_39 -> V_41 ) {
if ( ! F_31 ( & V_39 -> V_42 -> V_7 , V_40 ) )
return;
V_39 = V_39 -> V_41 ;
}
if ( V_39 -> V_43 )
F_31 ( V_39 -> V_43 , V_40 ) ;
}
static int F_32 ( struct V_6 * V_7 , bool V_40 )
{
if ( F_28 ( V_7 ) )
return F_31 ( & V_7 -> V_7 , V_40 ) ;
F_30 ( V_7 -> V_39 , V_40 ) ;
return 0 ;
}
static int F_33 ( struct V_44 * V_45 , bool V_40 )
{
struct V_9 * V_7 ;
T_1 V_1 ;
int error = - V_37 ;
if ( ! F_34 ( V_45 ) )
return - V_36 ;
V_1 = F_21 ( V_45 ) ;
if ( ! V_1 || F_10 ( F_35 ( V_1 , & V_7 ) ) ) {
F_36 ( V_45 , L_3 ,
V_46 ) ;
return - V_37 ;
}
if ( V_40 ) {
F_37 ( V_7 , V_47 ) ;
F_38 ( V_7 -> V_14 . V_48 , V_7 -> V_14 . V_49 ) ;
} else {
F_39 ( V_7 -> V_14 . V_48 , V_7 -> V_14 . V_49 ) ;
F_40 ( V_7 ) ;
}
return error ;
}
static void F_41 ( struct V_4 * V_39 , bool V_40 )
{
while ( V_39 -> V_41 ) {
struct V_6 * V_43 = V_39 -> V_42 ;
if ( V_43 -> V_50 )
return;
if ( ! F_33 ( & V_43 -> V_7 , V_40 ) )
return;
V_39 = V_39 -> V_41 ;
}
if ( V_39 -> V_43 )
F_33 ( V_39 -> V_43 , V_40 ) ;
}
static int F_42 ( struct V_6 * V_7 , bool V_40 )
{
if ( V_7 -> V_50 )
return 0 ;
if ( ! F_33 ( & V_7 -> V_7 , V_40 ) )
return 0 ;
F_41 ( V_7 -> V_39 , V_40 ) ;
return 0 ;
}
static int F_43 ( struct V_44 * V_7 , T_1 * V_1 )
{
struct V_6 * V_6 ;
T_7 V_51 ;
V_6 = F_44 ( V_7 ) ;
V_51 = ( F_45 ( V_6 -> V_52 ) << 16 ) | F_46 ( V_6 -> V_52 ) ;
* V_1 = F_47 ( F_21 ( V_7 -> V_41 ) , V_51 ) ;
if ( ! * V_1 )
return - V_37 ;
return 0 ;
}
static int F_48 ( struct V_44 * V_7 , T_1 * V_1 )
{
int V_53 ;
unsigned int V_54 , V_39 ;
V_53 = sscanf ( F_49 ( V_7 ) , L_4 , & V_54 , & V_39 ) ;
if ( V_53 != 2 )
return - V_37 ;
* V_1 = F_50 ( V_54 , V_39 ) ;
if ( ! * V_1 )
return - V_37 ;
return 0 ;
}
static int T_8 F_51 ( void )
{
int V_55 ;
if ( V_56 . V_57 & V_58 ) {
F_52 ( V_38 L_5 ) ;
F_53 () ;
}
if ( V_56 . V_57 & V_59 ) {
F_52 ( V_38 L_6 ) ;
F_54 () ;
F_55 () ;
}
V_55 = F_56 ( & V_60 ) ;
if ( V_55 )
return 0 ;
F_57 ( & V_61 ) ;
return 0 ;
}
