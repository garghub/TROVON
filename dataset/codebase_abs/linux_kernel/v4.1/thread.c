int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 = V_1 -> V_5 ;
if ( V_4 == V_1 -> V_6 || V_4 == - 1 ) {
V_1 -> V_7 = F_2 ( V_2 ) ;
} else {
V_3 = F_3 ( V_2 , V_4 , V_4 ) ;
if ( V_3 )
V_1 -> V_7 = F_4 ( V_3 -> V_7 ) ;
}
return V_1 -> V_7 ? 0 : - 1 ;
}
struct V_1 * F_5 ( T_1 V_4 , T_1 V_6 )
{
char * V_8 ;
struct V_9 * V_9 ;
struct V_1 * V_1 = F_6 ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
V_1 -> V_5 = V_4 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_10 = - 1 ;
V_1 -> V_11 = - 1 ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_8 ( V_1 ) < 0 )
goto V_13;
V_8 = malloc ( 32 ) ;
if ( ! V_8 )
goto V_13;
snprintf ( V_8 , 32 , L_1 , V_6 ) ;
V_9 = F_9 ( V_8 , 0 , false ) ;
free ( V_8 ) ;
if ( ! V_9 )
goto V_13;
F_10 ( & V_9 -> V_14 , & V_1 -> V_12 ) ;
}
return V_1 ;
V_13:
free ( V_1 ) ;
return NULL ;
}
void F_11 ( struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_15 ;
F_12 ( V_1 ) ;
if ( V_1 -> V_7 ) {
F_13 ( V_1 -> V_7 ) ;
V_1 -> V_7 = NULL ;
}
F_14 (comm, tmp, &thread->comm_list, list) {
F_15 ( & V_9 -> V_14 ) ;
F_16 ( V_9 ) ;
}
F_17 ( V_1 ) ;
free ( V_1 ) ;
}
struct V_1 * F_18 ( struct V_1 * V_1 )
{
++ V_1 -> V_16 ;
return V_1 ;
}
void F_19 ( struct V_1 * V_1 )
{
if ( V_1 && -- V_1 -> V_16 == 0 ) {
F_20 ( & V_1 -> V_17 ) ;
F_11 ( V_1 ) ;
}
}
struct V_9 * F_21 ( const struct V_1 * V_1 )
{
if ( F_22 ( & V_1 -> V_12 ) )
return NULL ;
return F_23 ( & V_1 -> V_12 , struct V_9 , V_14 ) ;
}
struct V_9 * F_24 ( const struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_18 = NULL ;
F_25 (comm, &thread->comm_list, list) {
if ( V_9 -> V_19 )
return V_9 ;
V_18 = V_9 ;
}
return V_18 ;
}
int F_26 ( struct V_1 * V_1 , const char * V_20 , T_2 V_21 ,
bool V_19 )
{
struct V_9 * V_22 , * V_23 = F_21 ( V_1 ) ;
int V_24 ;
if ( ! V_1 -> V_25 ) {
V_24 = F_27 ( V_23 , V_20 , V_21 , V_19 ) ;
if ( V_24 )
return V_24 ;
} else {
V_22 = F_9 ( V_20 , V_21 , V_19 ) ;
if ( ! V_22 )
return - V_26 ;
F_10 ( & V_22 -> V_14 , & V_1 -> V_12 ) ;
if ( V_19 )
F_28 ( V_1 ) ;
}
V_1 -> V_25 = true ;
return 0 ;
}
const char * F_29 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_21 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_30 ( V_9 ) ;
}
int F_31 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_27 ) {
const char * V_9 = F_29 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_27 = strlen ( V_9 ) ;
}
return V_1 -> V_27 ;
}
T_3 F_32 ( struct V_1 * V_1 , T_4 * V_28 )
{
return fprintf ( V_28 , L_2 , V_1 -> V_6 , F_29 ( V_1 ) ) +
F_33 ( V_1 -> V_7 , V_28 ) ;
}
void F_34 ( struct V_1 * V_1 , struct V_29 * V_29 )
{
F_35 ( V_1 -> V_7 , V_29 , V_30 ) ;
F_36 ( V_1 -> V_7 , V_29 ) ;
}
static int F_37 ( struct V_1 * V_1 ,
struct V_1 * V_31 )
{
int V_32 ;
if ( V_1 -> V_5 == V_31 -> V_5 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 )
if ( F_38 ( V_1 -> V_7 , V_31 -> V_7 , V_32 ) < 0 )
return - V_26 ;
return 0 ;
}
int F_39 ( struct V_1 * V_1 , struct V_1 * V_31 , T_2 V_21 )
{
int V_24 ;
if ( V_31 -> V_25 ) {
const char * V_9 = F_29 ( V_31 ) ;
if ( ! V_9 )
return - V_26 ;
V_24 = F_40 ( V_1 , V_9 , V_21 ) ;
if ( V_24 )
return V_24 ;
}
V_1 -> V_10 = V_31 -> V_6 ;
return F_37 ( V_1 , V_31 ) ;
}
void F_41 ( struct V_1 * V_1 ,
enum V_34 type , T_2 V_35 ,
struct V_36 * V_37 )
{
T_3 V_32 ;
const T_5 const V_38 [] = {
V_39 ,
V_40 ,
V_41 ,
V_42
} ;
for ( V_32 = 0 ; V_32 < F_42 ( V_38 ) ; V_32 ++ ) {
F_43 ( V_1 , V_38 [ V_32 ] , type , V_35 , V_37 ) ;
if ( V_37 -> V_29 )
break;
}
}
