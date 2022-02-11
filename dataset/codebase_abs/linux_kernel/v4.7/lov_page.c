static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
T_1 V_13 = * V_7 ;
unsigned int V_14 ;
F_4 ( V_15 , L_1 , V_13 , V_12 -> V_16 ) ;
if ( V_13 == 0 )
return 0 ;
if ( V_12 -> V_16 == 1 )
return 0 ;
if ( V_13 != V_17 ) {
int V_18 = F_5 ( V_4 -> V_19 ) ;
* V_7 = F_6 ( V_9 -> V_20 , V_13 , V_18 ) ;
}
V_14 = V_9 -> V_20 -> V_21 >> V_22 ;
V_13 = ( ( V_4 -> V_23 + V_14 ) & ~ ( V_14 - 1 ) ) - 1 ;
* V_7 = F_7 ( T_1 , * V_7 , V_13 ) ;
return 0 ;
}
static int F_8 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
void * V_24 , T_2 V_25 )
{
struct V_26 * V_27 = F_9 ( V_4 ) ;
return (* V_25)( V_2 , V_24 , V_28 L_2 , V_27 ) ;
}
int F_10 ( const struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 , T_1 V_13 )
{
struct V_8 * V_9 = F_2 ( V_30 ) ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_33 * V_34 = F_11 ( V_2 ) ;
struct V_29 * V_35 ;
struct V_29 * V_36 ;
struct V_37 * V_38 ;
struct V_26 * V_39 = F_12 ( V_30 , V_32 ) ;
T_3 V_40 ;
T_4 V_41 ;
int V_42 ;
int V_43 ;
V_40 = F_13 ( V_30 , V_13 ) ;
V_42 = F_14 ( V_9 -> V_20 , V_40 ) ;
F_15 ( V_42 < V_12 -> V_16 ) ;
V_43 = F_16 ( V_9 -> V_20 , V_40 , V_42 , & V_41 ) ;
F_15 ( V_43 == 0 ) ;
F_17 ( V_32 , & V_39 -> V_44 , V_30 , V_13 , & V_45 ) ;
V_38 = F_18 ( V_2 , V_34 , V_42 ) ;
if ( F_19 ( V_38 ) )
return F_20 ( V_38 ) ;
V_35 = F_21 ( V_12 -> V_46 [ V_42 ] ) ;
F_22 (o, &subobj->co_lu.lo_header->loh_layers,
co_lu.lo_linkage) {
if ( V_36 -> V_47 -> V_48 ) {
V_43 = V_36 -> V_47 -> V_48 ( V_38 -> V_49 , V_36 , V_32 ,
F_23 ( V_35 , V_41 ) ) ;
if ( V_43 != 0 )
break;
}
}
F_24 ( V_38 ) ;
return V_43 ;
}
static int F_25 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
void * V_24 , T_2 V_25 )
{
struct V_26 * V_27 = F_9 ( V_4 ) ;
return (* V_25)( V_2 , V_24 , V_28 L_3 ,
V_27 ) ;
}
int F_26 ( const struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_31 * V_32 , T_1 V_13 )
{
struct V_26 * V_39 = F_12 ( V_30 , V_32 ) ;
void * V_50 ;
F_17 ( V_32 , & V_39 -> V_44 , V_30 , V_13 , & V_51 ) ;
V_50 = F_27 ( V_32 -> V_52 ) ;
memset ( V_50 , 0 , F_28 ( V_30 ) ) ;
F_29 ( V_32 -> V_52 ) ;
F_30 ( V_2 , V_32 , 1 ) ;
return 0 ;
}
