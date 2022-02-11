int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_4 V_5 = { . V_6 = V_7 } ;
T_1 V_8 = sizeof( struct V_9 ) ;
int V_10 , V_11 , V_12 , V_13 ;
struct V_9 V_14 ;
T_2 V_15 ;
V_10 = F_2 ( NULL , V_3 , sizeof( V_16 ) , V_16 ,
& V_8 , & V_14 , NULL ) ;
if ( V_10 )
return V_10 ;
V_15 = F_3 ( V_14 . V_17 , ( T_1 ) V_18 ) ;
V_5 . V_19 = V_15 ;
V_11 = F_4 ( V_3 , & V_5 ) ;
V_5 . V_19 = V_14 . V_20 ;
V_12 = F_4 ( V_3 , & V_5 ) ;
V_13 = V_15 * sizeof( struct V_21 ) ;
F_5 ( V_22 , L_1 ,
V_11 , V_13 ) ;
V_10 = F_6 ( V_2 , V_11 , V_12 , V_13 ) ;
return V_10 ;
}
int F_7 ( struct V_23 * V_24 ,
struct V_23 * V_25 ,
enum V_26 V_27 , void * V_28 , void * V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_3 V_34 ;
int V_35 ;
if ( ! strcmp ( V_25 -> V_36 -> V_37 , V_38 ) ) {
V_33 = & V_25 -> V_39 . V_33 ;
V_31 = V_28 ;
V_34 = V_33 -> V_40 -> V_41 . V_42 ;
F_5 ( V_43 , L_2 V_44 L_3 V_44 L_4 ,
V_31 -> V_45 , V_34 ) ;
F_8 ( & V_31 -> V_46 ) ;
V_31 -> V_45 &= V_34 ;
if ( V_31 -> V_47 )
F_1 ( V_31 -> V_48 , V_31 -> V_47 ) ;
F_9 ( & V_31 -> V_46 ) ;
V_35 = 0 ;
} else {
F_10 ( L_5 ,
V_25 -> V_36 -> V_37 ,
V_25 -> V_49 ) ;
V_35 = - V_50 ;
}
return V_35 ;
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
if ( V_10 ) {
if ( V_10 > 0 )
V_10 = - V_70 ;
F_17 ( V_58 , & V_66 ) ;
return V_10 ;
}
V_64 = & F_18 ( V_58 ) -> V_71 ;
V_64 -> V_72 = V_52 ;
V_64 -> V_73 = 0 ;
V_64 -> V_74 = V_75 ;
V_64 -> V_76 = V_53 ;
V_64 -> V_77 = V_78 ;
V_65 = V_79 | ( V_54 ? V_80 : 0 ) ;
V_64 -> V_81 = V_65 ;
V_62 = F_19 ( V_58 , V_60 , V_64 , V_82 , V_83 ) ;
if ( F_13 ( V_62 ) ) {
F_20 ( V_58 , V_60 ) ;
F_17 ( V_58 , & V_66 ) ;
return F_14 ( V_62 ) ;
}
V_56 -> V_84 = F_12 ( & V_66 ) ;
V_56 -> V_85 = V_60 ;
V_56 -> V_86 = V_62 ;
V_56 -> V_87 = V_53 ;
F_21 ( V_56 -> V_84 == V_58 ) ;
F_22 ( V_58 , & V_66 ) ;
return 0 ;
}
void F_23 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = V_56 -> V_84 ;
struct V_59 * V_60 = V_56 -> V_85 ;
struct V_61 * V_62 = V_56 -> V_86 ;
int V_66 ;
F_21 ( V_56 -> V_84 ) ;
F_21 ( V_56 -> V_87 ) ;
F_24 ( V_58 , & V_66 ) ;
F_17 ( V_58 , & V_66 ) ;
F_25 ( V_58 , V_62 ) ;
F_26 ( V_58 , V_62 , V_82 , V_83 ) ;
F_20 ( V_58 , V_60 ) ;
F_17 ( V_58 , NULL ) ;
}
