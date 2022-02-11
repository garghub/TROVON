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
if ( V_8 -> V_29 == V_30 )
V_6 -> V_26 |= V_31 ;
else
V_6 -> V_26 |= V_32 ;
if ( V_8 -> V_33 == V_30 )
V_6 -> V_26 |= V_34 ;
else
V_6 -> V_26 |= V_35 ;
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
if ( V_6 -> V_26 & V_31 )
V_8 -> V_29 = V_30 ;
else
V_8 -> V_29 = V_36 ;
if ( V_6 -> V_26 & V_34 )
V_8 -> V_33 = V_30 ;
else
V_8 -> V_33 = V_36 ;
V_8 -> V_37 = V_38 ;
V_8 -> V_39 = V_30 ;
V_8 -> V_40 = V_41 ;
}
static enum V_42 F_5 (
struct V_1 * V_2 , bool V_43 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_44 * V_45 = V_3 -> V_45 ;
struct V_46 * V_47 = V_45 -> V_48 ;
enum V_42 V_49 ;
if ( V_47 -> V_50 ) {
if ( V_47 -> V_50 ( V_45 ) )
V_49 = V_51 ;
else
V_49 = V_52 ;
} else if ( V_45 -> type == V_53 ||
V_45 -> type == V_54 ||
V_45 -> type == V_55 ||
V_45 -> type == V_56 ) {
V_49 = V_51 ;
} else {
V_49 = V_57 ;
}
F_6 ( L_1 , V_3 -> V_45 -> V_58 , V_49 , V_43 ) ;
return V_49 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_44 * V_45 = V_3 -> V_45 ;
F_8 ( L_2 , V_3 -> V_45 -> V_58 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
F_11 ( V_3 ) ;
F_12 ( V_45 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_44 * V_45 = V_3 -> V_45 ;
struct V_46 * V_47 = V_45 -> V_48 ;
struct V_59 * V_60 = V_2 -> V_60 ;
int V_61 = 0 ;
F_8 ( L_2 , V_3 -> V_45 -> V_58 ) ;
if ( V_47 -> V_62 ) {
void * V_63 = F_14 ( V_64 , V_65 ) ;
if ( ( V_47 -> V_62 ( V_45 , V_63 , V_64 ) > 0 ) &&
F_15 ( V_63 ) ) {
F_16 (
V_2 , V_63 ) ;
V_61 = F_17 ( V_2 , V_63 ) ;
V_3 -> V_4 =
F_18 ( V_63 ) ;
} else {
F_16 (
V_2 , NULL ) ;
}
F_11 ( V_63 ) ;
} else {
struct V_5 * V_6 = F_19 ( V_60 ) ;
struct V_7 V_8 = { 0 } ;
V_47 -> V_66 ( V_45 , & V_8 ) ;
F_3 ( V_6 , & V_8 ) ;
V_6 -> type = V_67 | V_68 ;
F_20 ( V_6 ) ;
F_21 ( V_2 , V_6 ) ;
V_61 = 1 ;
}
return V_61 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_44 * V_45 = V_3 -> V_45 ;
struct V_46 * V_47 = V_45 -> V_48 ;
struct V_7 V_8 = { 0 } ;
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_5 * V_69 ;
int V_70 , V_49 = V_71 ;
F_4 ( & V_8 , V_6 ) ;
V_6 -> V_72 = F_23 ( V_6 ) ;
if ( V_47 -> V_73 ) {
V_70 = V_47 -> V_73 ( V_45 , & V_8 ) ;
} else {
struct V_7 V_74 = { 0 } ;
V_47 -> V_66 ( V_45 , & V_74 ) ;
if ( memcmp ( & V_8 , & V_74 , sizeof( struct V_7 ) ) )
V_70 = - V_75 ;
else
V_70 = 0 ;
}
if ( ! V_70 ) {
V_69 = F_24 ( V_60 , V_6 ) ;
V_69 -> clock = V_8 . V_9 / 1000 ;
V_69 -> V_72 = 0 ;
if ( V_6 -> V_72 == F_23 ( V_69 ) )
V_49 = V_76 ;
F_25 ( V_60 , V_69 ) ;
}
F_8 ( L_3
L_4 ,
( V_49 == V_76 ) ? L_5 : L_6 ,
V_6 -> V_77 . V_78 , V_6 -> V_58 , V_6 -> V_72 , V_6 -> clock ,
V_6 -> V_10 , V_6 -> V_12 ,
V_6 -> V_14 , V_6 -> V_16 ,
V_6 -> V_18 , V_6 -> V_20 ,
V_6 -> V_22 , V_6 -> V_24 , V_6 -> type , V_6 -> V_26 ) ;
return V_49 ;
}
struct V_79 * F_26 (
struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_80 ;
}
struct V_1 * F_27 ( struct V_59 * V_60 ,
int V_81 , struct V_44 * V_45 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
F_8 ( L_2 , V_45 -> V_58 ) ;
F_28 ( V_45 ) ;
V_3 = F_14 ( sizeof( struct V_3 ) , V_65 ) ;
if ( ! V_3 )
goto V_82;
V_3 -> V_45 = V_45 ;
V_3 -> V_80 = V_80 ;
V_2 = & V_3 -> V_77 ;
F_29 ( V_60 , V_2 , & V_83 ,
V_81 ) ;
F_30 ( V_2 , & V_84 ) ;
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
V_2 -> V_85 = V_86 |
V_87 ;
V_2 -> V_88 = 1 ;
V_2 -> V_89 = 0 ;
F_31 ( V_2 ) ;
return V_2 ;
V_82:
if ( V_2 )
F_7 ( V_2 ) ;
return NULL ;
}
