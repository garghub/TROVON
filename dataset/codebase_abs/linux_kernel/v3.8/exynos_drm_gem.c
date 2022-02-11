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
return F_10 ( V_20 , V_21 ) ;
}
static int F_11 ( struct V_22 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_23 ,
T_1 V_24 )
{
struct V_12 * V_25 = F_12 ( V_13 ) ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_29 * V_30 ;
unsigned long V_31 ;
int V_32 ;
if ( ! V_27 -> V_33 )
return - V_4 ;
if ( V_24 >= ( V_27 -> V_20 >> V_34 ) ) {
F_3 ( L_3 ) ;
return - V_11 ;
}
V_30 = V_27 -> V_33 -> V_30 ;
F_13 (buf->sgt->sgl, sgl, buf->sgt->nents, i) {
if ( V_24 < ( V_30 -> V_35 >> V_34 ) )
break;
V_24 -= ( V_30 -> V_35 >> V_34 ) ;
}
V_31 = F_14 ( F_15 ( V_30 ) ) + V_24 ;
return F_16 ( V_15 , V_23 , V_31 ) ;
}
static int F_17 ( struct V_22 * V_13 ,
struct V_36 * V_37 ,
unsigned int * V_38 )
{
int V_39 ;
V_39 = F_18 ( V_37 , V_13 , V_38 ) ;
if ( V_39 )
return V_39 ;
F_5 ( L_4 , * V_38 ) ;
F_19 ( V_13 ) ;
return 0 ;
}
void F_20 ( struct V_12 * V_25 )
{
struct V_22 * V_13 ;
struct V_26 * V_27 ;
F_5 ( L_5 , __FILE__ ) ;
V_13 = & V_25 -> V_40 ;
V_27 = V_25 -> V_28 ;
F_5 ( L_6 , F_21 ( & V_13 -> V_41 ) ) ;
if ( V_13 -> V_42 )
goto V_43;
F_22 ( V_13 -> V_44 , V_25 -> V_9 , V_27 ) ;
V_43:
F_23 ( V_13 -> V_44 , V_27 ) ;
V_25 -> V_28 = NULL ;
if ( V_13 -> V_45 . V_46 )
F_24 ( V_13 ) ;
F_25 ( V_13 ) ;
F_26 ( V_25 ) ;
V_25 = NULL ;
}
struct V_12 * F_27 ( struct V_47 * V_44 ,
unsigned long V_20 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
int V_39 ;
V_25 = F_28 ( sizeof( * V_25 ) , V_48 ) ;
if ( ! V_25 ) {
F_3 ( L_7 ) ;
return NULL ;
}
V_25 -> V_20 = V_20 ;
V_13 = & V_25 -> V_40 ;
V_39 = F_29 ( V_44 , V_13 , V_20 ) ;
if ( V_39 < 0 ) {
F_3 ( L_8 ) ;
F_26 ( V_25 ) ;
return NULL ;
}
F_5 ( L_9 , ( unsigned int ) V_13 -> V_49 ) ;
return V_25 ;
}
struct V_12 * F_30 ( struct V_47 * V_44 ,
unsigned int V_9 ,
unsigned long V_20 )
{
struct V_12 * V_25 ;
struct V_26 * V_27 ;
int V_39 ;
if ( ! V_20 ) {
F_3 ( L_10 ) ;
return F_31 ( - V_11 ) ;
}
V_20 = F_9 ( V_20 , V_9 ) ;
F_5 ( L_5 , __FILE__ ) ;
V_39 = F_2 ( V_9 ) ;
if ( V_39 )
return F_31 ( V_39 ) ;
V_27 = F_32 ( V_44 , V_20 ) ;
if ( ! V_27 )
return F_31 ( - V_6 ) ;
V_25 = F_27 ( V_44 , V_20 ) ;
if ( ! V_25 ) {
V_39 = - V_6 ;
goto V_50;
}
V_25 -> V_28 = V_27 ;
V_25 -> V_9 = V_9 ;
V_39 = F_33 ( V_44 , V_27 , V_9 ) ;
if ( V_39 < 0 ) {
F_25 ( & V_25 -> V_40 ) ;
goto V_50;
}
return V_25 ;
V_50:
F_23 ( V_44 , V_27 ) ;
return F_31 ( V_39 ) ;
}
int F_34 ( struct V_47 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{
struct V_52 * args = V_51 ;
struct V_12 * V_25 ;
int V_39 ;
F_5 ( L_5 , __FILE__ ) ;
V_25 = F_30 ( V_44 , args -> V_9 , args -> V_20 ) ;
if ( F_35 ( V_25 ) )
return F_36 ( V_25 ) ;
V_39 = F_17 ( & V_25 -> V_40 , V_37 ,
& args -> V_38 ) ;
if ( V_39 ) {
F_20 ( V_25 ) ;
return V_39 ;
}
return 0 ;
}
T_2 * F_37 ( struct V_47 * V_44 ,
unsigned int V_53 ,
struct V_36 * V_49 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
V_13 = F_38 ( V_44 , V_49 , V_53 ) ;
if ( ! V_13 ) {
F_3 ( L_11 ) ;
return F_31 ( - V_11 ) ;
}
V_25 = F_12 ( V_13 ) ;
return & V_25 -> V_28 -> V_54 ;
}
void F_39 ( struct V_47 * V_44 ,
unsigned int V_53 ,
struct V_36 * V_49 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
V_13 = F_38 ( V_44 , V_49 , V_53 ) ;
if ( ! V_13 ) {
F_3 ( L_11 ) ;
return;
}
V_25 = F_12 ( V_13 ) ;
F_19 ( V_13 ) ;
F_19 ( V_13 ) ;
}
int F_40 ( struct V_47 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{
struct V_55 * args = V_51 ;
F_5 ( L_5 , __FILE__ ) ;
F_5 ( L_12 ,
args -> V_38 , ( unsigned long ) args -> V_56 ) ;
if ( ! ( V_44 -> V_57 -> V_58 & V_59 ) ) {
F_3 ( L_13 ) ;
return - V_60 ;
}
return F_41 ( V_37 , V_44 , args -> V_38 ,
& args -> V_56 ) ;
}
static struct V_36 * F_42 ( struct V_47 * V_61 ,
struct V_62 * V_49 )
{
struct V_36 * V_37 ;
F_43 ( & V_61 -> V_63 ) ;
F_44 (file_priv, &drm_dev->filelist, lhead) {
if ( V_37 -> V_49 == V_49 ) {
F_45 ( & V_61 -> V_63 ) ;
return V_37 ;
}
}
F_45 ( & V_61 -> V_63 ) ;
F_46 ( 1 ) ;
return F_31 ( - V_64 ) ;
}
static int F_47 ( struct V_62 * V_49 ,
struct V_14 * V_15 )
{
struct V_22 * V_13 = V_49 -> V_65 ;
struct V_12 * V_25 = F_12 ( V_13 ) ;
struct V_47 * V_61 = V_13 -> V_44 ;
struct V_26 * V_28 ;
struct V_36 * V_37 ;
unsigned long V_66 ;
int V_39 ;
F_5 ( L_5 , __FILE__ ) ;
V_15 -> V_18 |= V_67 | V_68 | V_69 ;
V_15 -> V_70 = V_13 ;
V_15 -> V_71 = V_61 -> V_57 -> V_72 ;
V_49 -> V_73 = F_48 ( V_61 -> V_57 -> V_74 ) ;
V_37 = F_42 ( V_61 , V_49 ) ;
if ( F_35 ( V_37 ) )
return F_36 ( V_37 ) ;
V_49 -> V_65 = V_37 ;
F_4 ( V_25 , V_15 ) ;
V_66 = V_15 -> V_75 - V_15 -> V_76 ;
V_28 = V_25 -> V_28 ;
if ( V_66 > V_28 -> V_20 )
return - V_11 ;
V_39 = F_49 ( V_61 -> V_44 , V_15 , V_28 -> V_77 ,
V_28 -> V_54 , V_28 -> V_20 ,
& V_28 -> V_78 ) ;
if ( V_39 < 0 ) {
F_3 ( L_14 ) ;
return V_39 ;
}
F_50 ( V_13 ) ;
F_43 ( & V_61 -> V_63 ) ;
F_51 ( V_61 , V_15 ) ;
F_45 ( & V_61 -> V_63 ) ;
return 0 ;
}
int F_52 ( struct V_47 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{
struct V_79 * args = V_51 ;
struct V_22 * V_13 ;
unsigned int V_80 ;
F_5 ( L_5 , __FILE__ ) ;
if ( ! ( V_44 -> V_57 -> V_58 & V_59 ) ) {
F_3 ( L_13 ) ;
return - V_60 ;
}
V_13 = F_38 ( V_44 , V_37 , args -> V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_11 ) ;
return - V_11 ;
}
V_37 -> V_49 -> V_73 = & V_81 ;
V_37 -> V_49 -> V_65 = V_13 ;
V_80 = F_53 ( V_37 -> V_49 , 0 , args -> V_20 ,
V_82 | V_83 , V_84 , 0 ) ;
F_19 ( V_13 ) ;
if ( F_35 ( ( void * ) V_80 ) ) {
V_37 -> V_49 -> V_65 = V_37 ;
return F_36 ( ( void * ) V_80 ) ;
}
args -> V_85 = V_80 ;
F_5 ( L_15 , ( unsigned long ) args -> V_85 ) ;
return 0 ;
}
int F_54 ( struct V_47 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{ struct V_12 * V_25 ;
struct V_86 * args = V_51 ;
struct V_22 * V_13 ;
F_43 ( & V_44 -> V_63 ) ;
V_13 = F_38 ( V_44 , V_37 , args -> V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_11 ) ;
F_45 ( & V_44 -> V_63 ) ;
return - V_11 ;
}
V_25 = F_12 ( V_13 ) ;
args -> V_9 = V_25 -> V_9 ;
args -> V_20 = V_25 -> V_20 ;
F_55 ( V_13 ) ;
F_45 ( & V_44 -> V_63 ) ;
return 0 ;
}
struct V_14 * F_56 ( struct V_14 * V_15 )
{
struct V_14 * V_87 ;
V_87 = F_57 ( sizeof( * V_87 ) , V_48 ) ;
if ( ! V_87 )
return NULL ;
if ( V_15 -> V_71 && V_15 -> V_71 -> V_88 )
V_15 -> V_71 -> V_88 ( V_15 ) ;
if ( V_15 -> V_89 )
F_58 ( V_15 -> V_89 ) ;
memcpy ( V_87 , V_15 , sizeof( * V_15 ) ) ;
V_87 -> V_90 = NULL ;
V_87 -> V_91 = NULL ;
V_87 -> V_92 = NULL ;
return V_87 ;
}
void F_59 ( struct V_14 * V_15 )
{
if ( ! V_15 )
return;
if ( V_15 -> V_71 && V_15 -> V_71 -> V_93 )
V_15 -> V_71 -> V_93 ( V_15 ) ;
if ( V_15 -> V_89 )
F_60 ( V_15 -> V_89 ) ;
F_26 ( V_15 ) ;
}
int F_61 ( unsigned long V_94 ,
unsigned int V_95 ,
struct V_96 * * V_77 ,
struct V_14 * V_15 )
{
int V_97 ;
if ( F_62 ( V_15 ) ) {
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_95 ; ++ V_32 , V_94 += V_21 ) {
unsigned long V_31 ;
int V_39 = F_63 ( V_15 , V_94 , & V_31 ) ;
if ( V_39 )
return V_39 ;
V_77 [ V_32 ] = F_64 ( V_31 ) ;
}
if ( V_32 != V_95 ) {
F_3 ( L_16 ) ;
return - V_11 ;
}
return 0 ;
}
V_97 = F_65 ( V_98 , V_98 -> V_99 , V_94 ,
V_95 , 1 , 1 , V_77 , NULL ) ;
V_97 = F_66 ( V_97 , 0 ) ;
if ( V_97 != V_95 ) {
F_3 ( L_16 ) ;
while ( V_97 )
F_67 ( V_77 [ -- V_97 ] ) ;
return - V_64 ;
}
return 0 ;
}
void F_68 ( struct V_96 * * V_77 ,
unsigned int V_95 ,
struct V_14 * V_15 )
{
if ( ! F_62 ( V_15 ) ) {
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_95 ; V_32 ++ ) {
F_69 ( V_77 [ V_32 ] ) ;
F_67 ( V_77 [ V_32 ] ) ;
}
}
}
int F_70 ( struct V_47 * V_61 ,
struct V_100 * V_33 ,
enum V_101 V_102 )
{
int V_103 ;
F_43 ( & V_61 -> V_63 ) ;
V_103 = F_71 ( V_61 -> V_44 , V_33 -> V_30 , V_33 -> V_103 , V_102 ) ;
if ( ! V_103 ) {
F_3 ( L_17 ) ;
F_45 ( & V_61 -> V_63 ) ;
return V_103 ;
}
F_45 ( & V_61 -> V_63 ) ;
return 0 ;
}
void F_72 ( struct V_47 * V_61 ,
struct V_100 * V_33 ,
enum V_101 V_102 )
{
F_73 ( V_61 -> V_44 , V_33 -> V_30 , V_33 -> V_103 , V_102 ) ;
}
int F_74 ( struct V_22 * V_13 )
{
F_5 ( L_5 , __FILE__ ) ;
return 0 ;
}
void F_75 ( struct V_22 * V_13 )
{
struct V_12 * V_25 ;
struct V_26 * V_27 ;
F_5 ( L_5 , __FILE__ ) ;
V_25 = F_12 ( V_13 ) ;
V_27 = V_25 -> V_28 ;
if ( V_13 -> V_42 )
F_76 ( V_13 , V_27 -> V_33 ) ;
F_20 ( F_12 ( V_13 ) ) ;
}
int F_77 ( struct V_36 * V_37 ,
struct V_47 * V_44 ,
struct V_104 * args )
{
struct V_12 * V_25 ;
int V_39 ;
F_5 ( L_5 , __FILE__ ) ;
args -> V_105 = args -> V_106 * ( ( args -> V_107 + 7 ) / 8 ) ;
args -> V_20 = args -> V_105 * args -> V_108 ;
V_25 = F_30 ( V_44 , args -> V_9 , args -> V_20 ) ;
if ( F_35 ( V_25 ) )
return F_36 ( V_25 ) ;
V_39 = F_17 ( & V_25 -> V_40 , V_37 ,
& args -> V_38 ) ;
if ( V_39 ) {
F_20 ( V_25 ) ;
return V_39 ;
}
return 0 ;
}
int F_41 ( struct V_36 * V_37 ,
struct V_47 * V_44 , T_3 V_38 ,
T_4 * V_56 )
{
struct V_22 * V_13 ;
int V_39 = 0 ;
F_5 ( L_5 , __FILE__ ) ;
F_43 ( & V_44 -> V_63 ) ;
V_13 = F_38 ( V_44 , V_37 , V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_11 ) ;
V_39 = - V_11 ;
goto V_109;
}
if ( ! V_13 -> V_45 . V_46 ) {
V_39 = F_78 ( V_13 ) ;
if ( V_39 )
goto V_43;
}
* V_56 = ( V_110 ) V_13 -> V_45 . V_111 . V_112 << V_34 ;
F_5 ( L_18 , ( unsigned long ) * V_56 ) ;
V_43:
F_55 ( V_13 ) ;
V_109:
F_45 ( & V_44 -> V_63 ) ;
return V_39 ;
}
int F_79 ( struct V_36 * V_37 ,
struct V_47 * V_44 ,
unsigned int V_38 )
{
int V_39 ;
F_5 ( L_5 , __FILE__ ) ;
V_39 = F_80 ( V_37 , V_38 ) ;
if ( V_39 < 0 ) {
F_3 ( L_19 ) ;
return V_39 ;
}
return 0 ;
}
int F_81 ( struct V_14 * V_15 , struct V_113 * V_114 )
{
struct V_22 * V_13 = V_15 -> V_70 ;
struct V_47 * V_44 = V_13 -> V_44 ;
unsigned long V_23 ;
T_1 V_24 ;
int V_39 ;
V_24 = ( ( unsigned long ) V_114 -> V_115 -
V_15 -> V_76 ) >> V_34 ;
V_23 = ( unsigned long ) V_114 -> V_115 ;
F_43 ( & V_44 -> V_63 ) ;
V_39 = F_11 ( V_13 , V_15 , V_23 , V_24 ) ;
if ( V_39 < 0 )
F_3 ( L_20 ) ;
F_45 ( & V_44 -> V_63 ) ;
return F_1 ( V_39 ) ;
}
int F_82 ( struct V_62 * V_49 , struct V_14 * V_15 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
int V_39 ;
F_5 ( L_5 , __FILE__ ) ;
V_39 = F_83 ( V_49 , V_15 ) ;
if ( V_39 < 0 ) {
F_3 ( L_14 ) ;
return V_39 ;
}
V_13 = V_15 -> V_70 ;
V_25 = F_12 ( V_13 ) ;
V_39 = F_2 ( V_25 -> V_9 ) ;
if ( V_39 ) {
F_84 ( V_15 ) ;
F_24 ( V_13 ) ;
return V_39 ;
}
V_15 -> V_18 &= ~ V_116 ;
V_15 -> V_18 |= V_117 ;
F_4 ( V_25 , V_15 ) ;
return V_39 ;
}
