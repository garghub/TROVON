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
struct V_7 * V_7 = F_23 ( V_13 -> V_17 ) ;
struct V_1 * V_2 ;
int V_18 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_19 ) ;
if ( F_25 ( ! V_2 ) )
return F_26 ( - V_20 ) ;
F_27 ( & V_2 -> V_3 ) ;
F_28 ( & V_2 -> V_6 , F_5 ) ;
V_2 -> V_6 . V_21 = V_22 ;
V_18 = F_29 ( & V_2 -> V_6 , V_8 , V_7 , NULL , 0 ) ;
if ( V_18 < 0 ) {
F_1 ( V_2 ) ;
return F_26 ( V_18 ) ;
}
return V_2 ;
}
static struct V_9 * F_30 ( char * V_13 )
{
struct V_9 * V_10 ;
V_10 = F_24 ( sizeof( * V_10 ) , V_19 ) ;
if ( F_25 ( ! V_10 ) )
return F_26 ( - V_20 ) ;
F_27 ( & V_10 -> V_12 ) ;
F_31 ( & V_10 -> V_11 , 1 ) ;
V_10 -> V_13 = V_13 ;
V_10 -> V_16 = ( T_1 ) - 1 ;
V_10 -> V_15 = ( unsigned long ) - 1 ;
return V_10 ;
}
int F_32 ( struct V_23 * V_24 , char * V_13 , int V_25 , T_2 V_26 )
{
struct V_9 * V_10 ;
if ( ! V_8 )
return - V_27 ;
if ( V_13 [ 0 ] != '/' || V_13 [ V_25 - 1 ] == '/' ||
V_24 -> V_28 != V_29 ||
V_26 != V_30 ||
V_24 -> V_31 || V_24 -> V_10 || V_24 -> V_32 )
return - V_33 ;
V_10 = F_30 ( V_13 ) ;
if ( F_33 ( V_10 ) )
return F_34 ( V_10 ) ;
F_14 ( V_10 ) ;
V_24 -> V_10 = V_10 ;
return 0 ;
}
static struct V_9 * F_35 ( struct V_9 * V_34 )
{
char * V_13 ;
struct V_9 * V_35 ;
V_13 = F_36 ( V_34 -> V_13 , V_19 ) ;
if ( F_25 ( ! V_13 ) )
return F_26 ( - V_20 ) ;
V_35 = F_30 ( V_13 ) ;
if ( F_33 ( V_35 ) ) {
F_4 ( V_13 ) ;
goto V_36;
}
V_35 -> V_16 = V_34 -> V_16 ;
V_35 -> V_15 = V_34 -> V_15 ;
F_7 ( V_34 -> V_2 ) ;
V_35 -> V_2 = V_34 -> V_2 ;
V_36:
return V_35 ;
}
static void F_37 ( struct V_23 * V_37 , struct V_9 * V_38 , char * V_26 )
{
if ( V_39 ) {
struct V_40 * V_41 ;
V_41 = F_38 ( NULL , V_42 , V_43 ) ;
if ( F_25 ( ! V_41 ) )
return;
F_39 ( V_41 , L_1 ,
F_40 ( & V_44 , F_41 ( V_45 ) ) ,
F_42 ( V_45 ) ) ;
F_43 ( V_41 , V_26 ) ;
F_39 ( V_41 , L_2 ) ;
F_44 ( V_41 , V_38 -> V_13 ) ;
F_45 ( V_41 , V_37 -> V_46 ) ;
F_39 ( V_41 , L_3 , V_37 -> V_28 ) ;
F_46 ( V_41 ) ;
}
}
static void F_47 ( struct V_1 * V_2 ,
const char * V_47 , T_1 V_16 ,
unsigned long V_15 , unsigned V_48 )
{
struct V_9 * V_49 , * V_50 , * V_51 ;
struct V_23 * V_37 , * V_52 ;
struct V_53 * V_54 , * V_55 ;
F_48 ( & V_56 ) ;
F_49 (owatch, nextw, &parent->watches, wlist) {
if ( F_50 ( V_47 , V_49 -> V_13 ,
V_57 ) )
continue;
if ( V_48 && ! F_51 () )
F_52 ( V_45 , V_45 -> V_58 ) ;
V_50 = F_35 ( V_49 ) ;
if ( F_33 ( V_50 ) ) {
F_53 ( & V_56 ) ;
F_54 ( L_4 ) ;
return;
}
V_50 -> V_16 = V_16 ;
V_50 -> V_15 = V_15 ;
F_49 (r, nextr, &owatch->rules, rlist) {
V_54 = F_6 ( V_37 , struct V_53 , V_59 ) ;
F_19 ( & V_54 -> V_59 . V_60 ) ;
F_55 ( & V_54 -> V_61 ) ;
V_55 = F_56 ( & V_54 -> V_59 ) ;
if ( F_33 ( V_55 ) ) {
F_19 ( & V_54 -> V_59 . V_61 ) ;
F_54 ( L_5 ) ;
} else {
int V_62 = F_57 ( ( T_2 ) V_15 ) ;
F_16 ( V_55 -> V_59 . V_10 ) ;
F_14 ( V_50 ) ;
V_55 -> V_59 . V_10 = V_50 ;
F_58 ( & V_55 -> V_59 . V_60 , & V_50 -> V_12 ) ;
F_59 ( & V_55 -> V_61 , & V_63 [ V_62 ] ) ;
F_60 ( & V_54 -> V_59 . V_61 ,
& V_55 -> V_59 . V_61 ) ;
}
F_37 ( V_37 , V_49 , L_6 ) ;
F_61 ( & V_54 -> V_64 , V_65 ) ;
}
F_18 ( V_49 ) ;
goto V_66;
}
F_53 ( & V_56 ) ;
return;
V_66:
F_58 ( & V_50 -> V_14 , & V_2 -> V_3 ) ;
F_53 ( & V_56 ) ;
return;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_9 * V_38 , * V_51 ;
struct V_23 * V_37 , * V_52 ;
struct V_53 * V_67 ;
F_48 ( & V_56 ) ;
F_49 (w, nextw, &parent->watches, wlist) {
F_49 (r, nextr, &w->rules, rlist) {
V_67 = F_6 ( V_37 , struct V_53 , V_59 ) ;
F_37 ( V_37 , V_38 , L_7 ) ;
F_19 ( & V_37 -> V_60 ) ;
F_19 ( & V_37 -> V_61 ) ;
F_55 ( & V_67 -> V_61 ) ;
F_61 ( & V_67 -> V_64 , V_65 ) ;
}
F_18 ( V_38 ) ;
}
F_53 ( & V_56 ) ;
F_63 ( & V_2 -> V_6 , V_8 ) ;
}
static int F_64 ( struct V_9 * V_10 , struct V_13 * V_2 )
{
struct V_17 * V_68 = F_65 ( V_10 -> V_13 , V_2 ) ;
if ( F_33 ( V_68 ) )
return F_34 ( V_68 ) ;
F_53 ( & F_23 ( V_2 -> V_17 ) -> V_69 ) ;
if ( F_66 ( V_68 ) ) {
V_10 -> V_16 = F_23 ( V_68 ) -> V_70 -> V_71 ;
V_10 -> V_15 = F_23 ( V_68 ) -> V_72 ;
}
F_67 ( V_68 ) ;
return 0 ;
}
static void F_68 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_9 * V_38 , * V_10 = V_24 -> V_10 ;
int V_73 = 0 ;
F_69 ( ! F_70 ( & V_56 ) ) ;
F_71 (w, &parent->watches, wlist) {
if ( strcmp ( V_10 -> V_13 , V_38 -> V_13 ) )
continue;
V_73 = 1 ;
F_16 ( V_10 ) ;
F_16 ( V_10 ) ;
F_14 ( V_38 ) ;
V_24 -> V_10 = V_10 = V_38 ;
break;
}
if ( ! V_73 ) {
F_7 ( V_2 ) ;
V_10 -> V_2 = V_2 ;
F_58 ( & V_10 -> V_14 , & V_2 -> V_3 ) ;
}
F_58 ( & V_24 -> V_60 , & V_10 -> V_12 ) ;
}
int F_72 ( struct V_23 * V_24 , struct V_74 * * V_61 )
{
struct V_9 * V_10 = V_24 -> V_10 ;
struct V_1 * V_2 ;
struct V_13 V_75 ;
int V_62 , V_18 = 0 ;
F_53 ( & V_56 ) ;
V_18 = F_64 ( V_10 , & V_75 ) ;
F_48 ( & V_56 ) ;
if ( V_18 )
return V_18 ;
V_2 = F_12 ( F_23 ( V_75 . V_17 ) ) ;
if ( ! V_2 ) {
V_2 = F_22 ( & V_75 ) ;
if ( F_33 ( V_2 ) ) {
V_18 = F_34 ( V_2 ) ;
goto error;
}
}
F_68 ( V_24 , V_2 ) ;
F_10 ( V_2 ) ;
V_62 = F_57 ( ( T_2 ) V_10 -> V_15 ) ;
* V_61 = & V_63 [ V_62 ] ;
error:
F_73 ( & V_75 ) ;
return V_18 ;
}
void F_74 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_19 ( & V_24 -> V_60 ) ;
if ( F_3 ( & V_10 -> V_12 ) ) {
F_18 ( V_10 ) ;
if ( F_3 ( & V_2 -> V_3 ) ) {
F_7 ( V_2 ) ;
F_63 ( & V_2 -> V_6 , V_8 ) ;
F_10 ( V_2 ) ;
}
}
}
static int F_75 ( struct V_76 * V_77 ,
struct V_7 * V_78 ,
struct V_4 * V_79 ,
struct V_4 * V_80 ,
T_2 V_21 , void * V_81 , int V_82 ,
const unsigned char * V_47 , T_2 V_83 )
{
struct V_7 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_79 , struct V_1 , V_6 ) ;
F_69 ( V_77 != V_8 ) ;
switch ( V_82 ) {
case ( V_84 ) :
V_7 = F_23 ( ( (struct V_13 * ) V_81 ) -> V_17 ) ;
break;
case ( V_85 ) :
V_7 = (struct V_7 * ) V_81 ;
break;
default:
F_76 () ;
V_7 = NULL ;
break;
} ;
if ( V_21 & ( V_86 | V_87 ) && V_7 )
F_47 ( V_2 , V_47 , V_7 -> V_70 -> V_71 , V_7 -> V_72 , 0 ) ;
else if ( V_21 & ( V_88 | V_89 ) )
F_47 ( V_2 , V_47 , ( T_1 ) - 1 , ( unsigned long ) - 1 , 1 ) ;
else if ( V_21 & ( V_90 | V_91 | V_92 ) )
F_62 ( V_2 ) ;
return 0 ;
}
static int T_3 F_77 ( void )
{
V_8 = F_78 ( & V_93 ) ;
if ( F_33 ( V_8 ) ) {
V_8 = NULL ;
F_54 ( L_8 ) ;
}
return 0 ;
}
