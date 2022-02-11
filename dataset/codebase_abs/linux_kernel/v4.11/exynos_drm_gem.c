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
V_2 -> V_24 = F_3 ( V_7 , sizeof( struct V_25 * ) ) ;
if ( ! V_2 -> V_24 ) {
F_4 ( L_2 ) ;
return - V_11 ;
}
V_2 -> V_26 = F_5 ( F_6 ( V_4 ) , V_2 -> V_22 ,
& V_2 -> V_12 , V_27 ,
V_2 -> V_13 ) ;
if ( ! V_2 -> V_26 ) {
F_4 ( L_3 ) ;
goto V_28;
}
V_10 = F_7 ( F_6 ( V_4 ) , & V_9 , V_2 -> V_26 ,
V_2 -> V_12 , V_2 -> V_22 ,
V_2 -> V_13 ) ;
if ( V_10 < 0 ) {
F_4 ( L_4 ) ;
goto V_29;
}
if ( F_8 ( & V_9 , V_2 -> V_24 , NULL ,
V_7 ) ) {
F_4 ( L_5 ) ;
V_10 = - V_30 ;
goto V_31;
}
F_9 ( & V_9 ) ;
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_12 , V_2 -> V_22 ) ;
return 0 ;
V_31:
F_9 ( & V_9 ) ;
V_29:
F_10 ( F_6 ( V_4 ) , V_2 -> V_22 , V_2 -> V_26 ,
V_2 -> V_12 , V_2 -> V_13 ) ;
V_28:
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
F_10 ( F_6 ( V_4 ) , V_2 -> V_22 , V_2 -> V_26 ,
( V_32 ) V_2 -> V_12 ,
V_2 -> V_13 ) ;
F_11 ( V_2 -> V_24 ) ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
int V_10 ;
V_10 = F_14 ( V_36 , V_34 , V_37 ) ;
if ( V_10 )
return V_10 ;
F_2 ( L_8 , * V_37 ) ;
F_15 ( V_34 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_5 ;
F_2 ( L_9 , V_34 -> V_38 ) ;
if ( V_34 -> V_39 )
F_17 ( V_34 , V_2 -> V_9 ) ;
else
F_12 ( V_2 ) ;
F_18 ( V_34 ) ;
F_19 ( V_2 ) ;
}
unsigned long F_20 ( struct V_3 * V_4 ,
unsigned int V_40 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_34 = F_21 ( V_36 , V_40 ) ;
if ( ! V_34 ) {
F_4 ( L_10 ) ;
return 0 ;
}
V_2 = F_22 ( V_34 ) ;
F_15 ( V_34 ) ;
return V_2 -> V_22 ;
}
static struct V_1 * F_23 ( struct V_3 * V_4 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_10 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return F_25 ( - V_11 ) ;
V_2 -> V_22 = V_22 ;
V_34 = & V_2 -> V_5 ;
V_10 = F_26 ( V_4 , V_34 , V_22 ) ;
if ( V_10 < 0 ) {
F_4 ( L_11 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
V_10 = F_27 ( V_34 ) ;
if ( V_10 < 0 ) {
F_18 ( V_34 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
F_2 ( L_12 , V_34 -> V_41 ) ;
return V_2 ;
}
struct V_1 * F_28 ( struct V_3 * V_4 ,
unsigned int V_14 ,
unsigned long V_22 )
{
struct V_1 * V_2 ;
int V_10 ;
if ( V_14 & ~ ( V_42 ) ) {
F_4 ( L_13 , V_14 ) ;
return F_25 ( - V_30 ) ;
}
if ( ! V_22 ) {
F_4 ( L_14 , V_22 ) ;
return F_25 ( - V_30 ) ;
}
V_22 = F_29 ( V_22 , V_43 ) ;
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
int F_31 ( struct V_3 * V_4 , void * V_44 ,
struct V_35 * V_36 )
{
struct V_45 * args = V_44 ;
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_28 ( V_4 , args -> V_14 , args -> V_22 ) ;
if ( F_30 ( V_2 ) )
return F_32 ( V_2 ) ;
V_10 = F_13 ( & V_2 -> V_5 , V_36 ,
& args -> V_37 ) ;
if ( V_10 ) {
F_16 ( V_2 ) ;
return V_10 ;
}
return 0 ;
}
int F_33 ( struct V_3 * V_4 , void * V_44 ,
struct V_35 * V_36 )
{
struct V_46 * args = V_44 ;
return F_34 ( V_36 , V_4 , args -> V_37 ,
& args -> V_47 ) ;
}
V_32 * F_35 ( struct V_3 * V_4 ,
unsigned int V_40 ,
struct V_35 * V_41 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_34 = F_21 ( V_41 , V_40 ) ;
if ( ! V_34 ) {
F_4 ( L_10 ) ;
return F_25 ( - V_30 ) ;
}
V_2 = F_22 ( V_34 ) ;
return & V_2 -> V_12 ;
}
void F_36 ( struct V_3 * V_4 ,
unsigned int V_40 ,
struct V_35 * V_41 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_41 , V_40 ) ;
if ( ! V_34 ) {
F_4 ( L_10 ) ;
return;
}
F_15 ( V_34 ) ;
F_15 ( V_34 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_3 * V_50 = V_2 -> V_5 . V_4 ;
unsigned long V_51 ;
int V_10 ;
V_49 -> V_52 &= ~ V_53 ;
V_49 -> V_54 = 0 ;
V_51 = V_49 -> V_55 - V_49 -> V_56 ;
if ( V_51 > V_2 -> V_22 )
return - V_30 ;
V_10 = F_38 ( F_6 ( V_50 ) , V_49 , V_2 -> V_26 ,
V_2 -> V_12 , V_2 -> V_22 ,
V_2 -> V_13 ) ;
if ( V_10 < 0 ) {
F_4 ( L_15 ) ;
return V_10 ;
}
return 0 ;
}
int F_39 ( struct V_3 * V_4 , void * V_44 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_57 * args = V_44 ;
struct V_33 * V_34 ;
V_34 = F_21 ( V_36 , args -> V_37 ) ;
if ( ! V_34 ) {
F_4 ( L_10 ) ;
return - V_30 ;
}
V_2 = F_22 ( V_34 ) ;
args -> V_14 = V_2 -> V_14 ;
args -> V_22 = V_2 -> V_22 ;
F_15 ( V_34 ) ;
return 0 ;
}
void F_40 ( struct V_33 * V_34 )
{
F_16 ( F_22 ( V_34 ) ) ;
}
int F_41 ( struct V_35 * V_36 ,
struct V_3 * V_4 ,
struct V_58 * args )
{
struct V_1 * V_2 ;
unsigned int V_14 ;
int V_10 ;
args -> V_59 = args -> V_60 * ( ( args -> V_61 + 7 ) / 8 ) ;
args -> V_22 = args -> V_59 * args -> V_62 ;
if ( F_42 ( V_4 ) )
V_14 = V_15 | V_17 ;
else
V_14 = V_63 | V_17 ;
V_2 = F_28 ( V_4 , V_14 , args -> V_22 ) ;
if ( F_30 ( V_2 ) ) {
F_43 ( V_4 -> V_4 , L_16 ) ;
return F_32 ( V_2 ) ;
}
V_10 = F_13 ( & V_2 -> V_5 , V_36 ,
& args -> V_37 ) ;
if ( V_10 ) {
F_16 ( V_2 ) ;
return V_10 ;
}
return 0 ;
}
int F_34 ( struct V_35 * V_36 ,
struct V_3 * V_4 , T_1 V_37 ,
T_2 * V_47 )
{
struct V_33 * V_34 ;
int V_10 = 0 ;
V_34 = F_21 ( V_36 , V_37 ) ;
if ( ! V_34 ) {
F_4 ( L_10 ) ;
return - V_30 ;
}
* V_47 = F_44 ( & V_34 -> V_64 ) ;
F_2 ( L_17 , ( unsigned long ) * V_47 ) ;
F_15 ( V_34 ) ;
return V_10 ;
}
int F_45 ( struct V_65 * V_66 )
{
struct V_48 * V_49 = V_66 -> V_49 ;
struct V_33 * V_34 = V_49 -> V_67 ;
struct V_1 * V_2 = F_22 ( V_34 ) ;
unsigned long V_68 ;
T_3 V_69 ;
int V_10 ;
V_69 = ( V_66 -> V_70 - V_49 -> V_56 ) >> V_23 ;
if ( V_69 >= ( V_2 -> V_22 >> V_23 ) ) {
F_4 ( L_18 ) ;
V_10 = - V_30 ;
goto V_71;
}
V_68 = F_46 ( V_2 -> V_24 [ V_69 ] ) ;
V_10 = F_47 ( V_49 , V_66 -> V_70 , F_48 ( V_68 , V_72 ) ) ;
V_71:
switch ( V_10 ) {
case 0 :
case - V_73 :
case - V_74 :
return V_75 ;
case - V_11 :
return V_76 ;
default:
return V_77 ;
}
}
static int F_49 ( struct V_33 * V_34 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
int V_10 ;
F_2 ( L_19 , V_2 -> V_14 ) ;
if ( V_2 -> V_14 & V_18 )
V_49 -> V_78 = F_50 ( V_49 -> V_52 ) ;
else if ( V_2 -> V_14 & V_17 )
V_49 -> V_78 =
F_51 ( F_50 ( V_49 -> V_52 ) ) ;
else
V_49 -> V_78 =
F_52 ( F_50 ( V_49 -> V_52 ) ) ;
V_10 = F_37 ( V_2 , V_49 ) ;
if ( V_10 )
goto V_79;
return V_10 ;
V_79:
F_53 ( V_49 ) ;
return V_10 ;
}
int F_54 ( struct V_80 * V_41 , struct V_48 * V_49 )
{
struct V_33 * V_34 ;
int V_10 ;
V_10 = F_55 ( V_41 , V_49 ) ;
if ( V_10 < 0 ) {
F_4 ( L_15 ) ;
return V_10 ;
}
V_34 = V_49 -> V_67 ;
if ( V_34 -> V_39 )
return F_56 ( V_34 -> V_81 , V_49 , 0 ) ;
return F_49 ( V_34 , V_49 ) ;
}
struct V_8 * F_57 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
int V_82 ;
V_82 = V_2 -> V_22 >> V_23 ;
return F_58 ( V_2 -> V_24 , V_82 ) ;
}
struct V_33 *
F_59 ( struct V_3 * V_4 ,
struct V_83 * V_84 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_82 ;
int V_10 ;
V_2 = F_23 ( V_4 , V_84 -> V_85 -> V_22 ) ;
if ( F_30 ( V_2 ) ) {
V_10 = F_32 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
V_2 -> V_12 = F_60 ( V_9 -> V_86 ) ;
V_82 = V_2 -> V_22 >> V_23 ;
V_2 -> V_24 = F_61 ( V_82 , sizeof( struct V_25 * ) ) ;
if ( ! V_2 -> V_24 ) {
V_10 = - V_11 ;
goto V_87;
}
V_10 = F_8 ( V_9 , V_2 -> V_24 , NULL ,
V_82 ) ;
if ( V_10 < 0 )
goto V_88;
V_2 -> V_9 = V_9 ;
if ( V_9 -> V_89 == 1 ) {
V_2 -> V_14 |= V_63 ;
} else {
V_2 -> V_14 |= V_15 ;
}
return & V_2 -> V_5 ;
V_88:
F_11 ( V_2 -> V_24 ) ;
V_87:
F_18 ( & V_2 -> V_5 ) ;
F_19 ( V_2 ) ;
return F_25 ( V_10 ) ;
}
void * F_62 ( struct V_33 * V_34 )
{
return NULL ;
}
void F_63 ( struct V_33 * V_34 , void * V_90 )
{
}
int F_64 ( struct V_33 * V_34 ,
struct V_48 * V_49 )
{
int V_10 ;
V_10 = F_65 ( V_34 , V_34 -> V_22 , V_49 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_49 ( V_34 , V_49 ) ;
}
