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
return F_24 ( V_2 , V_51 ,
sizeof( V_52 ) ) ;
}
int F_28 ( struct V_1 * V_2 , const char * V_14 ,
int V_15 )
{
return F_11 ( V_2 , V_14 ,
V_15 + V_53 ) -
V_53 ;
}
int F_29 ( struct V_1 * V_2 , const char * V_14 ,
int V_15 )
{
return F_24 ( V_2 , V_14 ,
V_15 + V_53 ) -
V_53 ;
}
char * F_30 ( struct V_1 * V_2 , int V_54 , int V_55 ,
int V_15 )
{
char * V_14 = F_25 ( V_15 + V_53 , V_12 ) ;
if ( ! V_14 ) {
F_15 ( V_2 -> V_26 , L_7 ) ;
return NULL ;
}
V_14 [ 0 ] = V_56 ;
memcpy ( V_14 + 1 , V_57 , sizeof( V_57 ) ) ;
V_14 [ sizeof( V_57 ) + 1 ] = V_54 ;
V_14 [ sizeof( V_57 ) + 2 ] = V_55 ;
V_14 [ sizeof( V_57 ) + 3 + V_15 ] = V_58 ;
return V_14 ;
}
static void V_9 ( struct V_27 * V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 -> V_28 ;
struct V_59 * V_60 = & V_2 -> V_61 -> V_62 ;
int V_31 ;
if ( V_27 -> V_29 == - V_63 )
return;
#ifdef F_12
F_10 ( V_27 ) ;
#endif
V_31 =
F_31 ( V_60 , V_27 -> V_30 , V_27 -> V_11 ) ;
if ( V_31 < V_27 -> V_11 ) {
F_32 ( V_60 , V_31 ) ;
F_33 ( F_15
( V_2 -> V_26 ,
L_8 ,
V_31 , V_27 -> V_11 ) ) ;
}
for (; ; ) {
V_31 =
F_34 ( V_60 , V_2 -> V_64 ,
V_65 ) ;
if ( V_31 == 0 )
break;
if ( F_35
( V_60 , V_2 -> V_61 -> V_66 ) )
continue;
V_2 -> V_67 = V_31 ;
#ifdef F_36
F_7 ( V_2 , 'r' , V_2 -> V_64 , V_31 ) ;
#endif
F_37 ( V_2 , V_2 -> V_64 , V_31 ) ;
switch ( V_2 -> V_5 -> V_68 . V_69 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
F_38 ( (struct V_76 * )
V_2 ) ;
break;
case V_77 :
switch ( V_2 -> V_78 ) {
case V_79 :
F_38 ( (struct V_76
* ) V_2 ) ;
break;
case V_80 :
F_39 ( (struct
V_81
* ) V_2 ) ;
break;
default:
F_15 ( V_2 -> V_26 ,
L_9 ,
V_2 -> V_78 ) ;
}
break;
case V_82 :
F_39 ( (struct V_81 * )
V_2 ) ;
break;
default:
V_83 ;
}
}
F_1 ( V_2 ) ;
}
int F_40 ( struct V_1 * V_2 , int V_84 )
{
int V_36 ;
unsigned char * V_14 ;
int V_33 ;
V_14 = F_25 ( 2 , V_85 ) ;
if ( ! V_14 ) {
F_15 ( V_2 -> V_26 , L_7 ) ;
return - V_50 ;
}
V_14 [ 0 ] = V_86 | V_87 ;
V_14 [ 1 ] = V_84 ;
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
int F_41 ( struct V_1 * V_2 , int V_88 , int V_84 )
{
int V_36 ;
unsigned char * V_14 ;
int V_33 ;
V_14 = F_25 ( 3 , V_85 ) ;
if ( ! V_14 ) {
F_15 ( V_2 -> V_26 , L_7 ) ;
return - V_50 ;
}
V_14 [ 0 ] = V_89 | V_87 ;
V_14 [ 1 ] = V_88 ;
V_14 [ 2 ] = V_84 ;
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
int F_42 ( struct V_1 * V_2 , int V_90 , void * V_47 ,
T_1 V_91 )
{
struct V_92 * V_5 = V_2 -> V_5 ;
int V_93 ;
unsigned char V_94 ;
V_93 = F_43 ( V_5 , F_44 ( V_5 , 0 ) , 0x67 ,
V_95 | V_96 | V_97 ,
( V_91 << 8 ) | 0x21 , V_90 ,
NULL , 0 , V_38 * V_39 ) ;
if ( V_93 < 0 ) {
F_15 ( V_2 -> V_26 , L_10 , V_93 ) ;
return V_93 ;
}
do {
V_93 = F_43 ( V_5 , F_45 ( V_5 , 0 ) , 0x67 ,
V_95 | V_96 |
V_98 ,
0x0012 , 0x0000 , & V_94 , 1 ,
V_38 * V_39 ) ;
if ( V_93 < 0 ) {
F_15 ( V_2 -> V_26 ,
L_11 , V_93 ) ;
return V_93 ;
}
} while ( V_94 == 0xff );
if ( V_94 != V_91 ) {
F_15 ( V_2 -> V_26 ,
L_12 ,
( int ) V_91 , ( int ) V_94 ) ;
return - V_43 ;
}
V_93 = F_43 ( V_5 , F_45 ( V_5 , 0 ) , 0x67 ,
V_95 | V_96 | V_98 ,
0x0013 , 0x0000 , V_47 , V_91 ,
V_38 * V_39 ) ;
if ( V_93 < 0 ) {
F_15 ( V_2 -> V_26 , L_13 , V_93 ) ;
return V_93 ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , int V_90 , void * V_47 ,
T_1 V_91 )
{
struct V_92 * V_5 = V_2 -> V_5 ;
int V_93 ;
unsigned char V_29 ;
V_93 = F_43 ( V_5 , F_44 ( V_5 , 0 ) , 0x67 ,
V_95 | V_96 | V_97 ,
0x0022 , V_90 , V_47 , V_91 ,
V_38 * V_39 ) ;
if ( V_93 < 0 ) {
F_15 ( V_2 -> V_26 ,
L_14 , V_93 ) ;
return V_93 ;
}
do {
V_93 = F_43 ( V_5 , F_45 ( V_5 , 0 ) ,
0x67 ,
V_95 | V_96 |
V_98 ,
0x0012 , 0x0000 ,
& V_29 , 1 , V_38 * V_39 ) ;
if ( V_93 < 0 ) {
F_15 ( V_2 -> V_26 ,
L_15 , V_93 ) ;
return V_93 ;
}
} while ( V_29 == 0xff );
if ( V_29 != 0 ) {
F_15 ( V_2 -> V_26 , L_16 , V_93 ) ;
return - V_43 ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int * V_99 )
{
return F_42 ( V_2 , 0x80d0 , V_99 ,
sizeof( * V_99 ) ) ;
}
T_2 F_48 ( struct V_100 * V_101 , struct V_102 * V_103 ,
char * V_104 )
{
return 0 ;
}
T_2 F_49 ( struct V_100 * V_101 , struct V_102 * V_103 ,
const char * V_104 , T_1 V_105 )
{
return V_105 ;
}
T_2 F_50 ( struct V_100 * V_101 , struct V_102 * V_103 ,
const char * V_104 , T_1 V_105 )
{
struct V_106 * V_107 = F_51 ( V_101 ) ;
struct V_1 * V_2 = F_52 ( V_107 ) ;
F_11 ( V_2 , V_104 , V_105 ) ;
return V_105 ;
}
static void F_53 ( struct V_106 * V_107 )
{
struct V_1 * V_2 ;
if ( V_107 == NULL )
return;
V_2 = F_52 ( V_107 ) ;
if ( V_2 == NULL )
return;
F_18 ( V_2 -> V_64 ) ;
F_18 ( V_2 -> V_7 ) ;
F_17 ( V_2 -> V_4 ) ;
F_54 ( V_107 , NULL ) ;
F_18 ( V_2 ) ;
}
static int F_55 ( struct V_106 * V_107 ,
const struct V_108 * V_109 )
{
int V_110 ;
struct V_92 * V_5 = NULL ;
struct V_1 * V_2 = NULL ;
const struct V_111 * V_112 ;
int V_113 ;
int V_78 , V_114 = 0 ;
int V_115 ;
int V_15 = 0 ;
int V_116 = 0 , V_117 = 0 ;
int V_93 ;
if ( V_107 == NULL )
return - V_118 ;
V_5 = F_56 ( V_107 ) ;
if ( V_5 == NULL )
return - V_118 ;
if ( V_5 -> V_68 . V_119 != 1 ) {
V_93 = - V_118 ;
goto V_120;
}
for ( V_110 = F_57 ( V_121 ) - 1 ; V_110 -- ; ) {
T_3 V_122 = F_58 ( V_5 -> V_68 . V_122 ) ;
T_3 V_69 = F_58 ( V_5 -> V_68 . V_69 ) ;
if ( V_122 == V_121 [ V_110 ] . V_122 &&
V_69 == V_121 [ V_110 ] . V_69 )
break;
}
if ( V_110 < 0 ) {
V_93 = - V_118 ;
goto V_120;
}
for ( V_113 = 0 ; V_113 < V_123 ; ++ V_113 )
if ( V_124 [ V_113 ] == NULL )
break;
if ( V_113 == V_123 ) {
V_93 = - V_118 ;
goto V_120;
}
V_112 = & V_125 [ V_110 ] ;
F_9 ( & V_107 -> V_101 , L_17 , V_112 -> V_126 ) ;
V_115 = F_58 ( V_5 -> V_68 . V_69 ) ;
V_78 = V_107 -> V_127 -> V_128 . V_129 ;
switch ( V_115 ) {
case V_71 :
case V_77 :
case V_82 :
V_114 = 1 ;
break;
case V_75 :
switch ( V_78 ) {
case 0 :
return 0 ;
case 1 :
V_114 = 0 ;
break;
default:
V_83 ;
}
break;
case V_130 :
case V_131 :
switch ( V_78 ) {
case 0 :
V_114 = 1 ;
break;
case 1 :
V_114 = 0 ;
break;
default:
V_83 ;
}
break;
case V_70 :
case V_72 :
case V_73 :
case V_74 :
V_114 = 5 ;
break;
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
V_114 = 2 ;
break;
case V_137 :
case V_138 :
switch ( V_78 ) {
case 0 :
V_114 = 2 ;
break;
case 1 :
return - V_118 ;
default:
V_83 ;
}
break;
default:
V_83 ;
V_93 = - V_118 ;
goto V_120;
}
V_93 = F_59 ( V_5 , V_78 , V_114 ) ;
if ( V_93 < 0 ) {
F_15 ( & V_107 -> V_101 , L_18 ) ;
goto V_120;
}
switch ( V_115 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_15 = sizeof( struct V_76 ) ;
V_116 = 0x84 ;
V_117 = 0x03 ;
break;
case V_75 :
V_15 = sizeof( struct V_76 ) ;
V_116 = 0x82 ;
V_117 = 0x02 ;
break;
case V_130 :
case V_131 :
V_15 = sizeof( struct V_76 ) ;
V_116 = 0x81 ;
V_117 = 0x01 ;
break;
case V_133 :
case V_134 :
case V_138 :
case V_135 :
case V_136 :
case V_137 :
case V_132 :
V_15 = sizeof( struct V_139 ) ;
break;
case V_77 :
switch ( V_78 ) {
case V_79 :
V_15 = sizeof( struct V_76 ) ;
V_116 = 0x84 ;
V_117 = 0x03 ;
break;
case V_80 :
V_15 = sizeof( struct V_81 ) ;
V_116 = 0x86 ;
V_117 = 0x05 ;
break;
default:
V_93 = - V_118 ;
goto V_120;
}
break;
case V_82 :
V_15 = sizeof( struct V_81 ) ;
V_116 = 0x82 ;
V_117 = 0x01 ;
break;
default:
V_83 ;
V_93 = - V_118 ;
goto V_120;
}
if ( V_15 == 0 ) {
F_15 ( V_2 -> V_26 ,
L_19 ) ;
V_93 = - V_118 ;
goto V_120;
}
V_2 = F_60 ( V_15 , V_85 ) ;
if ( V_2 == NULL ) {
F_15 ( & V_107 -> V_101 , L_6 ) ;
V_93 = - V_118 ;
goto V_120;
}
V_2 -> V_78 = V_78 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_26 = & V_107 -> V_101 ;
V_2 -> V_6 = V_116 ;
V_2 -> V_37 = V_117 ;
V_2 -> V_115 = V_115 ;
{
struct V_140 * V_141 ;
unsigned V_142 =
F_61 ( F_3 ( V_5 , V_116 ) ) ;
V_141 = V_5 -> V_143 [ V_142 ] ;
if ( V_141 != NULL ) {
V_2 -> V_10 = V_141 -> V_128 . V_144 ;
V_2 -> V_32 =
F_58 ( V_141 -> V_128 . V_145 ) ;
} else {
V_2 -> V_10 = V_146 ;
V_2 -> V_32 = V_147 ;
F_15 ( V_2 -> V_26 ,
L_20 ) ;
}
}
F_54 ( V_107 , V_2 ) ;
if ( V_112 -> V_148 & V_149 ) {
V_2 -> V_7 =
F_25 ( V_8 , V_85 ) ;
if ( V_2 -> V_7 == NULL ) {
F_15 ( & V_107 -> V_101 , L_6 ) ;
V_93 = - V_50 ;
goto V_150;
}
V_2 -> V_64 =
F_25 ( V_65 , V_85 ) ;
if ( V_2 -> V_64 == NULL ) {
F_15 ( & V_107 -> V_101 , L_6 ) ;
V_93 = - V_50 ;
goto V_150;
}
V_2 -> V_4 = F_26 ( 0 , V_85 ) ;
if ( V_2 -> V_4 == NULL ) {
F_15 ( & V_107 -> V_101 , L_6 ) ;
F_53 ( V_107 ) ;
V_93 = - V_50 ;
goto V_150;
}
V_93 = F_1 ( V_2 ) ;
if ( V_93 < 0 ) {
F_15 ( & V_107 -> V_101 , L_21 ,
V_42 ) ;
goto V_150;
}
}
switch ( V_115 ) {
case V_70 :
case V_71 :
case V_72 :
case V_75 :
case V_130 :
case V_131 :
case V_73 :
case V_74 :
V_93 = F_62 ( V_107 , (struct V_76 * ) V_2 ) ;
break;
case V_77 :
switch ( V_78 ) {
case V_79 :
V_93 =
F_62 ( V_107 ,
(struct V_76 * ) V_2 ) ;
break;
case V_80 :
V_93 =
F_63 ( V_107 ,
(struct V_81 * ) V_2 ) ;
break;
default:
F_15 ( & V_107 -> V_101 ,
L_9 ,
V_78 ) ;
V_93 = - V_118 ;
}
break;
case V_82 :
V_93 =
F_63 ( V_107 ,
(struct V_81 * ) V_2 ) ;
break;
case V_133 :
case V_134 :
case V_138 :
case V_135 :
case V_136 :
case V_137 :
case V_132 :
V_93 =
F_64 ( V_107 ,
(struct V_139 * ) V_2 ) ;
break;
default:
V_83 ;
V_93 = - V_118 ;
}
if ( V_93 < 0 )
goto V_150;
V_93 = F_65 ( & V_107 -> V_101 . V_151 , & V_5 -> V_101 . V_151 ,
L_22 ) ;
if ( V_93 < 0 )
goto V_150;
F_9 ( & V_107 -> V_101 , L_23 ,
V_2 -> V_112 -> V_126 ) ;
V_124 [ V_113 ] = V_2 ;
switch ( V_115 ) {
case V_130 :
case V_131 :
F_9 ( & V_107 -> V_101 ,
L_24 ,
V_2 -> V_112 -> V_126 ) ;
}
F_66 ( V_107 ) ;
F_67 ( V_5 ) ;
return 0 ;
V_150:
F_53 ( V_107 ) ;
V_120:
return V_93 ;
}
static void F_68 ( struct V_106 * V_107 )
{
struct V_1 * V_2 ;
struct V_92 * V_5 ;
int V_78 , V_19 ;
if ( V_107 == NULL )
return;
V_5 = F_56 ( V_107 ) ;
if ( V_5 == NULL )
return;
F_69 ( & V_107 -> V_101 . V_151 , L_22 ) ;
V_78 = V_107 -> V_127 -> V_128 . V_129 ;
V_2 = F_52 ( V_107 ) ;
if ( V_2 != NULL ) {
if ( V_2 -> V_4 != NULL )
F_5 ( V_2 ) ;
if ( V_5 != V_2 -> V_5 )
F_15 ( V_2 -> V_26 ,
L_25 ) ;
switch ( V_2 -> V_5 -> V_68 . V_69 ) {
case V_70 :
case V_71 :
case V_72 :
case V_75 :
case V_130 :
case V_131 :
case V_73 :
case V_74 :
F_70 ( V_107 ) ;
break;
case V_77 :
switch ( V_78 ) {
case V_79 :
F_70 ( V_107 ) ;
break;
case V_80 :
F_71 ( V_107 ) ;
break;
}
break;
case V_82 :
F_71 ( V_107 ) ;
break;
case V_133 :
case V_134 :
case V_138 :
case V_135 :
case V_136 :
case V_137 :
case V_132 :
F_72 ( V_107 ) ;
break;
default:
V_83 ;
}
F_9 ( & V_107 -> V_101 , L_26 ,
V_2 -> V_112 -> V_126 ) ;
for ( V_19 = V_123 ; V_19 -- ; )
if ( V_124 [ V_19 ] == V_2 )
V_124 [ V_19 ] = NULL ;
}
F_53 ( V_107 ) ;
F_73 ( V_107 ) ;
F_74 ( V_5 ) ;
}
static int F_75 ( struct V_106 * V_107 , T_4 V_40 )
{
struct V_1 * V_2 = F_52 ( V_107 ) ;
struct V_152 * V_153 = V_2 -> V_153 ;
F_76 ( V_2 -> V_154 , V_155 ) ;
if ( V_2 -> V_112 -> V_148 & V_149 )
F_5 ( V_2 ) ;
if ( V_153 != NULL ) {
F_77 ( V_153 -> V_156 ) ;
F_78 ( V_153 ) ;
V_153 -> V_157 = 0 ;
}
return 0 ;
}
static int F_79 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_52 ( V_107 ) ;
if ( V_2 -> V_112 -> V_148 & V_149 )
F_1 ( V_2 ) ;
F_76 ( V_2 -> V_154 , V_158 ) ;
return 0 ;
}
static int F_80 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_52 ( V_107 ) ;
switch ( V_2 -> V_5 -> V_68 . V_69 ) {
case V_133 :
case V_134 :
case V_138 :
case V_135 :
case V_136 :
case V_137 :
case V_132 :
F_81 ( (struct V_139 * ) V_2 ) ;
}
return F_79 ( V_107 ) ;
}
static int T_5 F_82 ( void )
{
int V_19 , V_36 ;
F_83 ( V_159 L_27 , V_160 , V_161 ) ;
for ( V_19 = V_123 ; V_19 -- ; )
V_124 [ V_19 ] = NULL ;
V_36 = F_84 ( & V_162 ) ;
if ( V_36 ) {
V_3 ( L_28 , V_36 ) ;
return V_36 ;
}
V_51 = F_25 ( sizeof( V_52 ) ,
V_85 ) ;
if ( V_51 == NULL ) {
V_3 ( L_29 ) ;
return - V_50 ;
}
memcpy ( ( char * ) V_51 , V_52 ,
sizeof( V_52 ) ) ;
return V_36 ;
}
static void T_6 F_85 ( void )
{
int V_19 ;
struct V_1 * V_2 ;
struct V_152 * V_153 ;
for ( V_19 = V_123 ; V_19 -- ; ) {
V_2 = V_124 [ V_19 ] ;
if ( V_2 == NULL )
continue;
V_153 = V_2 -> V_153 ;
if ( V_153 == NULL )
continue;
F_86 ( V_153 , ~ 0 ) ;
}
F_87 ( & V_162 ) ;
F_18 ( V_51 ) ;
}
