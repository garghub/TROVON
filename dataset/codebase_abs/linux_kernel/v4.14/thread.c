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
V_1 -> V_18 = F_13 ( V_3 ) ;
}
return V_1 ;
V_14:
free ( V_1 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_1 )
{
struct V_19 * V_19 , * V_20 ;
struct V_9 * V_9 , * V_21 ;
F_15 ( ! F_16 ( & V_1 -> V_17 ) ) ;
F_17 ( V_1 ) ;
if ( V_1 -> V_6 ) {
F_18 ( V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
}
F_19 (namespaces, tmp_namespaces,
&thread->namespaces_list, list) {
F_20 ( & V_19 -> V_15 ) ;
F_21 ( V_19 ) ;
}
F_19 (comm, tmp_comm, &thread->comm_list, list) {
F_20 ( & V_9 -> V_15 ) ;
F_22 ( V_9 ) ;
}
F_23 ( V_1 ) ;
F_24 ( V_1 -> V_18 ) ;
free ( V_1 ) ;
}
struct V_1 * F_25 ( struct V_1 * V_1 )
{
if ( V_1 )
F_26 ( & V_1 -> V_16 ) ;
return V_1 ;
}
void F_5 ( struct V_1 * V_1 )
{
if ( V_1 && F_27 ( & V_1 -> V_16 ) ) {
F_28 ( & V_1 -> V_22 ) ;
F_14 ( V_1 ) ;
}
}
struct V_19 * F_29 ( const struct V_1 * V_1 )
{
if ( F_30 ( & V_1 -> V_12 ) )
return NULL ;
return F_31 ( & V_1 -> V_12 , struct V_19 , V_15 ) ;
}
int F_32 ( struct V_1 * V_1 , T_2 V_23 ,
struct V_24 * V_25 )
{
struct V_19 * V_26 , * V_27 = F_29 ( V_1 ) ;
V_26 = F_33 ( V_25 ) ;
if ( ! V_26 )
return - V_28 ;
F_10 ( & V_26 -> V_15 , & V_1 -> V_12 ) ;
if ( V_23 && V_27 ) {
V_27 = F_34 ( V_26 , V_15 ) ;
V_27 -> V_29 = V_23 ;
}
return 0 ;
}
struct V_9 * F_35 ( const struct V_1 * V_1 )
{
if ( F_30 ( & V_1 -> V_13 ) )
return NULL ;
return F_31 ( & V_1 -> V_13 , struct V_9 , V_15 ) ;
}
struct V_9 * F_36 ( const struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_30 = NULL ;
F_37 (comm, &thread->comm_list, list) {
if ( V_9 -> V_31 )
return V_9 ;
V_30 = V_9 ;
}
return V_30 ;
}
int F_38 ( struct V_1 * V_1 , const char * V_32 , T_2 V_23 ,
bool V_31 )
{
struct V_9 * V_26 , * V_27 = F_35 ( V_1 ) ;
if ( ! V_1 -> V_33 ) {
int V_34 = F_39 ( V_27 , V_32 , V_23 , V_31 ) ;
if ( V_34 )
return V_34 ;
} else {
V_26 = F_9 ( V_32 , V_23 , V_31 ) ;
if ( ! V_26 )
return - V_28 ;
F_10 ( & V_26 -> V_15 , & V_1 -> V_13 ) ;
if ( V_31 )
F_40 ( V_1 ) ;
}
V_1 -> V_33 = true ;
return 0 ;
}
int F_41 ( struct V_1 * V_1 )
{
char V_35 [ 64 ] ;
char * V_9 = NULL ;
T_3 V_36 ;
int V_34 = - 1 ;
if ( ! ( snprintf ( V_35 , sizeof( V_35 ) , L_2 ,
V_1 -> V_4 , V_1 -> V_5 ) >= ( int ) sizeof( V_35 ) ) &&
F_42 ( V_35 , & V_9 , & V_36 ) == 0 ) {
V_9 [ V_36 - 1 ] = '\0' ;
V_34 = F_43 ( V_1 , V_9 , 0 ) ;
}
return V_34 ;
}
const char * F_44 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_35 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_45 ( V_9 ) ;
}
int F_46 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_37 ) {
const char * V_9 = F_44 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_37 = strlen ( V_9 ) ;
}
return V_1 -> V_37 ;
}
T_3 F_47 ( struct V_1 * V_1 , T_4 * V_38 )
{
return fprintf ( V_38 , L_3 , V_1 -> V_5 , F_44 ( V_1 ) ) +
F_48 ( V_1 -> V_6 , V_38 ) ;
}
int F_49 ( struct V_1 * V_1 , struct V_39 * V_39 )
{
int V_40 ;
V_40 = F_50 ( V_1 , V_39 , NULL ) ;
if ( V_40 )
return V_40 ;
F_51 ( V_1 -> V_6 , V_39 , V_41 ) ;
F_52 ( V_1 -> V_6 , V_39 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 )
{
bool V_42 = false ;
int V_43 , V_34 = 0 ;
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 ) {
struct V_45 * V_45 = & V_1 -> V_6 -> V_45 [ V_43 ] ;
struct V_39 * V_39 ;
F_54 ( & V_45 -> V_46 ) ;
for ( V_39 = F_55 ( V_45 ) ; V_39 ; V_39 = F_56 ( V_39 ) ) {
V_34 = F_50 ( V_1 , V_39 , & V_42 ) ;
if ( V_34 || V_42 )
break;
}
F_57 ( & V_45 -> V_46 ) ;
}
return V_34 ;
}
static int F_58 ( struct V_1 * V_1 )
{
int V_34 = 0 ;
if ( V_47 . V_48 )
V_34 = F_53 ( V_1 ) ;
return V_34 ;
}
static int F_59 ( struct V_1 * V_1 ,
struct V_1 * V_49 )
{
int V_43 ;
if ( V_1 -> V_4 == V_49 -> V_4 )
return F_58 ( V_1 ) ;
if ( V_1 -> V_6 == V_49 -> V_6 ) {
F_60 ( L_4 ,
V_1 -> V_4 , V_1 -> V_5 , V_49 -> V_4 , V_49 -> V_5 ) ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_44 ; ++ V_43 )
if ( F_61 ( V_1 , V_49 -> V_6 , V_43 ) < 0 )
return - V_28 ;
return 0 ;
}
int F_62 ( struct V_1 * V_1 , struct V_1 * V_49 , T_2 V_23 )
{
if ( V_49 -> V_33 ) {
const char * V_9 = F_44 ( V_49 ) ;
int V_34 ;
if ( ! V_9 )
return - V_28 ;
V_34 = F_43 ( V_1 , V_9 , V_23 ) ;
if ( V_34 )
return V_34 ;
}
V_1 -> V_10 = V_49 -> V_5 ;
return F_59 ( V_1 , V_49 ) ;
}
void F_63 ( struct V_1 * V_1 ,
enum V_50 type , T_2 V_51 ,
struct V_52 * V_53 )
{
T_3 V_43 ;
const T_5 V_54 [] = {
V_55 ,
V_56 ,
V_57 ,
V_58
} ;
for ( V_43 = 0 ; V_43 < F_64 ( V_54 ) ; V_43 ++ ) {
F_65 ( V_1 , V_54 [ V_43 ] , type , V_51 , V_53 ) ;
if ( V_53 -> V_39 )
break;
}
}
struct V_1 * F_66 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
if ( V_1 -> V_4 == V_1 -> V_5 )
return F_25 ( V_1 ) ;
if ( V_1 -> V_4 == - 1 )
return NULL ;
return F_67 ( V_2 , V_1 -> V_4 , V_1 -> V_4 ) ;
}
