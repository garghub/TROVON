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
T_2 V_11 ;
bool V_12 ;
if ( V_13 != V_14 ||
V_9 -> V_15 != ! ! V_7 )
V_12 = true ;
else
V_12 = false ;
V_11 = F_6 ( V_9 -> V_16 ,
F_7 ( V_17 ) ) ;
if ( V_9 -> V_15 == ! ! V_7 &&
F_8 ( F_9 () , V_11 ) ) {
F_10 ( L_2 ) ;
if ( V_13 == V_14 ) {
V_12 = true ;
if ( ! V_7 ) {
F_11 ( V_9 -> V_18 ,
V_19 , V_7 ) ;
F_12 ( V_9 -> V_18 ) ;
}
}
}
if ( V_12 ) {
F_11 ( V_9 -> V_18 , V_19 , ! V_7 ) ;
F_12 ( V_9 -> V_18 ) ;
V_9 -> V_15 = ! ! V_7 ;
V_9 -> V_16 = F_9 () ;
}
if ( V_7 )
F_13 ( & V_2 -> V_20 , 0 ) ;
V_10 = F_14 ( & V_21 , V_7 , V_2 ) ;
if ( V_10 == V_22 )
V_10 = F_14 ( & V_21 , V_7 ,
V_2 ) ;
if ( V_10 == V_22 || V_10 == V_23 ) {
V_10 = 0 ;
}
return V_10 ;
}
static int F_15 ( struct V_24 * V_25 , void * V_26 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
F_16 ( V_25 , L_3 ,
V_7 < 0 ? L_4 : ( V_7 ? L_5 : L_6 ) ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_28 , struct V_29 * V_29 )
{
return F_18 ( V_29 , F_15 , F_19 ( V_28 ) ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_30 * V_31 = NULL ;
int V_10 = 0 ;
if ( V_9 -> type != V_32 )
return 0 ;
if ( V_33 || V_34 ) {
F_21 (KERN_ERR PREFIX L_7 ) ;
return - V_35 ;
}
V_33 = F_22 ( V_36 , V_37 ) ;
if ( ! V_33 )
return - V_6 ;
V_34 = F_22 ( V_38 , V_33 ) ;
if ( ! V_34 ) {
V_10 = - V_6 ;
goto V_39;
}
F_23 ( V_2 ) = F_22 ( F_24 ( V_2 ) , V_34 ) ;
if ( ! F_23 ( V_2 ) ) {
V_10 = - V_6 ;
goto V_40;
}
V_31 = F_25 ( V_41 ,
V_42 , F_23 ( V_2 ) ,
& V_43 , V_2 ) ;
if ( ! V_31 ) {
V_10 = - V_6 ;
goto V_44;
}
V_45:
return V_10 ;
V_44:
F_26 ( F_24 ( V_2 ) ,
V_34 ) ;
F_23 ( V_2 ) = NULL ;
V_40:
F_26 ( V_38 , V_33 ) ;
V_34 = NULL ;
V_39:
F_26 ( V_36 , V_37 ) ;
V_33 = NULL ;
goto V_45;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
if ( V_9 -> type != V_32 )
return 0 ;
F_26 ( V_41 ,
F_23 ( V_2 ) ) ;
F_26 ( F_24 ( V_2 ) ,
V_34 ) ;
F_23 ( V_2 ) = NULL ;
F_26 ( V_38 , V_33 ) ;
V_34 = NULL ;
F_26 ( V_36 , V_37 ) ;
V_33 = NULL ;
return 0 ;
}
int F_28 ( struct V_46 * V_47 )
{
return F_29 ( & V_21 , V_47 ) ;
}
int F_30 ( struct V_46 * V_47 )
{
return F_31 ( & V_21 , V_47 ) ;
}
int F_32 ( void )
{
if ( ! V_48 )
return - V_6 ;
return F_1 ( V_48 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_4 ( V_2 , V_7 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
switch ( V_13 ) {
case V_49 :
( void ) F_4 ( V_2 , 1 ) ;
break;
case V_50 :
( void ) F_33 ( V_2 ) ;
break;
case V_14 :
default:
break;
}
}
static void F_35 ( struct V_1 * V_2 , T_3 V_51 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_52 * V_18 ;
switch ( V_51 ) {
case V_53 :
V_51 = V_54 ;
case V_54 :
V_18 = V_9 -> V_18 ;
if ( V_9 -> type == V_32 ) {
F_33 ( V_2 ) ;
} else {
int V_55 ;
F_13 ( & V_2 -> V_20 , 0 ) ;
if ( V_9 -> V_56 )
break;
V_55 = F_36 ( V_57 , V_18 -> V_58 ) ?
V_57 : V_59 ;
F_37 ( V_18 , V_55 , 1 ) ;
F_12 ( V_18 ) ;
F_37 ( V_18 , V_55 , 0 ) ;
F_12 ( V_18 ) ;
F_38 (
V_2 -> V_60 . V_61 ,
F_39 ( & V_2 -> V_20 ) ,
V_51 , ++ V_9 -> V_62 ) ;
}
break;
default:
F_40 ( ( V_63 ,
L_8 , V_51 ) ) ;
break;
}
}
static int F_41 ( struct V_2 * V_20 )
{
struct V_1 * V_2 = F_42 ( V_20 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
V_9 -> V_56 = true ;
return 0 ;
}
static int F_43 ( struct V_2 * V_20 )
{
struct V_1 * V_2 = F_42 ( V_20 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
V_9 -> V_56 = false ;
if ( V_9 -> type == V_32 )
F_34 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_52 * V_18 ;
const char * V_64 = F_45 ( V_2 ) ;
char * V_65 , * V_66 ;
int error ;
V_9 = F_46 ( sizeof( struct V_8 ) , V_67 ) ;
if ( ! V_9 )
return - V_68 ;
V_2 -> V_69 = V_9 ;
V_9 -> V_18 = V_18 = F_47 () ;
if ( ! V_18 ) {
error = - V_68 ;
goto V_70;
}
V_65 = F_48 ( V_2 ) ;
V_66 = F_49 ( V_2 ) ;
if ( ! strcmp ( V_64 , V_71 ) ||
! strcmp ( V_64 , V_72 ) ) {
V_9 -> type = V_73 ;
strcpy ( V_65 , V_74 ) ;
sprintf ( V_66 , L_9 ,
V_36 , V_75 ) ;
} else if ( ! strcmp ( V_64 , V_76 ) ||
! strcmp ( V_64 , V_77 ) ) {
V_9 -> type = V_78 ;
strcpy ( V_65 , V_79 ) ;
sprintf ( V_66 , L_9 ,
V_36 , V_80 ) ;
} else if ( ! strcmp ( V_64 , V_81 ) ) {
V_9 -> type = V_32 ;
strcpy ( V_65 , V_82 ) ;
sprintf ( V_66 , L_9 ,
V_36 , V_38 ) ;
V_9 -> V_15 = ! ! F_1 ( V_2 ) ;
V_9 -> V_16 = F_9 () ;
} else {
F_21 (KERN_ERR PREFIX L_10 , hid) ;
error = - V_6 ;
goto V_83;
}
error = F_20 ( V_2 ) ;
if ( error )
goto V_83;
snprintf ( V_9 -> V_84 , sizeof( V_9 -> V_84 ) , L_11 , V_64 ) ;
V_18 -> V_65 = V_65 ;
V_18 -> V_84 = V_9 -> V_84 ;
V_18 -> V_85 . V_86 = V_87 ;
V_18 -> V_85 . V_88 = V_9 -> type ;
V_18 -> V_20 . V_89 = & V_2 -> V_20 ;
switch ( V_9 -> type ) {
case V_73 :
F_50 ( V_18 , V_90 , V_59 ) ;
break;
case V_78 :
F_50 ( V_18 , V_90 , V_57 ) ;
break;
case V_32 :
F_50 ( V_18 , V_91 , V_19 ) ;
break;
}
error = F_51 ( V_18 ) ;
if ( error )
goto V_92;
if ( V_9 -> type == V_32 ) {
F_34 ( V_2 ) ;
V_48 = V_2 ;
}
F_21 (KERN_INFO PREFIX L_12 , name, acpi_device_bid(device)) ;
return 0 ;
V_92:
F_27 ( V_2 ) ;
V_83:
F_52 ( V_18 ) ;
V_70:
F_53 ( V_9 ) ;
return error ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
F_27 ( V_2 ) ;
F_55 ( V_9 -> V_18 ) ;
F_53 ( V_9 ) ;
return 0 ;
}
static int F_56 ( const char * V_93 , struct V_94 * V_95 )
{
int V_96 = 0 ;
if ( ! strncmp ( V_93 , L_5 , sizeof( L_5 ) - 1 ) ) {
V_13 = V_49 ;
F_57 ( L_13 ) ;
} else if ( ! strncmp ( V_93 , L_14 , sizeof( L_14 ) - 1 ) ) {
V_13 = V_50 ;
F_57 ( L_15 ) ;
} else if ( ! strncmp ( V_93 , L_16 , sizeof( L_16 ) - 1 ) ) {
V_13 = V_14 ;
F_57 ( L_17 ) ;
} else
V_96 = - V_97 ;
return V_96 ;
}
static int F_58 ( char * V_98 , struct V_94 * V_95 )
{
switch ( V_13 ) {
case V_49 :
return sprintf ( V_98 , L_5 ) ;
case V_50 :
return sprintf ( V_98 , L_14 ) ;
case V_14 :
return sprintf ( V_98 , L_16 ) ;
default:
return sprintf ( V_98 , L_18 ) ;
}
return 0 ;
}
