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
static T_1 F_42 ( struct V_54 * V_47 , struct V_55 * V_55 ,
unsigned long V_49 , T_2 V_29 ,
enum V_56 V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_43 ( F_44 ( V_47 ) ) ;
unsigned long V_30 , V_60 ;
unsigned long V_28 = F_45 ( V_55 ) + V_49 ;
int V_26 = V_43 ;
T_1 V_21 ;
V_30 = F_46 ( V_28 , V_29 , V_7 ) ;
V_60 = F_39 ( V_2 , V_30 ) ;
if ( V_60 == - 1 )
goto V_61;
V_29 = V_30 * V_7 ;
V_21 = V_2 -> V_5 + V_60 * V_7 ;
if ( V_21 + V_29 > V_2 -> V_62 )
goto V_63;
if ( V_57 == V_64 || V_57 == V_65 )
V_26 |= V_14 ;
if ( ! F_29 ( V_2 , V_28 , V_21 , V_29 , V_26 ) ) {
F_47 ( V_30 , & V_2 -> V_66 ) ;
return V_21 + ( V_49 & ~ V_32 ) ;
}
V_63:
F_40 ( V_2 , V_60 , V_30 ) ;
V_61:
F_48 ( L_1 ) ;
F_49 ( & V_28 , sizeof( V_28 ) ) ;
return V_67 ;
}
static void F_50 ( struct V_54 * V_47 , T_1 V_21 ,
T_2 V_29 , enum V_56 V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_43 ( F_44 ( V_47 ) ) ;
unsigned long V_60 ;
int V_68 ;
V_68 = F_46 ( V_21 , V_29 , V_7 ) ;
V_21 = V_21 & V_32 ;
if ( F_29 ( V_2 , 0 , V_21 , V_68 * V_7 ,
V_14 | V_17 ) ) {
F_48 ( L_2 ) ;
F_49 ( & V_21 , sizeof( V_21 ) ) ;
}
F_47 ( V_68 , & V_2 -> V_69 ) ;
V_60 = ( V_21 - V_2 -> V_5 ) >> V_31 ;
F_40 ( V_2 , V_60 , V_68 ) ;
}
static void * F_51 ( struct V_54 * V_47 , T_2 V_29 ,
T_1 * V_70 , T_4 V_71 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_43 ( F_44 ( V_47 ) ) ;
struct V_55 * V_55 ;
unsigned long V_28 ;
T_1 V_72 ;
V_29 = F_30 ( V_29 ) ;
V_55 = F_52 ( V_71 , F_53 ( V_29 ) ) ;
if ( ! V_55 )
return NULL ;
V_28 = F_45 ( V_55 ) ;
memset ( ( void * ) V_28 , 0 , V_29 ) ;
V_72 = F_42 ( V_47 , V_55 , V_28 % V_7 ,
V_29 , V_73 , NULL ) ;
if ( F_54 ( V_47 , V_72 ) ) {
F_55 ( V_28 , F_53 ( V_29 ) ) ;
return NULL ;
}
F_47 ( V_29 / V_7 , & V_2 -> V_74 ) ;
if ( V_70 )
* V_70 = V_72 ;
return ( void * ) V_28 ;
}
static void F_56 ( struct V_54 * V_47 , T_2 V_29 ,
void * V_28 , T_1 V_70 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_43 ( F_44 ( V_47 ) ) ;
V_29 = F_30 ( V_29 ) ;
F_57 ( V_29 / V_7 , & V_2 -> V_74 ) ;
F_50 ( V_47 , V_70 , V_29 , V_73 , NULL ) ;
F_55 ( ( unsigned long ) V_28 , F_53 ( V_29 ) ) ;
}
static int F_58 ( struct V_54 * V_47 , struct V_75 * V_76 ,
int V_77 , enum V_56 V_78 ,
struct V_58 * V_59 )
{
int V_79 = 0 ;
struct V_75 * V_80 ;
int V_35 ;
F_59 (sg, s, nr_elements, i) {
struct V_55 * V_55 = F_60 ( V_80 ) ;
V_80 -> V_81 = F_42 ( V_47 , V_55 , V_80 -> V_49 ,
V_80 -> V_82 , V_78 , NULL ) ;
if ( ! F_54 ( V_47 , V_80 -> V_81 ) ) {
V_80 -> V_83 = V_80 -> V_82 ;
V_79 ++ ;
} else
goto V_84;
}
V_53:
return V_79 ;
V_84:
F_59 (sg, s, mapped_elements, i) {
if ( V_80 -> V_81 )
F_50 ( V_47 , V_80 -> V_81 , V_80 -> V_83 ,
V_78 , NULL ) ;
V_80 -> V_81 = 0 ;
V_80 -> V_83 = 0 ;
}
V_79 = 0 ;
goto V_53;
}
static void F_61 ( struct V_54 * V_47 , struct V_75 * V_76 ,
int V_77 , enum V_56 V_78 ,
struct V_58 * V_59 )
{
struct V_75 * V_80 ;
int V_35 ;
F_59 (sg, s, nr_elements, i) {
F_50 ( V_47 , V_80 -> V_81 , V_80 -> V_83 , V_78 , NULL ) ;
V_80 -> V_81 = 0 ;
V_80 -> V_83 = 0 ;
}
}
int F_62 ( struct V_1 * V_2 )
{
int V_36 ;
F_63 ( & V_2 -> V_51 ) ;
F_63 ( & V_2 -> V_38 ) ;
V_2 -> V_27 = F_3 () ;
if ( ! V_2 -> V_27 ) {
V_36 = - V_85 ;
goto V_86;
}
V_2 -> V_87 = ( unsigned long ) V_88 - V_89 ;
V_2 -> V_6 = V_2 -> V_87 >> V_31 ;
V_2 -> V_48 = F_64 ( V_2 -> V_6 / 8 ) ;
if ( ! V_2 -> V_48 ) {
V_36 = - V_85 ;
goto V_90;
}
V_36 = F_65 ( V_2 ,
0 ,
V_2 -> V_5 + V_89 ,
V_2 -> V_5 + V_2 -> V_87 - 1 ,
( V_3 ) V_2 -> V_27 ) ;
if ( V_36 )
goto V_90;
return 0 ;
V_90:
F_5 ( V_2 -> V_27 ) ;
V_86:
return V_36 ;
}
void F_66 ( struct V_1 * V_2 )
{
F_67 ( V_2 , 0 ) ;
F_34 ( V_2 ) ;
F_68 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
V_2 -> V_52 = 0 ;
}
static int T_5 F_69 ( void )
{
V_10 = F_70 ( L_3 ,
V_91 , V_92 ,
0 , NULL ) ;
if ( ! V_10 )
return - V_85 ;
V_15 = F_70 ( L_4 ,
V_93 , V_94 ,
0 , NULL ) ;
if ( ! V_15 ) {
F_71 ( V_10 ) ;
return - V_85 ;
}
return 0 ;
}
int T_5 F_72 ( void )
{
return F_69 () ;
}
void F_73 ( void )
{
F_71 ( V_15 ) ;
F_71 ( V_10 ) ;
}
static int T_5 F_74 ( void )
{
F_75 ( V_95 ) ;
return 0 ;
}
static int T_5 F_76 ( char * V_96 )
{
if ( ! strncmp ( V_96 , L_5 , 6 ) )
V_41 = 1 ;
return 0 ;
}
