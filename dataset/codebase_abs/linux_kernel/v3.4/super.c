static void F_1 ( struct V_1 * V_2 , unsigned * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_4 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_9 * V_11 ;
if ( V_5 != V_7 )
V_10 = V_11 = (struct V_9 * ) V_5 -> V_12 ;
else {
V_10 = (struct V_9 * ) V_5 -> V_12 ;
V_11 = (struct V_9 * ) ( V_7 -> V_12 - 512 ) ;
}
* V_3 = V_13 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = ( char * ) V_10 ;
V_2 -> V_19 = ( char * ) V_11 ;
V_2 -> V_20 = & V_10 -> V_21 ;
V_2 -> V_22 = & V_10 -> V_23 [ 0 ] ;
V_2 -> V_24 = & V_11 -> V_25 ;
V_2 -> V_26 = & V_10 -> V_27 ;
V_2 -> V_28 = & V_10 -> V_29 [ 0 ] ;
V_2 -> V_30 = & V_11 -> V_31 ;
V_2 -> V_32 = & V_11 -> V_33 ;
V_2 -> V_34 = F_2 ( V_2 , V_10 -> V_35 ) ;
V_2 -> V_36 = F_3 ( V_2 , V_10 -> V_37 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned * V_3 )
{
struct V_38 * V_39 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_4 * V_7 = V_2 -> V_8 ;
if ( V_5 == V_7 )
V_39 = (struct V_38 * ) ( V_5 -> V_12 + V_40 / 2 ) ;
else
V_39 = (struct V_38 * ) V_7 -> V_12 ;
* V_3 = V_41 ;
V_2 -> V_14 = V_42 ;
V_2 -> V_16 = V_43 ;
V_2 -> V_18 = ( char * ) V_39 ;
V_2 -> V_19 = ( char * ) V_39 ;
V_2 -> V_20 = & V_39 -> V_21 ;
V_2 -> V_22 = & V_39 -> V_23 [ 0 ] ;
V_2 -> V_24 = & V_39 -> V_25 ;
V_2 -> V_26 = & V_39 -> V_27 ;
V_2 -> V_28 = & V_39 -> V_29 [ 0 ] ;
V_2 -> V_30 = & V_39 -> V_31 ;
V_2 -> V_32 = & V_39 -> V_33 ;
V_2 -> V_44 = & V_39 -> V_45 ;
V_2 -> V_34 = F_2 ( V_2 , V_39 -> V_35 ) ;
V_2 -> V_36 = F_3 ( V_2 , V_39 -> V_37 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned * V_3 )
{
struct V_46 * V_39 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_4 * V_7 = V_2 -> V_8 ;
if ( V_5 == V_7 )
V_39 = (struct V_46 * ) ( V_5 -> V_12 + V_40 / 2 ) ;
else
V_39 = (struct V_46 * ) V_7 -> V_12 ;
* V_3 = V_41 ;
V_2 -> V_14 = V_42 ;
V_2 -> V_16 = V_43 ;
V_2 -> V_18 = ( char * ) V_39 ;
V_2 -> V_19 = ( char * ) V_39 ;
V_2 -> V_20 = & V_39 -> V_21 ;
V_2 -> V_22 = & V_39 -> V_23 [ 0 ] ;
V_2 -> V_24 = & V_39 -> V_25 ;
V_2 -> V_26 = & V_39 -> V_27 ;
V_2 -> V_28 = & V_39 -> V_29 [ 0 ] ;
V_2 -> V_30 = & V_39 -> V_31 ;
V_2 -> V_32 = & V_39 -> V_33 ;
V_2 -> V_44 = & V_39 -> V_45 ;
V_2 -> V_34 = F_2 ( V_2 , V_39 -> V_35 ) ;
V_2 -> V_36 = F_3 ( V_2 , V_39 -> V_37 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned * V_3 )
{
struct V_47 * V_39 ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_39 = (struct V_47 * ) V_5 -> V_12 ;
* V_3 = V_48 ;
V_2 -> V_14 = V_49 ;
V_2 -> V_16 = V_50 ;
V_2 -> V_18 = ( char * ) V_39 ;
V_2 -> V_19 = ( char * ) V_39 ;
V_2 -> V_20 = & V_39 -> V_21 ;
V_2 -> V_22 = & V_39 -> V_23 [ 0 ] ;
V_2 -> V_24 = & V_39 -> V_25 ;
V_2 -> V_26 = & V_39 -> V_27 ;
V_2 -> V_28 = & V_39 -> V_29 [ 0 ] ;
V_2 -> V_30 = & V_39 -> V_31 ;
V_2 -> V_32 = & V_39 -> V_33 ;
V_2 -> V_34 = F_2 ( V_2 , V_39 -> V_35 ) ;
V_2 -> V_36 = F_3 ( V_2 , V_39 -> V_37 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned * V_3 )
{
struct V_4 * V_7 = V_2 -> V_8 ;
struct V_51 * V_39 = (struct V_51 * ) V_7 -> V_12 ;
* V_3 = V_52 ;
V_2 -> V_14 = V_53 ;
V_2 -> V_16 = V_54 ;
V_2 -> V_18 = ( char * ) V_39 ;
V_2 -> V_19 = ( char * ) V_39 ;
V_2 -> V_20 = & V_39 -> V_21 ;
V_2 -> V_22 = & V_39 -> V_23 [ 0 ] ;
V_2 -> V_24 = & V_39 -> V_25 ;
V_2 -> V_26 = & V_39 -> V_27 ;
V_2 -> V_28 = & V_39 -> V_29 [ 0 ] ;
V_2 -> V_30 = & V_39 -> V_31 ;
V_2 -> V_32 = & V_39 -> V_33 ;
V_2 -> V_34 = F_2 ( V_2 , V_39 -> V_35 ) ;
V_2 -> V_36 = F_3 ( V_2 , V_39 -> V_37 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_4 * V_55 )
{
struct V_9 * V_39 = (struct V_9 * ) V_55 -> V_12 ;
if ( * ( V_56 * ) & V_39 -> V_57 == F_9 ( 0x2b5544 ) )
V_2 -> V_58 = V_59 ;
else if ( * ( V_60 * ) & V_39 -> V_57 == F_10 ( 0x2b5544 ) )
V_2 -> V_58 = V_61 ;
else
return 0 ;
switch ( F_3 ( V_2 , V_39 -> V_62 ) ) {
case 1 :
V_2 -> V_62 = V_63 ;
return 1 ;
case 2 :
V_2 -> V_62 = V_63 ;
return 2 ;
default:
return 0 ;
}
}
static int F_11 ( struct V_1 * V_2 , struct V_4 * V_55 )
{
struct V_64 * V_65 = V_2 -> V_66 ;
struct V_38 * V_39 ;
T_1 type ;
V_39 = (struct V_38 * ) ( V_55 -> V_12 + V_40 / 2 ) ;
if ( * ( V_56 * ) & V_39 -> V_57 == F_9 ( 0xfd187e20 ) )
V_2 -> V_58 = V_59 ;
else if ( * ( V_60 * ) & V_39 -> V_57 == F_10 ( 0xfd187e20 ) )
V_2 -> V_58 = V_61 ;
else
return 0 ;
type = F_3 ( V_2 , V_39 -> V_62 ) ;
if ( F_2 ( V_2 , V_39 -> V_27 ) == 0xffff ) {
V_2 -> V_62 = V_67 ;
V_2 -> V_68 = 1 ;
if ( ! ( V_65 -> V_69 & V_70 ) ) {
F_12 ( L_1
L_2 ,
V_65 -> V_71 ) ;
}
return type ;
}
if ( F_3 ( V_2 , V_39 -> V_33 ) < V_72 ) {
if ( type > 3 || type < 1 )
return 0 ;
V_2 -> V_62 = V_73 ;
return type ;
}
if ( ( type > 3 || type < 1 ) && ( type > 0x30 || type < 0x10 ) )
return 0 ;
if ( type >= 0x10 ) {
F_12 ( L_3
L_2 , V_65 -> V_71 ) ;
V_2 -> V_68 = 1 ;
}
V_2 -> V_62 = V_74 ;
return type >= 0x10 ? type >> 4 : type ;
}
static int F_13 ( struct V_1 * V_2 , struct V_4 * V_55 )
{
struct V_47 * V_39 ;
V_39 = (struct V_47 * ) ( V_55 -> V_12 + V_40 / 2 ) ;
if ( ( memcmp ( V_39 -> V_75 , L_4 , 6 ) && memcmp ( V_39 -> V_75 , L_5 , 6 ) )
|| ( memcmp ( V_39 -> V_76 , L_6 , 6 ) && memcmp ( V_39 -> V_76 , L_7 , 6 ) ) )
return 0 ;
V_2 -> V_58 = V_77 ;
V_2 -> V_62 = V_78 ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_4 * V_55 )
{
int V_79 = F_11 ( V_2 , V_55 ) ;
return V_79 > 2 ? 0 : V_79 ;
}
static int F_15 ( struct V_64 * V_65 , int V_80 , int V_79 )
{
struct V_1 * V_2 = F_16 ( V_65 ) ;
struct V_81 * V_82 ;
char * V_83 = V_84 [ V_2 -> V_62 ] ;
T_2 V_85 = V_79 + 8 ;
int V_86 = 1 << V_85 ;
int V_87 = V_86 >> 2 ;
V_2 -> V_88 = 2 ;
V_89 [ V_2 -> V_62 ] ( V_2 , & V_65 -> V_90 ) ;
V_2 -> V_91 = 1 ;
V_2 -> V_92 = V_2 -> V_36 - V_2 -> V_34 ;
V_2 -> V_93 = V_86 >> 6 ;
V_2 -> V_94 = ( V_86 >> 6 ) - 1 ;
V_2 -> V_95 = V_85 - 6 ;
V_2 -> V_96 = V_87 ;
V_2 -> V_97 = V_87 * V_87 ;
V_2 -> V_98 = 10 + V_87 * ( 1 + V_87 * ( 1 + V_87 ) ) ;
V_2 -> V_99 = V_85 - 2 ;
V_2 -> V_100 = ( V_2 -> V_34 - V_2 -> V_88 )
<< V_2 -> V_95 ;
if ( ! V_80 )
F_12 ( L_8 ,
V_83 , V_65 -> V_101 , V_65 -> V_71 ) ;
V_65 -> V_57 = V_102 + V_2 -> V_62 ;
V_65 -> V_103 = & V_104 ;
if ( V_2 -> V_68 )
V_65 -> V_69 |= V_70 ;
if ( V_2 -> V_91 )
V_65 -> V_105 = & V_106 ;
V_82 = F_17 ( V_65 , V_107 ) ;
if ( F_18 ( V_82 ) ) {
F_12 ( L_9 ) ;
return 0 ;
}
V_65 -> V_108 = F_19 ( V_82 ) ;
if ( ! V_65 -> V_108 ) {
F_12 ( L_10 ) ;
return 0 ;
}
return 1 ;
}
static int F_20 ( struct V_64 * V_65 , void * V_109 , int V_80 )
{
struct V_4 * V_5 , * V_55 = NULL ;
struct V_1 * V_2 ;
unsigned long V_110 ;
int V_79 = 0 , V_111 ;
F_21 ( 1024 != sizeof ( struct V_9 ) ) ;
F_21 ( 512 != sizeof ( struct V_38 ) ) ;
F_21 ( 512 != sizeof ( struct V_46 ) ) ;
F_21 ( 500 != sizeof ( struct V_47 ) ) ;
F_21 ( 64 != sizeof ( struct V_112 ) ) ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_115 = 0 ;
V_65 -> V_116 = V_2 ;
F_23 ( V_65 , V_40 ) ;
for ( V_111 = 0 ; V_111 < F_24 ( V_117 ) && ! V_79 ; V_111 ++ ) {
F_25 ( V_55 ) ;
V_55 = F_26 ( V_65 , V_117 [ V_111 ] . V_118 ) ;
if ( ! V_55 )
continue;
V_79 = V_117 [ V_111 ] . F_27 ( F_16 ( V_65 ) , V_55 ) ;
}
if ( ! V_79 )
goto V_119;
switch ( V_79 ) {
case 1 :
V_110 = V_55 -> V_120 << 1 ;
F_25 ( V_55 ) ;
F_23 ( V_65 , 512 ) ;
V_5 = F_26 ( V_65 , V_110 ) ;
V_55 = F_26 ( V_65 , V_110 + 1 ) ;
break;
case 2 :
V_5 = V_55 ;
break;
case 3 :
V_110 = V_55 -> V_120 >> 1 ;
F_25 ( V_55 ) ;
F_23 ( V_65 , 2048 ) ;
V_5 = V_55 = F_26 ( V_65 , V_110 ) ;
break;
default:
goto V_121;
}
if ( V_55 && V_5 ) {
V_2 -> V_6 = V_5 ;
V_2 -> V_8 = V_55 ;
if ( F_15 ( V_65 , V_80 , V_79 ) )
return 0 ;
}
F_25 ( V_5 ) ;
F_25 ( V_55 ) ;
F_23 ( V_65 , V_40 ) ;
F_12 ( L_11 ) ;
V_122:
F_28 ( V_2 ) ;
return - V_123 ;
V_119:
F_25 ( V_55 ) ;
if ( ! V_80 )
F_12 ( L_12 ,
V_65 -> V_71 ) ;
goto V_122;
V_121:
F_25 ( V_55 ) ;
if ( ! V_80 )
F_12 ( L_13 ,
1 << ( V_79 - 2 ) ) ;
goto V_122;
}
static int F_29 ( struct V_64 * V_65 , struct V_4 * V_55 )
{
struct V_51 * V_124 ;
struct V_112 * V_125 ;
struct V_4 * V_7 ;
struct V_1 * V_2 ;
V_2 = V_65 -> V_116 ;
V_124 = (struct V_51 * ) V_55 -> V_12 ;
if ( F_2 ( V_2 , V_124 -> V_27 ) > V_54 ||
F_2 ( V_2 , V_124 -> V_21 ) > V_53 ||
F_3 ( V_2 , V_124 -> V_37 ) > V_126 )
return 0 ;
V_7 = F_26 ( V_65 , 2 ) ;
if ( V_7 == NULL )
return 0 ;
V_125 = (struct V_112 * ) ( V_7 -> V_12 + 64 ) ;
if ( ( F_2 ( V_2 , V_125 -> V_127 ) & ~ 0777 ) != V_128 ||
( F_3 ( V_2 , V_125 -> V_129 ) == 0 ) ||
( F_3 ( V_2 , V_125 -> V_129 ) & 017 ) ||
( F_3 ( V_2 , V_125 -> V_129 ) > V_130 *
sizeof( struct V_131 ) ) ) {
F_25 ( V_7 ) ;
return 0 ;
}
F_25 ( V_7 ) ;
return 1 ;
}
static int F_30 ( struct V_64 * V_65 , void * V_109 , int V_80 )
{
struct V_1 * V_2 ;
struct V_4 * V_55 ;
if ( 440 != sizeof ( struct V_51 ) )
F_31 ( L_14 ) ;
if ( 64 != sizeof ( struct V_112 ) )
F_31 ( L_15 ) ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_115 = 0 ;
V_2 -> V_62 = V_132 ;
V_65 -> V_116 = V_2 ;
F_23 ( V_65 , 512 ) ;
if ( ( V_55 = F_26 ( V_65 , 1 ) ) == NULL ) {
if ( ! V_80 )
F_12 ( L_16
L_17 , V_65 -> V_71 ) ;
goto V_122;
}
V_2 -> V_58 = V_77 ;
if ( F_29 ( V_65 , V_55 ) )
goto V_133;
V_2 -> V_58 = V_59 ;
if ( F_29 ( V_65 , V_55 ) )
goto V_133;
goto V_122;
V_133:
V_2 -> V_6 = V_55 ;
V_2 -> V_8 = V_55 ;
if ( F_15 ( V_65 , V_80 , 1 ) )
return 0 ;
V_122:
F_12 ( V_134 L_18 ,
V_65 -> V_71 ) ;
F_25 ( V_55 ) ;
F_28 ( V_2 ) ;
return - V_123 ;
}
static struct V_135 * F_32 ( struct V_136 * V_137 ,
int V_138 , const char * V_139 , void * V_109 )
{
return F_33 ( V_137 , V_138 , V_139 , V_109 , F_20 ) ;
}
static struct V_135 * F_34 ( struct V_136 * V_137 ,
int V_138 , const char * V_139 , void * V_109 )
{
return F_33 ( V_137 , V_138 , V_139 , V_109 , F_30 ) ;
}
static int T_3 F_35 ( void )
{
int error ;
error = F_36 () ;
if ( error )
goto V_140;
error = F_37 ( & V_141 ) ;
if ( error )
goto V_142;
error = F_37 ( & V_143 ) ;
if ( error )
goto V_144;
return 0 ;
V_144:
F_38 ( & V_141 ) ;
V_142:
F_39 () ;
V_140:
return error ;
}
static void T_4 F_40 ( void )
{
F_38 ( & V_141 ) ;
F_38 ( & V_143 ) ;
F_39 () ;
}
