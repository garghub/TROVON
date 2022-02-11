static int
F_1 ( void )
{
if ( V_1 -> V_2 != V_3 )
return - V_4 ;
V_5 = V_6 ;
return 0 ;
}
static int
F_2 ( void )
{
int V_7 ;
if ( V_5 == NULL )
return - V_4 ;
if ( ( V_7 = F_3 () ) ) {
F_4 ( V_8 L_1 , V_7 ) ;
V_5 = NULL ;
return V_7 ;
}
if ( F_5 ( V_9 , V_10 , V_11 | V_12 ,
L_2 , V_10 ) ) {
F_4 ( V_8 L_3 , V_9 ) ;
return - V_13 ;
}
F_4 ( L_4 ) ;
return 0 ;
}
static void
F_6 ( void )
{
int V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
if ( V_14 & V_17 ) {
#ifdef F_7
F_4 ( V_18 L_5 ) ;
#endif
return;
}
F_8 ( V_19 ) ;
V_5 [ V_20 ] &= ~ V_21 ;
V_5 [ V_22 ] = V_23 | V_24 ;
F_8 ( V_19 ) ;
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
if ( ! ( V_14 & V_17 ) )
{
V_5 [ V_15 ] |= V_16 ;
while( 1 )
{
int V_25 = V_19 * 5 ;
while ( ! ( V_5 [ V_26 ] & V_24 ) && V_25 -- > 0 )
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
V_27 = V_5 [ V_28 ] ;
#ifdef F_7
F_4 ( V_18 L_6 ,
V_14 , V_25 , V_27 ) ;
#endif
if( V_5 [ V_15 ] & V_17 )
break;
V_5 [ V_15 ] |= V_29 ;
F_8 ( V_19 ) ;
V_5 [ V_15 ] &= ~ V_29 ;
}
V_5 [ V_15 ] &= ~ V_16 ;
F_8 ( V_19 ) ;
}
V_5 [ V_22 ] = V_30 | V_24 ;
}
static int
F_3 ( void )
{
int V_31 ;
V_5 [ V_32 ] = ( V_5 [ V_32 ] | V_29 | V_16 ) & ~ V_17 ;
V_5 [ V_20 ] = ( V_5 [ V_20 ] & ~ V_33 ) | V_34 ;
#ifdef F_7
F_4 ( V_18 L_7 , V_5 [ V_15 ] & ( V_16 | V_17 ) ) ;
#endif
V_27 = V_5 [ V_28 ] ;
V_5 [ V_22 ] = V_30 | V_24 ;
V_5 [ V_15 ] &= ~ ( V_29 | V_16 ) ;
V_5 [ V_26 ] = V_24 ;
for( V_31 = 0 ; V_31 < 60 ; V_31 ++ ) {
F_8 ( V_19 ) ;
F_6 () ;
F_8 ( V_19 ) ;
if( V_5 [ V_15 ] & V_17 )
break;
}
if ( V_31 == 60 )
F_4 ( V_8 L_8 ) ;
V_35 = V_36 ;
V_37 = 0 ;
return 0 ;
}
static int
F_9 ( struct V_38 * V_39 , int V_40 )
{
int V_31 ;
#ifdef F_7
static int V_41 = 0 ;
#endif
if ( V_5 == NULL ) {
V_39 -> V_42 = 1 ;
return - V_43 ;
}
#ifdef F_7
if ( V_41 ) {
F_4 ( V_18 L_9 ) ;
for ( V_31 = 0 ; V_31 < V_39 -> V_44 ; V_31 ++ ) {
F_4 ( L_10 , V_39 -> V_45 [ V_31 ] ) ;
}
F_4 ( L_11 , V_40 ) ;
}
#endif
V_39 -> V_46 = 1 ;
V_31 = F_10 ( V_39 ) ;
if ( V_31 )
{
if( V_31 == - V_47 && V_40 )
V_37 = 1 ;
else
V_37 = 0 ;
return V_31 ;
}
if( V_40 )
F_11 ( V_39 ) ;
return 0 ;
}
static void F_11 ( struct V_38 * V_39 )
{
int V_48 = 0 ;
#ifdef F_7
F_4 ( V_18 L_12 ) ;
#endif
while ( ! V_39 -> V_42 && V_48 ++ < 50 ) {
F_12 () ;
}
if ( V_48 > 50 )
F_4 ( V_8 L_13 ) ;
}
int
F_13 ( struct V_38 * V_39 , void (* F_14)( struct V_38 * ) ,
int V_44 , ... )
{
T_1 V_49 ;
int V_31 ;
V_39 -> V_44 = V_44 ;
V_39 -> F_14 = F_14 ;
V_39 -> V_46 = 0 ;
va_start ( V_49 , V_44 ) ;
for ( V_31 = 0 ; V_31 < V_44 ; V_31 ++ )
V_39 -> V_45 [ V_31 ++ ] = va_arg ( V_49 , int ) ;
va_end ( V_49 ) ;
return F_9 ( V_39 , 1 ) ;
}
static int
F_10 ( struct V_38 * V_39 )
{
unsigned long V_50 ;
int V_31 ;
if ( V_39 -> V_44 < 2 || V_39 -> V_45 [ 0 ] > V_51 ) {
F_4 ( V_8 L_14 ) ;
V_39 -> V_42 = 1 ;
return - V_52 ;
}
V_39 -> V_53 = NULL ;
V_39 -> V_54 = 0 ;
V_39 -> V_42 = 0 ;
V_39 -> V_55 = 0 ;
F_15 ( V_50 ) ;
if ( V_56 ) {
V_57 -> V_53 = V_39 ;
V_57 = V_39 ;
} else {
V_56 = V_39 ;
V_57 = V_39 ;
}
if ( V_35 == V_36 )
{
V_31 = F_16 () ;
if( V_31 != 0 )
{
F_17 ( V_50 ) ;
return V_31 ;
}
}
else
{
#ifdef F_7
F_4 ( V_18 L_15 , V_35 ) ;
#endif
F_17 ( V_50 ) ;
return - V_47 ;
}
F_17 ( V_50 ) ;
return 0 ;
}
static int
F_16 ( void )
{
struct V_38 * V_39 ;
int V_14 ;
#ifdef F_7
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
F_4 ( V_18 L_16 , V_35 , V_14 , V_5 [ V_26 ] ) ;
#endif
if ( V_35 != V_36 ) {
F_4 ( V_8 L_17 ) ;
return - V_47 ;
}
V_39 = V_56 ;
if ( V_39 == NULL )
return - V_52 ;
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
if ( ! ( V_14 & V_17 ) ) {
#ifdef F_7
F_4 ( V_18 L_18 ) ;
#endif
return - V_47 ;
}
#ifdef F_7
F_4 ( V_18 L_19 ) ;
#endif
V_5 [ V_15 ] |= V_16 ;
V_5 [ V_15 ] &= ~ V_29 ;
F_8 ( V_19 ) ;
V_5 [ V_20 ] |= V_21 ;
V_5 [ V_28 ] = V_39 -> V_45 [ 0 ] ;
V_58 = 1 ;
V_5 [ V_15 ] |= V_29 ;
V_35 = V_59 ;
return 0 ;
}
void
F_12 ( void )
{
unsigned long V_50 ;
F_15 ( V_50 ) ;
if ( V_5 [ V_26 ] & V_24 ) {
V_10 ( 0 , NULL ) ;
}
else
F_8 ( V_19 ) ;
F_17 ( V_50 ) ;
}
static T_2
V_10 ( int V_60 , void * V_61 )
{
int V_14 ;
struct V_38 * V_39 ;
#ifdef F_7
static int V_62 = 0 ;
#endif
int V_31 ;
unsigned long V_50 ;
F_15 ( V_50 ) ;
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
#ifdef F_7
F_4 ( V_18 L_20 , V_35 , V_14 , V_5 [ V_26 ] ) ;
#endif
if ( ! ( V_5 [ V_26 ] & V_24 ) ) {
F_4 ( V_8 L_21 ) ;
F_17 ( V_50 ) ;
return V_63 ;
}
V_64:
switch ( V_35 ) {
case V_36 :
if ( V_14 & V_16 )
F_4 ( V_8 L_22 ) ;
if( ! V_65 )
F_8 ( V_19 ) ;
V_5 [ V_20 ] &= ~ V_21 ;
V_5 [ V_15 ] |= V_16 ;
V_27 = V_5 [ V_28 ] ;
V_5 [ V_15 ] |= V_29 ;
F_8 ( V_19 ) ;
V_5 [ V_15 ] &= ~ V_29 ;
V_55 = 0 ;
V_35 = V_66 ;
if ( V_65 ) {
V_67 = V_56 -> V_68 ;
} else {
V_67 = V_69 ;
}
break;
case V_59 :
V_5 [ V_15 ] &= ~ V_29 ;
V_39 = V_56 ;
if ( ! ( V_14 & V_17 ) ) {
F_4 ( V_8 L_23 ) ;
V_5 [ V_20 ] &= ~ V_21 ;
V_27 = V_5 [ V_28 ] ;
V_5 [ V_15 ] &= ~ V_16 ;
V_65 = 0 ;
V_55 = 0 ;
V_35 = V_36 ;
F_8 ( V_19 ) ;
goto V_64;
}
F_8 ( V_19 ) ;
if ( V_58 >= V_39 -> V_44 ) {
V_5 [ V_20 ] &= ~ V_21 ;
V_27 = V_5 [ V_28 ] ;
V_5 [ V_15 ] &= ~ V_16 ;
V_39 -> V_54 = 1 ;
V_35 = V_36 ;
if ( V_39 -> V_46 ) {
V_65 = 1 ;
} else {
V_56 = V_39 -> V_53 ;
if ( V_39 -> F_14 )
(* V_39 -> F_14 )( V_39 ) ;
V_31 = F_16 () ;
if( V_31 == 0 && V_37 ) {
F_11 ( V_56 ) ;
}
if( V_31 != - V_47 )
V_37 = 0 ;
}
} else {
V_5 [ V_20 ] |= V_21 ;
V_5 [ V_28 ] = V_39 -> V_45 [ V_58 ++ ] ;
V_5 [ V_15 ] |= V_29 ;
}
break;
case V_66 :
if ( V_55 ++ > 16 ) {
F_4 ( V_8 L_24 ) ;
V_5 [ V_15 ] |= V_29 ;
F_8 ( V_19 ) ;
V_5 [ V_15 ] &= ~ ( V_29 | V_16 ) ;
V_35 = V_36 ;
V_31 = F_16 () ;
if( V_31 == 0 && V_37 ) {
F_11 ( V_56 ) ;
}
if( V_31 != - V_47 )
V_37 = 0 ;
break;
}
* V_67 ++ = V_5 [ V_28 ] ;
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
V_5 [ V_15 ] |= V_29 ;
F_8 ( V_19 ) ;
V_5 [ V_15 ] &= ~ V_29 ;
if ( ! ( V_14 & V_17 ) )
break;
V_5 [ V_15 ] &= ~ V_16 ;
V_27 = V_5 [ V_28 ] ;
F_8 ( V_19 ) ;
if ( V_65 ) {
V_39 = V_56 ;
V_39 -> V_55 = V_67 - V_39 -> V_68 ;
if ( V_39 -> V_45 [ 0 ] == V_70 ) {
if ( V_39 -> V_55 <= 2 || ( V_39 -> V_68 [ 1 ] & 2 ) != 0 ) {
V_39 -> V_55 = 0 ;
} else {
V_39 -> V_55 -= 2 ;
memmove ( V_39 -> V_68 , V_39 -> V_68 + 2 , V_39 -> V_55 ) ;
}
}
#ifdef F_7
if ( V_62 ) {
int V_31 ;
F_4 ( V_18 L_25 ) ;
for ( V_31 = 0 ; V_31 < V_39 -> V_55 ; ++ V_31 )
F_4 ( L_10 , V_39 -> V_68 [ V_31 ] ) ;
F_4 ( L_26 ) ;
}
#endif
V_39 -> V_42 = 1 ;
V_56 = V_39 -> V_53 ;
if ( V_39 -> F_14 )
(* V_39 -> F_14 )( V_39 ) ;
V_65 = 0 ;
} else {
F_18 ( V_69 , V_67 - V_69 ) ;
}
V_35 = V_36 ;
V_14 = V_5 [ V_15 ] & ( V_16 | V_17 ) ;
if ( ! ( V_14 & V_17 ) ) {
#ifdef F_7
F_4 ( V_18 L_27 ,
V_14 , V_5 [ V_26 ] ) ;
#endif
#if 0
udelay(ADB_DELAY);
via[B] |= TIP;
maciisi_state = reading;
reading_reply = 0;
reply_ptr = maciisi_rbuf;
#else
V_65 = 0 ;
goto V_64;
#endif
}
else {
V_31 = F_16 () ;
if( V_31 == 0 && V_37 ) {
F_11 ( V_56 ) ;
}
if( V_31 != - V_47 )
V_37 = 0 ;
}
break;
default:
F_4 ( L_28 , V_35 ) ;
}
F_17 ( V_50 ) ;
return V_71 ;
}
static void
F_18 ( unsigned char * V_72 , int V_73 )
{
#ifdef F_7
int V_31 ;
#endif
switch ( V_72 [ 0 ] ) {
case V_70 :
F_19 ( V_72 + 2 , V_73 - 2 , V_72 [ 1 ] & 0x40 ) ;
break;
default:
#ifdef F_7
F_4 ( V_18 L_29 , V_73 ) ;
for ( V_31 = 0 ; V_31 < V_73 ; ++ V_31 )
F_4 ( L_10 , V_72 [ V_31 ] ) ;
F_4 ( L_26 ) ;
#endif
break;
}
}
