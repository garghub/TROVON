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
static void F_36 ( struct V_64 * V_65 )
{
if ( V_65 -> V_81 & 0x40 ) {
F_21 ( 2 , L_20 ) ;
F_37 () ;
}
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
F_21 ( 4 , L_21 ,
V_65 -> V_82 ) ;
break;
}
}
static void F_38 ( struct V_83 * V_84 , struct V_83 * V_85 , int V_86 )
{
struct V_64 * V_65 ;
if ( V_86 ) {
F_37 () ;
return;
}
F_21 ( 2 , L_22
L_23 ,
V_84 -> V_87 , V_84 -> V_88 , V_84 -> V_89 , V_84 -> V_90 , V_84 -> V_91 ,
V_84 -> V_92 , V_84 -> V_67 ) ;
if ( ! V_93 )
return;
V_65 = V_93 ;
F_11 ( 2 , L_24 ) ;
do {
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
V_65 -> V_20 . V_21 = 0x0010 ;
V_65 -> V_20 . V_22 = 0x000e ;
if ( F_4 ( V_65 ) )
break;
if ( V_65 -> V_1 . V_22 == 0x0001 ) {
F_21 ( 4 , L_25 ) ;
F_36 ( V_65 ) ;
} else {
F_21 ( 2 , L_26 ,
V_65 -> V_1 . V_22 ) ;
break;
}
} while ( V_65 -> V_81 & 0x80 );
}
void F_39 ( struct V_47 V_35 )
{
char V_48 [ 15 ] ;
struct V_49 V_50 ;
sprintf ( V_48 , L_27 , V_35 . V_51 , V_35 . V_36 ) ;
F_11 ( 2 , V_48 ) ;
if ( F_12 ( V_35 ) != 0 ) {
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_35 = V_35 ;
F_13 () ;
F_14 ( F_17 , NULL ,
& V_50 ) ;
}
}
static void F_40 ( struct V_38 * V_39 ,
struct V_47 V_35 , int V_94 )
{
unsigned long V_81 ;
struct V_49 V_50 ;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 . V_35 = V_35 ;
F_41 ( V_39 -> V_41 , V_81 ) ;
if ( V_39 -> V_42 && V_39 -> V_42 -> V_43 )
V_39 -> V_42 -> V_43 ( V_39 , & V_50 ,
V_94 ? V_95 : V_96 ) ;
F_42 ( V_39 -> V_41 , V_81 ) ;
}
static int F_43 ( struct V_38 * V_39 , void * V_40 )
{
struct V_47 * V_35 = V_40 ;
F_40 ( V_39 , * V_35 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_38 * V_39 , void * V_40 )
{
struct V_47 * V_35 = V_40 ;
F_40 ( V_39 , * V_35 , 1 ) ;
return 0 ;
}
static int
F_45 ( struct V_7 V_8 , void * V_40 )
{
struct V_52 V_52 ;
if ( F_16 ( V_8 , & V_52 ) )
return - V_53 ;
F_9 ( V_8 ) ;
return 0 ;
}
int F_46 ( struct V_47 V_35 , int V_94 )
{
struct V_72 * V_73 = F_26 ( V_35 ) ;
F_13 () ;
if ( V_94 ) {
F_28 ( V_35 , & V_73 -> V_76 ) ;
F_14 ( F_44 ,
F_45 , & V_35 ) ;
} else
F_14 ( F_43 ,
NULL , & V_35 ) ;
return 0 ;
}
static void
F_47 ( struct V_97 * V_98 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 <= V_75 ; V_15 ++ ) {
if ( ! V_98 -> V_99 [ V_15 ] )
continue;
F_48 ( V_98 -> V_99 [ V_15 ] ) ;
}
}
static int
F_49 ( struct V_97 * V_98 )
{
int V_15 , V_14 ;
V_14 = 0 ;
for ( V_15 = 0 ; V_15 <= V_75 ; V_15 ++ ) {
if ( ! V_98 -> V_99 [ V_15 ] )
continue;
V_14 = F_50 ( V_98 -> V_99 [ V_15 ] ) ;
if ( V_14 )
goto V_100;
}
return V_14 ;
V_100:
for ( -- V_15 ; V_15 >= 0 ; V_15 -- ) {
if ( ! V_98 -> V_99 [ V_15 ] )
continue;
F_48 ( V_98 -> V_99 [ V_15 ] ) ;
}
return V_14 ;
}
int F_51 ( struct V_97 * V_98 , int V_101 )
{
struct {
struct V_102 V_20 ;
T_3 V_103 : 2 ;
T_3 : 30 ;
T_3 V_104 : 4 ;
T_3 : 28 ;
T_3 V_105 ;
T_3 V_106 ;
T_3 V_107 ;
T_3 V_108 ;
T_3 V_109 [ 13 ] ;
struct V_102 V_1 ;
T_3 V_69 : 8 ;
T_3 : 4 ;
T_3 V_110 : 4 ;
T_3 : 16 ;
} V_62 ( ( V_63 ) ) * V_111 ;
int V_14 , V_13 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_111 = V_18 ;
V_111 -> V_20 . V_21 = 0x0050 ;
V_111 -> V_20 . V_22 = 0x0016 ;
V_111 -> V_104 = V_112 >> 4 ;
V_111 -> V_106 = ( V_113 ) ( unsigned long ) V_98 -> V_106 ;
V_111 -> V_108 = ( V_113 ) ( unsigned long ) V_98 -> V_108 ;
V_111 -> V_103 = V_101 ? 0 : 1 ;
V_13 = F_4 ( V_111 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_111 -> V_1 . V_22 ) {
case 0x0102 :
case 0x0103 :
V_14 = - V_2 ;
break;
default:
V_14 = F_1 ( V_111 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_21 ( 2 , L_28 ,
V_111 -> V_1 . V_22 ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
int
F_52 ( struct V_97 * V_98 , int V_101 )
{
int V_14 ;
if ( V_101 && ! V_98 -> V_114 ) {
V_98 -> V_106 = ( void * ) F_53 ( V_115 | V_116 ) ;
V_98 -> V_108 = ( void * ) F_53 ( V_115 | V_116 ) ;
if ( ! V_98 -> V_106 || ! V_98 -> V_108 ) {
F_54 ( ( unsigned long ) V_98 -> V_106 ) ;
F_54 ( ( unsigned long ) V_98 -> V_108 ) ;
return - V_5 ;
}
}
V_14 = F_51 ( V_98 , V_101 ) ;
if ( ! V_14 ) {
V_98 -> V_114 = V_101 ;
if ( V_98 -> V_114 ) {
V_14 = F_49 ( V_98 ) ;
if ( V_14 ) {
F_51 ( V_98 , 0 ) ;
V_98 -> V_114 = 0 ;
}
} else
F_47 ( V_98 ) ;
}
if ( ! V_98 -> V_114 ) {
F_54 ( ( unsigned long ) V_98 -> V_106 ) ;
F_54 ( ( unsigned long ) V_98 -> V_108 ) ;
}
return V_14 ;
}
int F_55 ( struct V_47 V_35 , int V_110 , int V_117 ,
int V_118 , int V_119 , void * V_120 )
{
struct V_121 * V_122 ;
int V_13 , V_14 ;
if ( ( V_117 == 1 ) && ! V_123 . V_124 )
return - V_2 ;
if ( ( V_117 == 2 ) && ! V_123 . V_125 )
return - V_2 ;
memset ( V_120 , 0 , V_19 ) ;
V_122 = V_120 ;
V_122 -> V_20 . V_21 = 0x0010 ;
V_122 -> V_20 . V_22 = 0x0002 ;
V_122 -> V_51 = V_35 . V_51 ;
V_122 -> V_126 = V_35 . V_36 ;
V_122 -> V_127 = V_35 . V_36 ;
V_122 -> V_119 = V_119 ;
V_122 -> V_118 = V_118 ;
V_122 -> V_110 = V_110 ;
V_122 -> V_117 = V_117 ;
V_13 = F_4 ( V_122 ) ;
if ( V_13 > 0 )
return ( V_13 == 3 ) ? - V_27 : - V_4 ;
V_14 = F_1 ( V_122 -> V_1 . V_22 ) ;
if ( V_14 )
F_21 ( 2 , L_29 ,
V_122 -> V_1 . V_22 ) ;
return V_14 ;
}
int F_28 ( struct V_47 V_35 ,
struct V_128 * V_76 )
{
struct V_129 * V_130 ;
struct V_121 * V_122 ;
unsigned long V_81 ;
int V_14 ;
F_41 ( & V_17 , V_81 ) ;
V_122 = V_18 ;
V_14 = F_55 ( V_35 , 0 , 0 , 0 , 0 , V_122 ) ;
if ( V_14 )
goto V_28;
V_130 = ( void * ) & V_122 -> V_1 ;
memcpy ( V_76 , & V_130 -> V_40 , sizeof( * V_76 ) ) ;
V_28:
F_42 ( & V_17 , V_81 ) ;
return V_14 ;
}
int F_56 ( struct V_47 V_35 ,
struct V_131 * V_76 )
{
struct V_129 * V_130 ;
struct V_121 * V_122 ;
int V_14 ;
F_3 ( & V_17 ) ;
V_122 = V_18 ;
V_14 = F_55 ( V_35 , 0 , 0 , 1 , 0 , V_122 ) ;
if ( V_14 )
goto V_28;
V_130 = ( void * ) & V_122 -> V_1 ;
memcpy ( V_76 , & V_130 -> V_40 , sizeof( * V_76 ) ) ;
V_28:
F_7 ( & V_17 ) ;
return V_14 ;
}
static void
F_57 ( struct V_72 * V_73 , T_1 V_132 ,
struct V_133 * V_134 )
{
struct V_133 * V_133 ;
int V_15 , V_16 ;
V_133 = V_73 -> V_133 ;
for ( V_15 = 0 ; V_15 < V_135 ; V_15 ++ ) {
V_16 = 0x80 >> ( V_15 + 3 ) ;
if ( V_132 & V_16 )
V_133 -> V_136 [ V_15 ] = V_134 -> V_136 [ V_15 ] ;
else
V_133 -> V_136 [ V_15 ] = 0 ;
}
}
int F_58 ( struct V_72 * V_73 )
{
struct V_133 * V_133 ;
int V_13 , V_14 ;
struct {
struct V_102 V_20 ;
T_3 : 24 ;
T_3 V_126 : 8 ;
T_3 : 24 ;
T_3 V_127 : 8 ;
T_3 V_105 ;
struct V_102 V_1 ;
T_3 V_107 ;
T_3 V_137 : 1 ;
T_3 V_138 : 1 ;
T_3 : 22 ;
T_3 V_35 : 8 ;
T_3 V_132 : 5 ;
T_3 : 11 ;
T_3 V_139 : 8 ;
T_3 V_140 : 8 ;
T_3 V_141 ;
T_3 V_40 [ V_135 ] ;
} V_62 ( ( V_63 ) ) * V_142 ;
V_73 -> V_133 = NULL ;
V_133 = F_59 ( sizeof( * V_133 ) , V_115 ) ;
if ( ! V_133 )
return - V_5 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_142 = V_18 ;
V_142 -> V_20 . V_21 = 0x0010 ;
V_142 -> V_20 . V_22 = 0x0022 ;
V_142 -> V_126 = V_73 -> V_35 . V_36 ;
V_142 -> V_127 = V_73 -> V_35 . V_36 ;
V_13 = F_4 ( V_142 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_142 -> V_1 . V_22 ) ;
if ( V_14 ) {
F_21 ( 2 , L_30 ,
V_142 -> V_1 . V_22 ) ;
goto V_28;
}
if ( V_142 -> V_137 ) {
V_73 -> V_140 = - 1 ;
V_73 -> V_138 = - 1 ;
goto V_28;
}
V_73 -> V_140 = V_142 -> V_140 ;
V_73 -> V_138 = V_142 -> V_138 ;
if ( V_73 -> V_140 != 2 && V_73 -> V_140 != 3 ) {
goto V_28;
}
V_73 -> V_133 = V_133 ;
F_57 ( V_73 , V_142 -> V_132 ,
(struct V_133 * ) & V_142 -> V_40 ) ;
V_28:
F_7 ( & V_17 ) ;
if ( ! V_73 -> V_133 )
F_60 ( V_133 ) ;
return V_14 ;
}
int T_4 F_61 ( void )
{
int V_14 ;
V_93 = ( void * ) F_53 ( V_115 | V_116 ) ;
V_18 = ( void * ) F_53 ( V_115 | V_116 ) ;
if ( ! V_93 || ! V_18 ) {
V_14 = - V_5 ;
goto V_143;
}
V_14 = F_62 ( V_144 , F_38 ) ;
if ( V_14 )
goto V_143;
return V_14 ;
V_143:
F_54 ( ( unsigned long ) V_18 ) ;
F_54 ( ( unsigned long ) V_93 ) ;
return V_14 ;
}
void T_4 F_63 ( void )
{
F_64 ( V_144 ) ;
F_54 ( ( unsigned long ) V_18 ) ;
F_54 ( ( unsigned long ) V_93 ) ;
}
int F_65 ( int V_103 )
{
unsigned long V_81 ;
int V_14 ;
struct {
struct V_102 V_20 ;
T_1 V_145 : 4 ;
T_1 V_146 : 4 ;
T_1 V_147 ;
T_2 V_103 ;
T_3 V_148 ;
T_3 V_149 ;
T_3 V_150 [ 252 ] ;
struct V_102 V_1 ;
T_3 V_151 : 4 ;
T_3 V_152 : 4 ;
T_3 V_153 : 24 ;
} V_62 ( ( V_63 ) ) * V_154 ;
F_41 ( & V_17 , V_81 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_154 = V_18 ;
V_154 -> V_20 . V_21 = 0x0400 ;
V_154 -> V_20 . V_22 = 0x0031 ;
V_154 -> V_103 = V_103 ;
V_14 = F_4 ( V_154 ) ;
if ( V_14 > 0 ) {
V_14 = ( V_14 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
switch ( V_154 -> V_1 . V_22 ) {
case 0x0101 :
V_14 = - V_3 ;
break;
default:
V_14 = F_1 ( V_154 -> V_1 . V_22 ) ;
}
if ( V_14 != 0 )
F_21 ( 2 , L_31 ,
V_103 , V_154 -> V_1 . V_22 ) ;
V_28:
F_42 ( & V_17 , V_81 ) ;
return V_14 ;
}
int T_4
F_66 ( void )
{
int V_155 ;
struct {
struct V_102 V_20 ;
T_3 V_145 ;
T_3 V_147 ;
T_3 V_148 ;
struct V_102 V_1 ;
T_3 V_149 ;
T_3 V_156 [ 510 ] ;
T_3 V_157 [ 508 ] ;
} V_62 ( ( V_63 ) ) * V_158 ;
F_3 ( & V_17 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_158 = V_18 ;
V_158 -> V_20 . V_21 = 0x0010 ;
V_158 -> V_20 . V_22 = 0x0010 ;
V_155 = F_4 ( V_158 ) ;
if ( V_155 ) {
V_155 = ( V_155 == 3 ) ? - V_27 : - V_4 ;
goto exit;
}
V_155 = F_1 ( V_158 -> V_1 . V_22 ) ;
if ( V_155 == 0 ) {
memcpy ( & V_123 , V_158 -> V_156 ,
sizeof( V_123 ) ) ;
memcpy ( & V_159 , V_158 -> V_157 ,
sizeof( V_159 ) ) ;
} else
F_21 ( 2 , L_32 ,
V_158 -> V_1 . V_22 ) ;
exit:
F_7 ( & V_17 ) ;
return V_155 ;
}
int F_67 ( void * V_120 , unsigned int V_80 , T_2 V_160 )
{
struct {
struct V_102 V_20 ;
unsigned int V_161 ;
unsigned int V_80 : 8 ;
unsigned int V_162 : 8 ;
unsigned int V_160 : 16 ;
unsigned int V_163 [ 5 ] ;
struct V_102 V_1 ;
unsigned int V_164 [ 7 ] ;
} V_62 ( ( V_63 ) ) * V_165 ;
int V_166 ;
memset ( V_120 , 0 , V_19 ) ;
V_165 = V_120 ;
V_165 -> V_20 . V_21 = 0x0020 ;
V_165 -> V_20 . V_22 = 0x0033 ;
V_165 -> V_80 = V_80 ;
V_165 -> V_160 = V_160 ;
V_166 = F_4 ( V_165 ) ;
if ( V_166 )
return - V_6 ;
V_166 = ( V_165 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
return V_166 ;
}
int F_68 ( void * V_120 , void * V_155 , T_5 V_167 )
{
struct {
struct V_102 V_20 ;
unsigned int V_161 [ 3 ] ;
struct V_102 V_1 ;
char V_40 [ V_167 ] ;
} V_62 ( ( V_63 ) ) * V_165 ;
int V_166 ;
memset ( V_120 , 0 , V_19 ) ;
V_165 = V_120 ;
V_165 -> V_20 . V_21 = 0x0010 ;
V_165 -> V_20 . V_22 = 0x0038 ;
V_166 = F_4 ( V_165 ) ;
if ( V_166 )
return - V_6 ;
memcpy ( V_155 , & V_165 -> V_40 , V_167 ) ;
return ( V_165 -> V_1 . V_22 == 0x0001 ) ? 0 : - V_6 ;
}
int F_69 ( struct V_7 V_8 )
{
struct {
struct V_102 V_20 ;
T_3 V_168 ;
struct V_7 V_169 ;
T_3 V_170 ;
struct V_102 V_1 ;
T_3 V_171 [ 11 ] ;
} V_62 ( ( V_63 ) ) * V_172 ;
unsigned long V_81 ;
int V_13 ;
int V_166 ;
F_41 ( & V_17 , V_81 ) ;
memset ( V_18 , 0 , V_19 ) ;
V_172 = V_18 ;
V_172 -> V_20 . V_21 = 0x0010 ;
V_172 -> V_20 . V_22 = 0x0046 ;
V_172 -> V_168 = 0x80000000 ;
V_172 -> V_169 = V_8 ;
V_13 = F_4 ( V_172 ) ;
if ( V_13 > 0 ) {
if ( V_13 == 3 )
V_166 = - V_27 ;
else
V_166 = - V_4 ;
F_5 ( 2 , L_33 ,
V_8 . V_23 , V_8 . V_25 , V_13 ) ;
goto V_28;
}
V_166 = F_1 ( V_172 -> V_1 . V_22 ) ;
if ( V_166 )
F_5 ( 2 , L_34 ,
V_8 . V_23 , V_8 . V_25 ,
V_172 -> V_1 . V_22 ) ;
else
F_5 ( 4 , L_35 ,
V_8 . V_23 , V_8 . V_25 ) ;
V_28:
F_42 ( & V_17 , V_81 ) ;
return V_166 ;
}
int F_70 ( struct F_70 * V_173 , V_113 V_174 )
{
int V_13 , V_14 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_20 . V_21 = 0x0020 ;
V_173 -> V_20 . V_22 = 0x004C ;
V_173 -> V_175 = V_174 ;
V_13 = F_4 ( V_173 ) ;
if ( V_13 > 0 ) {
V_14 = ( V_13 == 3 ) ? - V_27 : - V_4 ;
goto V_28;
}
V_14 = F_1 ( V_173 -> V_1 . V_22 ) ;
if ( V_14 != 0 )
F_5 ( 2 , L_36 ,
V_173 -> V_1 . V_22 ) ;
V_28:
return V_14 ;
}
