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
static void F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_8 ( & V_9 -> V_10 , & V_7 -> V_11 ) ;
F_9 ( V_7 -> V_12 ) ;
}
static void F_10 ( unsigned int V_13 , struct V_8 * V_9 )
{
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
unsigned long V_14 ;
F_12 ( & V_7 -> V_15 , V_14 ) ;
if ( V_7 -> V_16 )
F_7 ( V_7 , V_9 ) ;
else
F_4 ( V_9 -> V_2 , false ) ;
F_13 ( & V_7 -> V_15 , V_14 ) ;
}
int F_14 ( unsigned int V_13 , T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
struct V_8 V_9 = { . V_17 = V_17 , . V_18 = V_18 , . V_2 = & V_2 } ;
F_1 ( & V_2 , 1 ) ;
F_10 ( V_13 , & V_9 ) ;
F_15 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
static void F_16 ( struct V_21 * V_22 ,
enum V_23 V_24 )
{
F_2 ( & V_22 -> V_25 , V_22 -> V_26 ) ;
F_17 () ;
V_22 -> V_27 = V_24 ;
}
static void F_18 ( struct V_21 * V_22 )
{
if ( F_5 ( & V_22 -> V_25 ) )
F_16 ( V_22 , V_22 -> V_27 + 1 ) ;
}
static int F_19 ( void * V_28 )
{
struct V_21 * V_22 = V_28 ;
enum V_23 V_29 = V_30 ;
int V_13 = F_20 () , V_31 = 0 ;
unsigned long V_14 ;
bool V_32 ;
F_21 ( V_14 ) ;
if ( ! V_22 -> V_33 )
V_32 = V_13 == F_22 ( V_34 ) ;
else
V_32 = F_23 ( V_13 , V_22 -> V_33 ) ;
do {
F_24 () ;
if ( V_22 -> V_27 != V_29 ) {
V_29 = V_22 -> V_27 ;
switch ( V_29 ) {
case V_35 :
F_25 () ;
F_26 () ;
break;
case V_36 :
if ( V_32 )
V_31 = V_22 -> V_17 ( V_22 -> V_28 ) ;
break;
default:
break;
}
F_18 ( V_22 ) ;
}
} while ( V_29 != V_37 );
F_27 ( V_14 ) ;
return V_31 ;
}
static int F_28 ( int V_38 , struct V_8 * V_39 ,
int V_40 , struct V_8 * V_41 )
{
struct V_6 * V_42 = F_29 ( & V_6 , V_38 ) ;
struct V_6 * V_43 = F_29 ( & V_6 , V_40 ) ;
int V_31 ;
F_30 ( & V_44 , V_38 , V_40 ) ;
F_31 ( & V_42 -> V_15 ) ;
F_32 ( & V_43 -> V_15 , V_45 ) ;
V_31 = - V_20 ;
if ( ! V_42 -> V_16 || ! V_43 -> V_16 )
goto V_46;
V_31 = 0 ;
F_7 ( V_42 , V_39 ) ;
F_7 ( V_43 , V_41 ) ;
V_46:
F_33 ( & V_43 -> V_15 ) ;
F_34 ( & V_42 -> V_15 ) ;
F_35 ( & V_44 , V_38 , V_40 ) ;
return V_31 ;
}
int F_36 ( unsigned int V_38 , unsigned int V_40 , T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
struct V_8 V_39 , V_41 ;
struct V_21 V_22 ;
F_37 () ;
V_22 = (struct V_21 ) {
. V_17 = V_17 ,
. V_28 = V_18 ,
. V_26 = 2 ,
. V_33 = F_38 ( V_38 ) ,
} ;
V_39 = V_41 = (struct V_8 ) {
. V_17 = F_19 ,
. V_18 = & V_22 ,
. V_2 = & V_2
} ;
F_1 ( & V_2 , 2 ) ;
F_16 ( & V_22 , V_47 ) ;
if ( V_38 > V_40 )
F_39 ( V_38 , V_40 ) ;
if ( F_28 ( V_38 , & V_39 , V_40 , & V_41 ) ) {
F_40 () ;
return - V_20 ;
}
F_40 () ;
F_15 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
void F_41 ( unsigned int V_13 , T_1 V_17 , void * V_18 ,
struct V_8 * V_48 )
{
* V_48 = (struct V_8 ) { . V_17 = V_17 , . V_18 = V_18 , } ;
F_10 ( V_13 , V_48 ) ;
}
static void F_42 ( const struct V_49 * V_49 ,
T_1 V_17 , void * V_18 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_13 ;
F_43 ( & V_44 ) ;
F_44 (cpu, cpumask) {
V_9 = & F_11 ( V_6 . V_50 , V_13 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_2 = V_2 ;
F_10 ( V_13 , V_9 ) ;
}
F_45 ( & V_44 ) ;
}
static int F_46 ( const struct V_49 * V_49 ,
T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_47 ( V_49 ) ) ;
F_42 ( V_49 , V_17 , V_18 , & V_2 ) ;
F_15 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
int F_48 ( const struct V_49 * V_49 , T_1 V_17 , void * V_18 )
{
int V_19 ;
F_49 ( & V_51 ) ;
V_19 = F_46 ( V_49 , V_17 , V_18 ) ;
F_50 ( & V_51 ) ;
return V_19 ;
}
int F_51 ( const struct V_49 * V_49 , T_1 V_17 , void * V_18 )
{
int V_19 ;
if ( ! F_52 ( & V_51 ) )
return - V_52 ;
V_19 = F_46 ( V_49 , V_17 , V_18 ) ;
F_50 ( & V_51 ) ;
return V_19 ;
}
static int F_53 ( unsigned int V_13 )
{
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
unsigned long V_14 ;
int V_53 ;
F_12 ( & V_7 -> V_15 , V_14 ) ;
V_53 = ! F_54 ( & V_7 -> V_11 ) ;
F_13 ( & V_7 -> V_15 , V_14 ) ;
return V_53 ;
}
static void F_55 ( unsigned int V_13 )
{
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
struct V_8 * V_9 ;
int V_19 ;
V_54:
V_9 = NULL ;
F_31 ( & V_7 -> V_15 ) ;
if ( ! F_54 ( & V_7 -> V_11 ) ) {
V_9 = F_56 ( & V_7 -> V_11 ,
struct V_8 , V_10 ) ;
F_57 ( & V_9 -> V_10 ) ;
}
F_34 ( & V_7 -> V_15 ) ;
if ( V_9 ) {
T_1 V_17 = V_9 -> V_17 ;
void * V_18 = V_9 -> V_18 ;
struct V_1 * V_2 = V_9 -> V_2 ;
char V_55 [ V_56 ] V_57 ;
F_37 () ;
V_19 = V_17 ( V_18 ) ;
if ( V_19 )
V_2 -> V_19 = V_19 ;
F_40 () ;
F_58 ( F_59 () ,
L_1 ,
F_60 ( ( unsigned long ) V_17 , NULL , NULL , NULL ,
V_55 ) , V_18 ) ;
F_4 ( V_2 , true ) ;
goto V_54;
}
}
void F_61 ( int V_13 )
{
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
V_7 -> V_16 = false ;
F_62 ( V_7 -> V_12 ) ;
}
static void F_63 ( unsigned int V_13 )
{
F_64 ( V_13 , F_11 ( V_6 . V_12 , V_13 ) ) ;
}
static void F_65 ( unsigned int V_13 )
{
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
F_66 ( ! F_54 ( & V_7 -> V_11 ) ) ;
}
void F_67 ( int V_13 )
{
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
V_7 -> V_16 = true ;
F_68 ( V_7 -> V_12 ) ;
}
static int T_2 F_69 ( void )
{
unsigned int V_13 ;
F_70 (cpu) {
struct V_6 * V_7 = & F_11 ( V_6 , V_13 ) ;
F_71 ( & V_7 -> V_15 ) ;
F_72 ( & V_7 -> V_11 ) ;
}
F_73 ( F_74 ( & V_58 ) ) ;
F_67 ( F_75 () ) ;
V_59 = true ;
return 0 ;
}
static int F_76 ( T_1 V_17 , void * V_28 , const struct V_49 * V_60 )
{
struct V_21 V_22 = {
. V_17 = V_17 ,
. V_28 = V_28 ,
. V_26 = F_77 () ,
. V_33 = V_60 ,
} ;
if ( ! V_59 ) {
unsigned long V_14 ;
int V_19 ;
F_78 ( V_22 . V_26 != 1 ) ;
F_79 ( V_14 ) ;
F_26 () ;
V_19 = (* V_17)( V_28 ) ;
F_27 ( V_14 ) ;
return V_19 ;
}
F_16 ( & V_22 , V_47 ) ;
return F_48 ( V_34 , F_19 , & V_22 ) ;
}
int F_80 ( T_1 V_17 , void * V_28 , const struct V_49 * V_60 )
{
int V_19 ;
F_81 () ;
V_19 = F_76 ( V_17 , V_28 , V_60 ) ;
F_82 () ;
return V_19 ;
}
int F_83 ( T_1 V_17 , void * V_28 ,
const struct V_49 * V_60 )
{
struct V_21 V_22 = { . V_17 = V_17 , . V_28 = V_28 ,
. V_33 = V_60 } ;
struct V_1 V_2 ;
int V_19 ;
F_73 ( F_84 ( F_75 () ) ) ;
V_22 . V_26 = F_85 () + 1 ;
while ( ! F_52 ( & V_51 ) )
F_24 () ;
F_16 ( & V_22 , V_47 ) ;
F_1 ( & V_2 , F_85 () ) ;
F_42 ( V_61 , F_19 , & V_22 ,
& V_2 ) ;
V_19 = F_19 ( & V_22 ) ;
while ( ! F_86 ( & V_2 . V_4 ) )
F_24 () ;
F_50 ( & V_51 ) ;
return V_19 ? : V_2 . V_19 ;
}
