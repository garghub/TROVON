T_1 F_1 ( void )
{
return F_2 ( V_1 ) & 0xf ;
}
static void F_3 ( T_2 V_2 )
{
unsigned long V_3 ;
F_4 ( V_3 ) ;
asm volatile("msr mdscr_el1, %0" :: "r" (mdscr));
F_5 ( V_3 ) ;
}
static T_2 F_6 ( void )
{
T_2 V_2 ;
asm volatile("mrs %0, mdscr_el1" : "=r" (mdscr));
return V_2 ;
}
static int F_7 ( void )
{
F_8 ( L_1 , 0644 , NULL , & V_4 ) ;
return 0 ;
}
static int T_3 F_9 ( char * V_5 )
{
V_4 = 0 ;
return 0 ;
}
void F_10 ( enum V_6 V_7 )
{
T_2 V_2 , V_8 = 0 ;
F_11 ( F_12 () ) ;
if ( F_13 ( & F_14 ( V_9 ) ) == 1 )
V_8 = V_10 ;
if ( V_7 == V_11 &&
F_13 ( & F_14 ( V_12 ) ) == 1 )
V_8 |= V_13 ;
if ( V_8 && V_4 ) {
V_2 = F_6 () ;
V_2 |= V_8 ;
F_3 ( V_2 ) ;
}
}
void F_15 ( enum V_6 V_7 )
{
T_2 V_2 , V_14 = 0 ;
F_11 ( F_12 () ) ;
if ( F_16 ( & F_14 ( V_9 ) ) )
V_14 = ~ V_10 ;
if ( V_7 == V_11 &&
F_16 ( & F_14 ( V_12 ) ) )
V_14 &= ~ V_13 ;
if ( V_14 ) {
V_2 = F_6 () ;
V_2 &= V_14 ;
F_3 ( V_2 ) ;
}
}
static void F_17 ( void * V_15 )
{
asm volatile("msr mdscr_el1, %0" : : "r" (0));
F_18 () ;
asm volatile("msr oslar_el1, %0" : : "r" (0));
F_18 () ;
}
static int T_4 F_19 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
int V_20 = ( unsigned long ) V_19 ;
if ( V_18 == V_21 )
F_20 ( V_20 , F_17 , NULL , 1 ) ;
return V_22 ;
}
static int T_4 F_21 ( void )
{
F_22 ( F_17 , NULL , 1 ) ;
F_17 ( NULL ) ;
F_23 ( & V_23 ) ;
return 0 ;
}
static void F_24 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
V_26 = V_25 -> V_27 ;
V_26 &= ~ V_28 ;
V_26 |= V_28 ;
V_25 -> V_27 = V_26 ;
}
static void F_25 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
V_26 = V_25 -> V_27 ;
V_26 &= ~ V_28 ;
V_25 -> V_27 = V_26 ;
}
static int F_26 ( unsigned long V_29 , unsigned int V_30 ,
struct V_24 * V_25 )
{
T_5 V_31 ;
if ( ! F_27 ( V_25 ) )
return 0 ;
if ( F_28 ( V_25 ) ) {
V_31 . V_32 = V_33 ;
V_31 . V_34 = 0 ;
V_31 . V_35 = V_36 ;
V_31 . V_37 = ( void V_38 * ) F_29 ( V_25 ) ;
F_30 ( V_33 , & V_31 , V_39 ) ;
F_31 ( V_39 ) ;
} else {
F_32 ( L_2 ) ;
F_24 ( V_25 ) ;
}
return 0 ;
}
static int T_3 F_33 ( void )
{
F_34 ( V_40 , F_26 , V_33 ,
V_36 , L_3 ) ;
return 0 ;
}
void F_31 ( struct V_41 * V_42 )
{
if ( F_35 ( F_36 ( V_42 ) , V_43 ) )
F_24 ( F_37 ( V_42 ) ) ;
}
void F_38 ( struct V_41 * V_42 )
{
if ( F_35 ( F_36 ( V_42 ) , V_43 ) )
F_25 ( F_37 ( V_42 ) ) ;
}
void F_39 ( struct V_24 * V_25 )
{
F_11 ( ! F_40 () ) ;
F_24 ( V_25 ) ;
F_3 ( F_6 () | V_44 ) ;
F_10 ( V_11 ) ;
}
void F_41 ( void )
{
F_11 ( ! F_40 () ) ;
F_3 ( F_6 () & ~ V_44 ) ;
F_15 ( V_11 ) ;
}
int F_42 ( void )
{
F_11 ( ! F_40 () ) ;
return F_6 () & V_44 ;
}
void F_43 ( struct V_41 * V_42 )
{
F_44 ( F_36 ( V_42 ) , V_43 ) ;
F_24 ( F_37 ( V_42 ) ) ;
}
void F_45 ( struct V_41 * V_42 )
{
F_46 ( F_36 ( V_42 ) , V_43 ) ;
}
