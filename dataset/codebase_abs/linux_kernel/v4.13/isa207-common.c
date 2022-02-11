static inline bool F_1 ( T_1 V_1 )
{
V_1 &= 0xff0fe ;
return ( V_1 == 0x30056 || V_1 == 0x4f052 ) ;
}
static bool F_2 ( T_1 V_1 )
{
T_1 V_2 = V_3 ;
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
V_2 = V_6 ;
return ! ( V_1 & ~ V_2 ) ;
}
static inline bool F_4 ( T_1 V_1 )
{
if ( V_1 & V_7 )
return true ;
return false ;
}
static void F_5 ( T_1 V_1 , unsigned long * V_8 )
{
if ( F_3 ( V_4 ) ) {
if ( F_4 ( V_1 ) || ( * V_8 & V_9 ) )
* V_8 &= V_10 ;
else if ( ! F_3 ( V_5 ) && F_6 ( V_1 ) )
* V_8 |= F_6 ( V_1 ) << V_11 ;
else
* V_8 |= V_12 ;
} else
* V_8 |= V_12 ;
}
static T_1 F_7 ( T_1 V_13 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return V_13 << V_14 ;
return V_13 << V_15 ;
}
static unsigned long F_8 ( T_1 V_1 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_9 ( V_1 ) ;
return F_10 ( V_1 ) ;
}
static unsigned long F_11 ( unsigned long V_16 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_12 ( V_16 ) ;
return F_13 ( V_16 ) ;
}
static inline bool F_14 ( T_1 V_1 )
{
return ( V_1 >> V_17 ) & V_18 ;
}
static bool F_15 ( T_1 V_1 )
{
unsigned int V_19 , exp ;
V_19 = ( V_1 >> V_20 ) & V_21 ;
exp = V_19 >> 7 ;
if ( exp && ( V_19 & 0x60 ) == 0 )
return false ;
return true ;
}
static inline T_1 F_16 ( T_1 V_22 , T_2 V_23 )
{
T_1 V_24 = V_25 ;
switch( V_22 ) {
case 0 :
break;
case 1 :
V_24 = F_17 ( V_26 , V_27 ) ;
break;
case 2 :
V_24 = F_17 ( V_26 , V_28 ) ;
break;
case 3 :
V_24 = F_17 ( V_26 , V_29 ) ;
break;
case 4 :
if ( V_23 <= 1 )
V_24 = F_17 ( V_26 , V_30 ) ;
else if ( V_23 > 1 && V_23 <= 2 )
V_24 = F_17 ( V_26 , V_31 ) ;
else
V_24 = F_17 ( V_26 , V_32 ) ;
V_24 |= F_18 ( V_33 , V_34 ) ;
break;
case 5 :
V_24 = F_17 ( V_26 , V_35 ) ;
if ( ( V_23 == 0 ) || ( V_23 == 2 ) || ( V_23 == 4 ) )
V_24 |= F_18 ( V_33 , V_34 ) ;
else if ( ( V_23 == 1 ) || ( V_23 == 3 ) || ( V_23 == 5 ) )
V_24 |= F_18 ( V_33 , V_36 ) ;
break;
case 6 :
V_24 = F_17 ( V_26 , V_37 ) ;
if ( ( V_23 == 0 ) || ( V_23 == 2 ) )
V_24 |= F_18 ( V_33 , V_34 ) ;
else if ( ( V_23 == 1 ) || ( V_23 == 3 ) )
V_24 |= F_18 ( V_33 , V_36 ) ;
break;
case 7 :
V_24 = F_19 ( V_26 , V_27 ) ;
break;
}
return V_24 ;
}
void F_20 ( union V_38 * V_39 , T_2 V_40 ,
struct V_41 * V_42 )
{
T_1 V_22 ;
T_2 V_23 ;
T_1 V_43 ;
T_1 V_44 ;
if ( ! ( V_40 & V_45 ) ) {
V_39 -> V_44 = 0 ;
return;
}
V_43 = F_21 ( V_46 ) ;
V_44 = ( V_43 & V_47 ) >> V_48 ;
if ( V_44 == 1 || V_44 == 2 ) {
V_22 = ( V_43 & V_49 ) >> V_50 ;
V_23 = ( V_43 & V_51 ) >> V_52 ;
V_39 -> V_44 = F_16 ( V_22 , V_23 ) ;
V_39 -> V_44 |= ( V_44 == 1 ) ? F_18 ( V_53 , V_54 ) : F_18 ( V_53 , V_55 ) ;
}
}
void F_22 ( T_1 * V_56 )
{
T_1 V_8 = F_21 ( V_57 ) ;
T_1 exp = F_23 ( V_8 ) ;
T_1 V_58 = F_24 ( V_8 ) ;
* V_56 = V_58 << ( 2 * exp ) ;
}
int F_25 ( T_1 V_1 , unsigned long * V_59 , unsigned long * V_60 )
{
unsigned int V_61 , V_16 , V_62 , V_63 ;
unsigned long V_64 , V_13 ;
V_64 = V_13 = 0 ;
if ( ! F_2 ( V_1 ) )
return - 1 ;
V_16 = ( V_1 >> V_65 ) & V_66 ;
V_61 = ( V_1 >> V_67 ) & V_68 ;
V_62 = ( V_1 >> V_69 ) & V_70 ;
V_63 = ( V_1 >> V_71 ) & V_72 ;
if ( V_16 ) {
T_1 V_73 ;
if ( V_16 > 6 )
return - 1 ;
V_73 = V_1 & ~ V_74 ;
if ( V_16 >= 5 && V_73 != 0x500fa &&
V_73 != 0x600f4 )
return - 1 ;
V_64 |= F_26 ( V_16 ) ;
V_13 |= F_27 ( V_16 ) ;
}
if ( V_16 <= 4 ) {
V_64 |= V_75 ;
V_13 |= V_76 ;
}
if ( V_61 >= 6 && V_61 <= 9 ) {
if ( V_62 & 0x7 )
return - 1 ;
} else if ( V_1 & V_77 ) {
V_64 |= V_78 ;
V_13 |= F_28 ( V_62 ) ;
}
if ( F_4 ( V_1 ) ) {
V_64 |= V_79 ;
V_13 |= F_29 ( V_1 >> V_80 ) ;
}
if ( F_3 ( V_4 ) ) {
if ( F_14 ( V_1 ) && F_15 ( V_1 ) ) {
V_64 |= V_81 ;
V_13 |= F_30 ( V_1 >> V_82 ) ;
}
} else {
if ( F_1 ( V_1 ) ) {
V_64 |= V_83 ;
V_13 |= F_31 ( V_1 >> V_84 ) ;
} else {
if ( ! F_15 ( V_1 ) )
return - 1 ;
V_64 |= V_81 ;
V_13 |= F_30 ( V_1 >> V_82 ) ;
}
}
if ( ! V_16 && V_63 )
return - 1 ;
if ( V_1 & V_85 ) {
if ( ! V_63 )
return - 1 ;
V_64 |= V_86 ;
V_13 |= F_32 ( V_1 >> V_87 ) ;
}
V_64 |= F_33 ( V_63 ) ;
V_13 |= V_88 ;
* V_59 = V_64 ;
* V_60 = V_13 ;
return 0 ;
}
int F_34 ( T_1 V_1 [] , int V_89 ,
unsigned int V_90 [] , unsigned long V_91 [] ,
struct V_92 * V_93 [] )
{
unsigned long V_8 , V_94 , V_95 , V_61 , V_96 , V_97 , V_62 , V_44 ;
unsigned int V_16 , V_98 ;
int V_99 ;
V_98 = 0 ;
for ( V_99 = 0 ; V_99 < V_89 ; ++ V_99 ) {
V_16 = ( V_1 [ V_99 ] >> V_65 ) & V_66 ;
if ( V_16 )
V_98 |= 1 << V_16 ;
}
V_8 = V_94 = V_95 = 0 ;
for ( V_99 = 0 ; V_99 < V_89 ; ++ V_99 ) {
V_16 = ( V_1 [ V_99 ] >> V_65 ) & V_66 ;
V_61 = ( V_1 [ V_99 ] >> V_67 ) & V_68 ;
V_96 = F_8 ( V_1 [ V_99 ] ) ;
V_97 = V_1 [ V_99 ] & V_100 ;
if ( ! V_16 ) {
for ( V_16 = 1 ; V_16 <= 4 ; ++ V_16 ) {
if ( ! ( V_98 & ( 1 << V_16 ) ) )
break;
}
V_98 |= 1 << V_16 ;
}
if ( V_16 <= 4 ) {
V_94 |= V_61 << F_35 ( V_16 ) ;
V_94 |= V_96 << F_11 ( V_16 ) ;
V_94 |= V_97 << F_36 ( V_16 ) ;
}
F_5 ( V_1 [ V_99 ] , & V_8 ) ;
if ( V_1 [ V_99 ] & V_77 ) {
V_62 = V_1 [ V_99 ] >> V_69 ;
V_94 |= ( V_62 & 1 ) << V_101 ;
V_62 >>= 1 ;
V_94 |= ( V_62 & 1 ) << V_102 ;
}
if ( F_4 ( V_1 [ V_99 ] ) ) {
V_8 |= V_9 ;
V_44 = ( V_1 [ V_99 ] >> V_80 ) & V_103 ;
if ( V_44 ) {
V_8 |= ( V_44 & 3 ) << V_104 ;
V_8 |= ( V_44 >> 2 ) << V_105 ;
}
}
if ( ! F_3 ( V_4 ) && F_1 ( V_1 [ V_99 ] ) ) {
V_94 |= ( ( V_1 [ V_99 ] >> V_84 ) &
V_106 ) << V_107 ;
} else {
V_44 = ( V_1 [ V_99 ] >> V_84 ) & V_106 ;
V_8 |= V_44 << V_108 ;
V_44 = ( V_1 [ V_99 ] >> V_17 ) & V_18 ;
V_8 |= V_44 << V_109 ;
V_44 = ( V_1 [ V_99 ] >> V_20 ) & V_21 ;
V_8 |= F_7 ( V_44 ) ;
}
if ( V_1 [ V_99 ] & V_85 ) {
V_44 = ( V_1 [ V_99 ] >> V_87 ) & V_110 ;
V_8 |= V_44 << V_111 ;
}
if ( V_93 [ V_99 ] -> V_112 . V_113 )
V_95 |= F_37 ( V_16 ) ;
if ( V_93 [ V_99 ] -> V_112 . V_114 )
V_95 |= F_38 ( V_16 ) ;
if ( V_93 [ V_99 ] -> V_112 . V_115 ) {
if ( F_3 ( V_116 ) )
V_95 |= F_38 ( V_16 ) ;
else
V_95 |= F_39 ( V_16 ) ;
}
V_90 [ V_99 ] = V_16 - 1 ;
}
V_91 [ 0 ] = 0 ;
if ( V_98 & 2 )
V_91 [ 0 ] = V_117 ;
if ( V_98 & 0x7c )
V_91 [ 0 ] |= V_118 ;
if ( ! ( V_98 & 0x60 ) )
V_91 [ 0 ] |= V_119 ;
V_91 [ 1 ] = V_94 ;
V_91 [ 2 ] = V_8 ;
V_91 [ 3 ] = V_95 ;
return 0 ;
}
void F_40 ( unsigned int V_16 , unsigned long V_91 [] )
{
if ( V_16 <= 3 )
V_91 [ 1 ] &= ~ ( 0xffUL << F_36 ( V_16 + 1 ) ) ;
}
static int F_41 ( T_1 V_1 , const unsigned int V_120 [] [ V_121 ] , int V_122 )
{
int V_99 , V_123 ;
for ( V_99 = 0 ; V_99 < V_122 ; ++ V_99 ) {
if ( V_1 < V_120 [ V_99 ] [ 0 ] )
break;
for ( V_123 = 0 ; V_123 < V_121 && V_120 [ V_99 ] [ V_123 ] ; ++ V_123 )
if ( V_1 == V_120 [ V_99 ] [ V_123 ] )
return V_99 ;
}
return - 1 ;
}
int F_42 ( T_1 V_1 , T_1 V_124 [] ,
const unsigned int V_120 [] [ V_121 ] , int V_122 )
{
int V_99 , V_123 , V_125 = 0 ;
T_1 V_126 ;
V_124 [ V_125 ++ ] = V_1 ;
V_99 = F_41 ( V_1 , V_120 , V_122 ) ;
if ( V_99 >= 0 ) {
for ( V_123 = 0 ; V_123 < V_121 ; ++ V_123 ) {
V_126 = V_120 [ V_99 ] [ V_123 ] ;
if ( V_126 && V_126 != V_1 )
V_124 [ V_125 ++ ] = V_126 ;
}
}
return V_125 ;
}
