int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_3 * V_7 ;
const T_1 * V_8 ;
T_2 V_9 ;
bool V_10 , V_11 = false ;
int V_12 , V_13 , V_14 ;
V_2 -> V_15 = ~ 0 ;
if ( V_2 -> V_16 )
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ )
V_2 -> V_16 [ V_13 ] = V_18 ;
V_2 -> V_19 . V_20 = V_4 ;
V_12 = F_2 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_3 (np, child) {
V_8 = F_4 ( V_7 , L_1 , & V_14 ) ;
if ( ! V_8 || V_14 < sizeof( * V_8 ) ) {
V_11 = true ;
F_5 ( & V_2 -> V_19 , L_2 ,
V_7 -> V_21 ) ;
continue;
}
V_9 = F_6 ( V_8 ) ;
if ( V_9 >= 32 ) {
F_5 ( & V_2 -> V_19 , L_3 ,
V_7 -> V_21 , V_9 ) ;
continue;
}
if ( V_2 -> V_16 ) {
V_2 -> V_16 [ V_9 ] = F_7 ( V_7 , 0 ) ;
if ( ! V_2 -> V_16 [ V_9 ] )
V_2 -> V_16 [ V_9 ] = V_18 ;
}
V_10 = F_8 ( V_7 ,
L_4 ) ;
V_6 = F_9 ( V_2 , V_9 , V_10 ) ;
if ( ! V_6 || F_10 ( V_6 ) ) {
F_5 ( & V_2 -> V_19 ,
L_5 ,
V_9 ) ;
continue;
}
F_11 ( V_7 ) ;
V_6 -> V_19 . V_20 = V_7 ;
V_12 = F_12 ( V_6 ) ;
if ( V_12 ) {
F_13 ( V_6 ) ;
F_14 ( V_7 ) ;
continue;
}
F_15 ( & V_2 -> V_19 , L_6 ,
V_7 -> V_22 , V_9 ) ;
}
if ( ! V_11 )
return 0 ;
F_3 (np, child) {
V_8 = F_4 ( V_7 , L_1 , & V_14 ) ;
if ( V_8 )
continue;
V_10 = F_8 ( V_7 ,
L_4 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
if ( V_2 -> V_23 [ V_9 ] )
continue;
F_16 ( & V_2 -> V_19 , L_7 ,
V_7 -> V_22 , V_9 ) ;
V_6 = F_9 ( V_2 , V_9 , V_10 ) ;
if ( ! V_6 || F_10 ( V_6 ) )
continue;
if ( V_2 -> V_16 ) {
V_2 -> V_16 [ V_9 ] =
F_7 ( V_7 , 0 ) ;
if ( ! V_2 -> V_16 [ V_9 ] )
V_2 -> V_16 [ V_9 ] = V_18 ;
}
F_11 ( V_7 ) ;
V_6 -> V_19 . V_20 = V_7 ;
V_12 = F_12 ( V_6 ) ;
if ( V_12 ) {
F_13 ( V_6 ) ;
F_14 ( V_7 ) ;
continue;
}
F_16 ( & V_2 -> V_19 , L_6 ,
V_7 -> V_22 , V_9 ) ;
break;
}
}
return 0 ;
}
static int F_17 ( struct V_24 * V_19 , void * V_25 )
{
return V_19 -> V_20 == V_25 ;
}
struct V_5 * F_18 ( struct V_3 * V_25 )
{
struct V_24 * V_26 ;
if ( ! V_25 )
return NULL ;
V_26 = F_19 ( & V_27 , NULL , V_25 , F_17 ) ;
return V_26 ? F_20 ( V_26 ) : NULL ;
}
struct V_5 * F_21 ( struct V_28 * V_19 ,
struct V_3 * V_25 ,
void (* F_22)( struct V_28 * ) , T_2 V_29 ,
T_3 V_30 )
{
struct V_5 * V_6 = F_18 ( V_25 ) ;
if ( ! V_6 )
return NULL ;
return F_23 ( V_19 , V_6 , F_22 , V_30 ) ? NULL : V_6 ;
}
struct V_5 * F_24 ( struct V_28 * V_19 ,
void (* F_22)( struct V_28 * ) ,
T_3 V_30 )
{
struct V_3 * V_31 ;
char V_32 [ V_33 + 3 ] ;
struct V_5 * V_6 ;
const T_1 * V_34 ;
int V_35 ;
if ( ! V_19 -> V_19 . V_36 )
return NULL ;
V_31 = V_19 -> V_19 . V_36 -> V_20 ;
if ( ! V_31 )
return NULL ;
V_34 = F_4 ( V_31 , L_8 , & V_35 ) ;
if ( ! V_34 || V_35 < sizeof( * V_34 ) )
return NULL ;
sprintf ( V_32 , V_37 , L_9 , F_25 ( V_34 [ 0 ] ) ) ;
V_6 = F_26 ( V_19 , V_32 , F_22 , V_30 ) ;
return F_10 ( V_6 ) ? NULL : V_6 ;
}
