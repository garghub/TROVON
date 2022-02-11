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
static int F_2 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
int V_14 ;
V_14 = F_3 ( V_12 , V_10 , V_13 ) ;
if ( V_14 )
return V_14 ;
F_4 ( L_1 , * V_13 ) ;
F_5 ( V_10 ) ;
return 0 ;
}
void F_6 ( struct V_15 * V_16 )
{
struct V_9 * V_10 ;
F_4 ( L_2 , __FILE__ ) ;
if ( ! V_16 )
return;
V_10 = & V_16 -> V_17 ;
F_4 ( L_3 , F_7 ( & V_10 -> V_18 ) ) ;
F_8 ( V_10 -> V_19 , V_16 -> V_20 ) ;
if ( V_10 -> V_21 . V_22 )
F_9 ( V_10 ) ;
F_10 ( V_10 ) ;
F_11 ( V_16 ) ;
}
static struct V_15 * F_12 ( struct V_23 * V_19 ,
unsigned long V_24 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_14 ;
V_16 = F_13 ( sizeof( * V_16 ) , V_25 ) ;
if ( ! V_16 ) {
F_14 ( L_4 ) ;
return NULL ;
}
V_10 = & V_16 -> V_17 ;
V_14 = F_15 ( V_19 , V_10 , V_24 ) ;
if ( V_14 < 0 ) {
F_14 ( L_5 ) ;
F_11 ( V_16 ) ;
return NULL ;
}
F_4 ( L_6 , ( unsigned int ) V_10 -> V_26 ) ;
return V_16 ;
}
struct V_15 * F_16 ( struct V_23 * V_19 ,
unsigned long V_24 )
{
struct V_27 * V_20 ;
struct V_15 * V_16 ;
V_24 = F_17 ( V_24 , V_28 ) ;
F_4 ( L_7 , __FILE__ , V_24 ) ;
V_20 = F_18 ( V_19 , V_24 ) ;
if ( ! V_20 )
return F_19 ( - V_6 ) ;
V_16 = F_12 ( V_19 , V_24 ) ;
if ( ! V_16 ) {
F_8 ( V_19 , V_20 ) ;
return F_19 ( - V_6 ) ;
}
V_16 -> V_20 = V_20 ;
return V_16 ;
}
int F_20 ( struct V_23 * V_19 , void * V_29 ,
struct V_11 * V_12 )
{
struct V_30 * args = V_29 ;
struct V_15 * V_16 ;
int V_14 ;
F_4 ( L_2 , __FILE__ ) ;
V_16 = F_16 ( V_19 , args -> V_24 ) ;
if ( F_21 ( V_16 ) )
return F_22 ( V_16 ) ;
V_14 = F_2 ( & V_16 -> V_17 , V_12 ,
& args -> V_13 ) ;
if ( V_14 ) {
F_6 ( V_16 ) ;
return V_14 ;
}
return 0 ;
}
int F_23 ( struct V_23 * V_19 , void * V_29 ,
struct V_11 * V_12 )
{
struct V_31 * args = V_29 ;
F_4 ( L_2 , __FILE__ ) ;
F_4 ( L_8 ,
args -> V_13 , ( unsigned long ) args -> V_32 ) ;
if ( ! ( V_19 -> V_33 -> V_34 & V_35 ) ) {
F_14 ( L_9 ) ;
return - V_36 ;
}
return F_24 ( V_12 , V_19 , args -> V_13 ,
& args -> V_32 ) ;
}
static int F_25 ( struct V_37 * V_26 ,
struct V_38 * V_39 )
{
struct V_9 * V_10 = V_26 -> V_40 ;
struct V_15 * V_16 = F_26 ( V_10 ) ;
struct V_27 * V_20 ;
unsigned long V_41 , V_42 ;
F_4 ( L_2 , __FILE__ ) ;
V_39 -> V_43 |= ( V_44 | V_45 ) ;
V_39 -> V_46 = F_27 ( V_39 -> V_46 ) ;
V_39 -> V_47 = V_26 ;
V_42 = V_39 -> V_48 - V_39 -> V_49 ;
V_20 = V_16 -> V_20 ;
if ( V_42 > V_20 -> V_24 )
return - V_50 ;
V_41 = ( ( unsigned long ) V_16 -> V_20 -> V_51 ) >> V_52 ;
F_4 ( L_10 , V_41 ) ;
if ( F_28 ( V_39 , V_39 -> V_49 , V_41 , V_42 ,
V_39 -> V_46 ) ) {
F_14 ( L_11 ) ;
return - V_53 ;
}
return 0 ;
}
int F_29 ( struct V_23 * V_19 , void * V_29 ,
struct V_11 * V_12 )
{
struct V_54 * args = V_29 ;
struct V_9 * V_10 ;
unsigned int V_55 ;
F_4 ( L_2 , __FILE__ ) ;
if ( ! ( V_19 -> V_33 -> V_34 & V_35 ) ) {
F_14 ( L_9 ) ;
return - V_36 ;
}
V_10 = F_30 ( V_19 , V_12 , args -> V_13 ) ;
if ( ! V_10 ) {
F_14 ( L_12 ) ;
return - V_50 ;
}
V_10 -> V_26 -> V_56 = & V_57 ;
V_10 -> V_26 -> V_40 = V_10 ;
F_31 ( & V_58 -> V_59 -> V_60 ) ;
V_55 = F_32 ( V_10 -> V_26 , 0 , args -> V_24 ,
V_61 | V_62 , V_63 , 0 ) ;
F_33 ( & V_58 -> V_59 -> V_60 ) ;
F_5 ( V_10 ) ;
if ( F_21 ( ( void * ) V_55 ) )
return F_22 ( ( void * ) V_55 ) ;
args -> V_64 = V_55 ;
F_4 ( L_13 , ( unsigned long ) args -> V_64 ) ;
return 0 ;
}
int F_34 ( struct V_9 * V_10 )
{
F_4 ( L_2 , __FILE__ ) ;
return 0 ;
}
void F_35 ( struct V_9 * V_10 )
{
F_4 ( L_2 , __FILE__ ) ;
F_6 ( F_26 ( V_10 ) ) ;
}
int F_36 ( struct V_11 * V_12 ,
struct V_23 * V_19 ,
struct V_65 * args )
{
struct V_15 * V_16 ;
int V_14 ;
F_4 ( L_2 , __FILE__ ) ;
args -> V_66 = args -> V_67 * args -> V_68 >> 3 ;
args -> V_24 = args -> V_66 * args -> V_69 ;
V_16 = F_16 ( V_19 , args -> V_24 ) ;
if ( F_21 ( V_16 ) )
return F_22 ( V_16 ) ;
V_14 = F_2 ( & V_16 -> V_17 , V_12 ,
& args -> V_13 ) ;
if ( V_14 ) {
F_6 ( V_16 ) ;
return V_14 ;
}
return 0 ;
}
int F_24 ( struct V_11 * V_12 ,
struct V_23 * V_19 , T_1 V_13 ,
T_2 * V_32 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_14 = 0 ;
F_4 ( L_2 , __FILE__ ) ;
F_37 ( & V_19 -> V_70 ) ;
V_10 = F_30 ( V_19 , V_12 , V_13 ) ;
if ( ! V_10 ) {
F_14 ( L_12 ) ;
V_14 = - V_50 ;
goto V_71;
}
V_16 = F_26 ( V_10 ) ;
if ( ! V_16 -> V_17 . V_21 . V_22 ) {
V_14 = F_38 ( & V_16 -> V_17 ) ;
if ( V_14 )
goto V_72;
}
* V_32 = ( V_73 ) V_16 -> V_17 . V_21 . V_74 . V_75 << V_52 ;
F_4 ( L_14 , ( unsigned long ) * V_32 ) ;
V_72:
F_39 ( V_10 ) ;
V_71:
F_40 ( & V_19 -> V_70 ) ;
return V_14 ;
}
int F_41 ( struct V_11 * V_12 ,
struct V_23 * V_19 ,
unsigned int V_13 )
{
int V_14 ;
F_4 ( L_2 , __FILE__ ) ;
V_14 = F_42 ( V_12 , V_13 ) ;
if ( V_14 < 0 ) {
F_14 ( L_15 ) ;
return V_14 ;
}
return 0 ;
}
int F_43 ( struct V_38 * V_39 , struct V_76 * V_77 )
{
struct V_9 * V_10 = V_39 -> V_78 ;
struct V_15 * V_16 = F_26 ( V_10 ) ;
struct V_23 * V_19 = V_10 -> V_19 ;
unsigned long V_41 ;
T_3 V_79 ;
int V_14 ;
V_79 = ( ( unsigned long ) V_77 -> V_80 -
V_39 -> V_49 ) >> V_52 ;
F_37 ( & V_19 -> V_70 ) ;
V_41 = ( ( ( unsigned long ) V_16 -> V_20 -> V_51 ) >>
V_52 ) + V_79 ;
V_14 = F_44 ( V_39 , ( unsigned long ) V_77 -> V_80 , V_41 ) ;
F_40 ( & V_19 -> V_70 ) ;
return F_1 ( V_14 ) ;
}
int F_45 ( struct V_37 * V_26 , struct V_38 * V_39 )
{
int V_14 ;
F_4 ( L_2 , __FILE__ ) ;
V_14 = F_46 ( V_26 , V_39 ) ;
if ( V_14 < 0 ) {
F_14 ( L_16 ) ;
return V_14 ;
}
V_39 -> V_43 &= ~ V_81 ;
V_39 -> V_43 |= V_82 ;
return V_14 ;
}
