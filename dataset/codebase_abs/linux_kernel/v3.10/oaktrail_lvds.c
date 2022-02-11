static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
bool V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_4 ) {
F_3 ( V_9 , F_4 ( V_9 ) |
V_10 ) ;
do {
V_5 = F_4 ( V_11 ) ;
} while ( ( V_5 & ( V_12 | V_13 ) ) == V_13 );
V_7 -> V_14 = true ;
if ( V_7 -> V_15 -> V_16 )
V_7 -> V_15 -> V_16 ( V_2 , true ) ;
} else {
if ( V_7 -> V_15 -> V_16 )
V_7 -> V_15 -> V_16 ( V_2 , false ) ;
F_3 ( V_9 , F_4 ( V_9 ) &
~ V_10 ) ;
do {
V_5 = F_4 ( V_11 ) ;
} while ( V_5 & V_12 );
V_7 -> V_14 = false ;
F_5 ( & V_2 -> V_17 -> V_2 ) ;
}
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_18 * V_19 , int V_20 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_3 =
F_8 ( V_19 ) ;
if ( V_20 == V_21 )
F_1 ( V_2 , V_3 , true ) ;
else
F_1 ( V_2 , V_3 , false ) ;
}
static void F_9 ( struct V_18 * V_19 ,
struct V_22 * V_20 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_24 * V_25 = & V_7 -> V_25 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_28 * V_29 = NULL ;
struct V_30 * V_31 = V_19 -> V_31 ;
T_1 V_32 ;
T_2 V_33 = V_34 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_32 = ( F_4 ( V_35 ) &
( ~ V_36 ) ) |
V_37 |
V_38 ;
if ( V_25 -> V_39 || V_7 -> V_40 )
V_32 |= V_41 ;
F_3 ( V_35 , V_32 ) ;
F_10 (connector, &mode_config->connector_list, head) {
if ( ! V_29 -> V_19 || V_29 -> V_19 -> V_31 != V_31 )
continue;
}
if ( ! V_29 ) {
F_11 ( L_1 ) ;
return;
}
F_12 (
& V_29 -> V_42 ,
V_2 -> V_27 . V_43 ,
& V_33 ) ;
if ( V_33 == V_44 )
F_3 ( V_45 , 0 ) ;
else if ( V_33 == V_46 ) {
if ( ( V_20 -> V_47 != V_23 -> V_48 ) ||
( V_20 -> V_49 != V_23 -> V_50 ) ) {
if ( ( V_23 -> V_50 * V_20 -> V_47 ) ==
( V_20 -> V_49 * V_23 -> V_48 ) )
F_3 ( V_45 , V_51 ) ;
else if ( ( V_23 -> V_50 *
V_20 -> V_47 ) > ( V_20 -> V_49 *
V_23 -> V_48 ) )
F_3 ( V_45 , V_51 |
V_52 ) ;
else
F_3 ( V_45 , V_51 |
V_53 ) ;
} else
F_3 ( V_45 , V_51 ) ;
} else
F_3 ( V_45 , V_51 ) ;
F_6 ( V_2 ) ;
}
static void F_13 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_3 * V_3 =
F_8 ( V_19 ) ;
struct V_24 * V_25 = & V_7 -> V_25 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_25 -> V_54 = F_4 ( V_55 ) ;
V_25 -> V_56 = ( V_25 -> V_54 &
V_57 ) ;
F_1 ( V_2 , V_3 , false ) ;
F_6 ( V_2 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_58 ;
if ( F_2 ( V_2 , false ) ) {
V_58 = ( ( F_4 ( V_55 ) &
V_59 ) >>
V_60 ) * 2 ;
F_6 ( V_2 ) ;
} else
V_58 = ( ( V_7 -> V_61 . V_54 &
V_59 ) >>
V_60 ) * 2 ;
return V_58 ;
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_3 * V_3 =
F_8 ( V_19 ) ;
struct V_24 * V_25 = & V_7 -> V_25 ;
if ( V_25 -> V_56 == 0 )
V_25 -> V_56 =
F_14 ( V_2 ) ;
F_1 ( V_2 , V_3 , true ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_22 * V_20 = NULL ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_62 * V_63 = & V_7 -> V_64 . V_65 ;
V_25 -> V_66 = NULL ;
if ( V_7 -> V_67 ) {
V_20 = F_17 ( sizeof( * V_20 ) , V_68 ) ;
if ( ! V_20 )
return;
V_20 -> V_49 = ( V_63 -> V_69 << 8 ) | V_63 -> V_70 ;
V_20 -> V_47 = ( V_63 -> V_71 << 8 ) | V_63 -> V_72 ;
V_20 -> V_73 = V_20 -> V_49 + \
( ( V_63 -> V_74 << 8 ) | \
V_63 -> V_75 ) ;
V_20 -> V_76 = V_20 -> V_73 + \
( ( V_63 -> V_77 << 8 ) | \
V_63 -> V_78 ) ;
V_20 -> V_79 = V_20 -> V_49 + ( ( V_63 -> V_80 << 8 ) | \
V_63 -> V_81 ) ;
V_20 -> V_82 = \
V_20 -> V_47 + ( ( V_63 -> V_83 << 4 ) | \
V_63 -> V_84 ) ;
V_20 -> V_85 = \
V_20 -> V_82 + ( ( V_63 -> V_86 << 4 ) | \
V_63 -> V_87 ) ;
V_20 -> V_88 = V_20 -> V_47 + \
( ( V_63 -> V_89 << 8 ) | V_63 -> V_90 ) ;
V_20 -> clock = V_63 -> V_91 * 10 ;
#if 0
printk(KERN_INFO "hdisplay is %d\n", mode->hdisplay);
printk(KERN_INFO "vdisplay is %d\n", mode->vdisplay);
printk(KERN_INFO "HSS is %d\n", mode->hsync_start);
printk(KERN_INFO "HSE is %d\n", mode->hsync_end);
printk(KERN_INFO "htotal is %d\n", mode->htotal);
printk(KERN_INFO "VSS is %d\n", mode->vsync_start);
printk(KERN_INFO "VSE is %d\n", mode->vsync_end);
printk(KERN_INFO "vtotal is %d\n", mode->vtotal);
printk(KERN_INFO "clock is %d\n", mode->clock);
#endif
V_25 -> V_66 = V_20 ;
}
if ( V_25 -> V_66 == NULL && V_25 -> V_92 )
V_25 -> V_66 = F_18 ( V_2 ,
V_25 -> V_92 ) ;
if ( V_25 -> V_66 == NULL )
if ( V_7 -> V_93 )
V_25 -> V_66 =
F_18 ( V_2 ,
V_7 -> V_93 ) ;
if ( V_25 -> V_66 == NULL )
V_25 -> V_66
= F_18 ( V_2 , & V_94 [ 2 ] ) ;
F_19 ( V_25 -> V_66 ) ;
F_20 ( V_25 -> V_66 , 0 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_3 ;
struct V_95 * V_95 ;
struct V_28 * V_29 ;
struct V_18 * V_19 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_96 * V_96 ;
struct V_97 * V_98 ;
struct V_22 * V_99 ;
V_3 = F_17 ( sizeof( struct V_3 ) , V_68 ) ;
if ( ! V_3 )
return;
V_95 = F_17 ( sizeof( struct V_95 ) , V_68 ) ;
if ( ! V_95 )
goto V_100;
V_29 = & V_95 -> V_42 ;
V_19 = & V_3 -> V_42 ;
V_7 -> V_14 = true ;
F_22 ( V_2 , V_29 ,
& V_101 ,
V_102 ) ;
F_23 ( V_2 , V_19 , & V_103 ,
V_104 ) ;
F_24 ( V_95 ,
V_3 ) ;
V_3 -> type = V_105 ;
F_25 ( V_19 , & V_106 ) ;
F_26 ( V_29 ,
& V_107 ) ;
V_29 -> V_108 . V_109 = V_110 ;
V_29 -> V_111 = false ;
V_29 -> V_112 = false ;
F_27 ( & V_29 -> V_42 ,
V_2 -> V_27 . V_43 ,
V_34 ) ;
F_27 ( & V_29 -> V_42 ,
V_7 -> V_113 ,
V_114 ) ;
V_25 -> V_39 = false ;
if ( V_7 -> V_67 )
V_25 -> V_39 = ( V_7 -> V_64 .
V_115 & V_41 ) ;
if ( V_7 -> V_40 )
V_25 -> V_39 = 1 ;
V_98 = F_28 ( V_7 -> V_15 -> V_116 ) ;
if ( V_98 == NULL )
F_29 ( V_2 -> V_2 , L_2 ) ;
if ( V_98 ) {
V_96 = F_30 ( V_29 , V_98 ) ;
if ( V_96 ) {
F_31 ( V_29 ,
V_96 ) ;
F_32 ( V_29 , V_96 ) ;
F_33 ( V_96 ) ;
}
F_10 (scan, &connector->probed_modes, head) {
if ( V_99 -> type & V_117 ) {
V_25 -> V_66 =
F_18 ( V_2 , V_99 ) ;
goto V_118;
}
}
}
F_16 ( V_2 , V_25 ) ;
if ( V_25 -> V_66 ) {
V_25 -> V_66 -> type |= V_117 ;
goto V_118;
}
if ( ! V_25 -> V_66 ) {
F_29 ( V_2 -> V_2 , L_3 ) ;
goto V_119;
}
V_118:
F_34 ( V_29 ) ;
return;
V_119:
F_35 ( V_2 -> V_2 , L_4 ) ;
if ( V_3 -> V_120 )
F_36 ( V_3 -> V_120 ) ;
F_37 ( V_19 ) ;
F_38 ( V_29 ) ;
F_33 ( V_95 ) ;
V_100:
F_33 ( V_3 ) ;
}
