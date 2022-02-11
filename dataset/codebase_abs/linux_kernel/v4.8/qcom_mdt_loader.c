struct V_1 * F_1 ( struct V_2 * V_2 ,
const struct V_3 * V_4 ,
int * V_5 )
{
static struct V_1 V_6 = { . V_7 = 1 , } ;
* V_5 = sizeof( V_6 ) ;
return & V_6 ;
}
int F_2 ( const struct V_3 * V_4 , T_1 * V_8 ,
T_2 * V_9 , bool * V_10 )
{
const struct V_11 * V_12 ;
const struct V_11 * V_13 ;
const struct V_14 * V_15 ;
T_1 V_16 = ( T_1 ) V_17 ;
T_1 V_18 = 0 ;
bool V_19 = false ;
int V_20 ;
V_15 = (struct V_14 * ) V_4 -> V_21 ;
V_12 = (struct V_11 * ) ( V_15 + 1 ) ;
for ( V_20 = 0 ; V_20 < V_15 -> V_22 ; V_20 ++ ) {
V_13 = & V_12 [ V_20 ] ;
if ( V_13 -> V_23 != V_24 )
continue;
if ( ( V_13 -> V_25 & V_26 ) == V_27 )
continue;
if ( ! V_13 -> V_28 )
continue;
if ( V_13 -> V_25 & V_29 )
V_19 = true ;
if ( V_13 -> V_30 < V_16 )
V_16 = V_13 -> V_30 ;
if ( V_13 -> V_30 + V_13 -> V_28 > V_18 )
V_18 = F_3 ( V_13 -> V_30 + V_13 -> V_28 , V_31 ) ;
}
if ( V_8 )
* V_8 = V_16 ;
if ( V_9 )
* V_9 = V_18 - V_16 ;
if ( V_10 )
* V_10 = V_19 ;
return 0 ;
}
int F_4 ( struct V_2 * V_2 ,
const struct V_3 * V_4 ,
const char * V_3 )
{
const struct V_11 * V_12 ;
const struct V_11 * V_13 ;
const struct V_14 * V_15 ;
T_2 V_32 ;
char * V_33 ;
void * V_34 ;
int V_35 ;
int V_20 ;
V_15 = (struct V_14 * ) V_4 -> V_21 ;
V_12 = (struct V_11 * ) ( V_15 + 1 ) ;
V_32 = strlen ( V_3 ) ;
if ( V_32 <= 4 )
return - V_36 ;
V_33 = F_5 ( V_3 , V_37 ) ;
if ( ! V_33 )
return - V_38 ;
for ( V_20 = 0 ; V_20 < V_15 -> V_22 ; V_20 ++ ) {
V_13 = & V_12 [ V_20 ] ;
if ( V_13 -> V_23 != V_24 )
continue;
if ( ( V_13 -> V_25 & V_26 ) == V_27 )
continue;
if ( ! V_13 -> V_28 )
continue;
V_34 = F_6 ( V_2 , V_13 -> V_30 , V_13 -> V_28 ) ;
if ( ! V_34 ) {
F_7 ( & V_2 -> V_39 , L_1 ) ;
V_35 = - V_36 ;
break;
}
if ( V_13 -> V_40 ) {
sprintf ( V_33 + V_32 - 3 , L_2 , V_20 ) ;
V_35 = F_8 ( & V_4 , V_33 , & V_2 -> V_39 ) ;
if ( V_35 ) {
F_7 ( & V_2 -> V_39 , L_3 ,
V_33 ) ;
break;
}
memcpy ( V_34 , V_4 -> V_21 , V_4 -> V_41 ) ;
F_9 ( V_4 ) ;
}
if ( V_13 -> V_28 > V_13 -> V_40 )
memset ( V_34 + V_13 -> V_40 , 0 , V_13 -> V_28 - V_13 -> V_40 ) ;
}
F_10 ( V_33 ) ;
return V_35 ;
}
