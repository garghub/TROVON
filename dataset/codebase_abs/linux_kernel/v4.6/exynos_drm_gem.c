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
V_35 = F_23 ( V_4 , V_37 , V_41 ) ;
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
V_35 = F_23 ( V_4 , V_42 , V_41 ) ;
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
V_35 = F_23 ( V_4 , V_42 , V_41 ) ;
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
F_42 ( & V_4 -> V_59 ) ;
V_35 = F_23 ( V_4 , V_37 , args -> V_38 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
F_43 ( & V_4 -> V_59 ) ;
return - V_31 ;
}
V_2 = F_24 ( V_35 ) ;
args -> V_15 = V_2 -> V_15 ;
args -> V_23 = V_2 -> V_23 ;
F_44 ( V_35 ) ;
F_43 ( & V_4 -> V_59 ) ;
return 0 ;
}
int F_45 ( struct V_3 * V_51 ,
struct V_9 * V_10 ,
enum V_60 V_61 )
{
int V_62 ;
F_42 ( & V_51 -> V_59 ) ;
V_62 = F_46 ( F_8 ( V_51 ) , V_10 -> V_63 , V_10 -> V_62 , V_61 ) ;
if ( ! V_62 ) {
F_6 ( L_16 ) ;
F_43 ( & V_51 -> V_59 ) ;
return V_62 ;
}
F_43 ( & V_51 -> V_59 ) ;
return 0 ;
}
void F_47 ( struct V_3 * V_51 ,
struct V_9 * V_10 ,
enum V_60 V_61 )
{
F_48 ( F_8 ( V_51 ) , V_10 -> V_63 , V_10 -> V_62 , V_61 ) ;
}
void F_49 ( struct V_34 * V_35 )
{
F_18 ( F_24 ( V_35 ) ) ;
}
int F_50 ( struct V_36 * V_37 ,
struct V_3 * V_4 ,
struct V_64 * args )
{
struct V_1 * V_2 ;
unsigned int V_15 ;
int V_11 ;
args -> V_65 = args -> V_66 * ( ( args -> V_67 + 7 ) / 8 ) ;
args -> V_23 = args -> V_65 * args -> V_68 ;
if ( F_51 ( V_4 ) )
V_15 = V_16 | V_18 ;
else
V_15 = V_69 | V_18 ;
V_2 = F_30 ( V_4 , V_15 , args -> V_23 ) ;
if ( F_32 ( V_2 ) ) {
F_52 ( V_4 -> V_4 , L_17 ) ;
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
F_42 ( & V_4 -> V_59 ) ;
V_35 = F_23 ( V_4 , V_37 , V_38 ) ;
if ( ! V_35 ) {
F_6 ( L_10 ) ;
V_11 = - V_31 ;
goto V_70;
}
* V_48 = F_53 ( & V_35 -> V_71 ) ;
F_2 ( L_18 , ( unsigned long ) * V_48 ) ;
F_44 ( V_35 ) ;
V_70:
F_43 ( & V_4 -> V_59 ) ;
return V_11 ;
}
int F_54 ( struct V_49 * V_50 , struct V_72 * V_73 )
{
struct V_34 * V_35 = V_50 -> V_74 ;
struct V_1 * V_2 = F_24 ( V_35 ) ;
unsigned long V_75 ;
T_3 V_76 ;
int V_11 ;
V_76 = ( ( unsigned long ) V_73 -> V_77 -
V_50 -> V_57 ) >> V_24 ;
if ( V_76 >= ( V_2 -> V_23 >> V_24 ) ) {
F_6 ( L_19 ) ;
V_11 = - V_31 ;
goto V_78;
}
V_75 = F_55 ( V_2 -> V_25 [ V_76 ] ) ;
V_11 = F_56 ( V_50 , ( unsigned long ) V_73 -> V_77 ,
F_57 ( V_75 , V_79 ) ) ;
V_78:
switch ( V_11 ) {
case 0 :
case - V_80 :
case - V_81 :
return V_82 ;
case - V_12 :
return V_83 ;
default:
return V_84 ;
}
}
int F_58 ( struct V_85 * V_42 , struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_11 ;
V_11 = F_59 ( V_42 , V_50 ) ;
if ( V_11 < 0 ) {
F_6 ( L_15 ) ;
return V_11 ;
}
V_35 = V_50 -> V_74 ;
V_2 = F_24 ( V_35 ) ;
F_2 ( L_20 , V_2 -> V_15 ) ;
if ( V_2 -> V_15 & V_19 )
V_50 -> V_86 = F_60 ( V_50 -> V_53 ) ;
else if ( V_2 -> V_15 & V_18 )
V_50 -> V_86 =
F_61 ( F_60 ( V_50 -> V_53 ) ) ;
else
V_50 -> V_86 =
F_62 ( F_60 ( V_50 -> V_53 ) ) ;
V_11 = F_39 ( V_2 , V_50 ) ;
if ( V_11 )
goto V_87;
return V_11 ;
V_87:
F_63 ( V_50 ) ;
return V_11 ;
}
struct V_9 * F_64 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_24 ( V_35 ) ;
int V_88 ;
V_88 = V_2 -> V_23 >> V_24 ;
return F_65 ( V_2 -> V_25 , V_88 ) ;
}
struct V_34 *
F_66 ( struct V_3 * V_4 ,
struct V_89 * V_90 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_88 ;
int V_11 ;
V_2 = F_25 ( V_4 , V_90 -> V_91 -> V_23 ) ;
if ( F_32 ( V_2 ) ) {
V_11 = F_34 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
V_2 -> V_13 = F_67 ( V_10 -> V_63 ) ;
V_88 = V_2 -> V_23 >> V_24 ;
V_2 -> V_25 = F_68 ( V_88 , sizeof( struct V_26 * ) ) ;
if ( ! V_2 -> V_25 ) {
V_11 = - V_12 ;
goto V_92;
}
V_11 = F_10 ( V_10 , V_2 -> V_25 , NULL ,
V_88 ) ;
if ( V_11 < 0 )
goto V_93;
V_2 -> V_10 = V_10 ;
if ( V_10 -> V_62 == 1 ) {
V_2 -> V_15 |= V_69 ;
} else {
V_2 -> V_15 |= V_16 ;
}
return & V_2 -> V_5 ;
V_93:
F_13 ( V_2 -> V_25 ) ;
V_92:
F_20 ( & V_2 -> V_5 ) ;
F_21 ( V_2 ) ;
return F_27 ( V_11 ) ;
}
void * F_69 ( struct V_34 * V_35 )
{
return NULL ;
}
void F_70 ( struct V_34 * V_35 , void * V_94 )
{
}
