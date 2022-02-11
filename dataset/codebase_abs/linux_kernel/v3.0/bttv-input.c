static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
if ( V_4 -> V_9 ) {
if ( V_4 -> V_10 == V_6 )
return;
V_4 -> V_10 = V_6 ;
}
V_7 = F_3 ( V_6 , V_4 -> V_11 ) ;
F_4 (KERN_INFO DEVNAME L_1 ,
gpio, data,
ir->polling ? L_2 : L_3 ,
(gpio & ir->mask_keydown) ? L_4 : L_5 ,
(gpio & ir->mask_keyup) ? L_6 : L_5 ) ;
if ( ( V_4 -> V_12 && ( V_6 & V_4 -> V_12 ) ) ||
( V_4 -> V_13 && ! ( V_6 & V_4 -> V_13 ) ) ) {
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
} else {
if ( V_2 -> V_8 . type == V_15 )
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
F_6 ( V_4 -> V_14 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_16 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_7 = F_3 ( V_6 , V_4 -> V_11 ) ;
V_16 = ( V_6 & V_4 -> V_13 ) ? 1 << 31 : 0 ;
if ( ( V_4 -> V_10 & 0x7f ) != V_7 ) {
F_4 (KERN_INFO DEVNAME L_7 ,
gpio, data,
(gpio & ir->mask_keyup) ? L_6 : L_8 ) ;
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
if ( V_16 )
F_6 ( V_4 -> V_14 ) ;
} else {
if ( ( V_4 -> V_10 & 1 << 31 ) == V_16 )
return;
F_4 (KERN_INFO DEVNAME L_9 ,
gpio, data,
(gpio & ir->mask_keyup) ? L_6 : L_10 ) ;
if ( V_16 )
F_6 ( V_4 -> V_14 ) ;
else
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
}
V_4 -> V_10 = V_7 | V_16 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_17 )
F_9 ( V_2 ) ;
else if ( ! V_4 -> V_9 )
F_1 ( V_2 ) ;
}
static void F_10 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_8 . type == V_18 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_11 ( & V_4 -> V_19 , V_20 + F_12 ( V_4 -> V_9 ) ) ;
}
static T_1 F_13 ( unsigned int V_21 )
{
unsigned int V_22 = V_21 ;
unsigned int V_23 ;
unsigned int V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < 14 ; ++ V_25 ) {
V_23 = V_21 & 0x3 ;
V_21 >>= 2 ;
V_24 <<= 1 ;
switch ( V_23 ) {
case 0 :
case 2 :
break;
case 1 :
V_24 |= 1 ;
break;
case 3 :
F_4 (KERN_INFO DEVNAME L_11 ,
org_code) ;
return 0 ;
}
}
F_4 (KERN_INFO DEVNAME L_12
L_13
L_14 , rc5, org_code, RC5_START(rc5),
RC5_TOGGLE(rc5), RC5_ADDR(rc5), RC5_INSTR(rc5)) ;
return V_24 ;
}
static void F_14 ( unsigned long V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_7 ;
struct V_26 V_27 ;
T_1 V_28 ;
T_1 V_24 = 0 ;
F_15 ( & V_27 ) ;
if ( V_27 . V_29 - V_4 -> V_30 . V_29 > 1 ) {
V_28 = 200000 ;
} else {
V_28 = 1000000 * ( V_27 . V_29 - V_4 -> V_30 . V_29 ) +
V_27 . V_31 - V_4 -> V_30 . V_31 ;
}
V_4 -> V_32 = false ;
if ( V_28 < 28000 ) {
F_4 (KERN_INFO DEVNAME L_15 ) ;
return;
}
if ( V_4 -> V_33 < 20 ) {
F_4 (KERN_INFO DEVNAME L_16 , ir->code) ;
} else {
V_4 -> V_21 = ( V_4 -> V_21 << V_4 -> V_34 ) | 1 ;
V_24 = F_13 ( V_4 -> V_21 ) ;
if ( F_16 ( V_24 ) != V_4 -> V_35 ) {
F_17 (KERN_INFO DEVNAME L_12
L_17 , RC5_START(rc5)) ;
} else if ( F_18 ( V_24 ) == V_4 -> V_36 ) {
T_1 V_37 = F_19 ( V_24 ) ;
T_1 V_38 = F_20 ( V_24 ) ;
F_21 ( V_4 -> V_14 , V_38 , V_37 ) ;
F_4 (KERN_INFO DEVNAME L_12
L_18 ,
instr, toggle) ;
}
}
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 V_27 ;
T_1 V_6 ;
T_1 V_28 ;
unsigned long V_39 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_39 = V_20 ;
F_15 ( & V_27 ) ;
if ( V_27 . V_29 - V_4 -> V_30 . V_29 > 1 ) {
V_28 = 200000 ;
} else {
V_28 = 1000000 * ( V_27 . V_29 - V_4 -> V_30 . V_29 ) +
V_27 . V_31 - V_4 -> V_30 . V_31 ;
}
F_4 (KERN_INFO DEVNAME L_19 ,
gap, (gpio & 0x20) ? L_20 : L_21 ) ;
if ( ! ( V_6 & 0x20 ) )
return 0 ;
if ( V_4 -> V_32 ) {
if ( V_4 -> V_33 < 28 ) {
V_4 -> V_33 = ( V_28 - V_40 / 2 ) /
V_40 ;
V_4 -> V_21 |= 1 << V_4 -> V_33 ;
}
} else {
V_4 -> V_32 = true ;
V_4 -> V_21 = 0 ;
V_4 -> V_30 = V_27 ;
V_4 -> V_33 = 0 ;
F_11 ( & V_4 -> V_19 , V_39 + F_12 ( 30 ) ) ;
}
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_22 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 ) {
F_24 ( & V_4 -> V_19 , F_10 , ( unsigned long ) V_2 ) ;
V_4 -> V_19 . V_41 = V_20 + F_12 ( 1000 ) ;
F_25 ( & V_4 -> V_19 ) ;
} else if ( V_4 -> V_17 ) {
F_24 ( & V_4 -> V_19 , F_14 , ( unsigned long ) V_4 ) ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = 3 ;
V_4 -> V_36 = 0x0 ;
V_4 -> V_42 = V_40 ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_9 )
F_27 ( & V_2 -> V_5 -> V_19 ) ;
if ( V_2 -> V_5 -> V_17 ) {
T_1 V_6 ;
F_27 ( & V_2 -> V_5 -> V_19 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
}
}
static int F_28 ( struct V_43 * V_4 , T_1 * V_44 , T_1 * V_45 )
{
unsigned char V_46 ;
if ( 1 != F_29 ( V_4 -> V_8 , & V_46 , 1 ) ) {
F_4 (KERN_INFO DEVNAME L_22 ) ;
return - V_47 ;
}
if ( V_46 == 0xaa )
return 0 ;
F_4 (KERN_INFO DEVNAME L_23 , b) ;
* V_44 = V_46 ;
* V_45 = V_46 ;
return 1 ;
}
void T_2 F_30 ( struct V_1 * V_2 )
{
const unsigned short V_48 [] = {
0x1a , 0x18 , 0x64 , 0x30 , 0x71 ,
V_49
} ;
struct V_50 V_51 ;
if ( 0 != V_2 -> V_52 )
return;
memset ( & V_51 , 0 , sizeof( struct V_50 ) ) ;
memset ( & V_2 -> V_53 , 0 , sizeof( V_2 -> V_53 ) ) ;
F_31 ( V_51 . type , L_24 , V_54 ) ;
switch ( V_2 -> V_8 . type ) {
case V_55 :
V_2 -> V_53 . V_56 = L_25 ;
V_2 -> V_53 . V_57 = F_28 ;
V_2 -> V_53 . V_58 = V_59 ;
V_51 . V_36 = 0x4b ;
break;
default:
F_32 ( & V_2 -> V_8 . V_60 , & V_51 , V_48 , NULL ) ;
return;
}
if ( V_2 -> V_53 . V_56 )
V_51 . V_61 = & V_2 -> V_53 ;
F_33 ( & V_2 -> V_8 . V_60 , & V_51 ) ;
return;
}
int T_3 F_34 ( struct V_1 * V_2 )
{
if ( 0 != V_2 -> V_52 )
return 0 ;
return F_35 ( & V_2 -> V_8 . V_60 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
char * V_58 = NULL ;
struct V_62 * V_63 ;
int V_64 = - V_65 ;
if ( ! V_2 -> V_66 )
return - V_67 ;
V_4 = F_37 ( sizeof( * V_4 ) , V_68 ) ;
V_63 = F_38 () ;
if ( ! V_4 || ! V_63 )
goto V_69;
switch ( V_2 -> V_8 . type ) {
case V_70 :
case V_71 :
case V_72 :
V_58 = V_73 ;
V_4 -> V_11 = 0xf88000 ;
V_4 -> V_12 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_74 :
case V_75 :
V_58 = V_76 ;
V_4 -> V_11 = 0x0f00c0 ;
V_4 -> V_12 = 0x000020 ;
V_4 -> V_9 = 50 ;
break;
case V_77 :
V_58 = V_78 ;
V_4 -> V_11 = 0x003e00 ;
V_4 -> V_13 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_79 :
case V_80 :
case V_81 :
V_58 = V_78 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_15 :
V_58 = V_82 ;
V_4 -> V_11 = 0x1f8 ;
break;
case V_83 :
case V_84 :
V_58 = V_82 ;
V_4 -> V_11 = 0x0008e000 ;
V_4 -> V_12 = 0x00200000 ;
break;
case V_85 :
V_58 = V_86 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_87 :
case V_88 :
case V_89 :
V_58 = V_78 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_90 :
V_58 = V_91 ;
V_4 -> V_17 = true ;
break;
case V_92 :
V_58 = V_86 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x004000 ;
V_4 -> V_9 = 50 ;
break;
case V_93 :
V_58 = V_94 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_18 :
V_58 = V_95 ;
V_4 -> V_11 = 0x00fd00 ;
V_4 -> V_13 = 0x000080 ;
V_4 -> V_9 = 1 ;
V_4 -> V_10 = F_3 ( F_2 ( & V_2 -> V_8 ) ,
V_4 -> V_11 ) ;
break;
}
if ( NULL == V_58 ) {
F_4 ( V_96 L_26 , V_2 -> V_8 . type ) ;
V_64 = - V_67 ;
goto V_69;
}
if ( V_4 -> V_17 ) {
T_1 V_6 ;
F_39 ( & V_2 -> V_8 , ( 1 << 4 ) , 1 << 4 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_22 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
} else {
F_39 ( & V_2 -> V_8 , V_4 -> V_11 | V_4 -> V_12 , 0 ) ;
}
V_4 -> V_14 = V_63 ;
snprintf ( V_4 -> V_56 , sizeof( V_4 -> V_56 ) , L_27 ,
V_2 -> V_8 . type ) ;
snprintf ( V_4 -> V_97 , sizeof( V_4 -> V_97 ) , L_28 ,
F_40 ( V_2 -> V_8 . V_98 ) ) ;
V_63 -> V_99 = V_4 -> V_56 ;
V_63 -> V_100 = V_4 -> V_97 ;
V_63 -> V_101 . V_102 = V_103 ;
V_63 -> V_101 . V_104 = 1 ;
if ( V_2 -> V_8 . V_98 -> V_105 ) {
V_63 -> V_101 . V_106 = V_2 -> V_8 . V_98 -> V_105 ;
V_63 -> V_101 . V_107 = V_2 -> V_8 . V_98 -> V_108 ;
} else {
V_63 -> V_101 . V_106 = V_2 -> V_8 . V_98 -> V_106 ;
V_63 -> V_101 . V_107 = V_2 -> V_8 . V_98 -> V_109 ;
}
V_63 -> V_14 . V_110 = & V_2 -> V_8 . V_98 -> V_14 ;
V_63 -> V_111 = V_58 ;
V_63 -> V_112 = V_113 ;
V_2 -> V_5 = V_4 ;
F_23 ( V_2 , V_4 ) ;
V_64 = F_41 ( V_63 ) ;
if ( V_64 )
goto V_114;
return 0 ;
V_114:
F_26 ( V_2 ) ;
V_2 -> V_5 = NULL ;
V_69:
F_42 ( V_63 ) ;
F_43 ( V_4 ) ;
return V_64 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == NULL )
return;
F_26 ( V_2 ) ;
F_45 ( V_2 -> V_5 -> V_14 ) ;
F_43 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
