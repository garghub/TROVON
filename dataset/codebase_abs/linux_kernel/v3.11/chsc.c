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
static int F_17 ( struct V_7 V_8 , void * V_57 )
{
struct V_69 V_69 ;
if ( F_18 ( V_8 , & V_69 ) )
return - V_70 ;
F_11 ( V_8 ) ;
return 0 ;
}
static int F_19 ( struct V_55 * V_56 , void * V_57 )
{
F_3 ( V_56 -> V_58 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
V_56 -> V_59 -> V_60 ( V_56 , V_57 , V_71 ) ;
F_7 ( V_56 -> V_58 ) ;
return 0 ;
}
static void F_20 ( struct V_66 * V_67 )
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
F_16 ( F_19 ,
F_17 , V_67 ) ;
}
static int
F_21 ( void * V_57 )
{
struct V_72 {
T_2 V_73 ;
T_2 V_74 ;
T_3 V_75 ;
T_4 V_76 [ 28 ] ;
T_4 V_77 [ 28 ] ;
T_4 V_78 [ 28 ] ;
} V_79 ( ( V_80 ) ) * V_72 ;
V_72 = V_57 ;
if ( ! ( V_72 -> V_73 & 0x80 ) )
return - V_2 ;
if ( ! ( V_72 -> V_76 [ 0 ] & 0xc0000000 ) )
return - V_2 ;
if ( ! ( V_72 -> V_76 [ 0 ] & 0x10000000 ) )
return - V_2 ;
return ( T_3 ) ( V_72 -> V_76 [ 0 ] & 0x000000ff ) ;
}
static void F_22 ( struct V_81 * V_82 )
{
struct V_64 V_35 ;
int V_36 ;
F_23 ( 4 , L_5 ,
V_82 -> V_83 , V_82 -> V_84 ) ;
if ( V_82 -> V_83 != 4 )
return;
V_36 = F_21 ( V_82 -> V_85 ) ;
if ( V_36 < 0 )
F_23 ( 4 , L_6 ) ;
else {
F_6 ( & V_35 ) ;
V_35 . V_36 = V_36 ;
F_12 ( V_35 ) ;
}
}
static void F_24 ( struct V_81 * V_82 )
{
struct V_66 V_67 ;
struct V_64 V_35 ;
int V_86 ;
F_23 ( 4 , L_7
L_8 , V_82 -> V_83 , V_82 -> V_84 ) ;
if ( V_82 -> V_83 != 4 )
return;
F_6 ( & V_35 ) ;
V_35 . V_36 = V_82 -> V_84 ;
V_86 = F_14 ( V_35 ) ;
if ( V_86 < 0 )
F_25 ( V_35 ) ;
else if ( ! V_86 )
return;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
if ( ( V_82 -> V_87 & 0xc0 ) != 0 ) {
V_67 . V_37 = V_82 -> V_37 ;
if ( ( V_82 -> V_87 & 0xc0 ) == 0xc0 )
V_67 . V_88 = 0xffff ;
else
V_67 . V_88 = 0xff00 ;
}
F_20 ( & V_67 ) ;
}
static void F_26 ( struct V_81 * V_82 )
{
struct V_89 * V_90 ;
struct V_64 V_35 ;
T_2 * V_57 ;
int V_91 ;
F_23 ( 4 , L_9 ) ;
if ( V_82 -> V_83 != 0 )
return;
V_57 = V_82 -> V_85 ;
F_6 ( & V_35 ) ;
for ( V_91 = 0 ; V_91 <= V_92 ; V_91 ++ ) {
if ( ! F_27 ( V_57 , V_91 ) )
continue;
V_35 . V_36 = V_91 ;
F_23 ( 4 , L_10
L_11 , V_35 . V_68 , V_35 . V_36 ) ;
V_90 = F_28 ( V_35 ) ;
if ( ! V_90 ) {
F_25 ( V_35 ) ;
continue;
}
F_29 ( & V_90 -> V_58 ) ;
F_30 ( V_90 ) ;
F_31 ( & V_90 -> V_58 ) ;
}
}
static void F_32 ( struct V_81 * V_82 )
{
struct V_93 * V_57 ;
struct V_64 V_35 ;
int V_91 ;
char * V_94 [ 3 ] = { L_12 , L_13 , L_14 } ;
F_23 ( 4 , L_15 ) ;
if ( V_82 -> V_83 != 0 )
return;
V_57 = (struct V_93 * ) & ( V_82 -> V_85 ) ;
F_6 ( & V_35 ) ;
for ( V_91 = 0 ; V_91 <= V_92 ; V_91 ++ ) {
if ( ! F_27 ( V_57 -> V_95 , V_91 ) )
continue;
V_35 . V_36 = V_91 ;
F_33 ( L_16 ,
V_94 [ V_57 -> V_96 ] , V_35 . V_68 , V_35 . V_36 ) ;
switch ( V_57 -> V_96 ) {
case 0 :
F_34 ( V_35 , 1 ) ;
break;
case 1 :
F_34 ( V_35 , 0 ) ;
break;
case 2 :
F_35 ( V_35 ) ;
break;
}
}
}
static void F_36 ( struct V_81 * V_82 )
{
int V_14 ;
F_23 ( 4 , L_17 ) ;
if ( V_82 -> V_83 != 7 )
return;
V_14 = F_37 () ;
if ( V_14 )
F_23 ( 0 , L_18
L_19 , V_14 ) ;
}
static void F_38 ( struct V_81 * V_82 )
{
int V_14 ;
F_23 ( 4 , L_20 ) ;
if ( V_82 -> V_83 != 7 )
return;
V_14 = F_39 () ;
if ( V_14 )
F_23 ( 0 , L_21
L_19 , V_14 ) ;
}
static void F_40 ( struct V_97 * V_82 )
{
switch ( V_82 -> V_98 ) {
case 1 :
F_41 ( V_82 -> V_85 ) ;
break;
case 2 :
F_42 ( V_82 -> V_85 ) ;
break;
default:
F_23 ( 2 , L_22 ,
V_82 -> V_98 ) ;
break;
}
}
static void F_43 ( struct V_81 * V_82 )
{
switch ( V_82 -> V_98 ) {
case 1 :
F_22 ( V_82 ) ;
break;
case 2 :
F_24 ( V_82 ) ;
break;
case 7 :
F_26 ( V_82 ) ;
break;
case 8 :
F_32 ( V_82 ) ;
break;
case 12 :
F_36 ( V_82 ) ;
break;
case 14 :
F_38 ( V_82 ) ;
break;
default:
F_23 ( 2 , L_23 ,
V_82 -> V_98 ) ;
break;
}
if ( V_82 -> V_99 & 0x40 ) {
F_23 ( 2 , L_24 ) ;
F_44 () ;
}
}
static void F_45 ( struct V_100 * V_101 , T_1 V_102 )
{
do {
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_20 . V_21 = 0x0010 ;
V_101 -> V_20 . V_22 = 0x000e ;
V_101 -> V_102 = V_102 ;
if ( F_4 ( V_101 ) )
break;
if ( V_101 -> V_1 . V_22 != 0x0001 ) {
F_23 ( 2 , L_25 ,
V_101 -> V_1 . V_22 ) ;
break;
}
F_23 ( 2 , L_26 , V_101 -> V_103 ) ;
switch ( V_101 -> V_103 ) {
case 0 :
F_43 ( & V_101 -> V_104 . V_105 ) ;
break;
case 2 :
F_40 ( & V_101 -> V_104 . V_106 ) ;
break;
default:
F_23 ( 2 , L_27 , V_101 -> V_103 ) ;
break;
}
} while ( V_101 -> V_104 . V_105 . V_99 & 0x80 );
}
static void F_46 ( struct V_107 * V_108 , struct V_107 * V_109 , int V_110 )
{
struct V_100 * V_101 = V_111 ;
if ( V_110 ) {
F_44 () ;
return;
}
F_23 ( 2 , L_28
L_29 ,
V_108 -> V_112 , V_108 -> V_113 , V_108 -> V_114 , V_108 -> V_115 , V_108 -> V_116 ,
V_108 -> V_117 , V_108 -> V_84 ) ;
F_13 ( 2 , L_30 ) ;
F_45 ( V_101 , V_118 | V_119 ) ;
}
void F_47 ( struct V_64 V_35 )
{
char V_65 [ 15 ] ;
struct V_66 V_67 ;
sprintf ( V_65 , L_31 , V_35 . V_68 , V_35 . V_36 ) ;
F_13 ( 2 , V_65 ) ;
if ( F_14 ( V_35 ) != 0 ) {
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
F_15 () ;
F_16 ( F_19 , NULL ,
& V_67 ) ;
}
}
static void F_48 ( struct V_55 * V_56 ,
struct V_64 V_35 , int V_120 )
{
unsigned long V_99 ;
struct V_66 V_67 ;
memset ( & V_67 , 0 , sizeof( struct V_66 ) ) ;
V_67 . V_35 = V_35 ;
F_49 ( V_56 -> V_58 , V_99 ) ;
if ( V_56 -> V_59 && V_56 -> V_59 -> V_60 )
V_56 -> V_59 -> V_60 ( V_56 , & V_67 ,
V_120 ? V_121 : V_122 ) ;
F_50 ( V_56 -> V_58 , V_99 ) ;
}
static int F_51 ( struct V_55 * V_56 , void * V_57 )
{
struct V_64 * V_35 = V_57 ;
F_48 ( V_56 , * V_35 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_55 * V_56 , void * V_57 )
{
struct V_64 * V_35 = V_57 ;
F_48 ( V_56 , * V_35 , 1 ) ;
return 0 ;
}
static int
F_53 ( struct V_7 V_8 , void * V_57 )
{
struct V_69 V_69 ;
if ( F_18 ( V_8 , & V_69 ) )
return - V_70 ;
F_11 ( V_8 ) ;
return 0 ;
}
int F_54 ( struct V_64 V_35 , int V_120 )
{
struct V_89 * V_90 = F_28 ( V_35 ) ;
F_15 () ;
if ( V_120 ) {
F_30 ( V_90 ) ;
F_16 ( F_52 ,
F_53 , & V_35 ) ;
} else
F_16 ( F_51 ,
NULL , & V_35 ) ;
return 0 ;
}
static void
F_55 ( struct V_123 * V_124 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 <= V_92 ; V_15 ++ ) {
if ( ! V_124 -> V_125 [ V_15 ] )
continue;
F_56 ( V_124 -> V_125 [ V_15 ] ) ;
}
}
static int
F_57 ( struct V_123 * V_124 )
{
int V_15 , V_14 ;
V_14 = 0 ;
for ( V_15 = 0 ; V_15 <= V_92 ; V_15 ++ ) {
if ( ! V_124 -> V_125 [ V_15 ] )
continue;
V_14 = F_58 ( V_124 -> V_125 [ V_15 ] ) ;
if ( V_14 )
goto V_126;
}
return V_14 ;
V_126:
for ( -- V_15 ; V_15 >= 0 ; V_15 -- ) {
if ( ! V_124 -> V_125 [ V_15 ] )
continue;
F_56 ( V_124 -> V_125 [ V_15 ] ) ;
}
return V_14 ;
}
int F_59 ( struct V_123 * V_124 , int V_127 )
{
struct {
struct V_128 V_20 ;
T_4 V_46 : 2 ;
T_4 : 30 ;
T_4 V_129 : 4 ;
T_4 : 28 ;
T_4 V_130 ;
T_4 V_131 ;
T_4 V_132 ;
T_4 V_133 ;
T_4 V_134 [ 13 ] ;
struct V_128 V_1 ;
T_4 V_86 : 8 ;
T_4 : 4 ;
T_4 V_135 : 4 ;
T_4 : 16 ;
} V_79 ( ( V_80 ) ) * V_136 ;
int V_14 , V_13 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_136 = V_18 ;
V_136 -> V_20 . V_21 = 0x0050 ;
V_136 -> V_20 . V_22 = 0x0016 ;
V_136 -> V_129 = V_48 >> 4 ;
V_136 -> V_131 = ( T_1 ) ( unsigned long ) V_124 -> V_131 ;
V_136 -> V_133 = ( T_1 ) ( unsigned long ) V_124 -> V_133 ;
V_136 -> V_46 = V_127 ? 0 : 1 ;
V_13 = F_4 ( V_136 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_136 -> V_1 . V_22 ) {
case 0x0102 :
case 0x0103 :
V_14 = - V_2 ;
break;
default:
V_14 = F_1 ( V_136 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_23 ( 2 , L_32 ,
V_136 -> V_1 . V_22 ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int
F_60 ( struct V_123 * V_124 , int V_127 )
{
int V_14 ;
if ( V_127 && ! V_124 -> V_137 ) {
V_124 -> V_131 = ( void * ) F_61 ( V_138 | V_139 ) ;
V_124 -> V_133 = ( void * ) F_61 ( V_138 | V_139 ) ;
if ( ! V_124 -> V_131 || ! V_124 -> V_133 ) {
F_62 ( ( unsigned long ) V_124 -> V_131 ) ;
F_62 ( ( unsigned long ) V_124 -> V_133 ) ;
return - V_5 ;
}
}
V_14 = F_59 ( V_124 , V_127 ) ;
if ( ! V_14 ) {
V_124 -> V_137 = V_127 ;
if ( V_124 -> V_137 ) {
V_14 = F_57 ( V_124 ) ;
if ( V_14 ) {
F_59 ( V_124 , 0 ) ;
V_124 -> V_137 = 0 ;
}
} else
F_55 ( V_124 ) ;
}
if ( ! V_124 -> V_137 ) {
F_62 ( ( unsigned long ) V_124 -> V_131 ) ;
F_62 ( ( unsigned long ) V_124 -> V_133 ) ;
}
return V_14 ;
}
int F_63 ( struct V_64 V_35 , int V_135 , int V_140 ,
int V_141 , int V_142 , void * V_143 )
{
struct V_144 * V_145 ;
int V_13 , V_14 ;
if ( ( V_140 == 1 ) && ! V_52 . V_146 )
return - V_2 ;
if ( ( V_140 == 2 ) && ! V_52 . V_147 )
return - V_2 ;
memset ( V_143 , 0 , V_19 ) ;
V_145 = V_143 ;
V_145 -> V_20 . V_21 = 0x0010 ;
V_145 -> V_20 . V_22 = 0x0002 ;
V_145 -> V_68 = V_35 . V_68 ;
V_145 -> V_148 = V_35 . V_36 ;
V_145 -> V_149 = V_35 . V_36 ;
V_145 -> V_142 = V_142 ;
V_145 -> V_141 = V_141 ;
V_145 -> V_135 = V_135 ;
V_145 -> V_140 = V_140 ;
V_13 = F_4 ( V_145 ) ;
if ( V_13 > 0 )
return ( V_13 == 3 ) ? - V_27 : - V_4 ;
V_14 = F_1 ( V_145 -> V_1 . V_22 ) ;
if ( V_14 )
F_23 ( 2 , L_33 ,
V_145 -> V_1 . V_22 ) ;
return V_14 ;
}
int F_64 ( struct V_64 V_35 ,
struct V_150 * V_151 )
{
struct V_152 * V_153 ;
struct V_144 * V_145 ;
unsigned long V_99 ;
int V_14 ;
F_49 ( & V_17 , V_99 ) ;
V_145 = V_18 ;
V_14 = F_63 ( V_35 , 0 , 0 , 0 , 0 , V_145 ) ;
if ( V_14 )
goto V_28;
V_153 = ( void * ) & V_145 -> V_1 ;
memcpy ( V_151 , & V_153 -> V_57 , sizeof( * V_151 ) ) ;
V_28:
F_50 ( & V_17 , V_99 ) ;
return V_14 ;
}
int F_65 ( struct V_64 V_35 ,
struct V_154 * V_151 )
{
struct V_152 * V_153 ;
struct V_144 * V_145 ;
unsigned long V_99 ;
int V_14 ;
F_49 ( & V_17 , V_99 ) ;
V_145 = V_18 ;
V_14 = F_63 ( V_35 , 0 , 0 , 1 , 0 , V_145 ) ;
if ( V_14 )
goto V_28;
V_153 = ( void * ) & V_145 -> V_1 ;
memcpy ( V_151 , & V_153 -> V_57 , sizeof( * V_151 ) ) ;
V_28:
F_50 ( & V_17 , V_99 ) ;
return V_14 ;
}
static void
F_66 ( struct V_89 * V_90 , T_2 V_155 ,
struct V_156 * V_157 )
{
struct V_156 * V_156 ;
int V_15 , V_16 ;
V_156 = V_90 -> V_156 ;
for ( V_15 = 0 ; V_15 < V_158 ; V_15 ++ ) {
V_16 = 0x80 >> ( V_15 + 3 ) ;
if ( V_155 & V_16 )
V_156 -> V_159 [ V_15 ] = V_157 -> V_159 [ V_15 ] ;
else
V_156 -> V_159 [ V_15 ] = 0 ;
}
}
int F_67 ( struct V_89 * V_90 )
{
struct V_156 * V_156 ;
int V_13 , V_14 ;
struct {
struct V_128 V_20 ;
T_4 : 24 ;
T_4 V_148 : 8 ;
T_4 : 24 ;
T_4 V_149 : 8 ;
T_4 V_130 ;
struct V_128 V_1 ;
T_4 V_132 ;
T_4 V_160 : 1 ;
T_4 V_161 : 1 ;
T_4 : 22 ;
T_4 V_35 : 8 ;
T_4 V_155 : 5 ;
T_4 : 11 ;
T_4 V_162 : 8 ;
T_4 V_163 : 8 ;
T_4 V_164 ;
T_4 V_57 [ V_158 ] ;
} V_79 ( ( V_80 ) ) * V_165 ;
V_90 -> V_156 = NULL ;
V_156 = F_68 ( sizeof( * V_156 ) , V_138 ) ;
if ( ! V_156 )
return - V_5 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_165 = V_18 ;
V_165 -> V_20 . V_21 = 0x0010 ;
V_165 -> V_20 . V_22 = 0x0022 ;
V_165 -> V_148 = V_90 -> V_35 . V_36 ;
V_165 -> V_149 = V_90 -> V_35 . V_36 ;
V_13 = F_4 ( V_165 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_165 -> V_1 . V_22 ) ;
if ( V_14 ) {
F_23 ( 2 , L_34 ,
V_165 -> V_1 . V_22 ) ;
goto V_28;
}
if ( V_165 -> V_160 ) {
V_90 -> V_163 = - 1 ;
V_90 -> V_161 = - 1 ;
goto V_28;
}
V_90 -> V_163 = V_165 -> V_163 ;
V_90 -> V_161 = V_165 -> V_161 ;
if ( V_90 -> V_163 != 2 && V_90 -> V_163 != 3 ) {
goto V_28;
}
V_90 -> V_156 = V_156 ;
F_66 ( V_90 , V_165 -> V_155 ,
(struct V_156 * ) & V_165 -> V_57 ) ;
V_28:
F_7 ( & V_17 ) ;
if ( ! V_90 -> V_156 )
F_69 ( V_156 ) ;
return V_14 ;
}
int T_5 F_70 ( void )
{
int V_14 ;
V_111 = ( void * ) F_61 ( V_138 | V_139 ) ;
V_18 = ( void * ) F_61 ( V_138 | V_139 ) ;
if ( ! V_111 || ! V_18 ) {
V_14 = - V_5 ;
goto V_166;
}
V_14 = F_71 ( V_167 , F_46 ) ;
if ( V_14 )
goto V_166;
return V_14 ;
V_166:
F_62 ( ( unsigned long ) V_18 ) ;
F_62 ( ( unsigned long ) V_111 ) ;
return V_14 ;
}
void T_5 F_72 ( void )
{
F_73 ( V_167 ) ;
F_62 ( ( unsigned long ) V_18 ) ;
F_62 ( ( unsigned long ) V_111 ) ;
}
int F_74 ( int V_46 )
{
unsigned long V_99 ;
int V_14 ;
struct {
struct V_128 V_20 ;
T_2 V_168 : 4 ;
T_2 V_169 : 4 ;
T_2 V_170 ;
T_3 V_46 ;
T_4 V_171 ;
T_4 V_172 ;
T_4 V_173 [ 252 ] ;
struct V_128 V_1 ;
T_4 V_174 : 4 ;
T_4 V_175 : 4 ;
T_4 V_176 : 24 ;
} V_79 ( ( V_80 ) ) * V_177 ;
F_49 ( & V_17 , V_99 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_177 = V_18 ;
V_177 -> V_20 . V_21 = 0x0400 ;
V_177 -> V_20 . V_22 = 0x0031 ;
V_177 -> V_46 = V_46 ;
V_14 = F_4 ( V_177 ) ;
if ( V_14 > 0 ) {
V_14 = ( V_14 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_177 -> V_1 . V_22 ) {
case 0x0101 :
V_14 = - V_3 ;
break;
default:
V_14 = F_1 ( V_177 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_23 ( 2 , L_35 ,
V_46 , V_177 -> V_1 . V_22 ) ;
V_28:
F_50 ( & V_17 , V_99 ) ;
return V_14 ;
}
int T_5
F_75 ( void )
{
int V_178 ;
struct {
struct V_128 V_20 ;
T_4 V_168 ;
T_4 V_170 ;
T_4 V_171 ;
struct V_128 V_1 ;
T_4 V_172 ;
T_4 V_179 [ 510 ] ;
T_4 V_180 [ 508 ] ;
} V_79 ( ( V_80 ) ) * V_181 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_181 = V_18 ;
V_181 -> V_20 . V_21 = 0x0010 ;
V_181 -> V_20 . V_22 = 0x0010 ;
V_178 = F_4 ( V_181 ) ;
if ( V_178 ) {
V_178 = ( V_178 == 3 ) ? - V_27 : - V_4 ;
goto exit;
}
V_178 = F_1 ( V_181 -> V_1 . V_22 ) ;
if ( V_178 == 0 ) {
memcpy ( & V_52 , V_181 -> V_179 ,
sizeof( V_52 ) ) ;
memcpy ( & V_182 , V_181 -> V_180 ,
sizeof( V_182 ) ) ;
} else
F_23 ( 2 , L_36 ,
V_181 -> V_1 . V_22 ) ;
exit:
F_7 ( & V_17 ) ;
return V_178 ;
}
int F_76 ( void * V_143 , unsigned int V_96 , T_3 V_183 )
{
struct {
struct V_128 V_20 ;
unsigned int V_184 ;
unsigned int V_96 : 8 ;
unsigned int V_185 : 8 ;
unsigned int V_183 : 16 ;
unsigned int V_186 [ 5 ] ;
struct V_128 V_1 ;
unsigned int V_187 [ 7 ] ;
} V_79 ( ( V_80 ) ) * V_188 ;
int V_189 ;
memset ( V_143 , 0 , V_19 ) ;
V_188 = V_143 ;
V_188 -> V_20 . V_21 = 0x0020 ;
V_188 -> V_20 . V_22 = 0x0033 ;
V_188 -> V_96 = V_96 ;
V_188 -> V_183 = V_183 ;
V_189 = F_4 ( V_188 ) ;
if ( V_189 )
return - V_6 ;
V_189 = ( V_188 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
return V_189 ;
}
int F_77 ( void * V_143 , void * V_178 , T_6 V_190 )
{
struct {
struct V_128 V_20 ;
unsigned int V_184 [ 3 ] ;
struct V_128 V_1 ;
char V_57 [ V_190 ] ;
} V_79 ( ( V_80 ) ) * V_188 ;
int V_189 ;
memset ( V_143 , 0 , V_19 ) ;
V_188 = V_143 ;
V_188 -> V_20 . V_21 = 0x0010 ;
V_188 -> V_20 . V_22 = 0x0038 ;
V_189 = F_4 ( V_188 ) ;
if ( V_189 )
return - V_6 ;
memcpy ( V_178 , & V_188 -> V_57 , V_190 ) ;
return ( V_188 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
}
int F_78 ( struct V_7 V_8 )
{
struct {
struct V_128 V_20 ;
T_4 V_191 ;
struct V_7 V_192 ;
T_4 V_193 ;
struct V_128 V_1 ;
T_4 V_194 [ 11 ] ;
} V_79 ( ( V_80 ) ) * V_195 ;
unsigned long V_99 ;
int V_13 ;
int V_189 ;
F_49 ( & V_17 , V_99 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_195 = V_18 ;
V_195 -> V_20 . V_21 = 0x0010 ;
V_195 -> V_20 . V_22 = 0x0046 ;
V_195 -> V_191 = 0x80000000 ;
V_195 -> V_192 = V_8 ;
V_13 = F_4 ( V_195 ) ;
if ( V_13 > 0 ) {
if ( V_13 == 3 )
V_189 = - V_27 ;
else
V_189 = - V_4 ;
F_5 ( 2 , L_37 ,
V_8 . V_23 , V_8 . V_25 , V_13 ) ;
goto V_28;
}
V_189 = F_1 ( V_195 -> V_1 . V_22 ) ;
if ( V_189 )
F_5 ( 2 , L_38 ,
V_8 . V_23 , V_8 . V_25 ,
V_195 -> V_1 . V_22 ) ;
else
F_5 ( 4 , L_39 ,
V_8 . V_23 , V_8 . V_25 ) ;
V_28:
F_50 ( & V_17 , V_99 ) ;
return V_189 ;
}
int F_79 ( struct F_79 * V_196 , T_1 V_197 )
{
int V_13 , V_14 ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
V_196 -> V_20 . V_21 = 0x0020 ;
V_196 -> V_20 . V_22 = 0x004C ;
V_196 -> V_198 = V_197 ;
V_13 = F_4 ( V_196 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_196 -> V_1 . V_22 ) ;
if ( V_14 != 0 )
F_5 ( 2 , L_40 ,
V_196 -> V_1 . V_22 ) ;
V_28:
return V_14 ;
}
