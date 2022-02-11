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
int F_16 ( struct V_22 * V_23 , struct V_6 * V_7 )
{
if ( ! V_23 || ! V_7 )
return - V_12 ;
F_7 ( & V_23 -> V_24 ) ;
F_17 ( V_23 -> V_25 ) ;
V_23 -> V_7 = F_18 ( V_7 ) ;
V_23 -> V_25 = true ;
F_11 ( & V_23 -> V_24 ) ;
return 0 ;
}
static struct V_6 * F_8 ( const char * V_8 )
{
struct V_6 * V_26 ;
F_19 (iter, &iio_trigger_list, list)
if ( ! strcmp ( V_26 -> V_8 , V_8 ) )
return V_26 ;
return NULL ;
}
static struct V_6 * F_20 ( const char * V_8 ,
T_2 V_27 )
{
struct V_6 * V_7 = NULL , * V_26 ;
F_7 ( & V_17 ) ;
F_19 (iter, &iio_trigger_list, list)
if ( F_21 ( V_26 -> V_8 , V_8 ) ) {
V_7 = V_26 ;
break;
}
F_11 ( & V_17 ) ;
return V_7 ;
}
void F_22 ( struct V_6 * V_7 )
{
int V_28 ;
if ( ! F_23 ( & V_7 -> V_29 ) ) {
F_24 ( & V_7 -> V_29 , V_30 ) ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( V_7 -> V_31 [ V_28 ] . V_32 )
F_25 ( V_7 -> V_33 + V_28 ) ;
else
F_26 ( V_7 ) ;
}
}
}
T_3 F_27 ( int V_34 , void * V_35 )
{
F_22 ( V_35 ) ;
return V_36 ;
}
void F_28 ( struct V_6 * V_7 )
{
int V_28 ;
if ( ! F_23 ( & V_7 -> V_29 ) ) {
F_24 ( & V_7 -> V_29 , V_30 ) ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( V_7 -> V_31 [ V_28 ] . V_32 )
F_29 ( V_7 -> V_33 + V_28 ) ;
else
F_26 ( V_7 ) ;
}
}
}
void F_26 ( struct V_6 * V_7 )
{
if ( F_30 ( & V_7 -> V_29 ) && V_7 -> V_11 -> V_37 )
if ( V_7 -> V_11 -> V_37 ( V_7 ) )
F_22 ( V_7 ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
int V_10 ;
F_7 ( & V_7 -> V_38 ) ;
V_10 = F_32 ( V_7 -> V_39 ,
V_30 ,
F_33 ( 1 ) ) ;
F_11 ( & V_7 -> V_38 ) ;
if ( V_10 >= 0 )
V_10 += V_7 -> V_33 ;
return V_10 ;
}
static void F_34 ( struct V_6 * V_7 , int V_34 )
{
F_7 ( & V_7 -> V_38 ) ;
F_35 ( V_34 - V_7 -> V_33 , V_7 -> V_39 ) ;
F_11 ( & V_7 -> V_38 ) ;
}
static int F_36 ( struct V_6 * V_7 ,
struct V_40 * V_41 )
{
int V_10 = 0 ;
bool V_42
= F_37 ( V_7 -> V_39 , V_30 ) ;
F_38 ( V_41 -> V_23 -> V_43 -> V_44 ) ;
V_41 -> V_34 = F_31 ( V_7 ) ;
if ( V_41 -> V_34 < 0 )
goto V_45;
V_10 = F_39 ( V_41 -> V_34 , V_41 -> V_46 , V_41 -> V_47 ,
V_41 -> type , V_41 -> V_8 ,
V_41 ) ;
if ( V_10 < 0 )
goto V_48;
if ( V_7 -> V_11 -> V_49 && V_42 ) {
V_10 = V_7 -> V_11 -> V_49 ( V_7 , true ) ;
if ( V_10 < 0 )
goto V_50;
}
if ( V_41 -> V_23 -> V_2 . V_51 == V_7 -> V_2 . V_51 )
V_7 -> V_52 = true ;
return V_10 ;
V_50:
F_40 ( V_41 -> V_34 , V_41 ) ;
V_48:
F_34 ( V_7 , V_41 -> V_34 ) ;
V_45:
F_41 ( V_41 -> V_23 -> V_43 -> V_44 ) ;
return V_10 ;
}
static int F_42 ( struct V_6 * V_7 ,
struct V_40 * V_41 )
{
int V_10 = 0 ;
bool V_53
= ( F_43 ( V_7 -> V_39 ,
V_30 )
== 1 ) ;
if ( V_7 -> V_11 -> V_49 && V_53 ) {
V_10 = V_7 -> V_11 -> V_49 ( V_7 , false ) ;
if ( V_10 )
return V_10 ;
}
if ( V_41 -> V_23 -> V_2 . V_51 == V_7 -> V_2 . V_51 )
V_7 -> V_52 = false ;
F_34 ( V_7 , V_41 -> V_34 ) ;
F_40 ( V_41 -> V_34 , V_41 ) ;
F_41 ( V_41 -> V_23 -> V_43 -> V_44 ) ;
return V_10 ;
}
T_3 F_44 ( int V_34 , void * V_54 )
{
struct V_40 * V_41 = V_54 ;
V_41 -> V_55 = F_45 ( V_41 -> V_23 ) ;
return V_56 ;
}
struct V_40
* F_46 ( T_3 (* V_46)( int V_34 , void * V_54 ) ,
T_3 (* V_47)( int V_34 , void * V_54 ) ,
int type ,
struct V_22 * V_23 ,
const char * V_57 ,
... )
{
T_4 V_58 ;
struct V_40 * V_41 ;
V_41 = F_47 ( sizeof *V_41 , V_15 ) ;
if ( V_41 == NULL )
return NULL ;
va_start ( V_58 , V_57 ) ;
V_41 -> V_8 = F_48 ( V_15 , V_57 , V_58 ) ;
va_end ( V_58 ) ;
if ( V_41 -> V_8 == NULL ) {
F_49 ( V_41 ) ;
return NULL ;
}
V_41 -> V_46 = V_46 ;
V_41 -> V_47 = V_47 ;
V_41 -> type = type ;
V_41 -> V_23 = V_23 ;
return V_41 ;
}
void F_50 ( struct V_40 * V_41 )
{
F_49 ( V_41 -> V_8 ) ;
F_49 ( V_41 ) ;
}
static T_1 F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_22 * V_23 = F_52 ( V_2 ) ;
if ( V_23 -> V_7 )
return sprintf ( V_5 , L_1 , V_23 -> V_7 -> V_8 ) ;
return 0 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_27 )
{
struct V_22 * V_23 = F_52 ( V_2 ) ;
struct V_6 * V_59 = V_23 -> V_7 ;
struct V_6 * V_7 ;
int V_10 ;
F_7 ( & V_23 -> V_24 ) ;
if ( V_23 -> V_60 == V_61 ) {
F_11 ( & V_23 -> V_24 ) ;
return - V_62 ;
}
if ( V_23 -> V_25 ) {
F_11 ( & V_23 -> V_24 ) ;
return - V_63 ;
}
F_11 ( & V_23 -> V_24 ) ;
V_7 = F_20 ( V_5 , V_27 ) ;
if ( V_59 == V_7 )
return V_27 ;
if ( V_7 && V_23 -> V_43 -> V_64 ) {
V_10 = V_23 -> V_43 -> V_64 ( V_23 , V_7 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_7 && V_7 -> V_11 -> V_65 ) {
V_10 = V_7 -> V_11 -> V_65 ( V_7 , V_23 ) ;
if ( V_10 )
return V_10 ;
}
V_23 -> V_7 = V_7 ;
if ( V_59 ) {
if ( V_23 -> V_66 & V_67 )
F_42 ( V_59 ,
V_23 -> V_68 ) ;
F_54 ( V_59 ) ;
}
if ( V_23 -> V_7 ) {
F_18 ( V_23 -> V_7 ) ;
if ( V_23 -> V_66 & V_67 )
F_36 ( V_23 -> V_7 ,
V_23 -> V_68 ) ;
}
return V_27 ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_2 ( V_1 ) ;
int V_28 ;
if ( V_7 -> V_33 ) {
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
F_56 ( V_7 -> V_33 + V_28 ,
V_69 ,
V_70 | V_71 ) ;
F_57 ( V_7 -> V_33 + V_28 ,
NULL ) ;
F_58 ( V_7 -> V_33 + V_28 ,
NULL ) ;
}
F_59 ( V_7 -> V_33 ,
V_30 ) ;
}
F_49 ( V_7 -> V_8 ) ;
F_49 ( V_7 ) ;
}
static void F_60 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = F_61 ( V_73 ) ;
struct V_6 * V_7
= F_62 ( V_75 ,
struct V_6 , V_76 ) ;
V_7 -> V_31 [ V_73 -> V_34 - V_7 -> V_33 ] . V_32 = false ;
}
static void F_63 ( struct V_72 * V_73 )
{
struct V_74 * V_75 = F_61 ( V_73 ) ;
struct V_6 * V_7
= F_62 ( V_75 ,
struct V_6 , V_76 ) ;
V_7 -> V_31 [ V_73 -> V_34 - V_7 -> V_33 ] . V_32 = true ;
}
static struct V_6 * F_64 ( const char * V_57 , T_4 V_58 )
{
struct V_6 * V_7 ;
V_7 = F_65 ( sizeof *V_7 , V_15 ) ;
if ( V_7 ) {
int V_28 ;
V_7 -> V_2 . type = & V_77 ;
V_7 -> V_2 . V_78 = & V_79 ;
F_66 ( & V_7 -> V_2 ) ;
F_67 ( & V_7 -> V_38 ) ;
V_7 -> V_33
= F_68 ( - 1 , 0 ,
V_30 ,
0 ) ;
if ( V_7 -> V_33 < 0 ) {
F_49 ( V_7 ) ;
return NULL ;
}
V_7 -> V_8 = F_48 ( V_15 , V_57 , V_58 ) ;
if ( V_7 -> V_8 == NULL ) {
F_59 ( V_7 -> V_33 ,
V_30 ) ;
F_49 ( V_7 ) ;
return NULL ;
}
V_7 -> V_76 . V_8 = V_7 -> V_8 ;
V_7 -> V_76 . V_80 = & F_60 ;
V_7 -> V_76 . V_81 = & F_63 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
F_57 ( V_7 -> V_33 + V_28 ,
& V_7 -> V_76 ) ;
F_58 ( V_7 -> V_33 + V_28 ,
& V_82 ) ;
F_56 ( V_7 -> V_33 + V_28 ,
V_70 | V_69 ,
V_71 ) ;
}
F_69 ( & V_7 -> V_2 ) ;
}
return V_7 ;
}
struct V_6 * F_70 ( const char * V_57 , ... )
{
struct V_6 * V_7 ;
T_4 V_58 ;
va_start ( V_58 , V_57 ) ;
V_7 = F_64 ( V_57 , V_58 ) ;
va_end ( V_58 ) ;
return V_7 ;
}
void F_71 ( struct V_6 * V_7 )
{
if ( V_7 )
F_72 ( & V_7 -> V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 , void * V_83 )
{
F_71 ( * (struct V_6 * * ) V_83 ) ;
}
static int F_74 ( struct V_1 * V_2 , void * V_83 , void * V_84 )
{
struct V_6 * * V_85 = V_83 ;
if ( ! V_85 || ! * V_85 ) {
F_17 ( ! V_85 || ! * V_85 ) ;
return 0 ;
}
return * V_85 == V_84 ;
}
struct V_6 * F_75 ( struct V_1 * V_2 ,
const char * V_57 , ... )
{
struct V_6 * * V_86 , * V_7 ;
T_4 V_58 ;
V_86 = F_76 ( F_73 , sizeof( * V_86 ) ,
V_15 ) ;
if ( ! V_86 )
return NULL ;
va_start ( V_58 , V_57 ) ;
V_7 = F_64 ( V_57 , V_58 ) ;
va_end ( V_58 ) ;
if ( V_7 ) {
* V_86 = V_7 ;
F_77 ( V_2 , V_86 ) ;
} else {
F_78 ( V_86 ) ;
}
return V_7 ;
}
void F_79 ( struct V_1 * V_2 , struct V_6 * V_87 )
{
int V_88 ;
V_88 = F_80 ( V_2 , F_73 ,
F_74 , V_87 ) ;
F_17 ( V_88 ) ;
}
static void F_81 ( struct V_1 * V_2 , void * V_83 )
{
F_14 ( * (struct V_6 * * ) V_83 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_6 * V_9 )
{
struct V_6 * * V_86 ;
int V_10 ;
V_86 = F_76 ( F_81 , sizeof( * V_86 ) , V_15 ) ;
if ( ! V_86 )
return - V_89 ;
* V_86 = V_9 ;
V_10 = F_3 ( V_9 ) ;
if ( ! V_10 )
F_77 ( V_2 , V_86 ) ;
else
F_78 ( V_86 ) ;
return V_10 ;
}
void F_83 ( struct V_1 * V_2 ,
struct V_6 * V_9 )
{
int V_88 ;
V_88 = F_80 ( V_2 , F_81 , F_74 ,
V_9 ) ;
F_17 ( V_88 ) ;
}
bool F_84 ( struct V_22 * V_23 )
{
return V_23 -> V_7 -> V_52 ;
}
int F_85 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_2 . V_51 != V_7 -> V_2 . V_51 )
return - V_12 ;
return 0 ;
}
void F_86 ( struct V_22 * V_23 )
{
V_23 -> V_90 [ V_23 -> V_91 ++ ] =
& V_92 ;
}
void F_87 ( struct V_22 * V_23 )
{
if ( V_23 -> V_7 )
F_54 ( V_23 -> V_7 ) ;
}
int F_88 ( struct V_22 * V_23 )
{
return F_36 ( V_23 -> V_7 ,
V_23 -> V_93 ) ;
}
int F_89 ( struct V_22 * V_23 )
{
return F_42 ( V_23 -> V_7 ,
V_23 -> V_93 ) ;
}
