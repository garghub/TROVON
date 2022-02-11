void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_2 ;
void * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
F_2 ( V_2 ) ;
if ( ! V_7 )
return;
F_3 () ;
V_16 = F_4 ( V_2 -> V_5 -> V_17 . V_16 ) ;
if ( F_5 ( ! V_16 ) ) {
F_6 () ;
return;
}
V_14 = V_4 -> V_18 . V_19 -> V_20 [ V_16 -> V_21 . V_22 -> V_23 ] ;
F_7 ( & V_2 -> V_24 ) ;
V_7 -> V_25 -> V_26 ( V_7 -> V_27 , V_14 , & V_16 -> V_21 , V_10 ,
V_11 ) ;
F_8 ( & V_2 -> V_24 ) ;
F_6 () ;
F_9 ( V_2 , V_28 ) ;
}
void F_10 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_1 * V_2 = F_11 ( V_30 -> V_2 , struct V_1 , V_2 ) ;
void * V_11 = V_2 -> V_12 ;
if ( ! V_7 || ! F_12 ( V_2 , V_28 ) )
return;
F_7 ( & V_2 -> V_24 ) ;
if ( V_7 -> V_25 -> V_31 )
V_7 -> V_25 -> V_31 ( V_7 -> V_27 , V_14 , V_11 , V_30 ) ;
else if ( V_30 -> V_32 )
V_7 -> V_25 -> V_33 ( V_7 -> V_27 , V_14 , V_30 -> V_2 , V_11 , V_30 -> V_32 ) ;
else
F_13 ( 1 ) ;
F_8 ( & V_2 -> V_24 ) ;
}
void F_14 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_1 * V_2 , T_1 V_34 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_2 ;
void * V_11 = V_2 -> V_12 ;
struct V_15 * V_16 ;
if ( V_7 && V_7 -> V_25 -> V_35 ) {
F_3 () ;
V_16 = F_4 ( V_2 -> V_5 -> V_17 . V_16 ) ;
if ( F_5 ( ! V_16 ) ) {
F_6 () ;
return;
}
F_7 ( & V_2 -> V_24 ) ;
V_7 -> V_25 -> V_35 ( V_7 -> V_27 , V_14 , & V_16 -> V_21 ,
V_10 , V_11 , V_34 ) ;
F_8 ( & V_2 -> V_24 ) ;
F_6 () ;
}
F_15 ( V_4 , V_2 -> V_5 , & V_2 -> V_2 , V_34 ) ;
}
int F_16 ( const struct V_36 * V_25 )
{
struct V_37 * V_38 ;
if ( ! V_25 -> V_39 )
return - V_40 ;
F_17 ( & V_41 ) ;
F_18 (alg, &rate_ctrl_algs, list) {
if ( ! strcmp ( V_38 -> V_25 -> V_39 , V_25 -> V_39 ) ) {
F_5 ( 1 ) ;
F_19 ( & V_41 ) ;
return - V_42 ;
}
}
V_38 = F_20 ( sizeof( * V_38 ) , V_43 ) ;
if ( V_38 == NULL ) {
F_19 ( & V_41 ) ;
return - V_44 ;
}
V_38 -> V_25 = V_25 ;
F_21 ( & V_38 -> V_45 , & V_46 ) ;
F_19 ( & V_41 ) ;
return 0 ;
}
void F_22 ( const struct V_36 * V_25 )
{
struct V_37 * V_38 ;
F_17 ( & V_41 ) ;
F_18 (alg, &rate_ctrl_algs, list) {
if ( V_38 -> V_25 == V_25 ) {
F_23 ( & V_38 -> V_45 ) ;
F_24 ( V_38 ) ;
break;
}
}
F_19 ( & V_41 ) ;
}
static const struct V_36 *
F_25 ( const char * V_39 )
{
struct V_37 * V_38 ;
const struct V_36 * V_25 = NULL ;
if ( ! V_39 )
return NULL ;
F_17 ( & V_41 ) ;
F_18 (alg, &rate_ctrl_algs, list) {
if ( ! strcmp ( V_38 -> V_25 -> V_39 , V_39 ) ) {
V_25 = V_38 -> V_25 ;
break;
}
}
F_19 ( & V_41 ) ;
return V_25 ;
}
static const struct V_36 *
F_26 ( const char * V_39 )
{
const struct V_36 * V_25 ;
const char * V_47 ;
F_27 ( V_48 ) ;
if ( ! V_39 )
V_47 = V_49 ;
else
V_47 = V_39 ;
V_25 = F_25 ( V_47 ) ;
if ( ! V_25 && V_39 )
V_25 = F_25 ( V_49 ) ;
if ( ! V_25 && ( strlen ( V_50 ) > 0 ) )
V_25 = F_25 ( V_50 ) ;
F_28 ( V_48 ) ;
return V_25 ;
}
static T_2 F_29 ( struct V_51 * V_51 , char T_3 * V_52 ,
T_4 V_53 , T_5 * V_54 )
{
struct V_6 * V_7 = V_51 -> V_55 ;
int V_56 = strlen ( V_7 -> V_25 -> V_39 ) ;
return F_30 ( V_52 , V_53 , V_54 ,
V_7 -> V_25 -> V_39 , V_56 ) ;
}
static struct V_6 * F_31 ( const char * V_39 ,
struct V_3 * V_4 )
{
struct V_57 * V_58 = NULL ;
struct V_6 * V_7 ;
V_7 = F_32 ( sizeof( struct V_6 ) , V_43 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_25 = F_26 ( V_39 ) ;
if ( ! V_7 -> V_25 )
goto free;
#ifdef F_33
V_58 = F_34 ( L_1 , V_4 -> V_18 . V_19 -> V_58 ) ;
V_4 -> V_59 . V_60 = V_58 ;
F_35 ( L_2 , 0400 , V_58 , V_7 , & V_61 ) ;
#endif
V_7 -> V_27 = V_7 -> V_25 -> V_62 ( & V_4 -> V_18 , V_58 ) ;
if ( ! V_7 -> V_27 )
goto free;
return V_7 ;
free:
F_24 ( V_7 ) ;
return NULL ;
}
static void F_36 ( struct V_3 * V_4 ,
struct V_6 * V_63 )
{
V_63 -> V_25 -> free ( V_63 -> V_27 ) ;
#ifdef F_33
F_37 ( V_4 -> V_59 . V_60 ) ;
V_4 -> V_59 . V_60 = NULL ;
#endif
F_24 ( V_63 ) ;
}
void F_38 ( struct V_64 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_13 * V_14 ;
T_1 V_65 , V_66 = V_5 -> V_17 . V_67 . V_66 ;
enum V_68 V_23 ;
if ( F_5 ( ! V_5 -> V_17 . V_67 . V_69 . V_22 ) )
return;
if ( F_13 ( ! V_66 ) )
return;
V_23 = V_5 -> V_17 . V_67 . V_69 . V_22 -> V_23 ;
V_65 = V_5 -> V_70 [ V_23 ] ;
V_14 = V_4 -> V_18 . V_19 -> V_20 [ V_23 ] ;
if ( V_65 & V_66 )
return;
F_39 ( V_5 ,
L_3 ,
V_66 , V_65 , V_23 ) ;
V_5 -> V_70 [ V_23 ] = ( 1 << V_14 -> V_71 ) - 1 ;
}
static bool F_40 ( struct V_72 * V_73 )
{
struct V_74 * V_32 = V_73 -> V_32 ;
struct V_75 * V_76 = (struct V_75 * ) V_32 -> V_77 ;
struct V_78 * V_79 = F_41 ( V_32 ) ;
T_6 V_80 ;
V_80 = V_76 -> V_81 ;
return ( V_79 -> V_82 & ( V_83 |
V_84 ) ) ||
! F_42 ( V_80 ) ;
}
static void F_43 ( T_7 * V_85 , T_1 V_66 ,
struct V_13 * V_14 )
{
T_8 V_86 ;
if ( V_66 == 0 )
return;
if ( * V_85 < 0 )
return;
if ( V_66 & ( 1 << * V_85 ) )
return;
for ( V_86 = * V_85 + 1 ; V_86 <= V_14 -> V_71 ; V_86 ++ ) {
if ( V_66 & ( 1 << V_86 ) ) {
* V_85 = V_86 ;
return;
}
}
}
static void F_44 ( struct V_87 * V_18 ,
struct V_13 * V_14 ,
struct V_9 * V_2 ,
struct V_78 * V_79 ,
T_1 V_88 )
{
int V_86 ;
T_1 V_89 =
F_45 ( & V_18 -> V_90 . V_69 ) ;
if ( ( V_14 -> V_23 == V_91 ) &&
( V_79 -> V_82 & V_92 ) )
V_89 |= V_93 ;
V_79 -> V_94 . V_95 [ 0 ] . V_85 = 0 ;
for ( V_86 = 0 ; V_86 < V_14 -> V_71 ; V_86 ++ ) {
if ( ! ( V_88 & F_46 ( V_86 ) ) )
continue;
if ( ( V_89 & V_14 -> V_96 [ V_86 ] . V_82 ) != V_89 )
continue;
if ( ! F_47 ( V_2 , V_14 -> V_23 , V_86 ) )
continue;
V_79 -> V_94 . V_95 [ 0 ] . V_85 = V_86 ;
break;
}
F_48 ( V_86 == V_14 -> V_71 ,
L_4 ,
V_2 ? V_2 -> V_97 [ V_14 -> V_23 ] : - 1 ,
V_88 , V_89 ) ;
V_79 -> V_94 . V_95 [ 0 ] . V_53 =
( V_79 -> V_82 & V_83 ) ?
1 : V_18 -> V_98 ;
V_79 -> V_94 . V_99 = 1 ;
}
bool F_49 ( struct V_9 * V_100 ,
void * V_11 ,
struct V_72 * V_73 )
{
struct V_78 * V_79 = F_41 ( V_73 -> V_32 ) ;
struct V_13 * V_14 = V_73 -> V_14 ;
struct V_1 * V_2 ;
int V_101 ;
bool V_102 = false ;
if ( ! V_100 || ! V_11 || F_40 ( V_73 ) ) {
F_44 ( V_73 -> V_18 , V_14 , V_100 , V_79 ,
V_73 -> V_103 ) ;
if ( ! V_100 && V_73 -> V_104 ) {
V_101 = V_73 -> V_67 -> V_101 [ V_14 -> V_23 ] ;
if ( V_101 > 0 ) {
V_79 -> V_94 . V_95 [ 0 ] . V_85 = V_101 - 1 ;
return true ;
}
V_102 = true ;
} else if ( V_100 ) {
V_2 = F_11 ( V_100 , struct V_1 , V_2 ) ;
if ( F_50 ( & V_2 -> V_5 -> V_17 ) )
V_102 = true ;
}
if ( V_102 )
F_43 ( & V_79 -> V_94 . V_95 [ 0 ] . V_85 ,
V_73 -> V_67 -> V_66 ,
V_14 ) ;
return true ;
}
return false ;
}
static bool F_51 ( T_7 * V_105 , int V_71 , T_1 V_106 )
{
int V_107 ;
for ( V_107 = * V_105 ; V_107 >= 0 ; V_107 -- ) {
if ( V_106 & ( 1 << V_107 ) ) {
* V_105 = V_107 ;
return true ;
}
}
for ( V_107 = * V_105 + 1 ; V_107 < V_71 ; V_107 ++ ) {
if ( V_106 & ( 1 << V_107 ) ) {
* V_105 = V_107 ;
return true ;
}
}
return false ;
}
static bool F_52 ( T_7 * V_105 , T_8 * V_108 )
{
int V_86 , V_107 ;
int V_109 , V_110 ;
V_109 = * V_105 / 8 ;
V_110 = * V_105 % 8 ;
if ( V_109 < 0 || V_109 >= V_111 )
return false ;
for ( V_86 = V_109 ; V_86 >= 0 ; V_86 -- ) {
for ( V_107 = V_110 ; V_107 >= 0 ; V_107 -- )
if ( V_108 [ V_86 ] & F_46 ( V_107 ) ) {
* V_105 = V_86 * 8 + V_107 ;
return true ;
}
V_110 = 7 ;
}
V_109 = ( * V_105 + 1 ) / 8 ;
V_110 = ( * V_105 + 1 ) % 8 ;
for ( V_86 = V_109 ; V_86 < V_111 ; V_86 ++ ) {
for ( V_107 = V_110 ; V_107 < 8 ; V_107 ++ )
if ( V_108 [ V_86 ] & F_46 ( V_107 ) ) {
* V_105 = V_86 * 8 + V_107 ;
return true ;
}
V_110 = 0 ;
}
return false ;
}
static bool F_53 ( T_7 * V_105 , T_9 * V_112 )
{
int V_86 , V_107 ;
int V_109 , V_110 ;
V_109 = * V_105 >> 4 ;
V_110 = * V_105 & 0xf ;
if ( V_109 < 0 || V_109 >= V_113 )
return false ;
for ( V_86 = V_109 ; V_86 >= 0 ; V_86 -- ) {
for ( V_107 = V_110 ; V_107 >= 0 ; V_107 -- ) {
if ( V_112 [ V_86 ] & F_46 ( V_107 ) ) {
* V_105 = ( V_86 << 4 ) | V_107 ;
return true ;
}
}
V_110 = 15 ;
}
V_109 = ( * V_105 + 1 ) >> 4 ;
V_110 = ( * V_105 + 1 ) & 0xf ;
for ( V_86 = V_109 ; V_86 < V_113 ; V_86 ++ ) {
for ( V_107 = V_110 ; V_107 < 16 ; V_107 ++ ) {
if ( V_112 [ V_86 ] & F_46 ( V_107 ) ) {
* V_105 = ( V_86 << 4 ) | V_107 ;
return true ;
}
}
V_110 = 0 ;
}
return false ;
}
static void F_54 ( T_7 * V_105 , T_9 * V_89 ,
struct V_13 * V_14 ,
enum V_114 V_115 ,
T_1 V_106 ,
T_8 V_108 [ V_111 ] ,
T_9 V_112 [ V_113 ] )
{
if ( * V_89 & V_116 ) {
if ( F_53 ( V_105 , V_112 ) )
return;
* V_105 = 0 ;
* V_89 &= ( V_117 |
V_118 |
V_119 ) ;
* V_89 |= V_120 ;
if ( V_115 == V_121 )
* V_89 |= V_122 ;
if ( F_52 ( V_105 , V_108 ) )
return;
* V_89 &= ~ ( V_120 |
V_122 ) ;
if ( F_51 ( V_105 , V_14 -> V_71 ,
V_106 ) )
return;
} else if ( * V_89 & V_120 ) {
if ( F_52 ( V_105 , V_108 ) )
return;
* V_105 = 0 ;
* V_89 &= ( V_117 |
V_118 |
V_119 ) ;
if ( F_51 ( V_105 , V_14 -> V_71 ,
V_106 ) )
return;
} else {
if ( F_51 ( V_105 , V_14 -> V_71 ,
V_106 ) )
return;
switch ( V_115 ) {
case V_123 :
case V_124 :
case V_125 :
return;
default:
break;
}
* V_105 = 0 ;
* V_89 &= ( V_117 |
V_118 |
V_119 ) ;
* V_89 |= V_120 ;
if ( V_115 == V_121 )
* V_89 |= V_122 ;
if ( F_52 ( V_105 , V_108 ) )
return;
}
}
static void F_55 ( struct V_126 * V_17 ,
struct V_13 * V_14 ,
struct V_78 * V_79 ,
struct V_127 * V_95 ,
int V_128 )
{
struct V_129 * V_130 ;
bool V_131 = false ;
int V_86 ;
if ( ! ( V_95 [ 0 ] . V_82 &
( V_120 | V_116 ) ) ) {
T_1 V_66 = V_17 -> V_67 . V_66 ;
T_7 V_132 = V_66 ? F_56 ( V_66 ) - 1 : 0 ;
V_130 = & V_14 -> V_96 [ V_95 [ 0 ] . V_85 ] ;
for ( V_86 = 0 ; V_86 < V_14 -> V_71 ; V_86 ++ ) {
if ( ! ( V_66 & F_46 ( V_86 ) ) )
continue;
if ( V_14 -> V_96 [ V_86 ] . V_133 > V_130 -> V_133 )
continue;
if ( V_14 -> V_96 [ V_132 ] . V_133 <
V_14 -> V_96 [ V_86 ] . V_133 )
V_132 = V_86 ;
}
V_79 -> V_94 . V_134 = V_132 ;
}
for ( V_86 = 0 ; V_86 < V_128 ; V_86 ++ ) {
if ( V_131 ) {
V_95 [ V_86 ] . V_85 = - 1 ;
continue;
}
if ( V_95 [ V_86 ] . V_85 < 0 ) {
V_131 = true ;
continue;
}
if ( V_95 [ V_86 ] . V_82 & V_120 ) {
F_5 ( V_95 [ V_86 ] . V_85 > 76 ) ;
if ( ! ( V_95 [ V_86 ] . V_82 & V_117 ) &&
V_79 -> V_94 . V_135 )
V_95 [ V_86 ] . V_82 |=
V_118 ;
continue;
}
if ( V_95 [ V_86 ] . V_82 & V_116 ) {
F_5 ( F_57 ( & V_95 [ V_86 ] ) > 9 ) ;
continue;
}
if ( V_79 -> V_94 . V_136 ) {
V_95 [ V_86 ] . V_82 |= V_117 ;
V_79 -> V_94 . V_135 = false ;
}
if ( F_13 ( V_95 [ V_86 ] . V_85 >= V_14 -> V_71 ) ) {
V_95 [ V_86 ] . V_85 = - 1 ;
continue;
}
V_130 = & V_14 -> V_96 [ V_95 [ V_86 ] . V_85 ] ;
if ( V_79 -> V_94 . V_137 &&
V_130 -> V_82 & V_138 )
V_95 [ V_86 ] . V_82 |= V_119 ;
if ( ! ( V_95 [ V_86 ] . V_82 & V_117 ) &&
V_79 -> V_94 . V_135 &&
V_130 -> V_82 & V_93 )
V_95 [ V_86 ] . V_82 |= V_118 ;
}
}
static void F_58 ( struct V_9 * V_2 ,
struct V_78 * V_79 ,
struct V_127 * V_95 ,
int V_128 )
{
struct V_139 * V_140 = NULL ;
int V_86 ;
if ( V_2 && ! V_79 -> V_94 . V_99 )
V_140 = F_4 ( V_2 -> V_95 ) ;
V_128 = F_59 ( int , V_128 , V_141 ) ;
for ( V_86 = 0 ; V_86 < V_128 ; V_86 ++ ) {
if ( V_86 < F_60 ( V_79 -> V_94 . V_95 ) &&
V_79 -> V_94 . V_95 [ V_86 ] . V_85 >= 0 &&
V_79 -> V_94 . V_95 [ V_86 ] . V_53 ) {
if ( V_95 != V_79 -> V_94 . V_95 )
V_95 [ V_86 ] = V_79 -> V_94 . V_95 [ V_86 ] ;
} else if ( V_140 ) {
V_95 [ V_86 ] . V_85 = V_140 -> V_130 [ V_86 ] . V_85 ;
V_95 [ V_86 ] . V_82 = V_140 -> V_130 [ V_86 ] . V_82 ;
if ( V_79 -> V_94 . V_136 )
V_95 [ V_86 ] . V_53 = V_140 -> V_130 [ V_86 ] . V_142 ;
else if ( V_79 -> V_94 . V_135 )
V_95 [ V_86 ] . V_53 = V_140 -> V_130 [ V_86 ] . V_143 ;
else
V_95 [ V_86 ] . V_53 = V_140 -> V_130 [ V_86 ] . V_53 ;
} else {
V_95 [ V_86 ] . V_85 = - 1 ;
V_95 [ V_86 ] . V_53 = 0 ;
}
if ( V_95 [ V_86 ] . V_85 < 0 || ! V_95 [ V_86 ] . V_53 )
break;
}
}
static bool F_61 ( struct V_64 * V_5 ,
struct V_13 * V_14 ,
struct V_9 * V_2 , T_1 * V_106 ,
T_8 V_108 [ V_111 ] ,
T_9 V_112 [ V_113 ] )
{
T_1 V_86 , V_82 ;
* V_106 = V_5 -> V_70 [ V_14 -> V_23 ] ;
V_82 = F_45 ( & V_5 -> V_17 . V_67 . V_69 ) ;
for ( V_86 = 0 ; V_86 < V_14 -> V_71 ; V_86 ++ ) {
if ( ( V_82 & V_14 -> V_96 [ V_86 ] . V_82 ) != V_82 )
* V_106 &= ~ F_46 ( V_86 ) ;
}
if ( * V_106 == ( 1 << V_14 -> V_71 ) - 1 &&
! V_5 -> V_144 [ V_14 -> V_23 ] &&
! V_5 -> V_145 [ V_14 -> V_23 ] )
return false ;
if ( V_5 -> V_144 [ V_14 -> V_23 ] )
memcpy ( V_108 , V_5 -> V_146 [ V_14 -> V_23 ] ,
V_111 ) ;
else
memset ( V_108 , 0xff , V_111 ) ;
if ( V_5 -> V_145 [ V_14 -> V_23 ] )
memcpy ( V_112 , V_5 -> V_147 [ V_14 -> V_23 ] ,
sizeof( T_9 ) * V_113 ) ;
else
memset ( V_112 , 0xff , sizeof( T_9 ) * V_113 ) ;
if ( V_2 ) {
T_6 V_148 ;
T_9 V_149 [ V_113 ] ;
* V_106 &= V_2 -> V_97 [ V_14 -> V_23 ] ;
for ( V_86 = 0 ; V_86 < V_111 ; V_86 ++ )
V_108 [ V_86 ] &= V_2 -> V_150 . V_151 . V_152 [ V_86 ] ;
V_148 = V_2 -> V_153 . V_154 . V_155 ;
F_62 ( V_148 , V_149 ) ;
for ( V_86 = 0 ; V_86 < V_113 ; V_86 ++ )
V_112 [ V_86 ] &= V_149 [ V_86 ] ;
}
return true ;
}
static void
F_63 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_139 * V_95 )
{
int V_86 ;
T_1 V_106 ;
T_8 V_108 [ V_111 ] ;
T_9 V_112 [ V_113 ] ;
enum V_114 V_115 ;
if ( ! F_61 ( V_2 -> V_5 , V_14 , & V_2 -> V_2 , & V_106 ,
V_108 , V_112 ) )
return;
V_115 = V_2 -> V_5 -> V_17 . V_67 . V_69 . V_156 ;
for ( V_86 = 0 ; V_86 < V_141 ; V_86 ++ ) {
if ( V_95 -> V_130 [ V_86 ] . V_85 < 0 )
break;
F_54 ( & V_95 -> V_130 [ V_86 ] . V_85 , & V_95 -> V_130 [ V_86 ] . V_82 ,
V_14 , V_115 , V_106 , V_108 ,
V_112 ) ;
}
}
static void F_64 ( struct V_64 * V_5 ,
struct V_9 * V_2 ,
struct V_13 * V_14 ,
struct V_127 * V_95 ,
int V_128 )
{
enum V_114 V_115 ;
T_8 V_108 [ V_111 ] ;
T_1 V_106 ;
T_9 V_89 , V_112 [ V_113 ] ;
int V_86 ;
if ( ! F_61 ( V_5 , V_14 , V_2 , & V_106 , V_108 ,
V_112 ) )
return;
V_115 = V_5 -> V_17 . V_67 . V_69 . V_156 ;
for ( V_86 = 0 ; V_86 < V_128 ; V_86 ++ ) {
if ( V_95 [ V_86 ] . V_85 < 0 )
break;
V_89 = V_95 [ V_86 ] . V_82 ;
F_54 ( & V_95 [ V_86 ] . V_85 , & V_89 , V_14 ,
V_115 , V_106 , V_108 , V_112 ) ;
V_95 [ V_86 ] . V_82 = V_89 ;
}
}
void F_65 ( struct V_126 * V_17 ,
struct V_9 * V_2 ,
struct V_74 * V_32 ,
struct V_127 * V_157 ,
int V_128 )
{
struct V_64 * V_5 ;
struct V_75 * V_76 = (struct V_75 * ) V_32 -> V_77 ;
struct V_78 * V_79 = F_41 ( V_32 ) ;
struct V_13 * V_14 ;
F_58 ( V_2 , V_79 , V_157 , V_128 ) ;
if ( ! V_17 )
return;
V_5 = F_66 ( V_17 ) ;
V_14 = V_5 -> V_4 -> V_18 . V_19 -> V_20 [ V_79 -> V_23 ] ;
if ( F_42 ( V_76 -> V_81 ) )
F_64 ( V_5 , V_2 , V_14 , V_157 , V_128 ) ;
if ( V_157 [ 0 ] . V_85 < 0 )
F_44 ( & V_5 -> V_4 -> V_18 , V_14 , V_2 , V_79 ,
V_5 -> V_70 [ V_79 -> V_23 ] ) ;
if ( V_2 )
F_55 ( V_17 , V_14 , V_79 , V_157 , V_128 ) ;
}
void F_67 ( struct V_64 * V_5 ,
struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_6 * V_7 = V_5 -> V_4 -> V_8 ;
void * V_11 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_78 * V_79 = F_41 ( V_73 -> V_32 ) ;
int V_86 ;
if ( V_2 && F_12 ( V_2 , V_28 ) ) {
V_10 = & V_2 -> V_2 ;
V_11 = V_2 -> V_12 ;
}
for ( V_86 = 0 ; V_86 < V_158 ; V_86 ++ ) {
V_79 -> V_94 . V_95 [ V_86 ] . V_85 = - 1 ;
V_79 -> V_94 . V_95 [ V_86 ] . V_82 = 0 ;
V_79 -> V_94 . V_95 [ V_86 ] . V_53 = 0 ;
}
if ( F_68 ( & V_5 -> V_4 -> V_18 , V_159 ) )
return;
if ( V_10 ) {
F_7 ( & V_2 -> V_24 ) ;
V_7 -> V_25 -> V_160 ( V_7 -> V_27 , V_10 , V_11 , V_73 ) ;
F_8 ( & V_2 -> V_24 ) ;
} else {
V_7 -> V_25 -> V_160 ( V_7 -> V_27 , NULL , NULL , V_73 ) ;
}
if ( F_68 ( & V_5 -> V_4 -> V_18 , V_161 ) )
return;
F_65 ( & V_5 -> V_17 , V_10 , V_73 -> V_32 ,
V_79 -> V_94 . V_95 ,
F_60 ( V_79 -> V_94 . V_95 ) ) ;
}
int F_69 ( struct V_87 * V_18 ,
struct V_9 * V_100 ,
struct V_139 * V_95 )
{
struct V_1 * V_2 = F_11 ( V_100 , struct V_1 , V_2 ) ;
struct V_139 * V_162 ;
struct V_13 * V_14 ;
V_14 = F_70 ( V_2 -> V_5 ) ;
if ( ! V_14 )
return - V_40 ;
F_63 ( V_2 , V_14 , V_95 ) ;
V_162 = F_71 ( V_100 -> V_95 , true ) ;
F_72 ( V_100 -> V_95 , V_95 ) ;
if ( V_162 )
F_73 ( V_162 , V_163 ) ;
F_74 ( F_75 ( V_18 ) , V_2 -> V_5 , V_100 ) ;
return 0 ;
}
int F_76 ( struct V_3 * V_4 ,
const char * V_39 )
{
struct V_6 * V_7 ;
F_77 () ;
if ( V_4 -> V_164 )
return - V_165 ;
if ( F_68 ( & V_4 -> V_18 , V_159 ) ) {
if ( F_5 ( ! V_4 -> V_25 -> V_166 ) )
return - V_40 ;
return 0 ;
}
V_7 = F_31 ( V_39 , V_4 ) ;
if ( ! V_7 ) {
F_78 ( V_4 -> V_18 . V_19 ,
L_5 ) ;
return - V_167 ;
}
F_5 ( V_4 -> V_8 ) ;
V_4 -> V_8 = V_7 ;
F_79 ( V_4 -> V_18 . V_19 , L_6 ,
V_7 -> V_25 -> V_39 ) ;
return 0 ;
}
void F_80 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
V_7 = V_4 -> V_8 ;
if ( ! V_7 )
return;
V_4 -> V_8 = NULL ;
F_36 ( V_4 , V_7 ) ;
}
