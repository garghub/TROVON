static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
int V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = V_5 ;
V_2 -> V_9 . V_10 = V_11 ;
V_2 -> V_9 . V_12 = V_13 ;
V_2 -> V_9 . V_2 [ 0 ] = 0 ;
V_2 -> V_14 = V_3 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 . V_17 = V_18 ;
V_6 = F_3 ( V_2 -> V_14 , & V_19 . V_20 ,
V_2 , & V_2 -> V_21 ) ;
if ( V_6 < 0 ) {
F_4 ( V_5 ,
L_1 ,
V_2 -> V_14 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_6 ( & V_2 -> V_9 , sizeof( V_2 -> V_9 ) ) ;
if ( V_6 )
goto V_23;
V_2 -> V_15 ++ ;
V_6 = F_7 ( V_2 -> V_21 , & V_2 -> V_9 , V_2 -> V_15 ,
& V_2 -> V_16 , V_2 , 0 , 0 , 0 ) ;
if ( V_6 )
goto V_24;
return 0 ;
V_24:
F_4 ( V_2 -> V_8 , L_2 , V_6 ) ;
return V_6 ;
V_23:
F_4 ( V_2 -> V_8 , L_3 , V_6 ) ;
return V_6 ;
}
static void F_8 ( struct V_25 * V_26 , void * V_27 )
{
unsigned short V_28 ;
struct V_1 * V_2 = V_27 ;
if ( V_26 -> V_29 != V_2 -> V_15 ) {
F_4 ( V_2 -> V_8 ,
L_4 ,
( int ) V_26 -> V_29 ,
( int ) V_2 -> V_15 ) ;
F_9 ( V_26 ) ;
return;
}
V_2 -> V_30 = V_26 -> V_31 ;
if ( V_26 -> V_26 . V_32 > 0 )
V_2 -> V_33 = V_26 -> V_26 . V_2 [ 0 ] ;
else
V_2 -> V_33 = V_34 ;
if ( V_26 -> V_26 . V_32 > 1 ) {
V_28 = V_26 -> V_26 . V_32 - 1 ;
if ( V_2 -> V_35 < V_28 )
V_28 = V_2 -> V_35 ;
V_2 -> V_35 = V_28 ;
memcpy ( V_2 -> V_36 , V_26 -> V_26 . V_2 + 1 , V_2 -> V_35 ) ;
} else
V_2 -> V_35 = 0 ;
F_9 ( V_26 ) ;
F_10 ( & V_2 -> V_7 ) ;
}
static int F_11 ( struct V_37 * V_2 , T_1 V_38 , T_1 V_39 ,
void * V_40 , T_2 V_41 )
{
int V_42 , V_43 ;
struct V_44 V_45 ;
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_1 * V_48 = & V_2 -> V_48 ;
switch ( V_41 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_49 ;
}
V_45 . V_50 = V_51 ;
V_45 . V_52 = V_2 -> V_52 ;
V_45 . V_53 = V_38 ;
V_45 . V_54 = V_55 ;
V_45 . V_39 = V_39 ;
V_45 . V_56 = V_41 ;
V_48 -> V_16 . V_57 = V_58 ;
V_48 -> V_16 . V_2 = ( char * ) & V_45 ;
V_48 -> V_16 . V_32 = sizeof( V_45 ) ;
V_42 = sizeof( * V_47 ) + V_41 ;
V_48 -> V_36 = V_47 ;
V_48 -> V_35 = V_42 ;
F_5 ( V_48 ) ;
V_43 = F_12 ( & V_48 -> V_7 , V_59 ) ;
if ( ! V_43 ) {
V_43 = - V_60 ;
goto V_23;
}
if ( V_48 -> V_33 || V_48 -> V_35 != V_42 ||
memcmp ( & V_47 -> V_50 , & V_51 , sizeof( V_51 ) ) ) {
V_43 = - V_61 ;
goto V_23;
}
switch ( V_41 ) {
case 1 : {
T_1 * V_62 = V_40 ;
* V_62 = V_47 -> V_63 [ 0 ] ;
break;
}
case 2 : {
T_3 * V_62 = V_40 ;
* V_62 = F_13 ( ( V_64 * ) V_47 -> V_63 ) ;
break;
}
case 4 : {
T_4 * V_62 = V_40 ;
* V_62 = F_14 ( ( V_65 * ) V_47 -> V_63 ) ;
break;
}
case 8 : {
T_5 * V_62 = V_40 ;
* V_62 = F_15 ( ( V_66 * ) V_47 -> V_63 ) ;
break;
}
}
V_43 = 0 ;
V_23:
return V_43 ;
}
static void F_16 ( struct V_37 * V_2 , int V_67 )
{
F_11 ( V_2 , V_68 , V_67 ,
& V_2 -> V_69 [ V_67 ] , 8 ) ;
}
static void F_17 ( struct V_37 * V_2 )
{
F_16 ( V_2 , 0 ) ;
if ( V_2 -> V_70 < 2 )
return;
F_16 ( V_2 , 1 ) ;
}
static void F_18 ( struct V_37 * V_2 )
{
F_19 ( & V_2 -> V_71 ) ;
if ( F_20 ( V_72 , V_2 -> V_73 + V_74 ) &&
V_2 -> V_75 )
goto V_23;
F_17 ( V_2 ) ;
V_23:
F_21 ( & V_2 -> V_71 ) ;
}
static void F_22 ( struct V_37 * V_2 )
{
int V_76 ;
F_19 ( & V_2 -> V_71 ) ;
if ( F_20 ( V_72 , V_2 -> V_73 + V_74 ) &&
V_2 -> V_75 )
goto V_23;
F_17 ( V_2 ) ;
F_11 ( V_2 , V_77 , 0 , & V_2 -> V_78 [ 0 ] , 1 ) ;
F_11 ( V_2 , V_77 , 1 , & V_2 -> V_78 [ 1 ] , 1 ) ;
for ( V_76 = V_79 ; V_76 <= V_80 ; V_76 ++ )
F_11 ( V_2 , V_81 , V_76 ,
& V_2 -> V_82 [ V_76 ] , 2 ) ;
V_23:
F_21 ( & V_2 -> V_71 ) ;
}
static void F_23 ( struct V_37 * V_2 )
{
F_24 ( & V_2 -> V_83 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_47 ) ;
F_27 ( V_2 -> V_84 ) ;
F_28 ( V_2 -> V_48 . V_21 ) ;
F_29 ( V_2 -> V_85 , NULL ) ;
F_30 ( V_2 -> V_85 ) ;
F_31 ( & V_86 , V_2 -> V_50 ) ;
F_26 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_87 V_88 ;
struct V_89 V_90 ;
V_88 . V_50 = V_51 ;
V_88 . V_91 = 0 ;
V_88 . V_92 = F_33 ( V_93 ) ;
V_2 -> V_16 . V_57 = V_94 ;
V_2 -> V_16 . V_2 = ( char * ) & V_88 ;
V_2 -> V_16 . V_32 = sizeof( V_88 ) ;
V_2 -> V_36 = & V_90 ;
V_2 -> V_35 = sizeof( V_90 ) ;
F_5 ( V_2 ) ;
V_43 = F_12 ( & V_2 -> V_7 , V_59 ) ;
if ( ! V_43 )
return - V_60 ;
if ( V_2 -> V_33 || V_2 -> V_35 != sizeof( V_90 ) ||
memcmp ( & V_90 . V_50 , & V_51 , sizeof( V_51 ) ) )
return - V_61 ;
return V_90 . V_95 ;
}
static int F_34 ( struct V_1 * V_96 , T_1 V_52 )
{
struct V_37 * V_2 ;
int V_76 ;
int V_43 = - V_97 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return V_43 ;
F_36 ( & V_2 -> V_71 ) ;
V_2 -> V_70 = 1 ;
V_2 -> V_99 = 0 ;
V_2 -> V_52 = V_52 ;
for ( V_76 = 0 ; V_76 < V_100 ; V_76 ++ )
V_2 -> V_101 [ V_76 ] = V_102 ;
V_2 -> V_50 = F_37 ( & V_86 , 0 , 0 , V_98 ) ;
if ( V_2 -> V_50 < 0 )
goto V_103;
V_2 -> V_85 = F_38 ( V_104 , V_2 -> V_50 ) ;
if ( ! V_2 -> V_85 )
goto F_4;
V_2 -> V_85 -> V_105 . V_106 = & V_107 . V_106 ;
V_43 = F_39 ( V_2 -> V_85 ) ;
if ( V_43 )
goto V_108;
F_29 ( V_2 -> V_85 , V_2 ) ;
V_43 = F_1 ( & V_2 -> V_48 , V_96 -> V_14 ,
V_96 -> V_8 ) ;
if ( V_43 )
goto V_108;
V_2 -> V_84 = F_40 ( & V_2 -> V_85 -> V_105 ) ;
if ( F_41 ( V_2 -> V_84 ) ) {
F_4 ( & V_2 -> V_85 -> V_105 ,
L_5 ,
V_96 -> V_14 ) ;
V_43 = F_42 ( V_2 -> V_84 ) ;
goto V_109;
}
V_2 -> V_110 = F_18 ;
V_2 -> V_47 = F_35 ( sizeof( * ( V_2 -> V_47 ) ) + 8 , V_98 ) ;
if ( ! V_2 -> V_47 ) {
V_43 = - V_97 ;
goto V_111;
}
V_43 = F_43 ( V_2 ) ;
if ( V_43 )
goto V_112;
F_44 ( & V_2 -> V_83 , & V_19 . V_113 ) ;
F_45 ( V_2 -> V_48 . V_8 , L_6 ,
V_2 -> V_70 , V_2 -> V_99 ,
V_2 -> V_52 ) ;
return 0 ;
V_112:
F_26 ( V_2 -> V_47 ) ;
V_111:
F_27 ( V_2 -> V_84 ) ;
V_109:
F_28 ( V_2 -> V_48 . V_21 ) ;
V_108:
F_29 ( V_2 -> V_85 , NULL ) ;
F_30 ( V_2 -> V_85 ) ;
F_4:
F_31 ( & V_86 , V_2 -> V_50 ) ;
V_103:
F_26 ( V_2 ) ;
return V_43 ;
}
static void F_46 ( struct V_1 * V_96 )
{
int V_114 , V_76 , V_6 ;
V_114 = F_32 ( V_96 ) ;
for ( V_76 = 0 ; V_76 < V_114 ; V_76 ++ ) {
V_6 = F_34 ( V_96 , V_76 ) ;
if ( V_6 ) {
F_4 ( V_96 -> V_8 ,
L_7 ,
V_6 , V_76 ) ;
}
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_115 * V_116 ,
int V_117 )
{
int V_43 ;
struct V_118 V_119 ;
V_119 . V_50 = V_51 ;
V_119 . V_120 = V_117 ;
V_119 . V_92 = F_33 ( V_93 ) ;
V_2 -> V_16 . V_57 = V_121 ;
V_2 -> V_16 . V_2 = ( char * ) & V_119 ;
V_2 -> V_16 . V_32 = sizeof( V_119 ) ;
V_2 -> V_36 = V_116 ;
V_2 -> V_35 = sizeof( * V_116 ) ;
F_5 ( V_2 ) ;
V_43 = F_12 ( & V_2 -> V_7 , V_59 ) ;
if ( ! V_43 )
return - V_60 ;
if ( V_2 -> V_33 || V_2 -> V_35 != sizeof( * V_116 ) ||
memcmp ( & V_116 -> V_50 , & V_51 , sizeof( V_51 ) ) ||
V_116 -> V_95 <= V_117 )
return - V_61 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_96 ,
struct V_115 * V_116 )
{
struct V_37 * V_2 ;
int V_76 ;
int V_43 = - V_97 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return V_43 ;
F_36 ( & V_2 -> V_71 ) ;
V_2 -> V_70 = V_116 -> V_122 ;
V_2 -> V_99 = V_116 -> V_123 ;
V_2 -> V_52 = V_116 -> V_52 ;
for ( V_76 = 0 ; V_76 < V_124 ; V_76 ++ )
V_2 -> V_101 [ V_76 ] = V_102 ;
V_2 -> V_50 = F_37 ( & V_86 , 0 , 0 , V_98 ) ;
if ( V_2 -> V_50 < 0 )
goto V_103;
V_2 -> V_85 = F_38 ( V_104 , V_2 -> V_50 ) ;
if ( ! V_2 -> V_85 )
goto F_4;
V_2 -> V_85 -> V_105 . V_106 = & V_107 . V_106 ;
V_43 = F_39 ( V_2 -> V_85 ) ;
if ( V_43 )
goto V_108;
F_29 ( V_2 -> V_85 , V_2 ) ;
V_43 = F_1 ( & V_2 -> V_48 , V_96 -> V_14 ,
V_96 -> V_8 ) ;
if ( V_43 )
goto V_108;
V_2 -> V_84 = F_40 ( & V_2 -> V_85 -> V_105 ) ;
if ( F_41 ( V_2 -> V_84 ) ) {
F_4 ( & V_2 -> V_85 -> V_105 ,
L_5 ,
V_96 -> V_14 ) ;
V_43 = F_42 ( V_2 -> V_84 ) ;
goto V_109;
}
V_2 -> V_110 = F_22 ;
V_2 -> V_47 = F_35 ( sizeof( * ( V_2 -> V_47 ) ) + 8 , V_98 ) ;
if ( ! V_2 -> V_47 ) {
V_43 = - V_97 ;
goto V_111;
}
V_43 = F_49 ( V_2 ) ;
if ( V_43 )
goto V_112;
F_44 ( & V_2 -> V_83 , & V_19 . V_113 ) ;
F_45 ( V_2 -> V_48 . V_8 , L_6 ,
V_2 -> V_70 , V_2 -> V_99 ,
V_2 -> V_52 ) ;
return 0 ;
V_112:
F_26 ( V_2 -> V_47 ) ;
V_111:
F_27 ( V_2 -> V_84 ) ;
V_109:
F_28 ( V_2 -> V_48 . V_21 ) ;
V_108:
F_29 ( V_2 -> V_85 , NULL ) ;
F_30 ( V_2 -> V_85 ) ;
F_4:
F_31 ( & V_86 , V_2 -> V_50 ) ;
V_103:
F_26 ( V_2 ) ;
return V_43 ;
}
static void F_50 ( struct V_1 * V_96 )
{
struct V_115 V_116 ;
int V_6 ;
int V_76 = 0 ;
while ( ! F_47 ( V_96 , & V_116 , V_76 ) ) {
if ( V_116 . V_122 != 2 ) {
F_4 ( V_96 -> V_8 ,
L_8 ,
V_116 . V_122 ) ;
V_76 ++ ;
continue;
}
V_6 = F_48 ( V_96 , & V_116 ) ;
if ( V_6 ) {
F_4 ( V_96 -> V_8 ,
L_9 ,
V_6 , V_116 . V_52 ) ;
}
V_76 ++ ;
}
}
static void F_51 ( int V_3 , struct V_4 * V_105 )
{
struct V_1 V_96 ;
if ( F_1 ( & V_96 , V_3 , V_105 ) )
return;
F_46 ( & V_96 ) ;
F_50 ( & V_96 ) ;
F_28 ( V_96 . V_21 ) ;
}
static void F_52 ( int V_3 )
{
struct V_37 * V_125 , * V_126 ;
F_53 (p1, next1, &driver_data.aem_devices, list)
if ( V_125 -> V_48 . V_14 == V_3 )
F_23 ( V_125 ) ;
}
static T_6 F_54 ( struct V_4 * V_105 , struct V_127 * V_128 ,
char * V_40 )
{
struct V_37 * V_2 = F_55 ( V_105 ) ;
return sprintf ( V_40 , L_10 , V_104 , V_2 -> V_70 ) ;
}
static T_6 F_56 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
char * V_40 )
{
struct V_37 * V_2 = F_55 ( V_105 ) ;
return sprintf ( V_40 , L_11 , V_2 -> V_70 , V_2 -> V_99 ) ;
}
static T_6 F_57 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
char * V_40 )
{
struct V_129 * V_130 = F_58 ( V_128 ) ;
struct V_37 * V_2 = F_55 ( V_105 ) ;
T_5 V_131 , V_132 , V_133 , time ;
signed long V_134 ;
struct V_135 V_136 , V_137 ;
F_19 ( & V_2 -> V_71 ) ;
F_16 ( V_2 , V_130 -> V_91 ) ;
F_59 ( & V_136 ) ;
V_131 = V_2 -> V_69 [ V_130 -> V_91 ] ;
V_134 = F_60 (
F_61 ( V_2 -> V_101 [ V_130 -> V_91 ] )
) ;
if ( V_134 ) {
F_21 ( & V_2 -> V_71 ) ;
return 0 ;
}
F_16 ( V_2 , V_130 -> V_91 ) ;
F_59 ( & V_137 ) ;
V_132 = V_2 -> V_69 [ V_130 -> V_91 ] ;
F_21 ( & V_2 -> V_71 ) ;
time = F_62 ( & V_137 ) - F_62 ( & V_136 ) ;
V_133 = ( V_132 - V_131 ) * V_138 ;
return sprintf ( V_40 , L_12 ,
( unsigned long long ) F_63 ( V_133 * V_139 , time ) ) ;
}
static T_6 F_64 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
char * V_40 )
{
struct V_129 * V_130 = F_58 ( V_128 ) ;
struct V_37 * V_137 = F_55 ( V_105 ) ;
F_19 ( & V_137 -> V_71 ) ;
F_16 ( V_137 , V_130 -> V_91 ) ;
F_21 ( & V_137 -> V_71 ) ;
return sprintf ( V_40 , L_12 ,
( unsigned long long ) V_137 -> V_69 [ V_130 -> V_91 ] * 1000 ) ;
}
static T_6 F_65 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
char * V_40 )
{
struct V_129 * V_130 = F_58 ( V_128 ) ;
struct V_37 * V_137 = F_55 ( V_105 ) ;
V_137 -> V_110 ( V_137 ) ;
return sprintf ( V_40 , L_13 , V_137 -> V_101 [ V_130 -> V_91 ] ) ;
}
static T_6 F_66 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
const char * V_40 , T_2 V_140 )
{
struct V_129 * V_130 = F_58 ( V_128 ) ;
struct V_37 * V_137 = F_55 ( V_105 ) ;
unsigned long V_78 ;
int V_43 ;
V_43 = F_67 ( V_40 , 10 , & V_78 ) ;
if ( V_43 )
return V_43 ;
if ( V_78 < V_141 )
return - V_49 ;
F_19 ( & V_137 -> V_71 ) ;
V_137 -> V_101 [ V_130 -> V_91 ] = V_78 ;
F_21 ( & V_137 -> V_71 ) ;
return V_140 ;
}
static int F_68 ( struct V_37 * V_2 ,
struct V_142 * V_143 ,
struct V_144 * V_145 )
{
struct V_4 * V_105 = & V_2 -> V_85 -> V_105 ;
struct V_129 * V_146 = V_2 -> V_146 ;
int V_6 ;
while ( V_143 -> V_147 ) {
F_69 ( & V_146 -> V_148 . V_130 ) ;
V_146 -> V_148 . V_130 . V_149 = V_143 -> V_147 ;
V_146 -> V_148 . V_130 . V_150 = V_151 ;
V_146 -> V_148 . V_152 = V_143 -> V_152 ;
V_146 -> V_91 = V_143 -> V_91 ;
V_6 = F_70 ( V_105 , & V_146 -> V_148 ) ;
if ( V_6 ) {
V_146 -> V_148 . V_130 . V_149 = NULL ;
goto error;
}
V_146 ++ ;
V_143 ++ ;
}
while ( V_145 -> V_147 ) {
F_69 ( & V_146 -> V_148 . V_130 ) ;
V_146 -> V_148 . V_130 . V_149 = V_145 -> V_147 ;
V_146 -> V_148 . V_130 . V_150 = V_151 | V_153 ;
V_146 -> V_148 . V_152 = V_145 -> V_152 ;
V_146 -> V_148 . V_154 = V_145 -> V_155 ;
V_146 -> V_91 = V_145 -> V_91 ;
V_6 = F_70 ( V_105 , & V_146 -> V_148 ) ;
if ( V_6 ) {
V_146 -> V_148 . V_130 . V_149 = NULL ;
goto error;
}
V_146 ++ ;
V_145 ++ ;
}
V_6 = F_70 ( V_105 , & V_156 . V_148 ) ;
if ( V_6 )
goto error;
V_6 = F_70 ( V_105 , & V_157 . V_148 ) ;
return V_6 ;
error:
F_25 ( V_2 ) ;
return V_6 ;
}
static T_6 F_71 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
char * V_40 )
{
struct V_129 * V_130 = F_58 ( V_128 ) ;
struct V_37 * V_137 = F_55 ( V_105 ) ;
V_137 -> V_110 ( V_137 ) ;
return sprintf ( V_40 , L_14 , V_137 -> V_78 [ V_130 -> V_91 ] * 1000 ) ;
}
static T_6 F_72 ( struct V_4 * V_105 ,
struct V_127 * V_128 ,
char * V_40 )
{
struct V_129 * V_130 = F_58 ( V_128 ) ;
struct V_37 * V_137 = F_55 ( V_105 ) ;
V_137 -> V_110 ( V_137 ) ;
return sprintf ( V_40 , L_14 , V_137 -> V_82 [ V_130 -> V_91 ] * 100000 ) ;
}
static void F_25 ( struct V_37 * V_2 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_158 ; V_76 ++ ) {
if ( ! V_2 -> V_146 [ V_76 ] . V_148 . V_130 . V_149 )
continue;
F_73 ( & V_2 -> V_85 -> V_105 ,
& V_2 -> V_146 [ V_76 ] . V_148 ) ;
}
F_73 ( & V_2 -> V_85 -> V_105 ,
& V_156 . V_148 ) ;
F_73 ( & V_2 -> V_85 -> V_105 ,
& V_157 . V_148 ) ;
}
static int F_43 ( struct V_37 * V_2 )
{
return F_68 ( V_2 , V_159 , V_160 ) ;
}
static int F_49 ( struct V_37 * V_2 )
{
return F_68 ( V_2 , V_161 , V_162 ) ;
}
static int T_7 F_74 ( void )
{
int V_43 ;
V_43 = F_75 ( & V_107 . V_106 ) ;
if ( V_43 ) {
F_76 ( L_15 ) ;
return V_43 ;
}
V_43 = F_77 ( & V_19 . V_163 ) ;
if ( V_43 )
goto V_164;
return 0 ;
V_164:
F_78 ( & V_107 . V_106 ) ;
return V_43 ;
}
static void T_8 F_79 ( void )
{
struct V_37 * V_125 , * V_126 ;
F_80 ( & V_19 . V_163 ) ;
F_78 ( & V_107 . V_106 ) ;
F_53 (p1, next1, &driver_data.aem_devices, list)
F_23 ( V_125 ) ;
}
