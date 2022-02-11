static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 -> V_6 ;
F_2 ( V_6 , L_1 , V_4 -> V_7 ) ;
F_2 ( V_6 , L_2 , V_4 -> V_8 ) ;
F_2 ( V_6 , L_3 , F_3 ( V_4 -> V_9 ) ) ;
F_2 ( V_6 , L_4 , V_4 -> V_10 ) ;
F_2 ( V_6 , L_5 , V_4 -> V_11 ) ;
F_2 ( V_6 , L_6 , V_4 -> V_12 ) ;
F_2 ( V_6 , L_7 , F_3 ( V_4 -> V_13 ) ) ;
F_2 ( V_6 , L_8 , V_4 -> V_14 ) ;
F_2 ( V_6 , L_9 , V_4 -> V_15 ) ;
F_2 ( V_6 , L_10 , V_4 -> V_16 ) ;
}
static struct V_3 *
F_4 ( struct V_1 * V_2 , unsigned int V_17 )
{
struct V_18 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return NULL ;
V_19 = F_6 ( V_6 , F_7 ( V_6 , 0 ) ,
V_21 ,
V_22 | V_23 | V_24 ,
0 , V_17 , V_4 , sizeof( * V_4 ) , 1000 ) ;
F_2 ( & V_2 -> V_6 -> V_6 , L_11 , V_25 , V_19 ) ;
if ( V_19 < sizeof( * V_4 ) ) {
F_2 ( & V_2 -> V_6 -> V_6 ,
L_12 , V_25 ,
( V_19 < 0 ) ? L_13 : L_14 , V_19 ) ;
goto error;
}
if ( V_4 -> V_8 != V_26 ) {
F_2 ( & V_2 -> V_6 -> V_6 , L_15 ,
V_25 ) ;
goto error;
}
F_1 ( V_2 , V_4 ) ;
return V_4 ;
error:
F_8 ( V_4 ) ;
return NULL ;
}
static T_1 F_9 ( T_1 V_27 )
{
T_1 V_28 ;
switch ( V_27 ) {
case 48 :
V_28 = 0x10 ;
break;
case 28 :
case 24 :
V_28 = 0x20 ;
break;
default:
case 12 :
V_28 = 0x30 ;
break;
case 5 :
case 6 :
V_28 = 0x40 ;
break;
case 3 :
V_28 = 0x50 ;
break;
case 2 :
V_28 = 0x60 ;
break;
case 1 :
V_28 = 0x70 ;
break;
case 0 :
V_28 = 0x80 ;
break;
}
return ( V_28 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_29 ;
V_29 = F_4 ( V_2 , 0 ) ;
if ( ! V_29 ) {
F_11 ( & V_2 -> V_6 -> V_6 ,
L_16 ) ;
return - V_30 ;
}
F_2 ( & V_2 -> V_6 -> V_6 ,
L_17 ,
V_25 ,
( V_29 -> V_13 & V_31 ) ? L_18 : L_19 ,
( V_29 -> V_13 & V_32 ) ? L_20 : L_19 ,
( V_29 -> V_13 & V_33 ) ? L_21 : L_19 ,
( V_29 -> V_13 & V_34 ) ? L_22 : L_19 ,
( V_29 -> V_13 & V_35 ) ? L_23 : L_19 ,
( V_29 -> V_13 & V_36 ) ? L_24 : L_19 ,
( V_29 -> V_13 & V_37 ) ? L_25 : L_19 ,
( V_29 -> V_13 & V_38 ) ? L_26 : L_19 ,
( V_29 -> V_13 & V_39 ) ? L_27 : L_19 ) ;
switch ( V_29 -> V_14 ) {
case V_40 :
V_41 = 48 ;
break;
case V_42 :
V_41 = 24 ;
break;
case V_43 :
V_41 = 12 ;
break;
case V_44 :
V_41 = 6 ;
break;
case V_45 :
V_41 = 3 ;
break;
case V_46 :
V_41 = 2 ;
break;
case V_47 :
V_41 = 1 ;
break;
case V_48 :
V_41 = 0 ;
break;
default:
break;
}
F_8 ( V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_49 * V_50 , struct V_51 * V_52 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < F_13 ( V_52 -> V_54 ) ; ++ V_53 )
V_52 -> V_54 [ V_53 ] -> V_55 = V_56 ;
return F_14 ( V_50 , V_52 ) ;
}
static int F_15 ( struct V_51 * V_52 ,
void * V_57 , T_2 V_58 )
{
unsigned char * V_59 = V_57 ;
int V_60 ;
* V_59 = V_61 | V_62 ;
V_60 = F_16 ( & V_52 -> V_63 , V_59 + 1 , V_58 - 1 ,
& V_52 -> V_64 ) ;
return V_60 + 1 ;
}
static void F_17 ( struct V_65 * V_65 )
{
struct V_51 * V_52 = V_65 -> V_66 ;
unsigned char * V_67 = V_65 -> V_68 ;
if ( ! V_65 -> V_69 )
return;
if ( * V_67 & 0x0f )
V_62 = * V_67 & 0x0f ;
if ( V_65 -> V_69 == 1 )
return;
F_18 ( & V_52 -> V_52 , V_67 + 1 , V_65 -> V_69 - 1 ) ;
F_19 ( & V_52 -> V_52 ) ;
}
static void F_20 ( struct V_65 * V_65 )
{
F_8 ( V_65 -> V_68 ) ;
if ( V_65 -> V_70 )
F_2 ( & V_65 -> V_6 -> V_6 , L_28 ,
V_25 , V_65 -> V_70 ) ;
}
static void F_21 ( struct V_49 * V_50 ,
struct V_51 * V_52 , struct V_71 * V_72 )
{
struct V_65 * V_65 ;
unsigned char * V_68 ;
int V_28 ;
T_3 V_73 ;
int V_62 ;
V_73 = F_22 ( V_50 ) ;
switch ( V_73 ) {
case 2400 :
V_62 = V_31 ;
break;
case 9600 :
V_62 = V_32 ;
break;
case 19200 :
V_62 = V_33 ;
break;
case 38400 :
V_62 = V_34 ;
break;
case 57600 :
V_62 = V_35 ;
break;
case 115200 :
V_62 = V_36 ;
break;
case 576000 :
V_62 = V_37 ;
break;
case 1152000 :
V_62 = V_38 ;
break;
case 4000000 :
V_62 = V_39 ;
break;
default:
V_62 = V_32 ;
V_73 = 9600 ;
}
if ( V_27 == - 1 )
V_61 = F_9 ( V_41 ) ;
else
V_61 = F_9 ( V_27 ) ;
F_23 ( & V_50 -> V_74 , V_72 ) ;
F_24 ( V_50 , V_73 , V_73 ) ;
V_65 = F_25 ( 0 , V_20 ) ;
if ( ! V_65 )
return;
V_68 = F_26 ( 1 , V_20 ) ;
if ( ! V_68 )
goto V_75;
* V_68 = V_61 | V_62 ;
F_27 (
V_65 ,
V_52 -> V_2 -> V_6 ,
F_28 ( V_52 -> V_2 -> V_6 ,
V_52 -> V_76 ) ,
V_68 ,
1 ,
F_20 ,
V_52 ) ;
V_65 -> V_55 = V_56 ;
V_28 = F_29 ( V_65 , V_20 ) ;
if ( V_28 ) {
F_11 ( & V_52 -> V_6 , L_29 ,
V_25 , V_28 ) ;
goto V_77;
}
F_30 ( V_65 ) ;
return;
V_77:
F_8 ( V_68 ) ;
V_75:
F_30 ( V_65 ) ;
}
static int T_4 F_31 ( void )
{
if ( V_78 ) {
V_79 . V_80 = V_78 ;
V_79 . V_81 = V_78 ;
}
return F_32 ( V_82 , V_83 , V_84 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( V_82 ) ;
}
