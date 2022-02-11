static inline long F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long * V_4 ;
if ( V_3 == V_5 )
V_4 = & V_2 -> V_6 . V_7 ;
else if ( V_3 < F_2 ( V_8 ) )
V_4 = ( unsigned long * ) ( V_2 -> V_6 . V_9 + V_8 [ V_3 ] ) ;
else
return 0 ;
if ( V_3 == V_10 || V_3 == V_11 ) {
long V_12 = * ( long * ) ( V_2 -> V_6 . V_9 + F_3 ( V_12 ) ) ;
V_4 = ( unsigned long * ) ( ( unsigned long ) V_4 + V_12 ) ;
if ( V_3 == V_10 )
return * ( unsigned short * ) V_4 ;
}
return * V_4 ;
}
static inline int F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_13 )
{
unsigned long * V_4 ;
if ( V_3 == V_5 )
V_4 = & V_2 -> V_6 . V_7 ;
else if ( V_3 < F_2 ( V_8 ) )
V_4 = ( unsigned long * ) ( V_2 -> V_6 . V_9 + V_8 [ V_3 ] ) ;
else
return - 1 ;
if ( V_3 == V_10 || V_3 == V_11 ) {
long V_12 = * ( long * ) ( V_2 -> V_6 . V_9 + F_3 ( V_12 ) ) ;
V_4 = ( unsigned long * ) ( ( unsigned long ) V_4 + V_12 ) ;
if ( V_3 == V_10 ) {
* ( unsigned short * ) V_4 = V_13 ;
return 0 ;
}
}
* V_4 = V_13 ;
return 0 ;
}
static inline void F_5 ( struct V_1 * V_14 )
{
unsigned long V_15 = F_1 ( V_14 , V_10 ) & ~ V_16 ;
F_4 ( V_14 , V_10 , V_15 ) ;
F_6 ( V_14 , V_17 ) ;
}
void F_7 ( struct V_1 * V_14 )
{
F_5 ( V_14 ) ;
}
void F_8 ( struct V_1 * V_14 )
{
unsigned long V_15 = F_1 ( V_14 , V_10 ) & ~ V_16 ;
F_4 ( V_14 , V_10 , V_15 | V_18 ) ;
F_9 ( V_14 , V_17 ) ;
}
void F_10 ( struct V_1 * V_14 )
{
unsigned long V_15 = F_1 ( V_14 , V_10 ) & ~ V_16 ;
F_4 ( V_14 , V_10 , V_15 | V_19 ) ;
}
void F_11 ( struct V_1 * V_14 )
{
F_5 ( V_14 ) ;
}
long F_12 ( struct V_1 * V_14 , long V_20 ,
unsigned long V_4 , unsigned long V_13 )
{
unsigned long V_15 ;
int V_21 , V_22 = 0 ;
int V_3 = V_4 >> 2 ;
unsigned long T_1 * V_23 = ( unsigned long T_1 * ) V_13 ;
switch ( V_20 ) {
case V_24 :
if ( V_4 & 3 )
goto V_25;
if ( V_3 >= 0 && V_3 < 19 ) {
V_15 = F_1 ( V_14 , V_3 ) ;
} else if ( V_3 >= 21 && V_3 < 49 ) {
V_15 = V_14 -> V_6 . V_26 [ V_3 - 21 ] ;
if ( V_27 && ( V_3 < 45 ) && ! ( V_3 % 3 ) )
V_15 = ( ( V_15 & 0xffff0000 ) << 15 ) |
( ( V_15 & 0x0000ffff ) << 16 ) ;
} else
goto V_25;
V_22 = F_13 ( V_15 , V_23 ) ;
break;
case V_28 :
if ( V_4 & 3 )
goto V_25;
if ( V_3 == V_10 ) {
V_13 &= V_29 ;
V_13 |= F_1 ( V_14 , V_10 ) & ~ V_29 ;
}
if ( V_3 >= 0 && V_3 < 19 ) {
if ( F_4 ( V_14 , V_3 , V_13 ) )
goto V_25;
} else if ( V_3 >= 21 && V_3 < 48 ) {
if ( V_27 && ( V_3 < 45 ) && ! ( V_3 % 3 ) ) {
V_13 <<= 15 ;
V_13 = ( V_13 & 0xffff0000 ) |
( ( V_13 & 0x0000ffff ) >> 1 ) ;
}
V_14 -> V_6 . V_26 [ V_3 - 21 ] = V_13 ;
} else
goto V_25;
break;
case V_30 :
for ( V_21 = 0 ; V_21 < 19 ; V_21 ++ ) {
V_15 = F_1 ( V_14 , V_21 ) ;
V_22 = F_13 ( V_15 , V_23 ) ;
if ( V_22 )
break;
V_23 ++ ;
}
break;
case V_31 :
for ( V_21 = 0 ; V_21 < 19 ; V_21 ++ ) {
V_22 = F_14 ( V_15 , V_23 ) ;
if ( V_22 )
break;
if ( V_21 == V_10 ) {
V_15 &= V_29 ;
V_15 |= F_1 ( V_14 , V_10 ) & ~ V_29 ;
}
F_4 ( V_14 , V_21 , V_15 ) ;
V_23 ++ ;
}
break;
case V_32 :
if ( F_15 ( V_23 , & V_14 -> V_6 . V_26 ,
sizeof( struct V_33 ) ) )
V_22 = - V_34 ;
break;
case V_35 :
if ( F_16 ( & V_14 -> V_6 . V_26 , V_23 ,
sizeof( struct V_33 ) ) )
V_22 = - V_34 ;
break;
case V_36 :
V_22 = F_13 ( F_17 ( V_14 ) -> V_37 , V_23 ) ;
break;
default:
V_22 = F_18 ( V_14 , V_20 , V_4 , V_13 ) ;
break;
}
return V_22 ;
V_25:
return - V_38 ;
}
T_2 void F_19 ( void )
{
F_20 ( V_39 | ( ( V_40 -> V_41 & V_42 )
? 0x80 : 0 ) ) ;
if ( V_40 -> V_43 ) {
F_21 ( V_40 -> V_43 , V_40 , 1 ) ;
V_40 -> V_43 = 0 ;
}
}
T_2 int F_22 ( void )
{
int V_22 = 0 ;
if ( F_23 ( V_44 ) )
V_22 = F_24 ( F_25 ( V_40 ) ) ;
return V_22 ;
}
T_2 void F_26 ( void )
{
if ( F_23 ( V_44 ) )
F_27 ( F_25 ( V_40 ) , 0 ) ;
}
