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
case 4 :
V_2 = F_2 ( V_7 ) ;
break;
case 5 :
V_2 = F_2 ( V_8 ) ;
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
case 4 :
F_5 ( V_7 , V_2 ) ;
break;
case 5 :
F_5 ( V_8 , V_2 ) ;
break;
default:
F_3 ( L_1 ) ;
}
}
static inline unsigned int F_6 ( unsigned int V_9 )
{
switch( V_9 ) {
case 0 :
return F_2 ( V_10 ) ;
case 1 :
return F_2 ( V_11 ) ;
case 2 :
return F_2 ( V_12 ) ;
case 3 :
return F_2 ( V_13 ) ;
case 4 :
return F_2 ( V_14 ) ;
case 5 :
return F_2 ( V_15 ) ;
default:
return 0 ;
}
}
static inline void F_7 ( unsigned int V_9 , unsigned int V_16 )
{
switch( V_9 ) {
case 0 :
F_5 ( V_10 , V_16 ) ;
break;
case 1 :
F_5 ( V_11 , V_16 ) ;
break;
case 2 :
F_5 ( V_12 , V_16 ) ;
break;
case 3 :
F_5 ( V_13 , V_16 ) ;
break;
case 4 :
F_5 ( V_14 , V_16 ) ;
break;
case 5 :
F_5 ( V_15 , V_16 ) ;
break;
default:
break;
}
}
static void F_8 ( int V_1 )
{
T_1 V_2 = ( V_17 | V_18 | V_19 |
V_20 | V_21 ) ;
T_1 V_22 = 0 ;
switch ( V_1 ) {
case 0 :
F_5 ( V_3 , V_2 ) ;
F_5 ( V_23 , V_22 ) ;
break;
case 1 :
F_5 ( V_4 , V_2 ) ;
F_5 ( V_24 , V_22 ) ;
break;
case 2 :
F_5 ( V_5 , V_2 ) ;
F_5 ( V_25 , V_22 ) ;
break;
case 3 :
F_5 ( V_6 , V_2 ) ;
F_5 ( V_26 , V_22 ) ;
break;
case 4 :
F_5 ( V_7 , V_2 ) ;
F_5 ( V_27 , V_22 ) ;
break;
case 5 :
F_5 ( V_8 , V_2 ) ;
F_5 ( V_28 , V_22 ) ;
break;
default:
F_3 ( L_2 ) ;
}
}
static void F_9 ( int V_1 , int V_29 )
{
T_1 V_2 ;
V_2 = F_1 ( V_1 ) ;
V_2 = ( V_2 & ~ V_30 ) |
( ( V_29 << V_31 ) &
V_30 ) ;
F_4 ( V_1 , V_2 ) ;
}
static void F_10 ( int V_1 , int V_32 , int V_33 )
{
T_1 V_2 ;
V_2 = F_1 ( V_1 ) ;
if( V_32 )
V_2 &= ~ V_19 ;
else
V_2 |= V_19 ;
if( V_33 )
V_2 &= ~ V_18 ;
else
V_2 |= V_18 ;
F_4 ( V_1 , V_2 ) ;
}
static void F_11 ( int V_1 , int V_34 , int V_35 )
{
T_1 V_2 = F_1 ( V_1 ) ;
if( V_34 )
V_2 &= ~ V_21 ;
else
V_2 |= V_21 ;
if( V_35 )
V_2 &= ~ V_20 ;
else
V_2 |= V_20 ;
F_4 ( V_1 , V_2 ) ;
}
static void F_12 ( int V_1 , int V_36 )
{
T_1 V_2 = F_1 ( V_1 ) ;
V_2 &= ~ V_17 ;
if ( V_36 )
V_2 |= V_37 ;
else
V_2 &= ~ V_37 ;
F_4 ( V_1 , V_2 ) ;
}
static void F_13 ( int V_36 )
{
T_1 V_38 = F_2 ( V_39 ) ;
V_38 &= ~ V_40 ;
V_38 |= V_41 ;
if ( V_36 )
V_38 |= V_42 ;
else
V_38 &= ~ V_42 ;
F_5 ( V_39 , V_38 ) ;
}
static void F_14 ( void )
{
T_1 V_38 = F_2 ( V_39 ) ;
V_38 |= V_40 ;
V_38 &= ~ ( V_42 | V_41 ) ;
F_5 ( V_39 , V_38 ) ;
}
static int F_15 ( struct V_43 * V_1 )
{
int V_9 ;
F_14 () ;
for ( V_9 = 0 ; V_9 < V_44 ; V_9 ++ ) {
F_8 ( V_9 ) ;
F_9 ( V_9 , V_1 [ V_9 ] . V_29 ) ;
F_10 ( V_9 , V_1 [ V_9 ] . V_32 , V_1 [ V_9 ] . V_33 ) ;
}
return 0 ;
}
static int F_16 ( struct V_43 * V_1 ,
struct V_45 * V_46 ,
int V_47 )
{
int V_9 ;
V_44 = V_47 ;
for ( V_9 = 0 ; V_9 < V_44 ; ++ V_9 )
V_48 [ V_9 ] = 0x80000000UL - V_1 [ V_9 ] . V_49 ;
return 0 ;
}
static int F_17 ( struct V_43 * V_1 )
{
int V_9 ;
F_18 ( F_19 () | V_50 ) ;
for ( V_9 = 0 ; V_9 < V_44 ; ++ V_9 ) {
if ( V_1 [ V_9 ] . V_51 ) {
F_7 ( V_9 , V_48 [ V_9 ] ) ;
F_11 ( V_9 , 1 , 0 ) ;
F_12 ( V_9 , 1 ) ;
} else {
F_7 ( V_9 , 0 ) ;
F_12 ( V_9 , 0 ) ;
}
}
F_13 ( 1 ) ;
V_52 = 1 ;
F_20 ( L_3 , F_21 () ,
F_2 ( V_39 ) ) ;
return 0 ;
}
static void F_22 ( void )
{
F_14 () ;
V_52 = 0 ;
F_20 ( L_4 , F_21 () ,
F_2 ( V_39 ) ) ;
F_23 () ;
}
static void F_24 ( struct V_53 * V_54 ,
struct V_43 * V_1 )
{
unsigned long V_55 ;
int V_56 ;
int V_16 ;
int V_9 ;
V_55 = V_54 -> V_57 ;
V_56 = F_25 ( V_55 ) ;
for ( V_9 = 0 ; V_9 < V_44 ; ++ V_9 ) {
V_16 = F_6 ( V_9 ) ;
if ( V_16 < 0 ) {
if ( V_52 && V_1 [ V_9 ] . V_51 ) {
F_26 ( V_55 , V_54 , V_9 , V_56 ) ;
F_7 ( V_9 , V_48 [ V_9 ] ) ;
} else {
F_7 ( V_9 , 0 ) ;
}
}
}
F_18 ( F_19 () | V_50 ) ;
F_13 ( 1 ) ;
}
