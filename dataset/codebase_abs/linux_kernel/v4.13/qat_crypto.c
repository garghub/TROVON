void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
}
static int F_4 ( struct V_5 * V_4 )
{
struct V_1 * V_2 , * V_6 ;
int V_7 ;
F_5 (inst, tmp, &accel_dev->crypto_list, list) {
for ( V_7 = 0 ; V_7 < F_6 ( & V_2 -> V_3 ) ; V_7 ++ )
F_1 ( V_2 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 -> V_8 ) ;
if ( V_2 -> V_9 )
F_7 ( V_2 -> V_9 ) ;
if ( V_2 -> V_10 )
F_7 ( V_2 -> V_10 ) ;
if ( V_2 -> V_11 )
F_7 ( V_2 -> V_11 ) ;
F_8 ( & V_2 -> V_12 ) ;
F_9 ( V_2 ) ;
}
return 0 ;
}
struct V_1 * F_10 ( int V_13 )
{
struct V_5 * V_4 = NULL , * V_14 ;
struct V_1 * V_2 = NULL , * V_15 ;
unsigned long V_16 = ~ 0 ;
F_11 (tmp_dev, adf_devmgr_get_head(), list) {
unsigned long V_17 ;
if ( ( V_13 == F_12 ( & F_13 ( V_14 ) ) ||
F_12 ( & F_13 ( V_14 ) ) < 0 ) &&
F_14 ( V_14 ) &&
! F_15 ( & V_14 -> V_18 ) ) {
V_17 = F_6 ( & V_14 -> V_19 ) ;
if ( V_16 > V_17 ) {
V_4 = V_14 ;
V_16 = V_17 ;
}
}
}
if ( ! V_4 ) {
F_16 ( L_1 , V_13 ) ;
F_11 (tmp_dev, adf_devmgr_get_head(), list) {
if ( F_14 ( V_14 ) &&
! F_15 ( & V_14 -> V_18 ) ) {
V_4 = V_14 ;
break;
}
}
}
if ( ! V_4 )
return NULL ;
V_16 = ~ 0 ;
F_11 (tmp_inst, &accel_dev->crypto_list, list) {
unsigned long V_17 ;
V_17 = F_6 ( & V_15 -> V_3 ) ;
if ( V_16 > V_17 ) {
V_2 = V_15 ;
V_16 = V_17 ;
}
}
if ( V_2 ) {
if ( F_17 ( V_4 ) ) {
F_18 ( & F_13 ( V_4 ) , L_2 ) ;
return NULL ;
}
F_19 ( & V_2 -> V_3 ) ;
}
return V_2 ;
}
int F_20 ( struct V_5 * V_4 )
{
int V_20 = F_21 () ;
int V_21 = F_22 ( V_4 ) ;
int V_22 = F_23 ( V_20 , V_21 ) ;
char V_23 [ V_24 ] ;
int V_7 ;
unsigned long V_25 ;
if ( F_24 ( V_4 , V_26 ) )
goto V_27;
if ( F_24 ( V_4 , L_3 ) )
goto V_27;
for ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ ) {
V_25 = V_7 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_29 , V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_31 ,
V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_32 , V_7 ) ;
V_25 = 128 ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
V_25 = 512 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_33 , V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
V_25 = 0 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_34 , V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
V_25 = 2 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_35 , V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
V_25 = 8 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_36 , V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
V_25 = 10 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_37 , V_7 ) ;
if ( F_25 ( V_4 , V_26 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
V_25 = V_38 ;
snprintf ( V_23 , sizeof( V_23 ) , V_39 , V_7 ) ;
if ( F_25 ( V_4 , L_3 ,
V_23 , ( void * ) & V_25 , V_30 ) )
goto V_27;
}
V_25 = V_7 ;
if ( F_25 ( V_4 , V_26 ,
V_40 , ( void * ) & V_25 , V_30 ) )
goto V_27;
F_26 ( V_41 , & V_4 -> V_42 ) ;
return 0 ;
V_27:
F_18 ( & F_13 ( V_4 ) , L_5 ) ;
return - V_43 ;
}
static int F_27 ( struct V_5 * V_4 )
{
int V_7 ;
unsigned long V_44 ;
unsigned long V_45 , V_46 , V_47 ;
int V_48 ;
struct V_1 * V_2 ;
char V_23 [ V_24 ] ;
char V_25 [ V_49 ] ;
F_28 ( & V_4 -> V_18 ) ;
F_29 ( V_23 , V_40 , sizeof( V_23 ) ) ;
if ( F_30 ( V_4 , V_50 , V_23 , V_25 ) )
return - V_51 ;
if ( F_31 ( V_25 , 0 , & V_45 ) )
return - V_51 ;
for ( V_7 = 0 ; V_7 < V_45 ; V_7 ++ ) {
V_2 = F_32 ( sizeof( * V_2 ) , V_52 ,
F_12 ( & F_13 ( V_4 ) ) ) ;
if ( ! V_2 )
goto V_27;
F_33 ( & V_2 -> V_12 , & V_4 -> V_18 ) ;
V_2 -> V_53 = V_7 ;
F_34 ( & V_2 -> V_3 , 0 ) ;
V_2 -> V_4 = V_4 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_29 , V_7 ) ;
if ( F_30 ( V_4 , V_50 , V_23 , V_25 ) )
goto V_27;
if ( F_31 ( V_25 , 10 , & V_44 ) )
goto V_27;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_33 , V_7 ) ;
if ( F_30 ( V_4 , V_50 , V_23 , V_25 ) )
goto V_27;
if ( F_31 ( V_25 , 10 , & V_46 ) )
goto V_27;
V_46 = V_46 >> 1 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_32 , V_7 ) ;
if ( F_30 ( V_4 , V_50 , V_23 , V_25 ) )
goto V_27;
if ( F_31 ( V_25 , 10 , & V_47 ) )
goto V_27;
V_47 = V_47 >> 1 ;
V_48 = V_54 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_35 , V_7 ) ;
if ( F_35 ( V_4 , V_50 , V_44 , V_46 ,
V_48 , V_23 , NULL , 0 , & V_2 -> V_8 ) )
goto V_27;
V_48 = V_48 >> 1 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_34 , V_7 ) ;
if ( F_35 ( V_4 , V_50 , V_44 , V_47 ,
V_48 , V_23 , NULL , 0 , & V_2 -> V_10 ) )
goto V_27;
V_48 = V_55 ;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_37 , V_7 ) ;
if ( F_35 ( V_4 , V_50 , V_44 , V_46 ,
V_48 , V_23 , V_56 , 0 ,
& V_2 -> V_9 ) )
goto V_27;
snprintf ( V_23 , sizeof( V_23 ) , V_28 L_4 V_36 , V_7 ) ;
if ( F_35 ( V_4 , V_50 , V_44 , V_47 ,
V_48 , V_23 , V_57 , 0 ,
& V_2 -> V_11 ) )
goto V_27;
}
return 0 ;
V_27:
F_4 ( V_4 ) ;
return - V_58 ;
}
static int F_36 ( struct V_5 * V_4 )
{
if ( F_27 ( V_4 ) )
return - V_51 ;
return 0 ;
}
static int F_37 ( struct V_5 * V_4 )
{
return F_4 ( V_4 ) ;
}
static int F_38 ( struct V_5 * V_4 ,
enum V_59 V_60 )
{
int V_61 ;
switch ( V_60 ) {
case V_62 :
V_61 = F_36 ( V_4 ) ;
break;
case V_63 :
V_61 = F_37 ( V_4 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
default:
V_61 = 0 ;
}
return V_61 ;
}
int F_39 ( void )
{
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_69 = F_38 ;
V_68 . V_70 = L_6 ;
return F_40 ( & V_68 ) ;
}
int F_41 ( void )
{
return F_42 ( & V_68 ) ;
}
