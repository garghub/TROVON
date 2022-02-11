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
V_27 = V_2 -> V_28 ;
V_29 = V_2 -> V_30 ;
if ( V_2 -> V_31 & 0x02 )
V_32 . V_33 |= V_34 ;
V_35 = V_2 -> V_36 ? V_2 -> V_36 : V_2 -> V_37 ;
V_38 = V_2 -> V_39 ? V_2 -> V_39 : V_2 -> V_40 ;
V_38 <<= 20 ;
V_41 = V_2 -> V_42 ;
if ( ! V_2 -> V_43 ) {
if ( V_44 )
V_45 = 64 ;
else
V_45 = V_2 -> V_46 ;
} else {
V_45 = V_2 -> V_43 + 1 ;
}
V_25 = F_11 () ;
V_24 = ( void * ) V_2 + V_2 -> V_47 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_46 ; V_24 ++ , V_26 ++ ) {
if ( V_25 != V_24 -> V_48 )
continue;
V_49 = V_24 -> V_50 ;
V_51 = V_24 -> V_52 ;
break;
}
V_53 . V_54 = 1 ;
if ( V_2 -> V_55 & 0x2 )
V_53 . V_56 = 1 ;
memcpy ( & V_53 . V_57 , & V_2 -> V_57 , V_58 ) ;
V_59 = ( V_2 -> V_60 & 0x80 ) ? ( V_2 -> V_60 & 31 ) : 0 ;
V_61 = ( V_2 -> V_60 & 0x80 ) ? ( V_2 -> V_62 & 31 ) : 0 ;
V_63 = F_12 ( V_59 , V_61 ) ;
V_64 = ( V_2 -> V_60 & 0x80 ) ? ( V_2 -> V_65 & 31 ) : 0 ;
}
bool T_1 F_13 ( void )
{
return ! ! V_66 ;
}
bool T_1 F_14 ( void )
{
return ! ! V_67 ;
}
unsigned long long F_15 ( void )
{
return V_35 ;
}
unsigned long long F_16 ( void )
{
return V_38 ;
}
unsigned int F_17 ( void )
{
return V_45 ;
}
int F_18 ( void )
{
return V_49 ;
}
int F_19 ( void )
{
return V_51 ;
}
unsigned int F_20 ( void )
{
return V_41 ;
}
unsigned int F_21 ( T_4 V_68 )
{
return V_68 ? V_59 : V_61 ;
}
unsigned int F_22 ( void )
{
return V_63 ;
}
unsigned int F_23 ( void )
{
return V_64 ;
}
void T_1 F_24 ( struct V_53 * V_69 )
{
* V_69 = V_53 ;
}
static int T_1 F_25 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
do {
V_3 = F_1 ( V_1 , V_2 ) ;
} while ( V_3 == - V_20 );
if ( V_3 )
return - V_22 ;
if ( ( (struct V_70 * ) V_2 ) -> V_21 != 0x0020 )
return - V_22 ;
return 0 ;
}
static void T_1 F_26 ( struct V_71 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_72 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_73 . V_72 . V_17 = sizeof( struct V_74 ) ;
V_2 -> V_73 . V_72 . type = V_75 ;
V_2 -> V_73 . V_76 = V_77 ;
V_2 -> V_73 . V_78 = V_79 ;
V_2 -> V_73 . V_80 = 4712 ;
V_2 -> V_73 . V_81 = 1 ;
}
static int T_1 F_27 ( struct V_82 * V_2 ,
unsigned long V_83 ,
unsigned long V_84 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_16 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_85 = sizeof( V_86 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_84 = V_84 ;
return F_25 ( V_87 , V_2 ) ;
}
static long T_1 F_28 ( struct V_71 * V_2 )
{
F_26 ( V_2 ) ;
if ( F_25 ( V_88 , V_2 ) )
return - V_22 ;
if ( V_2 -> V_73 . V_89 == 0 )
return 0 ;
return ( V_2 -> V_73 . V_89 - 1 ) * V_90 ;
}
static long T_1 F_29 ( struct V_70 * V_2 )
{
memset ( V_2 , 0 , V_90 ) ;
V_2 -> V_17 = V_90 ;
if ( F_25 ( V_91 , V_2 ) )
return - V_22 ;
if ( ( (struct V_71 * ) V_2 ) -> V_73 . V_89 == 0 )
return 0 ;
return ( ( (struct V_71 * ) V_2 ) -> V_73 . V_89 - 1 ) * V_90 ;
}
unsigned long F_30 ( void )
{
return V_92 ;
}
static void T_1 F_31 ( void * V_2 )
{
long V_93 ;
if ( F_27 ( V_2 , 0 , 0x40000010 ) )
return;
V_93 = F_28 ( V_2 ) ;
if ( V_93 < 0 )
return;
if ( V_93 != 0 )
goto V_4;
if ( F_27 ( V_2 , 0x00000010 , 0x40000010 ) )
return;
V_93 = F_28 ( V_2 ) ;
if ( V_93 < 0 )
return;
V_93 = F_29 ( V_2 ) ;
if ( V_93 < 0 )
return;
V_4:
V_92 = V_93 ;
}
static unsigned int T_1 F_32 ( struct V_82 * V_2 )
{
if ( ! ( V_2 -> V_94 & V_95 ) )
return 0 ;
if ( ! ( V_2 -> V_96 & ( V_97 | V_98 ) ) )
return 0 ;
return 1 ;
}
static void T_1 F_33 ( struct V_82 * V_2 )
{
if ( V_2 -> V_16 . V_21 != 0x20 )
return;
if ( V_2 -> V_94 & V_99 )
V_67 = 1 ;
if ( F_32 ( V_2 ) )
V_66 = 1 ;
}
void T_1 F_34 ( void )
{
void * V_2 = & V_100 ;
F_10 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( V_2 , 0 , 0 ) ;
F_33 ( V_2 ) ;
}
