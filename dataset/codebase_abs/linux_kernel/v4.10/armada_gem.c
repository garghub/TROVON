static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
unsigned long V_8 = V_6 -> V_9 >> V_10 ;
int V_11 ;
V_8 += ( V_4 -> V_12 - V_2 -> V_13 ) >> V_10 ;
V_11 = F_3 ( V_2 , V_4 -> V_12 , V_8 ) ;
switch ( V_11 ) {
case 0 :
case - V_14 :
return V_15 ;
case - V_16 :
return V_17 ;
default:
return V_18 ;
}
}
static T_1 F_4 ( T_1 V_19 )
{
return F_5 ( V_19 , V_20 ) ;
}
void F_6 ( struct V_21 * V_6 )
{
struct V_5 * V_22 = F_2 ( V_6 ) ;
struct V_23 * V_24 = V_6 -> V_25 -> V_26 ;
F_7 ( L_1 , V_22 ) ;
F_8 ( & V_22 -> V_6 ) ;
F_9 ( & V_24 -> V_27 ) ;
if ( V_22 -> V_28 ) {
unsigned int V_29 = F_10 ( V_22 -> V_6 . V_19 ) ;
F_11 ( V_22 -> V_28 , V_29 ) ;
} else if ( V_22 -> V_30 ) {
F_12 ( & V_24 -> V_27 ) ;
F_13 ( V_22 -> V_30 ) ;
F_14 ( & V_24 -> V_27 ) ;
F_15 ( V_22 -> V_30 ) ;
if ( V_22 -> V_31 )
F_16 ( V_22 -> V_31 ) ;
}
if ( V_22 -> V_6 . V_32 ) {
if ( V_22 -> V_33 )
F_17 ( V_22 -> V_6 . V_32 ,
V_22 -> V_33 , V_34 ) ;
F_18 ( & V_22 -> V_6 , NULL ) ;
}
F_19 ( & V_22 -> V_6 ) ;
F_15 ( V_22 ) ;
}
int
F_20 ( struct V_35 * V_25 , struct V_5 * V_6 )
{
struct V_23 * V_24 = V_25 -> V_26 ;
T_1 V_19 = V_6 -> V_6 . V_19 ;
if ( V_6 -> V_28 || V_6 -> V_30 )
return 0 ;
if ( V_19 <= 8192 ) {
unsigned int V_29 = F_10 ( V_19 ) ;
struct V_28 * V_36 = F_21 ( V_37 , V_29 ) ;
if ( V_36 ) {
V_6 -> V_31 = F_22 ( V_36 ) ;
V_6 -> V_9 = F_23 ( V_36 ) ;
V_6 -> V_28 = V_36 ;
memset ( V_6 -> V_31 , 0 , F_24 ( V_19 ) ) ;
}
}
if ( ! V_6 -> V_28 ) {
struct V_38 * V_39 ;
unsigned V_40 = F_25 ( unsigned , V_19 , V_41 ) ;
void T_2 * V_42 ;
int V_11 ;
V_39 = F_26 ( sizeof( * V_39 ) , V_37 ) ;
if ( ! V_39 )
return - V_43 ;
F_12 ( & V_24 -> V_27 ) ;
V_11 = F_27 ( & V_24 -> V_30 , V_39 , V_19 , V_40 ,
V_44 ) ;
F_14 ( & V_24 -> V_27 ) ;
if ( V_11 ) {
F_15 ( V_39 ) ;
return V_11 ;
}
V_6 -> V_30 = V_39 ;
V_42 = F_28 ( V_6 -> V_30 -> V_45 , V_19 ) ;
if ( ! V_42 ) {
F_12 ( & V_24 -> V_27 ) ;
F_13 ( V_6 -> V_30 ) ;
F_14 ( & V_24 -> V_27 ) ;
F_15 ( V_6 -> V_30 ) ;
V_6 -> V_30 = NULL ;
return - V_16 ;
}
F_29 ( V_42 , 0 , V_19 ) ;
F_16 ( V_42 ) ;
V_6 -> V_9 = V_6 -> V_30 -> V_45 ;
V_6 -> V_46 = V_6 -> V_30 -> V_45 ;
}
F_7 ( L_2 , V_6 ,
( unsigned long long ) V_6 -> V_9 ,
( unsigned long long ) V_6 -> V_46 ) ;
return 0 ;
}
void *
F_30 ( struct V_35 * V_25 , struct V_5 * V_22 )
{
if ( ! V_22 -> V_31 && V_22 -> V_30 )
V_22 -> V_31 = F_28 ( V_22 -> V_9 , V_22 -> V_6 . V_19 ) ;
return V_22 -> V_31 ;
}
struct V_5 *
F_31 ( struct V_35 * V_25 , T_1 V_19 )
{
struct V_5 * V_6 ;
V_19 = F_4 ( V_19 ) ;
V_6 = F_26 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return NULL ;
F_32 ( V_25 , & V_6 -> V_6 , V_19 ) ;
V_6 -> V_46 = V_47 ;
F_7 ( L_3 , V_6 , V_19 ) ;
return V_6 ;
}
static struct V_5 * F_33 ( struct V_35 * V_25 ,
T_1 V_19 )
{
struct V_5 * V_6 ;
struct V_48 * V_49 ;
V_19 = F_4 ( V_19 ) ;
V_6 = F_26 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return NULL ;
if ( F_34 ( V_25 , & V_6 -> V_6 , V_19 ) ) {
F_15 ( V_6 ) ;
return NULL ;
}
V_6 -> V_46 = V_47 ;
V_49 = V_6 -> V_6 . V_50 -> V_51 ;
F_35 ( V_49 , V_52 | V_53 ) ;
F_7 ( L_4 , V_6 , V_19 ) ;
return V_6 ;
}
int F_36 ( struct V_54 * V_55 , struct V_35 * V_25 ,
struct V_56 * args )
{
struct V_5 * V_22 ;
T_3 V_57 ;
T_1 V_19 ;
int V_11 ;
args -> V_58 = F_37 ( args -> V_59 , args -> V_60 ) ;
args -> V_19 = V_19 = args -> V_58 * args -> V_61 ;
V_22 = F_31 ( V_25 , V_19 ) ;
if ( V_22 == NULL )
return - V_16 ;
V_11 = F_20 ( V_25 , V_22 ) ;
if ( V_11 )
goto V_62;
V_11 = F_38 ( V_55 , & V_22 -> V_6 , & V_57 ) ;
if ( V_11 )
goto V_62;
args -> V_57 = V_57 ;
F_7 ( L_5 , V_22 , V_19 , V_57 ) ;
V_62:
F_39 ( & V_22 -> V_6 ) ;
return V_11 ;
}
int F_40 ( struct V_54 * V_55 , struct V_35 * V_25 ,
T_4 V_57 , T_5 * V_63 )
{
struct V_5 * V_6 ;
int V_11 = 0 ;
V_6 = F_41 ( V_55 , V_57 ) ;
if ( ! V_6 ) {
F_42 ( L_6 ) ;
return - V_64 ;
}
if ( V_6 -> V_6 . V_32 ) {
V_11 = - V_64 ;
goto V_65;
}
V_11 = F_43 ( & V_6 -> V_6 ) ;
if ( V_11 == 0 ) {
* V_63 = F_44 ( & V_6 -> V_6 . V_66 ) ;
F_7 ( L_7 , V_57 , * V_63 ) ;
}
V_65:
F_39 ( & V_6 -> V_6 ) ;
return V_11 ;
}
int F_45 ( struct V_54 * V_55 , struct V_35 * V_25 ,
T_4 V_57 )
{
return F_46 ( V_55 , V_57 ) ;
}
int F_47 ( struct V_35 * V_25 , void * V_67 ,
struct V_54 * V_55 )
{
struct V_68 * args = V_67 ;
struct V_5 * V_22 ;
T_1 V_19 ;
T_3 V_57 ;
int V_11 ;
if ( args -> V_19 == 0 )
return - V_16 ;
V_19 = args -> V_19 ;
V_22 = F_33 ( V_25 , V_19 ) ;
if ( V_22 == NULL )
return - V_16 ;
V_11 = F_38 ( V_55 , & V_22 -> V_6 , & V_57 ) ;
if ( V_11 )
goto V_62;
args -> V_57 = V_57 ;
F_7 ( L_5 , V_22 , V_19 , V_57 ) ;
V_62:
F_39 ( & V_22 -> V_6 ) ;
return V_11 ;
}
int F_48 ( struct V_35 * V_25 , void * V_67 ,
struct V_54 * V_55 )
{
struct V_69 * args = V_67 ;
struct V_5 * V_22 ;
unsigned long V_31 ;
V_22 = F_41 ( V_55 , args -> V_57 ) ;
if ( V_22 == NULL )
return - V_70 ;
if ( ! V_22 -> V_6 . V_50 ) {
F_39 ( & V_22 -> V_6 ) ;
return - V_64 ;
}
V_31 = F_49 ( V_22 -> V_6 . V_50 , 0 , args -> V_19 , V_71 | V_72 ,
V_73 , args -> V_63 ) ;
F_39 ( & V_22 -> V_6 ) ;
if ( F_50 ( V_31 ) )
return V_31 ;
args -> V_31 = V_31 ;
return 0 ;
}
int F_51 ( struct V_35 * V_25 , void * V_67 ,
struct V_54 * V_55 )
{
struct V_74 * args = V_67 ;
struct V_5 * V_22 ;
char T_6 * V_42 ;
int V_11 ;
F_7 ( L_8 ,
args -> V_57 , args -> V_63 , args -> V_19 , args -> V_42 ) ;
if ( args -> V_19 == 0 )
return 0 ;
V_42 = ( char T_6 * ) ( V_75 ) args -> V_42 ;
if ( ! F_52 ( V_76 , V_42 , args -> V_19 ) )
return - V_77 ;
V_11 = F_53 ( V_42 , args -> V_19 ) ;
if ( V_11 )
return V_11 ;
V_22 = F_41 ( V_55 , args -> V_57 ) ;
if ( V_22 == NULL )
return - V_70 ;
if ( ! V_22 -> V_31 )
return - V_64 ;
if ( args -> V_63 > V_22 -> V_6 . V_19 ||
args -> V_19 > V_22 -> V_6 . V_19 - args -> V_63 ) {
F_42 ( L_9 , V_22 -> V_6 . V_19 ) ;
V_11 = - V_64 ;
goto V_78;
}
if ( F_54 ( V_22 -> V_31 + args -> V_63 , V_42 , args -> V_19 ) ) {
V_11 = - V_77 ;
} else if ( V_22 -> V_79 ) {
V_22 -> V_79 ( V_22 -> V_80 ) ;
V_11 = 0 ;
}
V_78:
F_39 ( & V_22 -> V_6 ) ;
return V_11 ;
}
static struct V_81 *
F_55 ( struct V_82 * V_83 ,
enum V_84 V_85 )
{
struct V_21 * V_6 = V_83 -> V_86 -> V_24 ;
struct V_5 * V_22 = F_2 ( V_6 ) ;
struct V_87 * V_88 ;
struct V_81 * V_33 ;
int V_89 , V_90 ;
V_33 = F_56 ( sizeof( * V_33 ) , V_37 ) ;
if ( ! V_33 )
return NULL ;
if ( V_22 -> V_6 . V_50 ) {
struct V_48 * V_49 ;
int V_91 ;
V_91 = V_22 -> V_6 . V_19 / V_20 ;
if ( F_57 ( V_33 , V_91 , V_37 ) )
goto V_92;
V_49 = V_22 -> V_6 . V_50 -> V_51 ;
F_58 (sgt->sgl, sg, count, i) {
struct V_28 * V_28 ;
V_28 = F_59 ( V_49 , V_89 ) ;
if ( F_60 ( V_28 ) ) {
V_90 = V_89 ;
goto V_93;
}
F_61 ( V_88 , V_28 , V_20 , 0 ) ;
}
if ( F_62 ( V_83 -> V_25 , V_33 -> V_94 , V_33 -> V_95 , V_85 ) == 0 ) {
V_90 = V_33 -> V_95 ;
goto V_93;
}
} else if ( V_22 -> V_28 ) {
if ( F_57 ( V_33 , 1 , V_37 ) )
goto V_92;
F_61 ( V_33 -> V_94 , V_22 -> V_28 , V_22 -> V_6 . V_19 , 0 ) ;
if ( F_62 ( V_83 -> V_25 , V_33 -> V_94 , V_33 -> V_95 , V_85 ) == 0 )
goto V_96;
} else if ( V_22 -> V_30 ) {
if ( F_57 ( V_33 , 1 , V_37 ) )
goto V_92;
F_63 ( V_33 -> V_94 ) = V_22 -> V_46 ;
F_64 ( V_33 -> V_94 ) = V_22 -> V_6 . V_19 ;
} else {
goto V_92;
}
return V_33 ;
V_93:
F_58 (sgt->sgl, sg, num, i)
F_65 ( F_66 ( V_88 ) ) ;
V_96:
F_67 ( V_33 ) ;
V_92:
F_15 ( V_33 ) ;
return NULL ;
}
static void F_68 ( struct V_82 * V_83 ,
struct V_81 * V_33 , enum V_84 V_85 )
{
struct V_21 * V_6 = V_83 -> V_86 -> V_24 ;
struct V_5 * V_22 = F_2 ( V_6 ) ;
int V_89 ;
if ( ! V_22 -> V_30 )
F_69 ( V_83 -> V_25 , V_33 -> V_94 , V_33 -> V_95 , V_85 ) ;
if ( V_22 -> V_6 . V_50 ) {
struct V_87 * V_88 ;
F_58 (sgt->sgl, sg, sgt->nents, i)
F_65 ( F_66 ( V_88 ) ) ;
}
F_67 ( V_33 ) ;
F_15 ( V_33 ) ;
}
static void * F_70 ( struct V_97 * V_98 , unsigned long V_99 )
{
return NULL ;
}
static void
F_71 ( struct V_97 * V_98 , unsigned long V_99 , void * V_31 )
{
}
static int
F_72 ( struct V_97 * V_98 , struct V_1 * V_2 )
{
return - V_64 ;
}
struct V_97 *
F_73 ( struct V_35 * V_25 , struct V_21 * V_6 ,
int V_100 )
{
F_74 ( V_101 ) ;
V_101 . V_102 = & V_103 ;
V_101 . V_19 = V_6 -> V_19 ;
V_101 . V_100 = V_104 ;
V_101 . V_24 = V_6 ;
return F_75 ( V_25 , & V_101 ) ;
}
struct V_21 *
F_76 ( struct V_35 * V_25 , struct V_97 * V_98 )
{
struct V_82 * V_83 ;
struct V_5 * V_22 ;
if ( V_98 -> V_102 == & V_103 ) {
struct V_21 * V_6 = V_98 -> V_24 ;
if ( V_6 -> V_25 == V_25 ) {
F_77 ( V_6 ) ;
return V_6 ;
}
}
V_83 = F_78 ( V_98 , V_25 -> V_25 ) ;
if ( F_60 ( V_83 ) )
return F_79 ( V_83 ) ;
V_22 = F_31 ( V_25 , V_98 -> V_19 ) ;
if ( ! V_22 ) {
F_80 ( V_98 , V_83 ) ;
return F_81 ( - V_16 ) ;
}
V_22 -> V_6 . V_32 = V_83 ;
F_82 ( V_98 ) ;
return & V_22 -> V_6 ;
}
int F_83 ( struct V_5 * V_22 )
{
int V_11 ;
V_22 -> V_33 = F_84 ( V_22 -> V_6 . V_32 ,
V_34 ) ;
if ( F_60 ( V_22 -> V_33 ) ) {
V_11 = F_85 ( V_22 -> V_33 ) ;
V_22 -> V_33 = NULL ;
F_42 ( L_10 , V_11 ) ;
return V_11 ;
}
if ( V_22 -> V_33 -> V_95 > 1 ) {
F_42 ( L_11 ) ;
return - V_64 ;
}
if ( F_64 ( V_22 -> V_33 -> V_94 ) < V_22 -> V_6 . V_19 ) {
F_42 ( L_12 ) ;
return - V_64 ;
}
V_22 -> V_46 = F_63 ( V_22 -> V_33 -> V_94 ) ;
return 0 ;
}
