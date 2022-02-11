static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 , V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ,
V_2 -> V_7 , V_8 ,
V_9 , V_2 , V_2 -> V_10 ) ;
V_2 -> V_4 -> V_11 = 0 ;
V_3 = F_4 ( V_2 -> V_4 , V_12 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_4 ) ;
}
void F_7 ( struct V_1 * V_2 , char V_13 ,
const unsigned char * V_14 , int V_15 )
{
static const int V_16 = 8 ;
char V_17 [ 100 ] ;
char V_18 [ V_16 + 1 ] ;
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_15 ; V_19 += V_16 ) {
int V_21 = sizeof( V_17 ) ;
char * V_22 = V_17 ;
int V_23 = F_8 ( V_15 - V_19 , V_16 ) ;
V_18 [ V_23 ] = 0 ;
for ( V_20 = 0 ; V_20 < V_16 ; ++ V_20 ) {
int V_24 ;
if ( V_20 < V_23 ) {
unsigned char V_25 = V_14 [ V_19 + V_20 ] ;
V_24 = snprintf ( V_22 , V_21 , L_1 , V_25 ) ;
V_18 [ V_20 ] = ( ( V_25 >= 0x20 )
&& ( V_25 < 0x7f ) ) ? V_25 : '.' ;
} else
V_24 = snprintf ( V_22 , V_21 , L_2 ) ;
if ( V_24 > V_21 )
break;
V_22 += V_24 ;
V_21 -= V_24 ;
}
F_9 ( V_2 -> V_26 , L_3 , V_13 , V_19 , V_17 , V_18 ) ;
}
}
static void F_10 ( struct V_27 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 -> V_28 ;
if ( V_27 -> V_29 < 0 )
return;
F_7 ( V_2 , 'R' , ( unsigned char * ) V_27 -> V_30 ,
V_27 -> V_11 ) ;
}
int F_11 ( struct V_1 * V_2 , const char * V_14 ,
int V_15 )
{
int V_19 , V_31 = 0 ;
#ifdef F_12
F_7 ( V_2 , 'S' , V_14 , V_15 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_15 ; V_19 += V_2 -> V_32 ) {
int V_33 ;
const char * V_34 = V_14 + V_19 ;
int V_35 = F_8 ( V_2 -> V_32 , V_15 - V_19 ) ;
int V_36 ;
V_36 = F_13 ( V_2 -> V_5 ,
F_14 ( V_2 -> V_5 ,
V_2 -> V_37 ) ,
( char * ) V_34 , V_35 ,
& V_33 , V_38 * V_39 ) ;
if ( V_36 ) {
F_15 ( V_2 -> V_26 ,
L_4 , V_36 ) ;
break;
}
V_31 += V_35 ;
}
return V_31 ;
}
static void F_16 ( struct V_27 * V_27 )
{
struct V_40 * V_41 = (struct V_40 * ) V_27 -> V_28 ;
if ( V_41 -> V_31 >= V_41 -> V_15 ) {
F_17 ( V_27 ) ;
F_18 ( V_41 ) ;
} else
F_19 ( V_41 , V_27 ) ;
}
static int F_19 ( struct V_40 * V_41 ,
struct V_27 * V_27 )
{
int V_36 ;
struct V_1 * V_2 = V_41 -> V_2 ;
int V_31 = V_41 -> V_31 ;
int V_24 = F_8 ( V_41 -> V_15 - V_31 , V_2 -> V_32 ) ;
F_2 ( V_27 , V_2 -> V_5 ,
F_14 ( V_2 -> V_5 , V_2 -> V_37 ) ,
( char * ) V_41 -> V_14 + V_31 , V_24 ,
F_16 , V_41 , V_2 -> V_10 ) ;
#ifdef F_12
F_7 ( V_2 , 'S' , ( char * ) V_41 -> V_14 + V_31 , V_24 ) ;
#endif
V_41 -> V_31 += V_24 ;
V_36 = F_4 ( V_27 , V_12 ) ;
if ( V_36 < 0 ) {
F_15 ( V_2 -> V_26 , L_5 ,
V_42 , V_36 ) ;
F_17 ( V_27 ) ;
F_18 ( V_41 ) ;
return - V_43 ;
}
return 0 ;
}
void F_20 ( struct V_44 * V_45 , unsigned int V_46 ,
void (* F_21) ( unsigned long ) , unsigned long V_47 )
{
F_22 ( V_45 , F_21 , V_47 ) ;
V_45 -> V_48 = V_49 + V_46 * V_39 / 1000 ;
F_23 ( V_45 ) ;
}
int F_24 ( struct V_1 * V_2 , const char * V_14 ,
int V_15 )
{
struct V_40 * V_41 ;
struct V_27 * V_27 ;
V_41 = F_25 ( sizeof( struct V_40 ) , V_12 ) ;
if ( V_41 == NULL ) {
F_15 ( V_2 -> V_26 , L_6 ) ;
return - V_50 ;
}
V_27 = F_26 ( 0 , V_12 ) ;
if ( V_27 == NULL ) {
F_18 ( V_41 ) ;
F_15 ( V_2 -> V_26 , L_6 ) ;
return - V_50 ;
}
V_41 -> V_2 = V_2 ;
V_41 -> V_14 = V_14 ;
V_41 -> V_15 = V_15 ;
V_41 -> V_31 = 0 ;
return F_19 ( V_41 , V_27 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
char * V_14 ;
int V_36 ;
V_14 = F_25 ( sizeof( V_51 ) , V_12 ) ;
if ( V_14 == NULL ) {
F_15 ( V_2 -> V_26 , L_7 ) ;
return - V_50 ;
}
memcpy ( V_14 , V_51 , sizeof( V_51 ) ) ;
V_36 = F_24 ( V_2 , V_14 ,
sizeof( V_51 ) ) ;
F_18 ( V_14 ) ;
return V_36 ;
}
int F_28 ( struct V_1 * V_2 , const char * V_14 ,
int V_15 )
{
return F_11 ( V_2 , V_14 ,
V_15 + V_52 ) -
V_52 ;
}
int F_29 ( struct V_1 * V_2 , const char * V_14 ,
int V_15 )
{
return F_24 ( V_2 , V_14 ,
V_15 + V_52 ) -
V_52 ;
}
char * F_30 ( struct V_1 * V_2 , int V_53 , int V_54 ,
int V_15 )
{
char * V_14 = F_25 ( V_15 + V_52 , V_12 ) ;
if ( ! V_14 ) {
F_15 ( V_2 -> V_26 , L_8 ) ;
return NULL ;
}
V_14 [ 0 ] = V_55 ;
memcpy ( V_14 + 1 , V_56 , sizeof( V_56 ) ) ;
V_14 [ sizeof( V_56 ) + 1 ] = V_53 ;
V_14 [ sizeof( V_56 ) + 2 ] = V_54 ;
V_14 [ sizeof( V_56 ) + 3 + V_15 ] = V_57 ;
return V_14 ;
}
static void V_9 ( struct V_27 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 -> V_28 ;
struct V_58 * V_59 = & V_2 -> V_60 -> V_61 ;
int V_31 ;
if ( V_27 -> V_29 == - V_62 )
return;
#ifdef F_12
F_10 ( V_27 ) ;
#endif
V_31 =
F_31 ( V_59 , V_27 -> V_30 , V_27 -> V_11 ) ;
if ( V_31 < V_27 -> V_11 ) {
F_32 ( V_59 , V_31 ) ;
F_33 ( F_15
( V_2 -> V_26 ,
L_9 ,
V_31 , V_27 -> V_11 ) ) ;
}
for (; ; ) {
V_31 =
F_34 ( V_59 , V_2 -> V_63 ,
V_64 ) ;
if ( V_31 == 0 )
break;
if ( F_35
( V_59 , V_2 -> V_60 -> V_65 ) )
continue;
V_2 -> V_66 = V_31 ;
#ifdef F_36
F_7 ( V_2 , 'r' , V_2 -> V_63 , V_31 ) ;
#endif
F_37 ( V_2 , V_2 -> V_63 , V_31 ) ;
switch ( V_2 -> V_5 -> V_67 . V_68 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
F_38 ( (struct V_75 * )
V_2 ) ;
break;
case V_76 :
case V_77 :
break;
case V_78 :
switch ( V_2 -> V_79 ) {
case V_80 :
F_38 ( (struct V_75
* ) V_2 ) ;
break;
case V_81 :
F_39 ( (struct
V_82
* ) V_2 ) ;
break;
default:
F_15 ( V_2 -> V_26 ,
L_10 ,
V_2 -> V_79 ) ;
}
break;
case V_83 :
F_39 ( (struct V_82 * )
V_2 ) ;
break;
default:
V_84 ;
}
}
F_1 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 , int V_85 )
{
int V_36 ;
unsigned char * V_14 ;
int V_33 ;
V_14 = F_25 ( 2 , V_86 ) ;
if ( ! V_14 ) {
F_15 ( V_2 -> V_26 , L_8 ) ;
return - V_50 ;
}
V_14 [ 0 ] = V_87 | V_88 ;
V_14 [ 1 ] = V_85 ;
#ifdef F_12
F_7 ( V_2 , 'S' , V_14 , 2 ) ;
#endif
V_36 = F_13 ( V_2 -> V_5 ,
F_14 ( V_2 -> V_5 ,
V_2 -> V_37 ) ,
V_14 , 2 , & V_33 , V_38 * V_39 ) ;
if ( V_36 )
F_15 ( V_2 -> V_26 , L_4 ,
V_36 ) ;
F_18 ( V_14 ) ;
return V_36 ;
}
int F_41 ( struct V_1 * V_2 , int V_89 , int V_85 )
{
int V_36 ;
unsigned char * V_14 ;
int V_33 ;
V_14 = F_25 ( 3 , V_86 ) ;
if ( ! V_14 ) {
F_15 ( V_2 -> V_26 , L_8 ) ;
return - V_50 ;
}
V_14 [ 0 ] = V_90 | V_88 ;
V_14 [ 1 ] = V_89 ;
V_14 [ 2 ] = V_85 ;
#ifdef F_12
F_7 ( V_2 , 'S' , V_14 , 3 ) ;
#endif
V_36 = F_13 ( V_2 -> V_5 ,
F_14 ( V_2 -> V_5 ,
V_2 -> V_37 ) ,
V_14 , 3 , & V_33 , V_38 * V_39 ) ;
if ( V_36 )
F_15 ( V_2 -> V_26 , L_4 ,
V_36 ) ;
F_18 ( V_14 ) ;
return V_36 ;
}
int F_42 ( struct V_1 * V_2 , int V_91 , void * V_47 ,
T_1 V_92 )
{
struct V_93 * V_5 = V_2 -> V_5 ;
int V_94 ;
unsigned char V_95 ;
V_94 = F_43 ( V_5 , F_44 ( V_5 , 0 ) , 0x67 ,
V_96 | V_97 | V_98 ,
( V_92 << 8 ) | 0x21 , V_91 ,
NULL , 0 , V_38 * V_39 ) ;
if ( V_94 < 0 ) {
F_15 ( V_2 -> V_26 , L_11 , V_94 ) ;
return V_94 ;
}
do {
V_94 = F_43 ( V_5 , F_45 ( V_5 , 0 ) , 0x67 ,
V_96 | V_97 |
V_99 ,
0x0012 , 0x0000 , & V_95 , 1 ,
V_38 * V_39 ) ;
if ( V_94 < 0 ) {
F_15 ( V_2 -> V_26 ,
L_12 , V_94 ) ;
return V_94 ;
}
} while ( V_95 == 0xff );
if ( V_95 != V_92 ) {
F_15 ( V_2 -> V_26 ,
L_13 ,
( int ) V_92 , ( int ) V_95 ) ;
return - V_43 ;
}
V_94 = F_43 ( V_5 , F_45 ( V_5 , 0 ) , 0x67 ,
V_96 | V_97 | V_99 ,
0x0013 , 0x0000 , V_47 , V_92 ,
V_38 * V_39 ) ;
if ( V_94 < 0 ) {
F_15 ( V_2 -> V_26 , L_14 , V_94 ) ;
return V_94 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , int V_91 , void * V_47 ,
T_1 V_92 )
{
struct V_93 * V_5 = V_2 -> V_5 ;
int V_94 ;
unsigned char V_29 ;
V_94 = F_43 ( V_5 , F_44 ( V_5 , 0 ) , 0x67 ,
V_96 | V_97 | V_98 ,
0x0022 , V_91 , V_47 , V_92 ,
V_38 * V_39 ) ;
if ( V_94 < 0 ) {
F_15 ( V_2 -> V_26 ,
L_15 , V_94 ) ;
return V_94 ;
}
do {
V_94 = F_43 ( V_5 , F_45 ( V_5 , 0 ) ,
0x67 ,
V_96 | V_97 |
V_99 ,
0x0012 , 0x0000 ,
& V_29 , 1 , V_38 * V_39 ) ;
if ( V_94 < 0 ) {
F_15 ( V_2 -> V_26 ,
L_16 , V_94 ) ;
return V_94 ;
}
} while ( V_29 == 0xff );
if ( V_29 != 0 ) {
F_15 ( V_2 -> V_26 , L_17 , V_94 ) ;
return - V_43 ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int * V_100 )
{
return F_42 ( V_2 , 0x80d0 , V_100 ,
sizeof( * V_100 ) ) ;
}
T_2 F_48 ( struct V_101 * V_102 , struct V_103 * V_104 ,
char * V_105 )
{
return 0 ;
}
T_2 F_49 ( struct V_101 * V_102 , struct V_103 * V_104 ,
const char * V_105 , T_1 V_106 )
{
return V_106 ;
}
T_2 F_50 ( struct V_101 * V_102 , struct V_103 * V_104 ,
const char * V_105 , T_1 V_106 )
{
struct V_107 * V_108 = F_51 ( V_102 ) ;
struct V_1 * V_2 = F_52 ( V_108 ) ;
F_11 ( V_2 , V_105 , V_106 ) ;
return V_106 ;
}
static void F_53 ( struct V_107 * V_108 )
{
struct V_1 * V_2 ;
if ( V_108 == NULL )
return;
V_2 = F_52 ( V_108 ) ;
if ( V_2 == NULL )
return;
F_18 ( V_2 -> V_63 ) ;
F_18 ( V_2 -> V_7 ) ;
F_17 ( V_2 -> V_4 ) ;
F_54 ( V_108 , NULL ) ;
F_18 ( V_2 ) ;
}
static int F_55 ( struct V_107 * V_108 ,
const struct V_109 * V_110 )
{
int V_111 ;
struct V_93 * V_5 ;
struct V_1 * V_2 ;
const struct V_112 * V_113 ;
int V_114 ;
int V_79 , V_115 = 0 ;
int V_116 ;
int V_15 = 0 ;
int V_117 = 0 , V_118 = 0 ;
int V_94 ;
if ( V_108 == NULL )
return - V_119 ;
V_5 = F_56 ( V_108 ) ;
if ( V_5 == NULL )
return - V_119 ;
if ( V_5 -> V_67 . V_120 != 1 ) {
V_94 = - V_119 ;
goto V_121;
}
for ( V_111 = F_57 ( V_122 ) - 1 ; V_111 -- ; ) {
T_3 V_123 = F_58 ( V_5 -> V_67 . V_123 ) ;
T_3 V_68 = F_58 ( V_5 -> V_67 . V_68 ) ;
if ( V_123 == V_122 [ V_111 ] . V_123 &&
V_68 == V_122 [ V_111 ] . V_68 )
break;
}
if ( V_111 < 0 ) {
V_94 = - V_119 ;
goto V_121;
}
for ( V_114 = 0 ; V_114 < V_124 ; ++ V_114 )
if ( V_125 [ V_114 ] == NULL )
break;
if ( V_114 == V_124 ) {
V_94 = - V_119 ;
goto V_121;
}
V_113 = & V_126 [ V_111 ] ;
F_9 ( & V_108 -> V_102 , L_18 , V_113 -> V_127 ) ;
V_116 = F_58 ( V_5 -> V_67 . V_68 ) ;
V_79 = V_108 -> V_128 -> V_129 . V_130 ;
switch ( V_116 ) {
case V_70 :
case V_78 :
case V_83 :
V_115 = 1 ;
break;
case V_74 :
switch ( V_79 ) {
case 0 :
return 0 ;
case 1 :
V_115 = 0 ;
break;
default:
V_84 ;
}
break;
case V_77 :
case V_131 :
case V_132 :
switch ( V_79 ) {
case 0 :
V_115 = 1 ;
break;
case 1 :
V_115 = 0 ;
break;
default:
V_84 ;
}
break;
case V_69 :
case V_71 :
case V_72 :
case V_73 :
case V_76 :
V_115 = 5 ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_115 = 2 ;
break;
case V_138 :
case V_139 :
switch ( V_79 ) {
case 0 :
V_115 = 2 ;
break;
case 1 :
return - V_119 ;
default:
V_84 ;
}
break;
default:
V_84 ;
V_94 = - V_119 ;
goto V_121;
}
V_94 = F_59 ( V_5 , V_79 , V_115 ) ;
if ( V_94 < 0 ) {
F_15 ( & V_108 -> V_102 , L_19 ) ;
goto V_121;
}
switch ( V_116 ) {
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
V_15 = sizeof( struct V_75 ) ;
V_117 = 0x84 ;
V_118 = 0x03 ;
break;
case V_76 :
V_15 = sizeof( struct V_140 ) ;
V_117 = 0x84 ;
V_118 = 0x03 ;
break;
case V_77 :
V_15 = sizeof( struct V_140 ) ;
V_117 = 0x81 ;
V_118 = 0x01 ;
break;
case V_74 :
V_15 = sizeof( struct V_75 ) ;
V_117 = 0x82 ;
V_118 = 0x02 ;
break;
case V_131 :
case V_132 :
V_15 = sizeof( struct V_75 ) ;
V_117 = 0x81 ;
V_118 = 0x01 ;
break;
case V_134 :
case V_135 :
case V_139 :
case V_136 :
case V_137 :
case V_138 :
case V_133 :
V_15 = sizeof( struct V_141 ) ;
break;
case V_78 :
switch ( V_79 ) {
case V_80 :
V_15 = sizeof( struct V_75 ) ;
V_117 = 0x84 ;
V_118 = 0x03 ;
break;
case V_81 :
V_15 = sizeof( struct V_82 ) ;
V_117 = 0x86 ;
V_118 = 0x05 ;
break;
default:
V_94 = - V_119 ;
goto V_121;
}
break;
case V_83 :
V_15 = sizeof( struct V_82 ) ;
V_117 = 0x82 ;
V_118 = 0x01 ;
break;
default:
V_84 ;
V_94 = - V_119 ;
goto V_121;
}
if ( V_15 == 0 ) {
F_15 ( & V_108 -> V_102 ,
L_20 ) ;
V_94 = - V_119 ;
goto V_121;
}
V_2 = F_60 ( V_15 , V_86 ) ;
if ( V_2 == NULL ) {
F_15 ( & V_108 -> V_102 , L_6 ) ;
V_94 = - V_119 ;
goto V_121;
}
V_2 -> V_79 = V_79 ;
V_2 -> V_113 = V_113 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_26 = & V_108 -> V_102 ;
V_2 -> V_6 = V_117 ;
V_2 -> V_37 = V_118 ;
V_2 -> V_116 = V_116 ;
{
struct V_142 * V_143 ;
unsigned V_144 =
F_61 ( F_3 ( V_5 , V_117 ) ) ;
V_143 = V_5 -> V_145 [ V_144 ] ;
if ( V_143 != NULL ) {
V_2 -> V_10 = V_143 -> V_129 . V_146 ;
V_2 -> V_32 =
F_58 ( V_143 -> V_129 . V_147 ) ;
} else {
V_2 -> V_10 = V_148 ;
V_2 -> V_32 = V_149 ;
F_15 ( V_2 -> V_26 ,
L_21 ) ;
}
}
F_54 ( V_108 , V_2 ) ;
if ( V_113 -> V_150 & V_151 ) {
V_2 -> V_7 =
F_25 ( V_8 , V_86 ) ;
if ( V_2 -> V_7 == NULL ) {
F_15 ( & V_108 -> V_102 , L_6 ) ;
V_94 = - V_50 ;
goto V_152;
}
V_2 -> V_63 =
F_25 ( V_64 , V_86 ) ;
if ( V_2 -> V_63 == NULL ) {
F_15 ( & V_108 -> V_102 , L_6 ) ;
V_94 = - V_50 ;
goto V_152;
}
V_2 -> V_4 = F_26 ( 0 , V_86 ) ;
if ( V_2 -> V_4 == NULL ) {
F_15 ( & V_108 -> V_102 , L_6 ) ;
F_53 ( V_108 ) ;
V_94 = - V_50 ;
goto V_152;
}
V_94 = F_1 ( V_2 ) ;
if ( V_94 < 0 ) {
F_15 ( & V_108 -> V_102 , L_22 ,
V_42 ) ;
goto V_152;
}
}
switch ( V_116 ) {
case V_69 :
case V_70 :
case V_71 :
case V_74 :
case V_131 :
case V_132 :
case V_72 :
case V_73 :
V_94 = F_62 ( V_108 , (struct V_75 * ) V_2 ) ;
break;
case V_76 :
case V_77 :
V_94 = F_63 ( V_108 ,
(struct V_140 * ) V_2 ) ;
break;
case V_78 :
switch ( V_79 ) {
case V_80 :
V_94 =
F_62 ( V_108 ,
(struct V_75 * ) V_2 ) ;
break;
case V_81 :
V_94 =
F_64 ( V_108 ,
(struct V_82 * ) V_2 ) ;
break;
default:
F_15 ( & V_108 -> V_102 ,
L_10 ,
V_79 ) ;
V_94 = - V_119 ;
}
break;
case V_83 :
V_94 =
F_64 ( V_108 ,
(struct V_82 * ) V_2 ) ;
break;
case V_134 :
case V_135 :
case V_139 :
case V_136 :
case V_137 :
case V_138 :
case V_133 :
V_94 =
F_65 ( V_108 ,
(struct V_141 * ) V_2 ) ;
break;
default:
V_84 ;
V_94 = - V_119 ;
}
if ( V_94 < 0 )
goto V_152;
V_94 = F_66 ( & V_108 -> V_102 . V_153 , & V_5 -> V_102 . V_153 ,
L_23 ) ;
if ( V_94 < 0 )
goto V_152;
F_9 ( & V_108 -> V_102 , L_24 ,
V_2 -> V_113 -> V_127 ) ;
V_125 [ V_114 ] = V_2 ;
switch ( V_116 ) {
case V_131 :
case V_132 :
F_9 ( & V_108 -> V_102 ,
L_25 ,
V_2 -> V_113 -> V_127 ) ;
}
F_67 ( V_108 ) ;
F_68 ( V_5 ) ;
return 0 ;
V_152:
F_53 ( V_108 ) ;
V_121:
return V_94 ;
}
static void F_69 ( struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_93 * V_5 ;
int V_79 , V_19 ;
if ( V_108 == NULL )
return;
V_5 = F_56 ( V_108 ) ;
if ( V_5 == NULL )
return;
F_70 ( & V_108 -> V_102 . V_153 , L_23 ) ;
V_79 = V_108 -> V_128 -> V_129 . V_130 ;
V_2 = F_52 ( V_108 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_4 != NULL )
F_5 ( V_2 ) ;
if ( V_5 != V_2 -> V_5 )
F_15 ( V_2 -> V_26 ,
L_26 ) ;
switch ( V_2 -> V_5 -> V_67 . V_68 ) {
case V_69 :
case V_70 :
case V_71 :
case V_74 :
case V_131 :
case V_132 :
case V_72 :
case V_73 :
F_71 ( V_108 ) ;
break;
case V_76 :
case V_77 :
F_72 ( V_108 ) ;
break;
case V_78 :
switch ( V_79 ) {
case V_80 :
F_71 ( V_108 ) ;
break;
case V_81 :
F_73 ( V_108 ) ;
break;
}
break;
case V_83 :
F_73 ( V_108 ) ;
break;
case V_134 :
case V_135 :
case V_139 :
case V_136 :
case V_137 :
case V_138 :
case V_133 :
F_74 ( V_108 ) ;
break;
default:
V_84 ;
}
F_9 ( & V_108 -> V_102 , L_27 ,
V_2 -> V_113 -> V_127 ) ;
for ( V_19 = V_124 ; V_19 -- ; )
if ( V_125 [ V_19 ] == V_2 )
V_125 [ V_19 ] = NULL ;
}
F_53 ( V_108 ) ;
F_75 ( V_108 ) ;
F_76 ( V_5 ) ;
}
static int F_77 ( struct V_107 * V_108 , T_4 V_40 )
{
struct V_1 * V_2 = F_52 ( V_108 ) ;
struct V_154 * V_155 = V_2 -> V_155 ;
F_78 ( V_2 -> V_156 , V_157 ) ;
if ( V_2 -> V_113 -> V_150 & V_151 )
F_5 ( V_2 ) ;
if ( V_155 != NULL ) {
F_79 ( V_155 -> V_158 ) ;
F_80 ( V_155 ) ;
V_155 -> V_159 = 0 ;
}
return 0 ;
}
static int F_81 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_52 ( V_108 ) ;
if ( V_2 -> V_113 -> V_150 & V_151 )
F_1 ( V_2 ) ;
F_78 ( V_2 -> V_156 , V_160 ) ;
return 0 ;
}
static int F_82 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = F_52 ( V_108 ) ;
switch ( V_2 -> V_5 -> V_67 . V_68 ) {
case V_134 :
case V_135 :
case V_139 :
case V_136 :
case V_137 :
case V_138 :
case V_133 :
F_83 ( (struct V_141 * ) V_2 ) ;
}
return F_81 ( V_108 ) ;
}
