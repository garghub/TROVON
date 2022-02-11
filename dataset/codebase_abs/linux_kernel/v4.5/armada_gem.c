static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned long V_10 = V_6 -> V_11 >> V_12 ;
int V_13 ;
V_10 += ( V_8 - V_2 -> V_14 ) >> V_12 ;
V_13 = F_3 ( V_2 , V_8 , V_10 ) ;
switch ( V_13 ) {
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
void F_6 ( struct V_22 * V_6 )
{
struct V_5 * V_23 = F_2 ( V_6 ) ;
struct V_24 * V_25 = V_6 -> V_26 -> V_27 ;
F_7 ( L_1 , V_23 ) ;
F_8 ( & V_23 -> V_6 ) ;
F_9 ( & V_25 -> V_28 ) ;
if ( V_23 -> V_29 ) {
unsigned int V_30 = F_10 ( V_23 -> V_6 . V_20 ) ;
F_11 ( V_23 -> V_29 , V_30 ) ;
} else if ( V_23 -> V_31 ) {
F_12 ( & V_25 -> V_28 ) ;
F_13 ( V_23 -> V_31 ) ;
F_14 ( & V_25 -> V_28 ) ;
F_15 ( V_23 -> V_31 ) ;
if ( V_23 -> V_8 )
F_16 ( V_23 -> V_8 ) ;
}
if ( V_23 -> V_6 . V_32 ) {
if ( V_23 -> V_33 )
F_17 ( V_23 -> V_6 . V_32 ,
V_23 -> V_33 , V_34 ) ;
F_18 ( & V_23 -> V_6 , NULL ) ;
}
F_19 ( & V_23 -> V_6 ) ;
F_15 ( V_23 ) ;
}
int
F_20 ( struct V_35 * V_26 , struct V_5 * V_6 )
{
struct V_24 * V_25 = V_26 -> V_27 ;
T_1 V_20 = V_6 -> V_6 . V_20 ;
if ( V_6 -> V_29 || V_6 -> V_31 )
return 0 ;
if ( V_20 <= 8192 ) {
unsigned int V_30 = F_10 ( V_20 ) ;
struct V_29 * V_36 = F_21 ( V_37 , V_30 ) ;
if ( V_36 ) {
V_6 -> V_8 = F_22 ( V_36 ) ;
V_6 -> V_11 = F_23 ( V_36 ) ;
V_6 -> V_29 = V_36 ;
memset ( V_6 -> V_8 , 0 , F_24 ( V_20 ) ) ;
}
}
if ( ! V_6 -> V_29 ) {
struct V_38 * V_39 ;
unsigned V_40 = F_25 ( unsigned , V_20 , V_41 ) ;
void T_2 * V_42 ;
int V_13 ;
V_39 = F_26 ( sizeof( * V_39 ) , V_37 ) ;
if ( ! V_39 )
return - V_43 ;
F_12 ( & V_25 -> V_28 ) ;
V_13 = F_27 ( & V_25 -> V_31 , V_39 , V_20 , V_40 ,
V_44 ) ;
F_14 ( & V_25 -> V_28 ) ;
if ( V_13 ) {
F_15 ( V_39 ) ;
return V_13 ;
}
V_6 -> V_31 = V_39 ;
V_42 = F_28 ( V_6 -> V_31 -> V_45 , V_20 ) ;
if ( ! V_42 ) {
F_12 ( & V_25 -> V_28 ) ;
F_13 ( V_6 -> V_31 ) ;
F_14 ( & V_25 -> V_28 ) ;
F_15 ( V_6 -> V_31 ) ;
V_6 -> V_31 = NULL ;
return - V_17 ;
}
F_29 ( V_42 , 0 , V_20 ) ;
F_16 ( V_42 ) ;
V_6 -> V_11 = V_6 -> V_31 -> V_45 ;
V_6 -> V_46 = V_6 -> V_31 -> V_45 ;
}
F_7 ( L_2 , V_6 ,
( unsigned long long ) V_6 -> V_11 ,
( unsigned long long ) V_6 -> V_46 ) ;
return 0 ;
}
void *
F_30 ( struct V_35 * V_26 , struct V_5 * V_23 )
{
if ( ! V_23 -> V_8 && V_23 -> V_31 )
V_23 -> V_8 = F_28 ( V_23 -> V_11 , V_23 -> V_6 . V_20 ) ;
return V_23 -> V_8 ;
}
struct V_5 *
F_31 ( struct V_35 * V_26 , T_1 V_20 )
{
struct V_5 * V_6 ;
V_20 = F_4 ( V_20 ) ;
V_6 = F_26 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return NULL ;
F_32 ( V_26 , & V_6 -> V_6 , V_20 ) ;
V_6 -> V_46 = V_47 ;
F_7 ( L_3 , V_6 , V_20 ) ;
return V_6 ;
}
struct V_5 * F_33 ( struct V_35 * V_26 ,
T_1 V_20 )
{
struct V_5 * V_6 ;
struct V_48 * V_49 ;
V_20 = F_4 ( V_20 ) ;
V_6 = F_26 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return NULL ;
if ( F_34 ( V_26 , & V_6 -> V_6 , V_20 ) ) {
F_15 ( V_6 ) ;
return NULL ;
}
V_6 -> V_46 = V_47 ;
V_49 = F_35 ( V_6 -> V_6 . V_50 ) -> V_51 ;
F_36 ( V_49 , V_52 | V_53 ) ;
F_7 ( L_4 , V_6 , V_20 ) ;
return V_6 ;
}
int F_37 ( struct V_54 * V_55 , struct V_35 * V_26 ,
struct V_56 * args )
{
struct V_5 * V_23 ;
T_3 V_57 ;
T_1 V_20 ;
int V_13 ;
args -> V_58 = F_38 ( args -> V_59 , args -> V_60 ) ;
args -> V_20 = V_20 = args -> V_58 * args -> V_61 ;
V_23 = F_31 ( V_26 , V_20 ) ;
if ( V_23 == NULL )
return - V_17 ;
V_13 = F_20 ( V_26 , V_23 ) ;
if ( V_13 )
goto V_62;
V_13 = F_39 ( V_55 , & V_23 -> V_6 , & V_57 ) ;
if ( V_13 )
goto V_62;
args -> V_57 = V_57 ;
F_7 ( L_5 , V_23 , V_20 , V_57 ) ;
V_62:
F_40 ( & V_23 -> V_6 ) ;
return V_13 ;
}
int F_41 ( struct V_54 * V_55 , struct V_35 * V_26 ,
T_4 V_57 , T_5 * V_63 )
{
struct V_5 * V_6 ;
int V_13 = 0 ;
V_6 = F_42 ( V_26 , V_55 , V_57 ) ;
if ( ! V_6 ) {
F_43 ( L_6 ) ;
return - V_64 ;
}
if ( V_6 -> V_6 . V_32 ) {
V_13 = - V_64 ;
goto V_65;
}
V_13 = F_44 ( & V_6 -> V_6 ) ;
if ( V_13 == 0 ) {
* V_63 = F_45 ( & V_6 -> V_6 . V_66 ) ;
F_7 ( L_7 , V_57 , * V_63 ) ;
}
V_65:
F_40 ( & V_6 -> V_6 ) ;
return V_13 ;
}
int F_46 ( struct V_54 * V_55 , struct V_35 * V_26 ,
T_4 V_57 )
{
return F_47 ( V_55 , V_57 ) ;
}
int F_48 ( struct V_35 * V_26 , void * V_67 ,
struct V_54 * V_55 )
{
struct V_68 * args = V_67 ;
struct V_5 * V_23 ;
T_1 V_20 ;
T_3 V_57 ;
int V_13 ;
if ( args -> V_20 == 0 )
return - V_17 ;
V_20 = args -> V_20 ;
V_23 = F_33 ( V_26 , V_20 ) ;
if ( V_23 == NULL )
return - V_17 ;
V_13 = F_39 ( V_55 , & V_23 -> V_6 , & V_57 ) ;
if ( V_13 )
goto V_62;
args -> V_57 = V_57 ;
F_7 ( L_5 , V_23 , V_20 , V_57 ) ;
V_62:
F_40 ( & V_23 -> V_6 ) ;
return V_13 ;
}
int F_49 ( struct V_35 * V_26 , void * V_67 ,
struct V_54 * V_55 )
{
struct V_69 * args = V_67 ;
struct V_5 * V_23 ;
unsigned long V_8 ;
V_23 = F_42 ( V_26 , V_55 , args -> V_57 ) ;
if ( V_23 == NULL )
return - V_70 ;
if ( ! V_23 -> V_6 . V_50 ) {
F_40 ( & V_23 -> V_6 ) ;
return - V_64 ;
}
V_8 = F_50 ( V_23 -> V_6 . V_50 , 0 , args -> V_20 , V_71 | V_72 ,
V_73 , args -> V_63 ) ;
F_40 ( & V_23 -> V_6 ) ;
if ( F_51 ( V_8 ) )
return V_8 ;
args -> V_8 = V_8 ;
return 0 ;
}
int F_52 ( struct V_35 * V_26 , void * V_67 ,
struct V_54 * V_55 )
{
struct V_74 * args = V_67 ;
struct V_5 * V_23 ;
char T_6 * V_42 ;
int V_13 ;
F_7 ( L_8 ,
args -> V_57 , args -> V_63 , args -> V_20 , args -> V_42 ) ;
if ( args -> V_20 == 0 )
return 0 ;
V_42 = ( char T_6 * ) ( V_75 ) args -> V_42 ;
if ( ! F_53 ( V_76 , V_42 , args -> V_20 ) )
return - V_77 ;
V_13 = F_54 ( V_42 , args -> V_20 ) ;
if ( V_13 )
return V_13 ;
V_23 = F_42 ( V_26 , V_55 , args -> V_57 ) ;
if ( V_23 == NULL )
return - V_70 ;
if ( ! V_23 -> V_8 )
return - V_64 ;
if ( args -> V_63 > V_23 -> V_6 . V_20 ||
args -> V_20 > V_23 -> V_6 . V_20 - args -> V_63 ) {
F_43 ( L_9 , V_23 -> V_6 . V_20 ) ;
V_13 = - V_64 ;
goto V_78;
}
if ( F_55 ( V_23 -> V_8 + args -> V_63 , V_42 , args -> V_20 ) ) {
V_13 = - V_77 ;
} else if ( V_23 -> V_79 ) {
V_23 -> V_79 ( V_23 -> V_80 ) ;
V_13 = 0 ;
}
V_78:
F_40 ( & V_23 -> V_6 ) ;
return V_13 ;
}
struct V_81 *
F_56 ( struct V_82 * V_83 ,
enum V_84 V_85 )
{
struct V_22 * V_6 = V_83 -> V_86 -> V_25 ;
struct V_5 * V_23 = F_2 ( V_6 ) ;
struct V_87 * V_88 ;
struct V_81 * V_33 ;
int V_89 , V_90 ;
V_33 = F_57 ( sizeof( * V_33 ) , V_37 ) ;
if ( ! V_33 )
return NULL ;
if ( V_23 -> V_6 . V_50 ) {
struct V_48 * V_49 ;
int V_91 ;
V_91 = V_23 -> V_6 . V_20 / V_21 ;
if ( F_58 ( V_33 , V_91 , V_37 ) )
goto V_92;
V_49 = F_35 ( V_23 -> V_6 . V_50 ) -> V_51 ;
F_59 (sgt->sgl, sg, count, i) {
struct V_29 * V_29 ;
V_29 = F_60 ( V_49 , V_89 ) ;
if ( F_61 ( V_29 ) ) {
V_90 = V_89 ;
goto V_93;
}
F_62 ( V_88 , V_29 , V_21 , 0 ) ;
}
if ( F_63 ( V_83 -> V_26 , V_33 -> V_94 , V_33 -> V_95 , V_85 ) == 0 ) {
V_90 = V_33 -> V_95 ;
goto V_93;
}
} else if ( V_23 -> V_29 ) {
if ( F_58 ( V_33 , 1 , V_37 ) )
goto V_92;
F_62 ( V_33 -> V_94 , V_23 -> V_29 , V_23 -> V_6 . V_20 , 0 ) ;
if ( F_63 ( V_83 -> V_26 , V_33 -> V_94 , V_33 -> V_95 , V_85 ) == 0 )
goto V_96;
} else if ( V_23 -> V_31 ) {
if ( F_58 ( V_33 , 1 , V_37 ) )
goto V_92;
F_64 ( V_33 -> V_94 ) = V_23 -> V_46 ;
F_65 ( V_33 -> V_94 ) = V_23 -> V_6 . V_20 ;
} else {
goto V_92;
}
return V_33 ;
V_93:
F_59 (sgt->sgl, sg, num, i)
F_66 ( F_67 ( V_88 ) ) ;
V_96:
F_68 ( V_33 ) ;
V_92:
F_15 ( V_33 ) ;
return NULL ;
}
static void F_69 ( struct V_82 * V_83 ,
struct V_81 * V_33 , enum V_84 V_85 )
{
struct V_22 * V_6 = V_83 -> V_86 -> V_25 ;
struct V_5 * V_23 = F_2 ( V_6 ) ;
int V_89 ;
if ( ! V_23 -> V_31 )
F_70 ( V_83 -> V_26 , V_33 -> V_94 , V_33 -> V_95 , V_85 ) ;
if ( V_23 -> V_6 . V_50 ) {
struct V_87 * V_88 ;
F_59 (sgt->sgl, sg, sgt->nents, i)
F_66 ( F_67 ( V_88 ) ) ;
}
F_68 ( V_33 ) ;
F_15 ( V_33 ) ;
}
static void * F_71 ( struct V_97 * V_98 , unsigned long V_99 )
{
return NULL ;
}
static void
F_72 ( struct V_97 * V_98 , unsigned long V_99 , void * V_8 )
{
}
static int
F_73 ( struct V_97 * V_98 , struct V_1 * V_2 )
{
return - V_64 ;
}
struct V_97 *
F_74 ( struct V_35 * V_26 , struct V_22 * V_6 ,
int V_100 )
{
F_75 ( V_101 ) ;
V_101 . V_102 = & V_103 ;
V_101 . V_20 = V_6 -> V_20 ;
V_101 . V_100 = V_104 ;
V_101 . V_25 = V_6 ;
return F_76 ( & V_101 ) ;
}
struct V_22 *
F_77 ( struct V_35 * V_26 , struct V_97 * V_98 )
{
struct V_82 * V_83 ;
struct V_5 * V_23 ;
if ( V_98 -> V_102 == & V_103 ) {
struct V_22 * V_6 = V_98 -> V_25 ;
if ( V_6 -> V_26 == V_26 ) {
F_78 ( V_6 ) ;
return V_6 ;
}
}
V_83 = F_79 ( V_98 , V_26 -> V_26 ) ;
if ( F_61 ( V_83 ) )
return F_80 ( V_83 ) ;
V_23 = F_31 ( V_26 , V_98 -> V_20 ) ;
if ( ! V_23 ) {
F_81 ( V_98 , V_83 ) ;
return F_82 ( - V_17 ) ;
}
V_23 -> V_6 . V_32 = V_83 ;
F_83 ( V_98 ) ;
return & V_23 -> V_6 ;
}
int F_84 ( struct V_5 * V_23 )
{
int V_13 ;
V_23 -> V_33 = F_85 ( V_23 -> V_6 . V_32 ,
V_34 ) ;
if ( ! V_23 -> V_33 ) {
F_43 ( L_10 ) ;
return - V_64 ;
}
if ( F_61 ( V_23 -> V_33 ) ) {
V_13 = F_86 ( V_23 -> V_33 ) ;
V_23 -> V_33 = NULL ;
F_43 ( L_11 , V_13 ) ;
return V_13 ;
}
if ( V_23 -> V_33 -> V_95 > 1 ) {
F_43 ( L_12 ) ;
return - V_64 ;
}
if ( F_65 ( V_23 -> V_33 -> V_94 ) < V_23 -> V_6 . V_20 ) {
F_43 ( L_13 ) ;
return - V_64 ;
}
V_23 -> V_46 = F_64 ( V_23 -> V_33 -> V_94 ) ;
return 0 ;
}
