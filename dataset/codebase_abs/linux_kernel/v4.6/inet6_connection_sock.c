int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_5 )
{
const struct V_1 * V_6 ;
int V_7 = V_2 -> V_8 ;
int V_9 = V_2 -> V_10 ;
T_1 V_11 = F_2 ( (struct V_1 * ) V_2 ) ;
F_3 (sk2, &tb->owners) {
if ( V_2 != V_6 &&
( ! V_2 -> V_12 ||
! V_6 -> V_12 ||
V_2 -> V_12 == V_6 -> V_12 ) ) {
if ( ( ! V_7 || ! V_6 -> V_8 ||
V_6 -> V_13 == V_14 ) &&
( ! V_9 || ! V_6 -> V_10 ||
F_4 ( V_2 -> V_15 ) ||
( V_6 -> V_13 != V_16 &&
! F_5 ( V_11 ,
F_2 ( (struct V_1 * ) V_6 ) ) ) ) ) {
if ( F_6 ( V_2 , V_6 , true ) )
break;
}
if ( ! V_5 && V_7 && V_6 -> V_8 &&
V_6 -> V_13 != V_14 &&
F_6 ( V_2 , V_6 , true ) )
break;
}
}
return V_6 != NULL ;
}
struct V_17 * F_7 ( const struct V_1 * V_2 ,
struct V_18 * V_19 ,
const struct V_20 * V_21 ,
T_2 V_22 )
{
struct V_23 * V_24 = F_8 ( V_21 ) ;
const struct V_25 * V_26 = F_9 ( V_2 ) ;
struct V_27 * V_28 , V_29 ;
struct V_17 * V_30 ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_31 = V_22 ;
V_19 -> V_32 = V_24 -> V_33 ;
F_10 () ;
V_28 = F_11 ( V_19 , F_12 ( V_26 -> V_34 ) , & V_29 ) ;
F_13 () ;
V_19 -> V_35 = V_24 -> V_36 ;
V_19 -> V_37 = V_24 -> V_38 ;
V_19 -> V_39 = V_24 -> V_40 ;
V_19 -> V_41 = V_24 -> V_42 ;
V_19 -> V_43 = F_14 ( V_24 -> V_44 ) ;
F_15 ( V_21 , F_16 ( V_19 ) ) ;
V_30 = F_17 ( V_2 , V_19 , V_28 ) ;
if ( F_18 ( V_30 ) )
return NULL ;
return V_30 ;
}
void F_19 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_47 * V_48 = (struct V_47 * ) V_46 ;
V_48 -> V_49 = V_50 ;
V_48 -> V_51 = V_2 -> V_52 ;
V_48 -> V_53 = F_20 ( V_2 ) -> V_54 ;
V_48 -> V_55 = 0 ;
V_48 -> V_56 = F_21 ( & V_48 -> V_51 ,
V_2 -> V_12 ) ;
}
static inline
struct V_17 * F_22 ( struct V_1 * V_2 , T_3 V_57 )
{
return F_23 ( V_2 , V_57 ) ;
}
static struct V_17 * F_24 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_58 * V_59 = F_20 ( V_2 ) ;
struct V_25 * V_26 = F_9 ( V_2 ) ;
struct V_27 * V_28 , V_29 ;
struct V_17 * V_30 ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_31 = V_2 -> V_60 ;
V_19 -> V_32 = V_2 -> V_52 ;
V_19 -> V_35 = V_26 -> V_35 ;
V_19 -> V_61 = V_26 -> V_62 ;
F_25 ( V_2 , V_19 -> V_61 ) ;
V_19 -> V_37 = V_2 -> V_12 ;
V_19 -> V_39 = V_2 -> V_63 ;
V_19 -> V_43 = V_59 -> V_64 ;
V_19 -> V_41 = V_59 -> V_54 ;
F_26 ( V_2 , F_16 ( V_19 ) ) ;
F_10 () ;
V_28 = F_11 ( V_19 , F_12 ( V_26 -> V_34 ) , & V_29 ) ;
F_13 () ;
V_30 = F_22 ( V_2 , V_26 -> V_65 ) ;
if ( ! V_30 ) {
V_30 = F_17 ( V_2 , V_19 , V_28 ) ;
if ( ! F_18 ( V_30 ) )
F_27 ( V_2 , V_30 , NULL , NULL ) ;
}
return V_30 ;
}
int F_28 ( struct V_1 * V_2 , struct V_66 * V_67 , struct V_68 * V_69 )
{
struct V_25 * V_26 = F_9 ( V_2 ) ;
struct V_18 V_19 ;
struct V_17 * V_30 ;
int V_70 ;
V_30 = F_24 ( V_2 , & V_19 ) ;
if ( F_18 ( V_30 ) ) {
V_2 -> V_71 = - F_29 ( V_30 ) ;
V_2 -> V_72 = 0 ;
F_30 ( V_67 ) ;
return F_29 ( V_30 ) ;
}
F_10 () ;
F_31 ( V_67 , V_30 ) ;
V_19 . V_32 = V_2 -> V_52 ;
V_70 = F_32 ( V_2 , V_67 , & V_19 , F_12 ( V_26 -> V_34 ) ,
V_26 -> V_73 ) ;
F_13 () ;
return V_70 ;
}
struct V_17 * F_33 ( struct V_1 * V_2 , T_3 V_74 )
{
struct V_18 V_19 ;
struct V_17 * V_30 = F_24 ( V_2 , & V_19 ) ;
if ( F_18 ( V_30 ) )
return NULL ;
V_30 -> V_75 -> V_76 ( V_30 , V_2 , NULL , V_74 ) ;
V_30 = F_24 ( V_2 , & V_19 ) ;
return F_18 ( V_30 ) ? NULL : V_30 ;
}
