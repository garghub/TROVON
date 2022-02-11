T_1 F_1 ( void )
{
return F_2 ( F_3 ( V_1 ) ,
V_2 ) ;
}
static void F_4 ( T_2 V_3 )
{
unsigned long V_4 ;
F_5 ( V_4 ) ;
F_6 ( V_3 , V_5 ) ;
F_7 ( V_4 ) ;
}
static T_2 F_8 ( void )
{
return F_9 ( V_5 ) ;
}
static int F_10 ( void )
{
F_11 ( L_1 , 0644 , NULL , & V_6 ) ;
return 0 ;
}
static int T_3 F_12 ( char * V_7 )
{
V_6 = false ;
return 0 ;
}
void F_13 ( enum V_8 V_9 )
{
T_2 V_3 , V_10 = 0 ;
F_14 ( F_15 () ) ;
if ( F_16 ( V_11 ) == 1 )
V_10 = V_12 ;
if ( V_9 == V_13 &&
F_16 ( V_14 ) == 1 )
V_10 |= V_15 ;
if ( V_10 && V_6 ) {
V_3 = F_8 () ;
V_3 |= V_10 ;
F_4 ( V_3 ) ;
}
}
void F_17 ( enum V_8 V_9 )
{
T_2 V_3 , V_16 = 0 ;
F_14 ( F_15 () ) ;
if ( F_18 ( V_11 ) == 0 )
V_16 = ~ V_12 ;
if ( V_9 == V_13 &&
F_18 ( V_14 ) == 0 )
V_16 &= ~ V_15 ;
if ( V_16 ) {
V_3 = F_8 () ;
V_3 &= V_16 ;
F_4 ( V_3 ) ;
}
}
static int F_19 ( unsigned int V_17 )
{
F_6 ( 0 , V_18 ) ;
F_20 () ;
return 0 ;
}
static int F_21 ( void )
{
return F_22 ( V_19 ,
L_2 ,
F_19 , NULL ) ;
}
static void F_23 ( struct V_20 * V_21 )
{
V_21 -> V_22 |= V_23 ;
}
static void F_24 ( struct V_20 * V_21 )
{
V_21 -> V_22 &= ~ V_23 ;
}
void F_25 ( struct V_24 * V_25 )
{
F_26 ( & V_26 ) ;
F_27 ( & V_25 -> V_27 , & V_24 ) ;
F_28 ( & V_26 ) ;
}
void F_29 ( struct V_24 * V_25 )
{
F_26 ( & V_26 ) ;
F_30 ( & V_25 -> V_27 ) ;
F_28 ( & V_26 ) ;
F_31 () ;
}
static int F_32 ( struct V_20 * V_21 , unsigned int V_28 )
{
struct V_24 * V_25 ;
int V_29 = V_30 ;
F_33 () ;
F_34 (hook, &step_hook, node) {
V_29 = V_25 -> V_31 ( V_21 , V_28 ) ;
if ( V_29 == V_32 )
break;
}
F_35 () ;
return V_29 ;
}
static void F_36 ( int V_33 )
{
struct V_20 * V_21 = F_37 () ;
T_4 V_34 = {
. V_35 = V_36 ,
. V_37 = 0 ,
. V_33 = V_33 ,
. V_38 = ( void V_39 * ) F_38 ( V_21 ) ,
} ;
if ( F_14 ( ! F_39 ( V_21 ) ) )
return;
if ( F_40 ( V_21 ) )
F_41 () ;
F_42 ( V_36 , & V_34 , V_40 ) ;
}
static int F_43 ( unsigned long V_41 , unsigned int V_28 ,
struct V_20 * V_21 )
{
bool V_42 = false ;
if ( ! F_44 ( V_21 ) )
return 0 ;
#ifdef F_45
if ( F_46 ( V_21 , V_28 ) == V_32 )
V_42 = true ;
#endif
if ( ! V_42 && F_32 ( V_21 , V_28 ) == V_32 )
V_42 = true ;
if ( ! V_42 && F_39 ( V_21 ) ) {
F_36 ( V_43 ) ;
F_47 ( V_40 ) ;
} else if ( ! V_42 ) {
F_48 ( L_3 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
void F_49 ( struct V_44 * V_25 )
{
F_26 ( & V_45 ) ;
F_27 ( & V_25 -> V_27 , & V_44 ) ;
F_28 ( & V_45 ) ;
}
void F_50 ( struct V_44 * V_25 )
{
F_26 ( & V_45 ) ;
F_30 ( & V_25 -> V_27 ) ;
F_28 ( & V_45 ) ;
F_31 () ;
}
static int F_51 ( struct V_20 * V_21 , unsigned int V_28 )
{
struct V_44 * V_25 ;
int (* V_31)( struct V_20 * V_21 , unsigned int V_28 ) = NULL ;
F_33 () ;
F_34 (hook, &break_hook, node)
if ( ( V_28 & V_25 -> V_46 ) == V_25 -> V_47 )
V_31 = V_25 -> V_31 ;
F_35 () ;
return V_31 ? V_31 ( V_21 , V_28 ) : V_30 ;
}
static int F_52 ( unsigned long V_41 , unsigned int V_28 ,
struct V_20 * V_21 )
{
bool V_42 = false ;
#ifdef F_45
if ( ( V_28 & V_48 ) == V_49 ) {
if ( F_53 ( V_21 , V_28 ) == V_32 )
V_42 = true ;
}
#endif
if ( ! V_42 && F_51 ( V_21 , V_28 ) == V_32 )
V_42 = true ;
if ( ! V_42 && F_39 ( V_21 ) ) {
F_36 ( V_50 ) ;
} else if ( ! V_42 ) {
F_48 ( L_4 ) ;
return - V_51 ;
}
return 0 ;
}
int F_54 ( struct V_20 * V_21 )
{
T_2 V_52 ;
T_5 V_53 ;
bool V_54 = false ;
void V_39 * V_55 = ( void V_39 * ) F_38 ( V_21 ) ;
if ( ! F_55 ( V_21 ) )
return - V_51 ;
if ( F_56 ( V_21 ) ) {
F_57 ( V_53 , ( T_5 V_39 * ) V_55 ) ;
V_53 = F_58 ( V_53 ) ;
if ( V_53 == V_56 ) {
F_57 ( V_53 , ( T_5 V_39 * ) ( V_55 + 2 ) ) ;
V_53 = F_58 ( V_53 ) ;
V_54 = V_53 == V_57 ;
} else {
V_54 = V_53 == V_58 ;
}
} else {
F_57 ( V_52 , ( T_2 V_39 * ) V_55 ) ;
V_52 = F_59 ( V_52 ) ;
V_54 = ( V_52 & ~ 0xf0000000 ) == V_59 ;
}
if ( ! V_54 )
return - V_51 ;
F_36 ( V_50 ) ;
return 0 ;
}
static int T_3 F_60 ( void )
{
F_61 ( V_60 , F_43 , V_36 ,
V_43 , L_5 ) ;
F_61 ( V_61 , F_52 , V_36 ,
V_50 , L_6 ) ;
return 0 ;
}
void F_47 ( struct V_62 * V_63 )
{
if ( F_62 ( F_63 ( V_63 ) , V_64 ) )
F_23 ( F_64 ( V_63 ) ) ;
}
void F_65 ( struct V_62 * V_63 )
{
if ( F_62 ( F_63 ( V_63 ) , V_64 ) )
F_24 ( F_64 ( V_63 ) ) ;
}
void F_66 ( struct V_20 * V_21 )
{
F_14 ( ! F_67 () ) ;
F_23 ( V_21 ) ;
F_4 ( F_8 () | V_65 ) ;
F_13 ( V_13 ) ;
}
void F_68 ( void )
{
F_14 ( ! F_67 () ) ;
F_4 ( F_8 () & ~ V_65 ) ;
F_17 ( V_13 ) ;
}
int F_69 ( void )
{
F_14 ( ! F_67 () ) ;
return F_8 () & V_65 ;
}
void F_70 ( struct V_62 * V_63 )
{
struct V_66 * V_67 = F_63 ( V_63 ) ;
if ( ! F_71 ( V_67 , V_64 ) )
F_23 ( F_64 ( V_63 ) ) ;
}
void F_72 ( struct V_62 * V_63 )
{
F_73 ( F_63 ( V_63 ) , V_64 ) ;
}
