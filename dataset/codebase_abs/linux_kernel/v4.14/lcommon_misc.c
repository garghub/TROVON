int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
T_1 V_4 , V_5 , V_6 ;
int V_7 ;
V_4 = sizeof( V_5 ) ;
V_7 = F_2 ( NULL , V_3 , sizeof( V_8 ) , V_8 ,
& V_4 , & V_5 ) ;
if ( V_7 )
return V_7 ;
V_4 = sizeof( V_6 ) ;
V_7 = F_2 ( NULL , V_3 , sizeof( V_9 ) ,
V_9 , & V_4 , & V_6 ) ;
if ( V_7 )
return V_7 ;
F_3 ( V_10 , L_1 ,
V_6 , V_5 ) ;
V_7 = F_4 ( V_2 , V_5 , V_6 ) ;
return V_7 ;
}
int F_5 ( struct V_11 * V_12 ,
struct V_11 * V_13 ,
enum V_14 V_15 , void * V_16 , void * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
T_2 V_22 ;
int V_23 ;
if ( ! strcmp ( V_13 -> V_24 -> V_25 , V_26 ) &&
V_13 -> V_27 && ! V_13 -> V_28 ) {
V_21 = & V_13 -> V_29 . V_21 ;
V_19 = V_16 ;
V_22 = V_21 -> V_30 -> V_31 . V_32 ;
F_3 ( V_33 , L_2 ,
V_19 -> V_34 , V_22 ) ;
F_6 ( & V_19 -> V_35 ) ;
V_19 -> V_34 &= V_22 ;
if ( V_19 -> V_36 )
F_1 ( V_19 -> V_37 , V_19 -> V_36 ) ;
F_7 ( & V_19 -> V_35 ) ;
V_23 = 0 ;
} else {
F_8 ( L_3 ,
V_13 -> V_24 -> V_25 ,
V_13 -> V_38 , V_13 -> V_27 ,
V_13 -> V_28 ) ;
V_23 = - V_39 ;
}
return V_23 ;
}
int F_9 ( struct V_40 * V_41 , unsigned long V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_3 V_54 ;
T_4 V_55 ;
int V_7 ;
V_47 = F_10 ( & V_55 ) ;
if ( F_11 ( V_47 ) )
return F_12 ( V_47 ) ;
V_49 = F_13 ( V_47 ) ;
V_49 -> V_56 = V_41 ;
V_7 = F_14 ( V_47 , V_49 , V_57 , V_49 -> V_56 ) ;
if ( V_7 != 0 ) {
F_15 ( V_47 , V_49 ) ;
F_16 ( V_47 , & V_55 ) ;
if ( V_7 > 0 )
V_7 = - V_58 ;
return V_7 ;
}
V_51 = F_17 ( V_47 ) ;
V_53 = & V_51 -> V_59 ;
V_53 -> V_60 = V_41 ;
V_53 -> V_61 = 0 ;
V_53 -> V_62 = V_63 ;
V_53 -> V_64 = V_42 ;
V_53 -> V_65 = V_66 ;
V_54 = V_67 | ( V_43 ? V_68 : 0 ) ;
V_53 -> V_69 = V_54 ;
V_7 = F_18 ( V_47 , V_49 , V_51 ) ;
if ( V_7 < 0 ) {
F_15 ( V_47 , V_49 ) ;
F_16 ( V_47 , & V_55 ) ;
return V_7 ;
}
V_45 -> V_70 = V_47 ;
V_45 -> V_71 = V_49 ;
V_45 -> V_72 = V_51 ;
V_45 -> V_73 = V_42 ;
return 0 ;
}
void F_19 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_70 ;
struct V_48 * V_49 = V_45 -> V_71 ;
struct V_50 * V_51 = V_45 -> V_72 ;
F_20 ( V_45 -> V_70 ) ;
F_20 ( V_45 -> V_73 ) ;
F_21 ( V_47 , V_51 ) ;
F_15 ( V_47 , V_49 ) ;
F_16 ( V_47 , NULL ) ;
}
