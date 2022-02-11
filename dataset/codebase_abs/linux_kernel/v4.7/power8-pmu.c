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
if ( V_5 >= 5 && V_19 != V_21 &&
V_19 != V_22 )
return - 1 ;
V_8 |= F_3 ( V_5 ) ;
V_9 |= F_4 ( V_5 ) ;
}
if ( V_5 <= 4 ) {
V_8 |= V_23 ;
V_9 |= V_24 ;
}
if ( V_4 >= 6 && V_4 <= 9 ) {
if ( V_6 & 0x7 )
return - 1 ;
} else if ( V_1 & V_25 ) {
V_8 |= V_26 ;
V_9 |= F_5 ( V_6 ) ;
}
if ( V_1 & V_27 ) {
V_8 |= V_28 ;
V_9 |= F_6 ( V_1 >> V_29 ) ;
}
if ( F_1 ( V_1 ) ) {
V_8 |= V_30 ;
V_9 |= F_7 ( V_1 >> V_31 ) ;
} else {
unsigned int V_32 , exp ;
V_32 = ( V_1 >> V_33 ) & V_34 ;
exp = V_32 >> 7 ;
if ( exp && ( V_32 & 0x60 ) == 0 )
return - 1 ;
V_8 |= V_35 ;
V_9 |= F_8 ( V_1 >> V_36 ) ;
}
if ( ! V_5 && V_7 )
return - 1 ;
if ( V_1 & V_37 ) {
if ( ! V_7 )
return - 1 ;
V_8 |= V_38 ;
V_9 |= F_9 ( V_1 >> V_39 ) ;
}
V_8 |= F_10 ( V_7 ) ;
V_9 |= V_40 ;
* V_2 = V_8 ;
* V_3 = V_9 ;
return 0 ;
}
static int F_11 ( T_1 V_1 [] , int V_41 ,
unsigned int V_42 [] , unsigned long V_43 [] ,
struct V_44 * V_45 [] )
{
unsigned long V_46 , V_47 , V_48 , V_4 , V_49 , V_50 , V_6 , V_51 ;
unsigned int V_5 , V_52 ;
int V_53 ;
V_52 = 0 ;
for ( V_53 = 0 ; V_53 < V_41 ; ++ V_53 ) {
V_5 = ( V_1 [ V_53 ] >> V_11 ) & V_12 ;
if ( V_5 )
V_52 |= 1 << V_5 ;
}
V_46 = V_54 ;
V_47 = V_48 = 0 ;
for ( V_53 = 0 ; V_53 < V_41 ; ++ V_53 ) {
V_5 = ( V_1 [ V_53 ] >> V_11 ) & V_12 ;
V_4 = ( V_1 [ V_53 ] >> V_13 ) & V_14 ;
V_49 = ( V_1 [ V_53 ] >> V_55 ) & V_56 ;
V_50 = V_1 [ V_53 ] & V_57 ;
if ( ! V_5 ) {
for ( V_5 = 1 ; V_5 <= 4 ; ++ V_5 ) {
if ( ! ( V_52 & ( 1 << V_5 ) ) )
break;
}
V_52 |= 1 << V_5 ;
}
if ( V_5 <= 4 ) {
V_47 |= V_4 << F_12 ( V_5 ) ;
V_47 |= V_49 << F_13 ( V_5 ) ;
V_47 |= V_50 << F_14 ( V_5 ) ;
}
if ( V_1 [ V_53 ] & V_25 ) {
V_6 = V_1 [ V_53 ] >> V_15 ;
V_47 |= ( V_6 & 1 ) << V_58 ;
V_6 >>= 1 ;
V_47 |= ( V_6 & 1 ) << V_59 ;
}
if ( V_1 [ V_53 ] & V_27 ) {
V_46 |= V_60 ;
V_51 = ( V_1 [ V_53 ] >> V_29 ) & V_61 ;
if ( V_51 ) {
V_46 |= ( V_51 & 3 ) << V_62 ;
V_46 |= ( V_51 >> 2 ) << V_63 ;
}
}
if ( F_1 ( V_1 [ V_53 ] ) ) {
V_47 |= ( ( V_1 [ V_53 ] >> V_31 ) &
V_64 ) << V_65 ;
} else {
V_51 = ( V_1 [ V_53 ] >> V_31 ) & V_64 ;
V_46 |= V_51 << V_66 ;
V_51 = ( V_1 [ V_53 ] >> V_67 ) & V_68 ;
V_46 |= V_51 << V_69 ;
V_51 = ( V_1 [ V_53 ] >> V_33 ) & V_34 ;
V_46 |= V_51 << V_70 ;
}
if ( V_1 [ V_53 ] & V_37 ) {
V_51 = ( V_1 [ V_53 ] >> V_39 ) & V_71 ;
V_46 |= V_51 << V_72 ;
}
if ( V_45 [ V_53 ] -> V_73 . V_74 )
V_48 |= F_15 ( V_5 ) ;
if ( V_45 [ V_53 ] -> V_73 . V_75 )
V_48 |= F_16 ( V_5 ) ;
if ( V_45 [ V_53 ] -> V_73 . V_76 ) {
if ( F_17 ( V_77 ) )
V_48 |= F_16 ( V_5 ) ;
else
V_48 |= F_18 ( V_5 ) ;
}
V_42 [ V_53 ] = V_5 - 1 ;
}
V_43 [ 0 ] = 0 ;
if ( V_52 & 2 )
V_43 [ 0 ] = V_78 ;
if ( V_52 & 0x7c )
V_43 [ 0 ] |= V_79 ;
if ( ! ( V_52 & 0x60 ) )
V_43 [ 0 ] |= V_80 ;
V_43 [ 1 ] = V_47 ;
V_43 [ 2 ] = V_46 ;
V_43 [ 3 ] = V_48 ;
return 0 ;
}
static int F_19 ( T_1 V_1 )
{
int V_53 , V_81 ;
for ( V_53 = 0 ; V_53 < F_20 ( V_82 ) ; ++ V_53 ) {
if ( V_1 < V_82 [ V_53 ] [ 0 ] )
break;
for ( V_81 = 0 ; V_81 < V_83 && V_82 [ V_53 ] [ V_81 ] ; ++ V_81 )
if ( V_1 == V_82 [ V_53 ] [ V_81 ] )
return V_53 ;
}
return - 1 ;
}
static int F_21 ( T_1 V_1 , unsigned int V_84 , T_1 V_85 [] )
{
int V_53 , V_81 , V_86 = 0 ;
T_1 V_87 ;
V_85 [ V_86 ++ ] = V_1 ;
V_53 = F_19 ( V_1 ) ;
if ( V_53 >= 0 ) {
for ( V_81 = 0 ; V_81 < V_83 ; ++ V_81 ) {
V_87 = V_82 [ V_53 ] [ V_81 ] ;
if ( V_87 && V_87 != V_1 )
V_85 [ V_86 ++ ] = V_87 ;
}
}
if ( V_84 & V_88 ) {
V_81 = V_86 ;
for ( V_53 = 0 ; V_53 < V_86 ; ++ V_53 ) {
switch ( V_85 [ V_53 ] ) {
case V_89 :
V_85 [ V_81 ++ ] = V_22 ;
break;
case V_22 :
V_85 [ V_81 ++ ] = V_89 ;
break;
case V_90 :
V_85 [ V_81 ++ ] = V_21 ;
break;
case V_21 :
V_85 [ V_81 ++ ] = V_90 ;
break;
}
}
V_86 = V_81 ;
}
return V_86 ;
}
static void F_22 ( unsigned int V_5 , unsigned long V_43 [] )
{
if ( V_5 <= 3 )
V_43 [ 1 ] &= ~ ( 0xffUL << F_14 ( V_5 + 1 ) ) ;
}
static T_1 F_23 ( T_1 V_91 )
{
T_1 V_92 = 0 ;
if ( V_91 & V_93 )
return V_92 ;
if ( V_91 & V_94 )
return - 1 ;
if ( V_91 & V_95 )
return - 1 ;
if ( V_91 & V_96 )
return - 1 ;
if ( V_91 & V_97 ) {
V_92 |= V_98 ;
return V_92 ;
}
return - 1 ;
}
static void F_24 ( T_1 V_92 )
{
F_25 ( V_99 , ( F_26 ( V_99 ) | V_92 ) ) ;
}
static int T_2 F_27 ( void )
{
int V_100 ;
if ( ! V_101 -> V_102 ||
strcmp ( V_101 -> V_102 , L_1 ) )
return - V_103 ;
V_100 = F_28 ( & V_104 ) ;
if ( V_100 )
return V_100 ;
V_101 -> V_105 |= V_106 ;
if ( F_17 ( V_107 ) )
F_29 ( L_2 ) ;
return 0 ;
}
