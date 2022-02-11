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
* V_8 |= V_13 ;
}
static T_1 F_7 ( T_1 V_14 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return V_14 << V_15 ;
return V_14 << V_16 ;
}
static unsigned long F_8 ( T_1 V_1 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_9 ( V_1 ) ;
return F_10 ( V_1 ) ;
}
static unsigned long F_11 ( unsigned long V_17 )
{
if ( F_3 ( V_4 ) && ! F_3 ( V_5 ) )
return F_12 ( V_17 ) ;
return F_13 ( V_17 ) ;
}
static inline bool F_14 ( T_1 V_1 )
{
return ( V_1 >> V_18 ) & V_19 ;
}
static bool F_15 ( T_1 V_1 )
{
unsigned int V_20 , exp ;
V_20 = ( V_1 >> V_21 ) & V_22 ;
exp = V_20 >> 7 ;
if ( exp && ( V_20 & 0x60 ) == 0 )
return false ;
return true ;
}
static inline T_1 F_16 ( T_1 V_23 , T_2 V_24 )
{
T_1 V_25 = V_26 ;
switch( V_23 ) {
case 0 :
break;
case 1 :
V_25 = F_17 ( V_27 , V_28 ) ;
break;
case 2 :
V_25 = F_17 ( V_27 , V_29 ) ;
break;
case 3 :
V_25 = F_17 ( V_27 , V_30 ) ;
break;
case 4 :
if ( V_24 <= 1 )
V_25 = F_17 ( V_27 , V_31 ) ;
else if ( V_24 > 1 && V_24 <= 2 )
V_25 = F_17 ( V_27 , V_32 ) ;
else
V_25 = F_17 ( V_27 , V_33 ) ;
V_25 |= F_18 ( V_34 , V_35 ) ;
break;
case 5 :
V_25 = F_17 ( V_27 , V_36 ) ;
if ( ( V_24 == 0 ) || ( V_24 == 2 ) || ( V_24 == 4 ) )
V_25 |= F_18 ( V_34 , V_35 ) ;
else if ( ( V_24 == 1 ) || ( V_24 == 3 ) || ( V_24 == 5 ) )
V_25 |= F_18 ( V_34 , V_37 ) ;
break;
case 6 :
V_25 = F_17 ( V_27 , V_38 ) ;
if ( ( V_24 == 0 ) || ( V_24 == 2 ) )
V_25 |= F_18 ( V_34 , V_35 ) ;
else if ( ( V_24 == 1 ) || ( V_24 == 3 ) )
V_25 |= F_18 ( V_34 , V_37 ) ;
break;
case 7 :
V_25 = F_19 ( V_27 , V_28 ) ;
break;
}
return V_25 ;
}
void F_20 ( union V_39 * V_40 , T_2 V_41 ,
struct V_42 * V_43 )
{
T_1 V_23 ;
T_2 V_24 ;
T_1 V_44 ;
T_1 V_45 ;
if ( ! ( V_41 & V_46 ) ) {
V_40 -> V_45 = 0 ;
return;
}
V_44 = F_21 ( V_47 ) ;
V_45 = ( V_44 & V_48 ) >> V_49 ;
if ( V_45 == 1 || V_45 == 2 ) {
V_23 = ( V_44 & V_50 ) >> V_51 ;
V_24 = ( V_44 & V_52 ) >> V_53 ;
V_40 -> V_45 = F_16 ( V_23 , V_24 ) ;
V_40 -> V_45 |= ( V_45 == 1 ) ? F_18 ( V_54 , V_55 ) : F_18 ( V_54 , V_56 ) ;
}
}
void F_22 ( T_1 * V_57 )
{
T_1 V_8 = F_21 ( V_58 ) ;
T_1 exp = F_23 ( V_8 ) ;
T_1 V_59 = F_24 ( V_8 ) ;
* V_57 = V_59 << ( 2 * exp ) ;
}
int F_25 ( T_1 V_1 , unsigned long * V_60 , unsigned long * V_61 )
{
unsigned int V_62 , V_17 , V_63 , V_64 ;
unsigned long V_65 , V_14 ;
V_65 = V_14 = 0 ;
if ( ! F_2 ( V_1 ) )
return - 1 ;
V_17 = ( V_1 >> V_66 ) & V_67 ;
V_62 = ( V_1 >> V_68 ) & V_69 ;
V_63 = ( V_1 >> V_70 ) & V_71 ;
V_64 = ( V_1 >> V_72 ) & V_73 ;
if ( V_17 ) {
T_1 V_74 ;
if ( V_17 > 6 )
return - 1 ;
V_74 = V_1 & ~ V_75 ;
if ( V_17 >= 5 && V_74 != 0x500fa &&
V_74 != 0x600f4 )
return - 1 ;
V_65 |= F_26 ( V_17 ) ;
V_14 |= F_27 ( V_17 ) ;
}
if ( V_17 <= 4 ) {
V_65 |= V_76 ;
V_14 |= V_77 ;
}
if ( V_62 >= 6 && V_62 <= 9 ) {
if ( V_63 & 0x7 )
return - 1 ;
} else if ( V_1 & V_78 ) {
V_65 |= V_79 ;
V_14 |= F_28 ( V_63 ) ;
}
if ( F_4 ( V_1 ) ) {
V_65 |= V_80 ;
V_14 |= F_29 ( V_1 >> V_81 ) ;
}
if ( F_3 ( V_4 ) ) {
if ( F_14 ( V_1 ) && F_15 ( V_1 ) ) {
V_65 |= V_82 ;
V_14 |= F_30 ( V_1 >> V_83 ) ;
}
} else {
if ( F_1 ( V_1 ) ) {
V_65 |= V_84 ;
V_14 |= F_31 ( V_1 >> V_85 ) ;
} else {
if ( ! F_15 ( V_1 ) )
return - 1 ;
V_65 |= V_82 ;
V_14 |= F_30 ( V_1 >> V_83 ) ;
}
}
if ( ! V_17 && V_64 )
return - 1 ;
if ( V_1 & V_86 ) {
if ( ! V_64 )
return - 1 ;
V_65 |= V_87 ;
V_14 |= F_32 ( V_1 >> V_88 ) ;
}
V_65 |= F_33 ( V_64 ) ;
V_14 |= V_89 ;
* V_60 = V_65 ;
* V_61 = V_14 ;
return 0 ;
}
int F_34 ( T_1 V_1 [] , int V_90 ,
unsigned int V_91 [] , unsigned long V_92 [] ,
struct V_93 * V_94 [] )
{
unsigned long V_8 , V_95 , V_96 , V_62 , V_97 , V_98 , V_63 , V_45 ;
unsigned int V_17 , V_99 ;
int V_100 ;
V_99 = 0 ;
for ( V_100 = 0 ; V_100 < V_90 ; ++ V_100 ) {
V_17 = ( V_1 [ V_100 ] >> V_66 ) & V_67 ;
if ( V_17 )
V_99 |= 1 << V_17 ;
}
V_8 = V_95 = V_96 = 0 ;
for ( V_100 = 0 ; V_100 < V_90 ; ++ V_100 ) {
V_17 = ( V_1 [ V_100 ] >> V_66 ) & V_67 ;
V_62 = ( V_1 [ V_100 ] >> V_68 ) & V_69 ;
V_97 = F_8 ( V_1 [ V_100 ] ) ;
V_98 = V_1 [ V_100 ] & V_101 ;
if ( ! V_17 ) {
for ( V_17 = 1 ; V_17 <= 4 ; ++ V_17 ) {
if ( ! ( V_99 & ( 1 << V_17 ) ) )
break;
}
V_99 |= 1 << V_17 ;
}
if ( V_17 <= 4 ) {
V_95 |= V_62 << F_35 ( V_17 ) ;
V_95 |= V_97 << F_11 ( V_17 ) ;
V_95 |= V_98 << F_36 ( V_17 ) ;
}
F_5 ( V_1 [ V_100 ] , & V_8 ) ;
if ( V_1 [ V_100 ] & V_78 ) {
V_63 = V_1 [ V_100 ] >> V_70 ;
V_95 |= ( V_63 & 1 ) << V_102 ;
V_63 >>= 1 ;
V_95 |= ( V_63 & 1 ) << V_103 ;
}
if ( F_4 ( V_1 [ V_100 ] ) ) {
V_8 |= V_9 ;
V_45 = ( V_1 [ V_100 ] >> V_81 ) & V_104 ;
if ( V_45 ) {
V_8 |= ( V_45 & 3 ) << V_105 ;
V_8 |= ( V_45 >> 2 ) << V_106 ;
}
}
if ( ! F_3 ( V_4 ) && F_1 ( V_1 [ V_100 ] ) ) {
V_95 |= ( ( V_1 [ V_100 ] >> V_85 ) &
V_107 ) << V_108 ;
} else {
V_45 = ( V_1 [ V_100 ] >> V_85 ) & V_107 ;
V_8 |= V_45 << V_109 ;
V_45 = ( V_1 [ V_100 ] >> V_18 ) & V_19 ;
V_8 |= V_45 << V_110 ;
V_45 = ( V_1 [ V_100 ] >> V_21 ) & V_22 ;
V_8 |= F_7 ( V_45 ) ;
}
if ( V_1 [ V_100 ] & V_86 ) {
V_45 = ( V_1 [ V_100 ] >> V_88 ) & V_111 ;
V_8 |= V_45 << V_112 ;
}
if ( V_94 [ V_100 ] -> V_113 . V_114 )
V_96 |= F_37 ( V_17 ) ;
if ( V_94 [ V_100 ] -> V_113 . V_115 )
V_96 |= F_38 ( V_17 ) ;
if ( V_94 [ V_100 ] -> V_113 . V_116 ) {
if ( F_3 ( V_117 ) )
V_96 |= F_38 ( V_17 ) ;
else
V_96 |= F_39 ( V_17 ) ;
}
V_91 [ V_100 ] = V_17 - 1 ;
}
V_92 [ 0 ] = 0 ;
if ( V_99 & 2 )
V_92 [ 0 ] = V_118 ;
if ( V_99 & 0x7c )
V_92 [ 0 ] |= V_119 ;
if ( ! ( V_99 & 0x60 ) )
V_92 [ 0 ] |= V_120 ;
V_92 [ 1 ] = V_95 ;
V_92 [ 2 ] = V_8 ;
V_92 [ 3 ] = V_96 ;
return 0 ;
}
void F_40 ( unsigned int V_17 , unsigned long V_92 [] )
{
if ( V_17 <= 3 )
V_92 [ 1 ] &= ~ ( 0xffUL << F_36 ( V_17 + 1 ) ) ;
}
static int F_41 ( T_1 V_1 , const unsigned int V_121 [] [ V_122 ] , int V_123 )
{
int V_100 , V_124 ;
for ( V_100 = 0 ; V_100 < V_123 ; ++ V_100 ) {
if ( V_1 < V_121 [ V_100 ] [ 0 ] )
break;
for ( V_124 = 0 ; V_124 < V_122 && V_121 [ V_100 ] [ V_124 ] ; ++ V_124 )
if ( V_1 == V_121 [ V_100 ] [ V_124 ] )
return V_100 ;
}
return - 1 ;
}
int F_42 ( T_1 V_1 , T_1 V_125 [] , int V_123 , unsigned int V_41 ,
const unsigned int V_121 [] [ V_122 ] )
{
int V_100 , V_124 , V_126 = 0 ;
T_1 V_127 ;
V_125 [ V_126 ++ ] = V_1 ;
V_100 = F_41 ( V_1 , V_121 , V_123 ) ;
if ( V_100 >= 0 ) {
for ( V_124 = 0 ; V_124 < V_122 ; ++ V_124 ) {
V_127 = V_121 [ V_100 ] [ V_124 ] ;
if ( V_127 && V_127 != V_1 )
V_125 [ V_126 ++ ] = V_127 ;
}
}
if ( V_41 & V_128 ) {
V_124 = V_126 ;
for ( V_100 = 0 ; V_100 < V_126 ; ++ V_100 ) {
switch ( V_125 [ V_100 ] ) {
case 0x1e :
V_125 [ V_124 ++ ] = 0x600f4 ;
break;
case 0x600f4 :
V_125 [ V_124 ++ ] = 0x1e ;
break;
case 0x2 :
V_125 [ V_124 ++ ] = 0x500fa ;
break;
case 0x500fa :
V_125 [ V_124 ++ ] = 0x2 ;
break;
}
}
V_126 = V_124 ;
}
return V_126 ;
}
