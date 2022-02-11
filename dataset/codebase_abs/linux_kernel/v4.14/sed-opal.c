static const char * F_1 ( int error )
{
if ( error == 0x3f )
return L_1 ;
if ( error >= F_2 ( V_1 ) || error < 0 )
return L_2 ;
return V_1 [ error ] ;
}
static void F_3 ( const T_1 * V_2 , T_2 V_3 )
{
#ifdef F_4
F_5 ( L_3 , V_4 , V_2 , V_3 ) ;
F_6 ( L_4 ) ;
#endif
}
static bool F_7 ( const void * V_5 )
{
const struct V_6 * V_7 = V_5 ;
T_1 V_8 = V_7 -> V_9 ;
if ( ! ( V_8 & V_10 ) ) {
F_6 ( L_5 ,
V_7 -> V_9 ) ;
return false ;
}
return true ;
}
static bool F_8 ( const void * V_5 )
{
const struct V_11 * V_12 = V_5 ;
T_1 V_13 = V_12 -> V_9 ;
return ! ! ( V_13 & V_14 ) ;
}
static bool F_9 ( const void * V_5 )
{
const struct V_15 * V_16 = V_5 ;
T_2 V_17 = F_10 ( V_16 -> V_18 ) ;
if ( V_17 == 0 ) {
F_6 ( L_6 ) ;
return false ;
}
F_6 ( L_7 , V_17 ) ;
return true ;
}
static T_3 F_11 ( const void * V_5 )
{
const struct V_19 * V_20 = V_5 ;
return F_12 ( V_20 -> V_21 ) ;
}
static T_3 F_13 ( const void * V_5 )
{
const struct V_22 * V_23 = V_5 ;
return F_12 ( V_23 -> V_21 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
return V_25 -> V_26 ( V_25 -> V_5 , V_25 -> V_27 , V_28 ,
V_25 -> V_29 , V_30 ,
true ) ;
}
static int F_15 ( struct V_24 * V_25 )
{
return V_25 -> V_26 ( V_25 -> V_5 , V_25 -> V_27 , V_28 ,
V_25 -> V_31 , V_30 ,
false ) ;
}
static int F_16 ( struct V_24 * V_25 )
{
T_4 V_32 = V_30 ;
void * V_33 = V_25 -> V_31 ;
struct V_34 * V_35 = V_33 ;
int V_36 ;
do {
F_6 ( L_8 ,
V_35 -> V_37 . V_38 ,
V_35 -> V_37 . V_39 ) ;
if ( V_35 -> V_37 . V_38 == 0 ||
V_35 -> V_37 . V_39 != 0 )
return 0 ;
memset ( V_33 , 0 , V_32 ) ;
V_36 = F_15 ( V_25 ) ;
} while ( ! V_36 );
return V_36 ;
}
static int F_17 ( struct V_24 * V_25 , T_5 * V_40 )
{
int V_36 ;
V_36 = F_14 ( V_25 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_15 ( V_25 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_16 ( V_25 ) ;
if ( V_36 )
return V_36 ;
return V_40 ( V_25 ) ;
}
static void F_18 ( struct V_24 * V_25 , const void * V_5 )
{
const struct V_41 * V_42 = V_5 ;
V_25 -> V_43 = V_42 -> V_44 ;
V_25 -> V_45 = V_42 -> V_46 ;
}
static int F_19 ( struct V_24 * V_25 )
{
const struct V_47 * V_48 ;
int V_49 = 0 , error = 0 ;
do {
V_48 = & V_25 -> V_50 [ V_49 ] ;
if ( ! V_48 -> V_51 )
break;
error = V_48 -> V_51 ( V_25 , V_48 -> V_5 ) ;
if ( error ) {
F_6 ( L_9 ,
V_49 , error ,
F_1 ( error ) ) ;
if ( V_49 > 1 ) {
F_20 ( V_25 ) ;
return error ;
}
}
V_49 ++ ;
} while ( ! error );
return error ;
}
static int F_21 ( struct V_24 * V_25 )
{
bool V_52 = false , V_53 = true , V_54 = false ;
const struct V_55 * V_35 = (struct V_55 * ) V_25 -> V_31 ;
const T_1 * V_56 = V_25 -> V_31 , * V_57 = V_25 -> V_31 ;
T_3 V_27 = 0 ;
T_2 V_58 = F_10 ( V_35 -> V_3 ) ;
F_3 ( V_25 -> V_31 , V_58 ) ;
V_25 -> V_59 = false ;
if ( V_58 > V_30 - sizeof( * V_35 ) ) {
F_6 ( L_10 ,
sizeof( * V_35 ) , V_58 , V_30 ) ;
return - V_60 ;
}
V_56 += V_58 ;
V_57 += sizeof( * V_35 ) ;
while ( V_57 < V_56 && V_53 ) {
const struct V_61 * V_62 =
( const struct V_61 * ) V_57 ;
switch ( F_12 ( V_62 -> V_63 ) ) {
case V_64 :
V_53 = F_7 ( V_62 -> V_65 ) ;
break;
case V_66 :
V_54 = F_9 ( V_62 -> V_65 ) ;
break;
case V_67 :
F_18 ( V_25 , V_62 ) ;
break;
case V_68 :
V_25 -> V_59 = F_8 ( V_62 -> V_65 ) ;
break;
case V_69 :
case V_70 :
F_6 ( L_11 ,
F_12 ( V_62 -> V_63 ) ) ;
break;
case V_71 :
V_27 = F_11 ( V_62 -> V_65 ) ;
V_52 = true ;
break;
case V_72 :
V_27 = F_13 ( V_62 -> V_65 ) ;
V_52 = true ;
break;
case 0xbfff ... 0xffff :
break;
default:
F_6 ( L_12 ,
F_12 ( V_62 -> V_63 ) ) ;
}
V_57 += V_62 -> V_3 + 4 ;
}
if ( ! V_53 ) {
F_6 ( L_13 ) ;
return - V_73 ;
}
if ( ! V_54 )
F_6 ( L_14 ) ;
if ( ! V_52 ) {
F_6 ( L_15 ) ;
return - V_73 ; ;
}
V_25 -> V_27 = V_27 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 , void * V_5 )
{
int V_36 ;
memset ( V_25 -> V_31 , 0 , V_30 ) ;
V_25 -> V_27 = V_74 ;
V_36 = F_15 ( V_25 ) ;
if ( V_36 )
return V_36 ;
return F_21 ( V_25 ) ;
}
static void F_23 ( int * V_75 , struct V_24 * V_29 , T_1 V_76 )
{
if ( * V_75 )
return;
if ( V_29 -> V_77 >= V_30 - 1 ) {
F_6 ( L_16 ) ;
* V_75 = - V_78 ;
return;
}
V_29 -> V_29 [ V_29 -> V_77 ++ ] = V_76 ;
}
static void F_24 ( struct V_24 * V_29 , bool V_79 ,
bool V_80 , int V_81 )
{
T_1 V_82 ;
int V_75 = 0 ;
V_82 = V_83 ;
V_82 |= V_79 ? V_84 : 0 ;
V_82 |= V_80 ? V_85 : 0 ;
V_82 |= V_81 & V_86 ;
F_23 ( & V_75 , V_29 , V_82 ) ;
}
static void F_25 ( struct V_24 * V_29 , bool V_79 ,
bool V_80 , int V_81 )
{
T_1 V_87 ;
V_87 = V_88 ;
V_87 |= V_79 ? V_89 : 0 ;
V_87 |= V_80 ? V_90 : 0 ;
V_87 |= ( V_81 >> 8 ) & V_91 ;
V_29 -> V_29 [ V_29 -> V_77 ++ ] = V_87 ;
V_29 -> V_29 [ V_29 -> V_77 ++ ] = V_81 ;
}
static void F_26 ( int * V_75 , struct V_24 * V_29 , T_6 V_92 )
{
T_4 V_81 ;
int V_93 ;
T_1 V_94 ;
if ( ! ( V_92 & ~ V_95 ) ) {
F_23 ( V_75 , V_29 , V_92 ) ;
return;
}
V_93 = F_27 ( V_92 ) ;
V_81 = F_28 ( V_93 , 4 ) ;
if ( V_29 -> V_77 >= V_30 - V_81 - 1 ) {
F_6 ( L_17 ) ;
* V_75 = - V_78 ;
return;
}
F_24 ( V_29 , false , false , V_81 ) ;
while ( V_81 -- ) {
V_94 = V_92 >> ( V_81 * 8 ) ;
F_23 ( V_75 , V_29 , V_94 ) ;
}
}
static void F_29 ( int * V_75 , struct V_24 * V_29 ,
const T_1 * V_79 , T_4 V_81 )
{
T_4 V_96 = 1 ;
bool V_97 = true ;
if ( * V_75 )
return;
if ( V_81 & ~ V_86 ) {
V_96 = 2 ;
V_97 = false ;
}
if ( V_81 >= V_30 - V_29 -> V_77 - V_96 ) {
F_6 ( L_18 ) ;
* V_75 = - V_78 ;
return;
}
if ( V_97 )
F_24 ( V_29 , true , false , V_81 ) ;
else
F_25 ( V_29 , true , false , V_81 ) ;
memcpy ( & V_29 -> V_29 [ V_29 -> V_77 ] , V_79 , V_81 ) ;
V_29 -> V_77 += V_81 ;
}
static int F_30 ( T_1 * V_33 , T_4 V_3 , T_1 V_98 )
{
if ( V_3 > V_99 ) {
F_6 ( L_19 ) ;
return - V_78 ;
}
memcpy ( V_33 , V_100 [ V_101 ] , V_99 ) ;
if ( V_98 == 0 )
return 0 ;
V_33 [ 5 ] = V_102 ;
V_33 [ 7 ] = V_98 ;
return 0 ;
}
static int F_31 ( T_1 * V_33 , T_4 V_3 , T_1 V_98 )
{
if ( V_3 > V_99 ) {
F_6 ( L_20 ) ;
return - V_78 ;
}
memcpy ( V_33 , V_100 [ V_103 ] , V_99 ) ;
V_33 [ 7 ] = V_98 + 1 ;
return 0 ;
}
static void F_32 ( struct V_24 * V_29 , T_3 V_27 )
{
struct V_34 * V_35 = (struct V_34 * ) V_29 -> V_29 ;
V_35 -> V_37 . V_104 [ 0 ] = V_27 >> 8 ;
V_35 -> V_37 . V_104 [ 1 ] = V_27 ;
V_35 -> V_37 . V_104 [ 2 ] = 0 ;
V_35 -> V_37 . V_104 [ 3 ] = 0 ;
}
static int F_33 ( struct V_24 * V_29 , T_2 V_105 , T_2 V_106 )
{
struct V_34 * V_35 ;
int V_75 = 0 ;
F_23 ( & V_75 , V_29 , V_107 ) ;
F_23 ( & V_75 , V_29 , V_108 ) ;
F_23 ( & V_75 , V_29 , 0 ) ;
F_23 ( & V_75 , V_29 , 0 ) ;
F_23 ( & V_75 , V_29 , 0 ) ;
F_23 ( & V_75 , V_29 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_21 ) ;
return - V_60 ;
}
V_35 = (struct V_34 * ) V_29 -> V_29 ;
V_35 -> V_110 . V_106 = F_34 ( V_106 ) ;
V_35 -> V_110 . V_105 = F_34 ( V_105 ) ;
V_35 -> V_111 . V_3 = F_34 ( V_29 -> V_77 - sizeof( * V_35 ) ) ;
while ( V_29 -> V_77 % 4 ) {
if ( V_29 -> V_77 >= V_30 ) {
F_6 ( L_22 ) ;
return - V_78 ;
}
V_29 -> V_29 [ V_29 -> V_77 ++ ] = 0 ;
}
V_35 -> V_110 . V_3 = F_34 ( V_29 -> V_77 - sizeof( V_35 -> V_37 ) -
sizeof( V_35 -> V_110 ) ) ;
V_35 -> V_37 . V_3 = F_34 ( V_29 -> V_77 - sizeof( V_35 -> V_37 ) ) ;
return 0 ;
}
static const struct V_112 * F_35 (
const struct V_113 * V_31 ,
int V_94 )
{
const struct V_112 * V_76 ;
if ( V_94 >= V_31 -> V_114 ) {
F_6 ( L_23 ,
V_94 , V_31 -> V_114 ) ;
return F_36 ( - V_115 ) ;
}
V_76 = & V_31 -> V_116 [ V_94 ] ;
if ( V_76 -> V_81 == 0 ) {
F_6 ( L_24 ) ;
return F_36 ( - V_115 ) ;
}
return V_76 ;
}
static T_7 F_37 ( struct V_112 * V_76 ,
const T_1 * V_77 )
{
V_76 -> V_77 = V_77 ;
V_76 -> V_81 = 1 ;
V_76 -> V_117 = V_118 ;
if ( V_77 [ 0 ] & V_119 ) {
V_76 -> type = V_120 ;
} else {
V_76 -> type = V_121 ;
V_76 -> V_122 . V_123 = V_77 [ 0 ] & 0x3f ;
}
return V_76 -> V_81 ;
}
static T_7 F_38 ( struct V_112 * V_76 ,
const T_1 * V_77 )
{
V_76 -> V_77 = V_77 ;
V_76 -> V_81 = ( V_77 [ 0 ] & V_86 ) + 1 ;
V_76 -> V_117 = V_124 ;
if ( V_77 [ 0 ] & V_84 ) {
V_76 -> type = V_125 ;
} else if ( V_77 [ 0 ] & V_85 ) {
V_76 -> type = V_120 ;
} else {
T_6 V_126 = 0 ;
T_7 V_127 , V_128 = 0 ;
V_76 -> type = V_121 ;
if ( V_76 -> V_81 > 9 ) {
F_6 ( L_25 ) ;
return - V_115 ;
}
for ( V_127 = V_76 -> V_81 - 1 ; V_127 > 0 ; V_127 -- ) {
V_126 |= ( ( T_6 ) V_77 [ V_127 ] << ( 8 * V_128 ) ) ;
V_128 ++ ;
}
V_76 -> V_122 . V_123 = V_126 ;
}
return V_76 -> V_81 ;
}
static T_7 F_39 ( struct V_112 * V_76 ,
const T_1 * V_77 )
{
V_76 -> V_77 = V_77 ;
V_76 -> V_81 = ( ( ( V_77 [ 0 ] & V_91 ) << 8 ) | V_77 [ 1 ] ) + 2 ;
V_76 -> V_117 = V_129 ;
if ( V_77 [ 0 ] & V_89 )
V_76 -> type = V_125 ;
else if ( V_77 [ 0 ] & V_90 )
V_76 -> type = V_120 ;
else
V_76 -> type = V_121 ;
return V_76 -> V_81 ;
}
static T_7 F_40 ( struct V_112 * V_76 ,
const T_1 * V_77 )
{
V_76 -> V_77 = V_77 ;
V_76 -> V_81 = ( ( V_77 [ 1 ] << 16 ) | ( V_77 [ 2 ] << 8 ) | V_77 [ 3 ] ) + 4 ;
V_76 -> V_117 = V_130 ;
if ( V_77 [ 0 ] & V_131 )
V_76 -> type = V_125 ;
else if ( V_77 [ 0 ] & V_132 )
V_76 -> type = V_120 ;
else
V_76 -> type = V_121 ;
return V_76 -> V_81 ;
}
static T_7 F_41 ( struct V_112 * V_76 ,
const T_1 * V_77 )
{
V_76 -> V_77 = V_77 ;
V_76 -> V_81 = 1 ;
V_76 -> type = V_133 ;
V_76 -> V_117 = V_134 ;
return V_76 -> V_81 ;
}
static int F_42 ( const T_1 * V_135 , T_4 V_3 ,
struct V_113 * V_31 )
{
const struct V_34 * V_35 ;
struct V_112 * V_136 ;
int V_137 = 0 ;
int V_138 ;
T_7 V_139 ;
const T_1 * V_77 ;
T_2 V_140 , V_141 , V_142 ;
if ( ! V_135 )
return - V_60 ;
if ( ! V_31 )
return - V_60 ;
V_35 = (struct V_34 * ) V_135 ;
V_77 = V_135 ;
V_77 += sizeof( * V_35 ) ;
V_140 = F_10 ( V_35 -> V_37 . V_3 ) ;
V_141 = F_10 ( V_35 -> V_110 . V_3 ) ;
V_142 = F_10 ( V_35 -> V_111 . V_3 ) ;
F_6 ( L_26 ,
V_140 , V_141 , V_142 ) ;
if ( V_140 == 0 || V_141 == 0 || V_142 == 0 ||
V_142 > V_30 - sizeof( * V_35 ) ) {
F_6 ( L_27 ,
V_140 , V_141 , V_142 ) ;
F_3 ( V_77 , sizeof( * V_35 ) ) ;
return - V_115 ;
}
if ( V_77 > V_135 + V_3 )
return - V_60 ;
V_136 = V_31 -> V_116 ;
V_138 = V_142 ;
F_3 ( V_77 , V_138 ) ;
while ( V_138 > 0 ) {
if ( V_77 [ 0 ] <= V_143 )
V_139 = F_37 ( V_136 , V_77 ) ;
else if ( V_77 [ 0 ] <= V_144 )
V_139 = F_38 ( V_136 , V_77 ) ;
else if ( V_77 [ 0 ] <= V_145 )
V_139 = F_39 ( V_136 , V_77 ) ;
else if ( V_77 [ 0 ] <= V_146 )
V_139 = F_40 ( V_136 , V_77 ) ;
else
V_139 = F_41 ( V_136 , V_77 ) ;
if ( V_139 < 0 )
return V_139 ;
V_77 += V_139 ;
V_138 -= V_139 ;
V_136 ++ ;
V_137 ++ ;
}
if ( V_137 == 0 ) {
F_6 ( L_28 ) ;
return - V_115 ;
}
V_31 -> V_114 = V_137 ;
return 0 ;
}
static T_4 F_43 ( const struct V_113 * V_31 , int V_94 ,
const char * * V_147 )
{
* V_147 = NULL ;
if ( ! V_31 ) {
F_6 ( L_29 ) ;
return 0 ;
}
if ( V_94 > V_31 -> V_114 ) {
F_6 ( L_30 ,
V_31 -> V_114 , V_94 ) ;
return 0 ;
}
if ( V_31 -> V_116 [ V_94 ] . type != V_125 ) {
F_6 ( L_31 ) ;
return 0 ;
}
* V_147 = V_31 -> V_116 [ V_94 ] . V_77 + 1 ;
return V_31 -> V_116 [ V_94 ] . V_81 - 1 ;
}
static T_6 F_44 ( const struct V_113 * V_31 , int V_94 )
{
if ( ! V_31 ) {
F_6 ( L_29 ) ;
return 0 ;
}
if ( V_94 > V_31 -> V_114 ) {
F_6 ( L_30 ,
V_31 -> V_114 , V_94 ) ;
return 0 ;
}
if ( V_31 -> V_116 [ V_94 ] . type != V_121 ) {
F_6 ( L_32 ,
V_31 -> V_116 [ V_94 ] . type ) ;
return 0 ;
}
if ( ! ( V_31 -> V_116 [ V_94 ] . V_117 == V_118 ||
V_31 -> V_116 [ V_94 ] . V_117 == V_124 ) ) {
F_6 ( L_33 ,
V_31 -> V_116 [ V_94 ] . V_117 ) ;
return 0 ;
}
return V_31 -> V_116 [ V_94 ] . V_122 . V_123 ;
}
static bool F_45 ( const struct V_112 * V_148 , T_1 V_149 )
{
if ( F_46 ( V_148 ) ||
V_148 -> type != V_133 ||
V_148 -> V_77 [ 0 ] != V_149 )
return false ;
return true ;
}
static T_1 F_47 ( const struct V_113 * V_31 )
{
const struct V_112 * V_76 ;
V_76 = F_35 ( V_31 , 0 ) ;
if ( F_45 ( V_76 , V_150 ) )
return 0 ;
if ( V_31 -> V_114 < 5 )
return V_151 ;
V_76 = F_35 ( V_31 , V_31 -> V_114 - 5 ) ;
if ( ! F_45 ( V_76 , V_108 ) )
return V_151 ;
V_76 = F_35 ( V_31 , V_31 -> V_114 - 1 ) ;
if ( ! F_45 ( V_76 , V_109 ) )
return V_151 ;
return F_44 ( V_31 , V_31 -> V_114 - 4 ) ;
}
static int F_48 ( struct V_24 * V_25 )
{
int error ;
F_3 ( V_25 -> V_29 , V_25 -> V_77 ) ;
error = F_42 ( V_25 -> V_31 , V_30 , & V_25 -> V_152 ) ;
if ( error ) {
F_6 ( L_28 ) ;
return error ;
}
return F_47 ( & V_25 -> V_152 ) ;
}
static void F_49 ( struct V_24 * V_25 )
{
V_25 -> V_77 = sizeof( struct V_34 ) ;
memset ( V_25 -> V_29 , 0 , V_30 ) ;
}
static int F_50 ( struct V_24 * V_25 )
{
T_2 V_105 , V_106 ;
int error = 0 ;
error = F_48 ( V_25 ) ;
if ( error )
return error ;
V_105 = F_44 ( & V_25 -> V_152 , 4 ) ;
V_106 = F_44 ( & V_25 -> V_152 , 5 ) ;
if ( V_105 == 0 && V_106 == 0 ) {
F_6 ( L_34 ) ;
return - V_153 ;
}
V_25 -> V_105 = V_105 ;
V_25 -> V_106 = V_106 ;
return 0 ;
}
static void F_51 ( struct V_24 * V_25 ,
struct V_154 * V_155 )
{
struct V_154 * V_136 ;
F_52 (iter, &dev->unlk_lst, node) {
if ( V_136 -> V_98 == V_155 -> V_98 ) {
F_53 ( & V_136 -> V_156 ) ;
F_54 ( V_136 ) ;
break;
}
}
F_55 ( & V_155 -> V_156 , & V_25 -> V_157 ) ;
}
static int F_56 ( struct V_24 * V_25 )
{
V_25 -> V_105 = 0 ;
V_25 -> V_106 = 0 ;
return F_48 ( V_25 ) ;
}
static int F_57 ( struct V_24 * V_25 , T_5 V_40 )
{
int V_36 ;
V_36 = F_33 ( V_25 , V_25 -> V_105 , V_25 -> V_106 ) ;
if ( V_36 ) {
F_6 ( L_35 , V_36 ) ;
return V_36 ;
}
F_3 ( V_25 -> V_29 , V_25 -> V_77 ) ;
return F_17 ( V_25 , V_40 ) ;
}
static int F_58 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_158 [ V_99 ] ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
memcpy ( V_158 , V_25 -> V_159 , F_59 ( sizeof( V_158 ) , V_25 -> V_160 ) ) ;
F_54 ( V_25 -> V_159 ) ;
V_25 -> V_159 = NULL ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_158 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_163 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_36 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_60 ( struct V_24 * V_25 )
{
const char * V_164 ;
T_4 V_165 ;
int error = 0 ;
error = F_48 ( V_25 ) ;
if ( error )
return error ;
V_165 = F_43 ( & V_25 -> V_152 , 4 , & V_164 ) ;
if ( ! V_164 ) {
F_6 ( L_37 ,
V_166 ) ;
return V_167 ;
}
V_25 -> V_159 = F_61 ( V_164 , V_165 , V_168 ) ;
if ( ! V_25 -> V_159 )
return - V_169 ;
V_25 -> V_160 = V_165 ;
return 0 ;
}
static int F_62 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_158 [ V_99 ] ;
int V_75 = 0 ;
T_1 * V_98 = V_5 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
V_75 = F_30 ( V_158 , sizeof( V_158 ) , * V_98 ) ;
if ( V_75 )
return V_75 ;
V_75 = 0 ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_158 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_170 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_23 ( & V_75 , V_25 , 10 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 4 ) ;
F_23 ( & V_75 , V_25 , 10 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_38 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_60 ) ;
}
static int F_63 ( struct V_24 * V_25 ,
T_1 * V_158 , bool V_173 , bool V_174 ,
bool V_175 , bool V_176 )
{
int V_75 = 0 ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_158 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 5 ) ;
F_23 ( & V_75 , V_25 , V_173 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 6 ) ;
F_23 ( & V_75 , V_25 , V_174 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_179 ) ;
F_23 ( & V_75 , V_25 , V_175 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_180 ) ;
F_23 ( & V_75 , V_25 , V_176 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
return V_75 ;
}
static inline int F_64 ( struct V_24 * V_25 , T_1 * V_158 ,
struct V_181 * V_182 )
{
int V_75 ;
V_75 = F_63 ( V_25 , V_158 , ! ! V_182 -> V_183 , ! ! V_182 -> V_184 ,
0 , 0 ) ;
if ( V_75 )
F_6 ( L_39 ) ;
return V_75 ;
}
static int F_65 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_158 [ V_99 ] ;
struct V_181 * V_182 = V_5 ;
T_1 V_98 ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
V_98 = V_182 -> V_185 . V_186 . V_98 ;
V_75 = F_30 ( V_158 , sizeof( V_158 ) , V_98 ) ;
if ( V_75 )
return V_75 ;
if ( V_98 == 0 )
V_75 = F_64 ( V_25 , V_158 , V_182 ) ;
else {
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_158 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_26 ( & V_75 , V_25 , V_182 -> V_187 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 4 ) ;
F_26 ( & V_75 , V_25 , V_182 -> V_188 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 5 ) ;
F_26 ( & V_75 , V_25 , ! ! V_182 -> V_183 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 6 ) ;
F_26 ( & V_75 , V_25 , ! ! V_182 -> V_184 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
}
if ( V_75 ) {
F_6 ( L_40 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_66 ( struct V_24 * V_25 ,
enum V_189 V_190 ,
enum V_189 V_191 ,
const char * V_192 ,
T_1 V_193 )
{
T_2 V_105 ;
int V_75 = 0 ;
if ( V_192 == NULL && V_190 != V_194 )
return V_167 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
V_105 = V_195 ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_196 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_197 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_26 ( & V_75 , V_25 , V_105 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_191 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , 1 ) ;
switch ( V_190 ) {
case V_194 :
F_23 ( & V_75 , V_25 , V_109 ) ;
break;
case V_198 :
case V_199 :
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 0 ) ;
F_29 ( & V_75 , V_25 , V_192 , V_193 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_190 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
break;
default:
F_6 ( L_41 , V_190 ) ;
return V_167 ;
}
if ( V_75 ) {
F_6 ( L_42 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_50 ) ;
}
static int F_67 ( struct V_24 * V_25 , void * V_5 )
{
return F_66 ( V_25 , V_194 ,
V_200 , NULL , 0 ) ;
}
static int F_68 ( struct V_24 * V_25 , void * V_5 )
{
int V_36 ;
const T_1 * V_192 = V_25 -> V_159 ;
if ( ! V_192 ) {
const struct V_186 * V_201 = V_5 ;
V_36 = F_66 ( V_25 , V_199 ,
V_200 ,
V_201 -> V_192 ,
V_201 -> V_193 ) ;
} else {
V_36 = F_66 ( V_25 , V_199 ,
V_200 ,
V_192 , V_25 -> V_160 ) ;
F_54 ( V_192 ) ;
V_25 -> V_159 = NULL ;
}
return V_36 ;
}
static int F_69 ( struct V_24 * V_25 , void * V_5 )
{
struct V_186 * V_192 = V_5 ;
return F_66 ( V_25 , V_198 ,
V_202 ,
V_192 -> V_192 , V_192 -> V_193 ) ;
}
static int F_70 ( struct V_24 * V_25 , void * V_5 )
{
struct V_203 * V_185 = V_5 ;
T_1 V_204 [ V_99 ] ;
T_4 V_165 = V_185 -> V_186 . V_193 ;
int V_75 = 0 ;
T_1 * V_192 = V_185 -> V_186 . V_192 ;
T_2 V_105 = V_195 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
if ( V_185 -> V_16 ) {
V_75 = F_31 ( V_204 , sizeof( V_204 ) ,
V_185 -> V_186 . V_98 ) ;
if ( V_75 )
return V_75 ;
} else if ( V_185 -> V_205 != V_206 && ! V_185 -> V_16 ) {
V_75 = F_31 ( V_204 , sizeof( V_204 ) ,
V_185 -> V_205 - 1 ) ;
if ( V_75 )
return V_75 ;
} else
memcpy ( V_204 , V_100 [ V_198 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_196 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_197 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_26 ( & V_75 , V_25 , V_105 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_202 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , 1 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 0 ) ;
F_29 ( & V_75 , V_25 , V_192 , V_165 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_29 ( & V_75 , V_25 , V_204 , V_99 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_43 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_50 ) ;
}
static int F_71 ( struct V_24 * V_25 , void * V_5 )
{
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_200 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_207 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_44 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_72 ( struct V_24 * V_25 , void * V_5 )
{
struct V_203 * V_185 = V_5 ;
T_1 V_158 [ V_99 ] ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
memcpy ( V_158 , V_100 [ V_103 ] , V_99 ) ;
V_158 [ 7 ] = V_185 -> V_205 ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_158 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 5 ) ;
F_23 ( & V_75 , V_25 , V_208 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_45 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_73 ( struct V_24 * V_25 , void * V_5 )
{
struct V_203 * V_185 = V_5 ;
T_1 V_158 [ V_99 ] ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
if ( F_30 ( V_158 , sizeof( V_158 ) , V_185 -> V_186 . V_98 ) < 0 )
return - V_78 ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_158 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_209 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_46 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_74 ( struct V_24 * V_25 , void * V_5 )
{
T_1 * V_210 = V_5 ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_211 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 2 ) ;
F_23 ( & V_75 , V_25 , * V_210 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_47 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_75 ( struct V_24 * V_25 , void * V_5 )
{
T_1 * V_212 = V_5 ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_211 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 1 ) ;
F_23 ( & V_75 , V_25 , * V_212 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_48 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_76 ( T_1 * V_192 , T_4 V_193 , T_1 * V_213 ,
struct V_24 * V_25 )
{
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_213 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_29 ( & V_75 , V_25 , V_192 , V_193 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
return V_75 ;
}
static int F_77 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_213 [ V_99 ] ;
struct V_203 * V_214 = V_5 ;
memcpy ( V_213 , V_100 [ V_215 ] , V_99 ) ;
if ( V_214 -> V_205 != V_206 ) {
V_213 [ 5 ] = 0x03 ;
if ( V_214 -> V_16 )
V_213 [ 7 ] = V_214 -> V_186 . V_98 + 1 ;
else
V_213 [ 7 ] = V_214 -> V_205 ;
}
if ( F_76 ( V_214 -> V_186 . V_192 , V_214 -> V_186 . V_193 ,
V_213 , V_25 ) ) {
F_6 ( L_49 ) ;
return - V_78 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_78 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_213 [ V_99 ] ;
struct V_186 * V_192 = V_5 ;
memcpy ( V_213 , V_100 [ V_216 ] , V_99 ) ;
if ( F_76 ( V_192 -> V_192 , V_192 -> V_193 , V_213 , V_25 ) ) {
F_6 ( L_50 ) ;
return - V_78 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_79 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_217 [ V_99 ] ;
T_1 V_218 [ V_99 ] ;
struct V_219 * V_220 = V_5 ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
memcpy ( V_217 , V_100 [ V_221 ] ,
V_99 ) ;
if ( V_220 -> V_222 == V_223 )
memcpy ( V_217 , V_100 [ V_224 ] ,
V_99 ) ;
V_217 [ 7 ] = V_220 -> V_185 . V_186 . V_98 ;
memcpy ( V_218 , V_100 [ V_103 ] , V_99 ) ;
V_218 [ 7 ] = V_220 -> V_185 . V_205 ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_217 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] ,
V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_29 ( & V_75 , V_25 ,
V_100 [ V_225 ] ,
V_99 / 2 ) ;
F_29 ( & V_75 , V_25 , V_218 , V_99 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_29 ( & V_75 , V_25 ,
V_100 [ V_225 ] ,
V_99 / 2 ) ;
F_29 ( & V_75 , V_25 , V_218 , V_99 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_226 ] ,
V_99 / 2 ) ;
F_23 ( & V_75 , V_25 , 1 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_51 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_80 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_217 [ V_99 ] ;
struct V_219 * V_220 = V_5 ;
T_1 V_227 = 1 , V_228 = 1 ;
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
if ( F_30 ( V_217 , sizeof( V_217 ) ,
V_220 -> V_185 . V_186 . V_98 ) < 0 )
return - V_78 ;
switch ( V_220 -> V_222 ) {
case V_229 :
V_227 = 0 ;
V_228 = 1 ;
break;
case V_223 :
V_227 = 0 ;
V_228 = 0 ;
break;
case V_230 :
break;
default:
F_6 ( L_52 ) ;
return V_167 ;
}
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_217 , V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_177 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_178 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_179 ) ;
F_23 ( & V_75 , V_25 , V_227 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_180 ) ;
F_23 ( & V_75 , V_25 , V_228 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_53 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_81 ( struct V_24 * V_25 , void * V_5 )
{
T_1 V_217 [ V_99 ] ;
T_1 V_227 = 1 , V_228 = 1 ;
struct V_219 * V_220 = V_5 ;
int V_36 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
if ( F_30 ( V_217 , sizeof( V_217 ) ,
V_220 -> V_185 . V_186 . V_98 ) < 0 )
return - V_78 ;
switch ( V_220 -> V_222 ) {
case V_229 :
V_227 = 0 ;
V_228 = 1 ;
break;
case V_223 :
V_227 = 0 ;
V_228 = 0 ;
break;
case V_230 :
break;
default:
F_6 ( L_54 ) ;
return V_167 ;
}
V_36 = F_63 ( V_25 , V_217 , 1 , 1 ,
V_227 , V_228 ) ;
if ( V_36 < 0 ) {
F_6 ( L_53 ) ;
return V_36 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_82 ( struct V_24 * V_25 , void * V_5 )
{
struct V_231 * V_232 = V_5 ;
T_1 V_233 [ V_99 ] ;
T_1 V_234 = 0x83 ;
int V_75 = 0 , V_127 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_202 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_235 ] ,
V_99 ) ;
if ( V_232 -> V_16 ) {
V_75 = F_30 ( V_233 , sizeof( V_233 ) ,
V_232 -> V_98 [ 0 ] ) ;
if ( V_75 )
return V_75 ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , V_234 ) ;
F_23 ( & V_75 , V_25 , 6 ) ;
F_23 ( & V_75 , V_25 , 0 ) ;
F_23 ( & V_75 , V_25 , 0 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_29 ( & V_75 , V_25 , V_233 , V_99 ) ;
for ( V_127 = 1 ; V_127 < V_232 -> V_236 ; V_127 ++ ) {
V_233 [ 7 ] = V_232 -> V_98 [ V_127 ] ;
F_29 ( & V_75 , V_25 , V_233 , V_99 ) ;
}
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
} else {
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
}
if ( V_75 ) {
F_6 ( L_55 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_48 ) ;
}
static int F_83 ( struct V_24 * V_25 )
{
T_1 V_237 ;
int error = 0 ;
error = F_48 ( V_25 ) ;
if ( error )
return error ;
V_237 = F_44 ( & V_25 -> V_152 , 4 ) ;
if ( V_237 != V_238 ) {
F_6 ( L_56 ) ;
return - V_239 ;
}
return 0 ;
}
static int F_84 ( struct V_24 * V_25 , void * V_5 )
{
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_202 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_170 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_23 ( & V_75 , V_25 , 6 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 4 ) ;
F_23 ( & V_75 , V_25 , 6 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_57 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_83 ) ;
}
static int F_85 ( struct V_24 * V_25 )
{
const char * V_240 ;
T_4 strlen ;
int error = 0 ;
error = F_48 ( V_25 ) ;
if ( error )
return error ;
strlen = F_43 ( & V_25 -> V_152 , 4 , & V_240 ) ;
if ( ! V_240 ) {
F_6 ( L_58 , V_166 ) ;
return V_167 ;
}
V_25 -> V_159 = F_61 ( V_240 , strlen , V_168 ) ;
if ( ! V_25 -> V_159 )
return - V_169 ;
V_25 -> V_160 = strlen ;
return 0 ;
}
static int F_86 ( struct V_24 * V_25 , void * V_5 )
{
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_161 ) ;
F_29 ( & V_75 , V_25 , V_100 [ V_241 ] ,
V_99 ) ;
F_29 ( & V_75 , V_25 , V_162 [ V_170 ] , V_99 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_108 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_171 ) ;
F_23 ( & V_75 , V_25 , 4 ) ;
F_23 ( & V_75 , V_25 , 3 ) ;
F_23 ( & V_75 , V_25 , V_172 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
F_23 ( & V_75 , V_25 , V_109 ) ;
if ( V_75 ) {
F_6 ( L_59 ) ;
return V_75 ;
}
return F_57 ( V_25 , F_85 ) ;
}
static int F_87 ( struct V_24 * V_25 , void * V_5 )
{
int V_75 = 0 ;
F_49 ( V_25 ) ;
F_32 ( V_25 , V_25 -> V_27 ) ;
F_23 ( & V_75 , V_25 , V_150 ) ;
if ( V_75 < 0 )
return V_75 ;
return F_57 ( V_25 , F_56 ) ;
}
static int F_20 ( struct V_24 * V_25 )
{
const struct V_47 V_242 [] = {
{ F_87 , } ,
{ NULL , }
} ;
V_25 -> V_50 = V_242 ;
return F_19 ( V_25 ) ;
}
static inline void F_88 ( struct V_24 * V_25 ,
const struct V_47 * V_50 )
{
V_25 -> V_50 = V_50 ;
V_25 -> V_106 = 0 ;
V_25 -> V_105 = 0 ;
V_25 -> V_159 = NULL ;
}
static int F_89 ( struct V_24 * V_25 )
{
const struct V_47 V_50 [] = {
{ F_22 , } ,
{ NULL , }
} ;
int V_36 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_50 ) ;
V_36 = F_19 ( V_25 ) ;
V_25 -> V_53 = ! V_36 ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static void F_92 ( struct V_24 * V_25 )
{
struct V_154 * V_244 , * F_19 ;
F_90 ( & V_25 -> V_243 ) ;
F_93 (suspend, next, &dev->unlk_lst, node) {
F_53 ( & V_244 -> V_156 ) ;
F_54 ( V_244 ) ;
}
F_91 ( & V_25 -> V_243 ) ;
}
void F_94 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_92 ( V_25 ) ;
F_54 ( V_25 ) ;
}
struct V_24 * F_95 ( void * V_5 , T_8 * V_26 )
{
struct V_24 * V_25 ;
V_25 = F_96 ( sizeof( * V_25 ) , V_168 ) ;
if ( ! V_25 )
return NULL ;
F_97 ( & V_25 -> V_157 ) ;
F_98 ( & V_25 -> V_243 ) ;
V_25 -> V_5 = V_5 ;
V_25 -> V_26 = V_26 ;
if ( F_89 ( V_25 ) != 0 ) {
F_6 ( L_60 ) ;
F_54 ( V_25 ) ;
return NULL ;
}
return V_25 ;
}
static int F_99 ( struct V_24 * V_25 ,
struct V_203 * V_245 )
{
const struct V_47 V_246 [] = {
{ F_22 , } ,
{ F_70 , V_245 } ,
{ F_62 , & V_245 -> V_186 . V_98 } ,
{ F_58 , } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_246 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_100 ( struct V_24 * V_25 ,
struct V_203 * V_245 )
{
const struct V_47 V_246 [] = {
{ F_22 , } ,
{ F_70 , V_245 } ,
{ F_73 , V_245 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_246 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_101 ( struct V_24 * V_25 ,
struct V_247 * V_248 )
{
const struct V_47 V_249 [] = {
{ F_22 , } ,
{ F_69 , & V_248 -> V_192 } ,
{ F_74 , & V_248 -> V_250 } ,
{ F_87 , } ,
{ F_69 , & V_248 -> V_192 } ,
{ F_75 , & V_248 -> V_250 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
if ( V_248 -> V_250 != V_251 &&
V_248 -> V_250 != V_252 )
return - V_115 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_249 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_102 ( struct V_24 * V_25 , struct V_219 * V_253 )
{
struct V_154 * V_244 ;
V_244 = F_103 ( sizeof( * V_244 ) , V_168 ) ;
if ( ! V_244 )
return - V_169 ;
V_244 -> V_254 = * V_253 ;
V_244 -> V_98 = V_253 -> V_185 . V_186 . V_98 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , NULL ) ;
F_51 ( V_25 , V_244 ) ;
F_91 ( & V_25 -> V_243 ) ;
return 0 ;
}
static int F_104 ( struct V_24 * V_25 ,
struct V_219 * V_253 )
{
const struct V_47 V_50 [] = {
{ F_22 , } ,
{ F_69 , & V_253 -> V_185 . V_186 } ,
{ F_79 , V_253 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
if ( V_253 -> V_222 != V_229 &&
V_253 -> V_222 != V_223 ) {
F_6 ( L_61 ) ;
return - V_115 ;
}
if ( V_253 -> V_185 . V_205 < V_255 ||
V_253 -> V_185 . V_205 > V_256 ) {
F_6 ( L_62 ,
V_253 -> V_185 . V_205 ) ;
return - V_115 ;
}
if ( V_253 -> V_185 . V_16 ) {
F_6 ( L_63 ,
V_166 ) ;
return - V_115 ;
}
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_50 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_105 ( struct V_24 * V_25 , struct V_186 * V_257 )
{
const struct V_47 V_258 [] = {
{ F_22 , } ,
{ F_68 , V_257 } ,
{ F_71 , } ,
{ NULL , }
} ;
int V_36 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_258 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
if ( ! V_36 )
F_92 ( V_25 ) ;
return V_36 ;
}
static int F_106 ( struct V_24 * V_25 ,
struct V_219 * V_253 )
{
const struct V_47 V_259 [] = {
{ F_22 , } ,
{ F_70 , & V_253 -> V_185 } ,
{ F_80 , V_253 } ,
{ F_87 , } ,
{ NULL , }
} ;
const struct V_47 V_260 [] = {
{ F_22 , } ,
{ F_70 , & V_253 -> V_185 } ,
{ F_81 , V_253 } ,
{ F_87 , } ,
{ NULL , }
} ;
V_25 -> V_50 = V_253 -> V_185 . V_16 ? V_260 : V_259 ;
return F_19 ( V_25 ) ;
}
static int F_107 ( struct V_24 * V_25 , struct V_186 * V_192 )
{
T_1 V_210 = 1 ;
const struct V_47 V_261 [] = {
{ F_22 , } ,
{ F_69 , V_192 } ,
{ F_74 , & V_210 } ,
{ F_87 , } ,
{ NULL , }
} ;
V_25 -> V_50 = V_261 ;
return F_19 ( V_25 ) ;
}
static int V_219 ( struct V_24 * V_25 ,
struct V_219 * V_253 )
{
int V_36 ;
if ( V_253 -> V_185 . V_205 < V_206 ||
V_253 -> V_185 . V_205 > V_256 )
return - V_115 ;
F_90 ( & V_25 -> V_243 ) ;
V_36 = F_106 ( V_25 , V_253 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_108 ( struct V_24 * V_25 , struct V_186 * V_257 )
{
const struct V_47 V_262 [] = {
{ F_22 , } ,
{ F_67 , } ,
{ F_86 , } ,
{ F_87 , } ,
{ F_68 , V_257 } ,
{ F_78 , V_257 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
if ( ! V_25 )
return - V_239 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_262 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_109 ( struct V_24 * V_25 , struct V_231 * V_231 )
{
const struct V_47 V_263 [] = {
{ F_22 , } ,
{ F_68 , & V_231 -> V_192 } ,
{ F_84 , } ,
{ F_82 , V_231 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
if ( ! V_231 -> V_236 || V_231 -> V_236 > V_264 )
return - V_115 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_263 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_110 ( struct V_24 * V_25 ,
struct V_181 * V_265 )
{
const struct V_47 V_266 [] = {
{ F_22 , } ,
{ F_70 , & V_265 -> V_185 } ,
{ F_65 , V_265 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_266 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_111 ( struct V_24 * V_25 , struct V_267 * V_268 )
{
const struct V_47 V_269 [] = {
{ F_22 , } ,
{ F_70 , & V_268 -> V_185 } ,
{ F_77 , & V_268 -> V_270 } ,
{ F_87 , } ,
{ NULL }
} ;
int V_36 ;
if ( V_268 -> V_185 . V_205 < V_206 ||
V_268 -> V_185 . V_205 > V_256 ||
V_268 -> V_270 . V_205 < V_206 ||
V_268 -> V_270 . V_205 > V_256 )
return - V_115 ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_269 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
static int F_112 ( struct V_24 * V_25 ,
struct V_203 * V_245 )
{
const struct V_47 V_271 [] = {
{ F_22 , } ,
{ F_69 , & V_245 -> V_186 } ,
{ F_72 , V_245 } ,
{ F_87 , } ,
{ NULL , }
} ;
int V_36 ;
if ( V_245 -> V_205 < V_255 ||
V_245 -> V_205 > V_256 ) {
F_6 ( L_64 , V_245 -> V_205 ) ;
return - V_115 ;
}
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , V_271 ) ;
V_36 = F_19 ( V_25 ) ;
F_91 ( & V_25 -> V_243 ) ;
return V_36 ;
}
bool F_113 ( struct V_24 * V_25 )
{
struct V_154 * V_244 ;
bool V_272 = false ;
int V_36 = 0 ;
if ( ! V_25 )
return false ;
if ( ! V_25 -> V_53 )
return false ;
F_90 ( & V_25 -> V_243 ) ;
F_88 ( V_25 , NULL ) ;
F_52 (suspend, &dev->unlk_lst, node) {
V_25 -> V_106 = 0 ;
V_25 -> V_105 = 0 ;
V_36 = F_106 ( V_25 , & V_244 -> V_254 ) ;
if ( V_36 ) {
F_6 ( L_65 ,
V_244 -> V_254 . V_185 . V_186 . V_98 ,
V_244 -> V_254 . V_185 . V_16 ) ;
V_272 = true ;
}
if ( V_25 -> V_59 ) {
V_36 = F_107 ( V_25 , & V_244 -> V_254 . V_185 . V_186 ) ;
if ( V_36 )
F_6 ( L_66 ) ;
}
}
F_91 ( & V_25 -> V_243 ) ;
return V_272 ;
}
int F_114 ( struct V_24 * V_25 , unsigned int V_29 , void T_9 * V_273 )
{
void * V_274 ;
int V_36 = - V_275 ;
if ( ! F_115 ( V_276 ) )
return - V_277 ;
if ( ! V_25 )
return - V_278 ;
if ( ! V_25 -> V_53 )
return - V_278 ;
V_274 = F_116 ( V_273 , F_117 ( V_29 ) ) ;
if ( F_46 ( V_274 ) )
return F_118 ( V_274 ) ;
switch ( V_29 ) {
case V_279 :
V_36 = F_102 ( V_25 , V_274 ) ;
break;
case V_280 :
V_36 = V_219 ( V_25 , V_274 ) ;
break;
case V_281 :
V_36 = F_108 ( V_25 , V_274 ) ;
break;
case V_282 :
V_36 = F_109 ( V_25 , V_274 ) ;
break;
case V_283 :
V_36 = F_111 ( V_25 , V_274 ) ;
break;
case V_284 :
V_36 = F_112 ( V_25 , V_274 ) ;
break;
case V_285 :
V_36 = F_105 ( V_25 , V_274 ) ;
break;
case V_286 :
V_36 = F_110 ( V_25 , V_274 ) ;
break;
case V_287 :
V_36 = F_104 ( V_25 , V_274 ) ;
break;
case V_288 :
V_36 = F_101 ( V_25 , V_274 ) ;
break;
case V_289 :
V_36 = F_100 ( V_25 , V_274 ) ;
break;
case V_290 :
V_36 = F_99 ( V_25 , V_274 ) ;
break;
default:
break;
}
F_54 ( V_274 ) ;
return V_36 ;
}
