static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
enum V_6 V_7 ;
unsigned int V_8 ;
struct V_9 V_10 ;
int V_11 = - V_12 ;
if ( V_2 -> V_13 ) {
F_2 ( L_1 ) ;
return 0 ;
}
F_3 ( & V_2 -> V_14 ) ;
if ( ! ( V_2 -> V_15 & V_16 ) )
F_4 ( V_17 , & V_2 -> V_14 ) ;
if ( V_2 -> V_15 & V_18 ||
! ( V_2 -> V_15 & V_19 ) )
V_7 = V_20 ;
else
V_7 = V_21 ;
F_4 ( V_7 , & V_2 -> V_14 ) ;
F_4 ( V_22 , & V_2 -> V_14 ) ;
V_8 = V_2 -> V_23 >> V_24 ;
V_2 -> V_25 = F_5 ( V_8 , sizeof( struct V_26 * ) ) ;
if ( ! V_2 -> V_25 ) {
F_6 ( L_2 ) ;
return - V_12 ;
}
V_2 -> V_27 = F_7 ( F_8 ( V_4 ) , V_2 -> V_23 ,
& V_2 -> V_13 , V_28 ,
& V_2 -> V_14 ) ;
if ( ! V_2 -> V_27 ) {
F_6 ( L_3 ) ;
goto V_29;
}
V_11 = F_9 ( F_8 ( V_4 ) , & V_10 , V_2 -> V_27 ,
V_2 -> V_13 , V_2 -> V_23 ,
& V_2 -> V_14 ) ;
if ( V_11 < 0 ) {
F_6 ( L_4 ) ;
goto V_30;
}
if ( F_10 ( & V_10 , V_2 -> V_25 , NULL ,
V_8 ) ) {
F_6 ( L_5 ) ;
V_11 = - V_31 ;
goto V_32;
}
F_11 ( & V_10 ) ;
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_13 , V_2 -> V_23 ) ;
return 0 ;
V_32:
F_11 ( & V_10 ) ;
V_30:
F_12 ( F_8 ( V_4 ) , V_2 -> V_23 , V_2 -> V_27 ,
V_2 -> V_13 , & V_2 -> V_14 ) ;
V_29:
F_13 ( V_2 -> V_25 ) ;
return V_11 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( ! V_2 -> V_13 ) {
F_2 ( L_7 ) ;
return;
}
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_13 , V_2 -> V_23 ) ;
F_12 ( F_8 ( V_4 ) , V_2 -> V_23 , V_2 -> V_27 ,
( V_33 ) V_2 -> V_13 ,
& V_2 -> V_14 ) ;
F_13 ( V_2 -> V_25 ) ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
unsigned int * V_38 )
{
int V_11 ;
V_11 = F_16 ( V_37 , V_35 , V_38 ) ;
if ( V_11 )
return V_11 ;
F_2 ( L_8 , * V_38 ) ;
F_17 ( V_35 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_5 ;
F_2 ( L_9 , V_35 -> V_39 ) ;
if ( V_35 -> V_40 )
F_19 ( V_35 , V_2 -> V_10 ) ;
else
F_14 ( V_2 ) ;
F_20 ( V_35 ) ;
F_21 ( V_2 ) ;
}
unsigned long F_22 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_23 ( V_37 , V_41 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return 0 ;
}
V_2 = F_24 ( V_35 ) ;
F_17 ( V_35 ) ;
return V_2 -> V_23 ;
}
static struct V_1 * F_25 ( struct V_3 * V_4 ,
unsigned long V_23 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_11 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_27 ( - V_12 ) ;
V_2 -> V_23 = V_23 ;
V_35 = & V_2 -> V_5 ;
V_11 = F_28 ( V_4 , V_35 , V_23 ) ;
if ( V_11 < 0 ) {
F_6 ( L_11 ) ;
F_21 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
V_11 = F_29 ( V_35 ) ;
if ( V_11 < 0 ) {
F_20 ( V_35 ) ;
F_21 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
F_2 ( L_12 , V_35 -> V_42 ) ;
return V_2 ;
}
struct V_1 * F_30 ( struct V_3 * V_4 ,
unsigned int V_15 ,
unsigned long V_23 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( V_15 & ~ ( V_43 ) ) {
F_6 ( L_13 ) ;
return F_27 ( - V_31 ) ;
}
if ( ! V_23 ) {
F_6 ( L_14 ) ;
return F_27 ( - V_31 ) ;
}
V_23 = F_31 ( V_23 , V_44 ) ;
V_2 = F_25 ( V_4 , V_23 ) ;
if ( F_32 ( V_2 ) )
return V_2 ;
V_2 -> V_15 = V_15 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_20 ( & V_2 -> V_5 ) ;
F_21 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
return V_2 ;
}
int F_33 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_46 * args = V_45 ;
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_30 ( V_4 , args -> V_15 , args -> V_23 ) ;
if ( F_32 ( V_2 ) )
return F_34 ( V_2 ) ;
V_11 = F_15 ( & V_2 -> V_5 , V_37 ,
& args -> V_38 ) ;
if ( V_11 ) {
F_18 ( V_2 ) ;
return V_11 ;
}
return 0 ;
}
int F_35 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_47 * args = V_45 ;
return F_36 ( V_37 , V_4 , args -> V_38 ,
& args -> V_48 ) ;
}
V_33 * F_37 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_42 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_23 ( V_42 , V_41 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return F_27 ( - V_31 ) ;
}
V_2 = F_24 ( V_35 ) ;
return & V_2 -> V_13 ;
}
void F_38 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_42 )
{
struct V_34 * V_35 ;
V_35 = F_23 ( V_42 , V_41 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return;
}
F_17 ( V_35 ) ;
F_17 ( V_35 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_3 * V_51 = V_2 -> V_5 . V_4 ;
unsigned long V_52 ;
int V_11 ;
V_50 -> V_53 &= ~ V_54 ;
V_50 -> V_55 = 0 ;
V_52 = V_50 -> V_56 - V_50 -> V_57 ;
if ( V_52 > V_2 -> V_23 )
return - V_31 ;
V_11 = F_40 ( F_8 ( V_51 ) , V_50 , V_2 -> V_27 ,
V_2 -> V_13 , V_2 -> V_23 ,
& V_2 -> V_14 ) ;
if ( V_11 < 0 ) {
F_6 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
int F_41 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_58 * args = V_45 ;
struct V_34 * V_35 ;
V_35 = F_23 ( V_37 , args -> V_38 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return - V_31 ;
}
V_2 = F_24 ( V_35 ) ;
args -> V_15 = V_2 -> V_15 ;
args -> V_23 = V_2 -> V_23 ;
F_17 ( V_35 ) ;
return 0 ;
}
void F_42 ( struct V_34 * V_35 )
{
F_18 ( F_24 ( V_35 ) ) ;
}
int F_43 ( struct V_36 * V_37 ,
struct V_3 * V_4 ,
struct V_59 * args )
{
struct V_1 * V_2 ;
unsigned int V_15 ;
int V_11 ;
args -> V_60 = args -> V_61 * ( ( args -> V_62 + 7 ) / 8 ) ;
args -> V_23 = args -> V_60 * args -> V_63 ;
if ( F_44 ( V_4 ) )
V_15 = V_16 | V_18 ;
else
V_15 = V_64 | V_18 ;
V_2 = F_30 ( V_4 , V_15 , args -> V_23 ) ;
if ( F_32 ( V_2 ) ) {
F_45 ( V_4 -> V_4 , L_16 ) ;
return F_34 ( V_2 ) ;
}
V_11 = F_15 ( & V_2 -> V_5 , V_37 ,
& args -> V_38 ) ;
if ( V_11 ) {
F_18 ( V_2 ) ;
return V_11 ;
}
return 0 ;
}
int F_36 ( struct V_36 * V_37 ,
struct V_3 * V_4 , T_1 V_38 ,
T_2 * V_48 )
{
struct V_34 * V_35 ;
int V_11 = 0 ;
V_35 = F_23 ( V_37 , V_38 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return - V_31 ;
}
* V_48 = F_46 ( & V_35 -> V_65 ) ;
F_2 ( L_17 , ( unsigned long ) * V_48 ) ;
F_17 ( V_35 ) ;
return V_11 ;
}
int F_47 ( struct V_49 * V_50 , struct V_66 * V_67 )
{
struct V_34 * V_35 = V_50 -> V_68 ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
unsigned long V_69 ;
T_3 V_70 ;
int V_11 ;
V_70 = ( ( unsigned long ) V_67 -> V_71 -
V_50 -> V_57 ) >> V_24 ;
if ( V_70 >= ( V_2 -> V_23 >> V_24 ) ) {
F_6 ( L_18 ) ;
V_11 = - V_31 ;
goto V_72;
}
V_69 = F_48 ( V_2 -> V_25 [ V_70 ] ) ;
V_11 = F_49 ( V_50 , ( unsigned long ) V_67 -> V_71 ,
F_50 ( V_69 , V_73 ) ) ;
V_72:
switch ( V_11 ) {
case 0 :
case - V_74 :
case - V_75 :
return V_76 ;
case - V_12 :
return V_77 ;
default:
return V_78 ;
}
}
static int F_51 ( struct V_34 * V_35 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
int V_11 ;
F_2 ( L_19 , V_2 -> V_15 ) ;
if ( V_2 -> V_15 & V_19 )
V_50 -> V_79 = F_52 ( V_50 -> V_53 ) ;
else if ( V_2 -> V_15 & V_18 )
V_50 -> V_79 =
F_53 ( F_52 ( V_50 -> V_53 ) ) ;
else
V_50 -> V_79 =
F_54 ( F_52 ( V_50 -> V_53 ) ) ;
V_11 = F_39 ( V_2 , V_50 ) ;
if ( V_11 )
goto V_80;
return V_11 ;
V_80:
F_55 ( V_50 ) ;
return V_11 ;
}
int F_56 ( struct V_81 * V_42 , struct V_49 * V_50 )
{
struct V_34 * V_35 ;
int V_11 ;
V_11 = F_57 ( V_42 , V_50 ) ;
if ( V_11 < 0 ) {
F_6 ( L_15 ) ;
return V_11 ;
}
V_35 = V_50 -> V_68 ;
if ( V_35 -> V_40 )
return F_58 ( V_35 -> V_82 , V_50 , 0 ) ;
return F_51 ( V_35 , V_50 ) ;
}
struct V_9 * F_59 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
int V_83 ;
V_83 = V_2 -> V_23 >> V_24 ;
return F_60 ( V_2 -> V_25 , V_83 ) ;
}
struct V_34 *
F_61 ( struct V_3 * V_4 ,
struct V_84 * V_85 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_83 ;
int V_11 ;
V_2 = F_25 ( V_4 , V_85 -> V_86 -> V_23 ) ;
if ( F_32 ( V_2 ) ) {
V_11 = F_34 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
V_2 -> V_13 = F_62 ( V_10 -> V_87 ) ;
V_83 = V_2 -> V_23 >> V_24 ;
V_2 -> V_25 = F_63 ( V_83 , sizeof( struct V_26 * ) ) ;
if ( ! V_2 -> V_25 ) {
V_11 = - V_12 ;
goto V_88;
}
V_11 = F_10 ( V_10 , V_2 -> V_25 , NULL ,
V_83 ) ;
if ( V_11 < 0 )
goto V_89;
V_2 -> V_10 = V_10 ;
if ( V_10 -> V_90 == 1 ) {
V_2 -> V_15 |= V_64 ;
} else {
V_2 -> V_15 |= V_16 ;
}
return & V_2 -> V_5 ;
V_89:
F_13 ( V_2 -> V_25 ) ;
V_88:
F_20 ( & V_2 -> V_5 ) ;
F_21 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
void * F_64 ( struct V_34 * V_35 )
{
return NULL ;
}
void F_65 ( struct V_34 * V_35 , void * V_91 )
{
}
int F_66 ( struct V_34 * V_35 ,
struct V_49 * V_50 )
{
int V_11 ;
V_11 = F_67 ( V_35 , V_35 -> V_23 , V_50 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_51 ( V_35 , V_50 ) ;
}
