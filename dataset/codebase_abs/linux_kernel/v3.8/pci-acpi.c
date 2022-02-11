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
if ( ! V_6 -> V_10 || ! V_6 -> V_11
|| F_6 ( V_6 ) ) {
if ( V_6 -> V_12 )
V_6 -> V_12 = false ;
F_4 ( V_6 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
if ( V_6 -> V_13 )
F_2 ( V_6 -> V_13 ) ;
}
T_3 F_7 ( struct V_14 * V_9 ,
struct V_4 * V_4 )
{
return F_8 ( V_9 , F_1 , V_4 ) ;
}
T_3 F_9 ( struct V_14 * V_9 )
{
return F_10 ( V_9 , F_1 ) ;
}
T_3 F_11 ( struct V_14 * V_9 ,
struct V_6 * V_6 )
{
return F_8 ( V_9 , F_3 , V_6 ) ;
}
T_3 F_12 ( struct V_14 * V_9 )
{
return F_10 ( V_9 , F_3 ) ;
}
T_4 F_13 ( T_1 V_1 )
{
T_3 V_15 = V_16 ;
unsigned long long V_17 ;
if ( V_1 )
V_15 = F_14 ( V_1 , V_18 ,
NULL , & V_17 ) ;
if ( F_15 ( V_15 ) )
return 0 ;
return ( T_4 ) V_17 ;
}
static T_5 F_16 ( struct V_6 * V_19 )
{
int V_20 , V_21 ;
if ( V_19 -> V_22 )
V_21 = V_23 ;
else
V_21 = V_24 ;
V_20 = F_17 ( & V_19 -> V_9 , NULL , V_21 ) ;
if ( V_20 < 0 )
return V_25 ;
switch ( V_20 ) {
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_23 :
return V_32 ;
case V_24 :
return V_8 ;
}
return V_25 ;
}
static bool F_18 ( struct V_6 * V_9 )
{
T_1 V_1 = F_19 ( & V_9 -> V_9 ) ;
return V_1 ? F_20 ( V_1 ) : false ;
}
static int F_21 ( struct V_6 * V_9 , T_5 V_33 )
{
T_1 V_1 = F_19 ( & V_9 -> V_9 ) ;
T_1 V_34 ;
static const T_6 V_35 [] = {
[ V_27 ] = V_26 ,
[ V_29 ] = V_28 ,
[ V_31 ] = V_30 ,
[ V_32 ] = V_36 ,
[ V_8 ] = V_36
} ;
int error = - V_37 ;
if ( ! V_1 || F_22 ( F_23 ( V_1 , L_1 , & V_34 ) ) )
return - V_38 ;
switch ( V_33 ) {
case V_8 :
if ( F_24 ( & V_9 -> V_9 , V_39 ) ==
V_40 ) {
error = - V_41 ;
break;
}
case V_27 :
case V_29 :
case V_31 :
case V_32 :
error = F_25 ( V_1 , V_35 [ V_33 ] ) ;
}
if ( ! error )
F_26 ( & V_9 -> V_9 , L_2 ,
F_27 ( V_33 ) ) ;
return error ;
}
static bool F_28 ( struct V_6 * V_9 )
{
T_1 V_1 = F_19 ( & V_9 -> V_9 ) ;
return V_1 ? F_29 ( V_1 ) : false ;
}
static void F_30 ( struct V_4 * V_42 , bool V_43 )
{
while ( V_42 -> V_44 ) {
if ( ! F_31 ( & V_42 -> V_45 -> V_9 , V_43 ) )
return;
V_42 = V_42 -> V_44 ;
}
if ( V_42 -> V_46 )
F_31 ( V_42 -> V_46 , V_43 ) ;
}
static int F_32 ( struct V_6 * V_9 , bool V_43 )
{
if ( F_28 ( V_9 ) )
return F_31 ( & V_9 -> V_9 , V_43 ) ;
F_30 ( V_9 -> V_42 , V_43 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_42 , bool V_43 )
{
while ( V_42 -> V_44 ) {
struct V_6 * V_46 = V_42 -> V_45 ;
if ( V_46 -> V_47 )
return;
if ( ! F_34 ( & V_46 -> V_9 , V_43 ) )
return;
V_42 = V_42 -> V_44 ;
}
if ( V_42 -> V_46 )
F_34 ( V_42 -> V_46 , V_43 ) ;
}
static int F_35 ( struct V_6 * V_9 , bool V_43 )
{
if ( V_9 -> V_47 && ! V_9 -> V_48 )
return 0 ;
if ( ! F_34 ( & V_9 -> V_9 , V_43 ) )
return 0 ;
F_33 ( V_9 -> V_42 , V_43 ) ;
return 0 ;
}
static int F_36 ( struct V_49 * V_9 , T_1 * V_1 )
{
struct V_6 * V_6 ;
T_7 V_50 ;
V_6 = F_37 ( V_9 ) ;
V_50 = ( F_38 ( V_6 -> V_51 ) << 16 ) | F_39 ( V_6 -> V_51 ) ;
* V_1 = F_40 ( F_19 ( V_9 -> V_44 ) , V_50 ) ;
if ( ! * V_1 )
return - V_38 ;
return 0 ;
}
static int F_41 ( struct V_49 * V_9 , T_1 * V_1 )
{
int V_52 ;
unsigned int V_53 , V_42 ;
V_52 = sscanf ( F_42 ( V_9 ) , L_3 , & V_53 , & V_42 ) ;
if ( V_52 != 2 )
return - V_38 ;
* V_1 = F_43 ( V_53 , V_42 ) ;
if ( ! * V_1 )
return - V_38 ;
return 0 ;
}
static int T_8 F_44 ( void )
{
int V_54 ;
if ( V_55 . V_56 & V_57 ) {
F_45 ( V_58 L_4 ) ;
F_46 () ;
}
if ( V_55 . V_56 & V_59 ) {
F_45 ( V_58 L_5 ) ;
F_47 () ;
}
V_54 = F_48 ( & V_60 ) ;
if ( V_54 )
return 0 ;
F_49 ( & V_61 ) ;
return 0 ;
}
