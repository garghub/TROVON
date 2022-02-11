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
if ( ( V_18 & ~ V_21 ) == V_22 )
F_18 ( V_20 , F_16 , NULL , 1 ) ;
return V_23 ;
}
static int F_19 ( void )
{
F_20 () ;
F_21 ( F_16 , NULL , 1 ) ;
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
}
static int F_34 ( struct V_25 * V_26 , unsigned int V_34 )
{
struct V_30 * V_31 ;
int V_35 = V_36 ;
F_35 ( & V_32 ) ;
F_36 (hook, &step_hook, node) {
V_35 = V_31 -> V_37 ( V_26 , V_34 ) ;
if ( V_35 == V_38 )
break;
}
F_37 ( & V_32 ) ;
return V_35 ;
}
static int F_38 ( unsigned long V_39 , unsigned int V_34 ,
struct V_25 * V_26 )
{
T_4 V_40 ;
if ( ! F_39 ( V_26 ) )
return 0 ;
if ( F_40 ( V_26 ) ) {
V_40 . V_41 = V_42 ;
V_40 . V_43 = 0 ;
V_40 . V_44 = V_45 ;
V_40 . V_46 = ( void V_47 * ) F_41 ( V_26 ) ;
F_42 ( V_42 , & V_40 , V_48 ) ;
F_43 ( V_48 ) ;
} else {
if ( F_34 ( V_26 , V_34 ) == V_38 )
return 0 ;
F_44 ( L_2 ) ;
F_26 ( V_26 ) ;
}
return 0 ;
}
void F_45 ( struct V_49 * V_31 )
{
F_46 ( & V_50 ) ;
F_47 ( & V_31 -> V_33 , & V_49 ) ;
F_48 ( & V_50 ) ;
}
void F_49 ( struct V_49 * V_31 )
{
F_46 ( & V_50 ) ;
F_50 ( & V_31 -> V_33 ) ;
F_48 ( & V_50 ) ;
F_51 () ;
}
static int F_52 ( struct V_25 * V_26 , unsigned int V_34 )
{
struct V_49 * V_31 ;
int (* V_37)( struct V_25 * V_26 , unsigned int V_34 ) = NULL ;
F_53 () ;
F_54 (hook, &break_hook, node)
if ( ( V_34 & V_31 -> V_51 ) == V_31 -> V_52 )
V_37 = V_31 -> V_37 ;
F_55 () ;
return V_37 ? V_37 ( V_26 , V_34 ) : V_36 ;
}
static int F_56 ( unsigned long V_39 , unsigned int V_34 ,
struct V_25 * V_26 )
{
T_4 V_40 ;
if ( F_40 ( V_26 ) ) {
V_40 = ( T_4 ) {
. V_41 = V_42 ,
. V_43 = 0 ,
. V_44 = V_53 ,
. V_46 = ( void V_47 * ) F_41 ( V_26 ) ,
} ;
F_42 ( V_42 , & V_40 , V_48 ) ;
} else if ( F_52 ( V_26 , V_34 ) != V_38 ) {
F_44 ( L_3 ) ;
return - V_54 ;
}
return 0 ;
}
int F_57 ( struct V_25 * V_26 )
{
T_4 V_40 ;
T_2 V_55 ;
T_5 V_56 ;
bool V_57 = false ;
void V_47 * V_58 = ( void V_47 * ) F_41 ( V_26 ) ;
if ( ! F_58 ( V_26 ) )
return - V_54 ;
if ( F_59 ( V_26 ) ) {
F_60 ( V_56 , ( T_5 V_47 * ) V_58 ) ;
V_56 = F_61 ( V_56 ) ;
if ( V_56 == V_59 ) {
F_60 ( V_56 , ( T_5 V_47 * ) ( V_58 + 2 ) ) ;
V_56 = F_61 ( V_56 ) ;
V_57 = V_56 == V_60 ;
} else {
V_57 = V_56 == V_61 ;
}
} else {
F_60 ( V_55 , ( T_2 V_47 * ) V_58 ) ;
V_55 = F_62 ( V_55 ) ;
V_57 = ( V_55 & ~ 0xf0000000 ) == V_62 ;
}
if ( ! V_57 )
return - V_54 ;
V_40 = ( T_4 ) {
. V_41 = V_42 ,
. V_43 = 0 ,
. V_44 = V_53 ,
. V_46 = V_58 ,
} ;
F_42 ( V_42 , & V_40 , V_48 ) ;
return 0 ;
}
static int T_3 F_63 ( void )
{
F_64 ( V_63 , F_38 , V_42 ,
V_45 , L_4 ) ;
F_64 ( V_64 , F_56 , V_42 ,
V_53 , L_5 ) ;
return 0 ;
}
void F_43 ( struct V_65 * V_66 )
{
if ( F_65 ( F_66 ( V_66 ) , V_67 ) )
F_26 ( F_67 ( V_66 ) ) ;
}
void F_68 ( struct V_65 * V_66 )
{
if ( F_65 ( F_66 ( V_66 ) , V_67 ) )
F_27 ( F_67 ( V_66 ) ) ;
}
void F_69 ( struct V_25 * V_26 )
{
F_11 ( ! F_70 () ) ;
F_26 ( V_26 ) ;
F_3 ( F_6 () | V_68 ) ;
F_10 ( V_11 ) ;
}
void F_71 ( void )
{
F_11 ( ! F_70 () ) ;
F_3 ( F_6 () & ~ V_68 ) ;
F_14 ( V_11 ) ;
}
int F_72 ( void )
{
F_11 ( ! F_70 () ) ;
return F_6 () & V_68 ;
}
void F_73 ( struct V_65 * V_66 )
{
F_74 ( F_66 ( V_66 ) , V_67 ) ;
F_26 ( F_67 ( V_66 ) ) ;
}
void F_75 ( struct V_65 * V_66 )
{
F_76 ( F_66 ( V_66 ) , V_67 ) ;
}
