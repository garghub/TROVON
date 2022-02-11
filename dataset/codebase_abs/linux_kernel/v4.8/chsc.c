int F_1 ( int V_1 )
{
switch ( V_1 ) {
case 0x0001 :
return 0 ;
case 0x0002 :
case 0x0003 :
case 0x0006 :
case 0x0007 :
case 0x0008 :
case 0x000a :
case 0x0104 :
return - V_2 ;
case 0x0004 :
return - V_3 ;
case 0x000b :
case 0x0107 :
return - V_4 ;
case 0x0100 :
case 0x0102 :
return - V_5 ;
default:
return - V_6 ;
}
}
int F_2 ( struct V_7 V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_12 = V_18 ;
V_12 -> V_20 . V_21 = 0x0010 ;
V_12 -> V_20 . V_22 = 0x0004 ;
V_12 -> V_23 = V_8 . V_23 ;
V_12 -> V_24 = V_8 . V_25 ;
V_12 -> V_26 = V_8 . V_25 ;
V_13 = F_4 ( V_12 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_12 -> V_1 . V_22 ) ;
if ( V_14 != 0 ) {
F_5 ( 2 , L_1 ,
V_8 . V_23 , V_8 . V_25 ,
V_12 -> V_1 . V_22 ) ;
goto V_28;
}
if ( ! V_12 -> V_29 ) {
V_14 = - V_27 ;
goto V_28;
}
V_14 = 0 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
if ( ( V_12 -> V_30 != V_31 ) &&
( V_12 -> V_30 != V_32 ) )
goto V_28;
V_10 -> V_33 = V_12 -> V_33 ;
V_10 -> V_34 = V_12 -> V_34 ;
for ( V_15 = 0 ; V_15 < 8 ; V_15 ++ ) {
V_16 = 0x80 >> V_15 ;
if ( V_12 -> V_33 & V_16 ) {
F_6 ( & V_10 -> V_35 [ V_15 ] ) ;
V_10 -> V_35 [ V_15 ] . V_36 = V_12 -> V_35 [ V_15 ] ;
}
if ( V_12 -> V_34 & V_16 )
V_10 -> V_37 [ V_15 ] = V_12 -> V_37 [ V_15 ] ;
}
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int F_8 ( struct V_7 V_8 , struct V_38 * V_39 )
{
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_20 . V_21 = 0x0010 ;
V_39 -> V_20 . V_22 = 0x0024 ;
V_39 -> V_40 = V_8 . V_25 ;
V_39 -> V_41 = V_8 . V_25 ;
V_39 -> V_23 = V_8 . V_23 ;
if ( F_4 ( V_39 ) )
return - V_6 ;
return F_1 ( V_39 -> V_1 . V_22 ) ;
}
int F_9 ( struct V_7 V_8 , struct V_42 * V_43 ,
T_1 V_44 , T_1 V_45 )
{
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_20 . V_21 = 0x0fe0 ;
V_43 -> V_20 . V_22 = 0x0021 ;
V_43 -> V_46 = 0 ;
V_43 -> V_44 = V_44 ;
V_43 -> V_45 = V_45 ;
V_43 -> V_47 = V_48 >> 4 ;
V_43 -> V_49 = V_48 >> 4 ;
V_43 -> V_50 = V_51 ;
V_43 -> V_8 = V_8 ;
if ( V_52 . V_53 )
V_43 -> V_54 = 0x10000000 ;
if ( F_4 ( V_43 ) )
return - V_6 ;
return F_1 ( V_43 -> V_1 . V_22 ) ;
}
static int F_10 ( struct V_55 * V_56 , void * V_57 )
{
F_3 ( V_56 -> V_58 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
if ( V_56 -> V_59 -> V_60 ( V_56 , V_57 , V_61 ) != 0 )
goto V_62;
F_7 ( V_56 -> V_58 ) ;
return 0 ;
V_62:
V_56 -> V_63 = 0 ;
F_7 ( V_56 -> V_58 ) ;
F_11 ( V_56 -> V_8 ) ;
return 0 ;
}
void F_12 ( struct V_64 V_35 )
{
struct V_65 * V_66 = F_13 ( V_35 ) ;
struct V_67 V_68 ;
char V_69 [ 15 ] ;
sprintf ( V_69 , L_2 , V_35 . V_70 , V_35 . V_36 ) ;
F_14 ( 2 , V_69 ) ;
if ( F_15 ( V_35 ) <= 0 )
return;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_35 = V_35 ;
F_16 () ;
F_17 ( & V_66 -> V_58 ) ;
F_18 ( V_66 ) ;
F_19 ( & V_66 -> V_58 ) ;
F_20 ( F_10 , NULL , & V_68 ) ;
}
static int F_21 ( struct V_55 * V_56 , void * V_57 )
{
F_3 ( V_56 -> V_58 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
V_56 -> V_59 -> V_60 ( V_56 , V_57 , V_71 ) ;
F_7 ( V_56 -> V_58 ) ;
return 0 ;
}
static void F_22 ( struct V_67 * V_68 )
{
char V_69 [ 15 ] ;
sprintf ( V_69 , L_3 , V_68 -> V_35 . V_70 ,
V_68 -> V_35 . V_36 ) ;
F_14 ( 2 , V_69 ) ;
if ( V_68 -> V_37 != 0 ) {
sprintf ( V_69 , L_4 , V_68 -> V_37 ) ;
F_14 ( 2 , V_69 ) ;
}
F_16 () ;
F_20 ( F_21 , NULL , V_68 ) ;
F_23 () ;
}
static char * F_24 ( char * V_72 , const char * V_73 , unsigned long V_74 ,
char V_75 )
{
memcpy ( V_72 , V_73 , V_74 ) ;
F_25 ( V_72 , V_74 ) ;
if ( V_75 )
V_72 [ V_74 ++ ] = V_75 ;
return V_72 + V_74 ;
}
static void F_26 ( char * V_76 , char * V_36 , struct V_77 * V_78 )
{
memset ( V_76 , 0 , V_79 ) ;
memset ( V_36 , 0 , V_80 ) ;
if ( V_78 -> V_81 != V_82 ) {
strncpy ( V_76 , L_5 , V_79 - 1 ) ;
strncpy ( V_36 , L_5 , V_80 - 1 ) ;
return;
}
snprintf ( V_76 , V_79 , L_6 , V_78 -> V_83 , V_78 -> V_76 ) ;
V_36 = F_24 ( V_36 , V_78 -> type , sizeof( V_78 -> type ) , '/' ) ;
V_36 = F_24 ( V_36 , V_78 -> V_84 , sizeof( V_78 -> V_84 ) , ',' ) ;
V_36 = F_24 ( V_36 , V_78 -> V_85 , sizeof( V_78 -> V_85 ) , '.' ) ;
V_36 = F_24 ( V_36 , V_78 -> V_86 , sizeof( V_78 -> V_86 ) , 0 ) ;
V_36 = F_24 ( V_36 , V_78 -> V_87 , sizeof( V_78 -> V_87 ) , ',' ) ;
sprintf ( V_36 , L_7 , V_78 -> V_88 ) ;
}
static void F_27 ( struct V_89 * V_90 )
{
struct V_91 * V_91 = (struct V_91 * ) & V_90 -> V_92 ;
char V_93 [ V_79 ] , V_94 [ V_80 ] , V_95 [ V_79 ] ,
V_96 [ V_80 ] ;
F_28 ( 4 , L_8 ,
V_90 -> V_97 , V_90 -> V_98 , V_90 -> V_92 [ 0 ] ) ;
if ( V_91 -> V_99 . null )
return;
F_26 ( V_93 , V_94 , & V_91 -> V_100 ) ;
F_26 ( V_95 , V_96 , & V_91 -> V_101 ) ;
switch ( V_91 -> V_99 . V_102 ) {
case V_103 :
F_29 ( L_9
L_10 ,
V_90 -> V_97 , V_90 -> V_98 , V_91 -> V_104 , V_93 ,
V_94 , V_95 , V_96 ) ;
break;
case V_105 :
F_30 ( L_11
L_10 ,
V_90 -> V_97 , V_90 -> V_98 , V_91 -> V_104 , V_93 ,
V_94 , V_95 , V_96 ) ;
break;
default:
break;
}
}
static void F_31 ( struct V_89 * V_90 )
{
struct V_67 V_68 ;
struct V_64 V_35 ;
int V_106 ;
F_28 ( 4 , L_12
L_13 , V_90 -> V_97 , V_90 -> V_98 ) ;
if ( V_90 -> V_97 != 4 )
return;
F_6 ( & V_35 ) ;
V_35 . V_36 = V_90 -> V_98 ;
V_106 = F_15 ( V_35 ) ;
if ( V_106 < 0 )
F_32 ( V_35 ) ;
else if ( ! V_106 )
return;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_35 = V_35 ;
if ( ( V_90 -> V_107 & 0xc0 ) != 0 ) {
V_68 . V_37 = V_90 -> V_37 ;
if ( ( V_90 -> V_107 & 0xc0 ) == 0xc0 )
V_68 . V_108 = 0xffff ;
else
V_68 . V_108 = 0xff00 ;
}
F_22 ( & V_68 ) ;
}
static void F_33 ( struct V_89 * V_90 )
{
struct V_65 * V_66 ;
struct V_64 V_35 ;
T_2 * V_57 ;
int V_109 ;
F_28 ( 4 , L_14 ) ;
if ( V_90 -> V_97 != 0 )
return;
V_57 = V_90 -> V_92 ;
F_6 ( & V_35 ) ;
for ( V_109 = 0 ; V_109 <= V_110 ; V_109 ++ ) {
if ( ! F_34 ( V_57 , V_109 ) )
continue;
V_35 . V_36 = V_109 ;
F_28 ( 4 , L_15
L_16 , V_35 . V_70 , V_35 . V_36 ) ;
V_66 = F_13 ( V_35 ) ;
if ( ! V_66 ) {
F_32 ( V_35 ) ;
continue;
}
F_17 ( & V_66 -> V_58 ) ;
F_18 ( V_66 ) ;
F_19 ( & V_66 -> V_58 ) ;
}
}
static void F_35 ( struct V_89 * V_90 )
{
struct V_111 * V_57 ;
struct V_64 V_35 ;
int V_109 ;
char * V_112 [ 3 ] = { L_17 , L_18 , L_19 } ;
F_28 ( 4 , L_20 ) ;
if ( V_90 -> V_97 != 0 )
return;
V_57 = (struct V_111 * ) & ( V_90 -> V_92 ) ;
F_6 ( & V_35 ) ;
for ( V_109 = 0 ; V_109 <= V_110 ; V_109 ++ ) {
if ( ! F_34 ( V_57 -> V_113 , V_109 ) )
continue;
V_35 . V_36 = V_109 ;
F_36 ( L_21 ,
V_112 [ V_57 -> V_114 ] , V_35 . V_70 , V_35 . V_36 ) ;
switch ( V_57 -> V_114 ) {
case 0 :
F_37 ( V_35 , 1 ) ;
break;
case 1 :
F_37 ( V_35 , 0 ) ;
break;
case 2 :
F_38 ( V_35 ) ;
break;
}
}
}
static void F_39 ( struct V_89 * V_90 )
{
int V_14 ;
F_28 ( 4 , L_22 ) ;
if ( V_90 -> V_97 != 7 )
return;
V_14 = F_40 () ;
if ( V_14 )
F_28 ( 0 , L_23
L_24 , V_14 ) ;
}
static void F_41 ( struct V_89 * V_90 )
{
int V_14 ;
F_28 ( 4 , L_25 ) ;
if ( V_90 -> V_97 != 7 )
return;
V_14 = F_42 () ;
if ( V_14 )
F_28 ( 0 , L_26
L_24 , V_14 ) ;
}
static void F_43 ( struct V_115 * V_90 )
{
switch ( V_90 -> V_116 ) {
case 1 :
F_44 ( V_90 -> V_92 ) ;
break;
case 2 :
F_45 ( V_90 -> V_92 ) ;
break;
default:
F_28 ( 2 , L_27 ,
V_90 -> V_116 ) ;
break;
}
}
static void F_46 ( struct V_89 * V_90 )
{
switch ( V_90 -> V_116 ) {
case 1 :
F_27 ( V_90 ) ;
break;
case 2 :
F_31 ( V_90 ) ;
break;
case 7 :
F_33 ( V_90 ) ;
break;
case 8 :
F_35 ( V_90 ) ;
break;
case 12 :
F_39 ( V_90 ) ;
break;
case 14 :
F_41 ( V_90 ) ;
break;
default:
F_28 ( 2 , L_28 ,
V_90 -> V_116 ) ;
break;
}
if ( V_90 -> V_117 & 0x40 ) {
F_28 ( 2 , L_29 ) ;
F_47 () ;
}
}
static void F_48 ( struct V_118 * V_119 , T_1 V_120 )
{
static int V_121 ;
while ( true ) {
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_20 . V_21 = 0x0010 ;
V_119 -> V_20 . V_22 = 0x000e ;
if ( ! V_121 )
V_119 -> V_120 = V_120 ;
if ( F_4 ( V_119 ) )
break;
if ( V_119 -> V_1 . V_22 != 0x0001 ) {
F_28 ( 2 , L_30 ,
V_119 -> V_1 . V_22 , V_119 -> V_120 ) ;
if ( V_119 -> V_1 . V_22 == 3 && V_119 -> V_120 ) {
V_121 = 1 ;
continue;
}
break;
}
F_28 ( 2 , L_31 , V_119 -> V_122 ) ;
switch ( V_119 -> V_122 ) {
case 0 :
F_46 ( & V_119 -> V_123 . V_124 ) ;
break;
case 2 :
F_43 ( & V_119 -> V_123 . V_125 ) ;
break;
default:
F_28 ( 2 , L_32 , V_119 -> V_122 ) ;
break;
}
if ( ! ( V_119 -> V_123 . V_124 . V_117 & 0x80 ) )
break;
}
}
static void F_49 ( struct V_126 * V_127 , struct V_126 * V_128 , int V_129 )
{
struct V_118 * V_119 = V_130 ;
if ( V_129 ) {
F_47 () ;
return;
}
F_28 ( 2 , L_33
L_34 ,
V_127 -> V_131 , V_127 -> V_132 , V_127 -> V_133 , V_127 -> V_134 , V_127 -> V_135 ,
V_127 -> V_136 , V_127 -> V_98 ) ;
F_14 ( 2 , L_35 ) ;
F_48 ( V_119 , V_137 | V_138 ) ;
}
void F_50 ( struct V_64 V_35 )
{
struct V_65 * V_66 = F_13 ( V_35 ) ;
struct V_67 V_68 ;
char V_69 [ 15 ] ;
sprintf ( V_69 , L_36 , V_35 . V_70 , V_35 . V_36 ) ;
F_14 ( 2 , V_69 ) ;
if ( F_15 ( V_35 ) != 0 ) {
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_35 = V_35 ;
F_16 () ;
F_17 ( & V_66 -> V_58 ) ;
F_18 ( V_66 ) ;
F_19 ( & V_66 -> V_58 ) ;
F_20 ( F_21 , NULL ,
& V_68 ) ;
F_23 () ;
}
}
static void F_51 ( struct V_55 * V_56 ,
struct V_64 V_35 , int V_139 )
{
unsigned long V_117 ;
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_35 = V_35 ;
F_52 ( V_56 -> V_58 , V_117 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
V_56 -> V_59 -> V_60 ( V_56 , & V_68 ,
V_139 ? V_140 : V_141 ) ;
F_53 ( V_56 -> V_58 , V_117 ) ;
}
static int F_54 ( struct V_55 * V_56 , void * V_57 )
{
struct V_64 * V_35 = V_57 ;
F_51 ( V_56 , * V_35 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_55 * V_56 , void * V_57 )
{
struct V_64 * V_35 = V_57 ;
F_51 ( V_56 , * V_35 , 1 ) ;
return 0 ;
}
int F_56 ( struct V_64 V_35 , int V_139 )
{
struct V_65 * V_66 = F_13 ( V_35 ) ;
F_16 () ;
if ( V_139 ) {
F_18 ( V_66 ) ;
F_20 ( F_55 ,
NULL , & V_35 ) ;
F_23 () ;
} else
F_20 ( F_54 ,
NULL , & V_35 ) ;
return 0 ;
}
static void
F_57 ( struct V_142 * V_143 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 <= V_110 ; V_15 ++ ) {
if ( ! V_143 -> V_144 [ V_15 ] )
continue;
F_58 ( V_143 -> V_144 [ V_15 ] ) ;
}
}
static int
F_59 ( struct V_142 * V_143 )
{
int V_15 , V_14 ;
V_14 = 0 ;
for ( V_15 = 0 ; V_15 <= V_110 ; V_15 ++ ) {
if ( ! V_143 -> V_144 [ V_15 ] )
continue;
V_14 = F_60 ( V_143 -> V_144 [ V_15 ] ) ;
if ( V_14 )
goto V_145;
}
return V_14 ;
V_145:
for ( -- V_15 ; V_15 >= 0 ; V_15 -- ) {
if ( ! V_143 -> V_144 [ V_15 ] )
continue;
F_58 ( V_143 -> V_144 [ V_15 ] ) ;
}
return V_14 ;
}
int F_61 ( struct V_142 * V_143 , int V_146 )
{
struct {
struct V_147 V_20 ;
T_3 V_46 : 2 ;
T_3 : 30 ;
T_3 V_148 : 4 ;
T_3 : 28 ;
T_3 V_149 ;
T_3 V_150 ;
T_3 V_151 ;
T_3 V_152 ;
T_3 V_153 [ 13 ] ;
struct V_147 V_1 ;
T_3 V_106 : 8 ;
T_3 : 4 ;
T_3 V_154 : 4 ;
T_3 : 16 ;
} V_155 ( ( V_156 ) ) * V_157 ;
int V_14 , V_13 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_157 = V_18 ;
V_157 -> V_20 . V_21 = 0x0050 ;
V_157 -> V_20 . V_22 = 0x0016 ;
V_157 -> V_148 = V_48 >> 4 ;
V_157 -> V_150 = ( T_1 ) ( unsigned long ) V_143 -> V_150 ;
V_157 -> V_152 = ( T_1 ) ( unsigned long ) V_143 -> V_152 ;
V_157 -> V_46 = V_146 ? 0 : 1 ;
V_13 = F_4 ( V_157 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_157 -> V_1 . V_22 ) {
case 0x0102 :
case 0x0103 :
V_14 = - V_2 ;
break;
default:
V_14 = F_1 ( V_157 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_28 ( 2 , L_37 ,
V_157 -> V_1 . V_22 ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int
F_62 ( struct V_142 * V_143 , int V_146 )
{
int V_14 ;
if ( V_146 && ! V_143 -> V_158 ) {
V_143 -> V_150 = ( void * ) F_63 ( V_159 | V_160 ) ;
V_143 -> V_152 = ( void * ) F_63 ( V_159 | V_160 ) ;
if ( ! V_143 -> V_150 || ! V_143 -> V_152 ) {
F_64 ( ( unsigned long ) V_143 -> V_150 ) ;
F_64 ( ( unsigned long ) V_143 -> V_152 ) ;
return - V_5 ;
}
}
V_14 = F_61 ( V_143 , V_146 ) ;
if ( ! V_14 ) {
V_143 -> V_158 = V_146 ;
if ( V_143 -> V_158 ) {
V_14 = F_59 ( V_143 ) ;
if ( V_14 ) {
F_61 ( V_143 , 0 ) ;
V_143 -> V_158 = 0 ;
}
} else
F_57 ( V_143 ) ;
}
if ( ! V_143 -> V_158 ) {
F_64 ( ( unsigned long ) V_143 -> V_150 ) ;
F_64 ( ( unsigned long ) V_143 -> V_152 ) ;
}
return V_14 ;
}
int F_65 ( struct V_64 V_35 , int V_154 , int V_161 ,
int V_162 , int V_163 , void * V_164 )
{
struct V_165 * V_166 ;
int V_13 , V_14 ;
if ( ( V_161 == 1 || V_161 == 0 ) && V_162 == 1 &&
! V_52 . V_167 )
return - V_2 ;
if ( ( V_161 == 2 ) && ! V_52 . V_168 )
return - V_2 ;
memset ( V_164 , 0 , V_19 ) ;
V_166 = V_164 ;
V_166 -> V_20 . V_21 = 0x0010 ;
V_166 -> V_20 . V_22 = 0x0002 ;
V_166 -> V_70 = V_35 . V_70 ;
V_166 -> V_169 = V_35 . V_36 ;
V_166 -> V_170 = V_35 . V_36 ;
V_166 -> V_163 = V_163 ;
V_166 -> V_162 = V_162 ;
V_166 -> V_154 = V_154 ;
V_166 -> V_161 = V_161 ;
V_13 = F_4 ( V_166 ) ;
if ( V_13 > 0 )
return ( V_13 == 3 ) ? - V_27 : - V_4 ;
V_14 = F_1 ( V_166 -> V_1 . V_22 ) ;
if ( V_14 )
F_28 ( 2 , L_38 ,
V_166 -> V_1 . V_22 ) ;
return V_14 ;
}
int F_66 ( struct V_64 V_35 ,
struct V_171 * V_172 )
{
struct V_165 * V_166 ;
unsigned long V_117 ;
int V_14 ;
F_52 ( & V_17 , V_117 ) ;
V_166 = V_18 ;
V_14 = F_65 ( V_35 , 0 , 0 , 0 , 0 , V_166 ) ;
if ( V_14 )
goto V_28;
memcpy ( V_172 , V_166 -> V_57 , sizeof( * V_172 ) ) ;
V_28:
F_53 ( & V_17 , V_117 ) ;
return V_14 ;
}
int F_67 ( struct V_64 V_35 ,
struct V_173 * V_172 )
{
struct V_165 * V_166 ;
unsigned long V_117 ;
int V_14 ;
F_52 ( & V_17 , V_117 ) ;
V_166 = V_18 ;
V_14 = F_65 ( V_35 , 0 , 1 , 1 , 0 , V_166 ) ;
if ( V_14 )
goto V_28;
memcpy ( V_172 , V_166 -> V_57 , sizeof( * V_172 ) ) ;
V_28:
F_53 ( & V_17 , V_117 ) ;
return V_14 ;
}
static void
F_68 ( struct V_65 * V_66 , T_2 V_174 ,
struct V_175 * V_176 )
{
int V_15 , V_16 ;
for ( V_15 = 0 ; V_15 < V_177 ; V_15 ++ ) {
V_16 = 0x80 >> ( V_15 + 3 ) ;
if ( V_174 & V_16 )
V_66 -> V_175 . V_178 [ V_15 ] = V_176 -> V_178 [ V_15 ] ;
else
V_66 -> V_175 . V_178 [ V_15 ] = 0 ;
}
}
int F_69 ( struct V_65 * V_66 )
{
int V_13 , V_14 ;
struct {
struct V_147 V_20 ;
T_3 : 24 ;
T_3 V_169 : 8 ;
T_3 : 24 ;
T_3 V_170 : 8 ;
T_3 V_149 ;
struct V_147 V_1 ;
T_3 V_151 ;
T_3 V_179 : 1 ;
T_3 V_180 : 1 ;
T_3 : 22 ;
T_3 V_35 : 8 ;
T_3 V_174 : 5 ;
T_3 : 11 ;
T_3 V_181 : 8 ;
T_3 V_182 : 8 ;
T_3 V_183 ;
T_3 V_57 [ V_177 ] ;
} V_155 ( ( V_156 ) ) * V_184 ;
V_66 -> V_180 = - 1 ;
V_66 -> V_182 = - 1 ;
if ( ! V_185 . V_186 || ! V_185 . V_187 )
return - V_2 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_184 = V_18 ;
V_184 -> V_20 . V_21 = 0x0010 ;
V_184 -> V_20 . V_22 = 0x0022 ;
V_184 -> V_169 = V_66 -> V_35 . V_36 ;
V_184 -> V_170 = V_66 -> V_35 . V_36 ;
V_13 = F_4 ( V_184 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_184 -> V_1 . V_22 ) ;
if ( V_14 ) {
F_28 ( 2 , L_39 ,
V_184 -> V_1 . V_22 ) ;
goto V_28;
}
if ( V_184 -> V_179 )
goto V_28;
V_66 -> V_182 = V_184 -> V_182 ;
V_66 -> V_180 = V_184 -> V_180 ;
if ( V_66 -> V_182 != 2 && V_66 -> V_182 != 3 ) {
goto V_28;
}
F_68 ( V_66 , V_184 -> V_174 ,
(struct V_175 * ) & V_184 -> V_57 ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int T_4 F_70 ( void )
{
int V_14 ;
V_130 = ( void * ) F_63 ( V_159 | V_160 ) ;
V_18 = ( void * ) F_63 ( V_159 | V_160 ) ;
if ( ! V_130 || ! V_18 ) {
V_14 = - V_5 ;
goto V_188;
}
V_14 = F_71 ( V_189 , F_49 ) ;
if ( V_14 )
goto V_188;
return V_14 ;
V_188:
F_64 ( ( unsigned long ) V_18 ) ;
F_64 ( ( unsigned long ) V_130 ) ;
return V_14 ;
}
void T_4 F_72 ( void )
{
F_73 ( V_189 ) ;
F_64 ( ( unsigned long ) V_18 ) ;
F_64 ( ( unsigned long ) V_130 ) ;
}
int F_74 ( struct V_190 * V_191 , int V_46 )
{
int V_14 ;
V_191 -> V_20 . V_21 = 0x0400 ;
V_191 -> V_20 . V_22 = 0x0031 ;
V_191 -> V_46 = V_46 ;
V_14 = F_4 ( V_191 ) ;
if ( V_14 > 0 ) {
V_14 = ( V_14 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_191 -> V_1 . V_22 ) {
case 0x0101 :
V_14 = - V_3 ;
break;
default:
V_14 = F_1 ( V_191 -> V_1 . V_22 ) ;
}
V_28:
return V_14 ;
}
int F_75 ( int V_46 )
{
struct V_190 * V_191 ;
unsigned long V_117 ;
int V_14 ;
F_52 ( & V_17 , V_117 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_191 = V_18 ;
V_14 = F_74 ( V_191 , V_46 ) ;
if ( V_14 != 0 )
F_28 ( 2 , L_40 ,
V_46 , V_191 -> V_1 . V_22 ) ;
F_53 ( & V_17 , V_117 ) ;
return V_14 ;
}
int T_4
F_76 ( void )
{
int V_192 ;
struct {
struct V_147 V_20 ;
T_3 V_193 ;
T_3 V_194 ;
T_3 V_195 ;
struct V_147 V_1 ;
T_3 V_196 ;
T_3 V_197 [ 510 ] ;
T_3 V_198 [ 508 ] ;
} V_155 ( ( V_156 ) ) * V_199 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_199 = V_18 ;
V_199 -> V_20 . V_21 = 0x0010 ;
V_199 -> V_20 . V_22 = 0x0010 ;
V_192 = F_4 ( V_199 ) ;
if ( V_192 ) {
V_192 = ( V_192 == 3 ) ? - V_27 : - V_4 ;
goto exit;
}
V_192 = F_1 ( V_199 -> V_1 . V_22 ) ;
if ( V_192 == 0 ) {
memcpy ( & V_52 , V_199 -> V_197 ,
sizeof( V_52 ) ) ;
memcpy ( & V_185 , V_199 -> V_198 ,
sizeof( V_185 ) ) ;
} else
F_28 ( 2 , L_41 ,
V_199 -> V_1 . V_22 ) ;
exit:
F_7 ( & V_17 ) ;
return V_192 ;
}
int F_77 ( void * V_164 , unsigned int V_114 , T_5 V_200 , T_1 * V_201 )
{
struct {
struct V_147 V_20 ;
unsigned int V_202 ;
unsigned int V_114 : 8 ;
unsigned int V_203 : 8 ;
unsigned int V_200 : 16 ;
unsigned int V_204 [ 5 ] ;
struct V_147 V_1 ;
unsigned int V_205 [ 3 ] ;
T_1 V_201 ;
unsigned int V_206 [ 2 ] ;
} V_155 ( ( V_156 ) ) * V_207 ;
int V_208 ;
memset ( V_164 , 0 , V_19 ) ;
V_207 = V_164 ;
V_207 -> V_20 . V_21 = 0x0020 ;
V_207 -> V_20 . V_22 = 0x0033 ;
V_207 -> V_114 = V_114 ;
V_207 -> V_200 = V_200 ;
V_208 = F_4 ( V_207 ) ;
if ( V_208 )
return - V_6 ;
V_208 = ( V_207 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
if ( V_201 )
* V_201 = V_207 -> V_201 ;
return V_208 ;
}
int F_78 ( void * V_164 , void * V_192 , T_6 V_209 )
{
struct {
struct V_147 V_20 ;
unsigned int V_202 [ 3 ] ;
struct V_147 V_1 ;
char V_57 [ V_209 ] ;
} V_155 ( ( V_156 ) ) * V_207 ;
int V_208 ;
memset ( V_164 , 0 , V_19 ) ;
V_207 = V_164 ;
V_207 -> V_20 . V_21 = 0x0010 ;
V_207 -> V_20 . V_22 = 0x0038 ;
V_208 = F_4 ( V_207 ) ;
if ( V_208 )
return - V_6 ;
memcpy ( V_192 , & V_207 -> V_57 , V_209 ) ;
return ( V_207 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
}
int F_79 ( struct V_7 V_8 )
{
struct {
struct V_147 V_20 ;
T_3 V_210 ;
struct V_7 V_211 ;
T_3 V_212 ;
struct V_147 V_1 ;
T_3 V_213 [ 11 ] ;
} V_155 ( ( V_156 ) ) * V_214 ;
unsigned long V_117 ;
int V_13 ;
int V_208 ;
F_52 ( & V_17 , V_117 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_214 = V_18 ;
V_214 -> V_20 . V_21 = 0x0010 ;
V_214 -> V_20 . V_22 = 0x0046 ;
V_214 -> V_210 = 0x80000000 ;
V_214 -> V_211 = V_8 ;
V_13 = F_4 ( V_214 ) ;
if ( V_13 > 0 ) {
if ( V_13 == 3 )
V_208 = - V_27 ;
else
V_208 = - V_4 ;
F_5 ( 2 , L_42 ,
V_8 . V_23 , V_8 . V_25 , V_13 ) ;
goto V_28;
}
V_208 = F_1 ( V_214 -> V_1 . V_22 ) ;
if ( V_208 )
F_5 ( 2 , L_43 ,
V_8 . V_23 , V_8 . V_25 ,
V_214 -> V_1 . V_22 ) ;
else
F_5 ( 4 , L_44 ,
V_8 . V_23 , V_8 . V_25 ) ;
V_28:
F_53 ( & V_17 , V_117 ) ;
return V_208 ;
}
int F_80 ( struct F_80 * V_215 , T_1 V_216 )
{
int V_13 , V_14 ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
V_215 -> V_20 . V_21 = 0x0020 ;
V_215 -> V_20 . V_22 = 0x004C ;
V_215 -> V_217 = V_216 ;
V_13 = F_4 ( V_215 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_215 -> V_1 . V_22 ) ;
if ( V_14 != 0 )
F_5 ( 2 , L_45 ,
V_215 -> V_1 . V_22 ) ;
V_28:
return V_14 ;
}
int F_81 ( struct V_7 V_8 ,
struct V_218 * V_219 ,
struct V_220 V_221 ,
int V_222 )
{
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
V_219 -> V_20 . V_21 = 0x0030 ;
V_219 -> V_20 . V_22 = 0x003d ;
V_219 -> V_163 = V_8 . V_163 ;
V_219 -> V_23 = V_8 . V_23 ;
V_219 -> V_56 = V_8 . V_25 ;
V_219 -> V_70 = V_8 . V_70 ;
V_219 -> V_223 = 0 ;
V_219 -> V_221 = V_221 ;
V_219 -> V_224 = ( V_222 != 0 ) ;
if ( F_4 ( V_219 ) )
return - V_6 ;
return F_1 ( V_219 -> V_1 . V_22 ) ;
}
