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
default:
return - V_4 ;
}
}
int F_2 ( struct V_5 V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
int V_12 ;
int V_13 ;
int V_14 ;
F_3 ( & V_15 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_10 = V_16 ;
V_10 -> V_18 . V_19 = 0x0010 ;
V_10 -> V_18 . V_20 = 0x0004 ;
V_10 -> V_21 = V_6 . V_21 ;
V_10 -> V_22 = V_6 . V_23 ;
V_10 -> V_24 = V_6 . V_23 ;
V_11 = F_4 ( V_10 ) ;
if ( V_11 > 0 ) {
V_12 = ( V_11 == 3 ) ? - V_25 : - V_26 ;
goto V_27;
}
V_12 = F_1 ( V_10 -> V_1 . V_20 ) ;
if ( V_12 != 0 ) {
F_5 ( 2 , L_1 ,
V_6 . V_21 , V_6 . V_23 ,
V_10 -> V_1 . V_20 ) ;
goto V_27;
}
if ( ! V_10 -> V_28 ) {
V_12 = - V_25 ;
goto V_27;
}
V_12 = 0 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
if ( ( V_10 -> V_29 != V_30 ) &&
( V_10 -> V_29 != V_31 ) )
goto V_27;
V_8 -> V_32 = V_10 -> V_32 ;
V_8 -> V_33 = V_10 -> V_33 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_14 = 0x80 >> V_13 ;
if ( V_10 -> V_32 & V_14 ) {
F_6 ( & V_8 -> V_34 [ V_13 ] ) ;
V_8 -> V_34 [ V_13 ] . V_35 = V_10 -> V_34 [ V_13 ] ;
}
if ( V_10 -> V_33 & V_14 )
V_8 -> V_36 [ V_13 ] = V_10 -> V_36 [ V_13 ] ;
}
V_27:
F_7 ( & V_15 ) ;
return V_12 ;
}
static int F_8 ( struct V_37 * V_38 , void * V_39 )
{
F_3 ( V_38 -> V_40 ) ;
if ( V_38 -> V_41 && V_38 -> V_41 -> V_42 )
if ( V_38 -> V_41 -> V_42 ( V_38 , V_39 , V_43 ) != 0 )
goto V_44;
F_7 ( V_38 -> V_40 ) ;
return 0 ;
V_44:
V_38 -> V_45 = 0 ;
F_7 ( V_38 -> V_40 ) ;
F_9 ( V_38 -> V_6 ) ;
return 0 ;
}
void F_10 ( struct V_46 V_34 )
{
char V_47 [ 15 ] ;
struct V_48 V_49 ;
sprintf ( V_47 , L_2 , V_34 . V_50 , V_34 . V_35 ) ;
F_11 ( 2 , V_47 ) ;
if ( F_12 ( V_34 ) <= 0 )
return;
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_34 = V_34 ;
F_13 () ;
F_14 ( F_8 , NULL , & V_49 ) ;
}
static int F_15 ( struct V_5 V_6 , void * V_39 )
{
struct V_51 V_51 ;
if ( F_16 ( V_6 , & V_51 ) )
return - V_52 ;
F_9 ( V_6 ) ;
return 0 ;
}
static int F_17 ( struct V_37 * V_38 , void * V_39 )
{
F_3 ( V_38 -> V_40 ) ;
if ( V_38 -> V_41 && V_38 -> V_41 -> V_42 )
V_38 -> V_41 -> V_42 ( V_38 , V_39 , V_53 ) ;
F_7 ( V_38 -> V_40 ) ;
return 0 ;
}
static void F_18 ( struct V_48 * V_49 )
{
char V_47 [ 15 ] ;
sprintf ( V_47 , L_3 , V_49 -> V_34 . V_50 ,
V_49 -> V_34 . V_35 ) ;
F_11 ( 2 , V_47 ) ;
if ( V_49 -> V_36 != 0 ) {
sprintf ( V_47 , L_4 , V_49 -> V_36 ) ;
F_11 ( 2 , V_47 ) ;
}
F_13 () ;
F_14 ( F_17 ,
F_15 , V_49 ) ;
}
static int
F_19 ( void * V_39 )
{
struct V_54 {
T_1 V_55 ;
T_1 V_56 ;
T_2 V_57 ;
T_3 V_58 [ 28 ] ;
T_3 V_59 [ 28 ] ;
T_3 V_60 [ 28 ] ;
} V_61 ( ( V_62 ) ) * V_54 ;
V_54 = V_39 ;
if ( ! ( V_54 -> V_55 & 0x80 ) )
return - V_2 ;
if ( ! ( V_54 -> V_58 [ 0 ] & 0xc0000000 ) )
return - V_2 ;
if ( ! ( V_54 -> V_58 [ 0 ] & 0x10000000 ) )
return - V_2 ;
return ( T_2 ) ( V_54 -> V_58 [ 0 ] & 0x000000ff ) ;
}
static void F_20 ( struct V_63 * V_64 )
{
struct V_46 V_34 ;
int V_35 ;
F_21 ( 4 , L_5 ,
V_64 -> V_65 , V_64 -> V_66 ) ;
if ( V_64 -> V_65 != 4 )
return;
V_35 = F_19 ( V_64 -> V_67 ) ;
if ( V_35 < 0 )
F_21 ( 4 , L_6 ) ;
else {
F_6 ( & V_34 ) ;
V_34 . V_35 = V_35 ;
F_10 ( V_34 ) ;
}
}
static void F_22 ( struct V_63 * V_64 )
{
struct V_48 V_49 ;
struct V_46 V_34 ;
int V_68 ;
F_21 ( 4 , L_7
L_8 , V_64 -> V_65 , V_64 -> V_66 ) ;
if ( V_64 -> V_65 != 4 )
return;
F_6 ( & V_34 ) ;
V_34 . V_35 = V_64 -> V_66 ;
V_68 = F_12 ( V_34 ) ;
if ( V_68 < 0 )
F_23 ( V_34 ) ;
else if ( ! V_68 )
return;
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_34 = V_34 ;
if ( ( V_64 -> V_69 & 0xc0 ) != 0 ) {
V_49 . V_36 = V_64 -> V_36 ;
if ( ( V_64 -> V_69 & 0xc0 ) == 0xc0 )
V_49 . V_70 = 0xffff ;
else
V_49 . V_70 = 0xff00 ;
}
F_18 ( & V_49 ) ;
}
static void F_24 ( struct V_63 * V_64 )
{
struct V_71 * V_72 ;
struct V_46 V_34 ;
T_1 * V_39 ;
int V_73 ;
F_21 ( 4 , L_9 ) ;
if ( V_64 -> V_65 != 0 )
return;
V_39 = V_64 -> V_67 ;
F_6 ( & V_34 ) ;
for ( V_73 = 0 ; V_73 <= V_74 ; V_73 ++ ) {
if ( ! F_25 ( V_39 , V_73 ) )
continue;
V_34 . V_35 = V_73 ;
F_21 ( 4 , L_10
L_11 , V_34 . V_50 , V_34 . V_35 ) ;
V_72 = F_26 ( V_34 ) ;
if ( ! V_72 ) {
F_23 ( V_34 ) ;
continue;
}
F_27 ( & V_72 -> V_40 ) ;
F_28 ( V_34 , & V_72 -> V_75 ) ;
F_29 ( & V_72 -> V_40 ) ;
}
}
static void F_30 ( struct V_63 * V_64 )
{
struct V_76 * V_39 ;
struct V_46 V_34 ;
int V_73 ;
char * V_77 [ 3 ] = { L_12 , L_13 , L_14 } ;
F_21 ( 4 , L_15 ) ;
if ( V_64 -> V_65 != 0 )
return;
V_39 = (struct V_76 * ) & ( V_64 -> V_67 ) ;
F_6 ( & V_34 ) ;
for ( V_73 = 0 ; V_73 <= V_74 ; V_73 ++ ) {
if ( ! F_25 ( V_39 -> V_78 , V_73 ) )
continue;
V_34 . V_35 = V_73 ;
F_31 ( L_16 ,
V_77 [ V_39 -> V_79 ] , V_34 . V_50 , V_34 . V_35 ) ;
switch ( V_39 -> V_79 ) {
case 0 :
F_32 ( V_34 , 1 ) ;
break;
case 1 :
F_32 ( V_34 , 0 ) ;
break;
case 2 :
F_33 ( V_34 ) ;
break;
}
}
}
static void F_34 ( struct V_63 * V_64 )
{
if ( V_64 -> V_80 & 0x40 ) {
F_21 ( 2 , L_17 ) ;
F_35 () ;
}
switch ( V_64 -> V_81 ) {
case 1 :
F_20 ( V_64 ) ;
break;
case 2 :
F_22 ( V_64 ) ;
break;
case 7 :
F_24 ( V_64 ) ;
break;
case 8 :
F_30 ( V_64 ) ;
break;
default:
F_21 ( 4 , L_18 ,
V_64 -> V_81 ) ;
break;
}
}
static void F_36 ( struct V_82 * V_83 , struct V_82 * V_84 , int V_85 )
{
struct V_63 * V_64 ;
if ( V_85 ) {
F_35 () ;
return;
}
F_21 ( 2 , L_19
L_20 ,
V_83 -> V_86 , V_83 -> V_87 , V_83 -> V_88 , V_83 -> V_89 , V_83 -> V_90 ,
V_83 -> V_91 , V_83 -> V_66 ) ;
if ( ! V_92 )
return;
V_64 = V_92 ;
F_11 ( 2 , L_21 ) ;
do {
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_18 . V_19 = 0x0010 ;
V_64 -> V_18 . V_20 = 0x000e ;
if ( F_4 ( V_64 ) )
break;
if ( V_64 -> V_1 . V_20 == 0x0001 ) {
F_21 ( 4 , L_22 ) ;
F_34 ( V_64 ) ;
} else {
F_21 ( 2 , L_23 ,
V_64 -> V_1 . V_20 ) ;
break;
}
} while ( V_64 -> V_80 & 0x80 );
}
void F_37 ( struct V_46 V_34 )
{
char V_47 [ 15 ] ;
struct V_48 V_49 ;
sprintf ( V_47 , L_24 , V_34 . V_50 , V_34 . V_35 ) ;
F_11 ( 2 , V_47 ) ;
if ( F_12 ( V_34 ) != 0 ) {
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_34 = V_34 ;
F_13 () ;
F_14 ( F_17 , NULL ,
& V_49 ) ;
}
}
static void F_38 ( struct V_37 * V_38 ,
struct V_46 V_34 , int V_93 )
{
unsigned long V_80 ;
struct V_48 V_49 ;
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_34 = V_34 ;
F_39 ( V_38 -> V_40 , V_80 ) ;
if ( V_38 -> V_41 && V_38 -> V_41 -> V_42 )
V_38 -> V_41 -> V_42 ( V_38 , & V_49 ,
V_93 ? V_94 : V_95 ) ;
F_40 ( V_38 -> V_40 , V_80 ) ;
}
static int F_41 ( struct V_37 * V_38 , void * V_39 )
{
struct V_46 * V_34 = V_39 ;
F_38 ( V_38 , * V_34 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 , void * V_39 )
{
struct V_46 * V_34 = V_39 ;
F_38 ( V_38 , * V_34 , 1 ) ;
return 0 ;
}
static int
F_43 ( struct V_5 V_6 , void * V_39 )
{
struct V_51 V_51 ;
if ( F_16 ( V_6 , & V_51 ) )
return - V_52 ;
F_9 ( V_6 ) ;
return 0 ;
}
int F_44 ( struct V_46 V_34 , int V_93 )
{
struct V_71 * V_72 = F_26 ( V_34 ) ;
struct V_48 V_49 ;
memset ( & V_49 , 0 , sizeof( struct V_48 ) ) ;
V_49 . V_34 = V_34 ;
F_13 () ;
if ( V_93 ) {
F_28 ( V_34 , & V_72 -> V_75 ) ;
F_14 ( F_42 ,
F_43 , & V_49 ) ;
} else
F_14 ( F_41 ,
NULL , & V_49 ) ;
return 0 ;
}
static void
F_45 ( struct V_96 * V_97 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 <= V_74 ; V_13 ++ ) {
if ( ! V_97 -> V_98 [ V_13 ] )
continue;
F_46 ( V_97 -> V_98 [ V_13 ] ) ;
}
}
static int
F_47 ( struct V_96 * V_97 )
{
int V_13 , V_12 ;
V_12 = 0 ;
for ( V_13 = 0 ; V_13 <= V_74 ; V_13 ++ ) {
if ( ! V_97 -> V_98 [ V_13 ] )
continue;
V_12 = F_48 ( V_97 -> V_98 [ V_13 ] ) ;
if ( V_12 )
goto V_99;
}
return V_12 ;
V_99:
for ( -- V_13 ; V_13 >= 0 ; V_13 -- ) {
if ( ! V_97 -> V_98 [ V_13 ] )
continue;
F_46 ( V_97 -> V_98 [ V_13 ] ) ;
}
return V_12 ;
}
int F_49 ( struct V_96 * V_97 , int V_100 )
{
struct {
struct V_101 V_18 ;
T_3 V_102 : 2 ;
T_3 : 30 ;
T_3 V_103 : 4 ;
T_3 : 28 ;
T_3 V_104 ;
T_3 V_105 ;
T_3 V_106 ;
T_3 V_107 ;
T_3 V_108 [ 13 ] ;
struct V_101 V_1 ;
T_3 V_68 : 8 ;
T_3 : 4 ;
T_3 V_109 : 4 ;
T_3 : 16 ;
} V_61 ( ( V_62 ) ) * V_110 ;
int V_12 , V_11 ;
F_3 ( & V_15 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_110 = V_16 ;
V_110 -> V_18 . V_19 = 0x0050 ;
V_110 -> V_18 . V_20 = 0x0016 ;
V_110 -> V_103 = V_111 >> 4 ;
V_110 -> V_105 = ( V_112 ) ( unsigned long ) V_97 -> V_105 ;
V_110 -> V_107 = ( V_112 ) ( unsigned long ) V_97 -> V_107 ;
V_110 -> V_102 = V_100 ? 0 : 1 ;
V_11 = F_4 ( V_110 ) ;
if ( V_11 > 0 ) {
V_12 = ( V_11 == 3 ) ? - V_25 : - V_26 ;
goto V_27;
}
switch ( V_110 -> V_1 . V_20 ) {
case 0x0102 :
case 0x0103 :
V_12 = - V_2 ;
break;
default:
V_12 = F_1 ( V_110 -> V_1 . V_20 ) ;
}
if ( V_12 != 0 )
F_21 ( 2 , L_25 ,
V_110 -> V_1 . V_20 ) ;
V_27:
F_7 ( & V_15 ) ;
return V_12 ;
}
int
F_50 ( struct V_96 * V_97 , int V_100 )
{
int V_12 ;
if ( V_100 && ! V_97 -> V_113 ) {
V_97 -> V_105 = ( void * ) F_51 ( V_114 | V_115 ) ;
V_97 -> V_107 = ( void * ) F_51 ( V_114 | V_115 ) ;
if ( ! V_97 -> V_105 || ! V_97 -> V_107 ) {
F_52 ( ( unsigned long ) V_97 -> V_105 ) ;
F_52 ( ( unsigned long ) V_97 -> V_107 ) ;
return - V_116 ;
}
}
V_12 = F_49 ( V_97 , V_100 ) ;
if ( ! V_12 ) {
V_97 -> V_113 = V_100 ;
if ( V_97 -> V_113 ) {
V_12 = F_47 ( V_97 ) ;
if ( V_12 ) {
F_49 ( V_97 , 0 ) ;
V_97 -> V_113 = 0 ;
}
} else
F_45 ( V_97 ) ;
}
if ( ! V_97 -> V_113 ) {
F_52 ( ( unsigned long ) V_97 -> V_105 ) ;
F_52 ( ( unsigned long ) V_97 -> V_107 ) ;
}
return V_12 ;
}
int F_53 ( struct V_46 V_34 , int V_109 , int V_117 ,
int V_118 , int V_119 , void * V_120 )
{
struct V_121 * V_122 ;
int V_11 , V_12 ;
if ( ( V_117 == 1 ) && ! V_123 . V_124 )
return - V_2 ;
if ( ( V_117 == 2 ) && ! V_123 . V_125 )
return - V_2 ;
memset ( V_120 , 0 , V_17 ) ;
V_122 = V_120 ;
V_122 -> V_18 . V_19 = 0x0010 ;
V_122 -> V_18 . V_20 = 0x0002 ;
V_122 -> V_50 = V_34 . V_50 ;
V_122 -> V_126 = V_34 . V_35 ;
V_122 -> V_127 = V_34 . V_35 ;
V_122 -> V_119 = V_119 ;
V_122 -> V_118 = V_118 ;
V_122 -> V_109 = V_109 ;
V_122 -> V_117 = V_117 ;
V_11 = F_4 ( V_122 ) ;
if ( V_11 > 0 )
return ( V_11 == 3 ) ? - V_25 : - V_26 ;
V_12 = F_1 ( V_122 -> V_1 . V_20 ) ;
if ( V_12 )
F_21 ( 2 , L_26 ,
V_122 -> V_1 . V_20 ) ;
return V_12 ;
}
int F_28 ( struct V_46 V_34 ,
struct V_128 * V_75 )
{
struct V_129 * V_130 ;
struct V_121 * V_122 ;
unsigned long V_80 ;
int V_12 ;
F_39 ( & V_15 , V_80 ) ;
V_122 = V_16 ;
V_12 = F_53 ( V_34 , 0 , 0 , 0 , 0 , V_122 ) ;
if ( V_12 )
goto V_27;
V_130 = ( void * ) & V_122 -> V_1 ;
memcpy ( V_75 , & V_130 -> V_39 , sizeof( * V_75 ) ) ;
V_27:
F_40 ( & V_15 , V_80 ) ;
return V_12 ;
}
int F_54 ( struct V_46 V_34 ,
struct V_131 * V_75 )
{
struct V_129 * V_130 ;
struct V_121 * V_122 ;
int V_12 ;
F_3 ( & V_15 ) ;
V_122 = V_16 ;
V_12 = F_53 ( V_34 , 0 , 0 , 1 , 0 , V_122 ) ;
if ( V_12 )
goto V_27;
V_130 = ( void * ) & V_122 -> V_1 ;
memcpy ( V_75 , & V_130 -> V_39 , sizeof( * V_75 ) ) ;
V_27:
F_7 ( & V_15 ) ;
return V_12 ;
}
static void
F_55 ( struct V_71 * V_72 , T_1 V_132 ,
struct V_133 * V_134 )
{
struct V_133 * V_133 ;
int V_13 , V_14 ;
V_133 = V_72 -> V_133 ;
for ( V_13 = 0 ; V_13 < V_135 ; V_13 ++ ) {
V_14 = 0x80 >> ( V_13 + 3 ) ;
if ( V_132 & V_14 )
V_133 -> V_136 [ V_13 ] = V_134 -> V_136 [ V_13 ] ;
else
V_133 -> V_136 [ V_13 ] = 0 ;
}
}
int F_56 ( struct V_71 * V_72 )
{
struct V_133 * V_133 ;
int V_11 , V_12 ;
struct {
struct V_101 V_18 ;
T_3 : 24 ;
T_3 V_126 : 8 ;
T_3 : 24 ;
T_3 V_127 : 8 ;
T_3 V_104 ;
struct V_101 V_1 ;
T_3 V_106 ;
T_3 V_137 : 1 ;
T_3 V_138 : 1 ;
T_3 : 22 ;
T_3 V_34 : 8 ;
T_3 V_132 : 5 ;
T_3 : 11 ;
T_3 V_139 : 8 ;
T_3 V_140 : 8 ;
T_3 V_141 ;
T_3 V_39 [ V_135 ] ;
} V_61 ( ( V_62 ) ) * V_142 ;
V_72 -> V_133 = NULL ;
V_133 = F_57 ( sizeof( * V_133 ) , V_114 ) ;
if ( ! V_133 )
return - V_116 ;
F_3 ( & V_15 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_142 = V_16 ;
V_142 -> V_18 . V_19 = 0x0010 ;
V_142 -> V_18 . V_20 = 0x0022 ;
V_142 -> V_126 = V_72 -> V_34 . V_35 ;
V_142 -> V_127 = V_72 -> V_34 . V_35 ;
V_11 = F_4 ( V_142 ) ;
if ( V_11 > 0 ) {
V_12 = ( V_11 == 3 ) ? - V_25 : - V_26 ;
goto V_27;
}
V_12 = F_1 ( V_142 -> V_1 . V_20 ) ;
if ( V_12 ) {
F_21 ( 2 , L_27 ,
V_142 -> V_1 . V_20 ) ;
goto V_27;
}
if ( V_142 -> V_137 ) {
V_72 -> V_140 = - 1 ;
V_72 -> V_138 = - 1 ;
goto V_27;
}
V_72 -> V_140 = V_142 -> V_140 ;
V_72 -> V_138 = V_142 -> V_138 ;
if ( V_72 -> V_140 != 2 && V_72 -> V_140 != 3 ) {
goto V_27;
}
V_72 -> V_133 = V_133 ;
F_55 ( V_72 , V_142 -> V_132 ,
(struct V_133 * ) & V_142 -> V_39 ) ;
V_27:
F_7 ( & V_15 ) ;
if ( ! V_72 -> V_133 )
F_58 ( V_133 ) ;
return V_12 ;
}
int T_4 F_59 ( void )
{
int V_12 ;
V_92 = ( void * ) F_51 ( V_114 | V_115 ) ;
V_16 = ( void * ) F_51 ( V_114 | V_115 ) ;
if ( ! V_92 || ! V_16 ) {
V_12 = - V_116 ;
goto V_143;
}
V_12 = F_60 ( V_144 , F_36 ) ;
if ( V_12 )
goto V_143;
return V_12 ;
V_143:
F_52 ( ( unsigned long ) V_16 ) ;
F_52 ( ( unsigned long ) V_92 ) ;
return V_12 ;
}
void T_4 F_61 ( void )
{
F_62 ( V_144 ) ;
F_52 ( ( unsigned long ) V_16 ) ;
F_52 ( ( unsigned long ) V_92 ) ;
}
int F_63 ( int V_102 )
{
unsigned long V_80 ;
int V_12 ;
struct {
struct V_101 V_18 ;
T_1 V_145 : 4 ;
T_1 V_146 : 4 ;
T_1 V_147 ;
T_2 V_102 ;
T_3 V_148 ;
T_3 V_149 ;
T_3 V_150 [ 252 ] ;
struct V_101 V_1 ;
T_3 V_151 : 4 ;
T_3 V_152 : 4 ;
T_3 V_153 : 24 ;
} V_61 ( ( V_62 ) ) * V_154 ;
F_39 ( & V_15 , V_80 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_154 = V_16 ;
V_154 -> V_18 . V_19 = 0x0400 ;
V_154 -> V_18 . V_20 = 0x0031 ;
V_154 -> V_102 = V_102 ;
V_12 = F_4 ( V_154 ) ;
if ( V_12 > 0 ) {
V_12 = ( V_12 == 3 ) ? - V_25 : - V_26 ;
goto V_27;
}
switch ( V_154 -> V_1 . V_20 ) {
case 0x0101 :
V_12 = - V_3 ;
break;
default:
V_12 = F_1 ( V_154 -> V_1 . V_20 ) ;
}
if ( V_12 != 0 )
F_21 ( 2 , L_28 ,
V_102 , V_154 -> V_1 . V_20 ) ;
V_27:
F_40 ( & V_15 , V_80 ) ;
return V_12 ;
}
int T_4
F_64 ( void )
{
int V_155 ;
struct {
struct V_101 V_18 ;
T_3 V_145 ;
T_3 V_147 ;
T_3 V_148 ;
struct V_101 V_1 ;
T_3 V_149 ;
T_3 V_156 [ 510 ] ;
T_3 V_157 [ 508 ] ;
} V_61 ( ( V_62 ) ) * V_158 ;
F_3 ( & V_15 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_158 = V_16 ;
V_158 -> V_18 . V_19 = 0x0010 ;
V_158 -> V_18 . V_20 = 0x0010 ;
V_155 = F_4 ( V_158 ) ;
if ( V_155 ) {
V_155 = ( V_155 == 3 ) ? - V_25 : - V_26 ;
goto exit;
}
V_155 = F_1 ( V_158 -> V_1 . V_20 ) ;
if ( V_155 == 0 ) {
memcpy ( & V_123 , V_158 -> V_156 ,
sizeof( V_123 ) ) ;
memcpy ( & V_159 , V_158 -> V_157 ,
sizeof( V_159 ) ) ;
} else
F_21 ( 2 , L_29 ,
V_158 -> V_1 . V_20 ) ;
exit:
F_7 ( & V_15 ) ;
return V_155 ;
}
int F_65 ( void * V_120 , unsigned int V_79 , T_2 V_160 )
{
struct {
struct V_101 V_18 ;
unsigned int V_161 ;
unsigned int V_79 : 8 ;
unsigned int V_162 : 8 ;
unsigned int V_160 : 16 ;
unsigned int V_163 [ 5 ] ;
struct V_101 V_1 ;
unsigned int V_164 [ 7 ] ;
} V_61 ( ( V_62 ) ) * V_165 ;
int V_166 ;
memset ( V_120 , 0 , V_17 ) ;
V_165 = V_120 ;
V_165 -> V_18 . V_19 = 0x0020 ;
V_165 -> V_18 . V_20 = 0x0033 ;
V_165 -> V_79 = V_79 ;
V_165 -> V_160 = V_160 ;
V_166 = F_4 ( V_165 ) ;
if ( V_166 )
return - V_4 ;
V_166 = ( V_165 -> V_1 . V_20 == 0x0001 ) ? 0 : - V_4 ;
return V_166 ;
}
int F_66 ( void * V_120 , void * V_155 , T_5 V_167 )
{
struct {
struct V_101 V_18 ;
unsigned int V_161 [ 3 ] ;
struct V_101 V_1 ;
char V_39 [ V_167 ] ;
} V_61 ( ( V_62 ) ) * V_165 ;
int V_166 ;
memset ( V_120 , 0 , V_17 ) ;
V_165 = V_120 ;
V_165 -> V_18 . V_19 = 0x0010 ;
V_165 -> V_18 . V_20 = 0x0038 ;
V_166 = F_4 ( V_165 ) ;
if ( V_166 )
return - V_4 ;
memcpy ( V_155 , & V_165 -> V_39 , V_167 ) ;
return ( V_165 -> V_1 . V_20 == 0x0001 ) ? 0 : - V_4 ;
}
int F_67 ( struct V_5 V_6 )
{
struct {
struct V_101 V_18 ;
T_3 V_168 ;
struct V_5 V_169 ;
T_3 V_170 ;
struct V_101 V_1 ;
T_3 V_171 [ 11 ] ;
} V_61 ( ( V_62 ) ) * V_172 ;
unsigned long V_80 ;
int V_11 ;
int V_166 ;
F_39 ( & V_15 , V_80 ) ;
memset ( V_16 , 0 , V_17 ) ;
V_172 = V_16 ;
V_172 -> V_18 . V_19 = 0x0010 ;
V_172 -> V_18 . V_20 = 0x0046 ;
V_172 -> V_168 = 0x80000000 ;
V_172 -> V_169 = V_6 ;
V_11 = F_4 ( V_172 ) ;
if ( V_11 > 0 ) {
if ( V_11 == 3 )
V_166 = - V_25 ;
else
V_166 = - V_26 ;
F_5 ( 2 , L_30 ,
V_6 . V_21 , V_6 . V_23 , V_11 ) ;
goto V_27;
}
V_166 = F_1 ( V_172 -> V_1 . V_20 ) ;
if ( V_166 )
F_5 ( 2 , L_31 ,
V_6 . V_21 , V_6 . V_23 ,
V_172 -> V_1 . V_20 ) ;
else
F_5 ( 4 , L_32 ,
V_6 . V_21 , V_6 . V_23 ) ;
V_27:
F_40 ( & V_15 , V_80 ) ;
return V_166 ;
}
