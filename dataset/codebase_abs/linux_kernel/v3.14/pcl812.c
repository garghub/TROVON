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
F_6 ( V_2 -> V_22 , L_1 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
return - V_23 ;
V_21:
V_7 [ V_11 ] = ( ( V_13 & 0xf ) << 8 ) | F_5 ( V_2 -> V_15 + V_24 ) ;
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
if ( ! ( F_5 ( V_2 -> V_15 + V_25 ) & V_26 ) )
goto V_21;
F_4 ( 1 ) ;
}
F_6 ( V_2 -> V_22 , L_1 ) ;
F_2 ( 0 , V_2 -> V_15 + V_16 ) ;
return - V_23 ;
V_21:
V_7 [ V_11 ] =
( F_5 ( V_2 -> V_15 +
V_19 ) << 8 ) | F_5 ( V_2 -> V_15 + V_24 ) ;
}
F_2 ( 0 , V_2 -> V_15 + V_16 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_27 = F_9 ( V_6 -> V_17 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_11 ; V_28 ++ ) {
F_2 ( ( V_7 [ V_28 ] & 0xff ) ,
V_2 -> V_15 + ( V_27 ? V_29 : V_30 ) ) ;
F_2 ( ( V_7 [ V_28 ] >> 8 ) & 0x0f ,
V_2 -> V_15 + ( V_27 ? V_31 : V_32 ) ) ;
V_9 -> V_33 [ V_27 ] = V_7 [ V_28 ] ;
}
return V_28 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_27 = F_9 ( V_6 -> V_17 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_11 ; V_28 ++ )
V_7 [ V_28 ] = V_9 -> V_33 [ V_27 ] ;
return V_28 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_5 ( V_2 -> V_15 + V_34 ) ;
V_7 [ 1 ] |= F_5 ( V_2 -> V_15 + V_35 ) << 8 ;
return V_6 -> V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_13 ( V_4 , V_7 ) ) {
F_2 ( V_4 -> V_36 & 0xff , V_2 -> V_15 + V_37 ) ;
F_2 ( ( V_4 -> V_36 >> 8 ) , V_2 -> V_15 + V_38 ) ;
}
V_7 [ 1 ] = V_4 -> V_36 ;
return V_6 -> V_11 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_39 * V_40 )
{
const struct V_41 * V_42 = F_15 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_43 = 0 ;
unsigned int V_44 ;
int V_45 , V_46 , V_47 ;
V_43 |= F_16 ( & V_40 -> V_48 , V_49 ) ;
V_43 |= F_16 ( & V_40 -> V_50 , V_51 ) ;
if ( V_9 -> V_52 )
V_44 = V_53 ;
else
V_44 = V_54 ;
V_43 |= F_16 ( & V_40 -> V_55 , V_44 ) ;
V_43 |= F_16 ( & V_40 -> V_56 , V_57 ) ;
V_43 |= F_16 ( & V_40 -> V_58 , V_57 | V_59 ) ;
if ( V_43 )
return 1 ;
V_43 |= F_17 ( V_40 -> V_58 ) ;
if ( V_43 )
return 2 ;
V_43 |= F_18 ( & V_40 -> V_60 , 0 ) ;
V_43 |= F_18 ( & V_40 -> V_61 , 0 ) ;
if ( V_40 -> V_55 == V_54 )
V_43 |= F_19 ( & V_40 -> V_62 ,
V_42 -> V_63 ) ;
else
V_43 |= F_18 ( & V_40 -> V_62 , 0 ) ;
V_43 |= F_19 ( & V_40 -> V_64 , 1 ) ;
V_43 |= F_20 ( & V_40 -> V_64 , V_65 ) ;
V_43 |= F_18 ( & V_40 -> V_66 , V_40 -> V_64 ) ;
if ( V_40 -> V_58 == V_57 )
V_43 |= F_19 ( & V_40 -> V_67 , 1 ) ;
else
V_43 |= F_18 ( & V_40 -> V_67 , 0 ) ;
if ( V_43 )
return 3 ;
if ( V_40 -> V_55 == V_54 ) {
V_45 = V_40 -> V_62 ;
F_21 ( V_42 -> V_68 ,
& V_46 , & V_47 ,
& V_40 -> V_62 , V_40 -> V_44 ) ;
if ( V_40 -> V_62 < V_42 -> V_63 )
V_40 -> V_62 = V_42 -> V_63 ;
if ( V_45 != V_40 -> V_62 )
V_43 ++ ;
}
if ( V_43 )
return 4 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_41 * V_42 = F_15 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_46 = 0 , V_47 = 0 , V_28 , V_69 , V_70 ;
struct V_39 * V_40 = & V_4 -> V_71 -> V_40 ;
if ( V_40 -> V_48 != V_49 )
return - V_72 ;
if ( V_40 -> V_50 != V_51 )
return - V_72 ;
if ( V_9 -> V_52 ) {
if ( V_40 -> V_55 != V_53 )
return - V_72 ;
} else {
if ( V_40 -> V_55 != V_54 )
return - V_72 ;
}
if ( V_40 -> V_56 != V_57 )
return - V_72 ;
if ( V_40 -> V_66 != V_40 -> V_64 )
return - V_72 ;
if ( V_40 -> V_64 > V_65 )
return - V_72 ;
if ( V_40 -> V_55 == V_54 ) {
if ( V_40 -> V_62 < V_42 -> V_63 )
V_40 -> V_62 = V_42 -> V_63 ;
F_21 ( V_42 -> V_68 ,
& V_46 , & V_47 ,
& V_40 -> V_62 , V_40 -> V_44 ) ;
}
F_23 ( V_2 , - 1 , 0 , 0 ) ;
V_9 -> V_73 = V_40 -> V_64 ;
memcpy ( V_9 -> V_74 , V_40 -> V_75 ,
sizeof( unsigned int ) * V_40 -> V_66 ) ;
F_3 ( V_2 , V_4 , V_9 -> V_74 [ 0 ] , 1 ) ;
if ( V_9 -> V_76 ) {
V_9 -> V_77 = 1 ;
for ( V_28 = 1 ; V_28 < V_9 -> V_73 ; V_28 ++ )
if ( V_9 -> V_74 [ 0 ] != V_9 -> V_74 [ V_28 ] ) {
V_9 -> V_77 = 0 ;
break;
}
} else
V_9 -> V_77 = 0 ;
V_9 -> V_78 = V_40 -> V_44 ;
V_9 -> V_79 = V_4 -> V_71 -> V_80 ;
if ( V_40 -> V_58 == V_57 ) {
V_9 -> V_81 = V_40 -> V_67 ;
V_9 -> V_82 = 0 ;
} else {
V_9 -> V_81 = 0 ;
V_9 -> V_82 = 1 ;
}
V_9 -> V_83 = 0 ;
V_9 -> V_84 = 0 ;
V_4 -> V_71 -> V_85 = 0 ;
if ( ( V_9 -> V_78 & V_86 ) ) {
V_9 -> V_87 = 1 ;
if ( V_9 -> V_73 == 1 )
V_9 -> V_77 = 0 ;
}
if ( V_9 -> V_77 ) {
if ( V_9 -> V_87 ) {
V_9 -> V_88 [ 0 ] =
V_9 -> V_73 * sizeof( short ) ;
V_9 -> V_88 [ 1 ] =
V_9 -> V_73 * sizeof( short ) ;
V_9 -> V_89 = 1 ;
} else {
V_9 -> V_88 [ 0 ] = V_9 -> V_90 [ 0 ] ;
V_9 -> V_88 [ 1 ] = V_9 -> V_90 [ 1 ] ;
if ( V_9 -> V_79 < V_9 -> V_90 [ 0 ] )
V_9 -> V_88 [ 0 ] =
V_9 -> V_79 ;
if ( V_9 -> V_79 < V_9 -> V_90 [ 1 ] )
V_9 -> V_88 [ 1 ] =
V_9 -> V_79 ;
if ( V_9 -> V_82 ) {
V_9 -> V_89 = 1 ;
} else {
V_70 = V_9 -> V_73 *
V_9 -> V_81 * sizeof( short ) ;
V_9 -> V_89 =
V_70 / V_9 -> V_88 [ 0 ] ;
V_9 -> V_91 =
V_70 % V_9 -> V_88 [ 0 ] ;
if ( V_9 -> V_89 == 0 )
V_9 -> V_88 [ 0 ] =
V_9 -> V_91 ;
V_9 -> V_89 -- ;
}
}
if ( V_9 -> V_88 [ 0 ] > V_9 -> V_90 [ 0 ] ) {
V_9 -> V_88 [ 0 ] = V_9 -> V_90 [ 0 ] ;
V_9 -> V_87 = 0 ;
}
if ( V_9 -> V_88 [ 1 ] > V_9 -> V_90 [ 1 ] ) {
V_9 -> V_88 [ 1 ] = V_9 -> V_90 [ 1 ] ;
V_9 -> V_87 = 0 ;
}
V_9 -> V_92 = 0 ;
F_24 ( V_9 -> V_76 , V_93 ) ;
V_69 = F_25 () ;
F_26 ( V_9 -> V_76 ) ;
F_27 ( V_9 -> V_76 , V_9 -> V_94 [ 0 ] ) ;
F_28 ( V_9 -> V_76 , V_9 -> V_88 [ 0 ] ) ;
F_29 ( V_69 ) ;
F_30 ( V_9 -> V_76 ) ;
}
switch ( V_40 -> V_55 ) {
case V_54 :
F_23 ( V_2 , 1 , V_46 , V_47 ) ;
break;
}
if ( V_9 -> V_77 )
F_2 ( V_9 -> V_14 | 2 , V_2 -> V_15 + V_16 ) ;
else
F_2 ( V_9 -> V_14 | 6 , V_2 -> V_15 + V_16 ) ;
return 0 ;
}
static T_1 F_31 ( int V_95 , void * V_96 )
{
char V_43 = 1 ;
unsigned int V_97 , V_12 ;
struct V_1 * V_2 = V_96 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = V_2 -> V_98 ;
unsigned int V_99 ;
V_4 -> V_71 -> V_100 = 0 ;
V_12 = 50 ;
if ( V_9 -> V_101 ) {
V_97 = 0xffff ;
while ( V_12 -- ) {
if ( ! ( F_5 ( V_2 -> V_15 + V_25 ) & V_26 ) ) {
V_43 = 0 ;
break;
}
F_4 ( 1 ) ;
}
} else {
V_97 = 0x0fff ;
while ( V_12 -- ) {
if ( ! ( F_5 ( V_2 -> V_15 + V_19 ) & V_20 ) ) {
V_43 = 0 ;
break;
}
F_4 ( 1 ) ;
}
}
if ( V_43 ) {
F_6 ( V_2 -> V_22 , L_2 ) ;
F_32 ( V_2 , V_4 ) ;
V_4 -> V_71 -> V_100 |= V_102 | V_103 ;
F_33 ( V_2 , V_4 ) ;
return V_104 ;
}
F_34 ( V_4 -> V_71 ,
( ( F_5 ( V_2 -> V_15 + V_19 ) << 8 ) |
F_5 ( V_2 -> V_15 + V_24 ) ) & V_97 ) ;
V_99 = V_4 -> V_71 -> V_85 + 1 ;
if ( V_99 >= V_9 -> V_73 )
V_99 = 0 ;
if ( V_9 -> V_74 [ V_4 -> V_71 -> V_85 ] !=
V_9 -> V_74 [ V_99 ] )
F_3 ( V_2 , V_4 , V_9 -> V_74 [ V_99 ] , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_105 ) ;
V_4 -> V_71 -> V_85 = V_99 ;
if ( V_99 == 0 ) {
V_9 -> V_83 ++ ;
if ( ! ( V_9 -> V_82 ) )
if ( V_9 -> V_83 >= V_9 -> V_81 ) {
F_32 ( V_2 , V_4 ) ;
V_4 -> V_71 -> V_100 |= V_102 ;
}
}
F_33 ( V_2 , V_4 ) ;
return V_104 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned short * V_106 ,
unsigned int V_107 , unsigned int V_108 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_28 ;
V_4 -> V_71 -> V_100 = 0 ;
for ( V_28 = V_108 ; V_28 ; V_28 -- ) {
F_34 ( V_4 -> V_71 , V_106 [ V_107 ++ ] ) ;
V_4 -> V_71 -> V_85 ++ ;
if ( V_4 -> V_71 -> V_85 >= V_9 -> V_73 ) {
V_4 -> V_71 -> V_85 = 0 ;
V_9 -> V_83 ++ ;
if ( ! V_9 -> V_82 )
if ( V_9 -> V_83 >= V_9 -> V_81 ) {
F_32 ( V_2 , V_4 ) ;
V_4 -> V_71 -> V_100 |= V_102 ;
break;
}
}
}
F_33 ( V_2 , V_4 ) ;
}
static T_1 F_36 ( int V_95 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 = V_2 -> V_98 ;
unsigned long V_69 ;
int V_108 , V_107 ;
unsigned short * V_106 ;
V_106 = ( unsigned short * ) V_9 -> V_109 [ V_9 -> V_92 ] ;
V_108 = ( V_9 -> V_88 [ V_9 -> V_92 ] >> 1 ) -
V_9 -> V_84 ;
V_9 -> V_92 = 1 - V_9 -> V_92 ;
F_37 ( V_9 -> V_76 ) ;
F_24 ( V_9 -> V_76 , V_93 ) ;
V_69 = F_25 () ;
F_27 ( V_9 -> V_76 , V_9 -> V_94 [ V_9 -> V_92 ] ) ;
if ( V_9 -> V_87 ) {
F_28 ( V_9 -> V_76 ,
V_9 -> V_88 [ V_9 -> V_92 ] ) ;
} else {
if ( V_9 -> V_89 ) {
F_28 ( V_9 -> V_76 ,
V_9 -> V_88 [ V_9 ->
V_92 ] ) ;
} else {
F_28 ( V_9 -> V_76 , V_9 -> V_91 ) ;
}
V_9 -> V_89 -- ;
}
F_29 ( V_69 ) ;
F_30 ( V_9 -> V_76 ) ;
F_2 ( 0 , V_2 -> V_15 + V_105 ) ;
V_107 = V_9 -> V_84 ;
V_9 -> V_84 = 0 ;
F_35 ( V_2 , V_4 , V_106 , V_107 , V_108 ) ;
return V_104 ;
}
static T_1 F_38 ( int V_95 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_8 * V_9 = V_2 -> V_10 ;
if ( ! V_2 -> V_110 ) {
F_39 ( V_2 , L_3 ) ;
return V_104 ;
}
if ( V_9 -> V_77 )
return F_36 ( V_95 , V_96 ) ;
else
return F_31 ( V_95 , V_96 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_44 ;
unsigned int V_111 , V_112 , V_28 ;
if ( ! V_9 -> V_77 )
return 0 ;
F_41 ( & V_2 -> V_113 , V_44 ) ;
for ( V_28 = 0 ; V_28 < 10 ; V_28 ++ ) {
V_111 = F_42 ( V_9 -> V_77 ) ;
V_112 = F_42 ( V_9 -> V_77 ) ;
if ( V_111 == V_112 )
break;
}
if ( V_111 != V_112 ) {
F_43 ( & V_2 -> V_113 , V_44 ) ;
return 0 ;
}
V_111 = V_9 -> V_88 [ 1 - V_9 -> V_92 ] - V_111 ;
V_111 >>= 1 ;
V_112 = V_111 - V_9 -> V_84 ;
if ( V_112 < 1 ) {
F_43 ( & V_2 -> V_113 , V_44 ) ;
return 0 ;
}
F_35 ( V_2 , V_4 ,
( void * ) V_9 -> V_109 [ 1 -
V_9 -> V_92 ] ,
V_9 -> V_84 , V_112 ) ;
V_9 -> V_84 = V_111 ;
F_43 ( & V_2 -> V_113 , V_44 ) ;
return V_4 -> V_71 -> V_114 - V_4 -> V_71 -> V_115 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_116 , char V_117 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned char V_118 = F_9 ( V_116 ) ;
unsigned char V_119 = F_44 ( V_116 ) +
V_9 -> V_120 ;
if ( ( V_118 == V_9 -> V_121 )
&& ( V_119 == V_9 -> V_122 ) )
return;
V_9 -> V_121 = V_118 ;
V_9 -> V_122 = V_119 ;
if ( V_9 -> V_123 ) {
if ( V_9 -> V_124 ) {
V_118 = V_118 | 0x30 ;
} else {
if ( V_118 & 0x80 )
V_118 = V_118 | 0x20 ;
else
V_118 = V_118 | 0x10 ;
}
}
F_2 ( V_118 , V_2 -> V_15 + V_125 ) ;
F_2 ( V_119 , V_2 -> V_15 + V_126 ) ;
if ( V_117 )
F_4 ( V_9 -> V_127 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_128 ,
unsigned int V_46 , unsigned int V_47 )
{
F_2 ( 0xb4 , V_2 -> V_15 + V_129 ) ;
F_2 ( 0x74 , V_2 -> V_15 + V_129 ) ;
F_4 ( 1 ) ;
if ( V_128 == 1 ) {
F_2 ( V_47 & 0xff , V_2 -> V_15 + V_130 ) ;
F_2 ( ( V_47 >> 8 ) & 0xff , V_2 -> V_15 + V_130 ) ;
F_2 ( V_46 & 0xff , V_2 -> V_15 + V_131 ) ;
F_2 ( ( V_46 >> 8 ) & 0xff , V_2 -> V_15 + V_131 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_77 )
F_37 ( V_9 -> V_76 ) ;
F_2 ( 0 , V_2 -> V_15 + V_105 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
F_23 ( V_2 , - 1 , 0 , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_105 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
const struct V_41 * V_42 = F_15 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
F_2 ( 0 , V_2 -> V_15 + V_125 ) ;
F_2 ( 0 + V_9 -> V_120 , V_2 -> V_15 + V_126 ) ;
V_9 -> V_121 = - 1 ;
V_9 -> V_122 = - 1 ;
switch ( V_42 -> V_132 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
F_2 ( 0 , V_2 -> V_15 + V_29 ) ;
F_2 ( 0 , V_2 -> V_15 + V_31 ) ;
case V_137 :
F_2 ( 0 , V_2 -> V_15 + V_30 ) ;
F_2 ( 0 , V_2 -> V_15 + V_32 ) ;
F_23 ( V_2 , - 1 , 0 , 0 ) ;
F_2 ( 0 , V_2 -> V_15 + V_38 ) ;
F_2 ( 0 , V_2 -> V_15 + V_37 ) ;
F_2 ( V_9 -> V_14 | 0 , V_2 -> V_15 + V_16 ) ;
F_2 ( 0 , V_2 -> V_15 + V_105 ) ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
F_4 ( 5 ) ;
break;
}
F_4 ( 5 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
const struct V_41 * V_42 = F_15 ( V_2 ) ;
struct V_8 * V_9 ;
int V_144 , V_145 ;
unsigned int V_76 ;
unsigned long V_146 ;
struct V_3 * V_4 ;
int V_147 ;
V_144 = F_47 ( V_2 , V_143 -> V_148 [ 0 ] , V_42 -> V_149 ) ;
if ( V_144 )
return V_144 ;
V_9 = F_48 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_150 ;
if ( ( 1 << V_143 -> V_148 [ 1 ] ) & V_42 -> V_151 ) {
V_144 = F_49 ( V_143 -> V_148 [ 1 ] , F_38 , 0 ,
V_2 -> V_152 , V_2 ) ;
if ( V_144 == 0 )
V_2 -> V_95 = V_143 -> V_148 [ 1 ] ;
}
V_76 = 0 ;
V_9 -> V_76 = V_76 ;
if ( ! V_2 -> V_95 )
goto V_153;
if ( V_42 -> V_154 != 0 ) {
V_76 = V_143 -> V_148 [ 2 ] ;
if ( ( ( 1 << V_76 ) & V_42 -> V_154 ) == 0 ) {
F_50 ( V_2 -> V_22 ,
L_4 ) ;
return - V_72 ;
}
V_144 = F_51 ( V_76 , V_2 -> V_152 ) ;
if ( V_144 ) {
F_50 ( V_2 -> V_22 ,
L_5 , V_76 ) ;
return - V_155 ;
}
V_9 -> V_76 = V_76 ;
V_146 = 1 ;
V_9 -> V_109 [ 0 ] = F_52 ( V_156 , V_146 ) ;
if ( ! V_9 -> V_109 [ 0 ] ) {
F_50 ( V_2 -> V_22 ,
L_6 ) ;
return - V_155 ;
}
V_9 -> V_157 [ 0 ] = V_146 ;
V_9 -> V_94 [ 0 ] = F_53 ( ( void * ) V_9 -> V_109 [ 0 ] ) ;
V_9 -> V_90 [ 0 ] = V_158 * ( 1 << V_146 ) ;
V_9 -> V_109 [ 1 ] = F_52 ( V_156 , V_146 ) ;
if ( ! V_9 -> V_109 [ 1 ] ) {
F_50 ( V_2 -> V_22 ,
L_6 ) ;
return - V_155 ;
}
V_9 -> V_157 [ 1 ] = V_146 ;
V_9 -> V_94 [ 1 ] = F_53 ( ( void * ) V_9 -> V_109 [ 1 ] ) ;
V_9 -> V_90 [ 1 ] = V_158 * ( 1 << V_146 ) ;
}
V_153:
V_147 = 0 ;
if ( V_42 -> V_159 > 0 )
V_147 ++ ;
if ( V_42 -> V_160 > 0 )
V_147 ++ ;
if ( V_42 -> V_161 > 0 )
V_147 ++ ;
if ( V_42 -> V_162 > 0 )
V_147 ++ ;
V_144 = F_54 ( V_2 , V_147 ) ;
if ( V_144 )
return V_144 ;
V_145 = 0 ;
if ( V_42 -> V_159 > 0 ) {
V_4 = & V_2 -> V_163 [ V_145 ] ;
V_4 -> type = V_164 ;
V_4 -> V_165 = V_166 ;
switch ( V_42 -> V_132 ) {
case V_137 :
if ( V_143 -> V_148 [ 2 ] == 1 ) {
V_4 -> V_167 = V_42 -> V_168 ;
V_4 -> V_165 |= V_169 ;
V_9 -> V_124 = 1 ;
} else {
V_4 -> V_167 = V_42 -> V_159 ;
V_4 -> V_165 |= V_170 ;
}
break;
case V_135 :
case V_136 :
if ( V_143 -> V_148 [ 4 ] == 1 ) {
V_4 -> V_167 = V_42 -> V_168 ;
V_4 -> V_165 |= V_169 ;
V_9 -> V_124 = 1 ;
} else {
V_4 -> V_167 = V_42 -> V_159 ;
V_4 -> V_165 |= V_170 ;
}
break;
default:
V_4 -> V_167 = V_42 -> V_159 ;
V_4 -> V_165 |= V_170 ;
break;
}
V_4 -> V_171 = V_42 -> V_172 ;
V_4 -> V_173 = V_42 -> V_174 ;
if ( V_42 -> V_132 == V_136 )
V_4 -> V_175 = F_7 ;
else
V_4 -> V_175 = F_1 ;
V_9 -> V_123 = V_42 -> V_176 ;
if ( V_2 -> V_95 ) {
V_2 -> V_98 = V_4 ;
V_4 -> V_165 |= V_177 ;
V_4 -> V_178 = V_65 ;
V_4 -> V_179 = F_14 ;
V_4 -> V_180 = F_22 ;
V_4 -> V_181 = F_40 ;
V_4 -> V_182 = F_32 ;
}
switch ( V_42 -> V_132 ) {
case V_133 :
if ( V_143 -> V_148 [ 4 ] == 1 )
V_4 -> V_173 = & V_183 ;
break;
case V_134 :
switch ( V_143 -> V_148 [ 4 ] ) {
case 0 :
V_4 -> V_173 = & V_184 ;
break;
case 1 :
V_4 -> V_173 = & V_185 ;
break;
case 2 :
V_4 -> V_173 = & V_186 ;
break;
case 3 :
V_4 -> V_173 = & V_187 ;
break;
case 4 :
V_4 -> V_173 = & V_188 ;
break;
case 5 :
V_4 -> V_173 = & V_189 ;
break;
default:
V_4 -> V_173 = & V_184 ;
break;
}
break;
break;
case V_138 :
if ( V_143 -> V_148 [ 1 ] == 1 )
V_4 -> V_173 = & V_190 ;
break;
case V_140 :
switch ( V_143 -> V_148 [ 1 ] ) {
case 0 :
V_4 -> V_173 = & V_191 ;
break;
case 1 :
V_4 -> V_173 = & V_192 ;
break;
case 2 :
V_4 -> V_173 = & V_193 ;
V_9 -> V_120 = 1 ;
break;
case 3 :
V_4 -> V_173 = & V_194 ;
V_9 -> V_120 = 1 ;
break;
default:
V_4 -> V_173 = & V_191 ;
break;
}
break;
case V_141 :
switch ( V_143 -> V_148 [ 1 ] ) {
case 0 :
V_4 -> V_173 = & V_195 ;
break;
case 1 :
V_4 -> V_173 = & V_196 ;
break;
case 2 :
V_4 -> V_173 = & V_197 ;
V_9 -> V_120 = 1 ;
break;
case 3 :
V_4 -> V_173 = & V_198 ;
V_9 -> V_120 = 1 ;
break;
default:
V_4 -> V_173 = & V_195 ;
break;
}
break;
}
V_145 ++ ;
}
if ( V_42 -> V_160 > 0 ) {
V_4 = & V_2 -> V_163 [ V_145 ] ;
V_4 -> type = V_199 ;
V_4 -> V_165 = V_200 | V_170 ;
V_4 -> V_167 = V_42 -> V_160 ;
V_4 -> V_171 = 0xfff ;
V_4 -> V_173 = V_42 -> V_201 ;
V_4 -> V_175 = F_10 ;
V_4 -> V_202 = F_8 ;
switch ( V_42 -> V_132 ) {
case V_137 :
if ( V_143 -> V_148 [ 3 ] == 1 )
V_4 -> V_173 = & V_203 ;
break;
case V_134 :
case V_135 :
case V_133 :
case V_136 :
if ( V_143 -> V_148 [ 5 ] == 1 )
V_4 -> V_173 = & V_203 ;
if ( V_143 -> V_148 [ 5 ] == 2 )
V_4 -> V_173 = & V_204 ;
break;
}
V_145 ++ ;
}
if ( V_42 -> V_161 > 0 ) {
V_4 = & V_2 -> V_163 [ V_145 ] ;
V_4 -> type = V_205 ;
V_4 -> V_165 = V_166 ;
V_4 -> V_167 = V_42 -> V_161 ;
V_4 -> V_171 = 1 ;
V_4 -> V_173 = & V_206 ;
V_4 -> V_207 = F_11 ;
V_145 ++ ;
}
if ( V_42 -> V_162 > 0 ) {
V_4 = & V_2 -> V_163 [ V_145 ] ;
V_4 -> type = V_208 ;
V_4 -> V_165 = V_200 ;
V_4 -> V_167 = V_42 -> V_162 ;
V_4 -> V_171 = 1 ;
V_4 -> V_173 = & V_206 ;
V_4 -> V_207 = F_12 ;
V_145 ++ ;
}
switch ( V_42 -> V_132 ) {
case V_136 :
V_9 -> V_101 = 1 ;
case V_133 :
case V_134 :
case V_135 :
V_9 -> V_127 = 1 ;
if ( V_143 -> V_148 [ 3 ] > 0 )
V_9 -> V_52 = 1 ;
break;
case V_137 :
V_9 -> V_127 = 1 ;
V_9 -> V_14 = ( V_2 -> V_95 << 4 ) & 0xf0 ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
V_9 -> V_127 = 5 ;
break;
}
V_9 -> V_209 = 1 ;
F_45 ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 ) {
if ( V_9 -> V_109 [ 0 ] )
F_56 ( V_9 -> V_109 [ 0 ] , V_9 -> V_157 [ 0 ] ) ;
if ( V_9 -> V_109 [ 1 ] )
F_56 ( V_9 -> V_109 [ 1 ] , V_9 -> V_157 [ 1 ] ) ;
if ( V_9 -> V_76 )
F_57 ( V_9 -> V_76 ) ;
}
F_58 ( V_2 ) ;
}
