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
V_27 ) ;
return - V_35 ;
}
#endif
if ( F_24 ( V_36 , V_38 , 0 , L_8 , V_38 ) ) {
F_13 ( V_21 L_9 , V_36 ) ;
return - V_39 ;
}
F_25 ( L_10 ) ;
V_40 = 1 ;
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
( void ) F_5 ( & V_5 [ V_41 ] ) ;
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
( void ) F_5 ( & V_5 [ V_41 ] ) ;
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
F_4 ( & V_5 [ V_42 ] , ( F_5 ( & V_5 [ V_42 ] ) | V_8 | V_7 ) & ~ V_2 ) ;
F_4 ( & V_5 [ V_43 ] , ( F_5 ( & V_5 [ V_43 ] ) & ~ V_44 ) | V_45 ) ;
( void ) F_5 ( & V_5 [ V_41 ] ) ;
if ( V_3 )
return F_28 () ;
F_10 () ;
F_29 ( 4 ) ;
( void ) F_5 ( & V_5 [ V_41 ] ) ;
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
F_7 () ;
F_30 ( F_1 ( F_5 ( & V_5 [ V_6 ] ) ) , L_11 ) ;
F_30 ( F_5 ( & V_5 [ V_31 ] ) & V_34 , L_12 ) ;
( void ) F_5 ( & V_5 [ V_41 ] ) ;
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
F_9 () ;
F_30 ( ! F_1 ( F_5 ( & V_5 [ V_6 ] ) ) , L_13 ) ;
F_30 ( F_5 ( & V_5 [ V_31 ] ) & V_34 , L_14 ) ;
( void ) F_5 ( & V_5 [ V_41 ] ) ;
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
return 0 ;
}
static int
F_31 ( struct V_11 * V_12 , int V_46 )
{
int V_47 ;
if ( ( V_5 == NULL ) || ! V_40 ) {
V_12 -> V_24 = 1 ;
return - V_48 ;
}
V_12 -> V_49 = 1 ;
V_47 = F_32 ( V_12 ) ;
if ( V_47 )
return V_47 ;
if ( V_46 ) {
while ( ! V_12 -> V_24 )
F_15 () ;
}
return 0 ;
}
static int
F_33 ( int V_50 )
{
struct V_11 V_12 ;
if ( ( V_5 == NULL ) || ! V_40 )
return - V_48 ;
F_14 ( & V_12 , NULL , 3 , V_22 , V_23 , ( V_50 ? 1 : 0 ) ) ;
while ( ! V_12 . V_24 )
F_15 () ;
return 0 ;
}
static int
F_34 ( void )
{
struct V_11 V_12 ;
if ( ( V_5 == NULL ) || ! V_40 )
return - V_48 ;
F_14 ( & V_12 , NULL , 2 , V_51 , 0 ) ;
while ( ! V_12 . V_24 )
F_15 () ;
return 0 ;
}
int
F_14 ( struct V_11 * V_12 , void (* F_35)( struct V_11 * ) ,
int V_52 , ... )
{
T_5 V_53 ;
int V_47 ;
if ( V_5 == NULL ) {
V_12 -> V_24 = 1 ;
return - V_48 ;
}
V_12 -> V_52 = V_52 ;
V_12 -> F_35 = F_35 ;
va_start ( V_53 , V_52 ) ;
for ( V_47 = 0 ; V_47 < V_52 ; ++ V_47 )
V_12 -> V_54 [ V_47 ] = va_arg ( V_53 , int ) ;
va_end ( V_53 ) ;
V_12 -> V_49 = 1 ;
return F_32 ( V_12 ) ;
}
static int
F_32 ( struct V_11 * V_12 )
{
unsigned long V_55 ;
if ( V_12 -> V_52 < 2 || V_12 -> V_54 [ 0 ] > V_22 ) {
V_12 -> V_24 = 1 ;
return - V_56 ;
}
V_12 -> V_57 = NULL ;
V_12 -> V_58 = 0 ;
V_12 -> V_24 = 0 ;
V_12 -> V_59 = 0 ;
F_36 ( & V_60 , V_55 ) ;
if ( V_61 != 0 ) {
V_62 -> V_57 = V_12 ;
V_62 = V_12 ;
} else {
V_61 = V_12 ;
V_62 = V_12 ;
if ( V_19 == V_20 )
F_37 () ;
}
F_38 ( & V_60 , V_55 ) ;
return 0 ;
}
static void
F_37 ( void )
{
if ( V_61 == NULL )
return;
V_63 = 0 ;
if ( F_1 ( F_5 ( & V_5 [ V_6 ] ) ) )
return;
F_4 ( & V_5 [ V_43 ] , F_5 ( & V_5 [ V_43 ] ) | V_64 ) ;
F_4 ( & V_5 [ V_41 ] , V_61 -> V_54 [ V_63 ++ ] ) ;
if ( V_3 )
F_6 () ;
else
F_2 () ;
V_19 = V_65 ;
}
void
F_15 ( void )
{
V_38 ( 0 , NULL ) ;
}
static T_6
V_38 ( int V_66 , void * V_67 )
{
unsigned long V_55 ;
T_1 V_68 ;
struct V_11 * V_12 = NULL ;
unsigned char V_69 [ 16 ] ;
int V_70 = 0 ;
int V_24 = 0 ;
F_36 ( & V_60 , V_55 ) ;
#ifdef F_22
if ( ! V_67 )
#endif
{
if ( ( F_5 ( & V_5 [ V_31 ] ) & V_34 ) == 0 ) {
F_38 ( & V_60 , V_55 ) ;
return V_71 ;
} else {
F_4 ( & V_5 [ V_31 ] , V_34 ) ;
}
}
V_68 = F_5 ( & V_5 [ V_6 ] ) & ( V_7 | V_8 | V_2 ) ;
switch ( V_19 ) {
case V_20 :
( void ) F_5 ( & V_5 [ V_41 ] ) ;
V_72:
F_2 () ;
V_19 = V_73 ;
V_74 = V_75 ;
V_76 = 0 ;
break;
case V_77 :
( void ) F_5 ( & V_5 [ V_41 ] ) ;
F_2 () ;
V_19 = V_73 ;
V_74 = V_61 -> V_78 ;
V_76 = 1 ;
break;
case V_65 :
if ( F_1 ( V_68 ) ) {
F_4 ( & V_5 [ V_43 ] , F_5 ( & V_5 [ V_43 ] ) & ~ V_64 ) ;
( void ) F_5 ( & V_5 [ V_41 ] ) ;
F_10 () ;
V_19 = V_20 ;
if ( V_3 )
goto V_72;
} else {
F_4 ( & V_5 [ V_41 ] , V_61 -> V_54 [ V_63 ++ ] ) ;
F_8 () ;
if ( V_3 )
F_7 () ;
V_19 = V_79 ;
}
break;
case V_79 :
V_12 = V_61 ;
if ( V_63 >= V_12 -> V_52 ) {
F_4 ( & V_5 [ V_43 ] , F_5 ( & V_5 [ V_43 ] ) & ~ V_64 ) ;
( void ) F_5 ( & V_5 [ V_41 ] ) ;
F_10 () ;
V_12 -> V_58 = 1 ;
if ( V_12 -> V_49 ) {
V_19 = V_77 ;
} else {
V_61 = V_12 -> V_57 ;
V_24 = 1 ;
V_19 = V_20 ;
F_37 () ;
}
} else {
F_4 ( & V_5 [ V_41 ] , V_12 -> V_54 [ V_63 ++ ] ) ;
F_8 () ;
if ( V_3 )
F_7 () ;
}
break;
case V_73 :
if ( V_76 ? F_39 ( V_61 -> V_78 , V_74 )
: F_39 ( V_75 , V_74 ) )
( void ) F_5 ( & V_5 [ V_41 ] ) ;
else
* V_74 ++ = F_5 ( & V_5 [ V_41 ] ) ;
if ( ! F_1 ( V_68 ) ) {
if ( V_3 )
F_7 () ;
F_10 () ;
V_19 = V_80 ;
if ( V_3 )
goto V_81;
} else {
F_8 () ;
if ( V_3 )
F_9 () ;
}
break;
case V_80 :
( void ) F_5 ( & V_5 [ V_41 ] ) ;
V_81:
if ( V_76 ) {
V_12 = V_61 ;
V_12 -> V_59 = V_74 - V_12 -> V_78 ;
if ( V_12 -> V_54 [ 0 ] == V_51 ) {
if ( V_12 -> V_59 <= 2 || ( V_12 -> V_78 [ 1 ] & 2 ) != 0 ) {
V_12 -> V_59 = 0 ;
} else {
V_12 -> V_59 -= 2 ;
memmove ( V_12 -> V_78 , V_12 -> V_78 + 2 , V_12 -> V_59 ) ;
}
}
V_61 = V_12 -> V_57 ;
V_24 = 1 ;
V_76 = 0 ;
} else {
V_70 = V_74 - V_75 ;
memcpy ( V_69 , V_75 , V_70 ) ;
}
V_74 = V_75 ;
V_19 = V_20 ;
F_37 () ;
if ( V_19 == V_20 && F_1 ( F_5 ( & V_5 [ V_6 ] ) ) ) {
F_2 () ;
V_19 = V_73 ;
}
break;
default:
F_40 ( L_15 , V_19 ) ;
}
F_38 ( & V_60 , V_55 ) ;
if ( V_24 && V_12 ) {
void (* F_35)( struct V_11 * ) = V_12 -> F_35 ;
F_41 () ;
V_12 -> V_24 = 1 ;
if ( F_35 )
(* F_35)( V_12 ) ;
}
if ( V_70 )
F_42 ( V_69 , V_70 ) ;
return V_82 ;
}
static void
F_42 ( unsigned char * V_83 , int V_84 )
{
switch ( V_83 [ 0 ] ) {
case V_51 :
#ifdef F_43
if ( V_84 == 5 && V_83 [ 2 ] == 0x2c ) {
extern int V_85 , V_86 ;
if ( V_85 ) {
V_86 = V_83 [ 3 ] ;
return;
}
}
#endif
#ifdef F_44
F_45 ( V_83 + 2 , V_84 - 2 , V_83 [ 1 ] & 0x40 ) ;
#endif
break;
case V_87 :
break;
default:
F_46 ( V_88 , L_16 , V_89 , 32 , 1 ,
V_83 , V_84 , false ) ;
}
}
