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
if ( ! V_52 )
return;
for ( V_56 = 0 ; V_56 < V_49 ; V_56 ++ )
memcpy ( V_52 + V_56 * V_48 * 2 , V_11 -> line + ( V_11 -> V_57 % V_48 ) * 2 , V_48 * 2 ) ;
V_11 -> V_54 += F_12 ( V_58 - V_11 -> V_58 ) ;
V_11 -> V_58 = V_58 ;
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
F_13 ( & V_11 -> V_59 . V_60 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_3 ,
V_11 -> V_61 -> V_62 . V_63 ,
V_11 -> V_64 -> V_62 . V_63 ,
V_11 -> V_65 -> V_62 . V_63 ,
V_11 -> V_66 -> V_62 . V_63 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_4 , V_11 -> V_67 -> V_62 . V_63 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_5 ,
V_11 -> V_68 -> V_62 . V_63 ,
V_11 -> V_69 -> V_62 . V_70 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
snprintf ( V_55 , sizeof( V_55 ) , L_6 ,
V_11 -> boolean -> V_62 . V_63 ,
V_11 -> V_71 -> V_72 [ V_11 -> V_71 -> V_62 . V_63 ] ,
V_11 -> string -> V_62 . string ) ;
F_14 ( & V_11 -> V_59 . V_60 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
if ( V_11 -> V_73 ) {
V_11 -> V_73 -- ;
snprintf ( V_55 , sizeof( V_55 ) , L_7 ) ;
F_9 ( V_11 , V_52 , line ++ * 16 , 16 , V_55 ) ;
}
V_11 -> V_57 += 2 ;
V_25 -> V_53 . V_74 . V_75 = V_11 -> V_75 ;
V_11 -> V_76 ++ ;
V_25 -> V_53 . V_74 . V_77 = V_11 -> V_76 >> 1 ;
F_15 ( & V_51 ) ;
V_25 -> V_53 . V_74 . V_78 = V_51 ;
}
static void F_16 ( struct V_10 * V_11 )
{
struct V_79 * V_80 = & V_11 -> V_81 ;
struct V_47 * V_25 ;
unsigned long V_82 = 0 ;
F_17 ( V_11 , 1 , L_8 ) ;
F_18 ( & V_11 -> V_83 , V_82 ) ;
if ( F_19 ( & V_80 -> V_84 ) ) {
F_17 ( V_11 , 1 , L_9 ) ;
goto V_85;
}
V_25 = F_20 ( V_80 -> V_84 . V_86 , struct V_47 , V_87 ) ;
F_21 ( & V_25 -> V_87 ) ;
F_15 ( & V_25 -> V_53 . V_74 . V_78 ) ;
F_10 ( V_11 , V_25 ) ;
F_17 ( V_11 , 1 , L_10 , V_25 ) ;
F_22 ( & V_25 -> V_53 , V_88 ) ;
F_17 ( V_11 , 2 , L_11 , V_25 , V_25 -> V_53 . V_74 . V_89 ) ;
V_85:
F_23 ( & V_11 -> V_83 , V_82 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_79 * V_80 = & V_11 -> V_81 ;
int V_90 ;
F_25 ( V_91 , V_92 ) ;
F_17 ( V_11 , 1 , L_12 , V_93 ,
( unsigned long ) V_80 ) ;
F_26 ( & V_80 -> V_94 , & V_91 ) ;
if ( F_27 () )
goto V_95;
V_90 = F_28 ( F_29 ( 1 ) ) ;
F_16 ( V_11 ) ;
F_30 ( V_90 ) ;
V_95:
F_31 ( & V_80 -> V_94 , & V_91 ) ;
F_32 () ;
}
static int F_33 ( void * V_96 )
{
struct V_10 * V_11 = V_96 ;
F_17 ( V_11 , 1 , L_13 ) ;
F_34 () ;
for (; ; ) {
F_24 ( V_11 ) ;
if ( F_27 () )
break;
}
F_17 ( V_11 , 1 , L_14 ) ;
return 0 ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_79 * V_80 = & V_11 -> V_81 ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
V_11 -> V_54 = 0 ;
V_11 -> V_57 = 0 ;
V_11 -> V_58 = V_58 ;
V_80 -> V_97 = 0 ;
V_80 -> V_98 = V_58 ;
V_80 -> V_99 = F_36 ( F_33 , V_11 , V_11 -> V_100 . V_101 ) ;
if ( F_37 ( V_80 -> V_99 ) ) {
F_38 ( & V_11 -> V_100 , L_16 ) ;
return F_39 ( V_80 -> V_99 ) ;
}
F_40 ( & V_80 -> V_94 ) ;
F_17 ( V_11 , 1 , L_17 , V_93 ) ;
return 0 ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_79 * V_80 = & V_11 -> V_81 ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
if ( V_80 -> V_99 ) {
F_42 ( V_80 -> V_99 ) ;
V_80 -> V_99 = NULL ;
}
while ( ! F_19 ( & V_80 -> V_84 ) ) {
struct V_47 * V_25 ;
V_25 = F_20 ( V_80 -> V_84 . V_86 , struct V_47 , V_87 ) ;
F_21 ( & V_25 -> V_87 ) ;
F_22 ( & V_25 -> V_53 , V_102 ) ;
F_17 ( V_11 , 2 , L_11 , V_25 , V_25 -> V_53 . V_74 . V_89 ) ;
}
}
static int F_43 ( struct V_103 * V_104 , unsigned int * V_105 ,
unsigned int * V_106 , unsigned long V_107 [] ,
void * V_108 [] )
{
struct V_10 * V_11 = F_44 ( V_104 ) ;
unsigned long V_109 ;
V_109 = V_11 -> V_33 * V_11 -> V_38 * 2 ;
if ( 0 == * V_105 )
* V_105 = 32 ;
while ( V_109 * * V_105 > V_110 * 1024 * 1024 )
( * V_105 ) -- ;
* V_106 = 1 ;
V_107 [ 0 ] = V_109 ;
F_17 ( V_11 , 1 , L_18 , V_93 ,
* V_105 , V_109 ) ;
return 0 ;
}
static int F_45 ( struct V_111 * V_53 )
{
struct V_10 * V_11 = F_44 ( V_53 -> V_103 ) ;
F_46 ( NULL == V_11 -> V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_111 * V_53 )
{
struct V_10 * V_11 = F_44 ( V_53 -> V_103 ) ;
struct V_47 * V_25 = F_48 ( V_53 , struct V_47 , V_53 ) ;
unsigned long V_109 ;
F_17 ( V_11 , 1 , L_19 , V_93 , V_53 -> V_74 . V_75 ) ;
F_46 ( NULL == V_11 -> V_4 ) ;
if ( V_11 -> V_33 < 48 || V_11 -> V_33 > V_112 ||
V_11 -> V_38 < 32 || V_11 -> V_38 > V_113 )
return - V_114 ;
V_109 = V_11 -> V_33 * V_11 -> V_38 * 2 ;
if ( F_49 ( V_53 , 0 ) < V_109 ) {
F_17 ( V_11 , 1 , L_20 ,
V_93 , F_49 ( V_53 , 0 ) , V_109 ) ;
return - V_114 ;
}
F_50 ( & V_25 -> V_53 , 0 , V_109 ) ;
V_25 -> V_4 = V_11 -> V_4 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_51 ( struct V_111 * V_53 )
{
struct V_10 * V_11 = F_44 ( V_53 -> V_103 ) ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
return 0 ;
}
static void F_52 ( struct V_111 * V_53 )
{
struct V_10 * V_11 = F_44 ( V_53 -> V_103 ) ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
}
static void F_53 ( struct V_111 * V_53 )
{
struct V_10 * V_11 = F_44 ( V_53 -> V_103 ) ;
struct V_47 * V_25 = F_48 ( V_53 , struct V_47 , V_53 ) ;
struct V_79 * V_81 = & V_11 -> V_81 ;
unsigned long V_82 = 0 ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
F_18 ( & V_11 -> V_83 , V_82 ) ;
F_54 ( & V_25 -> V_87 , & V_81 -> V_84 ) ;
F_23 ( & V_11 -> V_83 , V_82 ) ;
}
static int F_55 ( struct V_103 * V_104 )
{
struct V_10 * V_11 = F_44 ( V_104 ) ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
return F_35 ( V_11 ) ;
}
static int F_56 ( struct V_103 * V_104 )
{
struct V_10 * V_11 = F_44 ( V_104 ) ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
F_41 ( V_11 ) ;
return 0 ;
}
static void F_57 ( struct V_103 * V_104 )
{
struct V_10 * V_11 = F_44 ( V_104 ) ;
F_13 ( & V_11 -> V_115 ) ;
}
static void F_58 ( struct V_103 * V_104 )
{
struct V_10 * V_11 = F_44 ( V_104 ) ;
F_14 ( & V_11 -> V_115 ) ;
}
static int F_59 ( struct V_116 * V_116 , void * V_117 ,
struct V_118 * V_119 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
strcpy ( V_119 -> V_120 , L_21 ) ;
strcpy ( V_119 -> V_121 , L_21 ) ;
F_61 ( V_119 -> V_122 , V_11 -> V_100 . V_101 , sizeof( V_119 -> V_122 ) ) ;
V_119 -> V_123 = V_124 ;
V_119 -> V_125 = V_126 | V_127 | \
V_128 ;
return 0 ;
}
static int F_62 ( struct V_116 * V_116 , void * V_117 ,
struct V_129 * V_3 )
{
struct V_1 * V_4 ;
if ( V_3 -> V_89 >= F_2 ( V_6 ) )
return - V_114 ;
V_4 = & V_6 [ V_3 -> V_89 ] ;
F_61 ( V_3 -> V_130 , V_4 -> V_101 , sizeof( V_3 -> V_130 ) ) ;
V_3 -> V_9 = V_4 -> V_7 ;
return 0 ;
}
static int F_63 ( struct V_116 * V_116 , void * V_117 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
V_3 -> V_4 . V_8 . V_33 = V_11 -> V_33 ;
V_3 -> V_4 . V_8 . V_38 = V_11 -> V_38 ;
V_3 -> V_4 . V_8 . V_75 = V_11 -> V_75 ;
V_3 -> V_4 . V_8 . V_9 = V_11 -> V_4 -> V_7 ;
V_3 -> V_4 . V_8 . V_131 =
( V_3 -> V_4 . V_8 . V_33 * V_11 -> V_4 -> V_132 ) >> 3 ;
V_3 -> V_4 . V_8 . V_133 =
V_3 -> V_4 . V_8 . V_38 * V_3 -> V_4 . V_8 . V_131 ;
return 0 ;
}
static int F_64 ( struct V_116 * V_116 , void * V_117 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
struct V_1 * V_4 ;
enum V_134 V_75 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_17 ( V_11 , 1 , L_22 ,
V_3 -> V_4 . V_8 . V_9 ) ;
return - V_114 ;
}
V_75 = V_3 -> V_4 . V_8 . V_75 ;
if ( V_75 == V_135 ) {
V_75 = V_136 ;
} else if ( V_136 != V_75 ) {
F_17 ( V_11 , 1 , L_23 ) ;
return - V_114 ;
}
V_3 -> V_4 . V_8 . V_75 = V_75 ;
F_65 ( & V_3 -> V_4 . V_8 . V_33 , 48 , V_112 , 2 ,
& V_3 -> V_4 . V_8 . V_38 , 32 , V_113 , 0 , 0 ) ;
V_3 -> V_4 . V_8 . V_131 =
( V_3 -> V_4 . V_8 . V_33 * V_4 -> V_132 ) >> 3 ;
V_3 -> V_4 . V_8 . V_133 =
V_3 -> V_4 . V_8 . V_38 * V_3 -> V_4 . V_8 . V_131 ;
return 0 ;
}
static int F_66 ( struct V_116 * V_116 , void * V_117 ,
struct V_2 * V_3 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
struct V_103 * V_137 = & V_11 -> V_138 ;
int V_139 = F_64 ( V_116 , V_117 , V_3 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( F_67 ( V_137 ) ) {
F_17 ( V_11 , 1 , L_24 , V_93 ) ;
return - V_140 ;
}
V_11 -> V_4 = F_1 ( V_3 ) ;
V_11 -> V_33 = V_3 -> V_4 . V_8 . V_33 ;
V_11 -> V_38 = V_3 -> V_4 . V_8 . V_38 ;
V_11 -> V_75 = V_3 -> V_4 . V_8 . V_75 ;
return 0 ;
}
static int F_68 ( struct V_116 * V_116 , void * V_117 ,
struct V_141 * V_31 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
return F_69 ( & V_11 -> V_138 , V_31 ) ;
}
static int F_70 ( struct V_116 * V_116 , void * V_117 , struct V_142 * V_31 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
return F_71 ( & V_11 -> V_138 , V_31 ) ;
}
static int F_72 ( struct V_116 * V_116 , void * V_117 , struct V_142 * V_31 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
return F_73 ( & V_11 -> V_138 , V_31 ) ;
}
static int F_74 ( struct V_116 * V_116 , void * V_117 , struct V_142 * V_31 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
return F_75 ( & V_11 -> V_138 , V_31 , V_116 -> V_143 & V_144 ) ;
}
static int F_76 ( struct V_116 * V_116 , void * V_117 , enum V_145 V_44 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
return F_77 ( & V_11 -> V_138 , V_44 ) ;
}
static int F_78 ( struct V_116 * V_116 , void * V_117 , enum V_145 V_44 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
return F_79 ( & V_11 -> V_138 , V_44 ) ;
}
static int F_80 ( struct V_116 * V_116 , void * V_117 , T_2 * V_44 )
{
return 0 ;
}
static int F_81 ( struct V_116 * V_116 , void * V_117 ,
struct V_146 * V_147 )
{
if ( V_147 -> V_89 >= V_148 )
return - V_114 ;
V_147 -> type = V_149 ;
V_147 -> V_150 = V_151 ;
sprintf ( V_147 -> V_101 , L_25 , V_147 -> V_89 ) ;
return 0 ;
}
static int F_82 ( struct V_116 * V_116 , void * V_117 , unsigned int * V_44 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
* V_44 = V_11 -> V_17 ;
return 0 ;
}
static int F_83 ( struct V_116 * V_116 , void * V_117 , unsigned int V_44 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
if ( V_44 >= V_148 )
return - V_114 ;
V_11 -> V_17 = V_44 ;
F_3 ( V_11 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int F_84 ( struct V_152 * V_153 )
{
struct V_10 * V_11 = F_48 ( V_153 -> V_154 , struct V_10 , V_59 ) ;
if ( V_153 == V_11 -> V_155 )
V_11 -> V_73 = 30 ;
return 0 ;
}
static T_3
F_85 ( struct V_116 * V_116 , char T_4 * V_96 , T_5 V_156 , T_6 * V_157 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
F_17 ( V_11 , 1 , L_26 ) ;
return F_86 ( & V_11 -> V_138 , V_96 , V_156 , V_157 ,
V_116 -> V_143 & V_144 ) ;
}
static unsigned int
F_87 ( struct V_116 * V_116 , struct V_158 * V_91 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
struct V_103 * V_137 = & V_11 -> V_138 ;
F_17 ( V_11 , 1 , L_15 , V_93 ) ;
return F_88 ( V_137 , V_116 , V_91 ) ;
}
static int F_89 ( struct V_116 * V_116 )
{
struct V_159 * V_160 = F_90 ( V_116 ) ;
struct V_10 * V_11 = F_60 ( V_116 ) ;
F_17 ( V_11 , 1 , L_27 ,
F_91 ( V_160 ) , V_116 ) ;
if ( F_92 ( V_116 ) )
F_93 ( & V_11 -> V_138 ) ;
return F_94 ( V_116 ) ;
}
static int F_95 ( struct V_116 * V_116 , struct V_161 * V_162 )
{
struct V_10 * V_11 = F_60 ( V_116 ) ;
int V_139 ;
F_17 ( V_11 , 1 , L_28 , ( unsigned long ) V_162 ) ;
V_139 = F_96 ( & V_11 -> V_138 , V_162 ) ;
F_17 ( V_11 , 1 , L_29 ,
( unsigned long ) V_162 -> V_163 ,
( unsigned long ) V_162 -> V_164 - ( unsigned long ) V_162 -> V_163 ,
V_139 ) ;
return V_139 ;
}
static int F_97 ( void )
{
struct V_10 * V_11 ;
struct V_165 * V_87 ;
while ( ! F_19 ( & V_166 ) ) {
V_87 = V_166 . V_86 ;
F_21 ( V_87 ) ;
V_11 = F_20 ( V_87 , struct V_10 , V_166 ) ;
F_98 ( & V_11 -> V_100 , L_30 ,
F_91 ( V_11 -> V_167 ) ) ;
F_99 ( V_11 -> V_167 ) ;
F_100 ( & V_11 -> V_100 ) ;
F_101 ( & V_11 -> V_59 ) ;
F_102 ( V_11 ) ;
}
return 0 ;
}
static int T_7 F_103 ( int V_168 )
{
struct V_10 * V_11 ;
struct V_159 * V_167 ;
struct V_169 * V_170 ;
struct V_103 * V_137 ;
int V_139 ;
V_11 = F_104 ( sizeof( * V_11 ) , V_171 ) ;
if ( ! V_11 )
return - V_172 ;
snprintf ( V_11 -> V_100 . V_101 , sizeof( V_11 -> V_100 . V_101 ) ,
L_31 , V_173 , V_168 ) ;
V_139 = F_105 ( NULL , & V_11 -> V_100 ) ;
if ( V_139 )
goto V_174;
V_11 -> V_4 = & V_6 [ 0 ] ;
V_11 -> V_33 = 640 ;
V_11 -> V_38 = 480 ;
V_170 = & V_11 -> V_59 ;
F_106 ( V_170 , 11 ) ;
V_11 -> V_67 = F_107 ( V_170 , & V_175 ,
V_176 , 0 , 255 , 1 , 200 ) ;
V_11 -> V_61 = F_107 ( V_170 , & V_175 ,
V_177 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_64 = F_107 ( V_170 , & V_175 ,
V_178 , 0 , 255 , 1 , 16 ) ;
V_11 -> V_65 = F_107 ( V_170 , & V_175 ,
V_179 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_66 = F_107 ( V_170 , & V_175 ,
V_180 , - 128 , 127 , 1 , 0 ) ;
V_11 -> V_155 = F_108 ( V_170 , & V_181 , NULL ) ;
V_11 -> V_68 = F_108 ( V_170 , & V_182 , NULL ) ;
V_11 -> V_69 = F_108 ( V_170 , & V_183 , NULL ) ;
V_11 -> boolean = F_108 ( V_170 , & V_184 , NULL ) ;
V_11 -> V_71 = F_108 ( V_170 , & V_185 , NULL ) ;
V_11 -> string = F_108 ( V_170 , & V_186 , NULL ) ;
if ( V_170 -> error ) {
V_139 = V_170 -> error ;
goto V_187;
}
V_11 -> V_100 . V_59 = V_170 ;
F_109 ( & V_11 -> V_83 ) ;
V_137 = & V_11 -> V_138 ;
memset ( V_137 , 0 , sizeof( V_11 -> V_138 ) ) ;
V_137 -> type = V_188 ;
V_137 -> V_189 = V_190 | V_191 | V_192 ;
V_137 -> V_193 = V_11 ;
V_137 -> V_194 = sizeof( struct V_47 ) ;
V_137 -> V_195 = & V_196 ;
V_137 -> V_197 = & V_198 ;
F_110 ( V_137 ) ;
F_111 ( & V_11 -> V_115 ) ;
F_112 ( & V_11 -> V_81 . V_84 ) ;
F_113 ( & V_11 -> V_81 . V_94 ) ;
V_139 = - V_172 ;
V_167 = F_114 () ;
if ( ! V_167 )
goto V_187;
* V_167 = V_199 ;
V_167 -> V_200 = V_200 ;
V_167 -> V_100 = & V_11 -> V_100 ;
F_115 ( V_201 , & V_167 -> V_82 ) ;
V_167 -> V_60 = & V_11 -> V_115 ;
V_139 = F_116 ( V_167 , V_202 , V_203 ) ;
if ( V_139 < 0 )
goto V_204;
F_117 ( V_167 , V_11 ) ;
F_54 ( & V_11 -> V_166 , & V_166 ) ;
if ( V_203 != - 1 )
V_203 ++ ;
V_11 -> V_167 = V_167 ;
F_98 ( & V_11 -> V_100 , L_32 ,
F_91 ( V_167 ) ) ;
return 0 ;
V_204:
F_118 ( V_167 ) ;
V_187:
F_101 ( V_170 ) ;
F_100 ( & V_11 -> V_100 ) ;
V_174:
F_102 ( V_11 ) ;
return V_139 ;
}
static int T_7 F_119 ( void )
{
const struct V_205 * V_206 = F_120 ( L_33 ) ;
int V_139 = 0 , V_44 ;
if ( V_206 == NULL ) {
F_121 ( V_207 L_34 ) ;
return - V_208 ;
}
V_43 = V_206 -> V_96 ;
if ( V_209 <= 0 )
V_209 = 1 ;
for ( V_44 = 0 ; V_44 < V_209 ; V_44 ++ ) {
V_139 = F_103 ( V_44 ) ;
if ( V_139 ) {
if ( V_44 )
V_139 = 0 ;
break;
}
}
if ( V_139 < 0 ) {
F_121 ( V_207 L_35 , V_139 ) ;
return V_139 ;
}
F_121 ( V_210 L_36
L_37 ,
( V_124 >> 16 ) & 0xFF , ( V_124 >> 8 ) & 0xFF ,
V_124 & 0xFF ) ;
V_209 = V_44 ;
return V_139 ;
}
static void T_8 F_122 ( void )
{
F_97 () ;
}
