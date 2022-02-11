static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
if ( ! V_2 )
return - V_5 ;
V_3 = F_2 ( V_2 -> V_6 -> V_7 , L_1 , NULL , & V_2 -> V_8 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( ( V_9 , V_3 , L_2 ) ) ;
V_2 -> V_8 = V_10 ;
return - V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
union V_16 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
if ( ! V_2 )
return - V_11 ;
if ( F_1 ( V_2 ) )
return - V_11 ;
switch ( V_15 ) {
case V_18 :
V_17 -> V_19 = V_2 -> V_8 ;
break;
default:
return - V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 , void * V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( ! V_2 )
return 0 ;
if ( F_1 ( V_2 ) ) {
F_8 ( V_21 , L_3 ) ;
return 0 ;
}
F_8 ( V_21 , L_4 ) ;
switch ( V_2 -> V_8 ) {
case V_24 :
F_8 ( V_21 , L_5 ) ;
break;
case V_25 :
F_8 ( V_21 , L_6 ) ;
break;
default:
F_8 ( V_21 , L_7 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
return F_10 ( V_27 , F_7 , F_11 ( V_26 ) ) ;
}
static int F_12 ( struct V_28 * V_6 )
{
struct V_29 * V_30 = NULL ;
F_13 (KERN_WARNING PREFIX L_8
L_9 ) ;
if ( ! F_14 ( V_6 ) ) {
F_14 ( V_6 ) = F_15 ( F_16 ( V_6 ) ,
V_31 ) ;
if ( ! F_14 ( V_6 ) )
return - V_11 ;
}
V_30 = F_17 ( V_32 ,
V_33 , F_14 ( V_6 ) ,
& V_34 , F_18 ( V_6 ) ) ;
if ( ! V_30 )
return - V_11 ;
return 0 ;
}
static int F_19 ( struct V_28 * V_6 )
{
if ( F_14 ( V_6 ) ) {
F_20 ( V_32 , F_14 ( V_6 ) ) ;
F_20 ( F_16 ( V_6 ) , V_31 ) ;
F_14 ( V_6 ) = NULL ;
}
return 0 ;
}
static void F_21 ( struct V_28 * V_6 , T_2 V_35 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
if ( ! V_2 )
return;
switch ( V_35 ) {
default:
F_22 ( ( V_36 ,
L_10 , V_35 ) ) ;
case V_37 :
case V_38 :
case V_39 :
if ( V_40 > 0 )
F_23 ( V_40 ) ;
F_1 ( V_2 ) ;
F_24 ( V_6 -> V_41 . V_42 ,
F_25 ( & V_6 -> V_43 ) , V_35 ,
( T_2 ) V_2 -> V_8 ) ;
F_26 ( V_6 , V_35 , ( T_2 ) V_2 -> V_8 ) ;
F_27 ( & V_2 -> V_44 . V_43 -> V_45 , V_46 ) ;
}
return;
}
static int F_28 ( const struct V_47 * V_48 )
{
V_40 = 1000 ;
return 0 ;
}
static int F_29 ( struct V_28 * V_6 )
{
int V_49 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_6 )
return - V_5 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_6 = V_6 ;
strcpy ( F_31 ( V_6 ) , V_52 ) ;
strcpy ( F_32 ( V_6 ) , V_53 ) ;
V_6 -> V_54 = V_2 ;
V_49 = F_1 ( V_2 ) ;
if ( V_49 )
goto V_55;
#ifdef F_33
V_49 = F_12 ( V_6 ) ;
#endif
if ( V_49 )
goto V_55;
V_2 -> V_44 . V_56 = F_16 ( V_6 ) ;
V_2 -> V_44 . type = V_57 ;
V_2 -> V_44 . V_58 = V_59 ;
V_2 -> V_44 . V_60 = F_34 ( V_59 ) ;
V_2 -> V_44 . V_61 = F_5 ;
V_49 = F_35 ( & V_2 -> V_6 -> V_43 , & V_2 -> V_44 ) ;
if ( V_49 )
goto V_55;
F_13 (KERN_INFO PREFIX L_11 ,
acpi_device_name(device), acpi_device_bid(device),
ac->state ? L_12 : L_13 ) ;
V_55:
if ( V_49 ) {
#ifdef F_33
F_19 ( V_6 ) ;
#endif
F_36 ( V_2 ) ;
}
F_37 ( V_62 ) ;
return V_49 ;
}
static int F_38 ( struct V_6 * V_43 )
{
struct V_1 * V_2 ;
unsigned V_63 ;
if ( ! V_43 )
return - V_5 ;
V_2 = F_18 ( F_39 ( V_43 ) ) ;
if ( ! V_2 )
return - V_5 ;
V_63 = V_2 -> V_8 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( V_63 != V_2 -> V_8 )
F_27 ( & V_2 -> V_44 . V_43 -> V_45 , V_46 ) ;
return 0 ;
}
static int F_40 ( struct V_28 * V_6 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_6 || ! F_18 ( V_6 ) )
return - V_5 ;
V_2 = F_18 ( V_6 ) ;
if ( V_2 -> V_44 . V_43 )
F_41 ( & V_2 -> V_44 ) ;
#ifdef F_33
F_19 ( V_6 ) ;
#endif
F_36 ( V_2 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
int V_49 ;
if ( V_64 )
return - V_11 ;
#ifdef F_33
V_31 = F_43 () ;
if ( ! V_31 )
return - V_11 ;
#endif
V_49 = F_44 ( & V_65 ) ;
if ( V_49 < 0 ) {
#ifdef F_33
F_45 ( V_31 ) ;
#endif
return - V_11 ;
}
return 0 ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_65 ) ;
#ifdef F_33
F_45 ( V_31 ) ;
#endif
return;
}
