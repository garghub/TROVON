static unsigned int F_1 ( int V_1 )
{
unsigned int V_2 ;
switch ( V_1 ) {
case 0 :
case - V_3 :
case - V_4 :
V_2 = V_5 ;
break;
case - V_6 :
V_2 = V_7 ;
break;
default:
V_2 = V_8 ;
break;
}
return V_2 ;
}
static int F_2 ( unsigned int V_9 )
{
if ( V_9 & ~ ( V_10 ) ) {
F_3 ( L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
F_5 ( L_2 , V_13 -> V_9 ) ;
if ( V_13 -> V_9 & V_16 )
V_15 -> V_17 = F_6 ( V_15 -> V_18 ) ;
else if ( V_13 -> V_9 & V_19 )
V_15 -> V_17 =
F_7 ( F_6 ( V_15 -> V_18 ) ) ;
else
V_15 -> V_17 =
F_8 ( F_6 ( V_15 -> V_18 ) ) ;
}
static unsigned long F_9 ( unsigned long V_20 , unsigned int V_9 )
{
if ( ! F_10 ( V_9 ) ) {
if ( V_20 >= V_21 )
return F_11 ( V_20 , V_22 ) ;
else if ( V_20 >= V_23 )
return F_11 ( V_20 , V_23 ) ;
else
goto V_24;
}
V_24:
return F_11 ( V_20 , V_25 ) ;
}
struct V_26 * * F_12 ( struct V_27 * V_13 ,
T_1 V_28 )
{
struct V_29 * V_29 ;
struct V_30 * V_31 ;
struct V_26 * V_32 , * * V_33 ;
int V_34 , V_35 ;
V_29 = V_13 -> V_36 -> V_37 . V_38 -> V_39 ;
V_31 = V_29 -> V_40 ;
V_35 = V_13 -> V_20 >> V_41 ;
V_33 = F_13 ( V_35 , sizeof( struct V_26 * ) ) ;
if ( V_33 == NULL )
return F_14 ( - V_6 ) ;
V_28 |= F_15 ( V_31 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_32 = F_16 ( V_31 , V_34 , V_28 ) ;
if ( F_17 ( V_32 ) )
goto V_42;
V_33 [ V_34 ] = V_32 ;
}
return V_33 ;
V_42:
while ( V_34 -- )
F_18 ( V_33 [ V_34 ] ) ;
F_19 ( V_33 ) ;
return F_14 ( F_20 ( V_32 ) ) ;
}
static void F_21 ( struct V_27 * V_13 ,
struct V_26 * * V_33 ,
bool V_43 , bool V_44 )
{
int V_34 , V_35 ;
V_35 = V_13 -> V_20 >> V_41 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( V_43 )
F_22 ( V_33 [ V_34 ] ) ;
if ( V_44 )
F_23 ( V_33 [ V_34 ] ) ;
F_18 ( V_33 [ V_34 ] ) ;
}
F_19 ( V_33 ) ;
}
static int F_24 ( struct V_27 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_45 ,
T_2 V_46 )
{
struct V_12 * V_47 = F_25 ( V_13 ) ;
struct V_48 * V_49 = V_47 -> V_50 ;
unsigned long V_51 ;
if ( V_47 -> V_9 & V_52 ) {
if ( ! V_49 -> V_33 )
return - V_4 ;
V_51 = F_26 ( V_49 -> V_33 [ V_46 ++ ] ) ;
} else
V_51 = ( V_49 -> V_53 >> V_41 ) + V_46 ;
return F_27 ( V_15 , V_45 , V_51 ) ;
}
static int F_28 ( struct V_27 * V_13 )
{
struct V_12 * V_47 = F_25 ( V_13 ) ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_54 * V_55 ;
struct V_26 * * V_33 ;
unsigned int V_35 , V_34 = 0 ;
int V_56 ;
if ( V_49 -> V_33 ) {
F_5 ( L_3 ) ;
return - V_11 ;
}
V_33 = F_12 ( V_13 , V_57 ) ;
if ( F_17 ( V_33 ) ) {
F_3 ( L_4 ) ;
return F_20 ( V_33 ) ;
}
V_35 = V_13 -> V_20 >> V_41 ;
V_49 -> V_58 = V_25 ;
V_49 -> V_59 = F_29 ( sizeof( struct V_60 ) , V_57 ) ;
if ( ! V_49 -> V_59 ) {
F_3 ( L_5 ) ;
V_56 = - V_6 ;
goto V_61;
}
V_56 = F_30 ( V_49 -> V_59 , V_35 , V_57 ) ;
if ( V_56 < 0 ) {
F_3 ( L_6 ) ;
V_56 = - V_62 ;
goto V_63;
}
V_55 = V_49 -> V_59 -> V_55 ;
while ( V_34 < V_35 ) {
F_31 ( V_55 , V_33 [ V_34 ] , V_25 , 0 ) ;
F_32 ( V_55 ) = F_33 ( V_33 [ V_34 ] ) ;
V_34 ++ ;
V_55 = F_34 ( V_55 ) ;
}
V_49 -> V_33 = V_33 ;
return V_56 ;
V_63:
F_35 ( V_49 -> V_59 ) ;
V_49 -> V_59 = NULL ;
V_61:
F_21 ( V_13 , V_33 , true , false ) ;
return V_56 ;
}
static void F_36 ( struct V_27 * V_13 )
{
struct V_12 * V_47 = F_25 ( V_13 ) ;
struct V_48 * V_49 = V_47 -> V_50 ;
F_37 ( V_49 -> V_59 ) ;
F_35 ( V_49 -> V_59 ) ;
V_49 -> V_59 = NULL ;
F_21 ( V_13 , V_49 -> V_33 , true , false ) ;
V_49 -> V_33 = NULL ;
}
static int F_38 ( struct V_27 * V_13 ,
struct V_64 * V_65 ,
unsigned int * V_66 )
{
int V_56 ;
V_56 = F_39 ( V_65 , V_13 , V_66 ) ;
if ( V_56 )
return V_56 ;
F_5 ( L_7 , * V_66 ) ;
F_40 ( V_13 ) ;
return 0 ;
}
void F_41 ( struct V_12 * V_47 )
{
struct V_27 * V_13 ;
struct V_48 * V_49 ;
F_5 ( L_8 , __FILE__ ) ;
V_13 = & V_47 -> V_67 ;
V_49 = V_47 -> V_50 ;
F_5 ( L_9 , F_42 ( & V_13 -> V_68 ) ) ;
if ( ! V_49 -> V_33 )
return;
if ( V_47 -> V_9 & V_52 )
F_36 ( V_13 ) ;
else
F_43 ( V_13 -> V_69 , V_47 -> V_9 , V_49 ) ;
F_44 ( V_13 -> V_69 , V_49 ) ;
V_47 -> V_50 = NULL ;
if ( V_13 -> V_70 . V_71 )
F_45 ( V_13 ) ;
F_46 ( V_13 ) ;
F_35 ( V_47 ) ;
V_47 = NULL ;
}
struct V_12 * F_47 ( struct V_72 * V_69 ,
unsigned long V_20 )
{
struct V_12 * V_47 ;
struct V_27 * V_13 ;
int V_56 ;
V_47 = F_29 ( sizeof( * V_47 ) , V_57 ) ;
if ( ! V_47 ) {
F_3 ( L_10 ) ;
return NULL ;
}
V_47 -> V_20 = V_20 ;
V_13 = & V_47 -> V_67 ;
V_56 = F_48 ( V_69 , V_13 , V_20 ) ;
if ( V_56 < 0 ) {
F_3 ( L_11 ) ;
F_35 ( V_47 ) ;
return NULL ;
}
F_5 ( L_12 , ( unsigned int ) V_13 -> V_36 ) ;
return V_47 ;
}
struct V_12 * F_49 ( struct V_72 * V_69 ,
unsigned int V_9 ,
unsigned long V_20 )
{
struct V_12 * V_47 ;
struct V_48 * V_49 ;
int V_56 ;
if ( ! V_20 ) {
F_3 ( L_13 ) ;
return F_14 ( - V_11 ) ;
}
V_20 = F_9 ( V_20 , V_9 ) ;
F_5 ( L_8 , __FILE__ ) ;
V_56 = F_2 ( V_9 ) ;
if ( V_56 )
return F_14 ( V_56 ) ;
V_49 = F_50 ( V_69 , V_20 ) ;
if ( ! V_49 )
return F_14 ( - V_6 ) ;
V_47 = F_47 ( V_69 , V_20 ) ;
if ( ! V_47 ) {
V_56 = - V_6 ;
goto V_73;
}
V_47 -> V_50 = V_49 ;
V_47 -> V_9 = V_9 ;
if ( V_9 & V_52 ) {
V_56 = F_28 ( & V_47 -> V_67 ) ;
if ( V_56 < 0 ) {
F_46 ( & V_47 -> V_67 ) ;
goto V_73;
}
} else {
V_56 = F_51 ( V_69 , V_49 , V_9 ) ;
if ( V_56 < 0 ) {
F_46 ( & V_47 -> V_67 ) ;
goto V_73;
}
}
return V_47 ;
V_73:
F_44 ( V_69 , V_49 ) ;
return F_14 ( V_56 ) ;
}
int F_52 ( struct V_72 * V_69 , void * V_74 ,
struct V_64 * V_65 )
{
struct V_75 * args = V_74 ;
struct V_12 * V_47 ;
int V_56 ;
F_5 ( L_8 , __FILE__ ) ;
V_47 = F_49 ( V_69 , args -> V_9 , args -> V_20 ) ;
if ( F_17 ( V_47 ) )
return F_20 ( V_47 ) ;
V_56 = F_38 ( & V_47 -> V_67 , V_65 ,
& args -> V_66 ) ;
if ( V_56 ) {
F_41 ( V_47 ) ;
return V_56 ;
}
return 0 ;
}
void * F_53 ( struct V_72 * V_69 ,
unsigned int V_76 ,
struct V_64 * V_65 )
{
struct V_12 * V_47 ;
struct V_27 * V_13 ;
V_13 = F_54 ( V_69 , V_65 , V_76 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
return F_14 ( - V_11 ) ;
}
V_47 = F_25 ( V_13 ) ;
if ( V_47 -> V_9 & V_52 ) {
F_5 ( L_15 ) ;
F_40 ( V_13 ) ;
return F_14 ( - V_11 ) ;
}
return & V_47 -> V_50 -> V_53 ;
}
void F_55 ( struct V_72 * V_69 ,
unsigned int V_76 ,
struct V_64 * V_65 )
{
struct V_12 * V_47 ;
struct V_27 * V_13 ;
V_13 = F_54 ( V_69 , V_65 , V_76 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
return;
}
V_47 = F_25 ( V_13 ) ;
if ( V_47 -> V_9 & V_52 ) {
F_5 ( L_15 ) ;
F_40 ( V_13 ) ;
return;
}
F_40 ( V_13 ) ;
F_40 ( V_13 ) ;
}
int F_56 ( struct V_72 * V_69 , void * V_74 ,
struct V_64 * V_65 )
{
struct V_77 * args = V_74 ;
F_5 ( L_8 , __FILE__ ) ;
F_5 ( L_16 ,
args -> V_66 , ( unsigned long ) args -> V_78 ) ;
if ( ! ( V_69 -> V_79 -> V_80 & V_81 ) ) {
F_3 ( L_17 ) ;
return - V_82 ;
}
return F_57 ( V_65 , V_69 , args -> V_66 ,
& args -> V_78 ) ;
}
static int F_58 ( struct V_83 * V_36 ,
struct V_14 * V_15 )
{
struct V_27 * V_13 = V_36 -> V_84 ;
struct V_12 * V_47 = F_25 ( V_13 ) ;
struct V_48 * V_50 ;
unsigned long V_51 , V_85 , V_86 , V_87 = V_15 -> V_88 ;
int V_56 ;
F_5 ( L_8 , __FILE__ ) ;
V_15 -> V_18 |= ( V_89 | V_90 ) ;
F_4 ( V_47 , V_15 ) ;
V_85 = V_86 = V_15 -> V_91 - V_15 -> V_88 ;
V_50 = V_47 -> V_50 ;
if ( V_85 > V_50 -> V_20 )
return - V_11 ;
if ( V_47 -> V_9 & V_52 ) {
int V_34 = 0 ;
if ( ! V_50 -> V_33 )
return - V_11 ;
V_15 -> V_18 |= V_92 ;
do {
V_56 = F_59 ( V_15 , V_87 , V_50 -> V_33 [ V_34 ++ ] ) ;
if ( V_56 ) {
F_3 ( L_18 ) ;
return V_56 ;
}
V_87 += V_25 ;
V_86 -= V_25 ;
} while ( V_86 > 0 );
} else {
V_51 = ( ( unsigned long ) V_47 -> V_50 -> V_53 ) >>
V_41 ;
F_5 ( L_19 , V_51 ) ;
if ( F_60 ( V_15 , V_15 -> V_88 , V_51 , V_85 ,
V_15 -> V_17 ) ) {
F_3 ( L_20 ) ;
return - V_93 ;
}
}
return 0 ;
}
int F_61 ( struct V_72 * V_69 , void * V_74 ,
struct V_64 * V_65 )
{
struct V_94 * args = V_74 ;
struct V_27 * V_13 ;
unsigned int V_95 ;
F_5 ( L_8 , __FILE__ ) ;
if ( ! ( V_69 -> V_79 -> V_80 & V_81 ) ) {
F_3 ( L_17 ) ;
return - V_82 ;
}
V_13 = F_54 ( V_69 , V_65 , args -> V_66 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
return - V_11 ;
}
V_13 -> V_36 -> V_96 = & V_97 ;
V_13 -> V_36 -> V_84 = V_13 ;
V_95 = F_62 ( V_13 -> V_36 , 0 , args -> V_20 ,
V_98 | V_99 , V_100 , 0 ) ;
F_40 ( V_13 ) ;
if ( F_17 ( ( void * ) V_95 ) )
return F_20 ( ( void * ) V_95 ) ;
args -> V_101 = V_95 ;
F_5 ( L_21 , ( unsigned long ) args -> V_101 ) ;
return 0 ;
}
int F_63 ( struct V_72 * V_69 , void * V_74 ,
struct V_64 * V_65 )
{ struct V_12 * V_47 ;
struct V_102 * args = V_74 ;
struct V_27 * V_13 ;
F_64 ( & V_69 -> V_103 ) ;
V_13 = F_54 ( V_69 , V_65 , args -> V_66 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
F_65 ( & V_69 -> V_103 ) ;
return - V_11 ;
}
V_47 = F_25 ( V_13 ) ;
args -> V_9 = V_47 -> V_9 ;
args -> V_20 = V_47 -> V_20 ;
F_66 ( V_13 ) ;
F_65 ( & V_69 -> V_103 ) ;
return 0 ;
}
int F_67 ( struct V_27 * V_13 )
{
F_5 ( L_8 , __FILE__ ) ;
return 0 ;
}
void F_68 ( struct V_27 * V_13 )
{
struct V_12 * V_47 ;
struct V_48 * V_49 ;
F_5 ( L_8 , __FILE__ ) ;
V_47 = F_25 ( V_13 ) ;
V_49 = V_47 -> V_50 ;
if ( V_13 -> V_104 )
F_69 ( V_13 , V_49 -> V_59 ) ;
F_41 ( F_25 ( V_13 ) ) ;
}
int F_70 ( struct V_64 * V_65 ,
struct V_72 * V_69 ,
struct V_105 * args )
{
struct V_12 * V_47 ;
int V_56 ;
F_5 ( L_8 , __FILE__ ) ;
args -> V_106 = args -> V_107 * args -> V_108 >> 3 ;
args -> V_20 = F_71 ( args -> V_106 * args -> V_109 ) ;
V_47 = F_49 ( V_69 , args -> V_9 , args -> V_20 ) ;
if ( F_17 ( V_47 ) )
return F_20 ( V_47 ) ;
V_56 = F_38 ( & V_47 -> V_67 , V_65 ,
& args -> V_66 ) ;
if ( V_56 ) {
F_41 ( V_47 ) ;
return V_56 ;
}
return 0 ;
}
int F_57 ( struct V_64 * V_65 ,
struct V_72 * V_69 , T_3 V_66 ,
T_4 * V_78 )
{
struct V_27 * V_13 ;
int V_56 = 0 ;
F_5 ( L_8 , __FILE__ ) ;
F_64 ( & V_69 -> V_103 ) ;
V_13 = F_54 ( V_69 , V_65 , V_66 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
V_56 = - V_11 ;
goto V_110;
}
if ( ! V_13 -> V_70 . V_71 ) {
V_56 = F_72 ( V_13 ) ;
if ( V_56 )
goto V_24;
}
* V_78 = ( V_111 ) V_13 -> V_70 . V_112 . V_113 << V_41 ;
F_5 ( L_22 , ( unsigned long ) * V_78 ) ;
V_24:
F_66 ( V_13 ) ;
V_110:
F_65 ( & V_69 -> V_103 ) ;
return V_56 ;
}
int F_73 ( struct V_64 * V_65 ,
struct V_72 * V_69 ,
unsigned int V_66 )
{
int V_56 ;
F_5 ( L_8 , __FILE__ ) ;
V_56 = F_74 ( V_65 , V_66 ) ;
if ( V_56 < 0 ) {
F_3 ( L_23 ) ;
return V_56 ;
}
return 0 ;
}
int F_75 ( struct V_14 * V_15 , struct V_114 * V_115 )
{
struct V_27 * V_13 = V_15 -> V_116 ;
struct V_72 * V_69 = V_13 -> V_69 ;
unsigned long V_45 ;
T_2 V_46 ;
int V_56 ;
V_46 = ( ( unsigned long ) V_115 -> V_117 -
V_15 -> V_88 ) >> V_41 ;
V_45 = ( unsigned long ) V_115 -> V_117 ;
F_64 ( & V_69 -> V_103 ) ;
V_56 = F_24 ( V_13 , V_15 , V_45 , V_46 ) ;
if ( V_56 < 0 )
F_3 ( L_24 ) ;
F_65 ( & V_69 -> V_103 ) ;
return F_1 ( V_56 ) ;
}
int F_76 ( struct V_83 * V_36 , struct V_14 * V_15 )
{
struct V_12 * V_47 ;
struct V_27 * V_13 ;
int V_56 ;
F_5 ( L_8 , __FILE__ ) ;
V_56 = F_77 ( V_36 , V_15 ) ;
if ( V_56 < 0 ) {
F_3 ( L_25 ) ;
return V_56 ;
}
V_13 = V_15 -> V_116 ;
V_47 = F_25 ( V_13 ) ;
V_56 = F_2 ( V_47 -> V_9 ) ;
if ( V_56 ) {
F_78 ( V_15 ) ;
F_45 ( V_13 ) ;
return V_56 ;
}
V_15 -> V_18 &= ~ V_118 ;
V_15 -> V_18 |= V_92 ;
F_4 ( V_47 , V_15 ) ;
return V_56 ;
}
