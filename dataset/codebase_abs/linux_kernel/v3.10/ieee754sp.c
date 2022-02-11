int F_1 ( T_1 V_1 )
{
V_2 ;
V_3 ;
return V_4 ;
}
int F_2 ( T_1 V_1 )
{
return F_1 ( V_1 ) >= V_5 ;
}
int F_3 ( T_1 V_1 )
{
assert ( F_2 ( V_1 ) ) ;
return ( F_4 ( V_1 ) & F_5 ( V_6 - 1 ) ) ;
}
T_1 F_6 ( T_1 V_7 , const char * V_8 , ... )
{
struct V_9 V_10 ;
if ( ! F_7 () )
return V_7 ;
V_10 . V_8 = V_8 ;
V_10 . V_11 = V_12 ;
V_10 . V_13 . V_14 = V_7 ;
va_start ( V_10 . V_15 , V_8 ) ;
F_8 ( & V_10 ) ;
va_end ( V_10 . V_15 ) ;
return V_10 . V_13 . V_14 ;
}
T_1 F_9 ( T_1 V_7 , const char * V_8 , ... )
{
struct V_9 V_10 ;
assert ( F_2 ( V_7 ) ) ;
if ( ! F_3 ( V_7 ) )
return V_7 ;
if ( ! F_10 ( V_16 ) ) {
F_4 ( V_7 ) &= ( ~ F_5 ( V_6 - 1 ) ) ;
if ( F_2 ( V_7 ) )
return V_7 ;
else
return F_11 () ;
}
V_10 . V_8 = V_8 ;
V_10 . V_11 = 0 ;
V_10 . V_13 . V_14 = V_7 ;
va_start ( V_10 . V_15 , V_8 ) ;
F_8 ( & V_10 ) ;
va_end ( V_10 . V_15 ) ;
return V_10 . V_13 . V_14 ;
}
T_1 F_12 ( T_1 V_1 , T_1 V_17 )
{
assert ( F_2 ( V_1 ) ) ;
assert ( F_2 ( V_17 ) ) ;
if ( F_4 ( V_1 ) > F_4 ( V_17 ) )
return V_1 ;
else
return V_17 ;
}
static unsigned F_13 ( int V_18 , unsigned V_19 )
{
if ( V_19 & ( F_5 ( 3 ) - 1 ) ) {
switch ( V_20 . V_21 ) {
case V_22 :
break;
case V_23 :
V_19 += 0x3 + ( ( V_19 >> 3 ) & 1 ) ;
break;
case V_24 :
if ( ! V_18 )
V_19 += 0x8 ;
break;
case V_25 :
if ( V_18 )
V_19 += 0x8 ;
break;
}
}
return V_19 ;
}
T_1 F_14 ( int V_18 , int V_26 , unsigned V_19 )
{
assert ( V_19 ) ;
assert ( ( V_19 >> ( V_6 + 1 + 3 ) ) == 0 ) ;
assert ( V_19 & ( V_27 << 3 ) ) ;
if ( V_26 < V_28 ) {
int V_29 = V_28 - V_26 ;
if ( V_20 . V_30 ) {
F_15 ( V_31 ) ;
F_15 ( V_32 ) ;
switch( V_20 . V_21 ) {
case V_23 :
case V_22 :
return F_16 ( V_18 ) ;
case V_24 :
if( V_18 == 0 )
return F_17 ( 0 ) ;
else
return F_16 ( 1 ) ;
case V_25 :
if( V_18 == 0 )
return F_16 ( 0 ) ;
else
return F_17 ( 1 ) ;
}
}
if ( V_26 == V_28 - 1
&& F_13 ( V_18 , V_19 ) >> ( V_6 + 1 + 3 ) )
{
F_15 ( V_32 ) ;
V_19 = F_13 ( V_18 , V_19 ) ;
V_19 >>= 1 ;
V_19 &= ~ ( F_5 ( 3 ) - 1 ) ;
V_26 ++ ;
}
else {
F_18 ( V_29 ) ;
assert ( ( V_19 & ( V_27 << 3 ) ) == 0 ) ;
assert ( V_26 == V_28 ) ;
}
}
if ( V_19 & ( F_5 ( 3 ) - 1 ) ) {
F_15 ( V_32 ) ;
if ( ( V_19 & ( V_27 << 3 ) ) == 0 ) {
F_15 ( V_31 ) ;
}
V_19 = F_13 ( V_18 , V_19 ) ;
if ( V_19 >> ( V_6 + 1 + 3 ) ) {
V_19 >>= 1 ;
V_26 ++ ;
}
}
V_19 >>= 3 ;
assert ( ( V_19 >> ( V_6 + 1 ) ) == 0 ) ;
assert ( V_26 >= V_28 ) ;
if ( V_26 > V_33 ) {
F_15 ( V_34 ) ;
F_15 ( V_32 ) ;
switch ( V_20 . V_21 ) {
case V_23 :
return F_19 ( V_18 ) ;
case V_22 :
return F_20 ( V_18 ) ;
case V_24 :
if ( V_18 == 0 )
return F_19 ( 0 ) ;
else
return F_20 ( 1 ) ;
case V_25 :
if ( V_18 == 0 )
return F_20 ( 0 ) ;
else
return F_19 ( 1 ) ;
}
}
if ( ( V_19 & V_27 ) == 0 ) {
assert ( V_26 == V_28 ) ;
if ( V_20 . V_35 & V_31 )
F_15 ( V_31 ) ;
return F_21 ( V_18 , V_28 - 1 + V_36 , V_19 ) ;
} else {
assert ( ( V_19 >> ( V_6 + 1 ) ) == 0 ) ;
assert ( V_19 & V_27 ) ;
return F_21 ( V_18 , V_26 + V_36 , V_19 & ~ V_27 ) ;
}
}
