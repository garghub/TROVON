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
}
static int F_17 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
int V_20 = ( unsigned long ) V_19 ;
if ( V_18 == V_21 )
F_18 ( V_20 , F_16 , NULL , 1 ) ;
return V_22 ;
}
static int F_19 ( void )
{
F_20 () ;
F_21 ( F_16 , NULL , 1 ) ;
F_22 () ;
F_23 () ;
F_24 ( & V_23 ) ;
F_25 () ;
return 0 ;
}
static void F_26 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
V_26 = V_25 -> V_27 ;
V_26 &= ~ V_28 ;
V_26 |= V_28 ;
V_25 -> V_27 = V_26 ;
}
static void F_27 ( struct V_24 * V_25 )
{
unsigned long V_26 ;
V_26 = V_25 -> V_27 ;
V_26 &= ~ V_28 ;
V_25 -> V_27 = V_26 ;
}
void F_28 ( struct V_29 * V_30 )
{
F_29 ( & V_31 ) ;
F_30 ( & V_30 -> V_32 , & V_29 ) ;
F_31 ( & V_31 ) ;
}
void F_32 ( struct V_29 * V_30 )
{
F_29 ( & V_31 ) ;
F_33 ( & V_30 -> V_32 ) ;
F_31 ( & V_31 ) ;
}
static int F_34 ( struct V_24 * V_25 , unsigned int V_33 )
{
struct V_29 * V_30 ;
int V_34 = V_35 ;
F_35 ( & V_31 ) ;
F_36 (hook, &step_hook, node) {
V_34 = V_30 -> V_36 ( V_25 , V_33 ) ;
if ( V_34 == V_37 )
break;
}
F_37 ( & V_31 ) ;
return V_34 ;
}
static int F_38 ( unsigned long V_38 , unsigned int V_33 ,
struct V_24 * V_25 )
{
T_4 V_39 ;
if ( ! F_39 ( V_25 ) )
return 0 ;
if ( F_40 ( V_25 ) ) {
V_39 . V_40 = V_41 ;
V_39 . V_42 = 0 ;
V_39 . V_43 = V_44 ;
V_39 . V_45 = ( void V_46 * ) F_41 ( V_25 ) ;
F_42 ( V_41 , & V_39 , V_47 ) ;
F_43 ( V_47 ) ;
} else {
if ( F_34 ( V_25 , V_33 ) == V_37 )
return 0 ;
F_44 ( L_2 ) ;
F_26 ( V_25 ) ;
}
return 0 ;
}
void F_45 ( struct V_48 * V_30 )
{
F_29 ( & V_49 ) ;
F_30 ( & V_30 -> V_32 , & V_48 ) ;
F_31 ( & V_49 ) ;
}
void F_46 ( struct V_48 * V_30 )
{
F_29 ( & V_49 ) ;
F_33 ( & V_30 -> V_32 ) ;
F_31 ( & V_49 ) ;
}
static int F_47 ( struct V_24 * V_25 , unsigned int V_33 )
{
struct V_48 * V_30 ;
int (* V_36)( struct V_24 * V_25 , unsigned int V_33 ) = NULL ;
F_35 ( & V_49 ) ;
F_36 (hook, &break_hook, node)
if ( ( V_33 & V_30 -> V_50 ) == V_30 -> V_51 )
V_36 = V_30 -> V_36 ;
F_37 ( & V_49 ) ;
return V_36 ? V_36 ( V_25 , V_33 ) : V_35 ;
}
static int F_48 ( unsigned long V_38 , unsigned int V_33 ,
struct V_24 * V_25 )
{
T_4 V_39 ;
if ( F_40 ( V_25 ) ) {
V_39 = ( T_4 ) {
. V_40 = V_41 ,
. V_42 = 0 ,
. V_43 = V_52 ,
. V_45 = ( void V_46 * ) F_41 ( V_25 ) ,
} ;
F_42 ( V_41 , & V_39 , V_47 ) ;
} else if ( F_47 ( V_25 , V_33 ) != V_37 ) {
F_44 ( L_3 ) ;
return - V_53 ;
}
return 0 ;
}
int F_49 ( struct V_24 * V_25 )
{
T_4 V_39 ;
T_2 V_54 ;
T_5 V_55 ;
bool V_56 = false ;
void V_46 * V_57 = ( void V_46 * ) F_41 ( V_25 ) ;
if ( ! F_50 ( V_25 ) )
return - V_53 ;
if ( F_51 ( V_25 ) ) {
F_52 ( V_55 , ( T_5 V_46 * ) V_57 ) ;
V_55 = F_53 ( V_55 ) ;
if ( V_55 == V_58 ) {
F_52 ( V_55 , ( T_5 V_46 * ) ( V_57 + 2 ) ) ;
V_55 = F_53 ( V_55 ) ;
V_56 = V_55 == V_59 ;
} else {
V_56 = V_55 == V_60 ;
}
} else {
F_52 ( V_54 , ( T_2 V_46 * ) V_57 ) ;
V_54 = F_54 ( V_54 ) ;
V_56 = ( V_54 & ~ 0xf0000000 ) == V_61 ;
}
if ( ! V_56 )
return - V_53 ;
V_39 = ( T_4 ) {
. V_40 = V_41 ,
. V_42 = 0 ,
. V_43 = V_52 ,
. V_45 = V_57 ,
} ;
F_42 ( V_41 , & V_39 , V_47 ) ;
return 0 ;
}
static int T_3 F_55 ( void )
{
F_56 ( V_62 , F_38 , V_41 ,
V_44 , L_4 ) ;
F_56 ( V_63 , F_48 , V_41 ,
V_52 , L_5 ) ;
return 0 ;
}
void F_43 ( struct V_64 * V_65 )
{
if ( F_57 ( F_58 ( V_65 ) , V_66 ) )
F_26 ( F_59 ( V_65 ) ) ;
}
void F_60 ( struct V_64 * V_65 )
{
if ( F_57 ( F_58 ( V_65 ) , V_66 ) )
F_27 ( F_59 ( V_65 ) ) ;
}
void F_61 ( struct V_24 * V_25 )
{
F_11 ( ! F_62 () ) ;
F_26 ( V_25 ) ;
F_3 ( F_6 () | V_67 ) ;
F_10 ( V_11 ) ;
}
void F_63 ( void )
{
F_11 ( ! F_62 () ) ;
F_3 ( F_6 () & ~ V_67 ) ;
F_14 ( V_11 ) ;
}
int F_64 ( void )
{
F_11 ( ! F_62 () ) ;
return F_6 () & V_67 ;
}
void F_65 ( struct V_64 * V_65 )
{
F_66 ( F_58 ( V_65 ) , V_66 ) ;
F_26 ( F_59 ( V_65 ) ) ;
}
void F_67 ( struct V_64 * V_65 )
{
F_68 ( F_58 ( V_65 ) , V_66 ) ;
}
