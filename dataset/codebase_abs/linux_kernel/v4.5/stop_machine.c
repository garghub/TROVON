static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( & V_2 -> V_3 , V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( & V_2 -> V_3 ) )
F_6 ( & V_2 -> V_4 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_8 ( & V_8 -> V_9 , & V_6 -> V_10 ) ;
F_9 ( V_6 -> V_11 ) ;
}
static bool F_10 ( unsigned int V_12 , struct V_7 * V_8 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
unsigned long V_13 ;
bool V_14 ;
F_12 ( & V_6 -> V_15 , V_13 ) ;
V_14 = V_6 -> V_14 ;
if ( V_14 )
F_7 ( V_6 , V_8 ) ;
else if ( V_8 -> V_2 )
F_4 ( V_8 -> V_2 ) ;
F_13 ( & V_6 -> V_15 , V_13 ) ;
return V_14 ;
}
int F_14 ( unsigned int V_12 , T_1 V_16 , void * V_17 )
{
struct V_1 V_2 ;
struct V_7 V_8 = { . V_16 = V_16 , . V_17 = V_17 , . V_2 = & V_2 } ;
F_1 ( & V_2 , 1 ) ;
if ( ! F_10 ( V_12 , & V_8 ) )
return - V_18 ;
F_15 ( & V_2 . V_4 ) ;
return V_2 . V_19 ;
}
static void F_16 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_2 ( & V_21 -> V_24 , V_21 -> V_25 ) ;
F_17 () ;
V_21 -> V_26 = V_23 ;
}
static void F_18 ( struct V_20 * V_21 )
{
if ( F_5 ( & V_21 -> V_24 ) )
F_16 ( V_21 , V_21 -> V_26 + 1 ) ;
}
static int F_19 ( void * V_27 )
{
struct V_20 * V_21 = V_27 ;
enum V_22 V_28 = V_29 ;
int V_12 = F_20 () , V_30 = 0 ;
unsigned long V_13 ;
bool V_31 ;
F_21 ( V_13 ) ;
if ( ! V_21 -> V_32 )
V_31 = V_12 == F_22 ( V_33 ) ;
else
V_31 = F_23 ( V_12 , V_21 -> V_32 ) ;
do {
F_24 () ;
if ( V_21 -> V_26 != V_28 ) {
V_28 = V_21 -> V_26 ;
switch ( V_28 ) {
case V_34 :
F_25 () ;
F_26 () ;
break;
case V_35 :
if ( V_31 )
V_30 = V_21 -> V_16 ( V_21 -> V_27 ) ;
break;
default:
break;
}
F_18 ( V_21 ) ;
}
} while ( V_28 != V_36 );
F_27 ( V_13 ) ;
return V_30 ;
}
static int F_28 ( int V_37 , struct V_7 * V_38 ,
int V_39 , struct V_7 * V_40 )
{
struct V_5 * V_41 = F_29 ( & V_5 , V_37 ) ;
struct V_5 * V_42 = F_29 ( & V_5 , V_39 ) ;
int V_30 ;
F_30 ( & V_43 , V_37 , V_39 ) ;
F_31 ( & V_41 -> V_15 ) ;
F_32 ( & V_42 -> V_15 , V_44 ) ;
V_30 = - V_18 ;
if ( ! V_41 -> V_14 || ! V_42 -> V_14 )
goto V_45;
V_30 = 0 ;
F_7 ( V_41 , V_38 ) ;
F_7 ( V_42 , V_40 ) ;
V_45:
F_33 ( & V_42 -> V_15 ) ;
F_34 ( & V_41 -> V_15 ) ;
F_35 ( & V_43 , V_37 , V_39 ) ;
return V_30 ;
}
int F_36 ( unsigned int V_37 , unsigned int V_39 , T_1 V_16 , void * V_17 )
{
struct V_1 V_2 ;
struct V_7 V_38 , V_40 ;
struct V_20 V_21 ;
V_21 = (struct V_20 ) {
. V_16 = V_16 ,
. V_27 = V_17 ,
. V_25 = 2 ,
. V_32 = F_37 ( V_37 ) ,
} ;
V_38 = V_40 = (struct V_7 ) {
. V_16 = F_19 ,
. V_17 = & V_21 ,
. V_2 = & V_2
} ;
F_1 ( & V_2 , 2 ) ;
F_16 ( & V_21 , V_46 ) ;
if ( V_37 > V_39 )
F_38 ( V_37 , V_39 ) ;
if ( F_28 ( V_37 , & V_38 , V_39 , & V_40 ) )
return - V_18 ;
F_15 ( & V_2 . V_4 ) ;
return V_2 . V_19 ;
}
bool F_39 ( unsigned int V_12 , T_1 V_16 , void * V_17 ,
struct V_7 * V_47 )
{
* V_47 = (struct V_7 ) { . V_16 = V_16 , . V_17 = V_17 , } ;
return F_10 ( V_12 , V_47 ) ;
}
static bool F_40 ( const struct V_48 * V_48 ,
T_1 V_16 , void * V_17 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_12 ;
bool V_49 = false ;
F_41 ( & V_43 ) ;
F_42 (cpu, cpumask) {
V_8 = & F_11 ( V_5 . V_50 , V_12 ) ;
V_8 -> V_16 = V_16 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_2 = V_2 ;
if ( F_10 ( V_12 , V_8 ) )
V_49 = true ;
}
F_43 ( & V_43 ) ;
return V_49 ;
}
static int F_44 ( const struct V_48 * V_48 ,
T_1 V_16 , void * V_17 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_45 ( V_48 ) ) ;
if ( ! F_40 ( V_48 , V_16 , V_17 , & V_2 ) )
return - V_18 ;
F_15 ( & V_2 . V_4 ) ;
return V_2 . V_19 ;
}
int F_46 ( const struct V_48 * V_48 , T_1 V_16 , void * V_17 )
{
int V_19 ;
F_47 ( & V_51 ) ;
V_19 = F_44 ( V_48 , V_16 , V_17 ) ;
F_48 ( & V_51 ) ;
return V_19 ;
}
int F_49 ( const struct V_48 * V_48 , T_1 V_16 , void * V_17 )
{
int V_19 ;
if ( ! F_50 ( & V_51 ) )
return - V_52 ;
V_19 = F_44 ( V_48 , V_16 , V_17 ) ;
F_48 ( & V_51 ) ;
return V_19 ;
}
static int F_51 ( unsigned int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
unsigned long V_13 ;
int V_53 ;
F_12 ( & V_6 -> V_15 , V_13 ) ;
V_53 = ! F_52 ( & V_6 -> V_10 ) ;
F_13 ( & V_6 -> V_15 , V_13 ) ;
return V_53 ;
}
static void F_53 ( unsigned int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
struct V_7 * V_8 ;
V_54:
V_8 = NULL ;
F_31 ( & V_6 -> V_15 ) ;
if ( ! F_52 ( & V_6 -> V_10 ) ) {
V_8 = F_54 ( & V_6 -> V_10 ,
struct V_7 , V_9 ) ;
F_55 ( & V_8 -> V_9 ) ;
}
F_34 ( & V_6 -> V_15 ) ;
if ( V_8 ) {
T_1 V_16 = V_8 -> V_16 ;
void * V_17 = V_8 -> V_17 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_19 ;
F_56 () ;
V_19 = V_16 ( V_17 ) ;
if ( V_2 ) {
if ( V_19 )
V_2 -> V_19 = V_19 ;
F_4 ( V_2 ) ;
}
F_57 () ;
F_58 ( F_59 () ,
L_1 , V_16 , V_17 ) ;
goto V_54;
}
}
void F_60 ( int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
V_6 -> V_14 = false ;
F_61 ( V_6 -> V_11 ) ;
}
static void F_62 ( unsigned int V_12 )
{
F_63 ( V_12 , F_11 ( V_5 . V_11 , V_12 ) ) ;
}
static void F_64 ( unsigned int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
F_65 ( ! F_52 ( & V_6 -> V_10 ) ) ;
}
void F_66 ( int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
V_6 -> V_14 = true ;
F_67 ( V_6 -> V_11 ) ;
}
static int T_2 F_68 ( void )
{
unsigned int V_12 ;
F_69 (cpu) {
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
F_70 ( & V_6 -> V_15 ) ;
F_71 ( & V_6 -> V_10 ) ;
}
F_72 ( F_73 ( & V_55 ) ) ;
F_66 ( F_74 () ) ;
V_56 = true ;
return 0 ;
}
static int F_75 ( T_1 V_16 , void * V_27 , const struct V_48 * V_57 )
{
struct V_20 V_21 = {
. V_16 = V_16 ,
. V_27 = V_27 ,
. V_25 = F_76 () ,
. V_32 = V_57 ,
} ;
if ( ! V_56 ) {
unsigned long V_13 ;
int V_19 ;
F_77 ( V_21 . V_25 != 1 ) ;
F_78 ( V_13 ) ;
F_26 () ;
V_19 = (* V_16)( V_27 ) ;
F_27 ( V_13 ) ;
return V_19 ;
}
F_16 ( & V_21 , V_46 ) ;
return F_46 ( V_33 , F_19 , & V_21 ) ;
}
int F_79 ( T_1 V_16 , void * V_27 , const struct V_48 * V_57 )
{
int V_19 ;
F_80 () ;
V_19 = F_75 ( V_16 , V_27 , V_57 ) ;
F_81 () ;
return V_19 ;
}
int F_82 ( T_1 V_16 , void * V_27 ,
const struct V_48 * V_57 )
{
struct V_20 V_21 = { . V_16 = V_16 , . V_27 = V_27 ,
. V_32 = V_57 } ;
struct V_1 V_2 ;
int V_19 ;
F_72 ( F_83 ( F_74 () ) ) ;
V_21 . V_25 = F_84 () + 1 ;
while ( ! F_50 ( & V_51 ) )
F_24 () ;
F_16 ( & V_21 , V_46 ) ;
F_1 ( & V_2 , F_84 () ) ;
F_40 ( V_58 , F_19 , & V_21 ,
& V_2 ) ;
V_19 = F_19 ( & V_21 ) ;
while ( ! F_85 ( & V_2 . V_4 ) )
F_24 () ;
F_48 ( & V_51 ) ;
return V_19 ? : V_2 . V_19 ;
}
