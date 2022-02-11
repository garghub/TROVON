static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_3 , T_1 V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( int V_4 )
{
if ( V_4 <= 0 || V_4 >= F_6 () )
return - V_5 ;
return V_6 [ V_4 ] ;
}
static bool F_7 ( int V_7 )
{
return ( F_1 ( V_8 ) >> V_7 ) & 1 ;
}
static int F_8 ( int V_7 , bool V_9 )
{
bool V_10 ;
unsigned long V_11 ;
F_9 ( & V_12 , V_11 ) ;
V_10 = F_7 ( V_7 ) ;
F_10 ( V_10 == V_9 ) ;
F_3 ( V_13 | V_7 , V_14 ) ;
F_11 ( & V_12 , V_11 ) ;
return 0 ;
}
static int F_12 ( int V_7 )
{
T_1 V_15 ;
if ( V_7 == V_16 )
V_15 = ( 1 << V_17 ) ;
else if ( V_7 == V_17 )
V_15 = ( 1 << V_16 ) ;
else
V_15 = ( 1 << V_7 ) ;
F_3 ( V_15 , V_18 ) ;
return 0 ;
}
bool F_13 ( int V_4 )
{
int V_7 ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 < 0 )
return false ;
return F_7 ( V_7 ) ;
}
int F_14 ( int V_4 )
{
int V_7 ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_8 ( V_7 , true ) ;
}
int F_15 ( int V_4 )
{
int V_7 ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_12 ( V_7 ) ;
}
static void F_16 ( T_1 V_19 , T_1 V_20 , unsigned long V_21 )
{
unsigned long long V_22 ;
unsigned long long V_23 ;
static unsigned long V_24 ;
if ( F_17 ( V_21 <= 0 ) )
V_23 = 100000000 ;
else
V_23 = V_21 ;
if ( ( V_21 != V_24 ) ) {
V_22 = ( V_19 * V_23 ) + 999999ull ;
F_18 ( V_22 , 1000000 ) ;
F_3 ( ( unsigned long ) V_22 , V_25 ) ;
V_22 = ( V_20 * V_23 ) + 999999ull ;
F_18 ( V_22 , 1000000 ) ;
F_3 ( ( unsigned long ) V_22 , V_26 ) ;
F_19 () ;
}
V_24 = V_23 ;
}
enum V_27 F_20 ( void )
{
return V_28 . V_29 ;
}
void F_21 ( enum V_27 V_30 )
{
T_1 V_1 ;
unsigned long V_21 = 0 ;
V_1 = F_1 ( V_31 ) ;
V_1 |= V_32 ;
V_1 &= ~ V_33 ;
switch ( V_30 ) {
case V_34 :
V_21 = F_22 ( V_35 ) ;
break;
default:
break;
}
F_16 ( V_28 . V_36 , V_28 . V_37 ,
V_21 ) ;
F_3 ( V_1 , V_31 ) ;
}
void F_23 ( void )
{
T_1 V_1 ;
V_1 = F_1 ( V_31 ) ;
V_1 |= V_32 ;
F_3 ( V_1 , V_31 ) ;
}
static void T_2 F_24 ( void )
{
struct V_38 * V_39 ;
T_1 V_40 ;
enum V_27 V_29 ;
T_1 V_41 [ 2 ] = { 0 , 0 } ;
T_1 V_42 [ 2 ] = { 0 , 0 } ;
V_39 = F_25 ( NULL , V_43 ) ;
F_26 ( ! V_39 ) ;
V_2 = F_27 ( V_39 , 0 ) ;
V_44 = F_28 ( V_39 ,
L_1 ) ;
V_35 = F_29 ( V_39 , L_2 ) ;
F_10 ( F_30 ( V_35 ) ) ;
if ( F_31 ( V_39 , L_3 , & V_40 ) ) {
V_29 = V_45 ;
} else {
switch ( V_40 ) {
case 0 :
V_29 = V_46 ;
break;
case 1 :
V_29 = V_47 ;
break;
case 2 :
V_29 = V_34 ;
break;
default:
V_29 = V_45 ;
break;
}
}
V_29 = F_32 ( V_29 ) ;
if ( F_31 ( V_39 , L_4 , & V_40 ) )
V_29 = V_45 ;
V_28 . V_36 = V_40 ;
if ( F_31 ( V_39 , L_5 , & V_40 ) )
V_29 = V_45 ;
V_28 . V_37 = V_40 ;
if ( F_33 ( V_39 , L_6 ,
V_41 , F_34 ( V_41 ) ) )
V_29 = V_45 ;
V_28 . V_48 = V_41 [ 0 ] ;
V_28 . V_49 = V_41 [ 1 ] ;
if ( F_31 ( V_39 , L_7 ,
& V_40 ) )
V_29 = V_45 ;
V_28 . V_50 = V_40 ;
V_28 . V_51 = F_28 ( V_39 ,
L_8 ) ;
V_28 . V_52 = F_28 ( V_39 ,
L_9 ) ;
V_28 . V_53 = F_28 ( V_39 ,
L_10 ) ;
V_28 . V_54 = F_28 ( V_39 ,
L_11 ) ;
if ( F_33 ( V_39 , L_12 , V_42 ,
F_34 ( V_42 ) ) )
if ( V_29 == V_46 )
V_29 = V_47 ;
V_28 . V_55 = V_42 [ 0 ] ;
V_28 . V_56 = V_42 [ 1 ] ;
V_28 . V_29 = V_29 ;
}
void T_2 F_35 ( void )
{
T_1 V_3 ;
F_24 () ;
V_3 = F_1 ( V_31 ) ;
if ( V_44 )
V_3 |= V_57 ;
else
V_3 &= ~ V_57 ;
F_3 ( V_3 , V_31 ) ;
}
