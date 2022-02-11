int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 ;
int V_8 , V_9 ;
V_2 -> V_10 = ~ 0 ;
if ( V_2 -> V_11 )
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ )
V_2 -> V_11 [ V_9 ] = V_13 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_3 (np, child) {
const T_1 * V_14 ;
T_2 V_15 ;
int V_16 ;
V_14 = F_4 ( V_7 , L_1 , & V_16 ) ;
if ( ! V_14 || V_16 < sizeof( * V_14 ) ) {
F_5 ( & V_2 -> V_17 , L_2 ,
V_7 -> V_18 ) ;
continue;
}
V_15 = F_6 ( V_14 ) ;
if ( V_15 >= 32 ) {
F_5 ( & V_2 -> V_17 , L_3 ,
V_7 -> V_18 , V_15 ) ;
continue;
}
if ( V_2 -> V_11 ) {
V_2 -> V_11 [ V_15 ] = F_7 ( V_7 , 0 ) ;
if ( ! V_2 -> V_11 [ V_15 ] )
V_2 -> V_11 [ V_15 ] = V_13 ;
}
V_6 = F_8 ( V_2 , V_15 ) ;
if ( ! V_6 || F_9 ( V_6 ) ) {
F_5 ( & V_2 -> V_17 , L_4 ,
V_15 ) ;
continue;
}
F_10 ( V_6 ) ;
F_11 ( V_7 ) ;
V_6 -> V_17 . V_19 = V_7 ;
V_8 = F_12 ( V_6 ) ;
if ( V_8 ) {
F_13 ( V_6 ) ;
F_14 ( V_7 ) ;
continue;
}
F_15 ( & V_2 -> V_17 , L_5 ,
V_7 -> V_20 , V_15 ) ;
}
return 0 ;
}
static int F_16 ( struct V_21 * V_17 , void * V_22 )
{
return V_17 -> V_19 == V_22 ;
}
struct V_5 * F_17 ( struct V_3 * V_22 )
{
struct V_21 * V_23 ;
if ( ! V_22 )
return NULL ;
V_23 = F_18 ( & V_24 , NULL , V_22 , F_16 ) ;
return V_23 ? F_19 ( V_23 ) : NULL ;
}
struct V_5 * F_20 ( struct V_25 * V_17 ,
struct V_3 * V_22 ,
void (* F_21)( struct V_25 * ) , T_2 V_26 ,
T_3 V_27 )
{
struct V_5 * V_6 = F_17 ( V_22 ) ;
if ( ! V_6 )
return NULL ;
return F_22 ( V_17 , V_6 , F_21 , V_26 , V_27 ) ? NULL : V_6 ;
}
struct V_5 * F_23 ( struct V_25 * V_17 ,
void (* F_21)( struct V_25 * ) ,
T_3 V_27 )
{
struct V_3 * V_28 ;
char V_29 [ V_30 + 3 ] ;
struct V_5 * V_6 ;
const T_1 * V_31 ;
int V_32 ;
if ( ! V_17 -> V_17 . V_33 )
return NULL ;
V_28 = V_17 -> V_17 . V_33 -> V_19 ;
if ( ! V_28 )
return NULL ;
V_31 = F_4 ( V_28 , L_6 , & V_32 ) ;
if ( ! V_31 || V_32 < sizeof( * V_31 ) )
return NULL ;
sprintf ( V_29 , V_34 , L_7 , F_24 ( V_31 [ 0 ] ) ) ;
V_6 = F_25 ( V_17 , V_29 , F_21 , 0 , V_27 ) ;
return F_9 ( V_6 ) ? NULL : V_6 ;
}
