void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , & V_7 , V_3 ) ;
if ( V_6 != NULL ) {
const struct V_8 * V_9 = F_3 ( V_2 ) ;
const int V_10 = ( V_9 -> V_11 << 2 ) - ( V_9 -> V_11 >> 1 ) ;
#if F_4 ( V_12 )
if ( V_6 -> V_13 == V_14 ) {
V_6 -> V_15 = V_2 -> V_16 ;
V_6 -> V_17 = V_2 -> V_18 ;
V_6 -> V_19 = V_2 -> V_20 ;
}
#endif
if ( V_4 < V_10 )
V_4 = V_10 ;
V_6 -> V_21 = V_22 ;
if ( V_3 == V_23 )
V_4 = V_22 ;
F_5 ( V_6 , V_4 ) ;
F_6 ( V_6 , V_2 , & V_24 ) ;
F_7 ( V_6 ) ;
} else {
F_8 ( L_1 ) ;
}
F_9 ( V_2 ) ;
}
struct V_1 * F_10 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_29 = F_11 ( V_2 , V_26 , V_30 ) ;
if ( V_29 != NULL ) {
struct V_31 * V_32 = F_12 ( V_26 ) ;
struct V_8 * V_33 = F_3 ( V_29 ) ;
struct V_34 * V_35 = F_13 ( V_29 ) ;
V_35 -> V_36 = V_37 ;
V_35 -> V_38 = NULL ;
V_35 -> V_39 = NULL ;
V_35 -> V_40 = V_32 -> V_41 ;
V_35 -> V_42 = V_32 -> V_43 ;
V_35 -> V_44 = V_32 -> V_45 ;
V_33 -> V_11 = V_46 ;
F_14 ( & V_35 -> V_47 ) ;
V_35 -> V_48 = V_32 -> V_49 ;
V_35 -> V_50 = V_32 -> V_51 ;
V_35 -> V_52 = V_35 -> V_48 ;
V_35 -> V_53 = V_32 -> V_54 ;
V_35 -> V_55 = V_32 -> V_56 ;
if ( F_15 ( V_29 , & V_32 -> V_57 ) ) {
F_16 ( V_29 ) ;
return NULL ;
}
F_17 ( V_29 ) ;
F_18 ( V_58 ) ;
}
return V_29 ;
}
struct V_1 * F_19 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_25 * V_26 )
{
struct V_1 * V_59 = NULL ;
struct V_31 * V_32 = F_12 ( V_26 ) ;
bool V_60 ;
F_20 ( & V_32 -> V_61 ) ;
if ( F_21 ( V_28 ) -> V_62 == V_63 ) {
if ( F_22 ( F_23 ( V_28 ) -> V_64 , V_32 -> V_56 ) ) {
F_24 ( L_2 ) ;
V_32 -> V_56 = F_23 ( V_28 ) -> V_64 ;
F_25 ( V_2 , V_26 ) ;
}
goto V_65;
}
F_23 ( V_28 ) -> V_66 = V_67 ;
if ( F_21 ( V_28 ) -> V_62 != V_68 &&
F_21 ( V_28 ) -> V_62 != V_69 )
goto V_70;
if ( ! F_26 ( F_23 ( V_28 ) -> V_71 ,
V_32 -> V_49 , V_32 -> V_51 ) ) {
F_24 ( L_3
L_4 ,
( unsigned long long )
F_23 ( V_28 ) -> V_71 ,
( unsigned long long ) V_32 -> V_49 ,
( unsigned long long ) V_32 -> V_51 ) ;
goto V_70;
}
if ( F_27 ( V_2 , V_32 , V_28 ) )
goto V_70;
V_59 = F_3 ( V_2 ) -> V_72 -> V_73 ( V_2 , V_28 , V_26 , NULL ,
V_26 , & V_60 ) ;
if ( V_59 ) {
V_59 = F_28 ( V_2 , V_59 , V_26 , V_60 ) ;
goto V_65;
}
F_23 ( V_28 ) -> V_66 = V_74 ;
V_70:
if ( F_21 ( V_28 ) -> V_62 != V_75 )
V_26 -> V_76 -> V_77 ( V_2 , V_28 ) ;
F_29 ( V_2 , V_26 ) ;
V_65:
F_30 ( & V_32 -> V_61 ) ;
return V_59 ;
}
int F_31 ( struct V_1 * V_78 , struct V_1 * V_59 ,
struct V_27 * V_28 )
{
int V_79 = 0 ;
const int V_3 = V_59 -> V_80 ;
if ( ! F_32 ( V_59 ) ) {
V_79 = F_33 ( V_59 , V_28 , F_21 ( V_28 ) ,
V_28 -> V_81 ) ;
if ( V_3 == V_82 && V_59 -> V_80 != V_3 )
V_78 -> V_83 ( V_78 ) ;
} else {
F_34 ( V_59 , V_28 ) ;
}
F_35 ( V_59 ) ;
F_36 ( V_59 ) ;
return V_79 ;
}
void F_37 ( const struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_25 * V_84 )
{
F_38 ( L_5 ) ;
}
int F_39 ( struct V_25 * V_26 ,
struct V_34 const * V_85 , struct V_27 const * V_28 )
{
struct V_31 * V_32 = F_12 ( V_26 ) ;
F_40 ( & V_32 -> V_61 ) ;
F_41 ( V_26 ) -> V_86 = F_21 ( V_28 ) -> V_87 ;
F_41 ( V_26 ) -> V_88 = F_42 ( F_21 ( V_28 ) -> V_89 ) ;
F_41 ( V_26 ) -> V_90 = 0 ;
V_32 -> V_43 = 0 ;
return F_43 ( & V_85 -> V_47 , & V_32 -> V_57 ) ;
}
