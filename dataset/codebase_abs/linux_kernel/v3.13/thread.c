struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 )
{
char * V_4 ;
struct V_5 * V_5 ;
struct V_1 * V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
F_3 ( & V_1 -> V_6 ) ;
V_1 -> V_7 = V_2 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_8 = - 1 ;
F_4 ( & V_1 -> V_9 ) ;
V_4 = malloc ( 32 ) ;
if ( ! V_4 )
goto V_10;
snprintf ( V_4 , 32 , L_1 , V_3 ) ;
V_5 = F_5 ( V_4 , 0 ) ;
free ( V_4 ) ;
if ( ! V_5 )
goto V_10;
F_6 ( & V_5 -> V_11 , & V_1 -> V_9 ) ;
}
return V_1 ;
V_10:
free ( V_1 ) ;
return NULL ;
}
void F_7 ( struct V_1 * V_1 )
{
struct V_5 * V_5 , * V_12 ;
F_8 ( & V_1 -> V_6 ) ;
F_9 (comm, tmp, &thread->comm_list, list) {
F_10 ( & V_5 -> V_11 ) ;
F_11 ( V_5 ) ;
}
free ( V_1 ) ;
}
struct V_5 * F_12 ( const struct V_1 * V_1 )
{
if ( F_13 ( & V_1 -> V_9 ) )
return NULL ;
return F_14 ( & V_1 -> V_9 , struct V_5 , V_11 ) ;
}
int F_15 ( struct V_1 * V_1 , const char * V_13 , T_2 V_14 )
{
struct V_5 * V_15 , * V_16 = F_12 ( V_1 ) ;
if ( ! V_16 -> V_17 ) {
F_16 ( V_16 , V_13 , V_14 ) ;
} else {
V_15 = F_5 ( V_13 , V_14 ) ;
if ( ! V_15 )
return - V_18 ;
F_6 ( & V_15 -> V_11 , & V_1 -> V_9 ) ;
}
V_1 -> V_19 = true ;
return 0 ;
}
const char * F_17 ( const struct V_1 * V_1 )
{
const struct V_5 * V_5 = F_12 ( V_1 ) ;
if ( ! V_5 )
return NULL ;
return F_18 ( V_5 ) ;
}
int F_19 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_20 ) {
const char * V_5 = F_17 ( V_1 ) ;
if ( ! V_5 )
return 0 ;
V_1 -> V_20 = strlen ( V_5 ) ;
}
return V_1 -> V_20 ;
}
T_3 F_20 ( struct V_1 * V_1 , T_4 * V_21 )
{
return fprintf ( V_21 , L_2 , V_1 -> V_3 , F_17 ( V_1 ) ) +
F_21 ( & V_1 -> V_6 , V_22 , V_21 ) ;
}
void F_22 ( struct V_1 * V_1 , struct V_23 * V_23 )
{
F_23 ( & V_1 -> V_6 , V_23 , V_22 , V_24 ) ;
F_24 ( & V_1 -> V_6 , V_23 ) ;
}
int F_25 ( struct V_1 * V_1 , struct V_1 * V_25 , T_2 V_14 )
{
int V_26 , V_27 ;
if ( V_25 -> V_19 ) {
const char * V_5 = F_17 ( V_25 ) ;
if ( ! V_5 )
return - V_18 ;
V_27 = F_15 ( V_1 , V_5 , V_14 ) ;
if ( ! V_27 )
return V_27 ;
V_1 -> V_19 = true ;
}
for ( V_26 = 0 ; V_26 < V_28 ; ++ V_26 )
if ( F_26 ( & V_1 -> V_6 , & V_25 -> V_6 , V_26 ) < 0 )
return - V_18 ;
V_1 -> V_8 = V_25 -> V_3 ;
return 0 ;
}
