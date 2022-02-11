static inline T_1 F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
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
memset ( V_28 -> V_32 , 0 , F_15 ( V_28 -> V_32 ) ) ;
memset ( V_28 -> V_33 , 0 , F_15 ( V_28 -> V_33 ) ) ;
V_9 -> V_29 -> V_34 = 0 ;
F_16 () ;
F_9 ( & V_9 -> V_31 -> V_35 , 0 ) ;
F_9 ( & V_9 -> V_31 -> V_36 , V_9 -> V_37 ) ;
F_9 ( & V_9 -> V_31 -> V_38 , ( V_39 << 16 ) | V_39 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_27 * V_40 = V_9 -> V_29 ;
struct V_41 * V_42 = V_40 -> V_42 ;
F_18 ( V_9 -> V_31 ) ;
F_13 ( L_4 ,
F_19 ( struct V_27 , V_34 ) ) ;
F_13 ( L_5 ,
F_19 ( struct V_27 , V_32 ) ) ;
F_13 ( L_6 ,
F_19 ( struct V_27 , V_33 ) ) ;
memset ( V_42 , 0 , 4 * sizeof( struct V_41 ) ) ;
V_42 -> V_43 = F_20 ( 4 ) ;
V_42 -> V_44 = F_20 ( V_45 | V_46 | V_47 ) ;
V_42 -> V_48 = F_21 ( V_9 -> V_37 +
F_19 ( struct V_27 , V_34 ) ) ;
V_42 -> V_49 = F_21 ( 0x02000000 ) ;
V_42 ++ ;
V_42 -> V_43 = F_20 ( V_50 * 4 ) ;
V_42 -> V_44 = F_20 ( V_51 ) ;
V_42 -> V_48 = F_21 ( V_9 -> V_37 +
F_19 ( struct V_27 , V_32 ) ) ;
V_42 ++ ;
V_42 -> V_43 = F_20 ( 4 ) ;
V_42 -> V_44 = F_20 ( V_45 | V_46 | V_47 ) ;
V_42 -> V_48 = F_21 ( V_9 -> V_37 +
F_19 ( struct V_27 , V_34 ) ) ;
V_42 -> V_49 = F_21 ( 0x01000000 ) ;
V_42 ++ ;
V_42 -> V_43 = F_20 ( V_50 * 4 ) ;
V_42 -> V_44 = F_20 ( V_51 | V_52 ) ;
V_42 -> V_48 = F_21 ( V_9 -> V_37 +
F_19 ( struct V_27 , V_33 ) ) ;
V_42 -> V_49 = F_21 ( V_9 -> V_37 ) ;
F_12 ( V_9 , 0 ) ;
}
static void F_22 ( struct V_53 * V_54 )
{
struct V_55 * V_56 =
F_23 ( V_54 , struct V_55 , V_57 . V_54 ) ;
struct V_8 * V_9 = V_56 -> V_9 ;
unsigned int V_1 = F_24 () ;
T_1 V_58 , V_59 ;
T_1 V_60 , V_61 ;
int V_24 , V_62 , V_63 , V_64 , V_26 ;
V_58 = F_25 ( F_26 () ) ;
V_60 = V_58 - V_56 -> V_65 ;
V_56 -> V_65 = V_58 ;
V_59 = F_1 ( V_1 ) ;
V_61 = V_59 - V_56 -> V_66 ;
V_61 = F_27 ( V_61 , V_60 ) ;
V_56 -> V_66 = V_59 ;
V_63 = F_28 ( 9 * ( V_60 - V_61 ) , V_60 ) ;
V_62 = V_1 << 3 ;
V_64 = 0 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
T_2 V_67 = ( V_63 > V_24 ) ? 0xff : 0 ;
V_9 -> V_25 [ V_24 + V_62 ] = V_67 ;
V_64 |= V_67 ;
}
V_56 -> V_68 = ( V_64 == 0 ) ;
V_26 = ( V_9 -> V_1 [ 0 ] . V_68 && V_9 -> V_1 [ 1 ] . V_68 ) ;
if ( V_26 != V_9 -> V_30 ) {
F_29 ( & V_9 -> V_69 ) ;
V_26 = ( V_9 -> V_1 [ 0 ] . V_68 && V_9 -> V_1 [ 1 ] . V_68 ) ;
F_12 ( V_9 , V_26 ) ;
F_30 ( & V_9 -> V_69 ) ;
}
F_31 ( V_1 , & V_56 -> V_57 ,
F_32 ( V_70 ) ) ;
}
static void F_33 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
V_9 -> V_1 [ 0 ] . V_9 = V_9 ;
F_34 ( & V_9 -> V_1 [ 0 ] . V_57 , F_22 ) ;
V_9 -> V_1 [ 1 ] . V_9 = V_9 ;
F_34 ( & V_9 -> V_1 [ 1 ] . V_57 , F_22 ) ;
F_35 (cpu) {
struct V_55 * V_56 ;
if ( V_1 > 1 )
continue;
V_56 = & V_9 -> V_1 [ V_1 ] ;
V_56 -> V_66 = F_1 ( V_1 ) ;
V_56 -> V_65 = F_25 ( F_26 () ) ;
F_31 ( V_1 , & V_9 -> V_1 [ V_1 ] . V_57 ,
F_32 ( V_70 ) ) ;
}
}
static void F_36 ( struct V_8 * V_9 )
{
F_37 ( & V_9 -> V_1 [ 0 ] . V_57 ) ;
F_37 ( & V_9 -> V_1 [ 1 ] . V_57 ) ;
}
static int F_38 ( struct V_8 * V_9 )
{
F_13 ( L_7 ) ;
F_3 ( V_9 ) ;
F_13 ( L_8 ) ;
F_11 ( V_9 ) ;
F_13 ( L_9 ) ;
F_17 ( V_9 ) ;
F_13 ( L_10 ) ;
F_33 ( V_9 ) ;
F_39 ( V_71 L_11 ) ;
return 0 ;
}
static T_3 F_40 ( struct V_8 * V_9 , unsigned int V_72 )
{
int V_73 ;
T_3 V_74 = 0 ;
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ ) {
V_74 >>= 1 ;
V_74 |= ( ( V_9 -> V_25 [ V_73 ] >= 0x80 ) << 15 ) ;
}
return ( V_74 << 17 ) | ( V_74 >> 15 ) ;
}
static T_4 F_41 ( int V_75 , void * V_76 )
{
struct V_8 * V_9 = V_76 ;
struct V_27 * V_40 = V_9 -> V_29 ;
unsigned int V_34 , V_24 ;
T_3 * V_77 ;
( void ) F_10 ( & V_9 -> V_31 -> V_78 ) ;
F_42 () ;
V_34 = V_40 -> V_34 ;
if ( V_34 != 1 && V_34 != 2 ) {
F_39 ( V_79 L_12 ,
V_34 ) ;
if ( ++ V_9 -> V_80 > 3 ) {
F_39 ( V_81 L_13
L_14 ) ;
F_18 ( V_9 -> V_31 ) ;
}
return V_82 ;
}
V_77 = V_34 == 1 ? V_40 -> V_32 : V_40 -> V_33 ;
for ( V_24 = 0 ; V_24 < V_50 ; V_24 ++ )
V_77 [ V_24 ] = F_40 ( V_9 , V_24 ) ;
return V_82 ;
}
static int F_43 ( struct V_83 * V_12 ,
const struct V_84 * V_85 )
{
struct V_86 * V_18 = NULL , * V_87 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_88 V_89 , V_28 ;
int V_90 = - V_91 ;
F_13 ( L_15 ) ;
while ( ( V_18 = F_44 ( V_12 -> V_92 . V_93 . V_94 , V_18 ) ) != NULL )
if ( strcmp ( V_18 -> V_95 , L_16 ) == 0 )
break;
if ( V_18 == NULL ) {
F_13 ( L_17 ) ;
goto V_96;
}
while ( ( V_87 = F_44 ( V_18 , V_87 ) ) != NULL ) {
if ( strcmp ( V_87 -> V_95 , L_18 ) == 0 )
break;
if ( ( strcmp ( V_87 -> V_95 , L_19 ) == 0 ) &&
F_45 ( V_87 , L_20 , NULL ) != NULL )
break;
}
if ( V_87 == NULL ) {
F_13 ( L_21 ) ;
goto V_96;
}
V_9 = F_46 ( sizeof( struct V_8 ) , V_97 ) ;
if ( V_9 == NULL ) {
F_39 ( V_81 L_22 ) ;
V_90 = - V_98 ;
goto V_99;
}
V_9 -> V_12 = V_12 ;
V_9 -> V_18 = V_18 ;
F_47 ( & V_9 -> V_69 ) ;
F_48 ( & V_12 -> V_92 . V_93 , V_9 ) ;
#if 0
if (macio_resource_count(mdev) < 2 || macio_irq_count(mdev) < 2) {
printk(KERN_ERR
"rackmeter: found match but lacks resources: %pOF"
" (%d resources, %d interrupts)\n",
mdev->ofdev.dev.of_node);
rc = -ENXIO;
goto bail_free;
}
if (macio_request_resources(mdev, "rackmeter")) {
printk(KERN_ERR
"rackmeter: failed to request resources: %pOF\n",
mdev->ofdev.dev.of_node);
rc = -EBUSY;
goto bail_free;
}
rm->irq = macio_irq(mdev, 1);
#else
V_9 -> V_75 = F_49 ( V_18 , 1 ) ;
if ( ! V_9 -> V_75 ||
F_50 ( V_18 , 0 , & V_89 ) ||
F_50 ( V_18 , 1 , & V_28 ) ) {
F_39 ( V_81
L_23 ,
V_12 -> V_92 . V_93 . V_94 ) ;
V_90 = - V_100 ;
goto V_101;
}
#endif
F_13 ( L_24 , ( unsigned int ) V_89 . V_102 ) ;
F_13 ( L_25 , ( unsigned int ) V_28 . V_102 ) ;
F_13 ( L_26 , V_9 -> V_75 ) ;
V_9 -> V_25 = ( T_2 * ) F_51 ( V_97 ) ;
if ( V_9 -> V_25 == NULL ) {
F_39 ( V_81
L_27 ) ;
V_90 = - V_98 ;
goto V_99;
}
V_9 -> V_29 = F_52 ( & F_53 ( V_12 ) -> V_93 ,
sizeof( struct V_27 ) ,
& V_9 -> V_37 , V_97 ) ;
if ( V_9 -> V_29 == NULL ) {
F_39 ( V_81
L_28 ) ;
V_90 = - V_98 ;
goto V_103;
}
#if 0
rm->i2s_regs = ioremap(macio_resource_start(mdev, 0), 0x1000);
#else
V_9 -> V_22 = F_54 ( V_89 . V_102 , 0x1000 ) ;
#endif
if ( V_9 -> V_22 == NULL ) {
F_39 ( V_81
L_29 ) ;
V_90 = - V_100 ;
goto V_104;
}
#if 0
rm->dma_regs = ioremap(macio_resource_start(mdev, 1), 0x100);
#else
V_9 -> V_31 = F_54 ( V_28 . V_102 , 0x100 ) ;
#endif
if ( V_9 -> V_31 == NULL ) {
F_39 ( V_81
L_30 ) ;
V_90 = - V_100 ;
goto V_105;
}
V_90 = F_38 ( V_9 ) ;
if ( V_90 ) {
F_39 ( V_81
L_31 ) ;
V_90 = - V_100 ;
goto V_106;
}
V_90 = F_55 ( V_9 -> V_75 , F_41 , 0 , L_32 , V_9 ) ;
if ( V_90 != 0 ) {
F_39 ( V_81
L_33 ) ;
goto V_107;
}
F_56 ( V_87 ) ;
return 0 ;
V_107:
F_18 ( V_9 -> V_31 ) ;
V_106:
F_57 ( V_9 -> V_31 ) ;
V_105:
F_57 ( V_9 -> V_22 ) ;
V_104:
F_58 ( & F_53 ( V_12 ) -> V_93 ,
sizeof( struct V_27 ) ,
V_9 -> V_29 , V_9 -> V_37 ) ;
V_103:
F_59 ( ( unsigned long ) V_9 -> V_25 ) ;
V_99:
#if 0
macio_release_resources(mdev);
#endif
V_101:
F_60 ( V_9 ) ;
V_96:
F_56 ( V_18 ) ;
F_56 ( V_87 ) ;
F_48 ( & V_12 -> V_92 . V_93 , NULL ) ;
return V_90 ;
}
static int F_61 ( struct V_83 * V_12 )
{
struct V_8 * V_9 = F_62 ( & V_12 -> V_92 . V_93 ) ;
F_36 ( V_9 ) ;
F_48 ( & V_12 -> V_92 . V_93 , NULL ) ;
F_18 ( V_9 -> V_31 ) ;
F_63 ( V_9 -> V_75 , V_9 ) ;
F_57 ( V_9 -> V_31 ) ;
F_57 ( V_9 -> V_22 ) ;
F_58 ( & F_53 ( V_12 ) -> V_93 ,
sizeof( struct V_27 ) ,
V_9 -> V_29 , V_9 -> V_37 ) ;
F_59 ( ( unsigned long ) V_9 -> V_25 ) ;
#if 0
macio_release_resources(mdev);
#endif
F_60 ( V_9 ) ;
return 0 ;
}
static int F_64 ( struct V_83 * V_12 )
{
struct V_8 * V_9 = F_62 ( & V_12 -> V_92 . V_93 ) ;
if ( V_9 == NULL )
return - V_91 ;
F_36 ( V_9 ) ;
F_18 ( V_9 -> V_31 ) ;
return 0 ;
}
static int T_5 F_65 ( void )
{
F_13 ( L_34 ) ;
return F_66 ( & V_108 ) ;
}
static void T_6 F_67 ( void )
{
F_13 ( L_35 ) ;
F_68 ( & V_108 ) ;
}
