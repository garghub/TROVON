struct V_1 * F_1 ( const struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_9 * V_10 = F_2 ( V_7 ) ;
const struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_13 * V_14 , V_15 ;
struct V_1 * V_16 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_17 = V_8 ;
V_5 -> V_18 = V_10 -> V_19 ;
F_4 () ;
V_14 = F_5 ( V_5 , F_6 ( V_12 -> V_20 ) , & V_15 ) ;
F_7 () ;
V_5 -> V_21 = V_10 -> V_22 ;
V_5 -> V_23 = V_10 -> V_24 ;
V_5 -> V_25 = V_10 -> V_26 ;
V_5 -> V_27 = V_10 -> V_28 ;
V_5 -> V_29 = F_8 ( V_10 -> V_30 ) ;
V_5 -> V_31 = V_3 -> V_32 ;
F_9 ( V_7 , F_10 ( V_5 ) ) ;
V_16 = F_11 ( V_3 , V_5 , V_14 ) ;
if ( F_12 ( V_16 ) )
return NULL ;
return V_16 ;
}
void F_13 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 ;
V_36 -> V_37 = V_38 ;
V_36 -> V_39 = V_3 -> V_40 ;
V_36 -> V_41 = F_14 ( V_3 ) -> V_42 ;
V_36 -> V_43 = 0 ;
V_36 -> V_44 = F_15 ( & V_36 -> V_39 ,
V_3 -> V_45 ) ;
}
static inline
struct V_1 * F_16 ( struct V_2 * V_3 , T_2 V_46 )
{
return F_17 ( V_3 , V_46 ) ;
}
static struct V_1 * F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_47 * V_48 = F_14 ( V_3 ) ;
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_13 * V_14 , V_15 ;
struct V_1 * V_16 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_17 = V_3 -> V_49 ;
V_5 -> V_18 = V_3 -> V_40 ;
V_5 -> V_21 = V_12 -> V_21 ;
V_5 -> V_50 = V_12 -> V_51 ;
F_19 ( V_3 , V_5 -> V_50 ) ;
V_5 -> V_23 = V_3 -> V_45 ;
V_5 -> V_25 = V_3 -> V_52 ;
V_5 -> V_29 = V_48 -> V_53 ;
V_5 -> V_27 = V_48 -> V_42 ;
V_5 -> V_31 = V_3 -> V_32 ;
F_20 ( V_3 , F_10 ( V_5 ) ) ;
F_4 () ;
V_14 = F_5 ( V_5 , F_6 ( V_12 -> V_20 ) , & V_15 ) ;
F_7 () ;
V_16 = F_16 ( V_3 , V_12 -> V_54 ) ;
if ( ! V_16 ) {
V_16 = F_11 ( V_3 , V_5 , V_14 ) ;
if ( ! F_12 ( V_16 ) )
F_21 ( V_3 , V_16 , NULL , NULL ) ;
}
return V_16 ;
}
int F_22 ( struct V_2 * V_3 , struct V_55 * V_56 , struct V_57 * V_58 )
{
struct V_11 * V_12 = F_3 ( V_3 ) ;
struct V_4 V_5 ;
struct V_1 * V_16 ;
int V_59 ;
V_16 = F_18 ( V_3 , & V_5 ) ;
if ( F_12 ( V_16 ) ) {
V_3 -> V_60 = - F_23 ( V_16 ) ;
V_3 -> V_61 = 0 ;
F_24 ( V_56 ) ;
return F_23 ( V_16 ) ;
}
F_4 () ;
F_25 ( V_56 , V_16 ) ;
V_5 . V_18 = V_3 -> V_40 ;
V_59 = F_26 ( V_3 , V_56 , & V_5 , V_3 -> V_52 , F_6 ( V_12 -> V_20 ) ,
V_12 -> V_62 ) ;
F_7 () ;
return V_59 ;
}
struct V_1 * F_27 ( struct V_2 * V_3 , T_2 V_63 )
{
struct V_4 V_5 ;
struct V_1 * V_16 = F_18 ( V_3 , & V_5 ) ;
if ( F_12 ( V_16 ) )
return NULL ;
V_16 -> V_64 -> V_65 ( V_16 , V_3 , NULL , V_63 ) ;
V_16 = F_18 ( V_3 , & V_5 ) ;
return F_12 ( V_16 ) ? NULL : V_16 ;
}
