void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = NULL ;
if ( V_7 . V_8 < V_7 . V_9 )
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_6 != NULL ) {
const struct V_10 * V_11 = F_3 ( V_2 ) ;
const int V_12 = ( V_11 -> V_13 << 2 ) - ( V_11 -> V_13 >> 1 ) ;
#if F_4 ( V_14 ) || F_4 ( V_15 )
if ( V_6 -> V_16 == V_17 ) {
const struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_20 * V_21 ;
V_6 -> V_22 = F_6 ( V_2 -> V_23 ) ;
V_21 = F_7 ( (struct V_1 * ) V_6 ) ;
F_8 ( & V_21 -> V_24 , & V_19 -> V_25 ) ;
F_8 ( & V_21 -> V_26 , & V_19 -> V_27 ) ;
V_6 -> V_28 = V_19 -> V_29 ;
}
#endif
F_9 ( V_6 , V_2 , & V_30 ) ;
if ( V_4 < V_12 )
V_4 = V_12 ;
V_6 -> V_31 = V_32 ;
if ( V_3 == V_33 )
V_4 = V_32 ;
F_10 ( V_6 , & V_7 , V_4 ,
V_32 ) ;
F_11 ( V_6 ) ;
} else {
F_12 ( L_1 ) ;
}
F_13 ( V_2 ) ;
}
struct V_1 * F_14 ( struct V_1 * V_2 ,
const struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_1 * V_38 = F_15 ( V_2 , V_35 , V_39 ) ;
if ( V_38 != NULL ) {
struct V_40 * V_41 = F_16 ( V_35 ) ;
struct V_10 * V_42 = F_3 ( V_38 ) ;
struct V_43 * V_44 = F_17 ( V_38 ) ;
V_44 -> V_45 = V_46 ;
V_44 -> V_47 = NULL ;
V_44 -> V_48 = NULL ;
V_44 -> V_49 = V_41 -> V_50 ;
V_44 -> V_51 = V_41 -> V_52 ;
V_44 -> V_53 = V_41 -> V_54 ;
V_42 -> V_13 = V_55 ;
F_18 ( & V_44 -> V_56 ) ;
V_44 -> V_57 = V_44 -> V_58 = V_41 -> V_59 ;
V_44 -> V_60 = V_44 -> V_58 ;
V_44 -> V_61 = V_44 -> V_62 = V_41 -> V_63 ;
if ( F_19 ( V_38 , & V_41 -> V_64 ) ) {
V_38 -> V_65 = NULL ;
F_20 ( V_38 ) ;
return NULL ;
}
F_21 ( V_38 ) ;
F_22 ( V_66 ) ;
}
return V_38 ;
}
struct V_1 * F_23 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_34 * V_35 ,
struct V_34 * * V_67 )
{
struct V_1 * V_68 = NULL ;
struct V_40 * V_41 = F_16 ( V_35 ) ;
if ( F_24 ( V_37 ) -> V_69 == V_70 ) {
if ( F_25 ( F_26 ( V_37 ) -> V_71 , V_41 -> V_63 ) ) {
F_27 ( L_2 ) ;
V_41 -> V_63 = F_26 ( V_37 ) -> V_71 ;
V_35 -> V_72 ++ ;
V_35 -> V_73 -> V_74 ( V_2 , V_35 , NULL ) ;
}
return NULL ;
}
F_26 ( V_37 ) -> V_75 = V_76 ;
if ( F_24 ( V_37 ) -> V_69 != V_77 &&
F_24 ( V_37 ) -> V_69 != V_78 )
goto V_79;
if ( F_26 ( V_37 ) -> V_80 != V_41 -> V_59 ) {
F_27 ( L_3
L_4 ,
( unsigned long long )
F_26 ( V_37 ) -> V_80 ,
( unsigned long long ) V_41 -> V_59 ) ;
goto V_79;
}
if ( F_28 ( V_2 , V_41 , V_37 ) )
goto V_79;
V_68 = F_3 ( V_2 ) -> V_81 -> V_82 ( V_2 , V_37 , V_35 , NULL ) ;
if ( V_68 == NULL )
goto V_83;
F_29 ( V_2 , V_35 , V_67 ) ;
F_30 ( V_2 , V_35 ) ;
F_31 ( V_2 , V_35 , V_68 ) ;
V_84:
return V_68 ;
V_83:
F_27 ( L_5 ) ;
F_26 ( V_37 ) -> V_75 = V_85 ;
V_79:
if ( F_24 ( V_37 ) -> V_69 != V_86 )
V_35 -> V_73 -> V_87 ( V_2 , V_37 ) ;
F_32 ( V_2 , V_35 , V_67 ) ;
goto V_84;
}
int F_33 ( struct V_1 * V_88 , struct V_1 * V_68 ,
struct V_36 * V_37 )
{
int V_89 = 0 ;
const int V_3 = V_68 -> V_90 ;
if ( ! F_34 ( V_68 ) ) {
V_89 = F_35 ( V_68 , V_37 , F_24 ( V_37 ) ,
V_37 -> V_91 ) ;
if ( V_3 == V_92 && V_68 -> V_90 != V_3 )
V_88 -> V_93 ( V_88 , 0 ) ;
} else {
F_36 ( V_68 , V_37 ) ;
}
F_37 ( V_68 ) ;
F_38 ( V_68 ) ;
return V_89 ;
}
void F_39 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_34 * V_94 )
{
F_40 ( L_6 ) ;
}
int F_41 ( struct V_34 * V_35 ,
struct V_43 const * V_95 , struct V_36 const * V_37 )
{
struct V_40 * V_41 = F_16 ( V_35 ) ;
F_42 ( V_35 ) -> V_96 = F_24 ( V_37 ) -> V_97 ;
F_42 ( V_35 ) -> V_98 = F_24 ( V_37 ) -> V_99 ;
F_42 ( V_35 ) -> V_100 = 0 ;
V_41 -> V_52 = 0 ;
return F_43 ( & V_95 -> V_56 , & V_41 -> V_64 ) ;
}
