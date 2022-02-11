static int F_1 ( enum V_1 V_2 )
{
return V_2 == V_3 ||
V_2 == V_4 ;
}
static inline int F_2 ( struct V_5 * V_5 )
{
int V_6 = F_3 ( V_5 -> V_7 -> V_8 ) ;
F_4 ( 3 , L_1 , V_5 -> V_7 -> V_8 , V_6 ) ;
if ( ! V_6 )
V_5 -> V_7 -> V_2 = V_3 ;
return V_6 ;
}
static inline int F_5 ( struct V_5 * V_5 )
{
int V_6 = F_6 ( V_5 -> V_7 -> V_8 ) ;
F_4 ( 3 , L_2 , V_5 -> V_7 -> V_8 , V_6 ) ;
if ( ! V_6 )
V_5 -> V_7 -> V_2 = V_9 ;
return V_6 ;
}
static int F_7 ( struct V_10 * V_10 )
{
struct V_5 * V_5 = V_10 -> V_11 ;
int V_12 ;
if ( V_5 -> V_7 -> V_2 != V_9 )
return - V_13 ;
V_12 = F_2 ( V_5 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_5 -> V_7 ) ;
if ( V_12 )
goto V_14;
F_9 ( V_5 -> V_7 -> V_15 , V_16 ) ;
F_10 () ;
F_11 ( V_5 -> V_7 -> V_15 ) ;
F_12 () ;
return V_12 ;
V_14:
F_5 ( V_5 ) ;
return V_12 ;
}
static int F_13 ( struct V_10 * V_10 )
{
struct V_5 * V_5 = V_10 -> V_11 ;
int V_12 ;
if ( ! F_1 ( V_5 -> V_7 -> V_2 ) )
return - V_13 ;
if ( V_5 -> V_7 -> V_17 )
F_14 ( V_5 -> V_7 -> V_17 ) ;
V_12 = F_15 ( V_5 -> V_7 ) ;
if ( V_12 )
return V_12 ;
return F_5 ( V_5 ) ;
}
static int F_16 ( struct V_10 * V_10 , T_1 * V_18 )
{
struct V_5 * V_5 = V_10 -> V_11 ;
switch ( V_5 -> V_7 -> V_2 ) {
case V_9 :
* V_18 = 0 ;
break;
default:
* V_18 = 1 ;
break;
}
return 0 ;
}
static int F_17 ( struct V_10 * V_10 , T_1 * V_18 )
{
* V_18 = 1 ;
return 0 ;
}
static void F_18 ( struct V_10 * V_10 )
{
struct V_5 * V_5 = V_10 -> V_11 ;
F_19 ( V_5 -> V_10 -> V_19 ) ;
F_19 ( V_5 -> V_10 ) ;
F_19 ( V_5 ) ;
}
int F_20 ( struct V_20 * V_7 )
{
struct V_10 * V_10 ;
struct V_21 * V_19 ;
char V_22 [ V_23 ] ;
struct V_5 * V_5 ;
int V_12 ;
if ( ! V_7 )
return 0 ;
V_5 = F_21 ( sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
goto error;
V_10 = F_21 ( sizeof( * V_10 ) , V_24 ) ;
if ( ! V_10 )
goto V_25;
V_10 -> V_11 = V_5 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_7 = V_7 ;
V_19 = F_21 ( sizeof( * V_19 ) , V_24 ) ;
if ( ! V_19 )
goto V_26;
V_10 -> V_19 = V_19 ;
V_10 -> V_27 = & V_28 ;
V_10 -> V_29 = & F_18 ;
F_16 ( V_10 , & V_19 -> V_30 ) ;
F_17 ( V_10 , & V_19 -> V_31 ) ;
snprintf ( V_22 , V_23 , L_3 , V_7 -> V_8 ) ;
V_12 = F_22 ( V_5 -> V_10 , V_7 -> V_15 ,
V_16 , V_22 ) ;
if ( V_12 )
goto V_32;
F_23 ( & V_5 -> V_33 , & V_34 ) ;
return 0 ;
V_32:
F_19 ( V_19 ) ;
V_26:
F_19 ( V_10 ) ;
V_25:
F_19 ( V_5 ) ;
error:
return - V_35 ;
}
void F_24 ( struct V_20 * V_7 )
{
struct V_36 * V_37 , * V_38 ;
struct V_5 * V_5 ;
F_25 (tmp, n, &s390_hotplug_slot_list) {
V_5 = F_26 ( V_37 , struct V_5 , V_33 ) ;
if ( V_5 -> V_7 != V_7 )
continue;
F_27 ( & V_5 -> V_33 ) ;
F_28 ( V_5 -> V_10 ) ;
}
}
