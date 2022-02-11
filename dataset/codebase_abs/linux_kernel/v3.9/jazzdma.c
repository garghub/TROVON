static inline void F_1 ( void )
{
unsigned long V_1 = 0 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
V_4 [ V_2 ] . V_5 = V_1 ;
V_4 [ V_2 ] . V_6 = V_7 ;
V_1 += V_8 ;
}
}
static int T_1 F_2 ( void )
{
V_4 = ( V_9 * ) F_3 ( V_10 | V_11 ,
F_4 ( V_12 ) ) ;
F_5 ( ! V_4 ) ;
F_6 ( ( unsigned long ) V_4 , V_12 ) ;
V_4 = ( V_9 * ) F_7 ( V_4 ) ;
F_1 () ;
F_8 ( V_13 , F_9 ( V_4 ) ) ;
F_8 ( V_14 , V_12 ) ;
F_8 ( V_15 , 0 ) ;
F_10 ( V_16 L_1 ) ;
return 0 ;
}
unsigned long F_11 ( unsigned long V_1 , unsigned long V_17 )
{
int V_18 , V_19 , V_20 , V_5 , V_2 ;
unsigned long V_21 , V_22 ;
if ( V_1 > 0x1fffffff ) {
if ( V_23 )
F_10 ( L_2 ,
V_1 ) ;
return V_24 ;
}
if ( V_17 > 0x400000 || V_17 == 0 ) {
if ( V_23 )
F_10 ( L_3 , V_17 ) ;
return V_24 ;
}
F_12 ( & V_25 , V_22 ) ;
V_20 = F_13 ( V_1 + V_17 ) - F_13 ( V_1 ) + 1 ;
V_18 = 0 ;
while ( 1 ) {
while ( V_4 [ V_18 ] . V_6 != V_7 &&
V_18 < V_3 ) V_18 ++ ;
if ( V_18 + V_20 > V_3 ) {
F_14 ( & V_25 , V_22 ) ;
return V_24 ;
}
V_19 = V_18 + 1 ;
while ( V_4 [ V_19 ] . V_6 == V_7
&& V_19 - V_18 < V_20 )
V_19 ++ ;
if ( V_19 - V_18 == V_20 )
break;
V_18 = V_19 + 1 ;
}
V_21 = ( V_18 << 12 ) + ( V_1 & ( V_8 - 1 ) ) ;
V_5 = V_1 & ~ ( V_8 - 1 ) ;
for ( V_2 = V_18 ; V_2 < V_19 ; V_2 ++ ) {
V_4 [ V_2 ] . V_5 = V_5 ;
V_4 [ V_2 ] . V_6 = V_21 ;
V_5 += V_8 ;
}
F_8 ( V_15 , 0 ) ;
if ( V_23 > 1 )
F_10 ( L_4 ,
V_20 , V_21 ) ;
if ( V_23 > 2 ) {
F_10 ( L_5 ) ;
for ( V_2 = V_18 ; V_2 < V_19 ; V_2 ++ )
F_10 ( L_6 , V_2 << 12 ) ;
F_10 ( L_7 ) ;
for ( V_2 = V_18 ; V_2 < V_19 ; V_2 ++ )
F_10 ( L_6 , V_4 [ V_2 ] . V_5 ) ;
F_10 ( L_8 ) ;
for ( V_2 = V_18 ; V_2 < V_19 ; V_2 ++ )
F_10 ( L_6 , V_4 [ V_2 ] . V_6 ) ;
F_10 ( L_9 ) ;
}
F_14 ( & V_25 , V_22 ) ;
return V_21 ;
}
int F_15 ( unsigned long V_21 )
{
int V_2 ;
V_2 = V_21 >> 12 ;
if ( V_4 [ V_2 ] . V_6 != V_21 ) {
F_10
( L_10 ,
V_21 ) ;
return - 1 ;
}
while ( V_2 < V_3 && V_4 [ V_2 ] . V_6 == V_21 ) {
V_4 [ V_2 ] . V_6 = V_7 ;
V_2 ++ ;
}
if ( V_23 > 1 )
F_10 ( L_11 ,
V_2 - ( V_21 >> 12 ) , V_21 ) ;
return 0 ;
}
int F_16 ( unsigned long V_21 , unsigned long V_1 , unsigned long V_17 )
{
int V_18 , V_20 ;
if ( V_21 > 0xffffff ) {
if ( V_23 )
F_10
( L_12 ,
V_21 ) ;
return - V_26 ;
}
if ( V_1 > 0x1fffffff ) {
if ( V_23 )
F_10
( L_13 ,
V_1 ) ;
return - V_26 ;
}
V_20 = ( ( ( V_1 & ( V_8 - 1 ) ) + V_17 ) >> 12 ) + 1 ;
V_18 = V_21 >> 12 ;
if ( V_23 )
F_10 ( L_14 , V_18 , V_20 ) ;
if ( V_18 + V_20 > V_3 ) {
if ( V_23 )
F_10 ( L_3 , V_17 ) ;
return - V_26 ;
}
V_1 &= ~ ( V_8 - 1 ) ;
while ( V_20 > 0 && V_18 < V_3 ) {
if ( V_4 [ V_18 ] . V_6 != V_21 ) {
if ( V_23 )
F_10 ( L_15 ) ;
return - V_27 ;
}
V_4 [ V_18 ] . V_5 = V_1 ;
V_1 += V_8 ;
V_18 ++ ;
V_20 -- ;
}
F_8 ( V_15 , 0 ) ;
if ( V_23 > 2 ) {
int V_2 ;
V_20 = ( ( ( V_1 & ( V_8 - 1 ) ) + V_17 ) >> 12 ) + 1 ;
V_18 = V_21 >> 12 ;
F_10 ( L_5 ) ;
for ( V_2 = V_18 ; V_2 < V_18 + V_20 ; V_2 ++ )
F_10 ( L_6 , V_2 << 12 ) ;
F_10 ( L_7 ) ;
for ( V_2 = V_18 ; V_2 < V_18 + V_20 ; V_2 ++ )
F_10 ( L_6 , V_4 [ V_2 ] . V_5 ) ;
F_10 ( L_8 ) ;
for ( V_2 = V_18 ; V_2 < V_18 + V_20 ; V_2 ++ )
F_10 ( L_6 , V_4 [ V_2 ] . V_6 ) ;
F_10 ( L_9 ) ;
}
return 0 ;
}
unsigned long F_17 ( unsigned long V_1 )
{
int V_2 ;
int V_5 ;
V_5 = V_1 & ~ ( V_8 - 1 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_4 [ V_2 ] . V_5 == V_5 )
break;
}
if ( V_2 == V_3 )
return ~ 0UL ;
return ( V_2 << 12 ) + ( V_1 & ( V_8 - 1 ) ) ;
}
unsigned long F_18 ( unsigned long V_21 )
{
return V_4 [ V_21 >> 12 ] . V_5 + ( V_21 & ( V_8 - 1 ) ) ;
}
void F_19 ( void )
{
int V_2 ;
F_10 ( L_16 ,
F_20 ( V_28 ) ) ;
F_10 ( L_17 ,
F_20 ( V_13 ) ) ;
F_10 ( L_18 ,
F_20 ( V_14 ) ) ;
F_10 ( L_19 ,
F_20 ( V_29 ) ) ;
F_10 ( L_20 ,
F_20 ( V_30 ) ) ;
F_10 ( L_21 ,
F_20 ( V_31 ) ) ;
F_10 ( L_22 ,
F_20 ( V_32 ) ) ;
F_10 ( L_23 ,
F_20 ( V_33 ) ) ;
F_10 ( L_24 ) ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ )
F_10 ( L_25 ,
( unsigned ) F_20 ( V_34 +
( V_2 << 5 ) ) ) ;
F_10 ( L_9 ) ;
F_10 ( L_26 ) ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ )
F_10 ( L_25 ,
( unsigned ) F_20 ( V_35 +
( V_2 << 5 ) ) ) ;
F_10 ( L_9 ) ;
}
void F_21 ( int V_36 )
{
int V_37 ;
if ( V_23 )
F_10 ( L_27 , V_36 ) ;
V_37 = F_20 ( V_35 + ( V_36 << 5 ) ) ;
if ( V_37 & 0x400 )
F_10 ( L_28 , V_36 ) ;
if ( V_37 & 0x200 )
F_10 ( L_29 , V_36 ) ;
F_8 ( V_35 + ( V_36 << 5 ) ,
F_20 ( V_35 +
( V_36 << 5 ) ) | V_38
| V_39 | V_40 ) ;
F_8 ( V_35 + ( V_36 << 5 ) ,
F_20 ( V_35 +
( V_36 << 5 ) ) |
V_41 ) ;
}
void F_22 ( int V_36 )
{
if ( V_23 ) {
int V_37 =
F_20 ( V_35 +
( V_36 << 5 ) ) ;
F_10 ( L_30 , V_36 ) ;
F_10 ( L_31
L_32 ,
V_36 , V_37 ,
( ( V_37 & 0x600 ) ? L_33 : L_34 ) ,
( unsigned ) F_20 ( V_34 +
( V_36 << 5 ) ) ,
( unsigned ) F_20 ( V_42 +
( V_36 << 5 ) ) ,
( unsigned ) F_20 ( V_43 +
( V_36 << 5 ) ) ) ;
}
F_8 ( V_35 + ( V_36 << 5 ) ,
F_20 ( V_35 +
( V_36 << 5 ) ) &
~ V_41 ) ;
* ( ( volatile unsigned int * ) V_44 ) ;
}
void F_23 ( int V_36 , int V_45 )
{
if ( V_23 )
F_10 ( L_35 , V_36 ,
V_45 ) ;
switch ( V_36 ) {
case V_46 :
F_8 ( V_34 + ( V_36 << 5 ) ,
V_47 |
V_48 |
V_49 ) ;
break;
case V_50 :
F_8 ( V_34 + ( V_36 << 5 ) ,
V_47 |
V_51 |
V_52 ) ;
break;
case V_53 :
case V_54 :
F_10 ( L_36 ) ;
break;
default:
F_10
( L_37 ,
V_36 ) ;
}
switch ( V_45 ) {
case V_55 :
F_8 ( V_35 + ( V_36 << 5 ) ,
F_20 ( V_35 +
( V_36 << 5 ) ) &
~ V_56 ) ;
break;
case V_57 :
F_8 ( V_35 + ( V_36 << 5 ) ,
F_20 ( V_35 +
( V_36 << 5 ) ) |
V_56 ) ;
break;
default:
F_10
( L_38 ,
V_45 ) ;
}
}
void F_24 ( int V_36 , long V_58 )
{
if ( V_23 )
F_10 ( L_39 , V_36 ,
V_58 ) ;
F_8 ( V_42 + ( V_36 << 5 ) , V_58 ) ;
}
void F_25 ( int V_36 , int V_59 )
{
if ( V_23 )
F_10 ( L_40 , V_36 ,
( unsigned ) V_59 ) ;
F_8 ( V_43 + ( V_36 << 5 ) , V_59 ) ;
}
int F_26 ( int V_36 )
{
int V_60 ;
V_60 = F_20 ( V_43 + ( V_36 << 5 ) ) ;
if ( V_23 )
F_10 ( L_41 ,
V_36 , V_60 ) ;
return V_60 ;
}
int F_27 ( int V_36 )
{
int V_61 ;
V_61 = F_20 ( V_35 + ( V_36 << 5 ) ) ;
if ( V_23 )
F_10 ( L_42 , V_36 ,
V_61 ) ;
return V_61 ;
}
