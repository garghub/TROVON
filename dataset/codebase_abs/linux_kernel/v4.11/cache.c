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
F_21 ( V_72 L_22 , V_65 , V_64 , V_62 -> V_73 ) ;
V_65 = V_64 ;
}
}
F_41 ( V_61 ) ;
}
void T_2 F_42 ( void )
{
unsigned long V_74 , V_75 ;
unsigned long V_76 , V_77 ;
unsigned long V_78 ;
V_75 = F_43 ( 16 ) ;
F_1 () ;
V_75 = F_43 ( 16 ) - V_75 ;
V_76 = ( unsigned long ) ( V_79 - V_80 ) ;
V_74 = F_43 ( 16 ) ;
F_44 ( ( unsigned long ) V_80 , V_76 ) ;
V_74 = F_43 ( 16 ) - V_74 ;
F_21 ( V_81 L_23 ,
V_75 , V_76 , V_74 ) ;
V_78 = F_45 ( V_76 * V_75 / V_74 ) ;
if ( V_78 > V_14 . V_17 )
V_78 = V_14 . V_17 ;
if ( V_78 )
V_82 = V_78 ;
F_21 ( V_83 L_24 ,
V_82 / 1024 ) ;
if ( F_46 () > 1 && ! F_14 () ) {
V_78 = F_47 ( V_14 . V_21 , V_14 . V_22 ) ;
V_78 *= V_84 ;
V_78 /= F_46 () ;
goto V_85;
}
V_75 = F_43 ( 16 ) ;
F_48 () ;
V_75 = F_43 ( 16 ) - V_75 ;
V_76 = 0 ;
V_77 = ( unsigned long ) V_80 ;
V_74 = F_43 ( 16 ) ;
while ( V_77 < ( unsigned long ) V_79 ) {
F_49 ( V_77 , V_77 + V_84 ) ;
V_77 += V_84 ;
V_76 += V_84 ;
}
V_74 = F_43 ( 16 ) - V_74 ;
F_21 ( V_81 L_25 ,
V_75 , V_76 , V_74 ) ;
V_78 = F_50 ( F_46 () * V_76 * V_75 / V_74 ) ;
V_85:
if ( V_78 )
V_86 = V_78 ;
F_21 ( V_83 L_26 ,
V_86 / 1024 ) ;
}
void F_11 ( void * V_64 )
{
unsigned long V_10 ;
F_51 ( V_64 ) ;
F_52 ( V_10 ) ;
F_53 ( V_64 ) ;
F_54 ( V_10 ) ;
}
void F_55 ( void * V_87 , void * V_88 , unsigned long V_89 ,
struct V_8 * V_90 )
{
F_29 () ;
F_30 ( F_56 ( V_88 ) , V_89 ) ;
F_32 () ;
F_57 ( V_87 , V_88 ) ;
}
int F_58 ( unsigned long V_91 , unsigned long V_77 ,
unsigned long V_92 )
{
unsigned long V_10 , V_76 ;
V_76 = ( V_92 - V_77 ) ;
if ( V_76 >= V_86 ) {
F_48 () ;
return 1 ;
}
if ( F_59 ( ! V_32 ) ) {
while ( V_77 < V_92 ) {
F_52 ( V_10 ) ;
F_60 ( V_91 , 1 ) ;
F_61 ( V_77 ) ;
F_54 ( V_10 ) ;
V_77 += V_84 ;
}
return 0 ;
}
while ( V_77 < V_92 ) {
F_52 ( V_10 ) ;
F_60 ( V_91 , 1 ) ;
F_61 ( V_77 ) ;
F_62 ( V_77 ) ;
F_54 ( V_10 ) ;
V_77 += V_84 ;
}
return 0 ;
}
static void F_63 ( void * V_93 )
{
F_4 () ;
}
void F_64 ( void )
{
F_2 ( F_63 , NULL , 1 ) ;
}
static inline unsigned long F_65 ( struct V_94 * V_95 )
{
struct V_3 * V_4 ;
unsigned long V_96 = 0 ;
for ( V_4 = V_95 -> V_97 ; V_4 ; V_4 = V_4 -> V_98 )
V_96 += V_4 -> V_99 - V_4 -> V_70 ;
return V_96 ;
}
static inline T_1 * F_66 ( T_5 * V_100 , unsigned long V_64 )
{
T_1 * V_6 = NULL ;
if ( ! F_67 ( * V_100 ) ) {
T_6 * V_101 = F_68 ( V_100 , V_64 ) ;
if ( ! F_69 ( * V_101 ) ) {
T_7 * V_102 = F_70 ( V_101 , V_64 ) ;
if ( ! F_71 ( * V_102 ) )
V_6 = F_72 ( V_102 , V_64 ) ;
}
}
return V_6 ;
}
void F_73 ( struct V_94 * V_95 )
{
struct V_3 * V_4 ;
T_5 * V_100 ;
if ( F_65 ( V_95 ) >= V_82 ) {
F_64 () ;
return;
}
if ( V_95 -> V_103 == F_74 ( 3 ) ) {
for ( V_4 = V_95 -> V_97 ; V_4 ; V_4 = V_4 -> V_98 ) {
F_75 ( V_4 -> V_70 , V_4 -> V_99 ) ;
if ( ( V_4 -> V_58 & V_59 ) == 0 )
continue;
F_76 ( V_4 -> V_70 , V_4 -> V_99 ) ;
}
return;
}
V_100 = V_95 -> V_100 ;
for ( V_4 = V_95 -> V_97 ; V_4 ; V_4 = V_4 -> V_98 ) {
unsigned long V_64 ;
for ( V_64 = V_4 -> V_70 ; V_64 < V_4 -> V_99 ;
V_64 += V_84 ) {
unsigned long V_7 ;
T_1 * V_6 = F_66 ( V_100 , V_64 ) ;
if ( ! V_6 )
continue;
V_7 = F_6 ( * V_6 ) ;
if ( ! F_7 ( V_7 ) )
continue;
F_28 ( V_4 , V_64 , F_77 ( V_7 ) ) ;
}
}
}
void F_78 ( struct V_3 * V_4 ,
unsigned long V_77 , unsigned long V_92 )
{
unsigned long V_64 ;
T_5 * V_100 ;
F_79 ( ! V_4 -> V_104 -> V_103 ) ;
if ( ( V_92 - V_77 ) >= V_82 ) {
F_64 () ;
return;
}
if ( V_4 -> V_104 -> V_103 == F_74 ( 3 ) ) {
F_75 ( V_77 , V_92 ) ;
if ( V_4 -> V_58 & V_59 )
F_76 ( V_77 , V_92 ) ;
return;
}
V_100 = V_4 -> V_104 -> V_100 ;
for ( V_64 = V_77 & V_105 ; V_64 < V_92 ; V_64 += V_84 ) {
unsigned long V_7 ;
T_1 * V_6 = F_66 ( V_100 , V_64 ) ;
if ( ! V_6 )
continue;
V_7 = F_6 ( * V_6 ) ;
if ( F_7 ( V_7 ) )
F_28 ( V_4 , V_64 , F_77 ( V_7 ) ) ;
}
}
void
F_80 ( struct V_3 * V_4 , unsigned long V_56 , unsigned long V_7 )
{
F_79 ( ! V_4 -> V_104 -> V_103 ) ;
if ( F_7 ( V_7 ) ) {
F_39 ( V_4 , V_56 ) ;
F_28 ( V_4 , V_56 , F_77 ( V_7 ) ) ;
}
}
void F_81 ( void * V_89 , int V_76 )
{
unsigned long V_77 = ( unsigned long ) V_89 ;
if ( ( unsigned long ) V_76 > V_82 )
F_1 () ;
else
F_82 ( V_77 , V_77 + V_76 ) ;
}
void F_83 ( void * V_89 , int V_76 )
{
unsigned long V_77 = ( unsigned long ) V_89 ;
if ( ( unsigned long ) V_76 > V_82 )
F_1 () ;
else
F_82 ( V_77 , V_77 + V_76 ) ;
}
