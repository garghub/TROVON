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
( V_6 -> V_13 != V_15 &&
! F_4 ( V_11 ,
F_2 ( (struct V_1 * ) V_6 ) ) ) ) ) {
if ( F_5 ( V_2 , V_6 ) )
break;
}
if ( ! V_5 && V_7 && V_6 -> V_8 &&
V_6 -> V_13 != V_14 &&
F_5 ( V_2 , V_6 ) )
break;
}
}
return V_6 != NULL ;
}
struct V_16 * F_6 ( const struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_19 * V_20 ,
T_2 V_21 )
{
struct V_22 * V_23 = F_7 ( V_20 ) ;
const struct V_24 * V_25 = F_8 ( V_2 ) ;
struct V_26 * V_27 , V_28 ;
struct V_16 * V_29 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_30 = V_21 ;
V_18 -> V_31 = V_23 -> V_32 ;
F_9 () ;
V_27 = F_10 ( V_18 , F_11 ( V_25 -> V_33 ) , & V_28 ) ;
F_12 () ;
V_18 -> V_34 = V_23 -> V_35 ;
V_18 -> V_36 = V_23 -> V_37 ;
V_18 -> V_38 = V_23 -> V_39 ;
V_18 -> V_40 = V_23 -> V_41 ;
V_18 -> V_42 = F_13 ( V_23 -> V_43 ) ;
F_14 ( V_20 , F_15 ( V_18 ) ) ;
V_29 = F_16 ( V_2 , V_18 , V_27 ) ;
if ( F_17 ( V_29 ) )
return NULL ;
return V_29 ;
}
void F_18 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_46 * V_47 = (struct V_46 * ) V_45 ;
V_47 -> V_48 = V_49 ;
V_47 -> V_50 = V_2 -> V_51 ;
V_47 -> V_52 = F_19 ( V_2 ) -> V_53 ;
V_47 -> V_54 = 0 ;
V_47 -> V_55 = F_20 ( & V_47 -> V_50 ,
V_2 -> V_12 ) ;
}
static inline
struct V_16 * F_21 ( struct V_1 * V_2 , T_3 V_56 )
{
return F_22 ( V_2 , V_56 ) ;
}
static struct V_16 * F_23 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_57 * V_58 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_8 ( V_2 ) ;
struct V_26 * V_27 , V_28 ;
struct V_16 * V_29 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_30 = V_2 -> V_59 ;
V_18 -> V_31 = V_2 -> V_51 ;
V_18 -> V_34 = V_25 -> V_34 ;
V_18 -> V_60 = V_25 -> V_61 ;
F_24 ( V_2 , V_18 -> V_60 ) ;
V_18 -> V_36 = V_2 -> V_12 ;
V_18 -> V_38 = V_2 -> V_62 ;
V_18 -> V_42 = V_58 -> V_63 ;
V_18 -> V_40 = V_58 -> V_53 ;
F_25 ( V_2 , F_15 ( V_18 ) ) ;
F_9 () ;
V_27 = F_10 ( V_18 , F_11 ( V_25 -> V_33 ) , & V_28 ) ;
F_12 () ;
V_29 = F_21 ( V_2 , V_25 -> V_64 ) ;
if ( ! V_29 ) {
V_29 = F_16 ( V_2 , V_18 , V_27 ) ;
if ( ! F_17 ( V_29 ) )
F_26 ( V_2 , V_29 , NULL , NULL ) ;
}
return V_29 ;
}
int F_27 ( struct V_1 * V_2 , struct V_65 * V_66 , struct V_67 * V_68 )
{
struct V_24 * V_25 = F_8 ( V_2 ) ;
struct V_17 V_18 ;
struct V_16 * V_29 ;
int V_69 ;
V_29 = F_23 ( V_2 , & V_18 ) ;
if ( F_17 ( V_29 ) ) {
V_2 -> V_70 = - F_28 ( V_29 ) ;
V_2 -> V_71 = 0 ;
F_29 ( V_66 ) ;
return F_28 ( V_29 ) ;
}
F_9 () ;
F_30 ( V_66 , V_29 ) ;
V_18 . V_31 = V_2 -> V_51 ;
V_69 = F_31 ( V_2 , V_66 , & V_18 , F_11 ( V_25 -> V_33 ) ,
V_25 -> V_72 ) ;
F_12 () ;
return V_69 ;
}
struct V_16 * F_32 ( struct V_1 * V_2 , T_3 V_73 )
{
struct V_17 V_18 ;
struct V_16 * V_29 = F_23 ( V_2 , & V_18 ) ;
if ( F_17 ( V_29 ) )
return NULL ;
V_29 -> V_74 -> V_75 ( V_29 , V_2 , NULL , V_73 ) ;
V_29 = F_23 ( V_2 , & V_18 ) ;
return F_17 ( V_29 ) ? NULL : V_29 ;
}
