int F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
int V_9 ;
V_5 = F_2 ( & V_9 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_7 = F_5 ( V_5 ) ;
V_7 -> V_10 = F_6 ( V_1 ) -> V_11 ;
V_7 -> V_12 . V_13 . V_14 . V_15 = F_7 ( V_3 -> V_16 ) ;
V_7 -> V_12 . V_13 . V_14 . V_17 = F_7 ( V_3 -> V_18 ) ;
V_7 -> V_12 . V_13 . V_14 . V_19 = F_7 ( V_3 -> V_20 ) ;
V_7 -> V_12 . V_13 . V_14 . V_21 = V_3 -> V_22 ;
V_7 -> V_12 . V_13 . V_23 = V_3 -> V_24 ;
V_7 -> V_12 . V_13 . V_25 = F_8 ( V_1 ) ;
V_26:
if ( F_9 ( V_5 , V_7 , V_27 , V_7 -> V_10 ) == 0 ) {
struct V_28 * V_29 = F_10 ( V_5 ) ;
if ( V_3 -> V_24 & V_30 )
V_29 -> V_31 = F_11 ( V_3 -> V_32 ) ;
V_8 = F_12 ( V_5 , V_7 ) ;
} else {
V_8 = V_7 -> V_33 ;
}
F_13 ( V_5 , V_7 ) ;
if ( F_14 ( V_7 -> V_34 ) )
goto V_26;
if ( V_8 == - V_35 && V_7 -> V_36 &&
V_7 -> V_33 != - V_35 )
V_8 = 0 ;
F_15 ( V_5 , & V_9 ) ;
return V_8 ;
}
int F_16 ( struct V_1 * V_1 , struct V_37 * V_38 )
{
struct V_4 * V_5 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 V_48 = {
. V_49 = V_1 ,
. V_12 = {
. V_50 = V_38
}
} ;
int V_8 = 0 ;
int V_9 ;
F_17 ( V_38 -> V_51 -> V_52 & V_53 ) ;
F_17 ( F_18 ( V_1 -> V_54 ) ) ;
V_5 = F_2 ( & V_9 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_44 = F_19 ( V_1 ) -> V_55 ;
V_40 = F_6 ( V_1 ) ;
V_46 = & V_40 -> V_56 ;
F_17 ( F_20 ( V_46 ) ) ;
if ( ! V_40 -> V_11 ) {
F_17 ( V_1 -> V_57 & V_58 ) ;
V_48 . V_59 . V_60 = V_61 ;
V_42 = F_21 ( V_5 , F_22 ( V_44 -> V_62 ) ,
V_46 , & V_48 ) ;
if ( ! F_3 ( V_42 ) ) {
V_40 -> V_11 = V_42 ;
V_40 -> V_63 = F_23 ( V_38 -> V_64 ) ;
F_24 ( & V_42 -> V_65 , L_1 , V_1 ) ;
} else {
V_8 = F_4 ( V_42 ) ;
}
} else {
V_8 = F_25 ( V_5 , V_40 -> V_11 , & V_48 ) ;
}
F_15 ( V_5 , & V_9 ) ;
if ( V_8 != 0 )
F_26 ( L_2 V_66 L_3 ,
F_27 ( V_46 ) , V_8 ) ;
return V_8 ;
}
static void F_28 ( struct V_4 * V_5 , struct V_41 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_65 . V_70 ;
T_1 V_71 ;
if ( F_14 ( F_29 ( & V_69 -> V_72 ) != 1 ) ) {
struct V_43 * V_44 = V_67 -> V_65 . V_73 -> V_74 ;
struct V_75 * V_76 ;
V_76 = F_30 ( V_44 , & V_69 -> V_77 ) ;
F_31 ( & V_71 , V_78 ) ;
F_32 ( & V_76 -> V_79 , & V_71 ) ;
while ( 1 ) {
F_33 ( V_80 ) ;
if ( F_29 ( & V_69 -> V_72 ) == 1 )
break;
F_34 () ;
}
F_33 ( V_81 ) ;
F_35 ( & V_76 -> V_79 , & V_71 ) ;
}
F_36 ( V_5 , V_67 ) ;
}
void F_37 ( struct V_1 * V_1 )
{
struct V_4 * V_5 ;
struct V_39 * V_40 = F_6 ( V_1 ) ;
struct V_41 * V_42 = V_40 -> V_11 ;
int V_9 ;
int V_82 ;
if ( V_42 ) {
void * V_83 ;
V_83 = F_38 () ;
V_5 = F_2 ( & V_9 ) ;
V_82 = F_3 ( V_5 ) ;
if ( V_82 ) {
F_39 ( & V_84 ) ;
F_17 ( V_85 ) ;
F_40 ( V_85 , & V_9 ) ;
V_5 = V_85 ;
}
F_41 ( V_5 , V_42 ) ;
F_42 ( & V_42 -> V_65 , L_1 , V_1 ) ;
F_28 ( V_5 , V_42 ) ;
V_40 -> V_11 = NULL ;
if ( V_82 ) {
F_43 ( V_85 , & V_9 ) ;
F_44 ( & V_84 ) ;
} else {
F_15 ( V_5 , & V_9 ) ;
}
F_45 ( V_83 ) ;
}
}
T_2 F_46 ( const struct V_45 * V_46 , int V_86 )
{
if ( V_87 == 32 || V_86 )
return F_47 ( V_46 ) ;
else
return F_48 ( V_46 ) ;
}
T_3 F_49 ( const struct V_45 * V_46 )
{
T_3 V_88 ;
if ( F_50 ( V_46 ) ) {
V_88 = F_51 ( V_46 ) ;
return V_88 ;
}
V_88 = F_48 ( V_46 ) >> 32 ;
return V_88 ;
}
struct V_89 * F_52 ( struct V_1 * V_1 )
{
return F_53 ( F_6 ( V_1 ) -> V_11 ) ;
}
inline void F_54 ( struct V_1 * V_1 , struct V_89 * V_64 )
{
F_55 ( F_6 ( V_1 ) -> V_11 , V_64 ) ;
}
