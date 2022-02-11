int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 = V_1 -> V_5 ;
if ( V_4 == V_1 -> V_6 || V_4 == - 1 ) {
V_1 -> V_7 = F_2 () ;
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
if ( V_1 -> V_7 ) {
F_12 ( V_1 -> V_7 ) ;
V_1 -> V_7 = NULL ;
}
F_13 (comm, tmp, &thread->comm_list, list) {
F_14 ( & V_9 -> V_14 ) ;
F_15 ( V_9 ) ;
}
F_16 ( V_1 ) ;
free ( V_1 ) ;
}
struct V_9 * F_17 ( const struct V_1 * V_1 )
{
if ( F_18 ( & V_1 -> V_12 ) )
return NULL ;
return F_19 ( & V_1 -> V_12 , struct V_9 , V_14 ) ;
}
struct V_9 * F_20 ( const struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_16 = NULL ;
F_21 (comm, &thread->comm_list, list) {
if ( V_9 -> V_17 )
return V_9 ;
V_16 = V_9 ;
}
return V_16 ;
}
int F_22 ( struct V_1 * V_1 , const char * V_18 , T_2 V_19 ,
bool V_17 )
{
struct V_9 * V_20 , * V_21 = F_17 ( V_1 ) ;
int V_22 ;
if ( ! V_21 -> V_23 && ! V_21 -> V_17 ) {
V_22 = F_23 ( V_21 , V_18 , V_19 , V_17 ) ;
if ( V_22 )
return V_22 ;
} else {
V_20 = F_9 ( V_18 , V_19 , V_17 ) ;
if ( ! V_20 )
return - V_24 ;
F_10 ( & V_20 -> V_14 , & V_1 -> V_12 ) ;
if ( V_17 )
F_24 ( V_1 ) ;
}
V_1 -> V_25 = true ;
return 0 ;
}
const char * F_25 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_17 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_26 ( V_9 ) ;
}
int F_27 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_26 ) {
const char * V_9 = F_25 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_26 = strlen ( V_9 ) ;
}
return V_1 -> V_26 ;
}
T_3 F_28 ( struct V_1 * V_1 , T_4 * V_27 )
{
return fprintf ( V_27 , L_2 , V_1 -> V_6 , F_25 ( V_1 ) ) +
F_29 ( V_1 -> V_7 , V_27 ) ;
}
void F_30 ( struct V_1 * V_1 , struct V_28 * V_28 )
{
F_31 ( V_1 -> V_7 , V_28 , V_29 ) ;
F_32 ( V_1 -> V_7 , V_28 ) ;
}
static int F_33 ( struct V_1 * V_1 ,
struct V_1 * V_30 )
{
int V_31 ;
if ( V_1 -> V_5 == V_30 -> V_5 )
return 0 ;
for ( V_31 = 0 ; V_31 < V_32 ; ++ V_31 )
if ( F_34 ( V_1 -> V_7 , V_30 -> V_7 , V_31 ) < 0 )
return - V_24 ;
return 0 ;
}
int F_35 ( struct V_1 * V_1 , struct V_1 * V_30 , T_2 V_19 )
{
int V_22 ;
if ( V_30 -> V_25 ) {
const char * V_9 = F_25 ( V_30 ) ;
if ( ! V_9 )
return - V_24 ;
V_22 = F_36 ( V_1 , V_9 , V_19 ) ;
if ( V_22 )
return V_22 ;
V_1 -> V_25 = true ;
}
V_1 -> V_10 = V_30 -> V_6 ;
return F_33 ( V_1 , V_30 ) ;
}
void F_37 ( struct V_1 * V_1 ,
struct V_2 * V_2 ,
enum V_33 type , T_2 V_34 ,
struct V_35 * V_36 )
{
T_3 V_31 ;
const T_5 const V_37 [] = {
V_38 ,
V_39 ,
V_40 ,
V_41
} ;
for ( V_31 = 0 ; V_31 < F_38 ( V_37 ) ; V_31 ++ ) {
F_39 ( V_1 , V_2 , V_37 [ V_31 ] , type ,
V_34 , V_36 ) ;
if ( V_36 -> V_28 )
break;
}
}
