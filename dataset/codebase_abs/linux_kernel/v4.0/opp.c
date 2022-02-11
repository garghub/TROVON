static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_5 = F_2 ( - V_6 ) ;
if ( F_3 ( F_4 ( V_3 ) ) ) {
F_5 ( L_1 , V_7 ) ;
return F_2 ( - V_8 ) ;
}
F_6 (tmp_dev_opp, &dev_opp_list, node) {
if ( V_4 -> V_3 == V_3 ) {
V_5 = V_4 ;
break;
}
}
return V_5 ;
}
unsigned long F_7 ( struct V_9 * V_10 )
{
struct V_9 * V_11 ;
unsigned long V_12 = 0 ;
F_8 () ;
V_11 = F_9 ( V_10 ) ;
if ( F_3 ( F_4 ( V_11 ) ) || ! V_11 -> V_13 )
F_5 ( L_1 , V_7 ) ;
else
V_12 = V_11 -> V_14 ;
return V_12 ;
}
unsigned long F_10 ( struct V_9 * V_10 )
{
struct V_9 * V_11 ;
unsigned long V_15 = 0 ;
F_8 () ;
V_11 = F_9 ( V_10 ) ;
if ( F_3 ( F_4 ( V_11 ) ) || ! V_11 -> V_13 )
F_5 ( L_1 , V_7 ) ;
else
V_15 = V_11 -> V_16 ;
return V_15 ;
}
int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 ;
int V_18 = 0 ;
F_12 () ;
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) ) {
V_18 = F_14 ( V_5 ) ;
F_15 ( V_3 , L_2 ,
V_7 , V_18 ) ;
goto V_19;
}
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 )
V_18 ++ ;
}
V_19:
F_16 () ;
return V_18 ;
}
struct V_9 * F_17 ( struct V_2 * V_3 ,
unsigned long V_20 ,
bool V_13 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 , * V_10 = F_2 ( - V_21 ) ;
F_8 () ;
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) ) {
int V_22 = F_14 ( V_5 ) ;
F_15 ( V_3 , L_2 , V_7 , V_22 ) ;
return F_2 ( V_22 ) ;
}
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 == V_13 &&
V_17 -> V_16 == V_20 ) {
V_10 = V_17 ;
break;
}
}
return V_10 ;
}
struct V_9 * F_18 ( struct V_2 * V_3 ,
unsigned long * V_20 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 , * V_10 = F_2 ( - V_21 ) ;
F_8 () ;
if ( ! V_3 || ! V_20 ) {
F_15 ( V_3 , L_3 , V_7 , V_20 ) ;
return F_2 ( - V_8 ) ;
}
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) )
return F_19 ( V_5 ) ;
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 && V_17 -> V_16 >= * V_20 ) {
V_10 = V_17 ;
* V_20 = V_10 -> V_16 ;
break;
}
}
return V_10 ;
}
struct V_9 * F_20 ( struct V_2 * V_3 ,
unsigned long * V_20 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 , * V_10 = F_2 ( - V_21 ) ;
F_8 () ;
if ( ! V_3 || ! V_20 ) {
F_15 ( V_3 , L_3 , V_7 , V_20 ) ;
return F_2 ( - V_8 ) ;
}
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) )
return F_19 ( V_5 ) ;
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 ) {
if ( V_17 -> V_16 > * V_20 )
break;
else
V_10 = V_17 ;
}
}
if ( ! F_13 ( V_10 ) )
* V_20 = V_10 -> V_16 ;
return V_10 ;
}
static struct V_1 * F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
V_5 = F_22 ( sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_3 = V_3 ;
F_23 ( & V_5 -> V_24 ) ;
F_24 ( & V_5 -> V_25 ) ;
F_25 ( & V_5 -> V_26 , & V_27 ) ;
return V_5 ;
}
static int F_26 ( struct V_2 * V_3 , unsigned long V_20 ,
long V_14 , bool V_28 )
{
struct V_1 * V_5 = NULL ;
struct V_9 * V_10 , * V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_29 = F_22 ( sizeof( * V_29 ) , V_23 ) ;
if ( ! V_29 )
return - V_33 ;
F_27 ( & V_34 ) ;
V_29 -> V_16 = V_20 ;
V_29 -> V_14 = V_14 ;
V_29 -> V_13 = true ;
V_29 -> V_28 = V_28 ;
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) ) {
V_5 = F_21 ( V_3 ) ;
if ( ! V_5 ) {
V_32 = - V_33 ;
goto V_35;
}
V_31 = & V_5 -> V_25 ;
goto V_36;
}
V_31 = & V_5 -> V_25 ;
F_6 (opp, &dev_opp->opp_list, node) {
if ( V_29 -> V_16 <= V_10 -> V_16 )
break;
else
V_31 = & V_10 -> V_26 ;
}
if ( V_29 -> V_16 == V_10 -> V_16 ) {
V_32 = V_10 -> V_13 && V_29 -> V_14 == V_10 -> V_14 ?
0 : - V_37 ;
F_28 ( V_3 , L_4 ,
V_7 , V_10 -> V_16 , V_10 -> V_14 , V_10 -> V_13 ,
V_29 -> V_16 , V_29 -> V_14 , V_29 -> V_13 ) ;
goto V_35;
}
V_36:
V_29 -> V_5 = V_5 ;
F_25 ( & V_29 -> V_26 , V_31 ) ;
F_29 ( & V_34 ) ;
F_30 ( & V_5 -> V_24 , V_38 , V_29 ) ;
return 0 ;
V_35:
F_29 ( & V_34 ) ;
F_31 ( V_29 ) ;
return V_32 ;
}
int F_32 ( struct V_2 * V_3 , unsigned long V_20 , unsigned long V_14 )
{
return F_26 ( V_3 , V_20 , V_14 , true ) ;
}
static void F_33 ( struct V_39 * V_31 )
{
struct V_9 * V_10 = F_34 ( V_31 , struct V_9 , V_39 ) ;
F_35 ( V_10 , V_39 ) ;
}
static void F_36 ( struct V_39 * V_31 )
{
struct V_1 * V_1 = F_34 ( V_31 , struct V_1 , V_39 ) ;
F_35 ( V_1 , V_39 ) ;
}
static void F_37 ( struct V_1 * V_5 ,
struct V_9 * V_10 )
{
F_30 ( & V_5 -> V_24 , V_40 , V_10 ) ;
F_38 ( & V_10 -> V_26 ) ;
F_39 ( & V_5 -> V_24 . V_41 , & V_10 -> V_39 , F_33 ) ;
if ( F_40 ( & V_5 -> V_25 ) ) {
F_38 ( & V_5 -> V_26 ) ;
F_39 ( & V_5 -> V_24 . V_41 , & V_5 -> V_39 ,
F_36 ) ;
}
}
void F_41 ( struct V_2 * V_3 , unsigned long V_20 )
{
struct V_9 * V_10 ;
struct V_1 * V_5 ;
bool V_42 = false ;
F_27 ( & V_34 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) )
goto V_43;
F_42 (opp, &dev_opp->opp_list, node) {
if ( V_10 -> V_16 == V_20 ) {
V_42 = true ;
break;
}
}
if ( ! V_42 ) {
F_28 ( V_3 , L_5 ,
V_7 , V_20 ) ;
goto V_43;
}
F_37 ( V_5 , V_10 ) ;
V_43:
F_29 ( & V_34 ) ;
}
static int F_43 ( struct V_2 * V_3 , unsigned long V_20 ,
bool V_44 )
{
struct V_1 * V_5 ;
struct V_9 * V_29 , * V_11 , * V_10 = F_2 ( - V_6 ) ;
int V_22 = 0 ;
V_29 = F_44 ( sizeof( * V_29 ) , V_23 ) ;
if ( ! V_29 )
return - V_33 ;
F_27 ( & V_34 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) ) {
V_22 = F_14 ( V_5 ) ;
F_28 ( V_3 , L_6 , V_7 , V_22 ) ;
goto V_43;
}
F_42 (tmp_opp, &dev_opp->opp_list, node) {
if ( V_11 -> V_16 == V_20 ) {
V_10 = V_11 ;
break;
}
}
if ( F_13 ( V_10 ) ) {
V_22 = F_14 ( V_10 ) ;
goto V_43;
}
if ( V_10 -> V_13 == V_44 )
goto V_43;
* V_29 = * V_10 ;
V_29 -> V_13 = V_44 ;
F_45 ( & V_10 -> V_26 , & V_29 -> V_26 ) ;
F_29 ( & V_34 ) ;
F_39 ( & V_5 -> V_24 . V_41 , & V_10 -> V_39 , F_33 ) ;
if ( V_44 )
F_30 ( & V_5 -> V_24 , V_45 ,
V_29 ) ;
else
F_30 ( & V_5 -> V_24 , V_46 ,
V_29 ) ;
return 0 ;
V_43:
F_29 ( & V_34 ) ;
F_31 ( V_29 ) ;
return V_22 ;
}
int F_46 ( struct V_2 * V_3 , unsigned long V_20 )
{
return F_43 ( V_3 , V_20 , true ) ;
}
int F_47 ( struct V_2 * V_3 , unsigned long V_20 )
{
return F_43 ( V_3 , V_20 , false ) ;
}
struct V_47 * F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) )
return F_19 ( V_5 ) ;
return & V_5 -> V_24 ;
}
int F_49 ( struct V_2 * V_3 )
{
const struct V_48 * V_49 ;
const T_1 * V_50 ;
int V_51 ;
V_49 = F_50 ( V_3 -> V_52 , L_7 , NULL ) ;
if ( ! V_49 )
return - V_6 ;
if ( ! V_49 -> V_53 )
return - V_54 ;
V_51 = V_49 -> V_55 / sizeof( V_56 ) ;
if ( V_51 % 2 ) {
F_15 ( V_3 , L_8 , V_7 ) ;
return - V_8 ;
}
V_50 = V_49 -> V_53 ;
while ( V_51 ) {
unsigned long V_20 = F_51 ( V_50 ++ ) * 1000 ;
unsigned long V_57 = F_51 ( V_50 ++ ) ;
if ( F_26 ( V_3 , V_20 , V_57 , false ) )
F_28 ( V_3 , L_9 ,
V_7 , V_20 ) ;
V_51 -= 2 ;
}
return 0 ;
}
void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_9 * V_10 , * V_58 ;
V_5 = F_1 ( V_3 ) ;
if ( F_13 ( V_5 ) ) {
int error = F_14 ( V_5 ) ;
if ( error != - V_6 )
F_53 ( 1 , L_10 ,
F_4 ( V_3 ) ?
L_11 : F_54 ( V_3 ) ,
error ) ;
return;
}
F_27 ( & V_34 ) ;
F_55 (opp, tmp, &dev_opp->opp_list, node) {
if ( ! V_10 -> V_28 )
F_37 ( V_5 , V_10 ) ;
}
F_29 ( & V_34 ) ;
}
