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
V_15 = F_3 ( V_14 . V_18 , ( T_1 ) V_19 ) ;
V_5 . V_20 = V_15 ;
V_11 = F_4 ( V_3 , & V_5 ) ;
V_16 = F_5 ( T_1 , V_14 . V_21 ,
V_19 ) ;
V_5 . V_20 = V_16 ;
V_12 = F_4 ( V_3 , & V_5 ) ;
V_13 = V_15 * sizeof( struct V_22 ) ;
F_6 ( V_23 ,
L_1 ,
V_12 , V_11 , V_13 ) ;
V_10 = F_7 ( V_2 , V_11 , V_12 , V_13 , 0 ) ;
return V_10 ;
}
int F_8 ( struct V_24 * V_25 ,
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
F_6 ( V_44 , L_2 V_45 L_3 V_45 L_4 ,
V_32 -> V_46 , V_35 ) ;
F_9 ( & V_32 -> V_47 ) ;
V_32 -> V_46 &= V_35 ;
if ( V_32 -> V_48 )
F_1 ( V_32 -> V_49 , V_32 -> V_48 ) ;
F_10 ( & V_32 -> V_47 ) ;
V_36 = 0 ;
} else {
F_11 ( L_5 ,
V_26 -> V_37 -> V_38 ,
V_26 -> V_50 ) ;
V_36 = - V_51 ;
}
return V_36 ;
}
int F_12 ( struct V_52 * V_53 , unsigned long V_54 , int V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
T_1 V_66 ;
int V_67 ;
int V_10 ;
V_59 = F_13 ( & V_67 ) ;
if ( F_14 ( V_59 ) )
return F_15 ( V_59 ) ;
V_61 = F_16 ( V_59 ) ;
V_61 -> V_68 = V_53 ;
V_61 -> V_69 = 1 ;
V_10 = F_17 ( V_59 , V_61 , V_70 , V_61 -> V_68 ) ;
if ( V_10 ) {
if ( V_10 > 0 )
V_10 = - V_71 ;
F_18 ( V_59 , & V_67 ) ;
return V_10 ;
}
V_65 = & F_19 ( V_59 ) -> V_72 ;
V_65 -> V_73 = V_53 ;
V_65 -> V_74 = 0 ;
V_65 -> V_75 = V_76 ;
V_65 -> V_77 = V_54 ;
V_65 -> V_78 = V_79 ;
V_66 = V_80 | ( V_55 ? V_81 : 0 ) ;
V_65 -> V_82 = V_66 ;
V_63 = F_20 ( V_59 , V_61 , V_65 , V_83 , V_84 ) ;
if ( F_14 ( V_63 ) ) {
F_21 ( V_59 , V_61 ) ;
F_18 ( V_59 , & V_67 ) ;
return F_15 ( V_63 ) ;
}
V_57 -> V_85 = F_13 ( & V_67 ) ;
V_57 -> V_86 = V_61 ;
V_57 -> V_87 = V_63 ;
V_57 -> V_88 = V_54 ;
F_22 ( V_57 -> V_85 == V_59 ) ;
F_23 ( V_59 , & V_67 ) ;
return 0 ;
}
void F_24 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_85 ;
struct V_60 * V_61 = V_57 -> V_86 ;
struct V_62 * V_63 = V_57 -> V_87 ;
int V_67 ;
F_22 ( V_57 -> V_85 ) ;
F_22 ( V_57 -> V_88 ) ;
F_25 ( V_59 , & V_67 ) ;
F_18 ( V_59 , & V_67 ) ;
F_26 ( V_59 , V_63 ) ;
F_27 ( V_59 , V_63 , V_83 , V_84 ) ;
F_21 ( V_59 , V_61 ) ;
F_18 ( V_59 , NULL ) ;
}
