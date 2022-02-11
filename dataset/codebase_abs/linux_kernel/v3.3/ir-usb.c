static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 -> V_3 ) ;
F_2 ( L_2 , V_2 -> V_4 ) ;
F_2 ( L_3 , F_3 ( V_2 -> V_5 ) ) ;
F_2 ( L_4 , V_2 -> V_6 ) ;
F_2 ( L_5 , V_2 -> V_7 ) ;
F_2 ( L_6 , V_2 -> V_8 ) ;
F_2 ( L_7 , F_3 ( V_2 -> V_9 ) ) ;
F_2 ( L_8 , V_2 -> V_10 ) ;
F_2 ( L_9 , V_2 -> V_11 ) ;
F_2 ( L_10 , V_2 -> V_12 ) ;
}
static struct V_1 *
F_4 ( struct V_13 * V_14 , unsigned int V_15 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_5 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return NULL ;
V_16 = F_6 ( V_14 , F_7 ( V_14 , 0 ) ,
V_18 ,
V_19 | V_20 | V_21 ,
0 , V_15 , V_2 , sizeof( * V_2 ) , 1000 ) ;
F_2 ( L_11 , V_22 , V_16 ) ;
if ( V_16 < sizeof( * V_2 ) ) {
F_2 ( L_12 ,
V_22 ,
( V_16 < 0 ) ? L_13 : L_14 ,
V_16 ) ;
goto error;
}
if ( V_2 -> V_4 != V_23 ) {
F_2 ( L_15 , V_22 ) ;
goto error;
}
F_1 ( V_2 ) ;
return V_2 ;
error:
F_8 ( V_2 ) ;
return NULL ;
}
static T_1 F_9 ( T_1 V_24 )
{
T_1 V_25 ;
switch ( V_24 ) {
case 48 :
V_25 = 0x10 ;
break;
case 28 :
case 24 :
V_25 = 0x20 ;
break;
default:
case 12 :
V_25 = 0x30 ;
break;
case 5 :
case 6 :
V_25 = 0x40 ;
break;
case 3 :
V_25 = 0x50 ;
break;
case 2 :
V_25 = 0x60 ;
break;
case 1 :
V_25 = 0x70 ;
break;
case 0 :
V_25 = 0x80 ;
break;
}
return ( V_25 ) ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_1 * V_28 ;
V_28 = F_4 ( V_27 -> V_14 , 0 ) ;
if ( ! V_28 ) {
F_11 ( & V_27 -> V_14 -> V_14 ,
L_16 ) ;
return - V_29 ;
}
F_2 ( L_17 ,
V_22 ,
( V_28 -> V_9 & V_30 ) ? L_18 : L_19 ,
( V_28 -> V_9 & V_31 ) ? L_20 : L_19 ,
( V_28 -> V_9 & V_32 ) ? L_21 : L_19 ,
( V_28 -> V_9 & V_33 ) ? L_22 : L_19 ,
( V_28 -> V_9 & V_34 ) ? L_23 : L_19 ,
( V_28 -> V_9 & V_35 ) ? L_24 : L_19 ,
( V_28 -> V_9 & V_36 ) ? L_25 : L_19 ,
( V_28 -> V_9 & V_37 ) ? L_26 : L_19 ,
( V_28 -> V_9 & V_38 ) ? L_27 : L_19 ) ;
switch ( V_28 -> V_10 ) {
case V_39 :
V_40 = 48 ;
break;
case V_41 :
V_40 = 24 ;
break;
case V_42 :
V_40 = 12 ;
break;
case V_43 :
V_40 = 6 ;
break;
case V_44 :
V_40 = 3 ;
break;
case V_45 :
V_40 = 2 ;
break;
case V_46 :
V_40 = 1 ;
break;
case V_47 :
V_40 = 0 ;
break;
default:
break;
}
F_8 ( V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
int V_52 ;
F_2 ( L_28 , V_22 , V_51 -> V_53 ) ;
for ( V_52 = 0 ; V_52 < F_13 ( V_51 -> V_54 ) ; ++ V_52 )
V_51 -> V_54 [ V_52 ] -> V_55 = V_56 ;
return F_14 ( V_49 , V_51 ) ;
}
static int F_15 ( struct V_50 * V_51 ,
void * V_57 , T_2 V_58 )
{
unsigned char * V_59 = V_57 ;
int V_60 ;
* V_59 = V_61 | V_62 ;
V_60 = F_16 ( & V_51 -> V_63 , V_59 + 1 , V_58 - 1 ,
& V_51 -> V_64 ) ;
return V_60 + 1 ;
}
static void F_17 ( struct V_65 * V_65 )
{
struct V_50 * V_51 = V_65 -> V_66 ;
unsigned char * V_67 = V_65 -> V_68 ;
struct V_48 * V_49 ;
if ( ! V_65 -> V_69 )
return;
if ( * V_67 & 0x0f )
V_62 = * V_67 & 0x0f ;
if ( V_65 -> V_69 == 1 )
return;
V_49 = F_18 ( & V_51 -> V_51 ) ;
if ( ! V_49 )
return;
F_19 ( V_49 , V_67 + 1 , V_65 -> V_69 - 1 ) ;
F_20 ( V_49 ) ;
F_21 ( V_49 ) ;
}
static void F_22 ( struct V_65 * V_65 )
{
struct V_50 * V_51 = V_65 -> V_66 ;
int V_70 = V_65 -> V_70 ;
F_2 ( L_28 , V_22 , V_51 -> V_53 ) ;
F_8 ( V_65 -> V_68 ) ;
if ( V_70 )
F_2 ( L_29 , V_22 , V_70 ) ;
}
static void F_23 ( struct V_48 * V_49 ,
struct V_50 * V_51 , struct V_71 * V_72 )
{
struct V_65 * V_65 ;
unsigned char * V_68 ;
int V_25 ;
T_3 V_73 ;
int V_62 ;
F_2 ( L_28 , V_22 , V_51 -> V_53 ) ;
V_73 = F_24 ( V_49 ) ;
switch ( V_73 ) {
case 2400 :
V_62 = V_30 ;
break;
case 9600 :
V_62 = V_31 ;
break;
case 19200 :
V_62 = V_32 ;
break;
case 38400 :
V_62 = V_33 ;
break;
case 57600 :
V_62 = V_34 ;
break;
case 115200 :
V_62 = V_35 ;
break;
case 576000 :
V_62 = V_36 ;
break;
case 1152000 :
V_62 = V_37 ;
break;
case 4000000 :
V_62 = V_38 ;
break;
default:
V_62 = V_31 ;
V_73 = 9600 ;
}
if ( V_24 == - 1 )
V_61 = F_9 ( V_40 ) ;
else
V_61 = F_9 ( V_24 ) ;
F_25 ( V_49 -> V_74 , V_72 ) ;
F_26 ( V_49 , V_73 , V_73 ) ;
V_65 = F_27 ( 0 , V_17 ) ;
if ( ! V_65 ) {
F_11 ( & V_51 -> V_14 , L_30 , V_22 ) ;
return;
}
V_68 = F_28 ( 1 , V_17 ) ;
if ( ! V_68 ) {
F_11 ( & V_51 -> V_14 , L_31 , V_22 ) ;
goto V_75;
}
* V_68 = V_61 | V_62 ;
F_29 (
V_65 ,
V_51 -> V_27 -> V_14 ,
F_30 ( V_51 -> V_27 -> V_14 ,
V_51 -> V_76 ) ,
V_68 ,
1 ,
F_22 ,
V_51 ) ;
V_65 -> V_55 = V_56 ;
V_25 = F_31 ( V_65 , V_17 ) ;
if ( V_25 ) {
F_11 ( & V_51 -> V_14 , L_32 ,
V_22 , V_25 ) ;
goto V_77;
}
F_32 ( V_65 ) ;
return;
V_77:
F_8 ( V_68 ) ;
V_75:
F_32 ( V_65 ) ;
}
static int T_4 F_33 ( void )
{
int V_78 ;
if ( V_79 ) {
V_80 . V_81 = V_79 ;
V_80 . V_82 = V_79 ;
}
V_78 = F_34 ( & V_80 ) ;
if ( V_78 )
goto V_83;
V_78 = F_35 ( & V_84 ) ;
if ( V_78 )
goto V_85;
F_36 (KERN_INFO KBUILD_MODNAME L_33 DRIVER_VERSION L_34
DRIVER_DESC L_35 ) ;
return 0 ;
V_85:
F_37 ( & V_80 ) ;
V_83:
return V_78 ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_84 ) ;
F_37 ( & V_80 ) ;
}
