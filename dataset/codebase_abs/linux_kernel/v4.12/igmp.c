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
unsigned long exp = V_19 + V_18 + 2 ;
if ( V_2 -> V_21 &&
F_20 ( exp , ( V_2 -> V_22 ) . V_23 ) )
return;
V_2 -> V_21 = 1 ;
if ( ! F_17 ( & V_2 -> V_22 , exp ) )
F_21 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_24 )
{
int V_18 = F_16 () % V_24 ;
if ( ! F_17 ( & V_2 -> V_25 , V_19 + V_18 + 2 ) )
F_21 ( V_2 ) ;
}
static void F_23 ( struct V_7 * V_8 , int V_17 )
{
F_11 ( & V_8 -> V_12 ) ;
V_8 -> V_16 = 0 ;
if ( F_12 ( & V_8 -> V_13 ) ) {
if ( ( long ) ( V_8 -> V_13 . V_23 - V_19 ) < V_17 ) {
F_24 ( & V_8 -> V_13 ) ;
V_8 -> V_14 = 1 ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
F_13 ( & V_8 -> V_9 ) ;
}
F_15 ( V_8 , V_17 ) ;
F_14 ( & V_8 -> V_12 ) ;
}
static int F_25 ( struct V_7 * V_26 , struct V_27 * V_28 , int type ,
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
F_26 ( struct V_7 * V_26 , int type , int V_29 , int V_30 )
{
struct V_27 * V_28 ;
int V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( ! F_25 ( V_26 , V_28 , type , V_29 , V_30 ) )
continue;
V_45 ++ ;
}
return V_45 ;
}
static struct V_48 * F_27 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_48 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_59 = F_28 ( V_50 ) ;
struct V_60 V_61 ;
int V_62 = F_29 ( V_50 ) ;
int V_63 = V_50 -> V_64 ;
unsigned int V_65 = V_51 ;
while ( 1 ) {
V_52 = F_30 ( V_65 + V_62 + V_63 ,
V_66 | V_67 ) ;
if ( V_52 )
break;
V_65 >>= 1 ;
if ( V_65 < 256 )
return NULL ;
}
V_52 -> V_68 = V_69 ;
V_54 = F_31 ( V_59 , & V_61 , NULL , V_70 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_32 ( V_54 ) ) {
F_33 ( V_52 ) ;
return NULL ;
}
F_34 ( V_52 , & V_54 -> V_73 ) ;
V_52 -> V_50 = V_50 ;
F_35 ( V_52 , V_62 ) ;
F_36 ( V_52 , V_51 , V_63 ) ;
F_37 ( V_52 ) ;
V_56 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_56 -> V_74 = 4 ;
V_56 -> V_75 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_56 -> V_76 = 0xc0 ;
V_56 -> V_77 = F_40 ( V_78 ) ;
V_56 -> V_79 = 1 ;
V_56 -> V_80 = V_61 . V_80 ;
V_56 -> V_81 = V_61 . V_81 ;
V_56 -> V_82 = V_71 ;
V_56 -> V_83 = 0 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_84 * ) & V_56 [ 1 ] ) [ 0 ] = V_85 ;
( ( V_84 * ) & V_56 [ 1 ] ) [ 1 ] = 4 ;
( ( V_84 * ) & V_56 [ 1 ] ) [ 2 ] = 0 ;
( ( V_84 * ) & V_56 [ 1 ] ) [ 3 ] = 0 ;
V_52 -> V_86 = V_52 -> V_87 + sizeof( struct V_55 ) + 4 ;
F_39 ( V_52 , sizeof( * V_58 ) ) ;
V_58 = F_42 ( V_52 ) ;
V_58 -> type = V_88 ;
V_58 -> V_89 = 0 ;
V_58 -> V_90 = 0 ;
V_58 -> V_91 = 0 ;
V_58 -> V_92 = 0 ;
return V_52 ;
}
static int F_43 ( struct V_48 * V_52 )
{
struct V_93 * V_58 = F_44 ( V_52 ) ;
const int V_94 = F_45 ( V_52 ) - F_46 ( V_52 ) ;
V_58 -> V_90 = F_47 ( F_44 ( V_52 ) , V_94 ) ;
return F_48 ( F_28 ( F_49 ( V_52 ) -> V_50 ) , V_52 -> V_95 , V_52 ) ;
}
static int F_50 ( struct V_7 * V_26 , int type , int V_96 , int V_97 )
{
return sizeof( struct V_98 ) + 4 * F_26 ( V_26 , type , V_96 , V_97 ) ;
}
static struct V_48 * F_51 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , struct V_98 * * V_99 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_57 * V_100 ;
struct V_98 * V_101 ;
if ( ! V_52 )
V_52 = F_27 ( V_50 , V_50 -> V_51 ) ;
if ( ! V_52 )
return NULL ;
V_101 = (struct V_98 * ) F_39 ( V_52 , sizeof( struct V_98 ) ) ;
V_101 -> V_102 = type ;
V_101 -> V_103 = 0 ;
V_101 -> V_104 = 0 ;
V_101 -> V_105 = V_26 -> V_106 ;
V_100 = F_42 ( V_52 ) ;
V_100 -> V_92 = F_40 ( F_52 ( V_100 -> V_92 ) + 1 ) ;
* V_99 = V_101 ;
return V_52 ;
}
static struct V_48 * F_53 ( struct V_48 * V_52 , struct V_7 * V_26 ,
int type , int V_29 , int V_30 )
{
struct V_49 * V_50 = V_26 -> V_10 -> V_50 ;
struct V_59 * V_59 = F_28 ( V_50 ) ;
struct V_57 * V_100 ;
struct V_98 * V_101 = NULL ;
struct V_27 * V_28 , * V_107 , * V_108 , * * V_109 ;
int V_45 , V_110 , V_111 , V_112 , V_113 ;
if ( V_26 -> V_106 == V_114 )
return V_52 ;
if ( F_54 ( V_26 -> V_106 ) && ! V_59 -> V_115 . V_116 )
return V_52 ;
V_112 = type == V_31 ||
type == V_32 ;
V_113 = type == V_32 ||
type == V_41 ;
V_110 = V_45 = 0 ;
V_109 = V_30 ? & V_26 -> V_117 : & V_26 -> V_46 ;
if ( ! * V_109 )
goto V_118;
V_100 = V_52 ? F_42 ( V_52 ) : NULL ;
if ( V_113 ) {
if ( V_100 && V_100 -> V_92 &&
F_55 ( V_52 ) < F_50 ( V_26 , type , V_29 , V_30 ) ) {
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_27 ( V_50 , V_50 -> V_51 ) ;
}
}
V_111 = 1 ;
V_108 = NULL ;
for ( V_28 = * V_109 ; V_28 ; V_28 = V_107 ) {
T_1 * V_119 ;
V_107 = V_28 -> V_47 ;
if ( ! F_25 ( V_26 , V_28 , type , V_29 , V_30 ) ) {
V_108 = V_28 ;
continue;
}
if ( ( ( V_29 && V_26 -> V_35 == V_39 ) ||
( ! V_29 && V_26 -> V_120 ) ) &&
( type == V_42 ||
type == V_44 ) && V_28 -> V_43 )
goto V_121;
if ( V_112 )
V_28 -> V_34 = 0 ;
if ( F_55 ( V_52 ) < sizeof( T_1 ) +
V_111 * sizeof( struct V_98 ) ) {
if ( V_113 && ! V_111 )
break;
if ( V_101 )
V_101 -> V_104 = F_40 ( V_45 ) ;
if ( V_52 )
F_43 ( V_52 ) ;
V_52 = F_27 ( V_50 , V_50 -> V_51 ) ;
V_111 = 1 ;
V_45 = 0 ;
}
if ( V_111 ) {
V_52 = F_51 ( V_52 , V_26 , type , & V_101 ) ;
V_111 = 0 ;
}
if ( ! V_52 )
return NULL ;
V_119 = ( T_1 * ) F_39 ( V_52 , sizeof( T_1 ) ) ;
* V_119 = V_28 -> V_122 ;
V_45 ++ ; V_110 ++ ;
if ( ( type == V_42 ||
type == V_44 ) && V_28 -> V_43 ) {
V_121:
V_28 -> V_43 -- ;
if ( ( V_30 || V_29 ) && V_28 -> V_43 == 0 ) {
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
* V_109 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
continue;
}
}
V_108 = V_28 ;
}
V_118:
if ( ! V_110 ) {
if ( type == V_42 ||
type == V_44 )
return V_52 ;
if ( V_26 -> V_120 || V_112 ) {
if ( V_52 && F_55 ( V_52 ) < sizeof( struct V_98 ) ) {
F_43 ( V_52 ) ;
V_52 = NULL ;
}
V_52 = F_51 ( V_52 , V_26 , type , & V_101 ) ;
}
}
if ( V_101 )
V_101 -> V_104 = F_40 ( V_45 ) ;
if ( V_112 )
V_26 -> V_33 = 0 ;
return V_52 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_7 * V_26 )
{
struct V_48 * V_52 = NULL ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
int type ;
if ( ! V_26 ) {
F_58 () ;
F_59 (in_dev, pmc) {
if ( V_26 -> V_106 == V_114 )
continue;
if ( F_54 ( V_26 -> V_106 ) &&
! V_59 -> V_115 . V_116 )
continue;
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
F_60 () ;
} else {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] )
type = V_32 ;
else
type = V_31 ;
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
F_14 ( & V_26 -> V_12 ) ;
}
if ( ! V_52 )
return 0 ;
return F_43 ( V_52 ) ;
}
static void F_61 ( struct V_27 * * V_123 )
{
struct V_27 * V_108 , * V_107 , * V_28 ;
V_108 = NULL ;
for ( V_28 = * V_123 ; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
if ( V_28 -> V_43 == 0 ) {
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
* V_123 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
} else
V_108 = V_28 ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_124 , * V_125 ;
struct V_48 * V_52 = NULL ;
int type , V_126 ;
F_58 () ;
F_11 ( & V_2 -> V_127 ) ;
V_124 = NULL ;
for ( V_26 = V_2 -> V_128 ; V_26 ; V_26 = V_125 ) {
V_125 = V_26 -> V_129 ;
if ( V_26 -> V_35 == V_36 ) {
type = V_44 ;
V_126 = V_44 ;
V_52 = F_53 ( V_52 , V_26 , type , 1 , 0 ) ;
V_52 = F_53 ( V_52 , V_26 , V_126 , 1 , 1 ) ;
}
if ( V_26 -> V_120 ) {
if ( V_26 -> V_35 == V_39 ) {
type = V_40 ;
V_52 = F_53 ( V_52 , V_26 , type , 1 , 0 ) ;
}
V_26 -> V_120 -- ;
if ( V_26 -> V_120 == 0 ) {
F_61 ( & V_26 -> V_117 ) ;
F_61 ( & V_26 -> V_46 ) ;
}
}
if ( V_26 -> V_120 == 0 && ! V_26 -> V_117 && ! V_26 -> V_46 ) {
if ( V_124 )
V_124 -> V_129 = V_125 ;
else
V_2 -> V_128 = V_125 ;
F_8 ( V_26 -> V_10 ) ;
F_56 ( V_26 ) ;
} else
V_124 = V_26 ;
}
F_14 ( & V_2 -> V_127 ) ;
F_59 (in_dev, pmc) {
F_11 ( & V_26 -> V_12 ) ;
if ( V_26 -> V_38 [ V_39 ] ) {
type = V_44 ;
V_126 = V_42 ;
} else {
type = V_42 ;
V_126 = V_44 ;
}
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
V_52 = F_53 ( V_52 , V_26 , V_126 , 0 , 1 ) ;
if ( V_26 -> V_120 ) {
if ( V_26 -> V_35 == V_39 )
type = V_41 ;
else
type = V_40 ;
V_52 = F_53 ( V_52 , V_26 , type , 0 , 0 ) ;
V_26 -> V_120 -- ;
}
F_14 ( & V_26 -> V_12 ) ;
}
F_60 () ;
if ( ! V_52 )
return;
( void ) F_43 ( V_52 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_7 * V_26 ,
int type )
{
struct V_48 * V_52 ;
struct V_55 * V_130 ;
struct V_93 * V_131 ;
struct V_53 * V_54 ;
struct V_49 * V_50 = V_2 -> V_50 ;
struct V_59 * V_59 = F_28 ( V_50 ) ;
T_1 V_132 = V_26 ? V_26 -> V_106 : 0 ;
struct V_60 V_61 ;
T_1 V_73 ;
int V_62 , V_63 ;
if ( type == V_88 )
return F_57 ( V_2 , V_26 ) ;
if ( F_54 ( V_132 ) && ! V_59 -> V_115 . V_116 )
return 0 ;
if ( type == V_133 )
V_73 = V_134 ;
else
V_73 = V_132 ;
V_54 = F_31 ( V_59 , & V_61 , NULL , V_73 , 0 ,
0 , 0 ,
V_71 , 0 , V_50 -> V_72 ) ;
if ( F_32 ( V_54 ) )
return - 1 ;
V_62 = F_29 ( V_50 ) ;
V_63 = V_50 -> V_64 ;
V_52 = F_30 ( V_135 + V_62 + V_63 , V_66 ) ;
if ( ! V_52 ) {
F_64 ( V_54 ) ;
return - 1 ;
}
V_52 -> V_68 = V_69 ;
F_34 ( V_52 , & V_54 -> V_73 ) ;
F_35 ( V_52 , V_62 ) ;
F_37 ( V_52 ) ;
V_130 = F_38 ( V_52 ) ;
F_39 ( V_52 , sizeof( struct V_55 ) + 4 ) ;
V_130 -> V_74 = 4 ;
V_130 -> V_75 = ( sizeof( struct V_55 ) + 4 ) >> 2 ;
V_130 -> V_76 = 0xc0 ;
V_130 -> V_77 = F_40 ( V_78 ) ;
V_130 -> V_79 = 1 ;
V_130 -> V_80 = V_73 ;
V_130 -> V_81 = V_61 . V_81 ;
V_130 -> V_82 = V_71 ;
F_41 ( V_59 , V_52 , NULL ) ;
( ( V_84 * ) & V_130 [ 1 ] ) [ 0 ] = V_85 ;
( ( V_84 * ) & V_130 [ 1 ] ) [ 1 ] = 4 ;
( ( V_84 * ) & V_130 [ 1 ] ) [ 2 ] = 0 ;
( ( V_84 * ) & V_130 [ 1 ] ) [ 3 ] = 0 ;
V_131 = (struct V_93 * ) F_39 ( V_52 , sizeof( struct V_93 ) ) ;
V_131 -> type = type ;
V_131 -> V_136 = 0 ;
V_131 -> V_90 = 0 ;
V_131 -> V_132 = V_132 ;
V_131 -> V_90 = F_47 ( ( void * ) V_131 , sizeof( struct V_93 ) ) ;
return F_48 ( V_59 , V_52 -> V_95 , V_52 ) ;
}
static void F_65 ( unsigned long V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_137 ;
V_2 -> V_21 = 0 ;
F_57 ( V_2 , NULL ) ;
F_8 ( V_2 ) ;
}
static void F_66 ( unsigned long V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_137 ;
F_62 ( V_2 ) ;
if ( V_2 -> V_138 ) {
V_2 -> V_138 -- ;
F_22 ( V_2 ,
F_1 ( V_2 ) ) ;
}
F_8 ( V_2 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) )
return;
V_2 -> V_138 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
F_22 ( V_2 , 1 ) ;
}
static void F_68 ( unsigned long V_137 )
{
struct V_7 * V_8 = (struct V_7 * ) V_137 ;
struct V_1 * V_2 = V_8 -> V_10 ;
F_69 ( & V_8 -> V_12 ) ;
V_8 -> V_14 = 0 ;
if ( V_8 -> V_16 ) {
V_8 -> V_16 -- ;
F_15 ( V_8 , F_1 ( V_2 ) ) ;
}
V_8 -> V_15 = 1 ;
F_70 ( & V_8 -> V_12 ) ;
if ( F_2 ( V_2 ) )
F_63 ( V_2 , V_8 , V_141 ) ;
else if ( F_3 ( V_2 ) )
F_63 ( V_2 , V_8 , V_142 ) ;
else
F_63 ( V_2 , V_8 , V_88 ) ;
F_6 ( V_8 ) ;
}
static int F_71 ( struct V_7 * V_26 , int V_143 , T_1 * V_144 )
{
struct V_27 * V_28 ;
int V_145 , V_45 ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_143 )
break;
for ( V_145 = 0 ; V_145 < V_143 ; V_145 ++ ) {
if ( V_28 -> V_37 [ V_36 ] ||
V_26 -> V_38 [ V_39 ] !=
V_28 -> V_37 [ V_39 ] )
break;
if ( V_144 [ V_145 ] == V_28 -> V_122 ) {
V_45 ++ ;
break;
}
}
}
V_26 -> V_33 = 0 ;
if ( V_45 == V_143 )
return 0 ;
return 1 ;
}
static int F_72 ( struct V_7 * V_26 , int V_143 , T_1 * V_144 )
{
struct V_27 * V_28 ;
int V_145 , V_45 ;
if ( V_26 -> V_35 == V_39 )
return F_71 ( V_26 , V_143 , V_144 ) ;
V_45 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_45 == V_143 )
break;
for ( V_145 = 0 ; V_145 < V_143 ; V_145 ++ )
if ( V_144 [ V_145 ] == V_28 -> V_122 ) {
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
static bool F_73 ( struct V_1 * V_2 , T_1 V_132 )
{
struct V_7 * V_8 ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
if ( V_132 == V_114 )
return false ;
if ( F_54 ( V_132 ) && ! V_59 -> V_115 . V_116 )
return false ;
F_58 () ;
F_59 (in_dev, im) {
if ( V_8 -> V_106 == V_132 ) {
F_10 ( V_8 ) ;
break;
}
}
F_60 () ;
return false ;
}
static bool F_74 ( struct V_1 * V_2 , struct V_48 * V_52 ,
int V_146 )
{
struct V_93 * V_131 = F_44 ( V_52 ) ;
struct V_147 * V_148 = F_75 ( V_52 ) ;
struct V_7 * V_8 ;
T_1 V_132 = V_131 -> V_132 ;
int V_17 ;
int V_149 = 0 ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
if ( V_146 == 8 ) {
if ( V_131 -> V_136 == 0 ) {
V_17 = V_150 ;
V_2 -> V_151 = V_19 +
V_152 ;
V_132 = 0 ;
} else {
V_17 = V_131 -> V_136 * ( V_153 / V_154 ) ;
V_2 -> V_155 = V_19 +
V_156 ;
}
V_2 -> V_138 = 0 ;
if ( F_12 ( & V_2 -> V_25 ) )
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
} else if ( V_146 < 12 ) {
return true ;
} else if ( F_2 ( V_2 ) ) {
V_17 = V_150 ;
V_132 = 0 ;
} else if ( F_3 ( V_2 ) ) {
V_17 = F_78 ( V_148 -> V_136 ) * ( V_153 / V_154 ) ;
if ( ! V_17 )
V_17 = 1 ;
} else {
if ( ! F_79 ( V_52 , sizeof( struct V_147 ) ) )
return true ;
V_148 = F_75 ( V_52 ) ;
if ( V_148 -> V_143 ) {
if ( ! F_79 ( V_52 , sizeof( struct V_147 )
+ F_52 ( V_148 -> V_143 ) * sizeof( T_1 ) ) )
return true ;
V_148 = F_75 ( V_52 ) ;
}
V_17 = F_78 ( V_148 -> V_136 ) * ( V_153 / V_154 ) ;
if ( ! V_17 )
V_17 = 1 ;
V_2 -> V_20 = V_17 ;
if ( V_148 -> V_157 )
V_2 -> V_139 = V_148 -> V_157 ;
if ( ! V_132 ) {
if ( V_148 -> V_143 )
return true ;
F_19 ( V_2 ) ;
return false ;
}
V_149 = V_148 -> V_143 != 0 ;
}
F_58 () ;
F_59 (in_dev, im) {
int V_158 ;
if ( V_132 && V_132 != V_8 -> V_106 )
continue;
if ( V_8 -> V_106 == V_114 )
continue;
if ( F_54 ( V_8 -> V_106 ) &&
! V_59 -> V_115 . V_116 )
continue;
F_11 ( & V_8 -> V_12 ) ;
if ( V_8 -> V_14 )
V_8 -> V_33 = V_8 -> V_33 && V_149 ;
else
V_8 -> V_33 = V_149 ;
V_158 = ! V_8 -> V_33 ||
F_72 ( V_8 , F_52 ( V_148 -> V_143 ) , V_148 -> V_144 ) ;
F_14 ( & V_8 -> V_12 ) ;
if ( V_158 )
F_23 ( V_8 , V_17 ) ;
}
F_60 () ;
return false ;
}
int F_80 ( struct V_48 * V_52 )
{
struct V_93 * V_131 ;
struct V_1 * V_2 = F_81 ( V_52 -> V_50 ) ;
int V_146 = V_52 -> V_146 ;
bool V_159 = true ;
if ( ! V_2 )
goto V_160;
if ( ! F_79 ( V_52 , sizeof( struct V_93 ) ) )
goto V_160;
if ( F_82 ( V_52 ) )
goto V_160;
V_131 = F_44 ( V_52 ) ;
switch ( V_131 -> type ) {
case V_161 :
V_159 = F_74 ( V_2 , V_52 , V_146 ) ;
break;
case V_141 :
case V_142 :
if ( F_83 ( F_84 ( V_52 ) ) )
break;
if ( V_52 -> V_162 == V_163 ||
V_52 -> V_162 == V_164 )
V_159 = F_73 ( V_2 , V_131 -> V_132 ) ;
break;
case V_165 :
#ifdef F_85
return F_86 ( V_52 ) ;
#endif
case V_88 :
case V_166 :
case V_167 :
case V_133 :
case V_168 :
case V_169 :
break;
default:
break;
}
V_160:
if ( V_159 )
F_33 ( V_52 ) ;
else
F_87 ( V_52 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , T_1 V_170 )
{
char V_171 [ V_172 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_89 ( V_170 , V_171 , V_50 , 0 ) == 0 )
F_90 ( V_50 , V_171 ) ;
}
static void F_91 ( struct V_1 * V_2 , T_1 V_170 )
{
char V_171 [ V_172 ] ;
struct V_49 * V_50 = V_2 -> V_50 ;
if ( F_89 ( V_170 , V_171 , V_50 , 0 ) == 0 )
F_92 ( V_50 , V_171 ) ;
}
static void F_93 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
V_26 = F_94 ( sizeof( * V_26 ) , V_173 ) ;
if ( ! V_26 )
return;
F_95 ( & V_26 -> V_12 ) ;
F_11 ( & V_8 -> V_12 ) ;
V_26 -> V_10 = V_8 -> V_10 ;
F_21 ( V_2 ) ;
V_26 -> V_106 = V_8 -> V_106 ;
V_26 -> V_120 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
V_26 -> V_35 = V_8 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
struct V_27 * V_28 ;
V_26 -> V_117 = V_8 -> V_117 ;
V_26 -> V_46 = V_8 -> V_46 ;
V_8 -> V_117 = V_8 -> V_46 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_26 -> V_120 ;
}
F_14 ( & V_8 -> V_12 ) ;
F_11 ( & V_2 -> V_127 ) ;
V_26 -> V_129 = V_2 -> V_128 ;
V_2 -> V_128 = V_26 ;
F_14 ( & V_2 -> V_127 ) ;
}
static void F_96 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_7 * V_26 , * V_124 ;
struct V_27 * V_28 ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
T_1 V_106 = V_8 -> V_106 ;
F_11 ( & V_2 -> V_127 ) ;
V_124 = NULL ;
for ( V_26 = V_2 -> V_128 ; V_26 ; V_26 = V_26 -> V_129 ) {
if ( V_26 -> V_106 == V_106 )
break;
V_124 = V_26 ;
}
if ( V_26 ) {
if ( V_124 )
V_124 -> V_129 = V_26 -> V_129 ;
else
V_2 -> V_128 = V_26 -> V_129 ;
}
F_14 ( & V_2 -> V_127 ) ;
F_11 ( & V_8 -> V_12 ) ;
if ( V_26 ) {
V_8 -> V_10 = V_26 -> V_10 ;
V_8 -> V_120 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
V_8 -> V_35 = V_26 -> V_35 ;
if ( V_26 -> V_35 == V_36 ) {
V_8 -> V_117 = V_26 -> V_117 ;
V_8 -> V_46 = V_26 -> V_46 ;
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = V_8 -> V_120 ;
}
F_8 ( V_26 -> V_10 ) ;
F_56 ( V_26 ) ;
}
F_14 ( & V_8 -> V_12 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_26 , * V_174 ;
F_11 ( & V_2 -> V_127 ) ;
V_26 = V_2 -> V_128 ;
V_2 -> V_128 = NULL ;
F_14 ( & V_2 -> V_127 ) ;
for (; V_26 ; V_26 = V_174 ) {
V_174 = V_26 -> V_129 ;
F_97 ( V_26 ) ;
F_8 ( V_26 -> V_10 ) ;
F_56 ( V_26 ) ;
}
F_58 () ;
F_59 (in_dev, pmc) {
struct V_27 * V_28 , * V_107 ;
F_11 ( & V_26 -> V_12 ) ;
V_28 = V_26 -> V_117 ;
V_26 -> V_117 = NULL ;
F_14 ( & V_26 -> V_12 ) ;
for (; V_28 ; V_28 = V_107 ) {
V_107 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
}
F_60 () ;
}
static void F_98 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_99
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
int V_15 ;
#endif
if ( V_8 -> V_175 ) {
V_8 -> V_175 = 0 ;
F_91 ( V_2 , V_8 -> V_106 ) ;
}
#ifdef F_99
if ( V_8 -> V_106 == V_114 )
return;
if ( F_54 ( V_8 -> V_106 ) && ! V_59 -> V_115 . V_116 )
return;
V_15 = V_8 -> V_15 ;
F_10 ( V_8 ) ;
if ( ! V_2 -> V_176 ) {
if ( F_2 ( V_2 ) )
return;
if ( F_3 ( V_2 ) ) {
if ( V_15 )
F_63 ( V_2 , V_8 , V_133 ) ;
return;
}
F_93 ( V_2 , V_8 ) ;
F_67 ( V_2 ) ;
}
#endif
}
static void F_100 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_10 ;
#ifdef F_99
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
#endif
if ( V_8 -> V_175 == 0 ) {
V_8 -> V_175 = 1 ;
F_88 ( V_2 , V_8 -> V_106 ) ;
}
#ifdef F_99
if ( V_8 -> V_106 == V_114 )
return;
if ( F_54 ( V_8 -> V_106 ) && ! V_59 -> V_115 . V_116 )
return;
if ( V_2 -> V_176 )
return;
if ( F_2 ( V_2 ) || F_3 ( V_2 ) ) {
F_11 ( & V_8 -> V_12 ) ;
F_15 ( V_8 , V_177 ) ;
F_14 ( & V_8 -> V_12 ) ;
return;
}
V_8 -> V_120 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
F_67 ( V_2 ) ;
#endif
}
static T_2 F_101 ( const struct V_7 * V_8 )
{
return F_102 ( ( V_178 T_2 ) V_8 -> V_106 , V_179 ) ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_180 ;
T_2 V_181 ;
V_180 = F_104 ( V_2 -> V_180 ) ;
if ( V_180 ) {
V_181 = F_101 ( V_8 ) ;
V_8 -> V_182 = V_180 [ V_181 ] ;
F_105 ( V_180 [ V_181 ] , V_8 ) ;
return;
}
if ( V_2 -> V_183 < 4 )
return;
V_180 = F_94 ( sizeof( struct V_7 * ) << V_179 ,
V_173 ) ;
if ( ! V_180 )
return;
F_106 (in_dev, im) {
V_181 = F_101 ( V_8 ) ;
V_8 -> V_182 = V_180 [ V_181 ] ;
F_107 ( V_180 [ V_181 ] , V_8 ) ;
}
F_105 ( V_2 -> V_180 , V_180 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_7 T_3 * * V_180 = F_104 ( V_2 -> V_180 ) ;
struct V_7 * V_184 ;
if ( ! V_180 )
return;
V_180 += F_101 ( V_8 ) ;
while ( ( V_184 = F_104 ( * V_180 ) ) != V_8 )
V_180 = & V_184 -> V_182 ;
* V_180 = V_8 -> V_182 ;
}
void F_109 ( struct V_1 * V_2 , T_1 V_170 )
{
struct V_7 * V_8 ;
#ifdef F_99
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
#endif
F_110 () ;
F_106 (in_dev, im) {
if ( V_8 -> V_106 == V_170 ) {
V_8 -> V_185 ++ ;
F_111 ( V_2 , & V_170 , V_39 , 0 , NULL , 0 ) ;
goto V_186;
}
}
V_8 = F_94 ( sizeof( * V_8 ) , V_173 ) ;
if ( ! V_8 )
goto V_186;
V_8 -> V_185 = 1 ;
V_8 -> V_10 = V_2 ;
F_21 ( V_2 ) ;
V_8 -> V_106 = V_170 ;
V_8 -> V_35 = V_39 ;
V_8 -> V_38 [ V_39 ] = 1 ;
F_112 ( & V_8 -> V_9 , 1 ) ;
F_95 ( & V_8 -> V_12 ) ;
#ifdef F_99
F_113 ( & V_8 -> V_13 , F_68 , ( unsigned long ) V_8 ) ;
V_8 -> V_16 = V_59 -> V_115 . V_140 ;
#endif
V_8 -> V_187 = V_2 -> V_188 ;
V_2 -> V_183 ++ ;
F_105 ( V_2 -> V_188 , V_8 ) ;
F_103 ( V_2 , V_8 ) ;
#ifdef F_99
F_96 ( V_2 , V_8 ) ;
#endif
F_100 ( V_8 ) ;
if ( ! V_2 -> V_176 )
F_114 ( V_2 ) ;
V_186:
return;
}
static int F_115 ( struct V_48 * V_52 )
{
const struct V_55 * V_130 ;
unsigned int V_146 ;
unsigned int V_189 = F_116 ( V_52 ) + sizeof( * V_130 ) ;
if ( ! F_79 ( V_52 , V_189 ) )
return - V_190 ;
V_130 = F_38 ( V_52 ) ;
if ( V_130 -> V_74 != 4 || F_117 ( V_52 ) < sizeof( * V_130 ) )
return - V_190 ;
V_189 += F_117 ( V_52 ) - sizeof( * V_130 ) ;
if ( ! F_79 ( V_52 , V_189 ) )
return - V_190 ;
V_130 = F_38 ( V_52 ) ;
if ( F_118 ( F_119 ( ( V_84 * ) V_130 , V_130 -> V_75 ) ) )
return - V_190 ;
V_146 = F_116 ( V_52 ) + F_52 ( V_130 -> V_83 ) ;
if ( V_52 -> V_146 < V_146 || V_146 < V_189 )
return - V_190 ;
F_120 ( V_52 , V_189 ) ;
return 0 ;
}
static int F_121 ( struct V_48 * V_52 )
{
unsigned int V_146 = F_122 ( V_52 ) ;
V_146 += sizeof( struct V_57 ) ;
return F_79 ( V_52 , V_146 ) ? 0 : - V_190 ;
}
static int F_123 ( struct V_48 * V_52 )
{
unsigned int V_146 = F_122 ( V_52 ) ;
V_146 += sizeof( struct V_93 ) ;
if ( V_52 -> V_146 < V_146 )
return - V_190 ;
if ( V_52 -> V_146 != V_146 ) {
V_146 += sizeof( struct V_147 ) - sizeof( struct V_93 ) ;
if ( V_52 -> V_146 < V_146 || ! F_79 ( V_52 , V_146 ) )
return - V_190 ;
}
if ( ! F_44 ( V_52 ) -> V_132 &&
F_38 ( V_52 ) -> V_80 != F_124 ( V_191 ) )
return - V_190 ;
return 0 ;
}
static int F_125 ( struct V_48 * V_52 )
{
switch ( F_44 ( V_52 ) -> type ) {
case V_133 :
case V_141 :
case V_142 :
return 0 ;
case V_88 :
return F_121 ( V_52 ) ;
case V_161 :
return F_123 ( V_52 ) ;
default:
return - V_192 ;
}
}
static inline T_4 F_126 ( struct V_48 * V_52 )
{
return F_82 ( V_52 ) ;
}
static int F_127 ( struct V_48 * V_52 , struct V_48 * * V_193 )
{
struct V_48 * V_194 ;
unsigned int V_195 ;
unsigned int V_146 = F_122 ( V_52 ) + sizeof( struct V_93 ) ;
int V_196 = - V_190 ;
V_195 = F_52 ( F_38 ( V_52 ) -> V_83 ) - F_117 ( V_52 ) ;
V_194 = F_128 ( V_52 , V_195 ,
F_126 ) ;
if ( ! V_194 )
goto V_197;
if ( ! F_79 ( V_194 , V_146 ) )
goto V_197;
V_196 = F_125 ( V_194 ) ;
if ( V_196 )
goto V_197;
if ( V_193 )
* V_193 = V_194 ;
else if ( V_194 != V_52 )
F_33 ( V_194 ) ;
V_196 = 0 ;
V_197:
if ( V_196 && V_194 && V_194 != V_52 )
F_33 ( V_194 ) ;
return V_196 ;
}
int F_129 ( struct V_48 * V_52 , struct V_48 * * V_193 )
{
int V_196 = F_115 ( V_52 ) ;
if ( V_196 < 0 )
return V_196 ;
if ( F_38 ( V_52 ) -> V_82 != V_71 )
return - V_192 ;
return F_127 ( V_52 , V_193 ) ;
}
static void F_130 ( struct V_1 * V_2 )
{
#ifdef F_99
struct V_7 * V_8 ;
int type ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
F_110 () ;
F_106 (in_dev, im) {
if ( V_8 -> V_106 == V_114 )
continue;
if ( F_54 ( V_8 -> V_106 ) &&
! V_59 -> V_115 . V_116 )
continue;
if ( F_2 ( V_2 ) )
type = V_141 ;
else if ( F_3 ( V_2 ) )
type = V_142 ;
else
type = V_88 ;
F_63 ( V_2 , V_8 , type ) ;
}
#endif
}
void F_131 ( struct V_1 * V_2 , T_1 V_170 )
{
struct V_7 * V_145 ;
struct V_7 T_3 * * V_198 ;
F_110 () ;
for ( V_198 = & V_2 -> V_188 ;
( V_145 = F_104 ( * V_198 ) ) != NULL ;
V_198 = & V_145 -> V_187 ) {
if ( V_145 -> V_106 == V_170 ) {
if ( -- V_145 -> V_185 == 0 ) {
F_108 ( V_2 , V_145 ) ;
* V_198 = V_145 -> V_187 ;
V_2 -> V_183 -- ;
F_98 ( V_145 ) ;
F_97 ( V_145 ) ;
if ( ! V_2 -> V_176 )
F_114 ( V_2 ) ;
F_6 ( V_145 ) ;
return;
}
break;
}
}
}
void F_132 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_110 () ;
F_106 (in_dev, pmc)
F_98 ( V_26 ) ;
}
void F_133 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_110 () ;
F_106 (in_dev, pmc) {
#ifdef F_99
F_96 ( V_2 , V_26 ) ;
#endif
F_100 ( V_26 ) ;
}
}
void F_134 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
F_110 () ;
F_106 (in_dev, pmc)
F_98 ( V_26 ) ;
#ifdef F_99
V_2 -> V_138 = 0 ;
if ( F_12 ( & V_2 -> V_25 ) )
F_76 ( V_2 ) ;
V_2 -> V_21 = 0 ;
if ( F_12 ( & V_2 -> V_22 ) )
F_76 ( V_2 ) ;
#endif
F_131 ( V_2 , V_114 ) ;
}
void F_135 ( struct V_1 * V_2 )
{
#ifdef F_99
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
#endif
F_110 () ;
#ifdef F_99
F_113 ( & V_2 -> V_22 , F_65 ,
( unsigned long ) V_2 ) ;
F_113 ( & V_2 -> V_25 , F_66 ,
( unsigned long ) V_2 ) ;
V_2 -> V_139 = V_59 -> V_115 . V_140 ;
#endif
F_95 ( & V_2 -> V_127 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
struct V_7 * V_26 ;
#ifdef F_99
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
#endif
F_110 () ;
#ifdef F_99
V_2 -> V_139 = V_59 -> V_115 . V_140 ;
#endif
F_109 ( V_2 , V_114 ) ;
F_106 (in_dev, pmc) {
#ifdef F_99
F_96 ( V_2 , V_26 ) ;
#endif
F_100 ( V_26 ) ;
}
}
void F_137 ( struct V_1 * V_2 )
{
struct V_7 * V_145 ;
F_110 () ;
F_134 ( V_2 ) ;
#ifdef F_99
F_77 ( V_2 ) ;
#endif
while ( ( V_145 = F_104 ( V_2 -> V_188 ) ) != NULL ) {
V_2 -> V_188 = V_145 -> V_187 ;
V_2 -> V_183 -- ;
F_6 ( V_145 ) ;
}
}
static struct V_1 * F_138 ( struct V_59 * V_59 , struct V_199 * V_200 )
{
struct V_49 * V_50 = NULL ;
struct V_1 * V_201 = NULL ;
if ( V_200 -> V_202 ) {
V_201 = F_139 ( V_59 , V_200 -> V_202 ) ;
return V_201 ;
}
if ( V_200 -> V_203 . V_204 ) {
V_50 = F_140 ( V_59 , V_200 -> V_203 . V_204 , false ) ;
if ( ! V_50 )
return NULL ;
}
if ( ! V_50 ) {
struct V_53 * V_54 = F_141 ( V_59 ,
V_200 -> V_205 . V_204 ,
0 , 0 , 0 ) ;
if ( ! F_32 ( V_54 ) ) {
V_50 = V_54 -> V_73 . V_50 ;
F_64 ( V_54 ) ;
}
}
if ( V_50 ) {
V_200 -> V_202 = V_50 -> V_72 ;
V_201 = F_142 ( V_50 ) ;
}
return V_201 ;
}
static int F_143 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_206 )
{
struct V_27 * V_28 , * V_108 ;
int V_207 = 0 ;
V_108 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_122 == * V_206 )
break;
V_108 = V_28 ;
}
if ( ! V_28 || V_28 -> V_37 [ V_35 ] == 0 ) {
return - V_208 ;
}
V_28 -> V_37 [ V_35 ] -- ;
if ( V_28 -> V_37 [ V_35 ] == 0 ) {
F_114 ( V_26 -> V_10 ) ;
}
if ( ! V_28 -> V_37 [ V_36 ] && ! V_28 -> V_37 [ V_39 ] ) {
#ifdef F_99
struct V_1 * V_2 = V_26 -> V_10 ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
#endif
if ( V_108 )
V_108 -> V_47 = V_28 -> V_47 ;
else
V_26 -> V_46 = V_28 -> V_47 ;
#ifdef F_99
if ( V_28 -> V_209 &&
! F_2 ( V_2 ) && ! F_3 ( V_2 ) ) {
V_28 -> V_43 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
V_28 -> V_47 = V_26 -> V_117 ;
V_26 -> V_117 = V_28 ;
V_207 = 1 ;
} else
#endif
F_56 ( V_28 ) ;
}
return V_207 ;
}
static int F_144 ( struct V_1 * V_2 , T_1 * V_210 , int V_35 ,
int V_38 , T_1 * V_206 , int V_211 )
{
struct V_7 * V_26 ;
int V_212 = 0 ;
int V_145 , V_197 ;
if ( ! V_2 )
return - V_213 ;
F_58 () ;
F_59 (in_dev, pmc) {
if ( * V_210 == V_26 -> V_106 )
break;
}
if ( ! V_26 ) {
F_60 () ;
return - V_208 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_60 () ;
#ifdef F_99
F_145 ( V_26 ) ;
#endif
if ( ! V_211 ) {
V_197 = - V_190 ;
if ( ! V_26 -> V_38 [ V_35 ] )
goto V_214;
V_26 -> V_38 [ V_35 ] -- ;
}
V_197 = 0 ;
for ( V_145 = 0 ; V_145 < V_38 ; V_145 ++ ) {
int V_207 = F_143 ( V_26 , V_35 , & V_206 [ V_145 ] ) ;
V_212 |= V_207 > 0 ;
if ( ! V_197 && V_207 < 0 )
V_197 = V_207 ;
}
if ( V_26 -> V_35 == V_39 &&
V_26 -> V_38 [ V_39 ] == 0 &&
V_26 -> V_38 [ V_36 ] ) {
#ifdef F_99
struct V_27 * V_28 ;
struct V_59 * V_59 = F_28 ( V_2 -> V_50 ) ;
#endif
V_26 -> V_35 = V_36 ;
#ifdef F_99
V_26 -> V_120 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
V_2 -> V_138 = V_26 -> V_120 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_67 ( V_26 -> V_10 ) ;
} else if ( F_146 ( V_26 ) || V_212 ) {
F_67 ( V_26 -> V_10 ) ;
#endif
}
V_214:
F_14 ( & V_26 -> V_12 ) ;
return V_197 ;
}
static int F_147 ( struct V_7 * V_26 , int V_35 ,
T_1 * V_206 )
{
struct V_27 * V_28 , * V_108 ;
V_108 = NULL ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_122 == * V_206 )
break;
V_108 = V_28 ;
}
if ( ! V_28 ) {
V_28 = F_94 ( sizeof( * V_28 ) , V_66 ) ;
if ( ! V_28 )
return - V_215 ;
V_28 -> V_122 = * V_206 ;
if ( V_108 ) {
V_108 -> V_47 = V_28 ;
} else
V_26 -> V_46 = V_28 ;
}
V_28 -> V_37 [ V_35 ] ++ ;
if ( V_28 -> V_37 [ V_35 ] == 1 ) {
F_114 ( V_26 -> V_10 ) ;
}
return 0 ;
}
static void F_145 ( struct V_7 * V_26 )
{
struct V_27 * V_28 ;
int V_216 = V_26 -> V_38 [ V_39 ] ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
if ( V_26 -> V_38 [ V_39 ] ) {
V_28 -> V_209 = V_216 ==
V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_28 -> V_209 = V_28 -> V_37 [ V_36 ] != 0 ;
}
static int F_146 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_217 ;
int V_216 = V_26 -> V_38 [ V_39 ] ;
int V_157 = V_26 -> V_10 -> V_139 ;
int V_218 , V_207 ;
V_207 = 0 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_26 -> V_38 [ V_39 ] ) {
V_218 = V_216 == V_28 -> V_37 [ V_39 ] &&
! V_28 -> V_37 [ V_36 ] ;
} else
V_218 = V_28 -> V_37 [ V_36 ] != 0 ;
if ( V_218 ) {
if ( ! V_28 -> V_209 ) {
struct V_27 * V_219 = NULL ;
for ( V_217 = V_26 -> V_117 ; V_217 ; V_217 = V_217 -> V_47 ) {
if ( V_217 -> V_122 == V_28 -> V_122 )
break;
V_219 = V_217 ;
}
if ( V_217 ) {
if ( V_219 )
V_219 -> V_47 = V_217 -> V_47 ;
else
V_26 -> V_117 = V_217 -> V_47 ;
F_56 ( V_217 ) ;
}
V_28 -> V_43 = V_157 ;
V_207 ++ ;
}
} else if ( V_28 -> V_209 ) {
V_28 -> V_43 = 0 ;
for ( V_217 = V_26 -> V_117 ; V_217 ; V_217 = V_217 -> V_47 )
if ( V_217 -> V_122 == V_28 -> V_122 )
break;
if ( ! V_217 ) {
V_217 = F_148 ( sizeof( * V_217 ) , V_66 ) ;
if ( ! V_217 )
continue;
* V_217 = * V_28 ;
V_217 -> V_47 = V_26 -> V_117 ;
V_26 -> V_117 = V_217 ;
}
V_217 -> V_43 = V_157 ;
V_207 ++ ;
}
}
return V_207 ;
}
static int F_111 ( struct V_1 * V_2 , T_1 * V_210 , int V_35 ,
int V_38 , T_1 * V_206 , int V_211 )
{
struct V_7 * V_26 ;
int V_220 ;
int V_145 , V_197 ;
if ( ! V_2 )
return - V_213 ;
F_58 () ;
F_59 (in_dev, pmc) {
if ( * V_210 == V_26 -> V_106 )
break;
}
if ( ! V_26 ) {
F_60 () ;
return - V_208 ;
}
F_11 ( & V_26 -> V_12 ) ;
F_60 () ;
#ifdef F_99
F_145 ( V_26 ) ;
#endif
V_220 = V_26 -> V_35 == V_39 ;
if ( ! V_211 )
V_26 -> V_38 [ V_35 ] ++ ;
V_197 = 0 ;
for ( V_145 = 0 ; V_145 < V_38 ; V_145 ++ ) {
V_197 = F_147 ( V_26 , V_35 , & V_206 [ V_145 ] ) ;
if ( V_197 )
break;
}
if ( V_197 ) {
int V_221 ;
if ( ! V_211 )
V_26 -> V_38 [ V_35 ] -- ;
for ( V_221 = 0 ; V_221 < V_145 ; V_221 ++ )
( void ) F_143 ( V_26 , V_35 , & V_206 [ V_221 ] ) ;
} else if ( V_220 != ( V_26 -> V_38 [ V_39 ] != 0 ) ) {
#ifdef F_99
struct V_27 * V_28 ;
struct V_59 * V_59 = F_28 ( V_26 -> V_10 -> V_50 ) ;
V_2 = V_26 -> V_10 ;
#endif
if ( V_26 -> V_38 [ V_39 ] )
V_26 -> V_35 = V_39 ;
else if ( V_26 -> V_38 [ V_36 ] )
V_26 -> V_35 = V_36 ;
#ifdef F_99
V_26 -> V_120 = V_2 -> V_139 ? : V_59 -> V_115 . V_140 ;
V_2 -> V_138 = V_26 -> V_120 ;
for ( V_28 = V_26 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 )
V_28 -> V_43 = 0 ;
F_67 ( V_2 ) ;
} else if ( F_146 ( V_26 ) ) {
F_67 ( V_2 ) ;
#endif
}
F_14 ( & V_26 -> V_12 ) ;
return V_197 ;
}
static void F_97 ( struct V_7 * V_26 )
{
struct V_27 * V_28 , * V_222 , * V_117 , * V_46 ;
F_11 ( & V_26 -> V_12 ) ;
V_117 = V_26 -> V_117 ;
V_26 -> V_117 = NULL ;
V_46 = V_26 -> V_46 ;
V_26 -> V_46 = NULL ;
V_26 -> V_35 = V_39 ;
V_26 -> V_38 [ V_36 ] = 0 ;
V_26 -> V_38 [ V_39 ] = 1 ;
F_14 ( & V_26 -> V_12 ) ;
for ( V_28 = V_117 ; V_28 ; V_28 = V_222 ) {
V_222 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
for ( V_28 = V_46 ; V_28 ; V_28 = V_222 ) {
V_222 = V_28 -> V_47 ;
F_56 ( V_28 ) ;
}
}
int F_149 ( struct V_223 * V_95 , struct V_199 * V_200 )
{
T_1 V_170 = V_200 -> V_205 . V_204 ;
struct V_224 * V_225 , * V_145 ;
struct V_1 * V_2 ;
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_59 * V_59 = F_151 ( V_95 ) ;
int V_72 ;
int V_228 = 0 ;
int V_197 ;
F_110 () ;
if ( ! F_152 ( V_170 ) )
return - V_190 ;
V_2 = F_138 ( V_59 , V_200 ) ;
if ( ! V_2 ) {
V_197 = - V_213 ;
goto V_229;
}
V_197 = - V_230 ;
V_72 = V_200 -> V_202 ;
F_106 (inet, i) {
if ( V_145 -> V_231 . V_205 . V_204 == V_170 &&
V_145 -> V_231 . V_202 == V_72 )
goto V_229;
V_228 ++ ;
}
V_197 = - V_215 ;
if ( V_228 >= V_59 -> V_115 . V_232 )
goto V_229;
V_225 = F_153 ( V_95 , sizeof( * V_225 ) , V_173 ) ;
if ( ! V_225 )
goto V_229;
memcpy ( & V_225 -> V_231 , V_200 , sizeof( * V_200 ) ) ;
V_225 -> V_187 = V_227 -> V_188 ;
V_225 -> V_233 = NULL ;
V_225 -> V_35 = V_39 ;
F_105 ( V_227 -> V_188 , V_225 ) ;
F_109 ( V_2 , V_170 ) ;
V_197 = 0 ;
V_229:
return V_197 ;
}
static int F_154 ( struct V_223 * V_95 , struct V_224 * V_225 ,
struct V_1 * V_2 )
{
struct V_234 * V_28 = F_104 ( V_225 -> V_233 ) ;
int V_197 ;
if ( ! V_28 ) {
return F_144 ( V_2 , & V_225 -> V_231 . V_205 . V_204 ,
V_225 -> V_35 , 0 , NULL , 0 ) ;
}
V_197 = F_144 ( V_2 , & V_225 -> V_231 . V_205 . V_204 ,
V_225 -> V_35 , V_28 -> V_235 , V_28 -> V_236 , 0 ) ;
F_107 ( V_225 -> V_233 , NULL ) ;
F_155 ( F_156 ( V_28 -> V_237 ) , & V_95 -> V_238 ) ;
F_9 ( V_28 , V_11 ) ;
return V_197 ;
}
int F_157 ( struct V_223 * V_95 , struct V_199 * V_200 )
{
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_224 * V_225 ;
struct V_224 T_3 * * V_239 ;
struct V_1 * V_2 ;
struct V_59 * V_59 = F_151 ( V_95 ) ;
T_1 V_132 = V_200 -> V_205 . V_204 ;
T_2 V_72 ;
int V_196 = - V_240 ;
F_110 () ;
V_2 = F_138 ( V_59 , V_200 ) ;
if ( ! V_200 -> V_202 && ! V_200 -> V_203 . V_204 && ! V_2 ) {
V_196 = - V_213 ;
goto V_186;
}
V_72 = V_200 -> V_202 ;
for ( V_239 = & V_227 -> V_188 ;
( V_225 = F_104 ( * V_239 ) ) != NULL ;
V_239 = & V_225 -> V_187 ) {
if ( V_225 -> V_231 . V_205 . V_204 != V_132 )
continue;
if ( V_72 ) {
if ( V_225 -> V_231 . V_202 != V_72 )
continue;
} else if ( V_200 -> V_203 . V_204 && V_200 -> V_203 . V_204 !=
V_225 -> V_231 . V_203 . V_204 )
continue;
( void ) F_154 ( V_95 , V_225 , V_2 ) ;
* V_239 = V_225 -> V_187 ;
if ( V_2 )
F_131 ( V_2 , V_132 ) ;
F_155 ( sizeof( * V_225 ) , & V_95 -> V_238 ) ;
F_9 ( V_225 , V_11 ) ;
return 0 ;
}
V_186:
return V_196 ;
}
int F_158 ( int V_241 , int V_242 , struct V_223 * V_95 , struct
V_243 * V_244 , int V_72 )
{
int V_197 ;
struct V_199 V_200 ;
T_1 V_170 = V_244 -> V_205 ;
struct V_224 * V_26 ;
struct V_1 * V_2 = NULL ;
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_234 * V_245 ;
struct V_59 * V_59 = F_151 ( V_95 ) ;
int V_246 = 0 ;
int V_145 , V_221 , V_207 ;
if ( ! F_152 ( V_170 ) )
return - V_190 ;
F_110 () ;
V_200 . V_205 . V_204 = V_244 -> V_205 ;
V_200 . V_203 . V_204 = V_244 -> V_247 ;
V_200 . V_202 = V_72 ;
V_2 = F_138 ( V_59 , & V_200 ) ;
if ( ! V_2 ) {
V_197 = - V_213 ;
goto V_229;
}
V_197 = - V_240 ;
F_106 (inet, pmc) {
if ( ( V_26 -> V_231 . V_205 . V_204 ==
V_200 . V_205 . V_204 ) &&
( V_26 -> V_231 . V_202 == V_200 . V_202 ) )
break;
}
if ( ! V_26 ) {
V_197 = - V_190 ;
goto V_229;
}
if ( V_26 -> V_233 ) {
if ( V_26 -> V_35 != V_242 ) {
V_197 = - V_190 ;
goto V_229;
}
} else if ( V_26 -> V_35 != V_242 ) {
F_111 ( V_2 , & V_244 -> V_205 , V_242 , 0 , NULL , 0 ) ;
F_144 ( V_2 , & V_244 -> V_205 , V_26 -> V_35 , 0 ,
NULL , 0 ) ;
V_26 -> V_35 = V_242 ;
}
V_245 = F_104 ( V_26 -> V_233 ) ;
if ( ! V_241 ) {
if ( ! V_245 )
goto V_229;
V_207 = ! 0 ;
for ( V_145 = 0 ; V_145 < V_245 -> V_235 ; V_145 ++ ) {
V_207 = memcmp ( & V_245 -> V_236 [ V_145 ] , & V_244 -> V_248 ,
sizeof( T_1 ) ) ;
if ( V_207 == 0 )
break;
}
if ( V_207 )
goto V_229;
if ( V_245 -> V_235 == 1 && V_242 == V_36 ) {
V_246 = 1 ;
goto V_229;
}
F_144 ( V_2 , & V_244 -> V_205 , V_242 , 1 ,
& V_244 -> V_248 , 1 ) ;
for ( V_221 = V_145 + 1 ; V_221 < V_245 -> V_235 ; V_221 ++ )
V_245 -> V_236 [ V_221 - 1 ] = V_245 -> V_236 [ V_221 ] ;
V_245 -> V_235 -- ;
V_197 = 0 ;
goto V_229;
}
if ( V_245 && V_245 -> V_235 >= V_59 -> V_115 . V_249 ) {
V_197 = - V_215 ;
goto V_229;
}
if ( ! V_245 || V_245 -> V_235 == V_245 -> V_237 ) {
struct V_234 * V_250 ;
int V_228 = V_251 ;
if ( V_245 )
V_228 += V_245 -> V_237 ;
V_250 = F_153 ( V_95 , F_156 ( V_228 ) , V_173 ) ;
if ( ! V_250 ) {
V_197 = - V_215 ;
goto V_229;
}
V_250 -> V_237 = V_228 ;
V_250 -> V_235 = V_228 - V_251 ;
if ( V_245 ) {
for ( V_145 = 0 ; V_145 < V_245 -> V_235 ; V_145 ++ )
V_250 -> V_236 [ V_145 ] = V_245 -> V_236 [ V_145 ] ;
F_155 ( F_156 ( V_245 -> V_237 ) , & V_95 -> V_238 ) ;
F_9 ( V_245 , V_11 ) ;
}
F_105 ( V_26 -> V_233 , V_250 ) ;
V_245 = V_250 ;
}
V_207 = 1 ;
for ( V_145 = 0 ; V_145 < V_245 -> V_235 ; V_145 ++ ) {
V_207 = memcmp ( & V_245 -> V_236 [ V_145 ] , & V_244 -> V_248 ,
sizeof( T_1 ) ) ;
if ( V_207 == 0 )
break;
}
if ( V_207 == 0 )
goto V_229;
for ( V_221 = V_245 -> V_235 - 1 ; V_221 >= V_145 ; V_221 -- )
V_245 -> V_236 [ V_221 + 1 ] = V_245 -> V_236 [ V_221 ] ;
V_245 -> V_236 [ V_145 ] = V_244 -> V_248 ;
V_245 -> V_235 ++ ;
V_197 = 0 ;
F_111 ( V_2 , & V_244 -> V_205 , V_242 , 1 ,
& V_244 -> V_248 , 1 ) ;
V_229:
if ( V_246 )
V_197 = F_157 ( V_95 , & V_200 ) ;
return V_197 ;
}
int F_159 ( struct V_223 * V_95 , struct V_252 * V_253 , int V_72 )
{
int V_197 = 0 ;
struct V_199 V_200 ;
T_1 V_170 = V_253 -> V_254 ;
struct V_224 * V_26 ;
struct V_1 * V_2 ;
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_234 * V_250 , * V_245 ;
struct V_59 * V_59 = F_151 ( V_95 ) ;
int V_246 = 0 ;
if ( ! F_152 ( V_170 ) )
return - V_190 ;
if ( V_253 -> V_255 != V_36 &&
V_253 -> V_255 != V_39 )
return - V_190 ;
F_110 () ;
V_200 . V_205 . V_204 = V_253 -> V_254 ;
V_200 . V_203 . V_204 = V_253 -> V_256 ;
V_200 . V_202 = V_72 ;
V_2 = F_138 ( V_59 , & V_200 ) ;
if ( ! V_2 ) {
V_197 = - V_213 ;
goto V_229;
}
if ( V_253 -> V_255 == V_36 && V_253 -> V_257 == 0 ) {
V_246 = 1 ;
goto V_229;
}
F_106 (inet, pmc) {
if ( V_26 -> V_231 . V_205 . V_204 == V_253 -> V_254 &&
V_26 -> V_231 . V_202 == V_200 . V_202 )
break;
}
if ( ! V_26 ) {
V_197 = - V_190 ;
goto V_229;
}
if ( V_253 -> V_257 ) {
V_250 = F_153 ( V_95 , F_156 ( V_253 -> V_257 ) ,
V_173 ) ;
if ( ! V_250 ) {
V_197 = - V_215 ;
goto V_229;
}
V_250 -> V_237 = V_250 -> V_235 = V_253 -> V_257 ;
memcpy ( V_250 -> V_236 , V_253 -> V_258 ,
V_253 -> V_257 * sizeof( V_253 -> V_258 [ 0 ] ) ) ;
V_197 = F_111 ( V_2 , & V_253 -> V_254 ,
V_253 -> V_255 , V_250 -> V_235 , V_250 -> V_236 , 0 ) ;
if ( V_197 ) {
F_160 ( V_95 , V_250 , F_156 ( V_250 -> V_237 ) ) ;
goto V_229;
}
} else {
V_250 = NULL ;
( void ) F_111 ( V_2 , & V_253 -> V_254 ,
V_253 -> V_255 , 0 , NULL , 0 ) ;
}
V_245 = F_104 ( V_26 -> V_233 ) ;
if ( V_245 ) {
( void ) F_144 ( V_2 , & V_253 -> V_254 , V_26 -> V_35 ,
V_245 -> V_235 , V_245 -> V_236 , 0 ) ;
F_155 ( F_156 ( V_245 -> V_237 ) , & V_95 -> V_238 ) ;
F_9 ( V_245 , V_11 ) ;
} else
( void ) F_144 ( V_2 , & V_253 -> V_254 , V_26 -> V_35 ,
0 , NULL , 0 ) ;
F_105 ( V_26 -> V_233 , V_250 ) ;
V_26 -> V_35 = V_253 -> V_255 ;
V_197 = 0 ;
V_229:
if ( V_246 )
V_197 = F_157 ( V_95 , & V_200 ) ;
return V_197 ;
}
int F_161 ( struct V_223 * V_95 , struct V_252 * V_253 ,
struct V_252 T_5 * V_259 , int T_5 * V_260 )
{
int V_197 , V_146 , V_228 , V_261 ;
struct V_199 V_200 ;
T_1 V_170 = V_253 -> V_254 ;
struct V_224 * V_26 ;
struct V_1 * V_2 ;
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_234 * V_245 ;
struct V_59 * V_59 = F_151 ( V_95 ) ;
F_110 () ;
if ( ! F_152 ( V_170 ) )
return - V_190 ;
V_200 . V_205 . V_204 = V_253 -> V_254 ;
V_200 . V_203 . V_204 = V_253 -> V_256 ;
V_200 . V_202 = 0 ;
V_2 = F_138 ( V_59 , & V_200 ) ;
if ( ! V_2 ) {
V_197 = - V_213 ;
goto V_229;
}
V_197 = - V_240 ;
F_106 (inet, pmc) {
if ( V_26 -> V_231 . V_205 . V_204 == V_253 -> V_254 &&
V_26 -> V_231 . V_202 == V_200 . V_202 )
break;
}
if ( ! V_26 )
goto V_229;
V_253 -> V_255 = V_26 -> V_35 ;
V_245 = F_104 ( V_26 -> V_233 ) ;
if ( ! V_245 ) {
V_146 = 0 ;
V_228 = 0 ;
} else {
V_228 = V_245 -> V_235 ;
}
V_261 = V_228 < V_253 -> V_257 ? V_228 : V_253 -> V_257 ;
V_146 = V_261 * sizeof( V_245 -> V_236 [ 0 ] ) ;
V_253 -> V_257 = V_228 ;
if ( F_162 ( F_163 ( V_261 ) , V_260 ) ||
F_164 ( V_259 , V_253 , F_163 ( 0 ) ) ) {
return - V_262 ;
}
if ( V_146 &&
F_164 ( & V_259 -> V_258 [ 0 ] , V_245 -> V_236 , V_146 ) )
return - V_262 ;
return 0 ;
V_229:
return V_197 ;
}
int F_165 ( struct V_223 * V_95 , struct V_263 * V_264 ,
struct V_263 T_5 * V_259 , int T_5 * V_260 )
{
int V_197 , V_145 , V_228 , V_261 ;
struct V_265 * V_266 ;
T_1 V_170 ;
struct V_224 * V_26 ;
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_234 * V_245 ;
F_110 () ;
V_266 = (struct V_265 * ) & V_264 -> V_267 ;
if ( V_266 -> V_268 != V_269 )
return - V_190 ;
V_170 = V_266 -> V_270 . V_204 ;
if ( ! F_152 ( V_170 ) )
return - V_190 ;
V_197 = - V_240 ;
F_106 (inet, pmc) {
if ( V_26 -> V_231 . V_205 . V_204 == V_170 &&
V_26 -> V_231 . V_202 == V_264 -> V_271 )
break;
}
if ( ! V_26 )
goto V_229;
V_264 -> V_272 = V_26 -> V_35 ;
V_245 = F_104 ( V_26 -> V_233 ) ;
V_228 = V_245 ? V_245 -> V_235 : 0 ;
V_261 = V_228 < V_264 -> V_273 ? V_228 : V_264 -> V_273 ;
V_264 -> V_273 = V_228 ;
if ( F_162 ( F_166 ( V_261 ) , V_260 ) ||
F_164 ( V_259 , V_264 , F_166 ( 0 ) ) ) {
return - V_262 ;
}
for ( V_145 = 0 ; V_145 < V_261 ; V_145 ++ ) {
struct V_274 V_275 ;
V_266 = (struct V_265 * ) & V_275 ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_266 -> V_268 = V_269 ;
V_266 -> V_270 . V_204 = V_245 -> V_236 [ V_145 ] ;
if ( F_164 ( & V_259 -> V_276 [ V_145 ] , & V_275 , sizeof( V_275 ) ) )
return - V_262 ;
}
return 0 ;
V_229:
return V_197 ;
}
int F_167 ( struct V_223 * V_95 , T_1 V_277 , T_1 V_278 , int V_279 )
{
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_224 * V_26 ;
struct V_234 * V_245 ;
int V_145 ;
int V_196 ;
V_196 = 1 ;
if ( ! F_152 ( V_277 ) )
goto V_186;
F_58 () ;
F_59 (inet, pmc) {
if ( V_26 -> V_231 . V_205 . V_204 == V_277 &&
V_26 -> V_231 . V_202 == V_279 )
break;
}
V_196 = V_227 -> V_280 ;
if ( ! V_26 )
goto V_281;
V_245 = F_168 ( V_26 -> V_233 ) ;
V_196 = ( V_26 -> V_35 == V_39 ) ;
if ( ! V_245 )
goto V_281;
for ( V_145 = 0 ; V_145 < V_245 -> V_235 ; V_145 ++ ) {
if ( V_245 -> V_236 [ V_145 ] == V_278 )
break;
}
V_196 = 0 ;
if ( V_26 -> V_35 == V_36 && V_145 >= V_245 -> V_235 )
goto V_281;
if ( V_26 -> V_35 == V_39 && V_145 < V_245 -> V_235 )
goto V_281;
V_196 = 1 ;
V_281:
F_60 () ;
V_186:
return V_196 ;
}
void F_169 ( struct V_223 * V_95 )
{
struct V_226 * V_227 = F_150 ( V_95 ) ;
struct V_224 * V_225 ;
struct V_59 * V_59 = F_151 ( V_95 ) ;
if ( ! V_227 -> V_188 )
return;
F_170 () ;
while ( ( V_225 = F_104 ( V_227 -> V_188 ) ) != NULL ) {
struct V_1 * V_2 ;
V_227 -> V_188 = V_225 -> V_187 ;
V_2 = F_139 ( V_59 , V_225 -> V_231 . V_202 ) ;
( void ) F_154 ( V_95 , V_225 , V_2 ) ;
if ( V_2 )
F_131 ( V_2 , V_225 -> V_231 . V_205 . V_204 ) ;
F_155 ( sizeof( * V_225 ) , & V_95 -> V_238 ) ;
F_9 ( V_225 , V_11 ) ;
}
F_171 () ;
}
int F_172 ( struct V_1 * V_2 , T_1 V_282 , T_1 V_283 , V_84 V_284 )
{
struct V_7 * V_8 ;
struct V_7 T_3 * * V_180 ;
struct V_27 * V_28 ;
int V_207 = 0 ;
V_180 = F_168 ( V_2 -> V_180 ) ;
if ( V_180 ) {
T_2 V_181 = F_102 ( ( V_178 T_2 ) V_282 , V_179 ) ;
for ( V_8 = F_168 ( V_180 [ V_181 ] ) ;
V_8 != NULL ;
V_8 = F_168 ( V_8 -> V_182 ) ) {
if ( V_8 -> V_106 == V_282 )
break;
}
} else {
F_59 (in_dev, im) {
if ( V_8 -> V_106 == V_282 )
break;
}
}
if ( V_8 && V_284 == V_71 ) {
V_207 = 1 ;
} else if ( V_8 ) {
if ( V_283 ) {
for ( V_28 = V_8 -> V_46 ; V_28 ; V_28 = V_28 -> V_47 ) {
if ( V_28 -> V_122 == V_283 )
break;
}
if ( V_28 )
V_207 = V_28 -> V_37 [ V_36 ] ||
V_28 -> V_37 [ V_39 ] !=
V_8 -> V_38 [ V_39 ] ;
else
V_207 = V_8 -> V_38 [ V_39 ] != 0 ;
} else
V_207 = 1 ;
}
return V_207 ;
}
static inline struct V_7 * F_173 ( struct V_285 * V_286 )
{
struct V_59 * V_59 = F_174 ( V_286 ) ;
struct V_7 * V_8 = NULL ;
struct V_287 * V_288 = F_175 ( V_286 ) ;
V_288 -> V_2 = NULL ;
F_176 (net, state->dev) {
struct V_1 * V_2 ;
V_2 = F_81 ( V_288 -> V_50 ) ;
if ( ! V_2 )
continue;
V_8 = F_168 ( V_2 -> V_188 ) ;
if ( V_8 ) {
V_288 -> V_2 = V_2 ;
break;
}
}
return V_8 ;
}
static struct V_7 * F_177 ( struct V_285 * V_286 , struct V_7 * V_8 )
{
struct V_287 * V_288 = F_175 ( V_286 ) ;
V_8 = F_168 ( V_8 -> V_187 ) ;
while ( ! V_8 ) {
V_288 -> V_50 = F_178 ( V_288 -> V_50 ) ;
if ( ! V_288 -> V_50 ) {
V_288 -> V_2 = NULL ;
break;
}
V_288 -> V_2 = F_81 ( V_288 -> V_50 ) ;
if ( ! V_288 -> V_2 )
continue;
V_8 = F_168 ( V_288 -> V_2 -> V_188 ) ;
}
return V_8 ;
}
static struct V_7 * F_179 ( struct V_285 * V_286 , T_6 V_289 )
{
struct V_7 * V_8 = F_173 ( V_286 ) ;
if ( V_8 )
while ( V_289 && ( V_8 = F_177 ( V_286 , V_8 ) ) != NULL )
-- V_289 ;
return V_289 ? NULL : V_8 ;
}
static void * F_180 ( struct V_285 * V_286 , T_6 * V_289 )
__acquires( V_11 )
{
F_58 () ;
return * V_289 ? F_179 ( V_286 , * V_289 - 1 ) : V_290 ;
}
static void * F_181 ( struct V_285 * V_286 , void * V_291 , T_6 * V_289 )
{
struct V_7 * V_8 ;
if ( V_291 == V_290 )
V_8 = F_173 ( V_286 ) ;
else
V_8 = F_177 ( V_286 , V_291 ) ;
++ * V_289 ;
return V_8 ;
}
static void F_182 ( struct V_285 * V_286 , void * V_291 )
__releases( V_11 )
{
struct V_287 * V_288 = F_175 ( V_286 ) ;
V_288 -> V_2 = NULL ;
V_288 -> V_50 = NULL ;
F_60 () ;
}
static int F_183 ( struct V_285 * V_286 , void * V_291 )
{
if ( V_291 == V_290 )
F_184 ( V_286 ,
L_1 ) ;
else {
struct V_7 * V_8 = (struct V_7 * ) V_291 ;
struct V_287 * V_288 = F_175 ( V_286 ) ;
char * V_292 ;
long V_211 ;
#ifdef F_99
V_292 = F_2 ( V_288 -> V_2 ) ? L_2 :
F_3 ( V_288 -> V_2 ) ? L_3 :
L_4 ;
#else
V_292 = L_5 ;
#endif
if ( F_185 ( V_288 -> V_2 -> V_188 ) == V_8 ) {
F_186 ( V_286 , L_6 ,
V_288 -> V_50 -> V_72 , V_288 -> V_50 -> V_293 , V_288 -> V_2 -> V_183 , V_292 ) ;
}
V_211 = V_8 -> V_13 . V_23 - V_19 ;
F_186 ( V_286 ,
L_7 ,
V_8 -> V_106 , V_8 -> V_185 ,
V_8 -> V_14 ,
V_8 -> V_14 ? F_187 ( V_211 ) : 0 ,
V_8 -> V_15 ) ;
}
return 0 ;
}
static int F_188 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_189 ( V_294 , V_295 , & V_296 ,
sizeof( struct V_287 ) ) ;
}
static inline struct V_27 * F_190 ( struct V_285 * V_286 )
{
struct V_59 * V_59 = F_174 ( V_286 ) ;
struct V_27 * V_28 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_297 * V_288 = F_191 ( V_286 ) ;
V_288 -> V_201 = NULL ;
V_288 -> V_8 = NULL ;
F_176 (net, state->dev) {
struct V_1 * V_201 ;
V_201 = F_81 ( V_288 -> V_50 ) ;
if ( F_118 ( ! V_201 ) )
continue;
V_8 = F_168 ( V_201 -> V_188 ) ;
if ( F_192 ( V_8 ) ) {
F_11 ( & V_8 -> V_12 ) ;
V_28 = V_8 -> V_46 ;
if ( F_192 ( V_28 ) ) {
V_288 -> V_8 = V_8 ;
V_288 -> V_201 = V_201 ;
break;
}
F_14 ( & V_8 -> V_12 ) ;
}
}
return V_28 ;
}
static struct V_27 * F_193 ( struct V_285 * V_286 , struct V_27 * V_28 )
{
struct V_297 * V_288 = F_191 ( V_286 ) ;
V_28 = V_28 -> V_47 ;
while ( ! V_28 ) {
F_14 ( & V_288 -> V_8 -> V_12 ) ;
V_288 -> V_8 = V_288 -> V_8 -> V_129 ;
while ( ! V_288 -> V_8 ) {
V_288 -> V_50 = F_178 ( V_288 -> V_50 ) ;
if ( ! V_288 -> V_50 ) {
V_288 -> V_201 = NULL ;
goto V_186;
}
V_288 -> V_201 = F_81 ( V_288 -> V_50 ) ;
if ( ! V_288 -> V_201 )
continue;
V_288 -> V_8 = F_168 ( V_288 -> V_201 -> V_188 ) ;
}
if ( ! V_288 -> V_8 )
break;
F_11 ( & V_288 -> V_8 -> V_12 ) ;
V_28 = V_288 -> V_8 -> V_46 ;
}
V_186:
return V_28 ;
}
static struct V_27 * F_194 ( struct V_285 * V_286 , T_6 V_289 )
{
struct V_27 * V_28 = F_190 ( V_286 ) ;
if ( V_28 )
while ( V_289 && ( V_28 = F_193 ( V_286 , V_28 ) ) != NULL )
-- V_289 ;
return V_289 ? NULL : V_28 ;
}
static void * F_195 ( struct V_285 * V_286 , T_6 * V_289 )
__acquires( V_11 )
{
F_58 () ;
return * V_289 ? F_194 ( V_286 , * V_289 - 1 ) : V_290 ;
}
static void * F_196 ( struct V_285 * V_286 , void * V_291 , T_6 * V_289 )
{
struct V_27 * V_28 ;
if ( V_291 == V_290 )
V_28 = F_190 ( V_286 ) ;
else
V_28 = F_193 ( V_286 , V_291 ) ;
++ * V_289 ;
return V_28 ;
}
static void F_197 ( struct V_285 * V_286 , void * V_291 )
__releases( V_11 )
{
struct V_297 * V_288 = F_191 ( V_286 ) ;
if ( F_192 ( V_288 -> V_8 ) ) {
F_14 ( & V_288 -> V_8 -> V_12 ) ;
V_288 -> V_8 = NULL ;
}
V_288 -> V_201 = NULL ;
V_288 -> V_50 = NULL ;
F_60 () ;
}
static int F_198 ( struct V_285 * V_286 , void * V_291 )
{
struct V_27 * V_28 = (struct V_27 * ) V_291 ;
struct V_297 * V_288 = F_191 ( V_286 ) ;
if ( V_291 == V_290 ) {
F_184 ( V_286 , L_8 ) ;
} else {
F_186 ( V_286 ,
L_9
L_10 ,
V_288 -> V_50 -> V_72 , V_288 -> V_50 -> V_293 ,
F_199 ( V_288 -> V_8 -> V_106 ) ,
F_199 ( V_28 -> V_122 ) ,
V_28 -> V_37 [ V_36 ] ,
V_28 -> V_37 [ V_39 ] ) ;
}
return 0 ;
}
static int F_200 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
return F_189 ( V_294 , V_295 , & V_298 ,
sizeof( struct V_297 ) ) ;
}
static int T_7 F_201 ( struct V_59 * V_59 )
{
struct V_299 * V_300 ;
int V_197 ;
V_300 = F_202 ( L_11 , V_301 , V_59 -> V_302 , & V_303 ) ;
if ( ! V_300 )
goto V_304;
V_300 = F_202 ( L_12 , V_301 , V_59 -> V_302 ,
& V_305 ) ;
if ( ! V_300 )
goto V_306;
V_197 = F_203 ( & V_59 -> V_115 . V_307 , V_269 ,
V_308 , 0 , V_59 ) ;
if ( V_197 < 0 ) {
F_204 ( L_13 ,
V_197 ) ;
goto V_309;
}
V_59 -> V_115 . V_232 = 20 ;
V_59 -> V_115 . V_249 = 10 ;
V_59 -> V_115 . V_116 = 1 ;
V_59 -> V_115 . V_140 = 2 ;
return 0 ;
V_309:
F_205 ( L_12 , V_59 -> V_302 ) ;
V_306:
F_205 ( L_11 , V_59 -> V_302 ) ;
V_304:
return - V_310 ;
}
static void T_8 F_206 ( struct V_59 * V_59 )
{
F_205 ( L_12 , V_59 -> V_302 ) ;
F_205 ( L_11 , V_59 -> V_302 ) ;
F_207 ( V_59 -> V_115 . V_307 ) ;
}
static int F_208 ( struct V_311 * V_312 ,
unsigned long V_313 , void * V_314 )
{
struct V_49 * V_50 = F_209 ( V_314 ) ;
struct V_1 * V_2 ;
switch ( V_313 ) {
case V_315 :
V_2 = F_142 ( V_50 ) ;
if ( V_2 )
F_130 ( V_2 ) ;
break;
default:
break;
}
return V_316 ;
}
int T_9 F_210 ( void )
{
#if F_211 ( V_317 )
int V_197 ;
V_197 = F_212 ( & V_318 ) ;
if ( V_197 )
return V_197 ;
V_197 = F_213 ( & V_319 ) ;
if ( V_197 )
goto V_320;
return 0 ;
V_320:
F_214 ( & V_318 ) ;
return V_197 ;
#else
return F_213 ( & V_319 ) ;
#endif
}
