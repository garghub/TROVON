static int F_1 ( struct V_1 * V_2 , unsigned long
* V_3 )
{
* V_3 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned long
* V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
int V_8 ;
if ( ! V_5 )
return - V_9 ;
V_7 = F_3 ( V_5 -> V_10 , & V_8 ) ;
if ( V_7 )
return V_7 ;
* V_3 = ( V_8 == V_11 ? 0 :
( V_8 == V_12 ? 1 : - 1 ) ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
if ( ! V_5 || ( V_3 != 0 && V_3 != 1 ) )
return - V_9 ;
V_7 = F_5 ( V_5 -> V_10 ,
V_3 ? V_12 : V_11 ) ;
return V_7 ;
}
static int F_6 ( struct V_4 * V_5 )
{
int V_7 = 0 ;
struct V_1 * V_2 ;
if ( ! V_5 )
return - V_9 ;
strcpy ( F_7 ( V_5 ) , L_1 ) ;
strcpy ( F_8 ( V_5 ) , V_13 ) ;
V_7 = F_3 ( V_5 -> V_10 , NULL ) ;
if ( V_7 ) {
F_9 (KERN_ERR PREFIX L_2 ) ;
goto V_14;
}
V_2 = F_10 ( L_1 , V_5 ,
& V_15 ) ;
if ( F_11 ( V_2 ) ) {
V_7 = F_12 ( V_2 ) ;
goto V_14;
}
F_13 ( & V_5 -> V_16 , L_3 , V_2 -> V_17 ) ;
V_5 -> V_18 = V_2 ;
V_7 = F_14 ( & V_5 -> V_16 . V_19 ,
& V_2 -> V_5 . V_19 ,
L_4 ) ;
if ( V_7 )
F_15 ( & V_5 -> V_16 , L_5
L_6 ) ;
V_7 = F_14 ( & V_2 -> V_5 . V_19 ,
& V_5 -> V_16 . V_19 ,
L_7 ) ;
if ( V_7 )
F_15 ( & V_5 -> V_16 , L_5
L_8 ) ;
F_9 (KERN_INFO PREFIX L_9 ,
acpi_device_name(device), acpi_device_bid(device),
!device->power.state ? L_10 : L_11 ) ;
V_14:
return V_7 ;
}
static int F_16 ( struct V_4 * V_5 , int type )
{
struct V_1 * V_2 = F_17 ( V_5 ) ;
if ( ! V_5 || ! V_2 )
return - V_9 ;
F_18 ( & V_5 -> V_16 . V_19 , L_4 ) ;
F_18 ( & V_2 -> V_5 . V_19 , L_7 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_16 )
{
if ( ! V_16 )
return - V_9 ;
F_5 ( F_21 ( V_16 ) -> V_10 , V_12 ) ;
return V_20 ;
}
static int F_22 ( struct V_5 * V_16 )
{
int V_7 ;
if ( ! V_16 )
return - V_9 ;
V_7 = F_3 ( F_21 ( V_16 ) -> V_10 , NULL ) ;
if ( V_7 )
F_9 (KERN_ERR PREFIX L_12 ) ;
return V_7 ;
}
static int T_1 F_23 ( void )
{
int V_7 = 0 ;
V_7 = F_24 ( & V_21 ) ;
if ( V_7 < 0 )
return - V_22 ;
return 0 ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_21 ) ;
return;
}
