static const char * F_1 ( int V_1 , const T_1 * V_2 , const char * V_3 )
{
for ( ; V_2 -> V_4 ; ++ V_2 )
if ( V_2 -> V_5 == V_1 )
return V_2 -> V_4 ;
return V_3 ;
}
int F_2 ( int V_6 , T_2 * V_7 )
{
T_3 * V_8 ;
int V_9 , V_10 ;
V_8 = F_3 ( V_7 ) ;
V_9 = F_4 ( V_7 ) ;
V_10 = F_5 ( V_7 ) ;
if ( ! V_11 . V_12 || ! V_6 ) {
F_6 ( V_13 , L_1 , V_10 ) ;
if ( V_8 ) {
F_7 ( V_13 ,
F_8 ( V_8 ) ,
0 , V_14 ) ;
F_9 ( V_13 , L_2 ) ;
} else
F_9 ( V_13 , L_3 ) ;
}
if ( ! V_6 ) {
F_6 ( V_13 , L_4 , V_9 ,
F_10 ( V_9 ) ) ;
if ( V_11 . V_10 >= V_10 ) {
if ( ! V_11 . V_15 )
V_6 = 1 ;
V_11 . error = V_9 ;
} else {
V_6 = 0 ;
V_11 . error = V_16 ;
}
}
switch ( V_9 ) {
case V_17 :
F_9 ( V_13 , L_5 ) ;
F_7 ( V_13 , F_11 ( V_8 ) ,
0 , V_14 ) ;
F_9 ( V_13 , L_2 ) ;
break;
case V_18 :
case V_19 :
F_6 ( V_13 , L_6 ) ;
F_12 ( V_13 , F_13 ( V_8 ) ) ;
F_6 ( V_13 , L_2 ) ;
break;
case V_20 :
case V_21 :
F_6 ( V_13 , L_7 ) ;
F_12 ( V_13 , F_14 ( V_8 ) ) ;
F_6 ( V_13 , L_2 ) ;
break;
case V_22 :
if ( ! V_11 . V_12 )
F_15 ( V_7 ) ;
break;
}
if ( V_9 == V_23 && V_6 == 2 && ! V_11 . V_12 )
F_15 ( V_7 ) ;
if ( V_6 && ! V_11 . V_12 )
F_6 ( V_13 , L_8 , V_6 ) ;
return ( V_6 ) ;
}
int F_16 ( T_4 * V_7 , char * V_24 , char * V_25 )
{
if ( V_24 != NULL ) {
if ( F_17 ( V_7 , V_24 ,
V_26 ) <= 0 ) {
F_6 ( V_13 , L_9 ,
V_24 ) ;
F_18 ( V_13 ) ;
return ( 0 ) ;
}
if ( V_25 == NULL )
V_25 = V_24 ;
if ( F_19 ( V_7 , V_25 , V_26 ) <= 0 ) {
F_6 ( V_13 , L_10 ,
V_25 ) ;
F_18 ( V_13 ) ;
return ( 0 ) ;
}
if ( ! F_20 ( V_7 ) ) {
F_6 ( V_13 ,
L_11 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
static void F_21 ( T_5 * V_27 , T_6 * V_28 )
{
const unsigned char * V_29 ;
int V_30 ;
int V_31 = F_22 ( V_28 , & V_29 ) ;
if ( ! V_31 )
return;
F_9 ( V_27 , L_12 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
unsigned char V_32 = V_29 [ V_30 ] ;
const char * V_33 = F_1 ( ( int ) V_32 , V_34 , NULL ) ;
if ( V_30 )
F_9 ( V_27 , L_13 ) ;
if ( V_33 )
F_9 ( V_27 , V_33 ) ;
else
F_6 ( V_27 , L_14 , V_32 ) ;
}
F_9 ( V_27 , L_2 ) ;
}
static int F_23 ( T_5 * V_35 , T_6 * V_28 , int V_36 )
{
int V_30 , V_37 , V_38 ;
V_38 = F_24 ( V_28 ) ? 0 : 1 ;
if ( V_36 )
V_37 = F_25 ( V_28 , - 1 , NULL , NULL , NULL , NULL , NULL ) ;
else
V_37 = F_26 ( V_28 , - 1 , NULL , NULL , NULL , NULL , NULL ) ;
if ( V_37 == 0 )
return 1 ;
if ( V_36 )
F_9 ( V_35 , L_15 ) ;
if ( V_38 )
F_9 ( V_35 , L_16 ) ;
F_9 ( V_35 , L_17 ) ;
for ( V_30 = 0 ; V_30 < V_37 ; V_30 ++ ) {
int V_39 , V_40 ;
unsigned char V_41 , V_42 ;
const char * V_43 = NULL ;
if ( V_36 )
F_25 ( V_28 , V_30 , & V_40 , & V_39 , NULL ,
& V_42 , & V_41 ) ;
else
F_26 ( V_28 , V_30 , & V_40 , & V_39 , NULL , & V_42 , & V_41 ) ;
if ( V_30 )
F_9 ( V_35 , L_18 ) ;
if ( V_40 == V_44 )
V_43 = L_19 ;
else if ( V_40 == V_45 )
V_43 = L_20 ;
else if ( V_40 == V_46 )
V_43 = L_21 ;
if ( V_43 )
F_6 ( V_35 , L_22 , V_43 ) ;
else
F_6 ( V_35 , L_23 , ( int ) V_42 ) ;
if ( V_39 != V_47 )
F_6 ( V_35 , L_24 , F_27 ( V_39 ) ) ;
else
F_6 ( V_35 , L_25 , ( int ) V_41 ) ;
}
F_9 ( V_35 , L_2 ) ;
return 1 ;
}
int F_28 ( T_5 * V_35 , T_6 * V_28 )
{
int V_48 ;
if ( ! F_24 ( V_28 ) )
F_21 ( V_35 , V_28 ) ;
F_23 ( V_35 , V_28 , 0 ) ;
F_23 ( V_35 , V_28 , 1 ) ;
if ( F_29 ( V_28 , & V_48 ) )
F_6 ( V_35 , L_26 , F_27 ( V_48 ) ) ;
return 1 ;
}
int F_30 ( T_5 * V_35 , T_6 * V_28 )
{
int V_30 , V_49 ;
const char * V_50 ;
V_49 = F_31 ( V_28 , & V_50 ) ;
if ( V_49 <= 0 )
return 1 ;
F_9 ( V_35 , L_27 ) ;
for ( V_30 = 0 ; V_30 < V_49 ; V_30 ++ , V_50 ++ ) {
if ( V_30 )
F_9 ( V_35 , L_18 ) ;
switch ( * V_50 ) {
case V_51 :
F_9 ( V_35 , L_28 ) ;
break;
case V_52 :
F_9 ( V_35 , L_29 ) ;
break;
case V_53 :
F_9 ( V_35 , L_30 ) ;
break;
default:
F_6 ( V_35 , L_31 , ( int ) * V_50 ) ;
break;
}
}
F_9 ( V_35 , L_2 ) ;
return 1 ;
}
int F_32 ( T_5 * V_35 , T_6 * V_28 , int V_54 )
{
int V_30 , V_55 , * V_56 , V_57 ;
const char * V_33 ;
V_55 = F_33 ( V_28 , NULL ) ;
if ( V_55 <= 0 )
return 1 ;
V_56 = F_34 ( V_55 * sizeof( int ) , L_32 ) ;
F_33 ( V_28 , V_56 ) ;
F_9 ( V_35 , L_33 ) ;
for ( V_30 = 0 ; V_30 < V_55 ; V_30 ++ ) {
if ( V_30 )
F_9 ( V_35 , L_18 ) ;
V_57 = V_56 [ V_30 ] ;
if ( V_57 & V_58 )
F_6 ( V_35 , L_34 , V_57 & 0xFFFF ) ;
else {
V_33 = F_35 ( V_57 ) ;
if ( ! V_33 )
V_33 = F_27 ( V_57 ) ;
F_6 ( V_35 , L_24 , V_33 ) ;
}
}
F_36 ( V_56 ) ;
if ( V_54 ) {
F_9 ( V_35 , L_2 ) ;
return 1 ;
}
F_9 ( V_35 , L_35 ) ;
V_55 = F_37 ( V_28 , - 1 ) ;
for ( V_30 = 0 ; V_30 < V_55 ; V_30 ++ ) {
if ( V_30 )
F_9 ( V_35 , L_18 ) ;
V_57 = F_37 ( V_28 , V_30 ) ;
V_33 = F_35 ( V_57 ) ;
if ( ! V_33 )
V_33 = F_27 ( V_57 ) ;
F_6 ( V_35 , L_24 , V_33 ) ;
}
if ( V_55 == 0 )
F_9 ( V_35 , L_36 ) ;
F_9 ( V_35 , L_2 ) ;
return 1 ;
}
int F_38 ( T_5 * V_35 , T_6 * V_28 )
{
T_7 * V_59 ;
if ( ! F_39 ( V_28 , & V_59 ) )
return 1 ;
F_9 ( V_35 , L_37 ) ;
switch ( F_40 ( V_59 ) ) {
case V_44 :
F_6 ( V_35 , L_38 , F_41 ( V_59 ) ) ;
break;
case V_60 :
F_6 ( V_35 , L_39 , F_41 ( V_59 ) ) ;
break;
#ifndef F_42
case V_46 :
{
T_8 * V_61 = F_43 ( V_59 ) ;
int V_57 ;
const char * V_33 ;
V_57 = F_44 ( F_45 ( V_61 ) ) ;
F_46 ( V_61 ) ;
V_33 = F_35 ( V_57 ) ;
if ( ! V_33 )
V_33 = F_27 ( V_57 ) ;
F_6 ( V_35 , L_40 , V_33 , F_41 ( V_59 ) ) ;
}
break;
#endif
default:
F_6 ( V_35 , L_41 , F_27 ( F_40 ( V_59 ) ) ,
F_41 ( V_59 ) ) ;
}
F_47 ( V_59 ) ;
return 1 ;
}
long F_48 ( T_5 * V_27 , int V_62 , const char * V_63 ,
int V_64 , long V_65 , long V_66 )
{
T_5 * V_35 ;
V_35 = ( T_5 * ) F_49 ( V_27 ) ;
if ( V_35 == NULL )
return ( V_66 ) ;
if ( V_62 == ( V_67 | V_68 ) ) {
F_6 ( V_35 , L_42 ,
( void * ) V_27 , ( void * ) V_63 , ( unsigned long ) V_64 , V_66 , V_66 ) ;
F_50 ( V_35 , V_63 , ( int ) V_66 ) ;
return ( V_66 ) ;
} else if ( V_62 == ( V_69 | V_68 ) ) {
F_6 ( V_35 , L_43 ,
( void * ) V_27 , ( void * ) V_63 , ( unsigned long ) V_64 , V_66 , V_66 ) ;
F_50 ( V_35 , V_63 , ( int ) V_66 ) ;
}
return ( V_66 ) ;
}
void F_51 ( const T_6 * V_28 , int V_70 , int V_66 )
{
const char * V_71 ;
int V_72 ;
V_72 = V_70 & ~ V_73 ;
if ( V_72 & V_74 )
V_71 = L_44 ;
else if ( V_72 & V_75 )
V_71 = L_45 ;
else
V_71 = L_46 ;
if ( V_70 & V_76 ) {
F_6 ( V_13 , L_47 , V_71 , F_52 ( V_28 ) ) ;
} else if ( V_70 & V_77 ) {
V_71 = ( V_70 & V_78 ) ? L_48 : L_49 ;
F_6 ( V_13 , L_50 ,
V_71 ,
F_53 ( V_66 ) ,
F_54 ( V_66 ) ) ;
} else if ( V_70 & V_79 ) {
if ( V_66 == 0 )
F_6 ( V_13 , L_51 ,
V_71 , F_52 ( V_28 ) ) ;
else if ( V_66 < 0 ) {
F_6 ( V_13 , L_52 ,
V_71 , F_52 ( V_28 ) ) ;
}
}
}
void F_55 ( int V_80 , int V_81 , int V_82 , const void * V_83 ,
T_9 V_84 , T_6 * V_85 , void * V_86 )
{
T_5 * V_27 = V_86 ;
const char * V_87 = V_80 ? L_53 : L_54 ;
const char * V_88 = F_1 ( V_81 , V_89 , L_55 ) ;
const char * V_90 = L_56 , * V_91 = L_56 , * V_92 = L_56 ;
const unsigned char * V_93 = V_83 ;
if ( V_81 == V_94 ||
V_81 == V_95 ||
V_81 == V_96 ||
V_81 == V_97 ||
V_81 == V_98 || V_81 == V_99 ) {
switch ( V_82 ) {
case 20 :
V_90 = L_57 ;
break;
case 21 :
V_90 = L_58 ;
V_91 = L_59 ;
if ( V_84 == 2 ) {
switch ( V_93 [ 0 ] ) {
case 1 :
V_91 = L_60 ;
break;
case 2 :
V_91 = L_61 ;
break;
}
V_92 = F_1 ( ( int ) V_93 [ 1 ] , V_100 , L_62 ) ;
}
break;
case 22 :
V_90 = L_63 ;
V_91 = L_55 ;
if ( V_84 > 0 )
V_91 = F_1 ( ( int ) V_93 [ 0 ] , V_101 , L_55 ) ;
break;
case 23 :
V_90 = L_64 ;
break;
#ifndef F_56
case 24 :
V_91 = L_65 ;
if ( V_84 > 0 ) {
switch ( V_93 [ 0 ] ) {
case 1 :
V_91 = L_66 ;
break;
case 2 :
V_91 = L_67 ;
break;
}
}
break;
#endif
}
}
F_6 ( V_27 , L_68 , V_87 , V_88 ,
V_90 , ( unsigned long ) V_84 , V_91 ,
V_92 ) ;
if ( V_84 > 0 ) {
T_9 V_102 , V_30 ;
F_6 ( V_27 , L_69 ) ;
V_102 = V_84 ;
for ( V_30 = 0 ; V_30 < V_102 ; V_30 ++ ) {
if ( V_30 % 16 == 0 && V_30 > 0 )
F_6 ( V_27 , L_70 ) ;
F_6 ( V_27 , L_71 , ( ( const unsigned char * ) V_83 ) [ V_30 ] ) ;
}
if ( V_30 < V_84 )
F_6 ( V_27 , L_72 ) ;
F_6 ( V_27 , L_2 ) ;
}
( void ) F_57 ( V_27 ) ;
}
void F_58 ( T_6 * V_28 , int V_103 , int type ,
const unsigned char * V_104 , int V_84 , void * V_86 )
{
T_5 * V_27 = V_86 ;
const char * V_105 = F_1 ( type , V_106 , L_73 ) ;
F_6 ( V_27 , L_74 ,
V_103 ? L_75 : L_76 , V_105 , type , V_84 ) ;
F_50 ( V_27 , ( const char * ) V_104 , V_84 ) ;
( void ) F_57 ( V_27 ) ;
}
int F_59 ( T_6 * V_85 , unsigned char * V_107 ,
unsigned int * V_108 )
{
unsigned char * V_109 ;
T_9 V_110 ;
unsigned short V_111 ;
T_10 * V_112 = NULL ;
if ( ! V_113 ) {
if ( F_60 ( V_114 , V_115 ) <= 0 ) {
F_6 ( V_13 , L_77 ) ;
return 0 ;
}
V_113 = 1 ;
}
V_112 = F_61 () ;
if ( V_112 == NULL ) {
F_6 ( V_13 , L_78 ) ;
return 0 ;
}
( void ) F_62 ( F_63 ( V_85 ) , V_112 ) ;
F_64 ( V_112 , NULL , & V_110 ) ;
F_65 ( V_110 != 0 ) ;
V_111 = F_66 ( V_112 ) ;
V_110 += sizeof( V_111 ) ;
V_109 = F_34 ( V_110 , L_79 ) ;
memcpy ( V_109 , & V_111 , sizeof( V_111 ) ) ;
F_64 ( V_112 , V_109 + sizeof( V_111 ) , NULL ) ;
F_67 ( F_68 () , V_114 , V_115 ,
V_109 , V_110 , V_107 , V_108 ) ;
F_36 ( V_109 ) ;
F_69 ( V_112 ) ;
return 1 ;
}
int F_70 ( T_6 * V_85 , const unsigned char * V_107 ,
unsigned int V_108 )
{
unsigned char V_116 [ V_117 ] ;
unsigned int V_118 ;
if ( V_113
&& F_59 ( V_85 , V_116 , & V_118 )
&& V_108 == V_118
&& memcmp ( V_116 , V_107 , V_118 ) == 0 )
return 1 ;
return 0 ;
}
static void F_71 ( T_6 * V_28 , int V_119 )
{
T_1 * V_120 ;
for ( V_120 = V_121 ; V_120 -> V_4 ; ++ V_120 )
F_6 ( V_13 , L_80 ,
V_120 -> V_4 ,
( V_119 & V_120 -> V_5 ) ? L_81 : L_82 ) ;
F_6 ( V_13 , L_83 ) ;
if ( F_72 ( V_28 , 0 ) & V_122 )
F_9 ( V_13 , V_119 & V_123 ? L_84 : L_85 ) ;
else
F_6 ( V_13 , L_86 ) ;
}
static int F_73 ( T_6 * V_85 , void * V_86 )
{
int V_30 , V_124 ;
T_11 * V_125 = V_86 ;
#ifdef F_74
static int V_126 ;
if ( V_126 < 5 ) {
V_126 ++ ;
F_6 ( V_13 ,
L_87 ,
V_126 ) ;
return - 1 ;
}
#endif
F_75 ( V_85 ) ;
if ( ! V_125 )
return 1 ;
while ( V_125 -> V_127 )
V_125 = V_125 -> V_127 ;
V_30 = 0 ;
while ( V_125 ) {
V_30 ++ ;
V_124 = F_76 ( V_85 , V_125 -> V_128 , V_125 -> V_59 , V_125 -> V_129 ) ;
F_6 ( V_13 , L_88 , V_30 ) ;
F_7 ( V_13 , F_8 ( V_125 -> V_128 ) , 0 ,
V_14 ) ;
F_9 ( V_13 , L_2 ) ;
F_71 ( V_85 , V_124 ) ;
if ( V_124 & V_130 ) {
if ( ! F_77 ( V_85 , V_125 -> V_128 )
|| ! F_78 ( V_85 , V_125 -> V_59 ) ) {
return 0 ;
}
if ( V_125 -> V_131 ) {
if ( ! F_79 ( V_85 , 0 ) )
return 0 ;
} else if ( V_125 -> V_129 )
F_80 ( V_85 , V_125 -> V_129 ) ;
}
V_125 = V_125 -> V_132 ;
}
return 1 ;
}
void F_81 ( T_4 * V_7 , T_11 * V_125 )
{
F_82 ( V_7 , F_73 , V_125 ) ;
}
static int F_83 ( T_11 * * V_133 )
{
T_11 * V_125 = F_34 ( sizeof( * V_125 ) , L_89 ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_125 -> V_127 = * V_133 ;
* V_133 = V_125 ;
if ( V_125 -> V_127 ) {
V_125 -> V_134 = V_125 -> V_127 -> V_134 ;
V_125 -> V_135 = V_125 -> V_127 -> V_135 ;
V_125 -> V_127 -> V_132 = V_125 ;
} else {
V_125 -> V_134 = V_136 ;
V_125 -> V_135 = V_136 ;
}
return 1 ;
}
void F_84 ( T_11 * V_125 )
{
T_11 * V_137 ;
if ( ! V_125 )
return;
while ( V_125 ) {
F_85 ( V_125 -> V_128 ) ;
F_47 ( V_125 -> V_59 ) ;
F_86 ( V_125 -> V_129 , F_85 ) ;
V_137 = V_125 ;
V_125 = V_125 -> V_127 ;
F_36 ( V_137 ) ;
}
}
int F_87 ( T_11 * * V_133 )
{
T_11 * V_125 = * V_133 ;
if ( ! V_125 )
return 1 ;
if ( ! V_125 -> V_138 && ! V_125 -> V_127 ) {
F_84 ( V_125 ) ;
* V_133 = NULL ;
return 1 ;
}
for (; V_125 ; V_125 = V_125 -> V_127 ) {
if ( ! V_125 -> V_138 ) {
F_6 ( V_13 , L_90 ) ;
return 0 ;
}
V_125 -> V_128 = F_88 ( V_125 -> V_138 , V_125 -> V_134 ,
L_91 ) ;
if ( ! V_125 -> V_128 )
return 0 ;
if ( V_125 -> V_139 ) {
V_125 -> V_59 = F_89 ( V_125 -> V_139 , V_125 -> V_135 ,
0 , NULL , NULL , L_92 ) ;
} else {
V_125 -> V_59 = F_89 ( V_125 -> V_138 , V_125 -> V_134 ,
0 , NULL , NULL , L_92 ) ;
}
if ( ! V_125 -> V_59 )
return 0 ;
if ( V_125 -> V_140 ) {
if ( ! F_90 ( V_125 -> V_140 , & V_125 -> V_129 , V_136 , NULL ,
L_93 ) )
return 0 ;
}
}
return 1 ;
}
int F_91 ( int V_141 , T_11 * * V_133 )
{
T_11 * V_125 = * V_133 ;
assert ( V_141 > V_142 ) ;
assert ( V_141 < V_143 ) ;
if ( V_125 == NULL ) {
if ( ! F_83 ( & V_125 ) ) {
F_6 ( V_13 , L_94 ,
F_92 () ) ;
goto V_9;
}
* V_133 = V_125 ;
}
switch ( (enum V_144 ) V_141 ) {
case V_142 :
case V_143 :
return 0 ;
case V_145 :
if ( V_125 -> V_138 && ! F_83 ( & V_125 ) ) {
F_6 ( V_13 , L_95 , F_92 () ) ;
goto V_9;
}
V_125 -> V_138 = F_93 () ;
break;
case V_146 :
if ( V_125 -> V_139 ) {
F_6 ( V_13 , L_96 , F_92 () ) ;
goto V_9;
}
V_125 -> V_139 = F_93 () ;
break;
case V_147 :
if ( V_125 -> V_140 ) {
F_6 ( V_13 , L_97 ,
F_92 () ) ;
goto V_9;
}
V_125 -> V_140 = F_93 () ;
break;
case V_148 :
V_125 -> V_131 = 1 ;
break;
case V_149 :
if ( ! F_94 ( F_93 () , V_150 , & V_125 -> V_134 ) )
return 0 ;
break;
case V_151 :
if ( ! F_94 ( F_93 () , V_150 , & V_125 -> V_135 ) )
return 0 ;
break;
}
return 1 ;
V_9:
F_18 ( V_13 ) ;
F_84 ( V_125 ) ;
* V_133 = NULL ;
return 0 ;
}
static void F_95 ( T_6 * V_28 )
{
const unsigned char * V_152 ;
static const unsigned char V_153 [] = { 0 , 0xFF } ;
T_9 V_30 , V_154 , V_102 ;
if ( ! F_24 ( V_28 ) )
return;
V_102 = F_96 ( V_28 , NULL ) ;
F_65 ( V_102 == 2 ) ;
V_154 = F_96 ( V_28 , & V_152 ) ;
F_9 ( V_13 , L_98 ) ;
for ( V_30 = 0 ; V_30 < V_154 ; V_30 += V_102 , V_152 += V_102 ) {
const T_12 * V_155 = F_97 ( V_28 , V_152 ) ;
if ( V_30 )
F_9 ( V_13 , L_18 ) ;
if ( V_155 )
F_9 ( V_13 , F_98 ( V_155 ) ) ;
else if ( ! memcmp ( V_152 , V_153 , V_102 ) )
F_9 ( V_13 , L_99 ) ;
else {
T_9 V_156 ;
F_9 ( V_13 , L_100 ) ;
for ( V_156 = 0 ; V_156 < V_102 ; V_156 ++ )
F_6 ( V_13 , L_101 , V_152 [ V_156 ] ) ;
}
}
F_9 ( V_13 , L_2 ) ;
}
static char * F_99 ( const unsigned char * V_104 , T_9 V_84 )
{
static const char * V_157 = L_102 ;
char * V_35 ;
char * V_158 ;
T_9 V_159 = 2 * V_84 + 1 ;
int V_160 = ( int ) V_159 ;
if ( V_159 < V_84 || V_160 < 0 || V_159 != ( T_9 ) V_160 ) {
F_6 ( V_13 , L_103 V_161 L_104 ,
F_92 () , ( V_162 ) V_84 ) ;
exit ( 1 ) ;
}
V_158 = V_35 = F_34 ( V_160 , L_105 ) ;
while ( V_84 -- > 0 ) {
* V_158 ++ = V_157 [ ( * V_104 >> 4 ) & 0x0f ] ;
* V_158 ++ = V_157 [ * V_104 ++ & 0x0f ] ;
}
* V_158 = '\0' ;
return V_35 ;
}
void F_100 ( T_6 * V_28 , T_5 * V_27 )
{
int V_163 ;
T_7 * V_164 ;
long V_165 = F_101 ( V_28 ) ;
if ( V_165 == V_23 ) {
const char * V_166 = F_102 ( V_28 ) ;
F_6 ( V_27 , L_106 ) ;
if ( V_166 != NULL )
F_6 ( V_27 , L_107 , V_166 ) ;
} else {
const char * V_167 = F_10 ( V_165 ) ;
F_6 ( V_27 , L_108 , V_167 ) ;
}
if ( ( V_163 = F_103 ( V_28 , NULL , & V_164 ) ) >= 0 ) {
T_13 V_168 , V_169 , V_170 ;
const unsigned char * V_104 = NULL ;
T_9 V_171 = 0 ;
char * V_172 ;
V_163 = F_104 ( V_28 , & V_168 , & V_169 , & V_170 , & V_104 , & V_171 ) ;
#define F_105 12
if ( V_171 > F_105 )
V_172 = F_99 ( V_104 + V_171 - F_105 , F_105 ) ;
else
V_172 = F_99 ( V_104 , V_171 ) ;
F_6 ( V_27 , L_109 ,
V_168 , V_169 , V_170 ,
( V_171 > F_105 ) ? L_110 : L_56 , V_172 ,
( V_164 != NULL ) ? L_111 :
V_163 ? L_112 : L_113 ,
V_163 ) ;
F_36 ( V_172 ) ;
}
}
void F_106 ( T_6 * V_28 )
{
const T_12 * V_155 ;
T_3 * V_112 ;
F_6 ( V_13 , L_114 , F_107 ( V_28 ) ) ;
F_95 ( V_28 ) ;
V_155 = F_108 ( V_28 ) ;
F_6 ( V_13 , L_115 , F_98 ( V_155 ) ) ;
F_23 ( V_13 , V_28 , 0 ) ;
V_112 = F_109 ( V_28 ) ;
if ( V_112 ) {
int V_57 ;
F_9 ( V_13 , L_116 ) ;
F_7 ( V_13 , F_8 ( V_112 ) ,
0 , V_14 ) ;
F_9 ( V_13 , L_2 ) ;
if ( F_29 ( V_28 , & V_57 ) )
F_6 ( V_13 , L_117 , F_27 ( V_57 ) ) ;
F_100 ( V_28 , V_13 ) ;
} else
F_9 ( V_13 , L_118 ) ;
F_85 ( V_112 ) ;
#ifndef F_42
F_30 ( V_13 , V_28 ) ;
if ( F_24 ( V_28 ) )
F_32 ( V_13 , V_28 , 1 ) ;
else
F_38 ( V_13 , V_28 ) ;
#else
if ( ! F_24 ( V_28 ) )
F_38 ( V_13 , V_28 ) ;
#endif
}
static int F_110 ( const T_6 * V_28 , const T_4 * V_7 ,
int V_173 , int V_174 , int V_57 ,
void * V_175 , void * V_176 )
{
T_14 * V_177 = V_176 ;
int V_124 , V_178 = 1 , V_179 = 0 ;
const char * V_180 ;
V_124 = V_177 -> V_181 ( V_28 , V_7 , V_173 , V_174 , V_57 , V_175 , V_176 ) ;
if ( V_124 == 1 && V_177 -> V_182 < 2 )
return 1 ;
F_9 ( V_177 -> V_35 , L_119 ) ;
V_180 = F_1 ( V_173 , V_183 , NULL ) ;
switch ( V_173 ) {
case V_184 :
case V_185 :
V_178 = 0 ;
V_180 = NULL ;
break;
case V_186 :
F_6 ( V_177 -> V_35 , L_120 , F_1 ( V_57 , V_89 , L_55 ) ) ;
V_178 = 0 ;
V_180 = NULL ;
break;
case V_187 :
case V_188 :
V_179 = 1 ;
break;
}
if ( V_180 )
F_6 ( V_177 -> V_35 , L_121 , V_180 ) ;
switch ( V_173 & V_189 ) {
case V_190 :
F_9 ( V_177 -> V_35 , F_98 ( V_175 ) ) ;
break;
#ifndef F_42
case V_191 :
{
const char * V_33 ;
V_33 = F_35 ( V_57 ) ;
if ( V_33 == NULL )
V_33 = F_27 ( V_57 ) ;
F_9 ( V_177 -> V_35 , V_33 ) ;
}
break;
#endif
#ifndef F_111
case V_192 :
{
T_15 * V_193 = V_175 ;
F_6 ( V_177 -> V_35 , L_122 , F_112 ( V_193 ) ) ;
break;
}
#endif
case V_194 :
{
if ( V_179 ) {
int V_195 = F_113 ( V_175 ) ;
F_9 ( V_177 -> V_35 , F_27 ( V_195 ) ) ;
} else {
T_7 * V_196 = F_114 ( V_175 ) ;
const char * V_197 = L_56 ;
F_115 ( NULL , NULL , NULL , NULL ,
& V_197 , F_116 ( V_196 ) ) ;
F_6 ( V_177 -> V_35 , L_123 ,
V_197 , F_41 ( V_196 ) ) ;
}
break;
}
case V_198 :
{
const unsigned char * V_199 = V_175 ;
const char * V_200 = NULL ;
switch ( V_199 [ 1 ] ) {
case V_201 :
V_200 = L_124 ;
break;
case V_202 :
V_200 = L_19 ;
break;
case V_203 :
V_200 = L_20 ;
break;
case V_204 :
V_200 = L_21 ;
break;
}
F_9 ( V_177 -> V_35 , F_27 ( V_57 ) ) ;
if ( V_200 )
F_6 ( V_177 -> V_35 , L_125 , V_200 ) ;
else
F_6 ( V_177 -> V_35 , L_126 , V_199 [ 1 ] ) ;
break;
}
}
if ( V_178 )
F_6 ( V_177 -> V_35 , L_127 , V_174 ) ;
F_6 ( V_177 -> V_35 , L_128 , V_124 ? L_129 : L_130 ) ;
return V_124 ;
}
void F_117 ( T_4 * V_7 , int V_182 )
{
static T_14 V_177 ;
V_177 . V_35 = V_13 ;
V_177 . V_182 = V_182 ;
V_177 . V_181 = F_118 ( V_7 ) ;
F_119 ( V_7 , F_110 ) ;
F_120 ( V_7 , & V_177 ) ;
}
