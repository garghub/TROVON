static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
void * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
return (* V_6)( V_2 , V_5 , V_9 L_1 , V_8 ) ;
}
int F_3 ( const struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_12 * V_13 , T_2 V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
struct V_19 * V_20 = F_6 ( V_2 ) ;
struct V_10 * V_21 ;
struct V_10 * V_22 ;
struct V_23 * V_24 ;
struct V_7 * V_25 = F_7 ( V_11 , V_13 ) ;
T_3 V_26 ;
T_4 V_27 ;
int V_28 ;
int V_29 ;
V_26 = F_8 ( V_11 , V_14 ) ;
V_28 = F_9 ( V_16 -> V_30 , V_26 ) ;
F_10 ( V_28 < V_18 -> V_31 ) ;
V_29 = F_11 ( V_16 -> V_30 , V_26 , V_28 , & V_27 ) ;
F_10 ( V_29 == 0 ) ;
V_25 -> V_32 = V_28 ;
F_12 ( V_13 , & V_25 -> V_33 , V_11 , V_14 , & V_34 ) ;
V_24 = F_13 ( V_2 , V_20 , V_28 ) ;
if ( F_14 ( V_24 ) )
return F_15 ( V_24 ) ;
V_21 = F_16 ( V_18 -> V_35 [ V_28 ] ) ;
F_17 (o, &subobj->co_lu.lo_header->loh_layers,
co_lu.lo_linkage) {
if ( V_22 -> V_36 -> V_37 ) {
V_29 = V_22 -> V_36 -> V_37 ( V_24 -> V_38 , V_22 , V_13 ,
F_18 ( V_21 , V_27 ) ) ;
if ( V_29 != 0 )
break;
}
}
return V_29 ;
}
static int F_19 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
void * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
return (* V_6)( V_2 , V_5 , V_9 L_2 ,
V_8 ) ;
}
int F_20 ( const struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_12 * V_13 , T_2 V_14 )
{
struct V_7 * V_25 = F_7 ( V_11 , V_13 ) ;
void * V_39 ;
F_12 ( V_13 , & V_25 -> V_33 , V_11 , V_14 , & V_40 ) ;
V_39 = F_21 ( V_13 -> V_41 ) ;
memset ( V_39 , 0 , F_22 ( V_11 ) ) ;
F_23 ( V_13 -> V_41 ) ;
F_24 ( V_2 , V_13 , 1 ) ;
return 0 ;
}
