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
if ( V_2 -> V_32 & 0x02 )
V_33 . V_34 |= V_35 ;
V_27 . V_36 = V_2 -> V_36 ? V_2 -> V_36 : V_2 -> V_37 ;
V_27 . V_38 = V_2 -> V_39 ? V_2 -> V_39 : V_2 -> V_40 ;
V_27 . V_38 <<= 20 ;
V_27 . V_41 = V_2 -> V_41 ;
if ( ! V_2 -> V_42 ) {
if ( V_43 )
V_27 . V_44 = 64 ;
else
V_27 . V_44 = V_2 -> V_45 ;
} else {
V_27 . V_44 = V_2 -> V_42 + 1 ;
}
V_25 = F_11 () ;
V_24 = ( void * ) V_2 + V_2 -> V_46 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_45 ; V_24 ++ , V_26 ++ ) {
if ( V_25 != V_24 -> V_47 )
continue;
V_27 . V_48 = V_24 -> V_49 ;
V_27 . V_50 = V_24 -> V_51 ;
break;
}
V_52 . V_53 = 1 ;
if ( V_2 -> V_54 & 0x2 )
V_52 . V_55 = 1 ;
memcpy ( & V_52 . V_56 , & V_2 -> V_56 , V_57 ) ;
V_27 . V_58 = ( V_2 -> V_59 & 0x80 ) ? ( V_2 -> V_59 & 31 ) : 0 ;
V_27 . V_60 = ( V_2 -> V_59 & 0x80 ) ? ( V_2 -> V_61 & 31 ) : 0 ;
V_27 . V_62 = ( V_2 -> V_59 & 0x80 ) ? ( V_2 -> V_63 & 31 ) : 0 ;
}
void T_1 F_12 ( struct V_52 * V_64 )
{
* V_64 = V_52 ;
}
static int T_1 F_13 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
do {
V_3 = F_1 ( V_1 , V_2 ) ;
} while ( V_3 == - V_20 );
if ( V_3 )
return - V_22 ;
if ( ( (struct V_65 * ) V_2 ) -> V_21 != 0x0020 )
return - V_22 ;
return 0 ;
}
static void T_1 F_14 ( struct V_66 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_67 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_68 . V_67 . V_17 = sizeof( struct V_69 ) ;
V_2 -> V_68 . V_67 . type = V_70 ;
V_2 -> V_68 . V_71 = V_72 ;
V_2 -> V_68 . V_73 = V_74 ;
V_2 -> V_68 . V_75 = 4712 ;
V_2 -> V_68 . V_76 = 1 ;
}
static int T_1 F_15 ( struct V_77 * V_2 ,
unsigned long V_78 ,
unsigned long V_79 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_16 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_80 = sizeof( V_81 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_79 = V_79 ;
return F_13 ( V_82 , V_2 ) ;
}
static long T_1 F_16 ( struct V_66 * V_2 )
{
F_14 ( V_2 ) ;
if ( F_13 ( V_83 , V_2 ) )
return - V_22 ;
if ( V_2 -> V_68 . V_84 == 0 )
return 0 ;
return ( V_2 -> V_68 . V_84 - 1 ) * V_85 ;
}
static long T_1 F_17 ( struct V_65 * V_2 )
{
memset ( V_2 , 0 , V_85 ) ;
V_2 -> V_17 = V_85 ;
if ( F_13 ( V_86 , V_2 ) )
return - V_22 ;
if ( ( (struct V_66 * ) V_2 ) -> V_68 . V_84 == 0 )
return 0 ;
return ( ( (struct V_66 * ) V_2 ) -> V_68 . V_84 - 1 ) * V_85 ;
}
static void T_1 F_18 ( void * V_2 )
{
long V_87 ;
if ( F_15 ( V_2 , 0 , 0x40000010 ) )
return;
V_87 = F_16 ( V_2 ) ;
if ( V_87 < 0 )
return;
if ( V_87 != 0 )
goto V_4;
if ( F_15 ( V_2 , 0x00000010 , 0x40000010 ) )
return;
V_87 = F_16 ( V_2 ) ;
if ( V_87 < 0 )
return;
V_87 = F_17 ( V_2 ) ;
if ( V_87 < 0 )
return;
V_4:
V_27 . V_88 = V_87 ;
}
static unsigned int T_1 F_19 ( struct V_77 * V_2 )
{
if ( ! ( V_2 -> V_89 & V_90 ) )
return 0 ;
if ( ! ( V_2 -> V_91 & ( V_92 | V_93 ) ) )
return 0 ;
return 1 ;
}
static void T_1 F_20 ( struct V_77 * V_2 )
{
if ( V_2 -> V_16 . V_21 != 0x20 )
return;
if ( V_2 -> V_89 & V_94 )
V_27 . V_95 = 1 ;
if ( F_19 ( V_2 ) )
V_27 . V_96 = 1 ;
}
void T_1 F_21 ( void )
{
void * V_2 = & V_97 ;
F_10 ( V_2 ) ;
F_18 ( V_2 ) ;
F_15 ( V_2 , 0 , 0 ) ;
F_20 ( V_2 ) ;
}
