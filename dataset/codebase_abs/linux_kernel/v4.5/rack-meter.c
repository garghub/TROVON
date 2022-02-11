static inline T_1 F_1 ( unsigned int V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 ) . V_3 [ V_4 ] +
F_2 ( V_1 ) . V_3 [ V_5 ] ;
if ( V_6 )
V_2 += F_2 ( V_1 ) . V_3 [ V_7 ] ;
return V_2 ;
}
static void F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 -> V_13 -> V_14 ;
F_4 ( V_15 , NULL , V_16 , 5 ) ;
F_4 ( V_17 , V_9 -> V_18 , 0 , 1 ) ;
F_5 ( V_19 , V_20 ) ;
F_6 ( V_19 , V_21 ) ;
( void ) F_7 ( V_19 ) ;
F_8 ( 10 ) ;
F_9 ( V_9 -> V_22 + 0x10 , 0x01fa0000 ) ;
( void ) F_10 ( V_9 -> V_22 + 0x10 ) ;
F_8 ( 10 ) ;
F_5 ( V_19 , V_23 |
V_21 ) ;
( void ) F_7 ( V_19 ) ;
F_8 ( 10 ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
if ( V_24 < 8 )
V_9 -> V_25 [ V_24 ] = ( V_24 & 1 ) * 255 ;
else
V_9 -> V_25 [ V_24 ] = ( ( ~ V_24 ) & 1 ) * 255 ;
}
}
static void F_12 ( struct V_8 * V_9 , int V_26 )
{
struct V_27 * V_28 = V_9 -> V_29 ;
F_13 ( L_1 , V_26 ? L_2 : L_3 ) ;
V_9 -> V_30 = V_26 ;
if ( V_26 ) {
F_14 ( V_9 -> V_31 ) ;
return;
}
memset ( V_28 -> V_32 , 0 , V_33 & sizeof( V_34 ) ) ;
memset ( V_28 -> V_35 , 0 , V_33 & sizeof( V_34 ) ) ;
V_9 -> V_29 -> V_36 = 0 ;
F_15 () ;
F_9 ( & V_9 -> V_31 -> V_37 , 0 ) ;
F_9 ( & V_9 -> V_31 -> V_38 , V_9 -> V_39 ) ;
F_9 ( & V_9 -> V_31 -> V_40 , ( V_41 << 16 ) | V_41 ) ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_27 * V_42 = V_9 -> V_29 ;
struct V_43 * V_44 = V_42 -> V_44 ;
F_17 ( V_9 -> V_31 ) ;
F_13 ( L_4 ,
F_18 ( struct V_27 , V_36 ) ) ;
F_13 ( L_5 ,
F_18 ( struct V_27 , V_32 ) ) ;
F_13 ( L_6 ,
F_18 ( struct V_27 , V_35 ) ) ;
memset ( V_44 , 0 , 4 * sizeof( struct V_43 ) ) ;
V_44 -> V_45 = F_19 ( 4 ) ;
V_44 -> V_46 = F_19 ( V_47 | V_48 | V_49 ) ;
V_44 -> V_50 = F_20 ( V_9 -> V_39 +
F_18 ( struct V_27 , V_36 ) ) ;
V_44 -> V_51 = F_20 ( 0x02000000 ) ;
V_44 ++ ;
V_44 -> V_45 = F_19 ( V_33 * 4 ) ;
V_44 -> V_46 = F_19 ( V_52 ) ;
V_44 -> V_50 = F_20 ( V_9 -> V_39 +
F_18 ( struct V_27 , V_32 ) ) ;
V_44 ++ ;
V_44 -> V_45 = F_19 ( 4 ) ;
V_44 -> V_46 = F_19 ( V_47 | V_48 | V_49 ) ;
V_44 -> V_50 = F_20 ( V_9 -> V_39 +
F_18 ( struct V_27 , V_36 ) ) ;
V_44 -> V_51 = F_20 ( 0x01000000 ) ;
V_44 ++ ;
V_44 -> V_45 = F_19 ( V_33 * 4 ) ;
V_44 -> V_46 = F_19 ( V_52 | V_53 ) ;
V_44 -> V_50 = F_20 ( V_9 -> V_39 +
F_18 ( struct V_27 , V_35 ) ) ;
V_44 -> V_51 = F_20 ( V_9 -> V_39 ) ;
F_12 ( V_9 , 0 ) ;
}
static void F_21 ( struct V_54 * V_55 )
{
struct V_56 * V_57 =
F_22 ( V_55 , struct V_56 , V_58 . V_55 ) ;
struct V_8 * V_9 = V_57 -> V_9 ;
unsigned int V_1 = F_23 () ;
T_1 V_59 , V_60 ;
unsigned int V_61 , V_62 ;
int V_24 , V_63 , V_64 , V_65 , V_26 ;
V_59 = F_24 ( F_25 () ) ;
V_61 = ( unsigned int ) ( V_59 - V_57 -> V_66 ) ;
V_57 -> V_66 = V_59 ;
V_60 = F_1 ( V_1 ) ;
V_62 = ( unsigned int ) ( V_60 - V_57 -> V_67 ) ;
V_57 -> V_67 = V_60 ;
V_64 = ( 9 * ( V_61 - V_62 ) ) / V_61 ;
V_63 = V_1 << 3 ;
V_65 = 0 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
T_3 V_68 = ( V_64 > V_24 ) ? 0xff : 0 ;
V_9 -> V_25 [ V_24 + V_63 ] = V_68 ;
V_65 |= V_68 ;
}
V_57 -> V_69 = ( V_65 == 0 ) ;
V_26 = ( V_9 -> V_1 [ 0 ] . V_69 && V_9 -> V_1 [ 1 ] . V_69 ) ;
if ( V_26 != V_9 -> V_30 ) {
F_26 ( & V_9 -> V_70 ) ;
V_26 = ( V_9 -> V_1 [ 0 ] . V_69 && V_9 -> V_1 [ 1 ] . V_69 ) ;
F_12 ( V_9 , V_26 ) ;
F_27 ( & V_9 -> V_70 ) ;
}
F_28 ( V_1 , & V_57 -> V_58 ,
F_29 ( V_71 ) ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
V_9 -> V_1 [ 0 ] . V_9 = V_9 ;
F_31 ( & V_9 -> V_1 [ 0 ] . V_58 , F_21 ) ;
V_9 -> V_1 [ 1 ] . V_9 = V_9 ;
F_31 ( & V_9 -> V_1 [ 1 ] . V_58 , F_21 ) ;
F_32 (cpu) {
struct V_56 * V_57 ;
if ( V_1 > 1 )
continue;
V_57 = & V_9 -> V_1 [ V_1 ] ;
V_57 -> V_67 = F_1 ( V_1 ) ;
V_57 -> V_66 = F_24 ( F_25 () ) ;
F_28 ( V_1 , & V_9 -> V_1 [ V_1 ] . V_58 ,
F_29 ( V_71 ) ) ;
}
}
static void F_33 ( struct V_8 * V_9 )
{
F_34 ( & V_9 -> V_1 [ 0 ] . V_58 ) ;
F_34 ( & V_9 -> V_1 [ 1 ] . V_58 ) ;
}
static int F_35 ( struct V_8 * V_9 )
{
F_13 ( L_7 ) ;
F_3 ( V_9 ) ;
F_13 ( L_8 ) ;
F_11 ( V_9 ) ;
F_13 ( L_9 ) ;
F_16 ( V_9 ) ;
F_13 ( L_10 ) ;
F_30 ( V_9 ) ;
F_36 ( V_72 L_11 ) ;
return 0 ;
}
static V_34 F_37 ( struct V_8 * V_9 , unsigned int V_73 )
{
int V_74 ;
V_34 V_75 = 0 ;
for ( V_74 = 0 ; V_74 < 16 ; V_74 ++ ) {
V_75 >>= 1 ;
V_75 |= ( ( V_9 -> V_25 [ V_74 ] >= 0x80 ) << 15 ) ;
}
return ( V_75 << 17 ) | ( V_75 >> 15 ) ;
}
static T_4 F_38 ( int V_76 , void * V_77 )
{
struct V_8 * V_9 = V_77 ;
struct V_27 * V_42 = V_9 -> V_29 ;
unsigned int V_36 , V_24 ;
V_34 * V_78 ;
( void ) F_10 ( & V_9 -> V_31 -> V_79 ) ;
F_39 () ;
V_36 = V_42 -> V_36 ;
if ( V_36 != 1 && V_36 != 2 ) {
F_36 ( V_80 L_12 ,
V_36 ) ;
if ( ++ V_9 -> V_81 > 3 ) {
F_36 ( V_82 L_13
L_14 ) ;
F_17 ( V_9 -> V_31 ) ;
}
return V_83 ;
}
V_78 = V_36 == 1 ? V_42 -> V_32 : V_42 -> V_35 ;
for ( V_24 = 0 ; V_24 < V_33 ; V_24 ++ )
V_78 [ V_24 ] = F_37 ( V_9 , V_24 ) ;
return V_83 ;
}
static int F_40 ( struct V_84 * V_12 ,
const struct V_85 * V_86 )
{
struct V_87 * V_18 = NULL , * V_88 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_89 V_90 , V_28 ;
int V_91 = - V_92 ;
F_13 ( L_15 ) ;
while ( ( V_18 = F_41 ( V_12 -> V_93 . V_94 . V_95 , V_18 ) ) != NULL )
if ( strcmp ( V_18 -> V_96 , L_16 ) == 0 )
break;
if ( V_18 == NULL ) {
F_13 ( L_17 ) ;
goto V_97;
}
while ( ( V_88 = F_41 ( V_18 , V_88 ) ) != NULL ) {
if ( strcmp ( V_88 -> V_96 , L_18 ) == 0 )
break;
if ( ( strcmp ( V_88 -> V_96 , L_19 ) == 0 ) &&
F_42 ( V_88 , L_20 , NULL ) != NULL )
break;
}
if ( V_88 == NULL ) {
F_13 ( L_21 ) ;
goto V_97;
}
V_9 = F_43 ( sizeof( struct V_8 ) , V_98 ) ;
if ( V_9 == NULL ) {
F_36 ( V_82 L_22 ) ;
V_91 = - V_99 ;
goto V_100;
}
V_9 -> V_12 = V_12 ;
V_9 -> V_18 = V_18 ;
F_44 ( & V_9 -> V_70 ) ;
F_45 ( & V_12 -> V_93 . V_94 , V_9 ) ;
#if 0
if (macio_resource_count(mdev) < 2 || macio_irq_count(mdev) < 2) {
printk(KERN_ERR
"rackmeter: found match but lacks resources: %s"
" (%d resources, %d interrupts)\n",
mdev->ofdev.node->full_name);
rc = -ENXIO;
goto bail_free;
}
if (macio_request_resources(mdev, "rackmeter")) {
printk(KERN_ERR
"rackmeter: failed to request resources: %s\n",
mdev->ofdev.node->full_name);
rc = -EBUSY;
goto bail_free;
}
rm->irq = macio_irq(mdev, 1);
#else
V_9 -> V_76 = F_46 ( V_18 , 1 ) ;
if ( V_9 -> V_76 == V_101 ||
F_47 ( V_18 , 0 , & V_90 ) ||
F_47 ( V_18 , 1 , & V_28 ) ) {
F_36 ( V_82
L_23 ,
V_12 -> V_93 . V_94 . V_95 -> V_102 ) ;
V_91 = - V_103 ;
goto V_104;
}
#endif
F_13 ( L_24 , ( unsigned int ) V_90 . V_105 ) ;
F_13 ( L_25 , ( unsigned int ) V_28 . V_105 ) ;
F_13 ( L_26 , V_9 -> V_76 ) ;
V_9 -> V_25 = ( T_3 * ) F_48 ( V_98 ) ;
if ( V_9 -> V_25 == NULL ) {
F_36 ( V_82
L_27 ) ;
V_91 = - V_99 ;
goto V_100;
}
V_9 -> V_29 = F_49 ( & F_50 ( V_12 ) -> V_94 ,
sizeof( struct V_27 ) ,
& V_9 -> V_39 , V_98 ) ;
if ( V_9 -> V_29 == NULL ) {
F_36 ( V_82
L_28 ) ;
V_91 = - V_99 ;
goto V_106;
}
#if 0
rm->i2s_regs = ioremap(macio_resource_start(mdev, 0), 0x1000);
#else
V_9 -> V_22 = F_51 ( V_90 . V_105 , 0x1000 ) ;
#endif
if ( V_9 -> V_22 == NULL ) {
F_36 ( V_82
L_29 ) ;
V_91 = - V_103 ;
goto V_107;
}
#if 0
rm->dma_regs = ioremap(macio_resource_start(mdev, 1), 0x100);
#else
V_9 -> V_31 = F_51 ( V_28 . V_105 , 0x100 ) ;
#endif
if ( V_9 -> V_31 == NULL ) {
F_36 ( V_82
L_30 ) ;
V_91 = - V_103 ;
goto V_108;
}
V_91 = F_35 ( V_9 ) ;
if ( V_91 ) {
F_36 ( V_82
L_31 ) ;
V_91 = - V_103 ;
goto V_109;
}
V_91 = F_52 ( V_9 -> V_76 , F_38 , 0 , L_32 , V_9 ) ;
if ( V_91 != 0 ) {
F_36 ( V_82
L_33 ) ;
goto V_110;
}
F_53 ( V_88 ) ;
return 0 ;
V_110:
F_17 ( V_9 -> V_31 ) ;
V_109:
F_54 ( V_9 -> V_31 ) ;
V_108:
F_54 ( V_9 -> V_22 ) ;
V_107:
F_55 ( & F_50 ( V_12 ) -> V_94 ,
sizeof( struct V_27 ) ,
V_9 -> V_29 , V_9 -> V_39 ) ;
V_106:
F_56 ( ( unsigned long ) V_9 -> V_25 ) ;
V_100:
#if 0
macio_release_resources(mdev);
#endif
V_104:
F_57 ( V_9 ) ;
V_97:
F_53 ( V_18 ) ;
F_53 ( V_88 ) ;
F_45 ( & V_12 -> V_93 . V_94 , NULL ) ;
return V_91 ;
}
static int F_58 ( struct V_84 * V_12 )
{
struct V_8 * V_9 = F_59 ( & V_12 -> V_93 . V_94 ) ;
F_33 ( V_9 ) ;
F_45 ( & V_12 -> V_93 . V_94 , NULL ) ;
F_17 ( V_9 -> V_31 ) ;
F_60 ( V_9 -> V_76 , V_9 ) ;
F_54 ( V_9 -> V_31 ) ;
F_54 ( V_9 -> V_22 ) ;
F_55 ( & F_50 ( V_12 ) -> V_94 ,
sizeof( struct V_27 ) ,
V_9 -> V_29 , V_9 -> V_39 ) ;
F_56 ( ( unsigned long ) V_9 -> V_25 ) ;
#if 0
macio_release_resources(mdev);
#endif
F_57 ( V_9 ) ;
return 0 ;
}
static int F_61 ( struct V_84 * V_12 )
{
struct V_8 * V_9 = F_59 ( & V_12 -> V_93 . V_94 ) ;
if ( V_9 == NULL )
return - V_92 ;
F_33 ( V_9 ) ;
F_17 ( V_9 -> V_31 ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
F_13 ( L_34 ) ;
return F_63 ( & V_111 ) ;
}
static void T_6 F_64 ( void )
{
F_13 ( L_35 ) ;
F_65 ( & V_111 ) ;
}
