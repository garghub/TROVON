static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_5 V_14 = 0 , V_15 = 4096 ;
char * V_16 ;
T_3 V_17 ;
int V_18 ;
V_16 = F_2 ( V_15 , V_19 ) ;
if ( V_16 == NULL )
return - V_20 ;
if ( ! V_6 -> V_21 -> V_22 . V_23 ) {
V_14 = F_3 ( V_16 , V_15 , L_1 ,
L_2 ) ;
goto exit;
}
V_14 = F_3 ( V_16 , V_15 , L_3 ,
V_6 -> V_24 ) ;
V_14 += F_3 ( V_16 + V_14 , V_15 - V_14 , L_4 ,
V_6 -> V_25 ) ;
V_14 += F_3 ( V_16 + V_14 , V_15 - V_14 ,
L_5 ,
L_6 , L_7 , L_8 , L_9 ,
L_10 , L_11 , L_12 , L_13 , L_14 ) ;
for ( V_18 = 0 ; V_18 < V_26 ; V_18 ++ ) {
V_11 = F_4 ( V_6 , V_18 ) ;
V_13 = V_11 -> V_13 ;
F_5 ( V_9 , V_13 ) ;
if ( V_11 -> V_27 ) {
V_14 += F_3 ( V_16 + V_14 , V_15 - V_14 ,
L_15 ,
V_11 -> V_18 ,
V_11 -> V_28 ,
V_11 -> V_29 ,
V_11 -> V_30 ,
V_11 -> V_31 ,
V_11 -> V_32 ,
V_11 -> V_33 ,
! F_6 ( & V_11 -> V_34 ) ) ;
}
F_7 ( V_9 , V_13 ) ;
}
exit:
V_17 = F_8 ( V_2 , V_3 , V_4 , V_16 , V_14 ) ;
F_9 ( V_16 ) ;
return V_17 ;
}
void F_10 ( struct V_8 * V_9 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = (struct V_39 * ) V_38 -> V_41 ;
struct V_42 * V_43 = V_9 -> V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_21 ;
struct V_5 * V_6 ;
if ( ! F_11 ( V_40 -> V_50 ) )
return;
F_12 () ;
V_21 = F_13 ( V_9 -> V_51 , V_40 -> V_52 , NULL ) ;
if ( ! V_21 )
goto exit;
V_6 = (struct V_5 * ) V_21 -> V_53 ;
V_48 = & V_6 -> V_54 ;
V_46 = F_14 ( V_38 ) ;
if ( F_15 ( V_36 -> V_55 ) ) {
if ( V_46 -> V_56 >= F_16 ( V_48 -> V_57 ) )
goto exit;
if ( V_46 -> V_58 & V_59 )
V_48 -> V_57 [ V_46 -> V_56 ] . V_60 ++ ;
else
V_48 -> V_57 [ V_46 -> V_56 ] . V_61 ++ ;
if ( V_46 -> V_58 & V_62 )
V_48 -> V_57 [ V_46 -> V_56 ] . V_63 ++ ;
else
V_48 -> V_57 [ V_46 -> V_56 ] . V_64 ++ ;
goto exit;
}
if ( F_17 ( V_36 -> V_55 ) ) {
if ( V_46 -> V_58 & V_65 )
V_48 -> V_66 [ V_46 -> V_56 ] . V_67 ++ ;
else
V_48 -> V_66 [ V_46 -> V_56 ] . V_68 ++ ;
goto exit;
}
if ( F_18 ( V_36 -> V_55 ) ) {
if ( V_43 -> V_69 -> V_70 -> V_71 == V_72 )
V_48 -> V_73 [ V_46 -> V_56 - 4 ] . V_74 ++ ;
else
V_48 -> V_73 [ V_46 -> V_56 ] . V_74 ++ ;
}
exit:
F_19 () ;
}
static T_1 F_20 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_42 * V_43 = V_9 -> V_44 ;
struct V_47 * V_48 ;
struct V_49 * V_21 = V_6 -> V_21 ;
enum V_75 V_71 ;
T_5 V_14 = 0 , V_15 = 4096 ;
char * V_16 ;
T_3 V_17 ;
int V_76 ;
V_16 = F_2 ( V_15 , V_19 ) ;
if ( V_16 == NULL )
return - V_20 ;
V_71 = V_43 -> V_69 -> V_70 -> V_71 ;
V_48 = & V_6 -> V_54 ;
if ( ! V_21 -> V_22 . V_23 )
goto V_77;
V_14 += F_3 ( V_16 + V_14 , V_15 - V_14 ,
L_16 ,
L_17 , L_18 , L_19 , L_20 ) ;
for ( V_76 = 0 ; V_76 < 24 ; V_76 ++ ) {
V_14 += F_3 ( V_16 + V_14 , V_15 - V_14 ,
L_21 ,
L_22 , V_76 ,
V_48 -> V_57 [ V_76 ] . V_61 ,
V_48 -> V_57 [ V_76 ] . V_60 ,
V_48 -> V_57 [ V_76 ] . V_63 ,
V_48 -> V_57 [ V_76 ] . V_64 ) ;
}
V_14 += F_3 ( V_16 + V_14 , V_15 - V_14 , L_23 ) ;
V_77:
if ( V_71 == V_72 ) {
F_21 ( L_24 , 0 , false ) ;
F_21 ( L_25 , 1 , false ) ;
F_21 ( L_26 , 2 , false ) ;
F_21 ( L_27 , 3 , false ) ;
F_21 ( L_28 , 1 , true ) ;
F_21 ( L_29 , 2 , true ) ;
F_21 ( L_30 , 3 , true ) ;
}
F_22 ( L_31 , 0 ) ;
F_22 ( L_32 , 1 ) ;
F_22 ( L_33 , 2 ) ;
F_22 ( L_34 , 3 ) ;
F_22 ( L_35 , 4 ) ;
F_22 ( L_36 , 5 ) ;
F_22 ( L_37 , 6 ) ;
F_22 ( L_38 , 7 ) ;
V_17 = F_8 ( V_2 , V_3 , V_4 , V_16 , V_14 ) ;
F_9 ( V_16 ) ;
return V_17 ;
}
void F_23 ( struct V_78 * V_51 ,
struct V_79 * V_80 ,
struct V_49 * V_21 ,
struct V_81 * V_82 )
{
struct V_5 * V_6 = (struct V_5 * ) V_21 -> V_53 ;
F_24 ( L_39 , V_83 , V_82 , V_6 , & V_84 ) ;
F_24 ( L_40 , V_83 , V_82 , V_6 , & V_85 ) ;
}
