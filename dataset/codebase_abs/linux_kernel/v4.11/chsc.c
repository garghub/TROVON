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
unsigned long V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
int V_17 ;
F_3 ( & V_18 , V_13 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_12 = V_19 ;
V_12 -> V_21 . V_22 = 0x0010 ;
V_12 -> V_21 . V_23 = 0x0004 ;
V_12 -> V_24 = V_8 . V_24 ;
V_12 -> V_25 = V_8 . V_26 ;
V_12 -> V_27 = V_8 . V_26 ;
V_14 = F_4 ( V_12 ) ;
if ( V_14 > 0 ) {
V_15 = ( V_14 == 3 ) ? - V_28 : - V_4 ;
goto V_29;
}
V_15 = F_1 ( V_12 -> V_1 . V_23 ) ;
if ( V_15 != 0 ) {
F_5 ( 2 , L_1 ,
V_8 . V_24 , V_8 . V_26 ,
V_12 -> V_1 . V_23 ) ;
goto V_29;
}
if ( ! V_12 -> V_30 ) {
V_15 = - V_28 ;
goto V_29;
}
V_15 = 0 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
if ( ( V_12 -> V_31 != V_32 ) &&
( V_12 -> V_31 != V_33 ) )
goto V_29;
V_10 -> V_34 = V_12 -> V_34 ;
V_10 -> V_35 = V_12 -> V_35 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
V_17 = 0x80 >> V_16 ;
if ( V_12 -> V_34 & V_17 ) {
F_6 ( & V_10 -> V_36 [ V_16 ] ) ;
V_10 -> V_36 [ V_16 ] . V_37 = V_12 -> V_36 [ V_16 ] ;
}
if ( V_12 -> V_35 & V_17 )
V_10 -> V_38 [ V_16 ] = V_12 -> V_38 [ V_16 ] ;
}
V_29:
F_7 ( & V_18 , V_13 ) ;
return V_15 ;
}
int F_8 ( struct V_7 V_8 , struct V_39 * V_40 )
{
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_21 . V_22 = 0x0010 ;
V_40 -> V_21 . V_23 = 0x0024 ;
V_40 -> V_41 = V_8 . V_26 ;
V_40 -> V_42 = V_8 . V_26 ;
V_40 -> V_24 = V_8 . V_24 ;
if ( F_4 ( V_40 ) )
return - V_6 ;
return F_1 ( V_40 -> V_1 . V_23 ) ;
}
int F_9 ( struct V_7 V_8 , struct V_43 * V_44 ,
T_1 V_45 , T_1 V_46 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_21 . V_22 = 0x0fe0 ;
V_44 -> V_21 . V_23 = 0x0021 ;
V_44 -> V_47 = 0 ;
V_44 -> V_45 = V_45 ;
V_44 -> V_46 = V_46 ;
V_44 -> V_48 = V_49 >> 4 ;
V_44 -> V_50 = V_49 >> 4 ;
V_44 -> V_51 = V_52 ;
V_44 -> V_8 = V_8 ;
if ( V_53 . V_54 )
V_44 -> V_55 = 0x10000000 ;
if ( F_4 ( V_44 ) )
return - V_6 ;
return F_1 ( V_44 -> V_1 . V_23 ) ;
}
static int F_10 ( struct V_56 * V_57 , void * V_58 )
{
F_11 ( V_57 -> V_59 ) ;
if ( V_57 -> V_60 && V_57 -> V_60 -> V_61 )
if ( V_57 -> V_60 -> V_61 ( V_57 , V_58 , V_62 ) != 0 )
goto V_63;
F_12 ( V_57 -> V_59 ) ;
return 0 ;
V_63:
V_57 -> V_64 = 0 ;
F_12 ( V_57 -> V_59 ) ;
F_13 ( V_57 -> V_8 ) ;
return 0 ;
}
void F_14 ( struct V_65 V_36 )
{
struct V_66 * V_67 = F_15 ( V_36 ) ;
struct V_68 V_69 ;
char V_70 [ 15 ] ;
sprintf ( V_70 , L_2 , V_36 . V_71 , V_36 . V_37 ) ;
F_16 ( 2 , V_70 ) ;
if ( F_17 ( V_36 ) <= 0 )
return;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 . V_36 = V_36 ;
F_18 () ;
F_19 ( & V_67 -> V_59 ) ;
F_20 ( V_67 ) ;
F_21 ( & V_67 -> V_59 ) ;
F_22 ( F_10 , NULL , & V_69 ) ;
}
static int F_23 ( struct V_56 * V_57 , void * V_58 )
{
F_11 ( V_57 -> V_59 ) ;
if ( V_57 -> V_60 && V_57 -> V_60 -> V_61 )
V_57 -> V_60 -> V_61 ( V_57 , V_58 , V_72 ) ;
F_12 ( V_57 -> V_59 ) ;
return 0 ;
}
static void F_24 ( struct V_68 * V_69 )
{
char V_70 [ 15 ] ;
sprintf ( V_70 , L_3 , V_69 -> V_36 . V_71 ,
V_69 -> V_36 . V_37 ) ;
F_16 ( 2 , V_70 ) ;
if ( V_69 -> V_38 != 0 ) {
sprintf ( V_70 , L_4 , V_69 -> V_38 ) ;
F_16 ( 2 , V_70 ) ;
}
F_18 () ;
F_22 ( F_23 , NULL , V_69 ) ;
F_25 () ;
}
static char * F_26 ( char * V_73 , const char * V_74 , unsigned long V_75 ,
char V_76 )
{
memcpy ( V_73 , V_74 , V_75 ) ;
F_27 ( V_73 , V_75 ) ;
if ( V_76 )
V_73 [ V_75 ++ ] = V_76 ;
return V_73 + V_75 ;
}
static void F_28 ( char * V_77 , char * V_37 , struct V_78 * V_79 )
{
memset ( V_77 , 0 , V_80 ) ;
memset ( V_37 , 0 , V_81 ) ;
if ( V_79 -> V_82 != V_83 ) {
strncpy ( V_77 , L_5 , V_80 - 1 ) ;
strncpy ( V_37 , L_5 , V_81 - 1 ) ;
return;
}
snprintf ( V_77 , V_80 , L_6 , V_79 -> V_84 , V_79 -> V_77 ) ;
V_37 = F_26 ( V_37 , V_79 -> type , sizeof( V_79 -> type ) , '/' ) ;
V_37 = F_26 ( V_37 , V_79 -> V_85 , sizeof( V_79 -> V_85 ) , ',' ) ;
V_37 = F_26 ( V_37 , V_79 -> V_86 , sizeof( V_79 -> V_86 ) , '.' ) ;
V_37 = F_26 ( V_37 , V_79 -> V_87 , sizeof( V_79 -> V_87 ) , 0 ) ;
V_37 = F_26 ( V_37 , V_79 -> V_88 , sizeof( V_79 -> V_88 ) , ',' ) ;
sprintf ( V_37 , L_7 , V_79 -> V_89 ) ;
}
static void F_29 ( struct V_90 * V_91 )
{
struct V_92 * V_92 = (struct V_92 * ) & V_91 -> V_93 ;
char V_94 [ V_80 ] , V_95 [ V_81 ] , V_96 [ V_80 ] ,
V_97 [ V_81 ] ;
F_30 ( 4 , L_8 ,
V_91 -> V_98 , V_91 -> V_99 , V_91 -> V_93 [ 0 ] ) ;
if ( V_92 -> V_100 . null )
return;
F_28 ( V_94 , V_95 , & V_92 -> V_101 ) ;
F_28 ( V_96 , V_97 , & V_92 -> V_102 ) ;
switch ( V_92 -> V_100 . V_103 ) {
case V_104 :
F_31 ( L_9
L_10 ,
V_91 -> V_98 , V_91 -> V_99 , V_92 -> V_105 , V_94 ,
V_95 , V_96 , V_97 ) ;
break;
case V_106 :
F_32 ( L_11
L_10 ,
V_91 -> V_98 , V_91 -> V_99 , V_92 -> V_105 , V_94 ,
V_95 , V_96 , V_97 ) ;
break;
default:
break;
}
}
static void F_33 ( struct V_90 * V_91 )
{
struct V_68 V_69 ;
struct V_65 V_36 ;
int V_107 ;
F_30 ( 4 , L_12
L_13 , V_91 -> V_98 , V_91 -> V_99 ) ;
if ( V_91 -> V_98 != 4 )
return;
F_6 ( & V_36 ) ;
V_36 . V_37 = V_91 -> V_99 ;
V_107 = F_17 ( V_36 ) ;
if ( V_107 < 0 )
F_34 ( V_36 ) ;
else if ( ! V_107 )
return;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 . V_36 = V_36 ;
if ( ( V_91 -> V_108 & 0xc0 ) != 0 ) {
V_69 . V_38 = V_91 -> V_38 ;
if ( ( V_91 -> V_108 & 0xc0 ) == 0xc0 )
V_69 . V_109 = 0xffff ;
else
V_69 . V_109 = 0xff00 ;
}
F_24 ( & V_69 ) ;
}
static void F_35 ( struct V_90 * V_91 )
{
struct V_66 * V_67 ;
struct V_65 V_36 ;
T_2 * V_58 ;
int V_110 ;
F_30 ( 4 , L_14 ) ;
if ( V_91 -> V_98 != 0 )
return;
V_58 = V_91 -> V_93 ;
F_6 ( & V_36 ) ;
for ( V_110 = 0 ; V_110 <= V_111 ; V_110 ++ ) {
if ( ! F_36 ( V_58 , V_110 ) )
continue;
V_36 . V_37 = V_110 ;
F_30 ( 4 , L_15
L_16 , V_36 . V_71 , V_36 . V_37 ) ;
V_67 = F_15 ( V_36 ) ;
if ( ! V_67 ) {
F_34 ( V_36 ) ;
continue;
}
F_19 ( & V_67 -> V_59 ) ;
F_20 ( V_67 ) ;
F_21 ( & V_67 -> V_59 ) ;
}
}
static void F_37 ( struct V_90 * V_91 )
{
struct V_112 * V_58 ;
struct V_65 V_36 ;
int V_110 ;
char * V_113 [ 3 ] = { L_17 , L_18 , L_19 } ;
F_30 ( 4 , L_20 ) ;
if ( V_91 -> V_98 != 0 )
return;
V_58 = (struct V_112 * ) & ( V_91 -> V_93 ) ;
F_6 ( & V_36 ) ;
for ( V_110 = 0 ; V_110 <= V_111 ; V_110 ++ ) {
if ( ! F_36 ( V_58 -> V_114 , V_110 ) )
continue;
V_36 . V_37 = V_110 ;
F_38 ( L_21 ,
V_113 [ V_58 -> V_115 ] , V_36 . V_71 , V_36 . V_37 ) ;
switch ( V_58 -> V_115 ) {
case 0 :
F_39 ( V_36 , 1 ) ;
break;
case 1 :
F_39 ( V_36 , 0 ) ;
break;
case 2 :
F_40 ( V_36 ) ;
break;
}
}
}
static void F_41 ( struct V_90 * V_91 )
{
int V_15 ;
F_30 ( 4 , L_22 ) ;
if ( V_91 -> V_98 != 7 )
return;
V_15 = F_42 () ;
if ( V_15 )
F_30 ( 0 , L_23
L_24 , V_15 ) ;
}
static void F_43 ( struct V_90 * V_91 )
{
int V_15 ;
F_30 ( 4 , L_25 ) ;
if ( V_91 -> V_98 != 7 )
return;
V_15 = F_44 () ;
if ( V_15 )
F_30 ( 0 , L_26
L_24 , V_15 ) ;
}
static void F_45 ( struct V_116 * V_91 )
{
switch ( V_91 -> V_117 ) {
case 1 :
F_46 ( V_91 -> V_93 ) ;
break;
case 2 :
F_47 ( V_91 -> V_93 ) ;
break;
default:
F_30 ( 2 , L_27 ,
V_91 -> V_117 ) ;
break;
}
}
static void F_48 ( struct V_90 * V_91 )
{
switch ( V_91 -> V_117 ) {
case 1 :
F_29 ( V_91 ) ;
break;
case 2 :
F_33 ( V_91 ) ;
break;
case 7 :
F_35 ( V_91 ) ;
break;
case 8 :
F_37 ( V_91 ) ;
break;
case 12 :
F_41 ( V_91 ) ;
break;
case 14 :
F_43 ( V_91 ) ;
break;
default:
F_30 ( 2 , L_28 ,
V_91 -> V_117 ) ;
break;
}
if ( V_91 -> V_13 & 0x40 ) {
F_30 ( 2 , L_29 ) ;
F_49 () ;
}
}
static void F_50 ( struct V_118 * V_119 , T_1 V_120 )
{
static int V_121 ;
while ( true ) {
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_21 . V_22 = 0x0010 ;
V_119 -> V_21 . V_23 = 0x000e ;
if ( ! V_121 )
V_119 -> V_120 = V_120 ;
if ( F_4 ( V_119 ) )
break;
if ( V_119 -> V_1 . V_23 != 0x0001 ) {
F_30 ( 2 , L_30 ,
V_119 -> V_1 . V_23 , V_119 -> V_120 ) ;
if ( V_119 -> V_1 . V_23 == 3 && V_119 -> V_120 ) {
V_121 = 1 ;
continue;
}
break;
}
F_30 ( 2 , L_31 , V_119 -> V_122 ) ;
switch ( V_119 -> V_122 ) {
case 0 :
F_48 ( & V_119 -> V_123 . V_124 ) ;
break;
case 2 :
F_45 ( & V_119 -> V_123 . V_125 ) ;
break;
default:
F_30 ( 2 , L_32 , V_119 -> V_122 ) ;
break;
}
if ( ! ( V_119 -> V_123 . V_124 . V_13 & 0x80 ) )
break;
}
}
static void F_51 ( struct V_126 * V_127 , struct V_126 * V_128 , int V_129 )
{
struct V_118 * V_119 = V_130 ;
if ( V_129 ) {
F_49 () ;
return;
}
F_30 ( 2 , L_33
L_34 ,
V_127 -> V_131 , V_127 -> V_132 , V_127 -> V_133 , V_127 -> V_134 , V_127 -> V_135 ,
V_127 -> V_136 , V_127 -> V_99 ) ;
F_16 ( 2 , L_35 ) ;
F_50 ( V_119 , V_137 | V_138 ) ;
}
void F_52 ( struct V_65 V_36 )
{
struct V_66 * V_67 = F_15 ( V_36 ) ;
struct V_68 V_69 ;
char V_70 [ 15 ] ;
sprintf ( V_70 , L_36 , V_36 . V_71 , V_36 . V_37 ) ;
F_16 ( 2 , V_70 ) ;
if ( F_17 ( V_36 ) != 0 ) {
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 . V_36 = V_36 ;
F_18 () ;
F_19 ( & V_67 -> V_59 ) ;
F_20 ( V_67 ) ;
F_21 ( & V_67 -> V_59 ) ;
F_22 ( F_23 , NULL ,
& V_69 ) ;
F_25 () ;
}
}
static void F_53 ( struct V_56 * V_57 ,
struct V_65 V_36 , int V_139 )
{
unsigned long V_13 ;
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 . V_36 = V_36 ;
F_3 ( V_57 -> V_59 , V_13 ) ;
if ( V_57 -> V_60 && V_57 -> V_60 -> V_61 )
V_57 -> V_60 -> V_61 ( V_57 , & V_69 ,
V_139 ? V_140 : V_141 ) ;
F_7 ( V_57 -> V_59 , V_13 ) ;
}
static int F_54 ( struct V_56 * V_57 , void * V_58 )
{
struct V_65 * V_36 = V_58 ;
F_53 ( V_57 , * V_36 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_56 * V_57 , void * V_58 )
{
struct V_65 * V_36 = V_58 ;
F_53 ( V_57 , * V_36 , 1 ) ;
return 0 ;
}
int F_56 ( struct V_65 V_36 , int V_139 )
{
struct V_66 * V_67 = F_15 ( V_36 ) ;
F_18 () ;
if ( V_139 ) {
F_20 ( V_67 ) ;
F_22 ( F_55 ,
NULL , & V_36 ) ;
F_25 () ;
} else
F_22 ( F_54 ,
NULL , & V_36 ) ;
return 0 ;
}
static void
F_57 ( struct V_142 * V_143 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 <= V_111 ; V_16 ++ ) {
if ( ! V_143 -> V_144 [ V_16 ] )
continue;
F_58 ( V_143 -> V_144 [ V_16 ] ) ;
}
}
static int
F_59 ( struct V_142 * V_143 )
{
int V_16 , V_15 ;
V_15 = 0 ;
for ( V_16 = 0 ; V_16 <= V_111 ; V_16 ++ ) {
if ( ! V_143 -> V_144 [ V_16 ] )
continue;
V_15 = F_60 ( V_143 -> V_144 [ V_16 ] ) ;
if ( V_15 )
goto V_145;
}
return V_15 ;
V_145:
for ( -- V_16 ; V_16 >= 0 ; V_16 -- ) {
if ( ! V_143 -> V_144 [ V_16 ] )
continue;
F_58 ( V_143 -> V_144 [ V_16 ] ) ;
}
return V_15 ;
}
int F_61 ( struct V_142 * V_143 , int V_146 )
{
struct {
struct V_147 V_21 ;
T_3 V_47 : 2 ;
T_3 : 30 ;
T_3 V_148 : 4 ;
T_3 : 28 ;
T_3 V_149 ;
T_3 V_150 ;
T_3 V_151 ;
T_3 V_152 ;
T_3 V_153 [ 13 ] ;
struct V_147 V_1 ;
T_3 V_107 : 8 ;
T_3 : 4 ;
T_3 V_154 : 4 ;
T_3 : 16 ;
} V_155 ( ( V_156 ) ) * V_157 ;
unsigned long V_13 ;
int V_15 , V_14 ;
F_3 ( & V_18 , V_13 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_157 = V_19 ;
V_157 -> V_21 . V_22 = 0x0050 ;
V_157 -> V_21 . V_23 = 0x0016 ;
V_157 -> V_148 = V_49 >> 4 ;
V_157 -> V_150 = ( T_1 ) ( unsigned long ) V_143 -> V_150 ;
V_157 -> V_152 = ( T_1 ) ( unsigned long ) V_143 -> V_152 ;
V_157 -> V_47 = V_146 ? 0 : 1 ;
V_14 = F_4 ( V_157 ) ;
if ( V_14 > 0 ) {
V_15 = ( V_14 == 3 ) ? - V_28 : - V_4 ;
goto V_29;
}
switch ( V_157 -> V_1 . V_23 ) {
case 0x0102 :
case 0x0103 :
V_15 = - V_2 ;
break;
default:
V_15 = F_1 ( V_157 -> V_1 . V_23 ) ;
}
if ( V_15 != 0 )
F_30 ( 2 , L_37 ,
V_157 -> V_1 . V_23 ) ;
V_29:
F_7 ( & V_18 , V_13 ) ;
return V_15 ;
}
int
F_62 ( struct V_142 * V_143 , int V_146 )
{
int V_15 ;
if ( V_146 && ! V_143 -> V_158 ) {
V_143 -> V_150 = ( void * ) F_63 ( V_159 | V_160 ) ;
V_143 -> V_152 = ( void * ) F_63 ( V_159 | V_160 ) ;
if ( ! V_143 -> V_150 || ! V_143 -> V_152 ) {
F_64 ( ( unsigned long ) V_143 -> V_150 ) ;
F_64 ( ( unsigned long ) V_143 -> V_152 ) ;
return - V_5 ;
}
}
V_15 = F_61 ( V_143 , V_146 ) ;
if ( ! V_15 ) {
V_143 -> V_158 = V_146 ;
if ( V_143 -> V_158 ) {
V_15 = F_59 ( V_143 ) ;
if ( V_15 ) {
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
return V_15 ;
}
int F_65 ( struct V_65 V_36 , int V_154 , int V_161 ,
int V_162 , int V_163 , void * V_164 )
{
struct V_165 * V_166 ;
int V_14 , V_15 ;
if ( ( V_161 == 1 || V_161 == 0 ) && V_162 == 1 &&
! V_53 . V_167 )
return - V_2 ;
if ( ( V_161 == 2 ) && ! V_53 . V_168 )
return - V_2 ;
memset ( V_164 , 0 , V_20 ) ;
V_166 = V_164 ;
V_166 -> V_21 . V_22 = 0x0010 ;
V_166 -> V_21 . V_23 = 0x0002 ;
V_166 -> V_71 = V_36 . V_71 ;
V_166 -> V_169 = V_36 . V_37 ;
V_166 -> V_170 = V_36 . V_37 ;
V_166 -> V_163 = V_163 ;
V_166 -> V_162 = V_162 ;
V_166 -> V_154 = V_154 ;
V_166 -> V_161 = V_161 ;
V_14 = F_4 ( V_166 ) ;
if ( V_14 > 0 )
return ( V_14 == 3 ) ? - V_28 : - V_4 ;
V_15 = F_1 ( V_166 -> V_1 . V_23 ) ;
if ( V_15 )
F_30 ( 2 , L_38 ,
V_166 -> V_1 . V_23 ) ;
return V_15 ;
}
int F_66 ( struct V_65 V_36 ,
struct V_171 * V_172 )
{
struct V_165 * V_166 ;
unsigned long V_13 ;
int V_15 ;
F_3 ( & V_18 , V_13 ) ;
V_166 = V_19 ;
V_15 = F_65 ( V_36 , 0 , 0 , 0 , 0 , V_166 ) ;
if ( V_15 )
goto V_29;
memcpy ( V_172 , V_166 -> V_58 , sizeof( * V_172 ) ) ;
V_29:
F_7 ( & V_18 , V_13 ) ;
return V_15 ;
}
int F_67 ( struct V_65 V_36 ,
struct V_173 * V_172 )
{
struct V_165 * V_166 ;
unsigned long V_13 ;
int V_15 ;
F_3 ( & V_18 , V_13 ) ;
V_166 = V_19 ;
V_15 = F_65 ( V_36 , 0 , 1 , 1 , 0 , V_166 ) ;
if ( V_15 )
goto V_29;
memcpy ( V_172 , V_166 -> V_58 , sizeof( * V_172 ) ) ;
V_29:
F_7 ( & V_18 , V_13 ) ;
return V_15 ;
}
static void
F_68 ( struct V_66 * V_67 , T_2 V_174 ,
struct V_175 * V_176 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < V_177 ; V_16 ++ ) {
V_17 = 0x80 >> ( V_16 + 3 ) ;
if ( V_174 & V_17 )
V_67 -> V_175 . V_178 [ V_16 ] = V_176 -> V_178 [ V_16 ] ;
else
V_67 -> V_175 . V_178 [ V_16 ] = 0 ;
}
}
int F_69 ( struct V_66 * V_67 )
{
unsigned long V_13 ;
int V_14 , V_15 ;
struct {
struct V_147 V_21 ;
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
T_3 V_36 : 8 ;
T_3 V_174 : 5 ;
T_3 : 11 ;
T_3 V_181 : 8 ;
T_3 V_182 : 8 ;
T_3 V_183 ;
T_3 V_58 [ V_177 ] ;
} V_155 ( ( V_156 ) ) * V_184 ;
V_67 -> V_180 = - 1 ;
V_67 -> V_182 = - 1 ;
if ( ! V_185 . V_186 || ! V_185 . V_187 )
return - V_2 ;
F_3 ( & V_18 , V_13 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_184 = V_19 ;
V_184 -> V_21 . V_22 = 0x0010 ;
V_184 -> V_21 . V_23 = 0x0022 ;
V_184 -> V_169 = V_67 -> V_36 . V_37 ;
V_184 -> V_170 = V_67 -> V_36 . V_37 ;
V_14 = F_4 ( V_184 ) ;
if ( V_14 > 0 ) {
V_15 = ( V_14 == 3 ) ? - V_28 : - V_4 ;
goto V_29;
}
V_15 = F_1 ( V_184 -> V_1 . V_23 ) ;
if ( V_15 ) {
F_30 ( 2 , L_39 ,
V_184 -> V_1 . V_23 ) ;
goto V_29;
}
if ( V_184 -> V_179 )
goto V_29;
V_67 -> V_182 = V_184 -> V_182 ;
V_67 -> V_180 = V_184 -> V_180 ;
if ( V_67 -> V_182 != 2 && V_67 -> V_182 != 3 ) {
goto V_29;
}
F_68 ( V_67 , V_184 -> V_174 ,
(struct V_175 * ) & V_184 -> V_58 ) ;
V_29:
F_7 ( & V_18 , V_13 ) ;
return V_15 ;
}
int T_4 F_70 ( void )
{
int V_15 ;
V_130 = ( void * ) F_63 ( V_159 | V_160 ) ;
V_19 = ( void * ) F_63 ( V_159 | V_160 ) ;
if ( ! V_130 || ! V_19 ) {
V_15 = - V_5 ;
goto V_188;
}
V_15 = F_71 ( V_189 , F_51 ) ;
if ( V_15 )
goto V_188;
return V_15 ;
V_188:
F_64 ( ( unsigned long ) V_19 ) ;
F_64 ( ( unsigned long ) V_130 ) ;
return V_15 ;
}
void T_4 F_72 ( void )
{
F_73 ( V_189 ) ;
F_64 ( ( unsigned long ) V_19 ) ;
F_64 ( ( unsigned long ) V_130 ) ;
}
int F_74 ( struct V_190 * V_191 , int V_47 )
{
int V_15 ;
V_191 -> V_21 . V_22 = 0x0400 ;
V_191 -> V_21 . V_23 = 0x0031 ;
V_191 -> V_47 = V_47 ;
V_15 = F_4 ( V_191 ) ;
if ( V_15 > 0 ) {
V_15 = ( V_15 == 3 ) ? - V_28 : - V_4 ;
goto V_29;
}
switch ( V_191 -> V_1 . V_23 ) {
case 0x0101 :
V_15 = - V_3 ;
break;
default:
V_15 = F_1 ( V_191 -> V_1 . V_23 ) ;
}
V_29:
return V_15 ;
}
int F_75 ( int V_47 )
{
struct V_190 * V_191 ;
unsigned long V_13 ;
int V_15 ;
F_3 ( & V_18 , V_13 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_191 = V_19 ;
V_15 = F_74 ( V_191 , V_47 ) ;
if ( V_15 != 0 )
F_30 ( 2 , L_40 ,
V_47 , V_191 -> V_1 . V_23 ) ;
F_7 ( & V_18 , V_13 ) ;
return V_15 ;
}
int T_4 F_76 ( int V_192 )
{
struct {
struct V_147 V_21 ;
T_2 V_193 ;
T_3 : 24 ;
T_3 V_194 [ 6 ] ;
struct V_147 V_1 ;
T_3 V_195 [ 3 ] ;
struct {
T_2 V_71 ;
T_3 : 24 ;
} V_196 [ 0 ] ;
} V_197 * V_198 ;
int V_15 ;
F_11 ( & V_18 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_198 = V_19 ;
V_198 -> V_21 . V_22 = 0x0020 ;
V_198 -> V_21 . V_23 = 0x0034 ;
V_198 -> V_193 = 4 ;
V_15 = F_4 ( V_198 ) ;
if ( V_15 ) {
V_15 = ( V_15 == 3 ) ? - V_28 : - V_4 ;
goto exit;
}
V_15 = F_1 ( V_198 -> V_1 . V_23 ) ;
if ( V_15 ) {
F_30 ( 2 , L_41 ,
V_198 -> V_1 . V_23 ) ;
goto exit;
}
if ( ( V_199 ) & V_198 -> V_196 [ V_192 ] <
( V_199 ) & V_198 -> V_1 + V_198 -> V_1 . V_22 )
V_15 = V_198 -> V_196 [ V_192 ] . V_71 ;
else
V_15 = - V_28 ;
exit:
F_12 ( & V_18 ) ;
return V_15 ;
}
int T_4
F_77 ( void )
{
unsigned long V_13 ;
int V_200 ;
struct {
struct V_147 V_21 ;
T_3 V_194 ;
T_3 V_195 ;
T_3 V_201 ;
struct V_147 V_1 ;
T_3 V_202 ;
T_3 V_203 [ 510 ] ;
T_3 V_204 [ 508 ] ;
} V_155 ( ( V_156 ) ) * V_205 ;
F_3 ( & V_18 , V_13 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_205 = V_19 ;
V_205 -> V_21 . V_22 = 0x0010 ;
V_205 -> V_21 . V_23 = 0x0010 ;
V_200 = F_4 ( V_205 ) ;
if ( V_200 ) {
V_200 = ( V_200 == 3 ) ? - V_28 : - V_4 ;
goto exit;
}
V_200 = F_1 ( V_205 -> V_1 . V_23 ) ;
if ( V_200 == 0 ) {
memcpy ( & V_53 , V_205 -> V_203 ,
sizeof( V_53 ) ) ;
memcpy ( & V_185 , V_205 -> V_204 ,
sizeof( V_185 ) ) ;
} else
F_30 ( 2 , L_42 ,
V_205 -> V_1 . V_23 ) ;
exit:
F_7 ( & V_18 , V_13 ) ;
return V_200 ;
}
int F_78 ( void * V_164 , unsigned int V_115 , T_5 V_206 , T_1 * V_207 )
{
struct {
struct V_147 V_21 ;
unsigned int V_208 ;
unsigned int V_115 : 8 ;
unsigned int V_209 : 8 ;
unsigned int V_206 : 16 ;
unsigned int V_210 [ 5 ] ;
struct V_147 V_1 ;
unsigned int V_211 [ 3 ] ;
T_1 V_207 ;
unsigned int V_212 [ 2 ] ;
} V_155 ( ( V_156 ) ) * V_213 ;
int V_214 ;
memset ( V_164 , 0 , V_20 ) ;
V_213 = V_164 ;
V_213 -> V_21 . V_22 = 0x0020 ;
V_213 -> V_21 . V_23 = 0x0033 ;
V_213 -> V_115 = V_115 ;
V_213 -> V_206 = V_206 ;
V_214 = F_4 ( V_213 ) ;
if ( V_214 )
return - V_6 ;
V_214 = ( V_213 -> V_1 . V_23 == 0x0001 ) ? 0 : - V_6 ;
if ( V_207 )
* V_207 = V_213 -> V_207 ;
return V_214 ;
}
int F_79 ( void * V_164 , void * V_200 , T_6 V_215 )
{
struct {
struct V_147 V_21 ;
unsigned int V_208 [ 3 ] ;
struct V_147 V_1 ;
char V_58 [] ;
} V_155 ( ( V_156 ) ) * V_213 ;
int V_214 ;
memset ( V_164 , 0 , V_20 ) ;
V_213 = V_164 ;
V_213 -> V_21 . V_22 = 0x0010 ;
V_213 -> V_21 . V_23 = 0x0038 ;
V_214 = F_4 ( V_213 ) ;
if ( V_214 )
return - V_6 ;
memcpy ( V_200 , & V_213 -> V_58 , V_215 ) ;
return ( V_213 -> V_1 . V_23 == 0x0001 ) ? 0 : - V_6 ;
}
int F_80 ( struct V_7 V_8 )
{
struct {
struct V_147 V_21 ;
T_3 V_216 ;
struct V_7 V_217 ;
T_3 V_218 ;
struct V_147 V_1 ;
T_3 V_219 [ 11 ] ;
} V_155 ( ( V_156 ) ) * V_220 ;
unsigned long V_13 ;
int V_14 ;
int V_214 ;
F_3 ( & V_18 , V_13 ) ;
memset ( V_19 , 0 , V_20 ) ;
V_220 = V_19 ;
V_220 -> V_21 . V_22 = 0x0010 ;
V_220 -> V_21 . V_23 = 0x0046 ;
V_220 -> V_216 = 0x80000000 ;
V_220 -> V_217 = V_8 ;
V_14 = F_4 ( V_220 ) ;
if ( V_14 > 0 ) {
if ( V_14 == 3 )
V_214 = - V_28 ;
else
V_214 = - V_4 ;
F_5 ( 2 , L_43 ,
V_8 . V_24 , V_8 . V_26 , V_14 ) ;
goto V_29;
}
V_214 = F_1 ( V_220 -> V_1 . V_23 ) ;
if ( V_214 )
F_5 ( 2 , L_44 ,
V_8 . V_24 , V_8 . V_26 ,
V_220 -> V_1 . V_23 ) ;
else
F_5 ( 4 , L_45 ,
V_8 . V_24 , V_8 . V_26 ) ;
V_29:
F_7 ( & V_18 , V_13 ) ;
return V_214 ;
}
int F_81 ( struct F_81 * V_221 , T_1 V_222 )
{
int V_14 , V_15 ;
memset ( V_221 , 0 , sizeof( * V_221 ) ) ;
V_221 -> V_21 . V_22 = 0x0020 ;
V_221 -> V_21 . V_23 = 0x004C ;
V_221 -> V_223 = V_222 ;
V_14 = F_4 ( V_221 ) ;
if ( V_14 > 0 ) {
V_15 = ( V_14 == 3 ) ? - V_28 : - V_4 ;
goto V_29;
}
V_15 = F_1 ( V_221 -> V_1 . V_23 ) ;
if ( V_15 != 0 )
F_5 ( 2 , L_46 ,
V_221 -> V_1 . V_23 ) ;
V_29:
return V_15 ;
}
int F_82 ( struct V_7 V_8 ,
struct V_224 * V_225 ,
struct V_226 V_227 ,
int V_228 )
{
memset ( V_225 , 0 , sizeof( * V_225 ) ) ;
V_225 -> V_21 . V_22 = 0x0030 ;
V_225 -> V_21 . V_23 = 0x003d ;
V_225 -> V_163 = V_8 . V_163 ;
V_225 -> V_24 = V_8 . V_24 ;
V_225 -> V_57 = V_8 . V_26 ;
V_225 -> V_71 = V_8 . V_71 ;
V_225 -> V_229 = 0 ;
V_225 -> V_227 = V_227 ;
V_225 -> V_230 = ( V_228 != 0 ) ;
if ( F_4 ( V_225 ) )
return - V_6 ;
return F_1 ( V_225 -> V_1 . V_23 ) ;
}
