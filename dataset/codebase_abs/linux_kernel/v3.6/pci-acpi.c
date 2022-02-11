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
static T_3 F_7 ( struct V_14 * V_9 ,
T_4 V_15 ,
void * V_3 )
{
T_3 V_16 = V_17 ;
F_8 ( & V_18 ) ;
if ( V_9 -> V_19 . V_20 . V_21 )
goto V_22;
V_16 = F_9 ( V_9 -> V_1 ,
V_23 ,
V_15 , V_3 ) ;
if ( F_10 ( V_16 ) )
goto V_22;
V_9 -> V_19 . V_20 . V_21 = true ;
V_22:
F_11 ( & V_18 ) ;
return V_16 ;
}
static T_3 F_12 ( struct V_14 * V_9 ,
T_4 V_15 )
{
T_3 V_16 = V_24 ;
F_8 ( & V_18 ) ;
if ( ! V_9 -> V_19 . V_20 . V_21 )
goto V_22;
V_16 = F_13 ( V_9 -> V_1 ,
V_23 ,
V_15 ) ;
if ( F_10 ( V_16 ) )
goto V_22;
V_9 -> V_19 . V_20 . V_21 = false ;
V_22:
F_11 ( & V_18 ) ;
return V_16 ;
}
T_3 F_14 ( struct V_14 * V_9 ,
struct V_4 * V_4 )
{
return F_7 ( V_9 , F_1 , V_4 ) ;
}
T_3 F_15 ( struct V_14 * V_9 )
{
return F_12 ( V_9 , F_1 ) ;
}
T_3 F_16 ( struct V_14 * V_9 ,
struct V_6 * V_6 )
{
return F_7 ( V_9 , F_3 , V_6 ) ;
}
T_3 F_17 ( struct V_14 * V_9 )
{
return F_12 ( V_9 , F_3 ) ;
}
T_5 F_18 ( T_1 V_1 )
{
T_3 V_16 = V_25 ;
unsigned long long V_26 ;
if ( V_1 )
V_16 = F_19 ( V_1 , V_27 ,
NULL , & V_26 ) ;
if ( F_10 ( V_16 ) )
return 0 ;
return ( T_5 ) V_26 ;
}
static T_6 F_20 ( struct V_6 * V_28 )
{
int V_29 , V_30 ;
if ( V_28 -> V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
V_29 = F_21 ( & V_28 -> V_9 , NULL , V_30 ) ;
if ( V_29 < 0 )
return V_34 ;
switch ( V_29 ) {
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_32 :
return V_41 ;
case V_33 :
return V_8 ;
}
return V_34 ;
}
static bool F_22 ( struct V_6 * V_9 )
{
T_1 V_1 = F_23 ( & V_9 -> V_9 ) ;
return V_1 ? F_24 ( V_1 ) : false ;
}
static int F_25 ( struct V_6 * V_9 , T_6 V_42 )
{
T_1 V_1 = F_23 ( & V_9 -> V_9 ) ;
T_1 V_43 ;
static const T_7 V_44 [] = {
[ V_36 ] = V_35 ,
[ V_38 ] = V_37 ,
[ V_40 ] = V_39 ,
[ V_41 ] = V_45 ,
[ V_8 ] = V_45
} ;
int error = - V_46 ;
if ( ! V_1 || F_26 ( F_27 ( V_1 , L_1 , & V_43 ) ) )
return - V_47 ;
switch ( V_42 ) {
case V_36 :
case V_38 :
case V_40 :
case V_41 :
case V_8 :
error = F_28 ( V_1 , V_44 [ V_42 ] ) ;
}
if ( ! error )
F_29 ( & V_9 -> V_9 , L_2 ,
F_30 ( V_42 ) ) ;
return error ;
}
static bool F_31 ( struct V_6 * V_9 )
{
T_1 V_1 = F_23 ( & V_9 -> V_9 ) ;
return V_1 ? F_32 ( V_1 ) : false ;
}
static void F_33 ( struct V_4 * V_48 , bool V_49 )
{
while ( V_48 -> V_50 ) {
if ( ! F_34 ( & V_48 -> V_51 -> V_9 , V_49 ) )
return;
V_48 = V_48 -> V_50 ;
}
if ( V_48 -> V_52 )
F_34 ( V_48 -> V_52 , V_49 ) ;
}
static int F_35 ( struct V_6 * V_9 , bool V_49 )
{
if ( F_31 ( V_9 ) )
return F_34 ( & V_9 -> V_9 , V_49 ) ;
F_33 ( V_9 -> V_48 , V_49 ) ;
return 0 ;
}
static void F_36 ( struct V_4 * V_48 , bool V_49 )
{
while ( V_48 -> V_50 ) {
struct V_6 * V_52 = V_48 -> V_51 ;
if ( V_52 -> V_53 )
return;
if ( ! F_37 ( & V_52 -> V_9 , V_49 ) )
return;
V_48 = V_48 -> V_50 ;
}
if ( V_48 -> V_52 )
F_37 ( V_48 -> V_52 , V_49 ) ;
}
static int F_38 ( struct V_6 * V_9 , bool V_49 )
{
if ( V_9 -> V_53 && ! V_9 -> V_54 )
return 0 ;
if ( ! F_37 ( & V_9 -> V_9 , V_49 ) )
return 0 ;
F_36 ( V_9 -> V_48 , V_49 ) ;
return 0 ;
}
static int F_39 ( struct V_55 * V_9 , T_1 * V_1 )
{
struct V_6 * V_6 ;
T_8 V_56 ;
V_6 = F_40 ( V_9 ) ;
V_56 = ( F_41 ( V_6 -> V_57 ) << 16 ) | F_42 ( V_6 -> V_57 ) ;
* V_1 = F_43 ( F_23 ( V_9 -> V_50 ) , V_56 ) ;
if ( ! * V_1 )
return - V_47 ;
return 0 ;
}
static int F_44 ( struct V_55 * V_9 , T_1 * V_1 )
{
int V_58 ;
unsigned int V_59 , V_48 ;
V_58 = sscanf ( F_45 ( V_9 ) , L_3 , & V_59 , & V_48 ) ;
if ( V_58 != 2 )
return - V_47 ;
* V_1 = F_46 ( V_59 , V_48 ) ;
if ( ! * V_1 )
return - V_47 ;
return 0 ;
}
static int T_9 F_47 ( void )
{
int V_60 ;
if ( V_61 . V_62 & V_63 ) {
F_48 ( V_64 L_4 ) ;
F_49 () ;
}
if ( V_61 . V_62 & V_65 ) {
F_48 ( V_64 L_5 ) ;
F_50 () ;
}
V_60 = F_51 ( & V_66 ) ;
if ( V_60 )
return 0 ;
F_52 ( & V_67 ) ;
return 0 ;
}
