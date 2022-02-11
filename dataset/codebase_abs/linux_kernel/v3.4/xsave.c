void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0x2 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 . V_9 -> V_10 ;
if ( ! V_6 )
return;
F_2 ( F_3 ( V_2 ) ) ;
V_3 = V_2 -> V_7 . V_8 . V_9 -> V_11 . V_12 . V_3 ;
if ( ( V_3 & V_13 ) == V_13 )
return;
if ( ! ( V_3 & V_14 ) ) {
V_6 -> V_15 = 0x37f ;
V_6 -> V_16 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
V_6 -> V_20 = 0 ;
memset ( & V_6 -> V_21 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_3 & V_22 ) )
memset ( & V_6 -> V_23 [ 0 ] , 0 , 256 ) ;
V_3 = ( V_13 & ~ V_3 ) >> 2 ;
while ( V_3 ) {
if ( V_3 & 0x1 ) {
int V_24 = V_25 [ V_4 ] ;
int V_26 = V_27 [ V_4 ] ;
memcpy ( ( ( void * ) V_6 ) + V_24 ,
( ( void * ) V_28 ) + V_24 ,
V_26 ) ;
}
V_3 >>= 1 ;
V_4 ++ ;
}
}
int F_4 ( struct V_5 T_2 * V_29 ,
void T_2 * V_30 ,
struct V_31 * V_32 )
{
int V_33 = sizeof( struct V_5 ) +
sizeof( struct V_34 ) ;
unsigned int V_35 ;
int V_36 ;
V_36 = F_5 ( V_32 , & V_29 -> V_37 [ 0 ] ,
sizeof( struct V_31 ) ) ;
if ( V_36 )
return - V_38 ;
if ( V_32 -> V_39 != V_40 )
return - V_41 ;
if ( V_32 -> V_42 < V_33 ||
V_32 -> V_42 > V_42 ||
V_32 -> V_42 > V_32 -> V_43 )
return - V_41 ;
V_36 = F_6 ( V_35 , ( V_44 * ) ( ( ( void * ) V_30 ) +
V_32 -> V_43 -
V_45 ) ) ;
if ( V_36 )
return V_36 ;
if ( V_35 != V_46 )
return - V_38 ;
return 0 ;
}
int F_7 ( void T_2 * V_29 )
{
struct V_1 * V_2 = V_47 ;
int V_36 = 0 ;
if ( ! F_8 ( V_48 , V_29 , V_49 ) )
return - V_50 ;
F_2 ( V_49 < V_42 ) ;
if ( ( unsigned long ) V_29 % 64 )
F_9 ( L_1 , V_29 ) ;
if ( ! F_10 () )
return 0 ;
if ( F_11 () ) {
if ( F_12 () )
V_36 = F_13 ( V_29 ) ;
else
V_36 = F_14 ( V_29 ) ;
if ( V_36 )
return V_36 ;
F_15 () ;
} else {
F_16 ( V_2 ) ;
if ( F_17 ( V_29 , & V_2 -> V_7 . V_8 . V_9 -> V_10 ,
V_42 ) )
return - 1 ;
}
F_18 () ;
if ( F_12 () ) {
struct V_51 T_2 * V_6 = V_29 ;
struct V_52 T_2 * V_53 = V_29 ;
T_1 V_3 ;
V_36 = F_17 ( & V_6 -> V_37 , & V_54 ,
sizeof( struct V_31 ) ) ;
V_36 |= F_19 ( V_46 ,
( V_44 T_2 * ) ( V_29 + V_49
- V_45 ) ) ;
V_36 |= F_6 ( V_3 , & V_53 -> V_55 . V_3 ) ;
V_3 |= V_56 ;
V_36 |= F_19 ( V_3 , & V_53 -> V_55 . V_3 ) ;
if ( V_36 )
return V_36 ;
}
return 1 ;
}
static int F_20 ( void T_2 * V_29 )
{
struct V_31 V_32 ;
T_1 V_57 ;
int V_36 ;
if ( ( ( unsigned long ) V_29 % 64 ) ||
F_4 ( V_29 , V_29 , & V_32 ) )
goto V_58;
V_57 = V_32 . V_3 ;
V_36 = F_21 ( V_29 , V_57 ) ;
if ( V_36 )
return V_36 ;
V_57 = V_13 & ~ V_57 ;
if ( F_22 ( V_57 ) )
F_23 ( V_28 , V_57 ) ;
return 0 ;
V_58:
F_23 ( V_28 , V_13 & ~ V_56 ) ;
return F_24 ( ( V_59 struct V_5 * ) V_29 ) ;
}
int F_25 ( void T_2 * V_29 )
{
struct V_1 * V_2 = V_47 ;
int V_36 = 0 ;
if ( ! V_29 ) {
if ( F_10 () )
goto V_60;
return 0 ;
} else
if ( ! F_8 ( V_61 , V_29 , V_49 ) )
return - V_50 ;
if ( ! F_10 () ) {
V_36 = F_26 ( V_2 ) ;
if ( V_36 )
return V_36 ;
}
F_27 () ;
if ( F_12 () )
V_36 = F_20 ( V_29 ) ;
else
V_36 = F_24 ( ( V_59 struct V_5 * )
V_29 ) ;
if ( F_22 ( V_36 ) ) {
V_60:
F_28 ( V_2 ) ;
F_18 () ;
}
return V_36 ;
}
static void F_29 ( void )
{
int V_62 = ( V_42 - sizeof( struct V_5 ) ) +
V_45 ;
V_49 = sizeof( struct V_51 ) + V_62 ;
#ifdef F_30
V_63 = sizeof( struct V_64 ) + V_62 ;
#endif
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_39 = V_40 ;
V_54 . V_43 = V_49 ;
V_54 . V_3 = V_13 ;
V_54 . V_42 = V_42 ;
#ifdef F_30
memcpy ( & V_65 , & V_54 ,
sizeof( struct V_31 ) ) ;
V_65 . V_43 = V_63 ;
#endif
}
static inline void F_31 ( void )
{
F_32 ( V_66 ) ;
F_33 ( V_67 , V_13 ) ;
}
static void T_3 F_34 ( void )
{
int V_68 , V_69 , V_70 , V_71 , V_72 = 0x2 ;
V_73 = F_35 ( V_13 ) ;
V_25 = F_36 ( V_73 * sizeof( int ) ) ;
V_27 = F_36 ( V_73 * sizeof( int ) ) ;
do {
F_37 ( V_74 , V_72 , & V_68 , & V_69 , & V_70 , & V_71 ) ;
if ( V_68 == 0 )
break;
V_25 [ V_72 ] = V_69 ;
V_27 [ V_72 ] = V_68 ;
V_72 ++ ;
} while ( 1 );
}
static void T_3 F_38 ( void )
{
F_34 () ;
V_28 = F_39 ( V_42 ,
F_40 ( struct V_75 ) ) ;
V_28 -> V_76 . V_77 = V_78 ;
F_41 () ;
F_23 ( V_28 , - 1 ) ;
F_42 ( V_28 , - 1 ) ;
F_43 () ;
}
static void T_3 F_44 ( void )
{
unsigned int V_68 , V_69 , V_70 , V_71 ;
if ( V_79 . V_80 < V_74 ) {
F_45 ( 1 , V_81 L_2 ) ;
return;
}
F_37 ( V_74 , 0 , & V_68 , & V_69 , & V_70 , & V_71 ) ;
V_13 = V_68 + ( ( T_1 ) V_71 << 32 ) ;
if ( ( V_13 & V_56 ) != V_56 ) {
F_9 ( V_81 L_3 ,
V_13 ) ;
F_46 () ;
}
V_13 = V_13 & V_82 ;
F_31 () ;
F_37 ( V_74 , 0 , & V_68 , & V_69 , & V_70 , & V_71 ) ;
V_42 = V_69 ;
F_47 ( V_42 , V_13 ) ;
F_29 () ;
F_38 () ;
F_9 ( V_83 L_4
L_5 ,
V_13 , V_42 ) ;
}
void T_4 F_48 ( void )
{
static T_5 void (* F_49)( void ) = F_44 ;
void (* F_50)( void );
if ( ! V_84 )
return;
F_50 = F_49 ;
F_49 = F_31 ;
F_50 () ;
}
