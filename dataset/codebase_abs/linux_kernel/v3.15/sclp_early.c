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
if ( F_8 ( V_2 ) )
return;
V_23 = V_2 -> V_24 ;
V_25 = V_2 -> V_26 ;
if ( V_2 -> V_27 & 0x02 )
V_28 . V_29 |= V_30 ;
V_31 = V_2 -> V_32 ? V_2 -> V_32 : V_2 -> V_33 ;
V_34 = V_2 -> V_35 ? V_2 -> V_35 : V_2 -> V_36 ;
V_34 <<= 20 ;
if ( ! V_2 -> V_37 ) {
if ( V_38 )
V_39 = 64 ;
else
V_39 = V_2 -> V_40 ;
} else {
V_39 = V_2 -> V_37 + 1 ;
}
V_41 . V_42 = 1 ;
if ( V_2 -> V_43 & 0x2 )
V_41 . V_44 = 1 ;
memcpy ( & V_41 . V_45 , & V_2 -> V_45 , V_46 ) ;
}
bool T_1 F_11 ( void )
{
return ! ! V_47 ;
}
bool T_1 F_12 ( void )
{
return ! ! V_48 ;
}
unsigned long long F_13 ( void )
{
return V_31 ;
}
unsigned long long F_14 ( void )
{
return V_34 ;
}
unsigned int F_15 ( void )
{
return V_39 ;
}
void T_1 F_16 ( struct V_41 * V_49 )
{
* V_49 = V_41 ;
}
static int T_1 F_17 ( T_2 V_1 , void * V_2 )
{
int V_3 ;
do {
V_3 = F_1 ( V_1 , V_2 ) ;
} while ( V_3 == - V_20 );
if ( V_3 )
return - V_22 ;
if ( ( (struct V_50 * ) V_2 ) -> V_21 != 0x0020 )
return - V_22 ;
return 0 ;
}
static void T_1 F_18 ( struct V_51 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_52 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_53 . V_52 . V_17 = sizeof( struct V_54 ) ;
V_2 -> V_53 . V_52 . type = V_55 ;
V_2 -> V_53 . V_56 = V_57 ;
V_2 -> V_53 . V_58 = V_59 ;
V_2 -> V_53 . V_60 = 4712 ;
V_2 -> V_53 . V_61 = 1 ;
}
static int T_1 F_19 ( struct V_62 * V_2 ,
unsigned long V_63 ,
unsigned long V_64 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_16 . V_17 = sizeof( * V_2 ) ;
V_2 -> V_65 = sizeof( V_66 ) ;
V_2 -> V_63 = V_63 ;
V_2 -> V_64 = V_64 ;
return F_17 ( V_67 , V_2 ) ;
}
static long T_1 F_20 ( struct V_51 * V_2 )
{
F_18 ( V_2 ) ;
if ( F_17 ( V_68 , V_2 ) )
return - V_22 ;
if ( V_2 -> V_53 . V_69 == 0 )
return 0 ;
return ( V_2 -> V_53 . V_69 - 1 ) * V_70 ;
}
static long T_1 F_21 ( struct V_50 * V_2 )
{
memset ( V_2 , 0 , V_70 ) ;
V_2 -> V_17 = V_70 ;
if ( F_17 ( V_71 , V_2 ) )
return - V_22 ;
if ( ( (struct V_51 * ) V_2 ) -> V_53 . V_69 == 0 )
return 0 ;
return ( ( (struct V_51 * ) V_2 ) -> V_53 . V_69 - 1 ) * V_70 ;
}
unsigned long F_22 ( void )
{
return V_72 ;
}
static void T_1 F_23 ( void * V_2 )
{
long V_73 ;
if ( F_19 ( V_2 , 0 , 0x40000010 ) )
return;
V_73 = F_20 ( V_2 ) ;
if ( V_73 < 0 )
return;
if ( V_73 != 0 )
goto V_4;
if ( F_19 ( V_2 , 0x00000010 , 0x40000010 ) )
return;
V_73 = F_20 ( V_2 ) ;
if ( V_73 < 0 )
return;
V_73 = F_21 ( V_2 ) ;
if ( V_73 < 0 )
return;
V_4:
V_72 = V_73 ;
}
static unsigned int T_1 F_24 ( struct V_62 * V_2 )
{
if ( ! ( V_2 -> V_74 & ( V_75 | V_76 ) ) )
return 0 ;
if ( ! ( V_2 -> V_77 & ( V_78 | V_76 ) ) )
return 0 ;
return 1 ;
}
static void T_1 F_25 ( struct V_62 * V_2 )
{
if ( V_2 -> V_16 . V_21 != 0x20 )
return;
if ( V_2 -> V_74 & V_79 )
V_48 = 1 ;
if ( F_24 ( V_2 ) )
V_47 = 1 ;
}
void T_1 F_26 ( void )
{
void * V_2 = & V_80 ;
F_10 ( V_2 ) ;
F_23 ( V_2 ) ;
F_19 ( V_2 , 0 , 0 ) ;
F_25 ( V_2 ) ;
}
