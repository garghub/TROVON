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
break;
}
V_51 . V_52 = 1 ;
if ( V_2 -> V_53 & 0x2 )
V_51 . V_54 = 1 ;
memcpy ( & V_51 . V_55 , & V_2 -> V_55 , V_56 ) ;
}
bool T_1 F_12 ( void )
{
return ! ! V_57 ;
}
bool T_1 F_13 ( void )
{
return ! ! V_58 ;
}
unsigned long long F_14 ( void )
{
return V_35 ;
}
unsigned long long F_15 ( void )
{
return V_38 ;
}
unsigned int F_16 ( void )
{
return V_45 ;
}
int F_17 ( void )
{
return V_49 ;
}
unsigned int F_18 ( void )
{
return V_41 ;
}
void T_1 F_19 ( struct V_51 * V_59 )
{
* V_59 = V_51 ;
}
static int T_1 F_20 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
do {
V_3 = F_1 ( V_1 , V_2 ) ;
} while ( V_3 == - V_20 );
if ( V_3 )
return - V_22 ;
if ( ( (struct V_60 * ) V_2 ) -> V_21 != 0x0020 )
return - V_22 ;
return 0 ;
}
static void T_1 F_21 ( struct V_61 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_62 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_63 . V_62 . V_17 = sizeof( struct V_64 ) ;
V_2 -> V_63 . V_62 . type = V_65 ;
V_2 -> V_63 . V_66 = V_67 ;
V_2 -> V_63 . V_68 = V_69 ;
V_2 -> V_63 . V_70 = 4712 ;
V_2 -> V_63 . V_71 = 1 ;
}
static int T_1 F_22 ( struct V_72 * V_2 ,
unsigned long V_73 ,
unsigned long V_74 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_16 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_75 = sizeof( V_76 ) ;
V_2 -> V_73 = V_73 ;
V_2 -> V_74 = V_74 ;
return F_20 ( V_77 , V_2 ) ;
}
static long T_1 F_23 ( struct V_61 * V_2 )
{
F_21 ( V_2 ) ;
if ( F_20 ( V_78 , V_2 ) )
return - V_22 ;
if ( V_2 -> V_63 . V_79 == 0 )
return 0 ;
return ( V_2 -> V_63 . V_79 - 1 ) * V_80 ;
}
static long T_1 F_24 ( struct V_60 * V_2 )
{
memset ( V_2 , 0 , V_80 ) ;
V_2 -> V_17 = V_80 ;
if ( F_20 ( V_81 , V_2 ) )
return - V_22 ;
if ( ( (struct V_61 * ) V_2 ) -> V_63 . V_79 == 0 )
return 0 ;
return ( ( (struct V_61 * ) V_2 ) -> V_63 . V_79 - 1 ) * V_80 ;
}
unsigned long F_25 ( void )
{
return V_82 ;
}
static void T_1 F_26 ( void * V_2 )
{
long V_83 ;
if ( F_22 ( V_2 , 0 , 0x40000010 ) )
return;
V_83 = F_23 ( V_2 ) ;
if ( V_83 < 0 )
return;
if ( V_83 != 0 )
goto V_4;
if ( F_22 ( V_2 , 0x00000010 , 0x40000010 ) )
return;
V_83 = F_23 ( V_2 ) ;
if ( V_83 < 0 )
return;
V_83 = F_24 ( V_2 ) ;
if ( V_83 < 0 )
return;
V_4:
V_82 = V_83 ;
}
static unsigned int T_1 F_27 ( struct V_72 * V_2 )
{
if ( ! ( V_2 -> V_84 & ( V_85 | V_86 ) ) )
return 0 ;
if ( ! ( V_2 -> V_87 & ( V_88 | V_86 ) ) )
return 0 ;
return 1 ;
}
static void T_1 F_28 ( struct V_72 * V_2 )
{
if ( V_2 -> V_16 . V_21 != 0x20 )
return;
if ( V_2 -> V_84 & V_89 )
V_58 = 1 ;
if ( F_27 ( V_2 ) )
V_57 = 1 ;
}
void T_1 F_29 ( void )
{
void * V_2 = & V_90 ;
F_10 ( V_2 ) ;
F_26 ( V_2 ) ;
F_22 ( V_2 , 0 , 0 ) ;
F_28 ( V_2 ) ;
}
