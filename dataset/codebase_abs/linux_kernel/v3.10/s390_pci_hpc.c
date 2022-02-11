static int F_1 ( enum V_1 V_2 )
{
return V_2 == V_3 ||
V_2 == V_4 ;
}
static int F_2 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
int V_8 ;
if ( V_6 -> V_9 -> V_2 != V_10 )
return - V_11 ;
V_8 = F_3 ( V_6 -> V_9 -> V_12 ) ;
F_4 ( 3 , L_1 , V_6 -> V_9 -> V_12 , V_8 ) ;
if ( ! V_8 ) {
V_6 -> V_9 -> V_2 = V_3 ;
F_5 ( V_6 -> V_9 ) ;
F_6 ( V_6 -> V_9 ) ;
}
return V_8 ;
}
static int F_7 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
int V_8 ;
if ( ! F_1 ( V_6 -> V_9 -> V_2 ) )
return - V_11 ;
V_8 = F_8 ( V_6 -> V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_9 ( V_6 -> V_9 -> V_12 ) ;
F_4 ( 3 , L_2 , V_6 -> V_9 -> V_12 , V_8 ) ;
if ( ! V_8 )
V_6 -> V_9 -> V_2 = V_10 ;
return V_8 ;
}
static int F_10 ( struct V_5 * V_5 , T_1 * V_13 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
switch ( V_6 -> V_9 -> V_2 ) {
case V_10 :
* V_13 = 0 ;
break;
default:
* V_13 = 1 ;
break;
}
return 0 ;
}
static int F_11 ( struct V_5 * V_5 , T_1 * V_13 )
{
* V_13 = 1 ;
return 0 ;
}
static void F_12 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
F_13 ( L_3 , V_14 , F_14 ( V_5 ) ) ;
F_15 ( V_6 -> V_5 -> V_15 ) ;
F_15 ( V_6 -> V_5 ) ;
F_15 ( V_6 ) ;
}
static int F_16 ( struct V_16 * V_9 )
{
struct V_5 * V_5 ;
struct V_17 * V_15 ;
char V_18 [ V_19 ] ;
struct V_6 * V_6 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
V_6 = F_17 ( sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
goto error;
V_5 = F_17 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
goto V_21;
V_5 -> V_7 = V_6 ;
V_6 -> V_5 = V_5 ;
V_6 -> V_9 = V_9 ;
V_15 = F_17 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 )
goto V_22;
V_5 -> V_15 = V_15 ;
V_5 -> V_23 = & V_24 ;
V_5 -> V_25 = & F_12 ;
F_10 ( V_5 , & V_15 -> V_26 ) ;
F_11 ( V_5 , & V_15 -> V_27 ) ;
snprintf ( V_18 , V_19 , L_4 , V_9 -> V_12 ) ;
V_8 = F_18 ( V_6 -> V_5 , V_9 -> V_28 ,
V_29 , V_18 ) ;
if ( V_8 ) {
F_19 ( L_5 , V_8 ) ;
goto V_30;
}
F_20 ( & V_6 -> V_31 , & V_32 ) ;
return 0 ;
V_30:
F_15 ( V_15 ) ;
V_22:
F_15 ( V_5 ) ;
V_21:
F_15 ( V_6 ) ;
error:
return - V_33 ;
}
static void F_21 ( struct V_16 * V_9 )
{
struct V_34 * V_35 , * V_36 ;
struct V_6 * V_6 ;
F_22 (tmp, n, &s390_hotplug_slot_list) {
V_6 = F_23 ( V_35 , struct V_6 , V_31 ) ;
if ( V_6 -> V_9 != V_9 )
continue;
F_24 ( & V_6 -> V_31 ) ;
F_25 ( V_6 -> V_5 ) ;
}
}
static void T_2 F_26 ( void )
{
struct V_16 * V_9 ;
F_27 ( & V_37 ) ;
F_28 (zdev, &zpci_list, entry) {
F_16 ( V_9 ) ;
}
F_29 ( & V_37 ) ;
}
static void T_3 F_30 ( void )
{
struct V_34 * V_35 , * V_36 ;
struct V_6 * V_6 ;
F_22 (tmp, n, &s390_hotplug_slot_list) {
V_6 = F_23 ( V_35 , struct V_6 , V_31 ) ;
F_24 ( & V_6 -> V_31 ) ;
F_25 ( V_6 -> V_5 ) ;
}
}
static int T_2 F_31 ( void )
{
if ( ! V_38 )
return - V_39 ;
F_32 ( & V_40 ) ;
F_26 () ;
return 0 ;
}
static void T_3 F_33 ( void )
{
F_30 () ;
F_34 () ;
}
