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
if ( F_24 ( ! V_42 ) )
return;
F_38 ( V_42 , L_1 ,
F_39 ( & V_45 , F_40 ( V_46 ) ) ,
F_41 ( V_46 ) ) ;
F_42 ( V_42 , V_27 ) ;
F_38 ( V_42 , L_2 ) ;
F_43 ( V_42 , V_39 -> V_13 ) ;
F_44 ( V_42 , V_38 -> V_47 ) ;
F_38 ( V_42 , L_3 , V_38 -> V_29 ) ;
F_45 ( V_42 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
const char * V_48 , T_1 V_16 ,
unsigned long V_15 , unsigned V_49 )
{
struct V_9 * V_50 , * V_51 , * V_52 ;
struct V_24 * V_38 , * V_53 ;
struct V_54 * V_55 , * V_56 ;
F_47 ( & V_57 ) ;
F_48 (owatch, nextw, &parent->watches, wlist) {
if ( F_49 ( V_48 , V_50 -> V_13 ,
V_58 ) )
continue;
if ( V_49 && ! F_50 () )
F_51 ( V_46 , V_46 -> V_59 ) ;
V_51 = F_34 ( V_50 ) ;
if ( F_32 ( V_51 ) ) {
F_52 ( & V_57 ) ;
F_53 ( L_4 ) ;
return;
}
V_51 -> V_16 = V_16 ;
V_51 -> V_15 = V_15 ;
F_48 (r, nextr, &owatch->rules, rlist) {
V_55 = F_6 ( V_38 , struct V_54 , V_60 ) ;
F_19 ( & V_55 -> V_60 . V_61 ) ;
F_54 ( & V_55 -> V_62 ) ;
V_56 = F_55 ( & V_55 -> V_60 ) ;
if ( F_32 ( V_56 ) ) {
F_19 ( & V_55 -> V_60 . V_62 ) ;
F_53 ( L_5 ) ;
} else {
int V_63 = F_56 ( ( T_2 ) V_15 ) ;
F_16 ( V_56 -> V_60 . V_10 ) ;
F_14 ( V_51 ) ;
V_56 -> V_60 . V_10 = V_51 ;
F_57 ( & V_56 -> V_60 . V_61 , & V_51 -> V_12 ) ;
F_58 ( & V_56 -> V_62 , & V_64 [ V_63 ] ) ;
F_59 ( & V_55 -> V_60 . V_62 ,
& V_56 -> V_60 . V_62 ) ;
}
F_36 ( V_38 , V_50 , L_6 ) ;
F_60 ( & V_55 -> V_65 , V_66 ) ;
}
F_18 ( V_50 ) ;
goto V_67;
}
F_52 ( & V_57 ) ;
return;
V_67:
F_57 ( & V_51 -> V_14 , & V_2 -> V_3 ) ;
F_52 ( & V_57 ) ;
return;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_9 * V_39 , * V_52 ;
struct V_24 * V_38 , * V_53 ;
struct V_54 * V_68 ;
F_47 ( & V_57 ) ;
F_48 (w, nextw, &parent->watches, wlist) {
F_48 (r, nextr, &w->rules, rlist) {
V_68 = F_6 ( V_38 , struct V_54 , V_60 ) ;
F_36 ( V_38 , V_39 , L_7 ) ;
F_19 ( & V_38 -> V_61 ) ;
F_19 ( & V_38 -> V_62 ) ;
F_54 ( & V_68 -> V_62 ) ;
F_60 ( & V_68 -> V_65 , V_66 ) ;
}
F_18 ( V_39 ) ;
}
F_52 ( & V_57 ) ;
F_62 ( & V_2 -> V_6 , V_8 ) ;
}
static int F_63 ( struct V_9 * V_10 , struct V_13 * V_2 )
{
struct V_17 * V_69 = F_64 ( V_10 -> V_13 , V_2 ) ;
if ( F_32 ( V_69 ) )
return F_33 ( V_69 ) ;
F_52 ( & V_2 -> V_17 -> V_18 -> V_70 ) ;
if ( V_69 -> V_18 ) {
V_10 -> V_16 = V_69 -> V_18 -> V_71 -> V_72 ;
V_10 -> V_15 = V_69 -> V_18 -> V_73 ;
}
F_65 ( V_69 ) ;
return 0 ;
}
static void F_66 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_9 * V_39 , * V_10 = V_25 -> V_10 ;
int V_74 = 0 ;
F_67 ( ! F_68 ( & V_57 ) ) ;
F_69 (w, &parent->watches, wlist) {
if ( strcmp ( V_10 -> V_13 , V_39 -> V_13 ) )
continue;
V_74 = 1 ;
F_16 ( V_10 ) ;
F_16 ( V_10 ) ;
F_14 ( V_39 ) ;
V_25 -> V_10 = V_10 = V_39 ;
break;
}
if ( ! V_74 ) {
F_7 ( V_2 ) ;
V_10 -> V_2 = V_2 ;
F_57 ( & V_10 -> V_14 , & V_2 -> V_3 ) ;
}
F_57 ( & V_25 -> V_61 , & V_10 -> V_12 ) ;
}
int F_70 ( struct V_24 * V_25 , struct V_75 * * V_62 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 ;
struct V_13 V_76 ;
int V_63 , V_19 = 0 ;
F_52 ( & V_57 ) ;
V_19 = F_63 ( V_10 , & V_76 ) ;
F_47 ( & V_57 ) ;
if ( V_19 )
return V_19 ;
V_2 = F_12 ( V_76 . V_17 -> V_18 ) ;
if ( ! V_2 ) {
V_2 = F_22 ( & V_76 ) ;
if ( F_32 ( V_2 ) ) {
V_19 = F_33 ( V_2 ) ;
goto error;
}
}
F_66 ( V_25 , V_2 ) ;
F_10 ( V_2 ) ;
V_63 = F_56 ( ( T_2 ) V_10 -> V_15 ) ;
* V_62 = & V_64 [ V_63 ] ;
error:
F_71 ( & V_76 ) ;
return V_19 ;
}
void F_72 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = V_25 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_19 ( & V_25 -> V_61 ) ;
if ( F_3 ( & V_10 -> V_12 ) ) {
F_18 ( V_10 ) ;
if ( F_3 ( & V_2 -> V_3 ) ) {
F_7 ( V_2 ) ;
F_62 ( & V_2 -> V_6 , V_8 ) ;
F_10 ( V_2 ) ;
}
}
}
static bool F_73 ( struct V_77 * V_78 , struct V_7 * V_7 ,
struct V_4 * V_79 ,
struct V_4 * V_80 ,
T_3 V_22 , void * V_81 , int V_82 )
{
return true ;
}
static int F_74 ( struct V_77 * V_78 ,
struct V_4 * V_79 ,
struct V_4 * V_80 ,
struct V_83 * V_84 )
{
struct V_7 * V_7 ;
T_3 V_22 = V_84 -> V_22 ;
const char * V_48 = V_84 -> V_85 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_79 , struct V_1 , V_6 ) ;
F_67 ( V_78 != V_8 ) ;
switch ( V_84 -> V_82 ) {
case ( V_86 ) :
V_7 = V_84 -> V_13 . V_17 -> V_18 ;
break;
case ( V_87 ) :
V_7 = V_84 -> V_7 ;
break;
default:
F_75 () ;
V_7 = NULL ;
break;
} ;
if ( V_22 & ( V_88 | V_89 ) && V_7 )
F_46 ( V_2 , V_48 , V_7 -> V_71 -> V_72 , V_7 -> V_73 , 0 ) ;
else if ( V_22 & ( V_90 | V_91 ) )
F_46 ( V_2 , V_48 , ( T_1 ) - 1 , ( unsigned long ) - 1 , 1 ) ;
else if ( V_22 & ( V_92 | V_93 | V_94 ) )
F_61 ( V_2 ) ;
return 0 ;
}
static int T_4 F_76 ( void )
{
V_8 = F_77 ( & V_95 ) ;
if ( F_32 ( V_8 ) ) {
V_8 = NULL ;
F_53 ( L_8 ) ;
}
return 0 ;
}
