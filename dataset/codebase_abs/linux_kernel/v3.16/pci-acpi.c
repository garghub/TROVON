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
static const T_6 V_33 [] = {
[ V_26 ] = V_25 ,
[ V_28 ] = V_27 ,
[ V_30 ] = V_29 ,
[ V_31 ] = V_23 ,
[ V_9 ] = V_23 ,
} ;
int error = - V_34 ;
if ( ! V_1 || F_22 ( V_1 , L_1 ) )
return - V_35 ;
switch ( V_32 ) {
case V_9 :
if ( F_23 ( & V_10 -> V_10 , V_36 ) ==
V_37 ) {
error = - V_38 ;
break;
}
case V_26 :
case V_28 :
case V_30 :
case V_31 :
error = F_24 ( V_1 , V_33 [ V_32 ] ) ;
}
if ( ! error )
F_25 ( & V_10 -> V_10 , L_2 ,
F_26 ( V_33 [ V_32 ] ) ) ;
return error ;
}
static bool F_27 ( struct V_6 * V_10 )
{
T_1 V_1 = F_19 ( & V_10 -> V_10 ) ;
return V_1 ? F_28 ( V_1 ) : false ;
}
static void F_29 ( struct V_4 * V_39 , bool V_40 )
{
while ( V_39 -> V_41 ) {
if ( ! F_30 ( & V_39 -> V_42 -> V_10 , V_40 ) )
return;
V_39 = V_39 -> V_41 ;
}
if ( V_39 -> V_43 )
F_30 ( V_39 -> V_43 , V_40 ) ;
}
static int F_31 ( struct V_6 * V_10 , bool V_40 )
{
if ( F_27 ( V_10 ) )
return F_30 ( & V_10 -> V_10 , V_40 ) ;
F_29 ( V_10 -> V_39 , V_40 ) ;
return 0 ;
}
static void F_32 ( struct V_4 * V_39 , bool V_40 )
{
while ( V_39 -> V_41 ) {
struct V_6 * V_43 = V_39 -> V_42 ;
if ( V_43 -> V_44 )
return;
if ( ! F_33 ( & V_43 -> V_10 , V_40 ) )
return;
V_39 = V_39 -> V_41 ;
}
if ( V_39 -> V_43 )
F_33 ( V_39 -> V_43 , V_40 ) ;
}
static int F_34 ( struct V_6 * V_10 , bool V_40 )
{
if ( V_10 -> V_44 && ! V_10 -> V_45 )
return 0 ;
if ( ! F_33 ( & V_10 -> V_10 , V_40 ) )
return 0 ;
F_32 ( V_10 -> V_39 , V_40 ) ;
return 0 ;
}
void F_35 ( struct V_4 * V_39 )
{
if ( V_46 || ! V_39 -> V_43 )
return;
F_36 ( V_39 ) ;
F_37 ( V_39 ) ;
}
void F_38 ( struct V_4 * V_39 )
{
if ( V_46 || ! V_39 -> V_43 )
return;
F_39 ( V_39 ) ;
F_40 ( V_39 ) ;
}
static struct V_13 * F_41 ( struct V_47 * V_10 )
{
struct V_6 * V_6 = F_42 ( V_10 ) ;
bool V_48 ;
T_7 V_49 ;
V_48 = F_43 ( V_6 ) ;
V_49 = ( F_44 ( V_6 -> V_50 ) << 16 ) | F_45 ( V_6 -> V_50 ) ;
return F_46 ( F_47 ( V_10 -> V_41 ) , V_49 ,
V_48 ) ;
}
static void F_48 ( struct V_47 * V_10 )
{
struct V_6 * V_6 = F_42 ( V_10 ) ;
struct V_13 * V_51 = F_47 ( V_10 ) ;
if ( ! V_51 )
return;
F_11 ( V_51 , V_6 ) ;
if ( ! V_51 -> V_52 . V_53 . V_54 )
return;
F_49 ( V_10 , true ) ;
F_31 ( V_6 , false ) ;
if ( V_51 -> V_52 . V_53 . V_55 )
F_50 ( V_10 , true ) ;
}
static void F_51 ( struct V_47 * V_10 )
{
struct V_13 * V_51 = F_47 ( V_10 ) ;
if ( ! V_51 )
return;
F_12 ( V_51 ) ;
if ( V_51 -> V_52 . V_53 . V_54 ) {
F_49 ( V_10 , false ) ;
F_50 ( V_10 , false ) ;
}
}
static bool F_52 ( struct V_47 * V_10 )
{
return F_53 ( V_10 ) ;
}
static int T_8 F_54 ( void )
{
int V_56 ;
if ( V_57 . V_58 & V_59 ) {
F_55 ( L_3 ) ;
F_56 () ;
}
if ( V_57 . V_58 & V_60 ) {
F_55 ( L_4 ) ;
F_57 () ;
}
V_56 = F_58 ( & V_61 ) ;
if ( V_56 )
return 0 ;
F_59 ( & V_62 ) ;
F_60 () ;
F_61 () ;
return 0 ;
}
