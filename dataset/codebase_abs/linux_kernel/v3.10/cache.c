void
F_1 ( void )
{
F_2 ( V_1 , NULL , 1 ) ;
}
void
F_3 ( void )
{
F_2 ( V_2 , NULL , 1 ) ;
}
void
F_4 ( void )
{
V_2 ( NULL ) ;
V_1 ( NULL ) ;
}
void
F_5 ( struct V_3 * V_4 , unsigned long V_5 , T_1 * V_6 )
{
struct V_7 * V_7 = F_6 ( * V_6 ) ;
if ( F_7 ( F_8 ( V_7 ) ) && F_9 ( V_7 ) &&
F_10 ( V_8 , & V_7 -> V_9 ) ) {
F_11 ( V_7 ) ;
F_12 ( V_8 , & V_7 -> V_9 ) ;
} else if ( F_13 () )
F_11 ( V_7 ) ;
}
void
F_14 ( struct V_10 * V_11 )
{
char V_12 [ 32 ] ;
F_15 ( V_11 , L_1 ,
V_13 . V_14 / 1024 ) ;
if ( V_13 . V_15 != 1 )
snprintf ( V_12 , 32 , L_2 , V_13 . V_15 ) ;
F_15 ( V_11 , L_3 ,
V_13 . V_16 / 1024 ,
( V_13 . V_17 . V_18 ? L_4 : L_5 ) ,
( V_13 . V_17 . V_19 ? L_6 : L_7 ) ,
( ( V_13 . V_15 == 1 ) ? L_8 : V_12 ) ) ;
F_15 ( V_11 , L_9 L_10 ,
V_13 . V_20 ,
V_13 . V_21 ,
V_13 . V_22 . V_23 ? L_11 : L_7
) ;
#ifndef F_16
if ( V_24 . V_25 == 0 ) {
F_15 ( V_11 , L_12 ) ;
} else {
F_15 ( V_11 ,
L_13
L_14
L_15 ,
V_24 . V_25 , ( int ) 4096 ,
V_24 . V_25 >> 8 ,
V_24 . V_26 . V_27 ,
V_24 . V_26 . V_28 ,
V_24 . V_26 . V_29 ,
V_24 . V_30 . V_27 ,
V_24 . V_30 . V_28 ,
V_24 . V_30 . V_29
) ;
}
#endif
}
void T_2
F_17 ( void )
{
if ( F_18 ( & V_13 ) < 0 )
F_19 ( L_16 ) ;
#if 0
printk("ic_size %lx dc_size %lx it_size %lx\n",
cache_info.ic_size,
cache_info.dc_size,
cache_info.it_size);
printk("DC base 0x%lx stride 0x%lx count 0x%lx loop 0x%lx\n",
cache_info.dc_base,
cache_info.dc_stride,
cache_info.dc_count,
cache_info.dc_loop);
printk("dc_conf = 0x%lx alias %d blk %d line %d shift %d\n",
*(unsigned long *) (&cache_info.dc_conf),
cache_info.dc_conf.cc_alias,
cache_info.dc_conf.cc_block,
cache_info.dc_conf.cc_line,
cache_info.dc_conf.cc_shift);
printk(" wt %d sh %d cst %d hv %d\n",
cache_info.dc_conf.cc_wt,
cache_info.dc_conf.cc_sh,
cache_info.dc_conf.cc_cst,
cache_info.dc_conf.cc_hv);
printk("IC base 0x%lx stride 0x%lx count 0x%lx loop 0x%lx\n",
cache_info.ic_base,
cache_info.ic_stride,
cache_info.ic_count,
cache_info.ic_loop);
printk("ic_conf = 0x%lx alias %d blk %d line %d shift %d\n",
*(unsigned long *) (&cache_info.ic_conf),
cache_info.ic_conf.cc_alias,
cache_info.ic_conf.cc_block,
cache_info.ic_conf.cc_line,
cache_info.ic_conf.cc_shift);
printk(" wt %d sh %d cst %d hv %d\n",
cache_info.ic_conf.cc_wt,
cache_info.ic_conf.cc_sh,
cache_info.ic_conf.cc_cst,
cache_info.ic_conf.cc_hv);
printk("D-TLB conf: sh %d page %d cst %d aid %d pad1 %d\n",
cache_info.dt_conf.tc_sh,
cache_info.dt_conf.tc_page,
cache_info.dt_conf.tc_cst,
cache_info.dt_conf.tc_aid,
cache_info.dt_conf.tc_pad1);
printk("I-TLB conf: sh %d page %d cst %d aid %d pad1 %d\n",
cache_info.it_conf.tc_sh,
cache_info.it_conf.tc_page,
cache_info.it_conf.tc_cst,
cache_info.it_conf.tc_aid,
cache_info.it_conf.tc_pad1);
#endif
V_31 = 0 ;
if ( V_13 . V_22 . V_23 == 0 || V_13 . V_22 . V_23 == 2 ) {
if ( V_13 . V_22 . V_23 == 2 )
F_20 ( V_32 L_17
L_18 ) ;
V_31 = 1 ;
}
#define F_21 ( T_3 ) (cnf.cc_line << (3 + cnf.cc_block + cnf.cc_shift))
V_33 = F_21 ( V_13 . V_17 ) ;
V_34 = F_21 ( V_13 . V_35 ) ;
#undef F_21
#ifndef F_16
if ( F_22 ( & V_24 ) < 0 ) {
memset ( & V_24 , 0 , sizeof V_24 ) ;
}
#endif
if ( ( V_36 . V_37 . V_38 & V_39 ) ==
V_40 ) {
F_20 ( V_32 L_19 ) ;
#if 0
panic("SMP kernel required to avoid non-equivalent aliasing");
#endif
}
}
void F_23 ( void )
{
int V_41 , V_42 ;
unsigned long V_43 ;
switch ( V_36 . V_44 ) {
case V_45 :
F_24 () ;
return;
case V_46 :
case V_47 :
case V_48 :
V_41 = V_49 ;
break;
case V_50 :
V_41 = V_51 ;
break;
case V_52 :
return;
default:
V_41 = V_53 ;
break;
}
F_25 ( V_41 ) ;
V_42 = F_26 ( & V_43 ) ;
if ( V_42 < 0 && V_42 != V_54 )
F_19 ( L_20 ) ;
if ( V_43 != 0 )
F_19 ( L_21 ) ;
}
static inline void
F_27 ( struct V_3 * V_4 , unsigned long V_55 ,
unsigned long V_56 )
{
F_28 () ;
F_29 ( V_56 , V_55 ) ;
if ( V_4 -> V_57 & V_58 )
F_30 ( V_56 , V_55 ) ;
F_31 () ;
}
void F_32 ( struct V_7 * V_7 )
{
struct V_59 * V_60 = F_9 ( V_7 ) ;
struct V_3 * V_61 ;
unsigned long V_62 ;
unsigned long V_63 , V_64 = 0 ;
T_4 V_65 ;
if ( V_60 && ! F_33 ( V_60 ) ) {
F_34 ( V_8 , & V_7 -> V_9 ) ;
return;
}
F_11 ( V_7 ) ;
if ( ! V_60 )
return;
V_65 = V_7 -> V_66 << ( V_67 - V_68 ) ;
F_35 ( V_60 ) ;
F_36 (mpnt, &mapping->i_mmap, pgoff, pgoff) {
V_62 = ( V_65 - V_61 -> V_69 ) << V_68 ;
V_63 = V_61 -> V_70 + V_62 ;
F_37 ( V_61 , V_63 ) ;
if ( V_64 == 0 || ( V_64 & ( V_71 - 1 ) ) != ( V_63 & ( V_71 - 1 ) ) ) {
F_27 ( V_61 , V_63 , F_38 ( V_7 ) ) ;
if ( V_64 )
F_20 ( V_72 L_22 , V_64 , V_63 , V_61 -> V_73 ? ( char * ) V_61 -> V_73 -> V_74 . V_75 -> V_76 . V_77 : L_23 ) ;
V_64 = V_63 ;
}
}
F_39 ( V_60 ) ;
}
void T_2 F_40 ( void )
{
unsigned long V_78 , V_79 ;
unsigned long V_80 ;
V_79 = F_41 ( 16 ) ;
F_1 () ;
V_79 = F_41 ( 16 ) - V_79 ;
V_80 = ( unsigned long ) ( V_81 - V_82 ) ;
V_78 = F_41 ( 16 ) ;
F_42 ( ( unsigned long ) V_82 , V_80 ) ;
V_78 = F_41 ( 16 ) - V_78 ;
F_20 ( V_83 L_24 ,
V_79 , V_80 , V_78 ) ;
V_84 = V_80 * V_79 / V_78 ;
V_84 = ( V_84 + V_85 - 1 ) & ~ ( V_85 - 1 ) ;
if ( ! V_84 )
V_84 = V_86 ;
if ( V_84 > V_13 . V_16 )
V_84 = V_13 . V_16 ;
F_20 ( V_87 L_25 , V_84 , F_43 () ) ;
}
void F_44 ( void * V_63 )
{
unsigned long V_9 ;
F_45 ( V_63 ) ;
F_46 ( V_9 ) ;
F_47 ( V_63 ) ;
F_48 ( V_9 ) ;
}
void F_49 ( void * V_88 , unsigned long V_89 , struct V_7 * V_7 )
{
F_50 ( V_88 ) ;
if ( ! F_13 () )
F_45 ( V_88 ) ;
}
void F_51 ( void * V_88 , void * V_90 , unsigned long V_89 ,
struct V_7 * V_91 )
{
F_28 () ;
F_29 ( F_52 ( V_90 ) , V_89 ) ;
F_31 () ;
F_53 ( V_88 , V_90 ) ;
if ( ! F_13 () )
F_45 ( V_88 ) ;
}
void F_54 ( void * V_63 )
{
if ( F_13 () )
F_44 ( V_63 ) ;
}
void F_55 ( struct V_92 * V_93 , unsigned long V_63 )
{
unsigned long V_9 ;
F_46 ( V_9 ) ;
F_56 ( V_93 -> V_94 , 1 ) ;
F_57 ( V_63 ) ;
F_58 ( V_63 ) ;
F_48 ( V_9 ) ;
}
void F_59 ( unsigned long V_95 , unsigned long V_96 ,
unsigned long V_97 )
{
unsigned long V_98 ;
V_98 = ( ( V_97 - ( V_96 & V_99 ) ) + ( V_100 - 1 ) ) >> V_68 ;
if ( V_98 >= 512 )
F_60 () ;
else {
unsigned long V_9 ;
F_56 ( V_95 , 1 ) ;
F_46 ( V_9 ) ;
if ( V_31 ) {
while ( V_98 -- ) {
F_57 ( V_96 ) ;
F_58 ( V_96 ) ;
V_96 += V_100 ;
}
} else {
while ( V_98 -- ) {
F_57 ( V_96 ) ;
V_96 += V_100 ;
}
}
F_48 ( V_9 ) ;
}
}
static void F_61 ( void * V_101 )
{
F_4 () ;
}
void F_62 ( void )
{
F_2 ( F_61 , NULL , 1 ) ;
}
static inline unsigned long F_63 ( struct V_92 * V_93 )
{
struct V_3 * V_4 ;
unsigned long V_102 = 0 ;
for ( V_4 = V_93 -> V_103 ; V_4 ; V_4 = V_4 -> V_104 )
V_102 += V_4 -> V_105 - V_4 -> V_70 ;
return V_102 ;
}
static inline T_1 * F_64 ( T_5 * V_106 , unsigned long V_63 )
{
T_1 * V_6 = NULL ;
if ( ! F_65 ( * V_106 ) ) {
T_6 * V_107 = F_66 ( V_106 , V_63 ) ;
if ( ! F_67 ( * V_107 ) ) {
T_7 * V_108 = F_68 ( V_107 , V_63 ) ;
if ( ! F_69 ( * V_108 ) )
V_6 = F_70 ( V_108 , V_63 ) ;
}
}
return V_6 ;
}
void F_71 ( struct V_92 * V_93 )
{
if ( F_63 ( V_93 ) < V_84 ) {
struct V_3 * V_4 ;
if ( V_93 -> V_94 == F_72 ( 3 ) ) {
for ( V_4 = V_93 -> V_103 ; V_4 ; V_4 = V_4 -> V_104 ) {
F_73 ( V_4 -> V_70 ,
V_4 -> V_105 ) ;
if ( V_4 -> V_57 & V_58 )
F_74 (
V_4 -> V_70 , V_4 -> V_105 ) ;
}
} else {
T_5 * V_106 = V_93 -> V_106 ;
for ( V_4 = V_93 -> V_103 ; V_4 ; V_4 = V_4 -> V_104 ) {
unsigned long V_63 ;
for ( V_63 = V_4 -> V_70 ; V_63 < V_4 -> V_105 ;
V_63 += V_100 ) {
T_1 * V_6 = F_64 ( V_106 , V_63 ) ;
if ( V_6 != NULL ) {
T_1 V_109 = * V_6 ;
F_27 ( V_4 , V_63 ,
F_38 ( F_6 ( V_109 ) ) ) ;
}
}
}
}
return;
}
#ifdef F_75
F_62 () ;
#else
F_4 () ;
#endif
}
void
F_76 ( unsigned long V_96 , unsigned long V_97 )
{
if ( ( V_97 - V_96 ) < V_84 )
F_73 ( V_96 , V_97 ) ;
else
F_1 () ;
}
void
F_77 ( unsigned long V_96 , unsigned long V_97 )
{
if ( ( V_97 - V_96 ) < V_84 )
F_74 ( V_96 , V_97 ) ;
else
F_3 () ;
}
void F_78 ( struct V_3 * V_4 ,
unsigned long V_96 , unsigned long V_97 )
{
F_79 ( ! V_4 -> V_110 -> V_94 ) ;
if ( ( V_97 - V_96 ) < V_84 ) {
if ( V_4 -> V_110 -> V_94 == F_72 ( 3 ) ) {
F_73 ( V_96 , V_97 ) ;
if ( V_4 -> V_57 & V_58 )
F_74 ( V_96 , V_97 ) ;
} else {
unsigned long V_63 ;
T_5 * V_106 = V_4 -> V_110 -> V_106 ;
for ( V_63 = V_96 & V_99 ; V_63 < V_97 ;
V_63 += V_100 ) {
T_1 * V_6 = F_64 ( V_106 , V_63 ) ;
if ( V_6 != NULL ) {
T_1 V_109 = * V_6 ;
F_80 ( V_4 ,
V_63 , F_81 ( V_109 ) ) ;
}
}
}
} else {
#ifdef F_75
F_62 () ;
#else
F_4 () ;
#endif
}
}
void
F_80 ( struct V_3 * V_4 , unsigned long V_55 , unsigned long V_111 )
{
F_79 ( ! V_4 -> V_110 -> V_94 ) ;
F_37 ( V_4 , V_55 ) ;
F_27 ( V_4 , V_55 , F_38 ( F_82 ( V_111 ) ) ) ;
}
void F_83 ( struct V_7 * V_7 , unsigned long V_89 )
{
void * V_88 ;
unsigned long V_9 ;
V_88 = F_84 ( V_7 ) ;
F_85 ( ( unsigned long ) V_88 ) ;
F_46 ( V_9 ) ;
F_47 ( V_88 ) ;
F_48 ( V_9 ) ;
F_28 () ;
F_86 ( V_88 , V_89 ) ;
F_31 () ;
F_87 () ;
}
void F_88 ( struct V_7 * V_112 , struct V_7 * V_113 ,
unsigned long V_89 , struct V_3 * V_4 )
{
void * V_90 , * V_88 ;
unsigned long V_9 ;
V_90 = F_84 ( V_113 ) ;
V_88 = F_84 ( V_112 ) ;
F_85 ( ( unsigned long ) V_88 ) ;
F_46 ( V_9 ) ;
F_47 ( V_88 ) ;
F_47 ( V_90 ) ;
F_48 ( V_9 ) ;
F_28 () ;
F_89 ( V_88 , V_90 , V_89 ) ;
F_29 ( F_52 ( V_88 ) , V_89 ) ;
F_31 () ;
F_87 () ;
F_87 () ;
}
