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
unsigned long F_7 ( struct V_9 * V_9 )
{
struct V_9 * V_10 ;
unsigned long V_11 = 0 ;
V_10 = F_8 ( V_9 ) ;
if ( F_3 ( F_4 ( V_10 ) ) || ! V_10 -> V_12 )
F_5 ( L_1 , V_7 ) ;
else
V_11 = V_10 -> V_13 ;
return V_11 ;
}
unsigned long F_9 ( struct V_9 * V_9 )
{
struct V_9 * V_10 ;
unsigned long V_14 = 0 ;
V_10 = F_8 ( V_9 ) ;
if ( F_3 ( F_4 ( V_10 ) ) || ! V_10 -> V_12 )
F_5 ( L_1 , V_7 ) ;
else
V_14 = V_10 -> V_15 ;
return V_14 ;
}
int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_9 * V_16 ;
int V_17 = 0 ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
int V_18 = F_12 ( V_5 ) ;
F_13 ( V_3 , L_2 , V_7 , V_18 ) ;
return V_18 ;
}
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_16 -> V_12 )
V_17 ++ ;
}
return V_17 ;
}
struct V_9 * F_14 ( struct V_2 * V_3 , unsigned long V_19 ,
bool V_12 )
{
struct V_1 * V_5 ;
struct V_9 * V_16 , * V_9 = F_2 ( - V_20 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
int V_18 = F_12 ( V_5 ) ;
F_13 ( V_3 , L_2 , V_7 , V_18 ) ;
return F_2 ( V_18 ) ;
}
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_16 -> V_12 == V_12 &&
V_16 -> V_15 == V_19 ) {
V_9 = V_16 ;
break;
}
}
return V_9 ;
}
struct V_9 * F_15 ( struct V_2 * V_3 , unsigned long * V_19 )
{
struct V_1 * V_5 ;
struct V_9 * V_16 , * V_9 = F_2 ( - V_20 ) ;
if ( ! V_3 || ! V_19 ) {
F_13 ( V_3 , L_3 , V_7 , V_19 ) ;
return F_2 ( - V_8 ) ;
}
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) )
return F_16 ( V_5 ) ;
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_16 -> V_12 && V_16 -> V_15 >= * V_19 ) {
V_9 = V_16 ;
* V_19 = V_9 -> V_15 ;
break;
}
}
return V_9 ;
}
struct V_9 * F_17 ( struct V_2 * V_3 , unsigned long * V_19 )
{
struct V_1 * V_5 ;
struct V_9 * V_16 , * V_9 = F_2 ( - V_20 ) ;
if ( ! V_3 || ! V_19 ) {
F_13 ( V_3 , L_3 , V_7 , V_19 ) ;
return F_2 ( - V_8 ) ;
}
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) )
return F_16 ( V_5 ) ;
F_6 (temp_opp, &dev_opp->opp_list, node) {
if ( V_16 -> V_12 ) {
if ( V_16 -> V_15 > * V_19 )
break;
else
V_9 = V_16 ;
}
}
if ( ! F_11 ( V_9 ) )
* V_19 = V_9 -> V_15 ;
return V_9 ;
}
int F_18 ( struct V_2 * V_3 , unsigned long V_19 , unsigned long V_13 )
{
struct V_1 * V_5 = NULL ;
struct V_9 * V_9 , * V_21 ;
struct V_22 * V_23 ;
V_21 = F_19 ( sizeof( struct V_9 ) , V_24 ) ;
if ( ! V_21 ) {
F_20 ( V_3 , L_4 , V_7 ) ;
return - V_25 ;
}
F_21 ( & V_26 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
V_5 = F_19 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_5 ) {
F_22 ( & V_26 ) ;
F_23 ( V_21 ) ;
F_20 ( V_3 ,
L_5 ,
V_7 ) ;
return - V_25 ;
}
V_5 -> V_3 = V_3 ;
F_24 ( & V_5 -> V_23 ) ;
F_25 ( & V_5 -> V_27 ) ;
F_26 ( & V_5 -> V_28 , & V_29 ) ;
}
V_21 -> V_5 = V_5 ;
V_21 -> V_15 = V_19 ;
V_21 -> V_13 = V_13 ;
V_21 -> V_12 = true ;
V_23 = & V_5 -> V_27 ;
F_6 (opp, &dev_opp->opp_list, node) {
if ( V_21 -> V_15 < V_9 -> V_15 )
break;
else
V_23 = & V_9 -> V_28 ;
}
F_26 ( & V_21 -> V_28 , V_23 ) ;
F_22 ( & V_26 ) ;
F_27 ( & V_5 -> V_23 , V_30 , V_21 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , unsigned long V_19 ,
bool V_31 )
{
struct V_1 * V_4 , * V_5 = F_2 ( - V_6 ) ;
struct V_9 * V_21 , * V_10 , * V_9 = F_2 ( - V_6 ) ;
int V_18 = 0 ;
V_21 = F_29 ( sizeof( struct V_9 ) , V_24 ) ;
if ( ! V_21 ) {
F_20 ( V_3 , L_6 , V_7 ) ;
return - V_25 ;
}
F_21 ( & V_26 ) ;
F_30 (tmp_dev_opp, &dev_opp_list, node) {
if ( V_3 == V_4 -> V_3 ) {
V_5 = V_4 ;
break;
}
}
if ( F_11 ( V_5 ) ) {
V_18 = F_12 ( V_5 ) ;
F_20 ( V_3 , L_7 , V_7 , V_18 ) ;
goto V_32;
}
F_30 (tmp_opp, &dev_opp->opp_list, node) {
if ( V_10 -> V_15 == V_19 ) {
V_9 = V_10 ;
break;
}
}
if ( F_11 ( V_9 ) ) {
V_18 = F_12 ( V_9 ) ;
goto V_32;
}
if ( V_9 -> V_12 == V_31 )
goto V_32;
* V_21 = * V_9 ;
V_21 -> V_12 = V_31 ;
F_31 ( & V_9 -> V_28 , & V_21 -> V_28 ) ;
F_22 ( & V_26 ) ;
F_32 ( V_9 , V_23 ) ;
if ( V_31 )
F_27 ( & V_5 -> V_23 , V_33 ,
V_21 ) ;
else
F_27 ( & V_5 -> V_23 , V_34 ,
V_21 ) ;
return 0 ;
V_32:
F_22 ( & V_26 ) ;
F_23 ( V_21 ) ;
return V_18 ;
}
int F_33 ( struct V_2 * V_3 , unsigned long V_19 )
{
return F_28 ( V_3 , V_19 , true ) ;
}
int F_34 ( struct V_2 * V_3 , unsigned long V_19 )
{
return F_28 ( V_3 , V_19 , false ) ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_35 * * V_36 )
{
struct V_1 * V_5 ;
struct V_9 * V_9 ;
struct V_35 * V_37 ;
int V_38 = 0 ;
F_21 ( & V_26 ) ;
V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) ) {
int V_18 = F_12 ( V_5 ) ;
F_22 ( & V_26 ) ;
F_13 ( V_3 , L_7 , V_7 , V_18 ) ;
return V_18 ;
}
V_37 = F_19 ( sizeof( struct V_35 ) *
( F_10 ( V_3 ) + 1 ) , V_24 ) ;
if ( ! V_37 ) {
F_22 ( & V_26 ) ;
F_20 ( V_3 , L_8 ,
V_7 ) ;
return - V_25 ;
}
F_30 (opp, &dev_opp->opp_list, node) {
if ( V_9 -> V_12 ) {
V_37 [ V_38 ] . V_39 = V_38 ;
V_37 [ V_38 ] . V_40 = V_9 -> V_15 / 1000 ;
V_38 ++ ;
}
}
F_22 ( & V_26 ) ;
V_37 [ V_38 ] . V_39 = V_38 ;
V_37 [ V_38 ] . V_40 = V_41 ;
* V_36 = & V_37 [ 0 ] ;
return 0 ;
}
void F_36 ( struct V_2 * V_3 ,
struct V_35 * * V_36 )
{
if ( ! V_36 )
return;
F_23 ( * V_36 ) ;
* V_36 = NULL ;
}
struct V_42 * F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( F_11 ( V_5 ) )
return F_16 ( V_5 ) ;
return & V_5 -> V_23 ;
}
int F_38 ( struct V_2 * V_3 )
{
const struct V_43 * V_44 ;
const T_1 * V_45 ;
int V_46 ;
V_44 = F_39 ( V_3 -> V_47 , L_9 , NULL ) ;
if ( ! V_44 )
return - V_6 ;
if ( ! V_44 -> V_48 )
return - V_49 ;
V_46 = V_44 -> V_50 / sizeof( V_51 ) ;
if ( V_46 % 2 ) {
F_13 ( V_3 , L_10 , V_7 ) ;
return - V_8 ;
}
V_45 = V_44 -> V_48 ;
while ( V_46 ) {
unsigned long V_19 = F_40 ( V_45 ++ ) * 1000 ;
unsigned long V_52 = F_40 ( V_45 ++ ) ;
if ( F_18 ( V_3 , V_19 , V_52 ) ) {
F_20 ( V_3 , L_11 ,
V_7 , V_19 ) ;
continue;
}
V_46 -= 2 ;
}
return 0 ;
}
