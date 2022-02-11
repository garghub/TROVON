static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_5 -> V_6 ) {
case V_7 :
return V_8 | V_9 ;
case V_10 :
return V_8 | V_11 ;
case V_12 :
case V_13 :
return V_14 ;
default:
return 0 ;
}
}
static bool F_3 ( struct V_1 * V_2 , T_1 V_15 )
{
return V_15 & V_9 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 -> V_6 = V_13 ;
F_5 () ;
F_6 ( V_4 -> V_16 ) ;
}
static unsigned int F_7 ( struct V_17 * V_5 )
{
return sizeof( * V_5 ) + sizeof( V_18 ) * V_5 -> V_19 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_20 , T_2 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_5 = V_4 -> V_5 ;
unsigned int V_22 = F_7 ( V_5 ) ;
V_18 V_23 ;
unsigned long V_24 ;
if ( V_22 > V_25 )
return - V_26 ;
if ( V_22 + V_21 > V_25 )
return - V_26 ;
if ( F_9 ( V_2 , V_8 , V_2 -> V_27 . V_28 ,
& V_2 -> V_27 . V_29 , true ) < 0 ) {
F_4 ( V_2 ) ;
return - V_30 ;
}
memcpy ( V_22 + ( T_1 * ) V_5 , V_20 , V_21 ) ;
V_5 -> V_31 = V_21 ;
F_10 () ;
V_5 -> V_6 = V_12 ;
F_5 () ;
F_6 ( V_4 -> V_16 ) ;
V_23 = F_11 ( ( (struct V_32 * ) V_20 ) -> V_23 ) ;
V_24 = F_12 ( V_2 , V_23 ) ;
if ( F_9 ( V_2 , V_8 , V_24 ,
& V_2 -> V_27 . V_29 , true ) < 0 ) {
F_4 ( V_2 ) ;
return - V_30 ;
}
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_20 , T_2 V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_17 * V_5 = V_4 -> V_5 ;
unsigned int V_22 = F_7 ( V_5 ) ;
T_2 V_31 = V_5 -> V_31 ;
if ( V_5 -> V_6 == V_7 )
return - V_33 ;
if ( F_9 ( V_2 , V_11 , V_2 -> V_27 . V_28 ,
& V_2 -> V_27 . V_29 , true ) < 0 ) {
F_4 ( V_2 ) ;
return - V_30 ;
}
if ( V_22 > V_25 )
return - V_34 ;
if ( V_22 + V_31 > V_25 )
V_31 = V_25 - V_22 ;
if ( V_31 > V_21 )
V_31 = V_21 ;
memcpy ( V_20 , V_22 + ( T_1 * ) V_5 , V_31 ) ;
return V_31 ;
}
static T_3 F_14 ( int V_35 , void * V_36 )
{
struct V_3 * V_4 = V_36 ;
switch ( V_4 -> V_5 -> V_6 ) {
case V_7 :
case V_10 :
F_15 ( & V_4 -> V_2 -> V_27 . V_29 ) ;
break;
case V_12 :
case V_13 :
default:
break;
}
return V_37 ;
}
static int F_16 ( struct V_38 * V_39 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_39 , & V_40 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_27 . V_29 ) ;
V_4 -> V_2 = V_2 ;
F_2 ( V_2 ) = V_4 ;
return 0 ;
}
static int F_21 ( struct V_41 * V_39 , struct V_3 * V_4 )
{
struct V_42 V_43 ;
const char * V_44 = NULL ;
int V_45 ;
V_4 -> V_5 = ( void * ) F_22 ( V_46 | V_47 ) ;
if ( ! V_4 -> V_5 ) {
F_23 ( V_39 , - V_48 , L_1 ) ;
return - V_48 ;
}
V_45 = F_24 ( V_39 , F_25 ( V_4 -> V_5 ) ) ;
if ( V_45 < 0 )
return V_45 ;
V_4 -> V_49 = V_45 ;
V_45 = F_26 ( V_39 , & V_4 -> V_16 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_27 ( V_4 -> V_16 , F_14 , 0 ,
L_2 , V_4 ) ;
if ( V_45 <= 0 ) {
F_23 ( V_39 , V_45 , L_3 ) ;
return V_45 ;
}
V_4 -> V_2 -> V_27 . V_50 = V_45 ;
V_51:
V_45 = F_28 ( & V_43 ) ;
if ( V_45 ) {
F_23 ( V_39 , V_45 , L_4 ) ;
return V_45 ;
}
V_45 = F_29 ( V_43 , V_39 -> V_52 ,
L_5 , L_6 , V_4 -> V_49 ) ;
if ( V_45 ) {
V_44 = L_7 ;
goto V_53;
}
V_45 = F_29 ( V_43 , V_39 -> V_52 , L_8 , L_6 ,
V_4 -> V_16 ) ;
if ( V_45 ) {
V_44 = L_9 ;
goto V_53;
}
V_45 = F_29 ( V_43 , V_39 -> V_52 , L_10 , L_11 ) ;
if ( V_45 ) {
V_44 = L_12 ;
goto V_53;
}
V_45 = F_30 ( V_43 , 0 ) ;
if ( V_45 == - V_54 )
goto V_51;
if ( V_45 ) {
F_23 ( V_39 , V_45 , L_13 ) ;
return V_45 ;
}
F_31 ( V_39 , V_55 ) ;
return 0 ;
V_53:
F_30 ( V_43 , 1 ) ;
if ( V_44 )
F_32 ( V_39 , V_45 , L_14 , V_44 ) ;
return V_45 ;
}
static void F_33 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_49 )
F_34 ( V_4 -> V_49 , 0 ,
( unsigned long ) V_4 -> V_5 ) ;
else
F_35 ( ( unsigned long ) V_4 -> V_5 ) ;
if ( V_4 -> V_2 && V_4 -> V_2 -> V_27 . V_50 )
F_36 ( V_4 -> V_2 -> V_27 . V_50 , V_4 ) ;
F_37 ( V_4 ) ;
}
static int F_38 ( struct V_41 * V_39 ,
const struct V_56 * V_57 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_45 ;
V_4 = F_39 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 ) {
F_23 ( V_39 , - V_48 , L_15 ) ;
return - V_48 ;
}
V_45 = F_16 ( & V_39 -> V_39 , V_4 ) ;
if ( V_45 ) {
F_37 ( V_4 ) ;
return V_45 ;
}
V_45 = F_21 ( V_39 , V_4 ) ;
if ( V_45 ) {
V_2 = F_40 ( & V_39 -> V_39 ) ;
F_41 ( V_2 ) ;
F_33 ( V_4 ) ;
return V_45 ;
}
F_42 ( V_4 -> V_2 ) ;
return F_43 ( V_4 -> V_2 ) ;
}
static int F_44 ( struct V_41 * V_39 )
{
struct V_1 * V_2 = F_40 ( & V_39 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_41 ( V_2 ) ;
F_33 ( V_4 ) ;
F_2 ( V_2 ) = NULL ;
return 0 ;
}
static int F_45 ( struct V_41 * V_39 )
{
F_44 ( V_39 ) ;
return F_38 ( V_39 , NULL ) ;
}
static void F_46 ( struct V_41 * V_39 ,
enum V_58 V_59 )
{
int V_60 ;
switch ( V_59 ) {
case V_55 :
case V_61 :
if ( V_39 -> V_6 == V_61 )
break;
if ( F_47 ( V_62 , V_39 -> V_63 ,
L_10 , L_16 , & V_60 ) < 0 )
V_60 = 0 ;
if ( ! V_60 ) {
F_23 ( V_39 , - V_26 ,
L_17 ) ;
return;
}
F_31 ( V_39 , V_61 ) ;
break;
case V_64 :
case V_65 :
F_48 ( & V_39 -> V_39 ) ;
F_49 ( V_39 ) ;
break;
default:
break;
}
}
static int T_4 F_50 ( void )
{
if ( ! F_51 () )
return - V_66 ;
if ( ! F_52 () )
return - V_66 ;
return F_53 ( & V_67 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_67 ) ;
}
