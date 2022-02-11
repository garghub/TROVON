static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
int V_7 ;
unsigned long V_8 ;
V_7 = F_2 ( V_5 , 10 , & V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_8 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
int V_7 ;
unsigned long V_8 ;
V_7 = F_2 ( V_5 , 10 , & V_8 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( V_8 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 )
{
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_9 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
F_9 ( V_11 , 0 ) ;
return V_9 ;
}
static int F_3 ( int V_12 )
{
struct V_13 * V_14 ;
int V_7 ;
bool V_15 = false ;
F_10 ( & V_16 ) ;
F_11 (t, &iio_sysfs_trig_list, l)
if ( V_12 == V_14 -> V_12 ) {
V_15 = true ;
break;
}
if ( V_15 ) {
V_7 = - V_17 ;
goto V_18;
}
V_14 = F_12 ( sizeof( * V_14 ) , V_19 ) ;
if ( V_14 == NULL ) {
V_7 = - V_20 ;
goto V_18;
}
V_14 -> V_12 = V_12 ;
V_14 -> V_11 = F_13 ( L_1 , V_12 ) ;
if ( ! V_14 -> V_11 ) {
V_7 = - V_20 ;
goto V_21;
}
V_14 -> V_11 -> V_2 . V_22 = V_23 ;
V_14 -> V_11 -> V_24 = & V_25 ;
V_14 -> V_11 -> V_2 . V_26 = & V_27 ;
V_7 = F_14 ( V_14 -> V_11 ) ;
if ( V_7 )
goto V_28;
F_15 ( & V_14 -> V_29 , & V_30 ) ;
F_16 ( V_31 ) ;
F_17 ( & V_16 ) ;
return 0 ;
V_28:
F_18 ( V_14 -> V_11 ) ;
V_21:
F_19 ( V_14 ) ;
V_18:
F_17 ( & V_16 ) ;
return V_7 ;
}
static int F_5 ( int V_12 )
{
bool V_15 = false ;
struct V_13 * V_14 ;
F_10 ( & V_16 ) ;
F_11 (t, &iio_sysfs_trig_list, l)
if ( V_12 == V_14 -> V_12 ) {
V_15 = true ;
break;
}
if ( ! V_15 ) {
F_17 ( & V_16 ) ;
return - V_17 ;
}
F_20 ( V_14 -> V_11 ) ;
F_21 ( V_14 -> V_11 ) ;
F_22 ( & V_14 -> V_29 ) ;
F_19 ( V_14 ) ;
F_23 ( V_31 ) ;
F_17 ( & V_16 ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
F_25 ( & V_27 ) ;
F_26 ( & V_27 , L_2 ) ;
return F_27 ( & V_27 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_27 ) ;
}
