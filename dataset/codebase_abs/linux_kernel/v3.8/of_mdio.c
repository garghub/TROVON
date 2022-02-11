int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 ;
int V_8 , V_9 ;
V_2 -> V_10 = ~ 0 ;
if ( V_2 -> V_11 )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
V_2 -> V_11 [ V_9 ] = V_13 ;
V_2 -> V_14 . V_15 = V_4 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_3 (np, child) {
const T_1 * V_16 ;
T_2 V_17 ;
int V_18 ;
bool V_19 ;
V_16 = F_4 ( V_7 , L_1 , & V_18 ) ;
if ( ! V_16 || V_18 < sizeof( * V_16 ) ) {
F_5 ( & V_2 -> V_14 , L_2 ,
V_7 -> V_20 ) ;
continue;
}
V_17 = F_6 ( V_16 ) ;
if ( V_17 >= 32 ) {
F_5 ( & V_2 -> V_14 , L_3 ,
V_7 -> V_20 , V_17 ) ;
continue;
}
if ( V_2 -> V_11 ) {
V_2 -> V_11 [ V_17 ] = F_7 ( V_7 , 0 ) ;
if ( ! V_2 -> V_11 [ V_17 ] )
V_2 -> V_11 [ V_17 ] = V_13 ;
}
V_19 = F_8 ( V_7 ,
L_4 ) ;
V_6 = F_9 ( V_2 , V_17 , V_19 ) ;
if ( ! V_6 || F_10 ( V_6 ) ) {
V_6 = F_11 ( V_2 , V_17 , 0 , false , NULL ) ;
if ( ! V_6 || F_10 ( V_6 ) ) {
F_5 ( & V_2 -> V_14 ,
L_5 ,
V_17 ) ;
continue;
}
}
F_12 ( V_7 ) ;
V_6 -> V_14 . V_15 = V_7 ;
V_8 = F_13 ( V_6 ) ;
if ( V_8 ) {
F_14 ( V_6 ) ;
F_15 ( V_7 ) ;
continue;
}
F_16 ( & V_2 -> V_14 , L_6 ,
V_7 -> V_21 , V_17 ) ;
}
return 0 ;
}
static int F_17 ( struct V_22 * V_14 , void * V_23 )
{
return V_14 -> V_15 == V_23 ;
}
struct V_5 * F_18 ( struct V_3 * V_23 )
{
struct V_22 * V_24 ;
if ( ! V_23 )
return NULL ;
V_24 = F_19 ( & V_25 , NULL , V_23 , F_17 ) ;
return V_24 ? F_20 ( V_24 ) : NULL ;
}
struct V_5 * F_21 ( struct V_26 * V_14 ,
struct V_3 * V_23 ,
void (* F_22)( struct V_26 * ) , T_2 V_27 ,
T_3 V_28 )
{
struct V_5 * V_6 = F_18 ( V_23 ) ;
if ( ! V_6 )
return NULL ;
return F_23 ( V_14 , V_6 , F_22 , V_27 , V_28 ) ? NULL : V_6 ;
}
struct V_5 * F_24 ( struct V_26 * V_14 ,
void (* F_22)( struct V_26 * ) ,
T_3 V_28 )
{
struct V_3 * V_29 ;
char V_30 [ V_31 + 3 ] ;
struct V_5 * V_6 ;
const T_1 * V_32 ;
int V_33 ;
if ( ! V_14 -> V_14 . V_34 )
return NULL ;
V_29 = V_14 -> V_14 . V_34 -> V_15 ;
if ( ! V_29 )
return NULL ;
V_32 = F_4 ( V_29 , L_7 , & V_33 ) ;
if ( ! V_32 || V_33 < sizeof( * V_32 ) )
return NULL ;
sprintf ( V_30 , V_35 , L_8 , F_25 ( V_32 [ 0 ] ) ) ;
V_6 = F_26 ( V_14 , V_30 , F_22 , 0 , V_28 ) ;
return F_10 ( V_6 ) ? NULL : V_6 ;
}
