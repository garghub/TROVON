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
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_13 ( V_4 , V_7 ) ) {
F_2 ( V_4 -> V_37 & 0xff , V_2 -> V_15 + V_38 ) ;
F_2 ( ( V_4 -> V_37 >> 8 ) , V_2 -> V_15 + V_39 ) ;
}
V_7 [ 1 ] = V_4 -> V_37 ;
return V_6 -> V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_40 * V_41 )
{
const struct V_42 * V_43 = F_15 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_44 = 0 ;
unsigned int V_45 ;
int V_46 , V_47 , V_48 ;
V_44 |= F_16 ( & V_41 -> V_49 , V_50 ) ;
V_44 |= F_16 ( & V_41 -> V_51 , V_52 ) ;
if ( V_9 -> V_53 )
V_45 = V_54 ;
else
V_45 = V_55 ;
V_44 |= F_16 ( & V_41 -> V_56 , V_45 ) ;
V_44 |= F_16 ( & V_41 -> V_57 , V_58 ) ;
V_44 |= F_16 ( & V_41 -> V_59 , V_58 | V_60 ) ;
if ( V_44 )
return 1 ;
V_44 |= F_17 ( V_41 -> V_59 ) ;
if ( V_44 )
return 2 ;
V_44 |= F_18 ( & V_41 -> V_61 , 0 ) ;
V_44 |= F_18 ( & V_41 -> V_62 , 0 ) ;
if ( V_41 -> V_56 == V_55 )
V_44 |= F_19 ( & V_41 -> V_63 ,
V_43 -> V_64 ) ;
else
V_44 |= F_18 ( & V_41 -> V_63 , 0 ) ;
V_44 |= F_19 ( & V_41 -> V_65 , 1 ) ;
V_44 |= F_20 ( & V_41 -> V_65 , V_66 ) ;
V_44 |= F_18 ( & V_41 -> V_67 , V_41 -> V_65 ) ;
if ( V_41 -> V_59 == V_58 )
V_44 |= F_19 ( & V_41 -> V_68 , 1 ) ;
else
V_44 |= F_18 ( & V_41 -> V_68 , 0 ) ;
if ( V_44 )
return 3 ;
if ( V_41 -> V_56 == V_55 ) {
V_46 = V_41 -> V_63 ;
F_21 ( V_43 -> V_69 ,
& V_47 , & V_48 ,
& V_41 -> V_63 , V_41 -> V_45 ) ;
if ( V_41 -> V_63 < V_43 -> V_64 )
V_41 -> V_63 = V_43 -> V_64 ;
if ( V_46 != V_41 -> V_63 )
V_44 ++ ;
}
if ( V_44 )
return 4 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_42 * V_43 = F_15 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_47 = 0 , V_48 = 0 , V_29 , V_70 , V_71 ;
struct V_40 * V_41 = & V_4 -> V_72 -> V_41 ;
if ( V_41 -> V_49 != V_50 )
return - V_73 ;
if ( V_41 -> V_51 != V_52 )
return - V_73 ;
if ( V_9 -> V_53 ) {
if ( V_41 -> V_56 != V_54 )
return - V_73 ;
} else {
if ( V_41 -> V_56 != V_55 )
return - V_73 ;
}
if ( V_41 -> V_57 != V_58 )
return - V_73 ;
if ( V_41 -> V_67 != V_41 -> V_65 )
return - V_73 ;
if ( V_41 -> V_65 > V_66 )
return - V_73 ;
if ( V_41 -> V_56 == V_55 ) {
if ( V_41 -> V_63 < V_43 -> V_64 )
V_41 -> V_63 = V_43 -> V_64 ;
F_21 ( V_43 -> V_69 ,
& V_47 , & V_48 ,
& V_41 -> V_63 , V_41 -> V_45 ) ;
}
F_23 ( V_2 , - 1 , 0 , 0 ) ;
V_9 -> V_74 = V_41 -> V_65 ;
memcpy ( V_9 -> V_75 , V_41 -> V_76 ,
sizeof( unsigned int ) * V_41 -> V_67 ) ;
F_3 ( V_2 , V_4 , V_9 -> V_75 [ 0 ] , 1 ) ;
if ( V_9 -> V_77 ) {
V_9 -> V_78 = 1 ;
for ( V_29 = 1 ; V_29 < V_9 -> V_74 ; V_29 ++ )
if ( V_9 -> V_75 [ 0 ] != V_9 -> V_75 [ V_29 ] ) {
V_9 -> V_78 = 0 ;
break;
}
} else
V_9 -> V_78 = 0 ;
V_9 -> V_79 = V_41 -> V_45 ;
V_9 -> V_80 = V_4 -> V_72 -> V_81 ;
if ( V_41 -> V_59 == V_58 ) {
V_9 -> V_82 = V_41 -> V_68 ;
V_9 -> V_83 = 0 ;
} else {
V_9 -> V_82 = 0 ;
V_9 -> V_83 = 1 ;
}
V_9 -> V_84 = 0 ;
V_9 -> V_85 = 0 ;
V_4 -> V_72 -> V_86 = 0 ;
if ( ( V_9 -> V_79 & V_87 ) ) {
V_9 -> V_88 = 1 ;
if ( V_9 -> V_74 == 1 )
V_9 -> V_78 = 0 ;
}
if ( V_9 -> V_78 ) {
if ( V_9 -> V_88 ) {
V_9 -> V_89 [ 0 ] =
V_9 -> V_74 * sizeof( short ) ;
V_9 -> V_89 [ 1 ] =
V_9 -> V_74 * sizeof( short ) ;
V_9 -> V_90 = 1 ;
} else {
V_9 -> V_89 [ 0 ] = V_9 -> V_91 [ 0 ] ;
V_9 -> V_89 [ 1 ] = V_9 -> V_91 [ 1 ] ;
if ( V_9 -> V_80 < V_9 -> V_91 [ 0 ] )
V_9 -> V_89 [ 0 ] =
V_9 -> V_80 ;
if ( V_9 -> V_80 < V_9 -> V_91 [ 1 ] )
V_9 -> V_89 [ 1 ] =
V_9 -> V_80 ;
if ( V_9 -> V_83 ) {
V_9 -> V_90 = 1 ;
} else {
V_71 = V_9 -> V_74 *
V_9 -> V_82 * sizeof( short ) ;
V_9 -> V_90 =
V_71 / V_9 -> V_89 [ 0 ] ;
V_9 -> V_92 =
V_71 % V_9 -> V_89 [ 0 ] ;
if ( V_9 -> V_90 == 0 )
V_9 -> V_89 [ 0 ] =
V_9 -> V_92 ;
V_9 -> V_90 -- ;
}
}
if ( V_9 -> V_89 [ 0 ] > V_9 -> V_91 [ 0 ] ) {
V_9 -> V_89 [ 0 ] = V_9 -> V_91 [ 0 ] ;
V_9 -> V_88 = 0 ;
}
if ( V_9 -> V_89 [ 1 ] > V_9 -> V_91 [ 1 ] ) {
V_9 -> V_89 [ 1 ] = V_9 -> V_91 [ 1 ] ;
V_9 -> V_88 = 0 ;
}
V_9 -> V_93 = 0 ;
F_24 ( V_9 -> V_77 , V_94 ) ;
V_70 = F_25 () ;
F_26 ( V_9 -> V_77 ) ;
F_27 ( V_9 -> V_77 , V_9 -> V_95 [ 0 ] ) ;
F_28 ( V_9 -> V_77 , V_9 -> V_89 [ 0 ] ) ;
F_29 ( V_70 ) ;
F_30 ( V_9 -> V_77 ) ;
}
switch ( V_41 -> V_56 ) {
case V_55 :
F_23 ( V_2 , 1 , V_47 , V_48 ) ;
break;
}
if ( V_9 -> V_78 )
F_2 ( V_9 -> V_14 | 2 , V_2 -> V_15 + V_16 ) ;
else
F_2 ( V_9 -> V_14 | 6 , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_31 ( int V_96 , void * V_97 )
{
char V_44 = 1 ;
unsigned int V_98 , V_12 ;
struct V_1 * V_2 = V_97 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_99 [ 0 ] ;
unsigned int V_100 ;
V_4 -> V_72 -> V_101 = 0 ;
V_12 = 50 ;
if ( V_9 -> V_102 ) {
V_98 = 0xffff ;
while ( V_12 -- ) {
if ( ! ( F_5 ( V_2 -> V_15 + V_26 ) & V_27 ) ) {
V_44 = 0 ;
break;
}
F_4 ( 1 ) ;
}
} else {
V_98 = 0x0fff ;
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
F_32 ( V_2 , V_4 ) ;
V_4 -> V_72 -> V_101 |= V_103 | V_104 ;
F_33 ( V_2 , V_4 ) ;
return V_105 ;
}
F_34 ( V_4 -> V_72 ,
( ( F_5 ( V_2 -> V_15 + V_19 ) << 8 ) |
F_5 ( V_2 -> V_15 + V_25 ) ) & V_98 ) ;
V_100 = V_4 -> V_72 -> V_86 + 1 ;
if ( V_100 >= V_9 -> V_74 )
V_100 = 0 ;
if ( V_9 -> V_75 [ V_4 -> V_72 -> V_86 ] !=
V_9 -> V_75 [ V_100 ] )
F_3 ( V_2 , V_4 , V_9 -> V_75 [ V_100 ] , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_106 ) ;
V_4 -> V_72 -> V_86 = V_100 ;
if ( V_100 == 0 ) {
V_9 -> V_84 ++ ;
if ( ! ( V_9 -> V_83 ) )
if ( V_9 -> V_84 >= V_9 -> V_82 ) {
F_32 ( V_2 , V_4 ) ;
V_4 -> V_72 -> V_101 |= V_103 ;
}
}
F_33 ( V_2 , V_4 ) ;
return V_105 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned short * V_107 ,
unsigned int V_108 , unsigned int V_109 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_29 ;
V_4 -> V_72 -> V_101 = 0 ;
for ( V_29 = V_109 ; V_29 ; V_29 -- ) {
F_34 ( V_4 -> V_72 , V_107 [ V_108 ++ ] ) ;
V_4 -> V_72 -> V_86 ++ ;
if ( V_4 -> V_72 -> V_86 >= V_9 -> V_74 ) {
V_4 -> V_72 -> V_86 = 0 ;
V_9 -> V_84 ++ ;
if ( ! V_9 -> V_83 )
if ( V_9 -> V_84 >= V_9 -> V_82 ) {
F_32 ( V_2 , V_4 ) ;
V_4 -> V_72 -> V_101 |= V_103 ;
break;
}
}
}
F_33 ( V_2 , V_4 ) ;
}
static T_1 F_36 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = & V_2 -> V_99 [ 0 ] ;
unsigned long V_70 ;
int V_109 , V_108 ;
unsigned short * V_107 ;
V_107 = ( unsigned short * ) V_9 -> V_110 [ V_9 -> V_93 ] ;
V_109 = ( V_9 -> V_89 [ V_9 -> V_93 ] >> 1 ) -
V_9 -> V_85 ;
V_9 -> V_93 = 1 - V_9 -> V_93 ;
F_37 ( V_9 -> V_77 ) ;
F_24 ( V_9 -> V_77 , V_94 ) ;
V_70 = F_25 () ;
F_27 ( V_9 -> V_77 , V_9 -> V_95 [ V_9 -> V_93 ] ) ;
if ( V_9 -> V_88 ) {
F_28 ( V_9 -> V_77 ,
V_9 -> V_89 [ V_9 -> V_93 ] ) ;
} else {
if ( V_9 -> V_90 ) {
F_28 ( V_9 -> V_77 ,
V_9 -> V_89 [ V_9 ->
V_93 ] ) ;
} else {
F_28 ( V_9 -> V_77 , V_9 -> V_92 ) ;
}
V_9 -> V_90 -- ;
}
F_29 ( V_70 ) ;
F_30 ( V_9 -> V_77 ) ;
F_2 ( 0 , V_2 -> V_15 + V_106 ) ;
V_108 = V_9 -> V_85 ;
V_9 -> V_85 = 0 ;
F_35 ( V_2 , V_4 , V_107 , V_108 , V_109 ) ;
return V_105 ;
}
static T_1 F_38 ( int V_96 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_2 -> V_111 ) {
F_39 ( V_2 , L_4 ) ;
return V_105 ;
}
if ( V_9 -> V_78 )
return F_36 ( V_96 , V_97 ) ;
else
return F_31 ( V_96 , V_97 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_45 ;
unsigned int V_112 , V_113 , V_29 ;
if ( ! V_9 -> V_78 )
return 0 ;
F_41 ( & V_2 -> V_114 , V_45 ) ;
for ( V_29 = 0 ; V_29 < 10 ; V_29 ++ ) {
V_112 = F_42 ( V_9 -> V_78 ) ;
V_113 = F_42 ( V_9 -> V_78 ) ;
if ( V_112 == V_113 )
break;
}
if ( V_112 != V_113 ) {
F_43 ( & V_2 -> V_114 , V_45 ) ;
return 0 ;
}
V_112 = V_9 -> V_89 [ 1 - V_9 -> V_93 ] - V_112 ;
V_112 >>= 1 ;
V_113 = V_112 - V_9 -> V_85 ;
if ( V_113 < 1 ) {
F_43 ( & V_2 -> V_114 , V_45 ) ;
return 0 ;
}
F_35 ( V_2 , V_4 ,
( void * ) V_9 -> V_110 [ 1 -
V_9 -> V_93 ] ,
V_9 -> V_85 , V_113 ) ;
V_9 -> V_85 = V_112 ;
F_43 ( & V_2 -> V_114 , V_45 ) ;
return V_4 -> V_72 -> V_115 - V_4 -> V_72 -> V_116 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_117 , char V_118 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned char V_119 = F_9 ( V_117 ) ;
unsigned char V_120 = F_44 ( V_117 ) +
V_9 -> V_121 ;
if ( ( V_119 == V_9 -> V_122 )
&& ( V_120 == V_9 -> V_123 ) )
return;
V_9 -> V_122 = V_119 ;
V_9 -> V_123 = V_120 ;
if ( V_9 -> V_124 ) {
if ( V_9 -> V_125 ) {
V_119 = V_119 | 0x30 ;
} else {
if ( V_119 & 0x80 )
V_119 = V_119 | 0x20 ;
else
V_119 = V_119 | 0x10 ;
}
}
F_2 ( V_119 , V_2 -> V_15 + V_126 ) ;
F_2 ( V_120 , V_2 -> V_15 + V_127 ) ;
if ( V_118 )
F_4 ( V_9 -> V_128 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_129 ,
unsigned int V_47 , unsigned int V_48 )
{
F_2 ( 0xb4 , V_2 -> V_15 + V_130 ) ;
F_2 ( 0x74 , V_2 -> V_15 + V_130 ) ;
F_4 ( 1 ) ;
if ( V_129 == 1 ) {
F_2 ( V_48 & 0xff , V_2 -> V_15 + V_131 ) ;
F_2 ( ( V_48 >> 8 ) & 0xff , V_2 -> V_15 + V_131 ) ;
F_2 ( V_47 & 0xff , V_2 -> V_15 + V_132 ) ;
F_2 ( ( V_47 >> 8 ) & 0xff , V_2 -> V_15 + V_132 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_78 )
F_37 ( V_9 -> V_77 ) ;
F_2 ( 0 , V_2 -> V_15 + V_106 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
F_23 ( V_2 , - 1 , 0 , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_106 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
const struct V_42 * V_43 = F_15 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
F_2 ( 0 , V_2 -> V_15 + V_126 ) ;
F_2 ( 0 + V_9 -> V_121 , V_2 -> V_15 + V_127 ) ;
V_9 -> V_122 = - 1 ;
V_9 -> V_123 = - 1 ;
switch ( V_43 -> V_133 ) {
case V_134 :
case V_135 :
case V_136 :
case V_137 :
F_2 ( 0 , V_2 -> V_15 + V_30 ) ;
F_2 ( 0 , V_2 -> V_15 + V_32 ) ;
case V_138 :
F_2 ( 0 , V_2 -> V_15 + V_31 ) ;
F_2 ( 0 , V_2 -> V_15 + V_33 ) ;
F_23 ( V_2 , - 1 , 0 , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_39 ) ;
F_2 ( 0 , V_2 -> V_15 + V_38 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
F_2 ( 0 , V_2 -> V_15 + V_106 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
F_4 ( 5 ) ;
break;
}
F_4 ( 5 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
const struct V_42 * V_43 = F_15 ( V_2 ) ;
struct V_8 * V_9 ;
int V_145 , V_146 ;
unsigned int V_96 ;
unsigned int V_77 ;
unsigned long V_147 ;
struct V_3 * V_4 ;
int V_148 ;
V_145 = F_47 ( V_2 , V_144 -> V_149 [ 0 ] , V_43 -> V_150 ) ;
if ( V_145 )
return V_145 ;
V_9 = F_48 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_151 ;
V_96 = 0 ;
if ( V_43 -> V_152 != 0 ) {
V_96 = V_144 -> V_149 [ 1 ] ;
if ( V_96 ) {
if ( ( ( 1 << V_96 ) & V_43 -> V_152 ) == 0 ) {
F_6
( L_5
L_6 , V_96 ) ;
V_96 = 0 ;
} else {
if ( F_49 ( V_96 , F_38 , 0 ,
V_2 -> V_23 , V_2 ) ) {
F_6
( L_7
L_6 , V_96 ) ;
V_96 = 0 ;
} else {
F_6 ( V_153 L_8 , V_96 ) ;
}
}
}
}
V_2 -> V_96 = V_96 ;
V_77 = 0 ;
V_9 -> V_77 = V_77 ;
if ( ! V_2 -> V_96 )
goto V_154;
if ( V_43 -> V_155 != 0 ) {
V_77 = V_144 -> V_149 [ 2 ] ;
if ( ( ( 1 << V_77 ) & V_43 -> V_155 ) == 0 ) {
F_6 ( L_9 ) ;
return - V_73 ;
}
V_145 = F_50 ( V_77 , V_2 -> V_23 ) ;
if ( V_145 ) {
F_6 ( V_156 L_10 ,
V_77 ) ;
return - V_157 ;
}
V_9 -> V_77 = V_77 ;
F_6 ( V_153 L_11 , V_77 ) ;
V_147 = 1 ;
V_9 -> V_110 [ 0 ] = F_51 ( V_158 , V_147 ) ;
if ( ! V_9 -> V_110 [ 0 ] ) {
F_6 ( L_12 ) ;
return - V_157 ;
}
V_9 -> V_159 [ 0 ] = V_147 ;
V_9 -> V_95 [ 0 ] = F_52 ( ( void * ) V_9 -> V_110 [ 0 ] ) ;
V_9 -> V_91 [ 0 ] = V_160 * ( 1 << V_147 ) ;
V_9 -> V_110 [ 1 ] = F_51 ( V_158 , V_147 ) ;
if ( ! V_9 -> V_110 [ 1 ] ) {
F_6 ( V_156 L_12 ) ;
return - V_157 ;
}
V_9 -> V_159 [ 1 ] = V_147 ;
V_9 -> V_95 [ 1 ] = F_52 ( ( void * ) V_9 -> V_110 [ 1 ] ) ;
V_9 -> V_91 [ 1 ] = V_160 * ( 1 << V_147 ) ;
}
V_154:
V_148 = 0 ;
if ( V_43 -> V_161 > 0 )
V_148 ++ ;
if ( V_43 -> V_162 > 0 )
V_148 ++ ;
if ( V_43 -> V_163 > 0 )
V_148 ++ ;
if ( V_43 -> V_164 > 0 )
V_148 ++ ;
V_145 = F_53 ( V_2 , V_148 ) ;
if ( V_145 )
return V_145 ;
V_146 = 0 ;
if ( V_43 -> V_161 > 0 ) {
V_4 = & V_2 -> V_99 [ V_146 ] ;
V_4 -> type = V_165 ;
V_4 -> V_166 = V_167 ;
switch ( V_43 -> V_133 ) {
case V_138 :
if ( V_144 -> V_149 [ 2 ] == 1 ) {
V_4 -> V_168 = V_43 -> V_169 ;
V_4 -> V_166 |= V_170 ;
V_9 -> V_125 = 1 ;
} else {
V_4 -> V_168 = V_43 -> V_161 ;
V_4 -> V_166 |= V_171 ;
}
break;
case V_136 :
case V_137 :
if ( V_144 -> V_149 [ 4 ] == 1 ) {
V_4 -> V_168 = V_43 -> V_169 ;
V_4 -> V_166 |= V_170 ;
V_9 -> V_125 = 1 ;
} else {
V_4 -> V_168 = V_43 -> V_161 ;
V_4 -> V_166 |= V_171 ;
}
break;
default:
V_4 -> V_168 = V_43 -> V_161 ;
V_4 -> V_166 |= V_171 ;
break;
}
V_4 -> V_172 = V_43 -> V_173 ;
V_4 -> V_174 = V_66 ;
V_4 -> V_175 = V_43 -> V_176 ;
if ( V_43 -> V_133 == V_137 )
V_4 -> V_177 = F_7 ;
else
V_4 -> V_177 = F_1 ;
V_9 -> V_124 = V_43 -> V_178 ;
V_4 -> V_179 = F_32 ;
if ( V_2 -> V_96 ) {
V_2 -> V_180 = V_4 ;
V_4 -> V_166 |= V_181 ;
V_4 -> V_182 = F_14 ;
V_4 -> V_183 = F_22 ;
V_4 -> V_184 = F_40 ;
}
switch ( V_43 -> V_133 ) {
case V_134 :
if ( V_144 -> V_149 [ 4 ] == 1 )
V_4 -> V_175 = & V_185 ;
break;
case V_135 :
switch ( V_144 -> V_149 [ 4 ] ) {
case 0 :
V_4 -> V_175 = & V_186 ;
break;
case 1 :
V_4 -> V_175 = & V_187 ;
break;
case 2 :
V_4 -> V_175 = & V_188 ;
break;
case 3 :
V_4 -> V_175 = & V_189 ;
break;
case 4 :
V_4 -> V_175 = & V_190 ;
break;
case 5 :
V_4 -> V_175 = & V_191 ;
break;
default:
V_4 -> V_175 = & V_186 ;
break;
F_6
( L_13
L_14 , V_144 -> V_149 [ 4 ] ) ;
break;
}
break;
break;
case V_139 :
if ( V_144 -> V_149 [ 1 ] == 1 )
V_4 -> V_175 = & V_192 ;
break;
case V_141 :
switch ( V_144 -> V_149 [ 1 ] ) {
case 0 :
V_4 -> V_175 = & V_193 ;
break;
case 1 :
V_4 -> V_175 = & V_194 ;
break;
case 2 :
V_4 -> V_175 = & V_195 ;
V_9 -> V_121 = 1 ;
break;
case 3 :
V_4 -> V_175 = & V_196 ;
V_9 -> V_121 = 1 ;
break;
default:
V_4 -> V_175 = & V_193 ;
break;
F_6
( L_15
L_16 , V_144 -> V_149 [ 1 ] ) ;
break;
}
break;
case V_142 :
switch ( V_144 -> V_149 [ 1 ] ) {
case 0 :
V_4 -> V_175 = & V_197 ;
break;
case 1 :
V_4 -> V_175 = & V_198 ;
break;
case 2 :
V_4 -> V_175 = & V_199 ;
V_9 -> V_121 = 1 ;
break;
case 3 :
V_4 -> V_175 = & V_200 ;
V_9 -> V_121 = 1 ;
break;
default:
V_4 -> V_175 = & V_197 ;
break;
F_6
( L_15
L_16 , V_144 -> V_149 [ 1 ] ) ;
break;
}
break;
}
V_146 ++ ;
}
if ( V_43 -> V_162 > 0 ) {
V_4 = & V_2 -> V_99 [ V_146 ] ;
V_4 -> type = V_201 ;
V_4 -> V_166 = V_202 | V_171 ;
V_4 -> V_168 = V_43 -> V_162 ;
V_4 -> V_172 = 0xfff ;
V_4 -> V_174 = 1 ;
V_4 -> V_175 = V_43 -> V_203 ;
V_4 -> V_177 = F_10 ;
V_4 -> V_204 = F_8 ;
switch ( V_43 -> V_133 ) {
case V_138 :
if ( V_144 -> V_149 [ 3 ] == 1 )
V_4 -> V_175 = & V_205 ;
break;
case V_135 :
case V_136 :
case V_134 :
case V_137 :
if ( V_144 -> V_149 [ 5 ] == 1 )
V_4 -> V_175 = & V_205 ;
if ( V_144 -> V_149 [ 5 ] == 2 )
V_4 -> V_175 = & V_206 ;
break;
}
V_146 ++ ;
}
if ( V_43 -> V_163 > 0 ) {
V_4 = & V_2 -> V_99 [ V_146 ] ;
V_4 -> type = V_207 ;
V_4 -> V_166 = V_167 ;
V_4 -> V_168 = V_43 -> V_163 ;
V_4 -> V_172 = 1 ;
V_4 -> V_174 = V_43 -> V_163 ;
V_4 -> V_175 = & V_208 ;
V_4 -> V_209 = F_11 ;
V_146 ++ ;
}
if ( V_43 -> V_164 > 0 ) {
V_4 = & V_2 -> V_99 [ V_146 ] ;
V_4 -> type = V_210 ;
V_4 -> V_166 = V_202 ;
V_4 -> V_168 = V_43 -> V_164 ;
V_4 -> V_172 = 1 ;
V_4 -> V_174 = V_43 -> V_164 ;
V_4 -> V_175 = & V_208 ;
V_4 -> V_209 = F_12 ;
V_146 ++ ;
}
switch ( V_43 -> V_133 ) {
case V_137 :
V_9 -> V_102 = 1 ;
case V_134 :
case V_135 :
case V_136 :
V_9 -> V_128 = 1 ;
if ( V_144 -> V_149 [ 3 ] > 0 )
V_9 -> V_53 = 1 ;
break;
case V_138 :
V_9 -> V_128 = 1 ;
V_9 -> V_14 = ( V_96 << 4 ) & 0xf0 ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
V_9 -> V_128 = 5 ;
break;
}
F_6 ( V_153 L_17 ) ;
V_9 -> V_211 = 1 ;
F_45 ( V_2 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 ) {
if ( V_9 -> V_110 [ 0 ] )
F_55 ( V_9 -> V_110 [ 0 ] , V_9 -> V_159 [ 0 ] ) ;
if ( V_9 -> V_110 [ 1 ] )
F_55 ( V_9 -> V_110 [ 1 ] , V_9 -> V_159 [ 1 ] ) ;
if ( V_9 -> V_77 )
F_56 ( V_9 -> V_77 ) ;
}
F_57 ( V_2 ) ;
}
