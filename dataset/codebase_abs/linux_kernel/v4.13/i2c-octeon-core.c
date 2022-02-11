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
static int F_5 ( struct V_3 * V_4 )
{
long V_9 ;
if ( V_4 -> V_10 ) {
T_2 V_11 = F_6 () + V_4 -> V_12 . V_13 ;
while ( ! F_3 ( V_4 ) &&
F_7 ( F_6 () , V_11 ) )
F_8 ( V_14 / 2 , V_14 ) ;
return F_3 ( V_4 ) ? 0 : - V_15 ;
}
V_4 -> V_16 ( V_4 ) ;
V_9 = F_9 ( V_4 -> V_6 , F_3 ( V_4 ) ,
V_4 -> V_12 . V_13 ) ;
V_4 -> V_5 ( V_4 ) ;
if ( V_4 -> V_17 && ! V_9 &&
F_3 ( V_4 ) ) {
F_10 ( V_4 -> V_18 , L_1 ) ;
V_4 -> V_10 = true ;
return 0 ;
}
if ( ! V_9 )
return - V_15 ;
return 0 ;
}
static bool F_11 ( struct V_3 * V_4 )
{
return ( F_12 ( V_4 -> V_19 + F_13 ( V_4 ) ) & V_20 ) == 0 ;
}
static void F_14 ( struct V_3 * V_4 )
{
F_15 ( V_4 , V_21 | V_22 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
int V_23 = 0 ;
T_2 V_24 ;
if ( V_4 -> V_25 )
return;
V_4 -> V_25 = true ;
while ( 1 ) {
V_24 = F_4 ( V_4 ) ;
if ( ! ( V_24 & ( V_26 | V_27 ) ) )
break;
if ( V_24 & V_8 )
F_17 ( V_4 , V_28 ) ;
if ( V_23 ++ > 100 ) {
F_18 ( L_2 , V_29 ) ;
break;
}
F_19 ( 10 ) ;
}
F_17 ( V_4 , V_30 | V_31 | V_28 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_25 )
return;
V_4 -> V_25 = false ;
F_17 ( V_4 , V_28 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_9 ;
if ( V_4 -> V_10 ) {
T_2 V_11 = F_6 () + V_4 -> V_12 . V_13 ;
while ( ! F_11 ( V_4 ) &&
F_7 ( F_6 () , V_11 ) )
F_8 ( V_14 / 2 , V_14 ) ;
return F_11 ( V_4 ) ? 0 : - V_15 ;
}
V_4 -> V_32 ( V_4 ) ;
V_9 = F_9 ( V_4 -> V_6 ,
F_11 ( V_4 ) ,
V_4 -> V_12 . V_13 ) ;
V_4 -> V_33 ( V_4 ) ;
if ( ! V_9 )
F_14 ( V_4 ) ;
if ( V_4 -> V_17 && ! V_9 &&
F_11 ( V_4 ) ) {
F_10 ( V_4 -> V_18 , L_1 ) ;
V_4 -> V_10 = true ;
return 0 ;
}
if ( ! V_9 )
return - V_15 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , int V_34 )
{
T_3 V_35 ;
if ( V_4 -> V_25 )
V_35 = F_12 ( V_4 -> V_19 + F_13 ( V_4 ) ) ;
else
V_35 = F_23 ( V_4 ) ;
switch ( V_35 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
return 0 ;
case V_41 :
if ( ! V_34 )
return 0 ;
return - V_42 ;
case V_43 :
if ( V_34 )
return 0 ;
return - V_42 ;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return - V_48 ;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return - V_53 ;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
return - V_53 ;
case V_61 :
return - V_42 ;
case V_62 :
case V_63 :
case V_64 :
return - V_65 ;
default:
F_10 ( V_4 -> V_18 , L_3 , V_35 ) ;
return - V_42 ;
}
}
static int F_24 ( struct V_3 * V_4 )
{
int V_66 ;
V_66 = F_25 ( & V_4 -> V_12 ) ;
if ( V_66 )
V_66 = F_26 ( V_4 ) ;
return V_66 ;
}
static int F_27 ( struct V_3 * V_4 )
{
int V_66 ;
T_3 V_35 ;
F_20 ( V_4 ) ;
F_17 ( V_4 , V_28 | V_26 ) ;
V_66 = F_5 ( V_4 ) ;
if ( V_66 )
goto error;
V_35 = F_23 ( V_4 ) ;
if ( V_35 == V_67 || V_35 == V_68 )
return 0 ;
error:
V_66 = F_24 ( V_4 ) ;
return ( V_66 ) ? V_66 : - V_48 ;
}
static void F_28 ( struct V_3 * V_4 )
{
F_17 ( V_4 , V_28 | V_27 ) ;
}
static int F_29 ( struct V_3 * V_4 , int V_69 ,
T_3 * V_70 , T_4 * V_71 , bool V_72 )
{
int V_73 , V_74 , V_75 = * V_71 ;
bool V_34 = false ;
F_30 ( V_4 , ( V_69 << 1 ) | 1 ) ;
F_17 ( V_4 , V_28 ) ;
V_74 = F_5 ( V_4 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_22 ( V_4 , false ) ;
if ( V_74 )
return V_74 ;
for ( V_73 = 0 ; V_73 < V_75 ; V_73 ++ ) {
if ( ( V_73 + 1 == V_75 ) && ! ( V_72 && V_73 == 0 ) )
V_34 = true ;
if ( V_34 )
F_17 ( V_4 , V_28 ) ;
else
F_17 ( V_4 , V_28 | V_31 ) ;
V_74 = F_5 ( V_4 ) ;
if ( V_74 )
return V_74 ;
V_70 [ V_73 ] = F_31 ( V_4 , & V_74 ) ;
if ( V_74 )
return V_74 ;
if ( V_72 && V_73 == 0 ) {
if ( V_70 [ V_73 ] > V_76 + 1 )
return - V_77 ;
V_75 += V_70 [ V_73 ] ;
}
V_74 = F_22 ( V_4 , V_34 ) ;
if ( V_74 )
return V_74 ;
}
* V_71 = V_75 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , int V_69 ,
const T_3 * V_70 , int V_75 )
{
int V_73 , V_74 ;
F_30 ( V_4 , V_69 << 1 ) ;
F_17 ( V_4 , V_28 ) ;
V_74 = F_5 ( V_4 ) ;
if ( V_74 )
return V_74 ;
for ( V_73 = 0 ; V_73 < V_75 ; V_73 ++ ) {
V_74 = F_22 ( V_4 , false ) ;
if ( V_74 )
return V_74 ;
F_30 ( V_4 , V_70 [ V_73 ] ) ;
F_17 ( V_4 , V_28 ) ;
V_74 = F_5 ( V_4 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static int F_33 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
int V_73 , V_80 , V_66 = 0 ;
T_2 V_81 ;
F_16 ( V_4 ) ;
F_14 ( V_4 ) ;
V_81 = V_20 | V_82 | V_83 ;
V_81 |= ( T_2 ) ( V_79 [ 0 ] . V_84 - 1 ) << V_85 ;
V_81 |= ( T_2 ) ( V_79 [ 0 ] . V_86 & 0x7full ) << V_87 ;
if ( V_79 [ 0 ] . V_88 & V_89 )
V_81 |= V_90 ;
else
V_81 |= V_91 ;
F_34 ( V_81 , V_4 -> V_19 + F_13 ( V_4 ) ) ;
V_66 = F_21 ( V_4 ) ;
if ( V_66 )
goto V_92;
V_81 = F_12 ( V_4 -> V_19 + F_13 ( V_4 ) ) ;
if ( ( V_81 & V_82 ) == 0 )
return F_22 ( V_4 , false ) ;
for ( V_73 = 0 , V_80 = V_79 [ 0 ] . V_84 - 1 ; V_73 < V_79 [ 0 ] . V_84 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_79 [ 0 ] . V_93 [ V_80 ] = ( V_81 >> ( 8 * V_73 ) ) & 0xff ;
if ( V_79 [ 0 ] . V_84 > 4 ) {
V_81 = F_12 ( V_4 -> V_19 + F_35 ( V_4 ) ) ;
for ( V_73 = 0 ; V_73 < V_79 [ 0 ] . V_84 - 4 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_79 [ 0 ] . V_93 [ V_80 ] = ( V_81 >> ( 8 * V_73 ) ) & 0xff ;
}
V_92:
return V_66 ;
}
static int F_36 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
int V_73 , V_80 , V_66 = 0 ;
T_2 V_81 ;
F_16 ( V_4 ) ;
F_14 ( V_4 ) ;
V_81 = V_20 | V_83 ;
V_81 |= ( T_2 ) ( V_79 [ 0 ] . V_84 - 1 ) << V_85 ;
V_81 |= ( T_2 ) ( V_79 [ 0 ] . V_86 & 0x7full ) << V_87 ;
if ( V_79 [ 0 ] . V_88 & V_89 )
V_81 |= V_90 ;
else
V_81 |= V_91 ;
for ( V_73 = 0 , V_80 = V_79 [ 0 ] . V_84 - 1 ; V_73 < V_79 [ 0 ] . V_84 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_81 |= ( T_2 ) V_79 [ 0 ] . V_93 [ V_80 ] << ( 8 * V_73 ) ;
if ( V_79 [ 0 ] . V_84 > 4 ) {
T_2 V_94 = 0 ;
for ( V_73 = 0 ; V_73 < V_79 [ 0 ] . V_84 - 4 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_94 |= ( T_2 ) V_79 [ 0 ] . V_93 [ V_80 ] << ( 8 * V_73 ) ;
F_34 ( V_94 , V_4 -> V_19 + F_35 ( V_4 ) ) ;
}
F_34 ( V_81 , V_4 -> V_19 + F_13 ( V_4 ) ) ;
V_66 = F_21 ( V_4 ) ;
if ( V_66 )
goto V_92;
V_81 = F_12 ( V_4 -> V_19 + F_13 ( V_4 ) ) ;
if ( ( V_81 & V_82 ) == 0 )
return F_22 ( V_4 , false ) ;
V_92:
return V_66 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
int V_73 , V_80 , V_66 = 0 ;
T_2 V_81 ;
F_16 ( V_4 ) ;
V_81 = V_20 | V_82 | V_83 ;
V_81 |= ( T_2 ) ( V_79 [ 1 ] . V_84 - 1 ) << V_85 ;
V_81 |= ( T_2 ) ( V_79 [ 0 ] . V_86 & 0x7full ) << V_87 ;
if ( V_79 [ 0 ] . V_88 & V_89 )
V_81 |= V_95 ;
else
V_81 |= V_96 ;
if ( V_79 [ 0 ] . V_84 == 2 ) {
T_2 V_94 = 0 ;
V_81 |= V_97 ;
V_94 = ( T_2 ) V_79 [ 0 ] . V_93 [ 0 ] << V_98 ;
V_81 |= ( T_2 ) V_79 [ 0 ] . V_93 [ 1 ] << V_98 ;
F_34 ( V_94 , V_4 -> V_19 + F_35 ( V_4 ) ) ;
} else {
V_81 |= ( T_2 ) V_79 [ 0 ] . V_93 [ 0 ] << V_98 ;
}
F_14 ( V_4 ) ;
F_34 ( V_81 , V_4 -> V_19 + F_13 ( V_4 ) ) ;
V_66 = F_21 ( V_4 ) ;
if ( V_66 )
goto V_92;
V_81 = F_12 ( V_4 -> V_19 + F_13 ( V_4 ) ) ;
if ( ( V_81 & V_82 ) == 0 )
return F_22 ( V_4 , false ) ;
for ( V_73 = 0 , V_80 = V_79 [ 1 ] . V_84 - 1 ; V_73 < V_79 [ 1 ] . V_84 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_79 [ 1 ] . V_93 [ V_80 ] = ( V_81 >> ( 8 * V_73 ) ) & 0xff ;
if ( V_79 [ 1 ] . V_84 > 4 ) {
V_81 = F_12 ( V_4 -> V_19 + F_35 ( V_4 ) ) ;
for ( V_73 = 0 ; V_73 < V_79 [ 1 ] . V_84 - 4 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_79 [ 1 ] . V_93 [ V_80 ] = ( V_81 >> ( 8 * V_73 ) ) & 0xff ;
}
V_92:
return V_66 ;
}
static int F_38 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
bool V_99 = false ;
int V_73 , V_80 , V_66 = 0 ;
T_2 V_81 , V_94 = 0 ;
F_16 ( V_4 ) ;
V_81 = V_20 | V_83 ;
V_81 |= ( T_2 ) ( V_79 [ 1 ] . V_84 - 1 ) << V_85 ;
V_81 |= ( T_2 ) ( V_79 [ 0 ] . V_86 & 0x7full ) << V_87 ;
if ( V_79 [ 0 ] . V_88 & V_89 )
V_81 |= V_95 ;
else
V_81 |= V_96 ;
if ( V_79 [ 0 ] . V_84 == 2 ) {
V_81 |= V_97 ;
V_94 |= ( T_2 ) V_79 [ 0 ] . V_93 [ 0 ] << V_98 ;
V_99 = true ;
V_81 |= ( T_2 ) V_79 [ 0 ] . V_93 [ 1 ] << V_98 ;
} else {
V_81 |= ( T_2 ) V_79 [ 0 ] . V_93 [ 0 ] << V_98 ;
}
for ( V_73 = 0 , V_80 = V_79 [ 1 ] . V_84 - 1 ; V_73 < V_79 [ 1 ] . V_84 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_81 |= ( T_2 ) V_79 [ 1 ] . V_93 [ V_80 ] << ( 8 * V_73 ) ;
if ( V_79 [ 1 ] . V_84 > 4 ) {
for ( V_73 = 0 ; V_73 < V_79 [ 1 ] . V_84 - 4 && V_73 < 4 ; V_73 ++ , V_80 -- )
V_94 |= ( T_2 ) V_79 [ 1 ] . V_93 [ V_80 ] << ( 8 * V_73 ) ;
V_99 = true ;
}
if ( V_99 )
F_34 ( V_94 , V_4 -> V_19 + F_35 ( V_4 ) ) ;
F_14 ( V_4 ) ;
F_34 ( V_81 , V_4 -> V_19 + F_13 ( V_4 ) ) ;
V_66 = F_21 ( V_4 ) ;
if ( V_66 )
goto V_92;
V_81 = F_12 ( V_4 -> V_19 + F_13 ( V_4 ) ) ;
if ( ( V_81 & V_82 ) == 0 )
return F_22 ( V_4 , false ) ;
V_92:
return V_66 ;
}
int F_39 ( struct V_100 * V_12 , struct V_78 * V_79 , int V_101 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
int V_73 , V_66 = 0 ;
if ( V_101 == 1 ) {
if ( V_79 [ 0 ] . V_84 > 0 && V_79 [ 0 ] . V_84 <= 8 ) {
if ( V_79 [ 0 ] . V_88 & V_102 )
V_66 = F_33 ( V_4 , V_79 ) ;
else
V_66 = F_36 ( V_4 , V_79 ) ;
goto V_103;
}
} else if ( V_101 == 2 ) {
if ( ( V_79 [ 0 ] . V_88 & V_102 ) == 0 &&
( V_79 [ 1 ] . V_88 & V_104 ) == 0 &&
V_79 [ 0 ] . V_84 > 0 && V_79 [ 0 ] . V_84 <= 2 &&
V_79 [ 1 ] . V_84 > 0 && V_79 [ 1 ] . V_84 <= 8 &&
V_79 [ 0 ] . V_86 == V_79 [ 1 ] . V_86 ) {
if ( V_79 [ 1 ] . V_88 & V_102 )
V_66 = F_37 ( V_4 , V_79 ) ;
else
V_66 = F_38 ( V_4 , V_79 ) ;
goto V_103;
}
}
for ( V_73 = 0 ; V_66 == 0 && V_73 < V_101 ; V_73 ++ ) {
struct V_78 * V_105 = & V_79 [ V_73 ] ;
if ( ! V_105 -> V_84 ) {
V_66 = - V_53 ;
break;
}
V_66 = F_27 ( V_4 ) ;
if ( V_66 )
return V_66 ;
if ( V_105 -> V_88 & V_102 )
V_66 = F_29 ( V_4 , V_105 -> V_86 , V_105 -> V_93 ,
& V_105 -> V_84 , V_105 -> V_88 & V_104 ) ;
else
V_66 = F_32 ( V_4 , V_105 -> V_86 , V_105 -> V_93 ,
V_105 -> V_84 ) ;
}
F_28 ( V_4 ) ;
V_103:
return ( V_66 != 0 ) ? V_66 : V_101 ;
}
void F_41 ( struct V_3 * V_4 )
{
int V_106 , V_107 , V_108 , V_109 , V_110 , V_111 , V_112 , V_113 ;
int V_114 = 0x18 , V_115 = 2 , V_116 = 0 , V_117 = 1000000 ;
for ( V_111 = 0 ; V_111 < 8 && V_117 != 0 ; V_111 ++ ) {
for ( V_110 = 15 ; V_110 >= 2 && V_117 != 0 ; V_110 -- ) {
V_106 = V_4 -> V_118 * ( V_110 + 1 ) * 10 ;
V_106 *= ( 1 << V_111 ) ;
V_107 = ( V_4 -> V_119 / ( V_106 * 2 ) ) - 1 ;
for ( V_108 = 0 ; V_108 <= 1 ; V_108 ++ ) {
V_109 = V_107 + V_108 ;
if ( V_109 < 5 || V_109 > 0xff )
continue;
V_112 = V_4 -> V_119 / ( 2 * ( V_109 + 1 ) ) ;
V_112 = V_112 / ( 1 << V_111 ) ;
V_112 = V_112 / ( V_110 + 1 ) / 10 ;
V_113 = abs ( V_112 - V_4 -> V_118 ) ;
if ( V_113 < V_117 ) {
V_117 = V_113 ;
V_114 = V_109 ;
V_115 = V_110 ;
V_116 = V_111 ;
}
}
}
}
F_42 ( V_4 , V_120 , V_114 ) ;
F_42 ( V_4 , V_121 , ( V_115 << 3 ) | V_116 ) ;
}
int F_26 ( struct V_3 * V_4 )
{
T_3 V_122 = 0 ;
int V_123 ;
F_42 ( V_4 , V_124 , 0 ) ;
for ( V_123 = 10 ; V_123 && V_122 != V_36 ; V_123 -- ) {
F_19 ( 1 ) ;
V_122 = F_23 ( V_4 ) ;
if ( V_122 == V_36 )
break;
}
if ( V_122 != V_36 ) {
F_10 ( V_4 -> V_18 , L_4 ,
V_29 , V_122 ) ;
return - V_42 ;
}
F_16 ( V_4 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static int F_43 ( struct V_100 * V_12 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
T_2 V_125 ;
V_125 = F_44 ( V_4 ) ;
return V_125 & V_126 ;
}
static void F_45 ( struct V_100 * V_12 , int V_24 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
F_15 ( V_4 , V_24 ? 0 : V_127 ) ;
}
static int F_46 ( struct V_100 * V_12 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
T_2 V_125 ;
V_125 = F_44 ( V_4 ) ;
return V_125 & V_128 ;
}
static void F_47 ( struct V_100 * V_12 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
F_20 ( V_4 ) ;
F_42 ( V_4 , V_124 , 0 ) ;
F_19 ( 5 ) ;
F_17 ( V_4 , V_28 ) ;
F_15 ( V_4 , 0 ) ;
}
static void F_48 ( struct V_100 * V_12 )
{
struct V_3 * V_4 = F_40 ( V_12 ) ;
F_15 ( V_4 , V_129 | V_127 ) ;
F_19 ( 5 ) ;
F_15 ( V_4 , V_129 ) ;
F_19 ( 5 ) ;
F_15 ( V_4 , 0 ) ;
}
