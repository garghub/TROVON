static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = F_2 ( V_2 ) ;
F_3 (fc, &fc_devices, list)
if ( V_8 -> V_10 . V_9 == V_9 )
break;
if ( V_8 -> V_10 . V_9 != V_9 )
return - V_11 ;
V_6 = V_8 -> V_6 ;
if ( F_4 ( V_6 -> V_12 ) == 0 )
return - V_11 ;
V_4 -> V_13 = V_6 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_13 ;
F_6 ( V_6 -> V_12 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_3 * V_4 , char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
struct V_5 * V_6 = V_4 -> V_13 ;
unsigned long V_17 ;
T_5 V_18 ;
if ( V_15 < sizeof( V_18 ) )
return - V_19 ;
V_15 = sizeof( V_18 ) ;
V_17 = * V_16 ;
if ( V_17 > V_6 -> V_20 )
return - V_21 ;
V_18 = F_8 ( V_6 , V_17 ) ;
if ( F_9 ( V_14 , & V_18 , V_15 ) )
return - V_22 ;
* V_16 += V_15 ;
return V_15 ;
}
static T_1 F_10 ( struct V_3 * V_4 , const char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
struct V_5 * V_6 = V_4 -> V_13 ;
unsigned long V_17 ;
T_5 V_18 ;
if ( V_15 < sizeof( V_18 ) )
return - V_19 ;
V_15 = sizeof( V_18 ) ;
V_17 = * V_16 ;
if ( V_17 > V_6 -> V_20 )
return - V_21 ;
if ( F_11 ( & V_18 , V_14 , V_15 ) )
return - V_22 ;
F_12 ( V_6 , V_18 , V_17 ) ;
* V_16 += V_15 ;
return V_15 ;
}
static int F_13 ( struct V_5 * V_6 )
{
int V_23 ;
int V_24 = 0 ;
struct V_7 * V_8 ;
if ( V_6 -> V_25 -> V_26 )
V_24 = V_6 -> V_25 -> V_26 ( V_6 , & V_27 ) ;
if ( V_24 < 0 )
return - V_19 ;
V_8 = F_14 ( sizeof( * V_8 ) , V_28 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_10 . V_9 = V_30 ;
V_8 -> V_10 . V_31 = & V_32 ;
V_8 -> V_10 . V_33 = F_15 ( F_16 ( & V_6 -> V_34 ) , V_28 ) ;
F_17 ( & V_35 ) ;
V_23 = F_18 ( & V_8 -> V_10 ) ;
if ( V_23 < 0 )
goto V_36;
F_19 ( & V_8 -> V_37 , & V_38 ) ;
F_20 ( & V_35 ) ;
F_21 ( & V_8 -> V_6 -> V_34 , L_1 ,
V_8 -> V_10 . V_33 ) ;
return 0 ;
V_36:
F_20 ( & V_35 ) ;
F_22 ( V_8 -> V_10 . V_33 ) ;
F_22 ( V_8 ) ;
return V_23 ;
}
static int F_23 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
F_3 (fc, &fc_devices, list)
if ( V_8 -> V_6 == V_6 )
break;
if ( V_8 -> V_6 != V_6 ) {
F_24 ( & V_6 -> V_34 , L_2 ) ;
return - V_11 ;
}
F_17 ( & V_35 ) ;
F_25 ( & V_8 -> V_37 ) ;
F_26 ( & V_8 -> V_10 ) ;
F_22 ( V_8 -> V_10 . V_33 ) ;
F_22 ( V_8 ) ;
F_20 ( & V_35 ) ;
return 0 ;
}
static int F_27 ( void )
{
int V_23 ;
V_23 = F_28 ( & V_27 ) ;
return V_23 ;
}
static void F_29 ( void )
{
F_30 ( & V_27 ) ;
}
