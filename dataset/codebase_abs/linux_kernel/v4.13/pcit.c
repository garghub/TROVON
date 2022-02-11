static void T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ )
F_3 ( & V_3 , V_2 + V_1 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
T_2 V_6 = 1 << ( V_5 -> V_7 - V_8 + 24 ) ;
* ( volatile T_2 * ) V_9 |= V_6 ;
}
void F_5 ( struct V_4 * V_5 )
{
T_2 V_6 = 1 << ( V_5 -> V_7 - V_8 + 24 ) ;
* ( volatile T_2 * ) V_9 &= ~ V_6 ;
}
static void F_6 ( void )
{
T_2 V_10 = * ( volatile T_2 * ) V_9 ;
int V_7 ;
F_7 ( V_11 ) ;
V_7 = F_8 ( ( V_10 >> 16 ) & 0x7f ) ;
if ( F_9 ( V_7 > 0 ) )
F_10 ( V_7 + V_8 - 1 ) ;
F_11 ( V_11 ) ;
}
static void F_12 ( void )
{
T_2 V_10 = * ( volatile T_2 * ) V_9 ;
int V_7 ;
F_7 ( V_12 ) ;
V_7 = F_8 ( ( V_10 >> 16 ) & 0x3f ) ;
if ( F_9 ( V_7 > 0 ) )
F_10 ( V_7 + V_8 - 1 ) ;
F_11 ( V_12 ) ;
}
static void F_13 ( void )
{
T_2 V_10 = F_14 () & F_15 () ;
if ( V_10 & V_13 )
F_6 () ;
else if ( V_10 & V_14 )
F_10 ( V_15 + 4 ) ;
else if ( V_10 & V_16 )
F_10 ( V_15 + 5 ) ;
else if ( V_10 & V_17 )
F_10 ( V_15 + 7 ) ;
}
static void F_16 ( void )
{
T_2 V_10 = F_14 () & F_15 () ;
if ( V_10 & V_18 )
F_12 () ;
else if ( V_10 & V_13 )
F_10 ( V_15 + 3 ) ;
else if ( V_10 & V_14 )
F_10 ( V_15 + 4 ) ;
else if ( V_10 & V_16 )
F_10 ( V_15 + 5 ) ;
else if ( V_10 & V_17 )
F_10 ( V_15 + 7 ) ;
}
void T_1 F_17 ( void )
{
int V_1 ;
F_18 () ;
for ( V_1 = V_8 ; V_1 <= V_19 ; V_1 ++ )
F_19 ( V_1 , & V_20 , V_21 ) ;
* ( volatile T_2 * ) V_9 = 0 ;
V_22 = F_13 ;
F_20 ( V_23 , V_11 ) ;
F_21 ( V_8 + 6 , & V_24 ) ;
}
void T_1 F_22 ( void )
{
int V_1 ;
F_18 () ;
for ( V_1 = V_8 ; V_1 <= V_19 ; V_1 ++ )
F_19 ( V_1 , & V_20 , V_21 ) ;
* ( volatile T_2 * ) V_9 = 0x40000000 ;
V_22 = F_16 ;
F_20 ( V_23 , V_12 ) ;
F_21 ( V_15 + 3 , & V_24 ) ;
}
void T_1 F_23 ( void )
{
V_25 . V_26 = V_3 . V_26 ;
#ifdef F_24
V_27 = 0x9000 ;
F_25 ( & V_28 ) ;
#endif
F_1 () ;
}
static int T_1 F_26 ( void )
{
switch ( V_29 ) {
case V_30 :
F_27 ( & V_31 ) ;
F_27 ( & V_32 ) ;
F_27 ( & V_33 ) ;
break;
case V_34 :
F_27 ( & V_35 ) ;
F_27 ( & V_32 ) ;
F_27 ( & V_33 ) ;
break;
}
return 0 ;
}
