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
static unsigned long F_34 ( struct V_1 * V_2 ,
unsigned long V_46 , int V_28 )
{
unsigned long V_47 ;
V_47 = F_35 ( F_36 ( & V_2 -> V_48 -> V_49 ) + 1 ,
V_7 ) >> V_30 ;
return F_37 ( V_2 -> V_50 , V_2 -> V_6 ,
V_46 , V_28 , 0 , V_47 , 0 ) ;
}
static unsigned long F_38 ( struct V_1 * V_2 , int V_28 )
{
unsigned long V_51 , V_25 ;
int V_52 = 0 ;
F_30 ( & V_2 -> V_53 , V_25 ) ;
V_51 = F_34 ( V_2 , V_2 -> V_54 , V_28 ) ;
if ( V_51 == - 1 ) {
V_51 = F_34 ( V_2 , 0 , V_28 ) ;
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
static void F_39 ( struct V_1 * V_2 , unsigned long V_51 , int V_28 )
{
unsigned long V_25 ;
F_30 ( & V_2 -> V_53 , V_25 ) ;
if ( ! V_2 -> V_50 )
goto V_55;
F_40 ( V_2 -> V_50 , V_51 , V_28 ) ;
if ( ! V_43 && V_51 >= V_2 -> V_54 )
V_2 -> V_54 = V_51 + V_28 ;
V_55:
F_31 ( & V_2 -> V_53 , V_25 ) ;
}
static inline void F_41 ( unsigned long V_35 , unsigned long V_56 )
{
struct {
unsigned long V_35 ;
unsigned long V_56 ;
} V_57 V_58 = { V_35 , V_56 } ;
F_42 ( & V_58 , sizeof( V_58 ) ) ;
}
static T_1 F_43 ( struct V_59 * V_49 , struct V_60 * V_60 ,
unsigned long V_51 , T_2 V_28 ,
enum V_61 V_62 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( F_45 ( V_49 ) ) ;
unsigned long V_29 , V_65 ;
unsigned long V_27 = F_46 ( V_60 ) + V_51 ;
int V_25 = V_45 ;
T_1 V_20 ;
int V_66 ;
V_29 = F_47 ( V_27 , V_28 , V_7 ) ;
V_65 = F_38 ( V_2 , V_29 ) ;
if ( V_65 == - 1 ) {
V_66 = - V_67 ;
goto V_68;
}
V_28 = V_29 * V_7 ;
V_20 = V_2 -> V_5 + V_65 * V_7 ;
if ( V_20 + V_28 > V_2 -> V_69 ) {
V_66 = - V_70 ;
goto V_71;
}
if ( V_62 == V_72 || V_62 == V_73 )
V_25 |= V_26 ;
V_66 = F_28 ( V_2 , V_27 , V_20 , V_28 , V_25 ) ;
if ( V_66 )
goto V_71;
F_48 ( V_29 , & V_2 -> V_74 ) ;
return V_20 + ( V_51 & ~ V_31 ) ;
V_71:
F_39 ( V_2 , V_65 , V_29 ) ;
V_68:
F_49 ( L_1 ) ;
F_41 ( V_66 , V_27 ) ;
return V_75 ;
}
static void F_50 ( struct V_59 * V_49 , T_1 V_20 ,
T_2 V_28 , enum V_61 V_62 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( F_45 ( V_49 ) ) ;
unsigned long V_65 ;
int V_76 , V_66 ;
V_76 = F_47 ( V_20 , V_28 , V_7 ) ;
V_20 = V_20 & V_31 ;
V_66 = F_28 ( V_2 , 0 , V_20 , V_76 * V_7 ,
V_16 ) ;
if ( V_66 ) {
F_49 ( L_2 ) ;
F_41 ( V_66 , V_20 ) ;
return;
}
F_48 ( V_76 , & V_2 -> V_77 ) ;
V_65 = ( V_20 - V_2 -> V_5 ) >> V_30 ;
F_39 ( V_2 , V_65 , V_76 ) ;
}
static void * F_51 ( struct V_59 * V_49 , T_2 V_28 ,
T_1 * V_78 , T_4 V_79 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( F_45 ( V_49 ) ) ;
struct V_60 * V_60 ;
unsigned long V_27 ;
T_1 V_80 ;
V_28 = F_29 ( V_28 ) ;
V_60 = F_52 ( V_79 , F_53 ( V_28 ) ) ;
if ( ! V_60 )
return NULL ;
V_27 = F_46 ( V_60 ) ;
memset ( ( void * ) V_27 , 0 , V_28 ) ;
V_80 = F_43 ( V_49 , V_60 , V_27 % V_7 ,
V_28 , V_81 , NULL ) ;
if ( F_54 ( V_49 , V_80 ) ) {
F_55 ( V_27 , F_53 ( V_28 ) ) ;
return NULL ;
}
F_48 ( V_28 / V_7 , & V_2 -> V_82 ) ;
if ( V_78 )
* V_78 = V_80 ;
return ( void * ) V_27 ;
}
static void F_56 ( struct V_59 * V_49 , T_2 V_28 ,
void * V_27 , T_1 V_78 ,
struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( F_45 ( V_49 ) ) ;
V_28 = F_29 ( V_28 ) ;
F_57 ( V_28 / V_7 , & V_2 -> V_82 ) ;
F_50 ( V_49 , V_78 , V_28 , V_81 , NULL ) ;
F_55 ( ( unsigned long ) V_27 , F_53 ( V_28 ) ) ;
}
static int F_58 ( struct V_59 * V_49 , struct V_83 * V_84 ,
int V_85 , enum V_61 V_86 ,
struct V_63 * V_64 )
{
int V_87 = 0 ;
struct V_83 * V_88 ;
int V_34 ;
F_59 (sg, s, nr_elements, i) {
struct V_60 * V_60 = F_60 ( V_88 ) ;
V_88 -> V_89 = F_43 ( V_49 , V_60 , V_88 -> V_51 ,
V_88 -> V_90 , V_86 , NULL ) ;
if ( ! F_54 ( V_49 , V_88 -> V_89 ) ) {
V_88 -> V_91 = V_88 -> V_90 ;
V_87 ++ ;
} else
goto V_92;
}
V_55:
return V_87 ;
V_92:
F_59 (sg, s, mapped_elements, i) {
if ( V_88 -> V_89 )
F_50 ( V_49 , V_88 -> V_89 , V_88 -> V_91 ,
V_86 , NULL ) ;
V_88 -> V_89 = 0 ;
V_88 -> V_91 = 0 ;
}
V_87 = 0 ;
goto V_55;
}
static void F_61 ( struct V_59 * V_49 , struct V_83 * V_84 ,
int V_85 , enum V_61 V_86 ,
struct V_63 * V_64 )
{
struct V_83 * V_88 ;
int V_34 ;
F_59 (sg, s, nr_elements, i) {
F_50 ( V_49 , V_88 -> V_89 , V_88 -> V_91 , V_86 , NULL ) ;
V_88 -> V_89 = 0 ;
V_88 -> V_91 = 0 ;
}
}
int F_62 ( struct V_1 * V_2 )
{
int V_35 ;
F_63 ( V_2 -> V_93 ) ;
F_64 ( & V_2 -> V_53 ) ;
F_64 ( & V_2 -> V_37 ) ;
V_2 -> V_38 = F_3 () ;
if ( ! V_2 -> V_38 ) {
V_35 = - V_40 ;
goto V_94;
}
V_2 -> V_95 = ( unsigned long ) V_96 - V_97 ;
V_2 -> V_6 = V_2 -> V_95 >> V_30 ;
V_2 -> V_50 = F_65 ( V_2 -> V_6 / 8 ) ;
if ( ! V_2 -> V_50 ) {
V_35 = - V_40 ;
goto V_98;
}
V_35 = F_66 ( V_2 ,
0 ,
V_2 -> V_5 + V_97 ,
V_2 -> V_5 + V_2 -> V_95 - 1 ,
( V_3 ) V_2 -> V_38 ) ;
if ( V_35 )
goto V_98;
return 0 ;
V_98:
F_5 ( V_2 -> V_38 ) ;
V_94:
return V_35 ;
}
void F_67 ( struct V_1 * V_2 )
{
F_63 ( V_2 -> V_93 ) ;
F_68 ( V_2 , 0 ) ;
F_33 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
F_69 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
V_2 -> V_54 = 0 ;
}
static int T_5 F_70 ( void )
{
V_10 = F_71 ( L_3 ,
V_99 , V_100 ,
0 , NULL ) ;
if ( ! V_10 )
return - V_40 ;
V_14 = F_71 ( L_4 ,
V_101 , V_102 ,
0 , NULL ) ;
if ( ! V_14 ) {
F_72 ( V_10 ) ;
return - V_40 ;
}
return 0 ;
}
int T_5 F_73 ( void )
{
return F_70 () ;
}
void F_74 ( void )
{
F_72 ( V_14 ) ;
F_72 ( V_10 ) ;
}
static int T_5 F_75 ( void )
{
F_76 ( V_103 ) ;
return 0 ;
}
static int T_5 F_77 ( char * V_104 )
{
if ( ! strncmp ( V_104 , L_5 , 6 ) )
V_43 = 1 ;
return 0 ;
}
