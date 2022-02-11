static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
if ( ! V_2 )
return - V_5 ;
V_3 = F_2 ( V_2 -> V_6 -> V_7 , L_1 , NULL ,
& V_2 -> V_8 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( ( V_9 , V_3 ,
L_2 ) ) ;
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
static void F_7 ( struct V_20 * V_6 , T_2 V_21 )
{
struct V_1 * V_2 = F_8 ( V_6 ) ;
if ( ! V_2 )
return;
switch ( V_21 ) {
default:
F_9 ( ( V_22 ,
L_3 , V_21 ) ) ;
case V_23 :
case V_24 :
case V_25 :
if ( V_26 > 0 )
F_10 ( V_26 ) ;
F_1 ( V_2 ) ;
F_11 ( V_6 -> V_27 . V_28 ,
F_12 ( & V_6 -> V_29 ) , V_21 ,
( T_2 ) V_2 -> V_8 ) ;
F_13 ( V_6 , V_21 , ( T_2 ) V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_30 . V_29 -> V_31 , V_32 ) ;
}
return;
}
static int F_15 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_36 )
{
struct V_1 * V_2 = F_16 ( V_34 , struct V_1 , V_37 ) ;
struct V_38 * V_21 = (struct V_38 * ) V_36 ;
if ( strcmp ( V_21 -> V_28 , V_39 ) == 0 &&
V_21 -> type == V_40 )
F_1 ( V_2 ) ;
return V_41 ;
}
static int F_17 ( const struct V_42 * V_43 )
{
V_26 = 1000 ;
return 0 ;
}
static int F_18 ( struct V_20 * V_6 )
{
int V_44 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_6 )
return - V_5 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_6 = V_6 ;
strcpy ( F_20 ( V_6 ) , V_47 ) ;
strcpy ( F_21 ( V_6 ) , V_48 ) ;
V_6 -> V_49 = V_2 ;
V_44 = F_1 ( V_2 ) ;
if ( V_44 )
goto V_50;
V_2 -> V_30 . V_51 = F_22 ( V_6 ) ;
V_2 -> V_30 . type = V_52 ;
V_2 -> V_30 . V_53 = V_54 ;
V_2 -> V_30 . V_55 = F_23 ( V_54 ) ;
V_2 -> V_30 . V_56 = F_5 ;
V_44 = F_24 ( & V_2 -> V_6 -> V_29 , & V_2 -> V_30 ) ;
if ( V_44 )
goto V_50;
F_25 (KERN_INFO PREFIX L_4 ,
acpi_device_name(device), acpi_device_bid(device),
ac->state ? L_5 : L_6 ) ;
V_2 -> V_37 . V_57 = F_15 ;
F_26 ( & V_2 -> V_37 ) ;
V_50:
if ( V_44 )
F_27 ( V_2 ) ;
F_28 ( V_58 ) ;
return V_44 ;
}
static int F_29 ( struct V_6 * V_29 )
{
struct V_1 * V_2 ;
unsigned V_59 ;
if ( ! V_29 )
return - V_5 ;
V_2 = F_8 ( F_30 ( V_29 ) ) ;
if ( ! V_2 )
return - V_5 ;
V_59 = V_2 -> V_8 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( V_59 != V_2 -> V_8 )
F_14 ( & V_2 -> V_30 . V_29 -> V_31 , V_32 ) ;
return 0 ;
}
static int F_31 ( struct V_20 * V_6 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_6 || ! F_8 ( V_6 ) )
return - V_5 ;
V_2 = F_8 ( V_6 ) ;
if ( V_2 -> V_30 . V_29 )
F_32 ( & V_2 -> V_30 ) ;
F_33 ( & V_2 -> V_37 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
int V_44 ;
if ( V_60 )
return - V_11 ;
V_44 = F_35 ( & V_61 ) ;
if ( V_44 < 0 )
return - V_11 ;
return 0 ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_61 ) ;
}
