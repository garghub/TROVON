static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( NULL == V_2 )
return;
F_2 ( V_5 L_1 , V_2 -> V_6 ) ;
for ( V_4 = V_3 ; V_4 ; -- V_4 ) F_2 ( L_2 ) ;
F_2 ( V_5 L_3 , V_2 ,
( long ) V_2 -> V_7 , ( long ) V_2 -> V_8 , V_2 -> V_9 ) ;
F_1 ( V_2 -> V_10 , V_3 + 2 ) ;
F_1 ( V_2 -> V_11 , V_3 ) ;
}
static int F_3 ( T_1 V_12 , T_1 V_13 , struct V_14 * V_3 )
{
T_1 V_15 = V_3 -> V_16 . V_17 -> V_18 . V_7 ;
T_1 V_19 = V_3 -> V_16 . V_17 -> V_18 . V_8 ;
if ( ( V_12 < V_15 ) ||
( V_12 > V_19 ) ||
( ( V_12 - V_15 ) >= V_20 ) ) {
return 0 ;
}
return 1 ;
}
static unsigned int
F_4 ( struct V_14 * V_3 , T_2 V_21 , T_1 V_22 , T_2 V_23 )
{
T_2 V_24 = ~ 0U ;
int error = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
F_5 ( V_3 , V_21 ) ;
F_6 ( V_3 , V_21 ) ;
F_7 ( V_3 , V_3 -> V_16 . V_28 , V_21 , error ) ;
if ( ! error ) {
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
F_8 ( V_3 , V_21 | V_22 ) ;
switch ( V_23 ) {
case 1 : V_24 = ( T_2 ) F_9 ( V_29 + ( V_22 & 3 ) ) ; break;
case 2 : V_24 = ( T_2 ) F_10 ( V_29 + ( V_22 & 2 ) ) ; break;
case 4 : V_24 = F_11 ( V_29 ) ; break;
}
}
F_12 ( V_3 , V_3 -> V_16 . V_28 ) ;
return ( V_24 ) ;
}
static int F_13 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 * V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
{
* V_24 = F_4 ( V_3 , V_21 , V_33 , V_23 ) ;
F_17 ( L_4 , V_37 , V_21 , V_33 , * V_24 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ! F_3 ( V_12 -> V_18 . V_7 , V_32 , V_3 ) ) {
F_17 ( L_5 , V_37 , V_21 , V_33 ) ;
* V_24 = ~ 0U ;
return ( 0 ) ;
}
F_8 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 : * V_24 = F_9 ( V_29 + ( V_33 & 3 ) ) ; break;
case 2 : * V_24 = F_10 ( V_29 + ( V_33 & 2 ) ) ; break;
case 4 : * V_24 = F_11 ( V_29 ) ; break;
}
F_17 ( L_6 , V_37 , V_21 , V_33 , * V_24 ) ;
return 0 ;
}
static void
F_19 ( struct V_14 * V_3 , T_2 V_21 , T_1 V_22 , T_2 V_24 , T_2 V_23 )
{
int error = 0 ;
T_2 V_25 = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
F_5 ( V_3 , V_21 ) ;
F_8 ( V_3 , V_21 | V_22 ) ;
switch ( V_23 ) {
case 1 : F_20 ( V_24 , V_29 + ( V_22 & 3 ) ) ; break;
case 2 : F_21 ( V_24 , V_29 + ( V_22 & 2 ) ) ; break;
case 4 : F_22 ( V_24 , V_29 ) ; break;
}
F_7 ( V_3 , V_3 -> V_16 . V_28 , V_21 , error ) ;
F_12 ( V_3 , V_3 -> V_16 . V_28 ) ;
}
static int F_23 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
if ( ! F_18 ( V_3 ) ) {
F_19 ( V_3 , V_21 , V_33 , ( T_2 ) V_24 , V_23 ) ;
F_17 ( L_7 , V_37 , V_21 , V_33 , V_24 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ( ! F_3 ( V_12 -> V_18 . V_7 , V_32 , V_3 ) ) ) {
F_17 ( L_8 , V_37 , V_21 , V_33 , V_24 ) ;
return 1 ;
}
F_17 ( L_9 , V_37 , V_21 , V_33 , V_24 ) ;
F_8 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 : F_20 ( V_24 , V_3 -> V_16 . V_28 + V_30 + ( V_33 & 3 ) ) ;
break;
case 2 : F_21 ( V_24 , V_3 -> V_16 . V_28 + V_30 + ( V_33 & 2 ) ) ;
break;
case 4 : F_22 ( V_24 , V_3 -> V_16 . V_28 + V_30 ) ;
break;
}
V_38 = F_11 ( V_3 -> V_16 . V_28 + V_39 ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 * V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
F_25 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 :
* V_24 = F_9 ( V_29 + ( V_33 & 3 ) ) ;
break;
case 2 :
* V_24 = F_10 ( V_29 + ( V_33 & 2 ) ) ;
break;
case 4 :
* V_24 = F_11 ( V_29 ) ; break;
break;
}
F_17 ( L_10 , V_21 , V_33 , * V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_12 , unsigned int V_32 , int V_33 , int V_23 , T_2 V_24 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
void T_3 * V_29 = V_3 -> V_16 . V_28 + V_30 ;
T_2 V_35 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 . V_7 ;
T_2 V_21 = F_16 ( V_35 , V_32 ) ;
if ( ( V_33 > 255 ) || ( V_32 > 255 ) )
return - V_36 ;
F_17 ( L_11 , V_37 , V_21 , V_33 , V_24 ) ;
F_25 ( V_3 , V_21 | V_33 ) ;
switch( V_23 ) {
case 1 :
F_20 ( V_24 , V_29 + ( V_33 & 3 ) ) ;
break;
case 2 :
F_21 ( V_24 , V_29 + ( V_33 & 2 ) ) ;
break;
case 4 :
F_22 ( V_24 , V_29 ) ;
break;
}
V_38 = F_27 ( V_3 -> V_16 . V_28 + V_39 ) ;
return 0 ;
}
static void
F_28 ( void )
{
F_29 ( V_40 L_12 ) ;
}
static unsigned long
F_30 ( struct V_1 * V_41 , struct V_1 * V_42 )
{
unsigned long V_7 = V_42 -> V_7 ;
unsigned long V_8 = V_42 -> V_8 ;
struct V_1 * V_43 = V_41 -> V_10 ;
if ( V_8 <= V_7 || V_7 < V_41 -> V_7 || ! V_43 )
return 0 ;
while ( V_43 && V_43 -> V_8 < V_7 )
V_43 = V_43 -> V_11 ;
if ( ! V_43 ) return 0 ;
if ( V_43 -> V_7 >= V_8 ) return 0 ;
if ( V_43 -> V_7 <= V_7 ) {
V_42 -> V_7 = V_43 -> V_8 + 1 ;
if ( V_43 -> V_8 >= V_8 ) {
return 1 ;
}
}
if ( V_43 -> V_8 < V_8 ) {
V_42 -> V_8 = V_43 -> V_7 - 1 ;
}
F_2 ( V_44 L_13
L_14 ,
V_7 , V_8 ,
( long ) V_42 -> V_7 , ( long ) V_42 -> V_8 ) ;
return 0 ;
}
static void
F_31 ( struct V_31 * V_12 )
{
struct V_45 * V_46 ;
#ifdef F_32
T_4 V_47 ;
#endif
struct V_14 * V_48 = F_14 ( F_15 ( V_12 -> V_34 ) ) ;
F_29 ( L_15 ,
V_12 , ( int ) V_12 -> V_18 . V_7 , V_12 -> V_34 -> V_49 ) ;
if ( V_12 -> V_6 ) {
int V_4 ;
F_33 ( V_12 ) ;
for ( V_4 = V_50 ; V_4 < V_51 ; V_4 ++ ) {
F_34 ( V_12 -> V_52 , V_4 ) ;
}
} else {
int V_53 ;
F_29 ( L_16 ,
V_48 -> V_16 . V_54 . V_55 ,
V_48 -> V_16 . V_54 . V_7 , V_48 -> V_16 . V_54 . V_8 ,
V_48 -> V_16 . V_54 . V_9 ) ;
F_29 ( L_16 ,
V_48 -> V_16 . V_56 . V_55 ,
V_48 -> V_16 . V_56 . V_7 , V_48 -> V_16 . V_56 . V_8 ,
V_48 -> V_16 . V_56 . V_9 ) ;
V_53 = F_35 ( & V_57 , & ( V_48 -> V_16 . V_54 ) ) ;
if ( V_53 < 0 ) {
F_1 ( & V_57 , 2 ) ;
F_36 () ;
}
if ( V_48 -> V_16 . V_58 . V_7 ) {
V_53 = F_35 ( & V_59 ,
& ( V_48 -> V_16 . V_58 ) ) ;
if ( V_53 < 0 ) {
F_2 ( L_17
L_18 ,
( long ) V_48 -> V_16 . V_58 . V_7 ,
( long ) V_48 -> V_16 . V_58 . V_8 ) ;
}
}
if ( V_48 -> V_16 . V_56 . V_9 ) {
V_53 = F_35 ( & V_59 , & ( V_48 -> V_16 . V_56 ) ) ;
if ( V_53 < 0 ) {
F_2 ( V_60 L_17
L_19 ,
( long ) V_48 -> V_16 . V_56 . V_7 ,
( long ) V_48 -> V_16 . V_56 . V_8 ) ;
}
}
#ifdef F_37
if ( V_48 -> V_16 . V_61 . V_9 ) {
V_53 = F_35 ( & V_59 , & ( V_48 -> V_16 . V_61 ) ) ;
if ( V_53 < 0 ) {
F_2 ( L_17
L_20 ,
( long ) V_48 -> V_16 . V_61 . V_7 ,
( long ) V_48 -> V_16 . V_61 . V_8 ) ;
F_1 ( & V_59 , 2 ) ;
F_36 () ;
}
}
#endif
}
F_38 (dev, &bus->devices, bus_list) {
int V_4 ;
F_29 ( L_21 , F_39 ( V_46 ) ) ;
for ( V_4 = 0 ; V_4 < V_50 ; V_4 ++ ) {
struct V_1 * V_62 = & V_46 -> V_1 [ V_4 ] ;
if ( ! V_62 -> V_7 )
continue;
F_34 ( V_46 , V_4 ) ;
}
#ifdef F_32
( void ) F_40 ( V_46 , V_63 , & V_47 ) ;
V_12 -> V_64 &= ~ ( V_47 & V_65 ) ;
#endif
if ( ( V_46 -> V_66 >> 8 ) == V_67 )
continue;
F_41 ( V_48 -> V_68 , V_46 ) ;
}
#ifdef F_32
if ( V_69 ) {
if ( V_12 -> V_6 ) {
T_1 V_70 ;
( void ) F_42 ( V_12 -> V_52 , V_71 , & V_70 ) ;
( void ) F_43 ( V_12 -> V_52 , V_71 , V_70 | V_65 ) ;
} else {
}
V_69 = V_72 ;
}
F_38 (dev, &bus->devices, bus_list) {
( void ) F_40 ( V_46 , V_73 , & V_47 ) ;
V_47 |= V_74 | V_75 | V_69 ;
( void ) F_44 ( V_46 , V_73 , V_47 ) ;
}
#endif
}
static void
F_45 ( struct V_76 * V_77 , struct V_14 * V_78 )
{
unsigned long V_79 ;
long V_80 ;
long V_47 ;
long V_81 ;
T_5 * V_82 ;
T_5 * V_83 ;
int V_4 ;
V_82 = F_46 ( sizeof( T_5 ) , V_84 ) ;
if ( ! V_82 )
return;
V_83 = F_46 ( sizeof( T_5 ) , V_84 ) ;
if ( ! V_83 ) {
F_47 ( V_82 ) ;
return;
}
V_47 = F_48 ( & V_79 , V_77 -> V_85 , V_77 -> V_86 ,
V_87 , V_82 ) ;
V_81 = V_82 -> V_88 [ 1 ] ;
V_47 |= F_48 ( & V_79 , V_77 -> V_85 , V_77 -> V_86 ,
V_89 , V_83 ) ;
V_80 = V_83 -> V_88 [ 1 ] ;
if ( V_47 != V_90 ) {
F_49 ( L_22 ) ;
}
if ( F_50 ( V_82 -> V_91 ) != V_92 ) {
F_49 ( L_23 ) ;
}
for ( V_4 = 0 ; V_4 < V_81 ; V_4 ++ ) {
struct {
unsigned long type ;
unsigned long V_7 ;
unsigned long V_8 ;
} * V_93 , * V_94 ;
struct V_1 * V_2 ;
V_93 = ( void * ) & ( V_82 -> V_88 [ 2 + V_4 * 3 ] ) ;
V_94 = ( void * ) & ( V_83 -> V_88 [ 2 + V_4 * 3 ] ) ;
switch( V_93 -> type & 0xff ) {
case V_95 :
V_78 -> V_16 . V_96 . V_7 = V_93 -> V_7 ;
V_78 -> V_16 . V_96 . V_8 = V_93 -> V_8 ;
V_78 -> V_16 . V_96 . V_9 = V_97 ;
break;
case V_98 :
if ( ! V_78 -> V_16 . V_56 . V_7 ) {
sprintf ( V_78 -> V_16 . V_99 ,
L_24 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_78 -> V_16 . V_100 = V_93 -> V_7 -
V_94 -> V_7 ;
V_2 = & V_78 -> V_16 . V_56 ;
V_2 -> V_55 = V_78 -> V_16 . V_99 ;
} else if ( ! V_78 -> V_16 . V_58 . V_7 ) {
sprintf ( V_78 -> V_16 . V_101 ,
L_25 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_2 = & V_78 -> V_16 . V_58 ;
V_2 -> V_55 = V_78 -> V_16 . V_101 ;
} else {
F_2 (KERN_WARNING MODULE_NAME
L_26 ) ;
break;
}
V_2 -> V_7 = V_93 -> V_7 ;
V_2 -> V_8 = V_93 -> V_8 ;
V_2 -> V_9 = V_102 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_103 :
sprintf ( V_78 -> V_16 . V_104 , L_27 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_2 = & V_78 -> V_16 . V_61 ;
V_2 -> V_55 = V_78 -> V_16 . V_104 ;
V_2 -> V_7 = V_93 -> V_7 ;
V_2 -> V_8 = V_93 -> V_8 ;
V_2 -> V_9 = V_102 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_105 :
F_2 (KERN_WARNING MODULE_NAME
L_28 ,
i, p->start) ;
break;
case V_106 :
V_78 -> V_107 = F_51 ( V_93 -> V_7 , 64 * 1024 * 1024 ) ;
sprintf ( V_78 -> V_16 . V_108 , L_29 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_2 = & V_78 -> V_16 . V_54 ;
V_2 -> V_55 = V_78 -> V_16 . V_108 ;
V_2 -> V_7 = F_52 ( V_78 -> V_16 . V_109 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_110 - 1 ;
V_2 -> V_9 = V_111 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
default:
F_2 (KERN_WARNING MODULE_NAME
L_30 ,
i, p->type & 0xff ) ;
break;
}
}
F_47 ( V_82 ) ;
F_47 ( V_83 ) ;
}
static void
F_53 ( struct V_76 * V_77 , struct V_14 * V_78 )
{
struct V_1 * V_2 ;
int V_112 ;
V_78 -> V_16 . V_100 = V_113 ;
V_112 = F_11 ( V_78 -> V_16 . V_28 + V_114 ) ;
V_2 = & ( V_78 -> V_16 . V_96 ) ;
V_2 -> V_55 = L_31 ;
V_2 -> V_7 = V_112 & 0xff ;
V_2 -> V_8 = ( V_112 >> 8 ) & 0xff ;
V_2 = & ( V_78 -> V_16 . V_56 ) ;
sprintf ( V_78 -> V_16 . V_99 , L_24 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_2 -> V_55 = V_78 -> V_16 . V_99 ;
#if 1
F_54 ( V_77 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_78 -> V_16 . V_28 + V_115 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_116 ;
V_2 -> V_9 = V_102 ;
V_2 -> V_7 &= V_117 ;
V_2 -> V_7 = F_55 ( F_56 ( V_78 ) , V_2 -> V_7 ) ;
V_116 = ~ F_11 ( V_78 -> V_16 . V_28 + V_118 ) ;
V_116 /= V_119 ;
V_2 -> V_7 += ( V_116 + 1 ) * F_57 ( V_77 -> V_120 . V_7 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_116 ;
} else {
V_2 -> V_8 = V_2 -> V_7 = 0 ;
}
#endif
V_2 = & ( V_78 -> V_16 . V_58 ) ;
sprintf ( V_78 -> V_16 . V_101 , L_25 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_2 -> V_55 = V_78 -> V_16 . V_101 ;
#if 1
F_58 ( V_77 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_78 -> V_16 . V_28 + V_121 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_116 ;
V_2 -> V_9 = V_102 ;
V_2 -> V_7 &= V_117 ;
V_2 -> V_7 = F_55 ( F_56 ( V_78 ) , V_2 -> V_7 ) ;
V_116 = F_11 ( V_78 -> V_16 . V_28 + V_122 ) ;
V_2 -> V_8 = V_2 -> V_7 + ~ V_116 ;
}
#endif
V_2 = & ( V_78 -> V_16 . V_54 ) ;
sprintf ( V_78 -> V_16 . V_108 , L_29 ,
( int ) V_78 -> V_16 . V_96 . V_7 ) ;
V_2 -> V_55 = V_78 -> V_16 . V_108 ;
V_2 -> V_9 = V_111 ;
V_2 -> V_7 = F_11 ( V_78 -> V_16 . V_28 + V_123 ) & ~ 1L ;
V_2 -> V_8 = V_2 -> V_7 + ( F_11 ( V_78 -> V_16 . V_28 + V_124 ) ^ ( V_110 - 1 ) ) ;
V_112 = F_52 ( V_78 -> V_16 . V_109 ) ;
V_2 -> V_7 |= V_112 ;
V_2 -> V_8 |= V_112 ;
}
static int T_6
F_59 ( struct V_14 * V_3 )
{
T_2 V_125 ;
T_2 V_126 ;
#if 0
printk(KERN_DEBUG "LBA %lx STAT_CTL %Lx ERROR_CFG %Lx STATUS %Lx DMA_CTL %Lx\n",
d->hba.base_addr,
READ_REG64(d->hba.base_addr + LBA_STAT_CTL),
READ_REG64(d->hba.base_addr + LBA_ERROR_CONFIG),
READ_REG64(d->hba.base_addr + LBA_ERROR_STATUS),
READ_REG64(d->hba.base_addr + LBA_DMA_CTL) );
printk(KERN_DEBUG " ARB mask %Lx pri %Lx mode %Lx mtlt %Lx\n",
READ_REG64(d->hba.base_addr + LBA_ARB_MASK),
READ_REG64(d->hba.base_addr + LBA_ARB_PRI),
READ_REG64(d->hba.base_addr + LBA_ARB_MODE),
READ_REG64(d->hba.base_addr + LBA_ARB_MTLT) );
printk(KERN_DEBUG " HINT cfg 0x%Lx\n",
READ_REG64(d->hba.base_addr + LBA_HINT_CFG));
printk(KERN_DEBUG " HINT reg ");
{ int i;
for (i=LBA_HINT_BASE; i< (14*8 + LBA_HINT_BASE); i+=8)
printk(" %Lx", READ_REG64(d->hba.base_addr + i));
}
printk("\n");
#endif
#ifdef F_37
#endif
V_126 = F_11 ( V_3 -> V_16 . V_28 + V_127 + 4 ) & 1 ;
if ( V_126 ) {
F_2 ( V_5 L_32 ) ;
}
V_125 = F_11 ( V_3 -> V_16 . V_28 + V_128 ) ;
if ( V_125 & V_129 ) {
F_2 ( V_5 L_33 ) ;
V_125 &= ~ V_129 ;
F_22 ( V_125 , V_3 -> V_16 . V_28 + V_128 ) ;
}
V_125 = F_11 ( V_3 -> V_16 . V_28 + V_127 ) ;
F_22 ( V_125 | V_130 , V_3 -> V_16 . V_28 + V_127 ) ;
if ( V_126 )
F_60 ( V_131 ) ;
if ( 0 == F_11 ( V_3 -> V_16 . V_28 + V_132 ) ) {
F_2 ( V_5 L_34 ) ;
F_22 ( 0x3 , V_3 -> V_16 . V_28 + V_132 ) ;
}
return 0 ;
}
static int T_6
F_61 ( struct V_76 * V_46 )
{
struct V_14 * V_78 ;
F_62 ( V_133 ) ;
struct V_31 * V_134 ;
struct V_135 * V_136 ;
T_2 V_137 ;
void * V_138 ;
char * V_139 ;
void T_3 * V_140 = F_51 ( V_46 -> V_120 . V_7 , 4096 ) ;
int V_141 ;
V_137 = F_11 ( V_140 + V_142 ) ;
if ( F_63 ( V_46 ) ) {
V_137 &= 0xf ;
switch ( V_137 ) {
case 0 : V_139 = L_35 ; break;
case 1 : V_139 = L_36 ; break;
case 2 : V_139 = L_37 ; break;
case 3 : V_139 = L_38 ; break;
case 4 : V_139 = L_39 ; break;
case 5 : V_139 = L_40 ; break;
default: V_139 = L_41 ;
}
F_2 ( V_143 L_42 ,
V_139 , V_137 & 0xf , ( long ) V_46 -> V_120 . V_7 ) ;
if ( V_137 < 2 ) {
F_2 ( V_44 L_43
L_44 ) ;
}
#if 0
if (func_class > 4) {
cfg_ops = &mercury_cfg_ops;
} else
#endif
{
V_136 = & V_144 ;
}
} else if ( F_64 ( V_46 ) || F_65 ( V_46 ) ) {
int V_145 , V_146 ;
V_137 &= 0xff ;
V_145 = V_137 >> 4 , V_146 = V_137 & 0xf ;
F_2 ( V_143 L_45 ,
F_64 ( V_46 ) ? L_46 : L_47 , V_145 ,
V_146 , V_137 , ( long ) V_46 -> V_120 . V_7 ) ;
V_136 = & V_147 ;
} else {
F_2 ( V_60 L_48 ,
( long ) V_46 -> V_120 . V_7 ) ;
return - V_148 ;
}
V_138 = F_66 ( V_46 -> V_120 . V_7 + V_149 ) ;
V_78 = F_46 ( sizeof( struct V_14 ) , V_84 ) ;
if ( ! V_78 ) {
F_2 ( V_60 L_49 ) ;
return ( 1 ) ;
}
V_78 -> V_150 = V_137 ;
V_78 -> V_16 . V_28 = V_140 ;
V_78 -> V_16 . V_46 = V_46 ;
V_78 -> V_68 = V_138 ;
V_78 -> V_16 . V_151 = F_67 ( V_46 ) ;
F_68 ( V_46 , V_78 ) ;
V_152 = & V_153 ;
F_69 ( F_56 ( V_78 ) ) ;
F_70 ( & V_78 -> V_154 ) ;
if ( F_59 ( V_78 ) )
return ( 1 ) ;
if ( F_71 () ) {
V_155 = & V_156 ;
F_45 ( V_46 , V_78 ) ;
} else {
if ( ! V_157 ) {
V_157 = F_51 ( V_158 , 64 * 1024 ) ;
V_155 = & V_159 ;
}
F_53 ( V_46 , V_78 ) ;
}
if ( V_78 -> V_16 . V_96 . V_7 < V_160 )
V_78 -> V_16 . V_96 . V_7 = V_160 ;
if ( F_30 ( & V_59 ,
& ( V_78 -> V_16 . V_56 ) ) ) {
F_2 ( V_44 L_50 ,
( long ) V_78 -> V_16 . V_56 . V_7 ,
( long ) V_78 -> V_16 . V_56 . V_8 ) ;
V_78 -> V_16 . V_56 . V_9 = 0 ;
}
F_72 ( & V_133 , & V_78 -> V_16 . V_54 ,
F_52 ( V_78 -> V_16 . V_109 ) ) ;
if ( V_78 -> V_16 . V_58 . V_7 )
F_72 ( & V_133 , & V_78 -> V_16 . V_58 ,
V_78 -> V_16 . V_100 ) ;
if ( V_78 -> V_16 . V_56 . V_9 )
F_72 ( & V_133 , & V_78 -> V_16 . V_56 ,
V_78 -> V_16 . V_100 ) ;
if ( V_78 -> V_16 . V_61 . V_9 )
F_73 ( & V_133 , & V_78 -> V_16 . V_61 ) ;
F_73 ( & V_133 , & V_78 -> V_16 . V_96 ) ;
V_46 -> V_46 . V_49 = V_78 ;
V_134 = V_78 -> V_16 . V_17 =
F_74 ( & V_46 -> V_46 , V_78 -> V_16 . V_96 . V_7 ,
V_136 , NULL , & V_133 ) ;
if ( ! V_134 ) {
F_75 ( & V_133 ) ;
return 0 ;
}
V_141 = F_76 ( V_134 ) ;
if ( F_71 () ) {
F_77 ( L_51 ) ;
F_78 ( V_134 ) ;
F_77 ( L_52 ) ;
F_79 ( V_134 ) ;
#ifdef F_80
F_77 ( L_53 ) ;
F_1 ( & V_78 -> V_16 . V_54 , 2 ) ;
F_77 ( L_54 ) ;
F_1 ( & V_78 -> V_16 . V_56 , 2 ) ;
#endif
}
F_81 ( V_134 ) ;
if ( V_136 == & V_144 ) {
V_78 -> V_9 |= V_161 ;
}
V_160 = V_141 + 1 ;
F_82 ( V_134 ) ;
return 0 ;
}
void T_6 F_83 ( void )
{
F_84 ( & V_162 ) ;
}
void F_85 ( struct V_76 * V_163 , T_2 V_164 , T_2 V_165 )
{
void T_3 * V_28 = F_51 ( V_163 -> V_120 . V_7 , 4096 ) ;
V_165 <<= 2 ;
F_86 ( ( V_164 & 0x001fffff ) != 0 ) ;
F_86 ( ( V_165 & 0x001fffff ) != 0 ) ;
F_29 ( L_55 , V_37 , V_164 , V_165 ) ;
F_22 ( V_165 , V_28 + V_166 ) ;
F_22 ( V_164 , V_28 + V_167 ) ;
F_87 ( V_28 ) ;
}
