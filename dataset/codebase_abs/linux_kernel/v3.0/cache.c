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
F_28 ( V_56 , V_55 ) ;
if ( V_4 -> V_57 & V_58 )
F_29 ( V_56 , V_55 ) ;
}
void F_30 ( struct V_7 * V_7 )
{
struct V_59 * V_60 = F_9 ( V_7 ) ;
struct V_3 * V_61 ;
struct V_62 V_63 ;
unsigned long V_64 ;
unsigned long V_65 , V_66 = 0 ;
T_4 V_67 ;
if ( V_60 && ! F_31 ( V_60 ) ) {
F_32 ( V_8 , & V_7 -> V_9 ) ;
return;
}
F_11 ( V_7 ) ;
if ( ! V_60 )
return;
V_67 = V_7 -> V_68 << ( V_69 - V_70 ) ;
F_33 ( V_60 ) ;
F_34 (mpnt, &iter, &mapping->i_mmap, pgoff, pgoff) {
V_64 = ( V_67 - V_61 -> V_71 ) << V_70 ;
V_65 = V_61 -> V_72 + V_64 ;
F_35 ( V_61 , V_65 ) ;
if ( V_66 == 0 || ( V_66 & ( V_73 - 1 ) ) != ( V_65 & ( V_73 - 1 ) ) ) {
F_27 ( V_61 , V_65 , F_36 ( V_7 ) ) ;
if ( V_66 )
F_20 ( V_74 L_22 , V_66 , V_65 , V_61 -> V_75 ? ( char * ) V_61 -> V_75 -> V_76 . V_77 -> V_78 . V_79 : L_23 ) ;
V_66 = V_65 ;
}
}
F_37 ( V_60 ) ;
}
void F_38 ( void * V_7 , unsigned long V_80 )
{
unsigned long V_9 ;
extern void V_81 ( void * V_7 , unsigned long V_80 ) ;
F_39 ( V_9 ) ;
V_81 ( V_7 , V_80 ) ;
F_40 ( V_9 ) ;
}
void T_2 F_41 ( void )
{
unsigned long V_82 , V_83 ;
unsigned long V_84 ;
V_83 = F_42 ( 16 ) ;
F_1 () ;
V_83 = F_42 ( 16 ) - V_83 ;
V_84 = ( unsigned long ) ( V_85 - V_86 ) ;
V_82 = F_42 ( 16 ) ;
F_43 ( ( unsigned long ) V_86 , V_84 ) ;
V_82 = F_42 ( 16 ) - V_82 ;
F_20 ( V_87 L_24 ,
V_83 , V_84 , V_82 ) ;
V_88 = V_84 * V_83 / V_82 ;
V_88 = ( V_88 + V_89 - 1 ) & ~ ( V_89 - 1 ) ;
if ( ! V_88 )
V_88 = V_90 ;
if ( V_88 > V_13 . V_16 )
V_88 = V_13 . V_16 ;
F_20 ( V_91 L_25 , V_88 , F_44 () ) ;
}
void F_45 ( void * V_7 , unsigned long V_80 , struct V_7 * V_92 )
{
unsigned long V_9 ;
F_46 ( ( unsigned long ) V_7 ) ;
F_39 ( V_9 ) ;
F_47 ( V_7 ) ;
F_40 ( V_9 ) ;
F_38 ( V_7 , V_80 ) ;
}
void F_48 ( void * V_65 )
{
unsigned long V_9 ;
F_49 ( V_65 ) ;
F_39 ( V_9 ) ;
F_47 ( V_65 ) ;
F_40 ( V_9 ) ;
}
void F_50 ( void * V_93 , void * V_94 , unsigned long V_80 ,
struct V_7 * V_92 )
{
F_51 ( V_93 , V_94 ) ;
if ( ! F_13 () )
F_49 ( V_93 ) ;
}
void F_52 ( void * V_65 )
{
if ( F_13 () )
F_48 ( V_65 ) ;
}
void F_53 ( unsigned long V_95 , unsigned long V_96 ,
unsigned long V_97 )
{
unsigned long V_98 ;
V_98 = ( ( V_97 - ( V_96 & V_99 ) ) + ( V_100 - 1 ) ) >> V_70 ;
if ( V_98 >= 512 )
F_54 () ;
else {
unsigned long V_9 ;
F_55 ( V_95 , 1 ) ;
F_39 ( V_9 ) ;
if ( V_31 ) {
while ( V_98 -- ) {
F_56 ( V_96 ) ;
F_57 ( V_96 ) ;
V_96 += V_100 ;
}
} else {
while ( V_98 -- ) {
F_56 ( V_96 ) ;
V_96 += V_100 ;
}
}
F_40 ( V_9 ) ;
}
}
static void F_58 ( void * V_101 )
{
F_4 () ;
}
void F_59 ( void )
{
F_2 ( F_58 , NULL , 1 ) ;
}
void F_60 ( struct V_102 * V_103 )
{
#ifdef F_61
F_59 () ;
#else
F_4 () ;
#endif
}
void
F_62 ( unsigned long V_96 , unsigned long V_97 )
{
if ( ( V_97 - V_96 ) < V_88 )
F_63 ( V_96 , V_97 ) ;
else
F_1 () ;
}
void
F_64 ( unsigned long V_96 , unsigned long V_97 )
{
if ( ( V_97 - V_96 ) < V_88 )
F_65 ( V_96 , V_97 ) ;
else
F_3 () ;
}
void F_66 ( struct V_3 * V_4 ,
unsigned long V_96 , unsigned long V_97 )
{
int V_104 ;
F_67 ( ! V_4 -> V_105 -> V_106 ) ;
V_104 = F_68 ( 3 ) ;
if ( V_4 -> V_105 -> V_106 == V_104 ) {
F_62 ( V_96 , V_97 ) ;
F_64 ( V_96 , V_97 ) ;
} else {
F_59 () ;
}
}
void
F_69 ( struct V_3 * V_4 , unsigned long V_55 , unsigned long V_107 )
{
F_67 ( ! V_4 -> V_105 -> V_106 ) ;
F_35 ( V_4 , V_55 ) ;
F_27 ( V_4 , V_55 , F_36 ( F_70 ( V_107 ) ) ) ;
}
