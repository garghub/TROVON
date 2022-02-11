unsigned int F_1 ( const unsigned int V_1 )
{
if ( V_1 & 0x800000 ) {
return F_2 ( V_1 ) ;
}
switch ( ( V_1 & 0x700000 ) >> 20 ) {
case V_2 >> 20 :
return F_3 ( V_1 ) ;
break;
case V_3 >> 20 :
return F_4 ( V_1 ) ;
break;
case V_4 >> 20 :
F_5 ( F_6 ( F_7 ( V_1 ) ) ) ;
break;
case V_5 >> 20 :
F_8 ( F_7 ( V_1 ) , F_9 () ) ;
break;
default:
return 0 ;
}
return 1 ;
}
unsigned int F_3 ( const unsigned int V_1 )
{
T_1 * V_6 = F_10 () ;
struct V_7 V_8 ;
V_8 . V_9 = F_11 ( V_1 ) ;
V_8 . V_10 = F_12 ( V_1 ) ;
V_8 . V_11 = 0 ;
switch ( V_1 & V_12 ) {
case V_13 :
{
V_6 -> V_14 [ F_13 ( V_1 ) ] = V_15 ;
V_6 -> V_16 [ F_13 ( V_1 ) ] . V_17 = F_14 ( & V_8 , F_6 ( F_7 ( V_1 ) ) ) ;
}
break;
case V_18 :
{
V_6 -> V_14 [ F_13 ( V_1 ) ] = V_19 ;
V_6 -> V_16 [ F_13 ( V_1 ) ] . V_20 = F_15 ( F_6 ( F_7 ( V_1 ) ) ) ;
}
break;
#ifdef F_16
case V_21 :
{
V_6 -> V_14 [ F_13 ( V_1 ) ] = V_22 ;
V_6 -> V_16 [ F_13 ( V_1 ) ] . V_23 = F_17 ( F_6 ( F_7 ( V_1 ) ) ) ;
}
break;
#endif
default:
return 0 ;
}
if ( V_8 . V_11 )
F_18 ( V_8 . V_11 ) ;
return 1 ;
}
unsigned int F_4 ( const unsigned int V_1 )
{
T_1 * V_6 = F_10 () ;
unsigned int V_24 = F_19 ( V_1 ) ;
struct V_7 V_8 ;
V_8 . V_9 = F_11 ( V_1 ) ;
V_8 . V_10 = F_12 ( V_1 ) ;
V_8 . V_11 = 0 ;
switch ( V_6 -> V_14 [ V_24 ] ) {
case V_15 :
{
F_8 ( F_7 ( V_1 ) , F_20 ( & V_8 , V_6 -> V_16 [ V_24 ] . V_17 ) ) ;
}
break;
case V_19 :
{
F_8 ( F_7 ( V_1 ) , F_21 ( & V_8 , V_6 -> V_16 [ V_24 ] . V_20 ) ) ;
}
break;
#ifdef F_16
case V_22 :
{
F_8 ( F_7 ( V_1 ) , F_22 ( & V_8 , V_6 -> V_16 [ V_24 ] . V_23 ) ) ;
}
break;
#endif
default:
return 0 ;
}
if ( V_8 . V_11 )
F_18 ( V_8 . V_11 ) ;
return 1 ;
}
static unsigned int F_2 ( const unsigned int V_1 )
{
T_1 * V_6 = F_10 () ;
unsigned int V_24 = F_13 ( V_1 ) , V_25 = F_19 ( V_1 ) ;
int V_26 = V_1 & 0x400000 ;
int V_27 = V_1 & 0x200000 ;
unsigned int V_28 = 0 ;
#ifdef F_16
T_2 V_29 , V_30 ;
switch ( V_6 -> V_14 [ V_24 ] ) {
case V_15 :
if ( F_23 ( V_6 -> V_16 [ V_24 ] . V_17 ) )
goto V_31;
V_29 = F_24 ( V_6 -> V_16 [ V_24 ] . V_17 ) ;
break;
case V_19 :
if ( F_25 ( V_6 -> V_16 [ V_24 ] . V_20 ) )
goto V_31;
V_29 = F_26 ( V_6 -> V_16 [ V_24 ] . V_20 ) ;
break;
case V_22 :
if ( F_27 ( V_6 -> V_16 [ V_24 ] . V_23 ) )
goto V_31;
V_29 = V_6 -> V_16 [ V_24 ] . V_23 ;
break;
default:
return 0 ;
}
if ( F_28 ( V_1 ) ) {
V_30 = F_29 ( V_25 ) ;
if ( F_27 ( V_30 ) )
goto V_31;
} else {
switch ( V_6 -> V_14 [ V_25 ] ) {
case V_15 :
if ( F_23 ( V_6 -> V_16 [ V_25 ] . V_17 ) )
goto V_31;
V_30 = F_24 ( V_6 -> V_16 [ V_25 ] . V_17 ) ;
break;
case V_19 :
if ( F_25 ( V_6 -> V_16 [ V_25 ] . V_20 ) )
goto V_31;
V_30 = F_26 ( V_6 -> V_16 [ V_25 ] . V_20 ) ;
break;
case V_22 :
if ( F_27 ( V_6 -> V_16 [ V_25 ] . V_23 ) )
goto V_31;
V_30 = V_6 -> V_16 [ V_25 ] . V_23 ;
break;
default:
return 0 ;
}
}
if ( V_27 )
V_30 . V_32 ^= 0x8000 ;
if ( F_30 ( V_29 , V_30 ) )
V_28 |= V_33 ;
if ( F_31 ( V_29 , V_30 ) )
V_28 |= V_34 ;
if ( F_30 ( V_30 , V_29 ) )
V_28 |= V_35 ;
#else
if ( F_28 ( V_1 ) ) {
if ( V_6 -> V_14 [ V_24 ] == V_15 ) {
T_3 V_30 = F_32 ( V_25 ) ;
T_3 V_29 = V_6 -> V_16 [ V_24 ] . V_17 ;
if ( F_23 ( V_29 ) )
goto V_31;
if ( V_27 )
V_30 ^= 0x80000000 ;
if ( F_33 ( V_29 , V_30 ) )
V_28 |= V_33 ;
if ( F_34 ( V_29 , V_30 ) )
V_28 |= V_34 ;
if ( F_33 ( V_30 , V_29 ) )
V_28 |= V_35 ;
} else {
T_4 V_30 = F_35 ( V_25 ) ;
T_4 V_29 = V_6 -> V_16 [ V_24 ] . V_20 ;
if ( F_25 ( V_29 ) )
goto V_31;
if ( V_27 )
V_30 ^= 0x8000000000000000ULL ;
if ( F_36 ( V_29 , V_30 ) )
V_28 |= V_33 ;
if ( F_37 ( V_29 , V_30 ) )
V_28 |= V_34 ;
if ( F_36 ( V_30 , V_29 ) )
V_28 |= V_35 ;
}
} else {
if ( V_6 -> V_14 [ V_24 ] == V_15
&& V_6 -> V_14 [ V_25 ] == V_15 ) {
T_3 V_30 = V_6 -> V_16 [ V_25 ] . V_17 ;
T_3 V_29 = V_6 -> V_16 [ V_24 ] . V_17 ;
if ( F_23 ( V_29 )
|| F_23 ( V_30 ) )
goto V_31;
if ( V_27 )
V_30 ^= 0x80000000 ;
if ( F_33 ( V_29 , V_30 ) )
V_28 |= V_33 ;
if ( F_34 ( V_29 , V_30 ) )
V_28 |= V_34 ;
if ( F_33 ( V_30 , V_29 ) )
V_28 |= V_35 ;
} else {
T_4 V_30 , V_29 ;
V_30 = ( V_6 -> V_14 [ V_25 ] == V_15 ) ?
F_38 ( V_6 -> V_16 [ V_25 ] . V_17 )
: V_6 -> V_16 [ V_25 ] . V_20 ;
V_29 = ( V_6 -> V_14 [ V_24 ] == V_15 ) ?
F_38 ( V_6 -> V_16 [ V_24 ] . V_17 )
: V_6 -> V_16 [ V_24 ] . V_20 ;
if ( F_25 ( V_29 )
|| F_25 ( V_30 ) )
goto V_31;
if ( V_27 )
V_30 ^= 0x8000000000000000ULL ;
if ( F_36 ( V_29 , V_30 ) )
V_28 |= V_33 ;
if ( F_37 ( V_29 , V_30 ) )
V_28 |= V_34 ;
if ( F_36 ( V_30 , V_29 ) )
V_28 |= V_35 ;
}
}
#endif
F_39 ( V_28 ) ;
return 1 ;
V_31:
V_28 |= V_36 ;
V_28 &= ~ ( V_34 | V_33 ) ;
if ( V_37 & F_9 () )
V_28 |= V_35 ;
if ( V_26 )
F_18 ( V_38 ) ;
F_39 ( V_28 ) ;
return 1 ;
}
