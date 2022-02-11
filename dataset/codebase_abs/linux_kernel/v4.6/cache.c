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
unsigned long V_7 = F_6 ( * V_6 ) ;
struct V_8 * V_8 ;
if ( ! F_7 ( V_7 ) )
return;
V_8 = F_8 ( V_7 ) ;
if ( F_9 ( V_8 ) && F_10 ( V_9 , & V_8 -> V_10 ) ) {
F_11 ( F_12 ( V_7 ) ) ;
F_13 ( V_9 , & V_8 -> V_10 ) ;
} else if ( F_14 () )
F_11 ( F_12 ( V_7 ) ) ;
}
void
F_15 ( struct V_11 * V_12 )
{
char V_13 [ 32 ] ;
F_16 ( V_12 , L_1 ,
V_14 . V_15 / 1024 ) ;
if ( V_14 . V_16 != 1 )
snprintf ( V_13 , 32 , L_2 , V_14 . V_16 ) ;
F_16 ( V_12 , L_3 ,
V_14 . V_17 / 1024 ,
( V_14 . V_18 . V_19 ? L_4 : L_5 ) ,
( V_14 . V_18 . V_20 ? L_6 : L_7 ) ,
( ( V_14 . V_16 == 1 ) ? L_8 : V_13 ) ) ;
F_16 ( V_12 , L_9 L_10 ,
V_14 . V_21 ,
V_14 . V_22 ,
V_14 . V_23 . V_24 ? L_11 : L_7
) ;
#ifndef F_17
if ( V_25 . V_26 == 0 ) {
F_16 ( V_12 , L_12 ) ;
} else {
F_16 ( V_12 ,
L_13
L_14
L_15 ,
V_25 . V_26 , ( int ) 4096 ,
V_25 . V_26 >> 8 ,
V_25 . V_27 . V_28 ,
V_25 . V_27 . V_29 ,
V_25 . V_27 . V_30 ,
V_25 . V_31 . V_28 ,
V_25 . V_31 . V_29 ,
V_25 . V_31 . V_30
) ;
}
#endif
}
void T_2
F_18 ( void )
{
if ( F_19 ( & V_14 ) < 0 )
F_20 ( L_16 ) ;
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
printk("IT base 0x%lx stride 0x%lx count 0x%lx loop 0x%lx off_base 0x%lx off_stride 0x%lx off_count 0x%lx\n",
cache_info.it_sp_base,
cache_info.it_sp_stride,
cache_info.it_sp_count,
cache_info.it_loop,
cache_info.it_off_base,
cache_info.it_off_stride,
cache_info.it_off_count);
printk("DT base 0x%lx stride 0x%lx count 0x%lx loop 0x%lx off_base 0x%lx off_stride 0x%lx off_count 0x%lx\n",
cache_info.dt_sp_base,
cache_info.dt_sp_stride,
cache_info.dt_sp_count,
cache_info.dt_loop,
cache_info.dt_off_base,
cache_info.dt_off_stride,
cache_info.dt_off_count);
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
printk("D-TLB conf: sh %d page %d cst %d aid %d sr %d\n",
cache_info.dt_conf.tc_sh,
cache_info.dt_conf.tc_page,
cache_info.dt_conf.tc_cst,
cache_info.dt_conf.tc_aid,
cache_info.dt_conf.tc_sr);
printk("I-TLB conf: sh %d page %d cst %d aid %d sr %d\n",
cache_info.it_conf.tc_sh,
cache_info.it_conf.tc_page,
cache_info.it_conf.tc_cst,
cache_info.it_conf.tc_aid,
cache_info.it_conf.tc_sr);
#endif
V_32 = 0 ;
if ( V_14 . V_23 . V_24 == 0 || V_14 . V_23 . V_24 == 2 ) {
if ( V_14 . V_23 . V_24 == 2 )
F_21 ( V_33 L_17
L_18 ) ;
V_32 = 1 ;
}
#define F_22 ( T_3 ) (cnf.cc_line << (3 + cnf.cc_block + cnf.cc_shift))
V_34 = F_22 ( V_14 . V_18 ) ;
V_35 = F_22 ( V_14 . V_36 ) ;
#undef F_22
#ifndef F_17
if ( F_23 ( & V_25 ) < 0 ) {
memset ( & V_25 , 0 , sizeof V_25 ) ;
}
#endif
if ( ( V_37 . V_38 . V_39 & V_40 ) ==
V_41 ) {
F_21 ( V_33 L_19 ) ;
#if 0
panic("SMP kernel required to avoid non-equivalent aliasing");
#endif
}
}
void F_24 ( void )
{
int V_42 , V_43 ;
unsigned long V_44 ;
switch ( V_37 . V_45 ) {
case V_46 :
F_25 () ;
return;
case V_47 :
case V_48 :
case V_49 :
V_42 = V_50 ;
break;
case V_51 :
V_42 = V_52 ;
break;
case V_53 :
return;
default:
V_42 = V_54 ;
break;
}
F_26 ( V_42 ) ;
V_43 = F_27 ( & V_44 ) ;
if ( V_43 < 0 && V_43 != V_55 )
F_20 ( L_20 ) ;
if ( V_44 != 0 )
F_20 ( L_21 ) ;
}
static inline void
F_28 ( struct V_3 * V_4 , unsigned long V_56 ,
unsigned long V_57 )
{
F_29 () ;
F_30 ( V_57 , V_56 ) ;
if ( V_4 -> V_58 & V_59 )
F_31 ( V_57 , V_56 ) ;
F_32 () ;
}
void F_33 ( struct V_8 * V_8 )
{
struct V_60 * V_61 = F_9 ( V_8 ) ;
struct V_3 * V_62 ;
unsigned long V_63 ;
unsigned long V_64 , V_65 = 0 ;
T_4 V_66 ;
if ( V_61 && ! F_34 ( V_61 ) ) {
F_35 ( V_9 , & V_8 -> V_10 ) ;
return;
}
F_36 ( V_8 ) ;
if ( ! V_61 )
return;
V_66 = V_8 -> V_67 ;
F_37 ( V_61 ) ;
F_38 (mpnt, &mapping->i_mmap, pgoff, pgoff) {
V_63 = ( V_66 - V_62 -> V_68 ) << V_69 ;
V_64 = V_62 -> V_70 + V_63 ;
F_39 ( V_62 , V_64 ) ;
if ( V_65 == 0 || ( V_65 & ( V_71 - 1 ) )
!= ( V_64 & ( V_71 - 1 ) ) ) {
F_28 ( V_62 , V_64 , F_40 ( V_8 ) ) ;
if ( V_65 )
F_21 ( V_72 L_22 , V_65 , V_64 , V_62 -> V_73 ? ( char * ) V_62 -> V_73 -> V_74 . V_75 -> V_76 . V_77 : L_23 ) ;
V_65 = V_64 ;
}
}
F_41 ( V_61 ) ;
}
void T_2 F_42 ( void )
{
unsigned long V_78 , V_79 ;
unsigned long V_80 , V_81 ;
V_79 = F_43 ( 16 ) ;
F_1 () ;
V_79 = F_43 ( 16 ) - V_79 ;
V_80 = ( unsigned long ) ( V_82 - V_83 ) ;
V_78 = F_43 ( 16 ) ;
F_44 ( ( unsigned long ) V_83 , V_80 ) ;
V_78 = F_43 ( 16 ) - V_78 ;
F_21 ( V_84 L_24 ,
V_79 , V_80 , V_78 ) ;
V_85 = V_80 * V_79 / V_78 ;
V_85 = F_45 ( V_85 ) ;
if ( ! V_85 )
V_85 = V_86 ;
if ( V_85 > V_14 . V_17 )
V_85 = V_14 . V_17 ;
F_21 ( V_87 L_25 ,
V_85 / 1024 ) ;
V_79 = F_43 ( 16 ) ;
F_46 () ;
V_79 = F_43 ( 16 ) - V_79 ;
V_80 = V_88 ;
V_81 = ( unsigned long ) V_83 ;
V_78 = F_43 ( 16 ) ;
while ( V_81 < ( unsigned long ) V_82 ) {
F_47 ( V_81 , V_81 + V_88 ) ;
V_81 += V_88 ;
V_80 += V_88 ;
}
V_78 = F_43 ( 16 ) - V_78 ;
F_21 ( V_84 L_26 ,
V_79 , V_80 , V_78 ) ;
V_89 = V_80 * V_79 / V_78 ;
V_89 *= F_48 () ;
V_89 = F_49 ( V_89 ) ;
if ( ! V_89 )
V_89 = V_90 ;
F_21 ( V_87 L_27 ,
V_89 / 1024 ) ;
}
void F_11 ( void * V_64 )
{
unsigned long V_10 ;
F_50 ( V_64 ) ;
F_51 ( V_10 ) ;
F_52 ( V_64 ) ;
F_53 ( V_10 ) ;
}
void F_54 ( void * V_91 , void * V_92 , unsigned long V_93 ,
struct V_8 * V_94 )
{
F_29 () ;
F_30 ( F_55 ( V_92 ) , V_93 ) ;
F_32 () ;
F_56 ( V_91 , V_92 ) ;
}
int F_57 ( unsigned long V_95 , unsigned long V_81 ,
unsigned long V_96 )
{
unsigned long V_10 , V_80 ;
V_80 = ( V_96 - V_81 ) ;
if ( V_80 >= V_89 ) {
F_46 () ;
return 1 ;
}
if ( F_58 ( ! V_32 ) ) {
while ( V_81 < V_96 ) {
F_51 ( V_10 ) ;
F_59 ( V_95 , 1 ) ;
F_60 ( V_81 ) ;
F_53 ( V_10 ) ;
V_81 += V_88 ;
}
return 0 ;
}
while ( V_81 < V_96 ) {
F_51 ( V_10 ) ;
F_59 ( V_95 , 1 ) ;
F_60 ( V_81 ) ;
F_61 ( V_81 ) ;
F_53 ( V_10 ) ;
V_81 += V_88 ;
}
return 0 ;
}
static void F_62 ( void * V_97 )
{
F_4 () ;
}
void F_63 ( void )
{
F_2 ( F_62 , NULL , 1 ) ;
}
static inline unsigned long F_64 ( struct V_98 * V_99 )
{
struct V_3 * V_4 ;
unsigned long V_100 = 0 ;
for ( V_4 = V_99 -> V_101 ; V_4 ; V_4 = V_4 -> V_102 )
V_100 += V_4 -> V_103 - V_4 -> V_70 ;
return V_100 ;
}
static inline T_1 * F_65 ( T_5 * V_104 , unsigned long V_64 )
{
T_1 * V_6 = NULL ;
if ( ! F_66 ( * V_104 ) ) {
T_6 * V_105 = F_67 ( V_104 , V_64 ) ;
if ( ! F_68 ( * V_105 ) ) {
T_7 * V_106 = F_69 ( V_105 , V_64 ) ;
if ( ! F_70 ( * V_106 ) )
V_6 = F_71 ( V_106 , V_64 ) ;
}
}
return V_6 ;
}
void F_72 ( struct V_98 * V_99 )
{
struct V_3 * V_4 ;
T_5 * V_104 ;
if ( F_64 ( V_99 ) >= V_85 ) {
F_63 () ;
return;
}
if ( V_99 -> V_107 == F_73 ( 3 ) ) {
for ( V_4 = V_99 -> V_101 ; V_4 ; V_4 = V_4 -> V_102 ) {
F_74 ( V_4 -> V_70 , V_4 -> V_103 ) ;
if ( ( V_4 -> V_58 & V_59 ) == 0 )
continue;
F_75 ( V_4 -> V_70 , V_4 -> V_103 ) ;
}
return;
}
V_104 = V_99 -> V_104 ;
for ( V_4 = V_99 -> V_101 ; V_4 ; V_4 = V_4 -> V_102 ) {
unsigned long V_64 ;
for ( V_64 = V_4 -> V_70 ; V_64 < V_4 -> V_103 ;
V_64 += V_88 ) {
unsigned long V_7 ;
T_1 * V_6 = F_65 ( V_104 , V_64 ) ;
if ( ! V_6 )
continue;
V_7 = F_6 ( * V_6 ) ;
if ( ! F_7 ( V_7 ) )
continue;
F_28 ( V_4 , V_64 , F_76 ( V_7 ) ) ;
}
}
}
void
F_77 ( unsigned long V_81 , unsigned long V_96 )
{
if ( ( V_96 - V_81 ) < V_85 )
F_74 ( V_81 , V_96 ) ;
else
F_1 () ;
}
void
F_78 ( unsigned long V_81 , unsigned long V_96 )
{
if ( ( V_96 - V_81 ) < V_85 )
F_75 ( V_81 , V_96 ) ;
else
F_3 () ;
}
void F_79 ( struct V_3 * V_4 ,
unsigned long V_81 , unsigned long V_96 )
{
unsigned long V_64 ;
T_5 * V_104 ;
F_80 ( ! V_4 -> V_108 -> V_107 ) ;
if ( ( V_96 - V_81 ) >= V_85 ) {
F_63 () ;
return;
}
if ( V_4 -> V_108 -> V_107 == F_73 ( 3 ) ) {
F_74 ( V_81 , V_96 ) ;
if ( V_4 -> V_58 & V_59 )
F_75 ( V_81 , V_96 ) ;
return;
}
V_104 = V_4 -> V_108 -> V_104 ;
for ( V_64 = V_81 & V_109 ; V_64 < V_96 ; V_64 += V_88 ) {
unsigned long V_7 ;
T_1 * V_6 = F_65 ( V_104 , V_64 ) ;
if ( ! V_6 )
continue;
V_7 = F_6 ( * V_6 ) ;
if ( F_7 ( V_7 ) )
F_28 ( V_4 , V_64 , F_76 ( V_7 ) ) ;
}
}
void
F_81 ( struct V_3 * V_4 , unsigned long V_56 , unsigned long V_7 )
{
F_80 ( ! V_4 -> V_108 -> V_107 ) ;
if ( F_7 ( V_7 ) ) {
F_39 ( V_4 , V_56 ) ;
F_28 ( V_4 , V_56 , F_76 ( V_7 ) ) ;
}
}
