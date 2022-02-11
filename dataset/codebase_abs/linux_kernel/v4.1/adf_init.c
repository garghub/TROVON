static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_7 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 || V_2 -> V_7 ) {
F_9 ( L_1 ) ;
return - V_8 ;
}
F_6 ( V_2 ) ;
return 0 ;
}
int F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 = V_10 -> V_15 ;
if ( ! V_14 ) {
F_11 ( & F_12 ( V_10 ) ,
L_2 ) ;
return - V_8 ;
}
if ( ! F_13 ( V_16 , & V_10 -> V_17 ) ) {
F_11 ( & F_12 ( V_10 ) , L_3 ) ;
return - V_8 ;
}
if ( F_14 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) , L_4 ) ;
return - V_8 ;
}
if ( V_14 -> V_18 && V_14 -> V_18 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) , L_5 ) ;
return - V_8 ;
}
if ( V_14 -> V_19 && V_14 -> V_19 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) , L_6 ) ;
return - V_8 ;
}
V_14 -> V_20 ( V_10 ) ;
if ( F_15 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) ,
L_7 ) ;
return - V_8 ;
}
F_16 ( V_21 , & V_10 -> V_17 ) ;
if ( F_17 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) ,
L_8 ) ;
return - V_8 ;
}
F_16 ( V_22 , & V_10 -> V_17 ) ;
if ( V_14 -> V_23 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) , L_9 ) ;
return - V_8 ;
}
F_16 ( V_24 , & V_10 -> V_17 ) ;
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_27 ) ) {
F_11 ( & F_12 ( V_10 ) ,
L_10 ,
V_2 -> V_28 ) ;
return - V_8 ;
}
F_16 ( V_10 -> V_29 , & V_2 -> V_6 ) ;
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_27 ) ) {
F_11 ( & F_12 ( V_10 ) ,
L_10 ,
V_2 -> V_28 ) ;
return - V_8 ;
}
F_16 ( V_10 -> V_29 , & V_2 -> V_6 ) ;
}
V_14 -> V_30 ( V_10 ) ;
return 0 ;
}
int F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_16 ( V_31 , & V_10 -> V_17 ) ;
if ( F_21 ( V_10 ) ) {
F_11 ( & F_12 ( V_10 ) , L_11 ) ;
return - V_8 ;
}
F_16 ( V_32 , & V_10 -> V_17 ) ;
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_33 ) ) {
F_11 ( & F_12 ( V_10 ) ,
L_12 ,
V_2 -> V_28 ) ;
return - V_8 ;
}
F_16 ( V_10 -> V_29 , & V_2 -> V_7 ) ;
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_33 ) ) {
F_11 ( & F_12 ( V_10 ) ,
L_12 ,
V_2 -> V_28 ) ;
return - V_8 ;
}
F_16 ( V_10 -> V_29 , & V_2 -> V_7 ) ;
}
F_22 ( V_31 , & V_10 -> V_17 ) ;
F_16 ( V_34 , & V_10 -> V_17 ) ;
if ( F_23 () ) {
F_11 ( & F_12 ( V_10 ) ,
L_13 ) ;
F_16 ( V_31 , & V_10 -> V_17 ) ;
F_22 ( V_34 , & V_10 -> V_17 ) ;
return - V_8 ;
}
return 0 ;
}
int F_24 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
bool V_35 = false ;
int V_36 ;
if ( ! F_25 ( V_10 ) &&
! F_13 ( V_31 , & V_10 -> V_17 ) ) {
return 0 ;
}
F_22 ( V_31 , & V_10 -> V_17 ) ;
F_22 ( V_34 , & V_10 -> V_17 ) ;
if ( F_26 () )
F_11 ( & F_12 ( V_10 ) ,
L_14 ) ;
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_25 )
continue;
if ( ! F_13 ( V_10 -> V_29 , & V_2 -> V_7 ) )
continue;
V_36 = V_2 -> V_26 ( V_10 , V_37 ) ;
if ( ! V_36 ) {
F_22 ( V_10 -> V_29 , & V_2 -> V_7 ) ;
} else if ( V_36 == - V_38 ) {
V_35 = true ;
F_22 ( V_10 -> V_29 , & V_2 -> V_7 ) ;
}
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_25 )
continue;
if ( ! F_13 ( V_10 -> V_29 , & V_2 -> V_7 ) )
continue;
if ( V_2 -> V_26 ( V_10 , V_37 ) )
F_11 ( & F_12 ( V_10 ) ,
L_15 ,
V_2 -> V_28 ) ;
else
F_22 ( V_10 -> V_29 , & V_2 -> V_7 ) ;
}
if ( V_35 )
F_27 ( 100 ) ;
if ( F_13 ( V_32 , & V_10 -> V_17 ) ) {
if ( F_28 ( V_10 ) )
F_11 ( & F_12 ( V_10 ) , L_16 ) ;
else
F_22 ( V_32 , & V_10 -> V_17 ) ;
}
return 0 ;
}
void F_29 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
if ( ! V_14 ) {
F_11 ( & F_12 ( V_10 ) ,
L_17 ) ;
return;
}
if ( F_13 ( V_22 , & V_10 -> V_17 ) ) {
F_30 ( V_10 ) ;
F_22 ( V_22 , & V_10 -> V_17 ) ;
}
if ( F_13 ( V_21 , & V_10 -> V_17 ) ) {
if ( F_31 ( V_10 ) )
F_11 ( & F_12 ( V_10 ) ,
L_18 ) ;
else
F_22 ( V_21 ,
& V_10 -> V_17 ) ;
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_25 )
continue;
if ( ! F_13 ( V_10 -> V_29 , & V_2 -> V_6 ) )
continue;
if ( V_2 -> V_26 ( V_10 , V_39 ) )
F_11 ( & F_12 ( V_10 ) ,
L_15 ,
V_2 -> V_28 ) ;
else
F_22 ( V_10 -> V_29 , & V_2 -> V_6 ) ;
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_25 )
continue;
if ( ! F_13 ( V_10 -> V_29 , & V_2 -> V_6 ) )
continue;
if ( V_2 -> V_26 ( V_10 , V_39 ) )
F_11 ( & F_12 ( V_10 ) ,
L_15 ,
V_2 -> V_28 ) ;
else
F_22 ( V_10 -> V_29 , & V_2 -> V_6 ) ;
}
if ( F_13 ( V_24 , & V_10 -> V_17 ) ) {
V_14 -> V_40 ( V_10 ) ;
F_22 ( V_24 , & V_10 -> V_17 ) ;
}
if ( ! F_13 ( V_41 , & V_10 -> V_17 ) )
F_32 ( V_10 ) ;
if ( V_14 -> V_42 )
V_14 -> V_42 ( V_10 ) ;
if ( V_14 -> V_43 )
V_14 -> V_43 ( V_10 ) ;
F_33 ( V_10 ) ;
}
int F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_44 ) )
F_11 ( & F_12 ( V_10 ) ,
L_19 ,
V_2 -> V_28 ) ;
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_44 ) )
F_11 ( & F_12 ( V_10 ) ,
L_19 ,
V_2 -> V_28 ) ;
}
return 0 ;
}
int F_35 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_45 ) )
F_11 ( & F_12 ( V_10 ) ,
L_19 ,
V_2 -> V_28 ) ;
}
F_18 (list_itr, &service_table) {
V_2 = F_19 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_25 )
continue;
if ( V_2 -> V_26 ( V_10 , V_45 ) )
F_11 ( & F_12 ( V_10 ) ,
L_19 ,
V_2 -> V_28 ) ;
}
return 0 ;
}
