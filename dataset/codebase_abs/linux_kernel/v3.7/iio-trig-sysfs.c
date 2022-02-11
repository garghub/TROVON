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
static void F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 , struct V_11 ,
V_10 ) ;
F_9 ( V_12 -> V_12 , 0 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_13 )
{
struct V_14 * V_12 = F_11 ( V_2 ) ;
struct V_11 * V_15 = V_12 -> V_16 ;
F_12 ( & V_15 -> V_10 ) ;
return V_13 ;
}
static int F_3 ( int V_17 )
{
struct V_11 * V_18 ;
int V_7 ;
bool V_19 = false ;
F_13 ( & V_20 ) ;
F_14 (t, &iio_sysfs_trig_list, l)
if ( V_17 == V_18 -> V_17 ) {
V_19 = true ;
break;
}
if ( V_19 ) {
V_7 = - V_21 ;
goto V_22;
}
V_18 = F_15 ( sizeof( * V_18 ) , V_23 ) ;
if ( V_18 == NULL ) {
V_7 = - V_24 ;
goto V_22;
}
V_18 -> V_17 = V_17 ;
V_18 -> V_12 = F_16 ( L_1 , V_17 ) ;
if ( ! V_18 -> V_12 ) {
V_7 = - V_24 ;
goto V_25;
}
V_18 -> V_12 -> V_2 . V_26 = V_27 ;
V_18 -> V_12 -> V_28 = & V_29 ;
V_18 -> V_12 -> V_2 . V_30 = & V_31 ;
V_18 -> V_12 -> V_16 = V_18 ;
F_17 ( & V_18 -> V_10 , F_7 ) ;
V_7 = F_18 ( V_18 -> V_12 ) ;
if ( V_7 )
goto V_32;
F_19 ( & V_18 -> V_33 , & V_34 ) ;
F_20 ( V_35 ) ;
F_21 ( & V_20 ) ;
return 0 ;
V_32:
F_22 ( V_18 -> V_12 ) ;
V_25:
F_23 ( V_18 ) ;
V_22:
F_21 ( & V_20 ) ;
return V_7 ;
}
static int F_5 ( int V_17 )
{
bool V_19 = false ;
struct V_11 * V_18 ;
F_13 ( & V_20 ) ;
F_14 (t, &iio_sysfs_trig_list, l)
if ( V_17 == V_18 -> V_17 ) {
V_19 = true ;
break;
}
if ( ! V_19 ) {
F_21 ( & V_20 ) ;
return - V_21 ;
}
F_24 ( V_18 -> V_12 ) ;
F_25 ( V_18 -> V_12 ) ;
F_26 ( & V_18 -> V_33 ) ;
F_23 ( V_18 ) ;
F_27 ( V_35 ) ;
F_21 ( & V_20 ) ;
return 0 ;
}
static int T_3 F_28 ( void )
{
F_29 ( & V_31 ) ;
F_30 ( & V_31 , L_2 ) ;
return F_31 ( & V_31 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_31 ) ;
}
