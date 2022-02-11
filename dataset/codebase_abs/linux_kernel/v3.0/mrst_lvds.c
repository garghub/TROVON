static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
T_1 V_6 ;
T_2 * V_7 = V_2 -> V_8 ;
F_2 ( L_1 ) ;
if ( ! F_3 ( V_2 , true ) )
return;
if ( V_5 ) {
F_4 ( V_9 , F_5 ( V_9 ) |
V_10 ) ;
do {
V_6 = F_5 ( V_11 ) ;
} while ( ( V_6 & ( V_12 | V_13 ) ) == V_13 );
V_7 -> V_14 = true ;
} else {
F_4 ( V_9 , F_5 ( V_9 ) &
~ V_10 ) ;
do {
V_6 = F_5 ( V_11 ) ;
} while ( V_6 & V_12 );
V_7 -> V_14 = false ;
F_6 ( & V_2 -> V_15 -> V_2 ) ;
}
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_16 * V_17 , int V_18 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_3 * V_4 = F_9 ( V_17 ) ;
F_2 ( L_1 ) ;
if ( V_18 == V_19 )
F_1 ( V_2 , V_4 , true ) ;
else
F_1 ( V_2 , V_4 , false ) ;
}
static void F_10 ( struct V_16 * V_17 ,
struct V_20 * V_18 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 =
F_9 ( V_17 ) -> V_23 ;
struct V_1 * V_2 = V_17 -> V_2 ;
T_1 V_24 ;
T_3 V_25 = V_26 ;
F_2 ( L_1 ) ;
if ( ! F_3 ( V_2 , true ) )
return;
V_24 = ( F_5 ( V_27 ) &
( ~ V_28 ) ) |
V_29 |
V_30 ;
if ( V_23 -> V_31 )
V_24 |= V_32 ;
F_4 ( V_27 , V_24 ) ;
F_11 (
& F_9 ( V_17 ) -> V_33 ,
V_2 -> V_34 . V_35 ,
& V_25 ) ;
if ( V_25 == V_36 )
F_4 ( V_37 , 0 ) ;
else if ( V_25 == V_38 ) {
if ( ( V_18 -> V_39 != V_21 -> V_40 ) ||
( V_18 -> V_41 != V_21 -> V_42 ) ) {
if ( ( V_21 -> V_42 * V_18 -> V_39 ) ==
( V_18 -> V_41 * V_21 -> V_40 ) )
F_4 ( V_37 , V_43 ) ;
else if ( ( V_21 -> V_42 *
V_18 -> V_39 ) > ( V_18 -> V_41 *
V_21 -> V_40 ) )
F_4 ( V_37 , V_43 |
V_44 ) ;
else
F_4 ( V_37 , V_43 |
V_45 ) ;
} else
F_4 ( V_37 , V_43 ) ;
} else
F_4 ( V_37 , V_43 ) ;
F_7 ( V_2 ) ;
}
static struct V_20 *
F_12 ( struct V_1 * V_2 )
{
struct V_20 * V_18 = NULL ;
struct V_46 * V_7 = V_2 -> V_8 ;
struct V_47 * V_48 = & V_7 -> V_49 . V_50 ;
if ( V_7 -> V_51 . V_52 != 0x00 ) {
V_18 = F_13 ( sizeof( * V_18 ) , V_53 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_41 = ( V_48 -> V_54 << 8 ) | V_48 -> V_55 ;
V_18 -> V_39 = ( V_48 -> V_56 << 8 ) | V_48 -> V_57 ;
V_18 -> V_58 = V_18 -> V_41 + \
( ( V_48 -> V_59 << 8 ) | \
V_48 -> V_60 ) ;
V_18 -> V_61 = V_18 -> V_58 + \
( ( V_48 -> V_62 << 8 ) | \
V_48 -> V_63 ) ;
V_18 -> V_64 = V_18 -> V_41 + ( ( V_48 -> V_65 << 8 ) | \
V_48 -> V_66 ) ;
V_18 -> V_67 = \
V_18 -> V_39 + ( ( V_48 -> V_68 << 4 ) | \
V_48 -> V_69 ) ;
V_18 -> V_70 = \
V_18 -> V_67 + ( ( V_48 -> V_71 << 4 ) | \
V_48 -> V_72 ) ;
V_18 -> V_73 = V_18 -> V_39 + \
( ( V_48 -> V_74 << 8 ) | V_48 -> V_75 ) ;
V_18 -> clock = V_48 -> V_76 * 10 ;
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
V_18 = F_14 ( V_2 , & V_77 [ 2 ] ) ;
F_15 ( V_18 ) ;
F_16 ( V_18 , 0 ) ;
return V_18 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_3 * V_3 ;
struct V_78 * V_79 ;
struct V_16 * V_17 ;
struct V_46 * V_7 =
(struct V_46 * ) V_2 -> V_8 ;
struct V_80 * V_80 ;
int V_81 = 0 ;
struct V_82 * V_83 ;
struct V_20 * V_84 ;
F_2 ( L_1 ) ;
V_3 = F_13 ( sizeof( struct V_3 ) , V_53 ) ;
if ( ! V_3 )
return;
V_3 -> V_23 = V_23 ;
V_79 = & V_3 -> V_33 ;
V_17 = & V_3 -> V_85 ;
V_7 -> V_14 = true ;
F_18 ( V_2 , & V_3 -> V_33 ,
& V_86 ,
V_87 ) ;
F_19 ( V_2 , & V_3 -> V_85 , & V_88 ,
V_89 ) ;
F_20 ( & V_3 -> V_33 ,
& V_3 -> V_85 ) ;
V_3 -> type = V_90 ;
F_21 ( V_17 , & V_91 ) ;
F_22 ( V_79 ,
& V_92 ) ;
V_79 -> V_93 . V_94 = V_95 ;
V_79 -> V_96 = false ;
V_79 -> V_97 = false ;
F_23 ( V_79 ,
V_2 -> V_34 . V_35 ,
V_26 ) ;
F_23 ( V_79 ,
V_7 -> V_98 ,
V_99 ) ;
V_23 -> V_31 = false ;
if ( V_7 -> V_51 . V_52 != 0x00 )
V_23 -> V_31 = ( V_7 -> V_49 .
V_100 & V_32 ) ;
#if F_24 ( V_101 )
if ( F_25 () )
V_83 = F_26 ( 2 ) ;
else
#endif
V_83 = F_26 ( 1 ) ;
if ( V_83 == NULL )
F_27 ( V_102 L_2 ) ;
if ( V_83 ) {
V_80 = F_28 ( V_79 , V_83 ) ;
if ( V_80 ) {
F_29 ( V_79 ,
V_80 ) ;
V_81 = F_30 ( V_79 , V_80 ) ;
F_31 ( V_80 ) ;
}
F_32 (scan, &connector->probed_modes, head) {
if ( V_84 -> type & V_103 ) {
V_23 -> V_104 =
F_14 ( V_2 , V_84 ) ;
goto V_105;
}
}
}
V_23 -> V_104 = F_12 ( V_2 ) ;
if ( V_23 -> V_104 ) {
V_23 -> V_104 -> type |=
V_103 ;
goto V_105;
}
if ( ! V_23 -> V_104 ) {
F_33
( L_3 ) ;
goto V_106;
}
V_105:
F_34 ( V_79 ) ;
return;
V_106:
F_33 ( L_4 ) ;
if ( V_3 -> V_107 )
F_35 ( V_3 -> V_107 ) ;
F_36 ( V_17 ) ;
F_37 ( V_79 ) ;
F_31 ( V_79 ) ;
}
