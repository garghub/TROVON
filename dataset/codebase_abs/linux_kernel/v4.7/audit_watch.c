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
return ( V_10 -> V_15 != V_17 ) &&
( V_10 -> V_15 == V_15 ) &&
( V_10 -> V_16 == V_16 ) ;
}
static struct V_1 * F_22 ( struct V_13 * V_13 )
{
struct V_7 * V_7 = F_23 ( V_13 -> V_18 ) ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_20 ) ;
if ( F_25 ( ! V_2 ) )
return F_26 ( - V_21 ) ;
F_27 ( & V_2 -> V_3 ) ;
F_28 ( & V_2 -> V_6 , F_5 ) ;
V_2 -> V_6 . V_22 = V_23 ;
V_19 = F_29 ( & V_2 -> V_6 , V_8 , V_7 , NULL , 0 ) ;
if ( V_19 < 0 ) {
F_1 ( V_2 ) ;
return F_26 ( V_19 ) ;
}
return V_2 ;
}
static struct V_9 * F_30 ( char * V_13 )
{
struct V_9 * V_10 ;
V_10 = F_24 ( sizeof( * V_10 ) , V_20 ) ;
if ( F_25 ( ! V_10 ) )
return F_26 ( - V_21 ) ;
F_27 ( & V_10 -> V_12 ) ;
F_31 ( & V_10 -> V_11 , 1 ) ;
V_10 -> V_13 = V_13 ;
V_10 -> V_16 = V_24 ;
V_10 -> V_15 = V_17 ;
return V_10 ;
}
int F_32 ( struct V_25 * V_26 , char * V_13 , int V_27 , T_2 V_28 )
{
struct V_9 * V_10 ;
if ( ! V_8 )
return - V_29 ;
if ( V_13 [ 0 ] != '/' || V_13 [ V_27 - 1 ] == '/' ||
V_26 -> V_30 != V_31 ||
V_28 != V_32 ||
V_26 -> V_33 || V_26 -> V_10 || V_26 -> V_34 )
return - V_35 ;
V_10 = F_30 ( V_13 ) ;
if ( F_33 ( V_10 ) )
return F_34 ( V_10 ) ;
V_26 -> V_10 = V_10 ;
return 0 ;
}
static struct V_9 * F_35 ( struct V_9 * V_36 )
{
char * V_13 ;
struct V_9 * V_37 ;
V_13 = F_36 ( V_36 -> V_13 , V_20 ) ;
if ( F_25 ( ! V_13 ) )
return F_26 ( - V_21 ) ;
V_37 = F_30 ( V_13 ) ;
if ( F_33 ( V_37 ) ) {
F_4 ( V_13 ) ;
goto V_38;
}
V_37 -> V_16 = V_36 -> V_16 ;
V_37 -> V_15 = V_36 -> V_15 ;
F_7 ( V_36 -> V_2 ) ;
V_37 -> V_2 = V_36 -> V_2 ;
V_38:
return V_37 ;
}
static void F_37 ( struct V_25 * V_39 , struct V_9 * V_40 , char * V_28 )
{
if ( V_41 ) {
struct V_42 * V_43 ;
V_43 = F_38 ( NULL , V_44 , V_45 ) ;
if ( F_25 ( ! V_43 ) )
return;
F_39 ( V_43 , L_1 ,
F_40 ( & V_46 , F_41 ( V_47 ) ) ,
F_42 ( V_47 ) ) ;
F_43 ( V_43 , V_28 ) ;
F_39 ( V_43 , L_2 ) ;
F_44 ( V_43 , V_40 -> V_13 ) ;
F_45 ( V_43 , V_39 -> V_48 ) ;
F_39 ( V_43 , L_3 , V_39 -> V_30 ) ;
F_46 ( V_43 ) ;
}
}
static void F_47 ( struct V_1 * V_2 ,
const char * V_49 , T_1 V_16 ,
unsigned long V_15 , unsigned V_50 )
{
struct V_9 * V_51 , * V_52 , * V_53 ;
struct V_25 * V_39 , * V_54 ;
struct V_55 * V_56 , * V_57 ;
F_48 ( & V_58 ) ;
F_49 (owatch, nextw, &parent->watches, wlist) {
if ( F_50 ( V_49 , V_51 -> V_13 ,
V_59 ) )
continue;
if ( V_50 && ! F_51 () )
F_52 ( V_47 , V_47 -> V_60 ) ;
V_52 = F_35 ( V_51 ) ;
if ( F_33 ( V_52 ) ) {
F_53 ( & V_58 ) ;
F_54 ( L_4 ) ;
return;
}
V_52 -> V_16 = V_16 ;
V_52 -> V_15 = V_15 ;
F_49 (r, nextr, &owatch->rules, rlist) {
V_56 = F_6 ( V_39 , struct V_55 , V_61 ) ;
F_19 ( & V_56 -> V_61 . V_62 ) ;
F_55 ( & V_56 -> V_63 ) ;
V_57 = F_56 ( & V_56 -> V_61 ) ;
if ( F_33 ( V_57 ) ) {
F_19 ( & V_56 -> V_61 . V_63 ) ;
F_54 ( L_5 ) ;
} else {
int V_64 = F_57 ( ( T_2 ) V_15 ) ;
F_16 ( V_57 -> V_61 . V_10 ) ;
F_14 ( V_52 ) ;
V_57 -> V_61 . V_10 = V_52 ;
F_58 ( & V_57 -> V_61 . V_62 , & V_52 -> V_12 ) ;
F_59 ( & V_57 -> V_63 , & V_65 [ V_64 ] ) ;
F_60 ( & V_56 -> V_61 . V_63 ,
& V_57 -> V_61 . V_63 ) ;
}
if ( V_56 -> V_61 . V_66 )
F_61 ( V_56 -> V_61 . V_66 ) ;
F_37 ( V_39 , V_51 , L_6 ) ;
F_62 ( & V_56 -> V_67 , V_68 ) ;
}
F_18 ( V_51 ) ;
goto V_69;
}
F_53 ( & V_58 ) ;
return;
V_69:
F_58 ( & V_52 -> V_14 , & V_2 -> V_3 ) ;
F_53 ( & V_58 ) ;
return;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_9 * V_40 , * V_53 ;
struct V_25 * V_39 , * V_54 ;
struct V_55 * V_70 ;
F_48 ( & V_58 ) ;
F_49 (w, nextw, &parent->watches, wlist) {
F_49 (r, nextr, &w->rules, rlist) {
V_70 = F_6 ( V_39 , struct V_55 , V_61 ) ;
F_37 ( V_39 , V_40 , L_7 ) ;
if ( V_70 -> V_61 . V_66 )
F_61 ( V_70 -> V_61 . V_66 ) ;
F_19 ( & V_39 -> V_62 ) ;
F_19 ( & V_39 -> V_63 ) ;
F_55 ( & V_70 -> V_63 ) ;
F_62 ( & V_70 -> V_67 , V_68 ) ;
}
F_18 ( V_40 ) ;
}
F_53 ( & V_58 ) ;
F_64 ( & V_2 -> V_6 , V_8 ) ;
}
static int F_65 ( struct V_9 * V_10 , struct V_13 * V_2 )
{
struct V_18 * V_71 = F_66 ( V_10 -> V_13 , V_2 ) ;
if ( F_33 ( V_71 ) )
return F_34 ( V_71 ) ;
F_67 ( F_23 ( V_2 -> V_18 ) ) ;
if ( F_68 ( V_71 ) ) {
V_10 -> V_16 = V_71 -> V_72 -> V_73 ;
V_10 -> V_15 = F_23 ( V_71 ) -> V_74 ;
}
F_69 ( V_71 ) ;
return 0 ;
}
static void F_70 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_9 * V_40 , * V_10 = V_26 -> V_10 ;
int V_75 = 0 ;
F_71 ( ! F_72 ( & V_58 ) ) ;
F_73 (w, &parent->watches, wlist) {
if ( strcmp ( V_10 -> V_13 , V_40 -> V_13 ) )
continue;
V_75 = 1 ;
F_16 ( V_10 ) ;
F_14 ( V_40 ) ;
V_26 -> V_10 = V_10 = V_40 ;
F_10 ( V_2 ) ;
break;
}
if ( ! V_75 ) {
V_10 -> V_2 = V_2 ;
F_14 ( V_10 ) ;
F_58 ( & V_10 -> V_14 , & V_2 -> V_3 ) ;
}
F_58 ( & V_26 -> V_62 , & V_10 -> V_12 ) ;
}
int F_74 ( struct V_25 * V_26 , struct V_76 * * V_63 )
{
struct V_9 * V_10 = V_26 -> V_10 ;
struct V_1 * V_2 ;
struct V_13 V_77 ;
int V_64 , V_19 = 0 ;
F_53 ( & V_58 ) ;
V_19 = F_65 ( V_10 , & V_77 ) ;
F_48 ( & V_58 ) ;
if ( V_19 )
return V_19 ;
V_2 = F_12 ( F_23 ( V_77 . V_18 ) ) ;
if ( ! V_2 ) {
V_2 = F_22 ( & V_77 ) ;
if ( F_33 ( V_2 ) ) {
V_19 = F_34 ( V_2 ) ;
goto error;
}
}
F_70 ( V_26 , V_2 ) ;
V_64 = F_57 ( ( T_2 ) V_10 -> V_15 ) ;
* V_63 = & V_65 [ V_64 ] ;
error:
F_75 ( & V_77 ) ;
return V_19 ;
}
void F_76 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = V_26 -> V_10 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_19 ( & V_26 -> V_62 ) ;
if ( F_3 ( & V_10 -> V_12 ) ) {
F_18 ( V_10 ) ;
if ( F_3 ( & V_2 -> V_3 ) ) {
F_7 ( V_2 ) ;
F_64 ( & V_2 -> V_6 , V_8 ) ;
F_10 ( V_2 ) ;
}
}
}
static int F_77 ( struct V_78 * V_79 ,
struct V_7 * V_80 ,
struct V_4 * V_81 ,
struct V_4 * V_82 ,
T_2 V_22 , void * V_83 , int V_84 ,
const unsigned char * V_49 , T_2 V_85 )
{
struct V_7 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_81 , struct V_1 , V_6 ) ;
F_71 ( V_79 != V_8 ) ;
switch ( V_84 ) {
case ( V_86 ) :
V_7 = F_23 ( ( (struct V_13 * ) V_83 ) -> V_18 ) ;
break;
case ( V_87 ) :
V_7 = (struct V_7 * ) V_83 ;
break;
default:
F_78 () ;
V_7 = NULL ;
break;
} ;
if ( V_22 & ( V_88 | V_89 ) && V_7 )
F_47 ( V_2 , V_49 , V_7 -> V_90 -> V_73 , V_7 -> V_74 , 0 ) ;
else if ( V_22 & ( V_91 | V_92 ) )
F_47 ( V_2 , V_49 , V_24 , V_17 , 1 ) ;
else if ( V_22 & ( V_93 | V_94 | V_95 ) )
F_63 ( V_2 ) ;
return 0 ;
}
static int T_3 F_79 ( void )
{
V_8 = F_80 ( & V_96 ) ;
if ( F_33 ( V_8 ) ) {
V_8 = NULL ;
F_54 ( L_8 ) ;
}
return 0 ;
}
int F_81 ( struct V_25 * V_37 , struct V_25 * V_36 )
{
struct V_97 * V_98 ;
char * V_99 ;
V_99 = F_36 ( F_82 ( V_36 -> V_66 ) , V_20 ) ;
if ( ! V_99 )
return - V_21 ;
V_98 = F_83 ( V_37 , V_99 , strlen ( V_99 ) ) ;
if ( F_33 ( V_98 ) ) {
F_4 ( V_99 ) ;
return F_34 ( V_98 ) ;
}
V_37 -> V_66 = V_98 ;
return 0 ;
}
int F_84 ( struct V_100 * V_101 , struct V_97 * V_6 )
{
struct V_102 * V_103 ;
unsigned long V_15 ;
T_1 V_16 ;
F_85 () ;
V_103 = F_86 ( V_101 -> V_104 -> V_103 ) ;
V_15 = V_103 -> V_105 -> V_74 ;
V_16 = V_103 -> V_105 -> V_90 -> V_73 ;
F_87 () ;
return F_88 ( V_6 , V_15 , V_16 ) ;
}
