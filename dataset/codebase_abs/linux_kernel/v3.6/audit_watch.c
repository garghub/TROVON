static void F_1 ( struct V_1 * V_2 )
{
F_2 ( ! F_3 ( & V_2 -> V_3 ) ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_5 , struct V_1 , V_6 ) ;
F_1 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
F_9 ( & V_2 -> V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) )
F_11 ( & V_2 -> V_6 ) ;
}
static inline struct V_1 * F_12 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = NULL ;
struct V_4 * V_5 ;
V_5 = F_13 ( V_8 , V_7 ) ;
if ( V_5 )
V_2 = F_6 ( V_5 , struct V_1 , V_6 ) ;
return V_2 ;
}
void F_14 ( struct V_9 * V_10 )
{
F_15 ( & V_10 -> V_11 ) ;
}
void F_16 ( struct V_9 * V_10 )
{
if ( F_17 ( & V_10 -> V_11 ) ) {
F_2 ( V_10 -> V_2 ) ;
F_2 ( ! F_3 ( & V_10 -> V_12 ) ) ;
F_4 ( V_10 -> V_13 ) ;
F_4 ( V_10 ) ;
}
}
static void F_18 ( struct V_9 * V_10 )
{
F_19 ( & V_10 -> V_14 ) ;
F_10 ( V_10 -> V_2 ) ;
V_10 -> V_2 = NULL ;
F_16 ( V_10 ) ;
}
char * F_20 ( struct V_9 * V_10 )
{
return V_10 -> V_13 ;
}
int F_21 ( struct V_9 * V_10 , unsigned long V_15 , T_1 V_16 )
{
return ( V_10 -> V_15 != ( unsigned long ) - 1 ) &&
( V_10 -> V_15 == V_15 ) &&
( V_10 -> V_16 == V_16 ) ;
}
static struct V_1 * F_22 ( struct V_13 * V_13 )
{
struct V_7 * V_7 = V_13 -> V_17 -> V_18 ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_20 ) ;
if ( F_24 ( ! V_2 ) )
return F_25 ( - V_21 ) ;
F_26 ( & V_2 -> V_3 ) ;
F_27 ( & V_2 -> V_6 , F_5 ) ;
V_2 -> V_6 . V_22 = V_23 ;
V_19 = F_28 ( & V_2 -> V_6 , V_8 , V_7 , NULL , 0 ) ;
if ( V_19 < 0 ) {
F_1 ( V_2 ) ;
return F_25 ( V_19 ) ;
}
return V_2 ;
}
static struct V_9 * F_29 ( char * V_13 )
{
struct V_9 * V_10 ;
V_10 = F_23 ( sizeof( * V_10 ) , V_20 ) ;
if ( F_24 ( ! V_10 ) )
return F_25 ( - V_21 ) ;
F_26 ( & V_10 -> V_12 ) ;
F_30 ( & V_10 -> V_11 , 1 ) ;
V_10 -> V_13 = V_13 ;
V_10 -> V_16 = ( T_1 ) - 1 ;
V_10 -> V_15 = ( unsigned long ) - 1 ;
return V_10 ;
}
int F_31 ( struct V_24 * V_25 , char * V_13 , int V_26 , T_2 V_27 )
{
struct V_9 * V_10 ;
if ( ! V_8 )
return - V_28 ;
if ( V_13 [ 0 ] != '/' || V_13 [ V_26 - 1 ] == '/' ||
V_25 -> V_29 != V_30 ||
V_27 != V_31 ||
V_25 -> V_32 || V_25 -> V_10 || V_25 -> V_33 )
return - V_34 ;
V_10 = F_29 ( V_13 ) ;
if ( F_32 ( V_10 ) )
return F_33 ( V_10 ) ;
F_14 ( V_10 ) ;
V_25 -> V_10 = V_10 ;
return 0 ;
}
static struct V_9 * F_34 ( struct V_9 * V_35 )
{
char * V_13 ;
struct V_9 * V_36 ;
V_13 = F_35 ( V_35 -> V_13 , V_20 ) ;
if ( F_24 ( ! V_13 ) )
return F_25 ( - V_21 ) ;
V_36 = F_29 ( V_13 ) ;
if ( F_32 ( V_36 ) ) {
F_4 ( V_13 ) ;
goto V_37;
}
V_36 -> V_16 = V_35 -> V_16 ;
V_36 -> V_15 = V_35 -> V_15 ;
F_7 ( V_35 -> V_2 ) ;
V_36 -> V_2 = V_35 -> V_2 ;
V_37:
return V_36 ;
}
static void F_36 ( struct V_24 * V_38 , struct V_9 * V_39 , char * V_27 )
{
if ( V_40 ) {
struct V_41 * V_42 ;
V_42 = F_37 ( NULL , V_43 , V_44 ) ;
F_38 ( V_42 , L_1 ,
F_39 ( V_45 ) ,
F_40 ( V_45 ) ) ;
F_41 ( V_42 , V_27 ) ;
F_38 ( V_42 , L_2 ) ;
F_42 ( V_42 , V_39 -> V_13 ) ;
F_43 ( V_42 , V_38 -> V_46 ) ;
F_38 ( V_42 , L_3 , V_38 -> V_29 ) ;
F_44 ( V_42 ) ;
}
}
static void F_45 ( struct V_1 * V_2 ,
const char * V_47 , T_1 V_16 ,
unsigned long V_15 , unsigned V_48 )
{
struct V_9 * V_49 , * V_50 , * V_51 ;
struct V_24 * V_38 , * V_52 ;
struct V_53 * V_54 , * V_55 ;
F_46 ( & V_56 ) ;
F_47 (owatch, nextw, &parent->watches, wlist) {
if ( F_48 ( V_47 , V_49 -> V_13 , NULL ) )
continue;
if ( V_48 && ! F_49 () )
F_50 ( V_45 , V_45 -> V_57 ) ;
V_50 = F_34 ( V_49 ) ;
if ( F_32 ( V_50 ) ) {
F_51 ( & V_56 ) ;
F_52 ( L_4 ) ;
return;
}
V_50 -> V_16 = V_16 ;
V_50 -> V_15 = V_15 ;
F_47 (r, nextr, &owatch->rules, rlist) {
V_54 = F_6 ( V_38 , struct V_53 , V_58 ) ;
F_19 ( & V_54 -> V_58 . V_59 ) ;
F_53 ( & V_54 -> V_60 ) ;
V_55 = F_54 ( & V_54 -> V_58 ) ;
if ( F_32 ( V_55 ) ) {
F_19 ( & V_54 -> V_58 . V_60 ) ;
F_52 ( L_5 ) ;
} else {
int V_61 = F_55 ( ( T_2 ) V_15 ) ;
F_16 ( V_55 -> V_58 . V_10 ) ;
F_14 ( V_50 ) ;
V_55 -> V_58 . V_10 = V_50 ;
F_56 ( & V_55 -> V_58 . V_59 , & V_50 -> V_12 ) ;
F_57 ( & V_55 -> V_60 , & V_62 [ V_61 ] ) ;
F_58 ( & V_54 -> V_58 . V_60 ,
& V_55 -> V_58 . V_60 ) ;
}
F_36 ( V_38 , V_49 , L_6 ) ;
F_59 ( & V_54 -> V_63 , V_64 ) ;
}
F_18 ( V_49 ) ;
goto V_65;
}
F_51 ( & V_56 ) ;
return;
V_65:
F_56 ( & V_50 -> V_14 , & V_2 -> V_3 ) ;
F_51 ( & V_56 ) ;
return;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_9 * V_39 , * V_51 ;
struct V_24 * V_38 , * V_52 ;
struct V_53 * V_66 ;
F_46 ( & V_56 ) ;
F_47 (w, nextw, &parent->watches, wlist) {
F_47 (r, nextr, &w->rules, rlist) {
V_66 = F_6 ( V_38 , struct V_53 , V_58 ) ;
F_36 ( V_38 , V_39 , L_7 ) ;
F_19 ( & V_38 -> V_59 ) ;
F_19 ( & V_38 -> V_60 ) ;
F_53 ( & V_66 -> V_60 ) ;
F_59 ( & V_66 -> V_63 , V_64 ) ;
}
F_18 ( V_39 ) ;
}
F_51 ( & V_56 ) ;
F_61 ( & V_2 -> V_6 ) ;
}
static int F_62 ( struct V_9 * V_10 , struct V_13 * V_2 )
{
struct V_17 * V_67 = F_63 ( V_10 -> V_13 , V_2 ) ;
if ( F_32 ( V_67 ) )
return F_33 ( V_67 ) ;
F_51 ( & V_2 -> V_17 -> V_18 -> V_68 ) ;
if ( V_67 -> V_18 ) {
V_10 -> V_16 = V_67 -> V_18 -> V_69 -> V_70 ;
V_10 -> V_15 = V_67 -> V_18 -> V_71 ;
}
F_64 ( V_67 ) ;
return 0 ;
}
static void F_65 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_9 * V_39 , * V_10 = V_25 -> V_10 ;
int V_72 = 0 ;
F_66 ( ! F_67 ( & V_56 ) ) ;
F_68 (w, &parent->watches, wlist) {
if ( strcmp ( V_10 -> V_13 , V_39 -> V_13 ) )
continue;
V_72 = 1 ;
F_16 ( V_10 ) ;
F_16 ( V_10 ) ;
F_14 ( V_39 ) ;
V_25 -> V_10 = V_10 = V_39 ;
break;
}
if ( ! V_72 ) {
F_7 ( V_2 ) ;
V_10 -> V_2 = V_2 ;
F_56 ( & V_10 -> V_14 , & V_2 -> V_3 ) ;
}
F_56 ( & V_25 -> V_59 , & V_10 -> V_12 ) ;
}
int F_69 ( struct V_24 * V_25 , struct V_73 * * V_60 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 ;
struct V_13 V_74 ;
int V_61 , V_19 = 0 ;
F_51 ( & V_56 ) ;
V_19 = F_62 ( V_10 , & V_74 ) ;
F_46 ( & V_56 ) ;
if ( V_19 )
return V_19 ;
V_2 = F_12 ( V_74 . V_17 -> V_18 ) ;
if ( ! V_2 ) {
V_2 = F_22 ( & V_74 ) ;
if ( F_32 ( V_2 ) ) {
V_19 = F_33 ( V_2 ) ;
goto error;
}
}
F_65 ( V_25 , V_2 ) ;
F_10 ( V_2 ) ;
V_61 = F_55 ( ( T_2 ) V_10 -> V_15 ) ;
* V_60 = & V_62 [ V_61 ] ;
error:
F_70 ( & V_74 ) ;
return V_19 ;
}
void F_71 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_19 ( & V_25 -> V_59 ) ;
if ( F_3 ( & V_10 -> V_12 ) ) {
F_18 ( V_10 ) ;
if ( F_3 ( & V_2 -> V_3 ) ) {
F_7 ( V_2 ) ;
F_61 ( & V_2 -> V_6 ) ;
F_10 ( V_2 ) ;
}
}
}
static bool F_72 ( struct V_75 * V_76 , struct V_7 * V_7 ,
struct V_4 * V_77 ,
struct V_4 * V_78 ,
T_3 V_22 , void * V_79 , int V_80 )
{
return true ;
}
static int F_73 ( struct V_75 * V_76 ,
struct V_4 * V_77 ,
struct V_4 * V_78 ,
struct V_81 * V_82 )
{
struct V_7 * V_7 ;
T_3 V_22 = V_82 -> V_22 ;
const char * V_47 = V_82 -> V_83 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_77 , struct V_1 , V_6 ) ;
F_66 ( V_76 != V_8 ) ;
switch ( V_82 -> V_80 ) {
case ( V_84 ) :
V_7 = V_82 -> V_13 . V_17 -> V_18 ;
break;
case ( V_85 ) :
V_7 = V_82 -> V_7 ;
break;
default:
F_74 () ;
V_7 = NULL ;
break;
} ;
if ( V_22 & ( V_86 | V_87 ) && V_7 )
F_45 ( V_2 , V_47 , V_7 -> V_69 -> V_70 , V_7 -> V_71 , 0 ) ;
else if ( V_22 & ( V_88 | V_89 ) )
F_45 ( V_2 , V_47 , ( T_1 ) - 1 , ( unsigned long ) - 1 , 1 ) ;
else if ( V_22 & ( V_90 | V_91 | V_92 ) )
F_60 ( V_2 ) ;
return 0 ;
}
static int T_4 F_75 ( void )
{
V_8 = F_76 ( & V_93 ) ;
if ( F_32 ( V_8 ) ) {
V_8 = NULL ;
F_52 ( L_8 ) ;
}
return 0 ;
}
