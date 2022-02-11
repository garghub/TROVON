static void F_1 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = V_2 -> V_4 ;
T_2 V_5 ;
V_5 = F_2 ( & V_4 -> V_6 ) ;
V_5 &= ~ ( V_7 ) ;
F_3 ( V_5 , & V_4 -> V_6 ) ;
}
static int F_4 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 -> V_2 ;
unsigned long V_12 ;
F_5 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_13 , V_12 ) ;
if ( V_9 -> V_14 || V_9 -> V_15 || V_9 -> V_16 )
return - V_17 ;
return 0 ;
}
static int F_7 ( unsigned V_18 ,
unsigned V_19 , unsigned V_20 , unsigned V_21 ,
unsigned V_22 , struct V_10 * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 -> V_2 ;
struct V_23 T_1 * V_24 = V_2 -> V_24 ;
unsigned long V_12 ;
T_3 V_5 ;
if ( V_18 >= 256 )
return 1 ;
V_19 >>= 8 ;
V_20 >>= 8 ;
V_21 >>= 8 ;
V_5 = ( V_19 | ( V_20 << 8 ) | ( V_21 << 16 ) ) ;
F_5 ( & V_2 -> V_13 , V_12 ) ;
F_8 ( V_5 , & V_24 -> V_25 [ V_18 ] ) ;
F_6 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , struct V_26 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 -> V_2 ;
return F_10 ( V_2 -> V_28 ,
V_11 -> V_29 . V_30 , V_11 -> V_29 . V_31 ,
V_2 -> V_32 , V_27 ) ;
}
static int F_11 ( struct V_10 * V_11 , unsigned int V_33 , unsigned long V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 -> V_2 ;
struct V_3 T_1 * V_4 = V_2 -> V_4 ;
struct V_35 V_36 , V_37 * V_38 ;
unsigned long V_12 ;
int V_39 , V_40 , V_41 = 0 ;
switch ( V_33 ) {
case V_42 :
F_5 ( & V_2 -> V_13 , V_12 ) ;
F_1 ( V_2 ) ;
F_6 ( & V_2 -> V_13 , V_12 ) ;
break;
case V_43 :
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
F_5 ( & V_2 -> V_13 , V_12 ) ;
V_36 . V_44 = V_45 ;
V_36 . V_46 = V_11 -> V_9 . V_47 ;
V_36 . V_48 = V_11 -> V_9 . V_49 ;
V_36 . V_50 = V_2 -> V_40 ;
V_36 . V_51 = 72 ;
V_36 . V_52 = V_2 -> V_53 ;
F_6 ( & V_2 -> V_13 , V_12 ) ;
V_38 = (struct V_35 V_37 * ) V_34 ;
if ( F_12 ( V_38 , & V_36 , sizeof( V_36 ) ) )
V_41 = - V_54 ;
break;
case V_55 :
if ( F_13 ( V_40 , ( int V_37 * ) V_34 ) ) {
V_41 = - V_54 ;
break;
}
F_5 ( & V_2 -> V_13 , V_12 ) ;
V_39 = F_2 ( & V_4 -> V_6 ) ;
V_39 &= ~ V_7 ;
switch( V_40 ) {
case V_56 :
V_39 |= ( V_57 <<
V_58 ) ;
break;
case V_59 :
V_39 |= ( V_60 <<
V_58 ) ;
break;
case V_61 :
break;
default:
V_41 = - V_62 ;
break;
}
if ( ! V_41 ) {
F_3 ( V_39 , & V_4 -> V_6 ) ;
V_2 -> V_40 = V_40 ;
}
F_6 ( & V_2 -> V_13 , V_12 ) ;
break;
default:
V_41 = F_14 ( V_33 , V_34 , V_11 ,
V_45 , 8 ,
V_11 -> V_29 . V_31 ) ;
break;
}
return V_41 ;
}
static void F_15 ( struct V_10 * V_11 , int V_63 ,
struct V_64 * V_65 )
{
const char * V_66 = V_65 -> V_66 ;
F_16 ( V_11 -> V_29 . V_67 , V_66 , sizeof( V_11 -> V_29 . V_67 ) ) ;
V_11 -> V_29 . type = V_68 ;
V_11 -> V_29 . V_69 = V_70 ;
V_11 -> V_29 . V_71 = V_63 ;
V_11 -> V_29 . V_72 = V_73 ;
}
static void F_17 ( struct V_74 * V_75 , struct V_10 * V_11 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_18 ( & V_75 -> V_76 [ 0 ] ,
V_2 -> V_4 , sizeof( struct V_3 ) ) ;
if ( V_2 -> V_24 )
F_18 ( & V_75 -> V_76 [ 0 ] ,
V_2 -> V_24 , sizeof( struct V_23 ) ) ;
if ( V_2 -> V_77 )
F_18 ( & V_75 -> V_76 [ 0 ] ,
V_2 -> V_77 , sizeof( struct V_78 ) ) ;
if ( V_11 -> V_79 )
F_18 ( & V_75 -> V_76 [ 1 ] ,
V_11 -> V_79 , V_11 -> V_29 . V_31 ) ;
}
static int F_19 ( struct V_74 * V_75 )
{
struct V_64 * V_65 = V_75 -> V_80 . V_81 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_82 , V_63 , V_83 , V_84 ;
V_11 = F_20 ( sizeof( struct V_1 ) , & V_75 -> V_80 ) ;
V_84 = - V_85 ;
if ( ! V_11 )
goto V_86;
V_2 = V_11 -> V_2 ;
F_21 ( & V_2 -> V_13 ) ;
F_22 ( & V_11 -> V_9 , V_65 , 8 ) ;
V_11 -> V_9 . V_19 . V_87 = 8 ;
V_11 -> V_9 . V_20 . V_87 = 8 ;
V_11 -> V_9 . V_21 . V_87 = 8 ;
V_63 = F_23 ( V_65 , L_1 ,
V_11 -> V_9 . V_49 ) ;
V_11 -> V_29 . V_31 = F_24 ( V_63 * V_11 -> V_9 . V_47 ) ;
if ( ! strcmp ( V_65 -> V_88 -> V_66 , L_2 ) ||
! strcmp ( V_65 -> V_88 -> V_66 , L_3 ) ) {
V_11 -> V_29 . V_30 = V_75 -> V_76 [ 0 ] . V_89 ;
V_2 -> V_32 = V_75 -> V_76 [ 0 ] . V_12 & V_90 ;
} else {
V_11 -> V_29 . V_30 = V_75 -> V_76 [ 1 ] . V_89 ;
V_2 -> V_32 = V_75 -> V_76 [ 0 ] . V_12 & V_90 ;
}
V_2 -> V_4 = F_25 ( & V_75 -> V_76 [ 0 ] , 0 ,
sizeof( struct V_3 ) , L_4 ) ;
V_2 -> V_24 = F_25 ( & V_75 -> V_76 [ 0 ] , V_91 ,
sizeof( struct V_23 ) , L_5 ) ;
V_2 -> V_77 = F_25 ( & V_75 -> V_76 [ 0 ] , V_92 ,
sizeof( struct V_78 ) , L_6 ) ;
V_11 -> V_79 = F_25 ( & V_75 -> V_76 [ 1 ] , 0 ,
V_11 -> V_29 . V_31 , L_7 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_24 || ! V_2 -> V_77 || ! V_11 -> V_79 )
goto V_93;
V_82 = ( ( ( V_75 -> V_76 [ 1 ] . V_94 - V_75 -> V_76 [ 1 ] . V_89 ) + 1 ) ==
( 8 * 1024 * 1024 ) ) ;
F_26 ( sizeof( V_2 -> V_28 ) != sizeof( V_95 ) ) ;
memcpy ( & V_2 -> V_28 , & V_95 , sizeof( V_2 -> V_28 ) ) ;
for ( V_83 = 0 ; V_83 < V_96 ; V_83 ++ ) {
struct V_97 * V_98 = & V_2 -> V_28 [ V_83 ] ;
if ( ! V_98 -> V_99 )
break;
if ( V_98 -> V_100 & 0x80000000 )
V_98 -> V_100 = ( V_98 -> V_100 & 0x7fffffff ) +
( V_75 -> V_76 [ 0 ] . V_89 -
V_75 -> V_76 [ 1 ] . V_89 ) ;
if ( V_82 &&
V_98 -> V_99 >= 0x100000 &&
V_98 -> V_99 <= 0x400000 )
V_98 -> V_99 *= 2 ;
}
V_2 -> V_40 = V_61 ;
V_2 -> V_53 = ( V_82 ? 0x800000 : 0x400000 ) ;
V_11 -> V_12 = V_101 | V_102 ;
V_11 -> V_103 = & V_104 ;
F_1 ( V_2 ) ;
if ( F_27 ( & V_11 -> V_105 , 256 , 0 ) )
goto V_93;
F_28 ( & V_11 -> V_105 , V_11 ) ;
F_15 ( V_11 , V_63 , V_65 ) ;
V_84 = F_29 ( V_11 ) ;
if ( V_84 < 0 )
goto V_106;
F_30 ( & V_75 -> V_80 , V_11 ) ;
F_31 ( V_107 L_8 ,
V_65 ,
V_2 -> V_32 , V_11 -> V_29 . V_30 ,
V_2 -> V_53 >> 20 ) ;
return 0 ;
V_106:
F_32 ( & V_11 -> V_105 ) ;
V_93:
F_17 ( V_75 , V_11 , V_2 ) ;
F_33 ( V_11 ) ;
V_86:
return V_84 ;
}
static int F_34 ( struct V_74 * V_75 )
{
struct V_10 * V_11 = F_35 ( & V_75 -> V_80 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_36 ( V_11 ) ;
F_32 ( & V_11 -> V_105 ) ;
F_17 ( V_75 , V_11 , V_2 ) ;
F_33 ( V_11 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
if ( F_38 ( L_9 , NULL ) )
return - V_108 ;
return F_39 ( & V_109 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_109 ) ;
}
