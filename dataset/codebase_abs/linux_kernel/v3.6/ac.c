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
return F_10 ( V_27 , F_7 , F_11 ( V_26 ) -> V_28 ) ;
}
static int F_12 ( struct V_29 * V_6 )
{
struct V_30 * V_31 = NULL ;
F_13 (KERN_WARNING PREFIX L_8
L_9 ) ;
if ( ! F_14 ( V_6 ) ) {
F_14 ( V_6 ) = F_15 ( F_16 ( V_6 ) ,
V_32 ) ;
if ( ! F_14 ( V_6 ) )
return - V_11 ;
}
V_31 = F_17 ( V_33 ,
V_34 , F_14 ( V_6 ) ,
& V_35 , F_18 ( V_6 ) ) ;
if ( ! V_31 )
return - V_11 ;
return 0 ;
}
static int F_19 ( struct V_29 * V_6 )
{
if ( F_14 ( V_6 ) ) {
F_20 ( V_33 , F_14 ( V_6 ) ) ;
F_20 ( F_16 ( V_6 ) , V_32 ) ;
F_14 ( V_6 ) = NULL ;
}
return 0 ;
}
static void F_21 ( struct V_29 * V_6 , T_2 V_36 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
if ( ! V_2 )
return;
switch ( V_36 ) {
default:
F_22 ( ( V_37 ,
L_10 , V_36 ) ) ;
case V_38 :
case V_39 :
case V_40 :
F_1 ( V_2 ) ;
F_23 ( V_6 , V_36 , ( T_2 ) V_2 -> V_8 ) ;
F_24 ( V_6 -> V_41 . V_42 ,
F_25 ( & V_6 -> V_43 ) , V_36 ,
( T_2 ) V_2 -> V_8 ) ;
F_26 ( V_6 , V_36 , ( T_2 ) V_2 -> V_8 ) ;
F_27 ( & V_2 -> V_44 . V_43 -> V_45 , V_46 ) ;
}
return;
}
static int F_28 ( struct V_29 * V_6 )
{
int V_47 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_6 )
return - V_5 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_6 = V_6 ;
strcpy ( F_30 ( V_6 ) , V_50 ) ;
strcpy ( F_31 ( V_6 ) , V_51 ) ;
V_6 -> V_52 = V_2 ;
V_47 = F_1 ( V_2 ) ;
if ( V_47 )
goto V_53;
#ifdef F_32
V_47 = F_12 ( V_6 ) ;
#endif
if ( V_47 )
goto V_53;
V_2 -> V_44 . V_54 = F_16 ( V_6 ) ;
V_2 -> V_44 . type = V_55 ;
V_2 -> V_44 . V_56 = V_57 ;
V_2 -> V_44 . V_58 = F_33 ( V_57 ) ;
V_2 -> V_44 . V_59 = F_5 ;
V_47 = F_34 ( & V_2 -> V_6 -> V_43 , & V_2 -> V_44 ) ;
if ( V_47 )
goto V_53;
F_13 (KERN_INFO PREFIX L_11 ,
acpi_device_name(device), acpi_device_bid(device),
ac->state ? L_12 : L_13 ) ;
V_53:
if ( V_47 ) {
#ifdef F_32
F_19 ( V_6 ) ;
#endif
F_35 ( V_2 ) ;
}
return V_47 ;
}
static int F_36 ( struct V_6 * V_43 )
{
struct V_1 * V_2 ;
unsigned V_60 ;
if ( ! V_43 )
return - V_5 ;
V_2 = F_18 ( F_37 ( V_43 ) ) ;
if ( ! V_2 )
return - V_5 ;
V_60 = V_2 -> V_8 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( V_60 != V_2 -> V_8 )
F_27 ( & V_2 -> V_44 . V_43 -> V_45 , V_46 ) ;
return 0 ;
}
static int F_38 ( struct V_29 * V_6 , int type )
{
struct V_1 * V_2 = NULL ;
if ( ! V_6 || ! F_18 ( V_6 ) )
return - V_5 ;
V_2 = F_18 ( V_6 ) ;
if ( V_2 -> V_44 . V_43 )
F_39 ( & V_2 -> V_44 ) ;
#ifdef F_32
F_19 ( V_6 ) ;
#endif
F_35 ( V_2 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_47 ;
if ( V_61 )
return - V_11 ;
#ifdef F_32
V_32 = F_41 () ;
if ( ! V_32 )
return - V_11 ;
#endif
V_47 = F_42 ( & V_62 ) ;
if ( V_47 < 0 ) {
#ifdef F_32
F_43 ( V_32 ) ;
#endif
return - V_11 ;
}
return 0 ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_62 ) ;
#ifdef F_32
F_43 ( V_32 ) ;
#endif
return;
}
