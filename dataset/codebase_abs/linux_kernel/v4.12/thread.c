int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
T_1 V_3 = V_1 -> V_4 ;
if ( V_3 == V_1 -> V_5 || V_3 == - 1 ) {
V_1 -> V_6 = F_2 ( V_2 ) ;
} else {
struct V_1 * V_7 = F_3 ( V_2 , V_3 , V_3 ) ;
if ( V_7 ) {
V_1 -> V_6 = F_4 ( V_7 -> V_6 ) ;
F_5 ( V_7 ) ;
}
}
return V_1 -> V_6 ? 0 : - 1 ;
}
struct V_1 * F_6 ( T_1 V_3 , T_1 V_5 )
{
char * V_8 ;
struct V_9 * V_9 ;
struct V_1 * V_1 = F_7 ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_10 = - 1 ;
V_1 -> V_11 = - 1 ;
F_8 ( & V_1 -> V_12 ) ;
F_8 ( & V_1 -> V_13 ) ;
V_8 = malloc ( 32 ) ;
if ( ! V_8 )
goto V_14;
snprintf ( V_8 , 32 , L_1 , V_5 ) ;
V_9 = F_9 ( V_8 , 0 , false ) ;
free ( V_8 ) ;
if ( ! V_9 )
goto V_14;
F_10 ( & V_9 -> V_15 , & V_1 -> V_13 ) ;
F_11 ( & V_1 -> V_16 , 1 ) ;
F_12 ( & V_1 -> V_17 ) ;
}
return V_1 ;
V_14:
free ( V_1 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_1 )
{
struct V_18 * V_18 , * V_19 ;
struct V_9 * V_9 , * V_20 ;
F_14 ( ! F_15 ( & V_1 -> V_17 ) ) ;
F_16 ( V_1 ) ;
if ( V_1 -> V_6 ) {
F_17 ( V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
}
F_18 (namespaces, tmp_namespaces,
&thread->namespaces_list, list) {
F_19 ( & V_18 -> V_15 ) ;
F_20 ( V_18 ) ;
}
F_18 (comm, tmp_comm, &thread->comm_list, list) {
F_19 ( & V_9 -> V_15 ) ;
F_21 ( V_9 ) ;
}
F_22 ( V_1 ) ;
free ( V_1 ) ;
}
struct V_1 * F_23 ( struct V_1 * V_1 )
{
if ( V_1 )
F_24 ( & V_1 -> V_16 ) ;
return V_1 ;
}
void F_5 ( struct V_1 * V_1 )
{
if ( V_1 && F_25 ( & V_1 -> V_16 ) ) {
F_26 ( & V_1 -> V_21 ) ;
F_13 ( V_1 ) ;
}
}
struct V_18 * F_27 ( const struct V_1 * V_1 )
{
if ( F_28 ( & V_1 -> V_12 ) )
return NULL ;
return F_29 ( & V_1 -> V_12 , struct V_18 , V_15 ) ;
}
int F_30 ( struct V_1 * V_1 , T_2 V_22 ,
struct V_23 * V_24 )
{
struct V_18 * V_25 , * V_26 = F_27 ( V_1 ) ;
V_25 = F_31 ( V_24 ) ;
if ( ! V_25 )
return - V_27 ;
F_10 ( & V_25 -> V_15 , & V_1 -> V_12 ) ;
if ( V_22 && V_26 ) {
V_26 = F_32 ( V_25 , V_15 ) ;
V_26 -> V_28 = V_22 ;
}
return 0 ;
}
struct V_9 * F_33 ( const struct V_1 * V_1 )
{
if ( F_28 ( & V_1 -> V_13 ) )
return NULL ;
return F_29 ( & V_1 -> V_13 , struct V_9 , V_15 ) ;
}
struct V_9 * F_34 ( const struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_29 = NULL ;
F_35 (comm, &thread->comm_list, list) {
if ( V_9 -> V_30 )
return V_9 ;
V_29 = V_9 ;
}
return V_29 ;
}
int F_36 ( struct V_1 * V_1 , const char * V_31 , T_2 V_22 ,
bool V_30 )
{
struct V_9 * V_25 , * V_26 = F_33 ( V_1 ) ;
if ( ! V_1 -> V_32 ) {
int V_33 = F_37 ( V_26 , V_31 , V_22 , V_30 ) ;
if ( V_33 )
return V_33 ;
} else {
V_25 = F_9 ( V_31 , V_22 , V_30 ) ;
if ( ! V_25 )
return - V_27 ;
F_10 ( & V_25 -> V_15 , & V_1 -> V_13 ) ;
if ( V_30 )
F_38 ( V_1 ) ;
}
V_1 -> V_32 = true ;
return 0 ;
}
int F_39 ( struct V_1 * V_1 )
{
char V_34 [ 64 ] ;
char * V_9 = NULL ;
T_3 V_35 ;
int V_33 = - 1 ;
if ( ! ( snprintf ( V_34 , sizeof( V_34 ) , L_2 ,
V_1 -> V_4 , V_1 -> V_5 ) >= ( int ) sizeof( V_34 ) ) &&
F_40 ( V_34 , & V_9 , & V_35 ) == 0 ) {
V_9 [ V_35 - 1 ] = '\0' ;
V_33 = F_41 ( V_1 , V_9 , 0 ) ;
}
return V_33 ;
}
const char * F_42 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_33 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_43 ( V_9 ) ;
}
int F_44 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_36 ) {
const char * V_9 = F_42 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_36 = strlen ( V_9 ) ;
}
return V_1 -> V_36 ;
}
T_3 F_45 ( struct V_1 * V_1 , T_4 * V_37 )
{
return fprintf ( V_37 , L_3 , V_1 -> V_5 , F_42 ( V_1 ) ) +
F_46 ( V_1 -> V_6 , V_37 ) ;
}
int F_47 ( struct V_1 * V_1 , struct V_38 * V_38 )
{
int V_39 ;
V_39 = F_48 ( V_1 , V_38 , NULL ) ;
if ( V_39 )
return V_39 ;
F_49 ( V_1 -> V_6 , V_38 , V_40 ) ;
F_50 ( V_1 -> V_6 , V_38 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 )
{
bool V_41 = false ;
int V_42 , V_33 = 0 ;
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 ) {
struct V_44 * V_44 = & V_1 -> V_6 -> V_44 [ V_42 ] ;
struct V_38 * V_38 ;
F_52 ( & V_44 -> V_45 ) ;
for ( V_38 = F_53 ( V_44 ) ; V_38 ; V_38 = F_54 ( V_38 ) ) {
V_33 = F_48 ( V_1 , V_38 , & V_41 ) ;
if ( V_33 || V_41 )
break;
}
F_55 ( & V_44 -> V_45 ) ;
}
return V_33 ;
}
static int F_56 ( struct V_1 * V_1 )
{
int V_33 = 0 ;
if ( V_46 . V_47 )
V_33 = F_51 ( V_1 ) ;
return V_33 ;
}
static int F_57 ( struct V_1 * V_1 ,
struct V_1 * V_48 )
{
int V_42 ;
if ( V_1 -> V_4 == V_48 -> V_4 )
return F_56 ( V_1 ) ;
if ( V_1 -> V_6 == V_48 -> V_6 ) {
F_58 ( L_4 ,
V_1 -> V_4 , V_1 -> V_5 , V_48 -> V_4 , V_48 -> V_5 ) ;
return 0 ;
}
for ( V_42 = 0 ; V_42 < V_43 ; ++ V_42 )
if ( F_59 ( V_1 , V_48 -> V_6 , V_42 ) < 0 )
return - V_27 ;
return 0 ;
}
int F_60 ( struct V_1 * V_1 , struct V_1 * V_48 , T_2 V_22 )
{
if ( V_48 -> V_32 ) {
const char * V_9 = F_42 ( V_48 ) ;
int V_33 ;
if ( ! V_9 )
return - V_27 ;
V_33 = F_41 ( V_1 , V_9 , V_22 ) ;
if ( V_33 )
return V_33 ;
}
V_1 -> V_10 = V_48 -> V_5 ;
return F_57 ( V_1 , V_48 ) ;
}
void F_61 ( struct V_1 * V_1 ,
enum V_49 type , T_2 V_50 ,
struct V_51 * V_52 )
{
T_3 V_42 ;
const T_5 V_53 [] = {
V_54 ,
V_55 ,
V_56 ,
V_57
} ;
for ( V_42 = 0 ; V_42 < F_62 ( V_53 ) ; V_42 ++ ) {
F_63 ( V_1 , V_53 [ V_42 ] , type , V_50 , V_52 ) ;
if ( V_52 -> V_38 )
break;
}
}
struct V_1 * F_64 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
if ( V_1 -> V_4 == V_1 -> V_5 )
return F_23 ( V_1 ) ;
if ( V_1 -> V_4 == - 1 )
return NULL ;
return F_65 ( V_2 , V_1 -> V_4 , V_1 -> V_4 ) ;
}
