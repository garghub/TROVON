static int F_1 ( T_1 const * V_1 , int V_2 )
{
int V_3 , V_4 , V_5 ;
T_2 V_6 ;
T_1 * V_7 ;
T_1 V_8 , V_9 ;
T_2 V_10 , V_11 = F_2 ( V_1 ) ;
V_7 = & F_3 ( 0 ) ;
V_6 = F_4 () ;
V_10 = F_2 ( V_7 ) ;
if ( V_2 == V_12 )
V_2 = F_5 ( V_1 ) ;
if ( V_6 == V_12 )
V_6 = F_5 ( V_7 ) ;
if ( ( ( V_6 != V_13 ) && ( V_6 != V_14 ) )
|| ( ( V_2 != V_13 ) && ( V_2 != V_14 ) ) ) {
if ( V_6 == V_15 ) {
if ( V_2 == V_15 )
return V_16 ;
if ( V_2 == V_13 )
return ( ( V_11 ==
V_17 ) ? V_18 : V_19 ) ;
if ( V_2 == V_14 )
return ( ( V_11 ==
V_17 ) ? V_18 : V_19 )
| V_20 ;
} else if ( V_2 == V_15 ) {
if ( V_6 == V_13 )
return ( ( V_10 ==
V_17 ) ? V_19 : V_18 ) ;
if ( V_6 == V_14 )
return ( ( V_10 ==
V_17 ) ? V_19 : V_18 )
| V_20 ;
}
if ( V_6 == V_21 ) {
if ( ( V_2 == V_13 ) || ( V_2 == V_15 ) )
return ( ( V_10 ==
V_17 ) ? V_19 : V_18 ) ;
else if ( V_2 == V_14 )
return ( ( V_10 ==
V_17 ) ? V_19 : V_18 )
| V_20 ;
else if ( V_2 == V_21 ) {
return ( V_10 == V_11 ) ? V_16 :
( ( V_10 ==
V_17 ) ? V_19 : V_18 ) ;
}
} else if ( V_2 == V_21 ) {
if ( ( V_6 == V_13 ) || ( V_6 == V_15 ) )
return ( ( V_11 ==
V_17 ) ? V_18 : V_19 ) ;
if ( V_6 == V_14 )
return ( ( V_11 ==
V_17 ) ? V_18 : V_19 )
| V_20 ;
}
if ( ( V_6 == V_22 ) || ( V_2 == V_22 ) ) {
int V_23 = 0 , V_24 = 0 ;
if ( V_6 == V_22 ) {
V_23 =
( V_7 -> V_25 & 0xc0000000 ) == 0x80000000 ;
V_24 = ! ( ( F_6 ( V_7 ) == V_26 )
&& ( V_7 ->
V_25 & 0x80000000 ) ) ;
}
if ( V_2 == V_22 ) {
V_23 |=
( V_1 -> V_25 & 0xc0000000 ) == 0x80000000 ;
V_24 |= ! ( ( F_6 ( V_1 ) == V_26 )
&& ( V_1 -> V_25 & 0x80000000 ) ) ;
}
if ( V_23 || V_24 )
return V_27 | V_28 | V_29 ;
else
return V_27 | V_29 ;
}
F_7 ( V_30 ) ;
}
if ( V_10 != V_11 ) {
return ( ( V_10 == V_17 ) ? V_19 : V_18 )
| ( ( ( V_6 == V_14 ) || ( V_2 == V_14 ) ) ?
V_20 : 0 ) ;
}
if ( ( V_6 == V_14 ) || ( V_2 == V_14 ) ) {
F_8 ( V_7 , & V_8 ) ;
F_8 ( V_1 , & V_9 ) ;
V_7 = & V_8 ;
V_1 = & V_9 ;
V_4 = F_9 ( V_7 ) ;
V_5 = F_9 ( V_1 ) ;
} else {
V_4 = F_6 ( V_7 ) ;
V_5 = F_6 ( V_1 ) ;
}
#ifdef F_10
if ( ! ( V_7 -> V_25 & 0x80000000 ) )
F_7 ( V_30 ) ;
if ( ! ( V_1 -> V_25 & 0x80000000 ) )
F_7 ( V_30 ) ;
#endif
V_3 = V_4 - V_5 ;
if ( V_3 == 0 ) {
V_3 = V_7 -> V_25 - V_1 -> V_25 ;
if ( V_3 == 0 ) {
V_3 = V_7 -> V_31 > V_1 -> V_31 ;
if ( V_3 == 0 )
V_3 = - ( V_7 -> V_31 < V_1 -> V_31 ) ;
}
}
if ( V_3 > 0 ) {
return ( ( V_10 == V_17 ) ? V_19 : V_18 )
| ( ( ( V_6 == V_14 ) || ( V_2 == V_14 ) ) ?
V_20 : 0 ) ;
}
if ( V_3 < 0 ) {
return ( ( V_10 == V_17 ) ? V_18 : V_19 )
| ( ( ( V_6 == V_14 ) || ( V_2 == V_14 ) ) ?
V_20 : 0 ) ;
}
return V_16
| ( ( ( V_6 == V_14 ) || ( V_2 == V_14 ) ) ?
V_20 : 0 ) ;
}
int F_11 ( T_1 const * V_32 , T_2 V_33 )
{
int V_34 = 0 , V_35 ;
V_35 = F_1 ( V_32 , V_33 ) ;
if ( V_35 & V_29 ) {
F_7 ( V_30 ) ;
V_34 = V_36 | V_37 | V_38 ;
} else
switch ( V_35 & 7 ) {
case V_18 :
V_34 = V_38 ;
break;
case V_16 :
V_34 = V_36 ;
break;
case V_19 :
V_34 = 0 ;
break;
case V_27 :
V_34 = V_36 | V_37 | V_38 ;
break;
#ifdef F_10
default:
F_7 ( V_39 | 0x121 ) ;
V_34 = V_36 | V_37 | V_38 ;
break;
#endif
}
F_12 ( V_34 ) ;
if ( V_35 & V_20 ) {
return F_13 () < 0 ;
}
return 0 ;
}
static int F_14 ( int V_40 )
{
int V_34 = 0 , V_35 ;
T_1 * V_41 ;
if ( ! F_15 ( 0 ) || ! F_15 ( V_40 ) ) {
F_12 ( V_36 | V_37 | V_38 ) ;
F_7 ( V_42 ) ;
return ! ( V_43 & V_44 ) ;
}
V_41 = & F_3 ( V_40 ) ;
V_35 = F_1 ( V_41 , F_16 ( V_40 ) ) ;
if ( V_35 & V_29 ) {
F_12 ( V_36 | V_37 | V_38 ) ;
F_7 ( V_30 ) ;
return ! ( V_43 & V_44 ) ;
} else
switch ( V_35 & 7 ) {
case V_18 :
V_34 = V_38 ;
break;
case V_16 :
V_34 = V_36 ;
break;
case V_19 :
V_34 = 0 ;
break;
case V_27 :
V_34 = V_36 | V_37 | V_38 ;
break;
#ifdef F_10
default:
F_7 ( V_39 | 0x122 ) ;
V_34 = V_36 | V_37 | V_38 ;
break;
#endif
}
F_12 ( V_34 ) ;
if ( V_35 & V_20 ) {
return F_13 () < 0 ;
}
return 0 ;
}
static int F_17 ( int V_40 )
{
int V_34 = 0 , V_35 ;
T_1 * V_41 ;
if ( ! F_15 ( 0 ) || ! F_15 ( V_40 ) ) {
F_12 ( V_36 | V_37 | V_38 ) ;
F_7 ( V_42 ) ;
return ! ( V_43 & V_44 ) ;
}
V_41 = & F_3 ( V_40 ) ;
V_35 = F_1 ( V_41 , F_16 ( V_40 ) ) ;
if ( V_35 & V_29 ) {
F_12 ( V_36 | V_37 | V_38 ) ;
if ( V_35 & V_28 ) {
F_7 ( V_30 ) ;
return ! ( V_43 & V_44 ) ;
}
return 0 ;
} else
switch ( V_35 & 7 ) {
case V_18 :
V_34 = V_38 ;
break;
case V_16 :
V_34 = V_36 ;
break;
case V_19 :
V_34 = 0 ;
break;
case V_27 :
V_34 = V_36 | V_37 | V_38 ;
break;
#ifdef F_10
default:
F_7 ( V_39 | 0x123 ) ;
V_34 = V_36 | V_37 | V_38 ;
break;
#endif
}
F_12 ( V_34 ) ;
if ( V_35 & V_20 ) {
return F_13 () < 0 ;
}
return 0 ;
}
void F_18 ( void )
{
F_14 ( V_45 ) ;
}
void F_19 ( void )
{
if ( ! F_14 ( V_45 ) )
F_20 () ;
}
void F_21 ( void )
{
if ( V_45 != 1 ) {
F_22 () ;
return;
}
if ( ! F_14 ( 1 ) )
F_23 () ;
}
void F_24 ( void )
{
F_17 ( V_45 ) ;
}
void F_25 ( void )
{
if ( ! F_17 ( V_45 ) )
F_20 () ;
}
void F_26 ( void )
{
if ( V_45 == 1 ) {
if ( ! F_17 ( 1 ) )
F_23 () ;
} else
F_22 () ;
}
