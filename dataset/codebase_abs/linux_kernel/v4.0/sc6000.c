static unsigned char F_1 ( int V_1 )
{
unsigned char V_2 = 0 ;
switch ( V_1 ) {
case 5 :
V_2 = 0x28 ;
break;
case 7 :
V_2 = 0x8 ;
break;
case 9 :
V_2 = 0x10 ;
break;
case 10 :
V_2 = 0x18 ;
break;
case 11 :
V_2 = 0x20 ;
break;
default:
break;
}
return V_2 ;
}
static unsigned char F_2 ( int V_3 )
{
unsigned char V_2 = 0 ;
switch ( V_3 ) {
case 0 :
V_2 = 1 ;
break;
case 1 :
V_2 = 2 ;
break;
case 3 :
V_2 = 3 ;
break;
default:
break;
}
return V_2 ;
}
static unsigned char F_3 ( int V_4 )
{
unsigned char V_2 = 0 ;
switch ( V_4 ) {
case 5 :
V_2 = 4 ;
break;
case 7 :
V_2 = 0x44 ;
break;
case 9 :
V_2 = 0x84 ;
break;
case 10 :
V_2 = 0xc4 ;
break;
default:
break;
}
return V_2 ;
}
static int F_4 ( char T_1 * V_5 )
{
int V_6 = 1000 ;
unsigned char V_2 = 0 ;
do {
V_2 = F_5 ( V_5 + V_7 ) ;
if ( V_2 & 0x80 )
return 0 ;
F_6 () ;
} while ( V_6 -- );
return - V_8 ;
}
static int F_7 ( char T_1 * V_5 )
{
if ( F_4 ( V_5 ) )
return - V_9 ;
return F_5 ( V_5 + V_10 ) ;
}
static int F_8 ( char T_1 * V_5 , int V_11 )
{
unsigned char V_2 ;
int V_6 = 500000 ;
do {
V_2 = F_5 ( V_5 + V_12 ) ;
if ( ! ( V_2 & 0x80 ) ) {
F_9 ( V_11 , V_5 + V_13 ) ;
return 0 ;
}
F_6 () ;
} while ( V_6 -- );
F_10 ( V_14 L_1 , V_11 ) ;
return - V_15 ;
}
static int F_11 ( char T_1 * V_5 , int V_16 ,
char * V_17 , int V_18 )
{
int V_19 = 0 ;
if ( F_8 ( V_5 , V_16 ) ) {
F_10 ( V_14 L_2 , V_16 ) ;
return - V_15 ;
}
do {
int V_2 = F_7 ( V_5 ) ;
if ( V_2 < 0 )
break;
V_17 [ V_19 ++ ] = V_2 ;
} while ( V_19 < V_18 );
return V_19 ? V_19 : - V_15 ;
}
static int F_12 ( char T_1 * V_5 )
{
F_9 ( 1 , V_5 + V_20 ) ;
F_13 ( 10 ) ;
F_9 ( 0 , V_5 + V_20 ) ;
F_13 ( 20 ) ;
if ( F_7 ( V_5 ) == 0xaa )
return 0 ;
return - V_21 ;
}
static int F_14 ( char T_1 * V_5 , const int * V_22 )
{
if ( F_8 ( V_5 , V_23 ) < 0 ) {
F_10 ( V_24 L_2 , V_23 ) ;
return - V_15 ;
}
if ( F_8 ( V_5 , V_25 ) < 0 ) {
F_10 ( V_14 L_2 , V_25 ) ;
return - V_15 ;
}
if ( F_8 ( V_5 , V_22 [ 0 ] ) < 0 ) {
F_10 ( V_14 L_3 , V_22 [ 0 ] ) ;
return - V_15 ;
}
if ( F_8 ( V_5 , V_22 [ 1 ] ) < 0 ) {
F_10 ( V_14 L_3 , V_22 [ 1 ] ) ;
return - V_15 ;
}
if ( F_8 ( V_5 , V_26 ) < 0 ) {
F_10 ( V_14 L_2 , V_26 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_15 ( char T_1 * V_5 , unsigned char V_27 )
{
if ( F_8 ( V_5 , V_28 ) ) {
F_10 ( V_14 L_2 , V_28 ) ;
return - V_15 ;
}
if ( F_8 ( V_5 , V_27 ) ) {
F_10 ( V_14 L_4 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_16 ( char T_1 * V_5 , int V_29 )
{
int V_6 = 10 ;
do {
if ( F_8 ( V_5 , V_30 ) ) {
F_10 ( V_14 L_2 ,
V_30 ) ;
return - V_15 ;
}
} while ( ( F_4 ( V_5 ) < 0 ) && V_6 -- );
if ( F_7 ( V_5 ) < 0 ) {
F_10 ( V_14 L_5 ,
V_30 ) ;
return - V_15 ;
}
if ( F_15 ( V_5 , V_29 ) )
return - V_21 ;
return 0 ;
}
static int F_17 ( char T_1 * V_5 , int V_29 ,
char T_1 * V_31 , int V_32 )
{
if ( F_8 ( V_5 , V_33 ) ) {
F_10 ( V_14 L_6 ,
V_33 ) ;
return - V_15 ;
}
F_18 ( 10 ) ;
if ( F_15 ( V_5 , V_29 ) )
return - V_15 ;
F_9 ( V_32 , V_31 ) ;
return 0 ;
}
static void F_19 ( char T_1 * V_5 , int * V_22 ,
long V_34 , long V_35 ,
long V_36 , int V_37 )
{
V_22 [ 0 ] = 0 ;
V_22 [ 1 ] = 0 ;
if ( V_34 == 0x240 )
V_22 [ 0 ] |= 1 ;
if ( V_35 != V_38 ) {
V_22 [ 0 ] |= ( V_35 & 0x30 ) >> 2 ;
V_22 [ 1 ] |= 0x20 ;
}
if ( V_36 == 0xe80 )
V_22 [ 0 ] |= 0x10 ;
V_22 [ 0 ] |= 0x40 ;
if ( ! V_37 )
V_22 [ 0 ] |= 0x02 ;
V_22 [ 1 ] |= 0x80 ;
V_22 [ 1 ] &= ~ 0x40 ;
F_20 ( L_7 , V_22 [ 0 ] , V_22 [ 1 ] ) ;
}
static int F_21 ( char T_1 * V_5 ,
char T_1 * V_31 , int V_39 )
{
char V_40 [ 15 ] ;
char V_41 [ 2 ] ;
int V_32 = F_1 ( V_1 [ V_39 ] ) |
F_2 ( V_3 [ V_39 ] ) ;
int V_29 = V_32 |
F_3 ( V_4 [ V_39 ] ) ;
int V_42 ;
int V_43 = 0 ;
V_42 = F_12 ( V_5 ) ;
if ( V_42 < 0 ) {
F_10 ( V_14 L_8 ) ;
return V_42 ;
}
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
V_42 = F_11 ( V_5 , V_44 , V_40 , 15 ) ;
if ( V_42 <= 0 ) {
F_10 ( V_14 L_9 ) ;
return - V_21 ;
}
if ( strncmp ( L_10 , V_40 , 7 ) )
F_10 ( V_24 L_11 ) ;
if ( F_11 ( V_5 , V_45 , V_41 , 2 ) < 2 ) {
F_10 ( V_14 L_12 ) ;
return - V_21 ;
}
F_22 (KERN_INFO PFX L_13 ,
answer, version[0], version[1]) ;
F_8 ( V_5 , V_25 ) ;
if ( F_7 ( V_5 ) < 0 )
V_43 = 1 ;
if ( ! V_43 ) {
int V_22 [ 2 ] ;
F_19 ( V_5 , & V_22 [ 0 ] , V_46 [ V_39 ] , V_47 [ V_39 ] ,
V_48 [ V_39 ] , V_37 [ V_39 ] ) ;
if ( F_14 ( V_5 , V_22 ) < 0 ) {
F_10 ( V_14 L_14 ) ;
return - V_15 ;
}
}
V_42 = F_16 ( V_5 , V_29 ) ;
if ( V_42 < 0 ) {
F_10 ( V_14 L_15 ) ;
return - V_21 ;
}
F_12 ( V_5 ) ;
if ( ! V_43 ) {
F_8 ( V_5 , V_49 ) ;
F_8 ( V_5 , 0x02 ) ;
F_12 ( V_5 ) ;
}
V_42 = F_16 ( V_5 , V_29 ) ;
if ( V_42 < 0 ) {
F_10 ( V_14 L_15 ) ;
return - V_21 ;
}
V_42 = F_17 ( V_5 , V_29 , V_31 , V_32 ) ;
if ( V_42 < 0 ) {
F_10 ( V_14 L_16
L_17 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_23 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_53 ;
struct V_54 V_55 , V_56 ;
int V_42 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_55 . V_57 = V_58 ;
V_56 . V_57 = V_58 ;
strcpy ( V_55 . V_59 , L_18 ) ;
strcpy ( V_56 . V_59 , L_19 ) ;
V_42 = F_24 ( V_53 , & V_55 , & V_56 ) ;
if ( V_42 < 0 )
return V_42 ;
strcpy ( V_55 . V_59 , L_20 ) ;
strcpy ( V_56 . V_59 , L_21 ) ;
V_42 = F_24 ( V_53 , & V_55 , & V_56 ) ;
if ( V_42 < 0 )
return V_42 ;
strcpy ( V_55 . V_59 , L_18 ) ; V_55 . V_60 = 1 ;
strcpy ( V_56 . V_59 , L_22 ) ;
V_42 = F_24 ( V_53 , & V_55 , & V_56 ) ;
if ( V_42 < 0 )
return V_42 ;
strcpy ( V_55 . V_59 , L_20 ) ;
strcpy ( V_56 . V_59 , L_23 ) ;
V_42 = F_24 ( V_53 , & V_55 , & V_56 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static int F_25 ( struct V_61 * V_62 , unsigned int V_39 )
{
if ( ! V_63 [ V_39 ] )
return 0 ;
if ( V_46 [ V_39 ] == V_38 ) {
F_22 (KERN_ERR PFX L_24 ) ;
return 0 ;
}
if ( V_48 [ V_39 ] == V_38 ) {
F_22 (KERN_ERR PFX L_25 ) ;
return 0 ;
}
if ( V_46 [ V_39 ] != 0x220 && V_46 [ V_39 ] != 0x240 ) {
F_22 (KERN_ERR PFX L_26 ) ;
return 0 ;
}
if ( V_48 [ V_39 ] != 0x530 && V_48 [ V_39 ] != 0xe80 ) {
F_22 (KERN_ERR PFX L_27 ) ;
return 0 ;
}
if ( V_1 [ V_39 ] != V_64 && ! F_1 ( V_1 [ V_39 ] ) ) {
F_22 (KERN_ERR PFX L_28 , irq[dev]) ;
return 0 ;
}
if ( V_3 [ V_39 ] != V_65 && ! F_2 ( V_3 [ V_39 ] ) ) {
F_22 (KERN_ERR PFX L_29 , dma[dev]) ;
return 0 ;
}
if ( V_47 [ V_39 ] != V_38 &&
( V_47 [ V_39 ] & ~ 0x30L ) != 0x300 ) {
F_22 (KERN_ERR PFX L_30 ,
mpu_port[dev]) ;
return 0 ;
}
if ( V_47 [ V_39 ] != V_38 &&
V_4 [ V_39 ] != V_64 && V_4 [ V_39 ] != 0 &&
! F_3 ( V_4 [ V_39 ] ) ) {
F_22 (KERN_ERR PFX L_31 , mpu_irq[dev]) ;
return 0 ;
}
return 1 ;
}
static int F_26 ( struct V_61 * V_62 , unsigned int V_39 )
{
static int V_66 [] = { 5 , 7 , 9 , 10 , 11 , - 1 } ;
static int V_67 [] = { 1 , 3 , 0 , - 1 } ;
int V_42 ;
int V_68 = V_1 [ V_39 ] ;
int V_69 = V_3 [ V_39 ] ;
struct V_52 * V_53 ;
struct V_50 * V_51 ;
struct V_70 * V_71 ;
char T_1 * * V_5 ;
char T_1 * V_31 ;
V_42 = F_27 ( V_62 , V_60 [ V_39 ] , V_72 [ V_39 ] , V_73 ,
sizeof( V_5 ) , & V_53 ) ;
if ( V_42 < 0 )
return V_42 ;
V_5 = V_53 -> V_74 ;
if ( V_68 == V_64 ) {
V_68 = F_28 ( V_66 ) ;
if ( V_68 < 0 ) {
F_10 (KERN_ERR PFX L_32 ) ;
V_42 = - V_9 ;
goto V_75;
}
}
if ( V_69 == V_65 ) {
V_69 = F_29 ( V_67 ) ;
if ( V_69 < 0 ) {
F_10 (KERN_ERR PFX L_33 ) ;
V_42 = - V_9 ;
goto V_75;
}
}
if ( ! F_30 ( V_46 [ V_39 ] , 0x10 , V_76 ) ) {
F_10 (KERN_ERR PFX
L_34 ) ;
V_42 = - V_9 ;
goto V_75;
}
* V_5 = F_31 ( V_62 , V_46 [ V_39 ] , 0x10 ) ;
if ( * V_5 == NULL ) {
F_10 (KERN_ERR PFX
L_35 ) ;
V_42 = - V_9 ;
goto V_77;
}
if ( ! F_30 ( V_48 [ V_39 ] , 4 , V_76 ) ) {
F_10 (KERN_ERR PFX
L_36 ) ;
V_42 = - V_9 ;
goto V_77;
}
V_31 = F_31 ( V_62 , V_48 [ V_39 ] , 4 ) ;
if ( ! V_31 ) {
F_10 (KERN_ERR PFX
L_37 ) ;
V_42 = - V_9 ;
goto V_78;
}
F_20 ( L_38 ,
V_46 [ V_39 ] , V_68 , V_69 ,
V_4 [ V_39 ] == V_64 ? 0 : V_4 [ V_39 ] ) ;
V_42 = F_21 ( * V_5 , V_31 , V_39 ) ;
if ( V_42 < 0 )
goto V_78;
V_42 = F_32 ( V_53 , V_48 [ V_39 ] + 4 , - 1 , V_68 , V_69 , - 1 ,
V_79 , 0 , & V_51 ) ;
if ( V_42 < 0 )
goto V_78;
V_42 = F_33 ( V_51 , 0 ) ;
if ( V_42 < 0 ) {
F_10 (KERN_ERR PFX
L_39 ) ;
goto V_78;
}
V_42 = F_34 ( V_51 ) ;
if ( V_42 < 0 ) {
F_10 (KERN_ERR PFX L_40 ) ;
goto V_78;
}
V_42 = F_23 ( V_51 ) ;
if ( V_42 < 0 ) {
F_10 (KERN_ERR PFX L_41 ) ;
goto V_78;
}
if ( F_35 ( V_53 ,
0x388 , 0x388 + 2 ,
V_80 , 0 , & V_71 ) < 0 ) {
F_10 (KERN_ERR PFX L_42 ,
0x388 , 0x388 + 2 ) ;
} else {
V_42 = F_36 ( V_71 , 0 , 1 , NULL ) ;
if ( V_42 < 0 )
goto V_78;
}
if ( V_47 [ V_39 ] != V_38 ) {
if ( V_4 [ V_39 ] == V_64 )
V_4 [ V_39 ] = - 1 ;
if ( F_37 ( V_53 , 0 ,
V_81 ,
V_47 [ V_39 ] , 0 ,
V_4 [ V_39 ] , NULL ) < 0 )
F_10 ( V_14 L_43 ,
V_47 [ V_39 ] ) ;
}
strcpy ( V_53 -> V_82 , V_76 ) ;
strcpy ( V_53 -> V_83 , L_10 ) ;
sprintf ( V_53 -> V_84 , L_44 ,
V_48 [ V_39 ] , V_68 , V_69 ) ;
V_42 = F_38 ( V_53 ) ;
if ( V_42 < 0 )
goto V_78;
F_39 ( V_62 , V_53 ) ;
return 0 ;
V_78:
F_16 ( * V_5 , 0 ) ;
F_40 ( V_48 [ V_39 ] , 4 ) ;
V_77:
F_40 ( V_46 [ V_39 ] , 0x10 ) ;
V_75:
F_41 ( V_53 ) ;
return V_42 ;
}
static int F_42 ( struct V_61 * V_62 , unsigned int V_39 )
{
struct V_52 * V_53 = F_43 ( V_62 ) ;
char T_1 * * V_5 = V_53 -> V_74 ;
if ( F_16 ( * V_5 , 0 ) < 0 )
F_10 ( V_24 L_45 ) ;
F_40 ( V_46 [ V_39 ] , 0x10 ) ;
F_40 ( V_48 [ V_39 ] , 4 ) ;
F_41 ( V_53 ) ;
return 0 ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_85 , V_86 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_85 ) ;
}
