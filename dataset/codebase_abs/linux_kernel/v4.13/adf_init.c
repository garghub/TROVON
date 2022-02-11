static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
memset ( V_2 -> V_7 , 0 , sizeof( V_2 -> V_7 ) ) ;
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
int V_8 ;
for ( V_8 = 0 ; V_8 < F_9 ( V_2 -> V_6 ) ; V_8 ++ ) {
if ( V_2 -> V_6 [ V_8 ] || V_2 -> V_7 [ V_8 ] ) {
F_10 ( L_1 ) ;
return - V_9 ;
}
}
F_6 ( V_2 ) ;
return 0 ;
}
int F_11 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = V_11 -> V_16 ;
if ( ! V_15 ) {
F_12 ( & F_13 ( V_11 ) ,
L_2 ) ;
return - V_9 ;
}
if ( ! F_14 ( V_17 , & V_11 -> V_18 ) ) {
F_12 ( & F_13 ( V_11 ) , L_3 ) ;
return - V_9 ;
}
if ( F_15 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) , L_4 ) ;
return - V_9 ;
}
if ( V_15 -> V_19 && V_15 -> V_19 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) , L_5 ) ;
return - V_9 ;
}
if ( V_15 -> V_20 && V_15 -> V_20 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) , L_6 ) ;
return - V_9 ;
}
V_15 -> V_21 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) ,
L_7 ) ;
return - V_9 ;
}
F_17 ( V_22 , & V_11 -> V_18 ) ;
if ( F_18 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) ,
L_8 ) ;
return - V_9 ;
}
F_17 ( V_23 , & V_11 -> V_18 ) ;
if ( V_15 -> V_24 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) , L_9 ) ;
return - V_9 ;
}
F_17 ( V_25 , & V_11 -> V_18 ) ;
F_19 (list_itr, &service_table) {
V_2 = F_20 ( V_13 , struct V_1 , V_4 ) ;
if ( V_2 -> V_26 ( V_11 , V_27 ) ) {
F_12 ( & F_13 ( V_11 ) ,
L_10 ,
V_2 -> V_28 ) ;
return - V_9 ;
}
F_17 ( V_11 -> V_29 , V_2 -> V_6 ) ;
}
V_15 -> V_30 ( V_11 ) ;
V_15 -> V_31 ( V_11 ) ;
return 0 ;
}
int F_21 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
F_17 ( V_32 , & V_11 -> V_18 ) ;
if ( F_22 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) , L_11 ) ;
return - V_9 ;
}
F_17 ( V_33 , & V_11 -> V_18 ) ;
if ( V_15 -> V_34 ( V_11 ) ) {
F_12 ( & F_13 ( V_11 ) , L_12 ) ;
return - V_9 ;
}
F_19 (list_itr, &service_table) {
V_2 = F_20 ( V_13 , struct V_1 , V_4 ) ;
if ( V_2 -> V_26 ( V_11 , V_35 ) ) {
F_12 ( & F_13 ( V_11 ) ,
L_13 ,
V_2 -> V_28 ) ;
return - V_9 ;
}
F_17 ( V_11 -> V_29 , V_2 -> V_7 ) ;
}
F_23 ( V_32 , & V_11 -> V_18 ) ;
F_17 ( V_36 , & V_11 -> V_18 ) ;
if ( ! F_24 ( & V_11 -> V_37 ) &&
( F_25 () || F_26 () ) ) {
F_12 ( & F_13 ( V_11 ) ,
L_14 ) ;
F_17 ( V_32 , & V_11 -> V_18 ) ;
F_23 ( V_36 , & V_11 -> V_18 ) ;
return - V_9 ;
}
return 0 ;
}
void F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
bool V_38 = false ;
int V_39 ;
if ( ! F_28 ( V_11 ) &&
! F_14 ( V_32 , & V_11 -> V_18 ) )
return;
F_23 ( V_32 , & V_11 -> V_18 ) ;
F_23 ( V_36 , & V_11 -> V_18 ) ;
if ( ! F_24 ( & V_11 -> V_37 ) ) {
F_29 () ;
F_30 () ;
}
F_19 (list_itr, &service_table) {
V_2 = F_20 ( V_13 , struct V_1 , V_4 ) ;
if ( ! F_14 ( V_11 -> V_29 , V_2 -> V_7 ) )
continue;
V_39 = V_2 -> V_26 ( V_11 , V_40 ) ;
if ( ! V_39 ) {
F_23 ( V_11 -> V_29 , V_2 -> V_7 ) ;
} else if ( V_39 == - V_41 ) {
V_38 = true ;
F_23 ( V_11 -> V_29 , V_2 -> V_7 ) ;
}
}
if ( V_38 )
F_31 ( 100 ) ;
if ( F_14 ( V_33 , & V_11 -> V_18 ) ) {
if ( F_32 ( V_11 ) )
F_12 ( & F_13 ( V_11 ) , L_15 ) ;
else
F_23 ( V_33 , & V_11 -> V_18 ) ;
}
}
void F_33 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
if ( ! V_15 ) {
F_12 ( & F_13 ( V_11 ) ,
L_16 ) ;
return;
}
if ( F_14 ( V_23 , & V_11 -> V_18 ) ) {
F_34 ( V_11 ) ;
F_23 ( V_23 , & V_11 -> V_18 ) ;
}
if ( F_14 ( V_22 , & V_11 -> V_18 ) ) {
if ( F_35 ( V_11 ) )
F_12 ( & F_13 ( V_11 ) ,
L_17 ) ;
else
F_23 ( V_22 ,
& V_11 -> V_18 ) ;
}
F_19 (list_itr, &service_table) {
V_2 = F_20 ( V_13 , struct V_1 , V_4 ) ;
if ( ! F_14 ( V_11 -> V_29 , V_2 -> V_6 ) )
continue;
if ( V_2 -> V_26 ( V_11 , V_42 ) )
F_12 ( & F_13 ( V_11 ) ,
L_18 ,
V_2 -> V_28 ) ;
else
F_23 ( V_11 -> V_29 , V_2 -> V_6 ) ;
}
V_15 -> V_43 ( V_11 ) ;
if ( F_14 ( V_25 , & V_11 -> V_18 ) ) {
V_15 -> V_44 ( V_11 ) ;
F_23 ( V_25 , & V_11 -> V_18 ) ;
}
if ( ! F_14 ( V_45 , & V_11 -> V_18 ) )
F_36 ( V_11 ) ;
if ( V_15 -> V_46 )
V_15 -> V_46 ( V_11 ) ;
if ( V_15 -> V_47 )
V_15 -> V_47 ( V_11 ) ;
F_37 ( V_11 ) ;
F_38 ( V_11 ) ;
}
int F_39 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
F_19 (list_itr, &service_table) {
V_2 = F_20 ( V_13 , struct V_1 , V_4 ) ;
if ( V_2 -> V_26 ( V_11 , V_48 ) )
F_12 ( & F_13 ( V_11 ) ,
L_19 ,
V_2 -> V_28 ) ;
}
return 0 ;
}
int F_40 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
F_19 (list_itr, &service_table) {
V_2 = F_20 ( V_13 , struct V_1 , V_4 ) ;
if ( V_2 -> V_26 ( V_11 , V_49 ) )
F_12 ( & F_13 ( V_11 ) ,
L_19 ,
V_2 -> V_28 ) ;
}
return 0 ;
}
