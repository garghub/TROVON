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
if ( V_6 -> V_7 )
V_6 -> V_7 = false ;
if ( V_6 -> V_8 == V_9 ) {
F_4 ( V_6 ) ;
F_5 ( & V_6 -> V_10 ) ;
return;
}
if ( V_6 -> V_11 )
F_6 ( V_6 ) ;
F_4 ( V_6 ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( V_6 -> V_12 )
F_2 ( V_6 -> V_12 ) ;
}
T_3 F_7 ( struct V_13 * V_10 ,
struct V_4 * V_4 )
{
return F_8 ( V_10 , F_1 , V_4 ) ;
}
T_3 F_9 ( struct V_13 * V_10 )
{
return F_10 ( V_10 , F_1 ) ;
}
T_3 F_11 ( struct V_13 * V_10 ,
struct V_6 * V_6 )
{
return F_8 ( V_10 , F_3 , V_6 ) ;
}
T_3 F_12 ( struct V_13 * V_10 )
{
return F_10 ( V_10 , F_3 ) ;
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
V_19 = F_17 ( & V_18 -> V_10 , NULL , V_20 ) ;
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
return V_9 ;
}
return V_24 ;
}
static bool F_18 ( struct V_6 * V_10 )
{
T_1 V_1 = F_19 ( & V_10 -> V_10 ) ;
return V_1 ? F_20 ( V_1 ) : false ;
}
static int F_21 ( struct V_6 * V_10 , T_5 V_32 )
{
T_1 V_1 = F_19 ( & V_10 -> V_10 ) ;
T_1 V_33 ;
static const T_6 V_34 [] = {
[ V_26 ] = V_25 ,
[ V_28 ] = V_27 ,
[ V_30 ] = V_29 ,
[ V_31 ] = V_23 ,
[ V_9 ] = V_23 ,
} ;
int error = - V_35 ;
if ( ! V_1 || F_22 ( F_23 ( V_1 , L_1 , & V_33 ) ) )
return - V_36 ;
switch ( V_32 ) {
case V_9 :
if ( F_24 ( & V_10 -> V_10 , V_37 ) ==
V_38 ) {
error = - V_39 ;
break;
}
case V_26 :
case V_28 :
case V_30 :
case V_31 :
error = F_25 ( V_1 , V_34 [ V_32 ] ) ;
}
if ( ! error )
F_26 ( & V_10 -> V_10 , L_2 ,
F_27 ( V_34 [ V_32 ] ) ) ;
return error ;
}
static bool F_28 ( struct V_6 * V_10 )
{
T_1 V_1 = F_19 ( & V_10 -> V_10 ) ;
return V_1 ? F_29 ( V_1 ) : false ;
}
static void F_30 ( struct V_4 * V_40 , bool V_41 )
{
while ( V_40 -> V_42 ) {
if ( ! F_31 ( & V_40 -> V_43 -> V_10 , V_41 ) )
return;
V_40 = V_40 -> V_42 ;
}
if ( V_40 -> V_44 )
F_31 ( V_40 -> V_44 , V_41 ) ;
}
static int F_32 ( struct V_6 * V_10 , bool V_41 )
{
if ( F_28 ( V_10 ) )
return F_31 ( & V_10 -> V_10 , V_41 ) ;
F_30 ( V_10 -> V_40 , V_41 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_40 , bool V_41 )
{
while ( V_40 -> V_42 ) {
struct V_6 * V_44 = V_40 -> V_43 ;
if ( V_44 -> V_45 )
return;
if ( ! F_34 ( & V_44 -> V_10 , V_41 ) )
return;
V_40 = V_40 -> V_42 ;
}
if ( V_40 -> V_44 )
F_34 ( V_40 -> V_44 , V_41 ) ;
}
static int F_35 ( struct V_6 * V_10 , bool V_41 )
{
if ( V_10 -> V_45 && ! V_10 -> V_46 )
return 0 ;
if ( ! F_34 ( & V_10 -> V_10 , V_41 ) )
return 0 ;
F_33 ( V_10 -> V_40 , V_41 ) ;
return 0 ;
}
void F_36 ( struct V_4 * V_40 )
{
if ( V_47 || ! V_40 -> V_44 )
return;
F_37 ( V_40 ) ;
F_38 ( V_40 ) ;
}
void F_39 ( struct V_4 * V_40 )
{
if ( V_47 || ! V_40 -> V_44 )
return;
F_40 ( V_40 ) ;
F_41 ( V_40 ) ;
}
static int F_42 ( struct V_48 * V_10 , T_1 * V_1 )
{
struct V_6 * V_6 = F_43 ( V_10 ) ;
bool V_49 ;
T_7 V_50 ;
V_49 = V_6 -> V_51 == V_52
|| V_6 -> V_51 == V_53 ;
V_50 = ( F_44 ( V_6 -> V_54 ) << 16 ) | F_45 ( V_6 -> V_54 ) ;
* V_1 = F_46 ( F_47 ( V_10 -> V_42 ) , V_50 , V_49 ) ;
if ( ! * V_1 )
return - V_36 ;
return 0 ;
}
static void F_48 ( struct V_48 * V_10 )
{
struct V_6 * V_6 = F_43 ( V_10 ) ;
T_1 V_1 = F_47 ( V_10 ) ;
struct V_13 * V_55 ;
if ( F_49 ( V_1 , & V_55 ) || ! V_55 -> V_56 . V_57 . V_58 )
return;
F_50 ( V_10 , true ) ;
F_32 ( V_6 , false ) ;
F_11 ( V_55 , V_6 ) ;
if ( V_55 -> V_56 . V_57 . V_59 )
F_51 ( V_10 , true ) ;
}
static void F_52 ( struct V_48 * V_10 )
{
T_1 V_1 = F_47 ( V_10 ) ;
struct V_13 * V_55 ;
if ( ! F_49 ( V_1 , & V_55 ) && V_55 -> V_56 . V_57 . V_58 ) {
F_50 ( V_10 , false ) ;
F_51 ( V_10 , false ) ;
F_12 ( V_55 ) ;
}
}
static bool F_53 ( struct V_48 * V_10 )
{
return V_10 -> V_40 == & V_60 ;
}
static int T_8 F_54 ( void )
{
int V_61 ;
if ( V_62 . V_63 & V_64 ) {
F_55 ( L_3 ) ;
F_56 () ;
}
if ( V_62 . V_63 & V_65 ) {
F_55 ( L_4 ) ;
F_57 () ;
}
V_61 = F_58 ( & V_66 ) ;
if ( V_61 )
return 0 ;
F_59 ( & V_67 ) ;
F_60 () ;
F_61 () ;
return 0 ;
}
