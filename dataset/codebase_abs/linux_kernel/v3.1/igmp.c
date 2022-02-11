static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) ) {
F_3 ( V_2 -> V_4 ) ;
F_4 ( V_2 , V_5 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_6 ) ;
if ( F_7 ( & V_2 -> V_7 ) )
F_8 ( & V_2 -> V_3 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
F_9 ( & V_2 -> V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_11 )
{
int V_12 = F_11 () % V_11 ;
V_2 -> V_8 = 1 ;
if ( ! F_12 ( & V_2 -> V_7 , V_13 + V_12 + 2 ) )
F_13 ( & V_2 -> V_3 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
int V_12 = F_11 () % V_15 -> V_16 ;
V_15 -> V_17 = 1 ;
if ( ! F_12 ( & V_15 -> V_18 , V_13 + V_12 + 2 ) )
F_15 ( V_15 ) ;
}
static void F_16 ( struct V_14 * V_15 , int V_19 )
{
int V_12 = F_11 () % V_19 ;
if ( ! F_12 ( & V_15 -> V_20 , V_13 + V_12 + 2 ) )
F_15 ( V_15 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_11 )
{
F_6 ( & V_2 -> V_6 ) ;
V_2 -> V_10 = 0 ;
if ( F_7 ( & V_2 -> V_7 ) ) {
if ( ( long ) ( V_2 -> V_7 . V_21 - V_13 ) < V_11 ) {
F_18 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = 1 ;
F_9 ( & V_2 -> V_6 ) ;
return;
}
F_8 ( & V_2 -> V_3 ) ;
}
F_10 ( V_2 , V_11 ) ;
F_9 ( & V_2 -> V_6 ) ;
}
static int F_19 ( struct V_1 * V_22 , struct V_23 * V_24 , int type ,
int V_25 , int V_26 )
{
switch ( type ) {
case V_27 :
case V_28 :
if ( V_25 || V_26 )
return 0 ;
if ( ! ( V_22 -> V_29 && ! V_24 -> V_30 ) ) {
if ( V_22 -> V_31 == V_32 )
return 1 ;
if ( V_24 -> V_33 [ V_32 ] )
return type == V_27 ;
return V_22 -> V_34 [ V_35 ] ==
V_24 -> V_33 [ V_35 ] ;
}
return 0 ;
case V_36 :
if ( V_25 || V_26 )
return 0 ;
return V_24 -> V_33 [ V_32 ] != 0 ;
case V_37 :
if ( V_25 || V_26 )
return 0 ;
if ( V_22 -> V_34 [ V_35 ] == 0 ||
V_24 -> V_33 [ V_32 ] )
return 0 ;
return V_22 -> V_34 [ V_35 ] ==
V_24 -> V_33 [ V_35 ] ;
case V_38 :
if ( V_25 || ! V_24 -> V_39 )
return 0 ;
return ( V_22 -> V_31 == V_32 ) ^ V_26 ;
case V_40 :
if ( V_22 -> V_31 == V_32 )
return V_25 || ( V_24 -> V_39 && V_26 ) ;
return V_24 -> V_39 && ! V_25 && ! V_26 ;
}
return 0 ;
}
static int
F_20 ( struct V_1 * V_22 , int type , int V_25 , int V_26 )
{
struct V_23 * V_24 ;
int V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( ! F_19 ( V_22 , V_24 , type , V_25 , V_26 ) )
continue;
V_41 ++ ;
}
return V_41 ;
}
static struct V_44 * F_21 ( struct V_45 * V_46 , int V_47 )
{
struct V_44 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_55 = F_22 ( V_46 ) ;
struct V_56 V_57 ;
while ( 1 ) {
V_48 = F_23 ( V_47 + F_24 ( V_46 ) ,
V_58 | V_59 ) ;
if ( V_48 )
break;
V_47 >>= 1 ;
if ( V_47 < 256 )
return NULL ;
}
F_25 ( V_48 ) = V_47 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_60 , 0 ,
0 , 0 ,
V_61 , 0 , V_46 -> V_62 ) ;
if ( F_27 ( V_50 ) ) {
F_28 ( V_48 ) ;
return NULL ;
}
F_29 ( V_48 , & V_50 -> V_63 ) ;
V_48 -> V_46 = V_46 ;
F_30 ( V_48 , F_31 ( V_46 ) ) ;
F_32 ( V_48 ) ;
V_52 = F_33 ( V_48 ) ;
F_34 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_52 -> V_64 = 4 ;
V_52 -> V_65 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_52 -> V_66 = 0xc0 ;
V_52 -> V_67 = F_35 ( V_68 ) ;
V_52 -> V_69 = 1 ;
V_52 -> V_70 = V_57 . V_70 ;
V_52 -> V_71 = V_57 . V_71 ;
V_52 -> V_72 = V_61 ;
V_52 -> V_73 = 0 ;
F_36 ( V_52 , & V_50 -> V_63 , NULL ) ;
( ( V_74 * ) & V_52 [ 1 ] ) [ 0 ] = V_75 ;
( ( V_74 * ) & V_52 [ 1 ] ) [ 1 ] = 4 ;
( ( V_74 * ) & V_52 [ 1 ] ) [ 2 ] = 0 ;
( ( V_74 * ) & V_52 [ 1 ] ) [ 3 ] = 0 ;
V_48 -> V_76 = V_48 -> V_77 + sizeof( struct V_51 ) + 4 ;
F_34 ( V_48 , sizeof( * V_54 ) ) ;
V_54 = F_37 ( V_48 ) ;
V_54 -> type = V_78 ;
V_54 -> V_79 = 0 ;
V_54 -> V_80 = 0 ;
V_54 -> V_81 = 0 ;
V_54 -> V_82 = 0 ;
return V_48 ;
}
static int F_38 ( struct V_44 * V_48 )
{
struct V_83 * V_54 = F_39 ( V_48 ) ;
const int V_84 = V_48 -> V_85 - V_48 -> V_76 ;
V_54 -> V_80 = F_40 ( F_39 ( V_48 ) , V_84 ) ;
return F_41 ( V_48 ) ;
}
static int F_42 ( struct V_1 * V_22 , int type , int V_86 , int V_87 )
{
return sizeof( struct V_88 ) + 4 * F_20 ( V_22 , type , V_86 , V_87 ) ;
}
static struct V_44 * F_43 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , struct V_88 * * V_89 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_90 ;
struct V_88 * V_91 ;
if ( ! V_48 )
V_48 = F_21 ( V_46 , V_46 -> V_92 ) ;
if ( ! V_48 )
return NULL ;
V_91 = (struct V_88 * ) F_34 ( V_48 , sizeof( struct V_88 ) ) ;
V_91 -> V_93 = type ;
V_91 -> V_94 = 0 ;
V_91 -> V_95 = 0 ;
V_91 -> V_96 = V_22 -> V_97 ;
V_90 = F_37 ( V_48 ) ;
V_90 -> V_82 = F_35 ( F_44 ( V_90 -> V_82 ) + 1 ) ;
* V_89 = V_91 ;
return V_48 ;
}
static struct V_44 * F_45 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , int V_25 , int V_26 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_90 ;
struct V_88 * V_91 = NULL ;
struct V_23 * V_24 , * V_98 , * V_99 , * * V_100 ;
int V_41 , V_101 , V_102 , V_103 , V_104 ;
if ( V_22 -> V_97 == V_105 )
return V_48 ;
V_103 = type == V_27 ||
type == V_28 ;
V_104 = type == V_28 ||
type == V_37 ;
V_101 = V_41 = 0 ;
V_100 = V_26 ? & V_22 -> V_106 : & V_22 -> V_42 ;
if ( ! * V_100 )
goto V_107;
V_90 = V_48 ? F_37 ( V_48 ) : NULL ;
if ( V_104 ) {
if ( V_90 && V_90 -> V_82 &&
F_46 ( V_48 ) < F_42 ( V_22 , type , V_25 , V_26 ) ) {
if ( V_48 )
F_38 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_92 ) ;
}
}
V_102 = 1 ;
V_99 = NULL ;
for ( V_24 = * V_100 ; V_24 ; V_24 = V_98 ) {
T_1 * V_108 ;
V_98 = V_24 -> V_43 ;
if ( ! F_19 ( V_22 , V_24 , type , V_25 , V_26 ) ) {
V_99 = V_24 ;
continue;
}
if ( V_103 )
V_24 -> V_30 = 0 ;
if ( F_46 ( V_48 ) < sizeof( T_1 ) +
V_102 * sizeof( struct V_88 ) ) {
if ( V_104 && ! V_102 )
break;
if ( V_91 )
V_91 -> V_95 = F_35 ( V_41 ) ;
if ( V_48 )
F_38 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_92 ) ;
V_102 = 1 ;
V_41 = 0 ;
}
if ( V_102 ) {
V_48 = F_43 ( V_48 , V_22 , type , & V_91 ) ;
V_102 = 0 ;
}
if ( ! V_48 )
return NULL ;
V_108 = ( T_1 * ) F_34 ( V_48 , sizeof( T_1 ) ) ;
* V_108 = V_24 -> V_109 ;
V_41 ++ ; V_101 ++ ;
if ( ( type == V_38 ||
type == V_40 ) && V_24 -> V_39 ) {
V_24 -> V_39 -- ;
if ( ( V_26 || V_25 ) && V_24 -> V_39 == 0 ) {
if ( V_99 )
V_99 -> V_43 = V_24 -> V_43 ;
else
* V_100 = V_24 -> V_43 ;
F_47 ( V_24 ) ;
continue;
}
}
V_99 = V_24 ;
}
V_107:
if ( ! V_101 ) {
if ( type == V_38 ||
type == V_40 )
return V_48 ;
if ( V_22 -> V_110 || V_103 ) {
if ( V_48 && F_46 ( V_48 ) < sizeof( struct V_88 ) ) {
F_38 ( V_48 ) ;
V_48 = NULL ;
}
V_48 = F_43 ( V_48 , V_22 , type , & V_91 ) ;
}
}
if ( V_91 )
V_91 -> V_95 = F_35 ( V_41 ) ;
if ( V_103 )
V_22 -> V_29 = 0 ;
return V_48 ;
}
static int F_48 ( struct V_14 * V_15 , struct V_1 * V_22 )
{
struct V_44 * V_48 = NULL ;
int type ;
if ( ! V_22 ) {
F_49 () ;
F_50 (in_dev, pmc) {
if ( V_22 -> V_97 == V_105 )
continue;
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_45 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
F_51 () ;
} else {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_45 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
if ( ! V_48 )
return 0 ;
return F_38 ( V_48 ) ;
}
static void F_52 ( struct V_23 * * V_111 )
{
struct V_23 * V_99 , * V_98 , * V_24 ;
V_99 = NULL ;
for ( V_24 = * V_111 ; V_24 ; V_24 = V_98 ) {
V_98 = V_24 -> V_43 ;
if ( V_24 -> V_39 == 0 ) {
if ( V_99 )
V_99 -> V_43 = V_24 -> V_43 ;
else
* V_111 = V_24 -> V_43 ;
F_47 ( V_24 ) ;
} else
V_99 = V_24 ;
}
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_112 , * V_113 ;
struct V_44 * V_48 = NULL ;
int type , V_114 ;
F_49 () ;
F_6 ( & V_15 -> V_115 ) ;
V_112 = NULL ;
for ( V_22 = V_15 -> V_116 ; V_22 ; V_22 = V_113 ) {
V_113 = V_22 -> V_117 ;
if ( V_22 -> V_31 == V_32 ) {
type = V_40 ;
V_114 = V_40 ;
V_48 = F_45 ( V_48 , V_22 , type , 1 , 0 ) ;
V_48 = F_45 ( V_48 , V_22 , V_114 , 1 , 1 ) ;
}
if ( V_22 -> V_110 ) {
if ( V_22 -> V_31 == V_35 ) {
type = V_36 ;
V_48 = F_45 ( V_48 , V_22 , type , 1 , 0 ) ;
}
V_22 -> V_110 -- ;
if ( V_22 -> V_110 == 0 ) {
F_52 ( & V_22 -> V_106 ) ;
F_52 ( & V_22 -> V_42 ) ;
}
}
if ( V_22 -> V_110 == 0 && ! V_22 -> V_106 && ! V_22 -> V_42 ) {
if ( V_112 )
V_112 -> V_117 = V_113 ;
else
V_15 -> V_116 = V_113 ;
F_3 ( V_22 -> V_4 ) ;
F_47 ( V_22 ) ;
} else
V_112 = V_22 ;
}
F_9 ( & V_15 -> V_115 ) ;
F_50 (in_dev, pmc) {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] ) {
type = V_40 ;
V_114 = V_38 ;
} else {
type = V_38 ;
V_114 = V_40 ;
}
V_48 = F_45 ( V_48 , V_22 , type , 0 , 0 ) ;
V_48 = F_45 ( V_48 , V_22 , V_114 , 0 , 1 ) ;
if ( V_22 -> V_110 ) {
if ( V_22 -> V_31 == V_35 )
type = V_37 ;
else
type = V_36 ;
V_48 = F_45 ( V_48 , V_22 , type , 0 , 0 ) ;
V_22 -> V_110 -- ;
}
F_9 ( & V_22 -> V_6 ) ;
}
F_51 () ;
if ( ! V_48 )
return;
( void ) F_38 ( V_48 ) ;
}
static int F_54 ( struct V_14 * V_15 , struct V_1 * V_22 ,
int type )
{
struct V_44 * V_48 ;
struct V_51 * V_118 ;
struct V_83 * V_119 ;
struct V_49 * V_50 ;
struct V_45 * V_46 = V_15 -> V_46 ;
struct V_55 * V_55 = F_22 ( V_46 ) ;
T_1 V_120 = V_22 ? V_22 -> V_97 : 0 ;
struct V_56 V_57 ;
T_1 V_63 ;
if ( type == V_78 )
return F_48 ( V_15 , V_22 ) ;
else if ( type == V_121 )
V_63 = V_122 ;
else
V_63 = V_120 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_63 , 0 ,
0 , 0 ,
V_61 , 0 , V_46 -> V_62 ) ;
if ( F_27 ( V_50 ) )
return - 1 ;
V_48 = F_23 ( V_123 + F_24 ( V_46 ) , V_58 ) ;
if ( V_48 == NULL ) {
F_55 ( V_50 ) ;
return - 1 ;
}
F_29 ( V_48 , & V_50 -> V_63 ) ;
F_30 ( V_48 , F_31 ( V_46 ) ) ;
F_32 ( V_48 ) ;
V_118 = F_33 ( V_48 ) ;
F_34 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_118 -> V_64 = 4 ;
V_118 -> V_65 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_118 -> V_66 = 0xc0 ;
V_118 -> V_67 = F_35 ( V_68 ) ;
V_118 -> V_69 = 1 ;
V_118 -> V_70 = V_63 ;
V_118 -> V_71 = V_57 . V_71 ;
V_118 -> V_72 = V_61 ;
F_36 ( V_118 , & V_50 -> V_63 , NULL ) ;
( ( V_74 * ) & V_118 [ 1 ] ) [ 0 ] = V_75 ;
( ( V_74 * ) & V_118 [ 1 ] ) [ 1 ] = 4 ;
( ( V_74 * ) & V_118 [ 1 ] ) [ 2 ] = 0 ;
( ( V_74 * ) & V_118 [ 1 ] ) [ 3 ] = 0 ;
V_119 = (struct V_83 * ) F_34 ( V_48 , sizeof( struct V_83 ) ) ;
V_119 -> type = type ;
V_119 -> V_124 = 0 ;
V_119 -> V_80 = 0 ;
V_119 -> V_120 = V_120 ;
V_119 -> V_80 = F_40 ( ( void * ) V_119 , sizeof( struct V_83 ) ) ;
return F_41 ( V_48 ) ;
}
static void F_56 ( unsigned long V_125 )
{
struct V_14 * V_15 = (struct V_14 * ) V_125 ;
V_15 -> V_17 = 0 ;
F_48 ( V_15 , NULL ) ;
F_57 ( V_15 ) ;
}
static void F_58 ( unsigned long V_125 )
{
struct V_14 * V_15 = (struct V_14 * ) V_125 ;
F_53 ( V_15 ) ;
if ( V_15 -> V_126 ) {
V_15 -> V_126 -- ;
F_16 ( V_15 , V_127 ) ;
}
F_57 ( V_15 ) ;
}
static void F_59 ( struct V_14 * V_15 )
{
if ( F_60 ( V_15 ) || F_61 ( V_15 ) )
return;
V_15 -> V_126 = V_15 -> V_128 ? V_15 -> V_128 :
V_129 ;
F_16 ( V_15 , 1 ) ;
}
static void F_62 ( unsigned long V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) V_125 ;
struct V_14 * V_15 = V_2 -> V_4 ;
F_63 ( & V_2 -> V_6 ) ;
V_2 -> V_8 = 0 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 -- ;
F_10 ( V_2 , V_127 ) ;
}
V_2 -> V_9 = 1 ;
F_64 ( & V_2 -> V_6 ) ;
if ( F_60 ( V_15 ) )
F_54 ( V_15 , V_2 , V_130 ) ;
else if ( F_61 ( V_15 ) )
F_54 ( V_15 , V_2 , V_131 ) ;
else
F_54 ( V_15 , V_2 , V_78 ) ;
F_1 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_22 , int V_132 , T_1 * V_133 )
{
struct V_23 * V_24 ;
int V_134 , V_41 ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_132 )
break;
for ( V_134 = 0 ; V_134 < V_132 ; V_134 ++ ) {
if ( V_24 -> V_33 [ V_32 ] ||
V_22 -> V_34 [ V_35 ] !=
V_24 -> V_33 [ V_35 ] )
continue;
if ( V_133 [ V_134 ] == V_24 -> V_109 ) {
V_41 ++ ;
break;
}
}
}
V_22 -> V_29 = 0 ;
if ( V_41 == V_132 )
return 0 ;
return 1 ;
}
static int F_66 ( struct V_1 * V_22 , int V_132 , T_1 * V_133 )
{
struct V_23 * V_24 ;
int V_134 , V_41 ;
if ( V_22 -> V_31 == V_35 )
return F_65 ( V_22 , V_132 , V_133 ) ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_132 )
break;
for ( V_134 = 0 ; V_134 < V_132 ; V_134 ++ )
if ( V_133 [ V_134 ] == V_24 -> V_109 ) {
V_24 -> V_30 = 1 ;
V_41 ++ ;
break;
}
}
if ( ! V_41 ) {
V_22 -> V_29 = 0 ;
return 0 ;
}
V_22 -> V_29 = 1 ;
return 1 ;
}
static void F_67 ( struct V_14 * V_15 , T_1 V_120 )
{
struct V_1 * V_2 ;
if ( V_120 == V_105 )
return;
F_49 () ;
F_50 (in_dev, im) {
if ( V_2 -> V_97 == V_120 ) {
F_5 ( V_2 ) ;
break;
}
}
F_51 () ;
}
static void F_68 ( struct V_14 * V_15 , struct V_44 * V_48 ,
int V_135 )
{
struct V_83 * V_119 = F_39 ( V_48 ) ;
struct V_136 * V_137 = F_69 ( V_48 ) ;
struct V_1 * V_2 ;
T_1 V_120 = V_119 -> V_120 ;
int V_11 ;
int V_138 = 0 ;
if ( V_135 == 8 ) {
if ( V_119 -> V_124 == 0 ) {
V_11 = V_139 ;
V_15 -> V_140 = V_13 +
V_141 ;
V_120 = 0 ;
} else {
V_11 = V_119 -> V_124 * ( V_142 / V_143 ) ;
V_15 -> V_144 = V_13 +
V_145 ;
}
V_15 -> V_126 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_57 ( V_15 ) ;
F_70 ( V_15 ) ;
} else if ( V_135 < 12 ) {
return;
} else if ( F_60 ( V_15 ) ) {
V_11 = V_139 ;
V_120 = 0 ;
} else if ( F_61 ( V_15 ) ) {
V_11 = F_71 ( V_137 -> V_124 ) * ( V_142 / V_143 ) ;
} else {
if ( ! F_72 ( V_48 , sizeof( struct V_136 ) ) )
return;
V_137 = F_69 ( V_48 ) ;
if ( V_137 -> V_132 ) {
if ( ! F_72 ( V_48 , sizeof( struct V_136 )
+ F_44 ( V_137 -> V_132 ) * sizeof( T_1 ) ) )
return;
V_137 = F_69 ( V_48 ) ;
}
V_11 = F_71 ( V_137 -> V_124 ) * ( V_142 / V_143 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_15 -> V_16 = V_11 ;
if ( V_137 -> V_146 )
V_15 -> V_128 = V_137 -> V_146 ;
if ( ! V_120 ) {
if ( V_137 -> V_132 )
return;
F_14 ( V_15 ) ;
return;
}
V_138 = V_137 -> V_132 != 0 ;
}
F_49 () ;
F_50 (in_dev, im) {
int V_147 ;
if ( V_120 && V_120 != V_2 -> V_97 )
continue;
if ( V_2 -> V_97 == V_105 )
continue;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_2 -> V_29 = V_2 -> V_29 && V_138 ;
else
V_2 -> V_29 = V_138 ;
V_147 = ! V_2 -> V_29 ||
F_66 ( V_2 , F_44 ( V_137 -> V_132 ) , V_137 -> V_133 ) ;
F_9 ( & V_2 -> V_6 ) ;
if ( V_147 )
F_17 ( V_2 , V_11 ) ;
}
F_51 () ;
}
int F_73 ( struct V_44 * V_48 )
{
struct V_83 * V_119 ;
struct V_14 * V_15 = F_74 ( V_48 -> V_46 ) ;
int V_135 = V_48 -> V_135 ;
if ( V_15 == NULL )
goto V_148;
if ( ! F_72 ( V_48 , sizeof( struct V_83 ) ) )
goto V_148;
switch ( V_48 -> V_149 ) {
case V_150 :
if ( ! F_75 ( V_48 -> V_80 ) )
break;
case V_151 :
V_48 -> V_80 = 0 ;
if ( F_76 ( V_48 ) )
goto V_148;
}
V_119 = F_39 ( V_48 ) ;
switch ( V_119 -> type ) {
case V_152 :
F_68 ( V_15 , V_48 , V_135 ) ;
break;
case V_130 :
case V_131 :
if ( F_77 ( F_78 ( V_48 ) ) )
break;
if ( V_48 -> V_153 == V_154 ||
V_48 -> V_153 == V_155 )
F_67 ( V_15 , V_119 -> V_120 ) ;
break;
case V_156 :
#ifdef F_79
return F_80 ( V_48 ) ;
#endif
case V_78 :
case V_157 :
case V_158 :
case V_121 :
case V_159 :
case V_160 :
break;
default:
break;
}
V_148:
F_28 ( V_48 ) ;
return 0 ;
}
static void F_81 ( struct V_14 * V_15 , T_1 V_161 )
{
char V_162 [ V_163 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_82 ( V_161 , V_162 , V_46 , 0 ) == 0 )
F_83 ( V_46 , V_162 ) ;
}
static void F_84 ( struct V_14 * V_15 , T_1 V_161 )
{
char V_162 [ V_163 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_82 ( V_161 , V_162 , V_46 , 0 ) == 0 )
F_85 ( V_46 , V_162 ) ;
}
static void F_86 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_1 * V_22 ;
V_22 = F_87 ( sizeof( * V_22 ) , V_164 ) ;
if ( ! V_22 )
return;
F_6 ( & V_2 -> V_6 ) ;
V_22 -> V_4 = V_2 -> V_4 ;
F_15 ( V_15 ) ;
V_22 -> V_97 = V_2 -> V_97 ;
V_22 -> V_110 = V_15 -> V_128 ? V_15 -> V_128 :
V_129 ;
V_22 -> V_31 = V_2 -> V_31 ;
if ( V_22 -> V_31 == V_32 ) {
struct V_23 * V_24 ;
V_22 -> V_106 = V_2 -> V_106 ;
V_22 -> V_42 = V_2 -> V_42 ;
V_2 -> V_106 = V_2 -> V_42 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = V_22 -> V_110 ;
}
F_9 ( & V_2 -> V_6 ) ;
F_6 ( & V_15 -> V_115 ) ;
V_22 -> V_117 = V_15 -> V_116 ;
V_15 -> V_116 = V_22 ;
F_9 ( & V_15 -> V_115 ) ;
}
static void F_88 ( struct V_14 * V_15 , T_1 V_97 )
{
struct V_1 * V_22 , * V_112 ;
struct V_23 * V_24 , * V_98 ;
F_6 ( & V_15 -> V_115 ) ;
V_112 = NULL ;
for ( V_22 = V_15 -> V_116 ; V_22 ; V_22 = V_22 -> V_117 ) {
if ( V_22 -> V_97 == V_97 )
break;
V_112 = V_22 ;
}
if ( V_22 ) {
if ( V_112 )
V_112 -> V_117 = V_22 -> V_117 ;
else
V_15 -> V_116 = V_22 -> V_117 ;
}
F_9 ( & V_15 -> V_115 ) ;
if ( V_22 ) {
for ( V_24 = V_22 -> V_106 ; V_24 ; V_24 = V_98 ) {
V_98 = V_24 -> V_43 ;
F_47 ( V_24 ) ;
}
F_3 ( V_22 -> V_4 ) ;
F_47 ( V_22 ) ;
}
}
static void F_70 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_165 ;
F_6 ( & V_15 -> V_115 ) ;
V_22 = V_15 -> V_116 ;
V_15 -> V_116 = NULL ;
F_9 ( & V_15 -> V_115 ) ;
for (; V_22 ; V_22 = V_165 ) {
V_165 = V_22 -> V_117 ;
F_89 ( V_22 ) ;
F_3 ( V_22 -> V_4 ) ;
F_47 ( V_22 ) ;
}
F_49 () ;
F_50 (in_dev, pmc) {
struct V_23 * V_24 , * V_98 ;
F_6 ( & V_22 -> V_6 ) ;
V_24 = V_22 -> V_106 ;
V_22 -> V_106 = NULL ;
F_9 ( & V_22 -> V_6 ) ;
for (; V_24 ; V_24 = V_98 ) {
V_98 = V_24 -> V_43 ;
F_47 ( V_24 ) ;
}
}
F_51 () ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
#ifdef F_91
int V_9 ;
#endif
if ( V_2 -> V_166 ) {
V_2 -> V_166 = 0 ;
F_84 ( V_15 , V_2 -> V_97 ) ;
}
#ifdef F_91
if ( V_2 -> V_97 == V_105 )
return;
V_9 = V_2 -> V_9 ;
F_5 ( V_2 ) ;
if ( ! V_15 -> V_167 ) {
if ( F_60 ( V_15 ) )
return;
if ( F_61 ( V_15 ) ) {
if ( V_9 )
F_54 ( V_15 , V_2 , V_121 ) ;
return;
}
F_86 ( V_15 , V_2 ) ;
F_59 ( V_15 ) ;
}
#endif
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
if ( V_2 -> V_166 == 0 ) {
V_2 -> V_166 = 1 ;
F_81 ( V_15 , V_2 -> V_97 ) ;
}
#ifdef F_91
if ( V_2 -> V_97 == V_105 )
return;
if ( V_15 -> V_167 )
return;
if ( F_60 ( V_15 ) || F_61 ( V_15 ) ) {
F_6 ( & V_2 -> V_6 ) ;
F_10 ( V_2 , V_168 ) ;
F_9 ( & V_2 -> V_6 ) ;
return;
}
V_2 -> V_110 = V_15 -> V_128 ? V_15 -> V_128 :
V_129 ;
F_59 ( V_15 ) ;
#endif
}
void F_93 ( struct V_14 * V_15 , T_1 V_161 )
{
struct V_1 * V_2 ;
F_94 () ;
F_95 (in_dev, im) {
if ( V_2 -> V_97 == V_161 ) {
V_2 -> V_169 ++ ;
F_96 ( V_15 , & V_161 , V_35 , 0 , NULL , 0 ) ;
goto V_170;
}
}
V_2 = F_87 ( sizeof( * V_2 ) , V_164 ) ;
if ( ! V_2 )
goto V_170;
V_2 -> V_169 = 1 ;
V_2 -> V_4 = V_15 ;
F_15 ( V_15 ) ;
V_2 -> V_97 = V_161 ;
V_2 -> V_31 = V_35 ;
V_2 -> V_34 [ V_35 ] = 1 ;
F_97 ( & V_2 -> V_3 , 1 ) ;
F_98 ( & V_2 -> V_6 ) ;
#ifdef F_91
F_99 ( & V_2 -> V_7 , & F_62 , ( unsigned long ) V_2 ) ;
V_2 -> V_10 = V_129 ;
#endif
V_2 -> V_171 = V_15 -> V_172 ;
V_15 -> V_173 ++ ;
F_100 ( V_15 -> V_172 , V_2 ) ;
#ifdef F_91
F_88 ( V_15 , V_2 -> V_97 ) ;
#endif
F_92 ( V_2 ) ;
if ( ! V_15 -> V_167 )
F_101 ( V_15 ) ;
V_170:
return;
}
void F_102 ( struct V_14 * V_15 )
{
#ifdef F_91
struct V_1 * V_2 ;
int type ;
F_50 (in_dev, im) {
if ( V_2 -> V_97 == V_105 )
continue;
if ( F_60 ( V_15 ) )
type = V_130 ;
else if ( F_61 ( V_15 ) )
type = V_131 ;
else
type = V_78 ;
F_54 ( V_15 , V_2 , type ) ;
}
#endif
}
void F_103 ( struct V_14 * V_15 , T_1 V_161 )
{
struct V_1 * V_134 ;
struct V_1 T_2 * * V_174 ;
F_94 () ;
for ( V_174 = & V_15 -> V_172 ;
( V_134 = F_104 ( * V_174 ) ) != NULL ;
V_174 = & V_134 -> V_171 ) {
if ( V_134 -> V_97 == V_161 ) {
if ( -- V_134 -> V_169 == 0 ) {
* V_174 = V_134 -> V_171 ;
V_15 -> V_173 -- ;
F_90 ( V_134 ) ;
F_89 ( V_134 ) ;
if ( ! V_15 -> V_167 )
F_101 ( V_15 ) ;
F_1 ( V_134 ) ;
return;
}
break;
}
}
}
void F_105 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_95 (in_dev, pmc)
F_90 ( V_22 ) ;
}
void F_106 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_95 (in_dev, pmc)
F_92 ( V_22 ) ;
}
void F_107 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_95 (in_dev, pmc)
F_90 ( V_22 ) ;
#ifdef F_91
V_15 -> V_126 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_57 ( V_15 ) ;
V_15 -> V_17 = 0 ;
if ( F_7 ( & V_15 -> V_18 ) )
F_57 ( V_15 ) ;
F_70 ( V_15 ) ;
#endif
F_103 ( V_15 , V_105 ) ;
}
void F_108 ( struct V_14 * V_15 )
{
F_94 () ;
V_15 -> V_116 = NULL ;
#ifdef F_91
V_15 -> V_17 = 0 ;
F_99 ( & V_15 -> V_18 , F_56 ,
( unsigned long ) V_15 ) ;
V_15 -> V_126 = 0 ;
V_15 -> V_173 = 0 ;
F_99 ( & V_15 -> V_20 , F_58 ,
( unsigned long ) V_15 ) ;
V_15 -> V_128 = V_129 ;
#endif
F_98 ( & V_15 -> V_115 ) ;
}
void F_109 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_94 () ;
F_93 ( V_15 , V_105 ) ;
F_95 (in_dev, pmc)
F_92 ( V_22 ) ;
}
void F_110 ( struct V_14 * V_15 )
{
struct V_1 * V_134 ;
F_94 () ;
F_107 ( V_15 ) ;
while ( ( V_134 = F_104 ( V_15 -> V_172 ) ) != NULL ) {
V_15 -> V_172 = V_134 -> V_171 ;
V_15 -> V_173 -- ;
F_89 ( V_134 ) ;
F_1 ( V_134 ) ;
}
}
static struct V_14 * F_111 ( struct V_55 * V_55 , struct V_175 * V_176 )
{
struct V_45 * V_46 = NULL ;
struct V_14 * V_177 = NULL ;
if ( V_176 -> V_178 ) {
V_177 = F_112 ( V_55 , V_176 -> V_178 ) ;
return V_177 ;
}
if ( V_176 -> V_179 . V_180 ) {
V_46 = F_113 ( V_55 , V_176 -> V_179 . V_180 , false ) ;
if ( ! V_46 )
return NULL ;
}
if ( ! V_46 ) {
struct V_49 * V_50 = F_114 ( V_55 ,
V_176 -> V_181 . V_180 ,
0 , 0 , 0 ) ;
if ( ! F_27 ( V_50 ) ) {
V_46 = V_50 -> V_63 . V_46 ;
F_55 ( V_50 ) ;
}
}
if ( V_46 ) {
V_176 -> V_178 = V_46 -> V_62 ;
V_177 = F_115 ( V_46 ) ;
}
return V_177 ;
}
static int F_116 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_182 )
{
struct V_23 * V_24 , * V_99 ;
int V_183 = 0 ;
V_99 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_109 == * V_182 )
break;
V_99 = V_24 ;
}
if ( ! V_24 || V_24 -> V_33 [ V_31 ] == 0 ) {
return - V_184 ;
}
V_24 -> V_33 [ V_31 ] -- ;
if ( V_24 -> V_33 [ V_31 ] == 0 ) {
F_101 ( V_22 -> V_4 ) ;
}
if ( ! V_24 -> V_33 [ V_32 ] && ! V_24 -> V_33 [ V_35 ] ) {
#ifdef F_91
struct V_14 * V_15 = V_22 -> V_4 ;
#endif
if ( V_99 )
V_99 -> V_43 = V_24 -> V_43 ;
else
V_22 -> V_42 = V_24 -> V_43 ;
#ifdef F_91
if ( V_24 -> V_185 &&
! F_60 ( V_15 ) && ! F_61 ( V_15 ) ) {
V_24 -> V_39 = V_15 -> V_128 ? V_15 -> V_128 :
V_129 ;
V_24 -> V_43 = V_22 -> V_106 ;
V_22 -> V_106 = V_24 ;
V_183 = 1 ;
} else
#endif
F_47 ( V_24 ) ;
}
return V_183 ;
}
static int F_117 ( struct V_14 * V_15 , T_1 * V_186 , int V_31 ,
int V_34 , T_1 * V_182 , int V_187 )
{
struct V_1 * V_22 ;
int V_188 = 0 ;
int V_134 , V_189 ;
if ( ! V_15 )
return - V_190 ;
F_49 () ;
F_50 (in_dev, pmc) {
if ( * V_186 == V_22 -> V_97 )
break;
}
if ( ! V_22 ) {
F_51 () ;
return - V_184 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_51 () ;
#ifdef F_91
F_118 ( V_22 ) ;
#endif
if ( ! V_187 ) {
V_189 = - V_191 ;
if ( ! V_22 -> V_34 [ V_31 ] )
goto V_192;
V_22 -> V_34 [ V_31 ] -- ;
}
V_189 = 0 ;
for ( V_134 = 0 ; V_134 < V_34 ; V_134 ++ ) {
int V_183 = F_116 ( V_22 , V_31 , & V_182 [ V_134 ] ) ;
V_188 |= V_183 > 0 ;
if ( ! V_189 && V_183 < 0 )
V_189 = V_183 ;
}
if ( V_22 -> V_31 == V_35 &&
V_22 -> V_34 [ V_35 ] == 0 &&
V_22 -> V_34 [ V_32 ] ) {
#ifdef F_91
struct V_23 * V_24 ;
#endif
V_22 -> V_31 = V_32 ;
#ifdef F_91
V_22 -> V_110 = V_15 -> V_128 ? V_15 -> V_128 :
V_129 ;
V_15 -> V_126 = V_22 -> V_110 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_59 ( V_22 -> V_4 ) ;
} else if ( F_119 ( V_22 ) || V_188 ) {
F_59 ( V_22 -> V_4 ) ;
#endif
}
V_192:
F_9 ( & V_22 -> V_6 ) ;
return V_189 ;
}
static int F_120 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_182 , int V_187 )
{
struct V_23 * V_24 , * V_99 ;
V_99 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_109 == * V_182 )
break;
V_99 = V_24 ;
}
if ( ! V_24 ) {
V_24 = F_87 ( sizeof( * V_24 ) , V_58 ) ;
if ( ! V_24 )
return - V_193 ;
V_24 -> V_109 = * V_182 ;
if ( V_99 ) {
V_99 -> V_43 = V_24 ;
} else
V_22 -> V_42 = V_24 ;
}
V_24 -> V_33 [ V_31 ] ++ ;
if ( V_24 -> V_33 [ V_31 ] == 1 ) {
F_101 ( V_22 -> V_4 ) ;
}
return 0 ;
}
static void F_118 ( struct V_1 * V_22 )
{
struct V_23 * V_24 ;
int V_194 = V_22 -> V_34 [ V_35 ] ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
if ( V_22 -> V_34 [ V_35 ] ) {
V_24 -> V_185 = V_194 ==
V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_24 -> V_185 = V_24 -> V_33 [ V_32 ] != 0 ;
}
static int F_119 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_195 ;
int V_194 = V_22 -> V_34 [ V_35 ] ;
int V_146 = V_22 -> V_4 -> V_128 ;
int V_196 , V_183 ;
V_183 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_22 -> V_34 [ V_35 ] ) {
V_196 = V_194 == V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_196 = V_24 -> V_33 [ V_32 ] != 0 ;
if ( V_196 ) {
if ( ! V_24 -> V_185 ) {
struct V_23 * V_197 = NULL ;
for ( V_195 = V_22 -> V_106 ; V_195 ; V_195 = V_195 -> V_43 ) {
if ( V_195 -> V_109 == V_24 -> V_109 )
break;
V_197 = V_195 ;
}
if ( V_195 ) {
if ( V_197 )
V_197 -> V_43 = V_195 -> V_43 ;
else
V_22 -> V_106 = V_195 -> V_43 ;
F_47 ( V_195 ) ;
}
V_24 -> V_39 = V_146 ;
V_183 ++ ;
}
} else if ( V_24 -> V_185 ) {
V_24 -> V_39 = 0 ;
for ( V_195 = V_22 -> V_106 ; V_195 ; V_195 = V_195 -> V_43 )
if ( V_195 -> V_109 == V_24 -> V_109 )
break;
if ( ! V_195 ) {
V_195 = F_121 ( sizeof( * V_195 ) , V_58 ) ;
if ( ! V_195 )
continue;
* V_195 = * V_24 ;
V_195 -> V_43 = V_22 -> V_106 ;
V_22 -> V_106 = V_195 ;
}
V_195 -> V_39 = V_146 ;
V_183 ++ ;
}
}
return V_183 ;
}
static int F_96 ( struct V_14 * V_15 , T_1 * V_186 , int V_31 ,
int V_34 , T_1 * V_182 , int V_187 )
{
struct V_1 * V_22 ;
int V_198 ;
int V_134 , V_189 ;
if ( ! V_15 )
return - V_190 ;
F_49 () ;
F_50 (in_dev, pmc) {
if ( * V_186 == V_22 -> V_97 )
break;
}
if ( ! V_22 ) {
F_51 () ;
return - V_184 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_51 () ;
#ifdef F_91
F_118 ( V_22 ) ;
#endif
V_198 = V_22 -> V_31 == V_35 ;
if ( ! V_187 )
V_22 -> V_34 [ V_31 ] ++ ;
V_189 = 0 ;
for ( V_134 = 0 ; V_134 < V_34 ; V_134 ++ ) {
V_189 = F_120 ( V_22 , V_31 , & V_182 [ V_134 ] , V_187 ) ;
if ( V_189 )
break;
}
if ( V_189 ) {
int V_199 ;
V_22 -> V_34 [ V_31 ] -- ;
for ( V_199 = 0 ; V_199 < V_134 ; V_199 ++ )
( void ) F_116 ( V_22 , V_31 , & V_182 [ V_199 ] ) ;
} else if ( V_198 != ( V_22 -> V_34 [ V_35 ] != 0 ) ) {
#ifdef F_91
struct V_23 * V_24 ;
V_15 = V_22 -> V_4 ;
#endif
if ( V_22 -> V_34 [ V_35 ] )
V_22 -> V_31 = V_35 ;
else if ( V_22 -> V_34 [ V_32 ] )
V_22 -> V_31 = V_32 ;
#ifdef F_91
V_22 -> V_110 = V_15 -> V_128 ? V_15 -> V_128 :
V_129 ;
V_15 -> V_126 = V_22 -> V_110 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_59 ( V_15 ) ;
} else if ( F_119 ( V_22 ) ) {
F_59 ( V_15 ) ;
#endif
}
F_9 ( & V_22 -> V_6 ) ;
return V_189 ;
}
static void F_89 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_200 ;
for ( V_24 = V_22 -> V_106 ; V_24 ; V_24 = V_200 ) {
V_200 = V_24 -> V_43 ;
F_47 ( V_24 ) ;
}
V_22 -> V_106 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_200 ) {
V_200 = V_24 -> V_43 ;
F_47 ( V_24 ) ;
}
V_22 -> V_42 = NULL ;
V_22 -> V_31 = V_35 ;
V_22 -> V_34 [ V_32 ] = 0 ;
V_22 -> V_34 [ V_35 ] = 1 ;
}
int F_122 ( struct V_201 * V_202 , struct V_175 * V_176 )
{
int V_189 ;
T_1 V_161 = V_176 -> V_181 . V_180 ;
struct V_203 * V_204 = NULL , * V_134 ;
struct V_14 * V_15 ;
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_55 * V_55 = F_124 ( V_202 ) ;
int V_62 ;
int V_207 = 0 ;
if ( ! F_125 ( V_161 ) )
return - V_191 ;
F_126 () ;
V_15 = F_111 ( V_55 , V_176 ) ;
if ( ! V_15 ) {
V_204 = NULL ;
V_189 = - V_190 ;
goto V_208;
}
V_189 = - V_209 ;
V_62 = V_176 -> V_178 ;
F_95 (inet, i) {
if ( V_134 -> V_210 . V_181 . V_180 == V_161 &&
V_134 -> V_210 . V_178 == V_62 )
goto V_208;
V_207 ++ ;
}
V_189 = - V_193 ;
if ( V_207 >= V_211 )
goto V_208;
V_204 = F_127 ( V_202 , sizeof( * V_204 ) , V_164 ) ;
if ( V_204 == NULL )
goto V_208;
memcpy ( & V_204 -> V_210 , V_176 , sizeof( * V_176 ) ) ;
V_204 -> V_171 = V_206 -> V_172 ;
V_204 -> V_212 = NULL ;
V_204 -> V_31 = V_35 ;
F_100 ( V_206 -> V_172 , V_204 ) ;
F_93 ( V_15 , V_161 ) ;
V_189 = 0 ;
V_208:
F_128 () ;
return V_189 ;
}
static int F_129 ( struct V_201 * V_202 , struct V_203 * V_204 ,
struct V_14 * V_15 )
{
struct V_213 * V_24 = F_104 ( V_204 -> V_212 ) ;
int V_189 ;
if ( V_24 == NULL ) {
return F_117 ( V_15 , & V_204 -> V_210 . V_181 . V_180 ,
V_204 -> V_31 , 0 , NULL , 0 ) ;
}
V_189 = F_117 ( V_15 , & V_204 -> V_210 . V_181 . V_180 ,
V_204 -> V_31 , V_24 -> V_214 , V_24 -> V_215 , 0 ) ;
F_100 ( V_204 -> V_212 , NULL ) ;
F_130 ( F_131 ( V_24 -> V_216 ) , & V_202 -> V_217 ) ;
F_4 ( V_24 , V_5 ) ;
return V_189 ;
}
int F_132 ( struct V_201 * V_202 , struct V_175 * V_176 )
{
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_203 * V_204 ;
struct V_203 T_2 * * V_218 ;
struct V_14 * V_15 ;
struct V_55 * V_55 = F_124 ( V_202 ) ;
T_1 V_120 = V_176 -> V_181 . V_180 ;
T_3 V_62 ;
int V_219 = - V_220 ;
F_126 () ;
V_15 = F_111 ( V_55 , V_176 ) ;
V_62 = V_176 -> V_178 ;
for ( V_218 = & V_206 -> V_172 ;
( V_204 = F_104 ( * V_218 ) ) != NULL ;
V_218 = & V_204 -> V_171 ) {
if ( V_204 -> V_210 . V_181 . V_180 != V_120 )
continue;
if ( V_62 ) {
if ( V_204 -> V_210 . V_178 != V_62 )
continue;
} else if ( V_176 -> V_179 . V_180 && V_176 -> V_179 . V_180 !=
V_204 -> V_210 . V_179 . V_180 )
continue;
( void ) F_129 ( V_202 , V_204 , V_15 ) ;
* V_218 = V_204 -> V_171 ;
if ( V_15 )
F_103 ( V_15 , V_120 ) ;
F_128 () ;
F_130 ( sizeof( * V_204 ) , & V_202 -> V_217 ) ;
F_4 ( V_204 , V_5 ) ;
return 0 ;
}
if ( ! V_15 )
V_219 = - V_190 ;
F_128 () ;
return V_219 ;
}
int F_133 ( int V_221 , int V_222 , struct V_201 * V_202 , struct
V_223 * V_224 , int V_62 )
{
int V_189 ;
struct V_175 V_176 ;
T_1 V_161 = V_224 -> V_181 ;
struct V_203 * V_22 ;
struct V_14 * V_15 = NULL ;
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_213 * V_225 ;
struct V_55 * V_55 = F_124 ( V_202 ) ;
int V_226 = 0 ;
int V_134 , V_199 , V_183 ;
if ( ! F_125 ( V_161 ) )
return - V_191 ;
F_126 () ;
V_176 . V_181 . V_180 = V_224 -> V_181 ;
V_176 . V_179 . V_180 = V_224 -> V_227 ;
V_176 . V_178 = V_62 ;
V_15 = F_111 ( V_55 , & V_176 ) ;
if ( ! V_15 ) {
V_189 = - V_190 ;
goto V_208;
}
V_189 = - V_220 ;
F_95 (inet, pmc) {
if ( ( V_22 -> V_210 . V_181 . V_180 ==
V_176 . V_181 . V_180 ) &&
( V_22 -> V_210 . V_178 == V_176 . V_178 ) )
break;
}
if ( ! V_22 ) {
V_189 = - V_191 ;
goto V_208;
}
if ( V_22 -> V_212 ) {
if ( V_22 -> V_31 != V_222 ) {
V_189 = - V_191 ;
goto V_208;
}
} else if ( V_22 -> V_31 != V_222 ) {
F_96 ( V_15 , & V_224 -> V_181 , V_222 , 0 , NULL , 0 ) ;
F_117 ( V_15 , & V_224 -> V_181 , V_22 -> V_31 , 0 ,
NULL , 0 ) ;
V_22 -> V_31 = V_222 ;
}
V_225 = F_104 ( V_22 -> V_212 ) ;
if ( ! V_221 ) {
if ( ! V_225 )
goto V_208;
V_183 = ! 0 ;
for ( V_134 = 0 ; V_134 < V_225 -> V_214 ; V_134 ++ ) {
V_183 = memcmp ( & V_225 -> V_215 [ V_134 ] , & V_224 -> V_228 ,
sizeof( T_1 ) ) ;
if ( V_183 == 0 )
break;
}
if ( V_183 )
goto V_208;
if ( V_225 -> V_214 == 1 && V_222 == V_32 ) {
V_226 = 1 ;
goto V_208;
}
F_117 ( V_15 , & V_224 -> V_181 , V_222 , 1 ,
& V_224 -> V_228 , 1 ) ;
for ( V_199 = V_134 + 1 ; V_199 < V_225 -> V_214 ; V_199 ++ )
V_225 -> V_215 [ V_199 - 1 ] = V_225 -> V_215 [ V_199 ] ;
V_225 -> V_214 -- ;
V_189 = 0 ;
goto V_208;
}
if ( V_225 && V_225 -> V_214 >= V_229 ) {
V_189 = - V_193 ;
goto V_208;
}
if ( ! V_225 || V_225 -> V_214 == V_225 -> V_216 ) {
struct V_213 * V_230 ;
int V_207 = V_231 ;
if ( V_225 )
V_207 += V_225 -> V_216 ;
V_230 = F_127 ( V_202 , F_131 ( V_207 ) , V_164 ) ;
if ( ! V_230 ) {
V_189 = - V_193 ;
goto V_208;
}
V_230 -> V_216 = V_207 ;
V_230 -> V_214 = V_207 - V_231 ;
if ( V_225 ) {
for ( V_134 = 0 ; V_134 < V_225 -> V_214 ; V_134 ++ )
V_230 -> V_215 [ V_134 ] = V_225 -> V_215 [ V_134 ] ;
F_130 ( F_131 ( V_225 -> V_216 ) , & V_202 -> V_217 ) ;
F_4 ( V_225 , V_5 ) ;
}
F_100 ( V_22 -> V_212 , V_230 ) ;
V_225 = V_230 ;
}
V_183 = 1 ;
for ( V_134 = 0 ; V_134 < V_225 -> V_214 ; V_134 ++ ) {
V_183 = memcmp ( & V_225 -> V_215 [ V_134 ] , & V_224 -> V_228 ,
sizeof( T_1 ) ) ;
if ( V_183 == 0 )
break;
}
if ( V_183 == 0 )
goto V_208;
for ( V_199 = V_225 -> V_214 - 1 ; V_199 >= V_134 ; V_199 -- )
V_225 -> V_215 [ V_199 + 1 ] = V_225 -> V_215 [ V_199 ] ;
V_225 -> V_215 [ V_134 ] = V_224 -> V_228 ;
V_225 -> V_214 ++ ;
V_189 = 0 ;
F_96 ( V_15 , & V_224 -> V_181 , V_222 , 1 ,
& V_224 -> V_228 , 1 ) ;
V_208:
F_128 () ;
if ( V_226 )
return F_132 ( V_202 , & V_176 ) ;
return V_189 ;
}
int F_134 ( struct V_201 * V_202 , struct V_232 * V_233 , int V_62 )
{
int V_189 = 0 ;
struct V_175 V_176 ;
T_1 V_161 = V_233 -> V_234 ;
struct V_203 * V_22 ;
struct V_14 * V_15 ;
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_213 * V_230 , * V_225 ;
struct V_55 * V_55 = F_124 ( V_202 ) ;
int V_226 = 0 ;
if ( ! F_125 ( V_161 ) )
return - V_191 ;
if ( V_233 -> V_235 != V_32 &&
V_233 -> V_235 != V_35 )
return - V_191 ;
F_126 () ;
V_176 . V_181 . V_180 = V_233 -> V_234 ;
V_176 . V_179 . V_180 = V_233 -> V_236 ;
V_176 . V_178 = V_62 ;
V_15 = F_111 ( V_55 , & V_176 ) ;
if ( ! V_15 ) {
V_189 = - V_190 ;
goto V_208;
}
if ( V_233 -> V_235 == V_32 && V_233 -> V_237 == 0 ) {
V_226 = 1 ;
goto V_208;
}
F_95 (inet, pmc) {
if ( V_22 -> V_210 . V_181 . V_180 == V_233 -> V_234 &&
V_22 -> V_210 . V_178 == V_176 . V_178 )
break;
}
if ( ! V_22 ) {
V_189 = - V_191 ;
goto V_208;
}
if ( V_233 -> V_237 ) {
V_230 = F_127 ( V_202 , F_131 ( V_233 -> V_237 ) ,
V_164 ) ;
if ( ! V_230 ) {
V_189 = - V_193 ;
goto V_208;
}
V_230 -> V_216 = V_230 -> V_214 = V_233 -> V_237 ;
memcpy ( V_230 -> V_215 , V_233 -> V_238 ,
V_233 -> V_237 * sizeof( V_233 -> V_238 [ 0 ] ) ) ;
V_189 = F_96 ( V_15 , & V_233 -> V_234 ,
V_233 -> V_235 , V_230 -> V_214 , V_230 -> V_215 , 0 ) ;
if ( V_189 ) {
F_135 ( V_202 , V_230 , F_131 ( V_230 -> V_216 ) ) ;
goto V_208;
}
} else {
V_230 = NULL ;
( void ) F_96 ( V_15 , & V_233 -> V_234 ,
V_233 -> V_235 , 0 , NULL , 0 ) ;
}
V_225 = F_104 ( V_22 -> V_212 ) ;
if ( V_225 ) {
( void ) F_117 ( V_15 , & V_233 -> V_234 , V_22 -> V_31 ,
V_225 -> V_214 , V_225 -> V_215 , 0 ) ;
F_130 ( F_131 ( V_225 -> V_216 ) , & V_202 -> V_217 ) ;
F_4 ( V_225 , V_5 ) ;
} else
( void ) F_117 ( V_15 , & V_233 -> V_234 , V_22 -> V_31 ,
0 , NULL , 0 ) ;
F_100 ( V_22 -> V_212 , V_230 ) ;
V_22 -> V_31 = V_233 -> V_235 ;
V_189 = 0 ;
V_208:
F_128 () ;
if ( V_226 )
V_189 = F_132 ( V_202 , & V_176 ) ;
return V_189 ;
}
int F_136 ( struct V_201 * V_202 , struct V_232 * V_233 ,
struct V_232 T_4 * V_239 , int T_4 * V_240 )
{
int V_189 , V_135 , V_207 , V_241 ;
struct V_175 V_176 ;
T_1 V_161 = V_233 -> V_234 ;
struct V_203 * V_22 ;
struct V_14 * V_15 ;
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_213 * V_225 ;
struct V_55 * V_55 = F_124 ( V_202 ) ;
if ( ! F_125 ( V_161 ) )
return - V_191 ;
F_126 () ;
V_176 . V_181 . V_180 = V_233 -> V_234 ;
V_176 . V_179 . V_180 = V_233 -> V_236 ;
V_176 . V_178 = 0 ;
V_15 = F_111 ( V_55 , & V_176 ) ;
if ( ! V_15 ) {
V_189 = - V_190 ;
goto V_208;
}
V_189 = - V_220 ;
F_95 (inet, pmc) {
if ( V_22 -> V_210 . V_181 . V_180 == V_233 -> V_234 &&
V_22 -> V_210 . V_178 == V_176 . V_178 )
break;
}
if ( ! V_22 )
goto V_208;
V_233 -> V_235 = V_22 -> V_31 ;
V_225 = F_104 ( V_22 -> V_212 ) ;
F_128 () ;
if ( ! V_225 ) {
V_135 = 0 ;
V_207 = 0 ;
} else {
V_207 = V_225 -> V_214 ;
}
V_241 = V_207 < V_233 -> V_237 ? V_207 : V_233 -> V_237 ;
V_135 = V_241 * sizeof( V_225 -> V_215 [ 0 ] ) ;
V_233 -> V_237 = V_207 ;
if ( F_137 ( F_138 ( V_241 ) , V_240 ) ||
F_139 ( V_239 , V_233 , F_138 ( 0 ) ) ) {
return - V_242 ;
}
if ( V_135 &&
F_139 ( & V_239 -> V_238 [ 0 ] , V_225 -> V_215 , V_135 ) )
return - V_242 ;
return 0 ;
V_208:
F_128 () ;
return V_189 ;
}
int F_140 ( struct V_201 * V_202 , struct V_243 * V_244 ,
struct V_243 T_4 * V_239 , int T_4 * V_240 )
{
int V_189 , V_134 , V_207 , V_241 ;
struct V_245 * V_246 ;
T_1 V_161 ;
struct V_203 * V_22 ;
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_213 * V_225 ;
V_246 = (struct V_245 * ) & V_244 -> V_247 ;
if ( V_246 -> V_248 != V_249 )
return - V_191 ;
V_161 = V_246 -> V_250 . V_180 ;
if ( ! F_125 ( V_161 ) )
return - V_191 ;
F_126 () ;
V_189 = - V_220 ;
F_95 (inet, pmc) {
if ( V_22 -> V_210 . V_181 . V_180 == V_161 &&
V_22 -> V_210 . V_178 == V_244 -> V_251 )
break;
}
if ( ! V_22 )
goto V_208;
V_244 -> V_252 = V_22 -> V_31 ;
V_225 = F_104 ( V_22 -> V_212 ) ;
F_128 () ;
V_207 = V_225 ? V_225 -> V_214 : 0 ;
V_241 = V_207 < V_244 -> V_253 ? V_207 : V_244 -> V_253 ;
V_244 -> V_253 = V_207 ;
if ( F_137 ( F_141 ( V_241 ) , V_240 ) ||
F_139 ( V_239 , V_244 , F_141 ( 0 ) ) ) {
return - V_242 ;
}
for ( V_134 = 0 ; V_134 < V_241 ; V_134 ++ ) {
struct V_254 V_255 ;
V_246 = (struct V_245 * ) & V_255 ;
memset ( & V_255 , 0 , sizeof( V_255 ) ) ;
V_246 -> V_248 = V_249 ;
V_246 -> V_250 . V_180 = V_225 -> V_215 [ V_134 ] ;
if ( F_139 ( & V_239 -> V_256 [ V_134 ] , & V_255 , sizeof( V_255 ) ) )
return - V_242 ;
}
return 0 ;
V_208:
F_128 () ;
return V_189 ;
}
int F_142 ( struct V_201 * V_202 , T_1 V_257 , T_1 V_258 , int V_259 )
{
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_203 * V_22 ;
struct V_213 * V_225 ;
int V_134 ;
int V_219 ;
V_219 = 1 ;
if ( ! F_125 ( V_257 ) )
goto V_170;
F_49 () ;
F_50 (inet, pmc) {
if ( V_22 -> V_210 . V_181 . V_180 == V_257 &&
V_22 -> V_210 . V_178 == V_259 )
break;
}
V_219 = V_206 -> V_260 ;
if ( ! V_22 )
goto V_261;
V_225 = F_143 ( V_22 -> V_212 ) ;
V_219 = ( V_22 -> V_31 == V_35 ) ;
if ( ! V_225 )
goto V_261;
for ( V_134 = 0 ; V_134 < V_225 -> V_214 ; V_134 ++ ) {
if ( V_225 -> V_215 [ V_134 ] == V_258 )
break;
}
V_219 = 0 ;
if ( V_22 -> V_31 == V_32 && V_134 >= V_225 -> V_214 )
goto V_261;
if ( V_22 -> V_31 == V_35 && V_134 < V_225 -> V_214 )
goto V_261;
V_219 = 1 ;
V_261:
F_51 () ;
V_170:
return V_219 ;
}
void F_144 ( struct V_201 * V_202 )
{
struct V_205 * V_206 = F_123 ( V_202 ) ;
struct V_203 * V_204 ;
struct V_55 * V_55 = F_124 ( V_202 ) ;
if ( V_206 -> V_172 == NULL )
return;
F_126 () ;
while ( ( V_204 = F_104 ( V_206 -> V_172 ) ) != NULL ) {
struct V_14 * V_15 ;
V_206 -> V_172 = V_204 -> V_171 ;
V_15 = F_112 ( V_55 , V_204 -> V_210 . V_178 ) ;
( void ) F_129 ( V_202 , V_204 , V_15 ) ;
if ( V_15 != NULL )
F_103 ( V_15 , V_204 -> V_210 . V_181 . V_180 ) ;
F_130 ( sizeof( * V_204 ) , & V_202 -> V_217 ) ;
F_4 ( V_204 , V_5 ) ;
}
F_128 () ;
}
int F_145 ( struct V_14 * V_15 , T_1 V_262 , T_1 V_263 , T_5 V_264 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_183 = 0 ;
F_50 (in_dev, im) {
if ( V_2 -> V_97 == V_262 )
break;
}
if ( V_2 && V_264 == V_61 ) {
V_183 = 1 ;
} else if ( V_2 ) {
if ( V_263 ) {
for ( V_24 = V_2 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_109 == V_263 )
break;
}
if ( V_24 )
V_183 = V_24 -> V_33 [ V_32 ] ||
V_24 -> V_33 [ V_35 ] !=
V_2 -> V_34 [ V_35 ] ;
else
V_183 = V_2 -> V_34 [ V_35 ] != 0 ;
} else
V_183 = 1 ;
}
return V_183 ;
}
static inline struct V_1 * F_146 ( struct V_265 * V_266 )
{
struct V_55 * V_55 = F_147 ( V_266 ) ;
struct V_1 * V_2 = NULL ;
struct V_267 * V_268 = F_148 ( V_266 ) ;
V_268 -> V_15 = NULL ;
F_149 (net, state->dev) {
struct V_14 * V_15 ;
V_15 = F_74 ( V_268 -> V_46 ) ;
if ( ! V_15 )
continue;
V_2 = F_143 ( V_15 -> V_172 ) ;
if ( V_2 ) {
V_268 -> V_15 = V_15 ;
break;
}
}
return V_2 ;
}
static struct V_1 * F_150 ( struct V_265 * V_266 , struct V_1 * V_2 )
{
struct V_267 * V_268 = F_148 ( V_266 ) ;
V_2 = F_143 ( V_2 -> V_171 ) ;
while ( ! V_2 ) {
V_268 -> V_46 = F_151 ( V_268 -> V_46 ) ;
if ( ! V_268 -> V_46 ) {
V_268 -> V_15 = NULL ;
break;
}
V_268 -> V_15 = F_74 ( V_268 -> V_46 ) ;
if ( ! V_268 -> V_15 )
continue;
V_2 = F_143 ( V_268 -> V_15 -> V_172 ) ;
}
return V_2 ;
}
static struct V_1 * F_152 ( struct V_265 * V_266 , T_6 V_269 )
{
struct V_1 * V_2 = F_146 ( V_266 ) ;
if ( V_2 )
while ( V_269 && ( V_2 = F_150 ( V_266 , V_2 ) ) != NULL )
-- V_269 ;
return V_269 ? NULL : V_2 ;
}
static void * F_153 ( struct V_265 * V_266 , T_6 * V_269 )
__acquires( V_5 )
{
F_49 () ;
return * V_269 ? F_152 ( V_266 , * V_269 - 1 ) : V_270 ;
}
static void * F_154 ( struct V_265 * V_266 , void * V_271 , T_6 * V_269 )
{
struct V_1 * V_2 ;
if ( V_271 == V_270 )
V_2 = F_146 ( V_266 ) ;
else
V_2 = F_150 ( V_266 , V_271 ) ;
++ * V_269 ;
return V_2 ;
}
static void F_155 ( struct V_265 * V_266 , void * V_271 )
__releases( V_5 )
{
struct V_267 * V_268 = F_148 ( V_266 ) ;
V_268 -> V_15 = NULL ;
V_268 -> V_46 = NULL ;
F_51 () ;
}
static int F_156 ( struct V_265 * V_266 , void * V_271 )
{
if ( V_271 == V_270 )
F_157 ( V_266 ,
L_1 ) ;
else {
struct V_1 * V_2 = (struct V_1 * ) V_271 ;
struct V_267 * V_268 = F_148 ( V_266 ) ;
char * V_272 ;
#ifdef F_91
V_272 = F_60 ( V_268 -> V_15 ) ? L_2 :
F_61 ( V_268 -> V_15 ) ? L_3 :
L_4 ;
#else
V_272 = L_5 ;
#endif
if ( F_143 ( V_268 -> V_15 -> V_172 ) == V_2 ) {
F_158 ( V_266 , L_6 ,
V_268 -> V_46 -> V_62 , V_268 -> V_46 -> V_273 , V_268 -> V_15 -> V_173 , V_272 ) ;
}
F_158 ( V_266 ,
L_7 ,
V_2 -> V_97 , V_2 -> V_169 ,
V_2 -> V_8 , V_2 -> V_8 ?
F_159 ( V_2 -> V_7 . V_21 - V_13 ) : 0 ,
V_2 -> V_9 ) ;
}
return 0 ;
}
static int F_160 ( struct V_274 * V_274 , struct V_275 * V_275 )
{
return F_161 ( V_274 , V_275 , & V_276 ,
sizeof( struct V_267 ) ) ;
}
static inline struct V_23 * F_162 ( struct V_265 * V_266 )
{
struct V_55 * V_55 = F_147 ( V_266 ) ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_277 * V_268 = F_163 ( V_266 ) ;
V_268 -> V_177 = NULL ;
V_268 -> V_2 = NULL ;
F_149 (net, state->dev) {
struct V_14 * V_177 ;
V_177 = F_74 ( V_268 -> V_46 ) ;
if ( F_164 ( V_177 == NULL ) )
continue;
V_2 = F_143 ( V_177 -> V_172 ) ;
if ( F_165 ( V_2 != NULL ) ) {
F_6 ( & V_2 -> V_6 ) ;
V_24 = V_2 -> V_42 ;
if ( F_165 ( V_24 != NULL ) ) {
V_268 -> V_2 = V_2 ;
V_268 -> V_177 = V_177 ;
break;
}
F_9 ( & V_2 -> V_6 ) ;
}
}
return V_24 ;
}
static struct V_23 * F_166 ( struct V_265 * V_266 , struct V_23 * V_24 )
{
struct V_277 * V_268 = F_163 ( V_266 ) ;
V_24 = V_24 -> V_43 ;
while ( ! V_24 ) {
F_9 ( & V_268 -> V_2 -> V_6 ) ;
V_268 -> V_2 = V_268 -> V_2 -> V_117 ;
while ( ! V_268 -> V_2 ) {
V_268 -> V_46 = F_151 ( V_268 -> V_46 ) ;
if ( ! V_268 -> V_46 ) {
V_268 -> V_177 = NULL ;
goto V_170;
}
V_268 -> V_177 = F_74 ( V_268 -> V_46 ) ;
if ( ! V_268 -> V_177 )
continue;
V_268 -> V_2 = F_143 ( V_268 -> V_177 -> V_172 ) ;
}
if ( ! V_268 -> V_2 )
break;
F_6 ( & V_268 -> V_2 -> V_6 ) ;
V_24 = V_268 -> V_2 -> V_42 ;
}
V_170:
return V_24 ;
}
static struct V_23 * F_167 ( struct V_265 * V_266 , T_6 V_269 )
{
struct V_23 * V_24 = F_162 ( V_266 ) ;
if ( V_24 )
while ( V_269 && ( V_24 = F_166 ( V_266 , V_24 ) ) != NULL )
-- V_269 ;
return V_269 ? NULL : V_24 ;
}
static void * F_168 ( struct V_265 * V_266 , T_6 * V_269 )
__acquires( V_5 )
{
F_49 () ;
return * V_269 ? F_167 ( V_266 , * V_269 - 1 ) : V_270 ;
}
static void * F_169 ( struct V_265 * V_266 , void * V_271 , T_6 * V_269 )
{
struct V_23 * V_24 ;
if ( V_271 == V_270 )
V_24 = F_162 ( V_266 ) ;
else
V_24 = F_166 ( V_266 , V_271 ) ;
++ * V_269 ;
return V_24 ;
}
static void F_170 ( struct V_265 * V_266 , void * V_271 )
__releases( V_5 )
{
struct V_277 * V_268 = F_163 ( V_266 ) ;
if ( F_165 ( V_268 -> V_2 != NULL ) ) {
F_9 ( & V_268 -> V_2 -> V_6 ) ;
V_268 -> V_2 = NULL ;
}
V_268 -> V_177 = NULL ;
V_268 -> V_46 = NULL ;
F_51 () ;
}
static int F_171 ( struct V_265 * V_266 , void * V_271 )
{
struct V_23 * V_24 = (struct V_23 * ) V_271 ;
struct V_277 * V_268 = F_163 ( V_266 ) ;
if ( V_271 == V_270 ) {
F_158 ( V_266 ,
L_8
L_9 , L_10 ,
L_11 , L_12 ,
L_13 , L_14 , L_15 ) ;
} else {
F_158 ( V_266 ,
L_16
L_17 ,
V_268 -> V_46 -> V_62 , V_268 -> V_46 -> V_273 ,
F_172 ( V_268 -> V_2 -> V_97 ) ,
F_172 ( V_24 -> V_109 ) ,
V_24 -> V_33 [ V_32 ] ,
V_24 -> V_33 [ V_35 ] ) ;
}
return 0 ;
}
static int F_173 ( struct V_274 * V_274 , struct V_275 * V_275 )
{
return F_161 ( V_274 , V_275 , & V_278 ,
sizeof( struct V_277 ) ) ;
}
static int T_7 F_174 ( struct V_55 * V_55 )
{
struct V_279 * V_280 ;
V_280 = F_175 ( V_55 , L_18 , V_281 , & V_282 ) ;
if ( ! V_280 )
goto V_283;
V_280 = F_175 ( V_55 , L_19 , V_281 , & V_284 ) ;
if ( ! V_280 )
goto V_285;
return 0 ;
V_285:
F_176 ( V_55 , L_18 ) ;
V_283:
return - V_286 ;
}
static void T_8 F_177 ( struct V_55 * V_55 )
{
F_176 ( V_55 , L_19 ) ;
F_176 ( V_55 , L_18 ) ;
}
int T_9 F_178 ( void )
{
return F_179 ( & V_287 ) ;
}
