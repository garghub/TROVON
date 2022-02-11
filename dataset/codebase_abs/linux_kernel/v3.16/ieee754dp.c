int F_1 ( union V_1 V_2 )
{
V_3 ;
V_4 ;
return V_5 ;
}
int F_2 ( union V_1 V_2 )
{
return F_1 ( V_2 ) >= V_6 ;
}
static inline int F_3 ( union V_1 V_2 )
{
assert ( F_2 ( V_2 ) ) ;
return ( ( F_4 ( V_2 ) & F_5 ( V_7 - 1 ) ) == F_5 ( V_7 - 1 ) ) ;
}
union V_1 T_1 F_6 ( union V_1 V_8 )
{
assert ( F_2 ( V_8 ) ) ;
if ( ! F_3 ( V_8 ) )
return V_8 ;
if ( ! F_7 ( V_9 ) ) {
F_4 ( V_8 ) &= ( ~ F_5 ( V_7 - 1 ) ) ;
if ( F_2 ( V_8 ) )
return V_8 ;
else
return F_8 () ;
}
return V_8 ;
}
static T_2 F_9 ( int V_10 , T_2 V_11 )
{
if ( V_11 & ( F_5 ( 3 ) - 1 ) ) {
switch ( V_12 . V_13 ) {
case V_14 :
break;
case V_15 :
V_11 += 0x3 + ( ( V_11 >> 3 ) & 1 ) ;
break;
case V_16 :
if ( ! V_10 )
V_11 += 0x8 ;
break;
case V_17 :
if ( V_10 )
V_11 += 0x8 ;
break;
}
}
return V_11 ;
}
union V_1 F_10 ( int V_10 , int V_18 , T_2 V_11 )
{
assert ( V_11 ) ;
assert ( ( V_11 >> ( V_7 + 1 + 3 ) ) == 0 ) ;
assert ( V_11 & ( V_19 << 3 ) ) ;
if ( V_18 < V_20 ) {
int V_21 = V_20 - V_18 ;
if ( V_12 . V_22 ) {
F_11 ( V_23 ) ;
F_11 ( V_24 ) ;
switch( V_12 . V_13 ) {
case V_15 :
case V_14 :
return F_12 ( V_10 ) ;
case V_16 :
if ( V_10 == 0 )
return F_13 ( 0 ) ;
else
return F_12 ( 1 ) ;
case V_17 :
if ( V_10 == 0 )
return F_12 ( 0 ) ;
else
return F_13 ( 1 ) ;
}
}
if ( V_18 == V_20 - 1 &&
F_9 ( V_10 , V_11 ) >> ( V_7 + 1 + 3 ) )
{
F_11 ( V_24 ) ;
V_11 = F_9 ( V_10 , V_11 ) ;
V_11 >>= 1 ;
V_11 &= ~ ( F_5 ( 3 ) - 1 ) ;
V_18 ++ ;
}
else {
V_11 = F_14 ( V_11 , V_21 ) ;
V_18 += V_21 ;
assert ( ( V_11 & ( V_19 << 3 ) ) == 0 ) ;
assert ( V_18 == V_20 ) ;
}
}
if ( V_11 & ( F_5 ( 3 ) - 1 ) ) {
F_11 ( V_24 ) ;
if ( ( V_11 & ( V_19 << 3 ) ) == 0 ) {
F_11 ( V_23 ) ;
}
V_11 = F_9 ( V_10 , V_11 ) ;
if ( V_11 >> ( V_7 + 3 + 1 ) ) {
V_11 >>= 1 ;
V_18 ++ ;
}
}
V_11 >>= 3 ;
assert ( ( V_11 >> ( V_7 + 1 ) ) == 0 ) ;
assert ( V_18 >= V_20 ) ;
if ( V_18 > V_25 ) {
F_11 ( V_26 ) ;
F_11 ( V_24 ) ;
switch ( V_12 . V_13 ) {
case V_15 :
return F_15 ( V_10 ) ;
case V_14 :
return F_16 ( V_10 ) ;
case V_16 :
if ( V_10 == 0 )
return F_15 ( 0 ) ;
else
return F_16 ( 1 ) ;
case V_17 :
if ( V_10 == 0 )
return F_16 ( 0 ) ;
else
return F_15 ( 1 ) ;
}
}
if ( ( V_11 & V_19 ) == 0 ) {
assert ( V_18 == V_20 ) ;
if ( V_12 . V_27 & V_23 )
F_11 ( V_23 ) ;
return F_17 ( V_10 , V_20 - 1 + V_28 , V_11 ) ;
} else {
assert ( ( V_11 >> ( V_7 + 1 ) ) == 0 ) ;
assert ( V_11 & V_19 ) ;
return F_17 ( V_10 , V_18 + V_28 , V_11 & ~ V_19 ) ;
}
}
