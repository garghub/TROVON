static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = 0 ;
F_2 ( V_4 ,
L_1 ,
V_1 , V_2 ) ;
F_3 ( V_4 ,
L_2 , V_3 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned int V_3 = 0 ;
F_2 ( V_4 ,
L_3 ,
V_1 , V_2 ) ;
F_3 ( V_4 , L_4 ,
V_3 ) ;
return V_3 ;
}
static long F_5 ( struct V_2 * V_2 , unsigned int V_5 ,
unsigned long V_6 )
{
unsigned int V_3 = 0 ;
T_1 V_7 = & V_8 ;
void T_2 * V_9 = ( void T_2 * ) V_6 ;
F_6 ( V_4 ,
L_5 ,
V_2 , V_5 , ( int ) V_6 ) ;
switch ( V_5 ) {
case V_10 :
F_7 ( V_4 ,
L_6
L_7 ) ;
F_8 ( & V_11 ) ;
V_3 = F_9 ( & V_7 -> V_12 ) ;
F_10 ( & V_11 ) ;
F_3 ( V_4 ,
L_6
L_8 ,
V_3 ) ;
break;
case V_13 :
F_7 ( V_4 ,
L_9
L_10 ) ;
F_8 ( & V_11 ) ;
V_3 = F_11 ( & V_7 -> V_12 ) ;
F_10 ( & V_11 ) ;
F_3 ( V_4 ,
L_9
L_11 ,
V_3 ) ;
break;
case V_14 : {
T_3 V_15 ;
F_7 ( V_4 ,
L_12
L_13
L_14 ) ;
F_8 ( & V_11 ) ;
V_3 = F_12 ( & V_7 -> V_12 ,
& V_15 ) ;
F_10 ( & V_11 ) ;
F_3 ( V_4 ,
L_15
L_16 ,
V_3 ) ;
if ( V_3 == 0 ) {
if( F_13 ( V_9 , & V_15 ,
sizeof( T_3 ) ) )
return - V_16 ;
}
F_3 ( V_4 ,
L_15
L_17 ,
V_3 ) ;
}
break;
case V_17 :
case V_18 : {
T_4 V_19 ;
unsigned short T_2 * V_20 = NULL ;
if( F_14 ( & V_19 , V_9 ,
sizeof( T_4 ) ) )
return - V_16 ;
V_20 = ( unsigned short T_2 * ) ( V_19 . V_21 ) ;
F_6 ( V_4 ,
L_18
L_19 ,
V_19 . V_22 , V_6 , V_20 ) ;
F_8 ( & V_11 ) ;
V_3 = F_15 ( & V_7 -> V_12 ,
V_5 ,
V_20 ,
V_19 . V_22 ,
V_19 . V_23 ) ;
F_10 ( & V_11 ) ;
}
break;
case V_24 : {
T_4 V_19 ;
unsigned short T_2 * V_20 = NULL ;
if( F_14 ( & V_19 , V_9 ,
sizeof( T_4 ) ) )
return - V_16 ;
V_20 = ( unsigned short T_2 * ) ( V_19 . V_21 ) ;
F_6 ( V_4 ,
L_20
L_19 ,
V_19 . V_22 / 2 , V_6 ,
V_20 ) ;
F_8 ( & V_11 ) ;
V_3 = F_15 ( & V_7 -> V_12 ,
V_5 , V_20 ,
V_19 . V_22 / 2 ,
V_19 . V_23 ) ;
F_10 ( & V_11 ) ;
}
break;
case V_25 : {
T_4 V_26 ;
unsigned short T_2 * V_20 = NULL ;
if( F_14 ( & V_26 , V_9 ,
sizeof( T_4 ) ) )
return - V_16 ;
V_20 = ( unsigned short T_2 * ) ( V_26 . V_21 ) ;
F_6 ( V_4 ,
L_21
L_19 ,
V_26 . V_22 , V_6 ,
V_20 ) ;
F_8 ( & V_11 ) ;
V_3 = F_15 ( & V_7 -> V_12 ,
V_5 , V_20 ,
V_26 . V_22 ,
V_26 . V_23 ) ;
F_10 ( & V_11 ) ;
}
break;
case V_27 : {
T_4 V_26 ;
unsigned short T_2 * V_20 = NULL ;
if( F_14 ( & V_26 , V_9 ,
sizeof( T_4 ) ) )
return - V_16 ;
V_20 = ( unsigned short T_2 * ) ( V_26 . V_21 ) ;
F_6 ( V_4 ,
L_22
L_19 ,
V_26 . V_22 , V_6 ,
V_20 ) ;
F_8 ( & V_11 ) ;
V_3 = F_16 ( & V_7 -> V_12 ,
V_5 , V_20 ,
V_26 . V_22 ,
V_26 . V_23 ) ;
F_10 ( & V_11 ) ;
}
break;
case V_28 : {
unsigned int V_29 = ( unsigned int ) V_6 ;
if ( V_29 >= F_17 ( V_7 -> V_30 ) ) {
F_18 ( V_31
L_23
L_24
L_25 ,
V_29 ) ;
return - V_32 ;
}
F_2 ( V_4 ,
L_26
L_27 ,
V_29 ,
V_7 -> V_30 [ V_29 ] . V_33 ) ;
F_8 ( & V_11 ) ;
V_7 -> V_30 [ V_29 ] . V_34 = FALSE ;
V_7 -> V_30 [ V_29 ] . V_35 = TRUE ;
F_10 ( & V_11 ) ;
F_3 ( V_4 ,
L_26
L_28 ,
V_29 ) ;
}
break;
case V_36 : {
unsigned int V_29 = ( unsigned int ) V_6 ;
if ( V_29 >= F_17 ( V_7 -> V_30 ) ) {
F_18 ( V_31
L_23
L_29
L_30 , V_29 ) ;
return - V_32 ;
}
F_2 ( V_4 ,
L_31
L_32 ,
V_29 ,
V_7 -> V_30 [ V_29 ] . V_33 ) ;
F_8 ( & V_11 ) ;
if ( V_7 -> V_30 [ V_29 ] . V_35 == TRUE ) {
F_19 ( V_37 , V_38 ) ;
F_3 ( V_4 ,
L_33
L_34 ,
V_29 ) ;
F_20 ( & V_7 -> V_30 [ V_29 ] . V_39 , & V_37 ) ;
V_7 -> V_30 [ V_29 ] . V_34 = TRUE ;
F_21 ( V_40 ) ;
if ( V_7 -> V_30 [ V_29 ] . V_33 == 1 ) {
V_7 -> V_30 [ V_29 ] . V_33 = 2 ;
F_3 ( V_4 ,
L_35
L_36
L_37 ,
V_29 ) ;
} else {
F_22 () ;
if ( V_7 -> V_30 [ V_29 ] . V_33 == 1 ) {
V_7 -> V_30 [ V_29 ] . V_33 = 2 ;
}
F_3 ( V_4 ,
L_35
L_36
L_38
L_39 ,
V_29 ) ;
}
V_7 -> V_30 [ V_29 ] . V_34 = FALSE ;
F_23 ( & V_7 -> V_30 [ V_29 ] . V_39 , & V_37 ) ;
F_21 ( V_41 ) ;
F_3 ( V_4 ,
L_40
L_41
L_42 ,
V_29 ) ;
}
F_10 ( & V_11 ) ;
}
break;
case V_42 : {
unsigned int V_29 = ( unsigned int ) V_6 ;
F_3 ( V_4 ,
L_43
L_44 ,
V_29 ) ;
if ( V_29 >= F_17 ( V_7 -> V_30 ) ) {
F_18 ( V_31
L_23
L_45
L_25 ,
V_29 ) ;
return - V_32 ;
}
F_8 ( & V_11 ) ;
if ( V_7 -> V_30 [ V_29 ] . V_35 == TRUE ) {
V_7 -> V_30 [ V_29 ] . V_35 = FALSE ;
if ( V_7 -> V_30 [ V_29 ] . V_34 == TRUE ) {
F_24 ( & V_7 -> V_30 [ V_29 ] . V_39 ) ;
}
}
F_10 ( & V_11 ) ;
}
break;
default:
return - V_43 ;
break;
}
F_3 ( V_4 , L_46 , V_3 ) ;
return V_3 ;
}
static T_5 F_25 ( struct V_2 * V_2 , char T_2 * V_44 , T_6 V_45 ,
T_7 * V_46 )
{
F_26 ( V_4 ,
L_47 ,
V_2 , V_44 , V_45 , V_46 ) ;
return - V_32 ;
}
static T_5 F_27 ( struct V_2 * V_2 , const char T_2 * V_44 ,
T_6 V_45 , T_7 * V_46 )
{
F_26 ( V_4 ,
L_48
L_49 ,
V_2 , V_44 , V_45 , V_46 ) ;
return - V_32 ;
}
static int F_28 ( unsigned int V_47 , int V_48 )
{
struct V_49 V_50 ;
switch ( V_47 ) {
case 0x3f8 :
case 0x2f8 :
case 0x3e8 :
case 0x2e8 :
break;
default:
F_18 ( V_31
L_50
L_51 , V_47 ) ;
return - 1 ;
}
switch ( V_48 ) {
case 3 :
case 4 :
case 5 :
case 7 :
break;
default:
F_18 ( V_31
L_50
L_52 , V_48 ) ;
return - 1 ;
}
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_51 = 1843200 ;
V_50 . V_52 = V_47 ;
V_50 . V_48 = V_48 ;
V_50 . V_53 = V_54 ;
V_50 . V_55 = V_56 ;
return F_29 ( & V_50 ) ;
}
static void F_30 ( void )
{
T_1 V_7 = & V_8 ;
F_7 ( V_4 , L_53 ) ;
#if 0
for (i = 0; i < pDrvData->nr_registered_attrs; i++)
device_remove_file(&mwave_device, mwave_dev_attrs[i]);
pDrvData->nr_registered_attrs = 0;
if (pDrvData->device_registered) {
device_unregister(&mwave_device);
pDrvData->device_registered = FALSE;
}
#endif
if ( V_7 -> V_57 >= 0 ) {
F_31 ( V_7 -> V_57 ) ;
}
if ( V_7 -> V_58 ) {
F_32 ( & V_59 ) ;
}
if ( V_7 -> V_60 ) {
F_33 ( & V_7 -> V_12 ) ;
}
if ( V_7 -> V_61 ) {
F_34 ( & V_7 -> V_12 ) ;
}
if ( V_7 -> V_62 ) {
F_35 ( & V_7 -> V_12 ) ;
}
F_7 ( V_4 , L_54 ) ;
}
static int T_8 F_36 ( void )
{
int V_63 ;
int V_3 = 0 ;
T_1 V_7 = & V_8 ;
F_7 ( V_4 , L_55 ) ;
memset ( & V_8 , 0 , sizeof( V_64 ) ) ;
V_7 -> V_62 = FALSE ;
V_7 -> V_61 = FALSE ;
V_7 -> V_60 = FALSE ;
V_7 -> V_65 = FALSE ;
V_7 -> V_58 = FALSE ;
V_7 -> V_57 = - 1 ;
for ( V_63 = 0 ; V_63 < F_17 ( V_7 -> V_30 ) ; V_63 ++ ) {
V_7 -> V_30 [ V_63 ] . V_35 = FALSE ;
V_7 -> V_30 [ V_63 ] . V_34 = FALSE ;
V_7 -> V_30 [ V_63 ] . V_33 = 0 ;
F_37 ( & V_7 -> V_30 [ V_63 ] . V_39 ) ;
}
V_3 = F_38 ( & V_7 -> V_12 ) ;
F_3 ( V_4 ,
L_56
L_57 ,
V_3 ) ;
if ( V_3 ) {
F_18 ( V_31
L_58
L_59 ) ;
goto V_66;
}
V_7 -> V_62 = TRUE ;
V_3 = F_39 ( & V_7 -> V_12 ) ;
F_3 ( V_4 ,
L_60
L_57 ,
V_3 ) ;
if ( V_3 ) {
F_18 ( V_31
L_61
L_62 ) ;
goto V_66;
}
V_3 = F_40 ( & V_7 -> V_12 ) ;
F_3 ( V_4 ,
L_63
L_57 ,
V_3 ) ;
if ( V_3 ) {
F_18 ( V_31
L_61
L_64 ) ;
goto V_66;
}
V_7 -> V_61 = TRUE ;
V_3 = F_41 ( & V_7 -> V_12 ) ;
F_3 ( V_4 ,
L_65
L_57 ,
V_3 ) ;
if ( V_3 ) {
F_18 ( V_31
L_61
L_66 ) ;
goto V_66;
}
V_7 -> V_60 = TRUE ;
if ( F_42 ( & V_59 ) < 0 ) {
F_18 ( V_31
L_61
L_67 ) ;
goto V_66;
}
V_7 -> V_58 = TRUE ;
V_7 -> V_57 = F_28 (
V_7 -> V_12 . V_67 . V_68 ,
V_7 -> V_12 . V_67 . V_69
) ;
if ( V_7 -> V_57 < 0 ) {
F_18 ( V_31
L_61
L_68 ) ;
goto V_66;
}
#if 0
memset(&mwave_device, 0, sizeof (struct device));
dev_set_name(&mwave_device, "mwave");
if (device_register(&mwave_device))
goto cleanup_error;
pDrvData->device_registered = TRUE;
for (i = 0; i < ARRAY_SIZE(mwave_dev_attrs); i++) {
if(device_create_file(&mwave_device, mwave_dev_attrs[i])) {
PRINTK_ERROR(KERN_ERR_MWAVE
"mwavedd:mwave_init: Error:"
" Failed to create sysfs file %s\n",
mwave_dev_attrs[i]->attr.name);
goto cleanup_error;
}
pDrvData->nr_registered_attrs++;
}
#endif
return 0 ;
V_66:
F_18 ( V_31
L_58
L_69 ) ;
F_30 () ;
return - V_70 ;
}
