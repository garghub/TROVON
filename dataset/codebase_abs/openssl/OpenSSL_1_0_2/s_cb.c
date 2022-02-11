int T_1 F_1 ( int V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
int V_4 , V_5 ;
V_3 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_2 ) ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_6 || ! V_1 ) {
F_5 ( V_7 , L_1 , V_5 ) ;
if ( V_3 ) {
F_6 ( V_7 ,
F_7 ( V_3 ) ,
0 , V_8 ) ;
F_8 ( V_7 , L_2 ) ;
} else
F_8 ( V_7 , L_3 ) ;
}
if ( ! V_1 ) {
F_5 ( V_7 , L_4 , V_4 ,
F_9 ( V_4 ) ) ;
if ( V_9 >= V_5 ) {
if ( ! V_10 )
V_1 = 1 ;
V_11 = V_12 ;
} else {
V_1 = 0 ;
V_11 = V_13 ;
}
}
switch ( V_4 ) {
case V_14 :
F_8 ( V_7 , L_5 ) ;
F_6 ( V_7 , F_10 ( V_3 ) ,
0 , V_8 ) ;
F_8 ( V_7 , L_2 ) ;
break;
case V_15 :
case V_16 :
F_5 ( V_7 , L_6 ) ;
F_11 ( V_7 , F_12 ( V_3 ) ) ;
F_5 ( V_7 , L_2 ) ;
break;
case V_17 :
case V_18 :
F_5 ( V_7 , L_7 ) ;
F_11 ( V_7 , F_13 ( V_3 ) ) ;
F_5 ( V_7 , L_2 ) ;
break;
case V_19 :
if ( ! V_6 )
F_14 ( V_7 , V_2 ) ;
break;
}
if ( V_4 == V_12 && V_1 == 2 && ! V_6 )
F_14 ( V_7 , V_2 ) ;
if ( V_1 && ! V_6 )
F_5 ( V_7 , L_8 , V_1 ) ;
return ( V_1 ) ;
}
int F_15 ( T_4 * V_2 , char * V_20 , char * V_21 )
{
if ( V_20 != NULL ) {
if ( F_16 ( V_2 , V_20 ,
V_22 ) <= 0 ) {
F_5 ( V_7 , L_9 ,
V_20 ) ;
F_17 ( V_7 ) ;
return ( 0 ) ;
}
if ( V_21 == NULL )
V_21 = V_20 ;
if ( F_18 ( V_2 , V_21 , V_22 ) <= 0 ) {
F_5 ( V_7 , L_10 ,
V_21 ) ;
F_17 ( V_7 ) ;
return ( 0 ) ;
}
if ( ! F_19 ( V_2 ) ) {
F_5 ( V_7 ,
L_11 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
static void F_20 ( T_5 * V_23 , T_6 * V_24 )
{
const unsigned char * V_25 ;
int V_26 ;
int V_27 = F_21 ( V_24 , & V_25 ) ;
if ( ! V_27 )
return;
F_8 ( V_23 , L_12 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
unsigned char V_28 = V_25 [ V_26 ] ;
char * V_29 ;
switch ( V_28 ) {
case V_30 :
V_29 = L_13 ;
break;
case V_31 :
V_29 = L_14 ;
break;
case V_32 :
V_29 = L_15 ;
break;
case V_33 :
V_29 = L_16 ;
break;
case V_34 :
V_29 = L_17 ;
break;
case V_35 :
V_29 = L_18 ;
break;
case V_36 :
V_29 = L_19 ;
break;
case V_37 :
V_29 = L_20 ;
break;
case V_38 :
V_29 = L_21 ;
break;
default:
V_29 = NULL ;
}
if ( V_26 )
F_8 ( V_23 , L_22 ) ;
if ( V_29 )
F_8 ( V_23 , V_29 ) ;
else
F_5 ( V_23 , L_23 , V_28 ) ;
}
F_8 ( V_23 , L_2 ) ;
}
static int F_22 ( T_5 * V_39 , T_6 * V_24 , int V_40 )
{
int V_26 , V_41 , V_42 ;
V_42 = F_23 ( V_24 ) ? 0 : 1 ;
if ( V_40 )
V_41 = F_24 ( V_24 , - 1 , NULL , NULL , NULL , NULL , NULL ) ;
else
V_41 = F_25 ( V_24 , - 1 , NULL , NULL , NULL , NULL , NULL ) ;
if ( V_41 == 0 )
return 1 ;
if ( V_40 )
F_8 ( V_39 , L_24 ) ;
if ( V_42 )
F_8 ( V_39 , L_25 ) ;
F_8 ( V_39 , L_26 ) ;
for ( V_26 = 0 ; V_26 < V_41 ; V_26 ++ ) {
int V_43 , V_44 ;
unsigned char V_45 , V_46 ;
const char * V_47 = NULL ;
if ( V_40 )
F_24 ( V_24 , V_26 , & V_44 , & V_43 , NULL ,
& V_46 , & V_45 ) ;
else
F_25 ( V_24 , V_26 , & V_44 , & V_43 , NULL , & V_46 , & V_45 ) ;
if ( V_26 )
F_8 ( V_39 , L_27 ) ;
if ( V_44 == V_48 )
V_47 = L_28 ;
else if ( V_44 == V_49 )
V_47 = L_29 ;
else if ( V_44 == V_50 )
V_47 = L_30 ;
if ( V_47 )
F_5 ( V_39 , L_31 , V_47 ) ;
else
F_5 ( V_39 , L_32 , ( int ) V_46 ) ;
if ( V_43 != V_51 )
F_5 ( V_39 , L_33 , F_26 ( V_43 ) ) ;
else
F_5 ( V_39 , L_34 , ( int ) V_45 ) ;
}
F_8 ( V_39 , L_2 ) ;
return 1 ;
}
int F_27 ( T_5 * V_39 , T_6 * V_24 )
{
int V_52 ;
if ( ! F_23 ( V_24 ) )
F_20 ( V_39 , V_24 ) ;
F_22 ( V_39 , V_24 , 0 ) ;
F_22 ( V_39 , V_24 , 1 ) ;
if ( F_28 ( V_24 , & V_52 ) )
F_5 ( V_39 , L_35 , F_26 ( V_52 ) ) ;
return 1 ;
}
int F_29 ( T_5 * V_39 , T_6 * V_24 )
{
int V_26 , V_53 ;
const char * V_54 ;
V_53 = F_30 ( V_24 , & V_54 ) ;
if ( V_53 <= 0 )
return 1 ;
F_8 ( V_39 , L_36 ) ;
for ( V_26 = 0 ; V_26 < V_53 ; V_26 ++ , V_54 ++ ) {
if ( V_26 )
F_8 ( V_39 , L_27 ) ;
switch ( * V_54 ) {
case V_55 :
F_8 ( V_39 , L_37 ) ;
break;
case V_56 :
F_8 ( V_39 , L_38 ) ;
break;
case V_57 :
F_8 ( V_39 , L_39 ) ;
break;
default:
F_5 ( V_39 , L_40 , ( int ) * V_54 ) ;
break;
}
}
if ( V_53 <= 0 )
F_8 ( V_39 , L_41 ) ;
F_8 ( V_39 , L_2 ) ;
return 1 ;
}
int F_31 ( T_5 * V_39 , T_6 * V_24 , int V_58 )
{
int V_26 , V_59 , * V_60 , V_61 ;
const char * V_29 ;
V_59 = F_32 ( V_24 , NULL ) ;
if ( V_59 <= 0 )
return 1 ;
V_60 = F_33 ( V_59 * sizeof( int ) ) ;
F_32 ( V_24 , V_60 ) ;
F_8 ( V_39 , L_42 ) ;
for ( V_26 = 0 ; V_26 < V_59 ; V_26 ++ ) {
if ( V_26 )
F_8 ( V_39 , L_27 ) ;
V_61 = V_60 [ V_26 ] ;
if ( V_61 & V_62 )
F_5 ( V_39 , L_43 , V_61 & 0xFFFF ) ;
else {
V_29 = F_34 ( V_61 ) ;
if ( ! V_29 )
V_29 = F_26 ( V_61 ) ;
F_5 ( V_39 , L_33 , V_29 ) ;
}
}
if ( V_59 == 0 )
F_8 ( V_39 , L_41 ) ;
F_35 ( V_60 ) ;
if ( V_58 ) {
F_8 ( V_39 , L_2 ) ;
return 1 ;
}
F_8 ( V_39 , L_44 ) ;
V_59 = F_36 ( V_24 , - 1 ) ;
for ( V_26 = 0 ; V_26 < V_59 ; V_26 ++ ) {
if ( V_26 )
F_8 ( V_39 , L_27 ) ;
V_61 = F_36 ( V_24 , V_26 ) ;
V_29 = F_34 ( V_61 ) ;
if ( ! V_29 )
V_29 = F_26 ( V_61 ) ;
F_5 ( V_39 , L_33 , V_29 ) ;
}
if ( V_59 == 0 )
F_8 ( V_39 , L_41 ) ;
F_8 ( V_39 , L_2 ) ;
return 1 ;
}
int F_37 ( T_5 * V_39 , T_6 * V_24 )
{
T_7 * V_63 ;
if ( ! F_38 ( V_24 , & V_63 ) )
return 1 ;
F_8 ( V_39 , L_45 ) ;
switch ( F_39 ( V_63 ) ) {
case V_48 :
F_5 ( V_39 , L_46 , F_40 ( V_63 ) ) ;
break;
case V_64 :
F_5 ( V_39 , L_47 , F_40 ( V_63 ) ) ;
break;
#ifndef F_41
case V_50 :
{
T_8 * V_65 = F_42 ( V_63 ) ;
int V_61 ;
const char * V_29 ;
V_61 = F_43 ( F_44 ( V_65 ) ) ;
F_45 ( V_65 ) ;
V_29 = F_34 ( V_61 ) ;
if ( ! V_29 )
V_29 = F_26 ( V_61 ) ;
F_5 ( V_39 , L_48 , V_29 , F_40 ( V_63 ) ) ;
}
#endif
}
F_46 ( V_63 ) ;
return 1 ;
}
long T_1 F_47 ( T_5 * V_23 , int V_66 , const char * V_67 ,
int V_68 , long V_69 , long V_70 )
{
T_5 * V_39 ;
V_39 = ( T_5 * ) F_48 ( V_23 ) ;
if ( V_39 == NULL )
return ( V_70 ) ;
if ( V_66 == ( V_71 | V_72 ) ) {
F_5 ( V_39 , L_49 ,
( void * ) V_23 , V_67 , ( unsigned long ) V_68 , V_70 , V_70 ) ;
F_49 ( V_39 , V_67 , ( int ) V_70 ) ;
return ( V_70 ) ;
} else if ( V_66 == ( V_73 | V_72 ) ) {
F_5 ( V_39 , L_50 ,
( void * ) V_23 , V_67 , ( unsigned long ) V_68 , V_70 , V_70 ) ;
F_49 ( V_39 , V_67 , ( int ) V_70 ) ;
}
return ( V_70 ) ;
}
void T_1 F_50 ( const T_6 * V_24 , int V_74 , int V_70 )
{
const char * V_75 ;
int V_76 ;
V_76 = V_74 & ~ V_77 ;
if ( V_76 & V_78 )
V_75 = L_51 ;
else if ( V_76 & V_79 )
V_75 = L_52 ;
else
V_75 = L_53 ;
if ( V_74 & V_80 ) {
F_5 ( V_7 , L_54 , V_75 , F_51 ( V_24 ) ) ;
} else if ( V_74 & V_81 ) {
V_75 = ( V_74 & V_82 ) ? L_55 : L_56 ;
F_5 ( V_7 , L_57 ,
V_75 ,
F_52 ( V_70 ) ,
F_53 ( V_70 ) ) ;
} else if ( V_74 & V_83 ) {
if ( V_70 == 0 )
F_5 ( V_7 , L_58 ,
V_75 , F_51 ( V_24 ) ) ;
else if ( V_70 < 0 ) {
F_5 ( V_7 , L_59 ,
V_75 , F_51 ( V_24 ) ) ;
}
}
}
void T_1 F_54 ( int V_84 , int V_85 , int V_86 ,
const void * V_87 , T_9 V_88 , T_6 * V_89 , void * V_90 )
{
T_5 * V_23 = V_90 ;
const char * V_91 , * V_92 , * V_93 =
L_60 , * V_94 = L_60 , * V_95 = L_60 ;
V_91 = V_84 ? L_61 : L_62 ;
switch ( V_85 ) {
case V_96 :
V_92 = L_63 ;
break;
case V_97 :
V_92 = L_64 ;
break;
case V_98 :
V_92 = L_65 ;
break;
case V_99 :
V_92 = L_66 ;
break;
case V_100 :
V_92 = L_67 ;
break;
case V_101 :
V_92 = L_68 ;
break;
case V_102 :
V_92 = L_69 ;
break;
default:
V_92 = L_70 ;
}
if ( V_85 == V_96 ) {
V_94 = L_70 ;
if ( V_88 > 0 ) {
switch ( ( ( const unsigned char * ) V_87 ) [ 0 ] ) {
case 0 :
V_94 = L_71 ;
V_95 = L_72 ;
if ( V_88 >= 3 ) {
unsigned V_4 =
( ( ( const unsigned char * ) V_87 ) [ 1 ] << 8 ) +
( ( const unsigned char * ) V_87 ) [ 2 ] ;
switch ( V_4 ) {
case 0x0001 :
V_95 = L_73 ;
break;
case 0x0002 :
V_95 = L_74 ;
break;
case 0x0004 :
V_95 = L_75 ;
break;
case 0x0006 :
V_95 = L_76 ;
break;
}
}
break;
case 1 :
V_94 = L_77 ;
break;
case 2 :
V_94 = L_78 ;
break;
case 3 :
V_94 = L_79 ;
break;
case 4 :
V_94 = L_80 ;
break;
case 5 :
V_94 = L_81 ;
break;
case 6 :
V_94 = L_82 ;
break;
case 7 :
V_94 = L_83 ;
break;
case 8 :
V_94 = L_84 ;
break;
}
}
}
if ( V_85 == V_97 ||
V_85 == V_98 ||
V_85 == V_99 ||
V_85 == V_100 ||
V_85 == V_101 || V_85 == V_102 ) {
switch ( V_86 ) {
case 20 :
V_93 = L_85 ;
break;
case 21 :
V_93 = L_86 ;
break;
case 22 :
V_93 = L_87 ;
break;
}
if ( V_86 == 21 ) {
V_94 = L_88 ;
if ( V_88 == 2 ) {
switch ( ( ( const unsigned char * ) V_87 ) [ 0 ] ) {
case 1 :
V_94 = L_89 ;
break;
case 2 :
V_94 = L_90 ;
break;
}
V_95 = L_72 ;
switch ( ( ( const unsigned char * ) V_87 ) [ 1 ] ) {
case 0 :
V_95 = L_91 ;
break;
case 10 :
V_95 = L_92 ;
break;
case 20 :
V_95 = L_93 ;
break;
case 21 :
V_95 = L_94 ;
break;
case 22 :
V_95 = L_95 ;
break;
case 30 :
V_95 = L_96 ;
break;
case 40 :
V_95 = L_97 ;
break;
case 42 :
V_95 = L_98 ;
break;
case 43 :
V_95 = L_99 ;
break;
case 44 :
V_95 = L_100 ;
break;
case 45 :
V_95 = L_101 ;
break;
case 46 :
V_95 = L_102 ;
break;
case 47 :
V_95 = L_103 ;
break;
case 48 :
V_95 = L_104 ;
break;
case 49 :
V_95 = L_105 ;
break;
case 50 :
V_95 = L_106 ;
break;
case 51 :
V_95 = L_107 ;
break;
case 60 :
V_95 = L_108 ;
break;
case 70 :
V_95 = L_109 ;
break;
case 71 :
V_95 = L_110 ;
break;
case 80 :
V_95 = L_111 ;
break;
case 90 :
V_95 = L_112 ;
break;
case 100 :
V_95 = L_113 ;
break;
case 110 :
V_95 = L_114 ;
break;
case 111 :
V_95 = L_115 ;
break;
case 112 :
V_95 = L_116 ;
break;
case 113 :
V_95 = L_117 ;
break;
case 114 :
V_95 = L_118 ;
break;
case 115 :
V_95 = L_119 ;
break;
}
}
}
if ( V_86 == 22 ) {
V_94 = L_70 ;
if ( V_88 > 0 ) {
switch ( ( ( const unsigned char * ) V_87 ) [ 0 ] ) {
case 0 :
V_94 = L_120 ;
break;
case 1 :
V_94 = L_121 ;
break;
case 2 :
V_94 = L_122 ;
break;
case 3 :
V_94 = L_123 ;
break;
case 11 :
V_94 = L_124 ;
break;
case 12 :
V_94 = L_125 ;
break;
case 13 :
V_94 = L_126 ;
break;
case 14 :
V_94 = L_127 ;
break;
case 15 :
V_94 = L_128 ;
break;
case 16 :
V_94 = L_129 ;
break;
case 20 :
V_94 = L_130 ;
break;
}
}
}
#ifndef F_55
if ( V_86 == 24 ) {
V_94 = L_131 ;
if ( V_88 > 0 ) {
switch ( ( ( const unsigned char * ) V_87 ) [ 0 ] ) {
case 1 :
V_94 = L_132 ;
break;
case 2 :
V_94 = L_133 ;
break;
}
}
}
#endif
}
F_5 ( V_23 , L_134 , V_91 , V_92 ,
V_93 , ( unsigned long ) V_88 , V_94 ,
V_95 ) ;
if ( V_88 > 0 ) {
T_9 V_103 , V_26 ;
F_5 ( V_23 , L_135 ) ;
V_103 = V_88 ;
#if 0
if (num > 16)
num = 16;
#endif
for ( V_26 = 0 ; V_26 < V_103 ; V_26 ++ ) {
if ( V_26 % 16 == 0 && V_26 > 0 )
F_5 ( V_23 , L_136 ) ;
F_5 ( V_23 , L_137 , ( ( const unsigned char * ) V_87 ) [ V_26 ] ) ;
}
if ( V_26 < V_88 )
F_5 ( V_23 , L_138 ) ;
F_5 ( V_23 , L_2 ) ;
}
( void ) F_56 ( V_23 ) ;
}
void T_1 F_57 ( T_6 * V_24 , int V_104 , int type ,
unsigned char * V_105 , int V_88 , void * V_90 )
{
T_5 * V_23 = V_90 ;
char * V_106 ;
switch ( type ) {
case V_107 :
V_106 = L_139 ;
break;
case V_108 :
V_106 = L_140 ;
break;
case V_109 :
V_106 = L_141 ;
break;
case V_110 :
V_106 = L_142 ;
break;
case V_111 :
V_106 = L_143 ;
break;
case V_112 :
V_106 = L_144 ;
break;
case V_113 :
V_106 = L_145 ;
break;
case V_114 :
V_106 = L_146 ;
break;
case V_115 :
V_106 = L_147 ;
break;
case V_116 :
V_106 = L_148 ;
break;
case V_117 :
V_106 = L_149 ;
break;
case V_118 :
V_106 = L_150 ;
break;
case V_119 :
V_106 = L_151 ;
break;
case V_120 :
V_106 = L_152 ;
break;
case V_121 :
V_106 = L_153 ;
break;
case V_122 :
V_106 = L_154 ;
break;
case V_123 :
V_106 = L_155 ;
break;
case V_124 :
V_106 = L_156 ;
break;
#ifdef F_58
case F_58 :
V_106 = L_157 ;
break;
#endif
#ifdef F_59
case F_59 :
V_106 = L_158 ;
break;
#endif
case V_125 :
V_106 = L_159 ;
break;
default:
V_106 = L_160 ;
break;
}
F_5 ( V_23 , L_161 ,
V_104 ? L_162 : L_163 , V_106 , type , V_88 ) ;
F_49 ( V_23 , ( char * ) V_105 , V_88 ) ;
( void ) F_56 ( V_23 ) ;
}
int T_1 F_60 ( T_6 * V_89 , unsigned char * V_126 ,
unsigned int * V_127 )
{
unsigned char * V_128 , V_129 [ V_130 ] ;
unsigned int V_131 , V_132 ;
union {
struct V_133 V_134 ;
struct V_135 V_136 ;
#if V_137
struct V_138 V_139 ;
#endif
} V_140 ;
if ( ! V_141 ) {
if ( ! F_61 ( V_142 , V_143 ) ) {
F_5 ( V_7 , L_164 ) ;
return 0 ;
}
V_141 = 1 ;
}
( void ) F_62 ( F_63 ( V_89 ) , & V_140 ) ;
V_131 = 0 ;
switch ( V_140 . V_134 . V_144 ) {
case V_145 :
V_131 += sizeof( struct V_146 ) ;
V_131 += sizeof( V_140 . V_136 . V_147 ) ;
break;
#if V_137
case V_148 :
V_131 += sizeof( struct V_149 ) ;
V_131 += sizeof( V_140 . V_139 . V_150 ) ;
break;
#endif
default:
F_64 ( 0 ) ;
break;
}
V_128 = F_33 ( V_131 ) ;
if ( V_128 == NULL ) {
F_5 ( V_7 , L_165 ) ;
return 0 ;
}
switch ( V_140 . V_134 . V_144 ) {
case V_145 :
memcpy ( V_128 , & V_140 . V_136 . V_147 , sizeof( V_140 . V_136 . V_147 ) ) ;
memcpy ( V_128 + sizeof( V_140 . V_136 . V_147 ) ,
& V_140 . V_136 . V_151 , sizeof( struct V_146 ) ) ;
break;
#if V_137
case V_148 :
memcpy ( V_128 , & V_140 . V_139 . V_150 , sizeof( V_140 . V_139 . V_150 ) ) ;
memcpy ( V_128 + sizeof( V_140 . V_139 . V_150 ) ,
& V_140 . V_139 . V_152 , sizeof( struct V_149 ) ) ;
break;
#endif
default:
F_64 ( 0 ) ;
break;
}
F_65 ( F_66 () , V_142 , V_143 ,
V_128 , V_131 , V_129 , & V_132 ) ;
F_35 ( V_128 ) ;
memcpy ( V_126 , V_129 , V_132 ) ;
* V_127 = V_132 ;
return 1 ;
}
int T_1 F_67 ( T_6 * V_89 , unsigned char * V_126 ,
unsigned int V_127 )
{
unsigned char * V_128 , V_129 [ V_130 ] ;
unsigned int V_131 , V_132 ;
union {
struct V_133 V_134 ;
struct V_135 V_136 ;
#if V_137
struct V_138 V_139 ;
#endif
} V_140 ;
if ( ! V_141 )
return 0 ;
( void ) F_62 ( F_63 ( V_89 ) , & V_140 ) ;
V_131 = 0 ;
switch ( V_140 . V_134 . V_144 ) {
case V_145 :
V_131 += sizeof( struct V_146 ) ;
V_131 += sizeof( V_140 . V_136 . V_147 ) ;
break;
#if V_137
case V_148 :
V_131 += sizeof( struct V_149 ) ;
V_131 += sizeof( V_140 . V_139 . V_150 ) ;
break;
#endif
default:
F_64 ( 0 ) ;
break;
}
V_128 = F_33 ( V_131 ) ;
if ( V_128 == NULL ) {
F_5 ( V_7 , L_165 ) ;
return 0 ;
}
switch ( V_140 . V_134 . V_144 ) {
case V_145 :
memcpy ( V_128 , & V_140 . V_136 . V_147 , sizeof( V_140 . V_136 . V_147 ) ) ;
memcpy ( V_128 + sizeof( V_140 . V_136 . V_147 ) ,
& V_140 . V_136 . V_151 , sizeof( struct V_146 ) ) ;
break;
#if V_137
case V_148 :
memcpy ( V_128 , & V_140 . V_139 . V_150 , sizeof( V_140 . V_139 . V_150 ) ) ;
memcpy ( V_128 + sizeof( V_140 . V_139 . V_150 ) ,
& V_140 . V_139 . V_152 , sizeof( struct V_149 ) ) ;
break;
#endif
default:
F_64 ( 0 ) ;
break;
}
F_65 ( F_66 () , V_142 , V_143 ,
V_128 , V_131 , V_129 , & V_132 ) ;
F_35 ( V_128 ) ;
if ( V_127 == V_132
&& memcmp ( V_129 , V_126 , V_132 ) == 0 )
return 1 ;
return 0 ;
}
static void F_68 ( T_5 * V_39 , T_6 * V_24 , int V_153 )
{
struct V_154 * V_155 = V_156 ;
while ( V_155 -> V_157 ) {
F_5 ( V_39 , L_166 , V_155 -> V_157 ,
V_153 & V_155 -> V_158 ? L_167 : L_168 ) ;
V_155 ++ ;
}
F_5 ( V_39 , L_169 ) ;
if ( F_69 ( V_24 , 0 ) & V_159 )
F_8 ( V_39 , V_153 & V_160 ? L_170 : L_171 ) ;
else
F_5 ( V_39 , L_172 ) ;
}
static int F_70 ( T_6 * V_89 , void * V_90 )
{
int V_26 , V_161 ;
T_10 * V_162 = V_90 ;
#ifdef F_71
static int V_163 ;
if ( V_163 < 5 ) {
V_163 ++ ;
fprintf ( V_164 , L_173 ,
V_163 ) ;
return - 1 ;
}
#endif
F_72 ( V_89 ) ;
if ( ! V_162 )
return 1 ;
while ( V_162 -> V_165 )
V_162 = V_162 -> V_165 ;
V_26 = 0 ;
while ( V_162 ) {
V_26 ++ ;
V_161 = F_73 ( V_89 , V_162 -> V_166 , V_162 -> V_63 , V_162 -> V_167 ) ;
F_5 ( V_7 , L_174 , V_26 ) ;
F_6 ( V_7 , F_7 ( V_162 -> V_166 ) , 0 ,
V_8 ) ;
F_8 ( V_7 , L_2 ) ;
F_68 ( V_7 , V_89 , V_161 ) ;
if ( V_161 & V_168 ) {
F_74 ( V_89 , V_162 -> V_166 ) ;
F_75 ( V_89 , V_162 -> V_63 ) ;
if ( V_162 -> V_169 ) {
if ( ! F_76 ( V_89 , 0 ) )
return 0 ;
} else if ( V_162 -> V_167 )
F_77 ( V_89 , V_162 -> V_167 ) ;
}
V_162 = V_162 -> V_170 ;
}
return 1 ;
}
void F_78 ( T_4 * V_2 , T_10 * V_162 )
{
F_79 ( V_2 , F_70 , V_162 ) ;
}
static int F_80 ( T_10 * * V_171 )
{
T_10 * V_162 ;
V_162 = F_33 ( sizeof( T_10 ) ) ;
if ( ! V_162 )
return 0 ;
V_162 -> V_172 = NULL ;
V_162 -> V_173 = NULL ;
V_162 -> V_174 = NULL ;
V_162 -> V_166 = NULL ;
V_162 -> V_63 = NULL ;
V_162 -> V_167 = NULL ;
V_162 -> V_170 = NULL ;
V_162 -> V_169 = 0 ;
V_162 -> V_165 = * V_171 ;
* V_171 = V_162 ;
if ( V_162 -> V_165 ) {
V_162 -> V_175 = V_162 -> V_165 -> V_175 ;
V_162 -> V_176 = V_162 -> V_165 -> V_176 ;
V_162 -> V_165 -> V_170 = V_162 ;
} else {
V_162 -> V_175 = V_177 ;
V_162 -> V_176 = V_177 ;
}
return 1 ;
}
void F_81 ( T_10 * V_162 )
{
T_10 * V_178 ;
while ( V_162 ) {
if ( V_162 -> V_166 )
F_82 ( V_162 -> V_166 ) ;
if ( V_162 -> V_63 )
F_46 ( V_162 -> V_63 ) ;
if ( V_162 -> V_167 )
F_83 ( V_162 -> V_167 , F_82 ) ;
V_178 = V_162 ;
V_162 = V_162 -> V_165 ;
F_35 ( V_178 ) ;
}
}
int F_84 ( T_10 * * V_171 , T_5 * V_4 )
{
T_10 * V_162 = * V_171 ;
if ( ! V_162 )
return 1 ;
if ( ! V_162 -> V_172 && ! V_162 -> V_165 ) {
F_81 ( V_162 ) ;
* V_171 = NULL ;
return 1 ;
}
for (; V_162 ; V_162 = V_162 -> V_165 ) {
if ( ! V_162 -> V_172 ) {
F_5 ( V_4 , L_175 ) ;
return 0 ;
}
V_162 -> V_166 = F_85 ( V_4 , V_162 -> V_172 , V_162 -> V_175 ,
NULL , NULL , L_176 ) ;
if ( ! V_162 -> V_166 )
return 0 ;
if ( V_162 -> V_173 ) {
V_162 -> V_63 = F_86 ( V_4 , V_162 -> V_173 , V_162 -> V_176 ,
0 , NULL , NULL , L_177 ) ;
} else {
V_162 -> V_63 = F_86 ( V_4 , V_162 -> V_172 , V_162 -> V_175 ,
0 , NULL , NULL , L_177 ) ;
}
if ( ! V_162 -> V_63 )
return 0 ;
if ( V_162 -> V_174 ) {
V_162 -> V_167 = F_87 ( V_4 ,
V_162 -> V_174 , V_177 ,
NULL , NULL , L_178 ) ;
if ( ! V_162 -> V_167 )
return 0 ;
}
}
return 1 ;
}
int F_88 ( char * * * V_179 , int * V_180 ,
int * V_181 , T_5 * V_4 , T_10 * * V_171 )
{
char * V_90 = * * V_179 , * V_182 = ( * V_179 ) [ 1 ] ;
T_10 * V_162 = * V_171 ;
int V_183 = 2 ;
if ( ! V_162 ) {
if ( F_80 ( & V_162 ) )
* V_171 = V_162 ;
else {
F_5 ( V_4 , L_179 ) ;
* V_181 = 1 ;
goto V_4;
}
}
if ( strcmp ( V_90 , L_180 ) == 0 ) {
if ( ! V_182 ) {
* V_181 = 1 ;
return 1 ;
}
if ( V_162 -> V_172 && ! F_80 ( & V_162 ) ) {
F_5 ( V_4 , L_181 ) ;
* V_181 = 1 ;
goto V_4;
}
V_162 -> V_172 = V_182 ;
} else if ( strcmp ( V_90 , L_182 ) == 0 ) {
if ( ! V_182 ) {
* V_181 = 1 ;
return 1 ;
}
if ( V_162 -> V_173 ) {
F_5 ( V_4 , L_183 ) ;
* V_181 = 1 ;
return 1 ;
}
V_162 -> V_173 = V_182 ;
} else if ( strcmp ( V_90 , L_184 ) == 0 ) {
if ( ! V_182 ) {
* V_181 = 1 ;
return 1 ;
}
if ( V_162 -> V_174 ) {
F_5 ( V_4 , L_185 ) ;
* V_181 = 1 ;
return 1 ;
}
V_162 -> V_174 = V_182 ;
} else if ( strcmp ( V_90 , L_186 ) == 0 ) {
V_183 = 1 ;
V_162 -> V_169 = 1 ;
} else if ( strcmp ( V_90 , L_187 ) == 0 ) {
if ( ! V_182 ) {
* V_181 = 1 ;
goto V_4;
}
V_162 -> V_175 = F_89 ( V_182 ) ;
} else if ( strcmp ( V_90 , L_188 ) == 0 ) {
if ( ! V_182 ) {
* V_181 = 1 ;
goto V_4;
}
V_162 -> V_176 = F_89 ( V_182 ) ;
} else
return 0 ;
( * V_179 ) += V_183 ;
if ( V_180 )
* V_180 -= V_183 ;
* V_171 = V_162 ;
return 1 ;
V_4:
F_17 ( V_4 ) ;
F_81 ( V_162 ) ;
* V_171 = NULL ;
return 1 ;
}
static void F_90 ( T_5 * V_23 , T_6 * V_24 )
{
const unsigned char * V_184 ;
static const unsigned char V_185 [] = { 0 , 0 , 0xFF } ;
T_9 V_26 , V_186 , V_103 ;
if ( ! F_23 ( V_24 ) )
return;
V_103 = F_91 ( V_24 , NULL ) ;
V_186 = F_91 ( V_24 , & V_184 ) ;
F_8 ( V_23 , L_189 ) ;
for ( V_26 = 0 ; V_26 < V_186 ; V_26 += V_103 , V_184 += V_103 ) {
const T_11 * V_187 = F_92 ( V_24 , V_184 ) ;
if ( V_26 )
F_8 ( V_23 , L_27 ) ;
if ( V_187 )
F_8 ( V_23 , F_93 ( V_187 ) ) ;
else if ( ! memcmp ( V_184 , V_185 - V_103 + 3 , V_103 ) )
F_8 ( V_23 , L_190 ) ;
else {
T_9 V_188 ;
F_8 ( V_23 , L_191 ) ;
for ( V_188 = 0 ; V_188 < V_103 ; V_188 ++ )
F_5 ( V_23 , L_192 , V_184 [ V_188 ] ) ;
}
}
F_8 ( V_23 , L_2 ) ;
}
void F_94 ( T_5 * V_23 , T_6 * V_24 )
{
const T_11 * V_187 ;
T_3 * V_140 ;
F_5 ( V_23 , L_193 , F_95 ( V_24 ) ) ;
F_90 ( V_23 , V_24 ) ;
V_187 = F_96 ( V_24 ) ;
F_5 ( V_23 , L_194 , F_93 ( V_187 ) ) ;
F_22 ( V_23 , V_24 , 0 ) ;
V_140 = F_97 ( V_24 ) ;
if ( V_140 ) {
int V_61 ;
F_8 ( V_23 , L_195 ) ;
F_6 ( V_23 , F_7 ( V_140 ) ,
0 , V_8 ) ;
F_8 ( V_23 , L_2 ) ;
if ( F_28 ( V_24 , & V_61 ) )
F_5 ( V_23 , L_196 , F_26 ( V_61 ) ) ;
} else
F_8 ( V_23 , L_197 ) ;
if ( V_140 )
F_82 ( V_140 ) ;
#ifndef F_98
F_29 ( V_23 , V_24 ) ;
if ( F_23 ( V_24 ) )
F_31 ( V_23 , V_24 , 1 ) ;
else
F_37 ( V_23 , V_24 ) ;
#else
if ( ! F_23 ( V_24 ) )
F_37 ( V_23 , V_24 ) ;
#endif
}
