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
V_13 = & V_25 -> V_40 ;
V_27 = V_25 -> V_28 ;
F_5 ( L_5 , V_13 -> V_41 ) ;
if ( V_13 -> V_42 )
goto V_43;
F_21 ( V_13 -> V_44 , V_25 -> V_9 , V_27 ) ;
V_43:
F_22 ( V_13 -> V_44 , V_27 ) ;
V_25 -> V_28 = NULL ;
F_23 ( V_13 ) ;
F_24 ( V_13 ) ;
F_25 ( V_25 ) ;
V_25 = NULL ;
}
unsigned long F_26 ( struct V_45 * V_44 ,
unsigned int V_46 ,
struct V_36 * V_37 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
V_13 = F_27 ( V_44 , V_37 , V_46 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
return 0 ;
}
V_25 = F_12 ( V_13 ) ;
F_19 ( V_13 ) ;
return V_25 -> V_28 -> V_20 ;
}
struct V_12 * F_28 ( struct V_45 * V_44 ,
unsigned long V_20 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
int V_39 ;
V_25 = F_29 ( sizeof( * V_25 ) , V_47 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_20 = V_20 ;
V_13 = & V_25 -> V_40 ;
V_39 = F_30 ( V_44 , V_13 , V_20 ) ;
if ( V_39 < 0 ) {
F_3 ( L_7 ) ;
F_25 ( V_25 ) ;
return NULL ;
}
F_5 ( L_8 , ( unsigned int ) V_13 -> V_48 ) ;
return V_25 ;
}
struct V_12 * F_31 ( struct V_45 * V_44 ,
unsigned int V_9 ,
unsigned long V_20 )
{
struct V_12 * V_25 ;
struct V_26 * V_27 ;
int V_39 ;
if ( ! V_20 ) {
F_3 ( L_9 ) ;
return F_32 ( - V_11 ) ;
}
V_20 = F_9 ( V_20 , V_9 ) ;
V_39 = F_2 ( V_9 ) ;
if ( V_39 )
return F_32 ( V_39 ) ;
V_27 = F_33 ( V_44 , V_20 ) ;
if ( ! V_27 )
return F_32 ( - V_6 ) ;
V_25 = F_28 ( V_44 , V_20 ) ;
if ( ! V_25 ) {
V_39 = - V_6 ;
goto V_49;
}
V_25 -> V_28 = V_27 ;
V_25 -> V_9 = V_9 ;
V_39 = F_34 ( V_44 , V_27 , V_9 ) ;
if ( V_39 < 0 )
goto V_50;
return V_25 ;
V_50:
F_24 ( & V_25 -> V_40 ) ;
F_25 ( V_25 ) ;
V_49:
F_22 ( V_44 , V_27 ) ;
return F_32 ( V_39 ) ;
}
int F_35 ( struct V_45 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{
struct V_52 * args = V_51 ;
struct V_12 * V_25 ;
int V_39 ;
V_25 = F_31 ( V_44 , args -> V_9 , args -> V_20 ) ;
if ( F_36 ( V_25 ) )
return F_37 ( V_25 ) ;
V_39 = F_17 ( & V_25 -> V_40 , V_37 ,
& args -> V_38 ) ;
if ( V_39 ) {
F_20 ( V_25 ) ;
return V_39 ;
}
return 0 ;
}
T_2 * F_38 ( struct V_45 * V_44 ,
unsigned int V_46 ,
struct V_36 * V_48 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
V_13 = F_27 ( V_44 , V_48 , V_46 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
return F_32 ( - V_11 ) ;
}
V_25 = F_12 ( V_13 ) ;
return & V_25 -> V_28 -> V_53 ;
}
void F_39 ( struct V_45 * V_44 ,
unsigned int V_46 ,
struct V_36 * V_48 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
V_13 = F_27 ( V_44 , V_48 , V_46 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
return;
}
V_25 = F_12 ( V_13 ) ;
F_19 ( V_13 ) ;
F_19 ( V_13 ) ;
}
int F_40 ( struct V_45 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{
struct V_54 * args = V_51 ;
F_5 ( L_10 ,
args -> V_38 , ( unsigned long ) args -> V_55 ) ;
if ( ! ( V_44 -> V_56 -> V_57 & V_58 ) ) {
F_3 ( L_11 ) ;
return - V_59 ;
}
return F_41 ( V_37 , V_44 , args -> V_38 ,
& args -> V_55 ) ;
}
static struct V_36 * F_42 ( struct V_45 * V_60 ,
struct V_61 * V_48 )
{
struct V_36 * V_37 ;
F_43 (file_priv, &drm_dev->filelist, lhead)
if ( V_37 -> V_48 == V_48 )
return V_37 ;
F_44 ( 1 ) ;
return F_32 ( - V_62 ) ;
}
static int F_45 ( struct V_61 * V_48 ,
struct V_14 * V_15 )
{
struct V_22 * V_13 = V_48 -> V_63 ;
struct V_12 * V_25 = F_12 ( V_13 ) ;
struct V_45 * V_60 = V_13 -> V_44 ;
struct V_26 * V_28 ;
struct V_36 * V_37 ;
unsigned long V_64 ;
int V_39 ;
V_15 -> V_18 |= V_65 | V_66 | V_67 ;
V_15 -> V_68 = V_13 ;
V_15 -> V_69 = V_60 -> V_56 -> V_70 ;
V_48 -> V_71 = F_46 ( V_60 -> V_56 -> V_72 ) ;
V_37 = F_42 ( V_60 , V_48 ) ;
if ( F_36 ( V_37 ) )
return F_37 ( V_37 ) ;
V_48 -> V_63 = V_37 ;
F_4 ( V_25 , V_15 ) ;
V_64 = V_15 -> V_73 - V_15 -> V_74 ;
V_28 = V_25 -> V_28 ;
if ( V_64 > V_28 -> V_20 )
return - V_11 ;
V_39 = F_47 ( V_60 -> V_44 , V_15 , V_28 -> V_75 ,
V_28 -> V_53 , V_28 -> V_20 ,
& V_28 -> V_76 ) ;
if ( V_39 < 0 ) {
F_3 ( L_12 ) ;
return V_39 ;
}
F_48 ( V_13 ) ;
F_49 ( V_60 , V_15 ) ;
return 0 ;
}
int F_50 ( struct V_45 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{
struct V_77 * args = V_51 ;
struct V_22 * V_13 ;
unsigned long V_78 ;
if ( ! ( V_44 -> V_56 -> V_57 & V_58 ) ) {
F_3 ( L_11 ) ;
return - V_59 ;
}
V_13 = F_27 ( V_44 , V_37 , args -> V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
return - V_11 ;
}
F_51 ( & V_44 -> V_79 ) ;
V_37 -> V_48 -> V_71 = & V_80 ;
V_37 -> V_48 -> V_63 = V_13 ;
V_78 = F_52 ( V_37 -> V_48 , 0 , args -> V_20 ,
V_81 | V_82 , V_83 , 0 ) ;
F_53 ( V_13 ) ;
if ( F_54 ( V_78 ) ) {
if ( V_37 -> V_48 -> V_71 == & V_80 ) {
V_37 -> V_48 -> V_71 = F_46 ( V_44 -> V_56 -> V_72 ) ;
V_37 -> V_48 -> V_63 = V_37 ;
}
F_55 ( & V_44 -> V_79 ) ;
return ( int ) V_78 ;
}
F_55 ( & V_44 -> V_79 ) ;
args -> V_84 = V_78 ;
F_5 ( L_13 , ( unsigned long ) args -> V_84 ) ;
return 0 ;
}
int F_56 ( struct V_45 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{ struct V_12 * V_25 ;
struct V_85 * args = V_51 ;
struct V_22 * V_13 ;
F_51 ( & V_44 -> V_79 ) ;
V_13 = F_27 ( V_44 , V_37 , args -> V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
F_55 ( & V_44 -> V_79 ) ;
return - V_11 ;
}
V_25 = F_12 ( V_13 ) ;
args -> V_9 = V_25 -> V_9 ;
args -> V_20 = V_25 -> V_20 ;
F_53 ( V_13 ) ;
F_55 ( & V_44 -> V_79 ) ;
return 0 ;
}
struct V_14 * F_57 ( struct V_14 * V_15 )
{
struct V_14 * V_86 ;
V_86 = F_58 ( sizeof( * V_86 ) , V_47 ) ;
if ( ! V_86 )
return NULL ;
if ( V_15 -> V_69 && V_15 -> V_69 -> V_87 )
V_15 -> V_69 -> V_87 ( V_15 ) ;
if ( V_15 -> V_88 )
F_59 ( V_15 -> V_88 ) ;
memcpy ( V_86 , V_15 , sizeof( * V_15 ) ) ;
V_86 -> V_89 = NULL ;
V_86 -> V_90 = NULL ;
V_86 -> V_91 = NULL ;
return V_86 ;
}
void F_60 ( struct V_14 * V_15 )
{
if ( ! V_15 )
return;
if ( V_15 -> V_69 && V_15 -> V_69 -> V_92 )
V_15 -> V_69 -> V_92 ( V_15 ) ;
if ( V_15 -> V_88 )
F_61 ( V_15 -> V_88 ) ;
F_25 ( V_15 ) ;
}
int F_62 ( unsigned long V_93 ,
unsigned int V_94 ,
struct V_95 * * V_75 ,
struct V_14 * V_15 )
{
int V_96 ;
if ( F_63 ( V_15 ) ) {
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_94 ; ++ V_32 , V_93 += V_21 ) {
unsigned long V_31 ;
int V_39 = F_64 ( V_15 , V_93 , & V_31 ) ;
if ( V_39 )
return V_39 ;
V_75 [ V_32 ] = F_65 ( V_31 ) ;
}
if ( V_32 != V_94 ) {
F_3 ( L_14 ) ;
return - V_11 ;
}
return 0 ;
}
V_96 = F_66 ( V_97 , V_97 -> V_98 , V_93 ,
V_94 , 1 , 1 , V_75 , NULL ) ;
V_96 = F_67 ( V_96 , 0 ) ;
if ( V_96 != V_94 ) {
F_3 ( L_14 ) ;
while ( V_96 )
F_68 ( V_75 [ -- V_96 ] ) ;
return - V_62 ;
}
return 0 ;
}
void F_69 ( struct V_95 * * V_75 ,
unsigned int V_94 ,
struct V_14 * V_15 )
{
if ( ! F_63 ( V_15 ) ) {
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_94 ; V_32 ++ ) {
F_70 ( V_75 [ V_32 ] ) ;
F_68 ( V_75 [ V_32 ] ) ;
}
}
}
int F_71 ( struct V_45 * V_60 ,
struct V_99 * V_33 ,
enum V_100 V_101 )
{
int V_102 ;
F_51 ( & V_60 -> V_79 ) ;
V_102 = F_72 ( V_60 -> V_44 , V_33 -> V_30 , V_33 -> V_102 , V_101 ) ;
if ( ! V_102 ) {
F_3 ( L_15 ) ;
F_55 ( & V_60 -> V_79 ) ;
return V_102 ;
}
F_55 ( & V_60 -> V_79 ) ;
return 0 ;
}
void F_73 ( struct V_45 * V_60 ,
struct V_99 * V_33 ,
enum V_100 V_101 )
{
F_74 ( V_60 -> V_44 , V_33 -> V_30 , V_33 -> V_102 , V_101 ) ;
}
int F_75 ( struct V_22 * V_13 )
{
return 0 ;
}
void F_76 ( struct V_22 * V_13 )
{
struct V_12 * V_25 ;
struct V_26 * V_27 ;
V_25 = F_12 ( V_13 ) ;
V_27 = V_25 -> V_28 ;
if ( V_13 -> V_42 )
F_77 ( V_13 , V_27 -> V_33 ) ;
F_20 ( F_12 ( V_13 ) ) ;
}
int F_78 ( struct V_36 * V_37 ,
struct V_45 * V_44 ,
struct V_103 * args )
{
struct V_12 * V_25 ;
int V_39 ;
args -> V_104 = args -> V_105 * ( ( args -> V_106 + 7 ) / 8 ) ;
args -> V_20 = args -> V_104 * args -> V_107 ;
V_25 = F_31 ( V_44 , V_108 |
V_19 , args -> V_20 ) ;
if ( F_36 ( V_25 ) && F_79 ( V_44 ) ) {
F_80 ( V_44 -> V_44 , L_16 ) ;
V_25 = F_31 ( V_44 ,
V_109 | V_19 ,
args -> V_20 ) ;
}
if ( F_36 ( V_25 ) )
return F_37 ( V_25 ) ;
V_39 = F_17 ( & V_25 -> V_40 , V_37 ,
& args -> V_38 ) ;
if ( V_39 ) {
F_20 ( V_25 ) ;
return V_39 ;
}
return 0 ;
}
int F_41 ( struct V_36 * V_37 ,
struct V_45 * V_44 , T_3 V_38 ,
T_4 * V_55 )
{
struct V_22 * V_13 ;
int V_39 = 0 ;
F_51 ( & V_44 -> V_79 ) ;
V_13 = F_27 ( V_44 , V_37 , V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
V_39 = - V_11 ;
goto V_110;
}
V_39 = F_81 ( V_13 ) ;
if ( V_39 )
goto V_43;
* V_55 = F_82 ( & V_13 -> V_111 ) ;
F_5 ( L_17 , ( unsigned long ) * V_55 ) ;
V_43:
F_53 ( V_13 ) ;
V_110:
F_55 ( & V_44 -> V_79 ) ;
return V_39 ;
}
int F_83 ( struct V_14 * V_15 , struct V_112 * V_113 )
{
struct V_22 * V_13 = V_15 -> V_68 ;
struct V_45 * V_44 = V_13 -> V_44 ;
unsigned long V_23 ;
T_1 V_24 ;
int V_39 ;
V_24 = ( ( unsigned long ) V_113 -> V_114 -
V_15 -> V_74 ) >> V_34 ;
V_23 = ( unsigned long ) V_113 -> V_114 ;
F_51 ( & V_44 -> V_79 ) ;
V_39 = F_11 ( V_13 , V_15 , V_23 , V_24 ) ;
if ( V_39 < 0 )
F_3 ( L_18 ) ;
F_55 ( & V_44 -> V_79 ) ;
return F_1 ( V_39 ) ;
}
int F_84 ( struct V_61 * V_48 , struct V_14 * V_15 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
int V_39 ;
V_39 = F_85 ( V_48 , V_15 ) ;
if ( V_39 < 0 ) {
F_3 ( L_12 ) ;
return V_39 ;
}
V_13 = V_15 -> V_68 ;
V_25 = F_12 ( V_13 ) ;
V_39 = F_2 ( V_25 -> V_9 ) ;
if ( V_39 ) {
F_86 ( V_15 ) ;
F_23 ( V_13 ) ;
return V_39 ;
}
V_15 -> V_18 &= ~ V_115 ;
V_15 -> V_18 |= V_116 ;
F_4 ( V_25 , V_15 ) ;
return V_39 ;
}
