static void F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 ^ V_3 ) {
F_2 ( V_1 ) ^= V_4 ;
F_3 () ;
} else
F_4 () ;
}
static void fabs ( T_1 * V_1 , T_2 V_2 )
{
if ( V_2 ^ V_3 ) {
F_5 ( V_1 ) ;
F_3 () ;
} else
F_4 () ;
}
static void F_6 ( T_1 * V_1 , T_2 V_2 )
{
switch ( V_2 ) {
case V_5 :
F_7 ( V_6 ) ;
break;
case V_7 :
if ( F_8 ( V_1 ) == V_8 )
F_7 ( 0 ) ;
else
F_7 ( V_9 ) ;
break;
case V_10 :
switch ( F_9 ( V_1 ) ) {
case V_11 :
if ( F_8 ( V_1 ) == V_8 )
F_7 ( 0 ) ;
else
F_7 ( V_9 ) ;
if ( F_10 () < 0 ) {
#ifdef F_11
if ( F_8 ( V_1 ) == V_8 )
F_7 ( V_6 ) ;
#endif
return;
}
break;
case V_12 :
F_7 ( V_9 | V_13 | V_6 ) ;
F_12 ( V_14 ) ;
break;
case V_15 :
if ( F_8 ( V_1 ) == V_8 )
F_7 ( 0 ) ;
else
F_7 ( V_9 ) ;
break;
default:
F_7 ( V_9 | V_13 | V_6 ) ;
F_12 ( V_16 | 0x14 ) ;
break;
}
break;
case V_3 :
F_7 ( V_9 | V_13 | V_6 ) ;
F_12 ( V_17 ) ;
break;
}
}
static void F_13 ( T_1 * V_1 , T_2 V_2 )
{
int V_18 = 0 ;
switch ( V_2 ) {
case V_3 :
V_18 = V_6 | V_9 ;
break;
case V_5 :
V_18 = V_6 ;
break;
case V_7 :
V_18 = V_13 ;
break;
case V_10 :
switch ( F_9 ( V_1 ) ) {
case V_11 :
V_18 = V_13 | V_6 ;
break;
case V_12 :
if ( ( V_1 -> V_19 & 0x80000000 )
&& ( F_14 ( V_1 ) == V_20 ) )
V_18 = V_9 ;
break;
case V_15 :
V_18 = V_13 | V_9 ;
break;
}
}
if ( F_8 ( V_1 ) == V_4 )
V_18 |= V_21 ;
F_7 ( V_18 ) ;
}
void F_15 ( void )
{
( V_22 [ V_23 ] ) ( & F_16 ( 0 ) , F_17 () ) ;
}
