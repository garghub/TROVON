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
if ( V_2 -> V_23 & 0x02 )
V_33 . V_34 |= V_35 ;
V_17 . V_36 = V_2 -> V_36 ? V_2 -> V_36 : V_2 -> V_37 ;
V_17 . V_38 = V_2 -> V_39 ? V_2 -> V_39 : V_2 -> V_40 ;
V_17 . V_38 <<= 20 ;
V_17 . V_41 = V_2 -> V_41 ;
if ( V_2 -> V_42 && V_2 -> V_42 < 64 )
V_17 . V_43 = ( 1UL << V_2 -> V_42 ) - 1 ;
else
V_17 . V_43 = V_44 ;
if ( ! V_2 -> V_45 ) {
if ( V_46 )
V_17 . V_47 = 64 ;
else
V_17 . V_47 = V_2 -> V_48 ;
} else {
V_17 . V_47 = V_2 -> V_45 + 1 ;
}
V_15 = F_5 () ;
V_14 = ( void * ) V_2 + V_2 -> V_49 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_48 ; V_14 ++ , V_16 ++ ) {
if ( V_15 != V_14 -> V_50 )
continue;
V_17 . V_51 = V_14 -> V_52 ;
V_17 . V_53 = V_14 -> V_54 ;
V_17 . V_55 = V_14 -> V_56 ;
V_17 . V_57 = V_14 -> V_58 ;
V_17 . V_59 = V_14 -> V_60 ;
V_17 . V_61 = V_14 -> V_62 ;
V_17 . V_63 = V_14 -> V_64 ;
break;
}
V_65 . V_66 = 1 ;
if ( V_2 -> V_67 & 0x2 )
V_65 . V_68 = 1 ;
memcpy ( & V_65 . V_69 , & V_2 -> V_69 , V_70 ) ;
V_17 . V_71 = ( V_2 -> V_72 & 0x80 ) ? ( V_2 -> V_72 & 31 ) : 0 ;
V_17 . V_73 = ( V_2 -> V_72 & 0x80 ) ? ( V_2 -> V_74 & 31 ) : 0 ;
V_17 . V_75 = ( V_2 -> V_72 & 0x80 ) ? ( V_2 -> V_76 & 31 ) : 0 ;
V_17 . V_77 = V_2 -> V_77 ;
}
void T_1 F_6 ( struct V_65 * V_78 )
{
* V_78 = V_65 ;
}
static void T_1 F_7 ( struct V_79 * V_2 )
{
if ( ! V_80 )
return;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_7 . V_8 = sizeof( * V_2 ) ;
if ( F_3 ( V_81 , V_2 ) )
return;
if ( V_2 -> V_7 . V_11 != 0x0010 )
return;
F_8 ( & V_82 , V_2 ) ;
V_83 = 1 ;
}
int T_1 F_9 ( struct V_84 * V_78 )
{
if ( ! V_83 )
return - V_12 ;
* V_78 = V_82 ;
return 0 ;
}
static long T_1 F_10 ( struct V_85 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_86 . V_8 = sizeof( * V_2 ) ;
V_2 -> V_87 . V_86 . V_8 = sizeof( struct V_88 ) ;
V_2 -> V_87 . V_86 . type = V_89 ;
V_2 -> V_87 . V_90 = V_91 ;
V_2 -> V_87 . V_92 = V_93 ;
V_2 -> V_87 . V_94 = 4712 ;
V_2 -> V_87 . V_95 = 1 ;
if ( F_3 ( V_96 , V_2 ) )
return - V_12 ;
if ( V_2 -> V_86 . V_11 != 0x20 )
return - V_12 ;
if ( V_2 -> V_87 . V_97 == 0 )
return 0 ;
return ( V_2 -> V_87 . V_97 - 1 ) * V_98 ;
}
static long T_1 F_11 ( struct V_85 * V_2 )
{
memset ( V_2 , 0 , V_98 ) ;
V_2 -> V_86 . V_8 = V_98 ;
if ( F_3 ( V_99 , V_2 ) )
return - V_12 ;
if ( ( V_2 -> V_86 . V_11 != 0x20 ) && ( V_2 -> V_86 . V_11 != 0x220 ) )
return - V_12 ;
if ( V_2 -> V_87 . V_97 == 0 )
return 0 ;
return ( V_2 -> V_87 . V_97 - 1 ) * V_98 ;
}
static void T_1 F_12 ( void * V_2 )
{
unsigned long V_67 ;
long V_100 = - V_12 ;
F_13 ( V_67 ) ;
if ( F_14 ( V_2 , V_101 , V_101 ) )
goto V_102;
V_100 = F_10 ( V_2 ) ;
if ( V_100 )
goto V_103;
if ( ! ( V_33 . V_104 & 1 ) )
F_15 () ;
V_100 = F_11 ( V_2 ) ;
V_103:
F_14 ( V_2 , 0 , 0 ) ;
V_102:
F_16 ( V_67 ) ;
if ( V_100 > 0 )
V_17 . V_105 = V_100 ;
}
static void T_1 F_17 ( struct V_106 * V_2 )
{
if ( V_2 -> V_7 . V_11 != 0x20 )
return;
if ( V_2 -> V_107 & V_108 )
V_17 . V_109 = 1 ;
if ( F_18 ( V_2 ) )
V_17 . V_110 = 1 ;
}
void T_1 F_19 ( void )
{
void * V_2 = & V_111 ;
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , 0 , 0 ) ;
F_17 ( V_2 ) ;
}
