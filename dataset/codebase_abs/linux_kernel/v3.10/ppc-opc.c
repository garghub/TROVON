static unsigned long
F_1 ( unsigned long V_1 ,
long T_1 V_2 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( ( ( V_1 >> 21 ) & 0x1f ) << 16 ) ;
}
static long
F_2 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 )
{
if ( ( ( V_1 >> 21 ) & 0x1f ) != ( ( V_1 >> 16 ) & 0x1f ) )
* V_3 = 1 ;
return 0 ;
}
static unsigned long
F_3 ( unsigned long V_1 ,
long T_1 V_2 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( ( ( V_1 >> 16 ) & 0x1f ) << 11 ) ;
}
static long
F_4 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 )
{
if ( ( ( V_1 >> 16 ) & 0x1f ) != ( ( V_1 >> 11 ) & 0x1f ) )
* V_3 = 1 ;
return 0 ;
}
static unsigned long
F_5 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( T_1 & 0xfffc ) ;
}
static long
F_6 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 & 0xfffc ) ^ 0x8000 ) - 0x8000 ;
}
static unsigned long
F_7 ( unsigned long V_1 ,
long T_1 ,
int T_2 ,
const char * * T_3 V_2 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( T_1 & 0x8000 ) != 0 )
V_1 |= 1 << 21 ;
}
else
{
if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x04 << 21 ) )
V_1 |= 0x02 << 21 ;
else if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x10 << 21 ) )
V_1 |= 0x08 << 21 ;
}
return V_1 | ( T_1 & 0xfffc ) ;
}
static long
F_8 ( unsigned long V_1 ,
int T_2 ,
int * V_3 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( ( V_1 & ( 1 << 21 ) ) == 0 ) != ( ( V_1 & ( 1 << 15 ) ) == 0 ) )
* V_3 = 1 ;
}
else
{
if ( ( V_1 & ( 0x17 << 21 ) ) != ( 0x06 << 21 )
&& ( V_1 & ( 0x1d << 21 ) ) != ( 0x18 << 21 ) )
* V_3 = 1 ;
}
return ( ( V_1 & 0xfffc ) ^ 0x8000 ) - 0x8000 ;
}
static unsigned long
F_9 ( unsigned long V_1 ,
long T_1 ,
int T_2 ,
const char * * T_3 V_2 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( T_1 & 0x8000 ) == 0 )
V_1 |= 1 << 21 ;
}
else
{
if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x04 << 21 ) )
V_1 |= 0x03 << 21 ;
else if ( ( V_1 & ( 0x14 << 21 ) ) == ( 0x10 << 21 ) )
V_1 |= 0x09 << 21 ;
}
return V_1 | ( T_1 & 0xfffc ) ;
}
static long
F_10 ( unsigned long V_1 ,
int T_2 ,
int * V_3 )
{
if ( ( T_2 & V_4 ) == 0 )
{
if ( ( ( V_1 & ( 1 << 21 ) ) == 0 ) == ( ( V_1 & ( 1 << 15 ) ) == 0 ) )
* V_3 = 1 ;
}
else
{
if ( ( V_1 & ( 0x17 << 21 ) ) != ( 0x07 << 21 )
&& ( V_1 & ( 0x1d << 21 ) ) != ( 0x19 << 21 ) )
* V_3 = 1 ;
}
return ( ( V_1 & 0xfffc ) ^ 0x8000 ) - 0x8000 ;
}
static int
F_11 ( long T_1 , int T_2 )
{
if ( ( T_2 & V_4 ) == 0 )
{
switch ( T_1 & 0x14 )
{
default:
case 0 :
return 1 ;
case 0x4 :
return ( T_1 & 0x2 ) == 0 ;
case 0x10 :
return ( T_1 & 0x8 ) == 0 ;
case 0x14 :
return T_1 == 0x14 ;
}
}
else
{
if ( ( T_1 & 0x14 ) == 0 )
return ( T_1 & 0x1 ) == 0 ;
else if ( ( T_1 & 0x14 ) == 0x14 )
return T_1 == 0x14 ;
else
return 1 ;
}
}
static unsigned long
F_12 ( unsigned long V_1 ,
long T_1 ,
int T_2 ,
const char * * T_3 )
{
if ( ! F_11 ( T_1 , T_2 ) )
* T_3 = _ ( L_1 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 21 ) ;
}
static long
F_13 ( unsigned long V_1 ,
int T_2 ,
int * V_3 )
{
long T_1 ;
T_1 = ( V_1 >> 21 ) & 0x1f ;
if ( ! F_11 ( T_1 , T_2 ) )
* V_3 = 1 ;
return T_1 ;
}
static unsigned long
F_14 ( unsigned long V_1 ,
long T_1 ,
int T_2 ,
const char * * T_3 )
{
if ( ! F_11 ( T_1 , T_2 ) )
* T_3 = _ ( L_1 ) ;
else if ( ( T_1 & 1 ) != 0 )
* T_3 = _ ( L_2 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 21 ) ;
}
static long
F_15 ( unsigned long V_1 ,
int T_2 ,
int * V_3 )
{
long T_1 ;
T_1 = ( V_1 >> 21 ) & 0x1f ;
if ( ! F_11 ( T_1 , T_2 ) )
* V_3 = 1 ;
return T_1 & 0x1e ;
}
static unsigned long
F_16 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 0xf ) != 0 )
* T_3 = _ ( L_3 ) ;
return V_1 | ( T_1 & 0xfff0 ) ;
}
static long
F_17 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 & 0xfff0 ) ^ 0x8000 ) - 0x8000 ;
}
static unsigned long
F_18 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 1 ) != 0 )
* T_3 = _ ( L_4 ) ;
if ( ( T_1 > 62 ) != 0 )
* T_3 = _ ( L_5 ) ;
return V_1 | ( ( T_1 & 0x3e ) << 10 ) ;
}
static long
F_19 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( V_1 >> 10 ) & 0x3e ;
}
static unsigned long
F_20 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 3 ) != 0 )
* T_3 = _ ( L_6 ) ;
if ( ( T_1 > 124 ) != 0 )
* T_3 = _ ( L_7 ) ;
return V_1 | ( ( T_1 & 0x7c ) << 9 ) ;
}
static long
F_21 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( V_1 >> 9 ) & 0x7c ;
}
static unsigned long
F_22 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 7 ) != 0 )
* T_3 = _ ( L_8 ) ;
if ( ( T_1 > 248 ) != 0 )
* T_3 = _ ( L_9 ) ;
return V_1 | ( ( T_1 & 0xf8 ) << 8 ) ;
}
static long
F_23 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( V_1 >> 8 ) & 0xf8 ;
}
static unsigned long
F_24 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 3 ) != 0 )
* T_3 = _ ( L_6 ) ;
return V_1 | ( T_1 & 0xfffc ) ;
}
static long
F_25 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 & 0xfffc ) ^ 0x8000 ) - 0x8000 ;
}
static unsigned long
F_26 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( T_1 > 2047 || T_1 < - 2048 )
* T_3 = _ ( L_10 ) ;
return V_1 | ( ( T_1 << 4 ) & 0xfff0 ) ;
}
static long
F_27 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( V_1 & 0xfff0 ) >> 4 ;
}
static unsigned long
F_28 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( T_1 > 8191 || T_1 < - 8192 )
* T_3 = _ ( L_11 ) ;
else if ( ( T_1 & 3 ) != 0 )
* T_3 = _ ( L_6 ) ;
return V_1 | ( ( T_1 << 2 ) & 0xfff0 ) ;
}
static long
F_29 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( ( V_1 >> 2 ) & 0x3ffc ) ^ 0x2000 ) - 0x2000 ;
}
static unsigned long
F_30 ( unsigned long V_1 ,
long T_1 ,
int T_2 ,
const char * * T_3 )
{
if ( ( V_1 & ( 1 << 20 ) ) != 0 )
{
if ( T_1 == 0 || ( T_1 & - T_1 ) != T_1 )
{
* T_3 = _ ( L_12 ) ;
T_1 = 0 ;
}
}
else if ( T_1 == 0 )
;
else if ( ( T_1 & - T_1 ) == T_1
&& ( ( T_2 & V_4 ) != 0
|| ( ( T_2 & V_5 ) != 0
&& ( V_1 & ( 0x3ff << 1 ) ) == 19 << 1 ) ) )
V_1 |= 1 << 20 ;
else if ( ( V_1 & ( 0x3ff << 1 ) ) == 19 << 1 )
{
* T_3 = _ ( L_13 ) ;
T_1 = 0 ;
}
return V_1 | ( ( T_1 & 0xff ) << 12 ) ;
}
static long
F_31 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 )
{
long V_6 = ( V_1 >> 12 ) & 0xff ;
if ( ( V_1 & ( 1 << 20 ) ) != 0 )
{
if ( V_6 == 0 || ( V_6 & - V_6 ) != V_6 )
* V_3 = 1 ;
}
else if ( ( V_1 & ( 0x3ff << 1 ) ) == 19 << 1 )
{
if ( V_6 != 0 )
* V_3 = 1 ;
}
return V_6 ;
}
static unsigned long
F_32 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 3 ) != 0 )
* T_3 = _ ( L_14 ) ;
return V_1 | ( T_1 & 0x3fffffc ) ;
}
static long
F_33 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 & 0x3fffffc ) ^ 0x2000000 ) - 0x2000000 ;
}
static unsigned long
F_34 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
unsigned long V_7 , V_6 ;
int V_8 , V_9 , V_10 , V_11 , V_12 ;
V_7 = T_1 ;
if ( V_7 == 0 )
{
* T_3 = _ ( L_15 ) ;
return V_1 ;
}
V_8 = 0 ;
V_9 = 32 ;
if ( ( V_7 & 1 ) != 0 )
V_12 = 1 ;
else
V_12 = 0 ;
V_11 = 0 ;
for ( V_10 = 0 , V_6 = 1L << 31 ; V_10 < 32 ; ++ V_10 , V_6 >>= 1 )
{
if ( ( V_7 & V_6 ) && ! V_12 )
{
++ V_11 ;
V_8 = V_10 ;
V_12 = 1 ;
}
else if ( ! ( V_7 & V_6 ) && V_12 )
{
++ V_11 ;
V_9 = V_10 ;
V_12 = 0 ;
}
}
if ( V_9 == 0 )
V_9 = 32 ;
if ( V_11 != 2 && ( V_11 != 0 || ! V_12 ) )
* T_3 = _ ( L_15 ) ;
return V_1 | ( V_8 << 6 ) | ( ( V_9 - 1 ) << 1 ) ;
}
static long
F_35 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 )
{
long V_13 ;
int V_8 , V_9 ;
int V_14 ;
* V_3 = 1 ;
V_8 = ( V_1 >> 6 ) & 0x1f ;
V_9 = ( V_1 >> 1 ) & 0x1f ;
if ( V_8 < V_9 + 1 )
{
V_13 = 0 ;
for ( V_14 = V_8 ; V_14 <= V_9 ; V_14 ++ )
V_13 |= 1L << ( 31 - V_14 ) ;
}
else if ( V_8 == V_9 + 1 )
V_13 = ~ 0 ;
else
{
V_13 = ~ 0 ;
for ( V_14 = V_9 + 1 ; V_14 < V_8 ; V_14 ++ )
V_13 &= ~ ( 1L << ( 31 - V_14 ) ) ;
}
return V_13 ;
}
static unsigned long
F_36 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( ( T_1 & 0x1f ) << 6 ) | ( T_1 & 0x20 ) ;
}
static long
F_37 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 >> 6 ) & 0x1f ) | ( V_1 & 0x20 ) ;
}
static unsigned long
F_38 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( T_1 < 0 || T_1 > 32 )
* T_3 = _ ( L_16 ) ;
if ( T_1 == 32 )
T_1 = 0 ;
return V_1 | ( ( T_1 & 0x1f ) << 11 ) ;
}
static long
F_39 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
long V_13 ;
V_13 = ( V_1 >> 11 ) & 0x1f ;
if ( V_13 == 0 )
V_13 = 32 ;
return V_13 ;
}
static unsigned long
F_40 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( - T_1 & 0xffff ) ;
}
static long
F_41 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 )
{
* V_3 = 1 ;
return - ( ( ( V_1 & 0xffff ) ^ 0x8000 ) - 0x8000 ) ;
}
static unsigned long
F_42 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( T_1 == 0
|| ( unsigned long ) T_1 == ( ( V_1 >> 21 ) & 0x1f ) )
* T_3 = L_17 ;
return V_1 | ( ( T_1 & 0x1f ) << 16 ) ;
}
static unsigned long
F_43 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( unsigned long ) T_1 >= ( ( V_1 >> 21 ) & 0x1f ) )
* T_3 = _ ( L_18 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 16 ) ;
}
static unsigned long
F_44 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
long V_15 = ( V_1 & V_16 ) >> 21 ;
if ( T_1 == V_15 )
* T_3 = _ ( L_19 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 16 ) ;
}
static unsigned long
F_45 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( T_1 == 0 )
* T_3 = _ ( L_17 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 16 ) ;
}
static unsigned long
F_46 ( unsigned long V_1 ,
long T_1 V_2 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( ( ( V_1 >> 21 ) & 0x1f ) << 11 ) ;
}
static long
F_47 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 )
{
if ( ( ( V_1 >> 21 ) & 0x1f ) != ( ( V_1 >> 11 ) & 0x1f ) )
* V_3 = 1 ;
return 0 ;
}
static unsigned long
F_48 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 1 ) != 0 )
* T_3 = _ ( L_20 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 21 ) ;
}
static unsigned long
F_49 ( unsigned long V_1 ,
long T_1 V_2 ,
int T_2 V_2 ,
const char * * T_3 )
{
if ( ( T_1 & 1 ) != 0 )
* T_3 = _ ( L_21 ) ;
return V_1 | ( ( T_1 & 0x1f ) << 21 ) ;
}
static unsigned long
F_50 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( ( T_1 & 0x1f ) << 11 ) | ( ( T_1 & 0x20 ) >> 4 ) ;
}
static long
F_51 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 >> 11 ) & 0x1f ) | ( ( V_1 << 4 ) & 0x20 ) ;
}
static unsigned long
F_52 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
return V_1 | ( ( T_1 & 0x1f ) << 16 ) | ( ( T_1 & 0x3e0 ) << 6 ) ;
}
static long
F_53 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
return ( ( V_1 >> 16 ) & 0x1f ) | ( ( V_1 >> 6 ) & 0x3e0 ) ;
}
static unsigned long
F_54 ( unsigned long V_1 ,
long T_1 ,
int T_2 ,
const char * * T_3 )
{
if ( T_1 > 7
|| ( T_1 > 3
&& ( T_2 & ( V_17 | V_18 ) ) == 0 ) )
* T_3 = _ ( L_22 ) ;
if ( T_1 <= 3 || ( V_1 & 0x100 ) != 0 )
T_1 |= 0x10 ;
return V_1 | ( ( T_1 & 0x17 ) << 16 ) ;
}
static long
F_55 ( unsigned long V_1 ,
int T_2 ,
int * V_3 )
{
unsigned long V_19 = ( V_1 >> 16 ) & 0x1f ;
if ( V_19 <= 3
|| ( V_19 < 0x10 && ( V_1 & 0x100 ) != 0 )
|| ( V_19 - 0x10 > 3
&& ( T_2 & ( V_17 | V_18 ) ) == 0 ) )
* V_3 = 1 ;
return V_19 & 7 ;
}
static unsigned long
F_56 ( unsigned long V_1 ,
long T_1 ,
int T_2 V_2 ,
const char * * T_3 V_2 )
{
if ( T_1 == 0 )
T_1 = V_20 ;
return V_1 | ( ( T_1 & 0x1f ) << 16 ) | ( ( T_1 & 0x3e0 ) << 6 ) ;
}
static long
F_57 ( unsigned long V_1 ,
int T_2 V_2 ,
int * V_3 V_2 )
{
long V_13 ;
V_13 = ( ( V_1 >> 16 ) & 0x1f ) | ( ( V_1 >> 6 ) & 0x3e0 ) ;
if ( V_13 == V_20 )
V_13 = 0 ;
return V_13 ;
}
