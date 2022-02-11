static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_2 ( F_3 ( V_3 ) ) ) {
F_4 ( L_1 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
F_6 ( ! F_7 ( & V_7 ) ,
L_2 ) ;
F_8 (tmp_devfreq, &devfreq_list, node) {
if ( V_4 -> V_3 . V_8 == V_3 )
return V_4 ;
}
return F_5 ( - V_9 ) ;
}
int F_9 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
int V_11 = 0 ;
T_1 V_12 = 0 ;
if ( ! F_7 ( & V_1 -> V_13 ) ) {
F_6 ( true , L_3 ) ;
return - V_6 ;
}
V_11 = V_1 -> V_14 -> V_15 ( V_1 , & V_10 ) ;
if ( V_11 )
return V_11 ;
if ( V_1 -> V_16 && V_10 < V_1 -> V_16 ) {
V_10 = V_1 -> V_16 ;
V_12 &= ~ V_17 ;
}
if ( V_1 -> V_18 && V_10 > V_1 -> V_18 ) {
V_10 = V_1 -> V_18 ;
V_12 |= V_17 ;
}
V_11 = V_1 -> V_19 -> V_20 ( V_1 -> V_3 . V_8 , & V_10 , V_12 ) ;
if ( V_11 )
return V_11 ;
V_1 -> V_21 = V_10 ;
return V_11 ;
}
static int F_10 ( struct V_22 * V_23 , unsigned long type ,
void * V_24 )
{
struct V_1 * V_1 = F_11 ( V_23 , struct V_1 , V_23 ) ;
int V_25 ;
F_12 ( & V_1 -> V_13 ) ;
V_25 = F_9 ( V_1 ) ;
F_13 ( & V_1 -> V_13 ) ;
return V_25 ;
}
static void F_14 ( struct V_1 * V_1 , bool V_26 )
{
if ( ! F_7 ( & V_1 -> V_13 ) ) {
F_6 ( true , L_3 ) ;
return;
}
if ( ! V_1 -> V_14 -> V_27 &&
! F_7 ( & V_7 ) ) {
F_6 ( true , L_4 ) ;
return;
}
if ( V_1 -> V_28 )
return;
V_1 -> V_28 = true ;
if ( V_1 -> V_19 -> exit )
V_1 -> V_19 -> exit ( V_1 -> V_3 . V_8 ) ;
if ( V_1 -> V_14 -> exit )
V_1 -> V_14 -> exit ( V_1 ) ;
if ( ! V_26 && F_15 ( & V_1 -> V_3 ) ) {
F_16 ( & V_1 -> V_3 ) ;
F_17 ( & V_1 -> V_3 ) ;
}
if ( ! V_1 -> V_14 -> V_27 )
F_18 ( & V_1 -> V_29 ) ;
F_13 ( & V_1 -> V_13 ) ;
F_19 ( & V_1 -> V_13 ) ;
F_20 ( V_1 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
bool V_30 = ! V_1 -> V_14 -> V_27 ;
if ( V_1 -> V_28 )
return;
if ( V_30 )
F_12 ( & V_7 ) ;
F_12 ( & V_1 -> V_13 ) ;
if ( V_1 -> V_28 ) {
F_13 ( & V_1 -> V_13 ) ;
goto V_31;
}
F_14 ( V_1 , true ) ;
V_31:
if ( V_30 )
F_13 ( & V_7 ) ;
}
static void F_23 ( struct V_32 * V_33 )
{
static unsigned long V_34 ;
struct V_1 * V_1 , * V_35 ;
int error ;
unsigned long V_36 ;
unsigned long V_37 = V_38 , V_39 = V_40 ;
struct V_2 * V_3 ;
V_36 = V_39 - V_34 ;
V_34 = V_39 ;
if ( V_36 == 0 )
V_36 = 1 ;
F_12 ( & V_7 ) ;
F_24 (devfreq, tmp, &devfreq_list, node) {
F_12 ( & V_1 -> V_13 ) ;
V_3 = V_1 -> V_3 . V_8 ;
V_41 = V_35 ;
if ( V_1 -> V_14 -> V_27 ||
V_1 -> V_42 == 0 ) {
F_13 ( & V_1 -> V_13 ) ;
continue;
}
F_13 ( & V_7 ) ;
if ( V_1 -> V_42 <= V_36 ) {
error = F_9 ( V_1 ) ;
if ( error && error != - V_43 ) {
F_25 ( V_3 , L_5 ,
error , V_1 -> V_14 -> V_44 ) ;
F_13 ( & V_1 -> V_13 ) ;
F_12 ( & V_7 ) ;
if ( F_26 ( F_1 ( V_3 ) ) )
continue;
F_12 ( & V_1 -> V_13 ) ;
F_14 ( V_1 , false ) ;
continue;
}
V_1 -> V_42 = V_1 -> V_45 ;
} else {
V_1 -> V_42 -= V_36 ;
}
if ( V_1 -> V_42 )
V_37 = ( V_37 > V_1 -> V_42 ) ?
V_1 -> V_42 : V_37 ;
F_13 ( & V_1 -> V_13 ) ;
F_12 ( & V_7 ) ;
}
V_41 = NULL ;
F_13 ( & V_7 ) ;
if ( V_37 > 0 && V_37 < V_38 ) {
V_46 = true ;
F_27 ( V_47 , & V_48 , V_37 ) ;
} else {
V_46 = false ;
}
}
struct V_1 * F_28 ( struct V_2 * V_3 ,
struct V_49 * V_19 ,
const struct V_50 * V_14 ,
void * V_51 )
{
struct V_1 * V_1 ;
int V_11 = 0 ;
if ( ! V_3 || ! V_19 || ! V_14 ) {
F_25 ( V_3 , L_6 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
if ( ! V_14 -> V_27 ) {
F_12 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_13 ( & V_7 ) ;
if ( ! F_26 ( V_1 ) ) {
F_25 ( V_3 , L_7 , V_5 ) ;
V_11 = - V_6 ;
goto V_52;
}
}
V_1 = F_29 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_1 ) {
F_25 ( V_3 , L_8 ,
V_5 ) ;
V_11 = - V_54 ;
goto V_52;
}
F_30 ( & V_1 -> V_13 ) ;
F_12 ( & V_1 -> V_13 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_55 = V_56 ;
V_1 -> V_3 . V_57 = F_21 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_21 = V_19 -> V_58 ;
V_1 -> V_51 = V_51 ;
V_1 -> V_42 = V_1 -> V_45
= F_31 ( V_1 -> V_19 -> V_59 ) ;
V_1 -> V_23 . V_60 = F_10 ;
F_32 ( & V_1 -> V_3 , F_33 ( V_3 ) ) ;
V_11 = F_34 ( & V_1 -> V_3 ) ;
if ( V_11 ) {
F_17 ( & V_1 -> V_3 ) ;
goto V_61;
}
if ( V_14 -> V_62 )
V_11 = V_14 -> V_62 ( V_1 ) ;
if ( V_11 )
goto V_63;
F_13 ( & V_1 -> V_13 ) ;
if ( V_14 -> V_27 )
goto V_31;
F_12 ( & V_7 ) ;
F_35 ( & V_1 -> V_29 , & V_64 ) ;
if ( V_47 && V_1 -> V_42 && ! V_46 ) {
V_46 = true ;
F_27 ( V_47 , & V_48 ,
V_1 -> V_42 ) ;
}
F_13 ( & V_7 ) ;
V_31:
return V_1 ;
V_63:
F_16 ( & V_1 -> V_3 ) ;
V_61:
F_13 ( & V_1 -> V_13 ) ;
F_20 ( V_1 ) ;
V_52:
return F_5 ( V_11 ) ;
}
int F_36 ( struct V_1 * V_1 )
{
bool V_30 ;
if ( ! V_1 )
return - V_6 ;
V_30 = ! V_1 -> V_14 -> V_27 ;
if ( V_30 ) {
F_12 ( & V_7 ) ;
while ( V_41 == V_1 ) {
F_13 ( & V_7 ) ;
F_37 () ;
F_12 ( & V_7 ) ;
}
}
F_12 ( & V_1 -> V_13 ) ;
F_14 ( V_1 , false ) ;
if ( V_30 )
F_13 ( & V_7 ) ;
return 0 ;
}
static T_2 F_38 ( struct V_2 * V_3 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_9 , F_22 ( V_3 ) -> V_14 -> V_44 ) ;
}
static T_2 F_39 ( struct V_2 * V_3 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_10 , F_22 ( V_3 ) -> V_21 ) ;
}
static T_2 F_40 ( struct V_2 * V_3 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_11 , F_22 ( V_3 ) -> V_19 -> V_59 ) ;
}
static T_2 F_41 ( struct V_2 * V_3 ,
struct V_65 * V_66 ,
const char * V_67 , T_3 V_68 )
{
struct V_1 * V_69 = F_22 ( V_3 ) ;
unsigned int V_70 ;
int V_25 ;
V_25 = sscanf ( V_67 , L_12 , & V_70 ) ;
if ( V_25 != 1 )
goto V_31;
F_12 ( & V_69 -> V_13 ) ;
V_69 -> V_19 -> V_59 = V_70 ;
V_69 -> V_42 = V_69 -> V_45
= F_31 ( V_70 ) ;
F_13 ( & V_69 -> V_13 ) ;
V_25 = V_68 ;
if ( V_69 -> V_14 -> V_27 )
goto V_31;
F_12 ( & V_7 ) ;
if ( V_69 -> V_42 > 0 && ! V_46 ) {
V_46 = true ;
F_27 ( V_47 , & V_48 ,
V_69 -> V_42 ) ;
}
F_13 ( & V_7 ) ;
V_31:
return V_25 ;
}
static T_2 F_42 ( struct V_2 * V_3 ,
struct V_65 * V_66 , char * V_67 )
{
return sprintf ( V_67 , L_11 ,
! F_22 ( V_3 ) -> V_14 -> V_27 ) ;
}
static T_2 F_43 ( struct V_2 * V_3 , struct V_65 * V_66 ,
const char * V_67 , T_3 V_68 )
{
struct V_1 * V_69 = F_22 ( V_3 ) ;
unsigned long V_70 ;
int V_25 ;
unsigned long V_71 ;
V_25 = sscanf ( V_67 , L_13 , & V_70 ) ;
if ( V_25 != 1 )
goto V_31;
F_12 ( & V_69 -> V_13 ) ;
V_71 = V_69 -> V_18 ;
if ( V_70 && V_71 && V_70 > V_71 ) {
V_25 = - V_6 ;
goto V_72;
}
V_69 -> V_16 = V_70 ;
F_9 ( V_69 ) ;
V_25 = V_68 ;
V_72:
F_13 ( & V_69 -> V_13 ) ;
V_31:
return V_25 ;
}
static T_2 F_44 ( struct V_2 * V_3 , struct V_65 * V_66 ,
char * V_67 )
{
return sprintf ( V_67 , L_10 , F_22 ( V_3 ) -> V_16 ) ;
}
static T_2 F_45 ( struct V_2 * V_3 , struct V_65 * V_66 ,
const char * V_67 , T_3 V_68 )
{
struct V_1 * V_69 = F_22 ( V_3 ) ;
unsigned long V_70 ;
int V_25 ;
unsigned long V_73 ;
V_25 = sscanf ( V_67 , L_13 , & V_70 ) ;
if ( V_25 != 1 )
goto V_31;
F_12 ( & V_69 -> V_13 ) ;
V_73 = V_69 -> V_16 ;
if ( V_70 && V_73 && V_70 < V_73 ) {
V_25 = - V_6 ;
goto V_72;
}
V_69 -> V_18 = V_70 ;
F_9 ( V_69 ) ;
V_25 = V_68 ;
V_72:
F_13 ( & V_69 -> V_13 ) ;
V_31:
return V_25 ;
}
static T_2 F_46 ( struct V_2 * V_3 , struct V_65 * V_66 ,
char * V_67 )
{
return sprintf ( V_67 , L_10 , F_22 ( V_3 ) -> V_18 ) ;
}
static int T_4 F_47 ( void )
{
F_12 ( & V_7 ) ;
V_46 = false ;
V_47 = F_48 ( L_14 ) ;
F_49 ( & V_48 , F_23 ) ;
F_13 ( & V_7 ) ;
F_23 ( & V_48 . V_33 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
V_56 = F_51 ( V_74 , L_15 ) ;
if ( F_26 ( V_56 ) ) {
F_4 ( L_16 , __FILE__ ) ;
return F_52 ( V_56 ) ;
}
V_56 -> V_75 = V_76 ;
return 0 ;
}
static void T_5 F_53 ( void )
{
F_54 ( V_56 ) ;
}
struct V_77 * F_55 ( struct V_2 * V_3 , unsigned long * V_10 ,
T_1 V_12 )
{
struct V_77 * V_77 ;
if ( V_12 & V_17 ) {
V_77 = F_56 ( V_3 , V_10 ) ;
if ( V_77 == F_5 ( - V_9 ) )
V_77 = F_57 ( V_3 , V_10 ) ;
} else {
V_77 = F_57 ( V_3 , V_10 ) ;
if ( V_77 == F_5 ( - V_9 ) )
V_77 = F_56 ( V_3 , V_10 ) ;
}
return V_77 ;
}
int F_58 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_78 * V_79 = F_59 ( V_3 ) ;
if ( F_26 ( V_79 ) )
return F_52 ( V_79 ) ;
return F_60 ( V_79 , & V_1 -> V_23 ) ;
}
int F_61 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_78 * V_79 = F_59 ( V_3 ) ;
if ( F_26 ( V_79 ) )
return F_52 ( V_79 ) ;
return F_62 ( V_79 , & V_1 -> V_23 ) ;
}
