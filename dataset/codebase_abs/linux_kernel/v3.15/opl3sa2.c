static unsigned char F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 ;
#if 0
outb(0x1d, port);
printk(KERN_DEBUG "read [0x%lx] = 0x%x\n", port, inb(port));
#endif
F_2 ( V_3 , V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_5 + 1 ) ;
#if 0
printk(KERN_DEBUG "read [0x%lx] = 0x%x [0x%x]\n",
port, result, inb(port));
#endif
return V_4 ;
}
static unsigned char F_4 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned long V_6 ;
unsigned char V_4 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_8 )
{
#if 0
outb(0x1d, port);
#endif
F_2 ( V_3 , V_2 -> V_5 ) ;
F_2 ( V_8 , V_2 -> V_5 + 1 ) ;
V_2 -> V_9 [ V_3 ] = V_8 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_8 )
{
unsigned long V_6 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
F_7 ( V_2 , V_3 , V_8 ) ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
unsigned long V_5 ;
unsigned char V_13 , V_14 ;
char V_15 [ 2 ] ;
V_5 = V_2 -> V_5 ;
if ( ( V_2 -> V_16 = F_10 ( V_5 , 2 , L_1 ) ) == NULL ) {
F_11 (KERN_ERR PFX L_2 , port) ;
return - V_17 ;
}
V_2 -> V_18 = 0 ;
V_13 = F_4 ( V_2 , V_19 ) ;
if ( V_13 == 0xff ) {
F_12 ( L_3 , V_5 , V_13 ) ;
return - V_20 ;
}
switch ( V_13 & 0x07 ) {
case 0x01 :
V_2 -> V_18 = 2 ;
break;
default:
V_2 -> V_18 = 3 ;
break;
}
V_15 [ 0 ] = V_2 -> V_18 + '0' ;
V_15 [ 1 ] = 0 ;
strcat ( V_11 -> V_21 , V_15 ) ;
F_8 ( V_2 , V_19 , V_13 ^ 7 ) ;
if ( ( V_14 = F_4 ( V_2 , V_19 ) ) != V_13 ) {
F_12 ( L_4 , V_5 , V_13 , V_14 ) ;
return - V_20 ;
}
V_13 = F_4 ( V_2 , V_22 ) ;
F_8 ( V_2 , V_22 , 0x8a ) ;
if ( ( ( V_14 = F_4 ( V_2 , V_22 ) ) & 0x9f ) != 0x8a ) {
F_12 ( L_5 , V_5 , V_13 , V_14 ) ;
return - V_20 ;
}
F_8 ( V_2 , V_22 , 0x9f ) ;
F_8 ( V_2 , V_23 , V_24 ) ;
if ( V_2 -> V_18 > 2 ) {
F_8 ( V_2 , V_25 , ( V_2 -> V_26 << 4 ) ) ;
} else {
F_8 ( V_2 , V_25 , 0x00 ) ;
}
F_8 ( V_2 , V_27 , 0x0d ) ;
if ( V_2 -> V_28 ) {
F_8 ( V_2 , V_29 , 0x03 ) ;
} else {
F_8 ( V_2 , V_29 , 0x21 ) ;
}
F_8 ( V_2 , V_19 , 0x80 | ( V_13 & 7 ) ) ;
if ( V_2 -> V_18 > 2 ) {
F_8 ( V_2 , V_30 , 0x00 ) ;
F_8 ( V_2 , V_31 , 0x00 ) ;
}
return 0 ;
}
static T_1 F_13 ( int V_32 , void * V_33 )
{
unsigned short V_34 ;
struct V_10 * V_11 = V_33 ;
struct V_1 * V_2 ;
int V_35 = 0 ;
if ( V_11 == NULL )
return V_36 ;
V_2 = V_11 -> V_12 ;
V_34 = F_4 ( V_2 , V_37 ) ;
if ( V_34 & 0x20 ) {
V_35 = 1 ;
F_14 ( V_2 -> V_38 ) ;
}
if ( ( V_34 & 0x10 ) && V_2 -> V_39 != NULL ) {
V_35 = 1 ;
F_15 ( V_32 , V_2 -> V_39 -> V_12 ) ;
}
if ( V_34 & 0x07 ) {
V_35 = 1 ;
F_16 ( V_32 , V_2 -> V_40 ) ;
}
if ( V_34 & 0x40 ) {
V_35 = 1 ;
F_4 ( V_2 , V_41 ) ;
F_4 ( V_2 , V_42 ) ;
if ( V_2 -> V_43 && V_2 -> V_44 ) {
F_17 ( V_11 , V_45 ,
& V_2 -> V_43 -> V_46 ) ;
F_17 ( V_11 , V_45 ,
& V_2 -> V_44 -> V_46 ) ;
}
}
return F_18 ( V_35 ) ;
}
static int F_19 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
unsigned long V_6 ;
int V_3 = V_48 -> V_51 & 0xff ;
int V_52 = ( V_48 -> V_51 >> 8 ) & 0xff ;
int V_53 = ( V_48 -> V_51 >> 16 ) & 0xff ;
int V_54 = ( V_48 -> V_51 >> 24 ) & 0xff ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
V_50 -> V_8 . integer . V_8 [ 0 ] = ( V_2 -> V_9 [ V_3 ] >> V_52 ) & V_53 ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
if ( V_54 )
V_50 -> V_8 . integer . V_8 [ 0 ] = V_53 - V_50 -> V_8 . integer . V_8 [ 0 ] ;
return 0 ;
}
static int F_21 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
unsigned long V_6 ;
int V_3 = V_48 -> V_51 & 0xff ;
int V_52 = ( V_48 -> V_51 >> 8 ) & 0xff ;
int V_53 = ( V_48 -> V_51 >> 16 ) & 0xff ;
int V_54 = ( V_48 -> V_51 >> 24 ) & 0xff ;
int V_55 ;
unsigned short V_56 , V_57 ;
V_56 = ( V_50 -> V_8 . integer . V_8 [ 0 ] & V_53 ) ;
if ( V_54 )
V_56 = V_53 - V_56 ;
V_56 <<= V_52 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
V_57 = V_2 -> V_9 [ V_3 ] ;
V_56 = ( V_57 & ~ ( V_53 << V_52 ) ) | V_56 ;
V_55 = V_56 != V_57 ;
F_7 ( V_2 , V_3 , V_56 ) ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
return V_55 ;
}
static int F_22 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
unsigned long V_6 ;
int V_58 = V_48 -> V_51 & 0xff ;
int V_59 = ( V_48 -> V_51 >> 8 ) & 0xff ;
int V_60 = ( V_48 -> V_51 >> 16 ) & 0x07 ;
int V_61 = ( V_48 -> V_51 >> 19 ) & 0x07 ;
int V_53 = ( V_48 -> V_51 >> 24 ) & 0xff ;
int V_54 = ( V_48 -> V_51 >> 22 ) & 1 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
V_50 -> V_8 . integer . V_8 [ 0 ] = ( V_2 -> V_9 [ V_58 ] >> V_60 ) & V_53 ;
V_50 -> V_8 . integer . V_8 [ 1 ] = ( V_2 -> V_9 [ V_59 ] >> V_61 ) & V_53 ;
F_6 ( & V_2 -> V_7 , V_6 ) ;
if ( V_54 ) {
V_50 -> V_8 . integer . V_8 [ 0 ] = V_53 - V_50 -> V_8 . integer . V_8 [ 0 ] ;
V_50 -> V_8 . integer . V_8 [ 1 ] = V_53 - V_50 -> V_8 . integer . V_8 [ 1 ] ;
}
return 0 ;
}
static int F_23 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
unsigned long V_6 ;
int V_58 = V_48 -> V_51 & 0xff ;
int V_59 = ( V_48 -> V_51 >> 8 ) & 0xff ;
int V_60 = ( V_48 -> V_51 >> 16 ) & 0x07 ;
int V_61 = ( V_48 -> V_51 >> 19 ) & 0x07 ;
int V_53 = ( V_48 -> V_51 >> 24 ) & 0xff ;
int V_54 = ( V_48 -> V_51 >> 22 ) & 1 ;
int V_55 ;
unsigned short V_62 , V_63 , V_64 , V_65 ;
V_62 = V_50 -> V_8 . integer . V_8 [ 0 ] & V_53 ;
V_63 = V_50 -> V_8 . integer . V_8 [ 1 ] & V_53 ;
if ( V_54 ) {
V_62 = V_53 - V_62 ;
V_63 = V_53 - V_63 ;
}
V_62 <<= V_60 ;
V_63 <<= V_61 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
if ( V_58 != V_59 ) {
V_64 = V_2 -> V_9 [ V_58 ] ;
V_65 = V_2 -> V_9 [ V_59 ] ;
V_62 = ( V_64 & ~ ( V_53 << V_60 ) ) | V_62 ;
V_63 = ( V_65 & ~ ( V_53 << V_61 ) ) | V_63 ;
V_55 = V_62 != V_64 || V_63 != V_65 ;
F_7 ( V_2 , V_58 , V_62 ) ;
F_7 ( V_2 , V_59 , V_63 ) ;
} else {
V_64 = V_2 -> V_9 [ V_58 ] ;
V_62 = ( V_64 & ~ ( ( V_53 << V_60 ) | ( V_53 << V_61 ) ) ) | V_62 | V_63 ;
V_55 = V_62 != V_64 ;
F_7 ( V_2 , V_58 , V_62 ) ;
}
F_6 ( & V_2 -> V_7 , V_6 ) ;
return V_55 ;
}
static void F_24 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_20 ( V_48 ) ;
V_2 -> V_43 = NULL ;
V_2 -> V_44 = NULL ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
struct V_66 V_67 , V_68 ;
struct V_47 * V_69 ;
unsigned int V_70 ;
int V_71 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_67 . V_72 = V_68 . V_72 = V_73 ;
strcpy ( V_67 . V_74 , L_6 ) ;
strcpy ( V_68 . V_74 , L_7 ) ;
if ( ( V_71 = F_26 ( V_11 , & V_67 , & V_68 ) ) < 0 ) {
F_11 ( V_75 L_8 ) ;
return V_71 ;
}
strcpy ( V_67 . V_74 , L_9 ) ;
strcpy ( V_68 . V_74 , L_10 ) ;
if ( ( V_71 = F_26 ( V_11 , & V_67 , & V_68 ) ) < 0 ) {
F_11 ( V_75 L_8 ) ;
return V_71 ;
}
strcpy ( V_67 . V_74 , L_6 ) ; V_67 . V_76 = 1 ;
strcpy ( V_68 . V_74 , L_11 ) ;
if ( ( V_71 = F_26 ( V_11 , & V_67 , & V_68 ) ) < 0 ) {
F_11 ( V_75 L_8 ) ;
return V_71 ;
}
strcpy ( V_67 . V_74 , L_9 ) ;
strcpy ( V_68 . V_74 , L_12 ) ;
if ( ( V_71 = F_26 ( V_11 , & V_67 , & V_68 ) ) < 0 ) {
F_11 ( V_75 L_8 ) ;
return V_71 ;
}
for ( V_70 = 0 ; V_70 < F_27 ( V_77 ) ; V_70 ++ ) {
if ( ( V_71 = F_28 ( V_11 , V_69 = F_29 ( & V_77 [ V_70 ] , V_2 ) ) ) < 0 )
return V_71 ;
switch ( V_70 ) {
case 0 : V_2 -> V_43 = V_69 ; V_69 -> V_78 = F_24 ; break;
case 1 : V_2 -> V_44 = V_69 ; V_69 -> V_78 = F_24 ; break;
}
}
if ( V_2 -> V_18 > 2 ) {
for ( V_70 = 0 ; V_70 < F_27 ( V_79 ) ; V_70 ++ )
if ( ( V_71 = F_28 ( V_11 , F_29 ( & V_79 [ V_70 ] , V_2 ) ) ) < 0 )
return V_71 ;
}
return 0 ;
}
static int F_30 ( struct V_10 * V_11 , T_2 V_80 )
{
if ( V_11 ) {
struct V_1 * V_2 = V_11 -> V_12 ;
F_31 ( V_11 , V_81 ) ;
V_2 -> V_40 -> V_82 ( V_2 -> V_40 ) ;
F_8 ( V_2 , V_23 , V_83 ) ;
}
return 0 ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
int V_84 ;
if ( ! V_11 )
return 0 ;
V_2 = V_11 -> V_12 ;
F_8 ( V_2 , V_23 , V_24 ) ;
for ( V_84 = 2 ; V_84 <= 0x0a ; V_84 ++ ) {
if ( V_84 != V_37 )
F_8 ( V_2 , V_84 , V_2 -> V_9 [ V_84 ] ) ;
}
if ( V_2 -> V_18 > 2 ) {
for ( V_84 = 0x12 ; V_84 <= 0x16 ; V_84 ++ )
F_8 ( V_2 , V_84 , V_2 -> V_9 [ V_84 ] ) ;
}
V_2 -> V_40 -> V_85 ( V_2 -> V_40 ) ;
F_31 ( V_11 , V_86 ) ;
return 0 ;
}
static int F_33 ( int V_87 , struct V_1 * V_2 ,
struct V_88 * V_89 )
{
if ( F_34 ( V_89 ) < 0 ) {
F_11 ( V_75 L_13 ) ;
return - V_17 ;
}
V_90 [ V_87 ] = F_35 ( V_89 , 0 ) ;
V_91 [ V_87 ] = F_35 ( V_89 , 1 ) ;
V_92 [ V_87 ] = F_35 ( V_89 , 2 ) ;
V_93 [ V_87 ] = F_35 ( V_89 , 3 ) ;
V_5 [ V_87 ] = F_35 ( V_89 , 4 ) ;
V_94 [ V_87 ] = F_36 ( V_89 , 0 ) ;
V_95 [ V_87 ] = F_36 ( V_89 , 1 ) ;
V_32 [ V_87 ] = F_37 ( V_89 , 0 ) ;
F_38 ( L_14 ,
F_39 ( V_89 ) ? L_15 : L_16 , V_90 [ V_87 ] , V_91 [ V_87 ] , V_92 [ V_87 ] , V_93 [ V_87 ] ) ;
F_38 ( L_17 ,
F_39 ( V_89 ) ? L_15 : L_16 , V_5 [ V_87 ] , V_94 [ V_87 ] , V_95 [ V_87 ] , V_32 [ V_87 ] ) ;
return 0 ;
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_12 ;
if ( V_2 -> V_32 >= 0 )
F_41 ( V_2 -> V_32 , V_11 ) ;
F_42 ( V_2 -> V_16 ) ;
}
static int F_43 ( struct V_96 * V_89 , int V_87 ,
struct V_10 * * V_97 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_71 ;
V_71 = F_44 ( V_89 , V_76 [ V_87 ] , V_46 [ V_87 ] , V_98 ,
sizeof( struct V_1 ) , & V_11 ) ;
if ( V_71 < 0 )
return V_71 ;
strcpy ( V_11 -> V_99 , L_18 ) ;
strcpy ( V_11 -> V_21 , L_19 ) ;
V_2 = V_11 -> V_12 ;
F_45 ( & V_2 -> V_7 ) ;
V_2 -> V_32 = - 1 ;
V_11 -> V_78 = F_40 ;
* V_97 = V_11 ;
return 0 ;
}
static int F_46 ( struct V_10 * V_11 , int V_87 )
{
int V_100 , V_101 , V_102 ;
struct V_1 * V_2 ;
struct V_103 * V_40 ;
struct V_104 * V_105 ;
int V_71 ;
V_2 = V_11 -> V_12 ;
V_2 -> V_26 = V_106 [ V_87 ] & 0x03 ;
V_2 -> V_5 = V_5 [ V_87 ] ;
V_100 = V_32 [ V_87 ] ;
V_101 = V_94 [ V_87 ] ;
V_102 = V_95 [ V_87 ] ;
if ( V_102 < 0 )
V_2 -> V_28 = 1 ;
V_71 = F_9 ( V_11 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_47 ( V_100 , F_13 , 0 ,
L_20 , V_11 ) ;
if ( V_71 ) {
F_11 (KERN_ERR PFX L_21 , xirq) ;
return - V_20 ;
}
V_2 -> V_32 = V_100 ;
V_71 = F_48 ( V_11 ,
V_91 [ V_87 ] + 4 , - 1 ,
V_100 , V_101 , V_102 ,
V_107 , V_108 , & V_40 ) ;
if ( V_71 < 0 ) {
F_12 ( L_22 , V_91 [ V_87 ] + 4 ) ;
return V_71 ;
}
V_2 -> V_40 = V_40 ;
V_71 = F_49 ( V_40 , 0 , NULL ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_50 ( V_40 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_25 ( V_11 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_51 ( V_40 , 0 , NULL ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_92 [ V_87 ] >= 0x340 && V_92 [ V_87 ] < 0x400 ) {
if ( ( V_71 = F_52 ( V_11 , V_92 [ V_87 ] ,
V_92 [ V_87 ] + 2 ,
V_109 , 0 , & V_105 ) ) < 0 )
return V_71 ;
if ( ( V_71 = F_53 ( V_105 , 1 , 2 ) ) < 0 )
return V_71 ;
if ( ( V_71 = F_54 ( V_105 , 0 , 1 , & V_2 -> V_38 ) ) < 0 )
return V_71 ;
}
if ( V_93 [ V_87 ] >= 0x300 && V_93 [ V_87 ] < 0x340 ) {
if ( ( V_71 = F_55 ( V_11 , 0 , V_110 ,
V_93 [ V_87 ] ,
V_111 , - 1 ,
& V_2 -> V_39 ) ) < 0 )
return V_71 ;
}
sprintf ( V_11 -> V_112 , L_23 ,
V_11 -> V_21 , V_2 -> V_5 , V_100 , V_101 ) ;
if ( V_102 >= 0 )
sprintf ( V_11 -> V_112 + strlen ( V_11 -> V_112 ) , L_24 , V_102 ) ;
return F_56 ( V_11 ) ;
}
static int F_57 ( struct V_88 * V_89 ,
const struct V_113 * V_46 )
{
static int V_87 ;
int V_71 ;
struct V_10 * V_11 ;
if ( F_58 ( V_89 ) )
return - V_114 ;
for (; V_87 < V_115 ; V_87 ++ ) {
if ( V_116 [ V_87 ] && V_117 [ V_87 ] )
break;
}
if ( V_87 >= V_115 )
return - V_20 ;
V_71 = F_43 ( & V_89 -> V_87 , V_87 , & V_11 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( ( V_71 = F_33 ( V_87 , V_11 -> V_12 , V_89 ) ) < 0 ) {
F_59 ( V_11 ) ;
return V_71 ;
}
if ( ( V_71 = F_46 ( V_11 , V_87 ) ) < 0 ) {
F_59 ( V_11 ) ;
return V_71 ;
}
F_60 ( V_89 , V_11 ) ;
V_87 ++ ;
return 0 ;
}
static void F_61 ( struct V_88 * V_89 )
{
F_59 ( F_62 ( V_89 ) ) ;
}
static int F_63 ( struct V_88 * V_89 , T_2 V_80 )
{
return F_30 ( F_62 ( V_89 ) , V_80 ) ;
}
static int F_64 ( struct V_88 * V_89 )
{
return F_32 ( F_62 ( V_89 ) ) ;
}
static int F_65 ( struct V_118 * V_119 ,
const struct V_120 * V_46 )
{
static int V_87 ;
struct V_88 * V_89 ;
int V_71 ;
struct V_10 * V_11 ;
V_89 = F_66 ( V_119 , V_46 -> V_121 [ 0 ] . V_46 , NULL ) ;
if ( V_89 == NULL ) {
F_11 (KERN_ERR PFX L_25 ,
id->devs[0].id) ;
return - V_17 ;
}
for (; V_87 < V_115 ; V_87 ++ ) {
if ( V_116 [ V_87 ] && V_117 [ V_87 ] )
break;
}
if ( V_87 >= V_115 )
return - V_20 ;
V_71 = F_43 ( & V_89 -> V_87 , V_87 , & V_11 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( ( V_71 = F_33 ( V_87 , V_11 -> V_12 , V_89 ) ) < 0 ) {
F_59 ( V_11 ) ;
return V_71 ;
}
if ( ( V_71 = F_46 ( V_11 , V_87 ) ) < 0 ) {
F_59 ( V_11 ) ;
return V_71 ;
}
F_67 ( V_119 , V_11 ) ;
V_87 ++ ;
return 0 ;
}
static void F_68 ( struct V_118 * V_119 )
{
F_59 ( F_69 ( V_119 ) ) ;
F_67 ( V_119 , NULL ) ;
}
static int F_70 ( struct V_118 * V_119 , T_2 V_80 )
{
return F_30 ( F_69 ( V_119 ) , V_80 ) ;
}
static int F_71 ( struct V_118 * V_119 )
{
return F_32 ( F_69 ( V_119 ) ) ;
}
static int F_72 ( struct V_96 * V_89 ,
unsigned int V_87 )
{
if ( ! V_116 [ V_87 ] )
return 0 ;
#ifdef F_73
if ( V_117 [ V_87 ] )
return 0 ;
#endif
if ( V_5 [ V_87 ] == V_122 ) {
F_11 (KERN_ERR PFX L_26 ) ;
return 0 ;
}
if ( V_91 [ V_87 ] == V_122 ) {
F_11 (KERN_ERR PFX L_27 ) ;
return 0 ;
}
if ( V_92 [ V_87 ] == V_122 ) {
F_11 (KERN_ERR PFX L_28 ) ;
return 0 ;
}
if ( V_93 [ V_87 ] == V_122 ) {
F_11 (KERN_ERR PFX L_29 ) ;
return 0 ;
}
return 1 ;
}
static int F_74 ( struct V_96 * V_89 ,
unsigned int V_87 )
{
struct V_10 * V_11 ;
int V_71 ;
V_71 = F_43 ( V_89 , V_87 , & V_11 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( ( V_71 = F_46 ( V_11 , V_87 ) ) < 0 ) {
F_59 ( V_11 ) ;
return V_71 ;
}
F_75 ( V_89 , V_11 ) ;
return 0 ;
}
static int F_76 ( struct V_96 * V_123 ,
unsigned int V_87 )
{
F_59 ( F_77 ( V_123 ) ) ;
return 0 ;
}
static int F_78 ( struct V_96 * V_87 , unsigned int V_124 ,
T_2 V_80 )
{
return F_30 ( F_77 ( V_87 ) , V_80 ) ;
}
static int F_79 ( struct V_96 * V_87 , unsigned int V_124 )
{
return F_32 ( F_77 ( V_87 ) ) ;
}
static int T_3 F_80 ( void )
{
int V_71 ;
V_71 = F_81 ( & V_125 , V_115 ) ;
#ifdef F_73
if ( ! V_71 )
V_126 = 1 ;
V_71 = F_82 ( & V_127 ) ;
if ( ! V_71 )
V_128 = 1 ;
V_71 = F_83 ( & V_129 ) ;
if ( ! V_71 )
V_130 = 1 ;
if ( V_126 || V_128 )
V_71 = 0 ;
#endif
return V_71 ;
}
static void T_4 F_84 ( void )
{
#ifdef F_73
if ( V_130 )
F_85 ( & V_129 ) ;
if ( V_128 )
F_86 ( & V_127 ) ;
if ( V_126 )
#endif
F_87 ( & V_125 ) ;
}
