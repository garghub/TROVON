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
unsigned long V_10 ;
F_8 ( & V_7 -> V_11 , V_10 ) ;
if ( V_7 -> V_12 ) {
F_9 ( & V_9 -> V_13 , & V_7 -> V_14 ) ;
F_10 ( V_7 -> V_15 ) ;
} else
F_4 ( V_9 -> V_2 , false ) ;
F_11 ( & V_7 -> V_11 , V_10 ) ;
}
int F_12 ( unsigned int V_16 , T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
struct V_8 V_9 = { . V_17 = V_17 , . V_18 = V_18 , . V_2 = & V_2 } ;
F_1 ( & V_2 , 1 ) ;
F_7 ( & F_13 ( V_6 , V_16 ) , & V_9 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
void F_15 ( unsigned int V_16 , T_1 V_17 , void * V_18 ,
struct V_8 * V_21 )
{
* V_21 = (struct V_8 ) { . V_17 = V_17 , . V_18 = V_18 , } ;
F_7 ( & F_13 ( V_6 , V_16 ) , V_21 ) ;
}
static void F_16 ( const struct V_22 * V_22 ,
T_1 V_17 , void * V_18 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
unsigned int V_16 ;
F_17 (cpu, cpumask) {
V_9 = & F_13 ( V_23 , V_16 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_18 = V_18 ;
V_9 -> V_2 = V_2 ;
}
F_18 () ;
F_17 (cpu, cpumask)
F_7 ( & F_13 ( V_6 , V_16 ) ,
& F_13 ( V_23 , V_16 ) ) ;
F_19 () ;
}
static int F_20 ( const struct V_22 * V_22 ,
T_1 V_17 , void * V_18 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_21 ( V_22 ) ) ;
F_16 ( V_22 , V_17 , V_18 , & V_2 ) ;
F_14 ( & V_2 . V_4 ) ;
return V_2 . V_5 ? V_2 . V_19 : - V_20 ;
}
int F_22 ( const struct V_22 * V_22 , T_1 V_17 , void * V_18 )
{
int V_19 ;
F_23 ( & V_24 ) ;
V_19 = F_20 ( V_22 , V_17 , V_18 ) ;
F_24 ( & V_24 ) ;
return V_19 ;
}
int F_25 ( const struct V_22 * V_22 , T_1 V_17 , void * V_18 )
{
int V_19 ;
if ( ! F_26 ( & V_24 ) )
return - V_25 ;
V_19 = F_20 ( V_22 , V_17 , V_18 ) ;
F_24 ( & V_24 ) ;
return V_19 ;
}
static int F_27 ( void * V_26 )
{
struct V_6 * V_7 = V_26 ;
struct V_8 * V_9 ;
int V_19 ;
V_27:
F_28 ( V_28 ) ;
if ( F_29 () ) {
F_30 ( V_29 ) ;
return 0 ;
}
V_9 = NULL ;
F_31 ( & V_7 -> V_11 ) ;
if ( ! F_32 ( & V_7 -> V_14 ) ) {
V_9 = F_33 ( & V_7 -> V_14 ,
struct V_8 , V_13 ) ;
F_34 ( & V_9 -> V_13 ) ;
}
F_35 ( & V_7 -> V_11 ) ;
if ( V_9 ) {
T_1 V_17 = V_9 -> V_17 ;
void * V_18 = V_9 -> V_18 ;
struct V_1 * V_2 = V_9 -> V_2 ;
char V_30 [ V_31 ] V_32 ;
F_30 ( V_29 ) ;
F_18 () ;
V_19 = V_17 ( V_18 ) ;
if ( V_19 )
V_2 -> V_19 = V_19 ;
F_19 () ;
F_36 ( F_37 () ,
L_1 ,
F_38 ( ( unsigned long ) V_17 , NULL , NULL , NULL ,
V_30 ) , V_18 ) ;
F_4 ( V_2 , true ) ;
} else
F_39 () ;
goto V_27;
}
static int T_2 F_40 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_36 )
{
unsigned int V_16 = ( unsigned long ) V_36 ;
struct V_6 * V_7 = & F_13 ( V_6 , V_16 ) ;
struct V_37 * V_38 ;
switch ( V_35 & ~ V_39 ) {
case V_40 :
F_41 ( V_7 -> V_15 || V_7 -> V_12 ||
! F_32 ( & V_7 -> V_14 ) ) ;
V_38 = F_42 ( F_27 ,
V_7 ,
F_43 ( V_16 ) ,
L_2 , V_16 ) ;
if ( F_44 ( V_38 ) )
return F_45 ( F_46 ( V_38 ) ) ;
F_47 ( V_38 ) ;
F_48 ( V_38 , V_16 ) ;
F_49 ( V_16 , V_38 ) ;
V_7 -> V_15 = V_38 ;
break;
case V_41 :
F_10 ( V_7 -> V_15 ) ;
F_31 ( & V_7 -> V_11 ) ;
V_7 -> V_12 = true ;
F_35 ( & V_7 -> V_11 ) ;
break;
#ifdef F_50
case V_42 :
case V_43 :
{
struct V_8 * V_9 ;
F_49 ( V_16 , NULL ) ;
F_51 ( V_7 -> V_15 ) ;
F_31 ( & V_7 -> V_11 ) ;
F_52 (work, &stopper->works, list)
F_4 ( V_9 -> V_2 , false ) ;
V_7 -> V_12 = false ;
F_35 ( & V_7 -> V_11 ) ;
F_53 ( V_7 -> V_15 ) ;
V_7 -> V_15 = NULL ;
break;
}
#endif
}
return V_44 ;
}
static int T_3 F_54 ( void )
{
void * V_45 = ( void * ) ( long ) F_55 () ;
unsigned int V_16 ;
int V_46 ;
F_56 (cpu) {
struct V_6 * V_7 = & F_13 ( V_6 , V_16 ) ;
F_57 ( & V_7 -> V_11 ) ;
F_58 ( & V_7 -> V_14 ) ;
}
V_46 = F_40 ( & V_47 , V_40 ,
V_45 ) ;
F_41 ( V_46 != V_44 ) ;
F_40 ( & V_47 , V_41 , V_45 ) ;
F_59 ( & V_47 ) ;
V_48 = true ;
return 0 ;
}
static void F_60 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
F_2 ( & V_50 -> V_53 , V_50 -> V_54 ) ;
F_61 () ;
V_50 -> V_55 = V_52 ;
}
static void F_62 ( struct V_49 * V_50 )
{
if ( F_5 ( & V_50 -> V_53 ) )
F_60 ( V_50 , V_50 -> V_55 + 1 ) ;
}
static int F_63 ( void * V_26 )
{
struct V_49 * V_50 = V_26 ;
enum V_51 V_56 = V_57 ;
int V_16 = F_55 () , V_46 = 0 ;
unsigned long V_10 ;
bool V_58 ;
F_64 ( V_10 ) ;
if ( ! V_50 -> V_59 )
V_58 = V_16 == F_65 ( V_60 ) ;
else
V_58 = F_66 ( V_16 , V_50 -> V_59 ) ;
do {
F_67 () ;
if ( V_50 -> V_55 != V_56 ) {
V_56 = V_50 -> V_55 ;
switch ( V_56 ) {
case V_61 :
F_68 () ;
F_69 () ;
break;
case V_62 :
if ( V_58 )
V_46 = V_50 -> V_17 ( V_50 -> V_26 ) ;
break;
default:
break;
}
F_62 ( V_50 ) ;
}
} while ( V_56 != V_63 );
F_70 ( V_10 ) ;
return V_46 ;
}
int F_71 ( int (* V_17)( void * ) , void * V_26 , const struct V_22 * V_64 )
{
struct V_49 V_50 = { . V_17 = V_17 , . V_26 = V_26 ,
. V_54 = F_72 () ,
. V_59 = V_64 } ;
if ( ! V_48 ) {
unsigned long V_10 ;
int V_19 ;
F_73 ( V_50 . V_54 != 1 ) ;
F_74 ( V_10 ) ;
F_69 () ;
V_19 = (* V_17)( V_26 ) ;
F_70 ( V_10 ) ;
return V_19 ;
}
F_60 ( & V_50 , V_65 ) ;
return F_22 ( V_60 , F_63 , & V_50 ) ;
}
int F_75 ( int (* V_17)( void * ) , void * V_26 , const struct V_22 * V_64 )
{
int V_19 ;
F_76 () ;
V_19 = F_71 ( V_17 , V_26 , V_64 ) ;
F_77 () ;
return V_19 ;
}
int F_78 ( int (* V_17)( void * ) , void * V_26 ,
const struct V_22 * V_64 )
{
struct V_49 V_50 = { . V_17 = V_17 , . V_26 = V_26 ,
. V_59 = V_64 } ;
struct V_1 V_2 ;
int V_19 ;
F_41 ( F_79 ( F_80 () ) ) ;
V_50 . V_54 = F_81 () + 1 ;
while ( ! F_26 ( & V_24 ) )
F_67 () ;
F_60 ( & V_50 , V_65 ) ;
F_1 ( & V_2 , F_81 () ) ;
F_16 ( V_66 , F_63 , & V_50 ,
& V_2 ) ;
V_19 = F_63 ( & V_50 ) ;
while ( ! F_82 ( & V_2 . V_4 ) )
F_67 () ;
F_24 ( & V_24 ) ;
return V_19 ? : V_2 . V_19 ;
}
