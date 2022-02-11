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
V_46 -> V_51 -> V_57 , V_47 , V_36 ) ;
return F_23 ( V_34 , V_47 , V_36 ) ;
}
static void F_31 ( struct V_58 * V_59 , T_2 * V_60 , T_2 * V_61 )
{
struct V_33 * V_62 = V_59 -> V_1 ;
T_4 V_63 = V_59 -> V_64 ;
* V_60 = F_1 ( V_62 -> V_6 , F_32 ( V_63 ) ) ;
* V_61 = F_1 ( V_62 -> V_6 , F_33 ( V_63 ) ) ;
}
static void F_34 ( struct V_58 * V_59 , T_2 V_60 , T_2 V_61 )
{
struct V_33 * V_62 = V_59 -> V_1 ;
F_24 ( L_18 ,
V_59 -> V_64 , V_62 -> V_43 , V_60 , V_61 ) ;
F_4 ( V_62 -> V_6 , F_32 ( V_59 -> V_64 ) , V_60 ) ;
V_60 = F_3 ( V_62 -> V_6 + V_4 ) ;
F_4 ( V_62 -> V_6 , F_33 ( V_59 -> V_64 ) , V_61 ) ;
V_61 = F_3 ( V_62 -> V_6 + V_4 ) ;
}
static void
F_35 ( struct V_58 * V_59 , T_2 * V_60 , T_2 * V_61 )
{
T_2 V_65 = 0 ;
struct V_8 * V_18 = V_59 -> V_66 ;
if ( ( V_18 -> V_24 & V_67 ) == V_68 )
V_65 |= V_69 ;
if ( ( ( V_18 -> V_24 >> V_70 ) & V_71 ) == V_72 )
V_65 |= V_73 ;
* V_60 = V_65 | ( T_2 ) V_59 -> V_74 ;
if ( F_11 () ) {
* V_61 = ( T_2 ) ( V_59 -> V_75 ) ;
} else {
* V_61 = ( ( ( T_2 ) V_59 -> V_75 & 0x0ff00000 ) >> 4 ) |
( ( ( T_2 ) V_59 -> V_75 & 0x000ff000 ) << 12 ) ;
}
F_24 ( L_19 , * V_60 , * V_61 ) ;
}
static void F_36 ( struct V_76 * V_77 )
{
unsigned long V_78 ;
struct V_58 * V_59 = F_37 ( V_77 ) ;
T_2 V_79 , V_80 ;
F_38 ( & V_81 , V_78 ) ;
F_31 ( V_59 , & V_79 , & V_80 ) ;
V_79 |= V_82 ;
F_34 ( V_59 , V_79 , V_80 ) ;
F_39 ( & V_81 , V_78 ) ;
}
static void F_40 ( struct V_76 * V_77 )
{
struct V_58 * V_59 = F_37 ( V_77 ) ;
T_2 V_79 , V_80 ;
F_16 ( V_59 -> V_83 == 0 ) ;
F_35 ( V_59 , & V_79 , & V_80 ) ;
F_34 ( V_59 , V_79 , V_80 ) ;
#ifdef F_19
{
T_2 * V_84 = ( T_2 * ) ( ( V_85 ) V_59 -> V_86 & ~ 0xffUL ) ;
F_14 ( L_20 , V_59 -> V_86 ) ;
for ( ; V_84 < V_59 -> V_86 ; V_84 ++ )
F_14 ( L_21 , F_3 ( V_84 ) ) ;
F_14 ( L_22 ) ;
}
F_14 ( L_23 ) ;
{
struct V_33 * V_62 = V_59 -> V_1 ;
for ( V_79 = 0x10 ; V_79 < 0x1e ; V_79 ++ ) {
V_80 = F_1 ( V_62 -> V_6 , V_79 ) ;
F_14 ( L_21 , V_80 ) ;
}
}
F_14 ( L_22 ) ;
#endif
F_12 ( V_87 L_24 , V_77 -> V_88 ,
V_59 -> V_86 , V_59 -> V_89 ) ;
F_5 ( V_59 -> V_86 , V_59 -> V_89 ) ;
}
static void F_41 ( struct V_76 * V_77 )
{
struct V_58 * V_59 = F_37 ( V_77 ) ;
F_5 ( V_59 -> V_86 , V_59 -> V_89 ) ;
F_42 ( V_77 ) ;
}
static int F_43 ( struct V_76 * V_77 ,
const struct V_90 * V_91 , bool V_92 )
{
struct V_58 * V_59 = F_37 ( V_77 ) ;
T_2 V_79 , V_80 , V_93 ;
unsigned long V_78 ;
int V_94 ;
V_94 = F_44 ( V_77 , V_91 ) ;
if ( V_94 < 0 )
return - 1 ;
F_45 ( V_77 -> V_95 , F_46 ( V_94 ) ) ;
V_59 -> V_75 = F_47 ( V_77 -> V_88 , V_94 ) ;
F_38 ( & V_81 , V_78 ) ;
F_31 ( V_59 , & V_79 , & V_80 ) ;
F_35 ( V_59 , & V_93 , & V_80 ) ;
F_34 ( V_59 , V_79 , V_80 ) ;
F_39 ( & V_81 , V_78 ) ;
return 0 ;
}
int F_48 ( void * V_96 , struct V_45 * V_46 )
{
struct V_33 * V_34 = V_96 ;
struct V_8 * V_66 = NULL ;
struct V_58 * V_59 ;
int V_97 ;
if ( ! V_34 ) {
F_14 (KERN_WARNING MODULE_NAME L_25 ,
pci_name(pcidev)) ;
return - 1 ;
}
#ifdef F_49
if ( F_50 ( V_46 ) ) {
V_46 -> V_88 = F_51 ( V_46 ) ;
if ( F_52 ( V_46 -> V_50 ) != V_98 )
return V_46 -> V_88 ;
}
#endif
V_66 = F_26 ( V_34 , V_46 ) ;
if ( ! V_66 ) {
F_14 ( L_26 ,
F_53 ( V_46 ) ) ;
return - 1 ;
}
F_24 ( L_27 ,
V_66 ,
V_66 -> V_21 ,
V_66 -> V_22 ,
V_66 -> V_24 ,
V_66 -> V_25 ,
V_66 -> V_26 ,
V_66 -> V_27 ,
V_66 -> V_28 ,
( T_2 ) V_66 -> V_99 ) ;
V_97 = V_66 -> V_28 ;
V_59 = V_34 -> V_100 + V_97 ;
F_24 ( L_28 , V_97 , V_59 ) ;
if ( V_59 -> V_66 )
goto V_101;
V_59 -> V_66 = V_66 ;
V_59 -> V_83 = F_54 ( 8 ) ;
if ( V_59 -> V_83 < 0 )
F_55 ( L_29 ) ;
V_59 -> V_75 = F_56 ( V_59 -> V_83 ) ;
V_59 -> V_74 = F_57 ( V_59 -> V_83 ) ;
V_59 -> V_86 = V_34 -> V_6 + V_102 ;
V_59 -> V_89 = F_58 ( V_59 -> V_74 ) ;
F_59 ( V_59 -> V_83 , & V_103 , V_59 ) ;
V_101:
V_46 -> V_88 = V_59 -> V_83 ;
F_24 ( L_30 ,
F_28 ( V_46 -> V_50 ) , F_52 ( V_46 -> V_50 ) ,
V_46 -> V_104 , V_46 -> V_105 , V_97 , V_46 -> V_88 ) ;
return V_46 -> V_88 ;
}
static unsigned int
F_60 ( struct V_33 * V_34 )
{
return F_1 ( V_34 -> V_6 , V_106 ) ;
}
void * F_61 ( unsigned long V_107 )
{
struct V_33 * V_34 = NULL ;
struct V_8 * V_66 = V_17 ;
struct V_58 * V_108 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_32 ; V_37 ++ , V_66 ++ ) {
F_16 ( V_40 != V_66 -> V_21 ) ;
if ( F_25 ( V_66 , V_107 ) )
break;
}
if ( V_37 >= V_32 ) {
F_12 ( L_31 , V_107 ) ;
return NULL ;
}
V_34 = F_62 ( sizeof( struct V_33 ) , V_11 ) ;
if ( ! V_34 ) {
F_63 () ;
return NULL ;
}
V_34 -> V_6 = F_64 ( V_107 , 4096 ) ;
V_34 -> V_43 = V_107 ;
V_34 -> V_109 = F_60 ( V_34 ) ;
V_34 -> V_110 = F_65 ( V_34 -> V_109 ) + 1 ;
V_108 = V_34 -> V_100 = F_66 ( V_34 -> V_110 ,
sizeof( struct V_58 ) , V_11 ) ;
if ( V_108 == NULL ) {
F_67 ( V_34 ) ;
return NULL ;
}
for ( V_37 = 0 ; V_37 < V_34 -> V_110 ; V_37 ++ , V_108 ++ ) {
V_108 -> V_64 = ( unsigned char ) V_37 ;
V_108 -> V_1 = V_34 ;
}
return V_34 ;
}
static void
F_68 ( void * V_13 , long V_111 )
{
unsigned int V_19 , * V_112 = ( unsigned int * ) V_13 ;
F_14 (KERN_DEBUG MODULE_NAME L_32 , num_entry) ;
for ( V_19 = 0 ; V_19 < V_111 ; V_19 ++ , V_112 += 4 ) {
F_14 ( V_87 L_33 ,
V_112 , V_19 , V_112 [ 0 ] , V_112 [ 1 ] , V_112 [ 2 ] , V_112 [ 3 ] ) ;
}
}
static void
F_69 ( struct V_58 * V_59 )
{
F_14 (KERN_DEBUG MODULE_NAME L_34 , vi->irqline, vi) ;
F_14 ( V_87 L_35 , V_59 -> V_14 ) ;
F_14 ( V_87 L_36 , V_59 -> V_83 ) ;
F_14 ( V_87 L_37 , V_59 -> V_75 ) ;
F_14 ( V_87 L_38 , V_59 -> V_74 ) ;
F_14 ( V_87 L_39 , V_59 -> V_86 ) ;
F_14 ( V_87 L_40 , V_59 -> V_89 ) ;
}
static void
F_70 ( struct V_33 * V_34 )
{
F_14 (KERN_DEBUG MODULE_NAME L_41 , isi) ;
F_14 ( V_87 L_42 , V_34 -> V_43 ) ;
F_14 ( V_87 L_43 , V_34 -> V_113 ) ;
F_14 ( V_87 L_44 , V_34 -> V_109 ) ;
F_14 ( V_87 L_45 , V_34 -> V_100 ) ;
}
