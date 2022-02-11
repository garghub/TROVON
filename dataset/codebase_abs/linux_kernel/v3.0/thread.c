static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 = F_2 ( sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
F_3 ( & V_3 -> V_4 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = malloc ( 32 ) ;
if ( V_3 -> V_5 )
snprintf ( V_3 -> V_5 , 32 , L_1 , V_3 -> V_2 ) ;
}
return V_3 ;
}
void F_4 ( struct V_1 * V_3 )
{
F_5 ( & V_3 -> V_4 ) ;
free ( V_3 -> V_5 ) ;
free ( V_3 ) ;
}
int F_6 ( struct V_1 * V_3 , const char * V_5 )
{
int V_6 ;
if ( V_3 -> V_5 )
free ( V_3 -> V_5 ) ;
V_3 -> V_5 = F_7 ( V_5 ) ;
V_6 = V_3 -> V_5 == NULL ? - V_7 : 0 ;
if ( ! V_6 ) {
V_3 -> V_8 = true ;
F_8 ( & V_3 -> V_4 ) ;
}
return V_6 ;
}
int F_9 ( struct V_1 * V_3 )
{
if ( ! V_3 -> V_9 ) {
if ( ! V_3 -> V_5 )
return 0 ;
V_3 -> V_9 = strlen ( V_3 -> V_5 ) ;
}
return V_3 -> V_9 ;
}
static T_2 F_10 ( struct V_1 * V_3 , T_3 * V_10 )
{
return fprintf ( V_10 , L_2 , V_3 -> V_2 , V_3 -> V_5 ) +
F_11 ( & V_3 -> V_4 , V_11 , V_10 ) ;
}
struct V_1 * F_12 ( struct V_12 * V_3 , T_1 V_2 )
{
struct V_13 * * V_14 = & V_3 -> V_15 . V_13 ;
struct V_13 * V_16 = NULL ;
struct V_1 * V_17 ;
if ( V_3 -> V_18 && V_3 -> V_18 -> V_2 == V_2 )
return V_3 -> V_18 ;
while ( * V_14 != NULL ) {
V_16 = * V_14 ;
V_17 = F_13 ( V_16 , struct V_1 , V_13 ) ;
if ( V_17 -> V_2 == V_2 ) {
V_3 -> V_18 = V_17 ;
return V_17 ;
}
if ( V_2 < V_17 -> V_2 )
V_14 = & ( * V_14 ) -> V_19 ;
else
V_14 = & ( * V_14 ) -> V_20 ;
}
V_17 = F_1 ( V_2 ) ;
if ( V_17 != NULL ) {
F_14 ( & V_17 -> V_13 , V_16 , V_14 ) ;
F_15 ( & V_17 -> V_13 , & V_3 -> V_15 ) ;
V_3 -> V_18 = V_17 ;
}
return V_17 ;
}
void F_16 ( struct V_1 * V_3 , struct V_21 * V_21 )
{
F_17 ( & V_3 -> V_4 , V_21 , V_11 , V_22 ) ;
F_18 ( & V_3 -> V_4 , V_21 ) ;
}
int F_19 ( struct V_1 * V_3 , struct V_1 * V_16 )
{
int V_23 ;
if ( V_16 -> V_8 ) {
if ( V_3 -> V_5 )
free ( V_3 -> V_5 ) ;
V_3 -> V_5 = F_7 ( V_16 -> V_5 ) ;
if ( ! V_3 -> V_5 )
return - V_7 ;
V_3 -> V_8 = true ;
}
for ( V_23 = 0 ; V_23 < V_24 ; ++ V_23 )
if ( F_20 ( & V_3 -> V_4 , & V_16 -> V_4 , V_23 ) < 0 )
return - V_7 ;
return 0 ;
}
T_2 F_21 ( struct V_12 * V_3 , T_3 * V_10 )
{
T_2 V_25 = 0 ;
struct V_13 * V_26 ;
for ( V_26 = F_22 ( & V_3 -> V_15 ) ; V_26 ; V_26 = F_23 ( V_26 ) ) {
struct V_1 * V_27 = F_13 ( V_26 , struct V_1 , V_13 ) ;
V_25 += F_10 ( V_27 , V_10 ) ;
}
return V_25 ;
}
