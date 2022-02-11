static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 , const char * V_5 , void * V_6 )
{
return F_2 ( V_3 , V_4 , V_6 , V_7 ) ;
}
static int V_7 ( struct V_8 * V_9 , void * V_6 , int V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_13 ;
V_9 -> V_14 = V_15 ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
V_9 -> V_20 = & V_21 ;
V_9 -> V_22 = 1 ;
V_12 = F_3 ( V_9 , V_23 | 0500 ) ;
if ( ! V_12 )
return - V_24 ;
V_12 -> V_25 = & V_26 ;
V_12 -> V_27 = V_28 ;
V_13 = F_4 ( V_12 ) ;
if ( ! V_13 ) {
F_5 ( V_12 ) ;
return - V_24 ;
}
V_9 -> V_29 = V_13 ;
F_6 ( V_9 , V_13 ) ;
return 0 ;
}
static struct V_11 * F_3 ( struct V_8 * V_9 , int V_30 )
{
struct V_11 * V_31 = F_7 ( V_9 ) ;
if ( V_31 ) {
V_31 -> V_32 = F_8 () ;
V_31 -> V_33 = V_30 ;
V_31 -> V_34 = V_31 -> V_35 = V_31 -> V_36 = V_37 ;
}
return V_31 ;
}
static struct V_1 * F_9 ( struct V_8 * V_9 ,
struct V_1 * V_38 ,
const char * V_5 ,
const struct V_39 * V_40 ,
void * V_6 ,
int V_30 )
{
struct V_1 * V_1 ;
struct V_11 * V_11 ;
V_1 = F_10 ( V_38 , V_5 ) ;
if ( ! V_1 )
return NULL ;
V_11 = F_3 ( V_9 , V_41 | V_30 ) ;
if ( ! V_11 ) {
F_11 ( V_1 ) ;
return NULL ;
}
V_11 -> V_27 = V_40 ;
V_11 -> V_42 = V_6 ;
F_12 ( V_1 , V_11 ) ;
return V_1 ;
}
static struct V_1 * F_13 ( struct V_8 * V_9 ,
struct V_1 * V_38 ,
const char * V_5 )
{
struct V_1 * V_1 ;
struct V_11 * V_11 ;
V_1 = F_10 ( V_38 , V_5 ) ;
if ( ! V_1 )
return NULL ;
V_11 = F_3 ( V_9 , V_23 | 0500 ) ;
if ( ! V_11 ) {
F_11 ( V_1 ) ;
return NULL ;
}
V_11 -> V_25 = & V_26 ;
V_11 -> V_27 = V_28 ;
F_12 ( V_1 , V_11 ) ;
return V_1 ;
}
int F_14 ( void )
{
return F_15 ( & V_43 ) ;
}
void F_16 ( void )
{
F_17 ( & V_43 ) ;
}
void F_18 ( struct V_44 * V_45 )
{
F_19 ( & V_45 -> V_46 , & V_47 ) ;
}
static int F_20 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
struct V_49 * V_50 ;
if ( ! V_11 -> V_42 )
return - V_51 ;
V_50 = F_21 ( sizeof( struct V_49 ) , V_52 ) ;
if ( ! V_50 )
return - V_24 ;
V_50 -> V_53 = NULL ;
V_50 -> V_45 = V_11 -> V_42 ;
V_48 -> V_54 = V_50 ;
return 0 ;
}
static int F_22 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_54 ;
if ( V_50 -> V_53 )
F_23 ( V_50 -> V_53 ) ;
F_24 ( V_50 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_48 * V_48 , char T_2 * V_55 , T_3 V_56 , T_4 * V_57 )
{
struct V_49 * V_50 = V_48 -> V_54 ;
struct V_53 * V_58 ;
int V_59 ;
unsigned long V_4 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 == 0 || V_56 > V_61 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
F_26 ( & V_50 -> V_45 -> V_62 , V_4 ) ;
V_58 = V_50 -> V_53 ;
if ( V_58 == NULL ) {
F_27 ( & V_50 -> V_45 -> V_62 , V_4 ) ;
return 0 ;
}
V_50 -> V_53 = NULL ;
F_27 ( & V_50 -> V_45 -> V_62 , V_4 ) ;
if ( V_58 -> V_63 != V_64 ) {
F_23 ( V_58 ) ;
return - V_65 ;
}
V_59 = F_28 ( V_56 , V_58 -> V_66 ) ;
if ( F_29 ( V_55 , V_58 -> V_67 , V_59 ) ) {
F_23 ( V_58 ) ;
return - V_68 ;
}
F_23 ( V_58 ) ;
return V_59 ;
}
static T_1 F_30 ( struct V_48 * V_48 , const char T_2 * V_69 , T_3 V_56 , T_4 * V_57 )
{
struct V_49 * V_50 = V_48 -> V_54 ;
struct V_53 * V_58 ;
unsigned long V_4 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 == 0 || V_56 > V_61 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
if ( V_50 -> V_53 )
return - V_70 ;
V_58 = F_31 ( V_50 -> V_45 , V_56 ) ;
if ( ! V_58 )
return - V_24 ;
if ( F_32 ( V_58 -> V_67 , V_69 , V_56 ) ) {
F_23 ( V_58 ) ;
return - V_68 ;
}
F_26 ( & V_50 -> V_45 -> V_62 , V_4 ) ;
if ( V_50 -> V_53 ) {
F_27 ( & V_50 -> V_45 -> V_62 , V_4 ) ;
F_23 ( V_58 ) ;
return - V_70 ;
}
V_50 -> V_53 = V_58 ;
F_27 ( & V_50 -> V_45 -> V_62 , V_4 ) ;
F_33 ( V_50 -> V_45 , V_58 ) ;
F_34 ( V_58 , F_35 ( V_58 -> V_67 ) ) ;
return V_56 ;
}
static int F_36 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
struct V_71 * V_72 ;
struct V_44 * V_45 ;
if ( ! V_11 -> V_42 )
return - V_51 ;
V_45 = V_11 -> V_42 ;
V_72 = F_21 ( sizeof( struct V_71 ) , V_52 ) ;
if ( ! V_72 )
return - V_24 ;
F_37 ( V_45 , & V_72 -> V_73 ) ;
V_72 -> V_45 = V_45 ;
V_72 -> V_74 = 0 ;
V_48 -> V_54 = V_72 ;
return 0 ;
}
static int F_38 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
struct V_71 * V_72 = V_48 -> V_54 ;
F_39 ( V_72 -> V_45 , & V_72 -> V_73 ) ;
F_24 ( V_72 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_48 * V_48 , char T_2 * V_55 , T_3 V_56 , T_4 * V_57 )
{
struct V_71 * V_72 = V_48 -> V_54 ;
struct V_75 * V_73 = & V_72 -> V_73 ;
struct V_44 * V_45 = V_72 -> V_45 ;
int V_31 ;
unsigned long V_4 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 == 0 || V_56 > V_76 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
F_26 ( & V_45 -> V_62 , V_4 ) ;
if ( V_72 -> V_74 ) {
F_27 ( & V_45 -> V_62 , V_4 ) ;
return - V_77 ;
}
V_72 -> V_74 = 1 ;
F_27 ( & V_45 -> V_62 , V_4 ) ;
V_31 = F_41 ( V_45 , V_73 ) ;
if ( V_31 <= 0 )
goto V_78;
if ( V_56 < V_73 -> V_79 ) {
V_31 = - V_60 ;
goto V_78;
}
if ( F_29 ( V_55 , V_73 -> V_6 , V_73 -> V_79 ) ) {
V_31 = - V_68 ;
goto V_78;
}
V_31 = V_73 -> V_79 ;
V_78:
V_72 -> V_74 = 0 ;
return V_31 ;
}
static T_1 F_42 ( struct V_48 * V_48 , const char T_2 * V_55 , T_3 V_56 , T_4 * V_57 )
{
struct V_71 * V_72 = V_48 -> V_54 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 != 1 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
F_43 ( & V_72 -> V_73 ) ;
return 0 ;
}
static int F_44 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
struct V_80 * V_81 ;
if ( ! V_11 -> V_42 )
return - V_51 ;
V_81 = F_21 ( sizeof( struct V_80 ) , V_52 ) ;
if ( ! V_81 )
return - V_24 ;
V_81 -> V_45 = V_11 -> V_42 ;
V_81 -> V_74 = 0 ;
F_45 ( V_81 -> V_45 , & V_81 -> V_82 ) ;
V_48 -> V_54 = V_81 ;
return 0 ;
}
static int F_46 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
struct V_80 * V_81 = V_48 -> V_54 ;
F_24 ( V_81 ) ;
return 0 ;
}
static T_1 F_47 ( struct V_48 * V_48 , char T_2 * V_55 , T_3 V_56 , T_4 * V_57 )
{
struct V_80 * V_81 = V_48 -> V_54 ;
unsigned long V_4 ;
int V_83 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 == 0 || V_56 > 1024 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
F_26 ( & V_81 -> V_45 -> V_62 , V_4 ) ;
if ( V_81 -> V_74 ) {
F_27 ( & V_81 -> V_45 -> V_62 , V_4 ) ;
return - V_77 ;
}
V_81 -> V_74 = 1 ;
F_27 ( & V_81 -> V_45 -> V_62 , V_4 ) ;
V_83 = F_48 ( V_81 -> V_45 , & V_81 -> V_82 ) ;
V_81 -> V_74 = 0 ;
return V_83 ;
}
static T_1 F_49 ( struct V_48 * V_48 , const char T_2 * V_55 , T_3 V_56 , T_4 * V_57 )
{
struct V_80 * V_81 = V_48 -> V_54 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 != 1 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
if ( V_81 -> V_74 )
F_50 ( & V_81 -> V_82 ) ;
return 1 ;
}
static int F_51 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
V_48 -> V_54 = V_11 -> V_42 ;
return 0 ;
}
static int F_52 ( struct V_11 * V_11 , struct V_48 * V_48 )
{
return 0 ;
}
static T_1 F_53 ( struct V_48 * V_48 , char T_2 * V_55 , T_3 V_56 , T_4 * V_57 )
{
void T_5 * V_84 = ( void T_5 * ) V_48 -> V_54 ;
unsigned char * V_85 ;
int V_86 ;
int V_59 = 0 ;
unsigned int V_87 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 == 0 || V_56 > 1024 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
V_85 = ( unsigned char * ) F_54 ( V_52 ) ;
if ( ! V_85 )
return - V_24 ;
V_87 = F_55 ( V_84 ) ;
V_59 = sprintf ( V_85 , L_1 , V_87 ) ;
if ( F_29 ( V_55 , V_85 , V_59 ) ) {
V_86 = - V_68 ;
goto exit;
}
* V_57 += V_59 ;
V_86 = V_59 ;
exit:
F_56 ( ( unsigned long ) V_85 ) ;
return V_86 ;
}
static T_1 F_57 ( struct V_48 * V_48 , const char T_2 * V_69 , T_3 V_56 , T_4 * V_57 )
{
void T_5 * V_84 = ( void T_5 * ) V_48 -> V_54 ;
char * V_88 ;
unsigned int V_87 ;
if ( * V_57 < 0 )
return - V_60 ;
if ( V_56 == 0 || V_56 > 1024 )
return 0 ;
if ( * V_57 != 0 )
return 0 ;
V_88 = F_58 ( V_56 + 1 , V_52 ) ;
if ( ! V_88 )
return - V_24 ;
if ( F_32 ( V_88 , V_69 , V_56 ) ) {
F_24 ( V_88 ) ;
return - V_68 ;
}
V_87 = F_59 ( V_88 , NULL , 10 ) ;
F_60 ( V_87 , V_84 ) ;
F_24 ( V_88 ) ;
return V_56 ;
}
static void F_6 ( struct V_8 * V_9 , struct V_1 * V_12 )
{
struct V_89 * V_90 ;
struct V_44 * V_45 ;
F_61 (entry, &service_processors) {
struct V_1 * V_91 ;
struct V_1 * V_92 ;
V_45 = F_62 ( V_90 , struct V_44 , V_46 ) ;
V_91 = F_13 ( V_9 , V_12 , V_45 -> V_93 ) ;
if ( ! V_91 )
continue;
F_9 ( V_9 , V_91 , L_2 , & V_94 , V_45 , V_95 | V_96 ) ;
F_9 ( V_9 , V_91 , L_3 , & V_97 , V_45 , V_95 | V_96 ) ;
F_9 ( V_9 , V_91 , L_4 , & V_98 , V_45 , V_95 | V_96 ) ;
V_92 = F_13 ( V_9 , V_91 , L_5 ) ;
if ( ! V_92 )
continue;
F_9 ( V_9 , V_92 , L_6 , & V_99 , ( void * ) F_63 ( V_45 ) , V_95 | V_96 ) ;
F_9 ( V_9 , V_92 , L_7 , & V_99 , ( void * ) F_64 ( V_45 ) , V_95 | V_96 ) ;
F_9 ( V_9 , V_92 , L_8 , & V_99 , ( void * ) F_65 ( V_45 ) , V_95 | V_96 ) ;
}
}
