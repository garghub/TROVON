bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
void F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
V_6 -> clock = V_8 -> V_9 / 1000 ;
V_6 -> V_10 = V_8 -> V_11 ;
V_6 -> V_12 = V_6 -> V_10 + V_8 -> V_13 ;
V_6 -> V_14 = V_6 -> V_12 + V_8 -> V_15 ;
V_6 -> V_16 = V_6 -> V_14 + V_8 -> V_17 ;
V_6 -> V_18 = V_8 -> V_19 ;
V_6 -> V_20 = V_6 -> V_18 + V_8 -> V_21 ;
V_6 -> V_22 = V_6 -> V_20 + V_8 -> V_23 ;
V_6 -> V_24 = V_6 -> V_22 + V_8 -> V_25 ;
V_6 -> V_26 = 0 ;
if ( V_8 -> V_27 )
V_6 -> V_26 |= V_28 ;
if ( V_8 -> V_29 )
V_6 -> V_26 |= V_30 ;
if ( V_8 -> V_31 == V_32 )
V_6 -> V_26 |= V_33 ;
else
V_6 -> V_26 |= V_34 ;
if ( V_8 -> V_35 == V_32 )
V_6 -> V_26 |= V_36 ;
else
V_6 -> V_26 |= V_37 ;
}
void F_4 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
V_8 -> V_9 = V_6 -> clock * 1000 ;
V_8 -> V_11 = V_6 -> V_10 ;
V_8 -> V_13 = V_6 -> V_12 - V_6 -> V_10 ;
V_8 -> V_15 = V_6 -> V_14 - V_6 -> V_12 ;
V_8 -> V_17 = V_6 -> V_16 - V_6 -> V_14 ;
V_8 -> V_19 = V_6 -> V_18 ;
V_8 -> V_21 = V_6 -> V_20 - V_6 -> V_18 ;
V_8 -> V_23 = V_6 -> V_22 - V_6 -> V_20 ;
V_8 -> V_25 = V_6 -> V_24 - V_6 -> V_22 ;
V_8 -> V_27 = ! ! ( V_6 -> V_26 & V_28 ) ;
V_8 -> V_29 = ! ! ( V_6 -> V_26 & V_30 ) ;
if ( V_6 -> V_26 & V_33 )
V_8 -> V_31 = V_32 ;
else
V_8 -> V_31 = V_38 ;
if ( V_6 -> V_26 & V_36 )
V_8 -> V_35 = V_32 ;
else
V_8 -> V_35 = V_38 ;
V_8 -> V_39 = V_40 ;
V_8 -> V_41 = V_32 ;
V_8 -> V_42 = V_43 ;
}
static enum V_44 F_5 (
struct V_1 * V_2 , bool V_45 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_46 * V_47 = V_3 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
enum V_44 V_51 ;
if ( V_49 -> V_52 ) {
if ( V_49 -> V_52 ( V_47 ) )
V_51 = V_53 ;
else
V_51 = V_54 ;
} else if ( V_47 -> type == V_55 ||
V_47 -> type == V_56 ||
V_47 -> type == V_57 ||
V_47 -> type == V_58 ) {
V_51 = V_53 ;
} else {
V_51 = V_59 ;
}
F_6 ( L_1 , V_3 -> V_47 -> V_60 , V_51 , V_45 ) ;
return V_51 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_46 * V_47 = V_3 -> V_47 ;
F_8 ( L_2 , V_3 -> V_47 -> V_60 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_3 ) ;
F_12 ( V_47 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_46 * V_47 = V_3 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_63 = 0 ;
F_8 ( L_2 , V_3 -> V_47 -> V_60 ) ;
if ( V_49 -> V_64 ) {
void * V_65 = F_14 ( V_66 , V_67 ) ;
if ( ( V_49 -> V_64 ( V_47 , V_65 , V_66 ) > 0 ) &&
F_15 ( V_65 ) ) {
F_16 (
V_2 , V_65 ) ;
V_63 = F_17 ( V_2 , V_65 ) ;
V_3 -> V_4 =
F_18 ( V_65 ) ;
} else {
F_16 (
V_2 , NULL ) ;
}
F_11 ( V_65 ) ;
} else {
struct V_5 * V_6 = F_19 ( V_62 ) ;
struct V_7 V_8 = { 0 } ;
V_49 -> V_68 ( V_47 , & V_8 ) ;
F_3 ( V_6 , & V_8 ) ;
V_6 -> type = V_69 | V_70 ;
F_20 ( V_6 ) ;
F_21 ( V_2 , V_6 ) ;
V_63 = 1 ;
}
return V_63 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_46 * V_47 = V_3 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_7 V_8 = { 0 } ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_5 * V_71 ;
int V_72 , V_51 = V_73 ;
F_4 ( & V_8 , V_6 ) ;
V_6 -> V_74 = F_23 ( V_6 ) ;
if ( V_49 -> V_75 ) {
V_72 = V_49 -> V_75 ( V_47 , & V_8 ) ;
} else {
struct V_7 V_76 = { 0 } ;
V_49 -> V_68 ( V_47 , & V_76 ) ;
if ( memcmp ( & V_8 , & V_76 , sizeof( struct V_7 ) ) )
V_72 = - V_77 ;
else
V_72 = 0 ;
}
if ( ! V_72 ) {
V_71 = F_24 ( V_62 , V_6 ) ;
V_71 -> clock = V_8 . V_9 / 1000 ;
V_71 -> V_74 = 0 ;
if ( V_6 -> V_74 == F_23 ( V_71 ) )
V_51 = V_78 ;
F_25 ( V_62 , V_71 ) ;
}
F_8 ( L_3
L_4 ,
( V_51 == V_78 ) ? L_5 : L_6 ,
V_6 -> V_79 . V_80 , V_6 -> V_60 , V_6 -> V_74 , V_6 -> clock ,
V_6 -> V_10 , V_6 -> V_12 ,
V_6 -> V_14 , V_6 -> V_16 ,
V_6 -> V_18 , V_6 -> V_20 ,
V_6 -> V_22 , V_6 -> V_24 , V_6 -> type , V_6 -> V_26 ) ;
return V_51 ;
}
struct V_1 * F_26 ( struct V_61 * V_62 ,
int V_81 , struct V_46 * V_47 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
F_8 ( L_2 , V_47 -> V_60 ) ;
F_27 ( V_47 ) ;
V_3 = F_14 ( sizeof( struct V_3 ) , V_67 ) ;
if ( ! V_3 )
goto V_84;
V_3 -> V_47 = V_47 ;
V_2 = & V_3 -> V_79 ;
F_28 ( V_62 , V_2 , & V_85 ,
V_81 ) ;
F_29 ( V_2 , & V_86 ) ;
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
V_2 -> V_87 = V_88 |
V_89 ;
V_2 -> V_90 = 1 ;
V_2 -> V_91 = 0 ;
F_30 ( V_2 ) ;
return V_2 ;
V_84:
if ( V_2 )
F_7 ( V_2 ) ;
return NULL ;
}
