static inline long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long * V_4 ;
if ( V_3 == V_5 )
V_4 = & V_2 -> V_6 . V_7 ;
else if ( V_3 < F_2 ( V_8 ) )
V_4 = ( unsigned long * ) ( V_2 -> V_6 . V_9 + V_8 [ V_3 ] ) ;
else
return 0 ;
return * V_4 ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_10 )
{
unsigned long * V_4 ;
if ( V_3 == V_5 )
V_4 = & V_2 -> V_6 . V_7 ;
else if ( V_3 < F_2 ( V_8 ) )
V_4 = ( unsigned long * ) ( V_2 -> V_6 . V_9 + V_8 [ V_3 ] ) ;
else
return - 1 ;
* V_4 = V_10 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
V_11 = F_1 ( V_2 , V_12 ) | ( V_13 << 16 ) ;
F_3 ( V_2 , V_12 , V_11 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
V_11 = F_1 ( V_2 , V_12 ) & ~ ( V_13 << 16 ) ;
F_3 ( V_2 , V_12 , V_11 ) ;
}
void F_6 ( struct V_1 * V_14 )
{
F_5 ( V_14 ) ;
}
long F_7 ( struct V_1 * V_14 , long V_15 ,
unsigned long V_4 , unsigned long V_10 )
{
int V_16 ;
int V_3 = V_4 >> 2 ;
unsigned long T_1 * V_17 = ( unsigned long T_1 * ) V_10 ;
switch ( V_15 ) {
case V_18 : {
unsigned long V_19 ;
V_16 = - V_20 ;
if ( ( V_4 & 3 ) || V_4 > sizeof( struct V_21 ) - 3 )
break;
V_19 = 0 ;
V_16 = - V_20 ;
if ( V_3 < 19 ) {
V_19 = F_1 ( V_14 , V_3 ) ;
if ( V_3 == V_12 )
V_19 >>= 16 ;
} else if ( V_3 >= 21 && V_3 < 49 ) {
V_19 = V_14 -> V_6 . V_22 [ V_3 - 21 ] ;
} else if ( V_3 == 49 ) {
V_19 = V_14 -> V_23 -> V_24 ;
} else if ( V_3 == 50 ) {
V_19 = V_14 -> V_23 -> V_25 ;
} else if ( V_3 == 51 ) {
V_19 = V_14 -> V_23 -> V_26 ;
} else
break;
V_16 = F_8 ( V_19 , V_17 ) ;
break;
}
case V_27 :
V_16 = - V_20 ;
if ( ( V_4 & 3 ) || V_4 > sizeof( struct V_21 ) - 3 )
break;
if ( V_3 == V_12 ) {
V_10 &= V_28 ;
V_10 <<= 16 ;
V_10 |= F_1 ( V_14 , V_12 ) & ~ ( V_28 << 16 ) ;
}
if ( V_3 < 19 ) {
if ( F_3 ( V_14 , V_3 , V_10 ) )
break;
V_16 = 0 ;
break;
}
if ( V_3 >= 21 && V_3 < 48 )
{
V_14 -> V_6 . V_22 [ V_3 - 21 ] = V_10 ;
V_16 = 0 ;
}
break;
case V_29 : {
int V_30 ;
unsigned long V_19 ;
for ( V_30 = 0 ; V_30 < 19 ; V_30 ++ ) {
V_19 = F_1 ( V_14 , V_30 ) ;
if ( V_30 == V_12 )
V_19 >>= 16 ;
if ( F_8 ( V_19 , V_17 ) ) {
V_16 = - V_31 ;
break;
}
V_17 ++ ;
}
V_16 = 0 ;
break;
}
case V_32 : {
int V_30 ;
unsigned long V_19 ;
for ( V_30 = 0 ; V_30 < 19 ; V_30 ++ ) {
if ( F_9 ( V_19 , V_17 ) ) {
V_16 = - V_31 ;
break;
}
if ( V_30 == V_12 ) {
V_19 &= V_28 ;
V_19 <<= 16 ;
V_19 |= F_1 ( V_14 , V_12 ) & ~ ( V_28 << 16 ) ;
}
F_3 ( V_14 , V_30 , V_19 ) ;
V_17 ++ ;
}
V_16 = 0 ;
break;
}
#ifdef F_10
case F_10 : {
V_16 = 0 ;
if ( F_11 ( V_17 , & V_14 -> V_6 . V_22 ,
sizeof( struct V_33 ) ) )
V_16 = - V_31 ;
break;
}
#endif
#ifdef F_12
case F_12 : {
V_16 = 0 ;
if ( F_13 ( & V_14 -> V_6 . V_22 , V_17 ,
sizeof( struct V_33 ) ) )
V_16 = - V_31 ;
break;
}
#endif
case V_34 :
V_16 = F_8 ( F_14 ( V_14 ) -> V_35 , V_17 ) ;
break;
default:
V_16 = F_15 ( V_14 , V_15 , V_4 , V_10 ) ;
break;
}
return V_16 ;
}
T_2 int F_16 ( void )
{
int V_16 = 0 ;
if ( F_17 ( V_36 ) )
V_16 = F_18 ( F_19 ( V_37 ) ) ;
return V_16 ;
}
T_2 void F_20 ( void )
{
if ( F_17 ( V_36 ) )
F_21 ( F_19 ( V_37 ) , 0 ) ;
}
