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
if ( V_5 ) {
T_1 V_19 ;
if ( V_5 > 6 )
return - 1 ;
V_19 = V_1 & ~ V_20 ;
if ( V_5 >= 5 && V_19 != 0x500fa && V_19 != 0x600f4 )
return - 1 ;
V_8 |= F_3 ( V_5 ) ;
V_9 |= F_4 ( V_5 ) ;
}
if ( V_5 <= 4 ) {
V_8 |= V_21 ;
V_9 |= V_22 ;
}
if ( V_4 >= 6 && V_4 <= 9 ) {
if ( V_6 & 0x7 )
return - 1 ;
} else if ( V_1 & V_23 ) {
V_8 |= V_24 ;
V_9 |= F_5 ( V_6 ) ;
}
if ( V_1 & V_25 ) {
V_8 |= V_26 ;
V_9 |= F_6 ( V_1 >> V_27 ) ;
}
if ( F_1 ( V_1 ) ) {
V_8 |= V_28 ;
V_9 |= F_7 ( V_1 >> V_29 ) ;
} else {
unsigned int V_30 , exp ;
V_30 = ( V_1 >> V_31 ) & V_32 ;
exp = V_30 >> 7 ;
if ( exp && ( V_30 & 0x60 ) == 0 )
return - 1 ;
V_8 |= V_33 ;
V_9 |= F_8 ( V_1 >> V_34 ) ;
}
if ( ! V_5 && V_7 )
return - 1 ;
if ( V_1 & V_35 ) {
if ( ! V_7 )
return - 1 ;
V_8 |= V_36 ;
V_9 |= F_9 ( V_1 >> V_37 ) ;
}
V_8 |= F_10 ( V_7 ) ;
V_9 |= V_38 ;
* V_2 = V_8 ;
* V_3 = V_9 ;
return 0 ;
}
static int F_11 ( T_1 V_1 [] , int V_39 ,
unsigned int V_40 [] , unsigned long V_41 [] )
{
unsigned long V_42 , V_43 , V_4 , V_44 , V_45 , V_6 , V_46 ;
unsigned int V_5 , V_47 ;
int V_48 ;
V_47 = 0 ;
for ( V_48 = 0 ; V_48 < V_39 ; ++ V_48 ) {
V_5 = ( V_1 [ V_48 ] >> V_11 ) & V_12 ;
if ( V_5 )
V_47 |= 1 << V_5 ;
}
V_42 = V_49 ;
V_43 = 0 ;
for ( V_48 = 0 ; V_48 < V_39 ; ++ V_48 ) {
V_5 = ( V_1 [ V_48 ] >> V_11 ) & V_12 ;
V_4 = ( V_1 [ V_48 ] >> V_13 ) & V_14 ;
V_44 = ( V_1 [ V_48 ] >> V_50 ) & V_51 ;
V_45 = V_1 [ V_48 ] & V_52 ;
if ( ! V_5 ) {
for ( V_5 = 1 ; V_5 <= 4 ; ++ V_5 ) {
if ( ! ( V_47 & ( 1 << V_5 ) ) )
break;
}
V_47 |= 1 << V_5 ;
}
if ( V_5 <= 4 ) {
V_43 |= V_4 << F_12 ( V_5 ) ;
V_43 |= V_44 << F_13 ( V_5 ) ;
V_43 |= V_45 << F_14 ( V_5 ) ;
}
if ( V_1 [ V_48 ] & V_23 ) {
V_6 = V_1 [ V_48 ] >> V_15 ;
V_43 |= ( V_6 & 1 ) << V_53 ;
V_6 >>= 1 ;
V_43 |= ( V_6 & 1 ) << V_54 ;
}
if ( V_1 [ V_48 ] & V_25 ) {
V_42 |= V_55 ;
V_46 = ( V_1 [ V_48 ] >> V_27 ) & V_56 ;
if ( V_46 ) {
V_42 |= ( V_46 & 3 ) << V_57 ;
V_42 |= ( V_46 >> 2 ) << V_58 ;
}
}
if ( F_1 ( V_1 [ V_48 ] ) ) {
V_43 |= ( ( V_1 [ V_48 ] >> V_29 ) &
V_59 ) << V_60 ;
} else {
V_46 = ( V_1 [ V_48 ] >> V_29 ) & V_59 ;
V_42 |= V_46 << V_61 ;
V_46 = ( V_1 [ V_48 ] >> V_62 ) & V_63 ;
V_42 |= V_46 << V_64 ;
V_46 = ( V_1 [ V_48 ] >> V_31 ) & V_32 ;
V_42 |= V_46 << V_65 ;
}
if ( V_1 [ V_48 ] & V_35 ) {
V_46 = ( V_1 [ V_48 ] >> V_37 ) & V_66 ;
V_42 |= V_46 << V_67 ;
}
V_40 [ V_48 ] = V_5 - 1 ;
}
V_41 [ 0 ] = 0 ;
if ( V_47 & 2 )
V_41 [ 0 ] = V_68 ;
if ( V_47 & 0x7c )
V_41 [ 0 ] |= V_69 ;
if ( ! ( V_47 & 0x60 ) )
V_41 [ 0 ] |= V_70 ;
V_41 [ 1 ] = V_43 ;
V_41 [ 2 ] = V_42 ;
return 0 ;
}
static int F_15 ( T_1 V_1 )
{
int V_48 , V_71 ;
for ( V_48 = 0 ; V_48 < F_16 ( V_72 ) ; ++ V_48 ) {
if ( V_1 < V_72 [ V_48 ] [ 0 ] )
break;
for ( V_71 = 0 ; V_71 < V_73 && V_72 [ V_48 ] [ V_71 ] ; ++ V_71 )
if ( V_1 == V_72 [ V_48 ] [ V_71 ] )
return V_48 ;
}
return - 1 ;
}
static int F_17 ( T_1 V_1 , unsigned int V_74 , T_1 V_75 [] )
{
int V_48 , V_71 , V_76 = 0 ;
T_1 V_77 ;
V_75 [ V_76 ++ ] = V_1 ;
V_48 = F_15 ( V_1 ) ;
if ( V_48 >= 0 ) {
for ( V_71 = 0 ; V_71 < V_73 ; ++ V_71 ) {
V_77 = V_72 [ V_48 ] [ V_71 ] ;
if ( V_77 && V_77 != V_1 )
V_75 [ V_76 ++ ] = V_77 ;
}
}
if ( V_74 & V_78 ) {
V_71 = V_76 ;
for ( V_48 = 0 ; V_48 < V_76 ; ++ V_48 ) {
switch ( V_75 [ V_48 ] ) {
case 0x1e :
V_75 [ V_71 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_75 [ V_71 ++ ] = 0x1e ;
break;
case 0x2 :
V_75 [ V_71 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_75 [ V_71 ++ ] = 0x2 ;
break;
}
}
V_76 = V_71 ;
}
return V_76 ;
}
static void F_18 ( unsigned int V_5 , unsigned long V_41 [] )
{
if ( V_5 <= 3 )
V_41 [ 1 ] &= ~ ( 0xffUL << F_14 ( V_5 + 1 ) ) ;
}
static T_1 F_19 ( T_1 V_79 )
{
T_1 V_80 = 0 ;
if ( V_79 & V_81 )
return V_80 ;
if ( V_79 & V_82 )
return - 1 ;
if ( V_79 & V_83 )
return - 1 ;
if ( V_79 & V_84 ) {
V_80 |= V_85 ;
return V_80 ;
}
return - 1 ;
}
static void F_20 ( T_1 V_80 )
{
F_21 ( V_86 , ( F_22 ( V_86 ) | V_80 ) ) ;
}
static int T_2 F_23 ( void )
{
int V_87 ;
if ( ! V_88 -> V_89 ||
strcmp ( V_88 -> V_89 , L_1 ) )
return - V_90 ;
V_87 = F_24 ( & V_91 ) ;
if ( V_87 )
return V_87 ;
V_88 -> V_92 |= V_93 ;
if ( F_25 ( V_94 ) )
F_26 ( L_2 ) ;
return 0 ;
}
