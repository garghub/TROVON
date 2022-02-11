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
V_11 = F_8 ( V_10 ) ;
if ( F_3 ( F_4 ( V_11 ) ) || ! V_11 -> V_13 )
F_5 ( L_1 , V_7 ) ;
else
V_12 = V_11 -> V_14 ;
return V_12 ;
}
unsigned long F_9 ( struct V_9 * V_10 )
{
struct V_9 * V_11 ;
unsigned long V_15 = 0 ;
V_11 = F_8 ( V_10 ) ;
if ( F_3 ( F_4 ( V_11 ) ) || ! V_11 -> V_13 )
F_5 ( L_1 , V_7 ) ;
else
V_15 = V_11 -> V_16 ;
return V_15 ;
}
int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 ;
int V_18 = 0 ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
int V_19 = F_12 ( V_5 ) ;
F_13 ( V_3 , L_2 , V_7 , V_19 ) ;
return V_19 ;
}
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 )
V_18 ++ ;
}
return V_18 ;
}
struct V_9 * F_14 ( struct V_2 * V_3 ,
unsigned long V_20 ,
bool V_13 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 , * V_10 = F_2 ( - V_21 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
int V_19 = F_12 ( V_5 ) ;
F_13 ( V_3 , L_2 , V_7 , V_19 ) ;
return F_2 ( V_19 ) ;
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
struct V_9 * F_15 ( struct V_2 * V_3 ,
unsigned long * V_20 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 , * V_10 = F_2 ( - V_21 ) ;
if ( ! V_3 || ! V_20 ) {
F_13 ( V_3 , L_3 , V_7 , V_20 ) ;
return F_2 ( - V_8 ) ;
}
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) )
return F_16 ( V_5 ) ;
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 && V_17 -> V_16 >= * V_20 ) {
V_10 = V_17 ;
* V_20 = V_10 -> V_16 ;
break;
}
}
return V_10 ;
}
struct V_9 * F_17 ( struct V_2 * V_3 ,
unsigned long * V_20 )
{
struct V_1 * V_5 ;
struct V_9 * V_17 , * V_10 = F_2 ( - V_21 ) ;
if ( ! V_3 || ! V_20 ) {
F_13 ( V_3 , L_3 , V_7 , V_20 ) ;
return F_2 ( - V_8 ) ;
}
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) )
return F_16 ( V_5 ) ;
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_17 -> V_13 ) {
if ( V_17 -> V_16 > * V_20 )
break;
else
V_10 = V_17 ;
}
}
if ( ! F_11 ( V_10 ) )
* V_20 = V_10 -> V_16 ;
return V_10 ;
}
int F_18 ( struct V_2 * V_3 , unsigned long V_20 , unsigned long V_14 )
{
struct V_1 * V_5 = NULL ;
struct V_9 * V_10 , * V_22 ;
struct V_23 * V_24 ;
V_22 = F_19 ( sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 ) {
F_20 ( V_3 , L_4 , V_7 ) ;
return - V_26 ;
}
F_21 ( & V_27 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
V_5 = F_19 ( sizeof( struct V_1 ) , V_25 ) ;
if ( ! V_5 ) {
F_22 ( & V_27 ) ;
F_23 ( V_22 ) ;
F_20 ( V_3 ,
L_5 ,
V_7 ) ;
return - V_26 ;
}
V_5 -> V_3 = V_3 ;
F_24 ( & V_5 -> V_24 ) ;
F_25 ( & V_5 -> V_28 ) ;
F_26 ( & V_5 -> V_29 , & V_30 ) ;
}
V_22 -> V_5 = V_5 ;
V_22 -> V_16 = V_20 ;
V_22 -> V_14 = V_14 ;
V_22 -> V_13 = true ;
V_24 = & V_5 -> V_28 ;
F_6 (opp, &dev_opp->opp_list, node) {
if ( V_22 -> V_16 <= V_10 -> V_16 )
break;
else
V_24 = & V_10 -> V_29 ;
}
if ( V_22 -> V_16 == V_10 -> V_16 ) {
int V_31 = V_10 -> V_13 && V_22 -> V_14 == V_10 -> V_14 ?
0 : - V_32 ;
F_20 ( V_3 , L_6 ,
V_7 , V_10 -> V_16 , V_10 -> V_14 , V_10 -> V_13 ,
V_22 -> V_16 , V_22 -> V_14 , V_22 -> V_13 ) ;
F_22 ( & V_27 ) ;
F_23 ( V_22 ) ;
return V_31 ;
}
F_26 ( & V_22 -> V_29 , V_24 ) ;
F_22 ( & V_27 ) ;
F_27 ( & V_5 -> V_24 , V_33 , V_22 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , unsigned long V_20 ,
bool V_34 )
{
struct V_1 * V_4 , * V_5 = F_2 ( - V_6 ) ;
struct V_9 * V_22 , * V_11 , * V_10 = F_2 ( - V_6 ) ;
int V_19 = 0 ;
V_22 = F_29 ( sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 ) {
F_20 ( V_3 , L_7 , V_7 ) ;
return - V_26 ;
}
F_21 ( & V_27 ) ;
F_30 (tmp_dev_opp, &dev_opp_list, node) {
if ( V_3 == V_4 -> V_3 ) {
V_5 = V_4 ;
break;
}
}
if ( F_11 ( V_5 ) ) {
V_19 = F_12 ( V_5 ) ;
F_20 ( V_3 , L_8 , V_7 , V_19 ) ;
goto V_35;
}
F_30 (tmp_opp, &dev_opp->opp_list, node) {
if ( V_11 -> V_16 == V_20 ) {
V_10 = V_11 ;
break;
}
}
if ( F_11 ( V_10 ) ) {
V_19 = F_12 ( V_10 ) ;
goto V_35;
}
if ( V_10 -> V_13 == V_34 )
goto V_35;
* V_22 = * V_10 ;
V_22 -> V_13 = V_34 ;
F_31 ( & V_10 -> V_29 , & V_22 -> V_29 ) ;
F_22 ( & V_27 ) ;
F_32 ( V_10 , V_24 ) ;
if ( V_34 )
F_27 ( & V_5 -> V_24 , V_36 ,
V_22 ) ;
else
F_27 ( & V_5 -> V_24 , V_37 ,
V_22 ) ;
return 0 ;
V_35:
F_22 ( & V_27 ) ;
F_23 ( V_22 ) ;
return V_19 ;
}
int F_33 ( struct V_2 * V_3 , unsigned long V_20 )
{
return F_28 ( V_3 , V_20 , true ) ;
}
int F_34 ( struct V_2 * V_3 , unsigned long V_20 )
{
return F_28 ( V_3 , V_20 , false ) ;
}
struct V_38 * F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) )
return F_16 ( V_5 ) ;
return & V_5 -> V_24 ;
}
int F_36 ( struct V_2 * V_3 )
{
const struct V_39 * V_40 ;
const T_1 * V_41 ;
int V_42 ;
V_40 = F_37 ( V_3 -> V_43 , L_9 , NULL ) ;
if ( ! V_40 )
return - V_6 ;
if ( ! V_40 -> V_44 )
return - V_45 ;
V_42 = V_40 -> V_46 / sizeof( V_47 ) ;
if ( V_42 % 2 ) {
F_13 ( V_3 , L_10 , V_7 ) ;
return - V_8 ;
}
V_41 = V_40 -> V_44 ;
while ( V_42 ) {
unsigned long V_20 = F_38 ( V_41 ++ ) * 1000 ;
unsigned long V_48 = F_38 ( V_41 ++ ) ;
if ( F_18 ( V_3 , V_20 , V_48 ) )
F_20 ( V_3 , L_11 ,
V_7 , V_20 ) ;
V_42 -= 2 ;
}
return 0 ;
}
