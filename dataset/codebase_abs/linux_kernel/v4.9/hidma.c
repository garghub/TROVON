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
struct V_12 * V_22 ;
unsigned long V_23 ;
struct V_24 V_25 ;
F_7 ( & V_25 ) ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_10 ( & V_17 -> V_27 , & V_25 ) ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
F_12 (mdesc, next, &list, node) {
enum V_28 V_29 ;
struct V_30 V_31 ;
struct V_32 V_33 ;
V_15 = & V_21 -> V_15 ;
V_20 = V_15 -> V_34 ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_13 ( V_15 ) ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
V_29 = F_14 ( V_19 -> V_7 , V_21 -> V_35 ) ;
F_15 ( V_15 , & V_31 ) ;
F_16 ( V_15 ) ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_17 ( & V_21 -> V_36 , & V_17 -> free ) ;
if ( V_29 == V_37 ) {
V_17 -> V_38 = V_20 ;
V_33 . V_33 = V_39 ;
} else
V_33 . V_33 = V_40 ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
F_18 ( & V_31 , & V_33 ) ;
}
}
static void F_19 ( void * V_41 )
{
struct V_12 * V_21 = V_41 ;
struct V_8 * V_17 = F_4 ( V_21 -> V_15 . V_11 ) ;
struct V_2 * V_4 = V_17 -> V_11 . V_18 ;
struct V_1 * V_3 = F_1 ( V_4 ) ;
unsigned long V_23 ;
bool V_42 = false ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
if ( V_21 -> V_36 . V_22 ) {
F_20 ( & V_21 -> V_36 , & V_17 -> V_27 ) ;
V_42 = true ;
V_17 -> V_43 = F_21 ( & V_17 -> V_44 ,
struct V_12 , V_36 ) ;
}
F_11 ( & V_17 -> V_26 , V_23 ) ;
F_8 ( V_17 ) ;
if ( V_42 ) {
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
}
}
static int F_24 ( struct V_1 * V_3 , T_2 V_46 )
{
struct V_8 * V_17 ;
struct V_2 * V_4 ;
V_17 = F_25 ( V_3 -> V_4 . V_45 , sizeof( * V_17 ) , V_47 ) ;
if ( ! V_17 )
return - V_48 ;
V_4 = & V_3 -> V_4 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_3 = V_3 ;
V_17 -> V_11 . V_18 = V_4 ;
F_26 ( & V_17 -> V_11 ) ;
F_7 ( & V_17 -> free ) ;
F_7 ( & V_17 -> V_49 ) ;
F_7 ( & V_17 -> V_44 ) ;
F_7 ( & V_17 -> V_27 ) ;
F_27 ( & V_17 -> V_26 ) ;
F_28 ( & V_17 -> V_11 . V_50 , & V_4 -> V_16 ) ;
V_3 -> V_4 . V_51 ++ ;
return 0 ;
}
static void F_29 ( unsigned long V_52 )
{
struct V_1 * V_3 = (struct V_1 * ) V_52 ;
F_30 ( V_3 -> V_4 . V_45 ) ;
F_31 ( V_3 -> V_7 ) ;
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_1 * V_3 = V_17 -> V_3 ;
unsigned long V_53 ;
int V_54 ;
F_9 ( & V_17 -> V_26 , V_53 ) ;
if ( ! V_17 -> V_43 ) {
struct V_12 * V_15 = F_21 ( & V_17 -> V_44 ,
struct V_12 ,
V_36 ) ;
V_17 -> V_43 = V_15 ;
}
F_11 ( & V_17 -> V_26 , V_53 ) ;
V_54 = F_33 ( V_3 -> V_4 . V_45 ) ;
if ( V_54 < 0 )
F_34 ( & V_3 -> V_55 ) ;
else
F_31 ( V_3 -> V_7 ) ;
}
static inline bool F_35 ( T_1 V_34 ,
T_1 V_38 , T_1 V_56 )
{
if ( V_38 <= V_56 ) {
if ( ( V_34 <= V_38 ) || ( V_34 > V_56 ) )
return true ;
} else {
if ( ( V_34 <= V_38 ) && ( V_34 > V_56 ) )
return true ;
}
return false ;
}
static enum V_28 F_36 ( struct V_9 * V_10 ,
T_1 V_34 ,
struct V_57 * V_58 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
enum V_28 V_59 ;
V_59 = F_37 ( V_10 , V_34 , V_58 ) ;
if ( V_59 == V_37 ) {
bool V_60 ;
V_60 = F_35 ( V_34 , V_17 -> V_38 ,
V_10 -> V_34 ) ;
return V_60 ? V_59 : V_61 ;
}
if ( V_17 -> V_62 && ( V_59 == V_63 ) ) {
unsigned long V_53 ;
T_1 V_64 ;
F_9 ( & V_17 -> V_26 , V_53 ) ;
if ( V_17 -> V_43 )
V_64 = V_17 -> V_43 -> V_15 . V_34 ;
else
V_64 = - V_65 ;
if ( V_64 == V_34 )
V_59 = V_66 ;
F_11 ( & V_17 -> V_26 , V_53 ) ;
}
return V_59 ;
}
static T_1 F_38 ( struct V_13 * V_67 )
{
struct V_8 * V_17 = F_4 ( V_67 -> V_11 ) ;
struct V_1 * V_3 = V_17 -> V_3 ;
struct V_12 * V_21 ;
unsigned long V_23 ;
T_1 V_34 ;
F_30 ( V_3 -> V_4 . V_45 ) ;
if ( ! F_39 ( V_3 -> V_7 ) ) {
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
return - V_68 ;
}
V_21 = F_2 ( V_67 , struct V_12 , V_15 ) ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_20 ( & V_21 -> V_36 , & V_17 -> V_44 ) ;
V_34 = F_40 ( V_67 ) ;
F_41 ( V_3 -> V_7 , V_21 -> V_35 ) ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
return V_34 ;
}
static int F_42 ( struct V_9 * V_10 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_1 * V_3 = V_17 -> V_3 ;
struct V_12 * V_21 , * V_69 ;
unsigned long V_23 ;
F_43 ( V_70 ) ;
unsigned int V_71 ;
int V_72 = 0 ;
if ( V_17 -> V_73 )
return 0 ;
for ( V_71 = 0 ; V_71 < V_3 -> V_74 ; V_71 ++ ) {
V_21 = F_44 ( sizeof( struct V_12 ) , V_75 ) ;
if ( ! V_21 ) {
V_72 = - V_48 ;
break;
}
F_45 ( & V_21 -> V_15 , V_10 ) ;
V_21 -> V_15 . V_76 = F_38 ;
V_72 = F_46 ( V_3 -> V_7 , V_17 -> V_46 ,
L_1 , F_19 , V_21 ,
& V_21 -> V_35 ) ;
if ( V_72 ) {
F_47 ( V_10 -> V_18 -> V_45 ,
L_2 , V_71 ) ;
F_48 ( V_21 ) ;
break;
}
F_28 ( & V_21 -> V_36 , & V_70 ) ;
}
if ( V_72 ) {
F_12 (mdesc, tmp, &descs, node) {
F_49 ( V_3 -> V_7 , V_21 -> V_35 ) ;
F_48 ( V_21 ) ;
}
return V_72 ;
}
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_10 ( & V_70 , & V_17 -> free ) ;
V_17 -> V_73 = true ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
return 1 ;
}
static struct V_13 *
F_50 ( struct V_9 * V_10 , T_3 V_77 , T_3 V_78 ,
T_4 V_79 , unsigned long V_53 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_12 * V_21 = NULL ;
struct V_1 * V_19 = V_17 -> V_3 ;
unsigned long V_23 ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
if ( ! F_51 ( & V_17 -> free ) ) {
V_21 = F_21 ( & V_17 -> free , struct V_12 , V_36 ) ;
F_52 ( & V_21 -> V_36 ) ;
}
F_11 ( & V_17 -> V_26 , V_23 ) ;
if ( ! V_21 )
return NULL ;
F_53 ( V_19 -> V_7 , V_21 -> V_35 ,
V_78 , V_77 , V_79 , V_53 ) ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_28 ( & V_21 -> V_36 , & V_17 -> V_49 ) ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
return & V_21 -> V_15 ;
}
static int F_54 ( struct V_9 * V_11 )
{
struct V_8 * V_17 = F_4 ( V_11 ) ;
struct V_1 * V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
struct V_12 * V_69 , * V_21 ;
unsigned long V_23 ;
F_43 ( V_25 ) ;
int V_72 ;
F_30 ( V_3 -> V_4 . V_45 ) ;
F_8 ( V_17 ) ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
V_17 -> V_38 = 0 ;
F_55 ( & V_17 -> V_44 , & V_25 ) ;
F_55 ( & V_17 -> V_49 , & V_25 ) ;
F_55 ( & V_17 -> V_27 , & V_25 ) ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
V_72 = F_56 ( V_3 -> V_7 ) ;
if ( V_72 ) {
F_47 ( V_3 -> V_4 . V_45 , L_3 ) ;
goto V_80;
}
F_12 (mdesc, tmp, &list, node) {
struct V_13 * V_67 = & V_21 -> V_15 ;
F_57 ( V_67 ) ;
F_58 ( V_67 , NULL ) ;
F_16 ( V_67 ) ;
F_17 ( & V_21 -> V_36 , & V_17 -> free ) ;
}
V_72 = F_59 ( V_3 -> V_7 ) ;
V_80:
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
return V_72 ;
}
static int F_60 ( struct V_9 * V_11 )
{
struct V_8 * V_17 = F_4 ( V_11 ) ;
struct V_1 * V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
int V_72 ;
V_72 = F_54 ( V_11 ) ;
if ( V_72 )
return V_72 ;
F_30 ( V_3 -> V_4 . V_45 ) ;
V_72 = F_61 ( V_3 -> V_7 ) ;
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
return V_72 ;
}
static void F_62 ( struct V_9 * V_10 )
{
struct V_8 * V_17 = F_4 ( V_10 ) ;
struct V_1 * V_19 = V_17 -> V_3 ;
struct V_12 * V_21 , * V_69 ;
unsigned long V_23 ;
F_43 ( V_70 ) ;
F_54 ( V_10 ) ;
F_9 ( & V_17 -> V_26 , V_23 ) ;
F_10 ( & V_17 -> free , & V_70 ) ;
F_12 (mdesc, tmp, &descs, node) {
F_49 ( V_19 -> V_7 , V_21 -> V_35 ) ;
F_52 ( & V_21 -> V_36 ) ;
F_48 ( V_21 ) ;
}
V_17 -> V_73 = 0 ;
F_11 ( & V_17 -> V_26 , V_23 ) ;
}
static int F_63 ( struct V_9 * V_11 )
{
struct V_8 * V_17 ;
struct V_1 * V_3 ;
V_17 = F_4 ( V_11 ) ;
V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
if ( ! V_17 -> V_62 ) {
F_30 ( V_3 -> V_4 . V_45 ) ;
if ( F_56 ( V_3 -> V_7 ) )
F_64 ( V_3 -> V_4 . V_45 , L_4 ) ;
V_17 -> V_62 = true ;
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
}
return 0 ;
}
static int F_65 ( struct V_9 * V_11 )
{
struct V_8 * V_17 ;
struct V_1 * V_3 ;
int V_72 = 0 ;
V_17 = F_4 ( V_11 ) ;
V_3 = F_1 ( V_17 -> V_11 . V_18 ) ;
if ( V_17 -> V_62 ) {
F_30 ( V_3 -> V_4 . V_45 ) ;
V_72 = F_59 ( V_3 -> V_7 ) ;
if ( ! V_72 )
V_17 -> V_62 = false ;
else
F_47 ( V_3 -> V_4 . V_45 ,
L_5 ) ;
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
}
return V_72 ;
}
static T_5 F_66 ( int V_81 , void * V_52 )
{
struct V_5 * V_7 = V_52 ;
return F_67 ( V_81 , V_7 ) ;
}
static T_6 F_68 ( struct V_18 * V_45 ,
struct V_82 * V_83 , char * V_84 )
{
struct V_85 * V_86 = F_69 ( V_45 ) ;
struct V_1 * V_87 = F_70 ( V_86 ) ;
V_84 [ 0 ] = 0 ;
if ( strcmp ( V_83 -> V_83 . V_88 , L_6 ) == 0 )
sprintf ( V_84 , L_7 , V_87 -> V_89 ) ;
return strlen ( V_84 ) ;
}
static int F_71 ( struct V_1 * V_45 , char * V_88 ,
int V_90 )
{
struct V_82 * V_91 ;
char * V_92 ;
V_91 = F_72 ( V_45 -> V_4 . V_45 , sizeof( struct V_82 ) ,
V_47 ) ;
if ( ! V_91 )
return - V_48 ;
V_92 = F_73 ( V_45 -> V_4 . V_45 , V_88 , V_47 ) ;
if ( ! V_92 )
return - V_48 ;
V_91 -> V_83 . V_88 = V_92 ;
V_91 -> V_83 . V_90 = V_90 ;
V_91 -> V_93 = F_68 ;
F_74 ( & V_91 -> V_83 ) ;
return F_75 ( V_45 -> V_4 . V_45 , V_91 ) ;
}
static int F_76 ( struct V_85 * V_86 )
{
struct V_1 * V_3 ;
struct V_94 * V_95 ;
struct V_94 * V_96 ;
int V_81 ;
void T_7 * V_97 ;
void T_7 * V_98 ;
int V_72 ;
F_77 ( & V_86 -> V_45 , V_99 ) ;
F_78 ( & V_86 -> V_45 ) ;
F_79 ( & V_86 -> V_45 ) ;
F_80 ( & V_86 -> V_45 ) ;
V_95 = F_81 ( V_86 , V_100 , 0 ) ;
V_98 = F_82 ( & V_86 -> V_45 , V_95 ) ;
if ( F_83 ( V_98 ) ) {
V_72 = - V_48 ;
goto V_101;
}
V_96 = F_81 ( V_86 , V_100 , 1 ) ;
V_97 = F_82 ( & V_86 -> V_45 , V_96 ) ;
if ( F_83 ( V_97 ) ) {
V_72 = - V_48 ;
goto V_101;
}
V_81 = F_84 ( V_86 , 0 ) ;
if ( V_81 < 0 ) {
V_72 = - V_68 ;
goto V_101;
}
V_3 = F_25 ( & V_86 -> V_45 , sizeof( * V_3 ) , V_47 ) ;
if ( ! V_3 ) {
V_72 = - V_48 ;
goto V_101;
}
F_7 ( & V_3 -> V_4 . V_16 ) ;
F_27 ( & V_3 -> V_26 ) ;
V_3 -> V_4 . V_45 = & V_86 -> V_45 ;
F_30 ( V_3 -> V_4 . V_45 ) ;
F_85 ( V_102 , V_3 -> V_4 . V_103 ) ;
if ( F_86 ( ! V_86 -> V_45 . V_104 ) ) {
V_72 = - V_105 ;
goto V_106;
}
V_3 -> V_107 = V_97 ;
V_3 -> V_96 = V_96 ;
V_3 -> V_108 = V_98 ;
V_3 -> V_95 = V_95 ;
V_3 -> V_4 . V_109 = F_50 ;
V_3 -> V_4 . V_110 = F_42 ;
V_3 -> V_4 . V_111 = F_62 ;
V_3 -> V_4 . V_112 = F_36 ;
V_3 -> V_4 . V_113 = F_32 ;
V_3 -> V_4 . V_114 = F_63 ;
V_3 -> V_4 . V_115 = F_65 ;
V_3 -> V_4 . V_116 = F_60 ;
V_3 -> V_4 . V_117 = 8 ;
F_87 ( & V_86 -> V_45 , L_8 ,
& V_3 -> V_74 ) ;
if ( ! V_3 -> V_74 && V_118 )
V_3 -> V_74 = V_118 ;
if ( ! V_3 -> V_74 )
V_3 -> V_74 = V_119 ;
V_3 -> V_89 = F_88 ( V_3 -> V_108 + 0x28 ) ;
V_72 = F_89 ( & V_86 -> V_45 , F_90 ( 64 ) ) ;
if ( V_72 ) {
F_64 ( & V_86 -> V_45 , L_9 ) ;
V_72 = F_89 ( & V_86 -> V_45 , F_90 ( 32 ) ) ;
if ( V_72 )
goto V_106;
}
V_3 -> V_7 = F_91 ( V_3 -> V_4 . V_45 ,
V_3 -> V_74 , V_3 -> V_108 ,
V_3 -> V_107 , V_3 -> V_89 ) ;
if ( ! V_3 -> V_7 ) {
V_72 = - V_120 ;
goto V_106;
}
V_72 = F_92 ( & V_86 -> V_45 , V_81 , F_66 , 0 ,
L_10 , V_3 -> V_7 ) ;
if ( V_72 )
goto V_121;
F_7 ( & V_3 -> V_4 . V_16 ) ;
V_72 = F_24 ( V_3 , 0 ) ;
if ( V_72 )
goto V_121;
V_72 = F_93 ( & V_3 -> V_4 ) ;
if ( V_72 )
goto V_121;
V_3 -> V_122 = V_81 ;
F_94 ( & V_3 -> V_55 , F_29 , ( unsigned long ) V_3 ) ;
F_95 ( V_3 ) ;
F_71 ( V_3 , L_6 , V_123 ) ;
F_96 ( & V_86 -> V_45 , L_11 ) ;
F_97 ( V_86 , V_3 ) ;
F_22 ( V_3 -> V_4 . V_45 ) ;
F_23 ( V_3 -> V_4 . V_45 ) ;
return 0 ;
V_121:
F_98 ( V_3 ) ;
F_99 ( V_3 -> V_7 ) ;
V_106:
if ( V_3 )
F_6 ( V_3 ) ;
V_101:
F_100 ( & V_86 -> V_45 ) ;
F_101 ( & V_86 -> V_45 ) ;
return V_72 ;
}
static int F_102 ( struct V_85 * V_86 )
{
struct V_1 * V_3 = F_70 ( V_86 ) ;
F_30 ( V_3 -> V_4 . V_45 ) ;
F_103 ( & V_3 -> V_4 ) ;
F_104 ( V_3 -> V_4 . V_45 , V_3 -> V_122 , V_3 -> V_7 ) ;
F_105 ( & V_3 -> V_55 ) ;
F_98 ( V_3 ) ;
F_99 ( V_3 -> V_7 ) ;
F_6 ( V_3 ) ;
F_96 ( & V_86 -> V_45 , L_12 ) ;
F_106 ( & V_86 -> V_45 ) ;
F_101 ( & V_86 -> V_45 ) ;
return 0 ;
}
