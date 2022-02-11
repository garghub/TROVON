int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_2 V_9 ,
T_2 V_10 , T_2 V_11 , T_3 V_12 , bool V_13 )
{
int V_14 = V_6 -> V_15 ;
struct V_16 * V_17 ;
int V_18 ;
F_2 ( V_6 , V_13 ) ;
F_3 ( V_6 ) ;
F_4 ( V_6 , & V_4 -> V_8 ) ;
memset ( F_5 ( V_6 ) , 0 , sizeof( * F_5 ( V_6 ) ) ) ;
F_6 ( V_6 , sizeof( struct V_16 ) ) ;
F_7 ( V_6 ) ;
V_17 = F_8 ( V_6 ) ;
V_17 -> V_19 = 4 ;
V_17 -> V_20 = sizeof( struct V_16 ) >> 2 ;
V_17 -> V_21 = V_12 ;
V_17 -> V_22 = V_9 ;
V_17 -> V_10 = V_10 ;
V_17 -> V_23 = V_8 ;
V_17 -> V_24 = V_7 ;
V_17 -> V_11 = V_11 ;
F_9 ( V_17 , F_10 ( V_6 ) -> V_25 ? : 1 ) ;
V_18 = F_11 ( V_2 , V_6 ) ;
if ( F_12 ( F_13 ( V_18 ) ) )
V_14 = 0 ;
return V_14 ;
}
int F_14 ( struct V_5 * V_6 , int V_26 , T_3 V_27 )
{
if ( F_12 ( ! F_15 ( V_6 , V_26 ) ) )
return - V_28 ;
F_16 ( V_6 , V_26 ) ;
if ( V_27 == F_17 ( V_29 ) ) {
struct V_30 * V_31 = (struct V_30 * ) V_6 -> V_32 ;
if ( F_12 ( ! F_15 ( V_6 , V_33 ) ) )
return - V_28 ;
if ( F_18 ( F_19 ( V_31 -> V_34 ) >= V_35 ) )
V_6 -> V_22 = V_31 -> V_34 ;
else
V_6 -> V_22 = F_17 ( V_36 ) ;
} else {
V_6 -> V_22 = V_27 ;
}
F_20 ( V_6 ) ;
F_21 ( V_6 ) ;
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
V_6 -> V_37 = 0 ;
F_24 ( V_6 , 0 ) ;
V_6 -> V_38 = V_39 ;
return 0 ;
}
struct V_5 * F_25 ( struct V_5 * V_6 ,
bool V_40 ,
int V_41 )
{
int V_18 ;
if ( F_18 ( ! V_6 -> V_42 ) ) {
F_26 ( V_6 ) ;
V_6 -> V_42 = 1 ;
}
if ( F_27 ( V_6 ) ) {
V_18 = F_28 ( V_6 , V_43 ) ;
if ( F_12 ( V_18 ) )
goto error;
F_10 ( V_6 ) -> V_44 |= V_41 ;
return V_6 ;
}
if ( V_40 )
V_6 -> V_42 = 0 ;
if ( V_6 -> V_45 == V_46 && V_40 ) {
V_18 = F_29 ( V_6 ) ;
if ( F_12 ( V_18 ) )
goto error;
} else if ( V_6 -> V_45 != V_46 )
V_6 -> V_45 = V_47 ;
return V_6 ;
error:
F_30 ( V_6 ) ;
return F_31 ( V_18 ) ;
}
struct V_48 * F_32 ( struct V_49 * V_50 ,
struct V_48 * V_51 )
{
int V_52 ;
F_33 (i) {
const struct V_53 * V_54 =
F_34 ( V_50 -> V_54 , V_52 ) ;
T_4 V_55 , V_56 , V_57 , V_58 ;
unsigned int V_59 ;
do {
V_59 = F_35 ( & V_54 -> V_60 ) ;
V_55 = V_54 -> V_55 ;
V_57 = V_54 -> V_57 ;
V_56 = V_54 -> V_56 ;
V_58 = V_54 -> V_58 ;
} while ( F_36 ( & V_54 -> V_60 , V_59 ) );
V_51 -> V_55 += V_55 ;
V_51 -> V_57 += V_57 ;
V_51 -> V_56 += V_56 ;
V_51 -> V_58 += V_58 ;
}
V_51 -> V_61 = V_50 -> V_62 . V_61 ;
V_51 -> V_63 = V_50 -> V_62 . V_63 ;
V_51 -> V_64 = V_50 -> V_62 . V_64 ;
V_51 -> V_65 = V_50 -> V_62 . V_65 ;
V_51 -> V_66 = V_50 -> V_62 . V_66 ;
V_51 -> V_67 = V_50 -> V_62 . V_67 ;
V_51 -> V_68 = V_50 -> V_62 . V_68 ;
V_51 -> V_69 = V_50 -> V_62 . V_69 ;
V_51 -> V_70 = V_50 -> V_62 . V_70 ;
V_51 -> V_71 = V_50 -> V_62 . V_71 ;
V_51 -> V_72 = V_50 -> V_62 . V_72 ;
V_51 -> V_73 = V_50 -> V_62 . V_73 ;
return V_51 ;
}
