static void * F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 ,
T_3 V_5 ,
unsigned long V_6 )
{
void * V_7 ;
V_7 = F_2 ( V_3 , V_5 ) ;
* V_4 = ( T_2 ) V_7 ;
return V_7 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_8 ,
T_2 V_4 ,
unsigned long V_6 )
{
F_4 ( V_8 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
unsigned long V_10 ,
T_1 V_3 ,
enum V_11 V_12 ,
unsigned long V_6 )
{
return ( T_2 ) ( F_6 ( V_9 ) + V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_13 ,
T_1 V_3 ,
enum V_11 V_12 ,
unsigned long V_6 )
{
return;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
int V_16 , enum V_11 V_12 ,
unsigned long V_6 )
{
struct V_14 * V_17 ;
int V_18 ;
F_9 (sgl, sg, nents, i) {
V_17 -> V_19 = ( T_2 ) F_10 ( V_17 ) ;
V_17 -> V_20 = V_17 -> V_21 ;
}
return V_16 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_14 * V_17 ,
int V_16 , enum V_11 V_12 ,
unsigned long V_6 )
{
return;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_22 )
{
return V_22 == F_13 ( 64 ) ;
}
static T_4 F_14 ( struct V_1 * V_2 )
{
return F_13 ( 64 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_23 )
{
struct V_24 * V_25 = F_16 ( V_2 ) -> V_2 . V_26 ;
return ( V_25 -> V_27 &&
( strcasecmp ( ( char * ) V_23 , V_25 -> V_27 ) == 0 ) ) ;
}
static int F_17 ( struct V_1 * V_2 , void * V_23 )
{
return F_16 ( V_2 ) -> V_2 . V_26 == V_23 ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_28 * V_2 ;
int V_29 ;
V_2 = F_19 ( V_25 , NULL , & V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_2 . V_32 = & V_33 ;
V_2 -> V_2 . V_34 . V_35 = & V_36 ;
V_29 = F_20 ( V_2 ) ;
if ( V_29 )
F_21 ( V_2 ) ;
return V_29 ;
}
static int F_22 ( const struct V_37 * V_38 )
{
struct V_24 * V_39 , * V_40 ;
int V_29 = 0 ;
V_39 = F_23 ( L_1 ) ;
F_24 (root, child) {
if ( ! F_25 ( V_38 , V_40 ) )
continue;
if ( F_26 ( & V_33 , NULL , V_40 ,
F_17 ) )
continue;
V_29 = F_18 ( V_40 ) ;
if ( V_29 ) {
F_27 ( V_41 L_2 ,
V_42 , V_29 ) ;
F_28 ( V_40 ) ;
break;
}
}
F_28 ( V_39 ) ;
return V_29 ;
}
int F_29 ( struct V_43 * V_44 )
{
F_22 ( V_44 -> V_45 . V_46 ) ;
V_44 -> V_45 . V_32 = & V_33 ;
return F_30 ( & V_44 -> V_45 ) ;
}
void F_31 ( struct V_43 * V_44 )
{
F_32 ( & V_44 -> V_45 ) ;
}
int F_33 ( T_5 V_47 , T_6 V_48 ,
unsigned long V_49 , const char * V_50 ,
void * V_51 )
{
unsigned int V_52 = F_34 ( NULL , V_47 ) ;
if ( ! V_52 )
return - V_53 ;
return F_35 ( V_52 , V_48 , V_49 , V_50 , V_51 ) ;
}
void F_36 ( T_5 V_47 , void * V_51 )
{
unsigned int V_52 = F_37 ( NULL , V_47 ) ;
F_38 ( V_52 , V_51 ) ;
F_39 ( V_52 ) ;
}
static char * F_40 ( const char * V_54 , T_1 V_55 )
{
char * V_56 = F_2 ( V_55 + 1 , V_57 ) ;
if ( ! V_56 )
return NULL ;
memcpy ( V_56 , V_54 , V_55 ) ;
V_56 [ V_55 ] = '\0' ;
if ( V_56 [ V_55 - 1 ] == '\n' )
V_56 [ V_55 - 1 ] = '\0' ;
return V_56 ;
}
static T_7 F_41 ( struct V_58 * V_32 ,
const char * V_59 , T_1 V_55 )
{
struct V_24 * V_25 = NULL ;
char * V_60 ;
T_7 V_61 = 0 ;
V_60 = F_40 ( V_59 , V_55 ) ;
if ( ! V_60 )
return - V_31 ;
if ( F_26 ( & V_33 , NULL , V_60 ,
F_15 ) ) {
F_27 ( V_62 L_3 ,
V_42 , V_60 ) ;
V_61 = - V_63 ;
goto V_56;
}
if ( ( V_25 = F_23 ( V_60 ) ) ) {
V_61 = F_18 ( V_25 ) ;
F_28 ( V_25 ) ;
} else {
F_27 ( V_62 L_4 ,
V_42 , V_60 ) ;
V_61 = - V_64 ;
}
V_56:
F_4 ( V_60 ) ;
if ( V_61 )
return V_61 ;
return V_55 ;
}
static T_7 F_42 ( struct V_58 * V_32 ,
const char * V_59 , T_1 V_55 )
{
struct V_1 * V_2 ;
char * V_60 ;
V_60 = F_40 ( V_59 , V_55 ) ;
if ( ! V_60 )
return - V_31 ;
if ( ( V_2 = F_26 ( & V_33 , NULL , V_60 ,
F_15 ) ) ) {
F_43 ( F_16 ( V_2 ) ) ;
F_4 ( V_60 ) ;
return V_55 ;
} else {
F_27 ( V_62 L_5 ,
V_42 , V_60 ) ;
F_4 ( V_60 ) ;
return - V_64 ;
}
}
static int F_44 ( struct V_1 * V_2 , struct V_65 * V_44 )
{
const struct V_37 * V_38 = V_44 -> V_46 ;
if ( ! V_38 )
return 0 ;
return F_45 ( V_38 , V_2 ) != NULL ;
}
static int F_46 ( struct V_1 * V_2 )
{
int error = - V_64 ;
struct V_43 * V_44 ;
struct V_28 * V_66 ;
V_44 = F_47 ( V_2 -> V_45 ) ;
V_66 = F_16 ( V_2 ) ;
if ( ! V_44 -> V_67 )
return error ;
F_48 ( V_66 ) ;
if ( F_49 ( V_2 , V_2 -> V_45 ) )
error = V_44 -> V_67 ( V_66 ) ;
if ( error )
F_50 ( V_66 ) ;
return error ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_28 * V_66 = F_16 ( V_2 ) ;
struct V_43 * V_44 = F_47 ( V_2 -> V_45 ) ;
if ( V_2 -> V_45 && V_44 -> remove )
V_44 -> remove ( V_66 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_28 * V_66 = F_16 ( V_2 ) ;
struct V_43 * V_44 = F_47 ( V_2 -> V_45 ) ;
if ( V_2 -> V_45 && V_44 -> V_68 )
V_44 -> V_68 ( V_66 ) ;
}
static T_7 F_53 ( struct V_1 * V_2 ,
struct V_69 * V_70 , char * V_59 )
{
struct V_28 * V_71 ;
V_71 = F_16 ( V_2 ) ;
return sprintf ( V_59 , L_6 , V_71 -> V_2 . V_26 -> V_27 ) ;
}
static T_7 F_54 ( struct V_1 * V_2 ,
struct V_69 * V_70 , char * V_59 )
{
struct V_28 * V_71 ;
V_71 = F_16 ( V_2 ) ;
return sprintf ( V_59 , L_6 , V_71 -> V_2 . V_26 -> V_72 ) ;
}
static T_7 F_55 ( struct V_1 * V_2 ,
struct V_69 * V_70 , char * V_59 )
{
T_7 V_73 = F_56 ( V_2 , V_59 , V_74 - 2 ) ;
V_59 [ V_73 ] = '\n' ;
V_59 [ V_73 + 1 ] = 0 ;
return V_73 + 1 ;
}
static int F_57 ( struct V_1 * V_2 , T_8 V_75 )
{
struct V_28 * V_66 = F_16 ( V_2 ) ;
struct V_43 * V_44 = F_47 ( V_2 -> V_45 ) ;
int V_29 = 0 ;
if ( V_2 -> V_45 && V_44 -> V_76 )
V_29 = V_44 -> V_76 ( V_66 , V_75 ) ;
return V_29 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_28 * V_66 = F_16 ( V_2 ) ;
struct V_43 * V_44 = F_47 ( V_2 -> V_45 ) ;
int V_29 = 0 ;
if ( V_2 -> V_45 && V_44 -> V_77 )
V_29 = V_44 -> V_77 ( V_66 ) ;
return V_29 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( V_44 && V_44 -> V_78 && V_44 -> V_78 -> V_79 )
V_29 = V_44 -> V_78 -> V_79 ( V_2 ) ;
return V_29 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
if ( V_44 && V_44 -> V_78 && V_44 -> V_78 -> V_80 )
V_44 -> V_78 -> V_80 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_76 )
V_29 = V_44 -> V_78 -> V_76 ( V_2 ) ;
} else {
V_29 = F_57 ( V_2 , V_81 ) ;
}
return V_29 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_82 )
V_29 = V_44 -> V_78 -> V_82 ( V_2 ) ;
}
return V_29 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_77 )
V_29 = V_44 -> V_78 -> V_77 ( V_2 ) ;
} else {
V_29 = F_58 ( V_2 ) ;
}
return V_29 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_83 )
V_29 = V_44 -> V_78 -> V_83 ( V_2 ) ;
}
return V_29 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_84 )
V_29 = V_44 -> V_78 -> V_84 ( V_2 ) ;
} else {
V_29 = F_57 ( V_2 , V_85 ) ;
}
return V_29 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_86 )
V_29 = V_44 -> V_78 -> V_86 ( V_2 ) ;
}
return V_29 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_87 )
V_29 = V_44 -> V_78 -> V_87 ( V_2 ) ;
} else {
V_29 = F_58 ( V_2 ) ;
}
return V_29 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_88 )
V_29 = V_44 -> V_78 -> V_88 ( V_2 ) ;
}
return V_29 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_89 )
V_29 = V_44 -> V_78 -> V_89 ( V_2 ) ;
} else {
V_29 = F_57 ( V_2 , V_90 ) ;
}
return V_29 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_91 )
V_29 = V_44 -> V_78 -> V_91 ( V_2 ) ;
}
return V_29 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_92 )
V_29 = V_44 -> V_78 -> V_92 ( V_2 ) ;
} else {
V_29 = F_58 ( V_2 ) ;
}
return V_29 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_65 * V_44 = V_2 -> V_45 ;
int V_29 = 0 ;
if ( ! V_44 )
return 0 ;
if ( V_44 -> V_78 ) {
if ( V_44 -> V_78 -> V_93 )
V_29 = V_44 -> V_78 -> V_93 ( V_2 ) ;
}
return V_29 ;
}
static int T_9 F_73 ( void )
{
int V_94 ;
F_27 ( V_95 L_7 ) ;
V_94 = F_74 ( & V_33 ) ;
if ( V_94 ) {
F_27 ( V_41 L_8 ,
V_42 ) ;
return V_94 ;
}
V_94 = F_75 ( & V_30 ) ;
if ( V_94 ) {
F_27 ( V_62 L_9 ,
V_42 , V_94 ) ;
F_76 ( & V_33 ) ;
return V_94 ;
}
V_94 = F_22 ( V_96 ) ;
if ( V_94 ) {
F_77 ( & V_30 ) ;
F_76 ( & V_33 ) ;
return V_94 ;
}
return 0 ;
}
