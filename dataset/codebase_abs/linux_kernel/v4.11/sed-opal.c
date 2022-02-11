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
F_8 ( L_5 ,
V_7 -> V_9 ) ;
return false ;
}
return true ;
}
static bool F_9 ( const void * V_5 )
{
const struct V_11 * V_12 = V_5 ;
T_2 V_13 = F_10 ( V_12 -> V_14 ) ;
if ( V_13 == 0 ) {
F_8 ( L_6 ) ;
return false ;
}
F_6 ( L_7 , V_13 ) ;
return true ;
}
static T_3 F_11 ( const void * V_5 )
{
const struct V_15 * V_16 = V_5 ;
return F_12 ( V_16 -> V_17 ) ;
}
static T_3 F_13 ( const void * V_5 )
{
const struct V_18 * V_19 = V_5 ;
return F_12 ( V_19 -> V_17 ) ;
}
static int F_14 ( struct V_20 * V_21 )
{
return V_21 -> V_22 ( V_21 -> V_5 , V_21 -> V_23 , V_24 ,
V_21 -> V_25 , V_26 ,
true ) ;
}
static int F_15 ( struct V_20 * V_21 )
{
return V_21 -> V_22 ( V_21 -> V_5 , V_21 -> V_23 , V_24 ,
V_21 -> V_27 , V_26 ,
false ) ;
}
static int F_16 ( struct V_20 * V_21 )
{
T_4 V_28 = V_26 ;
void * V_29 = V_21 -> V_27 ;
struct V_30 * V_31 = V_29 ;
int V_32 ;
do {
F_6 ( L_8 ,
V_31 -> V_33 . V_34 ,
V_31 -> V_33 . V_35 ) ;
if ( V_31 -> V_33 . V_34 == 0 ||
V_31 -> V_33 . V_35 != 0 )
return 0 ;
memset ( V_29 , 0 , V_28 ) ;
V_32 = F_15 ( V_21 ) ;
} while ( ! V_32 );
return V_32 ;
}
static int F_17 ( struct V_20 * V_21 , T_5 * V_36 )
{
int V_32 ;
V_32 = F_14 ( V_21 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_15 ( V_21 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_16 ( V_21 ) ;
if ( V_32 )
return V_32 ;
return V_36 ( V_21 ) ;
}
static void F_18 ( struct V_20 * V_21 , const void * V_5 )
{
const struct V_37 * V_38 = V_5 ;
V_21 -> V_39 = V_38 -> V_40 ;
V_21 -> V_41 = V_38 -> V_42 ;
}
static int F_19 ( struct V_20 * V_21 )
{
const struct V_43 * V_44 ;
int V_45 = 0 , error = 0 ;
do {
V_44 = & V_21 -> V_46 [ V_45 ] ;
if ( ! V_44 -> V_47 )
break;
error = V_44 -> V_47 ( V_21 , V_44 -> V_5 ) ;
if ( error ) {
F_8 ( L_9 ,
V_45 , error ,
F_1 ( error ) ) ;
if ( V_45 > 1 ) {
F_20 ( V_21 ) ;
return error ;
}
}
V_45 ++ ;
} while ( ! error );
return error ;
}
static int F_21 ( struct V_20 * V_21 )
{
bool V_48 = false , V_49 = true , V_50 = false ;
const struct V_51 * V_31 = (struct V_51 * ) V_21 -> V_27 ;
const T_1 * V_52 = V_21 -> V_27 , * V_53 = V_21 -> V_27 ;
T_3 V_23 = 0 ;
T_2 V_54 = F_10 ( V_31 -> V_3 ) ;
F_3 ( V_21 -> V_27 , V_54 ) ;
if ( V_54 > V_26 - sizeof( * V_31 ) ) {
F_22 ( L_10 ,
sizeof( * V_31 ) , V_54 , V_26 ) ;
return - V_55 ;
}
V_52 += V_54 ;
V_53 += sizeof( * V_31 ) ;
while ( V_53 < V_52 && V_49 ) {
const struct V_56 * V_57 =
( const struct V_56 * ) V_53 ;
switch ( F_12 ( V_57 -> V_58 ) ) {
case V_59 :
V_49 = F_7 ( V_57 -> V_60 ) ;
break;
case V_61 :
V_50 = F_9 ( V_57 -> V_60 ) ;
break;
case V_62 :
F_18 ( V_21 , V_57 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
F_6 ( L_11 ,
F_12 ( V_57 -> V_58 ) ) ;
break;
case V_66 :
V_23 = F_11 ( V_57 -> V_60 ) ;
V_48 = true ;
break;
case V_67 :
V_23 = F_13 ( V_57 -> V_60 ) ;
V_48 = true ;
break;
case 0xbfff ... 0xffff :
break;
default:
F_6 ( L_12 ,
F_12 ( V_57 -> V_58 ) ) ;
}
V_53 += V_57 -> V_3 + 4 ;
}
if ( ! V_49 ) {
F_6 ( L_13 ) ;
return - V_68 ;
}
if ( ! V_50 )
F_6 ( L_14 ) ;
if ( ! V_48 ) {
F_6 ( L_15 ) ;
return - V_68 ; ;
}
V_21 -> V_23 = V_23 ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 , void * V_5 )
{
int V_32 ;
memset ( V_21 -> V_27 , 0 , V_26 ) ;
V_21 -> V_23 = V_69 ;
V_32 = F_15 ( V_21 ) ;
if ( V_32 )
return V_32 ;
return F_21 ( V_21 ) ;
}
static void F_24 ( int * V_70 , struct V_20 * V_25 , T_1 V_71 )
{
if ( * V_70 )
return;
if ( V_25 -> V_72 >= V_26 - 1 ) {
F_8 ( L_16 ) ;
* V_70 = - V_73 ;
return;
}
V_25 -> V_25 [ V_25 -> V_72 ++ ] = V_71 ;
}
static void F_25 ( struct V_20 * V_25 , bool V_74 ,
bool V_75 , int V_76 )
{
T_1 V_77 ;
int V_70 = 0 ;
V_77 = V_78 ;
V_77 |= V_74 ? V_79 : 0 ;
V_77 |= V_75 ? V_80 : 0 ;
V_77 |= V_76 & V_81 ;
F_24 ( & V_70 , V_25 , V_77 ) ;
}
static void F_26 ( struct V_20 * V_25 , bool V_74 ,
bool V_75 , int V_76 )
{
T_1 V_82 ;
V_82 = V_83 ;
V_82 |= V_74 ? V_84 : 0 ;
V_82 |= V_75 ? V_85 : 0 ;
V_82 |= ( V_76 >> 8 ) & V_86 ;
V_25 -> V_25 [ V_25 -> V_72 ++ ] = V_82 ;
V_25 -> V_25 [ V_25 -> V_72 ++ ] = V_76 ;
}
static void F_27 ( int * V_70 , struct V_20 * V_25 , T_6 V_87 )
{
T_4 V_76 ;
int V_88 ;
T_1 V_89 ;
if ( ! ( V_87 & ~ V_90 ) ) {
F_24 ( V_70 , V_25 , V_87 ) ;
return;
}
V_88 = F_28 ( V_87 ) ;
V_76 = F_29 ( V_88 , 4 ) ;
if ( V_25 -> V_72 >= V_26 - V_76 - 1 ) {
F_8 ( L_17 ) ;
* V_70 = - V_73 ;
return;
}
F_25 ( V_25 , false , false , V_76 ) ;
while ( V_76 -- ) {
V_89 = V_87 >> ( V_76 * 8 ) ;
F_24 ( V_70 , V_25 , V_89 ) ;
}
}
static void F_30 ( int * V_70 , struct V_20 * V_25 ,
const T_1 * V_74 , T_4 V_76 )
{
T_4 V_91 = 1 ;
bool V_92 = true ;
if ( * V_70 )
return;
if ( V_76 & ~ V_81 ) {
V_91 = 2 ;
V_92 = false ;
}
if ( V_76 >= V_26 - V_25 -> V_72 - V_91 ) {
F_8 ( L_18 ) ;
* V_70 = - V_73 ;
return;
}
if ( V_92 )
F_25 ( V_25 , true , false , V_76 ) ;
else
F_26 ( V_25 , true , false , V_76 ) ;
memcpy ( & V_25 -> V_25 [ V_25 -> V_72 ] , V_74 , V_76 ) ;
V_25 -> V_72 += V_76 ;
}
static int F_31 ( T_1 * V_29 , T_4 V_3 , T_1 V_93 )
{
if ( V_3 > V_94 ) {
F_8 ( L_19 ) ;
return - V_73 ;
}
memcpy ( V_29 , V_95 [ V_96 ] , V_94 ) ;
if ( V_93 == 0 )
return 0 ;
V_29 [ 5 ] = V_97 ;
V_29 [ 7 ] = V_93 ;
return 0 ;
}
static int F_32 ( T_1 * V_29 , T_4 V_3 , T_1 V_93 )
{
if ( V_3 > V_94 ) {
F_8 ( L_20 ) ;
return - V_73 ;
}
memcpy ( V_29 , V_95 [ V_98 ] , V_94 ) ;
V_29 [ 7 ] = V_93 + 1 ;
return 0 ;
}
static void F_33 ( struct V_20 * V_25 , T_3 V_23 )
{
struct V_30 * V_31 = (struct V_30 * ) V_25 -> V_25 ;
V_31 -> V_33 . V_99 [ 0 ] = V_23 >> 8 ;
V_31 -> V_33 . V_99 [ 1 ] = V_23 ;
V_31 -> V_33 . V_99 [ 2 ] = 0 ;
V_31 -> V_33 . V_99 [ 3 ] = 0 ;
}
static int F_34 ( struct V_20 * V_25 , T_2 V_100 , T_2 V_101 )
{
struct V_30 * V_31 ;
int V_70 = 0 ;
F_24 ( & V_70 , V_25 , V_102 ) ;
F_24 ( & V_70 , V_25 , V_103 ) ;
F_24 ( & V_70 , V_25 , 0 ) ;
F_24 ( & V_70 , V_25 , 0 ) ;
F_24 ( & V_70 , V_25 , 0 ) ;
F_24 ( & V_70 , V_25 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_21 ) ;
return - V_55 ;
}
V_31 = (struct V_30 * ) V_25 -> V_25 ;
V_31 -> V_105 . V_101 = F_35 ( V_101 ) ;
V_31 -> V_105 . V_100 = F_35 ( V_100 ) ;
V_31 -> V_106 . V_3 = F_35 ( V_25 -> V_72 - sizeof( * V_31 ) ) ;
while ( V_25 -> V_72 % 4 ) {
if ( V_25 -> V_72 >= V_26 ) {
F_8 ( L_22 ) ;
return - V_73 ;
}
V_25 -> V_25 [ V_25 -> V_72 ++ ] = 0 ;
}
V_31 -> V_105 . V_3 = F_35 ( V_25 -> V_72 - sizeof( V_31 -> V_33 ) -
sizeof( V_31 -> V_105 ) ) ;
V_31 -> V_33 . V_3 = F_35 ( V_25 -> V_72 - sizeof( V_31 -> V_33 ) ) ;
return 0 ;
}
static const struct V_107 * F_36 (
const struct V_108 * V_27 ,
int V_89 )
{
const struct V_107 * V_71 ;
if ( V_89 >= V_27 -> V_109 ) {
F_8 ( L_23 ,
V_89 , V_27 -> V_109 ) ;
return F_37 ( - V_110 ) ;
}
V_71 = & V_27 -> V_111 [ V_89 ] ;
if ( V_71 -> V_76 == 0 ) {
F_8 ( L_24 ) ;
return F_37 ( - V_110 ) ;
}
return V_71 ;
}
static T_7 F_38 ( struct V_107 * V_71 ,
const T_1 * V_72 )
{
V_71 -> V_72 = V_72 ;
V_71 -> V_76 = 1 ;
V_71 -> V_112 = V_113 ;
if ( V_72 [ 0 ] & V_114 ) {
V_71 -> type = V_115 ;
} else {
V_71 -> type = V_116 ;
V_71 -> V_117 . V_118 = V_72 [ 0 ] & 0x3f ;
}
return V_71 -> V_76 ;
}
static T_7 F_39 ( struct V_107 * V_71 ,
const T_1 * V_72 )
{
V_71 -> V_72 = V_72 ;
V_71 -> V_76 = ( V_72 [ 0 ] & V_81 ) + 1 ;
V_71 -> V_112 = V_119 ;
if ( V_72 [ 0 ] & V_79 ) {
V_71 -> type = V_120 ;
} else if ( V_72 [ 0 ] & V_80 ) {
V_71 -> type = V_115 ;
} else {
T_6 V_121 = 0 ;
T_7 V_122 , V_123 = 0 ;
V_71 -> type = V_116 ;
if ( V_71 -> V_76 > 9 ) {
F_22 ( L_25 ) ;
return - V_110 ;
}
for ( V_122 = V_71 -> V_76 - 1 ; V_122 > 0 ; V_122 -- ) {
V_121 |= ( ( T_6 ) V_72 [ V_122 ] << ( 8 * V_123 ) ) ;
V_123 ++ ;
}
V_71 -> V_117 . V_118 = V_121 ;
}
return V_71 -> V_76 ;
}
static T_7 F_40 ( struct V_107 * V_71 ,
const T_1 * V_72 )
{
V_71 -> V_72 = V_72 ;
V_71 -> V_76 = ( ( ( V_72 [ 0 ] & V_86 ) << 8 ) | V_72 [ 1 ] ) + 2 ;
V_71 -> V_112 = V_124 ;
if ( V_72 [ 0 ] & V_84 )
V_71 -> type = V_120 ;
else if ( V_72 [ 0 ] & V_85 )
V_71 -> type = V_115 ;
else
V_71 -> type = V_116 ;
return V_71 -> V_76 ;
}
static T_7 F_41 ( struct V_107 * V_71 ,
const T_1 * V_72 )
{
V_71 -> V_72 = V_72 ;
V_71 -> V_76 = ( ( V_72 [ 1 ] << 16 ) | ( V_72 [ 2 ] << 8 ) | V_72 [ 3 ] ) + 4 ;
V_71 -> V_112 = V_125 ;
if ( V_72 [ 0 ] & V_126 )
V_71 -> type = V_120 ;
else if ( V_72 [ 0 ] & V_127 )
V_71 -> type = V_115 ;
else
V_71 -> type = V_116 ;
return V_71 -> V_76 ;
}
static T_7 F_42 ( struct V_107 * V_71 ,
const T_1 * V_72 )
{
V_71 -> V_72 = V_72 ;
V_71 -> V_76 = 1 ;
V_71 -> type = V_128 ;
V_71 -> V_112 = V_129 ;
return V_71 -> V_76 ;
}
static int F_43 ( const T_1 * V_130 , T_4 V_3 ,
struct V_108 * V_27 )
{
const struct V_30 * V_31 ;
struct V_107 * V_131 ;
int V_132 = 0 ;
int V_133 ;
T_7 V_134 ;
const T_1 * V_72 ;
T_2 V_135 , V_136 , V_137 ;
if ( ! V_130 )
return - V_55 ;
if ( ! V_27 )
return - V_55 ;
V_31 = (struct V_30 * ) V_130 ;
V_72 = V_130 ;
V_72 += sizeof( * V_31 ) ;
V_135 = F_10 ( V_31 -> V_33 . V_3 ) ;
V_136 = F_10 ( V_31 -> V_105 . V_3 ) ;
V_137 = F_10 ( V_31 -> V_106 . V_3 ) ;
F_6 ( L_26 ,
V_135 , V_136 , V_137 ) ;
if ( V_135 == 0 || V_136 == 0 || V_137 == 0 ||
V_137 > V_26 - sizeof( * V_31 ) ) {
F_8 ( L_27 ,
V_135 , V_136 , V_137 ) ;
F_3 ( V_72 , sizeof( * V_31 ) ) ;
return - V_110 ;
}
if ( V_72 > V_130 + V_3 )
return - V_55 ;
V_131 = V_27 -> V_111 ;
V_133 = V_137 ;
F_3 ( V_72 , V_133 ) ;
while ( V_133 > 0 ) {
if ( V_72 [ 0 ] <= V_138 )
V_134 = F_38 ( V_131 , V_72 ) ;
else if ( V_72 [ 0 ] <= V_139 )
V_134 = F_39 ( V_131 , V_72 ) ;
else if ( V_72 [ 0 ] <= V_140 )
V_134 = F_40 ( V_131 , V_72 ) ;
else if ( V_72 [ 0 ] <= V_141 )
V_134 = F_41 ( V_131 , V_72 ) ;
else
V_134 = F_42 ( V_131 , V_72 ) ;
if ( V_134 < 0 )
return V_134 ;
V_72 += V_134 ;
V_133 -= V_134 ;
V_131 ++ ;
V_132 ++ ;
}
if ( V_132 == 0 ) {
F_8 ( L_28 ) ;
return - V_110 ;
}
V_27 -> V_109 = V_132 ;
return 0 ;
}
static T_4 F_44 ( const struct V_108 * V_27 , int V_89 ,
const char * * V_142 )
{
* V_142 = NULL ;
if ( ! V_27 ) {
F_8 ( L_29 ) ;
return 0 ;
}
if ( V_89 > V_27 -> V_109 ) {
F_8 ( L_30 ,
V_27 -> V_109 , V_89 ) ;
return 0 ;
}
if ( V_27 -> V_111 [ V_89 ] . type != V_120 ) {
F_8 ( L_31 ) ;
return 0 ;
}
* V_142 = V_27 -> V_111 [ V_89 ] . V_72 + 1 ;
return V_27 -> V_111 [ V_89 ] . V_76 - 1 ;
}
static T_6 F_45 ( const struct V_108 * V_27 , int V_89 )
{
if ( ! V_27 ) {
F_8 ( L_29 ) ;
return 0 ;
}
if ( V_89 > V_27 -> V_109 ) {
F_8 ( L_30 ,
V_27 -> V_109 , V_89 ) ;
return 0 ;
}
if ( V_27 -> V_111 [ V_89 ] . type != V_116 ) {
F_8 ( L_32 ,
V_27 -> V_111 [ V_89 ] . type ) ;
return 0 ;
}
if ( ! ( V_27 -> V_111 [ V_89 ] . V_112 == V_113 ||
V_27 -> V_111 [ V_89 ] . V_112 == V_119 ) ) {
F_8 ( L_33 ,
V_27 -> V_111 [ V_89 ] . V_112 ) ;
return 0 ;
}
return V_27 -> V_111 [ V_89 ] . V_117 . V_118 ;
}
static bool F_46 ( const struct V_107 * V_143 , T_1 V_144 )
{
if ( F_47 ( V_143 ) ||
V_143 -> type != V_128 ||
V_143 -> V_72 [ 0 ] != V_144 )
return false ;
return true ;
}
static T_1 F_48 ( const struct V_108 * V_27 )
{
const struct V_107 * V_71 ;
V_71 = F_36 ( V_27 , 0 ) ;
if ( F_46 ( V_71 , V_145 ) )
return 0 ;
if ( V_27 -> V_109 < 5 )
return V_146 ;
V_71 = F_36 ( V_27 , V_27 -> V_109 - 5 ) ;
if ( ! F_46 ( V_71 , V_103 ) )
return V_146 ;
V_71 = F_36 ( V_27 , V_27 -> V_109 - 1 ) ;
if ( ! F_46 ( V_71 , V_104 ) )
return V_146 ;
return F_45 ( V_27 , V_27 -> V_109 - 4 ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
int error ;
F_3 ( V_21 -> V_25 , V_21 -> V_72 ) ;
error = F_43 ( V_21 -> V_27 , V_26 , & V_21 -> V_147 ) ;
if ( error ) {
F_8 ( L_28 ) ;
return error ;
}
return F_48 ( & V_21 -> V_147 ) ;
}
static void F_50 ( struct V_20 * V_21 )
{
V_21 -> V_72 = sizeof( struct V_30 ) ;
memset ( V_21 -> V_25 , 0 , V_26 ) ;
}
static int F_51 ( struct V_20 * V_21 )
{
T_2 V_100 , V_101 ;
int error = 0 ;
error = F_49 ( V_21 ) ;
if ( error )
return error ;
V_100 = F_45 ( & V_21 -> V_147 , 4 ) ;
V_101 = F_45 ( & V_21 -> V_147 , 5 ) ;
if ( V_100 == 0 && V_101 == 0 ) {
F_8 ( L_34 ) ;
return - V_148 ;
}
V_21 -> V_100 = V_100 ;
V_21 -> V_101 = V_101 ;
return 0 ;
}
static void F_52 ( struct V_20 * V_21 ,
struct V_149 * V_150 )
{
struct V_149 * V_131 ;
F_53 (iter, &dev->unlk_lst, node) {
if ( V_131 -> V_93 == V_150 -> V_93 ) {
F_54 ( & V_131 -> V_151 ) ;
F_55 ( V_131 ) ;
break;
}
}
F_56 ( & V_150 -> V_151 , & V_21 -> V_152 ) ;
}
static int F_57 ( struct V_20 * V_21 )
{
V_21 -> V_100 = 0 ;
V_21 -> V_101 = 0 ;
return F_49 ( V_21 ) ;
}
static int F_58 ( struct V_20 * V_21 , T_5 V_36 )
{
int V_32 ;
V_32 = F_34 ( V_21 , V_21 -> V_100 , V_21 -> V_101 ) ;
if ( V_32 ) {
F_8 ( L_35 , V_32 ) ;
return V_32 ;
}
F_3 ( V_21 -> V_25 , V_21 -> V_72 ) ;
return F_17 ( V_21 , V_36 ) ;
}
static int F_59 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_153 [ V_94 ] ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
memcpy ( V_153 , V_21 -> V_154 , F_60 ( sizeof( V_153 ) , V_21 -> V_155 ) ) ;
F_55 ( V_21 -> V_154 ) ;
V_21 -> V_154 = NULL ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_153 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_158 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_36 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_61 ( struct V_20 * V_21 )
{
const char * V_159 ;
T_4 V_160 ;
int error = 0 ;
error = F_49 ( V_21 ) ;
if ( error )
return error ;
V_160 = F_44 ( & V_21 -> V_147 , 4 , & V_159 ) ;
if ( ! V_159 ) {
F_8 ( L_37 ,
V_161 ) ;
return V_162 ;
}
V_21 -> V_154 = F_62 ( V_159 , V_160 , V_163 ) ;
if ( ! V_21 -> V_154 )
return - V_164 ;
V_21 -> V_155 = V_160 ;
return 0 ;
}
static int F_63 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_153 [ V_94 ] ;
int V_70 = 0 ;
T_1 * V_93 = V_5 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
V_70 = F_31 ( V_153 , sizeof( V_153 ) , * V_93 ) ;
if ( V_70 )
return V_70 ;
V_70 = 0 ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_153 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_165 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_24 ( & V_70 , V_21 , 10 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 4 ) ;
F_24 ( & V_70 , V_21 , 10 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_38 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_61 ) ;
}
static int F_64 ( struct V_20 * V_21 ,
T_1 * V_153 , bool V_168 , bool V_169 ,
bool V_170 , bool V_171 )
{
int V_70 = 0 ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_153 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 5 ) ;
F_24 ( & V_70 , V_21 , V_168 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 6 ) ;
F_24 ( & V_70 , V_21 , V_169 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_174 ) ;
F_24 ( & V_70 , V_21 , V_170 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_175 ) ;
F_24 ( & V_70 , V_21 , V_171 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
return V_70 ;
}
static inline int F_65 ( struct V_20 * V_21 , T_1 * V_153 ,
struct V_176 * V_177 )
{
int V_70 ;
V_70 = F_64 ( V_21 , V_153 , ! ! V_177 -> V_178 , ! ! V_177 -> V_179 ,
0 , 0 ) ;
if ( V_70 )
F_8 ( L_39 ) ;
return V_70 ;
}
static int F_66 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_153 [ V_94 ] ;
struct V_176 * V_177 = V_5 ;
T_1 V_93 ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
V_93 = V_177 -> V_180 . V_181 . V_93 ;
V_70 = F_31 ( V_153 , sizeof( V_153 ) , V_93 ) ;
if ( V_70 )
return V_70 ;
if ( V_93 == 0 )
V_70 = F_65 ( V_21 , V_153 , V_177 ) ;
else {
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_153 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_27 ( & V_70 , V_21 , V_177 -> V_182 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 4 ) ;
F_27 ( & V_70 , V_21 , V_177 -> V_183 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 5 ) ;
F_27 ( & V_70 , V_21 , ! ! V_177 -> V_178 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 6 ) ;
F_27 ( & V_70 , V_21 , ! ! V_177 -> V_179 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
}
if ( V_70 ) {
F_8 ( L_40 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_67 ( struct V_20 * V_21 ,
enum V_184 V_185 ,
enum V_184 V_186 ,
const char * V_187 ,
T_1 V_188 )
{
T_2 V_100 ;
int V_70 = 0 ;
if ( V_187 == NULL && V_185 != V_189 ) {
F_8 ( L_41 \
L_42 , V_161 ) ;
return V_162 ;
}
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
V_100 = V_190 ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_191 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_192 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_27 ( & V_70 , V_21 , V_100 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_186 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , 1 ) ;
switch ( V_185 ) {
case V_189 :
F_24 ( & V_70 , V_21 , V_104 ) ;
break;
case V_193 :
case V_194 :
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 0 ) ;
F_30 ( & V_70 , V_21 , V_187 , V_188 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_185 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
break;
default:
F_8 ( L_43 , V_185 ) ;
return V_162 ;
}
if ( V_70 ) {
F_8 ( L_44 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_51 ) ;
}
static int F_68 ( struct V_20 * V_21 , void * V_5 )
{
return F_67 ( V_21 , V_189 ,
V_195 , NULL , 0 ) ;
}
static int F_69 ( struct V_20 * V_21 , void * V_5 )
{
int V_32 ;
const T_1 * V_187 = V_21 -> V_154 ;
if ( ! V_187 ) {
const struct V_181 * V_196 = V_5 ;
V_32 = F_67 ( V_21 , V_194 ,
V_195 ,
V_196 -> V_187 ,
V_196 -> V_188 ) ;
} else {
V_32 = F_67 ( V_21 , V_194 ,
V_195 ,
V_187 , V_21 -> V_155 ) ;
F_55 ( V_187 ) ;
V_21 -> V_154 = NULL ;
}
return V_32 ;
}
static int F_70 ( struct V_20 * V_21 , void * V_5 )
{
struct V_181 * V_187 = V_5 ;
return F_67 ( V_21 , V_193 ,
V_197 ,
V_187 -> V_187 , V_187 -> V_188 ) ;
}
static int F_71 ( struct V_20 * V_21 , void * V_5 )
{
struct V_198 * V_180 = V_5 ;
T_1 V_199 [ V_94 ] ;
T_4 V_160 = V_180 -> V_181 . V_188 ;
int V_70 = 0 ;
T_1 * V_187 = V_180 -> V_181 . V_187 ;
T_2 V_100 = V_190 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
if ( V_180 -> V_12 ) {
V_70 = F_32 ( V_199 , sizeof( V_199 ) ,
V_180 -> V_181 . V_93 ) ;
if ( V_70 )
return V_70 ;
} else if ( V_180 -> V_200 != V_201 && ! V_180 -> V_12 ) {
V_70 = F_32 ( V_199 , sizeof( V_199 ) ,
V_180 -> V_200 - 1 ) ;
if ( V_70 )
return V_70 ;
} else
memcpy ( V_199 , V_95 [ V_193 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_191 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_192 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_27 ( & V_70 , V_21 , V_100 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_197 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , 1 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 0 ) ;
F_30 ( & V_70 , V_21 , V_187 , V_160 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_30 ( & V_70 , V_21 , V_199 , V_94 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_45 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_51 ) ;
}
static int F_72 ( struct V_20 * V_21 , void * V_5 )
{
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_195 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_202 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_46 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_73 ( struct V_20 * V_21 , void * V_5 )
{
struct V_198 * V_180 = V_5 ;
T_1 V_153 [ V_94 ] ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
memcpy ( V_153 , V_95 [ V_98 ] , V_94 ) ;
V_153 [ 7 ] = V_180 -> V_200 ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_153 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 5 ) ;
F_24 ( & V_70 , V_21 , V_203 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_47 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_74 ( struct V_20 * V_21 , void * V_5 )
{
struct V_198 * V_180 = V_5 ;
T_1 V_153 [ V_94 ] ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
if ( F_31 ( V_153 , sizeof( V_153 ) , V_180 -> V_181 . V_93 ) < 0 )
return - V_73 ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_153 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_204 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_48 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_75 ( struct V_20 * V_21 , void * V_5 )
{
T_1 * V_205 = V_5 ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_206 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 2 ) ;
F_24 ( & V_70 , V_21 , * V_205 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_49 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_76 ( struct V_20 * V_21 , void * V_5 )
{
T_1 * V_207 = V_5 ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_206 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 1 ) ;
F_24 ( & V_70 , V_21 , * V_207 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_50 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_77 ( T_1 * V_187 , T_4 V_188 , T_1 * V_208 ,
struct V_20 * V_21 )
{
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_208 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_30 ( & V_70 , V_21 , V_187 , V_188 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
return V_70 ;
}
static int F_78 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_208 [ V_94 ] ;
struct V_198 * V_209 = V_5 ;
memcpy ( V_208 , V_95 [ V_210 ] , V_94 ) ;
if ( V_209 -> V_200 != V_201 ) {
V_208 [ 5 ] = 0x03 ;
if ( V_209 -> V_12 )
V_208 [ 7 ] = V_209 -> V_181 . V_93 + 1 ;
else
V_208 [ 7 ] = V_209 -> V_200 ;
}
if ( F_77 ( V_209 -> V_181 . V_187 , V_209 -> V_181 . V_188 ,
V_208 , V_21 ) ) {
F_8 ( L_51 ) ;
return - V_73 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_79 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_208 [ V_94 ] ;
struct V_181 * V_187 = V_5 ;
memcpy ( V_208 , V_95 [ V_211 ] , V_94 ) ;
if ( F_77 ( V_187 -> V_187 , V_187 -> V_188 , V_208 , V_21 ) ) {
F_8 ( L_52 ) ;
return - V_73 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_80 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_212 [ V_94 ] ;
T_1 V_213 [ V_94 ] ;
struct V_214 * V_215 = V_5 ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
memcpy ( V_212 , V_95 [ V_216 ] ,
V_94 ) ;
if ( V_215 -> V_217 == V_218 )
memcpy ( V_212 , V_95 [ V_219 ] ,
V_94 ) ;
V_212 [ 7 ] = V_215 -> V_180 . V_181 . V_93 ;
memcpy ( V_213 , V_95 [ V_98 ] , V_94 ) ;
V_213 [ 7 ] = V_215 -> V_180 . V_200 ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_212 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] ,
V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_30 ( & V_70 , V_21 ,
V_95 [ V_220 ] ,
V_94 / 2 ) ;
F_30 ( & V_70 , V_21 , V_213 , V_94 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_30 ( & V_70 , V_21 ,
V_95 [ V_220 ] ,
V_94 / 2 ) ;
F_30 ( & V_70 , V_21 , V_213 , V_94 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_221 ] ,
V_94 / 2 ) ;
F_24 ( & V_70 , V_21 , 1 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_53 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_81 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_212 [ V_94 ] ;
struct V_214 * V_215 = V_5 ;
T_1 V_222 = 1 , V_223 = 1 ;
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
if ( F_31 ( V_212 , sizeof( V_212 ) ,
V_215 -> V_180 . V_181 . V_93 ) < 0 )
return - V_73 ;
switch ( V_215 -> V_217 ) {
case V_224 :
V_222 = 0 ;
V_223 = 1 ;
break;
case V_218 :
V_222 = 0 ;
V_223 = 0 ;
break;
case V_225 :
break;
default:
F_8 ( L_54 ) ;
return V_162 ;
}
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_212 , V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_172 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_173 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_174 ) ;
F_24 ( & V_70 , V_21 , V_222 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_175 ) ;
F_24 ( & V_70 , V_21 , V_223 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_55 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_82 ( struct V_20 * V_21 , void * V_5 )
{
T_1 V_212 [ V_94 ] ;
T_1 V_222 = 1 , V_223 = 1 ;
struct V_214 * V_215 = V_5 ;
int V_32 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
if ( F_31 ( V_212 , sizeof( V_212 ) ,
V_215 -> V_180 . V_181 . V_93 ) < 0 )
return - V_73 ;
switch ( V_215 -> V_217 ) {
case V_224 :
V_222 = 0 ;
V_223 = 1 ;
break;
case V_218 :
V_222 = 0 ;
V_223 = 0 ;
break;
case V_225 :
break;
default:
F_8 ( L_56 ) ;
return V_162 ;
}
V_32 = F_64 ( V_21 , V_212 , 1 , 1 ,
V_222 , V_223 ) ;
if ( V_32 < 0 ) {
F_8 ( L_55 ) ;
return V_32 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_83 ( struct V_20 * V_21 , void * V_5 )
{
struct V_226 * V_227 = V_5 ;
T_1 V_228 [ V_94 ] ;
T_1 V_229 = 0x83 ;
int V_70 = 0 , V_122 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_197 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_230 ] ,
V_94 ) ;
if ( V_227 -> V_12 ) {
V_70 = F_31 ( V_228 , sizeof( V_228 ) ,
V_227 -> V_93 [ 0 ] ) ;
if ( V_70 )
return V_70 ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , V_229 ) ;
F_24 ( & V_70 , V_21 , 6 ) ;
F_24 ( & V_70 , V_21 , 0 ) ;
F_24 ( & V_70 , V_21 , 0 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_30 ( & V_70 , V_21 , V_228 , V_94 ) ;
for ( V_122 = 1 ; V_122 < V_227 -> V_231 ; V_122 ++ ) {
V_228 [ 7 ] = V_227 -> V_93 [ V_122 ] ;
F_30 ( & V_70 , V_21 , V_228 , V_94 ) ;
}
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
} else {
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
}
if ( V_70 ) {
F_8 ( L_57 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_49 ) ;
}
static int F_84 ( struct V_20 * V_21 )
{
T_1 V_232 ;
int error = 0 ;
error = F_49 ( V_21 ) ;
if ( error )
return error ;
V_232 = F_45 ( & V_21 -> V_147 , 4 ) ;
if ( V_232 != V_233 ) {
F_8 ( L_58 ) ;
return - V_234 ;
}
return 0 ;
}
static int F_85 ( struct V_20 * V_21 , void * V_5 )
{
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_197 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_165 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_24 ( & V_70 , V_21 , 6 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 4 ) ;
F_24 ( & V_70 , V_21 , 6 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_59 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_84 ) ;
}
static int F_86 ( struct V_20 * V_21 )
{
const char * V_235 ;
T_4 strlen ;
int error = 0 ;
error = F_49 ( V_21 ) ;
if ( error )
return error ;
strlen = F_44 ( & V_21 -> V_147 , 4 , & V_235 ) ;
if ( ! V_235 ) {
F_8 ( L_60 , V_161 ) ;
return V_162 ;
}
V_21 -> V_154 = F_62 ( V_235 , strlen , V_163 ) ;
if ( ! V_21 -> V_154 )
return - V_164 ;
V_21 -> V_155 = strlen ;
return 0 ;
}
static int F_87 ( struct V_20 * V_21 , void * V_5 )
{
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_156 ) ;
F_30 ( & V_70 , V_21 , V_95 [ V_236 ] ,
V_94 ) ;
F_30 ( & V_70 , V_21 , V_157 [ V_165 ] , V_94 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_103 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_166 ) ;
F_24 ( & V_70 , V_21 , 4 ) ;
F_24 ( & V_70 , V_21 , 3 ) ;
F_24 ( & V_70 , V_21 , V_167 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
F_24 ( & V_70 , V_21 , V_104 ) ;
if ( V_70 ) {
F_8 ( L_61 ) ;
return V_70 ;
}
return F_58 ( V_21 , F_86 ) ;
}
static int F_88 ( struct V_20 * V_21 , void * V_5 )
{
int V_70 = 0 ;
F_50 ( V_21 ) ;
F_33 ( V_21 , V_21 -> V_23 ) ;
F_24 ( & V_70 , V_21 , V_145 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_58 ( V_21 , F_57 ) ;
}
static int F_20 ( struct V_20 * V_21 )
{
const struct V_43 V_237 [] = {
{ F_88 , } ,
{ NULL , }
} ;
V_21 -> V_46 = V_237 ;
return F_19 ( V_21 ) ;
}
static inline void F_89 ( struct V_20 * V_21 ,
const struct V_43 * V_46 )
{
V_21 -> V_46 = V_46 ;
V_21 -> V_101 = 0 ;
V_21 -> V_100 = 0 ;
V_21 -> V_154 = NULL ;
}
static int F_90 ( struct V_20 * V_21 )
{
const struct V_43 V_46 [] = {
{ F_23 , } ,
{ NULL , }
} ;
int V_32 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_46 ) ;
V_32 = F_19 ( V_21 ) ;
V_21 -> V_49 = ! V_32 ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static void F_93 ( struct V_20 * V_21 )
{
struct V_149 * V_239 , * F_19 ;
F_91 ( & V_21 -> V_238 ) ;
F_94 (suspend, next, &dev->unlk_lst, node) {
F_54 ( & V_239 -> V_151 ) ;
F_55 ( V_239 ) ;
}
F_92 ( & V_21 -> V_238 ) ;
}
void F_95 ( struct V_20 * V_21 )
{
if ( ! V_21 )
return;
F_93 ( V_21 ) ;
F_55 ( V_21 ) ;
}
struct V_20 * F_96 ( void * V_5 , T_8 * V_22 )
{
struct V_20 * V_21 ;
V_21 = F_97 ( sizeof( * V_21 ) , V_163 ) ;
if ( ! V_21 )
return NULL ;
F_98 ( & V_21 -> V_152 ) ;
F_99 ( & V_21 -> V_238 ) ;
V_21 -> V_5 = V_5 ;
V_21 -> V_22 = V_22 ;
if ( F_90 ( V_21 ) != 0 ) {
F_6 ( L_62 ) ;
F_55 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
static int F_100 ( struct V_20 * V_21 ,
struct V_198 * V_240 )
{
const struct V_43 V_241 [] = {
{ F_23 , } ,
{ F_71 , V_240 } ,
{ F_63 , & V_240 -> V_181 . V_93 } ,
{ F_59 , } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_241 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_101 ( struct V_20 * V_21 ,
struct V_198 * V_240 )
{
const struct V_43 V_241 [] = {
{ F_23 , } ,
{ F_71 , V_240 } ,
{ F_74 , V_240 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_241 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_102 ( struct V_20 * V_21 ,
struct V_242 * V_243 )
{
const struct V_43 V_244 [] = {
{ F_23 , } ,
{ F_70 , & V_243 -> V_187 } ,
{ F_75 , & V_243 -> V_245 } ,
{ F_88 , } ,
{ F_70 , & V_243 -> V_187 } ,
{ F_76 , & V_243 -> V_245 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
if ( V_243 -> V_245 != V_246 &&
V_243 -> V_245 != V_247 )
return - V_110 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_244 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_103 ( struct V_20 * V_21 , struct V_214 * V_248 )
{
struct V_149 * V_239 ;
V_239 = F_104 ( sizeof( * V_239 ) , V_163 ) ;
if ( ! V_239 )
return - V_164 ;
V_239 -> V_249 = * V_248 ;
V_239 -> V_93 = V_248 -> V_180 . V_181 . V_93 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , NULL ) ;
F_52 ( V_21 , V_239 ) ;
F_92 ( & V_21 -> V_238 ) ;
return 0 ;
}
static int F_105 ( struct V_20 * V_21 ,
struct V_214 * V_248 )
{
const struct V_43 V_46 [] = {
{ F_23 , } ,
{ F_70 , & V_248 -> V_180 . V_181 } ,
{ F_80 , V_248 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
if ( V_248 -> V_217 != V_224 &&
V_248 -> V_217 != V_218 ) {
F_8 ( L_63 ) ;
return - V_110 ;
}
if ( V_248 -> V_180 . V_200 < V_250 ||
V_248 -> V_180 . V_200 > V_251 ) {
F_8 ( L_64 ,
V_248 -> V_180 . V_200 ) ;
return - V_110 ;
}
if ( V_248 -> V_180 . V_12 ) {
F_8 ( L_65 ,
V_161 ) ;
return - V_110 ;
}
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_46 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_106 ( struct V_20 * V_21 , struct V_181 * V_252 )
{
const struct V_43 V_253 [] = {
{ F_23 , } ,
{ F_69 , V_252 } ,
{ F_72 , } ,
{ NULL , }
} ;
int V_32 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_253 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
if ( ! V_32 )
F_93 ( V_21 ) ;
return V_32 ;
}
static int F_107 ( struct V_20 * V_21 ,
struct V_214 * V_248 )
{
const struct V_43 V_254 [] = {
{ F_23 , } ,
{ F_71 , & V_248 -> V_180 } ,
{ F_81 , V_248 } ,
{ F_88 , } ,
{ NULL , }
} ;
const struct V_43 V_255 [] = {
{ F_23 , } ,
{ F_71 , & V_248 -> V_180 } ,
{ F_82 , V_248 } ,
{ F_88 , } ,
{ NULL , }
} ;
V_21 -> V_46 = V_248 -> V_180 . V_12 ? V_255 : V_254 ;
return F_19 ( V_21 ) ;
}
static int V_214 ( struct V_20 * V_21 ,
struct V_214 * V_248 )
{
int V_32 ;
if ( V_248 -> V_180 . V_200 < V_201 ||
V_248 -> V_180 . V_200 > V_251 )
return - V_110 ;
F_91 ( & V_21 -> V_238 ) ;
V_32 = F_107 ( V_21 , V_248 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_108 ( struct V_20 * V_21 , struct V_181 * V_252 )
{
const struct V_43 V_256 [] = {
{ F_23 , } ,
{ F_68 , } ,
{ F_87 , } ,
{ F_88 , } ,
{ F_69 , V_252 } ,
{ F_79 , V_252 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
if ( ! V_21 )
return - V_234 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_256 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_109 ( struct V_20 * V_21 , struct V_226 * V_226 )
{
const struct V_43 V_257 [] = {
{ F_23 , } ,
{ F_69 , & V_226 -> V_187 } ,
{ F_85 , } ,
{ F_83 , V_226 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
if ( ! V_226 -> V_231 || V_226 -> V_231 > V_258 )
return - V_110 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_257 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_110 ( struct V_20 * V_21 ,
struct V_176 * V_259 )
{
const struct V_43 V_260 [] = {
{ F_23 , } ,
{ F_71 , & V_259 -> V_180 } ,
{ F_66 , V_259 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_260 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_111 ( struct V_20 * V_21 , struct V_261 * V_262 )
{
const struct V_43 V_263 [] = {
{ F_23 , } ,
{ F_71 , & V_262 -> V_180 } ,
{ F_78 , & V_262 -> V_264 } ,
{ F_88 , } ,
{ NULL }
} ;
int V_32 ;
if ( V_262 -> V_180 . V_200 < V_201 ||
V_262 -> V_180 . V_200 > V_251 ||
V_262 -> V_264 . V_200 < V_201 ||
V_262 -> V_264 . V_200 > V_251 )
return - V_110 ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_263 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
static int F_112 ( struct V_20 * V_21 ,
struct V_198 * V_240 )
{
const struct V_43 V_265 [] = {
{ F_23 , } ,
{ F_70 , & V_240 -> V_181 } ,
{ F_73 , V_240 } ,
{ F_88 , } ,
{ NULL , }
} ;
int V_32 ;
if ( V_240 -> V_200 < V_250 ||
V_240 -> V_200 > V_251 ) {
F_8 ( L_66 , V_240 -> V_200 ) ;
return - V_110 ;
}
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , V_265 ) ;
V_32 = F_19 ( V_21 ) ;
F_92 ( & V_21 -> V_238 ) ;
return V_32 ;
}
bool F_113 ( struct V_20 * V_21 )
{
struct V_149 * V_239 ;
bool V_266 = false ;
int V_32 = 0 ;
if ( ! V_21 )
return false ;
if ( ! V_21 -> V_49 )
return false ;
F_91 ( & V_21 -> V_238 ) ;
F_89 ( V_21 , NULL ) ;
F_53 (suspend, &dev->unlk_lst, node) {
V_21 -> V_101 = 0 ;
V_21 -> V_100 = 0 ;
V_32 = F_107 ( V_21 , & V_239 -> V_249 ) ;
if ( V_32 ) {
F_22 ( L_67 ,
V_239 -> V_249 . V_180 . V_181 . V_93 ,
V_239 -> V_249 . V_180 . V_12 ) ;
V_266 = true ;
}
}
F_92 ( & V_21 -> V_238 ) ;
return V_266 ;
}
int F_114 ( struct V_20 * V_21 , unsigned int V_25 , void T_9 * V_267 )
{
void * V_268 ;
int V_32 = - V_269 ;
if ( ! F_115 ( V_270 ) )
return - V_271 ;
if ( ! V_21 )
return - V_272 ;
if ( ! V_21 -> V_49 ) {
F_8 ( L_68 ) ;
return - V_272 ;
}
V_268 = F_116 ( V_267 , F_117 ( V_25 ) ) ;
if ( F_47 ( V_268 ) )
return F_118 ( V_268 ) ;
switch ( V_25 ) {
case V_273 :
V_32 = F_103 ( V_21 , V_268 ) ;
break;
case V_274 :
V_32 = V_214 ( V_21 , V_268 ) ;
break;
case V_275 :
V_32 = F_108 ( V_21 , V_268 ) ;
break;
case V_276 :
V_32 = F_109 ( V_21 , V_268 ) ;
break;
case V_277 :
V_32 = F_111 ( V_21 , V_268 ) ;
break;
case V_278 :
V_32 = F_112 ( V_21 , V_268 ) ;
break;
case V_279 :
V_32 = F_106 ( V_21 , V_268 ) ;
break;
case V_280 :
V_32 = F_110 ( V_21 , V_268 ) ;
break;
case V_281 :
V_32 = F_105 ( V_21 , V_268 ) ;
break;
case V_282 :
V_32 = F_102 ( V_21 , V_268 ) ;
break;
case V_283 :
V_32 = F_101 ( V_21 , V_268 ) ;
break;
case V_284 :
V_32 = F_100 ( V_21 , V_268 ) ;
break;
default:
F_22 ( L_69 , V_25 ) ;
}
F_55 ( V_268 ) ;
return V_32 ;
}
