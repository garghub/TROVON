static unsigned long
F_1 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
if ( V_2 >= 8 && V_2 < 24 )
return V_1 | ( ( V_2 - 8 ) & 0xf ) ;
else
{
* T_3 = _ ( L_1 ) ;
return 0 ;
}
}
static long
F_2 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( V_1 & 0xf ) + 8 ;
}
static unsigned long
F_3 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
if ( V_2 >= 8 && V_2 < 24 )
return V_1 | ( ( ( V_2 - 8 ) & 0xf ) << 4 ) ;
else
{
* T_3 = _ ( L_1 ) ;
return 0 ;
}
}
static long
F_4 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 4 ) & 0xf ) + 8 ;
}
static unsigned long
F_5 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( V_2 >= 0 && V_2 < 8 )
return V_1 | V_2 ;
else if ( V_2 >= 24 && V_2 <= 31 )
return V_1 | ( V_2 - 16 ) ;
else
{
* T_3 = _ ( L_1 ) ;
return 0 ;
}
}
static long
F_6 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
int V_2 = V_1 & 0xf ;
if ( V_2 >= 0 && V_2 < 8 )
return V_2 ;
else
return V_2 + 16 ;
}
static unsigned long
F_7 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( V_2 >= 0 && V_2 < 8 )
return V_1 | ( V_2 << 4 ) ;
else if ( V_2 >= 24 && V_2 <= 31 )
return V_1 | ( ( V_2 - 16 ) << 4 ) ;
else
{
* T_3 = _ ( L_1 ) ;
return 0 ;
}
}
static long
F_8 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
int V_2 = ( V_1 >> 4 ) & 0xf ;
if ( V_2 >= 0 && V_2 < 8 )
return V_2 ;
else
return V_2 + 16 ;
}
static unsigned long
F_9 ( unsigned long V_1 ,
long V_2 V_3 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( ( V_1 >> 21 ) & 0x1f ) << 16 ) ;
}
static long
F_10 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
if ( ( ( V_1 >> 21 ) & 0x1f ) != ( ( V_1 >> 16 ) & 0x1f ) )
* T_4 = 1 ;
return 0 ;
}
static unsigned long
F_11 ( unsigned long V_1 ,
long V_2 V_3 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( ( V_1 >> 16 ) & 0x1f ) << 11 ) ;
}
static long
F_12 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
if ( ( ( V_1 >> 16 ) & 0x1f ) != ( ( V_1 >> 11 ) & 0x1f ) )
* T_4 = 1 ;
return 0 ;
}
static unsigned long
F_13 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 V_3 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( V_2 & 0x8000 ) != 0 )
V_1 |= 1 << 21 ;
}
else
{
if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x04 << 21 ) )
V_1 |= 0x02 << 21 ;
else if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x10 << 21 ) )
V_1 |= 0x08 << 21 ;
}
return V_1 | ( V_2 & 0xfffc ) ;
}
static long
F_14 ( unsigned long V_1 ,
T_1 T_2 ,
int * T_4 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( ( V_1 & ( 1 << 21 ) ) == 0 ) != ( ( V_1 & ( 1 << 15 ) ) == 0 ) )
* T_4 = 1 ;
}
else
{
if ( ( V_1 & ( 0x17 << 21 ) ) != ( 0x06 << 21 )
&& ( V_1 & ( 0x1d << 21 ) ) != ( 0x18 << 21 ) )
* T_4 = 1 ;
}
return ( ( V_1 & 0xfffc ) ^ 0x8000 ) - 0x8000 ;
}
static unsigned long
F_15 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 V_3 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( V_2 & 0x8000 ) == 0 )
V_1 |= 1 << 21 ;
}
else
{
if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x04 << 21 ) )
V_1 |= 0x03 << 21 ;
else if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x10 << 21 ) )
V_1 |= 0x09 << 21 ;
}
return V_1 | ( V_2 & 0xfffc ) ;
}
static long
F_16 ( unsigned long V_1 ,
T_1 T_2 ,
int * T_4 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( ( V_1 & ( 1 << 21 ) ) == 0 ) == ( ( V_1 & ( 1 << 15 ) ) == 0 ) )
* T_4 = 1 ;
}
else
{
if ( ( V_1 & ( 0x17 << 21 ) ) != ( 0x07 << 21 )
&& ( V_1 & ( 0x1d << 21 ) ) != ( 0x19 << 21 ) )
* T_4 = 1 ;
}
return ( ( V_1 & 0xfffc ) ^ 0x8000 ) - 0x8000 ;
}
static inline int
F_17 ( long V_2 )
{
if ( ( V_2 & 0x14 ) == 0 )
return 1 ;
else if ( ( V_2 & 0x14 ) == 0x4 )
return ( V_2 & 0x2 ) == 0 ;
else if ( ( V_2 & 0x14 ) == 0x10 )
return ( V_2 & 0x8 ) == 0 ;
else
return V_2 == 0x14 ;
}
static inline int
F_18 ( long V_2 )
{
if ( ( V_2 & 0x14 ) == 0 )
return ( V_2 & 0x1 ) == 0 ;
else if ( ( V_2 & 0x14 ) == 0x14 )
return V_2 == 0x14 ;
else
return 1 ;
}
static int
F_19 ( long V_2 , T_1 T_2 , int V_5 )
{
int V_6 = F_17 ( V_2 ) ;
int V_7 = F_18 ( V_2 ) ;
if ( V_5 && T_2 == ~ ( T_1 ) V_8 )
return V_6 || V_7 ;
if ( ( T_2 & V_4 ) == 0 )
return V_6 ;
else
return V_7 ;
}
static unsigned long
F_20 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
if ( ! F_19 ( V_2 , T_2 , 0 ) )
* T_3 = _ ( L_2 ) ;
else if ( F_21 ( V_1 ) == 19 && ( V_1 & 0x400 ) && ! ( V_2 & 4 ) )
* T_3 = _ ( L_3 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 21 ) ;
}
static long
F_22 ( unsigned long V_1 ,
T_1 T_2 ,
int * T_4 )
{
long V_2 ;
V_2 = ( V_1 >> 21 ) & 0x1f ;
if ( ! F_19 ( V_2 , T_2 , 1 ) )
* T_4 = 1 ;
return V_2 ;
}
static unsigned long
F_23 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
if ( ! F_19 ( V_2 , T_2 , 0 ) )
* T_3 = _ ( L_2 ) ;
else if ( F_21 ( V_1 ) == 19 && ( V_1 & 0x400 ) && ! ( V_2 & 4 ) )
* T_3 = _ ( L_3 ) ;
else if ( ( V_2 & 1 ) != 0 )
* T_3 = _ ( L_4 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 21 ) ;
}
static long
F_24 ( unsigned long V_1 ,
T_1 T_2 ,
int * T_4 )
{
long V_2 ;
V_2 = ( V_1 >> 21 ) & 0x1f ;
if ( ! F_19 ( V_2 , T_2 , 1 ) )
* T_4 = 1 ;
return V_2 & 0x1e ;
}
static unsigned long
F_25 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 16 ) | ( ( V_2 & 0x20 ) >> 3 ) | ( V_2 & 0x40 ) ;
}
static long
F_26 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( V_1 & 0x40 ) | ( ( V_1 << 3 ) & 0x20 ) | ( ( V_1 >> 16 ) & 0x1f ) ;
}
static unsigned long
F_27 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( V_2 & 0xffc1 ) | ( ( V_2 & 0x3e ) << 15 ) ;
}
static long
F_28 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
unsigned long V_9 = ( V_1 & 0xffc1 ) | ( ( V_1 >> 15 ) & 0x3e ) ;
return ( V_9 ^ 0x8000 ) - 0x8000 ;
}
static unsigned long
F_29 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return F_27 ( V_1 , - V_2 , T_2 , T_3 ) ;
}
static long
F_30 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return - F_28 ( V_1 , T_2 , T_4 ) ;
}
static unsigned long
F_31 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
if ( ( V_1 & ( 1 << 20 ) ) != 0 )
{
if ( V_2 == 0 || ( V_2 & - V_2 ) != V_2 )
{
* T_3 = _ ( L_5 ) ;
V_2 = 0 ;
}
}
else if ( V_2 > 0
&& ( V_2 & - V_2 ) == V_2
&& ( ( T_2 & V_10 ) != 0
|| ( ( T_2 & V_8 ) != 0
&& ( V_1 & ( 0x3ff << 1 ) ) == 19 << 1 ) ) )
V_1 |= 1 << 20 ;
else if ( ( V_1 & ( 0x3ff << 1 ) ) == 19 << 1 )
{
if ( V_2 != - 1 )
* T_3 = _ ( L_6 ) ;
V_2 = 0 ;
}
return V_1 | ( ( V_2 & 0xff ) << 12 ) ;
}
static long
F_32 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
long V_11 = ( V_1 >> 12 ) & 0xff ;
if ( ( V_1 & ( 1 << 20 ) ) != 0 )
{
if ( V_11 == 0 || ( V_11 & - V_11 ) != V_11 )
* T_4 = 1 ;
}
else if ( ( V_1 & ( 0x3ff << 1 ) ) == 19 << 1 )
{
if ( V_11 != 0 )
* T_4 = 1 ;
else
V_11 = - 1 ;
}
return V_11 ;
}
static unsigned long
F_33 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0xf0000 ) >> 5 ) | ( ( V_2 & 0x0f800 ) << 5 ) | ( V_2 & 0x7ff ) ;
}
static long
F_34 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
long V_12 = ( ( V_1 & 0x4000 ) == 0x4000 ) ? 0xfff00000 : 0x00000000 ;
return V_12
| ( ( ( V_1 >> 11 ) & 0xf ) << 16 )
| ( ( ( V_1 >> 17 ) & 0xf ) << 12 )
| ( ( ( V_1 >> 16 ) & 0x1 ) << 11 )
| ( V_1 & 0x7ff ) ;
}
static unsigned long
F_35 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
if ( ( ( V_1 >> 1 ) & 0x3ff ) == 598 )
{
long V_13 = ( T_2 & V_10 ) ? 2 : 1 ;
if ( V_2 > V_13 )
{
* T_3 = _ ( L_7 ) ;
return V_1 ;
}
}
return V_1 | ( ( V_2 & 0x3 ) << 21 ) ;
}
static unsigned long
F_36 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
unsigned long V_14 = ( V_1 >> 21 ) & 0x03 ;
if ( V_2 == 0 )
{
if ( ( ( T_2 & V_15 ) != 0 && V_14 > 1 )
|| ( ( T_2 & V_16 ) != 0 && V_14 > 2 ) )
* T_3 = _ ( L_7 ) ;
return V_1 ;
}
if ( ( V_14 & ~ 0x1 )
|| ( ( ( V_2 >> 1 ) & 0x1 ) ^ V_14 ) == 0 )
* T_3 = _ ( L_8 ) ;
return V_1 | ( ( V_2 & 0xf ) << 16 ) ;
}
static unsigned long
F_37 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
unsigned long V_17 , V_11 ;
int V_18 , V_19 , V_20 , V_21 , V_22 ;
V_17 = V_2 ;
if ( V_17 == 0 )
{
* T_3 = _ ( L_9 ) ;
return V_1 ;
}
V_18 = 0 ;
V_19 = 32 ;
if ( ( V_17 & 1 ) != 0 )
V_22 = 1 ;
else
V_22 = 0 ;
V_21 = 0 ;
for ( V_20 = 0 , V_11 = 1L << 31 ; V_20 < 32 ; ++ V_20 , V_11 >>= 1 )
{
if ( ( V_17 & V_11 ) && ! V_22 )
{
++ V_21 ;
V_18 = V_20 ;
V_22 = 1 ;
}
else if ( ! ( V_17 & V_11 ) && V_22 )
{
++ V_21 ;
V_19 = V_20 ;
V_22 = 0 ;
}
}
if ( V_19 == 0 )
V_19 = 32 ;
if ( V_21 != 2 && ( V_21 != 0 || ! V_22 ) )
* T_3 = _ ( L_9 ) ;
return V_1 | ( V_18 << 6 ) | ( ( V_19 - 1 ) << 1 ) ;
}
static long
F_38 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
long V_23 ;
int V_18 , V_19 ;
int V_24 ;
* T_4 = 1 ;
V_18 = ( V_1 >> 6 ) & 0x1f ;
V_19 = ( V_1 >> 1 ) & 0x1f ;
if ( V_18 < V_19 + 1 )
{
V_23 = 0 ;
for ( V_24 = V_18 ; V_24 <= V_19 ; V_24 ++ )
V_23 |= 1L << ( 31 - V_24 ) ;
}
else if ( V_18 == V_19 + 1 )
V_23 = ~ 0 ;
else
{
V_23 = ~ 0 ;
for ( V_24 = V_19 + 1 ; V_24 < V_18 ; V_24 ++ )
V_23 &= ~ ( 1L << ( 31 - V_24 ) ) ;
}
return V_23 ;
}
static unsigned long
F_39 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 6 ) | ( V_2 & 0x20 ) ;
}
static long
F_40 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 6 ) & 0x1f ) | ( V_1 & 0x20 ) ;
}
static long
F_41 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
long V_23 ;
V_23 = ( V_1 >> 11 ) & 0x1f ;
if ( V_23 == 0 )
V_23 = 32 ;
return V_23 ;
}
static unsigned long
F_42 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
long V_25 = ( V_1 & V_26 ) >> 21 ;
long V_27 = ( V_1 & V_28 ) >> 16 ;
if ( V_2 == 0 )
V_2 = 32 ;
if ( V_25 + ( V_2 + 3 ) / 4 > ( V_25 > V_27 ? V_27 + 32
: V_27 ) )
* T_3 = _ ( L_10 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 11 ) ;
}
static unsigned long
F_43 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( - V_2 & 0xffff ) ;
}
static long
F_44 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
* T_4 = 1 ;
return - ( ( ( V_1 & 0xffff ) ^ 0x8000 ) - 0x8000 ) ;
}
static unsigned long
F_45 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( V_2 == 0
|| ( unsigned long ) V_2 == ( ( V_1 >> 21 ) & 0x1f ) )
* T_3 = L_11 ;
return V_1 | ( ( V_2 & 0x1f ) << 16 ) ;
}
static unsigned long
F_46 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( ( unsigned long ) V_2 >= ( ( V_1 >> 21 ) & 0x1f ) )
* T_3 = _ ( L_12 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 16 ) ;
}
static unsigned long
F_47 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
long V_25 = ( V_1 & V_26 ) >> 21 ;
if ( V_2 == V_25 )
* T_3 = _ ( L_13 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 16 ) ;
}
static unsigned long
F_48 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( V_2 == 0 )
* T_3 = _ ( L_11 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 16 ) ;
}
static unsigned long
F_49 ( unsigned long V_1 ,
long V_2 V_3 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( ( V_1 >> 21 ) & 0x1f ) << 11 ) ;
}
static long
F_50 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
if ( ( ( V_1 >> 21 ) & 0x1f ) != ( ( V_1 >> 11 ) & 0x1f ) )
* T_4 = 1 ;
return 0 ;
}
static unsigned long
F_51 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
long V_25 = ( V_1 & V_26 ) >> 21 ;
if ( V_2 == V_25 )
* T_3 = _ ( L_13 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 11 ) ;
}
static unsigned long
F_52 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
unsigned int V_29 = 0 ;
unsigned long V_30 = V_2 ;
if ( ( V_30 & 0xffffff00 ) == 0 )
;
else if ( ( V_30 & 0xffffff00 ) == 0xffffff00 )
V_29 = 0x400 ;
else if ( ( V_30 & 0xffff00ff ) == 0 )
{
V_29 = 1 << 8 ;
V_30 >>= 8 ;
}
else if ( ( V_30 & 0xffff00ff ) == 0xffff00ff )
{
V_29 = 0x400 | ( 1 << 8 ) ;
V_30 >>= 8 ;
}
else if ( ( V_30 & 0xff00ffff ) == 0 )
{
V_29 = 2 << 8 ;
V_30 >>= 16 ;
}
else if ( ( V_30 & 0xff00ffff ) == 0xff00ffff )
{
V_29 = 0x400 | ( 2 << 8 ) ;
V_30 >>= 16 ;
}
else if ( ( V_30 & 0x00ffffff ) == 0 )
{
V_29 = 3 << 8 ;
V_30 >>= 24 ;
}
else if ( ( V_30 & 0x00ffffff ) == 0x00ffffff )
{
V_29 = 0x400 | ( 3 << 8 ) ;
V_30 >>= 24 ;
}
else
{
* T_3 = _ ( L_14 ) ;
V_30 = 0 ;
}
return V_1 | V_29 | ( V_30 & 0xff ) ;
}
static long
F_53 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
int V_31 = V_1 & 0x400 ;
int V_32 = ( V_1 & 0x300 ) >> 5 ;
long V_2 = ( V_1 & 0xff ) << V_32 ;
if ( V_31 != 0 )
V_2 |= ~ ( ( long ) 0xff << V_32 ) ;
return V_2 ;
}
static unsigned long
F_54 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
return F_52 ( V_1 , - V_2 , T_2 , T_3 ) ;
}
static long
F_55 ( unsigned long V_1 ,
T_1 T_2 ,
int * T_4 )
{
return - F_53 ( V_1 , T_2 , T_4 ) ;
}
static unsigned long
F_56 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1e ) << 7 ) ;
}
static long
F_57 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 8 ) & 0xf ) << 1 ;
}
static unsigned long
F_58 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x3c ) << 6 ) ;
}
static long
F_59 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 8 ) & 0xf ) << 2 ;
}
static unsigned long
F_60 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( ( V_2 - 1 ) & 0x1f ) << 4 ) ;
}
static long
F_61 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 4 ) & 0x1f ) + 1 ;
}
static unsigned long
F_62 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
if ( F_21 ( V_1 ) == 4 )
return V_1 | ( ( V_2 & 0x1f ) << 6 ) | ( ( V_2 & 0x20 ) >> 5 ) ;
else
return V_1 | ( ( V_2 & 0x1f ) << 11 ) | ( ( V_2 & 0x20 ) >> 4 ) ;
}
static long
F_63 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
if ( F_21 ( V_1 ) == 4 )
return ( ( V_1 >> 6 ) & 0x1f ) | ( ( V_1 << 5 ) & 0x20 ) ;
else
return ( ( V_1 >> 11 ) & 0x1f ) | ( ( V_1 << 4 ) & 0x20 ) ;
}
static unsigned long
F_64 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 16 ) | ( ( V_2 & 0x3e0 ) << 6 ) ;
}
static long
F_65 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 16 ) & 0x1f ) | ( ( V_1 >> 6 ) & 0x3e0 ) ;
}
static unsigned long
F_66 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 ,
const char * * T_3 )
{
if ( V_2 > 7
|| ( V_2 > 3 && ( T_2 & V_33 ) == 0 ) )
* T_3 = _ ( L_15 ) ;
if ( V_2 <= 3 || ( V_1 & 0x100 ) != 0 )
V_2 |= 0x10 ;
return V_1 | ( ( V_2 & 0x17 ) << 16 ) ;
}
static long
F_67 ( unsigned long V_1 ,
T_1 T_2 ,
int * T_4 )
{
unsigned long V_34 = ( V_1 >> 16 ) & 0x1f ;
if ( ( V_34 - 0x10 > 3 && ( T_2 & V_33 ) == 0 )
|| ( V_34 - 0x10 > 7 && ( V_1 & 0x100 ) != 0 )
|| V_34 <= 3
|| ( V_34 & 8 ) != 0 )
* T_4 = 1 ;
return V_34 & 7 ;
}
static unsigned long
F_68 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( V_2 != 268 && V_2 != 269 )
* T_3 = _ ( L_16 ) ;
return V_1 | ( ( V_2 & 0x1f ) << 16 ) | ( ( V_2 & 0x3e0 ) << 6 ) ;
}
static long
F_69 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
long V_23 ;
V_23 = ( ( V_1 >> 16 ) & 0x1f ) | ( ( V_1 >> 6 ) & 0x3e0 ) ;
if ( V_23 != 268 && V_23 != 269 )
* T_4 = 1 ;
return V_23 ;
}
static unsigned long
F_70 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 21 ) | ( ( V_2 & 0x20 ) >> 5 ) ;
}
static long
F_71 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 << 5 ) & 0x20 ) | ( ( V_1 >> 21 ) & 0x1f ) ;
}
static unsigned long
F_72 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 21 ) | ( ( V_2 & 0x20 ) >> 2 ) ;
}
static long
F_73 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 << 2 ) & 0x20 ) | ( ( V_1 >> 21 ) & 0x1f ) ;
}
static unsigned long
F_74 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 16 ) | ( ( V_2 & 0x20 ) >> 3 ) ;
}
static long
F_75 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 << 3 ) & 0x20 ) | ( ( V_1 >> 16 ) & 0x1f ) ;
}
static unsigned long
F_76 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 11 ) | ( ( V_2 & 0x20 ) >> 4 ) ;
}
static long
F_77 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 << 4 ) & 0x20 ) | ( ( V_1 >> 11 ) & 0x1f ) ;
}
static unsigned long
F_78 ( unsigned long V_1 ,
long V_2 V_3 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( ( V_1 >> 16 ) & 0x1f ) << 11 ) | ( ( ( V_1 >> 2 ) & 0x1 ) << 1 ) ;
}
static long
F_79 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
if ( ( ( ( V_1 >> 16 ) & 0x1f ) != ( ( V_1 >> 11 ) & 0x1f ) )
|| ( ( ( V_1 >> 2 ) & 0x1 ) != ( ( V_1 >> 1 ) & 0x1 ) ) )
* T_4 = 1 ;
return 0 ;
}
static unsigned long
F_80 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0x1f ) << 6 ) | ( ( V_2 & 0x20 ) >> 2 ) ;
}
static long
F_81 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 << 2 ) & 0x20 ) | ( ( V_1 >> 6 ) & 0x1f ) ;
}
static unsigned long
F_82 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 )
{
if ( V_2 != 0 && V_2 != 1 )
* T_3 = _ ( L_17 ) ;
return V_1 | ( ( ( V_2 ) ? 3 : 0 ) << 8 ) ;
}
static long
F_83 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 )
{
long V_2 ;
V_2 = ( V_1 >> 8 ) & 3 ;
if ( V_2 != 0 && V_2 != 3 )
* T_4 = 1 ;
return ( V_2 ) ? 1 : 0 ;
}
static unsigned long
F_84 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0xf800 ) << 10 ) | ( V_2 & 0x7ff ) ;
}
static long
F_85 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
long V_2 = ( ( V_1 >> 10 ) & 0xf800 ) | ( V_1 & 0x7ff ) ;
V_2 = ( V_2 ^ 0x8000 ) - 0x8000 ;
return V_2 ;
}
static unsigned long
F_86 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
V_2 = - V_2 ;
return V_1 | ( ( V_2 & 0xf800 ) << 10 ) | ( V_2 & 0x7ff ) ;
}
static long
F_87 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
long V_2 = ( ( V_1 >> 10 ) & 0xf800 ) | ( V_1 & 0x7ff ) ;
V_2 = ( V_2 ^ 0x8000 ) - 0x8000 ;
* T_4 = 1 ;
return - V_2 ;
}
static unsigned long
F_88 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0xf800 ) << 10 ) | ( V_2 & 0x7ff ) ;
}
static long
F_89 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 10 ) & 0xf800 ) | ( V_1 & 0x7ff ) ;
}
static unsigned long
F_90 ( unsigned long V_1 ,
long V_2 ,
T_1 T_2 V_3 ,
const char * * T_3 V_3 )
{
return V_1 | ( ( V_2 & 0xf800 ) << 5 ) | ( V_2 & 0x7ff ) ;
}
static long
F_91 ( unsigned long V_1 ,
T_1 T_2 V_3 ,
int * T_4 V_3 )
{
return ( ( V_1 >> 5 ) & 0xf800 ) | ( V_1 & 0x7ff ) ;
}
