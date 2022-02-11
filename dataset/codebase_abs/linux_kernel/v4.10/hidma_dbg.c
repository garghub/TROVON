static void F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_3 ;
struct V_7 * V_8 ;
T_1 V_9 ;
T_2 V_10 ;
T_2 V_11 ;
T_1 * V_12 ;
if ( V_4 >= V_6 -> V_13 ) {
F_2 ( V_6 -> V_14 , L_1 , V_4 ) ;
return;
}
V_8 = & V_6 -> V_15 [ V_4 ] ;
F_3 ( V_2 , L_2 , V_4 ) ;
F_3 ( V_2 , L_3 , F_4 ( & V_8 -> V_16 ) ) ;
F_3 ( V_2 , L_4 , V_8 -> V_17 ) ;
F_3 ( V_2 , L_5 , V_8 -> V_18 ) ;
F_3 ( V_2 , L_6 , V_8 -> V_19 ) ;
F_3 ( V_2 , L_7 , V_8 -> V_20 ) ;
F_3 ( V_2 , L_8 , V_8 -> V_21 ) ;
F_3 ( V_2 , L_9 , V_8 -> V_22 ) ;
F_3 ( V_2 , L_10 , V_8 -> V_23 ) ;
F_3 ( V_2 , L_11 , V_8 -> V_24 ) ;
F_3 ( V_2 , L_12 , V_8 -> V_25 ) ;
F_3 ( V_2 , L_13 , V_8 -> V_26 ) ;
V_12 = & V_8 -> V_12 [ 0 ] ;
V_10 = V_12 [ V_27 ] ;
V_10 = ( ( V_28 ) ( V_12 [ V_29 ] ) << 32 ) + V_10 ;
V_11 = V_12 [ V_30 ] ;
V_11 += ( ( V_28 ) ( V_12 [ V_31 ] ) << 32 ) ;
V_9 = V_12 [ V_32 ] ;
F_3 ( V_2 , L_14 , & V_10 ) ;
F_3 ( V_2 , L_15 , & V_11 ) ;
F_3 ( V_2 , L_16 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_6 = V_3 ;
F_6 ( V_2 , L_17 ) ;
F_3 ( V_2 , L_18 , V_6 -> V_33 ) ;
F_3 ( V_2 , L_19 , V_6 -> V_34 ) ;
F_3 ( V_2 , L_20 , V_6 -> V_35 ) ;
F_3 ( V_2 , L_21 , V_6 -> V_36 ) ;
F_3 ( V_2 , L_22 , V_6 -> V_13 ) ;
F_3 ( V_2 , L_23 , V_6 -> V_37 ) ;
F_3 ( V_2 , L_24 , V_6 -> V_38 ) ;
F_3 ( V_2 , L_25 , & V_6 -> V_39 ) ;
F_3 ( V_2 , L_26 , V_6 -> V_40 ) ;
F_3 ( V_2 , L_27 , V_6 -> V_41 ) ;
F_3 ( V_2 , L_28 ,
F_4 ( & V_6 -> V_42 ) ) ;
F_3 ( V_2 , L_29 , V_6 -> V_43 ) ;
F_3 ( V_2 , L_30 , V_6 -> V_44 ) ;
F_3 ( V_2 , L_31 , & V_6 -> V_45 ) ;
F_3 ( V_2 , L_32 , V_6 -> V_46 ) ;
F_3 ( V_2 , L_33 , V_6 -> V_47 ) ;
F_3 ( V_2 , L_34 , V_6 -> V_48 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_49 )
{
struct V_50 * V_51 = V_2 -> V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 = V_51 -> V_56 ;
F_8 ( V_56 -> V_57 . V_14 ) ;
F_3 ( V_2 , L_35 , V_51 -> V_58 ) ;
F_3 ( V_2 , L_36 , V_51 -> V_22 ) ;
F_6 ( V_2 , L_37 ) ;
F_9 (mdesc, &mchan->prepared, node)
F_1 ( V_2 , V_51 -> V_56 -> V_6 , V_54 -> V_4 ) ;
F_6 ( V_2 , L_38 ) ;
F_9 (mdesc, &mchan->active, node)
F_1 ( V_2 , V_51 -> V_56 -> V_6 , V_54 -> V_4 ) ;
F_6 ( V_2 , L_39 ) ;
F_9 (mdesc, &mchan->completed, node)
F_1 ( V_2 , V_51 -> V_56 -> V_6 , V_54 -> V_4 ) ;
F_5 ( V_2 , V_51 -> V_56 -> V_6 ) ;
F_10 ( V_56 -> V_57 . V_14 ) ;
F_11 ( V_56 -> V_57 . V_14 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_49 )
{
struct V_55 * V_56 = V_2 -> V_52 ;
T_3 V_59 ;
F_3 ( V_2 , L_40 , V_56 -> V_60 ) ;
F_3 ( V_2 , L_41 , & V_56 -> V_61 ) ;
F_3 ( V_2 , L_42 , & V_56 -> V_62 -> V_63 ) ;
V_59 = F_13 ( V_56 -> V_62 ) ;
F_3 ( V_2 , L_43 , & V_59 ) ;
F_3 ( V_2 , L_44 , & V_56 -> V_64 ) ;
F_3 ( V_2 , L_45 , & V_56 -> V_65 -> V_63 ) ;
V_59 = F_13 ( V_56 -> V_65 ) ;
F_3 ( V_2 , L_46 , & V_59 ) ;
return 0 ;
}
static int F_14 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_15 ( V_67 , F_7 , V_66 -> V_68 ) ;
}
static int F_16 ( struct V_66 * V_66 , struct V_67 * V_67 )
{
return F_15 ( V_67 , F_12 , V_66 -> V_68 ) ;
}
void F_17 ( struct V_55 * V_56 )
{
F_18 ( V_56 -> V_69 ) ;
}
int F_19 ( struct V_55 * V_56 )
{
int V_70 = 0 ;
int V_36 = 0 ;
struct V_71 * V_72 = NULL ;
V_56 -> V_69 = F_20 ( V_23 ( V_56 -> V_57 . V_14 ) , NULL ) ;
if ( ! V_56 -> V_69 ) {
V_70 = - V_73 ;
return V_70 ;
}
F_21 (position, &dmadev->ddev.channels) {
struct V_50 * V_74 ;
V_74 = F_22 ( V_72 , struct V_50 ,
V_74 . V_75 ) ;
sprintf ( V_74 -> V_76 , L_47 , V_36 ) ;
V_74 -> V_69 = F_20 ( V_74 -> V_76 ,
V_56 -> V_69 ) ;
if ( ! V_74 -> V_69 ) {
V_70 = - V_77 ;
goto V_78;
}
V_74 -> V_79 = F_23 ( L_48 , V_80 ,
V_74 -> V_69 , V_74 ,
& V_81 ) ;
if ( ! V_74 -> V_79 ) {
V_70 = - V_77 ;
goto V_78;
}
V_36 ++ ;
}
V_56 -> V_79 = F_23 ( L_48 , V_80 ,
V_56 -> V_69 , V_56 ,
& V_82 ) ;
if ( ! V_56 -> V_79 ) {
V_70 = - V_77 ;
goto V_78;
}
return 0 ;
V_78:
F_17 ( V_56 ) ;
return V_70 ;
}
