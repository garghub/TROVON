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
static void T_1 F_8 ( void )
{
int V_3 ;
int V_11 ;
struct V_12 * V_2 ;
T_2 V_13 [] = { V_14 ,
V_15 } ;
V_2 = & V_16 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_13 ) ; V_11 ++ ) {
do {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_17 . V_19 = 0x80 ;
V_2 -> V_17 . V_20 [ 2 ] = 0x80 ;
V_3 = F_1 ( V_13 [ V_11 ] , V_2 ) ;
} while ( V_3 == - V_21 );
if ( V_3 )
break;
if ( V_2 -> V_17 . V_22 == 0x10 ) {
V_23 = 1 ;
break;
}
if ( V_2 -> V_17 . V_22 != 0x1f0 )
break;
}
}
static void T_1 F_10 ( void )
{
struct V_12 * V_2 ;
F_8 () ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_24 = V_2 -> V_25 ;
V_26 = V_2 -> V_27 ;
if ( V_2 -> V_28 & 0x02 )
V_29 . V_30 |= V_31 ;
V_32 = V_2 -> V_33 ? V_2 -> V_33 : V_2 -> V_34 ;
V_35 = V_2 -> V_36 ? V_2 -> V_36 : V_2 -> V_37 ;
V_35 <<= 20 ;
}
bool T_1 F_11 ( void )
{
struct V_38 * V_2 = ( void * ) & V_39 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( ! ( V_2 -> V_40 & ( V_41 | V_42 ) ) )
return 0 ;
if ( ! ( V_2 -> V_43 & ( V_44 | V_42 ) ) )
return 0 ;
return 1 ;
}
bool T_1 F_12 ( void )
{
struct V_38 * V_2 = ( void * ) & V_39 ;
if ( V_2 -> V_17 . V_22 != 0x20 )
return 0 ;
if ( V_2 -> V_40 & V_45 )
return 1 ;
return 0 ;
}
unsigned long long F_13 ( void )
{
return V_32 ;
}
unsigned long long F_14 ( void )
{
return V_35 ;
}
void T_1 F_15 ( struct V_46 * V_47 )
{
struct V_12 * V_2 ;
if ( ! V_23 )
return;
V_2 = & V_16 ;
V_47 -> V_48 = 1 ;
if ( V_2 -> V_49 & 0x2 )
V_47 -> V_50 = 1 ;
memcpy ( & V_47 -> V_51 , & V_2 -> V_51 , V_52 ) ;
}
static int T_1 F_16 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
do {
V_3 = F_1 ( V_1 , V_2 ) ;
} while ( V_3 == - V_21 );
if ( V_3 )
return - V_53 ;
if ( ( (struct V_54 * ) V_2 ) -> V_22 != 0x0020 )
return - V_53 ;
return 0 ;
}
static void T_1 F_17 ( struct V_55 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_56 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_57 . V_56 . V_18 = sizeof( struct V_58 ) ;
V_2 -> V_57 . V_56 . type = V_59 ;
V_2 -> V_57 . V_60 = V_61 ;
V_2 -> V_57 . V_62 = V_63 ;
V_2 -> V_57 . V_64 = 4712 ;
V_2 -> V_57 . V_65 = 1 ;
}
static int T_1 F_18 ( unsigned long V_66 ,
unsigned long V_67 )
{
struct V_38 * V_2 = ( void * ) & V_39 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_17 . V_18 = sizeof( * V_2 ) ;
V_2 -> V_68 = sizeof( V_69 ) ;
V_2 -> V_66 = V_66 ;
V_2 -> V_67 = V_67 ;
return F_16 ( V_70 , V_2 ) ;
}
static long T_1 F_19 ( void )
{
struct V_55 * V_2 = ( void * ) & V_39 ;
F_17 ( V_2 ) ;
if ( F_16 ( V_71 , V_2 ) )
return - V_53 ;
if ( V_2 -> V_57 . V_72 != 0 )
return ( V_2 -> V_57 . V_72 - 1 ) * V_73 ;
return 0 ;
}
static long T_1 F_20 ( void )
{
struct V_54 * V_2 = ( void * ) & V_39 ;
memset ( V_2 , 0 , V_73 ) ;
V_2 -> V_18 = V_73 ;
if ( F_16 ( V_74 , V_2 ) )
return - V_53 ;
return ( ( (struct V_55 * ) V_2 ) -> V_57 . V_72 - 1 ) * V_73 ;
}
unsigned long F_21 ( void )
{
return V_75 ;
}
static void T_1 F_22 ( void )
{
long V_76 ;
if ( F_18 ( 0 , 0x40000010 ) )
return;
V_76 = F_19 () ;
if ( V_76 < 0 )
return;
if ( V_76 != 0 )
goto V_4;
if ( F_18 ( 0x00000010 , 0x40000010 ) )
return;
V_76 = F_19 () ;
if ( V_76 < 0 )
return;
V_76 = F_20 () ;
if ( V_76 < 0 )
return;
V_4:
V_75 = V_76 ;
}
void T_1 F_23 ( void )
{
F_10 () ;
F_22 () ;
F_18 ( 0 , 0 ) ;
}
