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
V_15 = 1 ;
break;
case V_21 :
case V_22 :
V_12 >>= 3 ;
V_13 >>= 2 ;
V_14 >>= 3 ;
break;
case V_23 :
case V_24 :
V_12 >>= 3 ;
V_13 >>= 3 ;
V_14 >>= 3 ;
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
static void F_7 ( struct V_10 * V_11 , T_1 * V_25 , int V_26 )
{
T_1 V_27 , V_28 , V_29 ;
int V_30 ;
T_1 * V_31 ;
V_27 = V_11 -> V_16 [ V_26 ] [ 0 ] ;
V_28 = V_11 -> V_16 [ V_26 ] [ 1 ] ;
V_29 = V_11 -> V_16 [ V_26 ] [ 2 ] ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
V_31 = V_25 + V_30 ;
switch ( V_11 -> V_4 -> V_7 ) {
case V_19 :
switch ( V_30 ) {
case 0 :
case 2 :
* V_31 = V_27 ;
break;
case 1 :
* V_31 = V_28 ;
break;
case 3 :
* V_31 = V_29 ;
break;
}
break;
case V_20 :
switch ( V_30 ) {
case 1 :
case 3 :
* V_31 = V_27 ;
break;
case 0 :
* V_31 = V_28 ;
break;
case 2 :
* V_31 = V_29 ;
break;
}
break;
case V_21 :
switch ( V_30 ) {
case 0 :
case 2 :
* V_31 = ( V_28 << 5 ) | V_29 ;
break;
case 1 :
case 3 :
* V_31 = ( V_27 << 3 ) | ( V_28 >> 3 ) ;
break;
}
break;
case V_22 :
switch ( V_30 ) {
case 0 :
case 2 :
* V_31 = ( V_27 << 3 ) | ( V_28 >> 3 ) ;
break;
case 1 :
case 3 :
* V_31 = ( V_28 << 5 ) | V_29 ;
break;
}
break;
case V_23 :
switch ( V_30 ) {
case 0 :
case 2 :
* V_31 = ( V_28 << 5 ) | V_29 ;
break;
case 1 :
case 3 :
* V_31 = ( V_27 << 2 ) | ( V_28 >> 3 ) ;
break;
}
break;
case V_24 :
switch ( V_30 ) {
case 0 :
case 2 :
* V_31 = ( V_27 << 2 ) | ( V_28 >> 3 ) ;
break;
case 1 :
case 3 :
* V_31 = ( V_28 << 5 ) | V_29 ;
break;
}
break;
}
}
}
static void F_8 ( struct V_10 * V_11 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_11 -> V_33 * 2 ; V_32 += 2 ) {
int V_26 = ( V_32 / ( V_11 -> V_33 / 8 ) % 8 ) ;
F_7 ( V_11 , V_11 -> line + V_32 * 2 , V_26 ) ;
}
}
static void F_9 ( struct V_10 * V_11 , char * V_34 ,
int V_35 , int V_36 , char * V_37 )
{
int line ;
if ( V_35 + 16 >= V_11 -> V_38 || V_36 + strlen ( V_37 ) * 8 >= V_11 -> V_33 )
return;
for ( line = V_35 ; line < V_35 + 16 ; line ++ ) {
int V_39 = 0 ;
char * V_40 = V_34 + line * V_11 -> V_33 * 2 + V_36 * 2 ;
char * V_41 ;
for ( V_41 = V_37 ; * V_41 ; V_41 ++ ) {
T_1 V_42 = V_43 [ * V_41 * 16 + line - V_35 ] ;
int V_44 ;
for ( V_44 = 0 ; V_44 < 7 ; V_44 ++ , V_39 ++ ) {
if ( V_42 & ( 1 << ( 7 - V_44 ) ) )
F_7 ( V_11 , V_40 + V_39 * 2 , V_45 ) ;
else
F_7 ( V_11 , V_40 + V_39 * 2 , V_46 ) ;
}
}
}
}
static void F_10 ( struct V_10 * V_11 , struct V_47 * V_25 )
{
int V_48 = V_11 -> V_33 ;
int V_49 = V_11 -> V_38 ;
struct V_50 V_51 ;
void * V_52 = F_11 ( & V_25 -> V_53 , 0 ) ;
unsigned V_54 ;
char V_55 [ 100 ] ;
int V_56 , line = 1 ;
T_2 V_57 ;
if ( ! V_52 )
return;
for ( V_56 = 0 ; V_56 < V_49 ; V_56 ++ )
memcpy ( V_52 + V_56 * V_48 * 2 , V_11 -> line + ( V_11 -> V_58 % V_48 ) * 2 , V_48 * 2 ) ;
V_11 -> V_54 += F_12 ( V_59 - V_11 -> V_59 ) ;
V_11 -> V_59 = V_59 ;
V_54 = V_11 -> V_54 ;
snprintf ( V_55 , sizeof( V_55 ) , L_1 ,
( V_54 / ( 60 * 60 * 1000 ) ) % 24 ,
( V_54 / ( 60 * 1000 ) ) % 60 ,
( V_54 / 1000 ) % 60 ,
V_54 % 1000 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_2 ,
V_11 -> V_33 , V_11 -> V_38 , V_11 -> V_17 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
V_57 = F_13 ( V_11 -> V_57 ) ;
F_14 ( & V_11 -> V_60 . V_61 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_3 ,
V_11 -> V_62 -> V_63 . V_64 ,
V_11 -> V_65 -> V_63 . V_64 ,
V_11 -> V_66 -> V_63 . V_64 ,
V_11 -> V_67 -> V_63 . V_64 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_4 ,
V_11 -> V_68 -> V_63 . V_64 , V_57 , V_11 -> V_69 -> V_63 . V_64 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_5 ,
V_11 -> V_70 -> V_63 . V_64 ,
V_11 -> V_71 -> V_63 . V_72 ,
V_11 -> V_73 -> V_63 . V_64 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_6 ,
V_11 -> boolean -> V_63 . V_64 ,
V_11 -> V_74 -> V_75 [ V_11 -> V_74 -> V_63 . V_64 ] ,
V_11 -> string -> V_63 . string ) ;
F_15 ( & V_11 -> V_60 . V_61 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
if ( V_11 -> V_76 ) {
V_11 -> V_76 -- ;
snprintf ( V_55 , sizeof( V_55 ) , L_7 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
}
V_11 -> V_58 += 2 ;
V_25 -> V_53 . V_77 . V_78 = V_11 -> V_78 ;
V_11 -> V_79 ++ ;
V_25 -> V_53 . V_77 . V_80 = V_11 -> V_79 >> 1 ;
F_16 ( & V_51 ) ;
V_25 -> V_53 . V_77 . V_81 = V_51 ;
}
static void F_17 ( struct V_10 * V_11 )
{
struct V_82 * V_83 = & V_11 -> V_84 ;
struct V_47 * V_25 ;
unsigned long V_85 = 0 ;
F_18 ( V_11 , 1 , L_8 ) ;
F_19 ( & V_11 -> V_86 , V_85 ) ;
if ( F_20 ( & V_83 -> V_87 ) ) {
F_18 ( V_11 , 1 , L_9 ) ;
F_21 ( & V_11 -> V_86 , V_85 ) ;
return;
}
V_25 = F_22 ( V_83 -> V_87 . V_88 , struct V_47 , V_89 ) ;
F_23 ( & V_25 -> V_89 ) ;
F_21 ( & V_11 -> V_86 , V_85 ) ;
F_16 ( & V_25 -> V_53 . V_77 . V_81 ) ;
F_10 ( V_11 , V_25 ) ;
F_18 ( V_11 , 1 , L_10 , V_25 ) ;
F_24 ( & V_25 -> V_53 , V_90 ) ;
F_18 ( V_11 , 2 , L_11 , V_25 , V_25 -> V_53 . V_77 . V_91 ) ;
}
static void F_25 ( struct V_10 * V_11 )
{
struct V_82 * V_83 = & V_11 -> V_84 ;
int V_92 ;
F_26 ( V_93 , V_94 ) ;
F_18 ( V_11 , 1 , L_12 , V_95 ,
( unsigned long ) V_83 ) ;
F_27 ( & V_83 -> V_96 , & V_93 ) ;
if ( F_28 () )
goto V_97;
V_92 = F_29 ( F_30 ( 1 ) ) ;
F_17 ( V_11 ) ;
F_31 ( V_92 ) ;
V_97:
F_32 ( & V_83 -> V_96 , & V_93 ) ;
F_33 () ;
}
static int F_34 ( void * V_98 )
{
struct V_10 * V_11 = V_98 ;
F_18 ( V_11 , 1 , L_13 ) ;
F_35 () ;
for (; ; ) {
F_25 ( V_11 ) ;
if ( F_28 () )
break;
}
F_18 ( V_11 , 1 , L_14 ) ;
return 0 ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_82 * V_83 = & V_11 -> V_84 ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
V_11 -> V_54 = 0 ;
V_11 -> V_58 = 0 ;
V_11 -> V_59 = V_59 ;
V_83 -> V_99 = 0 ;
V_83 -> V_100 = V_59 ;
V_83 -> V_101 = F_37 ( F_34 , V_11 , V_11 -> V_102 . V_103 ) ;
if ( F_38 ( V_83 -> V_101 ) ) {
F_39 ( & V_11 -> V_102 , L_16 ) ;
return F_40 ( V_83 -> V_101 ) ;
}
F_41 ( & V_83 -> V_96 ) ;
F_18 ( V_11 , 1 , L_17 , V_95 ) ;
return 0 ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_82 * V_83 = & V_11 -> V_84 ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
if ( V_83 -> V_101 ) {
F_43 ( V_83 -> V_101 ) ;
V_83 -> V_101 = NULL ;
}
while ( ! F_20 ( & V_83 -> V_87 ) ) {
struct V_47 * V_25 ;
V_25 = F_22 ( V_83 -> V_87 . V_88 , struct V_47 , V_89 ) ;
F_23 ( & V_25 -> V_89 ) ;
F_24 ( & V_25 -> V_53 , V_104 ) ;
F_18 ( V_11 , 2 , L_11 , V_25 , V_25 -> V_53 . V_77 . V_91 ) ;
}
}
static int F_44 ( struct V_105 * V_106 , const struct V_2 * V_4 ,
unsigned int * V_107 , unsigned int * V_108 ,
unsigned int V_109 [] , void * V_110 [] )
{
struct V_10 * V_11 = F_45 ( V_106 ) ;
unsigned long V_111 ;
V_111 = V_11 -> V_33 * V_11 -> V_38 * 2 ;
if ( 0 == * V_107 )
* V_107 = 32 ;
while ( V_111 * * V_107 > V_112 * 1024 * 1024 )
( * V_107 ) -- ;
* V_108 = 1 ;
V_109 [ 0 ] = V_111 ;
F_18 ( V_11 , 1 , L_18 , V_95 ,
* V_107 , V_111 ) ;
return 0 ;
}
static int F_46 ( struct V_113 * V_53 )
{
struct V_10 * V_11 = F_45 ( V_53 -> V_105 ) ;
F_47 ( NULL == V_11 -> V_4 ) ;
return 0 ;
}
static int F_48 ( struct V_113 * V_53 )
{
struct V_10 * V_11 = F_45 ( V_53 -> V_105 ) ;
struct V_47 * V_25 = F_49 ( V_53 , struct V_47 , V_53 ) ;
unsigned long V_111 ;
F_18 ( V_11 , 1 , L_19 , V_95 , V_53 -> V_77 . V_78 ) ;
F_47 ( NULL == V_11 -> V_4 ) ;
if ( V_11 -> V_33 < 48 || V_11 -> V_33 > V_114 ||
V_11 -> V_38 < 32 || V_11 -> V_38 > V_115 )
return - V_116 ;
V_111 = V_11 -> V_33 * V_11 -> V_38 * 2 ;
if ( F_50 ( V_53 , 0 ) < V_111 ) {
F_18 ( V_11 , 1 , L_20 ,
V_95 , F_50 ( V_53 , 0 ) , V_111 ) ;
return - V_116 ;
}
F_51 ( & V_25 -> V_53 , 0 , V_111 ) ;
V_25 -> V_4 = V_11 -> V_4 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_52 ( struct V_113 * V_53 )
{
struct V_10 * V_11 = F_45 ( V_53 -> V_105 ) ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
return 0 ;
}
static void F_53 ( struct V_113 * V_53 )
{
struct V_10 * V_11 = F_45 ( V_53 -> V_105 ) ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
}
static void F_54 ( struct V_113 * V_53 )
{
struct V_10 * V_11 = F_45 ( V_53 -> V_105 ) ;
struct V_47 * V_25 = F_49 ( V_53 , struct V_47 , V_53 ) ;
struct V_82 * V_84 = & V_11 -> V_84 ;
unsigned long V_85 = 0 ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
F_19 ( & V_11 -> V_86 , V_85 ) ;
F_55 ( & V_25 -> V_89 , & V_84 -> V_87 ) ;
F_21 ( & V_11 -> V_86 , V_85 ) ;
}
static int F_56 ( struct V_105 * V_106 , unsigned int V_117 )
{
struct V_10 * V_11 = F_45 ( V_106 ) ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
return F_36 ( V_11 ) ;
}
static int F_57 ( struct V_105 * V_106 )
{
struct V_10 * V_11 = F_45 ( V_106 ) ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
F_42 ( V_11 ) ;
return 0 ;
}
static void F_58 ( struct V_105 * V_106 )
{
struct V_10 * V_11 = F_45 ( V_106 ) ;
F_14 ( & V_11 -> V_118 ) ;
}
static void F_59 ( struct V_105 * V_106 )
{
struct V_10 * V_11 = F_45 ( V_106 ) ;
F_15 ( & V_11 -> V_118 ) ;
}
static int F_60 ( struct V_119 * V_119 , void * V_120 ,
struct V_121 * V_122 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
strcpy ( V_122 -> V_123 , L_21 ) ;
strcpy ( V_122 -> V_124 , L_21 ) ;
F_62 ( V_122 -> V_125 , V_11 -> V_102 . V_103 , sizeof( V_122 -> V_125 ) ) ;
V_122 -> V_126 = V_127 | V_128 | \
V_129 ;
return 0 ;
}
static int F_63 ( struct V_119 * V_119 , void * V_120 ,
struct V_130 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_91 >= F_2 ( V_6 ) )
return - V_116 ;
V_4 = & V_6 [ V_3 -> V_91 ] ;
F_62 ( V_3 -> V_131 , V_4 -> V_103 , sizeof( V_3 -> V_131 ) ) ;
V_3 -> V_9 = V_4 -> V_7 ;
return 0 ;
}
static int F_64 ( struct V_119 * V_119 , void * V_120 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
V_3 -> V_4 . V_8 . V_33 = V_11 -> V_33 ;
V_3 -> V_4 . V_8 . V_38 = V_11 -> V_38 ;
V_3 -> V_4 . V_8 . V_78 = V_11 -> V_78 ;
V_3 -> V_4 . V_8 . V_9 = V_11 -> V_4 -> V_7 ;
V_3 -> V_4 . V_8 . V_132 =
( V_3 -> V_4 . V_8 . V_33 * V_11 -> V_4 -> V_133 ) >> 3 ;
V_3 -> V_4 . V_8 . V_134 =
V_3 -> V_4 . V_8 . V_38 * V_3 -> V_4 . V_8 . V_132 ;
if ( V_11 -> V_4 -> V_7 == V_19 ||
V_11 -> V_4 -> V_7 == V_20 )
V_3 -> V_4 . V_8 . V_135 = V_136 ;
else
V_3 -> V_4 . V_8 . V_135 = V_137 ;
return 0 ;
}
static int F_65 ( struct V_119 * V_119 , void * V_120 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
struct V_1 * V_4 ;
enum V_138 V_78 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_18 ( V_11 , 1 , L_22 ,
V_3 -> V_4 . V_8 . V_9 ) ;
return - V_116 ;
}
V_78 = V_3 -> V_4 . V_8 . V_78 ;
if ( V_78 == V_139 ) {
V_78 = V_140 ;
} else if ( V_140 != V_78 ) {
F_18 ( V_11 , 1 , L_23 ) ;
return - V_116 ;
}
V_3 -> V_4 . V_8 . V_78 = V_78 ;
F_66 ( & V_3 -> V_4 . V_8 . V_33 , 48 , V_114 , 2 ,
& V_3 -> V_4 . V_8 . V_38 , 32 , V_115 , 0 , 0 ) ;
V_3 -> V_4 . V_8 . V_132 =
( V_3 -> V_4 . V_8 . V_33 * V_4 -> V_133 ) >> 3 ;
V_3 -> V_4 . V_8 . V_134 =
V_3 -> V_4 . V_8 . V_38 * V_3 -> V_4 . V_8 . V_132 ;
if ( V_4 -> V_7 == V_19 ||
V_4 -> V_7 == V_20 )
V_3 -> V_4 . V_8 . V_135 = V_136 ;
else
V_3 -> V_4 . V_8 . V_135 = V_137 ;
return 0 ;
}
static int F_67 ( struct V_119 * V_119 , void * V_120 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
struct V_105 * V_141 = & V_11 -> V_142 ;
int V_143 = F_65 ( V_119 , V_120 , V_3 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( F_68 ( V_141 ) ) {
F_18 ( V_11 , 1 , L_24 , V_95 ) ;
return - V_144 ;
}
V_11 -> V_4 = F_1 ( V_3 ) ;
V_11 -> V_33 = V_3 -> V_4 . V_8 . V_33 ;
V_11 -> V_38 = V_3 -> V_4 . V_8 . V_38 ;
V_11 -> V_78 = V_3 -> V_4 . V_8 . V_78 ;
return 0 ;
}
static int F_69 ( struct V_119 * V_119 , void * V_120 ,
struct V_145 * V_31 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
return F_70 ( & V_11 -> V_142 , V_31 ) ;
}
static int F_71 ( struct V_119 * V_119 , void * V_120 , struct V_146 * V_31 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
return F_72 ( & V_11 -> V_142 , V_31 ) ;
}
static int F_73 ( struct V_119 * V_119 , void * V_120 , struct V_146 * V_31 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
return F_74 ( & V_11 -> V_142 , V_31 ) ;
}
static int F_75 ( struct V_119 * V_119 , void * V_120 , struct V_146 * V_31 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
return F_76 ( & V_11 -> V_142 , V_31 , V_119 -> V_147 & V_148 ) ;
}
static int F_77 ( struct V_119 * V_119 , void * V_120 , enum V_149 V_44 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
return F_78 ( & V_11 -> V_142 , V_44 ) ;
}
static int F_79 ( struct V_119 * V_119 , void * V_120 , enum V_149 V_44 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
return F_80 ( & V_11 -> V_142 , V_44 ) ;
}
static int F_81 ( struct V_119 * V_119 , void * V_120 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
F_82 ( & V_11 -> V_60 , V_11 -> V_102 . V_103 ) ;
return 0 ;
}
static int F_83 ( struct V_119 * V_119 , void * V_120 , T_3 * V_44 )
{
return 0 ;
}
static int F_84 ( struct V_119 * V_119 , void * V_120 ,
struct V_150 * V_151 )
{
if ( V_151 -> V_91 >= V_152 )
return - V_116 ;
V_151 -> type = V_153 ;
V_151 -> V_154 = V_155 ;
sprintf ( V_151 -> V_103 , L_25 , V_151 -> V_91 ) ;
return 0 ;
}
static int F_85 ( struct V_119 * V_119 , void * V_120 , unsigned int * V_44 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
* V_44 = V_11 -> V_17 ;
return 0 ;
}
static int F_86 ( struct V_119 * V_119 , void * V_120 , unsigned int V_44 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
if ( V_44 >= V_152 )
return - V_116 ;
if ( V_44 == V_11 -> V_17 )
return 0 ;
V_11 -> V_17 = V_44 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_87 ( struct V_156 * V_157 ,
struct V_158 * V_159 )
{
switch ( V_159 -> type ) {
case V_160 :
return F_88 ( V_157 , V_159 , 0 ) ;
default:
return - V_116 ;
}
}
static int F_89 ( struct V_161 * V_162 )
{
struct V_10 * V_11 = F_49 ( V_162 -> V_163 , struct V_10 , V_60 ) ;
if ( V_162 == V_11 -> V_68 )
V_11 -> V_57 -> V_64 = V_59 & 0xff ;
return 0 ;
}
static int F_90 ( struct V_161 * V_162 )
{
struct V_10 * V_11 = F_49 ( V_162 -> V_163 , struct V_10 , V_60 ) ;
if ( V_162 == V_11 -> V_164 )
V_11 -> V_76 = 30 ;
return 0 ;
}
static T_4
F_91 ( struct V_119 * V_119 , char T_5 * V_98 , T_6 V_117 , T_7 * V_165 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
F_18 ( V_11 , 1 , L_26 ) ;
return F_92 ( & V_11 -> V_142 , V_98 , V_117 , V_165 ,
V_119 -> V_147 & V_148 ) ;
}
static unsigned int
F_93 ( struct V_119 * V_119 , struct V_166 * V_93 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
struct V_156 * V_157 = V_119 -> V_167 ;
struct V_105 * V_141 = & V_11 -> V_142 ;
unsigned int V_168 ;
F_18 ( V_11 , 1 , L_15 , V_95 ) ;
V_168 = F_94 ( V_141 , V_119 , V_93 ) ;
if ( F_95 ( V_157 ) )
V_168 |= V_169 ;
else
F_96 ( V_119 , & V_157 -> V_93 , V_93 ) ;
return V_168 ;
}
static int F_97 ( struct V_119 * V_119 )
{
struct V_170 * V_171 = F_98 ( V_119 ) ;
struct V_10 * V_11 = F_61 ( V_119 ) ;
F_18 ( V_11 , 1 , L_27 ,
F_99 ( V_171 ) , V_119 ) ;
if ( F_100 ( V_119 ) )
F_101 ( & V_11 -> V_142 ) ;
return F_102 ( V_119 ) ;
}
static int F_103 ( struct V_119 * V_119 , struct V_172 * V_173 )
{
struct V_10 * V_11 = F_61 ( V_119 ) ;
int V_143 ;
F_18 ( V_11 , 1 , L_28 , ( unsigned long ) V_173 ) ;
V_143 = F_104 ( & V_11 -> V_142 , V_173 ) ;
F_18 ( V_11 , 1 , L_29 ,
( unsigned long ) V_173 -> V_174 ,
( unsigned long ) V_173 -> V_175 - ( unsigned long ) V_173 -> V_174 ,
V_143 ) ;
return V_143 ;
}
static int F_105 ( void )
{
struct V_10 * V_11 ;
struct V_176 * V_89 ;
while ( ! F_20 ( & V_177 ) ) {
V_89 = V_177 . V_88 ;
F_23 ( V_89 ) ;
V_11 = F_22 ( V_89 , struct V_10 , V_177 ) ;
F_106 ( & V_11 -> V_102 , L_30 ,
F_99 ( V_11 -> V_178 ) ) ;
F_107 ( V_11 -> V_178 ) ;
F_108 ( & V_11 -> V_102 ) ;
F_109 ( & V_11 -> V_60 ) ;
F_110 ( V_11 ) ;
}
return 0 ;
}
static int T_8 F_111 ( int V_179 )
{
struct V_10 * V_11 ;
struct V_170 * V_178 ;
struct V_180 * V_181 ;
struct V_105 * V_141 ;
int V_143 ;
V_11 = F_112 ( sizeof( * V_11 ) , V_182 ) ;
if ( ! V_11 )
return - V_183 ;
snprintf ( V_11 -> V_102 . V_103 , sizeof( V_11 -> V_102 . V_103 ) ,
L_31 , V_184 , V_179 ) ;
V_143 = F_113 ( NULL , & V_11 -> V_102 ) ;
if ( V_143 )
goto V_185;
V_11 -> V_4 = & V_6 [ 0 ] ;
V_11 -> V_33 = 640 ;
V_11 -> V_38 = 480 ;
V_181 = & V_11 -> V_60 ;
F_114 ( V_181 , 11 ) ;
V_11 -> V_69 = F_115 ( V_181 , & V_186 ,
V_187 , 0 , 255 , 1 , 200 ) ;
V_11 -> V_62 = F_115 ( V_181 , & V_186 ,
V_188 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_65 = F_115 ( V_181 , & V_186 ,
V_189 , 0 , 255 , 1 , 16 ) ;
V_11 -> V_66 = F_115 ( V_181 , & V_186 ,
V_190 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_67 = F_115 ( V_181 , & V_186 ,
V_191 , - 128 , 127 , 1 , 0 ) ;
V_11 -> V_68 = F_115 ( V_181 , & V_186 ,
V_192 , 0 , 1 , 1 , 1 ) ;
V_11 -> V_57 = F_115 ( V_181 , & V_186 ,
V_193 , 0 , 255 , 1 , 100 ) ;
V_11 -> V_164 = F_116 ( V_181 , & V_194 , NULL ) ;
V_11 -> V_70 = F_116 ( V_181 , & V_195 , NULL ) ;
V_11 -> V_71 = F_116 ( V_181 , & V_196 , NULL ) ;
V_11 -> boolean = F_116 ( V_181 , & V_197 , NULL ) ;
V_11 -> V_74 = F_116 ( V_181 , & V_198 , NULL ) ;
V_11 -> string = F_116 ( V_181 , & V_199 , NULL ) ;
V_11 -> V_73 = F_116 ( V_181 , & V_200 , NULL ) ;
if ( V_181 -> error ) {
V_143 = V_181 -> error ;
goto V_201;
}
F_117 ( 2 , & V_11 -> V_68 , 0 , true ) ;
V_11 -> V_102 . V_60 = V_181 ;
F_118 ( & V_11 -> V_86 ) ;
V_141 = & V_11 -> V_142 ;
memset ( V_141 , 0 , sizeof( V_11 -> V_142 ) ) ;
V_141 -> type = V_202 ;
V_141 -> V_203 = V_204 | V_205 | V_206 ;
V_141 -> V_207 = V_11 ;
V_141 -> V_208 = sizeof( struct V_47 ) ;
V_141 -> V_209 = & V_210 ;
V_141 -> V_211 = & V_212 ;
F_119 ( V_141 ) ;
F_120 ( & V_11 -> V_118 ) ;
F_121 ( & V_11 -> V_84 . V_87 ) ;
F_122 ( & V_11 -> V_84 . V_96 ) ;
V_143 = - V_183 ;
V_178 = F_123 () ;
if ( ! V_178 )
goto V_201;
* V_178 = V_213 ;
V_178 -> V_214 = V_214 ;
V_178 -> V_102 = & V_11 -> V_102 ;
F_124 ( V_215 , & V_178 -> V_85 ) ;
V_178 -> V_61 = & V_11 -> V_118 ;
V_143 = F_125 ( V_178 , V_216 , V_217 ) ;
if ( V_143 < 0 )
goto V_218;
F_126 ( V_178 , V_11 ) ;
F_55 ( & V_11 -> V_177 , & V_177 ) ;
if ( V_217 != - 1 )
V_217 ++ ;
V_11 -> V_178 = V_178 ;
F_106 ( & V_11 -> V_102 , L_32 ,
F_99 ( V_178 ) ) ;
return 0 ;
V_218:
F_127 ( V_178 ) ;
V_201:
F_109 ( V_181 ) ;
F_108 ( & V_11 -> V_102 ) ;
V_185:
F_110 ( V_11 ) ;
return V_143 ;
}
static int T_8 F_128 ( void )
{
const struct V_219 * V_220 = F_129 ( L_33 ) ;
int V_143 = 0 , V_44 ;
if ( V_220 == NULL ) {
F_130 ( V_221 L_34 ) ;
return - V_222 ;
}
V_43 = V_220 -> V_98 ;
if ( V_223 <= 0 )
V_223 = 1 ;
for ( V_44 = 0 ; V_44 < V_223 ; V_44 ++ ) {
V_143 = F_111 ( V_44 ) ;
if ( V_143 ) {
if ( V_44 )
V_143 = 0 ;
break;
}
}
if ( V_143 < 0 ) {
F_130 ( V_221 L_35 , V_143 ) ;
return V_143 ;
}
F_130 ( V_224 L_36
L_37 ,
V_225 ) ;
V_223 = V_44 ;
return V_143 ;
}
static void T_9 F_131 ( void )
{
F_105 () ;
}
