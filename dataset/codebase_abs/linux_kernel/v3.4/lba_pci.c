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
T_1 V_15 = V_3 -> V_16 . V_17 -> V_18 ;
T_1 V_19 = V_3 -> V_16 . V_17 -> V_20 ;
if ( ( V_12 < V_15 ) ||
( V_12 > V_19 ) ||
( ( V_12 - V_15 ) >= V_21 ) ) {
return 0 ;
}
return 1 ;
}
static unsigned int
F_4 ( struct V_14 * V_3 , T_2 V_22 , T_1 V_23 , T_2 V_24 )
{
T_2 V_25 = ~ 0U ;
int error = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
T_2 V_28 = 0 ;
F_5 ( V_3 , V_22 ) ;
F_6 ( V_3 , V_22 ) ;
F_7 ( V_3 , V_3 -> V_16 . V_29 , V_22 , error ) ;
if ( ! error ) {
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
F_8 ( V_3 , V_22 | V_23 ) ;
switch ( V_24 ) {
case 1 : V_25 = ( T_2 ) F_9 ( V_30 + ( V_23 & 3 ) ) ; break;
case 2 : V_25 = ( T_2 ) F_10 ( V_30 + ( V_23 & 2 ) ) ; break;
case 4 : V_25 = F_11 ( V_30 ) ; break;
}
}
F_12 ( V_3 , V_3 -> V_16 . V_29 ) ;
return ( V_25 ) ;
}
static int F_13 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 * V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
{
* V_25 = F_4 ( V_3 , V_22 , V_34 , V_24 ) ;
F_17 ( L_4 , V_38 , V_22 , V_34 , * V_25 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ! F_3 ( V_12 -> V_18 , V_33 , V_3 ) ) {
F_17 ( L_5 , V_38 , V_22 , V_34 ) ;
* V_25 = ~ 0U ;
return ( 0 ) ;
}
F_8 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 : * V_25 = F_9 ( V_30 + ( V_34 & 3 ) ) ; break;
case 2 : * V_25 = F_10 ( V_30 + ( V_34 & 2 ) ) ; break;
case 4 : * V_25 = F_11 ( V_30 ) ; break;
}
F_17 ( L_6 , V_38 , V_22 , V_34 , * V_25 ) ;
return 0 ;
}
static void
F_19 ( struct V_14 * V_3 , T_2 V_22 , T_1 V_23 , T_2 V_25 , T_2 V_24 )
{
int error = 0 ;
T_2 V_26 = 0 ;
T_2 V_27 = 0 ;
T_2 V_28 = 0 ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
F_5 ( V_3 , V_22 ) ;
F_8 ( V_3 , V_22 | V_23 ) ;
switch ( V_24 ) {
case 1 : F_20 ( V_25 , V_30 + ( V_23 & 3 ) ) ; break;
case 2 : F_21 ( V_25 , V_30 + ( V_23 & 2 ) ) ; break;
case 4 : F_22 ( V_25 , V_30 ) ; break;
}
F_7 ( V_3 , V_3 -> V_16 . V_29 , V_22 , error ) ;
F_12 ( V_3 , V_3 -> V_16 . V_29 ) ;
}
static int F_23 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
if ( ! F_18 ( V_3 ) ) {
F_19 ( V_3 , V_22 , V_34 , ( T_2 ) V_25 , V_24 ) ;
F_17 ( L_7 , V_38 , V_22 , V_34 , V_25 ) ;
return 0 ;
}
if ( F_18 ( V_3 ) && ( ! F_3 ( V_12 -> V_18 , V_33 , V_3 ) ) ) {
F_17 ( L_8 , V_38 , V_22 , V_34 , V_25 ) ;
return 1 ;
}
F_17 ( L_9 , V_38 , V_22 , V_34 , V_25 ) ;
F_8 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 : F_20 ( V_25 , V_3 -> V_16 . V_29 + V_31 + ( V_34 & 3 ) ) ;
break;
case 2 : F_21 ( V_25 , V_3 -> V_16 . V_29 + V_31 + ( V_34 & 2 ) ) ;
break;
case 4 : F_22 ( V_25 , V_3 -> V_16 . V_29 + V_31 ) ;
break;
}
V_39 = F_11 ( V_3 -> V_16 . V_29 + V_40 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 * V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
F_25 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 :
* V_25 = F_9 ( V_30 + ( V_34 & 3 ) ) ;
break;
case 2 :
* V_25 = F_10 ( V_30 + ( V_34 & 2 ) ) ;
break;
case 4 :
* V_25 = F_11 ( V_30 ) ; break;
break;
}
F_17 ( L_10 , V_22 , V_34 , * V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_32 * V_12 , unsigned int V_33 , int V_34 , int V_24 , T_2 V_25 )
{
struct V_14 * V_3 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
void T_3 * V_30 = V_3 -> V_16 . V_29 + V_31 ;
T_2 V_36 = ( V_12 -> V_6 == NULL ) ? 0 : V_12 -> V_18 ;
T_2 V_22 = F_16 ( V_36 , V_33 ) ;
if ( ( V_34 > 255 ) || ( V_33 > 255 ) )
return - V_37 ;
F_17 ( L_11 , V_38 , V_22 , V_34 , V_25 ) ;
F_25 ( V_3 , V_22 | V_34 ) ;
switch( V_24 ) {
case 1 :
F_20 ( V_25 , V_30 + ( V_34 & 3 ) ) ;
break;
case 2 :
F_21 ( V_25 , V_30 + ( V_34 & 2 ) ) ;
break;
case 4 :
F_22 ( V_25 , V_30 ) ;
break;
}
V_39 = F_27 ( V_3 -> V_16 . V_29 + V_40 ) ;
return 0 ;
}
static void
F_28 ( void )
{
F_29 ( V_41 L_12 ) ;
}
static unsigned long
F_30 ( struct V_1 * V_42 , struct V_1 * V_43 )
{
unsigned long V_7 = V_43 -> V_7 ;
unsigned long V_8 = V_43 -> V_8 ;
struct V_1 * V_44 = V_42 -> V_10 ;
if ( V_8 <= V_7 || V_7 < V_42 -> V_7 || ! V_44 )
return 0 ;
while ( V_44 && V_44 -> V_8 < V_7 )
V_44 = V_44 -> V_11 ;
if ( ! V_44 ) return 0 ;
if ( V_44 -> V_7 >= V_8 ) return 0 ;
if ( V_44 -> V_7 <= V_7 ) {
V_43 -> V_7 = V_44 -> V_8 + 1 ;
if ( V_44 -> V_8 >= V_8 ) {
return 1 ;
}
}
if ( V_44 -> V_8 < V_8 ) {
V_43 -> V_8 = V_44 -> V_7 - 1 ;
}
F_2 ( V_45 L_13
L_14 ,
V_7 , V_8 ,
( long ) V_43 -> V_7 , ( long ) V_43 -> V_8 ) ;
return 0 ;
}
static void
F_31 ( struct V_32 * V_12 )
{
struct V_46 * V_47 ;
#ifdef F_32
T_4 V_48 ;
#endif
struct V_14 * V_49 = F_14 ( F_15 ( V_12 -> V_35 ) ) ;
F_29 ( L_15 ,
V_12 , V_12 -> V_18 , V_12 -> V_35 -> V_50 ) ;
if ( V_12 -> V_6 ) {
int V_4 ;
F_33 ( V_12 ) ;
for ( V_4 = V_51 ; V_4 < V_52 ; V_4 ++ ) {
F_34 ( V_12 -> V_53 , V_4 ) ;
}
} else {
int V_54 ;
F_29 ( L_16 ,
V_49 -> V_16 . V_55 . V_56 ,
V_49 -> V_16 . V_55 . V_7 , V_49 -> V_16 . V_55 . V_8 ,
V_49 -> V_16 . V_55 . V_9 ) ;
F_29 ( L_16 ,
V_49 -> V_16 . V_57 . V_56 ,
V_49 -> V_16 . V_57 . V_7 , V_49 -> V_16 . V_57 . V_8 ,
V_49 -> V_16 . V_57 . V_9 ) ;
V_54 = F_35 ( & V_58 , & ( V_49 -> V_16 . V_55 ) ) ;
if ( V_54 < 0 ) {
F_1 ( & V_58 , 2 ) ;
F_36 () ;
}
if ( V_49 -> V_16 . V_59 . V_7 ) {
V_54 = F_35 ( & V_60 ,
& ( V_49 -> V_16 . V_59 ) ) ;
if ( V_54 < 0 ) {
F_2 ( L_17
L_18 ,
( long ) V_49 -> V_16 . V_59 . V_7 ,
( long ) V_49 -> V_16 . V_59 . V_8 ) ;
}
}
if ( V_49 -> V_16 . V_57 . V_9 ) {
V_54 = F_35 ( & V_60 , & ( V_49 -> V_16 . V_57 ) ) ;
if ( V_54 < 0 ) {
F_2 ( V_61 L_17
L_19 ,
( long ) V_49 -> V_16 . V_57 . V_7 ,
( long ) V_49 -> V_16 . V_57 . V_8 ) ;
}
}
#ifdef F_37
if ( V_49 -> V_16 . V_62 . V_9 ) {
V_54 = F_35 ( & V_60 , & ( V_49 -> V_16 . V_62 ) ) ;
if ( V_54 < 0 ) {
F_2 ( L_17
L_20 ,
( long ) V_49 -> V_16 . V_62 . V_7 ,
( long ) V_49 -> V_16 . V_62 . V_8 ) ;
F_1 ( & V_60 , 2 ) ;
F_36 () ;
}
}
#endif
}
F_38 (ln, &bus->devices) {
int V_4 ;
struct V_63 * V_64 = F_39 ( V_47 ) ;
F_29 ( L_21 , F_40 ( V_64 ) ) ;
for ( V_4 = 0 ; V_4 < V_51 ; V_4 ++ ) {
struct V_1 * V_65 = & V_64 -> V_1 [ V_4 ] ;
if ( ! V_65 -> V_7 )
continue;
F_34 ( V_64 , V_4 ) ;
}
#ifdef F_32
( void ) F_41 ( V_64 , V_66 , & V_48 ) ;
V_12 -> V_67 &= ~ ( V_48 & V_68 ) ;
#endif
if ( ( V_64 -> V_69 >> 8 ) == V_70 )
continue;
F_42 ( V_49 -> V_71 , V_64 ) ;
}
#ifdef F_32
if ( V_72 ) {
if ( V_12 -> V_6 ) {
T_1 V_73 ;
( void ) F_43 ( V_12 -> V_53 , V_74 , & V_73 ) ;
( void ) F_44 ( V_12 -> V_53 , V_74 , V_73 | V_68 ) ;
} else {
}
V_72 = V_75 ;
}
F_38 (ln, &bus->devices) {
( void ) F_41 ( V_64 , V_76 , & V_48 ) ;
V_48 |= V_77 | V_78 | V_72 ;
( void ) F_45 ( V_64 , V_76 , V_48 ) ;
}
#endif
}
static void
F_46 ( struct V_79 * V_80 , struct V_14 * V_81 )
{
unsigned long V_82 ;
long V_83 ;
long V_48 ;
long V_84 ;
T_5 * V_85 ;
T_5 * V_86 ;
int V_4 ;
V_85 = F_47 ( sizeof( T_5 ) , V_87 ) ;
if ( ! V_85 )
return;
V_86 = F_47 ( sizeof( T_5 ) , V_87 ) ;
if ( ! V_86 ) {
F_48 ( V_85 ) ;
return;
}
V_48 = F_49 ( & V_82 , V_80 -> V_88 , V_80 -> V_89 ,
V_90 , V_85 ) ;
V_84 = V_85 -> V_91 [ 1 ] ;
V_48 |= F_49 ( & V_82 , V_80 -> V_88 , V_80 -> V_89 ,
V_92 , V_86 ) ;
V_83 = V_86 -> V_91 [ 1 ] ;
if ( V_48 != V_93 ) {
F_50 ( L_22 ) ;
}
if ( F_51 ( V_85 -> V_94 ) != V_95 ) {
F_50 ( L_23 ) ;
}
for ( V_4 = 0 ; V_4 < V_84 ; V_4 ++ ) {
struct {
unsigned long type ;
unsigned long V_7 ;
unsigned long V_8 ;
} * V_96 , * V_97 ;
struct V_1 * V_2 ;
V_96 = ( void * ) & ( V_85 -> V_91 [ 2 + V_4 * 3 ] ) ;
V_97 = ( void * ) & ( V_86 -> V_91 [ 2 + V_4 * 3 ] ) ;
switch( V_96 -> type & 0xff ) {
case V_98 :
V_81 -> V_16 . V_99 . V_7 = V_96 -> V_7 ;
V_81 -> V_16 . V_99 . V_8 = V_96 -> V_8 ;
break;
case V_100 :
if ( ! V_81 -> V_16 . V_57 . V_7 ) {
sprintf ( V_81 -> V_16 . V_101 ,
L_24 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_81 -> V_16 . V_102 = V_96 -> V_7 -
V_97 -> V_7 ;
V_2 = & V_81 -> V_16 . V_57 ;
V_2 -> V_56 = V_81 -> V_16 . V_101 ;
} else if ( ! V_81 -> V_16 . V_59 . V_7 ) {
sprintf ( V_81 -> V_16 . V_103 ,
L_25 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_2 = & V_81 -> V_16 . V_59 ;
V_2 -> V_56 = V_81 -> V_16 . V_103 ;
} else {
F_2 (KERN_WARNING MODULE_NAME
L_26 ) ;
break;
}
V_2 -> V_7 = V_96 -> V_7 ;
V_2 -> V_8 = V_96 -> V_8 ;
V_2 -> V_9 = V_104 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_105 :
sprintf ( V_81 -> V_16 . V_106 , L_27 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_2 = & V_81 -> V_16 . V_62 ;
V_2 -> V_56 = V_81 -> V_16 . V_106 ;
V_2 -> V_7 = V_96 -> V_7 ;
V_2 -> V_8 = V_96 -> V_8 ;
V_2 -> V_9 = V_104 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
case V_107 :
F_2 (KERN_WARNING MODULE_NAME
L_28 ,
i, p->start) ;
break;
case V_108 :
V_81 -> V_109 = F_52 ( V_96 -> V_7 , 64 * 1024 * 1024 ) ;
sprintf ( V_81 -> V_16 . V_110 , L_29 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_2 = & V_81 -> V_16 . V_55 ;
V_2 -> V_56 = V_81 -> V_16 . V_110 ;
V_2 -> V_7 = F_53 ( V_81 -> V_16 . V_111 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_112 - 1 ;
V_2 -> V_9 = V_113 ;
V_2 -> V_6 = V_2 -> V_11 = V_2 -> V_10 = NULL ;
break;
default:
F_2 (KERN_WARNING MODULE_NAME
L_30 ,
i, p->type & 0xff ) ;
break;
}
}
F_48 ( V_85 ) ;
F_48 ( V_86 ) ;
}
static void
F_54 ( struct V_79 * V_80 , struct V_14 * V_81 )
{
struct V_1 * V_2 ;
int V_114 ;
V_81 -> V_16 . V_102 = V_115 ;
V_114 = F_11 ( V_81 -> V_16 . V_29 + V_116 ) ;
V_2 = & ( V_81 -> V_16 . V_99 ) ;
V_2 -> V_56 = L_31 ;
V_2 -> V_7 = V_114 & 0xff ;
V_2 -> V_8 = ( V_114 >> 8 ) & 0xff ;
V_2 = & ( V_81 -> V_16 . V_57 ) ;
sprintf ( V_81 -> V_16 . V_101 , L_24 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_2 -> V_56 = V_81 -> V_16 . V_101 ;
#if 1
F_55 ( V_80 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_81 -> V_16 . V_29 + V_117 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_118 ;
V_2 -> V_9 = V_104 ;
V_2 -> V_7 &= V_119 ;
V_2 -> V_7 = F_56 ( F_57 ( V_81 ) , V_2 -> V_7 ) ;
V_118 = ~ F_11 ( V_81 -> V_16 . V_29 + V_120 ) ;
V_118 /= V_121 ;
V_2 -> V_7 += ( V_118 + 1 ) * F_58 ( V_80 -> V_122 . V_7 ) ;
V_2 -> V_8 = V_2 -> V_7 + V_118 ;
} else {
V_2 -> V_8 = V_2 -> V_7 = 0 ;
}
#endif
V_2 = & ( V_81 -> V_16 . V_59 ) ;
sprintf ( V_81 -> V_16 . V_103 , L_25 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_2 -> V_56 = V_81 -> V_16 . V_103 ;
#if 1
F_59 ( V_80 , V_2 ) ;
#else
V_2 -> V_7 = F_11 ( V_81 -> V_16 . V_29 + V_123 ) ;
if ( V_2 -> V_7 & 1 ) {
unsigned long V_118 ;
V_2 -> V_9 = V_104 ;
V_2 -> V_7 &= V_119 ;
V_2 -> V_7 = F_56 ( F_57 ( V_81 ) , V_2 -> V_7 ) ;
V_118 = F_11 ( V_81 -> V_16 . V_29 + V_124 ) ;
V_2 -> V_8 = V_2 -> V_7 + ~ V_118 ;
}
#endif
V_2 = & ( V_81 -> V_16 . V_55 ) ;
sprintf ( V_81 -> V_16 . V_110 , L_29 ,
( int ) V_81 -> V_16 . V_99 . V_7 ) ;
V_2 -> V_56 = V_81 -> V_16 . V_110 ;
V_2 -> V_9 = V_113 ;
V_2 -> V_7 = F_11 ( V_81 -> V_16 . V_29 + V_125 ) & ~ 1L ;
V_2 -> V_8 = V_2 -> V_7 + ( F_11 ( V_81 -> V_16 . V_29 + V_126 ) ^ ( V_112 - 1 ) ) ;
V_114 = F_53 ( V_81 -> V_16 . V_111 ) ;
V_2 -> V_7 |= V_114 ;
V_2 -> V_8 |= V_114 ;
}
static int T_6
F_60 ( struct V_14 * V_3 )
{
T_2 V_127 ;
T_2 V_128 ;
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
V_128 = F_11 ( V_3 -> V_16 . V_29 + V_129 + 4 ) & 1 ;
if ( V_128 ) {
F_2 ( V_5 L_32 ) ;
}
V_127 = F_11 ( V_3 -> V_16 . V_29 + V_130 ) ;
if ( V_127 & V_131 ) {
F_2 ( V_5 L_33 ) ;
V_127 &= ~ V_131 ;
F_22 ( V_127 , V_3 -> V_16 . V_29 + V_130 ) ;
}
V_127 = F_11 ( V_3 -> V_16 . V_29 + V_129 ) ;
F_22 ( V_127 | V_132 , V_3 -> V_16 . V_29 + V_129 ) ;
if ( V_128 )
F_61 ( V_133 ) ;
if ( 0 == F_11 ( V_3 -> V_16 . V_29 + V_134 ) ) {
F_2 ( V_5 L_34 ) ;
F_22 ( 0x3 , V_3 -> V_16 . V_29 + V_134 ) ;
}
return 0 ;
}
static int T_6
F_62 ( struct V_79 * V_64 )
{
struct V_14 * V_81 ;
F_63 ( V_135 ) ;
struct V_32 * V_136 ;
struct V_137 * V_138 ;
T_2 V_139 ;
void * V_140 ;
char * V_141 ;
void T_3 * V_142 = F_52 ( V_64 -> V_122 . V_7 , 4096 ) ;
V_139 = F_11 ( V_142 + V_143 ) ;
if ( F_64 ( V_64 ) ) {
V_139 &= 0xf ;
switch ( V_139 ) {
case 0 : V_141 = L_35 ; break;
case 1 : V_141 = L_36 ; break;
case 2 : V_141 = L_37 ; break;
case 3 : V_141 = L_38 ; break;
case 4 : V_141 = L_39 ; break;
case 5 : V_141 = L_40 ; break;
default: V_141 = L_41 ;
}
F_2 ( V_144 L_42 ,
V_141 , V_139 & 0xf , ( long ) V_64 -> V_122 . V_7 ) ;
if ( V_139 < 2 ) {
F_2 ( V_45 L_43
L_44 ) ;
}
#if 0
if (func_class > 4) {
cfg_ops = &mercury_cfg_ops;
} else
#endif
{
V_138 = & V_145 ;
}
} else if ( F_65 ( V_64 ) || F_66 ( V_64 ) ) {
int V_146 , V_147 ;
V_139 &= 0xff ;
V_146 = V_139 >> 4 , V_147 = V_139 & 0xf ;
F_2 ( V_144 L_45 ,
F_65 ( V_64 ) ? L_46 : L_47 , V_146 ,
V_147 , V_139 , ( long ) V_64 -> V_122 . V_7 ) ;
V_138 = & V_148 ;
} else {
F_2 ( V_61 L_48 ,
( long ) V_64 -> V_122 . V_7 ) ;
return - V_149 ;
}
V_140 = F_67 ( V_64 -> V_122 . V_7 + V_150 ) ;
V_81 = F_47 ( sizeof( struct V_14 ) , V_87 ) ;
if ( ! V_81 ) {
F_2 ( V_61 L_49 ) ;
return ( 1 ) ;
}
V_81 -> V_151 = V_139 ;
V_81 -> V_16 . V_29 = V_142 ;
V_81 -> V_16 . V_64 = V_64 ;
V_81 -> V_71 = V_140 ;
V_81 -> V_16 . V_152 = F_68 ( V_64 ) ;
F_69 ( V_64 , V_81 ) ;
V_153 = & V_154 ;
F_70 ( F_57 ( V_81 ) ) ;
F_71 ( & V_81 -> V_155 ) ;
if ( F_60 ( V_81 ) )
return ( 1 ) ;
if ( F_72 () ) {
V_156 = & V_157 ;
F_46 ( V_64 , V_81 ) ;
} else {
if ( ! V_158 ) {
V_158 = F_52 ( V_159 , 64 * 1024 ) ;
V_156 = & V_160 ;
}
F_54 ( V_64 , V_81 ) ;
}
if ( V_81 -> V_16 . V_99 . V_7 < V_161 )
V_81 -> V_16 . V_99 . V_7 = V_161 ;
if ( F_30 ( & V_60 ,
& ( V_81 -> V_16 . V_57 ) ) ) {
F_2 ( V_45 L_50 ,
( long ) V_81 -> V_16 . V_57 . V_7 ,
( long ) V_81 -> V_16 . V_57 . V_8 ) ;
V_81 -> V_16 . V_57 . V_9 = 0 ;
}
F_73 ( & V_135 , & V_81 -> V_16 . V_55 ,
F_53 ( V_81 -> V_16 . V_111 ) ) ;
if ( V_81 -> V_16 . V_59 . V_7 )
F_73 ( & V_135 , & V_81 -> V_16 . V_59 ,
V_81 -> V_16 . V_102 ) ;
if ( V_81 -> V_16 . V_57 . V_9 )
F_73 ( & V_135 , & V_81 -> V_16 . V_57 ,
V_81 -> V_16 . V_102 ) ;
if ( V_81 -> V_16 . V_62 . V_9 )
F_74 ( & V_135 , & V_81 -> V_16 . V_62 ) ;
V_64 -> V_64 . V_50 = V_81 ;
V_136 = V_81 -> V_16 . V_17 =
F_75 ( & V_64 -> V_64 , V_81 -> V_16 . V_99 . V_7 ,
V_138 , NULL , & V_135 ) ;
if ( ! V_136 ) {
F_76 ( & V_135 ) ;
return 0 ;
}
V_136 -> V_20 = F_77 ( V_136 ) ;
if ( F_72 () ) {
F_78 ( L_51 ) ;
F_79 ( V_136 ) ;
F_78 ( L_52 ) ;
F_80 ( V_136 ) ;
#ifdef F_81
F_78 ( L_53 ) ;
F_1 ( & V_81 -> V_16 . V_55 , 2 ) ;
F_78 ( L_54 ) ;
F_1 ( & V_81 -> V_16 . V_57 , 2 ) ;
#endif
}
F_82 ( V_136 ) ;
if ( V_138 == & V_145 ) {
V_81 -> V_9 |= V_162 ;
}
V_161 = V_136 -> V_20 + 1 ;
F_83 ( V_136 ) ;
return 0 ;
}
void T_6 F_84 ( void )
{
F_85 ( & V_163 ) ;
}
void F_86 ( struct V_79 * V_164 , T_2 V_165 , T_2 V_166 )
{
void T_3 * V_29 = F_52 ( V_164 -> V_122 . V_7 , 4096 ) ;
V_166 <<= 2 ;
F_87 ( ( V_165 & 0x001fffff ) != 0 ) ;
F_87 ( ( V_166 & 0x001fffff ) != 0 ) ;
F_29 ( L_55 , V_38 , V_165 , V_166 ) ;
F_22 ( V_166 , V_29 + V_167 ) ;
F_22 ( V_165 , V_29 + V_168 ) ;
F_88 ( V_29 ) ;
}
