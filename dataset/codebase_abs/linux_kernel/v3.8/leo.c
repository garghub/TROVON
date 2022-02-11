static void F_1 ( struct V_1 T_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ;
( F_2 ( & V_2 -> V_4 ) & V_5 ) &&
V_3 < 300000 ;
V_3 ++ )
F_3 ( 1 ) ;
return;
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_10 T_1 * V_11 = V_9 -> V_12 ;
struct V_13 T_1 * V_14 = V_9 -> V_14 ;
unsigned long V_15 ;
T_2 V_16 ;
F_5 ( & V_9 -> V_17 , V_15 ) ;
V_9 -> V_18 = ( ( V_7 -> V_19 . V_20 - 1 ) |
( ( V_7 -> V_19 . V_21 - 1 ) << 16 ) ) ;
F_6 ( 0xffffffff , & V_11 -> V_22 ) ;
F_6 ( 0xffff , & V_11 -> V_23 ) ;
F_6 ( 0 , & V_11 -> V_24 ) ;
F_6 ( V_9 -> V_18 , & V_11 -> V_25 ) ;
F_6 ( 0 , & V_11 -> V_26 ) ;
F_6 ( 0xff000000 , & V_11 -> V_27 ) ;
F_6 ( 0x310850 , & V_11 -> V_28 ) ;
F_6 ( 0 , & V_11 -> V_29 ) ;
F_6 ( ( V_7 -> V_19 . V_20 - 1 ) | ( ( V_7 -> V_19 . V_21 - 1 ) << 11 ) ,
& V_9 -> V_30 -> V_18 ) ;
F_6 ( 4 , & V_9 -> V_30 -> V_31 ) ;
F_6 ( 0x80000000 , & V_9 -> V_30 -> V_32 ) ;
F_6 ( 0 , & V_9 -> V_30 -> V_33 ) ;
do {
V_16 = F_2 ( & V_9 -> V_30 -> V_34 ) ;
} while ( V_16 & 0x20000000 );
F_6 ( 1 , & V_11 -> V_22 ) ;
F_6 ( 0x00ffffff , & V_11 -> V_27 ) ;
F_6 ( 0x310b90 , & V_11 -> V_28 ) ;
F_6 ( 0 , & V_9 -> V_30 -> V_31 ) ;
F_6 ( F_2 ( & V_14 -> V_35 ) & ~ V_36 , & V_14 -> V_35 ) ;
F_7 ( & V_9 -> V_17 , V_15 ) ;
}
static int F_8 ( struct V_37 * V_19 , struct V_6 * V_7 )
{
F_4 ( V_7 ) ;
if ( V_19 -> V_38 || V_19 -> V_39 || V_19 -> V_40 )
return - V_41 ;
return 0 ;
}
static int F_9 ( unsigned V_42 ,
unsigned V_43 , unsigned V_44 , unsigned V_45 ,
unsigned V_46 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
unsigned long V_15 ;
T_2 V_16 ;
int V_3 ;
if ( V_42 >= 256 )
return 1 ;
V_43 >>= 8 ;
V_44 >>= 8 ;
V_45 >>= 8 ;
V_9 -> V_47 [ V_42 ] = V_43 | ( V_44 << 8 ) | ( V_45 << 16 ) ;
F_5 ( & V_9 -> V_17 , V_15 ) ;
F_1 ( V_2 ) ;
F_6 ( V_48 , & V_2 -> V_49 ) ;
for ( V_3 = 0 ; V_3 < 256 ; V_3 ++ )
F_6 ( V_9 -> V_47 [ V_3 ] , & V_2 -> V_50 ) ;
F_6 ( V_51 , & V_2 -> V_49 ) ;
V_16 = F_2 ( & V_2 -> V_4 ) ;
V_16 |= ( V_52 | V_53 ) ;
F_6 ( V_16 , & V_2 -> V_4 ) ;
F_7 ( & V_9 -> V_17 , V_15 ) ;
return 0 ;
}
static int F_10 ( int V_54 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
unsigned long V_15 ;
T_2 V_16 ;
F_5 ( & V_9 -> V_17 , V_15 ) ;
switch ( V_54 ) {
case V_55 :
V_16 = F_2 ( & V_2 -> V_4 ) ;
V_16 |= V_56 ;
F_6 ( V_16 , & V_2 -> V_4 ) ;
V_9 -> V_15 &= ~ V_57 ;
break;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
V_16 = F_2 ( & V_2 -> V_4 ) ;
V_16 &= ~ V_56 ;
F_6 ( V_16 , & V_2 -> V_4 ) ;
V_9 -> V_15 |= V_57 ;
break;
}
F_7 ( & V_9 -> V_17 , V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , struct V_62 * V_63 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
return F_12 ( V_64 ,
V_7 -> V_65 . V_66 , V_7 -> V_65 . V_67 ,
V_9 -> V_68 , V_63 ) ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_69 , unsigned long V_70 )
{
return F_14 ( V_69 , V_70 , V_7 ,
V_71 , 32 , V_7 -> V_65 . V_67 ) ;
}
static void
F_15 ( struct V_6 * V_7 , struct V_72 * V_73 )
{
F_16 ( V_7 -> V_65 . V_74 , V_73 -> V_75 , sizeof( V_7 -> V_65 . V_74 ) ) ;
V_7 -> V_65 . type = V_76 ;
V_7 -> V_65 . V_77 = V_78 ;
V_7 -> V_65 . V_79 = 8192 ;
V_7 -> V_65 . V_80 = V_81 ;
}
static void F_17 ( struct V_6 * V_7 , struct V_82 * V_83 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
struct V_1 T_1 * V_2 = V_9 -> V_2 ;
struct V_84 * V_85 ;
unsigned long V_15 ;
T_2 V_16 ;
int V_3 , V_86 ;
F_5 ( & V_9 -> V_17 , V_15 ) ;
F_1 ( V_2 ) ;
for ( V_3 = 0 , V_85 = V_83 -> V_87 ; V_3 < V_83 -> V_88 ; V_3 ++ , V_85 ++ ) {
switch ( V_85 -> V_89 ) {
case V_90 :
V_86 = ( V_85 -> V_91 & 0xf ) + 0x40 ;
break;
case V_92 :
V_86 = V_85 -> V_91 & 0x3f ;
break;
default:
continue;
} ;
F_6 ( 0x5800 + V_86 , & V_2 -> V_49 ) ;
F_6 ( V_85 -> V_93 [ 0 ] , & V_2 -> V_50 ) ;
}
F_6 ( V_94 , & V_2 -> V_49 ) ;
V_16 = F_2 ( & V_2 -> V_4 ) ;
V_16 |= ( V_52 | V_53 ) ;
F_6 ( V_16 , & V_2 -> V_4 ) ;
F_7 ( & V_9 -> V_17 , V_15 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_84 V_85 ;
struct V_82 V_83 ;
V_83 . V_88 = 1 ;
V_83 . V_87 = & V_85 ;
V_85 . V_89 = V_90 ;
V_85 . V_91 = 0 ;
V_85 . V_93 [ 0 ] = 0x2c0 ;
F_17 ( V_7 , & V_83 ) ;
V_85 . V_91 = 1 ;
V_85 . V_93 [ 0 ] = 0x30 ;
F_17 ( V_7 , & V_83 ) ;
V_85 . V_91 = 2 ;
V_85 . V_93 [ 0 ] = 0x20 ;
F_17 ( V_7 , & V_83 ) ;
V_85 . V_89 = V_92 ;
V_85 . V_91 = 1 ;
V_85 . V_93 [ 0 ] = 0x30 ;
F_17 ( V_7 , & V_83 ) ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
T_2 V_16 ;
V_16 = F_2 ( & V_9 -> V_95 -> V_96 ) ;
V_16 |= V_97 ;
F_6 ( V_16 , & V_9 -> V_95 -> V_96 ) ;
F_4 ( V_7 ) ;
}
static void F_20 ( struct V_37 * V_19 )
{
V_19 -> V_43 . V_98 = 0 ;
V_19 -> V_43 . V_99 = 8 ;
V_19 -> V_44 . V_98 = 8 ;
V_19 -> V_44 . V_99 = 8 ;
V_19 -> V_45 . V_98 = 16 ;
V_19 -> V_45 . V_99 = 8 ;
V_19 -> V_46 . V_98 = 0 ;
V_19 -> V_46 . V_99 = 0 ;
}
static void F_21 ( struct V_100 * V_101 , struct V_6 * V_7 ,
struct V_8 * V_9 )
{
if ( V_9 -> V_30 )
F_22 ( & V_101 -> V_102 [ 0 ] , V_9 -> V_30 , 0x1000 ) ;
if ( V_9 -> V_12 )
F_22 ( & V_101 -> V_102 [ 0 ] , V_9 -> V_12 , 0x1000 ) ;
if ( V_9 -> V_95 )
F_22 ( & V_101 -> V_102 [ 0 ] , V_9 -> V_95 , 0x1000 ) ;
if ( V_9 -> V_2 )
F_22 ( & V_101 -> V_102 [ 0 ] , V_9 -> V_2 , 0x1000 ) ;
if ( V_9 -> V_14 )
F_22 ( & V_101 -> V_102 [ 0 ] ,
V_9 -> V_14 , sizeof( struct V_13 ) ) ;
if ( V_7 -> V_103 )
F_22 ( & V_101 -> V_102 [ 0 ] , V_7 -> V_103 , 0x800000 ) ;
}
static int F_23 ( struct V_100 * V_101 )
{
struct V_72 * V_73 = V_101 -> V_104 . V_105 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_106 , V_107 ;
V_7 = F_24 ( sizeof( struct V_8 ) , & V_101 -> V_104 ) ;
V_107 = - V_108 ;
if ( ! V_7 )
goto V_109;
V_9 = V_7 -> V_9 ;
F_25 ( & V_9 -> V_17 ) ;
V_7 -> V_65 . V_66 = V_101 -> V_102 [ 0 ] . V_110 ;
V_9 -> V_68 = V_101 -> V_102 [ 0 ] . V_15 & V_111 ;
F_26 ( & V_7 -> V_19 , V_73 , 32 ) ;
F_20 ( & V_7 -> V_19 ) ;
V_106 = F_27 ( V_73 , L_1 ,
V_7 -> V_19 . V_20 ) ;
V_7 -> V_65 . V_67 = F_28 ( V_106 * V_7 -> V_19 . V_21 ) ;
V_9 -> V_30 =
F_29 ( & V_101 -> V_102 [ 0 ] , V_112 ,
0x1000 , L_2 ) ;
V_9 -> V_12 =
F_29 ( & V_101 -> V_102 [ 0 ] , V_113 ,
0x1000 , L_3 ) ;
V_9 -> V_95 =
F_29 ( & V_101 -> V_102 [ 0 ] , V_114 ,
0x1000 , L_4 ) ;
V_9 -> V_2 =
F_29 ( & V_101 -> V_102 [ 0 ] , V_115 ,
0x1000 , L_5 ) ;
V_9 -> V_14 =
F_29 ( & V_101 -> V_102 [ 0 ] , V_116 ,
sizeof( struct V_13 ) , L_6 ) ;
V_7 -> V_103 =
F_29 ( & V_101 -> V_102 [ 0 ] , V_117 ,
0x800000 , L_7 ) ;
if ( ! V_9 -> V_30 ||
! V_9 -> V_12 ||
! V_9 -> V_95 ||
! V_9 -> V_2 ||
! V_9 -> V_14 ||
! V_7 -> V_103 )
goto V_118;
V_7 -> V_15 = V_119 ;
V_7 -> V_120 = & V_121 ;
V_7 -> V_122 = V_9 -> V_47 ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
F_10 ( V_55 , V_7 ) ;
if ( F_30 ( & V_7 -> V_123 , 256 , 0 ) )
goto V_118;
F_15 ( V_7 , V_73 ) ;
V_107 = F_31 ( V_7 ) ;
if ( V_107 < 0 )
goto V_124;
F_32 ( & V_101 -> V_104 , V_7 ) ;
F_33 ( V_125 L_8 ,
V_73 -> V_126 ,
V_9 -> V_68 , V_7 -> V_65 . V_66 ) ;
return 0 ;
V_124:
F_34 ( & V_7 -> V_123 ) ;
V_118:
F_21 ( V_101 , V_7 , V_9 ) ;
F_35 ( V_7 ) ;
V_109:
return V_107 ;
}
static int F_36 ( struct V_100 * V_101 )
{
struct V_6 * V_7 = F_37 ( & V_101 -> V_104 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_38 ( V_7 ) ;
F_34 ( & V_7 -> V_123 ) ;
F_21 ( V_101 , V_7 , V_9 ) ;
F_35 ( V_7 ) ;
F_32 ( & V_101 -> V_104 , NULL ) ;
return 0 ;
}
static int T_3 F_39 ( void )
{
if ( F_40 ( L_9 , NULL ) )
return - V_127 ;
return F_41 ( & V_128 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_128 ) ;
}
