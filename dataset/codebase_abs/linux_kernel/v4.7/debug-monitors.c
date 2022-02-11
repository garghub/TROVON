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
F_23 () ;
F_24 ( & V_24 ) ;
F_25 () ;
return 0 ;
}
static void F_26 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
V_27 = V_26 -> V_28 ;
V_27 &= ~ V_29 ;
V_27 |= V_29 ;
V_26 -> V_28 = V_27 ;
}
static void F_27 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
V_27 = V_26 -> V_28 ;
V_27 &= ~ V_29 ;
V_26 -> V_28 = V_27 ;
}
void F_28 ( struct V_30 * V_31 )
{
F_29 ( & V_32 ) ;
F_30 ( & V_31 -> V_33 , & V_30 ) ;
F_31 ( & V_32 ) ;
}
void F_32 ( struct V_30 * V_31 )
{
F_29 ( & V_32 ) ;
F_33 ( & V_31 -> V_33 ) ;
F_31 ( & V_32 ) ;
F_34 () ;
}
static int F_35 ( struct V_25 * V_26 , unsigned int V_34 )
{
struct V_30 * V_31 ;
int V_35 = V_36 ;
F_36 () ;
F_37 (hook, &step_hook, node) {
V_35 = V_31 -> V_37 ( V_26 , V_34 ) ;
if ( V_35 == V_38 )
break;
}
F_38 () ;
return V_35 ;
}
static void F_39 ( int V_39 )
{
struct V_25 * V_26 = F_40 () ;
T_4 V_40 = {
. V_41 = V_42 ,
. V_43 = 0 ,
. V_39 = V_39 ,
. V_44 = ( void V_45 * ) F_41 ( V_26 ) ,
} ;
if ( F_12 ( ! F_42 ( V_26 ) ) )
return;
if ( F_43 ( V_26 ) )
F_44 () ;
F_45 ( V_42 , & V_40 , V_46 ) ;
}
static int F_46 ( unsigned long V_47 , unsigned int V_34 ,
struct V_25 * V_26 )
{
if ( ! F_47 ( V_26 ) )
return 0 ;
if ( F_42 ( V_26 ) ) {
F_39 ( V_48 ) ;
F_48 ( V_46 ) ;
} else {
if ( F_35 ( V_26 , V_34 ) == V_38 )
return 0 ;
F_49 ( L_2 ) ;
F_26 ( V_26 ) ;
}
return 0 ;
}
void F_50 ( struct V_49 * V_31 )
{
F_29 ( & V_50 ) ;
F_30 ( & V_31 -> V_33 , & V_49 ) ;
F_31 ( & V_50 ) ;
}
void F_51 ( struct V_49 * V_31 )
{
F_29 ( & V_50 ) ;
F_33 ( & V_31 -> V_33 ) ;
F_31 ( & V_50 ) ;
F_34 () ;
}
static int F_52 ( struct V_25 * V_26 , unsigned int V_34 )
{
struct V_49 * V_31 ;
int (* V_37)( struct V_25 * V_26 , unsigned int V_34 ) = NULL ;
F_36 () ;
F_37 (hook, &break_hook, node)
if ( ( V_34 & V_31 -> V_51 ) == V_31 -> V_52 )
V_37 = V_31 -> V_37 ;
F_38 () ;
return V_37 ? V_37 ( V_26 , V_34 ) : V_36 ;
}
static int F_53 ( unsigned long V_47 , unsigned int V_34 ,
struct V_25 * V_26 )
{
if ( F_42 ( V_26 ) ) {
F_39 ( V_53 ) ;
} else if ( F_52 ( V_26 , V_34 ) != V_38 ) {
F_49 ( L_3 ) ;
return - V_54 ;
}
return 0 ;
}
int F_54 ( struct V_25 * V_26 )
{
T_2 V_55 ;
T_5 V_56 ;
bool V_57 = false ;
void V_45 * V_58 = ( void V_45 * ) F_41 ( V_26 ) ;
if ( ! F_55 ( V_26 ) )
return - V_54 ;
if ( F_56 ( V_26 ) ) {
F_57 ( V_56 , ( T_5 V_45 * ) V_58 ) ;
V_56 = F_58 ( V_56 ) ;
if ( V_56 == V_59 ) {
F_57 ( V_56 , ( T_5 V_45 * ) ( V_58 + 2 ) ) ;
V_56 = F_58 ( V_56 ) ;
V_57 = V_56 == V_60 ;
} else {
V_57 = V_56 == V_61 ;
}
} else {
F_57 ( V_55 , ( T_2 V_45 * ) V_58 ) ;
V_55 = F_59 ( V_55 ) ;
V_57 = ( V_55 & ~ 0xf0000000 ) == V_62 ;
}
if ( ! V_57 )
return - V_54 ;
F_39 ( V_53 ) ;
return 0 ;
}
static int T_3 F_60 ( void )
{
F_61 ( V_63 , F_46 , V_42 ,
V_48 , L_4 ) ;
F_61 ( V_64 , F_53 , V_42 ,
V_53 , L_5 ) ;
return 0 ;
}
void F_48 ( struct V_65 * V_66 )
{
if ( F_62 ( F_63 ( V_66 ) , V_67 ) )
F_26 ( F_64 ( V_66 ) ) ;
}
void F_65 ( struct V_65 * V_66 )
{
if ( F_62 ( F_63 ( V_66 ) , V_67 ) )
F_27 ( F_64 ( V_66 ) ) ;
}
void F_66 ( struct V_25 * V_26 )
{
F_12 ( ! F_67 () ) ;
F_26 ( V_26 ) ;
F_4 ( F_7 () | V_68 ) ;
F_11 ( V_12 ) ;
}
void F_68 ( void )
{
F_12 ( ! F_67 () ) ;
F_4 ( F_7 () & ~ V_68 ) ;
F_15 ( V_12 ) ;
}
int F_69 ( void )
{
F_12 ( ! F_67 () ) ;
return F_7 () & V_68 ;
}
void F_70 ( struct V_65 * V_66 )
{
F_71 ( F_63 ( V_66 ) , V_67 ) ;
F_26 ( F_64 ( V_66 ) ) ;
}
void F_72 ( struct V_65 * V_66 )
{
F_73 ( F_63 ( V_66 ) , V_67 ) ;
}
