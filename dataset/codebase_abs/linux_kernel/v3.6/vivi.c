static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
V_4 = & V_6 [ V_5 ] ;
if ( V_4 -> V_7 == V_3 -> V_4 . V_8 . V_9 )
break;
}
if ( V_5 == F_2 ( V_6 ) )
return NULL ;
return & V_6 [ V_5 ] ;
}
static void F_3 ( struct V_10 * V_11 )
{
T_1 V_12 , V_13 , V_14 ;
int V_5 , V_15 ;
for ( V_5 = 0 ; V_5 < 9 ; V_5 ++ ) {
V_12 = V_16 [ V_11 -> V_17 ] . V_18 [ V_5 ] [ 0 ] ;
V_13 = V_16 [ V_11 -> V_17 ] . V_18 [ V_5 ] [ 1 ] ;
V_14 = V_16 [ V_11 -> V_17 ] . V_18 [ V_5 ] [ 2 ] ;
V_15 = 0 ;
switch ( V_11 -> V_4 -> V_7 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_15 = 1 ;
break;
case V_23 :
case V_24 :
V_12 >>= 3 ;
V_13 >>= 2 ;
V_14 >>= 3 ;
break;
case V_25 :
case V_26 :
V_12 >>= 3 ;
V_13 >>= 3 ;
V_14 >>= 3 ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_30 :
break;
}
if ( V_15 ) {
V_11 -> V_16 [ V_5 ] [ 0 ] = F_4 ( V_12 , V_13 , V_14 ) ;
V_11 -> V_16 [ V_5 ] [ 1 ] = F_5 ( V_12 , V_13 , V_14 ) ;
V_11 -> V_16 [ V_5 ] [ 2 ] = F_6 ( V_12 , V_13 , V_14 ) ;
} else {
V_11 -> V_16 [ V_5 ] [ 0 ] = V_12 ;
V_11 -> V_16 [ V_5 ] [ 1 ] = V_13 ;
V_11 -> V_16 [ V_5 ] [ 2 ] = V_14 ;
}
}
}
static void F_7 ( struct V_10 * V_11 , T_1 * V_31 , int V_32 , bool V_33 )
{
T_1 V_34 , V_35 , V_36 ;
T_1 V_37 = V_11 -> V_38 ;
int V_39 ;
T_1 * V_40 ;
V_34 = V_11 -> V_16 [ V_32 ] [ 0 ] ;
V_35 = V_11 -> V_16 [ V_32 ] [ 1 ] ;
V_36 = V_11 -> V_16 [ V_32 ] [ 2 ] ;
for ( V_39 = 0 ; V_39 < V_11 -> V_41 ; V_39 ++ ) {
V_40 = V_31 + V_39 ;
switch ( V_11 -> V_4 -> V_7 ) {
case V_19 :
switch ( V_39 ) {
case 0 :
* V_40 = V_34 ;
break;
case 1 :
* V_40 = V_33 ? V_36 : V_35 ;
break;
}
break;
case V_20 :
switch ( V_39 ) {
case 0 :
* V_40 = V_33 ? V_36 : V_35 ;
break;
case 1 :
* V_40 = V_34 ;
break;
}
break;
case V_21 :
switch ( V_39 ) {
case 0 :
* V_40 = V_34 ;
break;
case 1 :
* V_40 = V_33 ? V_35 : V_36 ;
break;
}
break;
case V_22 :
switch ( V_39 ) {
case 0 :
* V_40 = V_33 ? V_35 : V_36 ;
break;
case 1 :
* V_40 = V_34 ;
break;
}
break;
case V_23 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
case 1 :
* V_40 = ( V_34 << 3 ) | ( V_35 >> 3 ) ;
break;
}
break;
case V_24 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_34 << 3 ) | ( V_35 >> 3 ) ;
break;
case 1 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
}
break;
case V_25 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
case 1 :
* V_40 = ( V_37 & 0x80 ) | ( V_34 << 2 ) | ( V_35 >> 3 ) ;
break;
}
break;
case V_26 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_37 & 0x80 ) | ( V_34 << 2 ) | ( V_35 >> 3 ) ;
break;
case 1 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
}
break;
case V_27 :
switch ( V_39 ) {
case 0 :
* V_40 = V_34 ;
break;
case 1 :
* V_40 = V_35 ;
break;
case 2 :
* V_40 = V_36 ;
break;
}
break;
case V_28 :
switch ( V_39 ) {
case 0 :
* V_40 = V_36 ;
break;
case 1 :
* V_40 = V_35 ;
break;
case 2 :
* V_40 = V_34 ;
break;
}
break;
case V_29 :
switch ( V_39 ) {
case 0 :
* V_40 = V_37 ;
break;
case 1 :
* V_40 = V_34 ;
break;
case 2 :
* V_40 = V_35 ;
break;
case 3 :
* V_40 = V_36 ;
break;
}
break;
case V_30 :
switch ( V_39 ) {
case 0 :
* V_40 = V_36 ;
break;
case 1 :
* V_40 = V_35 ;
break;
case 2 :
* V_40 = V_34 ;
break;
case 3 :
* V_40 = V_37 ;
break;
}
break;
}
}
}
static void F_8 ( struct V_10 * V_11 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_11 -> V_43 * 2 ; V_42 ++ ) {
int V_32 = V_42 / ( V_11 -> V_43 / 8 ) % 8 ;
F_7 ( V_11 , V_11 -> line + V_42 * V_11 -> V_41 , V_32 , V_42 & 1 ) ;
}
}
static void F_9 ( struct V_10 * V_11 , char * V_44 ,
int V_45 , int V_46 , char * V_47 )
{
int line ;
if ( V_45 + 16 >= V_11 -> V_48 || V_46 + strlen ( V_47 ) * 8 >= V_11 -> V_43 )
return;
for ( line = V_45 ; line < V_45 + 16 ; line ++ ) {
int V_49 = 0 ;
char * V_50 = V_44 + line * V_11 -> V_43 * V_11 -> V_41 + V_46 * V_11 -> V_41 ;
char * V_51 ;
for ( V_51 = V_47 ; * V_51 ; V_51 ++ ) {
T_1 V_52 = V_53 [ * V_51 * 16 + line - V_45 ] ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 7 ; V_54 ++ , V_49 ++ ) {
if ( V_52 & ( 1 << ( 7 - V_54 ) ) )
F_7 ( V_11 , V_50 + V_49 * V_11 -> V_41 , V_55 , ( V_46 + V_45 ) & 1 ) ;
else
F_7 ( V_11 , V_50 + V_49 * V_11 -> V_41 , V_56 , ( V_46 + V_45 ) & 1 ) ;
}
}
}
}
static void F_10 ( struct V_10 * V_11 , struct V_57 * V_31 )
{
int V_58 = V_11 -> V_43 ;
int V_59 = V_11 -> V_48 ;
struct V_60 V_61 ;
void * V_62 = F_11 ( & V_31 -> V_63 , 0 ) ;
unsigned V_64 ;
char V_65 [ 100 ] ;
int V_66 , line = 1 ;
T_2 V_67 ;
if ( ! V_62 )
return;
for ( V_66 = 0 ; V_66 < V_59 ; V_66 ++ )
memcpy ( V_62 + V_66 * V_58 * V_11 -> V_41 ,
V_11 -> line + ( V_11 -> V_68 % V_58 ) * V_11 -> V_41 ,
V_58 * V_11 -> V_41 ) ;
V_11 -> V_64 += F_12 ( V_69 - V_11 -> V_69 ) ;
V_11 -> V_69 = V_69 ;
V_64 = V_11 -> V_64 ;
snprintf ( V_65 , sizeof( V_65 ) , L_1 ,
( V_64 / ( 60 * 60 * 1000 ) ) % 24 ,
( V_64 / ( 60 * 1000 ) ) % 60 ,
( V_64 / 1000 ) % 60 ,
V_64 % 1000 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
snprintf ( V_65 , sizeof( V_65 ) , L_2 ,
V_11 -> V_43 , V_11 -> V_48 , V_11 -> V_17 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
V_67 = F_13 ( V_11 -> V_67 ) ;
F_14 ( V_11 -> V_70 . V_71 ) ;
snprintf ( V_65 , sizeof( V_65 ) , L_3 ,
V_11 -> V_72 -> V_73 . V_74 ,
V_11 -> V_75 -> V_73 . V_74 ,
V_11 -> V_76 -> V_73 . V_74 ,
V_11 -> V_77 -> V_73 . V_74 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
snprintf ( V_65 , sizeof( V_65 ) , L_4 ,
V_11 -> V_78 -> V_73 . V_74 , V_67 , V_11 -> V_79 -> V_73 . V_74 ,
V_11 -> V_37 -> V_73 . V_74 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
snprintf ( V_65 , sizeof( V_65 ) , L_5 ,
V_11 -> V_80 -> V_73 . V_74 ,
V_11 -> V_81 -> V_73 . V_82 ,
V_11 -> V_83 -> V_73 . V_74 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
snprintf ( V_65 , sizeof( V_65 ) , L_6 ,
V_11 -> boolean -> V_73 . V_74 ,
V_11 -> V_84 -> V_85 [ V_11 -> V_84 -> V_73 . V_74 ] ,
V_11 -> string -> V_73 . string ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
snprintf ( V_65 , sizeof( V_65 ) , L_7 ,
V_11 -> V_86 -> V_87 [ V_11 -> V_86 -> V_73 . V_74 ] ,
V_11 -> V_86 -> V_73 . V_74 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
F_15 ( V_11 -> V_70 . V_71 ) ;
if ( V_11 -> V_88 ) {
V_11 -> V_88 -- ;
snprintf ( V_65 , sizeof( V_65 ) , L_8 ) ;
F_9 ( V_11 , V_62 , line ++ * 16 , 16 , V_65 ) ;
}
V_11 -> V_68 += 2 ;
V_31 -> V_63 . V_89 . V_90 = V_91 ;
V_11 -> V_92 ++ ;
V_31 -> V_63 . V_89 . V_93 = V_11 -> V_92 >> 1 ;
F_16 ( & V_61 ) ;
V_31 -> V_63 . V_89 . V_94 = V_61 ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_95 * V_96 = & V_11 -> V_97 ;
struct V_57 * V_31 ;
unsigned long V_98 = 0 ;
F_18 ( V_11 , 1 , L_9 ) ;
F_19 ( & V_11 -> V_99 , V_98 ) ;
if ( F_20 ( & V_96 -> V_100 ) ) {
F_18 ( V_11 , 1 , L_10 ) ;
F_21 ( & V_11 -> V_99 , V_98 ) ;
return;
}
V_31 = F_22 ( V_96 -> V_100 . V_101 , struct V_57 , V_102 ) ;
F_23 ( & V_31 -> V_102 ) ;
F_21 ( & V_11 -> V_99 , V_98 ) ;
F_16 ( & V_31 -> V_63 . V_89 . V_94 ) ;
F_10 ( V_11 , V_31 ) ;
F_18 ( V_11 , 1 , L_11 , V_31 ) ;
F_24 ( & V_31 -> V_63 , V_103 ) ;
F_18 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_63 . V_89 . V_104 ) ;
}
static void F_25 ( struct V_10 * V_11 )
{
struct V_95 * V_96 = & V_11 -> V_97 ;
int V_105 ;
F_26 ( V_106 , V_107 ) ;
F_18 ( V_11 , 1 , L_13 , V_108 ,
( unsigned long ) V_96 ) ;
F_27 ( & V_96 -> V_109 , & V_106 ) ;
if ( F_28 () )
goto V_110;
V_105 = F_29 ( F_30 ( 1 ) ) ;
F_17 ( V_11 ) ;
F_31 ( V_105 ) ;
V_110:
F_32 ( & V_96 -> V_109 , & V_106 ) ;
F_33 () ;
}
static int F_34 ( void * V_111 )
{
struct V_10 * V_11 = V_111 ;
F_18 ( V_11 , 1 , L_14 ) ;
F_35 () ;
for (; ; ) {
F_25 ( V_11 ) ;
if ( F_28 () )
break;
}
F_18 ( V_11 , 1 , L_15 ) ;
return 0 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_95 * V_96 = & V_11 -> V_97 ;
F_18 ( V_11 , 1 , L_16 , V_108 ) ;
V_11 -> V_64 = 0 ;
V_11 -> V_68 = 0 ;
V_11 -> V_69 = V_69 ;
V_96 -> V_112 = 0 ;
V_96 -> V_113 = V_69 ;
V_96 -> V_114 = F_37 ( F_34 , V_11 , V_11 -> V_115 . V_116 ) ;
if ( F_38 ( V_96 -> V_114 ) ) {
F_39 ( & V_11 -> V_115 , L_17 ) ;
return F_40 ( V_96 -> V_114 ) ;
}
F_41 ( & V_96 -> V_109 ) ;
F_18 ( V_11 , 1 , L_18 , V_108 ) ;
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_95 * V_96 = & V_11 -> V_97 ;
F_18 ( V_11 , 1 , L_16 , V_108 ) ;
if ( V_96 -> V_114 ) {
F_43 ( V_96 -> V_114 ) ;
V_96 -> V_114 = NULL ;
}
while ( ! F_20 ( & V_96 -> V_100 ) ) {
struct V_57 * V_31 ;
V_31 = F_22 ( V_96 -> V_100 . V_101 , struct V_57 , V_102 ) ;
F_23 ( & V_31 -> V_102 ) ;
F_24 ( & V_31 -> V_63 , V_117 ) ;
F_18 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_63 . V_89 . V_104 ) ;
}
}
static int F_44 ( struct V_118 * V_119 , const struct V_2 * V_4 ,
unsigned int * V_120 , unsigned int * V_121 ,
unsigned int V_122 [] , void * V_123 [] )
{
struct V_10 * V_11 = F_45 ( V_119 ) ;
unsigned long V_124 ;
if ( V_4 )
V_124 = V_4 -> V_4 . V_8 . V_125 ;
else
V_124 = V_11 -> V_43 * V_11 -> V_48 * V_11 -> V_41 ;
if ( V_124 == 0 )
return - V_126 ;
if ( 0 == * V_120 )
* V_120 = 32 ;
while ( V_124 * * V_120 > V_127 * 1024 * 1024 )
( * V_120 ) -- ;
* V_121 = 1 ;
V_122 [ 0 ] = V_124 ;
F_18 ( V_11 , 1 , L_19 , V_108 ,
* V_120 , V_124 ) ;
return 0 ;
}
static int F_46 ( struct V_128 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_118 ) ;
struct V_57 * V_31 = F_47 ( V_63 , struct V_57 , V_63 ) ;
unsigned long V_124 ;
F_18 ( V_11 , 1 , L_20 , V_108 , V_63 -> V_89 . V_90 ) ;
F_48 ( NULL == V_11 -> V_4 ) ;
if ( V_11 -> V_43 < 48 || V_11 -> V_43 > V_129 ||
V_11 -> V_48 < 32 || V_11 -> V_48 > V_130 )
return - V_126 ;
V_124 = V_11 -> V_43 * V_11 -> V_48 * V_11 -> V_41 ;
if ( F_49 ( V_63 , 0 ) < V_124 ) {
F_18 ( V_11 , 1 , L_21 ,
V_108 , F_49 ( V_63 , 0 ) , V_124 ) ;
return - V_126 ;
}
F_50 ( & V_31 -> V_63 , 0 , V_124 ) ;
V_31 -> V_4 = V_11 -> V_4 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_51 ( struct V_128 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_118 ) ;
struct V_57 * V_31 = F_47 ( V_63 , struct V_57 , V_63 ) ;
struct V_95 * V_97 = & V_11 -> V_97 ;
unsigned long V_98 = 0 ;
F_18 ( V_11 , 1 , L_16 , V_108 ) ;
F_19 ( & V_11 -> V_99 , V_98 ) ;
F_52 ( & V_31 -> V_102 , & V_97 -> V_100 ) ;
F_21 ( & V_11 -> V_99 , V_98 ) ;
}
static int F_53 ( struct V_118 * V_119 , unsigned int V_131 )
{
struct V_10 * V_11 = F_45 ( V_119 ) ;
F_18 ( V_11 , 1 , L_16 , V_108 ) ;
return F_36 ( V_11 ) ;
}
static int F_54 ( struct V_118 * V_119 )
{
struct V_10 * V_11 = F_45 ( V_119 ) ;
F_18 ( V_11 , 1 , L_16 , V_108 ) ;
F_42 ( V_11 ) ;
return 0 ;
}
static void F_55 ( struct V_118 * V_119 )
{
struct V_10 * V_11 = F_45 ( V_119 ) ;
F_14 ( & V_11 -> V_132 ) ;
}
static void F_56 ( struct V_118 * V_119 )
{
struct V_10 * V_11 = F_45 ( V_119 ) ;
F_15 ( & V_11 -> V_132 ) ;
}
static int F_57 ( struct V_133 * V_133 , void * V_134 ,
struct V_135 * V_136 )
{
struct V_10 * V_11 = F_58 ( V_133 ) ;
strcpy ( V_136 -> V_137 , L_22 ) ;
strcpy ( V_136 -> V_138 , L_22 ) ;
F_59 ( V_136 -> V_139 , V_11 -> V_115 . V_116 , sizeof( V_136 -> V_139 ) ) ;
V_136 -> V_140 = V_141 | V_142 |
V_143 ;
V_136 -> V_144 = V_136 -> V_140 | V_145 ;
return 0 ;
}
static int F_60 ( struct V_133 * V_133 , void * V_134 ,
struct V_146 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_104 >= F_2 ( V_6 ) )
return - V_126 ;
V_4 = & V_6 [ V_3 -> V_104 ] ;
F_59 ( V_3 -> V_147 , V_4 -> V_116 , sizeof( V_3 -> V_147 ) ) ;
V_3 -> V_9 = V_4 -> V_7 ;
return 0 ;
}
static int F_61 ( struct V_133 * V_133 , void * V_134 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_58 ( V_133 ) ;
V_3 -> V_4 . V_8 . V_43 = V_11 -> V_43 ;
V_3 -> V_4 . V_8 . V_48 = V_11 -> V_48 ;
V_3 -> V_4 . V_8 . V_90 = V_91 ;
V_3 -> V_4 . V_8 . V_9 = V_11 -> V_4 -> V_7 ;
V_3 -> V_4 . V_8 . V_148 =
( V_3 -> V_4 . V_8 . V_43 * V_11 -> V_4 -> V_149 ) >> 3 ;
V_3 -> V_4 . V_8 . V_125 =
V_3 -> V_4 . V_8 . V_48 * V_3 -> V_4 . V_8 . V_148 ;
if ( V_11 -> V_4 -> V_7 == V_19 ||
V_11 -> V_4 -> V_7 == V_20 )
V_3 -> V_4 . V_8 . V_150 = V_151 ;
else
V_3 -> V_4 . V_8 . V_150 = V_152 ;
return 0 ;
}
static int F_62 ( struct V_133 * V_133 , void * V_134 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_58 ( V_133 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( V_11 , 1 , L_23 ,
V_3 -> V_4 . V_8 . V_9 ) ;
V_3 -> V_4 . V_8 . V_9 = V_19 ;
V_4 = F_1 ( V_3 ) ;
}
V_3 -> V_4 . V_8 . V_90 = V_91 ;
F_63 ( & V_3 -> V_4 . V_8 . V_43 , 48 , V_129 , 2 ,
& V_3 -> V_4 . V_8 . V_48 , 32 , V_130 , 0 , 0 ) ;
V_3 -> V_4 . V_8 . V_148 =
( V_3 -> V_4 . V_8 . V_43 * V_4 -> V_149 ) >> 3 ;
V_3 -> V_4 . V_8 . V_125 =
V_3 -> V_4 . V_8 . V_48 * V_3 -> V_4 . V_8 . V_148 ;
if ( V_4 -> V_7 == V_19 ||
V_4 -> V_7 == V_20 )
V_3 -> V_4 . V_8 . V_150 = V_151 ;
else
V_3 -> V_4 . V_8 . V_150 = V_152 ;
return 0 ;
}
static int F_64 ( struct V_133 * V_133 , void * V_134 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_58 ( V_133 ) ;
struct V_118 * V_153 = & V_11 -> V_154 ;
int V_155 = F_62 ( V_133 , V_134 , V_3 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( F_65 ( V_153 ) ) {
F_18 ( V_11 , 1 , L_24 , V_108 ) ;
return - V_156 ;
}
V_11 -> V_4 = F_1 ( V_3 ) ;
V_11 -> V_41 = V_11 -> V_4 -> V_149 / 8 ;
V_11 -> V_43 = V_3 -> V_4 . V_8 . V_43 ;
V_11 -> V_48 = V_3 -> V_4 . V_8 . V_48 ;
return 0 ;
}
static int F_66 ( struct V_133 * V_133 , void * V_134 ,
struct V_157 * V_158 )
{
if ( V_158 -> V_104 >= V_159 )
return - V_126 ;
V_158 -> type = V_160 ;
sprintf ( V_158 -> V_116 , L_25 , V_158 -> V_104 ) ;
return 0 ;
}
static int F_67 ( struct V_133 * V_133 , void * V_134 , unsigned int * V_54 )
{
struct V_10 * V_11 = F_58 ( V_133 ) ;
* V_54 = V_11 -> V_17 ;
return 0 ;
}
static int F_68 ( struct V_133 * V_133 , void * V_134 , unsigned int V_54 )
{
struct V_10 * V_11 = F_58 ( V_133 ) ;
if ( V_54 >= V_159 )
return - V_126 ;
if ( V_54 == V_11 -> V_17 )
return 0 ;
V_11 -> V_17 = V_54 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_69 ( struct V_161 * V_162 )
{
struct V_10 * V_11 = F_47 ( V_162 -> V_163 , struct V_10 , V_70 ) ;
if ( V_162 == V_11 -> V_78 )
V_11 -> V_67 -> V_74 = V_69 & 0xff ;
return 0 ;
}
static int F_70 ( struct V_161 * V_162 )
{
struct V_10 * V_11 = F_47 ( V_162 -> V_163 , struct V_10 , V_70 ) ;
switch ( V_162 -> V_164 ) {
case V_165 :
V_11 -> V_38 = V_162 -> V_74 ;
break;
default:
if ( V_162 == V_11 -> V_166 )
V_11 -> V_88 = 30 ;
break;
}
return 0 ;
}
static int F_71 ( void )
{
struct V_10 * V_11 ;
struct V_167 * V_102 ;
while ( ! F_20 ( & V_168 ) ) {
V_102 = V_168 . V_101 ;
F_23 ( V_102 ) ;
V_11 = F_22 ( V_102 , struct V_10 , V_168 ) ;
F_72 ( & V_11 -> V_115 , L_26 ,
F_73 ( & V_11 -> V_169 ) ) ;
F_74 ( & V_11 -> V_169 ) ;
F_75 ( & V_11 -> V_115 ) ;
F_76 ( & V_11 -> V_70 ) ;
F_77 ( V_11 ) ;
}
return 0 ;
}
static int T_3 F_78 ( int V_170 )
{
struct V_10 * V_11 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
struct V_118 * V_153 ;
int V_155 ;
V_11 = F_79 ( sizeof( * V_11 ) , V_175 ) ;
if ( ! V_11 )
return - V_176 ;
snprintf ( V_11 -> V_115 . V_116 , sizeof( V_11 -> V_115 . V_116 ) ,
L_27 , V_177 , V_170 ) ;
V_155 = F_80 ( NULL , & V_11 -> V_115 ) ;
if ( V_155 )
goto V_178;
V_11 -> V_4 = & V_6 [ 0 ] ;
V_11 -> V_43 = 640 ;
V_11 -> V_48 = 480 ;
V_11 -> V_41 = V_11 -> V_4 -> V_149 / 8 ;
V_174 = & V_11 -> V_70 ;
F_81 ( V_174 , 11 ) ;
V_11 -> V_79 = F_82 ( V_174 , & V_179 ,
V_180 , 0 , 255 , 1 , 200 ) ;
V_11 -> V_72 = F_82 ( V_174 , & V_179 ,
V_181 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_75 = F_82 ( V_174 , & V_179 ,
V_182 , 0 , 255 , 1 , 16 ) ;
V_11 -> V_76 = F_82 ( V_174 , & V_179 ,
V_183 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_77 = F_82 ( V_174 , & V_179 ,
V_184 , - 128 , 127 , 1 , 0 ) ;
V_11 -> V_78 = F_82 ( V_174 , & V_179 ,
V_185 , 0 , 1 , 1 , 1 ) ;
V_11 -> V_67 = F_82 ( V_174 , & V_179 ,
V_186 , 0 , 255 , 1 , 100 ) ;
V_11 -> V_37 = F_82 ( V_174 , & V_179 ,
V_165 , 0 , 255 , 1 , 0 ) ;
V_11 -> V_166 = F_83 ( V_174 , & V_187 , NULL ) ;
V_11 -> V_80 = F_83 ( V_174 , & V_188 , NULL ) ;
V_11 -> V_81 = F_83 ( V_174 , & V_189 , NULL ) ;
V_11 -> boolean = F_83 ( V_174 , & V_190 , NULL ) ;
V_11 -> V_84 = F_83 ( V_174 , & V_191 , NULL ) ;
V_11 -> string = F_83 ( V_174 , & V_192 , NULL ) ;
V_11 -> V_83 = F_83 ( V_174 , & V_193 , NULL ) ;
V_11 -> V_86 = F_83 ( V_174 , & V_194 , NULL ) ;
if ( V_174 -> error ) {
V_155 = V_174 -> error ;
goto V_195;
}
F_84 ( 2 , & V_11 -> V_78 , 0 , true ) ;
V_11 -> V_115 . V_70 = V_174 ;
F_85 ( & V_11 -> V_99 ) ;
V_153 = & V_11 -> V_154 ;
memset ( V_153 , 0 , sizeof( V_11 -> V_154 ) ) ;
V_153 -> type = V_196 ;
V_153 -> V_197 = V_198 | V_199 | V_200 ;
V_153 -> V_201 = V_11 ;
V_153 -> V_202 = sizeof( struct V_57 ) ;
V_153 -> V_203 = & V_204 ;
V_153 -> V_205 = & V_206 ;
F_86 ( V_153 ) ;
F_87 ( & V_11 -> V_132 ) ;
F_88 ( & V_11 -> V_97 . V_100 ) ;
F_89 ( & V_11 -> V_97 . V_109 ) ;
V_172 = & V_11 -> V_169 ;
* V_172 = V_207 ;
V_172 -> V_208 = V_208 ;
V_172 -> V_115 = & V_11 -> V_115 ;
V_172 -> V_209 = V_153 ;
F_90 ( V_210 , & V_172 -> V_98 ) ;
V_172 -> V_71 = & V_11 -> V_132 ;
F_91 ( V_172 , V_11 ) ;
V_155 = F_92 ( V_172 , V_211 , V_212 ) ;
if ( V_155 < 0 )
goto V_195;
F_52 ( & V_11 -> V_168 , & V_168 ) ;
F_72 ( & V_11 -> V_115 , L_28 ,
F_73 ( V_172 ) ) ;
return 0 ;
V_195:
F_76 ( V_174 ) ;
F_75 ( & V_11 -> V_115 ) ;
V_178:
F_77 ( V_11 ) ;
return V_155 ;
}
static int T_3 F_93 ( void )
{
const struct V_213 * V_214 = F_94 ( L_29 ) ;
int V_155 = 0 , V_54 ;
if ( V_214 == NULL ) {
F_95 ( V_215 L_30 ) ;
return - V_216 ;
}
V_53 = V_214 -> V_111 ;
if ( V_217 <= 0 )
V_217 = 1 ;
for ( V_54 = 0 ; V_54 < V_217 ; V_54 ++ ) {
V_155 = F_78 ( V_54 ) ;
if ( V_155 ) {
if ( V_54 )
V_155 = 0 ;
break;
}
}
if ( V_155 < 0 ) {
F_95 ( V_215 L_31 , V_155 ) ;
return V_155 ;
}
F_95 ( V_218 L_32
L_33 ,
V_219 ) ;
V_217 = V_54 ;
return V_155 ;
}
static void T_4 F_96 ( void )
{
F_71 () ;
}
