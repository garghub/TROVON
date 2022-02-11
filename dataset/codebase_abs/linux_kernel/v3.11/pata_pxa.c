static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
T_1 V_9 , V_10 ;
T_2 V_11 ;
V_11 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_2 ) ;
do {
V_10 = ( V_9 > 0x1000 ) ? 0x1000 : V_9 ;
V_6 -> V_12 [ V_6 -> V_13 ] . V_14 = V_6 -> V_15 +
( ( V_6 -> V_13 + 1 ) * sizeof( struct V_16 ) ) ;
V_6 -> V_12 [ V_6 -> V_13 ] . V_17 = V_18 |
V_19 | ( V_20 & V_10 ) ;
if ( V_4 -> V_21 . V_22 & V_23 ) {
V_6 -> V_12 [ V_6 -> V_13 ] . V_24 = V_11 ;
V_6 -> V_12 [ V_6 -> V_13 ] . V_25 = V_6 -> V_26 ;
V_6 -> V_12 [ V_6 -> V_13 ] . V_17 |= V_27 |
V_28 ;
} else {
V_6 -> V_12 [ V_6 -> V_13 ] . V_24 = V_6 -> V_26 ;
V_6 -> V_12 [ V_6 -> V_13 ] . V_25 = V_11 ;
V_6 -> V_12 [ V_6 -> V_13 ] . V_17 |= V_29 |
V_30 ;
}
V_9 -= V_10 ;
V_11 += V_10 ;
V_6 -> V_13 ++ ;
} while ( V_9 );
if ( V_10 & 0x1f )
V_31 |= ( 1 << V_6 -> V_32 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
int V_33 = 0 ;
struct V_1 * V_2 ;
if ( ! ( V_4 -> V_22 & V_34 ) )
return;
V_6 -> V_13 = 0 ;
F_5 ( V_6 -> V_35 ) = 0 ;
V_31 &= ~ ( 1 << V_6 -> V_32 ) ;
F_6 (qc->sg, sg, qc->n_elem, si)
F_1 ( V_2 , V_4 ) ;
V_6 -> V_12 [ V_6 -> V_13 - 1 ] . V_14 = V_36 ;
V_6 -> V_12 [ V_6 -> V_13 - 1 ] . V_17 |= V_37 ;
F_7 ( V_6 -> V_35 ) = V_6 -> V_15 ;
F_8 ( V_6 -> V_32 ) = V_38 | V_6 -> V_35 ;
}
static void F_9 ( struct V_3 * V_4 )
{
V_4 -> V_7 -> V_39 -> V_40 ( V_4 -> V_7 , & V_4 -> V_21 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
F_11 ( & V_6 -> V_41 ) ;
F_5 ( V_6 -> V_35 ) = V_42 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 -> V_8 ;
if ( ( F_5 ( V_6 -> V_35 ) & V_42 ) &&
F_13 ( & V_6 -> V_41 , V_43 ) )
F_14 ( V_4 -> V_7 -> V_44 , L_1 ) ;
F_5 ( V_6 -> V_35 ) = 0 ;
}
static unsigned char F_15 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
unsigned char V_46 = V_47 ;
if ( V_6 -> V_48 & V_49 )
V_46 |= V_50 ;
return V_46 ;
}
static void F_16 ( struct V_45 * V_7 )
{
}
static int F_17 ( struct V_3 * V_4 )
{
return - V_51 ;
}
static void F_18 ( int V_52 , void * V_53 )
{
struct V_45 * V_7 = V_53 ;
struct V_5 * V_6 = V_7 -> V_8 ;
V_6 -> V_48 = F_5 ( V_52 ) ;
F_5 ( V_52 ) = V_6 -> V_48 ;
if ( V_6 -> V_48 & V_54 )
F_19 ( & V_6 -> V_41 ) ;
}
static int F_20 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_45 * V_7 ;
struct V_5 * V_59 ;
struct V_60 * V_61 ;
struct V_60 * V_62 ;
struct V_60 * V_63 ;
struct V_60 * V_64 ;
struct V_65 * V_66 = V_56 -> V_44 . V_67 ;
int V_46 = 0 ;
if ( V_56 -> V_68 != 4 ) {
F_14 ( & V_56 -> V_44 , L_2 ) ;
return - V_69 ;
}
V_61 = F_21 ( V_56 , V_70 , 0 ) ;
if ( F_22 ( V_61 == NULL ) )
return - V_69 ;
V_62 = F_21 ( V_56 , V_70 , 1 ) ;
if ( F_22 ( V_62 == NULL ) )
return - V_69 ;
V_63 = F_21 ( V_56 , V_71 , 0 ) ;
if ( F_22 ( V_63 == NULL ) )
return - V_69 ;
V_64 = F_21 ( V_56 , V_72 , 0 ) ;
if ( F_22 ( V_64 == NULL ) )
return - V_69 ;
V_58 = F_23 ( & V_56 -> V_44 , 1 ) ;
if ( ! V_58 )
return - V_73 ;
V_7 = V_58 -> V_74 [ 0 ] ;
V_7 -> V_39 = & V_75 ;
V_7 -> V_76 = V_77 ;
V_7 -> V_78 = V_79 ;
V_7 -> V_80 . V_81 = F_24 ( & V_56 -> V_44 , V_61 -> V_82 ,
F_25 ( V_61 ) ) ;
V_7 -> V_80 . V_83 = F_24 ( & V_56 -> V_44 , V_62 -> V_82 ,
F_25 ( V_62 ) ) ;
V_7 -> V_80 . V_84 = F_24 ( & V_56 -> V_44 , V_63 -> V_82 ,
F_25 ( V_63 ) ) ;
V_7 -> V_80 . V_85 = V_7 -> V_80 . V_83 ;
V_7 -> V_80 . V_86 = V_7 -> V_80 . V_81 +
( V_87 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_89 = V_7 -> V_80 . V_81 +
( V_90 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_91 = V_7 -> V_80 . V_81 +
( V_92 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_93 = V_7 -> V_80 . V_81 +
( V_94 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_95 = V_7 -> V_80 . V_81 +
( V_96 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_97 = V_7 -> V_80 . V_81 +
( V_98 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_99 = V_7 -> V_80 . V_81 +
( V_100 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_101 = V_7 -> V_80 . V_81 +
( V_102 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_103 = V_7 -> V_80 . V_81 +
( V_104 << V_66 -> V_88 ) ;
V_7 -> V_80 . V_105 = V_7 -> V_80 . V_81 +
( V_106 << V_66 -> V_88 ) ;
V_59 = F_26 ( & V_56 -> V_44 , sizeof( struct V_5 ) ,
V_107 ) ;
if ( ! V_59 )
return - V_73 ;
V_7 -> V_8 = V_59 ;
V_59 -> V_32 = V_66 -> V_32 ;
V_59 -> V_26 = V_63 -> V_82 ;
V_59 -> V_12 = F_27 ( & V_56 -> V_44 , V_108 ,
& V_59 -> V_15 , V_107 ) ;
if ( ! V_59 -> V_12 )
return - V_69 ;
V_59 -> V_35 = F_28 ( V_109 , V_110 ,
F_18 , V_7 ) ;
if ( V_59 -> V_35 < 0 )
return - V_111 ;
F_5 ( V_59 -> V_35 ) = 0 ;
V_46 = F_29 ( V_58 , V_64 -> V_82 , V_112 ,
V_66 -> V_113 , & V_114 ) ;
if ( V_46 )
F_30 ( V_59 -> V_35 ) ;
return V_46 ;
}
static int F_31 ( struct V_55 * V_56 )
{
struct V_57 * V_58 = F_32 ( V_56 ) ;
struct V_5 * V_59 = V_58 -> V_74 [ 0 ] -> V_8 ;
F_30 ( V_59 -> V_35 ) ;
F_33 ( V_58 ) ;
return 0 ;
}
