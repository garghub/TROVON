int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
int V_11 ;
V_7 = F_2 ( & V_11 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
V_9 = F_5 ( V_7 ) ;
V_9 -> V_12 = V_2 ;
V_9 -> V_13 . V_14 . V_15 . V_16 = F_6 ( V_4 -> V_17 ) ;
V_9 -> V_13 . V_14 . V_15 . V_18 = F_6 ( V_4 -> V_19 ) ;
V_9 -> V_13 . V_14 . V_15 . V_20 = F_6 ( V_4 -> V_21 ) ;
V_9 -> V_13 . V_14 . V_15 . V_22 = V_4 -> V_23 ;
V_9 -> V_13 . V_14 . V_24 = V_5 ;
V_9 -> V_13 . V_14 . V_25 = V_4 -> V_26 ;
V_9 -> V_13 . V_14 . V_27 = F_7 ( & V_2 -> V_28 ) ;
V_29:
if ( F_8 ( V_7 , V_9 , V_30 , V_9 -> V_12 ) == 0 ) {
struct V_31 * V_32 = F_9 ( V_7 ) ;
if ( V_4 -> V_26 & V_33 )
V_32 -> V_34 = F_10 ( V_4 -> V_35 ) ;
V_10 = F_11 ( V_7 , V_9 ) ;
} else {
V_10 = V_9 -> V_36 ;
}
F_12 ( V_7 , V_9 ) ;
if ( F_13 ( V_9 -> V_37 ) )
goto V_29;
if ( V_10 == - V_38 && V_9 -> V_39 &&
V_9 -> V_36 != - V_38 )
V_10 = 0 ;
F_14 ( V_7 , & V_11 ) ;
return V_10 ;
}
int F_15 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_6 * V_7 ;
struct V_43 * V_44 ;
struct V_1 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 = {
. V_52 = V_40 ,
. V_13 = {
. V_53 = V_42 -> V_54 ,
}
} ;
int V_10 = 0 ;
int V_11 ;
F_16 ( V_42 -> V_55 -> V_56 & V_57 ) ;
F_16 ( F_17 ( V_40 -> V_58 ) ) ;
V_7 = F_2 ( & V_11 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
V_47 = F_18 ( V_40 ) -> V_59 ;
V_44 = F_19 ( V_40 ) ;
V_49 = & V_44 -> V_60 ;
F_16 ( F_20 ( V_49 ) ) ;
if ( ! V_44 -> V_61 ) {
F_16 ( V_40 -> V_62 & V_63 ) ;
V_51 . V_64 . V_65 = V_66 ;
V_45 = F_21 ( V_7 , F_22 ( V_47 -> V_67 ) ,
V_49 , & V_51 ) ;
if ( ! F_3 ( V_45 ) ) {
V_44 -> V_61 = V_45 ;
F_23 ( & V_45 -> V_28 , L_1 , V_40 ) ;
} else {
V_10 = F_4 ( V_45 ) ;
}
} else {
V_10 = F_24 ( V_7 , V_44 -> V_61 , & V_51 ) ;
}
F_14 ( V_7 , & V_11 ) ;
if ( V_10 != 0 )
F_25 ( L_2 V_68 L_3 ,
F_26 ( V_49 ) , V_10 ) ;
return V_10 ;
}
static void F_27 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_69 * V_70 = V_2 -> V_28 . V_71 ;
T_1 V_72 ;
if ( F_13 ( F_28 ( & V_70 -> V_73 ) != 1 ) ) {
struct V_46 * V_47 = V_2 -> V_28 . V_74 -> V_75 ;
struct V_76 * V_77 ;
V_77 = F_29 ( V_47 , & V_70 -> V_78 ) ;
F_30 ( & V_72 , V_79 ) ;
F_31 ( & V_77 -> V_80 , & V_72 ) ;
while ( 1 ) {
F_32 ( V_81 ) ;
if ( F_28 ( & V_70 -> V_73 ) == 1 )
break;
F_33 () ;
}
F_32 ( V_82 ) ;
F_34 ( & V_77 -> V_80 , & V_72 ) ;
}
F_35 ( V_7 , V_2 ) ;
}
void F_36 ( struct V_40 * V_40 )
{
struct V_6 * V_7 ;
struct V_43 * V_44 = F_19 ( V_40 ) ;
struct V_1 * V_45 = V_44 -> V_61 ;
int V_11 ;
int V_83 ;
if ( V_45 ) {
V_7 = F_2 ( & V_11 ) ;
V_83 = F_3 ( V_7 ) ;
if ( V_83 ) {
F_37 ( & V_84 ) ;
F_16 ( V_85 ) ;
V_7 = V_85 ;
}
F_38 ( V_7 , V_45 ) ;
F_39 ( & V_45 -> V_28 , L_1 , V_40 ) ;
F_27 ( V_7 , V_45 ) ;
V_44 -> V_61 = NULL ;
if ( V_83 )
F_40 ( & V_84 ) ;
else
F_14 ( V_7 , & V_11 ) ;
}
}
T_2 F_41 ( const struct V_48 * V_49 , int V_86 )
{
if ( V_87 == 32 || V_86 )
return F_42 ( V_49 ) ;
else
return F_43 ( V_49 ) ;
}
T_3 F_44 ( const struct V_48 * V_49 )
{
T_3 V_88 ;
if ( F_45 ( V_49 ) ) {
V_88 = F_46 ( V_49 ) ;
return V_88 ;
}
V_88 = F_43 ( V_49 ) >> 32 ;
return V_88 ;
}
