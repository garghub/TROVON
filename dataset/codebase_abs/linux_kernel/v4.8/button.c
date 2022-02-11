static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , L_1 , NULL , & V_3 ) ;
if ( F_3 ( V_4 ) )
return - V_6 ;
return V_3 ? 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
int V_10 ;
F_6 ( V_9 -> V_11 , V_12 , ! V_7 ) ;
F_7 ( V_9 -> V_11 ) ;
if ( V_7 )
F_8 ( & V_2 -> V_13 , 0 ) ;
V_10 = F_9 ( & V_14 , V_7 , V_2 ) ;
if ( V_10 == V_15 )
V_10 = F_9 ( & V_14 , V_7 ,
V_2 ) ;
if ( V_10 == V_15 || V_10 == V_16 ) {
V_10 = 0 ;
}
return V_10 ;
}
static int F_10 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
F_11 ( V_18 , L_2 ,
V_7 < 0 ? L_3 : ( V_7 ? L_4 : L_5 ) ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_13 ( V_22 , F_10 , F_14 ( V_21 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_23 * V_24 = NULL ;
int V_10 = 0 ;
if ( V_9 -> type != V_25 )
return 0 ;
if ( V_26 || V_27 ) {
F_16 (KERN_ERR PREFIX L_6 ) ;
return - V_28 ;
}
V_26 = F_17 ( V_29 , V_30 ) ;
if ( ! V_26 )
return - V_6 ;
V_27 = F_17 ( V_31 , V_26 ) ;
if ( ! V_27 ) {
V_10 = - V_6 ;
goto V_32;
}
F_18 ( V_2 ) = F_17 ( F_19 ( V_2 ) , V_27 ) ;
if ( ! F_18 ( V_2 ) ) {
V_10 = - V_6 ;
goto V_33;
}
V_24 = F_20 ( V_34 ,
V_35 , F_18 ( V_2 ) ,
& V_36 , V_2 ) ;
if ( ! V_24 ) {
V_10 = - V_6 ;
goto V_37;
}
V_38:
return V_10 ;
V_37:
F_21 ( F_19 ( V_2 ) ,
V_27 ) ;
F_18 ( V_2 ) = NULL ;
V_33:
F_21 ( V_31 , V_26 ) ;
V_27 = NULL ;
V_32:
F_21 ( V_29 , V_30 ) ;
V_26 = NULL ;
goto V_38;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
if ( V_9 -> type != V_25 )
return 0 ;
F_21 ( V_34 ,
F_18 ( V_2 ) ) ;
F_21 ( F_19 ( V_2 ) ,
V_27 ) ;
F_18 ( V_2 ) = NULL ;
F_21 ( V_31 , V_26 ) ;
V_27 = NULL ;
F_21 ( V_29 , V_30 ) ;
V_26 = NULL ;
return 0 ;
}
int F_23 ( struct V_39 * V_40 )
{
return F_24 ( & V_14 , V_40 ) ;
}
int F_25 ( struct V_39 * V_40 )
{
return F_26 ( & V_14 , V_40 ) ;
}
int F_27 ( void )
{
if ( ! V_41 )
return - V_6 ;
return F_1 ( V_41 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 , V_7 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
switch ( V_42 ) {
case V_43 :
( void ) F_4 ( V_2 , 1 ) ;
break;
case V_44 :
( void ) F_28 ( V_2 ) ;
break;
case V_45 :
default:
break;
}
}
static void F_30 ( struct V_1 * V_2 , T_2 V_46 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_47 * V_11 ;
switch ( V_46 ) {
case V_48 :
V_46 = V_49 ;
case V_49 :
V_11 = V_9 -> V_11 ;
if ( V_9 -> type == V_25 ) {
F_28 ( V_2 ) ;
} else {
int V_50 ;
F_8 ( & V_2 -> V_13 , 0 ) ;
if ( V_9 -> V_51 )
break;
V_50 = F_31 ( V_52 , V_11 -> V_53 ) ?
V_52 : V_54 ;
F_32 ( V_11 , V_50 , 1 ) ;
F_7 ( V_11 ) ;
F_32 ( V_11 , V_50 , 0 ) ;
F_7 ( V_11 ) ;
F_33 (
V_2 -> V_55 . V_56 ,
F_34 ( & V_2 -> V_13 ) ,
V_46 , ++ V_9 -> V_57 ) ;
}
break;
default:
F_35 ( ( V_58 ,
L_7 , V_46 ) ) ;
break;
}
}
static int F_36 ( struct V_2 * V_13 )
{
struct V_1 * V_2 = F_37 ( V_13 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
V_9 -> V_51 = true ;
return 0 ;
}
static int F_38 ( struct V_2 * V_13 )
{
struct V_1 * V_2 = F_37 ( V_13 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
V_9 -> V_51 = false ;
if ( V_9 -> type == V_25 )
F_29 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_47 * V_11 ;
const char * V_59 = F_40 ( V_2 ) ;
char * V_60 , * V_61 ;
int error ;
V_9 = F_41 ( sizeof( struct V_8 ) , V_62 ) ;
if ( ! V_9 )
return - V_63 ;
V_2 -> V_64 = V_9 ;
V_9 -> V_11 = V_11 = F_42 () ;
if ( ! V_11 ) {
error = - V_63 ;
goto V_65;
}
V_60 = F_43 ( V_2 ) ;
V_61 = F_44 ( V_2 ) ;
if ( ! strcmp ( V_59 , V_66 ) ||
! strcmp ( V_59 , V_67 ) ) {
V_9 -> type = V_68 ;
strcpy ( V_60 , V_69 ) ;
sprintf ( V_61 , L_8 ,
V_29 , V_70 ) ;
} else if ( ! strcmp ( V_59 , V_71 ) ||
! strcmp ( V_59 , V_72 ) ) {
V_9 -> type = V_73 ;
strcpy ( V_60 , V_74 ) ;
sprintf ( V_61 , L_8 ,
V_29 , V_75 ) ;
} else if ( ! strcmp ( V_59 , V_76 ) ) {
V_9 -> type = V_25 ;
strcpy ( V_60 , V_77 ) ;
sprintf ( V_61 , L_8 ,
V_29 , V_31 ) ;
} else {
F_16 (KERN_ERR PREFIX L_9 , hid) ;
error = - V_6 ;
goto V_78;
}
error = F_15 ( V_2 ) ;
if ( error )
goto V_78;
snprintf ( V_9 -> V_79 , sizeof( V_9 -> V_79 ) , L_10 , V_59 ) ;
V_11 -> V_60 = V_60 ;
V_11 -> V_79 = V_9 -> V_79 ;
V_11 -> V_80 . V_81 = V_82 ;
V_11 -> V_80 . V_83 = V_9 -> type ;
V_11 -> V_13 . V_84 = & V_2 -> V_13 ;
switch ( V_9 -> type ) {
case V_68 :
F_45 ( V_11 , V_85 , V_54 ) ;
break;
case V_73 :
F_45 ( V_11 , V_85 , V_52 ) ;
break;
case V_25 :
F_45 ( V_11 , V_86 , V_12 ) ;
break;
}
error = F_46 ( V_11 ) ;
if ( error )
goto V_87;
if ( V_9 -> type == V_25 ) {
F_29 ( V_2 ) ;
V_41 = V_2 ;
}
F_16 (KERN_INFO PREFIX L_11 , name, acpi_device_bid(device)) ;
return 0 ;
V_87:
F_22 ( V_2 ) ;
V_78:
F_47 ( V_11 ) ;
V_65:
F_48 ( V_9 ) ;
return error ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
F_22 ( V_2 ) ;
F_50 ( V_9 -> V_11 ) ;
F_48 ( V_9 ) ;
return 0 ;
}
static int F_51 ( const char * V_88 , struct V_89 * V_90 )
{
int V_91 = 0 ;
if ( ! strncmp ( V_88 , L_4 , sizeof( L_4 ) - 1 ) ) {
V_42 = V_43 ;
F_52 ( L_12 ) ;
} else if ( ! strncmp ( V_88 , L_13 , sizeof( L_13 ) - 1 ) ) {
V_42 = V_44 ;
F_52 ( L_14 ) ;
} else if ( ! strncmp ( V_88 , L_15 , sizeof( L_15 ) - 1 ) ) {
V_42 = V_45 ;
F_52 ( L_16 ) ;
} else
V_91 = - V_92 ;
return V_91 ;
}
static int F_53 ( char * V_93 , struct V_89 * V_90 )
{
switch ( V_42 ) {
case V_43 :
return sprintf ( V_93 , L_4 ) ;
case V_44 :
return sprintf ( V_93 , L_13 ) ;
case V_45 :
return sprintf ( V_93 , L_15 ) ;
default:
return sprintf ( V_93 , L_17 ) ;
}
return 0 ;
}
