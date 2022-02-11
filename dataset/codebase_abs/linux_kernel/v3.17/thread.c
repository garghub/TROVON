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
V_8 = malloc ( 32 ) ;
if ( ! V_8 )
goto V_13;
snprintf ( V_8 , 32 , L_1 , V_6 ) ;
V_9 = F_8 ( V_8 , 0 ) ;
free ( V_8 ) ;
if ( ! V_9 )
goto V_13;
F_9 ( & V_9 -> V_14 , & V_1 -> V_12 ) ;
}
return V_1 ;
V_13:
free ( V_1 ) ;
return NULL ;
}
void F_10 ( struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_15 ;
if ( V_1 -> V_7 ) {
F_11 ( V_1 -> V_7 ) ;
V_1 -> V_7 = NULL ;
}
F_12 (comm, tmp, &thread->comm_list, list) {
F_13 ( & V_9 -> V_14 ) ;
F_14 ( V_9 ) ;
}
free ( V_1 ) ;
}
struct V_9 * F_15 ( const struct V_1 * V_1 )
{
if ( F_16 ( & V_1 -> V_12 ) )
return NULL ;
return F_17 ( & V_1 -> V_12 , struct V_9 , V_14 ) ;
}
int F_18 ( struct V_1 * V_1 , const char * V_16 , T_2 V_17 )
{
struct V_9 * V_18 , * V_19 = F_15 ( V_1 ) ;
int V_20 ;
if ( ! V_19 -> V_21 ) {
V_20 = F_19 ( V_19 , V_16 , V_17 ) ;
if ( V_20 )
return V_20 ;
} else {
V_18 = F_8 ( V_16 , V_17 ) ;
if ( ! V_18 )
return - V_22 ;
F_9 ( & V_18 -> V_14 , & V_1 -> V_12 ) ;
}
V_1 -> V_23 = true ;
return 0 ;
}
const char * F_20 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_15 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_21 ( V_9 ) ;
}
int F_22 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_24 ) {
const char * V_9 = F_20 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_24 = strlen ( V_9 ) ;
}
return V_1 -> V_24 ;
}
T_3 F_23 ( struct V_1 * V_1 , T_4 * V_25 )
{
return fprintf ( V_25 , L_2 , V_1 -> V_6 , F_20 ( V_1 ) ) +
F_24 ( V_1 -> V_7 , V_25 ) ;
}
void F_25 ( struct V_1 * V_1 , struct V_26 * V_26 )
{
F_26 ( V_1 -> V_7 , V_26 , V_27 ) ;
F_27 ( V_1 -> V_7 , V_26 ) ;
}
static int F_28 ( struct V_1 * V_1 ,
struct V_1 * V_28 )
{
int V_29 ;
if ( V_1 -> V_5 == V_28 -> V_5 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
if ( F_29 ( V_1 -> V_7 , V_28 -> V_7 , V_29 ) < 0 )
return - V_22 ;
return 0 ;
}
int F_30 ( struct V_1 * V_1 , struct V_1 * V_28 , T_2 V_17 )
{
int V_20 ;
if ( V_28 -> V_23 ) {
const char * V_9 = F_20 ( V_28 ) ;
if ( ! V_9 )
return - V_22 ;
V_20 = F_18 ( V_1 , V_9 , V_17 ) ;
if ( V_20 )
return V_20 ;
V_1 -> V_23 = true ;
}
V_1 -> V_10 = V_28 -> V_6 ;
return F_28 ( V_1 , V_28 ) ;
}
void F_31 ( struct V_1 * V_1 ,
struct V_2 * V_2 ,
enum V_31 type , T_2 V_32 ,
struct V_33 * V_34 )
{
T_3 V_29 ;
const T_5 const V_35 [] = {
V_36 ,
V_37 ,
V_38 ,
V_39
} ;
for ( V_29 = 0 ; V_29 < F_32 ( V_35 ) ; V_29 ++ ) {
F_33 ( V_1 , V_2 , V_35 [ V_29 ] , type ,
V_32 , V_34 ) ;
if ( V_34 -> V_26 )
break;
}
}
