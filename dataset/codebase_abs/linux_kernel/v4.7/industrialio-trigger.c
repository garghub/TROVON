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
if ( V_9 -> V_11 < 0 )
return V_9 -> V_11 ;
F_5 ( & V_9 -> V_2 , L_2 ,
( unsigned long ) V_9 -> V_11 ) ;
V_10 = F_6 ( & V_9 -> V_2 ) ;
if ( V_10 )
goto V_14;
F_7 ( & V_15 ) ;
F_8 ( & V_9 -> V_16 , & V_17 ) ;
F_9 ( & V_15 ) ;
return 0 ;
V_14:
F_10 ( & V_12 , V_9 -> V_11 ) ;
return V_10 ;
}
void F_11 ( struct V_6 * V_9 )
{
F_7 ( & V_15 ) ;
F_12 ( & V_9 -> V_16 ) ;
F_9 ( & V_15 ) ;
F_10 ( & V_12 , V_9 -> V_11 ) ;
F_13 ( & V_9 -> V_2 ) ;
}
static struct V_6 * F_14 ( const char * V_8 ,
T_2 V_18 )
{
struct V_6 * V_7 = NULL , * V_19 ;
F_7 ( & V_15 ) ;
F_15 (iter, &iio_trigger_list, list)
if ( F_16 ( V_19 -> V_8 , V_8 ) ) {
V_7 = V_19 ;
break;
}
F_9 ( & V_15 ) ;
return V_7 ;
}
void F_17 ( struct V_6 * V_7 )
{
int V_20 ;
if ( ! F_18 ( & V_7 -> V_21 ) ) {
F_19 ( & V_7 -> V_21 , V_22 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( V_7 -> V_23 [ V_20 ] . V_24 )
F_20 ( V_7 -> V_25 + V_20 ) ;
else
F_21 ( V_7 ) ;
}
}
}
T_3 F_22 ( int V_26 , void * V_27 )
{
F_17 ( V_27 ) ;
return V_28 ;
}
void F_23 ( struct V_6 * V_7 )
{
int V_20 ;
if ( ! F_18 ( & V_7 -> V_21 ) ) {
F_19 ( & V_7 -> V_21 , V_22 ) ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
if ( V_7 -> V_23 [ V_20 ] . V_24 )
F_24 ( V_7 -> V_25 + V_20 ) ;
else
F_21 ( V_7 ) ;
}
}
}
void F_21 ( struct V_6 * V_7 )
{
if ( F_25 ( & V_7 -> V_21 ) && V_7 -> V_29 &&
V_7 -> V_29 -> V_30 )
if ( V_7 -> V_29 -> V_30 ( V_7 ) )
F_17 ( V_7 ) ;
}
static int F_26 ( struct V_6 * V_7 )
{
int V_10 ;
F_7 ( & V_7 -> V_31 ) ;
V_10 = F_27 ( V_7 -> V_32 ,
V_22 ,
F_28 ( 1 ) ) ;
F_9 ( & V_7 -> V_31 ) ;
if ( V_10 >= 0 )
V_10 += V_7 -> V_25 ;
return V_10 ;
}
static void F_29 ( struct V_6 * V_7 , int V_26 )
{
F_7 ( & V_7 -> V_31 ) ;
F_30 ( V_26 - V_7 -> V_25 , V_7 -> V_32 ) ;
F_9 ( & V_7 -> V_31 ) ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_33 * V_34 )
{
int V_10 = 0 ;
bool V_35
= F_32 ( V_7 -> V_32 , V_22 ) ;
F_33 ( V_34 -> V_36 -> V_37 -> V_38 ) ;
V_34 -> V_26 = F_26 ( V_7 ) ;
if ( V_34 -> V_26 < 0 )
goto V_39;
V_10 = F_34 ( V_34 -> V_26 , V_34 -> V_40 , V_34 -> V_41 ,
V_34 -> type , V_34 -> V_8 ,
V_34 ) ;
if ( V_10 < 0 )
goto V_42;
if ( V_7 -> V_29 && V_7 -> V_29 -> V_43 && V_35 ) {
V_10 = V_7 -> V_29 -> V_43 ( V_7 , true ) ;
if ( V_10 < 0 )
goto V_44;
}
return V_10 ;
V_44:
F_35 ( V_34 -> V_26 , V_34 ) ;
V_42:
F_29 ( V_7 , V_34 -> V_26 ) ;
V_39:
F_36 ( V_34 -> V_36 -> V_37 -> V_38 ) ;
return V_10 ;
}
static int F_37 ( struct V_6 * V_7 ,
struct V_33 * V_34 )
{
int V_10 = 0 ;
bool V_45
= ( F_38 ( V_7 -> V_32 ,
V_22 )
== 1 ) ;
if ( V_7 -> V_29 && V_7 -> V_29 -> V_43 && V_45 ) {
V_10 = V_7 -> V_29 -> V_43 ( V_7 , false ) ;
if ( V_10 )
return V_10 ;
}
F_29 ( V_7 , V_34 -> V_26 ) ;
F_35 ( V_34 -> V_26 , V_34 ) ;
F_36 ( V_34 -> V_36 -> V_37 -> V_38 ) ;
return V_10 ;
}
T_3 F_39 ( int V_26 , void * V_46 )
{
struct V_33 * V_34 = V_46 ;
V_34 -> V_47 = F_40 () ;
return V_48 ;
}
struct V_33
* F_41 ( T_3 (* V_40)( int V_26 , void * V_46 ) ,
T_3 (* V_41)( int V_26 , void * V_46 ) ,
int type ,
struct V_49 * V_36 ,
const char * V_50 ,
... )
{
T_4 V_51 ;
struct V_33 * V_34 ;
V_34 = F_42 ( sizeof *V_34 , V_13 ) ;
if ( V_34 == NULL )
return NULL ;
va_start ( V_51 , V_50 ) ;
V_34 -> V_8 = F_43 ( V_13 , V_50 , V_51 ) ;
va_end ( V_51 ) ;
if ( V_34 -> V_8 == NULL ) {
F_44 ( V_34 ) ;
return NULL ;
}
V_34 -> V_40 = V_40 ;
V_34 -> V_41 = V_41 ;
V_34 -> type = type ;
V_34 -> V_36 = V_36 ;
return V_34 ;
}
void F_45 ( struct V_33 * V_34 )
{
F_44 ( V_34 -> V_8 ) ;
F_44 ( V_34 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_49 * V_36 = F_47 ( V_2 ) ;
if ( V_36 -> V_7 )
return sprintf ( V_5 , L_1 , V_36 -> V_7 -> V_8 ) ;
return 0 ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_18 )
{
struct V_49 * V_36 = F_47 ( V_2 ) ;
struct V_6 * V_52 = V_36 -> V_7 ;
struct V_6 * V_7 ;
int V_10 ;
F_7 ( & V_36 -> V_53 ) ;
if ( V_36 -> V_54 == V_55 ) {
F_9 ( & V_36 -> V_53 ) ;
return - V_56 ;
}
F_9 ( & V_36 -> V_53 ) ;
V_7 = F_14 ( V_5 , V_18 ) ;
if ( V_52 == V_7 )
return V_18 ;
if ( V_7 && V_36 -> V_37 -> V_57 ) {
V_10 = V_36 -> V_37 -> V_57 ( V_36 , V_7 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_7 && V_7 -> V_29 && V_7 -> V_29 -> V_58 ) {
V_10 = V_7 -> V_29 -> V_58 ( V_7 , V_36 ) ;
if ( V_10 )
return V_10 ;
}
V_36 -> V_7 = V_7 ;
if ( V_52 ) {
if ( V_36 -> V_59 & V_60 )
F_37 ( V_52 ,
V_36 -> V_61 ) ;
F_49 ( V_52 ) ;
}
if ( V_36 -> V_7 ) {
F_50 ( V_36 -> V_7 ) ;
if ( V_36 -> V_59 & V_60 )
F_31 ( V_36 -> V_7 ,
V_36 -> V_61 ) ;
}
return V_18 ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_2 ( V_1 ) ;
int V_20 ;
if ( V_7 -> V_25 ) {
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
F_52 ( V_7 -> V_25 + V_20 ,
V_62 ,
V_63 | V_64 ) ;
F_53 ( V_7 -> V_25 + V_20 ,
NULL ) ;
F_54 ( V_7 -> V_25 + V_20 ,
NULL ) ;
}
F_55 ( V_7 -> V_25 ,
V_22 ) ;
}
F_44 ( V_7 -> V_8 ) ;
F_44 ( V_7 ) ;
}
static void F_56 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = F_57 ( V_66 ) ;
struct V_6 * V_7
= F_58 ( V_68 ,
struct V_6 , V_69 ) ;
V_7 -> V_23 [ V_66 -> V_26 - V_7 -> V_25 ] . V_24 = false ;
}
static void F_59 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = F_57 ( V_66 ) ;
struct V_6 * V_7
= F_58 ( V_68 ,
struct V_6 , V_69 ) ;
V_7 -> V_23 [ V_66 -> V_26 - V_7 -> V_25 ] . V_24 = true ;
}
static struct V_6 * F_60 ( const char * V_50 , T_4 V_51 )
{
struct V_6 * V_7 ;
V_7 = F_61 ( sizeof *V_7 , V_13 ) ;
if ( V_7 ) {
int V_20 ;
V_7 -> V_2 . type = & V_70 ;
V_7 -> V_2 . V_71 = & V_72 ;
F_62 ( & V_7 -> V_2 ) ;
F_63 ( & V_7 -> V_31 ) ;
V_7 -> V_25
= F_64 ( - 1 , 0 ,
V_22 ,
0 ) ;
if ( V_7 -> V_25 < 0 ) {
F_44 ( V_7 ) ;
return NULL ;
}
V_7 -> V_8 = F_43 ( V_13 , V_50 , V_51 ) ;
if ( V_7 -> V_8 == NULL ) {
F_55 ( V_7 -> V_25 ,
V_22 ) ;
F_44 ( V_7 ) ;
return NULL ;
}
V_7 -> V_69 . V_8 = V_7 -> V_8 ;
V_7 -> V_69 . V_73 = & F_56 ;
V_7 -> V_69 . V_74 = & F_59 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
F_53 ( V_7 -> V_25 + V_20 ,
& V_7 -> V_69 ) ;
F_54 ( V_7 -> V_25 + V_20 ,
& V_75 ) ;
F_52 ( V_7 -> V_25 + V_20 ,
V_63 | V_62 ,
V_64 ) ;
}
F_65 ( & V_7 -> V_2 ) ;
}
return V_7 ;
}
struct V_6 * F_66 ( const char * V_50 , ... )
{
struct V_6 * V_7 ;
T_4 V_51 ;
va_start ( V_51 , V_50 ) ;
V_7 = F_60 ( V_50 , V_51 ) ;
va_end ( V_51 ) ;
return V_7 ;
}
void F_67 ( struct V_6 * V_7 )
{
if ( V_7 )
F_68 ( & V_7 -> V_2 ) ;
}
static void F_69 ( struct V_1 * V_2 , void * V_76 )
{
F_67 ( * (struct V_6 * * ) V_76 ) ;
}
static int F_70 ( struct V_1 * V_2 , void * V_76 , void * V_77 )
{
struct V_6 * * V_78 = V_76 ;
if ( ! V_78 || ! * V_78 ) {
F_71 ( ! V_78 || ! * V_78 ) ;
return 0 ;
}
return * V_78 == V_77 ;
}
struct V_6 * F_72 ( struct V_1 * V_2 ,
const char * V_50 , ... )
{
struct V_6 * * V_79 , * V_7 ;
T_4 V_51 ;
V_79 = F_73 ( F_69 , sizeof( * V_79 ) ,
V_13 ) ;
if ( ! V_79 )
return NULL ;
va_start ( V_51 , V_50 ) ;
V_7 = F_60 ( V_50 , V_51 ) ;
va_end ( V_51 ) ;
if ( V_7 ) {
* V_79 = V_7 ;
F_74 ( V_2 , V_79 ) ;
} else {
F_75 ( V_79 ) ;
}
return V_7 ;
}
void F_76 ( struct V_1 * V_2 , struct V_6 * V_80 )
{
int V_81 ;
V_81 = F_77 ( V_2 , F_69 ,
F_70 , V_80 ) ;
F_71 ( V_81 ) ;
}
void F_78 ( struct V_49 * V_36 )
{
V_36 -> V_82 [ V_36 -> V_83 ++ ] =
& V_84 ;
}
void F_79 ( struct V_49 * V_36 )
{
if ( V_36 -> V_7 )
F_49 ( V_36 -> V_7 ) ;
}
int F_80 ( struct V_49 * V_36 )
{
return F_31 ( V_36 -> V_7 ,
V_36 -> V_85 ) ;
}
int F_81 ( struct V_49 * V_36 )
{
return F_37 ( V_36 -> V_7 ,
V_36 -> V_85 ) ;
}
