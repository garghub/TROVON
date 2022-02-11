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
if ( ! V_2 )
return - V_41 ;
F_18 ( & V_2 -> V_27 . V_29 ) ;
V_4 -> V_2 = V_2 ;
F_2 ( V_2 ) = V_4 ;
return 0 ;
}
static int F_19 ( struct V_42 * V_39 , struct V_3 * V_4 )
{
struct V_43 V_44 ;
const char * V_45 = NULL ;
int V_46 ;
V_4 -> V_5 = ( void * ) F_20 ( V_47 | V_48 ) ;
if ( ! V_4 -> V_5 ) {
F_21 ( V_39 , - V_49 , L_1 ) ;
return - V_49 ;
}
V_46 = F_22 ( V_39 , F_23 ( V_4 -> V_5 ) ) ;
if ( V_46 < 0 )
return V_46 ;
V_4 -> V_50 = V_46 ;
V_46 = F_24 ( V_39 , & V_4 -> V_16 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_25 ( V_4 -> V_16 , F_14 , 0 ,
L_2 , V_4 ) ;
if ( V_46 <= 0 ) {
F_21 ( V_39 , V_46 , L_3 ) ;
return V_46 ;
}
V_4 -> V_2 -> V_27 . V_51 = V_46 ;
V_52:
V_46 = F_26 ( & V_44 ) ;
if ( V_46 ) {
F_21 ( V_39 , V_46 , L_4 ) ;
return V_46 ;
}
V_46 = F_27 ( V_44 , V_39 -> V_53 ,
L_5 , L_6 , V_4 -> V_50 ) ;
if ( V_46 ) {
V_45 = L_7 ;
goto V_54;
}
V_46 = F_27 ( V_44 , V_39 -> V_53 , L_8 , L_6 ,
V_4 -> V_16 ) ;
if ( V_46 ) {
V_45 = L_9 ;
goto V_54;
}
V_46 = F_27 ( V_44 , V_39 -> V_53 , L_10 , L_11 ) ;
if ( V_46 ) {
V_45 = L_12 ;
goto V_54;
}
V_46 = F_28 ( V_44 , 0 ) ;
if ( V_46 == - V_55 )
goto V_52;
if ( V_46 ) {
F_21 ( V_39 , V_46 , L_13 ) ;
return V_46 ;
}
F_29 ( V_39 , V_56 ) ;
return 0 ;
V_54:
F_28 ( V_44 , 1 ) ;
if ( V_45 )
F_30 ( V_39 , V_46 , L_14 , V_45 ) ;
return V_46 ;
}
static void F_31 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
if ( V_4 -> V_50 )
F_32 ( V_4 -> V_50 , 0 ,
( unsigned long ) V_4 -> V_5 ) ;
else
F_33 ( ( unsigned long ) V_4 -> V_5 ) ;
if ( V_4 -> V_2 && V_4 -> V_2 -> V_27 . V_51 )
F_34 ( V_4 -> V_2 -> V_27 . V_51 , V_4 ) ;
F_35 ( V_4 ) ;
}
static int F_36 ( struct V_42 * V_39 ,
const struct V_57 * V_58 )
{
struct V_3 * V_4 ;
int V_46 ;
V_4 = F_37 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 ) {
F_21 ( V_39 , - V_49 , L_15 ) ;
return - V_49 ;
}
V_46 = F_16 ( & V_39 -> V_39 , V_4 ) ;
if ( V_46 ) {
F_35 ( V_4 ) ;
return V_46 ;
}
V_46 = F_19 ( V_39 , V_4 ) ;
if ( V_46 ) {
F_38 ( & V_39 -> V_39 ) ;
F_31 ( V_4 ) ;
return V_46 ;
}
F_39 ( V_4 -> V_2 ) ;
F_40 ( & V_39 -> V_39 , V_4 -> V_2 ) ;
return V_46 ;
}
static int F_41 ( struct V_42 * V_39 )
{
struct V_1 * V_2 = F_42 ( & V_39 -> V_39 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( & V_39 -> V_39 ) ;
F_31 ( V_4 ) ;
F_2 ( V_2 ) = NULL ;
return 0 ;
}
static int F_43 ( struct V_42 * V_39 )
{
F_41 ( V_39 ) ;
return F_36 ( V_39 , NULL ) ;
}
static void F_44 ( struct V_42 * V_39 ,
enum V_59 V_60 )
{
int V_61 ;
switch ( V_60 ) {
case V_56 :
case V_62 :
if ( V_39 -> V_6 == V_62 )
break;
if ( F_45 ( V_63 , V_39 -> V_64 ,
L_10 , L_16 , & V_61 ) < 0 )
V_61 = 0 ;
if ( ! V_61 ) {
F_21 ( V_39 , - V_26 ,
L_17 ) ;
return;
}
F_29 ( V_39 , V_62 ) ;
break;
case V_65 :
case V_66 :
F_46 ( & V_39 -> V_39 ) ;
F_47 ( V_39 ) ;
break;
default:
break;
}
}
static int T_4 F_48 ( void )
{
if ( ! F_49 () )
return - V_41 ;
return F_50 ( & V_67 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_67 ) ;
}
