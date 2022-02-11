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
V_25:
if ( F_8 ( V_5 , V_7 , V_26 , V_7 -> V_10 ) == 0 ) {
struct V_27 * V_28 = F_9 ( V_5 ) ;
if ( V_3 -> V_24 & V_29 )
V_28 -> V_30 = F_10 ( V_3 -> V_31 ) ;
V_8 = F_11 ( V_5 , V_7 ) ;
} else {
V_8 = V_7 -> V_32 ;
}
F_12 ( V_5 , V_7 ) ;
if ( F_13 ( V_7 -> V_33 ) )
goto V_25;
if ( V_8 == - V_34 && V_7 -> V_35 &&
V_7 -> V_32 != - V_34 )
V_8 = 0 ;
F_14 ( V_5 , & V_9 ) ;
return V_8 ;
}
int F_15 ( struct V_1 * V_1 , struct V_36 * V_37 )
{
struct V_4 * V_5 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 V_47 = {
. V_48 = V_1 ,
. V_12 = {
. V_49 = V_37
}
} ;
int V_8 = 0 ;
int V_9 ;
F_16 ( V_37 -> V_50 -> V_51 & V_52 ) ;
F_16 ( F_17 ( V_1 -> V_53 ) ) ;
V_5 = F_2 ( & V_9 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_43 = F_18 ( V_1 ) -> V_54 ;
V_39 = F_6 ( V_1 ) ;
V_45 = & V_39 -> V_55 ;
F_16 ( F_19 ( V_45 ) ) ;
if ( ! V_39 -> V_11 ) {
F_16 ( V_1 -> V_56 & V_57 ) ;
V_47 . V_58 . V_59 = V_60 ;
V_41 = F_20 ( V_5 , F_21 ( V_43 -> V_61 ) ,
V_45 , & V_47 ) ;
if ( ! F_3 ( V_41 ) ) {
V_39 -> V_11 = V_41 ;
V_39 -> V_62 = F_22 ( V_37 -> V_63 ) ;
F_23 ( & V_41 -> V_64 , L_1 , V_1 ) ;
} else {
V_8 = F_4 ( V_41 ) ;
}
} else {
V_8 = F_24 ( V_5 , V_39 -> V_11 , & V_47 ) ;
}
F_14 ( V_5 , & V_9 ) ;
if ( V_8 != 0 )
F_25 ( L_2 V_65 L_3 ,
F_26 ( V_45 ) , V_8 ) ;
return V_8 ;
}
static void F_27 ( struct V_4 * V_5 , struct V_40 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_64 . V_69 ;
T_1 V_70 ;
if ( F_13 ( F_28 ( & V_68 -> V_71 ) != 1 ) ) {
struct V_42 * V_43 = V_66 -> V_64 . V_72 -> V_73 ;
struct V_74 * V_75 ;
V_75 = F_29 ( V_43 , & V_68 -> V_76 ) ;
F_30 ( & V_70 , V_77 ) ;
F_31 ( & V_75 -> V_78 , & V_70 ) ;
while ( 1 ) {
F_32 ( V_79 ) ;
if ( F_28 ( & V_68 -> V_71 ) == 1 )
break;
F_33 () ;
}
F_32 ( V_80 ) ;
F_34 ( & V_75 -> V_78 , & V_70 ) ;
}
F_35 ( V_5 , V_66 ) ;
}
void F_36 ( struct V_1 * V_1 )
{
struct V_4 * V_5 ;
struct V_38 * V_39 = F_6 ( V_1 ) ;
struct V_40 * V_41 = V_39 -> V_11 ;
int V_9 ;
int V_81 ;
if ( V_41 ) {
void * V_82 ;
V_82 = F_37 () ;
V_5 = F_2 ( & V_9 ) ;
V_81 = F_3 ( V_5 ) ;
if ( V_81 ) {
F_38 ( & V_83 ) ;
F_16 ( V_84 ) ;
F_39 ( V_84 , & V_9 ) ;
V_5 = V_84 ;
}
F_40 ( V_5 , V_41 ) ;
F_41 ( & V_41 -> V_64 , L_1 , V_1 ) ;
F_27 ( V_5 , V_41 ) ;
V_39 -> V_11 = NULL ;
if ( V_81 ) {
F_42 ( V_84 , & V_9 ) ;
F_43 ( & V_83 ) ;
} else {
F_14 ( V_5 , & V_9 ) ;
}
F_44 ( V_82 ) ;
}
}
T_2 F_45 ( const struct V_44 * V_45 , int V_85 )
{
if ( V_86 == 32 || V_85 )
return F_46 ( V_45 ) ;
else
return F_47 ( V_45 ) ;
}
T_3 F_48 ( const struct V_44 * V_45 )
{
T_3 V_87 ;
if ( F_49 ( V_45 ) ) {
V_87 = F_50 ( V_45 ) ;
return V_87 ;
}
V_87 = F_47 ( V_45 ) >> 32 ;
return V_87 ;
}
struct V_88 * F_51 ( struct V_1 * V_1 )
{
return F_52 ( F_6 ( V_1 ) -> V_11 ) ;
}
inline void F_53 ( struct V_1 * V_1 , struct V_88 * V_63 )
{
F_54 ( F_6 ( V_1 ) -> V_11 , V_63 ) ;
}
