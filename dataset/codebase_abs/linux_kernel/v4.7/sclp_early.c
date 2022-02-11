static int T_1 F_1 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
F_2 ( 0 , 9 ) ;
V_3 = F_3 ( V_1 , V_2 ) ;
if ( V_3 )
goto V_4;
F_4 ( V_5 | V_6 | V_7 |
V_8 | V_9 | V_10 ) ;
F_5 () ;
V_4:
F_6 () ;
F_7 ( 0 , 9 ) ;
return V_3 ;
}
static int T_1 F_8 ( struct V_11 * V_2 )
{
int V_3 , V_12 ;
T_2 V_13 [] = { V_14 ,
V_15 } ;
for ( V_12 = 0 ; V_12 < F_9 ( V_13 ) ; V_12 ++ ) {
do {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_16 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_16 . V_18 = 0x80 ;
V_2 -> V_16 . V_19 [ 2 ] = 0x80 ;
V_3 = F_1 ( V_13 [ V_12 ] , V_2 ) ;
} while ( V_3 == - V_20 );
if ( V_3 )
break;
if ( V_2 -> V_16 . V_21 == 0x10 )
return 0 ;
if ( V_2 -> V_16 . V_21 != 0x1f0 )
break;
}
return - V_22 ;
}
static void T_1 F_10 ( struct V_11 * V_2 )
{
struct V_23 * V_24 ;
T_3 V_25 , V_26 ;
if ( F_8 ( V_2 ) )
return;
V_27 . V_28 = V_2 -> V_28 ;
V_27 . V_29 = ! ! ( V_2 -> V_30 & 0x02 ) ;
V_27 . V_31 = ! ! ( V_2 -> V_30 & 0x01 ) ;
V_27 . V_32 = ! ! ( V_2 -> V_33 & 0x08 ) ;
V_27 . V_34 = ! ! ( V_2 -> V_35 & 0x80 ) ;
if ( V_2 -> V_36 & 0x02 )
V_37 . V_38 |= V_39 ;
V_27 . V_40 = V_2 -> V_40 ? V_2 -> V_40 : V_2 -> V_41 ;
V_27 . V_42 = V_2 -> V_43 ? V_2 -> V_43 : V_2 -> V_44 ;
V_27 . V_42 <<= 20 ;
V_27 . V_45 = V_2 -> V_45 ;
if ( V_2 -> V_46 && V_2 -> V_46 < 64 )
V_27 . V_47 = ( 1UL << V_2 -> V_46 ) - 1 ;
else
V_27 . V_47 = V_48 ;
if ( ! V_2 -> V_49 ) {
if ( V_50 )
V_27 . V_51 = 64 ;
else
V_27 . V_51 = V_2 -> V_52 ;
} else {
V_27 . V_51 = V_2 -> V_49 + 1 ;
}
V_25 = F_11 () ;
V_24 = ( void * ) V_2 + V_2 -> V_53 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_52 ; V_24 ++ , V_26 ++ ) {
if ( V_25 != V_24 -> V_54 )
continue;
V_27 . V_55 = V_24 -> V_56 ;
V_27 . V_57 = V_24 -> V_58 ;
V_27 . V_59 = V_24 -> V_60 ;
break;
}
V_61 . V_62 = 1 ;
if ( V_2 -> V_63 & 0x2 )
V_61 . V_64 = 1 ;
memcpy ( & V_61 . V_65 , & V_2 -> V_65 , V_66 ) ;
V_27 . V_67 = ( V_2 -> V_68 & 0x80 ) ? ( V_2 -> V_68 & 31 ) : 0 ;
V_27 . V_69 = ( V_2 -> V_68 & 0x80 ) ? ( V_2 -> V_70 & 31 ) : 0 ;
V_27 . V_71 = ( V_2 -> V_68 & 0x80 ) ? ( V_2 -> V_72 & 31 ) : 0 ;
V_27 . V_73 = V_2 -> V_73 ;
}
void T_1 F_12 ( struct V_61 * V_74 )
{
* V_74 = V_61 ;
}
static int T_1 F_13 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
do {
V_3 = F_1 ( V_1 , V_2 ) ;
} while ( V_3 == - V_20 );
if ( V_3 )
return - V_22 ;
if ( ( (struct V_75 * ) V_2 ) -> V_21 != 0x0020 )
return - V_22 ;
return 0 ;
}
static void T_1 F_14 ( struct V_76 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_77 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_78 . V_77 . V_17 = sizeof( struct V_79 ) ;
V_2 -> V_78 . V_77 . type = V_80 ;
V_2 -> V_78 . V_81 = V_82 ;
V_2 -> V_78 . V_83 = V_84 ;
V_2 -> V_78 . V_85 = 4712 ;
V_2 -> V_78 . V_86 = 1 ;
}
static int T_1 F_15 ( struct V_87 * V_2 ,
unsigned long V_88 ,
unsigned long V_89 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_16 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_90 = sizeof( V_91 ) ;
V_2 -> V_88 = V_88 ;
V_2 -> V_89 = V_89 ;
return F_13 ( V_92 , V_2 ) ;
}
static long T_1 F_16 ( struct V_76 * V_2 )
{
F_14 ( V_2 ) ;
if ( F_13 ( V_93 , V_2 ) )
return - V_22 ;
if ( V_2 -> V_78 . V_94 == 0 )
return 0 ;
return ( V_2 -> V_78 . V_94 - 1 ) * V_95 ;
}
static long T_1 F_17 ( struct V_75 * V_2 )
{
memset ( V_2 , 0 , V_95 ) ;
V_2 -> V_17 = V_95 ;
if ( F_13 ( V_96 , V_2 ) )
return - V_22 ;
if ( ( (struct V_76 * ) V_2 ) -> V_78 . V_94 == 0 )
return 0 ;
return ( ( (struct V_76 * ) V_2 ) -> V_78 . V_94 - 1 ) * V_95 ;
}
static void T_1 F_18 ( void * V_2 )
{
long V_97 ;
if ( F_15 ( V_2 , 0 , 0x40000010 ) )
return;
V_97 = F_16 ( V_2 ) ;
if ( V_97 < 0 )
return;
if ( V_97 != 0 )
goto V_4;
if ( F_15 ( V_2 , 0x00000010 , 0x40000010 ) )
return;
V_97 = F_16 ( V_2 ) ;
if ( V_97 < 0 )
return;
V_97 = F_17 ( V_2 ) ;
if ( V_97 < 0 )
return;
V_4:
V_27 . V_98 = V_97 ;
}
static unsigned int T_1 F_19 ( struct V_87 * V_2 )
{
if ( ! ( V_2 -> V_99 & V_100 ) )
return 0 ;
if ( ! ( V_2 -> V_101 & ( V_102 | V_103 ) ) )
return 0 ;
return 1 ;
}
static void T_1 F_20 ( struct V_87 * V_2 )
{
if ( V_2 -> V_16 . V_21 != 0x20 )
return;
if ( V_2 -> V_99 & V_104 )
V_27 . V_105 = 1 ;
if ( F_19 ( V_2 ) )
V_27 . V_106 = 1 ;
}
void T_1 F_21 ( void )
{
void * V_2 = & V_107 ;
F_10 ( V_2 ) ;
F_18 ( V_2 ) ;
F_15 ( V_2 , 0 , 0 ) ;
F_20 ( V_2 ) ;
}
