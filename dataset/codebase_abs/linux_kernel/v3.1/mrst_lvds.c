static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
T_1 V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
if ( ! F_2 ( V_2 , true ) )
return;
if ( V_5 ) {
F_3 ( V_10 , F_4 ( V_10 ) |
V_11 ) ;
do {
V_6 = F_4 ( V_12 ) ;
} while ( ( V_6 & ( V_13 | V_14 ) ) == V_14 );
V_8 -> V_15 = true ;
if ( V_8 -> V_16 -> V_17 )
V_8 -> V_16 -> V_17 ( V_2 , true ) ;
} else {
if ( V_8 -> V_16 -> V_17 )
V_8 -> V_16 -> V_17 ( V_2 , false ) ;
F_3 ( V_10 , F_4 ( V_10 ) &
~ V_11 ) ;
do {
V_6 = F_4 ( V_12 ) ;
} while ( V_6 & V_13 );
V_8 -> V_15 = false ;
F_5 ( & V_2 -> V_18 -> V_2 ) ;
}
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_19 * V_20 , int V_21 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = F_8 ( V_20 ) ;
if ( V_21 == V_22 )
F_1 ( V_2 , V_4 , true ) ;
else
F_1 ( V_2 , V_4 , false ) ;
}
static void F_9 ( struct V_19 * V_20 ,
struct V_23 * V_21 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 =
F_8 ( V_20 ) -> V_26 ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_27 ;
T_2 V_28 = V_29 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_27 = ( F_4 ( V_30 ) &
( ~ V_31 ) ) |
V_32 |
V_33 ;
if ( V_26 -> V_34 || V_8 -> V_35 )
V_27 |= V_36 ;
F_3 ( V_30 , V_27 ) ;
F_10 (
& F_8 ( V_20 ) -> V_37 ,
V_2 -> V_38 . V_39 ,
& V_28 ) ;
if ( V_28 == V_40 )
F_3 ( V_41 , 0 ) ;
else if ( V_28 == V_42 ) {
if ( ( V_21 -> V_43 != V_24 -> V_44 ) ||
( V_21 -> V_45 != V_24 -> V_46 ) ) {
if ( ( V_24 -> V_46 * V_21 -> V_43 ) ==
( V_21 -> V_45 * V_24 -> V_44 ) )
F_3 ( V_41 , V_47 ) ;
else if ( ( V_24 -> V_46 *
V_21 -> V_43 ) > ( V_21 -> V_45 *
V_24 -> V_44 ) )
F_3 ( V_41 , V_47 |
V_48 ) ;
else
F_3 ( V_41 , V_47 |
V_49 ) ;
} else
F_3 ( V_41 , V_47 ) ;
} else
F_3 ( V_41 , V_47 ) ;
F_6 ( V_2 ) ;
}
static void F_11 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = F_8 ( V_20 ) ;
struct V_25 * V_26 = V_4 -> V_26 ;
if ( ! F_2 ( V_2 , true ) )
return;
V_26 -> V_50 = F_4 ( V_51 ) ;
V_26 -> V_52 = ( V_26 -> V_50 &
V_53 ) ;
F_1 ( V_2 , V_4 , false ) ;
F_6 ( V_2 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_54 ;
if ( F_2 ( V_2 , false ) ) {
V_54 = ( ( F_4 ( V_51 ) &
V_55 ) >>
V_56 ) * 2 ;
F_6 ( V_2 ) ;
} else
V_54 = ( ( V_8 -> V_50 &
V_55 ) >>
V_56 ) * 2 ;
return V_54 ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_3 * V_4 = F_8 ( V_20 ) ;
struct V_25 * V_26 = V_4 -> V_26 ;
if ( V_26 -> V_52 == 0 )
V_26 -> V_52 =
F_12 ( V_2 ) ;
F_1 ( V_2 , V_4 , true ) ;
}
static struct V_23 *
F_14 ( struct V_1 * V_2 )
{
struct V_23 * V_21 = NULL ;
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_57 * V_58 = & V_8 -> V_59 . V_60 ;
if ( V_8 -> V_61 . V_62 != 0x00 ) {
V_21 = F_15 ( sizeof( * V_21 ) , V_63 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_45 = ( V_58 -> V_64 << 8 ) | V_58 -> V_65 ;
V_21 -> V_43 = ( V_58 -> V_66 << 8 ) | V_58 -> V_67 ;
V_21 -> V_68 = V_21 -> V_45 + \
( ( V_58 -> V_69 << 8 ) | \
V_58 -> V_70 ) ;
V_21 -> V_71 = V_21 -> V_68 + \
( ( V_58 -> V_72 << 8 ) | \
V_58 -> V_73 ) ;
V_21 -> V_74 = V_21 -> V_45 + ( ( V_58 -> V_75 << 8 ) | \
V_58 -> V_76 ) ;
V_21 -> V_77 = \
V_21 -> V_43 + ( ( V_58 -> V_78 << 4 ) | \
V_58 -> V_79 ) ;
V_21 -> V_80 = \
V_21 -> V_77 + ( ( V_58 -> V_81 << 4 ) | \
V_58 -> V_82 ) ;
V_21 -> V_83 = V_21 -> V_43 + \
( ( V_58 -> V_84 << 8 ) | V_58 -> V_85 ) ;
V_21 -> clock = V_58 -> V_86 * 10 ;
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
} else
V_21 = F_16 ( V_2 , & V_87 [ 2 ] ) ;
F_17 ( V_21 ) ;
F_18 ( V_21 , 0 ) ;
return V_21 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_3 ;
struct V_88 * V_89 ;
struct V_19 * V_20 ;
struct V_7 * V_8 =
(struct V_7 * ) V_2 -> V_9 ;
struct V_90 * V_90 ;
int V_54 = 0 ;
struct V_91 * V_92 ;
struct V_23 * V_93 ;
V_3 = F_15 ( sizeof( struct V_3 ) , V_63 ) ;
if ( ! V_3 )
return;
V_3 -> V_26 = V_26 ;
V_89 = & V_3 -> V_37 ;
V_20 = & V_3 -> V_94 ;
V_8 -> V_15 = true ;
F_20 ( V_2 , & V_3 -> V_37 ,
& V_95 ,
V_96 ) ;
F_21 ( V_2 , & V_3 -> V_94 , & V_97 ,
V_98 ) ;
F_22 ( & V_3 -> V_37 ,
& V_3 -> V_94 ) ;
V_3 -> type = V_99 ;
F_23 ( V_20 , & V_100 ) ;
F_24 ( V_89 ,
& V_101 ) ;
V_89 -> V_102 . V_103 = V_104 ;
V_89 -> V_105 = false ;
V_89 -> V_106 = false ;
F_25 ( V_89 ,
V_2 -> V_38 . V_39 ,
V_29 ) ;
F_25 ( V_89 ,
V_8 -> V_107 ,
V_108 ) ;
V_26 -> V_34 = false ;
if ( V_8 -> V_61 . V_62 != 0x00 )
V_26 -> V_34 = ( V_8 -> V_59 .
V_109 & V_36 ) ;
V_92 = F_26 ( V_8 -> V_16 -> V_110 ) ;
if ( V_92 == NULL )
F_27 ( V_2 -> V_2 , L_1 ) ;
if ( V_92 ) {
V_90 = F_28 ( V_89 , V_92 ) ;
if ( V_90 ) {
F_29 ( V_89 ,
V_90 ) ;
V_54 = F_30 ( V_89 , V_90 ) ;
F_31 ( V_90 ) ;
}
F_32 (scan, &connector->probed_modes, head) {
if ( V_93 -> type & V_111 ) {
V_26 -> V_112 =
F_16 ( V_2 , V_93 ) ;
goto V_113;
}
}
}
V_26 -> V_112 = F_14 ( V_2 ) ;
if ( V_26 -> V_112 ) {
V_26 -> V_112 -> type |= V_111 ;
goto V_113;
}
if ( ! V_26 -> V_112 ) {
F_27 ( V_2 -> V_2 , L_2 ) ;
goto V_114;
}
V_113:
F_33 ( V_89 ) ;
return;
V_114:
F_34 ( V_2 -> V_2 , L_3 ) ;
if ( V_3 -> V_115 )
F_35 ( V_3 -> V_115 ) ;
F_36 ( V_20 ) ;
F_37 ( V_89 ) ;
F_31 ( V_89 ) ;
}
