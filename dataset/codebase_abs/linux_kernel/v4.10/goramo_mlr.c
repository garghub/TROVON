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
F_8 ( V_2 , 1 ) ;
F_8 ( V_3 , 1 ) ;
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
static int F_9 ( int V_7 , unsigned int V_8 )
{
int V_9 = V_7 ? V_10 : V_11 ;
switch ( V_8 ) {
case V_12 :
case V_13 :
F_6 ( V_9 , 0 ) ;
F_7 () ;
return V_13 ;
case V_14 :
F_6 ( V_9 , 1 ) ;
F_7 () ;
return V_14 ;
default:
return - V_15 ;
}
}
static T_2 F_10 ( int V_16 , void * V_17 )
{
int V_7 = ( V_16 == F_11 ( V_18 ) ) ;
int V_6 = F_12 ( V_7 ? V_18 : V_19 ) ;
V_20 [ V_7 ] ( V_17 , ! V_6 ) ;
return V_21 ;
}
static int F_13 ( int V_7 , void * V_17 ,
void (* F_14)( void * V_17 , int V_22 ) )
{
int V_6 , V_16 ;
if ( ! V_7 )
V_16 = F_11 ( V_19 ) ;
else
V_16 = F_11 ( V_18 ) ;
V_6 = F_12 ( V_7 ? V_18 : V_19 ) ;
F_14 ( V_17 , ! V_6 ) ;
V_20 [ ! ! V_7 ] = F_14 ;
if ( ( V_6 = F_15 ( V_16 , F_10 , 0 , L_1 , V_17 ) ) != 0 ) {
F_16 ( V_23 L_2 ,
V_16 , V_6 ) ;
return V_6 ;
}
F_6 ( V_7 ? V_24 : V_25 , 0 ) ;
F_7 () ;
F_2 ( V_7 ? V_26 : V_27 , 0 ) ;
return 0 ;
}
static void F_17 ( int V_7 , void * V_17 )
{
F_18 ( V_7 ? F_11 ( V_18 ) :
F_11 ( V_19 ) , V_17 ) ;
V_20 [ ! ! V_7 ] = NULL ;
F_6 ( V_7 ? V_24 : V_25 , 1 ) ;
F_7 () ;
F_2 ( V_7 ? V_26 : V_27 , 1 ) ;
}
static inline T_1 T_3 F_19 ( T_1 T_4 * V_28 , T_5 V_29 )
{
#ifdef F_20
return F_21 ( V_28 + V_29 ) ;
#else
return F_21 ( V_28 + ( V_29 ^ 3 ) ) ;
#endif
}
static inline T_6 T_3 F_22 ( T_1 T_4 * V_28 , T_5 V_29 )
{
#ifdef F_20
return F_23 ( V_28 + V_29 ) ;
#else
return F_23 ( V_28 + ( V_29 ^ 2 ) ) ;
#endif
}
static void T_3 F_24 ( void )
{
T_1 T_4 * V_28 ;
int V_6 , V_30 = 1 ;
F_25 () ;
if ( ( V_28 = F_26 ( V_31 , 0x80 ) ) == NULL )
F_16 ( V_23 L_3
L_4 ) ;
else {
V_32 = F_27 ( V_28 + V_33 ) ;
V_34 = F_27 ( V_28 + V_35 ) ;
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ ) {
V_37 [ 0 ] . V_38 [ V_6 ] =
F_19 ( V_28 , V_39 + V_6 ) ;
V_37 [ 1 ] . V_38 [ V_6 ] =
F_19 ( V_28 , V_40 + V_6 ) ;
}
F_28 ( V_41 , V_28 ) ;
V_42 = F_22 ( V_28 , V_43 ) ;
V_42 <<= 16 ;
V_42 |= F_22 ( V_28 , V_43 + 2 ) ;
V_44 = F_22 ( V_28 , V_43 + 4 ) ;
V_44 <<= 16 ;
V_44 |= F_22 ( V_28 , V_43 + 6 ) ;
F_28 ( V_45 , V_28 ) ;
F_29 ( V_28 ) ;
}
switch ( V_34 & ( V_46 | V_47 ) ) {
case V_46 :
memset ( & V_48 [ 1 ] , 0 , sizeof( V_48 [ 1 ] ) ) ;
V_49 . V_50 = 1 ;
break;
case V_47 :
V_49 . V_51 . V_52 = & V_48 [ 1 ] ;
V_49 . V_53 = & V_54 [ 1 ] ;
V_49 . V_50 = 1 ;
break;
}
if ( V_34 & ( V_46 | V_47 ) )
V_55 [ V_30 ++ ] = & V_49 ;
if ( V_34 & V_56 )
V_55 [ V_30 ++ ] = & V_57 [ 0 ] ;
if ( V_34 & V_58 )
V_55 [ V_30 ++ ] = & V_57 [ 1 ] ;
if ( V_34 & V_59 )
V_55 [ V_30 ++ ] = & V_60 [ 0 ] ;
if ( V_34 & V_61 )
V_55 [ V_30 ++ ] = & V_60 [ 1 ] ;
if ( V_34 & V_62 )
V_55 [ V_30 ++ ] = & V_63 ;
F_30 ( V_2 , L_5 ) ;
F_30 ( V_3 , L_6 ) ;
F_30 ( V_4 , L_7 ) ;
F_30 ( V_27 , L_8 ) ;
F_30 ( V_26 , L_9 ) ;
F_30 ( V_19 , L_10 ) ;
F_30 ( V_18 , L_11 ) ;
F_8 ( V_2 , 1 ) ;
F_8 ( V_3 , 1 ) ;
F_8 ( V_4 , 0 ) ;
F_8 ( V_27 , 1 ) ;
F_8 ( V_26 , 1 ) ;
F_31 ( V_19 ) ;
F_31 ( V_18 ) ;
F_32 ( F_11 ( V_19 ) , V_64 ) ;
F_32 ( F_11 ( V_18 ) , V_64 ) ;
F_6 ( V_25 , 1 ) ;
F_6 ( V_24 , 1 ) ;
F_6 ( V_65 , 1 ) ;
F_6 ( V_66 , 1 ) ;
F_7 () ;
F_33 ( 1 ) ;
V_67 . V_68 = F_34 ( 0 ) ;
V_67 . V_69 = F_34 ( 0 ) + V_70 - 1 ;
F_35 ( V_55 , V_30 ) ;
}
static void T_3 F_36 ( void )
{
F_32 ( F_11 ( V_71 ) , V_72 ) ;
F_32 ( F_11 ( V_73 ) , V_72 ) ;
F_32 ( F_11 ( V_74 ) , V_72 ) ;
F_32 ( F_11 ( V_75 ) , V_72 ) ;
F_37 () ;
}
static void T_3 F_38 ( void )
{
if ( ( V_34 & V_76 ) >= 2 &&
( V_34 & V_76 ) < 5 ) {
T_5 V_1 , V_29 = F_39 ( 32 - V_77 ) | 0xE0 ;
if ( ! F_40 ( V_29 , V_78 , & V_1 ) ) {
V_1 &= ~ 7 ;
V_1 |= ( V_34 & V_76 ) ;
F_41 ( V_29 , V_79 , V_1 ) ;
}
}
}
static int T_3 F_42 ( const struct V_80 * V_51 , T_1 V_81 , T_1 V_82 )
{
switch( V_81 ) {
case V_83 : return F_11 ( V_71 ) ;
case V_84 : return F_11 ( V_73 ) ;
case V_77 : return F_11 ( V_74 ) ;
default: return F_11 ( V_75 ) ;
}
}
static int T_3 F_43 ( void )
{
if ( F_44 () &&
( V_34 & ( V_76 | V_85 ) ) )
F_45 ( & V_86 ) ;
return 0 ;
}
