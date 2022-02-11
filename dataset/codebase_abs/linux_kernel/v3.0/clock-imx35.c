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
T_2 V_8 = F_5 ( V_9 + V_10 ) ;
return F_6 ( V_8 , 24000000 ) ;
}
static unsigned long F_7 ( void )
{
T_2 V_11 = F_5 ( V_9 + V_12 ) ;
return F_6 ( V_11 , 24000000 ) ;
}
static unsigned long F_8 ( void )
{
unsigned long V_13 = F_5 ( V_9 + V_14 ) ;
struct V_15 * V_16 ;
unsigned long V_17 = F_4 () ;
V_16 = & V_18 [ ( V_13 >> 16 ) & 0xf ] ;
if ( V_16 -> V_19 )
V_17 = V_17 * 3 / 4 ;
return V_17 / V_16 -> V_20 ;
}
static unsigned long F_9 ( struct V_21 * V_21 )
{
unsigned long V_13 = F_5 ( V_9 + V_14 ) ;
struct V_15 * V_16 ;
unsigned long V_17 = F_8 () ;
V_16 = & V_18 [ ( V_13 >> 16 ) & 0xf ] ;
return V_17 / V_16 -> V_22 ;
}
static unsigned long F_10 ( struct V_21 * V_21 )
{
return F_9 ( NULL ) >> 1 ;
}
static unsigned long F_11 ( struct V_21 * V_21 )
{
unsigned long V_23 = F_5 ( V_9 + V_24 ) ;
unsigned long V_25 = F_5 ( V_9 + V_26 ) ;
unsigned long div = ( ( V_25 >> 10 ) & 0x3f ) + 1 ;
if ( V_23 & ( 1 << 14 ) )
return F_8 () / div ;
else
return F_7 () / div ;
}
static unsigned long F_12 ( struct V_21 * V_21 )
{
unsigned long V_23 = F_5 ( V_9 + V_24 ) ;
unsigned long div , V_27 ;
if ( V_23 & ( 1 << 6 ) )
V_27 = F_8 () ;
else
V_27 = F_7 () ;
switch ( V_21 -> V_28 ) {
default:
case 0 :
div = V_23 & 0x3f ;
break;
case 1 :
div = ( V_23 >> 8 ) & 0x3f ;
break;
case 2 :
div = ( V_23 >> 16 ) & 0x3f ;
break;
}
return V_27 / ( div + 1 ) ;
}
static unsigned long F_13 ( struct V_21 * V_21 )
{
unsigned long V_29 = F_5 ( V_9 + V_30 ) ;
unsigned long V_31 , V_32 , V_27 ;
if ( V_29 & ( 1 << 7 ) )
V_27 = F_8 () ;
else
V_27 = F_7 () ;
V_31 = ( V_29 >> 29 ) & 0x7 ;
V_32 = ( V_29 >> 22 ) & 0x3f ;
return V_27 / ( ( V_31 + 1 ) * ( V_32 + 1 ) ) ;
}
static unsigned long F_14 ( struct V_21 * V_21 )
{
unsigned long V_33 = F_5 ( V_9 + V_34 ) ;
unsigned long V_31 , V_32 , V_27 ;
if ( V_33 & ( 1 << 6 ) )
V_27 = F_8 () ;
else
V_27 = F_7 () ;
switch ( V_21 -> V_28 ) {
default:
case 0 :
V_31 = V_33 & 0x3f ;
V_32 = ( V_33 >> 24 ) & 0x7 ;
break;
case 1 :
V_31 = ( V_33 >> 8 ) & 0x3f ;
V_32 = ( V_33 >> 27 ) & 0x7 ;
break;
}
return V_27 / ( ( V_31 + 1 ) * ( V_32 + 1 ) ) ;
}
static unsigned long F_15 ( struct V_21 * V_21 )
{
unsigned long V_33 = F_5 ( V_9 + V_34 ) ;
unsigned long V_27 ;
if ( V_33 & ( 1 << 7 ) )
V_27 = F_8 () ;
else
V_27 = F_7 () ;
return V_27 / ( ( ( V_33 >> 16 ) & 0x3f ) + 1 ) ;
}
static unsigned long F_16 ( struct V_21 * V_21 )
{
unsigned long V_25 = F_5 ( V_9 + V_26 ) ;
unsigned long V_27 ;
if ( V_25 & ( 1 << 9 ) )
V_27 = F_8 () ;
else
V_27 = F_7 () ;
return V_27 / ( ( ( V_25 >> 22 ) & 0x3f ) + 1 ) ;
}
static unsigned long F_17 ( struct V_21 * V_21 )
{
unsigned long V_13 = F_5 ( V_9 + V_14 ) ;
unsigned long V_25 = F_5 ( V_9 + V_26 ) ;
unsigned long div ;
if ( V_13 & ( 1 << 26 ) ) {
div = ( V_25 >> 16 ) & 0x3f ;
return F_8 () / ( div + 1 ) ;
} else {
div = ( V_13 >> 12 ) & 0x7 ;
return F_9 ( NULL ) / ( div + 1 ) ;
}
}
static unsigned long F_18 ( struct V_21 * V_21 )
{
unsigned long V_35 = ( F_5 ( V_9 + V_14 ) >> 20 ) & 0x03 ;
unsigned long V_17 = F_4 () ;
if ( V_17 > 400 * 1000 * 1000 ) {
switch ( V_35 ) {
case 0 :
return V_17 >> 2 ;
case 1 :
return V_17 >> 3 ;
case 2 :
return V_17 / 3 ;
}
} else {
switch ( V_35 ) {
case 0 :
case 2 :
return V_17 / 3 ;
case 1 :
return V_17 / 6 ;
}
}
return 0 ;
}
static int F_19 ( struct V_21 * V_21 )
{
T_1 V_36 ;
V_36 = F_5 ( V_21 -> V_37 ) ;
V_36 |= 3 << V_21 -> V_38 ;
F_20 ( V_36 , V_21 -> V_37 ) ;
return 0 ;
}
static void F_21 ( struct V_21 * V_21 )
{
T_1 V_36 ;
V_36 = F_5 ( V_21 -> V_37 ) ;
V_36 &= ~ ( 3 << V_21 -> V_38 ) ;
F_20 ( V_36 , V_21 -> V_37 ) ;
}
static int F_22 ( struct V_21 * V_21 )
{
return 0 ;
}
static void F_23 ( struct V_21 * V_21 )
{
}
static unsigned long F_24 ( struct V_21 * V_21 )
{
unsigned long V_31 ;
V_31 = ( F_5 ( V_9 + V_26 ) >> 28 ) + 1 ;
return F_9 ( NULL ) / V_31 ;
}
int T_3 F_25 ()
{
unsigned int V_39 = 3 << 26 , V_40 = 0 ;
#if F_26 ( V_41 ) && ! F_26 ( V_42 )
V_39 |= 3 << 16 ;
#endif
F_27 ( V_43 , F_28 ( V_43 ) ) ;
F_20 ( ( 3 << 18 ) , V_9 + V_44 ) ;
F_20 ( ( 3 << 2 ) | ( 3 << 4 ) | ( 3 << 6 ) | ( 3 << 8 ) | ( 3 << 16 ) ,
V_9 + V_45 ) ;
if ( ! ( F_5 ( V_9 + V_46 ) & ( 3 << 10 ) ) ) {
V_39 |= 3 << 16 | 3 << 4 ;
V_40 |= 3 << 2 ;
}
F_20 ( V_39 , V_9 + V_47 ) ;
F_20 ( V_40 , V_9 + V_48 ) ;
F_29 ( & V_49 ) ;
F_30 () ;
#ifdef F_31
F_32 ( & V_50 ,
F_33 ( V_51 ) , V_52 ) ;
#else
F_34 ( & V_53 ,
F_33 ( V_54 ) , V_55 ) ;
#endif
return 0 ;
}
