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
struct V_21 * V_22 ;
int V_3 = 0 ;
int V_23 = 0 ;
int V_24 = 0 ;
int V_25 = 0 ;
int V_26 = 0 ;
int V_27 = 0 ;
T_1 T_2 * V_28 ;
T_1 T_2 * V_29 ;
T_1 T_2 * V_30 ;
T_1 T_2 * V_31 ;
if ( ! F_12 ( V_2 , V_32 ) )
return - V_33 ;
F_13 ( & V_10 -> V_34 ) ;
F_14 (lh, &file_priv->fbs)
V_25 ++ ;
if ( V_12 -> V_35 >= V_25 ) {
V_27 = 0 ;
V_28 = ( T_1 T_2 * ) ( unsigned long ) V_12 -> V_36 ;
F_15 (fb, &file_priv->fbs, filp_head) {
if ( F_16 ( V_16 -> V_37 . V_38 , V_28 + V_27 ) ) {
F_17 ( & V_10 -> V_34 ) ;
return - V_39 ;
}
V_27 ++ ;
}
}
V_12 -> V_35 = V_25 ;
F_17 ( & V_10 -> V_34 ) ;
F_13 ( & V_2 -> V_40 . V_41 ) ;
F_18 (crtc, dev)
V_24 ++ ;
F_19 (connector, dev)
V_23 ++ ;
F_20 (encoder, dev)
V_26 ++ ;
V_12 -> V_42 = V_2 -> V_40 . V_42 ;
V_12 -> V_43 = V_2 -> V_40 . V_43 ;
V_12 -> V_44 = V_2 -> V_40 . V_44 ;
V_12 -> V_45 = V_2 -> V_40 . V_45 ;
if ( V_12 -> V_46 >= V_24 ) {
V_27 = 0 ;
V_29 = ( T_1 T_2 * ) ( unsigned long ) V_12 -> V_47 ;
F_18 (crtc, dev) {
if ( F_16 ( V_20 -> V_37 . V_38 , V_29 + V_27 ) ) {
V_3 = - V_39 ;
goto V_48;
}
V_27 ++ ;
}
}
V_12 -> V_46 = V_24 ;
if ( V_12 -> V_49 >= V_26 ) {
V_27 = 0 ;
V_31 = ( T_1 T_2 * ) ( unsigned long ) V_12 -> V_50 ;
F_20 (encoder, dev) {
if ( F_16 ( V_22 -> V_37 . V_38 , V_31 +
V_27 ) ) {
V_3 = - V_39 ;
goto V_48;
}
V_27 ++ ;
}
}
V_12 -> V_49 = V_26 ;
if ( V_12 -> V_51 >= V_23 ) {
V_27 = 0 ;
V_30 = ( T_1 T_2 * ) ( unsigned long ) V_12 -> V_52 ;
F_19 (connector, dev) {
if ( F_16 ( V_18 -> V_37 . V_38 ,
V_30 + V_27 ) ) {
V_3 = - V_39 ;
goto V_48;
}
V_27 ++ ;
}
}
V_12 -> V_51 = V_23 ;
V_48:
F_17 ( & V_2 -> V_40 . V_41 ) ;
return V_3 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_53 * V_54 ;
struct V_21 * V_22 ;
struct V_17 * V_18 ;
F_22 (plane, dev)
if ( V_54 -> V_55 -> V_56 )
V_54 -> V_55 -> V_56 ( V_54 ) ;
F_18 (crtc, dev)
if ( V_20 -> V_55 -> V_56 )
V_20 -> V_55 -> V_56 ( V_20 ) ;
F_20 (encoder, dev)
if ( V_22 -> V_55 -> V_56 )
V_22 -> V_55 -> V_56 ( V_22 ) ;
F_13 ( & V_2 -> V_40 . V_41 ) ;
F_19 (connector, dev)
if ( V_18 -> V_55 -> V_56 )
V_18 -> V_55 -> V_56 ( V_18 ) ;
F_17 ( & V_2 -> V_40 . V_41 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
int V_3 ;
V_3 = F_24 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_58 = F_25 ( V_2 , V_59 ,
L_1 , V_60 ,
F_26 ( V_60 ) ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_62 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_2 , 0 , V_64 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_65 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_3 , 0 , V_64 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_66 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_4 , 0 , V_64 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_67 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_5 , 0 , V_64 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_68 = V_58 ;
V_58 = F_28 ( V_2 , V_63 ,
L_6 , V_69 , V_70 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_71 = V_58 ;
V_58 = F_28 ( V_2 , V_63 ,
L_7 , V_69 , V_70 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_72 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_8 , 0 , V_70 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_73 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_9 , 0 , V_70 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_74 = V_58 ;
V_58 = F_29 ( V_2 , V_63 ,
L_10 , V_75 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_76 = V_58 ;
V_58 = F_28 ( V_2 , V_63 ,
L_11 , - 1 , V_70 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_77 = V_58 ;
V_58 = F_27 ( V_2 , V_63 ,
L_12 , 0 , V_78 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_79 = V_58 ;
V_58 = F_29 ( V_2 , V_63 ,
L_13 , V_80 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_81 = V_58 ;
V_58 = F_30 ( V_2 , V_63 ,
L_14 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_82 = V_58 ;
V_58 = F_31 ( V_2 ,
V_63 | V_83 ,
L_15 , 0 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_84 = V_58 ;
V_58 = F_31 ( V_2 ,
V_83 ,
L_16 , 0 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_85 = V_58 ;
V_58 = F_27 ( V_2 ,
V_59 ,
L_17 , 0 , V_64 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_86 = V_58 ;
V_58 = F_31 ( V_2 ,
V_83 ,
L_18 , 0 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_87 = V_58 ;
V_58 = F_31 ( V_2 ,
V_83 ,
L_19 , 0 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_88 = V_58 ;
V_58 = F_27 ( V_2 ,
V_59 ,
L_20 , 0 , V_64 ) ;
if ( ! V_58 )
return - V_61 ;
V_2 -> V_40 . V_89 = V_58 ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_40 . V_41 ) ;
F_34 ( & V_2 -> V_40 . V_90 ) ;
F_33 ( & V_2 -> V_40 . V_91 ) ;
F_33 ( & V_2 -> V_40 . V_92 ) ;
F_33 ( & V_2 -> V_40 . V_93 ) ;
F_35 ( & V_2 -> V_40 . V_94 ) ;
F_35 ( & V_2 -> V_40 . V_95 ) ;
F_35 ( & V_2 -> V_40 . V_96 ) ;
F_35 ( & V_2 -> V_40 . V_97 ) ;
F_35 ( & V_2 -> V_40 . V_98 ) ;
F_35 ( & V_2 -> V_40 . V_99 ) ;
F_35 ( & V_2 -> V_40 . V_100 ) ;
F_36 ( & V_2 -> V_40 . V_101 ) ;
F_36 ( & V_2 -> V_40 . V_102 ) ;
F_37 ( & V_2 -> V_40 . V_103 ) ;
F_38 ( V_2 ) ;
F_23 ( V_2 ) ;
F_39 ( V_2 ) ;
V_2 -> V_40 . V_104 = 0 ;
V_2 -> V_40 . V_105 = 0 ;
V_2 -> V_40 . V_106 = 0 ;
V_2 -> V_40 . V_107 = 0 ;
V_2 -> V_40 . V_108 = 0 ;
V_2 -> V_40 . V_109 = 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_17 * V_18 , * V_110 ;
struct V_19 * V_20 , * V_111 ;
struct V_21 * V_22 , * V_112 ;
struct V_15 * V_16 , * V_113 ;
struct V_57 * V_114 , * V_115 ;
struct V_116 * V_117 , * V_118 ;
struct V_53 * V_54 , * V_119 ;
F_41 (encoder, enct, &dev->mode_config.encoder_list,
head) {
V_22 -> V_55 -> V_120 ( V_22 ) ;
}
F_41 (connector, ot,
&dev->mode_config.connector_list, head) {
V_18 -> V_55 -> V_120 ( V_18 ) ;
}
F_41 (property, pt, &dev->mode_config.property_list,
head) {
F_42 ( V_2 , V_114 ) ;
}
F_41 (plane, plt, &dev->mode_config.plane_list,
head) {
V_54 -> V_55 -> V_120 ( V_54 ) ;
}
F_41 (crtc, ct, &dev->mode_config.crtc_list, head) {
V_20 -> V_55 -> V_120 ( V_20 ) ;
}
F_41 (blob, bt, &dev->mode_config.property_blob_list,
head_global) {
F_43 ( V_117 ) ;
}
F_44 ( ! F_45 ( & V_2 -> V_40 . V_94 ) ) ;
F_41 (fb, fbt, &dev->mode_config.fb_list, head) {
F_46 ( & V_16 -> V_37 . V_121 ) ;
}
F_47 ( & V_2 -> V_40 . V_103 ) ;
F_48 ( & V_2 -> V_40 . V_102 ) ;
F_48 ( & V_2 -> V_40 . V_101 ) ;
F_49 ( & V_2 -> V_40 . V_90 ) ;
}
