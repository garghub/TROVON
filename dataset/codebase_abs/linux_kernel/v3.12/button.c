static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
unsigned long long V_8 ;
V_7 = F_2 ( V_5 -> V_9 , L_1 , NULL , & V_8 ) ;
F_3 ( V_2 , L_2 ,
F_4 ( V_7 ) ? L_3 :
( V_8 ? L_4 : L_5 ) ) ;
return 0 ;
}
static int F_5 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_6 ( V_11 , F_1 , F_7 ( V_10 ) ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_9 ( V_5 ) ;
struct V_14 * V_15 = NULL ;
int V_16 = 0 ;
if ( V_13 -> type != V_17 )
return 0 ;
if ( V_18 || V_19 ) {
F_10 (KERN_ERR PREFIX L_6 ) ;
return - V_20 ;
}
V_18 = F_11 ( V_21 , V_22 ) ;
if ( ! V_18 )
return - V_23 ;
V_19 = F_11 ( V_24 , V_18 ) ;
if ( ! V_19 ) {
V_16 = - V_23 ;
goto V_25;
}
F_12 ( V_5 ) = F_11 ( F_13 ( V_5 ) , V_19 ) ;
if ( ! F_12 ( V_5 ) ) {
V_16 = - V_23 ;
goto V_26;
}
V_15 = F_14 ( V_27 ,
V_28 , F_12 ( V_5 ) ,
& V_29 , V_5 ) ;
if ( ! V_15 ) {
V_16 = - V_23 ;
goto V_30;
}
V_31:
return V_16 ;
V_30:
F_15 ( F_13 ( V_5 ) ,
V_19 ) ;
F_12 ( V_5 ) = NULL ;
V_26:
F_15 ( V_24 , V_18 ) ;
V_25:
F_15 ( V_21 , V_22 ) ;
goto V_31;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_9 ( V_5 ) ;
if ( V_13 -> type != V_17 )
return 0 ;
F_15 ( V_27 ,
F_12 ( V_5 ) ) ;
F_15 ( F_13 ( V_5 ) ,
V_19 ) ;
F_12 ( V_5 ) = NULL ;
F_15 ( V_24 , V_18 ) ;
F_15 ( V_21 , V_22 ) ;
return 0 ;
}
int F_17 ( struct V_32 * V_33 )
{
return F_18 ( & V_34 , V_33 ) ;
}
int F_19 ( struct V_32 * V_33 )
{
return F_20 ( & V_34 , V_33 ) ;
}
int F_21 ( void )
{
T_1 V_7 ;
unsigned long long V_8 ;
if ( ! V_35 )
return - V_23 ;
V_7 = F_2 ( V_35 -> V_9 , L_1 , NULL ,
& V_8 ) ;
if ( F_4 ( V_7 ) )
return - V_23 ;
return ! ! V_8 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_9 ( V_5 ) ;
unsigned long long V_8 ;
T_1 V_7 ;
int V_16 ;
V_7 = F_2 ( V_5 -> V_9 , L_1 , NULL , & V_8 ) ;
if ( F_4 ( V_7 ) )
return - V_23 ;
F_23 ( V_13 -> V_36 , V_37 , ! V_8 ) ;
F_24 ( V_13 -> V_36 ) ;
if ( V_8 )
F_25 ( & V_5 -> V_38 , 0 ) ;
V_16 = F_26 ( & V_34 , V_8 , V_5 ) ;
if ( V_16 == V_39 )
V_16 = F_26 ( & V_34 , V_8 ,
V_5 ) ;
if ( V_16 == V_39 || V_16 == V_40 ) {
V_16 = 0 ;
}
return V_16 ;
}
static void F_27 ( struct V_4 * V_5 , T_2 V_41 )
{
struct V_12 * V_13 = F_9 ( V_5 ) ;
struct V_42 * V_36 ;
switch ( V_41 ) {
case V_43 :
V_41 = V_44 ;
case V_44 :
V_36 = V_13 -> V_36 ;
if ( V_13 -> type == V_17 ) {
F_22 ( V_5 ) ;
} else {
int V_45 = F_28 ( V_46 , V_36 -> V_47 ) ?
V_46 : V_48 ;
F_29 ( V_36 , V_45 , 1 ) ;
F_24 ( V_36 ) ;
F_29 ( V_36 , V_45 , 0 ) ;
F_24 ( V_36 ) ;
F_25 ( & V_5 -> V_38 , 0 ) ;
}
break;
default:
F_30 ( ( V_49 ,
L_7 , V_41 ) ) ;
break;
}
}
static int F_31 ( struct V_5 * V_38 )
{
struct V_4 * V_5 = F_32 ( V_38 ) ;
struct V_12 * V_13 = F_9 ( V_5 ) ;
if ( V_13 -> type == V_17 )
return F_22 ( V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_4 * V_5 )
{
struct V_12 * V_13 ;
struct V_42 * V_36 ;
const char * V_50 = F_34 ( V_5 ) ;
char * V_51 , * V_52 ;
int error ;
V_13 = F_35 ( sizeof( struct V_12 ) , V_53 ) ;
if ( ! V_13 )
return - V_54 ;
V_5 -> V_55 = V_13 ;
V_13 -> V_36 = V_36 = F_36 () ;
if ( ! V_36 ) {
error = - V_54 ;
goto V_56;
}
V_51 = F_37 ( V_5 ) ;
V_52 = F_38 ( V_5 ) ;
if ( ! strcmp ( V_50 , V_57 ) ||
! strcmp ( V_50 , V_58 ) ) {
V_13 -> type = V_59 ;
strcpy ( V_51 , V_60 ) ;
sprintf ( V_52 , L_8 ,
V_21 , V_61 ) ;
} else if ( ! strcmp ( V_50 , V_62 ) ||
! strcmp ( V_50 , V_63 ) ) {
V_13 -> type = V_64 ;
strcpy ( V_51 , V_65 ) ;
sprintf ( V_52 , L_8 ,
V_21 , V_66 ) ;
} else if ( ! strcmp ( V_50 , V_67 ) ) {
V_13 -> type = V_17 ;
strcpy ( V_51 , V_68 ) ;
sprintf ( V_52 , L_8 ,
V_21 , V_24 ) ;
} else {
F_10 (KERN_ERR PREFIX L_9 , hid) ;
error = - V_23 ;
goto V_69;
}
error = F_8 ( V_5 ) ;
if ( error )
goto V_69;
snprintf ( V_13 -> V_70 , sizeof( V_13 -> V_70 ) , L_10 , V_50 ) ;
V_36 -> V_51 = V_51 ;
V_36 -> V_70 = V_13 -> V_70 ;
V_36 -> V_71 . V_72 = V_73 ;
V_36 -> V_71 . V_74 = V_13 -> type ;
V_36 -> V_38 . V_75 = & V_5 -> V_38 ;
switch ( V_13 -> type ) {
case V_59 :
V_36 -> V_76 [ 0 ] = F_39 ( V_77 ) ;
F_40 ( V_48 , V_36 -> V_47 ) ;
break;
case V_64 :
V_36 -> V_76 [ 0 ] = F_39 ( V_77 ) ;
F_40 ( V_46 , V_36 -> V_47 ) ;
break;
case V_17 :
V_36 -> V_76 [ 0 ] = F_39 ( V_78 ) ;
F_40 ( V_37 , V_36 -> V_79 ) ;
break;
}
error = F_41 ( V_36 ) ;
if ( error )
goto V_80;
if ( V_13 -> type == V_17 ) {
F_22 ( V_5 ) ;
V_35 = V_5 ;
}
if ( V_5 -> V_81 . V_82 . V_83 ) {
F_42 ( V_5 -> V_81 . V_84 ,
V_5 -> V_81 . V_85 ) ;
if ( ! F_43 ( & V_5 -> V_38 ) ) {
F_44 ( & V_5 -> V_38 , true ) ;
V_13 -> V_86 = true ;
}
}
F_10 (KERN_INFO PREFIX L_11 , name, acpi_device_bid(device)) ;
return 0 ;
V_80:
F_16 ( V_5 ) ;
V_69:
F_45 ( V_36 ) ;
V_56:
F_46 ( V_13 ) ;
return error ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_9 ( V_5 ) ;
if ( V_5 -> V_81 . V_82 . V_83 ) {
F_48 ( V_5 -> V_81 . V_84 ,
V_5 -> V_81 . V_85 ) ;
if ( V_13 -> V_86 )
F_44 ( & V_5 -> V_38 , false ) ;
}
F_16 ( V_5 ) ;
F_49 ( V_13 -> V_36 ) ;
F_46 ( V_13 ) ;
return 0 ;
}
