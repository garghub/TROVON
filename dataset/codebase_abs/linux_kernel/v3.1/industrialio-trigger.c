static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static int F_3 ( struct V_6 * V_9 )
{
return F_4 ( & V_9 -> V_2 . V_10 ,
& V_11 . V_4 ,
NULL ) ;
}
static void F_5 ( struct V_6 * V_9 )
{
F_6 ( & V_9 -> V_2 . V_10 ,
& V_11 . V_4 ,
NULL ) ;
}
static int F_7 ( struct V_6 * V_9 )
{
int V_12 = 0 ;
V_13:
if ( F_8 ( F_9 ( & V_14 , V_15 ) == 0 ) )
return - V_16 ;
F_10 ( & V_17 ) ;
V_12 = F_11 ( & V_14 , NULL , & V_9 -> V_18 ) ;
F_12 ( & V_17 ) ;
if ( F_8 ( V_12 == - V_19 ) )
goto V_13;
else if ( F_13 ( ! V_12 ) )
V_9 -> V_18 = V_9 -> V_18 & V_20 ;
return V_12 ;
}
static void F_14 ( struct V_6 * V_9 )
{
F_10 ( & V_17 ) ;
F_15 ( & V_14 , V_9 -> V_18 ) ;
F_12 ( & V_17 ) ;
}
int F_16 ( struct V_6 * V_9 )
{
int V_12 ;
V_12 = F_7 ( V_9 ) ;
if ( V_12 )
goto V_21;
F_17 ( & V_9 -> V_2 , L_2 ,
( unsigned long ) V_9 -> V_18 ) ;
V_12 = F_18 ( & V_9 -> V_2 ) ;
if ( V_12 )
goto V_22;
V_12 = F_3 ( V_9 ) ;
if ( V_12 )
goto V_23;
F_19 ( & V_24 ) ;
F_20 ( & V_9 -> V_25 , & V_26 ) ;
F_21 ( & V_24 ) ;
return 0 ;
V_23:
F_22 ( & V_9 -> V_2 ) ;
V_22:
F_14 ( V_9 ) ;
V_21:
return V_12 ;
}
void F_23 ( struct V_6 * V_9 )
{
F_19 ( & V_24 ) ;
F_24 ( & V_9 -> V_25 ) ;
F_21 ( & V_24 ) ;
F_5 ( V_9 ) ;
F_14 ( V_9 ) ;
F_25 ( & V_9 -> V_2 ) ;
}
static struct V_6 * F_26 ( const char * V_8 ,
T_2 V_27 )
{
struct V_6 * V_7 = NULL , * V_28 ;
F_19 ( & V_24 ) ;
F_27 (iter, &iio_trigger_list, list)
if ( F_28 ( V_28 -> V_8 , V_8 ) ) {
V_7 = V_28 ;
break;
}
F_21 ( & V_24 ) ;
return V_7 ;
}
void F_29 ( struct V_6 * V_7 , T_3 time )
{
int V_29 ;
if ( ! V_7 -> V_30 ) {
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ )
if ( V_7 -> V_32 [ V_29 ] . V_33 ) {
V_7 -> V_30 ++ ;
F_30 ( V_7 -> V_34 + V_29 ) ;
}
}
}
T_4 F_31 ( int V_35 , void * V_36 )
{
F_29 ( V_36 , F_32 () ) ;
return V_37 ;
}
void F_33 ( struct V_6 * V_7 , T_3 time )
{
int V_29 ;
if ( ! V_7 -> V_30 ) {
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ )
if ( V_7 -> V_32 [ V_29 ] . V_33 ) {
V_7 -> V_30 ++ ;
F_34 ( V_7 -> V_34 + V_29 ) ;
}
}
}
void F_35 ( struct V_6 * V_7 )
{
V_7 -> V_30 -- ;
if ( V_7 -> V_30 == 0 && V_7 -> V_38 )
if ( V_7 -> V_38 ( V_7 ) ) {
F_29 ( V_7 , 0 ) ;
}
}
int F_36 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
int V_12 = 0 ;
bool V_41
= F_37 ( V_7 -> V_42 , V_31 ) ;
V_40 -> V_35 = F_38 ( V_7 ) ;
V_12 = F_39 ( V_40 -> V_35 , V_40 -> V_43 , V_40 -> V_44 ,
V_40 -> type , V_40 -> V_8 ,
V_40 ) ;
if ( V_7 -> V_45 && V_41 )
V_12 = V_7 -> V_45 ( V_7 , true ) ;
return V_12 ;
}
int F_40 ( struct V_6 * V_7 ,
struct V_39 * V_40 )
{
int V_12 = 0 ;
bool V_46
= ( F_41 ( V_7 -> V_42 ,
V_31 )
== 1 ) ;
if ( V_7 -> V_45 && V_46 ) {
V_12 = V_7 -> V_45 ( V_7 , false ) ;
if ( V_12 )
goto V_21;
}
F_42 ( V_7 , V_40 -> V_35 ) ;
F_43 ( V_40 -> V_35 , V_40 ) ;
V_21:
return V_12 ;
}
T_4 F_44 ( int V_35 , void * V_47 )
{
struct V_39 * V_40 = V_47 ;
V_40 -> V_48 = F_32 () ;
return V_49 ;
}
struct V_39
* F_45 ( T_4 (* V_43)( int V_35 , void * V_47 ) ,
T_4 (* V_44)( int V_35 , void * V_47 ) ,
int type ,
void * V_36 ,
const char * V_50 ,
... )
{
T_5 V_51 ;
struct V_39 * V_40 ;
V_40 = F_46 ( sizeof *V_40 , V_15 ) ;
if ( V_40 == NULL )
return NULL ;
va_start ( V_51 , V_50 ) ;
V_40 -> V_8 = F_47 ( V_15 , V_50 , V_51 ) ;
va_end ( V_51 ) ;
if ( V_40 -> V_8 == NULL ) {
F_48 ( V_40 ) ;
return NULL ;
}
V_40 -> V_43 = V_43 ;
V_40 -> V_44 = V_44 ;
V_40 -> type = type ;
V_40 -> V_52 = V_36 ;
return V_40 ;
}
void F_49 ( struct V_39 * V_40 )
{
F_48 ( V_40 -> V_8 ) ;
F_48 ( V_40 ) ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_53 * V_54 = F_2 ( V_2 ) ;
int V_27 = 0 ;
if ( V_54 -> V_7 )
V_27 = sprintf ( V_5 ,
L_1 ,
V_54 -> V_7 -> V_8 ) ;
return V_27 ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_27 )
{
struct V_53 * V_54 = F_2 ( V_2 ) ;
struct V_6 * V_55 = V_54 -> V_7 ;
struct V_6 * V_7 ;
int V_12 ;
F_19 ( & V_54 -> V_56 ) ;
if ( V_54 -> V_57 == V_58 ) {
F_21 ( & V_54 -> V_56 ) ;
return - V_59 ;
}
F_21 ( & V_54 -> V_56 ) ;
V_7 = F_26 ( V_5 , V_27 ) ;
if ( V_7 && V_54 -> V_60 -> V_61 ) {
V_12 = V_54 -> V_60 -> V_61 ( V_54 , V_7 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_7 && V_7 -> V_62 ) {
V_12 = V_7 -> V_62 ( V_7 , V_54 ) ;
if ( V_12 )
return V_12 ;
}
V_54 -> V_7 = V_7 ;
if ( V_55 && V_54 -> V_7 != V_55 )
F_52 ( V_55 ) ;
if ( V_54 -> V_7 )
F_53 ( V_54 -> V_7 ) ;
return V_27 ;
}
static void F_54 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_55 ( V_1 ) ;
int V_29 ;
if ( V_7 -> V_34 ) {
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_56 ( V_7 -> V_34 + V_29 ,
V_63 ,
V_64 | V_65 ) ;
F_57 ( V_7 -> V_34 + V_29 ,
NULL ) ;
F_58 ( V_7 -> V_34 + V_29 ,
NULL ) ;
}
F_59 ( V_7 -> V_34 ,
V_31 ) ;
}
F_48 ( V_7 -> V_8 ) ;
F_48 ( V_7 ) ;
F_60 () ;
}
static void F_61 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = F_62 ( V_67 ) ;
struct V_6 * V_7
= F_63 ( V_69 ,
struct V_6 , V_70 ) ;
V_7 -> V_32 [ V_67 -> V_35 - V_7 -> V_34 ] . V_33 = false ;
}
static void F_64 ( struct V_66 * V_67 )
{
struct V_68 * V_69 = F_62 ( V_67 ) ;
struct V_6 * V_7
= F_63 ( V_69 ,
struct V_6 , V_70 ) ;
V_7 -> V_32 [ V_67 -> V_35 - V_7 -> V_34 ] . V_33 = true ;
}
struct V_6 * F_65 ( const char * V_50 , ... )
{
T_5 V_51 ;
struct V_6 * V_7 ;
V_7 = F_66 ( sizeof *V_7 , V_15 ) ;
if ( V_7 ) {
int V_29 ;
V_7 -> V_2 . type = & V_71 ;
V_7 -> V_2 . V_72 = & V_73 ;
F_67 ( & V_7 -> V_2 ) ;
F_68 ( & V_7 -> V_2 , ( void * ) V_7 ) ;
F_69 ( & V_7 -> V_74 ) ;
V_7 -> V_34
= F_70 ( - 1 , 0 ,
V_31 ,
0 ) ;
if ( V_7 -> V_34 < 0 ) {
F_48 ( V_7 ) ;
return NULL ;
}
va_start ( V_51 , V_50 ) ;
V_7 -> V_8 = F_47 ( V_15 , V_50 , V_51 ) ;
va_end ( V_51 ) ;
if ( V_7 -> V_8 == NULL ) {
F_59 ( V_7 -> V_34 ,
V_31 ) ;
F_48 ( V_7 ) ;
return NULL ;
}
V_7 -> V_70 . V_8 = V_7 -> V_8 ;
V_7 -> V_70 . V_75 = & F_61 ;
V_7 -> V_70 . V_76 = & F_64 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_57 ( V_7 -> V_34 + V_29 ,
& V_7 -> V_70 ) ;
F_58 ( V_7 -> V_34 + V_29 ,
& V_77 ) ;
F_56 ( V_7 -> V_34 + V_29 ,
V_64 | V_63 ,
V_65 ) ;
}
F_71 () ;
}
return V_7 ;
}
void F_72 ( struct V_6 * V_7 )
{
if ( V_7 )
F_73 ( & V_7 -> V_2 ) ;
}
int F_74 ( struct V_53 * V_54 )
{
int V_12 ;
V_12 = F_75 ( & V_54 -> V_2 . V_10 ,
& V_78 ) ;
return V_12 ;
}
int F_76 ( struct V_53 * V_54 )
{
F_77 ( & V_54 -> V_2 . V_10 ,
& V_78 ) ;
return 0 ;
}
int F_78 ( struct V_53 * V_79 )
{
return V_79 -> V_7
? F_36 ( V_79 -> V_7 ,
V_79 -> V_80 )
: 0 ;
}
int F_79 ( struct V_53 * V_79 )
{
return V_79 -> V_7
? F_40 ( V_79 -> V_7 ,
V_79 -> V_80 )
: 0 ;
}
