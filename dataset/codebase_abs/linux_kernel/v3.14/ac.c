static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 = F_2 ( & V_2 -> V_5 -> V_6 ) ;
V_3 = F_3 ( V_4 , L_1 , NULL ,
& V_2 -> V_7 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( ( V_8 , V_3 ,
L_2 ) ) ;
V_2 -> V_7 = V_9 ;
return - V_10 ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_12 ,
enum V_13 V_14 ,
union V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
if ( ! V_2 )
return - V_10 ;
if ( F_1 ( V_2 ) )
return - V_10 ;
switch ( V_14 ) {
case V_17 :
V_16 -> V_18 = V_2 -> V_7 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static void F_8 ( T_2 V_4 , T_3 V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
struct V_22 * V_23 ;
if ( ! V_2 )
return;
switch ( V_20 ) {
default:
F_9 ( ( V_24 ,
L_3 , V_20 ) ) ;
case V_25 :
case V_26 :
case V_27 :
if ( V_28 > 0 )
F_10 ( V_28 ) ;
F_1 ( V_2 ) ;
V_23 = F_11 ( & V_2 -> V_5 -> V_6 ) ;
F_12 ( V_23 -> V_29 . V_30 ,
F_13 ( & V_2 -> V_5 -> V_6 ) ,
V_20 , ( T_3 ) V_2 -> V_7 ) ;
F_14 ( V_23 , V_20 , ( T_3 ) V_2 -> V_7 ) ;
F_15 ( & V_2 -> V_31 . V_6 -> V_32 , V_33 ) ;
}
return;
}
static int F_16 ( const struct V_34 * V_35 )
{
V_28 = 1000 ;
return 0 ;
}
static int F_17 ( struct V_36 * V_5 )
{
int V_37 = 0 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 ;
if ( ! V_5 )
return - V_19 ;
V_23 = F_11 ( & V_5 -> V_6 ) ;
if ( ! V_23 )
return - V_10 ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
strcpy ( F_19 ( V_23 ) , V_40 ) ;
strcpy ( F_20 ( V_23 ) , V_41 ) ;
V_2 -> V_5 = V_5 ;
F_21 ( V_5 , V_2 ) ;
V_37 = F_1 ( V_2 ) ;
if ( V_37 )
goto V_42;
V_2 -> V_31 . V_43 = F_22 ( V_23 ) ;
V_2 -> V_31 . type = V_44 ;
V_2 -> V_31 . V_45 = V_46 ;
V_2 -> V_31 . V_47 = F_23 ( V_46 ) ;
V_2 -> V_31 . V_48 = F_6 ;
V_37 = F_24 ( & V_5 -> V_6 , & V_2 -> V_31 ) ;
if ( V_37 )
goto V_42;
V_37 = F_25 ( F_2 ( & V_5 -> V_6 ) ,
V_49 , F_8 , V_2 ) ;
if ( V_37 ) {
F_26 ( & V_2 -> V_31 ) ;
goto V_42;
}
F_27 (KERN_INFO PREFIX L_4 ,
acpi_device_name(adev), acpi_device_bid(adev),
ac->state ? L_5 : L_6 ) ;
V_42:
if ( V_37 )
F_28 ( V_2 ) ;
F_29 ( V_50 ) ;
return V_37 ;
}
static int F_30 ( struct V_51 * V_6 )
{
struct V_1 * V_2 ;
unsigned V_52 ;
if ( ! V_6 )
return - V_19 ;
V_2 = F_31 ( F_32 ( V_6 ) ) ;
if ( ! V_2 )
return - V_19 ;
V_52 = V_2 -> V_7 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( V_52 != V_2 -> V_7 )
F_15 ( & V_2 -> V_31 . V_6 -> V_32 , V_33 ) ;
return 0 ;
}
static int F_33 ( struct V_36 * V_5 )
{
struct V_1 * V_2 ;
if ( ! V_5 )
return - V_19 ;
F_34 ( F_2 ( & V_5 -> V_6 ) ,
V_49 , F_8 ) ;
V_2 = F_31 ( V_5 ) ;
if ( V_2 -> V_31 . V_6 )
F_26 ( & V_2 -> V_31 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
int V_37 ;
if ( V_53 )
return - V_10 ;
V_37 = F_36 ( & V_54 ) ;
if ( V_37 < 0 )
return - V_10 ;
return 0 ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_54 ) ;
}
