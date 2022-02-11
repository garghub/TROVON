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
static unsigned int F_2 ( struct V_9 * V_10 )
{
F_3 ( L_1 , __FILE__ ) ;
return ( unsigned int ) V_10 -> V_11 . V_12 . V_13 << V_14 ;
}
static struct V_15
* F_4 ( struct V_16 * V_17 ,
struct V_18 * V_19 , unsigned int * V_20 ,
unsigned int V_21 )
{
struct V_15 * V_22 ;
struct V_9 * V_10 ;
int V_23 ;
V_22 = F_5 ( sizeof( * V_22 ) , V_24 ) ;
if ( ! V_22 ) {
F_6 ( L_2 ) ;
return F_7 ( - V_6 ) ;
}
V_10 = & V_22 -> V_25 ;
V_23 = F_8 ( V_17 , V_10 , V_21 ) ;
if ( V_23 < 0 ) {
F_6 ( L_3 ) ;
V_23 = - V_26 ;
goto V_27;
}
F_3 ( L_4 , ( unsigned int ) V_10 -> V_28 ) ;
V_23 = F_9 ( V_10 ) ;
if ( V_23 < 0 ) {
F_6 ( L_5 ) ;
goto V_29;
}
V_23 = F_10 ( V_19 , V_10 , V_20 ) ;
if ( V_23 )
goto V_30;
F_3 ( L_6 , * V_20 ) ;
F_11 ( V_10 ) ;
return V_22 ;
V_30:
F_12 ( V_10 ) ;
V_29:
F_13 ( V_10 ) ;
V_27:
F_14 ( V_22 ) ;
return F_7 ( V_23 ) ;
}
struct V_15 * F_15 ( struct V_16 * V_31 ,
struct V_18 * V_19 ,
unsigned int * V_20 , unsigned long V_21 )
{
struct V_15 * V_22 = NULL ;
struct V_32 * V_33 ;
V_21 = F_16 ( V_21 , V_34 ) ;
F_3 ( L_7 , __FILE__ , V_21 ) ;
V_33 = F_17 ( V_31 , V_21 ) ;
if ( F_18 ( V_33 ) ) {
return F_19 ( V_33 ) ;
}
V_22 = F_4 ( V_31 , V_19 , V_20 , V_21 ) ;
if ( F_18 ( V_22 ) ) {
F_20 ( V_31 , V_33 ) ;
return V_22 ;
}
V_22 -> V_33 = V_33 ;
return V_22 ;
}
int F_21 ( struct V_16 * V_31 , void * V_35 ,
struct V_18 * V_19 )
{
struct V_36 * args = V_35 ;
struct V_15 * V_22 = NULL ;
F_3 ( L_1 , __FILE__ ) ;
V_22 = F_15 ( V_31 , V_19 ,
& args -> V_20 , args -> V_21 ) ;
if ( F_18 ( V_22 ) )
return F_22 ( V_22 ) ;
return 0 ;
}
int F_23 ( struct V_16 * V_31 , void * V_35 ,
struct V_18 * V_19 )
{
struct V_37 * args = V_35 ;
F_3 ( L_1 , __FILE__ ) ;
F_3 ( L_8 ,
args -> V_20 , ( unsigned long ) args -> V_38 ) ;
if ( ! ( V_31 -> V_39 -> V_40 & V_41 ) ) {
F_6 ( L_9 ) ;
return - V_42 ;
}
return F_24 ( V_19 , V_31 , args -> V_20 ,
& args -> V_38 ) ;
}
static int F_25 ( struct V_43 * V_28 ,
struct V_44 * V_45 )
{
struct V_9 * V_10 = V_28 -> V_46 ;
struct V_15 * V_22 = F_26 ( V_10 ) ;
struct V_32 * V_33 ;
unsigned long V_47 , V_48 ;
F_3 ( L_1 , __FILE__ ) ;
V_45 -> V_49 |= ( V_50 | V_51 ) ;
V_45 -> V_52 = F_27 ( V_45 -> V_52 ) ;
V_45 -> V_53 = V_28 ;
V_48 = V_45 -> V_54 - V_45 -> V_55 ;
V_33 = V_22 -> V_33 ;
if ( V_48 > V_33 -> V_21 )
return - V_26 ;
V_47 = ( ( unsigned long ) V_22 -> V_33 -> V_56 ) >> V_14 ;
F_3 ( L_10 , V_47 ) ;
if ( F_28 ( V_45 , V_45 -> V_55 , V_47 , V_48 ,
V_45 -> V_52 ) ) {
F_6 ( L_11 ) ;
return - V_57 ;
}
return 0 ;
}
int F_29 ( struct V_16 * V_31 , void * V_35 ,
struct V_18 * V_19 )
{
struct V_58 * args = V_35 ;
struct V_9 * V_10 ;
unsigned int V_59 ;
F_3 ( L_1 , __FILE__ ) ;
if ( ! ( V_31 -> V_39 -> V_40 & V_41 ) ) {
F_6 ( L_9 ) ;
return - V_42 ;
}
V_10 = F_30 ( V_31 , V_19 , args -> V_20 ) ;
if ( ! V_10 ) {
F_6 ( L_12 ) ;
return - V_26 ;
}
V_10 -> V_28 -> V_60 = & V_61 ;
V_10 -> V_28 -> V_46 = V_10 ;
F_31 ( & V_62 -> V_63 -> V_64 ) ;
V_59 = F_32 ( V_10 -> V_28 , 0 , args -> V_21 ,
V_65 | V_66 , V_67 , 0 ) ;
F_33 ( & V_62 -> V_63 -> V_64 ) ;
F_11 ( V_10 ) ;
if ( F_18 ( ( void * ) V_59 ) )
return F_22 ( ( void * ) V_59 ) ;
args -> V_68 = V_59 ;
F_3 ( L_13 , ( unsigned long ) args -> V_68 ) ;
return 0 ;
}
int F_34 ( struct V_9 * V_10 )
{
F_3 ( L_1 , __FILE__ ) ;
return 0 ;
}
void F_35 ( struct V_9 * V_69 )
{
struct V_15 * V_22 ;
F_3 ( L_1 , __FILE__ ) ;
F_3 ( L_14 ,
F_36 ( & V_69 -> V_70 ) ) ;
if ( V_69 -> V_11 . V_71 )
F_12 ( V_69 ) ;
F_13 ( V_69 ) ;
V_22 = F_26 ( V_69 ) ;
F_20 ( V_69 -> V_31 , V_22 -> V_33 ) ;
F_14 ( V_22 ) ;
}
int F_37 ( struct V_18 * V_19 ,
struct V_16 * V_31 , struct V_72 * args )
{
struct V_15 * V_22 ;
F_3 ( L_1 , __FILE__ ) ;
args -> V_73 = args -> V_74 * args -> V_75 >> 3 ;
args -> V_21 = args -> V_73 * args -> V_76 ;
V_22 = F_15 ( V_31 , V_19 , & args -> V_20 ,
args -> V_21 ) ;
if ( F_18 ( V_22 ) )
return F_22 ( V_22 ) ;
return 0 ;
}
int F_24 ( struct V_18 * V_19 ,
struct V_16 * V_31 , T_1 V_20 , T_2 * V_38 )
{
struct V_15 * V_22 ;
struct V_9 * V_10 ;
F_3 ( L_1 , __FILE__ ) ;
F_38 ( & V_31 -> V_77 ) ;
V_10 = F_30 ( V_31 , V_19 , V_20 ) ;
if ( ! V_10 ) {
F_6 ( L_12 ) ;
F_39 ( & V_31 -> V_77 ) ;
return - V_26 ;
}
V_22 = F_26 ( V_10 ) ;
* V_38 = F_2 ( & V_22 -> V_25 ) ;
F_40 ( V_10 ) ;
F_3 ( L_15 , ( unsigned long ) * V_38 ) ;
F_39 ( & V_31 -> V_77 ) ;
return 0 ;
}
int F_41 ( struct V_44 * V_45 , struct V_78 * V_79 )
{
struct V_9 * V_10 = V_45 -> V_80 ;
struct V_15 * V_22 = F_26 ( V_10 ) ;
struct V_16 * V_31 = V_10 -> V_31 ;
unsigned long V_47 ;
T_3 V_81 ;
int V_23 ;
V_81 = ( ( unsigned long ) V_79 -> V_82 -
V_45 -> V_55 ) >> V_14 ;
F_38 ( & V_31 -> V_77 ) ;
V_47 = ( ( ( unsigned long ) V_22 -> V_33 -> V_56 ) >>
V_14 ) + V_81 ;
V_23 = F_42 ( V_45 , ( unsigned long ) V_79 -> V_82 , V_47 ) ;
F_39 ( & V_31 -> V_77 ) ;
return F_1 ( V_23 ) ;
}
int F_43 ( struct V_43 * V_28 , struct V_44 * V_45 )
{
int V_23 ;
F_3 ( L_1 , __FILE__ ) ;
V_23 = F_44 ( V_28 , V_45 ) ;
if ( V_23 < 0 ) {
F_6 ( L_16 ) ;
return V_23 ;
}
V_45 -> V_49 &= ~ V_83 ;
V_45 -> V_49 |= V_84 ;
return V_23 ;
}
int F_45 ( struct V_18 * V_19 ,
struct V_16 * V_31 , unsigned int V_20 )
{
int V_23 ;
F_3 ( L_1 , __FILE__ ) ;
V_23 = F_46 ( V_19 , V_20 ) ;
if ( V_23 < 0 ) {
F_6 ( L_17 ) ;
return V_23 ;
}
return 0 ;
}
