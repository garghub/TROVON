static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
T_5 V_16 = 0 , V_17 = 4096 ;
char * V_18 ;
T_3 V_19 ;
int V_20 , V_21 ;
V_18 = F_2 ( V_17 , V_22 ) ;
if ( V_18 == NULL )
return - V_23 ;
if ( ! V_6 -> V_24 -> V_25 . V_26 ) {
V_16 = F_3 ( V_18 , V_17 , L_1 ,
L_2 ) ;
goto exit;
}
V_16 = F_3 ( V_18 , V_17 , L_3 ,
V_6 -> V_27 ) ;
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 , L_4 ,
V_6 -> V_28 ) ;
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 ,
L_5 , L_6 , L_7 ) ;
for ( V_21 = 0 , V_13 = & V_6 -> V_13 [ V_21 ] ;
V_21 < V_29 ; V_21 ++ , V_13 ++ ) {
V_15 = V_13 -> V_15 ;
F_4 ( V_9 , V_15 ) ;
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 ,
L_8 ,
V_21 , V_13 -> V_30 ) ;
F_5 ( V_9 , V_15 ) ;
}
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 ,
L_9 ,
L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_7 , L_17 ) ;
for ( V_20 = 0 , V_11 = & V_6 -> V_11 [ V_20 ] ;
V_20 < V_31 ; V_20 ++ , V_11 ++ ) {
V_15 = V_11 -> V_13 -> V_15 ;
F_4 ( V_9 , V_15 ) ;
if ( V_11 -> V_32 ) {
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 ,
L_18 ,
V_11 -> V_20 ,
V_11 -> V_33 ,
V_11 -> V_34 ,
V_11 -> V_35 ,
V_11 -> V_36 ,
V_11 -> V_37 ,
V_11 -> V_38 ,
V_11 -> V_30 ,
V_11 -> V_39 ) ;
}
F_5 ( V_9 , V_15 ) ;
}
exit:
V_19 = F_6 ( V_2 , V_3 , V_4 , V_18 , V_16 ) ;
F_7 ( V_18 ) ;
return V_19 ;
}
void F_8 ( struct V_8 * V_9 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = (struct V_44 * ) V_43 -> V_46 ;
struct V_47 * V_48 = V_9 -> V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_24 ;
struct V_5 * V_6 ;
if ( ! F_9 ( V_45 -> V_55 ) )
return;
F_10 () ;
V_24 = F_11 ( V_9 -> V_56 , V_45 -> V_57 , NULL ) ;
if ( ! V_24 )
goto exit;
V_6 = (struct V_5 * ) V_24 -> V_58 ;
V_53 = & V_6 -> V_59 ;
V_51 = F_12 ( V_43 ) ;
if ( F_13 ( V_41 -> V_60 ) ) {
if ( V_51 -> V_61 >= F_14 ( V_53 -> V_62 ) )
goto exit;
if ( V_51 -> V_63 & V_64 )
V_53 -> V_62 [ V_51 -> V_61 ] . V_65 ++ ;
else
V_53 -> V_62 [ V_51 -> V_61 ] . V_66 ++ ;
if ( V_51 -> V_63 & V_67 )
V_53 -> V_62 [ V_51 -> V_61 ] . V_68 ++ ;
else
V_53 -> V_62 [ V_51 -> V_61 ] . V_69 ++ ;
goto exit;
}
if ( F_15 ( V_41 -> V_60 ) ) {
if ( V_51 -> V_63 & V_70 )
V_53 -> V_71 [ V_51 -> V_61 ] . V_72 ++ ;
else
V_53 -> V_71 [ V_51 -> V_61 ] . V_73 ++ ;
goto exit;
}
if ( F_16 ( V_41 -> V_60 ) ) {
if ( V_48 -> V_74 -> V_75 -> V_76 == V_77 )
V_53 -> V_78 [ V_51 -> V_61 - 4 ] . V_79 ++ ;
else
V_53 -> V_78 [ V_51 -> V_61 ] . V_79 ++ ;
}
exit:
F_17 () ;
}
static T_1 F_18 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_47 * V_48 = V_9 -> V_49 ;
struct V_52 * V_53 ;
struct V_54 * V_24 = V_6 -> V_24 ;
enum V_80 V_76 ;
T_5 V_16 = 0 , V_17 = 4096 ;
char * V_18 ;
T_3 V_19 ;
int V_81 ;
V_18 = F_2 ( V_17 , V_22 ) ;
if ( V_18 == NULL )
return - V_23 ;
V_76 = V_48 -> V_74 -> V_75 -> V_76 ;
V_53 = & V_6 -> V_59 ;
if ( ! V_24 -> V_25 . V_26 )
goto V_82;
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 ,
L_19 ,
L_20 , L_21 , L_22 , L_23 ) ;
for ( V_81 = 0 ; V_81 < 24 ; V_81 ++ ) {
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 ,
L_24 ,
L_25 , V_81 ,
V_53 -> V_62 [ V_81 ] . V_66 ,
V_53 -> V_62 [ V_81 ] . V_65 ,
V_53 -> V_62 [ V_81 ] . V_68 ,
V_53 -> V_62 [ V_81 ] . V_69 ) ;
}
V_16 += F_3 ( V_18 + V_16 , V_17 - V_16 , L_26 ) ;
V_82:
if ( V_76 == V_77 ) {
F_19 ( L_27 , 0 , false ) ;
F_19 ( L_28 , 1 , false ) ;
F_19 ( L_29 , 2 , false ) ;
F_19 ( L_30 , 3 , false ) ;
F_19 ( L_31 , 1 , true ) ;
F_19 ( L_32 , 2 , true ) ;
F_19 ( L_33 , 3 , true ) ;
}
F_20 ( L_34 , 0 ) ;
F_20 ( L_35 , 1 ) ;
F_20 ( L_36 , 2 ) ;
F_20 ( L_37 , 3 ) ;
F_20 ( L_38 , 4 ) ;
F_20 ( L_39 , 5 ) ;
F_20 ( L_40 , 6 ) ;
F_20 ( L_41 , 7 ) ;
V_19 = F_6 ( V_2 , V_3 , V_4 , V_18 , V_16 ) ;
F_7 ( V_18 ) ;
return V_19 ;
}
void F_21 ( struct V_83 * V_56 ,
struct V_84 * V_85 ,
struct V_54 * V_24 ,
struct V_86 * V_87 )
{
struct V_5 * V_6 = (struct V_5 * ) V_24 -> V_58 ;
F_22 ( L_42 , V_88 , V_87 , V_6 , & V_89 ) ;
F_22 ( L_43 , V_88 , V_87 , V_6 , & V_90 ) ;
}
