void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> clock = V_4 -> V_5 ;
V_2 -> V_6 = V_4 -> V_7 ;
V_2 -> V_8 = V_2 -> V_6 + V_4 -> V_9 ;
V_2 -> V_10 = V_2 -> V_8 + V_4 -> V_11 ;
V_2 -> V_12 = V_2 -> V_10 + V_4 -> V_13 ;
V_2 -> V_14 = V_4 -> V_15 ;
V_2 -> V_16 = V_2 -> V_14 + V_4 -> V_17 ;
V_2 -> V_18 = V_2 -> V_16 + V_4 -> V_19 ;
V_2 -> V_20 = V_2 -> V_18 + V_4 -> V_21 ;
V_2 -> V_22 = 0 ;
if ( V_4 -> V_23 )
V_2 -> V_22 |= V_24 ;
if ( V_4 -> V_25 == V_26 )
V_2 -> V_22 |= V_27 ;
else
V_2 -> V_22 |= V_28 ;
if ( V_4 -> V_29 == V_26 )
V_2 -> V_22 |= V_30 ;
else
V_2 -> V_22 |= V_31 ;
}
void F_2 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
V_4 -> V_5 = V_2 -> clock ;
V_4 -> V_7 = V_2 -> V_6 ;
V_4 -> V_9 = V_2 -> V_8 - V_2 -> V_6 ;
V_4 -> V_11 = V_2 -> V_10 - V_2 -> V_8 ;
V_4 -> V_13 = V_2 -> V_12 - V_2 -> V_10 ;
V_4 -> V_15 = V_2 -> V_14 ;
V_4 -> V_17 = V_2 -> V_16 - V_2 -> V_14 ;
V_4 -> V_19 = V_2 -> V_18 - V_2 -> V_16 ;
V_4 -> V_21 = V_2 -> V_20 - V_2 -> V_18 ;
V_4 -> V_23 = ! ! ( V_2 -> V_22 & V_24 ) ;
if ( V_2 -> V_22 & V_27 )
V_4 -> V_25 = V_26 ;
else
V_4 -> V_25 = V_32 ;
if ( V_2 -> V_22 & V_30 )
V_4 -> V_29 = V_26 ;
else
V_4 -> V_29 = V_32 ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 = V_26 ;
V_4 -> V_36 = V_37 ;
}
static enum V_38 F_3 (
struct V_39 * V_40 , bool V_41 )
{
struct V_42 * V_42 = F_4 ( V_40 ) ;
struct V_43 * V_44 = V_42 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
enum V_38 V_48 ;
if ( V_46 -> V_49 ) {
if ( V_46 -> V_49 ( V_44 ) )
V_48 = V_50 ;
else
V_48 = V_51 ;
} else if ( V_44 -> type == V_52 ||
V_44 -> type == V_53 ||
V_44 -> type == V_54 ||
V_44 -> type == V_55 ) {
V_48 = V_50 ;
} else {
V_48 = V_56 ;
}
F_5 ( L_1 , V_42 -> V_44 -> V_57 , V_48 , V_41 ) ;
return V_48 ;
}
static void F_6 ( struct V_39 * V_40 )
{
struct V_42 * V_42 = F_4 ( V_40 ) ;
struct V_43 * V_44 = V_42 -> V_44 ;
F_7 ( L_2 , V_42 -> V_44 -> V_57 ) ;
F_8 ( V_40 ) ;
F_9 ( V_40 ) ;
F_10 ( V_42 ) ;
F_11 ( V_44 ) ;
}
static int F_12 ( struct V_39 * V_40 )
{
struct V_42 * V_42 = F_4 ( V_40 ) ;
struct V_43 * V_44 = V_42 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_58 * V_59 = V_40 -> V_59 ;
int V_60 = 0 ;
F_7 ( L_2 , V_42 -> V_44 -> V_57 ) ;
if ( V_46 -> V_61 ) {
void * V_62 = F_13 ( V_63 , V_64 ) ;
if ( ( V_46 -> V_61 ( V_44 , V_62 , V_63 ) > 0 ) &&
F_14 ( V_62 ) ) {
F_15 (
V_40 , V_62 ) ;
V_60 = F_16 ( V_40 , V_62 ) ;
} else {
F_15 (
V_40 , NULL ) ;
}
F_10 ( V_62 ) ;
} else {
struct V_1 * V_2 = F_17 ( V_59 ) ;
struct V_3 V_4 = { 0 } ;
V_46 -> V_65 ( V_44 , & V_4 ) ;
F_1 ( V_2 , & V_4 ) ;
V_2 -> type = V_66 | V_67 ;
F_18 ( V_2 ) ;
F_19 ( V_40 , V_2 ) ;
V_60 = 1 ;
}
return V_60 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
struct V_42 * V_42 = F_4 ( V_40 ) ;
struct V_43 * V_44 = V_42 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_3 V_4 = { 0 } ;
struct V_58 * V_59 = V_40 -> V_59 ;
struct V_1 * V_68 ;
int V_69 , V_48 = V_70 ;
F_2 ( & V_4 , V_2 ) ;
V_2 -> V_71 = F_21 ( V_2 ) ;
if ( V_46 -> V_72 ) {
V_69 = V_46 -> V_72 ( V_44 , & V_4 ) ;
} else {
struct V_3 V_73 = { 0 } ;
V_46 -> V_65 ( V_44 , & V_73 ) ;
if ( memcmp ( & V_4 , & V_73 , sizeof( struct V_3 ) ) )
V_69 = - V_74 ;
else
V_69 = 0 ;
}
if ( ! V_69 ) {
V_68 = F_22 ( V_59 , V_2 ) ;
V_68 -> clock = V_4 . V_5 ;
V_68 -> V_71 = 0 ;
if ( V_2 -> V_71 == F_21 ( V_68 ) )
V_48 = V_75 ;
F_23 ( V_59 , V_68 ) ;
}
F_7 ( L_3
L_4 ,
( V_48 == V_75 ) ? L_5 : L_6 ,
V_2 -> V_76 . V_77 , V_2 -> V_57 , V_2 -> V_71 , V_2 -> clock ,
V_2 -> V_6 , V_2 -> V_8 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_2 -> V_14 , V_2 -> V_16 ,
V_2 -> V_18 , V_2 -> V_20 , V_2 -> type , V_2 -> V_22 ) ;
return V_48 ;
}
struct V_78 * F_24 (
struct V_39 * V_40 )
{
struct V_42 * V_42 = F_4 ( V_40 ) ;
return V_42 -> V_79 ;
}
void F_25 ( struct V_39 * V_40 ,
int V_80 , int V_81 , int V_82 , int V_83 )
{
struct V_42 * V_42 = F_4 ( V_40 ) ;
F_5 ( L_7 , V_42 -> V_44 -> V_57 , V_80 , V_81 , V_82 , V_83 ) ;
}
struct V_39 * F_26 ( struct V_58 * V_59 ,
int V_84 , struct V_43 * V_44 ,
struct V_78 * V_79 )
{
struct V_39 * V_40 = NULL ;
struct V_42 * V_42 ;
F_7 ( L_2 , V_44 -> V_57 ) ;
F_27 ( V_44 ) ;
V_42 = F_13 ( sizeof( struct V_42 ) , V_64 ) ;
if ( ! V_42 )
goto V_85;
V_42 -> V_44 = V_44 ;
V_42 -> V_79 = V_79 ;
V_40 = & V_42 -> V_76 ;
F_28 ( V_59 , V_40 , & V_86 ,
V_84 ) ;
F_29 ( V_40 , & V_87 ) ;
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
V_40 -> V_88 = V_89 |
V_90 ;
V_40 -> V_91 = 1 ;
V_40 -> V_92 = 0 ;
F_30 ( V_40 ) ;
return V_40 ;
V_85:
if ( V_40 )
F_6 ( V_40 ) ;
return NULL ;
}
