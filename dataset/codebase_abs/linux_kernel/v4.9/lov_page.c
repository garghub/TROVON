static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
T_1 V_13 = * V_7 ;
unsigned int V_14 ;
F_4 ( V_15 , V_16 L_1 ,
F_5 ( F_6 ( F_7 ( V_9 ) ) ) , V_13 , V_12 -> V_17 ) ;
if ( V_13 == 0 )
return 0 ;
if ( V_12 -> V_17 == 1 )
return 0 ;
if ( V_13 != V_18 ) {
int V_19 = F_8 ( V_4 -> V_20 ) ;
* V_7 = F_9 ( V_9 -> V_21 , V_13 , V_19 ) ;
}
V_14 = V_9 -> V_21 -> V_22 >> V_23 ;
V_13 = V_4 -> V_24 + V_14 - V_4 -> V_24 % V_14 - 1 ;
F_4 ( V_15 , V_16 L_2 ,
F_5 ( F_6 ( F_7 ( V_9 ) ) ) , * V_7 , V_13 , V_14 ,
V_9 -> V_21 -> V_22 , F_8 ( V_4 -> V_20 ) ,
V_4 -> V_24 ) ;
* V_7 = F_10 ( T_1 , * V_7 , V_13 ) ;
return 0 ;
}
static int F_11 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
void * V_25 , T_2 V_26 )
{
struct V_27 * V_28 = F_12 ( V_4 ) ;
return (* V_26)( V_2 , V_25 , V_29 L_3 , V_28 ) ;
}
int F_13 ( const struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_1 V_13 )
{
struct V_8 * V_9 = F_2 ( V_31 ) ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_34 * V_35 = F_14 ( V_2 ) ;
struct V_30 * V_36 ;
struct V_30 * V_37 ;
struct V_38 * V_39 ;
struct V_27 * V_40 = F_15 ( V_31 , V_33 ) ;
T_3 V_41 ;
T_4 V_42 ;
int V_43 ;
int V_44 ;
V_41 = F_16 ( V_31 , V_13 ) ;
V_43 = F_17 ( V_9 -> V_21 , V_41 ) ;
F_18 ( V_43 < V_12 -> V_17 ) ;
V_44 = F_19 ( V_9 -> V_21 , V_41 , V_43 , & V_42 ) ;
F_18 ( V_44 == 0 ) ;
V_40 -> V_45 = V_43 ;
F_20 ( V_33 , & V_40 -> V_46 , V_31 , V_13 , & V_47 ) ;
V_39 = F_21 ( V_2 , V_35 , V_43 ) ;
if ( F_22 ( V_39 ) )
return F_23 ( V_39 ) ;
V_36 = F_24 ( V_12 -> V_48 [ V_43 ] ) ;
F_25 (o, &subobj->co_lu.lo_header->loh_layers,
co_lu.lo_linkage) {
if ( V_37 -> V_49 -> V_50 ) {
V_44 = V_37 -> V_49 -> V_50 ( V_39 -> V_51 , V_37 , V_33 ,
F_26 ( V_36 , V_42 ) ) ;
if ( V_44 != 0 )
break;
}
}
F_27 ( V_39 ) ;
return V_44 ;
}
static int F_28 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
void * V_25 , T_2 V_26 )
{
struct V_27 * V_28 = F_12 ( V_4 ) ;
return (* V_26)( V_2 , V_25 , V_29 L_4 ,
V_28 ) ;
}
int F_29 ( const struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_1 V_13 )
{
struct V_27 * V_40 = F_15 ( V_31 , V_33 ) ;
void * V_52 ;
F_20 ( V_33 , & V_40 -> V_46 , V_31 , V_13 , & V_53 ) ;
V_52 = F_30 ( V_33 -> V_54 ) ;
memset ( V_52 , 0 , F_31 ( V_31 ) ) ;
F_32 ( V_33 -> V_54 ) ;
F_33 ( V_2 , V_33 , 1 ) ;
return 0 ;
}
