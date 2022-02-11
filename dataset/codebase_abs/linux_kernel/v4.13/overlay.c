int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_8 V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_12 ; V_10 ++ ) {
struct V_13 * V_14 = & V_5 -> V_15 [ V_10 ] ;
V_9 . V_16 = V_14 -> V_16 ;
V_9 . V_17 = V_14 -> V_17 ;
V_11 = F_6 ( & V_3 ,
V_7 , & V_9 ) ;
if ( V_11 )
return F_7 ( V_11 ) ;
}
return 0 ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_18 * V_16 , struct V_19 * V_20 )
{
struct V_19 * V_21 , * V_22 ;
V_22 = F_9 ( V_16 , V_20 -> V_23 , NULL ) ;
if ( F_10 ( V_20 -> V_23 , L_1 ) == 0 ||
F_10 ( V_20 -> V_23 , L_2 ) == 0 ||
F_10 ( V_20 -> V_23 , L_3 ) == 0 )
return 0 ;
V_21 = F_11 ( V_20 , V_24 ) ;
if ( V_21 == NULL )
return - V_25 ;
if ( V_22 == NULL )
return F_12 ( & V_5 -> V_26 , V_16 , V_21 ) ;
return F_13 ( & V_5 -> V_26 , V_16 , V_21 ) ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_18 * V_16 , struct V_18 * V_27 )
{
const char * V_28 ;
struct V_18 * V_29 ;
int V_11 = 0 ;
V_28 = F_15 ( V_27 -> V_30 ) ;
if ( V_28 == NULL )
return - V_25 ;
V_29 = F_16 ( V_16 , V_28 ) ;
if ( V_29 != NULL ) {
if ( V_27 -> V_31 )
return - V_32 ;
V_11 = F_17 ( V_5 , V_29 , V_27 ) ;
F_18 ( V_29 ) ;
} else {
V_29 = F_19 ( V_27 , L_4 , V_16 -> V_30 , V_28 ) ;
if ( ! V_29 )
return - V_25 ;
V_29 -> V_33 = V_16 ;
V_11 = F_20 ( & V_5 -> V_26 , V_29 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_17 ( V_5 , V_29 , V_27 ) ;
if ( V_11 )
return V_11 ;
}
return V_11 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_18 * V_16 , const struct V_18 * V_17 )
{
struct V_18 * V_27 ;
struct V_19 * V_20 ;
int V_11 ;
F_21 (overlay, prop) {
V_11 = F_8 ( V_5 , V_16 , V_20 ) ;
if ( V_11 ) {
F_22 ( L_5 ,
V_16 -> V_30 , V_20 -> V_23 ) ;
return V_11 ;
}
}
F_23 (overlay, child) {
V_11 = F_14 ( V_5 , V_16 , V_27 ) ;
if ( V_11 != 0 ) {
F_22 ( L_6 ,
V_16 -> V_30 , V_27 -> V_23 ) ;
F_18 ( V_27 ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_10 , V_34 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_12 ; V_10 ++ ) {
struct V_13 * V_14 = & V_5 -> V_15 [ V_10 ] ;
V_34 = F_17 ( V_5 , V_14 -> V_16 , V_14 -> V_17 ) ;
if ( V_34 != 0 ) {
F_22 ( L_7 , V_14 -> V_16 -> V_30 ) ;
return V_34 ;
}
}
return 0 ;
}
static struct V_18 * F_25 ( struct V_18 * V_35 )
{
const char * V_36 ;
T_1 V_37 ;
int V_11 ;
V_11 = F_26 ( V_35 , L_8 , & V_37 ) ;
if ( V_11 == 0 )
return F_27 ( V_37 ) ;
V_11 = F_28 ( V_35 , L_9 , & V_36 ) ;
if ( V_11 == 0 )
return F_29 ( V_36 ) ;
F_22 ( L_10 ,
V_35 , V_35 -> V_23 ) ;
return NULL ;
}
static int F_30 ( struct V_4 * V_5 ,
struct V_18 * V_35 , struct V_13 * V_14 )
{
V_14 -> V_17 = F_16 ( V_35 , L_11 ) ;
if ( V_14 -> V_17 == NULL )
goto V_38;
V_14 -> V_16 = F_25 ( V_35 ) ;
if ( V_14 -> V_16 == NULL )
goto V_38;
return 0 ;
V_38:
F_18 ( V_14 -> V_16 ) ;
F_18 ( V_14 -> V_17 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
return - V_32 ;
}
static int F_31 ( struct V_4 * V_5 ,
struct V_18 * V_39 )
{
struct V_18 * V_40 ;
struct V_13 * V_14 ;
int V_41 , V_34 ;
V_41 = 0 ;
F_23 (tree, node)
V_41 ++ ;
V_14 = F_32 ( V_41 , sizeof( * V_14 ) , V_24 ) ;
if ( V_14 == NULL )
return - V_25 ;
V_41 = 0 ;
F_23 (tree, node) {
V_34 = F_30 ( V_5 , V_40 , & V_14 [ V_41 ] ) ;
if ( V_34 == 0 )
V_41 ++ ;
}
if ( V_41 == 0 ) {
F_33 ( V_14 ) ;
return - V_42 ;
}
V_5 -> V_12 = V_41 ;
V_5 -> V_15 = V_14 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_10 ;
for ( V_10 = V_5 -> V_12 - 1 ; V_10 >= 0 ; V_10 -- ) {
V_14 = & V_5 -> V_15 [ V_10 ] ;
F_18 ( V_14 -> V_16 ) ;
F_18 ( V_14 -> V_17 ) ;
}
F_33 ( V_5 -> V_15 ) ;
return 0 ;
}
int F_35 ( struct V_18 * V_39 )
{
struct V_4 * V_5 ;
int V_34 , V_43 ;
V_5 = F_36 ( sizeof( * V_5 ) , V_24 ) ;
if ( V_5 == NULL )
return - V_25 ;
V_5 -> V_43 = - 1 ;
F_37 ( & V_5 -> V_40 ) ;
F_38 ( & V_5 -> V_26 ) ;
F_39 ( & V_44 ) ;
V_43 = F_40 ( & V_45 , V_5 , 0 , 0 , V_24 ) ;
if ( V_43 < 0 ) {
V_34 = V_43 ;
goto V_46;
}
V_5 -> V_43 = V_43 ;
V_34 = F_31 ( V_5 , V_39 ) ;
if ( V_34 ) {
F_22 ( L_12 ,
V_39 -> V_30 ) ;
goto V_47;
}
V_34 = F_5 ( V_5 , V_48 ) ;
if ( V_34 < 0 ) {
F_22 ( L_13 ,
V_49 , V_34 ) ;
goto V_47;
}
V_34 = F_24 ( V_5 ) ;
if ( V_34 )
goto V_50;
V_34 = F_41 ( & V_5 -> V_26 ) ;
if ( V_34 )
goto V_51;
F_42 ( & V_5 -> V_40 , & V_52 ) ;
F_5 ( V_5 , V_53 ) ;
F_43 ( & V_44 ) ;
return V_43 ;
V_51:
V_50:
F_34 ( V_5 ) ;
V_47:
F_44 ( & V_45 , V_5 -> V_43 ) ;
V_46:
F_45 ( & V_5 -> V_26 ) ;
F_33 ( V_5 ) ;
F_43 ( & V_44 ) ;
return V_34 ;
}
static int F_46 ( struct V_18 * V_39 ,
struct V_18 * V_54 )
{
struct V_18 * V_27 ;
if ( V_39 == V_54 )
return 1 ;
F_23 (tree, child) {
if ( F_46 ( V_27 , V_54 ) ) {
F_18 ( V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , struct V_18 * V_54 )
{
struct V_4 * V_55 ;
struct V_56 * V_57 ;
F_48 (ovt, &ov_list, node) {
if ( V_55 == V_5 )
break;
F_49 (ce, &ovt->cset.entries, node) {
if ( F_46 ( V_57 -> V_58 , V_54 ) ) {
F_22 ( L_14 ,
V_49 , V_5 -> V_43 , V_55 -> V_43 ,
V_54 -> V_30 ) ;
return 0 ;
}
}
}
return 1 ;
}
static int F_50 ( struct V_4 * V_5 )
{
struct V_56 * V_57 ;
F_49 (ce, &ov->cset.entries, node) {
if ( ! F_47 ( V_5 , V_57 -> V_58 ) ) {
F_22 ( L_15 , V_5 -> V_43 ) ;
return 0 ;
}
}
return 1 ;
}
int F_51 ( int V_43 )
{
struct V_4 * V_5 ;
int V_34 ;
F_39 ( & V_44 ) ;
V_5 = F_52 ( & V_45 , V_43 ) ;
if ( V_5 == NULL ) {
V_34 = - V_42 ;
F_22 ( L_16 , V_43 ) ;
goto V_59;
}
if ( ! F_50 ( V_5 ) ) {
V_34 = - V_60 ;
goto V_59;
}
F_5 ( V_5 , V_61 ) ;
F_53 ( & V_5 -> V_40 ) ;
F_54 ( & V_5 -> V_26 ) ;
F_5 ( V_5 , V_62 ) ;
F_34 ( V_5 ) ;
F_44 ( & V_45 , V_43 ) ;
F_45 ( & V_5 -> V_26 ) ;
F_33 ( V_5 ) ;
V_34 = 0 ;
V_59:
F_43 ( & V_44 ) ;
return V_34 ;
}
int F_55 ( void )
{
struct V_4 * V_5 , * V_63 ;
F_39 ( & V_44 ) ;
F_56 (ov, ovn, &ov_list, node) {
F_53 ( & V_5 -> V_40 ) ;
F_54 ( & V_5 -> V_26 ) ;
F_34 ( V_5 ) ;
F_44 ( & V_45 , V_5 -> V_43 ) ;
F_33 ( V_5 ) ;
}
F_43 ( & V_44 ) ;
return 0 ;
}
