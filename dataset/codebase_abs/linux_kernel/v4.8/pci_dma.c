static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( ( V_3 ) V_2 -> V_4 << 32 , V_2 -> V_5 ,
V_2 -> V_6 * V_7 ) ;
}
unsigned long * F_3 ( void )
{
unsigned long * V_8 , * V_9 ;
V_8 = F_4 ( V_10 , V_11 ) ;
if ( ! V_8 )
return NULL ;
for ( V_9 = V_8 ; V_9 < V_8 + V_12 ; V_9 ++ )
* V_9 = V_13 ;
return V_8 ;
}
static void F_5 ( void * V_8 )
{
F_6 ( V_10 , V_8 ) ;
}
static unsigned long * F_7 ( void )
{
unsigned long * V_8 , * V_9 ;
V_8 = F_4 ( V_14 , V_11 ) ;
if ( ! V_8 )
return NULL ;
for ( V_9 = V_8 ; V_9 < V_8 + V_15 ; V_9 ++ )
* V_9 = V_16 ;
return V_8 ;
}
static void F_8 ( void * V_8 )
{
F_6 ( V_14 , V_8 ) ;
}
static unsigned long * F_9 ( unsigned long * V_9 )
{
unsigned long * V_17 ;
if ( F_10 ( * V_9 ) )
V_17 = F_11 ( * V_9 ) ;
else {
V_17 = F_3 () ;
if ( ! V_17 )
return NULL ;
F_12 ( V_9 , V_17 ) ;
F_13 ( V_9 ) ;
F_14 ( V_9 ) ;
}
return V_17 ;
}
static unsigned long * F_15 ( unsigned long * V_9 )
{
unsigned long * V_18 ;
if ( F_10 ( * V_9 ) )
V_18 = F_16 ( * V_9 ) ;
else {
V_18 = F_7 () ;
if ( ! V_18 )
return NULL ;
F_17 ( V_9 , V_18 ) ;
F_18 ( V_9 ) ;
F_14 ( V_9 ) ;
}
return V_18 ;
}
unsigned long * F_19 ( unsigned long * V_19 , T_1 V_20 )
{
unsigned long * V_17 , * V_18 ;
unsigned int V_21 , V_22 , V_23 ;
V_21 = F_20 ( V_20 ) ;
V_17 = F_9 ( & V_19 [ V_21 ] ) ;
if ( ! V_17 )
return NULL ;
V_22 = F_21 ( V_20 ) ;
V_18 = F_15 ( & V_17 [ V_22 ] ) ;
if ( ! V_18 )
return NULL ;
V_23 = F_22 ( V_20 ) ;
return & V_18 [ V_23 ] ;
}
void F_23 ( unsigned long * V_9 , void * V_24 , int V_25 )
{
if ( V_25 & V_16 ) {
F_24 ( V_9 ) ;
} else {
F_25 ( V_9 , V_24 ) ;
F_26 ( V_9 ) ;
}
if ( V_25 & V_26 )
F_27 ( V_9 ) ;
else
F_14 ( V_9 ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_27 ,
T_1 V_20 , T_2 V_28 , int V_25 )
{
unsigned int V_29 = F_29 ( V_28 ) >> V_30 ;
T_3 * V_24 = ( T_3 * ) ( V_27 & V_31 ) ;
T_1 V_32 = V_20 ;
unsigned long V_33 ;
unsigned long * V_9 ;
int V_34 , V_35 = 0 ;
if ( ! V_29 )
return - V_36 ;
F_30 ( & V_2 -> V_37 , V_33 ) ;
if ( ! V_2 -> V_38 ) {
V_35 = - V_36 ;
goto V_39;
}
for ( V_34 = 0 ; V_34 < V_29 ; V_34 ++ ) {
V_9 = F_19 ( V_2 -> V_38 , V_20 ) ;
if ( ! V_9 ) {
V_35 = - V_40 ;
goto V_41;
}
F_23 ( V_9 , V_24 , V_25 ) ;
V_24 += V_7 ;
V_20 += V_7 ;
}
if ( ! V_2 -> V_42 &&
( ! V_43 ||
( ( V_25 & V_44 ) == V_45 ) ) )
goto V_39;
V_35 = F_2 ( ( V_3 ) V_2 -> V_4 << 32 , V_32 ,
V_29 * V_7 ) ;
V_41:
if ( V_35 && ( ( V_25 & V_44 ) == V_45 ) ) {
V_25 = V_16 ;
while ( V_34 -- > 0 ) {
V_24 -= V_7 ;
V_20 -= V_7 ;
V_9 = F_19 ( V_2 -> V_38 , V_20 ) ;
if ( ! V_9 )
break;
F_23 ( V_9 , V_24 , V_25 ) ;
}
}
V_39:
F_31 ( & V_2 -> V_37 , V_33 ) ;
return V_35 ;
}
void F_32 ( unsigned long V_9 )
{
unsigned long * V_17 = F_11 ( V_9 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
if ( F_10 ( V_17 [ V_22 ] ) )
F_8 ( F_16 ( V_17 [ V_22 ] ) ) ;
F_5 ( V_17 ) ;
}
void F_33 ( unsigned long * V_8 )
{
int V_21 ;
if ( ! V_8 )
return;
for ( V_21 = 0 ; V_21 < V_12 ; V_21 ++ )
if ( F_10 ( V_8 [ V_21 ] ) )
F_32 ( V_8 [ V_21 ] ) ;
F_5 ( V_8 ) ;
}
static unsigned long F_34 ( struct V_46 * V_47 ,
unsigned long V_48 , int V_28 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
unsigned long V_49 ;
V_49 = F_37 ( F_38 ( V_47 ) + 1 ,
V_7 ) >> V_30 ;
return F_39 ( V_2 -> V_50 , V_2 -> V_6 ,
V_48 , V_28 , V_2 -> V_5 >> V_30 ,
V_49 , 0 ) ;
}
static unsigned long F_40 ( struct V_46 * V_47 , int V_28 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
unsigned long V_51 , V_25 ;
int V_52 = 0 ;
F_30 ( & V_2 -> V_53 , V_25 ) ;
V_51 = F_34 ( V_47 , V_2 -> V_54 , V_28 ) ;
if ( V_51 == - 1 ) {
V_51 = F_34 ( V_47 , 0 , V_28 ) ;
V_52 = 1 ;
}
if ( V_51 != - 1 ) {
V_2 -> V_54 = V_51 + V_28 ;
if ( ! V_2 -> V_42 && ! V_43 && V_52 )
F_1 ( V_2 ) ;
}
F_31 ( & V_2 -> V_53 , V_25 ) ;
return V_51 ;
}
static void F_41 ( struct V_46 * V_47 , unsigned long V_51 , int V_28 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
unsigned long V_25 ;
F_30 ( & V_2 -> V_53 , V_25 ) ;
if ( ! V_2 -> V_50 )
goto V_55;
F_42 ( V_2 -> V_50 , V_51 , V_28 ) ;
if ( ! V_43 && V_51 >= V_2 -> V_54 )
V_2 -> V_54 = V_51 + V_28 ;
V_55:
F_31 ( & V_2 -> V_53 , V_25 ) ;
}
static inline void F_43 ( unsigned long V_35 , unsigned long V_56 )
{
struct {
unsigned long V_35 ;
unsigned long V_56 ;
} V_57 V_58 = { V_35 , V_56 } ;
F_44 ( & V_58 , sizeof( V_58 ) ) ;
}
static T_1 F_45 ( struct V_46 * V_47 , struct V_59 * V_59 ,
unsigned long V_51 , T_2 V_28 ,
enum V_60 V_61 ,
unsigned long V_62 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
unsigned long V_29 , V_63 ;
unsigned long V_27 = F_46 ( V_59 ) + V_51 ;
int V_25 = V_45 ;
T_1 V_20 ;
int V_64 ;
V_29 = F_47 ( V_27 , V_28 , V_7 ) ;
V_63 = F_40 ( V_47 , V_29 ) ;
if ( V_63 == - 1 ) {
V_64 = - V_65 ;
goto V_66;
}
V_28 = V_29 * V_7 ;
V_20 = V_2 -> V_5 + V_63 * V_7 ;
if ( V_20 + V_28 > V_2 -> V_67 ) {
V_64 = - V_68 ;
goto V_69;
}
if ( V_61 == V_70 || V_61 == V_71 )
V_25 |= V_26 ;
V_64 = F_28 ( V_2 , V_27 , V_20 , V_28 , V_25 ) ;
if ( V_64 )
goto V_69;
F_48 ( V_29 , & V_2 -> V_72 ) ;
return V_20 + ( V_51 & ~ V_31 ) ;
V_69:
F_41 ( V_47 , V_63 , V_29 ) ;
V_66:
F_49 ( L_1 ) ;
F_43 ( V_64 , V_27 ) ;
return V_73 ;
}
static void F_50 ( struct V_46 * V_47 , T_1 V_20 ,
T_2 V_28 , enum V_60 V_61 ,
unsigned long V_62 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
unsigned long V_63 ;
int V_74 , V_64 ;
V_74 = F_47 ( V_20 , V_28 , V_7 ) ;
V_20 = V_20 & V_31 ;
V_64 = F_28 ( V_2 , 0 , V_20 , V_74 * V_7 ,
V_16 ) ;
if ( V_64 ) {
F_49 ( L_2 ) ;
F_43 ( V_64 , V_20 ) ;
return;
}
F_48 ( V_74 , & V_2 -> V_75 ) ;
V_63 = ( V_20 - V_2 -> V_5 ) >> V_30 ;
F_41 ( V_47 , V_63 , V_74 ) ;
}
static void * F_51 ( struct V_46 * V_47 , T_2 V_28 ,
T_1 * V_76 , T_4 V_77 ,
unsigned long V_62 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
struct V_59 * V_59 ;
unsigned long V_27 ;
T_1 V_78 ;
V_28 = F_29 ( V_28 ) ;
V_59 = F_52 ( V_77 , F_53 ( V_28 ) ) ;
if ( ! V_59 )
return NULL ;
V_27 = F_46 ( V_59 ) ;
memset ( ( void * ) V_27 , 0 , V_28 ) ;
V_78 = F_45 ( V_47 , V_59 , 0 , V_28 , V_79 , 0 ) ;
if ( F_54 ( V_47 , V_78 ) ) {
F_55 ( V_27 , F_53 ( V_28 ) ) ;
return NULL ;
}
F_48 ( V_28 / V_7 , & V_2 -> V_80 ) ;
if ( V_76 )
* V_76 = V_78 ;
return ( void * ) V_27 ;
}
static void F_56 ( struct V_46 * V_47 , T_2 V_28 ,
void * V_27 , T_1 V_76 ,
unsigned long V_62 )
{
struct V_1 * V_2 = F_35 ( F_36 ( V_47 ) ) ;
V_28 = F_29 ( V_28 ) ;
F_57 ( V_28 / V_7 , & V_2 -> V_80 ) ;
F_50 ( V_47 , V_76 , V_28 , V_79 , 0 ) ;
F_55 ( ( unsigned long ) V_27 , F_53 ( V_28 ) ) ;
}
static int F_58 ( struct V_46 * V_47 , struct V_81 * V_82 ,
int V_83 , enum V_60 V_84 ,
unsigned long V_62 )
{
int V_85 = 0 ;
struct V_81 * V_86 ;
int V_34 ;
F_59 (sg, s, nr_elements, i) {
struct V_59 * V_59 = F_60 ( V_86 ) ;
V_86 -> V_87 = F_45 ( V_47 , V_59 , V_86 -> V_51 ,
V_86 -> V_88 , V_84 , 0 ) ;
if ( ! F_54 ( V_47 , V_86 -> V_87 ) ) {
V_86 -> V_89 = V_86 -> V_88 ;
V_85 ++ ;
} else
goto V_90;
}
V_55:
return V_85 ;
V_90:
F_59 (sg, s, mapped_elements, i) {
if ( V_86 -> V_87 )
F_50 ( V_47 , V_86 -> V_87 , V_86 -> V_89 ,
V_84 , 0 ) ;
V_86 -> V_87 = 0 ;
V_86 -> V_89 = 0 ;
}
V_85 = 0 ;
goto V_55;
}
static void F_61 ( struct V_46 * V_47 , struct V_81 * V_82 ,
int V_83 , enum V_60 V_84 ,
unsigned long V_62 )
{
struct V_81 * V_86 ;
int V_34 ;
F_59 (sg, s, nr_elements, i) {
F_50 ( V_47 , V_86 -> V_87 , V_86 -> V_89 , V_84 ,
0 ) ;
V_86 -> V_87 = 0 ;
V_86 -> V_89 = 0 ;
}
}
int F_62 ( struct V_1 * V_2 )
{
int V_35 ;
F_63 ( V_2 -> V_91 ) ;
F_64 ( & V_2 -> V_53 ) ;
F_64 ( & V_2 -> V_37 ) ;
V_2 -> V_38 = F_3 () ;
if ( ! V_2 -> V_38 ) {
V_35 = - V_40 ;
goto V_55;
}
V_2 -> V_5 = F_29 ( V_2 -> V_5 ) ;
V_2 -> V_92 = F_65 ( ( V_3 ) V_93 ,
V_94 - V_2 -> V_5 ,
V_2 -> V_67 - V_2 -> V_5 + 1 ) ;
V_2 -> V_67 = V_2 -> V_5 + V_2 -> V_92 - 1 ;
V_2 -> V_6 = V_2 -> V_92 >> V_30 ;
V_2 -> V_50 = F_66 ( V_2 -> V_6 / 8 ) ;
if ( ! V_2 -> V_50 ) {
V_35 = - V_40 ;
goto V_95;
}
V_35 = F_67 ( V_2 , 0 , V_2 -> V_5 , V_2 -> V_67 ,
( V_3 ) V_2 -> V_38 ) ;
if ( V_35 )
goto V_96;
return 0 ;
V_96:
F_68 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
V_95:
F_5 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
V_55:
return V_35 ;
}
void F_69 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_91 ) ;
F_70 ( V_2 , 0 ) ;
F_33 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
F_68 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_54 = 0 ;
}
static int T_5 F_71 ( void )
{
V_10 = F_72 ( L_3 ,
V_97 , V_98 ,
0 , NULL ) ;
if ( ! V_10 )
return - V_40 ;
V_14 = F_72 ( L_4 ,
V_99 , V_100 ,
0 , NULL ) ;
if ( ! V_14 ) {
F_73 ( V_10 ) ;
return - V_40 ;
}
return 0 ;
}
int T_5 F_74 ( void )
{
return F_71 () ;
}
void F_75 ( void )
{
F_73 ( V_14 ) ;
F_73 ( V_10 ) ;
}
static int T_5 F_76 ( void )
{
F_77 ( V_101 ) ;
return 0 ;
}
static int T_5 F_78 ( char * V_102 )
{
if ( ! strncmp ( V_102 , L_5 , 6 ) )
V_43 = 1 ;
return 0 ;
}
