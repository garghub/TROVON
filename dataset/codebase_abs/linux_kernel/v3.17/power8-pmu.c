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
unsigned int V_40 [] , unsigned long V_41 [] ,
struct V_42 * V_43 [] )
{
unsigned long V_44 , V_45 , V_46 , V_4 , V_47 , V_48 , V_6 , V_49 ;
unsigned int V_5 , V_50 ;
int V_51 ;
V_50 = 0 ;
for ( V_51 = 0 ; V_51 < V_39 ; ++ V_51 ) {
V_5 = ( V_1 [ V_51 ] >> V_11 ) & V_12 ;
if ( V_5 )
V_50 |= 1 << V_5 ;
}
V_44 = V_52 ;
V_45 = V_46 = 0 ;
for ( V_51 = 0 ; V_51 < V_39 ; ++ V_51 ) {
V_5 = ( V_1 [ V_51 ] >> V_11 ) & V_12 ;
V_4 = ( V_1 [ V_51 ] >> V_13 ) & V_14 ;
V_47 = ( V_1 [ V_51 ] >> V_53 ) & V_54 ;
V_48 = V_1 [ V_51 ] & V_55 ;
if ( ! V_5 ) {
for ( V_5 = 1 ; V_5 <= 4 ; ++ V_5 ) {
if ( ! ( V_50 & ( 1 << V_5 ) ) )
break;
}
V_50 |= 1 << V_5 ;
}
if ( V_5 <= 4 ) {
V_45 |= V_4 << F_12 ( V_5 ) ;
V_45 |= V_47 << F_13 ( V_5 ) ;
V_45 |= V_48 << F_14 ( V_5 ) ;
}
if ( V_1 [ V_51 ] & V_23 ) {
V_6 = V_1 [ V_51 ] >> V_15 ;
V_45 |= ( V_6 & 1 ) << V_56 ;
V_6 >>= 1 ;
V_45 |= ( V_6 & 1 ) << V_57 ;
}
if ( V_1 [ V_51 ] & V_25 ) {
V_44 |= V_58 ;
V_49 = ( V_1 [ V_51 ] >> V_27 ) & V_59 ;
if ( V_49 ) {
V_44 |= ( V_49 & 3 ) << V_60 ;
V_44 |= ( V_49 >> 2 ) << V_61 ;
}
}
if ( F_1 ( V_1 [ V_51 ] ) ) {
V_45 |= ( ( V_1 [ V_51 ] >> V_29 ) &
V_62 ) << V_63 ;
} else {
V_49 = ( V_1 [ V_51 ] >> V_29 ) & V_62 ;
V_44 |= V_49 << V_64 ;
V_49 = ( V_1 [ V_51 ] >> V_65 ) & V_66 ;
V_44 |= V_49 << V_67 ;
V_49 = ( V_1 [ V_51 ] >> V_31 ) & V_32 ;
V_44 |= V_49 << V_68 ;
}
if ( V_1 [ V_51 ] & V_35 ) {
V_49 = ( V_1 [ V_51 ] >> V_37 ) & V_69 ;
V_44 |= V_49 << V_70 ;
}
if ( V_43 [ V_51 ] -> V_71 . V_72 )
V_46 |= F_15 ( V_5 ) ;
if ( V_43 [ V_51 ] -> V_71 . V_73 )
V_46 |= F_16 ( V_5 ) ;
if ( V_43 [ V_51 ] -> V_71 . V_74 ) {
if ( F_17 ( V_75 ) )
V_46 |= F_16 ( V_5 ) ;
else
V_46 |= F_18 ( V_5 ) ;
}
V_40 [ V_51 ] = V_5 - 1 ;
}
V_41 [ 0 ] = 0 ;
if ( V_50 & 2 )
V_41 [ 0 ] = V_76 ;
if ( V_50 & 0x7c )
V_41 [ 0 ] |= V_77 ;
if ( ! ( V_50 & 0x60 ) )
V_41 [ 0 ] |= V_78 ;
V_41 [ 1 ] = V_45 ;
V_41 [ 2 ] = V_44 ;
V_41 [ 3 ] = V_46 ;
return 0 ;
}
static int F_19 ( T_1 V_1 )
{
int V_51 , V_79 ;
for ( V_51 = 0 ; V_51 < F_20 ( V_80 ) ; ++ V_51 ) {
if ( V_1 < V_80 [ V_51 ] [ 0 ] )
break;
for ( V_79 = 0 ; V_79 < V_81 && V_80 [ V_51 ] [ V_79 ] ; ++ V_79 )
if ( V_1 == V_80 [ V_51 ] [ V_79 ] )
return V_51 ;
}
return - 1 ;
}
static int F_21 ( T_1 V_1 , unsigned int V_82 , T_1 V_83 [] )
{
int V_51 , V_79 , V_84 = 0 ;
T_1 V_85 ;
V_83 [ V_84 ++ ] = V_1 ;
V_51 = F_19 ( V_1 ) ;
if ( V_51 >= 0 ) {
for ( V_79 = 0 ; V_79 < V_81 ; ++ V_79 ) {
V_85 = V_80 [ V_51 ] [ V_79 ] ;
if ( V_85 && V_85 != V_1 )
V_83 [ V_84 ++ ] = V_85 ;
}
}
if ( V_82 & V_86 ) {
V_79 = V_84 ;
for ( V_51 = 0 ; V_51 < V_84 ; ++ V_51 ) {
switch ( V_83 [ V_51 ] ) {
case 0x1e :
V_83 [ V_79 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_83 [ V_79 ++ ] = 0x1e ;
break;
case 0x2 :
V_83 [ V_79 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_83 [ V_79 ++ ] = 0x2 ;
break;
}
}
V_84 = V_79 ;
}
return V_84 ;
}
static void F_22 ( unsigned int V_5 , unsigned long V_41 [] )
{
if ( V_5 <= 3 )
V_41 [ 1 ] &= ~ ( 0xffUL << F_14 ( V_5 + 1 ) ) ;
}
static T_1 F_23 ( T_1 V_87 )
{
T_1 V_88 = 0 ;
if ( V_87 & V_89 )
return V_88 ;
if ( V_87 & V_90 )
return - 1 ;
if ( V_87 & V_91 )
return - 1 ;
if ( V_87 & V_92 ) {
V_88 |= V_93 ;
return V_88 ;
}
return - 1 ;
}
static void F_24 ( T_1 V_88 )
{
F_25 ( V_94 , ( F_26 ( V_94 ) | V_88 ) ) ;
}
static int T_2 F_27 ( void )
{
int V_95 ;
if ( ! V_96 -> V_97 ||
strcmp ( V_96 -> V_97 , L_1 ) )
return - V_98 ;
V_95 = F_28 ( & V_99 ) ;
if ( V_95 )
return V_95 ;
V_96 -> V_100 |= V_101 ;
if ( F_17 ( V_102 ) )
F_29 ( L_2 ) ;
return 0 ;
}
