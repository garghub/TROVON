static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
unsigned long V_9 = V_8 -> V_10 >> V_11 ;
int V_12 ;
V_9 += ( V_2 -> V_13 - V_2 -> V_5 -> V_14 ) >> V_11 ;
V_12 = F_3 ( V_2 -> V_5 , V_2 -> V_13 , V_9 ) ;
switch ( V_12 ) {
case 0 :
case - V_15 :
return V_16 ;
case - V_17 :
return V_18 ;
default:
return V_19 ;
}
}
static T_1 F_4 ( T_1 V_20 )
{
return F_5 ( V_20 , V_21 ) ;
}
void F_6 ( struct V_3 * V_8 )
{
struct V_7 * V_22 = F_2 ( V_8 ) ;
struct V_23 * V_24 = V_8 -> V_25 -> V_26 ;
F_7 ( L_1 , V_22 ) ;
F_8 ( & V_22 -> V_8 ) ;
F_9 ( & V_24 -> V_27 ) ;
if ( V_22 -> V_28 ) {
unsigned int V_29 = F_10 ( V_22 -> V_8 . V_20 ) ;
F_11 ( V_22 -> V_28 , V_29 ) ;
} else if ( V_22 -> V_30 ) {
F_12 ( & V_24 -> V_27 ) ;
F_13 ( V_22 -> V_30 ) ;
F_14 ( & V_24 -> V_27 ) ;
F_15 ( V_22 -> V_30 ) ;
if ( V_22 -> V_31 )
F_16 ( V_22 -> V_31 ) ;
}
if ( V_22 -> V_8 . V_32 ) {
if ( V_22 -> V_33 )
F_17 ( V_22 -> V_8 . V_32 ,
V_22 -> V_33 , V_34 ) ;
F_18 ( & V_22 -> V_8 , NULL ) ;
}
F_19 ( & V_22 -> V_8 ) ;
F_15 ( V_22 ) ;
}
int
F_20 ( struct V_35 * V_25 , struct V_7 * V_8 )
{
struct V_23 * V_24 = V_25 -> V_26 ;
T_1 V_20 = V_8 -> V_8 . V_20 ;
if ( V_8 -> V_28 || V_8 -> V_30 )
return 0 ;
if ( V_20 <= 8192 ) {
unsigned int V_29 = F_10 ( V_20 ) ;
struct V_28 * V_36 = F_21 ( V_37 , V_29 ) ;
if ( V_36 ) {
V_8 -> V_31 = F_22 ( V_36 ) ;
V_8 -> V_10 = F_23 ( V_36 ) ;
V_8 -> V_28 = V_36 ;
memset ( V_8 -> V_31 , 0 , F_24 ( V_20 ) ) ;
}
}
if ( ! V_8 -> V_28 ) {
struct V_38 * V_39 ;
unsigned V_40 = F_25 ( unsigned , V_20 , V_41 ) ;
void T_2 * V_42 ;
int V_12 ;
V_39 = F_26 ( sizeof( * V_39 ) , V_37 ) ;
if ( ! V_39 )
return - V_43 ;
F_12 ( & V_24 -> V_27 ) ;
V_12 = F_27 ( & V_24 -> V_30 , V_39 ,
V_20 , V_40 , 0 , 0 ) ;
F_14 ( & V_24 -> V_27 ) ;
if ( V_12 ) {
F_15 ( V_39 ) ;
return V_12 ;
}
V_8 -> V_30 = V_39 ;
V_42 = F_28 ( V_8 -> V_30 -> V_44 , V_20 ) ;
if ( ! V_42 ) {
F_12 ( & V_24 -> V_27 ) ;
F_13 ( V_8 -> V_30 ) ;
F_14 ( & V_24 -> V_27 ) ;
F_15 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
return - V_17 ;
}
F_29 ( V_42 , 0 , V_20 ) ;
F_16 ( V_42 ) ;
V_8 -> V_10 = V_8 -> V_30 -> V_44 ;
V_8 -> V_45 = V_8 -> V_30 -> V_44 ;
}
F_7 ( L_2 , V_8 ,
( unsigned long long ) V_8 -> V_10 ,
( unsigned long long ) V_8 -> V_45 ) ;
return 0 ;
}
void *
F_30 ( struct V_35 * V_25 , struct V_7 * V_22 )
{
if ( ! V_22 -> V_31 && V_22 -> V_30 )
V_22 -> V_31 = F_28 ( V_22 -> V_10 , V_22 -> V_8 . V_20 ) ;
return V_22 -> V_31 ;
}
struct V_7 *
F_31 ( struct V_35 * V_25 , T_1 V_20 )
{
struct V_7 * V_8 ;
V_20 = F_4 ( V_20 ) ;
V_8 = F_26 ( sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return NULL ;
F_32 ( V_25 , & V_8 -> V_8 , V_20 ) ;
V_8 -> V_45 = V_46 ;
F_7 ( L_3 , V_8 , V_20 ) ;
return V_8 ;
}
static struct V_7 * F_33 ( struct V_35 * V_25 ,
T_1 V_20 )
{
struct V_7 * V_8 ;
struct V_47 * V_48 ;
V_20 = F_4 ( V_20 ) ;
V_8 = F_26 ( sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return NULL ;
if ( F_34 ( V_25 , & V_8 -> V_8 , V_20 ) ) {
F_15 ( V_8 ) ;
return NULL ;
}
V_8 -> V_45 = V_46 ;
V_48 = V_8 -> V_8 . V_49 -> V_50 ;
F_35 ( V_48 , V_51 | V_52 ) ;
F_7 ( L_4 , V_8 , V_20 ) ;
return V_8 ;
}
int F_36 ( struct V_53 * V_54 , struct V_35 * V_25 ,
struct V_55 * args )
{
struct V_7 * V_22 ;
T_3 V_56 ;
T_1 V_20 ;
int V_12 ;
args -> V_57 = F_37 ( args -> V_58 , args -> V_59 ) ;
args -> V_20 = V_20 = args -> V_57 * args -> V_60 ;
V_22 = F_31 ( V_25 , V_20 ) ;
if ( V_22 == NULL )
return - V_17 ;
V_12 = F_20 ( V_25 , V_22 ) ;
if ( V_12 )
goto V_61;
V_12 = F_38 ( V_54 , & V_22 -> V_8 , & V_56 ) ;
if ( V_12 )
goto V_61;
args -> V_56 = V_56 ;
F_7 ( L_5 , V_22 , V_20 , V_56 ) ;
V_61:
F_39 ( & V_22 -> V_8 ) ;
return V_12 ;
}
int F_40 ( struct V_53 * V_54 , struct V_35 * V_25 ,
T_4 V_56 , T_5 * V_62 )
{
struct V_7 * V_8 ;
int V_12 = 0 ;
V_8 = F_41 ( V_54 , V_56 ) ;
if ( ! V_8 ) {
F_42 ( L_6 ) ;
return - V_63 ;
}
if ( V_8 -> V_8 . V_32 ) {
V_12 = - V_63 ;
goto V_64;
}
V_12 = F_43 ( & V_8 -> V_8 ) ;
if ( V_12 == 0 ) {
* V_62 = F_44 ( & V_8 -> V_8 . V_65 ) ;
F_7 ( L_7 , V_56 , * V_62 ) ;
}
V_64:
F_39 ( & V_8 -> V_8 ) ;
return V_12 ;
}
int F_45 ( struct V_53 * V_54 , struct V_35 * V_25 ,
T_4 V_56 )
{
return F_46 ( V_54 , V_56 ) ;
}
int F_47 ( struct V_35 * V_25 , void * V_66 ,
struct V_53 * V_54 )
{
struct V_67 * args = V_66 ;
struct V_7 * V_22 ;
T_1 V_20 ;
T_3 V_56 ;
int V_12 ;
if ( args -> V_20 == 0 )
return - V_17 ;
V_20 = args -> V_20 ;
V_22 = F_33 ( V_25 , V_20 ) ;
if ( V_22 == NULL )
return - V_17 ;
V_12 = F_38 ( V_54 , & V_22 -> V_8 , & V_56 ) ;
if ( V_12 )
goto V_61;
args -> V_56 = V_56 ;
F_7 ( L_5 , V_22 , V_20 , V_56 ) ;
V_61:
F_39 ( & V_22 -> V_8 ) ;
return V_12 ;
}
int F_48 ( struct V_35 * V_25 , void * V_66 ,
struct V_53 * V_54 )
{
struct V_68 * args = V_66 ;
struct V_7 * V_22 ;
unsigned long V_31 ;
V_22 = F_41 ( V_54 , args -> V_56 ) ;
if ( V_22 == NULL )
return - V_69 ;
if ( ! V_22 -> V_8 . V_49 ) {
F_39 ( & V_22 -> V_8 ) ;
return - V_63 ;
}
V_31 = F_49 ( V_22 -> V_8 . V_49 , 0 , args -> V_20 , V_70 | V_71 ,
V_72 , args -> V_62 ) ;
F_39 ( & V_22 -> V_8 ) ;
if ( F_50 ( V_31 ) )
return V_31 ;
args -> V_31 = V_31 ;
return 0 ;
}
int F_51 ( struct V_35 * V_25 , void * V_66 ,
struct V_53 * V_54 )
{
struct V_73 * args = V_66 ;
struct V_7 * V_22 ;
char T_6 * V_42 ;
int V_12 ;
F_7 ( L_8 ,
args -> V_56 , args -> V_62 , args -> V_20 , args -> V_42 ) ;
if ( args -> V_20 == 0 )
return 0 ;
V_42 = ( char T_6 * ) ( V_74 ) args -> V_42 ;
if ( ! F_52 ( V_75 , V_42 , args -> V_20 ) )
return - V_76 ;
V_12 = F_53 ( V_42 , args -> V_20 ) ;
if ( V_12 )
return V_12 ;
V_22 = F_41 ( V_54 , args -> V_56 ) ;
if ( V_22 == NULL )
return - V_69 ;
if ( ! V_22 -> V_31 )
return - V_63 ;
if ( args -> V_62 > V_22 -> V_8 . V_20 ||
args -> V_20 > V_22 -> V_8 . V_20 - args -> V_62 ) {
F_42 ( L_9 , V_22 -> V_8 . V_20 ) ;
V_12 = - V_63 ;
goto V_77;
}
if ( F_54 ( V_22 -> V_31 + args -> V_62 , V_42 , args -> V_20 ) ) {
V_12 = - V_76 ;
} else if ( V_22 -> V_78 ) {
V_22 -> V_78 ( V_22 -> V_79 ) ;
V_12 = 0 ;
}
V_77:
F_39 ( & V_22 -> V_8 ) ;
return V_12 ;
}
static struct V_80 *
F_55 ( struct V_81 * V_82 ,
enum V_83 V_84 )
{
struct V_3 * V_8 = V_82 -> V_85 -> V_24 ;
struct V_7 * V_22 = F_2 ( V_8 ) ;
struct V_86 * V_87 ;
struct V_80 * V_33 ;
int V_88 , V_89 ;
V_33 = F_56 ( sizeof( * V_33 ) , V_37 ) ;
if ( ! V_33 )
return NULL ;
if ( V_22 -> V_8 . V_49 ) {
struct V_47 * V_48 ;
int V_90 ;
V_90 = V_22 -> V_8 . V_20 / V_21 ;
if ( F_57 ( V_33 , V_90 , V_37 ) )
goto V_91;
V_48 = V_22 -> V_8 . V_49 -> V_50 ;
F_58 (sgt->sgl, sg, count, i) {
struct V_28 * V_28 ;
V_28 = F_59 ( V_48 , V_88 ) ;
if ( F_60 ( V_28 ) ) {
V_89 = V_88 ;
goto V_92;
}
F_61 ( V_87 , V_28 , V_21 , 0 ) ;
}
if ( F_62 ( V_82 -> V_25 , V_33 -> V_93 , V_33 -> V_94 , V_84 ) == 0 ) {
V_89 = V_33 -> V_94 ;
goto V_92;
}
} else if ( V_22 -> V_28 ) {
if ( F_57 ( V_33 , 1 , V_37 ) )
goto V_91;
F_61 ( V_33 -> V_93 , V_22 -> V_28 , V_22 -> V_8 . V_20 , 0 ) ;
if ( F_62 ( V_82 -> V_25 , V_33 -> V_93 , V_33 -> V_94 , V_84 ) == 0 )
goto V_95;
} else if ( V_22 -> V_30 ) {
if ( F_57 ( V_33 , 1 , V_37 ) )
goto V_91;
F_63 ( V_33 -> V_93 ) = V_22 -> V_45 ;
F_64 ( V_33 -> V_93 ) = V_22 -> V_8 . V_20 ;
} else {
goto V_91;
}
return V_33 ;
V_92:
F_58 (sgt->sgl, sg, num, i)
F_65 ( F_66 ( V_87 ) ) ;
V_95:
F_67 ( V_33 ) ;
V_91:
F_15 ( V_33 ) ;
return NULL ;
}
static void F_68 ( struct V_81 * V_82 ,
struct V_80 * V_33 , enum V_83 V_84 )
{
struct V_3 * V_8 = V_82 -> V_85 -> V_24 ;
struct V_7 * V_22 = F_2 ( V_8 ) ;
int V_88 ;
if ( ! V_22 -> V_30 )
F_69 ( V_82 -> V_25 , V_33 -> V_93 , V_33 -> V_94 , V_84 ) ;
if ( V_22 -> V_8 . V_49 ) {
struct V_86 * V_87 ;
F_58 (sgt->sgl, sg, sgt->nents, i)
F_65 ( F_66 ( V_87 ) ) ;
}
F_67 ( V_33 ) ;
F_15 ( V_33 ) ;
}
static void * F_70 ( struct V_96 * V_97 , unsigned long V_98 )
{
return NULL ;
}
static void
F_71 ( struct V_96 * V_97 , unsigned long V_98 , void * V_31 )
{
}
static int
F_72 ( struct V_96 * V_97 , struct V_99 * V_5 )
{
return - V_63 ;
}
struct V_96 *
F_73 ( struct V_35 * V_25 , struct V_3 * V_8 ,
int V_100 )
{
F_74 ( V_101 ) ;
V_101 . V_102 = & V_103 ;
V_101 . V_20 = V_8 -> V_20 ;
V_101 . V_100 = V_104 ;
V_101 . V_24 = V_8 ;
return F_75 ( V_25 , & V_101 ) ;
}
struct V_3 *
F_76 ( struct V_35 * V_25 , struct V_96 * V_97 )
{
struct V_81 * V_82 ;
struct V_7 * V_22 ;
if ( V_97 -> V_102 == & V_103 ) {
struct V_3 * V_8 = V_97 -> V_24 ;
if ( V_8 -> V_25 == V_25 ) {
F_77 ( V_8 ) ;
return V_8 ;
}
}
V_82 = F_78 ( V_97 , V_25 -> V_25 ) ;
if ( F_60 ( V_82 ) )
return F_79 ( V_82 ) ;
V_22 = F_31 ( V_25 , V_97 -> V_20 ) ;
if ( ! V_22 ) {
F_80 ( V_97 , V_82 ) ;
return F_81 ( - V_17 ) ;
}
V_22 -> V_8 . V_32 = V_82 ;
F_82 ( V_97 ) ;
return & V_22 -> V_8 ;
}
int F_83 ( struct V_7 * V_22 )
{
int V_12 ;
V_22 -> V_33 = F_84 ( V_22 -> V_8 . V_32 ,
V_34 ) ;
if ( F_60 ( V_22 -> V_33 ) ) {
V_12 = F_85 ( V_22 -> V_33 ) ;
V_22 -> V_33 = NULL ;
F_42 ( L_10 , V_12 ) ;
return V_12 ;
}
if ( V_22 -> V_33 -> V_94 > 1 ) {
F_42 ( L_11 ) ;
return - V_63 ;
}
if ( F_64 ( V_22 -> V_33 -> V_93 ) < V_22 -> V_8 . V_20 ) {
F_42 ( L_12 ) ;
return - V_63 ;
}
V_22 -> V_45 = F_63 ( V_22 -> V_33 -> V_93 ) ;
return 0 ;
}
