static void * F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 ,
T_3 V_5 )
{
void * V_6 ;
V_6 = F_2 ( V_3 , V_5 ) ;
* V_4 = ( T_2 ) V_6 ;
return V_6 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_7 ,
T_2 V_4 )
{
F_4 ( V_7 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 ,
struct V_8 * V_8 ,
unsigned long V_9 ,
T_1 V_3 ,
enum V_10 V_11 ,
struct V_12 * V_13 )
{
return ( T_2 ) ( F_6 ( V_8 ) + V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_14 ,
T_1 V_3 ,
enum V_10 V_11 ,
struct V_12 * V_13 )
{
return;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_17 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
struct V_15 * V_18 ;
int V_19 ;
F_9 (sgl, sg, nents, i) {
V_18 -> V_20 = ( T_2 ) F_10 ( V_18 ) ;
V_18 -> V_21 = V_18 -> V_22 ;
}
return V_17 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_15 * V_18 ,
int V_17 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
return;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_23 )
{
return 1 ;
}
static int F_13 ( struct V_1 * V_2 , void * V_24 )
{
struct V_25 * V_26 = F_14 ( V_2 ) -> V_2 . V_27 ;
return ( V_26 -> V_28 &&
( strcasecmp ( ( char * ) V_24 , V_26 -> V_28 ) == 0 ) ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_24 )
{
return F_14 ( V_2 ) -> V_2 . V_27 == V_24 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_29 * V_2 ;
int V_30 ;
V_2 = F_17 ( V_26 , NULL , & V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_2 . V_33 = & V_34 ;
V_2 -> V_2 . V_35 . V_36 = & V_37 ;
V_30 = F_18 ( V_2 ) ;
if ( V_30 )
F_19 ( V_2 ) ;
return V_30 ;
}
static int F_20 ( const struct V_38 * V_39 )
{
struct V_25 * V_40 , * V_41 ;
int V_30 = 0 ;
V_40 = F_21 ( L_1 ) ;
F_22 (root, child) {
if ( ! F_23 ( V_39 , V_41 ) )
continue;
if ( F_24 ( & V_34 , NULL , V_41 ,
F_15 ) )
continue;
V_30 = F_16 ( V_41 ) ;
if ( V_30 ) {
F_25 ( V_42 L_2 ,
V_43 , V_30 ) ;
F_26 ( V_41 ) ;
break;
}
}
F_26 ( V_40 ) ;
return V_30 ;
}
int F_27 ( struct V_44 * V_45 )
{
F_20 ( V_45 -> V_46 . V_47 ) ;
V_45 -> V_46 . V_33 = & V_34 ;
return F_28 ( & V_45 -> V_46 ) ;
}
void F_29 ( struct V_44 * V_45 )
{
F_30 ( & V_45 -> V_46 ) ;
}
int F_31 ( T_5 V_48 , T_6 V_49 ,
unsigned long V_50 , const char * V_51 ,
void * V_52 )
{
unsigned int V_53 = F_32 ( NULL , V_48 ) ;
if ( V_53 == V_54 )
return - V_55 ;
return F_33 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
}
void F_34 ( T_5 V_48 , void * V_52 )
{
unsigned int V_53 = F_35 ( NULL , V_48 ) ;
F_36 ( V_53 , V_52 ) ;
F_37 ( V_53 ) ;
}
static char * F_38 ( const char * V_56 , T_1 V_57 )
{
char * V_58 = F_2 ( V_57 + 1 , V_59 ) ;
if ( ! V_58 )
return NULL ;
memcpy ( V_58 , V_56 , V_57 ) ;
V_58 [ V_57 ] = '\0' ;
if ( V_58 [ V_57 - 1 ] == '\n' )
V_58 [ V_57 - 1 ] = '\0' ;
return V_58 ;
}
static T_7 F_39 ( struct V_60 * V_33 ,
const char * V_61 , T_1 V_57 )
{
struct V_25 * V_26 = NULL ;
char * V_62 ;
T_7 V_63 = 0 ;
V_62 = F_38 ( V_61 , V_57 ) ;
if ( ! V_62 )
return - V_32 ;
if ( F_24 ( & V_34 , NULL , V_62 ,
F_13 ) ) {
F_25 ( V_64 L_3 ,
V_43 , V_62 ) ;
V_63 = - V_65 ;
goto V_58;
}
if ( ( V_26 = F_21 ( V_62 ) ) ) {
V_63 = F_16 ( V_26 ) ;
F_26 ( V_26 ) ;
} else {
F_25 ( V_64 L_4 ,
V_43 , V_62 ) ;
V_63 = - V_66 ;
}
V_58:
F_4 ( V_62 ) ;
if ( V_63 )
return V_63 ;
return V_57 ;
}
static T_7 F_40 ( struct V_60 * V_33 ,
const char * V_61 , T_1 V_57 )
{
struct V_1 * V_2 ;
char * V_62 ;
V_62 = F_38 ( V_61 , V_57 ) ;
if ( ! V_62 )
return - V_32 ;
if ( ( V_2 = F_24 ( & V_34 , NULL , V_62 ,
F_13 ) ) ) {
F_41 ( F_14 ( V_2 ) ) ;
F_4 ( V_62 ) ;
return V_57 ;
} else {
F_25 ( V_64 L_5 ,
V_43 , V_62 ) ;
F_4 ( V_62 ) ;
return - V_66 ;
}
}
static int F_42 ( struct V_1 * V_2 , struct V_67 * V_45 )
{
const struct V_38 * V_39 = V_45 -> V_47 ;
if ( ! V_39 )
return 0 ;
return F_43 ( V_39 , V_2 ) != NULL ;
}
static int F_44 ( struct V_1 * V_2 )
{
int error = - V_66 ;
struct V_44 * V_45 ;
struct V_29 * V_68 ;
const struct V_38 * V_69 ;
V_45 = F_45 ( V_2 -> V_46 ) ;
V_68 = F_14 ( V_2 ) ;
if ( ! V_45 -> V_70 )
return error ;
F_46 ( V_68 ) ;
V_69 = F_43 ( V_45 -> V_46 . V_47 , V_2 ) ;
if ( V_69 )
error = V_45 -> V_70 ( V_68 , V_69 ) ;
if ( error )
F_47 ( V_68 ) ;
return error ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_29 * V_68 = F_14 ( V_2 ) ;
struct V_44 * V_45 = F_45 ( V_2 -> V_46 ) ;
if ( V_2 -> V_46 && V_45 -> remove )
V_45 -> remove ( V_68 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_29 * V_68 = F_14 ( V_2 ) ;
struct V_44 * V_45 = F_45 ( V_2 -> V_46 ) ;
if ( V_2 -> V_46 && V_45 -> V_71 )
V_45 -> V_71 ( V_68 ) ;
}
static T_7 F_50 ( struct V_1 * V_2 ,
struct V_72 * V_73 , char * V_61 )
{
struct V_29 * V_74 ;
V_74 = F_14 ( V_2 ) ;
return sprintf ( V_61 , L_6 , V_74 -> V_2 . V_27 -> V_28 ) ;
}
static T_7 F_51 ( struct V_1 * V_2 ,
struct V_72 * V_73 , char * V_61 )
{
struct V_29 * V_74 ;
V_74 = F_14 ( V_2 ) ;
return sprintf ( V_61 , L_6 , V_74 -> V_2 . V_27 -> V_75 ) ;
}
static T_7 F_52 ( struct V_1 * V_2 ,
struct V_72 * V_73 , char * V_61 )
{
T_7 V_76 = F_53 ( V_2 , V_61 , V_77 - 2 ) ;
V_61 [ V_76 ] = '\n' ;
V_61 [ V_76 + 1 ] = 0 ;
return V_76 + 1 ;
}
static int F_54 ( struct V_1 * V_2 , T_8 V_78 )
{
struct V_29 * V_68 = F_14 ( V_2 ) ;
struct V_44 * V_45 = F_45 ( V_2 -> V_46 ) ;
int V_30 = 0 ;
if ( V_2 -> V_46 && V_45 -> V_79 )
V_30 = V_45 -> V_79 ( V_68 , V_78 ) ;
return V_30 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_29 * V_68 = F_14 ( V_2 ) ;
struct V_44 * V_45 = F_45 ( V_2 -> V_46 ) ;
int V_30 = 0 ;
if ( V_2 -> V_46 && V_45 -> V_80 )
V_30 = V_45 -> V_80 ( V_68 ) ;
return V_30 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( V_45 && V_45 -> V_81 && V_45 -> V_81 -> V_82 )
V_30 = V_45 -> V_81 -> V_82 ( V_2 ) ;
return V_30 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
if ( V_45 && V_45 -> V_81 && V_45 -> V_81 -> V_83 )
V_45 -> V_81 -> V_83 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_79 )
V_30 = V_45 -> V_81 -> V_79 ( V_2 ) ;
} else {
V_30 = F_54 ( V_2 , V_84 ) ;
}
return V_30 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_85 )
V_30 = V_45 -> V_81 -> V_85 ( V_2 ) ;
}
return V_30 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_80 )
V_30 = V_45 -> V_81 -> V_80 ( V_2 ) ;
} else {
V_30 = F_55 ( V_2 ) ;
}
return V_30 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_86 )
V_30 = V_45 -> V_81 -> V_86 ( V_2 ) ;
}
return V_30 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_87 )
V_30 = V_45 -> V_81 -> V_87 ( V_2 ) ;
} else {
V_30 = F_54 ( V_2 , V_88 ) ;
}
return V_30 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_89 )
V_30 = V_45 -> V_81 -> V_89 ( V_2 ) ;
}
return V_30 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_90 )
V_30 = V_45 -> V_81 -> V_90 ( V_2 ) ;
} else {
V_30 = F_55 ( V_2 ) ;
}
return V_30 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_91 )
V_30 = V_45 -> V_81 -> V_91 ( V_2 ) ;
}
return V_30 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_92 )
V_30 = V_45 -> V_81 -> V_92 ( V_2 ) ;
} else {
V_30 = F_54 ( V_2 , V_93 ) ;
}
return V_30 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_94 )
V_30 = V_45 -> V_81 -> V_94 ( V_2 ) ;
}
return V_30 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_95 )
V_30 = V_45 -> V_81 -> V_95 ( V_2 ) ;
} else {
V_30 = F_55 ( V_2 ) ;
}
return V_30 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_81 ) {
if ( V_45 -> V_81 -> V_96 )
V_30 = V_45 -> V_81 -> V_96 ( V_2 ) ;
}
return V_30 ;
}
static int T_9 F_70 ( void )
{
int V_97 ;
F_25 ( V_98 L_7 ) ;
V_97 = F_71 ( & V_34 ) ;
if ( V_97 ) {
F_25 ( V_42 L_8 ,
V_43 ) ;
return V_97 ;
}
V_97 = F_72 ( & V_31 ) ;
if ( V_97 ) {
F_25 ( V_64 L_9 ,
V_43 , V_97 ) ;
F_73 ( & V_34 ) ;
return V_97 ;
}
V_97 = F_20 ( V_99 ) ;
if ( V_97 ) {
F_74 ( & V_31 ) ;
F_73 ( & V_34 ) ;
return V_97 ;
}
return 0 ;
}
