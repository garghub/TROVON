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
V_31 -> V_63 . V_89 . V_90 = V_11 -> V_90 ;
V_11 -> V_91 ++ ;
V_31 -> V_63 . V_89 . V_92 = V_11 -> V_91 >> 1 ;
F_16 ( & V_61 ) ;
V_31 -> V_63 . V_89 . V_93 = V_61 ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_94 * V_95 = & V_11 -> V_96 ;
struct V_57 * V_31 ;
unsigned long V_97 = 0 ;
F_18 ( V_11 , 1 , L_9 ) ;
F_19 ( & V_11 -> V_98 , V_97 ) ;
if ( F_20 ( & V_95 -> V_99 ) ) {
F_18 ( V_11 , 1 , L_10 ) ;
F_21 ( & V_11 -> V_98 , V_97 ) ;
return;
}
V_31 = F_22 ( V_95 -> V_99 . V_100 , struct V_57 , V_101 ) ;
F_23 ( & V_31 -> V_101 ) ;
F_21 ( & V_11 -> V_98 , V_97 ) ;
F_16 ( & V_31 -> V_63 . V_89 . V_93 ) ;
F_10 ( V_11 , V_31 ) ;
F_18 ( V_11 , 1 , L_11 , V_31 ) ;
F_24 ( & V_31 -> V_63 , V_102 ) ;
F_18 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_63 . V_89 . V_103 ) ;
}
static void F_25 ( struct V_10 * V_11 )
{
struct V_94 * V_95 = & V_11 -> V_96 ;
int V_104 ;
F_26 ( V_105 , V_106 ) ;
F_18 ( V_11 , 1 , L_13 , V_107 ,
( unsigned long ) V_95 ) ;
F_27 ( & V_95 -> V_108 , & V_105 ) ;
if ( F_28 () )
goto V_109;
V_104 = F_29 ( F_30 ( 1 ) ) ;
F_17 ( V_11 ) ;
F_31 ( V_104 ) ;
V_109:
F_32 ( & V_95 -> V_108 , & V_105 ) ;
F_33 () ;
}
static int F_34 ( void * V_110 )
{
struct V_10 * V_11 = V_110 ;
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
struct V_94 * V_95 = & V_11 -> V_96 ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
V_11 -> V_64 = 0 ;
V_11 -> V_68 = 0 ;
V_11 -> V_69 = V_69 ;
V_95 -> V_111 = 0 ;
V_95 -> V_112 = V_69 ;
V_95 -> V_113 = F_37 ( F_34 , V_11 , V_11 -> V_114 . V_115 ) ;
if ( F_38 ( V_95 -> V_113 ) ) {
F_39 ( & V_11 -> V_114 , L_17 ) ;
return F_40 ( V_95 -> V_113 ) ;
}
F_41 ( & V_95 -> V_108 ) ;
F_18 ( V_11 , 1 , L_18 , V_107 ) ;
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_94 * V_95 = & V_11 -> V_96 ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
if ( V_95 -> V_113 ) {
F_43 ( V_95 -> V_113 ) ;
V_95 -> V_113 = NULL ;
}
while ( ! F_20 ( & V_95 -> V_99 ) ) {
struct V_57 * V_31 ;
V_31 = F_22 ( V_95 -> V_99 . V_100 , struct V_57 , V_101 ) ;
F_23 ( & V_31 -> V_101 ) ;
F_24 ( & V_31 -> V_63 , V_116 ) ;
F_18 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_63 . V_89 . V_103 ) ;
}
}
static int F_44 ( struct V_117 * V_118 , const struct V_2 * V_4 ,
unsigned int * V_119 , unsigned int * V_120 ,
unsigned int V_121 [] , void * V_122 [] )
{
struct V_10 * V_11 = F_45 ( V_118 ) ;
unsigned long V_123 ;
V_123 = V_11 -> V_43 * V_11 -> V_48 * V_11 -> V_41 ;
if ( 0 == * V_119 )
* V_119 = 32 ;
while ( V_123 * * V_119 > V_124 * 1024 * 1024 )
( * V_119 ) -- ;
* V_120 = 1 ;
V_121 [ 0 ] = V_123 ;
F_18 ( V_11 , 1 , L_19 , V_107 ,
* V_119 , V_123 ) ;
return 0 ;
}
static int F_46 ( struct V_125 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_117 ) ;
F_47 ( NULL == V_11 -> V_4 ) ;
return 0 ;
}
static int F_48 ( struct V_125 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_117 ) ;
struct V_57 * V_31 = F_49 ( V_63 , struct V_57 , V_63 ) ;
unsigned long V_123 ;
F_18 ( V_11 , 1 , L_20 , V_107 , V_63 -> V_89 . V_90 ) ;
F_47 ( NULL == V_11 -> V_4 ) ;
if ( V_11 -> V_43 < 48 || V_11 -> V_43 > V_126 ||
V_11 -> V_48 < 32 || V_11 -> V_48 > V_127 )
return - V_128 ;
V_123 = V_11 -> V_43 * V_11 -> V_48 * V_11 -> V_41 ;
if ( F_50 ( V_63 , 0 ) < V_123 ) {
F_18 ( V_11 , 1 , L_21 ,
V_107 , F_50 ( V_63 , 0 ) , V_123 ) ;
return - V_128 ;
}
F_51 ( & V_31 -> V_63 , 0 , V_123 ) ;
V_31 -> V_4 = V_11 -> V_4 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_52 ( struct V_125 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_117 ) ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
return 0 ;
}
static void F_53 ( struct V_125 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_117 ) ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
}
static void F_54 ( struct V_125 * V_63 )
{
struct V_10 * V_11 = F_45 ( V_63 -> V_117 ) ;
struct V_57 * V_31 = F_49 ( V_63 , struct V_57 , V_63 ) ;
struct V_94 * V_96 = & V_11 -> V_96 ;
unsigned long V_97 = 0 ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
F_19 ( & V_11 -> V_98 , V_97 ) ;
F_55 ( & V_31 -> V_101 , & V_96 -> V_99 ) ;
F_21 ( & V_11 -> V_98 , V_97 ) ;
}
static int F_56 ( struct V_117 * V_118 , unsigned int V_129 )
{
struct V_10 * V_11 = F_45 ( V_118 ) ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
return F_36 ( V_11 ) ;
}
static int F_57 ( struct V_117 * V_118 )
{
struct V_10 * V_11 = F_45 ( V_118 ) ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
F_42 ( V_11 ) ;
return 0 ;
}
static void F_58 ( struct V_117 * V_118 )
{
struct V_10 * V_11 = F_45 ( V_118 ) ;
F_14 ( & V_11 -> V_130 ) ;
}
static void F_59 ( struct V_117 * V_118 )
{
struct V_10 * V_11 = F_45 ( V_118 ) ;
F_15 ( & V_11 -> V_130 ) ;
}
static int F_60 ( struct V_131 * V_131 , void * V_132 ,
struct V_133 * V_134 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
strcpy ( V_134 -> V_135 , L_22 ) ;
strcpy ( V_134 -> V_136 , L_22 ) ;
F_62 ( V_134 -> V_137 , V_11 -> V_114 . V_115 , sizeof( V_134 -> V_137 ) ) ;
V_134 -> V_138 = V_139 | V_140 |
V_141 ;
V_134 -> V_142 = V_134 -> V_138 | V_143 ;
return 0 ;
}
static int F_63 ( struct V_131 * V_131 , void * V_132 ,
struct V_144 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_103 >= F_2 ( V_6 ) )
return - V_128 ;
V_4 = & V_6 [ V_3 -> V_103 ] ;
F_62 ( V_3 -> V_145 , V_4 -> V_115 , sizeof( V_3 -> V_145 ) ) ;
V_3 -> V_9 = V_4 -> V_7 ;
return 0 ;
}
static int F_64 ( struct V_131 * V_131 , void * V_132 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
V_3 -> V_4 . V_8 . V_43 = V_11 -> V_43 ;
V_3 -> V_4 . V_8 . V_48 = V_11 -> V_48 ;
V_3 -> V_4 . V_8 . V_90 = V_11 -> V_90 ;
V_3 -> V_4 . V_8 . V_9 = V_11 -> V_4 -> V_7 ;
V_3 -> V_4 . V_8 . V_146 =
( V_3 -> V_4 . V_8 . V_43 * V_11 -> V_4 -> V_147 ) >> 3 ;
V_3 -> V_4 . V_8 . V_148 =
V_3 -> V_4 . V_8 . V_48 * V_3 -> V_4 . V_8 . V_146 ;
if ( V_11 -> V_4 -> V_7 == V_19 ||
V_11 -> V_4 -> V_7 == V_20 )
V_3 -> V_4 . V_8 . V_149 = V_150 ;
else
V_3 -> V_4 . V_8 . V_149 = V_151 ;
return 0 ;
}
static int F_65 ( struct V_131 * V_131 , void * V_132 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
struct V_1 * V_4 ;
enum V_152 V_90 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( V_11 , 1 , L_23 ,
V_3 -> V_4 . V_8 . V_9 ) ;
return - V_128 ;
}
V_90 = V_3 -> V_4 . V_8 . V_90 ;
if ( V_90 == V_153 ) {
V_90 = V_154 ;
} else if ( V_154 != V_90 ) {
F_18 ( V_11 , 1 , L_24 ) ;
return - V_128 ;
}
V_3 -> V_4 . V_8 . V_90 = V_90 ;
F_66 ( & V_3 -> V_4 . V_8 . V_43 , 48 , V_126 , 2 ,
& V_3 -> V_4 . V_8 . V_48 , 32 , V_127 , 0 , 0 ) ;
V_3 -> V_4 . V_8 . V_146 =
( V_3 -> V_4 . V_8 . V_43 * V_4 -> V_147 ) >> 3 ;
V_3 -> V_4 . V_8 . V_148 =
V_3 -> V_4 . V_8 . V_48 * V_3 -> V_4 . V_8 . V_146 ;
if ( V_4 -> V_7 == V_19 ||
V_4 -> V_7 == V_20 )
V_3 -> V_4 . V_8 . V_149 = V_150 ;
else
V_3 -> V_4 . V_8 . V_149 = V_151 ;
return 0 ;
}
static int F_67 ( struct V_131 * V_131 , void * V_132 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
struct V_117 * V_155 = & V_11 -> V_156 ;
int V_157 = F_65 ( V_131 , V_132 , V_3 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( F_68 ( V_155 ) ) {
F_18 ( V_11 , 1 , L_25 , V_107 ) ;
return - V_158 ;
}
V_11 -> V_4 = F_1 ( V_3 ) ;
V_11 -> V_41 = V_11 -> V_4 -> V_147 / 8 ;
V_11 -> V_43 = V_3 -> V_4 . V_8 . V_43 ;
V_11 -> V_48 = V_3 -> V_4 . V_8 . V_48 ;
V_11 -> V_90 = V_3 -> V_4 . V_8 . V_90 ;
return 0 ;
}
static int F_69 ( struct V_131 * V_131 , void * V_132 ,
struct V_159 * V_40 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
return F_70 ( & V_11 -> V_156 , V_40 ) ;
}
static int F_71 ( struct V_131 * V_131 , void * V_132 , struct V_160 * V_40 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
return F_72 ( & V_11 -> V_156 , V_40 ) ;
}
static int F_73 ( struct V_131 * V_131 , void * V_132 , struct V_160 * V_40 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
return F_74 ( & V_11 -> V_156 , V_40 ) ;
}
static int F_75 ( struct V_131 * V_131 , void * V_132 , struct V_160 * V_40 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
return F_76 ( & V_11 -> V_156 , V_40 , V_131 -> V_161 & V_162 ) ;
}
static int F_77 ( struct V_131 * V_131 , void * V_132 , enum V_163 V_54 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
return F_78 ( & V_11 -> V_156 , V_54 ) ;
}
static int F_79 ( struct V_131 * V_131 , void * V_132 , enum V_163 V_54 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
return F_80 ( & V_11 -> V_156 , V_54 ) ;
}
static int F_81 ( struct V_131 * V_131 , void * V_132 , T_3 * V_54 )
{
return 0 ;
}
static int F_82 ( struct V_131 * V_131 , void * V_132 ,
struct V_164 * V_165 )
{
if ( V_165 -> V_103 >= V_166 )
return - V_128 ;
V_165 -> type = V_167 ;
V_165 -> V_168 = V_169 ;
sprintf ( V_165 -> V_115 , L_26 , V_165 -> V_103 ) ;
return 0 ;
}
static int F_83 ( struct V_131 * V_131 , void * V_132 , unsigned int * V_54 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
* V_54 = V_11 -> V_17 ;
return 0 ;
}
static int F_84 ( struct V_131 * V_131 , void * V_132 , unsigned int V_54 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
if ( V_54 >= V_166 )
return - V_128 ;
if ( V_54 == V_11 -> V_17 )
return 0 ;
V_11 -> V_17 = V_54 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_85 ( struct V_170 * V_171 )
{
struct V_10 * V_11 = F_49 ( V_171 -> V_172 , struct V_10 , V_70 ) ;
if ( V_171 == V_11 -> V_78 )
V_11 -> V_67 -> V_74 = V_69 & 0xff ;
return 0 ;
}
static int F_86 ( struct V_170 * V_171 )
{
struct V_10 * V_11 = F_49 ( V_171 -> V_172 , struct V_10 , V_70 ) ;
switch ( V_171 -> V_173 ) {
case V_174 :
V_11 -> V_38 = V_171 -> V_74 ;
break;
default:
if ( V_171 == V_11 -> V_175 )
V_11 -> V_88 = 30 ;
break;
}
return 0 ;
}
static T_4
F_87 ( struct V_131 * V_131 , char T_5 * V_110 , T_6 V_129 , T_7 * V_176 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
int V_177 ;
F_18 ( V_11 , 1 , L_27 ) ;
F_14 ( & V_11 -> V_130 ) ;
V_177 = F_88 ( & V_11 -> V_156 , V_110 , V_129 , V_176 ,
V_131 -> V_161 & V_162 ) ;
F_15 ( & V_11 -> V_130 ) ;
return V_177 ;
}
static unsigned int
F_89 ( struct V_131 * V_131 , struct V_178 * V_105 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
struct V_117 * V_155 = & V_11 -> V_156 ;
F_18 ( V_11 , 1 , L_16 , V_107 ) ;
return F_90 ( V_155 , V_131 , V_105 ) ;
}
static int F_91 ( struct V_131 * V_131 )
{
struct V_179 * V_180 = F_92 ( V_131 ) ;
struct V_10 * V_11 = F_61 ( V_131 ) ;
F_18 ( V_11 , 1 , L_28 ,
F_93 ( V_180 ) , V_131 ) ;
if ( F_94 ( V_131 ) )
F_95 ( & V_11 -> V_156 ) ;
return F_96 ( V_131 ) ;
}
static int F_97 ( struct V_131 * V_131 , struct V_181 * V_182 )
{
struct V_10 * V_11 = F_61 ( V_131 ) ;
int V_157 ;
F_18 ( V_11 , 1 , L_29 , ( unsigned long ) V_182 ) ;
V_157 = F_98 ( & V_11 -> V_156 , V_182 ) ;
F_18 ( V_11 , 1 , L_30 ,
( unsigned long ) V_182 -> V_183 ,
( unsigned long ) V_182 -> V_184 - ( unsigned long ) V_182 -> V_183 ,
V_157 ) ;
return V_157 ;
}
static int F_99 ( void )
{
struct V_10 * V_11 ;
struct V_185 * V_101 ;
while ( ! F_20 ( & V_186 ) ) {
V_101 = V_186 . V_100 ;
F_23 ( V_101 ) ;
V_11 = F_22 ( V_101 , struct V_10 , V_186 ) ;
F_100 ( & V_11 -> V_114 , L_31 ,
F_93 ( V_11 -> V_187 ) ) ;
F_101 ( V_11 -> V_187 ) ;
F_102 ( & V_11 -> V_114 ) ;
F_103 ( & V_11 -> V_70 ) ;
F_104 ( V_11 ) ;
}
return 0 ;
}
static int T_8 F_105 ( int V_188 )
{
struct V_10 * V_11 ;
struct V_179 * V_187 ;
struct V_189 * V_190 ;
struct V_117 * V_155 ;
int V_157 ;
V_11 = F_106 ( sizeof( * V_11 ) , V_191 ) ;
if ( ! V_11 )
return - V_192 ;
snprintf ( V_11 -> V_114 . V_115 , sizeof( V_11 -> V_114 . V_115 ) ,
L_32 , V_193 , V_188 ) ;
V_157 = F_107 ( NULL , & V_11 -> V_114 ) ;
if ( V_157 )
goto V_194;
V_11 -> V_4 = & V_6 [ 0 ] ;
V_11 -> V_43 = 640 ;
V_11 -> V_48 = 480 ;
V_11 -> V_41 = V_11 -> V_4 -> V_147 / 8 ;
V_190 = & V_11 -> V_70 ;
F_108 ( V_190 , 11 ) ;
V_11 -> V_79 = F_109 ( V_190 , & V_195 ,
V_196 , 0 , 255 , 1 , 200 ) ;
V_11 -> V_72 = F_109 ( V_190 , & V_195 ,
V_197 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_75 = F_109 ( V_190 , & V_195 ,
V_198 , 0 , 255 , 1 , 16 ) ;
V_11 -> V_76 = F_109 ( V_190 , & V_195 ,
V_199 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_77 = F_109 ( V_190 , & V_195 ,
V_200 , - 128 , 127 , 1 , 0 ) ;
V_11 -> V_78 = F_109 ( V_190 , & V_195 ,
V_201 , 0 , 1 , 1 , 1 ) ;
V_11 -> V_67 = F_109 ( V_190 , & V_195 ,
V_202 , 0 , 255 , 1 , 100 ) ;
V_11 -> V_37 = F_109 ( V_190 , & V_195 ,
V_174 , 0 , 255 , 1 , 0 ) ;
V_11 -> V_175 = F_110 ( V_190 , & V_203 , NULL ) ;
V_11 -> V_80 = F_110 ( V_190 , & V_204 , NULL ) ;
V_11 -> V_81 = F_110 ( V_190 , & V_205 , NULL ) ;
V_11 -> boolean = F_110 ( V_190 , & V_206 , NULL ) ;
V_11 -> V_84 = F_110 ( V_190 , & V_207 , NULL ) ;
V_11 -> string = F_110 ( V_190 , & V_208 , NULL ) ;
V_11 -> V_83 = F_110 ( V_190 , & V_209 , NULL ) ;
V_11 -> V_86 = F_110 ( V_190 , & V_210 , NULL ) ;
if ( V_190 -> error ) {
V_157 = V_190 -> error ;
goto V_211;
}
F_111 ( 2 , & V_11 -> V_78 , 0 , true ) ;
V_11 -> V_114 . V_70 = V_190 ;
F_112 ( & V_11 -> V_98 ) ;
V_155 = & V_11 -> V_156 ;
memset ( V_155 , 0 , sizeof( V_11 -> V_156 ) ) ;
V_155 -> type = V_212 ;
V_155 -> V_213 = V_214 | V_215 | V_216 ;
V_155 -> V_217 = V_11 ;
V_155 -> V_218 = sizeof( struct V_57 ) ;
V_155 -> V_219 = & V_220 ;
V_155 -> V_221 = & V_222 ;
F_113 ( V_155 ) ;
F_114 ( & V_11 -> V_130 ) ;
F_115 ( & V_11 -> V_96 . V_99 ) ;
F_116 ( & V_11 -> V_96 . V_108 ) ;
V_157 = - V_192 ;
V_187 = F_117 () ;
if ( ! V_187 )
goto V_211;
* V_187 = V_223 ;
V_187 -> V_224 = V_224 ;
V_187 -> V_114 = & V_11 -> V_114 ;
F_118 ( V_225 , & V_187 -> V_97 ) ;
V_187 -> V_71 = & V_11 -> V_130 ;
V_157 = F_119 ( V_187 , V_226 , V_227 ) ;
if ( V_157 < 0 )
goto V_228;
F_120 ( V_187 , V_11 ) ;
F_55 ( & V_11 -> V_186 , & V_186 ) ;
if ( V_227 != - 1 )
V_227 ++ ;
V_11 -> V_187 = V_187 ;
F_100 ( & V_11 -> V_114 , L_33 ,
F_93 ( V_187 ) ) ;
return 0 ;
V_228:
F_121 ( V_187 ) ;
V_211:
F_103 ( V_190 ) ;
F_102 ( & V_11 -> V_114 ) ;
V_194:
F_104 ( V_11 ) ;
return V_157 ;
}
static int T_8 F_122 ( void )
{
const struct V_229 * V_230 = F_123 ( L_34 ) ;
int V_157 = 0 , V_54 ;
if ( V_230 == NULL ) {
F_124 ( V_231 L_35 ) ;
return - V_232 ;
}
V_53 = V_230 -> V_110 ;
if ( V_233 <= 0 )
V_233 = 1 ;
for ( V_54 = 0 ; V_54 < V_233 ; V_54 ++ ) {
V_157 = F_105 ( V_54 ) ;
if ( V_157 ) {
if ( V_54 )
V_157 = 0 ;
break;
}
}
if ( V_157 < 0 ) {
F_124 ( V_231 L_36 , V_157 ) ;
return V_157 ;
}
F_124 ( V_234 L_37
L_38 ,
V_235 ) ;
V_233 = V_54 ;
return V_157 ;
}
static void T_9 F_125 ( void )
{
F_99 () ;
}
