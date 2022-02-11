static inline bool F_1 ( T_1 V_1 )
{
V_1 &= 0xff0fe ;
return ( V_1 == 0x30056 || V_1 == 0x4f052 ) ;
}
static int F_2 ( T_1 V_1 , unsigned long * V_2 , unsigned long * V_3 )
{
unsigned int V_4 , V_5 , V_6 , V_7 ;
unsigned long V_8 , V_9 ;
V_8 = V_9 = 0 ;
if ( V_1 & ~ V_10 )
return - 1 ;
V_5 = ( V_1 >> V_11 ) & V_12 ;
V_4 = ( V_1 >> V_13 ) & V_14 ;
V_6 = ( V_1 >> V_15 ) & V_16 ;
V_7 = ( V_1 >> V_17 ) & V_18 ;
V_1 &= ~ ( V_18 << V_17 ) ;
if ( V_5 ) {
if ( V_5 > 6 )
return - 1 ;
V_8 |= F_3 ( V_5 ) ;
V_9 |= F_4 ( V_5 ) ;
if ( V_5 >= 5 && V_1 != 0x500fa && V_1 != 0x600f4 )
return - 1 ;
}
if ( V_5 <= 4 ) {
V_8 |= V_19 ;
V_9 |= V_20 ;
}
if ( V_4 >= 6 && V_4 <= 9 ) {
if ( V_6 )
return - 1 ;
} else if ( V_1 & V_21 ) {
V_8 |= V_22 ;
V_9 |= F_5 ( V_6 ) ;
}
if ( V_1 & V_23 ) {
V_8 |= V_24 ;
V_9 |= F_6 ( V_1 >> V_25 ) ;
}
if ( F_1 ( V_1 ) ) {
V_8 |= V_26 ;
V_9 |= F_7 ( V_1 >> V_27 ) ;
} else {
unsigned int V_28 , exp ;
V_28 = ( V_1 >> V_29 ) & V_30 ;
exp = V_28 >> 7 ;
if ( exp && ( V_28 & 0x60 ) == 0 )
return - 1 ;
V_8 |= V_31 ;
V_9 |= F_8 ( V_1 >> V_32 ) ;
}
if ( ! V_5 && V_7 )
return - 1 ;
V_8 |= F_9 ( V_7 ) ;
V_9 |= V_33 ;
* V_2 = V_8 ;
* V_3 = V_9 ;
return 0 ;
}
static int F_10 ( T_1 V_1 [] , int V_34 ,
unsigned int V_35 [] , unsigned long V_36 [] )
{
unsigned long V_37 , V_38 , V_4 , V_39 , V_40 , V_6 , V_41 ;
unsigned int V_5 , V_42 ;
int V_43 ;
V_42 = 0 ;
for ( V_43 = 0 ; V_43 < V_34 ; ++ V_43 ) {
V_5 = ( V_1 [ V_43 ] >> V_11 ) & V_12 ;
if ( V_5 )
V_42 |= 1 << V_5 ;
}
V_37 = V_44 ;
V_38 = 0 ;
for ( V_43 = 0 ; V_43 < V_34 ; ++ V_43 ) {
V_5 = ( V_1 [ V_43 ] >> V_11 ) & V_12 ;
V_4 = ( V_1 [ V_43 ] >> V_13 ) & V_14 ;
V_39 = ( V_1 [ V_43 ] >> V_45 ) & V_46 ;
V_40 = V_1 [ V_43 ] & V_47 ;
if ( ! V_5 ) {
for ( V_5 = 1 ; V_5 <= 4 ; ++ V_5 ) {
if ( ! ( V_42 & ( 1 << V_5 ) ) )
break;
}
V_42 |= 1 << V_5 ;
}
if ( V_5 <= 4 ) {
V_38 |= V_4 << F_11 ( V_5 ) ;
V_38 |= V_39 << F_12 ( V_5 ) ;
V_38 |= V_40 << F_13 ( V_5 ) ;
}
if ( V_1 [ V_43 ] & V_21 ) {
V_6 = V_1 [ V_43 ] >> V_15 ;
V_38 |= ( V_6 & 1 ) << V_48 ;
V_6 >>= 1 ;
V_38 |= ( V_6 & 1 ) << V_49 ;
}
if ( V_1 [ V_43 ] & V_23 ) {
V_37 |= V_50 ;
V_41 = ( V_1 [ V_43 ] >> V_25 ) & V_51 ;
if ( V_41 ) {
V_37 |= ( V_41 & 3 ) << V_52 ;
V_37 |= ( V_41 >> 2 ) << V_53 ;
}
}
if ( F_1 ( V_1 [ V_43 ] ) ) {
V_38 |= ( V_1 [ V_43 ] >> V_27 ) &
V_54 ;
} else {
V_41 = ( V_1 [ V_43 ] >> V_27 ) & V_54 ;
V_37 |= V_41 << V_55 ;
V_41 = ( V_1 [ V_43 ] >> V_56 ) & V_57 ;
V_37 |= V_41 << V_58 ;
V_41 = ( V_1 [ V_43 ] >> V_29 ) & V_30 ;
V_37 |= V_41 << V_59 ;
}
V_35 [ V_43 ] = V_5 - 1 ;
}
V_36 [ 0 ] = 0 ;
if ( V_42 & 2 )
V_36 [ 0 ] = V_60 ;
if ( V_42 & 0x7c )
V_36 [ 0 ] |= V_61 ;
if ( ! ( V_42 & 0x60 ) )
V_36 [ 0 ] |= V_62 ;
V_36 [ 1 ] = V_38 ;
V_36 [ 2 ] = V_37 ;
return 0 ;
}
static int F_14 ( T_1 V_1 )
{
int V_43 , V_63 ;
for ( V_43 = 0 ; V_43 < F_15 ( V_64 ) ; ++ V_43 ) {
if ( V_1 < V_64 [ V_43 ] [ 0 ] )
break;
for ( V_63 = 0 ; V_63 < V_65 && V_64 [ V_43 ] [ V_63 ] ; ++ V_63 )
if ( V_1 == V_64 [ V_43 ] [ V_63 ] )
return V_43 ;
}
return - 1 ;
}
static int F_16 ( T_1 V_1 , unsigned int V_66 , T_1 V_67 [] )
{
int V_43 , V_63 , V_68 = 0 ;
T_1 V_69 ;
V_67 [ V_68 ++ ] = V_1 ;
V_43 = F_14 ( V_1 ) ;
if ( V_43 >= 0 ) {
for ( V_63 = 0 ; V_63 < V_65 ; ++ V_63 ) {
V_69 = V_64 [ V_43 ] [ V_63 ] ;
if ( V_69 && V_69 != V_1 )
V_67 [ V_68 ++ ] = V_69 ;
}
}
if ( V_66 & V_70 ) {
V_63 = V_68 ;
for ( V_43 = 0 ; V_43 < V_68 ; ++ V_43 ) {
switch ( V_67 [ V_43 ] ) {
case 0x1e :
V_67 [ V_63 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_67 [ V_63 ++ ] = 0x1e ;
break;
case 0x2 :
V_67 [ V_63 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_67 [ V_63 ++ ] = 0x2 ;
break;
}
}
V_68 = V_63 ;
}
return V_68 ;
}
static void F_17 ( unsigned int V_5 , unsigned long V_36 [] )
{
if ( V_5 <= 3 )
V_36 [ 1 ] &= ~ ( 0xffUL << F_13 ( V_5 + 1 ) ) ;
}
static T_1 F_18 ( T_1 V_71 )
{
T_1 V_72 = 0 ;
if ( V_71 & V_73 )
return V_72 ;
if ( V_71 & V_74 )
return - 1 ;
if ( V_71 & V_75 )
return - 1 ;
if ( V_71 & V_76 ) {
V_72 |= V_77 ;
return V_72 ;
}
return - 1 ;
}
static void F_19 ( T_1 V_72 )
{
F_20 ( V_78 , ( F_21 ( V_78 ) | V_72 ) ) ;
}
static int T_2 F_22 ( void )
{
int V_79 ;
if ( ! V_80 -> V_81 ||
strcmp ( V_80 -> V_81 , L_1 ) )
return - V_82 ;
V_79 = F_23 ( & V_83 ) ;
if ( V_79 )
return V_79 ;
V_80 -> V_84 |= V_85 ;
return 0 ;
}
