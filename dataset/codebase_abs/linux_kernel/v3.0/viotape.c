static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 V_5 L_2 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
F_2 ( V_2 , L_3
L_4 ,
V_4 , V_7 [ V_4 ] . V_8 ,
V_7 [ V_4 ] . type ,
V_7 [ V_4 ] . V_9 ) ;
}
return 0 ;
}
static int F_3 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_4 ( V_11 , F_1 , NULL ) ;
}
void F_5 ( struct V_10 * V_12 , struct V_13 * V_14 )
{
V_14 -> V_15 = F_6 ( V_12 ) & 0x1F ;
V_14 -> V_16 = ( F_6 ( V_12 ) & 0x60 ) >> 5 ;
V_14 -> rewind = ( F_6 ( V_12 ) & 0x80 ) == 0 ;
}
static void F_7 ( void )
{
while ( V_17 ) {
struct V_18 * V_19 = V_17 ;
V_17 = V_17 -> V_20 ;
F_8 ( V_19 ) ;
}
}
static int F_9 ( int V_21 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_21 ; ++ V_4 ) {
struct V_18 * V_22 =
F_10 ( sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 ) {
F_7 () ;
return - V_24 ;
}
V_22 -> V_20 = V_17 ;
V_17 = V_22 ;
}
return 0 ;
}
static struct V_18 * F_11 ( void )
{
struct V_18 * V_25 ;
unsigned long V_26 ;
F_12 ( & V_27 , V_26 ) ;
V_25 = V_17 ;
if ( V_25 )
V_17 = V_25 -> V_20 ;
F_13 ( & V_27 , V_26 ) ;
if ( V_25 ) {
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
F_14 ( & V_25 -> V_28 ) ;
}
return V_25 ;
}
static void F_15 ( struct V_18 * V_18 )
{
unsigned long V_26 ;
F_12 ( & V_27 , V_26 ) ;
V_18 -> V_20 = V_17 ;
V_17 = V_18 ;
F_13 ( & V_27 , V_26 ) ;
}
int F_16 ( int V_29 , char * V_30 , int V_31 )
{
const struct V_32 * V_33 ;
if ( V_29 == 0 )
return 0 ;
V_33 = F_17 ( V_34 , V_29 ) ;
F_18 ( V_35 L_5 ,
V_30 , V_29 , V_31 ,
V_7 [ V_31 ] . V_8 , V_33 -> V_36 ) ;
return - V_33 -> V_37 ;
}
static T_1 F_19 ( struct V_11 * V_11 , const char * V_38 ,
T_2 V_39 , T_3 * V_40 )
{
T_4 V_41 ;
unsigned short V_26 = V_11 -> V_42 ;
int V_43 = ( ( V_26 & V_44 ) != 0 ) ;
T_1 V_45 ;
struct V_13 V_14 ;
struct V_18 * V_46 = F_11 () ;
if ( V_46 == NULL )
return - V_24 ;
F_5 ( V_11 -> V_47 . V_48 -> V_49 , & V_14 ) ;
if ( V_43 ) {
if ( F_20 ( & V_50 ) ) {
V_45 = - V_51 ;
goto V_52;
}
} else
F_21 ( & V_50 ) ;
V_46 -> V_53 = V_54 [ V_14 . V_15 ] ;
V_46 -> V_55 = F_22 ( V_46 -> V_53 , V_39 , & V_46 -> V_56 ,
V_57 ) ;
if ( V_46 -> V_55 == NULL ) {
F_18 ( V_35
L_6 ,
V_39 ) ;
V_45 = - V_58 ;
goto V_59;
}
if ( F_23 ( V_46 -> V_55 , V_38 , V_39 ) ) {
F_18 ( V_35 L_7 ) ;
V_45 = - V_58 ;
goto V_60;
}
V_46 -> V_61 = V_43 ;
F_14 ( & V_46 -> V_28 ) ;
V_46 -> V_39 = V_39 ;
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_65 ,
V_66 , V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 , V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) | V_46 -> V_56 , V_39 , 0 , 0 ) ;
if ( V_41 != V_70 ) {
F_18 ( V_35 L_8 ,
( int ) V_41 ) ;
V_45 = - V_71 ;
goto V_60;
}
if ( V_43 )
return V_39 ;
F_27 ( & V_46 -> V_28 ) ;
if ( V_46 -> V_72 )
V_45 = F_16 ( V_46 -> V_72 , L_9 , V_14 . V_15 ) ;
else {
F_28 ( V_14 . V_15 , V_73 , V_11 ) ;
V_45 = V_46 -> V_39 ;
}
V_60:
F_29 ( V_46 -> V_53 , V_39 , V_46 -> V_55 , V_46 -> V_56 ) ;
V_59:
F_30 ( & V_50 ) ;
V_52:
F_15 ( V_46 ) ;
return V_45 ;
}
static T_1 F_31 ( struct V_11 * V_11 , char * V_38 , T_2 V_39 ,
T_3 * V_74 )
{
T_4 V_41 ;
unsigned short V_26 = V_11 -> V_42 ;
struct V_18 * V_46 = F_11 () ;
int V_43 = ( ( V_26 & V_44 ) != 0 ) ;
T_1 V_45 ;
struct V_13 V_14 ;
if ( V_46 == NULL )
return - V_24 ;
F_5 ( V_11 -> V_47 . V_48 -> V_49 , & V_14 ) ;
if ( V_43 ) {
if ( F_20 ( & V_50 ) ) {
V_45 = - V_51 ;
goto V_52;
}
} else
F_21 ( & V_50 ) ;
F_28 ( V_14 . V_15 , V_75 , V_11 ) ;
V_46 -> V_53 = V_54 [ V_14 . V_15 ] ;
V_46 -> V_55 = F_22 ( V_46 -> V_53 , V_39 , & V_46 -> V_56 ,
V_57 ) ;
if ( V_46 -> V_55 == NULL ) {
V_45 = - V_58 ;
goto V_59;
}
V_46 -> V_39 = V_39 ;
F_14 ( & V_46 -> V_28 ) ;
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_76 ,
V_66 , V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 , V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) | V_46 -> V_56 , V_39 , 0 , 0 ) ;
if ( V_41 != V_70 ) {
F_18 ( V_35 L_10 ,
( int ) V_41 ) ;
V_45 = - V_71 ;
goto V_60;
}
F_27 ( & V_46 -> V_28 ) ;
if ( V_46 -> V_72 )
V_45 = F_16 ( V_46 -> V_72 , L_11 , V_14 . V_15 ) ;
else {
V_45 = V_46 -> V_39 ;
if ( V_45 && F_32 ( V_38 , V_46 -> V_55 , V_45 ) ) {
F_18 ( V_35 L_12 ) ;
V_45 = - V_58 ;
}
}
V_60:
F_29 ( V_46 -> V_53 , V_39 , V_46 -> V_55 , V_46 -> V_56 ) ;
V_59:
F_30 ( & V_50 ) ;
V_52:
F_15 ( V_46 ) ;
return V_45 ;
}
static int F_33 ( struct V_10 * V_10 , struct V_11 * V_11 ,
unsigned int V_77 , unsigned long V_78 )
{
T_4 V_41 ;
int V_45 ;
struct V_13 V_14 ;
struct V_79 V_80 ;
T_5 V_81 ;
struct V_18 * V_46 = F_11 () ;
if ( V_46 == NULL )
return - V_24 ;
F_5 ( V_11 -> V_47 . V_48 -> V_49 , & V_14 ) ;
F_21 ( & V_50 ) ;
V_45 = - V_82 ;
switch ( V_77 ) {
case V_83 :
V_45 = - V_58 ;
if ( V_10 == NULL )
memcpy ( & V_80 , ( void * ) V_78 , sizeof( struct V_79 ) ) ;
else if ( F_23 ( ( char * ) & V_80 , ( char * ) V_78 ,
sizeof( struct V_79 ) ) )
goto V_52;
V_45 = - V_71 ;
switch ( V_80 . V_84 ) {
case V_85 :
V_81 = V_86 ;
break;
case V_87 :
V_81 = V_88 ;
break;
case V_89 :
V_81 = V_90 ;
break;
case V_91 :
V_81 = V_92 ;
break;
case V_93 :
V_81 = V_94 ;
break;
case V_95 :
V_81 = V_96 ;
break;
case V_97 :
V_81 = V_98 ;
break;
case V_99 :
V_81 = V_100 ;
break;
case V_101 :
V_81 = V_102 ;
break;
case V_103 :
V_81 = V_104 ;
break;
case V_105 :
V_81 = V_106 ;
break;
case V_107 :
V_81 = V_108 ;
break;
case V_109 :
V_81 = V_110 ;
break;
case V_111 :
V_81 = V_112 ;
break;
case V_113 :
V_81 = V_114 ;
break;
case V_115 :
V_81 = V_116 ;
break;
default:
F_18 ( V_35 L_13
L_14 , V_80 . V_84 ) ;
goto V_52;
}
switch ( V_80 . V_84 ) {
case V_87 :
case V_89 :
case V_91 :
case V_93 :
case V_109 :
case V_111 :
case V_97 :
F_28 ( V_14 . V_15 , V_117 , V_11 ) ;
}
F_14 ( & V_46 -> V_28 ) ;
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_118 ,
V_66 ,
V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 ,
V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) , 0 ,
( ( ( V_68 ) V_81 ) << 32 ) | V_80 . V_119 , 0 ) ;
if ( V_41 != V_70 ) {
F_18 ( V_35 L_8 ,
( int ) V_41 ) ;
goto V_52;
}
F_27 ( & V_46 -> V_28 ) ;
V_45 = F_16 ( V_46 -> V_72 , L_15 , V_14 . V_15 ) ;
goto V_52;
case V_120 :
V_45 = - V_71 ;
F_14 ( & V_46 -> V_28 ) ;
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_121 ,
V_66 ,
V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 , V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) , 0 , 0 , 0 ) ;
if ( V_41 != V_70 ) {
F_18 ( V_35 L_8 ,
( int ) V_41 ) ;
goto V_52;
}
F_27 ( & V_46 -> V_28 ) ;
V_45 = F_16 ( V_46 -> V_72 , L_16 , V_14 . V_15 ) ;
F_15 ( V_46 ) ;
F_30 ( & V_50 ) ;
if ( ( V_45 == 0 ) && F_32 ( ( void * ) V_78 ,
& V_122 [ V_14 . V_15 ] ,
sizeof( V_122 [ 0 ] ) ) )
V_45 = - V_58 ;
return V_45 ;
case V_123 :
F_18 ( V_35 L_17 ) ;
break;
default:
F_18 ( V_35 L_18 ,
V_77 ) ;
break;
}
V_52:
F_15 ( V_46 ) ;
F_30 ( & V_50 ) ;
return V_45 ;
}
static long F_34 ( struct V_11 * V_11 ,
unsigned int V_77 , unsigned long V_78 )
{
long V_72 ;
F_35 ( & V_124 ) ;
V_72 = F_33 ( V_11 -> V_47 . V_48 -> V_49 , V_11 , V_77 , V_78 ) ;
F_36 ( & V_124 ) ;
return V_72 ;
}
static int F_37 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
T_4 V_41 ;
struct V_13 V_14 ;
int V_45 ;
struct V_18 * V_46 = F_11 () ;
if ( V_46 == NULL )
return - V_24 ;
F_35 ( & V_124 ) ;
F_5 ( V_11 -> V_47 . V_48 -> V_49 , & V_14 ) ;
if ( ( V_14 . V_15 >= V_6 ) || ( V_14 . V_16 ) ) {
V_45 = - V_125 ;
goto V_52;
}
F_14 ( & V_46 -> V_28 ) ;
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_126 ,
V_66 , V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 , V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) , 0 , 0 , 0 ) ;
if ( V_41 != 0 ) {
F_18 ( V_35 L_19 ,
( int ) V_41 ) ;
V_45 = - V_71 ;
goto V_52;
}
F_27 ( & V_46 -> V_28 ) ;
V_45 = F_16 ( V_46 -> V_72 , L_20 , V_14 . V_15 ) ;
V_52:
F_15 ( V_46 ) ;
F_36 ( & V_124 ) ;
return V_45 ;
}
static int F_38 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
T_4 V_41 ;
struct V_13 V_14 ;
int V_45 = 0 ;
struct V_18 * V_46 = F_11 () ;
if ( V_46 == NULL )
return - V_24 ;
F_14 ( & V_46 -> V_28 ) ;
F_5 ( V_11 -> V_47 . V_48 -> V_49 , & V_14 ) ;
if ( V_14 . V_15 >= V_6 ) {
V_45 = - V_125 ;
goto V_52;
}
F_28 ( V_14 . V_15 , V_117 , V_11 ) ;
if ( V_14 . rewind ) {
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_118 ,
V_66 ,
V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 , V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) , 0 ,
( ( V_68 ) V_98 ) << 32 , 0 ) ;
F_27 ( & V_46 -> V_28 ) ;
F_16 ( V_46 -> V_72 , L_21 , V_14 . V_15 ) ;
}
V_41 = F_24 ( V_62 ,
V_63 ,
V_64 | V_127 ,
V_66 , V_67 ,
F_25 ( V_62 ) ,
F_26 ( V_62 ) ,
( V_68 ) ( unsigned long ) V_46 , V_69 << 16 ,
( ( V_68 ) V_14 . V_15 << 48 ) , 0 , 0 , 0 ) ;
if ( V_41 != 0 ) {
F_18 ( V_35 L_19 ,
( int ) V_41 ) ;
V_45 = - V_71 ;
goto V_52;
}
F_27 ( & V_46 -> V_28 ) ;
if ( V_46 -> V_72 )
F_18 ( V_35 L_22 ) ;
V_52:
F_15 ( V_46 ) ;
return V_45 ;
}
static void F_39 ( struct V_128 * V_129 )
{
int V_130 ;
struct V_18 * V_46 ;
struct V_131 * V_132 = (struct V_131 * ) V_129 ;
if ( V_129 == NULL ) {
if ( ! F_40 ( V_62 ) ) {
}
return;
}
V_130 = V_129 -> V_133 & V_134 ;
V_46 = (struct V_18 * ) V_129 -> V_135 ;
switch ( V_130 ) {
case V_126 :
case V_127 :
V_46 -> V_72 = V_132 -> V_136 ;
F_41 ( & V_46 -> V_28 ) ;
break;
case V_76 :
V_46 -> V_72 = V_132 -> V_136 ;
V_46 -> V_39 = V_132 -> V_137 ;
F_41 ( & V_46 -> V_28 ) ;
break;
case V_65 :
if ( V_46 -> V_61 ) {
F_29 ( V_46 -> V_53 , V_46 -> V_39 ,
V_46 -> V_55 , V_46 -> V_56 ) ;
F_15 ( V_46 ) ;
F_30 ( & V_50 ) ;
} else {
V_46 -> V_72 = V_132 -> V_136 ;
V_46 -> V_39 = V_132 -> V_137 ;
F_41 ( & V_46 -> V_28 ) ;
}
break;
case V_118 :
case V_138 :
case V_139 :
case V_121 :
if ( V_46 ) {
V_46 -> V_39 = V_132 -> V_140 . V_46 . V_39 ;
V_46 -> V_72 = V_132 -> V_136 ;
if ( ! V_46 -> V_61 )
F_41 ( & V_46 -> V_28 ) ;
}
break;
default:
F_18 ( V_35 L_23 ) ;
}
}
static int F_42 ( struct V_141 * V_142 , const struct V_143 * V_144 )
{
int V_4 = V_142 -> V_145 ;
int V_146 ;
struct V_147 * V_148 = V_142 -> V_53 . V_149 ;
if ( V_4 >= V_150 )
return - V_125 ;
if ( ! V_148 )
return - V_125 ;
if ( V_4 >= V_6 )
V_6 = V_4 + 1 ;
V_54 [ V_4 ] = & V_142 -> V_53 ;
V_7 [ V_4 ] . V_8 = F_43 ( V_148 ,
L_24 , NULL ) ;
V_7 [ V_4 ] . type = F_43 ( V_148 , L_25 ,
NULL ) ;
V_7 [ V_4 ] . V_9 = F_43 ( V_148 , L_26 ,
NULL ) ;
V_151 [ V_4 ] . V_152 = 0 ;
for ( V_146 = 0 ; V_146 < V_153 ; ++ V_146 )
V_151 [ V_4 ] . V_154 [ V_146 ] = V_117 ;
F_44 ( V_155 , NULL , F_45 ( V_156 , V_4 ) , NULL ,
L_27 , V_4 ) ;
F_44 ( V_155 , NULL , F_45 ( V_156 , V_4 | 0x80 ) , NULL ,
L_28 , V_4 ) ;
F_18 ( V_157 L_29
L_30 ,
V_4 , V_7 [ V_4 ] . V_8 ,
V_7 [ V_4 ] . type , V_7 [ V_4 ] . V_9 ) ;
return 0 ;
}
static int F_46 ( struct V_141 * V_142 )
{
int V_4 = V_142 -> V_145 ;
F_47 ( V_155 , F_45 ( V_156 , V_4 | 0x80 ) ) ;
F_47 ( V_155 , F_45 ( V_156 , V_4 ) ) ;
return 0 ;
}
int T_6 F_48 ( void )
{
int V_45 ;
if ( ! F_49 ( V_158 ) )
return - V_125 ;
V_17 = NULL ;
if ( ( V_45 = F_9 ( V_159 ) ) < 0 ) {
F_18 ( V_35 L_31 ) ;
return V_45 ;
}
F_50 ( & V_27 ) ;
F_51 ( & V_50 , V_159 ) ;
if ( V_62 == V_160 ) {
F_52 () ;
if ( V_62 == V_160 ) {
V_45 = - V_125 ;
goto V_161;
}
}
V_45 = F_53 ( V_62 , V_64 ,
V_159 + 2 ) ;
if ( V_45 ) {
F_18 ( V_35
L_32 , V_45 ) ;
V_45 = - V_71 ;
goto V_161;
}
F_18 ( V_157 L_33 V_5
L_34 , V_62 ) ;
F_54 ( V_64 , F_39 ) ;
V_45 = F_55 ( V_156 , L_35 , & V_162 ) ;
if ( V_45 < 0 ) {
F_18 ( V_35 L_36 ) ;
goto V_163;
}
V_155 = F_56 ( V_164 , L_37 ) ;
if ( F_57 ( V_155 ) ) {
F_18 ( V_35 L_38 ) ;
V_45 = F_58 ( V_155 ) ;
goto V_165;
}
V_45 = F_59 ( & V_166 ) ;
if ( V_45 )
goto V_167;
F_60 ( L_39 , V_168 | V_169 , NULL ,
& V_170 ) ;
return 0 ;
V_167:
F_61 ( V_155 ) ;
V_165:
F_62 ( V_156 , L_35 ) ;
V_163:
F_63 ( V_64 ) ;
F_64 ( V_62 , V_64 , V_159 + 2 ) ;
V_161:
F_7 () ;
return V_45 ;
}
static int F_28 ( int V_171 , unsigned char V_172 , struct V_11 * V_11 )
{
unsigned char * V_173 =
& V_151 [ V_171 ] . V_154 [ V_151 [ V_171 ] . V_152 ] ;
int V_72 = 0 ;
if ( * V_173 == V_172 )
return 0 ;
if ( * V_173 == V_73 ) {
struct V_79 V_174 = { V_95 , 1 } ;
V_72 = F_33 ( NULL , V_11 , V_83 ,
( unsigned long ) & V_174 ) ;
}
* V_173 = V_172 ;
return V_72 ;
}
static void T_7 F_65 ( void )
{
F_66 ( L_39 , NULL ) ;
F_67 ( & V_166 ) ;
F_61 ( V_155 ) ;
F_62 ( V_156 , L_35 ) ;
F_64 ( V_62 , V_64 , V_159 + 2 ) ;
F_63 ( V_64 ) ;
F_7 () ;
}
