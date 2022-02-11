int F_1 ( union V_1 V_2 )
{
V_3 ;
V_4 ;
return V_5 ;
}
static inline int F_2 ( union V_1 V_2 )
{
return F_3 ( F_1 ( V_2 ) ) ;
}
static inline int F_4 ( union V_1 V_2 )
{
int V_6 ;
assert ( F_2 ( V_2 ) ) ;
V_6 = ( F_5 ( V_2 ) & F_6 ( V_7 - 1 ) ) == F_6 ( V_7 - 1 ) ;
return V_8 . V_9 ^ V_6 ;
}
union V_1 T_1 F_7 ( union V_1 V_10 )
{
assert ( F_4 ( V_10 ) ) ;
F_8 ( V_11 ) ;
if ( V_8 . V_9 )
F_5 ( V_10 ) |= F_6 ( V_7 - 1 ) ;
else
V_10 = F_9 () ;
return V_10 ;
}
static T_2 F_10 ( int V_12 , T_2 V_13 )
{
if ( V_13 & ( F_6 ( 3 ) - 1 ) ) {
switch ( V_8 . V_14 ) {
case V_15 :
break;
case V_16 :
V_13 += 0x3 + ( ( V_13 >> 3 ) & 1 ) ;
break;
case V_17 :
if ( ! V_12 )
V_13 += 0x8 ;
break;
case V_18 :
if ( V_12 )
V_13 += 0x8 ;
break;
}
}
return V_13 ;
}
union V_1 F_11 ( int V_12 , int V_19 , T_2 V_13 )
{
assert ( V_13 ) ;
assert ( ( V_13 >> ( V_7 + 1 + 3 ) ) == 0 ) ;
assert ( V_13 & ( V_20 << 3 ) ) ;
if ( V_19 < V_21 ) {
int V_22 = V_21 - V_19 ;
if ( V_8 . V_23 ) {
F_8 ( V_24 ) ;
F_8 ( V_25 ) ;
switch( V_8 . V_14 ) {
case V_16 :
case V_15 :
return F_12 ( V_12 ) ;
case V_17 :
if ( V_12 == 0 )
return F_13 ( 0 ) ;
else
return F_12 ( 1 ) ;
case V_18 :
if ( V_12 == 0 )
return F_12 ( 0 ) ;
else
return F_13 ( 1 ) ;
}
}
if ( V_19 == V_21 - 1 &&
F_10 ( V_12 , V_13 ) >> ( V_7 + 1 + 3 ) )
{
F_8 ( V_25 ) ;
V_13 = F_10 ( V_12 , V_13 ) ;
V_13 >>= 1 ;
V_13 &= ~ ( F_6 ( 3 ) - 1 ) ;
V_19 ++ ;
}
else {
V_13 = F_14 ( V_13 , V_22 ) ;
V_19 += V_22 ;
assert ( ( V_13 & ( V_20 << 3 ) ) == 0 ) ;
assert ( V_19 == V_21 ) ;
}
}
if ( V_13 & ( F_6 ( 3 ) - 1 ) ) {
F_8 ( V_25 ) ;
if ( ( V_13 & ( V_20 << 3 ) ) == 0 ) {
F_8 ( V_24 ) ;
}
V_13 = F_10 ( V_12 , V_13 ) ;
if ( V_13 >> ( V_7 + 3 + 1 ) ) {
V_13 >>= 1 ;
V_19 ++ ;
}
}
V_13 >>= 3 ;
assert ( ( V_13 >> ( V_7 + 1 ) ) == 0 ) ;
assert ( V_19 >= V_21 ) ;
if ( V_19 > V_26 ) {
F_8 ( V_27 ) ;
F_8 ( V_25 ) ;
switch ( V_8 . V_14 ) {
case V_16 :
return F_15 ( V_12 ) ;
case V_15 :
return F_16 ( V_12 ) ;
case V_17 :
if ( V_12 == 0 )
return F_15 ( 0 ) ;
else
return F_16 ( 1 ) ;
case V_18 :
if ( V_12 == 0 )
return F_16 ( 0 ) ;
else
return F_15 ( 1 ) ;
}
}
if ( ( V_13 & V_20 ) == 0 ) {
assert ( V_19 == V_21 ) ;
if ( V_8 . V_28 & V_24 )
F_8 ( V_24 ) ;
return F_17 ( V_12 , V_21 - 1 + V_29 , V_13 ) ;
} else {
assert ( ( V_13 >> ( V_7 + 1 ) ) == 0 ) ;
assert ( V_13 & V_20 ) ;
return F_17 ( V_12 , V_19 + V_29 , V_13 & ~ V_20 ) ;
}
}
