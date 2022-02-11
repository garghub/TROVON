void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0x2 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 . V_9 -> V_10 ;
if ( ! V_6 )
return;
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
int F_2 ( struct V_5 T_2 * V_29 ,
void T_2 * V_30 ,
struct V_31 * V_32 )
{
int V_33 = sizeof( struct V_5 ) +
sizeof( struct V_34 ) ;
unsigned int V_35 ;
int V_36 ;
V_36 = F_3 ( V_32 , & V_29 -> V_37 [ 0 ] ,
sizeof( struct V_31 ) ) ;
if ( V_36 )
return - V_38 ;
if ( V_32 -> V_39 != V_40 )
return - V_41 ;
if ( V_32 -> V_42 < V_33 ||
V_32 -> V_42 > V_42 ||
V_32 -> V_42 > V_32 -> V_43 )
return - V_41 ;
V_36 = F_4 ( V_35 , ( V_44 * ) ( ( ( void * ) V_30 ) +
V_32 -> V_43 -
V_45 ) ) ;
if ( V_36 )
return V_36 ;
if ( V_35 != V_46 )
return - V_38 ;
return 0 ;
}
int F_5 ( void T_2 * V_29 )
{
struct V_1 * V_2 = V_47 ;
int V_36 = 0 ;
if ( ! F_6 ( V_48 , V_29 , V_49 ) )
return - V_50 ;
F_7 ( V_49 < V_42 ) ;
if ( ( unsigned long ) V_29 % 64 )
F_8 ( L_1 , V_51 , V_29 ) ;
if ( ! F_9 () )
return 0 ;
if ( F_10 () ) {
if ( F_11 () )
V_36 = F_12 ( V_29 ) ;
else
V_36 = F_13 ( V_29 ) ;
if ( V_36 )
return V_36 ;
F_14 () ;
} else {
F_15 ( V_2 ) ;
if ( F_16 ( V_29 , & V_2 -> V_7 . V_8 . V_9 -> V_10 ,
V_42 ) )
return - 1 ;
}
F_17 () ;
if ( F_11 () ) {
struct V_52 T_2 * V_6 = V_29 ;
struct V_53 T_2 * V_54 = V_29 ;
T_1 V_3 ;
V_36 = F_16 ( & V_6 -> V_37 , & V_55 ,
sizeof( struct V_31 ) ) ;
V_36 |= F_18 ( V_46 ,
( V_44 T_2 * ) ( V_29 + V_49
- V_45 ) ) ;
V_36 |= F_4 ( V_3 , & V_54 -> V_56 . V_3 ) ;
V_3 |= V_57 ;
V_36 |= F_18 ( V_3 , & V_54 -> V_56 . V_3 ) ;
if ( V_36 )
return V_36 ;
}
return 1 ;
}
static int F_19 ( void T_2 * V_29 )
{
struct V_31 V_32 ;
T_1 V_58 ;
int V_36 ;
if ( ( ( unsigned long ) V_29 % 64 ) ||
F_2 ( V_29 , V_29 , & V_32 ) )
goto V_59;
V_58 = V_32 . V_3 ;
V_36 = F_20 ( V_29 , V_58 ) ;
if ( V_36 )
return V_36 ;
V_58 = V_13 & ~ V_58 ;
if ( F_21 ( V_58 ) )
F_22 ( V_28 , V_58 ) ;
return 0 ;
V_59:
F_22 ( V_28 , V_13 & ~ V_57 ) ;
return F_23 ( ( V_60 struct V_5 * ) V_29 ) ;
}
int F_24 ( void T_2 * V_29 )
{
struct V_1 * V_2 = V_47 ;
int V_36 = 0 ;
if ( ! V_29 ) {
if ( F_9 () )
goto V_61;
return 0 ;
} else
if ( ! F_6 ( V_62 , V_29 , V_49 ) )
return - V_50 ;
if ( ! F_9 () ) {
V_36 = F_25 ( V_2 ) ;
if ( V_36 )
return V_36 ;
}
F_26 () ;
if ( F_11 () )
V_36 = F_19 ( V_29 ) ;
else
V_36 = F_23 ( ( V_60 struct V_5 * )
V_29 ) ;
if ( F_21 ( V_36 ) ) {
V_61:
F_27 ( V_2 ) ;
F_17 () ;
}
return V_36 ;
}
static void F_28 ( void )
{
int V_63 = ( V_42 - sizeof( struct V_5 ) ) +
V_45 ;
V_49 = sizeof( struct V_52 ) + V_63 ;
#ifdef F_29
V_64 = sizeof( struct V_65 ) + V_63 ;
#endif
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_39 = V_40 ;
V_55 . V_43 = V_49 ;
V_55 . V_3 = V_13 ;
V_55 . V_42 = V_42 ;
#ifdef F_29
memcpy ( & V_66 , & V_55 ,
sizeof( struct V_31 ) ) ;
V_66 . V_43 = V_64 ;
#endif
}
static inline void F_30 ( void )
{
F_31 ( V_67 ) ;
F_32 ( V_68 , V_13 ) ;
}
static void T_3 F_33 ( void )
{
int V_69 , V_70 , V_71 , V_72 , V_73 = 0x2 ;
V_74 = F_34 ( V_13 ) ;
V_25 = F_35 ( V_74 * sizeof( int ) ) ;
V_27 = F_35 ( V_74 * sizeof( int ) ) ;
do {
F_36 ( V_75 , V_73 , & V_69 , & V_70 , & V_71 , & V_72 ) ;
if ( V_69 == 0 )
break;
V_25 [ V_73 ] = V_70 ;
V_27 [ V_73 ] = V_69 ;
V_73 ++ ;
} while ( 1 );
}
static void T_3 F_37 ( void )
{
F_33 () ;
V_28 = F_38 ( V_42 ,
F_39 ( struct V_76 ) ) ;
V_28 -> V_77 . V_78 = V_79 ;
F_40 () ;
F_22 ( V_28 , - 1 ) ;
F_41 ( V_28 , - 1 ) ;
F_42 () ;
}
static void T_3 F_43 ( void )
{
unsigned int V_69 , V_70 , V_71 , V_72 ;
if ( V_80 . V_81 < V_75 ) {
F_44 ( 1 , V_82 L_2 ) ;
return;
}
F_36 ( V_75 , 0 , & V_69 , & V_70 , & V_71 , & V_72 ) ;
V_13 = V_69 + ( ( T_1 ) V_72 << 32 ) ;
if ( ( V_13 & V_57 ) != V_57 ) {
F_8 ( L_3 ,
V_13 ) ;
F_45 () ;
}
V_13 = V_13 & V_83 ;
F_30 () ;
F_36 ( V_75 , 0 , & V_69 , & V_70 , & V_71 , & V_72 ) ;
V_42 = V_70 ;
F_46 ( V_42 , V_13 ) ;
F_28 () ;
F_37 () ;
F_47 ( L_4 ,
V_13 , V_42 ) ;
}
void T_4 F_48 ( void )
{
static T_5 void (* F_49)( void ) = F_43 ;
void (* F_50)( void );
if ( ! V_84 )
return;
F_50 = F_49 ;
F_49 = F_30 ;
F_50 () ;
}
