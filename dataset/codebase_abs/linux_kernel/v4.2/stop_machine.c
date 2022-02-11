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
static void F_15 ( struct V_23 * V_24 ,
enum V_25 V_26 )
{
F_2 ( & V_24 -> V_27 , V_24 -> V_28 ) ;
F_16 () ;
V_24 -> V_29 = V_26 ;
}
static void F_17 ( struct V_23 * V_24 )
{
if ( F_5 ( & V_24 -> V_27 ) )
F_15 ( V_24 , V_24 -> V_29 + 1 ) ;
}
static int F_18 ( void * V_30 )
{
struct V_23 * V_24 = V_30 ;
enum V_25 V_31 = V_32 ;
int V_6 = F_19 () , V_33 = 0 ;
unsigned long V_14 ;
bool V_34 ;
F_20 ( V_14 ) ;
if ( ! V_24 -> V_35 )
V_34 = V_6 == F_21 ( V_36 ) ;
else
V_34 = F_22 ( V_6 , V_24 -> V_35 ) ;
do {
F_23 () ;
if ( V_24 -> V_29 != V_31 ) {
V_31 = V_24 -> V_29 ;
switch ( V_31 ) {
case V_37 :
F_24 () ;
F_25 () ;
break;
case V_38 :
if ( V_34 )
V_33 = V_24 -> V_19 ( V_24 -> V_30 ) ;
break;
default:
break;
}
F_17 ( V_24 ) ;
}
} while ( V_31 != V_39 );
F_26 ( V_14 ) ;
return V_33 ;
}
int F_27 ( unsigned int V_40 , unsigned int V_41 , T_1 V_19 , void * V_20 )
{
struct V_1 V_2 ;
struct V_7 V_42 , V_43 ;
struct V_23 V_24 ;
F_28 () ;
V_24 = (struct V_23 ) {
. V_19 = V_19 ,
. V_30 = V_20 ,
. V_28 = 2 ,
. V_35 = F_29 ( V_40 ) ,
} ;
V_42 = V_43 = (struct V_7 ) {
. V_19 = F_18 ,
. V_20 = & V_24 ,
. V_2 = & V_2
} ;
F_1 ( & V_2 , 2 ) ;
F_15 ( & V_24 , V_44 ) ;
if ( ! F_30 ( V_40 ) || ! F_30 ( V_41 ) ) {
F_31 () ;
return - V_22 ;
}
F_32 ( & V_45 , V_40 , V_41 ) ;
F_7 ( V_40 , & V_42 ) ;
F_7 ( V_41 , & V_43 ) ;
F_33 ( & V_45 , V_40 , V_41 ) ;
F_31 () ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_21 : - V_22 ;
}
void F_34 ( unsigned int V_6 , T_1 V_19 , void * V_20 ,
struct V_7 * V_46 )
{
* V_46 = (struct V_7 ) { . V_19 = V_19 , . V_20 = V_20 , } ;
F_7 ( V_6 , V_46 ) ;
}
static void F_35 ( const struct V_47 * V_47 ,
T_1 V_19 , void * V_20 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_6 ;
F_36 (cpu, cpumask) {
V_8 = & F_8 ( V_48 , V_6 ) ;
V_8 -> V_19 = V_19 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_2 = V_2 ;
}
F_37 ( & V_45 ) ;
F_36 (cpu, cpumask)
F_7 ( V_6 , & F_8 ( V_48 , V_6 ) ) ;
F_38 ( & V_45 ) ;
}
static int F_39 ( const struct V_47 * V_47 ,
T_1 V_19 , void * V_20 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_40 ( V_47 ) ) ;
F_35 ( V_47 , V_19 , V_20 , & V_2 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_21 : - V_22 ;
}
int F_41 ( const struct V_47 * V_47 , T_1 V_19 , void * V_20 )
{
int V_21 ;
F_42 ( & V_49 ) ;
V_21 = F_39 ( V_47 , V_19 , V_20 ) ;
F_43 ( & V_49 ) ;
return V_21 ;
}
int F_44 ( const struct V_47 * V_47 , T_1 V_19 , void * V_20 )
{
int V_21 ;
if ( ! F_45 ( & V_49 ) )
return - V_50 ;
V_21 = F_39 ( V_47 , V_19 , V_20 ) ;
F_43 ( & V_49 ) ;
return V_21 ;
}
static int F_46 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
unsigned long V_14 ;
int V_51 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
V_51 = ! F_47 ( & V_10 -> V_18 ) ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
return V_51 ;
}
static void F_48 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
int V_21 ;
V_52:
V_8 = NULL ;
F_49 ( & V_10 -> V_15 ) ;
if ( ! F_47 ( & V_10 -> V_18 ) ) {
V_8 = F_50 ( & V_10 -> V_18 ,
struct V_7 , V_17 ) ;
F_51 ( & V_8 -> V_17 ) ;
}
F_52 ( & V_10 -> V_15 ) ;
if ( V_8 ) {
T_1 V_19 = V_8 -> V_19 ;
void * V_20 = V_8 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
char V_53 [ V_54 ] V_55 ;
F_28 () ;
V_21 = V_19 ( V_20 ) ;
if ( V_21 )
V_2 -> V_21 = V_21 ;
F_31 () ;
F_53 ( F_54 () ,
L_1 ,
F_55 ( ( unsigned long ) V_19 , NULL , NULL , NULL ,
V_53 ) , V_20 ) ;
F_4 ( V_2 , true ) ;
goto V_52;
}
}
static void F_56 ( unsigned int V_6 )
{
F_57 ( V_6 , F_8 ( V_13 , V_6 ) ) ;
}
static void F_58 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
unsigned long V_14 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
F_59 (work, &stopper->works, list)
F_4 ( V_8 -> V_2 , false ) ;
V_10 -> V_16 = false ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
}
static void F_60 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_49 ( & V_10 -> V_15 ) ;
V_10 -> V_16 = true ;
F_52 ( & V_10 -> V_15 ) ;
}
static int T_2 F_61 ( void )
{
unsigned int V_6 ;
F_62 (cpu) {
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_63 ( & V_10 -> V_15 ) ;
F_64 ( & V_10 -> V_18 ) ;
}
F_65 ( F_66 ( & V_56 ) ) ;
V_57 = true ;
return 0 ;
}
int F_67 ( int (* V_19)( void * ) , void * V_30 , const struct V_47 * V_58 )
{
struct V_23 V_24 = {
. V_19 = V_19 ,
. V_30 = V_30 ,
. V_28 = F_68 () ,
. V_35 = V_58 ,
} ;
if ( ! V_57 ) {
unsigned long V_14 ;
int V_21 ;
F_69 ( V_24 . V_28 != 1 ) ;
F_70 ( V_14 ) ;
F_25 () ;
V_21 = (* V_19)( V_30 ) ;
F_26 ( V_14 ) ;
return V_21 ;
}
F_15 ( & V_24 , V_44 ) ;
return F_41 ( V_36 , F_18 , & V_24 ) ;
}
int F_71 ( int (* V_19)( void * ) , void * V_30 , const struct V_47 * V_58 )
{
int V_21 ;
F_72 () ;
V_21 = F_67 ( V_19 , V_30 , V_58 ) ;
F_73 () ;
return V_21 ;
}
int F_74 ( int (* V_19)( void * ) , void * V_30 ,
const struct V_47 * V_58 )
{
struct V_23 V_24 = { . V_19 = V_19 , . V_30 = V_30 ,
. V_35 = V_58 } ;
struct V_1 V_2 ;
int V_21 ;
F_65 ( F_30 ( F_75 () ) ) ;
V_24 . V_28 = F_76 () + 1 ;
while ( ! F_45 ( & V_49 ) )
F_23 () ;
F_15 ( & V_24 , V_44 ) ;
F_1 ( & V_2 , F_76 () ) ;
F_35 ( V_59 , F_18 , & V_24 ,
& V_2 ) ;
V_21 = F_18 ( & V_24 ) ;
while ( ! F_77 ( & V_2 . V_4 ) )
F_23 () ;
F_43 ( & V_49 ) ;
return V_21 ? : V_2 . V_21 ;
}
