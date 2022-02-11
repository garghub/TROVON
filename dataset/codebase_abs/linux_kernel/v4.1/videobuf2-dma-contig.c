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
static void * F_24 ( void * V_29 , unsigned long V_15 ,
enum V_30 V_27 , T_2 V_31 )
{
struct V_32 * V_33 = V_29 ;
struct V_34 * V_25 = V_33 -> V_25 ;
struct V_17 * V_18 ;
V_18 = F_25 ( sizeof *V_18 , V_35 ) ;
if ( ! V_18 )
return F_26 ( - V_36 ) ;
V_18 -> V_20 = F_27 ( V_25 , V_15 , & V_18 -> V_19 ,
V_35 | V_31 ) ;
if ( ! V_18 -> V_20 ) {
F_28 ( V_25 , L_1 , V_15 ) ;
F_21 ( V_18 ) ;
return F_26 ( - V_36 ) ;
}
V_18 -> V_25 = F_29 ( V_25 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_27 = V_27 ;
V_18 -> V_37 . V_23 = & V_18 -> V_23 ;
V_18 -> V_37 . V_38 = F_18 ;
V_18 -> V_37 . V_39 = V_18 ;
F_30 ( & V_18 -> V_23 ) ;
return V_18 ;
}
static int F_31 ( void * V_16 , struct V_40 * V_41 )
{
struct V_17 * V_18 = V_16 ;
int V_42 ;
if ( ! V_18 ) {
F_32 ( V_43 L_2 ) ;
return - V_44 ;
}
V_41 -> V_45 = 0 ;
V_42 = F_33 ( V_18 -> V_25 , V_41 , V_18 -> V_20 ,
V_18 -> V_19 , V_18 -> V_15 ) ;
if ( V_42 ) {
F_34 ( L_3 , V_42 ) ;
return V_42 ;
}
V_41 -> V_46 |= V_47 | V_48 ;
V_41 -> V_49 = & V_18 -> V_37 ;
V_41 -> V_50 = & V_51 ;
V_41 -> V_50 -> V_52 ( V_41 ) ;
F_35 ( L_4 ,
V_53 , ( unsigned long ) V_18 -> V_19 , V_41 -> V_54 ,
V_18 -> V_15 ) ;
return 0 ;
}
static int F_36 ( struct V_55 * V_56 , struct V_34 * V_25 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 ;
unsigned int V_7 ;
struct V_5 * V_61 , * V_62 ;
struct V_1 * V_2 ;
struct V_17 * V_18 = V_56 -> V_63 ;
int V_42 ;
V_60 = F_25 ( sizeof( * V_60 ) , V_35 ) ;
if ( ! V_60 )
return - V_36 ;
V_2 = & V_60 -> V_2 ;
V_42 = F_37 ( V_2 , V_18 -> V_28 -> V_64 , V_35 ) ;
if ( V_42 ) {
F_21 ( V_60 ) ;
return - V_36 ;
}
V_61 = V_18 -> V_28 -> V_14 ;
V_62 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_64 ; ++ V_7 ) {
F_38 ( V_62 , F_4 ( V_61 ) , V_61 -> V_10 , V_61 -> V_9 ) ;
V_61 = F_39 ( V_61 ) ;
V_62 = F_39 ( V_62 ) ;
}
V_60 -> V_27 = V_65 ;
V_58 -> V_63 = V_60 ;
return 0 ;
}
static void F_40 ( struct V_55 * V_56 ,
struct V_57 * V_21 )
{
struct V_59 * V_60 = V_21 -> V_63 ;
struct V_1 * V_2 ;
if ( ! V_60 )
return;
V_2 = & V_60 -> V_2 ;
if ( V_60 -> V_27 != V_65 )
F_41 ( V_21 -> V_25 , V_2 -> V_14 , V_2 -> V_64 ,
V_60 -> V_27 ) ;
F_20 ( V_2 ) ;
F_21 ( V_60 ) ;
V_21 -> V_63 = NULL ;
}
static struct V_1 * F_42 (
struct V_57 * V_21 , enum V_30 V_27 )
{
struct V_59 * V_60 = V_21 -> V_63 ;
struct V_66 * V_67 = & V_21 -> V_22 -> V_67 ;
struct V_1 * V_2 ;
int V_42 ;
F_43 ( V_67 ) ;
V_2 = & V_60 -> V_2 ;
if ( V_60 -> V_27 == V_27 ) {
F_44 ( V_67 ) ;
return V_2 ;
}
if ( V_60 -> V_27 != V_65 ) {
F_41 ( V_21 -> V_25 , V_2 -> V_14 , V_2 -> V_64 ,
V_60 -> V_27 ) ;
V_60 -> V_27 = V_65 ;
}
V_42 = F_45 ( V_21 -> V_25 , V_2 -> V_14 , V_2 -> V_64 , V_27 ) ;
if ( V_42 <= 0 ) {
F_34 ( L_5 ) ;
F_44 ( V_67 ) ;
return F_26 ( - V_68 ) ;
}
V_60 -> V_27 = V_27 ;
F_44 ( V_67 ) ;
return V_2 ;
}
static void F_46 ( struct V_57 * V_21 ,
struct V_1 * V_2 , enum V_30 V_27 )
{
}
static void F_47 ( struct V_55 * V_56 )
{
F_18 ( V_56 -> V_63 ) ;
}
static void * F_48 ( struct V_55 * V_56 , unsigned long V_69 )
{
struct V_17 * V_18 = V_56 -> V_63 ;
return V_18 -> V_20 + V_69 * V_70 ;
}
static void * F_49 ( struct V_55 * V_56 )
{
struct V_17 * V_18 = V_56 -> V_63 ;
return V_18 -> V_20 ;
}
static int F_50 ( struct V_55 * V_56 ,
struct V_40 * V_41 )
{
return F_31 ( V_56 -> V_63 , V_41 ) ;
}
static struct V_1 * F_51 ( struct V_17 * V_18 )
{
int V_42 ;
struct V_1 * V_2 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 ) {
F_28 ( V_18 -> V_25 , L_6 ) ;
return NULL ;
}
V_42 = F_53 ( V_18 -> V_25 , V_2 , V_18 -> V_20 , V_18 -> V_19 ,
V_18 -> V_15 ) ;
if ( V_42 < 0 ) {
F_28 ( V_18 -> V_25 , L_7 ) ;
F_21 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_55 * F_54 ( void * V_16 , unsigned long V_71 )
{
struct V_17 * V_18 = V_16 ;
struct V_55 * V_56 ;
F_55 ( V_72 ) ;
V_72 . V_73 = & V_74 ;
V_72 . V_15 = V_18 -> V_15 ;
V_72 . V_71 = V_71 ;
V_72 . V_63 = V_18 ;
if ( ! V_18 -> V_28 )
V_18 -> V_28 = F_51 ( V_18 ) ;
if ( F_56 ( ! V_18 -> V_28 ) )
return NULL ;
V_56 = F_57 ( & V_72 ) ;
if ( F_58 ( V_56 ) )
return NULL ;
F_30 ( & V_18 -> V_23 ) ;
return V_56 ;
}
static inline int F_59 ( struct V_40 * V_41 )
{
return ! ! ( V_41 -> V_46 & ( V_75 | V_76 ) ) ;
}
static int F_60 ( unsigned long V_77 , int V_8 ,
struct V_40 * V_41 , unsigned long * V_78 )
{
unsigned long V_79 , V_80 , V_81 ;
unsigned int V_7 ;
int V_42 ;
if ( ! F_59 ( V_41 ) )
return - V_82 ;
V_42 = F_61 ( V_41 , V_77 , & V_79 ) ;
if ( V_42 )
return V_42 ;
V_80 = V_79 ;
V_77 += V_70 ;
for ( V_7 = 1 ; V_7 < V_8 ; ++ V_7 , V_77 += V_70 ) {
V_81 = V_79 ;
V_42 = F_61 ( V_41 , V_77 , & V_79 ) ;
if ( V_42 ) {
F_34 ( L_8 , V_77 ) ;
return V_42 ;
}
if ( V_79 != V_81 + 1 )
return - V_44 ;
}
* V_78 = V_80 ;
return 0 ;
}
static int F_62 ( unsigned long V_77 , struct V_3 * * V_83 ,
int V_8 , struct V_40 * V_41 ,
enum V_30 V_27 )
{
if ( F_59 ( V_41 ) ) {
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 , V_77 += V_70 ) {
unsigned long V_79 ;
int V_42 = F_61 ( V_41 , V_77 , & V_79 ) ;
if ( ! F_63 ( V_79 ) )
return - V_44 ;
if ( V_42 ) {
F_34 ( L_8 , V_77 ) ;
return V_42 ;
}
V_83 [ V_7 ] = F_64 ( V_79 ) ;
}
} else {
int V_84 ;
V_84 = F_65 ( V_85 , V_85 -> V_86 , V_77 & V_87 ,
V_8 , V_27 == V_88 , 1 , V_83 , NULL ) ;
V_84 = F_66 ( V_84 , 0 ) ;
if ( V_84 != V_8 ) {
F_34 ( L_9 , V_84 , V_8 ) ;
while ( V_84 )
F_67 ( V_83 [ -- V_84 ] ) ;
return - V_82 ;
}
}
return 0 ;
}
static void F_68 ( struct V_3 * V_3 )
{
F_69 ( V_3 ) ;
F_67 ( V_3 ) ;
}
static void F_70 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_24 ;
if ( V_2 ) {
F_71 ( V_89 ) ;
F_72 ( V_90 , & V_89 ) ;
F_73 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_64 ,
V_18 -> V_27 , & V_89 ) ;
if ( ! F_59 ( V_18 -> V_41 ) )
F_1 ( V_2 , F_68 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
}
F_74 ( V_18 -> V_41 ) ;
F_21 ( V_18 ) ;
}
static inline T_1 F_75 ( struct V_34 * V_25 , unsigned long V_79 )
{
return ( T_1 ) F_76 ( V_25 , V_79 ) ;
}
static inline T_1 F_75 ( struct V_34 * V_25 , unsigned long V_79 )
{
return ( T_1 ) F_77 ( V_79 ) ;
}
static inline T_1 F_75 ( struct V_34 * V_25 , unsigned long V_79 )
{
return ( T_1 ) F_78 ( V_79 ) ;
}
static inline T_1 F_75 ( struct V_34 * V_25 , unsigned long V_79 )
{
return ( T_1 ) ( V_79 ) << V_11 ;
}
static void * F_79 ( void * V_29 , unsigned long V_20 ,
unsigned long V_15 , enum V_30 V_27 )
{
struct V_32 * V_33 = V_29 ;
struct V_17 * V_18 ;
unsigned long V_77 ;
unsigned long V_91 ;
unsigned long V_9 ;
struct V_3 * * V_83 ;
int V_8 ;
int V_42 = 0 ;
struct V_40 * V_41 ;
struct V_1 * V_2 ;
unsigned long V_92 ;
unsigned long V_93 = F_80 () ;
F_71 ( V_89 ) ;
F_72 ( V_90 , & V_89 ) ;
if ( ! F_81 ( V_20 | V_15 , V_93 ) ) {
F_35 ( L_10 , V_93 ) ;
return F_26 ( - V_44 ) ;
}
if ( ! V_15 ) {
F_35 ( L_11 ) ;
return F_26 ( - V_44 ) ;
}
V_18 = F_25 ( sizeof *V_18 , V_35 ) ;
if ( ! V_18 )
return F_26 ( - V_36 ) ;
V_18 -> V_25 = V_33 -> V_25 ;
V_18 -> V_27 = V_27 ;
V_77 = V_20 & V_87 ;
V_9 = V_20 & ~ V_87 ;
V_91 = F_5 ( V_20 + V_15 ) ;
V_8 = ( V_91 - V_77 ) >> V_11 ;
V_83 = F_52 ( V_8 * sizeof( V_83 [ 0 ] ) , V_35 ) ;
if ( ! V_83 ) {
V_42 = - V_36 ;
F_34 ( L_12 ) ;
goto V_94;
}
V_41 = F_82 ( V_85 -> V_86 , V_20 ) ;
if ( ! V_41 ) {
F_34 ( L_13 , V_20 ) ;
V_42 = - V_82 ;
goto V_95;
}
if ( V_41 -> V_96 < V_20 + V_15 ) {
F_34 ( L_14 , V_20 , V_15 ) ;
V_42 = - V_82 ;
goto V_95;
}
V_18 -> V_41 = F_83 ( V_41 ) ;
if ( ! V_18 -> V_41 ) {
F_34 ( L_15 ) ;
V_42 = - V_36 ;
goto V_95;
}
V_42 = F_62 ( V_77 , V_83 , V_8 , V_41 , V_27 ) ;
if ( V_42 ) {
unsigned long V_79 ;
if ( F_60 ( V_77 , V_8 , V_41 , & V_79 ) == 0 ) {
V_18 -> V_19 = F_75 ( V_18 -> V_25 , V_79 ) ;
V_18 -> V_15 = V_15 ;
F_21 ( V_83 ) ;
return V_18 ;
}
F_34 ( L_16 ) ;
goto V_97;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 ) {
F_34 ( L_17 ) ;
V_42 = - V_36 ;
goto V_98;
}
V_42 = F_84 ( V_2 , V_83 , V_8 ,
V_9 , V_15 , V_35 ) ;
if ( V_42 ) {
F_34 ( L_18 ) ;
goto V_99;
}
F_21 ( V_83 ) ;
V_83 = NULL ;
V_2 -> V_26 = F_85 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_64 ,
V_18 -> V_27 , & V_89 ) ;
if ( V_2 -> V_26 <= 0 ) {
F_34 ( L_5 ) ;
V_42 = - V_68 ;
goto V_100;
}
V_92 = F_6 ( V_2 ) ;
if ( V_92 < V_15 ) {
F_34 ( L_19 ,
V_92 , V_15 ) ;
V_42 = - V_82 ;
goto V_101;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_24 = V_2 ;
return V_18 ;
V_101:
F_73 ( V_18 -> V_25 , V_2 -> V_14 , V_2 -> V_64 ,
V_18 -> V_27 , & V_89 ) ;
V_100:
if ( ! F_59 ( V_18 -> V_41 ) )
F_1 ( V_2 , F_67 ) ;
F_20 ( V_2 ) ;
V_99:
F_21 ( V_2 ) ;
V_98:
if ( V_83 && ! F_59 ( V_18 -> V_41 ) )
while ( V_8 )
F_67 ( V_83 [ -- V_8 ] ) ;
V_97:
F_74 ( V_18 -> V_41 ) ;
V_95:
F_21 ( V_83 ) ;
V_94:
F_21 ( V_18 ) ;
return F_26 ( V_42 ) ;
}
static int F_86 ( void * V_102 )
{
struct V_17 * V_18 = V_102 ;
struct V_1 * V_2 ;
unsigned long V_92 ;
if ( F_56 ( ! V_18 -> V_21 ) ) {
F_34 ( L_20 ) ;
return - V_44 ;
}
if ( F_56 ( V_18 -> V_24 ) ) {
F_34 ( L_21 ) ;
return 0 ;
}
V_2 = F_87 ( V_18 -> V_21 , V_18 -> V_27 ) ;
if ( F_58 ( V_2 ) ) {
F_34 ( L_22 ) ;
return - V_44 ;
}
V_92 = F_6 ( V_2 ) ;
if ( V_92 < V_18 -> V_15 ) {
F_34 ( L_23 ,
V_92 , V_18 -> V_15 ) ;
F_88 ( V_18 -> V_21 , V_2 , V_18 -> V_27 ) ;
return - V_82 ;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_24 = V_2 ;
V_18 -> V_20 = NULL ;
return 0 ;
}
static void F_89 ( void * V_102 )
{
struct V_17 * V_18 = V_102 ;
struct V_1 * V_2 = V_18 -> V_24 ;
if ( F_56 ( ! V_18 -> V_21 ) ) {
F_34 ( L_24 ) ;
return;
}
if ( F_56 ( ! V_2 ) ) {
F_34 ( L_25 ) ;
return;
}
if ( V_18 -> V_20 ) {
F_90 ( V_18 -> V_21 -> V_22 , V_18 -> V_20 ) ;
V_18 -> V_20 = NULL ;
}
F_88 ( V_18 -> V_21 , V_2 , V_18 -> V_27 ) ;
V_18 -> V_19 = 0 ;
V_18 -> V_24 = NULL ;
}
static void F_91 ( void * V_102 )
{
struct V_17 * V_18 = V_102 ;
if ( F_56 ( V_18 -> V_19 ) )
F_89 ( V_18 ) ;
F_92 ( V_18 -> V_21 -> V_22 , V_18 -> V_21 ) ;
F_21 ( V_18 ) ;
}
static void * F_93 ( void * V_29 , struct V_55 * V_56 ,
unsigned long V_15 , enum V_30 V_27 )
{
struct V_32 * V_33 = V_29 ;
struct V_17 * V_18 ;
struct V_57 * V_103 ;
if ( V_56 -> V_15 < V_15 )
return F_26 ( - V_82 ) ;
V_18 = F_25 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return F_26 ( - V_36 ) ;
V_18 -> V_25 = V_33 -> V_25 ;
V_103 = F_94 ( V_56 , V_18 -> V_25 ) ;
if ( F_58 ( V_103 ) ) {
F_34 ( L_26 ) ;
F_21 ( V_18 ) ;
return V_103 ;
}
V_18 -> V_27 = V_27 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_21 = V_103 ;
return V_18 ;
}
void * F_95 ( struct V_34 * V_25 )
{
struct V_32 * V_33 ;
V_33 = F_25 ( sizeof *V_33 , V_35 ) ;
if ( ! V_33 )
return F_26 ( - V_36 ) ;
V_33 -> V_25 = V_25 ;
return V_33 ;
}
void F_96 ( void * V_29 )
{
if ( ! F_97 ( V_29 ) )
F_21 ( V_29 ) ;
}
