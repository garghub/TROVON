static void * F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 ,
T_3 V_5 ,
struct V_6 * V_7 )
{
void * V_8 ;
V_8 = F_2 ( V_3 , V_5 ) ;
* V_4 = ( T_2 ) V_8 ;
return V_8 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_9 ,
T_2 V_4 ,
struct V_6 * V_7 )
{
F_4 ( V_9 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 ,
struct V_10 * V_10 ,
unsigned long V_11 ,
T_1 V_3 ,
enum V_12 V_13 ,
struct V_6 * V_7 )
{
return ( T_2 ) ( F_6 ( V_10 ) + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_14 ,
T_1 V_3 ,
enum V_12 V_13 ,
struct V_6 * V_7 )
{
return;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_17 , enum V_12 V_13 ,
struct V_6 * V_7 )
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
int V_17 , enum V_12 V_13 ,
struct V_6 * V_7 )
{
return;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_23 )
{
return V_23 == F_13 ( 64 ) ;
}
static T_4 F_14 ( struct V_1 * V_2 )
{
return F_13 ( 64 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_24 )
{
struct V_25 * V_26 = F_16 ( V_2 ) -> V_2 . V_27 ;
return ( V_26 -> V_28 &&
( strcasecmp ( ( char * ) V_24 , V_26 -> V_28 ) == 0 ) ) ;
}
static int F_17 ( struct V_1 * V_2 , void * V_24 )
{
return F_16 ( V_2 ) -> V_2 . V_27 == V_24 ;
}
static int F_18 ( struct V_25 * V_26 )
{
struct V_29 * V_2 ;
int V_30 ;
V_2 = F_19 ( V_26 , NULL , & V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_2 . V_33 = & V_34 ;
V_2 -> V_2 . V_35 . V_36 = & V_37 ;
V_30 = F_20 ( V_2 ) ;
if ( V_30 )
F_21 ( V_2 ) ;
return V_30 ;
}
static int F_22 ( const struct V_38 * V_39 )
{
struct V_25 * V_40 , * V_41 ;
int V_30 = 0 ;
V_40 = F_23 ( L_1 ) ;
F_24 (root, child) {
if ( ! F_25 ( V_39 , V_41 ) )
continue;
if ( F_26 ( & V_34 , NULL , V_41 ,
F_17 ) )
continue;
V_30 = F_18 ( V_41 ) ;
if ( V_30 ) {
F_27 ( V_42 L_2 ,
V_43 , V_30 ) ;
F_28 ( V_41 ) ;
break;
}
}
F_28 ( V_40 ) ;
return V_30 ;
}
int F_29 ( struct V_44 * V_45 )
{
F_22 ( V_45 -> V_46 . V_47 ) ;
V_45 -> V_46 . V_33 = & V_34 ;
return F_30 ( & V_45 -> V_46 ) ;
}
void F_31 ( struct V_44 * V_45 )
{
F_32 ( & V_45 -> V_46 ) ;
}
int F_33 ( T_5 V_48 , T_6 V_49 ,
unsigned long V_50 , const char * V_51 ,
void * V_52 )
{
unsigned int V_53 = F_34 ( NULL , V_48 ) ;
if ( V_53 == V_54 )
return - V_55 ;
return F_35 ( V_53 , V_49 , V_50 , V_51 , V_52 ) ;
}
void F_36 ( T_5 V_48 , void * V_52 )
{
unsigned int V_53 = F_37 ( NULL , V_48 ) ;
F_38 ( V_53 , V_52 ) ;
F_39 ( V_53 ) ;
}
static char * F_40 ( const char * V_56 , T_1 V_57 )
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
static T_7 F_41 ( struct V_60 * V_33 ,
const char * V_61 , T_1 V_57 )
{
struct V_25 * V_26 = NULL ;
char * V_62 ;
T_7 V_63 = 0 ;
V_62 = F_40 ( V_61 , V_57 ) ;
if ( ! V_62 )
return - V_32 ;
if ( F_26 ( & V_34 , NULL , V_62 ,
F_15 ) ) {
F_27 ( V_64 L_3 ,
V_43 , V_62 ) ;
V_63 = - V_65 ;
goto V_58;
}
if ( ( V_26 = F_23 ( V_62 ) ) ) {
V_63 = F_18 ( V_26 ) ;
F_28 ( V_26 ) ;
} else {
F_27 ( V_64 L_4 ,
V_43 , V_62 ) ;
V_63 = - V_66 ;
}
V_58:
F_4 ( V_62 ) ;
if ( V_63 )
return V_63 ;
return V_57 ;
}
static T_7 F_42 ( struct V_60 * V_33 ,
const char * V_61 , T_1 V_57 )
{
struct V_1 * V_2 ;
char * V_62 ;
V_62 = F_40 ( V_61 , V_57 ) ;
if ( ! V_62 )
return - V_32 ;
if ( ( V_2 = F_26 ( & V_34 , NULL , V_62 ,
F_15 ) ) ) {
F_43 ( F_16 ( V_2 ) ) ;
F_4 ( V_62 ) ;
return V_57 ;
} else {
F_27 ( V_64 L_5 ,
V_43 , V_62 ) ;
F_4 ( V_62 ) ;
return - V_66 ;
}
}
static int F_44 ( struct V_1 * V_2 , struct V_67 * V_45 )
{
const struct V_38 * V_39 = V_45 -> V_47 ;
if ( ! V_39 )
return 0 ;
return F_45 ( V_39 , V_2 ) != NULL ;
}
static int F_46 ( struct V_1 * V_2 )
{
int error = - V_66 ;
struct V_44 * V_45 ;
struct V_29 * V_68 ;
V_45 = F_47 ( V_2 -> V_46 ) ;
V_68 = F_16 ( V_2 ) ;
if ( ! V_45 -> V_69 )
return error ;
F_48 ( V_68 ) ;
if ( F_49 ( V_2 , V_2 -> V_46 ) )
error = V_45 -> V_69 ( V_68 ) ;
if ( error )
F_50 ( V_68 ) ;
return error ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_29 * V_68 = F_16 ( V_2 ) ;
struct V_44 * V_45 = F_47 ( V_2 -> V_46 ) ;
if ( V_2 -> V_46 && V_45 -> remove )
V_45 -> remove ( V_68 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_29 * V_68 = F_16 ( V_2 ) ;
struct V_44 * V_45 = F_47 ( V_2 -> V_46 ) ;
if ( V_2 -> V_46 && V_45 -> V_70 )
V_45 -> V_70 ( V_68 ) ;
}
static T_7 F_53 ( struct V_1 * V_2 ,
struct V_71 * V_72 , char * V_61 )
{
struct V_29 * V_73 ;
V_73 = F_16 ( V_2 ) ;
return sprintf ( V_61 , L_6 , V_73 -> V_2 . V_27 -> V_28 ) ;
}
static T_7 F_54 ( struct V_1 * V_2 ,
struct V_71 * V_72 , char * V_61 )
{
struct V_29 * V_73 ;
V_73 = F_16 ( V_2 ) ;
return sprintf ( V_61 , L_6 , V_73 -> V_2 . V_27 -> V_74 ) ;
}
static T_7 F_55 ( struct V_1 * V_2 ,
struct V_71 * V_72 , char * V_61 )
{
T_7 V_75 = F_56 ( V_2 , V_61 , V_76 - 2 ) ;
V_61 [ V_75 ] = '\n' ;
V_61 [ V_75 + 1 ] = 0 ;
return V_75 + 1 ;
}
static int F_57 ( struct V_1 * V_2 , T_8 V_77 )
{
struct V_29 * V_68 = F_16 ( V_2 ) ;
struct V_44 * V_45 = F_47 ( V_2 -> V_46 ) ;
int V_30 = 0 ;
if ( V_2 -> V_46 && V_45 -> V_78 )
V_30 = V_45 -> V_78 ( V_68 , V_77 ) ;
return V_30 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_29 * V_68 = F_16 ( V_2 ) ;
struct V_44 * V_45 = F_47 ( V_2 -> V_46 ) ;
int V_30 = 0 ;
if ( V_2 -> V_46 && V_45 -> V_79 )
V_30 = V_45 -> V_79 ( V_68 ) ;
return V_30 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( V_45 && V_45 -> V_80 && V_45 -> V_80 -> V_81 )
V_30 = V_45 -> V_80 -> V_81 ( V_2 ) ;
return V_30 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
if ( V_45 && V_45 -> V_80 && V_45 -> V_80 -> V_82 )
V_45 -> V_80 -> V_82 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_78 )
V_30 = V_45 -> V_80 -> V_78 ( V_2 ) ;
} else {
V_30 = F_57 ( V_2 , V_83 ) ;
}
return V_30 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_84 )
V_30 = V_45 -> V_80 -> V_84 ( V_2 ) ;
}
return V_30 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_79 )
V_30 = V_45 -> V_80 -> V_79 ( V_2 ) ;
} else {
V_30 = F_58 ( V_2 ) ;
}
return V_30 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_85 )
V_30 = V_45 -> V_80 -> V_85 ( V_2 ) ;
}
return V_30 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_86 )
V_30 = V_45 -> V_80 -> V_86 ( V_2 ) ;
} else {
V_30 = F_57 ( V_2 , V_87 ) ;
}
return V_30 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_88 )
V_30 = V_45 -> V_80 -> V_88 ( V_2 ) ;
}
return V_30 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_89 )
V_30 = V_45 -> V_80 -> V_89 ( V_2 ) ;
} else {
V_30 = F_58 ( V_2 ) ;
}
return V_30 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_90 )
V_30 = V_45 -> V_80 -> V_90 ( V_2 ) ;
}
return V_30 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_91 )
V_30 = V_45 -> V_80 -> V_91 ( V_2 ) ;
} else {
V_30 = F_57 ( V_2 , V_92 ) ;
}
return V_30 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_93 )
V_30 = V_45 -> V_80 -> V_93 ( V_2 ) ;
}
return V_30 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_94 )
V_30 = V_45 -> V_80 -> V_94 ( V_2 ) ;
} else {
V_30 = F_58 ( V_2 ) ;
}
return V_30 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_67 * V_45 = V_2 -> V_46 ;
int V_30 = 0 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_80 ) {
if ( V_45 -> V_80 -> V_95 )
V_30 = V_45 -> V_80 -> V_95 ( V_2 ) ;
}
return V_30 ;
}
static int T_9 F_73 ( void )
{
int V_96 ;
F_27 ( V_97 L_7 ) ;
V_96 = F_74 ( & V_34 ) ;
if ( V_96 ) {
F_27 ( V_42 L_8 ,
V_43 ) ;
return V_96 ;
}
V_96 = F_75 ( & V_31 ) ;
if ( V_96 ) {
F_27 ( V_64 L_9 ,
V_43 , V_96 ) ;
F_76 ( & V_34 ) ;
return V_96 ;
}
V_96 = F_22 ( V_98 ) ;
if ( V_96 ) {
F_77 ( & V_31 ) ;
F_76 ( & V_34 ) ;
return V_96 ;
}
return 0 ;
}
