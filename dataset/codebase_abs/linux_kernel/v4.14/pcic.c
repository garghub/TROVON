static int F_1 ( unsigned int V_1 , unsigned int V_2 ,
int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
V_6 = & V_8 ;
F_2 ( V_7 ) ;
#if 0
pcic_speculative = 1;
pcic_trapped = 0;
#endif
F_3 ( F_4 ( V_1 , V_2 , V_3 ) , V_6 -> V_9 ) ;
#if 0
nop();
if (pcic_trapped) {
local_irq_restore(flags);
*value = ~0;
return 0;
}
#endif
V_10 = 2 ;
V_11 = 0 ;
* V_4 = F_5 ( V_6 -> V_12 + ( V_3 & 4 ) ) ;
F_6 () ;
if ( V_11 ) {
V_10 = 0 ;
F_7 ( V_7 ) ;
* V_4 = ~ 0 ;
return 0 ;
}
V_10 = 0 ;
F_7 ( V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 , unsigned int V_2 ,
int V_3 , int V_15 , T_1 * V_16 )
{
unsigned int V_17 ;
if ( V_14 -> V_18 != 0 ) return - V_19 ;
switch ( V_15 ) {
case 1 :
F_1 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , & V_17 ) ;
* V_16 = 0xff & ( V_17 >> ( 8 * ( V_3 & 3 ) ) ) ;
return 0 ;
case 2 :
if ( V_3 & 1 ) return - V_19 ;
F_1 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , & V_17 ) ;
* V_16 = 0xffff & ( V_17 >> ( 8 * ( V_3 & 3 ) ) ) ;
return 0 ;
case 4 :
if ( V_3 & 3 ) return - V_19 ;
F_1 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , V_16 ) ;
return 0 ;
}
return - V_19 ;
}
static int F_9 ( unsigned int V_1 , unsigned int V_2 ,
int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
V_6 = & V_8 ;
F_2 ( V_7 ) ;
F_3 ( F_4 ( V_1 , V_2 , V_3 ) , V_6 -> V_9 ) ;
F_3 ( V_4 , V_6 -> V_12 + ( V_3 & 4 ) ) ;
F_7 ( V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , unsigned int V_2 ,
int V_3 , int V_15 , T_1 V_16 )
{
unsigned int V_17 ;
if ( V_14 -> V_18 != 0 ) return - V_19 ;
switch ( V_15 ) {
case 1 :
F_1 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , & V_17 ) ;
V_17 = ( V_17 & ~ ( 0xff << ( 8 * ( V_3 & 3 ) ) ) ) |
( ( 0xff & V_16 ) << ( 8 * ( V_3 & 3 ) ) ) ;
return F_9 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , V_17 ) ;
case 2 :
if ( V_3 & 1 ) return - V_19 ;
F_1 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , & V_17 ) ;
V_17 = ( V_17 & ~ ( 0xffff << ( 8 * ( V_3 & 3 ) ) ) ) |
( ( 0xffff & V_16 ) << ( 8 * ( V_3 & 3 ) ) ) ;
return F_9 ( V_14 -> V_18 , V_2 , V_3 & ~ 3 , V_17 ) ;
case 4 :
if ( V_3 & 3 ) return - V_19 ;
return F_9 ( V_14 -> V_18 , V_2 , V_3 , V_16 ) ;
}
return - V_19 ;
}
int T_2 F_11 ( void )
{
struct V_5 * V_6 ;
struct V_20 V_21 [ V_22 ] ;
struct V_23 * V_24 ;
char V_25 [ 64 ] ;
T_3 V_26 ;
int V_27 ;
if ( V_28 ) {
F_12 ( L_1 ) ;
F_13 () ;
}
V_6 = & V_8 ;
V_26 = F_14 ( V_29 ) ;
V_26 = F_15 ( V_26 , L_2 ) ;
if ( V_26 == 0 )
return - V_30 ;
V_27 = F_16 ( V_26 , L_3 , ( char * ) V_21 , sizeof( V_21 ) ) ;
if ( V_27 == 0 || V_27 == - 1 ) {
F_12 ( L_4
L_5 ) ;
F_13 () ;
}
V_28 = 1 ;
V_6 -> V_31 . V_32 = L_6 ;
V_6 -> V_33 = F_17 ( V_21 [ 0 ] . V_34 , V_21 [ 0 ] . V_35 ) ;
if ( ! V_6 -> V_33 ) {
F_12 ( L_7 ) ;
F_13 () ;
}
V_6 -> V_36 . V_32 = L_8 ;
if ( ( V_6 -> V_37 = ( unsigned long )
F_17 ( V_21 [ 1 ] . V_34 , 0x10000 ) ) == 0 ) {
F_12 ( L_9 ) ;
F_13 () ;
}
V_6 -> V_38 . V_32 = L_10 ;
if ( ( V_6 -> V_9 =
F_17 ( V_21 [ 2 ] . V_34 , V_21 [ 2 ] . V_35 * 2 ) ) == NULL ) {
F_12 ( L_11
L_12 ) ;
F_13 () ;
}
V_6 -> V_39 . V_32 = L_13 ;
if ( ( V_6 -> V_12 =
F_17 ( V_21 [ 3 ] . V_34 , V_21 [ 3 ] . V_35 * 2 ) ) == NULL ) {
F_12 ( L_11
L_14 ) ;
F_13 () ;
}
V_24 = & V_6 -> V_24 ;
V_24 -> V_40 = V_26 ;
F_18 ( V_26 , L_15 , V_25 , 63 ) ; V_25 [ 63 ] = 0 ;
strcpy ( V_24 -> V_41 , V_25 ) ;
{
extern int V_42 [ 4 ] ;
V_43 [ 0 ] = V_42 [ 0 ] ;
V_43 [ 1 ] = V_42 [ 1 ] ;
V_43 [ 2 ] = V_42 [ 2 ] ;
V_43 [ 3 ] = V_42 [ 3 ] ;
F_19 () ;
V_33 = V_6 -> V_33 ;
}
F_18 ( V_29 , L_15 , V_25 , 63 ) ; V_25 [ 63 ] = 0 ;
{
struct V_44 * V_45 ;
for ( V_45 = V_46 ; V_45 -> V_47 != NULL ; V_45 ++ ) {
if ( strcmp ( V_25 , V_45 -> V_47 ) == 0 )
break;
}
V_6 -> V_48 = V_45 -> V_49 ;
V_6 -> V_50 = V_45 -> V_51 ;
}
if ( V_6 -> V_48 == NULL ) {
F_20 ( L_16 ,
V_25 ) ;
}
return 0 ;
}
static void T_2 F_21 ( struct V_5 * V_6 )
{
struct V_23 * V_24 = & V_6 -> V_24 ;
V_24 -> V_13 = F_22 ( V_24 -> V_52 , & V_53 , V_24 ) ;
if ( ! V_24 -> V_13 )
return;
#if 0
pci_fill_in_pbm_cookies(pbm->pci_bus, pbm, pbm->prom_node);
pci_record_assignments(pbm, pbm->pci_bus);
pci_assign_unassigned(pbm, pbm->pci_bus);
pci_fixup_irq(pbm, pbm->pci_bus);
#endif
F_23 ( V_24 -> V_13 ) ;
}
static int T_2 F_24 ( void )
{
struct V_5 * V_6 ;
if( ! V_28 )
return 0 ;
V_6 = & V_8 ;
F_25 ( V_54 ,
V_6 -> V_33 + V_55 ) ;
F_3 ( 0xF0000000UL , V_6 -> V_33 + V_56 ) ;
F_3 ( 0 + V_57 ,
V_6 -> V_33 + V_58 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
int F_26 ( void )
{
return V_28 ;
}
static int F_27 ( struct V_23 * V_24 , struct V_59 * V_60 )
{
struct V_61 V_21 [ V_22 ] ;
int V_27 ;
T_3 V_26 = F_14 ( V_24 -> V_40 ) ;
while( V_26 ) {
V_27 = F_16 ( V_26 , L_3 ,
( char * ) & V_21 [ 0 ] , sizeof( V_21 ) ) ;
if( V_27 != 0 && V_27 != - 1 ) {
unsigned long V_2 = ( V_21 [ 0 ] . V_62 >> 8 ) & 0xff ;
if( V_2 == V_60 -> V_2 )
return V_26 ;
}
V_26 = F_28 ( V_26 ) ;
}
return 0 ;
}
static inline struct V_63 * F_29 ( void )
{
return F_30 ( sizeof( struct V_63 ) , V_64 ) ;
}
static void F_31 ( struct V_5 * V_6 ,
struct V_59 * V_65 , int V_26 )
{
char V_25 [ 64 ] ;
unsigned long V_66 ;
unsigned long V_7 ;
int V_67 ;
if ( V_26 == 0 || V_26 == - 1 ) {
strcpy ( V_25 , L_17 ) ;
} else {
F_18 ( V_26 , L_15 , V_25 , 63 ) ; V_25 [ 63 ] = 0 ;
}
for ( V_67 = 0 ; V_67 < 6 ; V_67 ++ ) {
V_66 = V_65 -> V_68 [ V_67 ] . V_69 ;
if ( V_66 == 0 ) break;
V_7 = V_65 -> V_68 [ V_67 ] . V_7 ;
if ( ( V_7 & V_70 ) != 0 ) {
if ( V_66 < 0x10000 ) {
V_65 -> V_68 [ V_67 ] . V_69 =
V_6 -> V_37 + V_66 ;
V_65 -> V_68 [ V_67 ] . V_71 = 1 ;
V_65 -> V_68 [ V_67 ] . V_7 =
( V_7 & ~ V_70 ) | V_72 ;
} else {
F_20 ( L_18
L_19
L_20 , V_66 ,
V_25 , V_65 -> V_14 -> V_18 , V_65 -> V_2 ) ;
}
}
}
}
static void
F_32 ( struct V_5 * V_6 , struct V_59 * V_65 , int V_26 )
{
struct V_73 * V_45 ;
unsigned int V_74 ;
int V_75 , V_76 ;
char V_25 [ 64 ] ;
if ( V_26 == 0 || V_26 == - 1 ) {
strcpy ( V_25 , L_17 ) ;
} else {
F_18 ( V_26 , L_15 , V_25 , sizeof( V_25 ) ) ;
}
if ( ( V_45 = V_6 -> V_48 ) == NULL ) {
V_65 -> V_77 = 0 ;
return;
}
for ( V_75 = 0 ; V_75 < V_6 -> V_50 ; V_75 ++ ) {
if ( V_45 -> V_1 == V_65 -> V_14 -> V_18 && V_45 -> V_2 == V_65 -> V_2 )
break;
V_45 ++ ;
}
if ( V_75 >= V_6 -> V_50 ) {
F_20 ( L_21 ,
V_25 , V_65 -> V_14 -> V_18 , V_65 -> V_2 , V_6 -> V_50 ) ;
V_65 -> V_77 = 0 ;
return;
}
V_75 = V_45 -> V_78 ;
if ( V_75 >= 0 && V_75 < 4 ) {
V_76 = F_33 ( V_6 -> V_33 + V_79 ) ;
V_74 = V_76 >> ( V_75 << 2 ) & 0xF ;
} else if ( V_75 >= 4 && V_75 < 8 ) {
V_76 = F_33 ( V_6 -> V_33 + V_80 ) ;
V_74 = V_76 >> ( ( V_75 - 4 ) << 2 ) & 0xF ;
} else {
F_20 ( L_22 , V_75 ) ; for (; ; ) {}
}
if ( V_74 == 0 || V_45 -> V_81 ) {
if ( V_45 -> V_77 == 0 || V_45 -> V_77 >= 15 ) {
F_20 ( L_23 , V_45 -> V_77 ) ; for (; ; ) {}
}
F_20 ( L_24 ,
V_45 -> V_77 , V_45 -> V_78 , V_65 -> V_14 -> V_18 , V_65 -> V_2 ) ;
V_74 = V_45 -> V_77 ;
V_75 = V_45 -> V_78 ;
if ( V_75 >= 4 ) {
V_76 = F_33 ( V_6 -> V_33 + V_80 ) ;
V_76 &= ~ ( 0xF << ( ( V_75 - 4 ) << 2 ) ) ;
V_76 |= V_45 -> V_77 << ( ( V_75 - 4 ) << 2 ) ;
F_34 ( V_76 , V_6 -> V_33 + V_80 ) ;
} else {
V_76 = F_33 ( V_6 -> V_33 + V_79 ) ;
V_76 &= ~ ( 0xF << ( V_75 << 2 ) ) ;
V_76 |= V_45 -> V_77 << ( V_75 << 2 ) ;
F_34 ( V_76 , V_6 -> V_33 + V_79 ) ;
}
}
V_65 -> V_77 = F_35 ( NULL , V_74 ) ;
}
void F_36 ( struct V_13 * V_14 )
{
struct V_59 * V_65 ;
int V_75 , V_82 , V_83 ;
unsigned int V_84 = 0 ;
struct V_5 * V_6 ;
int V_26 ;
struct V_63 * V_85 ;
if ( ! V_28 ) {
F_20 ( L_25 ) ;
return;
}
V_6 = & V_8 ;
if ( V_14 -> V_18 != 0 ) {
F_20 ( L_26 , V_14 -> V_18 ) ;
return;
}
F_37 (dev, &bus->devices, bus_list) {
V_82 = V_83 = 0 ;
for( V_75 = 0 ; V_75 < 6 ; V_75 ++ ) {
unsigned long V_86 = V_65 -> V_68 [ V_75 ] . V_7 ;
if ( V_86 & V_70 ) {
V_82 = 1 ;
} else if ( V_86 & V_72 )
V_83 = 1 ;
}
F_8 ( V_65 -> V_14 , V_65 -> V_2 , V_87 , 2 , & V_84 ) ;
if ( V_82 && ! ( V_84 & V_88 ) ) {
F_20 ( L_27 ,
V_65 -> V_14 -> V_18 , V_65 -> V_2 ) ;
V_84 |= V_88 ;
F_10 ( V_65 -> V_14 , V_65 -> V_2 ,
V_87 , 2 , V_84 ) ;
}
if ( V_83 && ! ( V_84 & V_89 ) ) {
F_20 ( L_28 ,
V_65 -> V_14 -> V_18 , V_65 -> V_2 ) ;
V_84 |= V_89 ;
F_10 ( V_65 -> V_14 , V_65 -> V_2 ,
V_87 , 2 , V_84 ) ;
}
V_26 = F_27 ( & V_6 -> V_24 , V_65 ) ;
if( V_26 == 0 )
V_26 = - 1 ;
V_85 = F_29 () ;
V_85 -> V_24 = & V_6 -> V_24 ;
V_85 -> V_40 = F_38 ( V_26 ) ;
V_65 -> V_90 = V_85 ;
if ( ( V_65 -> V_91 >> 16 ) != V_92 )
F_31 ( V_6 , V_65 , V_26 ) ;
F_32 ( V_6 , V_65 , V_26 ) ;
}
}
static void F_39 ( void )
{
V_93 = F_5 ( V_8 . V_33 + V_94 ) ;
}
static unsigned int F_40 ( void )
{
T_1 V_4 , V_95 ;
V_4 = F_5 ( V_8 . V_33 + V_96 ) ;
V_95 = V_4 & ~ V_97 ;
if ( V_4 & V_97 )
V_95 += V_98 ;
V_95 = ( ( V_95 / V_99 ) * V_100 ) / ( V_98 / V_99 ) ;
return V_95 * 2 ;
}
void T_2 F_41 ( void )
{
struct V_5 * V_6 = & V_8 ;
unsigned long V_17 ;
int V_101 , V_77 ;
int V_27 ;
#ifndef F_42
V_102 . V_103 = V_104 / V_99 ;
V_102 . V_105 |= V_106 ;
#endif
V_102 . V_105 |= V_107 ;
V_102 . V_108 = F_40 ;
F_3 ( V_98 , V_6 -> V_33 + V_94 ) ;
V_17 = F_43 ( V_6 -> V_33 + V_109 ) ;
V_101 = F_44 ( V_17 ) ;
F_3 ( F_45 ( V_101 , 0 ) ,
V_6 -> V_33 + V_109 ) ;
V_77 = F_35 ( NULL , V_101 ) ;
V_27 = F_46 ( V_77 , V_110 ,
V_111 , L_29 , NULL ) ;
if ( V_27 ) {
F_12 ( L_30 , V_101 ) ;
F_13 () ;
}
F_47 () ;
}
int F_48 ( struct V_59 * V_60 , int V_112 )
{
return 0 ;
}
void F_49 ( unsigned int V_113 , struct V_114 * V_21 )
{
V_113 = F_50 ( V_113 ) ;
if ( ! V_10 || ( V_113 & V_115 ) == 0 ) {
F_20 ( L_31 ,
V_113 , ( int ) V_21 -> V_116 , V_10 ) ;
for (; ; ) { }
}
V_10 = 0 ;
V_11 = 1 ;
V_21 -> V_116 = V_21 -> V_117 ;
V_21 -> V_117 += 4 ;
}
static inline unsigned long F_51 ( int V_118 )
{
return 1 << V_118 ;
}
static void F_52 ( struct V_119 * V_120 )
{
unsigned long V_112 , V_7 ;
V_112 = ( unsigned long ) V_120 -> V_121 ;
F_2 ( V_7 ) ;
F_3 ( V_112 , V_8 . V_33 + V_122 ) ;
F_7 ( V_7 ) ;
}
static void F_53 ( struct V_119 * V_120 )
{
unsigned long V_112 , V_7 ;
V_112 = ( unsigned long ) V_120 -> V_121 ;
F_2 ( V_7 ) ;
F_3 ( V_112 , V_8 . V_33 + V_123 ) ;
F_7 ( V_7 ) ;
}
static unsigned int F_54 ( struct V_119 * V_120 )
{
F_55 ( V_120 -> V_77 ) ;
F_53 ( V_120 ) ;
return 0 ;
}
unsigned int F_35 ( struct V_124 * V_125 ,
unsigned int V_74 )
{
unsigned int V_77 ;
unsigned long V_112 ;
V_77 = 0 ;
V_112 = F_51 ( V_74 ) ;
if ( V_112 == 0 )
goto V_126;
V_77 = F_56 ( V_74 , V_74 ) ;
if ( V_77 == 0 )
goto V_126;
F_57 ( V_77 , & V_127 ,
V_128 , L_32 ) ;
F_58 ( V_77 , ( void * ) V_112 ) ;
V_126:
return V_77 ;
}
static void F_59 ( int V_129 , unsigned int V_130 )
{
F_20 ( L_33 , __FILE__ , __LINE__ ) ;
}
void T_2 F_60 ( void )
{
V_102 . V_131 = F_35 ;
V_102 . V_132 = F_39 ;
V_102 . V_133 = F_59 ;
}
