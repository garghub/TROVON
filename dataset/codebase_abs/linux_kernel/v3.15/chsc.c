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
char V_65 [ 15 ] ;
struct V_66 V_67 ;
sprintf ( V_65 , L_2 , V_35 . V_68 , V_35 . V_36 ) ;
F_13 ( 2 , V_65 ) ;
if ( F_14 ( V_35 ) <= 0 )
return;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
F_15 () ;
F_16 ( F_10 , NULL , & V_67 ) ;
}
static int F_17 ( struct V_55 * V_56 , void * V_57 )
{
F_3 ( V_56 -> V_58 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
V_56 -> V_59 -> V_60 ( V_56 , V_57 , V_69 ) ;
F_7 ( V_56 -> V_58 ) ;
return 0 ;
}
static void F_18 ( struct V_66 * V_67 )
{
char V_65 [ 15 ] ;
sprintf ( V_65 , L_3 , V_67 -> V_35 . V_68 ,
V_67 -> V_35 . V_36 ) ;
F_13 ( 2 , V_65 ) ;
if ( V_67 -> V_37 != 0 ) {
sprintf ( V_65 , L_4 , V_67 -> V_37 ) ;
F_13 ( 2 , V_65 ) ;
}
F_15 () ;
F_16 ( F_17 , NULL , V_67 ) ;
F_19 () ;
}
static int
F_20 ( void * V_57 )
{
struct V_70 {
T_2 V_71 ;
T_2 V_72 ;
T_3 V_73 ;
T_4 V_74 [ 28 ] ;
T_4 V_75 [ 28 ] ;
T_4 V_76 [ 28 ] ;
} V_77 ( ( V_78 ) ) * V_70 ;
V_70 = V_57 ;
if ( ! ( V_70 -> V_71 & 0x80 ) )
return - V_2 ;
if ( ! ( V_70 -> V_74 [ 0 ] & 0xc0000000 ) )
return - V_2 ;
if ( ! ( V_70 -> V_74 [ 0 ] & 0x10000000 ) )
return - V_2 ;
return ( T_3 ) ( V_70 -> V_74 [ 0 ] & 0x000000ff ) ;
}
static void F_21 ( struct V_79 * V_80 )
{
struct V_64 V_35 ;
int V_36 ;
F_22 ( 4 , L_5 ,
V_80 -> V_81 , V_80 -> V_82 ) ;
if ( V_80 -> V_81 != 4 )
return;
V_36 = F_20 ( V_80 -> V_83 ) ;
if ( V_36 < 0 )
F_22 ( 4 , L_6 ) ;
else {
F_6 ( & V_35 ) ;
V_35 . V_36 = V_36 ;
F_12 ( V_35 ) ;
}
}
static void F_23 ( struct V_79 * V_80 )
{
struct V_66 V_67 ;
struct V_64 V_35 ;
int V_84 ;
F_22 ( 4 , L_7
L_8 , V_80 -> V_81 , V_80 -> V_82 ) ;
if ( V_80 -> V_81 != 4 )
return;
F_6 ( & V_35 ) ;
V_35 . V_36 = V_80 -> V_82 ;
V_84 = F_14 ( V_35 ) ;
if ( V_84 < 0 )
F_24 ( V_35 ) ;
else if ( ! V_84 )
return;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
if ( ( V_80 -> V_85 & 0xc0 ) != 0 ) {
V_67 . V_37 = V_80 -> V_37 ;
if ( ( V_80 -> V_85 & 0xc0 ) == 0xc0 )
V_67 . V_86 = 0xffff ;
else
V_67 . V_86 = 0xff00 ;
}
F_18 ( & V_67 ) ;
}
static void F_25 ( struct V_79 * V_80 )
{
struct V_87 * V_88 ;
struct V_64 V_35 ;
T_2 * V_57 ;
int V_89 ;
F_22 ( 4 , L_9 ) ;
if ( V_80 -> V_81 != 0 )
return;
V_57 = V_80 -> V_83 ;
F_6 ( & V_35 ) ;
for ( V_89 = 0 ; V_89 <= V_90 ; V_89 ++ ) {
if ( ! F_26 ( V_57 , V_89 ) )
continue;
V_35 . V_36 = V_89 ;
F_22 ( 4 , L_10
L_11 , V_35 . V_68 , V_35 . V_36 ) ;
V_88 = F_27 ( V_35 ) ;
if ( ! V_88 ) {
F_24 ( V_35 ) ;
continue;
}
F_28 ( & V_88 -> V_58 ) ;
F_29 ( V_88 ) ;
F_30 ( & V_88 -> V_58 ) ;
}
}
static void F_31 ( struct V_79 * V_80 )
{
struct V_91 * V_57 ;
struct V_64 V_35 ;
int V_89 ;
char * V_92 [ 3 ] = { L_12 , L_13 , L_14 } ;
F_22 ( 4 , L_15 ) ;
if ( V_80 -> V_81 != 0 )
return;
V_57 = (struct V_91 * ) & ( V_80 -> V_83 ) ;
F_6 ( & V_35 ) ;
for ( V_89 = 0 ; V_89 <= V_90 ; V_89 ++ ) {
if ( ! F_26 ( V_57 -> V_93 , V_89 ) )
continue;
V_35 . V_36 = V_89 ;
F_32 ( L_16 ,
V_92 [ V_57 -> V_94 ] , V_35 . V_68 , V_35 . V_36 ) ;
switch ( V_57 -> V_94 ) {
case 0 :
F_33 ( V_35 , 1 ) ;
break;
case 1 :
F_33 ( V_35 , 0 ) ;
break;
case 2 :
F_34 ( V_35 ) ;
break;
}
}
}
static void F_35 ( struct V_79 * V_80 )
{
int V_14 ;
F_22 ( 4 , L_17 ) ;
if ( V_80 -> V_81 != 7 )
return;
V_14 = F_36 () ;
if ( V_14 )
F_22 ( 0 , L_18
L_19 , V_14 ) ;
}
static void F_37 ( struct V_79 * V_80 )
{
int V_14 ;
F_22 ( 4 , L_20 ) ;
if ( V_80 -> V_81 != 7 )
return;
V_14 = F_38 () ;
if ( V_14 )
F_22 ( 0 , L_21
L_19 , V_14 ) ;
}
static void F_39 ( struct V_95 * V_80 )
{
switch ( V_80 -> V_96 ) {
case 1 :
F_40 ( V_80 -> V_83 ) ;
break;
case 2 :
F_41 ( V_80 -> V_83 ) ;
break;
default:
F_22 ( 2 , L_22 ,
V_80 -> V_96 ) ;
break;
}
}
static void F_42 ( struct V_79 * V_80 )
{
switch ( V_80 -> V_96 ) {
case 1 :
F_21 ( V_80 ) ;
break;
case 2 :
F_23 ( V_80 ) ;
break;
case 7 :
F_25 ( V_80 ) ;
break;
case 8 :
F_31 ( V_80 ) ;
break;
case 12 :
F_35 ( V_80 ) ;
break;
case 14 :
F_37 ( V_80 ) ;
break;
default:
F_22 ( 2 , L_23 ,
V_80 -> V_96 ) ;
break;
}
if ( V_80 -> V_97 & 0x40 ) {
F_22 ( 2 , L_24 ) ;
F_43 () ;
}
}
static void F_44 ( struct V_98 * V_99 , T_1 V_100 )
{
static int V_101 ;
while ( true ) {
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_99 -> V_20 . V_21 = 0x0010 ;
V_99 -> V_20 . V_22 = 0x000e ;
if ( ! V_101 )
V_99 -> V_100 = V_100 ;
if ( F_4 ( V_99 ) )
break;
if ( V_99 -> V_1 . V_22 != 0x0001 ) {
F_22 ( 2 , L_25 ,
V_99 -> V_1 . V_22 , V_99 -> V_100 ) ;
if ( V_99 -> V_1 . V_22 == 3 && V_99 -> V_100 ) {
V_101 = 1 ;
continue;
}
break;
}
F_22 ( 2 , L_26 , V_99 -> V_102 ) ;
switch ( V_99 -> V_102 ) {
case 0 :
F_42 ( & V_99 -> V_103 . V_104 ) ;
break;
case 2 :
F_39 ( & V_99 -> V_103 . V_105 ) ;
break;
default:
F_22 ( 2 , L_27 , V_99 -> V_102 ) ;
break;
}
if ( ! ( V_99 -> V_103 . V_104 . V_97 & 0x80 ) )
break;
}
}
static void F_45 ( struct V_106 * V_107 , struct V_106 * V_108 , int V_109 )
{
struct V_98 * V_99 = V_110 ;
if ( V_109 ) {
F_43 () ;
return;
}
F_22 ( 2 , L_28
L_29 ,
V_107 -> V_111 , V_107 -> V_112 , V_107 -> V_113 , V_107 -> V_114 , V_107 -> V_115 ,
V_107 -> V_116 , V_107 -> V_82 ) ;
F_13 ( 2 , L_30 ) ;
F_44 ( V_99 , V_117 | V_118 ) ;
}
void F_46 ( struct V_64 V_35 )
{
char V_65 [ 15 ] ;
struct V_66 V_67 ;
sprintf ( V_65 , L_31 , V_35 . V_68 , V_35 . V_36 ) ;
F_13 ( 2 , V_65 ) ;
if ( F_14 ( V_35 ) != 0 ) {
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
F_15 () ;
F_16 ( F_17 , NULL ,
& V_67 ) ;
F_19 () ;
}
}
static void F_47 ( struct V_55 * V_56 ,
struct V_64 V_35 , int V_119 )
{
unsigned long V_97 ;
struct V_66 V_67 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
F_48 ( V_56 -> V_58 , V_97 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
V_56 -> V_59 -> V_60 ( V_56 , & V_67 ,
V_119 ? V_120 : V_121 ) ;
F_49 ( V_56 -> V_58 , V_97 ) ;
}
static int F_50 ( struct V_55 * V_56 , void * V_57 )
{
struct V_64 * V_35 = V_57 ;
F_47 ( V_56 , * V_35 , 0 ) ;
return 0 ;
}
static int F_51 ( struct V_55 * V_56 , void * V_57 )
{
struct V_64 * V_35 = V_57 ;
F_47 ( V_56 , * V_35 , 1 ) ;
return 0 ;
}
int F_52 ( struct V_64 V_35 , int V_119 )
{
struct V_87 * V_88 = F_27 ( V_35 ) ;
F_15 () ;
if ( V_119 ) {
F_29 ( V_88 ) ;
F_16 ( F_51 ,
NULL , & V_35 ) ;
F_19 () ;
} else
F_16 ( F_50 ,
NULL , & V_35 ) ;
return 0 ;
}
static void
F_53 ( struct V_122 * V_123 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 <= V_90 ; V_15 ++ ) {
if ( ! V_123 -> V_124 [ V_15 ] )
continue;
F_54 ( V_123 -> V_124 [ V_15 ] ) ;
}
}
static int
F_55 ( struct V_122 * V_123 )
{
int V_15 , V_14 ;
V_14 = 0 ;
for ( V_15 = 0 ; V_15 <= V_90 ; V_15 ++ ) {
if ( ! V_123 -> V_124 [ V_15 ] )
continue;
V_14 = F_56 ( V_123 -> V_124 [ V_15 ] ) ;
if ( V_14 )
goto V_125;
}
return V_14 ;
V_125:
for ( -- V_15 ; V_15 >= 0 ; V_15 -- ) {
if ( ! V_123 -> V_124 [ V_15 ] )
continue;
F_54 ( V_123 -> V_124 [ V_15 ] ) ;
}
return V_14 ;
}
int F_57 ( struct V_122 * V_123 , int V_126 )
{
struct {
struct V_127 V_20 ;
T_4 V_46 : 2 ;
T_4 : 30 ;
T_4 V_128 : 4 ;
T_4 : 28 ;
T_4 V_129 ;
T_4 V_130 ;
T_4 V_131 ;
T_4 V_132 ;
T_4 V_133 [ 13 ] ;
struct V_127 V_1 ;
T_4 V_84 : 8 ;
T_4 : 4 ;
T_4 V_134 : 4 ;
T_4 : 16 ;
} V_77 ( ( V_78 ) ) * V_135 ;
int V_14 , V_13 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_135 = V_18 ;
V_135 -> V_20 . V_21 = 0x0050 ;
V_135 -> V_20 . V_22 = 0x0016 ;
V_135 -> V_128 = V_48 >> 4 ;
V_135 -> V_130 = ( T_1 ) ( unsigned long ) V_123 -> V_130 ;
V_135 -> V_132 = ( T_1 ) ( unsigned long ) V_123 -> V_132 ;
V_135 -> V_46 = V_126 ? 0 : 1 ;
V_13 = F_4 ( V_135 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_135 -> V_1 . V_22 ) {
case 0x0102 :
case 0x0103 :
V_14 = - V_2 ;
break;
default:
V_14 = F_1 ( V_135 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_22 ( 2 , L_32 ,
V_135 -> V_1 . V_22 ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int
F_58 ( struct V_122 * V_123 , int V_126 )
{
int V_14 ;
if ( V_126 && ! V_123 -> V_136 ) {
V_123 -> V_130 = ( void * ) F_59 ( V_137 | V_138 ) ;
V_123 -> V_132 = ( void * ) F_59 ( V_137 | V_138 ) ;
if ( ! V_123 -> V_130 || ! V_123 -> V_132 ) {
F_60 ( ( unsigned long ) V_123 -> V_130 ) ;
F_60 ( ( unsigned long ) V_123 -> V_132 ) ;
return - V_5 ;
}
}
V_14 = F_57 ( V_123 , V_126 ) ;
if ( ! V_14 ) {
V_123 -> V_136 = V_126 ;
if ( V_123 -> V_136 ) {
V_14 = F_55 ( V_123 ) ;
if ( V_14 ) {
F_57 ( V_123 , 0 ) ;
V_123 -> V_136 = 0 ;
}
} else
F_53 ( V_123 ) ;
}
if ( ! V_123 -> V_136 ) {
F_60 ( ( unsigned long ) V_123 -> V_130 ) ;
F_60 ( ( unsigned long ) V_123 -> V_132 ) ;
}
return V_14 ;
}
int F_61 ( struct V_64 V_35 , int V_134 , int V_139 ,
int V_140 , int V_141 , void * V_142 )
{
struct V_143 * V_144 ;
int V_13 , V_14 ;
if ( ( V_139 == 1 ) && ! V_52 . V_145 )
return - V_2 ;
if ( ( V_139 == 2 ) && ! V_52 . V_146 )
return - V_2 ;
memset ( V_142 , 0 , V_19 ) ;
V_144 = V_142 ;
V_144 -> V_20 . V_21 = 0x0010 ;
V_144 -> V_20 . V_22 = 0x0002 ;
V_144 -> V_68 = V_35 . V_68 ;
V_144 -> V_147 = V_35 . V_36 ;
V_144 -> V_148 = V_35 . V_36 ;
V_144 -> V_141 = V_141 ;
V_144 -> V_140 = V_140 ;
V_144 -> V_134 = V_134 ;
V_144 -> V_139 = V_139 ;
V_13 = F_4 ( V_144 ) ;
if ( V_13 > 0 )
return ( V_13 == 3 ) ? - V_27 : - V_4 ;
V_14 = F_1 ( V_144 -> V_1 . V_22 ) ;
if ( V_14 )
F_22 ( 2 , L_33 ,
V_144 -> V_1 . V_22 ) ;
return V_14 ;
}
int F_62 ( struct V_64 V_35 ,
struct V_149 * V_150 )
{
struct V_151 * V_152 ;
struct V_143 * V_144 ;
unsigned long V_97 ;
int V_14 ;
F_48 ( & V_17 , V_97 ) ;
V_144 = V_18 ;
V_14 = F_61 ( V_35 , 0 , 0 , 0 , 0 , V_144 ) ;
if ( V_14 )
goto V_28;
V_152 = ( void * ) & V_144 -> V_1 ;
memcpy ( V_150 , & V_152 -> V_57 , sizeof( * V_150 ) ) ;
V_28:
F_49 ( & V_17 , V_97 ) ;
return V_14 ;
}
int F_63 ( struct V_64 V_35 ,
struct V_153 * V_150 )
{
struct V_151 * V_152 ;
struct V_143 * V_144 ;
unsigned long V_97 ;
int V_14 ;
F_48 ( & V_17 , V_97 ) ;
V_144 = V_18 ;
V_14 = F_61 ( V_35 , 0 , 0 , 1 , 0 , V_144 ) ;
if ( V_14 )
goto V_28;
V_152 = ( void * ) & V_144 -> V_1 ;
memcpy ( V_150 , & V_152 -> V_57 , sizeof( * V_150 ) ) ;
V_28:
F_49 ( & V_17 , V_97 ) ;
return V_14 ;
}
static void
F_64 ( struct V_87 * V_88 , T_2 V_154 ,
struct V_155 * V_156 )
{
struct V_155 * V_155 ;
int V_15 , V_16 ;
V_155 = V_88 -> V_155 ;
for ( V_15 = 0 ; V_15 < V_157 ; V_15 ++ ) {
V_16 = 0x80 >> ( V_15 + 3 ) ;
if ( V_154 & V_16 )
V_155 -> V_158 [ V_15 ] = V_156 -> V_158 [ V_15 ] ;
else
V_155 -> V_158 [ V_15 ] = 0 ;
}
}
int F_65 ( struct V_87 * V_88 )
{
struct V_155 * V_155 ;
int V_13 , V_14 ;
struct {
struct V_127 V_20 ;
T_4 : 24 ;
T_4 V_147 : 8 ;
T_4 : 24 ;
T_4 V_148 : 8 ;
T_4 V_129 ;
struct V_127 V_1 ;
T_4 V_131 ;
T_4 V_159 : 1 ;
T_4 V_160 : 1 ;
T_4 : 22 ;
T_4 V_35 : 8 ;
T_4 V_154 : 5 ;
T_4 : 11 ;
T_4 V_161 : 8 ;
T_4 V_162 : 8 ;
T_4 V_163 ;
T_4 V_57 [ V_157 ] ;
} V_77 ( ( V_78 ) ) * V_164 ;
V_88 -> V_155 = NULL ;
V_155 = F_66 ( sizeof( * V_155 ) , V_137 ) ;
if ( ! V_155 )
return - V_5 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_164 = V_18 ;
V_164 -> V_20 . V_21 = 0x0010 ;
V_164 -> V_20 . V_22 = 0x0022 ;
V_164 -> V_147 = V_88 -> V_35 . V_36 ;
V_164 -> V_148 = V_88 -> V_35 . V_36 ;
V_13 = F_4 ( V_164 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_164 -> V_1 . V_22 ) ;
if ( V_14 ) {
F_22 ( 2 , L_34 ,
V_164 -> V_1 . V_22 ) ;
goto V_28;
}
if ( V_164 -> V_159 ) {
V_88 -> V_162 = - 1 ;
V_88 -> V_160 = - 1 ;
goto V_28;
}
V_88 -> V_162 = V_164 -> V_162 ;
V_88 -> V_160 = V_164 -> V_160 ;
if ( V_88 -> V_162 != 2 && V_88 -> V_162 != 3 ) {
goto V_28;
}
V_88 -> V_155 = V_155 ;
F_64 ( V_88 , V_164 -> V_154 ,
(struct V_155 * ) & V_164 -> V_57 ) ;
V_28:
F_7 ( & V_17 ) ;
if ( ! V_88 -> V_155 )
F_67 ( V_155 ) ;
return V_14 ;
}
int T_5 F_68 ( void )
{
int V_14 ;
V_110 = ( void * ) F_59 ( V_137 | V_138 ) ;
V_18 = ( void * ) F_59 ( V_137 | V_138 ) ;
if ( ! V_110 || ! V_18 ) {
V_14 = - V_5 ;
goto V_165;
}
V_14 = F_69 ( V_166 , F_45 ) ;
if ( V_14 )
goto V_165;
return V_14 ;
V_165:
F_60 ( ( unsigned long ) V_18 ) ;
F_60 ( ( unsigned long ) V_110 ) ;
return V_14 ;
}
void T_5 F_70 ( void )
{
F_71 ( V_166 ) ;
F_60 ( ( unsigned long ) V_18 ) ;
F_60 ( ( unsigned long ) V_110 ) ;
}
int F_72 ( int V_46 )
{
unsigned long V_97 ;
int V_14 ;
struct {
struct V_127 V_20 ;
T_2 V_167 : 4 ;
T_2 V_168 : 4 ;
T_2 V_169 ;
T_3 V_46 ;
T_4 V_170 ;
T_4 V_171 ;
T_4 V_172 [ 252 ] ;
struct V_127 V_1 ;
T_4 V_173 : 4 ;
T_4 V_174 : 4 ;
T_4 V_175 : 24 ;
} V_77 ( ( V_78 ) ) * V_176 ;
F_48 ( & V_17 , V_97 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_176 = V_18 ;
V_176 -> V_20 . V_21 = 0x0400 ;
V_176 -> V_20 . V_22 = 0x0031 ;
V_176 -> V_46 = V_46 ;
V_14 = F_4 ( V_176 ) ;
if ( V_14 > 0 ) {
V_14 = ( V_14 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_176 -> V_1 . V_22 ) {
case 0x0101 :
V_14 = - V_3 ;
break;
default:
V_14 = F_1 ( V_176 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_22 ( 2 , L_35 ,
V_46 , V_176 -> V_1 . V_22 ) ;
V_28:
F_49 ( & V_17 , V_97 ) ;
return V_14 ;
}
int T_5
F_73 ( void )
{
int V_177 ;
struct {
struct V_127 V_20 ;
T_4 V_167 ;
T_4 V_169 ;
T_4 V_170 ;
struct V_127 V_1 ;
T_4 V_171 ;
T_4 V_178 [ 510 ] ;
T_4 V_179 [ 508 ] ;
} V_77 ( ( V_78 ) ) * V_180 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_180 = V_18 ;
V_180 -> V_20 . V_21 = 0x0010 ;
V_180 -> V_20 . V_22 = 0x0010 ;
V_177 = F_4 ( V_180 ) ;
if ( V_177 ) {
V_177 = ( V_177 == 3 ) ? - V_27 : - V_4 ;
goto exit;
}
V_177 = F_1 ( V_180 -> V_1 . V_22 ) ;
if ( V_177 == 0 ) {
memcpy ( & V_52 , V_180 -> V_178 ,
sizeof( V_52 ) ) ;
memcpy ( & V_181 , V_180 -> V_179 ,
sizeof( V_181 ) ) ;
} else
F_22 ( 2 , L_36 ,
V_180 -> V_1 . V_22 ) ;
exit:
F_7 ( & V_17 ) ;
return V_177 ;
}
int F_74 ( void * V_142 , unsigned int V_94 , T_3 V_182 )
{
struct {
struct V_127 V_20 ;
unsigned int V_183 ;
unsigned int V_94 : 8 ;
unsigned int V_184 : 8 ;
unsigned int V_182 : 16 ;
unsigned int V_185 [ 5 ] ;
struct V_127 V_1 ;
unsigned int V_186 [ 7 ] ;
} V_77 ( ( V_78 ) ) * V_187 ;
int V_188 ;
memset ( V_142 , 0 , V_19 ) ;
V_187 = V_142 ;
V_187 -> V_20 . V_21 = 0x0020 ;
V_187 -> V_20 . V_22 = 0x0033 ;
V_187 -> V_94 = V_94 ;
V_187 -> V_182 = V_182 ;
V_188 = F_4 ( V_187 ) ;
if ( V_188 )
return - V_6 ;
V_188 = ( V_187 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
return V_188 ;
}
int F_75 ( void * V_142 , void * V_177 , T_6 V_189 )
{
struct {
struct V_127 V_20 ;
unsigned int V_183 [ 3 ] ;
struct V_127 V_1 ;
char V_57 [ V_189 ] ;
} V_77 ( ( V_78 ) ) * V_187 ;
int V_188 ;
memset ( V_142 , 0 , V_19 ) ;
V_187 = V_142 ;
V_187 -> V_20 . V_21 = 0x0010 ;
V_187 -> V_20 . V_22 = 0x0038 ;
V_188 = F_4 ( V_187 ) ;
if ( V_188 )
return - V_6 ;
memcpy ( V_177 , & V_187 -> V_57 , V_189 ) ;
return ( V_187 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
}
int F_76 ( struct V_7 V_8 )
{
struct {
struct V_127 V_20 ;
T_4 V_190 ;
struct V_7 V_191 ;
T_4 V_192 ;
struct V_127 V_1 ;
T_4 V_193 [ 11 ] ;
} V_77 ( ( V_78 ) ) * V_194 ;
unsigned long V_97 ;
int V_13 ;
int V_188 ;
F_48 ( & V_17 , V_97 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_194 = V_18 ;
V_194 -> V_20 . V_21 = 0x0010 ;
V_194 -> V_20 . V_22 = 0x0046 ;
V_194 -> V_190 = 0x80000000 ;
V_194 -> V_191 = V_8 ;
V_13 = F_4 ( V_194 ) ;
if ( V_13 > 0 ) {
if ( V_13 == 3 )
V_188 = - V_27 ;
else
V_188 = - V_4 ;
F_5 ( 2 , L_37 ,
V_8 . V_23 , V_8 . V_25 , V_13 ) ;
goto V_28;
}
V_188 = F_1 ( V_194 -> V_1 . V_22 ) ;
if ( V_188 )
F_5 ( 2 , L_38 ,
V_8 . V_23 , V_8 . V_25 ,
V_194 -> V_1 . V_22 ) ;
else
F_5 ( 4 , L_39 ,
V_8 . V_23 , V_8 . V_25 ) ;
V_28:
F_49 ( & V_17 , V_97 ) ;
return V_188 ;
}
int F_77 ( struct F_77 * V_195 , T_1 V_196 )
{
int V_13 , V_14 ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
V_195 -> V_20 . V_21 = 0x0020 ;
V_195 -> V_20 . V_22 = 0x004C ;
V_195 -> V_197 = V_196 ;
V_13 = F_4 ( V_195 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_195 -> V_1 . V_22 ) ;
if ( V_14 != 0 )
F_5 ( 2 , L_40 ,
V_195 -> V_1 . V_22 ) ;
V_28:
return V_14 ;
}
int F_78 ( struct V_7 V_8 ,
struct V_198 * V_199 ,
struct V_200 V_201 ,
int V_202 )
{
memset ( V_199 , 0 , sizeof( * V_199 ) ) ;
V_199 -> V_20 . V_21 = 0x0030 ;
V_199 -> V_20 . V_22 = 0x003d ;
V_199 -> V_141 = V_8 . V_141 ;
V_199 -> V_23 = V_8 . V_23 ;
V_199 -> V_56 = V_8 . V_25 ;
V_199 -> V_68 = V_8 . V_68 ;
V_199 -> V_203 = 0 ;
V_199 -> V_201 = V_201 ;
V_199 -> V_204 = ( V_202 != 0 ) ;
if ( F_4 ( V_199 ) )
return - V_6 ;
return F_1 ( V_199 -> V_1 . V_22 ) ;
}
