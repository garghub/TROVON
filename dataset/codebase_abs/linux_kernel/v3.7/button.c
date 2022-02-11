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
return F_6 ( V_11 , F_1 , F_7 ( V_10 ) -> V_12 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_9 ( V_5 ) ;
struct V_15 * V_16 = NULL ;
int V_17 = 0 ;
if ( V_14 -> type != V_18 )
return 0 ;
if ( V_19 || V_20 ) {
F_10 (KERN_ERR PREFIX L_6 ) ;
return - V_21 ;
}
V_19 = F_11 ( V_22 , V_23 ) ;
if ( ! V_19 )
return - V_24 ;
V_20 = F_11 ( V_25 , V_19 ) ;
if ( ! V_20 ) {
V_17 = - V_24 ;
goto V_26;
}
F_12 ( V_5 ) = F_11 ( F_13 ( V_5 ) , V_20 ) ;
if ( ! F_12 ( V_5 ) ) {
V_17 = - V_24 ;
goto V_27;
}
V_16 = F_14 ( V_28 ,
V_29 , F_12 ( V_5 ) ,
& V_30 , V_5 ) ;
if ( ! V_16 ) {
V_17 = - V_24 ;
goto V_31;
}
V_32:
return V_17 ;
V_31:
F_15 ( F_13 ( V_5 ) ,
V_20 ) ;
F_12 ( V_5 ) = NULL ;
V_27:
F_15 ( V_25 , V_19 ) ;
V_26:
F_15 ( V_22 , V_23 ) ;
goto V_32;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_9 ( V_5 ) ;
if ( V_14 -> type != V_18 )
return 0 ;
F_15 ( V_28 ,
F_12 ( V_5 ) ) ;
F_15 ( F_13 ( V_5 ) ,
V_20 ) ;
F_12 ( V_5 ) = NULL ;
F_15 ( V_25 , V_19 ) ;
F_15 ( V_22 , V_23 ) ;
return 0 ;
}
int F_17 ( struct V_33 * V_34 )
{
return F_18 ( & V_35 , V_34 ) ;
}
int F_19 ( struct V_33 * V_34 )
{
return F_20 ( & V_35 , V_34 ) ;
}
int F_21 ( void )
{
T_1 V_7 ;
unsigned long long V_8 ;
if ( ! V_36 )
return - V_24 ;
V_7 = F_2 ( V_36 -> V_9 , L_1 , NULL ,
& V_8 ) ;
if ( F_4 ( V_7 ) )
return - V_24 ;
return ! ! V_8 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_9 ( V_5 ) ;
unsigned long long V_8 ;
T_1 V_7 ;
int V_17 ;
V_7 = F_2 ( V_5 -> V_9 , L_1 , NULL , & V_8 ) ;
if ( F_4 ( V_7 ) )
return - V_24 ;
F_23 ( V_14 -> V_37 , V_38 , ! V_8 ) ;
F_24 ( V_14 -> V_37 ) ;
if ( V_8 )
F_25 ( & V_5 -> V_39 , 0 ) ;
V_17 = F_26 ( & V_35 , V_8 , V_5 ) ;
if ( V_17 == V_40 )
V_17 = F_26 ( & V_35 , V_8 ,
V_5 ) ;
if ( V_17 == V_40 || V_17 == V_41 ) {
V_17 = 0 ;
}
return V_17 ;
}
static void F_27 ( struct V_4 * V_5 , T_2 V_42 )
{
struct V_13 * V_14 = F_9 ( V_5 ) ;
struct V_43 * V_37 ;
switch ( V_42 ) {
case V_44 :
V_42 = V_45 ;
case V_45 :
V_37 = V_14 -> V_37 ;
if ( V_14 -> type == V_18 ) {
F_22 ( V_5 ) ;
} else {
int V_46 = F_28 ( V_47 , V_37 -> V_48 ) ?
V_47 : V_49 ;
F_29 ( V_37 , V_46 , 1 ) ;
F_24 ( V_37 ) ;
F_29 ( V_37 , V_46 , 0 ) ;
F_24 ( V_37 ) ;
F_25 ( & V_5 -> V_39 , 0 ) ;
}
F_30 ( V_5 , V_42 , ++ V_14 -> V_50 ) ;
break;
default:
F_31 ( ( V_51 ,
L_7 , V_42 ) ) ;
break;
}
}
static int F_32 ( struct V_5 * V_39 )
{
struct V_4 * V_5 = F_33 ( V_39 ) ;
struct V_13 * V_14 = F_9 ( V_5 ) ;
if ( V_14 -> type == V_18 )
return F_22 ( V_5 ) ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
struct V_43 * V_37 ;
const char * V_52 = F_35 ( V_5 ) ;
char * V_53 , * V_54 ;
int error ;
V_14 = F_36 ( sizeof( struct V_13 ) , V_55 ) ;
if ( ! V_14 )
return - V_56 ;
V_5 -> V_57 = V_14 ;
V_14 -> V_37 = V_37 = F_37 () ;
if ( ! V_37 ) {
error = - V_56 ;
goto V_58;
}
V_53 = F_38 ( V_5 ) ;
V_54 = F_39 ( V_5 ) ;
if ( ! strcmp ( V_52 , V_59 ) ||
! strcmp ( V_52 , V_60 ) ) {
V_14 -> type = V_61 ;
strcpy ( V_53 , V_62 ) ;
sprintf ( V_54 , L_8 ,
V_22 , V_63 ) ;
} else if ( ! strcmp ( V_52 , V_64 ) ||
! strcmp ( V_52 , V_65 ) ) {
V_14 -> type = V_66 ;
strcpy ( V_53 , V_67 ) ;
sprintf ( V_54 , L_8 ,
V_22 , V_68 ) ;
} else if ( ! strcmp ( V_52 , V_69 ) ) {
V_14 -> type = V_18 ;
strcpy ( V_53 , V_70 ) ;
sprintf ( V_54 , L_8 ,
V_22 , V_25 ) ;
} else {
F_10 (KERN_ERR PREFIX L_9 , hid) ;
error = - V_24 ;
goto V_71;
}
error = F_8 ( V_5 ) ;
if ( error )
goto V_71;
snprintf ( V_14 -> V_72 , sizeof( V_14 -> V_72 ) , L_10 , V_52 ) ;
V_37 -> V_53 = V_53 ;
V_37 -> V_72 = V_14 -> V_72 ;
V_37 -> V_73 . V_74 = V_75 ;
V_37 -> V_73 . V_76 = V_14 -> type ;
V_37 -> V_39 . V_77 = & V_5 -> V_39 ;
switch ( V_14 -> type ) {
case V_61 :
V_37 -> V_78 [ 0 ] = F_40 ( V_79 ) ;
F_41 ( V_49 , V_37 -> V_48 ) ;
break;
case V_66 :
V_37 -> V_78 [ 0 ] = F_40 ( V_79 ) ;
F_41 ( V_47 , V_37 -> V_48 ) ;
break;
case V_18 :
V_37 -> V_78 [ 0 ] = F_40 ( V_80 ) ;
F_41 ( V_38 , V_37 -> V_81 ) ;
break;
}
error = F_42 ( V_37 ) ;
if ( error )
goto V_82;
if ( V_14 -> type == V_18 ) {
F_22 ( V_5 ) ;
V_36 = V_5 ;
}
if ( V_5 -> V_83 . V_84 . V_85 ) {
F_43 ( V_5 -> V_83 . V_86 ,
V_5 -> V_83 . V_87 ) ;
if ( ! F_44 ( & V_5 -> V_39 ) ) {
F_45 ( & V_5 -> V_39 , true ) ;
V_14 -> V_88 = true ;
}
}
F_10 (KERN_INFO PREFIX L_11 , name, acpi_device_bid(device)) ;
return 0 ;
V_82:
F_16 ( V_5 ) ;
V_71:
F_46 ( V_37 ) ;
V_58:
F_47 ( V_14 ) ;
return error ;
}
static int F_48 ( struct V_4 * V_5 , int type )
{
struct V_13 * V_14 = F_9 ( V_5 ) ;
if ( V_5 -> V_83 . V_84 . V_85 ) {
F_49 ( V_5 -> V_83 . V_86 ,
V_5 -> V_83 . V_87 ) ;
if ( V_14 -> V_88 )
F_45 ( & V_5 -> V_39 , false ) ;
}
F_16 ( V_5 ) ;
F_50 ( V_14 -> V_37 ) ;
F_47 ( V_14 ) ;
return 0 ;
}
