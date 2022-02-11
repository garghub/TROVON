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
unsigned long V_32 ;
unsigned long * V_9 ;
int V_33 , V_34 = 0 ;
if ( ! V_29 )
return - V_35 ;
F_30 ( & V_2 -> V_36 , V_32 ) ;
if ( ! V_2 -> V_37 ) {
V_34 = - V_35 ;
goto V_38;
}
for ( V_33 = 0 ; V_33 < V_29 ; V_33 ++ ) {
V_9 = F_19 ( V_2 -> V_37 , V_20 ) ;
if ( ! V_9 ) {
V_34 = - V_39 ;
goto V_40;
}
F_23 ( V_9 , V_24 , V_25 ) ;
V_24 += V_7 ;
V_20 += V_7 ;
}
V_40:
if ( V_34 && ( ( V_25 & V_41 ) == V_42 ) ) {
V_25 = V_16 ;
while ( V_33 -- > 0 ) {
V_24 -= V_7 ;
V_20 -= V_7 ;
V_9 = F_19 ( V_2 -> V_37 , V_20 ) ;
if ( ! V_9 )
break;
F_23 ( V_9 , V_24 , V_25 ) ;
}
}
V_38:
F_31 ( & V_2 -> V_36 , V_32 ) ;
return V_34 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_20 ,
T_2 V_28 , int V_25 )
{
if ( ( V_25 & V_41 ) == V_42 ) {
if ( ! V_2 -> V_43 )
return 0 ;
} else {
if ( ! V_44 )
return 0 ;
}
return F_2 ( ( V_3 ) V_2 -> V_4 << 32 , V_20 ,
F_29 ( V_28 ) ) ;
}
static int F_33 ( struct V_1 * V_2 , unsigned long V_27 ,
T_1 V_20 , T_2 V_28 , int V_25 )
{
int V_34 ;
V_34 = F_28 ( V_2 , V_27 , V_20 , V_28 , V_25 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_32 ( V_2 , V_20 , V_28 , V_25 ) ;
if ( V_34 && ( ( V_25 & V_41 ) == V_42 ) )
F_28 ( V_2 , V_27 , V_20 , V_28 , V_16 ) ;
return V_34 ;
}
void F_34 ( unsigned long V_9 )
{
unsigned long * V_17 = F_11 ( V_9 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
if ( F_10 ( V_17 [ V_22 ] ) )
F_8 ( F_16 ( V_17 [ V_22 ] ) ) ;
F_5 ( V_17 ) ;
}
void F_35 ( unsigned long * V_8 )
{
int V_21 ;
if ( ! V_8 )
return;
for ( V_21 = 0 ; V_21 < V_12 ; V_21 ++ )
if ( F_10 ( V_8 [ V_21 ] ) )
F_34 ( V_8 [ V_21 ] ) ;
F_5 ( V_8 ) ;
}
static unsigned long F_36 ( struct V_45 * V_46 ,
unsigned long V_47 , int V_28 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
unsigned long V_48 ;
V_48 = F_39 ( F_40 ( V_46 ) + 1 ,
V_7 ) >> V_30 ;
return F_41 ( V_2 -> V_49 , V_2 -> V_6 ,
V_47 , V_28 , V_2 -> V_5 >> V_30 ,
V_48 , 0 ) ;
}
static T_1 F_42 ( struct V_45 * V_46 , int V_28 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
unsigned long V_50 , V_25 ;
F_30 ( & V_2 -> V_51 , V_25 ) ;
V_50 = F_36 ( V_46 , V_2 -> V_52 , V_28 ) ;
if ( V_50 == - 1 ) {
if ( ! V_44 ) {
if ( F_1 ( V_2 ) )
goto V_53;
F_43 ( V_2 -> V_49 , V_2 -> V_49 ,
V_2 -> V_54 , V_2 -> V_6 ) ;
F_44 ( V_2 -> V_54 , V_2 -> V_6 ) ;
}
V_50 = F_36 ( V_46 , 0 , V_28 ) ;
if ( V_50 == - 1 )
goto V_53;
}
V_2 -> V_52 = V_50 + V_28 ;
F_31 ( & V_2 -> V_51 , V_25 ) ;
return V_2 -> V_5 + V_50 * V_7 ;
V_53:
F_31 ( & V_2 -> V_51 , V_25 ) ;
return V_55 ;
}
static void F_45 ( struct V_45 * V_46 , T_1 V_20 , int V_28 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
unsigned long V_25 , V_50 ;
V_50 = ( V_20 - V_2 -> V_5 ) >> V_30 ;
F_30 ( & V_2 -> V_51 , V_25 ) ;
if ( ! V_2 -> V_49 )
goto V_56;
if ( V_44 )
F_46 ( V_2 -> V_49 , V_50 , V_28 ) ;
else
F_47 ( V_2 -> V_54 , V_50 , V_28 ) ;
V_56:
F_31 ( & V_2 -> V_51 , V_25 ) ;
}
static inline void F_48 ( unsigned long V_34 , unsigned long V_57 )
{
struct {
unsigned long V_34 ;
unsigned long V_57 ;
} V_58 V_59 = { V_34 , V_57 } ;
F_49 ( & V_59 , sizeof( V_59 ) ) ;
}
static T_1 F_50 ( struct V_45 * V_46 , struct V_60 * V_60 ,
unsigned long V_50 , T_2 V_28 ,
enum V_61 V_62 ,
unsigned long V_63 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
unsigned long V_27 = F_51 ( V_60 ) + V_50 ;
int V_25 = V_42 ;
unsigned long V_29 ;
T_1 V_20 ;
int V_64 ;
V_29 = F_52 ( V_27 , V_28 , V_7 ) ;
V_20 = F_42 ( V_46 , V_29 ) ;
if ( V_20 == V_55 ) {
V_64 = - V_65 ;
goto V_66;
}
V_28 = V_29 * V_7 ;
if ( V_62 == V_67 || V_62 == V_68 )
V_25 |= V_26 ;
V_64 = F_33 ( V_2 , V_27 , V_20 , V_28 , V_25 ) ;
if ( V_64 )
goto V_69;
F_53 ( V_29 , & V_2 -> V_70 ) ;
return V_20 + ( V_50 & ~ V_31 ) ;
V_69:
F_45 ( V_46 , V_20 , V_29 ) ;
V_66:
F_54 ( L_1 ) ;
F_48 ( V_64 , V_27 ) ;
return V_55 ;
}
static void F_55 ( struct V_45 * V_46 , T_1 V_20 ,
T_2 V_28 , enum V_61 V_62 ,
unsigned long V_63 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
int V_71 , V_64 ;
V_71 = F_52 ( V_20 , V_28 , V_7 ) ;
V_20 = V_20 & V_31 ;
V_64 = F_33 ( V_2 , 0 , V_20 , V_71 * V_7 ,
V_16 ) ;
if ( V_64 ) {
F_54 ( L_2 ) ;
F_48 ( V_64 , V_20 ) ;
return;
}
F_53 ( V_71 , & V_2 -> V_72 ) ;
F_45 ( V_46 , V_20 , V_71 ) ;
}
static void * F_56 ( struct V_45 * V_46 , T_2 V_28 ,
T_1 * V_73 , T_4 V_74 ,
unsigned long V_63 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
struct V_60 * V_60 ;
unsigned long V_27 ;
T_1 V_75 ;
V_28 = F_29 ( V_28 ) ;
V_60 = F_57 ( V_74 , F_58 ( V_28 ) ) ;
if ( ! V_60 )
return NULL ;
V_27 = F_51 ( V_60 ) ;
V_75 = F_50 ( V_46 , V_60 , 0 , V_28 , V_76 , 0 ) ;
if ( F_59 ( V_46 , V_75 ) ) {
F_60 ( V_27 , F_58 ( V_28 ) ) ;
return NULL ;
}
F_53 ( V_28 / V_7 , & V_2 -> V_77 ) ;
if ( V_73 )
* V_73 = V_75 ;
return ( void * ) V_27 ;
}
static void F_61 ( struct V_45 * V_46 , T_2 V_28 ,
void * V_27 , T_1 V_73 ,
unsigned long V_63 )
{
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
V_28 = F_29 ( V_28 ) ;
F_62 ( V_28 / V_7 , & V_2 -> V_77 ) ;
F_55 ( V_46 , V_73 , V_28 , V_76 , 0 ) ;
F_60 ( ( unsigned long ) V_27 , F_58 ( V_28 ) ) ;
}
static int F_63 ( struct V_45 * V_46 , struct V_78 * V_79 ,
T_2 V_28 , T_1 * V_80 ,
enum V_61 V_81 )
{
unsigned long V_29 = F_29 ( V_28 ) >> V_30 ;
struct V_1 * V_2 = F_37 ( F_38 ( V_46 ) ) ;
T_1 V_82 , V_20 ;
int V_25 = V_42 ;
struct V_78 * V_83 ;
unsigned long V_27 = 0 ;
int V_64 ;
V_82 = F_42 ( V_46 , V_29 ) ;
if ( V_82 == V_55 )
return - V_39 ;
V_20 = V_82 ;
if ( V_81 == V_67 || V_81 == V_68 )
V_25 |= V_26 ;
for ( V_83 = V_79 ; V_20 < V_82 + V_28 ; V_83 = F_64 ( V_83 ) ) {
V_27 = F_51 ( F_65 ( V_83 ) ) ;
V_64 = F_28 ( V_2 , V_27 , V_20 ,
V_83 -> V_50 + V_83 -> V_84 , V_25 ) ;
if ( V_64 )
goto V_85;
V_20 += V_83 -> V_50 + V_83 -> V_84 ;
}
V_64 = F_32 ( V_2 , V_82 , V_28 , V_25 ) ;
if ( V_64 )
goto V_85;
* V_80 = V_82 ;
F_53 ( V_29 , & V_2 -> V_70 ) ;
return V_64 ;
V_85:
F_33 ( V_2 , 0 , V_82 , V_20 - V_82 ,
V_16 ) ;
F_45 ( V_46 , V_82 , V_29 ) ;
F_54 ( L_1 ) ;
F_48 ( V_64 , V_27 ) ;
return V_64 ;
}
static int F_66 ( struct V_45 * V_46 , struct V_78 * V_79 ,
int V_86 , enum V_61 V_81 ,
unsigned long V_63 )
{
struct V_78 * V_83 = V_79 , * V_47 = V_79 , * V_87 = V_79 ;
unsigned int V_88 = F_67 ( V_46 ) ;
unsigned int V_28 = V_83 -> V_50 + V_83 -> V_84 ;
unsigned int V_50 = V_83 -> V_50 ;
int V_89 = 0 , V_33 ;
for ( V_33 = 1 ; V_33 < V_86 ; V_33 ++ ) {
V_83 = F_64 ( V_83 ) ;
V_83 -> V_90 = V_55 ;
V_83 -> V_91 = 0 ;
if ( V_83 -> V_50 || ( V_28 & ~ V_31 ) ||
V_28 + V_83 -> V_84 > V_88 ) {
if ( F_63 ( V_46 , V_47 , V_28 ,
& V_87 -> V_90 , V_81 ) )
goto V_85;
V_87 -> V_90 += V_50 ;
V_87 -> V_91 = V_28 - V_50 ;
V_28 = V_50 = V_83 -> V_50 ;
V_47 = V_83 ;
V_87 = F_64 ( V_87 ) ;
V_89 ++ ;
}
V_28 += V_83 -> V_84 ;
}
if ( F_63 ( V_46 , V_47 , V_28 , & V_87 -> V_90 , V_81 ) )
goto V_85;
V_87 -> V_90 += V_50 ;
V_87 -> V_91 = V_28 - V_50 ;
return V_89 + 1 ;
V_85:
F_68 (sg, s, count, i)
F_55 ( V_46 , F_69 ( V_83 ) , F_70 ( V_83 ) ,
V_81 , V_63 ) ;
return 0 ;
}
static void F_71 ( struct V_45 * V_46 , struct V_78 * V_79 ,
int V_86 , enum V_61 V_81 ,
unsigned long V_63 )
{
struct V_78 * V_83 ;
int V_33 ;
F_68 (sg, s, nr_elements, i) {
if ( V_83 -> V_91 )
F_55 ( V_46 , V_83 -> V_90 , V_83 -> V_91 ,
V_81 , V_63 ) ;
V_83 -> V_90 = 0 ;
V_83 -> V_91 = 0 ;
}
}
int F_72 ( struct V_1 * V_2 )
{
int V_34 ;
F_73 ( V_2 -> V_92 ) ;
F_74 ( & V_2 -> V_51 ) ;
F_74 ( & V_2 -> V_36 ) ;
V_2 -> V_37 = F_3 () ;
if ( ! V_2 -> V_37 ) {
V_34 = - V_39 ;
goto V_56;
}
V_2 -> V_5 = F_29 ( V_2 -> V_5 ) ;
V_2 -> V_93 = F_75 ( ( V_3 ) V_94 ,
V_95 - V_2 -> V_5 ,
V_2 -> V_96 - V_2 -> V_5 + 1 ) ;
V_2 -> V_96 = V_2 -> V_5 + V_2 -> V_93 - 1 ;
V_2 -> V_6 = V_2 -> V_93 >> V_30 ;
V_2 -> V_49 = F_76 ( V_2 -> V_6 / 8 ) ;
if ( ! V_2 -> V_49 ) {
V_34 = - V_39 ;
goto V_97;
}
if ( ! V_44 ) {
V_2 -> V_54 = F_76 ( V_2 -> V_6 / 8 ) ;
if ( ! V_2 -> V_54 ) {
V_34 = - V_39 ;
goto V_98;
}
}
V_34 = F_77 ( V_2 , 0 , V_2 -> V_5 , V_2 -> V_96 ,
( V_3 ) V_2 -> V_37 ) ;
if ( V_34 )
goto V_98;
return 0 ;
V_98:
F_78 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
F_78 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
V_97:
F_5 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
V_56:
return V_34 ;
}
void F_79 ( struct V_1 * V_2 )
{
F_73 ( V_2 -> V_92 ) ;
F_80 ( V_2 , 0 ) ;
F_35 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
F_78 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
F_78 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_52 = 0 ;
}
static int T_5 F_81 ( void )
{
V_10 = F_82 ( L_3 ,
V_99 , V_100 ,
0 , NULL ) ;
if ( ! V_10 )
return - V_39 ;
V_14 = F_82 ( L_4 ,
V_101 , V_102 ,
0 , NULL ) ;
if ( ! V_14 ) {
F_83 ( V_10 ) ;
return - V_39 ;
}
return 0 ;
}
int T_5 F_84 ( void )
{
return F_81 () ;
}
void F_85 ( void )
{
F_83 ( V_14 ) ;
F_83 ( V_10 ) ;
}
static int T_5 F_86 ( void )
{
F_87 ( V_103 ) ;
return 0 ;
}
static int T_5 F_88 ( char * V_104 )
{
if ( ! strncmp ( V_104 , L_5 , 6 ) )
V_44 = 1 ;
return 0 ;
}
