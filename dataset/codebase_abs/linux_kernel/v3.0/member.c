static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_5 = NULL ;
struct V_6 * V_7 ;
struct V_6 * V_8 = & V_4 -> V_9 ;
struct V_6 * V_10 = & V_2 -> V_11 ;
F_2 (tmp, head) {
V_5 = F_3 ( V_7 , struct V_3 , V_9 ) ;
if ( V_4 -> V_12 < V_5 -> V_12 )
break;
}
if ( ! V_5 )
F_4 ( V_8 , V_10 ) ;
else {
V_8 -> V_13 = V_7 -> V_13 ;
V_8 -> V_14 = V_7 ;
V_7 -> V_13 -> V_14 = V_8 ;
V_7 -> V_13 = V_8 ;
}
}
static int F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_5 ;
int V_15 , error ;
V_5 = F_6 ( sizeof( struct V_3 ) , V_16 ) ;
if ( ! V_5 )
return - V_17 ;
V_15 = F_7 ( V_2 -> V_18 , V_12 ) ;
if ( V_15 < 0 ) {
F_8 ( V_5 ) ;
return V_15 ;
}
error = F_9 ( V_12 ) ;
if ( error < 0 ) {
F_8 ( V_5 ) ;
return error ;
}
V_5 -> V_12 = V_12 ;
V_5 -> V_19 = V_15 ;
F_1 ( V_2 , V_5 ) ;
V_2 -> V_20 ++ ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_5 )
{
F_11 ( & V_5 -> V_9 , & V_2 -> V_21 ) ;
V_2 -> V_20 -- ;
}
int F_12 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_5 ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_5 -> V_12 == V_12 )
return 1 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_5 ;
F_13 (memb, &ls->ls_nodes_gone, list) {
if ( V_5 -> V_12 == V_12 )
return 1 ;
}
return 0 ;
}
static void F_15 ( struct V_6 * V_10 )
{
struct V_3 * V_5 ;
while ( ! F_16 ( V_10 ) ) {
V_5 = F_3 ( V_10 -> V_14 , struct V_3 , V_9 ) ;
F_17 ( & V_5 -> V_9 ) ;
F_8 ( V_5 ) ;
}
}
void F_18 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_11 ) ;
V_2 -> V_20 = 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_21 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
int V_22 , V_15 , V_23 = 0 , V_24 = 0 , V_25 = 0 , * V_26 ;
F_8 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
F_13 (memb, &ls->ls_nodes, list) {
if ( V_5 -> V_19 )
V_24 += V_5 -> V_19 ;
}
if ( ! V_24 ) {
V_24 = V_2 -> V_20 ;
V_25 = 1 ;
}
V_2 -> V_28 = V_24 ;
V_26 = F_21 ( sizeof( int ) * V_24 , V_16 ) ;
if ( ! V_26 )
return;
F_13 (memb, &ls->ls_nodes, list) {
if ( ! V_25 && ! V_5 -> V_19 )
continue;
if ( V_25 )
V_15 = 1 ;
else
V_15 = V_5 -> V_19 ;
F_22 (x < total, printk(L_1, total, x);) ;
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ )
V_26 [ V_23 ++ ] = V_5 -> V_12 ;
}
V_2 -> V_27 = V_26 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
int error = 0 ;
F_13 (memb, &ls->ls_nodes, list) {
error = F_24 ( V_2 ) ;
if ( error )
break;
error = F_25 ( V_2 , V_5 -> V_12 ) ;
if ( error )
break;
}
if ( error )
F_26 ( V_2 , L_2 ,
error , V_2 -> V_29 ) ;
return error ;
}
int F_27 ( struct V_1 * V_2 , struct V_30 * V_31 , int * V_32 )
{
struct V_3 * V_5 , * V_33 ;
int V_22 , error , V_34 , V_35 = 0 , V_36 = 0 , V_37 = - 1 ;
F_13 (memb, &ls->ls_nodes_gone, list) {
F_26 ( V_2 , L_3 , V_5 -> V_12 ) ;
V_36 ++ ;
}
F_28 (memb, safe, &ls->ls_nodes, list) {
V_34 = 0 ;
for ( V_22 = 0 ; V_22 < V_31 -> V_38 ; V_22 ++ ) {
if ( V_5 -> V_12 == V_31 -> V_39 [ V_22 ] ) {
V_34 = 1 ;
break;
}
}
if ( ! V_34 ) {
V_36 ++ ;
F_10 ( V_2 , V_5 ) ;
F_26 ( V_2 , L_4 , V_5 -> V_12 ) ;
}
}
for ( V_22 = 0 ; V_22 < V_31 -> V_40 ; V_22 ++ ) {
if ( ! F_12 ( V_2 , V_31 -> V_4 [ V_22 ] ) )
continue;
F_26 ( V_2 , L_5 , V_31 -> V_4 [ V_22 ] ) ;
V_5 = F_6 ( sizeof( struct V_3 ) , V_16 ) ;
if ( ! V_5 )
return - V_17 ;
V_5 -> V_12 = V_31 -> V_4 [ V_22 ] ;
F_4 ( & V_5 -> V_9 , & V_2 -> V_21 ) ;
V_36 ++ ;
}
for ( V_22 = 0 ; V_22 < V_31 -> V_38 ; V_22 ++ ) {
if ( F_12 ( V_2 , V_31 -> V_39 [ V_22 ] ) )
continue;
F_5 ( V_2 , V_31 -> V_39 [ V_22 ] ) ;
V_35 ++ ;
F_26 ( V_2 , L_6 , V_31 -> V_39 [ V_22 ] ) ;
}
F_13 (memb, &ls->ls_nodes, list) {
if ( V_37 == - 1 || V_5 -> V_12 < V_37 )
V_37 = V_5 -> V_12 ;
}
V_2 -> V_41 = V_37 ;
F_20 ( V_2 ) ;
F_29 ( V_2 , V_42 ) ;
* V_32 = V_36 ;
error = F_23 ( V_2 ) ;
if ( ! error || error == - V_43 ) {
V_2 -> V_44 = error ;
F_30 ( & V_2 -> V_45 ) ;
}
if ( error )
goto V_46;
error = F_31 ( V_2 ) ;
V_46:
F_26 ( V_2 , L_7 , V_2 -> V_20 , error ) ;
return error ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_4 ;
F_33 ( & V_2 -> V_47 ) ;
F_34 ( & V_2 -> V_48 ) ;
F_35 ( V_49 , & V_2 -> V_50 ) ;
V_4 = F_36 ( V_51 , & V_2 -> V_50 ) ;
V_2 -> V_52 ++ ;
F_37 ( & V_2 -> V_48 ) ;
F_38 ( & V_2 -> V_47 ) ;
if ( V_4 )
F_33 ( & V_2 -> V_53 ) ;
F_39 ( V_2 ) ;
V_2 -> V_54 = 0 ;
F_40 ( V_2 ) ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = V_56 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = NULL , * V_57 ;
int * V_58 = NULL , * V_4 = NULL ;
int error , V_59 = 0 , V_40 = 0 ;
V_31 = F_6 ( sizeof( struct V_30 ) , V_16 ) ;
if ( ! V_31 )
return - V_17 ;
error = F_42 ( V_2 -> V_18 , & V_58 , & V_59 ,
& V_4 , & V_40 ) ;
if ( error < 0 )
goto V_60;
F_34 ( & V_2 -> V_48 ) ;
if ( ! F_43 ( V_2 ) ) {
F_37 ( & V_2 -> V_48 ) ;
F_44 ( V_2 , L_8 ) ;
error = - V_61 ;
goto V_60;
}
V_31 -> V_39 = V_58 ;
V_31 -> V_38 = V_59 ;
V_31 -> V_4 = V_4 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_62 = ++ V_2 -> V_52 ;
V_57 = V_2 -> V_63 ;
V_2 -> V_63 = V_31 ;
F_37 ( & V_2 -> V_48 ) ;
if ( V_57 ) {
F_44 ( V_2 , L_9 ,
( unsigned long long ) V_57 -> V_62 , V_57 -> V_38 ) ;
F_8 ( V_57 -> V_39 ) ;
F_8 ( V_57 -> V_4 ) ;
F_8 ( V_57 ) ;
}
F_45 ( V_2 ) ;
return 0 ;
V_60:
F_8 ( V_31 ) ;
F_8 ( V_58 ) ;
F_8 ( V_4 ) ;
return error ;
}
