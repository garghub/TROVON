bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
static enum V_5 F_3 (
struct V_1 * V_2 , bool V_6 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
enum V_5 V_12 ;
if ( V_10 -> V_13 ) {
if ( V_10 -> V_13 ( V_8 ) )
V_12 = V_14 ;
else
V_12 = V_15 ;
} else if ( V_8 -> type == V_16 ||
V_8 -> type == V_17 ||
V_8 -> type == V_18 ||
V_8 -> type == V_19 ) {
V_12 = V_14 ;
} else {
V_12 = V_20 ;
}
F_4 ( L_1 , V_3 -> V_8 -> V_21 , V_12 , V_6 ) ;
return V_12 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
F_6 ( L_2 , V_3 -> V_8 -> V_21 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_3 ) ;
F_10 ( V_8 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_24 = 0 ;
F_6 ( L_2 , V_3 -> V_8 -> V_21 ) ;
if ( V_10 -> V_25 ) {
void * V_26 = F_12 ( V_27 , V_28 ) ;
if ( ( V_10 -> V_25 ( V_8 , V_26 , V_27 ) > 0 ) &&
F_13 ( V_26 ) ) {
F_14 (
V_2 , V_26 ) ;
V_24 = F_15 ( V_2 , V_26 ) ;
V_3 -> V_4 =
F_16 ( V_26 ) ;
} else {
F_14 (
V_2 , NULL ) ;
}
F_9 ( V_26 ) ;
} else {
struct V_29 * V_30 = F_17 ( V_23 ) ;
struct V_31 V_32 = { 0 } ;
V_10 -> V_33 ( V_8 , & V_32 ) ;
F_18 ( & V_32 , V_30 ) ;
V_30 -> type = V_34 | V_35 ;
F_19 ( V_30 ) ;
F_20 ( V_2 , V_30 ) ;
V_24 = 1 ;
}
return V_24 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_31 V_32 = { 0 } ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_29 * V_36 ;
int V_37 , V_12 = V_38 ;
F_22 ( V_30 , & V_32 ) ;
V_32 . V_39 |= V_40 | V_41 |
V_42 ;
V_30 -> V_43 = F_23 ( V_30 ) ;
if ( V_10 -> V_44 ) {
V_37 = V_10 -> V_44 ( V_8 , & V_32 ) ;
} else {
struct V_31 V_45 = { 0 } ;
V_10 -> V_33 ( V_8 , & V_45 ) ;
if ( memcmp ( & V_32 , & V_45 , sizeof( V_32 ) ) )
V_37 = - V_46 ;
else
V_37 = 0 ;
}
if ( ! V_37 ) {
V_36 = F_24 ( V_23 , V_30 ) ;
V_36 -> clock = V_32 . V_47 / 1000 ;
V_36 -> V_43 = 0 ;
if ( V_30 -> V_43 == F_23 ( V_36 ) )
V_12 = V_48 ;
F_25 ( V_23 , V_36 ) ;
}
F_6 ( L_3
L_4 ,
( V_12 == V_48 ) ? L_5 : L_6 ,
V_30 -> V_49 . V_50 , V_30 -> V_21 , V_30 -> V_43 , V_30 -> clock ,
V_30 -> V_51 , V_30 -> V_52 ,
V_30 -> V_53 , V_30 -> V_54 ,
V_30 -> V_55 , V_30 -> V_56 ,
V_30 -> V_57 , V_30 -> V_58 , V_30 -> type , V_30 -> V_39 ) ;
return V_12 ;
}
struct V_1 * F_26 ( struct V_22 * V_23 ,
int V_59 , struct V_7 * V_8 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
F_6 ( L_2 , V_8 -> V_21 ) ;
F_27 ( V_8 ) ;
V_3 = F_12 ( sizeof( * V_3 ) , V_28 ) ;
if ( ! V_3 )
goto V_62;
V_3 -> V_8 = V_8 ;
V_2 = & V_3 -> V_49 ;
F_28 ( V_23 , V_2 , & V_63 ,
V_59 ) ;
F_29 ( V_2 , & V_64 ) ;
#if 0
if (dssdev->caps & OMAP_DSS_DISPLAY_CAP_HPD)
connector->polled = 0;
else
#endif
V_2 -> V_65 = V_66 |
V_67 ;
V_2 -> V_68 = 1 ;
V_2 -> V_69 = 0 ;
return V_2 ;
V_62:
if ( V_2 )
F_5 ( V_2 ) ;
return NULL ;
}
