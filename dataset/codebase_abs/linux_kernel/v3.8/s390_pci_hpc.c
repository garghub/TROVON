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
if ( ! V_8 ) {
V_6 -> V_9 -> V_2 = V_3 ;
F_4 ( V_6 -> V_9 ) ;
F_5 ( V_6 -> V_9 ) ;
}
return V_8 ;
}
static int F_6 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
int V_8 ;
if ( ! F_1 ( V_6 -> V_9 -> V_2 ) )
return - V_11 ;
V_8 = F_7 ( V_6 -> V_9 -> V_12 ) ;
if ( ! V_8 ) {
V_6 -> V_9 -> V_13 &= 0x7fffffff ;
V_6 -> V_9 -> V_2 = V_10 ;
}
return V_8 ;
}
static int F_8 ( struct V_5 * V_5 , T_1 * V_14 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
switch ( V_6 -> V_9 -> V_2 ) {
case V_10 :
* V_14 = 0 ;
break;
default:
* V_14 = 1 ;
break;
}
return 0 ;
}
static int F_9 ( struct V_5 * V_5 , T_1 * V_14 )
{
* V_14 = 1 ;
return 0 ;
}
static void F_10 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
F_11 ( L_1 , V_15 , F_12 ( V_5 ) ) ;
F_13 ( V_6 -> V_5 -> V_16 ) ;
F_13 ( V_6 -> V_5 ) ;
F_13 ( V_6 ) ;
}
static int F_14 ( struct V_17 * V_9 )
{
struct V_5 * V_5 ;
struct V_18 * V_16 ;
char V_19 [ V_20 ] ;
struct V_6 * V_6 ;
int V_8 ;
if ( ! V_9 )
return 0 ;
V_6 = F_15 ( sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
goto error;
V_5 = F_15 ( sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
goto V_22;
V_5 -> V_7 = V_6 ;
V_6 -> V_5 = V_5 ;
V_6 -> V_9 = V_9 ;
V_16 = F_15 ( sizeof( * V_16 ) , V_21 ) ;
if ( ! V_16 )
goto V_23;
V_5 -> V_16 = V_16 ;
V_5 -> V_24 = & V_25 ;
V_5 -> V_26 = & F_10 ;
F_8 ( V_5 , & V_16 -> V_27 ) ;
F_9 ( V_5 , & V_16 -> V_28 ) ;
snprintf ( V_19 , V_20 , L_2 , V_9 -> V_12 ) ;
V_8 = F_16 ( V_6 -> V_5 , V_9 -> V_29 ,
V_30 , V_19 ) ;
if ( V_8 ) {
F_17 ( L_3 , V_8 ) ;
goto V_31;
}
F_18 ( & V_6 -> V_32 , & V_33 ) ;
return 0 ;
V_31:
F_13 ( V_16 ) ;
V_23:
F_13 ( V_5 ) ;
V_22:
F_13 ( V_6 ) ;
error:
return - V_34 ;
}
static int T_2 F_19 ( void )
{
struct V_17 * V_9 ;
int V_35 = 0 ;
F_20 ( & V_36 ) ;
F_21 (zdev, &zpci_list, entry) {
F_14 ( V_9 ) ;
V_35 ++ ;
}
F_22 ( & V_36 ) ;
return ( V_35 ) ? 0 : - V_37 ;
}
static void F_23 ( struct V_17 * V_9 )
{
struct V_38 * V_39 , * V_40 ;
struct V_6 * V_6 ;
F_24 (tmp, n, &s390_hotplug_slot_list) {
V_6 = F_25 ( V_39 , struct V_6 , V_32 ) ;
if ( V_6 -> V_9 != V_9 )
continue;
F_26 ( & V_6 -> V_32 ) ;
F_27 ( V_6 -> V_5 ) ;
}
}
static void T_3 F_28 ( void )
{
struct V_38 * V_39 , * V_40 ;
struct V_6 * V_6 ;
F_24 (tmp, n, &s390_hotplug_slot_list) {
V_6 = F_25 ( V_39 , struct V_6 , V_32 ) ;
F_26 ( & V_6 -> V_32 ) ;
F_27 ( V_6 -> V_5 ) ;
}
}
static int T_2 F_29 ( void )
{
if ( ! V_41 )
return - V_42 ;
F_20 ( & V_36 ) ;
V_43 . V_44 = F_14 ;
V_43 . V_45 = F_23 ;
F_22 ( & V_36 ) ;
F_30 ( L_4 ) ;
return F_19 () ;
}
static void T_3 F_31 ( void )
{
F_28 () ;
}
