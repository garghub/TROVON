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
int V_21 = ( unsigned long ) V_20 ;
if ( ( V_19 & ~ V_22 ) == V_23 )
F_19 ( V_21 , F_17 , NULL , 1 ) ;
return V_24 ;
}
static int F_20 ( void )
{
F_21 () ;
F_22 ( F_17 , NULL , 1 ) ;
F_23 () ;
F_24 () ;
F_25 ( & V_25 ) ;
F_26 () ;
return 0 ;
}
static void F_27 ( struct V_26 * V_27 )
{
unsigned long V_28 ;
V_28 = V_27 -> V_29 ;
V_28 &= ~ V_30 ;
V_28 |= V_30 ;
V_27 -> V_29 = V_28 ;
}
static void F_28 ( struct V_26 * V_27 )
{
unsigned long V_28 ;
V_28 = V_27 -> V_29 ;
V_28 &= ~ V_30 ;
V_27 -> V_29 = V_28 ;
}
void F_29 ( struct V_31 * V_32 )
{
F_30 ( & V_33 ) ;
F_31 ( & V_32 -> V_34 , & V_31 ) ;
F_32 ( & V_33 ) ;
}
void F_33 ( struct V_31 * V_32 )
{
F_30 ( & V_33 ) ;
F_34 ( & V_32 -> V_34 ) ;
F_32 ( & V_33 ) ;
}
static int F_35 ( struct V_26 * V_27 , unsigned int V_35 )
{
struct V_31 * V_32 ;
int V_36 = V_37 ;
F_36 ( & V_33 ) ;
F_37 (hook, &step_hook, node) {
V_36 = V_32 -> V_38 ( V_27 , V_35 ) ;
if ( V_36 == V_39 )
break;
}
F_38 ( & V_33 ) ;
return V_36 ;
}
static int F_39 ( unsigned long V_40 , unsigned int V_35 ,
struct V_26 * V_27 )
{
T_4 V_41 ;
if ( ! F_40 ( V_27 ) )
return 0 ;
if ( F_41 ( V_27 ) ) {
V_41 . V_42 = V_43 ;
V_41 . V_44 = 0 ;
V_41 . V_45 = V_46 ;
V_41 . V_47 = ( void V_48 * ) F_42 ( V_27 ) ;
F_43 ( V_43 , & V_41 , V_49 ) ;
F_44 ( V_49 ) ;
} else {
if ( F_35 ( V_27 , V_35 ) == V_39 )
return 0 ;
F_45 ( L_2 ) ;
F_27 ( V_27 ) ;
}
return 0 ;
}
void F_46 ( struct V_50 * V_32 )
{
F_47 ( & V_51 ) ;
F_48 ( & V_32 -> V_34 , & V_50 ) ;
F_49 ( & V_51 ) ;
}
void F_50 ( struct V_50 * V_32 )
{
F_47 ( & V_51 ) ;
F_51 ( & V_32 -> V_34 ) ;
F_49 ( & V_51 ) ;
F_52 () ;
}
static int F_53 ( struct V_26 * V_27 , unsigned int V_35 )
{
struct V_50 * V_32 ;
int (* V_38)( struct V_26 * V_27 , unsigned int V_35 ) = NULL ;
F_54 () ;
F_55 (hook, &break_hook, node)
if ( ( V_35 & V_32 -> V_52 ) == V_32 -> V_53 )
V_38 = V_32 -> V_38 ;
F_56 () ;
return V_38 ? V_38 ( V_27 , V_35 ) : V_37 ;
}
static int F_57 ( unsigned long V_40 , unsigned int V_35 ,
struct V_26 * V_27 )
{
T_4 V_41 ;
if ( F_41 ( V_27 ) ) {
V_41 = ( T_4 ) {
. V_42 = V_43 ,
. V_44 = 0 ,
. V_45 = V_54 ,
. V_47 = ( void V_48 * ) F_42 ( V_27 ) ,
} ;
F_43 ( V_43 , & V_41 , V_49 ) ;
} else if ( F_53 ( V_27 , V_35 ) != V_39 ) {
F_45 ( L_3 ) ;
return - V_55 ;
}
return 0 ;
}
int F_58 ( struct V_26 * V_27 )
{
T_4 V_41 ;
T_2 V_56 ;
T_5 V_57 ;
bool V_58 = false ;
void V_48 * V_59 = ( void V_48 * ) F_42 ( V_27 ) ;
if ( ! F_59 ( V_27 ) )
return - V_55 ;
if ( F_60 ( V_27 ) ) {
F_61 ( V_57 , ( T_5 V_48 * ) V_59 ) ;
V_57 = F_62 ( V_57 ) ;
if ( V_57 == V_60 ) {
F_61 ( V_57 , ( T_5 V_48 * ) ( V_59 + 2 ) ) ;
V_57 = F_62 ( V_57 ) ;
V_58 = V_57 == V_61 ;
} else {
V_58 = V_57 == V_62 ;
}
} else {
F_61 ( V_56 , ( T_2 V_48 * ) V_59 ) ;
V_56 = F_63 ( V_56 ) ;
V_58 = ( V_56 & ~ 0xf0000000 ) == V_63 ;
}
if ( ! V_58 )
return - V_55 ;
V_41 = ( T_4 ) {
. V_42 = V_43 ,
. V_44 = 0 ,
. V_45 = V_54 ,
. V_47 = V_59 ,
} ;
F_43 ( V_43 , & V_41 , V_49 ) ;
return 0 ;
}
static int T_3 F_64 ( void )
{
F_65 ( V_64 , F_39 , V_43 ,
V_46 , L_4 ) ;
F_65 ( V_65 , F_57 , V_43 ,
V_54 , L_5 ) ;
return 0 ;
}
void F_44 ( struct V_66 * V_67 )
{
if ( F_66 ( F_67 ( V_67 ) , V_68 ) )
F_27 ( F_68 ( V_67 ) ) ;
}
void F_69 ( struct V_66 * V_67 )
{
if ( F_66 ( F_67 ( V_67 ) , V_68 ) )
F_28 ( F_68 ( V_67 ) ) ;
}
void F_70 ( struct V_26 * V_27 )
{
F_12 ( ! F_71 () ) ;
F_27 ( V_27 ) ;
F_4 ( F_7 () | V_69 ) ;
F_11 ( V_12 ) ;
}
void F_72 ( void )
{
F_12 ( ! F_71 () ) ;
F_4 ( F_7 () & ~ V_69 ) ;
F_15 ( V_12 ) ;
}
int F_73 ( void )
{
F_12 ( ! F_71 () ) ;
return F_7 () & V_69 ;
}
void F_74 ( struct V_66 * V_67 )
{
F_75 ( F_67 ( V_67 ) , V_68 ) ;
F_27 ( F_68 ( V_67 ) ) ;
}
void F_76 ( struct V_66 * V_67 )
{
F_77 ( F_67 ( V_67 ) , V_68 ) ;
}
