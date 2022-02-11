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
V_2 -> V_27 = F_7 ( V_4 -> V_4 , V_2 -> V_23 ,
& V_2 -> V_13 , V_28 ,
& V_2 -> V_14 ) ;
if ( ! V_2 -> V_27 ) {
F_6 ( L_3 ) ;
goto V_29;
}
V_11 = F_8 ( V_4 -> V_4 , & V_10 , V_2 -> V_27 ,
V_2 -> V_13 , V_2 -> V_23 ,
& V_2 -> V_14 ) ;
if ( V_11 < 0 ) {
F_6 ( L_4 ) ;
goto V_30;
}
if ( F_9 ( & V_10 , V_2 -> V_25 , NULL ,
V_8 ) ) {
F_6 ( L_5 ) ;
V_11 = - V_31 ;
goto V_32;
}
F_10 ( & V_10 ) ;
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_13 , V_2 -> V_23 ) ;
return 0 ;
V_32:
F_10 ( & V_10 ) ;
V_30:
F_11 ( V_4 -> V_4 , V_2 -> V_23 , V_2 -> V_27 ,
V_2 -> V_13 , & V_2 -> V_14 ) ;
V_29:
F_12 ( V_2 -> V_25 ) ;
return V_11 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
if ( ! V_2 -> V_13 ) {
F_2 ( L_7 ) ;
return;
}
F_2 ( L_6 ,
( unsigned long ) V_2 -> V_13 , V_2 -> V_23 ) ;
F_11 ( V_4 -> V_4 , V_2 -> V_23 , V_2 -> V_27 ,
( V_33 ) V_2 -> V_13 ,
& V_2 -> V_14 ) ;
F_12 ( V_2 -> V_25 ) ;
}
static int F_14 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
unsigned int * V_38 )
{
int V_11 ;
V_11 = F_15 ( V_37 , V_35 , V_38 ) ;
if ( V_11 )
return V_11 ;
F_2 ( L_8 , * V_38 ) ;
F_16 ( V_35 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_5 ;
F_2 ( L_9 , V_35 -> V_39 ) ;
if ( V_35 -> V_40 )
F_18 ( V_35 , V_2 -> V_10 ) ;
else
F_13 ( V_2 ) ;
F_19 ( V_35 ) ;
F_20 ( V_2 ) ;
}
unsigned long F_21 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_22 ( V_4 , V_37 , V_41 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return 0 ;
}
V_2 = F_23 ( V_35 ) ;
F_16 ( V_35 ) ;
return V_2 -> V_23 ;
}
static struct V_1 * F_24 ( struct V_3 * V_4 ,
unsigned long V_23 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_11 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_26 ( - V_12 ) ;
V_2 -> V_23 = V_23 ;
V_35 = & V_2 -> V_5 ;
V_11 = F_27 ( V_4 , V_35 , V_23 ) ;
if ( V_11 < 0 ) {
F_6 ( L_11 ) ;
F_20 ( V_2 ) ;
return F_26 ( V_11 ) ;
}
V_11 = F_28 ( V_35 ) ;
if ( V_11 < 0 ) {
F_19 ( V_35 ) ;
F_20 ( V_2 ) ;
return F_26 ( V_11 ) ;
}
F_2 ( L_12 , ( unsigned int ) V_35 -> V_42 ) ;
return V_2 ;
}
struct V_1 * F_29 ( struct V_3 * V_4 ,
unsigned int V_15 ,
unsigned long V_23 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( V_15 & ~ ( V_43 ) ) {
F_6 ( L_13 ) ;
return F_26 ( - V_31 ) ;
}
if ( ! V_23 ) {
F_6 ( L_14 ) ;
return F_26 ( - V_31 ) ;
}
V_23 = F_30 ( V_23 , V_44 ) ;
V_2 = F_24 ( V_4 , V_23 ) ;
if ( F_31 ( V_2 ) )
return V_2 ;
V_2 -> V_15 = V_15 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_19 ( & V_2 -> V_5 ) ;
F_20 ( V_2 ) ;
return F_26 ( V_11 ) ;
}
return V_2 ;
}
int F_32 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_46 * args = V_45 ;
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_29 ( V_4 , args -> V_15 , args -> V_23 ) ;
if ( F_31 ( V_2 ) )
return F_33 ( V_2 ) ;
V_11 = F_14 ( & V_2 -> V_5 , V_37 ,
& args -> V_38 ) ;
if ( V_11 ) {
F_17 ( V_2 ) ;
return V_11 ;
}
return 0 ;
}
V_33 * F_34 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_42 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
V_35 = F_22 ( V_4 , V_42 , V_41 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return F_26 ( - V_31 ) ;
}
V_2 = F_23 ( V_35 ) ;
return & V_2 -> V_13 ;
}
void F_35 ( struct V_3 * V_4 ,
unsigned int V_41 ,
struct V_36 * V_42 )
{
struct V_34 * V_35 ;
V_35 = F_22 ( V_4 , V_42 , V_41 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
return;
}
F_16 ( V_35 ) ;
F_16 ( V_35 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_3 * V_49 = V_2 -> V_5 . V_4 ;
unsigned long V_50 ;
int V_11 ;
V_48 -> V_51 &= ~ V_52 ;
V_48 -> V_53 = 0 ;
V_50 = V_48 -> V_54 - V_48 -> V_55 ;
if ( V_50 > V_2 -> V_23 )
return - V_31 ;
V_11 = F_37 ( V_49 -> V_4 , V_48 , V_2 -> V_25 ,
V_2 -> V_13 , V_2 -> V_23 ,
& V_2 -> V_14 ) ;
if ( V_11 < 0 ) {
F_6 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
int F_38 ( struct V_3 * V_4 , void * V_45 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_56 * args = V_45 ;
struct V_34 * V_35 ;
F_39 ( & V_4 -> V_57 ) ;
V_35 = F_22 ( V_4 , V_37 , args -> V_38 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
F_40 ( & V_4 -> V_57 ) ;
return - V_31 ;
}
V_2 = F_23 ( V_35 ) ;
args -> V_15 = V_2 -> V_15 ;
args -> V_23 = V_2 -> V_23 ;
F_41 ( V_35 ) ;
F_40 ( & V_4 -> V_57 ) ;
return 0 ;
}
int F_42 ( struct V_3 * V_49 ,
struct V_9 * V_10 ,
enum V_58 V_59 )
{
int V_60 ;
F_39 ( & V_49 -> V_57 ) ;
V_60 = F_43 ( V_49 -> V_4 , V_10 -> V_61 , V_10 -> V_60 , V_59 ) ;
if ( ! V_60 ) {
F_6 ( L_16 ) ;
F_40 ( & V_49 -> V_57 ) ;
return V_60 ;
}
F_40 ( & V_49 -> V_57 ) ;
return 0 ;
}
void F_44 ( struct V_3 * V_49 ,
struct V_9 * V_10 ,
enum V_58 V_59 )
{
F_45 ( V_49 -> V_4 , V_10 -> V_61 , V_10 -> V_60 , V_59 ) ;
}
void F_46 ( struct V_34 * V_35 )
{
F_17 ( F_23 ( V_35 ) ) ;
}
int F_47 ( struct V_36 * V_37 ,
struct V_3 * V_4 ,
struct V_62 * args )
{
struct V_1 * V_2 ;
unsigned int V_15 ;
int V_11 ;
args -> V_63 = args -> V_64 * ( ( args -> V_65 + 7 ) / 8 ) ;
args -> V_23 = args -> V_63 * args -> V_66 ;
if ( F_48 ( V_4 ) )
V_15 = V_16 | V_18 ;
else
V_15 = V_67 | V_18 ;
V_2 = F_29 ( V_4 , V_15 , args -> V_23 ) ;
if ( F_31 ( V_2 ) ) {
F_49 ( V_4 -> V_4 , L_17 ) ;
return F_33 ( V_2 ) ;
}
V_11 = F_14 ( & V_2 -> V_5 , V_37 ,
& args -> V_38 ) ;
if ( V_11 ) {
F_17 ( V_2 ) ;
return V_11 ;
}
return 0 ;
}
int F_50 ( struct V_36 * V_37 ,
struct V_3 * V_4 , T_1 V_38 ,
T_2 * V_68 )
{
struct V_34 * V_35 ;
int V_11 = 0 ;
F_39 ( & V_4 -> V_57 ) ;
V_35 = F_22 ( V_4 , V_37 , V_38 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
V_11 = - V_31 ;
goto V_69;
}
* V_68 = F_51 ( & V_35 -> V_70 ) ;
F_2 ( L_18 , ( unsigned long ) * V_68 ) ;
F_41 ( V_35 ) ;
V_69:
F_40 ( & V_4 -> V_57 ) ;
return V_11 ;
}
int F_52 ( struct V_47 * V_48 , struct V_71 * V_72 )
{
struct V_34 * V_35 = V_48 -> V_73 ;
struct V_1 * V_2 = F_23 ( V_35 ) ;
unsigned long V_74 ;
T_3 V_75 ;
int V_11 ;
V_75 = ( ( unsigned long ) V_72 -> V_76 -
V_48 -> V_55 ) >> V_24 ;
if ( V_75 >= ( V_2 -> V_23 >> V_24 ) ) {
F_6 ( L_19 ) ;
V_11 = - V_31 ;
goto V_77;
}
V_74 = F_53 ( V_2 -> V_25 [ V_75 ] ) ;
V_11 = F_54 ( V_48 , ( unsigned long ) V_72 -> V_76 , V_74 ) ;
V_77:
switch ( V_11 ) {
case 0 :
case - V_78 :
case - V_79 :
return V_80 ;
case - V_12 :
return V_81 ;
default:
return V_82 ;
}
}
int F_55 ( struct V_83 * V_42 , struct V_47 * V_48 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_11 ;
V_11 = F_56 ( V_42 , V_48 ) ;
if ( V_11 < 0 ) {
F_6 ( L_15 ) ;
return V_11 ;
}
V_35 = V_48 -> V_73 ;
V_2 = F_23 ( V_35 ) ;
F_2 ( L_20 , V_2 -> V_15 ) ;
if ( V_2 -> V_15 & V_19 )
V_48 -> V_84 = F_57 ( V_48 -> V_51 ) ;
else if ( V_2 -> V_15 & V_18 )
V_48 -> V_84 =
F_58 ( F_57 ( V_48 -> V_51 ) ) ;
else
V_48 -> V_84 =
F_59 ( F_57 ( V_48 -> V_51 ) ) ;
V_11 = F_36 ( V_2 , V_48 ) ;
if ( V_11 )
goto V_85;
return V_11 ;
V_85:
F_60 ( V_48 ) ;
return V_11 ;
}
struct V_9 * F_61 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_23 ( V_35 ) ;
int V_86 ;
V_86 = V_2 -> V_23 >> V_24 ;
return F_62 ( V_2 -> V_25 , V_86 ) ;
}
struct V_34 *
F_63 ( struct V_3 * V_4 ,
struct V_87 * V_88 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_86 ;
int V_11 ;
V_2 = F_24 ( V_4 , V_88 -> V_89 -> V_23 ) ;
if ( F_31 ( V_2 ) ) {
V_11 = F_33 ( V_2 ) ;
return F_26 ( V_11 ) ;
}
V_2 -> V_13 = F_64 ( V_10 -> V_61 ) ;
V_86 = V_2 -> V_23 >> V_24 ;
V_2 -> V_25 = F_65 ( V_86 , sizeof( struct V_26 * ) ) ;
if ( ! V_2 -> V_25 ) {
V_11 = - V_12 ;
goto V_90;
}
V_11 = F_9 ( V_10 , V_2 -> V_25 , NULL ,
V_86 ) ;
if ( V_11 < 0 )
goto V_91;
V_2 -> V_10 = V_10 ;
if ( V_10 -> V_60 == 1 ) {
V_2 -> V_15 |= V_67 ;
} else {
V_2 -> V_15 |= V_16 ;
}
return & V_2 -> V_5 ;
V_91:
F_12 ( V_2 -> V_25 ) ;
V_90:
F_19 ( & V_2 -> V_5 ) ;
F_20 ( V_2 ) ;
return F_26 ( V_11 ) ;
}
void * F_66 ( struct V_34 * V_35 )
{
return NULL ;
}
void F_67 ( struct V_34 * V_35 , void * V_92 )
{
}
