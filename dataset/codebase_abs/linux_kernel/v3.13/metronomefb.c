static T_1 F_1 ( int V_1 , int V_2 , T_1 * V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = V_1 ; V_5 < V_2 ; V_5 ++ )
V_4 += V_3 [ V_5 ] ;
return V_4 ;
}
static T_2 F_2 ( T_2 * V_1 , int V_6 )
{
T_2 V_4 = 0 ;
while ( V_6 -- )
V_4 += * V_1 ++ ;
return V_4 ;
}
static int F_3 ( T_1 * V_3 , T_3 V_7 , int V_8 , int V_9 ,
struct V_10 * V_11 )
{
int V_12 ;
int V_13 ;
int V_14 = 0 ;
int V_5 ;
unsigned char V_15 ;
T_1 V_16 ;
int V_17 ;
int V_18 , V_19 ;
int V_20 = 0 ;
struct V_21 * V_22 ;
T_1 * V_23 = V_11 -> V_24 ;
struct V_25 * V_26 = V_11 -> V_27 -> V_26 ;
if ( V_28 )
V_29 [ V_11 -> V_30 ] . V_31 = V_28 ;
if ( V_7 != V_29 [ V_11 -> V_30 ] . V_31 ) {
F_4 ( V_26 , L_1 , V_7 ,
V_29 [ V_11 -> V_30 ] . V_31 ) ;
return - V_32 ;
}
V_22 = (struct V_21 * ) V_3 ;
if ( V_22 -> V_33 != 1 ) {
F_4 ( V_26 , L_2 , V_22 -> V_33 ) ;
return - V_32 ;
}
if ( V_22 -> V_34 != 0 ) {
F_4 ( V_26 , L_3 , V_22 -> V_34 ) ;
return - V_32 ;
}
V_16 = F_1 ( 32 , 47 , V_3 ) ;
if ( V_16 != V_22 -> V_35 ) {
F_4 ( V_26 , L_4 , V_16 ,
V_22 -> V_35 ) ;
return - V_32 ;
}
V_22 -> V_36 += 1 ;
V_22 -> V_37 += 1 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
if ( * ( V_22 -> V_38 + V_5 ) != 0 ) {
F_4 ( V_26 , L_5 ) ;
return - V_32 ;
}
}
if ( ( sizeof( * V_22 ) + V_22 -> V_37 ) > V_7 )
return - V_32 ;
for ( V_5 = sizeof( * V_22 ) ; V_5 <= sizeof( * V_22 ) + V_22 -> V_37 ; V_5 ++ ) {
if ( V_3 [ V_5 ] > V_9 ) {
V_14 = V_5 - sizeof( * V_22 ) - 1 ;
break;
}
}
V_17 = sizeof( * V_22 ) + V_22 -> V_37 + 1 ;
if ( V_17 > V_7 )
return - V_32 ;
V_16 = F_1 ( sizeof( * V_22 ) , V_17 , V_3 ) ;
if ( V_16 != V_3 [ V_17 ] ) {
F_4 ( V_26 , L_6
L_7 , V_16 , V_3 [ V_17 ] ) ;
return - V_32 ;
}
V_13 = F_5 ( V_22 -> V_13 ) & 0x00FFFFFF ;
V_17 = V_13 + V_8 * 4 + 3 ;
if ( V_17 > V_7 )
return - V_32 ;
V_16 = F_1 ( V_17 - 3 , V_17 , V_3 ) ;
if ( V_16 != V_3 [ V_17 ] ) {
F_4 ( V_26 , L_8
L_7 , V_16 , V_3 [ V_17 ] ) ;
return - V_32 ;
}
V_12 = F_5 ( V_3 + V_13 + V_8 * 4 ) & 0x00FFFFFF ;
V_17 = V_12 + V_14 * 4 + 3 ;
if ( V_17 > V_7 )
return - V_32 ;
V_16 = F_1 ( V_17 - 3 , V_17 , V_3 ) ;
if ( V_16 != V_3 [ V_17 ] ) {
F_4 ( V_26 , L_9
L_7 , V_16 , V_3 [ V_17 ] ) ;
return - V_32 ;
}
V_18 = F_5 ( V_3 + V_12 + V_14 * 4 ) & 0x00FFFFFF ;
V_19 = V_18 ;
if ( V_18 > V_7 )
return - V_32 ;
while ( V_18 < V_7 ) {
unsigned char V_39 ;
V_15 = V_3 [ V_18 ++ ] ;
if ( V_15 == V_22 -> V_40 ) {
while ( ( ( V_15 = V_3 [ V_18 ++ ] ) != V_22 -> V_40 ) &&
V_18 < V_7 )
V_23 [ V_20 ++ ] = V_15 ;
continue;
}
if ( V_15 == V_22 -> V_41 )
break;
V_39 = V_3 [ V_18 ++ ] ;
for ( V_5 = 0 ; V_5 <= V_39 ; V_5 ++ )
V_23 [ V_20 ++ ] = V_15 ;
}
V_17 = V_18 ;
if ( V_17 > V_7 )
return - V_32 ;
V_16 = F_1 ( V_19 , V_17 , V_3 ) ;
if ( V_16 != V_3 [ V_17 ] ) {
F_4 ( V_26 , L_10
L_7 , V_16 , V_3 [ V_17 ] ) ;
return - V_32 ;
}
V_11 -> V_42 = ( V_20 / 64 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
int V_5 ;
T_2 V_43 ;
T_2 V_44 ;
static T_1 V_45 ;
if ( V_11 -> V_46 -> V_44 == 0xCC40 )
V_44 = V_43 = 0xCC41 ;
else
V_44 = V_43 = 0xCC40 ;
V_5 = 0 ;
V_11 -> V_46 -> args [ V_5 ] = 1 << 3
| ( ( V_45 ++ % 4 ) & 0x0F ) << 4
| ( V_11 -> V_42 - 1 ) << 8 ;
V_43 += V_11 -> V_46 -> args [ V_5 ++ ] ;
memset ( ( T_1 * ) ( V_11 -> V_46 -> args + V_5 ) , 0 , ( 32 - V_5 ) * 2 ) ;
V_11 -> V_46 -> V_47 = V_43 ;
V_11 -> V_46 -> V_44 = V_44 ;
return V_11 -> V_48 -> V_49 ( V_11 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
int V_5 ;
T_2 V_43 ;
V_11 -> V_46 -> V_44 = 0x1234 ;
V_43 = V_11 -> V_46 -> V_44 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_11 -> V_46 -> args [ V_5 ] = 1024 ;
V_43 += V_11 -> V_46 -> args [ V_5 ] ;
}
memset ( ( T_1 * ) ( V_11 -> V_46 -> args + V_5 ) , 0 , ( 32 - V_5 ) * 2 ) ;
V_11 -> V_46 -> V_47 = V_43 ;
F_8 ( 1 ) ;
V_11 -> V_48 -> V_50 ( V_11 , 1 ) ;
F_8 ( 1 ) ;
V_11 -> V_48 -> V_51 ( V_11 , 1 ) ;
return V_11 -> V_48 -> V_52 ( V_11 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
memcpy ( V_11 -> V_46 -> args , V_29 [ V_11 -> V_30 ] . V_53 ,
sizeof( V_29 [ V_11 -> V_30 ] . V_53 ) ) ;
memset ( ( T_1 * ) ( V_11 -> V_46 -> args + 4 ) , 0 , ( 32 - 4 ) * 2 ) ;
V_11 -> V_46 -> V_47 = 0xCC10 ;
V_11 -> V_46 -> V_47 += F_2 ( V_11 -> V_46 -> args , 4 ) ;
V_11 -> V_46 -> V_44 = 0xCC10 ;
return V_11 -> V_48 -> V_52 ( V_11 ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
int V_5 ;
T_2 V_43 ;
V_43 = 0xCC20 ;
V_5 = 0 ;
V_11 -> V_46 -> args [ V_5 ] = 0 ;
V_43 += V_11 -> V_46 -> args [ V_5 ++ ] ;
memset ( ( T_1 * ) ( V_11 -> V_46 -> args + V_5 ) , 0 , ( 32 - V_5 ) * 2 ) ;
V_11 -> V_46 -> V_47 = V_43 ;
V_11 -> V_46 -> V_44 = 0xCC20 ;
return V_11 -> V_48 -> V_52 ( V_11 ) ;
}
static int F_11 ( struct V_10 * V_11 )
{
int V_54 ;
V_54 = V_11 -> V_48 -> V_55 ( V_11 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_7 ( V_11 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_9 ( V_11 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_10 ( V_11 ) ;
return V_54 ;
}
static void F_12 ( struct V_10 * V_11 )
{
int V_56 ;
T_2 V_16 ;
unsigned char * V_57 = ( unsigned char V_58 * ) V_11 -> V_27 -> V_59 ;
V_56 = V_11 -> V_27 -> V_60 . V_61 ;
memcpy ( V_11 -> V_62 , V_57 , V_56 ) ;
V_16 = F_2 ( ( T_2 * ) V_11 -> V_62 , V_56 / 2 ) ;
* ( ( T_2 * ) ( V_11 -> V_62 ) + V_56 / 2 ) = V_16 ;
F_6 ( V_11 ) ;
}
static T_2 F_13 ( struct V_10 * V_11 , int V_63 )
{
int V_5 ;
T_2 V_47 = 0 ;
T_2 * V_57 = ( T_2 V_58 * ) ( V_11 -> V_27 -> V_59 + V_63 ) ;
T_2 * V_64 = ( T_2 * ) ( V_11 -> V_62 + V_63 ) ;
for ( V_5 = 0 ; V_5 < V_65 / 2 ; V_5 ++ ) {
* ( V_64 + V_5 ) = ( V_57 [ V_5 ] << 5 ) & 0xE0E0 ;
V_47 += * ( V_64 + V_5 ) ;
}
return V_47 ;
}
static void F_14 ( struct V_66 * V_27 ,
struct V_67 * V_68 )
{
T_2 V_16 ;
struct V_69 * V_70 ;
struct V_71 * V_72 = V_27 -> V_72 ;
struct V_10 * V_11 = V_27 -> V_11 ;
F_15 (cur, &fbdefio->pagelist, lru) {
V_16 = F_13 ( V_11 ,
( V_70 -> V_63 << V_73 ) ) ;
V_11 -> V_74 -= V_11 -> V_75 [ V_70 -> V_63 ] ;
V_11 -> V_75 [ V_70 -> V_63 ] = V_16 ;
V_11 -> V_74 += V_16 ;
}
F_6 ( V_11 ) ;
}
static void F_16 ( struct V_66 * V_27 ,
const struct V_76 * V_77 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
F_17 ( V_27 , V_77 ) ;
F_12 ( V_11 ) ;
}
static void F_18 ( struct V_66 * V_27 ,
const struct V_78 * V_79 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
F_19 ( V_27 , V_79 ) ;
F_12 ( V_11 ) ;
}
static void F_20 ( struct V_66 * V_27 ,
const struct V_80 * V_81 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
F_21 ( V_27 , V_81 ) ;
F_12 ( V_11 ) ;
}
static T_4 F_22 ( struct V_66 * V_27 , const char T_5 * V_57 ,
T_3 V_82 , T_6 * V_83 )
{
struct V_10 * V_11 = V_27 -> V_11 ;
unsigned long V_84 = * V_83 ;
void * V_85 ;
int V_86 = 0 ;
unsigned long V_87 ;
if ( V_27 -> V_88 != V_89 )
return - V_90 ;
V_87 = V_27 -> V_60 . V_61 ;
if ( V_84 > V_87 )
return - V_91 ;
if ( V_82 > V_87 ) {
V_86 = - V_91 ;
V_82 = V_87 ;
}
if ( V_82 + V_84 > V_87 ) {
if ( ! V_86 )
V_86 = - V_92 ;
V_82 = V_87 - V_84 ;
}
V_85 = ( void V_58 * ) ( V_27 -> V_59 + V_84 ) ;
if ( F_23 ( V_85 , V_57 , V_82 ) )
V_86 = - V_93 ;
if ( ! V_86 )
* V_83 += V_82 ;
F_12 ( V_11 ) ;
return ( V_86 ) ? V_86 : V_82 ;
}
static int F_24 ( struct V_94 * V_26 )
{
struct V_66 * V_27 ;
struct V_95 * V_48 ;
int V_96 = - V_97 ;
int V_98 ;
unsigned char * V_99 ;
struct V_10 * V_11 ;
const struct V_100 * V_101 ;
int V_5 ;
int V_102 ;
int V_103 , V_104 ;
int V_105 ;
V_48 = V_26 -> V_26 . V_106 ;
if ( ! V_48 )
return - V_32 ;
if ( ! F_25 ( V_48 -> V_107 ) )
return - V_108 ;
V_27 = F_26 ( sizeof( struct V_10 ) , & V_26 -> V_26 ) ;
if ( ! V_27 )
goto V_86;
V_102 = V_48 -> V_109 () ;
switch ( V_102 ) {
case 6 :
V_105 = 0 ;
break;
case 8 :
V_105 = 1 ;
break;
case 97 :
V_105 = 2 ;
break;
default:
F_4 ( & V_26 -> V_26 , L_11 ) ;
V_105 = 0 ;
break;
}
V_103 = V_29 [ V_105 ] . V_103 ;
V_104 = V_29 [ V_105 ] . V_104 ;
V_98 = V_65 + ( V_103 * V_104 ) ;
V_99 = F_27 ( V_98 ) ;
if ( ! V_99 )
goto V_110;
V_27 -> V_59 = ( char V_58 V_111 * ) V_99 ;
V_27 -> V_112 = & V_113 ;
V_114 . V_115 = V_103 ;
V_116 . V_117 = V_103 ;
V_116 . V_118 = V_104 ;
V_116 . V_119 = V_103 ;
V_116 . V_120 = V_104 ;
V_27 -> V_121 = V_116 ;
V_27 -> V_60 = V_114 ;
V_27 -> V_60 . V_61 = V_98 ;
V_11 = V_27 -> V_11 ;
V_11 -> V_27 = V_27 ;
V_11 -> V_48 = V_48 ;
V_11 -> V_30 = V_105 ;
F_28 ( & V_11 -> V_122 ) ;
V_11 -> V_75 = F_29 ( V_98 / V_65 ) ;
if ( ! V_11 -> V_75 )
goto V_123;
V_96 = V_48 -> V_124 ( V_11 ) ;
if ( V_96 ) {
F_4 ( & V_26 -> V_26 , L_12 ) ;
goto V_125;
}
if ( ( ! V_11 -> V_24 ) || ( ! V_11 -> V_62 ) ||
( ! V_11 -> V_126 ) ) {
F_4 ( & V_26 -> V_26 , L_13 ) ;
V_96 = - V_32 ;
goto V_125;
}
V_27 -> V_60 . V_127 = V_11 -> V_126 ;
V_96 = F_30 ( & V_101 , L_14 , & V_26 -> V_26 ) ;
if ( V_96 < 0 ) {
F_4 ( & V_26 -> V_26 , L_15 ) ;
goto V_125;
}
V_96 = F_3 ( ( T_1 * ) V_101 -> V_128 , V_101 -> V_7 , 3 , 31 ,
V_11 ) ;
F_31 ( V_101 ) ;
if ( V_96 < 0 ) {
F_4 ( & V_26 -> V_26 , L_16 ) ;
goto V_125;
}
V_96 = V_48 -> V_129 ( V_27 ) ;
if ( V_96 )
goto V_125;
V_96 = F_11 ( V_11 ) ;
if ( V_96 < 0 )
goto V_130;
V_27 -> V_131 = V_132 | V_133 ;
V_27 -> V_72 = & V_134 ;
F_32 ( V_27 ) ;
V_96 = F_33 ( & V_27 -> V_135 , 8 , 0 ) ;
if ( V_96 < 0 ) {
F_4 ( & V_26 -> V_26 , L_17 ) ;
goto V_130;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
V_27 -> V_135 . V_136 [ V_5 ] = ( ( ( 2 * V_5 ) + 1 ) * ( 0xFFFF ) ) / 16 ;
memcpy ( V_27 -> V_135 . V_137 , V_27 -> V_135 . V_136 , sizeof( T_2 ) * 8 ) ;
memcpy ( V_27 -> V_135 . V_138 , V_27 -> V_135 . V_136 , sizeof( T_2 ) * 8 ) ;
V_96 = F_34 ( V_27 ) ;
if ( V_96 < 0 )
goto V_139;
F_35 ( V_26 , V_27 ) ;
F_36 ( & V_26 -> V_26 ,
L_18
L_19 , V_27 -> V_140 , V_98 >> 10 ) ;
return 0 ;
V_139:
F_37 ( & V_27 -> V_135 ) ;
V_130:
V_48 -> V_141 ( V_11 ) ;
V_125:
F_38 ( V_11 -> V_75 ) ;
V_123:
F_38 ( V_99 ) ;
V_110:
F_39 ( V_27 ) ;
V_86:
F_40 ( V_48 -> V_107 ) ;
return V_96 ;
}
static int F_41 ( struct V_94 * V_26 )
{
struct V_66 * V_27 = F_42 ( V_26 ) ;
if ( V_27 ) {
struct V_10 * V_11 = V_27 -> V_11 ;
F_43 ( V_27 ) ;
F_44 ( V_27 ) ;
F_37 ( & V_27 -> V_135 ) ;
V_11 -> V_48 -> V_141 ( V_11 ) ;
F_38 ( V_11 -> V_75 ) ;
F_38 ( ( void V_58 * ) V_27 -> V_59 ) ;
F_40 ( V_11 -> V_48 -> V_107 ) ;
F_36 ( & V_26 -> V_26 , L_20 ) ;
F_39 ( V_27 ) ;
}
return 0 ;
}
