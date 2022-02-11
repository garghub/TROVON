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
if ( V_6 -> V_7 == V_8 ) {
F_4 ( V_6 ) ;
F_5 ( & V_6 -> V_9 ) ;
return;
}
if ( V_6 -> V_10 )
F_6 ( V_6 ) ;
if ( V_6 -> V_11 )
V_6 -> V_11 = false ;
F_4 ( V_6 ) ;
F_5 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_12 )
F_2 ( V_6 -> V_12 ) ;
}
T_3 F_7 ( struct V_13 * V_9 ,
struct V_4 * V_4 )
{
return F_8 ( V_9 , F_1 , V_4 ) ;
}
T_3 F_9 ( struct V_13 * V_9 )
{
return F_10 ( V_9 , F_1 ) ;
}
T_3 F_11 ( struct V_13 * V_9 ,
struct V_6 * V_6 )
{
return F_8 ( V_9 , F_3 , V_6 ) ;
}
T_3 F_12 ( struct V_13 * V_9 )
{
return F_10 ( V_9 , F_3 ) ;
}
T_4 F_13 ( T_1 V_1 )
{
T_3 V_14 = V_15 ;
unsigned long long V_16 ;
if ( V_1 )
V_14 = F_14 ( V_1 , V_17 ,
NULL , & V_16 ) ;
if ( F_15 ( V_14 ) )
return 0 ;
return ( T_4 ) V_16 ;
}
static T_5 F_16 ( struct V_6 * V_18 )
{
int V_19 , V_20 ;
if ( V_18 -> V_21 )
V_20 = V_22 ;
else
V_20 = V_23 ;
V_19 = F_17 ( & V_18 -> V_9 , NULL , V_20 ) ;
if ( V_19 < 0 )
return V_24 ;
switch ( V_19 ) {
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_22 :
return V_31 ;
case V_23 :
return V_8 ;
}
return V_24 ;
}
static bool F_18 ( struct V_6 * V_9 )
{
T_1 V_1 = F_19 ( & V_9 -> V_9 ) ;
return V_1 ? F_20 ( V_1 ) : false ;
}
static int F_21 ( struct V_6 * V_9 , T_5 V_32 )
{
T_1 V_1 = F_19 ( & V_9 -> V_9 ) ;
T_1 V_33 ;
static const T_6 V_34 [] = {
[ V_26 ] = V_25 ,
[ V_28 ] = V_27 ,
[ V_30 ] = V_29 ,
[ V_31 ] = V_35 ,
[ V_8 ] = V_35
} ;
int error = - V_36 ;
if ( ! V_1 || F_22 ( F_23 ( V_1 , L_1 , & V_33 ) ) )
return - V_37 ;
switch ( V_32 ) {
case V_8 :
if ( F_24 ( & V_9 -> V_9 , V_38 ) ==
V_39 ) {
error = - V_40 ;
break;
}
case V_26 :
case V_28 :
case V_30 :
case V_31 :
error = F_25 ( V_1 , V_34 [ V_32 ] ) ;
}
if ( ! error )
F_26 ( & V_9 -> V_9 , L_2 ,
F_27 ( V_32 ) ) ;
return error ;
}
static bool F_28 ( struct V_6 * V_9 )
{
T_1 V_1 = F_19 ( & V_9 -> V_9 ) ;
return V_1 ? F_29 ( V_1 ) : false ;
}
static void F_30 ( struct V_4 * V_41 , bool V_42 )
{
while ( V_41 -> V_43 ) {
if ( ! F_31 ( & V_41 -> V_44 -> V_9 , V_42 ) )
return;
V_41 = V_41 -> V_43 ;
}
if ( V_41 -> V_45 )
F_31 ( V_41 -> V_45 , V_42 ) ;
}
static int F_32 ( struct V_6 * V_9 , bool V_42 )
{
if ( F_28 ( V_9 ) )
return F_31 ( & V_9 -> V_9 , V_42 ) ;
F_30 ( V_9 -> V_41 , V_42 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_41 , bool V_42 )
{
while ( V_41 -> V_43 ) {
struct V_6 * V_45 = V_41 -> V_44 ;
if ( V_45 -> V_46 )
return;
if ( ! F_34 ( & V_45 -> V_9 , V_42 ) )
return;
V_41 = V_41 -> V_43 ;
}
if ( V_41 -> V_45 )
F_34 ( V_41 -> V_45 , V_42 ) ;
}
static int F_35 ( struct V_6 * V_9 , bool V_42 )
{
if ( V_9 -> V_46 && ! V_9 -> V_47 )
return 0 ;
if ( ! F_34 ( & V_9 -> V_9 , V_42 ) )
return 0 ;
F_33 ( V_9 -> V_41 , V_42 ) ;
return 0 ;
}
static int F_36 ( struct V_48 * V_9 , T_1 * V_1 )
{
struct V_6 * V_6 ;
T_7 V_49 ;
V_6 = F_37 ( V_9 ) ;
V_49 = ( F_38 ( V_6 -> V_50 ) << 16 ) | F_39 ( V_6 -> V_50 ) ;
* V_1 = F_40 ( F_19 ( V_9 -> V_43 ) , V_49 ) ;
if ( ! * V_1 )
return - V_37 ;
return 0 ;
}
static void F_41 ( struct V_48 * V_9 )
{
struct V_6 * V_6 = F_37 ( V_9 ) ;
T_1 V_1 = F_42 ( V_9 ) ;
struct V_13 * V_51 ;
if ( F_43 ( V_1 , & V_51 ) || ! V_51 -> V_52 . V_53 . V_54 )
return;
F_44 ( V_9 , true ) ;
F_32 ( V_6 , false ) ;
F_11 ( V_51 , V_6 ) ;
if ( V_51 -> V_52 . V_53 . V_55 )
F_45 ( V_9 , true ) ;
}
static void F_46 ( struct V_48 * V_9 )
{
T_1 V_1 = F_42 ( V_9 ) ;
struct V_13 * V_51 ;
if ( ! F_43 ( V_1 , & V_51 ) && V_51 -> V_52 . V_53 . V_54 ) {
F_44 ( V_9 , false ) ;
F_45 ( V_9 , false ) ;
F_12 ( V_51 ) ;
}
}
static bool F_47 ( struct V_48 * V_9 )
{
return V_9 -> V_41 == & V_56 ;
}
static int T_8 F_48 ( void )
{
int V_57 ;
if ( V_58 . V_59 & V_60 ) {
F_49 ( V_61 L_3 ) ;
F_50 () ;
}
if ( V_58 . V_59 & V_62 ) {
F_49 ( V_61 L_4 ) ;
F_51 () ;
}
V_57 = F_52 ( & V_63 ) ;
if ( V_57 )
return 0 ;
F_53 ( & V_64 ) ;
return 0 ;
}
