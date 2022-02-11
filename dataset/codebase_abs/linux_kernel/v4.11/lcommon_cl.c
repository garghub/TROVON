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
V_9 -> V_13 = 1 ;
V_9 -> V_14 . V_15 . V_16 . V_17 = F_6 ( V_4 -> V_18 ) ;
V_9 -> V_14 . V_15 . V_16 . V_19 = F_6 ( V_4 -> V_20 ) ;
V_9 -> V_14 . V_15 . V_16 . V_21 = F_6 ( V_4 -> V_22 ) ;
V_9 -> V_14 . V_15 . V_16 . V_23 = V_4 -> V_24 ;
V_9 -> V_14 . V_15 . V_25 = V_5 ;
V_9 -> V_14 . V_15 . V_26 = V_4 -> V_27 ;
V_9 -> V_14 . V_15 . V_28 = F_7 ( & V_2 -> V_29 ) ;
V_30:
if ( F_8 ( V_7 , V_9 , V_31 , V_9 -> V_12 ) == 0 ) {
struct V_32 * V_33 = F_9 ( V_7 ) ;
if ( V_4 -> V_27 & V_34 )
V_33 -> V_35 = F_10 ( V_4 -> V_36 ) ;
V_10 = F_11 ( V_7 , V_9 ) ;
} else {
V_10 = V_9 -> V_37 ;
}
F_12 ( V_7 , V_9 ) ;
if ( F_13 ( V_9 -> V_38 ) )
goto V_30;
F_14 ( V_7 , & V_11 ) ;
return V_10 ;
}
int F_15 ( struct V_39 * V_39 , struct V_40 * V_41 )
{
struct V_6 * V_7 ;
struct V_42 * V_43 ;
struct V_1 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 V_50 = {
. V_51 = V_39 ,
. V_14 = {
. V_52 = V_41 -> V_53 ,
}
} ;
int V_10 = 0 ;
int V_11 ;
F_16 ( V_41 -> V_54 -> V_55 & V_56 ) ;
F_16 ( F_17 ( V_39 -> V_57 ) ) ;
V_7 = F_2 ( & V_11 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
V_46 = F_18 ( V_39 ) -> V_58 ;
V_43 = F_19 ( V_39 ) ;
V_48 = & V_43 -> V_59 ;
F_16 ( F_20 ( V_48 ) ) ;
if ( ! V_43 -> V_60 ) {
F_16 ( V_39 -> V_61 & V_62 ) ;
V_50 . V_63 . V_64 = V_65 ;
V_44 = F_21 ( V_7 , F_22 ( V_46 -> V_66 ) ,
V_48 , & V_50 ) ;
if ( ! F_3 ( V_44 ) ) {
V_43 -> V_60 = V_44 ;
F_23 ( & V_44 -> V_29 , L_1 , V_39 ) ;
} else {
V_10 = F_4 ( V_44 ) ;
}
} else {
V_10 = F_24 ( V_7 , V_43 -> V_60 , & V_50 ) ;
}
F_14 ( V_7 , & V_11 ) ;
if ( V_10 != 0 )
F_25 ( L_2 V_67 L_3 ,
F_26 ( V_48 ) , V_10 ) ;
return V_10 ;
}
static void F_27 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_29 . V_70 ;
T_1 V_71 ;
if ( F_13 ( F_28 ( & V_69 -> V_72 ) != 1 ) ) {
struct V_45 * V_46 = V_2 -> V_29 . V_73 -> V_74 ;
struct V_75 * V_76 ;
V_76 = F_29 ( V_46 , & V_69 -> V_77 ) ;
F_30 ( & V_71 , V_78 ) ;
F_31 ( & V_76 -> V_79 , & V_71 ) ;
while ( 1 ) {
F_32 ( V_80 ) ;
if ( F_28 ( & V_69 -> V_72 ) == 1 )
break;
F_33 () ;
}
F_32 ( V_81 ) ;
F_34 ( & V_76 -> V_79 , & V_71 ) ;
}
F_35 ( V_7 , V_2 ) ;
}
void F_36 ( struct V_39 * V_39 )
{
struct V_6 * V_7 ;
struct V_42 * V_43 = F_19 ( V_39 ) ;
struct V_1 * V_44 = V_43 -> V_60 ;
int V_11 ;
int V_82 ;
if ( V_44 ) {
V_7 = F_2 ( & V_11 ) ;
V_82 = F_3 ( V_7 ) ;
if ( V_82 ) {
F_37 ( & V_83 ) ;
F_16 ( V_84 ) ;
V_7 = V_84 ;
}
F_38 ( V_7 , V_44 ) ;
F_39 ( & V_44 -> V_29 , L_1 , V_39 ) ;
F_27 ( V_7 , V_44 ) ;
V_43 -> V_60 = NULL ;
if ( V_82 )
F_40 ( & V_83 ) ;
else
F_14 ( V_7 , & V_11 ) ;
}
}
T_2 F_41 ( const struct V_47 * V_48 , int V_85 )
{
if ( V_86 == 32 || V_85 )
return F_42 ( V_48 ) ;
else
return F_43 ( V_48 ) ;
}
T_3 F_44 ( const struct V_47 * V_48 )
{
T_3 V_87 ;
if ( F_45 ( V_48 ) ) {
V_87 = F_46 ( V_48 ) ;
return V_87 ;
}
V_87 = F_43 ( V_48 ) >> 32 ;
return V_87 ;
}
