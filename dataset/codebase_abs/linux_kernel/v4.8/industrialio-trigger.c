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
if ( ! V_9 -> V_11 )
return - V_12 ;
V_9 -> V_13 = F_4 ( & V_14 , 0 , 0 , V_15 ) ;
if ( V_9 -> V_13 < 0 )
return V_9 -> V_13 ;
F_5 ( & V_9 -> V_2 , L_2 ,
( unsigned long ) V_9 -> V_13 ) ;
V_10 = F_6 ( & V_9 -> V_2 ) ;
if ( V_10 )
goto V_16;
F_7 ( & V_17 ) ;
if ( F_8 ( V_9 -> V_8 ) ) {
F_9 ( L_3 , V_9 -> V_8 ) ;
V_10 = - V_18 ;
goto V_19;
}
F_10 ( & V_9 -> V_20 , & V_21 ) ;
F_11 ( & V_17 ) ;
return 0 ;
V_19:
F_11 ( & V_17 ) ;
F_12 ( & V_9 -> V_2 ) ;
V_16:
F_13 ( & V_14 , V_9 -> V_13 ) ;
return V_10 ;
}
void F_14 ( struct V_6 * V_9 )
{
F_7 ( & V_17 ) ;
F_15 ( & V_9 -> V_20 ) ;
F_11 ( & V_17 ) ;
F_13 ( & V_14 , V_9 -> V_13 ) ;
F_12 ( & V_9 -> V_2 ) ;
}
static struct V_6 * F_8 ( const char * V_8 )
{
struct V_6 * V_22 ;
F_16 (iter, &iio_trigger_list, list)
if ( ! strcmp ( V_22 -> V_8 , V_8 ) )
return V_22 ;
return NULL ;
}
static struct V_6 * F_17 ( const char * V_8 ,
T_2 V_23 )
{
struct V_6 * V_7 = NULL , * V_22 ;
F_7 ( & V_17 ) ;
F_16 (iter, &iio_trigger_list, list)
if ( F_18 ( V_22 -> V_8 , V_8 ) ) {
V_7 = V_22 ;
break;
}
F_11 ( & V_17 ) ;
return V_7 ;
}
void F_19 ( struct V_6 * V_7 )
{
int V_24 ;
if ( ! F_20 ( & V_7 -> V_25 ) ) {
F_21 ( & V_7 -> V_25 , V_26 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
if ( V_7 -> V_27 [ V_24 ] . V_28 )
F_22 ( V_7 -> V_29 + V_24 ) ;
else
F_23 ( V_7 ) ;
}
}
}
T_3 F_24 ( int V_30 , void * V_31 )
{
F_19 ( V_31 ) ;
return V_32 ;
}
void F_25 ( struct V_6 * V_7 )
{
int V_24 ;
if ( ! F_20 ( & V_7 -> V_25 ) ) {
F_21 ( & V_7 -> V_25 , V_26 ) ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
if ( V_7 -> V_27 [ V_24 ] . V_28 )
F_26 ( V_7 -> V_29 + V_24 ) ;
else
F_23 ( V_7 ) ;
}
}
}
void F_23 ( struct V_6 * V_7 )
{
if ( F_27 ( & V_7 -> V_25 ) && V_7 -> V_11 -> V_33 )
if ( V_7 -> V_11 -> V_33 ( V_7 ) )
F_19 ( V_7 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
int V_10 ;
F_7 ( & V_7 -> V_34 ) ;
V_10 = F_29 ( V_7 -> V_35 ,
V_26 ,
F_30 ( 1 ) ) ;
F_11 ( & V_7 -> V_34 ) ;
if ( V_10 >= 0 )
V_10 += V_7 -> V_29 ;
return V_10 ;
}
static void F_31 ( struct V_6 * V_7 , int V_30 )
{
F_7 ( & V_7 -> V_34 ) ;
F_32 ( V_30 - V_7 -> V_29 , V_7 -> V_35 ) ;
F_11 ( & V_7 -> V_34 ) ;
}
static int F_33 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
int V_10 = 0 ;
bool V_38
= F_34 ( V_7 -> V_35 , V_26 ) ;
F_35 ( V_37 -> V_39 -> V_40 -> V_41 ) ;
V_37 -> V_30 = F_28 ( V_7 ) ;
if ( V_37 -> V_30 < 0 )
goto V_42;
V_10 = F_36 ( V_37 -> V_30 , V_37 -> V_43 , V_37 -> V_44 ,
V_37 -> type , V_37 -> V_8 ,
V_37 ) ;
if ( V_10 < 0 )
goto V_45;
if ( V_7 -> V_11 -> V_46 && V_38 ) {
V_10 = V_7 -> V_11 -> V_46 ( V_7 , true ) ;
if ( V_10 < 0 )
goto V_47;
}
return V_10 ;
V_47:
F_37 ( V_37 -> V_30 , V_37 ) ;
V_45:
F_31 ( V_7 , V_37 -> V_30 ) ;
V_42:
F_38 ( V_37 -> V_39 -> V_40 -> V_41 ) ;
return V_10 ;
}
static int F_39 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
int V_10 = 0 ;
bool V_48
= ( F_40 ( V_7 -> V_35 ,
V_26 )
== 1 ) ;
if ( V_7 -> V_11 -> V_46 && V_48 ) {
V_10 = V_7 -> V_11 -> V_46 ( V_7 , false ) ;
if ( V_10 )
return V_10 ;
}
F_31 ( V_7 , V_37 -> V_30 ) ;
F_37 ( V_37 -> V_30 , V_37 ) ;
F_38 ( V_37 -> V_39 -> V_40 -> V_41 ) ;
return V_10 ;
}
T_3 F_41 ( int V_30 , void * V_49 )
{
struct V_36 * V_37 = V_49 ;
V_37 -> V_50 = F_42 ( V_37 -> V_39 ) ;
return V_51 ;
}
struct V_36
* F_43 ( T_3 (* V_43)( int V_30 , void * V_49 ) ,
T_3 (* V_44)( int V_30 , void * V_49 ) ,
int type ,
struct V_52 * V_39 ,
const char * V_53 ,
... )
{
T_4 V_54 ;
struct V_36 * V_37 ;
V_37 = F_44 ( sizeof *V_37 , V_15 ) ;
if ( V_37 == NULL )
return NULL ;
va_start ( V_54 , V_53 ) ;
V_37 -> V_8 = F_45 ( V_15 , V_53 , V_54 ) ;
va_end ( V_54 ) ;
if ( V_37 -> V_8 == NULL ) {
F_46 ( V_37 ) ;
return NULL ;
}
V_37 -> V_43 = V_43 ;
V_37 -> V_44 = V_44 ;
V_37 -> type = type ;
V_37 -> V_39 = V_39 ;
return V_37 ;
}
void F_47 ( struct V_36 * V_37 )
{
F_46 ( V_37 -> V_8 ) ;
F_46 ( V_37 ) ;
}
static T_1 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_52 * V_39 = F_49 ( V_2 ) ;
if ( V_39 -> V_7 )
return sprintf ( V_5 , L_1 , V_39 -> V_7 -> V_8 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_23 )
{
struct V_52 * V_39 = F_49 ( V_2 ) ;
struct V_6 * V_55 = V_39 -> V_7 ;
struct V_6 * V_7 ;
int V_10 ;
F_7 ( & V_39 -> V_56 ) ;
if ( V_39 -> V_57 == V_58 ) {
F_11 ( & V_39 -> V_56 ) ;
return - V_59 ;
}
F_11 ( & V_39 -> V_56 ) ;
V_7 = F_17 ( V_5 , V_23 ) ;
if ( V_55 == V_7 )
return V_23 ;
if ( V_7 && V_39 -> V_40 -> V_60 ) {
V_10 = V_39 -> V_40 -> V_60 ( V_39 , V_7 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_7 && V_7 -> V_11 -> V_61 ) {
V_10 = V_7 -> V_11 -> V_61 ( V_7 , V_39 ) ;
if ( V_10 )
return V_10 ;
}
V_39 -> V_7 = V_7 ;
if ( V_55 ) {
if ( V_39 -> V_62 & V_63 )
F_39 ( V_55 ,
V_39 -> V_64 ) ;
F_51 ( V_55 ) ;
}
if ( V_39 -> V_7 ) {
F_52 ( V_39 -> V_7 ) ;
if ( V_39 -> V_62 & V_63 )
F_33 ( V_39 -> V_7 ,
V_39 -> V_64 ) ;
}
return V_23 ;
}
static void F_53 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_2 ( V_1 ) ;
int V_24 ;
if ( V_7 -> V_29 ) {
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_54 ( V_7 -> V_29 + V_24 ,
V_65 ,
V_66 | V_67 ) ;
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
static void F_58 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_59 ( V_69 ) ;
struct V_6 * V_7
= F_60 ( V_71 ,
struct V_6 , V_72 ) ;
V_7 -> V_27 [ V_69 -> V_30 - V_7 -> V_29 ] . V_28 = false ;
}
static void F_61 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_59 ( V_69 ) ;
struct V_6 * V_7
= F_60 ( V_71 ,
struct V_6 , V_72 ) ;
V_7 -> V_27 [ V_69 -> V_30 - V_7 -> V_29 ] . V_28 = true ;
}
static struct V_6 * F_62 ( const char * V_53 , T_4 V_54 )
{
struct V_6 * V_7 ;
V_7 = F_63 ( sizeof *V_7 , V_15 ) ;
if ( V_7 ) {
int V_24 ;
V_7 -> V_2 . type = & V_73 ;
V_7 -> V_2 . V_74 = & V_75 ;
F_64 ( & V_7 -> V_2 ) ;
F_65 ( & V_7 -> V_34 ) ;
V_7 -> V_29
= F_66 ( - 1 , 0 ,
V_26 ,
0 ) ;
if ( V_7 -> V_29 < 0 ) {
F_46 ( V_7 ) ;
return NULL ;
}
V_7 -> V_8 = F_45 ( V_15 , V_53 , V_54 ) ;
if ( V_7 -> V_8 == NULL ) {
F_57 ( V_7 -> V_29 ,
V_26 ) ;
F_46 ( V_7 ) ;
return NULL ;
}
V_7 -> V_72 . V_8 = V_7 -> V_8 ;
V_7 -> V_72 . V_76 = & F_58 ;
V_7 -> V_72 . V_77 = & F_61 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
F_55 ( V_7 -> V_29 + V_24 ,
& V_7 -> V_72 ) ;
F_56 ( V_7 -> V_29 + V_24 ,
& V_78 ) ;
F_54 ( V_7 -> V_29 + V_24 ,
V_66 | V_65 ,
V_67 ) ;
}
F_67 ( & V_7 -> V_2 ) ;
}
return V_7 ;
}
struct V_6 * F_68 ( const char * V_53 , ... )
{
struct V_6 * V_7 ;
T_4 V_54 ;
va_start ( V_54 , V_53 ) ;
V_7 = F_62 ( V_53 , V_54 ) ;
va_end ( V_54 ) ;
return V_7 ;
}
void F_69 ( struct V_6 * V_7 )
{
if ( V_7 )
F_70 ( & V_7 -> V_2 ) ;
}
static void F_71 ( struct V_1 * V_2 , void * V_79 )
{
F_69 ( * (struct V_6 * * ) V_79 ) ;
}
static int F_72 ( struct V_1 * V_2 , void * V_79 , void * V_80 )
{
struct V_6 * * V_81 = V_79 ;
if ( ! V_81 || ! * V_81 ) {
F_73 ( ! V_81 || ! * V_81 ) ;
return 0 ;
}
return * V_81 == V_80 ;
}
struct V_6 * F_74 ( struct V_1 * V_2 ,
const char * V_53 , ... )
{
struct V_6 * * V_82 , * V_7 ;
T_4 V_54 ;
V_82 = F_75 ( F_71 , sizeof( * V_82 ) ,
V_15 ) ;
if ( ! V_82 )
return NULL ;
va_start ( V_54 , V_53 ) ;
V_7 = F_62 ( V_53 , V_54 ) ;
va_end ( V_54 ) ;
if ( V_7 ) {
* V_82 = V_7 ;
F_76 ( V_2 , V_82 ) ;
} else {
F_77 ( V_82 ) ;
}
return V_7 ;
}
void F_78 ( struct V_1 * V_2 , struct V_6 * V_83 )
{
int V_84 ;
V_84 = F_79 ( V_2 , F_71 ,
F_72 , V_83 ) ;
F_73 ( V_84 ) ;
}
void F_80 ( struct V_52 * V_39 )
{
V_39 -> V_85 [ V_39 -> V_86 ++ ] =
& V_87 ;
}
void F_81 ( struct V_52 * V_39 )
{
if ( V_39 -> V_7 )
F_51 ( V_39 -> V_7 ) ;
}
int F_82 ( struct V_52 * V_39 )
{
return F_33 ( V_39 -> V_7 ,
V_39 -> V_88 ) ;
}
int F_83 ( struct V_52 * V_39 )
{
return F_39 ( V_39 -> V_7 ,
V_39 -> V_88 ) ;
}
