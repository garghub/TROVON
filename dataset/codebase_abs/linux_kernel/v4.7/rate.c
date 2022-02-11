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
struct V_1 * V_2 , T_1 V_29 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = & V_2 -> V_2 ;
void * V_11 = V_2 -> V_12 ;
struct V_15 * V_16 ;
if ( V_7 && V_7 -> V_25 -> V_30 ) {
F_3 () ;
V_16 = F_4 ( V_2 -> V_5 -> V_17 . V_16 ) ;
if ( F_5 ( ! V_16 ) ) {
F_6 () ;
return;
}
F_7 ( & V_2 -> V_24 ) ;
V_7 -> V_25 -> V_30 ( V_7 -> V_27 , V_14 , & V_16 -> V_21 ,
V_10 , V_11 , V_29 ) ;
F_8 ( & V_2 -> V_24 ) ;
F_6 () ;
}
F_11 ( V_4 , V_2 -> V_5 , & V_2 -> V_2 , V_29 ) ;
}
int F_12 ( const struct V_31 * V_25 )
{
struct V_32 * V_33 ;
if ( ! V_25 -> V_34 )
return - V_35 ;
F_13 ( & V_36 ) ;
F_14 (alg, &rate_ctrl_algs, list) {
if ( ! strcmp ( V_33 -> V_25 -> V_34 , V_25 -> V_34 ) ) {
F_5 ( 1 ) ;
F_15 ( & V_36 ) ;
return - V_37 ;
}
}
V_33 = F_16 ( sizeof( * V_33 ) , V_38 ) ;
if ( V_33 == NULL ) {
F_15 ( & V_36 ) ;
return - V_39 ;
}
V_33 -> V_25 = V_25 ;
F_17 ( & V_33 -> V_40 , & V_41 ) ;
F_15 ( & V_36 ) ;
return 0 ;
}
void F_18 ( const struct V_31 * V_25 )
{
struct V_32 * V_33 ;
F_13 ( & V_36 ) ;
F_14 (alg, &rate_ctrl_algs, list) {
if ( V_33 -> V_25 == V_25 ) {
F_19 ( & V_33 -> V_40 ) ;
F_20 ( V_33 ) ;
break;
}
}
F_15 ( & V_36 ) ;
}
static const struct V_31 *
F_21 ( const char * V_34 )
{
struct V_32 * V_33 ;
const struct V_31 * V_25 = NULL ;
if ( ! V_34 )
return NULL ;
F_13 ( & V_36 ) ;
F_14 (alg, &rate_ctrl_algs, list) {
if ( ! strcmp ( V_33 -> V_25 -> V_34 , V_34 ) ) {
V_25 = V_33 -> V_25 ;
break;
}
}
F_15 ( & V_36 ) ;
return V_25 ;
}
static const struct V_31 *
F_22 ( const char * V_34 )
{
const struct V_31 * V_25 ;
const char * V_42 ;
F_23 ( V_43 ) ;
if ( ! V_34 )
V_42 = V_44 ;
else
V_42 = V_34 ;
V_25 = F_21 ( V_42 ) ;
if ( ! V_25 && V_34 )
V_25 = F_21 ( V_44 ) ;
if ( ! V_25 && strlen ( V_45 ) )
V_25 = F_21 ( V_45 ) ;
F_24 ( V_43 ) ;
return V_25 ;
}
static T_2 F_25 ( struct V_46 * V_46 , char T_3 * V_47 ,
T_4 V_48 , T_5 * V_49 )
{
struct V_6 * V_7 = V_46 -> V_50 ;
int V_51 = strlen ( V_7 -> V_25 -> V_34 ) ;
return F_26 ( V_47 , V_48 , V_49 ,
V_7 -> V_25 -> V_34 , V_51 ) ;
}
static struct V_6 * F_27 ( const char * V_34 ,
struct V_3 * V_4 )
{
struct V_52 * V_53 = NULL ;
struct V_6 * V_7 ;
V_7 = F_28 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_4 = V_4 ;
V_7 -> V_25 = F_22 ( V_34 ) ;
if ( ! V_7 -> V_25 )
goto free;
#ifdef F_29
V_53 = F_30 ( L_1 , V_4 -> V_18 . V_19 -> V_53 ) ;
V_4 -> V_54 . V_55 = V_53 ;
F_31 ( L_2 , 0400 , V_53 , V_7 , & V_56 ) ;
#endif
V_7 -> V_27 = V_7 -> V_25 -> V_57 ( & V_4 -> V_18 , V_53 ) ;
if ( ! V_7 -> V_27 )
goto free;
return V_7 ;
free:
F_20 ( V_7 ) ;
return NULL ;
}
static void F_32 ( struct V_6 * V_58 )
{
V_58 -> V_25 -> free ( V_58 -> V_27 ) ;
#ifdef F_29
F_33 ( V_58 -> V_4 -> V_54 . V_55 ) ;
V_58 -> V_4 -> V_54 . V_55 = NULL ;
#endif
F_20 ( V_58 ) ;
}
static bool F_34 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_62 ;
struct V_63 * V_64 = (struct V_63 * ) V_62 -> V_65 ;
struct V_66 * V_67 = F_35 ( V_62 ) ;
T_6 V_68 ;
V_68 = V_64 -> V_69 ;
return ( V_67 -> V_70 & ( V_71 |
V_72 ) ) ||
! F_36 ( V_68 ) ;
}
static void F_37 ( T_7 * V_73 , T_1 V_74 ,
struct V_13 * V_14 )
{
T_8 V_75 ;
if ( V_74 == 0 )
return;
if ( * V_73 < 0 )
return;
if ( V_74 & ( 1 << * V_73 ) )
return;
for ( V_75 = * V_73 + 1 ; V_75 <= V_14 -> V_76 ; V_75 ++ ) {
if ( V_74 & ( 1 << V_75 ) ) {
* V_73 = V_75 ;
return;
}
}
}
static void F_38 ( struct V_77 * V_18 ,
struct V_13 * V_14 ,
struct V_9 * V_2 ,
struct V_66 * V_67 ,
T_1 V_78 )
{
int V_75 ;
T_1 V_79 =
F_39 ( & V_18 -> V_80 . V_81 ) ;
if ( ( V_14 -> V_23 == V_82 ) &&
( V_67 -> V_70 & V_83 ) )
V_79 |= V_84 ;
V_67 -> V_85 . V_86 [ 0 ] . V_73 = 0 ;
for ( V_75 = 0 ; V_75 < V_14 -> V_76 ; V_75 ++ ) {
if ( ! ( V_78 & F_40 ( V_75 ) ) )
continue;
if ( ( V_79 & V_14 -> V_87 [ V_75 ] . V_70 ) != V_79 )
continue;
if ( ! F_41 ( V_2 , V_14 -> V_23 , V_75 ) )
continue;
V_67 -> V_85 . V_86 [ 0 ] . V_73 = V_75 ;
break;
}
F_42 ( V_75 == V_14 -> V_76 ,
L_3 ,
V_2 ? V_2 -> V_88 [ V_14 -> V_23 ] : - 1 ,
V_78 , V_79 ) ;
V_67 -> V_85 . V_86 [ 0 ] . V_48 =
( V_67 -> V_70 & V_71 ) ?
1 : V_18 -> V_89 ;
V_67 -> V_85 . V_90 = 1 ;
}
bool F_43 ( struct V_9 * V_91 ,
void * V_11 ,
struct V_59 * V_60 )
{
struct V_66 * V_67 = F_35 ( V_60 -> V_62 ) ;
struct V_13 * V_14 = V_60 -> V_14 ;
struct V_1 * V_2 ;
int V_92 ;
bool V_93 = false ;
if ( ! V_91 || ! V_11 || F_34 ( V_60 ) ) {
F_38 ( V_60 -> V_18 , V_14 , V_91 , V_67 ,
V_60 -> V_94 ) ;
if ( ! V_91 && V_60 -> V_95 ) {
V_92 = V_60 -> V_96 -> V_92 [ V_14 -> V_23 ] ;
if ( V_92 > 0 ) {
V_67 -> V_85 . V_86 [ 0 ] . V_73 = V_92 - 1 ;
return true ;
}
V_93 = true ;
} else if ( V_91 ) {
V_2 = F_44 ( V_91 , struct V_1 , V_2 ) ;
if ( F_45 ( & V_2 -> V_5 -> V_17 ) )
V_93 = true ;
}
if ( V_93 )
F_37 ( & V_67 -> V_85 . V_86 [ 0 ] . V_73 ,
V_60 -> V_96 -> V_74 ,
V_14 ) ;
return true ;
}
return false ;
}
static bool F_46 ( T_7 * V_97 , int V_76 , T_1 V_98 )
{
int V_99 ;
for ( V_99 = * V_97 ; V_99 >= 0 ; V_99 -- ) {
if ( V_98 & ( 1 << V_99 ) ) {
* V_97 = V_99 ;
return true ;
}
}
for ( V_99 = * V_97 + 1 ; V_99 < V_76 ; V_99 ++ ) {
if ( V_98 & ( 1 << V_99 ) ) {
* V_97 = V_99 ;
return true ;
}
}
return false ;
}
static bool F_47 ( T_7 * V_97 , T_8 * V_100 )
{
int V_75 , V_99 ;
int V_101 , V_102 ;
V_101 = * V_97 / 8 ;
V_102 = * V_97 % 8 ;
if ( V_101 < 0 || V_101 >= V_103 )
return false ;
for ( V_75 = V_101 ; V_75 >= 0 ; V_75 -- ) {
for ( V_99 = V_102 ; V_99 >= 0 ; V_99 -- )
if ( V_100 [ V_75 ] & F_40 ( V_99 ) ) {
* V_97 = V_75 * 8 + V_99 ;
return true ;
}
V_102 = 7 ;
}
V_101 = ( * V_97 + 1 ) / 8 ;
V_102 = ( * V_97 + 1 ) % 8 ;
for ( V_75 = V_101 ; V_75 < V_103 ; V_75 ++ ) {
for ( V_99 = V_102 ; V_99 < 8 ; V_99 ++ )
if ( V_100 [ V_75 ] & F_40 ( V_99 ) ) {
* V_97 = V_75 * 8 + V_99 ;
return true ;
}
V_102 = 0 ;
}
return false ;
}
static bool F_48 ( T_7 * V_97 , T_9 * V_104 )
{
int V_75 , V_99 ;
int V_101 , V_102 ;
V_101 = * V_97 >> 4 ;
V_102 = * V_97 & 0xf ;
if ( V_101 < 0 || V_101 >= V_105 )
return false ;
for ( V_75 = V_101 ; V_75 >= 0 ; V_75 -- ) {
for ( V_99 = V_102 ; V_99 >= 0 ; V_99 -- ) {
if ( V_104 [ V_75 ] & F_40 ( V_99 ) ) {
* V_97 = ( V_75 << 4 ) | V_99 ;
return true ;
}
}
V_102 = 15 ;
}
V_101 = ( * V_97 + 1 ) >> 4 ;
V_102 = ( * V_97 + 1 ) & 0xf ;
for ( V_75 = V_101 ; V_75 < V_105 ; V_75 ++ ) {
for ( V_99 = V_102 ; V_99 < 16 ; V_99 ++ ) {
if ( V_104 [ V_75 ] & F_40 ( V_99 ) ) {
* V_97 = ( V_75 << 4 ) | V_99 ;
return true ;
}
}
V_102 = 0 ;
}
return false ;
}
static void F_49 ( T_7 * V_97 , T_9 * V_79 ,
struct V_13 * V_14 ,
enum V_106 V_107 ,
T_1 V_98 ,
T_8 V_100 [ V_103 ] ,
T_9 V_104 [ V_105 ] )
{
if ( * V_79 & V_108 ) {
if ( F_48 ( V_97 , V_104 ) )
return;
* V_97 = 0 ;
* V_79 &= ( V_109 |
V_110 |
V_111 ) ;
* V_79 |= V_112 ;
if ( V_107 == V_113 )
* V_79 |= V_114 ;
if ( F_47 ( V_97 , V_100 ) )
return;
* V_79 &= ~ ( V_112 |
V_114 ) ;
if ( F_46 ( V_97 , V_14 -> V_76 ,
V_98 ) )
return;
} else if ( * V_79 & V_112 ) {
if ( F_47 ( V_97 , V_100 ) )
return;
* V_97 = 0 ;
* V_79 &= ( V_109 |
V_110 |
V_111 ) ;
if ( F_46 ( V_97 , V_14 -> V_76 ,
V_98 ) )
return;
} else {
if ( F_46 ( V_97 , V_14 -> V_76 ,
V_98 ) )
return;
switch ( V_107 ) {
case V_115 :
case V_116 :
case V_117 :
return;
default:
break;
}
* V_97 = 0 ;
* V_79 &= ( V_109 |
V_110 |
V_111 ) ;
* V_79 |= V_112 ;
if ( V_107 == V_113 )
* V_79 |= V_114 ;
if ( F_47 ( V_97 , V_100 ) )
return;
}
}
static void F_50 ( struct V_118 * V_17 ,
struct V_13 * V_14 ,
struct V_66 * V_67 ,
struct V_119 * V_86 ,
int V_120 )
{
struct V_121 * V_122 ;
bool V_123 = false ;
int V_75 ;
if ( ! ( V_86 [ 0 ] . V_70 &
( V_112 | V_108 ) ) ) {
T_1 V_74 = V_17 -> V_96 . V_74 ;
T_7 V_124 = V_74 ? F_51 ( V_74 ) - 1 : 0 ;
V_122 = & V_14 -> V_87 [ V_86 [ 0 ] . V_73 ] ;
for ( V_75 = 0 ; V_75 < V_14 -> V_76 ; V_75 ++ ) {
if ( ! ( V_74 & F_40 ( V_75 ) ) )
continue;
if ( V_14 -> V_87 [ V_75 ] . V_125 > V_122 -> V_125 )
continue;
if ( V_14 -> V_87 [ V_124 ] . V_125 <
V_14 -> V_87 [ V_75 ] . V_125 )
V_124 = V_75 ;
}
V_67 -> V_85 . V_126 = V_124 ;
}
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( V_123 ) {
V_86 [ V_75 ] . V_73 = - 1 ;
continue;
}
if ( V_86 [ V_75 ] . V_73 < 0 ) {
V_123 = true ;
continue;
}
if ( V_86 [ V_75 ] . V_70 & V_112 ) {
F_5 ( V_86 [ V_75 ] . V_73 > 76 ) ;
if ( ! ( V_86 [ V_75 ] . V_70 & V_109 ) &&
V_67 -> V_85 . V_127 )
V_86 [ V_75 ] . V_70 |=
V_110 ;
continue;
}
if ( V_86 [ V_75 ] . V_70 & V_108 ) {
F_5 ( F_52 ( & V_86 [ V_75 ] ) > 9 ) ;
continue;
}
if ( V_67 -> V_85 . V_128 ) {
V_86 [ V_75 ] . V_70 |= V_109 ;
V_67 -> V_85 . V_127 = false ;
}
if ( F_53 ( V_86 [ V_75 ] . V_73 >= V_14 -> V_76 ) ) {
V_86 [ V_75 ] . V_73 = - 1 ;
continue;
}
V_122 = & V_14 -> V_87 [ V_86 [ V_75 ] . V_73 ] ;
if ( V_67 -> V_85 . V_129 &&
V_122 -> V_70 & V_130 )
V_86 [ V_75 ] . V_70 |= V_111 ;
if ( ! ( V_86 [ V_75 ] . V_70 & V_109 ) &&
V_67 -> V_85 . V_127 &&
V_122 -> V_70 & V_84 )
V_86 [ V_75 ] . V_70 |= V_110 ;
}
}
static void F_54 ( struct V_9 * V_2 ,
struct V_66 * V_67 ,
struct V_119 * V_86 ,
int V_120 )
{
struct V_131 * V_132 = NULL ;
int V_75 ;
if ( V_2 && ! V_67 -> V_85 . V_90 )
V_132 = F_4 ( V_2 -> V_86 ) ;
V_120 = F_55 ( int , V_120 , V_133 ) ;
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( V_75 < F_56 ( V_67 -> V_85 . V_86 ) &&
V_67 -> V_85 . V_86 [ V_75 ] . V_73 >= 0 &&
V_67 -> V_85 . V_86 [ V_75 ] . V_48 ) {
if ( V_86 != V_67 -> V_85 . V_86 )
V_86 [ V_75 ] = V_67 -> V_85 . V_86 [ V_75 ] ;
} else if ( V_132 ) {
V_86 [ V_75 ] . V_73 = V_132 -> V_122 [ V_75 ] . V_73 ;
V_86 [ V_75 ] . V_70 = V_132 -> V_122 [ V_75 ] . V_70 ;
if ( V_67 -> V_85 . V_128 )
V_86 [ V_75 ] . V_48 = V_132 -> V_122 [ V_75 ] . V_134 ;
else if ( V_67 -> V_85 . V_127 )
V_86 [ V_75 ] . V_48 = V_132 -> V_122 [ V_75 ] . V_135 ;
else
V_86 [ V_75 ] . V_48 = V_132 -> V_122 [ V_75 ] . V_48 ;
} else {
V_86 [ V_75 ] . V_73 = - 1 ;
V_86 [ V_75 ] . V_48 = 0 ;
}
if ( V_86 [ V_75 ] . V_73 < 0 || ! V_86 [ V_75 ] . V_48 )
break;
}
}
static bool F_57 ( struct V_136 * V_5 ,
struct V_13 * V_14 ,
struct V_9 * V_2 , T_1 * V_98 ,
T_8 V_100 [ V_103 ] ,
T_9 V_104 [ V_105 ] )
{
T_1 V_75 , V_70 ;
* V_98 = V_5 -> V_137 [ V_14 -> V_23 ] ;
V_70 = F_39 ( & V_5 -> V_17 . V_96 . V_81 ) ;
for ( V_75 = 0 ; V_75 < V_14 -> V_76 ; V_75 ++ ) {
if ( ( V_70 & V_14 -> V_87 [ V_75 ] . V_70 ) != V_70 )
* V_98 &= ~ F_40 ( V_75 ) ;
}
if ( * V_98 == ( 1 << V_14 -> V_76 ) - 1 &&
! V_5 -> V_138 [ V_14 -> V_23 ] &&
! V_5 -> V_139 [ V_14 -> V_23 ] )
return false ;
if ( V_5 -> V_138 [ V_14 -> V_23 ] )
memcpy ( V_100 , V_5 -> V_140 [ V_14 -> V_23 ] ,
V_103 ) ;
else
memset ( V_100 , 0xff , V_103 ) ;
if ( V_5 -> V_139 [ V_14 -> V_23 ] )
memcpy ( V_104 , V_5 -> V_141 [ V_14 -> V_23 ] ,
sizeof( T_9 ) * V_105 ) ;
else
memset ( V_104 , 0xff , sizeof( T_9 ) * V_105 ) ;
if ( V_2 ) {
T_6 V_142 ;
T_9 V_143 [ V_105 ] ;
* V_98 &= V_2 -> V_88 [ V_14 -> V_23 ] ;
for ( V_75 = 0 ; V_75 < V_103 ; V_75 ++ )
V_100 [ V_75 ] &= V_2 -> V_144 . V_145 . V_146 [ V_75 ] ;
V_142 = V_2 -> V_147 . V_148 . V_149 ;
F_58 ( V_142 , V_143 ) ;
for ( V_75 = 0 ; V_75 < V_105 ; V_75 ++ )
V_104 [ V_75 ] &= V_143 [ V_75 ] ;
}
return true ;
}
static void
F_59 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_131 * V_86 )
{
int V_75 ;
T_1 V_98 ;
T_8 V_100 [ V_103 ] ;
T_9 V_104 [ V_105 ] ;
enum V_106 V_107 ;
if ( ! F_57 ( V_2 -> V_5 , V_14 , & V_2 -> V_2 , & V_98 ,
V_100 , V_104 ) )
return;
V_107 = V_2 -> V_5 -> V_17 . V_96 . V_81 . V_150 ;
for ( V_75 = 0 ; V_75 < V_133 ; V_75 ++ ) {
if ( V_86 -> V_122 [ V_75 ] . V_73 < 0 )
break;
F_49 ( & V_86 -> V_122 [ V_75 ] . V_73 , & V_86 -> V_122 [ V_75 ] . V_70 ,
V_14 , V_107 , V_98 , V_100 ,
V_104 ) ;
}
}
static void F_60 ( struct V_136 * V_5 ,
struct V_9 * V_2 ,
struct V_13 * V_14 ,
struct V_119 * V_86 ,
int V_120 )
{
enum V_106 V_107 ;
T_8 V_100 [ V_103 ] ;
T_1 V_98 ;
T_9 V_79 , V_104 [ V_105 ] ;
int V_75 ;
if ( ! F_57 ( V_5 , V_14 , V_2 , & V_98 , V_100 ,
V_104 ) )
return;
V_107 = V_5 -> V_17 . V_96 . V_81 . V_150 ;
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ ) {
if ( V_86 [ V_75 ] . V_73 < 0 )
break;
V_79 = V_86 [ V_75 ] . V_70 ;
F_49 ( & V_86 [ V_75 ] . V_73 , & V_79 , V_14 ,
V_107 , V_98 , V_100 , V_104 ) ;
V_86 [ V_75 ] . V_70 = V_79 ;
}
}
void F_61 ( struct V_118 * V_17 ,
struct V_9 * V_2 ,
struct V_61 * V_62 ,
struct V_119 * V_151 ,
int V_120 )
{
struct V_136 * V_5 ;
struct V_63 * V_64 = (struct V_63 * ) V_62 -> V_65 ;
struct V_66 * V_67 = F_35 ( V_62 ) ;
struct V_13 * V_14 ;
F_54 ( V_2 , V_67 , V_151 , V_120 ) ;
if ( ! V_17 )
return;
V_5 = F_62 ( V_17 ) ;
V_14 = V_5 -> V_4 -> V_18 . V_19 -> V_20 [ V_67 -> V_23 ] ;
if ( F_36 ( V_64 -> V_69 ) )
F_60 ( V_5 , V_2 , V_14 , V_151 , V_120 ) ;
if ( V_151 [ 0 ] . V_73 < 0 )
F_38 ( & V_5 -> V_4 -> V_18 , V_14 , V_2 , V_67 ,
V_5 -> V_137 [ V_67 -> V_23 ] ) ;
if ( V_2 )
F_50 ( V_17 , V_14 , V_67 , V_151 , V_120 ) ;
}
void F_63 ( struct V_136 * V_5 ,
struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_6 * V_7 = V_5 -> V_4 -> V_8 ;
void * V_11 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_66 * V_67 = F_35 ( V_60 -> V_62 ) ;
int V_75 ;
if ( V_2 && F_64 ( V_2 , V_28 ) ) {
V_10 = & V_2 -> V_2 ;
V_11 = V_2 -> V_12 ;
}
for ( V_75 = 0 ; V_75 < V_152 ; V_75 ++ ) {
V_67 -> V_85 . V_86 [ V_75 ] . V_73 = - 1 ;
V_67 -> V_85 . V_86 [ V_75 ] . V_70 = 0 ;
V_67 -> V_85 . V_86 [ V_75 ] . V_48 = 0 ;
}
if ( F_65 ( & V_5 -> V_4 -> V_18 , V_153 ) )
return;
if ( V_10 ) {
F_7 ( & V_2 -> V_24 ) ;
V_7 -> V_25 -> V_154 ( V_7 -> V_27 , V_10 , V_11 , V_60 ) ;
F_8 ( & V_2 -> V_24 ) ;
} else {
V_7 -> V_25 -> V_154 ( V_7 -> V_27 , NULL , NULL , V_60 ) ;
}
if ( F_65 ( & V_5 -> V_4 -> V_18 , V_155 ) )
return;
F_61 ( & V_5 -> V_17 , V_10 , V_60 -> V_62 ,
V_67 -> V_85 . V_86 ,
F_56 ( V_67 -> V_85 . V_86 ) ) ;
}
int F_66 ( struct V_77 * V_18 ,
struct V_9 * V_91 ,
struct V_131 * V_86 )
{
struct V_1 * V_2 = F_44 ( V_91 , struct V_1 , V_2 ) ;
struct V_131 * V_156 ;
struct V_13 * V_14 ;
V_14 = V_18 -> V_19 -> V_20 [ F_67 ( V_2 -> V_5 ) ] ;
F_59 ( V_2 , V_14 , V_86 ) ;
V_156 = F_68 ( V_91 -> V_86 , true ) ;
F_69 ( V_91 -> V_86 , V_86 ) ;
if ( V_156 )
F_70 ( V_156 , V_157 ) ;
F_71 ( F_72 ( V_18 ) , V_2 -> V_5 , V_91 ) ;
return 0 ;
}
int F_73 ( struct V_3 * V_4 ,
const char * V_34 )
{
struct V_6 * V_7 ;
F_74 () ;
if ( V_4 -> V_158 )
return - V_159 ;
if ( F_65 ( & V_4 -> V_18 , V_153 ) ) {
if ( F_5 ( ! V_4 -> V_25 -> V_160 ) )
return - V_35 ;
return 0 ;
}
V_7 = F_27 ( V_34 , V_4 ) ;
if ( ! V_7 ) {
F_75 ( V_4 -> V_18 . V_19 ,
L_4 ) ;
return - V_161 ;
}
F_5 ( V_4 -> V_8 ) ;
V_4 -> V_8 = V_7 ;
F_76 ( V_4 -> V_18 . V_19 , L_5 ,
V_7 -> V_25 -> V_34 ) ;
return 0 ;
}
void F_77 ( struct V_3 * V_4 )
{
struct V_6 * V_7 ;
V_7 = V_4 -> V_8 ;
if ( ! V_7 )
return;
V_4 -> V_8 = NULL ;
F_32 ( V_7 ) ;
}
