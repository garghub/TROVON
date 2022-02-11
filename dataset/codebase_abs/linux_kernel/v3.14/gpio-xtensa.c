static inline unsigned long F_1 ( unsigned long * V_1 )
{
unsigned long V_2 ;
F_2 ( V_2 ) ;
F_3 ( * V_1 ) ;
F_4 ( * V_1 | F_5 ( V_3 ) ) ;
return V_2 ;
}
static inline void F_6 ( unsigned long V_2 , unsigned long V_1 )
{
F_4 ( V_1 ) ;
F_7 ( V_2 ) ;
}
static inline unsigned long F_1 ( unsigned long * V_1 )
{
* V_1 = 0 ;
return 0 ;
}
static inline void F_6 ( unsigned long V_2 , unsigned long V_1 )
{
}
static int F_8 ( struct V_4 * V_5 , unsigned V_6 )
{
return 1 ;
}
static int F_9 ( struct V_4 * V_5 , unsigned V_6 )
{
unsigned long V_2 , V_7 ;
T_1 V_8 ;
V_2 = F_1 ( & V_7 ) ;
__asm__ __volatile__("read_impwire %0" : "=a" (impwire));
F_6 ( V_2 , V_7 ) ;
return ! ! ( V_8 & F_5 ( V_6 ) ) ;
}
static void F_10 ( struct V_4 * V_5 , unsigned V_6 ,
int V_9 )
{
F_11 () ;
}
static int F_12 ( struct V_4 * V_5 , unsigned V_6 )
{
return 0 ;
}
static int F_13 ( struct V_4 * V_5 , unsigned V_6 )
{
unsigned long V_2 , V_7 ;
T_1 V_10 ;
V_2 = F_1 ( & V_7 ) ;
__asm__ __volatile__("rur.expstate %0" : "=a" (expstate));
F_6 ( V_2 , V_7 ) ;
return ! ! ( V_10 & F_5 ( V_6 ) ) ;
}
static void F_14 ( struct V_4 * V_5 , unsigned V_6 ,
int V_9 )
{
unsigned long V_2 , V_7 ;
T_1 V_11 = F_5 ( V_6 ) ;
T_1 V_12 = V_9 ? F_5 ( V_6 ) : 0 ;
V_2 = F_1 ( & V_7 ) ;
__asm__ __volatile__("wrmsk_expstate %0, %1"
:: "a" (val), "a" (mask));
F_6 ( V_2 , V_7 ) ;
}
static int F_15 ( struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_16 ( & V_16 ) ;
if ( V_15 )
return V_15 ;
return F_16 ( & V_17 ) ;
}
static int T_2 F_17 ( void )
{
struct V_13 * V_14 ;
V_14 = F_18 ( L_1 , 0 , NULL , 0 ) ;
if ( F_19 ( V_14 ) )
return F_20 ( V_14 ) ;
return F_21 ( & V_18 ) ;
}
