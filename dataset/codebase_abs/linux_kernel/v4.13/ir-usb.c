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
int V_30 ;
V_29 = F_4 ( V_2 , 0 ) ;
if ( ! V_29 ) {
F_11 ( & V_2 -> V_6 -> V_6 ,
L_16 ) ;
return - V_31 ;
}
V_30 = F_12 ( V_29 -> V_13 ) ;
F_2 ( & V_2 -> V_6 -> V_6 ,
L_17 ,
V_25 ,
( V_30 & V_32 ) ? L_18 : L_19 ,
( V_30 & V_33 ) ? L_20 : L_19 ,
( V_30 & V_34 ) ? L_21 : L_19 ,
( V_30 & V_35 ) ? L_22 : L_19 ,
( V_30 & V_36 ) ? L_23 : L_19 ,
( V_30 & V_37 ) ? L_24 : L_19 ,
( V_30 & V_38 ) ? L_25 : L_19 ,
( V_30 & V_39 ) ? L_26 : L_19 ,
( V_30 & V_40 ) ? L_27 : L_19 ) ;
switch ( V_29 -> V_14 ) {
case V_41 :
V_42 = 48 ;
break;
case V_43 :
V_42 = 24 ;
break;
case V_44 :
V_42 = 12 ;
break;
case V_45 :
V_42 = 6 ;
break;
case V_46 :
V_42 = 3 ;
break;
case V_47 :
V_42 = 2 ;
break;
case V_48 :
V_42 = 1 ;
break;
case V_49 :
V_42 = 0 ;
break;
default:
break;
}
F_8 ( V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < F_14 ( V_53 -> V_55 ) ; ++ V_54 )
V_53 -> V_55 [ V_54 ] -> V_56 = V_57 ;
return F_15 ( V_51 , V_53 ) ;
}
static int F_16 ( struct V_52 * V_53 ,
void * V_58 , T_2 V_59 )
{
unsigned char * V_60 = V_58 ;
int V_61 ;
* V_60 = V_62 | V_63 ;
V_61 = F_17 ( & V_53 -> V_64 , V_60 + 1 , V_59 - 1 ,
& V_53 -> V_65 ) ;
return V_61 + 1 ;
}
static void F_18 ( struct V_66 * V_66 )
{
struct V_52 * V_53 = V_66 -> V_67 ;
unsigned char * V_68 = V_66 -> V_69 ;
if ( ! V_66 -> V_70 )
return;
if ( * V_68 & 0x0f )
V_63 = * V_68 & 0x0f ;
if ( V_66 -> V_70 == 1 )
return;
F_19 ( & V_53 -> V_53 , V_68 + 1 , V_66 -> V_70 - 1 ) ;
F_20 ( & V_53 -> V_53 ) ;
}
static void F_21 ( struct V_66 * V_66 )
{
F_8 ( V_66 -> V_69 ) ;
if ( V_66 -> V_71 )
F_2 ( & V_66 -> V_6 -> V_6 , L_28 ,
V_25 , V_66 -> V_71 ) ;
}
static void F_22 ( struct V_50 * V_51 ,
struct V_52 * V_53 , struct V_72 * V_73 )
{
struct V_66 * V_66 ;
unsigned char * V_69 ;
int V_28 ;
T_3 V_74 ;
int V_63 ;
V_74 = F_23 ( V_51 ) ;
switch ( V_74 ) {
case 2400 :
V_63 = V_32 ;
break;
case 9600 :
V_63 = V_33 ;
break;
case 19200 :
V_63 = V_34 ;
break;
case 38400 :
V_63 = V_35 ;
break;
case 57600 :
V_63 = V_36 ;
break;
case 115200 :
V_63 = V_37 ;
break;
case 576000 :
V_63 = V_38 ;
break;
case 1152000 :
V_63 = V_39 ;
break;
case 4000000 :
V_63 = V_40 ;
break;
default:
V_63 = V_33 ;
V_74 = 9600 ;
}
if ( V_27 == - 1 )
V_62 = F_9 ( V_42 ) ;
else
V_62 = F_9 ( V_27 ) ;
F_24 ( & V_51 -> V_75 , V_73 ) ;
F_25 ( V_51 , V_74 , V_74 ) ;
V_66 = F_26 ( 0 , V_20 ) ;
if ( ! V_66 )
return;
V_69 = F_27 ( 1 , V_20 ) ;
if ( ! V_69 )
goto V_76;
* V_69 = V_62 | V_63 ;
F_28 (
V_66 ,
V_53 -> V_2 -> V_6 ,
F_29 ( V_53 -> V_2 -> V_6 ,
V_53 -> V_77 ) ,
V_69 ,
1 ,
F_21 ,
V_53 ) ;
V_66 -> V_56 = V_57 ;
V_28 = F_30 ( V_66 , V_20 ) ;
if ( V_28 ) {
F_11 ( & V_53 -> V_6 , L_29 ,
V_25 , V_28 ) ;
goto V_78;
}
F_31 ( V_66 ) ;
return;
V_78:
F_8 ( V_69 ) ;
V_76:
F_31 ( V_66 ) ;
}
static int T_4 F_32 ( void )
{
if ( V_79 ) {
V_80 . V_81 = V_79 ;
V_80 . V_82 = V_79 ;
}
return F_33 ( V_83 , V_84 , V_85 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( V_83 ) ;
}
