static inline T_1 F_1 ( int V_1 )
{
T_1 V_2 ;
switch ( V_1 ) {
case 0 :
V_2 = F_2 ( V_3 ) ;
break;
case 1 :
V_2 = F_2 ( V_4 ) ;
break;
case 2 :
V_2 = F_2 ( V_5 ) ;
break;
case 3 :
V_2 = F_2 ( V_6 ) ;
break;
default:
F_3 ( L_1 ) ;
}
return V_2 ;
}
static inline void F_4 ( int V_1 , T_1 V_2 )
{
switch ( V_1 ) {
case 0 :
F_5 ( V_3 , V_2 ) ;
break;
case 1 :
F_5 ( V_4 , V_2 ) ;
break;
case 2 :
F_5 ( V_5 , V_2 ) ;
break;
case 3 :
F_5 ( V_6 , V_2 ) ;
break;
default:
F_3 ( L_1 ) ;
}
}
static inline unsigned int F_6 ( unsigned int V_7 )
{
switch( V_7 ) {
case 0 :
return F_2 ( V_8 ) ;
case 1 :
return F_2 ( V_9 ) ;
case 2 :
return F_2 ( V_10 ) ;
case 3 :
return F_2 ( V_11 ) ;
default:
return 0 ;
}
}
static inline void F_7 ( unsigned int V_7 , unsigned int V_12 )
{
switch( V_7 ) {
case 0 :
F_5 ( V_8 , V_12 ) ;
break;
case 1 :
F_5 ( V_9 , V_12 ) ;
break;
case 2 :
F_5 ( V_10 , V_12 ) ;
break;
case 3 :
F_5 ( V_11 , V_12 ) ;
break;
default:
break;
}
}
static void F_8 ( int V_1 )
{
T_1 V_2 = ( V_13 | V_14 | V_15 |
V_16 | V_17 ) ;
T_1 V_18 = 0 ;
switch ( V_1 ) {
case 0 :
F_5 ( V_3 , V_2 ) ;
F_5 ( V_19 , V_18 ) ;
break;
case 1 :
F_5 ( V_4 , V_2 ) ;
F_5 ( V_20 , V_18 ) ;
break;
case 2 :
F_5 ( V_5 , V_2 ) ;
F_5 ( V_21 , V_18 ) ;
break;
case 3 :
F_5 ( V_6 , V_2 ) ;
F_5 ( V_22 , V_18 ) ;
break;
default:
F_3 ( L_2 ) ;
}
}
static void F_9 ( int V_1 , int V_23 )
{
T_1 V_2 ;
V_2 = F_1 ( V_1 ) ;
V_2 = ( V_2 & ~ V_24 ) |
( ( V_23 << V_25 ) &
V_24 ) ;
F_4 ( V_1 , V_2 ) ;
}
static void F_10 ( int V_1 , int V_26 , int V_27 )
{
T_1 V_2 ;
V_2 = F_1 ( V_1 ) ;
if( V_26 )
V_2 &= ~ V_15 ;
else
V_2 |= V_15 ;
if( V_27 )
V_2 &= ~ V_14 ;
else
V_2 |= V_14 ;
F_4 ( V_1 , V_2 ) ;
}
static void F_11 ( int V_1 , int V_28 , int V_29 )
{
T_1 V_2 = F_1 ( V_1 ) ;
if( V_28 )
V_2 &= ~ V_17 ;
else
V_2 |= V_17 ;
if( V_29 )
V_2 &= ~ V_16 ;
else
V_2 |= V_16 ;
F_4 ( V_1 , V_2 ) ;
}
static void F_12 ( int V_1 , int V_30 )
{
T_1 V_2 = F_1 ( V_1 ) ;
V_2 &= ~ V_13 ;
if ( V_30 )
V_2 |= V_31 ;
else
V_2 &= ~ V_31 ;
F_4 ( V_1 , V_2 ) ;
}
static void F_13 ( int V_30 )
{
T_1 V_32 = F_2 ( V_33 ) ;
V_32 &= ~ V_34 ;
V_32 |= V_35 ;
if ( V_30 )
V_32 |= V_36 ;
else
V_32 &= ~ V_36 ;
F_5 ( V_33 , V_32 ) ;
}
static void F_14 ( void )
{
T_1 V_32 = F_2 ( V_33 ) ;
V_32 |= V_34 ;
V_32 &= ~ ( V_36 | V_35 ) ;
F_5 ( V_33 , V_32 ) ;
}
static int F_15 ( struct V_37 * V_1 )
{
int V_7 ;
F_14 () ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
F_8 ( V_7 ) ;
F_9 ( V_7 , V_1 [ V_7 ] . V_23 ) ;
F_10 ( V_7 , V_1 [ V_7 ] . V_26 , V_1 [ V_7 ] . V_27 ) ;
}
return 0 ;
}
static int F_16 ( struct V_37 * V_1 ,
struct V_39 * V_40 ,
int V_41 )
{
int V_7 ;
V_38 = V_41 ;
for ( V_7 = 0 ; V_7 < V_38 ; ++ V_7 )
V_42 [ V_7 ] = 0x80000000UL - V_1 [ V_7 ] . V_43 ;
return 0 ;
}
static int F_17 ( struct V_37 * V_1 )
{
int V_7 ;
F_18 ( F_19 () | V_44 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; ++ V_7 ) {
if ( V_1 [ V_7 ] . V_45 ) {
F_7 ( V_7 , V_42 [ V_7 ] ) ;
F_11 ( V_7 , 1 , 0 ) ;
F_12 ( V_7 , 1 ) ;
} else {
F_7 ( V_7 , 0 ) ;
F_12 ( V_7 , 0 ) ;
}
}
F_13 ( 1 ) ;
V_46 = 1 ;
F_20 ( L_3 , F_21 () ,
F_2 ( V_33 ) ) ;
return 0 ;
}
static void F_22 ( void )
{
F_14 () ;
V_46 = 0 ;
F_20 ( L_4 , F_21 () ,
F_2 ( V_33 ) ) ;
F_23 () ;
}
static void F_24 ( struct V_47 * V_48 ,
struct V_37 * V_1 )
{
unsigned long V_49 ;
int V_50 ;
int V_12 ;
int V_7 ;
V_49 = V_48 -> V_51 ;
V_50 = F_25 ( V_49 ) ;
for ( V_7 = 0 ; V_7 < V_38 ; ++ V_7 ) {
V_12 = F_6 ( V_7 ) ;
if ( V_12 < 0 ) {
if ( V_46 && V_1 [ V_7 ] . V_45 ) {
F_26 ( V_49 , V_48 , V_7 , V_50 ) ;
F_7 ( V_7 , V_42 [ V_7 ] ) ;
} else {
F_7 ( V_7 , 0 ) ;
}
}
}
F_18 ( F_19 () | V_44 ) ;
F_13 ( 1 ) ;
}
