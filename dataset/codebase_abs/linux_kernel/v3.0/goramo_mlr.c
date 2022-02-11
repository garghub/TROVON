static void F_1 ( T_1 V_1 )
{
F_2 ( V_2 , ! ! V_1 ) ;
F_3 ( 3 ) ;
}
static void F_4 ( T_1 V_1 )
{
F_2 ( V_3 , ! ! V_1 ) ;
F_3 ( 3 ) ;
}
static void F_5 ( T_1 V_1 )
{
F_2 ( V_4 , ! ! V_1 ) ;
F_3 ( 3 ) ;
}
static inline void F_6 ( int line , int V_1 )
{
if ( V_1 )
V_5 |= ( 1 << line ) ;
else
V_5 &= ~ ( 1 << line ) ;
}
static void F_7 ( void )
{
int V_6 ;
F_8 ( V_2 , V_7 ) ;
F_8 ( V_3 , V_7 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
F_1 ( 0 ) ;
F_4 ( V_5 & ( 0x80 >> V_6 ) ) ;
F_1 ( 1 ) ;
}
F_5 ( 1 ) ;
F_5 ( 0 ) ;
F_1 ( 0 ) ;
F_4 ( 1 ) ;
F_1 ( 1 ) ;
}
static int F_9 ( int V_8 , unsigned int V_9 )
{
int V_10 = V_8 ? V_11 : V_12 ;
switch ( V_9 ) {
case V_13 :
case V_14 :
F_6 ( V_10 , 0 ) ;
F_7 () ;
return V_14 ;
case V_15 :
F_6 ( V_10 , 1 ) ;
F_7 () ;
return V_15 ;
default:
return - V_16 ;
}
}
static T_2 F_10 ( int V_17 , void * V_18 )
{
int V_6 , V_8 = ( V_17 == F_11 ( V_19 ) ) ;
F_12 ( V_8 ? V_19 : V_20 , & V_6 ) ;
V_21 [ V_8 ] ( V_18 , ! V_6 ) ;
return V_22 ;
}
static int F_13 ( int V_8 , void * V_18 ,
void (* F_14)( void * V_18 , int V_23 ) )
{
int V_6 , V_17 ;
if ( ! V_8 )
V_17 = F_11 ( V_20 ) ;
else
V_17 = F_11 ( V_19 ) ;
F_12 ( V_8 ? V_19 : V_20 , & V_6 ) ;
F_14 ( V_18 , ! V_6 ) ;
V_21 [ ! ! V_8 ] = F_14 ;
if ( ( V_6 = F_15 ( V_17 , F_10 , 0 , L_1 , V_18 ) ) != 0 ) {
F_16 ( V_24 L_2 ,
V_17 , V_6 ) ;
return V_6 ;
}
F_6 ( V_8 ? V_25 : V_26 , 0 ) ;
F_7 () ;
F_2 ( V_8 ? V_27 : V_28 , 0 ) ;
return 0 ;
}
static void F_17 ( int V_8 , void * V_18 )
{
F_18 ( V_8 ? F_11 ( V_19 ) :
F_11 ( V_20 ) , V_18 ) ;
V_21 [ ! ! V_8 ] = NULL ;
F_6 ( V_8 ? V_25 : V_26 , 1 ) ;
F_7 () ;
F_2 ( V_8 ? V_27 : V_28 , 1 ) ;
}
static inline T_1 T_3 F_19 ( T_1 T_4 * V_29 , T_5 V_30 )
{
#ifdef F_20
return F_21 ( V_29 + V_30 ) ;
#else
return F_21 ( V_29 + ( V_30 ^ 3 ) ) ;
#endif
}
static inline T_6 T_3 F_22 ( T_1 T_4 * V_29 , T_5 V_30 )
{
#ifdef F_20
return F_23 ( V_29 + V_30 ) ;
#else
return F_23 ( V_29 + ( V_30 ^ 2 ) ) ;
#endif
}
static void T_3 F_24 ( void )
{
T_1 T_4 * V_29 ;
int V_6 , V_31 = 1 ;
F_25 () ;
if ( ( V_29 = F_26 ( V_32 , 0x80 ) ) == NULL )
F_16 ( V_24 L_3
L_4 ) ;
else {
V_33 = F_27 ( V_29 + V_34 ) ;
V_35 = F_27 ( V_29 + V_36 ) ;
for ( V_6 = 0 ; V_6 < V_37 ; V_6 ++ ) {
V_38 [ 0 ] . V_39 [ V_6 ] =
F_19 ( V_29 , V_40 + V_6 ) ;
V_38 [ 1 ] . V_39 [ V_6 ] =
F_19 ( V_29 , V_41 + V_6 ) ;
}
F_28 ( V_42 , V_29 ) ;
V_43 = F_22 ( V_29 , V_44 ) ;
V_43 <<= 16 ;
V_43 |= F_22 ( V_29 , V_44 + 2 ) ;
V_45 = F_22 ( V_29 , V_44 + 4 ) ;
V_45 <<= 16 ;
V_45 |= F_22 ( V_29 , V_44 + 6 ) ;
F_28 ( V_46 , V_29 ) ;
F_29 ( V_29 ) ;
}
switch ( V_35 & ( V_47 | V_48 ) ) {
case V_47 :
memset ( & V_49 [ 1 ] , 0 , sizeof( V_49 [ 1 ] ) ) ;
V_50 . V_51 = 1 ;
break;
case V_48 :
V_50 . V_52 . V_53 = & V_49 [ 1 ] ;
V_50 . V_54 = & V_55 [ 1 ] ;
V_50 . V_51 = 1 ;
break;
}
if ( V_35 & ( V_47 | V_48 ) )
V_56 [ V_31 ++ ] = & V_50 ;
if ( V_35 & V_57 )
V_56 [ V_31 ++ ] = & V_58 [ 0 ] ;
if ( V_35 & V_59 )
V_56 [ V_31 ++ ] = & V_58 [ 1 ] ;
if ( V_35 & V_60 )
V_56 [ V_31 ++ ] = & V_61 [ 0 ] ;
if ( V_35 & V_62 )
V_56 [ V_31 ++ ] = & V_61 [ 1 ] ;
if ( V_35 & V_63 )
V_56 [ V_31 ++ ] = & V_64 ;
F_8 ( V_2 , V_7 ) ;
F_8 ( V_3 , V_7 ) ;
F_8 ( V_4 , V_7 ) ;
F_8 ( V_28 , V_7 ) ;
F_8 ( V_27 , V_7 ) ;
F_8 ( V_20 , V_65 ) ;
F_8 ( V_19 , V_65 ) ;
F_30 ( F_11 ( V_20 ) , V_66 ) ;
F_30 ( F_11 ( V_19 ) , V_66 ) ;
F_6 ( V_26 , 1 ) ;
F_6 ( V_25 , 1 ) ;
F_6 ( V_67 , 1 ) ;
F_6 ( V_68 , 1 ) ;
F_7 () ;
F_31 ( 1 ) ;
V_69 . V_70 = F_32 ( 0 ) ;
V_69 . V_71 = F_32 ( 0 ) + V_72 - 1 ;
F_33 ( V_56 , V_31 ) ;
}
static void T_3 F_34 ( void )
{
F_30 ( F_11 ( V_73 ) , V_74 ) ;
F_30 ( F_11 ( V_75 ) , V_74 ) ;
F_30 ( F_11 ( V_76 ) , V_74 ) ;
F_30 ( F_11 ( V_77 ) , V_74 ) ;
F_35 () ;
}
static void T_3 F_36 ( void )
{
if ( ( V_35 & V_78 ) >= 2 &&
( V_35 & V_78 ) < 5 ) {
T_5 V_1 , V_30 = F_37 ( 32 - V_79 ) | 0xE0 ;
if ( ! F_38 ( V_30 , V_80 , & V_1 ) ) {
V_1 &= ~ 7 ;
V_1 |= ( V_35 & V_78 ) ;
F_39 ( V_30 , V_81 , V_1 ) ;
}
}
}
static int T_3 F_40 ( struct V_82 * V_52 , T_1 V_83 , T_1 V_84 )
{
switch( V_83 ) {
case V_85 : return F_11 ( V_73 ) ;
case V_86 : return F_11 ( V_75 ) ;
case V_79 : return F_11 ( V_76 ) ;
default: return F_11 ( V_77 ) ;
}
}
static int T_3 F_41 ( void )
{
if ( F_42 () &&
( V_35 & ( V_78 | V_87 ) ) )
F_43 ( & V_88 ) ;
return 0 ;
}
