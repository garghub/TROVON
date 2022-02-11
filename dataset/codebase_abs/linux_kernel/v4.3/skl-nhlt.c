void T_1 * F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
union V_4 * V_5 ;
struct V_6 * V_7 = NULL ;
if ( F_2 ( F_3 ( NULL , V_8 , & V_3 ) ) ) {
F_4 ( V_2 , L_1 ) ;
return NULL ;
}
V_5 = F_5 ( V_3 , V_9 , 1 , 1 , NULL ) ;
if ( V_5 && V_5 -> type == V_10 ) {
V_7 = (struct V_6 * ) V_5 -> V_11 . V_12 ;
return F_6 ( V_7 -> V_13 , V_7 -> V_14 ) ;
}
F_4 ( V_2 , L_2 ) ;
return NULL ;
}
void F_7 ( void T_1 * V_15 )
{
F_8 ( V_15 ) ;
V_15 = NULL ;
}
static struct V_16 * F_9 (
struct V_1 * V_2 , struct V_17 * V_18 ,
T_3 V_19 , T_4 V_20 , T_5 V_21 )
{
struct V_16 * V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 = V_18 -> V_26 ;
int V_27 ;
F_10 ( V_2 , L_3 , V_18 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_18 -> V_28 ; V_27 ++ ) {
V_24 = & V_26 -> V_29 . V_18 ;
F_10 ( V_2 , L_4 , V_24 -> V_30 ,
V_24 -> V_31 , V_24 -> V_32 ) ;
if ( V_24 -> V_30 == V_19 && V_24 -> V_32 == V_20 &&
V_24 -> V_31 == V_21 ) {
V_22 = & V_26 -> V_33 ;
return V_22 ;
}
V_26 = (struct V_25 * ) ( V_26 -> V_33 . V_34 +
V_26 -> V_33 . V_35 ) ;
}
return NULL ;
}
static void F_11 ( struct V_1 * V_2 , T_4 V_36 , T_3 V_37 ,
T_3 V_38 , T_3 V_39 , T_4 V_40 , T_3 V_41 , T_5 V_21 )
{
F_10 ( V_2 , L_5 ) ;
F_10 ( V_2 , L_4 , V_39 , V_38 , V_40 ) ;
F_10 ( V_2 , L_6 , V_36 , V_37 ) ;
F_10 ( V_2 , L_7 , V_21 ) ;
}
static bool F_12 ( struct V_1 * V_2 , struct V_42 * V_43 ,
T_4 V_36 , T_3 V_44 , T_3 V_41 )
{
F_10 ( V_2 , L_8 ,
V_43 -> V_45 , V_43 -> V_37 , V_43 -> V_46 ) ;
if ( ( V_43 -> V_45 == V_36 ) &&
( V_43 -> V_37 == V_44 ) &&
( V_43 -> V_46 == V_41 ) )
return true ;
else
return false ;
}
struct V_16
* F_13 ( struct V_47 * V_47 , T_4 V_48 , T_3 V_44 ,
T_3 V_38 , T_3 V_49 , T_4 V_40 , T_3 V_41 )
{
struct V_17 * V_18 ;
struct V_42 * V_43 ;
struct V_50 * V_51 = F_14 ( & V_47 -> V_52 ) ;
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_16 * V_22 ;
struct V_53 * V_54 = (struct V_53 * ) V_47 -> V_54 ;
T_5 V_21 = V_49 * V_38 ;
T_3 V_55 ;
F_11 ( V_2 , V_48 , V_44 , V_38 , V_49 , V_40 , V_41 , V_21 ) ;
V_43 = (struct V_42 * ) V_54 -> V_56 ;
F_10 ( V_2 , L_9 , V_54 -> V_57 ) ;
for ( V_55 = 0 ; V_55 < V_54 -> V_57 ; V_55 ++ ) {
if ( F_12 ( V_2 , V_43 , V_48 , V_44 , V_41 ) ) {
V_18 = (struct V_17 * ) ( V_43 -> V_33 . V_34 +
V_43 -> V_33 . V_35 ) ;
V_22 = F_9 ( V_2 , V_18 , V_49 , V_40 , V_21 ) ;
if ( V_22 )
return V_22 ;
}
V_43 = (struct V_42 * ) ( ( T_3 * ) V_43 + V_43 -> V_14 ) ;
}
return NULL ;
}
