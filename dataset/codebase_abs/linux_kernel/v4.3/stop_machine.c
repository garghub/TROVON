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
unsigned long V_11 ;
F_9 ( & V_10 -> V_12 , V_11 ) ;
if ( V_10 -> V_13 ) {
F_10 ( & V_8 -> V_14 , & V_10 -> V_15 ) ;
F_11 ( V_10 -> V_16 ) ;
} else
F_4 ( V_8 -> V_2 , false ) ;
F_12 ( & V_10 -> V_12 , V_11 ) ;
}
int F_13 ( unsigned int V_6 , T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
struct V_7 V_8 = { . V_17 = V_17 , . V_18 = V_18 , . V_2 = & V_2 } ;
F_1 ( & V_2 , 1 ) ;
F_7 ( V_6 , & V_8 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
static void F_15 ( struct V_21 * V_22 ,
enum V_23 V_24 )
{
F_2 ( & V_22 -> V_25 , V_22 -> V_26 ) ;
F_16 () ;
V_22 -> V_27 = V_24 ;
}
static void F_17 ( struct V_21 * V_22 )
{
if ( F_5 ( & V_22 -> V_25 ) )
F_15 ( V_22 , V_22 -> V_27 + 1 ) ;
}
static int F_18 ( void * V_28 )
{
struct V_21 * V_22 = V_28 ;
enum V_23 V_29 = V_30 ;
int V_6 = F_19 () , V_31 = 0 ;
unsigned long V_11 ;
bool V_32 ;
F_20 ( V_11 ) ;
if ( ! V_22 -> V_33 )
V_32 = V_6 == F_21 ( V_34 ) ;
else
V_32 = F_22 ( V_6 , V_22 -> V_33 ) ;
do {
F_23 () ;
if ( V_22 -> V_27 != V_29 ) {
V_29 = V_22 -> V_27 ;
switch ( V_29 ) {
case V_35 :
F_24 () ;
F_25 () ;
break;
case V_36 :
if ( V_32 )
V_31 = V_22 -> V_17 ( V_22 -> V_28 ) ;
break;
default:
break;
}
F_17 ( V_22 ) ;
}
} while ( V_29 != V_37 );
F_26 ( V_11 ) ;
return V_31 ;
}
int F_27 ( unsigned int V_38 , unsigned int V_39 , T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
struct V_7 V_40 , V_41 ;
struct V_21 V_22 ;
F_28 () ;
V_22 = (struct V_21 ) {
. V_17 = V_17 ,
. V_28 = V_18 ,
. V_26 = 2 ,
. V_33 = F_29 ( V_38 ) ,
} ;
V_40 = V_41 = (struct V_7 ) {
. V_17 = F_18 ,
. V_18 = & V_22 ,
. V_2 = & V_2
} ;
F_1 ( & V_2 , 2 ) ;
F_15 ( & V_22 , V_42 ) ;
if ( ! F_30 ( V_38 ) || ! F_30 ( V_39 ) ) {
F_31 () ;
return - V_20 ;
}
F_32 ( & V_43 , V_38 , V_39 ) ;
F_7 ( V_38 , & V_40 ) ;
F_7 ( V_39 , & V_41 ) ;
F_33 ( & V_43 , V_38 , V_39 ) ;
F_31 () ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
void F_34 ( unsigned int V_6 , T_1 V_17 , void * V_18 ,
struct V_7 * V_44 )
{
* V_44 = (struct V_7 ) { . V_17 = V_17 , . V_18 = V_18 , } ;
F_7 ( V_6 , V_44 ) ;
}
static void F_35 ( const struct V_45 * V_45 ,
T_1 V_17 , void * V_18 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_6 ;
F_36 ( & V_43 ) ;
F_37 (cpu, cpumask) {
V_8 = & F_8 ( V_9 . V_46 , V_6 ) ;
V_8 -> V_17 = V_17 ;
V_8 -> V_18 = V_18 ;
V_8 -> V_2 = V_2 ;
F_7 ( V_6 , V_8 ) ;
}
F_38 ( & V_43 ) ;
}
static int F_39 ( const struct V_45 * V_45 ,
T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_40 ( V_45 ) ) ;
F_35 ( V_45 , V_17 , V_18 , & V_2 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
int F_41 ( const struct V_45 * V_45 , T_1 V_17 , void * V_18 )
{
int V_19 ;
F_42 ( & V_47 ) ;
V_19 = F_39 ( V_45 , V_17 , V_18 ) ;
F_43 ( & V_47 ) ;
return V_19 ;
}
int F_44 ( const struct V_45 * V_45 , T_1 V_17 , void * V_18 )
{
int V_19 ;
if ( ! F_45 ( & V_47 ) )
return - V_48 ;
V_19 = F_39 ( V_45 , V_17 , V_18 ) ;
F_43 ( & V_47 ) ;
return V_19 ;
}
static int F_46 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
unsigned long V_11 ;
int V_49 ;
F_9 ( & V_10 -> V_12 , V_11 ) ;
V_49 = ! F_47 ( & V_10 -> V_15 ) ;
F_12 ( & V_10 -> V_12 , V_11 ) ;
return V_49 ;
}
static void F_48 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 ;
int V_19 ;
V_50:
V_8 = NULL ;
F_49 ( & V_10 -> V_12 ) ;
if ( ! F_47 ( & V_10 -> V_15 ) ) {
V_8 = F_50 ( & V_10 -> V_15 ,
struct V_7 , V_14 ) ;
F_51 ( & V_8 -> V_14 ) ;
}
F_52 ( & V_10 -> V_12 ) ;
if ( V_8 ) {
T_1 V_17 = V_8 -> V_17 ;
void * V_18 = V_8 -> V_18 ;
struct V_1 * V_2 = V_8 -> V_2 ;
char V_51 [ V_52 ] V_53 ;
F_28 () ;
V_19 = V_17 ( V_18 ) ;
if ( V_19 )
V_2 -> V_19 = V_19 ;
F_31 () ;
F_53 ( F_54 () ,
L_1 ,
F_55 ( ( unsigned long ) V_17 , NULL , NULL , NULL ,
V_51 ) , V_18 ) ;
F_4 ( V_2 , true ) ;
goto V_50;
}
}
static void F_56 ( unsigned int V_6 )
{
F_57 ( V_6 , F_8 ( V_9 . V_16 , V_6 ) ) ;
}
static void F_58 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
struct V_7 * V_8 , * V_54 ;
unsigned long V_11 ;
F_9 ( & V_10 -> V_12 , V_11 ) ;
F_59 (work, tmp, &stopper->works, list) {
F_51 ( & V_8 -> V_14 ) ;
F_4 ( V_8 -> V_2 , false ) ;
}
V_10 -> V_13 = false ;
F_12 ( & V_10 -> V_12 , V_11 ) ;
}
static void F_60 ( unsigned int V_6 )
{
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_49 ( & V_10 -> V_12 ) ;
V_10 -> V_13 = true ;
F_52 ( & V_10 -> V_12 ) ;
}
static int T_2 F_61 ( void )
{
unsigned int V_6 ;
F_62 (cpu) {
struct V_9 * V_10 = & F_8 ( V_9 , V_6 ) ;
F_63 ( & V_10 -> V_12 ) ;
F_64 ( & V_10 -> V_15 ) ;
}
F_65 ( F_66 ( & V_55 ) ) ;
V_56 = true ;
return 0 ;
}
static int F_67 ( T_1 V_17 , void * V_28 , const struct V_45 * V_57 )
{
struct V_21 V_22 = {
. V_17 = V_17 ,
. V_28 = V_28 ,
. V_26 = F_68 () ,
. V_33 = V_57 ,
} ;
if ( ! V_56 ) {
unsigned long V_11 ;
int V_19 ;
F_69 ( V_22 . V_26 != 1 ) ;
F_70 ( V_11 ) ;
F_25 () ;
V_19 = (* V_17)( V_28 ) ;
F_26 ( V_11 ) ;
return V_19 ;
}
F_15 ( & V_22 , V_42 ) ;
return F_41 ( V_34 , F_18 , & V_22 ) ;
}
int F_71 ( T_1 V_17 , void * V_28 , const struct V_45 * V_57 )
{
int V_19 ;
F_72 () ;
V_19 = F_67 ( V_17 , V_28 , V_57 ) ;
F_73 () ;
return V_19 ;
}
int F_74 ( T_1 V_17 , void * V_28 ,
const struct V_45 * V_57 )
{
struct V_21 V_22 = { . V_17 = V_17 , . V_28 = V_28 ,
. V_33 = V_57 } ;
struct V_1 V_2 ;
int V_19 ;
F_65 ( F_30 ( F_75 () ) ) ;
V_22 . V_26 = F_76 () + 1 ;
while ( ! F_45 ( & V_47 ) )
F_23 () ;
F_15 ( & V_22 , V_42 ) ;
F_1 ( & V_2 , F_76 () ) ;
F_35 ( V_58 , F_18 , & V_22 ,
& V_2 ) ;
V_19 = F_18 ( & V_22 ) ;
while ( ! F_77 ( & V_2 . V_4 ) )
F_23 () ;
F_43 ( & V_47 ) ;
return V_19 ? : V_2 . V_19 ;
}
