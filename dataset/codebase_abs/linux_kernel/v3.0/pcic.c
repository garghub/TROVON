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
F_17 ( V_21 [ 2 ] . V_34 , V_21 [ 2 ] . V_35 * 2 ) ) == 0 ) {
F_12 ( L_11
L_12 ) ;
F_13 () ;
}
V_6 -> V_39 . V_32 = L_13 ;
if ( ( V_6 -> V_12 =
F_17 ( V_21 [ 3 ] . V_34 , V_21 [ 3 ] . V_35 * 2 ) ) == 0 ) {
F_12 ( L_11
L_14 ) ;
F_13 () ;
}
V_24 = & V_6 -> V_24 ;
V_24 -> V_40 = V_26 ;
F_18 ( V_26 , L_15 , V_25 , 63 ) ; V_25 [ 63 ] = 0 ;
strcpy ( V_24 -> V_41 , V_25 ) ;
{
extern volatile int V_42 [ 1 ] ;
extern int V_43 [ 1 ] ;
V_42 [ 0 ] = V_43 [ 0 ] ;
V_42 [ 1 ] = V_43 [ 1 ] ;
V_42 [ 2 ] = V_43 [ 2 ] ;
V_42 [ 3 ] = V_43 [ 3 ] ;
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
#if 0
pci_fill_in_pbm_cookies(pbm->pci_bus, pbm, pbm->prom_node);
pci_record_assignments(pbm, pbm->pci_bus);
pci_assign_unassigned(pbm, pbm->pci_bus);
pci_fixup_irq(pbm, pbm->pci_bus);
#endif
}
static int T_2 F_23 ( void )
{
struct V_5 * V_6 ;
if( ! V_28 )
return 0 ;
V_6 = & V_8 ;
F_24 ( V_54 ,
V_6 -> V_33 + V_55 ) ;
F_3 ( 0xF0000000UL , V_6 -> V_33 + V_56 ) ;
F_3 ( 0 + V_57 ,
V_6 -> V_33 + V_58 ) ;
F_21 ( V_6 ) ;
return 0 ;
}
int F_25 ( void )
{
return V_28 ;
}
static int T_4 F_26 ( struct V_23 * V_24 ,
struct V_59 * V_60 )
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
V_26 = F_27 ( V_26 ) ;
}
return 0 ;
}
static inline struct V_63 * F_28 ( void )
{
return F_29 ( sizeof( struct V_63 ) , V_64 ) ;
}
static void F_30 ( struct V_5 * V_6 ,
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
F_31 ( struct V_5 * V_6 , struct V_59 * V_65 , int V_26 )
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
if ( ( V_45 = V_6 -> V_48 ) == 0 ) {
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
V_76 = F_32 ( V_6 -> V_33 + V_79 ) ;
V_74 = V_76 >> ( V_75 << 2 ) & 0xF ;
} else if ( V_75 >= 4 && V_75 < 8 ) {
V_76 = F_32 ( V_6 -> V_33 + V_80 ) ;
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
V_76 = F_32 ( V_6 -> V_33 + V_80 ) ;
V_76 &= ~ ( 0xF << ( ( V_75 - 4 ) << 2 ) ) ;
V_76 |= V_45 -> V_77 << ( ( V_75 - 4 ) << 2 ) ;
F_33 ( V_76 , V_6 -> V_33 + V_80 ) ;
} else {
V_76 = F_32 ( V_6 -> V_33 + V_79 ) ;
V_76 &= ~ ( 0xF << ( V_75 << 2 ) ) ;
V_76 |= V_45 -> V_77 << ( V_75 << 2 ) ;
F_33 ( V_76 , V_6 -> V_33 + V_79 ) ;
}
}
V_65 -> V_77 = F_34 ( NULL , V_74 ) ;
}
void T_4 F_35 ( struct V_13 * V_14 )
{
struct V_59 * V_65 ;
int V_75 , V_82 , V_83 ;
unsigned int V_84 ;
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
F_36 (dev, &bus->devices, bus_list) {
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
V_26 = F_26 ( & V_6 -> V_24 , V_65 ) ;
if( V_26 == 0 )
V_26 = - 1 ;
V_85 = F_28 () ;
V_85 -> V_24 = & V_6 -> V_24 ;
V_85 -> V_40 = F_37 ( V_26 ) ;
V_65 -> V_90 = V_85 ;
if ( ( V_65 -> V_91 >> 16 ) != V_92 )
F_30 ( V_6 , V_65 , V_26 ) ;
F_31 ( V_6 , V_65 , V_26 ) ;
}
}
unsigned int
F_38 ( unsigned int V_78 , const char * V_32 )
{
struct V_5 * V_6 = & V_8 ;
unsigned int V_77 ;
unsigned int V_76 ;
if ( V_78 < 4 ) {
V_76 = F_32 ( V_6 -> V_33 + V_79 ) ;
V_77 = V_76 >> ( V_78 << 2 ) & 0xF ;
} else if ( V_78 < 8 ) {
V_76 = F_32 ( V_6 -> V_33 + V_80 ) ;
V_77 = V_76 >> ( ( V_78 - 4 ) << 2 ) & 0xF ;
} else {
F_20 ( L_29 , V_78 , V_32 ) ;
for (; ; ) {}
}
return V_77 ;
}
static void F_39 ( void )
{
V_93 = F_5 ( V_8 . V_33 + V_94 ) ;
}
static T_5 F_40 ( int V_77 , void * V_95 )
{
F_39 () ;
F_41 ( 1 ) ;
#ifndef F_42
F_43 ( F_44 ( F_45 () ) ) ;
#endif
return V_96 ;
}
T_1 F_46 ( void )
{
unsigned long V_97 =
F_5 ( V_8 . V_33 + V_98 ) & ~ V_99 ;
V_97 = ( ( V_97 / 100 ) * V_100 ) / ( V_101 / 100 ) ;
return V_97 * 1000 ;
}
void T_2 F_47 ( void )
{
struct V_5 * V_6 = & V_8 ;
unsigned long V_17 ;
int V_102 , V_77 ;
int V_27 ;
V_103 = F_46 ;
F_48 () ;
F_3 ( V_101 , V_6 -> V_33 + V_94 ) ;
V_17 = F_49 ( V_6 -> V_33 + V_104 ) ;
V_102 = F_50 ( V_17 ) ;
F_3 ( F_51 ( V_102 , 0 ) ,
V_6 -> V_33 + V_104 ) ;
V_77 = F_34 ( NULL , V_102 ) ;
V_27 = F_52 ( V_77 , F_40 ,
V_105 , L_30 , NULL ) ;
if ( V_27 ) {
F_12 ( L_31 , V_102 ) ;
F_13 () ;
}
F_53 () ;
}
char * T_4 F_54 ( char * V_106 )
{
return V_106 ;
}
T_6 F_55 ( void * V_107 , const struct V_68 * V_108 ,
T_6 V_15 , T_6 V_109 )
{
return V_108 -> V_69 ;
}
int F_56 ( struct V_59 * V_60 , int V_110 )
{
return 0 ;
}
void F_57 ( unsigned int V_111 , struct V_112 * V_21 )
{
V_111 = F_58 ( V_111 ) ;
if ( ! V_10 || ( V_111 & V_113 ) == 0 ) {
F_20 ( L_32 ,
V_111 , ( int ) V_21 -> V_114 , V_10 ) ;
for (; ; ) { }
}
V_10 = 0 ;
V_11 = 1 ;
V_21 -> V_114 = V_21 -> V_115 ;
V_21 -> V_115 += 4 ;
}
static inline unsigned long F_59 ( int V_116 )
{
return 1 << V_116 ;
}
static void F_60 ( struct V_117 * V_107 )
{
unsigned long V_110 , V_7 ;
V_110 = ( unsigned long ) V_107 -> V_118 ;
F_2 ( V_7 ) ;
F_3 ( V_110 , V_8 . V_33 + V_119 ) ;
F_7 ( V_7 ) ;
}
static void F_61 ( struct V_117 * V_107 )
{
unsigned long V_110 , V_7 ;
V_110 = ( unsigned long ) V_107 -> V_118 ;
F_2 ( V_7 ) ;
F_3 ( V_110 , V_8 . V_33 + V_120 ) ;
F_7 ( V_7 ) ;
}
static unsigned int F_62 ( struct V_117 * V_107 )
{
F_63 ( V_107 -> V_77 ) ;
F_61 ( V_107 ) ;
return 0 ;
}
unsigned int F_34 ( struct V_121 * V_122 ,
unsigned int V_74 )
{
unsigned int V_77 ;
unsigned long V_110 ;
V_77 = 0 ;
V_110 = F_59 ( V_74 ) ;
if ( V_110 == 0 )
goto V_123;
V_77 = F_64 ( V_74 , V_74 ) ;
if ( V_77 == 0 )
goto V_123;
F_65 ( V_77 , & V_124 ,
V_125 , L_33 ) ;
F_66 ( V_77 , ( void * ) V_110 ) ;
V_123:
return V_77 ;
}
static void F_67 ( int V_126 , unsigned int V_127 )
{
F_20 ( L_34 , __FILE__ , __LINE__ ) ;
}
void T_2 F_68 ( void )
{
V_128 . V_129 = F_34 ;
F_69 ( V_130 , F_39 , V_131 ) ;
F_69 ( V_132 , F_67 , V_131 ) ;
}
int F_70 ( struct V_59 * V_60 , int V_68 )
{
return - V_133 ;
}
struct V_134 * F_71 ( struct V_59 * V_60 )
{
struct V_63 * V_114 = V_60 -> V_90 ;
return V_114 -> V_40 ;
}
void F_72 ( unsigned long V_135 , const void * V_136 , unsigned long V_97 )
{
while ( V_97 ) {
V_97 -= 1 ;
F_73 ( * ( const char * ) V_136 , V_135 ) ;
V_136 += 1 ;
}
}
void F_74 ( unsigned long V_135 , const void * V_136 , unsigned long V_97 )
{
while ( V_97 ) {
V_97 -= 2 ;
F_75 ( * ( const short * ) V_136 , V_135 ) ;
V_136 += 2 ;
}
}
void F_76 ( unsigned long V_135 , const void * V_136 , unsigned long V_97 )
{
while ( V_97 ) {
V_97 -= 4 ;
F_77 ( * ( const long * ) V_136 , V_135 ) ;
V_136 += 4 ;
}
}
void F_78 ( unsigned long V_135 , void * V_137 , unsigned long V_97 )
{
while ( V_97 ) {
V_97 -= 1 ;
* ( unsigned char * ) V_137 = F_79 ( V_135 ) ;
V_137 += 1 ;
}
}
void F_80 ( unsigned long V_135 , void * V_137 , unsigned long V_97 )
{
while ( V_97 ) {
V_97 -= 2 ;
* ( unsigned short * ) V_137 = F_81 ( V_135 ) ;
V_137 += 2 ;
}
}
void F_82 ( unsigned long V_135 , void * V_137 , unsigned long V_97 )
{
while ( V_97 ) {
V_97 -= 4 ;
* ( unsigned long * ) V_137 = F_83 ( V_135 ) ;
V_137 += 4 ;
}
}
