int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
goto V_4;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
goto V_5;
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
goto V_6;
V_3 = F_5 ( V_2 ) ;
if ( V_3 )
goto V_7;
return 0 ;
V_7:
F_6 ( V_2 ) ;
V_6:
F_7 ( V_2 ) ;
V_5:
F_8 ( V_2 ) ;
V_4:
return V_3 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
int F_11 ( struct V_1 * V_2 , void * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_8 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 , V_3 = 0 ;
T_1 T_2 * V_22 ;
T_1 T_2 * V_23 ;
T_1 T_2 * V_24 ;
T_1 T_2 * V_25 ;
struct V_26 V_27 ;
if ( ! F_12 ( V_2 , V_28 ) )
return - V_29 ;
F_13 ( & V_10 -> V_30 ) ;
V_21 = 0 ;
V_22 = F_14 ( V_12 -> V_31 ) ;
F_15 (fb, &file_priv->fbs, filp_head) {
if ( V_21 < V_12 -> V_32 &&
F_16 ( V_14 -> V_33 . V_34 , V_22 + V_21 ) ) {
F_17 ( & V_10 -> V_30 ) ;
return - V_35 ;
}
V_21 ++ ;
}
V_12 -> V_32 = V_21 ;
F_17 ( & V_10 -> V_30 ) ;
V_12 -> V_36 = V_2 -> V_37 . V_36 ;
V_12 -> V_38 = V_2 -> V_37 . V_38 ;
V_12 -> V_39 = V_2 -> V_37 . V_39 ;
V_12 -> V_40 = V_2 -> V_37 . V_40 ;
V_21 = 0 ;
V_23 = F_14 ( V_12 -> V_41 ) ;
F_18 (crtc, dev) {
if ( V_21 < V_12 -> V_42 &&
F_16 ( V_18 -> V_33 . V_34 , V_23 + V_21 ) )
return - V_35 ;
V_21 ++ ;
}
V_12 -> V_42 = V_21 ;
V_21 = 0 ;
V_25 = F_14 ( V_12 -> V_43 ) ;
F_19 (encoder, dev) {
if ( V_21 < V_12 -> V_44 &&
F_16 ( V_20 -> V_33 . V_34 , V_25 + V_21 ) )
return - V_35 ;
V_21 ++ ;
}
V_12 -> V_44 = V_21 ;
F_20 ( V_2 , & V_27 ) ;
V_21 = 0 ;
V_24 = F_14 ( V_12 -> V_45 ) ;
F_21 (connector, &conn_iter) {
if ( V_21 < V_12 -> V_46 &&
F_16 ( V_16 -> V_33 . V_34 , V_24 + V_21 ) ) {
F_22 ( & V_27 ) ;
return - V_35 ;
}
V_21 ++ ;
}
V_12 -> V_46 = V_21 ;
F_22 ( & V_27 ) ;
return V_3 ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_47 * V_48 ;
struct V_19 * V_20 ;
struct V_15 * V_16 ;
struct V_26 V_27 ;
F_24 (plane, dev)
if ( V_48 -> V_49 -> V_50 )
V_48 -> V_49 -> V_50 ( V_48 ) ;
F_18 (crtc, dev)
if ( V_18 -> V_49 -> V_50 )
V_18 -> V_49 -> V_50 ( V_18 ) ;
F_19 (encoder, dev)
if ( V_20 -> V_49 -> V_50 )
V_20 -> V_49 -> V_50 ( V_20 ) ;
F_20 ( V_2 , & V_27 ) ;
F_21 (connector, &conn_iter)
if ( V_16 -> V_49 -> V_50 )
V_16 -> V_49 -> V_50 ( V_16 ) ;
F_22 ( & V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
int V_3 ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_52 = F_27 ( V_2 , V_53 ,
L_1 , V_54 ,
F_28 ( V_54 ) ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_56 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_2 , 0 , V_58 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_59 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_3 , 0 , V_58 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_60 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_4 , 0 , V_58 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_61 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_5 , 0 , V_58 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_62 = V_52 ;
V_52 = F_30 ( V_2 , V_57 ,
L_6 , V_63 , V_64 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_65 = V_52 ;
V_52 = F_30 ( V_2 , V_57 ,
L_7 , V_63 , V_64 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_66 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_8 , 0 , V_64 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_67 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_9 , 0 , V_64 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_68 = V_52 ;
V_52 = F_31 ( V_2 , V_57 ,
L_10 , V_69 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_70 = V_52 ;
V_52 = F_30 ( V_2 , V_57 ,
L_11 , - 1 , V_64 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_71 = V_52 ;
V_52 = F_29 ( V_2 , V_57 ,
L_12 , 0 , V_72 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_73 = V_52 ;
V_52 = F_31 ( V_2 , V_57 ,
L_13 , V_74 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_75 = V_52 ;
V_52 = F_32 ( V_2 , V_57 ,
L_14 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_76 = V_52 ;
V_52 = F_33 ( V_2 ,
V_57 | V_77 ,
L_15 , 0 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_78 = V_52 ;
V_52 = F_33 ( V_2 ,
V_77 ,
L_16 , 0 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_79 = V_52 ;
V_52 = F_29 ( V_2 ,
V_53 ,
L_17 , 0 , V_58 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_80 = V_52 ;
V_52 = F_33 ( V_2 ,
V_77 ,
L_18 , 0 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_81 = V_52 ;
V_52 = F_33 ( V_2 ,
V_77 ,
L_19 , 0 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_82 = V_52 ;
V_52 = F_29 ( V_2 ,
V_53 ,
L_20 , 0 , V_58 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_83 = V_52 ;
V_52 = F_33 ( V_2 ,
V_53 | V_77 ,
L_21 , 0 ) ;
if ( ! V_52 )
return - V_55 ;
V_2 -> V_37 . V_84 = V_52 ;
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_37 . V_85 ) ;
F_36 ( & V_2 -> V_37 . V_86 ) ;
F_35 ( & V_2 -> V_37 . V_87 ) ;
F_35 ( & V_2 -> V_37 . V_88 ) ;
F_35 ( & V_2 -> V_37 . V_89 ) ;
F_37 ( & V_2 -> V_37 . V_90 ) ;
F_37 ( & V_2 -> V_37 . V_91 ) ;
F_37 ( & V_2 -> V_37 . V_92 ) ;
F_37 ( & V_2 -> V_37 . V_93 ) ;
F_37 ( & V_2 -> V_37 . V_94 ) ;
F_37 ( & V_2 -> V_37 . V_95 ) ;
F_37 ( & V_2 -> V_37 . V_96 ) ;
F_38 ( & V_2 -> V_37 . V_97 ) ;
F_38 ( & V_2 -> V_37 . V_98 ) ;
F_39 ( & V_2 -> V_37 . V_99 ) ;
F_40 ( & V_2 -> V_37 . V_100 ) ;
F_25 ( V_2 ) ;
V_2 -> V_37 . V_101 = 0 ;
V_2 -> V_37 . V_102 = 0 ;
V_2 -> V_37 . V_103 = 0 ;
V_2 -> V_37 . V_104 = 0 ;
V_2 -> V_37 . V_105 = 0 ;
V_2 -> V_37 . V_106 = 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_26 V_27 ;
struct V_17 * V_18 , * V_107 ;
struct V_19 * V_20 , * V_108 ;
struct V_13 * V_14 , * V_109 ;
struct V_51 * V_110 , * V_111 ;
struct V_112 * V_113 , * V_114 ;
struct V_47 * V_48 , * V_115 ;
F_42 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_20 -> V_49 -> V_116 ( V_20 ) ;
}
F_20 ( V_2 , & V_27 ) ;
F_21 (connector, &conn_iter) {
F_43 ( V_16 ) ;
}
F_22 ( & V_27 ) ;
if ( F_44 ( ! F_45 ( & V_2 -> V_37 . V_92 ) ) ) {
F_20 ( V_2 , & V_27 ) ;
F_21 (connector, &conn_iter)
F_46 ( L_22 , V_16 -> V_117 ) ;
F_22 ( & V_27 ) ;
}
F_42 (property, pt, &dev->mode_config.property_list,
head) {
F_47 ( V_2 , V_110 ) ;
}
F_42 (plane, plt, &dev->mode_config.plane_list,
head) {
V_48 -> V_49 -> V_116 ( V_48 ) ;
}
F_42 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_18 -> V_49 -> V_116 ( V_18 ) ;
}
F_42 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_48 ( V_113 ) ;
}
F_44 ( ! F_45 ( & V_2 -> V_37 . V_90 ) ) ;
F_42 (fb, fbt, &dev->mode_config.fb_list, head) {
F_49 ( & V_14 -> V_33 . V_118 ) ;
}
F_50 ( & V_2 -> V_37 . V_99 ) ;
F_51 ( & V_2 -> V_37 . V_98 ) ;
F_51 ( & V_2 -> V_37 . V_97 ) ;
F_52 ( & V_2 -> V_37 . V_86 ) ;
}
