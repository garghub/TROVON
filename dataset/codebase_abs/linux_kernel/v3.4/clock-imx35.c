static void F_1 ( T_1 div , T_1 * V_1 , T_1 * V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 , V_6 , V_7 ;
V_4 = ( div - 1 ) / V_3 + 1 ;
V_6 = 8 ;
for ( V_5 = 8 ; V_5 >= V_4 ; V_5 -- ) {
if ( div > ( V_5 * V_3 ) )
break;
if ( div < ( V_5 * V_5 ) )
continue;
V_7 = div % V_5 ;
if ( V_7 == 0 ) {
* V_1 = V_5 ;
break;
}
V_7 = V_5 - V_7 ;
if ( V_7 < V_6 ) {
V_6 = V_7 ;
* V_1 = V_5 ;
}
}
* V_2 = ( div + * V_1 - 1 ) / * V_1 ;
}
static void F_2 ( T_1 div , T_1 * V_1 , T_1 * V_2 )
{
if ( div >= 512 ) {
* V_1 = 8 ;
* V_2 = 64 ;
} else if ( div >= 64 ) {
F_1 ( div , V_1 , V_2 , 64 ) ;
} else if ( div <= 8 ) {
* V_1 = div ;
* V_2 = 1 ;
} else {
* V_1 = 1 ;
* V_2 = div ;
}
}
static void F_3 ( T_1 div , T_1 * V_1 , T_1 * V_2 )
{
if ( div >= 64 ) {
* V_1 = * V_2 = 8 ;
} else if ( div > 8 ) {
F_1 ( div , V_1 , V_2 , 8 ) ;
} else {
* V_1 = 1 ;
* V_2 = div ;
}
}
static unsigned long F_4 ( void )
{
T_2 V_8 = F_5 ( V_9 ) ;
return F_6 ( V_8 , 24000000 ) ;
}
static unsigned long F_7 ( void )
{
T_2 V_10 = F_5 ( V_11 ) ;
return F_6 ( V_10 , 24000000 ) ;
}
static unsigned long F_8 ( void )
{
unsigned long V_12 = F_5 ( V_13 ) ;
struct V_14 * V_15 ;
unsigned long V_16 = F_4 () ;
V_15 = & V_17 [ ( V_12 >> 16 ) & 0xf ] ;
if ( V_15 -> V_18 )
V_16 = V_16 * 3 / 4 ;
return V_16 / V_15 -> V_19 ;
}
static unsigned long F_9 ( struct V_20 * V_20 )
{
unsigned long V_12 = F_5 ( V_13 ) ;
struct V_14 * V_15 ;
unsigned long V_16 = F_8 () ;
V_15 = & V_17 [ ( V_12 >> 16 ) & 0xf ] ;
return V_16 / V_15 -> V_21 ;
}
static unsigned long F_10 ( struct V_20 * V_20 )
{
return F_9 ( NULL ) >> 1 ;
}
static unsigned long F_11 ( struct V_20 * V_20 )
{
unsigned long V_22 = F_5 ( V_23 ) ;
unsigned long V_24 = F_5 ( V_25 ) ;
unsigned long div = ( ( V_24 >> 10 ) & 0x3f ) + 1 ;
if ( V_22 & ( 1 << 14 ) )
return F_8 () / div ;
else
return F_7 () / div ;
}
static unsigned long F_12 ( struct V_20 * V_20 )
{
unsigned long V_22 = F_5 ( V_23 ) ;
unsigned long div , V_26 ;
if ( V_22 & ( 1 << 6 ) )
V_26 = F_8 () ;
else
V_26 = F_7 () ;
switch ( V_20 -> V_27 ) {
default:
case 0 :
div = V_22 & 0x3f ;
break;
case 1 :
div = ( V_22 >> 8 ) & 0x3f ;
break;
case 2 :
div = ( V_22 >> 16 ) & 0x3f ;
break;
}
return V_26 / ( div + 1 ) ;
}
static unsigned long F_13 ( struct V_20 * V_20 )
{
unsigned long V_28 = F_5 ( V_29 ) ;
unsigned long V_30 , V_31 , V_26 ;
if ( V_28 & ( 1 << 7 ) )
V_26 = F_8 () ;
else
V_26 = F_7 () ;
V_30 = ( V_28 >> 29 ) & 0x7 ;
V_31 = ( V_28 >> 22 ) & 0x3f ;
return V_26 / ( ( V_30 + 1 ) * ( V_31 + 1 ) ) ;
}
static unsigned long F_14 ( struct V_20 * V_20 )
{
unsigned long V_32 = F_5 ( V_33 ) ;
unsigned long V_30 , V_31 , V_26 ;
if ( V_32 & ( 1 << 6 ) )
V_26 = F_8 () ;
else
V_26 = F_7 () ;
switch ( V_20 -> V_27 ) {
default:
case 0 :
V_30 = V_32 & 0x3f ;
V_31 = ( V_32 >> 24 ) & 0x7 ;
break;
case 1 :
V_30 = ( V_32 >> 8 ) & 0x3f ;
V_31 = ( V_32 >> 27 ) & 0x7 ;
break;
}
return V_26 / ( ( V_30 + 1 ) * ( V_31 + 1 ) ) ;
}
static unsigned long F_15 ( struct V_20 * V_20 )
{
unsigned long V_32 = F_5 ( V_33 ) ;
unsigned long V_26 ;
if ( V_32 & ( 1 << 7 ) )
V_26 = F_8 () ;
else
V_26 = F_7 () ;
return V_26 / ( ( ( V_32 >> 16 ) & 0x3f ) + 1 ) ;
}
static unsigned long F_16 ( struct V_20 * V_20 )
{
unsigned long V_24 = F_5 ( V_25 ) ;
unsigned long V_26 ;
if ( V_24 & ( 1 << 9 ) )
V_26 = F_8 () ;
else
V_26 = F_7 () ;
return V_26 / ( ( ( V_24 >> 22 ) & 0x3f ) + 1 ) ;
}
static unsigned long F_17 ( struct V_20 * V_20 )
{
unsigned long V_12 = F_5 ( V_13 ) ;
unsigned long V_24 = F_5 ( V_25 ) ;
unsigned long div ;
if ( V_12 & ( 1 << 26 ) ) {
div = ( V_24 >> 16 ) & 0x3f ;
return F_8 () / ( div + 1 ) ;
} else {
div = ( V_12 >> 12 ) & 0x7 ;
return F_9 ( NULL ) / ( div + 1 ) ;
}
}
static unsigned long F_18 ( struct V_20 * V_20 )
{
unsigned long V_34 = ( F_5 ( V_13 ) >> 20 ) & 0x03 ;
unsigned long V_16 = F_4 () ;
if ( V_16 > 400 * 1000 * 1000 ) {
switch ( V_34 ) {
case 0 :
return V_16 >> 2 ;
case 1 :
return V_16 >> 3 ;
case 2 :
return V_16 / 3 ;
}
} else {
switch ( V_34 ) {
case 0 :
case 2 :
return V_16 / 3 ;
case 1 :
return V_16 / 6 ;
}
}
return 0 ;
}
static int F_19 ( struct V_20 * V_20 )
{
T_1 V_35 ;
V_35 = F_5 ( V_20 -> V_36 ) ;
V_35 |= 3 << V_20 -> V_37 ;
F_20 ( V_35 , V_20 -> V_36 ) ;
return 0 ;
}
static void F_21 ( struct V_20 * V_20 )
{
T_1 V_35 ;
V_35 = F_5 ( V_20 -> V_36 ) ;
V_35 &= ~ ( 3 << V_20 -> V_37 ) ;
F_20 ( V_35 , V_20 -> V_36 ) ;
}
static int F_22 ( struct V_20 * V_20 )
{
return 0 ;
}
static void F_23 ( struct V_20 * V_20 )
{
}
static unsigned long F_24 ( struct V_20 * V_20 )
{
unsigned long V_30 ;
V_30 = ( F_5 ( V_25 ) >> 28 ) + 1 ;
return F_9 ( NULL ) / V_30 ;
}
int T_3 F_25 ()
{
unsigned int V_38 = 3 << 26 ;
#if F_26 ( V_39 ) && ! F_26 ( V_40 )
V_38 |= 3 << 16 ;
#endif
F_27 ( V_41 , F_28 ( V_41 ) ) ;
F_20 ( ( 3 << 18 ) , V_42 ) ;
F_20 ( ( 3 << 2 ) | ( 3 << 4 ) | ( 3 << 6 ) | ( 3 << 8 ) | ( 3 << 16 ) ,
V_43 ) ;
F_20 ( V_38 , V_44 ) ;
F_20 ( 0 , V_45 ) ;
F_29 ( & V_46 ) ;
F_30 ( L_1 , F_31 () ) ;
F_32 ( & V_46 ) ;
if ( ! ( F_5 ( V_47 ) & ( 3 << 10 ) ) ) {
F_29 ( & V_46 ) ;
F_29 ( & V_48 ) ;
F_29 ( & V_49 ) ;
}
#ifdef F_33
F_34 ( & V_50 ,
F_35 ( V_51 ) , V_52 ) ;
#else
F_36 ( & V_53 ,
F_35 ( V_54 ) , V_55 ) ;
#endif
return 0 ;
}
