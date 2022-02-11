static void F_1 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
if ( V_2 == V_5 && V_4 )
F_2 ( V_4 ) ;
}
static void F_3 ( T_1 V_1 , T_2 V_2 , void * V_3 )
{
struct V_6 * V_6 = V_3 ;
if ( V_2 != V_5 || ! V_6 )
return;
if ( ! V_6 -> V_7 || ! V_6 -> V_8
|| F_4 ( V_6 ) ) {
if ( V_6 -> V_9 )
V_6 -> V_9 = false ;
F_5 ( V_6 ) ;
F_6 ( & V_6 -> V_10 ) ;
}
if ( V_6 -> V_11 )
F_2 ( V_6 -> V_11 ) ;
}
static T_3 F_7 ( struct V_12 * V_10 ,
T_4 V_13 ,
void * V_3 )
{
T_3 V_14 = V_15 ;
F_8 ( & V_16 ) ;
if ( V_10 -> V_17 . V_18 . V_19 )
goto V_20;
V_14 = F_9 ( V_10 -> V_1 ,
V_21 ,
V_13 , V_3 ) ;
if ( F_10 ( V_14 ) )
goto V_20;
V_10 -> V_17 . V_18 . V_19 = true ;
V_20:
F_11 ( & V_16 ) ;
return V_14 ;
}
static T_3 F_12 ( struct V_12 * V_10 ,
T_4 V_13 )
{
T_3 V_14 = V_22 ;
F_8 ( & V_16 ) ;
if ( ! V_10 -> V_17 . V_18 . V_19 )
goto V_20;
V_14 = F_13 ( V_10 -> V_1 ,
V_21 ,
V_13 ) ;
if ( F_10 ( V_14 ) )
goto V_20;
V_10 -> V_17 . V_18 . V_19 = false ;
V_20:
F_11 ( & V_16 ) ;
return V_14 ;
}
T_3 F_14 ( struct V_12 * V_10 ,
struct V_4 * V_4 )
{
return F_7 ( V_10 , F_1 , V_4 ) ;
}
T_3 F_15 ( struct V_12 * V_10 )
{
return F_12 ( V_10 , F_1 ) ;
}
T_3 F_16 ( struct V_12 * V_10 ,
struct V_6 * V_6 )
{
return F_7 ( V_10 , F_3 , V_6 ) ;
}
T_3 F_17 ( struct V_12 * V_10 )
{
return F_12 ( V_10 , F_3 ) ;
}
static T_5 F_18 ( struct V_6 * V_23 )
{
int V_24 ;
V_24 = F_19 ( & V_23 -> V_10 , NULL ) ;
if ( V_24 < 0 )
return V_25 ;
switch ( V_24 ) {
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
}
return V_25 ;
}
static bool F_20 ( struct V_6 * V_10 )
{
T_1 V_1 = F_21 ( & V_10 -> V_10 ) ;
return V_1 ? F_22 ( V_1 ) : false ;
}
static int F_23 ( struct V_6 * V_10 , T_5 V_36 )
{
T_1 V_1 = F_21 ( & V_10 -> V_10 ) ;
T_1 V_37 ;
static const T_6 V_38 [] = {
[ V_27 ] = V_26 ,
[ V_29 ] = V_28 ,
[ V_31 ] = V_30 ,
[ V_33 ] = V_39 ,
[ V_35 ] = V_39
} ;
int error = - V_40 ;
if ( ! V_1 || F_24 ( F_25 ( V_1 , L_1 , & V_37 ) ) )
return - V_41 ;
switch ( V_36 ) {
case V_27 :
case V_29 :
case V_31 :
case V_33 :
case V_35 :
error = F_26 ( V_1 , V_38 [ V_36 ] ) ;
}
if ( ! error )
F_27 ( V_42 , & V_10 -> V_10 ,
L_2 , V_36 ) ;
return error ;
}
static bool F_28 ( struct V_6 * V_10 )
{
T_1 V_1 = F_21 ( & V_10 -> V_10 ) ;
return V_1 ? F_29 ( V_1 ) : false ;
}
static void F_30 ( struct V_4 * V_43 , bool V_44 )
{
while ( V_43 -> V_45 ) {
if ( ! F_31 ( & V_43 -> V_46 -> V_10 , V_44 ) )
return;
V_43 = V_43 -> V_45 ;
}
if ( V_43 -> V_47 )
F_31 ( V_43 -> V_47 , V_44 ) ;
}
static int F_32 ( struct V_6 * V_10 , bool V_44 )
{
if ( F_28 ( V_10 ) )
return F_31 ( & V_10 -> V_10 , V_44 ) ;
F_30 ( V_10 -> V_43 , V_44 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_43 , bool V_44 )
{
while ( V_43 -> V_45 ) {
struct V_6 * V_47 = V_43 -> V_46 ;
if ( V_47 -> V_48 )
return;
if ( ! F_34 ( & V_47 -> V_10 , V_44 ) )
return;
V_43 = V_43 -> V_45 ;
}
if ( V_43 -> V_47 )
F_34 ( V_43 -> V_47 , V_44 ) ;
}
static int F_35 ( struct V_6 * V_10 , bool V_44 )
{
if ( V_10 -> V_48 )
return 0 ;
if ( ! F_34 ( & V_10 -> V_10 , V_44 ) )
return 0 ;
F_33 ( V_10 -> V_43 , V_44 ) ;
return 0 ;
}
static int F_36 ( struct V_49 * V_10 , T_1 * V_1 )
{
struct V_6 * V_6 ;
T_7 V_50 ;
V_6 = F_37 ( V_10 ) ;
V_50 = ( F_38 ( V_6 -> V_51 ) << 16 ) | F_39 ( V_6 -> V_51 ) ;
* V_1 = F_40 ( F_21 ( V_10 -> V_45 ) , V_50 ) ;
if ( ! * V_1 )
return - V_41 ;
return 0 ;
}
static int F_41 ( struct V_49 * V_10 , T_1 * V_1 )
{
int V_52 ;
unsigned int V_53 , V_43 ;
V_52 = sscanf ( F_42 ( V_10 ) , L_3 , & V_53 , & V_43 ) ;
if ( V_52 != 2 )
return - V_41 ;
* V_1 = F_43 ( V_53 , V_43 ) ;
if ( ! * V_1 )
return - V_41 ;
return 0 ;
}
static int T_8 F_44 ( void )
{
int V_54 ;
if ( V_55 . V_56 & V_57 ) {
F_45 ( V_42 L_4 ) ;
F_46 () ;
}
if ( V_55 . V_56 & V_58 ) {
F_45 ( V_42 L_5 ) ;
F_47 () ;
}
V_54 = F_48 ( & V_59 ) ;
if ( V_54 )
return 0 ;
F_49 ( & V_60 ) ;
return 0 ;
}
