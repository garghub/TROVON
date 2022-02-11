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
V_43 -> V_56 = V_40 -> V_57 ;
V_43 -> V_58 = V_40 -> V_59 ;
V_43 -> V_60 = V_43 -> V_56 ;
V_43 -> V_61 = V_40 -> V_62 ;
V_43 -> V_63 = V_40 -> V_64 ;
if ( F_18 ( V_37 , & V_40 -> V_65 ) ) {
V_37 -> V_66 = NULL ;
F_19 ( V_37 ) ;
return NULL ;
}
F_20 ( V_37 ) ;
F_21 ( V_67 ) ;
}
return V_37 ;
}
struct V_1 * F_22 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_33 * V_34 ,
struct V_33 * * V_68 )
{
struct V_1 * V_69 = NULL ;
struct V_39 * V_40 = F_15 ( V_34 ) ;
if ( F_23 ( V_36 ) -> V_70 == V_71 ) {
if ( F_24 ( F_25 ( V_36 ) -> V_72 , V_40 -> V_64 ) ) {
F_26 ( L_2 ) ;
V_40 -> V_64 = F_25 ( V_36 ) -> V_72 ;
V_34 -> V_73 ++ ;
V_34 -> V_74 -> V_75 ( V_2 , V_34 , NULL ) ;
}
return NULL ;
}
F_25 ( V_36 ) -> V_76 = V_77 ;
if ( F_23 ( V_36 ) -> V_70 != V_78 &&
F_23 ( V_36 ) -> V_70 != V_79 )
goto V_80;
if ( ! F_27 ( F_25 ( V_36 ) -> V_81 ,
V_40 -> V_57 , V_40 -> V_59 ) ) {
F_26 ( L_3
L_4 ,
( unsigned long long )
F_25 ( V_36 ) -> V_81 ,
( unsigned long long ) V_40 -> V_57 ,
( unsigned long long ) V_40 -> V_59 ) ;
goto V_80;
}
if ( F_28 ( V_2 , V_40 , V_36 ) )
goto V_80;
V_69 = F_3 ( V_2 ) -> V_82 -> V_83 ( V_2 , V_36 , V_34 , NULL ) ;
if ( V_69 == NULL )
goto V_84;
F_29 ( V_2 , V_34 , V_68 ) ;
F_30 ( V_2 , V_34 ) ;
F_31 ( V_2 , V_34 , V_69 ) ;
V_85:
return V_69 ;
V_84:
F_26 ( L_5 ) ;
F_25 ( V_36 ) -> V_76 = V_86 ;
V_80:
if ( F_23 ( V_36 ) -> V_70 != V_87 )
V_34 -> V_74 -> V_88 ( V_2 , V_36 ) ;
F_32 ( V_2 , V_34 , V_68 ) ;
goto V_85;
}
int F_33 ( struct V_1 * V_89 , struct V_1 * V_69 ,
struct V_35 * V_36 )
{
int V_90 = 0 ;
const int V_3 = V_69 -> V_91 ;
if ( ! F_34 ( V_69 ) ) {
V_90 = F_35 ( V_69 , V_36 , F_23 ( V_36 ) ,
V_36 -> V_92 ) ;
if ( V_3 == V_93 && V_69 -> V_91 != V_3 )
V_89 -> V_94 ( V_89 , 0 ) ;
} else {
F_36 ( V_69 , V_36 ) ;
}
F_37 ( V_69 ) ;
F_38 ( V_69 ) ;
return V_90 ;
}
void F_39 ( struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_33 * V_95 )
{
F_40 ( L_6 ) ;
}
int F_41 ( struct V_33 * V_34 ,
struct V_42 const * V_96 , struct V_35 const * V_36 )
{
struct V_39 * V_40 = F_15 ( V_34 ) ;
F_42 ( V_34 ) -> V_97 = F_23 ( V_36 ) -> V_98 ;
F_42 ( V_34 ) -> V_99 = F_23 ( V_36 ) -> V_100 ;
F_42 ( V_34 ) -> V_101 = 0 ;
V_40 -> V_51 = 0 ;
return F_43 ( & V_96 -> V_55 , & V_40 -> V_65 ) ;
}
