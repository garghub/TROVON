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
V_5 = F_13 ( & V_7 -> V_8 , V_9 ) ;
if ( V_5 )
V_2 = F_6 ( V_5 , struct V_1 , V_6 ) ;
return V_2 ;
}
void F_14 ( struct V_10 * V_11 )
{
F_15 ( & V_11 -> V_12 ) ;
}
void F_16 ( struct V_10 * V_11 )
{
if ( F_17 ( & V_11 -> V_12 ) ) {
F_2 ( V_11 -> V_2 ) ;
F_2 ( ! F_3 ( & V_11 -> V_13 ) ) ;
F_4 ( V_11 -> V_14 ) ;
F_4 ( V_11 ) ;
}
}
static void F_18 ( struct V_10 * V_11 )
{
F_19 ( & V_11 -> V_15 ) ;
F_10 ( V_11 -> V_2 ) ;
V_11 -> V_2 = NULL ;
F_16 ( V_11 ) ;
}
char * F_20 ( struct V_10 * V_11 )
{
return V_11 -> V_14 ;
}
int F_21 ( struct V_10 * V_11 , unsigned long V_16 , T_1 V_17 )
{
return ( V_11 -> V_16 != V_18 ) &&
( V_11 -> V_16 == V_16 ) &&
( V_11 -> V_17 == V_17 ) ;
}
static struct V_1 * F_22 ( struct V_14 * V_14 )
{
struct V_7 * V_7 = F_23 ( V_14 -> V_19 ) ;
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_21 ) ;
if ( F_25 ( ! V_2 ) )
return F_26 ( - V_22 ) ;
F_27 ( & V_2 -> V_3 ) ;
F_28 ( & V_2 -> V_6 , V_9 ) ;
V_2 -> V_6 . V_23 = V_24 ;
V_20 = F_29 ( & V_2 -> V_6 , V_7 , NULL , 0 ) ;
if ( V_20 < 0 ) {
F_1 ( V_2 ) ;
return F_26 ( V_20 ) ;
}
return V_2 ;
}
static struct V_10 * F_30 ( char * V_14 )
{
struct V_10 * V_11 ;
V_11 = F_24 ( sizeof( * V_11 ) , V_21 ) ;
if ( F_25 ( ! V_11 ) )
return F_26 ( - V_22 ) ;
F_27 ( & V_11 -> V_13 ) ;
F_31 ( & V_11 -> V_12 , 1 ) ;
V_11 -> V_14 = V_14 ;
V_11 -> V_17 = V_25 ;
V_11 -> V_16 = V_18 ;
return V_11 ;
}
int F_32 ( struct V_26 * V_27 , char * V_14 , int V_28 , T_2 V_29 )
{
struct V_10 * V_11 ;
if ( ! V_9 )
return - V_30 ;
if ( V_14 [ 0 ] != '/' || V_14 [ V_28 - 1 ] == '/' ||
V_27 -> V_31 != V_32 ||
V_29 != V_33 ||
V_27 -> V_34 || V_27 -> V_11 || V_27 -> V_35 )
return - V_36 ;
V_11 = F_30 ( V_14 ) ;
if ( F_33 ( V_11 ) )
return F_34 ( V_11 ) ;
V_27 -> V_11 = V_11 ;
return 0 ;
}
static struct V_10 * F_35 ( struct V_10 * V_37 )
{
char * V_14 ;
struct V_10 * V_38 ;
V_14 = F_36 ( V_37 -> V_14 , V_21 ) ;
if ( F_25 ( ! V_14 ) )
return F_26 ( - V_22 ) ;
V_38 = F_30 ( V_14 ) ;
if ( F_33 ( V_38 ) ) {
F_4 ( V_14 ) ;
goto V_39;
}
V_38 -> V_17 = V_37 -> V_17 ;
V_38 -> V_16 = V_37 -> V_16 ;
F_7 ( V_37 -> V_2 ) ;
V_38 -> V_2 = V_37 -> V_2 ;
V_39:
return V_38 ;
}
static void F_37 ( struct V_26 * V_40 , struct V_10 * V_41 , char * V_29 )
{
if ( V_42 ) {
struct V_43 * V_44 ;
V_44 = F_38 ( NULL , V_45 , V_46 ) ;
if ( F_25 ( ! V_44 ) )
return;
F_39 ( V_44 , L_1 ,
F_40 ( & V_47 , F_41 ( V_48 ) ) ,
F_42 ( V_48 ) , V_29 ) ;
F_39 ( V_44 , L_2 ) ;
F_43 ( V_44 , V_41 -> V_14 ) ;
F_44 ( V_44 , V_40 -> V_49 ) ;
F_39 ( V_44 , L_3 , V_40 -> V_31 ) ;
F_45 ( V_44 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
const char * V_50 , T_1 V_17 ,
unsigned long V_16 , unsigned V_51 )
{
struct V_10 * V_52 , * V_53 , * V_54 ;
struct V_26 * V_40 , * V_55 ;
struct V_56 * V_57 , * V_58 ;
F_47 ( & V_59 ) ;
F_48 (owatch, nextw, &parent->watches, wlist) {
if ( F_49 ( V_50 , V_52 -> V_14 ,
V_60 ) )
continue;
if ( V_51 && ! F_50 () )
F_51 ( V_48 , V_48 -> V_61 ) ;
V_53 = F_35 ( V_52 ) ;
if ( F_33 ( V_53 ) ) {
F_52 ( & V_59 ) ;
F_53 ( L_4 ) ;
return;
}
V_53 -> V_17 = V_17 ;
V_53 -> V_16 = V_16 ;
F_48 (r, nextr, &owatch->rules, rlist) {
V_57 = F_6 ( V_40 , struct V_56 , V_62 ) ;
F_19 ( & V_57 -> V_62 . V_63 ) ;
F_54 ( & V_57 -> V_64 ) ;
V_58 = F_55 ( & V_57 -> V_62 ) ;
if ( F_33 ( V_58 ) ) {
F_19 ( & V_57 -> V_62 . V_64 ) ;
F_53 ( L_5 ) ;
} else {
int V_65 = F_56 ( ( T_2 ) V_16 ) ;
F_16 ( V_58 -> V_62 . V_11 ) ;
F_14 ( V_53 ) ;
V_58 -> V_62 . V_11 = V_53 ;
F_57 ( & V_58 -> V_62 . V_63 , & V_53 -> V_13 ) ;
F_58 ( & V_58 -> V_64 , & V_66 [ V_65 ] ) ;
F_59 ( & V_57 -> V_62 . V_64 ,
& V_58 -> V_62 . V_64 ) ;
}
if ( V_57 -> V_62 . V_67 )
F_60 ( V_57 -> V_62 . V_67 ) ;
F_37 ( V_40 , V_52 , L_6 ) ;
F_61 ( & V_57 -> V_68 , V_69 ) ;
}
F_18 ( V_52 ) ;
goto V_70;
}
F_52 ( & V_59 ) ;
return;
V_70:
F_57 ( & V_53 -> V_15 , & V_2 -> V_3 ) ;
F_52 ( & V_59 ) ;
return;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_41 , * V_54 ;
struct V_26 * V_40 , * V_55 ;
struct V_56 * V_71 ;
F_47 ( & V_59 ) ;
F_48 (w, nextw, &parent->watches, wlist) {
F_48 (r, nextr, &w->rules, rlist) {
V_71 = F_6 ( V_40 , struct V_56 , V_62 ) ;
F_37 ( V_40 , V_41 , L_7 ) ;
if ( V_71 -> V_62 . V_67 )
F_60 ( V_71 -> V_62 . V_67 ) ;
F_19 ( & V_40 -> V_63 ) ;
F_19 ( & V_40 -> V_64 ) ;
F_54 ( & V_71 -> V_64 ) ;
F_61 ( & V_71 -> V_68 , V_69 ) ;
}
F_18 ( V_41 ) ;
}
F_52 ( & V_59 ) ;
F_63 ( & V_2 -> V_6 , V_9 ) ;
}
static int F_64 ( struct V_10 * V_11 , struct V_14 * V_2 )
{
struct V_19 * V_72 = F_65 ( V_11 -> V_14 , V_2 ) ;
if ( F_33 ( V_72 ) )
return F_34 ( V_72 ) ;
F_66 ( F_23 ( V_2 -> V_19 ) ) ;
if ( F_67 ( V_72 ) ) {
V_11 -> V_17 = V_72 -> V_73 -> V_74 ;
V_11 -> V_16 = F_23 ( V_72 ) -> V_75 ;
}
F_68 ( V_72 ) ;
return 0 ;
}
static void F_69 ( struct V_26 * V_27 ,
struct V_1 * V_2 )
{
struct V_10 * V_41 , * V_11 = V_27 -> V_11 ;
int V_76 = 0 ;
F_70 ( ! F_71 ( & V_59 ) ) ;
F_72 (w, &parent->watches, wlist) {
if ( strcmp ( V_11 -> V_14 , V_41 -> V_14 ) )
continue;
V_76 = 1 ;
F_16 ( V_11 ) ;
F_14 ( V_41 ) ;
V_27 -> V_11 = V_11 = V_41 ;
F_10 ( V_2 ) ;
break;
}
if ( ! V_76 ) {
V_11 -> V_2 = V_2 ;
F_14 ( V_11 ) ;
F_57 ( & V_11 -> V_15 , & V_2 -> V_3 ) ;
}
F_57 ( & V_27 -> V_63 , & V_11 -> V_13 ) ;
}
int F_73 ( struct V_26 * V_27 , struct V_77 * * V_64 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
struct V_1 * V_2 ;
struct V_14 V_78 ;
int V_65 , V_20 = 0 ;
F_52 ( & V_59 ) ;
V_20 = F_64 ( V_11 , & V_78 ) ;
F_47 ( & V_59 ) ;
if ( V_20 )
return V_20 ;
V_2 = F_12 ( F_23 ( V_78 . V_19 ) ) ;
if ( ! V_2 ) {
V_2 = F_22 ( & V_78 ) ;
if ( F_33 ( V_2 ) ) {
V_20 = F_34 ( V_2 ) ;
goto error;
}
}
F_69 ( V_27 , V_2 ) ;
V_65 = F_56 ( ( T_2 ) V_11 -> V_16 ) ;
* V_64 = & V_66 [ V_65 ] ;
error:
F_74 ( & V_78 ) ;
return V_20 ;
}
void F_75 ( struct V_26 * V_27 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_19 ( & V_27 -> V_63 ) ;
if ( F_3 ( & V_11 -> V_13 ) ) {
F_7 ( V_2 ) ;
F_18 ( V_11 ) ;
if ( F_3 ( & V_2 -> V_3 ) )
F_63 ( & V_2 -> V_6 , V_9 ) ;
F_10 ( V_2 ) ;
}
}
static int F_76 ( struct V_79 * V_80 ,
struct V_7 * V_81 ,
struct V_4 * V_82 ,
struct V_4 * V_83 ,
T_2 V_23 , const void * V_84 , int V_85 ,
const unsigned char * V_50 , T_2 V_86 ,
struct V_87 * V_88 )
{
const struct V_7 * V_7 ;
struct V_1 * V_2 ;
V_2 = F_6 ( V_82 , struct V_1 , V_6 ) ;
F_70 ( V_80 != V_9 ) ;
switch ( V_85 ) {
case ( V_89 ) :
V_7 = F_23 ( ( ( const struct V_14 * ) V_84 ) -> V_19 ) ;
break;
case ( V_90 ) :
V_7 = ( const struct V_7 * ) V_84 ;
break;
default:
F_77 () ;
V_7 = NULL ;
break;
}
if ( V_23 & ( V_91 | V_92 ) && V_7 )
F_46 ( V_2 , V_50 , V_7 -> V_93 -> V_74 , V_7 -> V_75 , 0 ) ;
else if ( V_23 & ( V_94 | V_95 ) )
F_46 ( V_2 , V_50 , V_25 , V_18 , 1 ) ;
else if ( V_23 & ( V_96 | V_97 | V_98 ) )
F_62 ( V_2 ) ;
return 0 ;
}
static int T_3 F_78 ( void )
{
V_9 = F_79 ( & V_99 ) ;
if ( F_33 ( V_9 ) ) {
V_9 = NULL ;
F_53 ( L_8 ) ;
}
return 0 ;
}
int F_80 ( struct V_26 * V_38 , struct V_26 * V_37 )
{
struct V_100 * V_101 ;
char * V_102 ;
V_102 = F_36 ( F_81 ( V_37 -> V_67 ) , V_21 ) ;
if ( ! V_102 )
return - V_22 ;
V_101 = F_82 ( V_38 , V_102 , strlen ( V_102 ) ) ;
if ( F_33 ( V_101 ) ) {
F_4 ( V_102 ) ;
return F_34 ( V_101 ) ;
}
V_38 -> V_67 = V_101 ;
return 0 ;
}
int F_83 ( struct V_103 * V_104 , struct V_100 * V_6 )
{
struct V_105 * V_106 ;
unsigned long V_16 ;
T_1 V_17 ;
V_106 = F_84 ( V_104 ) ;
if ( ! V_106 )
return 0 ;
V_16 = F_85 ( V_106 ) -> V_75 ;
V_17 = F_85 ( V_106 ) -> V_93 -> V_74 ;
F_86 ( V_106 ) ;
return F_87 ( V_6 , V_16 , V_17 ) ;
}
