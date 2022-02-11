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
static int F_8 ( struct V_38 * V_39 , void * V_40 )
{
F_3 ( V_39 -> V_41 ) ;
if ( V_39 -> V_42 && V_39 -> V_42 -> V_43 )
if ( V_39 -> V_42 -> V_43 ( V_39 , V_40 , V_44 ) != 0 )
goto V_45;
F_7 ( V_39 -> V_41 ) ;
return 0 ;
V_45:
V_39 -> V_46 = 0 ;
F_7 ( V_39 -> V_41 ) ;
F_9 ( V_39 -> V_8 ) ;
return 0 ;
}
void F_10 ( struct V_47 V_35 )
{
char V_48 [ 15 ] ;
struct V_49 V_50 ;
sprintf ( V_48 , L_2 , V_35 . V_51 , V_35 . V_36 ) ;
F_11 ( 2 , V_48 ) ;
if ( F_12 ( V_35 ) <= 0 )
return;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_35 = V_35 ;
F_13 () ;
F_14 ( F_8 , NULL , & V_50 ) ;
}
static int F_15 ( struct V_7 V_8 , void * V_40 )
{
struct V_52 V_52 ;
if ( F_16 ( V_8 , & V_52 ) )
return - V_53 ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_17 ( struct V_38 * V_39 , void * V_40 )
{
F_3 ( V_39 -> V_41 ) ;
if ( V_39 -> V_42 && V_39 -> V_42 -> V_43 )
V_39 -> V_42 -> V_43 ( V_39 , V_40 , V_54 ) ;
F_7 ( V_39 -> V_41 ) ;
return 0 ;
}
static void F_18 ( struct V_49 * V_50 )
{
char V_48 [ 15 ] ;
sprintf ( V_48 , L_3 , V_50 -> V_35 . V_51 ,
V_50 -> V_35 . V_36 ) ;
F_11 ( 2 , V_48 ) ;
if ( V_50 -> V_37 != 0 ) {
sprintf ( V_48 , L_4 , V_50 -> V_37 ) ;
F_11 ( 2 , V_48 ) ;
}
F_13 () ;
F_14 ( F_17 ,
F_15 , V_50 ) ;
}
static int
F_19 ( void * V_40 )
{
struct V_55 {
T_1 V_56 ;
T_1 V_57 ;
T_2 V_58 ;
T_3 V_59 [ 28 ] ;
T_3 V_60 [ 28 ] ;
T_3 V_61 [ 28 ] ;
} V_62 ( ( V_63 ) ) * V_55 ;
V_55 = V_40 ;
if ( ! ( V_55 -> V_56 & 0x80 ) )
return - V_2 ;
if ( ! ( V_55 -> V_59 [ 0 ] & 0xc0000000 ) )
return - V_2 ;
if ( ! ( V_55 -> V_59 [ 0 ] & 0x10000000 ) )
return - V_2 ;
return ( T_2 ) ( V_55 -> V_59 [ 0 ] & 0x000000ff ) ;
}
static void F_20 ( struct V_64 * V_65 )
{
struct V_47 V_35 ;
int V_36 ;
F_21 ( 4 , L_5 ,
V_65 -> V_66 , V_65 -> V_67 ) ;
if ( V_65 -> V_66 != 4 )
return;
V_36 = F_19 ( V_65 -> V_68 ) ;
if ( V_36 < 0 )
F_21 ( 4 , L_6 ) ;
else {
F_6 ( & V_35 ) ;
V_35 . V_36 = V_36 ;
F_10 ( V_35 ) ;
}
}
static void F_22 ( struct V_64 * V_65 )
{
struct V_49 V_50 ;
struct V_47 V_35 ;
int V_69 ;
F_21 ( 4 , L_7
L_8 , V_65 -> V_66 , V_65 -> V_67 ) ;
if ( V_65 -> V_66 != 4 )
return;
F_6 ( & V_35 ) ;
V_35 . V_36 = V_65 -> V_67 ;
V_69 = F_12 ( V_35 ) ;
if ( V_69 < 0 )
F_23 ( V_35 ) ;
else if ( ! V_69 )
return;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_35 = V_35 ;
if ( ( V_65 -> V_70 & 0xc0 ) != 0 ) {
V_50 . V_37 = V_65 -> V_37 ;
if ( ( V_65 -> V_70 & 0xc0 ) == 0xc0 )
V_50 . V_71 = 0xffff ;
else
V_50 . V_71 = 0xff00 ;
}
F_18 ( & V_50 ) ;
}
static void F_24 ( struct V_64 * V_65 )
{
struct V_72 * V_73 ;
struct V_47 V_35 ;
T_1 * V_40 ;
int V_74 ;
F_21 ( 4 , L_9 ) ;
if ( V_65 -> V_66 != 0 )
return;
V_40 = V_65 -> V_68 ;
F_6 ( & V_35 ) ;
for ( V_74 = 0 ; V_74 <= V_75 ; V_74 ++ ) {
if ( ! F_25 ( V_40 , V_74 ) )
continue;
V_35 . V_36 = V_74 ;
F_21 ( 4 , L_10
L_11 , V_35 . V_51 , V_35 . V_36 ) ;
V_73 = F_26 ( V_35 ) ;
if ( ! V_73 ) {
F_23 ( V_35 ) ;
continue;
}
F_27 ( & V_73 -> V_41 ) ;
F_28 ( V_35 , & V_73 -> V_76 ) ;
F_29 ( & V_73 -> V_41 ) ;
}
}
static void F_30 ( struct V_64 * V_65 )
{
struct V_77 * V_40 ;
struct V_47 V_35 ;
int V_74 ;
char * V_78 [ 3 ] = { L_12 , L_13 , L_14 } ;
F_21 ( 4 , L_15 ) ;
if ( V_65 -> V_66 != 0 )
return;
V_40 = (struct V_77 * ) & ( V_65 -> V_68 ) ;
F_6 ( & V_35 ) ;
for ( V_74 = 0 ; V_74 <= V_75 ; V_74 ++ ) {
if ( ! F_25 ( V_40 -> V_79 , V_74 ) )
continue;
V_35 . V_36 = V_74 ;
F_31 ( L_16 ,
V_78 [ V_40 -> V_80 ] , V_35 . V_51 , V_35 . V_36 ) ;
switch ( V_40 -> V_80 ) {
case 0 :
F_32 ( V_35 , 1 ) ;
break;
case 1 :
F_32 ( V_35 , 0 ) ;
break;
case 2 :
F_33 ( V_35 ) ;
break;
}
}
}
static void F_34 ( struct V_64 * V_65 )
{
int V_14 ;
F_21 ( 4 , L_17 ) ;
if ( V_65 -> V_66 != 7 )
return;
V_14 = F_35 () ;
if ( V_14 )
F_21 ( 0 , L_18
L_19 , V_14 ) ;
}
static void F_36 ( struct V_81 * V_65 )
{
#ifdef F_37
switch ( V_65 -> V_82 ) {
case 1 :
F_38 ( V_65 -> V_68 ) ;
break;
case 2 :
F_39 ( V_65 -> V_68 ) ;
break;
default:
F_21 ( 2 , L_20 ,
V_65 -> V_82 ) ;
break;
}
#endif
}
static void F_40 ( struct V_64 * V_65 )
{
switch ( V_65 -> V_82 ) {
case 1 :
F_20 ( V_65 ) ;
break;
case 2 :
F_22 ( V_65 ) ;
break;
case 7 :
F_24 ( V_65 ) ;
break;
case 8 :
F_30 ( V_65 ) ;
break;
case 12 :
F_34 ( V_65 ) ;
break;
default:
F_21 ( 4 , L_20 ,
V_65 -> V_82 ) ;
break;
}
}
static int F_41 ( struct V_83 * V_84 , T_4 V_85 )
{
do {
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
V_84 -> V_20 . V_21 = 0x0010 ;
V_84 -> V_20 . V_22 = 0x000e ;
V_84 -> V_85 = V_85 ;
if ( F_4 ( V_84 ) )
break;
if ( V_84 -> V_1 . V_22 == 0x0001 ) {
F_21 ( 2 , L_21 ) ;
if ( V_84 -> V_86 . V_87 . V_88 & 0x40 ) {
F_21 ( 2 , L_22 ) ;
F_42 () ;
}
switch ( V_84 -> V_89 ) {
case 0 :
F_40 ( & V_84 -> V_86 . V_87 ) ;
break;
case 2 :
F_36 ( & V_84 -> V_86 . V_90 ) ;
break;
default:
F_21 ( 2 , L_23 ,
V_84 -> V_89 ) ;
break;
}
} else {
F_21 ( 2 , L_24 ,
V_84 -> V_1 . V_22 ) ;
break;
}
} while ( V_84 -> V_86 . V_87 . V_88 & 0x80 );
return 0 ;
}
static void F_43 ( struct V_91 * V_92 , struct V_91 * V_93 , int V_94 )
{
struct V_83 * V_84 ;
if ( V_94 ) {
F_42 () ;
return;
}
F_21 ( 2 , L_25
L_26 ,
V_92 -> V_95 , V_92 -> V_96 , V_92 -> V_97 , V_92 -> V_98 , V_92 -> V_99 ,
V_92 -> V_100 , V_92 -> V_67 ) ;
if ( ! V_101 )
return;
V_84 = V_101 ;
F_11 ( 2 , L_27 ) ;
F_41 ( V_84 , V_102 | V_103 ) ;
}
void F_44 ( struct V_47 V_35 )
{
char V_48 [ 15 ] ;
struct V_49 V_50 ;
sprintf ( V_48 , L_28 , V_35 . V_51 , V_35 . V_36 ) ;
F_11 ( 2 , V_48 ) ;
if ( F_12 ( V_35 ) != 0 ) {
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_35 = V_35 ;
F_13 () ;
F_14 ( F_17 , NULL ,
& V_50 ) ;
}
}
static void F_45 ( struct V_38 * V_39 ,
struct V_47 V_35 , int V_104 )
{
unsigned long V_88 ;
struct V_49 V_50 ;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_35 = V_35 ;
F_46 ( V_39 -> V_41 , V_88 ) ;
if ( V_39 -> V_42 && V_39 -> V_42 -> V_43 )
V_39 -> V_42 -> V_43 ( V_39 , & V_50 ,
V_104 ? V_105 : V_106 ) ;
F_47 ( V_39 -> V_41 , V_88 ) ;
}
static int F_48 ( struct V_38 * V_39 , void * V_40 )
{
struct V_47 * V_35 = V_40 ;
F_45 ( V_39 , * V_35 , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_38 * V_39 , void * V_40 )
{
struct V_47 * V_35 = V_40 ;
F_45 ( V_39 , * V_35 , 1 ) ;
return 0 ;
}
static int
F_50 ( struct V_7 V_8 , void * V_40 )
{
struct V_52 V_52 ;
if ( F_16 ( V_8 , & V_52 ) )
return - V_53 ;
F_9 ( V_8 ) ;
return 0 ;
}
int F_51 ( struct V_47 V_35 , int V_104 )
{
struct V_72 * V_73 = F_26 ( V_35 ) ;
F_13 () ;
if ( V_104 ) {
F_28 ( V_35 , & V_73 -> V_76 ) ;
F_14 ( F_49 ,
F_50 , & V_35 ) ;
} else
F_14 ( F_48 ,
NULL , & V_35 ) ;
return 0 ;
}
static void
F_52 ( struct V_107 * V_108 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 <= V_75 ; V_15 ++ ) {
if ( ! V_108 -> V_109 [ V_15 ] )
continue;
F_53 ( V_108 -> V_109 [ V_15 ] ) ;
}
}
static int
F_54 ( struct V_107 * V_108 )
{
int V_15 , V_14 ;
V_14 = 0 ;
for ( V_15 = 0 ; V_15 <= V_75 ; V_15 ++ ) {
if ( ! V_108 -> V_109 [ V_15 ] )
continue;
V_14 = F_55 ( V_108 -> V_109 [ V_15 ] ) ;
if ( V_14 )
goto V_110;
}
return V_14 ;
V_110:
for ( -- V_15 ; V_15 >= 0 ; V_15 -- ) {
if ( ! V_108 -> V_109 [ V_15 ] )
continue;
F_53 ( V_108 -> V_109 [ V_15 ] ) ;
}
return V_14 ;
}
int F_56 ( struct V_107 * V_108 , int V_111 )
{
struct {
struct V_112 V_20 ;
T_3 V_113 : 2 ;
T_3 : 30 ;
T_3 V_114 : 4 ;
T_3 : 28 ;
T_3 V_115 ;
T_3 V_116 ;
T_3 V_117 ;
T_3 V_118 ;
T_3 V_119 [ 13 ] ;
struct V_112 V_1 ;
T_3 V_69 : 8 ;
T_3 : 4 ;
T_3 V_120 : 4 ;
T_3 : 16 ;
} V_62 ( ( V_63 ) ) * V_121 ;
int V_14 , V_13 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_121 = V_18 ;
V_121 -> V_20 . V_21 = 0x0050 ;
V_121 -> V_20 . V_22 = 0x0016 ;
V_121 -> V_114 = V_122 >> 4 ;
V_121 -> V_116 = ( T_4 ) ( unsigned long ) V_108 -> V_116 ;
V_121 -> V_118 = ( T_4 ) ( unsigned long ) V_108 -> V_118 ;
V_121 -> V_113 = V_111 ? 0 : 1 ;
V_13 = F_4 ( V_121 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_121 -> V_1 . V_22 ) {
case 0x0102 :
case 0x0103 :
V_14 = - V_2 ;
break;
default:
V_14 = F_1 ( V_121 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_21 ( 2 , L_29 ,
V_121 -> V_1 . V_22 ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int
F_57 ( struct V_107 * V_108 , int V_111 )
{
int V_14 ;
if ( V_111 && ! V_108 -> V_123 ) {
V_108 -> V_116 = ( void * ) F_58 ( V_124 | V_125 ) ;
V_108 -> V_118 = ( void * ) F_58 ( V_124 | V_125 ) ;
if ( ! V_108 -> V_116 || ! V_108 -> V_118 ) {
F_59 ( ( unsigned long ) V_108 -> V_116 ) ;
F_59 ( ( unsigned long ) V_108 -> V_118 ) ;
return - V_5 ;
}
}
V_14 = F_56 ( V_108 , V_111 ) ;
if ( ! V_14 ) {
V_108 -> V_123 = V_111 ;
if ( V_108 -> V_123 ) {
V_14 = F_54 ( V_108 ) ;
if ( V_14 ) {
F_56 ( V_108 , 0 ) ;
V_108 -> V_123 = 0 ;
}
} else
F_52 ( V_108 ) ;
}
if ( ! V_108 -> V_123 ) {
F_59 ( ( unsigned long ) V_108 -> V_116 ) ;
F_59 ( ( unsigned long ) V_108 -> V_118 ) ;
}
return V_14 ;
}
int F_60 ( struct V_47 V_35 , int V_120 , int V_126 ,
int V_127 , int V_128 , void * V_129 )
{
struct V_130 * V_131 ;
int V_13 , V_14 ;
if ( ( V_126 == 1 ) && ! V_132 . V_133 )
return - V_2 ;
if ( ( V_126 == 2 ) && ! V_132 . V_134 )
return - V_2 ;
memset ( V_129 , 0 , V_19 ) ;
V_131 = V_129 ;
V_131 -> V_20 . V_21 = 0x0010 ;
V_131 -> V_20 . V_22 = 0x0002 ;
V_131 -> V_51 = V_35 . V_51 ;
V_131 -> V_135 = V_35 . V_36 ;
V_131 -> V_136 = V_35 . V_36 ;
V_131 -> V_128 = V_128 ;
V_131 -> V_127 = V_127 ;
V_131 -> V_120 = V_120 ;
V_131 -> V_126 = V_126 ;
V_13 = F_4 ( V_131 ) ;
if ( V_13 > 0 )
return ( V_13 == 3 ) ? - V_27 : - V_4 ;
V_14 = F_1 ( V_131 -> V_1 . V_22 ) ;
if ( V_14 )
F_21 ( 2 , L_30 ,
V_131 -> V_1 . V_22 ) ;
return V_14 ;
}
int F_28 ( struct V_47 V_35 ,
struct V_137 * V_76 )
{
struct V_138 * V_139 ;
struct V_130 * V_131 ;
unsigned long V_88 ;
int V_14 ;
F_46 ( & V_17 , V_88 ) ;
V_131 = V_18 ;
V_14 = F_60 ( V_35 , 0 , 0 , 0 , 0 , V_131 ) ;
if ( V_14 )
goto V_28;
V_139 = ( void * ) & V_131 -> V_1 ;
memcpy ( V_76 , & V_139 -> V_40 , sizeof( * V_76 ) ) ;
V_28:
F_47 ( & V_17 , V_88 ) ;
return V_14 ;
}
int F_61 ( struct V_47 V_35 ,
struct V_140 * V_76 )
{
struct V_138 * V_139 ;
struct V_130 * V_131 ;
int V_14 ;
F_3 ( & V_17 ) ;
V_131 = V_18 ;
V_14 = F_60 ( V_35 , 0 , 0 , 1 , 0 , V_131 ) ;
if ( V_14 )
goto V_28;
V_139 = ( void * ) & V_131 -> V_1 ;
memcpy ( V_76 , & V_139 -> V_40 , sizeof( * V_76 ) ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
static void
F_62 ( struct V_72 * V_73 , T_1 V_141 ,
struct V_142 * V_143 )
{
struct V_142 * V_142 ;
int V_15 , V_16 ;
V_142 = V_73 -> V_142 ;
for ( V_15 = 0 ; V_15 < V_144 ; V_15 ++ ) {
V_16 = 0x80 >> ( V_15 + 3 ) ;
if ( V_141 & V_16 )
V_142 -> V_145 [ V_15 ] = V_143 -> V_145 [ V_15 ] ;
else
V_142 -> V_145 [ V_15 ] = 0 ;
}
}
int F_63 ( struct V_72 * V_73 )
{
struct V_142 * V_142 ;
int V_13 , V_14 ;
struct {
struct V_112 V_20 ;
T_3 : 24 ;
T_3 V_135 : 8 ;
T_3 : 24 ;
T_3 V_136 : 8 ;
T_3 V_115 ;
struct V_112 V_1 ;
T_3 V_117 ;
T_3 V_146 : 1 ;
T_3 V_147 : 1 ;
T_3 : 22 ;
T_3 V_35 : 8 ;
T_3 V_141 : 5 ;
T_3 : 11 ;
T_3 V_148 : 8 ;
T_3 V_149 : 8 ;
T_3 V_150 ;
T_3 V_40 [ V_144 ] ;
} V_62 ( ( V_63 ) ) * V_151 ;
V_73 -> V_142 = NULL ;
V_142 = F_64 ( sizeof( * V_142 ) , V_124 ) ;
if ( ! V_142 )
return - V_5 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_151 = V_18 ;
V_151 -> V_20 . V_21 = 0x0010 ;
V_151 -> V_20 . V_22 = 0x0022 ;
V_151 -> V_135 = V_73 -> V_35 . V_36 ;
V_151 -> V_136 = V_73 -> V_35 . V_36 ;
V_13 = F_4 ( V_151 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_151 -> V_1 . V_22 ) ;
if ( V_14 ) {
F_21 ( 2 , L_31 ,
V_151 -> V_1 . V_22 ) ;
goto V_28;
}
if ( V_151 -> V_146 ) {
V_73 -> V_149 = - 1 ;
V_73 -> V_147 = - 1 ;
goto V_28;
}
V_73 -> V_149 = V_151 -> V_149 ;
V_73 -> V_147 = V_151 -> V_147 ;
if ( V_73 -> V_149 != 2 && V_73 -> V_149 != 3 ) {
goto V_28;
}
V_73 -> V_142 = V_142 ;
F_62 ( V_73 , V_151 -> V_141 ,
(struct V_142 * ) & V_151 -> V_40 ) ;
V_28:
F_7 ( & V_17 ) ;
if ( ! V_73 -> V_142 )
F_65 ( V_142 ) ;
return V_14 ;
}
int T_5 F_66 ( void )
{
int V_14 ;
V_101 = ( void * ) F_58 ( V_124 | V_125 ) ;
V_18 = ( void * ) F_58 ( V_124 | V_125 ) ;
if ( ! V_101 || ! V_18 ) {
V_14 = - V_5 ;
goto V_152;
}
V_14 = F_67 ( V_153 , F_43 ) ;
if ( V_14 )
goto V_152;
return V_14 ;
V_152:
F_59 ( ( unsigned long ) V_18 ) ;
F_59 ( ( unsigned long ) V_101 ) ;
return V_14 ;
}
void T_5 F_68 ( void )
{
F_69 ( V_153 ) ;
F_59 ( ( unsigned long ) V_18 ) ;
F_59 ( ( unsigned long ) V_101 ) ;
}
int F_70 ( int V_113 )
{
unsigned long V_88 ;
int V_14 ;
struct {
struct V_112 V_20 ;
T_1 V_154 : 4 ;
T_1 V_155 : 4 ;
T_1 V_156 ;
T_2 V_113 ;
T_3 V_157 ;
T_3 V_158 ;
T_3 V_159 [ 252 ] ;
struct V_112 V_1 ;
T_3 V_160 : 4 ;
T_3 V_161 : 4 ;
T_3 V_162 : 24 ;
} V_62 ( ( V_63 ) ) * V_163 ;
F_46 ( & V_17 , V_88 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_163 = V_18 ;
V_163 -> V_20 . V_21 = 0x0400 ;
V_163 -> V_20 . V_22 = 0x0031 ;
V_163 -> V_113 = V_113 ;
V_14 = F_4 ( V_163 ) ;
if ( V_14 > 0 ) {
V_14 = ( V_14 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_163 -> V_1 . V_22 ) {
case 0x0101 :
V_14 = - V_3 ;
break;
default:
V_14 = F_1 ( V_163 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_21 ( 2 , L_32 ,
V_113 , V_163 -> V_1 . V_22 ) ;
V_28:
F_47 ( & V_17 , V_88 ) ;
return V_14 ;
}
int T_5
F_71 ( void )
{
int V_164 ;
struct {
struct V_112 V_20 ;
T_3 V_154 ;
T_3 V_156 ;
T_3 V_157 ;
struct V_112 V_1 ;
T_3 V_158 ;
T_3 V_165 [ 510 ] ;
T_3 V_166 [ 508 ] ;
} V_62 ( ( V_63 ) ) * V_167 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_167 = V_18 ;
V_167 -> V_20 . V_21 = 0x0010 ;
V_167 -> V_20 . V_22 = 0x0010 ;
V_164 = F_4 ( V_167 ) ;
if ( V_164 ) {
V_164 = ( V_164 == 3 ) ? - V_27 : - V_4 ;
goto exit;
}
V_164 = F_1 ( V_167 -> V_1 . V_22 ) ;
if ( V_164 == 0 ) {
memcpy ( & V_132 , V_167 -> V_165 ,
sizeof( V_132 ) ) ;
memcpy ( & V_168 , V_167 -> V_166 ,
sizeof( V_168 ) ) ;
} else
F_21 ( 2 , L_33 ,
V_167 -> V_1 . V_22 ) ;
exit:
F_7 ( & V_17 ) ;
return V_164 ;
}
int F_72 ( void * V_129 , unsigned int V_80 , T_2 V_169 )
{
struct {
struct V_112 V_20 ;
unsigned int V_170 ;
unsigned int V_80 : 8 ;
unsigned int V_171 : 8 ;
unsigned int V_169 : 16 ;
unsigned int V_172 [ 5 ] ;
struct V_112 V_1 ;
unsigned int V_173 [ 7 ] ;
} V_62 ( ( V_63 ) ) * V_174 ;
int V_175 ;
memset ( V_129 , 0 , V_19 ) ;
V_174 = V_129 ;
V_174 -> V_20 . V_21 = 0x0020 ;
V_174 -> V_20 . V_22 = 0x0033 ;
V_174 -> V_80 = V_80 ;
V_174 -> V_169 = V_169 ;
V_175 = F_4 ( V_174 ) ;
if ( V_175 )
return - V_6 ;
V_175 = ( V_174 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
return V_175 ;
}
int F_73 ( void * V_129 , void * V_164 , T_6 V_176 )
{
struct {
struct V_112 V_20 ;
unsigned int V_170 [ 3 ] ;
struct V_112 V_1 ;
char V_40 [ V_176 ] ;
} V_62 ( ( V_63 ) ) * V_174 ;
int V_175 ;
memset ( V_129 , 0 , V_19 ) ;
V_174 = V_129 ;
V_174 -> V_20 . V_21 = 0x0010 ;
V_174 -> V_20 . V_22 = 0x0038 ;
V_175 = F_4 ( V_174 ) ;
if ( V_175 )
return - V_6 ;
memcpy ( V_164 , & V_174 -> V_40 , V_176 ) ;
return ( V_174 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
}
int F_74 ( struct V_7 V_8 )
{
struct {
struct V_112 V_20 ;
T_3 V_177 ;
struct V_7 V_178 ;
T_3 V_179 ;
struct V_112 V_1 ;
T_3 V_180 [ 11 ] ;
} V_62 ( ( V_63 ) ) * V_181 ;
unsigned long V_88 ;
int V_13 ;
int V_175 ;
F_46 ( & V_17 , V_88 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_181 = V_18 ;
V_181 -> V_20 . V_21 = 0x0010 ;
V_181 -> V_20 . V_22 = 0x0046 ;
V_181 -> V_177 = 0x80000000 ;
V_181 -> V_178 = V_8 ;
V_13 = F_4 ( V_181 ) ;
if ( V_13 > 0 ) {
if ( V_13 == 3 )
V_175 = - V_27 ;
else
V_175 = - V_4 ;
F_5 ( 2 , L_34 ,
V_8 . V_23 , V_8 . V_25 , V_13 ) ;
goto V_28;
}
V_175 = F_1 ( V_181 -> V_1 . V_22 ) ;
if ( V_175 )
F_5 ( 2 , L_35 ,
V_8 . V_23 , V_8 . V_25 ,
V_181 -> V_1 . V_22 ) ;
else
F_5 ( 4 , L_36 ,
V_8 . V_23 , V_8 . V_25 ) ;
V_28:
F_47 ( & V_17 , V_88 ) ;
return V_175 ;
}
int F_75 ( struct F_75 * V_182 , T_4 V_183 )
{
int V_13 , V_14 ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_20 . V_21 = 0x0020 ;
V_182 -> V_20 . V_22 = 0x004C ;
V_182 -> V_184 = V_183 ;
V_13 = F_4 ( V_182 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_182 -> V_1 . V_22 ) ;
if ( V_14 != 0 )
F_5 ( 2 , L_37 ,
V_182 -> V_1 . V_22 ) ;
V_28:
return V_14 ;
}
