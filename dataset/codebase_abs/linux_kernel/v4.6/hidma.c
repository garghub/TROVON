static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline
struct V_1 * F_3 ( struct V_5 * * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static inline struct V_8 * F_4 ( struct V_9 * V_10 )
{
return F_2 ( V_10 , struct V_8 , V_11 ) ;
}
static inline
struct V_12 * F_5 ( struct V_13 * V_14 )
{
return F_2 ( V_14 , struct V_12 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_3 )
{
F_7 ( & V_3 -> V_4 . V_16 ) ;
}
static void F_8 ( struct V_8 * V_17 )
{
struct V_2 * V_4 = V_17 -> V_11 . V_18 ;
struct V_1 * V_19 = F_1 ( V_4 ) ;
struct V_13 * V_15 ;
T_1 V_20 ;
struct V_12 * V_21 ;
unsigned long V_22 ;
struct V_23 V_24 ;
F_7 ( & V_24 ) ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_10 ( & V_17 -> V_26 , & V_24 ) ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
F_12 (mdesc, &list, node) {
enum V_27 V_28 ;
V_15 = & V_21 -> V_15 ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_13 ( V_15 ) ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
V_28 = F_14 ( V_19 -> V_7 , V_21 -> V_29 ) ;
if ( V_15 -> V_30 && ( V_28 == V_31 ) )
V_15 -> V_30 ( V_15 -> V_32 ) ;
V_20 = V_15 -> V_33 ;
F_15 ( V_15 ) ;
}
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_10 ( & V_24 , & V_17 -> free ) ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
}
static void F_16 ( void * V_34 )
{
struct V_12 * V_21 = V_34 ;
struct V_8 * V_17 = F_4 ( V_21 -> V_15 . V_11 ) ;
struct V_2 * V_4 = V_17 -> V_11 . V_18 ;
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_22 ;
bool V_35 = false ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
if ( V_21 -> V_36 . V_37 ) {
F_17 ( & V_21 -> V_36 , & V_17 -> V_26 ) ;
V_35 = true ;
V_17 -> V_38 = F_18 ( & V_17 -> V_39 ,
struct V_12 , V_36 ) ;
}
F_11 ( & V_17 -> V_25 , V_22 ) ;
F_8 ( V_17 ) ;
if ( V_35 ) {
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
}
}
static int F_21 ( struct V_1 * V_3 , T_2 V_41 )
{
struct V_8 * V_17 ;
struct V_2 * V_4 ;
V_17 = F_22 ( V_3 -> V_4 . V_40 , sizeof( * V_17 ) , V_42 ) ;
if ( ! V_17 )
return - V_43 ;
V_4 = & V_3 -> V_4 ;
V_17 -> V_41 = V_41 ;
V_17 -> V_3 = V_3 ;
V_17 -> V_11 . V_18 = V_4 ;
F_23 ( & V_17 -> V_11 ) ;
F_7 ( & V_17 -> free ) ;
F_7 ( & V_17 -> V_44 ) ;
F_7 ( & V_17 -> V_39 ) ;
F_7 ( & V_17 -> V_26 ) ;
F_24 ( & V_17 -> V_25 ) ;
F_25 ( & V_17 -> V_11 . V_45 , & V_4 -> V_16 ) ;
V_3 -> V_4 . V_46 ++ ;
return 0 ;
}
static void F_26 ( unsigned long V_47 )
{
struct V_1 * V_3 = (struct V_1 * ) V_47 ;
F_27 ( V_3 -> V_4 . V_40 ) ;
F_28 ( V_3 -> V_7 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_1 * V_3 = V_17 -> V_3 ;
unsigned long V_48 ;
int V_49 ;
F_9 ( & V_17 -> V_25 , V_48 ) ;
if ( ! V_17 -> V_38 ) {
struct V_12 * V_15 = F_18 ( & V_17 -> V_39 ,
struct V_12 ,
V_36 ) ;
V_17 -> V_38 = V_15 ;
}
F_11 ( & V_17 -> V_25 , V_48 ) ;
V_49 = F_30 ( V_3 -> V_4 . V_40 ) ;
if ( V_49 < 0 )
F_31 ( & V_3 -> V_50 ) ;
else
F_28 ( V_3 -> V_7 ) ;
}
static enum V_27 F_32 ( struct V_9 * V_10 ,
T_1 V_33 ,
struct V_51 * V_52 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
enum V_27 V_53 ;
V_53 = F_33 ( V_10 , V_33 , V_52 ) ;
if ( V_53 == V_31 )
return V_53 ;
if ( V_17 -> V_54 && ( V_53 == V_55 ) ) {
unsigned long V_48 ;
T_1 V_56 ;
F_9 ( & V_17 -> V_25 , V_48 ) ;
if ( V_17 -> V_38 )
V_56 = V_17 -> V_38 -> V_15 . V_33 ;
else
V_56 = - V_57 ;
if ( V_56 == V_33 )
V_53 = V_58 ;
F_11 ( & V_17 -> V_25 , V_48 ) ;
}
return V_53 ;
}
static T_1 F_34 ( struct V_13 * V_59 )
{
struct V_8 * V_17 = F_4 ( V_59 -> V_11 ) ;
struct V_1 * V_3 = V_17 -> V_3 ;
struct V_12 * V_21 ;
unsigned long V_22 ;
T_1 V_33 ;
F_27 ( V_3 -> V_4 . V_40 ) ;
if ( ! F_35 ( V_3 -> V_7 ) ) {
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
return - V_60 ;
}
V_21 = F_2 ( V_59 , struct V_12 , V_15 ) ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_17 ( & V_21 -> V_36 , & V_17 -> V_39 ) ;
V_33 = F_36 ( V_59 ) ;
F_37 ( V_3 -> V_7 , V_21 -> V_29 ) ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
return V_33 ;
}
static int F_38 ( struct V_9 * V_10 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_1 * V_3 = V_17 -> V_3 ;
struct V_12 * V_21 , * V_61 ;
unsigned long V_22 ;
F_39 ( V_62 ) ;
unsigned int V_63 ;
int V_64 = 0 ;
if ( V_17 -> V_65 )
return 0 ;
for ( V_63 = 0 ; V_63 < V_3 -> V_66 ; V_63 ++ ) {
V_21 = F_40 ( sizeof( struct V_12 ) , V_67 ) ;
if ( ! V_21 ) {
V_64 = - V_43 ;
break;
}
F_41 ( & V_21 -> V_15 , V_10 ) ;
V_21 -> V_15 . V_68 = F_34 ;
V_64 = F_42 ( V_3 -> V_7 , V_17 -> V_41 ,
L_1 , F_16 , V_21 ,
& V_21 -> V_29 ) ;
if ( V_64 ) {
F_43 ( V_10 -> V_18 -> V_40 ,
L_2 , V_63 ) ;
F_44 ( V_21 ) ;
break;
}
F_25 ( & V_21 -> V_36 , & V_62 ) ;
}
if ( V_64 ) {
F_45 (mdesc, tmp, &descs, node) {
F_46 ( V_3 -> V_7 , V_21 -> V_29 ) ;
F_44 ( V_21 ) ;
}
return V_64 ;
}
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_10 ( & V_62 , & V_17 -> free ) ;
V_17 -> V_65 = true ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
return 1 ;
}
static struct V_13 *
F_47 ( struct V_9 * V_10 , T_3 V_69 , T_3 V_70 ,
T_4 V_71 , unsigned long V_48 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_12 * V_21 = NULL ;
struct V_1 * V_19 = V_17 -> V_3 ;
unsigned long V_22 ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
if ( ! F_48 ( & V_17 -> free ) ) {
V_21 = F_18 ( & V_17 -> free , struct V_12 , V_36 ) ;
F_49 ( & V_21 -> V_36 ) ;
}
F_11 ( & V_17 -> V_25 , V_22 ) ;
if ( ! V_21 )
return NULL ;
F_50 ( V_19 -> V_7 , V_21 -> V_29 ,
V_70 , V_69 , V_71 , V_48 ) ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_25 ( & V_21 -> V_36 , & V_17 -> V_44 ) ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
return & V_21 -> V_15 ;
}
static int F_51 ( struct V_9 * V_11 )
{
struct V_8 * V_17 = F_4 ( V_11 ) ;
struct V_1 * V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
struct V_12 * V_61 , * V_21 ;
unsigned long V_22 ;
F_39 ( V_24 ) ;
int V_64 ;
F_27 ( V_3 -> V_4 . V_40 ) ;
F_8 ( V_17 ) ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_52 ( & V_17 -> V_39 , & V_24 ) ;
F_52 ( & V_17 -> V_44 , & V_24 ) ;
F_52 ( & V_17 -> V_26 , & V_24 ) ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
V_64 = F_53 ( V_3 -> V_7 ) ;
if ( V_64 ) {
F_43 ( V_3 -> V_4 . V_40 , L_3 ) ;
goto V_72;
}
F_45 (mdesc, tmp, &list, node) {
struct V_13 * V_59 = & V_21 -> V_15 ;
T_5 V_30 = V_21 -> V_15 . V_30 ;
void * V_73 = V_21 -> V_15 . V_32 ;
F_54 ( V_59 ) ;
if ( V_30 )
V_30 ( V_73 ) ;
F_15 ( V_59 ) ;
F_55 ( & V_21 -> V_36 , & V_17 -> free ) ;
}
V_64 = F_56 ( V_3 -> V_7 ) ;
V_72:
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
return V_64 ;
}
static int F_57 ( struct V_9 * V_11 )
{
struct V_8 * V_17 = F_4 ( V_11 ) ;
struct V_1 * V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
int V_64 ;
V_64 = F_51 ( V_11 ) ;
if ( V_64 )
return V_64 ;
F_27 ( V_3 -> V_4 . V_40 ) ;
V_64 = F_58 ( V_3 -> V_7 ) ;
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
return V_64 ;
}
static void F_59 ( struct V_9 * V_10 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_1 * V_19 = V_17 -> V_3 ;
struct V_12 * V_21 , * V_61 ;
unsigned long V_22 ;
F_39 ( V_62 ) ;
F_51 ( V_10 ) ;
F_9 ( & V_17 -> V_25 , V_22 ) ;
F_10 ( & V_17 -> free , & V_62 ) ;
F_45 (mdesc, tmp, &descs, node) {
F_46 ( V_19 -> V_7 , V_21 -> V_29 ) ;
F_49 ( & V_21 -> V_36 ) ;
F_44 ( V_21 ) ;
}
V_17 -> V_65 = 0 ;
F_11 ( & V_17 -> V_25 , V_22 ) ;
}
static int F_60 ( struct V_9 * V_11 )
{
struct V_8 * V_17 ;
struct V_1 * V_3 ;
V_17 = F_4 ( V_11 ) ;
V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
if ( ! V_17 -> V_54 ) {
F_27 ( V_3 -> V_4 . V_40 ) ;
if ( F_53 ( V_3 -> V_7 ) )
F_61 ( V_3 -> V_4 . V_40 , L_4 ) ;
V_17 -> V_54 = true ;
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
}
return 0 ;
}
static int F_62 ( struct V_9 * V_11 )
{
struct V_8 * V_17 ;
struct V_1 * V_3 ;
int V_64 = 0 ;
V_17 = F_4 ( V_11 ) ;
V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
if ( V_17 -> V_54 ) {
F_27 ( V_3 -> V_4 . V_40 ) ;
V_64 = F_56 ( V_3 -> V_7 ) ;
if ( ! V_64 )
V_17 -> V_54 = false ;
else
F_43 ( V_3 -> V_4 . V_40 ,
L_5 ) ;
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
}
return V_64 ;
}
static T_6 F_63 ( int V_74 , void * V_47 )
{
struct V_5 * V_7 = V_47 ;
return F_64 ( V_74 , V_7 ) ;
}
static int F_65 ( struct V_75 * V_76 )
{
struct V_1 * V_3 ;
struct V_77 * V_78 ;
struct V_77 * V_79 ;
int V_74 ;
void T_7 * V_80 ;
void T_7 * V_81 ;
int V_64 ;
F_66 ( & V_76 -> V_40 , V_82 ) ;
F_67 ( & V_76 -> V_40 ) ;
F_68 ( & V_76 -> V_40 ) ;
F_69 ( & V_76 -> V_40 ) ;
V_78 = F_70 ( V_76 , V_83 , 0 ) ;
V_81 = F_71 ( & V_76 -> V_40 , V_78 ) ;
if ( F_72 ( V_81 ) ) {
V_64 = - V_43 ;
goto V_84;
}
V_79 = F_70 ( V_76 , V_83 , 1 ) ;
V_80 = F_71 ( & V_76 -> V_40 , V_79 ) ;
if ( F_72 ( V_80 ) ) {
V_64 = - V_43 ;
goto V_84;
}
V_74 = F_73 ( V_76 , 0 ) ;
if ( V_74 < 0 ) {
V_64 = - V_60 ;
goto V_84;
}
V_3 = F_22 ( & V_76 -> V_40 , sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 ) {
V_64 = - V_43 ;
goto V_84;
}
F_7 ( & V_3 -> V_4 . V_16 ) ;
F_24 ( & V_3 -> V_25 ) ;
V_3 -> V_4 . V_40 = & V_76 -> V_40 ;
F_27 ( V_3 -> V_4 . V_40 ) ;
F_74 ( V_85 , V_3 -> V_4 . V_86 ) ;
if ( F_75 ( ! V_76 -> V_40 . V_87 ) ) {
V_64 = - V_88 ;
goto V_89;
}
V_3 -> V_90 = V_80 ;
V_3 -> V_79 = V_79 ;
V_3 -> V_91 = V_81 ;
V_3 -> V_78 = V_78 ;
V_3 -> V_4 . V_92 = F_47 ;
V_3 -> V_4 . V_93 = F_38 ;
V_3 -> V_4 . V_94 = F_59 ;
V_3 -> V_4 . V_95 = F_32 ;
V_3 -> V_4 . V_96 = F_29 ;
V_3 -> V_4 . V_97 = F_60 ;
V_3 -> V_4 . V_98 = F_62 ;
V_3 -> V_4 . V_99 = F_57 ;
V_3 -> V_4 . V_100 = 8 ;
F_76 ( & V_76 -> V_40 , L_6 ,
& V_3 -> V_66 ) ;
if ( ! V_3 -> V_66 && V_101 )
V_3 -> V_66 = V_101 ;
if ( ! V_3 -> V_66 )
V_3 -> V_66 = V_102 ;
V_3 -> V_103 = F_77 ( V_3 -> V_91 + 0x28 ) ;
V_64 = F_78 ( & V_76 -> V_40 , F_79 ( 64 ) ) ;
if ( V_64 ) {
F_61 ( & V_76 -> V_40 , L_7 ) ;
V_64 = F_78 ( & V_76 -> V_40 , F_79 ( 32 ) ) ;
if ( V_64 )
goto V_89;
}
V_3 -> V_7 = F_80 ( V_3 -> V_4 . V_40 ,
V_3 -> V_66 , V_3 -> V_91 ,
V_3 -> V_90 , V_3 -> V_103 ) ;
if ( ! V_3 -> V_7 ) {
V_64 = - V_104 ;
goto V_89;
}
V_64 = F_81 ( & V_76 -> V_40 , V_74 , F_63 , 0 ,
L_8 , V_3 -> V_7 ) ;
if ( V_64 )
goto V_105;
F_7 ( & V_3 -> V_4 . V_16 ) ;
V_64 = F_21 ( V_3 , 0 ) ;
if ( V_64 )
goto V_105;
V_64 = F_82 ( & V_3 -> V_4 ) ;
if ( V_64 )
goto V_105;
V_3 -> V_106 = V_74 ;
F_83 ( & V_3 -> V_50 , F_26 , ( unsigned long ) V_3 ) ;
F_84 ( & V_76 -> V_40 , L_9 ) ;
F_85 ( V_76 , V_3 ) ;
F_19 ( V_3 -> V_4 . V_40 ) ;
F_20 ( V_3 -> V_4 . V_40 ) ;
return 0 ;
V_105:
F_86 ( V_3 -> V_7 ) ;
V_89:
if ( V_3 )
F_6 ( V_3 ) ;
V_84:
F_87 ( & V_76 -> V_40 ) ;
F_88 ( & V_76 -> V_40 ) ;
return V_64 ;
}
static int F_89 ( struct V_75 * V_76 )
{
struct V_1 * V_3 = F_90 ( V_76 ) ;
F_27 ( V_3 -> V_4 . V_40 ) ;
F_91 ( & V_3 -> V_4 ) ;
F_92 ( V_3 -> V_4 . V_40 , V_3 -> V_106 , V_3 -> V_7 ) ;
F_86 ( V_3 -> V_7 ) ;
F_6 ( V_3 ) ;
F_84 ( & V_76 -> V_40 , L_10 ) ;
F_93 ( & V_76 -> V_40 ) ;
F_88 ( & V_76 -> V_40 ) ;
return 0 ;
}
