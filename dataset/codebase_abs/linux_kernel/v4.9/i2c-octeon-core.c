T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
V_4 -> V_5 ( V_4 ) ;
F_2 ( & V_4 -> V_6 ) ;
return V_7 ;
}
static bool F_3 ( struct V_3 * V_4 )
{
return ( F_4 ( V_4 ) & V_8 ) ;
}
static bool F_5 ( struct V_3 * V_4 , bool * V_9 )
{
if ( F_3 ( V_4 ) )
return true ;
if ( * V_9 ) {
* V_9 = false ;
return false ;
}
F_6 ( V_10 , 2 * V_10 ) ;
return F_3 ( V_4 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
long V_11 ;
bool V_9 = true ;
if ( V_4 -> V_12 ) {
T_2 V_13 = F_8 () + V_4 -> V_14 . V_15 ;
while ( ! F_3 ( V_4 ) &&
F_9 ( F_8 () , V_13 ) )
F_6 ( V_10 / 2 , V_10 ) ;
return F_3 ( V_4 ) ? 0 : - V_16 ;
}
V_4 -> V_17 ( V_4 ) ;
V_11 = F_10 ( V_4 -> V_6 , F_5 ( V_4 , & V_9 ) ,
V_4 -> V_14 . V_15 ) ;
V_4 -> V_5 ( V_4 ) ;
if ( V_4 -> V_18 && ! V_11 &&
F_3 ( V_4 ) ) {
F_11 ( V_4 -> V_19 , L_1 ) ;
V_4 -> V_12 = true ;
return 0 ;
}
if ( ! V_11 )
return - V_16 ;
return 0 ;
}
static bool F_12 ( struct V_3 * V_4 )
{
return ( F_13 ( V_4 -> V_20 + F_14 ( V_4 ) ) & V_21 ) == 0 ;
}
static bool F_15 ( struct V_3 * V_4 , bool * V_9 )
{
if ( F_12 ( V_4 ) )
return true ;
if ( * V_9 ) {
* V_9 = false ;
return false ;
}
F_6 ( V_10 , 2 * V_10 ) ;
return F_12 ( V_4 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
F_17 ( V_4 , V_22 | V_23 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
int V_24 = 0 ;
T_2 V_25 ;
if ( V_4 -> V_26 )
return;
V_4 -> V_26 = true ;
while ( 1 ) {
V_25 = F_4 ( V_4 ) ;
if ( ! ( V_25 & ( V_27 | V_28 ) ) )
break;
if ( V_25 & V_8 )
F_19 ( V_4 , V_29 ) ;
if ( V_24 ++ > 100 ) {
F_20 ( L_2 , V_30 ) ;
break;
}
F_21 ( 10 ) ;
}
F_19 ( V_4 , V_31 | V_32 | V_29 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_26 )
return;
V_4 -> V_26 = false ;
F_19 ( V_4 , V_29 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
bool V_9 = true ;
int V_11 ;
if ( V_4 -> V_12 ) {
T_2 V_13 = F_8 () + V_4 -> V_14 . V_15 ;
while ( ! F_12 ( V_4 ) &&
F_9 ( F_8 () , V_13 ) )
F_6 ( V_10 / 2 , V_10 ) ;
return F_12 ( V_4 ) ? 0 : - V_16 ;
}
V_4 -> V_33 ( V_4 ) ;
V_11 = F_10 ( V_4 -> V_6 ,
F_15 ( V_4 , & V_9 ) ,
V_4 -> V_14 . V_15 ) ;
V_4 -> V_34 ( V_4 ) ;
if ( ! V_11 )
F_16 ( V_4 ) ;
if ( V_4 -> V_18 && ! V_11 &&
F_12 ( V_4 ) ) {
F_11 ( V_4 -> V_19 , L_1 ) ;
V_4 -> V_12 = true ;
return 0 ;
}
if ( ! V_11 )
return - V_16 ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 , int V_35 )
{
T_3 V_36 ;
if ( V_4 -> V_26 )
V_36 = F_13 ( V_4 -> V_20 + F_14 ( V_4 ) ) ;
else
V_36 = F_25 ( V_4 ) ;
switch ( V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return 0 ;
case V_42 :
if ( ! V_35 )
return 0 ;
return - V_43 ;
case V_44 :
if ( V_35 )
return 0 ;
return - V_43 ;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
return - V_49 ;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return - V_54 ;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
return - V_54 ;
case V_62 :
return - V_43 ;
case V_63 :
case V_64 :
case V_65 :
return - V_66 ;
default:
F_11 ( V_4 -> V_19 , L_3 , V_36 ) ;
return - V_43 ;
}
}
static int F_26 ( struct V_3 * V_4 )
{
int V_67 ;
V_67 = F_27 ( & V_4 -> V_14 ) ;
if ( V_67 )
V_67 = F_28 ( V_4 ) ;
return V_67 ;
}
static int F_29 ( struct V_3 * V_4 )
{
int V_67 ;
T_3 V_36 ;
F_22 ( V_4 ) ;
F_19 ( V_4 , V_29 | V_27 ) ;
V_67 = F_7 ( V_4 ) ;
if ( V_67 )
goto error;
V_36 = F_25 ( V_4 ) ;
if ( V_36 == V_68 || V_36 == V_69 )
return 0 ;
error:
V_67 = F_26 ( V_4 ) ;
return ( V_67 ) ? V_67 : - V_49 ;
}
static void F_30 ( struct V_3 * V_4 )
{
F_19 ( V_4 , V_29 | V_28 ) ;
}
static int F_31 ( struct V_3 * V_4 , int V_70 ,
T_3 * V_71 , T_4 * V_72 , bool V_73 )
{
int V_74 , V_75 , V_76 = * V_72 ;
bool V_35 = false ;
F_32 ( V_4 , ( V_70 << 1 ) | 1 ) ;
F_19 ( V_4 , V_29 ) ;
V_75 = F_7 ( V_4 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_24 ( V_4 , false ) ;
if ( V_75 )
return V_75 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
if ( ( V_74 + 1 == V_76 ) && ! ( V_73 && V_74 == 0 ) )
V_35 = true ;
if ( V_35 )
F_19 ( V_4 , V_29 ) ;
else
F_19 ( V_4 , V_29 | V_32 ) ;
V_75 = F_7 ( V_4 ) ;
if ( V_75 )
return V_75 ;
V_71 [ V_74 ] = F_33 ( V_4 ) ;
if ( V_73 && V_74 == 0 ) {
if ( V_71 [ V_74 ] > V_77 + 1 )
return - V_78 ;
V_76 += V_71 [ V_74 ] ;
}
V_75 = F_24 ( V_4 , V_35 ) ;
if ( V_75 )
return V_75 ;
}
* V_72 = V_76 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 , int V_70 ,
const T_3 * V_71 , int V_76 )
{
int V_74 , V_75 ;
F_32 ( V_4 , V_70 << 1 ) ;
F_19 ( V_4 , V_29 ) ;
V_75 = F_7 ( V_4 ) ;
if ( V_75 )
return V_75 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_75 = F_24 ( V_4 , false ) ;
if ( V_75 )
return V_75 ;
F_32 ( V_4 , V_71 [ V_74 ] ) ;
F_19 ( V_4 , V_29 ) ;
V_75 = F_7 ( V_4 ) ;
if ( V_75 )
return V_75 ;
}
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
int V_74 , V_81 , V_67 = 0 ;
T_2 V_82 ;
F_18 ( V_4 ) ;
F_16 ( V_4 ) ;
V_82 = V_21 | V_83 | V_84 ;
V_82 |= ( T_2 ) ( V_80 [ 0 ] . V_85 - 1 ) << V_86 ;
V_82 |= ( T_2 ) ( V_80 [ 0 ] . V_87 & 0x7full ) << V_88 ;
if ( V_80 [ 0 ] . V_89 & V_90 )
V_82 |= V_91 ;
else
V_82 |= V_92 ;
F_36 ( V_82 , V_4 -> V_20 + F_14 ( V_4 ) ) ;
V_67 = F_23 ( V_4 ) ;
if ( V_67 )
goto V_93;
V_82 = F_13 ( V_4 -> V_20 + F_14 ( V_4 ) ) ;
if ( ( V_82 & V_83 ) == 0 )
return F_24 ( V_4 , false ) ;
for ( V_74 = 0 , V_81 = V_80 [ 0 ] . V_85 - 1 ; V_74 < V_80 [ 0 ] . V_85 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_80 [ 0 ] . V_94 [ V_81 ] = ( V_82 >> ( 8 * V_74 ) ) & 0xff ;
if ( V_80 [ 0 ] . V_85 > 4 ) {
V_82 = F_13 ( V_4 -> V_20 + F_37 ( V_4 ) ) ;
for ( V_74 = 0 ; V_74 < V_80 [ 0 ] . V_85 - 4 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_80 [ 0 ] . V_94 [ V_81 ] = ( V_82 >> ( 8 * V_74 ) ) & 0xff ;
}
V_93:
return V_67 ;
}
static int F_38 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
int V_74 , V_81 , V_67 = 0 ;
T_2 V_82 ;
F_18 ( V_4 ) ;
F_16 ( V_4 ) ;
V_82 = V_21 | V_84 ;
V_82 |= ( T_2 ) ( V_80 [ 0 ] . V_85 - 1 ) << V_86 ;
V_82 |= ( T_2 ) ( V_80 [ 0 ] . V_87 & 0x7full ) << V_88 ;
if ( V_80 [ 0 ] . V_89 & V_90 )
V_82 |= V_91 ;
else
V_82 |= V_92 ;
for ( V_74 = 0 , V_81 = V_80 [ 0 ] . V_85 - 1 ; V_74 < V_80 [ 0 ] . V_85 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_82 |= ( T_2 ) V_80 [ 0 ] . V_94 [ V_81 ] << ( 8 * V_74 ) ;
if ( V_80 [ 0 ] . V_85 > 4 ) {
T_2 V_95 = 0 ;
for ( V_74 = 0 ; V_74 < V_80 [ 0 ] . V_85 - 4 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_95 |= ( T_2 ) V_80 [ 0 ] . V_94 [ V_81 ] << ( 8 * V_74 ) ;
F_36 ( V_95 , V_4 -> V_20 + F_37 ( V_4 ) ) ;
}
F_36 ( V_82 , V_4 -> V_20 + F_14 ( V_4 ) ) ;
V_67 = F_23 ( V_4 ) ;
if ( V_67 )
goto V_93;
V_82 = F_13 ( V_4 -> V_20 + F_14 ( V_4 ) ) ;
if ( ( V_82 & V_83 ) == 0 )
return F_24 ( V_4 , false ) ;
V_93:
return V_67 ;
}
static int F_39 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
int V_74 , V_81 , V_67 = 0 ;
T_2 V_82 ;
F_18 ( V_4 ) ;
V_82 = V_21 | V_83 | V_84 ;
V_82 |= ( T_2 ) ( V_80 [ 1 ] . V_85 - 1 ) << V_86 ;
V_82 |= ( T_2 ) ( V_80 [ 0 ] . V_87 & 0x7full ) << V_88 ;
if ( V_80 [ 0 ] . V_89 & V_90 )
V_82 |= V_96 ;
else
V_82 |= V_97 ;
if ( V_80 [ 0 ] . V_85 == 2 ) {
T_2 V_95 = 0 ;
V_82 |= V_98 ;
V_95 = ( T_2 ) V_80 [ 0 ] . V_94 [ 0 ] << V_99 ;
V_82 |= ( T_2 ) V_80 [ 0 ] . V_94 [ 1 ] << V_99 ;
F_36 ( V_95 , V_4 -> V_20 + F_37 ( V_4 ) ) ;
} else {
V_82 |= ( T_2 ) V_80 [ 0 ] . V_94 [ 0 ] << V_99 ;
}
F_16 ( V_4 ) ;
F_36 ( V_82 , V_4 -> V_20 + F_14 ( V_4 ) ) ;
V_67 = F_23 ( V_4 ) ;
if ( V_67 )
goto V_93;
V_82 = F_13 ( V_4 -> V_20 + F_14 ( V_4 ) ) ;
if ( ( V_82 & V_83 ) == 0 )
return F_24 ( V_4 , false ) ;
for ( V_74 = 0 , V_81 = V_80 [ 1 ] . V_85 - 1 ; V_74 < V_80 [ 1 ] . V_85 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_80 [ 1 ] . V_94 [ V_81 ] = ( V_82 >> ( 8 * V_74 ) ) & 0xff ;
if ( V_80 [ 1 ] . V_85 > 4 ) {
V_82 = F_13 ( V_4 -> V_20 + F_37 ( V_4 ) ) ;
for ( V_74 = 0 ; V_74 < V_80 [ 1 ] . V_85 - 4 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_80 [ 1 ] . V_94 [ V_81 ] = ( V_82 >> ( 8 * V_74 ) ) & 0xff ;
}
V_93:
return V_67 ;
}
static int F_40 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
bool V_100 = false ;
int V_74 , V_81 , V_67 = 0 ;
T_2 V_82 , V_95 = 0 ;
F_18 ( V_4 ) ;
V_82 = V_21 | V_84 ;
V_82 |= ( T_2 ) ( V_80 [ 1 ] . V_85 - 1 ) << V_86 ;
V_82 |= ( T_2 ) ( V_80 [ 0 ] . V_87 & 0x7full ) << V_88 ;
if ( V_80 [ 0 ] . V_89 & V_90 )
V_82 |= V_96 ;
else
V_82 |= V_97 ;
if ( V_80 [ 0 ] . V_85 == 2 ) {
V_82 |= V_98 ;
V_95 |= ( T_2 ) V_80 [ 0 ] . V_94 [ 0 ] << V_99 ;
V_100 = true ;
V_82 |= ( T_2 ) V_80 [ 0 ] . V_94 [ 1 ] << V_99 ;
} else {
V_82 |= ( T_2 ) V_80 [ 0 ] . V_94 [ 0 ] << V_99 ;
}
for ( V_74 = 0 , V_81 = V_80 [ 1 ] . V_85 - 1 ; V_74 < V_80 [ 1 ] . V_85 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_82 |= ( T_2 ) V_80 [ 1 ] . V_94 [ V_81 ] << ( 8 * V_74 ) ;
if ( V_80 [ 1 ] . V_85 > 4 ) {
for ( V_74 = 0 ; V_74 < V_80 [ 1 ] . V_85 - 4 && V_74 < 4 ; V_74 ++ , V_81 -- )
V_95 |= ( T_2 ) V_80 [ 1 ] . V_94 [ V_81 ] << ( 8 * V_74 ) ;
V_100 = true ;
}
if ( V_100 )
F_36 ( V_95 , V_4 -> V_20 + F_37 ( V_4 ) ) ;
F_16 ( V_4 ) ;
F_36 ( V_82 , V_4 -> V_20 + F_14 ( V_4 ) ) ;
V_67 = F_23 ( V_4 ) ;
if ( V_67 )
goto V_93;
V_82 = F_13 ( V_4 -> V_20 + F_14 ( V_4 ) ) ;
if ( ( V_82 & V_83 ) == 0 )
return F_24 ( V_4 , false ) ;
V_93:
return V_67 ;
}
int F_41 ( struct V_101 * V_14 , struct V_79 * V_80 , int V_102 )
{
struct V_3 * V_4 = F_42 ( V_14 ) ;
int V_74 , V_67 = 0 ;
if ( V_102 == 1 ) {
if ( V_80 [ 0 ] . V_85 > 0 && V_80 [ 0 ] . V_85 <= 8 ) {
if ( V_80 [ 0 ] . V_89 & V_103 )
V_67 = F_35 ( V_4 , V_80 ) ;
else
V_67 = F_38 ( V_4 , V_80 ) ;
goto V_104;
}
} else if ( V_102 == 2 ) {
if ( ( V_80 [ 0 ] . V_89 & V_103 ) == 0 &&
( V_80 [ 1 ] . V_89 & V_105 ) == 0 &&
V_80 [ 0 ] . V_85 > 0 && V_80 [ 0 ] . V_85 <= 2 &&
V_80 [ 1 ] . V_85 > 0 && V_80 [ 1 ] . V_85 <= 8 &&
V_80 [ 0 ] . V_87 == V_80 [ 1 ] . V_87 ) {
if ( V_80 [ 1 ] . V_89 & V_103 )
V_67 = F_39 ( V_4 , V_80 ) ;
else
V_67 = F_40 ( V_4 , V_80 ) ;
goto V_104;
}
}
for ( V_74 = 0 ; V_67 == 0 && V_74 < V_102 ; V_74 ++ ) {
struct V_79 * V_106 = & V_80 [ V_74 ] ;
if ( ! V_106 -> V_85 ) {
V_67 = - V_54 ;
break;
}
V_67 = F_29 ( V_4 ) ;
if ( V_67 )
return V_67 ;
if ( V_106 -> V_89 & V_103 )
V_67 = F_31 ( V_4 , V_106 -> V_87 , V_106 -> V_94 ,
& V_106 -> V_85 , V_106 -> V_89 & V_105 ) ;
else
V_67 = F_34 ( V_4 , V_106 -> V_87 , V_106 -> V_94 ,
V_106 -> V_85 ) ;
}
F_30 ( V_4 ) ;
V_104:
return ( V_67 != 0 ) ? V_67 : V_102 ;
}
void F_43 ( struct V_3 * V_4 )
{
int V_107 , V_108 , V_109 , V_110 , V_111 , V_112 , V_113 , V_114 ;
int V_115 = 0x18 , V_116 = 2 , V_117 = 0 , V_118 = 1000000 ;
for ( V_112 = 0 ; V_112 < 8 && V_118 != 0 ; V_112 ++ ) {
for ( V_111 = 15 ; V_111 >= 2 && V_118 != 0 ; V_111 -- ) {
V_107 = V_4 -> V_119 * ( V_111 + 1 ) * 10 ;
V_107 *= ( 1 << V_112 ) ;
V_108 = ( V_4 -> V_120 / ( V_107 * 2 ) ) - 1 ;
for ( V_109 = 0 ; V_109 <= 1 ; V_109 ++ ) {
V_110 = V_108 + V_109 ;
if ( V_110 < 5 || V_110 > 0xff )
continue;
V_113 = V_4 -> V_120 / ( 2 * ( V_110 + 1 ) ) ;
V_113 = V_113 / ( 1 << V_112 ) ;
V_113 = V_113 / ( V_111 + 1 ) / 10 ;
V_114 = abs ( V_113 - V_4 -> V_119 ) ;
if ( V_114 < V_118 ) {
V_118 = V_114 ;
V_115 = V_110 ;
V_116 = V_111 ;
V_117 = V_112 ;
}
}
}
}
F_44 ( V_4 , V_121 , V_115 ) ;
F_44 ( V_4 , V_122 , ( V_116 << 3 ) | V_117 ) ;
}
int F_28 ( struct V_3 * V_4 )
{
T_3 V_123 = 0 ;
int V_124 ;
F_44 ( V_4 , V_125 , 0 ) ;
for ( V_124 = 10 ; V_124 && V_123 != V_37 ; V_124 -- ) {
F_21 ( 1 ) ;
V_123 = F_25 ( V_4 ) ;
if ( V_123 == V_37 )
break;
}
if ( V_123 != V_37 ) {
F_11 ( V_4 -> V_19 , L_4 ,
V_30 , V_123 ) ;
return - V_43 ;
}
F_18 ( V_4 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static int F_45 ( struct V_101 * V_14 )
{
struct V_3 * V_4 = F_42 ( V_14 ) ;
T_2 V_126 ;
V_126 = F_46 ( V_4 ) ;
return V_126 & V_127 ;
}
static void F_47 ( struct V_101 * V_14 , int V_25 )
{
struct V_3 * V_4 = F_42 ( V_14 ) ;
F_17 ( V_4 , V_25 ? 0 : V_128 ) ;
}
static int F_48 ( struct V_101 * V_14 )
{
struct V_3 * V_4 = F_42 ( V_14 ) ;
T_2 V_126 ;
V_126 = F_46 ( V_4 ) ;
return V_126 & V_129 ;
}
static void F_49 ( struct V_101 * V_14 )
{
struct V_3 * V_4 = F_42 ( V_14 ) ;
F_22 ( V_4 ) ;
F_19 ( V_4 , V_29 ) ;
F_17 ( V_4 , 0 ) ;
}
static void F_50 ( struct V_101 * V_14 )
{
struct V_3 * V_4 = F_42 ( V_14 ) ;
F_17 ( V_4 , V_130 | V_128 ) ;
F_21 ( 5 ) ;
F_17 ( V_4 , V_130 ) ;
F_21 ( 5 ) ;
F_17 ( V_4 , 0 ) ;
}
