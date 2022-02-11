static
T_1 F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 ;
return V_5 -> V_7 ;
}
static int
F_2 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_8 * V_9 = & V_1 -> V_9 ;
struct V_4 * V_5 ;
struct V_10 * V_11 ;
int V_12 , V_13 = 0 ;
const T_2 * V_14 = V_3 -> V_6 ;
V_5 = (struct V_4 * ) V_14 ;
V_11 = (struct V_10 * ) ( V_14 + V_5 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < V_5 -> V_16 ; V_12 ++ , V_11 ++ ) {
T_1 V_17 = V_11 -> V_18 ;
T_1 V_19 = V_11 -> V_20 ;
T_1 V_21 = V_11 -> V_22 ;
T_1 V_23 = V_11 -> V_24 ;
void * V_25 ;
if ( V_11 -> V_26 != V_27 )
continue;
F_3 ( V_9 , L_1 ,
V_11 -> V_26 , V_17 , V_19 , V_21 ) ;
if ( V_21 > V_19 ) {
F_4 ( V_9 , L_2 ,
V_21 , V_19 ) ;
V_13 = - V_28 ;
break;
}
if ( V_23 + V_21 > V_3 -> V_29 ) {
F_4 ( V_9 , L_3 ,
V_23 + V_21 , V_3 -> V_29 ) ;
V_13 = - V_28 ;
break;
}
V_25 = F_5 ( V_1 , V_17 , V_19 ) ;
if ( ! V_25 ) {
F_4 ( V_9 , L_4 , V_17 , V_19 ) ;
V_13 = - V_28 ;
break;
}
if ( V_11 -> V_22 )
memcpy ( V_25 , V_14 + V_11 -> V_24 , V_21 ) ;
if ( V_19 > V_21 )
memset ( V_25 + V_21 , 0 , V_19 - V_21 ) ;
}
return V_13 ;
}
static struct V_30 *
F_6 ( struct V_8 * V_9 , struct V_4 * V_5 , T_3 V_31 )
{
struct V_30 * V_32 ;
int V_12 ;
const char * V_33 ;
struct V_34 * V_35 = NULL ;
const T_2 * V_14 = ( void * ) V_5 ;
V_32 = (struct V_30 * ) ( V_14 + V_5 -> V_36 ) ;
V_33 = V_14 + V_32 [ V_5 -> V_37 ] . V_38 ;
for ( V_12 = 0 ; V_12 < V_5 -> V_39 ; V_12 ++ , V_32 ++ ) {
T_1 V_29 = V_32 -> V_40 ;
T_1 V_23 = V_32 -> V_38 ;
if ( strcmp ( V_33 + V_32 -> V_41 , L_5 ) )
continue;
V_35 = (struct V_34 * ) ( V_14 + V_23 ) ;
if ( V_23 + V_29 > V_31 || V_23 + V_29 < V_29 ) {
F_4 ( V_9 , L_6 ) ;
return NULL ;
}
if ( sizeof( struct V_34 ) > V_29 ) {
F_4 ( V_9 , L_7 ) ;
return NULL ;
}
if ( V_35 -> V_42 != 1 ) {
F_4 ( V_9 , L_8 , V_35 -> V_42 ) ;
return NULL ;
}
if ( V_35 -> V_43 [ 0 ] || V_35 -> V_43 [ 1 ] ) {
F_4 ( V_9 , L_9 ) ;
return NULL ;
}
if ( V_35 -> V_44 * sizeof( V_35 -> V_23 [ 0 ] ) +
sizeof( struct V_34 ) > V_29 ) {
F_4 ( V_9 , L_10 ) ;
return NULL ;
}
return V_32 ;
}
return NULL ;
}
static struct V_34 *
F_7 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
int * V_45 )
{
struct V_4 * V_5 ;
struct V_30 * V_32 ;
struct V_8 * V_9 = & V_1 -> V_9 ;
struct V_34 * V_35 = NULL ;
const T_2 * V_14 = V_3 -> V_6 ;
V_5 = (struct V_4 * ) V_14 ;
V_32 = F_6 ( V_9 , V_5 , V_3 -> V_29 ) ;
if ( ! V_32 )
return NULL ;
V_35 = (struct V_34 * ) ( V_14 + V_32 -> V_38 ) ;
* V_45 = V_32 -> V_40 ;
return V_35 ;
}
static struct V_34 *
F_8 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_6 ;
struct V_30 * V_32 ;
V_32 = F_6 ( & V_1 -> V_9 , V_5 , V_3 -> V_29 ) ;
if ( ! V_32 )
return NULL ;
return F_5 ( V_1 , V_32 -> V_46 , V_32 -> V_40 ) ;
}
