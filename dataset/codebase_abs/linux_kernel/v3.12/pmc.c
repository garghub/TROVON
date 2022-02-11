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
if ( V_30 < V_31 || V_30 >= V_32 )
return;
V_28 . V_29 = V_30 ;
}
void F_22 ( void )
{
F_3 ( F_23 ( V_33 ) , V_34 ) ;
}
void F_24 ( void )
{
F_3 ( 0x0 , V_34 ) ;
}
void F_25 ( enum V_27 V_30 )
{
T_1 V_1 , V_35 ;
unsigned long V_21 = 0 ;
V_1 = F_1 ( V_36 ) ;
V_1 |= V_37 ;
V_1 &= ~ V_38 ;
switch ( V_39 ) {
case V_40 :
case V_41 :
break;
default:
V_35 = F_26 ( 0 ) ;
V_35 &= ~ V_42 ;
V_35 |= V_43 ;
F_27 ( 0 , V_35 ) ;
break;
}
switch ( V_30 ) {
case V_44 :
V_21 = 32768 ;
break;
case V_45 :
V_21 = F_28 ( V_46 ) ;
break;
default:
break;
}
F_16 ( V_28 . V_47 , V_28 . V_48 ,
V_21 ) ;
F_3 ( V_1 , V_36 ) ;
}
void F_29 ( void )
{
T_1 V_1 ;
V_1 = F_1 ( V_36 ) ;
V_1 |= V_37 ;
F_3 ( V_1 , V_36 ) ;
V_1 = F_1 ( V_36 ) ;
if ( ! V_28 . V_49 )
V_1 |= V_50 ;
else
V_1 &= ~ V_50 ;
F_3 ( V_1 , V_36 ) ;
V_1 |= V_51 ;
F_3 ( V_1 , V_36 ) ;
}
static void T_2 F_30 ( void )
{
struct V_52 * V_53 ;
T_1 V_54 ;
enum V_27 V_29 ;
T_1 V_55 [ 2 ] = { 0 , 0 } ;
T_1 V_56 [ 2 ] = { 0 , 0 } ;
V_53 = F_31 ( NULL , V_57 ) ;
F_32 ( ! V_53 ) ;
V_2 = F_33 ( V_53 , 0 ) ;
V_58 = F_34 ( V_53 ,
L_1 ) ;
V_46 = F_35 ( V_53 , L_2 ) ;
F_10 ( F_36 ( V_46 ) ) ;
if ( F_37 ( V_53 , L_3 , & V_54 ) ) {
V_29 = V_31 ;
} else {
switch ( V_54 ) {
case 0 :
V_29 = V_59 ;
break;
case 1 :
V_29 = V_44 ;
break;
case 2 :
V_29 = V_45 ;
break;
default:
V_29 = V_31 ;
break;
}
}
V_29 = F_38 ( V_29 ) ;
if ( F_37 ( V_53 , L_4 , & V_54 ) )
V_29 = V_31 ;
V_28 . V_47 = V_54 ;
if ( F_37 ( V_53 , L_5 , & V_54 ) )
V_29 = V_31 ;
V_28 . V_48 = V_54 ;
if ( F_39 ( V_53 , L_6 ,
V_55 , F_40 ( V_55 ) ) )
V_29 = V_31 ;
V_28 . V_60 = V_55 [ 0 ] ;
V_28 . V_61 = V_55 [ 1 ] ;
if ( F_37 ( V_53 , L_7 ,
& V_54 ) )
V_29 = V_31 ;
V_28 . V_62 = V_54 ;
V_28 . V_63 = F_34 ( V_53 ,
L_8 ) ;
V_28 . V_49 = F_34 ( V_53 ,
L_9 ) ;
V_28 . V_64 = F_34 ( V_53 ,
L_10 ) ;
V_28 . V_65 = F_34 ( V_53 ,
L_11 ) ;
if ( F_39 ( V_53 , L_12 , V_56 ,
F_40 ( V_56 ) ) )
if ( V_29 == V_59 )
V_29 = V_44 ;
V_28 . V_66 = V_56 [ 0 ] ;
V_28 . V_67 = V_56 [ 1 ] ;
V_28 . V_29 = V_29 ;
}
void T_2 F_41 ( void )
{
T_1 V_3 ;
F_30 () ;
V_3 = F_1 ( V_36 ) ;
if ( V_58 )
V_3 |= V_68 ;
else
V_3 &= ~ V_68 ;
F_3 ( V_3 , V_36 ) ;
}
