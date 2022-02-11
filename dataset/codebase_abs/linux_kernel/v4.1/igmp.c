static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
V_3 = F_4 (
V_2 ,
V_5 ) ;
else
V_3 = F_4 (
V_2 ,
V_6 ) ;
V_4 = F_5 ( V_3 ) ;
if ( V_4 <= 0 )
V_4 = 1 ;
return V_4 ;
}
static void F_6 ( struct V_7 * V_8 )
{
if ( F_7 ( & V_8 -> V_9 ) ) {
F_8 ( V_8 -> V_10 ) ;
F_9 ( V_8 , V_11 ) ;
}
}
static void F_10 ( struct V_7 * V_8 )
{
F_11 ( & V_8 -> V_12 ) ;
if ( F_12 ( & V_8 -> V_13 ) )
F_13 ( & V_8 -> V_9 ) ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = 0 ;
F_14 ( & V_8 -> V_12 ) ;
}
static void F_15 ( struct V_7 * V_8 , int V_17 )
{
int V_18 = F_16 () % V_17 ;
V_8 -> V_14 = 1 ;
if ( ! F_17 ( & V_8 -> V_13 , V_19 + V_18 + 2 ) )
F_18 ( & V_8 -> V_9 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_18 = F_16 () % V_2 -> V_20 ;
V_2 -> V_21 = 1 ;
if ( ! F_17 ( & V_2 -> V_22 , V_19 + V_18 + 2 ) )
F_20 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_23 )
{
int V_18 = F_16 () % V_23 ;
if ( ! F_17 ( & V_2 -> V_24 , V_19 + V_18 + 2 ) )
F_20 ( V_2 ) ;
}
static void F_22 ( struct V_7 * V_8 , int V_17 )
{
F_11 ( & V_8 -> V_12 ) ;
V_8 -> V_16 = 0 ;
if ( F_12 ( & V_8 -> V_13 ) ) {
if ( ( long ) ( V_8 -> V_13 . V_25 - V_19 ) < V_17 ) {
F_23 ( & V_8 -> V_13 ) ;
V_8 -> V_14 = 1 ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
F_13 ( & V_8 -> V_9 ) ;
}
F_15 ( V_8 , V_17 ) ;
F_14 ( & V_8 -> V_12 ) ;
}
static int F_24 ( struct V_7 * V_26 , struct V_27 * V_28 , int type ,
int V_29 , int V_30 )
{
switch ( type ) {
case V_31 :
case V_32 :
if ( V_29 || V_30 )
return 0 ;
if ( ! ( V_26 -> V_33 && ! V_28 -> V_34 ) ) {
if ( V_26 -> V_35 == V_36 )
return 1 ;
if ( V_28 -> V_37 [ V_36 ] )
return type == V_31 ;
return V_26 -> V_38 [ V_39 ] ==
V_28 -> V_37 [ V_39 ] ;
}
return 0 ;
case V_40 :
if ( V_29 || V_30 )
return 0 ;
return V_28 -> V_37 [ V_36 ] != 0 ;
case V_41 :
if ( V_29 || V_30 )
return 0 ;
if ( V_26 -> V_38 [ V_39 ] == 0 ||
V_28 -> V_37 [ V_36 ] )
return 0 ;
return V_26 -> V_38 [ V_39 ] ==
V_28 -> V_37 [ V_39 ] ;
case V_42 :
if ( V_29 || ! V_28 -> V_43 )
return 0 ;
return ( V_26 -> V_35 == V_36 ) ^ V_30 ;
case V_44 :
if ( V_26 -> V_35 == V_36 )
return V_29 || ( V_28 -> V_43 && V_30 ) ;
return V_28 -> V_43 && ! V_29 && ! V_30 ;
}
return 0 ;
}
static int
F_25 ( struct V_7 * V_26 , int type , int V_29 , int V_30 )
{
struct V_27 * V_28 ;
int V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) )
continue;
V_45 ++ ;
}
return V_45 ;
}
static struct V_48 * F_26 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_48 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
struct V_60 V_61 ;
int V_62 = F_28 ( V_50 ) ;
int V_63 = V_50 -> V_64 ;
unsigned int V_65 = V_51 ;
while ( 1 ) {
V_52 = F_29 ( V_65 + V_62 + V_63 ,
V_66 | V_67 ) ;
if ( V_52 )
break;
V_65 >>= 1 ;
if ( V_65 < 256 )
return NULL ;
}
V_52 -> V_68 = V_69 ;
V_54 = F_30 ( V_59 , & V_61 , NULL , V_70 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_31 ( V_54 ) ) {
F_32 ( V_52 ) ;
return NULL ;
}
F_33 ( V_52 , & V_54 -> V_73 ) ;
V_52 -> V_50 = V_50 ;
V_52 -> V_74 = F_34 ( V_52 ) -
F_35 ( V_51 , F_34 ( V_52 ) ) ;
F_36 ( V_52 , V_62 ) ;
F_37 ( V_52 ) ;
V_56 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_56 -> V_75 = 4 ;
V_56 -> V_76 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_56 -> V_77 = 0xc0 ;
V_56 -> V_78 = F_40 ( V_79 ) ;
V_56 -> V_80 = 1 ;
V_56 -> V_81 = V_61 . V_81 ;
V_56 -> V_82 = V_61 . V_82 ;
V_56 -> V_83 = V_71 ;
V_56 -> V_84 = 0 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 0 ] = V_86 ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 1 ] = 4 ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 2 ] = 0 ;
( ( V_85 * ) & V_56 [ 1 ] ) [ 3 ] = 0 ;
V_52 -> V_87 = V_52 -> V_88 + sizeof( struct V_55 ) + 4 ;
F_39 ( V_52 , sizeof( * V_58 ) ) ;
V_58 = F_42 ( V_52 ) ;
V_58 -> type = V_89 ;
V_58 -> V_90 = 0 ;
V_58 -> V_91 = 0 ;
V_58 -> V_92 = 0 ;
V_58 -> V_93 = 0 ;
return V_52 ;
}
static int F_43 ( struct V_48 * V_52 )
{
struct V_94 * V_58 = F_44 ( V_52 ) ;
const int V_95 = F_45 ( V_52 ) - F_46 ( V_52 ) ;
V_58 -> V_91 = F_47 ( F_44 ( V_52 ) , V_95 ) ;
return F_48 ( V_52 ) ;
}
static int F_49 ( struct V_7 * V_26 , int type , int V_96 , int V_97 )
{
return sizeof( struct V_98 ) + 4 * F_25 ( V_26 , type , V_96 , V_97 ) ;
}
static struct V_48 * F_50 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , struct V_98 * * V_99 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_100 ;
struct V_98 * V_101 ;
if ( ! V_52 )
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
if ( ! V_52 )
return NULL ;
V_101 = (struct V_98 * ) F_39 ( V_52 , sizeof( struct V_98 ) ) ;
V_101 -> V_102 = type ;
V_101 -> V_103 = 0 ;
V_101 -> V_104 = 0 ;
V_101 -> V_105 = V_26 -> V_106 ;
V_100 = F_42 ( V_52 ) ;
V_100 -> V_93 = F_40 ( F_51 ( V_100 -> V_93 ) + 1 ) ;
* V_99 = V_101 ;
return V_52 ;
}
static struct V_48 * F_52 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , int V_29 , int V_30 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_100 ;
struct V_98 * V_101 = NULL ;
struct V_27 * V_28 , * V_107 , * V_108 , * * V_109 ;
int V_45 , V_110 , V_111 , V_112 , V_113 ;
if ( V_26 -> V_106 == V_114 )
return V_52 ;
V_112 = type == V_31 ||
type == V_32 ;
V_113 = type == V_32 ||
type == V_41 ;
V_110 = V_45 = 0 ;
V_109 = V_30 ? & V_26 -> V_115 : & V_26 -> V_46 ;
if ( ! * V_109 )
goto V_116;
V_100 = V_52 ? F_42 ( V_52 ) : NULL ;
if ( V_113 ) {
if ( V_100 && V_100 -> V_93 &&
F_53 ( V_52 ) < F_49 ( V_26 , type , V_29 , V_30 ) ) {
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
}
}
V_111 = 1 ;
V_108 = NULL ;
for ( V_28 = * V_109 ; V_28 ; V_28 = V_107 ) {
T_1 * V_117 ;
V_107 = V_28 -> V_47 ;
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) ) {
V_108 = V_28 ;
continue;
}
if ( V_112 )
V_28 -> V_34 = 0 ;
if ( F_53 ( V_52 ) < sizeof( T_1 ) +
V_111 * sizeof( struct V_98 ) ) {
if ( V_113 && ! V_111 )
break;
if ( V_101 )
V_101 -> V_104 = F_40 ( V_45 ) ;
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_51 ) ;
V_111 = 1 ;
V_45 = 0 ;
}
if ( V_111 ) {
V_52 = F_50 ( V_52 , V_26 , type , & V_101 ) ;
V_111 = 0 ;
}
if ( ! V_52 )
return NULL ;
V_117 = ( T_1 * ) F_39 ( V_52 , sizeof( T_1 ) ) ;
* V_117 = V_28 -> V_118 ;
V_45 ++ ; V_110 ++ ;
if ( ( type == V_42 ||
type == V_44 ) && V_28 -> V_43 ) {
V_28 -> V_43 -- ;
if ( ( V_30 || V_29 ) && V_28 -> V_43 == 0 ) {
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
* V_109 = V_28 -> V_47 ;
F_54 ( V_28 ) ;
continue;
}
}
V_108 = V_28 ;
}
V_116:
if ( ! V_110 ) {
if ( type == V_42 ||
type == V_44 )
return V_52 ;
if ( V_26 -> V_119 || V_112 ) {
if ( V_52 && F_53 ( V_52 ) < sizeof( struct V_98 ) ) {
F_43 ( V_52 ) ;
V_52 = NULL ;
}
V_52 = F_50 ( V_52 , V_26 , type , & V_101 ) ;
}
}
if ( V_101 )
V_101 -> V_104 = F_40 ( V_45 ) ;
if ( V_112 )
V_26 -> V_33 = 0 ;
return V_52 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_7 * V_26 )
{
struct V_48 * V_52 = NULL ;
int type ;
if ( ! V_26 ) {
F_56 () ;
F_57 (in_dev, pmc) {
if ( V_26 -> V_106 == V_114 )
continue;
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
F_58 () ;
} else {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
if ( ! V_52 )
return 0 ;
return F_43 ( V_52 ) ;
}
static void F_59 ( struct V_27 * * V_120 )
{
struct V_27 * V_108 , * V_107 , * V_28 ;
V_108 = NULL ;
for ( V_28 = * V_120 ; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
if ( V_28 -> V_43 == 0 ) {
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
* V_120 = V_28 -> V_47 ;
F_54 ( V_28 ) ;
} else
V_108 = V_28 ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_121 , * V_122 ;
struct V_48 * V_52 = NULL ;
int type , V_123 ;
F_56 () ;
F_11 ( & V_2 -> V_124 ) ;
V_121 = NULL ;
for ( V_26 = V_2 -> V_125 ; V_26 ; V_26 = V_122 ) {
V_122 = V_26 -> V_126 ;
if ( V_26 -> V_35 == V_36 ) {
type = V_44 ;
V_123 = V_44 ;
V_52 = F_52 ( V_52 , V_26 , type , 1 , 0 ) ;
V_52 = F_52 ( V_52 , V_26 , V_123 , 1 , 1 ) ;
}
if ( V_26 -> V_119 ) {
if ( V_26 -> V_35 == V_39 ) {
type = V_40 ;
V_52 = F_52 ( V_52 , V_26 , type , 1 , 0 ) ;
}
V_26 -> V_119 -- ;
if ( V_26 -> V_119 == 0 ) {
F_59 ( & V_26 -> V_115 ) ;
F_59 ( & V_26 -> V_46 ) ;
}
}
if ( V_26 -> V_119 == 0 && ! V_26 -> V_115 && ! V_26 -> V_46 ) {
if ( V_121 )
V_121 -> V_126 = V_122 ;
else
V_2 -> V_125 = V_122 ;
F_8 ( V_26 -> V_10 ) ;
F_54 ( V_26 ) ;
} else
V_121 = V_26 ;
}
F_14 ( & V_2 -> V_124 ) ;
F_57 (in_dev, pmc) {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] ) {
type = V_44 ;
V_123 = V_42 ;
} else {
type = V_42 ;
V_123 = V_44 ;
}
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
V_52 = F_52 ( V_52 , V_26 , V_123 , 0 , 1 ) ;
if ( V_26 -> V_119 ) {
if ( V_26 -> V_35 == V_39 )
type = V_41 ;
else
type = V_40 ;
V_52 = F_52 ( V_52 , V_26 , type , 0 , 0 ) ;
V_26 -> V_119 -- ;
}
F_14 ( & V_26 -> V_12 ) ;
}
F_58 () ;
if ( ! V_52 )
return;
( void ) F_43 ( V_52 ) ;
}
static int F_61 ( struct V_1 * V_2 , struct V_7 * V_26 ,
int type )
{
struct V_48 * V_52 ;
struct V_55 * V_127 ;
struct V_94 * V_128 ;
struct V_53 * V_54 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
T_1 V_129 = V_26 ? V_26 -> V_106 : 0 ;
struct V_60 V_61 ;
T_1 V_73 ;
int V_62 , V_63 ;
if ( type == V_89 )
return F_55 ( V_2 , V_26 ) ;
else if ( type == V_130 )
V_73 = V_131 ;
else
V_73 = V_129 ;
V_54 = F_30 ( V_59 , & V_61 , NULL , V_73 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_31 ( V_54 ) )
return - 1 ;
V_62 = F_28 ( V_50 ) ;
V_63 = V_50 -> V_64 ;
V_52 = F_29 ( V_132 + V_62 + V_63 , V_66 ) ;
if ( ! V_52 ) {
F_62 ( V_54 ) ;
return - 1 ;
}
V_52 -> V_68 = V_69 ;
F_33 ( V_52 , & V_54 -> V_73 ) ;
F_36 ( V_52 , V_62 ) ;
F_37 ( V_52 ) ;
V_127 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_127 -> V_75 = 4 ;
V_127 -> V_76 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_127 -> V_77 = 0xc0 ;
V_127 -> V_78 = F_40 ( V_79 ) ;
V_127 -> V_80 = 1 ;
V_127 -> V_81 = V_73 ;
V_127 -> V_82 = V_61 . V_82 ;
V_127 -> V_83 = V_71 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_85 * ) & V_127 [ 1 ] ) [ 0 ] = V_86 ;
( ( V_85 * ) & V_127 [ 1 ] ) [ 1 ] = 4 ;
( ( V_85 * ) & V_127 [ 1 ] ) [ 2 ] = 0 ;
( ( V_85 * ) & V_127 [ 1 ] ) [ 3 ] = 0 ;
V_128 = (struct V_94 * ) F_39 ( V_52 , sizeof( struct V_94 ) ) ;
V_128 -> type = type ;
V_128 -> V_133 = 0 ;
V_128 -> V_91 = 0 ;
V_128 -> V_129 = V_129 ;
V_128 -> V_91 = F_47 ( ( void * ) V_128 , sizeof( struct V_94 ) ) ;
return F_48 ( V_52 ) ;
}
static void F_63 ( unsigned long V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_134 ;
V_2 -> V_21 = 0 ;
F_55 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
}
static void F_64 ( unsigned long V_134 )
{
struct V_1 * V_2 = (struct V_1 * ) V_134 ;
F_60 ( V_2 ) ;
if ( V_2 -> V_135 ) {
V_2 -> V_135 -- ;
F_21 ( V_2 ,
F_1 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
return;
V_2 -> V_135 = V_2 -> V_136 ? : V_137 ;
F_21 ( V_2 , 1 ) ;
}
static void F_66 ( unsigned long V_134 )
{
struct V_7 * V_8 = (struct V_7 * ) V_134 ;
struct V_1 * V_2 = V_8 -> V_10 ;
F_67 ( & V_8 -> V_12 ) ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 -- ;
F_15 ( V_8 , F_1 ( V_2 ) ) ;
}
V_8 -> V_15 = 1 ;
F_68 ( & V_8 -> V_12 ) ;
if ( F_2 ( V_2 ) )
F_61 ( V_2 , V_8 , V_138 ) ;
else if ( F_3 ( V_2 ) )
F_61 ( V_2 , V_8 , V_139 ) ;
else
F_61 ( V_2 , V_8 , V_89 ) ;
F_6 ( V_8 ) ;
}
static int F_69 ( struct V_7 * V_26 , int V_140 , T_1 * V_141 )
{
struct V_27 * V_28 ;
int V_142 , V_45 ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_140 )
break;
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ ) {
if ( V_28 -> V_37 [ V_36 ] ||
V_26 -> V_38 [ V_39 ] !=
V_28 -> V_37 [ V_39 ] )
break;
if ( V_141 [ V_142 ] == V_28 -> V_118 ) {
V_45 ++ ;
break;
}
}
}
V_26 -> V_33 = 0 ;
if ( V_45 == V_140 )
return 0 ;
return 1 ;
}
static int F_70 ( struct V_7 * V_26 , int V_140 , T_1 * V_141 )
{
struct V_27 * V_28 ;
int V_142 , V_45 ;
if ( V_26 -> V_35 == V_39 )
return F_69 ( V_26 , V_140 , V_141 ) ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_140 )
break;
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ )
if ( V_141 [ V_142 ] == V_28 -> V_118 ) {
V_28 -> V_34 = 1 ;
V_45 ++ ;
break;
}
}
if ( ! V_45 ) {
V_26 -> V_33 = 0 ;
return 0 ;
}
V_26 -> V_33 = 1 ;
return 1 ;
}
static bool F_71 ( struct V_1 * V_2 , T_1 V_129 )
{
struct V_7 * V_8 ;
if ( V_129 == V_114 )
return false ;
F_56 () ;
F_57 (in_dev, im) {
if ( V_8 -> V_106 == V_129 ) {
F_10 ( V_8 ) ;
break;
}
}
F_58 () ;
return false ;
}
static bool F_72 ( struct V_1 * V_2 , struct V_48 * V_52 ,
int V_143 )
{
struct V_94 * V_128 = F_44 ( V_52 ) ;
struct V_144 * V_145 = F_73 ( V_52 ) ;
struct V_7 * V_8 ;
T_1 V_129 = V_128 -> V_129 ;
int V_17 ;
int V_146 = 0 ;
if ( V_143 == 8 ) {
if ( V_128 -> V_133 == 0 ) {
V_17 = V_147 ;
V_2 -> V_148 = V_19 +
V_149 ;
V_129 = 0 ;
} else {
V_17 = V_128 -> V_133 * ( V_150 / V_151 ) ;
V_2 -> V_152 = V_19 +
V_153 ;
}
V_2 -> V_135 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
} else if ( V_143 < 12 ) {
return true ;
} else if ( F_2 ( V_2 ) ) {
V_17 = V_147 ;
V_129 = 0 ;
} else if ( F_3 ( V_2 ) ) {
V_17 = F_76 ( V_145 -> V_133 ) * ( V_150 / V_151 ) ;
if ( ! V_17 )
V_17 = 1 ;
} else {
if ( ! F_77 ( V_52 , sizeof( struct V_144 ) ) )
return true ;
V_145 = F_73 ( V_52 ) ;
if ( V_145 -> V_140 ) {
if ( ! F_77 ( V_52 , sizeof( struct V_144 )
+ F_51 ( V_145 -> V_140 ) * sizeof( T_1 ) ) )
return true ;
V_145 = F_73 ( V_52 ) ;
}
V_17 = F_76 ( V_145 -> V_133 ) * ( V_150 / V_151 ) ;
if ( ! V_17 )
V_17 = 1 ;
V_2 -> V_20 = V_17 ;
if ( V_145 -> V_154 )
V_2 -> V_136 = V_145 -> V_154 ;
if ( ! V_129 ) {
if ( V_145 -> V_140 )
return true ;
F_19 ( V_2 ) ;
return false ;
}
V_146 = V_145 -> V_140 != 0 ;
}
F_56 () ;
F_57 (in_dev, im) {
int V_155 ;
if ( V_129 && V_129 != V_8 -> V_106 )
continue;
if ( V_8 -> V_106 == V_114 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( V_8 -> V_14 )
V_8 -> V_33 = V_8 -> V_33 && V_146 ;
else
V_8 -> V_33 = V_146 ;
V_155 = ! V_8 -> V_33 ||
F_70 ( V_8 , F_51 ( V_145 -> V_140 ) , V_145 -> V_141 ) ;
F_14 ( & V_8 -> V_12 ) ;
if ( V_155 )
F_22 ( V_8 , V_17 ) ;
}
F_58 () ;
return false ;
}
int F_78 ( struct V_48 * V_52 )
{
struct V_94 * V_128 ;
struct V_1 * V_2 = F_79 ( V_52 -> V_50 ) ;
int V_143 = V_52 -> V_143 ;
bool V_156 = true ;
if ( ! V_2 )
goto V_157;
if ( ! F_77 ( V_52 , sizeof( struct V_94 ) ) )
goto V_157;
if ( F_80 ( V_52 ) )
goto V_157;
V_128 = F_44 ( V_52 ) ;
switch ( V_128 -> type ) {
case V_158 :
V_156 = F_72 ( V_2 , V_52 , V_143 ) ;
break;
case V_138 :
case V_139 :
if ( F_81 ( F_82 ( V_52 ) ) )
break;
if ( V_52 -> V_159 == V_160 ||
V_52 -> V_159 == V_161 )
V_156 = F_71 ( V_2 , V_128 -> V_129 ) ;
break;
case V_162 :
#ifdef F_83
return F_84 ( V_52 ) ;
#endif
case V_89 :
case V_163 :
case V_164 :
case V_130 :
case V_165 :
case V_166 :
break;
default:
break;
}
V_157:
if ( V_156 )
F_32 ( V_52 ) ;
else
F_85 ( V_52 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 , T_1 V_167 )
{
char V_168 [ V_169 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_87 ( V_167 , V_168 , V_50 , 0 ) == 0 )
F_88 ( V_50 , V_168 ) ;
}
static void F_89 ( struct V_1 * V_2 , T_1 V_167 )
{
char V_168 [ V_169 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_87 ( V_167 , V_168 , V_50 , 0 ) == 0 )
F_90 ( V_50 , V_168 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 ;
V_26 = F_92 ( sizeof( * V_26 ) , V_170 ) ;
if ( ! V_26 )
return;
F_11 ( & V_8 -> V_12 ) ;
V_26 -> V_10 = V_8 -> V_10 ;
F_20 ( V_2 ) ;
V_26 -> V_106 = V_8 -> V_106 ;
V_26 -> V_119 = V_2 -> V_136 ? : V_137 ;
V_26 -> V_35 = V_8 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
struct V_27 * V_28 ;
V_26 -> V_115 = V_8 -> V_115 ;
V_26 -> V_46 = V_8 -> V_46 ;
V_8 -> V_115 = V_8 -> V_46 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_26 -> V_119 ;
}
F_14 ( & V_8 -> V_12 ) ;
F_11 ( & V_2 -> V_124 ) ;
V_26 -> V_126 = V_2 -> V_125 ;
V_2 -> V_125 = V_26 ;
F_14 ( & V_2 -> V_124 ) ;
}
static void F_93 ( struct V_1 * V_2 , T_1 V_106 )
{
struct V_7 * V_26 , * V_121 ;
struct V_27 * V_28 , * V_107 ;
F_11 ( & V_2 -> V_124 ) ;
V_121 = NULL ;
for ( V_26 = V_2 -> V_125 ; V_26 ; V_26 = V_26 -> V_126 ) {
if ( V_26 -> V_106 == V_106 )
break;
V_121 = V_26 ;
}
if ( V_26 ) {
if ( V_121 )
V_121 -> V_126 = V_26 -> V_126 ;
else
V_2 -> V_125 = V_26 -> V_126 ;
}
F_14 ( & V_2 -> V_124 ) ;
if ( V_26 ) {
for ( V_28 = V_26 -> V_115 ; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
F_54 ( V_28 ) ;
}
F_8 ( V_26 -> V_10 ) ;
F_54 ( V_26 ) ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_171 ;
F_11 ( & V_2 -> V_124 ) ;
V_26 = V_2 -> V_125 ;
V_2 -> V_125 = NULL ;
F_14 ( & V_2 -> V_124 ) ;
for (; V_26 ; V_26 = V_171 ) {
V_171 = V_26 -> V_126 ;
F_94 ( V_26 ) ;
F_8 ( V_26 -> V_10 ) ;
F_54 ( V_26 ) ;
}
F_56 () ;
F_57 (in_dev, pmc) {
struct V_27 * V_28 , * V_107 ;
F_11 ( & V_26 -> V_12 ) ;
V_28 = V_26 -> V_115 ;
V_26 -> V_115 = NULL ;
F_14 ( & V_26 -> V_12 ) ;
for (; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
F_54 ( V_28 ) ;
}
}
F_58 () ;
}
static void F_95 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_96
int V_15 ;
#endif
if ( V_8 -> V_172 ) {
V_8 -> V_172 = 0 ;
F_89 ( V_2 , V_8 -> V_106 ) ;
}
#ifdef F_96
if ( V_8 -> V_106 == V_114 )
return;
V_15 = V_8 -> V_15 ;
F_10 ( V_8 ) ;
if ( ! V_2 -> V_173 ) {
if ( F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) ) {
if ( V_15 )
F_61 ( V_2 , V_8 , V_130 ) ;
return;
}
F_91 ( V_2 , V_8 ) ;
F_65 ( V_2 ) ;
}
#endif
}
static void F_97 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
if ( V_8 -> V_172 == 0 ) {
V_8 -> V_172 = 1 ;
F_86 ( V_2 , V_8 -> V_106 ) ;
}
#ifdef F_96
if ( V_8 -> V_106 == V_114 )
return;
if ( V_2 -> V_173 )
return;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
F_11 ( & V_8 -> V_12 ) ;
F_15 ( V_8 , V_174 ) ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
V_8 -> V_119 = V_2 -> V_136 ? : V_137 ;
F_65 ( V_2 ) ;
#endif
}
static T_2 F_98 ( const struct V_7 * V_8 )
{
return F_99 ( ( V_175 T_2 ) V_8 -> V_106 , V_176 ) ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_177 ;
T_2 V_178 ;
V_177 = F_101 ( V_2 -> V_177 ) ;
if ( V_177 ) {
V_178 = F_98 ( V_8 ) ;
V_8 -> V_179 = V_177 [ V_178 ] ;
F_102 ( V_177 [ V_178 ] , V_8 ) ;
return;
}
if ( V_2 -> V_180 < 4 )
return;
V_177 = F_92 ( sizeof( struct V_7 * ) << V_176 ,
V_170 ) ;
if ( ! V_177 )
return;
F_103 (in_dev, im) {
V_178 = F_98 ( V_8 ) ;
V_8 -> V_179 = V_177 [ V_178 ] ;
F_104 ( V_177 [ V_178 ] , V_8 ) ;
}
F_102 ( V_2 -> V_177 , V_177 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_177 = F_101 ( V_2 -> V_177 ) ;
struct V_7 * V_181 ;
if ( ! V_177 )
return;
V_177 += F_98 ( V_8 ) ;
while ( ( V_181 = F_101 ( * V_177 ) ) != V_8 )
V_177 = & V_181 -> V_179 ;
* V_177 = V_8 -> V_179 ;
}
void F_106 ( struct V_1 * V_2 , T_1 V_167 )
{
struct V_7 * V_8 ;
F_107 () ;
F_103 (in_dev, im) {
if ( V_8 -> V_106 == V_167 ) {
V_8 -> V_182 ++ ;
F_108 ( V_2 , & V_167 , V_39 , 0 , NULL , 0 ) ;
goto V_183;
}
}
V_8 = F_92 ( sizeof( * V_8 ) , V_170 ) ;
if ( ! V_8 )
goto V_183;
V_8 -> V_182 = 1 ;
V_8 -> V_10 = V_2 ;
F_20 ( V_2 ) ;
V_8 -> V_106 = V_167 ;
V_8 -> V_35 = V_39 ;
V_8 -> V_38 [ V_39 ] = 1 ;
F_109 ( & V_8 -> V_9 , 1 ) ;
F_110 ( & V_8 -> V_12 ) ;
#ifdef F_96
F_111 ( & V_8 -> V_13 , F_66 , ( unsigned long ) V_8 ) ;
V_8 -> V_16 = V_137 ;
#endif
V_8 -> V_184 = V_2 -> V_185 ;
V_2 -> V_180 ++ ;
F_102 ( V_2 -> V_185 , V_8 ) ;
F_100 ( V_2 , V_8 ) ;
#ifdef F_96
F_93 ( V_2 , V_8 -> V_106 ) ;
#endif
F_97 ( V_8 ) ;
if ( ! V_2 -> V_173 )
F_112 ( V_2 ) ;
V_183:
return;
}
static void F_113 ( struct V_1 * V_2 )
{
#ifdef F_96
struct V_7 * V_8 ;
int type ;
F_107 () ;
F_103 (in_dev, im) {
if ( V_8 -> V_106 == V_114 )
continue;
if ( F_2 ( V_2 ) )
type = V_138 ;
else if ( F_3 ( V_2 ) )
type = V_139 ;
else
type = V_89 ;
F_61 ( V_2 , V_8 , type ) ;
}
#endif
}
void F_114 ( struct V_1 * V_2 , T_1 V_167 )
{
struct V_7 * V_142 ;
struct V_7 T_3 * * V_186 ;
F_107 () ;
for ( V_186 = & V_2 -> V_185 ;
( V_142 = F_101 ( * V_186 ) ) != NULL ;
V_186 = & V_142 -> V_184 ) {
if ( V_142 -> V_106 == V_167 ) {
if ( -- V_142 -> V_182 == 0 ) {
F_105 ( V_2 , V_142 ) ;
* V_186 = V_142 -> V_184 ;
V_2 -> V_180 -- ;
F_95 ( V_142 ) ;
F_94 ( V_142 ) ;
if ( ! V_2 -> V_173 )
F_112 ( V_2 ) ;
F_6 ( V_142 ) ;
return;
}
break;
}
}
}
void F_115 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_107 () ;
F_103 (in_dev, pmc)
F_95 ( V_26 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_107 () ;
F_103 (in_dev, pmc)
F_97 ( V_26 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_107 () ;
F_103 (in_dev, pmc)
F_95 ( V_26 ) ;
#ifdef F_96
V_2 -> V_135 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_74 ( V_2 ) ;
V_2 -> V_21 = 0 ;
if ( F_12 ( & V_2 -> V_22 ) )
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
#endif
F_114 ( V_2 , V_114 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
F_107 () ;
#ifdef F_96
F_111 ( & V_2 -> V_22 , F_63 ,
( unsigned long ) V_2 ) ;
F_111 ( & V_2 -> V_24 , F_64 ,
( unsigned long ) V_2 ) ;
V_2 -> V_136 = V_137 ;
#endif
F_110 ( & V_2 -> V_124 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_107 () ;
#ifdef F_96
V_2 -> V_136 = V_137 ;
#endif
F_106 ( V_2 , V_114 ) ;
F_103 (in_dev, pmc)
F_97 ( V_26 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
struct V_7 * V_142 ;
F_107 () ;
F_117 ( V_2 ) ;
while ( ( V_142 = F_101 ( V_2 -> V_185 ) ) != NULL ) {
V_2 -> V_185 = V_142 -> V_184 ;
V_2 -> V_180 -- ;
F_94 ( V_142 ) ;
F_6 ( V_142 ) ;
}
}
static struct V_1 * F_121 ( struct V_59 * V_59 , struct V_187 * V_188 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_189 = NULL ;
if ( V_188 -> V_190 ) {
V_189 = F_122 ( V_59 , V_188 -> V_190 ) ;
return V_189 ;
}
if ( V_188 -> V_191 . V_192 ) {
V_50 = F_123 ( V_59 , V_188 -> V_191 . V_192 , false ) ;
if ( ! V_50 )
return NULL ;
}
if ( ! V_50 ) {
struct V_53 * V_54 = F_124 ( V_59 ,
V_188 -> V_193 . V_192 ,
0 , 0 , 0 ) ;
if ( ! F_31 ( V_54 ) ) {
V_50 = V_54 -> V_73 . V_50 ;
F_62 ( V_54 ) ;
}
}
if ( V_50 ) {
V_188 -> V_190 = V_50 -> V_72 ;
V_189 = F_125 ( V_50 ) ;
}
return V_189 ;
}
static int F_126 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_194 )
{
struct V_27 * V_28 , * V_108 ;
int V_195 = 0 ;
V_108 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_118 == * V_194 )
break;
V_108 = V_28 ;
}
if ( ! V_28 || V_28 -> V_37 [ V_35 ] == 0 ) {
return - V_196 ;
}
V_28 -> V_37 [ V_35 ] -- ;
if ( V_28 -> V_37 [ V_35 ] == 0 ) {
F_112 ( V_26 -> V_10 ) ;
}
if ( ! V_28 -> V_37 [ V_36 ] && ! V_28 -> V_37 [ V_39 ] ) {
#ifdef F_96
struct V_1 * V_2 = V_26 -> V_10 ;
#endif
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
V_26 -> V_46 = V_28 -> V_47 ;
#ifdef F_96
if ( V_28 -> V_197 &&
! F_2 ( V_2 ) && ! F_3 ( V_2 ) ) {
V_28 -> V_43 = V_2 -> V_136 ? : V_137 ;
V_28 -> V_47 = V_26 -> V_115 ;
V_26 -> V_115 = V_28 ;
V_195 = 1 ;
} else
#endif
F_54 ( V_28 ) ;
}
return V_195 ;
}
static int F_127 ( struct V_1 * V_2 , T_1 * V_198 , int V_35 ,
int V_38 , T_1 * V_194 , int V_199 )
{
struct V_7 * V_26 ;
int V_200 = 0 ;
int V_142 , V_201 ;
if ( ! V_2 )
return - V_202 ;
F_56 () ;
F_57 (in_dev, pmc) {
if ( * V_198 == V_26 -> V_106 )
break;
}
if ( ! V_26 ) {
F_58 () ;
return - V_196 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_58 () ;
#ifdef F_96
F_128 ( V_26 ) ;
#endif
if ( ! V_199 ) {
V_201 = - V_203 ;
if ( ! V_26 -> V_38 [ V_35 ] )
goto V_204;
V_26 -> V_38 [ V_35 ] -- ;
}
V_201 = 0 ;
for ( V_142 = 0 ; V_142 < V_38 ; V_142 ++ ) {
int V_195 = F_126 ( V_26 , V_35 , & V_194 [ V_142 ] ) ;
V_200 |= V_195 > 0 ;
if ( ! V_201 && V_195 < 0 )
V_201 = V_195 ;
}
if ( V_26 -> V_35 == V_39 &&
V_26 -> V_38 [ V_39 ] == 0 &&
V_26 -> V_38 [ V_36 ] ) {
#ifdef F_96
struct V_27 * V_28 ;
#endif
V_26 -> V_35 = V_36 ;
#ifdef F_96
V_26 -> V_119 = V_2 -> V_136 ? : V_137 ;
V_2 -> V_135 = V_26 -> V_119 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_65 ( V_26 -> V_10 ) ;
} else if ( F_129 ( V_26 ) || V_200 ) {
F_65 ( V_26 -> V_10 ) ;
#endif
}
V_204:
F_14 ( & V_26 -> V_12 ) ;
return V_201 ;
}
static int F_130 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_194 )
{
struct V_27 * V_28 , * V_108 ;
V_108 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_118 == * V_194 )
break;
V_108 = V_28 ;
}
if ( ! V_28 ) {
V_28 = F_92 ( sizeof( * V_28 ) , V_66 ) ;
if ( ! V_28 )
return - V_205 ;
V_28 -> V_118 = * V_194 ;
if ( V_108 ) {
V_108 -> V_47 = V_28 ;
} else
V_26 -> V_46 = V_28 ;
}
V_28 -> V_37 [ V_35 ] ++ ;
if ( V_28 -> V_37 [ V_35 ] == 1 ) {
F_112 ( V_26 -> V_10 ) ;
}
return 0 ;
}
static void F_128 ( struct V_7 * V_26 )
{
struct V_27 * V_28 ;
int V_206 = V_26 -> V_38 [ V_39 ] ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
if ( V_26 -> V_38 [ V_39 ] ) {
V_28 -> V_197 = V_206 ==
V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_28 -> V_197 = V_28 -> V_37 [ V_36 ] != 0 ;
}
static int F_129 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_207 ;
int V_206 = V_26 -> V_38 [ V_39 ] ;
int V_154 = V_26 -> V_10 -> V_136 ;
int V_208 , V_195 ;
V_195 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_26 -> V_38 [ V_39 ] ) {
V_208 = V_206 == V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_208 = V_28 -> V_37 [ V_36 ] != 0 ;
if ( V_208 ) {
if ( ! V_28 -> V_197 ) {
struct V_27 * V_209 = NULL ;
for ( V_207 = V_26 -> V_115 ; V_207 ; V_207 = V_207 -> V_47 ) {
if ( V_207 -> V_118 == V_28 -> V_118 )
break;
V_209 = V_207 ;
}
if ( V_207 ) {
if ( V_209 )
V_209 -> V_47 = V_207 -> V_47 ;
else
V_26 -> V_115 = V_207 -> V_47 ;
F_54 ( V_207 ) ;
}
V_28 -> V_43 = V_154 ;
V_195 ++ ;
}
} else if ( V_28 -> V_197 ) {
V_28 -> V_43 = 0 ;
for ( V_207 = V_26 -> V_115 ; V_207 ; V_207 = V_207 -> V_47 )
if ( V_207 -> V_118 == V_28 -> V_118 )
break;
if ( ! V_207 ) {
V_207 = F_131 ( sizeof( * V_207 ) , V_66 ) ;
if ( ! V_207 )
continue;
* V_207 = * V_28 ;
V_207 -> V_47 = V_26 -> V_115 ;
V_26 -> V_115 = V_207 ;
}
V_207 -> V_43 = V_154 ;
V_195 ++ ;
}
}
return V_195 ;
}
static int F_108 ( struct V_1 * V_2 , T_1 * V_198 , int V_35 ,
int V_38 , T_1 * V_194 , int V_199 )
{
struct V_7 * V_26 ;
int V_210 ;
int V_142 , V_201 ;
if ( ! V_2 )
return - V_202 ;
F_56 () ;
F_57 (in_dev, pmc) {
if ( * V_198 == V_26 -> V_106 )
break;
}
if ( ! V_26 ) {
F_58 () ;
return - V_196 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_58 () ;
#ifdef F_96
F_128 ( V_26 ) ;
#endif
V_210 = V_26 -> V_35 == V_39 ;
if ( ! V_199 )
V_26 -> V_38 [ V_35 ] ++ ;
V_201 = 0 ;
for ( V_142 = 0 ; V_142 < V_38 ; V_142 ++ ) {
V_201 = F_130 ( V_26 , V_35 , & V_194 [ V_142 ] ) ;
if ( V_201 )
break;
}
if ( V_201 ) {
int V_211 ;
if ( ! V_199 )
V_26 -> V_38 [ V_35 ] -- ;
for ( V_211 = 0 ; V_211 < V_142 ; V_211 ++ )
( void ) F_126 ( V_26 , V_35 , & V_194 [ V_211 ] ) ;
} else if ( V_210 != ( V_26 -> V_38 [ V_39 ] != 0 ) ) {
#ifdef F_96
struct V_27 * V_28 ;
V_2 = V_26 -> V_10 ;
#endif
if ( V_26 -> V_38 [ V_39 ] )
V_26 -> V_35 = V_39 ;
else if ( V_26 -> V_38 [ V_36 ] )
V_26 -> V_35 = V_36 ;
#ifdef F_96
V_26 -> V_119 = V_2 -> V_136 ? : V_137 ;
V_2 -> V_135 = V_26 -> V_119 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_65 ( V_2 ) ;
} else if ( F_129 ( V_26 ) ) {
F_65 ( V_2 ) ;
#endif
}
F_14 ( & V_26 -> V_12 ) ;
return V_201 ;
}
static void F_94 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_212 ;
for ( V_28 = V_26 -> V_115 ; V_28 ; V_28 = V_212 ) {
V_212 = V_28 -> V_47 ;
F_54 ( V_28 ) ;
}
V_26 -> V_115 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_212 ) {
V_212 = V_28 -> V_47 ;
F_54 ( V_28 ) ;
}
V_26 -> V_46 = NULL ;
V_26 -> V_35 = V_39 ;
V_26 -> V_38 [ V_36 ] = 0 ;
V_26 -> V_38 [ V_39 ] = 1 ;
}
int F_132 ( struct V_213 * V_214 , struct V_187 * V_188 )
{
T_1 V_167 = V_188 -> V_193 . V_192 ;
struct V_215 * V_216 , * V_142 ;
struct V_1 * V_2 ;
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_59 * V_59 = F_134 ( V_214 ) ;
int V_72 ;
int V_219 = 0 ;
int V_201 ;
F_107 () ;
if ( ! F_135 ( V_167 ) )
return - V_203 ;
V_2 = F_121 ( V_59 , V_188 ) ;
if ( ! V_2 ) {
V_201 = - V_202 ;
goto V_220;
}
V_201 = - V_221 ;
V_72 = V_188 -> V_190 ;
F_103 (inet, i) {
if ( V_142 -> V_222 . V_193 . V_192 == V_167 &&
V_142 -> V_222 . V_190 == V_72 )
goto V_220;
V_219 ++ ;
}
V_201 = - V_205 ;
if ( V_219 >= V_223 )
goto V_220;
V_216 = F_136 ( V_214 , sizeof( * V_216 ) , V_170 ) ;
if ( ! V_216 )
goto V_220;
memcpy ( & V_216 -> V_222 , V_188 , sizeof( * V_188 ) ) ;
V_216 -> V_184 = V_218 -> V_185 ;
V_216 -> V_224 = NULL ;
V_216 -> V_35 = V_39 ;
F_102 ( V_218 -> V_185 , V_216 ) ;
F_106 ( V_2 , V_167 ) ;
V_201 = 0 ;
V_220:
return V_201 ;
}
static int F_137 ( struct V_213 * V_214 , struct V_215 * V_216 ,
struct V_1 * V_2 )
{
struct V_225 * V_28 = F_101 ( V_216 -> V_224 ) ;
int V_201 ;
if ( ! V_28 ) {
return F_127 ( V_2 , & V_216 -> V_222 . V_193 . V_192 ,
V_216 -> V_35 , 0 , NULL , 0 ) ;
}
V_201 = F_127 ( V_2 , & V_216 -> V_222 . V_193 . V_192 ,
V_216 -> V_35 , V_28 -> V_226 , V_28 -> V_227 , 0 ) ;
F_104 ( V_216 -> V_224 , NULL ) ;
F_138 ( F_139 ( V_28 -> V_228 ) , & V_214 -> V_229 ) ;
F_9 ( V_28 , V_11 ) ;
return V_201 ;
}
int F_140 ( struct V_213 * V_214 , struct V_187 * V_188 )
{
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_215 * V_216 ;
struct V_215 T_3 * * V_230 ;
struct V_1 * V_2 ;
struct V_59 * V_59 = F_134 ( V_214 ) ;
T_1 V_129 = V_188 -> V_193 . V_192 ;
T_2 V_72 ;
int V_231 = - V_232 ;
F_107 () ;
V_2 = F_121 ( V_59 , V_188 ) ;
if ( ! V_2 ) {
V_231 = - V_202 ;
goto V_183;
}
V_72 = V_188 -> V_190 ;
for ( V_230 = & V_218 -> V_185 ;
( V_216 = F_101 ( * V_230 ) ) != NULL ;
V_230 = & V_216 -> V_184 ) {
if ( V_216 -> V_222 . V_193 . V_192 != V_129 )
continue;
if ( V_72 ) {
if ( V_216 -> V_222 . V_190 != V_72 )
continue;
} else if ( V_188 -> V_191 . V_192 && V_188 -> V_191 . V_192 !=
V_216 -> V_222 . V_191 . V_192 )
continue;
( void ) F_137 ( V_214 , V_216 , V_2 ) ;
* V_230 = V_216 -> V_184 ;
F_114 ( V_2 , V_129 ) ;
F_138 ( sizeof( * V_216 ) , & V_214 -> V_229 ) ;
F_9 ( V_216 , V_11 ) ;
return 0 ;
}
V_183:
return V_231 ;
}
int F_141 ( int V_233 , int V_234 , struct V_213 * V_214 , struct
V_235 * V_236 , int V_72 )
{
int V_201 ;
struct V_187 V_188 ;
T_1 V_167 = V_236 -> V_193 ;
struct V_215 * V_26 ;
struct V_1 * V_2 = NULL ;
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_225 * V_237 ;
struct V_59 * V_59 = F_134 ( V_214 ) ;
int V_238 = 0 ;
int V_142 , V_211 , V_195 ;
if ( ! F_135 ( V_167 ) )
return - V_203 ;
F_107 () ;
V_188 . V_193 . V_192 = V_236 -> V_193 ;
V_188 . V_191 . V_192 = V_236 -> V_239 ;
V_188 . V_190 = V_72 ;
V_2 = F_121 ( V_59 , & V_188 ) ;
if ( ! V_2 ) {
V_201 = - V_202 ;
goto V_220;
}
V_201 = - V_232 ;
F_103 (inet, pmc) {
if ( ( V_26 -> V_222 . V_193 . V_192 ==
V_188 . V_193 . V_192 ) &&
( V_26 -> V_222 . V_190 == V_188 . V_190 ) )
break;
}
if ( ! V_26 ) {
V_201 = - V_203 ;
goto V_220;
}
if ( V_26 -> V_224 ) {
if ( V_26 -> V_35 != V_234 ) {
V_201 = - V_203 ;
goto V_220;
}
} else if ( V_26 -> V_35 != V_234 ) {
F_108 ( V_2 , & V_236 -> V_193 , V_234 , 0 , NULL , 0 ) ;
F_127 ( V_2 , & V_236 -> V_193 , V_26 -> V_35 , 0 ,
NULL , 0 ) ;
V_26 -> V_35 = V_234 ;
}
V_237 = F_101 ( V_26 -> V_224 ) ;
if ( ! V_233 ) {
if ( ! V_237 )
goto V_220;
V_195 = ! 0 ;
for ( V_142 = 0 ; V_142 < V_237 -> V_226 ; V_142 ++ ) {
V_195 = memcmp ( & V_237 -> V_227 [ V_142 ] , & V_236 -> V_240 ,
sizeof( T_1 ) ) ;
if ( V_195 == 0 )
break;
}
if ( V_195 )
goto V_220;
if ( V_237 -> V_226 == 1 && V_234 == V_36 ) {
V_238 = 1 ;
goto V_220;
}
F_127 ( V_2 , & V_236 -> V_193 , V_234 , 1 ,
& V_236 -> V_240 , 1 ) ;
for ( V_211 = V_142 + 1 ; V_211 < V_237 -> V_226 ; V_211 ++ )
V_237 -> V_227 [ V_211 - 1 ] = V_237 -> V_227 [ V_211 ] ;
V_237 -> V_226 -- ;
V_201 = 0 ;
goto V_220;
}
if ( V_237 && V_237 -> V_226 >= V_241 ) {
V_201 = - V_205 ;
goto V_220;
}
if ( ! V_237 || V_237 -> V_226 == V_237 -> V_228 ) {
struct V_225 * V_242 ;
int V_219 = V_243 ;
if ( V_237 )
V_219 += V_237 -> V_228 ;
V_242 = F_136 ( V_214 , F_139 ( V_219 ) , V_170 ) ;
if ( ! V_242 ) {
V_201 = - V_205 ;
goto V_220;
}
V_242 -> V_228 = V_219 ;
V_242 -> V_226 = V_219 - V_243 ;
if ( V_237 ) {
for ( V_142 = 0 ; V_142 < V_237 -> V_226 ; V_142 ++ )
V_242 -> V_227 [ V_142 ] = V_237 -> V_227 [ V_142 ] ;
F_138 ( F_139 ( V_237 -> V_228 ) , & V_214 -> V_229 ) ;
F_9 ( V_237 , V_11 ) ;
}
F_102 ( V_26 -> V_224 , V_242 ) ;
V_237 = V_242 ;
}
V_195 = 1 ;
for ( V_142 = 0 ; V_142 < V_237 -> V_226 ; V_142 ++ ) {
V_195 = memcmp ( & V_237 -> V_227 [ V_142 ] , & V_236 -> V_240 ,
sizeof( T_1 ) ) ;
if ( V_195 == 0 )
break;
}
if ( V_195 == 0 )
goto V_220;
for ( V_211 = V_237 -> V_226 - 1 ; V_211 >= V_142 ; V_211 -- )
V_237 -> V_227 [ V_211 + 1 ] = V_237 -> V_227 [ V_211 ] ;
V_237 -> V_227 [ V_142 ] = V_236 -> V_240 ;
V_237 -> V_226 ++ ;
V_201 = 0 ;
F_108 ( V_2 , & V_236 -> V_193 , V_234 , 1 ,
& V_236 -> V_240 , 1 ) ;
V_220:
if ( V_238 )
V_201 = F_140 ( V_214 , & V_188 ) ;
return V_201 ;
}
int F_142 ( struct V_213 * V_214 , struct V_244 * V_245 , int V_72 )
{
int V_201 = 0 ;
struct V_187 V_188 ;
T_1 V_167 = V_245 -> V_246 ;
struct V_215 * V_26 ;
struct V_1 * V_2 ;
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_225 * V_242 , * V_237 ;
struct V_59 * V_59 = F_134 ( V_214 ) ;
int V_238 = 0 ;
if ( ! F_135 ( V_167 ) )
return - V_203 ;
if ( V_245 -> V_247 != V_36 &&
V_245 -> V_247 != V_39 )
return - V_203 ;
F_107 () ;
V_188 . V_193 . V_192 = V_245 -> V_246 ;
V_188 . V_191 . V_192 = V_245 -> V_248 ;
V_188 . V_190 = V_72 ;
V_2 = F_121 ( V_59 , & V_188 ) ;
if ( ! V_2 ) {
V_201 = - V_202 ;
goto V_220;
}
if ( V_245 -> V_247 == V_36 && V_245 -> V_249 == 0 ) {
V_238 = 1 ;
goto V_220;
}
F_103 (inet, pmc) {
if ( V_26 -> V_222 . V_193 . V_192 == V_245 -> V_246 &&
V_26 -> V_222 . V_190 == V_188 . V_190 )
break;
}
if ( ! V_26 ) {
V_201 = - V_203 ;
goto V_220;
}
if ( V_245 -> V_249 ) {
V_242 = F_136 ( V_214 , F_139 ( V_245 -> V_249 ) ,
V_170 ) ;
if ( ! V_242 ) {
V_201 = - V_205 ;
goto V_220;
}
V_242 -> V_228 = V_242 -> V_226 = V_245 -> V_249 ;
memcpy ( V_242 -> V_227 , V_245 -> V_250 ,
V_245 -> V_249 * sizeof( V_245 -> V_250 [ 0 ] ) ) ;
V_201 = F_108 ( V_2 , & V_245 -> V_246 ,
V_245 -> V_247 , V_242 -> V_226 , V_242 -> V_227 , 0 ) ;
if ( V_201 ) {
F_143 ( V_214 , V_242 , F_139 ( V_242 -> V_228 ) ) ;
goto V_220;
}
} else {
V_242 = NULL ;
( void ) F_108 ( V_2 , & V_245 -> V_246 ,
V_245 -> V_247 , 0 , NULL , 0 ) ;
}
V_237 = F_101 ( V_26 -> V_224 ) ;
if ( V_237 ) {
( void ) F_127 ( V_2 , & V_245 -> V_246 , V_26 -> V_35 ,
V_237 -> V_226 , V_237 -> V_227 , 0 ) ;
F_138 ( F_139 ( V_237 -> V_228 ) , & V_214 -> V_229 ) ;
F_9 ( V_237 , V_11 ) ;
} else
( void ) F_127 ( V_2 , & V_245 -> V_246 , V_26 -> V_35 ,
0 , NULL , 0 ) ;
F_102 ( V_26 -> V_224 , V_242 ) ;
V_26 -> V_35 = V_245 -> V_247 ;
V_201 = 0 ;
V_220:
if ( V_238 )
V_201 = F_140 ( V_214 , & V_188 ) ;
return V_201 ;
}
int F_144 ( struct V_213 * V_214 , struct V_244 * V_245 ,
struct V_244 T_4 * V_251 , int T_4 * V_252 )
{
int V_201 , V_143 , V_219 , V_253 ;
struct V_187 V_188 ;
T_1 V_167 = V_245 -> V_246 ;
struct V_215 * V_26 ;
struct V_1 * V_2 ;
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_225 * V_237 ;
struct V_59 * V_59 = F_134 ( V_214 ) ;
if ( ! F_135 ( V_167 ) )
return - V_203 ;
F_145 () ;
V_188 . V_193 . V_192 = V_245 -> V_246 ;
V_188 . V_191 . V_192 = V_245 -> V_248 ;
V_188 . V_190 = 0 ;
V_2 = F_121 ( V_59 , & V_188 ) ;
if ( ! V_2 ) {
V_201 = - V_202 ;
goto V_220;
}
V_201 = - V_232 ;
F_103 (inet, pmc) {
if ( V_26 -> V_222 . V_193 . V_192 == V_245 -> V_246 &&
V_26 -> V_222 . V_190 == V_188 . V_190 )
break;
}
if ( ! V_26 )
goto V_220;
V_245 -> V_247 = V_26 -> V_35 ;
V_237 = F_101 ( V_26 -> V_224 ) ;
F_146 () ;
if ( ! V_237 ) {
V_143 = 0 ;
V_219 = 0 ;
} else {
V_219 = V_237 -> V_226 ;
}
V_253 = V_219 < V_245 -> V_249 ? V_219 : V_245 -> V_249 ;
V_143 = V_253 * sizeof( V_237 -> V_227 [ 0 ] ) ;
V_245 -> V_249 = V_219 ;
if ( F_147 ( F_148 ( V_253 ) , V_252 ) ||
F_149 ( V_251 , V_245 , F_148 ( 0 ) ) ) {
return - V_254 ;
}
if ( V_143 &&
F_149 ( & V_251 -> V_250 [ 0 ] , V_237 -> V_227 , V_143 ) )
return - V_254 ;
return 0 ;
V_220:
F_146 () ;
return V_201 ;
}
int F_150 ( struct V_213 * V_214 , struct V_255 * V_256 ,
struct V_255 T_4 * V_251 , int T_4 * V_252 )
{
int V_201 , V_142 , V_219 , V_253 ;
struct V_257 * V_258 ;
T_1 V_167 ;
struct V_215 * V_26 ;
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_225 * V_237 ;
V_258 = (struct V_257 * ) & V_256 -> V_259 ;
if ( V_258 -> V_260 != V_261 )
return - V_203 ;
V_167 = V_258 -> V_262 . V_192 ;
if ( ! F_135 ( V_167 ) )
return - V_203 ;
F_145 () ;
V_201 = - V_232 ;
F_103 (inet, pmc) {
if ( V_26 -> V_222 . V_193 . V_192 == V_167 &&
V_26 -> V_222 . V_190 == V_256 -> V_263 )
break;
}
if ( ! V_26 )
goto V_220;
V_256 -> V_264 = V_26 -> V_35 ;
V_237 = F_101 ( V_26 -> V_224 ) ;
F_146 () ;
V_219 = V_237 ? V_237 -> V_226 : 0 ;
V_253 = V_219 < V_256 -> V_265 ? V_219 : V_256 -> V_265 ;
V_256 -> V_265 = V_219 ;
if ( F_147 ( F_151 ( V_253 ) , V_252 ) ||
F_149 ( V_251 , V_256 , F_151 ( 0 ) ) ) {
return - V_254 ;
}
for ( V_142 = 0 ; V_142 < V_253 ; V_142 ++ ) {
struct V_266 V_267 ;
V_258 = (struct V_257 * ) & V_267 ;
memset ( & V_267 , 0 , sizeof( V_267 ) ) ;
V_258 -> V_260 = V_261 ;
V_258 -> V_262 . V_192 = V_237 -> V_227 [ V_142 ] ;
if ( F_149 ( & V_251 -> V_268 [ V_142 ] , & V_267 , sizeof( V_267 ) ) )
return - V_254 ;
}
return 0 ;
V_220:
F_146 () ;
return V_201 ;
}
int F_152 ( struct V_213 * V_214 , T_1 V_269 , T_1 V_270 , int V_271 )
{
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_215 * V_26 ;
struct V_225 * V_237 ;
int V_142 ;
int V_231 ;
V_231 = 1 ;
if ( ! F_135 ( V_269 ) )
goto V_183;
F_56 () ;
F_57 (inet, pmc) {
if ( V_26 -> V_222 . V_193 . V_192 == V_269 &&
V_26 -> V_222 . V_190 == V_271 )
break;
}
V_231 = V_218 -> V_272 ;
if ( ! V_26 )
goto V_273;
V_237 = F_153 ( V_26 -> V_224 ) ;
V_231 = ( V_26 -> V_35 == V_39 ) ;
if ( ! V_237 )
goto V_273;
for ( V_142 = 0 ; V_142 < V_237 -> V_226 ; V_142 ++ ) {
if ( V_237 -> V_227 [ V_142 ] == V_270 )
break;
}
V_231 = 0 ;
if ( V_26 -> V_35 == V_36 && V_142 >= V_237 -> V_226 )
goto V_273;
if ( V_26 -> V_35 == V_39 && V_142 < V_237 -> V_226 )
goto V_273;
V_231 = 1 ;
V_273:
F_58 () ;
V_183:
return V_231 ;
}
void F_154 ( struct V_213 * V_214 )
{
struct V_217 * V_218 = F_133 ( V_214 ) ;
struct V_215 * V_216 ;
struct V_59 * V_59 = F_134 ( V_214 ) ;
if ( ! V_218 -> V_185 )
return;
F_145 () ;
while ( ( V_216 = F_101 ( V_218 -> V_185 ) ) != NULL ) {
struct V_1 * V_2 ;
V_218 -> V_185 = V_216 -> V_184 ;
V_2 = F_122 ( V_59 , V_216 -> V_222 . V_190 ) ;
( void ) F_137 ( V_214 , V_216 , V_2 ) ;
if ( V_2 )
F_114 ( V_2 , V_216 -> V_222 . V_193 . V_192 ) ;
F_138 ( sizeof( * V_216 ) , & V_214 -> V_229 ) ;
F_9 ( V_216 , V_11 ) ;
}
F_146 () ;
}
int F_155 ( struct V_1 * V_2 , T_1 V_274 , T_1 V_275 , T_5 V_276 )
{
struct V_7 * V_8 ;
struct V_7 T_3 * * V_177 ;
struct V_27 * V_28 ;
int V_195 = 0 ;
V_177 = F_153 ( V_2 -> V_177 ) ;
if ( V_177 ) {
T_2 V_178 = F_99 ( ( V_175 T_2 ) V_274 , V_176 ) ;
for ( V_8 = F_153 ( V_177 [ V_178 ] ) ;
V_8 != NULL ;
V_8 = F_153 ( V_8 -> V_179 ) ) {
if ( V_8 -> V_106 == V_274 )
break;
}
} else {
F_57 (in_dev, im) {
if ( V_8 -> V_106 == V_274 )
break;
}
}
if ( V_8 && V_276 == V_71 ) {
V_195 = 1 ;
} else if ( V_8 ) {
if ( V_275 ) {
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_118 == V_275 )
break;
}
if ( V_28 )
V_195 = V_28 -> V_37 [ V_36 ] ||
V_28 -> V_37 [ V_39 ] !=
V_8 -> V_38 [ V_39 ] ;
else
V_195 = V_8 -> V_38 [ V_39 ] != 0 ;
} else
V_195 = 1 ;
}
return V_195 ;
}
static inline struct V_7 * F_156 ( struct V_277 * V_278 )
{
struct V_59 * V_59 = F_157 ( V_278 ) ;
struct V_7 * V_8 = NULL ;
struct V_279 * V_280 = F_158 ( V_278 ) ;
V_280 -> V_2 = NULL ;
F_159 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_79 ( V_280 -> V_50 ) ;
if ( ! V_2 )
continue;
V_8 = F_153 ( V_2 -> V_185 ) ;
if ( V_8 ) {
V_280 -> V_2 = V_2 ;
break;
}
}
return V_8 ;
}
static struct V_7 * F_160 ( struct V_277 * V_278 , struct V_7 * V_8 )
{
struct V_279 * V_280 = F_158 ( V_278 ) ;
V_8 = F_153 ( V_8 -> V_184 ) ;
while ( ! V_8 ) {
V_280 -> V_50 = F_161 ( V_280 -> V_50 ) ;
if ( ! V_280 -> V_50 ) {
V_280 -> V_2 = NULL ;
break;
}
V_280 -> V_2 = F_79 ( V_280 -> V_50 ) ;
if ( ! V_280 -> V_2 )
continue;
V_8 = F_153 ( V_280 -> V_2 -> V_185 ) ;
}
return V_8 ;
}
static struct V_7 * F_162 ( struct V_277 * V_278 , T_6 V_281 )
{
struct V_7 * V_8 = F_156 ( V_278 ) ;
if ( V_8 )
while ( V_281 && ( V_8 = F_160 ( V_278 , V_8 ) ) != NULL )
-- V_281 ;
return V_281 ? NULL : V_8 ;
}
static void * F_163 ( struct V_277 * V_278 , T_6 * V_281 )
__acquires( V_11 )
{
F_56 () ;
return * V_281 ? F_162 ( V_278 , * V_281 - 1 ) : V_282 ;
}
static void * F_164 ( struct V_277 * V_278 , void * V_283 , T_6 * V_281 )
{
struct V_7 * V_8 ;
if ( V_283 == V_282 )
V_8 = F_156 ( V_278 ) ;
else
V_8 = F_160 ( V_278 , V_283 ) ;
++ * V_281 ;
return V_8 ;
}
static void F_165 ( struct V_277 * V_278 , void * V_283 )
__releases( V_11 )
{
struct V_279 * V_280 = F_158 ( V_278 ) ;
V_280 -> V_2 = NULL ;
V_280 -> V_50 = NULL ;
F_58 () ;
}
static int F_166 ( struct V_277 * V_278 , void * V_283 )
{
if ( V_283 == V_282 )
F_167 ( V_278 ,
L_1 ) ;
else {
struct V_7 * V_8 = (struct V_7 * ) V_283 ;
struct V_279 * V_280 = F_158 ( V_278 ) ;
char * V_284 ;
long V_199 ;
#ifdef F_96
V_284 = F_2 ( V_280 -> V_2 ) ? L_2 :
F_3 ( V_280 -> V_2 ) ? L_3 :
L_4 ;
#else
V_284 = L_5 ;
#endif
if ( F_168 ( V_280 -> V_2 -> V_185 ) == V_8 ) {
F_169 ( V_278 , L_6 ,
V_280 -> V_50 -> V_72 , V_280 -> V_50 -> V_285 , V_280 -> V_2 -> V_180 , V_284 ) ;
}
V_199 = V_8 -> V_13 . V_25 - V_19 ;
F_169 ( V_278 ,
L_7 ,
V_8 -> V_106 , V_8 -> V_182 ,
V_8 -> V_14 ,
V_8 -> V_14 ? F_170 ( V_199 ) : 0 ,
V_8 -> V_15 ) ;
}
return 0 ;
}
static int F_171 ( struct V_286 * V_286 , struct V_287 * V_287 )
{
return F_172 ( V_286 , V_287 , & V_288 ,
sizeof( struct V_279 ) ) ;
}
static inline struct V_27 * F_173 ( struct V_277 * V_278 )
{
struct V_59 * V_59 = F_157 ( V_278 ) ;
struct V_27 * V_28 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_289 * V_280 = F_174 ( V_278 ) ;
V_280 -> V_189 = NULL ;
V_280 -> V_8 = NULL ;
F_159 (net, state->dev) {
struct V_1 * V_189 ;
V_189 = F_79 ( V_280 -> V_50 ) ;
if ( F_175 ( ! V_189 ) )
continue;
V_8 = F_153 ( V_189 -> V_185 ) ;
if ( F_176 ( V_8 ) ) {
F_11 ( & V_8 -> V_12 ) ;
V_28 = V_8 -> V_46 ;
if ( F_176 ( V_28 ) ) {
V_280 -> V_8 = V_8 ;
V_280 -> V_189 = V_189 ;
break;
}
F_14 ( & V_8 -> V_12 ) ;
}
}
return V_28 ;
}
static struct V_27 * F_177 ( struct V_277 * V_278 , struct V_27 * V_28 )
{
struct V_289 * V_280 = F_174 ( V_278 ) ;
V_28 = V_28 -> V_47 ;
while ( ! V_28 ) {
F_14 ( & V_280 -> V_8 -> V_12 ) ;
V_280 -> V_8 = V_280 -> V_8 -> V_126 ;
while ( ! V_280 -> V_8 ) {
V_280 -> V_50 = F_161 ( V_280 -> V_50 ) ;
if ( ! V_280 -> V_50 ) {
V_280 -> V_189 = NULL ;
goto V_183;
}
V_280 -> V_189 = F_79 ( V_280 -> V_50 ) ;
if ( ! V_280 -> V_189 )
continue;
V_280 -> V_8 = F_153 ( V_280 -> V_189 -> V_185 ) ;
}
if ( ! V_280 -> V_8 )
break;
F_11 ( & V_280 -> V_8 -> V_12 ) ;
V_28 = V_280 -> V_8 -> V_46 ;
}
V_183:
return V_28 ;
}
static struct V_27 * F_178 ( struct V_277 * V_278 , T_6 V_281 )
{
struct V_27 * V_28 = F_173 ( V_278 ) ;
if ( V_28 )
while ( V_281 && ( V_28 = F_177 ( V_278 , V_28 ) ) != NULL )
-- V_281 ;
return V_281 ? NULL : V_28 ;
}
static void * F_179 ( struct V_277 * V_278 , T_6 * V_281 )
__acquires( V_11 )
{
F_56 () ;
return * V_281 ? F_178 ( V_278 , * V_281 - 1 ) : V_282 ;
}
static void * F_180 ( struct V_277 * V_278 , void * V_283 , T_6 * V_281 )
{
struct V_27 * V_28 ;
if ( V_283 == V_282 )
V_28 = F_173 ( V_278 ) ;
else
V_28 = F_177 ( V_278 , V_283 ) ;
++ * V_281 ;
return V_28 ;
}
static void F_181 ( struct V_277 * V_278 , void * V_283 )
__releases( V_11 )
{
struct V_289 * V_280 = F_174 ( V_278 ) ;
if ( F_176 ( V_280 -> V_8 ) ) {
F_14 ( & V_280 -> V_8 -> V_12 ) ;
V_280 -> V_8 = NULL ;
}
V_280 -> V_189 = NULL ;
V_280 -> V_50 = NULL ;
F_58 () ;
}
static int F_182 ( struct V_277 * V_278 , void * V_283 )
{
struct V_27 * V_28 = (struct V_27 * ) V_283 ;
struct V_289 * V_280 = F_174 ( V_278 ) ;
if ( V_283 == V_282 ) {
F_167 ( V_278 , L_8 ) ;
} else {
F_169 ( V_278 ,
L_9
L_10 ,
V_280 -> V_50 -> V_72 , V_280 -> V_50 -> V_285 ,
F_183 ( V_280 -> V_8 -> V_106 ) ,
F_183 ( V_28 -> V_118 ) ,
V_28 -> V_37 [ V_36 ] ,
V_28 -> V_37 [ V_39 ] ) ;
}
return 0 ;
}
static int F_184 ( struct V_286 * V_286 , struct V_287 * V_287 )
{
return F_172 ( V_286 , V_287 , & V_290 ,
sizeof( struct V_289 ) ) ;
}
static int T_7 F_185 ( struct V_59 * V_59 )
{
struct V_291 * V_292 ;
int V_201 ;
V_292 = F_186 ( L_11 , V_293 , V_59 -> V_294 , & V_295 ) ;
if ( ! V_292 )
goto V_296;
V_292 = F_186 ( L_12 , V_293 , V_59 -> V_294 ,
& V_297 ) ;
if ( ! V_292 )
goto V_298;
V_201 = F_187 ( & V_59 -> V_299 . V_300 , V_261 ,
V_301 , 0 , V_59 ) ;
if ( V_201 < 0 ) {
F_188 ( L_13 ,
V_201 ) ;
goto V_302;
}
return 0 ;
V_302:
F_189 ( L_12 , V_59 -> V_294 ) ;
V_298:
F_189 ( L_11 , V_59 -> V_294 ) ;
V_296:
return - V_303 ;
}
static void T_8 F_190 ( struct V_59 * V_59 )
{
F_189 ( L_12 , V_59 -> V_294 ) ;
F_189 ( L_11 , V_59 -> V_294 ) ;
F_191 ( V_59 -> V_299 . V_300 ) ;
}
static int F_192 ( struct V_304 * V_305 ,
unsigned long V_306 , void * V_307 )
{
struct V_49 * V_50 = F_193 ( V_307 ) ;
struct V_1 * V_2 ;
switch ( V_306 ) {
case V_308 :
V_2 = F_125 ( V_50 ) ;
if ( V_2 )
F_113 ( V_2 ) ;
break;
default:
break;
}
return V_309 ;
}
int T_9 F_194 ( void )
{
#if F_195 ( V_310 )
int V_201 ;
V_201 = F_196 ( & V_311 ) ;
if ( V_201 )
return V_201 ;
V_201 = F_197 ( & V_312 ) ;
if ( V_201 )
goto V_313;
return 0 ;
V_313:
F_198 ( & V_311 ) ;
return V_201 ;
#else
return F_197 ( & V_312 ) ;
#endif
}
