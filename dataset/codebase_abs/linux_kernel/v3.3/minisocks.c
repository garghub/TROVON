void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = NULL ;
if ( V_7 . V_8 < V_7 . V_9 )
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_6 != NULL ) {
const struct V_10 * V_11 = F_3 ( V_2 ) ;
const int V_12 = ( V_11 -> V_13 << 2 ) - ( V_11 -> V_13 >> 1 ) ;
#if F_4 ( V_14 )
if ( V_6 -> V_15 == V_16 ) {
const struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_19 * V_20 ;
V_6 -> V_21 = F_6 ( V_2 -> V_22 ) ;
V_20 = F_7 ( (struct V_1 * ) V_6 ) ;
V_20 -> V_23 = V_18 -> V_24 ;
V_20 -> V_25 = V_18 -> V_26 ;
V_6 -> V_27 = V_18 -> V_28 ;
}
#endif
F_8 ( V_6 , V_2 , & V_29 ) ;
if ( V_4 < V_12 )
V_4 = V_12 ;
V_6 -> V_30 = V_31 ;
if ( V_3 == V_32 )
V_4 = V_31 ;
F_9 ( V_6 , & V_7 , V_4 ,
V_31 ) ;
F_10 ( V_6 ) ;
} else {
F_11 ( L_1 ) ;
}
F_12 ( V_2 ) ;
}
struct V_1 * F_13 ( struct V_1 * V_2 ,
const struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_1 * V_37 = F_14 ( V_2 , V_34 , V_38 ) ;
if ( V_37 != NULL ) {
struct V_39 * V_40 = F_15 ( V_34 ) ;
struct V_10 * V_41 = F_3 ( V_37 ) ;
struct V_42 * V_43 = F_16 ( V_37 ) ;
V_43 -> V_44 = V_45 ;
V_43 -> V_46 = NULL ;
V_43 -> V_47 = NULL ;
V_43 -> V_48 = V_40 -> V_49 ;
V_43 -> V_50 = V_40 -> V_51 ;
V_43 -> V_52 = V_40 -> V_53 ;
V_41 -> V_13 = V_54 ;
F_17 ( & V_43 -> V_55 ) ;
V_43 -> V_56 = V_43 -> V_57 = V_40 -> V_58 ;
V_43 -> V_59 = V_43 -> V_57 ;
V_43 -> V_60 = V_43 -> V_61 = V_40 -> V_62 ;
if ( F_18 ( V_37 , & V_40 -> V_63 ) ) {
V_37 -> V_64 = NULL ;
F_19 ( V_37 ) ;
return NULL ;
}
F_20 ( V_37 ) ;
F_21 ( V_65 ) ;
}
return V_37 ;
}
struct V_1 * F_22 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_33 * V_34 ,
struct V_33 * * V_66 )
{
struct V_1 * V_67 = NULL ;
struct V_39 * V_40 = F_15 ( V_34 ) ;
if ( F_23 ( V_36 ) -> V_68 == V_69 ) {
if ( F_24 ( F_25 ( V_36 ) -> V_70 , V_40 -> V_62 ) ) {
F_26 ( L_2 ) ;
V_40 -> V_62 = F_25 ( V_36 ) -> V_70 ;
V_34 -> V_71 ++ ;
V_34 -> V_72 -> V_73 ( V_2 , V_34 , NULL ) ;
}
return NULL ;
}
F_25 ( V_36 ) -> V_74 = V_75 ;
if ( F_23 ( V_36 ) -> V_68 != V_76 &&
F_23 ( V_36 ) -> V_68 != V_77 )
goto V_78;
if ( F_25 ( V_36 ) -> V_79 != V_40 -> V_58 ) {
F_26 ( L_3
L_4 ,
( unsigned long long )
F_25 ( V_36 ) -> V_79 ,
( unsigned long long ) V_40 -> V_58 ) ;
goto V_78;
}
if ( F_27 ( V_2 , V_40 , V_36 ) )
goto V_78;
V_67 = F_3 ( V_2 ) -> V_80 -> V_81 ( V_2 , V_36 , V_34 , NULL ) ;
if ( V_67 == NULL )
goto V_82;
F_28 ( V_2 , V_34 , V_66 ) ;
F_29 ( V_2 , V_34 ) ;
F_30 ( V_2 , V_34 , V_67 ) ;
V_83:
return V_67 ;
V_82:
F_26 ( L_5 ) ;
F_25 ( V_36 ) -> V_74 = V_84 ;
V_78:
if ( F_23 ( V_36 ) -> V_68 != V_85 )
V_34 -> V_72 -> V_86 ( V_2 , V_36 ) ;
F_31 ( V_2 , V_34 , V_66 ) ;
goto V_83;
}
int F_32 ( struct V_1 * V_87 , struct V_1 * V_67 ,
struct V_35 * V_36 )
{
int V_88 = 0 ;
const int V_3 = V_67 -> V_89 ;
if ( ! F_33 ( V_67 ) ) {
V_88 = F_34 ( V_67 , V_36 , F_23 ( V_36 ) ,
V_36 -> V_90 ) ;
if ( V_3 == V_91 && V_67 -> V_89 != V_3 )
V_87 -> V_92 ( V_87 , 0 ) ;
} else {
F_35 ( V_67 , V_36 ) ;
}
F_36 ( V_67 ) ;
F_37 ( V_67 ) ;
return V_88 ;
}
void F_38 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_33 * V_93 )
{
F_39 ( L_6 ) ;
}
int F_40 ( struct V_33 * V_34 ,
struct V_42 const * V_94 , struct V_35 const * V_36 )
{
struct V_39 * V_40 = F_15 ( V_34 ) ;
F_41 ( V_34 ) -> V_95 = F_23 ( V_36 ) -> V_96 ;
F_41 ( V_34 ) -> V_97 = F_23 ( V_36 ) -> V_98 ;
F_41 ( V_34 ) -> V_99 = 0 ;
V_40 -> V_51 = 0 ;
return F_42 ( & V_94 -> V_55 , & V_40 -> V_63 ) ;
}
