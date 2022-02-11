static int F_1 ( void * V_1 , T_1 * V_2 )
{
int V_3 ;
unsigned long V_4 = 0 ;
F_2 (cpu) {
struct V_5 * V_6 ;
T_2 * V_7 ;
V_6 = & F_3 ( V_8 , V_3 ) ;
V_7 = ( void * ) V_6 + ( unsigned long ) V_1 ;
V_4 += F_4 ( V_7 ) ;
}
* V_2 = V_4 ;
return 0 ;
}
static int T_3 F_5 ( void )
{
struct V_9 * V_10 , * V_11 ;
if ( ! V_12 )
return - V_13 ;
V_11 = F_6 ( L_1 , V_12 ) ;
if ( ! V_11 )
return - V_14 ;
#define F_7 ( T_4 ) \
offsetof(struct mips_fpu_emulator_stats, m)
#define F_8 ( T_4 ) \
do { \
d = debugfs_create_file(#m , S_IRUGO, dir, \
(void *)FPU_EMU_STAT_OFFSET(m), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
F_8 ( V_15 ) ;
F_8 ( V_16 ) ;
F_8 ( V_17 ) ;
F_8 ( V_18 ) ;
F_8 ( V_19 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
F_8 ( V_22 ) ;
F_8 ( V_23 ) ;
F_8 ( V_24 ) ;
F_8 ( V_25 ) ;
return 0 ;
}
