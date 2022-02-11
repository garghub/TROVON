static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_6 )
return 0 ;
if ( V_4 -> V_7 )
F_2 ( V_4 -> V_6 ) ;
else
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 , * V_12 ;
F_5 (jack_kctl, tmp_jack_kctl, &jack->kctl_list, list) {
F_6 ( & V_11 -> V_13 ) ;
F_7 ( V_9 , V_11 -> V_14 ) ;
}
if ( V_4 -> V_15 )
V_4 -> V_15 ( V_4 ) ;
F_1 ( V_2 ) ;
F_8 ( V_4 -> V_16 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_17 , V_18 ;
snprintf ( V_4 -> V_19 , sizeof( V_4 -> V_19 ) , L_1 ,
V_9 -> V_20 , V_4 -> V_16 ) ;
if ( ! V_4 -> V_6 )
return 0 ;
V_4 -> V_6 -> V_19 = V_4 -> V_19 ;
if ( ! V_4 -> V_6 -> V_21 . V_22 )
V_4 -> V_6 -> V_21 . V_22 = F_10 ( V_9 ) ;
for ( V_18 = 0 ; V_18 < F_11 ( V_4 -> V_23 ) ; V_18 ++ ) {
int V_24 = V_25 >> V_18 ;
if ( ! ( V_4 -> type & V_24 ) )
continue;
if ( ! V_4 -> V_23 [ V_18 ] )
V_4 -> V_23 [ V_18 ] = V_26 + V_18 ;
F_12 ( V_4 -> V_6 , V_27 , V_4 -> V_23 [ V_18 ] ) ;
}
V_17 = F_13 ( V_4 -> V_6 ) ;
if ( V_17 == 0 )
V_4 -> V_7 = 1 ;
return V_17 ;
}
static void F_14 ( struct V_28 * V_14 )
{
struct V_10 * V_11 ;
V_11 = V_14 -> V_29 ;
if ( V_11 ) {
F_15 ( & V_11 -> V_13 ) ;
F_8 ( V_11 ) ;
}
}
static void F_16 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
F_17 ( & V_11 -> V_13 , & V_4 -> V_30 ) ;
}
static struct V_10 * F_18 ( struct V_8 * V_9 , const char * V_19 , unsigned int V_31 )
{
struct V_28 * V_14 ;
struct V_10 * V_11 ;
int V_17 ;
V_14 = F_19 ( V_19 , V_9 ) ;
if ( ! V_14 )
return NULL ;
V_17 = F_20 ( V_9 , V_14 ) ;
if ( V_17 < 0 )
return NULL ;
V_11 = F_21 ( sizeof( * V_11 ) , V_32 ) ;
if ( ! V_11 )
goto error;
V_11 -> V_14 = V_14 ;
V_11 -> V_33 = V_31 ;
V_14 -> V_29 = V_11 ;
V_14 -> V_15 = F_14 ;
return V_11 ;
error:
F_22 ( V_14 ) ;
return NULL ;
}
int F_23 ( struct V_3 * V_4 , const char * V_19 , int V_31 )
{
struct V_10 * V_11 ;
V_11 = F_18 ( V_4 -> V_9 , V_19 , V_31 ) ;
if ( ! V_11 )
return - V_34 ;
F_16 ( V_4 , V_11 ) ;
return 0 ;
}
int F_24 ( struct V_8 * V_9 , const char * V_16 , int type ,
struct V_3 * * V_35 , bool V_36 , bool V_37 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 = NULL ;
int V_17 ;
int V_18 ;
static struct V_38 V_39 = {
. V_40 = F_4 ,
. V_41 = F_9 ,
. V_42 = F_1 ,
} ;
if ( V_36 ) {
V_11 = F_18 ( V_9 , V_16 , type ) ;
if ( ! V_11 )
return - V_34 ;
}
V_4 = F_21 ( sizeof( struct V_3 ) , V_32 ) ;
if ( V_4 == NULL )
return - V_34 ;
V_4 -> V_16 = F_25 ( V_16 , V_32 ) ;
if ( ! V_37 ) {
V_4 -> V_6 = F_26 () ;
if ( V_4 -> V_6 == NULL ) {
V_17 = - V_34 ;
goto V_43;
}
V_4 -> V_6 -> V_44 = L_2 ;
V_4 -> type = type ;
for ( V_18 = 0 ; V_18 < V_45 ; V_18 ++ )
if ( type & ( 1 << V_18 ) )
F_12 ( V_4 -> V_6 , V_46 ,
V_47 [ V_18 ] ) ;
}
V_17 = F_27 ( V_9 , V_48 , V_4 , & V_39 ) ;
if ( V_17 < 0 )
goto V_43;
V_4 -> V_9 = V_9 ;
F_28 ( & V_4 -> V_30 ) ;
if ( V_36 )
F_16 ( V_4 , V_11 ) ;
* V_35 = V_4 ;
return 0 ;
V_43:
F_3 ( V_4 -> V_6 ) ;
F_8 ( V_4 -> V_16 ) ;
F_8 ( V_4 ) ;
return V_17 ;
}
void F_29 ( struct V_3 * V_4 , struct V_2 * V_22 )
{
F_30 ( V_4 -> V_7 ) ;
if ( ! V_4 -> V_6 )
return;
V_4 -> V_6 -> V_21 . V_22 = V_22 ;
}
int F_31 ( struct V_3 * V_4 , enum V_49 type ,
int V_50 )
{
int V_23 = F_32 ( V_25 ) - F_32 ( type ) ;
F_30 ( V_4 -> V_7 ) ;
if ( ! V_50 || V_23 >= F_11 ( V_4 -> V_23 ) )
return - V_51 ;
V_4 -> type |= type ;
V_4 -> V_23 [ V_23 ] = V_50 ;
return 0 ;
}
void F_33 ( struct V_3 * V_4 , int V_52 )
{
struct V_10 * V_11 ;
int V_18 ;
if ( ! V_4 )
return;
F_34 (jack_kctl, &jack->kctl_list, list)
F_35 ( V_4 -> V_9 , V_11 -> V_14 ,
V_52 & V_11 -> V_33 ) ;
if ( ! V_4 -> V_6 )
return;
for ( V_18 = 0 ; V_18 < F_11 ( V_4 -> V_23 ) ; V_18 ++ ) {
int V_24 = V_25 >> V_18 ;
if ( V_4 -> type & V_24 )
F_36 ( V_4 -> V_6 , V_4 -> V_23 [ V_18 ] ,
V_52 & V_24 ) ;
}
for ( V_18 = 0 ; V_18 < F_11 ( V_47 ) ; V_18 ++ ) {
int V_24 = 1 << V_18 ;
if ( V_4 -> type & V_24 )
F_37 ( V_4 -> V_6 ,
V_47 [ V_18 ] ,
V_52 & V_24 ) ;
}
F_38 ( V_4 -> V_6 ) ;
}
