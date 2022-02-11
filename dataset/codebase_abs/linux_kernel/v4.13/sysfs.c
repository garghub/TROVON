static T_1 F_1 ( char * V_1 , int V_2 )
{
T_1 V_3 = F_2 ( V_2 , ( unsigned long ) V_1 , V_4 - 1 ) ;
V_3 = V_3 < 0 ? 0 : F_3 ( V_3 , ( T_1 ) V_4 - 1 ) - 1 ;
if ( V_3 )
V_1 [ V_3 ++ ] = '\n' ;
V_1 [ V_3 ] = '\0' ;
return V_3 ;
}
static T_1 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_1 )
{
return sprintf ( V_1 , L_1 , V_9 ) ;
}
static T_1 F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_1 )
{
return sprintf ( V_1 , L_1 , V_10 ) ;
}
static T_1 F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_1 )
{
return F_1 ( V_1 , V_11 ) ;
}
static T_1 F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_1 )
{
return F_1 ( V_1 , V_12 ) ;
}
static T_1 F_8 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_1 )
{
return sprintf ( V_1 , L_2 ) ;
}
static T_1
F_9 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 , T_2 V_20 , T_3 V_21 )
{
static T_3 V_22 ;
if ( V_22 == 0 )
V_22 = F_2 ( V_23 , 0 , 0 ) - 1 ;
if ( V_20 > V_22 )
return - V_24 ;
if ( V_21 > V_22 - V_20 )
V_21 = V_22 - V_20 ;
if ( V_21 ) {
char * V_25 ;
V_22 = V_20 + V_21 ;
V_25 = F_10 ( V_22 , V_26 ) ;
if ( V_25 == NULL )
return - V_27 ;
F_2 ( V_23 , ( unsigned long ) V_25 , V_22 ) ;
memcpy ( V_19 , V_25 + V_20 , V_21 ) ;
F_11 ( V_25 ) ;
}
return V_21 ;
}
static T_1 F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_1 )
{
int V_28 = V_6 -> V_29 ;
long V_30 = F_13 ( F_14 ( V_28 ) , F_15 ( V_28 ) ) ;
T_1 V_3 = F_2 ( V_31 ,
( unsigned long ) V_1 , V_4 - 1 ,
V_30 , 0 ) ;
V_3 = V_3 < 0 ? 0 : F_3 ( V_3 , ( T_1 ) V_4 - 1 ) ;
V_1 [ V_3 ] = '\0' ;
return V_3 ;
}
static T_1 F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_1 ,
T_3 V_21 )
{
int V_28 = V_6 -> V_29 ;
long V_30 = F_13 ( F_14 ( V_28 ) , F_15 ( V_28 ) ) ;
T_1 V_3 = F_2 ( V_31 , 0 , 0 , V_30 , 1 ) ;
return V_3 < 0 ? V_3 : V_21 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_32 * V_33 )
{
int V_34 , V_28 = V_6 -> V_29 ;
if ( ! F_18 ( V_28 ) )
return 0 ;
V_34 = F_19 ( & V_6 -> V_16 , & V_35 . V_8 ) ;
return V_34 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_28 = V_6 -> V_29 ;
if ( F_18 ( V_28 ) )
F_21 ( & V_6 -> V_16 , & V_35 . V_8 ) ;
}
static int T_4 F_22 ( void )
{
int V_34 = 0 ;
#define F_23 ( T_5 ) \
if (!err) \
err = device_create_file(cpu_subsys.dev_root, &dev_attr_##name);
F_23 ( V_36 ) ;
F_23 ( V_37 ) ;
F_23 ( V_38 ) ;
F_23 ( V_39 ) ;
#define F_24 ( T_5 ) \
if (!err) \
err = sysfs_create_file(hypervisor_kobj, &dev_attr_##name.attr);
F_24 ( type ) ;
F_24 ( V_40 ) ;
F_24 ( V_41 ) ;
if ( ! V_34 )
V_34 = F_25 ( V_42 , & V_43 ) ;
if ( ! V_34 ) {
F_26 ( & V_44 ) ;
V_44 . V_8 . T_5 = L_3 ;
V_44 . V_8 . V_45 = V_46 ;
V_44 . V_47 = F_9 ;
V_44 . V_22 = V_4 ;
V_34 = F_27 ( V_42 , & V_44 ) ;
}
if ( ! V_34 ) {
int V_28 = F_28 () ;
long V_30 = F_13 ( F_14 ( V_28 ) , F_15 ( V_28 ) ) ;
char V_48 ;
T_1 V_3 = F_2 ( V_31 ,
( unsigned long ) & V_48 , 1 ,
V_30 , 0 ) ;
if ( V_3 >= 0 )
V_34 = F_29 ( & V_49 ) ;
}
return V_34 ;
}
