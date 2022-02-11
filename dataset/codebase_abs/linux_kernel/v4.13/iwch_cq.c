static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = NULL ;
struct V_9 V_10 , * V_11 ;
struct V_12 * V_13 ;
T_1 V_14 = 0 ;
T_2 V_15 ;
T_3 V_16 ;
int V_17 = 1 ;
V_11 = F_2 ( & V_4 -> V_18 ) ;
if ( ! V_11 )
return 0 ;
V_8 = F_3 ( V_2 , F_4 ( * V_11 ) ) ;
if ( ! V_8 )
V_13 = NULL ;
else {
F_5 ( & V_8 -> V_19 ) ;
V_13 = & ( V_8 -> V_13 ) ;
}
V_17 = F_6 ( V_13 , & ( V_4 -> V_18 ) , & V_10 , & V_15 , & V_16 ,
& V_14 ) ;
if ( F_7 ( V_4 -> V_2 ) && V_14 ) {
F_8 ( L_1 , V_20 ,
V_14 , V_4 -> V_18 . V_21 ) ;
F_9 ( & V_2 -> V_22 , & V_4 -> V_18 , V_23 , V_14 ) ;
}
if ( V_17 ) {
V_17 = - V_24 ;
goto V_25;
}
V_17 = 1 ;
V_6 -> V_26 = V_16 ;
V_6 -> V_27 = & V_8 -> V_28 ;
V_6 -> V_29 = F_10 ( V_10 ) ;
V_6 -> V_30 = 0 ;
F_8 ( L_2 ,
V_20 ,
F_4 ( V_10 ) , F_11 ( V_10 ) ,
F_12 ( V_10 ) , F_10 ( V_10 ) , F_13 ( V_10 ) ,
F_14 ( V_10 ) , ( unsigned long long ) V_16 ) ;
if ( F_11 ( V_10 ) == 0 ) {
if ( ! F_10 ( V_10 ) )
V_6 -> V_31 = F_15 ( V_10 ) ;
else
V_6 -> V_31 = 0 ;
V_6 -> V_32 = V_33 ;
if ( F_12 ( V_10 ) == V_34 ||
F_12 ( V_10 ) == V_35 ) {
V_6 -> V_36 . V_37 = F_16 ( V_10 ) ;
V_6 -> V_30 |= V_38 ;
}
} else {
switch ( F_12 ( V_10 ) ) {
case V_39 :
V_6 -> V_32 = V_40 ;
break;
case V_41 :
V_6 -> V_32 = V_42 ;
V_6 -> V_31 = F_15 ( V_10 ) ;
break;
case V_43 :
case V_44 :
case V_34 :
case V_35 :
V_6 -> V_32 = V_45 ;
break;
case V_46 :
V_6 -> V_32 = V_47 ;
break;
case V_48 :
V_6 -> V_32 = V_49 ;
break;
default:
F_17 ( L_3 ,
F_12 ( V_10 ) , F_4 ( V_10 ) ) ;
V_17 = - V_50 ;
goto V_25;
}
}
if ( V_15 )
V_6 -> V_51 = V_52 ;
else {
switch ( F_10 ( V_10 ) ) {
case V_53 :
V_6 -> V_51 = V_54 ;
break;
case V_55 :
V_6 -> V_51 = V_56 ;
break;
case V_57 :
V_6 -> V_51 = V_58 ;
break;
case V_59 :
case V_60 :
V_6 -> V_51 = V_56 ;
break;
case V_61 :
V_6 -> V_51 = V_62 ;
break;
case V_63 :
V_6 -> V_51 = V_64 ;
break;
case V_65 :
case V_66 :
V_6 -> V_51 = V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_6 -> V_51 = V_81 ;
break;
case V_82 :
V_6 -> V_51 = V_52 ;
break;
default:
F_17 ( L_4 ,
F_10 ( V_10 ) , F_4 ( V_10 ) ) ;
V_17 = - V_50 ;
}
}
V_25:
if ( V_13 )
F_18 ( & V_8 -> V_19 ) ;
return V_17 ;
}
int F_19 ( struct V_83 * V_84 , int V_85 , struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned long V_86 ;
int V_87 ;
int V_88 = 0 ;
V_4 = F_20 ( V_84 ) ;
V_2 = V_4 -> V_2 ;
F_21 ( & V_4 -> V_19 , V_86 ) ;
for ( V_87 = 0 ; V_87 < V_85 ; ++ V_87 ) {
#ifdef F_22
int V_89 = 0 ;
#endif
do {
V_88 = F_1 ( V_2 , V_4 , V_6 + V_87 ) ;
#ifdef F_22
F_23 ( ++ V_89 > 1000 ) ;
#endif
} while ( V_88 == - V_24 );
if ( V_88 <= 0 )
break;
}
F_24 ( & V_4 -> V_19 , V_86 ) ;
if ( V_88 < 0 )
return V_88 ;
else {
return V_87 ;
}
}
