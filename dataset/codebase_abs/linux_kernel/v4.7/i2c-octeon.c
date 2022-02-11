static void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_3 * V_4 , T_1 V_5 , T_3 V_6 )
{
T_1 V_7 ;
F_2 ( V_8 | V_5 | V_6 , V_4 -> V_9 + V_10 ) ;
do {
V_7 = F_3 ( V_4 -> V_9 + V_10 ) ;
} while ( ( V_7 & V_8 ) != 0 );
}
static T_3 F_5 ( struct V_3 * V_4 , T_1 V_5 )
{
T_1 V_7 ;
F_2 ( V_8 | V_5 | V_11 , V_4 -> V_9 + V_10 ) ;
do {
V_7 = F_3 ( V_4 -> V_9 + V_10 ) ;
} while ( ( V_7 & V_8 ) != 0 );
return V_7 & 0xFF ;
}
static T_1 F_6 ( struct V_3 * V_4 )
{
return F_3 ( V_4 -> V_9 + V_12 ) ;
}
static void F_7 ( struct V_3 * V_4 , T_1 V_6 )
{
F_1 ( V_6 , V_4 -> V_9 + V_12 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_7 ( V_4 , V_13 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_7 ( V_4 , 0 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_14 ) ;
F_12 ( V_4 -> V_15 ) ;
}
static void F_13 ( T_4 * V_16 , int V_15 )
{
int V_17 ;
V_17 = F_14 ( V_16 ) ;
if ( V_17 >= 0 )
F_15 ( V_15 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
F_13 ( & V_4 -> V_14 , V_4 -> V_15 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
F_11 ( & V_4 -> V_18 ) ;
F_12 ( V_4 -> V_19 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
F_13 ( & V_4 -> V_18 , V_4 -> V_19 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
int V_20 = 0 ;
T_1 V_1 ;
if ( V_4 -> V_21 )
return;
V_4 -> V_21 = true ;
while ( 1 ) {
V_1 = F_20 ( V_4 ) ;
if ( ! ( V_1 & ( V_22 | V_23 ) ) )
break;
if ( V_1 & V_24 )
F_21 ( V_4 , V_25 ) ;
if ( V_20 ++ > 100 ) {
F_22 ( L_1 , V_26 ) ;
break;
}
F_23 ( 10 ) ;
}
F_21 ( V_4 , V_27 | V_28 | V_25 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_21 )
return;
V_4 -> V_21 = false ;
F_21 ( V_4 , V_25 ) ;
}
static T_5 F_25 ( int V_15 , void * V_29 )
{
struct V_3 * V_4 = V_29 ;
V_4 -> V_30 ( V_4 ) ;
F_26 ( & V_4 -> V_31 ) ;
return V_32 ;
}
static T_5 F_27 ( int V_15 , void * V_29 )
{
struct V_3 * V_4 = V_29 ;
V_4 -> V_33 ( V_4 ) ;
F_26 ( & V_4 -> V_31 ) ;
return V_32 ;
}
static bool F_28 ( struct V_3 * V_4 )
{
return ( F_20 ( V_4 ) & V_24 ) ;
}
static bool F_29 ( struct V_3 * V_4 , bool * V_34 )
{
if ( F_28 ( V_4 ) )
return true ;
if ( * V_34 ) {
* V_34 = false ;
return false ;
}
F_30 ( V_35 , 2 * V_35 ) ;
return F_28 ( V_4 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
long V_36 ;
bool V_34 = 1 ;
if ( V_4 -> V_37 ) {
T_1 V_38 = F_32 () + V_4 -> V_39 . V_40 ;
while ( ! F_28 ( V_4 ) &&
F_33 ( F_32 () , V_38 ) )
F_30 ( V_35 / 2 , V_35 ) ;
return F_28 ( V_4 ) ? 0 : - V_41 ;
}
V_4 -> V_42 ( V_4 ) ;
V_36 = F_34 ( V_4 -> V_31 , F_29 ( V_4 , & V_34 ) ,
V_4 -> V_39 . V_40 ) ;
V_4 -> V_30 ( V_4 ) ;
if ( V_4 -> V_43 && ! V_36 &&
F_28 ( V_4 ) ) {
F_35 ( V_4 -> V_44 , L_2 ) ;
V_4 -> V_37 = true ;
return 0 ;
}
if ( ! V_36 )
return - V_41 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , int V_45 )
{
T_3 V_46 = F_37 ( V_4 ) ;
switch ( V_46 ) {
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
return 0 ;
case V_52 :
if ( ! V_45 )
return 0 ;
return - V_53 ;
case V_54 :
if ( V_45 )
return 0 ;
return - V_53 ;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return - V_59 ;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return - V_64 ;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
return - V_64 ;
case V_72 :
return - V_53 ;
case V_73 :
case V_74 :
case V_75 :
return - V_76 ;
default:
F_35 ( V_4 -> V_44 , L_3 , V_46 ) ;
return - V_53 ;
}
}
static bool F_38 ( struct V_3 * V_4 )
{
return ( F_3 ( V_4 -> V_9 + V_10 ) & V_8 ) == 0 ;
}
static bool F_39 ( struct V_3 * V_4 , bool * V_34 )
{
if ( F_38 ( V_4 ) )
return true ;
if ( * V_34 ) {
* V_34 = false ;
return false ;
}
F_30 ( V_35 , 2 * V_35 ) ;
return F_38 ( V_4 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
F_7 ( V_4 , V_77 ) ;
}
static void F_41 ( struct V_3 * V_4 )
{
F_7 ( V_4 , V_78 | V_79 ) ;
}
static int F_42 ( struct V_3 * V_4 )
{
bool V_34 = 1 ;
int V_36 ;
if ( V_4 -> V_37 ) {
T_1 V_38 = F_32 () + V_4 -> V_39 . V_40 ;
while ( ! F_38 ( V_4 ) &&
F_33 ( F_32 () , V_38 ) )
F_30 ( V_35 / 2 , V_35 ) ;
return F_38 ( V_4 ) ? 0 : - V_41 ;
}
V_4 -> V_80 ( V_4 ) ;
V_36 = F_34 ( V_4 -> V_31 ,
F_39 ( V_4 , & V_34 ) ,
V_4 -> V_39 . V_40 ) ;
V_4 -> V_33 ( V_4 ) ;
if ( ! V_36 )
F_41 ( V_4 ) ;
if ( V_4 -> V_43 && ! V_36 &&
F_38 ( V_4 ) ) {
F_35 ( V_4 -> V_44 , L_2 ) ;
V_4 -> V_37 = true ;
return 0 ;
}
if ( ! V_36 )
return - V_41 ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 , struct V_81 * V_82 )
{
int V_83 , V_84 , V_85 = 0 ;
T_1 V_86 ;
F_19 ( V_4 ) ;
F_41 ( V_4 ) ;
V_86 = V_8 | V_11 | V_87 ;
V_86 |= ( T_1 ) ( V_82 [ 0 ] . V_88 - 1 ) << V_89 ;
V_86 |= ( T_1 ) ( V_82 [ 0 ] . V_2 & 0x7full ) << V_90 ;
if ( V_82 [ 0 ] . V_91 & V_92 )
V_86 |= V_93 ;
else
V_86 |= V_94 ;
F_1 ( V_86 , V_4 -> V_9 + V_10 ) ;
V_85 = F_42 ( V_4 ) ;
if ( V_85 )
goto V_95;
V_86 = F_3 ( V_4 -> V_9 + V_10 ) ;
if ( ( V_86 & V_11 ) == 0 )
return - V_59 ;
for ( V_83 = 0 , V_84 = V_82 [ 0 ] . V_88 - 1 ; V_83 < V_82 [ 0 ] . V_88 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_82 [ 0 ] . V_96 [ V_84 ] = ( V_86 >> ( 8 * V_83 ) ) & 0xff ;
if ( V_82 [ 0 ] . V_88 > 4 ) {
V_86 = F_3 ( V_4 -> V_9 + V_97 ) ;
for ( V_83 = 0 ; V_83 < V_82 [ 0 ] . V_88 - 4 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_82 [ 0 ] . V_96 [ V_84 ] = ( V_86 >> ( 8 * V_83 ) ) & 0xff ;
}
V_95:
return V_85 ;
}
static int F_44 ( struct V_3 * V_4 , struct V_81 * V_82 )
{
int V_83 , V_84 , V_85 = 0 ;
T_1 V_86 ;
F_19 ( V_4 ) ;
F_41 ( V_4 ) ;
V_86 = V_8 | V_87 ;
V_86 |= ( T_1 ) ( V_82 [ 0 ] . V_88 - 1 ) << V_89 ;
V_86 |= ( T_1 ) ( V_82 [ 0 ] . V_2 & 0x7full ) << V_90 ;
if ( V_82 [ 0 ] . V_91 & V_92 )
V_86 |= V_93 ;
else
V_86 |= V_94 ;
for ( V_83 = 0 , V_84 = V_82 [ 0 ] . V_88 - 1 ; V_83 < V_82 [ 0 ] . V_88 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_86 |= ( T_1 ) V_82 [ 0 ] . V_96 [ V_84 ] << ( 8 * V_83 ) ;
if ( V_82 [ 0 ] . V_88 > 4 ) {
T_1 V_98 = 0 ;
for ( V_83 = 0 ; V_83 < V_82 [ 0 ] . V_88 - 4 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_98 |= ( T_1 ) V_82 [ 0 ] . V_96 [ V_84 ] << ( 8 * V_83 ) ;
F_1 ( V_98 , V_4 -> V_9 + V_97 ) ;
}
F_1 ( V_86 , V_4 -> V_9 + V_10 ) ;
V_85 = F_42 ( V_4 ) ;
if ( V_85 )
goto V_95;
V_86 = F_3 ( V_4 -> V_9 + V_10 ) ;
if ( ( V_86 & V_11 ) == 0 )
return - V_59 ;
V_85 = F_36 ( V_4 , false ) ;
V_95:
return V_85 ;
}
static int F_45 ( struct V_3 * V_4 , struct V_81 * V_82 )
{
int V_83 , V_84 , V_85 = 0 ;
T_1 V_86 ;
F_19 ( V_4 ) ;
V_86 = V_8 | V_11 | V_87 ;
V_86 |= ( T_1 ) ( V_82 [ 1 ] . V_88 - 1 ) << V_89 ;
V_86 |= ( T_1 ) ( V_82 [ 0 ] . V_2 & 0x7full ) << V_90 ;
if ( V_82 [ 0 ] . V_91 & V_92 )
V_86 |= V_99 ;
else
V_86 |= V_100 ;
if ( V_82 [ 0 ] . V_88 == 2 ) {
T_1 V_98 = 0 ;
V_86 |= V_101 ;
V_98 = ( T_1 ) V_82 [ 0 ] . V_96 [ 0 ] << V_102 ;
V_86 |= ( T_1 ) V_82 [ 0 ] . V_96 [ 1 ] << V_102 ;
F_1 ( V_98 , V_4 -> V_9 + V_97 ) ;
} else {
V_86 |= ( T_1 ) V_82 [ 0 ] . V_96 [ 0 ] << V_102 ;
}
F_41 ( V_4 ) ;
F_1 ( V_86 , V_4 -> V_9 + V_10 ) ;
V_85 = F_42 ( V_4 ) ;
if ( V_85 )
goto V_95;
V_86 = F_3 ( V_4 -> V_9 + V_10 ) ;
if ( ( V_86 & V_11 ) == 0 )
return - V_59 ;
for ( V_83 = 0 , V_84 = V_82 [ 1 ] . V_88 - 1 ; V_83 < V_82 [ 1 ] . V_88 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_82 [ 1 ] . V_96 [ V_84 ] = ( V_86 >> ( 8 * V_83 ) ) & 0xff ;
if ( V_82 [ 1 ] . V_88 > 4 ) {
V_86 = F_3 ( V_4 -> V_9 + V_97 ) ;
for ( V_83 = 0 ; V_83 < V_82 [ 1 ] . V_88 - 4 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_82 [ 1 ] . V_96 [ V_84 ] = ( V_86 >> ( 8 * V_83 ) ) & 0xff ;
}
V_95:
return V_85 ;
}
static int F_46 ( struct V_3 * V_4 , struct V_81 * V_82 )
{
bool V_103 = false ;
int V_83 , V_84 , V_85 = 0 ;
T_1 V_86 , V_98 = 0 ;
F_19 ( V_4 ) ;
V_86 = V_8 | V_87 ;
V_86 |= ( T_1 ) ( V_82 [ 1 ] . V_88 - 1 ) << V_89 ;
V_86 |= ( T_1 ) ( V_82 [ 0 ] . V_2 & 0x7full ) << V_90 ;
if ( V_82 [ 0 ] . V_91 & V_92 )
V_86 |= V_99 ;
else
V_86 |= V_100 ;
if ( V_82 [ 0 ] . V_88 == 2 ) {
V_86 |= V_101 ;
V_98 |= ( T_1 ) V_82 [ 0 ] . V_96 [ 0 ] << V_102 ;
V_103 = true ;
V_86 |= ( T_1 ) V_82 [ 0 ] . V_96 [ 1 ] << V_102 ;
} else {
V_86 |= ( T_1 ) V_82 [ 0 ] . V_96 [ 0 ] << V_102 ;
}
for ( V_83 = 0 , V_84 = V_82 [ 1 ] . V_88 - 1 ; V_83 < V_82 [ 1 ] . V_88 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_86 |= ( T_1 ) V_82 [ 1 ] . V_96 [ V_84 ] << ( 8 * V_83 ) ;
if ( V_82 [ 1 ] . V_88 > 4 ) {
for ( V_83 = 0 ; V_83 < V_82 [ 1 ] . V_88 - 4 && V_83 < 4 ; V_83 ++ , V_84 -- )
V_98 |= ( T_1 ) V_82 [ 1 ] . V_96 [ V_84 ] << ( 8 * V_83 ) ;
V_103 = true ;
}
if ( V_103 )
F_1 ( V_98 , V_4 -> V_9 + V_97 ) ;
F_41 ( V_4 ) ;
F_1 ( V_86 , V_4 -> V_9 + V_10 ) ;
V_85 = F_42 ( V_4 ) ;
if ( V_85 )
goto V_95;
V_86 = F_3 ( V_4 -> V_9 + V_10 ) ;
if ( ( V_86 & V_11 ) == 0 )
return - V_59 ;
V_85 = F_36 ( V_4 , false ) ;
V_95:
return V_85 ;
}
static void F_47 ( struct V_3 * V_4 )
{
int V_104 , V_105 , V_106 , V_107 , V_108 , V_109 , V_110 , V_111 ;
int V_112 = 0x18 , V_113 = 2 , V_114 = 0 , V_115 = 1000000 ;
for ( V_109 = 0 ; V_109 < 8 && V_115 != 0 ; V_109 ++ ) {
for ( V_108 = 15 ; V_108 >= 2 && V_115 != 0 ; V_108 -- ) {
V_104 = V_4 -> V_116 * ( V_108 + 1 ) * 10 ;
V_104 *= ( 1 << V_109 ) ;
V_105 = ( V_4 -> V_117 / ( V_104 * 2 ) ) - 1 ;
for ( V_106 = 0 ; V_106 <= 1 ; V_106 ++ ) {
V_107 = V_105 + V_106 ;
if ( V_107 < 5 || V_107 > 0xff )
continue;
V_110 = V_4 -> V_117 / ( 2 * ( V_107 + 1 ) ) ;
V_110 = V_110 / ( 1 << V_109 ) ;
V_110 = V_110 / ( V_108 + 1 ) / 10 ;
V_111 = abs ( V_110 - V_4 -> V_116 ) ;
if ( V_111 < V_115 ) {
V_115 = V_111 ;
V_112 = V_107 ;
V_113 = V_108 ;
V_114 = V_109 ;
}
}
}
}
F_4 ( V_4 , V_118 , V_112 ) ;
F_4 ( V_4 , V_119 , ( V_113 << 3 ) | V_114 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
T_3 V_120 = 0 ;
int V_121 ;
F_4 ( V_4 , V_122 , 0 ) ;
for ( V_121 = 10 ; V_121 && V_120 != V_47 ; V_121 -- ) {
F_23 ( 1 ) ;
V_120 = F_37 ( V_4 ) ;
if ( V_120 == V_47 )
break;
}
if ( V_120 != V_47 ) {
F_35 ( V_4 -> V_44 , L_4 ,
V_26 , V_120 ) ;
return - V_53 ;
}
F_19 ( V_4 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 )
{
int V_85 ;
V_85 = F_50 ( & V_4 -> V_39 ) ;
if ( V_85 )
V_85 = F_48 ( V_4 ) ;
return V_85 ;
}
static int F_51 ( struct V_3 * V_4 )
{
int V_85 ;
T_3 V_46 ;
F_24 ( V_4 ) ;
F_21 ( V_4 , V_25 | V_22 ) ;
V_85 = F_31 ( V_4 ) ;
if ( V_85 )
goto error;
V_46 = F_37 ( V_4 ) ;
if ( V_46 == V_123 || V_46 == V_124 )
return 0 ;
error:
V_85 = F_49 ( V_4 ) ;
return ( V_85 ) ? V_85 : - V_59 ;
}
static void F_52 ( struct V_3 * V_4 )
{
F_21 ( V_4 , V_25 | V_23 ) ;
}
static int F_53 ( struct V_3 * V_4 , int V_125 ,
const T_3 * V_6 , int V_126 )
{
int V_83 , V_127 ;
F_54 ( V_4 , V_125 << 1 ) ;
F_21 ( V_4 , V_25 ) ;
V_127 = F_31 ( V_4 ) ;
if ( V_127 )
return V_127 ;
for ( V_83 = 0 ; V_83 < V_126 ; V_83 ++ ) {
V_127 = F_36 ( V_4 , false ) ;
if ( V_127 )
return V_127 ;
F_54 ( V_4 , V_6 [ V_83 ] ) ;
F_21 ( V_4 , V_25 ) ;
V_127 = F_31 ( V_4 ) ;
if ( V_127 )
return V_127 ;
}
return 0 ;
}
static int F_55 ( struct V_3 * V_4 , int V_125 ,
T_3 * V_6 , T_6 * V_128 , bool V_129 )
{
int V_83 , V_127 , V_126 = * V_128 ;
bool V_45 = false ;
F_54 ( V_4 , ( V_125 << 1 ) | 1 ) ;
F_21 ( V_4 , V_25 ) ;
V_127 = F_31 ( V_4 ) ;
if ( V_127 )
return V_127 ;
V_127 = F_36 ( V_4 , false ) ;
if ( V_127 )
return V_127 ;
for ( V_83 = 0 ; V_83 < V_126 ; V_83 ++ ) {
if ( ( V_83 + 1 == V_126 ) && ! ( V_129 && V_83 == 0 ) )
V_45 = true ;
if ( V_45 )
F_21 ( V_4 , V_25 ) ;
else
F_21 ( V_4 , V_25 | V_28 ) ;
V_127 = F_31 ( V_4 ) ;
if ( V_127 )
return V_127 ;
V_6 [ V_83 ] = F_56 ( V_4 ) ;
if ( V_129 && V_83 == 0 ) {
if ( V_6 [ V_83 ] > V_130 + 1 )
return - V_131 ;
V_126 += V_6 [ V_83 ] ;
}
V_127 = F_36 ( V_4 , V_45 ) ;
if ( V_127 )
return V_127 ;
}
* V_128 = V_126 ;
return 0 ;
}
static int F_57 ( struct V_132 * V_39 , struct V_81 * V_82 ,
int V_133 )
{
struct V_3 * V_4 = F_58 ( V_39 ) ;
int V_83 , V_85 = 0 ;
if ( V_133 == 1 ) {
if ( V_82 [ 0 ] . V_88 > 0 && V_82 [ 0 ] . V_88 <= 8 ) {
if ( V_82 [ 0 ] . V_91 & V_134 )
V_85 = F_43 ( V_4 , V_82 ) ;
else
V_85 = F_44 ( V_4 , V_82 ) ;
goto V_135;
}
} else if ( V_133 == 2 ) {
if ( ( V_82 [ 0 ] . V_91 & V_134 ) == 0 &&
( V_82 [ 1 ] . V_91 & V_136 ) == 0 &&
V_82 [ 0 ] . V_88 > 0 && V_82 [ 0 ] . V_88 <= 2 &&
V_82 [ 1 ] . V_88 > 0 && V_82 [ 1 ] . V_88 <= 8 &&
V_82 [ 0 ] . V_2 == V_82 [ 1 ] . V_2 ) {
if ( V_82 [ 1 ] . V_91 & V_134 )
V_85 = F_45 ( V_4 , V_82 ) ;
else
V_85 = F_46 ( V_4 , V_82 ) ;
goto V_135;
}
}
for ( V_83 = 0 ; V_85 == 0 && V_83 < V_133 ; V_83 ++ ) {
struct V_81 * V_137 = & V_82 [ V_83 ] ;
if ( ! V_137 -> V_88 ) {
V_85 = - V_64 ;
break;
}
V_85 = F_51 ( V_4 ) ;
if ( V_85 )
return V_85 ;
if ( V_137 -> V_91 & V_134 )
V_85 = F_55 ( V_4 , V_137 -> V_2 , V_137 -> V_96 ,
& V_137 -> V_88 , V_137 -> V_91 & V_136 ) ;
else
V_85 = F_53 ( V_4 , V_137 -> V_2 , V_137 -> V_96 ,
V_137 -> V_88 ) ;
}
F_52 ( V_4 ) ;
V_135:
return ( V_85 != 0 ) ? V_85 : V_133 ;
}
static int F_59 ( struct V_132 * V_39 )
{
struct V_3 * V_4 = F_58 ( V_39 ) ;
T_1 V_138 ;
V_138 = F_6 ( V_4 ) ;
return V_138 & V_139 ;
}
static void F_60 ( struct V_132 * V_39 , int V_1 )
{
struct V_3 * V_4 = F_58 ( V_39 ) ;
F_7 ( V_4 , V_140 ) ;
}
static int F_61 ( struct V_132 * V_39 )
{
struct V_3 * V_4 = F_58 ( V_39 ) ;
T_1 V_138 ;
V_138 = F_6 ( V_4 ) ;
return V_138 & V_141 ;
}
static void F_62 ( struct V_132 * V_39 )
{
struct V_3 * V_4 = F_58 ( V_39 ) ;
F_52 ( V_4 ) ;
F_24 ( V_4 ) ;
F_7 ( V_4 , 0 ) ;
}
static void F_63 ( struct V_132 * V_39 )
{
struct V_3 * V_4 = F_58 ( V_39 ) ;
F_7 ( V_4 , 0 ) ;
}
static T_7 F_64 ( struct V_132 * V_39 )
{
return V_142 | ( V_143 & ~ V_144 ) |
V_145 | V_146 ;
}
static int F_65 ( struct V_147 * V_148 )
{
struct V_149 * V_150 = V_148 -> V_44 . V_151 ;
int V_15 , V_127 = 0 , V_19 = 0 ;
struct V_152 * V_153 ;
struct V_3 * V_4 ;
bool V_154 ;
V_154 = F_66 ( V_150 , L_5 ) ;
if ( V_154 ) {
V_19 = F_67 ( V_148 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_15 = F_67 ( V_148 , 2 ) ;
if ( V_15 < 0 )
return V_15 ;
} else {
V_15 = F_67 ( V_148 , 0 ) ;
if ( V_15 < 0 )
return V_15 ;
}
V_4 = F_68 ( & V_148 -> V_44 , sizeof( * V_4 ) , V_155 ) ;
if ( ! V_4 ) {
V_127 = - V_156 ;
goto V_135;
}
V_4 -> V_44 = & V_148 -> V_44 ;
V_153 = F_69 ( V_148 , V_157 , 0 ) ;
V_4 -> V_9 = F_70 ( & V_148 -> V_44 , V_153 ) ;
if ( F_71 ( V_4 -> V_9 ) ) {
V_127 = F_72 ( V_4 -> V_9 ) ;
goto V_135;
}
if ( F_73 ( V_150 , L_6 , & V_4 -> V_116 ) &&
F_73 ( V_150 , L_7 , & V_4 -> V_116 ) ) {
F_35 ( V_4 -> V_44 ,
L_8 ) ;
V_127 = - V_76 ;
goto V_135;
}
V_4 -> V_117 = F_74 () ;
F_75 ( & V_4 -> V_31 ) ;
V_4 -> V_15 = V_15 ;
if ( V_154 ) {
V_4 -> V_19 = V_19 ;
V_4 -> V_42 = F_10 ;
V_4 -> V_30 = F_16 ;
V_4 -> V_80 = F_17 ;
V_4 -> V_33 = F_18 ;
F_76 ( V_4 -> V_15 , V_158 ) ;
F_76 ( V_4 -> V_19 , V_158 ) ;
V_127 = F_77 ( & V_148 -> V_44 , V_4 -> V_19 ,
F_27 , 0 ,
V_159 , V_4 ) ;
if ( V_127 < 0 ) {
F_35 ( V_4 -> V_44 , L_9 ) ;
goto V_135;
}
} else {
V_4 -> V_42 = F_8 ;
V_4 -> V_30 = F_9 ;
V_4 -> V_80 = F_40 ;
V_4 -> V_33 = F_9 ;
}
V_127 = F_77 ( & V_148 -> V_44 , V_4 -> V_15 ,
F_25 , 0 , V_159 , V_4 ) ;
if ( V_127 < 0 ) {
F_35 ( V_4 -> V_44 , L_9 ) ;
goto V_135;
}
if ( F_78 ( V_160 ) )
V_4 -> V_43 = true ;
V_127 = F_48 ( V_4 ) ;
if ( V_127 ) {
F_35 ( V_4 -> V_44 , L_10 ) ;
goto V_135;
}
F_47 ( V_4 ) ;
V_4 -> V_39 = V_161 ;
V_4 -> V_39 . V_40 = F_79 ( 2 ) ;
V_4 -> V_39 . V_162 = 5 ;
V_4 -> V_39 . V_163 = & V_164 ;
V_4 -> V_39 . V_44 . V_165 = & V_148 -> V_44 ;
V_4 -> V_39 . V_44 . V_151 = V_150 ;
F_80 ( & V_4 -> V_39 , V_4 ) ;
F_81 ( V_148 , V_4 ) ;
V_127 = F_82 ( & V_4 -> V_39 ) ;
if ( V_127 < 0 ) {
F_35 ( V_4 -> V_44 , L_11 ) ;
goto V_135;
}
F_83 ( V_4 -> V_44 , L_12 ) ;
return 0 ;
V_135:
return V_127 ;
}
static int F_84 ( struct V_147 * V_148 )
{
struct V_3 * V_4 = F_85 ( V_148 ) ;
F_86 ( & V_4 -> V_39 ) ;
return 0 ;
}
