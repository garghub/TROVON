static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_4 ) ;
F_3 ( & V_3 -> V_5 -> V_6 , L_1 ) ;
F_4 ( V_3 -> V_5 ) ;
F_5 ( V_3 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = F_2 ( V_1 , struct V_7 , V_4 ) ;
struct V_2 * V_3 = V_8 -> V_3 ;
unsigned long V_9 ;
if ( F_7 ( V_8 -> V_10 ) )
F_8 ( V_8 -> V_10 ) ;
F_5 ( V_8 -> V_11 ) ;
F_9 ( & V_3 -> V_12 , V_9 ) ;
F_10 ( & V_8 -> V_13 ) ;
F_11 ( & V_3 -> V_12 , V_9 ) ;
F_5 ( V_8 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
}
static void F_13 ( struct V_10 * V_10 )
{
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_2 * V_3 ;
int V_16 = V_10 -> V_16 ;
V_8 = V_10 -> V_17 ;
V_3 = V_8 -> V_3 ;
V_15 = V_3 -> V_15 ;
if ( V_16 ) {
F_14 ( & V_10 -> V_6 -> V_6 , L_2 ,
V_16 ) ;
} else if ( V_8 -> V_11 -> V_18 == 3 ) {
memcpy ( V_3 -> V_19 , V_8 -> V_19 , sizeof( V_3 -> V_19 ) ) ;
#if 0
dev_dbg(&priv->usbdev->dev, "async_complete regs %7ph\n",
priv->reg);
#endif
if ( V_8 -> V_19 [ 2 ] & V_8 -> V_19 [ 1 ] & 0x10 && V_15 )
F_15 ( V_15 ) ;
}
F_16 ( & V_8 -> V_20 ) ;
F_12 ( & V_8 -> V_4 , F_6 ) ;
}
static struct V_7 * F_17 ( struct V_2 * V_3 ,
T_1 V_21 , T_1 V_22 , T_2 V_23 , T_2 V_24 ,
T_3 V_25 )
{
struct V_26 * V_5 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
int V_27 ;
if ( ! V_3 )
return NULL ;
V_5 = V_3 -> V_5 ;
if ( ! V_5 )
return NULL ;
V_8 = F_18 ( sizeof( struct V_7 ) , V_25 ) ;
if ( ! V_8 ) {
F_14 ( & V_5 -> V_6 , L_3 ) ;
return NULL ;
}
F_19 ( & V_8 -> V_4 ) ;
F_20 ( & V_8 -> V_13 ) ;
F_21 ( & V_8 -> V_20 ) ;
F_22 ( & V_3 -> V_4 ) ;
V_8 -> V_3 = V_3 ;
V_8 -> V_10 = F_23 ( 0 , V_25 ) ;
if ( ! V_8 -> V_10 ) {
F_12 ( & V_8 -> V_4 , F_6 ) ;
F_14 ( & V_5 -> V_6 , L_3 ) ;
return NULL ;
}
V_8 -> V_11 = F_24 ( sizeof( * V_8 -> V_11 ) , V_25 ) ;
if ( ! V_8 -> V_11 ) {
F_12 ( & V_8 -> V_4 , F_6 ) ;
return NULL ;
}
V_8 -> V_11 -> V_28 = V_22 ;
V_8 -> V_11 -> V_18 = V_21 ;
V_8 -> V_11 -> V_29 = F_25 ( V_23 ) ;
V_8 -> V_11 -> V_30 = F_25 ( V_24 ) ;
V_8 -> V_11 -> V_31 = F_25 ( ( V_21 == 3 ) ? sizeof( V_8 -> V_19 ) : 0 ) ;
F_26 ( V_8 -> V_10 , V_5 , ( V_22 & 0x80 ) ? F_27 ( V_5 , 0 ) : F_28 ( V_5 , 0 ) ,
( unsigned char * ) V_8 -> V_11 ,
( V_21 == 3 ) ? V_8 -> V_19 : NULL , ( V_21 == 3 ) ? sizeof( V_8 -> V_19 ) : 0 , F_13 , V_8 ) ;
F_9 ( & V_3 -> V_12 , V_9 ) ;
F_29 ( & V_8 -> V_13 , & V_3 -> V_13 ) ;
F_11 ( & V_3 -> V_12 , V_9 ) ;
F_22 ( & V_8 -> V_4 ) ;
V_27 = F_30 ( V_8 -> V_10 , V_25 ) ;
if ( ! V_27 )
return V_8 ;
F_6 ( & V_8 -> V_4 ) ;
F_14 ( & V_5 -> V_6 , L_4 , V_27 ) ;
return NULL ;
}
static unsigned int F_31 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
unsigned int V_27 = 0 ;
F_9 ( & V_3 -> V_12 , V_9 ) ;
F_32 (rq, &priv->asynclist, asynclist) {
F_33 ( V_8 -> V_10 ) ;
V_27 ++ ;
}
F_11 ( & V_3 -> V_12 , V_9 ) ;
return V_27 ;
}
static int F_34 ( struct V_14 * V_15 , unsigned char V_19 , unsigned char * V_32 , T_3 V_25 )
{
struct V_2 * V_3 ;
struct V_7 * V_8 ;
static const unsigned char V_33 [ 9 ] = {
4 , 0 , 1 , 5 , 5 , 0 , 2 , 3 , 6
} ;
int V_27 ;
if ( ! V_15 )
return - V_34 ;
V_3 = V_15 -> V_35 ;
V_8 = F_17 ( V_3 , 3 , 0xc0 , ( ( unsigned int ) V_19 ) << 8 , 0 , V_25 ) ;
if ( ! V_8 ) {
F_14 ( & V_3 -> V_5 -> V_6 , L_5 ,
( unsigned int ) V_19 ) ;
return - V_34 ;
}
if ( ! V_32 ) {
F_12 ( & V_8 -> V_4 , F_6 ) ;
return 0 ;
}
if ( F_35 ( & V_8 -> V_20 , V_36 ) ) {
V_27 = V_8 -> V_10 -> V_16 ;
* V_32 = V_3 -> V_19 [ ( V_19 >= 9 ) ? 0 : V_33 [ V_19 ] ] ;
if ( V_27 )
F_36 ( V_37 L_6
L_7 , V_27 ) ;
F_12 ( & V_8 -> V_4 , F_6 ) ;
return V_27 ;
}
F_36 ( V_37 L_8 ) ;
F_31 ( V_3 ) ;
return - V_34 ;
}
static int F_37 ( struct V_14 * V_15 , unsigned char V_19 , unsigned char V_32 , T_3 V_25 )
{
struct V_2 * V_3 ;
struct V_7 * V_8 ;
if ( ! V_15 )
return - V_34 ;
V_3 = V_15 -> V_35 ;
V_8 = F_17 ( V_3 , 4 , 0x40 , ( ( ( unsigned int ) V_19 ) << 8 ) | V_32 , 0 , V_25 ) ;
if ( ! V_8 ) {
F_14 ( & V_3 -> V_5 -> V_6 , L_9 ,
( unsigned int ) V_19 , ( unsigned int ) V_32 ) ;
return - V_34 ;
}
F_12 ( & V_8 -> V_4 , F_6 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 , int V_38 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
int V_39 ;
T_1 V_19 ;
if ( F_34 ( V_15 , 6 , & V_19 , V_40 ) )
return - V_34 ;
V_39 = ( V_3 -> V_19 [ 2 ] >> 5 ) & 0x7 ;
if ( V_39 == V_38 )
return 0 ;
if ( V_39 > V_41 && V_38 > V_41 )
if ( F_38 ( V_15 , V_41 ) )
return - V_34 ;
if ( V_38 <= V_41 && ! ( V_3 -> V_19 [ 1 ] & 0x20 ) ) {
unsigned long V_42 = V_43 + V_15 -> V_44 -> V_45 -> V_46 ;
switch ( V_39 ) {
case V_47 :
case V_48 :
for (; ; ) {
if ( F_34 ( V_15 , 6 , & V_19 , V_40 ) )
return - V_34 ;
if ( V_3 -> V_19 [ 2 ] & 0x01 )
break;
if ( F_39 ( V_43 , V_42 ) )
return - V_49 ;
F_40 ( 10 ) ;
if ( F_41 ( V_50 ) )
break;
}
}
}
if ( F_37 ( V_15 , 6 , V_38 << 5 , V_40 ) )
return - V_34 ;
if ( F_34 ( V_15 , 6 , & V_19 , V_40 ) )
return - V_34 ;
return 0 ;
}
static int F_42 ( struct V_14 * V_15 )
{
unsigned char V_51 ;
if ( F_34 ( V_15 , 1 , & V_51 , V_40 ) )
return 1 ;
return V_51 & 1 ;
}
static void F_43 ( struct V_14 * V_15 , unsigned char V_52 )
{
F_37 ( V_15 , 0 , V_52 , V_40 ) ;
}
static unsigned char F_44 ( struct V_14 * V_15 )
{
unsigned char V_27 ;
if ( F_34 ( V_15 , 0 , & V_27 , V_40 ) )
return 0 ;
return V_27 ;
}
static void F_45 ( struct V_14 * V_15 , unsigned char V_52 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
V_52 = ( V_52 & 0xf ) | ( V_3 -> V_19 [ 1 ] & 0xf0 ) ;
if ( F_37 ( V_15 , 2 , V_52 , V_40 ) )
return;
V_3 -> V_19 [ 1 ] = V_52 ;
}
static unsigned char F_46 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
return V_3 -> V_19 [ 1 ] & 0xf ;
}
static unsigned char F_47 ( struct V_14 * V_15 , unsigned char V_53 , unsigned char V_32 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
unsigned char V_52 ;
V_53 &= 0x0f ;
V_32 &= 0x0f ;
V_52 = ( V_3 -> V_19 [ 1 ] & ( ~ V_53 ) ) ^ V_32 ;
if ( F_37 ( V_15 , 2 , V_52 , V_40 ) )
return 0 ;
V_3 -> V_19 [ 1 ] = V_52 ;
return V_52 & 0xf ;
}
static unsigned char F_48 ( struct V_14 * V_15 )
{
unsigned char V_27 ;
if ( F_34 ( V_15 , 1 , & V_27 , V_40 ) )
return 0 ;
return V_27 & 0xf8 ;
}
static void F_49 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
unsigned char V_52 ;
V_52 = V_3 -> V_19 [ 1 ] & ~ 0x10 ;
if ( F_37 ( V_15 , 2 , V_52 , V_40 ) )
return;
V_3 -> V_19 [ 1 ] = V_52 ;
}
static void F_50 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
unsigned char V_52 ;
V_52 = V_3 -> V_19 [ 1 ] | 0x10 ;
if ( F_37 ( V_15 , 2 , V_52 , V_40 ) )
return;
V_3 -> V_19 [ 1 ] = V_52 ;
}
static void F_51 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
unsigned char V_52 ;
V_52 = V_3 -> V_19 [ 1 ] & ~ 0x20 ;
if ( F_37 ( V_15 , 2 , V_52 , V_40 ) )
return;
V_3 -> V_19 [ 1 ] = V_52 ;
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
unsigned char V_52 ;
V_52 = V_3 -> V_19 [ 1 ] | 0x20 ;
if ( F_37 ( V_15 , 2 , V_52 , V_40 ) )
return;
V_3 -> V_19 [ 1 ] = V_52 ;
}
static void F_53 ( struct V_54 * V_6 , struct V_55 * V_56 )
{
V_56 -> V_57 . V_58 . V_59 = 0xc | ( V_6 -> V_60 ? 0x10 : 0x0 ) ;
V_56 -> V_57 . V_58 . V_61 = 0x24 ;
}
static void F_54 ( struct V_14 * V_15 , struct V_55 * V_56 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
#if 0
if (get_1284_register(pp, 2, NULL, GFP_ATOMIC))
return;
#endif
V_56 -> V_57 . V_58 . V_59 = V_3 -> V_19 [ 1 ] ;
V_56 -> V_57 . V_58 . V_61 = V_3 -> V_19 [ 2 ] ;
}
static void F_55 ( struct V_14 * V_15 , struct V_55 * V_56 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
F_37 ( V_15 , 2 , V_56 -> V_57 . V_58 . V_59 , V_62 ) ;
F_37 ( V_15 , 6 , V_56 -> V_57 . V_58 . V_61 , V_62 ) ;
F_34 ( V_15 , 2 , NULL , V_62 ) ;
V_3 -> V_19 [ 1 ] = V_56 -> V_57 . V_58 . V_59 ;
V_3 -> V_19 [ 2 ] = V_56 -> V_57 . V_58 . V_61 ;
}
static T_4 F_56 ( struct V_14 * V_15 , void * V_63 , T_4 V_64 , int V_9 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
T_4 V_65 = 0 ;
if ( F_38 ( V_15 , V_66 ) )
return 0 ;
for (; V_65 < V_64 ; V_65 ++ ) {
if ( F_34 ( V_15 , 4 , ( char * ) V_63 , V_40 ) )
break;
V_63 ++ ;
if ( V_3 -> V_19 [ 0 ] & 0x01 ) {
F_42 ( V_15 ) ;
break;
}
}
F_38 ( V_15 , V_41 ) ;
return V_65 ;
}
static T_4 F_57 ( struct V_14 * V_15 , const void * V_63 , T_4 V_64 , int V_9 )
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
struct V_2 * V_3 = V_15 -> V_35 ;
struct V_26 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_38 ( V_15 , V_66 ) )
return 0 ;
V_68 = F_58 ( V_5 , F_59 ( V_5 , 1 ) , ( void * ) V_63 , V_64 , & V_67 , 20000 ) ;
if ( V_68 )
F_36 ( V_69 L_10 , V_63 , V_64 , V_67 ) ;
F_38 ( V_15 , V_41 ) ;
return V_67 ;
#endif
}
static T_4 F_60 ( struct V_14 * V_15 , void * V_63 , T_4 V_64 , int V_9 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
T_4 V_65 = 0 ;
if ( F_38 ( V_15 , V_66 ) )
return 0 ;
for (; V_65 < V_64 ; V_65 ++ ) {
if ( F_34 ( V_15 , 3 , ( char * ) V_63 , V_40 ) )
break;
V_63 ++ ;
if ( V_3 -> V_19 [ 0 ] & 0x01 ) {
F_42 ( V_15 ) ;
break;
}
}
F_38 ( V_15 , V_41 ) ;
return V_65 ;
}
static T_4 F_61 ( struct V_14 * V_15 , const void * V_63 , T_4 V_64 , int V_9 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
T_4 V_70 = 0 ;
if ( F_38 ( V_15 , V_66 ) )
return 0 ;
for (; V_70 < V_64 ; V_70 ++ ) {
if ( F_37 ( V_15 , 3 , * ( char * ) V_63 , V_40 ) )
break;
V_63 ++ ;
if ( F_34 ( V_15 , 1 , NULL , V_40 ) )
break;
if ( V_3 -> V_19 [ 0 ] & 0x01 ) {
F_42 ( V_15 ) ;
break;
}
}
F_38 ( V_15 , V_41 ) ;
return V_70 ;
}
static T_4 F_62 ( struct V_14 * V_15 , const void * V_71 , T_4 V_72 , int V_9 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
struct V_26 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_38 ( V_15 , V_48 ) )
return 0 ;
V_68 = F_58 ( V_5 , F_59 ( V_5 , 1 ) , ( void * ) V_71 , V_72 , & V_67 , 20000 ) ;
if ( V_68 )
F_36 ( V_69 L_10 , V_71 , V_72 , V_67 ) ;
F_38 ( V_15 , V_41 ) ;
return V_67 ;
}
static T_4 F_63 ( struct V_14 * V_15 , void * V_71 , T_4 V_72 , int V_9 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
struct V_26 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_38 ( V_15 , V_48 ) )
return 0 ;
V_68 = F_58 ( V_5 , F_64 ( V_5 , 2 ) , V_71 , V_72 , & V_67 , 20000 ) ;
if ( V_68 )
F_36 ( V_69 L_11 , V_71 , V_72 , V_67 ) ;
F_38 ( V_15 , V_41 ) ;
return V_67 ;
}
static T_4 F_65 ( struct V_14 * V_15 , const void * V_71 , T_4 V_72 , int V_9 )
{
T_4 V_70 = 0 ;
if ( F_38 ( V_15 , V_48 ) )
return 0 ;
for (; V_70 < V_72 ; V_70 ++ ) {
if ( F_37 ( V_15 , 5 , * ( char * ) V_71 , V_40 ) )
break;
V_71 ++ ;
}
F_38 ( V_15 , V_41 ) ;
return V_70 ;
}
static T_4 F_66 ( struct V_14 * V_15 , const void * V_71 , T_4 V_72 , int V_9 )
{
struct V_2 * V_3 = V_15 -> V_35 ;
struct V_26 * V_5 = V_3 -> V_5 ;
int V_67 ;
int V_68 ;
if ( ! V_5 )
return 0 ;
if ( F_38 ( V_15 , V_47 ) )
return 0 ;
V_68 = F_58 ( V_5 , F_59 ( V_5 , 1 ) , ( void * ) V_71 , V_72 , & V_67 , 20000 ) ;
if ( V_68 )
F_36 ( V_69 L_10 , V_71 , V_72 , V_67 ) ;
F_38 ( V_15 , V_41 ) ;
return V_67 ;
}
static int F_67 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_26 * V_5 = F_68 ( F_69 ( V_74 ) ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_2 * V_3 ;
struct V_14 * V_15 ;
unsigned char V_19 ;
int V_68 ;
F_3 ( & V_74 -> V_6 , L_12 ,
F_70 ( V_5 -> V_81 . V_82 ) ,
F_70 ( V_5 -> V_81 . V_83 ) ) ;
if ( V_74 -> V_84 != 3 ) {
F_4 ( V_5 ) ;
return - V_85 ;
}
V_68 = F_71 ( V_5 , V_74 -> V_86 -> V_87 . V_88 , 2 ) ;
F_3 ( & V_74 -> V_6 , L_13 , V_68 ) ;
V_78 = V_74 -> V_89 ;
if ( ! ( V_3 = F_18 ( sizeof( struct V_2 ) , V_40 ) ) ) {
F_4 ( V_5 ) ;
return - V_90 ;
}
V_3 -> V_15 = NULL ;
V_3 -> V_5 = V_5 ;
F_19 ( & V_3 -> V_4 ) ;
F_72 ( & V_3 -> V_12 ) ;
F_20 ( & V_3 -> V_13 ) ;
if ( ! ( V_15 = F_73 ( 0 , V_91 , V_92 , & V_93 ) ) ) {
F_36 ( V_37 L_14 ) ;
goto V_94;
}
V_3 -> V_15 = V_15 ;
V_15 -> V_35 = V_3 ;
V_15 -> V_95 = V_96 | V_97 | V_98 | V_99 | V_100 ;
F_37 ( V_15 , 7 , 0x00 , V_40 ) ;
F_37 ( V_15 , 6 , 0x30 , V_40 ) ;
F_37 ( V_15 , 2 , 0x0c , V_40 ) ;
F_34 ( V_15 , 0 , & V_19 , V_40 ) ;
F_3 ( & V_74 -> V_6 , L_15 , V_3 -> V_19 ) ;
V_80 = & V_78 -> V_80 [ 2 ] ;
F_3 ( & V_74 -> V_6 , L_16 ,
V_80 -> V_87 . V_101 , V_80 -> V_87 . V_102 ) ;
F_74 ( V_15 ) ;
F_75 ( V_74 , V_15 ) ;
return 0 ;
V_94:
F_31 ( V_3 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
return - V_85 ;
}
static void F_76 ( struct V_73 * V_74 )
{
struct V_14 * V_15 = F_77 ( V_74 ) ;
struct V_2 * V_3 ;
struct V_26 * V_5 ;
F_3 ( & V_74 -> V_6 , L_17 ) ;
F_75 ( V_74 , NULL ) ;
if ( V_15 ) {
V_3 = V_15 -> V_35 ;
V_5 = V_3 -> V_5 ;
V_3 -> V_5 = NULL ;
V_3 -> V_15 = NULL ;
F_3 ( & V_74 -> V_6 , L_18 ) ;
F_78 ( V_15 ) ;
F_79 ( V_15 ) ;
F_31 ( V_3 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
}
F_3 ( & V_74 -> V_6 , L_19 ) ;
}
static int T_5 F_80 ( void )
{
int V_103 ;
V_103 = F_81 ( & V_104 ) ;
if ( V_103 )
goto V_105;
F_36 (KERN_INFO KBUILD_MODNAME L_20 DRIVER_VERSION L_21
DRIVER_DESC L_22 ) ;
F_36 (KERN_INFO KBUILD_MODNAME L_23
L_24 ) ;
F_36 (KERN_INFO KBUILD_MODNAME L_25
L_26 ) ;
F_36 (KERN_INFO KBUILD_MODNAME L_27
L_28 ) ;
V_105:
return V_103 ;
}
static void T_6 F_82 ( void )
{
F_83 ( & V_104 ) ;
}
