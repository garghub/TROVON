T_1 F_1 ( void )
{
return F_2 ( F_3 ( V_1 ) ,
V_2 ) ;
}
static void F_4 ( T_2 V_3 )
{
unsigned long V_4 ;
F_5 ( V_4 ) ;
asm volatile("msr mdscr_el1, %0" :: "r" (mdscr));
F_6 ( V_4 ) ;
}
static T_2 F_7 ( void )
{
T_2 V_3 ;
asm volatile("mrs %0, mdscr_el1" : "=r" (mdscr));
return V_3 ;
}
static int F_8 ( void )
{
F_9 ( L_1 , 0644 , NULL , & V_5 ) ;
return 0 ;
}
static int T_3 F_10 ( char * V_6 )
{
V_5 = false ;
return 0 ;
}
void F_11 ( enum V_7 V_8 )
{
T_2 V_3 , V_9 = 0 ;
F_12 ( F_13 () ) ;
if ( F_14 ( V_10 ) == 1 )
V_9 = V_11 ;
if ( V_8 == V_12 &&
F_14 ( V_13 ) == 1 )
V_9 |= V_14 ;
if ( V_9 && V_5 ) {
V_3 = F_7 () ;
V_3 |= V_9 ;
F_4 ( V_3 ) ;
}
}
void F_15 ( enum V_7 V_8 )
{
T_2 V_3 , V_15 = 0 ;
F_12 ( F_13 () ) ;
if ( F_16 ( V_10 ) == 0 )
V_15 = ~ V_11 ;
if ( V_8 == V_12 &&
F_16 ( V_13 ) == 0 )
V_15 &= ~ V_14 ;
if ( V_15 ) {
V_3 = F_7 () ;
V_3 &= V_15 ;
F_4 ( V_3 ) ;
}
}
static void F_17 ( void * V_16 )
{
asm volatile("msr oslar_el1, %0" : : "r" (0));
}
static int F_18 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
if ( ( V_19 & ~ V_21 ) == V_22 )
F_17 ( NULL ) ;
return V_23 ;
}
static int F_19 ( void )
{
F_20 () ;
F_21 ( F_17 , NULL , 1 ) ;
F_22 () ;
F_23 ( & V_24 ) ;
F_24 () ;
return 0 ;
}
static void F_25 ( struct V_25 * V_26 )
{
V_26 -> V_27 |= V_28 ;
}
static void F_26 ( struct V_25 * V_26 )
{
V_26 -> V_27 &= ~ V_28 ;
}
void F_27 ( struct V_29 * V_30 )
{
F_28 ( & V_31 ) ;
F_29 ( & V_30 -> V_32 , & V_29 ) ;
F_30 ( & V_31 ) ;
}
void F_31 ( struct V_29 * V_30 )
{
F_28 ( & V_31 ) ;
F_32 ( & V_30 -> V_32 ) ;
F_30 ( & V_31 ) ;
F_33 () ;
}
static int F_34 ( struct V_25 * V_26 , unsigned int V_33 )
{
struct V_29 * V_30 ;
int V_34 = V_35 ;
F_35 () ;
F_36 (hook, &step_hook, node) {
V_34 = V_30 -> V_36 ( V_26 , V_33 ) ;
if ( V_34 == V_37 )
break;
}
F_37 () ;
return V_34 ;
}
static void F_38 ( int V_38 )
{
struct V_25 * V_26 = F_39 () ;
T_4 V_39 = {
. V_40 = V_41 ,
. V_42 = 0 ,
. V_38 = V_38 ,
. V_43 = ( void V_44 * ) F_40 ( V_26 ) ,
} ;
if ( F_12 ( ! F_41 ( V_26 ) ) )
return;
if ( F_42 ( V_26 ) )
F_43 () ;
F_44 ( V_41 , & V_39 , V_45 ) ;
}
static int F_45 ( unsigned long V_46 , unsigned int V_33 ,
struct V_25 * V_26 )
{
if ( ! F_46 ( V_26 ) )
return 0 ;
if ( F_41 ( V_26 ) ) {
F_38 ( V_47 ) ;
F_47 ( V_45 ) ;
} else {
#ifdef F_48
if ( F_49 ( V_26 , V_33 ) == V_37 )
return 0 ;
#endif
if ( F_34 ( V_26 , V_33 ) == V_37 )
return 0 ;
F_50 ( L_2 ) ;
F_25 ( V_26 ) ;
}
return 0 ;
}
void F_51 ( struct V_48 * V_30 )
{
F_28 ( & V_49 ) ;
F_29 ( & V_30 -> V_32 , & V_48 ) ;
F_30 ( & V_49 ) ;
}
void F_52 ( struct V_48 * V_30 )
{
F_28 ( & V_49 ) ;
F_32 ( & V_30 -> V_32 ) ;
F_30 ( & V_49 ) ;
F_33 () ;
}
static int F_53 ( struct V_25 * V_26 , unsigned int V_33 )
{
struct V_48 * V_30 ;
int (* V_36)( struct V_25 * V_26 , unsigned int V_33 ) = NULL ;
F_35 () ;
F_36 (hook, &break_hook, node)
if ( ( V_33 & V_30 -> V_50 ) == V_30 -> V_51 )
V_36 = V_30 -> V_36 ;
F_37 () ;
return V_36 ? V_36 ( V_26 , V_33 ) : V_35 ;
}
static int F_54 ( unsigned long V_46 , unsigned int V_33 ,
struct V_25 * V_26 )
{
if ( F_41 ( V_26 ) ) {
F_38 ( V_52 ) ;
}
#ifdef F_48
else if ( ( V_33 & V_53 ) == V_54 ) {
if ( F_55 ( V_26 , V_33 ) != V_37 )
return - V_55 ;
}
#endif
else if ( F_53 ( V_26 , V_33 ) != V_37 ) {
F_56 ( L_3 ) ;
return - V_55 ;
}
return 0 ;
}
int F_57 ( struct V_25 * V_26 )
{
T_2 V_56 ;
T_5 V_57 ;
bool V_58 = false ;
void V_44 * V_59 = ( void V_44 * ) F_40 ( V_26 ) ;
if ( ! F_58 ( V_26 ) )
return - V_55 ;
if ( F_59 ( V_26 ) ) {
F_60 ( V_57 , ( T_5 V_44 * ) V_59 ) ;
V_57 = F_61 ( V_57 ) ;
if ( V_57 == V_60 ) {
F_60 ( V_57 , ( T_5 V_44 * ) ( V_59 + 2 ) ) ;
V_57 = F_61 ( V_57 ) ;
V_58 = V_57 == V_61 ;
} else {
V_58 = V_57 == V_62 ;
}
} else {
F_60 ( V_56 , ( T_2 V_44 * ) V_59 ) ;
V_56 = F_62 ( V_56 ) ;
V_58 = ( V_56 & ~ 0xf0000000 ) == V_63 ;
}
if ( ! V_58 )
return - V_55 ;
F_38 ( V_52 ) ;
return 0 ;
}
static int T_3 F_63 ( void )
{
F_64 ( V_64 , F_45 , V_41 ,
V_47 , L_4 ) ;
F_64 ( V_65 , F_54 , V_41 ,
V_52 , L_5 ) ;
return 0 ;
}
void F_47 ( struct V_66 * V_67 )
{
if ( F_65 ( F_66 ( V_67 ) , V_68 ) )
F_25 ( F_67 ( V_67 ) ) ;
}
void F_68 ( struct V_66 * V_67 )
{
if ( F_65 ( F_66 ( V_67 ) , V_68 ) )
F_26 ( F_67 ( V_67 ) ) ;
}
void F_69 ( struct V_25 * V_26 )
{
F_12 ( ! F_70 () ) ;
F_25 ( V_26 ) ;
F_4 ( F_7 () | V_69 ) ;
F_11 ( V_12 ) ;
}
void F_71 ( void )
{
F_12 ( ! F_70 () ) ;
F_4 ( F_7 () & ~ V_69 ) ;
F_15 ( V_12 ) ;
}
int F_72 ( void )
{
F_12 ( ! F_70 () ) ;
return F_7 () & V_69 ;
}
void F_73 ( struct V_66 * V_67 )
{
F_74 ( F_66 ( V_67 ) , V_68 ) ;
F_25 ( F_67 ( V_67 ) ) ;
}
void F_75 ( struct V_66 * V_67 )
{
F_76 ( F_66 ( V_67 ) , V_68 ) ;
}
