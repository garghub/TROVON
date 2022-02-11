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
if ( ! F_44 ( V_21 ) )
return 0 ;
if ( F_39 ( V_21 ) ) {
F_36 ( V_42 ) ;
F_45 ( V_40 ) ;
} else {
#ifdef F_46
if ( F_47 ( V_21 , V_28 ) == V_32 )
return 0 ;
#endif
if ( F_32 ( V_21 , V_28 ) == V_32 )
return 0 ;
F_48 ( L_3 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
void F_49 ( struct V_43 * V_25 )
{
F_26 ( & V_44 ) ;
F_27 ( & V_25 -> V_27 , & V_43 ) ;
F_28 ( & V_44 ) ;
}
void F_50 ( struct V_43 * V_25 )
{
F_26 ( & V_44 ) ;
F_30 ( & V_25 -> V_27 ) ;
F_28 ( & V_44 ) ;
F_31 () ;
}
static int F_51 ( struct V_20 * V_21 , unsigned int V_28 )
{
struct V_43 * V_25 ;
int (* V_31)( struct V_20 * V_21 , unsigned int V_28 ) = NULL ;
F_33 () ;
F_34 (hook, &break_hook, node)
if ( ( V_28 & V_25 -> V_45 ) == V_25 -> V_46 )
V_31 = V_25 -> V_31 ;
F_35 () ;
return V_31 ? V_31 ( V_21 , V_28 ) : V_30 ;
}
static int F_52 ( unsigned long V_41 , unsigned int V_28 ,
struct V_20 * V_21 )
{
if ( F_39 ( V_21 ) ) {
F_36 ( V_47 ) ;
}
#ifdef F_46
else if ( ( V_28 & V_48 ) == V_49 ) {
if ( F_53 ( V_21 , V_28 ) != V_32 )
return - V_50 ;
}
#endif
else if ( F_51 ( V_21 , V_28 ) != V_32 ) {
F_54 ( L_4 ) ;
return - V_50 ;
}
return 0 ;
}
int F_55 ( struct V_20 * V_21 )
{
T_2 V_51 ;
T_5 V_52 ;
bool V_53 = false ;
void V_39 * V_54 = ( void V_39 * ) F_38 ( V_21 ) ;
if ( ! F_56 ( V_21 ) )
return - V_50 ;
if ( F_57 ( V_21 ) ) {
F_58 ( V_52 , ( T_5 V_39 * ) V_54 ) ;
V_52 = F_59 ( V_52 ) ;
if ( V_52 == V_55 ) {
F_58 ( V_52 , ( T_5 V_39 * ) ( V_54 + 2 ) ) ;
V_52 = F_59 ( V_52 ) ;
V_53 = V_52 == V_56 ;
} else {
V_53 = V_52 == V_57 ;
}
} else {
F_58 ( V_51 , ( T_2 V_39 * ) V_54 ) ;
V_51 = F_60 ( V_51 ) ;
V_53 = ( V_51 & ~ 0xf0000000 ) == V_58 ;
}
if ( ! V_53 )
return - V_50 ;
F_36 ( V_47 ) ;
return 0 ;
}
static int T_3 F_61 ( void )
{
F_62 ( V_59 , F_43 , V_36 ,
V_42 , L_5 ) ;
F_62 ( V_60 , F_52 , V_36 ,
V_47 , L_6 ) ;
return 0 ;
}
void F_45 ( struct V_61 * V_62 )
{
if ( F_63 ( F_64 ( V_62 ) , V_63 ) )
F_23 ( F_65 ( V_62 ) ) ;
}
void F_66 ( struct V_61 * V_62 )
{
if ( F_63 ( F_64 ( V_62 ) , V_63 ) )
F_24 ( F_65 ( V_62 ) ) ;
}
void F_67 ( struct V_20 * V_21 )
{
F_14 ( ! F_68 () ) ;
F_23 ( V_21 ) ;
F_4 ( F_8 () | V_64 ) ;
F_13 ( V_13 ) ;
}
void F_69 ( void )
{
F_14 ( ! F_68 () ) ;
F_4 ( F_8 () & ~ V_64 ) ;
F_17 ( V_13 ) ;
}
int F_70 ( void )
{
F_14 ( ! F_68 () ) ;
return F_8 () & V_64 ;
}
void F_71 ( struct V_61 * V_62 )
{
struct V_65 * V_66 = F_64 ( V_62 ) ;
if ( ! F_72 ( V_66 , V_63 ) )
F_23 ( F_65 ( V_62 ) ) ;
}
void F_73 ( struct V_61 * V_62 )
{
F_74 ( F_64 ( V_62 ) , V_63 ) ;
}
