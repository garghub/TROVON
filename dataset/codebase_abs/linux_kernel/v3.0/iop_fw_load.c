static int F_1 ( void )
{
T_1 V_1 ;
unsigned int V_2 = V_3 ;
do {
V_1 = F_2 ( V_4 , V_5 , V_6 ) ;
} while ( V_1 . V_7 == V_8 && -- V_2 > 0 );
if ( V_2 == 0 ) {
F_3 ( V_9 L_1 ) ;
return - V_10 ;
}
return 0 ;
}
int F_4 ( const unsigned char * V_11 , unsigned int V_12 )
{
T_2 V_13 = {
. V_14 = V_15 ,
. V_16 = V_15 ,
. V_17 = 4 ,
. V_18 = V_19 ,
. V_20 = V_21
} ;
T_3 V_22 = {
. V_23 = V_24 ,
. V_25 = V_24 ,
} ;
T_4 V_26 ;
const struct V_27 * V_28 ;
T_5 * V_29 ;
unsigned int V_2 ;
int V_30 , V_31 ;
if ( V_12 > 1 )
return - V_32 ;
V_30 = F_5 ( & V_28 ,
V_11 ,
& V_33 [ V_12 ] ) ;
if ( V_30 != 0 )
{
F_3 ( V_9
L_2 ,
V_11 ) ;
return V_30 ;
}
V_29 = ( T_5 * ) V_28 -> V_29 ;
switch ( V_12 ) {
case 0 :
V_13 . V_14 = V_21 ;
F_6 ( V_34 , V_35 , V_36 , V_22 ) ;
break;
case 1 :
V_13 . V_16 = V_21 ;
F_6 ( V_34 , V_37 , V_36 , V_22 ) ;
break;
}
V_2 = V_3 ;
do {
F_6 ( V_38 , V_39 , V_40 , V_13 ) ;
V_26 = F_2 ( V_38 , V_39 , V_41 ) ;
} while ( V_26 . V_42 == V_15 && -- V_2 > 0 );
if ( V_2 == 0 ) {
F_3 ( V_9 L_3 ) ;
V_30 = - V_10 ;
goto V_43;
}
for ( V_31 = 0 ; V_31 < ( V_28 -> V_17 / 4 ) ; V_31 ++ ) {
switch ( V_12 ) {
case 0 :
F_7 ( V_34 , V_35 , V_44 , ( V_31 * 4 ) ) ;
break;
case 1 :
F_7 ( V_34 , V_37 , V_44 , ( V_31 * 4 ) ) ;
break;
}
F_7 ( V_38 , V_39 , V_45 , * V_29 ) ;
V_29 ++ ;
}
( void ) F_2 ( V_38 , V_39 , V_46 ) ;
V_43:
F_8 ( V_28 ) ;
return V_30 ;
}
int F_9 ( unsigned char * V_11 )
{
const unsigned int V_47 = 0 ;
T_6 V_48 ;
const struct V_27 * V_28 ;
T_5 * V_29 ;
int V_30 , V_31 ;
V_30 = F_5 ( & V_28 , V_11 , & V_49 ) ;
if ( V_30 != 0 )
{
F_3 ( V_9
L_2 ,
V_11 ) ;
return V_30 ;
}
V_29 = ( T_5 * ) V_28 -> V_29 ;
V_48 . V_23 = V_50 ;
F_6 ( V_4 , V_5 , V_36 , V_48 ) ;
F_10 ( V_4 , V_5 , V_51 , 0 , V_47 ) ;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
F_6 ( V_4 , V_5 , V_52 , F_11 ( 0 , 4 , 0 ) ) ;
for ( V_31 = 0 ; V_31 < ( V_28 -> V_17 / 4 ) ; V_31 ++ ) {
F_7 ( V_4 , V_5 , V_53 , * V_29 ) ;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
V_29 ++ ;
}
V_43:
F_8 ( V_28 ) ;
return V_30 ;
}
int F_12 ( unsigned int V_47 )
{
T_6 V_48 = { . V_23 = V_8 } ;
int V_30 ;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
F_6 ( V_4 , V_5 , V_52 , F_13 () ) ;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
F_7 ( V_4 , V_5 , V_52 , F_14 ( V_47 ) ) ;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
F_6 ( V_4 , V_5 , V_52 , F_15 () ) ;
if ( ( V_30 = F_1 () ) != 0 )
goto V_43;
F_6 ( V_4 , V_5 , V_36 , V_48 ) ;
V_43:
return V_30 ;
}
static int T_7 F_16 ( void )
{
#if 0
device_initialize(&iop_spu_device[0]);
kobject_set_name(&iop_spu_device[0].kobj, "iop-spu0");
kobject_add(&iop_spu_device[0].kobj);
device_initialize(&iop_spu_device[1]);
kobject_set_name(&iop_spu_device[1].kobj, "iop-spu1");
kobject_add(&iop_spu_device[1].kobj);
device_initialize(&iop_mpu_device);
kobject_set_name(&iop_mpu_device.kobj, "iop-mpu");
kobject_add(&iop_mpu_device.kobj);
#endif
return 0 ;
}
static void T_8 F_17 ( void )
{
}
