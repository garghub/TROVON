int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 , T_2 V_7 ,
T_2 V_8 , T_2 V_9 , T_3 V_10 , bool V_11 )
{
int V_12 = V_4 -> V_13 ;
struct V_14 * V_15 ;
int V_16 ;
F_2 ( V_4 , V_11 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 , & V_2 -> V_6 ) ;
memset ( F_5 ( V_4 ) , 0 , sizeof( * F_5 ( V_4 ) ) ) ;
F_6 ( V_4 , sizeof( struct V_14 ) ) ;
F_7 ( V_4 ) ;
V_15 = F_8 ( V_4 ) ;
V_15 -> V_17 = 4 ;
V_15 -> V_18 = sizeof( struct V_14 ) >> 2 ;
V_15 -> V_19 = V_10 ;
V_15 -> V_20 = V_7 ;
V_15 -> V_8 = V_8 ;
V_15 -> V_21 = V_6 ;
V_15 -> V_22 = V_5 ;
V_15 -> V_9 = V_9 ;
F_9 ( V_15 , & V_2 -> V_6 , ( F_10 ( V_4 ) -> V_23 ? : 1 ) - 1 ) ;
V_16 = F_11 ( V_4 ) ;
if ( F_12 ( F_13 ( V_16 ) ) )
V_12 = 0 ;
return V_12 ;
}
int F_14 ( struct V_3 * V_4 , int V_24 , T_3 V_25 )
{
if ( F_12 ( ! F_15 ( V_4 , V_24 ) ) )
return - V_26 ;
F_16 ( V_4 , V_24 ) ;
if ( V_25 == F_17 ( V_27 ) ) {
struct V_28 * V_29 = (struct V_28 * ) V_4 -> V_30 ;
if ( F_12 ( ! F_15 ( V_4 , V_31 ) ) )
return - V_26 ;
if ( F_18 ( F_19 ( V_29 -> V_32 ) >= V_33 ) )
V_4 -> V_20 = V_29 -> V_32 ;
else
V_4 -> V_20 = F_17 ( V_34 ) ;
} else {
V_4 -> V_20 = V_25 ;
}
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
F_23 ( V_4 ) ;
V_4 -> V_35 = 0 ;
F_24 ( V_4 , 0 ) ;
V_4 -> V_36 = V_37 ;
return 0 ;
}
struct V_3 * F_25 ( struct V_3 * V_4 ,
bool V_38 ,
int V_39 )
{
int V_16 ;
if ( F_18 ( ! V_4 -> V_40 ) ) {
F_26 ( V_4 ) ;
V_4 -> V_40 = 1 ;
}
if ( F_27 ( V_4 ) ) {
V_16 = F_28 ( V_4 , V_41 ) ;
if ( F_12 ( V_16 ) )
goto error;
F_10 ( V_4 ) -> V_42 |= V_39 ;
return V_4 ;
}
if ( V_4 -> V_43 == V_44 && V_38 ) {
V_16 = F_29 ( V_4 ) ;
if ( F_12 ( V_16 ) )
goto error;
} else if ( V_4 -> V_43 != V_44 )
V_4 -> V_43 = V_45 ;
return V_4 ;
error:
F_30 ( V_4 ) ;
return F_31 ( V_16 ) ;
}
struct V_46 * F_32 ( struct V_47 * V_48 ,
struct V_46 * V_49 )
{
int V_50 ;
F_33 (i) {
const struct V_51 * V_52 =
F_34 ( V_48 -> V_52 , V_50 ) ;
T_4 V_53 , V_54 , V_55 , V_56 ;
unsigned int V_57 ;
do {
V_57 = F_35 ( & V_52 -> V_58 ) ;
V_53 = V_52 -> V_53 ;
V_55 = V_52 -> V_55 ;
V_54 = V_52 -> V_54 ;
V_56 = V_52 -> V_56 ;
} while ( F_36 ( & V_52 -> V_58 , V_57 ) );
V_49 -> V_53 += V_53 ;
V_49 -> V_55 += V_55 ;
V_49 -> V_54 += V_54 ;
V_49 -> V_56 += V_56 ;
}
V_49 -> V_59 = V_48 -> V_60 . V_59 ;
V_49 -> V_61 = V_48 -> V_60 . V_61 ;
V_49 -> V_62 = V_48 -> V_60 . V_62 ;
V_49 -> V_63 = V_48 -> V_60 . V_63 ;
V_49 -> V_64 = V_48 -> V_60 . V_64 ;
V_49 -> V_65 = V_48 -> V_60 . V_65 ;
V_49 -> V_66 = V_48 -> V_60 . V_66 ;
V_49 -> V_67 = V_48 -> V_60 . V_67 ;
V_49 -> V_68 = V_48 -> V_60 . V_68 ;
V_49 -> V_69 = V_48 -> V_60 . V_69 ;
V_49 -> V_70 = V_48 -> V_60 . V_70 ;
V_49 -> V_71 = V_48 -> V_60 . V_71 ;
return V_49 ;
}
