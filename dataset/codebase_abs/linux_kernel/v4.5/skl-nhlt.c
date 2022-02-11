void * F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
union V_4 * V_5 ;
struct V_6 * V_7 = NULL ;
if ( F_2 ( F_3 ( NULL , V_8 , & V_3 ) ) ) {
F_4 ( V_2 , L_1 ) ;
return NULL ;
}
V_5 = F_5 ( V_3 , V_9 , 1 , 1 , NULL ) ;
if ( V_5 && V_5 -> type == V_10 ) {
V_7 = (struct V_6 * ) V_5 -> V_11 . V_12 ;
return F_6 ( V_7 -> V_13 , V_7 -> V_14 ,
V_15 ) ;
}
F_4 ( V_2 , L_2 ) ;
return NULL ;
}
void F_7 ( void * V_16 )
{
F_8 ( V_16 ) ;
}
static struct V_17 * F_9 (
struct V_1 * V_2 , struct V_18 * V_19 ,
T_2 V_20 , T_3 V_21 , T_4 V_22 , T_2 V_23 )
{
struct V_17 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 = V_19 -> V_28 ;
int V_29 ;
F_10 ( V_2 , L_3 , V_19 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_19 -> V_30 ; V_29 ++ ) {
V_26 = & V_28 -> V_31 . V_19 ;
F_10 ( V_2 , L_4 , V_26 -> V_32 ,
V_26 -> V_33 , V_26 -> V_34 ) ;
if ( V_26 -> V_32 == V_20 && V_26 -> V_33 == V_22 ) {
V_24 = & V_28 -> V_35 ;
if ( V_23 == V_36 )
return V_24 ;
if ( V_26 -> V_34 == V_21 )
return V_24 ;
}
V_28 = (struct V_27 * ) ( V_28 -> V_35 . V_37 +
V_28 -> V_35 . V_38 ) ;
}
return NULL ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_39 , T_2 V_23 ,
T_2 V_40 , T_2 V_41 , T_3 V_42 , T_2 V_43 , T_4 V_22 )
{
F_10 ( V_2 , L_5 ) ;
F_10 ( V_2 , L_4 , V_41 , V_40 , V_42 ) ;
F_10 ( V_2 , L_6 , V_39 , V_23 ) ;
F_10 ( V_2 , L_7 , V_22 ) ;
}
static bool F_12 ( struct V_1 * V_2 , struct V_44 * V_45 ,
T_3 V_39 , T_2 V_46 , T_2 V_43 )
{
F_10 ( V_2 , L_8 ,
V_45 -> V_47 , V_45 -> V_23 , V_45 -> V_48 ) ;
if ( ( V_45 -> V_47 == V_39 ) &&
( V_45 -> V_23 == V_46 ) &&
( V_45 -> V_48 == V_43 ) )
return true ;
else
return false ;
}
struct V_17
* F_13 ( struct V_49 * V_49 , T_3 V_50 , T_2 V_46 ,
T_2 V_40 , T_2 V_51 , T_3 V_42 , T_2 V_43 )
{
struct V_18 * V_19 ;
struct V_44 * V_45 ;
struct V_52 * V_53 = F_14 ( & V_49 -> V_54 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_17 * V_24 ;
struct V_55 * V_56 = (struct V_55 * ) V_49 -> V_56 ;
T_4 V_22 = ( V_40 == 16 ) ? 16 : 32 ;
T_2 V_57 ;
F_11 ( V_2 , V_50 , V_46 , V_40 , V_51 , V_42 , V_43 , V_22 ) ;
V_45 = (struct V_44 * ) V_56 -> V_58 ;
F_10 ( V_2 , L_9 , V_56 -> V_59 ) ;
for ( V_57 = 0 ; V_57 < V_56 -> V_59 ; V_57 ++ ) {
if ( F_12 ( V_2 , V_45 , V_50 , V_46 , V_43 ) ) {
V_19 = (struct V_18 * ) ( V_45 -> V_35 . V_37 +
V_45 -> V_35 . V_38 ) ;
V_24 = F_9 ( V_2 , V_19 , V_51 ,
V_42 , V_22 , V_46 ) ;
if ( V_24 )
return V_24 ;
}
V_45 = (struct V_44 * ) ( ( T_2 * ) V_45 + V_45 -> V_14 ) ;
}
return NULL ;
}
