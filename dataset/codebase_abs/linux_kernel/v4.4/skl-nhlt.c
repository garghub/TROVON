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
T_2 V_20 , T_3 V_21 , T_4 V_22 )
{
struct V_17 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 = V_19 -> V_27 ;
int V_28 ;
F_10 ( V_2 , L_3 , V_19 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_19 -> V_29 ; V_28 ++ ) {
V_25 = & V_27 -> V_30 . V_19 ;
F_10 ( V_2 , L_4 , V_25 -> V_31 ,
V_25 -> V_32 , V_25 -> V_33 ) ;
if ( V_25 -> V_31 == V_20 && V_25 -> V_33 == V_21 &&
V_25 -> V_32 == V_22 ) {
V_23 = & V_27 -> V_34 ;
return V_23 ;
}
V_27 = (struct V_26 * ) ( V_27 -> V_34 . V_35 +
V_27 -> V_34 . V_36 ) ;
}
return NULL ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_37 , T_2 V_38 ,
T_2 V_39 , T_2 V_40 , T_3 V_41 , T_2 V_42 , T_4 V_22 )
{
F_10 ( V_2 , L_5 ) ;
F_10 ( V_2 , L_4 , V_40 , V_39 , V_41 ) ;
F_10 ( V_2 , L_6 , V_37 , V_38 ) ;
F_10 ( V_2 , L_7 , V_22 ) ;
}
static bool F_12 ( struct V_1 * V_2 , struct V_43 * V_44 ,
T_3 V_37 , T_2 V_45 , T_2 V_42 )
{
F_10 ( V_2 , L_8 ,
V_44 -> V_46 , V_44 -> V_38 , V_44 -> V_47 ) ;
if ( ( V_44 -> V_46 == V_37 ) &&
( V_44 -> V_38 == V_45 ) &&
( V_44 -> V_47 == V_42 ) )
return true ;
else
return false ;
}
struct V_17
* F_13 ( struct V_48 * V_48 , T_3 V_49 , T_2 V_45 ,
T_2 V_39 , T_2 V_50 , T_3 V_41 , T_2 V_42 )
{
struct V_18 * V_19 ;
struct V_43 * V_44 ;
struct V_51 * V_52 = F_14 ( & V_48 -> V_53 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_17 * V_23 ;
struct V_54 * V_55 = (struct V_54 * ) V_48 -> V_55 ;
T_4 V_22 = V_50 * V_39 ;
T_2 V_56 ;
F_11 ( V_2 , V_49 , V_45 , V_39 , V_50 , V_41 , V_42 , V_22 ) ;
V_44 = (struct V_43 * ) V_55 -> V_57 ;
F_10 ( V_2 , L_9 , V_55 -> V_58 ) ;
for ( V_56 = 0 ; V_56 < V_55 -> V_58 ; V_56 ++ ) {
if ( F_12 ( V_2 , V_44 , V_49 , V_45 , V_42 ) ) {
V_19 = (struct V_18 * ) ( V_44 -> V_34 . V_35 +
V_44 -> V_34 . V_36 ) ;
V_23 = F_9 ( V_2 , V_19 , V_50 , V_41 , V_22 ) ;
if ( V_23 )
return V_23 ;
}
V_44 = (struct V_43 * ) ( ( T_2 * ) V_44 + V_44 -> V_14 ) ;
}
return NULL ;
}
