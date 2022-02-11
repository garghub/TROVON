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
if ( ! F_11 ( V_16 , & V_10 -> V_17 ) ) {
F_12 ( L_2 ) ;
return - V_8 ;
}
F_13 ( V_18 , & V_10 -> V_17 ) ;
if ( F_14 ( V_10 ) ) {
F_9 ( L_3 ) ;
return - V_8 ;
}
F_13 ( V_19 , & V_10 -> V_17 ) ;
if ( F_15 ( V_10 ) ) {
F_9 ( L_4 ) ;
F_16 ( V_10 ) ;
return - V_8 ;
}
F_13 ( V_20 , & V_10 -> V_17 ) ;
if ( V_14 -> V_21 ( V_10 ) ) {
F_9 ( L_5 ) ;
return - V_8 ;
}
F_13 ( V_22 , & V_10 -> V_17 ) ;
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_25 ) ) {
F_9 ( L_6 ,
V_2 -> V_26 ) ;
return - V_8 ;
}
F_13 ( V_10 -> V_27 , & V_2 -> V_6 ) ;
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_25 ) ) {
F_9 ( L_6 ,
V_2 -> V_26 ) ;
return - V_8 ;
}
F_13 ( V_10 -> V_27 , & V_2 -> V_6 ) ;
}
V_14 -> V_28 ( V_10 ) ;
if ( F_19 ( V_10 ) ) {
F_9 ( L_7 ) ;
return - V_8 ;
}
F_13 ( V_29 , & V_10 -> V_17 ) ;
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_30 ) ) {
F_9 ( L_8 ,
V_2 -> V_26 ) ;
return - V_8 ;
}
F_13 ( V_10 -> V_27 , & V_2 -> V_7 ) ;
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_30 ) ) {
F_9 ( L_8 ,
V_2 -> V_26 ) ;
return - V_8 ;
}
F_13 ( V_10 -> V_27 , & V_2 -> V_7 ) ;
}
F_20 ( V_18 , & V_10 -> V_17 ) ;
F_13 ( V_31 , & V_10 -> V_17 ) ;
if ( F_21 () ) {
F_9 ( L_9 ) ;
F_13 ( V_18 , & V_10 -> V_17 ) ;
F_20 ( V_31 , & V_10 -> V_17 ) ;
return - V_8 ;
}
return 0 ;
}
int F_22 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int V_32 , V_33 = 0 ;
if ( ! F_23 ( V_10 ) &&
! F_11 ( V_18 , & V_10 -> V_17 ) ) {
return 0 ;
}
F_20 ( V_16 , & V_10 -> V_17 ) ;
F_20 ( V_18 , & V_10 -> V_17 ) ;
F_20 ( V_31 , & V_10 -> V_17 ) ;
if ( F_24 () )
F_9 ( L_10 ) ;
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_23 )
continue;
if ( ! F_11 ( V_10 -> V_27 , & V_2 -> V_7 ) )
continue;
V_32 = V_2 -> V_24 ( V_10 , V_34 ) ;
if ( ! V_32 ) {
F_20 ( V_10 -> V_27 , & V_2 -> V_7 ) ;
} else if ( V_32 == - V_35 ) {
V_33 = 1 ;
F_20 ( V_10 -> V_27 , & V_2 -> V_7 ) ;
}
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_23 )
continue;
if ( ! F_11 ( V_10 -> V_27 , & V_2 -> V_7 ) )
continue;
if ( V_2 -> V_24 ( V_10 , V_34 ) )
F_9 ( L_11 ,
V_2 -> V_26 ) ;
else
F_20 ( V_10 -> V_27 , & V_2 -> V_7 ) ;
}
if ( V_33 )
F_25 ( 100 ) ;
if ( F_23 ( V_10 ) ) {
if ( F_26 ( V_10 ) )
F_9 ( L_12 ) ;
else
F_20 ( V_29 , & V_10 -> V_17 ) ;
}
if ( F_11 ( V_20 , & V_10 -> V_17 ) ) {
if ( F_16 ( V_10 ) )
F_9 ( L_13 ) ;
else
F_20 ( V_20 ,
& V_10 -> V_17 ) ;
}
if ( F_11 ( V_19 , & V_10 -> V_17 ) ) {
if ( F_27 ( V_10 ) )
F_9 ( L_14 ) ;
else
F_20 ( V_19 ,
& V_10 -> V_17 ) ;
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_23 )
continue;
if ( ! F_11 ( V_10 -> V_27 , & V_2 -> V_6 ) )
continue;
if ( V_2 -> V_24 ( V_10 , V_36 ) )
F_9 ( L_11 ,
V_2 -> V_26 ) ;
else
F_20 ( V_10 -> V_27 , & V_2 -> V_6 ) ;
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_23 )
continue;
if ( ! F_11 ( V_10 -> V_27 , & V_2 -> V_6 ) )
continue;
if ( V_2 -> V_24 ( V_10 , V_36 ) )
F_9 ( L_11 ,
V_2 -> V_26 ) ;
else
F_20 ( V_10 -> V_27 , & V_2 -> V_6 ) ;
}
if ( F_11 ( V_22 , & V_10 -> V_17 ) ) {
V_14 -> V_37 ( V_10 ) ;
F_20 ( V_22 , & V_10 -> V_17 ) ;
}
if ( ! F_11 ( V_38 , & V_10 -> V_17 ) )
F_28 ( V_10 ) ;
return 0 ;
}
int F_29 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_39 ) )
F_9 ( L_15 ,
V_2 -> V_26 ) ;
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_39 ) )
F_9 ( L_15 ,
V_2 -> V_26 ) ;
}
return 0 ;
}
int F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_40 ) )
F_9 ( L_15 ,
V_2 -> V_26 ) ;
}
F_17 (list_itr, &service_table) {
V_2 = F_18 ( V_12 , struct V_1 , V_4 ) ;
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_24 ( V_10 , V_40 ) )
F_9 ( L_15 ,
V_2 -> V_26 ) ;
}
return 0 ;
}
