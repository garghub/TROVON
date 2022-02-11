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
if ( ! strcmp ( V_26 -> V_37 -> V_38 , V_39 ) &&
V_26 -> V_40 && ! V_26 -> V_41 ) {
V_34 = & V_26 -> V_42 . V_34 ;
V_32 = V_29 ;
V_35 = V_34 -> V_43 -> V_44 . V_45 ;
F_5 ( V_46 , L_2 ,
V_32 -> V_47 , V_35 ) ;
F_8 ( & V_32 -> V_48 ) ;
V_32 -> V_47 &= V_35 ;
if ( V_32 -> V_49 )
F_1 ( V_32 -> V_50 , V_32 -> V_49 ) ;
F_9 ( & V_32 -> V_48 ) ;
V_36 = 0 ;
} else {
F_10 ( L_3 ,
V_26 -> V_37 -> V_38 ,
V_26 -> V_51 , V_26 -> V_40 ,
V_26 -> V_41 ) ;
V_36 = - V_52 ;
}
return V_36 ;
}
int F_11 ( struct V_53 * V_54 , unsigned long V_55 , int V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
T_1 V_67 ;
int V_68 ;
int V_10 ;
V_60 = F_12 ( & V_68 ) ;
if ( F_13 ( V_60 ) )
return F_14 ( V_60 ) ;
V_62 = F_15 ( V_60 ) ;
V_62 -> V_69 = V_54 ;
V_62 -> V_70 = 1 ;
V_10 = F_16 ( V_60 , V_62 , V_71 , V_62 -> V_69 ) ;
if ( V_10 != 0 ) {
F_17 ( V_60 , V_62 ) ;
F_18 ( V_60 , & V_68 ) ;
if ( V_10 > 0 )
V_10 = - V_72 ;
return V_10 ;
}
V_64 = F_19 ( V_60 ) ;
V_66 = & V_64 -> V_73 ;
V_66 -> V_74 = V_54 ;
V_66 -> V_75 = 0 ;
V_66 -> V_76 = V_77 ;
V_66 -> V_78 = V_55 ;
V_66 -> V_79 = V_80 ;
V_67 = V_81 | ( V_56 ? V_82 : 0 ) ;
V_66 -> V_83 = V_67 ;
V_10 = F_20 ( V_60 , V_62 , V_64 ) ;
if ( V_10 < 0 ) {
F_17 ( V_60 , V_62 ) ;
F_18 ( V_60 , & V_68 ) ;
return V_10 ;
}
V_58 -> V_84 = F_12 ( & V_68 ) ;
V_58 -> V_85 = V_62 ;
V_58 -> V_86 = V_64 ;
V_58 -> V_87 = V_55 ;
F_21 ( V_58 -> V_84 == V_60 ) ;
F_22 ( V_60 , & V_68 ) ;
return 0 ;
}
void F_23 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_84 ;
struct V_61 * V_62 = V_58 -> V_85 ;
struct V_63 * V_64 = V_58 -> V_86 ;
int V_68 ;
F_21 ( V_58 -> V_84 ) ;
F_21 ( V_58 -> V_87 ) ;
F_24 ( V_60 , & V_68 ) ;
F_18 ( V_60 , & V_68 ) ;
F_25 ( V_60 , V_64 ) ;
F_17 ( V_60 , V_62 ) ;
F_18 ( V_60 , NULL ) ;
}
