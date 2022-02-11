static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_4 ) ;
F_3 ( V_3 -> V_5 ) ;
F_4 ( V_3 ) ;
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_2 ( V_1 , struct V_6 , V_4 ) ;
struct V_2 * V_3 = V_7 -> V_3 ;
unsigned long V_8 ;
if ( F_7 ( V_7 -> V_9 ) )
F_8 ( V_7 -> V_9 ) ;
F_9 ( & V_3 -> V_10 , V_8 ) ;
F_10 ( & V_7 -> V_11 ) ;
F_11 ( & V_3 -> V_10 , V_8 ) ;
F_4 ( V_7 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
}
static void F_13 ( struct V_9 * V_9 )
{
struct V_6 * V_7 ;
struct V_12 * V_13 ;
struct V_2 * V_3 ;
int V_14 = V_9 -> V_14 ;
V_7 = V_9 -> V_15 ;
V_3 = V_7 -> V_3 ;
V_13 = V_3 -> V_13 ;
if ( V_14 ) {
F_14 ( L_2 , V_14 ) ;
} else if ( V_7 -> V_16 . V_17 == 3 ) {
memcpy ( V_3 -> V_18 , V_7 -> V_18 , sizeof( V_3 -> V_18 ) ) ;
#if 0
dbg("async_complete regs %02x %02x %02x %02x %02x %02x %02x",
(unsigned int)priv->reg[0], (unsigned int)priv->reg[1], (unsigned int)priv->reg[2],
(unsigned int)priv->reg[3], (unsigned int)priv->reg[4], (unsigned int)priv->reg[5],
(unsigned int)priv->reg[6]);
#endif
if ( V_7 -> V_18 [ 2 ] & V_7 -> V_18 [ 1 ] & 0x10 && V_13 )
F_15 ( V_13 ) ;
}
F_16 ( & V_7 -> V_19 ) ;
F_12 ( & V_7 -> V_4 , F_6 ) ;
}
static struct V_6 * F_17 ( struct V_2 * V_3 ,
T_1 V_20 , T_1 V_21 , T_2 V_22 , T_2 V_23 ,
T_3 V_24 )
{
struct V_25 * V_5 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_26 ;
if ( ! V_3 )
return NULL ;
V_5 = V_3 -> V_5 ;
if ( ! V_5 )
return NULL ;
V_7 = F_18 ( sizeof( struct V_6 ) , V_24 ) ;
if ( ! V_7 ) {
F_14 ( L_3 ) ;
return NULL ;
}
F_19 ( & V_7 -> V_4 ) ;
F_20 ( & V_7 -> V_11 ) ;
F_21 ( & V_7 -> V_19 ) ;
F_22 ( & V_3 -> V_4 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_9 = F_23 ( 0 , V_24 ) ;
if ( ! V_7 -> V_9 ) {
F_12 ( & V_7 -> V_4 , F_6 ) ;
F_14 ( L_3 ) ;
return NULL ;
}
V_7 -> V_16 . V_27 = V_21 ;
V_7 -> V_16 . V_17 = V_20 ;
V_7 -> V_16 . V_28 = F_24 ( V_22 ) ;
V_7 -> V_16 . V_29 = F_24 ( V_23 ) ;
V_7 -> V_16 . V_30 = F_24 ( ( V_20 == 3 ) ? sizeof( V_7 -> V_18 ) : 0 ) ;
F_25 ( V_7 -> V_9 , V_5 , ( V_21 & 0x80 ) ? F_26 ( V_5 , 0 ) : F_27 ( V_5 , 0 ) ,
( unsigned char * ) & V_7 -> V_16 ,
( V_20 == 3 ) ? V_7 -> V_18 : NULL , ( V_20 == 3 ) ? sizeof( V_7 -> V_18 ) : 0 , F_13 , V_7 ) ;
F_9 ( & V_3 -> V_10 , V_8 ) ;
F_28 ( & V_7 -> V_11 , & V_3 -> V_11 ) ;
F_11 ( & V_3 -> V_10 , V_8 ) ;
F_22 ( & V_7 -> V_4 ) ;
V_26 = F_29 ( V_7 -> V_9 , V_24 ) ;
if ( ! V_26 )
return V_7 ;
F_6 ( & V_7 -> V_4 ) ;
F_14 ( L_4 , V_26 ) ;
return NULL ;
}
static unsigned int F_30 ( struct V_2 * V_3 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
unsigned int V_26 = 0 ;
F_9 ( & V_3 -> V_10 , V_8 ) ;
F_31 (rq, &priv->asynclist, asynclist) {
F_32 ( V_7 -> V_9 ) ;
V_26 ++ ;
}
F_11 ( & V_3 -> V_10 , V_8 ) ;
return V_26 ;
}
static int F_33 ( struct V_12 * V_13 , unsigned char V_18 , unsigned char * V_31 , T_3 V_24 )
{
struct V_2 * V_3 ;
struct V_6 * V_7 ;
static const unsigned char V_32 [ 9 ] = {
4 , 0 , 1 , 5 , 5 , 0 , 2 , 3 , 6
} ;
int V_26 ;
if ( ! V_13 )
return - V_33 ;
V_3 = V_13 -> V_34 ;
V_7 = F_17 ( V_3 , 3 , 0xc0 , ( ( unsigned int ) V_18 ) << 8 , 0 , V_24 ) ;
if ( ! V_7 ) {
F_14 ( L_5 , ( unsigned int ) V_18 ) ;
return - V_33 ;
}
if ( ! V_31 ) {
F_12 ( & V_7 -> V_4 , F_6 ) ;
return 0 ;
}
if ( F_34 ( & V_7 -> V_19 , V_35 ) ) {
V_26 = V_7 -> V_9 -> V_14 ;
* V_31 = V_3 -> V_18 [ ( V_18 >= 9 ) ? 0 : V_32 [ V_18 ] ] ;
if ( V_26 )
F_35 ( V_36 L_6
L_7 , V_26 ) ;
F_12 ( & V_7 -> V_4 , F_6 ) ;
return V_26 ;
}
F_35 ( V_36 L_8 ) ;
F_30 ( V_3 ) ;
return - V_33 ;
}
static int F_36 ( struct V_12 * V_13 , unsigned char V_18 , unsigned char V_31 , T_3 V_24 )
{
struct V_2 * V_3 ;
struct V_6 * V_7 ;
if ( ! V_13 )
return - V_33 ;
V_3 = V_13 -> V_34 ;
V_7 = F_17 ( V_3 , 4 , 0x40 , ( ( ( unsigned int ) V_18 ) << 8 ) | V_31 , 0 , V_24 ) ;
if ( ! V_7 ) {
F_14 ( L_9 , ( unsigned int ) V_18 , ( unsigned int ) V_31 ) ;
return - V_33 ;
}
F_12 ( & V_7 -> V_4 , F_6 ) ;
return 0 ;
}
static int F_37 ( struct V_12 * V_13 , int V_37 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
int V_38 ;
T_1 V_18 ;
if ( F_33 ( V_13 , 6 , & V_18 , V_39 ) )
return - V_33 ;
V_38 = ( V_3 -> V_18 [ 2 ] >> 5 ) & 0x7 ;
if ( V_38 == V_37 )
return 0 ;
if ( V_38 > V_40 && V_37 > V_40 )
if ( F_37 ( V_13 , V_40 ) )
return - V_33 ;
if ( V_37 <= V_40 && ! ( V_3 -> V_18 [ 1 ] & 0x20 ) ) {
unsigned long V_41 = V_42 + V_13 -> V_43 -> V_44 -> V_45 ;
switch ( V_38 ) {
case V_46 :
case V_47 :
for (; ; ) {
if ( F_33 ( V_13 , 6 , & V_18 , V_39 ) )
return - V_33 ;
if ( V_3 -> V_18 [ 2 ] & 0x01 )
break;
if ( F_38 ( V_42 , V_41 ) )
return - V_48 ;
F_39 ( 10 ) ;
if ( F_40 ( V_49 ) )
break;
}
}
}
if ( F_36 ( V_13 , 6 , V_37 << 5 , V_39 ) )
return - V_33 ;
if ( F_33 ( V_13 , 6 , & V_18 , V_39 ) )
return - V_33 ;
return 0 ;
}
static int F_41 ( struct V_12 * V_13 )
{
unsigned char V_50 ;
if ( F_33 ( V_13 , 1 , & V_50 , V_39 ) )
return 1 ;
return V_50 & 1 ;
}
static void F_42 ( struct V_12 * V_13 , unsigned char V_51 )
{
F_36 ( V_13 , 0 , V_51 , V_39 ) ;
}
static unsigned char F_43 ( struct V_12 * V_13 )
{
unsigned char V_26 ;
if ( F_33 ( V_13 , 0 , & V_26 , V_39 ) )
return 0 ;
return V_26 ;
}
static void F_44 ( struct V_12 * V_13 , unsigned char V_51 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
V_51 = ( V_51 & 0xf ) | ( V_3 -> V_18 [ 1 ] & 0xf0 ) ;
if ( F_36 ( V_13 , 2 , V_51 , V_39 ) )
return;
V_3 -> V_18 [ 1 ] = V_51 ;
}
static unsigned char F_45 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
return V_3 -> V_18 [ 1 ] & 0xf ;
}
static unsigned char F_46 ( struct V_12 * V_13 , unsigned char V_52 , unsigned char V_31 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
unsigned char V_51 ;
V_52 &= 0x0f ;
V_31 &= 0x0f ;
V_51 = ( V_3 -> V_18 [ 1 ] & ( ~ V_52 ) ) ^ V_31 ;
if ( F_36 ( V_13 , 2 , V_51 , V_39 ) )
return 0 ;
V_3 -> V_18 [ 1 ] = V_51 ;
return V_51 & 0xf ;
}
static unsigned char F_47 ( struct V_12 * V_13 )
{
unsigned char V_26 ;
if ( F_33 ( V_13 , 1 , & V_26 , V_39 ) )
return 0 ;
return V_26 & 0xf8 ;
}
static void F_48 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
unsigned char V_51 ;
V_51 = V_3 -> V_18 [ 1 ] & ~ 0x10 ;
if ( F_36 ( V_13 , 2 , V_51 , V_39 ) )
return;
V_3 -> V_18 [ 1 ] = V_51 ;
}
static void F_49 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
unsigned char V_51 ;
V_51 = V_3 -> V_18 [ 1 ] | 0x10 ;
if ( F_36 ( V_13 , 2 , V_51 , V_39 ) )
return;
V_3 -> V_18 [ 1 ] = V_51 ;
}
static void F_50 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
unsigned char V_51 ;
V_51 = V_3 -> V_18 [ 1 ] & ~ 0x20 ;
if ( F_36 ( V_13 , 2 , V_51 , V_39 ) )
return;
V_3 -> V_18 [ 1 ] = V_51 ;
}
static void F_51 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
unsigned char V_51 ;
V_51 = V_3 -> V_18 [ 1 ] | 0x20 ;
if ( F_36 ( V_13 , 2 , V_51 , V_39 ) )
return;
V_3 -> V_18 [ 1 ] = V_51 ;
}
static void F_52 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
V_56 -> V_57 . V_58 . V_59 = 0xc | ( V_54 -> V_60 ? 0x10 : 0x0 ) ;
V_56 -> V_57 . V_58 . V_61 = 0x24 ;
}
static void F_53 ( struct V_12 * V_13 , struct V_55 * V_56 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
#if 0
if (get_1284_register(pp, 2, NULL, GFP_ATOMIC))
return;
#endif
V_56 -> V_57 . V_58 . V_59 = V_3 -> V_18 [ 1 ] ;
V_56 -> V_57 . V_58 . V_61 = V_3 -> V_18 [ 2 ] ;
}
static void F_54 ( struct V_12 * V_13 , struct V_55 * V_56 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
F_36 ( V_13 , 2 , V_56 -> V_57 . V_58 . V_59 , V_62 ) ;
F_36 ( V_13 , 6 , V_56 -> V_57 . V_58 . V_61 , V_62 ) ;
F_33 ( V_13 , 2 , NULL , V_62 ) ;
V_3 -> V_18 [ 1 ] = V_56 -> V_57 . V_58 . V_59 ;
V_3 -> V_18 [ 2 ] = V_56 -> V_57 . V_58 . V_61 ;
}
static T_4 F_55 ( struct V_12 * V_13 , void * V_63 , T_4 V_64 , int V_8 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
T_4 V_65 = 0 ;
if ( F_37 ( V_13 , V_66 ) )
return 0 ;
for (; V_65 < V_64 ; V_65 ++ ) {
if ( F_33 ( V_13 , 4 , ( char * ) V_63 , V_39 ) )
break;
V_63 ++ ;
if ( V_3 -> V_18 [ 0 ] & 0x01 ) {
F_41 ( V_13 ) ;
break;
}
}
F_37 ( V_13 , V_40 ) ;
return V_65 ;
}
static T_4 F_56 ( struct V_12 * V_13 , const void * V_63 , T_4 V_64 , int V_8 )
{
#if 0
struct parport_uss720_private *priv = pp->private_data;
size_t written = 0;
if (change_mode(pp, ECR_EPP))
return 0;
for (; written < length; written++) {
if (set_1284_register(pp, 4, (char *)buf, GFP_KERNEL))
break;
((char*)buf)++;
if (get_1284_register(pp, 1, NULL, GFP_KERNEL))
break;
if (priv->reg[0] & 0x01) {
clear_epp_timeout(pp);
break;
}
}
change_mode(pp, ECR_PS2);
return written;
#else
struct V_2 * V_3 = V_13 -> V_34 ;
struct V_25 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_37 ( V_13 , V_66 ) )
return 0 ;
V_68 = F_57 ( V_5 , F_58 ( V_5 , 1 ) , ( void * ) V_63 , V_64 , & V_67 , 20000 ) ;
if ( V_68 )
F_35 ( V_69 L_10 , V_63 , V_64 , V_67 ) ;
F_37 ( V_13 , V_40 ) ;
return V_67 ;
#endif
}
static T_4 F_59 ( struct V_12 * V_13 , void * V_63 , T_4 V_64 , int V_8 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
T_4 V_65 = 0 ;
if ( F_37 ( V_13 , V_66 ) )
return 0 ;
for (; V_65 < V_64 ; V_65 ++ ) {
if ( F_33 ( V_13 , 3 , ( char * ) V_63 , V_39 ) )
break;
V_63 ++ ;
if ( V_3 -> V_18 [ 0 ] & 0x01 ) {
F_41 ( V_13 ) ;
break;
}
}
F_37 ( V_13 , V_40 ) ;
return V_65 ;
}
static T_4 F_60 ( struct V_12 * V_13 , const void * V_63 , T_4 V_64 , int V_8 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
T_4 V_70 = 0 ;
if ( F_37 ( V_13 , V_66 ) )
return 0 ;
for (; V_70 < V_64 ; V_70 ++ ) {
if ( F_36 ( V_13 , 3 , * ( char * ) V_63 , V_39 ) )
break;
V_63 ++ ;
if ( F_33 ( V_13 , 1 , NULL , V_39 ) )
break;
if ( V_3 -> V_18 [ 0 ] & 0x01 ) {
F_41 ( V_13 ) ;
break;
}
}
F_37 ( V_13 , V_40 ) ;
return V_70 ;
}
static T_4 F_61 ( struct V_12 * V_13 , const void * V_71 , T_4 V_72 , int V_8 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
struct V_25 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_37 ( V_13 , V_47 ) )
return 0 ;
V_68 = F_57 ( V_5 , F_58 ( V_5 , 1 ) , ( void * ) V_71 , V_72 , & V_67 , 20000 ) ;
if ( V_68 )
F_35 ( V_69 L_10 , V_71 , V_72 , V_67 ) ;
F_37 ( V_13 , V_40 ) ;
return V_67 ;
}
static T_4 F_62 ( struct V_12 * V_13 , void * V_71 , T_4 V_72 , int V_8 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
struct V_25 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_37 ( V_13 , V_47 ) )
return 0 ;
V_68 = F_57 ( V_5 , F_63 ( V_5 , 2 ) , V_71 , V_72 , & V_67 , 20000 ) ;
if ( V_68 )
F_35 ( V_69 L_11 , V_71 , V_72 , V_67 ) ;
F_37 ( V_13 , V_40 ) ;
return V_67 ;
}
static T_4 F_64 ( struct V_12 * V_13 , const void * V_71 , T_4 V_72 , int V_8 )
{
T_4 V_70 = 0 ;
if ( F_37 ( V_13 , V_47 ) )
return 0 ;
for (; V_70 < V_72 ; V_70 ++ ) {
if ( F_36 ( V_13 , 5 , * ( char * ) V_71 , V_39 ) )
break;
V_71 ++ ;
}
F_37 ( V_13 , V_40 ) ;
return V_70 ;
}
static T_4 F_65 ( struct V_12 * V_13 , const void * V_71 , T_4 V_72 , int V_8 )
{
struct V_2 * V_3 = V_13 -> V_34 ;
struct V_25 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_37 ( V_13 , V_46 ) )
return 0 ;
V_68 = F_57 ( V_5 , F_58 ( V_5 , 1 ) , ( void * ) V_71 , V_72 , & V_67 , 20000 ) ;
if ( V_68 )
F_35 ( V_69 L_10 , V_71 , V_72 , V_67 ) ;
F_37 ( V_13 , V_40 ) ;
return V_67 ;
}
static int F_66 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_25 * V_5 = F_67 ( F_68 ( V_74 ) ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_2 * V_3 ;
struct V_12 * V_13 ;
unsigned char V_18 ;
int V_68 ;
F_5 ( L_12 ,
F_69 ( V_5 -> V_81 . V_82 ) ,
F_69 ( V_5 -> V_81 . V_83 ) ) ;
if ( V_74 -> V_84 != 3 ) {
F_3 ( V_5 ) ;
return - V_85 ;
}
V_68 = F_70 ( V_5 , V_74 -> V_86 -> V_87 . V_88 , 2 ) ;
F_5 ( L_13 , V_68 ) ;
V_78 = V_74 -> V_89 ;
if ( ! ( V_3 = F_71 ( sizeof( struct V_2 ) , V_39 ) ) ) {
F_3 ( V_5 ) ;
return - V_90 ;
}
V_3 -> V_13 = NULL ;
V_3 -> V_5 = V_5 ;
F_19 ( & V_3 -> V_4 ) ;
F_72 ( & V_3 -> V_10 ) ;
F_20 ( & V_3 -> V_11 ) ;
if ( ! ( V_13 = F_73 ( 0 , V_91 , V_92 , & V_93 ) ) ) {
F_35 ( V_36 L_14 ) ;
goto V_94;
}
V_3 -> V_13 = V_13 ;
V_13 -> V_34 = V_3 ;
V_13 -> V_95 = V_96 | V_97 | V_98 | V_99 | V_100 ;
F_36 ( V_13 , 7 , 0x00 , V_39 ) ;
F_36 ( V_13 , 6 , 0x30 , V_39 ) ;
F_36 ( V_13 , 2 , 0x0c , V_39 ) ;
F_33 ( V_13 , 0 , & V_18 , V_39 ) ;
F_5 ( L_15 ,
V_3 -> V_18 [ 0 ] , V_3 -> V_18 [ 1 ] , V_3 -> V_18 [ 2 ] , V_3 -> V_18 [ 3 ] , V_3 -> V_18 [ 4 ] , V_3 -> V_18 [ 5 ] , V_3 -> V_18 [ 6 ] ) ;
V_80 = & V_78 -> V_80 [ 2 ] ;
F_5 ( L_16 , V_80 -> V_87 . V_101 , V_80 -> V_87 . V_102 ) ;
F_74 ( V_13 ) ;
F_75 ( V_74 , V_13 ) ;
return 0 ;
V_94:
F_30 ( V_3 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
return - V_85 ;
}
static void F_76 ( struct V_73 * V_74 )
{
struct V_12 * V_13 = F_77 ( V_74 ) ;
struct V_2 * V_3 ;
struct V_25 * V_5 ;
F_5 ( L_17 ) ;
F_75 ( V_74 , NULL ) ;
if ( V_13 ) {
V_3 = V_13 -> V_34 ;
V_5 = V_3 -> V_5 ;
V_3 -> V_5 = NULL ;
V_3 -> V_13 = NULL ;
F_5 ( L_18 ) ;
F_78 ( V_13 ) ;
F_79 ( V_13 ) ;
F_30 ( V_3 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
}
F_5 ( L_19 ) ;
}
static int T_5 F_80 ( void )
{
int V_103 ;
V_103 = F_81 ( & V_104 ) ;
if ( V_103 )
goto V_105;
F_35 (KERN_INFO KBUILD_MODNAME L_20 DRIVER_VERSION L_21
DRIVER_DESC L_22 ) ;
F_35 (KERN_INFO KBUILD_MODNAME L_23
L_24 ) ;
F_35 (KERN_INFO KBUILD_MODNAME L_25
L_26 ) ;
F_35 (KERN_INFO KBUILD_MODNAME L_27
L_28 ) ;
V_105:
return V_103 ;
}
static void T_6 F_82 ( void )
{
F_83 ( & V_104 ) ;
}
