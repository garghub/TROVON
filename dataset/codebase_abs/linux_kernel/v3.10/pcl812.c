static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
int V_12 , V_13 ;
F_2 ( V_9 -> V_14 | 1 , V_2 -> V_15 + V_16 ) ;
F_3 ( V_2 , V_4 , V_6 -> V_17 , 1 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_2 ( 255 , V_2 -> V_15 + V_18 ) ;
F_4 ( 5 ) ;
V_12 = 50 ;
while ( V_12 -- ) {
V_13 = F_5 ( V_2 -> V_15 + V_19 ) ;
if ( ! ( V_13 & V_20 ) )
goto V_21;
F_4 ( 1 ) ;
}
F_6
( L_1 ,
V_2 -> V_22 , V_2 -> V_23 , V_2 -> V_15 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
return - V_24 ;
V_21:
V_7 [ V_11 ] = ( ( V_13 & 0xf ) << 8 ) | F_5 ( V_2 -> V_15 + V_25 ) ;
}
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_11 ;
int V_12 ;
F_2 ( 1 , V_2 -> V_15 + V_16 ) ;
F_3 ( V_2 , V_4 , V_6 -> V_17 , 1 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
F_2 ( 255 , V_2 -> V_15 + V_18 ) ;
F_4 ( 5 ) ;
V_12 = 50 ;
while ( V_12 -- ) {
if ( ! ( F_5 ( V_2 -> V_15 + V_26 ) & V_27 ) )
goto V_21;
F_4 ( 1 ) ;
}
F_6
( L_1 ,
V_2 -> V_22 , V_2 -> V_23 , V_2 -> V_15 ) ;
F_2 ( 0 , V_2 -> V_15 + V_16 ) ;
return - V_24 ;
V_21:
V_7 [ V_11 ] =
( F_5 ( V_2 -> V_15 +
V_19 ) << 8 ) | F_5 ( V_2 -> V_15 + V_25 ) ;
}
F_2 ( 0 , V_2 -> V_15 + V_16 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_28 = F_9 ( V_6 -> V_17 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_11 ; V_29 ++ ) {
F_2 ( ( V_7 [ V_29 ] & 0xff ) ,
V_2 -> V_15 + ( V_28 ? V_30 : V_31 ) ) ;
F_2 ( ( V_7 [ V_29 ] >> 8 ) & 0x0f ,
V_2 -> V_15 + ( V_28 ? V_32 : V_33 ) ) ;
V_9 -> V_34 [ V_28 ] = V_7 [ V_29 ] ;
}
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_28 = F_9 ( V_6 -> V_17 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_11 ; V_29 ++ )
V_7 [ V_29 ] = V_9 -> V_34 [ V_28 ] ;
return V_29 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_5 ( V_2 -> V_15 + V_35 ) ;
V_7 [ 1 ] |= F_5 ( V_2 -> V_15 + V_36 ) << 8 ;
return V_6 -> V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_37 &= ~ V_7 [ 0 ] ;
V_4 -> V_37 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_4 -> V_37 & 0xff , V_2 -> V_15 + V_38 ) ;
F_2 ( ( V_4 -> V_37 >> 8 ) , V_2 -> V_15 + V_39 ) ;
}
V_7 [ 1 ] = V_4 -> V_37 ;
return V_6 -> V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_40 * V_41 )
{
const struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_44 = 0 ;
unsigned int V_45 ;
int V_46 , V_47 , V_48 ;
V_44 |= F_15 ( & V_41 -> V_49 , V_50 ) ;
V_44 |= F_15 ( & V_41 -> V_51 , V_52 ) ;
if ( V_9 -> V_53 )
V_45 = V_54 ;
else
V_45 = V_55 ;
V_44 |= F_15 ( & V_41 -> V_56 , V_45 ) ;
V_44 |= F_15 ( & V_41 -> V_57 , V_58 ) ;
V_44 |= F_15 ( & V_41 -> V_59 , V_58 | V_60 ) ;
if ( V_44 )
return 1 ;
V_44 |= F_16 ( V_41 -> V_59 ) ;
if ( V_44 )
return 2 ;
V_44 |= F_17 ( & V_41 -> V_61 , 0 ) ;
V_44 |= F_17 ( & V_41 -> V_62 , 0 ) ;
if ( V_41 -> V_56 == V_55 )
V_44 |= F_18 ( & V_41 -> V_63 ,
V_43 -> V_64 ) ;
else
V_44 |= F_17 ( & V_41 -> V_63 , 0 ) ;
V_44 |= F_18 ( & V_41 -> V_65 , 1 ) ;
V_44 |= F_19 ( & V_41 -> V_65 , V_66 ) ;
V_44 |= F_17 ( & V_41 -> V_67 , V_41 -> V_65 ) ;
if ( V_41 -> V_59 == V_58 )
V_44 |= F_18 ( & V_41 -> V_68 , 1 ) ;
else
V_44 |= F_17 ( & V_41 -> V_68 , 0 ) ;
if ( V_44 )
return 3 ;
if ( V_41 -> V_56 == V_55 ) {
V_46 = V_41 -> V_63 ;
F_20 ( V_43 -> V_69 , & V_47 ,
& V_48 , & V_41 -> V_63 ,
V_41 -> V_45 & V_70 ) ;
if ( V_41 -> V_63 < V_43 -> V_64 )
V_41 -> V_63 = V_43 -> V_64 ;
if ( V_46 != V_41 -> V_63 )
V_44 ++ ;
}
if ( V_44 )
return 4 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_47 = 0 , V_48 = 0 , V_29 , V_71 , V_72 ;
struct V_40 * V_41 = & V_4 -> V_73 -> V_41 ;
if ( V_41 -> V_49 != V_50 )
return - V_74 ;
if ( V_41 -> V_51 != V_52 )
return - V_74 ;
if ( V_9 -> V_53 ) {
if ( V_41 -> V_56 != V_54 )
return - V_74 ;
} else {
if ( V_41 -> V_56 != V_55 )
return - V_74 ;
}
if ( V_41 -> V_57 != V_58 )
return - V_74 ;
if ( V_41 -> V_67 != V_41 -> V_65 )
return - V_74 ;
if ( V_41 -> V_65 > V_66 )
return - V_74 ;
if ( V_41 -> V_56 == V_55 ) {
if ( V_41 -> V_63 < V_43 -> V_64 )
V_41 -> V_63 = V_43 -> V_64 ;
F_20 ( V_43 -> V_69 ,
& V_47 , & V_48 ,
& V_41 -> V_63 ,
V_41 -> V_45 & V_70 ) ;
}
F_22 ( V_2 , - 1 , 0 , 0 ) ;
V_9 -> V_75 = V_41 -> V_65 ;
memcpy ( V_9 -> V_76 , V_41 -> V_77 ,
sizeof( unsigned int ) * V_41 -> V_67 ) ;
F_3 ( V_2 , V_4 , V_9 -> V_76 [ 0 ] , 1 ) ;
if ( V_9 -> V_78 ) {
V_9 -> V_79 = 1 ;
for ( V_29 = 1 ; V_29 < V_9 -> V_75 ; V_29 ++ )
if ( V_9 -> V_76 [ 0 ] != V_9 -> V_76 [ V_29 ] ) {
V_9 -> V_79 = 0 ;
break;
}
} else
V_9 -> V_79 = 0 ;
V_9 -> V_80 = V_41 -> V_45 ;
V_9 -> V_81 = V_4 -> V_73 -> V_82 ;
V_9 -> V_83 = V_4 -> V_73 -> V_84 ;
if ( V_41 -> V_59 == V_58 ) {
V_9 -> V_85 = V_41 -> V_68 ;
V_9 -> V_86 = 0 ;
} else {
V_9 -> V_85 = 0 ;
V_9 -> V_86 = 1 ;
}
V_9 -> V_87 = 0 ;
V_9 -> V_88 = 0 ;
V_4 -> V_73 -> V_89 = 0 ;
if ( ( V_9 -> V_80 & V_90 ) ) {
V_9 -> V_91 = 1 ;
if ( V_9 -> V_75 == 1 )
V_9 -> V_79 = 0 ;
}
if ( V_9 -> V_79 ) {
if ( V_9 -> V_91 ) {
V_9 -> V_92 [ 0 ] =
V_9 -> V_75 * sizeof( short ) ;
V_9 -> V_92 [ 1 ] =
V_9 -> V_75 * sizeof( short ) ;
V_9 -> V_93 = 1 ;
} else {
V_9 -> V_92 [ 0 ] = V_9 -> V_94 [ 0 ] ;
V_9 -> V_92 [ 1 ] = V_9 -> V_94 [ 1 ] ;
if ( V_9 -> V_81 < V_9 -> V_94 [ 0 ] )
V_9 -> V_92 [ 0 ] =
V_9 -> V_81 ;
if ( V_9 -> V_81 < V_9 -> V_94 [ 1 ] )
V_9 -> V_92 [ 1 ] =
V_9 -> V_81 ;
if ( V_9 -> V_86 ) {
V_9 -> V_93 = 1 ;
} else {
V_72 = V_9 -> V_75 *
V_9 -> V_85 * sizeof( short ) ;
V_9 -> V_93 =
V_72 / V_9 -> V_92 [ 0 ] ;
V_9 -> V_95 =
V_72 % V_9 -> V_92 [ 0 ] ;
if ( V_9 -> V_93 == 0 )
V_9 -> V_92 [ 0 ] =
V_9 -> V_95 ;
V_9 -> V_93 -- ;
}
}
if ( V_9 -> V_92 [ 0 ] > V_9 -> V_94 [ 0 ] ) {
V_9 -> V_92 [ 0 ] = V_9 -> V_94 [ 0 ] ;
V_9 -> V_91 = 0 ;
}
if ( V_9 -> V_92 [ 1 ] > V_9 -> V_94 [ 1 ] ) {
V_9 -> V_92 [ 1 ] = V_9 -> V_94 [ 1 ] ;
V_9 -> V_91 = 0 ;
}
V_9 -> V_96 = 0 ;
F_23 ( V_9 -> V_78 , V_97 ) ;
V_71 = F_24 () ;
F_25 ( V_9 -> V_78 ) ;
F_26 ( V_9 -> V_78 , V_9 -> V_98 [ 0 ] ) ;
F_27 ( V_9 -> V_78 , V_9 -> V_92 [ 0 ] ) ;
F_28 ( V_71 ) ;
F_29 ( V_9 -> V_78 ) ;
}
switch ( V_41 -> V_56 ) {
case V_55 :
F_22 ( V_2 , 1 , V_47 , V_48 ) ;
break;
}
if ( V_9 -> V_79 )
F_2 ( V_9 -> V_14 | 2 , V_2 -> V_15 + V_16 ) ;
else
F_2 ( V_9 -> V_14 | 6 , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_30 ( int V_99 , void * V_100 )
{
char V_44 = 1 ;
unsigned int V_101 , V_12 ;
struct V_1 * V_2 = V_100 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_102 [ 0 ] ;
unsigned int V_103 ;
V_4 -> V_73 -> V_104 = 0 ;
V_12 = 50 ;
if ( V_9 -> V_105 ) {
V_101 = 0xffff ;
while ( V_12 -- ) {
if ( ! ( F_5 ( V_2 -> V_15 + V_26 ) & V_27 ) ) {
V_44 = 0 ;
break;
}
F_4 ( 1 ) ;
}
} else {
V_101 = 0x0fff ;
while ( V_12 -- ) {
if ( ! ( F_5 ( V_2 -> V_15 + V_19 ) & V_20 ) ) {
V_44 = 0 ;
break;
}
F_4 ( 1 ) ;
}
}
if ( V_44 ) {
F_6
( L_2
L_3 ,
V_2 -> V_22 , V_2 -> V_23 , V_2 -> V_15 ) ;
F_31 ( V_2 , V_4 ) ;
V_4 -> V_73 -> V_104 |= V_106 | V_107 ;
F_32 ( V_2 , V_4 ) ;
return V_108 ;
}
F_33 ( V_4 -> V_73 ,
( ( F_5 ( V_2 -> V_15 + V_19 ) << 8 ) |
F_5 ( V_2 -> V_15 + V_25 ) ) & V_101 ) ;
V_103 = V_4 -> V_73 -> V_89 + 1 ;
if ( V_103 >= V_9 -> V_75 )
V_103 = 0 ;
if ( V_9 -> V_76 [ V_4 -> V_73 -> V_89 ] !=
V_9 -> V_76 [ V_103 ] )
F_3 ( V_2 , V_4 , V_9 -> V_76 [ V_103 ] , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_109 ) ;
V_4 -> V_73 -> V_89 = V_103 ;
if ( V_103 == 0 ) {
V_9 -> V_87 ++ ;
if ( ! ( V_9 -> V_86 ) )
if ( V_9 -> V_87 >= V_9 -> V_85 ) {
F_31 ( V_2 , V_4 ) ;
V_4 -> V_73 -> V_104 |= V_106 ;
}
}
F_32 ( V_2 , V_4 ) ;
return V_108 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , short * V_110 ,
unsigned int V_111 , unsigned int V_112 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_29 ;
V_4 -> V_73 -> V_104 = 0 ;
for ( V_29 = V_112 ; V_29 ; V_29 -- ) {
F_33 ( V_4 -> V_73 , V_110 [ V_111 ++ ] ) ;
V_4 -> V_73 -> V_89 ++ ;
if ( V_4 -> V_73 -> V_89 >= V_9 -> V_75 ) {
V_4 -> V_73 -> V_89 = 0 ;
V_9 -> V_87 ++ ;
if ( ! V_9 -> V_86 )
if ( V_9 -> V_87 >= V_9 -> V_85 ) {
F_31 ( V_2 , V_4 ) ;
V_4 -> V_73 -> V_104 |= V_106 ;
break;
}
}
}
F_32 ( V_2 , V_4 ) ;
}
static T_1 F_35 ( int V_99 , void * V_100 )
{
struct V_1 * V_2 = V_100 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_102 [ 0 ] ;
unsigned long V_71 ;
int V_112 , V_111 ;
short * V_110 ;
V_110 = ( short * ) V_9 -> V_113 [ V_9 -> V_96 ] ;
V_112 = ( V_9 -> V_92 [ V_9 -> V_96 ] >> 1 ) -
V_9 -> V_88 ;
V_9 -> V_96 = 1 - V_9 -> V_96 ;
F_36 ( V_9 -> V_78 ) ;
F_23 ( V_9 -> V_78 , V_97 ) ;
V_71 = F_24 () ;
F_26 ( V_9 -> V_78 , V_9 -> V_98 [ V_9 -> V_96 ] ) ;
if ( V_9 -> V_91 ) {
F_27 ( V_9 -> V_78 ,
V_9 -> V_92 [ V_9 -> V_96 ] ) ;
} else {
if ( V_9 -> V_93 ) {
F_27 ( V_9 -> V_78 ,
V_9 -> V_92 [ V_9 ->
V_96 ] ) ;
} else {
F_27 ( V_9 -> V_78 , V_9 -> V_95 ) ;
}
V_9 -> V_93 -- ;
}
F_28 ( V_71 ) ;
F_29 ( V_9 -> V_78 ) ;
F_2 ( 0 , V_2 -> V_15 + V_109 ) ;
V_111 = V_9 -> V_88 ;
V_9 -> V_88 = 0 ;
F_34 ( V_2 , V_4 , V_110 , V_111 , V_112 ) ;
return V_108 ;
}
static T_1 F_37 ( int V_99 , void * V_100 )
{
struct V_1 * V_2 = V_100 ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_2 -> V_114 ) {
F_38 ( V_2 , L_4 ) ;
return V_108 ;
}
if ( V_9 -> V_79 )
return F_35 ( V_99 , V_100 ) ;
else
return F_30 ( V_99 , V_100 ) ;
}
static int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_45 ;
unsigned int V_115 , V_116 , V_29 ;
if ( ! V_9 -> V_79 )
return 0 ;
F_40 ( & V_2 -> V_117 , V_45 ) ;
for ( V_29 = 0 ; V_29 < 10 ; V_29 ++ ) {
V_115 = F_41 ( V_9 -> V_79 ) ;
V_116 = F_41 ( V_9 -> V_79 ) ;
if ( V_115 == V_116 )
break;
}
if ( V_115 != V_116 ) {
F_42 ( & V_2 -> V_117 , V_45 ) ;
return 0 ;
}
V_115 = V_9 -> V_92 [ 1 - V_9 -> V_96 ] - V_115 ;
V_115 >>= 1 ;
V_116 = V_115 - V_9 -> V_88 ;
if ( V_116 < 1 ) {
F_42 ( & V_2 -> V_117 , V_45 ) ;
return 0 ;
}
F_34 ( V_2 , V_4 ,
( void * ) V_9 -> V_113 [ 1 -
V_9 -> V_96 ] ,
V_9 -> V_88 , V_116 ) ;
V_9 -> V_88 = V_115 ;
F_42 ( & V_2 -> V_117 , V_45 ) ;
return V_4 -> V_73 -> V_118 - V_4 -> V_73 -> V_119 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_120 , char V_121 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned char V_122 = F_9 ( V_120 ) ;
unsigned char V_123 = F_43 ( V_120 ) +
V_9 -> V_124 ;
if ( ( V_122 == V_9 -> V_125 )
&& ( V_123 == V_9 -> V_126 ) )
return;
V_9 -> V_125 = V_122 ;
V_9 -> V_126 = V_123 ;
if ( V_9 -> V_127 ) {
if ( V_9 -> V_128 ) {
V_122 = V_122 | 0x30 ;
} else {
if ( V_122 & 0x80 )
V_122 = V_122 | 0x20 ;
else
V_122 = V_122 | 0x10 ;
}
}
F_2 ( V_122 , V_2 -> V_15 + V_129 ) ;
F_2 ( V_123 , V_2 -> V_15 + V_130 ) ;
if ( V_121 )
F_4 ( V_9 -> V_131 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_132 ,
unsigned int V_47 , unsigned int V_48 )
{
F_2 ( 0xb4 , V_2 -> V_15 + V_133 ) ;
F_2 ( 0x74 , V_2 -> V_15 + V_133 ) ;
F_4 ( 1 ) ;
if ( V_132 == 1 ) {
F_2 ( V_48 & 0xff , V_2 -> V_15 + V_134 ) ;
F_2 ( ( V_48 >> 8 ) & 0xff , V_2 -> V_15 + V_134 ) ;
F_2 ( V_47 & 0xff , V_2 -> V_15 + V_135 ) ;
F_2 ( ( V_47 >> 8 ) & 0xff , V_2 -> V_15 + V_135 ) ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_79 )
F_36 ( V_9 -> V_78 ) ;
F_2 ( 0 , V_2 -> V_15 + V_109 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
F_22 ( V_2 , - 1 , 0 , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_109 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
const struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
F_2 ( 0 , V_2 -> V_15 + V_129 ) ;
F_2 ( 0 + V_9 -> V_124 , V_2 -> V_15 + V_130 ) ;
V_9 -> V_125 = - 1 ;
V_9 -> V_126 = - 1 ;
switch ( V_43 -> V_136 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
F_2 ( 0 , V_2 -> V_15 + V_30 ) ;
F_2 ( 0 , V_2 -> V_15 + V_32 ) ;
case V_141 :
F_2 ( 0 , V_2 -> V_15 + V_31 ) ;
F_2 ( 0 , V_2 -> V_15 + V_33 ) ;
F_22 ( V_2 , - 1 , 0 , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_39 ) ;
F_2 ( 0 , V_2 -> V_15 + V_38 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
F_2 ( 0 , V_2 -> V_15 + V_109 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
F_4 ( 5 ) ;
break;
}
F_4 ( 5 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
const struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_8 * V_9 ;
int V_148 , V_149 ;
unsigned int V_99 ;
unsigned int V_78 ;
unsigned long V_150 ;
struct V_3 * V_4 ;
int V_151 ;
V_148 = F_46 ( V_2 , V_147 -> V_152 [ 0 ] , V_43 -> V_153 ) ;
if ( V_148 )
return V_148 ;
V_9 = F_47 ( sizeof( * V_9 ) , V_154 ) ;
if ( ! V_9 )
return - V_155 ;
V_2 -> V_10 = V_9 ;
V_99 = 0 ;
if ( V_43 -> V_156 != 0 ) {
V_99 = V_147 -> V_152 [ 1 ] ;
if ( V_99 ) {
if ( ( ( 1 << V_99 ) & V_43 -> V_156 ) == 0 ) {
F_6
( L_5
L_6 , V_99 ) ;
V_99 = 0 ;
} else {
if ( F_48 ( V_99 , F_37 , 0 ,
V_2 -> V_23 , V_2 ) ) {
F_6
( L_7
L_6 , V_99 ) ;
V_99 = 0 ;
} else {
F_6 ( V_157 L_8 , V_99 ) ;
}
}
}
}
V_2 -> V_99 = V_99 ;
V_78 = 0 ;
V_9 -> V_78 = V_78 ;
if ( ! V_2 -> V_99 )
goto V_158;
if ( V_43 -> V_159 != 0 ) {
V_78 = V_147 -> V_152 [ 2 ] ;
if ( ( ( 1 << V_78 ) & V_43 -> V_159 ) == 0 ) {
F_6 ( L_9 ) ;
return - V_74 ;
}
V_148 = F_49 ( V_78 , V_2 -> V_23 ) ;
if ( V_148 ) {
F_6 ( V_160 L_10 ,
V_78 ) ;
return - V_161 ;
}
V_9 -> V_78 = V_78 ;
F_6 ( V_157 L_11 , V_78 ) ;
V_150 = 1 ;
V_9 -> V_113 [ 0 ] = F_50 ( V_154 , V_150 ) ;
if ( ! V_9 -> V_113 [ 0 ] ) {
F_6 ( L_12 ) ;
return - V_161 ;
}
V_9 -> V_162 [ 0 ] = V_150 ;
V_9 -> V_98 [ 0 ] = F_51 ( ( void * ) V_9 -> V_113 [ 0 ] ) ;
V_9 -> V_94 [ 0 ] = V_163 * ( 1 << V_150 ) ;
V_9 -> V_113 [ 1 ] = F_50 ( V_154 , V_150 ) ;
if ( ! V_9 -> V_113 [ 1 ] ) {
F_6 ( V_160 L_12 ) ;
return - V_161 ;
}
V_9 -> V_162 [ 1 ] = V_150 ;
V_9 -> V_98 [ 1 ] = F_51 ( ( void * ) V_9 -> V_113 [ 1 ] ) ;
V_9 -> V_94 [ 1 ] = V_163 * ( 1 << V_150 ) ;
}
V_158:
V_151 = 0 ;
if ( V_43 -> V_164 > 0 )
V_151 ++ ;
if ( V_43 -> V_165 > 0 )
V_151 ++ ;
if ( V_43 -> V_166 > 0 )
V_151 ++ ;
if ( V_43 -> V_167 > 0 )
V_151 ++ ;
V_148 = F_52 ( V_2 , V_151 ) ;
if ( V_148 )
return V_148 ;
V_149 = 0 ;
if ( V_43 -> V_164 > 0 ) {
V_4 = & V_2 -> V_102 [ V_149 ] ;
V_4 -> type = V_168 ;
V_4 -> V_169 = V_170 ;
switch ( V_43 -> V_136 ) {
case V_141 :
if ( V_147 -> V_152 [ 2 ] == 1 ) {
V_4 -> V_171 = V_43 -> V_172 ;
V_4 -> V_169 |= V_173 ;
V_9 -> V_128 = 1 ;
} else {
V_4 -> V_171 = V_43 -> V_164 ;
V_4 -> V_169 |= V_174 ;
}
break;
case V_139 :
case V_140 :
if ( V_147 -> V_152 [ 4 ] == 1 ) {
V_4 -> V_171 = V_43 -> V_172 ;
V_4 -> V_169 |= V_173 ;
V_9 -> V_128 = 1 ;
} else {
V_4 -> V_171 = V_43 -> V_164 ;
V_4 -> V_169 |= V_174 ;
}
break;
default:
V_4 -> V_171 = V_43 -> V_164 ;
V_4 -> V_169 |= V_174 ;
break;
}
V_4 -> V_175 = V_43 -> V_176 ;
V_4 -> V_177 = V_66 ;
V_4 -> V_178 = V_43 -> V_179 ;
if ( V_43 -> V_136 == V_140 )
V_4 -> V_180 = F_7 ;
else
V_4 -> V_180 = F_1 ;
V_9 -> V_127 = V_43 -> V_181 ;
V_4 -> V_182 = F_31 ;
if ( V_2 -> V_99 ) {
V_2 -> V_183 = V_4 ;
V_4 -> V_169 |= V_184 ;
V_4 -> V_185 = F_13 ;
V_4 -> V_186 = F_21 ;
V_4 -> V_187 = F_39 ;
}
switch ( V_43 -> V_136 ) {
case V_137 :
if ( V_147 -> V_152 [ 4 ] == 1 )
V_4 -> V_178 = & V_188 ;
break;
case V_138 :
switch ( V_147 -> V_152 [ 4 ] ) {
case 0 :
V_4 -> V_178 = & V_189 ;
break;
case 1 :
V_4 -> V_178 = & V_190 ;
break;
case 2 :
V_4 -> V_178 = & V_191 ;
break;
case 3 :
V_4 -> V_178 = & V_192 ;
break;
case 4 :
V_4 -> V_178 = & V_193 ;
break;
case 5 :
V_4 -> V_178 = & V_194 ;
break;
default:
V_4 -> V_178 = & V_189 ;
break;
F_6
( L_13
L_14 , V_147 -> V_152 [ 4 ] ) ;
break;
}
break;
break;
case V_142 :
if ( V_147 -> V_152 [ 1 ] == 1 )
V_4 -> V_178 = & V_195 ;
break;
case V_144 :
switch ( V_147 -> V_152 [ 1 ] ) {
case 0 :
V_4 -> V_178 = & V_196 ;
break;
case 1 :
V_4 -> V_178 = & V_197 ;
break;
case 2 :
V_4 -> V_178 = & V_198 ;
V_9 -> V_124 = 1 ;
break;
case 3 :
V_4 -> V_178 = & V_199 ;
V_9 -> V_124 = 1 ;
break;
default:
V_4 -> V_178 = & V_196 ;
break;
F_6
( L_15
L_16 , V_147 -> V_152 [ 1 ] ) ;
break;
}
break;
case V_145 :
switch ( V_147 -> V_152 [ 1 ] ) {
case 0 :
V_4 -> V_178 = & V_200 ;
break;
case 1 :
V_4 -> V_178 = & V_201 ;
break;
case 2 :
V_4 -> V_178 = & V_202 ;
V_9 -> V_124 = 1 ;
break;
case 3 :
V_4 -> V_178 = & V_203 ;
V_9 -> V_124 = 1 ;
break;
default:
V_4 -> V_178 = & V_200 ;
break;
F_6
( L_15
L_16 , V_147 -> V_152 [ 1 ] ) ;
break;
}
break;
}
V_149 ++ ;
}
if ( V_43 -> V_165 > 0 ) {
V_4 = & V_2 -> V_102 [ V_149 ] ;
V_4 -> type = V_204 ;
V_4 -> V_169 = V_205 | V_174 ;
V_4 -> V_171 = V_43 -> V_165 ;
V_4 -> V_175 = 0xfff ;
V_4 -> V_177 = 1 ;
V_4 -> V_178 = V_43 -> V_206 ;
V_4 -> V_180 = F_10 ;
V_4 -> V_207 = F_8 ;
switch ( V_43 -> V_136 ) {
case V_141 :
if ( V_147 -> V_152 [ 3 ] == 1 )
V_4 -> V_178 = & V_208 ;
break;
case V_138 :
case V_139 :
case V_137 :
case V_140 :
if ( V_147 -> V_152 [ 5 ] == 1 )
V_4 -> V_178 = & V_208 ;
if ( V_147 -> V_152 [ 5 ] == 2 )
V_4 -> V_178 = & V_209 ;
break;
}
V_149 ++ ;
}
if ( V_43 -> V_166 > 0 ) {
V_4 = & V_2 -> V_102 [ V_149 ] ;
V_4 -> type = V_210 ;
V_4 -> V_169 = V_170 ;
V_4 -> V_171 = V_43 -> V_166 ;
V_4 -> V_175 = 1 ;
V_4 -> V_177 = V_43 -> V_166 ;
V_4 -> V_178 = & V_211 ;
V_4 -> V_212 = F_11 ;
V_149 ++ ;
}
if ( V_43 -> V_167 > 0 ) {
V_4 = & V_2 -> V_102 [ V_149 ] ;
V_4 -> type = V_213 ;
V_4 -> V_169 = V_205 ;
V_4 -> V_171 = V_43 -> V_167 ;
V_4 -> V_175 = 1 ;
V_4 -> V_177 = V_43 -> V_167 ;
V_4 -> V_178 = & V_211 ;
V_4 -> V_212 = F_12 ;
V_149 ++ ;
}
switch ( V_43 -> V_136 ) {
case V_140 :
V_9 -> V_105 = 1 ;
case V_137 :
case V_138 :
case V_139 :
V_9 -> V_131 = 1 ;
if ( V_147 -> V_152 [ 3 ] > 0 )
V_9 -> V_53 = 1 ;
case V_141 :
V_9 -> V_131 = 1 ;
V_9 -> V_14 = ( V_99 << 4 ) & 0xf0 ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_9 -> V_131 = 5 ;
break;
}
F_6 ( V_157 L_17 ) ;
V_9 -> V_214 = 1 ;
F_44 ( V_2 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 ) {
if ( V_9 -> V_113 [ 0 ] )
F_54 ( V_9 -> V_113 [ 0 ] , V_9 -> V_162 [ 0 ] ) ;
if ( V_9 -> V_113 [ 1 ] )
F_54 ( V_9 -> V_113 [ 1 ] , V_9 -> V_162 [ 1 ] ) ;
if ( V_9 -> V_78 )
F_55 ( V_9 -> V_78 ) ;
}
F_56 ( V_2 ) ;
}
