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
assert ( F_2 ( V_2 ) ) ;
return F_5 ( V_2 ) & F_6 ( V_6 - 1 ) ;
}
union V_1 T_1 F_7 ( union V_1 V_7 )
{
assert ( F_4 ( V_7 ) ) ;
F_8 ( V_8 ) ;
return F_9 () ;
}
static unsigned F_10 ( int V_9 , unsigned V_10 )
{
if ( V_10 & ( F_6 ( 3 ) - 1 ) ) {
switch ( V_11 . V_12 ) {
case V_13 :
break;
case V_14 :
V_10 += 0x3 + ( ( V_10 >> 3 ) & 1 ) ;
break;
case V_15 :
if ( ! V_9 )
V_10 += 0x8 ;
break;
case V_16 :
if ( V_9 )
V_10 += 0x8 ;
break;
}
}
return V_10 ;
}
union V_1 F_11 ( int V_9 , int V_17 , unsigned V_10 )
{
assert ( V_10 ) ;
assert ( ( V_10 >> ( V_6 + 1 + 3 ) ) == 0 ) ;
assert ( V_10 & ( V_18 << 3 ) ) ;
if ( V_17 < V_19 ) {
int V_20 = V_19 - V_17 ;
if ( V_11 . V_21 ) {
F_8 ( V_22 ) ;
F_8 ( V_23 ) ;
switch( V_11 . V_12 ) {
case V_14 :
case V_13 :
return F_12 ( V_9 ) ;
case V_15 :
if ( V_9 == 0 )
return F_13 ( 0 ) ;
else
return F_12 ( 1 ) ;
case V_16 :
if ( V_9 == 0 )
return F_12 ( 0 ) ;
else
return F_13 ( 1 ) ;
}
}
if ( V_17 == V_19 - 1 &&
F_10 ( V_9 , V_10 ) >> ( V_6 + 1 + 3 ) )
{
F_8 ( V_23 ) ;
V_10 = F_10 ( V_9 , V_10 ) ;
V_10 >>= 1 ;
V_10 &= ~ ( F_6 ( 3 ) - 1 ) ;
V_17 ++ ;
} else {
F_14 ( V_20 ) ;
assert ( ( V_10 & ( V_18 << 3 ) ) == 0 ) ;
assert ( V_17 == V_19 ) ;
}
}
if ( V_10 & ( F_6 ( 3 ) - 1 ) ) {
F_8 ( V_23 ) ;
if ( ( V_10 & ( V_18 << 3 ) ) == 0 ) {
F_8 ( V_22 ) ;
}
V_10 = F_10 ( V_9 , V_10 ) ;
if ( V_10 >> ( V_6 + 1 + 3 ) ) {
V_10 >>= 1 ;
V_17 ++ ;
}
}
V_10 >>= 3 ;
assert ( ( V_10 >> ( V_6 + 1 ) ) == 0 ) ;
assert ( V_17 >= V_19 ) ;
if ( V_17 > V_24 ) {
F_8 ( V_25 ) ;
F_8 ( V_23 ) ;
switch ( V_11 . V_12 ) {
case V_14 :
return F_15 ( V_9 ) ;
case V_13 :
return F_16 ( V_9 ) ;
case V_15 :
if ( V_9 == 0 )
return F_15 ( 0 ) ;
else
return F_16 ( 1 ) ;
case V_16 :
if ( V_9 == 0 )
return F_16 ( 0 ) ;
else
return F_15 ( 1 ) ;
}
}
if ( ( V_10 & V_18 ) == 0 ) {
assert ( V_17 == V_19 ) ;
if ( V_11 . V_26 & V_22 )
F_8 ( V_22 ) ;
return F_17 ( V_9 , V_19 - 1 + V_27 , V_10 ) ;
} else {
assert ( ( V_10 >> ( V_6 + 1 ) ) == 0 ) ;
assert ( V_10 & V_18 ) ;
return F_17 ( V_9 , V_17 + V_27 , V_10 & ~ V_18 ) ;
}
}
