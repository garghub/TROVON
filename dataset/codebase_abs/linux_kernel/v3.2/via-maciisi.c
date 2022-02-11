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
if ( F_5 ( V_9 , V_10 , 0 , L_2 ,
V_10 ) ) {
F_4 ( V_8 L_3 , V_9 ) ;
return - V_11 ;
}
F_4 ( L_4 ) ;
return 0 ;
}
static void
F_6 ( void )
{
int V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
if ( V_12 & V_15 ) {
#ifdef F_7
F_4 ( V_16 L_5 ) ;
#endif
return;
}
F_8 ( V_17 ) ;
V_5 [ V_18 ] &= ~ V_19 ;
V_5 [ V_20 ] = V_21 | V_22 ;
F_8 ( V_17 ) ;
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
if ( ! ( V_12 & V_15 ) )
{
V_5 [ V_13 ] |= V_14 ;
while( 1 )
{
int V_23 = V_17 * 5 ;
while ( ! ( V_5 [ V_24 ] & V_22 ) && V_23 -- > 0 )
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
V_25 = V_5 [ V_26 ] ;
#ifdef F_7
F_4 ( V_16 L_6 ,
V_12 , V_23 , V_25 ) ;
#endif
if( V_5 [ V_13 ] & V_15 )
break;
V_5 [ V_13 ] |= V_27 ;
F_8 ( V_17 ) ;
V_5 [ V_13 ] &= ~ V_27 ;
}
V_5 [ V_13 ] &= ~ V_14 ;
F_8 ( V_17 ) ;
}
V_5 [ V_20 ] = V_28 | V_22 ;
}
static int
F_3 ( void )
{
int V_29 ;
V_5 [ V_30 ] = ( V_5 [ V_30 ] | V_27 | V_14 ) & ~ V_15 ;
V_5 [ V_18 ] = ( V_5 [ V_18 ] & ~ V_31 ) | V_32 ;
#ifdef F_7
F_4 ( V_16 L_7 , V_5 [ V_13 ] & ( V_14 | V_15 ) ) ;
#endif
V_25 = V_5 [ V_26 ] ;
V_5 [ V_20 ] = V_28 | V_22 ;
V_5 [ V_13 ] &= ~ ( V_27 | V_14 ) ;
V_5 [ V_24 ] = V_22 ;
for( V_29 = 0 ; V_29 < 60 ; V_29 ++ ) {
F_8 ( V_17 ) ;
F_6 () ;
F_8 ( V_17 ) ;
if( V_5 [ V_13 ] & V_15 )
break;
}
if ( V_29 == 60 )
F_4 ( V_8 L_8 ) ;
V_33 = V_34 ;
V_35 = 0 ;
return 0 ;
}
static int
F_9 ( struct V_36 * V_37 , int V_38 )
{
int V_29 ;
#ifdef F_7
static int V_39 = 0 ;
#endif
if ( V_5 == NULL ) {
V_37 -> V_40 = 1 ;
return - V_41 ;
}
#ifdef F_7
if ( V_39 ) {
F_4 ( V_16 L_9 ) ;
for ( V_29 = 0 ; V_29 < V_37 -> V_42 ; V_29 ++ ) {
F_4 ( L_10 , V_37 -> V_43 [ V_29 ] ) ;
}
F_4 ( L_11 , V_38 ) ;
}
#endif
V_37 -> V_44 = 1 ;
V_29 = F_10 ( V_37 ) ;
if ( V_29 )
{
if( V_29 == - V_45 && V_38 )
V_35 = 1 ;
else
V_35 = 0 ;
return V_29 ;
}
if( V_38 )
F_11 ( V_37 ) ;
return 0 ;
}
static void F_11 ( struct V_36 * V_37 )
{
int V_46 = 0 ;
#ifdef F_7
F_4 ( V_16 L_12 ) ;
#endif
while ( ! V_37 -> V_40 && V_46 ++ < 50 ) {
F_12 () ;
}
if ( V_46 > 50 )
F_4 ( V_8 L_13 ) ;
}
int
F_13 ( struct V_36 * V_37 , void (* F_14)( struct V_36 * ) ,
int V_42 , ... )
{
T_1 V_47 ;
int V_29 ;
V_37 -> V_42 = V_42 ;
V_37 -> F_14 = F_14 ;
V_37 -> V_44 = 0 ;
va_start ( V_47 , V_42 ) ;
for ( V_29 = 0 ; V_29 < V_42 ; V_29 ++ )
V_37 -> V_43 [ V_29 ++ ] = va_arg ( V_47 , int ) ;
va_end ( V_47 ) ;
return F_9 ( V_37 , 1 ) ;
}
static int
F_10 ( struct V_36 * V_37 )
{
unsigned long V_48 ;
int V_29 ;
if ( V_37 -> V_42 < 2 || V_37 -> V_43 [ 0 ] > V_49 ) {
F_4 ( V_8 L_14 ) ;
V_37 -> V_40 = 1 ;
return - V_50 ;
}
V_37 -> V_51 = NULL ;
V_37 -> V_52 = 0 ;
V_37 -> V_40 = 0 ;
V_37 -> V_53 = 0 ;
F_15 ( V_48 ) ;
if ( V_54 ) {
V_55 -> V_51 = V_37 ;
V_55 = V_37 ;
} else {
V_54 = V_37 ;
V_55 = V_37 ;
}
if ( V_33 == V_34 )
{
V_29 = F_16 () ;
if( V_29 != 0 )
{
F_17 ( V_48 ) ;
return V_29 ;
}
}
else
{
#ifdef F_7
F_4 ( V_16 L_15 , V_33 ) ;
#endif
F_17 ( V_48 ) ;
return - V_45 ;
}
F_17 ( V_48 ) ;
return 0 ;
}
static int
F_16 ( void )
{
struct V_36 * V_37 ;
int V_12 ;
#ifdef F_7
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
F_4 ( V_16 L_16 , V_33 , V_12 , V_5 [ V_24 ] ) ;
#endif
if ( V_33 != V_34 ) {
F_4 ( V_8 L_17 ) ;
return - V_45 ;
}
V_37 = V_54 ;
if ( V_37 == NULL )
return - V_50 ;
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
if ( ! ( V_12 & V_15 ) ) {
#ifdef F_7
F_4 ( V_16 L_18 ) ;
#endif
return - V_45 ;
}
#ifdef F_7
F_4 ( V_16 L_19 ) ;
#endif
V_5 [ V_13 ] |= V_14 ;
V_5 [ V_13 ] &= ~ V_27 ;
F_8 ( V_17 ) ;
V_5 [ V_18 ] |= V_19 ;
V_5 [ V_26 ] = V_37 -> V_43 [ 0 ] ;
V_56 = 1 ;
V_5 [ V_13 ] |= V_27 ;
V_33 = V_57 ;
return 0 ;
}
void
F_12 ( void )
{
unsigned long V_48 ;
F_15 ( V_48 ) ;
if ( V_5 [ V_24 ] & V_22 ) {
V_10 ( 0 , NULL ) ;
}
else
F_8 ( V_17 ) ;
F_17 ( V_48 ) ;
}
static T_2
V_10 ( int V_58 , void * V_59 )
{
int V_12 ;
struct V_36 * V_37 ;
#ifdef F_7
static int V_60 = 0 ;
#endif
int V_29 ;
unsigned long V_48 ;
F_15 ( V_48 ) ;
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
#ifdef F_7
F_4 ( V_16 L_20 , V_33 , V_12 , V_5 [ V_24 ] ) ;
#endif
if ( ! ( V_5 [ V_24 ] & V_22 ) ) {
F_4 ( V_8 L_21 ) ;
F_17 ( V_48 ) ;
return V_61 ;
}
V_62:
switch ( V_33 ) {
case V_34 :
if ( V_12 & V_14 )
F_4 ( V_8 L_22 ) ;
if( ! V_63 )
F_8 ( V_17 ) ;
V_5 [ V_18 ] &= ~ V_19 ;
V_5 [ V_13 ] |= V_14 ;
V_25 = V_5 [ V_26 ] ;
V_5 [ V_13 ] |= V_27 ;
F_8 ( V_17 ) ;
V_5 [ V_13 ] &= ~ V_27 ;
V_53 = 0 ;
V_33 = V_64 ;
if ( V_63 ) {
V_65 = V_54 -> V_66 ;
} else {
V_65 = V_67 ;
}
break;
case V_57 :
V_5 [ V_13 ] &= ~ V_27 ;
V_37 = V_54 ;
if ( ! ( V_12 & V_15 ) ) {
F_4 ( V_8 L_23 ) ;
V_5 [ V_18 ] &= ~ V_19 ;
V_25 = V_5 [ V_26 ] ;
V_5 [ V_13 ] &= ~ V_14 ;
V_63 = 0 ;
V_53 = 0 ;
V_33 = V_34 ;
F_8 ( V_17 ) ;
goto V_62;
}
F_8 ( V_17 ) ;
if ( V_56 >= V_37 -> V_42 ) {
V_5 [ V_18 ] &= ~ V_19 ;
V_25 = V_5 [ V_26 ] ;
V_5 [ V_13 ] &= ~ V_14 ;
V_37 -> V_52 = 1 ;
V_33 = V_34 ;
if ( V_37 -> V_44 ) {
V_63 = 1 ;
} else {
V_54 = V_37 -> V_51 ;
if ( V_37 -> F_14 )
(* V_37 -> F_14 )( V_37 ) ;
V_29 = F_16 () ;
if( V_29 == 0 && V_35 ) {
F_11 ( V_54 ) ;
}
if( V_29 != - V_45 )
V_35 = 0 ;
}
} else {
V_5 [ V_18 ] |= V_19 ;
V_5 [ V_26 ] = V_37 -> V_43 [ V_56 ++ ] ;
V_5 [ V_13 ] |= V_27 ;
}
break;
case V_64 :
if ( V_53 ++ > 16 ) {
F_4 ( V_8 L_24 ) ;
V_5 [ V_13 ] |= V_27 ;
F_8 ( V_17 ) ;
V_5 [ V_13 ] &= ~ ( V_27 | V_14 ) ;
V_33 = V_34 ;
V_29 = F_16 () ;
if( V_29 == 0 && V_35 ) {
F_11 ( V_54 ) ;
}
if( V_29 != - V_45 )
V_35 = 0 ;
break;
}
* V_65 ++ = V_5 [ V_26 ] ;
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
V_5 [ V_13 ] |= V_27 ;
F_8 ( V_17 ) ;
V_5 [ V_13 ] &= ~ V_27 ;
if ( ! ( V_12 & V_15 ) )
break;
V_5 [ V_13 ] &= ~ V_14 ;
V_25 = V_5 [ V_26 ] ;
F_8 ( V_17 ) ;
if ( V_63 ) {
V_37 = V_54 ;
V_37 -> V_53 = V_65 - V_37 -> V_66 ;
if ( V_37 -> V_43 [ 0 ] == V_68 ) {
if ( V_37 -> V_53 <= 2 || ( V_37 -> V_66 [ 1 ] & 2 ) != 0 ) {
V_37 -> V_53 = 0 ;
} else {
V_37 -> V_53 -= 2 ;
memmove ( V_37 -> V_66 , V_37 -> V_66 + 2 , V_37 -> V_53 ) ;
}
}
#ifdef F_7
if ( V_60 ) {
int V_29 ;
F_4 ( V_16 L_25 ) ;
for ( V_29 = 0 ; V_29 < V_37 -> V_53 ; ++ V_29 )
F_4 ( L_10 , V_37 -> V_66 [ V_29 ] ) ;
F_4 ( L_26 ) ;
}
#endif
V_37 -> V_40 = 1 ;
V_54 = V_37 -> V_51 ;
if ( V_37 -> F_14 )
(* V_37 -> F_14 )( V_37 ) ;
V_63 = 0 ;
} else {
F_18 ( V_67 , V_65 - V_67 ) ;
}
V_33 = V_34 ;
V_12 = V_5 [ V_13 ] & ( V_14 | V_15 ) ;
if ( ! ( V_12 & V_15 ) ) {
#ifdef F_7
F_4 ( V_16 L_27 ,
V_12 , V_5 [ V_24 ] ) ;
#endif
#if 0
udelay(ADB_DELAY);
via[B] |= TIP;
maciisi_state = reading;
reading_reply = 0;
reply_ptr = maciisi_rbuf;
#else
V_63 = 0 ;
goto V_62;
#endif
}
else {
V_29 = F_16 () ;
if( V_29 == 0 && V_35 ) {
F_11 ( V_54 ) ;
}
if( V_29 != - V_45 )
V_35 = 0 ;
}
break;
default:
F_4 ( L_28 , V_33 ) ;
}
F_17 ( V_48 ) ;
return V_69 ;
}
static void
F_18 ( unsigned char * V_70 , int V_71 )
{
#ifdef F_7
int V_29 ;
#endif
switch ( V_70 [ 0 ] ) {
case V_68 :
F_19 ( V_70 + 2 , V_71 - 2 , V_70 [ 1 ] & 0x40 ) ;
break;
default:
#ifdef F_7
F_4 ( V_16 L_29 , V_71 ) ;
for ( V_29 = 0 ; V_29 < V_71 ; ++ V_29 )
F_4 ( L_10 , V_70 [ V_29 ] ) ;
F_4 ( L_26 ) ;
#endif
break;
}
}
