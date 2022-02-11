int T_1 F_1 ( void )
{
struct V_1 V_2 ;
int V_3 ;
if ( V_4 -> V_5 != V_6 )
return 0 ;
V_7 = V_8 ;
V_9 = V_10 ;
V_3 = F_2 () ;
if ( V_3 ) {
F_3 ( V_11 L_1 ) ;
V_7 = NULL ;
return 0 ;
}
F_4 ( & V_2 , NULL , 3 , V_12 , V_13 , 1 ) ;
while ( ! V_2 . V_14 )
F_5 () ;
return 1 ;
}
int T_1 F_1 ( void )
{
struct V_1 V_2 ;
T_2 V_15 ;
const T_3 * V_16 ;
int V_3 ;
if ( V_17 != 0 )
return 1 ;
V_17 = F_6 ( NULL , L_2 ) ;
if ( V_17 == 0 )
return 0 ;
V_16 = F_7 ( V_17 , L_3 , NULL ) ;
if ( V_16 == NULL ) {
F_3 ( V_11 L_4 ) ;
goto V_18;
}
V_15 = F_8 ( V_17 , V_16 ) ;
if ( V_15 == 0 ) {
F_3 ( V_11 L_5 ) ;
goto V_18;
}
V_7 = F_9 ( V_15 , 0x2000 ) ;
if ( V_7 == NULL ) {
F_3 ( V_11 L_6 ) ;
goto V_18;
}
V_9 = V_10 ;
V_19 = V_20 ;
V_3 = F_2 () ;
if ( V_3 ) {
F_3 ( V_11 L_1 ) ;
V_7 = NULL ;
return 0 ;
}
F_10 ( & V_7 [ V_21 ] , 0x7f ) ;
F_10 ( & V_7 [ V_22 ] , V_23 | V_24 ) ;
F_4 ( & V_2 , NULL , 3 , V_12 , V_13 , 1 ) ;
while ( ! V_2 . V_14 )
F_5 () ;
return 1 ;
V_18:
F_11 ( V_17 ) ;
V_17 = NULL ;
return 0 ;
}
static int T_1 F_12 ( void )
{
if ( V_7 == NULL )
return - V_25 ;
#ifdef F_13
V_26 = V_27 ;
#else
V_26 = F_14 ( V_17 , 0 ) ;
if ( ! V_26 ) {
F_3 ( V_11 L_7 ,
V_17 -> V_28 ) ;
return - V_25 ;
}
#endif
if ( F_15 ( V_26 , V_29 , 0 , L_8 , V_29 ) ) {
F_3 ( V_11 L_9 , V_26 ) ;
return - V_30 ;
}
F_3 ( L_10 ) ;
V_31 = 1 ;
return 0 ;
}
static int
F_16 ( void )
{
#ifdef F_17
if ( V_19 != V_20 )
return - V_25 ;
#else
if ( V_4 -> V_5 != V_6 )
return - V_25 ;
#endif
if ( V_7 == NULL )
return - V_25 ;
return 0 ;
}
static int
T_1 F_2 ( void )
{
F_10 ( & V_7 [ V_32 ] , ( F_18 ( & V_7 [ V_32 ] ) | V_33 | V_34 ) & ~ V_35 ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) | V_33 | V_34 ) ;
F_10 ( & V_7 [ V_37 ] , ( F_18 ( & V_7 [ V_37 ] ) & ~ V_38 ) | V_39 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
#ifdef F_17
F_10 ( & V_7 [ V_22 ] , 0x7f ) ;
( void ) F_18 ( & V_7 [ V_22 ] ) ;
#else
F_10 ( & V_7 [ V_22 ] , V_24 ) ;
#endif
F_19 ( 4 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) & ~ V_33 ) ;
F_20 ( ( F_18 ( & V_7 [ V_36 ] ) & V_35 ) == 0 , L_11 ) ;
F_20 ( F_18 ( & V_7 [ V_21 ] ) & V_24 , L_12 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) | V_33 ) ;
F_20 ( F_18 ( & V_7 [ V_36 ] ) & V_35 , L_13 ) ;
F_20 ( F_18 ( & V_7 [ V_21 ] ) & V_24 , L_14 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) | V_34 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , int V_41 )
{
int V_42 ;
if ( ( V_7 == NULL ) || ! V_31 ) {
V_2 -> V_14 = 1 ;
return - V_43 ;
}
V_2 -> V_44 = 1 ;
V_42 = F_22 ( V_2 ) ;
if ( V_42 )
return V_42 ;
if ( V_41 ) {
while ( ! V_2 -> V_14 )
F_5 () ;
}
return 0 ;
}
static int
F_23 ( int V_45 )
{
struct V_1 V_2 ;
if ( ( V_7 == NULL ) || ! V_31 )
return - V_43 ;
F_4 ( & V_2 , NULL , 3 , V_12 , V_13 , ( V_45 ? 1 : 0 ) ) ;
while ( ! V_2 . V_14 )
F_5 () ;
return 0 ;
}
static int
F_24 ( void )
{
struct V_1 V_2 ;
if ( ( V_7 == NULL ) || ! V_31 )
return - V_43 ;
F_4 ( & V_2 , NULL , 2 , V_46 , 0 ) ;
while ( ! V_2 . V_14 )
F_5 () ;
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , void (* F_25)( struct V_1 * ) ,
int V_47 , ... )
{
T_4 V_48 ;
int V_42 ;
if ( V_7 == NULL ) {
V_2 -> V_14 = 1 ;
return - V_43 ;
}
V_2 -> V_47 = V_47 ;
V_2 -> F_25 = F_25 ;
va_start ( V_48 , V_47 ) ;
for ( V_42 = 0 ; V_42 < V_47 ; ++ V_42 )
V_2 -> V_49 [ V_42 ] = va_arg ( V_48 , int ) ;
va_end ( V_48 ) ;
V_2 -> V_44 = 1 ;
return F_22 ( V_2 ) ;
}
static int
F_22 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
if ( V_2 -> V_47 < 2 || V_2 -> V_49 [ 0 ] > V_12 ) {
V_2 -> V_14 = 1 ;
return - V_51 ;
}
V_2 -> V_52 = NULL ;
V_2 -> V_53 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_54 = 0 ;
F_26 ( & V_55 , V_50 ) ;
if ( V_56 != 0 ) {
V_57 -> V_52 = V_2 ;
V_57 = V_2 ;
} else {
V_56 = V_2 ;
V_57 = V_2 ;
if ( V_9 == V_10 )
F_27 () ;
}
F_28 ( & V_55 , V_50 ) ;
return 0 ;
}
static void
F_27 ( void )
{
struct V_1 * V_2 ;
V_2 = V_56 ;
if ( V_2 == 0 )
return;
if ( ( F_18 ( & V_7 [ V_36 ] ) & V_35 ) == 0 )
return;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_58 ) ;
F_10 ( & V_7 [ V_40 ] , V_2 -> V_49 [ 0 ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) & ~ V_34 ) ;
V_9 = V_59 ;
}
void
F_5 ( void )
{
if ( V_26 )
F_29 ( V_26 ) ;
V_29 ( 0 , NULL ) ;
if ( V_26 )
F_30 ( V_26 ) ;
}
static T_5
V_29 ( int V_60 , void * V_61 )
{
int V_62 ;
struct V_1 * V_2 = NULL ;
unsigned char V_63 [ 16 ] ;
int V_64 = 0 ;
int V_14 = 0 ;
F_31 ( & V_55 ) ;
#ifdef F_13
if ( ! V_61 )
#endif
{
if ( ( F_18 ( & V_7 [ V_21 ] ) & V_24 ) == 0 ) {
F_32 ( & V_55 ) ;
return V_65 ;
} else {
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
}
}
V_62 = ( ~ F_18 ( & V_7 [ V_36 ] ) & ( V_34 | V_35 ) ) | ( F_18 ( & V_7 [ V_37 ] ) & V_58 ) ;
switch ( V_9 ) {
case V_10 :
if ( V_62 != V_35 )
F_3 ( L_15 , V_62 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) & ~ V_34 ) ;
V_9 = V_66 ;
V_67 = V_68 ;
V_69 = 0 ;
break;
case V_70 :
if ( V_62 != V_35 )
F_3 ( L_16 , V_62 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) & ~ V_34 ) ;
V_9 = V_66 ;
V_67 = V_56 -> V_71 ;
V_69 = 1 ;
break;
case V_59 :
if ( V_62 == V_35 + V_34 + V_58 ) {
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_58 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) | V_34 | V_33 ) ;
V_9 = V_10 ;
} else {
if ( V_62 != V_34 + V_58 )
F_3 ( L_17 , V_62 ) ;
F_10 ( & V_7 [ V_40 ] , V_56 -> V_49 [ 1 ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) ^ V_33 ) ;
V_72 = 2 ;
V_9 = V_73 ;
}
break;
case V_73 :
V_2 = V_56 ;
if ( V_72 >= V_2 -> V_47 ) {
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_58 ) ;
( void ) F_18 ( & V_7 [ V_40 ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) | V_33 | V_34 ) ;
V_2 -> V_53 = 1 ;
if ( V_2 -> V_44 ) {
V_9 = V_70 ;
} else {
V_56 = V_2 -> V_52 ;
V_14 = 1 ;
V_9 = V_10 ;
F_27 () ;
}
} else {
F_10 ( & V_7 [ V_40 ] , V_2 -> V_49 [ V_72 ++ ] ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) ^ V_33 ) ;
}
break;
case V_66 :
* V_67 ++ = F_18 ( & V_7 [ V_40 ] ) ;
if ( V_62 == V_34 ) {
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) | V_33 | V_34 ) ;
V_9 = V_74 ;
} else {
if ( V_62 != V_34 + V_35 )
F_3 ( L_18 , V_62 ) ;
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) ^ V_33 ) ;
}
break;
case V_74 :
( void ) F_18 ( & V_7 [ V_40 ] ) ;
if ( V_69 ) {
V_2 = V_56 ;
V_2 -> V_54 = V_67 - V_2 -> V_71 ;
if ( V_2 -> V_49 [ 0 ] == V_46 ) {
if ( V_2 -> V_54 <= 2 || ( V_2 -> V_71 [ 1 ] & 2 ) != 0 ) {
V_2 -> V_54 = 0 ;
} else {
V_2 -> V_54 -= 2 ;
memmove ( V_2 -> V_71 , V_2 -> V_71 + 2 , V_2 -> V_54 ) ;
}
}
V_56 = V_2 -> V_52 ;
V_14 = 1 ;
} else {
V_64 = V_67 - V_68 ;
memcpy ( V_63 , V_68 , V_64 ) ;
}
if ( V_62 == V_35 ) {
F_10 ( & V_7 [ V_36 ] , F_18 ( & V_7 [ V_36 ] ) & ~ V_34 ) ;
V_9 = V_66 ;
V_67 = V_68 ;
V_69 = 0 ;
} else {
V_9 = V_10 ;
F_27 () ;
}
break;
default:
F_3 ( L_19 , V_9 ) ;
}
F_32 ( & V_55 ) ;
if ( V_14 && V_2 ) {
void (* F_25)( struct V_1 * ) = V_2 -> F_25 ;
F_33 () ;
V_2 -> V_14 = 1 ;
if ( F_25 )
(* F_25)( V_2 ) ;
}
if ( V_64 )
F_34 ( V_63 , V_64 ) ;
return V_75 ;
}
static void
F_34 ( unsigned char * V_76 , int V_77 )
{
int V_42 ;
switch ( V_76 [ 0 ] ) {
case V_46 :
#ifdef F_35
if ( V_77 == 5 && V_76 [ 2 ] == 0x2c ) {
extern int V_78 , V_79 ;
if ( V_78 ) {
V_79 = V_76 [ 3 ] ;
return;
}
}
#endif
#ifdef F_36
F_37 ( V_76 + 2 , V_77 - 2 , V_76 [ 1 ] & 0x40 ) ;
#endif
break;
default:
F_3 ( L_20 , V_77 ) ;
for ( V_42 = 0 ; V_42 < V_77 ; ++ V_42 )
F_3 ( L_21 , V_76 [ V_42 ] ) ;
F_3 ( L_22 ) ;
}
}
