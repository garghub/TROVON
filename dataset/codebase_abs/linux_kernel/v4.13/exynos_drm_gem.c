static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
unsigned long V_6 ;
unsigned int V_7 ;
struct V_8 V_9 ;
int V_10 = - V_11 ;
if ( V_2 -> V_12 ) {
F_2 ( L_1 ) ;
return 0 ;
}
V_2 -> V_13 = 0 ;
if ( ! ( V_2 -> V_14 & V_15 ) )
V_2 -> V_13 |= V_16 ;
if ( V_2 -> V_14 & V_17 ||
! ( V_2 -> V_14 & V_18 ) )
V_6 = V_19 ;
else
V_6 = V_20 ;
V_2 -> V_13 |= V_6 ;
V_2 -> V_13 |= V_21 ;
V_7 = V_2 -> V_22 >> V_23 ;
V_2 -> V_24 = F_3 ( V_7 , sizeof( struct V_25 * ) ,
V_26 | V_27 ) ;
if ( ! V_2 -> V_24 ) {
F_4 ( L_2 ) ;
return - V_11 ;
}
V_2 -> V_28 = F_5 ( F_6 ( V_4 ) , V_2 -> V_22 ,
& V_2 -> V_12 , V_26 ,
V_2 -> V_13 ) ;
if ( ! V_2 -> V_28 ) {
F_4 ( L_3 ) ;
goto V_29;
}
V_10 = F_7 ( F_6 ( V_4 ) , & V_9 , V_2 -> V_28 ,
V_2 -> V_12 , V_2 -> V_22 ,
V_2 -> V_13 ) ;
if ( V_10 < 0 ) {
F_4 ( L_4 ) ;
goto V_30;
}
if ( F_8 ( & V_9 , V_2 -> V_24 , NULL ,
V_7 ) ) {
F_4 ( L_5 ) ;
V_10 = - V_31 ;
goto V_32;
}
F_9 ( & V_9 ) ;
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_12 , V_2 -> V_22 ) ;
return 0 ;
V_32:
F_9 ( & V_9 ) ;
V_30:
F_10 ( F_6 ( V_4 ) , V_2 -> V_22 , V_2 -> V_28 ,
V_2 -> V_12 , V_2 -> V_13 ) ;
V_29:
F_11 ( V_2 -> V_24 ) ;
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( ! V_2 -> V_12 ) {
F_2 ( L_7 ) ;
return;
}
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_12 , V_2 -> V_22 ) ;
F_10 ( F_6 ( V_4 ) , V_2 -> V_22 , V_2 -> V_28 ,
( V_33 ) V_2 -> V_12 ,
V_2 -> V_13 ) ;
F_11 ( V_2 -> V_24 ) ;
}
static int F_13 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
unsigned int * V_38 )
{
int V_10 ;
V_10 = F_14 ( V_37 , V_35 , V_38 ) ;
if ( V_10 )
return V_10 ;
F_2 ( L_8 , * V_38 ) ;
F_15 ( V_35 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_5 ;
F_2 ( L_9 , V_35 -> V_39 ) ;
if ( V_35 -> V_40 )
F_17 ( V_35 , V_2 -> V_9 ) ;
else
F_12 ( V_2 ) ;
F_18 ( V_35 ) ;
F_19 ( V_2 ) ;
}
unsigned long F_20 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_21 ( V_37 , V_41 ) ;
if ( ! V_35 ) {
F_4 ( L_10 ) ;
return 0 ;
}
V_2 = F_22 ( V_35 ) ;
F_15 ( V_35 ) ;
return V_2 -> V_22 ;
}
static struct V_1 * F_23 ( struct V_3 * V_4 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_10 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return F_25 ( - V_11 ) ;
V_2 -> V_22 = V_22 ;
V_35 = & V_2 -> V_5 ;
V_10 = F_26 ( V_4 , V_35 , V_22 ) ;
if ( V_10 < 0 ) {
F_4 ( L_11 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
V_10 = F_27 ( V_35 ) ;
if ( V_10 < 0 ) {
F_18 ( V_35 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
F_2 ( L_12 , V_35 -> V_42 ) ;
return V_2 ;
}
struct V_1 * F_28 ( struct V_3 * V_4 ,
unsigned int V_14 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
int V_10 ;
if ( V_14 & ~ ( V_43 ) ) {
F_4 ( L_13 , V_14 ) ;
return F_25 ( - V_31 ) ;
}
if ( ! V_22 ) {
F_4 ( L_14 , V_22 ) ;
return F_25 ( - V_31 ) ;
}
V_22 = F_29 ( V_22 , V_44 ) ;
V_2 = F_23 ( V_4 , V_22 ) ;
if ( F_30 ( V_2 ) )
return V_2 ;
V_2 -> V_14 = V_14 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 ) {
F_18 ( & V_2 -> V_5 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
return V_2 ;
}
int F_31 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_46 * args = V_45 ;
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_28 ( V_4 , args -> V_14 , args -> V_22 ) ;
if ( F_30 ( V_2 ) )
return F_32 ( V_2 ) ;
V_10 = F_13 ( & V_2 -> V_5 , V_37 ,
& args -> V_38 ) ;
if ( V_10 ) {
F_16 ( V_2 ) ;
return V_10 ;
}
return 0 ;
}
int F_33 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_47 * args = V_45 ;
return F_34 ( V_37 , V_4 , args -> V_38 ,
& args -> V_48 ) ;
}
V_33 * F_35 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_42 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_21 ( V_42 , V_41 ) ;
if ( ! V_35 ) {
F_4 ( L_10 ) ;
return F_25 ( - V_31 ) ;
}
V_2 = F_22 ( V_35 ) ;
return & V_2 -> V_12 ;
}
void F_36 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_42 )
{
struct V_34 * V_35 ;
V_35 = F_21 ( V_42 , V_41 ) ;
if ( ! V_35 ) {
F_4 ( L_10 ) ;
return;
}
F_15 ( V_35 ) ;
F_15 ( V_35 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_3 * V_51 = V_2 -> V_5 . V_4 ;
unsigned long V_52 ;
int V_10 ;
V_50 -> V_53 &= ~ V_54 ;
V_50 -> V_55 = 0 ;
V_52 = V_50 -> V_56 - V_50 -> V_57 ;
if ( V_52 > V_2 -> V_22 )
return - V_31 ;
V_10 = F_38 ( F_6 ( V_51 ) , V_50 , V_2 -> V_28 ,
V_2 -> V_12 , V_2 -> V_22 ,
V_2 -> V_13 ) ;
if ( V_10 < 0 ) {
F_4 ( L_15 ) ;
return V_10 ;
}
return 0 ;
}
int F_39 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_58 * args = V_45 ;
struct V_34 * V_35 ;
V_35 = F_21 ( V_37 , args -> V_38 ) ;
if ( ! V_35 ) {
F_4 ( L_10 ) ;
return - V_31 ;
}
V_2 = F_22 ( V_35 ) ;
args -> V_14 = V_2 -> V_14 ;
args -> V_22 = V_2 -> V_22 ;
F_15 ( V_35 ) ;
return 0 ;
}
void F_40 ( struct V_34 * V_35 )
{
F_16 ( F_22 ( V_35 ) ) ;
}
int F_41 ( struct V_36 * V_37 ,
struct V_3 * V_4 ,
struct V_59 * args )
{
struct V_1 * V_2 ;
unsigned int V_14 ;
int V_10 ;
args -> V_60 = args -> V_61 * ( ( args -> V_62 + 7 ) / 8 ) ;
args -> V_22 = args -> V_60 * args -> V_63 ;
if ( F_42 ( V_4 ) )
V_14 = V_15 | V_17 ;
else
V_14 = V_64 | V_17 ;
V_2 = F_28 ( V_4 , V_14 , args -> V_22 ) ;
if ( F_30 ( V_2 ) ) {
F_43 ( V_4 -> V_4 , L_16 ) ;
return F_32 ( V_2 ) ;
}
V_10 = F_13 ( & V_2 -> V_5 , V_37 ,
& args -> V_38 ) ;
if ( V_10 ) {
F_16 ( V_2 ) ;
return V_10 ;
}
return 0 ;
}
int F_34 ( struct V_36 * V_37 ,
struct V_3 * V_4 , T_1 V_38 ,
T_2 * V_48 )
{
struct V_34 * V_35 ;
int V_10 = 0 ;
V_35 = F_21 ( V_37 , V_38 ) ;
if ( ! V_35 ) {
F_4 ( L_10 ) ;
return - V_31 ;
}
* V_48 = F_44 ( & V_35 -> V_65 ) ;
F_2 ( L_17 , ( unsigned long ) * V_48 ) ;
F_15 ( V_35 ) ;
return V_10 ;
}
int F_45 ( struct V_66 * V_67 )
{
struct V_49 * V_50 = V_67 -> V_50 ;
struct V_34 * V_35 = V_50 -> V_68 ;
struct V_1 * V_2 = F_22 ( V_35 ) ;
unsigned long V_69 ;
T_3 V_70 ;
int V_10 ;
V_70 = ( V_67 -> V_71 - V_50 -> V_57 ) >> V_23 ;
if ( V_70 >= ( V_2 -> V_22 >> V_23 ) ) {
F_4 ( L_18 ) ;
V_10 = - V_31 ;
goto V_72;
}
V_69 = F_46 ( V_2 -> V_24 [ V_70 ] ) ;
V_10 = F_47 ( V_50 , V_67 -> V_71 , F_48 ( V_69 , V_73 ) ) ;
V_72:
switch ( V_10 ) {
case 0 :
case - V_74 :
case - V_75 :
return V_76 ;
case - V_11 :
return V_77 ;
default:
return V_78 ;
}
}
static int F_49 ( struct V_34 * V_35 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
int V_10 ;
F_2 ( L_19 , V_2 -> V_14 ) ;
if ( V_2 -> V_14 & V_18 )
V_50 -> V_79 = F_50 ( V_50 -> V_53 ) ;
else if ( V_2 -> V_14 & V_17 )
V_50 -> V_79 =
F_51 ( F_50 ( V_50 -> V_53 ) ) ;
else
V_50 -> V_79 =
F_52 ( F_50 ( V_50 -> V_53 ) ) ;
V_10 = F_37 ( V_2 , V_50 ) ;
if ( V_10 )
goto V_80;
return V_10 ;
V_80:
F_53 ( V_50 ) ;
return V_10 ;
}
int F_54 ( struct V_81 * V_42 , struct V_49 * V_50 )
{
struct V_34 * V_35 ;
int V_10 ;
V_10 = F_55 ( V_42 , V_50 ) ;
if ( V_10 < 0 ) {
F_4 ( L_15 ) ;
return V_10 ;
}
V_35 = V_50 -> V_68 ;
if ( V_35 -> V_40 )
return F_56 ( V_35 -> V_82 , V_50 , 0 ) ;
return F_49 ( V_35 , V_50 ) ;
}
struct V_8 * F_57 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_22 ( V_35 ) ;
int V_83 ;
V_83 = V_2 -> V_22 >> V_23 ;
return F_58 ( V_2 -> V_24 , V_83 ) ;
}
struct V_34 *
F_59 ( struct V_3 * V_4 ,
struct V_84 * V_85 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_83 ;
int V_10 ;
V_2 = F_23 ( V_4 , V_85 -> V_86 -> V_22 ) ;
if ( F_30 ( V_2 ) ) {
V_10 = F_32 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
V_2 -> V_12 = F_60 ( V_9 -> V_87 ) ;
V_83 = V_2 -> V_22 >> V_23 ;
V_2 -> V_24 = F_3 ( V_83 , sizeof( struct V_25 * ) , V_26 ) ;
if ( ! V_2 -> V_24 ) {
V_10 = - V_11 ;
goto V_88;
}
V_10 = F_8 ( V_9 , V_2 -> V_24 , NULL ,
V_83 ) ;
if ( V_10 < 0 )
goto V_89;
V_2 -> V_9 = V_9 ;
if ( V_9 -> V_90 == 1 ) {
V_2 -> V_14 |= V_64 ;
} else {
V_2 -> V_14 |= V_15 ;
}
return & V_2 -> V_5 ;
V_89:
F_11 ( V_2 -> V_24 ) ;
V_88:
F_18 ( & V_2 -> V_5 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
void * F_61 ( struct V_34 * V_35 )
{
return NULL ;
}
void F_62 ( struct V_34 * V_35 , void * V_91 )
{
}
int F_63 ( struct V_34 * V_35 ,
struct V_49 * V_50 )
{
int V_10 ;
V_10 = F_64 ( V_35 , V_35 -> V_22 , V_50 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_49 ( V_35 , V_50 ) ;
}
