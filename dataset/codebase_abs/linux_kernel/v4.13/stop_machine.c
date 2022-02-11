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
F_15 () ;
F_16 ( & V_2 . V_4 ) ;
return V_2 . V_19 ;
}
static void F_17 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_2 ( & V_21 -> V_24 , V_21 -> V_25 ) ;
F_18 () ;
V_21 -> V_26 = V_23 ;
}
static void F_19 ( struct V_20 * V_21 )
{
if ( F_5 ( & V_21 -> V_24 ) )
F_17 ( V_21 , V_21 -> V_26 + 1 ) ;
}
static int F_20 ( void * V_27 )
{
struct V_20 * V_21 = V_27 ;
enum V_22 V_28 = V_29 ;
int V_12 = F_21 () , V_30 = 0 ;
unsigned long V_13 ;
bool V_31 ;
F_22 ( V_13 ) ;
if ( ! V_21 -> V_32 )
V_31 = V_12 == F_23 ( V_33 ) ;
else
V_31 = F_24 ( V_12 , V_21 -> V_32 ) ;
do {
F_25 () ;
if ( V_21 -> V_26 != V_28 ) {
V_28 = V_21 -> V_26 ;
switch ( V_28 ) {
case V_34 :
F_26 () ;
F_27 () ;
break;
case V_35 :
if ( V_31 )
V_30 = V_21 -> V_16 ( V_21 -> V_27 ) ;
break;
default:
break;
}
F_19 ( V_21 ) ;
} else if ( V_28 > V_36 ) {
F_28 () ;
}
} while ( V_28 != V_37 );
F_29 ( V_13 ) ;
return V_30 ;
}
static int F_30 ( int V_38 , struct V_7 * V_39 ,
int V_40 , struct V_7 * V_41 )
{
struct V_5 * V_42 = F_31 ( & V_5 , V_38 ) ;
struct V_5 * V_43 = F_31 ( & V_5 , V_40 ) ;
int V_30 ;
V_44:
F_32 ( & V_42 -> V_15 ) ;
F_33 ( & V_43 -> V_15 , V_45 ) ;
V_30 = - V_18 ;
if ( ! V_42 -> V_14 || ! V_43 -> V_14 )
goto V_46;
V_30 = - V_47 ;
if ( F_34 ( V_48 ) )
goto V_46;
V_30 = 0 ;
F_7 ( V_42 , V_39 ) ;
F_7 ( V_43 , V_41 ) ;
V_46:
F_35 ( & V_43 -> V_15 ) ;
F_36 ( & V_42 -> V_15 ) ;
if ( F_34 ( V_30 == - V_47 ) ) {
while ( V_48 )
F_37 () ;
goto V_44;
}
return V_30 ;
}
int F_38 ( unsigned int V_38 , unsigned int V_40 , T_1 V_16 , void * V_17 )
{
struct V_1 V_2 ;
struct V_7 V_39 , V_41 ;
struct V_20 V_21 ;
V_21 = (struct V_20 ) {
. V_16 = V_16 ,
. V_27 = V_17 ,
. V_25 = 2 ,
. V_32 = F_39 ( V_38 ) ,
} ;
V_39 = V_41 = (struct V_7 ) {
. V_16 = F_20 ,
. V_17 = & V_21 ,
. V_2 = & V_2
} ;
F_1 ( & V_2 , 2 ) ;
F_17 ( & V_21 , V_36 ) ;
if ( V_38 > V_40 )
F_40 ( V_38 , V_40 ) ;
if ( F_30 ( V_38 , & V_39 , V_40 , & V_41 ) )
return - V_18 ;
F_16 ( & V_2 . V_4 ) ;
return V_2 . V_19 ;
}
bool F_41 ( unsigned int V_12 , T_1 V_16 , void * V_17 ,
struct V_7 * V_49 )
{
* V_49 = (struct V_7 ) { . V_16 = V_16 , . V_17 = V_17 , } ;
return F_10 ( V_12 , V_49 ) ;
}
static bool F_42 ( const struct V_50 * V_50 ,
T_1 V_16 , void * V_17 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
unsigned int V_12 ;
bool V_51 = false ;
F_43 () ;
V_48 = true ;
F_44 (cpu, cpumask) {
V_8 = & F_11 ( V_5 . V_52 , V_12 ) ;
V_8 -> V_16 = V_16 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_2 = V_2 ;
if ( F_10 ( V_12 , V_8 ) )
V_51 = true ;
}
V_48 = false ;
F_45 () ;
return V_51 ;
}
static int F_46 ( const struct V_50 * V_50 ,
T_1 V_16 , void * V_17 )
{
struct V_1 V_2 ;
F_1 ( & V_2 , F_47 ( V_50 ) ) ;
if ( ! F_42 ( V_50 , V_16 , V_17 , & V_2 ) )
return - V_18 ;
F_16 ( & V_2 . V_4 ) ;
return V_2 . V_19 ;
}
int F_48 ( const struct V_50 * V_50 , T_1 V_16 , void * V_17 )
{
int V_19 ;
F_49 ( & V_53 ) ;
V_19 = F_46 ( V_50 , V_16 , V_17 ) ;
F_50 ( & V_53 ) ;
return V_19 ;
}
int F_51 ( const struct V_50 * V_50 , T_1 V_16 , void * V_17 )
{
int V_19 ;
if ( ! F_52 ( & V_53 ) )
return - V_54 ;
V_19 = F_46 ( V_50 , V_16 , V_17 ) ;
F_50 ( & V_53 ) ;
return V_19 ;
}
static int F_53 ( unsigned int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
unsigned long V_13 ;
int V_55 ;
F_12 ( & V_6 -> V_15 , V_13 ) ;
V_55 = ! F_54 ( & V_6 -> V_10 ) ;
F_13 ( & V_6 -> V_15 , V_13 ) ;
return V_55 ;
}
static void F_55 ( unsigned int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
struct V_7 * V_8 ;
V_56:
V_8 = NULL ;
F_32 ( & V_6 -> V_15 ) ;
if ( ! F_54 ( & V_6 -> V_10 ) ) {
V_8 = F_56 ( & V_6 -> V_10 ,
struct V_7 , V_9 ) ;
F_57 ( & V_8 -> V_9 ) ;
}
F_36 ( & V_6 -> V_15 ) ;
if ( V_8 ) {
T_1 V_16 = V_8 -> V_16 ;
void * V_17 = V_8 -> V_17 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_19 ;
F_58 () ;
V_19 = V_16 ( V_17 ) ;
if ( V_2 ) {
if ( V_19 )
V_2 -> V_19 = V_19 ;
F_4 ( V_2 ) ;
}
F_59 () ;
F_60 ( F_61 () ,
L_1 , V_16 , V_17 ) ;
goto V_56;
}
}
void F_62 ( int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
V_6 -> V_14 = false ;
F_63 ( V_6 -> V_11 ) ;
}
static void F_64 ( unsigned int V_12 )
{
F_65 ( V_12 , F_11 ( V_5 . V_11 , V_12 ) ) ;
}
static void F_66 ( unsigned int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
F_67 ( ! F_54 ( & V_6 -> V_10 ) ) ;
}
void F_68 ( int V_12 )
{
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
V_6 -> V_14 = true ;
F_69 ( V_6 -> V_11 ) ;
}
static int T_2 F_70 ( void )
{
unsigned int V_12 ;
F_71 (cpu) {
struct V_5 * V_6 = & F_11 ( V_5 , V_12 ) ;
F_72 ( & V_6 -> V_15 ) ;
F_73 ( & V_6 -> V_10 ) ;
}
F_74 ( F_75 ( & V_57 ) ) ;
F_68 ( F_76 () ) ;
V_58 = true ;
return 0 ;
}
int F_77 ( T_1 V_16 , void * V_27 ,
const struct V_50 * V_59 )
{
struct V_20 V_21 = {
. V_16 = V_16 ,
. V_27 = V_27 ,
. V_25 = F_78 () ,
. V_32 = V_59 ,
} ;
F_79 () ;
if ( ! V_58 ) {
unsigned long V_13 ;
int V_19 ;
F_80 ( V_21 . V_25 != 1 ) ;
F_81 ( V_13 ) ;
F_27 () ;
V_19 = (* V_16)( V_27 ) ;
F_29 ( V_13 ) ;
return V_19 ;
}
F_17 ( & V_21 , V_36 ) ;
return F_48 ( V_33 , F_20 , & V_21 ) ;
}
int F_82 ( T_1 V_16 , void * V_27 , const struct V_50 * V_59 )
{
int V_19 ;
F_83 () ;
V_19 = F_77 ( V_16 , V_27 , V_59 ) ;
F_84 () ;
return V_19 ;
}
int F_85 ( T_1 V_16 , void * V_27 ,
const struct V_50 * V_59 )
{
struct V_20 V_21 = { . V_16 = V_16 , . V_27 = V_27 ,
. V_32 = V_59 } ;
struct V_1 V_2 ;
int V_19 ;
F_74 ( F_86 ( F_76 () ) ) ;
V_21 . V_25 = F_87 () + 1 ;
while ( ! F_52 ( & V_53 ) )
F_37 () ;
F_17 ( & V_21 , V_36 ) ;
F_1 ( & V_2 , F_87 () ) ;
F_42 ( V_60 , F_20 , & V_21 ,
& V_2 ) ;
V_19 = F_20 ( & V_21 ) ;
while ( ! F_88 ( & V_2 . V_4 ) )
F_37 () ;
F_50 ( & V_53 ) ;
return V_19 ? : V_2 . V_19 ;
}
