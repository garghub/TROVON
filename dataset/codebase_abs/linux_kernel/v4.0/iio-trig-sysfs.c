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
F_9 ( V_12 -> V_12 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_13 )
{
struct V_14 * V_12 = F_11 ( V_2 ) ;
struct V_11 * V_15 = F_12 ( V_12 ) ;
F_13 ( & V_15 -> V_10 ) ;
return V_13 ;
}
static int F_3 ( int V_16 )
{
struct V_11 * V_17 ;
int V_7 ;
bool V_18 = false ;
F_14 ( & V_19 ) ;
F_15 (t, &iio_sysfs_trig_list, l)
if ( V_16 == V_17 -> V_16 ) {
V_18 = true ;
break;
}
if ( V_18 ) {
V_7 = - V_20 ;
goto V_21;
}
V_17 = F_16 ( sizeof( * V_17 ) , V_22 ) ;
if ( V_17 == NULL ) {
V_7 = - V_23 ;
goto V_21;
}
V_17 -> V_16 = V_16 ;
V_17 -> V_12 = F_17 ( L_1 , V_16 ) ;
if ( ! V_17 -> V_12 ) {
V_7 = - V_23 ;
goto V_24;
}
V_17 -> V_12 -> V_2 . V_25 = V_26 ;
V_17 -> V_12 -> V_27 = & V_28 ;
V_17 -> V_12 -> V_2 . V_29 = & V_30 ;
F_18 ( V_17 -> V_12 , V_17 ) ;
F_19 ( & V_17 -> V_10 , F_7 ) ;
V_7 = F_20 ( V_17 -> V_12 ) ;
if ( V_7 )
goto V_31;
F_21 ( & V_17 -> V_32 , & V_33 ) ;
F_22 ( V_34 ) ;
F_23 ( & V_19 ) ;
return 0 ;
V_31:
F_24 ( V_17 -> V_12 ) ;
V_24:
F_25 ( V_17 ) ;
V_21:
F_23 ( & V_19 ) ;
return V_7 ;
}
static int F_5 ( int V_16 )
{
bool V_18 = false ;
struct V_11 * V_17 ;
F_14 ( & V_19 ) ;
F_15 (t, &iio_sysfs_trig_list, l)
if ( V_16 == V_17 -> V_16 ) {
V_18 = true ;
break;
}
if ( ! V_18 ) {
F_23 ( & V_19 ) ;
return - V_20 ;
}
F_26 ( V_17 -> V_12 ) ;
F_27 ( V_17 -> V_12 ) ;
F_28 ( & V_17 -> V_32 ) ;
F_25 ( V_17 ) ;
F_29 ( V_34 ) ;
F_23 ( & V_19 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
F_31 ( & V_30 ) ;
F_32 ( & V_30 , L_2 ) ;
return F_33 ( & V_30 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_30 ) ;
}
