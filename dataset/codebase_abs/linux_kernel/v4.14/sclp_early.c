static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_4 [] = { V_5 ,
V_6 } ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_7 . V_8 = sizeof( * V_2 ) ;
V_2 -> V_7 . V_9 = 0x80 ;
V_2 -> V_7 . V_10 [ 2 ] = 0x80 ;
if ( F_3 ( V_4 [ V_3 ] , V_2 ) )
break;
if ( V_2 -> V_7 . V_11 == 0x10 )
return 0 ;
if ( V_2 -> V_7 . V_11 != 0x1f0 )
break;
}
return - V_12 ;
}
static void T_1 F_4 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
T_3 V_15 , V_16 ;
if ( F_1 ( V_2 ) )
return;
V_17 . V_18 = V_2 -> V_18 ;
V_17 . V_19 = ! ! ( V_2 -> V_20 & 0x02 ) ;
V_17 . V_21 = ! ! ( V_2 -> V_20 & 0x01 ) ;
V_17 . V_22 = ! ! ( V_2 -> V_23 & 0x80 ) ;
V_17 . V_24 = ! ! ( V_2 -> V_25 & 0x80 ) ;
V_17 . V_26 = ! ! ( V_2 -> V_25 & 0x40 ) ;
V_17 . V_27 = ! ! ( V_2 -> V_25 & 0x08 ) ;
V_17 . V_28 = ! ! ( V_2 -> V_29 & 0x40 ) ;
V_17 . V_30 = ! ! ( V_2 -> V_29 & 0x20 ) ;
V_17 . V_31 = ! ! ( V_2 -> V_32 & 0x80 ) ;
V_17 . V_33 = ! ! ( V_2 -> V_34 & 0x01 ) ;
if ( V_2 -> V_23 & 0x02 )
V_35 . V_36 |= V_37 ;
if ( V_2 -> V_38 & 0x40 )
V_35 . V_36 |= V_39 ;
V_17 . V_40 = V_2 -> V_40 ? V_2 -> V_40 : V_2 -> V_41 ;
V_17 . V_42 = V_2 -> V_43 ? V_2 -> V_43 : V_2 -> V_44 ;
V_17 . V_42 <<= 20 ;
V_17 . V_45 = V_2 -> V_45 ;
if ( V_2 -> V_46 && V_2 -> V_46 < 64 )
V_17 . V_47 = ( 1UL << V_2 -> V_46 ) - 1 ;
else
V_17 . V_47 = V_48 ;
if ( ! V_2 -> V_49 ) {
if ( V_50 )
V_17 . V_51 = 64 ;
else
V_17 . V_51 = V_2 -> V_52 ;
} else {
V_17 . V_51 = V_2 -> V_49 + 1 ;
}
V_15 = F_5 () ;
V_14 = ( void * ) V_2 + V_2 -> V_53 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_52 ; V_14 ++ , V_16 ++ ) {
if ( V_15 != V_14 -> V_54 )
continue;
V_17 . V_55 = V_14 -> V_56 ;
V_17 . V_57 = V_14 -> V_58 ;
V_17 . V_59 = V_14 -> V_60 ;
V_17 . V_61 = V_14 -> V_62 ;
V_17 . V_63 = V_14 -> V_64 ;
V_17 . V_65 = V_14 -> V_66 ;
V_17 . V_67 = V_14 -> V_68 ;
break;
}
V_69 . V_70 = 1 ;
if ( V_2 -> V_38 & 0x2 )
V_69 . V_71 = 1 ;
memcpy ( & V_69 . V_72 , & V_2 -> V_72 , V_73 ) ;
V_17 . V_74 = ( V_2 -> V_75 & 0x80 ) ? ( V_2 -> V_75 & 31 ) : 0 ;
V_17 . V_76 = ( V_2 -> V_75 & 0x80 ) ? ( V_2 -> V_77 & 31 ) : 0 ;
V_17 . V_78 = ( V_2 -> V_75 & 0x80 ) ? ( V_2 -> V_79 & 31 ) : 0 ;
V_17 . V_80 = V_2 -> V_80 ;
}
void T_1 F_6 ( struct V_69 * V_81 )
{
* V_81 = V_69 ;
}
static void T_1 F_7 ( struct V_82 * V_2 )
{
if ( ! V_83 )
return;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_7 . V_8 = sizeof( * V_2 ) ;
if ( F_3 ( V_84 , V_2 ) )
return;
if ( V_2 -> V_7 . V_11 != 0x0010 )
return;
F_8 ( & V_85 , V_2 ) ;
V_86 = 1 ;
}
int T_1 F_9 ( struct V_87 * V_81 )
{
if ( ! V_86 )
return - V_12 ;
* V_81 = V_85 ;
return 0 ;
}
static long T_1 F_10 ( struct V_88 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_89 . V_8 = sizeof( * V_2 ) ;
V_2 -> V_90 . V_89 . V_8 = sizeof( struct V_91 ) ;
V_2 -> V_90 . V_89 . type = V_92 ;
V_2 -> V_90 . V_93 = V_94 ;
V_2 -> V_90 . V_95 = V_96 ;
V_2 -> V_90 . V_97 = 4712 ;
V_2 -> V_90 . V_98 = 1 ;
if ( F_3 ( V_99 , V_2 ) )
return - V_12 ;
if ( V_2 -> V_89 . V_11 != 0x20 )
return - V_12 ;
if ( V_2 -> V_90 . V_100 == 0 )
return 0 ;
return ( V_2 -> V_90 . V_100 - 1 ) * V_101 ;
}
static long T_1 F_11 ( struct V_88 * V_2 )
{
memset ( V_2 , 0 , V_101 ) ;
V_2 -> V_89 . V_8 = V_101 ;
if ( F_3 ( V_102 , V_2 ) )
return - V_12 ;
if ( ( V_2 -> V_89 . V_11 != 0x20 ) && ( V_2 -> V_89 . V_11 != 0x220 ) )
return - V_12 ;
if ( V_2 -> V_90 . V_100 == 0 )
return 0 ;
return ( V_2 -> V_90 . V_100 - 1 ) * V_101 ;
}
static void T_1 F_12 ( void * V_2 )
{
unsigned long V_103 ;
long V_104 = - V_12 ;
F_13 ( V_103 ) ;
if ( F_14 ( V_2 , V_105 , V_105 ) )
goto V_106;
V_104 = F_10 ( V_2 ) ;
if ( V_104 )
goto V_107;
if ( ! ( V_35 . V_108 & 1 ) )
F_15 () ;
V_104 = F_11 ( V_2 ) ;
V_107:
F_14 ( V_2 , 0 , 0 ) ;
V_106:
F_16 ( V_103 ) ;
if ( V_104 > 0 )
V_17 . V_109 = V_104 ;
}
static void T_1 F_17 ( struct V_110 * V_2 )
{
if ( V_2 -> V_7 . V_11 != 0x20 )
return;
if ( V_2 -> V_111 & V_112 )
V_17 . V_113 = 1 ;
if ( F_18 ( V_2 ) )
V_17 . V_114 = 1 ;
}
void T_1 F_19 ( void )
{
void * V_2 = & V_115 ;
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , 0 , 0 ) ;
F_17 ( V_2 ) ;
}
