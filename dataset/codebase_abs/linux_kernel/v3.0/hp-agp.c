static int T_1 F_1 ( void )
{
struct V_1 * V_2 = & V_3 ;
F_2 (KERN_INFO PFX L_1 ) ;
V_2 -> V_4 = F_3 ( V_2 -> V_5 + V_6 ) ;
switch ( V_2 -> V_4 ) {
case 0 : V_2 -> V_7 = 12 ; break;
case 1 : V_2 -> V_7 = 13 ; break;
case 2 : V_2 -> V_7 = 14 ; break;
case 3 : V_2 -> V_7 = 16 ; break;
default:
F_2 (KERN_ERR PFX L_2
L_3 , hp->io_tlb_ps) ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
return - V_10 ;
}
V_2 -> V_11 = 1 << V_2 -> V_7 ;
V_2 -> V_12 = V_13 / V_2 -> V_11 ;
V_2 -> V_14 = F_3 ( V_2 -> V_5 + V_15 ) & ~ 0x1 ;
V_2 -> V_16 = V_2 -> V_14 + V_17 - V_18 ;
V_2 -> V_19 = V_18 ;
V_2 -> V_9 = V_2 -> V_19 / V_2 -> V_11 ;
V_2 -> V_20 = F_4 ( F_3 ( V_2 -> V_5 + V_21 ) ) ;
V_2 -> V_8 = & V_2 -> V_20 [ F_5 ( V_2 -> V_16 ) ] ;
if ( V_2 -> V_8 [ 0 ] != V_22 ) {
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
F_2 (KERN_ERR PFX L_4
L_5 ) ;
return - V_10 ;
}
return 0 ;
}
static int T_1
F_6 ( void )
{
struct V_1 * V_2 = & V_3 ;
F_2 (KERN_INFO PFX L_6 ) ;
if ( V_13 >= F_7 ( 64 ) ) {
V_2 -> V_7 = 16 ;
V_2 -> V_4 = 3 ;
} else if ( V_13 >= F_7 ( 16 ) ) {
V_2 -> V_7 = 14 ;
V_2 -> V_4 = 2 ;
} else if ( V_13 >= F_7 ( 8 ) ) {
V_2 -> V_7 = 13 ;
V_2 -> V_4 = 1 ;
} else {
V_2 -> V_7 = 12 ;
V_2 -> V_4 = 0 ;
}
V_2 -> V_11 = 1 << V_2 -> V_7 ;
V_2 -> V_12 = V_13 / V_2 -> V_11 ;
V_2 -> V_14 = V_23 ;
V_2 -> V_19 = V_18 ;
V_2 -> V_16 = V_2 -> V_14 + V_17 - V_2 -> V_19 ;
V_2 -> V_9 = V_2 -> V_19 / V_2 -> V_11 ;
V_2 -> V_24 = ( V_17 / V_2 -> V_11 ) * sizeof( V_25 ) ;
return 0 ;
}
static int T_1
F_8 ( V_25 V_26 )
{
struct V_1 * V_2 = & V_3 ;
V_2 -> V_5 = F_9 ( V_26 , 1024 ) ;
if ( ! V_2 -> V_5 )
return - V_27 ;
V_2 -> V_28 = ( F_3 ( V_2 -> V_5 + V_15 ) & 0x1 ) == 0 ;
if ( V_2 -> V_28 )
return F_6 () ;
return F_1 () ;
}
static int
F_10 ( volatile T_2 T_3 * V_26 , int V_29 )
{
T_4 V_30 ;
T_2 V_31 , V_32 ;
int V_33 = 48 ;
V_30 = F_11 ( V_26 + V_34 ) ;
if ( ! ( V_30 & V_35 ) )
return 0 ;
V_31 = F_12 ( V_26 + V_36 ) ;
while ( V_33 -- && V_31 >= 0x40 ) {
V_31 &= ~ 3 ;
V_32 = F_12 ( V_26 + V_31 + V_37 ) ;
if ( V_32 == 0xff )
break;
if ( V_32 == V_29 )
return V_31 ;
V_31 = F_12 ( V_26 + V_31 + V_38 ) ;
}
return 0 ;
}
static int T_1
F_13 ( V_25 V_26 )
{
struct V_1 * V_2 = & V_3 ;
int V_29 ;
V_2 -> V_39 = F_9 ( V_26 , 256 ) ;
if ( ! V_2 -> V_39 )
return - V_27 ;
V_2 -> V_40 = F_10 ( V_2 -> V_39 , V_41 ) ;
V_29 = F_14 ( V_2 -> V_39 + V_2 -> V_40 ) & 0xff ;
if ( V_29 != V_41 ) {
F_2 (KERN_ERR PFX L_7 ,
cap, hp->lba_cap_offset) ;
F_15 ( V_2 -> V_39 ) ;
return - V_10 ;
}
return 0 ;
}
static int
F_16 ( void )
{
int V_42 ;
V_42 = V_3 . V_19 / F_17 ( 1 ) ;
V_43 [ 0 ] . V_42 = V_42 ;
V_44 -> V_45 = ( void * ) & V_43 [ 0 ] ;
return V_42 ;
}
static int
F_18 ( void )
{
struct V_1 * V_2 = & V_3 ;
V_44 -> V_46 = V_2 -> V_16 ;
V_44 -> V_47 = V_2 -> V_40 ;
V_44 -> V_48 = F_14 ( V_2 -> V_39 + V_2 -> V_40 + V_49 ) ;
if ( V_2 -> V_28 ) {
F_19 ( F_20 ( V_2 -> V_20 ) , V_2 -> V_5 + V_21 ) ;
F_14 ( V_2 -> V_5 + V_21 ) ;
F_19 ( V_2 -> V_4 , V_2 -> V_5 + V_6 ) ;
F_14 ( V_2 -> V_5 + V_6 ) ;
F_19 ( ( unsigned int ) ( ~ ( V_17 - 1 ) ) , V_2 -> V_5 + V_50 ) ;
F_14 ( V_2 -> V_5 + V_50 ) ;
F_19 ( V_2 -> V_14 | 1 , V_2 -> V_5 + V_15 ) ;
F_14 ( V_2 -> V_5 + V_15 ) ;
F_19 ( V_2 -> V_14 | F_21 ( V_17 ) , V_2 -> V_5 + V_51 ) ;
F_14 ( V_2 -> V_5 + V_51 ) ;
}
return 0 ;
}
static void
F_22 ( void )
{
struct V_1 * V_2 = & V_3 ;
if ( V_2 -> V_5 ) {
if ( V_2 -> V_28 ) {
F_23 ( 0 , V_2 -> V_5 + V_15 ) ;
F_3 ( V_2 -> V_5 + V_15 ) ;
}
F_15 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_39 )
F_15 ( V_2 -> V_39 ) ;
}
static void
F_24 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = & V_3 ;
F_23 ( V_2 -> V_16 | F_21 ( V_2 -> V_19 ) , V_2 -> V_5 + V_51 ) ;
F_3 ( V_2 -> V_5 + V_51 ) ;
}
static int
F_25 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = & V_3 ;
int V_56 ;
if ( V_2 -> V_28 ) {
V_2 -> V_20 = ( V_25 * ) F_26 ( V_57 ,
F_27 ( V_2 -> V_24 ) ) ;
if ( ! V_2 -> V_20 ) {
F_2 (KERN_ERR PFX L_8
L_9 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = 0 ;
return - V_27 ;
}
memset ( V_2 -> V_20 , 0 , V_2 -> V_24 ) ;
V_2 -> V_8 = & V_2 -> V_20 [ F_5 ( V_2 -> V_16 ) ] ;
}
for ( V_56 = 0 ; V_56 < V_2 -> V_9 ; V_56 ++ ) {
V_2 -> V_8 [ V_56 ] = ( unsigned long ) V_44 -> V_58 ;
}
return 0 ;
}
static int
F_28 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = & V_3 ;
if ( V_2 -> V_28 )
F_29 ( ( unsigned long ) V_2 -> V_20 ,
F_27 ( V_2 -> V_24 ) ) ;
else
V_2 -> V_8 [ 0 ] = V_22 ;
return 0 ;
}
static int
F_30 ( struct V_52 * V_53 , T_5 V_59 , int type )
{
struct V_1 * V_2 = & V_3 ;
int V_56 , V_60 ;
T_5 V_61 , V_62 ;
int V_63 ;
if ( type != 0 || V_53 -> type != 0 ) {
return - V_64 ;
}
V_62 = V_2 -> V_12 * V_59 ;
V_63 = V_2 -> V_12 * V_53 -> V_65 ;
if ( ( V_62 + V_63 ) > V_2 -> V_9 ) {
return - V_64 ;
}
V_61 = V_62 ;
while ( V_61 < ( V_62 + V_63 ) ) {
if ( V_2 -> V_8 [ V_61 ] ) {
return - V_66 ;
}
V_61 ++ ;
}
if ( ! V_53 -> V_67 ) {
F_31 () ;
V_53 -> V_67 = true ;
}
for ( V_56 = 0 , V_61 = V_62 ; V_56 < V_53 -> V_65 ; V_56 ++ ) {
unsigned long V_68 ;
V_68 = F_32 ( V_53 -> V_69 [ V_56 ] ) ;
for ( V_60 = 0 ;
V_60 < V_2 -> V_12 ;
V_60 ++ , V_61 ++ , V_68 += V_2 -> V_11 ) {
V_2 -> V_8 [ V_61 ] = V_70 | V_68 ;
}
}
V_44 -> V_71 -> V_72 ( V_53 ) ;
return 0 ;
}
static int
F_33 ( struct V_52 * V_53 , T_5 V_59 , int type )
{
struct V_1 * V_2 = & V_3 ;
int V_56 , V_62 , V_63 ;
if ( type != 0 || V_53 -> type != 0 ) {
return - V_64 ;
}
V_62 = V_2 -> V_12 * V_59 ;
V_63 = V_2 -> V_12 * V_53 -> V_65 ;
for ( V_56 = V_62 ; V_56 < V_63 + V_62 ; V_56 ++ ) {
V_2 -> V_8 [ V_56 ] = V_44 -> V_58 ;
}
V_44 -> V_71 -> V_72 ( V_53 ) ;
return 0 ;
}
static unsigned long
F_34 ( struct V_54 * V_55 , T_6 V_73 , int type )
{
return V_70 | V_73 ;
}
static void
F_35 ( struct V_54 * V_55 , T_7 V_48 )
{
struct V_1 * V_2 = & V_3 ;
T_7 V_74 ;
V_74 = F_14 ( V_2 -> V_39 + V_2 -> V_40 + V_49 ) ;
V_74 = F_36 ( V_55 , V_48 , V_74 ) ;
V_74 |= 0x00000100 ;
F_19 ( V_74 , V_2 -> V_39 + V_2 -> V_40 + V_75 ) ;
F_37 ( V_74 , ( V_48 & V_76 ) != 0 ) ;
}
static int T_1
F_38 ( V_25 V_77 , V_25 V_78 )
{
struct V_54 * V_55 ;
int error = 0 ;
error = F_8 ( V_77 ) ;
if ( error )
goto V_79;
error = F_13 ( V_78 ) ;
if ( error )
goto V_79;
V_55 = F_39 () ;
if ( ! V_55 ) {
error = - V_27 ;
goto V_79;
}
V_55 -> V_71 = & V_80 ;
V_81 . V_82 = V_83 ;
V_81 . V_84 = V_85 ;
V_55 -> V_86 = & V_81 ;
error = F_40 ( V_55 ) ;
V_79:
if ( error )
F_22 () ;
return error ;
}
static T_8 T_1
F_41 ( T_9 V_87 , T_7 V_88 , void * V_89 , void * * V_90 )
{
T_9 V_91 , V_92 ;
T_8 V_30 ;
struct V_93 * V_94 ;
V_25 V_78 , V_95 , V_96 ;
int V_97 ;
V_30 = F_42 ( V_87 , & V_78 , & V_96 ) ;
if ( F_43 ( V_30 ) )
return V_98 ;
V_91 = V_87 ;
do {
V_30 = F_44 ( V_91 , & V_94 ) ;
if ( F_45 ( V_30 ) && ( V_94 -> V_99 & V_100 ) ) {
V_97 = ( strcmp ( V_94 -> V_101 . string , L_10 ) == 0 ) ;
F_46 ( V_94 ) ;
if ( V_97 ) {
V_30 = F_42 ( V_91 , & V_95 , & V_96 ) ;
if ( F_45 ( V_30 ) )
break;
else {
F_2 (KERN_ERR PFX L_11
L_12 ) ;
return V_98 ;
}
}
}
V_30 = F_47 ( V_91 , & V_92 ) ;
V_91 = V_92 ;
} while ( F_45 ( V_30 ) );
if ( F_43 ( V_30 ) )
return V_98 ;
if ( F_38 ( V_95 + V_102 , V_78 ) )
return V_98 ;
F_2 (KERN_INFO PFX L_13
L_14 , (char *)context,
sba_hpa + HP_ZX1_IOC_OFFSET, lba_hpa) ;
V_103 = 1 ;
return V_104 ;
}
static int T_1
F_48 ( void )
{
if ( V_105 )
return - V_64 ;
F_49 ( L_15 , F_41 , L_15 , NULL ) ;
if ( V_103 )
return 0 ;
F_49 ( L_16 , F_41 , L_16 , NULL ) ;
if ( V_103 )
return 0 ;
return - V_10 ;
}
static void T_10
F_50 ( void )
{
}
