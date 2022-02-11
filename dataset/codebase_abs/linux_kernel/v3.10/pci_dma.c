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
if ( ! V_19 -> V_22 ) {
F_30 ( & V_19 -> V_34 -> V_35 , L_1 ) ;
goto V_36;
}
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ ) {
F_21 ( V_19 , V_20 , V_14 , V_21 ) ;
V_20 += V_37 ;
V_14 += V_37 ;
}
if ( ! V_19 -> V_38 &&
( ( V_21 & V_39 ) == V_40 ) )
goto V_36;
V_31 = F_31 ( ( V_41 ) V_19 -> V_42 << 32 , V_28 ,
V_25 * V_37 ) ;
V_36:
F_32 ( & V_19 -> V_33 , V_29 ) ;
return V_31 ;
}
static void F_33 ( unsigned long V_2 )
{
unsigned long * V_11 = F_9 ( V_2 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ )
if ( F_8 ( V_11 [ V_16 ] ) )
F_6 ( F_14 ( V_11 [ V_16 ] ) ) ;
F_3 ( V_11 ) ;
}
static void F_34 ( struct V_18 * V_19 )
{
unsigned long * V_1 ;
int V_15 ;
if ( ! V_19 || ! V_19 -> V_22 )
return;
V_1 = V_19 -> V_22 ;
for ( V_15 = 0 ; V_15 < V_5 ; V_15 ++ )
if ( F_8 ( V_1 [ V_15 ] ) )
F_33 ( V_1 [ V_15 ] ) ;
F_3 ( V_1 ) ;
V_19 -> V_22 = NULL ;
}
static unsigned long F_35 ( struct V_18 * V_19 , unsigned long V_43 ,
int V_24 )
{
unsigned long V_44 = 0x1000000 ;
return F_36 ( V_19 -> V_45 , V_19 -> V_46 ,
V_43 , V_24 , 0 , V_44 , 0 ) ;
}
static unsigned long F_37 ( struct V_18 * V_19 , int V_24 )
{
unsigned long V_47 , V_21 ;
F_29 ( & V_19 -> V_48 , V_21 ) ;
V_47 = F_35 ( V_19 , V_19 -> V_49 , V_24 ) ;
if ( V_47 == - 1 )
V_47 = F_35 ( V_19 , 0 , V_24 ) ;
if ( V_47 != - 1 ) {
V_19 -> V_49 = V_47 + V_24 ;
if ( V_19 -> V_49 >= V_19 -> V_46 )
V_19 -> V_49 = 0 ;
}
F_32 ( & V_19 -> V_48 , V_21 ) ;
return V_47 ;
}
static void F_38 ( struct V_18 * V_19 , unsigned long V_47 , int V_24 )
{
unsigned long V_21 ;
F_29 ( & V_19 -> V_48 , V_21 ) ;
if ( ! V_19 -> V_45 )
goto V_50;
F_39 ( V_19 -> V_45 , V_47 , V_24 ) ;
if ( V_47 >= V_19 -> V_49 )
V_19 -> V_49 = V_47 + V_24 ;
V_50:
F_32 ( & V_19 -> V_48 , V_21 ) ;
}
int F_40 ( struct V_51 * V_35 , V_41 V_52 )
{
if ( ! V_35 -> V_53 || ! F_41 ( V_35 , V_52 ) )
return - V_54 ;
* V_35 -> V_53 = V_52 ;
return 0 ;
}
static T_1 F_42 ( struct V_51 * V_35 , struct V_55 * V_55 ,
unsigned long V_47 , T_2 V_24 ,
enum V_56 V_57 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_43 ( F_44 ( V_35 , struct V_60 , V_35 ) ) ;
unsigned long V_25 , V_61 ;
unsigned long V_23 = F_45 ( V_55 ) + V_47 ;
int V_21 = V_40 ;
T_1 V_14 ;
V_25 = F_46 ( V_23 , V_24 , V_37 ) ;
V_61 = F_37 ( V_19 , V_25 ) ;
if ( V_61 == - 1 )
goto V_62;
V_24 = V_25 * V_37 ;
V_14 = V_19 -> V_63 + V_61 * V_37 ;
if ( V_14 + V_24 > V_19 -> V_64 ) {
F_30 ( V_35 , L_2 ,
V_14 , V_24 , V_19 -> V_64 ) ;
goto V_65;
}
if ( V_57 == V_66 || V_57 == V_67 )
V_21 |= V_7 ;
if ( ! F_27 ( V_19 , V_23 , V_14 , V_24 , V_21 ) ) {
F_47 ( V_25 , ( V_68 * ) & V_19 -> V_69 -> V_70 ) ;
return V_14 + ( V_47 & ~ V_27 ) ;
}
V_65:
F_38 ( V_19 , V_61 , V_25 ) ;
V_62:
F_30 ( V_35 , L_3 , V_23 ) ;
return V_71 ;
}
static void F_48 ( struct V_51 * V_35 , T_1 V_14 ,
T_2 V_24 , enum V_56 V_57 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_43 ( F_44 ( V_35 , struct V_60 , V_35 ) ) ;
unsigned long V_61 ;
int V_72 ;
V_72 = F_46 ( V_14 , V_24 , V_37 ) ;
V_14 = V_14 & V_27 ;
if ( F_27 ( V_19 , 0 , V_14 , V_72 * V_37 ,
V_7 | V_10 ) )
F_30 ( V_35 , L_4 , V_14 ) ;
F_47 ( V_72 , ( V_68 * ) & V_19 -> V_69 -> V_73 ) ;
V_61 = ( V_14 - V_19 -> V_63 ) >> V_26 ;
F_38 ( V_19 , V_61 , V_72 ) ;
}
static void * F_49 ( struct V_51 * V_35 , T_2 V_24 ,
T_1 * V_74 , T_4 V_75 ,
struct V_58 * V_59 )
{
struct V_18 * V_19 = F_43 ( F_44 ( V_35 , struct V_60 , V_35 ) ) ;
struct V_55 * V_55 ;
unsigned long V_23 ;
T_1 V_76 ;
V_24 = F_28 ( V_24 ) ;
V_55 = F_50 ( V_75 , F_51 ( V_24 ) ) ;
if ( ! V_55 )
return NULL ;
F_47 ( V_24 / V_37 , ( V_68 * ) & V_19 -> V_69 -> V_77 ) ;
V_23 = F_45 ( V_55 ) ;
memset ( ( void * ) V_23 , 0 , V_24 ) ;
V_76 = F_42 ( V_35 , V_55 , V_23 % V_37 ,
V_24 , V_78 , NULL ) ;
if ( F_52 ( V_35 , V_76 ) ) {
F_53 ( V_23 , F_51 ( V_24 ) ) ;
return NULL ;
}
if ( V_74 )
* V_74 = V_76 ;
return ( void * ) V_23 ;
}
static void F_54 ( struct V_51 * V_35 , T_2 V_24 ,
void * V_23 , T_1 V_74 ,
struct V_58 * V_59 )
{
F_48 ( V_35 , V_74 , F_28 ( V_24 ) ,
V_78 , NULL ) ;
F_53 ( ( unsigned long ) V_23 , F_51 ( V_24 ) ) ;
}
static int F_55 ( struct V_51 * V_35 , struct V_79 * V_80 ,
int V_81 , enum V_56 V_82 ,
struct V_58 * V_59 )
{
int V_83 = 0 ;
struct V_79 * V_84 ;
int V_30 ;
F_56 (sg, s, nr_elements, i) {
struct V_55 * V_55 = F_57 ( V_84 ) ;
V_84 -> V_85 = F_42 ( V_35 , V_55 , V_84 -> V_47 ,
V_84 -> V_86 , V_82 , NULL ) ;
if ( ! F_52 ( V_35 , V_84 -> V_85 ) ) {
V_84 -> V_87 = V_84 -> V_86 ;
V_83 ++ ;
} else
goto V_88;
}
V_50:
return V_83 ;
V_88:
F_56 (sg, s, mapped_elements, i) {
if ( V_84 -> V_85 )
F_48 ( V_35 , V_84 -> V_85 , V_84 -> V_87 ,
V_82 , NULL ) ;
V_84 -> V_85 = 0 ;
V_84 -> V_87 = 0 ;
}
V_83 = 0 ;
goto V_50;
}
static void F_58 ( struct V_51 * V_35 , struct V_79 * V_80 ,
int V_81 , enum V_56 V_82 ,
struct V_58 * V_59 )
{
struct V_79 * V_84 ;
int V_30 ;
F_56 (sg, s, nr_elements, i) {
F_48 ( V_35 , V_84 -> V_85 , V_84 -> V_87 , V_82 , NULL ) ;
V_84 -> V_85 = 0 ;
V_84 -> V_87 = 0 ;
}
}
int F_59 ( struct V_18 * V_19 )
{
unsigned int V_89 ;
int V_31 ;
F_60 ( & V_19 -> V_48 ) ;
F_60 ( & V_19 -> V_33 ) ;
V_19 -> V_22 = F_1 () ;
if ( ! V_19 -> V_22 ) {
V_31 = - V_90 ;
goto V_91;
}
V_19 -> V_92 = ( unsigned long ) V_93 - V_94 ;
V_19 -> V_46 = V_19 -> V_92 >> V_26 ;
V_89 = F_51 ( V_19 -> V_46 / 8 ) ;
F_61 ( L_5 ,
V_19 -> V_92 , V_19 -> V_46 , V_89 ) ;
V_19 -> V_45 = ( void * ) F_62 ( V_95 | V_96 ,
V_89 ) ;
if ( ! V_19 -> V_45 ) {
V_31 = - V_90 ;
goto V_97;
}
V_31 = F_63 ( V_19 ,
0 ,
V_19 -> V_63 + V_94 ,
V_19 -> V_63 + V_19 -> V_92 - 1 ,
( V_41 ) V_19 -> V_22 ) ;
if ( V_31 )
goto V_97;
return 0 ;
V_97:
F_3 ( V_19 -> V_22 ) ;
V_91:
return V_31 ;
}
void F_64 ( struct V_18 * V_19 )
{
F_65 ( V_19 , 0 ) ;
F_34 ( V_19 ) ;
F_53 ( ( unsigned long ) V_19 -> V_45 ,
F_51 ( V_19 -> V_46 / 8 ) ) ;
V_19 -> V_45 = NULL ;
V_19 -> V_49 = 0 ;
}
static int T_5 F_66 ( void )
{
V_3 = F_67 ( L_6 ,
V_98 , V_99 ,
0 , NULL ) ;
if ( ! V_3 )
return - V_90 ;
V_8 = F_67 ( L_7 ,
V_100 , V_101 ,
0 , NULL ) ;
if ( ! V_8 ) {
F_68 ( V_3 ) ;
return - V_90 ;
}
return 0 ;
}
int T_5 F_69 ( void )
{
return F_66 () ;
}
void F_70 ( void )
{
F_68 ( V_8 ) ;
F_68 ( V_3 ) ;
}
static int T_5 F_71 ( void )
{
F_72 ( V_102 ) ;
return 0 ;
}
