static inline long F_1 ( long V_1 , long V_2 , long V_3 , long V_4 ,
long V_5 )
{
register long T_1 V_6 ( L_1 ) = V_1 ;
register long T_2 V_6 ( L_2 ) = V_2 ;
register long T_3 V_6 ( L_3 ) = V_3 ;
register long T_4 V_6 ( L_4 ) = V_4 ;
register long T_5 V_6 ( L_5 ) = V_5 ;
if ( ! V_7 )
return - V_8 ;
__asm__ __volatile__("trapa #0x3f":"=z"(r0)
:"0"(r0), "r"(r4), "r"(r5), "r"(r6), "r"(r7)
:"memory");
return T_1 ;
}
void F_2 ( const char * V_9 , unsigned int V_10 )
{
F_1 ( V_11 , ( long ) V_9 , ( long ) V_10 , 0 , 0 ) ;
}
void F_3 ( void )
{
F_1 ( V_12 , 0 , 0 , 0 , 0 ) ;
}
void F_4 ( unsigned char * V_13 )
{
F_1 ( V_14 , 0 , ( long ) V_13 , 0 , 0 ) ;
}
void F_5 ( unsigned int V_15 )
{
F_1 ( V_16 , V_15 , 0 , 0 , 0 ) ;
}
void F_6 ( void )
{
unsigned long V_17 ;
if ( F_7 ( V_7 ) )
return;
__asm__ __volatile__ ("stc vbr, %0" : "=r" (vbr));
if ( V_17 ) {
V_7 = ( void * ) ( V_17 + 0x100 ) ;
F_8 ( V_18 L_6 ,
V_7 ) ;
} else
F_8 ( V_18 L_7 ) ;
}
void F_9 ( void )
{
if ( V_7 )
__asm__ __volatile__ (
"ldc %0, vbr"
:
: "r" (((unsigned long) gdb_vbr_vector) - 0x100)
: "memory"
);
}
static void F_10 ( struct V_19 * V_20 , const char * V_21 ,
unsigned V_22 )
{
F_2 ( V_21 , V_22 ) ;
}
static int T_6 F_11 ( struct V_19 * V_20 , char * V_23 )
{
int V_24 = V_25 | V_26 | V_27 ;
V_24 |= V_28 | V_29 | 0 ;
V_20 -> V_24 = V_24 ;
return 0 ;
}
static int T_6 F_12 ( char * V_9 )
{
int V_30 = 0 ;
if ( ! V_9 )
return 0 ;
if ( strstr ( V_9 , L_8 ) )
V_30 = 1 ;
if ( ! strncmp ( V_9 , L_9 , 4 ) )
V_31 = & V_32 ;
if ( F_13 ( V_31 ) ) {
if ( V_30 )
V_31 -> V_33 &= ~ V_34 ;
else
V_31 -> V_33 |= V_34 ;
F_14 ( V_31 ) ;
}
return 0 ;
}
