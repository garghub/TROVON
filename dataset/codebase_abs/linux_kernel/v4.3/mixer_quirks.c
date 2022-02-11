static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
int V_6 ,
unsigned int V_7 ,
const char * V_8 ,
T_1 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
F_3 ( & V_11 -> V_16 , V_2 , V_3 ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_17 = 1 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 1 ;
V_11 -> V_20 = 0 ;
V_11 -> V_21 = 0 ;
V_11 -> V_22 = 0 ;
V_13 = F_4 ( V_23 , V_11 ) ;
if ( ! V_13 ) {
F_5 ( V_11 ) ;
return - V_15 ;
}
snprintf ( V_13 -> V_24 . V_8 , sizeof( V_13 -> V_24 . V_8 ) , V_8 ) ;
V_13 -> V_25 = V_26 ;
if ( V_9 ) {
V_13 -> V_27 . V_28 = V_9 ;
V_13 -> V_29 [ 0 ] . V_30 |=
V_31 |
V_32 ;
}
return F_6 ( & V_11 -> V_16 , V_13 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
int V_6 ,
const char * V_8 ,
T_1 * V_9 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , 0 , V_8 , V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
int V_35 ;
while ( V_34 -> V_8 != NULL ) {
V_35 = F_7 ( V_2 , V_34 -> V_3 , V_34 -> V_4 ,
V_34 -> V_5 , V_34 -> V_6 , V_34 -> V_8 , V_34 -> V_9 ) ;
if ( V_35 < 0 )
return V_35 ;
V_34 ++ ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_24 ,
T_2 V_36 ,
const struct V_37 * V_38 ,
struct V_39 * * V_40 )
{
struct V_39 * V_41 ;
struct V_12 * V_13 ;
V_41 = F_2 ( sizeof( * V_41 ) , V_14 ) ;
if ( ! V_41 )
return - V_15 ;
if ( V_40 )
* V_40 = V_41 ;
V_41 -> V_2 = V_2 ;
V_41 -> V_24 = V_24 ;
V_41 -> V_36 = V_36 ;
V_13 = F_4 ( V_38 , V_41 ) ;
if ( ! V_13 ) {
F_5 ( V_41 ) ;
return - V_15 ;
}
V_13 -> V_25 = V_26 ;
return F_6 ( V_41 , V_13 ) ;
}
static void F_10 ( struct V_42 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
const struct V_44 * V_45 = V_2 -> V_46 ;
T_3 V_47 ;
if ( V_42 -> V_48 < 0 || V_42 -> V_49 < V_45 -> V_50 )
return;
V_47 = V_2 -> V_51 [ V_45 -> V_52 ] ;
if ( V_45 -> V_53 == 2 )
V_47 |= V_2 -> V_51 [ V_45 -> V_52 + 1 ] << 8 ;
if ( V_47 == V_45 -> V_54 )
F_11 ( V_2 , V_45 -> V_55 ) ;
V_2 -> V_56 = V_47 ;
F_12 () ;
F_13 ( & V_2 -> V_57 ) ;
}
static long F_14 ( struct V_58 * V_59 , char T_4 * V_60 ,
long V_61 , T_5 * V_52 )
{
struct V_1 * V_2 = V_59 -> V_62 ;
int V_35 ;
T_3 V_56 ;
if ( V_61 != 1 && V_61 != 4 )
return - V_63 ;
V_35 = F_15 ( V_2 -> V_57 ,
( V_56 = F_16 ( & V_2 -> V_56 , 0 ) ) != 0 ) ;
if ( V_35 == 0 ) {
if ( V_61 == 1 )
V_35 = F_17 ( V_56 , V_60 ) ;
else
V_35 = F_17 ( V_56 , ( T_3 T_4 * ) V_60 ) ;
}
return V_35 < 0 ? V_35 : V_61 ;
}
static unsigned int F_18 ( struct V_58 * V_59 , struct V_64 * V_64 ,
T_6 * V_65 )
{
struct V_1 * V_2 = V_59 -> V_62 ;
F_19 ( V_64 , & V_2 -> V_57 , V_65 ) ;
return V_2 -> V_56 ? V_66 | V_67 : 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_58 * V_68 ;
int V_35 , V_69 , V_70 ;
for ( V_70 = 0 ; V_70 < F_21 ( V_71 ) ; ++ V_70 )
if ( V_71 [ V_70 ] . V_72 == V_2 -> V_73 -> V_72 )
break;
if ( V_70 >= F_21 ( V_71 ) )
return 0 ;
V_2 -> V_46 = & V_71 [ V_70 ] ;
V_69 = V_2 -> V_46 -> V_74 ;
F_22 ( & V_2 -> V_57 ) ;
V_35 = F_23 ( V_2 -> V_73 -> V_75 , L_1 , 0 , & V_68 ) ;
if ( V_35 < 0 )
return V_35 ;
snprintf ( V_68 -> V_8 , sizeof( V_68 -> V_8 ) ,
L_2 , V_2 -> V_73 -> V_75 -> V_76 ) ;
V_68 -> V_77 = V_78 ;
V_68 -> V_62 = V_2 ;
V_68 -> V_79 . V_80 = F_14 ;
V_68 -> V_79 . V_81 = F_18 ;
V_68 -> V_82 = 1 ;
V_2 -> V_83 = F_24 ( 0 , V_14 ) ;
if ( ! V_2 -> V_83 )
return - V_15 ;
V_2 -> V_84 = F_25 ( sizeof( * V_2 -> V_84 ) , V_14 ) ;
if ( ! V_2 -> V_84 ) {
F_26 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
return - V_15 ;
}
V_2 -> V_84 -> V_85 =
V_86 | V_87 | V_88 ;
V_2 -> V_84 -> V_89 = V_90 ;
V_2 -> V_84 -> V_91 = F_27 ( 0 ) ;
V_2 -> V_84 -> V_92 = F_27 ( 0 ) ;
V_2 -> V_84 -> V_93 = F_27 ( V_69 ) ;
F_28 ( V_2 -> V_83 , V_2 -> V_73 -> V_94 ,
F_29 ( V_2 -> V_73 -> V_94 , 0 ) ,
( V_95 * ) V_2 -> V_84 , V_2 -> V_51 , V_69 ,
F_10 , V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_12 * V_96 , struct V_97 * V_98 )
{
V_98 -> V_99 . integer . V_99 [ 0 ] = V_96 -> V_100 >> 8 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
int V_99 , int V_101 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
int V_35 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_73 -> V_72 == F_33 ( 0x041e , 0x3042 ) )
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) , 0x24 ,
V_103 | V_104 | V_105 ,
! V_99 , 0 , NULL , 0 ) ;
if ( V_73 -> V_72 == F_33 ( 0x041e , 0x30df ) )
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) , 0x24 ,
V_103 | V_104 | V_105 ,
! V_99 , 0 , NULL , 0 ) ;
else
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) , 0x24 ,
V_103 | V_104 | V_105 ,
V_99 , V_101 + 2 , NULL , 0 ) ;
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_37 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
int V_101 = V_96 -> V_100 & 0xff ;
int V_99 = V_98 -> V_99 . integer . V_99 [ 0 ] ;
int V_106 = V_96 -> V_100 >> 8 ;
int V_35 ;
if ( V_99 > 1 )
return - V_63 ;
if ( V_99 == V_106 )
return 0 ;
V_96 -> V_100 = ( V_99 << 8 ) | V_101 ;
V_35 = F_31 ( V_2 , V_99 , V_101 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_39 ( struct V_39 * V_41 )
{
int V_107 = V_41 -> V_13 -> V_100 ;
return F_31 ( V_41 -> V_2 , V_107 >> 8 ,
V_107 & 0xff ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_70 , V_35 ;
for ( V_70 = 0 ; V_70 < F_21 ( V_108 ) ; ++ V_70 ) {
struct V_37 V_38 ;
if ( ( V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3042 ) ) && V_70 == 0 )
continue;
if ( ( V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x30df ) ) && V_70 == 0 )
continue;
if ( V_70 > 1 &&
( V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3040 ) ||
V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3042 ) ||
V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x30df ) ||
V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3048 ) ) )
break;
V_38 = V_109 ;
V_38 . V_8 = V_108 [ V_70 ] ;
V_38 . V_100 = ( 1 << 8 ) | V_70 ;
V_35 = F_9 ( V_2 , 0 ,
F_39 ,
& V_38 , NULL ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static void F_41 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
static const struct V_114 {
int V_3 ;
const char * V_8 ;
} V_115 [] = {
{ 4 , L_3 } ,
{ 7 , L_4 } ,
{ 19 , L_5 } ,
{ 20 , L_6 } ,
{ - 1 , NULL }
} , V_116 [] = {
{ 4 , L_4 } ,
{ 3 , L_6 } ,
{ 0 , L_7 } ,
{ - 1 , NULL }
} ;
const struct V_114 * V_117 ;
struct V_1 * V_2 = V_111 -> V_62 ;
int V_70 , V_35 ;
V_95 V_60 [ 3 ] ;
F_42 ( V_113 , L_8 , V_2 -> V_73 -> V_75 -> V_76 ) ;
if ( V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3020 ) )
V_117 = V_115 ;
else if ( V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3040 ) ||
V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3048 ) )
V_117 = V_116 ;
else
return;
for ( V_70 = 0 ; V_117 [ V_70 ] . V_8 ; ++ V_70 ) {
F_42 ( V_113 , L_9 , V_117 [ V_70 ] . V_8 ) ;
V_35 = F_32 ( V_2 -> V_73 ) ;
if ( V_35 < 0 )
return;
V_35 = F_34 ( V_2 -> V_73 -> V_94 ,
F_29 ( V_2 -> V_73 -> V_94 , 0 ) ,
V_90 , V_86 | V_87 |
V_88 , 0 ,
V_117 [ V_70 ] . V_3 << 8 , V_60 , 3 ) ;
F_36 ( V_2 -> V_73 ) ;
if ( V_35 == 3 && ( V_60 [ 0 ] == 3 || V_60 [ 0 ] == 6 ) )
F_42 ( V_113 , L_10 , V_60 [ 1 ] , V_60 [ 2 ] ) ;
else
F_42 ( V_113 , L_11 ) ;
}
}
static int F_43 ( struct V_12 * V_96 ,
struct V_118 * V_119 )
{
static const char * const V_120 [ 2 ] = { L_12 , L_13 } ;
return F_44 ( V_119 , 1 , F_21 ( V_120 ) , V_120 ) ;
}
static int F_45 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . V_121 . V_122 [ 0 ] = V_96 -> V_100 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
int V_99 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
int V_35 ;
unsigned char V_60 [ 2 ] ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_60 [ 0 ] = 0x01 ;
V_60 [ 1 ] = V_99 ? 0x02 : 0x01 ;
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) , V_123 ,
V_88 | V_87 | V_103 ,
0x0400 , 0x0e00 , V_60 , 2 ) ;
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_47 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
unsigned int V_99 = V_98 -> V_99 . V_121 . V_122 [ 0 ] ;
int V_35 ;
if ( V_99 > 1 )
return - V_63 ;
if ( V_99 == V_96 -> V_100 )
return 0 ;
V_96 -> V_100 = V_99 ;
V_35 = F_46 ( V_2 , V_99 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_48 ( struct V_39 * V_41 )
{
return F_46 ( V_41 -> V_2 ,
V_41 -> V_13 -> V_100 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , 0 ,
F_48 ,
& V_124 , NULL ) ;
}
static int F_50 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . integer . V_99 [ 0 ] = ! ! ( V_96 -> V_100 & 0x02 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned char V_48 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
int V_35 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) , 0x08 ,
V_103 | V_104 | V_105 ,
50 , 0 , & V_48 , 1 ) ;
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_52 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
V_95 V_125 , V_126 ;
int V_35 ;
V_125 = V_96 -> V_100 ;
if ( V_98 -> V_99 . integer . V_99 [ 0 ] )
V_126 = V_125 | 0x02 ;
else
V_126 = V_125 & ~ 0x02 ;
if ( V_126 == V_125 )
return 0 ;
V_96 -> V_100 = V_126 ;
V_35 = F_51 ( V_41 -> V_2 , V_126 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_53 ( struct V_39 * V_41 )
{
return F_51 ( V_41 -> V_2 ,
V_41 -> V_13 -> V_100 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , 0 ,
F_53 ,
& V_127 , NULL ) ;
}
static int F_55 ( struct V_12 * V_13 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . V_121 . V_122 [ 0 ] = V_13 -> V_100 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , int V_128 )
{
struct V_102 * V_73 = V_2 -> V_73 ;
int V_35 ;
unsigned char V_129 [ 3 ] ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_34 ( V_73 -> V_94 ,
F_29 ( V_73 -> V_94 , 0 ) , 0x81 ,
V_86 |
V_87 |
V_88 , 0x00 , 0x500 , V_129 , 1 ) ;
if ( V_35 < 0 )
goto V_35;
V_35 = F_34 ( V_73 -> V_94 ,
F_29 ( V_73 -> V_94 , 0 ) , 0x81 ,
V_86 |
V_87 |
V_130 , 0x100 , 0x81 , V_129 , 3 ) ;
if ( V_35 < 0 )
goto V_35;
if ( V_128 == 0 ) {
V_129 [ 0 ] = 0x80 ;
V_129 [ 1 ] = 0xbb ;
V_129 [ 2 ] = 0x00 ;
} else {
V_129 [ 0 ] = V_129 [ 1 ] = V_129 [ 2 ] = 0x00 ;
}
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) , 0x1 ,
V_87 |
V_130 , 0x100 , 0x81 , V_129 , 3 ) ;
if ( V_35 < 0 )
goto V_35;
V_35 = F_34 ( V_73 -> V_94 ,
F_29 ( V_73 -> V_94 , 0 ) , 0x81 ,
V_86 |
V_87 |
V_130 , 0x100 , 0x81 , V_129 , 3 ) ;
if ( V_35 < 0 )
goto V_35;
V_35 = F_34 ( V_73 -> V_94 ,
F_29 ( V_73 -> V_94 , 0 ) , 0x81 ,
V_86 |
V_87 |
V_130 , 0x100 , 0x2 , V_129 , 3 ) ;
if ( V_35 < 0 )
goto V_35;
V_35:
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_57 ( struct V_12 * V_13 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_13 ) ;
struct V_1 * V_2 = V_41 -> V_2 ;
int V_35 ;
bool V_131 , V_132 ;
V_131 = V_13 -> V_100 ;
V_132 = V_98 -> V_99 . V_121 . V_122 [ 0 ] ;
if ( V_131 == V_132 )
return 0 ;
V_13 -> V_100 = V_132 ;
V_35 = F_56 ( V_2 , V_132 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_58 ( struct V_12 * V_96 ,
struct V_118 * V_119 )
{
static const char * const V_120 [ 2 ] = {
L_14 ,
L_15
} ;
return F_44 ( V_119 , 1 , F_21 ( V_120 ) , V_120 ) ;
}
static int F_59 ( struct V_39 * V_41 )
{
return F_56 ( V_41 -> V_2 , V_41 -> V_13 -> V_100 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , 0 ,
F_59 ,
& V_133 , NULL ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_134 * V_94 = V_2 -> V_73 -> V_94 ;
unsigned int V_135 = V_13 -> V_100 ;
V_95 V_99 ;
int V_35 ;
V_35 = F_34 ( V_94 , F_29 ( V_94 , 0 ) ,
( V_135 >> 16 ) & 0xff ,
V_104 | V_136 | V_86 ,
0 , V_135 & 0xffff , & V_99 , 1 ) ;
if ( V_35 < 0 ) {
F_62 ( & V_94 -> V_94 ,
L_16 , V_35 ) ;
return V_35 ;
}
V_13 -> V_100 |= ( V_99 << 24 ) ;
return 0 ;
}
static int F_63 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . integer . V_99 [ 0 ] = V_96 -> V_100 >> 24 ;
return 0 ;
}
static int F_64 ( struct V_39 * V_41 )
{
struct V_102 * V_73 = V_41 -> V_2 -> V_73 ;
unsigned int V_135 = V_41 -> V_13 -> V_100 ;
int V_35 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_65 ( V_73 -> V_94 , F_35 ( V_73 -> V_94 , 0 ) ,
( V_135 >> 16 ) & 0xff ,
V_104 | V_136 | V_103 ,
V_135 >> 24 , V_135 & 0xffff , NULL , 0 , 1000 ) ;
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_66 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
V_95 V_137 = ( V_96 -> V_100 >> 24 ) & 0xff ;
V_95 V_138 = V_98 -> V_99 . integer . V_99 [ 0 ] ;
int V_35 ;
if ( V_137 == V_138 )
return 0 ;
V_96 -> V_100 &= ~ ( 0xff << 24 ) ;
V_96 -> V_100 |= V_138 ;
V_35 = F_64 ( V_41 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_67 ( struct V_1 * V_2 ,
const struct V_37 * V_139 ,
unsigned int V_61 )
{
int V_70 , V_35 = 0 ;
struct V_37 V_140 = {
. V_77 = V_141 ,
. V_30 = V_142 ,
. V_143 = F_63 ,
. V_144 = F_66 ,
. V_145 = V_146 ,
} ;
for ( V_70 = 0 ; V_70 < V_61 ; V_70 ++ ) {
struct V_39 * V_41 ;
V_140 . V_8 = V_139 [ V_70 ] . V_8 ;
V_140 . V_100 = V_139 [ V_70 ] . V_100 ;
V_35 = F_9 ( V_2 , 0 ,
F_64 ,
& V_140 , & V_41 ) ;
if ( V_35 < 0 )
break;
F_61 ( V_2 , V_41 -> V_13 ) ;
}
return V_35 ;
}
static int F_68 ( struct V_12 * V_96 ,
struct V_118 * V_119 )
{
static const char * const V_120 [ 8 ] = {
L_17 , L_18 , L_19 , L_20 ,
L_21 , L_22 , L_23 , L_24
} ;
return F_44 ( V_119 , 1 , F_21 ( V_120 ) , V_120 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_134 * V_94 = V_2 -> V_73 -> V_94 ;
unsigned int V_135 = V_13 -> V_100 ;
int V_35 ;
unsigned char V_99 [ 2 ] ;
V_99 [ 0 ] = 0x00 ;
V_99 [ 1 ] = 0x00 ;
V_35 = F_34 ( V_94 , F_29 ( V_94 , 0 ) , V_147 ,
V_88 | V_87 | V_86 ,
V_135 & 0xff00 ,
F_70 ( V_2 -> V_73 ) | ( ( V_135 & 0xff ) << 8 ) ,
V_99 , 2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_13 -> V_100 |= V_99 [ 0 ] << 24 ;
return 0 ;
}
static int F_71 ( struct V_12 * V_13 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . V_121 . V_122 [ 0 ] = V_13 -> V_100 >> 24 ;
return 0 ;
}
static int F_72 ( struct V_39 * V_41 )
{
struct V_102 * V_73 = V_41 -> V_2 -> V_73 ;
unsigned int V_135 = V_41 -> V_13 -> V_100 ;
unsigned char V_99 [ 2 ] ;
int V_35 ;
V_99 [ 0 ] = V_135 >> 24 ;
V_99 [ 1 ] = 0 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) ,
V_123 ,
V_88 | V_87 | V_103 ,
V_135 & 0xff00 ,
F_70 ( V_73 ) | ( ( V_135 & 0xff ) << 8 ) ,
V_99 , 2 ) ;
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_73 ( struct V_12 * V_13 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_13 ) ;
unsigned int V_135 = V_41 -> V_13 -> V_100 ;
int V_131 , V_35 , V_132 ;
V_131 = V_135 >> 24 ;
V_132 = V_98 -> V_99 . V_121 . V_122 [ 0 ] ;
if ( V_131 == V_132 )
return 0 ;
V_13 -> V_100 &= ~ ( 0xff << 24 ) ;
V_13 -> V_100 |= V_132 << 24 ;
V_35 = F_72 ( V_41 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_74 ( struct V_1 * V_2 ,
int V_148 , int V_149 )
{
static struct V_37 V_140 = {
. V_77 = V_141 ,
. V_8 = L_25 ,
. V_101 = 0 ,
. V_30 = V_142 ,
. V_145 = F_68 ,
. V_143 = F_71 ,
. V_144 = F_73
} ;
struct V_39 * V_41 ;
int V_35 ;
V_35 = F_9 ( V_2 , V_149 ,
F_72 ,
& V_140 , & V_41 ) ;
if ( V_35 < 0 )
return V_35 ;
V_41 -> V_13 -> V_100 = ( V_148 << 8 ) | V_149 ;
F_69 ( V_2 , V_41 -> V_13 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
char V_8 [ 64 ] ;
unsigned int V_4 , V_5 ;
int V_150 , V_151 , V_35 ;
const unsigned int V_24 = 5 ;
const int V_6 = V_152 ;
for ( V_151 = 0 ; V_151 < 8 ; V_151 ++ ) {
V_4 = V_151 + 1 ;
for ( V_150 = 0 ; V_150 < 8 ; V_150 ++ ) {
V_5 = 1 << V_150 ;
snprintf ( V_8 , sizeof( V_8 ) ,
L_26 ,
V_150 + 1 , V_151 + 1 ) ;
V_35 = F_7 ( V_2 , V_24 , V_4 ,
V_5 , V_6 , V_8 ,
& V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
for ( V_150 = 8 ; V_150 < 16 ; V_150 ++ ) {
V_5 = 1 << V_150 ;
snprintf ( V_8 , sizeof( V_8 ) ,
L_27 ,
V_150 - 7 , V_151 + 1 ) ;
V_35 = F_7 ( V_2 , V_24 , V_4 ,
V_5 , V_6 , V_8 ,
& V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
static const char V_8 [] = L_28 ;
const unsigned int V_24 = 6 ;
const int V_6 = V_154 ;
const unsigned int V_4 = 2 ;
const unsigned int V_5 = 0 ;
return F_7 ( V_2 , V_24 , V_4 , V_5 , V_6 ,
V_8 , V_153 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
static const char V_8 [] = L_29 ;
const unsigned int V_24 = 6 ;
const int V_6 = V_152 ;
const unsigned int V_4 = 3 ;
const unsigned int V_5 = 0 ;
return F_7 ( V_2 , V_24 , V_4 , V_5 , V_6 ,
V_8 , V_153 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
static const char V_8 [] = L_30 ;
const unsigned int V_24 = 6 ;
const int V_6 = V_154 ;
const unsigned int V_4 = 4 ;
const unsigned int V_5 = 0 ;
return F_7 ( V_2 , V_24 , V_4 , V_5 , V_6 ,
V_8 , NULL ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
int V_35 , V_155 ;
char V_8 [ 48 ] ;
const unsigned int V_24 = 7 ;
const int V_6 = V_152 ;
const unsigned int V_4 = 7 ;
for ( V_155 = 0 ; V_155 < 4 ; ++ V_155 ) {
V_5 = 1 << V_155 ;
snprintf ( V_8 , sizeof( V_8 ) ,
L_31 , V_155 + 1 ) ;
V_35 = F_7 ( V_2 , V_24 , V_4 ,
V_5 , V_6 , V_8 ,
V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
int V_35 , V_155 ;
char V_8 [ 48 ] ;
const unsigned int V_24 = 5 ;
const int V_6 = V_152 ;
const unsigned int V_4 = 9 ;
for ( V_155 = 0 ; V_155 < 8 ; ++ V_155 ) {
V_5 = 1 << V_155 ;
snprintf ( V_8 , sizeof( V_8 ) ,
L_32 , V_155 + 1 ) ;
V_35 = F_7 ( V_2 , V_24 , V_4 , V_5 ,
V_6 , V_8 ,
V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
for ( V_155 = 8 ; V_155 < 16 ; ++ V_155 ) {
V_5 = 1 << V_155 ;
snprintf ( V_8 , sizeof( V_8 ) ,
L_33 , V_155 - 7 ) ;
V_35 = F_7 ( V_2 , V_24 , V_4 , V_5 ,
V_6 , V_8 ,
V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_75 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_74 ( V_2 , 1 , 6 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_76 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_77 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_78 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_79 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_80 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
void F_82 ( struct V_102 * V_73 ,
unsigned char V_156 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_3 = 12 ;
F_83 (mixer, &chip->mixer_list, list) {
V_11 = (struct V_10 * ) V_2 -> V_157 [ V_3 ] ;
if ( V_11 ) {
F_84 ( V_11 , V_123 ,
V_11 -> V_4 << 8 ,
V_156 ) ;
F_11 ( V_2 , V_3 ) ;
}
break;
}
}
static int F_85 ( struct V_1 * V_2 )
{
char V_8 [ 64 ] ;
unsigned int V_5 , V_52 ;
int V_151 , V_158 , V_35 ;
int V_159 = 0 ;
int V_160 = 0 ;
const unsigned int V_24 = 0x40 ;
const int V_6 = V_152 ;
const int V_4 = 1 ;
switch ( V_2 -> V_73 -> V_72 ) {
case F_33 ( 0x0763 , 0x2030 ) :
V_159 = 6 ;
V_160 = 4 ;
break;
case F_33 ( 0x0763 , 0x2031 ) :
V_159 = 8 ;
V_160 = 6 ;
break;
}
for ( V_158 = 0 ; V_158 < V_159 + V_160 ; V_158 ++ ) {
for ( V_151 = 0 ; V_151 < V_159 ; V_151 ++ ) {
if ( V_158 < V_159 ) {
snprintf ( V_8 , sizeof( V_8 ) ,
L_34 ,
V_158 + 1 , V_151 + 1 ) ;
} else {
snprintf ( V_8 , sizeof( V_8 ) ,
L_35 ,
V_158 - V_159 + 1 , V_151 + 1 ) ;
}
V_5 = ( V_151 == 0 ) ? 0 : 1 << ( V_151 - 1 ) ;
V_52 = V_158 * V_159 ;
V_35 = F_1 ( V_2 , V_24 , V_4 ,
V_5 , V_6 , V_52 , V_8 ,
& V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
static const char V_8 [] = L_28 ;
const unsigned int V_24 = 0x43 ;
const int V_6 = V_154 ;
const unsigned int V_4 = 3 ;
const unsigned int V_5 = 0 ;
return F_7 ( V_2 , V_24 , V_4 , V_5 , V_6 ,
V_8 , V_153 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
static const char V_8 [] = L_29 ;
const unsigned int V_24 = 0x43 ;
const int V_6 = V_152 ;
const unsigned int V_4 = 4 ;
const unsigned int V_5 = 0 ;
return F_7 ( V_2 , V_24 , V_4 , V_5 , V_6 ,
V_8 , V_153 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
static const char V_8 [] = L_30 ;
const unsigned int V_24 = 0x43 ;
const int V_6 = V_154 ;
const unsigned int V_4 = 5 ;
const unsigned int V_5 = 0 ;
return F_7 ( V_2 , V_24 , V_4 , V_5 , V_6 ,
V_8 , NULL ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
char V_8 [ 64 ] ;
unsigned int V_5 ;
int V_158 , V_35 ;
int V_159 = 0 ;
int V_160 = 0 ;
const unsigned int V_24 = 0x42 ;
const int V_6 = V_152 ;
const int V_4 = 1 ;
switch ( V_2 -> V_73 -> V_72 ) {
case F_33 ( 0x0763 , 0x2030 ) :
V_159 = 6 ;
V_160 = 4 ;
break;
case F_33 ( 0x0763 , 0x2031 ) :
V_159 = 8 ;
V_160 = 6 ;
break;
}
for ( V_158 = 0 ; V_158 < V_159 + V_160 ; V_158 ++ ) {
if ( V_158 < V_159 ) {
snprintf ( V_8 , sizeof( V_8 ) ,
L_36 ,
V_158 + 1 ) ;
} else {
snprintf ( V_8 , sizeof( V_8 ) ,
L_37 ,
V_158 - V_159 + 1 ) ;
}
V_5 = ( V_158 == 0 ) ? 0 : 1 << ( V_158 - 1 ) ;
V_35 = F_7 ( V_2 , V_24 , V_4 ,
V_5 , V_6 , V_8 ,
& V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
char V_8 [ 64 ] ;
unsigned int V_5 ;
int V_158 , V_35 ;
int V_159 = 0 ;
int V_52 = 0 ;
const unsigned int V_24 = 0x40 ;
const int V_6 = V_152 ;
const int V_4 = 1 ;
switch ( V_2 -> V_73 -> V_72 ) {
case F_33 ( 0x0763 , 0x2030 ) :
V_159 = 6 ;
V_52 = 0x3c ;
break;
case F_33 ( 0x0763 , 0x2031 ) :
V_159 = 8 ;
V_52 = 0x70 ;
break;
}
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
snprintf ( V_8 , sizeof( V_8 ) ,
L_38 ,
V_158 + 1 ) ;
V_5 = ( V_158 == 0 ) ? 0 :
1 << ( V_158 + ( V_158 % 2 ) * V_159 - 1 ) ;
V_35 = F_1 ( V_2 , V_24 , V_4 ,
V_5 , V_6 , V_52 , V_8 ,
& V_153 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_85 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_89 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_90 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_74 ( V_2 , 2 , 0x43 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_86 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_87 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_88 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static int F_92 ( struct V_12 * V_96 ,
struct V_118 * V_119 )
{
V_119 -> type = V_161 ;
V_119 -> V_61 = 1 ;
return 0 ;
}
static int F_93 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
struct V_102 * V_73 = V_41 -> V_2 -> V_73 ;
int V_35 ;
struct V_162 * V_77 ;
struct V_163 * V_164 ;
unsigned int V_165 ;
unsigned char V_166 [ 3 ] ;
int V_167 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_98 -> V_99 . V_168 . V_48 [ 0 ] = V_96 -> V_100 & 0xff ;
V_98 -> V_99 . V_168 . V_48 [ 1 ] = ( V_96 -> V_100 >> 8 ) & 0xff ;
V_98 -> V_99 . V_168 . V_48 [ 2 ] = 0x00 ;
V_77 = F_94 ( V_73 -> V_94 , 1 ) ;
V_164 = & V_77 -> V_169 [ 1 ] ;
V_165 = F_95 ( V_164 , 0 ) -> V_170 ;
V_35 = F_34 ( V_73 -> V_94 ,
F_29 ( V_73 -> V_94 , 0 ) ,
V_147 ,
V_87 | V_130 | V_86 ,
V_171 << 8 ,
V_165 ,
V_166 ,
sizeof( V_166 ) ) ;
if ( V_35 < 0 )
goto V_172;
V_167 = V_166 [ 0 ] | ( V_166 [ 1 ] << 8 ) | ( V_166 [ 2 ] << 16 ) ;
V_98 -> V_99 . V_168 . V_48 [ 3 ] = ( V_167 == 48000 ) ?
V_173 : V_174 ;
V_35 = 0 ;
V_172:
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_96 ( struct V_39 * V_41 )
{
struct V_102 * V_73 = V_41 -> V_2 -> V_73 ;
unsigned int V_135 = V_41 -> V_13 -> V_100 ;
V_95 V_175 ;
int V_35 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_175 = ( ( V_135 >> 4 ) & 0xf0 ) | ( V_135 & 0x0f ) ;
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) ,
V_123 ,
V_103 | V_104 | V_105 ,
V_175 ,
2 ,
NULL ,
0 ) ;
if ( V_35 < 0 )
goto V_172;
V_175 = ( V_135 & V_176 ) ? 0xa0 : 0x20 ;
V_175 |= ( V_135 >> 12 ) & 0x0f ;
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) ,
V_123 ,
V_103 | V_104 | V_105 ,
V_175 ,
3 ,
NULL ,
0 ) ;
if ( V_35 < 0 )
goto V_172;
V_172:
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_97 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
unsigned int V_135 , V_177 ;
int V_35 ;
V_135 = V_177 = V_96 -> V_100 ;
V_135 &= 0xfffff0f0 ;
V_135 |= ( V_98 -> V_99 . V_168 . V_48 [ 1 ] & 0x0f ) << 8 ;
V_135 |= ( V_98 -> V_99 . V_168 . V_48 [ 0 ] & 0x0f ) ;
V_135 &= 0xffff0fff ;
V_135 |= ( V_98 -> V_99 . V_168 . V_48 [ 1 ] & 0xf0 ) << 8 ;
if ( V_135 == V_177 )
return 0 ;
V_96 -> V_100 = V_135 ;
V_35 = F_96 ( V_41 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_98 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . V_168 . V_48 [ 0 ] = 0x0f ;
V_98 -> V_99 . V_168 . V_48 [ 1 ] = 0xff ;
V_98 -> V_99 . V_168 . V_48 [ 2 ] = 0x00 ;
V_98 -> V_99 . V_168 . V_48 [ 3 ] = 0x00 ;
return 0 ;
}
static int F_99 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
V_98 -> V_99 . integer . V_99 [ 0 ] = ! ( V_96 -> V_100 & 0x02 ) ;
return 0 ;
}
static int F_100 ( struct V_39 * V_41 )
{
struct V_102 * V_73 = V_41 -> V_2 -> V_73 ;
V_95 V_175 = V_41 -> V_13 -> V_100 ;
int V_35 ;
V_35 = F_32 ( V_73 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_34 ( V_73 -> V_94 ,
F_35 ( V_73 -> V_94 , 0 ) ,
V_123 ,
V_103 | V_104 | V_105 ,
V_175 ,
9 ,
NULL ,
0 ) ;
F_36 ( V_73 ) ;
return V_35 ;
}
static int F_101 ( struct V_12 * V_96 ,
struct V_97 * V_98 )
{
struct V_39 * V_41 = F_38 ( V_96 ) ;
V_95 V_175 ;
int V_35 ;
V_175 = V_98 -> V_99 . integer . V_99 [ 0 ] ? 0x28 : 0x2a ;
if ( V_175 != V_41 -> V_13 -> V_100 )
return 0 ;
V_96 -> V_100 = V_175 ;
V_35 = F_100 ( V_41 ) ;
return V_35 < 0 ? V_35 : 1 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_35 , V_70 ;
static T_2 V_178 [] = {
F_96 ,
NULL ,
F_100
} ;
for ( V_70 = 0 ; V_70 < F_21 ( V_179 ) ; ++ V_70 ) {
V_35 = F_9 ( V_2 , 0 ,
V_178 [ V_70 ] ,
& V_179 [ V_70 ] ,
NULL ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_2 )
{
int V_35 = 0 ;
struct V_110 * V_111 ;
if ( ( V_35 = F_20 ( V_2 ) ) < 0 )
return V_35 ;
switch ( V_2 -> V_73 -> V_72 ) {
case F_33 ( 0x041e , 0x3020 ) :
case F_33 ( 0x041e , 0x3040 ) :
case F_33 ( 0x041e , 0x3042 ) :
case F_33 ( 0x041e , 0x30df ) :
case F_33 ( 0x041e , 0x3048 ) :
V_35 = F_40 ( V_2 ) ;
if ( V_35 < 0 )
break;
if ( ! F_104 ( V_2 -> V_73 -> V_75 , L_39 , & V_111 ) )
F_105 ( V_111 , V_2 ,
F_41 ) ;
break;
case F_33 ( 0x041e , 0x3f19 ) :
V_35 = F_49 ( V_2 ) ;
if ( V_35 < 0 )
break;
break;
case F_33 ( 0x0763 , 0x2030 ) :
case F_33 ( 0x0763 , 0x2031 ) :
V_35 = F_91 ( V_2 ) ;
break;
case F_33 ( 0x0763 , 0x2080 ) :
case F_33 ( 0x0763 , 0x2081 ) :
V_35 = F_81 ( V_2 ) ;
break;
case F_33 ( 0x0b05 , 0x1739 ) :
case F_33 ( 0x0b05 , 0x1743 ) :
case F_33 ( 0x0b05 , 0x17a0 ) :
V_35 = F_54 ( V_2 ) ;
break;
case F_33 ( 0x0d8c , 0x0103 ) :
V_35 = F_102 ( V_2 ) ;
break;
case F_33 ( 0x0dba , 0x1000 ) :
V_35 = F_60 ( V_2 ) ;
break;
case F_33 ( 0x17cc , 0x1011 ) :
V_35 = F_67 ( V_2 ,
V_180 ,
F_21 ( V_180 ) ) ;
break;
case F_33 ( 0x17cc , 0x1021 ) :
V_35 = F_67 ( V_2 ,
V_181 ,
F_21 ( V_181 ) ) ;
break;
case F_33 ( 0x200c , 0x1018 ) :
V_35 = F_8 ( V_2 , V_182 ) ;
break;
case F_33 ( 0x1235 , 0x8012 ) :
case F_33 ( 0x1235 , 0x8002 ) :
case F_33 ( 0x1235 , 0x8004 ) :
case F_33 ( 0x1235 , 0x8014 ) :
case F_33 ( 0x1235 , 0x800c ) :
V_35 = F_106 ( V_2 ) ;
break;
}
return V_35 ;
}
void F_107 ( struct V_1 * V_2 ,
int V_3 )
{
if ( ! V_2 -> V_46 )
return;
switch ( V_3 ) {
case 0 :
V_2 -> V_83 -> V_94 = V_2 -> V_73 -> V_94 ;
F_108 ( V_2 -> V_83 , V_183 ) ;
break;
case 4 :
case 7 :
case 19 :
case 20 :
break;
case 3 :
if ( V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3040 ) ||
V_2 -> V_73 -> V_72 == F_33 ( 0x041e , 0x3048 ) )
F_11 ( V_2 , V_2 -> V_46 -> V_55 ) ;
break;
default:
F_109 ( V_2 -> V_73 , L_40 , V_3 ) ;
break;
}
}
