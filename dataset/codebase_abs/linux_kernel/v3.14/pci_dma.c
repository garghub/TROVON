static unsigned long * F_1 ( void )
{
unsigned long * V_1 , * V_2 ;
V_1 = F_2 ( V_3 , V_4 ) ;
if ( ! V_1 )
return NULL ;
for ( V_2 = V_1 ; V_2 < V_1 + V_5 ; V_2 ++ )
* V_2 = V_6 | V_7 ;
return V_1 ;
}
static void F_3 ( void * V_1 )
{
F_4 ( V_3 , V_1 ) ;
}
static unsigned long * F_5 ( void )
{
unsigned long * V_1 , * V_2 ;
V_1 = F_2 ( V_8 , V_4 ) ;
if ( ! V_1 )
return NULL ;
for ( V_2 = V_1 ; V_2 < V_1 + V_9 ; V_2 ++ )
* V_2 = V_10 | V_7 ;
return V_1 ;
}
static void F_6 ( void * V_1 )
{
F_4 ( V_8 , V_1 ) ;
}
static unsigned long * F_7 ( unsigned long * V_2 )
{
unsigned long * V_11 ;
if ( F_8 ( * V_2 ) )
V_11 = F_9 ( * V_2 ) ;
else {
V_11 = F_1 () ;
if ( ! V_11 )
return NULL ;
F_10 ( V_2 , V_11 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
return V_11 ;
}
static unsigned long * F_13 ( unsigned long * V_2 )
{
unsigned long * V_12 ;
if ( F_8 ( * V_2 ) )
V_12 = F_14 ( * V_2 ) ;
else {
V_12 = F_5 () ;
if ( ! V_12 )
return NULL ;
F_15 ( V_2 , V_12 ) ;
F_16 ( V_2 ) ;
F_12 ( V_2 ) ;
}
return V_12 ;
}
static unsigned long * F_17 ( unsigned long * V_13 , T_1 V_14 )
{
unsigned long * V_11 , * V_12 ;
unsigned int V_15 , V_16 , V_17 ;
V_15 = F_18 ( V_14 ) ;
V_11 = F_7 ( & V_13 [ V_15 ] ) ;
if ( ! V_11 )
return NULL ;
V_16 = F_19 ( V_14 ) ;
V_12 = F_13 ( & V_11 [ V_16 ] ) ;
if ( ! V_12 )
return NULL ;
V_17 = F_20 ( V_14 ) ;
return & V_12 [ V_17 ] ;
}
static void F_21 ( struct V_18 * V_19 , void * V_20 ,
T_1 V_14 , int V_21 )
{
unsigned long * V_2 ;
V_2 = F_17 ( V_19 -> V_22 , V_14 ) ;
if ( ! V_2 ) {
F_22 ( 1 ) ;
return;
}
if ( V_21 & V_10 ) {
F_23 ( V_2 ) ;
return;
} else {
F_24 ( V_2 , V_20 ) ;
F_25 ( V_2 ) ;
}
if ( V_21 & V_7 )
F_26 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
static int F_27 ( struct V_18 * V_19 , unsigned long V_23 ,
T_1 V_14 , T_2 V_24 , int V_21 )
{
unsigned int V_25 = F_28 ( V_24 ) >> V_26 ;
T_3 * V_20 = ( T_3 * ) ( V_23 & V_27 ) ;
T_1 V_28 = V_14 ;
unsigned long V_29 ;
int V_30 , V_31 = 0 ;
if ( ! V_25 )
return - V_32 ;
F_29 ( & V_19 -> V_33 , V_29 ) ;
if ( ! V_19 -> V_22 )
goto V_34;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ ) {
F_21 ( V_19 , V_20 , V_14 , V_21 ) ;
V_20 += V_35 ;
V_14 += V_35 ;
}
if ( ! V_19 -> V_36 &&
( ( V_21 & V_37 ) == V_38 ) )
goto V_34;
V_31 = F_30 ( ( V_39 ) V_19 -> V_40 << 32 , V_28 ,
V_25 * V_35 ) ;
V_34:
F_31 ( & V_19 -> V_33 , V_29 ) ;
return V_31 ;
}
static void F_32 ( unsigned long V_2 )
{
unsigned long * V_11 = F_9 ( V_2 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ )
if ( F_8 ( V_11 [ V_16 ] ) )
F_6 ( F_14 ( V_11 [ V_16 ] ) ) ;
F_3 ( V_11 ) ;
}
static void F_33 ( struct V_18 * V_19 )
{
unsigned long * V_1 ;
int V_15 ;
if ( ! V_19 || ! V_19 -> V_22 )
return;
V_1 = V_19 -> V_22 ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ )
if ( F_8 ( V_1 [ V_15 ] ) )
F_32 ( V_1 [ V_15 ] ) ;
F_3 ( V_1 ) ;
V_19 -> V_22 = NULL ;
}
static unsigned long F_34 ( struct V_18 * V_19 ,
unsigned long V_41 , int V_24 )
{
unsigned long V_42 ;
V_42 = F_35 ( F_36 ( & V_19 -> V_43 -> V_44 ) + 1 ,
V_35 ) >> V_26 ;
return F_37 ( V_19 -> V_45 , V_19 -> V_46 ,
V_41 , V_24 , 0 , V_42 , 0 ) ;
}
static unsigned long F_38 ( struct V_18 * V_19 , int V_24 )
{
unsigned long V_47 , V_21 ;
F_29 ( & V_19 -> V_48 , V_21 ) ;
V_47 = F_34 ( V_19 , V_19 -> V_49 , V_24 ) ;
if ( V_47 == - 1 )
V_47 = F_34 ( V_19 , 0 , V_24 ) ;
if ( V_47 != - 1 ) {
V_19 -> V_49 = V_47 + V_24 ;
if ( V_19 -> V_49 >= V_19 -> V_46 )
V_19 -> V_49 = 0 ;
}
F_31 ( & V_19 -> V_48 , V_21 ) ;
return V_47 ;
}
static void F_39 ( struct V_18 * V_19 , unsigned long V_47 , int V_24 )
{
unsigned long V_21 ;
F_29 ( & V_19 -> V_48 , V_21 ) ;
if ( ! V_19 -> V_45 )
goto V_50;
F_40 ( V_19 -> V_45 , V_47 , V_24 ) ;
if ( V_47 >= V_19 -> V_49 )
V_19 -> V_49 = V_47 + V_24 ;
V_50:
F_31 ( & V_19 -> V_48 , V_21 ) ;
}
int F_41 ( struct V_51 * V_44 , V_39 V_52 )
{
if ( ! V_44 -> V_53 || ! F_42 ( V_44 , V_52 ) )
return - V_54 ;
* V_44 -> V_53 = V_52 ;
return 0 ;
}
static T_1 F_43 ( struct V_51 * V_44 , struct V_55 * V_55 ,
unsigned long V_47 , T_2 V_24 ,
enum V_56 V_57 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_44 ( F_45 ( V_44 ) ) ;
unsigned long V_25 , V_60 ;
unsigned long V_23 = F_46 ( V_55 ) + V_47 ;
int V_21 = V_38 ;
T_1 V_14 ;
V_25 = F_47 ( V_23 , V_24 , V_35 ) ;
V_60 = F_38 ( V_19 , V_25 ) ;
if ( V_60 == - 1 )
goto V_61;
V_24 = V_25 * V_35 ;
V_14 = V_19 -> V_62 + V_60 * V_35 ;
if ( V_14 + V_24 > V_19 -> V_63 )
goto V_64;
if ( V_57 == V_65 || V_57 == V_66 )
V_21 |= V_7 ;
if ( ! F_27 ( V_19 , V_23 , V_14 , V_24 , V_21 ) ) {
F_48 ( V_25 , & V_19 -> V_67 -> V_68 ) ;
return V_14 + ( V_47 & ~ V_27 ) ;
}
V_64:
F_39 ( V_19 , V_60 , V_25 ) ;
V_61:
F_49 ( L_1 ) ;
F_50 ( & V_23 , sizeof( V_23 ) ) ;
return V_69 ;
}
static void F_51 ( struct V_51 * V_44 , T_1 V_14 ,
T_2 V_24 , enum V_56 V_57 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_44 ( F_45 ( V_44 ) ) ;
unsigned long V_60 ;
int V_70 ;
V_70 = F_47 ( V_14 , V_24 , V_35 ) ;
V_14 = V_14 & V_27 ;
if ( F_27 ( V_19 , 0 , V_14 , V_70 * V_35 ,
V_7 | V_10 ) ) {
F_49 ( L_2 ) ;
F_50 ( & V_14 , sizeof( V_14 ) ) ;
}
F_48 ( V_70 , & V_19 -> V_67 -> V_71 ) ;
V_60 = ( V_14 - V_19 -> V_62 ) >> V_26 ;
F_39 ( V_19 , V_60 , V_70 ) ;
}
static void * F_52 ( struct V_51 * V_44 , T_2 V_24 ,
T_1 * V_72 , T_4 V_73 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_44 ( F_45 ( V_44 ) ) ;
struct V_55 * V_55 ;
unsigned long V_23 ;
T_1 V_74 ;
V_24 = F_28 ( V_24 ) ;
V_55 = F_53 ( V_73 , F_54 ( V_24 ) ) ;
if ( ! V_55 )
return NULL ;
V_23 = F_46 ( V_55 ) ;
memset ( ( void * ) V_23 , 0 , V_24 ) ;
V_74 = F_43 ( V_44 , V_55 , V_23 % V_35 ,
V_24 , V_75 , NULL ) ;
if ( F_55 ( V_44 , V_74 ) ) {
F_56 ( V_23 , F_54 ( V_24 ) ) ;
return NULL ;
}
F_48 ( V_24 / V_35 , & V_19 -> V_67 -> V_76 ) ;
if ( V_72 )
* V_72 = V_74 ;
return ( void * ) V_23 ;
}
static void F_57 ( struct V_51 * V_44 , T_2 V_24 ,
void * V_23 , T_1 V_72 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_44 ( F_45 ( V_44 ) ) ;
V_24 = F_28 ( V_24 ) ;
F_58 ( V_24 / V_35 , & V_19 -> V_67 -> V_76 ) ;
F_51 ( V_44 , V_72 , V_24 , V_75 , NULL ) ;
F_56 ( ( unsigned long ) V_23 , F_54 ( V_24 ) ) ;
}
static int F_59 ( struct V_51 * V_44 , struct V_77 * V_78 ,
int V_79 , enum V_56 V_80 ,
struct V_58 * V_59 )
{
int V_81 = 0 ;
struct V_77 * V_82 ;
int V_30 ;
F_60 (sg, s, nr_elements, i) {
struct V_55 * V_55 = F_61 ( V_82 ) ;
V_82 -> V_83 = F_43 ( V_44 , V_55 , V_82 -> V_47 ,
V_82 -> V_84 , V_80 , NULL ) ;
if ( ! F_55 ( V_44 , V_82 -> V_83 ) ) {
V_82 -> V_85 = V_82 -> V_84 ;
V_81 ++ ;
} else
goto V_86;
}
V_50:
return V_81 ;
V_86:
F_60 (sg, s, mapped_elements, i) {
if ( V_82 -> V_83 )
F_51 ( V_44 , V_82 -> V_83 , V_82 -> V_85 ,
V_80 , NULL ) ;
V_82 -> V_83 = 0 ;
V_82 -> V_85 = 0 ;
}
V_81 = 0 ;
goto V_50;
}
static void F_62 ( struct V_51 * V_44 , struct V_77 * V_78 ,
int V_79 , enum V_56 V_80 ,
struct V_58 * V_59 )
{
struct V_77 * V_82 ;
int V_30 ;
F_60 (sg, s, nr_elements, i) {
F_51 ( V_44 , V_82 -> V_83 , V_82 -> V_85 , V_80 , NULL ) ;
V_82 -> V_83 = 0 ;
V_82 -> V_85 = 0 ;
}
}
int F_63 ( struct V_18 * V_19 )
{
int V_31 ;
F_64 ( & V_19 -> V_48 ) ;
F_64 ( & V_19 -> V_33 ) ;
V_19 -> V_22 = F_1 () ;
if ( ! V_19 -> V_22 ) {
V_31 = - V_87 ;
goto V_88;
}
V_19 -> V_89 = ( unsigned long ) V_90 - V_91 ;
V_19 -> V_46 = V_19 -> V_89 >> V_26 ;
V_19 -> V_45 = F_65 ( V_19 -> V_46 / 8 ) ;
if ( ! V_19 -> V_45 ) {
V_31 = - V_87 ;
goto V_92;
}
V_31 = F_66 ( V_19 ,
0 ,
V_19 -> V_62 + V_91 ,
V_19 -> V_62 + V_19 -> V_89 - 1 ,
( V_39 ) V_19 -> V_22 ) ;
if ( V_31 )
goto V_92;
return 0 ;
V_92:
F_3 ( V_19 -> V_22 ) ;
V_88:
return V_31 ;
}
void F_67 ( struct V_18 * V_19 )
{
F_68 ( V_19 , 0 ) ;
F_33 ( V_19 ) ;
F_69 ( V_19 -> V_45 ) ;
V_19 -> V_45 = NULL ;
V_19 -> V_49 = 0 ;
}
static int T_5 F_70 ( void )
{
V_3 = F_71 ( L_3 ,
V_93 , V_94 ,
0 , NULL ) ;
if ( ! V_3 )
return - V_87 ;
V_8 = F_71 ( L_4 ,
V_95 , V_96 ,
0 , NULL ) ;
if ( ! V_8 ) {
F_72 ( V_3 ) ;
return - V_87 ;
}
return 0 ;
}
int T_5 F_73 ( void )
{
return F_70 () ;
}
void F_74 ( void )
{
F_72 ( V_8 ) ;
F_72 ( V_3 ) ;
}
static int T_5 F_75 ( void )
{
F_76 ( V_97 ) ;
return 0 ;
}
