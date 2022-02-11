static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
F_2 ( V_2 , L_1
L_2 ,
V_4 , V_6 [ V_4 ] . V_7 ,
V_6 [ V_4 ] . type ,
V_6 [ V_4 ] . V_8 ) ;
}
return 0 ;
}
static int F_3 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_4 ( V_10 , F_1 , NULL ) ;
}
static int F_5 ( struct V_11 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 = V_12 -> V_16 -> V_17 ;
int V_18 ;
F_6 ( & V_19 ) ;
V_18 = F_7 ( & V_15 -> V_20 , V_12 , V_13 ) ;
F_8 ( & V_19 ) ;
return V_18 ;
}
static int F_9 ( struct V_21 * V_22 , T_1 V_13 )
{
struct V_14 * V_15 = V_22 -> V_17 ;
F_6 ( & V_19 ) ;
F_10 ( & V_15 -> V_20 , V_13 ) ;
F_8 ( & V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 , T_1 V_13 ,
unsigned V_23 , unsigned long V_24 )
{
struct V_14 * V_15 = V_12 -> V_16 -> V_17 ;
int V_18 ;
F_6 ( & V_19 ) ;
V_18 = F_12 ( & V_15 -> V_20 , V_12 , V_13 , V_23 , V_24 ) ;
F_8 ( & V_19 ) ;
return V_18 ;
}
static unsigned int F_13 ( struct V_21 * V_22 ,
unsigned int V_25 )
{
struct V_14 * V_15 = V_22 -> V_17 ;
return F_14 ( & V_15 -> V_20 , V_25 ) ;
}
static int F_15 ( struct V_26 * V_27 , int V_28 )
{
struct V_14 * V_29 = V_27 -> V_30 ;
int V_31 = F_16 ( V_29 ) ;
T_2 V_32 ;
struct V_33 V_34 ;
F_17 ( & V_34 . V_35 ) ;
V_32 = F_18 ( V_36 ,
V_37 ,
V_38 | V_39 ,
V_40 , V_41 ,
F_19 ( V_36 ) ,
F_20 ( V_36 ) ,
( V_42 ) & V_34 , V_43 << 16 , ( ( V_42 ) V_31 << 48 ) ,
0 , 0 , 0 ) ;
if ( V_32 != 0 ) {
F_21 ( L_3 ,
( int ) V_32 ) ;
return - V_44 ;
}
F_22 ( & V_34 . V_35 ) ;
if ( V_34 . V_45 ) {
const struct V_46 * V_47 =
F_23 ( V_48 , V_34 . V_49 ) ;
F_21 ( L_4 ,
V_34 . V_45 , V_34 . V_49 , V_47 -> V_50 ) ;
return - V_47 -> V_51 ;
}
return 0 ;
}
static void F_24 ( struct V_26 * V_27 )
{
int V_31 = F_16 ( (struct V_14 * ) V_27 -> V_30 ) ;
T_2 V_32 ;
V_32 = F_18 ( V_36 ,
V_37 ,
V_38 | V_52 ,
V_53 , V_41 ,
F_19 ( V_36 ) ,
F_20 ( V_36 ) , 0 ,
V_43 << 16 , ( ( V_42 ) V_31 << 48 ) , 0 , 0 , 0 ) ;
if ( V_32 != 0 )
F_21 ( L_3 ,
( int ) V_32 ) ;
}
static int F_25 ( struct V_54 * V_55 )
{
T_2 V_32 ;
struct V_14 * V_29 = V_55 -> V_56 -> V_17 ;
V_42 V_57 ;
T_3 V_58 ;
int V_59 ;
T_4 V_23 ;
struct V_60 V_61 ;
F_26 ( V_55 -> V_62 > 1 ) ;
if ( F_27 ( V_55 ) == V_63 ) {
V_59 = V_64 ;
V_23 = V_38 | V_65 ;
} else {
V_59 = V_66 ;
V_23 = V_38 | V_67 ;
}
F_28 ( & V_61 , 1 ) ;
if ( F_29 ( V_55 -> V_68 , V_55 , & V_61 ) == 0 ) {
F_21 ( L_5 ) ;
return - 1 ;
}
if ( F_30 ( V_29 -> V_69 , & V_61 , 1 , V_59 ) == 0 ) {
F_21 ( L_6 ) ;
return - 1 ;
}
V_58 = F_31 ( & V_61 ) ;
V_57 = F_32 ( & V_61 ) ;
V_32 = F_18 ( V_36 ,
V_37 , V_23 ,
V_40 ,
V_41 ,
F_19 ( V_36 ) ,
F_20 ( V_36 ) ,
( V_42 ) V_55 , V_43 << 16 ,
( ( V_42 ) F_16 ( V_29 ) << 48 ) | V_58 ,
( V_42 ) F_33 ( V_55 ) * 512 , V_57 , 0 ) ;
if ( V_32 != V_70 ) {
F_21 ( L_7 , ( int ) V_32 ) ;
return - 1 ;
}
return 0 ;
}
static void F_34 ( struct V_71 * V_68 )
{
struct V_54 * V_55 ;
while ( ( V_72 == 0 ) && ( ( V_55 = F_35 ( V_68 ) ) != NULL ) ) {
if ( V_55 -> V_73 != V_74 )
F_36 ( V_55 , - V_44 ) ;
else if ( F_25 ( V_55 ) < 0 ) {
F_21 ( L_8 ) ;
F_36 ( V_55 , - V_44 ) ;
} else
V_72 ++ ;
}
}
static unsigned int F_37 ( struct V_26 * V_27 ,
unsigned int V_25 , int V_75 )
{
struct V_33 V_34 ;
T_2 V_32 ;
int V_31 = F_16 ( (struct V_14 * ) V_27 -> V_30 ) ;
F_17 ( & V_34 . V_35 ) ;
V_32 = F_18 ( V_36 ,
V_37 ,
V_38 | V_76 ,
V_40 , V_41 ,
F_19 ( V_36 ) ,
F_20 ( V_36 ) ,
( V_42 ) & V_34 , V_43 << 16 , ( ( V_42 ) V_31 << 48 ) ,
0 , 0 , 0 ) ;
if ( V_32 != 0 ) {
F_21 ( L_3 ,
( int ) V_32 ) ;
return 0 ;
}
F_22 ( & V_34 . V_35 ) ;
if ( V_34 . V_45 ) {
const struct V_46 * V_47 =
F_23 ( V_48 , V_34 . V_49 ) ;
F_21 ( L_9 ,
V_34 . V_45 , V_34 . V_49 , V_47 -> V_50 ) ;
return 0 ;
}
return V_34 . V_77 ? V_78 : 0 ;
}
static int F_38 ( struct V_26 * V_27 , int V_79 )
{
T_2 V_32 ;
V_42 V_31 = F_16 ( (struct V_14 * ) V_27 -> V_30 ) ;
V_42 V_80 = ! ! V_79 ;
struct V_33 V_34 ;
F_17 ( & V_34 . V_35 ) ;
V_32 = F_18 ( V_36 ,
V_37 ,
V_38 | V_81 ,
V_40 , V_41 ,
F_19 ( V_36 ) ,
F_20 ( V_36 ) ,
( V_42 ) & V_34 , V_43 << 16 ,
( V_31 << 48 ) | ( V_80 << 32 ) , 0 , 0 , 0 ) ;
if ( V_32 != 0 ) {
F_21 ( L_3 ,
( int ) V_32 ) ;
return - V_44 ;
}
F_22 ( & V_34 . V_35 ) ;
if ( V_34 . V_45 != 0 )
return - V_44 ;
return 0 ;
}
static int F_39 ( struct V_26 * V_27 ,
struct V_82 * V_83 )
{
unsigned int V_84 = V_83 -> V_84 ;
int V_18 = - V_44 ;
switch ( V_83 -> V_23 [ 0 ] ) {
case V_85 :
{
T_5 * V_15 = ( T_5 * ) V_83 -> V_86 ;
if ( V_84 >= 2 ) {
V_15 -> V_87 = F_40 ( 1 ) ;
V_18 = 0 ;
}
if ( V_84 >= 3 )
V_15 -> V_88 =
( V_27 -> V_89 -> V_90 & ~ V_27 -> V_91
& ( V_92 | V_93 ) ) != 0 ;
}
break;
case V_94 :
if ( V_83 -> V_23 [ 3 ] == V_95 ) {
struct V_96 * V_97 = (struct V_96 * ) ( V_83 -> V_86 + sizeof( struct V_98 ) ) ;
if ( ( V_84 >=
( sizeof( struct V_98 ) + sizeof( * V_97 ) ) ) &&
( V_27 -> V_89 -> V_90 & ~ V_27 -> V_91
& ( V_92 | V_93 ) ) ) {
V_97 -> V_99 = F_40 ( V_95 ) ;
V_97 -> V_100 = 1 ;
V_18 = 0 ;
}
}
break;
default:
if ( V_83 -> V_101 ) {
V_83 -> V_101 -> V_102 = 0x05 ;
V_83 -> V_101 -> V_103 = 0x20 ;
V_83 -> V_101 -> V_104 = 0x00 ;
}
break;
}
V_83 -> V_105 = V_18 ;
return V_18 ;
}
static void F_41 ( int V_106 )
{
int V_4 ;
for ( V_4 = V_106 + 1 ; V_4 < V_5 ; V_4 ++ )
if ( V_6 [ V_4 ] . V_107 )
F_42 ( V_6 [ V_4 ] . V_107 -> V_108 ) ;
for ( V_4 = 0 ; V_4 <= V_106 ; V_4 ++ )
if ( V_6 [ V_4 ] . V_107 )
F_42 ( V_6 [ V_4 ] . V_107 -> V_108 ) ;
}
static void F_43 ( struct V_109 * V_110 )
{
struct V_111 * V_112 ;
struct V_33 * V_113 ;
struct V_14 * V_15 ;
unsigned long V_80 ;
struct V_54 * V_55 ;
if ( V_110 == NULL )
return;
if ( F_44 ( V_110 ) ) {
F_21 ( L_10 ) ;
if ( F_45 ( V_110 ) ) {
V_110 -> V_114 = V_115 ;
F_46 ( V_110 ) ;
}
}
V_112 = (struct V_111 * ) V_110 ;
switch ( V_110 -> V_116 & V_117 ) {
case V_39 :
if ( V_110 -> V_114 == 0 ) {
V_15 = & V_6 [ V_112 -> V_22 ] ;
F_47 ( V_15 -> V_107 -> V_108 ,
V_112 -> V_118 ) ;
F_48 ( V_15 -> V_107 ,
V_112 -> V_119 *
V_112 -> V_118 / 512 ) ;
}
case V_81 :
V_113 = (struct V_33 * ) V_110 -> V_120 ;
V_121:
V_113 -> V_45 = V_110 -> V_114 ;
V_113 -> V_49 = V_112 -> V_49 ;
F_49 ( & V_113 -> V_35 ) ;
break;
case V_76 :
V_113 = (struct V_33 * ) V_110 -> V_120 ;
V_113 -> V_77 = V_112 -> V_80 ;
goto V_121;
case V_52 :
break;
case V_67 :
case V_65 :
V_15 = & V_6 [ V_112 -> V_22 ] ;
F_50 ( & V_122 , V_80 ) ;
F_51 ( V_15 -> V_69 , V_112 -> V_123 , V_112 -> V_57 ,
( ( V_110 -> V_116 & V_117 ) == V_65 )
? V_64 : V_66 ) ;
V_55 = (struct V_54 * ) V_112 -> V_110 . V_120 ;
V_72 -- ;
if ( V_110 -> V_114 != V_70 ) {
const struct V_46 * V_47 =
F_23 ( V_48 ,
V_112 -> V_49 ) ;
F_21 ( L_11 ,
V_55 , V_110 -> V_114 ,
V_112 -> V_49 , V_47 -> V_50 ) ;
F_36 ( V_55 , - V_44 ) ;
} else
F_36 ( V_55 , 0 ) ;
F_52 ( & V_122 , V_80 ) ;
F_41 ( V_112 -> V_22 ) ;
break;
default:
F_21 ( L_12 ,
V_110 -> V_116 & V_117 ) ;
if ( F_45 ( V_110 ) ) {
V_110 -> V_114 = V_115 ;
F_46 ( V_110 ) ;
}
}
}
static int F_53 ( struct V_26 * V_27 , unsigned int V_23 ,
void * V_24 )
{
return - V_124 ;
}
static int F_54 ( const char * type )
{
struct V_125 * V_126 ;
for( V_126 = V_127 ; V_126 -> type ; ++ V_126 )
if( ! strncmp ( V_126 -> type , type , 4 ) )
break;
return V_126 -> V_90 ;
}
static int F_55 ( struct V_128 * V_129 , const struct V_130 * V_131 )
{
struct V_21 * V_21 ;
int V_132 ;
struct V_14 * V_133 ;
struct V_26 * V_134 ;
struct V_71 * V_68 ;
struct V_135 * V_136 = V_129 -> V_69 . V_137 ;
V_132 = V_129 -> V_138 ;
if ( V_132 >= V_139 )
return - V_140 ;
if ( ! V_136 )
return - V_140 ;
if ( V_132 >= V_5 )
V_5 = V_132 + 1 ;
V_133 = & V_6 [ V_132 ] ;
V_133 -> V_7 = F_56 ( V_136 , L_13 , NULL ) ;
V_133 -> type = F_56 ( V_136 , L_14 , NULL ) ;
V_133 -> V_8 = F_56 ( V_136 , L_15 , NULL ) ;
V_134 = & V_133 -> V_20 ;
V_134 -> V_89 = & V_141 ;
V_134 -> V_142 = 4 ;
V_134 -> V_143 = 1 ;
V_134 -> V_30 = V_133 ;
V_134 -> V_91 = ~ F_54 ( V_133 -> type ) ;
sprintf ( V_134 -> V_144 , V_145 L_16 , 'a' + V_132 ) ;
if ( F_57 ( V_134 ) != 0 ) {
F_21 ( L_17 , V_134 -> V_144 ) ;
goto V_146;
}
F_58 ( L_18 ,
V_134 -> V_144 , V_133 -> V_7 , V_133 -> type , V_133 -> V_8 ) ;
V_68 = F_59 ( F_34 , & V_122 ) ;
if ( V_68 == NULL ) {
F_21 ( L_19 , V_134 -> V_144 ) ;
goto V_147;
}
V_21 = F_60 ( 1 ) ;
if ( V_21 == NULL ) {
F_21 ( L_20 , V_134 -> V_144 ) ;
goto V_148;
}
V_21 -> V_149 = V_150 ;
V_21 -> V_151 = V_132 ;
strncpy ( V_21 -> V_152 , V_134 -> V_144 ,
sizeof( V_21 -> V_152 ) ) ;
F_61 ( V_68 , 1 ) ;
F_62 ( V_68 , 4096 / 512 ) ;
V_21 -> V_108 = V_68 ;
V_21 -> V_153 = & V_154 ;
V_21 -> V_80 = V_155 | V_156 |
V_157 ;
F_48 ( V_21 , 0 ) ;
V_21 -> V_17 = V_133 ;
V_133 -> V_107 = V_21 ;
V_133 -> V_69 = & V_129 -> V_69 ;
V_21 -> V_158 = V_133 -> V_69 ;
F_63 ( V_21 ) ;
return 0 ;
V_148:
F_64 ( V_68 ) ;
V_147:
F_65 ( V_134 ) ;
V_146:
return - V_140 ;
}
static int F_66 ( struct V_128 * V_129 )
{
struct V_14 * V_133 = & V_6 [ V_129 -> V_138 ] ;
F_65 ( & V_133 -> V_20 ) ;
F_67 ( V_133 -> V_107 ) ;
F_64 ( V_133 -> V_107 -> V_108 ) ;
F_68 ( V_133 -> V_107 ) ;
return 0 ;
}
static int T_6 F_69 ( void )
{
int V_18 = 0 ;
if ( ! F_70 ( V_159 ) )
return - V_140 ;
if ( V_36 == V_160 ) {
F_71 () ;
if ( V_36 == V_160 )
return - V_140 ;
}
F_58 ( L_21 V_161 L_22 , V_36 ) ;
if ( F_72 ( V_150 , V_145 ) != 0 ) {
F_21 ( L_23 ,
V_150 , V_145 ) ;
return - V_44 ;
}
V_18 = F_73 ( V_36 , V_38 ,
V_162 + 2 ) ;
if ( V_18 ) {
F_21 ( L_24 ,
V_36 ) ;
goto V_163;
}
F_74 ( V_38 , F_43 ) ;
F_75 ( & V_122 ) ;
V_18 = F_76 ( & V_164 ) ;
if ( V_18 )
goto V_165;
F_77 ( L_25 , V_166 | V_167 , NULL ,
& V_168 ) ;
return 0 ;
V_165:
F_78 ( V_38 ) ;
F_79 ( V_36 , V_38 , V_162 + 2 ) ;
V_163:
F_80 ( V_150 , V_145 ) ;
return V_18 ;
}
static void T_7 F_81 ( void )
{
F_82 ( L_25 , NULL ) ;
F_83 ( & V_164 ) ;
F_79 ( V_36 , V_38 , V_162 + 2 ) ;
F_78 ( V_38 ) ;
F_80 ( V_150 , V_145 ) ;
}
