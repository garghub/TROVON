static bool F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void F_3 ( unsigned long V_2 )
{
unsigned int V_3 ;
T_1 * V_4 = F_4 ( V_2 , & V_3 ) ;
if ( ! V_4 ) {
F_5 ( L_1 ,
V_5 , V_2 ) ;
return;
}
if ( V_3 == V_6 ) {
F_6 ( L_2 ,
V_2 ) ;
F_7 () ;
}
F_8 ( L_3 ,
V_2 ,
( unsigned long long ) F_9 ( * V_4 ) ,
( unsigned long long ) F_9 ( * V_4 ) & V_7 ) ;
}
static void F_10 ( struct V_8 * V_9 , unsigned long V_10 )
{
const struct V_11 * V_12 = & F_11 ( V_13 ) ;
F_6 ( L_4 ,
V_10 , V_12 -> V_10 ) ;
F_3 ( V_10 ) ;
F_12 ( V_14 L_5 , V_9 -> V_15 ) ;
F_12 ( V_14 L_6 , V_12 -> V_15 ) ;
#ifdef F_13
F_6 ( L_7 ,
V_9 -> V_16 , V_9 -> V_17 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_6 ( L_8 ,
V_9 -> V_20 , V_9 -> V_21 , V_9 -> V_22 , V_9 -> V_23 ) ;
#else
F_6 ( L_9 ,
V_9 -> V_16 , V_9 -> V_18 , V_9 -> V_19 ) ;
F_6 ( L_10 ,
V_9 -> V_20 , V_9 -> V_21 , V_9 -> V_22 , V_9 -> V_23 ) ;
#endif
F_14 ( V_13 ) ;
F_7 () ;
}
static void F_15 ( struct V_24 * V_25 , struct V_8 * V_9 ,
unsigned long V_10 )
{
struct V_11 * V_12 = & F_11 ( V_13 ) ;
struct V_26 * V_27 = & F_11 ( V_28 ) ;
const unsigned long V_29 = F_16 ( V_9 ) ;
const enum V_30 type = F_17 ( V_29 ) ;
struct V_31 * V_32 = V_25 -> V_33 ;
if ( V_12 -> V_34 )
F_10 ( V_9 , V_10 ) ;
else
V_12 -> V_34 ++ ;
V_12 -> type = type ;
V_12 -> V_10 = V_10 ;
V_12 -> V_15 = V_29 ;
V_27 -> V_35 = V_10 - V_32 -> V_36 . V_10 + V_32 -> V_35 ;
V_27 -> V_37 = V_32 -> V_38 ;
if ( V_39 )
V_27 -> V_40 = V_29 ;
else
V_27 -> V_40 = 0 ;
switch ( type ) {
case V_41 :
V_27 -> V_42 = V_43 ;
V_27 -> V_44 = F_18 ( V_29 ) ;
break;
case V_45 :
V_27 -> V_42 = V_46 ;
V_27 -> V_44 = F_18 ( V_29 ) ;
V_27 -> V_47 = F_19 ( V_29 , V_9 ) ;
break;
case V_48 :
V_27 -> V_42 = V_46 ;
V_27 -> V_44 = F_18 ( V_29 ) ;
V_27 -> V_47 = F_20 ( V_29 ) ;
break;
default:
{
unsigned char * V_15 = ( unsigned char * ) V_29 ;
V_27 -> V_42 = V_49 ;
V_27 -> V_44 = 0 ;
V_27 -> V_47 = ( * V_15 ) << 16 | * ( V_15 + 1 ) << 8 |
* ( V_15 + 2 ) ;
}
}
F_14 ( V_28 ) ;
F_14 ( V_13 ) ;
}
static void F_21 ( struct V_24 * V_25 , unsigned long V_50 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = & F_11 ( V_13 ) ;
struct V_26 * V_27 = & F_11 ( V_28 ) ;
V_12 -> V_34 -- ;
if ( V_12 -> V_34 ) {
F_6 ( L_11 ) ;
F_7 () ;
}
switch ( V_12 -> type ) {
case V_41 :
V_27 -> V_47 = F_19 ( V_12 -> V_15 , V_9 ) ;
break;
default:
break;
}
F_22 ( V_27 ) ;
F_14 ( V_28 ) ;
F_14 ( V_13 ) ;
}
static void F_23 ( T_2 V_51 , unsigned long V_52 ,
void T_3 * V_10 )
{
static T_4 V_53 ;
struct V_31 * V_32 = F_24 ( sizeof( * V_32 ) , V_54 ) ;
struct V_55 V_56 = {
. V_35 = V_51 ,
. V_57 = ( unsigned long ) V_10 ,
. V_58 = V_52 ,
. V_42 = V_59
} ;
if ( ! V_32 ) {
F_5 ( L_12 ) ;
return;
}
* V_32 = (struct V_31 ) {
. V_36 = {
. V_10 = ( unsigned long ) V_10 ,
. V_58 = V_52 ,
. V_60 = F_15 ,
. V_61 = F_21 ,
. V_33 = V_32
} ,
. V_35 = V_51 ,
. V_38 = F_25 (&next_id)
} ;
V_56 . V_37 = V_32 -> V_38 ;
F_26 ( & V_62 ) ;
if ( ! F_1 () ) {
F_27 ( V_32 ) ;
goto V_63;
}
F_28 ( & V_56 ) ;
F_29 ( & V_32 -> V_64 , & V_65 ) ;
if ( ! V_66 )
F_30 ( & V_32 -> V_36 ) ;
V_63:
F_31 ( & V_62 ) ;
}
void F_32 ( T_2 V_51 , unsigned long V_52 ,
void T_3 * V_10 )
{
if ( ! F_1 () )
return;
F_33 ( L_13 ,
( unsigned long long ) V_51 , V_52 , V_10 ) ;
if ( ( V_67 ) && ( V_51 != V_67 ) )
return;
F_23 ( V_51 , V_52 , V_10 ) ;
}
static void F_34 ( volatile void T_3 * V_10 )
{
struct V_55 V_56 = {
. V_35 = 0 ,
. V_57 = ( unsigned long ) V_10 ,
. V_58 = 0 ,
. V_42 = V_68
} ;
struct V_31 * V_32 ;
struct V_31 * V_69 ;
struct V_31 * V_70 = NULL ;
F_33 ( L_14 , V_10 ) ;
F_26 ( & V_62 ) ;
if ( ! F_1 () )
goto V_63;
F_35 (trace, tmp, &trace_list, list) {
if ( ( unsigned long ) V_10 == V_32 -> V_36 . V_10 ) {
if ( ! V_66 )
F_36 ( & V_32 -> V_36 ) ;
F_37 ( & V_32 -> V_64 ) ;
V_70 = V_32 ;
break;
}
}
V_56 . V_37 = ( V_70 ) ? V_70 -> V_38 : - 1 ;
F_28 ( & V_56 ) ;
V_63:
F_31 ( & V_62 ) ;
if ( V_70 ) {
F_38 () ;
F_27 ( V_70 ) ;
}
}
void F_39 ( volatile void T_3 * V_10 )
{
F_40 () ;
if ( F_1 () )
F_34 ( V_10 ) ;
}
int F_41 ( const char * V_71 , ... )
{
int V_72 = 0 ;
T_5 args ;
unsigned long V_73 ;
va_start ( args , V_71 ) ;
F_42 ( & V_62 , V_73 ) ;
if ( F_1 () )
V_72 = F_43 ( V_71 , args ) ;
F_44 ( & V_62 , V_73 ) ;
va_end ( args ) ;
return V_72 ;
}
static void F_45 ( void )
{
struct V_31 * V_32 ;
struct V_31 * V_69 ;
F_46 (trace, &trace_list, list) {
F_47 ( L_15 ,
V_32 -> V_36 . V_10 , V_32 -> V_36 . V_58 ) ;
if ( ! V_66 )
F_36 ( & V_32 -> V_36 ) ;
}
F_38 () ;
F_35 (trace, tmp, &trace_list, list) {
F_37 ( & V_32 -> V_64 ) ;
F_27 ( V_32 ) ;
}
}
static void F_48 ( void )
{
int V_74 ;
int V_75 ;
if ( V_76 == NULL &&
! F_49 ( & V_76 , V_54 ) ) {
F_47 ( L_16 ) ;
goto V_77;
}
F_50 () ;
F_51 ( V_76 , V_78 ) ;
F_52 ( F_53 ( V_78 ) , V_76 ) ;
if ( F_54 () > 1 )
F_47 ( L_17 ) ;
F_55 () ;
F_56 (cpu, downed_cpus) {
V_75 = F_57 ( V_74 ) ;
if ( ! V_75 )
F_8 ( L_18 , V_74 ) ;
else
F_5 ( L_19 , V_74 , V_75 ) ;
}
V_77:
if ( F_54 () > 1 )
F_58 ( L_20 ) ;
}
static void F_59 ( void )
{
int V_74 ;
int V_75 ;
if ( V_76 == NULL || F_60 ( V_76 ) == 0 )
return;
F_47 ( L_21 ) ;
F_56 (cpu, downed_cpus) {
V_75 = F_61 ( V_74 ) ;
if ( ! V_75 )
F_8 ( L_22 , V_74 ) ;
else
F_5 ( L_23 , V_74 , V_75 ) ;
}
}
static void F_48 ( void )
{
if ( F_54 () > 1 )
F_58 ( L_24
L_25 ) ;
}
static void F_59 ( void )
{
}
void F_62 ( void )
{
F_63 ( & V_79 ) ;
if ( F_1 () )
goto V_77;
if ( V_66 )
F_8 ( L_26 ) ;
F_64 () ;
F_48 () ;
F_26 ( & V_62 ) ;
F_65 ( & V_1 ) ;
F_31 ( & V_62 ) ;
F_8 ( L_27 ) ;
V_77:
F_66 ( & V_79 ) ;
}
void F_67 ( void )
{
F_63 ( & V_79 ) ;
if ( ! F_1 () )
goto V_77;
F_26 ( & V_62 ) ;
F_68 ( & V_1 ) ;
F_69 ( F_1 () ) ;
F_31 ( & V_62 ) ;
F_45 () ;
F_59 () ;
F_70 () ;
F_8 ( L_28 ) ;
V_77:
F_66 ( & V_79 ) ;
}
