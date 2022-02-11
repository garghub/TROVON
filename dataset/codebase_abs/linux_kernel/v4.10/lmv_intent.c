static int F_1 ( struct V_1 * exp , struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * * V_7 ,
T_1 V_8 ,
T_2 V_9 )
{
struct V_10 * V_11 = exp -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_14 ;
struct V_6 * V_16 = NULL ;
struct V_17 V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
int V_26 = 0 ;
V_24 = F_2 ( & ( * V_7 ) -> V_27 , & V_28 ) ;
if ( ! V_24 )
return - V_29 ;
F_3 ( ( V_24 -> V_30 & V_31 ) ) ;
if ( V_3 -> V_32 & V_33 )
V_3 -> V_32 = V_34 ;
V_25 = V_3 -> V_35 ;
if ( V_25 ) {
V_18 . V_36 = V_3 -> V_37 ;
V_3 -> V_35 = 0 ;
V_3 -> V_38 = NULL ;
}
F_3 ( F_4 ( & V_24 -> V_39 ) ) ;
V_22 = F_5 ( V_14 , & V_24 -> V_39 ) ;
if ( F_6 ( V_22 ) ) {
V_26 = F_7 ( V_22 ) ;
goto V_40;
}
V_20 = F_8 ( sizeof( * V_20 ) , V_41 ) ;
if ( ! V_20 ) {
V_26 = - V_42 ;
goto V_40;
}
V_20 -> V_43 = V_24 -> V_39 ;
if ( V_5 ) {
F_3 ( V_3 -> V_32 & V_44 ) ;
V_20 -> V_45 = * V_5 ;
}
V_20 -> V_46 = V_47 ;
F_9 ( V_48 , L_1 V_49 L_2 ,
F_10 ( & V_24 -> V_39 ) , V_22 -> V_50 ) ;
V_26 = F_11 ( V_22 -> V_51 , V_20 , V_3 , & V_16 , V_8 ,
V_9 ) ;
if ( V_26 )
goto V_52;
if ( V_3 -> V_35 != 0 ) {
V_3 -> V_53 =
V_3 -> V_37 ;
V_3 -> V_54 = V_3 -> V_35 ;
}
if ( V_25 ) {
V_3 -> V_37 = V_18 . V_36 ;
V_3 -> V_35 = V_25 ;
}
V_52:
F_12 ( V_20 ) ;
V_40:
if ( V_26 && V_25 )
F_13 ( & V_18 , V_25 ) ;
F_14 ( * V_7 ) ;
* V_7 = V_16 ;
return V_26 ;
}
int F_15 ( struct V_1 * exp ,
const struct V_55 * V_56 ,
T_1 V_8 ,
int V_9 )
{
struct V_10 * V_11 = exp -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_14 ;
struct V_6 * V_16 = NULL ;
struct V_23 * V_24 ;
struct V_19 * V_20 ;
int V_26 = 0 , V_57 ;
V_20 = F_8 ( sizeof( * V_20 ) , V_41 ) ;
if ( ! V_20 )
return - V_42 ;
for ( V_57 = 0 ; V_57 < V_56 -> V_58 ; V_57 ++ ) {
struct V_2 V_3 = { . V_32 = V_34 } ;
struct V_17 * V_59 = NULL ;
struct V_21 * V_22 = NULL ;
struct V_60 * V_60 ;
struct V_4 V_61 ;
V_61 = V_56 -> V_62 [ V_57 ] . V_63 ;
V_60 = V_56 -> V_62 [ V_57 ] . V_64 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_43 = V_61 ;
V_20 -> V_45 = V_61 ;
V_22 = F_16 ( V_14 , V_20 , & V_61 ) ;
if ( F_6 ( V_22 ) ) {
V_26 = F_7 ( V_22 ) ;
goto V_65;
}
F_9 ( V_48 , L_3 V_49 L_2 ,
F_10 ( & V_61 ) , V_22 -> V_50 ) ;
if ( V_16 ) {
F_14 ( V_16 ) ;
V_16 = NULL ;
}
V_26 = F_11 ( V_22 -> V_51 , V_20 , & V_3 , & V_16 ,
V_8 , V_9 ) ;
if ( V_26 < 0 )
goto V_65;
V_59 = (struct V_17 * ) & V_3 . V_37 ;
if ( V_26 > 0 && ! V_16 ) {
F_9 ( V_48 , L_4 V_49 L_5 ,
F_10 ( & V_61 ) ) ;
V_26 = 0 ;
} else {
V_24 = F_2 ( & V_16 -> V_27 ,
& V_28 ) ;
F_3 ( V_24 ) ;
if ( F_17 ( V_24 -> V_66 < 2 ) ) {
F_9 ( V_48 , L_6 V_49 L_7 V_49 L_8 ,
V_11 -> V_67 , V_24 -> V_66 , V_57 ,
F_10 ( & V_56 -> V_62 [ V_57 ] . V_63 ) ,
F_10 ( & V_56 -> V_62 [ 0 ] . V_63 ) ) ;
if ( V_3 . V_35 && V_59 ) {
F_13 ( V_59 , V_3 . V_35 ) ;
V_3 . V_35 = 0 ;
}
V_26 = - V_68 ;
goto V_65;
}
F_18 ( V_60 , V_24 -> V_69 ) ;
V_60 -> V_70 = V_24 -> V_71 ;
F_19 ( V_60 , V_24 -> V_66 ) ;
F_20 ( V_60 -> V_72 ) = V_24 -> V_73 ;
F_20 ( V_60 -> V_74 ) = V_24 -> V_75 ;
F_20 ( V_60 -> V_76 ) = V_24 -> V_77 ;
}
F_21 ( V_22 -> V_51 , V_59 , V_60 , NULL ) ;
if ( V_3 . V_35 && V_59 ) {
F_13 ( V_59 , V_3 . V_35 ) ;
V_3 . V_35 = 0 ;
}
}
V_65:
if ( V_16 )
F_14 ( V_16 ) ;
F_12 ( V_20 ) ;
return V_26 ;
}
static int F_22 ( struct V_1 * exp , struct V_19 * V_20 ,
struct V_2 * V_3 ,
struct V_6 * * V_7 ,
T_1 V_8 ,
T_2 V_9 )
{
struct V_10 * V_11 = exp -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_14 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_26 ;
if ( V_3 -> V_78 & V_79 ) {
F_3 ( F_4 ( & V_20 -> V_45 ) ) ;
if ( V_20 -> V_80 )
V_20 -> V_43 = V_20 -> V_45 ;
V_22 = F_5 ( V_14 , & V_20 -> V_45 ) ;
if ( F_6 ( V_22 ) )
return F_7 ( V_22 ) ;
V_20 -> V_81 = V_22 -> V_50 ;
} else {
F_3 ( F_4 ( & V_20 -> V_43 ) ) ;
F_3 ( F_23 ( & V_20 -> V_45 ) ) ;
F_3 ( V_20 -> V_82 ) ;
V_22 = F_16 ( V_14 , V_20 , & V_20 -> V_43 ) ;
if ( F_6 ( V_22 ) )
return F_7 ( V_22 ) ;
}
if ( ( V_3 -> V_32 & V_83 ) && ! ( V_3 -> V_78 & V_79 ) ) {
V_26 = F_24 ( NULL , exp , & V_20 -> V_45 , V_20 ) ;
if ( V_26 != 0 )
return V_26 ;
}
F_9 ( V_48 , L_9 V_49 L_10 V_49 L_11 ,
F_10 ( & V_20 -> V_43 ) ,
F_10 ( & V_20 -> V_45 ) , V_20 -> V_82 , V_22 -> V_50 ) ;
V_26 = F_11 ( V_22 -> V_51 , V_20 , V_3 , V_7 , V_8 ,
V_9 ) ;
if ( V_26 != 0 )
return V_26 ;
if ( ( V_3 -> V_84 & V_85 ) &&
! ( V_3 -> V_84 & V_86 ) &&
! ( V_3 -> V_84 & V_87 ) )
return V_26 ;
V_24 = F_2 ( & ( * V_7 ) -> V_27 , & V_28 ) ;
if ( ! V_24 )
return - V_29 ;
if ( F_17 ( ( V_24 -> V_30 & V_31 ) ) ) {
V_26 = F_1 ( exp , V_3 , & V_20 -> V_43 , V_7 ,
V_8 , V_9 ) ;
if ( V_26 != 0 )
return V_26 ;
V_24 = F_2 ( & ( * V_7 ) -> V_27 , & V_28 ) ;
if ( ! V_24 )
return - V_29 ;
}
return V_26 ;
}
static int F_25 ( struct V_1 * exp ,
struct V_19 * V_20 ,
struct V_2 * V_3 ,
struct V_6 * * V_7 ,
T_1 V_8 ,
T_2 V_9 )
{
struct V_55 * V_56 = V_20 -> V_80 ;
struct V_10 * V_11 = exp -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 . V_14 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 ;
int V_26 = 0 ;
V_22 = F_16 ( V_14 , V_20 , & V_20 -> V_43 ) ;
if ( F_6 ( V_22 ) && ( F_7 ( V_22 ) != - V_88 ) )
return F_7 ( V_22 ) ;
if ( V_56 && ! F_26 ( V_56 -> V_89 ) ) {
struct V_90 * V_91 = & V_56 -> V_62 [ 0 ] ;
V_20 -> V_43 = V_91 -> V_63 ;
V_20 -> V_81 = V_91 -> V_92 ;
V_22 = F_27 ( V_14 , V_91 -> V_92 , NULL ) ;
if ( F_6 ( V_22 ) )
return F_7 ( V_22 ) ;
}
if ( ! F_4 ( & V_20 -> V_45 ) )
F_28 ( & V_20 -> V_45 ) ;
F_9 ( V_48 , L_12 V_49 L_10 V_49 L_13 ,
F_10 ( & V_20 -> V_43 ) , F_10 ( & V_20 -> V_45 ) ,
V_20 -> V_82 ? V_20 -> V_82 : L_14 ,
V_22 -> V_50 , V_56 , ! V_56 ? - 1 : V_56 -> V_93 ) ;
V_20 -> V_46 &= ~ V_47 ;
V_26 = F_11 ( V_22 -> V_51 , V_20 , V_3 , V_7 , V_8 ,
V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! * V_7 ) {
if ( V_20 -> V_94 ) {
V_26 = F_15 ( exp , V_20 -> V_94 ,
V_8 ,
V_9 ) ;
if ( V_26 != 0 )
return V_26 ;
}
return V_26 ;
} else if ( V_84 ( V_3 , V_85 ) && V_56 &&
F_29 ( V_56 ) ) {
int V_95 ;
for ( V_95 = 1 ;
V_95 < V_56 -> V_58 &&
V_84 ( V_3 , V_85 ) ; V_95 ++ ) {
struct V_90 * V_91 ;
F_14 ( * V_7 ) ;
V_3 -> V_38 = NULL ;
* V_7 = NULL ;
V_91 = & V_56 -> V_62 [ V_95 ] ;
V_22 = F_5 ( V_14 , & V_91 -> V_63 ) ;
if ( F_6 ( V_22 ) )
return F_7 ( V_22 ) ;
F_9 ( V_48 , L_15 V_49 L_8 ,
F_10 ( & V_91 -> V_63 ) ) ;
V_20 -> V_43 = V_91 -> V_63 ;
V_3 -> V_84 &= ~ V_96 ;
V_26 = F_11 ( V_22 -> V_51 , V_20 , V_3 , V_7 ,
V_8 , V_9 ) ;
if ( V_26 )
return V_26 ;
}
}
V_24 = F_2 ( & ( * V_7 ) -> V_27 , & V_28 ) ;
if ( ! V_24 )
return - V_29 ;
if ( F_17 ( ( V_24 -> V_30 & V_31 ) ) ) {
V_26 = F_1 ( exp , V_3 , NULL , V_7 , V_8 ,
V_9 ) ;
if ( V_26 != 0 )
return V_26 ;
V_24 = F_2 ( & ( * V_7 ) -> V_27 , & V_28 ) ;
if ( ! V_24 )
return - V_29 ;
}
return V_26 ;
}
int F_30 ( struct V_1 * exp , struct V_19 * V_20 ,
struct V_2 * V_3 , struct V_6 * * V_7 ,
T_1 V_8 ,
T_2 V_9 )
{
struct V_10 * V_11 = exp -> V_12 ;
int V_26 ;
F_3 ( F_4 ( & V_20 -> V_43 ) ) ;
F_9 ( V_48 , L_16 V_49 L_17 V_49 L_8 ,
F_31 ( V_3 ) , F_10 ( & V_20 -> V_45 ) ,
( int ) V_20 -> V_97 , V_20 -> V_82 ,
F_10 ( & V_20 -> V_43 ) ) ;
V_26 = F_32 ( V_11 ) ;
if ( V_26 )
return V_26 ;
if ( V_3 -> V_32 & ( V_33 | V_34 | V_98 ) )
V_26 = F_25 ( exp , V_20 , V_3 , V_7 , V_8 ,
V_9 ) ;
else if ( V_3 -> V_32 & V_44 )
V_26 = F_22 ( exp , V_20 , V_3 , V_7 , V_8 ,
V_9 ) ;
else
F_33 () ;
if ( V_26 < 0 ) {
struct V_17 V_99 ;
if ( V_3 -> V_35 ) {
V_99 . V_36 = V_3 -> V_37 ;
F_13 ( & V_99 , V_3 -> V_35 ) ;
}
V_3 -> V_37 = 0 ;
V_3 -> V_35 = 0 ;
if ( V_3 -> V_54 ) {
V_99 . V_36 = V_3 -> V_53 ;
F_13 ( & V_99 ,
V_3 -> V_54 ) ;
}
V_3 -> V_53 = 0 ;
V_3 -> V_54 = 0 ;
}
return V_26 ;
}
