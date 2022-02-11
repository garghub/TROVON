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
if ( V_26 == V_28 ) {
F_3 ( V_11 L_7 ,
V_17 -> V_29 ) ;
return - V_25 ;
}
#endif
if ( F_15 ( V_26 , V_30 , 0 , L_8 , V_30 ) ) {
F_3 ( V_11 L_9 , V_26 ) ;
return - V_31 ;
}
F_3 ( L_10 ) ;
V_32 = 1 ;
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
F_2 ( void )
{
F_10 ( & V_7 [ V_33 ] , ( F_18 ( & V_7 [ V_33 ] ) | V_34 | V_35 ) & ~ V_36 ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_34 | V_35 ) ;
F_10 ( & V_7 [ V_38 ] , ( F_18 ( & V_7 [ V_38 ] ) & ~ V_39 ) | V_40 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
#ifdef F_17
F_10 ( & V_7 [ V_22 ] , 0x7f ) ;
( void ) F_18 ( & V_7 [ V_22 ] ) ;
#else
F_10 ( & V_7 [ V_22 ] , V_24 ) ;
#endif
F_19 ( 4 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_34 ) ;
F_20 ( ( F_18 ( & V_7 [ V_37 ] ) & V_36 ) == 0 , L_11 ) ;
F_20 ( F_18 ( & V_7 [ V_21 ] ) & V_24 , L_12 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_34 ) ;
F_20 ( F_18 ( & V_7 [ V_37 ] ) & V_36 , L_13 ) ;
F_20 ( F_18 ( & V_7 [ V_21 ] ) & V_24 , L_14 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_35 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , int V_42 )
{
int V_43 ;
if ( ( V_7 == NULL ) || ! V_32 ) {
V_2 -> V_14 = 1 ;
return - V_44 ;
}
V_2 -> V_45 = 1 ;
V_43 = F_22 ( V_2 ) ;
if ( V_43 )
return V_43 ;
if ( V_42 ) {
while ( ! V_2 -> V_14 )
F_5 () ;
}
return 0 ;
}
static int
F_23 ( int V_46 )
{
struct V_1 V_2 ;
if ( ( V_7 == NULL ) || ! V_32 )
return - V_44 ;
F_4 ( & V_2 , NULL , 3 , V_12 , V_13 , ( V_46 ? 1 : 0 ) ) ;
while ( ! V_2 . V_14 )
F_5 () ;
return 0 ;
}
static int
F_24 ( void )
{
struct V_1 V_2 ;
if ( ( V_7 == NULL ) || ! V_32 )
return - V_44 ;
F_4 ( & V_2 , NULL , 2 , V_47 , 0 ) ;
while ( ! V_2 . V_14 )
F_5 () ;
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , void (* F_25)( struct V_1 * ) ,
int V_48 , ... )
{
T_4 V_49 ;
int V_43 ;
if ( V_7 == NULL ) {
V_2 -> V_14 = 1 ;
return - V_44 ;
}
V_2 -> V_48 = V_48 ;
V_2 -> F_25 = F_25 ;
va_start ( V_49 , V_48 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; ++ V_43 )
V_2 -> V_50 [ V_43 ] = va_arg ( V_49 , int ) ;
va_end ( V_49 ) ;
V_2 -> V_45 = 1 ;
return F_22 ( V_2 ) ;
}
static int
F_22 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
if ( V_2 -> V_48 < 2 || V_2 -> V_50 [ 0 ] > V_12 ) {
V_2 -> V_14 = 1 ;
return - V_52 ;
}
V_2 -> V_53 = NULL ;
V_2 -> V_54 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_55 = 0 ;
F_26 ( & V_56 , V_51 ) ;
if ( V_57 != 0 ) {
V_58 -> V_53 = V_2 ;
V_58 = V_2 ;
} else {
V_57 = V_2 ;
V_58 = V_2 ;
if ( V_9 == V_10 )
F_27 () ;
}
F_28 ( & V_56 , V_51 ) ;
return 0 ;
}
static void
F_27 ( void )
{
struct V_1 * V_2 ;
V_2 = V_57 ;
if ( V_2 == 0 )
return;
if ( ( F_18 ( & V_7 [ V_37 ] ) & V_36 ) == 0 )
return;
F_10 ( & V_7 [ V_38 ] , F_18 ( & V_7 [ V_38 ] ) | V_59 ) ;
F_10 ( & V_7 [ V_41 ] , V_2 -> V_50 [ 0 ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_35 ) ;
V_9 = V_60 ;
}
void
F_5 ( void )
{
if ( V_26 )
F_29 ( V_26 ) ;
V_30 ( 0 , NULL ) ;
if ( V_26 )
F_30 ( V_26 ) ;
}
static T_5
V_30 ( int V_61 , void * V_62 )
{
int V_63 ;
struct V_1 * V_2 = NULL ;
unsigned char V_64 [ 16 ] ;
int V_65 = 0 ;
int V_14 = 0 ;
F_31 ( & V_56 ) ;
#ifdef F_13
if ( ! V_62 )
#endif
{
if ( ( F_18 ( & V_7 [ V_21 ] ) & V_24 ) == 0 ) {
F_32 ( & V_56 ) ;
return V_66 ;
} else {
F_10 ( & V_7 [ V_21 ] , V_24 ) ;
}
}
V_63 = ( ~ F_18 ( & V_7 [ V_37 ] ) & ( V_35 | V_36 ) ) | ( F_18 ( & V_7 [ V_38 ] ) & V_59 ) ;
switch ( V_9 ) {
case V_10 :
if ( V_63 != V_36 )
F_3 ( L_15 , V_63 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_35 ) ;
V_9 = V_67 ;
V_68 = V_69 ;
V_70 = 0 ;
break;
case V_71 :
if ( V_63 != V_36 )
F_3 ( L_16 , V_63 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_35 ) ;
V_9 = V_67 ;
V_68 = V_57 -> V_72 ;
V_70 = 1 ;
break;
case V_60 :
if ( V_63 == V_36 + V_35 + V_59 ) {
F_10 ( & V_7 [ V_38 ] , F_18 ( & V_7 [ V_38 ] ) & ~ V_59 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_35 | V_34 ) ;
V_9 = V_10 ;
} else {
if ( V_63 != V_35 + V_59 )
F_3 ( L_17 , V_63 ) ;
F_10 ( & V_7 [ V_41 ] , V_57 -> V_50 [ 1 ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) ^ V_34 ) ;
V_73 = 2 ;
V_9 = V_74 ;
}
break;
case V_74 :
V_2 = V_57 ;
if ( V_73 >= V_2 -> V_48 ) {
F_10 ( & V_7 [ V_38 ] , F_18 ( & V_7 [ V_38 ] ) & ~ V_59 ) ;
( void ) F_18 ( & V_7 [ V_41 ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_34 | V_35 ) ;
V_2 -> V_54 = 1 ;
if ( V_2 -> V_45 ) {
V_9 = V_71 ;
} else {
V_57 = V_2 -> V_53 ;
V_14 = 1 ;
V_9 = V_10 ;
F_27 () ;
}
} else {
F_10 ( & V_7 [ V_41 ] , V_2 -> V_50 [ V_73 ++ ] ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) ^ V_34 ) ;
}
break;
case V_67 :
* V_68 ++ = F_18 ( & V_7 [ V_41 ] ) ;
if ( V_63 == V_35 ) {
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) | V_34 | V_35 ) ;
V_9 = V_75 ;
} else {
if ( V_63 != V_35 + V_36 )
F_3 ( L_18 , V_63 ) ;
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) ^ V_34 ) ;
}
break;
case V_75 :
( void ) F_18 ( & V_7 [ V_41 ] ) ;
if ( V_70 ) {
V_2 = V_57 ;
V_2 -> V_55 = V_68 - V_2 -> V_72 ;
if ( V_2 -> V_50 [ 0 ] == V_47 ) {
if ( V_2 -> V_55 <= 2 || ( V_2 -> V_72 [ 1 ] & 2 ) != 0 ) {
V_2 -> V_55 = 0 ;
} else {
V_2 -> V_55 -= 2 ;
memmove ( V_2 -> V_72 , V_2 -> V_72 + 2 , V_2 -> V_55 ) ;
}
}
V_57 = V_2 -> V_53 ;
V_14 = 1 ;
} else {
V_65 = V_68 - V_69 ;
memcpy ( V_64 , V_69 , V_65 ) ;
}
if ( V_63 == V_36 ) {
F_10 ( & V_7 [ V_37 ] , F_18 ( & V_7 [ V_37 ] ) & ~ V_35 ) ;
V_9 = V_67 ;
V_68 = V_69 ;
V_70 = 0 ;
} else {
V_9 = V_10 ;
F_27 () ;
}
break;
default:
F_3 ( L_19 , V_9 ) ;
}
F_32 ( & V_56 ) ;
if ( V_14 && V_2 ) {
void (* F_25)( struct V_1 * ) = V_2 -> F_25 ;
F_33 () ;
V_2 -> V_14 = 1 ;
if ( F_25 )
(* F_25)( V_2 ) ;
}
if ( V_65 )
F_34 ( V_64 , V_65 ) ;
return V_76 ;
}
static void
F_34 ( unsigned char * V_77 , int V_78 )
{
int V_43 ;
switch ( V_77 [ 0 ] ) {
case V_47 :
#ifdef F_35
if ( V_78 == 5 && V_77 [ 2 ] == 0x2c ) {
extern int V_79 , V_80 ;
if ( V_79 ) {
V_80 = V_77 [ 3 ] ;
return;
}
}
#endif
#ifdef F_36
F_37 ( V_77 + 2 , V_78 - 2 , V_77 [ 1 ] & 0x40 ) ;
#endif
break;
default:
F_3 ( L_20 , V_78 ) ;
for ( V_43 = 0 ; V_43 < V_78 ; ++ V_43 )
F_3 ( L_21 , V_77 [ V_43 ] ) ;
F_3 ( L_22 ) ;
}
}
