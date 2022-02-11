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
if ( ! F_7 ( & V_1 -> V_12 ) ) {
F_6 ( true , L_3 ) ;
return - V_6 ;
}
V_11 = V_1 -> V_13 -> V_14 ( V_1 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_1 -> V_15 -> V_16 ( V_1 -> V_3 . V_8 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_1 -> V_17 = V_10 ;
return V_11 ;
}
static int F_10 ( struct V_18 * V_19 , unsigned long type ,
void * V_20 )
{
struct V_1 * V_1 = F_11 ( V_19 , struct V_1 , V_19 ) ;
int V_21 ;
F_12 ( & V_1 -> V_12 ) ;
V_21 = F_9 ( V_1 ) ;
F_13 ( & V_1 -> V_12 ) ;
return V_21 ;
}
static void F_14 ( struct V_1 * V_1 , bool V_22 )
{
if ( ! F_7 ( & V_1 -> V_12 ) ) {
F_6 ( true , L_3 ) ;
return;
}
if ( ! V_1 -> V_13 -> V_23 &&
! F_7 ( & V_7 ) ) {
F_6 ( true , L_4 ) ;
return;
}
if ( V_1 -> V_24 )
return;
V_1 -> V_24 = true ;
if ( V_1 -> V_15 -> exit )
V_1 -> V_15 -> exit ( V_1 -> V_3 . V_8 ) ;
if ( V_1 -> V_13 -> exit )
V_1 -> V_13 -> exit ( V_1 ) ;
if ( ! V_22 && F_15 ( & V_1 -> V_3 ) ) {
F_16 ( & V_1 -> V_3 ) ;
F_17 ( & V_1 -> V_3 ) ;
}
if ( ! V_1 -> V_13 -> V_23 )
F_18 ( & V_1 -> V_25 ) ;
F_13 ( & V_1 -> V_12 ) ;
F_19 ( & V_1 -> V_12 ) ;
F_20 ( V_1 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_22 ( V_3 ) ;
bool V_26 = ! V_1 -> V_13 -> V_23 ;
if ( V_1 -> V_24 )
return;
if ( V_26 )
F_12 ( & V_7 ) ;
F_12 ( & V_1 -> V_12 ) ;
if ( V_1 -> V_24 ) {
F_13 ( & V_1 -> V_12 ) ;
goto V_27;
}
F_14 ( V_1 , true ) ;
V_27:
if ( V_26 )
F_13 ( & V_7 ) ;
}
static void F_23 ( struct V_28 * V_29 )
{
static unsigned long V_30 ;
struct V_1 * V_1 , * V_31 ;
int error ;
unsigned long V_32 ;
unsigned long V_33 = V_34 , V_35 = V_36 ;
struct V_2 * V_3 ;
V_32 = V_35 - V_30 ;
V_30 = V_35 ;
if ( V_32 == 0 )
V_32 = 1 ;
F_12 ( & V_7 ) ;
F_24 (devfreq, tmp, &devfreq_list, node) {
F_12 ( & V_1 -> V_12 ) ;
V_3 = V_1 -> V_3 . V_8 ;
V_37 = V_31 ;
if ( V_1 -> V_13 -> V_23 ||
V_1 -> V_38 == 0 ) {
F_13 ( & V_1 -> V_12 ) ;
continue;
}
F_13 ( & V_7 ) ;
if ( V_1 -> V_38 <= V_32 ) {
error = F_9 ( V_1 ) ;
if ( error && error != - V_39 ) {
F_25 ( V_3 , L_5 ,
error , V_1 -> V_13 -> V_40 ) ;
F_13 ( & V_1 -> V_12 ) ;
F_12 ( & V_7 ) ;
if ( F_26 ( F_1 ( V_3 ) ) )
continue;
F_12 ( & V_1 -> V_12 ) ;
F_14 ( V_1 , false ) ;
continue;
}
V_1 -> V_38 = V_1 -> V_41 ;
} else {
V_1 -> V_38 -= V_32 ;
}
if ( V_1 -> V_38 )
V_33 = ( V_33 > V_1 -> V_38 ) ?
V_1 -> V_38 : V_33 ;
F_13 ( & V_1 -> V_12 ) ;
F_12 ( & V_7 ) ;
}
V_37 = NULL ;
F_13 ( & V_7 ) ;
if ( V_33 > 0 && V_33 < V_34 ) {
V_42 = true ;
F_27 ( V_43 , & V_44 , V_33 ) ;
} else {
V_42 = false ;
}
}
struct V_1 * F_28 ( struct V_2 * V_3 ,
struct V_45 * V_15 ,
const struct V_46 * V_13 ,
void * V_47 )
{
struct V_1 * V_1 ;
int V_11 = 0 ;
if ( ! V_3 || ! V_15 || ! V_13 ) {
F_25 ( V_3 , L_6 , V_5 ) ;
return F_5 ( - V_6 ) ;
}
if ( ! V_13 -> V_23 ) {
F_12 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_13 ( & V_7 ) ;
if ( ! F_26 ( V_1 ) ) {
F_25 ( V_3 , L_7 , V_5 ) ;
V_11 = - V_6 ;
goto V_27;
}
}
V_1 = F_29 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_1 ) {
F_25 ( V_3 , L_8 ,
V_5 ) ;
V_11 = - V_49 ;
goto V_27;
}
F_30 ( & V_1 -> V_12 ) ;
F_12 ( & V_1 -> V_12 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_50 = V_51 ;
V_1 -> V_3 . V_52 = F_21 ;
V_1 -> V_15 = V_15 ;
V_1 -> V_13 = V_13 ;
V_1 -> V_17 = V_15 -> V_53 ;
V_1 -> V_47 = V_47 ;
V_1 -> V_38 = V_1 -> V_41
= F_31 ( V_1 -> V_15 -> V_54 ) ;
V_1 -> V_19 . V_55 = F_10 ;
F_32 ( & V_1 -> V_3 , F_33 ( V_3 ) ) ;
V_11 = F_34 ( & V_1 -> V_3 ) ;
if ( V_11 ) {
F_17 ( & V_1 -> V_3 ) ;
goto V_56;
}
if ( V_13 -> V_57 )
V_11 = V_13 -> V_57 ( V_1 ) ;
if ( V_11 )
goto V_58;
F_13 ( & V_1 -> V_12 ) ;
if ( V_13 -> V_23 )
goto V_27;
F_12 ( & V_7 ) ;
F_35 ( & V_1 -> V_25 , & V_59 ) ;
if ( V_43 && V_1 -> V_38 && ! V_42 ) {
V_42 = true ;
F_27 ( V_43 , & V_44 ,
V_1 -> V_38 ) ;
}
F_13 ( & V_7 ) ;
goto V_27;
V_58:
F_16 ( & V_1 -> V_3 ) ;
V_56:
F_13 ( & V_1 -> V_12 ) ;
F_20 ( V_1 ) ;
V_27:
if ( V_11 )
return F_5 ( V_11 ) ;
else
return V_1 ;
}
int F_36 ( struct V_1 * V_1 )
{
bool V_26 ;
if ( ! V_1 )
return - V_6 ;
V_26 = ! V_1 -> V_13 -> V_23 ;
if ( V_26 ) {
F_12 ( & V_7 ) ;
while ( V_37 == V_1 ) {
F_13 ( & V_7 ) ;
F_37 () ;
F_12 ( & V_7 ) ;
}
}
F_12 ( & V_1 -> V_12 ) ;
F_14 ( V_1 , false ) ;
if ( V_26 )
F_13 ( & V_7 ) ;
return 0 ;
}
static T_1 F_38 ( struct V_2 * V_3 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_9 , F_22 ( V_3 ) -> V_13 -> V_40 ) ;
}
static T_1 F_39 ( struct V_2 * V_3 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_10 , F_22 ( V_3 ) -> V_17 ) ;
}
static T_1 F_40 ( struct V_2 * V_3 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_11 , F_22 ( V_3 ) -> V_15 -> V_54 ) ;
}
static T_1 F_41 ( struct V_2 * V_3 ,
struct V_60 * V_61 ,
const char * V_62 , T_2 V_63 )
{
struct V_1 * V_64 = F_22 ( V_3 ) ;
unsigned int V_65 ;
int V_21 ;
V_21 = sscanf ( V_62 , L_12 , & V_65 ) ;
if ( V_21 != 1 )
goto V_27;
F_12 ( & V_64 -> V_12 ) ;
V_64 -> V_15 -> V_54 = V_65 ;
V_64 -> V_38 = V_64 -> V_41
= F_31 ( V_65 ) ;
F_13 ( & V_64 -> V_12 ) ;
V_21 = V_63 ;
if ( V_64 -> V_13 -> V_23 )
goto V_27;
F_12 ( & V_7 ) ;
if ( V_64 -> V_38 > 0 && ! V_42 ) {
V_42 = true ;
F_27 ( V_43 , & V_44 ,
V_64 -> V_38 ) ;
}
F_13 ( & V_7 ) ;
V_27:
return V_21 ;
}
static T_1 F_42 ( struct V_2 * V_3 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_11 ,
! F_22 ( V_3 ) -> V_13 -> V_23 ) ;
}
static int T_3 F_43 ( void )
{
F_12 ( & V_7 ) ;
V_42 = false ;
V_43 = F_44 ( L_13 ) ;
F_45 ( & V_44 , F_23 ) ;
F_13 ( & V_7 ) ;
F_23 ( & V_44 . V_29 ) ;
return 0 ;
}
static int T_3 F_46 ( void )
{
V_51 = F_47 ( V_66 , L_14 ) ;
if ( F_26 ( V_51 ) ) {
F_4 ( L_15 , __FILE__ ) ;
return F_48 ( V_51 ) ;
}
V_51 -> V_67 = V_68 ;
return 0 ;
}
static void T_4 F_49 ( void )
{
F_50 ( V_51 ) ;
}
struct V_69 * F_51 ( struct V_2 * V_3 , unsigned long * V_10 )
{
struct V_69 * V_69 = F_52 ( V_3 , V_10 ) ;
if ( V_69 == F_5 ( - V_9 ) )
V_69 = F_53 ( V_3 , V_10 ) ;
return V_69 ;
}
int F_54 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_70 * V_71 = F_55 ( V_3 ) ;
if ( F_26 ( V_71 ) )
return F_48 ( V_71 ) ;
return F_56 ( V_71 , & V_1 -> V_19 ) ;
}
int F_57 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
struct V_70 * V_71 = F_55 ( V_3 ) ;
if ( F_26 ( V_71 ) )
return F_48 ( V_71 ) ;
return F_58 ( V_71 , & V_1 -> V_19 ) ;
}
