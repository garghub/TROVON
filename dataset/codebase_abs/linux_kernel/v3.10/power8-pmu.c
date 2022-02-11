static inline bool F_1 ( T_1 V_1 )
{
V_1 &= 0xff0fe ;
return ( V_1 == 0x30056 || V_1 == 0x4f052 ) ;
}
static int F_2 ( T_1 V_1 , unsigned long * V_2 , unsigned long * V_3 )
{
unsigned int V_4 , V_5 , V_6 ;
unsigned long V_7 , V_8 ;
V_7 = V_8 = 0 ;
V_5 = ( V_1 >> V_9 ) & V_10 ;
V_4 = ( V_1 >> V_11 ) & V_12 ;
V_6 = ( V_1 >> V_13 ) & V_14 ;
if ( V_5 ) {
if ( V_5 > 6 )
return - 1 ;
V_7 |= F_3 ( V_5 ) ;
V_8 |= F_4 ( V_5 ) ;
if ( V_5 >= 5 && V_1 != 0x500fa && V_1 != 0x600f4 )
return - 1 ;
}
if ( V_5 <= 4 ) {
V_7 |= V_15 ;
V_8 |= V_16 ;
}
if ( V_4 >= 6 && V_4 <= 9 ) {
if ( V_6 )
return - 1 ;
} else if ( V_1 & V_17 ) {
V_7 |= V_18 ;
V_8 |= F_5 ( V_6 ) ;
}
if ( V_1 & V_19 ) {
V_7 |= V_20 ;
V_8 |= F_6 ( V_1 >> V_21 ) ;
}
if ( F_1 ( V_1 ) ) {
V_7 |= V_22 ;
V_8 |= F_7 ( V_1 >> V_23 ) ;
} else {
unsigned int V_24 , exp ;
V_24 = ( V_1 >> V_25 ) & V_26 ;
exp = V_24 >> 7 ;
if ( exp && ( V_24 & 0x60 ) == 0 )
return - 1 ;
V_7 |= V_27 ;
V_8 |= F_8 ( V_1 >> V_28 ) ;
}
* V_2 = V_7 ;
* V_3 = V_8 ;
return 0 ;
}
static int F_9 ( T_1 V_1 [] , int V_29 ,
unsigned int V_30 [] , unsigned long V_31 [] )
{
unsigned long V_32 , V_33 , V_4 , V_34 , V_35 , V_6 , V_36 ;
unsigned int V_5 , V_37 ;
int V_38 ;
V_37 = 0 ;
for ( V_38 = 0 ; V_38 < V_29 ; ++ V_38 ) {
V_5 = ( V_1 [ V_38 ] >> V_9 ) & V_10 ;
if ( V_5 )
V_37 |= 1 << V_5 ;
}
V_32 = V_39 ;
V_33 = 0 ;
for ( V_38 = 0 ; V_38 < V_29 ; ++ V_38 ) {
V_5 = ( V_1 [ V_38 ] >> V_9 ) & V_10 ;
V_4 = ( V_1 [ V_38 ] >> V_11 ) & V_12 ;
V_34 = ( V_1 [ V_38 ] >> V_40 ) & V_41 ;
V_35 = V_1 [ V_38 ] & V_42 ;
if ( ! V_5 ) {
for ( V_5 = 1 ; V_5 <= 4 ; ++ V_5 ) {
if ( ! ( V_37 & ( 1 << V_5 ) ) )
break;
}
V_37 |= 1 << V_5 ;
}
if ( V_5 <= 4 ) {
V_33 |= V_4 << F_10 ( V_5 ) ;
V_33 |= V_34 << F_11 ( V_5 ) ;
V_33 |= V_35 << F_12 ( V_5 ) ;
}
if ( V_1 [ V_38 ] & V_17 ) {
V_6 = V_1 [ V_38 ] >> V_13 ;
V_33 |= ( V_6 & 1 ) << V_43 ;
V_6 >>= 1 ;
V_33 |= ( V_6 & 1 ) << V_44 ;
}
if ( V_1 [ V_38 ] & V_19 ) {
V_32 |= V_45 ;
V_36 = ( V_1 [ V_38 ] >> V_21 ) & V_46 ;
if ( V_36 ) {
V_32 |= ( V_36 & 3 ) << V_47 ;
V_32 |= ( V_36 >> 2 ) << V_48 ;
}
}
if ( F_1 ( V_1 [ V_38 ] ) ) {
V_33 |= ( V_1 [ V_38 ] >> V_23 ) &
V_49 ;
} else {
V_36 = ( V_1 [ V_38 ] >> V_23 ) & V_49 ;
V_32 |= V_36 << V_50 ;
V_36 = ( V_1 [ V_38 ] >> V_51 ) & V_52 ;
V_32 |= V_36 << V_53 ;
V_36 = ( V_1 [ V_38 ] >> V_25 ) & V_26 ;
V_32 |= V_36 << V_54 ;
}
V_30 [ V_38 ] = V_5 - 1 ;
}
V_31 [ 0 ] = 0 ;
if ( V_37 & 2 )
V_31 [ 0 ] = V_55 ;
if ( V_37 & 0x7c )
V_31 [ 0 ] |= V_56 ;
V_31 [ 1 ] = V_33 ;
V_31 [ 2 ] = V_32 ;
return 0 ;
}
static int F_13 ( T_1 V_1 )
{
int V_38 , V_57 ;
for ( V_38 = 0 ; V_38 < F_14 ( V_58 ) ; ++ V_38 ) {
if ( V_1 < V_58 [ V_38 ] [ 0 ] )
break;
for ( V_57 = 0 ; V_57 < V_59 && V_58 [ V_38 ] [ V_57 ] ; ++ V_57 )
if ( V_1 == V_58 [ V_38 ] [ V_57 ] )
return V_38 ;
}
return - 1 ;
}
static int F_15 ( T_1 V_1 , unsigned int V_60 , T_1 V_61 [] )
{
int V_38 , V_57 , V_62 = 0 ;
T_1 V_63 ;
V_61 [ V_62 ++ ] = V_1 ;
V_38 = F_13 ( V_1 ) ;
if ( V_38 >= 0 ) {
for ( V_57 = 0 ; V_57 < V_59 ; ++ V_57 ) {
V_63 = V_58 [ V_38 ] [ V_57 ] ;
if ( V_63 && V_63 != V_1 )
V_61 [ V_62 ++ ] = V_63 ;
}
}
if ( V_60 & V_64 ) {
V_57 = V_62 ;
for ( V_38 = 0 ; V_38 < V_62 ; ++ V_38 ) {
switch ( V_61 [ V_38 ] ) {
case 0x1e :
V_61 [ V_57 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_61 [ V_57 ++ ] = 0x1e ;
break;
case 0x2 :
V_61 [ V_57 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_61 [ V_57 ++ ] = 0x2 ;
break;
}
}
V_62 = V_57 ;
}
return V_62 ;
}
static void F_16 ( unsigned int V_5 , unsigned long V_31 [] )
{
if ( V_5 <= 3 )
V_31 [ 1 ] &= ~ ( 0xffUL << F_12 ( V_5 + 1 ) ) ;
}
static T_1 F_17 ( T_1 V_65 )
{
T_1 V_66 = 0 ;
T_1 V_67 = V_65 & V_68 ;
if ( ( V_67 != 7 ) && ( V_67 != 0 ) )
return - 1 ;
if ( V_65 & V_69 )
return V_66 ;
if ( V_65 & V_70 )
return - 1 ;
if ( V_65 & V_71 )
return - 1 ;
if ( V_65 & V_72 ) {
V_66 |= V_73 ;
return V_66 ;
}
return - 1 ;
}
static void F_18 ( T_1 V_66 )
{
F_19 ( V_74 , ( F_20 ( V_74 ) | V_66 ) ) ;
}
static int T_2 F_21 ( void )
{
if ( ! V_75 -> V_76 ||
strcmp ( V_75 -> V_76 , L_1 ) )
return - V_77 ;
return F_22 ( & V_78 ) ;
}
