static inline void
F_1 ( unsigned long V_1 )
{
* ( V_2 ) V_3 = V_1 ;
F_2 () ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
F_1 ( V_6 |= 1UL << ( V_5 -> V_7 - 16 ) ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
F_1 ( V_6 &= ~ ( 1UL << ( V_5 -> V_7 - 16 ) ) ) ;
}
static void
F_5 ( struct V_4 * V_5 )
{
F_4 ( V_5 ) ;
* ( V_2 ) V_8 = 1 << ( V_5 -> V_7 - 16 ) ; F_2 () ;
* ( V_2 ) V_8 = 0 ; F_2 () ;
}
static void
F_6 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
* ( V_2 ) V_8 = 0x80000000 ; F_2 () ;
* ( V_2 ) V_8 = 0 ; F_2 () ;
}
static void
F_8 ( unsigned long V_9 )
{
unsigned long V_10 ;
unsigned int V_11 ;
V_10 = ( * ( V_2 ) V_12 ) & V_13 ;
while ( V_10 ) {
V_11 = F_9 ( ~ V_10 ) ;
V_10 &= V_10 - 1 ;
if ( V_11 == 31 ) {
F_10 ( V_9 ) ;
} else {
F_11 ( 16 + V_11 ) ;
}
}
}
static void T_1
F_12 ( void )
{
long V_11 ;
if ( V_14 )
V_15 . V_16 = V_17 ;
* ( V_2 ) V_3 = 0 ; F_2 () ;
* ( V_2 ) V_18 = 0 ; F_2 () ;
* ( V_2 ) V_19 = 0x80000000U ; F_2 () ;
* ( V_2 ) V_8 = 0 ; F_2 () ;
for ( V_11 = 16 ; V_11 < 48 ; ++ V_11 ) {
if ( V_11 >= 16 + 20 && V_11 <= 16 + 30 )
continue;
F_13 ( V_11 , & V_20 , V_21 ) ;
F_14 ( V_11 , V_22 ) ;
}
V_23 . V_24 = F_6 ;
F_15 () ;
F_16 () ;
F_17 ( 16 + 31 , & V_25 ) ;
}
static int
F_18 ( const struct V_26 * V_27 , T_2 V_28 , T_2 V_29 )
{
static char V_30 [ 7 ] [ 5 ] = {
{ 16 + 13 , 16 + 13 , 16 + 13 , 16 + 13 , 16 + 13 } ,
{ 16 + 8 , 16 + 8 , 16 + 9 , 16 + 10 , 16 + 11 } ,
{ 16 + 16 , 16 + 16 , 16 + 17 , 16 + 18 , 16 + 19 } ,
{ 16 + 12 , 16 + 12 , 16 + 13 , 16 + 14 , 16 + 15 } ,
{ - 1 , - 1 , - 1 , - 1 , - 1 } ,
{ 16 + 0 , 16 + 0 , 16 + 1 , 16 + 2 , 16 + 3 } ,
{ 16 + 4 , 16 + 4 , 16 + 5 , 16 + 6 , 16 + 7 } ,
} ;
const long V_31 = 6 , V_32 = 12 , V_33 = 5 ;
return V_34 ;
}
static void
F_19 ( int V_35 )
{
F_20 ( V_35 ) ;
#ifndef F_21
switch( V_35 ) {
case V_36 :
if ( V_14 ) {
* ( V_2 ) V_37 = 0x0000dead ;
F_2 () ;
}
break;
case V_38 :
break;
case V_39 :
break;
}
F_22 () ;
#endif
}
static void T_1
F_23 ( void )
{
struct V_26 * V_27 ;
F_24 () ;
V_27 = F_25 ( V_40 ,
V_41 ,
NULL ) ;
if ( V_27 && V_27 -> V_42 == F_26 ( 6 , 0 ) ) {
V_15 . V_43 . V_44 . V_45 = V_46 ;
F_27 ( V_47 L_1 ,
V_48 ) ;
}
F_28 ( V_27 ) ;
}
