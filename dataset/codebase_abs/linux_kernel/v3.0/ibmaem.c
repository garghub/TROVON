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
F_4 ( V_5 , L_1
L_2 , V_2 -> V_14 ) ;
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
F_4 ( V_2 -> V_8 , L_3 , V_6 ) ;
return V_6 ;
V_23:
F_4 ( V_2 -> V_8 , L_4 , V_6 ) ;
return V_6 ;
}
static void F_8 ( struct V_25 * V_26 , void * V_27 )
{
unsigned short V_28 ;
struct V_1 * V_2 = V_27 ;
if ( V_26 -> V_29 != V_2 -> V_15 ) {
F_4 ( V_2 -> V_8 , L_5
L_6 ,
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
static int F_11 ( int * V_37 )
{
int V_38 , V_6 ;
V_39:
if ( F_12 ( ! F_13 ( & V_40 , V_41 ) ) )
return - V_42 ;
F_14 ( & V_43 ) ;
V_6 = F_15 ( & V_40 , NULL , & V_38 ) ;
F_16 ( & V_43 ) ;
if ( F_12 ( V_6 == - V_44 ) )
goto V_39;
else if ( F_12 ( V_6 ) )
return V_6 ;
* V_37 = V_38 & V_45 ;
return 0 ;
}
static void F_17 ( int V_37 )
{
F_14 ( & V_43 ) ;
F_18 ( & V_40 , V_37 ) ;
F_16 ( & V_43 ) ;
}
static int F_19 ( struct V_46 * V_2 , T_1 V_47 , T_1 V_48 ,
void * V_49 , T_2 V_50 )
{
int V_51 , V_52 ;
struct V_53 V_54 ;
struct V_55 * V_56 ;
struct V_1 * V_57 = & V_2 -> V_57 ;
switch ( V_50 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_58 ;
}
V_54 . V_37 = V_59 ;
V_54 . V_60 = V_2 -> V_60 ;
V_54 . V_61 = V_47 ;
V_54 . V_62 = V_63 ;
V_54 . V_48 = V_48 ;
V_54 . V_64 = V_50 ;
V_57 -> V_16 . V_65 = V_66 ;
V_57 -> V_16 . V_2 = ( char * ) & V_54 ;
V_57 -> V_16 . V_32 = sizeof( V_54 ) ;
V_51 = sizeof( * V_56 ) + V_50 ;
V_56 = F_20 ( V_51 , V_41 ) ;
if ( ! V_56 )
return - V_42 ;
V_57 -> V_36 = V_56 ;
V_57 -> V_35 = V_51 ;
F_5 ( V_57 ) ;
V_52 = F_21 ( & V_57 -> V_7 , V_67 ) ;
if ( ! V_52 )
return - V_68 ;
if ( V_57 -> V_33 || V_57 -> V_35 != V_51 ||
memcmp ( & V_56 -> V_37 , & V_59 , sizeof( V_59 ) ) ) {
F_22 ( V_56 ) ;
return - V_69 ;
}
switch ( V_50 ) {
case 1 : {
T_1 * V_70 = V_49 ;
* V_70 = V_56 -> V_71 [ 0 ] ;
break;
}
case 2 : {
T_3 * V_70 = V_49 ;
* V_70 = F_23 ( ( V_72 * ) V_56 -> V_71 ) ;
break;
}
case 4 : {
T_4 * V_70 = V_49 ;
* V_70 = F_24 ( ( V_73 * ) V_56 -> V_71 ) ;
break;
}
case 8 : {
T_5 * V_70 = V_49 ;
* V_70 = F_25 ( ( V_74 * ) V_56 -> V_71 ) ;
break;
}
}
return 0 ;
}
static void F_26 ( struct V_46 * V_2 , int V_75 )
{
F_19 ( V_2 , V_76 , V_75 ,
& V_2 -> V_77 [ V_75 ] , 8 ) ;
}
static void F_27 ( struct V_46 * V_2 )
{
F_26 ( V_2 , 0 ) ;
if ( V_2 -> V_78 < 2 )
return;
F_26 ( V_2 , 1 ) ;
}
static void F_28 ( struct V_46 * V_2 )
{
F_29 ( & V_2 -> V_79 ) ;
if ( F_30 ( V_80 , V_2 -> V_81 + V_82 ) &&
V_2 -> V_83 )
goto V_23;
F_27 ( V_2 ) ;
V_23:
F_31 ( & V_2 -> V_79 ) ;
}
static void F_32 ( struct V_46 * V_2 )
{
int V_38 ;
F_29 ( & V_2 -> V_79 ) ;
if ( F_30 ( V_80 , V_2 -> V_81 + V_82 ) &&
V_2 -> V_83 )
goto V_23;
F_27 ( V_2 ) ;
F_19 ( V_2 , V_84 , 0 , & V_2 -> V_85 [ 0 ] , 1 ) ;
F_19 ( V_2 , V_84 , 1 , & V_2 -> V_85 [ 1 ] , 1 ) ;
for ( V_38 = V_86 ; V_38 <= V_87 ; V_38 ++ )
F_19 ( V_2 , V_88 , V_38 ,
& V_2 -> V_89 [ V_38 ] , 2 ) ;
V_23:
F_31 ( & V_2 -> V_79 ) ;
}
static void F_33 ( struct V_46 * V_2 )
{
F_34 ( & V_2 -> V_90 ) ;
F_35 ( V_2 ) ;
F_36 ( V_2 -> V_91 ) ;
F_37 ( V_2 -> V_57 . V_21 ) ;
F_38 ( V_2 -> V_92 , NULL ) ;
F_39 ( V_2 -> V_92 ) ;
F_17 ( V_2 -> V_37 ) ;
F_22 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_52 ;
struct V_93 V_94 ;
struct V_95 V_96 ;
V_94 . V_37 = V_59 ;
V_94 . V_97 = 0 ;
V_94 . V_98 = F_41 ( V_99 ) ;
V_2 -> V_16 . V_65 = V_100 ;
V_2 -> V_16 . V_2 = ( char * ) & V_94 ;
V_2 -> V_16 . V_32 = sizeof( V_94 ) ;
V_2 -> V_36 = & V_96 ;
V_2 -> V_35 = sizeof( V_96 ) ;
F_5 ( V_2 ) ;
V_52 = F_21 ( & V_2 -> V_7 , V_67 ) ;
if ( ! V_52 )
return - V_68 ;
if ( V_2 -> V_33 || V_2 -> V_35 != sizeof( V_96 ) ||
memcmp ( & V_96 . V_37 , & V_59 , sizeof( V_59 ) ) )
return - V_69 ;
return V_96 . V_101 ;
}
static int F_42 ( struct V_1 * V_102 , T_1 V_60 )
{
struct V_46 * V_2 ;
int V_38 ;
int V_52 = - V_42 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return V_52 ;
F_43 ( & V_2 -> V_79 ) ;
V_2 -> V_78 = 1 ;
V_2 -> V_103 = 0 ;
V_2 -> V_60 = V_60 ;
for ( V_38 = 0 ; V_38 < V_104 ; V_38 ++ )
V_2 -> V_105 [ V_38 ] = V_106 ;
if ( F_11 ( & V_2 -> V_37 ) )
goto V_107;
V_2 -> V_92 = F_44 ( V_108 , V_2 -> V_37 ) ;
if ( ! V_2 -> V_92 )
goto F_4;
V_2 -> V_92 -> V_109 . V_110 = & V_111 . V_110 ;
V_52 = F_45 ( V_2 -> V_92 ) ;
if ( V_52 )
goto V_112;
F_38 ( V_2 -> V_92 , V_2 ) ;
if ( F_1 ( & V_2 -> V_57 , V_102 -> V_14 ,
V_102 -> V_8 ) )
goto V_112;
V_2 -> V_91 = F_46 ( & V_2 -> V_92 -> V_109 ) ;
if ( F_47 ( V_2 -> V_91 ) ) {
F_4 ( & V_2 -> V_92 -> V_109 , L_7
L_8 ,
V_102 -> V_14 ) ;
goto V_113;
}
V_2 -> V_114 = F_28 ;
if ( F_48 ( V_2 ) )
goto V_115;
F_49 ( & V_2 -> V_90 , & V_19 . V_116 ) ;
F_50 ( V_2 -> V_57 . V_8 , L_9 ,
V_2 -> V_78 , V_2 -> V_103 ,
V_2 -> V_60 ) ;
return 0 ;
V_115:
F_36 ( V_2 -> V_91 ) ;
V_113:
F_37 ( V_2 -> V_57 . V_21 ) ;
V_112:
F_38 ( V_2 -> V_92 , NULL ) ;
F_39 ( V_2 -> V_92 ) ;
F_4:
F_17 ( V_2 -> V_37 ) ;
V_107:
F_22 ( V_2 ) ;
return V_52 ;
}
static int F_51 ( struct V_1 * V_102 )
{
int V_117 , V_38 , V_6 ;
V_117 = F_40 ( V_102 ) ;
for ( V_38 = 0 ; V_38 < V_117 ; V_38 ++ ) {
V_6 = F_42 ( V_102 , V_38 ) ;
if ( V_6 ) {
F_4 ( V_102 -> V_8 ,
L_10 ,
V_6 , V_38 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
int V_120 )
{
int V_52 ;
struct V_121 V_122 ;
V_122 . V_37 = V_59 ;
V_122 . V_123 = V_120 ;
V_122 . V_98 = F_41 ( V_99 ) ;
V_2 -> V_16 . V_65 = V_124 ;
V_2 -> V_16 . V_2 = ( char * ) & V_122 ;
V_2 -> V_16 . V_32 = sizeof( V_122 ) ;
V_2 -> V_36 = V_119 ;
V_2 -> V_35 = sizeof( * V_119 ) ;
F_5 ( V_2 ) ;
V_52 = F_21 ( & V_2 -> V_7 , V_67 ) ;
if ( ! V_52 )
return - V_68 ;
if ( V_2 -> V_33 || V_2 -> V_35 != sizeof( * V_119 ) ||
memcmp ( & V_119 -> V_37 , & V_59 , sizeof( V_59 ) ) ||
V_119 -> V_101 <= V_120 )
return - V_69 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_102 ,
struct V_118 * V_119 )
{
struct V_46 * V_2 ;
int V_38 ;
int V_52 = - V_42 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return V_52 ;
F_43 ( & V_2 -> V_79 ) ;
V_2 -> V_78 = V_119 -> V_125 ;
V_2 -> V_103 = V_119 -> V_126 ;
V_2 -> V_60 = V_119 -> V_60 ;
for ( V_38 = 0 ; V_38 < V_127 ; V_38 ++ )
V_2 -> V_105 [ V_38 ] = V_106 ;
if ( F_11 ( & V_2 -> V_37 ) )
goto V_107;
V_2 -> V_92 = F_44 ( V_108 , V_2 -> V_37 ) ;
if ( ! V_2 -> V_92 )
goto F_4;
V_2 -> V_92 -> V_109 . V_110 = & V_111 . V_110 ;
V_52 = F_45 ( V_2 -> V_92 ) ;
if ( V_52 )
goto V_112;
F_38 ( V_2 -> V_92 , V_2 ) ;
if ( F_1 ( & V_2 -> V_57 , V_102 -> V_14 ,
V_102 -> V_8 ) )
goto V_112;
V_2 -> V_91 = F_46 ( & V_2 -> V_92 -> V_109 ) ;
if ( F_47 ( V_2 -> V_91 ) ) {
F_4 ( & V_2 -> V_92 -> V_109 , L_7
L_8 ,
V_102 -> V_14 ) ;
goto V_113;
}
V_2 -> V_114 = F_32 ;
if ( F_54 ( V_2 ) )
goto V_115;
F_49 ( & V_2 -> V_90 , & V_19 . V_116 ) ;
F_50 ( V_2 -> V_57 . V_8 , L_9 ,
V_2 -> V_78 , V_2 -> V_103 ,
V_2 -> V_60 ) ;
return 0 ;
V_115:
F_36 ( V_2 -> V_91 ) ;
V_113:
F_37 ( V_2 -> V_57 . V_21 ) ;
V_112:
F_38 ( V_2 -> V_92 , NULL ) ;
F_39 ( V_2 -> V_92 ) ;
F_4:
F_17 ( V_2 -> V_37 ) ;
V_107:
F_22 ( V_2 ) ;
return V_52 ;
}
static int F_55 ( struct V_1 * V_102 )
{
struct V_118 V_119 ;
int V_6 ;
int V_38 = 0 ;
while ( ! F_52 ( V_102 , & V_119 , V_38 ) ) {
if ( V_119 . V_125 != 2 ) {
F_4 ( V_102 -> V_8 , L_11
L_12 ,
V_119 . V_125 ) ;
V_38 ++ ;
continue;
}
V_6 = F_53 ( V_102 , & V_119 ) ;
if ( V_6 ) {
F_4 ( V_102 -> V_8 ,
L_13 ,
V_6 , V_119 . V_60 ) ;
return V_6 ;
}
V_38 ++ ;
}
return 0 ;
}
static void F_56 ( int V_3 , struct V_4 * V_109 )
{
struct V_1 V_102 ;
if ( F_1 ( & V_102 , V_3 , V_109 ) )
return;
F_51 ( & V_102 ) ;
F_55 ( & V_102 ) ;
F_37 ( V_102 . V_21 ) ;
}
static void F_57 ( int V_3 )
{
struct V_46 * V_128 , * V_129 ;
F_58 (p1, next1, &driver_data.aem_devices, list)
if ( V_128 -> V_57 . V_14 == V_3 )
F_33 ( V_128 ) ;
}
static T_6 F_59 ( struct V_4 * V_109 , struct V_130 * V_131 ,
char * V_49 )
{
struct V_46 * V_2 = F_60 ( V_109 ) ;
return sprintf ( V_49 , L_14 , V_108 , V_2 -> V_78 ) ;
}
static T_6 F_61 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
char * V_49 )
{
struct V_46 * V_2 = F_60 ( V_109 ) ;
return sprintf ( V_49 , L_15 , V_2 -> V_78 , V_2 -> V_103 ) ;
}
static T_6 F_62 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
char * V_49 )
{
struct V_132 * V_133 = F_63 ( V_131 ) ;
struct V_46 * V_2 = F_60 ( V_109 ) ;
T_5 V_134 , V_135 , V_136 , time ;
signed long V_137 ;
struct V_138 V_139 , V_140 ;
F_29 ( & V_2 -> V_79 ) ;
F_26 ( V_2 , V_133 -> V_97 ) ;
F_64 ( & V_139 ) ;
V_134 = V_2 -> V_77 [ V_133 -> V_97 ] ;
V_137 = F_65 (
F_66 ( V_2 -> V_105 [ V_133 -> V_97 ] )
) ;
if ( V_137 ) {
F_31 ( & V_2 -> V_79 ) ;
return 0 ;
}
F_26 ( V_2 , V_133 -> V_97 ) ;
F_64 ( & V_140 ) ;
V_135 = V_2 -> V_77 [ V_133 -> V_97 ] ;
F_31 ( & V_2 -> V_79 ) ;
time = F_67 ( & V_140 ) - F_67 ( & V_139 ) ;
V_136 = ( V_135 - V_134 ) * V_141 ;
return sprintf ( V_49 , L_16 ,
( unsigned long long ) F_68 ( V_136 * V_142 , time ) ) ;
}
static T_6 F_69 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
char * V_49 )
{
struct V_132 * V_133 = F_63 ( V_131 ) ;
struct V_46 * V_140 = F_60 ( V_109 ) ;
F_29 ( & V_140 -> V_79 ) ;
F_26 ( V_140 , V_133 -> V_97 ) ;
F_31 ( & V_140 -> V_79 ) ;
return sprintf ( V_49 , L_16 ,
( unsigned long long ) V_140 -> V_77 [ V_133 -> V_97 ] * 1000 ) ;
}
static T_6 F_70 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
char * V_49 )
{
struct V_132 * V_133 = F_63 ( V_131 ) ;
struct V_46 * V_140 = F_60 ( V_109 ) ;
V_140 -> V_114 ( V_140 ) ;
return sprintf ( V_49 , L_17 , V_140 -> V_105 [ V_133 -> V_97 ] ) ;
}
static T_6 F_71 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
const char * V_49 , T_2 V_143 )
{
struct V_132 * V_133 = F_63 ( V_131 ) ;
struct V_46 * V_140 = F_60 ( V_109 ) ;
unsigned long V_85 ;
int V_52 ;
V_52 = F_72 ( V_49 , 10 , & V_85 ) ;
if ( V_52 )
return V_52 ;
if ( V_85 < V_144 )
return - V_58 ;
F_29 ( & V_140 -> V_79 ) ;
V_140 -> V_105 [ V_133 -> V_97 ] = V_85 ;
F_31 ( & V_140 -> V_79 ) ;
return V_143 ;
}
static int F_73 ( struct V_46 * V_2 ,
struct V_145 * V_146 ,
struct V_147 * V_148 )
{
struct V_4 * V_109 = & V_2 -> V_92 -> V_109 ;
struct V_132 * V_149 = V_2 -> V_149 ;
int V_6 ;
while ( V_146 -> V_150 ) {
F_74 ( & V_149 -> V_151 . V_133 ) ;
V_149 -> V_151 . V_133 . V_152 = V_146 -> V_150 ;
V_149 -> V_151 . V_133 . V_153 = V_154 ;
V_149 -> V_151 . V_155 = V_146 -> V_155 ;
V_149 -> V_97 = V_146 -> V_97 ;
V_6 = F_75 ( V_109 , & V_149 -> V_151 ) ;
if ( V_6 ) {
V_149 -> V_151 . V_133 . V_152 = NULL ;
goto error;
}
V_149 ++ ;
V_146 ++ ;
}
while ( V_148 -> V_150 ) {
F_74 ( & V_149 -> V_151 . V_133 ) ;
V_149 -> V_151 . V_133 . V_152 = V_148 -> V_150 ;
V_149 -> V_151 . V_133 . V_153 = V_154 | V_156 ;
V_149 -> V_151 . V_155 = V_148 -> V_155 ;
V_149 -> V_151 . V_157 = V_148 -> V_158 ;
V_149 -> V_97 = V_148 -> V_97 ;
V_6 = F_75 ( V_109 , & V_149 -> V_151 ) ;
if ( V_6 ) {
V_149 -> V_151 . V_133 . V_152 = NULL ;
goto error;
}
V_149 ++ ;
V_148 ++ ;
}
V_6 = F_75 ( V_109 , & V_159 . V_151 ) ;
if ( V_6 )
goto error;
V_6 = F_75 ( V_109 , & V_160 . V_151 ) ;
return V_6 ;
error:
F_35 ( V_2 ) ;
return V_6 ;
}
static T_6 F_76 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
char * V_49 )
{
struct V_132 * V_133 = F_63 ( V_131 ) ;
struct V_46 * V_140 = F_60 ( V_109 ) ;
V_140 -> V_114 ( V_140 ) ;
return sprintf ( V_49 , L_18 , V_140 -> V_85 [ V_133 -> V_97 ] * 1000 ) ;
}
static T_6 F_77 ( struct V_4 * V_109 ,
struct V_130 * V_131 ,
char * V_49 )
{
struct V_132 * V_133 = F_63 ( V_131 ) ;
struct V_46 * V_140 = F_60 ( V_109 ) ;
V_140 -> V_114 ( V_140 ) ;
return sprintf ( V_49 , L_18 , V_140 -> V_89 [ V_133 -> V_97 ] * 100000 ) ;
}
static void F_35 ( struct V_46 * V_2 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_161 ; V_38 ++ ) {
if ( ! V_2 -> V_149 [ V_38 ] . V_151 . V_133 . V_152 )
continue;
F_78 ( & V_2 -> V_92 -> V_109 ,
& V_2 -> V_149 [ V_38 ] . V_151 ) ;
}
F_78 ( & V_2 -> V_92 -> V_109 ,
& V_159 . V_151 ) ;
F_78 ( & V_2 -> V_92 -> V_109 ,
& V_160 . V_151 ) ;
}
static int F_48 ( struct V_46 * V_2 )
{
return F_73 ( V_2 , V_162 , V_163 ) ;
}
static int F_54 ( struct V_46 * V_2 )
{
return F_73 ( V_2 , V_164 , V_165 ) ;
}
static int T_7 F_79 ( void )
{
int V_52 ;
V_52 = F_80 ( & V_111 . V_110 ) ;
if ( V_52 ) {
F_81 ( L_19 ) ;
return V_52 ;
}
V_52 = F_82 ( & V_19 . V_166 ) ;
if ( V_52 )
goto V_167;
return 0 ;
V_167:
F_83 ( & V_111 . V_110 ) ;
return V_52 ;
}
static void T_8 F_84 ( void )
{
struct V_46 * V_128 , * V_129 ;
F_85 ( & V_19 . V_166 ) ;
F_83 ( & V_111 . V_110 ) ;
F_58 (p1, next1, &driver_data.aem_devices, list)
F_33 ( V_128 ) ;
}
