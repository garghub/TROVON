static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
enum V_6 V_7 ;
unsigned int V_8 ;
if ( V_2 -> V_9 ) {
F_2 ( L_1 ) ;
return 0 ;
}
F_3 ( & V_2 -> V_10 ) ;
if ( ! ( V_2 -> V_11 & V_12 ) )
F_4 ( V_13 , & V_2 -> V_10 ) ;
if ( V_2 -> V_11 & V_14 || ! ( V_2 -> V_11 & V_15 ) )
V_7 = V_16 ;
else
V_7 = V_17 ;
F_4 ( V_7 , & V_2 -> V_10 ) ;
F_4 ( V_18 , & V_2 -> V_10 ) ;
V_8 = V_2 -> V_19 >> V_20 ;
if ( ! F_5 ( V_4 ) ) {
V_2 -> V_21 = F_6 ( V_8 , sizeof( struct V_22 * ) ) ;
if ( ! V_2 -> V_21 ) {
F_7 ( L_2 ) ;
return - V_23 ;
}
}
V_2 -> V_24 = F_8 ( V_4 -> V_4 , V_2 -> V_19 , & V_2 -> V_9 ,
V_25 , & V_2 -> V_10 ) ;
if ( ! V_2 -> V_24 ) {
F_7 ( L_3 ) ;
if ( V_2 -> V_21 )
F_9 ( V_2 -> V_21 ) ;
return - V_23 ;
}
if ( V_2 -> V_21 ) {
T_1 V_26 ;
unsigned int V_27 = 0 ;
V_26 = V_2 -> V_9 ;
while ( V_27 < V_8 ) {
V_2 -> V_21 [ V_27 ] = F_10 ( F_11 ( V_4 -> V_4 ,
V_26 ) ) ;
V_26 += V_28 ;
V_27 ++ ;
}
} else {
V_2 -> V_21 = V_2 -> V_24 ;
}
F_2 ( L_4 ,
( unsigned long ) V_2 -> V_9 ,
V_2 -> V_19 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( ! V_2 -> V_9 ) {
F_2 ( L_5 ) ;
return;
}
F_2 ( L_4 ,
( unsigned long ) V_2 -> V_9 , V_2 -> V_19 ) ;
F_13 ( V_4 -> V_4 , V_2 -> V_19 , V_2 -> V_24 ,
( T_1 ) V_2 -> V_9 , & V_2 -> V_10 ) ;
if ( ! F_5 ( V_4 ) )
F_9 ( V_2 -> V_21 ) ;
}
static int F_14 ( struct V_29 * V_2 ,
struct V_30 * V_31 ,
unsigned int * V_32 )
{
int V_33 ;
V_33 = F_15 ( V_31 , V_2 , V_32 ) ;
if ( V_33 )
return V_33 ;
F_2 ( L_6 , * V_32 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_34 )
{
struct V_29 * V_2 = & V_34 -> V_5 ;
F_2 ( L_7 , V_2 -> V_35 ) ;
if ( V_2 -> V_36 )
F_18 ( V_2 , V_34 -> V_37 ) ;
else
F_12 ( V_34 ) ;
F_19 ( V_2 ) ;
F_20 ( V_34 ) ;
}
unsigned long F_21 ( struct V_3 * V_4 ,
unsigned int V_38 ,
struct V_30 * V_31 )
{
struct V_1 * V_34 ;
struct V_29 * V_2 ;
V_2 = F_22 ( V_4 , V_31 , V_38 ) ;
if ( ! V_2 ) {
F_7 ( L_8 ) ;
return 0 ;
}
V_34 = F_23 ( V_2 ) ;
F_16 ( V_2 ) ;
return V_34 -> V_19 ;
}
static struct V_1 * F_24 ( struct V_3 * V_4 ,
unsigned long V_19 )
{
struct V_1 * V_34 ;
struct V_29 * V_2 ;
int V_33 ;
V_34 = F_25 ( sizeof( * V_34 ) , V_25 ) ;
if ( ! V_34 )
return F_26 ( - V_23 ) ;
V_34 -> V_19 = V_19 ;
V_2 = & V_34 -> V_5 ;
V_33 = F_27 ( V_4 , V_2 , V_19 ) ;
if ( V_33 < 0 ) {
F_7 ( L_9 ) ;
F_20 ( V_34 ) ;
return F_26 ( V_33 ) ;
}
V_33 = F_28 ( V_2 ) ;
if ( V_33 < 0 ) {
F_19 ( V_2 ) ;
F_20 ( V_34 ) ;
return F_26 ( V_33 ) ;
}
F_2 ( L_10 , ( unsigned int ) V_2 -> V_39 ) ;
return V_34 ;
}
struct V_1 * F_29 ( struct V_3 * V_4 ,
unsigned int V_11 ,
unsigned long V_19 )
{
struct V_1 * V_34 ;
int V_33 ;
if ( V_11 & ~ ( V_40 ) ) {
F_7 ( L_11 ) ;
return F_26 ( - V_41 ) ;
}
if ( ! V_19 ) {
F_7 ( L_12 ) ;
return F_26 ( - V_41 ) ;
}
V_19 = F_30 ( V_19 , V_28 ) ;
V_34 = F_24 ( V_4 , V_19 ) ;
if ( F_31 ( V_34 ) )
return V_34 ;
V_34 -> V_11 = V_11 ;
V_33 = F_1 ( V_34 ) ;
if ( V_33 < 0 ) {
F_19 ( & V_34 -> V_5 ) ;
F_20 ( V_34 ) ;
return F_26 ( V_33 ) ;
}
return V_34 ;
}
int F_32 ( struct V_3 * V_4 , void * V_42 ,
struct V_30 * V_31 )
{
struct V_43 * args = V_42 ;
struct V_1 * V_34 ;
int V_33 ;
V_34 = F_29 ( V_4 , args -> V_11 , args -> V_19 ) ;
if ( F_31 ( V_34 ) )
return F_33 ( V_34 ) ;
V_33 = F_14 ( & V_34 -> V_5 , V_31 ,
& args -> V_32 ) ;
if ( V_33 ) {
F_17 ( V_34 ) ;
return V_33 ;
}
return 0 ;
}
T_1 * F_34 ( struct V_3 * V_4 ,
unsigned int V_38 ,
struct V_30 * V_39 )
{
struct V_1 * V_34 ;
struct V_29 * V_2 ;
V_2 = F_22 ( V_4 , V_39 , V_38 ) ;
if ( ! V_2 ) {
F_7 ( L_8 ) ;
return F_26 ( - V_41 ) ;
}
V_34 = F_23 ( V_2 ) ;
return & V_34 -> V_9 ;
}
void F_35 ( struct V_3 * V_4 ,
unsigned int V_38 ,
struct V_30 * V_39 )
{
struct V_29 * V_2 ;
V_2 = F_22 ( V_4 , V_39 , V_38 ) ;
if ( ! V_2 ) {
F_7 ( L_8 ) ;
return;
}
F_16 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_34 ,
struct V_44 * V_45 )
{
struct V_3 * V_46 = V_34 -> V_5 . V_4 ;
unsigned long V_47 ;
int V_33 ;
V_45 -> V_48 &= ~ V_49 ;
V_45 -> V_50 = 0 ;
V_47 = V_45 -> V_51 - V_45 -> V_52 ;
if ( V_47 > V_34 -> V_19 )
return - V_41 ;
V_33 = F_37 ( V_46 -> V_4 , V_45 , V_34 -> V_21 ,
V_34 -> V_9 , V_34 -> V_19 ,
& V_34 -> V_10 ) ;
if ( V_33 < 0 ) {
F_7 ( L_13 ) ;
return V_33 ;
}
return 0 ;
}
int F_38 ( struct V_3 * V_4 , void * V_42 ,
struct V_30 * V_31 )
{
struct V_1 * V_34 ;
struct V_53 * args = V_42 ;
struct V_29 * V_2 ;
F_39 ( & V_4 -> V_54 ) ;
V_2 = F_22 ( V_4 , V_31 , args -> V_32 ) ;
if ( ! V_2 ) {
F_7 ( L_8 ) ;
F_40 ( & V_4 -> V_54 ) ;
return - V_41 ;
}
V_34 = F_23 ( V_2 ) ;
args -> V_11 = V_34 -> V_11 ;
args -> V_19 = V_34 -> V_19 ;
F_41 ( V_2 ) ;
F_40 ( & V_4 -> V_54 ) ;
return 0 ;
}
int F_42 ( struct V_3 * V_46 ,
struct V_55 * V_37 ,
enum V_56 V_57 )
{
int V_58 ;
F_39 ( & V_46 -> V_54 ) ;
V_58 = F_43 ( V_46 -> V_4 , V_37 -> V_59 , V_37 -> V_58 , V_57 ) ;
if ( ! V_58 ) {
F_7 ( L_14 ) ;
F_40 ( & V_46 -> V_54 ) ;
return V_58 ;
}
F_40 ( & V_46 -> V_54 ) ;
return 0 ;
}
void F_44 ( struct V_3 * V_46 ,
struct V_55 * V_37 ,
enum V_56 V_57 )
{
F_45 ( V_46 -> V_4 , V_37 -> V_59 , V_37 -> V_58 , V_57 ) ;
}
void F_46 ( struct V_29 * V_2 )
{
F_17 ( F_23 ( V_2 ) ) ;
}
int F_47 ( struct V_30 * V_31 ,
struct V_3 * V_4 ,
struct V_60 * args )
{
struct V_1 * V_34 ;
unsigned int V_11 ;
int V_33 ;
args -> V_61 = args -> V_62 * ( ( args -> V_63 + 7 ) / 8 ) ;
args -> V_19 = args -> V_61 * args -> V_64 ;
if ( F_5 ( V_4 ) )
V_11 = V_12 | V_14 ;
else
V_11 = V_65 | V_14 ;
V_34 = F_29 ( V_4 , V_11 , args -> V_19 ) ;
if ( F_31 ( V_34 ) ) {
F_48 ( V_4 -> V_4 , L_15 ) ;
return F_33 ( V_34 ) ;
}
V_33 = F_14 ( & V_34 -> V_5 , V_31 ,
& args -> V_32 ) ;
if ( V_33 ) {
F_17 ( V_34 ) ;
return V_33 ;
}
return 0 ;
}
int F_49 ( struct V_30 * V_31 ,
struct V_3 * V_4 , T_2 V_32 ,
T_3 * V_66 )
{
struct V_29 * V_2 ;
int V_33 = 0 ;
F_39 ( & V_4 -> V_54 ) ;
V_2 = F_22 ( V_4 , V_31 , V_32 ) ;
if ( ! V_2 ) {
F_7 ( L_8 ) ;
V_33 = - V_41 ;
goto V_67;
}
* V_66 = F_50 ( & V_2 -> V_68 ) ;
F_2 ( L_16 , ( unsigned long ) * V_66 ) ;
F_41 ( V_2 ) ;
V_67:
F_40 ( & V_4 -> V_54 ) ;
return V_33 ;
}
int F_51 ( struct V_44 * V_45 , struct V_69 * V_70 )
{
struct V_29 * V_2 = V_45 -> V_71 ;
struct V_1 * V_34 = F_23 ( V_2 ) ;
unsigned long V_72 ;
T_4 V_73 ;
int V_33 ;
V_73 = ( ( unsigned long ) V_70 -> V_74 -
V_45 -> V_52 ) >> V_20 ;
if ( V_73 >= ( V_34 -> V_19 >> V_20 ) ) {
F_7 ( L_17 ) ;
V_33 = - V_41 ;
goto V_75;
}
V_72 = F_52 ( V_34 -> V_21 [ V_73 ] ) ;
V_33 = F_53 ( V_45 , ( unsigned long ) V_70 -> V_74 , V_72 ) ;
V_75:
switch ( V_33 ) {
case 0 :
case - V_76 :
case - V_77 :
return V_78 ;
case - V_23 :
return V_79 ;
default:
return V_80 ;
}
}
int F_54 ( struct V_81 * V_39 , struct V_44 * V_45 )
{
struct V_1 * V_34 ;
struct V_29 * V_2 ;
int V_33 ;
V_33 = F_55 ( V_39 , V_45 ) ;
if ( V_33 < 0 ) {
F_7 ( L_13 ) ;
return V_33 ;
}
V_2 = V_45 -> V_71 ;
V_34 = F_23 ( V_2 ) ;
F_2 ( L_18 , V_34 -> V_11 ) ;
if ( V_34 -> V_11 & V_15 )
V_45 -> V_82 = F_56 ( V_45 -> V_48 ) ;
else if ( V_34 -> V_11 & V_14 )
V_45 -> V_82 =
F_57 ( F_56 ( V_45 -> V_48 ) ) ;
else
V_45 -> V_82 =
F_58 ( F_56 ( V_45 -> V_48 ) ) ;
V_33 = F_36 ( V_34 , V_45 ) ;
if ( V_33 )
goto V_83;
return V_33 ;
V_83:
F_59 ( V_45 ) ;
return V_33 ;
}
struct V_55 * F_60 ( struct V_29 * V_2 )
{
struct V_1 * V_34 = F_23 ( V_2 ) ;
int V_84 ;
V_84 = V_34 -> V_19 >> V_20 ;
return F_61 ( V_34 -> V_21 , V_84 ) ;
}
struct V_29 *
F_62 ( struct V_3 * V_4 ,
struct V_85 * V_86 ,
struct V_55 * V_37 )
{
struct V_1 * V_34 ;
int V_84 ;
int V_33 ;
V_34 = F_24 ( V_4 , V_86 -> V_87 -> V_19 ) ;
if ( F_31 ( V_34 ) ) {
V_33 = F_33 ( V_34 ) ;
return F_26 ( V_33 ) ;
}
V_34 -> V_9 = F_63 ( V_37 -> V_59 ) ;
V_84 = V_34 -> V_19 >> V_20 ;
V_34 -> V_21 = F_64 ( V_84 , sizeof( struct V_22 * ) ) ;
if ( ! V_34 -> V_21 ) {
V_33 = - V_23 ;
goto V_88;
}
V_33 = F_65 ( V_37 , V_34 -> V_21 , NULL ,
V_84 ) ;
if ( V_33 < 0 )
goto V_89;
V_34 -> V_37 = V_37 ;
if ( V_37 -> V_58 == 1 ) {
V_34 -> V_11 |= V_65 ;
} else {
V_34 -> V_11 |= V_12 ;
}
return & V_34 -> V_5 ;
V_89:
F_9 ( V_34 -> V_21 ) ;
V_88:
F_19 ( & V_34 -> V_5 ) ;
F_20 ( V_34 ) ;
return F_26 ( V_33 ) ;
}
void * F_66 ( struct V_29 * V_2 )
{
return NULL ;
}
void F_67 ( struct V_29 * V_2 , void * V_90 )
{
}
