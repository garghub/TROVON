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
struct V_22 * V_13 ;
V_13 = F_27 ( V_44 , V_48 , V_46 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
return;
}
F_19 ( V_13 ) ;
F_19 ( V_13 ) ;
}
int F_40 ( struct V_12 * V_25 ,
struct V_14 * V_15 )
{
struct V_45 * V_54 = V_25 -> V_40 . V_44 ;
struct V_26 * V_28 ;
unsigned long V_55 ;
int V_39 ;
V_15 -> V_18 &= ~ V_56 ;
V_15 -> V_57 = 0 ;
V_55 = V_15 -> V_58 - V_15 -> V_59 ;
V_28 = V_25 -> V_28 ;
if ( V_55 > V_28 -> V_20 )
return - V_11 ;
V_39 = F_41 ( V_54 -> V_44 , V_15 , V_28 -> V_60 ,
V_28 -> V_53 , V_28 -> V_20 ,
& V_28 -> V_61 ) ;
if ( V_39 < 0 ) {
F_3 ( L_10 ) ;
return V_39 ;
}
return 0 ;
}
int F_42 ( struct V_45 * V_44 , void * V_51 ,
struct V_36 * V_37 )
{ struct V_12 * V_25 ;
struct V_62 * args = V_51 ;
struct V_22 * V_13 ;
F_43 ( & V_44 -> V_63 ) ;
V_13 = F_27 ( V_44 , V_37 , args -> V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
F_44 ( & V_44 -> V_63 ) ;
return - V_11 ;
}
V_25 = F_12 ( V_13 ) ;
args -> V_9 = V_25 -> V_9 ;
args -> V_20 = V_25 -> V_20 ;
F_45 ( V_13 ) ;
F_44 ( & V_44 -> V_63 ) ;
return 0 ;
}
struct V_14 * F_46 ( struct V_14 * V_15 )
{
struct V_14 * V_64 ;
V_64 = F_47 ( sizeof( * V_64 ) , V_47 ) ;
if ( ! V_64 )
return NULL ;
if ( V_15 -> V_65 && V_15 -> V_65 -> V_66 )
V_15 -> V_65 -> V_66 ( V_15 ) ;
if ( V_15 -> V_67 )
F_48 ( V_15 -> V_67 ) ;
memcpy ( V_64 , V_15 , sizeof( * V_15 ) ) ;
V_64 -> V_68 = NULL ;
V_64 -> V_69 = NULL ;
V_64 -> V_70 = NULL ;
return V_64 ;
}
void F_49 ( struct V_14 * V_15 )
{
if ( ! V_15 )
return;
if ( V_15 -> V_65 && V_15 -> V_65 -> V_71 )
V_15 -> V_65 -> V_71 ( V_15 ) ;
if ( V_15 -> V_67 )
F_50 ( V_15 -> V_67 ) ;
F_25 ( V_15 ) ;
}
int F_51 ( unsigned long V_72 ,
unsigned int V_73 ,
struct V_74 * * V_60 ,
struct V_14 * V_15 )
{
int V_75 ;
if ( F_52 ( V_15 ) ) {
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; ++ V_32 , V_72 += V_21 ) {
unsigned long V_31 ;
int V_39 = F_53 ( V_15 , V_72 , & V_31 ) ;
if ( V_39 )
return V_39 ;
V_60 [ V_32 ] = F_54 ( V_31 ) ;
}
if ( V_32 != V_73 ) {
F_3 ( L_11 ) ;
return - V_11 ;
}
return 0 ;
}
V_75 = F_55 ( V_76 , V_76 -> V_77 , V_72 ,
V_73 , 1 , 1 , V_60 , NULL ) ;
V_75 = F_56 ( V_75 , 0 ) ;
if ( V_75 != V_73 ) {
F_3 ( L_11 ) ;
while ( V_75 )
F_57 ( V_60 [ -- V_75 ] ) ;
return - V_78 ;
}
return 0 ;
}
void F_58 ( struct V_74 * * V_60 ,
unsigned int V_73 ,
struct V_14 * V_15 )
{
if ( ! F_52 ( V_15 ) ) {
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
F_59 ( V_60 [ V_32 ] ) ;
F_57 ( V_60 [ V_32 ] ) ;
}
}
}
int F_60 ( struct V_45 * V_54 ,
struct V_79 * V_33 ,
enum V_80 V_81 )
{
int V_82 ;
F_43 ( & V_54 -> V_63 ) ;
V_82 = F_61 ( V_54 -> V_44 , V_33 -> V_30 , V_33 -> V_82 , V_81 ) ;
if ( ! V_82 ) {
F_3 ( L_12 ) ;
F_44 ( & V_54 -> V_63 ) ;
return V_82 ;
}
F_44 ( & V_54 -> V_63 ) ;
return 0 ;
}
void F_62 ( struct V_45 * V_54 ,
struct V_79 * V_33 ,
enum V_80 V_81 )
{
F_63 ( V_54 -> V_44 , V_33 -> V_30 , V_33 -> V_82 , V_81 ) ;
}
void F_64 ( struct V_22 * V_13 )
{
struct V_12 * V_25 ;
struct V_26 * V_27 ;
V_25 = F_12 ( V_13 ) ;
V_27 = V_25 -> V_28 ;
if ( V_13 -> V_42 )
F_65 ( V_13 , V_27 -> V_33 ) ;
F_20 ( F_12 ( V_13 ) ) ;
}
int F_66 ( struct V_36 * V_37 ,
struct V_45 * V_44 ,
struct V_83 * args )
{
struct V_12 * V_25 ;
int V_39 ;
args -> V_84 = args -> V_85 * ( ( args -> V_86 + 7 ) / 8 ) ;
args -> V_20 = args -> V_84 * args -> V_87 ;
if ( F_67 ( V_44 ) ) {
V_25 = F_31 ( V_44 ,
V_88 | V_19 ,
args -> V_20 ) ;
} else {
V_25 = F_31 ( V_44 ,
V_89 | V_19 ,
args -> V_20 ) ;
}
if ( F_36 ( V_25 ) ) {
F_68 ( V_44 -> V_44 , L_13 ) ;
return F_37 ( V_25 ) ;
}
V_39 = F_17 ( & V_25 -> V_40 , V_37 ,
& args -> V_38 ) ;
if ( V_39 ) {
F_20 ( V_25 ) ;
return V_39 ;
}
return 0 ;
}
int F_69 ( struct V_36 * V_37 ,
struct V_45 * V_44 , T_3 V_38 ,
T_4 * V_90 )
{
struct V_22 * V_13 ;
int V_39 = 0 ;
F_43 ( & V_44 -> V_63 ) ;
V_13 = F_27 ( V_44 , V_37 , V_38 ) ;
if ( ! V_13 ) {
F_3 ( L_6 ) ;
V_39 = - V_11 ;
goto V_91;
}
V_39 = F_70 ( V_13 ) ;
if ( V_39 )
goto V_43;
* V_90 = F_71 ( & V_13 -> V_92 ) ;
F_5 ( L_14 , ( unsigned long ) * V_90 ) ;
V_43:
F_45 ( V_13 ) ;
V_91:
F_44 ( & V_44 -> V_63 ) ;
return V_39 ;
}
int F_72 ( struct V_14 * V_15 , struct V_93 * V_94 )
{
struct V_22 * V_13 = V_15 -> V_95 ;
struct V_45 * V_44 = V_13 -> V_44 ;
unsigned long V_23 ;
T_1 V_24 ;
int V_39 ;
V_24 = ( ( unsigned long ) V_94 -> V_96 -
V_15 -> V_59 ) >> V_34 ;
V_23 = ( unsigned long ) V_94 -> V_96 ;
F_43 ( & V_44 -> V_63 ) ;
V_39 = F_11 ( V_13 , V_15 , V_23 , V_24 ) ;
if ( V_39 < 0 )
F_3 ( L_15 ) ;
F_44 ( & V_44 -> V_63 ) ;
return F_1 ( V_39 ) ;
}
int F_73 ( struct V_97 * V_48 , struct V_14 * V_15 )
{
struct V_12 * V_25 ;
struct V_22 * V_13 ;
int V_39 ;
V_39 = F_74 ( V_48 , V_15 ) ;
if ( V_39 < 0 ) {
F_3 ( L_10 ) ;
return V_39 ;
}
V_13 = V_15 -> V_95 ;
V_25 = F_12 ( V_13 ) ;
V_39 = F_2 ( V_25 -> V_9 ) ;
if ( V_39 )
goto V_98;
F_4 ( V_25 , V_15 ) ;
V_39 = F_40 ( V_25 , V_15 ) ;
if ( V_39 )
goto V_98;
return V_39 ;
V_98:
F_75 ( V_15 ) ;
F_23 ( V_13 ) ;
return V_39 ;
}
