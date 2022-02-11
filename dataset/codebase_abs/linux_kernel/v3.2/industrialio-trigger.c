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
int F_7 ( struct V_6 * V_9 )
{
int V_12 ;
V_9 -> V_13 = F_8 ( & V_14 , 0 , 0 , V_15 ) ;
if ( V_9 -> V_13 < 0 ) {
V_12 = V_9 -> V_13 ;
goto V_16;
}
F_9 ( & V_9 -> V_2 , L_2 ,
( unsigned long ) V_9 -> V_13 ) ;
V_12 = F_10 ( & V_9 -> V_2 ) ;
if ( V_12 )
goto V_17;
V_12 = F_3 ( V_9 ) ;
if ( V_12 )
goto V_18;
F_11 ( & V_19 ) ;
F_12 ( & V_9 -> V_20 , & V_21 ) ;
F_13 ( & V_19 ) ;
return 0 ;
V_18:
F_14 ( & V_9 -> V_2 ) ;
V_17:
F_15 ( & V_14 , V_9 -> V_13 ) ;
V_16:
return V_12 ;
}
void F_16 ( struct V_6 * V_9 )
{
F_11 ( & V_19 ) ;
F_17 ( & V_9 -> V_20 ) ;
F_13 ( & V_19 ) ;
F_5 ( V_9 ) ;
F_15 ( & V_14 , V_9 -> V_13 ) ;
F_18 ( & V_9 -> V_2 ) ;
}
static struct V_6 * F_19 ( const char * V_8 ,
T_2 V_22 )
{
struct V_6 * V_7 = NULL , * V_23 ;
F_11 ( & V_19 ) ;
F_20 (iter, &iio_trigger_list, list)
if ( F_21 ( V_23 -> V_8 , V_8 ) ) {
V_7 = V_23 ;
break;
}
F_13 ( & V_19 ) ;
return V_7 ;
}
void F_22 ( struct V_6 * V_7 , T_3 time )
{
int V_24 ;
if ( ! V_7 -> V_25 )
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
if ( V_7 -> V_27 [ V_24 ] . V_28 ) {
V_7 -> V_25 ++ ;
F_23 ( V_7 -> V_29 + V_24 ) ;
}
}
T_4 F_24 ( int V_30 , void * V_31 )
{
F_22 ( V_31 , F_25 () ) ;
return V_32 ;
}
void F_26 ( struct V_6 * V_7 , T_3 time )
{
int V_24 ;
if ( ! V_7 -> V_25 ) {
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
if ( V_7 -> V_27 [ V_24 ] . V_28 ) {
V_7 -> V_25 ++ ;
F_27 ( V_7 -> V_29 + V_24 ) ;
}
}
}
void F_28 ( struct V_6 * V_7 )
{
V_7 -> V_25 -- ;
if ( V_7 -> V_25 == 0 && V_7 -> V_33 && V_7 -> V_33 -> V_34 )
if ( V_7 -> V_33 -> V_34 ( V_7 ) ) {
F_22 ( V_7 , 0 ) ;
}
}
static int F_29 ( struct V_6 * V_7 )
{
int V_12 ;
F_11 ( & V_7 -> V_35 ) ;
V_12 = F_30 ( V_7 -> V_36 ,
V_26 ,
F_31 ( 1 ) ) ;
F_13 ( & V_7 -> V_35 ) ;
if ( V_12 >= 0 )
V_12 += V_7 -> V_29 ;
return V_12 ;
}
static void F_32 ( struct V_6 * V_7 , int V_30 )
{
F_11 ( & V_7 -> V_35 ) ;
F_33 ( V_30 - V_7 -> V_29 , V_7 -> V_36 ) ;
F_13 ( & V_7 -> V_35 ) ;
}
static int F_34 ( struct V_6 * V_7 ,
struct V_37 * V_38 )
{
int V_12 = 0 ;
bool V_39
= F_35 ( V_7 -> V_36 , V_26 ) ;
F_36 ( V_38 -> V_40 -> V_41 -> V_42 ) ;
V_38 -> V_30 = F_29 ( V_7 ) ;
V_12 = F_37 ( V_38 -> V_30 , V_38 -> V_43 , V_38 -> V_44 ,
V_38 -> type , V_38 -> V_8 ,
V_38 ) ;
if ( V_7 -> V_33 && V_7 -> V_33 -> V_45 && V_39 )
V_12 = V_7 -> V_33 -> V_45 ( V_7 , true ) ;
return V_12 ;
}
static int F_38 ( struct V_6 * V_7 ,
struct V_37 * V_38 )
{
int V_12 = 0 ;
bool V_46
= ( F_39 ( V_7 -> V_36 ,
V_26 )
== 1 ) ;
if ( V_7 -> V_33 && V_7 -> V_33 -> V_45 && V_46 ) {
V_12 = V_7 -> V_33 -> V_45 ( V_7 , false ) ;
if ( V_12 )
goto V_16;
}
F_32 ( V_7 , V_38 -> V_30 ) ;
F_40 ( V_38 -> V_30 , V_38 ) ;
F_41 ( V_38 -> V_40 -> V_41 -> V_42 ) ;
V_16:
return V_12 ;
}
T_4 F_42 ( int V_30 , void * V_47 )
{
struct V_37 * V_38 = V_47 ;
V_38 -> V_48 = F_25 () ;
return V_49 ;
}
struct V_37
* F_43 ( T_4 (* V_43)( int V_30 , void * V_47 ) ,
T_4 (* V_44)( int V_30 , void * V_47 ) ,
int type ,
struct V_50 * V_40 ,
const char * V_51 ,
... )
{
T_5 V_52 ;
struct V_37 * V_38 ;
V_38 = F_44 ( sizeof *V_38 , V_15 ) ;
if ( V_38 == NULL )
return NULL ;
va_start ( V_52 , V_51 ) ;
V_38 -> V_8 = F_45 ( V_15 , V_51 , V_52 ) ;
va_end ( V_52 ) ;
if ( V_38 -> V_8 == NULL ) {
F_46 ( V_38 ) ;
return NULL ;
}
V_38 -> V_43 = V_43 ;
V_38 -> V_44 = V_44 ;
V_38 -> type = type ;
V_38 -> V_40 = V_40 ;
return V_38 ;
}
void F_47 ( struct V_37 * V_38 )
{
F_46 ( V_38 -> V_8 ) ;
F_46 ( V_38 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_50 * V_40 = F_2 ( V_2 ) ;
if ( V_40 -> V_7 )
return sprintf ( V_5 , L_1 , V_40 -> V_7 -> V_8 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_22 )
{
struct V_50 * V_40 = F_2 ( V_2 ) ;
struct V_6 * V_53 = V_40 -> V_7 ;
struct V_6 * V_7 ;
int V_12 ;
F_11 ( & V_40 -> V_54 ) ;
if ( V_40 -> V_55 == V_56 ) {
F_13 ( & V_40 -> V_54 ) ;
return - V_57 ;
}
F_13 ( & V_40 -> V_54 ) ;
V_7 = F_19 ( V_5 , V_22 ) ;
if ( V_7 && V_40 -> V_41 -> V_58 ) {
V_12 = V_40 -> V_41 -> V_58 ( V_40 , V_7 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_7 && V_7 -> V_33 && V_7 -> V_33 -> V_59 ) {
V_12 = V_7 -> V_33 -> V_59 ( V_7 , V_40 ) ;
if ( V_12 )
return V_12 ;
}
V_40 -> V_7 = V_7 ;
if ( V_53 && V_40 -> V_7 != V_53 )
F_50 ( V_53 ) ;
if ( V_40 -> V_7 )
F_51 ( V_40 -> V_7 ) ;
return V_22 ;
}
static void F_52 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_53 ( V_1 ) ;
int V_24 ;
if ( V_7 -> V_29 ) {
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_54 ( V_7 -> V_29 + V_24 ,
V_60 ,
V_61 | V_62 ) ;
F_55 ( V_7 -> V_29 + V_24 ,
NULL ) ;
F_56 ( V_7 -> V_29 + V_24 ,
NULL ) ;
}
F_57 ( V_7 -> V_29 ,
V_26 ) ;
}
F_46 ( V_7 -> V_8 ) ;
F_46 ( V_7 ) ;
}
static void F_58 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_59 ( V_64 ) ;
struct V_6 * V_7
= F_60 ( V_66 ,
struct V_6 , V_67 ) ;
V_7 -> V_27 [ V_64 -> V_30 - V_7 -> V_29 ] . V_28 = false ;
}
static void F_61 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_59 ( V_64 ) ;
struct V_6 * V_7
= F_60 ( V_66 ,
struct V_6 , V_67 ) ;
V_7 -> V_27 [ V_64 -> V_30 - V_7 -> V_29 ] . V_28 = true ;
}
struct V_6 * F_62 ( const char * V_51 , ... )
{
T_5 V_52 ;
struct V_6 * V_7 ;
V_7 = F_63 ( sizeof *V_7 , V_15 ) ;
if ( V_7 ) {
int V_24 ;
V_7 -> V_2 . type = & V_68 ;
V_7 -> V_2 . V_69 = & V_70 ;
F_64 ( & V_7 -> V_2 ) ;
F_65 ( & V_7 -> V_2 , ( void * ) V_7 ) ;
F_66 ( & V_7 -> V_35 ) ;
V_7 -> V_29
= F_67 ( - 1 , 0 ,
V_26 ,
0 ) ;
if ( V_7 -> V_29 < 0 ) {
F_46 ( V_7 ) ;
return NULL ;
}
va_start ( V_52 , V_51 ) ;
V_7 -> V_8 = F_45 ( V_15 , V_51 , V_52 ) ;
va_end ( V_52 ) ;
if ( V_7 -> V_8 == NULL ) {
F_57 ( V_7 -> V_29 ,
V_26 ) ;
F_46 ( V_7 ) ;
return NULL ;
}
V_7 -> V_67 . V_8 = V_7 -> V_8 ;
V_7 -> V_67 . V_71 = & F_58 ;
V_7 -> V_67 . V_72 = & F_61 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_55 ( V_7 -> V_29 + V_24 ,
& V_7 -> V_67 ) ;
F_56 ( V_7 -> V_29 + V_24 ,
& V_73 ) ;
F_54 ( V_7 -> V_29 + V_24 ,
V_61 | V_60 ,
V_62 ) ;
}
F_68 ( & V_7 -> V_2 ) ;
}
return V_7 ;
}
void F_69 ( struct V_6 * V_7 )
{
if ( V_7 )
F_70 ( & V_7 -> V_2 ) ;
}
int F_71 ( struct V_50 * V_40 )
{
V_40 -> V_74 [ V_40 -> V_75 ++ ] =
& V_76 ;
return 0 ;
}
void F_72 ( struct V_50 * V_40 )
{
if ( V_40 -> V_7 )
F_50 ( V_40 -> V_7 ) ;
}
int F_73 ( struct V_50 * V_40 )
{
return V_40 -> V_7
? F_34 ( V_40 -> V_7 ,
V_40 -> V_77 )
: 0 ;
}
int F_74 ( struct V_50 * V_40 )
{
return V_40 -> V_7
? F_38 ( V_40 -> V_7 ,
V_40 -> V_77 )
: 0 ;
}
