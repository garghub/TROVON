void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0x2 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 . V_9 -> V_10 ;
if ( ! V_6 )
return;
F_2 ( F_3 ( V_2 ) -> V_11 & V_12 ) ;
V_3 = V_2 -> V_7 . V_8 . V_9 -> V_13 . V_14 . V_3 ;
if ( ( V_3 & V_15 ) == V_15 )
return;
if ( ! ( V_3 & V_16 ) ) {
V_6 -> V_17 = 0x37f ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
V_6 -> V_20 = 0 ;
V_6 -> V_21 = 0 ;
V_6 -> V_22 = 0 ;
memset ( & V_6 -> V_23 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_3 & V_24 ) )
memset ( & V_6 -> V_25 [ 0 ] , 0 , 256 ) ;
V_3 = ( V_15 & ~ V_3 ) >> 2 ;
while ( V_3 ) {
if ( V_3 & 0x1 ) {
int V_26 = V_27 [ V_4 ] ;
int V_28 = V_29 [ V_4 ] ;
memcpy ( ( ( void * ) V_6 ) + V_26 ,
( ( void * ) V_30 ) + V_26 ,
V_28 ) ;
}
V_3 >>= 1 ;
V_4 ++ ;
}
}
int F_4 ( struct V_5 T_2 * V_31 ,
void T_2 * V_32 ,
struct V_33 * V_34 )
{
int V_35 = sizeof( struct V_5 ) +
sizeof( struct V_36 ) ;
unsigned int V_37 ;
int V_38 ;
V_38 = F_5 ( V_34 , & V_31 -> V_39 [ 0 ] ,
sizeof( struct V_33 ) ) ;
if ( V_38 )
return - V_40 ;
if ( V_34 -> V_41 != V_42 )
return - V_43 ;
if ( V_34 -> V_44 < V_35 ||
V_34 -> V_44 > V_44 ||
V_34 -> V_44 > V_34 -> V_45 )
return - V_43 ;
V_38 = F_6 ( V_37 , ( V_46 * ) ( ( ( void * ) V_32 ) +
V_34 -> V_45 -
V_47 ) ) ;
if ( V_38 )
return V_38 ;
if ( V_37 != V_48 )
return - V_40 ;
return 0 ;
}
int F_7 ( void T_2 * V_31 )
{
struct V_1 * V_2 = V_49 ;
int V_38 = 0 ;
if ( ! F_8 ( V_50 , V_31 , V_51 ) )
return - V_52 ;
F_2 ( V_51 < V_44 ) ;
if ( ( unsigned long ) V_31 % 64 )
F_9 ( L_1 , V_31 ) ;
if ( ! F_10 () )
return 0 ;
if ( F_3 ( V_2 ) -> V_11 & V_12 ) {
if ( F_11 () )
V_38 = F_12 ( V_31 ) ;
else
V_38 = F_13 ( V_31 ) ;
if ( V_38 )
return V_38 ;
F_3 ( V_2 ) -> V_11 &= ~ V_12 ;
F_14 () ;
} else {
F_15 ( V_2 ) ;
if ( F_16 ( V_31 , & V_2 -> V_7 . V_8 . V_9 -> V_10 ,
V_44 ) )
return - 1 ;
}
F_17 () ;
if ( F_11 () ) {
struct V_53 T_2 * V_6 = V_31 ;
struct V_54 T_2 * V_55 = V_31 ;
T_1 V_3 ;
V_38 = F_16 ( & V_6 -> V_39 , & V_56 ,
sizeof( struct V_33 ) ) ;
V_38 |= F_18 ( V_48 ,
( V_46 T_2 * ) ( V_31 + V_51
- V_47 ) ) ;
V_38 |= F_6 ( V_3 , & V_55 -> V_57 . V_3 ) ;
V_3 |= V_58 ;
V_38 |= F_18 ( V_3 , & V_55 -> V_57 . V_3 ) ;
if ( V_38 )
return V_38 ;
}
return 1 ;
}
static int F_19 ( void T_2 * V_31 )
{
struct V_33 V_34 ;
T_1 V_59 ;
int V_38 ;
if ( ( ( unsigned long ) V_31 % 64 ) ||
F_4 ( V_31 , V_31 , & V_34 ) )
goto V_60;
V_59 = V_34 . V_3 ;
V_38 = F_20 ( V_31 , V_59 ) ;
if ( V_38 )
return V_38 ;
V_59 = V_15 & ~ V_59 ;
if ( F_21 ( V_59 ) )
F_22 ( V_30 , V_59 ) ;
return 0 ;
V_60:
F_22 ( V_30 , V_15 & ~ V_58 ) ;
return F_23 ( ( V_61 struct V_5 * ) V_31 ) ;
}
int F_24 ( void T_2 * V_31 )
{
struct V_1 * V_2 = V_49 ;
int V_38 = 0 ;
if ( ! V_31 ) {
if ( F_10 () )
goto V_62;
return 0 ;
} else
if ( ! F_8 ( V_63 , V_31 , V_51 ) )
return - V_52 ;
if ( ! F_10 () ) {
V_38 = F_25 ( V_2 ) ;
if ( V_38 )
return V_38 ;
}
if ( ! ( F_3 ( V_49 ) -> V_11 & V_12 ) ) {
F_26 () ;
F_3 ( V_49 ) -> V_11 |= V_12 ;
}
if ( F_11 () )
V_38 = F_19 ( V_31 ) ;
else
V_38 = F_23 ( ( V_61 struct V_5 * )
V_31 ) ;
if ( F_21 ( V_38 ) ) {
V_62:
F_27 ( V_2 ) ;
F_17 () ;
}
return V_38 ;
}
static void F_28 ( void )
{
int V_64 = ( V_44 - sizeof( struct V_5 ) ) +
V_47 ;
V_51 = sizeof( struct V_53 ) + V_64 ;
#ifdef F_29
V_65 = sizeof( struct V_66 ) + V_64 ;
#endif
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_41 = V_42 ;
V_56 . V_45 = V_51 ;
V_56 . V_3 = V_15 ;
V_56 . V_44 = V_44 ;
#ifdef F_29
memcpy ( & V_67 , & V_56 ,
sizeof( struct V_33 ) ) ;
V_67 . V_45 = V_65 ;
#endif
}
static inline void F_30 ( void )
{
F_31 ( V_68 ) ;
F_32 ( V_69 , V_15 ) ;
}
static void T_3 F_33 ( void )
{
int V_70 , V_71 , V_72 , V_73 , V_74 = 0x2 ;
V_75 = F_34 ( V_15 ) ;
V_27 = F_35 ( V_75 * sizeof( int ) ) ;
V_29 = F_35 ( V_75 * sizeof( int ) ) ;
do {
F_36 ( V_76 , V_74 , & V_70 , & V_71 , & V_72 , & V_73 ) ;
if ( V_70 == 0 )
break;
V_27 [ V_74 ] = V_71 ;
V_29 [ V_74 ] = V_70 ;
V_74 ++ ;
} while ( 1 );
}
static void T_3 F_37 ( void )
{
F_33 () ;
V_30 = F_38 ( V_44 ,
F_39 ( struct V_77 ) ) ;
V_30 -> V_78 . V_79 = V_80 ;
F_26 () ;
F_22 ( V_30 , - 1 ) ;
F_40 ( V_30 , - 1 ) ;
F_14 () ;
}
static void T_3 F_41 ( void )
{
unsigned int V_70 , V_71 , V_72 , V_73 ;
if ( V_81 . V_82 < V_76 ) {
F_42 ( 1 , V_83 L_2 ) ;
return;
}
F_36 ( V_76 , 0 , & V_70 , & V_71 , & V_72 , & V_73 ) ;
V_15 = V_70 + ( ( T_1 ) V_73 << 32 ) ;
if ( ( V_15 & V_58 ) != V_58 ) {
F_9 ( V_83 L_3 ,
V_15 ) ;
F_43 () ;
}
V_15 = V_15 & V_84 ;
F_30 () ;
F_36 ( V_76 , 0 , & V_70 , & V_71 , & V_72 , & V_73 ) ;
V_44 = V_71 ;
F_44 ( V_44 , V_15 ) ;
F_28 () ;
F_37 () ;
F_9 ( V_85 L_4
L_5 ,
V_15 , V_44 ) ;
}
void T_4 F_45 ( void )
{
static T_5 void (* F_46)( void ) = F_41 ;
void (* F_47)( void );
if ( ! V_86 )
return;
F_47 = F_46 ;
F_46 = F_30 ;
F_47 () ;
}
