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
static void F_27 ( void * V_20 )
{
struct V_40 * V_41 = V_20 ;
F_7 ( V_41 -> V_42 , V_41 -> V_43 ) ;
F_7 ( V_41 -> V_44 , V_41 -> V_45 ) ;
}
int F_28 ( unsigned int V_42 , unsigned int V_44 , T_1 V_19 , void * V_20 )
{
struct V_1 V_2 ;
struct V_7 V_43 , V_45 ;
struct V_40 V_46 ;
struct V_23 V_24 ;
F_29 () ;
V_24 = (struct V_23 ) {
. V_19 = V_19 ,
. V_30 = V_20 ,
. V_28 = 2 ,
. V_35 = F_30 ( V_42 ) ,
} ;
V_43 = V_45 = (struct V_7 ) {
. V_19 = F_18 ,
. V_20 = & V_24 ,
. V_2 = & V_2
} ;
V_46 = (struct V_40 ) {
. V_42 = V_42 ,
. V_44 = V_44 ,
. V_43 = & V_43 ,
. V_45 = & V_45 ,
} ;
F_1 ( & V_2 , 2 ) ;
F_15 ( & V_24 , V_47 ) ;
if ( ! F_31 ( V_42 ) || ! F_31 ( V_44 ) ) {
F_32 () ;
return - V_22 ;
}
F_33 ( & V_48 ) ;
F_34 ( F_35 ( V_42 , V_44 ) ,
& F_27 ,
& V_46 , 1 ) ;
F_36 ( & V_48 ) ;
F_32 () ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_21 : - V_22 ;
}
void F_37 ( unsigned int V_6 , T_1 V_19 , void * V_20 ,
struct V_7 * V_49 )
{
* V_49 = (struct V_7 ) { . V_19 = V_19 , . V_20 = V_20 , } ;
F_7 ( V_6 , V_49 ) ;
}
static void F_38 ( const struct V_50 * V_50 ,
T_1 V_19 , void * V_20 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_6 ;
F_39 (cpu, cpumask) {
V_8 = & F_8 ( V_51 , V_6 ) ;
V_8 -> V_19 = V_19 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_2 = V_2 ;
}
F_40 ( & V_48 ) ;
F_39 (cpu, cpumask)
F_7 ( V_6 , & F_8 ( V_51 , V_6 ) ) ;
F_41 ( & V_48 ) ;
}
static int F_42 ( const struct V_50 * V_50 ,
T_1 V_19 , void * V_20 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_43 ( V_50 ) ) ;
F_38 ( V_50 , V_19 , V_20 , & V_2 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_21 : - V_22 ;
}
int F_44 ( const struct V_50 * V_50 , T_1 V_19 , void * V_20 )
{
int V_21 ;
F_45 ( & V_52 ) ;
V_21 = F_42 ( V_50 , V_19 , V_20 ) ;
F_46 ( & V_52 ) ;
return V_21 ;
}
int F_47 ( const struct V_50 * V_50 , T_1 V_19 , void * V_20 )
{
int V_21 ;
if ( ! F_48 ( & V_52 ) )
return - V_53 ;
V_21 = F_42 ( V_50 , V_19 , V_20 ) ;
F_46 ( & V_52 ) ;
return V_21 ;
}
static int F_49 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
unsigned long V_14 ;
int V_54 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
V_54 = ! F_50 ( & V_10 -> V_18 ) ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
return V_54 ;
}
static void F_51 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
int V_21 ;
V_55:
V_8 = NULL ;
F_52 ( & V_10 -> V_15 ) ;
if ( ! F_50 ( & V_10 -> V_18 ) ) {
V_8 = F_53 ( & V_10 -> V_18 ,
struct V_7 , V_17 ) ;
F_54 ( & V_8 -> V_17 ) ;
}
F_55 ( & V_10 -> V_15 ) ;
if ( V_8 ) {
T_1 V_19 = V_8 -> V_19 ;
void * V_20 = V_8 -> V_20 ;
struct V_1 * V_2 = V_8 -> V_2 ;
char V_56 [ V_57 ] V_58 ;
F_29 () ;
V_21 = V_19 ( V_20 ) ;
if ( V_21 )
V_2 -> V_21 = V_21 ;
F_32 () ;
F_56 ( F_57 () ,
L_1 ,
F_58 ( ( unsigned long ) V_19 , NULL , NULL , NULL ,
V_56 ) , V_20 ) ;
F_4 ( V_2 , true ) ;
goto V_55;
}
}
static void F_59 ( unsigned int V_6 )
{
F_60 ( V_6 , F_8 ( V_13 , V_6 ) ) ;
}
static void F_61 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
unsigned long V_14 ;
F_9 ( & V_10 -> V_15 , V_14 ) ;
F_62 (work, &stopper->works, list)
F_4 ( V_8 -> V_2 , false ) ;
V_10 -> V_16 = false ;
F_12 ( & V_10 -> V_15 , V_14 ) ;
}
static void F_63 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_52 ( & V_10 -> V_15 ) ;
V_10 -> V_16 = true ;
F_55 ( & V_10 -> V_15 ) ;
}
static int T_2 F_64 ( void )
{
unsigned int V_6 ;
F_65 (cpu) {
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_66 ( & V_10 -> V_15 ) ;
F_67 ( & V_10 -> V_18 ) ;
}
F_68 ( F_69 ( & V_59 ) ) ;
V_60 = true ;
return 0 ;
}
int F_70 ( int (* V_19)( void * ) , void * V_30 , const struct V_50 * V_61 )
{
struct V_23 V_24 = {
. V_19 = V_19 ,
. V_30 = V_30 ,
. V_28 = F_71 () ,
. V_35 = V_61 ,
} ;
if ( ! V_60 ) {
unsigned long V_14 ;
int V_21 ;
F_72 ( V_24 . V_28 != 1 ) ;
F_73 ( V_14 ) ;
F_25 () ;
V_21 = (* V_19)( V_30 ) ;
F_26 ( V_14 ) ;
return V_21 ;
}
F_15 ( & V_24 , V_47 ) ;
return F_44 ( V_36 , F_18 , & V_24 ) ;
}
int F_74 ( int (* V_19)( void * ) , void * V_30 , const struct V_50 * V_61 )
{
int V_21 ;
F_75 () ;
V_21 = F_70 ( V_19 , V_30 , V_61 ) ;
F_76 () ;
return V_21 ;
}
int F_77 ( int (* V_19)( void * ) , void * V_30 ,
const struct V_50 * V_61 )
{
struct V_23 V_24 = { . V_19 = V_19 , . V_30 = V_30 ,
. V_35 = V_61 } ;
struct V_1 V_2 ;
int V_21 ;
F_68 ( F_31 ( F_78 () ) ) ;
V_24 . V_28 = F_79 () + 1 ;
while ( ! F_48 ( & V_52 ) )
F_23 () ;
F_15 ( & V_24 , V_47 ) ;
F_1 ( & V_2 , F_79 () ) ;
F_38 ( V_62 , F_18 , & V_24 ,
& V_2 ) ;
V_21 = F_18 ( & V_24 ) ;
while ( ! F_80 ( & V_2 . V_4 ) )
F_23 () ;
F_46 ( & V_52 ) ;
return V_21 ? : V_2 . V_21 ;
}
