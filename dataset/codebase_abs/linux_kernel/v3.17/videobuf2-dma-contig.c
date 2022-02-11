static void F_1 ( struct V_1 * V_2 ,
void (* F_2)( struct V_3 * V_4 ) )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
F_3 (sgt->sgl, s, sgt->orig_nents, i) {
struct V_3 * V_3 = F_4 ( V_6 ) ;
unsigned int V_8 = F_5 ( V_6 -> V_9 + V_6 -> V_10 )
>> V_11 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_8 ; ++ V_12 , ++ V_3 )
F_2 ( V_3 ) ;
}
}
static unsigned long F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_1 V_13 = F_7 ( V_2 -> V_14 ) ;
unsigned int V_7 ;
unsigned long V_15 = 0 ;
F_3 (sgt->sgl, s, sgt->nents, i) {
if ( F_7 ( V_6 ) != V_13 )
break;
V_13 = F_7 ( V_6 ) + F_8 ( V_6 ) ;
V_15 += F_8 ( V_6 ) ;
}
return V_15 ;
}
static void * F_9 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
return & V_18 -> V_19 ;
}
static void * F_10 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
if ( ! V_18 -> V_20 && V_18 -> V_21 )
V_18 -> V_20 = F_11 ( V_18 -> V_21 -> V_22 ) ;
return V_18 -> V_20 ;
}
static unsigned int F_12 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
return F_13 ( & V_18 -> V_23 ) ;
}
static void F_14 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_24 ;
if ( ! V_2 || V_18 -> V_21 )
return;
F_15 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_26 , V_18 -> V_27 ) ;
}
static void F_16 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_24 ;
if ( ! V_2 || V_18 -> V_21 )
return;
F_17 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_26 , V_18 -> V_27 ) ;
}
static void F_18 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
if ( ! F_19 ( & V_18 -> V_23 ) )
return;
if ( V_18 -> V_28 ) {
F_20 ( V_18 -> V_28 ) ;
F_21 ( V_18 -> V_28 ) ;
}
F_22 ( V_18 -> V_25 , V_18 -> V_15 , V_18 -> V_20 , V_18 -> V_19 ) ;
F_23 ( V_18 -> V_25 ) ;
F_21 ( V_18 ) ;
}
static void * F_24 ( void * V_29 , unsigned long V_15 , T_2 V_30 )
{
struct V_31 * V_32 = V_29 ;
struct V_33 * V_25 = V_32 -> V_25 ;
struct V_17 * V_18 ;
V_18 = F_25 ( sizeof *V_18 , V_34 ) ;
if ( ! V_18 )
return F_26 ( - V_35 ) ;
V_18 -> V_20 = F_27 ( V_25 , V_15 , & V_18 -> V_19 ,
V_34 | V_30 ) ;
if ( ! V_18 -> V_20 ) {
F_28 ( V_25 , L_1 , V_15 ) ;
F_21 ( V_18 ) ;
return F_26 ( - V_35 ) ;
}
V_18 -> V_25 = F_29 ( V_25 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_36 . V_23 = & V_18 -> V_23 ;
V_18 -> V_36 . V_37 = F_18 ;
V_18 -> V_36 . V_38 = V_18 ;
F_30 ( & V_18 -> V_23 ) ;
return V_18 ;
}
static int F_31 ( void * V_16 , struct V_39 * V_40 )
{
struct V_17 * V_18 = V_16 ;
int V_41 ;
if ( ! V_18 ) {
F_32 ( V_42 L_2 ) ;
return - V_43 ;
}
V_40 -> V_44 = 0 ;
V_41 = F_33 ( V_18 -> V_25 , V_40 , V_18 -> V_20 ,
V_18 -> V_19 , V_18 -> V_15 ) ;
if ( V_41 ) {
F_34 ( L_3 , V_41 ) ;
return V_41 ;
}
V_40 -> V_45 |= V_46 | V_47 ;
V_40 -> V_48 = & V_18 -> V_36 ;
V_40 -> V_49 = & V_50 ;
V_40 -> V_49 -> V_51 ( V_40 ) ;
F_35 ( L_4 ,
V_52 , ( unsigned long ) V_18 -> V_19 , V_40 -> V_53 ,
V_18 -> V_15 ) ;
return 0 ;
}
static int F_36 ( struct V_54 * V_55 , struct V_33 * V_25 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 ;
unsigned int V_7 ;
struct V_5 * V_60 , * V_61 ;
struct V_1 * V_2 ;
struct V_17 * V_18 = V_55 -> V_62 ;
int V_41 ;
V_59 = F_25 ( sizeof( * V_59 ) , V_34 ) ;
if ( ! V_59 )
return - V_35 ;
V_2 = & V_59 -> V_2 ;
V_41 = F_37 ( V_2 , V_18 -> V_28 -> V_63 , V_34 ) ;
if ( V_41 ) {
F_21 ( V_59 ) ;
return - V_35 ;
}
V_60 = V_18 -> V_28 -> V_14 ;
V_61 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_63 ; ++ V_7 ) {
F_38 ( V_61 , F_4 ( V_60 ) , V_60 -> V_10 , V_60 -> V_9 ) ;
V_60 = F_39 ( V_60 ) ;
V_61 = F_39 ( V_61 ) ;
}
V_59 -> V_64 = V_65 ;
V_57 -> V_62 = V_59 ;
return 0 ;
}
static void F_40 ( struct V_54 * V_55 ,
struct V_56 * V_21 )
{
struct V_58 * V_59 = V_21 -> V_62 ;
struct V_1 * V_2 ;
if ( ! V_59 )
return;
V_2 = & V_59 -> V_2 ;
if ( V_59 -> V_64 != V_65 )
F_41 ( V_21 -> V_25 , V_2 -> V_14 , V_2 -> V_63 ,
V_59 -> V_64 ) ;
F_20 ( V_2 ) ;
F_21 ( V_59 ) ;
V_21 -> V_62 = NULL ;
}
static struct V_1 * F_42 (
struct V_56 * V_21 , enum V_66 V_64 )
{
struct V_58 * V_59 = V_21 -> V_62 ;
struct V_67 * V_68 = & V_21 -> V_22 -> V_68 ;
struct V_1 * V_2 ;
int V_41 ;
F_43 ( V_68 ) ;
V_2 = & V_59 -> V_2 ;
if ( V_59 -> V_64 == V_64 ) {
F_44 ( V_68 ) ;
return V_2 ;
}
if ( V_59 -> V_64 != V_65 ) {
F_41 ( V_21 -> V_25 , V_2 -> V_14 , V_2 -> V_63 ,
V_59 -> V_64 ) ;
V_59 -> V_64 = V_65 ;
}
V_41 = F_45 ( V_21 -> V_25 , V_2 -> V_14 , V_2 -> V_63 , V_64 ) ;
if ( V_41 <= 0 ) {
F_34 ( L_5 ) ;
F_44 ( V_68 ) ;
return F_26 ( - V_69 ) ;
}
V_59 -> V_64 = V_64 ;
F_44 ( V_68 ) ;
return V_2 ;
}
static void F_46 ( struct V_56 * V_21 ,
struct V_1 * V_2 , enum V_66 V_64 )
{
}
static void F_47 ( struct V_54 * V_55 )
{
F_18 ( V_55 -> V_62 ) ;
}
static void * F_48 ( struct V_54 * V_55 , unsigned long V_70 )
{
struct V_17 * V_18 = V_55 -> V_62 ;
return V_18 -> V_20 + V_70 * V_71 ;
}
static void * F_49 ( struct V_54 * V_55 )
{
struct V_17 * V_18 = V_55 -> V_62 ;
return V_18 -> V_20 ;
}
static int F_50 ( struct V_54 * V_55 ,
struct V_39 * V_40 )
{
return F_31 ( V_55 -> V_62 , V_40 ) ;
}
static struct V_1 * F_51 ( struct V_17 * V_18 )
{
int V_41 ;
struct V_1 * V_2 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
F_28 ( V_18 -> V_25 , L_6 ) ;
return NULL ;
}
V_41 = F_53 ( V_18 -> V_25 , V_2 , V_18 -> V_20 , V_18 -> V_19 ,
V_18 -> V_15 ) ;
if ( V_41 < 0 ) {
F_28 ( V_18 -> V_25 , L_7 ) ;
F_21 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_54 * F_54 ( void * V_16 , unsigned long V_72 )
{
struct V_17 * V_18 = V_16 ;
struct V_54 * V_55 ;
if ( ! V_18 -> V_28 )
V_18 -> V_28 = F_51 ( V_18 ) ;
if ( F_55 ( ! V_18 -> V_28 ) )
return NULL ;
V_55 = F_56 ( V_18 , & V_73 , V_18 -> V_15 , V_72 , NULL ) ;
if ( F_57 ( V_55 ) )
return NULL ;
F_30 ( & V_18 -> V_23 ) ;
return V_55 ;
}
static inline int F_58 ( struct V_39 * V_40 )
{
return ! ! ( V_40 -> V_45 & ( V_74 | V_75 ) ) ;
}
static int F_59 ( unsigned long V_76 , int V_8 ,
struct V_39 * V_40 , unsigned long * V_77 )
{
unsigned long V_78 , V_79 , V_80 ;
unsigned int V_7 ;
int V_41 ;
if ( ! F_58 ( V_40 ) )
return - V_81 ;
V_41 = F_60 ( V_40 , V_76 , & V_78 ) ;
if ( V_41 )
return V_41 ;
V_79 = V_78 ;
V_76 += V_71 ;
for ( V_7 = 1 ; V_7 < V_8 ; ++ V_7 , V_76 += V_71 ) {
V_80 = V_78 ;
V_41 = F_60 ( V_40 , V_76 , & V_78 ) ;
if ( V_41 ) {
F_34 ( L_8 , V_76 ) ;
return V_41 ;
}
if ( V_78 != V_80 + 1 )
return - V_43 ;
}
* V_77 = V_79 ;
return 0 ;
}
static int F_61 ( unsigned long V_76 , struct V_3 * * V_82 ,
int V_8 , struct V_39 * V_40 , int V_83 )
{
if ( F_58 ( V_40 ) ) {
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 , V_76 += V_71 ) {
unsigned long V_78 ;
int V_41 = F_60 ( V_40 , V_76 , & V_78 ) ;
if ( ! F_62 ( V_78 ) )
return - V_43 ;
if ( V_41 ) {
F_34 ( L_8 , V_76 ) ;
return V_41 ;
}
V_82 [ V_7 ] = F_63 ( V_78 ) ;
}
} else {
int V_84 ;
V_84 = F_64 ( V_85 , V_85 -> V_86 , V_76 & V_87 ,
V_8 , V_83 , 1 , V_82 , NULL ) ;
V_84 = F_65 ( V_84 , 0 ) ;
if ( V_84 != V_8 ) {
F_34 ( L_9 , V_84 , V_8 ) ;
while ( V_84 )
F_66 ( V_82 [ -- V_84 ] ) ;
return - V_81 ;
}
}
return 0 ;
}
static void F_67 ( struct V_3 * V_3 )
{
F_68 ( V_3 ) ;
F_66 ( V_3 ) ;
}
static void F_69 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_24 ;
if ( V_2 ) {
F_41 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_63 , V_18 -> V_27 ) ;
if ( ! F_58 ( V_18 -> V_40 ) )
F_1 ( V_2 , F_67 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
F_70 ( V_18 -> V_40 ) ;
F_21 ( V_18 ) ;
}
static inline T_1 F_71 ( struct V_33 * V_25 , unsigned long V_78 )
{
return ( T_1 ) F_72 ( V_25 , V_78 ) ;
}
static inline T_1 F_71 ( struct V_33 * V_25 , unsigned long V_78 )
{
return ( T_1 ) F_73 ( V_78 ) ;
}
static inline T_1 F_71 ( struct V_33 * V_25 , unsigned long V_78 )
{
return ( T_1 ) F_74 ( V_78 ) ;
}
static inline T_1 F_71 ( struct V_33 * V_25 , unsigned long V_78 )
{
return ( T_1 ) ( V_78 ) << V_11 ;
}
static void * F_75 ( void * V_29 , unsigned long V_20 ,
unsigned long V_15 , int V_83 )
{
struct V_31 * V_32 = V_29 ;
struct V_17 * V_18 ;
unsigned long V_76 ;
unsigned long V_88 ;
unsigned long V_9 ;
struct V_3 * * V_82 ;
int V_8 ;
int V_41 = 0 ;
struct V_39 * V_40 ;
struct V_1 * V_2 ;
unsigned long V_89 ;
unsigned long V_90 = F_76 () ;
if ( ! F_77 ( V_20 | V_15 , V_90 ) ) {
F_35 ( L_10 , V_90 ) ;
return F_26 ( - V_43 ) ;
}
if ( ! V_15 ) {
F_35 ( L_11 ) ;
return F_26 ( - V_43 ) ;
}
V_18 = F_25 ( sizeof *V_18 , V_34 ) ;
if ( ! V_18 )
return F_26 ( - V_35 ) ;
V_18 -> V_25 = V_32 -> V_25 ;
V_18 -> V_27 = V_83 ? V_91 : V_92 ;
V_76 = V_20 & V_87 ;
V_9 = V_20 & ~ V_87 ;
V_88 = F_5 ( V_20 + V_15 ) ;
V_8 = ( V_88 - V_76 ) >> V_11 ;
V_82 = F_52 ( V_8 * sizeof( V_82 [ 0 ] ) , V_34 ) ;
if ( ! V_82 ) {
V_41 = - V_35 ;
F_34 ( L_12 ) ;
goto V_93;
}
V_40 = F_78 ( V_85 -> V_86 , V_20 ) ;
if ( ! V_40 ) {
F_34 ( L_13 , V_20 ) ;
V_41 = - V_81 ;
goto V_94;
}
if ( V_40 -> V_95 < V_20 + V_15 ) {
F_34 ( L_14 , V_20 , V_15 ) ;
V_41 = - V_81 ;
goto V_94;
}
V_18 -> V_40 = F_79 ( V_40 ) ;
if ( ! V_18 -> V_40 ) {
F_34 ( L_15 ) ;
V_41 = - V_35 ;
goto V_94;
}
V_41 = F_61 ( V_76 , V_82 , V_8 , V_40 , V_83 ) ;
if ( V_41 ) {
unsigned long V_78 ;
if ( F_59 ( V_76 , V_8 , V_40 , & V_78 ) == 0 ) {
V_18 -> V_19 = F_71 ( V_18 -> V_25 , V_78 ) ;
V_18 -> V_15 = V_15 ;
F_21 ( V_82 ) ;
return V_18 ;
}
F_34 ( L_16 ) ;
goto V_96;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 ) {
F_34 ( L_17 ) ;
V_41 = - V_35 ;
goto V_97;
}
V_41 = F_80 ( V_2 , V_82 , V_8 ,
V_9 , V_15 , V_34 ) ;
if ( V_41 ) {
F_34 ( L_18 ) ;
goto V_98;
}
F_21 ( V_82 ) ;
V_82 = NULL ;
V_2 -> V_26 = F_45 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_63 ,
V_18 -> V_27 ) ;
if ( V_2 -> V_26 <= 0 ) {
F_34 ( L_5 ) ;
V_41 = - V_69 ;
goto V_99;
}
V_89 = F_6 ( V_2 ) ;
if ( V_89 < V_15 ) {
F_34 ( L_19 ,
V_89 , V_15 ) ;
V_41 = - V_81 ;
goto V_100;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_24 = V_2 ;
return V_18 ;
V_100:
F_41 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_63 , V_18 -> V_27 ) ;
V_99:
if ( ! F_58 ( V_18 -> V_40 ) )
F_1 ( V_2 , F_66 ) ;
F_20 ( V_2 ) ;
V_98:
F_21 ( V_2 ) ;
V_97:
if ( V_82 && ! F_58 ( V_18 -> V_40 ) )
while ( V_8 )
F_66 ( V_82 [ -- V_8 ] ) ;
V_96:
F_70 ( V_18 -> V_40 ) ;
V_94:
F_21 ( V_82 ) ;
V_93:
F_21 ( V_18 ) ;
return F_26 ( V_41 ) ;
}
static int F_81 ( void * V_101 )
{
struct V_17 * V_18 = V_101 ;
struct V_1 * V_2 ;
unsigned long V_89 ;
if ( F_55 ( ! V_18 -> V_21 ) ) {
F_34 ( L_20 ) ;
return - V_43 ;
}
if ( F_55 ( V_18 -> V_24 ) ) {
F_34 ( L_21 ) ;
return 0 ;
}
V_2 = F_82 ( V_18 -> V_21 , V_18 -> V_27 ) ;
if ( F_57 ( V_2 ) ) {
F_34 ( L_22 ) ;
return - V_43 ;
}
V_89 = F_6 ( V_2 ) ;
if ( V_89 < V_18 -> V_15 ) {
F_34 ( L_23 ,
V_89 , V_18 -> V_15 ) ;
F_83 ( V_18 -> V_21 , V_2 , V_18 -> V_27 ) ;
return - V_81 ;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_24 = V_2 ;
V_18 -> V_20 = NULL ;
return 0 ;
}
static void F_84 ( void * V_101 )
{
struct V_17 * V_18 = V_101 ;
struct V_1 * V_2 = V_18 -> V_24 ;
if ( F_55 ( ! V_18 -> V_21 ) ) {
F_34 ( L_24 ) ;
return;
}
if ( F_55 ( ! V_2 ) ) {
F_34 ( L_25 ) ;
return;
}
if ( V_18 -> V_20 ) {
F_85 ( V_18 -> V_21 -> V_22 , V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
F_83 ( V_18 -> V_21 , V_2 , V_18 -> V_27 ) ;
V_18 -> V_19 = 0 ;
V_18 -> V_24 = NULL ;
}
static void F_86 ( void * V_101 )
{
struct V_17 * V_18 = V_101 ;
if ( F_55 ( V_18 -> V_19 ) )
F_84 ( V_18 ) ;
F_87 ( V_18 -> V_21 -> V_22 , V_18 -> V_21 ) ;
F_21 ( V_18 ) ;
}
static void * F_88 ( void * V_29 , struct V_54 * V_55 ,
unsigned long V_15 , int V_83 )
{
struct V_31 * V_32 = V_29 ;
struct V_17 * V_18 ;
struct V_56 * V_102 ;
if ( V_55 -> V_15 < V_15 )
return F_26 ( - V_81 ) ;
V_18 = F_25 ( sizeof( * V_18 ) , V_34 ) ;
if ( ! V_18 )
return F_26 ( - V_35 ) ;
V_18 -> V_25 = V_32 -> V_25 ;
V_102 = F_89 ( V_55 , V_18 -> V_25 ) ;
if ( F_57 ( V_102 ) ) {
F_34 ( L_26 ) ;
F_21 ( V_18 ) ;
return V_102 ;
}
V_18 -> V_27 = V_83 ? V_91 : V_92 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_21 = V_102 ;
return V_18 ;
}
void * F_90 ( struct V_33 * V_25 )
{
struct V_31 * V_32 ;
V_32 = F_25 ( sizeof *V_32 , V_34 ) ;
if ( ! V_32 )
return F_26 ( - V_35 ) ;
V_32 -> V_25 = V_25 ;
return V_32 ;
}
void F_91 ( void * V_29 )
{
F_21 ( V_29 ) ;
}
