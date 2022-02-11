static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
int F_3 ( struct V_6 * V_9 )
{
int V_10 ;
V_9 -> V_11 = F_4 ( & V_12 , 0 , 0 , V_13 ) ;
if ( V_9 -> V_11 < 0 ) {
V_10 = V_9 -> V_11 ;
goto V_14;
}
F_5 ( & V_9 -> V_2 , L_2 ,
( unsigned long ) V_9 -> V_11 ) ;
V_10 = F_6 ( & V_9 -> V_2 ) ;
if ( V_10 )
goto V_15;
F_7 ( & V_16 ) ;
F_8 ( & V_9 -> V_17 , & V_18 ) ;
F_9 ( & V_16 ) ;
return 0 ;
V_15:
F_10 ( & V_12 , V_9 -> V_11 ) ;
V_14:
return V_10 ;
}
void F_11 ( struct V_6 * V_9 )
{
F_7 ( & V_16 ) ;
F_12 ( & V_9 -> V_17 ) ;
F_9 ( & V_16 ) ;
F_10 ( & V_12 , V_9 -> V_11 ) ;
F_13 ( & V_9 -> V_2 ) ;
}
static struct V_6 * F_14 ( const char * V_8 ,
T_2 V_19 )
{
struct V_6 * V_7 = NULL , * V_20 ;
F_7 ( & V_16 ) ;
F_15 (iter, &iio_trigger_list, list)
if ( F_16 ( V_20 -> V_8 , V_8 ) ) {
V_7 = V_20 ;
break;
}
F_9 ( & V_16 ) ;
return V_7 ;
}
void F_17 ( struct V_6 * V_7 , T_3 time )
{
int V_21 ;
if ( ! F_18 ( & V_7 -> V_22 ) ) {
F_19 ( & V_7 -> V_22 , V_23 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
if ( V_7 -> V_24 [ V_21 ] . V_25 )
F_20 ( V_7 -> V_26 + V_21 ) ;
else
F_21 ( V_7 ) ;
}
}
}
T_4 F_22 ( int V_27 , void * V_28 )
{
F_17 ( V_28 , F_23 () ) ;
return V_29 ;
}
void F_24 ( struct V_6 * V_7 , T_3 time )
{
int V_21 ;
if ( ! F_18 ( & V_7 -> V_22 ) ) {
F_19 ( & V_7 -> V_22 , V_23 ) ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
if ( V_7 -> V_24 [ V_21 ] . V_25 )
F_25 ( V_7 -> V_26 + V_21 ) ;
else
F_21 ( V_7 ) ;
}
}
}
void F_21 ( struct V_6 * V_7 )
{
if ( F_26 ( & V_7 -> V_22 ) && V_7 -> V_30 &&
V_7 -> V_30 -> V_31 )
if ( V_7 -> V_30 -> V_31 ( V_7 ) )
F_17 ( V_7 , 0 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
int V_10 ;
F_7 ( & V_7 -> V_32 ) ;
V_10 = F_28 ( V_7 -> V_33 ,
V_23 ,
F_29 ( 1 ) ) ;
F_9 ( & V_7 -> V_32 ) ;
if ( V_10 >= 0 )
V_10 += V_7 -> V_26 ;
return V_10 ;
}
static void F_30 ( struct V_6 * V_7 , int V_27 )
{
F_7 ( & V_7 -> V_32 ) ;
F_31 ( V_27 - V_7 -> V_26 , V_7 -> V_33 ) ;
F_9 ( & V_7 -> V_32 ) ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_34 * V_35 )
{
int V_10 = 0 ;
bool V_36
= F_33 ( V_7 -> V_33 , V_23 ) ;
F_34 ( V_35 -> V_37 -> V_38 -> V_39 ) ;
V_35 -> V_27 = F_27 ( V_7 ) ;
V_10 = F_35 ( V_35 -> V_27 , V_35 -> V_40 , V_35 -> V_41 ,
V_35 -> type , V_35 -> V_8 ,
V_35 ) ;
if ( V_10 < 0 ) {
F_36 ( V_35 -> V_37 -> V_38 -> V_39 ) ;
return V_10 ;
}
if ( V_7 -> V_30 && V_7 -> V_30 -> V_42 && V_36 ) {
V_10 = V_7 -> V_30 -> V_42 ( V_7 , true ) ;
if ( V_10 < 0 )
F_36 ( V_35 -> V_37 -> V_38 -> V_39 ) ;
}
return V_10 ;
}
static int F_37 ( struct V_6 * V_7 ,
struct V_34 * V_35 )
{
int V_10 = 0 ;
bool V_43
= ( F_38 ( V_7 -> V_33 ,
V_23 )
== 1 ) ;
if ( V_7 -> V_30 && V_7 -> V_30 -> V_42 && V_43 ) {
V_10 = V_7 -> V_30 -> V_42 ( V_7 , false ) ;
if ( V_10 )
goto V_14;
}
F_30 ( V_7 , V_35 -> V_27 ) ;
F_39 ( V_35 -> V_27 , V_35 ) ;
F_36 ( V_35 -> V_37 -> V_38 -> V_39 ) ;
V_14:
return V_10 ;
}
T_4 F_40 ( int V_27 , void * V_44 )
{
struct V_34 * V_35 = V_44 ;
V_35 -> V_45 = F_23 () ;
return V_46 ;
}
struct V_34
* F_41 ( T_4 (* V_40)( int V_27 , void * V_44 ) ,
T_4 (* V_41)( int V_27 , void * V_44 ) ,
int type ,
struct V_47 * V_37 ,
const char * V_48 ,
... )
{
T_5 V_49 ;
struct V_34 * V_35 ;
V_35 = F_42 ( sizeof *V_35 , V_13 ) ;
if ( V_35 == NULL )
return NULL ;
va_start ( V_49 , V_48 ) ;
V_35 -> V_8 = F_43 ( V_13 , V_48 , V_49 ) ;
va_end ( V_49 ) ;
if ( V_35 -> V_8 == NULL ) {
F_44 ( V_35 ) ;
return NULL ;
}
V_35 -> V_40 = V_40 ;
V_35 -> V_41 = V_41 ;
V_35 -> type = type ;
V_35 -> V_37 = V_37 ;
return V_35 ;
}
void F_45 ( struct V_34 * V_35 )
{
F_44 ( V_35 -> V_8 ) ;
F_44 ( V_35 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_47 * V_37 = F_47 ( V_2 ) ;
if ( V_37 -> V_7 )
return sprintf ( V_5 , L_1 , V_37 -> V_7 -> V_8 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_19 )
{
struct V_47 * V_37 = F_47 ( V_2 ) ;
struct V_6 * V_50 = V_37 -> V_7 ;
struct V_6 * V_7 ;
int V_10 ;
F_7 ( & V_37 -> V_51 ) ;
if ( V_37 -> V_52 == V_53 ) {
F_9 ( & V_37 -> V_51 ) ;
return - V_54 ;
}
F_9 ( & V_37 -> V_51 ) ;
V_7 = F_14 ( V_5 , V_19 ) ;
if ( V_50 == V_7 )
return V_19 ;
if ( V_7 && V_37 -> V_38 -> V_55 ) {
V_10 = V_37 -> V_38 -> V_55 ( V_37 , V_7 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_7 && V_7 -> V_30 && V_7 -> V_30 -> V_56 ) {
V_10 = V_7 -> V_30 -> V_56 ( V_7 , V_37 ) ;
if ( V_10 )
return V_10 ;
}
V_37 -> V_7 = V_7 ;
if ( V_50 && V_37 -> V_7 != V_50 )
F_49 ( V_50 ) ;
if ( V_37 -> V_7 )
F_50 ( V_37 -> V_7 ) ;
return V_19 ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_2 ( V_1 ) ;
int V_21 ;
if ( V_7 -> V_26 ) {
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
F_52 ( V_7 -> V_26 + V_21 ,
V_57 ,
V_58 | V_59 ) ;
F_53 ( V_7 -> V_26 + V_21 ,
NULL ) ;
F_54 ( V_7 -> V_26 + V_21 ,
NULL ) ;
}
F_55 ( V_7 -> V_26 ,
V_23 ) ;
}
F_44 ( V_7 -> V_8 ) ;
F_44 ( V_7 ) ;
}
static void F_56 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_57 ( V_61 ) ;
struct V_6 * V_7
= F_58 ( V_63 ,
struct V_6 , V_64 ) ;
V_7 -> V_24 [ V_61 -> V_27 - V_7 -> V_26 ] . V_25 = false ;
}
static void F_59 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_57 ( V_61 ) ;
struct V_6 * V_7
= F_58 ( V_63 ,
struct V_6 , V_64 ) ;
V_7 -> V_24 [ V_61 -> V_27 - V_7 -> V_26 ] . V_25 = true ;
}
struct V_6 * F_60 ( const char * V_48 , ... )
{
T_5 V_49 ;
struct V_6 * V_7 ;
V_7 = F_61 ( sizeof *V_7 , V_13 ) ;
if ( V_7 ) {
int V_21 ;
V_7 -> V_2 . type = & V_65 ;
V_7 -> V_2 . V_66 = & V_67 ;
F_62 ( & V_7 -> V_2 ) ;
F_63 ( & V_7 -> V_32 ) ;
V_7 -> V_26
= F_64 ( - 1 , 0 ,
V_23 ,
0 ) ;
if ( V_7 -> V_26 < 0 ) {
F_44 ( V_7 ) ;
return NULL ;
}
va_start ( V_49 , V_48 ) ;
V_7 -> V_8 = F_43 ( V_13 , V_48 , V_49 ) ;
va_end ( V_49 ) ;
if ( V_7 -> V_8 == NULL ) {
F_55 ( V_7 -> V_26 ,
V_23 ) ;
F_44 ( V_7 ) ;
return NULL ;
}
V_7 -> V_64 . V_8 = V_7 -> V_8 ;
V_7 -> V_64 . V_68 = & F_56 ;
V_7 -> V_64 . V_69 = & F_59 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
F_53 ( V_7 -> V_26 + V_21 ,
& V_7 -> V_64 ) ;
F_54 ( V_7 -> V_26 + V_21 ,
& V_70 ) ;
F_52 ( V_7 -> V_26 + V_21 ,
V_58 | V_57 ,
V_59 ) ;
}
F_65 ( & V_7 -> V_2 ) ;
}
return V_7 ;
}
void F_66 ( struct V_6 * V_7 )
{
if ( V_7 )
F_67 ( & V_7 -> V_2 ) ;
}
void F_68 ( struct V_47 * V_37 )
{
V_37 -> V_71 [ V_37 -> V_72 ++ ] =
& V_73 ;
}
void F_69 ( struct V_47 * V_37 )
{
if ( V_37 -> V_7 )
F_49 ( V_37 -> V_7 ) ;
}
int F_70 ( struct V_47 * V_37 )
{
return F_32 ( V_37 -> V_7 ,
V_37 -> V_74 ) ;
}
int F_71 ( struct V_47 * V_37 )
{
return F_37 ( V_37 -> V_7 ,
V_37 -> V_74 ) ;
}
