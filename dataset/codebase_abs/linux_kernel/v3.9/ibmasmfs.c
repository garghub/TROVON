static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 , const char * V_5 , void * V_6 )
{
return F_2 ( V_3 , V_4 , V_6 , V_7 ) ;
}
static int V_7 ( struct V_8 * V_9 , void * V_6 , int V_10 )
{
struct V_11 * V_12 ;
V_9 -> V_13 = V_14 ;
V_9 -> V_15 = V_16 ;
V_9 -> V_17 = V_18 ;
V_9 -> V_19 = & V_20 ;
V_9 -> V_21 = 1 ;
V_12 = F_3 ( V_9 , V_22 | 0500 ) ;
if ( ! V_12 )
return - V_23 ;
V_12 -> V_24 = & V_25 ;
V_12 -> V_26 = V_27 ;
V_9 -> V_28 = F_4 ( V_12 ) ;
if ( ! V_9 -> V_28 )
return - V_23 ;
F_5 ( V_9 ) ;
return 0 ;
}
static struct V_11 * F_3 ( struct V_8 * V_9 , int V_29 )
{
struct V_11 * V_30 = F_6 ( V_9 ) ;
if ( V_30 ) {
V_30 -> V_31 = F_7 () ;
V_30 -> V_32 = V_29 ;
V_30 -> V_33 = V_30 -> V_34 = V_30 -> V_35 = V_36 ;
}
return V_30 ;
}
static struct V_1 * F_8 ( struct V_8 * V_9 ,
struct V_1 * V_37 ,
const char * V_5 ,
const struct V_38 * V_39 ,
void * V_6 ,
int V_29 )
{
struct V_1 * V_1 ;
struct V_11 * V_11 ;
V_1 = F_9 ( V_37 , V_5 ) ;
if ( ! V_1 )
return NULL ;
V_11 = F_3 ( V_9 , V_40 | V_29 ) ;
if ( ! V_11 ) {
F_10 ( V_1 ) ;
return NULL ;
}
V_11 -> V_26 = V_39 ;
V_11 -> V_41 = V_6 ;
F_11 ( V_1 , V_11 ) ;
return V_1 ;
}
static struct V_1 * F_12 ( struct V_8 * V_9 ,
struct V_1 * V_37 ,
const char * V_5 )
{
struct V_1 * V_1 ;
struct V_11 * V_11 ;
V_1 = F_9 ( V_37 , V_5 ) ;
if ( ! V_1 )
return NULL ;
V_11 = F_3 ( V_9 , V_22 | 0500 ) ;
if ( ! V_11 ) {
F_10 ( V_1 ) ;
return NULL ;
}
V_11 -> V_24 = & V_25 ;
V_11 -> V_26 = V_27 ;
F_11 ( V_1 , V_11 ) ;
return V_1 ;
}
int F_13 ( void )
{
return F_14 ( & V_42 ) ;
}
void F_15 ( void )
{
F_16 ( & V_42 ) ;
}
void F_17 ( struct V_43 * V_44 )
{
F_18 ( & V_44 -> V_45 , & V_46 ) ;
}
static int F_19 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
struct V_48 * V_49 ;
if ( ! V_11 -> V_41 )
return - V_50 ;
V_49 = F_20 ( sizeof( struct V_48 ) , V_51 ) ;
if ( ! V_49 )
return - V_23 ;
V_49 -> V_52 = NULL ;
V_49 -> V_44 = V_11 -> V_41 ;
V_47 -> V_53 = V_49 ;
return 0 ;
}
static int F_21 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_53 ;
if ( V_49 -> V_52 )
F_22 ( V_49 -> V_52 ) ;
F_23 ( V_49 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_47 * V_47 , char T_2 * V_54 , T_3 V_55 , T_4 * V_56 )
{
struct V_48 * V_49 = V_47 -> V_53 ;
struct V_52 * V_57 ;
int V_58 ;
unsigned long V_4 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 == 0 || V_55 > V_60 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
F_25 ( & V_49 -> V_44 -> V_61 , V_4 ) ;
V_57 = V_49 -> V_52 ;
if ( V_57 == NULL ) {
F_26 ( & V_49 -> V_44 -> V_61 , V_4 ) ;
return 0 ;
}
V_49 -> V_52 = NULL ;
F_26 ( & V_49 -> V_44 -> V_61 , V_4 ) ;
if ( V_57 -> V_62 != V_63 ) {
F_22 ( V_57 ) ;
return - V_64 ;
}
V_58 = F_27 ( V_55 , V_57 -> V_65 ) ;
if ( F_28 ( V_54 , V_57 -> V_66 , V_58 ) ) {
F_22 ( V_57 ) ;
return - V_67 ;
}
F_22 ( V_57 ) ;
return V_58 ;
}
static T_1 F_29 ( struct V_47 * V_47 , const char T_2 * V_68 , T_3 V_55 , T_4 * V_56 )
{
struct V_48 * V_49 = V_47 -> V_53 ;
struct V_52 * V_57 ;
unsigned long V_4 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 == 0 || V_55 > V_60 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
if ( V_49 -> V_52 )
return - V_69 ;
V_57 = F_30 ( V_49 -> V_44 , V_55 ) ;
if ( ! V_57 )
return - V_23 ;
if ( F_31 ( V_57 -> V_66 , V_68 , V_55 ) ) {
F_22 ( V_57 ) ;
return - V_67 ;
}
F_25 ( & V_49 -> V_44 -> V_61 , V_4 ) ;
if ( V_49 -> V_52 ) {
F_26 ( & V_49 -> V_44 -> V_61 , V_4 ) ;
F_22 ( V_57 ) ;
return - V_69 ;
}
V_49 -> V_52 = V_57 ;
F_26 ( & V_49 -> V_44 -> V_61 , V_4 ) ;
F_32 ( V_49 -> V_44 , V_57 ) ;
F_33 ( V_57 , F_34 ( V_57 -> V_66 ) ) ;
return V_55 ;
}
static int F_35 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
struct V_70 * V_71 ;
struct V_43 * V_44 ;
if ( ! V_11 -> V_41 )
return - V_50 ;
V_44 = V_11 -> V_41 ;
V_71 = F_20 ( sizeof( struct V_70 ) , V_51 ) ;
if ( ! V_71 )
return - V_23 ;
F_36 ( V_44 , & V_71 -> V_72 ) ;
V_71 -> V_44 = V_44 ;
V_71 -> V_73 = 0 ;
V_47 -> V_53 = V_71 ;
return 0 ;
}
static int F_37 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
struct V_70 * V_71 = V_47 -> V_53 ;
F_38 ( V_71 -> V_44 , & V_71 -> V_72 ) ;
F_23 ( V_71 ) ;
return 0 ;
}
static T_1 F_39 ( struct V_47 * V_47 , char T_2 * V_54 , T_3 V_55 , T_4 * V_56 )
{
struct V_70 * V_71 = V_47 -> V_53 ;
struct V_74 * V_72 = & V_71 -> V_72 ;
struct V_43 * V_44 = V_71 -> V_44 ;
int V_30 ;
unsigned long V_4 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 == 0 || V_55 > V_75 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
F_25 ( & V_44 -> V_61 , V_4 ) ;
if ( V_71 -> V_73 ) {
F_26 ( & V_44 -> V_61 , V_4 ) ;
return - V_76 ;
}
V_71 -> V_73 = 1 ;
F_26 ( & V_44 -> V_61 , V_4 ) ;
V_30 = F_40 ( V_44 , V_72 ) ;
if ( V_30 <= 0 )
goto V_77;
if ( V_55 < V_72 -> V_78 ) {
V_30 = - V_59 ;
goto V_77;
}
if ( F_28 ( V_54 , V_72 -> V_6 , V_72 -> V_78 ) ) {
V_30 = - V_67 ;
goto V_77;
}
V_30 = V_72 -> V_78 ;
V_77:
V_71 -> V_73 = 0 ;
return V_30 ;
}
static T_1 F_41 ( struct V_47 * V_47 , const char T_2 * V_54 , T_3 V_55 , T_4 * V_56 )
{
struct V_70 * V_71 = V_47 -> V_53 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 != 1 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
F_42 ( & V_71 -> V_72 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
struct V_79 * V_80 ;
if ( ! V_11 -> V_41 )
return - V_50 ;
V_80 = F_20 ( sizeof( struct V_79 ) , V_51 ) ;
if ( ! V_80 )
return - V_23 ;
V_80 -> V_44 = V_11 -> V_41 ;
V_80 -> V_73 = 0 ;
F_44 ( V_80 -> V_44 , & V_80 -> V_81 ) ;
V_47 -> V_53 = V_80 ;
return 0 ;
}
static int F_45 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
struct V_79 * V_80 = V_47 -> V_53 ;
F_23 ( V_80 ) ;
return 0 ;
}
static T_1 F_46 ( struct V_47 * V_47 , char T_2 * V_54 , T_3 V_55 , T_4 * V_56 )
{
struct V_79 * V_80 = V_47 -> V_53 ;
unsigned long V_4 ;
int V_82 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 == 0 || V_55 > 1024 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
F_25 ( & V_80 -> V_44 -> V_61 , V_4 ) ;
if ( V_80 -> V_73 ) {
F_26 ( & V_80 -> V_44 -> V_61 , V_4 ) ;
return - V_76 ;
}
V_80 -> V_73 = 1 ;
F_26 ( & V_80 -> V_44 -> V_61 , V_4 ) ;
V_82 = F_47 ( V_80 -> V_44 , & V_80 -> V_81 ) ;
V_80 -> V_73 = 0 ;
return V_82 ;
}
static T_1 F_48 ( struct V_47 * V_47 , const char T_2 * V_54 , T_3 V_55 , T_4 * V_56 )
{
struct V_79 * V_80 = V_47 -> V_53 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 != 1 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
if ( V_80 -> V_73 )
F_49 ( & V_80 -> V_81 ) ;
return 1 ;
}
static int F_50 ( struct V_11 * V_11 , struct V_47 * V_47 )
{
return 0 ;
}
static T_1 F_51 ( struct V_47 * V_47 , char T_2 * V_54 , T_3 V_55 , T_4 * V_56 )
{
void T_5 * V_83 = ( void T_5 * ) V_47 -> V_53 ;
unsigned char * V_84 ;
int V_85 ;
int V_58 = 0 ;
unsigned int V_86 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 == 0 || V_55 > 1024 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
V_84 = ( unsigned char * ) F_52 ( V_51 ) ;
if ( ! V_84 )
return - V_23 ;
V_86 = F_53 ( V_83 ) ;
V_58 = sprintf ( V_84 , L_1 , V_86 ) ;
if ( F_28 ( V_54 , V_84 , V_58 ) ) {
V_85 = - V_67 ;
goto exit;
}
* V_56 += V_58 ;
V_85 = V_58 ;
exit:
F_54 ( ( unsigned long ) V_84 ) ;
return V_85 ;
}
static T_1 F_55 ( struct V_47 * V_47 , const char T_2 * V_68 , T_3 V_55 , T_4 * V_56 )
{
void T_5 * V_83 = ( void T_5 * ) V_47 -> V_53 ;
char * V_87 ;
unsigned int V_86 ;
if ( * V_56 < 0 )
return - V_59 ;
if ( V_55 == 0 || V_55 > 1024 )
return 0 ;
if ( * V_56 != 0 )
return 0 ;
V_87 = F_56 ( V_55 + 1 , V_51 ) ;
if ( ! V_87 )
return - V_23 ;
if ( F_31 ( V_87 , V_68 , V_55 ) ) {
F_23 ( V_87 ) ;
return - V_67 ;
}
V_86 = F_57 ( V_87 , NULL , 10 ) ;
F_58 ( V_86 , V_83 ) ;
F_23 ( V_87 ) ;
return V_55 ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_88 * V_89 ;
struct V_43 * V_44 ;
F_59 (entry, &service_processors) {
struct V_1 * V_90 ;
struct V_1 * V_91 ;
V_44 = F_60 ( V_89 , struct V_43 , V_45 ) ;
V_90 = F_12 ( V_9 , V_9 -> V_28 , V_44 -> V_92 ) ;
if ( ! V_90 )
continue;
F_8 ( V_9 , V_90 , L_2 , & V_93 , V_44 , V_94 | V_95 ) ;
F_8 ( V_9 , V_90 , L_3 , & V_96 , V_44 , V_94 | V_95 ) ;
F_8 ( V_9 , V_90 , L_4 , & V_97 , V_44 , V_94 | V_95 ) ;
V_91 = F_12 ( V_9 , V_90 , L_5 ) ;
if ( ! V_91 )
continue;
F_8 ( V_9 , V_91 , L_6 , & V_98 , ( void * ) F_61 ( V_44 ) , V_94 | V_95 ) ;
F_8 ( V_9 , V_91 , L_7 , & V_98 , ( void * ) F_62 ( V_44 ) , V_94 | V_95 ) ;
F_8 ( V_9 , V_91 , L_8 , & V_98 , ( void * ) F_63 ( V_44 ) , V_94 | V_95 ) ;
}
}
