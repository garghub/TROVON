int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 = V_1 -> V_5 ;
if ( V_4 == V_1 -> V_6 || V_4 == - 1 ) {
V_1 -> V_7 = F_2 ( V_2 ) ;
} else {
V_3 = F_3 ( V_2 , V_4 , V_4 ) ;
if ( V_3 ) {
V_1 -> V_7 = F_4 ( V_3 -> V_7 ) ;
F_5 ( V_3 ) ;
}
}
return V_1 -> V_7 ? 0 : - 1 ;
}
struct V_1 * F_6 ( T_1 V_4 , T_1 V_6 )
{
char * V_8 ;
struct V_9 * V_9 ;
struct V_1 * V_1 = F_7 ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
V_1 -> V_5 = V_4 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_10 = - 1 ;
V_1 -> V_11 = - 1 ;
F_8 ( & V_1 -> V_12 ) ;
if ( F_9 ( V_1 ) < 0 )
goto V_13;
V_8 = malloc ( 32 ) ;
if ( ! V_8 )
goto V_13;
snprintf ( V_8 , 32 , L_1 , V_6 ) ;
V_9 = F_10 ( V_8 , 0 , false ) ;
free ( V_8 ) ;
if ( ! V_9 )
goto V_13;
F_11 ( & V_9 -> V_14 , & V_1 -> V_12 ) ;
F_12 ( & V_1 -> V_15 , 1 ) ;
F_13 ( & V_1 -> V_16 ) ;
}
return V_1 ;
V_13:
free ( V_1 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_17 ;
F_15 ( ! F_16 ( & V_1 -> V_16 ) ) ;
F_17 ( V_1 ) ;
if ( V_1 -> V_7 ) {
F_18 ( V_1 -> V_7 ) ;
V_1 -> V_7 = NULL ;
}
F_19 (comm, tmp, &thread->comm_list, list) {
F_20 ( & V_9 -> V_14 ) ;
F_21 ( V_9 ) ;
}
F_22 ( V_1 ) ;
free ( V_1 ) ;
}
struct V_1 * F_23 ( struct V_1 * V_1 )
{
if ( V_1 )
F_24 ( & V_1 -> V_15 ) ;
return V_1 ;
}
void F_5 ( struct V_1 * V_1 )
{
if ( V_1 && F_25 ( & V_1 -> V_15 ) ) {
F_26 ( & V_1 -> V_18 ) ;
F_14 ( V_1 ) ;
}
}
struct V_9 * F_27 ( const struct V_1 * V_1 )
{
if ( F_28 ( & V_1 -> V_12 ) )
return NULL ;
return F_29 ( & V_1 -> V_12 , struct V_9 , V_14 ) ;
}
struct V_9 * F_30 ( const struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_19 = NULL ;
F_31 (comm, &thread->comm_list, list) {
if ( V_9 -> V_20 )
return V_9 ;
V_19 = V_9 ;
}
return V_19 ;
}
int F_32 ( struct V_1 * V_1 , const char * V_21 , T_2 V_22 ,
bool V_20 )
{
struct V_9 * V_23 , * V_24 = F_27 ( V_1 ) ;
int V_25 ;
if ( ! V_1 -> V_26 ) {
V_25 = F_33 ( V_24 , V_21 , V_22 , V_20 ) ;
if ( V_25 )
return V_25 ;
} else {
V_23 = F_10 ( V_21 , V_22 , V_20 ) ;
if ( ! V_23 )
return - V_27 ;
F_11 ( & V_23 -> V_14 , & V_1 -> V_12 ) ;
if ( V_20 )
F_34 ( V_1 ) ;
}
V_1 -> V_26 = true ;
return 0 ;
}
const char * F_35 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_27 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_36 ( V_9 ) ;
}
int F_37 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_28 ) {
const char * V_9 = F_35 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_28 = strlen ( V_9 ) ;
}
return V_1 -> V_28 ;
}
T_3 F_38 ( struct V_1 * V_1 , T_4 * V_29 )
{
return fprintf ( V_29 , L_2 , V_1 -> V_6 , F_35 ( V_1 ) ) +
F_39 ( V_1 -> V_7 , V_29 ) ;
}
void F_40 ( struct V_1 * V_1 , struct V_30 * V_30 )
{
F_41 ( V_1 -> V_7 , V_30 , V_31 ) ;
F_42 ( V_1 -> V_7 , V_30 ) ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_1 * V_32 )
{
int V_33 ;
if ( V_1 -> V_5 == V_32 -> V_5 )
return 0 ;
if ( V_1 -> V_7 == V_32 -> V_7 ) {
F_44 ( L_3 ,
V_1 -> V_5 , V_1 -> V_6 , V_32 -> V_5 , V_32 -> V_6 ) ;
return 0 ;
}
for ( V_33 = 0 ; V_33 < V_34 ; ++ V_33 )
if ( F_45 ( V_1 -> V_7 , V_32 -> V_7 , V_33 ) < 0 )
return - V_27 ;
return 0 ;
}
int F_46 ( struct V_1 * V_1 , struct V_1 * V_32 , T_2 V_22 )
{
int V_25 ;
if ( V_32 -> V_26 ) {
const char * V_9 = F_35 ( V_32 ) ;
if ( ! V_9 )
return - V_27 ;
V_25 = F_47 ( V_1 , V_9 , V_22 ) ;
if ( V_25 )
return V_25 ;
}
V_1 -> V_10 = V_32 -> V_6 ;
return F_43 ( V_1 , V_32 ) ;
}
void F_48 ( struct V_1 * V_1 ,
enum V_35 type , T_2 V_36 ,
struct V_37 * V_38 )
{
T_3 V_33 ;
const T_5 const V_39 [] = {
V_40 ,
V_41 ,
V_42 ,
V_43
} ;
for ( V_33 = 0 ; V_33 < F_49 ( V_39 ) ; V_33 ++ ) {
F_50 ( V_1 , V_39 [ V_33 ] , type , V_36 , V_38 ) ;
if ( V_38 -> V_30 )
break;
}
}
