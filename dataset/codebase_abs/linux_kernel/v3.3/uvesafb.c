static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! F_2 ( F_3 () , V_9 ) )
return;
if ( V_2 -> V_10 >= V_11 )
return;
F_4 ( & V_12 ) ;
V_8 = V_13 [ V_2 -> V_10 ] ;
if ( ! V_8 || V_2 -> V_14 != V_8 -> V_14 ) {
F_5 ( & V_12 ) ;
return;
}
V_6 = (struct V_5 * ) V_2 -> V_15 ;
if ( V_8 -> V_16 . V_17 < V_6 -> V_17 ||
V_6 -> V_17 > V_2 -> V_18 - sizeof( * V_6 ) ) {
F_5 ( & V_12 ) ;
return;
}
V_13 [ V_2 -> V_10 ] = NULL ;
F_5 ( & V_12 ) ;
memcpy ( & V_8 -> V_16 , V_6 , sizeof( * V_6 ) ) ;
if ( V_8 -> V_16 . V_17 && V_8 -> V_19 )
memcpy ( V_8 -> V_19 , V_6 + 1 , V_8 -> V_16 . V_17 ) ;
F_6 ( V_8 -> V_20 ) ;
return;
}
static int F_7 ( void )
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
return F_8 ( V_23 , V_22 , V_21 , 1 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
static int V_10 ;
struct V_1 * V_24 ;
int V_25 ;
int V_18 = sizeof( V_8 -> V_16 ) + V_8 -> V_16 . V_17 ;
if ( sizeof( * V_24 ) + V_18 > V_26 ) {
F_10 ( V_27 L_3
L_4 , ( int ) ( sizeof( * V_24 ) + V_18 ) ) ;
return - V_28 ;
}
V_24 = F_11 ( sizeof( * V_24 ) + V_18 , V_29 ) ;
if ( ! V_24 )
return - V_30 ;
F_12 ( V_8 -> V_20 ) ;
memcpy ( & V_24 -> V_31 , & V_32 , sizeof( V_24 -> V_31 ) ) ;
V_24 -> V_10 = V_10 ;
V_24 -> V_18 = V_18 ;
V_24 -> V_14 = F_13 () ;
memcpy ( V_24 + 1 , & V_8 -> V_16 , sizeof( V_8 -> V_16 ) ) ;
memcpy ( ( V_33 * ) ( V_24 + 1 ) + sizeof( V_8 -> V_16 ) , V_8 -> V_19 , V_8 -> V_16 . V_17 ) ;
V_8 -> V_14 = V_24 -> V_14 ;
F_4 ( & V_12 ) ;
if ( V_13 [ V_10 ] ) {
F_5 ( & V_12 ) ;
V_25 = - V_34 ;
goto V_35;
}
V_13 [ V_10 ] = V_8 ;
F_5 ( & V_12 ) ;
V_25 = F_14 ( V_24 , 0 , V_29 ) ;
if ( V_25 == - V_36 ) {
V_25 = F_7 () ;
if ( V_25 ) {
F_10 ( V_37 L_5 ,
V_23 ) ;
F_10 ( V_37 L_6
L_7 ) ;
} else {
V_38 = 1 ;
V_25 = F_14 ( V_24 , 0 , F_15 () ) ;
if ( V_25 == - V_39 )
V_25 = 0 ;
}
} else if ( V_25 == - V_39 )
V_25 = 0 ;
if ( ! V_25 && ! ( V_8 -> V_16 . V_40 & V_41 ) )
V_25 = ! F_16 ( V_8 -> V_20 ,
F_17 ( V_42 ) ) ;
F_4 ( & V_12 ) ;
V_13 [ V_10 ] = NULL ;
F_5 ( & V_12 ) ;
V_10 ++ ;
if ( V_10 >= V_11 )
V_10 = 0 ;
V_35:
F_18 ( V_24 ) ;
return V_25 ;
}
static void F_19 ( struct V_7 * V_8 )
{
if ( V_8 ) {
if ( V_8 -> V_20 )
F_18 ( V_8 -> V_20 ) ;
F_18 ( V_8 ) ;
}
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_43 * V_44 = V_8 -> V_20 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_20 = V_44 ;
}
static struct V_7 * F_21 ( void )
{
struct V_7 * V_8 ;
V_8 = F_11 ( sizeof( * V_8 ) , V_29 ) ;
if ( V_8 ) {
V_8 -> V_20 = F_11 ( sizeof( * V_8 -> V_20 ) , V_29 ) ;
if ( ! V_8 -> V_20 ) {
F_18 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_8 ;
}
static void F_22 ( struct V_45 * V_46 ,
struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_51 * V_52 = V_48 -> V_52 ;
V_46 -> V_53 = V_54 ;
V_46 -> V_55 = V_56 ;
V_46 -> V_57 = V_50 -> V_58 ;
V_46 -> V_59 = V_50 -> V_60 ;
V_46 -> V_61 = V_50 -> V_58 ;
V_46 -> V_62 = ( V_52 -> V_63 ) ?
V_48 -> V_64 . V_65 / V_50 -> V_66 :
V_50 -> V_60 ;
V_46 -> V_67 = 0 ;
V_46 -> V_68 = 0 ;
V_46 -> V_69 = V_50 -> V_69 ;
if ( V_46 -> V_69 == 15 )
V_46 -> V_69 = 16 ;
if ( V_46 -> V_69 > 8 ) {
V_46 -> V_70 . V_71 = V_50 -> V_72 ;
V_46 -> V_70 . V_73 = V_50 -> V_74 ;
V_46 -> V_75 . V_71 = V_50 -> V_76 ;
V_46 -> V_75 . V_73 = V_50 -> V_77 ;
V_46 -> V_78 . V_71 = V_50 -> V_79 ;
V_46 -> V_78 . V_73 = V_50 -> V_80 ;
V_46 -> V_81 . V_71 = V_50 -> V_82 ;
V_46 -> V_81 . V_73 = V_50 -> V_83 ;
} else {
V_46 -> V_70 . V_71 = 0 ;
V_46 -> V_75 . V_71 = 0 ;
V_46 -> V_78 . V_71 = 0 ;
V_46 -> V_81 . V_71 = 0 ;
V_46 -> V_70 . V_73 = 8 ;
V_46 -> V_75 . V_73 = 8 ;
V_46 -> V_78 . V_73 = 8 ;
V_46 -> V_81 . V_73 = 0 ;
}
}
static int F_23 ( struct V_51 * V_52 ,
int V_57 , int V_59 , int V_84 , unsigned char V_40 )
{
int V_85 , V_86 = - 1 , V_87 = 0 , V_88 = 0x7fffffff ;
for ( V_85 = 0 ; V_85 < V_52 -> V_89 ; V_85 ++ ) {
V_87 = abs ( V_52 -> V_90 [ V_85 ] . V_58 - V_57 ) +
abs ( V_52 -> V_90 [ V_85 ] . V_60 - V_59 ) +
abs ( V_84 - V_52 -> V_90 [ V_85 ] . V_84 ) ;
if ( V_87 == 0 )
return V_85 ;
if ( V_87 < V_88 || ( V_87 == V_88 && V_52 -> V_90 [ V_85 ] . V_84 > V_84 ) ) {
V_88 = V_87 ;
V_86 = V_85 ;
}
}
V_85 = 1 ;
if ( V_40 & V_91 &&
V_52 -> V_90 [ V_86 ] . V_84 != V_84 )
V_85 = 0 ;
if ( V_40 & V_92 && V_88 > 24 )
V_85 = 0 ;
if ( V_85 != 0 )
return V_86 ;
else
return - 1 ;
}
static V_33 * F_24 ( struct V_51 * V_52 )
{
struct V_7 * V_8 ;
V_33 * V_93 ;
int V_25 ;
if ( ! V_52 -> V_94 )
return NULL ;
V_93 = F_25 ( V_52 -> V_94 , V_29 ) ;
if ( ! V_93 )
return NULL ;
V_8 = F_21 () ;
if ( ! V_8 ) {
F_18 ( V_93 ) ;
return NULL ;
}
V_8 -> V_16 . V_95 . V_96 = 0x4f04 ;
V_8 -> V_16 . V_95 . V_97 = 0x000f ;
V_8 -> V_16 . V_95 . V_98 = 0x0001 ;
V_8 -> V_16 . V_40 = V_99 | V_100 ;
V_8 -> V_16 . V_17 = V_52 -> V_94 ;
V_8 -> V_19 = V_93 ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f ) {
F_10 ( V_27 L_8
L_9 ,
V_8 -> V_16 . V_95 . V_96 , V_25 ) ;
F_18 ( V_93 ) ;
V_93 = NULL ;
}
F_19 ( V_8 ) ;
return V_93 ;
}
static void F_26 ( struct V_51 * V_52 , V_33 * V_101 )
{
struct V_7 * V_8 ;
int V_25 ;
if ( ! V_101 )
return;
V_8 = F_21 () ;
if ( ! V_8 )
return;
V_8 -> V_16 . V_95 . V_96 = 0x4f04 ;
V_8 -> V_16 . V_95 . V_97 = 0x000f ;
V_8 -> V_16 . V_95 . V_98 = 0x0002 ;
V_8 -> V_16 . V_17 = V_52 -> V_94 ;
V_8 -> V_16 . V_40 = V_100 ;
V_8 -> V_19 = V_101 ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f )
F_10 ( V_27 L_10
L_9 ,
V_8 -> V_16 . V_95 . V_96 , V_25 ) ;
F_19 ( V_8 ) ;
}
static int T_1 F_27 ( struct V_7 * V_8 ,
struct V_51 * V_52 )
{
int V_25 ;
V_8 -> V_16 . V_95 . V_96 = 0x4f00 ;
V_8 -> V_16 . V_40 = V_102 ;
V_8 -> V_16 . V_17 = sizeof( struct V_103 ) ;
V_8 -> V_19 = & V_52 -> V_103 ;
strncpy ( V_52 -> V_103 . V_104 , L_11 , 4 ) ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f ) {
F_10 ( V_37 L_12
L_13 , ( V_105 ) V_8 -> V_16 . V_95 . V_96 ,
V_25 ) ;
return - V_106 ;
}
if ( V_52 -> V_103 . V_107 < 0x0200 ) {
F_10 ( V_37 L_14
L_15 ) ;
return - V_106 ;
}
if ( ! V_52 -> V_103 . V_108 ) {
F_10 ( V_37 L_16 ) ;
return - V_106 ;
}
F_10 ( V_109 L_17 ) ;
if ( V_52 -> V_103 . V_110 )
F_10 ( L_18 ,
( ( char * ) V_8 -> V_19 ) + V_52 -> V_103 . V_110 ) ;
if ( V_52 -> V_103 . V_111 )
F_10 ( L_18 ,
( ( char * ) V_8 -> V_19 ) + V_52 -> V_103 . V_111 ) ;
if ( V_52 -> V_103 . V_112 )
F_10 ( L_18 ,
( ( char * ) V_8 -> V_19 ) + V_52 -> V_103 . V_112 ) ;
if ( V_52 -> V_103 . V_113 )
F_10 ( L_19 ,
( ( char * ) V_8 -> V_19 ) + V_52 -> V_103 . V_113 ) ;
F_10 ( L_20 , ( ( V_52 -> V_103 . V_107 & 0xff00 ) >> 8 ) ,
V_52 -> V_103 . V_107 & 0xff ) ;
return 0 ;
}
static int T_1 F_28 ( struct V_7 * V_8 ,
struct V_51 * V_52 )
{
int V_114 = 0 , V_25 ;
T_2 * V_50 ;
V_52 -> V_89 = 0 ;
V_50 = ( T_2 * ) ( ( ( V_33 * ) & V_52 -> V_103 ) + V_52 -> V_103 . V_108 ) ;
while ( * V_50 != 0xffff ) {
V_52 -> V_89 ++ ;
V_50 ++ ;
}
V_52 -> V_90 = F_11 ( sizeof( struct V_49 ) *
V_52 -> V_89 , V_29 ) ;
if ( ! V_52 -> V_90 )
return - V_30 ;
V_50 = ( T_2 * ) ( ( ( V_33 * ) & V_52 -> V_103 ) + V_52 -> V_103 . V_108 ) ;
while ( * V_50 != 0xffff ) {
struct V_49 * V_115 ;
F_20 ( V_8 ) ;
V_8 -> V_16 . V_95 . V_96 = 0x4f01 ;
V_8 -> V_16 . V_95 . V_97 = ( V_105 ) * V_50 ;
V_8 -> V_16 . V_40 = V_99 | V_116 ;
V_8 -> V_16 . V_17 = sizeof( struct V_49 ) ;
V_8 -> V_19 = V_52 -> V_90 + V_114 ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f ) {
F_10 ( V_27 L_21
L_22 ,
* V_50 , ( V_105 ) V_8 -> V_16 . V_95 . V_96 , V_25 ) ;
V_50 ++ ;
V_52 -> V_89 -- ;
continue;
}
V_115 = V_8 -> V_19 ;
V_115 -> V_117 = * V_50 ;
if ( ( V_115 -> V_118 & V_119 ) == V_119 &&
V_115 -> V_69 >= 8 )
V_114 ++ ;
else
V_52 -> V_89 -- ;
V_50 ++ ;
V_115 -> V_84 = V_115 -> V_74 + V_115 -> V_77 + V_115 -> V_80 ;
if ( V_115 -> V_84 == 0 || ( V_115 -> V_84 == 24 &&
V_115 -> V_69 == 32 ) )
V_115 -> V_84 = V_115 -> V_69 ;
}
if ( V_52 -> V_89 > 0 )
return 0 ;
else
return - V_106 ;
}
static int T_1 F_29 ( struct V_7 * V_8 ,
struct V_51 * V_52 )
{
int V_85 , V_25 ;
F_20 ( V_8 ) ;
V_8 -> V_16 . V_95 . V_96 = 0x4f0a ;
V_8 -> V_16 . V_95 . V_120 = 0x0 ;
V_25 = F_9 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x4f || V_8 -> V_16 . V_95 . V_121 < 0xc000 ) {
V_52 -> V_122 = V_52 -> V_63 = 0 ;
} else {
V_52 -> V_123 = ( T_2 * ) F_30 ( ( ( V_105 ) V_8 -> V_16 . V_95 . V_121 << 4 )
+ V_8 -> V_16 . V_95 . V_124 ) ;
V_52 -> V_125 = ( V_33 * ) V_52 -> V_123 + V_52 -> V_123 [ 1 ] ;
V_52 -> V_126 = ( V_33 * ) V_52 -> V_123 + V_52 -> V_123 [ 2 ] ;
F_10 ( V_109 L_23
L_24 ,
( T_2 ) V_8 -> V_16 . V_95 . V_121 , ( T_2 ) V_8 -> V_16 . V_95 . V_124 ) ;
F_10 ( V_109 L_25
L_26 , V_52 -> V_125 ,
V_52 -> V_126 ) ;
if ( V_52 -> V_123 [ 3 ] ) {
F_10 ( V_109 L_27 ) ;
for ( V_85 = V_52 -> V_123 [ 3 ] / 2 ;
V_52 -> V_123 [ V_85 ] != 0xffff ; V_85 ++ )
F_10 ( L_28 , V_52 -> V_123 [ V_85 ] ) ;
F_10 ( L_29 ) ;
if ( V_52 -> V_123 [ V_85 ] != 0xffff ) {
F_10 ( V_109 L_30
L_31 ) ;
V_52 -> V_63 = V_52 -> V_122 = 0 ;
}
}
}
return 0 ;
}
static int T_1 F_31 ( struct V_127 * V_50 ,
struct V_47 * V_48 )
{
if ( V_48 -> V_128 . V_129 ) {
F_32 ( & V_48 -> V_46 , V_50 ) ;
if ( F_33 ( & V_48 -> V_46 , V_48 ) )
return 0 ;
}
if ( F_23 ( V_48 -> V_52 , V_50 -> V_57 , V_50 -> V_59 , 8 ,
V_92 ) == - 1 )
return 0 ;
return 1 ;
}
static int T_1 F_34 ( struct V_7 * V_8 ,
struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_52 ;
int V_25 = 0 ;
if ( V_130 || V_52 -> V_103 . V_107 < 0x0300 )
return - V_106 ;
V_8 -> V_16 . V_95 . V_96 = 0x4f15 ;
V_8 -> V_16 . V_95 . V_120 = 0 ;
V_8 -> V_16 . V_95 . V_97 = 0 ;
V_8 -> V_16 . V_17 = 0 ;
V_8 -> V_16 . V_40 = 0 ;
V_25 = F_9 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f || V_25 )
return - V_106 ;
if ( ( V_8 -> V_16 . V_95 . V_120 & 0x3 ) == 3 ) {
F_10 ( V_109 L_32
L_33 ) ;
} else if ( ( V_8 -> V_16 . V_95 . V_120 & 0x3 ) == 2 ) {
F_10 ( V_109 L_34
L_35 ) ;
} else if ( ( V_8 -> V_16 . V_95 . V_120 & 0x3 ) == 1 ) {
F_10 ( V_109 L_36
L_35 ) ;
} else {
F_10 ( V_109 L_37
L_38 ) ;
return - V_106 ;
}
V_8 -> V_16 . V_95 . V_96 = 0x4f15 ;
V_8 -> V_16 . V_95 . V_120 = 1 ;
V_8 -> V_16 . V_95 . V_97 = V_8 -> V_16 . V_95 . V_98 = 0 ;
V_8 -> V_16 . V_40 = V_99 | V_116 ;
V_8 -> V_16 . V_17 = V_131 ;
V_8 -> V_19 = F_11 ( V_131 , V_29 ) ;
V_25 = F_9 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) == 0x004f && ! V_25 ) {
F_35 ( V_8 -> V_19 , & V_48 -> V_128 ) ;
if ( V_48 -> V_128 . V_132 && V_48 -> V_128 . V_133 ) {
if ( V_48 -> V_128 . V_134 == 0 )
V_48 -> V_128 . V_134 = 300 * 1000000 ;
V_48 -> V_128 . V_129 = 1 ;
}
} else {
V_25 = - V_106 ;
}
F_18 ( V_8 -> V_19 ) ;
return V_25 ;
}
static void T_1 F_36 ( struct V_7 * V_8 ,
struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_52 ;
int V_85 ;
memset ( & V_48 -> V_128 , 0 , sizeof( V_48 -> V_128 ) ) ;
if ( F_34 ( V_8 , V_48 ) ) {
V_48 -> V_128 . V_129 = 0 ;
V_52 -> V_135 = 1 ;
}
if ( V_136 )
V_48 -> V_128 . V_134 = V_136 * 1000000 ;
if ( V_137 )
V_48 -> V_128 . V_132 = V_137 ;
if ( V_138 )
V_48 -> V_128 . V_133 = V_138 * 1000 ;
if ( V_48 -> V_128 . V_129 == 0 && V_136 && V_137 && V_138 ) {
V_48 -> V_128 . V_139 = 0 ;
V_48 -> V_128 . V_140 = 60 ;
V_48 -> V_128 . V_141 = 29000 ;
V_48 -> V_128 . V_129 = 1 ;
V_52 -> V_135 = 0 ;
}
if ( V_48 -> V_128 . V_129 )
F_10 ( V_109
L_39
L_40 , V_48 -> V_128 . V_132 ,
( int ) ( V_48 -> V_128 . V_133 / 1000 ) ,
( int ) ( V_48 -> V_128 . V_134 / 1000000 ) ) ;
else
F_10 ( V_109 L_41
L_42 ) ;
for ( V_85 = 0 ; V_85 < V_52 -> V_89 ; V_85 ++ ) {
struct V_45 V_46 ;
struct V_49 * V_50 ;
struct V_127 V_53 ;
V_50 = & V_52 -> V_90 [ V_85 ] ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_46 . V_57 = V_50 -> V_58 ;
V_46 . V_59 = V_50 -> V_60 ;
F_37 ( V_142 | V_143 , 60 , & V_46 , V_48 ) ;
F_38 ( & V_53 , & V_46 ) ;
F_39 ( & V_53 , & V_48 -> V_144 ) ;
}
for ( V_85 = 0 ; V_85 < V_145 ; V_85 ++ ) {
if ( F_31 ( (struct V_127 * )
& V_146 [ V_85 ] , V_48 ) )
F_39 ( & V_146 [ V_85 ] , & V_48 -> V_144 ) ;
}
for ( V_85 = 0 ; V_85 < V_48 -> V_128 . V_147 ; V_85 ++ ) {
if ( F_31 ( & V_48 -> V_128 . V_148 [ V_85 ] , V_48 ) )
F_39 ( & V_48 -> V_128 . V_148 [ V_85 ] ,
& V_48 -> V_144 ) ;
}
return;
}
static void T_1 F_40 ( struct V_7 * V_8 ,
struct V_51 * V_52 )
{
int V_25 ;
F_20 ( V_8 ) ;
V_8 -> V_16 . V_95 . V_96 = 0x4f04 ;
V_8 -> V_16 . V_95 . V_97 = 0x000f ;
V_8 -> V_16 . V_95 . V_98 = 0x0000 ;
V_8 -> V_16 . V_40 = 0 ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f ) {
F_10 ( V_27 L_43
L_44 ,
V_8 -> V_16 . V_95 . V_96 , V_25 ) ;
V_52 -> V_94 = 0 ;
return;
}
V_52 -> V_94 = 64 * ( V_8 -> V_16 . V_95 . V_120 & 0xffff ) ;
}
static int T_1 F_41 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = NULL ;
struct V_51 * V_52 = V_48 -> V_52 ;
int V_25 ;
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_25 = F_27 ( V_8 , V_52 ) ;
if ( V_25 )
goto V_35;
V_25 = F_28 ( V_8 , V_52 ) ;
if ( V_25 )
goto V_35;
V_52 -> V_135 = V_135 ;
#ifdef F_42
V_52 -> V_122 = V_122 ;
V_52 -> V_63 = V_63 ;
if ( V_52 -> V_122 || V_52 -> V_63 )
F_29 ( V_8 , V_52 ) ;
#else
V_52 -> V_122 = V_52 -> V_63 = 0 ;
#endif
F_43 ( & V_48 -> V_144 ) ;
F_36 ( V_8 , V_48 ) ;
F_40 ( V_8 , V_52 ) ;
V_35: F_19 ( V_8 ) ;
return V_25 ;
}
static int T_1 F_44 ( struct V_47 * V_48 )
{
struct V_149 * V_150 ;
struct V_151 * V_144 ;
struct V_127 * V_50 ;
struct V_51 * V_52 = V_48 -> V_52 ;
int V_85 , V_152 ;
if ( V_153 ) {
for ( V_85 = 0 ; V_85 < V_52 -> V_89 ; V_85 ++ ) {
if ( V_52 -> V_90 [ V_85 ] . V_117 == V_153 ) {
V_152 = V_85 ;
F_22 ( & V_48 -> V_46 , V_48 ,
& V_52 -> V_90 [ V_152 ] ) ;
F_37 ( V_142 | V_143 , 60 ,
& V_48 -> V_46 , V_48 ) ;
V_48 -> V_46 . V_154 = 0 ;
goto V_155;
}
}
F_10 ( V_109 L_45
L_46 , V_153 ) ;
V_153 = 0 ;
}
V_85 = 0 ;
F_45 (pos, &info->modelist)
V_85 ++ ;
V_50 = F_11 ( V_85 * sizeof( * V_50 ) , V_29 ) ;
if ( V_50 ) {
V_85 = 0 ;
F_45 (pos, &info->modelist) {
V_144 = F_46 ( V_150 , struct V_151 , V_156 ) ;
V_50 [ V_85 ] = V_144 -> V_50 ;
V_85 ++ ;
}
if ( ! V_157 )
V_157 = V_158 ;
V_85 = F_47 ( & V_48 -> V_46 , V_48 , V_157 , V_50 , V_85 ,
NULL , 8 ) ;
F_18 ( V_50 ) ;
}
if ( V_85 == 0 ) {
V_48 -> V_46 . V_57 = 640 ;
V_48 -> V_46 . V_59 = 480 ;
V_50 = (struct V_127 * )
F_48 ( & V_48 -> V_46 , & V_48 -> V_144 ) ;
if ( V_50 ) {
F_32 ( & V_48 -> V_46 , V_50 ) ;
} else {
V_152 = V_52 -> V_90 [ 0 ] . V_117 ;
F_22 ( & V_48 -> V_46 , V_48 ,
& V_52 -> V_90 [ V_152 ] ) ;
F_37 ( V_142 | V_143 , 60 ,
& V_48 -> V_46 , V_48 ) ;
goto V_155;
}
}
V_152 = F_23 ( V_52 , V_48 -> V_46 . V_57 , V_48 -> V_46 . V_59 ,
V_48 -> V_46 . V_69 , V_92 ) ;
if ( V_152 == - 1 )
return - V_106 ;
F_22 ( & V_48 -> V_46 , V_48 , & V_52 -> V_90 [ V_152 ] ) ;
V_155:
if ( V_52 -> V_103 . V_107 < 0x0300 || V_52 -> V_135 )
F_37 ( V_142 | V_143 , 60 ,
& V_48 -> V_46 , V_48 ) ;
return V_152 ;
}
static int F_49 ( struct V_159 * V_160 , int V_161 ,
int V_162 , struct V_47 * V_48 )
{
struct V_7 * V_8 ;
#ifdef F_50
struct V_51 * V_52 = V_48 -> V_52 ;
int V_85 = V_52 -> V_163 ;
#endif
int V_25 = 0 ;
if ( V_162 + V_161 > 256 )
return - V_106 ;
#ifdef F_50
if ( V_85 >= 0 && V_85 < V_52 -> V_89 &&
V_52 -> V_90 [ V_85 ] . V_118 & V_164 ) {
for ( V_85 = 0 ; V_85 < V_161 ; V_85 ++ ) {
F_51 ( V_162 + V_85 , V_165 ) ;
F_51 ( V_160 [ V_85 ] . V_70 , V_166 ) ;
F_51 ( V_160 [ V_85 ] . V_75 , V_166 ) ;
F_51 ( V_160 [ V_85 ] . V_78 , V_166 ) ;
}
}
#ifdef F_42
else if ( V_52 -> V_122 ) {
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
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_16 . V_95 . V_96 = 0x4f09 ;
V_8 -> V_16 . V_95 . V_120 = 0x0 ;
V_8 -> V_16 . V_95 . V_97 = V_161 ;
V_8 -> V_16 . V_95 . V_98 = V_162 ;
V_8 -> V_16 . V_40 = V_116 ;
V_8 -> V_16 . V_17 = sizeof( struct V_159 ) * V_161 ;
V_8 -> V_19 = V_160 ;
V_25 = F_9 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f )
V_25 = 1 ;
F_19 ( V_8 ) ;
}
return V_25 ;
}
static int F_52 ( unsigned V_167 , unsigned V_70 , unsigned V_75 ,
unsigned V_78 , unsigned V_81 ,
struct V_47 * V_48 )
{
struct V_159 V_168 ;
int V_169 = 16 - V_170 ;
int V_25 = 0 ;
if ( V_167 >= V_48 -> V_171 . V_18 )
return - V_106 ;
if ( V_48 -> V_46 . V_69 == 8 ) {
V_168 . V_70 = V_70 >> V_169 ;
V_168 . V_75 = V_75 >> V_169 ;
V_168 . V_78 = V_78 >> V_169 ;
V_168 . V_172 = 0 ;
V_25 = F_49 ( & V_168 , 1 , V_167 , V_48 ) ;
} else if ( V_167 < 16 ) {
switch ( V_48 -> V_46 . V_69 ) {
case 16 :
if ( V_48 -> V_46 . V_70 . V_71 == 10 ) {
( ( V_105 * ) ( V_48 -> V_173 ) ) [ V_167 ] =
( ( V_70 & 0xf800 ) >> 1 ) |
( ( V_75 & 0xf800 ) >> 6 ) |
( ( V_78 & 0xf800 ) >> 11 ) ;
} else {
( ( V_105 * ) ( V_48 -> V_173 ) ) [ V_167 ] =
( ( V_70 & 0xf800 ) ) |
( ( V_75 & 0xfc00 ) >> 5 ) |
( ( V_78 & 0xf800 ) >> 11 ) ;
}
break;
case 24 :
case 32 :
V_70 >>= 8 ;
V_75 >>= 8 ;
V_78 >>= 8 ;
( ( V_105 * ) ( V_48 -> V_173 ) ) [ V_167 ] =
( V_70 << V_48 -> V_46 . V_70 . V_71 ) |
( V_75 << V_48 -> V_46 . V_75 . V_71 ) |
( V_78 << V_48 -> V_46 . V_78 . V_71 ) ;
break;
}
}
return V_25 ;
}
static int F_53 ( struct V_174 * V_171 , struct V_47 * V_48 )
{
struct V_159 * V_160 ;
int V_169 = 16 - V_170 ;
int V_85 , V_25 = 0 ;
if ( V_48 -> V_46 . V_69 == 8 ) {
if ( V_171 -> V_162 + V_171 -> V_18 > V_48 -> V_171 . V_162 +
V_48 -> V_171 . V_18 || V_171 -> V_162 < V_48 -> V_171 . V_162 )
return - V_106 ;
V_160 = F_25 ( sizeof( * V_160 ) * V_171 -> V_18 , V_29 ) ;
if ( ! V_160 )
return - V_30 ;
for ( V_85 = 0 ; V_85 < V_171 -> V_18 ; V_85 ++ ) {
V_160 [ V_85 ] . V_70 = V_171 -> V_70 [ V_85 ] >> V_169 ;
V_160 [ V_85 ] . V_75 = V_171 -> V_75 [ V_85 ] >> V_169 ;
V_160 [ V_85 ] . V_78 = V_171 -> V_78 [ V_85 ] >> V_169 ;
V_160 [ V_85 ] . V_172 = 0 ;
}
V_25 = F_49 ( V_160 , V_171 -> V_18 , V_171 -> V_162 , V_48 ) ;
F_18 ( V_160 ) ;
} else {
for ( V_85 = 0 ; V_85 < V_171 -> V_18 ; V_85 ++ ) {
V_25 |= F_52 ( V_171 -> V_162 + V_85 , V_171 -> V_70 [ V_85 ] ,
V_171 -> V_75 [ V_85 ] , V_171 -> V_78 [ V_85 ] ,
0 , V_48 ) ;
}
}
return V_25 ;
}
static int F_54 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
#ifdef F_42
int V_71 ;
struct V_51 * V_52 = V_48 -> V_52 ;
V_71 = ( V_46 -> V_68 * V_48 -> V_64 . V_175 + V_46 -> V_67 ) / 4 ;
if ( V_52 -> V_125 ) {
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
static int F_55 ( int V_176 , struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_25 = 1 ;
#ifdef F_50
struct V_51 * V_52 = V_48 -> V_52 ;
if ( V_52 -> V_103 . V_177 & V_178 ) {
int V_179 = 10000 ;
V_33 V_10 = 0 , V_180 = 0 ;
if ( V_176 == V_181 ) {
V_10 = 0x20 ;
V_180 = 0x00 ;
V_25 = 0 ;
} else {
V_10 = 0x00 ;
V_180 = 0x80 ;
V_25 = ( V_176 == V_182 ) ? 0 : - V_106 ;
}
F_56 ( NULL , 0x00 , 0x01 ) ;
V_10 |= F_57 ( NULL , 0x01 ) & ~ 0x20 ;
F_56 ( NULL , 0x00 , V_10 ) ;
V_180 |= F_58 ( NULL , 0x17 ) & ~ 0x80 ;
while ( V_179 -- ) ;
F_59 ( NULL , 0x17 , V_180 ) ;
F_56 ( NULL , 0x00 , 0x03 ) ;
} else
#endif
{
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_16 . V_95 . V_96 = 0x4f10 ;
switch ( V_176 ) {
case V_182 :
V_8 -> V_16 . V_95 . V_120 = 0x0001 ;
break;
case V_183 :
V_8 -> V_16 . V_95 . V_120 = 0x0101 ;
break;
case V_181 :
V_8 -> V_16 . V_95 . V_120 = 0x0401 ;
break;
default:
goto V_35;
}
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f )
V_25 = 1 ;
V_35: F_19 ( V_8 ) ;
}
return V_25 ;
}
static int F_60 ( struct V_47 * V_48 , int V_184 )
{
struct V_51 * V_52 = V_48 -> V_52 ;
int V_185 = F_61 ( & V_52 -> V_186 ) ;
if ( ! V_185 && V_52 -> V_94 )
V_52 -> V_187 = F_24 ( V_52 ) ;
F_62 ( & V_52 -> V_186 ) ;
return 0 ;
}
static int F_63 ( struct V_47 * V_48 , int V_184 )
{
struct V_7 * V_8 = NULL ;
struct V_51 * V_52 = V_48 -> V_52 ;
int V_185 = F_61 ( & V_52 -> V_186 ) ;
if ( ! V_185 )
return - V_106 ;
if ( V_185 != 1 )
goto V_35;
V_8 = F_21 () ;
if ( ! V_8 )
goto V_35;
V_8 -> V_16 . V_95 . V_96 = 0x0003 ;
F_9 ( V_8 ) ;
F_26 ( V_52 , V_52 -> V_187 ) ;
V_35:
F_64 ( & V_52 -> V_186 ) ;
if ( V_8 )
F_19 ( V_8 ) ;
return 0 ;
}
static int F_65 ( struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_52 ;
struct V_7 * V_8 = NULL ;
struct V_188 * V_189 = NULL ;
struct V_49 * V_50 = NULL ;
int V_85 , V_25 = 0 , V_84 = V_48 -> V_46 . V_69 ;
if ( V_84 > 8 && V_84 != 32 )
V_84 = V_48 -> V_46 . V_70 . V_73 + V_48 -> V_46 . V_75 . V_73 +
V_48 -> V_46 . V_78 . V_73 ;
V_85 = F_23 ( V_52 , V_48 -> V_46 . V_57 , V_48 -> V_46 . V_59 , V_84 ,
V_92 | V_91 ) ;
if ( V_85 >= 0 )
V_50 = & V_52 -> V_90 [ V_85 ] ;
else
return - V_106 ;
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_190:
V_8 -> V_16 . V_95 . V_96 = 0x4f02 ;
V_8 -> V_16 . V_95 . V_120 = V_50 -> V_117 | 0x4000 ;
if ( V_52 -> V_103 . V_107 >= 0x0300 && ! V_52 -> V_135 &&
V_48 -> V_46 . V_154 != 0 ) {
V_8 -> V_16 . V_95 . V_120 |= 0x0800 ;
V_8 -> V_16 . V_40 = V_116 ;
V_189 = F_11 ( sizeof( struct V_188 ) , V_29 ) ;
if ( ! V_189 ) {
V_25 = - V_30 ;
goto V_35;
}
V_189 -> V_191 = V_48 -> V_46 . V_57 + V_48 -> V_46 . V_192 ;
V_189 -> V_193 = V_189 -> V_191 + V_48 -> V_46 . V_194 ;
V_189 -> V_195 = V_189 -> V_193 + V_48 -> V_46 . V_196 ;
V_189 -> V_197 = V_48 -> V_46 . V_59 + V_48 -> V_46 . V_198 ;
V_189 -> V_199 = V_189 -> V_197 + V_48 -> V_46 . V_200 ;
V_189 -> V_201 = V_189 -> V_199 + V_48 -> V_46 . V_202 ;
V_189 -> V_203 = F_66 ( V_48 -> V_46 . V_154 ) * 1000 ;
V_189 -> V_204 = ( T_2 ) ( 100 * ( V_189 -> V_203 /
( V_189 -> V_201 * V_189 -> V_195 ) ) ) ;
if ( V_48 -> V_46 . V_53 & V_205 )
V_189 -> V_40 |= 0x1 ;
if ( V_48 -> V_46 . V_53 & V_206 )
V_189 -> V_40 |= 0x2 ;
if ( ! ( V_48 -> V_46 . V_55 & V_207 ) )
V_189 -> V_40 |= 0x4 ;
if ( ! ( V_48 -> V_46 . V_55 & V_56 ) )
V_189 -> V_40 |= 0x8 ;
memcpy ( & V_52 -> V_189 , V_189 , sizeof( * V_189 ) ) ;
} else {
memset ( & V_52 -> V_189 , 0 , sizeof( * V_189 ) ) ;
}
V_8 -> V_16 . V_17 = sizeof( struct V_188 ) ;
V_8 -> V_19 = & V_52 -> V_189 ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f ) {
if ( V_189 != NULL ) {
F_10 ( V_27 L_47
L_48
L_49 , V_8 -> V_16 . V_95 . V_96 , V_25 ) ;
F_20 ( V_8 ) ;
F_18 ( V_189 ) ;
V_189 = NULL ;
V_48 -> V_46 . V_154 = 0 ;
goto V_190;
} else {
F_10 ( V_37 L_50
L_51 , V_8 -> V_16 . V_95 . V_96 , V_25 ) ;
V_25 = - V_106 ;
goto V_35;
}
}
V_52 -> V_163 = V_85 ;
if ( V_52 -> V_103 . V_177 & V_208 &&
V_50 -> V_69 <= 8 ) {
F_20 ( V_8 ) ;
V_8 -> V_16 . V_95 . V_96 = 0x4f08 ;
V_8 -> V_16 . V_95 . V_120 = 0x0800 ;
V_25 = F_9 ( V_8 ) ;
if ( V_25 || ( V_8 -> V_16 . V_95 . V_96 & 0xffff ) != 0x004f ||
( ( V_8 -> V_16 . V_95 . V_120 & 0xff00 ) >> 8 ) != 8 ) {
V_170 = 6 ;
} else {
V_170 = 8 ;
}
}
V_48 -> V_64 . V_209 = ( V_48 -> V_46 . V_69 == 8 ) ?
V_210 : V_211 ;
V_48 -> V_64 . V_175 = V_50 -> V_66 ;
V_35: if ( V_189 != NULL )
F_18 ( V_189 ) ;
F_19 ( V_8 ) ;
return V_25 ;
}
static void F_67 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
const struct V_127 * V_50 ;
struct V_51 * V_52 = V_48 -> V_52 ;
if ( ! V_46 -> V_154 )
return;
if ( V_52 -> V_103 . V_107 < 0x0300 ) {
F_37 ( V_142 | V_143 , 60 , V_46 , V_48 ) ;
return;
}
if ( ! F_33 ( V_46 , V_48 ) )
return;
V_50 = F_48 ( V_46 , & V_48 -> V_144 ) ;
if ( V_50 ) {
if ( V_50 -> V_57 == V_46 -> V_57 && V_50 -> V_59 == V_46 -> V_59 &&
! ( V_50 -> V_53 & ( V_206 | V_205 ) ) ) {
F_32 ( V_46 , V_50 ) ;
return;
}
}
if ( V_48 -> V_128 . V_129 && ! F_37 ( V_212 , 0 , V_46 , V_48 ) )
return;
V_46 -> V_154 = 0 ;
}
static int F_68 ( struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_52 ;
struct V_49 * V_50 = NULL ;
int V_86 = - 1 ;
int V_84 = V_46 -> V_70 . V_73 + V_46 -> V_75 . V_73 + V_46 -> V_78 . V_73 ;
if ( V_84 == 0 || abs ( V_84 - V_46 -> V_69 ) >= 8 )
V_84 = V_46 -> V_69 ;
V_86 = F_23 ( V_52 , V_46 -> V_57 , V_46 -> V_59 , V_84 ,
V_92 ) ;
if ( V_86 == - 1 )
return - V_106 ;
V_50 = & V_52 -> V_90 [ V_86 ] ;
F_22 ( V_46 , V_48 , V_50 ) ;
if ( V_46 -> V_59 * V_50 -> V_66 > V_48 -> V_64 . V_65
&& V_48 -> V_64 . V_65 )
return - V_106 ;
if ( ( V_46 -> V_53 & V_205 ) &&
! ( V_52 -> V_90 [ V_86 ] . V_118 & 0x100 ) )
V_46 -> V_53 &= ~ V_205 ;
if ( ( V_46 -> V_53 & V_206 ) &&
! ( V_52 -> V_90 [ V_86 ] . V_118 & 0x200 ) )
V_46 -> V_53 &= ~ V_206 ;
F_67 ( V_46 , V_48 ) ;
V_46 -> V_61 = V_46 -> V_57 ;
V_46 -> V_62 = ( V_52 -> V_63 ) ?
V_48 -> V_64 . V_65 / V_50 -> V_66 :
V_46 -> V_59 ;
return 0 ;
}
static void T_1 F_69 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
unsigned int V_213 ;
unsigned int V_214 ;
unsigned int V_215 ;
struct V_51 * V_52 = V_48 -> V_52 ;
int V_85 , V_87 ;
V_48 -> V_173 = ( ( V_33 * ) V_48 -> V_52 + sizeof( struct V_51 ) ) ;
V_48 -> V_64 = V_216 ;
V_48 -> V_64 . V_217 = V_52 -> V_63 ? 1 : 0 ;
V_48 -> V_64 . V_218 = ( V_52 -> V_63 > 1 ) ? 1 : 0 ;
if ( ! V_176 )
V_48 -> V_219 -> V_220 = NULL ;
V_214 = 0 ;
for ( V_85 = 0 ; V_85 < V_52 -> V_89 ; V_85 ++ ) {
V_87 = V_52 -> V_90 [ V_85 ] . V_66 *
V_52 -> V_90 [ V_85 ] . V_60 ;
if ( V_87 > V_214 )
V_214 = V_87 ;
}
V_214 *= 2 ;
if ( V_50 != NULL ) {
V_213 = V_48 -> V_46 . V_59 * V_50 -> V_66 ;
} else {
V_213 = V_48 -> V_46 . V_59 * V_48 -> V_46 . V_57 *
( ( V_48 -> V_46 . V_69 + 7 ) >> 3 ) ;
}
V_215 = V_52 -> V_103 . V_221 * 65536 ;
if ( V_222 )
V_215 = V_222 * 1024 * 1024 ;
if ( V_215 < V_213 )
V_215 = V_213 ;
if ( V_223 )
V_214 = V_223 * 1024 * 1024 ;
if ( V_214 < V_213 )
V_214 = V_213 ;
if ( V_214 > V_215 )
V_214 = V_215 ;
V_48 -> V_64 . V_65 = V_214 ;
V_48 -> V_64 . V_224 = V_50 -> V_225 ;
V_48 -> V_46 . V_62 = V_48 -> V_64 . V_65 /
V_50 -> V_66 ;
if ( V_52 -> V_63 && V_48 -> V_46 . V_62 > V_48 -> V_46 . V_59 ) {
F_10 ( V_109 L_52
L_53
L_54 ,
( V_52 -> V_63 > 1 ) ? L_55 : L_56 ,
V_48 -> V_46 . V_62 ) ;
} else {
F_10 ( V_109 L_57 ) ;
V_48 -> V_46 . V_62 = V_48 -> V_46 . V_59 ;
V_52 -> V_63 = 0 ;
}
V_48 -> V_40 = V_226 |
( V_52 -> V_63 ? V_227 : 0 ) ;
if ( ! V_52 -> V_63 )
V_48 -> V_219 -> V_228 = NULL ;
}
static void T_1 F_70 ( struct V_47 * V_48 )
{
#ifdef F_71
if ( V_229 && ! ( V_48 -> V_64 . V_224 & ( V_230 - 1 ) ) ) {
int V_231 = V_48 -> V_64 . V_65 ;
unsigned int type = 0 ;
switch ( V_229 ) {
case 1 :
type = V_232 ;
break;
case 2 :
type = V_233 ;
break;
case 3 :
type = V_234 ;
break;
case 4 :
type = V_235 ;
break;
default:
type = 0 ;
break;
}
if ( type ) {
int V_236 ;
V_231 = F_72 ( V_231 ) ;
do {
V_236 = F_73 ( V_48 -> V_64 . V_224 ,
V_231 , type , 1 ) ;
V_231 >>= 1 ;
} while ( V_231 >= V_230 && V_236 == - V_106 );
}
}
#endif
}
static void T_1 F_74 ( struct V_47 * V_48 )
{
#ifdef F_50
switch ( V_229 ) {
case 1 :
V_48 -> V_237 = F_75 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
break;
case 2 :
V_48 -> V_237 = F_76 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
break;
case 3 :
V_48 -> V_237 = F_77 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
break;
case 4 :
default:
V_48 -> V_237 = F_78 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
break;
}
#else
V_48 -> V_237 = F_78 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
#endif
}
static T_3 F_79 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
return snprintf ( V_19 , V_230 , L_58 , V_52 -> V_103 . V_107 ) ;
}
static T_3 F_82 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
int V_242 = 0 , V_85 ;
for ( V_85 = 0 ; V_85 < V_52 -> V_89 && V_242 < V_230 ; V_85 ++ ) {
V_242 += snprintf ( V_19 + V_242 , V_230 - V_242 ,
L_59 ,
V_52 -> V_90 [ V_85 ] . V_58 , V_52 -> V_90 [ V_85 ] . V_60 ,
V_52 -> V_90 [ V_85 ] . V_84 , V_52 -> V_90 [ V_85 ] . V_117 ) ;
}
return V_242 ;
}
static T_3 F_83 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
if ( V_52 -> V_103 . V_110 )
return snprintf ( V_19 , V_230 , L_60 , ( char * )
( & V_52 -> V_103 ) + V_52 -> V_103 . V_110 ) ;
else
return 0 ;
}
static T_3 F_84 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
if ( V_52 -> V_103 . V_111 )
return snprintf ( V_19 , V_230 , L_60 , ( char * )
( & V_52 -> V_103 ) + V_52 -> V_103 . V_111 ) ;
else
return 0 ;
}
static T_3 F_85 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
if ( V_52 -> V_103 . V_112 )
return snprintf ( V_19 , V_230 , L_60 , ( char * )
( & V_52 -> V_103 ) + V_52 -> V_103 . V_112 ) ;
else
return 0 ;
}
static T_3 F_86 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
if ( V_52 -> V_103 . V_113 )
return snprintf ( V_19 , V_230 , L_60 ,
( char * ) ( & V_52 -> V_103 ) + V_52 -> V_103 . V_113 ) ;
else
return 0 ;
}
static T_3 F_87 ( struct V_238 * V_239 ,
struct V_240 * V_241 , char * V_19 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
return snprintf ( V_19 , V_230 , L_61 , V_52 -> V_135 ) ;
}
static T_3 F_88 ( struct V_238 * V_239 ,
struct V_240 * V_241 , const char * V_19 , T_4 V_161 )
{
struct V_47 * V_48 = F_80 ( F_81 ( V_239 ) ) ;
struct V_51 * V_52 = V_48 -> V_52 ;
if ( V_161 > 0 ) {
if ( V_19 [ 0 ] == '0' )
V_52 -> V_135 = 0 ;
else
V_52 -> V_135 = 1 ;
}
return V_161 ;
}
static int T_1 F_89 ( struct V_243 * V_239 )
{
struct V_47 * V_48 ;
struct V_49 * V_50 = NULL ;
struct V_51 * V_52 ;
int V_25 = 0 , V_85 ;
V_48 = F_90 ( sizeof( * V_52 ) + sizeof( V_105 ) * 256 , & V_239 -> V_239 ) ;
if ( ! V_48 )
return - V_30 ;
V_52 = V_48 -> V_52 ;
V_25 = F_41 ( V_48 ) ;
if ( V_25 ) {
F_10 ( V_37 L_62 , V_25 ) ;
goto V_35;
}
V_48 -> V_219 = & V_244 ;
V_85 = F_44 ( V_48 ) ;
if ( V_85 < 0 ) {
V_25 = - V_106 ;
goto V_35;
} else {
V_50 = & V_52 -> V_90 [ V_85 ] ;
}
if ( F_91 ( & V_48 -> V_171 , 256 , 0 ) < 0 ) {
V_25 = - V_245 ;
goto V_35;
}
F_69 ( V_48 , V_50 ) ;
if ( ! F_92 ( 0x3c0 , 32 , L_63 ) ) {
F_10 ( V_37 L_64 ) ;
V_25 = - V_246 ;
goto V_247;
}
if ( ! F_93 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ,
L_63 ) ) {
F_10 ( V_37 L_65
L_66 , V_48 -> V_64 . V_224 ) ;
V_25 = - V_246 ;
goto V_248;
}
F_70 ( V_48 ) ;
F_74 ( V_48 ) ;
if ( ! V_48 -> V_237 ) {
F_10 ( V_37
L_67
L_68 ,
V_48 -> V_64 . V_65 , V_48 -> V_64 . V_224 ) ;
V_25 = - V_246 ;
goto V_249;
}
F_94 ( V_239 , V_48 ) ;
if ( F_95 ( V_48 ) < 0 ) {
F_10 ( V_37
L_69 ) ;
V_25 = - V_106 ;
goto V_250;
}
F_10 ( V_109 L_70
L_71 , V_48 -> V_64 . V_224 ,
V_48 -> V_237 , V_48 -> V_64 . V_65 / 1024 ,
V_52 -> V_103 . V_221 * 64 ) ;
F_10 ( V_109 L_72 , V_48 -> V_251 ,
V_48 -> V_64 . V_31 ) ;
V_25 = F_96 ( & V_239 -> V_239 . V_252 , & V_253 ) ;
if ( V_25 != 0 )
F_10 ( V_27 L_73 ,
V_48 -> V_251 ) ;
return 0 ;
V_250:
F_97 ( V_48 -> V_237 ) ;
V_249:
F_98 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
V_248:
F_99 ( 0x3c0 , 32 ) ;
V_247:
if ( ! F_100 ( & V_48 -> V_144 ) )
F_101 ( & V_48 -> V_144 ) ;
F_102 ( V_48 -> V_128 . V_148 ) ;
F_103 ( & V_48 -> V_171 ) ;
V_35:
if ( V_52 -> V_90 )
F_18 ( V_52 -> V_90 ) ;
F_104 ( V_48 ) ;
return V_25 ;
}
static int F_105 ( struct V_243 * V_239 )
{
struct V_47 * V_48 = F_80 ( V_239 ) ;
if ( V_48 ) {
struct V_51 * V_52 = V_48 -> V_52 ;
F_106 ( & V_239 -> V_239 . V_252 , & V_253 ) ;
F_107 ( V_48 ) ;
F_99 ( 0x3c0 , 32 ) ;
F_97 ( V_48 -> V_237 ) ;
F_98 ( V_48 -> V_64 . V_224 , V_48 -> V_64 . V_65 ) ;
F_102 ( V_48 -> V_128 . V_148 ) ;
F_103 ( & V_48 -> V_171 ) ;
if ( V_52 ) {
if ( V_52 -> V_90 )
F_18 ( V_52 -> V_90 ) ;
if ( V_52 -> V_187 )
F_18 ( V_52 -> V_187 ) ;
if ( V_52 -> V_254 )
F_18 ( V_52 -> V_254 ) ;
}
F_104 ( V_48 ) ;
}
return 0 ;
}
static int T_1 F_108 ( char * V_255 )
{
char * V_256 ;
if ( ! V_255 || ! * V_255 )
return 0 ;
while ( ( V_256 = F_109 ( & V_255 , L_74 ) ) != NULL ) {
if ( ! * V_256 ) continue;
if ( ! strcmp ( V_256 , L_75 ) )
V_63 = 0 ;
else if ( ! strcmp ( V_256 , L_56 ) )
V_63 = 1 ;
else if ( ! strcmp ( V_256 , L_55 ) )
V_63 = 2 ;
else if ( ! strcmp ( V_256 , L_76 ) )
V_122 = 0 ;
else if ( ! strcmp ( V_256 , L_77 ) )
V_122 = 1 ;
else if ( ! strncmp ( V_256 , L_78 , 5 ) )
V_229 = F_110 ( V_256 + 5 , NULL , 0 ) ;
else if ( ! strcmp ( V_256 , L_79 ) )
V_229 = 0 ;
else if ( ! strcmp ( V_256 , L_80 ) )
V_135 = 1 ;
else if ( ! strcmp ( V_256 , L_81 ) )
V_130 = 1 ;
else if ( ! strcmp ( V_256 , L_82 ) )
V_176 = 0 ;
else if ( ! strncmp ( V_256 , L_83 , 7 ) )
V_222 = F_110 ( V_256 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_84 , 7 ) )
V_223 = F_110 ( V_256 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_85 , 6 ) )
V_138 = F_110 ( V_256 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_86 , 6 ) )
V_137 = F_110 ( V_256 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_87 , 7 ) )
V_136 = F_110 ( V_256 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_256 , L_88 , 8 ) )
V_153 = F_110 ( V_256 + 8 , NULL , 0 ) ;
else if ( V_256 [ 0 ] >= '0' && V_256 [ 0 ] <= '9' ) {
V_157 = V_256 ;
} else {
F_10 ( V_27
L_89 , V_256 ) ;
}
}
return 0 ;
}
static T_3 F_111 ( struct V_257 * V_239 , char * V_19 )
{
return snprintf ( V_19 , V_230 , L_60 , V_23 ) ;
}
static T_3 F_112 ( struct V_257 * V_239 , const char * V_19 ,
T_4 V_161 )
{
strncpy ( V_23 , V_19 , V_258 ) ;
return V_161 ;
}
static int T_1 F_113 ( void )
{
int V_25 ;
#ifndef F_114
char * V_259 = NULL ;
if ( F_115 ( L_63 , & V_259 ) )
return - V_260 ;
F_108 ( V_259 ) ;
#endif
V_25 = F_116 ( & V_32 , L_63 , F_1 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_117 ( & V_261 ) ;
if ( ! V_25 ) {
V_262 = F_118 ( L_63 , 0 ) ;
if ( V_262 )
V_25 = F_119 ( V_262 ) ;
else
V_25 = - V_30 ;
if ( V_25 ) {
F_120 ( V_262 ) ;
F_121 ( & V_261 ) ;
F_122 ( & V_32 ) ;
return V_25 ;
}
V_25 = F_123 ( & V_261 . V_263 ,
& V_264 ) ;
if ( V_25 ) {
F_10 ( V_27 L_90
L_91 ) ;
V_25 = 0 ;
}
}
return V_25 ;
}
static void T_5 F_124 ( void )
{
struct V_7 * V_8 ;
if ( V_38 ) {
V_8 = F_21 () ;
if ( V_8 ) {
V_8 -> V_16 . V_40 = V_41 ;
F_9 ( V_8 ) ;
F_19 ( V_8 ) ;
}
}
F_122 ( & V_32 ) ;
F_125 ( & V_261 . V_263 , & V_264 ) ;
F_126 ( V_262 ) ;
F_121 ( & V_261 ) ;
}
static int F_127 ( const char * V_265 , const struct V_266 * V_267 )
{
V_63 = 0 ;
if ( ! strcmp ( V_265 , L_75 ) )
V_63 = 0 ;
else if ( ! strcmp ( V_265 , L_56 ) )
V_63 = 1 ;
else if ( ! strcmp ( V_265 , L_55 ) )
V_63 = 2 ;
else
return - V_106 ;
return 0 ;
}
