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
if ( ! F_12 ( V_65 ) ) {
F_13 ( L_1
L_2 ,
V_65 -> V_69 ) ;
}
return type ;
}
if ( F_3 ( V_2 , V_39 -> V_33 ) < V_70 ) {
if ( type > 3 || type < 1 )
return 0 ;
V_2 -> V_62 = V_71 ;
return type ;
}
if ( ( type > 3 || type < 1 ) && ( type > 0x30 || type < 0x10 ) )
return 0 ;
if ( type >= 0x10 ) {
F_13 ( L_3
L_2 , V_65 -> V_69 ) ;
V_2 -> V_68 = 1 ;
}
V_2 -> V_62 = V_72 ;
return type >= 0x10 ? type >> 4 : type ;
}
static int F_14 ( struct V_1 * V_2 , struct V_4 * V_55 )
{
struct V_47 * V_39 ;
V_39 = (struct V_47 * ) ( V_55 -> V_12 + V_40 / 2 ) ;
if ( ( memcmp ( V_39 -> V_73 , L_4 , 6 ) && memcmp ( V_39 -> V_73 , L_5 , 6 ) )
|| ( memcmp ( V_39 -> V_74 , L_6 , 6 ) && memcmp ( V_39 -> V_74 , L_7 , 6 ) ) )
return 0 ;
V_2 -> V_58 = V_75 ;
V_2 -> V_62 = V_76 ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_4 * V_55 )
{
int V_77 = F_11 ( V_2 , V_55 ) ;
return V_77 > 2 ? 0 : V_77 ;
}
static int F_16 ( struct V_64 * V_65 , int V_78 , int V_77 )
{
struct V_1 * V_2 = F_17 ( V_65 ) ;
struct V_79 * V_80 ;
char * V_81 = V_82 [ V_2 -> V_62 ] ;
T_2 V_83 = V_77 + 8 ;
int V_84 = 1 << V_83 ;
int V_85 = V_84 >> 2 ;
V_2 -> V_86 = 2 ;
V_87 [ V_2 -> V_62 ] ( V_2 , & V_65 -> V_88 ) ;
V_2 -> V_89 = 1 ;
V_2 -> V_90 = V_2 -> V_36 - V_2 -> V_34 ;
V_2 -> V_91 = V_84 >> 6 ;
V_2 -> V_92 = ( V_84 >> 6 ) - 1 ;
V_2 -> V_93 = V_83 - 6 ;
V_2 -> V_94 = V_85 ;
V_2 -> V_95 = V_85 * V_85 ;
V_2 -> V_96 = 10 + V_85 * ( 1 + V_85 * ( 1 + V_85 ) ) ;
V_2 -> V_97 = V_83 - 2 ;
V_2 -> V_98 = ( V_2 -> V_34 - V_2 -> V_86 )
<< V_2 -> V_93 ;
if ( ! V_78 )
F_13 ( L_8 ,
V_81 , V_65 -> V_99 , V_65 -> V_69 ) ;
V_65 -> V_57 = V_100 + V_2 -> V_62 ;
V_65 -> V_101 = & V_102 ;
if ( V_2 -> V_68 )
V_65 -> V_103 |= V_104 ;
if ( V_2 -> V_89 )
V_65 -> V_105 = & V_106 ;
V_80 = F_18 ( V_65 , V_107 ) ;
if ( F_19 ( V_80 ) ) {
F_13 ( L_9 ) ;
return 0 ;
}
V_65 -> V_108 = F_20 ( V_80 ) ;
if ( ! V_65 -> V_108 ) {
F_13 ( L_10 ) ;
return 0 ;
}
return 1 ;
}
static int F_21 ( struct V_64 * V_65 , void * V_109 , int V_78 )
{
struct V_4 * V_5 , * V_55 = NULL ;
struct V_1 * V_2 ;
unsigned long V_110 ;
int V_77 = 0 , V_111 ;
F_22 ( 1024 != sizeof ( struct V_9 ) ) ;
F_22 ( 512 != sizeof ( struct V_38 ) ) ;
F_22 ( 512 != sizeof ( struct V_46 ) ) ;
F_22 ( 500 != sizeof ( struct V_47 ) ) ;
F_22 ( 64 != sizeof ( struct V_112 ) ) ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_115 = 0 ;
F_24 ( & V_2 -> V_116 ) ;
V_65 -> V_117 = V_2 ;
F_25 ( V_65 , V_40 ) ;
for ( V_111 = 0 ; V_111 < F_26 ( V_118 ) && ! V_77 ; V_111 ++ ) {
F_27 ( V_55 ) ;
V_55 = F_28 ( V_65 , V_118 [ V_111 ] . V_119 ) ;
if ( ! V_55 )
continue;
V_77 = V_118 [ V_111 ] . F_29 ( F_17 ( V_65 ) , V_55 ) ;
}
if ( ! V_77 )
goto V_120;
switch ( V_77 ) {
case 1 :
V_110 = V_55 -> V_121 << 1 ;
F_27 ( V_55 ) ;
F_25 ( V_65 , 512 ) ;
V_5 = F_28 ( V_65 , V_110 ) ;
V_55 = F_28 ( V_65 , V_110 + 1 ) ;
break;
case 2 :
V_5 = V_55 ;
break;
case 3 :
V_110 = V_55 -> V_121 >> 1 ;
F_27 ( V_55 ) ;
F_25 ( V_65 , 2048 ) ;
V_5 = V_55 = F_28 ( V_65 , V_110 ) ;
break;
default:
goto V_122;
}
if ( V_55 && V_5 ) {
V_2 -> V_6 = V_5 ;
V_2 -> V_8 = V_55 ;
if ( F_16 ( V_65 , V_78 , V_77 ) )
return 0 ;
}
F_27 ( V_5 ) ;
F_27 ( V_55 ) ;
F_25 ( V_65 , V_40 ) ;
F_13 ( L_11 ) ;
V_123:
F_30 ( V_2 ) ;
return - V_124 ;
V_120:
F_27 ( V_55 ) ;
if ( ! V_78 )
F_13 ( L_12 ,
V_65 -> V_69 ) ;
goto V_123;
V_122:
F_27 ( V_55 ) ;
if ( ! V_78 )
F_13 ( L_13 ,
1 << ( V_77 - 2 ) ) ;
goto V_123;
}
static int F_31 ( struct V_64 * V_65 , struct V_4 * V_55 )
{
struct V_51 * V_125 ;
struct V_112 * V_126 ;
struct V_4 * V_7 ;
struct V_1 * V_2 ;
V_2 = V_65 -> V_117 ;
V_125 = (struct V_51 * ) V_55 -> V_12 ;
if ( F_2 ( V_2 , V_125 -> V_27 ) > V_54 ||
F_2 ( V_2 , V_125 -> V_21 ) > V_53 ||
F_3 ( V_2 , V_125 -> V_37 ) > V_127 )
return 0 ;
V_7 = F_28 ( V_65 , 2 ) ;
if ( V_7 == NULL )
return 0 ;
V_126 = (struct V_112 * ) ( V_7 -> V_12 + 64 ) ;
if ( ( F_2 ( V_2 , V_126 -> V_128 ) & ~ 0777 ) != V_129 ||
( F_3 ( V_2 , V_126 -> V_130 ) == 0 ) ||
( F_3 ( V_2 , V_126 -> V_130 ) & 017 ) ||
( F_3 ( V_2 , V_126 -> V_130 ) > V_131 *
sizeof( struct V_132 ) ) ) {
F_27 ( V_7 ) ;
return 0 ;
}
F_27 ( V_7 ) ;
return 1 ;
}
static int F_32 ( struct V_64 * V_65 , void * V_109 , int V_78 )
{
struct V_1 * V_2 ;
struct V_4 * V_55 ;
if ( 440 != sizeof ( struct V_51 ) )
F_33 ( L_14 ) ;
if ( 64 != sizeof ( struct V_112 ) )
F_33 ( L_15 ) ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_66 = V_65 ;
V_2 -> V_115 = 0 ;
V_2 -> V_62 = V_133 ;
F_24 ( & V_2 -> V_116 ) ;
V_65 -> V_117 = V_2 ;
F_25 ( V_65 , 512 ) ;
if ( ( V_55 = F_28 ( V_65 , 1 ) ) == NULL ) {
if ( ! V_78 )
F_13 ( L_16
L_17 , V_65 -> V_69 ) ;
goto V_123;
}
V_2 -> V_58 = V_75 ;
if ( F_31 ( V_65 , V_55 ) )
goto V_134;
V_2 -> V_58 = V_59 ;
if ( F_31 ( V_65 , V_55 ) )
goto V_134;
goto V_123;
V_134:
V_2 -> V_6 = V_55 ;
V_2 -> V_8 = V_55 ;
if ( F_16 ( V_65 , V_78 , 1 ) )
return 0 ;
V_123:
F_13 ( V_135 L_18 ,
V_65 -> V_69 ) ;
F_27 ( V_55 ) ;
F_30 ( V_2 ) ;
return - V_124 ;
}
static struct V_136 * F_34 ( struct V_137 * V_138 ,
int V_139 , const char * V_140 , void * V_109 )
{
return F_35 ( V_138 , V_139 , V_140 , V_109 , F_21 ) ;
}
static struct V_136 * F_36 ( struct V_137 * V_138 ,
int V_139 , const char * V_140 , void * V_109 )
{
return F_35 ( V_138 , V_139 , V_140 , V_109 , F_32 ) ;
}
static int T_3 F_37 ( void )
{
int error ;
error = F_38 () ;
if ( error )
goto V_141;
error = F_39 ( & V_142 ) ;
if ( error )
goto V_143;
error = F_39 ( & V_144 ) ;
if ( error )
goto V_145;
return 0 ;
V_145:
F_40 ( & V_142 ) ;
V_143:
F_41 () ;
V_141:
return error ;
}
static void T_4 F_42 ( void )
{
F_40 ( & V_142 ) ;
F_40 ( & V_144 ) ;
F_41 () ;
}
