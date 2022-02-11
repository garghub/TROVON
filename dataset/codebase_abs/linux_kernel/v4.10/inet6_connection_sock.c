int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_5 ,
bool V_6 )
{
const struct V_1 * V_7 ;
bool V_8 = ! ! V_2 -> V_9 ;
bool V_10 = ! ! V_2 -> V_11 && V_6 ;
T_1 V_12 = F_2 ( (struct V_1 * ) V_2 ) ;
F_3 (sk2, &tb->owners) {
if ( V_2 != V_7 &&
( ! V_2 -> V_13 ||
! V_7 -> V_13 ||
V_2 -> V_13 == V_7 -> V_13 ) ) {
if ( ( ! V_8 || ! V_7 -> V_9 ||
V_7 -> V_14 == V_15 ) &&
( ! V_10 || ! V_7 -> V_11 ||
F_4 ( V_2 -> V_16 ) ||
( V_7 -> V_14 != V_17 &&
! F_5 ( V_12 ,
F_2 ( (struct V_1 * ) V_7 ) ) ) ) ) {
if ( F_6 ( V_2 , V_7 , true ) )
break;
}
if ( ! V_5 && V_8 && V_7 -> V_9 &&
V_7 -> V_14 != V_15 &&
F_6 ( V_2 , V_7 , true ) )
break;
}
}
return V_7 != NULL ;
}
struct V_18 * F_7 ( const struct V_1 * V_2 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 ,
T_2 V_23 )
{
struct V_24 * V_25 = F_8 ( V_22 ) ;
const struct V_26 * V_27 = F_9 ( V_2 ) ;
struct V_28 * V_29 , V_30 ;
struct V_18 * V_31 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_32 = V_23 ;
V_20 -> V_33 = V_25 -> V_34 ;
F_10 () ;
V_29 = F_11 ( V_20 , F_12 ( V_27 -> V_35 ) , & V_30 ) ;
F_13 () ;
V_20 -> V_36 = V_25 -> V_37 ;
V_20 -> V_38 = V_25 -> V_39 ;
V_20 -> V_40 = V_25 -> V_41 ;
V_20 -> V_42 = V_25 -> V_43 ;
V_20 -> V_44 = F_14 ( V_25 -> V_45 ) ;
V_20 -> V_46 = V_2 -> V_47 ;
F_15 ( V_22 , F_16 ( V_20 ) ) ;
V_31 = F_17 ( V_2 , V_20 , V_29 ) ;
if ( F_18 ( V_31 ) )
return NULL ;
return V_31 ;
}
void F_19 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_49 ;
V_51 -> V_52 = V_53 ;
V_51 -> V_54 = V_2 -> V_55 ;
V_51 -> V_56 = F_20 ( V_2 ) -> V_57 ;
V_51 -> V_58 = 0 ;
V_51 -> V_59 = F_21 ( & V_51 -> V_54 ,
V_2 -> V_13 ) ;
}
static inline
struct V_18 * F_22 ( struct V_1 * V_2 , T_3 V_60 )
{
return F_23 ( V_2 , V_60 ) ;
}
static struct V_18 * F_24 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_61 * V_62 = F_20 ( V_2 ) ;
struct V_26 * V_27 = F_9 ( V_2 ) ;
struct V_28 * V_29 , V_30 ;
struct V_18 * V_31 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_32 = V_2 -> V_63 ;
V_20 -> V_33 = V_2 -> V_55 ;
V_20 -> V_36 = V_27 -> V_36 ;
V_20 -> V_64 = V_27 -> V_65 ;
F_25 ( V_2 , V_20 -> V_64 ) ;
V_20 -> V_38 = V_2 -> V_13 ;
V_20 -> V_40 = V_2 -> V_66 ;
V_20 -> V_44 = V_62 -> V_67 ;
V_20 -> V_42 = V_62 -> V_57 ;
V_20 -> V_46 = V_2 -> V_47 ;
F_26 ( V_2 , F_16 ( V_20 ) ) ;
F_10 () ;
V_29 = F_11 ( V_20 , F_12 ( V_27 -> V_35 ) , & V_30 ) ;
F_13 () ;
V_31 = F_22 ( V_2 , V_27 -> V_68 ) ;
if ( ! V_31 ) {
V_31 = F_17 ( V_2 , V_20 , V_29 ) ;
if ( ! F_18 ( V_31 ) )
F_27 ( V_2 , V_31 , NULL , NULL ) ;
}
return V_31 ;
}
int F_28 ( struct V_1 * V_2 , struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
struct V_19 V_20 ;
struct V_18 * V_31 ;
int V_73 ;
V_31 = F_24 ( V_2 , & V_20 ) ;
if ( F_18 ( V_31 ) ) {
V_2 -> V_74 = - F_29 ( V_31 ) ;
V_2 -> V_75 = 0 ;
F_30 ( V_70 ) ;
return F_29 ( V_31 ) ;
}
F_10 () ;
F_31 ( V_70 , V_31 ) ;
V_20 . V_33 = V_2 -> V_55 ;
V_73 = F_32 ( V_2 , V_70 , & V_20 , V_2 -> V_66 , F_12 ( V_27 -> V_35 ) ,
V_27 -> V_76 ) ;
F_13 () ;
return V_73 ;
}
struct V_18 * F_33 ( struct V_1 * V_2 , T_3 V_77 )
{
struct V_19 V_20 ;
struct V_18 * V_31 = F_24 ( V_2 , & V_20 ) ;
if ( F_18 ( V_31 ) )
return NULL ;
V_31 -> V_78 -> V_79 ( V_31 , V_2 , NULL , V_77 ) ;
V_31 = F_24 ( V_2 , & V_20 ) ;
return F_18 ( V_31 ) ? NULL : V_31 ;
}
