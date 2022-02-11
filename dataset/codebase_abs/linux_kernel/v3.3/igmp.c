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
int V_58 = F_23 ( V_46 ) ;
int V_59 = V_46 -> V_60 ;
while ( 1 ) {
V_48 = F_24 ( V_47 + V_58 + V_59 ,
V_61 | V_62 ) ;
if ( V_48 )
break;
V_47 >>= 1 ;
if ( V_47 < 256 )
return NULL ;
}
F_25 ( V_48 ) = V_47 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_63 , 0 ,
0 , 0 ,
V_64 , 0 , V_46 -> V_65 ) ;
if ( F_27 ( V_50 ) ) {
F_28 ( V_48 ) ;
return NULL ;
}
F_29 ( V_48 , & V_50 -> V_66 ) ;
V_48 -> V_46 = V_46 ;
F_30 ( V_48 , V_58 ) ;
F_31 ( V_48 ) ;
V_52 = F_32 ( V_48 ) ;
F_33 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_52 -> V_67 = 4 ;
V_52 -> V_68 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_52 -> V_69 = 0xc0 ;
V_52 -> V_70 = F_34 ( V_71 ) ;
V_52 -> V_72 = 1 ;
V_52 -> V_73 = V_57 . V_73 ;
V_52 -> V_74 = V_57 . V_74 ;
V_52 -> V_75 = V_64 ;
V_52 -> V_76 = 0 ;
F_35 ( V_52 , & V_50 -> V_66 , NULL ) ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 0 ] = V_78 ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 1 ] = 4 ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 2 ] = 0 ;
( ( V_77 * ) & V_52 [ 1 ] ) [ 3 ] = 0 ;
V_48 -> V_79 = V_48 -> V_80 + sizeof( struct V_51 ) + 4 ;
F_33 ( V_48 , sizeof( * V_54 ) ) ;
V_54 = F_36 ( V_48 ) ;
V_54 -> type = V_81 ;
V_54 -> V_82 = 0 ;
V_54 -> V_83 = 0 ;
V_54 -> V_84 = 0 ;
V_54 -> V_85 = 0 ;
return V_48 ;
}
static int F_37 ( struct V_44 * V_48 )
{
struct V_86 * V_54 = F_38 ( V_48 ) ;
const int V_87 = V_48 -> V_88 - V_48 -> V_79 ;
V_54 -> V_83 = F_39 ( F_38 ( V_48 ) , V_87 ) ;
return F_40 ( V_48 ) ;
}
static int F_41 ( struct V_1 * V_22 , int type , int V_89 , int V_90 )
{
return sizeof( struct V_91 ) + 4 * F_20 ( V_22 , type , V_89 , V_90 ) ;
}
static struct V_44 * F_42 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , struct V_91 * * V_92 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_93 ;
struct V_91 * V_94 ;
if ( ! V_48 )
V_48 = F_21 ( V_46 , V_46 -> V_95 ) ;
if ( ! V_48 )
return NULL ;
V_94 = (struct V_91 * ) F_33 ( V_48 , sizeof( struct V_91 ) ) ;
V_94 -> V_96 = type ;
V_94 -> V_97 = 0 ;
V_94 -> V_98 = 0 ;
V_94 -> V_99 = V_22 -> V_100 ;
V_93 = F_36 ( V_48 ) ;
V_93 -> V_85 = F_34 ( F_43 ( V_93 -> V_85 ) + 1 ) ;
* V_92 = V_94 ;
return V_48 ;
}
static struct V_44 * F_44 ( struct V_44 * V_48 , struct V_1 * V_22 ,
int type , int V_25 , int V_26 )
{
struct V_45 * V_46 = V_22 -> V_4 -> V_46 ;
struct V_53 * V_93 ;
struct V_91 * V_94 = NULL ;
struct V_23 * V_24 , * V_101 , * V_102 , * * V_103 ;
int V_41 , V_104 , V_105 , V_106 , V_107 ;
if ( V_22 -> V_100 == V_108 )
return V_48 ;
V_106 = type == V_27 ||
type == V_28 ;
V_107 = type == V_28 ||
type == V_37 ;
V_104 = V_41 = 0 ;
V_103 = V_26 ? & V_22 -> V_109 : & V_22 -> V_42 ;
if ( ! * V_103 )
goto V_110;
V_93 = V_48 ? F_36 ( V_48 ) : NULL ;
if ( V_107 ) {
if ( V_93 && V_93 -> V_85 &&
F_45 ( V_48 ) < F_41 ( V_22 , type , V_25 , V_26 ) ) {
if ( V_48 )
F_37 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_95 ) ;
}
}
V_105 = 1 ;
V_102 = NULL ;
for ( V_24 = * V_103 ; V_24 ; V_24 = V_101 ) {
T_1 * V_111 ;
V_101 = V_24 -> V_43 ;
if ( ! F_19 ( V_22 , V_24 , type , V_25 , V_26 ) ) {
V_102 = V_24 ;
continue;
}
if ( V_106 )
V_24 -> V_30 = 0 ;
if ( F_45 ( V_48 ) < sizeof( T_1 ) +
V_105 * sizeof( struct V_91 ) ) {
if ( V_107 && ! V_105 )
break;
if ( V_94 )
V_94 -> V_98 = F_34 ( V_41 ) ;
if ( V_48 )
F_37 ( V_48 ) ;
V_48 = F_21 ( V_46 , V_46 -> V_95 ) ;
V_105 = 1 ;
V_41 = 0 ;
}
if ( V_105 ) {
V_48 = F_42 ( V_48 , V_22 , type , & V_94 ) ;
V_105 = 0 ;
}
if ( ! V_48 )
return NULL ;
V_111 = ( T_1 * ) F_33 ( V_48 , sizeof( T_1 ) ) ;
* V_111 = V_24 -> V_112 ;
V_41 ++ ; V_104 ++ ;
if ( ( type == V_38 ||
type == V_40 ) && V_24 -> V_39 ) {
V_24 -> V_39 -- ;
if ( ( V_26 || V_25 ) && V_24 -> V_39 == 0 ) {
if ( V_102 )
V_102 -> V_43 = V_24 -> V_43 ;
else
* V_103 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
continue;
}
}
V_102 = V_24 ;
}
V_110:
if ( ! V_104 ) {
if ( type == V_38 ||
type == V_40 )
return V_48 ;
if ( V_22 -> V_113 || V_106 ) {
if ( V_48 && F_45 ( V_48 ) < sizeof( struct V_91 ) ) {
F_37 ( V_48 ) ;
V_48 = NULL ;
}
V_48 = F_42 ( V_48 , V_22 , type , & V_94 ) ;
}
}
if ( V_94 )
V_94 -> V_98 = F_34 ( V_41 ) ;
if ( V_106 )
V_22 -> V_29 = 0 ;
return V_48 ;
}
static int F_47 ( struct V_14 * V_15 , struct V_1 * V_22 )
{
struct V_44 * V_48 = NULL ;
int type ;
if ( ! V_22 ) {
F_48 () ;
F_49 (in_dev, pmc) {
if ( V_22 -> V_100 == V_108 )
continue;
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
F_50 () ;
} else {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] )
type = V_28 ;
else
type = V_27 ;
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
F_9 ( & V_22 -> V_6 ) ;
}
if ( ! V_48 )
return 0 ;
return F_37 ( V_48 ) ;
}
static void F_51 ( struct V_23 * * V_114 )
{
struct V_23 * V_102 , * V_101 , * V_24 ;
V_102 = NULL ;
for ( V_24 = * V_114 ; V_24 ; V_24 = V_101 ) {
V_101 = V_24 -> V_43 ;
if ( V_24 -> V_39 == 0 ) {
if ( V_102 )
V_102 -> V_43 = V_24 -> V_43 ;
else
* V_114 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
} else
V_102 = V_24 ;
}
}
static void F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_115 , * V_116 ;
struct V_44 * V_48 = NULL ;
int type , V_117 ;
F_48 () ;
F_6 ( & V_15 -> V_118 ) ;
V_115 = NULL ;
for ( V_22 = V_15 -> V_119 ; V_22 ; V_22 = V_116 ) {
V_116 = V_22 -> V_120 ;
if ( V_22 -> V_31 == V_32 ) {
type = V_40 ;
V_117 = V_40 ;
V_48 = F_44 ( V_48 , V_22 , type , 1 , 0 ) ;
V_48 = F_44 ( V_48 , V_22 , V_117 , 1 , 1 ) ;
}
if ( V_22 -> V_113 ) {
if ( V_22 -> V_31 == V_35 ) {
type = V_36 ;
V_48 = F_44 ( V_48 , V_22 , type , 1 , 0 ) ;
}
V_22 -> V_113 -- ;
if ( V_22 -> V_113 == 0 ) {
F_51 ( & V_22 -> V_109 ) ;
F_51 ( & V_22 -> V_42 ) ;
}
}
if ( V_22 -> V_113 == 0 && ! V_22 -> V_109 && ! V_22 -> V_42 ) {
if ( V_115 )
V_115 -> V_120 = V_116 ;
else
V_15 -> V_119 = V_116 ;
F_3 ( V_22 -> V_4 ) ;
F_46 ( V_22 ) ;
} else
V_115 = V_22 ;
}
F_9 ( & V_15 -> V_118 ) ;
F_49 (in_dev, pmc) {
F_6 ( & V_22 -> V_6 ) ;
if ( V_22 -> V_34 [ V_35 ] ) {
type = V_40 ;
V_117 = V_38 ;
} else {
type = V_38 ;
V_117 = V_40 ;
}
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
V_48 = F_44 ( V_48 , V_22 , V_117 , 0 , 1 ) ;
if ( V_22 -> V_113 ) {
if ( V_22 -> V_31 == V_35 )
type = V_37 ;
else
type = V_36 ;
V_48 = F_44 ( V_48 , V_22 , type , 0 , 0 ) ;
V_22 -> V_113 -- ;
}
F_9 ( & V_22 -> V_6 ) ;
}
F_50 () ;
if ( ! V_48 )
return;
( void ) F_37 ( V_48 ) ;
}
static int F_53 ( struct V_14 * V_15 , struct V_1 * V_22 ,
int type )
{
struct V_44 * V_48 ;
struct V_51 * V_121 ;
struct V_86 * V_122 ;
struct V_49 * V_50 ;
struct V_45 * V_46 = V_15 -> V_46 ;
struct V_55 * V_55 = F_22 ( V_46 ) ;
T_1 V_123 = V_22 ? V_22 -> V_100 : 0 ;
struct V_56 V_57 ;
T_1 V_66 ;
int V_58 , V_59 ;
if ( type == V_81 )
return F_47 ( V_15 , V_22 ) ;
else if ( type == V_124 )
V_66 = V_125 ;
else
V_66 = V_123 ;
V_50 = F_26 ( V_55 , & V_57 , NULL , V_66 , 0 ,
0 , 0 ,
V_64 , 0 , V_46 -> V_65 ) ;
if ( F_27 ( V_50 ) )
return - 1 ;
V_58 = F_23 ( V_46 ) ;
V_59 = V_46 -> V_60 ;
V_48 = F_24 ( V_126 + V_58 + V_59 , V_61 ) ;
if ( V_48 == NULL ) {
F_54 ( V_50 ) ;
return - 1 ;
}
F_29 ( V_48 , & V_50 -> V_66 ) ;
F_30 ( V_48 , V_58 ) ;
F_31 ( V_48 ) ;
V_121 = F_32 ( V_48 ) ;
F_33 ( V_48 , sizeof( struct V_51 ) + 4 ) ;
V_121 -> V_67 = 4 ;
V_121 -> V_68 = ( sizeof( struct V_51 ) + 4 ) >> 2 ;
V_121 -> V_69 = 0xc0 ;
V_121 -> V_70 = F_34 ( V_71 ) ;
V_121 -> V_72 = 1 ;
V_121 -> V_73 = V_66 ;
V_121 -> V_74 = V_57 . V_74 ;
V_121 -> V_75 = V_64 ;
F_35 ( V_121 , & V_50 -> V_66 , NULL ) ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 0 ] = V_78 ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 1 ] = 4 ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 2 ] = 0 ;
( ( V_77 * ) & V_121 [ 1 ] ) [ 3 ] = 0 ;
V_122 = (struct V_86 * ) F_33 ( V_48 , sizeof( struct V_86 ) ) ;
V_122 -> type = type ;
V_122 -> V_127 = 0 ;
V_122 -> V_83 = 0 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_83 = F_39 ( ( void * ) V_122 , sizeof( struct V_86 ) ) ;
return F_40 ( V_48 ) ;
}
static void F_55 ( unsigned long V_128 )
{
struct V_14 * V_15 = (struct V_14 * ) V_128 ;
V_15 -> V_17 = 0 ;
F_47 ( V_15 , NULL ) ;
F_56 ( V_15 ) ;
}
static void F_57 ( unsigned long V_128 )
{
struct V_14 * V_15 = (struct V_14 * ) V_128 ;
F_52 ( V_15 ) ;
if ( V_15 -> V_129 ) {
V_15 -> V_129 -- ;
F_16 ( V_15 , V_130 ) ;
}
F_56 ( V_15 ) ;
}
static void F_58 ( struct V_14 * V_15 )
{
if ( F_59 ( V_15 ) || F_60 ( V_15 ) )
return;
V_15 -> V_129 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
F_16 ( V_15 , 1 ) ;
}
static void F_61 ( unsigned long V_128 )
{
struct V_1 * V_2 = (struct V_1 * ) V_128 ;
struct V_14 * V_15 = V_2 -> V_4 ;
F_62 ( & V_2 -> V_6 ) ;
V_2 -> V_8 = 0 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 -- ;
F_10 ( V_2 , V_130 ) ;
}
V_2 -> V_9 = 1 ;
F_63 ( & V_2 -> V_6 ) ;
if ( F_59 ( V_15 ) )
F_53 ( V_15 , V_2 , V_133 ) ;
else if ( F_60 ( V_15 ) )
F_53 ( V_15 , V_2 , V_134 ) ;
else
F_53 ( V_15 , V_2 , V_81 ) ;
F_1 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_22 , int V_135 , T_1 * V_136 )
{
struct V_23 * V_24 ;
int V_137 , V_41 ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_135 )
break;
for ( V_137 = 0 ; V_137 < V_135 ; V_137 ++ ) {
if ( V_24 -> V_33 [ V_32 ] ||
V_22 -> V_34 [ V_35 ] !=
V_24 -> V_33 [ V_35 ] )
continue;
if ( V_136 [ V_137 ] == V_24 -> V_112 ) {
V_41 ++ ;
break;
}
}
}
V_22 -> V_29 = 0 ;
if ( V_41 == V_135 )
return 0 ;
return 1 ;
}
static int F_65 ( struct V_1 * V_22 , int V_135 , T_1 * V_136 )
{
struct V_23 * V_24 ;
int V_137 , V_41 ;
if ( V_22 -> V_31 == V_35 )
return F_64 ( V_22 , V_135 , V_136 ) ;
V_41 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_41 == V_135 )
break;
for ( V_137 = 0 ; V_137 < V_135 ; V_137 ++ )
if ( V_136 [ V_137 ] == V_24 -> V_112 ) {
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
static void F_66 ( struct V_14 * V_15 , T_1 V_123 )
{
struct V_1 * V_2 ;
if ( V_123 == V_108 )
return;
F_48 () ;
F_49 (in_dev, im) {
if ( V_2 -> V_100 == V_123 ) {
F_5 ( V_2 ) ;
break;
}
}
F_50 () ;
}
static void F_67 ( struct V_14 * V_15 , struct V_44 * V_48 ,
int V_138 )
{
struct V_86 * V_122 = F_38 ( V_48 ) ;
struct V_139 * V_140 = F_68 ( V_48 ) ;
struct V_1 * V_2 ;
T_1 V_123 = V_122 -> V_123 ;
int V_11 ;
int V_141 = 0 ;
if ( V_138 == 8 ) {
if ( V_122 -> V_127 == 0 ) {
V_11 = V_142 ;
V_15 -> V_143 = V_13 +
V_144 ;
V_123 = 0 ;
} else {
V_11 = V_122 -> V_127 * ( V_145 / V_146 ) ;
V_15 -> V_147 = V_13 +
V_148 ;
}
V_15 -> V_129 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_56 ( V_15 ) ;
F_69 ( V_15 ) ;
} else if ( V_138 < 12 ) {
return;
} else if ( F_59 ( V_15 ) ) {
V_11 = V_142 ;
V_123 = 0 ;
} else if ( F_60 ( V_15 ) ) {
V_11 = F_70 ( V_140 -> V_127 ) * ( V_145 / V_146 ) ;
if ( ! V_11 )
V_11 = 1 ;
} else {
if ( ! F_71 ( V_48 , sizeof( struct V_139 ) ) )
return;
V_140 = F_68 ( V_48 ) ;
if ( V_140 -> V_135 ) {
if ( ! F_71 ( V_48 , sizeof( struct V_139 )
+ F_43 ( V_140 -> V_135 ) * sizeof( T_1 ) ) )
return;
V_140 = F_68 ( V_48 ) ;
}
V_11 = F_70 ( V_140 -> V_127 ) * ( V_145 / V_146 ) ;
if ( ! V_11 )
V_11 = 1 ;
V_15 -> V_16 = V_11 ;
if ( V_140 -> V_149 )
V_15 -> V_131 = V_140 -> V_149 ;
if ( ! V_123 ) {
if ( V_140 -> V_135 )
return;
F_14 ( V_15 ) ;
return;
}
V_141 = V_140 -> V_135 != 0 ;
}
F_48 () ;
F_49 (in_dev, im) {
int V_150 ;
if ( V_123 && V_123 != V_2 -> V_100 )
continue;
if ( V_2 -> V_100 == V_108 )
continue;
F_6 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_2 -> V_29 = V_2 -> V_29 && V_141 ;
else
V_2 -> V_29 = V_141 ;
V_150 = ! V_2 -> V_29 ||
F_65 ( V_2 , F_43 ( V_140 -> V_135 ) , V_140 -> V_136 ) ;
F_9 ( & V_2 -> V_6 ) ;
if ( V_150 )
F_17 ( V_2 , V_11 ) ;
}
F_50 () ;
}
int F_72 ( struct V_44 * V_48 )
{
struct V_86 * V_122 ;
struct V_14 * V_15 = F_73 ( V_48 -> V_46 ) ;
int V_138 = V_48 -> V_138 ;
if ( V_15 == NULL )
goto V_151;
if ( ! F_71 ( V_48 , sizeof( struct V_86 ) ) )
goto V_151;
switch ( V_48 -> V_152 ) {
case V_153 :
if ( ! F_74 ( V_48 -> V_83 ) )
break;
case V_154 :
V_48 -> V_83 = 0 ;
if ( F_75 ( V_48 ) )
goto V_151;
}
V_122 = F_38 ( V_48 ) ;
switch ( V_122 -> type ) {
case V_155 :
F_67 ( V_15 , V_48 , V_138 ) ;
break;
case V_133 :
case V_134 :
if ( F_76 ( F_77 ( V_48 ) ) )
break;
if ( V_48 -> V_156 == V_157 ||
V_48 -> V_156 == V_158 )
F_66 ( V_15 , V_122 -> V_123 ) ;
break;
case V_159 :
#ifdef F_78
return F_79 ( V_48 ) ;
#endif
case V_81 :
case V_160 :
case V_161 :
case V_124 :
case V_162 :
case V_163 :
break;
default:
break;
}
V_151:
F_28 ( V_48 ) ;
return 0 ;
}
static void F_80 ( struct V_14 * V_15 , T_1 V_164 )
{
char V_165 [ V_166 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_81 ( V_164 , V_165 , V_46 , 0 ) == 0 )
F_82 ( V_46 , V_165 ) ;
}
static void F_83 ( struct V_14 * V_15 , T_1 V_164 )
{
char V_165 [ V_166 ] ;
struct V_45 * V_46 = V_15 -> V_46 ;
if ( F_81 ( V_164 , V_165 , V_46 , 0 ) == 0 )
F_84 ( V_46 , V_165 ) ;
}
static void F_85 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_1 * V_22 ;
V_22 = F_86 ( sizeof( * V_22 ) , V_167 ) ;
if ( ! V_22 )
return;
F_6 ( & V_2 -> V_6 ) ;
V_22 -> V_4 = V_2 -> V_4 ;
F_15 ( V_15 ) ;
V_22 -> V_100 = V_2 -> V_100 ;
V_22 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_22 -> V_31 = V_2 -> V_31 ;
if ( V_22 -> V_31 == V_32 ) {
struct V_23 * V_24 ;
V_22 -> V_109 = V_2 -> V_109 ;
V_22 -> V_42 = V_2 -> V_42 ;
V_2 -> V_109 = V_2 -> V_42 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = V_22 -> V_113 ;
}
F_9 ( & V_2 -> V_6 ) ;
F_6 ( & V_15 -> V_118 ) ;
V_22 -> V_120 = V_15 -> V_119 ;
V_15 -> V_119 = V_22 ;
F_9 ( & V_15 -> V_118 ) ;
}
static void F_87 ( struct V_14 * V_15 , T_1 V_100 )
{
struct V_1 * V_22 , * V_115 ;
struct V_23 * V_24 , * V_101 ;
F_6 ( & V_15 -> V_118 ) ;
V_115 = NULL ;
for ( V_22 = V_15 -> V_119 ; V_22 ; V_22 = V_22 -> V_120 ) {
if ( V_22 -> V_100 == V_100 )
break;
V_115 = V_22 ;
}
if ( V_22 ) {
if ( V_115 )
V_115 -> V_120 = V_22 -> V_120 ;
else
V_15 -> V_119 = V_22 -> V_120 ;
}
F_9 ( & V_15 -> V_118 ) ;
if ( V_22 ) {
for ( V_24 = V_22 -> V_109 ; V_24 ; V_24 = V_101 ) {
V_101 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
F_3 ( V_22 -> V_4 ) ;
F_46 ( V_22 ) ;
}
}
static void F_69 ( struct V_14 * V_15 )
{
struct V_1 * V_22 , * V_168 ;
F_6 ( & V_15 -> V_118 ) ;
V_22 = V_15 -> V_119 ;
V_15 -> V_119 = NULL ;
F_9 ( & V_15 -> V_118 ) ;
for (; V_22 ; V_22 = V_168 ) {
V_168 = V_22 -> V_120 ;
F_88 ( V_22 ) ;
F_3 ( V_22 -> V_4 ) ;
F_46 ( V_22 ) ;
}
F_48 () ;
F_49 (in_dev, pmc) {
struct V_23 * V_24 , * V_101 ;
F_6 ( & V_22 -> V_6 ) ;
V_24 = V_22 -> V_109 ;
V_22 -> V_109 = NULL ;
F_9 ( & V_22 -> V_6 ) ;
for (; V_24 ; V_24 = V_101 ) {
V_101 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
}
F_50 () ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
#ifdef F_90
int V_9 ;
#endif
if ( V_2 -> V_169 ) {
V_2 -> V_169 = 0 ;
F_83 ( V_15 , V_2 -> V_100 ) ;
}
#ifdef F_90
if ( V_2 -> V_100 == V_108 )
return;
V_9 = V_2 -> V_9 ;
F_5 ( V_2 ) ;
if ( ! V_15 -> V_170 ) {
if ( F_59 ( V_15 ) )
return;
if ( F_60 ( V_15 ) ) {
if ( V_9 )
F_53 ( V_15 , V_2 , V_124 ) ;
return;
}
F_85 ( V_15 , V_2 ) ;
F_58 ( V_15 ) ;
}
#endif
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_4 ;
if ( V_2 -> V_169 == 0 ) {
V_2 -> V_169 = 1 ;
F_80 ( V_15 , V_2 -> V_100 ) ;
}
#ifdef F_90
if ( V_2 -> V_100 == V_108 )
return;
if ( V_15 -> V_170 )
return;
if ( F_59 ( V_15 ) || F_60 ( V_15 ) ) {
F_6 ( & V_2 -> V_6 ) ;
F_10 ( V_2 , V_171 ) ;
F_9 ( & V_2 -> V_6 ) ;
return;
}
V_2 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
F_58 ( V_15 ) ;
#endif
}
void F_92 ( struct V_14 * V_15 , T_1 V_164 )
{
struct V_1 * V_2 ;
F_93 () ;
F_94 (in_dev, im) {
if ( V_2 -> V_100 == V_164 ) {
V_2 -> V_172 ++ ;
F_95 ( V_15 , & V_164 , V_35 , 0 , NULL , 0 ) ;
goto V_173;
}
}
V_2 = F_86 ( sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 )
goto V_173;
V_2 -> V_172 = 1 ;
V_2 -> V_4 = V_15 ;
F_15 ( V_15 ) ;
V_2 -> V_100 = V_164 ;
V_2 -> V_31 = V_35 ;
V_2 -> V_34 [ V_35 ] = 1 ;
F_96 ( & V_2 -> V_3 , 1 ) ;
F_97 ( & V_2 -> V_6 ) ;
#ifdef F_90
F_98 ( & V_2 -> V_7 , & F_61 , ( unsigned long ) V_2 ) ;
V_2 -> V_10 = V_132 ;
#endif
V_2 -> V_174 = V_15 -> V_175 ;
V_15 -> V_176 ++ ;
F_99 ( V_15 -> V_175 , V_2 ) ;
#ifdef F_90
F_87 ( V_15 , V_2 -> V_100 ) ;
#endif
F_91 ( V_2 ) ;
if ( ! V_15 -> V_170 )
F_100 ( V_15 ) ;
V_173:
return;
}
void F_101 ( struct V_14 * V_15 )
{
#ifdef F_90
struct V_1 * V_2 ;
int type ;
F_49 (in_dev, im) {
if ( V_2 -> V_100 == V_108 )
continue;
if ( F_59 ( V_15 ) )
type = V_133 ;
else if ( F_60 ( V_15 ) )
type = V_134 ;
else
type = V_81 ;
F_53 ( V_15 , V_2 , type ) ;
}
#endif
}
void F_102 ( struct V_14 * V_15 , T_1 V_164 )
{
struct V_1 * V_137 ;
struct V_1 T_2 * * V_177 ;
F_93 () ;
for ( V_177 = & V_15 -> V_175 ;
( V_137 = F_103 ( * V_177 ) ) != NULL ;
V_177 = & V_137 -> V_174 ) {
if ( V_137 -> V_100 == V_164 ) {
if ( -- V_137 -> V_172 == 0 ) {
* V_177 = V_137 -> V_174 ;
V_15 -> V_176 -- ;
F_89 ( V_137 ) ;
F_88 ( V_137 ) ;
if ( ! V_15 -> V_170 )
F_100 ( V_15 ) ;
F_1 ( V_137 ) ;
return;
}
break;
}
}
}
void F_104 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_93 () ;
F_94 (in_dev, pmc)
F_89 ( V_22 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_93 () ;
F_94 (in_dev, pmc)
F_91 ( V_22 ) ;
}
void F_106 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_93 () ;
F_94 (in_dev, pmc)
F_89 ( V_22 ) ;
#ifdef F_90
V_15 -> V_129 = 0 ;
if ( F_7 ( & V_15 -> V_20 ) )
F_56 ( V_15 ) ;
V_15 -> V_17 = 0 ;
if ( F_7 ( & V_15 -> V_18 ) )
F_56 ( V_15 ) ;
F_69 ( V_15 ) ;
#endif
F_102 ( V_15 , V_108 ) ;
}
void F_107 ( struct V_14 * V_15 )
{
F_93 () ;
V_15 -> V_119 = NULL ;
#ifdef F_90
V_15 -> V_17 = 0 ;
F_98 ( & V_15 -> V_18 , F_55 ,
( unsigned long ) V_15 ) ;
V_15 -> V_129 = 0 ;
V_15 -> V_176 = 0 ;
F_98 ( & V_15 -> V_20 , F_57 ,
( unsigned long ) V_15 ) ;
V_15 -> V_131 = V_132 ;
#endif
F_97 ( & V_15 -> V_118 ) ;
}
void F_108 ( struct V_14 * V_15 )
{
struct V_1 * V_22 ;
F_93 () ;
F_92 ( V_15 , V_108 ) ;
F_94 (in_dev, pmc)
F_91 ( V_22 ) ;
}
void F_109 ( struct V_14 * V_15 )
{
struct V_1 * V_137 ;
F_93 () ;
F_106 ( V_15 ) ;
while ( ( V_137 = F_103 ( V_15 -> V_175 ) ) != NULL ) {
V_15 -> V_175 = V_137 -> V_174 ;
V_15 -> V_176 -- ;
F_88 ( V_137 ) ;
F_1 ( V_137 ) ;
}
}
static struct V_14 * F_110 ( struct V_55 * V_55 , struct V_178 * V_179 )
{
struct V_45 * V_46 = NULL ;
struct V_14 * V_180 = NULL ;
if ( V_179 -> V_181 ) {
V_180 = F_111 ( V_55 , V_179 -> V_181 ) ;
return V_180 ;
}
if ( V_179 -> V_182 . V_183 ) {
V_46 = F_112 ( V_55 , V_179 -> V_182 . V_183 , false ) ;
if ( ! V_46 )
return NULL ;
}
if ( ! V_46 ) {
struct V_49 * V_50 = F_113 ( V_55 ,
V_179 -> V_184 . V_183 ,
0 , 0 , 0 ) ;
if ( ! F_27 ( V_50 ) ) {
V_46 = V_50 -> V_66 . V_46 ;
F_54 ( V_50 ) ;
}
}
if ( V_46 ) {
V_179 -> V_181 = V_46 -> V_65 ;
V_180 = F_114 ( V_46 ) ;
}
return V_180 ;
}
static int F_115 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_185 )
{
struct V_23 * V_24 , * V_102 ;
int V_186 = 0 ;
V_102 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_112 == * V_185 )
break;
V_102 = V_24 ;
}
if ( ! V_24 || V_24 -> V_33 [ V_31 ] == 0 ) {
return - V_187 ;
}
V_24 -> V_33 [ V_31 ] -- ;
if ( V_24 -> V_33 [ V_31 ] == 0 ) {
F_100 ( V_22 -> V_4 ) ;
}
if ( ! V_24 -> V_33 [ V_32 ] && ! V_24 -> V_33 [ V_35 ] ) {
#ifdef F_90
struct V_14 * V_15 = V_22 -> V_4 ;
#endif
if ( V_102 )
V_102 -> V_43 = V_24 -> V_43 ;
else
V_22 -> V_42 = V_24 -> V_43 ;
#ifdef F_90
if ( V_24 -> V_188 &&
! F_59 ( V_15 ) && ! F_60 ( V_15 ) ) {
V_24 -> V_39 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_24 -> V_43 = V_22 -> V_109 ;
V_22 -> V_109 = V_24 ;
V_186 = 1 ;
} else
#endif
F_46 ( V_24 ) ;
}
return V_186 ;
}
static int F_116 ( struct V_14 * V_15 , T_1 * V_189 , int V_31 ,
int V_34 , T_1 * V_185 , int V_190 )
{
struct V_1 * V_22 ;
int V_191 = 0 ;
int V_137 , V_192 ;
if ( ! V_15 )
return - V_193 ;
F_48 () ;
F_49 (in_dev, pmc) {
if ( * V_189 == V_22 -> V_100 )
break;
}
if ( ! V_22 ) {
F_50 () ;
return - V_187 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_50 () ;
#ifdef F_90
F_117 ( V_22 ) ;
#endif
if ( ! V_190 ) {
V_192 = - V_194 ;
if ( ! V_22 -> V_34 [ V_31 ] )
goto V_195;
V_22 -> V_34 [ V_31 ] -- ;
}
V_192 = 0 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
int V_186 = F_115 ( V_22 , V_31 , & V_185 [ V_137 ] ) ;
V_191 |= V_186 > 0 ;
if ( ! V_192 && V_186 < 0 )
V_192 = V_186 ;
}
if ( V_22 -> V_31 == V_35 &&
V_22 -> V_34 [ V_35 ] == 0 &&
V_22 -> V_34 [ V_32 ] ) {
#ifdef F_90
struct V_23 * V_24 ;
#endif
V_22 -> V_31 = V_32 ;
#ifdef F_90
V_22 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_15 -> V_129 = V_22 -> V_113 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_58 ( V_22 -> V_4 ) ;
} else if ( F_118 ( V_22 ) || V_191 ) {
F_58 ( V_22 -> V_4 ) ;
#endif
}
V_195:
F_9 ( & V_22 -> V_6 ) ;
return V_192 ;
}
static int F_119 ( struct V_1 * V_22 , int V_31 ,
T_1 * V_185 )
{
struct V_23 * V_24 , * V_102 ;
V_102 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_112 == * V_185 )
break;
V_102 = V_24 ;
}
if ( ! V_24 ) {
V_24 = F_86 ( sizeof( * V_24 ) , V_61 ) ;
if ( ! V_24 )
return - V_196 ;
V_24 -> V_112 = * V_185 ;
if ( V_102 ) {
V_102 -> V_43 = V_24 ;
} else
V_22 -> V_42 = V_24 ;
}
V_24 -> V_33 [ V_31 ] ++ ;
if ( V_24 -> V_33 [ V_31 ] == 1 ) {
F_100 ( V_22 -> V_4 ) ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_22 )
{
struct V_23 * V_24 ;
int V_197 = V_22 -> V_34 [ V_35 ] ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
if ( V_22 -> V_34 [ V_35 ] ) {
V_24 -> V_188 = V_197 ==
V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_24 -> V_188 = V_24 -> V_33 [ V_32 ] != 0 ;
}
static int F_118 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_198 ;
int V_197 = V_22 -> V_34 [ V_35 ] ;
int V_149 = V_22 -> V_4 -> V_131 ;
int V_199 , V_186 ;
V_186 = 0 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_22 -> V_34 [ V_35 ] ) {
V_199 = V_197 == V_24 -> V_33 [ V_35 ] &&
! V_24 -> V_33 [ V_32 ] ;
} else
V_199 = V_24 -> V_33 [ V_32 ] != 0 ;
if ( V_199 ) {
if ( ! V_24 -> V_188 ) {
struct V_23 * V_200 = NULL ;
for ( V_198 = V_22 -> V_109 ; V_198 ; V_198 = V_198 -> V_43 ) {
if ( V_198 -> V_112 == V_24 -> V_112 )
break;
V_200 = V_198 ;
}
if ( V_198 ) {
if ( V_200 )
V_200 -> V_43 = V_198 -> V_43 ;
else
V_22 -> V_109 = V_198 -> V_43 ;
F_46 ( V_198 ) ;
}
V_24 -> V_39 = V_149 ;
V_186 ++ ;
}
} else if ( V_24 -> V_188 ) {
V_24 -> V_39 = 0 ;
for ( V_198 = V_22 -> V_109 ; V_198 ; V_198 = V_198 -> V_43 )
if ( V_198 -> V_112 == V_24 -> V_112 )
break;
if ( ! V_198 ) {
V_198 = F_120 ( sizeof( * V_198 ) , V_61 ) ;
if ( ! V_198 )
continue;
* V_198 = * V_24 ;
V_198 -> V_43 = V_22 -> V_109 ;
V_22 -> V_109 = V_198 ;
}
V_198 -> V_39 = V_149 ;
V_186 ++ ;
}
}
return V_186 ;
}
static int F_95 ( struct V_14 * V_15 , T_1 * V_189 , int V_31 ,
int V_34 , T_1 * V_185 , int V_190 )
{
struct V_1 * V_22 ;
int V_201 ;
int V_137 , V_192 ;
if ( ! V_15 )
return - V_193 ;
F_48 () ;
F_49 (in_dev, pmc) {
if ( * V_189 == V_22 -> V_100 )
break;
}
if ( ! V_22 ) {
F_50 () ;
return - V_187 ;
}
F_6 ( & V_22 -> V_6 ) ;
F_50 () ;
#ifdef F_90
F_117 ( V_22 ) ;
#endif
V_201 = V_22 -> V_31 == V_35 ;
if ( ! V_190 )
V_22 -> V_34 [ V_31 ] ++ ;
V_192 = 0 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
V_192 = F_119 ( V_22 , V_31 , & V_185 [ V_137 ] ) ;
if ( V_192 )
break;
}
if ( V_192 ) {
int V_202 ;
if ( ! V_190 )
V_22 -> V_34 [ V_31 ] -- ;
for ( V_202 = 0 ; V_202 < V_137 ; V_202 ++ )
( void ) F_115 ( V_22 , V_31 , & V_185 [ V_202 ] ) ;
} else if ( V_201 != ( V_22 -> V_34 [ V_35 ] != 0 ) ) {
#ifdef F_90
struct V_23 * V_24 ;
V_15 = V_22 -> V_4 ;
#endif
if ( V_22 -> V_34 [ V_35 ] )
V_22 -> V_31 = V_35 ;
else if ( V_22 -> V_34 [ V_32 ] )
V_22 -> V_31 = V_32 ;
#ifdef F_90
V_22 -> V_113 = V_15 -> V_131 ? V_15 -> V_131 :
V_132 ;
V_15 -> V_129 = V_22 -> V_113 ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 )
V_24 -> V_39 = 0 ;
F_58 ( V_15 ) ;
} else if ( F_118 ( V_22 ) ) {
F_58 ( V_15 ) ;
#endif
}
F_9 ( & V_22 -> V_6 ) ;
return V_192 ;
}
static void F_88 ( struct V_1 * V_22 )
{
struct V_23 * V_24 , * V_203 ;
for ( V_24 = V_22 -> V_109 ; V_24 ; V_24 = V_203 ) {
V_203 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
V_22 -> V_109 = NULL ;
for ( V_24 = V_22 -> V_42 ; V_24 ; V_24 = V_203 ) {
V_203 = V_24 -> V_43 ;
F_46 ( V_24 ) ;
}
V_22 -> V_42 = NULL ;
V_22 -> V_31 = V_35 ;
V_22 -> V_34 [ V_32 ] = 0 ;
V_22 -> V_34 [ V_35 ] = 1 ;
}
int F_121 ( struct V_204 * V_205 , struct V_178 * V_179 )
{
int V_192 ;
T_1 V_164 = V_179 -> V_184 . V_183 ;
struct V_206 * V_207 = NULL , * V_137 ;
struct V_14 * V_15 ;
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_55 * V_55 = F_123 ( V_205 ) ;
int V_65 ;
int V_210 = 0 ;
if ( ! F_124 ( V_164 ) )
return - V_194 ;
F_125 () ;
V_15 = F_110 ( V_55 , V_179 ) ;
if ( ! V_15 ) {
V_207 = NULL ;
V_192 = - V_193 ;
goto V_211;
}
V_192 = - V_212 ;
V_65 = V_179 -> V_181 ;
F_94 (inet, i) {
if ( V_137 -> V_213 . V_184 . V_183 == V_164 &&
V_137 -> V_213 . V_181 == V_65 )
goto V_211;
V_210 ++ ;
}
V_192 = - V_196 ;
if ( V_210 >= V_214 )
goto V_211;
V_207 = F_126 ( V_205 , sizeof( * V_207 ) , V_167 ) ;
if ( V_207 == NULL )
goto V_211;
memcpy ( & V_207 -> V_213 , V_179 , sizeof( * V_179 ) ) ;
V_207 -> V_174 = V_209 -> V_175 ;
V_207 -> V_215 = NULL ;
V_207 -> V_31 = V_35 ;
F_99 ( V_209 -> V_175 , V_207 ) ;
F_92 ( V_15 , V_164 ) ;
V_192 = 0 ;
V_211:
F_127 () ;
return V_192 ;
}
static int F_128 ( struct V_204 * V_205 , struct V_206 * V_207 ,
struct V_14 * V_15 )
{
struct V_216 * V_24 = F_103 ( V_207 -> V_215 ) ;
int V_192 ;
if ( V_24 == NULL ) {
return F_116 ( V_15 , & V_207 -> V_213 . V_184 . V_183 ,
V_207 -> V_31 , 0 , NULL , 0 ) ;
}
V_192 = F_116 ( V_15 , & V_207 -> V_213 . V_184 . V_183 ,
V_207 -> V_31 , V_24 -> V_217 , V_24 -> V_218 , 0 ) ;
F_129 ( V_207 -> V_215 , NULL ) ;
F_130 ( F_131 ( V_24 -> V_219 ) , & V_205 -> V_220 ) ;
F_4 ( V_24 , V_5 ) ;
return V_192 ;
}
int F_132 ( struct V_204 * V_205 , struct V_178 * V_179 )
{
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_206 * V_207 ;
struct V_206 T_2 * * V_221 ;
struct V_14 * V_15 ;
struct V_55 * V_55 = F_123 ( V_205 ) ;
T_1 V_123 = V_179 -> V_184 . V_183 ;
T_3 V_65 ;
int V_222 = - V_223 ;
F_125 () ;
V_15 = F_110 ( V_55 , V_179 ) ;
V_65 = V_179 -> V_181 ;
for ( V_221 = & V_209 -> V_175 ;
( V_207 = F_103 ( * V_221 ) ) != NULL ;
V_221 = & V_207 -> V_174 ) {
if ( V_207 -> V_213 . V_184 . V_183 != V_123 )
continue;
if ( V_65 ) {
if ( V_207 -> V_213 . V_181 != V_65 )
continue;
} else if ( V_179 -> V_182 . V_183 && V_179 -> V_182 . V_183 !=
V_207 -> V_213 . V_182 . V_183 )
continue;
( void ) F_128 ( V_205 , V_207 , V_15 ) ;
* V_221 = V_207 -> V_174 ;
if ( V_15 )
F_102 ( V_15 , V_123 ) ;
F_127 () ;
F_130 ( sizeof( * V_207 ) , & V_205 -> V_220 ) ;
F_4 ( V_207 , V_5 ) ;
return 0 ;
}
if ( ! V_15 )
V_222 = - V_193 ;
F_127 () ;
return V_222 ;
}
int F_133 ( int V_224 , int V_225 , struct V_204 * V_205 , struct
V_226 * V_227 , int V_65 )
{
int V_192 ;
struct V_178 V_179 ;
T_1 V_164 = V_227 -> V_184 ;
struct V_206 * V_22 ;
struct V_14 * V_15 = NULL ;
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_216 * V_228 ;
struct V_55 * V_55 = F_123 ( V_205 ) ;
int V_229 = 0 ;
int V_137 , V_202 , V_186 ;
if ( ! F_124 ( V_164 ) )
return - V_194 ;
F_125 () ;
V_179 . V_184 . V_183 = V_227 -> V_184 ;
V_179 . V_182 . V_183 = V_227 -> V_230 ;
V_179 . V_181 = V_65 ;
V_15 = F_110 ( V_55 , & V_179 ) ;
if ( ! V_15 ) {
V_192 = - V_193 ;
goto V_211;
}
V_192 = - V_223 ;
F_94 (inet, pmc) {
if ( ( V_22 -> V_213 . V_184 . V_183 ==
V_179 . V_184 . V_183 ) &&
( V_22 -> V_213 . V_181 == V_179 . V_181 ) )
break;
}
if ( ! V_22 ) {
V_192 = - V_194 ;
goto V_211;
}
if ( V_22 -> V_215 ) {
if ( V_22 -> V_31 != V_225 ) {
V_192 = - V_194 ;
goto V_211;
}
} else if ( V_22 -> V_31 != V_225 ) {
F_95 ( V_15 , & V_227 -> V_184 , V_225 , 0 , NULL , 0 ) ;
F_116 ( V_15 , & V_227 -> V_184 , V_22 -> V_31 , 0 ,
NULL , 0 ) ;
V_22 -> V_31 = V_225 ;
}
V_228 = F_103 ( V_22 -> V_215 ) ;
if ( ! V_224 ) {
if ( ! V_228 )
goto V_211;
V_186 = ! 0 ;
for ( V_137 = 0 ; V_137 < V_228 -> V_217 ; V_137 ++ ) {
V_186 = memcmp ( & V_228 -> V_218 [ V_137 ] , & V_227 -> V_231 ,
sizeof( T_1 ) ) ;
if ( V_186 == 0 )
break;
}
if ( V_186 )
goto V_211;
if ( V_228 -> V_217 == 1 && V_225 == V_32 ) {
V_229 = 1 ;
goto V_211;
}
F_116 ( V_15 , & V_227 -> V_184 , V_225 , 1 ,
& V_227 -> V_231 , 1 ) ;
for ( V_202 = V_137 + 1 ; V_202 < V_228 -> V_217 ; V_202 ++ )
V_228 -> V_218 [ V_202 - 1 ] = V_228 -> V_218 [ V_202 ] ;
V_228 -> V_217 -- ;
V_192 = 0 ;
goto V_211;
}
if ( V_228 && V_228 -> V_217 >= V_232 ) {
V_192 = - V_196 ;
goto V_211;
}
if ( ! V_228 || V_228 -> V_217 == V_228 -> V_219 ) {
struct V_216 * V_233 ;
int V_210 = V_234 ;
if ( V_228 )
V_210 += V_228 -> V_219 ;
V_233 = F_126 ( V_205 , F_131 ( V_210 ) , V_167 ) ;
if ( ! V_233 ) {
V_192 = - V_196 ;
goto V_211;
}
V_233 -> V_219 = V_210 ;
V_233 -> V_217 = V_210 - V_234 ;
if ( V_228 ) {
for ( V_137 = 0 ; V_137 < V_228 -> V_217 ; V_137 ++ )
V_233 -> V_218 [ V_137 ] = V_228 -> V_218 [ V_137 ] ;
F_130 ( F_131 ( V_228 -> V_219 ) , & V_205 -> V_220 ) ;
F_4 ( V_228 , V_5 ) ;
}
F_99 ( V_22 -> V_215 , V_233 ) ;
V_228 = V_233 ;
}
V_186 = 1 ;
for ( V_137 = 0 ; V_137 < V_228 -> V_217 ; V_137 ++ ) {
V_186 = memcmp ( & V_228 -> V_218 [ V_137 ] , & V_227 -> V_231 ,
sizeof( T_1 ) ) ;
if ( V_186 == 0 )
break;
}
if ( V_186 == 0 )
goto V_211;
for ( V_202 = V_228 -> V_217 - 1 ; V_202 >= V_137 ; V_202 -- )
V_228 -> V_218 [ V_202 + 1 ] = V_228 -> V_218 [ V_202 ] ;
V_228 -> V_218 [ V_137 ] = V_227 -> V_231 ;
V_228 -> V_217 ++ ;
V_192 = 0 ;
F_95 ( V_15 , & V_227 -> V_184 , V_225 , 1 ,
& V_227 -> V_231 , 1 ) ;
V_211:
F_127 () ;
if ( V_229 )
return F_132 ( V_205 , & V_179 ) ;
return V_192 ;
}
int F_134 ( struct V_204 * V_205 , struct V_235 * V_236 , int V_65 )
{
int V_192 = 0 ;
struct V_178 V_179 ;
T_1 V_164 = V_236 -> V_237 ;
struct V_206 * V_22 ;
struct V_14 * V_15 ;
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_216 * V_233 , * V_228 ;
struct V_55 * V_55 = F_123 ( V_205 ) ;
int V_229 = 0 ;
if ( ! F_124 ( V_164 ) )
return - V_194 ;
if ( V_236 -> V_238 != V_32 &&
V_236 -> V_238 != V_35 )
return - V_194 ;
F_125 () ;
V_179 . V_184 . V_183 = V_236 -> V_237 ;
V_179 . V_182 . V_183 = V_236 -> V_239 ;
V_179 . V_181 = V_65 ;
V_15 = F_110 ( V_55 , & V_179 ) ;
if ( ! V_15 ) {
V_192 = - V_193 ;
goto V_211;
}
if ( V_236 -> V_238 == V_32 && V_236 -> V_240 == 0 ) {
V_229 = 1 ;
goto V_211;
}
F_94 (inet, pmc) {
if ( V_22 -> V_213 . V_184 . V_183 == V_236 -> V_237 &&
V_22 -> V_213 . V_181 == V_179 . V_181 )
break;
}
if ( ! V_22 ) {
V_192 = - V_194 ;
goto V_211;
}
if ( V_236 -> V_240 ) {
V_233 = F_126 ( V_205 , F_131 ( V_236 -> V_240 ) ,
V_167 ) ;
if ( ! V_233 ) {
V_192 = - V_196 ;
goto V_211;
}
V_233 -> V_219 = V_233 -> V_217 = V_236 -> V_240 ;
memcpy ( V_233 -> V_218 , V_236 -> V_241 ,
V_236 -> V_240 * sizeof( V_236 -> V_241 [ 0 ] ) ) ;
V_192 = F_95 ( V_15 , & V_236 -> V_237 ,
V_236 -> V_238 , V_233 -> V_217 , V_233 -> V_218 , 0 ) ;
if ( V_192 ) {
F_135 ( V_205 , V_233 , F_131 ( V_233 -> V_219 ) ) ;
goto V_211;
}
} else {
V_233 = NULL ;
( void ) F_95 ( V_15 , & V_236 -> V_237 ,
V_236 -> V_238 , 0 , NULL , 0 ) ;
}
V_228 = F_103 ( V_22 -> V_215 ) ;
if ( V_228 ) {
( void ) F_116 ( V_15 , & V_236 -> V_237 , V_22 -> V_31 ,
V_228 -> V_217 , V_228 -> V_218 , 0 ) ;
F_130 ( F_131 ( V_228 -> V_219 ) , & V_205 -> V_220 ) ;
F_4 ( V_228 , V_5 ) ;
} else
( void ) F_116 ( V_15 , & V_236 -> V_237 , V_22 -> V_31 ,
0 , NULL , 0 ) ;
F_99 ( V_22 -> V_215 , V_233 ) ;
V_22 -> V_31 = V_236 -> V_238 ;
V_192 = 0 ;
V_211:
F_127 () ;
if ( V_229 )
V_192 = F_132 ( V_205 , & V_179 ) ;
return V_192 ;
}
int F_136 ( struct V_204 * V_205 , struct V_235 * V_236 ,
struct V_235 T_4 * V_242 , int T_4 * V_243 )
{
int V_192 , V_138 , V_210 , V_244 ;
struct V_178 V_179 ;
T_1 V_164 = V_236 -> V_237 ;
struct V_206 * V_22 ;
struct V_14 * V_15 ;
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_216 * V_228 ;
struct V_55 * V_55 = F_123 ( V_205 ) ;
if ( ! F_124 ( V_164 ) )
return - V_194 ;
F_125 () ;
V_179 . V_184 . V_183 = V_236 -> V_237 ;
V_179 . V_182 . V_183 = V_236 -> V_239 ;
V_179 . V_181 = 0 ;
V_15 = F_110 ( V_55 , & V_179 ) ;
if ( ! V_15 ) {
V_192 = - V_193 ;
goto V_211;
}
V_192 = - V_223 ;
F_94 (inet, pmc) {
if ( V_22 -> V_213 . V_184 . V_183 == V_236 -> V_237 &&
V_22 -> V_213 . V_181 == V_179 . V_181 )
break;
}
if ( ! V_22 )
goto V_211;
V_236 -> V_238 = V_22 -> V_31 ;
V_228 = F_103 ( V_22 -> V_215 ) ;
F_127 () ;
if ( ! V_228 ) {
V_138 = 0 ;
V_210 = 0 ;
} else {
V_210 = V_228 -> V_217 ;
}
V_244 = V_210 < V_236 -> V_240 ? V_210 : V_236 -> V_240 ;
V_138 = V_244 * sizeof( V_228 -> V_218 [ 0 ] ) ;
V_236 -> V_240 = V_210 ;
if ( F_137 ( F_138 ( V_244 ) , V_243 ) ||
F_139 ( V_242 , V_236 , F_138 ( 0 ) ) ) {
return - V_245 ;
}
if ( V_138 &&
F_139 ( & V_242 -> V_241 [ 0 ] , V_228 -> V_218 , V_138 ) )
return - V_245 ;
return 0 ;
V_211:
F_127 () ;
return V_192 ;
}
int F_140 ( struct V_204 * V_205 , struct V_246 * V_247 ,
struct V_246 T_4 * V_242 , int T_4 * V_243 )
{
int V_192 , V_137 , V_210 , V_244 ;
struct V_248 * V_249 ;
T_1 V_164 ;
struct V_206 * V_22 ;
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_216 * V_228 ;
V_249 = (struct V_248 * ) & V_247 -> V_250 ;
if ( V_249 -> V_251 != V_252 )
return - V_194 ;
V_164 = V_249 -> V_253 . V_183 ;
if ( ! F_124 ( V_164 ) )
return - V_194 ;
F_125 () ;
V_192 = - V_223 ;
F_94 (inet, pmc) {
if ( V_22 -> V_213 . V_184 . V_183 == V_164 &&
V_22 -> V_213 . V_181 == V_247 -> V_254 )
break;
}
if ( ! V_22 )
goto V_211;
V_247 -> V_255 = V_22 -> V_31 ;
V_228 = F_103 ( V_22 -> V_215 ) ;
F_127 () ;
V_210 = V_228 ? V_228 -> V_217 : 0 ;
V_244 = V_210 < V_247 -> V_256 ? V_210 : V_247 -> V_256 ;
V_247 -> V_256 = V_210 ;
if ( F_137 ( F_141 ( V_244 ) , V_243 ) ||
F_139 ( V_242 , V_247 , F_141 ( 0 ) ) ) {
return - V_245 ;
}
for ( V_137 = 0 ; V_137 < V_244 ; V_137 ++ ) {
struct V_257 V_258 ;
V_249 = (struct V_248 * ) & V_258 ;
memset ( & V_258 , 0 , sizeof( V_258 ) ) ;
V_249 -> V_251 = V_252 ;
V_249 -> V_253 . V_183 = V_228 -> V_218 [ V_137 ] ;
if ( F_139 ( & V_242 -> V_259 [ V_137 ] , & V_258 , sizeof( V_258 ) ) )
return - V_245 ;
}
return 0 ;
V_211:
F_127 () ;
return V_192 ;
}
int F_142 ( struct V_204 * V_205 , T_1 V_260 , T_1 V_261 , int V_262 )
{
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_206 * V_22 ;
struct V_216 * V_228 ;
int V_137 ;
int V_222 ;
V_222 = 1 ;
if ( ! F_124 ( V_260 ) )
goto V_173;
F_48 () ;
F_49 (inet, pmc) {
if ( V_22 -> V_213 . V_184 . V_183 == V_260 &&
V_22 -> V_213 . V_181 == V_262 )
break;
}
V_222 = V_209 -> V_263 ;
if ( ! V_22 )
goto V_264;
V_228 = F_143 ( V_22 -> V_215 ) ;
V_222 = ( V_22 -> V_31 == V_35 ) ;
if ( ! V_228 )
goto V_264;
for ( V_137 = 0 ; V_137 < V_228 -> V_217 ; V_137 ++ ) {
if ( V_228 -> V_218 [ V_137 ] == V_261 )
break;
}
V_222 = 0 ;
if ( V_22 -> V_31 == V_32 && V_137 >= V_228 -> V_217 )
goto V_264;
if ( V_22 -> V_31 == V_35 && V_137 < V_228 -> V_217 )
goto V_264;
V_222 = 1 ;
V_264:
F_50 () ;
V_173:
return V_222 ;
}
void F_144 ( struct V_204 * V_205 )
{
struct V_208 * V_209 = F_122 ( V_205 ) ;
struct V_206 * V_207 ;
struct V_55 * V_55 = F_123 ( V_205 ) ;
if ( V_209 -> V_175 == NULL )
return;
F_125 () ;
while ( ( V_207 = F_103 ( V_209 -> V_175 ) ) != NULL ) {
struct V_14 * V_15 ;
V_209 -> V_175 = V_207 -> V_174 ;
V_15 = F_111 ( V_55 , V_207 -> V_213 . V_181 ) ;
( void ) F_128 ( V_205 , V_207 , V_15 ) ;
if ( V_15 != NULL )
F_102 ( V_15 , V_207 -> V_213 . V_184 . V_183 ) ;
F_130 ( sizeof( * V_207 ) , & V_205 -> V_220 ) ;
F_4 ( V_207 , V_5 ) ;
}
F_127 () ;
}
int F_145 ( struct V_14 * V_15 , T_1 V_265 , T_1 V_266 , T_5 V_267 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_186 = 0 ;
F_49 (in_dev, im) {
if ( V_2 -> V_100 == V_265 )
break;
}
if ( V_2 && V_267 == V_64 ) {
V_186 = 1 ;
} else if ( V_2 ) {
if ( V_266 ) {
for ( V_24 = V_2 -> V_42 ; V_24 ; V_24 = V_24 -> V_43 ) {
if ( V_24 -> V_112 == V_266 )
break;
}
if ( V_24 )
V_186 = V_24 -> V_33 [ V_32 ] ||
V_24 -> V_33 [ V_35 ] !=
V_2 -> V_34 [ V_35 ] ;
else
V_186 = V_2 -> V_34 [ V_35 ] != 0 ;
} else
V_186 = 1 ;
}
return V_186 ;
}
static inline struct V_1 * F_146 ( struct V_268 * V_269 )
{
struct V_55 * V_55 = F_147 ( V_269 ) ;
struct V_1 * V_2 = NULL ;
struct V_270 * V_271 = F_148 ( V_269 ) ;
V_271 -> V_15 = NULL ;
F_149 (net, state->dev) {
struct V_14 * V_15 ;
V_15 = F_73 ( V_271 -> V_46 ) ;
if ( ! V_15 )
continue;
V_2 = F_143 ( V_15 -> V_175 ) ;
if ( V_2 ) {
V_271 -> V_15 = V_15 ;
break;
}
}
return V_2 ;
}
static struct V_1 * F_150 ( struct V_268 * V_269 , struct V_1 * V_2 )
{
struct V_270 * V_271 = F_148 ( V_269 ) ;
V_2 = F_143 ( V_2 -> V_174 ) ;
while ( ! V_2 ) {
V_271 -> V_46 = F_151 ( V_271 -> V_46 ) ;
if ( ! V_271 -> V_46 ) {
V_271 -> V_15 = NULL ;
break;
}
V_271 -> V_15 = F_73 ( V_271 -> V_46 ) ;
if ( ! V_271 -> V_15 )
continue;
V_2 = F_143 ( V_271 -> V_15 -> V_175 ) ;
}
return V_2 ;
}
static struct V_1 * F_152 ( struct V_268 * V_269 , T_6 V_272 )
{
struct V_1 * V_2 = F_146 ( V_269 ) ;
if ( V_2 )
while ( V_272 && ( V_2 = F_150 ( V_269 , V_2 ) ) != NULL )
-- V_272 ;
return V_272 ? NULL : V_2 ;
}
static void * F_153 ( struct V_268 * V_269 , T_6 * V_272 )
__acquires( V_5 )
{
F_48 () ;
return * V_272 ? F_152 ( V_269 , * V_272 - 1 ) : V_273 ;
}
static void * F_154 ( struct V_268 * V_269 , void * V_274 , T_6 * V_272 )
{
struct V_1 * V_2 ;
if ( V_274 == V_273 )
V_2 = F_146 ( V_269 ) ;
else
V_2 = F_150 ( V_269 , V_274 ) ;
++ * V_272 ;
return V_2 ;
}
static void F_155 ( struct V_268 * V_269 , void * V_274 )
__releases( V_5 )
{
struct V_270 * V_271 = F_148 ( V_269 ) ;
V_271 -> V_15 = NULL ;
V_271 -> V_46 = NULL ;
F_50 () ;
}
static int F_156 ( struct V_268 * V_269 , void * V_274 )
{
if ( V_274 == V_273 )
F_157 ( V_269 ,
L_1 ) ;
else {
struct V_1 * V_2 = (struct V_1 * ) V_274 ;
struct V_270 * V_271 = F_148 ( V_269 ) ;
char * V_275 ;
#ifdef F_90
V_275 = F_59 ( V_271 -> V_15 ) ? L_2 :
F_60 ( V_271 -> V_15 ) ? L_3 :
L_4 ;
#else
V_275 = L_5 ;
#endif
if ( F_143 ( V_271 -> V_15 -> V_175 ) == V_2 ) {
F_158 ( V_269 , L_6 ,
V_271 -> V_46 -> V_65 , V_271 -> V_46 -> V_276 , V_271 -> V_15 -> V_176 , V_275 ) ;
}
F_158 ( V_269 ,
L_7 ,
V_2 -> V_100 , V_2 -> V_172 ,
V_2 -> V_8 , V_2 -> V_8 ?
F_159 ( V_2 -> V_7 . V_21 - V_13 ) : 0 ,
V_2 -> V_9 ) ;
}
return 0 ;
}
static int F_160 ( struct V_277 * V_277 , struct V_278 * V_278 )
{
return F_161 ( V_277 , V_278 , & V_279 ,
sizeof( struct V_270 ) ) ;
}
static inline struct V_23 * F_162 ( struct V_268 * V_269 )
{
struct V_55 * V_55 = F_147 ( V_269 ) ;
struct V_23 * V_24 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_280 * V_271 = F_163 ( V_269 ) ;
V_271 -> V_180 = NULL ;
V_271 -> V_2 = NULL ;
F_149 (net, state->dev) {
struct V_14 * V_180 ;
V_180 = F_73 ( V_271 -> V_46 ) ;
if ( F_164 ( V_180 == NULL ) )
continue;
V_2 = F_143 ( V_180 -> V_175 ) ;
if ( F_165 ( V_2 != NULL ) ) {
F_6 ( & V_2 -> V_6 ) ;
V_24 = V_2 -> V_42 ;
if ( F_165 ( V_24 != NULL ) ) {
V_271 -> V_2 = V_2 ;
V_271 -> V_180 = V_180 ;
break;
}
F_9 ( & V_2 -> V_6 ) ;
}
}
return V_24 ;
}
static struct V_23 * F_166 ( struct V_268 * V_269 , struct V_23 * V_24 )
{
struct V_280 * V_271 = F_163 ( V_269 ) ;
V_24 = V_24 -> V_43 ;
while ( ! V_24 ) {
F_9 ( & V_271 -> V_2 -> V_6 ) ;
V_271 -> V_2 = V_271 -> V_2 -> V_120 ;
while ( ! V_271 -> V_2 ) {
V_271 -> V_46 = F_151 ( V_271 -> V_46 ) ;
if ( ! V_271 -> V_46 ) {
V_271 -> V_180 = NULL ;
goto V_173;
}
V_271 -> V_180 = F_73 ( V_271 -> V_46 ) ;
if ( ! V_271 -> V_180 )
continue;
V_271 -> V_2 = F_143 ( V_271 -> V_180 -> V_175 ) ;
}
if ( ! V_271 -> V_2 )
break;
F_6 ( & V_271 -> V_2 -> V_6 ) ;
V_24 = V_271 -> V_2 -> V_42 ;
}
V_173:
return V_24 ;
}
static struct V_23 * F_167 ( struct V_268 * V_269 , T_6 V_272 )
{
struct V_23 * V_24 = F_162 ( V_269 ) ;
if ( V_24 )
while ( V_272 && ( V_24 = F_166 ( V_269 , V_24 ) ) != NULL )
-- V_272 ;
return V_272 ? NULL : V_24 ;
}
static void * F_168 ( struct V_268 * V_269 , T_6 * V_272 )
__acquires( V_5 )
{
F_48 () ;
return * V_272 ? F_167 ( V_269 , * V_272 - 1 ) : V_273 ;
}
static void * F_169 ( struct V_268 * V_269 , void * V_274 , T_6 * V_272 )
{
struct V_23 * V_24 ;
if ( V_274 == V_273 )
V_24 = F_162 ( V_269 ) ;
else
V_24 = F_166 ( V_269 , V_274 ) ;
++ * V_272 ;
return V_24 ;
}
static void F_170 ( struct V_268 * V_269 , void * V_274 )
__releases( V_5 )
{
struct V_280 * V_271 = F_163 ( V_269 ) ;
if ( F_165 ( V_271 -> V_2 != NULL ) ) {
F_9 ( & V_271 -> V_2 -> V_6 ) ;
V_271 -> V_2 = NULL ;
}
V_271 -> V_180 = NULL ;
V_271 -> V_46 = NULL ;
F_50 () ;
}
static int F_171 ( struct V_268 * V_269 , void * V_274 )
{
struct V_23 * V_24 = (struct V_23 * ) V_274 ;
struct V_280 * V_271 = F_163 ( V_269 ) ;
if ( V_274 == V_273 ) {
F_158 ( V_269 ,
L_8
L_9 , L_10 ,
L_11 , L_12 ,
L_13 , L_14 , L_15 ) ;
} else {
F_158 ( V_269 ,
L_16
L_17 ,
V_271 -> V_46 -> V_65 , V_271 -> V_46 -> V_276 ,
F_172 ( V_271 -> V_2 -> V_100 ) ,
F_172 ( V_24 -> V_112 ) ,
V_24 -> V_33 [ V_32 ] ,
V_24 -> V_33 [ V_35 ] ) ;
}
return 0 ;
}
static int F_173 ( struct V_277 * V_277 , struct V_278 * V_278 )
{
return F_161 ( V_277 , V_278 , & V_281 ,
sizeof( struct V_280 ) ) ;
}
static int T_7 F_174 ( struct V_55 * V_55 )
{
struct V_282 * V_283 ;
V_283 = F_175 ( V_55 , L_18 , V_284 , & V_285 ) ;
if ( ! V_283 )
goto V_286;
V_283 = F_175 ( V_55 , L_19 , V_284 , & V_287 ) ;
if ( ! V_283 )
goto V_288;
return 0 ;
V_288:
F_176 ( V_55 , L_18 ) ;
V_286:
return - V_289 ;
}
static void T_8 F_177 ( struct V_55 * V_55 )
{
F_176 ( V_55 , L_19 ) ;
F_176 ( V_55 , L_18 ) ;
}
int T_9 F_178 ( void )
{
return F_179 ( & V_290 ) ;
}
