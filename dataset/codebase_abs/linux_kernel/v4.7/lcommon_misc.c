int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_4 V_5 = { . V_6 = V_7 } ;
T_1 V_8 = sizeof( struct V_9 ) ;
int V_10 , V_11 , V_12 , V_13 ;
struct V_9 V_14 ;
T_2 V_15 , V_16 ;
V_10 = F_2 ( NULL , V_3 , sizeof( V_17 ) , V_17 ,
& V_8 , & V_14 , NULL ) ;
if ( V_10 )
return V_10 ;
V_15 = F_3 ( T_1 , V_14 . V_18 , V_19 ) ;
V_5 . V_20 = V_15 ;
V_11 = F_4 ( V_3 , & V_5 ) ;
V_16 = F_3 ( T_1 , V_14 . V_21 ,
V_19 ) ;
V_5 . V_20 = V_16 ;
V_12 = F_4 ( V_3 , & V_5 ) ;
V_13 = V_15 * sizeof( struct V_22 ) ;
F_5 ( V_23 ,
L_1 ,
V_12 , V_11 , V_13 ) ;
V_10 = F_6 ( V_2 , V_11 , V_12 , V_13 , 0 ) ;
return V_10 ;
}
int F_7 ( struct V_24 * V_25 ,
struct V_24 * V_26 ,
enum V_27 V_28 , void * V_29 , void * V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_3 V_35 ;
int V_36 ;
if ( ! strcmp ( V_26 -> V_37 -> V_38 , V_39 ) ) {
V_34 = & V_26 -> V_40 . V_34 ;
V_32 = V_29 ;
V_35 = V_34 -> V_41 -> V_42 . V_43 ;
F_5 ( V_44 , L_2 ,
V_32 -> V_45 , V_35 ) ;
F_8 ( & V_32 -> V_46 ) ;
V_32 -> V_45 &= V_35 ;
if ( V_32 -> V_47 )
F_1 ( V_32 -> V_48 , V_32 -> V_47 ) ;
F_9 ( & V_32 -> V_46 ) ;
V_36 = 0 ;
} else {
F_10 ( L_3 ,
V_26 -> V_37 -> V_38 ,
V_26 -> V_49 ) ;
V_36 = - V_50 ;
}
return V_36 ;
}
int F_11 ( struct V_51 * V_52 , unsigned long V_53 , int V_54 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_1 V_65 ;
int V_66 ;
int V_10 ;
V_58 = F_12 ( & V_66 ) ;
if ( F_13 ( V_58 ) )
return F_14 ( V_58 ) ;
V_60 = F_15 ( V_58 ) ;
V_60 -> V_67 = V_52 ;
V_60 -> V_68 = 1 ;
V_10 = F_16 ( V_58 , V_60 , V_69 , V_60 -> V_67 ) ;
if ( V_10 != 0 ) {
F_17 ( V_58 , V_60 ) ;
F_18 ( V_58 , & V_66 ) ;
if ( V_10 > 0 )
V_10 = - V_70 ;
return V_10 ;
}
V_62 = F_19 ( V_58 ) ;
V_64 = & V_62 -> V_71 ;
V_64 -> V_72 = V_52 ;
V_64 -> V_73 = 0 ;
V_64 -> V_74 = V_75 ;
V_64 -> V_76 = V_53 ;
V_64 -> V_77 = V_78 ;
V_65 = V_79 | ( V_54 ? V_80 : 0 ) ;
V_64 -> V_81 = V_65 ;
V_10 = F_20 ( V_58 , V_60 , V_62 ) ;
if ( V_10 < 0 ) {
F_17 ( V_58 , V_60 ) ;
F_18 ( V_58 , & V_66 ) ;
return V_10 ;
}
V_56 -> V_82 = F_12 ( & V_66 ) ;
V_56 -> V_83 = V_60 ;
V_56 -> V_84 = V_62 ;
V_56 -> V_85 = V_53 ;
F_21 ( V_56 -> V_82 == V_58 ) ;
F_22 ( V_58 , & V_66 ) ;
return 0 ;
}
void F_23 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_82 ;
struct V_59 * V_60 = V_56 -> V_83 ;
struct V_61 * V_62 = V_56 -> V_84 ;
int V_66 ;
F_21 ( V_56 -> V_82 ) ;
F_21 ( V_56 -> V_85 ) ;
F_24 ( V_58 , & V_66 ) ;
F_18 ( V_58 , & V_66 ) ;
F_25 ( V_58 , V_62 ) ;
F_17 ( V_58 , V_60 ) ;
F_18 ( V_58 , NULL ) ;
}
