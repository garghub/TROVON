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
if ( F_13 ( V_9 ) == 1 )
V_8 = V_10 ;
if ( V_7 == V_11 &&
F_13 ( V_12 ) == 1 )
V_8 |= V_13 ;
if ( V_8 && V_4 ) {
V_2 = F_6 () ;
V_2 |= V_8 ;
F_3 ( V_2 ) ;
}
}
void F_14 ( enum V_6 V_7 )
{
T_2 V_2 , V_14 = 0 ;
F_11 ( F_12 () ) ;
if ( F_15 ( V_9 ) == 0 )
V_14 = ~ V_10 ;
if ( V_7 == V_11 &&
F_15 ( V_12 ) == 0 )
V_14 &= ~ V_13 ;
if ( V_14 ) {
V_2 = F_6 () ;
V_2 &= V_14 ;
F_3 ( V_2 ) ;
}
}
static void F_16 ( void * V_15 )
{
asm volatile("msr oslar_el1, %0" : : "r" (0));
F_17 () ;
}
static int F_18 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
int V_20 = ( unsigned long ) V_19 ;
if ( V_18 == V_21 )
F_19 ( V_20 , F_16 , NULL , 1 ) ;
return V_22 ;
}
static int F_20 ( void )
{
F_21 ( F_16 , NULL , 1 ) ;
F_16 ( NULL ) ;
F_22 ( & V_23 ) ;
return 0 ;
}
static void F_23 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
V_26 = V_25 -> V_27 ;
V_26 &= ~ V_28 ;
V_26 |= V_28 ;
V_25 -> V_27 = V_26 ;
}
static void F_24 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
V_26 = V_25 -> V_27 ;
V_26 &= ~ V_28 ;
V_25 -> V_27 = V_26 ;
}
static int F_25 ( unsigned long V_29 , unsigned int V_30 ,
struct V_24 * V_25 )
{
T_4 V_31 ;
if ( ! F_26 ( V_25 ) )
return 0 ;
if ( F_27 ( V_25 ) ) {
V_31 . V_32 = V_33 ;
V_31 . V_34 = 0 ;
V_31 . V_35 = V_36 ;
V_31 . V_37 = ( void V_38 * ) F_28 ( V_25 ) ;
F_29 ( V_33 , & V_31 , V_39 ) ;
F_30 ( V_39 ) ;
} else {
F_31 ( L_2 ) ;
F_23 ( V_25 ) ;
}
return 0 ;
}
static int F_32 ( unsigned long V_29 , unsigned int V_30 ,
struct V_24 * V_25 )
{
T_4 V_31 ;
if ( ! F_27 ( V_25 ) )
return - V_40 ;
V_31 = ( T_4 ) {
. V_32 = V_33 ,
. V_34 = 0 ,
. V_35 = V_41 ,
. V_37 = ( void V_38 * ) F_28 ( V_25 ) ,
} ;
F_29 ( V_33 , & V_31 , V_39 ) ;
return 0 ;
}
int F_33 ( struct V_24 * V_25 )
{
T_4 V_31 ;
T_2 V_42 ;
T_5 V_43 ;
bool V_44 = false ;
void V_38 * V_45 = ( void V_38 * ) F_28 ( V_25 ) ;
if ( ! F_34 ( V_25 ) )
return - V_40 ;
if ( F_35 ( V_25 ) ) {
F_36 ( V_43 , ( T_5 V_38 * ) V_45 ) ;
V_43 = F_37 ( V_43 ) ;
if ( V_43 == V_46 ) {
F_36 ( V_43 , ( T_5 V_38 * ) ( V_45 + 2 ) ) ;
V_43 = F_37 ( V_43 ) ;
V_44 = V_43 == V_47 ;
} else {
V_44 = V_43 == V_48 ;
}
} else {
F_36 ( V_42 , ( T_2 V_38 * ) V_45 ) ;
V_42 = F_38 ( V_42 ) ;
V_44 = ( V_42 & ~ 0xf0000000 ) == V_49 ;
}
if ( ! V_44 )
return - V_40 ;
V_31 = ( T_4 ) {
. V_32 = V_33 ,
. V_34 = 0 ,
. V_35 = V_41 ,
. V_37 = V_45 ,
} ;
F_29 ( V_33 , & V_31 , V_39 ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
F_40 ( V_50 , F_25 , V_33 ,
V_36 , L_3 ) ;
F_40 ( V_51 , F_32 , V_33 ,
V_41 , L_4 ) ;
return 0 ;
}
void F_30 ( struct V_52 * V_53 )
{
if ( F_41 ( F_42 ( V_53 ) , V_54 ) )
F_23 ( F_43 ( V_53 ) ) ;
}
void F_44 ( struct V_52 * V_53 )
{
if ( F_41 ( F_42 ( V_53 ) , V_54 ) )
F_24 ( F_43 ( V_53 ) ) ;
}
void F_45 ( struct V_24 * V_25 )
{
F_11 ( ! F_46 () ) ;
F_23 ( V_25 ) ;
F_3 ( F_6 () | V_55 ) ;
F_10 ( V_11 ) ;
}
void F_47 ( void )
{
F_11 ( ! F_46 () ) ;
F_3 ( F_6 () & ~ V_55 ) ;
F_14 ( V_11 ) ;
}
int F_48 ( void )
{
F_11 ( ! F_46 () ) ;
return F_6 () & V_55 ;
}
void F_49 ( struct V_52 * V_53 )
{
F_50 ( F_42 ( V_53 ) , V_54 ) ;
F_23 ( F_43 ( V_53 ) ) ;
}
void F_51 ( struct V_52 * V_53 )
{
F_52 ( F_42 ( V_53 ) , V_54 ) ;
}
