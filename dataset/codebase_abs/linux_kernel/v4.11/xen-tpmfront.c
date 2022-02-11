static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
switch ( V_4 -> V_6 -> V_7 ) {
case V_8 :
return V_9 | V_10 ;
case V_11 :
return V_9 | V_12 ;
case V_13 :
case V_14 :
return V_15 ;
default:
return 0 ;
}
}
static bool F_3 ( struct V_1 * V_2 , T_1 V_16 )
{
return V_16 & V_10 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
V_4 -> V_6 -> V_7 = V_14 ;
F_5 () ;
F_6 ( V_4 -> V_17 ) ;
}
static unsigned int F_7 ( struct V_18 * V_6 )
{
return sizeof( * V_6 ) + sizeof( V_19 ) * V_6 -> V_20 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_21 , T_2 V_22 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_18 * V_6 = V_4 -> V_6 ;
unsigned int V_23 = F_7 ( V_6 ) ;
V_19 V_24 ;
unsigned long V_25 ;
if ( V_23 > V_26 )
return - V_27 ;
if ( V_23 + V_22 > V_26 )
return - V_27 ;
if ( F_9 ( V_2 , V_9 , V_2 -> V_28 ,
& V_4 -> V_29 , true ) < 0 ) {
F_4 ( V_2 ) ;
return - V_30 ;
}
memcpy ( V_23 + ( T_1 * ) V_6 , V_21 , V_22 ) ;
V_6 -> V_31 = V_22 ;
F_10 () ;
V_6 -> V_7 = V_13 ;
F_5 () ;
F_6 ( V_4 -> V_17 ) ;
V_24 = F_11 ( ( (struct V_32 * ) V_21 ) -> V_24 ) ;
V_25 = F_12 ( V_2 , V_24 ) ;
if ( F_9 ( V_2 , V_9 , V_25 ,
& V_4 -> V_29 , true ) < 0 ) {
F_4 ( V_2 ) ;
return - V_30 ;
}
return V_22 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_21 , T_2 V_22 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_18 * V_6 = V_4 -> V_6 ;
unsigned int V_23 = F_7 ( V_6 ) ;
T_2 V_31 = V_6 -> V_31 ;
if ( V_6 -> V_7 == V_8 )
return - V_33 ;
if ( F_9 ( V_2 , V_12 , V_2 -> V_28 ,
& V_4 -> V_29 , true ) < 0 ) {
F_4 ( V_2 ) ;
return - V_30 ;
}
if ( V_23 > V_26 )
return - V_34 ;
if ( V_23 + V_31 > V_26 )
V_31 = V_26 - V_23 ;
if ( V_31 > V_22 )
V_31 = V_22 ;
memcpy ( V_21 , V_23 + ( T_1 * ) V_6 , V_31 ) ;
return V_31 ;
}
static T_3 F_14 ( int V_35 , void * V_36 )
{
struct V_3 * V_4 = V_36 ;
switch ( V_4 -> V_6 -> V_7 ) {
case V_8 :
case V_11 :
F_15 ( & V_4 -> V_29 ) ;
break;
case V_13 :
case V_14 :
default:
break;
}
return V_37 ;
}
static int F_16 ( struct V_38 * V_5 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_5 , & V_39 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
F_20 ( & V_4 -> V_29 ) ;
V_4 -> V_2 = V_2 ;
F_21 ( & V_2 -> V_5 , V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_40 * V_5 , struct V_3 * V_4 )
{
struct V_41 V_42 ;
const char * V_43 = NULL ;
int V_44 ;
T_4 V_45 ;
V_4 -> V_6 = ( void * ) F_23 ( V_46 | V_47 ) ;
if ( ! V_4 -> V_6 ) {
F_24 ( V_5 , - V_48 , L_1 ) ;
return - V_48 ;
}
V_44 = F_25 ( V_5 , & V_4 -> V_6 , 1 , & V_45 ) ;
if ( V_44 < 0 )
return V_44 ;
V_4 -> V_49 = V_45 ;
V_44 = F_26 ( V_5 , & V_4 -> V_17 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_27 ( V_4 -> V_17 , F_14 , 0 ,
L_2 , V_4 ) ;
if ( V_44 <= 0 ) {
F_24 ( V_5 , V_44 , L_3 ) ;
return V_44 ;
}
V_4 -> V_50 = V_44 ;
V_51:
V_44 = F_28 ( & V_42 ) ;
if ( V_44 ) {
F_24 ( V_5 , V_44 , L_4 ) ;
return V_44 ;
}
V_44 = F_29 ( V_42 , V_5 -> V_52 ,
L_5 , L_6 , V_4 -> V_49 ) ;
if ( V_44 ) {
V_43 = L_7 ;
goto V_53;
}
V_44 = F_29 ( V_42 , V_5 -> V_52 , L_8 , L_6 ,
V_4 -> V_17 ) ;
if ( V_44 ) {
V_43 = L_9 ;
goto V_53;
}
V_44 = F_29 ( V_42 , V_5 -> V_52 , L_10 , L_11 ) ;
if ( V_44 ) {
V_43 = L_12 ;
goto V_53;
}
V_44 = F_30 ( V_42 , 0 ) ;
if ( V_44 == - V_54 )
goto V_51;
if ( V_44 ) {
F_24 ( V_5 , V_44 , L_13 ) ;
return V_44 ;
}
F_31 ( V_5 , V_55 ) ;
return 0 ;
V_53:
F_30 ( V_42 , 1 ) ;
if ( V_43 )
F_32 ( V_5 , V_44 , L_14 , V_43 ) ;
return V_44 ;
}
static void F_33 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_49 )
F_34 ( V_4 -> V_49 , 0 ,
( unsigned long ) V_4 -> V_6 ) ;
else
F_35 ( ( unsigned long ) V_4 -> V_6 ) ;
if ( V_4 -> V_50 )
F_36 ( V_4 -> V_50 , V_4 ) ;
F_37 ( V_4 ) ;
}
static int F_38 ( struct V_40 * V_5 ,
const struct V_56 * V_57 )
{
struct V_3 * V_4 ;
int V_44 ;
V_4 = F_39 ( sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 ) {
F_24 ( V_5 , - V_48 , L_15 ) ;
return - V_48 ;
}
V_44 = F_16 ( & V_5 -> V_5 , V_4 ) ;
if ( V_44 ) {
F_37 ( V_4 ) ;
return V_44 ;
}
V_44 = F_22 ( V_5 , V_4 ) ;
if ( V_44 ) {
F_33 ( V_4 ) ;
return V_44 ;
}
F_40 ( V_4 -> V_2 ) ;
return F_41 ( V_4 -> V_2 ) ;
}
static int F_42 ( struct V_40 * V_5 )
{
struct V_1 * V_2 = F_2 ( & V_5 -> V_5 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_43 ( V_2 ) ;
F_33 ( V_4 ) ;
F_21 ( & V_2 -> V_5 , NULL ) ;
return 0 ;
}
static int F_44 ( struct V_40 * V_5 )
{
F_42 ( V_5 ) ;
return F_38 ( V_5 , NULL ) ;
}
static void F_45 ( struct V_40 * V_5 ,
enum V_58 V_59 )
{
switch ( V_59 ) {
case V_55 :
case V_60 :
if ( V_5 -> V_7 == V_60 )
break;
if ( ! F_46 ( V_5 -> V_61 , L_10 ,
0 ) ) {
F_24 ( V_5 , - V_27 ,
L_16 ) ;
return;
}
F_31 ( V_5 , V_60 ) ;
break;
case V_62 :
case V_63 :
F_47 ( & V_5 -> V_5 ) ;
F_48 ( V_5 ) ;
break;
default:
break;
}
}
static int T_5 F_49 ( void )
{
if ( ! F_50 () )
return - V_64 ;
if ( ! F_51 () )
return - V_64 ;
return F_52 ( & V_65 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_65 ) ;
}
