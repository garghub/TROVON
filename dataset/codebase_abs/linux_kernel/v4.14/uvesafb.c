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
F_9 ( L_3 ,
( int ) ( sizeof( * V_25 ) + V_18 ) ) ;
return - V_28 ;
}
V_25 = F_10 ( sizeof( * V_25 ) + V_18 , V_29 ) ;
if ( ! V_25 )
return - V_30 ;
F_11 ( V_8 -> V_20 ) ;
memcpy ( & V_25 -> V_31 , & V_32 , sizeof( V_25 -> V_31 ) ) ;
V_25 -> V_10 = V_10 ;
V_25 -> V_18 = V_18 ;
V_25 -> V_14 = F_12 () ;
memcpy ( V_25 + 1 , & V_8 -> V_16 , sizeof( V_8 -> V_16 ) ) ;
memcpy ( ( V_33 * ) ( V_25 + 1 ) + sizeof( V_8 -> V_16 ) , V_8 -> V_19 , V_8 -> V_16 . V_17 ) ;
V_8 -> V_14 = V_25 -> V_14 ;
F_3 ( & V_12 ) ;
if ( V_13 [ V_10 ] ) {
F_4 ( & V_12 ) ;
V_26 = - V_34 ;
goto V_35;
}
V_13 [ V_10 ] = V_8 ;
F_4 ( & V_12 ) ;
V_26 = F_13 ( V_25 , 0 , 0 , V_29 ) ;
if ( V_26 == - V_36 ) {
V_26 = F_6 () ;
if ( V_26 ) {
F_14 ( L_4 , V_23 ) ;
F_14 ( L_5 ) ;
} else {
V_37 = 1 ;
V_26 = F_13 ( V_25 , 0 , 0 , F_15 () ) ;
if ( V_26 == - V_38 )
V_26 = 0 ;
}
} else if ( V_26 == - V_38 )
V_26 = 0 ;
if ( ! V_26 && ! ( V_8 -> V_16 . V_39 & V_40 ) )
V_26 = ! F_16 ( V_8 -> V_20 ,
F_17 ( V_41 ) ) ;
F_3 ( & V_12 ) ;
V_13 [ V_10 ] = NULL ;
F_4 ( & V_12 ) ;
V_10 ++ ;
if ( V_10 >= V_11 )
V_10 = 0 ;
V_35:
F_18 ( V_25 ) ;
return V_26 ;
}
static void F_19 ( struct V_7 * V_8 )
{
if ( V_8 ) {
F_18 ( V_8 -> V_20 ) ;
F_18 ( V_8 ) ;
}
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_42 * V_43 = V_8 -> V_20 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_20 = V_43 ;
}
static struct V_7 * F_21 ( void )
{
struct V_7 * V_8 ;
V_8 = F_10 ( sizeof( * V_8 ) , V_29 ) ;
if ( V_8 ) {
V_8 -> V_20 = F_10 ( sizeof( * V_8 -> V_20 ) , V_29 ) ;
if ( ! V_8 -> V_20 ) {
F_18 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_8 ;
}
static void F_22 ( struct V_44 * V_45 ,
struct V_46 * V_47 , struct V_48 * V_49 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
V_45 -> V_52 = V_53 ;
V_45 -> V_54 = V_55 ;
V_45 -> V_56 = V_49 -> V_57 ;
V_45 -> V_58 = V_49 -> V_59 ;
V_45 -> V_60 = V_49 -> V_57 ;
V_45 -> V_61 = ( V_51 -> V_62 ) ?
V_47 -> V_63 . V_64 / V_49 -> V_65 :
V_49 -> V_59 ;
V_45 -> V_66 = 0 ;
V_45 -> V_67 = 0 ;
V_45 -> V_68 = V_49 -> V_68 ;
if ( V_45 -> V_68 == 15 )
V_45 -> V_68 = 16 ;
if ( V_45 -> V_68 > 8 ) {
V_45 -> V_69 . V_70 = V_49 -> V_71 ;
V_45 -> V_69 . V_72 = V_49 -> V_73 ;
V_45 -> V_74 . V_70 = V_49 -> V_75 ;
V_45 -> V_74 . V_72 = V_49 -> V_76 ;
V_45 -> V_77 . V_70 = V_49 -> V_78 ;
V_45 -> V_77 . V_72 = V_49 -> V_79 ;
V_45 -> V_80 . V_70 = V_49 -> V_81 ;
V_45 -> V_80 . V_72 = V_49 -> V_82 ;
} else {
V_45 -> V_69 . V_70 = 0 ;
V_45 -> V_74 . V_70 = 0 ;
V_45 -> V_77 . V_70 = 0 ;
V_45 -> V_80 . V_70 = 0 ;
V_45 -> V_69 . V_72 = 8 ;
V_45 -> V_74 . V_72 = 8 ;
V_45 -> V_77 . V_72 = 8 ;
V_45 -> V_80 . V_72 = 0 ;
}
}
static int F_23 ( struct V_50 * V_51 ,
int V_56 , int V_58 , int V_83 , unsigned char V_39 )
{
int V_84 , V_85 = - 1 , V_86 = 0 , V_87 = 0x7fffffff ;
for ( V_84 = 0 ; V_84 < V_51 -> V_88 ; V_84 ++ ) {
V_86 = abs ( V_51 -> V_89 [ V_84 ] . V_57 - V_56 ) +
abs ( V_51 -> V_89 [ V_84 ] . V_59 - V_58 ) +
abs ( V_83 - V_51 -> V_89 [ V_84 ] . V_83 ) ;
if ( V_86 == 0 )
return V_84 ;
if ( V_86 < V_87 || ( V_86 == V_87 && V_51 -> V_89 [ V_84 ] . V_83 > V_83 ) ) {
V_87 = V_86 ;
V_85 = V_84 ;
}
}
V_84 = 1 ;
if ( V_39 & V_90 &&
V_51 -> V_89 [ V_85 ] . V_83 != V_83 )
V_84 = 0 ;
if ( V_39 & V_91 && V_87 > 24 )
V_84 = 0 ;
if ( V_84 != 0 )
return V_85 ;
else
return - 1 ;
}
static V_33 * F_24 ( struct V_50 * V_51 )
{
struct V_7 * V_8 ;
V_33 * V_92 ;
int V_26 ;
if ( ! V_51 -> V_93 )
return NULL ;
V_92 = F_25 ( V_51 -> V_93 , V_29 ) ;
if ( ! V_92 )
return F_26 ( - V_30 ) ;
V_8 = F_21 () ;
if ( ! V_8 ) {
F_18 ( V_92 ) ;
return NULL ;
}
V_8 -> V_16 . V_94 . V_95 = 0x4f04 ;
V_8 -> V_16 . V_94 . V_96 = 0x000f ;
V_8 -> V_16 . V_94 . V_97 = 0x0001 ;
V_8 -> V_16 . V_39 = V_98 | V_99 ;
V_8 -> V_16 . V_17 = V_51 -> V_93 ;
V_8 -> V_19 = V_92 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f ) {
F_9 ( L_6 ,
V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
F_18 ( V_92 ) ;
V_92 = NULL ;
}
F_19 ( V_8 ) ;
return V_92 ;
}
static void F_27 ( struct V_50 * V_51 , V_33 * V_100 )
{
struct V_7 * V_8 ;
int V_26 ;
if ( ! V_100 )
return;
V_8 = F_21 () ;
if ( ! V_8 )
return;
V_8 -> V_16 . V_94 . V_95 = 0x4f04 ;
V_8 -> V_16 . V_94 . V_96 = 0x000f ;
V_8 -> V_16 . V_94 . V_97 = 0x0002 ;
V_8 -> V_16 . V_17 = V_51 -> V_93 ;
V_8 -> V_16 . V_39 = V_99 ;
V_8 -> V_19 = V_100 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f )
F_9 ( L_7 ,
V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
F_19 ( V_8 ) ;
}
static int F_28 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_26 ;
V_8 -> V_16 . V_94 . V_95 = 0x4f00 ;
V_8 -> V_16 . V_39 = V_101 ;
V_8 -> V_16 . V_17 = sizeof( struct V_102 ) ;
V_8 -> V_19 = & V_51 -> V_102 ;
strncpy ( V_51 -> V_102 . V_103 , L_8 , 4 ) ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f ) {
F_14 ( L_9 ,
( V_104 ) V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
return - V_105 ;
}
if ( V_51 -> V_102 . V_106 < 0x0200 ) {
F_14 ( L_10 ) ;
return - V_105 ;
}
if ( ! V_51 -> V_102 . V_107 ) {
F_14 ( L_11 ) ;
return - V_105 ;
}
F_29 ( L_12 ) ;
if ( V_51 -> V_102 . V_108 )
F_30 ( L_13 ,
( ( char * ) V_8 -> V_19 ) + V_51 -> V_102 . V_108 ) ;
if ( V_51 -> V_102 . V_109 )
F_30 ( L_13 ,
( ( char * ) V_8 -> V_19 ) + V_51 -> V_102 . V_109 ) ;
if ( V_51 -> V_102 . V_110 )
F_30 ( L_13 ,
( ( char * ) V_8 -> V_19 ) + V_51 -> V_102 . V_110 ) ;
if ( V_51 -> V_102 . V_111 )
F_30 ( L_14 ,
( ( char * ) V_8 -> V_19 ) + V_51 -> V_102 . V_111 ) ;
F_30 ( L_15 ,
( V_51 -> V_102 . V_106 & 0xff00 ) >> 8 ,
V_51 -> V_102 . V_106 & 0xff ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_112 = 0 , V_26 ;
T_1 * V_49 ;
V_51 -> V_88 = 0 ;
V_49 = ( T_1 * ) ( ( ( V_33 * ) & V_51 -> V_102 ) + V_51 -> V_102 . V_107 ) ;
while ( * V_49 != 0xffff ) {
V_51 -> V_88 ++ ;
V_49 ++ ;
}
V_51 -> V_89 = F_10 ( sizeof( struct V_48 ) *
V_51 -> V_88 , V_29 ) ;
if ( ! V_51 -> V_89 )
return - V_30 ;
V_49 = ( T_1 * ) ( ( ( V_33 * ) & V_51 -> V_102 ) + V_51 -> V_102 . V_107 ) ;
while ( * V_49 != 0xffff ) {
struct V_48 * V_113 ;
F_20 ( V_8 ) ;
V_8 -> V_16 . V_94 . V_95 = 0x4f01 ;
V_8 -> V_16 . V_94 . V_96 = ( V_104 ) * V_49 ;
V_8 -> V_16 . V_39 = V_98 | V_114 ;
V_8 -> V_16 . V_17 = sizeof( struct V_48 ) ;
V_8 -> V_19 = V_51 -> V_89 + V_112 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f ) {
F_9 ( L_16 ,
* V_49 , ( V_104 ) V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
V_49 ++ ;
V_51 -> V_88 -- ;
continue;
}
V_113 = V_8 -> V_19 ;
V_113 -> V_115 = * V_49 ;
if ( ( V_113 -> V_116 & V_117 ) == V_117 &&
V_113 -> V_68 >= 8 )
V_112 ++ ;
else
V_51 -> V_88 -- ;
V_49 ++ ;
V_113 -> V_83 = V_113 -> V_73 + V_113 -> V_76 + V_113 -> V_79 ;
if ( V_113 -> V_83 == 0 || ( V_113 -> V_83 == 24 &&
V_113 -> V_68 == 32 ) )
V_113 -> V_83 = V_113 -> V_68 ;
}
if ( V_51 -> V_88 > 0 )
return 0 ;
else
return - V_105 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_84 , V_26 ;
F_20 ( V_8 ) ;
V_8 -> V_16 . V_94 . V_95 = 0x4f0a ;
V_8 -> V_16 . V_94 . V_118 = 0x0 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x4f || V_8 -> V_16 . V_94 . V_119 < 0xc000 ) {
V_51 -> V_120 = V_51 -> V_62 = 0 ;
} else {
V_51 -> V_121 = ( T_1 * ) F_33 ( ( ( V_104 ) V_8 -> V_16 . V_94 . V_119 << 4 )
+ V_8 -> V_16 . V_94 . V_122 ) ;
V_51 -> V_123 = ( V_33 * ) V_51 -> V_121 + V_51 -> V_121 [ 1 ] ;
V_51 -> V_124 = ( V_33 * ) V_51 -> V_121 + V_51 -> V_121 [ 2 ] ;
F_29 ( L_17 ,
( T_1 ) V_8 -> V_16 . V_94 . V_119 , ( T_1 ) V_8 -> V_16 . V_94 . V_122 ) ;
F_29 ( L_18 ,
V_51 -> V_123 , V_51 -> V_124 ) ;
if ( V_51 -> V_121 [ 3 ] ) {
F_29 ( L_19 ) ;
for ( V_84 = V_51 -> V_121 [ 3 ] / 2 ;
V_51 -> V_121 [ V_84 ] != 0xffff ; V_84 ++ )
F_30 ( L_20 , V_51 -> V_121 [ V_84 ] ) ;
F_30 ( L_21 ) ;
if ( V_51 -> V_121 [ V_84 ] != 0xffff ) {
F_29 ( L_22 ) ;
V_51 -> V_62 = V_51 -> V_120 = 0 ;
}
}
}
return 0 ;
}
static int F_34 ( struct V_125 * V_49 ,
struct V_46 * V_47 )
{
if ( V_47 -> V_126 . V_127 ) {
F_35 ( & V_47 -> V_45 , V_49 ) ;
if ( F_36 ( & V_47 -> V_45 , V_47 ) )
return 0 ;
}
if ( F_23 ( V_47 -> V_51 , V_49 -> V_56 , V_49 -> V_58 , 8 ,
V_91 ) == - 1 )
return 0 ;
return 1 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
int V_26 = 0 ;
if ( V_128 || V_51 -> V_102 . V_106 < 0x0300 )
return - V_105 ;
V_8 -> V_16 . V_94 . V_95 = 0x4f15 ;
V_8 -> V_16 . V_94 . V_118 = 0 ;
V_8 -> V_16 . V_94 . V_96 = 0 ;
V_8 -> V_16 . V_17 = 0 ;
V_8 -> V_16 . V_39 = 0 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f || V_26 )
return - V_105 ;
if ( ( V_8 -> V_16 . V_94 . V_118 & 0x3 ) == 3 ) {
F_29 ( L_23 ) ;
} else if ( ( V_8 -> V_16 . V_94 . V_118 & 0x3 ) == 2 ) {
F_29 ( L_24 ) ;
} else if ( ( V_8 -> V_16 . V_94 . V_118 & 0x3 ) == 1 ) {
F_29 ( L_25 ) ;
} else {
F_29 ( L_26 ) ;
return - V_105 ;
}
V_8 -> V_16 . V_94 . V_95 = 0x4f15 ;
V_8 -> V_16 . V_94 . V_118 = 1 ;
V_8 -> V_16 . V_94 . V_96 = V_8 -> V_16 . V_94 . V_97 = 0 ;
V_8 -> V_16 . V_39 = V_98 | V_114 ;
V_8 -> V_16 . V_17 = V_129 ;
V_8 -> V_19 = F_10 ( V_129 , V_29 ) ;
if ( ! V_8 -> V_19 )
return - V_30 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) == 0x004f && ! V_26 ) {
F_38 ( V_8 -> V_19 , & V_47 -> V_126 ) ;
if ( V_47 -> V_126 . V_130 && V_47 -> V_126 . V_131 ) {
if ( V_47 -> V_126 . V_132 == 0 )
V_47 -> V_126 . V_132 = 300 * 1000000 ;
V_47 -> V_126 . V_127 = 1 ;
}
} else {
V_26 = - V_105 ;
}
F_18 ( V_8 -> V_19 ) ;
return V_26 ;
}
static void F_39 ( struct V_7 * V_8 ,
struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
int V_84 ;
memset ( & V_47 -> V_126 , 0 , sizeof( V_47 -> V_126 ) ) ;
if ( F_37 ( V_8 , V_47 ) ) {
V_47 -> V_126 . V_127 = 0 ;
V_51 -> V_133 = 1 ;
}
if ( V_134 )
V_47 -> V_126 . V_132 = V_134 * 1000000 ;
if ( V_135 )
V_47 -> V_126 . V_130 = V_135 ;
if ( V_136 )
V_47 -> V_126 . V_131 = V_136 * 1000 ;
if ( V_47 -> V_126 . V_127 == 0 && V_134 && V_135 && V_136 ) {
V_47 -> V_126 . V_137 = 0 ;
V_47 -> V_126 . V_138 = 60 ;
V_47 -> V_126 . V_139 = 29000 ;
V_47 -> V_126 . V_127 = 1 ;
V_51 -> V_133 = 0 ;
}
if ( V_47 -> V_126 . V_127 )
F_29 ( L_27 ,
V_47 -> V_126 . V_130 ,
( int ) ( V_47 -> V_126 . V_131 / 1000 ) ,
( int ) ( V_47 -> V_126 . V_132 / 1000000 ) ) ;
else
F_29 ( L_28 ) ;
for ( V_84 = 0 ; V_84 < V_51 -> V_88 ; V_84 ++ ) {
struct V_44 V_45 ;
struct V_48 * V_49 ;
struct V_125 V_52 ;
V_49 = & V_51 -> V_89 [ V_84 ] ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_56 = V_49 -> V_57 ;
V_45 . V_58 = V_49 -> V_59 ;
F_40 ( V_140 | V_141 , 60 , & V_45 , V_47 ) ;
F_41 ( & V_52 , & V_45 ) ;
F_42 ( & V_52 , & V_47 -> V_142 ) ;
}
for ( V_84 = 0 ; V_84 < V_143 ; V_84 ++ ) {
if ( F_34 ( (struct V_125 * )
& V_144 [ V_84 ] , V_47 ) )
F_42 ( & V_144 [ V_84 ] , & V_47 -> V_142 ) ;
}
for ( V_84 = 0 ; V_84 < V_47 -> V_126 . V_145 ; V_84 ++ ) {
if ( F_34 ( & V_47 -> V_126 . V_146 [ V_84 ] , V_47 ) )
F_42 ( & V_47 -> V_126 . V_146 [ V_84 ] ,
& V_47 -> V_142 ) ;
}
return;
}
static void F_43 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_26 ;
F_20 ( V_8 ) ;
V_8 -> V_16 . V_94 . V_95 = 0x4f04 ;
V_8 -> V_16 . V_94 . V_96 = 0x000f ;
V_8 -> V_16 . V_94 . V_97 = 0x0000 ;
V_8 -> V_16 . V_39 = 0 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f ) {
F_9 ( L_29 ,
V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
V_51 -> V_93 = 0 ;
return;
}
V_51 -> V_93 = 64 * ( V_8 -> V_16 . V_94 . V_118 & 0xffff ) ;
}
static int F_44 ( struct V_46 * V_47 )
{
struct V_7 * V_8 = NULL ;
struct V_50 * V_51 = V_47 -> V_51 ;
int V_26 ;
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_26 = F_28 ( V_8 , V_51 ) ;
if ( V_26 )
goto V_35;
V_26 = F_31 ( V_8 , V_51 ) ;
if ( V_26 )
goto V_35;
V_51 -> V_133 = V_133 ;
#ifdef F_45
V_51 -> V_120 = V_120 ;
V_51 -> V_62 = V_62 ;
if ( V_51 -> V_120 || V_51 -> V_62 ) {
if ( V_147 & V_148 ) {
V_51 -> V_120 = V_51 -> V_62 = 0 ;
F_9 ( L_30 ) ;
} else {
F_32 ( V_8 , V_51 ) ;
}
}
#else
V_51 -> V_120 = V_51 -> V_62 = 0 ;
#endif
F_46 ( & V_47 -> V_142 ) ;
F_39 ( V_8 , V_47 ) ;
F_43 ( V_8 , V_51 ) ;
V_35: F_19 ( V_8 ) ;
return V_26 ;
}
static int F_47 ( struct V_46 * V_47 )
{
struct V_149 * V_150 ;
struct V_151 * V_142 ;
struct V_125 * V_49 ;
struct V_50 * V_51 = V_47 -> V_51 ;
int V_84 , V_152 ;
if ( V_153 ) {
for ( V_84 = 0 ; V_84 < V_51 -> V_88 ; V_84 ++ ) {
if ( V_51 -> V_89 [ V_84 ] . V_115 == V_153 ) {
V_152 = V_84 ;
F_22 ( & V_47 -> V_45 , V_47 ,
& V_51 -> V_89 [ V_152 ] ) ;
F_40 ( V_140 | V_141 , 60 ,
& V_47 -> V_45 , V_47 ) ;
V_47 -> V_45 . V_154 = 0 ;
goto V_155;
}
}
F_29 ( L_31 , V_153 ) ;
V_153 = 0 ;
}
V_84 = 0 ;
F_48 (pos, &info->modelist)
V_84 ++ ;
V_49 = F_10 ( V_84 * sizeof( * V_49 ) , V_29 ) ;
if ( V_49 ) {
V_84 = 0 ;
F_48 (pos, &info->modelist) {
V_142 = F_49 ( V_150 , struct V_151 , V_156 ) ;
V_49 [ V_84 ] = V_142 -> V_49 ;
V_84 ++ ;
}
if ( ! V_157 )
V_157 = V_158 ;
V_84 = F_50 ( & V_47 -> V_45 , V_47 , V_157 , V_49 , V_84 ,
NULL , 8 ) ;
F_18 ( V_49 ) ;
}
if ( V_84 == 0 ) {
V_47 -> V_45 . V_56 = 640 ;
V_47 -> V_45 . V_58 = 480 ;
V_49 = (struct V_125 * )
F_51 ( & V_47 -> V_45 , & V_47 -> V_142 ) ;
if ( V_49 ) {
F_35 ( & V_47 -> V_45 , V_49 ) ;
} else {
V_152 = V_51 -> V_89 [ 0 ] . V_115 ;
F_22 ( & V_47 -> V_45 , V_47 ,
& V_51 -> V_89 [ V_152 ] ) ;
F_40 ( V_140 | V_141 , 60 ,
& V_47 -> V_45 , V_47 ) ;
goto V_155;
}
}
V_152 = F_23 ( V_51 , V_47 -> V_45 . V_56 , V_47 -> V_45 . V_58 ,
V_47 -> V_45 . V_68 , V_91 ) ;
if ( V_152 == - 1 )
return - V_105 ;
F_22 ( & V_47 -> V_45 , V_47 , & V_51 -> V_89 [ V_152 ] ) ;
V_155:
if ( V_51 -> V_102 . V_106 < 0x0300 || V_51 -> V_133 )
F_40 ( V_140 | V_141 , 60 ,
& V_47 -> V_45 , V_47 ) ;
return V_152 ;
}
static int F_52 ( struct V_159 * V_160 , int V_161 ,
int V_162 , struct V_46 * V_47 )
{
struct V_7 * V_8 ;
#ifdef F_53
struct V_50 * V_51 = V_47 -> V_51 ;
int V_84 = V_51 -> V_163 ;
#endif
int V_26 = 0 ;
if ( V_162 + V_161 > 256 )
return - V_105 ;
#ifdef F_53
if ( V_84 >= 0 && V_84 < V_51 -> V_88 &&
V_51 -> V_89 [ V_84 ] . V_116 & V_164 ) {
for ( V_84 = 0 ; V_84 < V_161 ; V_84 ++ ) {
F_54 ( V_162 + V_84 , V_165 ) ;
F_54 ( V_160 [ V_84 ] . V_69 , V_166 ) ;
F_54 ( V_160 [ V_84 ] . V_74 , V_166 ) ;
F_54 ( V_160 [ V_84 ] . V_77 , V_166 ) ;
}
}
#ifdef F_45
else if ( V_51 -> V_120 ) {
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
V_8 -> V_16 . V_94 . V_95 = 0x4f09 ;
V_8 -> V_16 . V_94 . V_118 = 0x0 ;
V_8 -> V_16 . V_94 . V_96 = V_161 ;
V_8 -> V_16 . V_94 . V_97 = V_162 ;
V_8 -> V_16 . V_39 = V_114 ;
V_8 -> V_16 . V_17 = sizeof( struct V_159 ) * V_161 ;
V_8 -> V_19 = V_160 ;
V_26 = F_8 ( V_8 ) ;
if ( ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f )
V_26 = 1 ;
F_19 ( V_8 ) ;
}
return V_26 ;
}
static int F_55 ( unsigned V_167 , unsigned V_69 , unsigned V_74 ,
unsigned V_77 , unsigned V_80 ,
struct V_46 * V_47 )
{
struct V_159 V_168 ;
int V_169 = 16 - V_170 ;
int V_26 = 0 ;
if ( V_167 >= V_47 -> V_171 . V_18 )
return - V_105 ;
if ( V_47 -> V_45 . V_68 == 8 ) {
V_168 . V_69 = V_69 >> V_169 ;
V_168 . V_74 = V_74 >> V_169 ;
V_168 . V_77 = V_77 >> V_169 ;
V_168 . V_172 = 0 ;
V_26 = F_52 ( & V_168 , 1 , V_167 , V_47 ) ;
} else if ( V_167 < 16 ) {
switch ( V_47 -> V_45 . V_68 ) {
case 16 :
if ( V_47 -> V_45 . V_69 . V_70 == 10 ) {
( ( V_104 * ) ( V_47 -> V_173 ) ) [ V_167 ] =
( ( V_69 & 0xf800 ) >> 1 ) |
( ( V_74 & 0xf800 ) >> 6 ) |
( ( V_77 & 0xf800 ) >> 11 ) ;
} else {
( ( V_104 * ) ( V_47 -> V_173 ) ) [ V_167 ] =
( ( V_69 & 0xf800 ) ) |
( ( V_74 & 0xfc00 ) >> 5 ) |
( ( V_77 & 0xf800 ) >> 11 ) ;
}
break;
case 24 :
case 32 :
V_69 >>= 8 ;
V_74 >>= 8 ;
V_77 >>= 8 ;
( ( V_104 * ) ( V_47 -> V_173 ) ) [ V_167 ] =
( V_69 << V_47 -> V_45 . V_69 . V_70 ) |
( V_74 << V_47 -> V_45 . V_74 . V_70 ) |
( V_77 << V_47 -> V_45 . V_77 . V_70 ) ;
break;
}
}
return V_26 ;
}
static int F_56 ( struct V_174 * V_171 , struct V_46 * V_47 )
{
struct V_159 * V_160 ;
int V_169 = 16 - V_170 ;
int V_84 , V_26 = 0 ;
if ( V_47 -> V_45 . V_68 == 8 ) {
if ( V_171 -> V_162 + V_171 -> V_18 > V_47 -> V_171 . V_162 +
V_47 -> V_171 . V_18 || V_171 -> V_162 < V_47 -> V_171 . V_162 )
return - V_105 ;
V_160 = F_25 ( sizeof( * V_160 ) * V_171 -> V_18 , V_29 ) ;
if ( ! V_160 )
return - V_30 ;
for ( V_84 = 0 ; V_84 < V_171 -> V_18 ; V_84 ++ ) {
V_160 [ V_84 ] . V_69 = V_171 -> V_69 [ V_84 ] >> V_169 ;
V_160 [ V_84 ] . V_74 = V_171 -> V_74 [ V_84 ] >> V_169 ;
V_160 [ V_84 ] . V_77 = V_171 -> V_77 [ V_84 ] >> V_169 ;
V_160 [ V_84 ] . V_172 = 0 ;
}
V_26 = F_52 ( V_160 , V_171 -> V_18 , V_171 -> V_162 , V_47 ) ;
F_18 ( V_160 ) ;
} else {
for ( V_84 = 0 ; V_84 < V_171 -> V_18 ; V_84 ++ ) {
V_26 |= F_55 ( V_171 -> V_162 + V_84 , V_171 -> V_69 [ V_84 ] ,
V_171 -> V_74 [ V_84 ] , V_171 -> V_77 [ V_84 ] ,
0 , V_47 ) ;
}
}
return V_26 ;
}
static int F_57 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
#ifdef F_45
int V_70 ;
struct V_50 * V_51 = V_47 -> V_51 ;
V_70 = ( V_45 -> V_67 * V_47 -> V_63 . V_175 + V_45 -> V_66 ) / 4 ;
if ( V_51 -> V_123 ) {
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
static int F_58 ( int V_176 , struct V_46 * V_47 )
{
struct V_7 * V_8 ;
int V_26 = 1 ;
#ifdef F_53
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_51 -> V_102 . V_177 & V_178 ) {
int V_179 = 10000 ;
V_33 V_10 = 0 , V_180 = 0 ;
if ( V_176 == V_181 ) {
V_10 = 0x20 ;
V_180 = 0x00 ;
V_26 = 0 ;
} else {
V_10 = 0x00 ;
V_180 = 0x80 ;
V_26 = ( V_176 == V_182 ) ? 0 : - V_105 ;
}
F_59 ( NULL , 0x00 , 0x01 ) ;
V_10 |= F_60 ( NULL , 0x01 ) & ~ 0x20 ;
F_59 ( NULL , 0x00 , V_10 ) ;
V_180 |= F_61 ( NULL , 0x17 ) & ~ 0x80 ;
while ( V_179 -- ) ;
F_62 ( NULL , 0x17 , V_180 ) ;
F_59 ( NULL , 0x00 , 0x03 ) ;
} else
#endif
{
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_16 . V_94 . V_95 = 0x4f10 ;
switch ( V_176 ) {
case V_182 :
V_8 -> V_16 . V_94 . V_118 = 0x0001 ;
break;
case V_183 :
V_8 -> V_16 . V_94 . V_118 = 0x0101 ;
break;
case V_181 :
V_8 -> V_16 . V_94 . V_118 = 0x0401 ;
break;
default:
goto V_35;
}
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f )
V_26 = 1 ;
V_35: F_19 ( V_8 ) ;
}
return V_26 ;
}
static int F_63 ( struct V_46 * V_47 , int V_184 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
int V_185 = F_64 ( & V_51 -> V_186 ) ;
V_33 * V_19 = NULL ;
if ( ! V_185 && V_51 -> V_93 ) {
V_19 = F_24 ( V_51 ) ;
if ( F_65 ( V_19 ) ) {
F_9 ( L_32 ,
F_66 ( V_19 ) ) ;
} else {
V_51 -> V_187 = V_19 ;
}
}
F_67 ( & V_51 -> V_186 ) ;
return 0 ;
}
static int F_68 ( struct V_46 * V_47 , int V_184 )
{
struct V_7 * V_8 = NULL ;
struct V_50 * V_51 = V_47 -> V_51 ;
int V_185 = F_64 ( & V_51 -> V_186 ) ;
if ( ! V_185 )
return - V_105 ;
if ( V_185 != 1 )
goto V_35;
V_8 = F_21 () ;
if ( ! V_8 )
goto V_35;
V_8 -> V_16 . V_94 . V_95 = 0x0003 ;
F_8 ( V_8 ) ;
F_27 ( V_51 , V_51 -> V_187 ) ;
V_35:
F_69 ( & V_51 -> V_186 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
static int F_70 ( struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
struct V_7 * V_8 = NULL ;
struct V_188 * V_189 = NULL ;
struct V_48 * V_49 = NULL ;
int V_84 , V_26 = 0 , V_83 = V_47 -> V_45 . V_68 ;
if ( V_83 > 8 && V_83 != 32 )
V_83 = V_47 -> V_45 . V_69 . V_72 + V_47 -> V_45 . V_74 . V_72 +
V_47 -> V_45 . V_77 . V_72 ;
V_84 = F_23 ( V_51 , V_47 -> V_45 . V_56 , V_47 -> V_45 . V_58 , V_83 ,
V_91 | V_90 ) ;
if ( V_84 >= 0 )
V_49 = & V_51 -> V_89 [ V_84 ] ;
else
return - V_105 ;
V_8 = F_21 () ;
if ( ! V_8 )
return - V_30 ;
V_190:
V_8 -> V_16 . V_94 . V_95 = 0x4f02 ;
V_8 -> V_16 . V_94 . V_118 = V_49 -> V_115 | 0x4000 ;
if ( V_51 -> V_102 . V_106 >= 0x0300 && ! V_51 -> V_133 &&
V_47 -> V_45 . V_154 != 0 ) {
V_8 -> V_16 . V_94 . V_118 |= 0x0800 ;
V_8 -> V_16 . V_39 = V_114 ;
V_189 = F_10 ( sizeof( struct V_188 ) , V_29 ) ;
if ( ! V_189 ) {
V_26 = - V_30 ;
goto V_35;
}
V_189 -> V_191 = V_47 -> V_45 . V_56 + V_47 -> V_45 . V_192 ;
V_189 -> V_193 = V_189 -> V_191 + V_47 -> V_45 . V_194 ;
V_189 -> V_195 = V_189 -> V_193 + V_47 -> V_45 . V_196 ;
V_189 -> V_197 = V_47 -> V_45 . V_58 + V_47 -> V_45 . V_198 ;
V_189 -> V_199 = V_189 -> V_197 + V_47 -> V_45 . V_200 ;
V_189 -> V_201 = V_189 -> V_199 + V_47 -> V_45 . V_202 ;
V_189 -> V_203 = F_71 ( V_47 -> V_45 . V_154 ) * 1000 ;
V_189 -> V_204 = ( T_1 ) ( 100 * ( V_189 -> V_203 /
( V_189 -> V_201 * V_189 -> V_195 ) ) ) ;
if ( V_47 -> V_45 . V_52 & V_205 )
V_189 -> V_39 |= 0x1 ;
if ( V_47 -> V_45 . V_52 & V_206 )
V_189 -> V_39 |= 0x2 ;
if ( ! ( V_47 -> V_45 . V_54 & V_207 ) )
V_189 -> V_39 |= 0x4 ;
if ( ! ( V_47 -> V_45 . V_54 & V_55 ) )
V_189 -> V_39 |= 0x8 ;
memcpy ( & V_51 -> V_189 , V_189 , sizeof( * V_189 ) ) ;
} else {
memset ( & V_51 -> V_189 , 0 , sizeof( * V_189 ) ) ;
}
V_8 -> V_16 . V_17 = sizeof( struct V_188 ) ;
V_8 -> V_19 = & V_51 -> V_189 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f ) {
if ( V_189 != NULL ) {
F_9 ( L_33 ,
V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
F_20 ( V_8 ) ;
F_18 ( V_189 ) ;
V_189 = NULL ;
V_47 -> V_45 . V_154 = 0 ;
goto V_190;
} else {
F_14 ( L_34 ,
V_8 -> V_16 . V_94 . V_95 , V_26 ) ;
V_26 = - V_105 ;
goto V_35;
}
}
V_51 -> V_163 = V_84 ;
if ( V_51 -> V_102 . V_177 & V_208 &&
V_49 -> V_68 <= 8 ) {
F_20 ( V_8 ) ;
V_8 -> V_16 . V_94 . V_95 = 0x4f08 ;
V_8 -> V_16 . V_94 . V_118 = 0x0800 ;
V_26 = F_8 ( V_8 ) ;
if ( V_26 || ( V_8 -> V_16 . V_94 . V_95 & 0xffff ) != 0x004f ||
( ( V_8 -> V_16 . V_94 . V_118 & 0xff00 ) >> 8 ) != 8 ) {
V_170 = 6 ;
} else {
V_170 = 8 ;
}
}
V_47 -> V_63 . V_209 = ( V_47 -> V_45 . V_68 == 8 ) ?
V_210 : V_211 ;
V_47 -> V_63 . V_175 = V_49 -> V_65 ;
V_35:
F_18 ( V_189 ) ;
F_19 ( V_8 ) ;
return V_26 ;
}
static void F_72 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
const struct V_125 * V_49 ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( ! V_45 -> V_154 )
return;
if ( V_51 -> V_102 . V_106 < 0x0300 ) {
F_40 ( V_140 | V_141 , 60 , V_45 , V_47 ) ;
return;
}
if ( ! F_36 ( V_45 , V_47 ) )
return;
V_49 = F_51 ( V_45 , & V_47 -> V_142 ) ;
if ( V_49 ) {
if ( V_49 -> V_56 == V_45 -> V_56 && V_49 -> V_58 == V_45 -> V_58 &&
! ( V_49 -> V_52 & ( V_206 | V_205 ) ) ) {
F_35 ( V_45 , V_49 ) ;
return;
}
}
if ( V_47 -> V_126 . V_127 && ! F_40 ( V_212 , 0 , V_45 , V_47 ) )
return;
V_45 -> V_154 = 0 ;
}
static int F_73 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
struct V_48 * V_49 = NULL ;
int V_85 = - 1 ;
int V_83 = V_45 -> V_69 . V_72 + V_45 -> V_74 . V_72 + V_45 -> V_77 . V_72 ;
if ( V_83 == 0 || abs ( V_83 - V_45 -> V_68 ) >= 8 )
V_83 = V_45 -> V_68 ;
V_85 = F_23 ( V_51 , V_45 -> V_56 , V_45 -> V_58 , V_83 ,
V_91 ) ;
if ( V_85 == - 1 )
return - V_105 ;
V_49 = & V_51 -> V_89 [ V_85 ] ;
F_22 ( V_45 , V_47 , V_49 ) ;
if ( V_45 -> V_58 * V_49 -> V_65 > V_47 -> V_63 . V_64
&& V_47 -> V_63 . V_64 )
return - V_105 ;
if ( ( V_45 -> V_52 & V_205 ) &&
! ( V_51 -> V_89 [ V_85 ] . V_116 & 0x100 ) )
V_45 -> V_52 &= ~ V_205 ;
if ( ( V_45 -> V_52 & V_206 ) &&
! ( V_51 -> V_89 [ V_85 ] . V_116 & 0x200 ) )
V_45 -> V_52 &= ~ V_206 ;
F_72 ( V_45 , V_47 ) ;
V_45 -> V_60 = V_45 -> V_56 ;
V_45 -> V_61 = ( V_51 -> V_62 ) ?
V_47 -> V_63 . V_64 / V_49 -> V_65 :
V_45 -> V_58 ;
return 0 ;
}
static void F_74 ( struct V_46 * V_47 , struct V_48 * V_49 )
{
unsigned int V_213 ;
unsigned int V_214 ;
unsigned int V_215 ;
struct V_50 * V_51 = V_47 -> V_51 ;
int V_84 , V_86 ;
V_47 -> V_173 = ( ( V_33 * ) V_47 -> V_51 + sizeof( struct V_50 ) ) ;
V_47 -> V_63 = V_216 ;
V_47 -> V_63 . V_217 = V_51 -> V_62 ? 1 : 0 ;
V_47 -> V_63 . V_218 = ( V_51 -> V_62 > 1 ) ? 1 : 0 ;
if ( ! V_176 )
V_47 -> V_219 -> V_220 = NULL ;
V_214 = 0 ;
for ( V_84 = 0 ; V_84 < V_51 -> V_88 ; V_84 ++ ) {
V_86 = V_51 -> V_89 [ V_84 ] . V_65 *
V_51 -> V_89 [ V_84 ] . V_59 ;
if ( V_86 > V_214 )
V_214 = V_86 ;
}
V_214 *= 2 ;
V_213 = V_47 -> V_45 . V_58 * V_49 -> V_65 ;
V_215 = V_51 -> V_102 . V_221 * 65536 ;
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
V_47 -> V_63 . V_64 = V_214 ;
V_47 -> V_63 . V_224 = V_49 -> V_225 ;
V_47 -> V_45 . V_61 = V_47 -> V_63 . V_64 /
V_49 -> V_65 ;
if ( V_51 -> V_62 && V_47 -> V_45 . V_61 > V_47 -> V_45 . V_58 ) {
F_29 ( L_35 ,
( V_51 -> V_62 > 1 ) ? L_36 : L_37 ,
V_47 -> V_45 . V_61 ) ;
} else {
F_29 ( L_38 ) ;
V_47 -> V_45 . V_61 = V_47 -> V_45 . V_58 ;
V_51 -> V_62 = 0 ;
}
V_47 -> V_39 = V_226 |
( V_51 -> V_62 ? V_227 : 0 ) ;
if ( ! V_51 -> V_62 )
V_47 -> V_219 -> V_228 = NULL ;
}
static void F_75 ( struct V_46 * V_47 )
{
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_229 && ! ( V_47 -> V_63 . V_224 & ( V_230 - 1 ) ) ) {
int V_231 = V_47 -> V_63 . V_64 ;
int V_232 ;
V_231 = F_76 ( V_231 ) ;
do {
V_232 = F_77 ( V_47 -> V_63 . V_224 , V_231 ) ;
V_231 >>= 1 ;
} while ( V_231 >= V_230 && V_232 == - V_105 );
if ( V_232 >= 0 )
V_51 -> V_233 = V_232 ;
}
}
static void F_78 ( struct V_46 * V_47 )
{
V_47 -> V_234 = F_79 ( V_47 -> V_63 . V_224 , V_47 -> V_63 . V_64 ) ;
}
static T_2 F_80 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
return snprintf ( V_19 , V_230 , L_39 , V_51 -> V_102 . V_106 ) ;
}
static T_2 F_83 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
int V_239 = 0 , V_84 ;
for ( V_84 = 0 ; V_84 < V_51 -> V_88 && V_239 < V_230 ; V_84 ++ ) {
V_239 += snprintf ( V_19 + V_239 , V_230 - V_239 ,
L_40 ,
V_51 -> V_89 [ V_84 ] . V_57 , V_51 -> V_89 [ V_84 ] . V_59 ,
V_51 -> V_89 [ V_84 ] . V_83 , V_51 -> V_89 [ V_84 ] . V_115 ) ;
}
return V_239 ;
}
static T_2 F_84 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_51 -> V_102 . V_108 )
return snprintf ( V_19 , V_230 , L_41 , ( char * )
( & V_51 -> V_102 ) + V_51 -> V_102 . V_108 ) ;
else
return 0 ;
}
static T_2 F_85 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_51 -> V_102 . V_109 )
return snprintf ( V_19 , V_230 , L_41 , ( char * )
( & V_51 -> V_102 ) + V_51 -> V_102 . V_109 ) ;
else
return 0 ;
}
static T_2 F_86 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_51 -> V_102 . V_110 )
return snprintf ( V_19 , V_230 , L_41 , ( char * )
( & V_51 -> V_102 ) + V_51 -> V_102 . V_110 ) ;
else
return 0 ;
}
static T_2 F_87 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_51 -> V_102 . V_111 )
return snprintf ( V_19 , V_230 , L_41 ,
( char * ) ( & V_51 -> V_102 ) + V_51 -> V_102 . V_111 ) ;
else
return 0 ;
}
static T_2 F_88 ( struct V_235 * V_236 ,
struct V_237 * V_238 , char * V_19 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
return snprintf ( V_19 , V_230 , L_42 , V_51 -> V_133 ) ;
}
static T_2 F_89 ( struct V_235 * V_236 ,
struct V_237 * V_238 , const char * V_19 , T_3 V_161 )
{
struct V_46 * V_47 = F_81 ( F_82 ( V_236 ) ) ;
struct V_50 * V_51 = V_47 -> V_51 ;
if ( V_161 > 0 ) {
if ( V_19 [ 0 ] == '0' )
V_51 -> V_133 = 0 ;
else
V_51 -> V_133 = 1 ;
}
return V_161 ;
}
static int F_90 ( struct V_240 * V_236 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 = NULL ;
struct V_50 * V_51 ;
int V_26 = 0 , V_84 ;
V_47 = F_91 ( sizeof( * V_51 ) + sizeof( V_104 ) * 256 , & V_236 -> V_236 ) ;
if ( ! V_47 )
return - V_30 ;
V_51 = V_47 -> V_51 ;
V_26 = F_44 ( V_47 ) ;
if ( V_26 ) {
F_14 ( L_43 , V_26 ) ;
goto V_35;
}
V_47 -> V_219 = & V_241 ;
V_84 = F_47 ( V_47 ) ;
if ( V_84 < 0 ) {
V_26 = - V_105 ;
goto V_35;
} else {
V_49 = & V_51 -> V_89 [ V_84 ] ;
}
if ( F_92 ( & V_47 -> V_171 , 256 , 0 ) < 0 ) {
V_26 = - V_242 ;
goto V_35;
}
F_74 ( V_47 , V_49 ) ;
if ( ! F_93 ( 0x3c0 , 32 , L_44 ) ) {
F_14 ( L_45 ) ;
V_26 = - V_243 ;
goto V_244;
}
if ( ! F_94 ( V_47 -> V_63 . V_224 , V_47 -> V_63 . V_64 ,
L_44 ) ) {
F_14 ( L_46 ,
V_47 -> V_63 . V_224 ) ;
V_26 = - V_243 ;
goto V_245;
}
F_75 ( V_47 ) ;
F_78 ( V_47 ) ;
if ( ! V_47 -> V_234 ) {
F_14 ( L_47 ,
V_47 -> V_63 . V_64 , V_47 -> V_63 . V_224 ) ;
V_26 = - V_243 ;
goto V_246;
}
F_95 ( V_236 , V_47 ) ;
if ( F_96 ( V_47 ) < 0 ) {
F_14 ( L_48 ) ;
V_26 = - V_105 ;
goto V_247;
}
F_29 ( L_49 ,
V_47 -> V_63 . V_224 , V_47 -> V_234 ,
V_47 -> V_63 . V_64 / 1024 , V_51 -> V_102 . V_221 * 64 ) ;
V_46 ( V_47 , L_50 , V_47 -> V_63 . V_31 ) ;
V_26 = F_97 ( & V_236 -> V_236 . V_248 , & V_249 ) ;
if ( V_26 != 0 )
F_98 ( V_47 , L_51 ) ;
return 0 ;
V_247:
F_99 ( V_47 -> V_234 ) ;
V_246:
F_100 ( V_47 -> V_63 . V_224 , V_47 -> V_63 . V_64 ) ;
V_245:
F_101 ( 0x3c0 , 32 ) ;
V_244:
if ( ! F_102 ( & V_47 -> V_142 ) )
F_103 ( & V_47 -> V_142 ) ;
F_104 ( V_47 -> V_126 . V_146 ) ;
F_105 ( & V_47 -> V_171 ) ;
V_35:
F_18 ( V_51 -> V_89 ) ;
F_106 ( V_47 ) ;
return V_26 ;
}
static int F_107 ( struct V_240 * V_236 )
{
struct V_46 * V_47 = F_81 ( V_236 ) ;
if ( V_47 ) {
struct V_50 * V_51 = V_47 -> V_51 ;
F_108 ( & V_236 -> V_236 . V_248 , & V_249 ) ;
F_109 ( V_47 ) ;
F_101 ( 0x3c0 , 32 ) ;
F_99 ( V_47 -> V_234 ) ;
F_110 ( V_51 -> V_233 ) ;
F_100 ( V_47 -> V_63 . V_224 , V_47 -> V_63 . V_64 ) ;
F_104 ( V_47 -> V_126 . V_146 ) ;
F_105 ( & V_47 -> V_171 ) ;
F_18 ( V_51 -> V_89 ) ;
F_18 ( V_51 -> V_187 ) ;
F_18 ( V_51 -> V_250 ) ;
F_106 ( V_47 ) ;
}
return 0 ;
}
static int F_111 ( char * V_251 )
{
char * V_252 ;
if ( ! V_251 || ! * V_251 )
return 0 ;
while ( ( V_252 = F_112 ( & V_251 , L_52 ) ) != NULL ) {
if ( ! * V_252 ) continue;
if ( ! strcmp ( V_252 , L_53 ) )
V_62 = 0 ;
else if ( ! strcmp ( V_252 , L_37 ) )
V_62 = 1 ;
else if ( ! strcmp ( V_252 , L_36 ) )
V_62 = 2 ;
else if ( ! strcmp ( V_252 , L_54 ) )
V_120 = 0 ;
else if ( ! strcmp ( V_252 , L_55 ) )
V_120 = 1 ;
else if ( ! strncmp ( V_252 , L_56 , 5 ) )
V_229 = F_113 ( V_252 + 5 , NULL , 0 ) ;
else if ( ! strcmp ( V_252 , L_57 ) )
V_229 = 0 ;
else if ( ! strcmp ( V_252 , L_58 ) )
V_133 = 1 ;
else if ( ! strcmp ( V_252 , L_59 ) )
V_128 = 1 ;
else if ( ! strcmp ( V_252 , L_60 ) )
V_176 = 0 ;
else if ( ! strncmp ( V_252 , L_61 , 7 ) )
V_222 = F_113 ( V_252 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_252 , L_62 , 7 ) )
V_223 = F_113 ( V_252 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_252 , L_63 , 6 ) )
V_136 = F_113 ( V_252 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_252 , L_64 , 6 ) )
V_135 = F_113 ( V_252 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_252 , L_65 , 7 ) )
V_134 = F_113 ( V_252 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_252 , L_66 , 8 ) )
V_153 = F_113 ( V_252 + 8 , NULL , 0 ) ;
else if ( V_252 [ 0 ] >= '0' && V_252 [ 0 ] <= '9' ) {
V_157 = V_252 ;
} else {
F_9 ( L_67 , V_252 ) ;
}
}
if ( V_229 != 3 && V_229 != 0 )
F_9 ( L_68 , V_229 ) ;
return 0 ;
}
static T_2 F_114 ( struct V_253 * V_236 , char * V_19 )
{
return snprintf ( V_19 , V_230 , L_41 , V_23 ) ;
}
static T_2 F_115 ( struct V_253 * V_236 , const char * V_19 ,
T_3 V_161 )
{
strncpy ( V_23 , V_19 , V_254 ) ;
return V_161 ;
}
static int F_116 ( void )
{
int V_26 ;
#ifndef F_117
char * V_255 = NULL ;
if ( F_118 ( L_44 , & V_255 ) )
return - V_256 ;
F_111 ( V_255 ) ;
#endif
V_26 = F_119 ( & V_32 , L_44 , F_1 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_120 ( & V_257 ) ;
if ( ! V_26 ) {
V_258 = F_121 ( L_44 , 0 ) ;
if ( V_258 )
V_26 = F_122 ( V_258 ) ;
else
V_26 = - V_30 ;
if ( V_26 ) {
F_123 ( V_258 ) ;
F_124 ( & V_257 ) ;
F_125 ( & V_32 ) ;
return V_26 ;
}
V_26 = F_126 ( & V_257 . V_259 ,
& V_260 ) ;
if ( V_26 ) {
F_9 ( L_51 ) ;
V_26 = 0 ;
}
}
return V_26 ;
}
static void F_127 ( void )
{
struct V_7 * V_8 ;
if ( V_37 ) {
V_8 = F_21 () ;
if ( V_8 ) {
V_8 -> V_16 . V_39 = V_40 ;
F_8 ( V_8 ) ;
F_19 ( V_8 ) ;
}
}
F_125 ( & V_32 ) ;
F_128 ( & V_257 . V_259 , & V_260 ) ;
F_129 ( V_258 ) ;
F_124 ( & V_257 ) ;
}
static int F_130 ( const char * V_261 , const struct V_262 * V_263 )
{
V_62 = 0 ;
if ( ! strcmp ( V_261 , L_53 ) )
V_62 = 0 ;
else if ( ! strcmp ( V_261 , L_37 ) )
V_62 = 1 ;
else if ( ! strcmp ( V_261 , L_36 ) )
V_62 = 2 ;
else
return - V_105 ;
return 0 ;
}
