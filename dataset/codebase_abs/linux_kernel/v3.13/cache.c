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
V_66 = V_8 -> V_67 << ( V_68 - V_69 ) ;
F_37 ( V_61 ) ;
F_38 (mpnt, &mapping->i_mmap, pgoff, pgoff) {
V_63 = ( V_66 - V_62 -> V_70 ) << V_69 ;
V_64 = V_62 -> V_71 + V_63 ;
F_39 ( V_62 , V_64 ) ;
if ( V_65 == 0 || ( V_65 & ( V_72 - 1 ) ) != ( V_64 & ( V_72 - 1 ) ) ) {
F_28 ( V_62 , V_64 , F_40 ( V_8 ) ) ;
if ( V_65 )
F_21 ( V_73 L_22 , V_65 , V_64 , V_62 -> V_74 ? ( char * ) V_62 -> V_74 -> V_75 . V_76 -> V_77 . V_78 : L_23 ) ;
V_65 = V_64 ;
}
}
F_41 ( V_61 ) ;
}
void T_2 F_42 ( void )
{
unsigned long V_79 , V_80 ;
unsigned long V_81 ;
V_80 = F_43 ( 16 ) ;
F_1 () ;
V_80 = F_43 ( 16 ) - V_80 ;
V_81 = ( unsigned long ) ( V_82 - V_83 ) ;
V_79 = F_43 ( 16 ) ;
F_44 ( ( unsigned long ) V_83 , V_81 ) ;
V_79 = F_43 ( 16 ) - V_79 ;
F_21 ( V_84 L_24 ,
V_80 , V_81 , V_79 ) ;
V_85 = V_81 * V_80 / V_79 ;
V_85 = ( V_85 + V_86 - 1 ) & ~ ( V_86 - 1 ) ;
if ( ! V_85 )
V_85 = V_87 ;
if ( V_85 > V_14 . V_17 )
V_85 = V_14 . V_17 ;
F_21 ( V_88 L_25 , V_85 , F_45 () ) ;
}
void F_11 ( void * V_64 )
{
unsigned long V_10 ;
F_46 ( V_64 ) ;
F_47 ( V_10 ) ;
F_48 ( V_64 ) ;
F_49 ( V_10 ) ;
}
void F_50 ( struct V_89 * V_90 , unsigned long V_64 )
{
unsigned long V_10 ;
F_47 ( V_10 ) ;
F_51 ( V_90 -> V_91 , 1 ) ;
F_52 ( V_64 ) ;
F_53 ( V_64 ) ;
F_49 ( V_10 ) ;
}
void F_54 ( unsigned long V_92 , unsigned long V_93 ,
unsigned long V_94 )
{
unsigned long V_95 ;
V_95 = ( ( V_94 - ( V_93 & V_96 ) ) + ( V_97 - 1 ) ) >> V_69 ;
if ( V_95 >= 512 )
F_55 () ;
else {
unsigned long V_10 ;
F_47 ( V_10 ) ;
F_51 ( V_92 , 1 ) ;
if ( V_32 ) {
while ( V_95 -- ) {
F_52 ( V_93 ) ;
F_53 ( V_93 ) ;
V_93 += V_97 ;
}
} else {
while ( V_95 -- ) {
F_52 ( V_93 ) ;
V_93 += V_97 ;
}
}
F_49 ( V_10 ) ;
}
}
static void F_56 ( void * V_98 )
{
F_4 () ;
}
void F_57 ( void )
{
F_2 ( F_56 , NULL , 1 ) ;
}
static inline unsigned long F_58 ( struct V_89 * V_90 )
{
struct V_3 * V_4 ;
unsigned long V_99 = 0 ;
for ( V_4 = V_90 -> V_100 ; V_4 ; V_4 = V_4 -> V_101 )
V_99 += V_4 -> V_102 - V_4 -> V_71 ;
return V_99 ;
}
static inline T_1 * F_59 ( T_5 * V_103 , unsigned long V_64 )
{
T_1 * V_6 = NULL ;
if ( ! F_60 ( * V_103 ) ) {
T_6 * V_104 = F_61 ( V_103 , V_64 ) ;
if ( ! F_62 ( * V_104 ) ) {
T_7 * V_105 = F_63 ( V_104 , V_64 ) ;
if ( ! F_64 ( * V_105 ) )
V_6 = F_65 ( V_105 , V_64 ) ;
}
}
return V_6 ;
}
void F_66 ( struct V_89 * V_90 )
{
struct V_3 * V_4 ;
T_5 * V_103 ;
if ( F_58 ( V_90 ) >= V_85 ) {
F_57 () ;
return;
}
if ( V_90 -> V_91 == F_67 ( 3 ) ) {
for ( V_4 = V_90 -> V_100 ; V_4 ; V_4 = V_4 -> V_101 ) {
F_68 ( V_4 -> V_71 , V_4 -> V_102 ) ;
if ( ( V_4 -> V_58 & V_59 ) == 0 )
continue;
F_69 ( V_4 -> V_71 , V_4 -> V_102 ) ;
}
return;
}
V_103 = V_90 -> V_103 ;
for ( V_4 = V_90 -> V_100 ; V_4 ; V_4 = V_4 -> V_101 ) {
unsigned long V_64 ;
for ( V_64 = V_4 -> V_71 ; V_64 < V_4 -> V_102 ;
V_64 += V_97 ) {
unsigned long V_7 ;
T_1 * V_6 = F_59 ( V_103 , V_64 ) ;
if ( ! V_6 )
continue;
V_7 = F_6 ( * V_6 ) ;
if ( ! F_7 ( V_7 ) )
continue;
F_28 ( V_4 , V_64 , F_70 ( V_7 ) ) ;
}
}
}
void
F_71 ( unsigned long V_93 , unsigned long V_94 )
{
if ( ( V_94 - V_93 ) < V_85 )
F_68 ( V_93 , V_94 ) ;
else
F_1 () ;
}
void
F_72 ( unsigned long V_93 , unsigned long V_94 )
{
if ( ( V_94 - V_93 ) < V_85 )
F_69 ( V_93 , V_94 ) ;
else
F_3 () ;
}
void F_73 ( struct V_3 * V_4 ,
unsigned long V_93 , unsigned long V_94 )
{
unsigned long V_64 ;
T_5 * V_103 ;
F_74 ( ! V_4 -> V_106 -> V_91 ) ;
if ( ( V_94 - V_93 ) >= V_85 ) {
F_57 () ;
return;
}
if ( V_4 -> V_106 -> V_91 == F_67 ( 3 ) ) {
F_68 ( V_93 , V_94 ) ;
if ( V_4 -> V_58 & V_59 )
F_69 ( V_93 , V_94 ) ;
return;
}
V_103 = V_4 -> V_106 -> V_103 ;
for ( V_64 = V_93 & V_96 ; V_64 < V_94 ; V_64 += V_97 ) {
unsigned long V_7 ;
T_1 * V_6 = F_59 ( V_103 , V_64 ) ;
if ( ! V_6 )
continue;
V_7 = F_6 ( * V_6 ) ;
if ( F_7 ( V_7 ) )
F_28 ( V_4 , V_64 , F_70 ( V_7 ) ) ;
}
}
void
F_75 ( struct V_3 * V_4 , unsigned long V_56 , unsigned long V_7 )
{
F_74 ( ! V_4 -> V_106 -> V_91 ) ;
if ( F_7 ( V_7 ) ) {
F_39 ( V_4 , V_56 ) ;
F_28 ( V_4 , V_56 , F_70 ( V_7 ) ) ;
}
}
void F_76 ( struct V_8 * V_8 , unsigned long V_107 )
{
void * V_108 ;
unsigned long V_10 ;
V_108 = F_77 ( V_8 ) ;
F_78 ( ( unsigned long ) V_108 ) ;
F_47 ( V_10 ) ;
F_48 ( V_108 ) ;
F_49 ( V_10 ) ;
F_29 () ;
F_79 ( V_108 , V_107 ) ;
F_32 () ;
F_80 () ;
}
void F_81 ( struct V_8 * V_109 , struct V_8 * V_110 ,
unsigned long V_107 , struct V_3 * V_4 )
{
void * V_111 , * V_108 ;
unsigned long V_10 ;
V_111 = F_77 ( V_110 ) ;
V_108 = F_77 ( V_109 ) ;
F_78 ( ( unsigned long ) V_108 ) ;
F_47 ( V_10 ) ;
F_48 ( V_108 ) ;
F_48 ( V_111 ) ;
F_49 ( V_10 ) ;
F_29 () ;
F_82 ( V_108 , V_111 , V_107 ) ;
F_30 ( F_83 ( V_108 ) , V_107 ) ;
F_32 () ;
F_80 () ;
F_80 () ;
}
