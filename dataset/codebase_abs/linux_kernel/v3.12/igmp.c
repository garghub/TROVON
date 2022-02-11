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
static struct V_48 * F_26 ( struct V_49 * V_50 , int V_51 )
{
struct V_48 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
struct V_60 V_61 ;
int V_62 = F_28 ( V_50 ) ;
int V_63 = V_50 -> V_64 ;
while ( 1 ) {
V_52 = F_29 ( V_51 + V_62 + V_63 ,
V_65 | V_66 ) ;
if ( V_52 )
break;
V_51 >>= 1 ;
if ( V_51 < 256 )
return NULL ;
}
V_52 -> V_67 = V_68 ;
F_30 ( V_52 ) = V_51 ;
V_54 = F_31 ( V_59 , & V_61 , NULL , V_69 , 0 ,
0 , 0 ,
V_70 , 0 , V_50 -> V_71 ) ;
if ( F_32 ( V_54 ) ) {
F_33 ( V_52 ) ;
return NULL ;
}
F_34 ( V_52 , & V_54 -> V_72 ) ;
V_52 -> V_50 = V_50 ;
F_35 ( V_52 , V_62 ) ;
F_36 ( V_52 ) ;
V_56 = F_37 ( V_52 ) ;
F_38 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_56 -> V_73 = 4 ;
V_56 -> V_74 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_56 -> V_75 = 0xc0 ;
V_56 -> V_76 = F_39 ( V_77 ) ;
V_56 -> V_78 = 1 ;
V_56 -> V_79 = V_61 . V_79 ;
V_56 -> V_80 = V_61 . V_80 ;
V_56 -> V_81 = V_70 ;
V_56 -> V_82 = 0 ;
F_40 ( V_52 , & V_54 -> V_72 , NULL ) ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 0 ] = V_84 ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 1 ] = 4 ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 2 ] = 0 ;
( ( V_83 * ) & V_56 [ 1 ] ) [ 3 ] = 0 ;
V_52 -> V_85 = V_52 -> V_86 + sizeof( struct V_55 ) + 4 ;
F_38 ( V_52 , sizeof( * V_58 ) ) ;
V_58 = F_41 ( V_52 ) ;
V_58 -> type = V_87 ;
V_58 -> V_88 = 0 ;
V_58 -> V_89 = 0 ;
V_58 -> V_90 = 0 ;
V_58 -> V_91 = 0 ;
return V_52 ;
}
static int F_42 ( struct V_48 * V_52 )
{
struct V_92 * V_58 = F_43 ( V_52 ) ;
const int V_93 = F_44 ( V_52 ) - F_45 ( V_52 ) ;
V_58 -> V_89 = F_46 ( F_43 ( V_52 ) , V_93 ) ;
return F_47 ( V_52 ) ;
}
static int F_48 ( struct V_7 * V_26 , int type , int V_94 , int V_95 )
{
return sizeof( struct V_96 ) + 4 * F_25 ( V_26 , type , V_94 , V_95 ) ;
}
static struct V_48 * F_49 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , struct V_96 * * V_97 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_98 ;
struct V_96 * V_99 ;
if ( ! V_52 )
V_52 = F_26 ( V_50 , V_50 -> V_100 ) ;
if ( ! V_52 )
return NULL ;
V_99 = (struct V_96 * ) F_38 ( V_52 , sizeof( struct V_96 ) ) ;
V_99 -> V_101 = type ;
V_99 -> V_102 = 0 ;
V_99 -> V_103 = 0 ;
V_99 -> V_104 = V_26 -> V_105 ;
V_98 = F_41 ( V_52 ) ;
V_98 -> V_91 = F_39 ( F_50 ( V_98 -> V_91 ) + 1 ) ;
* V_97 = V_99 ;
return V_52 ;
}
static struct V_48 * F_51 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , int V_29 , int V_30 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_98 ;
struct V_96 * V_99 = NULL ;
struct V_27 * V_28 , * V_106 , * V_107 , * * V_108 ;
int V_45 , V_109 , V_110 , V_111 , V_112 ;
if ( V_26 -> V_105 == V_113 )
return V_52 ;
V_111 = type == V_31 ||
type == V_32 ;
V_112 = type == V_32 ||
type == V_41 ;
V_109 = V_45 = 0 ;
V_108 = V_30 ? & V_26 -> V_114 : & V_26 -> V_46 ;
if ( ! * V_108 )
goto V_115;
V_98 = V_52 ? F_41 ( V_52 ) : NULL ;
if ( V_112 ) {
if ( V_98 && V_98 -> V_91 &&
F_52 ( V_52 ) < F_48 ( V_26 , type , V_29 , V_30 ) ) {
if ( V_52 )
F_42 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_100 ) ;
}
}
V_110 = 1 ;
V_107 = NULL ;
for ( V_28 = * V_108 ; V_28 ; V_28 = V_106 ) {
T_1 * V_116 ;
V_106 = V_28 -> V_47 ;
if ( ! F_24 ( V_26 , V_28 , type , V_29 , V_30 ) ) {
V_107 = V_28 ;
continue;
}
if ( V_111 )
V_28 -> V_34 = 0 ;
if ( F_52 ( V_52 ) < sizeof( T_1 ) +
V_110 * sizeof( struct V_96 ) ) {
if ( V_112 && ! V_110 )
break;
if ( V_99 )
V_99 -> V_103 = F_39 ( V_45 ) ;
if ( V_52 )
F_42 ( V_52 ) ;
V_52 = F_26 ( V_50 , V_50 -> V_100 ) ;
V_110 = 1 ;
V_45 = 0 ;
}
if ( V_110 ) {
V_52 = F_49 ( V_52 , V_26 , type , & V_99 ) ;
V_110 = 0 ;
}
if ( ! V_52 )
return NULL ;
V_116 = ( T_1 * ) F_38 ( V_52 , sizeof( T_1 ) ) ;
* V_116 = V_28 -> V_117 ;
V_45 ++ ; V_109 ++ ;
if ( ( type == V_42 ||
type == V_44 ) && V_28 -> V_43 ) {
V_28 -> V_43 -- ;
if ( ( V_30 || V_29 ) && V_28 -> V_43 == 0 ) {
if ( V_107 )
V_107 -> V_47 = V_28 -> V_47 ;
else
* V_108 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
continue;
}
}
V_107 = V_28 ;
}
V_115:
if ( ! V_109 ) {
if ( type == V_42 ||
type == V_44 )
return V_52 ;
if ( V_26 -> V_118 || V_111 ) {
if ( V_52 && F_52 ( V_52 ) < sizeof( struct V_96 ) ) {
F_42 ( V_52 ) ;
V_52 = NULL ;
}
V_52 = F_49 ( V_52 , V_26 , type , & V_99 ) ;
}
}
if ( V_99 )
V_99 -> V_103 = F_39 ( V_45 ) ;
if ( V_111 )
V_26 -> V_33 = 0 ;
return V_52 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_7 * V_26 )
{
struct V_48 * V_52 = NULL ;
int type ;
if ( ! V_26 ) {
F_55 () ;
F_56 (in_dev, pmc) {
if ( V_26 -> V_105 == V_113 )
continue;
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
F_57 () ;
} else {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
if ( ! V_52 )
return 0 ;
return F_42 ( V_52 ) ;
}
static void F_58 ( struct V_27 * * V_119 )
{
struct V_27 * V_107 , * V_106 , * V_28 ;
V_107 = NULL ;
for ( V_28 = * V_119 ; V_28 ; V_28 = V_106 ) {
V_106 = V_28 -> V_47 ;
if ( V_28 -> V_43 == 0 ) {
if ( V_107 )
V_107 -> V_47 = V_28 -> V_47 ;
else
* V_119 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
} else
V_107 = V_28 ;
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_120 , * V_121 ;
struct V_48 * V_52 = NULL ;
int type , V_122 ;
F_55 () ;
F_11 ( & V_2 -> V_123 ) ;
V_120 = NULL ;
for ( V_26 = V_2 -> V_124 ; V_26 ; V_26 = V_121 ) {
V_121 = V_26 -> V_125 ;
if ( V_26 -> V_35 == V_36 ) {
type = V_44 ;
V_122 = V_44 ;
V_52 = F_51 ( V_52 , V_26 , type , 1 , 0 ) ;
V_52 = F_51 ( V_52 , V_26 , V_122 , 1 , 1 ) ;
}
if ( V_26 -> V_118 ) {
if ( V_26 -> V_35 == V_39 ) {
type = V_40 ;
V_52 = F_51 ( V_52 , V_26 , type , 1 , 0 ) ;
}
V_26 -> V_118 -- ;
if ( V_26 -> V_118 == 0 ) {
F_58 ( & V_26 -> V_114 ) ;
F_58 ( & V_26 -> V_46 ) ;
}
}
if ( V_26 -> V_118 == 0 && ! V_26 -> V_114 && ! V_26 -> V_46 ) {
if ( V_120 )
V_120 -> V_125 = V_121 ;
else
V_2 -> V_124 = V_121 ;
F_8 ( V_26 -> V_10 ) ;
F_53 ( V_26 ) ;
} else
V_120 = V_26 ;
}
F_14 ( & V_2 -> V_123 ) ;
F_56 (in_dev, pmc) {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] ) {
type = V_44 ;
V_122 = V_42 ;
} else {
type = V_42 ;
V_122 = V_44 ;
}
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
V_52 = F_51 ( V_52 , V_26 , V_122 , 0 , 1 ) ;
if ( V_26 -> V_118 ) {
if ( V_26 -> V_35 == V_39 )
type = V_41 ;
else
type = V_40 ;
V_52 = F_51 ( V_52 , V_26 , type , 0 , 0 ) ;
V_26 -> V_118 -- ;
}
F_14 ( & V_26 -> V_12 ) ;
}
F_57 () ;
if ( ! V_52 )
return;
( void ) F_42 ( V_52 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_7 * V_26 ,
int type )
{
struct V_48 * V_52 ;
struct V_55 * V_126 ;
struct V_92 * V_127 ;
struct V_53 * V_54 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_59 * V_59 = F_27 ( V_50 ) ;
T_1 V_128 = V_26 ? V_26 -> V_105 : 0 ;
struct V_60 V_61 ;
T_1 V_72 ;
int V_62 , V_63 ;
if ( type == V_87 )
return F_54 ( V_2 , V_26 ) ;
else if ( type == V_129 )
V_72 = V_130 ;
else
V_72 = V_128 ;
V_54 = F_31 ( V_59 , & V_61 , NULL , V_72 , 0 ,
0 , 0 ,
V_70 , 0 , V_50 -> V_71 ) ;
if ( F_32 ( V_54 ) )
return - 1 ;
V_62 = F_28 ( V_50 ) ;
V_63 = V_50 -> V_64 ;
V_52 = F_29 ( V_131 + V_62 + V_63 , V_65 ) ;
if ( V_52 == NULL ) {
F_61 ( V_54 ) ;
return - 1 ;
}
V_52 -> V_67 = V_68 ;
F_34 ( V_52 , & V_54 -> V_72 ) ;
F_35 ( V_52 , V_62 ) ;
F_36 ( V_52 ) ;
V_126 = F_37 ( V_52 ) ;
F_38 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_126 -> V_73 = 4 ;
V_126 -> V_74 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_126 -> V_75 = 0xc0 ;
V_126 -> V_76 = F_39 ( V_77 ) ;
V_126 -> V_78 = 1 ;
V_126 -> V_79 = V_72 ;
V_126 -> V_80 = V_61 . V_80 ;
V_126 -> V_81 = V_70 ;
F_40 ( V_52 , & V_54 -> V_72 , NULL ) ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 0 ] = V_84 ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 1 ] = 4 ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 2 ] = 0 ;
( ( V_83 * ) & V_126 [ 1 ] ) [ 3 ] = 0 ;
V_127 = (struct V_92 * ) F_38 ( V_52 , sizeof( struct V_92 ) ) ;
V_127 -> type = type ;
V_127 -> V_132 = 0 ;
V_127 -> V_89 = 0 ;
V_127 -> V_128 = V_128 ;
V_127 -> V_89 = F_46 ( ( void * ) V_127 , sizeof( struct V_92 ) ) ;
return F_47 ( V_52 ) ;
}
static void F_62 ( unsigned long V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_133 ;
V_2 -> V_21 = 0 ;
F_54 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
}
static void F_63 ( unsigned long V_133 )
{
struct V_1 * V_2 = (struct V_1 * ) V_133 ;
F_59 ( V_2 ) ;
if ( V_2 -> V_134 ) {
V_2 -> V_134 -- ;
F_21 ( V_2 ,
F_1 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
return;
V_2 -> V_134 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
F_21 ( V_2 , 1 ) ;
}
static void F_65 ( unsigned long V_133 )
{
struct V_7 * V_8 = (struct V_7 * ) V_133 ;
struct V_1 * V_2 = V_8 -> V_10 ;
F_66 ( & V_8 -> V_12 ) ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 -- ;
F_15 ( V_8 , F_1 ( V_2 ) ) ;
}
V_8 -> V_15 = 1 ;
F_67 ( & V_8 -> V_12 ) ;
if ( F_2 ( V_2 ) )
F_60 ( V_2 , V_8 , V_137 ) ;
else if ( F_3 ( V_2 ) )
F_60 ( V_2 , V_8 , V_138 ) ;
else
F_60 ( V_2 , V_8 , V_87 ) ;
F_6 ( V_8 ) ;
}
static int F_68 ( struct V_7 * V_26 , int V_139 , T_1 * V_140 )
{
struct V_27 * V_28 ;
int V_141 , V_45 ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_139 )
break;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ ) {
if ( V_28 -> V_37 [ V_36 ] ||
V_26 -> V_38 [ V_39 ] !=
V_28 -> V_37 [ V_39 ] )
break;
if ( V_140 [ V_141 ] == V_28 -> V_117 ) {
V_45 ++ ;
break;
}
}
}
V_26 -> V_33 = 0 ;
if ( V_45 == V_139 )
return 0 ;
return 1 ;
}
static int F_69 ( struct V_7 * V_26 , int V_139 , T_1 * V_140 )
{
struct V_27 * V_28 ;
int V_141 , V_45 ;
if ( V_26 -> V_35 == V_39 )
return F_68 ( V_26 , V_139 , V_140 ) ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_139 )
break;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ )
if ( V_140 [ V_141 ] == V_28 -> V_117 ) {
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
static bool F_70 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_7 * V_8 ;
if ( V_128 == V_113 )
return false ;
F_55 () ;
F_56 (in_dev, im) {
if ( V_8 -> V_105 == V_128 ) {
F_10 ( V_8 ) ;
break;
}
}
F_57 () ;
return false ;
}
static bool F_71 ( struct V_1 * V_2 , struct V_48 * V_52 ,
int V_142 )
{
struct V_92 * V_127 = F_43 ( V_52 ) ;
struct V_143 * V_144 = F_72 ( V_52 ) ;
struct V_7 * V_8 ;
T_1 V_128 = V_127 -> V_128 ;
int V_17 ;
int V_145 = 0 ;
if ( V_142 == 8 ) {
if ( V_127 -> V_132 == 0 ) {
V_17 = V_146 ;
V_2 -> V_147 = V_19 +
V_148 ;
V_128 = 0 ;
} else {
V_17 = V_127 -> V_132 * ( V_149 / V_150 ) ;
V_2 -> V_151 = V_19 +
V_152 ;
}
V_2 -> V_134 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
} else if ( V_142 < 12 ) {
return true ;
} else if ( F_2 ( V_2 ) ) {
V_17 = V_146 ;
V_128 = 0 ;
} else if ( F_3 ( V_2 ) ) {
V_17 = F_75 ( V_144 -> V_132 ) * ( V_149 / V_150 ) ;
if ( ! V_17 )
V_17 = 1 ;
} else {
if ( ! F_76 ( V_52 , sizeof( struct V_143 ) ) )
return true ;
V_144 = F_72 ( V_52 ) ;
if ( V_144 -> V_139 ) {
if ( ! F_76 ( V_52 , sizeof( struct V_143 )
+ F_50 ( V_144 -> V_139 ) * sizeof( T_1 ) ) )
return true ;
V_144 = F_72 ( V_52 ) ;
}
V_17 = F_75 ( V_144 -> V_132 ) * ( V_149 / V_150 ) ;
if ( ! V_17 )
V_17 = 1 ;
V_2 -> V_20 = V_17 ;
if ( V_144 -> V_153 )
V_2 -> V_135 = V_144 -> V_153 ;
if ( ! V_128 ) {
if ( V_144 -> V_139 )
return false ;
F_19 ( V_2 ) ;
return false ;
}
V_145 = V_144 -> V_139 != 0 ;
}
F_55 () ;
F_56 (in_dev, im) {
int V_154 ;
if ( V_128 && V_128 != V_8 -> V_105 )
continue;
if ( V_8 -> V_105 == V_113 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( V_8 -> V_14 )
V_8 -> V_33 = V_8 -> V_33 && V_145 ;
else
V_8 -> V_33 = V_145 ;
V_154 = ! V_8 -> V_33 ||
F_69 ( V_8 , F_50 ( V_144 -> V_139 ) , V_144 -> V_140 ) ;
F_14 ( & V_8 -> V_12 ) ;
if ( V_154 )
F_22 ( V_8 , V_17 ) ;
}
F_57 () ;
return false ;
}
int F_77 ( struct V_48 * V_52 )
{
struct V_92 * V_127 ;
struct V_1 * V_2 = F_78 ( V_52 -> V_50 ) ;
int V_142 = V_52 -> V_142 ;
bool V_155 = true ;
if ( V_2 == NULL )
goto V_156;
if ( ! F_76 ( V_52 , sizeof( struct V_92 ) ) )
goto V_156;
switch ( V_52 -> V_157 ) {
case V_158 :
if ( ! F_79 ( V_52 -> V_89 ) )
break;
case V_159 :
V_52 -> V_89 = 0 ;
if ( F_80 ( V_52 ) )
goto V_156;
}
V_127 = F_43 ( V_52 ) ;
switch ( V_127 -> type ) {
case V_160 :
V_155 = F_71 ( V_2 , V_52 , V_142 ) ;
break;
case V_137 :
case V_138 :
if ( F_81 ( F_82 ( V_52 ) ) )
break;
if ( V_52 -> V_161 == V_162 ||
V_52 -> V_161 == V_163 )
V_155 = F_70 ( V_2 , V_127 -> V_128 ) ;
break;
case V_164 :
#ifdef F_83
return F_84 ( V_52 ) ;
#endif
case V_87 :
case V_165 :
case V_166 :
case V_129 :
case V_167 :
case V_168 :
break;
default:
break;
}
V_156:
if ( V_155 )
F_33 ( V_52 ) ;
else
F_85 ( V_52 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 , T_1 V_169 )
{
char V_170 [ V_171 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_87 ( V_169 , V_170 , V_50 , 0 ) == 0 )
F_88 ( V_50 , V_170 ) ;
}
static void F_89 ( struct V_1 * V_2 , T_1 V_169 )
{
char V_170 [ V_171 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_87 ( V_169 , V_170 , V_50 , 0 ) == 0 )
F_90 ( V_50 , V_170 ) ;
}
static void F_91 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 ;
V_26 = F_92 ( sizeof( * V_26 ) , V_172 ) ;
if ( ! V_26 )
return;
F_11 ( & V_8 -> V_12 ) ;
V_26 -> V_10 = V_8 -> V_10 ;
F_20 ( V_2 ) ;
V_26 -> V_105 = V_8 -> V_105 ;
V_26 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_26 -> V_35 = V_8 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
struct V_27 * V_28 ;
V_26 -> V_114 = V_8 -> V_114 ;
V_26 -> V_46 = V_8 -> V_46 ;
V_8 -> V_114 = V_8 -> V_46 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_26 -> V_118 ;
}
F_14 ( & V_8 -> V_12 ) ;
F_11 ( & V_2 -> V_123 ) ;
V_26 -> V_125 = V_2 -> V_124 ;
V_2 -> V_124 = V_26 ;
F_14 ( & V_2 -> V_123 ) ;
}
static void F_93 ( struct V_1 * V_2 , T_1 V_105 )
{
struct V_7 * V_26 , * V_120 ;
struct V_27 * V_28 , * V_106 ;
F_11 ( & V_2 -> V_123 ) ;
V_120 = NULL ;
for ( V_26 = V_2 -> V_124 ; V_26 ; V_26 = V_26 -> V_125 ) {
if ( V_26 -> V_105 == V_105 )
break;
V_120 = V_26 ;
}
if ( V_26 ) {
if ( V_120 )
V_120 -> V_125 = V_26 -> V_125 ;
else
V_2 -> V_124 = V_26 -> V_125 ;
}
F_14 ( & V_2 -> V_123 ) ;
if ( V_26 ) {
for ( V_28 = V_26 -> V_114 ; V_28 ; V_28 = V_106 ) {
V_106 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
F_8 ( V_26 -> V_10 ) ;
F_53 ( V_26 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_173 ;
F_11 ( & V_2 -> V_123 ) ;
V_26 = V_2 -> V_124 ;
V_2 -> V_124 = NULL ;
F_14 ( & V_2 -> V_123 ) ;
for (; V_26 ; V_26 = V_173 ) {
V_173 = V_26 -> V_125 ;
F_94 ( V_26 ) ;
F_8 ( V_26 -> V_10 ) ;
F_53 ( V_26 ) ;
}
F_55 () ;
F_56 (in_dev, pmc) {
struct V_27 * V_28 , * V_106 ;
F_11 ( & V_26 -> V_12 ) ;
V_28 = V_26 -> V_114 ;
V_26 -> V_114 = NULL ;
F_14 ( & V_26 -> V_12 ) ;
for (; V_28 ; V_28 = V_106 ) {
V_106 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
}
F_57 () ;
}
static void F_95 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_96
int V_15 ;
#endif
if ( V_8 -> V_174 ) {
V_8 -> V_174 = 0 ;
F_89 ( V_2 , V_8 -> V_105 ) ;
}
#ifdef F_96
if ( V_8 -> V_105 == V_113 )
return;
V_15 = V_8 -> V_15 ;
F_10 ( V_8 ) ;
if ( ! V_2 -> V_175 ) {
if ( F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) ) {
if ( V_15 )
F_60 ( V_2 , V_8 , V_129 ) ;
return;
}
F_91 ( V_2 , V_8 ) ;
F_64 ( V_2 ) ;
}
#endif
}
static void F_97 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
if ( V_8 -> V_174 == 0 ) {
V_8 -> V_174 = 1 ;
F_86 ( V_2 , V_8 -> V_105 ) ;
}
#ifdef F_96
if ( V_8 -> V_105 == V_113 )
return;
if ( V_2 -> V_175 )
return;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
F_11 ( & V_8 -> V_12 ) ;
F_15 ( V_8 , V_176 ) ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
V_8 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
F_64 ( V_2 ) ;
#endif
}
static T_2 F_98 ( const struct V_7 * V_8 )
{
return F_99 ( ( V_177 T_2 ) V_8 -> V_105 , V_178 ) ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_179 ;
T_2 V_180 ;
V_179 = F_101 ( V_2 -> V_179 ) ;
if ( V_179 ) {
V_180 = F_98 ( V_8 ) ;
V_8 -> V_181 = V_179 [ V_180 ] ;
F_102 ( V_179 [ V_180 ] , V_8 ) ;
return;
}
if ( V_2 -> V_182 < 4 )
return;
V_179 = F_92 ( sizeof( struct V_7 * ) << V_178 ,
V_172 ) ;
if ( ! V_179 )
return;
F_103 (in_dev, im) {
V_180 = F_98 ( V_8 ) ;
V_8 -> V_181 = V_179 [ V_180 ] ;
F_104 ( V_179 [ V_180 ] , V_8 ) ;
}
F_102 ( V_2 -> V_179 , V_179 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_179 = F_101 ( V_2 -> V_179 ) ;
struct V_7 * V_183 ;
if ( ! V_179 )
return;
V_179 += F_98 ( V_8 ) ;
while ( ( V_183 = F_101 ( * V_179 ) ) != V_8 )
V_179 = & V_183 -> V_181 ;
* V_179 = V_8 -> V_181 ;
}
void F_106 ( struct V_1 * V_2 , T_1 V_169 )
{
struct V_7 * V_8 ;
F_107 () ;
F_103 (in_dev, im) {
if ( V_8 -> V_105 == V_169 ) {
V_8 -> V_184 ++ ;
F_108 ( V_2 , & V_169 , V_39 , 0 , NULL , 0 ) ;
goto V_185;
}
}
V_8 = F_92 ( sizeof( * V_8 ) , V_172 ) ;
if ( ! V_8 )
goto V_185;
V_8 -> V_184 = 1 ;
V_8 -> V_10 = V_2 ;
F_20 ( V_2 ) ;
V_8 -> V_105 = V_169 ;
V_8 -> V_35 = V_39 ;
V_8 -> V_38 [ V_39 ] = 1 ;
F_109 ( & V_8 -> V_9 , 1 ) ;
F_110 ( & V_8 -> V_12 ) ;
#ifdef F_96
F_111 ( & V_8 -> V_13 , & F_65 , ( unsigned long ) V_8 ) ;
V_8 -> V_16 = V_136 ;
#endif
V_8 -> V_186 = V_2 -> V_187 ;
V_2 -> V_182 ++ ;
F_102 ( V_2 -> V_187 , V_8 ) ;
F_100 ( V_2 , V_8 ) ;
#ifdef F_96
F_93 ( V_2 , V_8 -> V_105 ) ;
#endif
F_97 ( V_8 ) ;
if ( ! V_2 -> V_175 )
F_112 ( V_2 ) ;
V_185:
return;
}
static void F_113 ( struct V_1 * V_2 )
{
#ifdef F_96
struct V_7 * V_8 ;
int type ;
F_107 () ;
F_103 (in_dev, im) {
if ( V_8 -> V_105 == V_113 )
continue;
if ( F_2 ( V_2 ) )
type = V_137 ;
else if ( F_3 ( V_2 ) )
type = V_138 ;
else
type = V_87 ;
F_60 ( V_2 , V_8 , type ) ;
}
#endif
}
void F_114 ( struct V_1 * V_2 , T_1 V_169 )
{
struct V_7 * V_141 ;
struct V_7 T_3 * * V_188 ;
F_107 () ;
for ( V_188 = & V_2 -> V_187 ;
( V_141 = F_101 ( * V_188 ) ) != NULL ;
V_188 = & V_141 -> V_186 ) {
if ( V_141 -> V_105 == V_169 ) {
if ( -- V_141 -> V_184 == 0 ) {
F_105 ( V_2 , V_141 ) ;
* V_188 = V_141 -> V_186 ;
V_2 -> V_182 -- ;
F_95 ( V_141 ) ;
F_94 ( V_141 ) ;
if ( ! V_2 -> V_175 )
F_112 ( V_2 ) ;
F_6 ( V_141 ) ;
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
V_2 -> V_134 = 0 ;
if ( F_12 ( & V_2 -> V_24 ) )
F_73 ( V_2 ) ;
V_2 -> V_21 = 0 ;
if ( F_12 ( & V_2 -> V_22 ) )
F_73 ( V_2 ) ;
F_74 ( V_2 ) ;
#endif
F_114 ( V_2 , V_113 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
F_107 () ;
#ifdef F_96
F_111 ( & V_2 -> V_22 , F_62 ,
( unsigned long ) V_2 ) ;
F_111 ( & V_2 -> V_24 , F_63 ,
( unsigned long ) V_2 ) ;
V_2 -> V_135 = V_136 ;
#endif
F_110 ( & V_2 -> V_123 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_107 () ;
F_106 ( V_2 , V_113 ) ;
F_103 (in_dev, pmc)
F_97 ( V_26 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
struct V_7 * V_141 ;
F_107 () ;
F_117 ( V_2 ) ;
while ( ( V_141 = F_101 ( V_2 -> V_187 ) ) != NULL ) {
V_2 -> V_187 = V_141 -> V_186 ;
V_2 -> V_182 -- ;
F_94 ( V_141 ) ;
F_6 ( V_141 ) ;
}
}
static struct V_1 * F_121 ( struct V_59 * V_59 , struct V_189 * V_190 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_191 = NULL ;
if ( V_190 -> V_192 ) {
V_191 = F_122 ( V_59 , V_190 -> V_192 ) ;
return V_191 ;
}
if ( V_190 -> V_193 . V_194 ) {
V_50 = F_123 ( V_59 , V_190 -> V_193 . V_194 , false ) ;
if ( ! V_50 )
return NULL ;
}
if ( ! V_50 ) {
struct V_53 * V_54 = F_124 ( V_59 ,
V_190 -> V_195 . V_194 ,
0 , 0 , 0 ) ;
if ( ! F_32 ( V_54 ) ) {
V_50 = V_54 -> V_72 . V_50 ;
F_61 ( V_54 ) ;
}
}
if ( V_50 ) {
V_190 -> V_192 = V_50 -> V_71 ;
V_191 = F_125 ( V_50 ) ;
}
return V_191 ;
}
static int F_126 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_196 )
{
struct V_27 * V_28 , * V_107 ;
int V_197 = 0 ;
V_107 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_117 == * V_196 )
break;
V_107 = V_28 ;
}
if ( ! V_28 || V_28 -> V_37 [ V_35 ] == 0 ) {
return - V_198 ;
}
V_28 -> V_37 [ V_35 ] -- ;
if ( V_28 -> V_37 [ V_35 ] == 0 ) {
F_112 ( V_26 -> V_10 ) ;
}
if ( ! V_28 -> V_37 [ V_36 ] && ! V_28 -> V_37 [ V_39 ] ) {
#ifdef F_96
struct V_1 * V_2 = V_26 -> V_10 ;
#endif
if ( V_107 )
V_107 -> V_47 = V_28 -> V_47 ;
else
V_26 -> V_46 = V_28 -> V_47 ;
#ifdef F_96
if ( V_28 -> V_199 &&
! F_2 ( V_2 ) && ! F_3 ( V_2 ) ) {
V_28 -> V_43 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_28 -> V_47 = V_26 -> V_114 ;
V_26 -> V_114 = V_28 ;
V_197 = 1 ;
} else
#endif
F_53 ( V_28 ) ;
}
return V_197 ;
}
static int F_127 ( struct V_1 * V_2 , T_1 * V_200 , int V_35 ,
int V_38 , T_1 * V_196 , int V_201 )
{
struct V_7 * V_26 ;
int V_202 = 0 ;
int V_141 , V_203 ;
if ( ! V_2 )
return - V_204 ;
F_55 () ;
F_56 (in_dev, pmc) {
if ( * V_200 == V_26 -> V_105 )
break;
}
if ( ! V_26 ) {
F_57 () ;
return - V_198 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_57 () ;
#ifdef F_96
F_128 ( V_26 ) ;
#endif
if ( ! V_201 ) {
V_203 = - V_205 ;
if ( ! V_26 -> V_38 [ V_35 ] )
goto V_206;
V_26 -> V_38 [ V_35 ] -- ;
}
V_203 = 0 ;
for ( V_141 = 0 ; V_141 < V_38 ; V_141 ++ ) {
int V_197 = F_126 ( V_26 , V_35 , & V_196 [ V_141 ] ) ;
V_202 |= V_197 > 0 ;
if ( ! V_203 && V_197 < 0 )
V_203 = V_197 ;
}
if ( V_26 -> V_35 == V_39 &&
V_26 -> V_38 [ V_39 ] == 0 &&
V_26 -> V_38 [ V_36 ] ) {
#ifdef F_96
struct V_27 * V_28 ;
#endif
V_26 -> V_35 = V_36 ;
#ifdef F_96
V_26 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_2 -> V_134 = V_26 -> V_118 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_64 ( V_26 -> V_10 ) ;
} else if ( F_129 ( V_26 ) || V_202 ) {
F_64 ( V_26 -> V_10 ) ;
#endif
}
V_206:
F_14 ( & V_26 -> V_12 ) ;
return V_203 ;
}
static int F_130 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_196 )
{
struct V_27 * V_28 , * V_107 ;
V_107 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_117 == * V_196 )
break;
V_107 = V_28 ;
}
if ( ! V_28 ) {
V_28 = F_92 ( sizeof( * V_28 ) , V_65 ) ;
if ( ! V_28 )
return - V_207 ;
V_28 -> V_117 = * V_196 ;
if ( V_107 ) {
V_107 -> V_47 = V_28 ;
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
int V_208 = V_26 -> V_38 [ V_39 ] ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
if ( V_26 -> V_38 [ V_39 ] ) {
V_28 -> V_199 = V_208 ==
V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_28 -> V_199 = V_28 -> V_37 [ V_36 ] != 0 ;
}
static int F_129 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_209 ;
int V_208 = V_26 -> V_38 [ V_39 ] ;
int V_153 = V_26 -> V_10 -> V_135 ;
int V_210 , V_197 ;
V_197 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_26 -> V_38 [ V_39 ] ) {
V_210 = V_208 == V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_210 = V_28 -> V_37 [ V_36 ] != 0 ;
if ( V_210 ) {
if ( ! V_28 -> V_199 ) {
struct V_27 * V_211 = NULL ;
for ( V_209 = V_26 -> V_114 ; V_209 ; V_209 = V_209 -> V_47 ) {
if ( V_209 -> V_117 == V_28 -> V_117 )
break;
V_211 = V_209 ;
}
if ( V_209 ) {
if ( V_211 )
V_211 -> V_47 = V_209 -> V_47 ;
else
V_26 -> V_114 = V_209 -> V_47 ;
F_53 ( V_209 ) ;
}
V_28 -> V_43 = V_153 ;
V_197 ++ ;
}
} else if ( V_28 -> V_199 ) {
V_28 -> V_43 = 0 ;
for ( V_209 = V_26 -> V_114 ; V_209 ; V_209 = V_209 -> V_47 )
if ( V_209 -> V_117 == V_28 -> V_117 )
break;
if ( ! V_209 ) {
V_209 = F_131 ( sizeof( * V_209 ) , V_65 ) ;
if ( ! V_209 )
continue;
* V_209 = * V_28 ;
V_209 -> V_47 = V_26 -> V_114 ;
V_26 -> V_114 = V_209 ;
}
V_209 -> V_43 = V_153 ;
V_197 ++ ;
}
}
return V_197 ;
}
static int F_108 ( struct V_1 * V_2 , T_1 * V_200 , int V_35 ,
int V_38 , T_1 * V_196 , int V_201 )
{
struct V_7 * V_26 ;
int V_212 ;
int V_141 , V_203 ;
if ( ! V_2 )
return - V_204 ;
F_55 () ;
F_56 (in_dev, pmc) {
if ( * V_200 == V_26 -> V_105 )
break;
}
if ( ! V_26 ) {
F_57 () ;
return - V_198 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_57 () ;
#ifdef F_96
F_128 ( V_26 ) ;
#endif
V_212 = V_26 -> V_35 == V_39 ;
if ( ! V_201 )
V_26 -> V_38 [ V_35 ] ++ ;
V_203 = 0 ;
for ( V_141 = 0 ; V_141 < V_38 ; V_141 ++ ) {
V_203 = F_130 ( V_26 , V_35 , & V_196 [ V_141 ] ) ;
if ( V_203 )
break;
}
if ( V_203 ) {
int V_213 ;
if ( ! V_201 )
V_26 -> V_38 [ V_35 ] -- ;
for ( V_213 = 0 ; V_213 < V_141 ; V_213 ++ )
( void ) F_126 ( V_26 , V_35 , & V_196 [ V_213 ] ) ;
} else if ( V_212 != ( V_26 -> V_38 [ V_39 ] != 0 ) ) {
#ifdef F_96
struct V_27 * V_28 ;
V_2 = V_26 -> V_10 ;
#endif
if ( V_26 -> V_38 [ V_39 ] )
V_26 -> V_35 = V_39 ;
else if ( V_26 -> V_38 [ V_36 ] )
V_26 -> V_35 = V_36 ;
#ifdef F_96
V_26 -> V_118 = V_2 -> V_135 ? V_2 -> V_135 :
V_136 ;
V_2 -> V_134 = V_26 -> V_118 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_64 ( V_2 ) ;
} else if ( F_129 ( V_26 ) ) {
F_64 ( V_2 ) ;
#endif
}
F_14 ( & V_26 -> V_12 ) ;
return V_203 ;
}
static void F_94 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_214 ;
for ( V_28 = V_26 -> V_114 ; V_28 ; V_28 = V_214 ) {
V_214 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
V_26 -> V_114 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_214 ) {
V_214 = V_28 -> V_47 ;
F_53 ( V_28 ) ;
}
V_26 -> V_46 = NULL ;
V_26 -> V_35 = V_39 ;
V_26 -> V_38 [ V_36 ] = 0 ;
V_26 -> V_38 [ V_39 ] = 1 ;
}
int F_132 ( struct V_215 * V_216 , struct V_189 * V_190 )
{
int V_203 ;
T_1 V_169 = V_190 -> V_195 . V_194 ;
struct V_217 * V_218 = NULL , * V_141 ;
struct V_1 * V_2 ;
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_59 * V_59 = F_134 ( V_216 ) ;
int V_71 ;
int V_221 = 0 ;
if ( ! F_135 ( V_169 ) )
return - V_205 ;
F_136 () ;
V_2 = F_121 ( V_59 , V_190 ) ;
if ( ! V_2 ) {
V_218 = NULL ;
V_203 = - V_204 ;
goto V_222;
}
V_203 = - V_223 ;
V_71 = V_190 -> V_192 ;
F_103 (inet, i) {
if ( V_141 -> V_224 . V_195 . V_194 == V_169 &&
V_141 -> V_224 . V_192 == V_71 )
goto V_222;
V_221 ++ ;
}
V_203 = - V_207 ;
if ( V_221 >= V_225 )
goto V_222;
V_218 = F_137 ( V_216 , sizeof( * V_218 ) , V_172 ) ;
if ( V_218 == NULL )
goto V_222;
memcpy ( & V_218 -> V_224 , V_190 , sizeof( * V_190 ) ) ;
V_218 -> V_186 = V_220 -> V_187 ;
V_218 -> V_226 = NULL ;
V_218 -> V_35 = V_39 ;
F_102 ( V_220 -> V_187 , V_218 ) ;
F_106 ( V_2 , V_169 ) ;
V_203 = 0 ;
V_222:
F_138 () ;
return V_203 ;
}
static int F_139 ( struct V_215 * V_216 , struct V_217 * V_218 ,
struct V_1 * V_2 )
{
struct V_227 * V_28 = F_101 ( V_218 -> V_226 ) ;
int V_203 ;
if ( V_28 == NULL ) {
return F_127 ( V_2 , & V_218 -> V_224 . V_195 . V_194 ,
V_218 -> V_35 , 0 , NULL , 0 ) ;
}
V_203 = F_127 ( V_2 , & V_218 -> V_224 . V_195 . V_194 ,
V_218 -> V_35 , V_28 -> V_228 , V_28 -> V_229 , 0 ) ;
F_104 ( V_218 -> V_226 , NULL ) ;
F_140 ( F_141 ( V_28 -> V_230 ) , & V_216 -> V_231 ) ;
F_9 ( V_28 , V_11 ) ;
return V_203 ;
}
int F_142 ( struct V_215 * V_216 , struct V_189 * V_190 )
{
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_217 * V_218 ;
struct V_217 T_3 * * V_232 ;
struct V_1 * V_2 ;
struct V_59 * V_59 = F_134 ( V_216 ) ;
T_1 V_128 = V_190 -> V_195 . V_194 ;
T_2 V_71 ;
int V_233 = - V_234 ;
F_136 () ;
V_2 = F_121 ( V_59 , V_190 ) ;
V_71 = V_190 -> V_192 ;
for ( V_232 = & V_220 -> V_187 ;
( V_218 = F_101 ( * V_232 ) ) != NULL ;
V_232 = & V_218 -> V_186 ) {
if ( V_218 -> V_224 . V_195 . V_194 != V_128 )
continue;
if ( V_71 ) {
if ( V_218 -> V_224 . V_192 != V_71 )
continue;
} else if ( V_190 -> V_193 . V_194 && V_190 -> V_193 . V_194 !=
V_218 -> V_224 . V_193 . V_194 )
continue;
( void ) F_139 ( V_216 , V_218 , V_2 ) ;
* V_232 = V_218 -> V_186 ;
if ( V_2 )
F_114 ( V_2 , V_128 ) ;
F_138 () ;
F_140 ( sizeof( * V_218 ) , & V_216 -> V_231 ) ;
F_9 ( V_218 , V_11 ) ;
return 0 ;
}
if ( ! V_2 )
V_233 = - V_204 ;
F_138 () ;
return V_233 ;
}
int F_143 ( int V_235 , int V_236 , struct V_215 * V_216 , struct
V_237 * V_238 , int V_71 )
{
int V_203 ;
struct V_189 V_190 ;
T_1 V_169 = V_238 -> V_195 ;
struct V_217 * V_26 ;
struct V_1 * V_2 = NULL ;
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_227 * V_239 ;
struct V_59 * V_59 = F_134 ( V_216 ) ;
int V_240 = 0 ;
int V_141 , V_213 , V_197 ;
if ( ! F_135 ( V_169 ) )
return - V_205 ;
F_136 () ;
V_190 . V_195 . V_194 = V_238 -> V_195 ;
V_190 . V_193 . V_194 = V_238 -> V_241 ;
V_190 . V_192 = V_71 ;
V_2 = F_121 ( V_59 , & V_190 ) ;
if ( ! V_2 ) {
V_203 = - V_204 ;
goto V_222;
}
V_203 = - V_234 ;
F_103 (inet, pmc) {
if ( ( V_26 -> V_224 . V_195 . V_194 ==
V_190 . V_195 . V_194 ) &&
( V_26 -> V_224 . V_192 == V_190 . V_192 ) )
break;
}
if ( ! V_26 ) {
V_203 = - V_205 ;
goto V_222;
}
if ( V_26 -> V_226 ) {
if ( V_26 -> V_35 != V_236 ) {
V_203 = - V_205 ;
goto V_222;
}
} else if ( V_26 -> V_35 != V_236 ) {
F_108 ( V_2 , & V_238 -> V_195 , V_236 , 0 , NULL , 0 ) ;
F_127 ( V_2 , & V_238 -> V_195 , V_26 -> V_35 , 0 ,
NULL , 0 ) ;
V_26 -> V_35 = V_236 ;
}
V_239 = F_101 ( V_26 -> V_226 ) ;
if ( ! V_235 ) {
if ( ! V_239 )
goto V_222;
V_197 = ! 0 ;
for ( V_141 = 0 ; V_141 < V_239 -> V_228 ; V_141 ++ ) {
V_197 = memcmp ( & V_239 -> V_229 [ V_141 ] , & V_238 -> V_242 ,
sizeof( T_1 ) ) ;
if ( V_197 == 0 )
break;
}
if ( V_197 )
goto V_222;
if ( V_239 -> V_228 == 1 && V_236 == V_36 ) {
V_240 = 1 ;
goto V_222;
}
F_127 ( V_2 , & V_238 -> V_195 , V_236 , 1 ,
& V_238 -> V_242 , 1 ) ;
for ( V_213 = V_141 + 1 ; V_213 < V_239 -> V_228 ; V_213 ++ )
V_239 -> V_229 [ V_213 - 1 ] = V_239 -> V_229 [ V_213 ] ;
V_239 -> V_228 -- ;
V_203 = 0 ;
goto V_222;
}
if ( V_239 && V_239 -> V_228 >= V_243 ) {
V_203 = - V_207 ;
goto V_222;
}
if ( ! V_239 || V_239 -> V_228 == V_239 -> V_230 ) {
struct V_227 * V_244 ;
int V_221 = V_245 ;
if ( V_239 )
V_221 += V_239 -> V_230 ;
V_244 = F_137 ( V_216 , F_141 ( V_221 ) , V_172 ) ;
if ( ! V_244 ) {
V_203 = - V_207 ;
goto V_222;
}
V_244 -> V_230 = V_221 ;
V_244 -> V_228 = V_221 - V_245 ;
if ( V_239 ) {
for ( V_141 = 0 ; V_141 < V_239 -> V_228 ; V_141 ++ )
V_244 -> V_229 [ V_141 ] = V_239 -> V_229 [ V_141 ] ;
F_140 ( F_141 ( V_239 -> V_230 ) , & V_216 -> V_231 ) ;
F_9 ( V_239 , V_11 ) ;
}
F_102 ( V_26 -> V_226 , V_244 ) ;
V_239 = V_244 ;
}
V_197 = 1 ;
for ( V_141 = 0 ; V_141 < V_239 -> V_228 ; V_141 ++ ) {
V_197 = memcmp ( & V_239 -> V_229 [ V_141 ] , & V_238 -> V_242 ,
sizeof( T_1 ) ) ;
if ( V_197 == 0 )
break;
}
if ( V_197 == 0 )
goto V_222;
for ( V_213 = V_239 -> V_228 - 1 ; V_213 >= V_141 ; V_213 -- )
V_239 -> V_229 [ V_213 + 1 ] = V_239 -> V_229 [ V_213 ] ;
V_239 -> V_229 [ V_141 ] = V_238 -> V_242 ;
V_239 -> V_228 ++ ;
V_203 = 0 ;
F_108 ( V_2 , & V_238 -> V_195 , V_236 , 1 ,
& V_238 -> V_242 , 1 ) ;
V_222:
F_138 () ;
if ( V_240 )
return F_142 ( V_216 , & V_190 ) ;
return V_203 ;
}
int F_144 ( struct V_215 * V_216 , struct V_246 * V_247 , int V_71 )
{
int V_203 = 0 ;
struct V_189 V_190 ;
T_1 V_169 = V_247 -> V_248 ;
struct V_217 * V_26 ;
struct V_1 * V_2 ;
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_227 * V_244 , * V_239 ;
struct V_59 * V_59 = F_134 ( V_216 ) ;
int V_240 = 0 ;
if ( ! F_135 ( V_169 ) )
return - V_205 ;
if ( V_247 -> V_249 != V_36 &&
V_247 -> V_249 != V_39 )
return - V_205 ;
F_136 () ;
V_190 . V_195 . V_194 = V_247 -> V_248 ;
V_190 . V_193 . V_194 = V_247 -> V_250 ;
V_190 . V_192 = V_71 ;
V_2 = F_121 ( V_59 , & V_190 ) ;
if ( ! V_2 ) {
V_203 = - V_204 ;
goto V_222;
}
if ( V_247 -> V_249 == V_36 && V_247 -> V_251 == 0 ) {
V_240 = 1 ;
goto V_222;
}
F_103 (inet, pmc) {
if ( V_26 -> V_224 . V_195 . V_194 == V_247 -> V_248 &&
V_26 -> V_224 . V_192 == V_190 . V_192 )
break;
}
if ( ! V_26 ) {
V_203 = - V_205 ;
goto V_222;
}
if ( V_247 -> V_251 ) {
V_244 = F_137 ( V_216 , F_141 ( V_247 -> V_251 ) ,
V_172 ) ;
if ( ! V_244 ) {
V_203 = - V_207 ;
goto V_222;
}
V_244 -> V_230 = V_244 -> V_228 = V_247 -> V_251 ;
memcpy ( V_244 -> V_229 , V_247 -> V_252 ,
V_247 -> V_251 * sizeof( V_247 -> V_252 [ 0 ] ) ) ;
V_203 = F_108 ( V_2 , & V_247 -> V_248 ,
V_247 -> V_249 , V_244 -> V_228 , V_244 -> V_229 , 0 ) ;
if ( V_203 ) {
F_145 ( V_216 , V_244 , F_141 ( V_244 -> V_230 ) ) ;
goto V_222;
}
} else {
V_244 = NULL ;
( void ) F_108 ( V_2 , & V_247 -> V_248 ,
V_247 -> V_249 , 0 , NULL , 0 ) ;
}
V_239 = F_101 ( V_26 -> V_226 ) ;
if ( V_239 ) {
( void ) F_127 ( V_2 , & V_247 -> V_248 , V_26 -> V_35 ,
V_239 -> V_228 , V_239 -> V_229 , 0 ) ;
F_140 ( F_141 ( V_239 -> V_230 ) , & V_216 -> V_231 ) ;
F_9 ( V_239 , V_11 ) ;
} else
( void ) F_127 ( V_2 , & V_247 -> V_248 , V_26 -> V_35 ,
0 , NULL , 0 ) ;
F_102 ( V_26 -> V_226 , V_244 ) ;
V_26 -> V_35 = V_247 -> V_249 ;
V_203 = 0 ;
V_222:
F_138 () ;
if ( V_240 )
V_203 = F_142 ( V_216 , & V_190 ) ;
return V_203 ;
}
int F_146 ( struct V_215 * V_216 , struct V_246 * V_247 ,
struct V_246 T_4 * V_253 , int T_4 * V_254 )
{
int V_203 , V_142 , V_221 , V_255 ;
struct V_189 V_190 ;
T_1 V_169 = V_247 -> V_248 ;
struct V_217 * V_26 ;
struct V_1 * V_2 ;
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_227 * V_239 ;
struct V_59 * V_59 = F_134 ( V_216 ) ;
if ( ! F_135 ( V_169 ) )
return - V_205 ;
F_136 () ;
V_190 . V_195 . V_194 = V_247 -> V_248 ;
V_190 . V_193 . V_194 = V_247 -> V_250 ;
V_190 . V_192 = 0 ;
V_2 = F_121 ( V_59 , & V_190 ) ;
if ( ! V_2 ) {
V_203 = - V_204 ;
goto V_222;
}
V_203 = - V_234 ;
F_103 (inet, pmc) {
if ( V_26 -> V_224 . V_195 . V_194 == V_247 -> V_248 &&
V_26 -> V_224 . V_192 == V_190 . V_192 )
break;
}
if ( ! V_26 )
goto V_222;
V_247 -> V_249 = V_26 -> V_35 ;
V_239 = F_101 ( V_26 -> V_226 ) ;
F_138 () ;
if ( ! V_239 ) {
V_142 = 0 ;
V_221 = 0 ;
} else {
V_221 = V_239 -> V_228 ;
}
V_255 = V_221 < V_247 -> V_251 ? V_221 : V_247 -> V_251 ;
V_142 = V_255 * sizeof( V_239 -> V_229 [ 0 ] ) ;
V_247 -> V_251 = V_221 ;
if ( F_147 ( F_148 ( V_255 ) , V_254 ) ||
F_149 ( V_253 , V_247 , F_148 ( 0 ) ) ) {
return - V_256 ;
}
if ( V_142 &&
F_149 ( & V_253 -> V_252 [ 0 ] , V_239 -> V_229 , V_142 ) )
return - V_256 ;
return 0 ;
V_222:
F_138 () ;
return V_203 ;
}
int F_150 ( struct V_215 * V_216 , struct V_257 * V_258 ,
struct V_257 T_4 * V_253 , int T_4 * V_254 )
{
int V_203 , V_141 , V_221 , V_255 ;
struct V_259 * V_260 ;
T_1 V_169 ;
struct V_217 * V_26 ;
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_227 * V_239 ;
V_260 = (struct V_259 * ) & V_258 -> V_261 ;
if ( V_260 -> V_262 != V_263 )
return - V_205 ;
V_169 = V_260 -> V_264 . V_194 ;
if ( ! F_135 ( V_169 ) )
return - V_205 ;
F_136 () ;
V_203 = - V_234 ;
F_103 (inet, pmc) {
if ( V_26 -> V_224 . V_195 . V_194 == V_169 &&
V_26 -> V_224 . V_192 == V_258 -> V_265 )
break;
}
if ( ! V_26 )
goto V_222;
V_258 -> V_266 = V_26 -> V_35 ;
V_239 = F_101 ( V_26 -> V_226 ) ;
F_138 () ;
V_221 = V_239 ? V_239 -> V_228 : 0 ;
V_255 = V_221 < V_258 -> V_267 ? V_221 : V_258 -> V_267 ;
V_258 -> V_267 = V_221 ;
if ( F_147 ( F_151 ( V_255 ) , V_254 ) ||
F_149 ( V_253 , V_258 , F_151 ( 0 ) ) ) {
return - V_256 ;
}
for ( V_141 = 0 ; V_141 < V_255 ; V_141 ++ ) {
struct V_268 V_269 ;
V_260 = (struct V_259 * ) & V_269 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
V_260 -> V_262 = V_263 ;
V_260 -> V_264 . V_194 = V_239 -> V_229 [ V_141 ] ;
if ( F_149 ( & V_253 -> V_270 [ V_141 ] , & V_269 , sizeof( V_269 ) ) )
return - V_256 ;
}
return 0 ;
V_222:
F_138 () ;
return V_203 ;
}
int F_152 ( struct V_215 * V_216 , T_1 V_271 , T_1 V_272 , int V_273 )
{
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_217 * V_26 ;
struct V_227 * V_239 ;
int V_141 ;
int V_233 ;
V_233 = 1 ;
if ( ! F_135 ( V_271 ) )
goto V_185;
F_55 () ;
F_56 (inet, pmc) {
if ( V_26 -> V_224 . V_195 . V_194 == V_271 &&
V_26 -> V_224 . V_192 == V_273 )
break;
}
V_233 = V_220 -> V_274 ;
if ( ! V_26 )
goto V_275;
V_239 = F_153 ( V_26 -> V_226 ) ;
V_233 = ( V_26 -> V_35 == V_39 ) ;
if ( ! V_239 )
goto V_275;
for ( V_141 = 0 ; V_141 < V_239 -> V_228 ; V_141 ++ ) {
if ( V_239 -> V_229 [ V_141 ] == V_272 )
break;
}
V_233 = 0 ;
if ( V_26 -> V_35 == V_36 && V_141 >= V_239 -> V_228 )
goto V_275;
if ( V_26 -> V_35 == V_39 && V_141 < V_239 -> V_228 )
goto V_275;
V_233 = 1 ;
V_275:
F_57 () ;
V_185:
return V_233 ;
}
void F_154 ( struct V_215 * V_216 )
{
struct V_219 * V_220 = F_133 ( V_216 ) ;
struct V_217 * V_218 ;
struct V_59 * V_59 = F_134 ( V_216 ) ;
if ( V_220 -> V_187 == NULL )
return;
F_136 () ;
while ( ( V_218 = F_101 ( V_220 -> V_187 ) ) != NULL ) {
struct V_1 * V_2 ;
V_220 -> V_187 = V_218 -> V_186 ;
V_2 = F_122 ( V_59 , V_218 -> V_224 . V_192 ) ;
( void ) F_139 ( V_216 , V_218 , V_2 ) ;
if ( V_2 != NULL )
F_114 ( V_2 , V_218 -> V_224 . V_195 . V_194 ) ;
F_140 ( sizeof( * V_218 ) , & V_216 -> V_231 ) ;
F_9 ( V_218 , V_11 ) ;
}
F_138 () ;
}
int F_155 ( struct V_1 * V_2 , T_1 V_276 , T_1 V_277 , T_5 V_278 )
{
struct V_7 * V_8 ;
struct V_7 T_3 * * V_179 ;
struct V_27 * V_28 ;
int V_197 = 0 ;
V_179 = F_153 ( V_2 -> V_179 ) ;
if ( V_179 ) {
T_2 V_180 = F_99 ( ( V_177 T_2 ) V_276 , V_178 ) ;
for ( V_8 = F_153 ( V_179 [ V_180 ] ) ;
V_8 != NULL ;
V_8 = F_153 ( V_8 -> V_181 ) ) {
if ( V_8 -> V_105 == V_276 )
break;
}
} else {
F_56 (in_dev, im) {
if ( V_8 -> V_105 == V_276 )
break;
}
}
if ( V_8 && V_278 == V_70 ) {
V_197 = 1 ;
} else if ( V_8 ) {
if ( V_277 ) {
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_117 == V_277 )
break;
}
if ( V_28 )
V_197 = V_28 -> V_37 [ V_36 ] ||
V_28 -> V_37 [ V_39 ] !=
V_8 -> V_38 [ V_39 ] ;
else
V_197 = V_8 -> V_38 [ V_39 ] != 0 ;
} else
V_197 = 1 ;
}
return V_197 ;
}
static inline struct V_7 * F_156 ( struct V_279 * V_280 )
{
struct V_59 * V_59 = F_157 ( V_280 ) ;
struct V_7 * V_8 = NULL ;
struct V_281 * V_282 = F_158 ( V_280 ) ;
V_282 -> V_2 = NULL ;
F_159 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_78 ( V_282 -> V_50 ) ;
if ( ! V_2 )
continue;
V_8 = F_153 ( V_2 -> V_187 ) ;
if ( V_8 ) {
V_282 -> V_2 = V_2 ;
break;
}
}
return V_8 ;
}
static struct V_7 * F_160 ( struct V_279 * V_280 , struct V_7 * V_8 )
{
struct V_281 * V_282 = F_158 ( V_280 ) ;
V_8 = F_153 ( V_8 -> V_186 ) ;
while ( ! V_8 ) {
V_282 -> V_50 = F_161 ( V_282 -> V_50 ) ;
if ( ! V_282 -> V_50 ) {
V_282 -> V_2 = NULL ;
break;
}
V_282 -> V_2 = F_78 ( V_282 -> V_50 ) ;
if ( ! V_282 -> V_2 )
continue;
V_8 = F_153 ( V_282 -> V_2 -> V_187 ) ;
}
return V_8 ;
}
static struct V_7 * F_162 ( struct V_279 * V_280 , T_6 V_283 )
{
struct V_7 * V_8 = F_156 ( V_280 ) ;
if ( V_8 )
while ( V_283 && ( V_8 = F_160 ( V_280 , V_8 ) ) != NULL )
-- V_283 ;
return V_283 ? NULL : V_8 ;
}
static void * F_163 ( struct V_279 * V_280 , T_6 * V_283 )
__acquires( V_11 )
{
F_55 () ;
return * V_283 ? F_162 ( V_280 , * V_283 - 1 ) : V_284 ;
}
static void * F_164 ( struct V_279 * V_280 , void * V_285 , T_6 * V_283 )
{
struct V_7 * V_8 ;
if ( V_285 == V_284 )
V_8 = F_156 ( V_280 ) ;
else
V_8 = F_160 ( V_280 , V_285 ) ;
++ * V_283 ;
return V_8 ;
}
static void F_165 ( struct V_279 * V_280 , void * V_285 )
__releases( V_11 )
{
struct V_281 * V_282 = F_158 ( V_280 ) ;
V_282 -> V_2 = NULL ;
V_282 -> V_50 = NULL ;
F_57 () ;
}
static int F_166 ( struct V_279 * V_280 , void * V_285 )
{
if ( V_285 == V_284 )
F_167 ( V_280 ,
L_1 ) ;
else {
struct V_7 * V_8 = (struct V_7 * ) V_285 ;
struct V_281 * V_282 = F_158 ( V_280 ) ;
char * V_286 ;
long V_201 ;
#ifdef F_96
V_286 = F_2 ( V_282 -> V_2 ) ? L_2 :
F_3 ( V_282 -> V_2 ) ? L_3 :
L_4 ;
#else
V_286 = L_5 ;
#endif
if ( F_153 ( V_282 -> V_2 -> V_187 ) == V_8 ) {
F_168 ( V_280 , L_6 ,
V_282 -> V_50 -> V_71 , V_282 -> V_50 -> V_287 , V_282 -> V_2 -> V_182 , V_286 ) ;
}
V_201 = V_8 -> V_13 . V_25 - V_19 ;
F_168 ( V_280 ,
L_7 ,
V_8 -> V_105 , V_8 -> V_184 ,
V_8 -> V_14 ,
V_8 -> V_14 ? F_169 ( V_201 ) : 0 ,
V_8 -> V_15 ) ;
}
return 0 ;
}
static int F_170 ( struct V_288 * V_288 , struct V_289 * V_289 )
{
return F_171 ( V_288 , V_289 , & V_290 ,
sizeof( struct V_281 ) ) ;
}
static inline struct V_27 * F_172 ( struct V_279 * V_280 )
{
struct V_59 * V_59 = F_157 ( V_280 ) ;
struct V_27 * V_28 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_291 * V_282 = F_173 ( V_280 ) ;
V_282 -> V_191 = NULL ;
V_282 -> V_8 = NULL ;
F_159 (net, state->dev) {
struct V_1 * V_191 ;
V_191 = F_78 ( V_282 -> V_50 ) ;
if ( F_174 ( V_191 == NULL ) )
continue;
V_8 = F_153 ( V_191 -> V_187 ) ;
if ( F_175 ( V_8 != NULL ) ) {
F_11 ( & V_8 -> V_12 ) ;
V_28 = V_8 -> V_46 ;
if ( F_175 ( V_28 != NULL ) ) {
V_282 -> V_8 = V_8 ;
V_282 -> V_191 = V_191 ;
break;
}
F_14 ( & V_8 -> V_12 ) ;
}
}
return V_28 ;
}
static struct V_27 * F_176 ( struct V_279 * V_280 , struct V_27 * V_28 )
{
struct V_291 * V_282 = F_173 ( V_280 ) ;
V_28 = V_28 -> V_47 ;
while ( ! V_28 ) {
F_14 ( & V_282 -> V_8 -> V_12 ) ;
V_282 -> V_8 = V_282 -> V_8 -> V_125 ;
while ( ! V_282 -> V_8 ) {
V_282 -> V_50 = F_161 ( V_282 -> V_50 ) ;
if ( ! V_282 -> V_50 ) {
V_282 -> V_191 = NULL ;
goto V_185;
}
V_282 -> V_191 = F_78 ( V_282 -> V_50 ) ;
if ( ! V_282 -> V_191 )
continue;
V_282 -> V_8 = F_153 ( V_282 -> V_191 -> V_187 ) ;
}
if ( ! V_282 -> V_8 )
break;
F_11 ( & V_282 -> V_8 -> V_12 ) ;
V_28 = V_282 -> V_8 -> V_46 ;
}
V_185:
return V_28 ;
}
static struct V_27 * F_177 ( struct V_279 * V_280 , T_6 V_283 )
{
struct V_27 * V_28 = F_172 ( V_280 ) ;
if ( V_28 )
while ( V_283 && ( V_28 = F_176 ( V_280 , V_28 ) ) != NULL )
-- V_283 ;
return V_283 ? NULL : V_28 ;
}
static void * F_178 ( struct V_279 * V_280 , T_6 * V_283 )
__acquires( V_11 )
{
F_55 () ;
return * V_283 ? F_177 ( V_280 , * V_283 - 1 ) : V_284 ;
}
static void * F_179 ( struct V_279 * V_280 , void * V_285 , T_6 * V_283 )
{
struct V_27 * V_28 ;
if ( V_285 == V_284 )
V_28 = F_172 ( V_280 ) ;
else
V_28 = F_176 ( V_280 , V_285 ) ;
++ * V_283 ;
return V_28 ;
}
static void F_180 ( struct V_279 * V_280 , void * V_285 )
__releases( V_11 )
{
struct V_291 * V_282 = F_173 ( V_280 ) ;
if ( F_175 ( V_282 -> V_8 != NULL ) ) {
F_14 ( & V_282 -> V_8 -> V_12 ) ;
V_282 -> V_8 = NULL ;
}
V_282 -> V_191 = NULL ;
V_282 -> V_50 = NULL ;
F_57 () ;
}
static int F_181 ( struct V_279 * V_280 , void * V_285 )
{
struct V_27 * V_28 = (struct V_27 * ) V_285 ;
struct V_291 * V_282 = F_173 ( V_280 ) ;
if ( V_285 == V_284 ) {
F_168 ( V_280 ,
L_8
L_9 , L_10 ,
L_11 , L_12 ,
L_13 , L_14 , L_15 ) ;
} else {
F_168 ( V_280 ,
L_16
L_17 ,
V_282 -> V_50 -> V_71 , V_282 -> V_50 -> V_287 ,
F_182 ( V_282 -> V_8 -> V_105 ) ,
F_182 ( V_28 -> V_117 ) ,
V_28 -> V_37 [ V_36 ] ,
V_28 -> V_37 [ V_39 ] ) ;
}
return 0 ;
}
static int F_183 ( struct V_288 * V_288 , struct V_289 * V_289 )
{
return F_171 ( V_288 , V_289 , & V_292 ,
sizeof( struct V_291 ) ) ;
}
static int T_7 F_184 ( struct V_59 * V_59 )
{
struct V_293 * V_294 ;
V_294 = F_185 ( L_18 , V_295 , V_59 -> V_296 , & V_297 ) ;
if ( ! V_294 )
goto V_298;
V_294 = F_185 ( L_19 , V_295 , V_59 -> V_296 ,
& V_299 ) ;
if ( ! V_294 )
goto V_300;
return 0 ;
V_300:
F_186 ( L_18 , V_59 -> V_296 ) ;
V_298:
return - V_301 ;
}
static void T_8 F_187 ( struct V_59 * V_59 )
{
F_186 ( L_19 , V_59 -> V_296 ) ;
F_186 ( L_18 , V_59 -> V_296 ) ;
}
static int F_188 ( struct V_302 * V_303 ,
unsigned long V_304 , void * V_305 )
{
struct V_49 * V_50 = F_189 ( V_305 ) ;
struct V_1 * V_2 ;
switch ( V_304 ) {
case V_306 :
V_2 = F_125 ( V_50 ) ;
if ( V_2 )
F_113 ( V_2 ) ;
break;
default:
break;
}
return V_307 ;
}
int T_9 F_190 ( void )
{
int V_203 ;
V_203 = F_191 ( & V_308 ) ;
if ( V_203 )
return V_203 ;
V_203 = F_192 ( & V_309 ) ;
if ( V_203 )
goto V_310;
return 0 ;
V_310:
F_193 ( & V_308 ) ;
return V_203 ;
}
