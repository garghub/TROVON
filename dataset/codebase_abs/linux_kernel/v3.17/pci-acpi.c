static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_7 . V_8 . V_2 ) ;
V_6 = F_3 ( V_4 ) ;
F_4 ( V_6 -> V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_8 ;
struct V_11 * V_11 ;
V_8 = F_2 ( V_2 , struct V_10 , V_2 ) ;
V_11 = F_6 ( V_8 -> V_12 ) ;
if ( V_11 -> V_13 )
V_11 -> V_13 = false ;
if ( V_11 -> V_14 == V_15 ) {
F_7 ( V_11 ) ;
F_8 ( & V_11 -> V_12 ) ;
return;
}
if ( V_11 -> V_16 )
F_9 ( V_11 ) ;
F_7 ( V_11 ) ;
F_8 ( & V_11 -> V_12 ) ;
if ( V_11 -> V_17 )
F_4 ( V_11 -> V_17 ) ;
}
T_1 F_10 ( struct V_3 * V_12 )
{
return F_11 ( V_12 , NULL , F_1 ) ;
}
T_1 F_12 ( struct V_3 * V_12 ,
struct V_11 * V_11 )
{
return F_11 ( V_12 , & V_11 -> V_12 , F_5 ) ;
}
T_2 F_13 ( T_3 V_18 )
{
T_1 V_19 = V_20 ;
unsigned long long V_21 ;
if ( V_18 )
V_19 = F_14 ( V_18 , V_22 ,
NULL , & V_21 ) ;
if ( F_15 ( V_19 ) )
return 0 ;
return ( T_2 ) V_21 ;
}
static T_4 F_16 ( struct V_11 * V_23 )
{
int V_24 , V_25 ;
if ( V_23 -> V_26 )
V_25 = V_27 ;
else
V_25 = V_28 ;
V_24 = F_17 ( & V_23 -> V_12 , NULL , V_25 ) ;
if ( V_24 < 0 )
return V_29 ;
switch ( V_24 ) {
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_27 :
return V_36 ;
case V_28 :
return V_15 ;
}
return V_29 ;
}
static bool F_18 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_19 ( & V_12 -> V_12 ) ;
return V_4 ? F_20 ( V_4 ) : false ;
}
static int F_21 ( struct V_11 * V_12 , T_4 V_37 )
{
struct V_3 * V_4 = F_19 ( & V_12 -> V_12 ) ;
static const T_5 V_38 [] = {
[ V_31 ] = V_30 ,
[ V_33 ] = V_32 ,
[ V_35 ] = V_34 ,
[ V_36 ] = V_28 ,
[ V_15 ] = V_28 ,
} ;
int error = - V_39 ;
if ( ! V_4 || F_22 ( V_4 -> V_18 , L_1 ) )
return - V_40 ;
switch ( V_37 ) {
case V_15 :
if ( F_23 ( & V_12 -> V_12 , V_41 ) ==
V_42 ) {
error = - V_43 ;
break;
}
case V_31 :
case V_33 :
case V_35 :
case V_36 :
error = F_24 ( V_4 , V_38 [ V_37 ] ) ;
}
if ( ! error )
F_25 ( & V_12 -> V_12 , L_2 ,
F_26 ( V_38 [ V_37 ] ) ) ;
return error ;
}
static bool F_27 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_19 ( & V_12 -> V_12 ) ;
return V_4 ? F_28 ( V_4 ) : false ;
}
static void F_29 ( struct V_44 * V_9 , bool V_45 )
{
while ( V_9 -> V_46 ) {
if ( ! F_30 ( & V_9 -> V_47 -> V_12 , V_45 ) )
return;
V_9 = V_9 -> V_46 ;
}
if ( V_9 -> V_48 )
F_30 ( V_9 -> V_48 , V_45 ) ;
}
static int F_31 ( struct V_11 * V_12 , bool V_45 )
{
if ( F_27 ( V_12 ) )
return F_30 ( & V_12 -> V_12 , V_45 ) ;
F_29 ( V_12 -> V_9 , V_45 ) ;
return 0 ;
}
static void F_32 ( struct V_44 * V_9 , bool V_45 )
{
while ( V_9 -> V_46 ) {
struct V_11 * V_48 = V_9 -> V_47 ;
if ( V_48 -> V_49 )
return;
if ( ! F_33 ( & V_48 -> V_12 , V_45 ) )
return;
V_9 = V_9 -> V_46 ;
}
if ( V_9 -> V_48 )
F_33 ( V_9 -> V_48 , V_45 ) ;
}
static int F_34 ( struct V_11 * V_12 , bool V_45 )
{
if ( V_12 -> V_49 && ! V_12 -> V_50 )
return 0 ;
if ( ! F_33 ( & V_12 -> V_12 , V_45 ) )
return 0 ;
F_32 ( V_12 -> V_9 , V_45 ) ;
return 0 ;
}
void F_35 ( struct V_44 * V_9 )
{
if ( V_51 || ! V_9 -> V_48 )
return;
F_36 ( V_9 ) ;
F_37 ( V_9 ) ;
}
void F_38 ( struct V_44 * V_9 )
{
if ( V_51 || ! V_9 -> V_48 )
return;
F_39 ( V_9 ) ;
F_40 ( V_9 ) ;
}
static struct V_3 * F_41 ( struct V_52 * V_12 )
{
struct V_11 * V_11 = F_6 ( V_12 ) ;
bool V_53 ;
T_6 V_54 ;
V_53 = F_42 ( V_11 ) ;
V_54 = ( F_43 ( V_11 -> V_55 ) << 16 ) | F_44 ( V_11 -> V_55 ) ;
return F_45 ( F_19 ( V_12 -> V_46 ) , V_54 ,
V_53 ) ;
}
static void F_46 ( struct V_52 * V_12 )
{
struct V_11 * V_11 = F_6 ( V_12 ) ;
struct V_3 * V_4 = F_19 ( V_12 ) ;
if ( ! V_4 )
return;
F_12 ( V_4 , V_11 ) ;
if ( ! V_4 -> V_7 . V_56 . V_57 )
return;
F_47 ( V_12 , true ) ;
F_31 ( V_11 , false ) ;
if ( V_4 -> V_7 . V_56 . V_58 )
F_48 ( V_12 , true ) ;
}
static void F_49 ( struct V_52 * V_12 )
{
struct V_3 * V_4 = F_19 ( V_12 ) ;
if ( ! V_4 )
return;
F_50 ( V_4 ) ;
if ( V_4 -> V_7 . V_56 . V_57 ) {
F_47 ( V_12 , false ) ;
F_48 ( V_12 , false ) ;
}
}
static bool F_51 ( struct V_52 * V_12 )
{
return F_52 ( V_12 ) ;
}
static int T_7 F_53 ( void )
{
int V_59 ;
if ( V_60 . V_61 & V_62 ) {
F_54 ( L_3 ) ;
F_55 () ;
}
if ( V_60 . V_61 & V_63 ) {
F_54 ( L_4 ) ;
F_56 () ;
}
V_59 = F_57 ( & V_64 ) ;
if ( V_59 )
return 0 ;
F_58 ( & V_65 ) ;
F_59 () ;
F_60 () ;
return 0 ;
}
