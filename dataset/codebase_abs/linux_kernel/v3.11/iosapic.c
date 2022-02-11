static inline unsigned int F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
return F_3 ( V_1 + V_4 ) ;
}
static inline void F_4 ( void T_1 * V_1 , unsigned int V_2 , T_2 V_5 )
{
F_2 ( V_2 , V_1 + V_3 ) ;
F_2 ( V_5 , V_1 + V_4 ) ;
}
static inline void F_5 ( void T_1 * V_6 , unsigned int V_7 )
{
F_6 ( V_7 , V_6 ) ;
}
static struct V_8 * F_7 ( int V_9 )
{
unsigned long V_10 ;
V_10 = ( unsigned long ) F_8 ( sizeof( struct V_8 ) * V_9 + 8 , V_11 ) ;
V_10 = ( V_10 + 7UL ) & ~ 7UL ;
return (struct V_8 * ) V_10 ;
}
static int T_3
F_9 ( unsigned long V_12 , struct V_8 * * V_13 )
{
long V_14 ;
struct V_8 * V_15 ;
unsigned long V_9 = 0UL ;
F_10 ( ! V_13 ) ;
if ( F_11 () ) {
F_12 ( L_1 , V_12 ) ;
V_14 = F_13 ( & V_9 , V_12 ) ;
F_12 ( L_2 , V_14 ) ;
F_10 ( V_14 != V_16 ) ;
F_10 ( V_9 == 0 ) ;
V_15 = F_7 ( V_9 ) ;
if ( V_15 == NULL ) {
F_14 (KERN_WARNING MODULE_NAME L_3
L_4 ) ;
return 0 ;
}
V_14 = F_15 ( V_15 , V_12 ) ;
F_12 ( L_5 , V_14 ) ;
F_16 ( V_14 != V_16 ) ;
} else {
if ( V_17 )
return 0 ;
V_14 = F_17 ( & V_9 , 0 ) ;
F_12 ( L_6 , V_14 ) ;
if ( V_14 != V_16 ) {
return 0 ;
}
F_10 ( V_9 == 0 ) ;
V_15 = F_7 ( V_9 ) ;
if ( ! V_15 ) {
F_14 (KERN_WARNING MODULE_NAME L_3
L_4 ) ;
return 0 ;
}
V_14 = F_18 ( V_9 , 0 , V_15 ) ;
F_10 ( V_14 != V_16 ) ;
}
* V_13 = V_15 ;
#ifdef F_19
{
struct V_8 * V_18 = V_15 ;
int V_19 ;
F_14 ( V_20 L_7 , V_12 ) ;
F_14 ( V_20 L_8 ,
V_15 ,
V_9 ,
( int ) sizeof( struct V_8 ) ) ;
for ( V_19 = 0 ; V_19 < V_9 ; V_19 ++ , V_18 ++ ) {
F_14 ( V_20 L_9 ,
V_18 -> V_21 , V_18 -> V_22 , V_18 -> V_23 ,
V_18 -> V_24 , V_18 -> V_25 , V_18 -> V_26 ,
V_18 -> V_27 , V_18 -> V_28 ,
( ( T_2 * ) V_18 ) [ 2 ] ,
( ( T_2 * ) V_18 ) [ 3 ]
) ;
}
}
#endif
return V_9 ;
}
void T_3 F_20 ( void )
{
unsigned long V_29 = 0 ;
F_12 ( L_10 ) ;
#ifdef F_21
if ( F_11 () ) {
int V_14 ;
struct V_30 V_31 ;
V_14 = F_22 ( & V_31 ) ;
if ( V_14 == V_16 ) {
V_29 = V_31 . V_12 ;
}
}
#endif
V_32 = F_9 ( V_29 , & V_17 ) ;
if ( V_32 == 0 )
V_17 = NULL ;
}
static struct V_8 *
F_23 ( struct V_33 * V_34 , T_4 V_35 , T_4 V_36 )
{
struct V_8 * V_19 = V_17 ;
int V_37 ;
T_4 V_38 = ( V_35 << V_39 ) | ( V_36 - 1 ) ;
F_24 ( L_11 , V_35 , V_36 ) ;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ , V_19 ++ ) {
if ( V_19 -> V_21 != V_40 ) {
F_24 (KERN_WARNING MODULE_NAME L_12 , i, cnt, i->entry_type) ;
continue;
}
if ( V_19 -> V_22 != V_41 ) {
F_24 (KERN_WARNING MODULE_NAME L_13 , i, cnt, i->entry_length) ;
continue;
}
if ( V_19 -> V_23 != V_42 ) {
F_24 (KERN_WARNING MODULE_NAME L_14 , i, cnt, i->interrupt_type) ;
continue;
}
if ( ! F_25 ( V_19 , V_34 -> V_43 ) )
continue;
if ( ( V_19 -> V_25 & V_44 ) != V_38 )
continue;
return V_19 ;
}
F_14 (KERN_WARNING MODULE_NAME L_15 ,
isi->isi_hpa, slot, intr_pin) ;
return NULL ;
}
static struct V_8 *
F_26 ( struct V_33 * V_34 , struct V_45 * V_46 )
{
T_4 V_36 , V_47 ;
F_27 ( V_46 , V_48 , & V_36 ) ;
F_24 ( L_16 ,
V_46 -> V_49 , F_28 ( V_46 -> V_50 ) , V_36 ) ;
if ( V_36 == 0 ) {
return NULL ;
}
if ( V_46 -> V_51 -> V_52 ) {
#ifdef F_29
if ( V_53 -> V_54 ) {
V_36 = V_53 -> V_54 ( V_46 ) ;
}
#else
struct V_55 * V_18 = V_46 -> V_51 ;
V_36 = F_30 ( V_46 , V_36 ) ;
#endif
while ( V_18 -> V_52 -> V_52 )
V_18 = V_18 -> V_52 ;
V_47 = F_28 ( V_18 -> V_56 -> V_50 ) ;
} else {
V_47 = F_28 ( V_46 -> V_50 ) ;
}
F_24 ( L_17 ,
V_46 -> V_51 -> V_57 . V_58 , V_47 , V_36 ) ;
return F_23 ( V_34 , V_47 , V_36 ) ;
}
static void F_31 ( struct V_59 * V_60 , T_2 * V_61 , T_2 * V_62 )
{
struct V_33 * V_63 = V_60 -> V_1 ;
T_4 V_64 = V_60 -> V_65 ;
* V_61 = F_1 ( V_63 -> V_6 , F_32 ( V_64 ) ) ;
* V_62 = F_1 ( V_63 -> V_6 , F_33 ( V_64 ) ) ;
}
static void F_34 ( struct V_59 * V_60 , T_2 V_61 , T_2 V_62 )
{
struct V_33 * V_63 = V_60 -> V_1 ;
F_24 ( L_18 ,
V_60 -> V_65 , V_63 -> V_43 , V_61 , V_62 ) ;
F_4 ( V_63 -> V_6 , F_32 ( V_60 -> V_65 ) , V_61 ) ;
V_61 = F_3 ( V_63 -> V_6 + V_4 ) ;
F_4 ( V_63 -> V_6 , F_33 ( V_60 -> V_65 ) , V_62 ) ;
V_62 = F_3 ( V_63 -> V_6 + V_4 ) ;
}
static void
F_35 ( struct V_59 * V_60 , T_2 * V_61 , T_2 * V_62 )
{
T_2 V_66 = 0 ;
struct V_8 * V_18 = V_60 -> V_67 ;
if ( ( V_18 -> V_24 & V_68 ) == V_69 )
V_66 |= V_70 ;
if ( ( ( V_18 -> V_24 >> V_71 ) & V_72 ) == V_73 )
V_66 |= V_74 ;
* V_61 = V_66 | ( T_2 ) V_60 -> V_75 ;
if ( F_11 () ) {
* V_62 = ( T_2 ) ( V_60 -> V_76 ) ;
} else {
* V_62 = ( ( ( T_2 ) V_60 -> V_76 & 0x0ff00000 ) >> 4 ) |
( ( ( T_2 ) V_60 -> V_76 & 0x000ff000 ) << 12 ) ;
}
F_24 ( L_19 , * V_61 , * V_62 ) ;
}
static void F_36 ( struct V_77 * V_78 )
{
unsigned long V_79 ;
struct V_59 * V_60 = F_37 ( V_78 ) ;
T_2 V_80 , V_81 ;
F_38 ( & V_82 , V_79 ) ;
F_31 ( V_60 , & V_80 , & V_81 ) ;
V_80 |= V_83 ;
F_34 ( V_60 , V_80 , V_81 ) ;
F_39 ( & V_82 , V_79 ) ;
}
static void F_40 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = F_37 ( V_78 ) ;
T_2 V_80 , V_81 ;
F_16 ( V_60 -> V_84 == 0 ) ;
F_35 ( V_60 , & V_80 , & V_81 ) ;
F_34 ( V_60 , V_80 , V_81 ) ;
#ifdef F_19
{
T_2 * V_85 = ( T_2 * ) ( ( V_86 ) V_60 -> V_87 & ~ 0xffUL ) ;
F_14 ( L_20 , V_60 -> V_87 ) ;
for ( ; V_85 < V_60 -> V_87 ; V_85 ++ )
F_14 ( L_21 , F_3 ( V_85 ) ) ;
F_14 ( L_22 ) ;
}
F_14 ( L_23 ) ;
{
struct V_33 * V_63 = V_60 -> V_1 ;
for ( V_80 = 0x10 ; V_80 < 0x1e ; V_80 ++ ) {
V_81 = F_1 ( V_63 -> V_6 , V_80 ) ;
F_14 ( L_21 , V_81 ) ;
}
}
F_14 ( L_22 ) ;
#endif
F_12 ( V_88 L_24 , V_78 -> V_89 ,
V_60 -> V_87 , V_60 -> V_90 ) ;
F_5 ( V_60 -> V_87 , V_60 -> V_90 ) ;
}
static void F_41 ( struct V_77 * V_78 )
{
struct V_59 * V_60 = F_37 ( V_78 ) ;
F_5 ( V_60 -> V_87 , V_60 -> V_90 ) ;
F_42 ( V_78 ) ;
}
static int F_43 ( struct V_77 * V_78 ,
const struct V_91 * V_92 , bool V_93 )
{
struct V_59 * V_60 = F_37 ( V_78 ) ;
T_2 V_80 , V_81 , V_94 ;
unsigned long V_79 ;
int V_95 ;
V_95 = F_44 ( V_78 , V_92 ) ;
if ( V_95 < 0 )
return - 1 ;
F_45 ( V_78 -> V_96 , F_46 ( V_95 ) ) ;
V_60 -> V_76 = F_47 ( V_78 -> V_89 , V_95 ) ;
F_38 ( & V_82 , V_79 ) ;
F_31 ( V_60 , & V_80 , & V_81 ) ;
F_35 ( V_60 , & V_94 , & V_81 ) ;
F_34 ( V_60 , V_80 , V_81 ) ;
F_39 ( & V_82 , V_79 ) ;
return 0 ;
}
int F_48 ( void * V_97 , struct V_45 * V_46 )
{
struct V_33 * V_34 = V_97 ;
struct V_8 * V_67 = NULL ;
struct V_59 * V_60 ;
int V_98 ;
if ( ! V_34 ) {
F_14 (KERN_WARNING MODULE_NAME L_25 ,
pci_name(pcidev)) ;
return - 1 ;
}
#ifdef F_49
if ( F_50 ( V_46 ) ) {
V_46 -> V_89 = F_51 ( V_46 ) ;
if ( F_52 ( V_46 -> V_50 ) != V_99 )
return V_46 -> V_89 ;
}
#endif
V_67 = F_26 ( V_34 , V_46 ) ;
if ( ! V_67 ) {
F_14 ( L_26 ,
F_53 ( V_46 ) ) ;
return - 1 ;
}
F_24 ( L_27 ,
V_67 ,
V_67 -> V_21 ,
V_67 -> V_22 ,
V_67 -> V_24 ,
V_67 -> V_25 ,
V_67 -> V_26 ,
V_67 -> V_27 ,
V_67 -> V_28 ,
( T_2 ) V_67 -> V_100 ) ;
V_98 = V_67 -> V_28 ;
V_60 = V_34 -> V_101 + V_98 ;
F_24 ( L_28 , V_98 , V_60 ) ;
if ( V_60 -> V_67 )
goto V_102;
V_60 -> V_67 = V_67 ;
V_60 -> V_84 = F_54 ( 8 ) ;
if ( V_60 -> V_84 < 0 )
F_55 ( L_29 ) ;
V_60 -> V_76 = F_56 ( V_60 -> V_84 ) ;
V_60 -> V_75 = F_57 ( V_60 -> V_84 ) ;
V_60 -> V_87 = V_34 -> V_6 + V_103 ;
V_60 -> V_90 = F_58 ( V_60 -> V_75 ) ;
F_59 ( V_60 -> V_84 , & V_104 , V_60 ) ;
V_102:
V_46 -> V_89 = V_60 -> V_84 ;
F_24 ( L_30 ,
F_28 ( V_46 -> V_50 ) , F_52 ( V_46 -> V_50 ) ,
V_46 -> V_105 , V_46 -> V_106 , V_98 , V_46 -> V_89 ) ;
return V_46 -> V_89 ;
}
int F_60 ( struct V_107 * V_108 )
{
struct V_33 * V_34 ;
struct V_8 * V_67 ;
struct V_59 * V_60 ;
int V_37 ;
int V_109 ;
V_109 = ( V_108 -> V_110 >> 24 ) & 15 ;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ ) {
V_67 = & V_17 [ V_37 ] ;
if ( F_25 ( V_67 , V_108 -> V_111 ) &&
V_67 -> V_28 == V_109 )
break;
}
if ( V_37 >= V_32 )
return 0 ;
F_24 ( L_31 ,
V_67 ,
V_67 -> V_21 ,
V_67 -> V_22 ,
V_67 -> V_24 ,
V_67 -> V_25 ,
V_67 -> V_26 ,
V_67 -> V_27 ,
V_67 -> V_28 ,
( T_2 ) V_67 -> V_100 ) ;
for ( V_34 = V_112 ; V_34 ; V_34 = V_34 -> V_113 )
if ( V_34 -> V_43 == V_108 -> V_111 )
break;
if ( ! V_34 )
return 0 ;
V_60 = V_34 -> V_101 + V_109 ;
F_24 ( L_32 , V_114 , V_60 ) ;
if ( V_60 -> V_67 )
goto V_102;
V_60 -> V_67 = V_67 ;
V_60 -> V_84 = F_54 ( 8 ) ;
if ( V_60 -> V_84 < 0 )
F_55 ( L_29 ) ;
V_60 -> V_76 = F_56 ( V_60 -> V_84 ) ;
V_60 -> V_75 = F_57 ( V_60 -> V_84 ) ;
V_60 -> V_87 = V_34 -> V_6 + V_103 ;
V_60 -> V_90 = F_58 ( V_60 -> V_75 ) ;
F_59 ( V_60 -> V_84 , & V_104 , V_60 ) ;
V_102:
return V_60 -> V_84 ;
}
static unsigned int
F_61 ( struct V_33 * V_34 )
{
return F_1 ( V_34 -> V_6 , V_115 ) ;
}
void * F_62 ( unsigned long V_116 )
{
struct V_33 * V_34 = NULL ;
struct V_8 * V_67 = V_17 ;
struct V_59 * V_117 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ , V_67 ++ ) {
F_16 ( V_40 != V_67 -> V_21 ) ;
if ( F_25 ( V_67 , V_116 ) )
break;
}
if ( V_37 >= V_32 ) {
F_12 ( L_33 , V_116 ) ;
return NULL ;
}
V_34 = F_63 ( sizeof( struct V_33 ) , V_11 ) ;
if ( ! V_34 ) {
F_64 () ;
return NULL ;
}
V_34 -> V_6 = F_65 ( V_116 , 4096 ) ;
V_34 -> V_43 = V_116 ;
V_34 -> V_118 = F_61 ( V_34 ) ;
V_34 -> V_119 = F_66 ( V_34 -> V_118 ) + 1 ;
V_117 = V_34 -> V_101 = F_67 ( V_34 -> V_119 ,
sizeof( struct V_59 ) , V_11 ) ;
if ( V_117 == NULL ) {
F_68 ( V_34 ) ;
return NULL ;
}
for ( V_37 = 0 ; V_37 < V_34 -> V_119 ; V_37 ++ , V_117 ++ ) {
V_117 -> V_65 = ( unsigned char ) V_37 ;
V_117 -> V_1 = V_34 ;
}
V_34 -> V_113 = V_112 ;
V_112 = V_34 ;
return V_34 ;
}
static void
F_69 ( void * V_13 , long V_120 )
{
unsigned int V_19 , * V_121 = ( unsigned int * ) V_13 ;
F_14 (KERN_DEBUG MODULE_NAME L_34 , num_entry) ;
for ( V_19 = 0 ; V_19 < V_120 ; V_19 ++ , V_121 += 4 ) {
F_14 ( V_88 L_35 ,
V_121 , V_19 , V_121 [ 0 ] , V_121 [ 1 ] , V_121 [ 2 ] , V_121 [ 3 ] ) ;
}
}
static void
F_70 ( struct V_59 * V_60 )
{
F_14 (KERN_DEBUG MODULE_NAME L_36 , vi->irqline, vi) ;
F_14 ( V_88 L_37 , V_60 -> V_14 ) ;
F_14 ( V_88 L_38 , V_60 -> V_84 ) ;
F_14 ( V_88 L_39 , V_60 -> V_76 ) ;
F_14 ( V_88 L_40 , V_60 -> V_75 ) ;
F_14 ( V_88 L_41 , V_60 -> V_87 ) ;
F_14 ( V_88 L_42 , V_60 -> V_90 ) ;
}
static void
F_71 ( struct V_33 * V_34 )
{
F_14 (KERN_DEBUG MODULE_NAME L_43 , isi) ;
F_14 ( V_88 L_44 , V_34 -> V_43 ) ;
F_14 ( V_88 L_45 , V_34 -> V_122 ) ;
F_14 ( V_88 L_46 , V_34 -> V_118 ) ;
F_14 ( V_88 L_47 , V_34 -> V_101 ) ;
}
