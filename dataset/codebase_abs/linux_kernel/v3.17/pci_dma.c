static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( ( V_3 ) V_2 -> V_4 << 32 , V_2 -> V_5 ,
V_2 -> V_6 * V_7 ) ;
}
static unsigned long * F_3 ( void )
{
unsigned long * V_8 , * V_9 ;
V_8 = F_4 ( V_10 , V_11 ) ;
if ( ! V_8 )
return NULL ;
for ( V_9 = V_8 ; V_9 < V_8 + V_12 ; V_9 ++ )
* V_9 = V_13 | V_14 ;
return V_8 ;
}
static void F_5 ( void * V_8 )
{
F_6 ( V_10 , V_8 ) ;
}
static unsigned long * F_7 ( void )
{
unsigned long * V_8 , * V_9 ;
V_8 = F_4 ( V_15 , V_11 ) ;
if ( ! V_8 )
return NULL ;
for ( V_9 = V_8 ; V_9 < V_8 + V_16 ; V_9 ++ )
* V_9 = V_17 | V_14 ;
return V_8 ;
}
static void F_8 ( void * V_8 )
{
F_6 ( V_15 , V_8 ) ;
}
static unsigned long * F_9 ( unsigned long * V_9 )
{
unsigned long * V_18 ;
if ( F_10 ( * V_9 ) )
V_18 = F_11 ( * V_9 ) ;
else {
V_18 = F_3 () ;
if ( ! V_18 )
return NULL ;
F_12 ( V_9 , V_18 ) ;
F_13 ( V_9 ) ;
F_14 ( V_9 ) ;
}
return V_18 ;
}
static unsigned long * F_15 ( unsigned long * V_9 )
{
unsigned long * V_19 ;
if ( F_10 ( * V_9 ) )
V_19 = F_16 ( * V_9 ) ;
else {
V_19 = F_7 () ;
if ( ! V_19 )
return NULL ;
F_17 ( V_9 , V_19 ) ;
F_18 ( V_9 ) ;
F_14 ( V_9 ) ;
}
return V_19 ;
}
static unsigned long * F_19 ( unsigned long * V_20 , T_1 V_21 )
{
unsigned long * V_18 , * V_19 ;
unsigned int V_22 , V_23 , V_24 ;
V_22 = F_20 ( V_21 ) ;
V_18 = F_9 ( & V_20 [ V_22 ] ) ;
if ( ! V_18 )
return NULL ;
V_23 = F_21 ( V_21 ) ;
V_19 = F_15 ( & V_18 [ V_23 ] ) ;
if ( ! V_19 )
return NULL ;
V_24 = F_22 ( V_21 ) ;
return & V_19 [ V_24 ] ;
}
static void F_23 ( struct V_1 * V_2 , void * V_25 ,
T_1 V_21 , int V_26 )
{
unsigned long * V_9 ;
V_9 = F_19 ( V_2 -> V_27 , V_21 ) ;
if ( ! V_9 ) {
F_24 ( 1 ) ;
return;
}
if ( V_26 & V_17 ) {
F_25 ( V_9 ) ;
return;
} else {
F_26 ( V_9 , V_25 ) ;
F_27 ( V_9 ) ;
}
if ( V_26 & V_14 )
F_28 ( V_9 ) ;
else
F_14 ( V_9 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_28 ,
T_1 V_21 , T_2 V_29 , int V_26 )
{
unsigned int V_30 = F_30 ( V_29 ) >> V_31 ;
T_3 * V_25 = ( T_3 * ) ( V_28 & V_32 ) ;
T_1 V_33 = V_21 ;
unsigned long V_34 ;
int V_35 , V_36 = 0 ;
if ( ! V_30 )
return - V_37 ;
F_31 ( & V_2 -> V_38 , V_34 ) ;
if ( ! V_2 -> V_27 )
goto V_39;
for ( V_35 = 0 ; V_35 < V_30 ; V_35 ++ ) {
F_23 ( V_2 , V_25 , V_21 , V_26 ) ;
V_25 += V_7 ;
V_21 += V_7 ;
}
if ( ! V_2 -> V_40 &&
( ! V_41 ||
( ( V_26 & V_42 ) == V_43 ) ) )
goto V_39;
V_36 = F_2 ( ( V_3 ) V_2 -> V_4 << 32 , V_33 ,
V_30 * V_7 ) ;
V_39:
F_32 ( & V_2 -> V_38 , V_34 ) ;
return V_36 ;
}
static void F_33 ( unsigned long V_9 )
{
unsigned long * V_18 = F_11 ( V_9 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_12 ; V_23 ++ )
if ( F_10 ( V_18 [ V_23 ] ) )
F_8 ( F_16 ( V_18 [ V_23 ] ) ) ;
F_5 ( V_18 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long * V_8 ;
int V_22 ;
if ( ! V_2 || ! V_2 -> V_27 )
return;
V_8 = V_2 -> V_27 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
if ( F_10 ( V_8 [ V_22 ] ) )
F_33 ( V_8 [ V_22 ] ) ;
F_5 ( V_8 ) ;
V_2 -> V_27 = NULL ;
}
static unsigned long F_35 ( struct V_1 * V_2 ,
unsigned long V_44 , int V_29 )
{
unsigned long V_45 ;
V_45 = F_36 ( F_37 ( & V_2 -> V_46 -> V_47 ) + 1 ,
V_7 ) >> V_31 ;
return F_38 ( V_2 -> V_48 , V_2 -> V_6 ,
V_44 , V_29 , 0 , V_45 , 0 ) ;
}
static unsigned long F_39 ( struct V_1 * V_2 , int V_29 )
{
unsigned long V_49 , V_26 ;
int V_50 = 0 ;
F_31 ( & V_2 -> V_51 , V_26 ) ;
V_49 = F_35 ( V_2 , V_2 -> V_52 , V_29 ) ;
if ( V_49 == - 1 ) {
V_49 = F_35 ( V_2 , 0 , V_29 ) ;
V_50 = 1 ;
}
if ( V_49 != - 1 ) {
V_2 -> V_52 = V_49 + V_29 ;
if ( ! V_2 -> V_40 && ! V_41 && V_50 )
F_1 ( V_2 ) ;
}
F_32 ( & V_2 -> V_51 , V_26 ) ;
return V_49 ;
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_49 , int V_29 )
{
unsigned long V_26 ;
F_31 ( & V_2 -> V_51 , V_26 ) ;
if ( ! V_2 -> V_48 )
goto V_53;
F_41 ( V_2 -> V_48 , V_49 , V_29 ) ;
if ( ! V_41 && V_49 >= V_2 -> V_52 )
V_2 -> V_52 = V_49 + V_29 ;
V_53:
F_32 ( & V_2 -> V_51 , V_26 ) ;
}
int F_42 ( struct V_54 * V_47 , V_3 V_55 )
{
if ( ! V_47 -> V_56 || ! F_43 ( V_47 , V_55 ) )
return - V_57 ;
* V_47 -> V_56 = V_55 ;
return 0 ;
}
static T_1 F_44 ( struct V_54 * V_47 , struct V_58 * V_58 ,
unsigned long V_49 , T_2 V_29 ,
enum V_59 V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_45 ( F_46 ( V_47 ) ) ;
unsigned long V_30 , V_63 ;
unsigned long V_28 = F_47 ( V_58 ) + V_49 ;
int V_26 = V_43 ;
T_1 V_21 ;
V_30 = F_48 ( V_28 , V_29 , V_7 ) ;
V_63 = F_39 ( V_2 , V_30 ) ;
if ( V_63 == - 1 )
goto V_64;
V_29 = V_30 * V_7 ;
V_21 = V_2 -> V_5 + V_63 * V_7 ;
if ( V_21 + V_29 > V_2 -> V_65 )
goto V_66;
if ( V_60 == V_67 || V_60 == V_68 )
V_26 |= V_14 ;
if ( ! F_29 ( V_2 , V_28 , V_21 , V_29 , V_26 ) ) {
F_49 ( V_30 , & V_2 -> V_69 -> V_70 ) ;
return V_21 + ( V_49 & ~ V_32 ) ;
}
V_66:
F_40 ( V_2 , V_63 , V_30 ) ;
V_64:
F_50 ( L_1 ) ;
F_51 ( & V_28 , sizeof( V_28 ) ) ;
return V_71 ;
}
static void F_52 ( struct V_54 * V_47 , T_1 V_21 ,
T_2 V_29 , enum V_59 V_60 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_45 ( F_46 ( V_47 ) ) ;
unsigned long V_63 ;
int V_72 ;
V_72 = F_48 ( V_21 , V_29 , V_7 ) ;
V_21 = V_21 & V_32 ;
if ( F_29 ( V_2 , 0 , V_21 , V_72 * V_7 ,
V_14 | V_17 ) ) {
F_50 ( L_2 ) ;
F_51 ( & V_21 , sizeof( V_21 ) ) ;
}
F_49 ( V_72 , & V_2 -> V_69 -> V_73 ) ;
V_63 = ( V_21 - V_2 -> V_5 ) >> V_31 ;
F_40 ( V_2 , V_63 , V_72 ) ;
}
static void * F_53 ( struct V_54 * V_47 , T_2 V_29 ,
T_1 * V_74 , T_4 V_75 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_45 ( F_46 ( V_47 ) ) ;
struct V_58 * V_58 ;
unsigned long V_28 ;
T_1 V_76 ;
V_29 = F_30 ( V_29 ) ;
V_58 = F_54 ( V_75 , F_55 ( V_29 ) ) ;
if ( ! V_58 )
return NULL ;
V_28 = F_47 ( V_58 ) ;
memset ( ( void * ) V_28 , 0 , V_29 ) ;
V_76 = F_44 ( V_47 , V_58 , V_28 % V_7 ,
V_29 , V_77 , NULL ) ;
if ( F_56 ( V_47 , V_76 ) ) {
F_57 ( V_28 , F_55 ( V_29 ) ) ;
return NULL ;
}
F_49 ( V_29 / V_7 , & V_2 -> V_69 -> V_78 ) ;
if ( V_74 )
* V_74 = V_76 ;
return ( void * ) V_28 ;
}
static void F_58 ( struct V_54 * V_47 , T_2 V_29 ,
void * V_28 , T_1 V_74 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_45 ( F_46 ( V_47 ) ) ;
V_29 = F_30 ( V_29 ) ;
F_59 ( V_29 / V_7 , & V_2 -> V_69 -> V_78 ) ;
F_52 ( V_47 , V_74 , V_29 , V_77 , NULL ) ;
F_57 ( ( unsigned long ) V_28 , F_55 ( V_29 ) ) ;
}
static int F_60 ( struct V_54 * V_47 , struct V_79 * V_80 ,
int V_81 , enum V_59 V_82 ,
struct V_61 * V_62 )
{
int V_83 = 0 ;
struct V_79 * V_84 ;
int V_35 ;
F_61 (sg, s, nr_elements, i) {
struct V_58 * V_58 = F_62 ( V_84 ) ;
V_84 -> V_85 = F_44 ( V_47 , V_58 , V_84 -> V_49 ,
V_84 -> V_86 , V_82 , NULL ) ;
if ( ! F_56 ( V_47 , V_84 -> V_85 ) ) {
V_84 -> V_87 = V_84 -> V_86 ;
V_83 ++ ;
} else
goto V_88;
}
V_53:
return V_83 ;
V_88:
F_61 (sg, s, mapped_elements, i) {
if ( V_84 -> V_85 )
F_52 ( V_47 , V_84 -> V_85 , V_84 -> V_87 ,
V_82 , NULL ) ;
V_84 -> V_85 = 0 ;
V_84 -> V_87 = 0 ;
}
V_83 = 0 ;
goto V_53;
}
static void F_63 ( struct V_54 * V_47 , struct V_79 * V_80 ,
int V_81 , enum V_59 V_82 ,
struct V_61 * V_62 )
{
struct V_79 * V_84 ;
int V_35 ;
F_61 (sg, s, nr_elements, i) {
F_52 ( V_47 , V_84 -> V_85 , V_84 -> V_87 , V_82 , NULL ) ;
V_84 -> V_85 = 0 ;
V_84 -> V_87 = 0 ;
}
}
int F_64 ( struct V_1 * V_2 )
{
int V_36 ;
F_65 ( & V_2 -> V_51 ) ;
F_65 ( & V_2 -> V_38 ) ;
V_2 -> V_27 = F_3 () ;
if ( ! V_2 -> V_27 ) {
V_36 = - V_89 ;
goto V_90;
}
V_2 -> V_91 = ( unsigned long ) V_92 - V_93 ;
V_2 -> V_6 = V_2 -> V_91 >> V_31 ;
V_2 -> V_48 = F_66 ( V_2 -> V_6 / 8 ) ;
if ( ! V_2 -> V_48 ) {
V_36 = - V_89 ;
goto V_94;
}
V_36 = F_67 ( V_2 ,
0 ,
V_2 -> V_5 + V_93 ,
V_2 -> V_5 + V_2 -> V_91 - 1 ,
( V_3 ) V_2 -> V_27 ) ;
if ( V_36 )
goto V_94;
return 0 ;
V_94:
F_5 ( V_2 -> V_27 ) ;
V_90:
return V_36 ;
}
void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_2 , 0 ) ;
F_34 ( V_2 ) ;
F_70 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
V_2 -> V_52 = 0 ;
}
static int T_5 F_71 ( void )
{
V_10 = F_72 ( L_3 ,
V_95 , V_96 ,
0 , NULL ) ;
if ( ! V_10 )
return - V_89 ;
V_15 = F_72 ( L_4 ,
V_97 , V_98 ,
0 , NULL ) ;
if ( ! V_15 ) {
F_73 ( V_10 ) ;
return - V_89 ;
}
return 0 ;
}
int T_5 F_74 ( void )
{
return F_71 () ;
}
void F_75 ( void )
{
F_73 ( V_15 ) ;
F_73 ( V_10 ) ;
}
static int T_5 F_76 ( void )
{
F_77 ( V_99 ) ;
return 0 ;
}
static int T_5 F_78 ( char * V_100 )
{
if ( ! strncmp ( V_100 , L_5 , 6 ) )
V_41 = 1 ;
return 0 ;
}
