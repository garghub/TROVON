static inline bool F_1 ( T_1 V_1 )
{
return ! ( V_1 & V_2 ) ;
}
static inline void F_2 ( void )
{
if ( V_3 ) {
F_3 ( V_4 ) ;
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) | V_7 ) ;
} else
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) & ~ V_7 ) ;
}
static inline void F_6 ( void )
{
if ( V_3 ) {
F_3 ( V_4 ) ;
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) | V_7 | V_8 ) ;
} else
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) & ~ ( V_7 | V_8 ) ) ;
}
static inline void F_7 ( void )
{
if ( V_3 ) {
F_3 ( V_9 ) ;
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) | V_8 ) ;
} else
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) & ~ V_8 ) ;
}
static inline void F_8 ( void )
{
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) ^ V_8 ) ;
}
static inline void F_9 ( void )
{
if ( V_3 ) {
F_3 ( V_10 ) ;
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) & ~ V_8 ) ;
} else
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) | V_8 ) ;
}
static inline void F_10 ( void )
{
if ( V_3 ) {
F_3 ( V_10 ) ;
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) & ~ ( V_7 | V_8 ) ) ;
} else
F_4 ( & V_5 [ V_6 ] , F_5 ( & V_5 [ V_6 ] ) | V_7 | V_8 ) ;
}
int T_2 F_11 ( void )
{
struct V_11 V_12 ;
int V_13 ;
if ( V_14 -> V_15 != V_16 &&
V_14 -> V_15 != V_17 )
return 0 ;
V_5 = V_18 ;
V_19 = V_20 ;
V_3 = V_14 -> V_15 == V_17 ;
V_13 = F_12 () ;
if ( V_13 ) {
F_13 ( V_21 L_1 ) ;
V_5 = NULL ;
return 0 ;
}
F_14 ( & V_12 , NULL , 3 , V_22 , V_23 , 1 ) ;
while ( ! V_12 . V_24 )
F_15 () ;
return 1 ;
}
int T_2 F_11 ( void )
{
struct V_11 V_12 ;
T_3 V_25 ;
const T_4 * V_26 ;
int V_13 ;
if ( V_27 != 0 )
return 1 ;
V_27 = F_16 ( NULL , L_2 ) ;
if ( V_27 == 0 )
return 0 ;
V_26 = F_17 ( V_27 , L_3 , NULL ) ;
if ( V_26 == NULL ) {
F_13 ( V_21 L_4 ) ;
goto V_28;
}
V_25 = F_18 ( V_27 , V_26 ) ;
if ( V_25 == 0 ) {
F_13 ( V_21 L_5 ) ;
goto V_28;
}
V_5 = F_19 ( V_25 , 0x2000 ) ;
if ( V_5 == NULL ) {
F_13 ( V_21 L_6 ) ;
goto V_28;
}
V_19 = V_20 ;
V_29 = V_30 ;
V_13 = F_12 () ;
if ( V_13 ) {
F_13 ( V_21 L_1 ) ;
V_5 = NULL ;
return 0 ;
}
F_4 ( & V_5 [ V_31 ] , 0x7f ) ;
F_4 ( & V_5 [ V_32 ] , V_33 | V_34 ) ;
F_14 ( & V_12 , NULL , 3 , V_22 , V_23 , 1 ) ;
while ( ! V_12 . V_24 )
F_15 () ;
return 1 ;
V_28:
F_20 ( V_27 ) ;
V_27 = NULL ;
return 0 ;
}
static int T_2 F_21 ( void )
{
if ( V_5 == NULL )
return - V_35 ;
#ifdef F_22
V_36 = V_37 ;
#else
V_36 = F_23 ( V_27 , 0 ) ;
if ( ! V_36 ) {
F_13 ( V_21 L_7 ,
V_27 -> V_38 ) ;
return - V_35 ;
}
#endif
if ( F_24 ( V_36 , V_39 , 0 , L_8 , V_39 ) ) {
F_13 ( V_21 L_9 , V_36 ) ;
return - V_40 ;
}
F_25 ( L_10 ) ;
V_41 = 1 ;
return 0 ;
}
static int
F_26 ( void )
{
#ifdef F_27
if ( V_29 != V_30 )
return - V_35 ;
#else
if ( V_14 -> V_15 != V_16 &&
V_14 -> V_15 != V_17 )
return - V_35 ;
#endif
if ( V_5 == NULL )
return - V_35 ;
return 0 ;
}
static int T_2 F_28 ( void )
{
if ( F_1 ( F_5 ( & V_5 [ V_6 ] ) ) ) {
F_6 () ;
while ( 1 ) {
F_9 () ;
F_29 ( 1 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_7 () ;
if ( ! F_1 ( F_5 ( & V_5 [ V_6 ] ) ) )
break;
}
F_10 () ;
} else if ( F_5 ( & V_5 [ V_6 ] ) & V_7 ) {
F_9 () ;
F_7 () ;
F_29 ( 1 ) ;
F_10 () ;
}
if ( F_5 ( & V_5 [ V_31 ] ) & V_34 )
( void ) F_5 ( & V_5 [ V_42 ] ) ;
return 0 ;
}
static int
T_2 F_12 ( void )
{
#ifdef F_27
F_4 ( & V_5 [ V_32 ] , 0x7f ) ;
( void ) F_5 ( & V_5 [ V_32 ] ) ;
#else
F_4 ( & V_5 [ V_32 ] , V_34 ) ;
#endif
F_4 ( & V_5 [ V_43 ] , ( F_5 ( & V_5 [ V_43 ] ) | V_8 | V_7 ) & ~ V_2 ) ;
F_4 ( & V_5 [ V_44 ] , ( F_5 ( & V_5 [ V_44 ] ) & ~ V_45 ) | V_46 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
if ( V_3 )
return F_28 () ;
F_10 () ;
F_29 ( 4 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
F_7 () ;
F_30 ( F_1 ( F_5 ( & V_5 [ V_6 ] ) ) , L_11 ) ;
F_30 ( F_5 ( & V_5 [ V_31 ] ) & V_34 , L_12 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
F_9 () ;
F_30 ( ! F_1 ( F_5 ( & V_5 [ V_6 ] ) ) , L_13 ) ;
F_30 ( F_5 ( & V_5 [ V_31 ] ) & V_34 , L_14 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
return 0 ;
}
static int
F_31 ( struct V_11 * V_12 , int V_47 )
{
int V_48 ;
if ( ( V_5 == NULL ) || ! V_41 ) {
V_12 -> V_24 = 1 ;
return - V_49 ;
}
V_12 -> V_50 = 1 ;
V_48 = F_32 ( V_12 ) ;
if ( V_48 )
return V_48 ;
if ( V_47 ) {
while ( ! V_12 -> V_24 )
F_15 () ;
}
return 0 ;
}
static int
F_33 ( int V_51 )
{
struct V_11 V_12 ;
if ( ( V_5 == NULL ) || ! V_41 )
return - V_49 ;
F_14 ( & V_12 , NULL , 3 , V_22 , V_23 , ( V_51 ? 1 : 0 ) ) ;
while ( ! V_12 . V_24 )
F_15 () ;
return 0 ;
}
static int
F_34 ( void )
{
struct V_11 V_12 ;
if ( ( V_5 == NULL ) || ! V_41 )
return - V_49 ;
F_14 ( & V_12 , NULL , 2 , V_52 , 0 ) ;
while ( ! V_12 . V_24 )
F_15 () ;
return 0 ;
}
int
F_14 ( struct V_11 * V_12 , void (* F_35)( struct V_11 * ) ,
int V_53 , ... )
{
T_5 V_54 ;
int V_48 ;
if ( V_5 == NULL ) {
V_12 -> V_24 = 1 ;
return - V_49 ;
}
V_12 -> V_53 = V_53 ;
V_12 -> F_35 = F_35 ;
va_start ( V_54 , V_53 ) ;
for ( V_48 = 0 ; V_48 < V_53 ; ++ V_48 )
V_12 -> V_55 [ V_48 ] = va_arg ( V_54 , int ) ;
va_end ( V_54 ) ;
V_12 -> V_50 = 1 ;
return F_32 ( V_12 ) ;
}
static int
F_32 ( struct V_11 * V_12 )
{
unsigned long V_56 ;
if ( V_12 -> V_53 < 2 || V_12 -> V_55 [ 0 ] > V_22 ) {
V_12 -> V_24 = 1 ;
return - V_57 ;
}
V_12 -> V_58 = NULL ;
V_12 -> V_59 = 0 ;
V_12 -> V_24 = 0 ;
V_12 -> V_60 = 0 ;
F_36 ( & V_61 , V_56 ) ;
if ( V_62 != 0 ) {
V_63 -> V_58 = V_12 ;
V_63 = V_12 ;
} else {
V_62 = V_12 ;
V_63 = V_12 ;
if ( V_19 == V_20 )
F_37 () ;
}
F_38 ( & V_61 , V_56 ) ;
return 0 ;
}
static void
F_37 ( void )
{
if ( V_62 == NULL )
return;
V_64 = 0 ;
if ( F_1 ( F_5 ( & V_5 [ V_6 ] ) ) )
return;
F_4 ( & V_5 [ V_44 ] , F_5 ( & V_5 [ V_44 ] ) | V_65 ) ;
F_4 ( & V_5 [ V_42 ] , V_62 -> V_55 [ V_64 ++ ] ) ;
if ( V_3 )
F_6 () ;
else
F_2 () ;
V_19 = V_66 ;
}
void
F_15 ( void )
{
V_39 ( 0 , NULL ) ;
}
static T_6
V_39 ( int V_67 , void * V_68 )
{
unsigned long V_56 ;
T_1 V_69 ;
struct V_11 * V_12 = NULL ;
unsigned char V_70 [ 16 ] ;
int V_71 = 0 ;
int V_24 = 0 ;
F_36 ( & V_61 , V_56 ) ;
#ifdef F_22
if ( ! V_68 )
#endif
{
if ( ( F_5 ( & V_5 [ V_31 ] ) & V_34 ) == 0 ) {
F_38 ( & V_61 , V_56 ) ;
return V_72 ;
} else {
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
}
}
V_69 = F_5 ( & V_5 [ V_6 ] ) & ( V_7 | V_8 | V_2 ) ;
switch ( V_19 ) {
case V_20 :
( void ) F_5 ( & V_5 [ V_42 ] ) ;
V_73:
F_2 () ;
V_19 = V_74 ;
V_75 = V_76 ;
V_77 = 0 ;
break;
case V_78 :
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_2 () ;
V_19 = V_74 ;
V_75 = V_62 -> V_79 ;
V_77 = 1 ;
break;
case V_66 :
if ( F_1 ( V_69 ) ) {
F_4 ( & V_5 [ V_44 ] , F_5 ( & V_5 [ V_44 ] ) & ~ V_65 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_10 () ;
V_19 = V_20 ;
if ( V_3 )
goto V_73;
} else {
F_4 ( & V_5 [ V_42 ] , V_62 -> V_55 [ V_64 ++ ] ) ;
F_8 () ;
if ( V_3 )
F_7 () ;
V_19 = V_80 ;
}
break;
case V_80 :
V_12 = V_62 ;
if ( V_64 >= V_12 -> V_53 ) {
F_4 ( & V_5 [ V_44 ] , F_5 ( & V_5 [ V_44 ] ) & ~ V_65 ) ;
( void ) F_5 ( & V_5 [ V_42 ] ) ;
F_10 () ;
V_12 -> V_59 = 1 ;
if ( V_12 -> V_50 ) {
V_19 = V_78 ;
} else {
V_62 = V_12 -> V_58 ;
V_24 = 1 ;
V_19 = V_20 ;
F_37 () ;
}
} else {
F_4 ( & V_5 [ V_42 ] , V_12 -> V_55 [ V_64 ++ ] ) ;
F_8 () ;
if ( V_3 )
F_7 () ;
}
break;
case V_74 :
if ( V_77 ? F_39 ( V_62 -> V_79 , V_75 )
: F_39 ( V_76 , V_75 ) )
( void ) F_5 ( & V_5 [ V_42 ] ) ;
else
* V_75 ++ = F_5 ( & V_5 [ V_42 ] ) ;
if ( ! F_1 ( V_69 ) ) {
if ( V_3 )
F_7 () ;
F_10 () ;
V_19 = V_81 ;
if ( V_3 )
goto V_82;
} else {
F_8 () ;
if ( V_3 )
F_9 () ;
}
break;
case V_81 :
( void ) F_5 ( & V_5 [ V_42 ] ) ;
V_82:
if ( V_77 ) {
V_12 = V_62 ;
V_12 -> V_60 = V_75 - V_12 -> V_79 ;
if ( V_12 -> V_55 [ 0 ] == V_52 ) {
if ( V_12 -> V_60 <= 2 || ( V_12 -> V_79 [ 1 ] & 2 ) != 0 ) {
V_12 -> V_60 = 0 ;
} else {
V_12 -> V_60 -= 2 ;
memmove ( V_12 -> V_79 , V_12 -> V_79 + 2 , V_12 -> V_60 ) ;
}
}
V_62 = V_12 -> V_58 ;
V_24 = 1 ;
V_77 = 0 ;
} else {
V_71 = V_75 - V_76 ;
memcpy ( V_70 , V_76 , V_71 ) ;
}
V_75 = V_76 ;
V_19 = V_20 ;
F_37 () ;
if ( V_19 == V_20 && F_1 ( F_5 ( & V_5 [ V_6 ] ) ) ) {
F_2 () ;
V_19 = V_74 ;
}
break;
default:
F_40 ( L_15 , V_19 ) ;
}
F_38 ( & V_61 , V_56 ) ;
if ( V_24 && V_12 ) {
void (* F_35)( struct V_11 * ) = V_12 -> F_35 ;
F_41 () ;
V_12 -> V_24 = 1 ;
if ( F_35 )
(* F_35)( V_12 ) ;
}
if ( V_71 )
F_42 ( V_70 , V_71 ) ;
return V_83 ;
}
static void
F_42 ( unsigned char * V_84 , int V_85 )
{
switch ( V_84 [ 0 ] ) {
case V_52 :
#ifdef F_43
if ( V_85 == 5 && V_84 [ 2 ] == 0x2c ) {
extern int V_86 , V_87 ;
if ( V_86 ) {
V_87 = V_84 [ 3 ] ;
return;
}
}
#endif
#ifdef F_44
F_45 ( V_84 + 2 , V_85 - 2 , V_84 [ 1 ] & 0x40 ) ;
#endif
break;
case V_88 :
break;
default:
F_46 ( V_89 , L_16 , V_90 , 32 , 1 ,
V_84 , V_85 , false ) ;
}
}
