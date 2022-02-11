int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_4 -> V_7 && V_2 -> V_4 -> V_7 -> V_8
&& V_2 -> V_9 == 0 ) {
V_3 = V_2 -> V_4 -> V_7 -> V_8 ( V_2 ) ;
if ( V_3 < 0 )
goto V_10;
}
V_2 -> V_9 ++ ;
V_10:
F_3 ( & V_2 -> V_6 ) ;
return V_3 ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_9 <= 0 ) {
F_5 ( & V_2 -> V_11 , L_1 ) ;
V_3 = - V_12 ;
goto V_10;
}
if ( V_2 -> V_4 -> V_7 && V_2 -> V_4 -> V_7 -> V_13
&& V_2 -> V_9 == 1 ) {
V_3 = V_2 -> V_4 -> V_7 -> V_13 ( V_2 ) ;
if ( V_3 < 0 )
goto V_10;
}
V_2 -> V_9 -- ;
V_10:
F_3 ( & V_2 -> V_6 ) ;
return V_3 ;
}
bool F_6 ( struct V_1 * V_2 )
{
bool V_14 = false ;
if ( ! V_2 || ! V_2 -> V_4 )
return V_14 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_9 > 0 )
V_14 = true ;
F_3 ( & V_2 -> V_6 ) ;
return V_14 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
if ( ! V_2 -> V_4 -> V_7 || ! V_2 -> V_4 -> V_7 -> V_15 )
return - V_5 ;
if ( ! F_6 ( V_2 ) )
return - V_16 ;
F_2 ( & V_2 -> V_6 ) ;
V_3 = V_2 -> V_4 -> V_7 -> V_15 ( V_2 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_3 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_3 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
if ( ! V_2 -> V_4 -> V_7 || ! V_2 -> V_4 -> V_7 -> V_19 )
return - V_5 ;
if ( ! F_6 ( V_2 ) )
return - V_5 ;
V_18 -> V_20 = V_18 -> V_21 = 0 ;
F_2 ( & V_2 -> V_6 ) ;
V_3 = V_2 -> V_4 -> V_7 -> V_19 ( V_2 , V_18 ) ;
if ( V_3 < 0 )
V_18 -> V_20 = V_18 -> V_21 = 0 ;
F_3 ( & V_2 -> V_6 ) ;
return V_3 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
if ( ! F_6 ( V_2 ) )
return - V_16 ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_4 -> V_7 && V_2 -> V_4 -> V_7 -> V_22 )
V_3 = V_2 -> V_4 -> V_7 -> V_22 ( V_2 ) ;
F_3 ( & V_2 -> V_6 ) ;
return V_3 ;
}
struct V_1 * F_10 ( struct V_23 * V_11 ,
int V_24 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
if ( ! V_11 -> V_27 )
return F_11 ( - V_5 ) ;
V_26 = F_12 ( V_11 -> V_27 , L_2 , V_24 ) ;
if ( ! V_26 )
return F_11 ( - V_28 ) ;
F_2 ( & V_29 ) ;
F_13 (edev, &devfreq_event_list, node) {
if ( V_2 -> V_11 . V_30 && V_2 -> V_11 . V_30 -> V_27 == V_26 )
goto V_31;
}
F_13 (edev, &devfreq_event_list, node) {
if ( ! strcmp ( V_2 -> V_4 -> V_32 , V_26 -> V_32 ) )
goto V_31;
}
V_2 = NULL ;
V_31:
F_3 ( & V_29 ) ;
if ( ! V_2 ) {
F_14 ( V_26 ) ;
return F_11 ( - V_28 ) ;
}
F_14 ( V_26 ) ;
return V_2 ;
}
int F_15 ( struct V_23 * V_11 )
{
int V_33 ;
if ( ! V_11 -> V_27 ) {
F_16 ( V_11 , L_3 ) ;
return - V_5 ;
}
V_33 = F_17 ( V_11 -> V_27 , L_2 ,
sizeof( V_34 ) ) ;
if ( V_33 < 0 ) {
F_16 ( V_11 ,
L_4 ,
V_11 -> V_27 -> V_35 ) ;
return V_33 ;
}
return V_33 ;
}
static void F_18 ( struct V_23 * V_11 )
{
struct V_1 * V_2 = F_19 ( V_11 ) ;
F_20 ( V_2 ) ;
}
struct V_1 * F_21 ( struct V_23 * V_11 ,
struct V_36 * V_4 )
{
struct V_1 * V_2 ;
static T_1 V_37 = F_22 ( 0 ) ;
int V_3 ;
if ( ! V_11 || ! V_4 )
return F_11 ( - V_5 ) ;
if ( ! V_4 -> V_32 || ! V_4 -> V_7 )
return F_11 ( - V_5 ) ;
if ( ! V_4 -> V_7 -> V_15 || ! V_4 -> V_7 -> V_19 )
return F_11 ( - V_5 ) ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_38 ) ;
if ( ! V_2 )
return F_11 ( - V_39 ) ;
F_24 ( & V_2 -> V_6 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_9 = 0 ;
V_2 -> V_11 . V_30 = V_11 ;
V_2 -> V_11 . V_40 = V_41 ;
V_2 -> V_11 . V_42 = F_18 ;
F_25 ( & V_2 -> V_11 , L_5 , F_26 ( & V_37 ) - 1 ) ;
V_3 = F_27 ( & V_2 -> V_11 ) ;
if ( V_3 < 0 ) {
F_28 ( & V_2 -> V_11 ) ;
return F_11 ( V_3 ) ;
}
F_29 ( & V_2 -> V_11 , V_2 ) ;
F_30 ( & V_2 -> V_26 ) ;
F_2 ( & V_29 ) ;
F_31 ( & V_2 -> V_26 , & V_43 ) ;
F_3 ( & V_29 ) ;
return V_2 ;
}
int F_32 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_5 ;
F_33 ( V_2 -> V_9 ) ;
F_2 ( & V_29 ) ;
F_34 ( & V_2 -> V_26 ) ;
F_3 ( & V_29 ) ;
F_35 ( & V_2 -> V_11 ) ;
return 0 ;
}
static int F_36 ( struct V_23 * V_11 , void * V_44 , void * V_45 )
{
struct V_1 * * V_46 = V_44 ;
if ( F_33 ( ! V_46 || ! * V_46 ) )
return 0 ;
return * V_46 == V_45 ;
}
static void F_37 ( struct V_23 * V_11 , void * V_44 )
{
F_32 ( * (struct V_1 * * ) V_44 ) ;
}
struct V_1 * F_38 ( struct V_23 * V_11 ,
struct V_36 * V_4 )
{
struct V_1 * * V_47 , * V_2 ;
V_47 = F_39 ( F_37 , sizeof( * V_47 ) ,
V_38 ) ;
if ( ! V_47 )
return F_11 ( - V_39 ) ;
V_2 = F_21 ( V_11 , V_4 ) ;
if ( F_40 ( V_2 ) ) {
F_41 ( V_47 ) ;
return F_11 ( - V_39 ) ;
}
* V_47 = V_2 ;
F_42 ( V_11 , V_47 ) ;
return V_2 ;
}
void F_43 ( struct V_23 * V_11 ,
struct V_1 * V_2 )
{
F_33 ( F_44 ( V_11 , F_37 ,
F_36 , V_2 ) ) ;
}
static T_2 F_45 ( struct V_23 * V_11 , struct V_48 * V_49 ,
char * V_50 )
{
struct V_1 * V_2 = F_19 ( V_11 ) ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
return sprintf ( V_50 , L_6 , V_2 -> V_4 -> V_32 ) ;
}
static T_2 F_46 ( struct V_23 * V_11 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_19 ( V_11 ) ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_5 ;
return sprintf ( V_50 , L_7 , V_2 -> V_9 ) ;
}
static int T_3 F_47 ( void )
{
V_41 = F_48 ( V_51 , L_8 ) ;
if ( F_40 ( V_41 ) ) {
F_49 ( L_9 , __FILE__ ) ;
return F_50 ( V_41 ) ;
}
V_41 -> V_52 = V_53 ;
return 0 ;
}
static void T_4 F_51 ( void )
{
F_52 ( V_41 ) ;
}
