static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
int V_4 ;
for ( V_4 = 10000 ; V_4 ; V_4 -- )
if ( ( F_2 ( F_3 ( V_2 , V_5 ) ) & 0x80 ) == 0 ) {
F_4 ( V_3 , F_3 ( V_2 , V_6 ) ) ;
return 1 ;
}
#ifdef F_5
F_6 ( V_7 L_1 , V_3 ) ;
#endif
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 1000 ; V_4 ; V_4 -- )
if ( F_2 ( F_3 ( V_2 , V_8 ) ) & 0x80 )
return F_2 ( F_3 ( V_2 , V_9 ) ) ;
F_8 ( L_2 , F_3 ( V_2 , V_8 ) , F_2 ( F_3 ( V_2 , V_8 ) ) ) ;
return - V_10 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_11 , unsigned char V_12 )
{
if ( ! F_1 ( V_2 , V_11 ) )
return 0 ;
return F_1 ( V_2 , V_12 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned char V_11 )
{
if ( ! F_1 ( V_2 , 0xc0 ) )
return - 1 ;
if ( ! F_1 ( V_2 , V_11 ) )
return - 1 ;
return F_7 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 ,
unsigned char V_11 , unsigned char V_12 )
{
F_4 ( V_11 , F_3 ( V_2 , V_13 ) ) ;
F_12 ( 10 ) ;
F_4 ( V_12 , F_3 ( V_2 , V_14 ) ) ;
F_12 ( 10 ) ;
}
static unsigned char F_13 ( struct V_1 * V_2 , unsigned char V_11 )
{
unsigned char V_15 ;
F_4 ( V_11 , F_3 ( V_2 , V_13 ) ) ;
F_12 ( 10 ) ;
V_15 = F_2 ( F_3 ( V_2 , V_14 ) ) ;
F_12 ( 10 ) ;
return V_15 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_4 ;
F_4 ( 3 , F_3 ( V_2 , V_16 ) ) ;
F_12 ( 10 ) ;
F_4 ( 0 , F_3 ( V_2 , V_16 ) ) ;
F_12 ( 30 ) ;
for ( V_4 = 0 ; V_4 < 1000 && ! ( F_2 ( F_3 ( V_2 , V_8 ) ) & 0x80 ) ; V_4 ++ ) ;
if ( F_2 ( F_3 ( V_2 , V_9 ) ) != 0xaa ) {
F_8 ( L_3 , V_2 -> V_17 ) ;
return - V_10 ;
}
F_1 ( V_2 , 0xc6 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
unsigned short V_19 , V_20 , V_21 ;
int V_4 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_24 ) ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_24 ) ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_24 ) ) ;
F_2 ( F_3 ( V_2 , V_23 ) ) ;
F_2 ( F_3 ( V_2 , V_25 ) ) ;
if ( F_14 ( V_2 ) < 0 ) {
F_17 ( L_4 , V_2 -> V_17 , F_2 ( F_3 ( V_2 , V_9 ) ) ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
return - V_10 ;
}
F_1 ( V_2 , 0xe7 ) ;
for ( V_4 = 1000 , V_19 = V_20 = 0 ; V_4 ; V_4 -- ) {
if ( F_2 ( F_3 ( V_2 , V_8 ) ) & 0x80 ) {
if ( V_19 == 0 ) {
V_19 = F_2 ( F_3 ( V_2 , V_9 ) ) ;
} else {
V_20 = F_2 ( F_3 ( V_2 , V_9 ) ) ;
}
}
}
F_18 ( & V_2 -> V_22 , V_18 ) ;
F_17 ( L_5 , V_2 -> V_17 , V_19 , V_20 ) ;
V_2 -> V_26 = ( V_19 << 8 ) | V_20 ;
if ( ! V_2 -> V_26 )
return - V_10 ;
V_21 = V_27 ;
switch ( V_2 -> V_26 & 0xfff0 ) {
case 0x4880 :
F_19 ( V_28 L_6
L_7 , V_2 -> V_17 ) ;
return - V_10 ;
case 0x6880 :
V_21 = ( V_2 -> V_26 & 0x0f ) >= 8 ? V_29 : V_30 ;
break;
default:
F_19 ( V_28 L_8
L_9 ,
V_2 -> V_17 , V_2 -> V_26 ) ;
return - V_10 ;
}
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_9 ( V_2 , 0xb1 , 0x10 ) ;
F_9 ( V_2 , 0xb2 , 0x00 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
F_16 ( & V_2 -> V_31 , V_18 ) ;
F_11 ( V_2 , 0x40 , 0x01 ) ;
F_18 ( & V_2 -> V_31 , V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_32 )
{
static int V_33 [ 16 ] = { - 1 , - 1 , 0 , - 1 , - 1 , 1 , - 1 , 2 , - 1 , 0 , 3 , - 1 , - 1 , - 1 , - 1 , - 1 } ;
unsigned long V_18 ;
int V_34 , V_35 , V_36 , V_37 , V_38 , V_39 ;
V_34 = 0x01 ;
if ( V_32 && V_2 -> V_40 >= 0x300 && V_2 -> V_41 > 0 && V_2 -> V_42 != V_30 ) {
V_38 = ( V_2 -> V_40 & 0x0f0 ) >> 4 ;
if ( V_38 <= 3 ) {
switch ( V_2 -> V_41 ) {
case 9 :
V_39 = 4 ;
break;
case 5 :
V_39 = 5 ;
break;
case 7 :
V_39 = 6 ;
break;
case 10 :
V_39 = 7 ;
break;
default:
V_39 = 0 ;
}
if ( V_39 ) {
V_34 |= ( V_38 << 3 ) | ( V_39 << 5 ) ;
}
}
}
#if 0
snd_printk(KERN_DEBUG "mpu cfg = 0x%x\n", cfg);
#endif
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_11 ( V_2 , 0x40 , V_34 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_10 ( V_2 , 0xb1 ) ;
F_10 ( V_2 , 0xb2 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
if ( V_32 ) {
V_34 = 0xf0 ;
V_35 = V_33 [ V_2 -> V_43 & 0x0f ] ;
if ( V_35 < 0 ) {
F_19 ( V_28 L_10
L_11 ,
V_2 -> V_17 , V_2 -> V_43 ) ;
#if 0
irq_bits = 0;
cfg = 0x10;
#endif
return - V_44 ;
}
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_9 ( V_2 , 0xb1 , V_34 | ( V_35 << 2 ) ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
V_34 = 0xf0 ;
V_36 = V_2 -> V_45 ;
if ( V_36 > 3 || V_36 == 2 ) {
F_19 ( V_28 L_12
L_11 , V_2 -> V_17 , V_36 ) ;
#if 0
dma_bits = 0;
cfg = 0x00;
#endif
return - V_44 ;
} else {
V_37 = V_36 ;
if ( V_36 != 3 )
V_37 ++ ;
}
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_9 ( V_2 , 0xb2 , V_34 | ( V_37 << 2 ) ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
} else {
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_9 ( V_2 , 0xb1 , 0x10 ) ;
F_9 ( V_2 , 0xb2 , 0x00 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
}
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_10 ( V_2 , 0xb1 ) ;
F_10 ( V_2 , 0xb2 ) ;
F_14 ( V_2 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_49 ;
unsigned int V_50 , V_51 ;
if ( V_49 -> V_52 == V_53 [ 0 ] . V_54 )
V_50 = 256 - V_49 -> V_55 ;
else
V_50 = 128 - V_49 -> V_55 ;
V_51 = 256 - 7160000 * 20 / ( 8 * 82 * V_49 -> V_56 ) ;
F_9 ( V_2 , 0xa1 , V_50 ) ;
F_9 ( V_2 , 0xa2 , V_51 ) ;
}
static int F_22 ( struct V_46 * V_47 ,
unsigned int V_57 , void * V_58 )
{
return F_23 ( V_47 , V_57 , V_58 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_57 , unsigned char V_59 )
{
int V_3 ;
if ( V_57 == V_60 ) {
V_59 = 0x00 ;
} else if ( V_57 != V_61 ) {
return - V_44 ;
}
F_25 ( & V_2 -> V_22 ) ;
V_2 -> V_62 = V_59 ;
V_3 = F_10 ( V_2 , 0xb8 ) ;
if ( ( V_3 < 0 ) || ( V_3 & 0x0f ) == V_59 ) {
F_26 ( & V_2 -> V_22 ) ;
return - V_44 ;
}
#if 0
printk(KERN_DEBUG "trigger: val = 0x%x, value = 0x%x\n", val, value);
printk(KERN_DEBUG "trigger: pointer = 0x%x\n",
snd_dma_pointer(chip->dma8, chip->dma_size));
#endif
F_9 ( V_2 , 0xb8 , ( V_3 & 0xf0 ) | V_59 ) ;
F_26 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 ,
struct V_63 * V_64 )
{
return F_28 ( V_47 , F_29 ( V_64 ) ) ;
}
static int F_30 ( struct V_46 * V_47 )
{
return F_31 ( V_47 ) ;
}
static int F_32 ( struct V_46 * V_47 )
{
unsigned long V_18 ;
struct V_1 * V_2 = F_33 ( V_47 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
unsigned int V_65 = F_34 ( V_47 ) ;
unsigned int V_66 = F_35 ( V_47 ) ;
V_2 -> V_67 = V_65 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_14 ( V_2 ) ;
F_21 ( V_2 , V_47 ) ;
F_9 ( V_2 , 0xb8 , 4 ) ;
F_9 ( V_2 , 0xa8 , ( F_10 ( V_2 , 0xa8 ) & ~ 0x03 ) | ( 3 - V_49 -> V_68 ) ) ;
F_9 ( V_2 , 0xb9 , 2 ) ;
if ( V_49 -> V_68 == 1 ) {
if ( F_36 ( V_49 -> V_69 ) == 8 ) {
F_9 ( V_2 , 0xb6 , 0x80 ) ;
F_9 ( V_2 , 0xb7 , 0x51 ) ;
F_9 ( V_2 , 0xb7 , 0xd0 ) ;
} else {
F_9 ( V_2 , 0xb6 , 0x00 ) ;
F_9 ( V_2 , 0xb7 , 0x71 ) ;
F_9 ( V_2 , 0xb7 , 0xf4 ) ;
}
} else {
if ( F_36 ( V_49 -> V_69 ) == 8 ) {
F_9 ( V_2 , 0xb6 , 0x80 ) ;
F_9 ( V_2 , 0xb7 , 0x51 ) ;
F_9 ( V_2 , 0xb7 , 0x98 ) ;
} else {
F_9 ( V_2 , 0xb6 , 0x00 ) ;
F_9 ( V_2 , 0xb7 , 0x71 ) ;
F_9 ( V_2 , 0xb7 , 0xbc ) ;
}
}
F_9 ( V_2 , 0xb1 , ( F_10 ( V_2 , 0xb1 ) & 0x0f ) | 0x50 ) ;
F_9 ( V_2 , 0xb2 , ( F_10 ( V_2 , 0xb2 ) & 0x0f ) | 0x50 ) ;
F_1 ( V_2 , V_70 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
V_66 = - V_66 ;
F_37 ( V_2 -> V_45 , V_49 -> V_71 , V_65 , V_72 | V_73 ) ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_9 ( V_2 , 0xa4 , ( unsigned char ) V_66 ) ;
F_9 ( V_2 , 0xa5 , ( unsigned char ) ( V_66 >> 8 ) ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
return 0 ;
}
static int F_38 ( struct V_46 * V_47 ,
int V_57 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
return F_24 ( V_2 , V_57 , 0x05 ) ;
}
static int F_39 ( struct V_46 * V_47 )
{
unsigned long V_18 ;
struct V_1 * V_2 = F_33 ( V_47 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
unsigned int V_65 = F_34 ( V_47 ) ;
unsigned int V_66 = F_35 ( V_47 ) ;
V_2 -> V_67 = V_65 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_14 ( V_2 ) ;
F_21 ( V_2 , V_47 ) ;
F_1 ( V_2 , V_74 ) ;
F_9 ( V_2 , 0xb8 , 0x0e ) ;
F_9 ( V_2 , 0xa8 , ( F_10 ( V_2 , 0xa8 ) & ~ 0x03 ) | ( 3 - V_49 -> V_68 ) ) ;
F_9 ( V_2 , 0xb9 , 2 ) ;
if ( V_49 -> V_68 == 1 ) {
if ( F_36 ( V_49 -> V_69 ) == 8 ) {
F_9 ( V_2 , 0xb7 , 0x51 ) ;
F_9 ( V_2 , 0xb7 , 0xd0 ) ;
} else {
F_9 ( V_2 , 0xb7 , 0x71 ) ;
F_9 ( V_2 , 0xb7 , 0xf4 ) ;
}
} else {
if ( F_36 ( V_49 -> V_69 ) == 8 ) {
F_9 ( V_2 , 0xb7 , 0x51 ) ;
F_9 ( V_2 , 0xb7 , 0x98 ) ;
} else {
F_9 ( V_2 , 0xb7 , 0x71 ) ;
F_9 ( V_2 , 0xb7 , 0xbc ) ;
}
}
F_9 ( V_2 , 0xb1 , ( F_10 ( V_2 , 0xb1 ) & 0x0f ) | 0x50 ) ;
F_9 ( V_2 , 0xb2 , ( F_10 ( V_2 , 0xb2 ) & 0x0f ) | 0x50 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
V_66 = - V_66 ;
F_37 ( V_2 -> V_45 , V_49 -> V_71 , V_65 , V_75 | V_73 ) ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
F_9 ( V_2 , 0xa4 , ( unsigned char ) V_66 ) ;
F_9 ( V_2 , 0xa5 , ( unsigned char ) ( V_66 >> 8 ) ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
return 0 ;
}
static int F_40 ( struct V_46 * V_47 ,
int V_57 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
return F_24 ( V_2 , V_57 , 0x0f ) ;
}
static T_1 F_41 ( int V_43 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
if ( V_2 -> V_62 == 0x05 )
F_42 ( V_2 -> V_77 ) ;
if ( V_2 -> V_62 == 0x0f )
F_42 ( V_2 -> V_78 ) ;
F_2 ( F_3 ( V_2 , V_8 ) ) ;
return V_79 ;
}
static T_2 F_43 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
T_3 V_80 ;
if ( V_2 -> V_62 != 0x05 )
return 0 ;
V_80 = F_44 ( V_2 -> V_45 , V_2 -> V_67 ) ;
return F_45 ( V_47 -> V_49 , V_80 ) ;
}
static T_2 F_46 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
T_3 V_80 ;
if ( V_2 -> V_62 != 0x0f )
return 0 ;
V_80 = F_44 ( V_2 -> V_45 , V_2 -> V_67 ) ;
return F_45 ( V_47 -> V_49 , V_80 ) ;
}
static int F_47 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
if ( V_2 -> V_78 != NULL )
return - V_81 ;
V_2 -> V_77 = V_47 ;
V_49 -> V_21 = V_82 ;
F_48 ( V_49 , 0 , V_83 ,
& V_84 ) ;
return 0 ;
}
static int F_49 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
if ( V_2 -> V_77 != NULL )
return - V_81 ;
V_2 -> V_78 = V_47 ;
V_49 -> V_21 = V_85 ;
F_48 ( V_49 , 0 , V_83 ,
& V_84 ) ;
return 0 ;
}
static int F_50 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
V_2 -> V_77 = NULL ;
return 0 ;
}
static int F_51 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
V_2 -> V_78 = NULL ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 != V_86 )
F_20 ( V_2 , 0 ) ;
F_53 ( V_2 -> V_87 ) ;
if ( V_2 -> V_43 >= 0 )
F_54 ( V_2 -> V_43 , ( void * ) V_2 ) ;
if ( V_2 -> V_45 >= 0 ) {
F_55 ( V_2 -> V_45 ) ;
F_56 ( V_2 -> V_45 ) ;
}
return 0 ;
}
static int F_57 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_90 ;
return F_52 ( V_2 ) ;
}
static const char * F_58 ( struct V_1 * V_2 )
{
static char V_38 [ 16 ] ;
sprintf ( V_38 , L_13 , V_2 -> V_42 == V_30 ? L_14 : L_15 , V_2 -> V_26 & 0x0f ) ;
return V_38 ;
}
int F_59 ( struct V_91 * V_92 ,
struct V_1 * V_2 ,
unsigned long V_17 ,
unsigned long V_40 ,
int V_43 ,
int V_41 ,
int V_45 ,
unsigned short V_42 )
{
static struct V_93 V_94 = {
. V_95 = F_57 ,
} ;
int V_96 ;
if ( V_2 == NULL )
return - V_97 ;
V_2 -> V_43 = - 1 ;
V_2 -> V_45 = - 1 ;
V_2 -> V_42 = V_86 ;
V_2 -> V_87 = F_60 ( V_17 + 4 , 12 , L_16 ) ;
if ( V_2 -> V_87 == NULL ) {
F_19 ( V_28 L_17 , V_17 + 4 ) ;
V_96 = - V_98 ;
goto exit;
}
V_96 = F_61 ( V_43 , F_41 , 0 , L_16 , ( void * ) V_2 ) ;
if ( V_96 < 0 ) {
F_19 ( V_28 L_18 , V_43 ) ;
goto exit;
}
V_2 -> V_43 = V_43 ;
V_96 = F_62 ( V_45 , L_16 ) ;
if ( V_96 < 0 ) {
F_19 ( V_28 L_19 , V_45 ) ;
goto exit;
}
V_2 -> V_45 = V_45 ;
F_63 ( & V_2 -> V_22 ) ;
F_63 ( & V_2 -> V_31 ) ;
V_2 -> V_17 = V_17 ;
V_40 &= ~ 0x000f ;
if ( V_40 < 0x300 || V_40 > 0x330 )
V_40 = 0 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_42 = V_42 ;
V_96 = F_15 ( V_2 ) ;
if ( V_96 < 0 )
goto exit;
V_96 = F_20 ( V_2 , 1 ) ;
if ( V_96 < 0 )
goto exit;
V_96 = F_64 ( V_92 , V_99 , V_2 , & V_94 ) ;
exit:
if ( V_96 )
F_52 ( V_2 ) ;
return V_96 ;
}
int F_65 ( struct V_91 * V_92 , struct V_1 * V_2 ,
int V_89 , struct V_100 * * V_101 )
{
struct V_100 * V_102 ;
int V_96 ;
V_96 = F_66 ( V_92 , L_20 , V_89 , 1 , 1 , & V_102 ) ;
if ( V_96 < 0 )
return V_96 ;
F_67 ( V_102 , V_103 , & V_104 ) ;
F_67 ( V_102 , V_105 , & V_106 ) ;
V_102 -> V_107 = V_2 ;
V_102 -> V_108 = V_109 ;
sprintf ( V_102 -> V_110 , F_58 ( V_2 ) ) ;
V_2 -> V_102 = V_102 ;
F_68 ( V_102 , V_111 ,
F_69 () ,
64 * 1024 , 64 * 1024 ) ;
if ( V_101 )
* V_101 = V_102 ;
return 0 ;
}
static int F_70 ( struct V_112 * V_113 , struct V_114 * V_115 )
{
static const char * const V_116 [ 8 ] = {
L_21 , L_22 , L_23 , L_24 ,
L_25 , L_26 , L_27 , L_28
} ;
return F_71 ( V_115 , 1 , 8 , V_116 ) ;
}
static int F_72 ( struct V_112 * V_113 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_73 ( V_113 ) ;
V_118 -> V_59 . V_119 . V_120 [ 0 ] = F_13 ( V_2 , V_121 ) & 7 ;
return 0 ;
}
static int F_74 ( struct V_112 * V_113 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_73 ( V_113 ) ;
unsigned long V_18 ;
unsigned char V_122 , V_123 ;
int V_124 ;
if ( V_118 -> V_59 . V_119 . V_120 [ 0 ] > 8 )
return - V_44 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
V_122 = F_13 ( V_2 , V_121 ) ;
V_123 = ( V_118 -> V_59 . V_119 . V_120 [ 0 ] & 7 ) | ( V_122 & ~ 15 ) ;
V_124 = V_123 != V_122 ;
if ( V_124 )
F_11 ( V_2 , V_121 , V_123 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
return V_124 ;
}
static int F_75 ( struct V_112 * V_113 , struct V_114 * V_115 )
{
int V_125 = ( V_113 -> V_126 >> 16 ) & 0xff ;
V_115 -> type = V_125 == 1 ? V_127 : V_128 ;
V_115 -> V_66 = 1 ;
V_115 -> V_59 . integer . V_129 = 0 ;
V_115 -> V_59 . integer . V_130 = V_125 ;
return 0 ;
}
static int F_76 ( struct V_112 * V_113 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_73 ( V_113 ) ;
unsigned long V_18 ;
int V_11 = V_113 -> V_126 & 0xff ;
int V_131 = ( V_113 -> V_126 >> 8 ) & 0xff ;
int V_125 = ( V_113 -> V_126 >> 16 ) & 0xff ;
int V_132 = ( V_113 -> V_126 >> 24 ) & 0xff ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
V_118 -> V_59 . integer . V_59 [ 0 ] = ( F_13 ( V_2 , V_11 ) >> V_131 ) & V_125 ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
if ( V_132 )
V_118 -> V_59 . integer . V_59 [ 0 ] = V_125 - V_118 -> V_59 . integer . V_59 [ 0 ] ;
return 0 ;
}
static int F_77 ( struct V_112 * V_113 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_73 ( V_113 ) ;
unsigned long V_18 ;
int V_11 = V_113 -> V_126 & 0xff ;
int V_131 = ( V_113 -> V_126 >> 8 ) & 0xff ;
int V_125 = ( V_113 -> V_126 >> 16 ) & 0xff ;
int V_132 = ( V_113 -> V_126 >> 24 ) & 0xff ;
int V_124 ;
unsigned char V_122 , V_123 ;
V_123 = ( V_118 -> V_59 . integer . V_59 [ 0 ] & V_125 ) ;
if ( V_132 )
V_123 = V_125 - V_123 ;
V_123 <<= V_131 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
V_122 = F_13 ( V_2 , V_11 ) ;
V_123 = ( V_122 & ~ ( V_125 << V_131 ) ) | V_123 ;
V_124 = V_123 != V_122 ;
if ( V_124 )
F_11 ( V_2 , V_11 , V_123 ) ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
return V_124 ;
}
static int F_78 ( struct V_112 * V_113 , struct V_114 * V_115 )
{
int V_125 = ( V_113 -> V_126 >> 24 ) & 0xff ;
V_115 -> type = V_125 == 1 ? V_127 : V_128 ;
V_115 -> V_66 = 2 ;
V_115 -> V_59 . integer . V_129 = 0 ;
V_115 -> V_59 . integer . V_130 = V_125 ;
return 0 ;
}
static int F_79 ( struct V_112 * V_113 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_73 ( V_113 ) ;
unsigned long V_18 ;
int V_133 = V_113 -> V_126 & 0xff ;
int V_134 = ( V_113 -> V_126 >> 8 ) & 0xff ;
int V_135 = ( V_113 -> V_126 >> 16 ) & 0x07 ;
int V_136 = ( V_113 -> V_126 >> 19 ) & 0x07 ;
int V_125 = ( V_113 -> V_126 >> 24 ) & 0xff ;
int V_132 = ( V_113 -> V_126 >> 22 ) & 1 ;
unsigned char V_137 , V_138 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
if ( V_133 < 0xa0 )
V_137 = F_13 ( V_2 , V_133 ) ;
else
V_137 = F_10 ( V_2 , V_133 ) ;
if ( V_133 != V_134 ) {
if ( V_134 < 0xa0 )
V_138 = F_13 ( V_2 , V_134 ) ;
else
V_138 = F_10 ( V_2 , V_134 ) ;
} else
V_138 = V_137 ;
F_18 ( & V_2 -> V_22 , V_18 ) ;
V_118 -> V_59 . integer . V_59 [ 0 ] = ( V_137 >> V_135 ) & V_125 ;
V_118 -> V_59 . integer . V_59 [ 1 ] = ( V_138 >> V_136 ) & V_125 ;
if ( V_132 ) {
V_118 -> V_59 . integer . V_59 [ 0 ] = V_125 - V_118 -> V_59 . integer . V_59 [ 0 ] ;
V_118 -> V_59 . integer . V_59 [ 1 ] = V_125 - V_118 -> V_59 . integer . V_59 [ 1 ] ;
}
return 0 ;
}
static int F_80 ( struct V_112 * V_113 , struct V_117 * V_118 )
{
struct V_1 * V_2 = F_73 ( V_113 ) ;
unsigned long V_18 ;
int V_133 = V_113 -> V_126 & 0xff ;
int V_134 = ( V_113 -> V_126 >> 8 ) & 0xff ;
int V_135 = ( V_113 -> V_126 >> 16 ) & 0x07 ;
int V_136 = ( V_113 -> V_126 >> 19 ) & 0x07 ;
int V_125 = ( V_113 -> V_126 >> 24 ) & 0xff ;
int V_132 = ( V_113 -> V_126 >> 22 ) & 1 ;
int V_124 ;
unsigned char V_139 , V_140 , V_141 , V_142 ;
V_139 = V_118 -> V_59 . integer . V_59 [ 0 ] & V_125 ;
V_140 = V_118 -> V_59 . integer . V_59 [ 1 ] & V_125 ;
if ( V_132 ) {
V_139 = V_125 - V_139 ;
V_140 = V_125 - V_140 ;
}
V_139 <<= V_135 ;
V_140 <<= V_136 ;
F_16 ( & V_2 -> V_22 , V_18 ) ;
if ( V_133 != V_134 ) {
if ( V_133 < 0xa0 )
V_141 = F_13 ( V_2 , V_133 ) ;
else
V_141 = F_10 ( V_2 , V_133 ) ;
if ( V_134 < 0xa0 )
V_142 = F_13 ( V_2 , V_134 ) ;
else
V_142 = F_10 ( V_2 , V_134 ) ;
V_139 = ( V_141 & ~ ( V_125 << V_135 ) ) | V_139 ;
V_140 = ( V_142 & ~ ( V_125 << V_136 ) ) | V_140 ;
V_124 = V_139 != V_141 || V_140 != V_142 ;
if ( V_124 ) {
if ( V_133 < 0xa0 )
F_11 ( V_2 , V_133 , V_139 ) ;
else
F_9 ( V_2 , V_133 , V_139 ) ;
if ( V_134 < 0xa0 )
F_11 ( V_2 , V_134 , V_139 ) ;
else
F_9 ( V_2 , V_134 , V_139 ) ;
}
} else {
if ( V_133 < 0xa0 )
V_141 = F_13 ( V_2 , V_133 ) ;
else
V_141 = F_10 ( V_2 , V_133 ) ;
V_139 = ( V_141 & ~ ( ( V_125 << V_135 ) | ( V_125 << V_136 ) ) ) | V_139 | V_140 ;
V_124 = V_139 != V_141 ;
if ( V_124 ) {
if ( V_133 < 0xa0 )
F_11 ( V_2 , V_133 , V_139 ) ;
else
F_9 ( V_2 , V_133 , V_139 ) ;
}
}
F_18 ( & V_2 -> V_22 , V_18 ) ;
return V_124 ;
}
int F_81 ( struct V_91 * V_92 , struct V_1 * V_2 )
{
unsigned int V_143 ;
int V_96 ;
unsigned char V_11 , V_3 ;
if ( F_82 ( ! V_2 || ! V_92 ) )
return - V_44 ;
strcpy ( V_92 -> V_144 , F_58 ( V_2 ) ) ;
for ( V_143 = 0 ; V_143 < F_83 ( V_145 ) ; V_143 ++ ) {
if ( ( V_96 = F_84 ( V_92 , F_85 ( & V_145 [ V_143 ] , V_2 ) ) ) < 0 )
return V_96 ;
}
for ( V_143 = 0 ; V_143 < V_146 ; V_143 ++ ) {
V_11 = V_147 [ V_143 ] [ 0 ] ;
V_3 = V_147 [ V_143 ] [ 1 ] ;
if ( V_11 < 0xa0 )
F_11 ( V_2 , V_11 , V_3 ) ;
else
F_9 ( V_2 , V_11 , V_3 ) ;
}
return 0 ;
}
static int T_4 F_86 ( void )
{
return 0 ;
}
static void T_5 F_87 ( void )
{
}
