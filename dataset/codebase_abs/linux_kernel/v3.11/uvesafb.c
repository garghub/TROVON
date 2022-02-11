static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! F_2 ( V_9 ) )
return;
if ( V_2 -> V_10 >= V_11 )
return;
F_3 ( & V_12 ) ;
V_8 = V_13 [ V_2 -> V_10 ] ;
if ( ! V_8 || V_2 -> V_14 != V_8 -> V_14 ) {
F_4 ( & V_12 ) ;
return;
}
V_6 = (struct V_5 * ) V_2 -> V_15 ;
if ( V_8 -> V_16 . V_17 < V_6 -> V_17 ||
V_6 -> V_17 > V_2 -> V_18 - sizeof( * V_6 ) ) {
F_4 ( & V_12 ) ;
return;
}
V_13 [ V_2 -> V_10 ] = NULL ;
F_4 ( & V_12 ) ;
memcpy ( & V_8 -> V_16 , V_6 , sizeof( * V_6 ) ) ;
if ( V_8 -> V_16 . V_17 && V_8 -> V_19 )
memcpy ( V_8 -> V_19 , V_6 + 1 , V_8 -> V_16 . V_17 ) ;
F_5 ( V_8 -> V_20 ) ;
return;
}
static int F_6 ( void )
{
char * V_21 [] = {
L_1 ,
L_2 ,
NULL ,
} ;
char * V_22 [] = {
V_23 ,
NULL ,
} ;
return F_7 ( V_23 , V_22 , V_21 , V_24 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
static int V_10 ;
struct V_1 * V_25 ;
int V_26 ;
int V_18 = sizeof( V_8 -> V_16 ) + V_8 -> V_16 . V_17 ;
if ( sizeof( * V_25 ) + V_18 > V_27 ) {
F_9 ( V_28 L_3
L_4 , ( int ) ( sizeof( * V_25 ) + V_18 ) ) ;
return - V_29 ;
}
V_25 = F_10 ( sizeof( * V_25 ) + V_18 , V_30 ) ;
if ( ! V_25 )
return - V_31 ;
F_11 ( V_8 -> V_20 ) ;
memcpy ( & V_25 -> V_32 , & V_33 , sizeof( V_25 -> V_32 ) ) ;
V_25 -> V_10 = V_10 ;
V_25 -> V_18 = V_18 ;
V_25 -> V_14 = F_12 () ;
memcpy ( V_25 + 1 , & V_8 -> V_16 , sizeof( V_8 -> V_16 ) ) ;
memcpy ( ( V_34 * ) ( V_25 + 1 ) + sizeof( V_8 -> V_16 ) , V_8 -> V_19 , V_8 -> V_16 . V_17 ) ;
V_8 -> V_14 = V_25 -> V_14 ;
F_3 ( & V_12 ) ;
if ( V_13 [ V_10 ] ) {
F_4 ( & V_12 ) ;
V_26 = - V_35 ;
goto V_36;
}
V_13 [ V_10 ] = V_8 ;
F_4 ( & V_12 ) ;
V_26 = F_13 ( V_25 , 0 , V_30 ) ;
if ( V_26 == - V_37 ) {
V_26 = F_6 () ;
if ( V_26 ) {
F_9 ( V_38 L_5 ,
V_23 ) ;
F_9 ( V_38 L_6
L_7 ) ;
} else {
V_39 = 1 ;
V_26 = F_13 ( V_25 , 0 , F_14 () ) ;
if ( V_26 == - V_40 )
V_26 = 0 ;
}
} else if ( V_26 == - V_40 )
V_26 = 0 ;
if ( ! V_26 && ! ( V_8 -> V_16 . V_41 & V_42 ) )
V_26 = ! F_15 ( V_8 -> V_20 ,
F_16 ( V_43 ) ) ;
F_3 ( & V_12 ) ;
V_13 [ V_10 ] = NULL ;
F_4 ( & V_12 ) ;
V_10 ++ ;
if ( V_10 >= V_11 )
V_10 = 0 ;
V_36:
F_17 ( V_25 ) ;
return V_26 ;
}
static void F_18 ( struct V_7 * V_8 )
{
if ( V_8 ) {
if ( V_8 -> V_20 )
F_17 ( V_8 -> V_20 ) ;
F_17 ( V_8 ) ;
}
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_44 * V_45 = V_8 -> V_20 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_20 = V_45 ;
}
static struct V_7 * F_20 ( void )
{
struct V_7 * V_8 ;
V_8 = F_10 ( sizeof( * V_8 ) , V_30 ) ;
if ( V_8 ) {
V_8 -> V_20 = F_10 ( sizeof( * V_8 -> V_20 ) , V_30 ) ;
if ( ! V_8 -> V_20 ) {
F_17 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_8 ;
}
static void F_21 ( struct V_46 * V_47 ,
struct V_48 * V_49 , struct V_50 * V_51 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
V_47 -> V_54 = V_55 ;
V_47 -> V_56 = V_57 ;
V_47 -> V_58 = V_51 -> V_59 ;
V_47 -> V_60 = V_51 -> V_61 ;
V_47 -> V_62 = V_51 -> V_59 ;
V_47 -> V_63 = ( V_53 -> V_64 ) ?
V_49 -> V_65 . V_66 / V_51 -> V_67 :
V_51 -> V_61 ;
V_47 -> V_68 = 0 ;
V_47 -> V_69 = 0 ;
V_47 -> V_70 = V_51 -> V_70 ;
if ( V_47 -> V_70 == 15 )
V_47 -> V_70 = 16 ;
if ( V_47 -> V_70 > 8 ) {
V_47 -> V_71 . V_72 = V_51 -> V_73 ;
V_47 -> V_71 . V_74 = V_51 -> V_75 ;
V_47 -> V_76 . V_72 = V_51 -> V_77 ;
V_47 -> V_76 . V_74 = V_51 -> V_78 ;
V_47 -> V_79 . V_72 = V_51 -> V_80 ;
V_47 -> V_79 . V_74 = V_51 -> V_81 ;
V_47 -> V_82 . V_72 = V_51 -> V_83 ;
V_47 -> V_82 . V_74 = V_51 -> V_84 ;
} else {
V_47 -> V_71 . V_72 = 0 ;
V_47 -> V_76 . V_72 = 0 ;
V_47 -> V_79 . V_72 = 0 ;
V_47 -> V_82 . V_72 = 0 ;
V_47 -> V_71 . V_74 = 8 ;
V_47 -> V_76 . V_74 = 8 ;
V_47 -> V_79 . V_74 = 8 ;
V_47 -> V_82 . V_74 = 0 ;
}
}
static int F_22 ( struct V_52 * V_53 ,
int V_58 , int V_60 , int V_85 , unsigned char V_41 )
{
int V_86 , V_87 = - 1 , V_88 = 0 , V_89 = 0x7fffffff ;
for ( V_86 = 0 ; V_86 < V_53 -> V_90 ; V_86 ++ ) {
V_88 = abs ( V_53 -> V_91 [ V_86 ] . V_59 - V_58 ) +
abs ( V_53 -> V_91 [ V_86 ] . V_61 - V_60 ) +
abs ( V_85 - V_53 -> V_91 [ V_86 ] . V_85 ) ;
if ( V_88 == 0 )
return V_86 ;
if ( V_88 < V_89 || ( V_88 == V_89 && V_53 -> V_91 [ V_86 ] . V_85 > V_85 ) ) {
V_89 = V_88 ;
V_87 = V_86 ;
}
}
V_86 = 1 ;
if ( V_41 & V_92 &&
V_53 -> V_91 [ V_87 ] . V_85 != V_85 )
V_86 = 0 ;
if ( V_41 & V_93 && V_89 > 24 )
V_86 = 0 ;
if ( V_86 != 0 )
return V_87 ;
else
return - 1 ;
}
static V_34 * F_23 ( struct V_52 * V_53 )
{
struct V_7 * V_8 ;
V_34 * V_94 ;
int V_26 ;
if ( ! V_53 -> V_95 )
return NULL ;
V_94 = F_24 ( V_53 -> V_95 , V_30 ) ;
if ( ! V_94 )
return F_25 ( - V_31 ) ;
V_8 = F_20 () ;
if ( ! V_8 ) {
F_17 ( V_94 ) ;
return NULL ;
}
V_8 -> V_16 . V_96 . V_97 = 0x4f04 ;
V_8 -> V_16 . V_96 . V_98 = 0x000f ;
V_8 -> V_16 . V_96 . V_99 = 0x0001 ;
V_8 -> V_16 . V_41 = V_100 | V_101 ;
V_8 -> V_16 . V_17 = V_53 -> V_95 ;
V_8 -> V_19 = V_94 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f ) {
F_9 ( V_28 L_8
L_9 ,
V_8 -> V_16 . V_96 . V_97 , V_26 ) ;
F_17 ( V_94 ) ;
V_94 = NULL ;
}
F_18 ( V_8 ) ;
return V_94 ;
}
static void F_26 ( struct V_52 * V_53 , V_34 * V_102 )
{
struct V_7 * V_8 ;
int V_26 ;
if ( ! V_102 )
return;
V_8 = F_20 () ;
if ( ! V_8 )
return;
V_8 -> V_16 . V_96 . V_97 = 0x4f04 ;
V_8 -> V_16 . V_96 . V_98 = 0x000f ;
V_8 -> V_16 . V_96 . V_99 = 0x0002 ;
V_8 -> V_16 . V_17 = V_53 -> V_95 ;
V_8 -> V_16 . V_41 = V_101 ;
V_8 -> V_19 = V_102 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f )
F_9 ( V_28 L_10
L_9 ,
V_8 -> V_16 . V_96 . V_97 , V_26 ) ;
F_18 ( V_8 ) ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_52 * V_53 )
{
int V_26 ;
V_8 -> V_16 . V_96 . V_97 = 0x4f00 ;
V_8 -> V_16 . V_41 = V_103 ;
V_8 -> V_16 . V_17 = sizeof( struct V_104 ) ;
V_8 -> V_19 = & V_53 -> V_104 ;
strncpy ( V_53 -> V_104 . V_105 , L_11 , 4 ) ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f ) {
F_9 ( V_38 L_12
L_13 , ( V_106 ) V_8 -> V_16 . V_96 . V_97 ,
V_26 ) ;
return - V_107 ;
}
if ( V_53 -> V_104 . V_108 < 0x0200 ) {
F_9 ( V_38 L_14
L_15 ) ;
return - V_107 ;
}
if ( ! V_53 -> V_104 . V_109 ) {
F_9 ( V_38 L_16 ) ;
return - V_107 ;
}
F_9 ( V_110 L_17 ) ;
if ( V_53 -> V_104 . V_111 )
F_9 ( L_18 ,
( ( char * ) V_8 -> V_19 ) + V_53 -> V_104 . V_111 ) ;
if ( V_53 -> V_104 . V_112 )
F_9 ( L_18 ,
( ( char * ) V_8 -> V_19 ) + V_53 -> V_104 . V_112 ) ;
if ( V_53 -> V_104 . V_113 )
F_9 ( L_18 ,
( ( char * ) V_8 -> V_19 ) + V_53 -> V_104 . V_113 ) ;
if ( V_53 -> V_104 . V_114 )
F_9 ( L_19 ,
( ( char * ) V_8 -> V_19 ) + V_53 -> V_104 . V_114 ) ;
F_9 ( L_20 , ( ( V_53 -> V_104 . V_108 & 0xff00 ) >> 8 ) ,
V_53 -> V_104 . V_108 & 0xff ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 ,
struct V_52 * V_53 )
{
int V_115 = 0 , V_26 ;
T_1 * V_51 ;
V_53 -> V_90 = 0 ;
V_51 = ( T_1 * ) ( ( ( V_34 * ) & V_53 -> V_104 ) + V_53 -> V_104 . V_109 ) ;
while ( * V_51 != 0xffff ) {
V_53 -> V_90 ++ ;
V_51 ++ ;
}
V_53 -> V_91 = F_10 ( sizeof( struct V_50 ) *
V_53 -> V_90 , V_30 ) ;
if ( ! V_53 -> V_91 )
return - V_31 ;
V_51 = ( T_1 * ) ( ( ( V_34 * ) & V_53 -> V_104 ) + V_53 -> V_104 . V_109 ) ;
while ( * V_51 != 0xffff ) {
struct V_50 * V_116 ;
F_19 ( V_8 ) ;
V_8 -> V_16 . V_96 . V_97 = 0x4f01 ;
V_8 -> V_16 . V_96 . V_98 = ( V_106 ) * V_51 ;
V_8 -> V_16 . V_41 = V_100 | V_117 ;
V_8 -> V_16 . V_17 = sizeof( struct V_50 ) ;
V_8 -> V_19 = V_53 -> V_91 + V_115 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f ) {
F_9 ( V_28 L_21
L_22 ,
* V_51 , ( V_106 ) V_8 -> V_16 . V_96 . V_97 , V_26 ) ;
V_51 ++ ;
V_53 -> V_90 -- ;
continue;
}
V_116 = V_8 -> V_19 ;
V_116 -> V_118 = * V_51 ;
if ( ( V_116 -> V_119 & V_120 ) == V_120 &&
V_116 -> V_70 >= 8 )
V_115 ++ ;
else
V_53 -> V_90 -- ;
V_51 ++ ;
V_116 -> V_85 = V_116 -> V_75 + V_116 -> V_78 + V_116 -> V_81 ;
if ( V_116 -> V_85 == 0 || ( V_116 -> V_85 == 24 &&
V_116 -> V_70 == 32 ) )
V_116 -> V_85 = V_116 -> V_70 ;
}
if ( V_53 -> V_90 > 0 )
return 0 ;
else
return - V_107 ;
}
static int F_29 ( struct V_7 * V_8 ,
struct V_52 * V_53 )
{
int V_86 , V_26 ;
F_19 ( V_8 ) ;
V_8 -> V_16 . V_96 . V_97 = 0x4f0a ;
V_8 -> V_16 . V_96 . V_121 = 0x0 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x4f || V_8 -> V_16 . V_96 . V_122 < 0xc000 ) {
V_53 -> V_123 = V_53 -> V_64 = 0 ;
} else {
V_53 -> V_124 = ( T_1 * ) F_30 ( ( ( V_106 ) V_8 -> V_16 . V_96 . V_122 << 4 )
+ V_8 -> V_16 . V_96 . V_125 ) ;
V_53 -> V_126 = ( V_34 * ) V_53 -> V_124 + V_53 -> V_124 [ 1 ] ;
V_53 -> V_127 = ( V_34 * ) V_53 -> V_124 + V_53 -> V_124 [ 2 ] ;
F_9 ( V_110 L_23
L_24 ,
( T_1 ) V_8 -> V_16 . V_96 . V_122 , ( T_1 ) V_8 -> V_16 . V_96 . V_125 ) ;
F_9 ( V_110 L_25
L_26 , V_53 -> V_126 ,
V_53 -> V_127 ) ;
if ( V_53 -> V_124 [ 3 ] ) {
F_9 ( V_110 L_27 ) ;
for ( V_86 = V_53 -> V_124 [ 3 ] / 2 ;
V_53 -> V_124 [ V_86 ] != 0xffff ; V_86 ++ )
F_9 ( L_28 , V_53 -> V_124 [ V_86 ] ) ;
F_9 ( L_29 ) ;
if ( V_53 -> V_124 [ V_86 ] != 0xffff ) {
F_9 ( V_110 L_30
L_31 ) ;
V_53 -> V_64 = V_53 -> V_123 = 0 ;
}
}
}
return 0 ;
}
static int F_31 ( struct V_128 * V_51 ,
struct V_48 * V_49 )
{
if ( V_49 -> V_129 . V_130 ) {
F_32 ( & V_49 -> V_47 , V_51 ) ;
if ( F_33 ( & V_49 -> V_47 , V_49 ) )
return 0 ;
}
if ( F_22 ( V_49 -> V_53 , V_51 -> V_58 , V_51 -> V_60 , 8 ,
V_93 ) == - 1 )
return 0 ;
return 1 ;
}
static int F_34 ( struct V_7 * V_8 , struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
int V_26 = 0 ;
if ( V_131 || V_53 -> V_104 . V_108 < 0x0300 )
return - V_107 ;
V_8 -> V_16 . V_96 . V_97 = 0x4f15 ;
V_8 -> V_16 . V_96 . V_121 = 0 ;
V_8 -> V_16 . V_96 . V_98 = 0 ;
V_8 -> V_16 . V_17 = 0 ;
V_8 -> V_16 . V_41 = 0 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f || V_26 )
return - V_107 ;
if ( ( V_8 -> V_16 . V_96 . V_121 & 0x3 ) == 3 ) {
F_9 ( V_110 L_32
L_33 ) ;
} else if ( ( V_8 -> V_16 . V_96 . V_121 & 0x3 ) == 2 ) {
F_9 ( V_110 L_34
L_35 ) ;
} else if ( ( V_8 -> V_16 . V_96 . V_121 & 0x3 ) == 1 ) {
F_9 ( V_110 L_36
L_35 ) ;
} else {
F_9 ( V_110 L_37
L_38 ) ;
return - V_107 ;
}
V_8 -> V_16 . V_96 . V_97 = 0x4f15 ;
V_8 -> V_16 . V_96 . V_121 = 1 ;
V_8 -> V_16 . V_96 . V_98 = V_8 -> V_16 . V_96 . V_99 = 0 ;
V_8 -> V_16 . V_41 = V_100 | V_117 ;
V_8 -> V_16 . V_17 = V_132 ;
V_8 -> V_19 = F_10 ( V_132 , V_30 ) ;
if ( ! V_8 -> V_19 )
return - V_31 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) == 0x004f && ! V_26 ) {
F_35 ( V_8 -> V_19 , & V_49 -> V_129 ) ;
if ( V_49 -> V_129 . V_133 && V_49 -> V_129 . V_134 ) {
if ( V_49 -> V_129 . V_135 == 0 )
V_49 -> V_129 . V_135 = 300 * 1000000 ;
V_49 -> V_129 . V_130 = 1 ;
}
} else {
V_26 = - V_107 ;
}
F_17 ( V_8 -> V_19 ) ;
return V_26 ;
}
static void F_36 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
int V_86 ;
memset ( & V_49 -> V_129 , 0 , sizeof( V_49 -> V_129 ) ) ;
if ( F_34 ( V_8 , V_49 ) ) {
V_49 -> V_129 . V_130 = 0 ;
V_53 -> V_136 = 1 ;
}
if ( V_137 )
V_49 -> V_129 . V_135 = V_137 * 1000000 ;
if ( V_138 )
V_49 -> V_129 . V_133 = V_138 ;
if ( V_139 )
V_49 -> V_129 . V_134 = V_139 * 1000 ;
if ( V_49 -> V_129 . V_130 == 0 && V_137 && V_138 && V_139 ) {
V_49 -> V_129 . V_140 = 0 ;
V_49 -> V_129 . V_141 = 60 ;
V_49 -> V_129 . V_142 = 29000 ;
V_49 -> V_129 . V_130 = 1 ;
V_53 -> V_136 = 0 ;
}
if ( V_49 -> V_129 . V_130 )
F_9 ( V_110
L_39
L_40 , V_49 -> V_129 . V_133 ,
( int ) ( V_49 -> V_129 . V_134 / 1000 ) ,
( int ) ( V_49 -> V_129 . V_135 / 1000000 ) ) ;
else
F_9 ( V_110 L_41
L_42 ) ;
for ( V_86 = 0 ; V_86 < V_53 -> V_90 ; V_86 ++ ) {
struct V_46 V_47 ;
struct V_50 * V_51 ;
struct V_128 V_54 ;
V_51 = & V_53 -> V_91 [ V_86 ] ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_58 = V_51 -> V_59 ;
V_47 . V_60 = V_51 -> V_61 ;
F_37 ( V_143 | V_144 , 60 , & V_47 , V_49 ) ;
F_38 ( & V_54 , & V_47 ) ;
F_39 ( & V_54 , & V_49 -> V_145 ) ;
}
for ( V_86 = 0 ; V_86 < V_146 ; V_86 ++ ) {
if ( F_31 ( (struct V_128 * )
& V_147 [ V_86 ] , V_49 ) )
F_39 ( & V_147 [ V_86 ] , & V_49 -> V_145 ) ;
}
for ( V_86 = 0 ; V_86 < V_49 -> V_129 . V_148 ; V_86 ++ ) {
if ( F_31 ( & V_49 -> V_129 . V_149 [ V_86 ] , V_49 ) )
F_39 ( & V_49 -> V_129 . V_149 [ V_86 ] ,
& V_49 -> V_145 ) ;
}
return;
}
static void F_40 ( struct V_7 * V_8 ,
struct V_52 * V_53 )
{
int V_26 ;
F_19 ( V_8 ) ;
V_8 -> V_16 . V_96 . V_97 = 0x4f04 ;
V_8 -> V_16 . V_96 . V_98 = 0x000f ;
V_8 -> V_16 . V_96 . V_99 = 0x0000 ;
V_8 -> V_16 . V_41 = 0 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f ) {
F_9 ( V_28 L_43
L_44 ,
V_8 -> V_16 . V_96 . V_97 , V_26 ) ;
V_53 -> V_95 = 0 ;
return;
}
V_53 -> V_95 = 64 * ( V_8 -> V_16 . V_96 . V_121 & 0xffff ) ;
}
static int F_41 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = NULL ;
struct V_52 * V_53 = V_49 -> V_53 ;
int V_26 ;
V_8 = F_20 () ;
if ( ! V_8 )
return - V_31 ;
V_26 = F_27 ( V_8 , V_53 ) ;
if ( V_26 )
goto V_36;
V_26 = F_28 ( V_8 , V_53 ) ;
if ( V_26 )
goto V_36;
V_53 -> V_136 = V_136 ;
#ifdef F_42
V_53 -> V_123 = V_123 ;
V_53 -> V_64 = V_64 ;
if ( V_53 -> V_123 || V_53 -> V_64 ) {
if ( V_150 & V_151 ) {
V_53 -> V_123 = V_53 -> V_64 = 0 ;
F_9 ( V_28 L_45
L_46 ) ;
} else {
F_29 ( V_8 , V_53 ) ;
}
}
#else
V_53 -> V_123 = V_53 -> V_64 = 0 ;
#endif
F_43 ( & V_49 -> V_145 ) ;
F_36 ( V_8 , V_49 ) ;
F_40 ( V_8 , V_53 ) ;
V_36: F_18 ( V_8 ) ;
return V_26 ;
}
static int F_44 ( struct V_48 * V_49 )
{
struct V_152 * V_153 ;
struct V_154 * V_145 ;
struct V_128 * V_51 ;
struct V_52 * V_53 = V_49 -> V_53 ;
int V_86 , V_155 ;
if ( V_156 ) {
for ( V_86 = 0 ; V_86 < V_53 -> V_90 ; V_86 ++ ) {
if ( V_53 -> V_91 [ V_86 ] . V_118 == V_156 ) {
V_155 = V_86 ;
F_21 ( & V_49 -> V_47 , V_49 ,
& V_53 -> V_91 [ V_155 ] ) ;
F_37 ( V_143 | V_144 , 60 ,
& V_49 -> V_47 , V_49 ) ;
V_49 -> V_47 . V_157 = 0 ;
goto V_158;
}
}
F_9 ( V_110 L_47
L_48 , V_156 ) ;
V_156 = 0 ;
}
V_86 = 0 ;
F_45 (pos, &info->modelist)
V_86 ++ ;
V_51 = F_10 ( V_86 * sizeof( * V_51 ) , V_30 ) ;
if ( V_51 ) {
V_86 = 0 ;
F_45 (pos, &info->modelist) {
V_145 = F_46 ( V_153 , struct V_154 , V_159 ) ;
V_51 [ V_86 ] = V_145 -> V_51 ;
V_86 ++ ;
}
if ( ! V_160 )
V_160 = V_161 ;
V_86 = F_47 ( & V_49 -> V_47 , V_49 , V_160 , V_51 , V_86 ,
NULL , 8 ) ;
F_17 ( V_51 ) ;
}
if ( V_86 == 0 ) {
V_49 -> V_47 . V_58 = 640 ;
V_49 -> V_47 . V_60 = 480 ;
V_51 = (struct V_128 * )
F_48 ( & V_49 -> V_47 , & V_49 -> V_145 ) ;
if ( V_51 ) {
F_32 ( & V_49 -> V_47 , V_51 ) ;
} else {
V_155 = V_53 -> V_91 [ 0 ] . V_118 ;
F_21 ( & V_49 -> V_47 , V_49 ,
& V_53 -> V_91 [ V_155 ] ) ;
F_37 ( V_143 | V_144 , 60 ,
& V_49 -> V_47 , V_49 ) ;
goto V_158;
}
}
V_155 = F_22 ( V_53 , V_49 -> V_47 . V_58 , V_49 -> V_47 . V_60 ,
V_49 -> V_47 . V_70 , V_93 ) ;
if ( V_155 == - 1 )
return - V_107 ;
F_21 ( & V_49 -> V_47 , V_49 , & V_53 -> V_91 [ V_155 ] ) ;
V_158:
if ( V_53 -> V_104 . V_108 < 0x0300 || V_53 -> V_136 )
F_37 ( V_143 | V_144 , 60 ,
& V_49 -> V_47 , V_49 ) ;
return V_155 ;
}
static int F_49 ( struct V_162 * V_163 , int V_164 ,
int V_165 , struct V_48 * V_49 )
{
struct V_7 * V_8 ;
#ifdef F_50
struct V_52 * V_53 = V_49 -> V_53 ;
int V_86 = V_53 -> V_166 ;
#endif
int V_26 = 0 ;
if ( V_165 + V_164 > 256 )
return - V_107 ;
#ifdef F_50
if ( V_86 >= 0 && V_86 < V_53 -> V_90 &&
V_53 -> V_91 [ V_86 ] . V_119 & V_167 ) {
for ( V_86 = 0 ; V_86 < V_164 ; V_86 ++ ) {
F_51 ( V_165 + V_86 , V_168 ) ;
F_51 ( V_163 [ V_86 ] . V_71 , V_169 ) ;
F_51 ( V_163 [ V_86 ] . V_76 , V_169 ) ;
F_51 ( V_163 [ V_86 ] . V_79 , V_169 ) ;
}
}
#ifdef F_42
else if ( V_53 -> V_123 ) {
__asm__ __volatile__(
"call *(%%esi)"
:
: "a" (0x4f09),
"b" (0),
"c" (count),
"d" (start),
"D" (entries),
"S" (&par->pmi_pal));
}
#endif
else
#endif
{
V_8 = F_20 () ;
if ( ! V_8 )
return - V_31 ;
V_8 -> V_16 . V_96 . V_97 = 0x4f09 ;
V_8 -> V_16 . V_96 . V_121 = 0x0 ;
V_8 -> V_16 . V_96 . V_98 = V_164 ;
V_8 -> V_16 . V_96 . V_99 = V_165 ;
V_8 -> V_16 . V_41 = V_117 ;
V_8 -> V_16 . V_17 = sizeof( struct V_162 ) * V_164 ;
V_8 -> V_19 = V_163 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f )
V_26 = 1 ;
F_18 ( V_8 ) ;
}
return V_26 ;
}
static int F_52 ( unsigned V_170 , unsigned V_71 , unsigned V_76 ,
unsigned V_79 , unsigned V_82 ,
struct V_48 * V_49 )
{
struct V_162 V_171 ;
int V_172 = 16 - V_173 ;
int V_26 = 0 ;
if ( V_170 >= V_49 -> V_174 . V_18 )
return - V_107 ;
if ( V_49 -> V_47 . V_70 == 8 ) {
V_171 . V_71 = V_71 >> V_172 ;
V_171 . V_76 = V_76 >> V_172 ;
V_171 . V_79 = V_79 >> V_172 ;
V_171 . V_175 = 0 ;
V_26 = F_49 ( & V_171 , 1 , V_170 , V_49 ) ;
} else if ( V_170 < 16 ) {
switch ( V_49 -> V_47 . V_70 ) {
case 16 :
if ( V_49 -> V_47 . V_71 . V_72 == 10 ) {
( ( V_106 * ) ( V_49 -> V_176 ) ) [ V_170 ] =
( ( V_71 & 0xf800 ) >> 1 ) |
( ( V_76 & 0xf800 ) >> 6 ) |
( ( V_79 & 0xf800 ) >> 11 ) ;
} else {
( ( V_106 * ) ( V_49 -> V_176 ) ) [ V_170 ] =
( ( V_71 & 0xf800 ) ) |
( ( V_76 & 0xfc00 ) >> 5 ) |
( ( V_79 & 0xf800 ) >> 11 ) ;
}
break;
case 24 :
case 32 :
V_71 >>= 8 ;
V_76 >>= 8 ;
V_79 >>= 8 ;
( ( V_106 * ) ( V_49 -> V_176 ) ) [ V_170 ] =
( V_71 << V_49 -> V_47 . V_71 . V_72 ) |
( V_76 << V_49 -> V_47 . V_76 . V_72 ) |
( V_79 << V_49 -> V_47 . V_79 . V_72 ) ;
break;
}
}
return V_26 ;
}
static int F_53 ( struct V_177 * V_174 , struct V_48 * V_49 )
{
struct V_162 * V_163 ;
int V_172 = 16 - V_173 ;
int V_86 , V_26 = 0 ;
if ( V_49 -> V_47 . V_70 == 8 ) {
if ( V_174 -> V_165 + V_174 -> V_18 > V_49 -> V_174 . V_165 +
V_49 -> V_174 . V_18 || V_174 -> V_165 < V_49 -> V_174 . V_165 )
return - V_107 ;
V_163 = F_24 ( sizeof( * V_163 ) * V_174 -> V_18 , V_30 ) ;
if ( ! V_163 )
return - V_31 ;
for ( V_86 = 0 ; V_86 < V_174 -> V_18 ; V_86 ++ ) {
V_163 [ V_86 ] . V_71 = V_174 -> V_71 [ V_86 ] >> V_172 ;
V_163 [ V_86 ] . V_76 = V_174 -> V_76 [ V_86 ] >> V_172 ;
V_163 [ V_86 ] . V_79 = V_174 -> V_79 [ V_86 ] >> V_172 ;
V_163 [ V_86 ] . V_175 = 0 ;
}
V_26 = F_49 ( V_163 , V_174 -> V_18 , V_174 -> V_165 , V_49 ) ;
F_17 ( V_163 ) ;
} else {
for ( V_86 = 0 ; V_86 < V_174 -> V_18 ; V_86 ++ ) {
V_26 |= F_52 ( V_174 -> V_165 + V_86 , V_174 -> V_71 [ V_86 ] ,
V_174 -> V_76 [ V_86 ] , V_174 -> V_79 [ V_86 ] ,
0 , V_49 ) ;
}
}
return V_26 ;
}
static int F_54 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
#ifdef F_42
int V_72 ;
struct V_52 * V_53 = V_49 -> V_53 ;
V_72 = ( V_47 -> V_69 * V_49 -> V_65 . V_178 + V_47 -> V_68 ) / 4 ;
if ( V_53 -> V_126 ) {
__asm__ __volatile__(
"call *(%%edi)"
:
: "a" (0x4f07),
"b" (0),
"c" (offset),
"d" (offset >> 16),
"D" (&par->pmi_start));
}
#endif
return 0 ;
}
static int F_55 ( int V_179 , struct V_48 * V_49 )
{
struct V_7 * V_8 ;
int V_26 = 1 ;
#ifdef F_50
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_53 -> V_104 . V_180 & V_181 ) {
int V_182 = 10000 ;
V_34 V_10 = 0 , V_183 = 0 ;
if ( V_179 == V_184 ) {
V_10 = 0x20 ;
V_183 = 0x00 ;
V_26 = 0 ;
} else {
V_10 = 0x00 ;
V_183 = 0x80 ;
V_26 = ( V_179 == V_185 ) ? 0 : - V_107 ;
}
F_56 ( NULL , 0x00 , 0x01 ) ;
V_10 |= F_57 ( NULL , 0x01 ) & ~ 0x20 ;
F_56 ( NULL , 0x00 , V_10 ) ;
V_183 |= F_58 ( NULL , 0x17 ) & ~ 0x80 ;
while ( V_182 -- ) ;
F_59 ( NULL , 0x17 , V_183 ) ;
F_56 ( NULL , 0x00 , 0x03 ) ;
} else
#endif
{
V_8 = F_20 () ;
if ( ! V_8 )
return - V_31 ;
V_8 -> V_16 . V_96 . V_97 = 0x4f10 ;
switch ( V_179 ) {
case V_185 :
V_8 -> V_16 . V_96 . V_121 = 0x0001 ;
break;
case V_186 :
V_8 -> V_16 . V_96 . V_121 = 0x0101 ;
break;
case V_184 :
V_8 -> V_16 . V_96 . V_121 = 0x0401 ;
break;
default:
goto V_36;
}
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f )
V_26 = 1 ;
V_36: F_18 ( V_8 ) ;
}
return V_26 ;
}
static int F_60 ( struct V_48 * V_49 , int V_187 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
int V_188 = F_61 ( & V_53 -> V_189 ) ;
V_34 * V_19 = NULL ;
if ( ! V_188 && V_53 -> V_95 ) {
V_19 = F_23 ( V_53 ) ;
if ( F_62 ( V_19 ) ) {
F_9 ( V_28 L_49
L_50 , F_63 ( V_19 ) ) ;
} else {
V_53 -> V_190 = V_19 ;
}
}
F_64 ( & V_53 -> V_189 ) ;
return 0 ;
}
static int F_65 ( struct V_48 * V_49 , int V_187 )
{
struct V_7 * V_8 = NULL ;
struct V_52 * V_53 = V_49 -> V_53 ;
int V_188 = F_61 ( & V_53 -> V_189 ) ;
if ( ! V_188 )
return - V_107 ;
if ( V_188 != 1 )
goto V_36;
V_8 = F_20 () ;
if ( ! V_8 )
goto V_36;
V_8 -> V_16 . V_96 . V_97 = 0x0003 ;
F_8 ( V_8 ) ;
F_26 ( V_53 , V_53 -> V_190 ) ;
V_36:
F_66 ( & V_53 -> V_189 ) ;
if ( V_8 )
F_18 ( V_8 ) ;
return 0 ;
}
static int F_67 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
struct V_7 * V_8 = NULL ;
struct V_191 * V_192 = NULL ;
struct V_50 * V_51 = NULL ;
int V_86 , V_26 = 0 , V_85 = V_49 -> V_47 . V_70 ;
if ( V_85 > 8 && V_85 != 32 )
V_85 = V_49 -> V_47 . V_71 . V_74 + V_49 -> V_47 . V_76 . V_74 +
V_49 -> V_47 . V_79 . V_74 ;
V_86 = F_22 ( V_53 , V_49 -> V_47 . V_58 , V_49 -> V_47 . V_60 , V_85 ,
V_93 | V_92 ) ;
if ( V_86 >= 0 )
V_51 = & V_53 -> V_91 [ V_86 ] ;
else
return - V_107 ;
V_8 = F_20 () ;
if ( ! V_8 )
return - V_31 ;
V_193:
V_8 -> V_16 . V_96 . V_97 = 0x4f02 ;
V_8 -> V_16 . V_96 . V_121 = V_51 -> V_118 | 0x4000 ;
if ( V_53 -> V_104 . V_108 >= 0x0300 && ! V_53 -> V_136 &&
V_49 -> V_47 . V_157 != 0 ) {
V_8 -> V_16 . V_96 . V_121 |= 0x0800 ;
V_8 -> V_16 . V_41 = V_117 ;
V_192 = F_10 ( sizeof( struct V_191 ) , V_30 ) ;
if ( ! V_192 ) {
V_26 = - V_31 ;
goto V_36;
}
V_192 -> V_194 = V_49 -> V_47 . V_58 + V_49 -> V_47 . V_195 ;
V_192 -> V_196 = V_192 -> V_194 + V_49 -> V_47 . V_197 ;
V_192 -> V_198 = V_192 -> V_196 + V_49 -> V_47 . V_199 ;
V_192 -> V_200 = V_49 -> V_47 . V_60 + V_49 -> V_47 . V_201 ;
V_192 -> V_202 = V_192 -> V_200 + V_49 -> V_47 . V_203 ;
V_192 -> V_204 = V_192 -> V_202 + V_49 -> V_47 . V_205 ;
V_192 -> V_206 = F_68 ( V_49 -> V_47 . V_157 ) * 1000 ;
V_192 -> V_207 = ( T_1 ) ( 100 * ( V_192 -> V_206 /
( V_192 -> V_204 * V_192 -> V_198 ) ) ) ;
if ( V_49 -> V_47 . V_54 & V_208 )
V_192 -> V_41 |= 0x1 ;
if ( V_49 -> V_47 . V_54 & V_209 )
V_192 -> V_41 |= 0x2 ;
if ( ! ( V_49 -> V_47 . V_56 & V_210 ) )
V_192 -> V_41 |= 0x4 ;
if ( ! ( V_49 -> V_47 . V_56 & V_57 ) )
V_192 -> V_41 |= 0x8 ;
memcpy ( & V_53 -> V_192 , V_192 , sizeof( * V_192 ) ) ;
} else {
memset ( & V_53 -> V_192 , 0 , sizeof( * V_192 ) ) ;
}
V_8 -> V_16 . V_17 = sizeof( struct V_191 ) ;
V_8 -> V_19 = & V_53 -> V_192 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f ) {
if ( V_192 != NULL ) {
F_9 ( V_28 L_51
L_52
L_53 , V_8 -> V_16 . V_96 . V_97 , V_26 ) ;
F_19 ( V_8 ) ;
F_17 ( V_192 ) ;
V_192 = NULL ;
V_49 -> V_47 . V_157 = 0 ;
goto V_193;
} else {
F_9 ( V_38 L_54
L_55 , V_8 -> V_16 . V_96 . V_97 , V_26 ) ;
V_26 = - V_107 ;
goto V_36;
}
}
V_53 -> V_166 = V_86 ;
if ( V_53 -> V_104 . V_180 & V_211 &&
V_51 -> V_70 <= 8 ) {
F_19 ( V_8 ) ;
V_8 -> V_16 . V_96 . V_97 = 0x4f08 ;
V_8 -> V_16 . V_96 . V_121 = 0x0800 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_96 . V_97 & 0xffff ) != 0x004f ||
( ( V_8 -> V_16 . V_96 . V_121 & 0xff00 ) >> 8 ) != 8 ) {
V_173 = 6 ;
} else {
V_173 = 8 ;
}
}
V_49 -> V_65 . V_212 = ( V_49 -> V_47 . V_70 == 8 ) ?
V_213 : V_214 ;
V_49 -> V_65 . V_178 = V_51 -> V_67 ;
V_36: if ( V_192 != NULL )
F_17 ( V_192 ) ;
F_18 ( V_8 ) ;
return V_26 ;
}
static void F_69 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
const struct V_128 * V_51 ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( ! V_47 -> V_157 )
return;
if ( V_53 -> V_104 . V_108 < 0x0300 ) {
F_37 ( V_143 | V_144 , 60 , V_47 , V_49 ) ;
return;
}
if ( ! F_33 ( V_47 , V_49 ) )
return;
V_51 = F_48 ( V_47 , & V_49 -> V_145 ) ;
if ( V_51 ) {
if ( V_51 -> V_58 == V_47 -> V_58 && V_51 -> V_60 == V_47 -> V_60 &&
! ( V_51 -> V_54 & ( V_209 | V_208 ) ) ) {
F_32 ( V_47 , V_51 ) ;
return;
}
}
if ( V_49 -> V_129 . V_130 && ! F_37 ( V_215 , 0 , V_47 , V_49 ) )
return;
V_47 -> V_157 = 0 ;
}
static int F_70 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
struct V_50 * V_51 = NULL ;
int V_87 = - 1 ;
int V_85 = V_47 -> V_71 . V_74 + V_47 -> V_76 . V_74 + V_47 -> V_79 . V_74 ;
if ( V_85 == 0 || abs ( V_85 - V_47 -> V_70 ) >= 8 )
V_85 = V_47 -> V_70 ;
V_87 = F_22 ( V_53 , V_47 -> V_58 , V_47 -> V_60 , V_85 ,
V_93 ) ;
if ( V_87 == - 1 )
return - V_107 ;
V_51 = & V_53 -> V_91 [ V_87 ] ;
F_21 ( V_47 , V_49 , V_51 ) ;
if ( V_47 -> V_60 * V_51 -> V_67 > V_49 -> V_65 . V_66
&& V_49 -> V_65 . V_66 )
return - V_107 ;
if ( ( V_47 -> V_54 & V_208 ) &&
! ( V_53 -> V_91 [ V_87 ] . V_119 & 0x100 ) )
V_47 -> V_54 &= ~ V_208 ;
if ( ( V_47 -> V_54 & V_209 ) &&
! ( V_53 -> V_91 [ V_87 ] . V_119 & 0x200 ) )
V_47 -> V_54 &= ~ V_209 ;
F_69 ( V_47 , V_49 ) ;
V_47 -> V_62 = V_47 -> V_58 ;
V_47 -> V_63 = ( V_53 -> V_64 ) ?
V_49 -> V_65 . V_66 / V_51 -> V_67 :
V_47 -> V_60 ;
return 0 ;
}
static void F_71 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
unsigned int V_216 ;
unsigned int V_217 ;
unsigned int V_218 ;
struct V_52 * V_53 = V_49 -> V_53 ;
int V_86 , V_88 ;
V_49 -> V_176 = ( ( V_34 * ) V_49 -> V_53 + sizeof( struct V_52 ) ) ;
V_49 -> V_65 = V_219 ;
V_49 -> V_65 . V_220 = V_53 -> V_64 ? 1 : 0 ;
V_49 -> V_65 . V_221 = ( V_53 -> V_64 > 1 ) ? 1 : 0 ;
if ( ! V_179 )
V_49 -> V_222 -> V_223 = NULL ;
V_217 = 0 ;
for ( V_86 = 0 ; V_86 < V_53 -> V_90 ; V_86 ++ ) {
V_88 = V_53 -> V_91 [ V_86 ] . V_67 *
V_53 -> V_91 [ V_86 ] . V_61 ;
if ( V_88 > V_217 )
V_217 = V_88 ;
}
V_217 *= 2 ;
if ( V_51 != NULL ) {
V_216 = V_49 -> V_47 . V_60 * V_51 -> V_67 ;
} else {
V_216 = V_49 -> V_47 . V_60 * V_49 -> V_47 . V_58 *
( ( V_49 -> V_47 . V_70 + 7 ) >> 3 ) ;
}
V_218 = V_53 -> V_104 . V_224 * 65536 ;
if ( V_225 )
V_218 = V_225 * 1024 * 1024 ;
if ( V_218 < V_216 )
V_218 = V_216 ;
if ( V_226 )
V_217 = V_226 * 1024 * 1024 ;
if ( V_217 < V_216 )
V_217 = V_216 ;
if ( V_217 > V_218 )
V_217 = V_218 ;
V_49 -> V_65 . V_66 = V_217 ;
V_49 -> V_65 . V_227 = V_51 -> V_228 ;
V_49 -> V_47 . V_63 = V_49 -> V_65 . V_66 /
V_51 -> V_67 ;
if ( V_53 -> V_64 && V_49 -> V_47 . V_63 > V_49 -> V_47 . V_60 ) {
F_9 ( V_110 L_56
L_57
L_58 ,
( V_53 -> V_64 > 1 ) ? L_59 : L_60 ,
V_49 -> V_47 . V_63 ) ;
} else {
F_9 ( V_110 L_61 ) ;
V_49 -> V_47 . V_63 = V_49 -> V_47 . V_60 ;
V_53 -> V_64 = 0 ;
}
V_49 -> V_41 = V_229 |
( V_53 -> V_64 ? V_230 : 0 ) ;
if ( ! V_53 -> V_64 )
V_49 -> V_222 -> V_231 = NULL ;
}
static void F_72 ( struct V_48 * V_49 )
{
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_232 && ! ( V_49 -> V_65 . V_227 & ( V_233 - 1 ) ) ) {
int V_234 = V_49 -> V_65 . V_66 ;
int V_235 ;
V_234 = F_73 ( V_234 ) ;
do {
V_235 = F_74 ( V_49 -> V_65 . V_227 , V_234 ) ;
V_234 >>= 1 ;
} while ( V_234 >= V_233 && V_235 == - V_107 );
if ( V_235 >= 0 )
V_53 -> V_236 = V_235 ;
}
}
static void F_75 ( struct V_48 * V_49 )
{
V_49 -> V_237 = F_76 ( V_49 -> V_65 . V_227 , V_49 -> V_65 . V_66 ) ;
}
static T_2 F_77 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
return snprintf ( V_19 , V_233 , L_62 , V_53 -> V_104 . V_108 ) ;
}
static T_2 F_80 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
int V_242 = 0 , V_86 ;
for ( V_86 = 0 ; V_86 < V_53 -> V_90 && V_242 < V_233 ; V_86 ++ ) {
V_242 += snprintf ( V_19 + V_242 , V_233 - V_242 ,
L_63 ,
V_53 -> V_91 [ V_86 ] . V_59 , V_53 -> V_91 [ V_86 ] . V_61 ,
V_53 -> V_91 [ V_86 ] . V_85 , V_53 -> V_91 [ V_86 ] . V_118 ) ;
}
return V_242 ;
}
static T_2 F_81 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_53 -> V_104 . V_111 )
return snprintf ( V_19 , V_233 , L_64 , ( char * )
( & V_53 -> V_104 ) + V_53 -> V_104 . V_111 ) ;
else
return 0 ;
}
static T_2 F_82 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_53 -> V_104 . V_112 )
return snprintf ( V_19 , V_233 , L_64 , ( char * )
( & V_53 -> V_104 ) + V_53 -> V_104 . V_112 ) ;
else
return 0 ;
}
static T_2 F_83 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_53 -> V_104 . V_113 )
return snprintf ( V_19 , V_233 , L_64 , ( char * )
( & V_53 -> V_104 ) + V_53 -> V_104 . V_113 ) ;
else
return 0 ;
}
static T_2 F_84 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_53 -> V_104 . V_114 )
return snprintf ( V_19 , V_233 , L_64 ,
( char * ) ( & V_53 -> V_104 ) + V_53 -> V_104 . V_114 ) ;
else
return 0 ;
}
static T_2 F_85 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
return snprintf ( V_19 , V_233 , L_65 , V_53 -> V_136 ) ;
}
static T_2 F_86 ( struct V_238 * V_239 ,
struct V_240 * V_241 , const char * V_19 , T_3 V_164 )
{
struct V_48 * V_49 = F_78 ( F_79 ( V_239 ) ) ;
struct V_52 * V_53 = V_49 -> V_53 ;
if ( V_164 > 0 ) {
if ( V_19 [ 0 ] == '0' )
V_53 -> V_136 = 0 ;
else
V_53 -> V_136 = 1 ;
}
return V_164 ;
}
static int F_87 ( struct V_243 * V_239 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 = NULL ;
struct V_52 * V_53 ;
int V_26 = 0 , V_86 ;
V_49 = F_88 ( sizeof( * V_53 ) + sizeof( V_106 ) * 256 , & V_239 -> V_239 ) ;
if ( ! V_49 )
return - V_31 ;
V_53 = V_49 -> V_53 ;
V_26 = F_41 ( V_49 ) ;
if ( V_26 ) {
F_9 ( V_38 L_66 , V_26 ) ;
goto V_36;
}
V_49 -> V_222 = & V_244 ;
V_86 = F_44 ( V_49 ) ;
if ( V_86 < 0 ) {
V_26 = - V_107 ;
goto V_36;
} else {
V_51 = & V_53 -> V_91 [ V_86 ] ;
}
if ( F_89 ( & V_49 -> V_174 , 256 , 0 ) < 0 ) {
V_26 = - V_245 ;
goto V_36;
}
F_71 ( V_49 , V_51 ) ;
if ( ! F_90 ( 0x3c0 , 32 , L_67 ) ) {
F_9 ( V_38 L_68 ) ;
V_26 = - V_246 ;
goto V_247;
}
if ( ! F_91 ( V_49 -> V_65 . V_227 , V_49 -> V_65 . V_66 ,
L_67 ) ) {
F_9 ( V_38 L_69
L_70 , V_49 -> V_65 . V_227 ) ;
V_26 = - V_246 ;
goto V_248;
}
F_72 ( V_49 ) ;
F_75 ( V_49 ) ;
if ( ! V_49 -> V_237 ) {
F_9 ( V_38
L_71
L_72 ,
V_49 -> V_65 . V_66 , V_49 -> V_65 . V_227 ) ;
V_26 = - V_246 ;
goto V_249;
}
F_92 ( V_239 , V_49 ) ;
if ( F_93 ( V_49 ) < 0 ) {
F_9 ( V_38
L_73 ) ;
V_26 = - V_107 ;
goto V_250;
}
F_9 ( V_110 L_74
L_75 , V_49 -> V_65 . V_227 ,
V_49 -> V_237 , V_49 -> V_65 . V_66 / 1024 ,
V_53 -> V_104 . V_224 * 64 ) ;
F_9 ( V_110 L_76 , V_49 -> V_251 ,
V_49 -> V_65 . V_32 ) ;
V_26 = F_94 ( & V_239 -> V_239 . V_252 , & V_253 ) ;
if ( V_26 != 0 )
F_9 ( V_28 L_77 ,
V_49 -> V_251 ) ;
return 0 ;
V_250:
F_95 ( V_49 -> V_237 ) ;
V_249:
F_96 ( V_49 -> V_65 . V_227 , V_49 -> V_65 . V_66 ) ;
V_248:
F_97 ( 0x3c0 , 32 ) ;
V_247:
if ( ! F_98 ( & V_49 -> V_145 ) )
F_99 ( & V_49 -> V_145 ) ;
F_100 ( V_49 -> V_129 . V_149 ) ;
F_101 ( & V_49 -> V_174 ) ;
V_36:
if ( V_53 -> V_91 )
F_17 ( V_53 -> V_91 ) ;
F_102 ( V_49 ) ;
return V_26 ;
}
static int F_103 ( struct V_243 * V_239 )
{
struct V_48 * V_49 = F_78 ( V_239 ) ;
if ( V_49 ) {
struct V_52 * V_53 = V_49 -> V_53 ;
F_104 ( & V_239 -> V_239 . V_252 , & V_253 ) ;
F_105 ( V_49 ) ;
F_97 ( 0x3c0 , 32 ) ;
F_95 ( V_49 -> V_237 ) ;
F_106 ( V_53 -> V_236 ) ;
F_96 ( V_49 -> V_65 . V_227 , V_49 -> V_65 . V_66 ) ;
F_100 ( V_49 -> V_129 . V_149 ) ;
F_101 ( & V_49 -> V_174 ) ;
if ( V_53 ) {
if ( V_53 -> V_91 )
F_17 ( V_53 -> V_91 ) ;
if ( V_53 -> V_190 )
F_17 ( V_53 -> V_190 ) ;
if ( V_53 -> V_254 )
F_17 ( V_53 -> V_254 ) ;
}
F_102 ( V_49 ) ;
}
return 0 ;
}
static int F_107 ( char * V_255 )
{
char * V_256 ;
if ( ! V_255 || ! * V_255 )
return 0 ;
while ( ( V_256 = F_108 ( & V_255 , L_78 ) ) != NULL ) {
if ( ! * V_256 ) continue;
if ( ! strcmp ( V_256 , L_79 ) )
V_64 = 0 ;
else if ( ! strcmp ( V_256 , L_60 ) )
V_64 = 1 ;
else if ( ! strcmp ( V_256 , L_59 ) )
V_64 = 2 ;
else if ( ! strcmp ( V_256 , L_80 ) )
V_123 = 0 ;
else if ( ! strcmp ( V_256 , L_81 ) )
V_123 = 1 ;
else if ( ! strncmp ( V_256 , L_82 , 5 ) )
V_232 = F_109 ( V_256 + 5 , NULL , 0 ) ;
else if ( ! strcmp ( V_256 , L_83 ) )
V_232 = 0 ;
else if ( ! strcmp ( V_256 , L_84 ) )
V_136 = 1 ;
else if ( ! strcmp ( V_256 , L_85 ) )
V_131 = 1 ;
else if ( ! strcmp ( V_256 , L_86 ) )
V_179 = 0 ;
else if ( ! strncmp ( V_256 , L_87 , 7 ) )
V_225 = F_109 ( V_256 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_88 , 7 ) )
V_226 = F_109 ( V_256 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_89 , 6 ) )
V_139 = F_109 ( V_256 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_90 , 6 ) )
V_138 = F_109 ( V_256 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_91 , 7 ) )
V_137 = F_109 ( V_256 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_92 , 8 ) )
V_156 = F_109 ( V_256 + 8 , NULL , 0 ) ;
else if ( V_256 [ 0 ] >= '0' && V_256 [ 0 ] <= '9' ) {
V_160 = V_256 ;
} else {
F_9 ( V_28
L_93 , V_256 ) ;
}
}
if ( V_232 != 3 && V_232 != 0 )
F_110 ( L_94 , V_232 ) ;
return 0 ;
}
static T_2 F_111 ( struct V_257 * V_239 , char * V_19 )
{
return snprintf ( V_19 , V_233 , L_64 , V_23 ) ;
}
static T_2 F_112 ( struct V_257 * V_239 , const char * V_19 ,
T_3 V_164 )
{
strncpy ( V_23 , V_19 , V_258 ) ;
return V_164 ;
}
static int F_113 ( void )
{
int V_26 ;
#ifndef F_114
char * V_259 = NULL ;
if ( F_115 ( L_67 , & V_259 ) )
return - V_260 ;
F_107 ( V_259 ) ;
#endif
V_26 = F_116 ( & V_33 , L_67 , F_1 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_117 ( & V_261 ) ;
if ( ! V_26 ) {
V_262 = F_118 ( L_67 , 0 ) ;
if ( V_262 )
V_26 = F_119 ( V_262 ) ;
else
V_26 = - V_31 ;
if ( V_26 ) {
if ( V_262 )
F_120 ( V_262 ) ;
F_121 ( & V_261 ) ;
F_122 ( & V_33 ) ;
return V_26 ;
}
V_26 = F_123 ( & V_261 . V_263 ,
& V_264 ) ;
if ( V_26 ) {
F_9 ( V_28 L_95
L_96 ) ;
V_26 = 0 ;
}
}
return V_26 ;
}
static void F_124 ( void )
{
struct V_7 * V_8 ;
if ( V_39 ) {
V_8 = F_20 () ;
if ( V_8 ) {
V_8 -> V_16 . V_41 = V_42 ;
F_8 ( V_8 ) ;
F_18 ( V_8 ) ;
}
}
F_122 ( & V_33 ) ;
F_125 ( & V_261 . V_263 , & V_264 ) ;
F_126 ( V_262 ) ;
F_121 ( & V_261 ) ;
}
static int F_127 ( const char * V_265 , const struct V_266 * V_267 )
{
V_64 = 0 ;
if ( ! strcmp ( V_265 , L_79 ) )
V_64 = 0 ;
else if ( ! strcmp ( V_265 , L_60 ) )
V_64 = 1 ;
else if ( ! strcmp ( V_265 , L_59 ) )
V_64 = 2 ;
else
return - V_107 ;
return 0 ;
}
