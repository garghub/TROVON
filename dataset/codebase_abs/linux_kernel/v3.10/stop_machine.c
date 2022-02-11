static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( & V_2 -> V_3 , V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , bool V_5 )
{
if ( V_2 ) {
if ( V_5 )
V_2 -> V_5 = true ;
if ( F_5 ( & V_2 -> V_3 ) )
F_6 ( & V_2 -> V_4 ) ;
}
}
static void F_7 ( unsigned int V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_11 * V_12 = F_8 ( V_13 , V_6 ) ;
unsigned long V_14 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
if ( V_10 -> V_16 ) {
F_10 ( & V_8 -> V_17 , & V_10 -> V_18 ) ;
F_11 ( V_12 ) ;
} else
F_4 ( V_8 -> V_2 , false ) ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
}
int F_13 ( unsigned int V_6 , T_1 V_19 , void * V_20 )
{
struct V_1 V_2 ;
struct V_7 V_8 = { . V_19 = V_19 , . V_20 = V_20 , . V_2 = & V_2 } ;
F_1 ( & V_2 , 1 ) ;
F_7 ( V_6 , & V_8 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_21 : - V_22 ;
}
void F_15 ( unsigned int V_6 , T_1 V_19 , void * V_20 ,
struct V_7 * V_23 )
{
* V_23 = (struct V_7 ) { . V_19 = V_19 , . V_20 = V_20 , } ;
F_7 ( V_6 , V_23 ) ;
}
static void F_16 ( const struct V_24 * V_24 ,
T_1 V_19 , void * V_20 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_6 ;
F_17 (cpu, cpumask) {
V_8 = & F_8 ( V_25 , V_6 ) ;
V_8 -> V_19 = V_19 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_2 = V_2 ;
}
F_18 () ;
F_17 (cpu, cpumask)
F_7 ( V_6 , & F_8 ( V_25 , V_6 ) ) ;
F_19 () ;
}
static int F_20 ( const struct V_24 * V_24 ,
T_1 V_19 , void * V_20 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_21 ( V_24 ) ) ;
F_16 ( V_24 , V_19 , V_20 , & V_2 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_21 : - V_22 ;
}
int F_22 ( const struct V_24 * V_24 , T_1 V_19 , void * V_20 )
{
int V_21 ;
F_23 ( & V_26 ) ;
V_21 = F_20 ( V_24 , V_19 , V_20 ) ;
F_24 ( & V_26 ) ;
return V_21 ;
}
int F_25 ( const struct V_24 * V_24 , T_1 V_19 , void * V_20 )
{
int V_21 ;
if ( ! F_26 ( & V_26 ) )
return - V_27 ;
V_21 = F_20 ( V_24 , V_19 , V_20 ) ;
F_24 ( & V_26 ) ;
return V_21 ;
}
static int F_27 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
unsigned long V_14 ;
int V_28 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
V_28 = ! F_28 ( & V_10 -> V_18 ) ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
return V_28 ;
}
static void F_29 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
int V_21 ;
V_29:
V_8 = NULL ;
F_30 ( & V_10 -> V_15 ) ;
if ( ! F_28 ( & V_10 -> V_18 ) ) {
V_8 = F_31 ( & V_10 -> V_18 ,
struct V_7 , V_17 ) ;
F_32 ( & V_8 -> V_17 ) ;
}
F_33 ( & V_10 -> V_15 ) ;
if ( V_8 ) {
T_1 V_19 = V_8 -> V_19 ;
void * V_20 = V_8 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
char V_30 [ V_31 ] V_32 ;
F_18 () ;
V_21 = V_19 ( V_20 ) ;
if ( V_21 )
V_2 -> V_21 = V_21 ;
F_19 () ;
F_34 ( F_35 () ,
L_1 ,
F_36 ( ( unsigned long ) V_19 , NULL , NULL , NULL ,
V_30 ) , V_20 ) ;
F_4 ( V_2 , true ) ;
goto V_29;
}
}
static void F_37 ( unsigned int V_6 )
{
F_38 ( V_6 , F_8 ( V_13 , V_6 ) ) ;
}
static void F_39 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
unsigned long V_14 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
F_40 (work, &stopper->works, list)
F_4 ( V_8 -> V_2 , false ) ;
V_10 -> V_16 = false ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
}
static void F_41 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_30 ( & V_10 -> V_15 ) ;
V_10 -> V_16 = true ;
F_33 ( & V_10 -> V_15 ) ;
}
static int T_2 F_42 ( void )
{
unsigned int V_6 ;
F_43 (cpu) {
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_44 ( & V_10 -> V_15 ) ;
F_45 ( & V_10 -> V_18 ) ;
}
F_46 ( F_47 ( & V_33 ) ) ;
V_34 = true ;
return 0 ;
}
static void F_48 ( struct V_35 * V_36 ,
enum V_37 V_38 )
{
F_2 ( & V_36 -> V_39 , V_36 -> V_40 ) ;
F_49 () ;
V_36 -> V_41 = V_38 ;
}
static void F_50 ( struct V_35 * V_36 )
{
if ( F_5 ( & V_36 -> V_39 ) )
F_48 ( V_36 , V_36 -> V_41 + 1 ) ;
}
static int F_51 ( void * V_42 )
{
struct V_35 * V_36 = V_42 ;
enum V_37 V_43 = V_44 ;
int V_6 = F_52 () , V_45 = 0 ;
unsigned long V_14 ;
bool V_46 ;
F_53 ( V_14 ) ;
if ( ! V_36 -> V_47 )
V_46 = V_6 == F_54 ( V_48 ) ;
else
V_46 = F_55 ( V_6 , V_36 -> V_47 ) ;
do {
F_56 () ;
if ( V_36 -> V_41 != V_43 ) {
V_43 = V_36 -> V_41 ;
switch ( V_43 ) {
case V_49 :
F_57 () ;
F_58 () ;
break;
case V_50 :
if ( V_46 )
V_45 = V_36 -> V_19 ( V_36 -> V_42 ) ;
break;
default:
break;
}
F_50 ( V_36 ) ;
}
} while ( V_43 != V_51 );
F_59 ( V_14 ) ;
return V_45 ;
}
int F_60 ( int (* V_19)( void * ) , void * V_42 , const struct V_24 * V_52 )
{
struct V_35 V_36 = { . V_19 = V_19 , . V_42 = V_42 ,
. V_40 = F_61 () ,
. V_47 = V_52 } ;
if ( ! V_34 ) {
unsigned long V_14 ;
int V_21 ;
F_62 ( V_36 . V_40 != 1 ) ;
F_63 ( V_14 ) ;
F_58 () ;
V_21 = (* V_19)( V_42 ) ;
F_59 ( V_14 ) ;
return V_21 ;
}
F_48 ( & V_36 , V_53 ) ;
return F_22 ( V_48 , F_51 , & V_36 ) ;
}
int F_64 ( int (* V_19)( void * ) , void * V_42 , const struct V_24 * V_52 )
{
int V_21 ;
F_65 () ;
V_21 = F_60 ( V_19 , V_42 , V_52 ) ;
F_66 () ;
return V_21 ;
}
int F_67 ( int (* V_19)( void * ) , void * V_42 ,
const struct V_24 * V_52 )
{
struct V_35 V_36 = { . V_19 = V_19 , . V_42 = V_42 ,
. V_47 = V_52 } ;
struct V_1 V_2 ;
int V_21 ;
F_46 ( F_68 ( F_69 () ) ) ;
V_36 . V_40 = F_70 () + 1 ;
while ( ! F_26 ( & V_26 ) )
F_56 () ;
F_48 ( & V_36 , V_53 ) ;
F_1 ( & V_2 , F_70 () ) ;
F_16 ( V_54 , F_51 , & V_36 ,
& V_2 ) ;
V_21 = F_51 ( & V_36 ) ;
while ( ! F_71 ( & V_2 . V_4 ) )
F_56 () ;
F_24 ( & V_26 ) ;
return V_21 ? : V_2 . V_21 ;
}
