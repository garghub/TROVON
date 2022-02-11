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
return V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_6 ( & V_2 -> V_9 , sizeof( V_2 -> V_9 ) ) ;
if ( V_6 )
goto V_22;
V_2 -> V_15 ++ ;
V_6 = F_7 ( V_2 -> V_21 , & V_2 -> V_9 , V_2 -> V_15 ,
& V_2 -> V_16 , V_2 , 0 , 0 , 0 ) ;
if ( V_6 )
goto V_23;
return 0 ;
V_23:
F_4 ( V_2 -> V_8 , L_2 , V_6 ) ;
return V_6 ;
V_22:
F_4 ( V_2 -> V_8 , L_3 , V_6 ) ;
return V_6 ;
}
static void F_8 ( struct V_24 * V_25 , void * V_26 )
{
unsigned short V_27 ;
struct V_1 * V_2 = V_26 ;
if ( V_25 -> V_28 != V_2 -> V_15 ) {
F_4 ( V_2 -> V_8 ,
L_4 ,
( int ) V_25 -> V_28 ,
( int ) V_2 -> V_15 ) ;
F_9 ( V_25 ) ;
return;
}
V_2 -> V_29 = V_25 -> V_30 ;
if ( V_25 -> V_25 . V_31 > 0 )
V_2 -> V_32 = V_25 -> V_25 . V_2 [ 0 ] ;
else
V_2 -> V_32 = V_33 ;
if ( V_25 -> V_25 . V_31 > 1 ) {
V_27 = V_25 -> V_25 . V_31 - 1 ;
if ( V_2 -> V_34 < V_27 )
V_27 = V_2 -> V_34 ;
V_2 -> V_34 = V_27 ;
memcpy ( V_2 -> V_35 , V_25 -> V_25 . V_2 + 1 , V_2 -> V_34 ) ;
} else
V_2 -> V_34 = 0 ;
F_9 ( V_25 ) ;
F_10 ( & V_2 -> V_7 ) ;
}
static int F_11 ( struct V_36 * V_2 , T_1 V_37 , T_1 V_38 ,
void * V_39 , T_2 V_40 )
{
int V_41 , V_42 ;
struct V_43 V_44 ;
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_1 * V_47 = & V_2 -> V_47 ;
switch ( V_40 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_48 ;
}
V_44 . V_49 = V_50 ;
V_44 . V_51 = V_2 -> V_51 ;
V_44 . V_52 = V_37 ;
V_44 . V_53 = V_54 ;
V_44 . V_38 = V_38 ;
V_44 . V_55 = V_40 ;
V_47 -> V_16 . V_56 = V_57 ;
V_47 -> V_16 . V_2 = ( char * ) & V_44 ;
V_47 -> V_16 . V_31 = sizeof( V_44 ) ;
V_41 = sizeof( * V_46 ) + V_40 ;
V_47 -> V_35 = V_46 ;
V_47 -> V_34 = V_41 ;
F_5 ( V_47 ) ;
V_42 = F_12 ( & V_47 -> V_7 , V_58 ) ;
if ( ! V_42 ) {
V_42 = - V_59 ;
goto V_22;
}
if ( V_47 -> V_32 || V_47 -> V_34 != V_41 ||
memcmp ( & V_46 -> V_49 , & V_50 , sizeof( V_50 ) ) ) {
V_42 = - V_60 ;
goto V_22;
}
switch ( V_40 ) {
case 1 : {
T_1 * V_61 = V_39 ;
* V_61 = V_46 -> V_62 [ 0 ] ;
break;
}
case 2 : {
T_3 * V_61 = V_39 ;
* V_61 = F_13 ( ( V_63 * ) V_46 -> V_62 ) ;
break;
}
case 4 : {
T_4 * V_61 = V_39 ;
* V_61 = F_14 ( ( V_64 * ) V_46 -> V_62 ) ;
break;
}
case 8 : {
T_5 * V_61 = V_39 ;
* V_61 = F_15 ( ( V_65 * ) V_46 -> V_62 ) ;
break;
}
}
V_42 = 0 ;
V_22:
return V_42 ;
}
static void F_16 ( struct V_36 * V_2 , int V_66 )
{
F_11 ( V_2 , V_67 , V_66 ,
& V_2 -> V_68 [ V_66 ] , 8 ) ;
}
static void F_17 ( struct V_36 * V_2 )
{
F_16 ( V_2 , 0 ) ;
if ( V_2 -> V_69 < 2 )
return;
F_16 ( V_2 , 1 ) ;
}
static void F_18 ( struct V_36 * V_2 )
{
F_19 ( & V_2 -> V_70 ) ;
if ( F_20 ( V_71 , V_2 -> V_72 + V_73 ) &&
V_2 -> V_74 )
goto V_22;
F_17 ( V_2 ) ;
V_22:
F_21 ( & V_2 -> V_70 ) ;
}
static void F_22 ( struct V_36 * V_2 )
{
int V_75 ;
F_19 ( & V_2 -> V_70 ) ;
if ( F_20 ( V_71 , V_2 -> V_72 + V_73 ) &&
V_2 -> V_74 )
goto V_22;
F_17 ( V_2 ) ;
F_11 ( V_2 , V_76 , 0 , & V_2 -> V_77 [ 0 ] , 1 ) ;
F_11 ( V_2 , V_76 , 1 , & V_2 -> V_77 [ 1 ] , 1 ) ;
for ( V_75 = V_78 ; V_75 <= V_79 ; V_75 ++ )
F_11 ( V_2 , V_80 , V_75 ,
& V_2 -> V_81 [ V_75 ] , 2 ) ;
V_22:
F_21 ( & V_2 -> V_70 ) ;
}
static void F_23 ( struct V_36 * V_2 )
{
F_24 ( & V_2 -> V_82 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_46 ) ;
F_27 ( V_2 -> V_83 ) ;
F_28 ( V_2 -> V_47 . V_21 ) ;
F_29 ( V_2 -> V_84 , NULL ) ;
F_30 ( V_2 -> V_84 ) ;
F_31 ( & V_85 , V_2 -> V_49 ) ;
F_26 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_86 V_87 ;
struct V_88 V_89 ;
V_87 . V_49 = V_50 ;
V_87 . V_90 = 0 ;
V_87 . V_91 = F_33 ( V_92 ) ;
V_2 -> V_16 . V_56 = V_93 ;
V_2 -> V_16 . V_2 = ( char * ) & V_87 ;
V_2 -> V_16 . V_31 = sizeof( V_87 ) ;
V_2 -> V_35 = & V_89 ;
V_2 -> V_34 = sizeof( V_89 ) ;
F_5 ( V_2 ) ;
V_42 = F_12 ( & V_2 -> V_7 , V_58 ) ;
if ( ! V_42 )
return - V_59 ;
if ( V_2 -> V_32 || V_2 -> V_34 != sizeof( V_89 ) ||
memcmp ( & V_89 . V_49 , & V_50 , sizeof( V_50 ) ) )
return - V_60 ;
return V_89 . V_94 ;
}
static int F_34 ( struct V_1 * V_95 , T_1 V_51 )
{
struct V_36 * V_2 ;
int V_75 ;
int V_42 = - V_96 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return V_42 ;
F_36 ( & V_2 -> V_70 ) ;
V_2 -> V_69 = 1 ;
V_2 -> V_98 = 0 ;
V_2 -> V_51 = V_51 ;
for ( V_75 = 0 ; V_75 < V_99 ; V_75 ++ )
V_2 -> V_100 [ V_75 ] = V_101 ;
V_2 -> V_49 = F_37 ( & V_85 , 0 , 0 , V_97 ) ;
if ( V_2 -> V_49 < 0 )
goto V_102;
V_2 -> V_84 = F_38 ( V_103 , V_2 -> V_49 ) ;
if ( ! V_2 -> V_84 )
goto F_4;
V_2 -> V_84 -> V_104 . V_105 = & V_106 . V_105 ;
V_42 = F_39 ( V_2 -> V_84 ) ;
if ( V_42 )
goto V_107;
F_29 ( V_2 -> V_84 , V_2 ) ;
V_42 = F_1 ( & V_2 -> V_47 , V_95 -> V_14 ,
V_95 -> V_8 ) ;
if ( V_42 )
goto V_107;
V_2 -> V_83 = F_40 ( & V_2 -> V_84 -> V_104 ) ;
if ( F_41 ( V_2 -> V_83 ) ) {
F_4 ( & V_2 -> V_84 -> V_104 ,
L_5 ,
V_95 -> V_14 ) ;
V_42 = F_42 ( V_2 -> V_83 ) ;
goto V_108;
}
V_2 -> V_109 = F_18 ;
V_2 -> V_46 = F_35 ( sizeof( * ( V_2 -> V_46 ) ) + 8 , V_97 ) ;
if ( ! V_2 -> V_46 ) {
V_42 = - V_96 ;
goto V_110;
}
V_42 = F_43 ( V_2 ) ;
if ( V_42 )
goto V_111;
F_44 ( & V_2 -> V_82 , & V_19 . V_112 ) ;
F_45 ( V_2 -> V_47 . V_8 , L_6 ,
V_2 -> V_69 , V_2 -> V_98 ,
V_2 -> V_51 ) ;
return 0 ;
V_111:
F_26 ( V_2 -> V_46 ) ;
V_110:
F_27 ( V_2 -> V_83 ) ;
V_108:
F_28 ( V_2 -> V_47 . V_21 ) ;
V_107:
F_29 ( V_2 -> V_84 , NULL ) ;
F_30 ( V_2 -> V_84 ) ;
F_4:
F_31 ( & V_85 , V_2 -> V_49 ) ;
V_102:
F_26 ( V_2 ) ;
return V_42 ;
}
static void F_46 ( struct V_1 * V_95 )
{
int V_113 , V_75 , V_6 ;
V_113 = F_32 ( V_95 ) ;
for ( V_75 = 0 ; V_75 < V_113 ; V_75 ++ ) {
V_6 = F_34 ( V_95 , V_75 ) ;
if ( V_6 ) {
F_4 ( V_95 -> V_8 ,
L_7 ,
V_6 , V_75 ) ;
}
}
}
static int F_47 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
int V_116 )
{
int V_42 ;
struct V_117 V_118 ;
V_118 . V_49 = V_50 ;
V_118 . V_119 = V_116 ;
V_118 . V_91 = F_33 ( V_92 ) ;
V_2 -> V_16 . V_56 = V_120 ;
V_2 -> V_16 . V_2 = ( char * ) & V_118 ;
V_2 -> V_16 . V_31 = sizeof( V_118 ) ;
V_2 -> V_35 = V_115 ;
V_2 -> V_34 = sizeof( * V_115 ) ;
F_5 ( V_2 ) ;
V_42 = F_12 ( & V_2 -> V_7 , V_58 ) ;
if ( ! V_42 )
return - V_59 ;
if ( V_2 -> V_32 || V_2 -> V_34 != sizeof( * V_115 ) ||
memcmp ( & V_115 -> V_49 , & V_50 , sizeof( V_50 ) ) ||
V_115 -> V_94 <= V_116 )
return - V_60 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_95 ,
struct V_114 * V_115 )
{
struct V_36 * V_2 ;
int V_75 ;
int V_42 = - V_96 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return V_42 ;
F_36 ( & V_2 -> V_70 ) ;
V_2 -> V_69 = V_115 -> V_121 ;
V_2 -> V_98 = V_115 -> V_122 ;
V_2 -> V_51 = V_115 -> V_51 ;
for ( V_75 = 0 ; V_75 < V_123 ; V_75 ++ )
V_2 -> V_100 [ V_75 ] = V_101 ;
V_2 -> V_49 = F_37 ( & V_85 , 0 , 0 , V_97 ) ;
if ( V_2 -> V_49 < 0 )
goto V_102;
V_2 -> V_84 = F_38 ( V_103 , V_2 -> V_49 ) ;
if ( ! V_2 -> V_84 )
goto F_4;
V_2 -> V_84 -> V_104 . V_105 = & V_106 . V_105 ;
V_42 = F_39 ( V_2 -> V_84 ) ;
if ( V_42 )
goto V_107;
F_29 ( V_2 -> V_84 , V_2 ) ;
V_42 = F_1 ( & V_2 -> V_47 , V_95 -> V_14 ,
V_95 -> V_8 ) ;
if ( V_42 )
goto V_107;
V_2 -> V_83 = F_40 ( & V_2 -> V_84 -> V_104 ) ;
if ( F_41 ( V_2 -> V_83 ) ) {
F_4 ( & V_2 -> V_84 -> V_104 ,
L_5 ,
V_95 -> V_14 ) ;
V_42 = F_42 ( V_2 -> V_83 ) ;
goto V_108;
}
V_2 -> V_109 = F_22 ;
V_2 -> V_46 = F_35 ( sizeof( * ( V_2 -> V_46 ) ) + 8 , V_97 ) ;
if ( ! V_2 -> V_46 ) {
V_42 = - V_96 ;
goto V_110;
}
V_42 = F_49 ( V_2 ) ;
if ( V_42 )
goto V_111;
F_44 ( & V_2 -> V_82 , & V_19 . V_112 ) ;
F_45 ( V_2 -> V_47 . V_8 , L_6 ,
V_2 -> V_69 , V_2 -> V_98 ,
V_2 -> V_51 ) ;
return 0 ;
V_111:
F_26 ( V_2 -> V_46 ) ;
V_110:
F_27 ( V_2 -> V_83 ) ;
V_108:
F_28 ( V_2 -> V_47 . V_21 ) ;
V_107:
F_29 ( V_2 -> V_84 , NULL ) ;
F_30 ( V_2 -> V_84 ) ;
F_4:
F_31 ( & V_85 , V_2 -> V_49 ) ;
V_102:
F_26 ( V_2 ) ;
return V_42 ;
}
static void F_50 ( struct V_1 * V_95 )
{
struct V_114 V_115 ;
int V_6 ;
int V_75 = 0 ;
while ( ! F_47 ( V_95 , & V_115 , V_75 ) ) {
if ( V_115 . V_121 != 2 ) {
F_4 ( V_95 -> V_8 ,
L_8 ,
V_115 . V_121 ) ;
V_75 ++ ;
continue;
}
V_6 = F_48 ( V_95 , & V_115 ) ;
if ( V_6 ) {
F_4 ( V_95 -> V_8 ,
L_9 ,
V_6 , V_115 . V_51 ) ;
}
V_75 ++ ;
}
}
static void F_51 ( int V_3 , struct V_4 * V_104 )
{
struct V_1 V_95 ;
if ( F_1 ( & V_95 , V_3 , V_104 ) )
return;
F_46 ( & V_95 ) ;
F_50 ( & V_95 ) ;
F_28 ( V_95 . V_21 ) ;
}
static void F_52 ( int V_3 )
{
struct V_36 * V_124 , * V_125 ;
F_53 (p1, next1, &driver_data.aem_devices, list)
if ( V_124 -> V_47 . V_14 == V_3 )
F_23 ( V_124 ) ;
}
static T_6 F_54 ( struct V_4 * V_104 , struct V_126 * V_127 ,
char * V_39 )
{
struct V_36 * V_2 = F_55 ( V_104 ) ;
return sprintf ( V_39 , L_10 , V_103 , V_2 -> V_69 ) ;
}
static T_6 F_56 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
char * V_39 )
{
struct V_36 * V_2 = F_55 ( V_104 ) ;
return sprintf ( V_39 , L_11 , V_2 -> V_69 , V_2 -> V_98 ) ;
}
static T_6 F_57 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
char * V_39 )
{
struct V_128 * V_129 = F_58 ( V_127 ) ;
struct V_36 * V_2 = F_55 ( V_104 ) ;
T_5 V_130 , V_131 , V_132 , time ;
signed long V_133 ;
F_19 ( & V_2 -> V_70 ) ;
F_16 ( V_2 , V_129 -> V_90 ) ;
time = F_59 () ;
V_130 = V_2 -> V_68 [ V_129 -> V_90 ] ;
V_133 = F_60 (
F_61 ( V_2 -> V_100 [ V_129 -> V_90 ] )
) ;
if ( V_133 ) {
F_21 ( & V_2 -> V_70 ) ;
return 0 ;
}
F_16 ( V_2 , V_129 -> V_90 ) ;
time = F_59 () - time ;
V_131 = V_2 -> V_68 [ V_129 -> V_90 ] ;
F_21 ( & V_2 -> V_70 ) ;
V_132 = ( V_131 - V_130 ) * V_134 ;
return sprintf ( V_39 , L_12 ,
( unsigned long long ) F_62 ( V_132 * V_135 , time ) ) ;
}
static T_6 F_63 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
char * V_39 )
{
struct V_128 * V_129 = F_58 ( V_127 ) ;
struct V_36 * V_136 = F_55 ( V_104 ) ;
F_19 ( & V_136 -> V_70 ) ;
F_16 ( V_136 , V_129 -> V_90 ) ;
F_21 ( & V_136 -> V_70 ) ;
return sprintf ( V_39 , L_12 ,
( unsigned long long ) V_136 -> V_68 [ V_129 -> V_90 ] * 1000 ) ;
}
static T_6 F_64 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
char * V_39 )
{
struct V_128 * V_129 = F_58 ( V_127 ) ;
struct V_36 * V_136 = F_55 ( V_104 ) ;
V_136 -> V_109 ( V_136 ) ;
return sprintf ( V_39 , L_13 , V_136 -> V_100 [ V_129 -> V_90 ] ) ;
}
static T_6 F_65 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
const char * V_39 , T_2 V_137 )
{
struct V_128 * V_129 = F_58 ( V_127 ) ;
struct V_36 * V_136 = F_55 ( V_104 ) ;
unsigned long V_77 ;
int V_42 ;
V_42 = F_66 ( V_39 , 10 , & V_77 ) ;
if ( V_42 )
return V_42 ;
if ( V_77 < V_138 )
return - V_48 ;
F_19 ( & V_136 -> V_70 ) ;
V_136 -> V_100 [ V_129 -> V_90 ] = V_77 ;
F_21 ( & V_136 -> V_70 ) ;
return V_137 ;
}
static int F_67 ( struct V_36 * V_2 ,
struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_4 * V_104 = & V_2 -> V_84 -> V_104 ;
struct V_128 * V_143 = V_2 -> V_143 ;
int V_6 ;
while ( V_140 -> V_144 ) {
F_68 ( & V_143 -> V_145 . V_129 ) ;
V_143 -> V_145 . V_129 . V_146 = V_140 -> V_144 ;
V_143 -> V_145 . V_129 . V_147 = V_148 ;
V_143 -> V_145 . V_149 = V_140 -> V_149 ;
V_143 -> V_90 = V_140 -> V_90 ;
V_6 = F_69 ( V_104 , & V_143 -> V_145 ) ;
if ( V_6 ) {
V_143 -> V_145 . V_129 . V_146 = NULL ;
goto error;
}
V_143 ++ ;
V_140 ++ ;
}
while ( V_142 -> V_144 ) {
F_68 ( & V_143 -> V_145 . V_129 ) ;
V_143 -> V_145 . V_129 . V_146 = V_142 -> V_144 ;
V_143 -> V_145 . V_129 . V_147 = V_148 | V_150 ;
V_143 -> V_145 . V_149 = V_142 -> V_149 ;
V_143 -> V_145 . V_151 = V_142 -> V_152 ;
V_143 -> V_90 = V_142 -> V_90 ;
V_6 = F_69 ( V_104 , & V_143 -> V_145 ) ;
if ( V_6 ) {
V_143 -> V_145 . V_129 . V_146 = NULL ;
goto error;
}
V_143 ++ ;
V_142 ++ ;
}
V_6 = F_69 ( V_104 , & V_153 . V_145 ) ;
if ( V_6 )
goto error;
V_6 = F_69 ( V_104 , & V_154 . V_145 ) ;
return V_6 ;
error:
F_25 ( V_2 ) ;
return V_6 ;
}
static T_6 F_70 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
char * V_39 )
{
struct V_128 * V_129 = F_58 ( V_127 ) ;
struct V_36 * V_136 = F_55 ( V_104 ) ;
V_136 -> V_109 ( V_136 ) ;
return sprintf ( V_39 , L_14 , V_136 -> V_77 [ V_129 -> V_90 ] * 1000 ) ;
}
static T_6 F_71 ( struct V_4 * V_104 ,
struct V_126 * V_127 ,
char * V_39 )
{
struct V_128 * V_129 = F_58 ( V_127 ) ;
struct V_36 * V_136 = F_55 ( V_104 ) ;
V_136 -> V_109 ( V_136 ) ;
return sprintf ( V_39 , L_14 , V_136 -> V_81 [ V_129 -> V_90 ] * 100000 ) ;
}
static void F_25 ( struct V_36 * V_2 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_155 ; V_75 ++ ) {
if ( ! V_2 -> V_143 [ V_75 ] . V_145 . V_129 . V_146 )
continue;
F_72 ( & V_2 -> V_84 -> V_104 ,
& V_2 -> V_143 [ V_75 ] . V_145 ) ;
}
F_72 ( & V_2 -> V_84 -> V_104 ,
& V_153 . V_145 ) ;
F_72 ( & V_2 -> V_84 -> V_104 ,
& V_154 . V_145 ) ;
}
static int F_43 ( struct V_36 * V_2 )
{
return F_67 ( V_2 , V_156 , V_157 ) ;
}
static int F_49 ( struct V_36 * V_2 )
{
return F_67 ( V_2 , V_158 , V_159 ) ;
}
static int T_7 F_73 ( void )
{
int V_42 ;
V_42 = F_74 ( & V_106 . V_105 ) ;
if ( V_42 ) {
F_75 ( L_15 ) ;
return V_42 ;
}
V_42 = F_76 ( & V_19 . V_160 ) ;
if ( V_42 )
goto V_161;
return 0 ;
V_161:
F_77 ( & V_106 . V_105 ) ;
return V_42 ;
}
static void T_8 F_78 ( void )
{
struct V_36 * V_124 , * V_125 ;
F_79 ( & V_19 . V_160 ) ;
F_77 ( & V_106 . V_105 ) ;
F_53 (p1, next1, &driver_data.aem_devices, list)
F_23 ( V_124 ) ;
}
