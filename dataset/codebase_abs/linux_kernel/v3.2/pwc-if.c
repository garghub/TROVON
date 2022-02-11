struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned long V_4 = 0 ;
struct V_1 * V_5 = NULL ;
F_2 ( & V_3 -> V_6 , V_4 ) ;
if ( F_3 ( & V_3 -> V_7 ) )
goto V_8;
V_5 = F_4 ( V_3 -> V_7 . V_9 , struct V_1 , V_10 ) ;
F_5 ( & V_5 -> V_10 ) ;
V_8:
F_6 ( & V_3 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_7 ( struct V_2 * V_3 , int V_11 )
{
if ( V_11 ) {
F_8 ( L_1 ) ;
V_3 -> V_12 = 1 ;
} else {
F_8 ( L_2 ) ;
}
#ifdef F_9
if ( V_3 -> V_13 ) {
F_10 ( V_3 -> V_13 , V_14 , V_11 ) ;
F_11 ( V_3 -> V_13 ) ;
}
#endif
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_15 = V_3 -> V_16 ;
if ( V_3 -> type == 730 ) {
unsigned char * V_17 = ( unsigned char * ) V_15 -> V_18 ;
if ( V_17 [ 1 ] == 1 && V_17 [ 0 ] & 0x10 ) {
F_8 ( L_3 ) ;
V_3 -> V_19 += 2 ;
}
if ( ( V_17 [ 0 ] ^ V_3 -> V_20 ) & 0x01 ) {
F_7 ( V_3 , V_17 [ 0 ] & 0x01 ) ;
}
if ( ( V_17 [ 0 ] ^ V_3 -> V_20 ) & 0x02 ) {
if ( V_17 [ 0 ] & 0x02 )
F_8 ( L_4 ) ;
else
F_8 ( L_5 ) ;
}
V_3 -> V_20 = V_17 [ 0 ] & 0x03 ;
if ( V_15 -> V_21 == 4 )
V_3 -> V_19 ++ ;
} else if ( V_3 -> type == 740 || V_3 -> type == 720 ) {
unsigned char * V_17 = ( unsigned char * ) V_15 -> V_18 ;
if ( ( V_17 [ 0 ] ^ V_3 -> V_20 ) & 0x01 ) {
F_7 ( V_3 , V_17 [ 0 ] & 0x01 ) ;
}
V_3 -> V_20 = V_17 [ 0 ] & 0x03 ;
}
if ( V_3 -> V_19 > 0 ) {
V_3 -> V_19 -- ;
} else {
if ( V_15 -> V_21 < V_3 -> V_22 ) {
F_13 ( L_6
L_7 , V_15 -> V_21 ) ;
} else {
V_15 -> V_23 . V_24 . V_25 = V_26 ;
V_15 -> V_23 . V_24 . V_27 = V_3 -> V_28 ;
F_14 ( & V_15 -> V_23 , V_29 ) ;
V_3 -> V_16 = NULL ;
V_3 -> V_30 = 0 ;
}
}
V_3 -> V_28 ++ ;
}
static void F_15 ( struct V_31 * V_31 )
{
struct V_2 * V_3 = (struct V_2 * ) V_31 -> V_32 ;
int V_33 , V_34 , V_35 ;
unsigned char * V_36 = NULL ;
if ( V_31 -> V_37 == - V_38 || V_31 -> V_37 == - V_39 ||
V_31 -> V_37 == - V_40 ) {
F_16 ( L_8 , V_31 , V_31 -> V_37 == - V_38 ? L_9 : L_10 ) ;
return;
}
if ( V_3 -> V_16 == NULL )
V_3 -> V_16 = F_1 ( V_3 ) ;
if ( V_31 -> V_37 != 0 ) {
const char * V_41 ;
V_41 = L_11 ;
switch( V_31 -> V_37 ) {
case - V_42 : V_41 = L_12 ; break;
case - V_43 : V_41 = L_13 ; break;
case - V_44 : V_41 = L_14 ; break;
case - V_45 : V_41 = L_15 ; break;
case - V_46 : V_41 = L_16 ; break;
case - V_47 : V_41 = L_17 ; break;
}
F_17 ( L_18 ,
V_31 -> V_37 , V_41 ) ;
if ( ++ V_3 -> V_48 > V_49 )
{
F_17 ( L_19 ) ;
if ( V_3 -> V_16 ) {
F_14 ( & V_3 -> V_16 -> V_23 ,
V_50 ) ;
V_3 -> V_16 = NULL ;
}
}
V_3 -> V_30 = 0 ;
goto V_51;
}
V_3 -> V_48 = 0 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_52 ; V_33 ++ ) {
V_34 = V_31 -> V_53 [ V_33 ] . V_37 ;
V_35 = V_31 -> V_53 [ V_33 ] . V_54 ;
V_36 = V_31 -> V_55 + V_31 -> V_53 [ V_33 ] . V_56 ;
if ( V_34 != 0 ) {
F_17 ( L_20 , V_33 , V_34 ) ;
continue;
}
if ( V_35 > 0 && V_3 -> V_30 ) {
struct V_1 * V_15 = V_3 -> V_16 ;
if ( V_3 -> V_30 == 1 ) {
F_18 ( & V_15 -> V_23 . V_24 . V_57 ) ;
V_3 -> V_30 = 2 ;
}
if ( V_35 + V_15 -> V_21 > V_3 -> V_22 ) {
F_17 ( L_21 ,
V_35 + V_15 -> V_21 ,
V_3 -> V_22 ) ;
V_3 -> V_30 = 0 ;
} else {
memcpy ( V_15 -> V_18 + V_15 -> V_21 , V_36 ,
V_35 ) ;
V_15 -> V_21 += V_35 ;
}
}
if ( V_35 < V_3 -> V_58 ) {
if ( V_3 -> V_30 == 2 )
F_12 ( V_3 ) ;
if ( V_3 -> V_16 == NULL )
V_3 -> V_16 = F_1 ( V_3 ) ;
if ( V_3 -> V_16 ) {
V_3 -> V_16 -> V_21 = 0 ;
V_3 -> V_30 = 1 ;
}
}
V_3 -> V_58 = V_35 ;
}
V_51:
V_33 = F_19 ( V_31 , V_59 ) ;
if ( V_33 != 0 )
F_17 ( L_22 , V_33 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_60 * V_61 ;
struct V_31 * V_31 ;
int V_33 , V_62 , V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 = NULL ;
if ( V_3 -> V_68 )
return 0 ;
V_3 -> V_30 = 0 ;
V_3 -> V_58 = 0 ;
V_3 -> V_16 = NULL ;
V_3 -> V_28 = 0 ;
V_3 -> V_48 = 0 ;
V_61 = V_3 -> V_61 ;
V_65 = F_21 ( V_61 , 0 ) ;
if ( V_65 )
V_67 = F_22 ( V_65 , V_3 -> V_69 ) ;
if ( ! V_67 )
return - V_70 ;
V_3 -> V_71 = - 1 ;
for ( V_33 = 0 ; V_33 < V_67 -> V_72 . V_73 ; V_33 ++ ) {
if ( ( V_67 -> V_74 [ V_33 ] . V_72 . V_75 & 0xF ) == V_3 -> V_76 ) {
V_3 -> V_71 = F_23 ( V_67 -> V_74 [ V_33 ] . V_72 . V_77 ) ;
break;
}
}
if ( V_3 -> V_71 < 0 || V_3 -> V_71 > V_78 ) {
F_17 ( L_23 ) ;
return - V_79 ;
}
V_63 = 0 ;
F_16 ( L_24 , V_3 -> V_69 ) ;
V_63 = F_24 ( V_3 -> V_61 , 0 , V_3 -> V_69 ) ;
if ( V_63 < 0 )
return V_63 ;
for ( V_33 = 0 ; V_33 < V_80 ; V_33 ++ ) {
V_31 = F_25 ( V_81 , V_82 ) ;
if ( V_31 == NULL ) {
F_17 ( L_25 , V_33 ) ;
V_3 -> V_68 = 1 ;
F_26 ( V_3 ) ;
return - V_83 ;
}
V_3 -> V_84 [ V_33 ] = V_31 ;
F_27 ( L_26 , V_31 ) ;
V_31 -> V_85 = 1 ;
V_31 -> V_86 = V_61 ;
V_31 -> V_87 = F_28 ( V_61 , V_3 -> V_76 ) ;
V_31 -> V_88 = V_89 | V_90 ;
V_31 -> V_55 = F_29 ( V_61 ,
V_91 ,
V_82 ,
& V_31 -> V_92 ) ;
if ( V_31 -> V_55 == NULL ) {
F_17 ( L_27 , V_33 ) ;
V_3 -> V_68 = 1 ;
F_26 ( V_3 ) ;
return - V_83 ;
}
V_31 -> V_93 = V_91 ;
V_31 -> V_94 = F_15 ;
V_31 -> V_32 = V_3 ;
V_31 -> V_95 = 0 ;
V_31 -> V_52 = V_81 ;
for ( V_62 = 0 ; V_62 < V_81 ; V_62 ++ ) {
V_31 -> V_53 [ V_62 ] . V_56 = V_62 * V_78 ;
V_31 -> V_53 [ V_62 ] . V_96 = V_3 -> V_71 ;
}
}
for ( V_33 = 0 ; V_33 < V_80 ; V_33 ++ ) {
V_63 = F_19 ( V_3 -> V_84 [ V_33 ] , V_82 ) ;
if ( V_63 ) {
F_17 ( L_28 , V_33 , V_63 ) ;
V_3 -> V_68 = 1 ;
F_26 ( V_3 ) ;
return V_63 ;
}
F_27 ( L_29 , V_3 -> V_84 [ V_33 ] ) ;
}
V_3 -> V_68 = 1 ;
F_16 ( L_30 ) ;
return 0 ;
}
static void F_30 ( struct V_2 * V_3 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_80 ; V_33 ++ ) {
if ( V_3 -> V_84 [ V_33 ] ) {
F_27 ( L_31 , V_3 -> V_84 [ V_33 ] ) ;
F_31 ( V_3 -> V_84 [ V_33 ] ) ;
}
}
}
static void F_32 ( struct V_2 * V_3 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_80 ; V_33 ++ ) {
if ( V_3 -> V_84 [ V_33 ] ) {
F_27 ( L_32 ) ;
if ( V_3 -> V_84 [ V_33 ] -> V_55 ) {
F_33 ( V_3 -> V_61 ,
V_3 -> V_84 [ V_33 ] -> V_93 ,
V_3 -> V_84 [ V_33 ] -> V_55 ,
V_3 -> V_84 [ V_33 ] -> V_92 ) ;
}
F_34 ( V_3 -> V_84 [ V_33 ] ) ;
V_3 -> V_84 [ V_33 ] = NULL ;
}
}
}
static void F_26 ( struct V_2 * V_3 )
{
F_16 ( L_33 ) ;
if ( V_3 -> V_68 == 0 )
return;
F_30 ( V_3 ) ;
F_32 ( V_3 ) ;
F_24 ( V_3 -> V_61 , 0 , 0 ) ;
V_3 -> V_68 = 0 ;
F_16 ( L_34 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
while ( ! F_3 ( & V_3 -> V_7 ) ) {
struct V_1 * V_5 ;
V_5 = F_4 ( V_3 -> V_7 . V_9 , struct V_1 ,
V_10 ) ;
F_5 ( & V_5 -> V_10 ) ;
F_14 ( & V_5 -> V_23 , V_50 ) ;
}
}
static struct V_2 * F_36 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = F_37 ( V_98 ) ;
return F_38 ( V_100 ) ;
}
static T_1 F_39 ( struct V_97 * V_101 ,
struct V_102 * V_103 , char * V_5 )
{
struct V_2 * V_3 = F_36 ( V_101 ) ;
return sprintf ( V_5 , L_35 , V_3 -> V_104 , V_3 -> V_105 ) ;
}
static T_1 F_40 ( struct V_97 * V_101 ,
struct V_102 * V_103 ,
const char * V_5 , T_2 V_106 )
{
struct V_2 * V_3 = F_36 ( V_101 ) ;
int V_107 , V_108 ;
int V_63 = - V_109 ;
if ( strncmp ( V_5 , L_36 , 5 ) == 0 )
V_63 = F_41 ( V_3 , 0x3 ) ;
else if ( sscanf ( V_5 , L_37 , & V_107 , & V_108 ) > 0 )
V_63 = F_42 ( V_3 , V_107 , V_108 ) ;
if ( V_63 < 0 )
return V_63 ;
return strlen ( V_5 ) ;
}
static T_1 F_43 ( struct V_97 * V_101 ,
struct V_102 * V_103 , char * V_5 )
{
struct V_2 * V_3 = F_36 ( V_101 ) ;
int V_37 = V_3 -> V_12 ;
V_3 -> V_12 = 0 ;
return sprintf ( V_5 , L_38 , V_37 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_110 ;
V_110 = F_45 ( & V_3 -> V_100 . V_86 , & V_111 ) ;
if ( V_110 )
goto V_112;
if ( V_3 -> V_113 & V_114 ) {
V_110 = F_45 ( & V_3 -> V_100 . V_86 , & V_115 ) ;
if ( V_110 )
goto V_116;
}
return 0 ;
V_116:
F_46 ( & V_3 -> V_100 . V_86 , & V_111 ) ;
V_112:
F_17 ( L_39 ) ;
return V_110 ;
}
static void F_47 ( struct V_2 * V_3 )
{
if ( V_3 -> V_113 & V_114 )
F_46 ( & V_3 -> V_100 . V_86 , & V_115 ) ;
F_46 ( & V_3 -> V_100 . V_86 , & V_111 ) ;
}
static const char * F_48 ( unsigned int V_117 )
{
switch( V_117 ) {
case 0x00 :
return L_40 ;
case 0x20 :
return L_41 ;
case 0x2E :
return L_42 ;
case 0x2F :
return L_43 ;
case 0x30 :
return L_44 ;
case 0x3E :
return L_45 ;
case 0x3F :
return L_46 ;
case 0x40 :
return L_47 ;
case 0x100 :
return L_48 ;
case 0x101 :
return L_49 ;
default:
return L_50 ;
}
}
static int F_49 ( struct V_118 * V_118 )
{
struct V_99 * V_100 = F_50 ( V_118 ) ;
struct V_2 * V_3 ;
F_16 ( L_51 , V_100 ) ;
V_3 = F_38 ( V_100 ) ;
if ( ! V_3 -> V_61 )
return - V_119 ;
V_118 -> V_120 = V_100 ;
F_16 ( L_52 ) ;
return 0 ;
}
static void F_51 ( struct V_99 * V_121 )
{
struct V_2 * V_3 = F_52 ( V_121 , struct V_2 , V_100 ) ;
int V_122 ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ )
if ( V_124 [ V_122 ] . V_3 == V_3 )
V_124 [ V_122 ] . V_3 = NULL ;
if ( V_3 -> V_125 != NULL ) {
F_27 ( L_53 ,
V_3 -> V_125 ) ;
F_53 ( V_3 -> V_125 ) ;
V_3 -> V_125 = NULL ;
}
F_54 ( & V_3 -> V_126 ) ;
F_53 ( V_3 ) ;
}
static int F_55 ( struct V_118 * V_118 )
{
struct V_99 * V_100 = V_118 -> V_120 ;
struct V_2 * V_3 ;
F_16 ( L_54 , V_100 ) ;
V_3 = F_38 ( V_100 ) ;
if ( V_3 -> V_127 == V_118 ) {
F_56 ( & V_3 -> V_128 ) ;
V_3 -> V_127 = NULL ;
}
F_16 ( L_55 ) ;
return 0 ;
}
static T_1 F_57 ( struct V_118 * V_118 , char T_3 * V_5 ,
T_2 V_106 , T_4 * V_129 )
{
struct V_99 * V_100 = V_118 -> V_120 ;
struct V_2 * V_3 = F_38 ( V_100 ) ;
if ( ! V_3 -> V_61 )
return - V_119 ;
if ( V_3 -> V_127 != NULL &&
V_3 -> V_127 != V_118 )
return - V_130 ;
V_3 -> V_127 = V_118 ;
return F_58 ( & V_3 -> V_128 , V_5 , V_106 , V_129 ,
V_118 -> V_131 & V_132 ) ;
}
static unsigned int F_59 ( struct V_118 * V_118 , T_5 * V_133 )
{
struct V_99 * V_100 = V_118 -> V_120 ;
struct V_2 * V_3 = F_38 ( V_100 ) ;
if ( ! V_3 -> V_61 )
return V_134 ;
return F_60 ( & V_3 -> V_128 , V_118 , V_133 ) ;
}
static int F_61 ( struct V_118 * V_118 , struct V_135 * V_136 )
{
struct V_99 * V_100 = V_118 -> V_120 ;
struct V_2 * V_3 = F_38 ( V_100 ) ;
if ( V_3 -> V_127 != V_118 )
return - V_130 ;
return F_62 ( & V_3 -> V_128 , V_136 ) ;
}
static int F_63 ( struct V_137 * V_138 , const struct V_139 * V_140 ,
unsigned int * V_141 , unsigned int * V_142 ,
unsigned int V_143 [] , void * V_144 [] )
{
struct V_2 * V_3 = F_64 ( V_138 ) ;
if ( * V_141 < V_145 )
* V_141 = V_145 ;
else if ( * V_141 > V_146 )
* V_141 = V_146 ;
* V_142 = 1 ;
V_143 [ 0 ] = F_65 ( ( V_3 -> V_147 . V_148 * V_3 -> V_147 . V_149 * 3 ) / 2 ) ;
return 0 ;
}
static int F_66 ( struct V_150 * V_23 )
{
struct V_1 * V_5 = F_52 ( V_23 , struct V_1 , V_23 ) ;
V_5 -> V_18 = F_67 ( V_151 ) ;
if ( V_5 -> V_18 == NULL )
return - V_83 ;
return 0 ;
}
static int F_68 ( struct V_150 * V_23 )
{
struct V_2 * V_3 = F_64 ( V_23 -> V_137 ) ;
if ( ! V_3 -> V_61 )
return - V_119 ;
return 0 ;
}
static int F_69 ( struct V_150 * V_23 )
{
struct V_2 * V_3 = F_64 ( V_23 -> V_137 ) ;
struct V_1 * V_5 = F_52 ( V_23 , struct V_1 , V_23 ) ;
return F_70 ( V_3 , V_5 ) ;
}
static void F_71 ( struct V_150 * V_23 )
{
struct V_1 * V_5 = F_52 ( V_23 , struct V_1 , V_23 ) ;
F_72 ( V_5 -> V_18 ) ;
}
static void F_73 ( struct V_150 * V_23 )
{
struct V_2 * V_3 = F_64 ( V_23 -> V_137 ) ;
struct V_1 * V_5 = F_52 ( V_23 , struct V_1 , V_23 ) ;
unsigned long V_4 = 0 ;
F_2 ( & V_3 -> V_6 , V_4 ) ;
F_74 ( & V_5 -> V_10 , & V_3 -> V_7 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
}
static int F_75 ( struct V_137 * V_138 , unsigned int V_106 )
{
struct V_2 * V_3 = F_64 ( V_138 ) ;
if ( ! V_3 -> V_61 )
return - V_119 ;
F_76 ( V_3 , 1 ) ;
if ( V_3 -> V_152 ) {
F_77 ( V_3 , V_3 -> V_153 . V_148 , V_3 -> V_153 . V_149 ,
V_3 -> V_154 , V_3 -> V_155 ,
V_3 -> V_156 ) ;
}
F_78 ( V_3 , V_157 , V_158 ) ;
return F_20 ( V_3 ) ;
}
static int F_79 ( struct V_137 * V_138 )
{
struct V_2 * V_3 = F_64 ( V_138 ) ;
if ( V_3 -> V_61 ) {
F_78 ( V_3 , 0 , 0 ) ;
F_76 ( V_3 , 0 ) ;
F_26 ( V_3 ) ;
}
F_35 ( V_3 ) ;
return 0 ;
}
static void F_80 ( struct V_137 * V_138 )
{
struct V_2 * V_3 = F_64 ( V_138 ) ;
F_81 ( & V_3 -> V_159 ) ;
}
static void F_82 ( struct V_137 * V_138 )
{
struct V_2 * V_3 = F_64 ( V_138 ) ;
F_83 ( & V_3 -> V_159 ) ;
}
static int F_84 ( struct V_64 * V_65 , const struct V_160 * V_161 )
{
struct V_60 * V_61 = F_85 ( V_65 ) ;
struct V_2 * V_3 = NULL ;
int V_162 , V_163 , V_164 ;
int V_122 , V_110 ;
int V_113 = 0 ;
int V_165 = - 1 ;
int V_166 = V_152 ;
char V_167 [ 30 ] , * V_168 ;
V_162 = F_23 ( V_61 -> V_169 . V_170 ) ;
V_163 = F_23 ( V_61 -> V_169 . V_171 ) ;
F_86 ( L_56 ,
V_162 , V_163 ,
V_65 -> V_172 -> V_72 . V_173 ) ;
if ( V_65 -> V_172 -> V_72 . V_173 > 0 )
return - V_119 ;
if ( V_162 == 0x0471 ) {
switch ( V_163 ) {
case 0x0302 :
F_87 ( L_57 ) ;
V_168 = L_58 ;
V_164 = 645 ;
break;
case 0x0303 :
F_87 ( L_59 ) ;
V_168 = L_60 ;
V_164 = 646 ;
break;
case 0x0304 :
F_87 ( L_61 ) ;
V_168 = L_62 ;
V_164 = 646 ;
break;
case 0x0307 :
F_87 ( L_63 ) ;
V_168 = L_64 ;
V_164 = 675 ;
break;
case 0x0308 :
F_87 ( L_65 ) ;
V_168 = L_66 ;
V_164 = 680 ;
break;
case 0x030C :
F_87 ( L_67 ) ;
V_168 = L_68 ;
V_164 = 690 ;
break;
case 0x0310 :
F_87 ( L_69 ) ;
V_168 = L_70 ;
V_164 = 730 ;
break;
case 0x0311 :
F_87 ( L_71 ) ;
V_168 = L_72 ;
V_164 = 740 ;
break;
case 0x0312 :
F_87 ( L_73 ) ;
V_168 = L_74 ;
V_164 = 750 ;
break;
case 0x0313 :
F_87 ( L_75 ) ;
V_168 = L_76 ;
V_164 = 720 ;
break;
case 0x0329 :
F_87 ( L_77 ) ;
V_168 = L_78 ;
V_164 = 740 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x069A ) {
switch( V_163 ) {
case 0x0001 :
F_87 ( L_79 ) ;
V_168 = L_62 ;
V_164 = 645 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x046d ) {
switch( V_163 ) {
case 0x08b0 :
F_87 ( L_80 ) ;
V_168 = L_81 ;
V_164 = 740 ;
break;
case 0x08b1 :
F_87 ( L_82 ) ;
V_168 = L_83 ;
V_164 = 740 ;
break;
case 0x08b2 :
F_87 ( L_84 ) ;
V_168 = L_85 ;
V_164 = 740 ;
if ( V_166 == - 1 )
V_166 = 1 ;
break;
case 0x08b3 :
F_87 ( L_86 ) ;
V_168 = L_87 ;
V_164 = 740 ;
break;
case 0x08B4 :
F_87 ( L_88 ) ;
V_168 = L_87 ;
V_164 = 740 ;
if ( V_166 == - 1 )
V_166 = 1 ;
break;
case 0x08b5 :
F_87 ( L_89 ) ;
V_168 = L_90 ;
V_164 = 740 ;
if ( V_166 == - 1 )
V_166 = 1 ;
V_113 |= V_114 ;
break;
case 0x08b6 :
F_87 ( L_91 ) ;
V_168 = L_92 ;
V_164 = 740 ;
break;
case 0x08b7 :
F_87 ( L_93 ) ;
V_168 = L_94 ;
V_164 = 740 ;
break;
case 0x08b8 :
F_87 ( L_95 ) ;
V_168 = L_96 ;
V_164 = 730 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x055d ) {
switch( V_163 ) {
case 0x9000 :
F_87 ( L_97 ) ;
V_168 = L_98 ;
V_164 = 675 ;
break;
case 0x9001 :
F_87 ( L_99 ) ;
V_168 = L_100 ;
V_164 = 675 ;
break;
case 0x9002 :
F_87 ( L_101 ) ;
V_168 = L_100 ;
V_164 = 740 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x041e ) {
switch( V_163 ) {
case 0x400c :
F_87 ( L_102 ) ;
V_168 = L_103 ;
V_164 = 730 ;
if ( V_166 == - 1 )
V_166 = 1 ;
break;
case 0x4011 :
F_87 ( L_104 ) ;
V_168 = L_105 ;
V_164 = 740 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x04cc ) {
switch( V_163 ) {
case 0x8116 :
F_87 ( L_106 ) ;
V_168 = L_107 ;
V_164 = 730 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x06be ) {
switch( V_163 ) {
case 0x8116 :
F_87 ( L_108 ) ;
V_168 = L_109 ;
V_164 = 750 ;
break;
default:
return - V_119 ;
break;
}
}
else if ( V_162 == 0x0d81 ) {
switch( V_163 ) {
case 0x1900 :
F_87 ( L_110 ) ;
V_168 = L_111 ;
V_164 = 740 ;
break;
case 0x1910 :
F_87 ( L_112 ) ;
V_168 = L_113 ;
V_164 = 730 ;
break;
default:
return - V_119 ;
break;
}
}
else
return - V_119 ;
if ( V_166 == - 1 )
V_166 = 0 ;
memset ( V_167 , 0 , 30 ) ;
F_88 ( V_61 , V_61 -> V_169 . V_174 , V_167 , 29 ) ;
F_86 ( L_114 , V_167 ) ;
if ( V_61 -> V_169 . V_175 > 1 )
F_89 ( L_115 ) ;
V_3 = F_90 ( sizeof( struct V_2 ) , V_82 ) ;
if ( V_3 == NULL ) {
F_17 ( L_116 ) ;
return - V_83 ;
}
V_3 -> type = V_164 ;
V_3 -> V_154 = V_176 ;
strcpy ( V_3 -> V_177 , V_167 ) ;
V_3 -> V_113 = V_113 ;
if ( V_162 == 0x046D && V_163 == 0x08B5 ) {
V_3 -> V_178 . V_179 = - 7000 ;
V_3 -> V_178 . V_180 = 7000 ;
V_3 -> V_178 . V_181 = - 3000 ;
V_3 -> V_178 . V_182 = 2500 ;
}
F_91 ( V_3 ) ;
F_92 ( & V_3 -> V_159 ) ;
F_92 ( & V_3 -> V_183 ) ;
F_93 ( & V_3 -> V_6 ) ;
F_94 ( & V_3 -> V_7 ) ;
V_3 -> V_61 = V_61 ;
V_3 -> V_155 = V_184 ;
V_3 -> V_152 = V_166 ;
memset ( & V_3 -> V_128 , 0 , sizeof( V_3 -> V_128 ) ) ;
V_3 -> V_128 . type = V_185 ;
V_3 -> V_128 . V_186 = V_187 | V_188 | V_189 ;
V_3 -> V_128 . V_190 = V_3 ;
V_3 -> V_128 . V_191 = sizeof( struct V_1 ) ;
V_3 -> V_128 . V_192 = & V_193 ;
V_3 -> V_128 . V_194 = & V_195 ;
F_95 ( & V_3 -> V_128 ) ;
memcpy ( & V_3 -> V_100 , & V_196 , sizeof( V_196 ) ) ;
V_3 -> V_100 . V_197 = & V_65 -> V_86 ;
V_3 -> V_100 . V_198 = & V_3 -> V_159 ;
strcpy ( V_3 -> V_100 . V_168 , V_168 ) ;
F_96 ( & V_3 -> V_100 , V_3 ) ;
V_3 -> V_199 = F_23 ( V_61 -> V_169 . V_200 ) ;
F_86 ( L_117 , V_3 -> V_199 ) ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ ) {
if ( ( ( V_124 [ V_122 ] . type == - 1 ) || ( V_124 [ V_122 ] . type == V_3 -> type ) ) &&
( V_124 [ V_122 ] . V_3 == NULL ) ) {
if ( ( V_124 [ V_122 ] . V_167 [ 0 ] == '*' ) || ! strcmp ( V_124 [ V_122 ] . V_167 , V_167 ) ) {
V_165 = V_124 [ V_122 ] . V_201 ;
F_86 ( L_118 , V_165 ) ;
break;
}
}
}
if ( V_122 < V_123 )
V_124 [ V_122 ] . V_3 = V_3 ;
F_86 ( L_119 , V_3 ) ;
F_97 ( V_65 , V_3 ) ;
#ifdef F_98
if ( F_99 ( V_3 , & V_110 ) >= 0 ) {
F_16 ( L_120 ,
V_3 -> V_100 . V_168 ,
F_48 ( V_110 ) , V_110 ) ;
}
#endif
F_78 ( V_3 , 0 , 0 ) ;
V_110 = F_77 ( V_3 , V_3 -> V_202 . V_148 , V_3 -> V_202 . V_149 ,
V_3 -> V_154 , V_3 -> V_155 , 0 ) ;
if ( V_110 )
goto V_203;
V_110 = F_100 ( V_3 ) ;
if ( V_110 ) {
F_17 ( L_121 , V_110 ) ;
goto V_203;
}
V_3 -> V_100 . V_126 = & V_3 -> V_126 ;
F_76 ( V_3 , 0 ) ;
V_110 = F_101 ( & V_3 -> V_100 , V_204 , V_165 ) ;
if ( V_110 < 0 ) {
F_17 ( L_122 , V_110 ) ;
goto V_205;
}
V_110 = F_44 ( V_3 ) ;
if ( V_110 )
goto V_206;
F_87 ( L_123 , F_102 ( & V_3 -> V_100 ) ) ;
#ifdef F_9
V_3 -> V_13 = F_103 () ;
if ( ! V_3 -> V_13 ) {
F_17 ( L_124 ) ;
V_110 = - V_83 ;
F_47 ( V_3 ) ;
goto V_206;
}
F_104 ( V_61 , V_3 -> V_207 , sizeof( V_3 -> V_207 ) ) ;
F_105 ( V_3 -> V_207 , L_125 , sizeof( V_3 -> V_207 ) ) ;
V_3 -> V_13 -> V_168 = L_126 ;
V_3 -> V_13 -> V_208 = V_3 -> V_207 ;
F_106 ( V_3 -> V_61 , & V_3 -> V_13 -> V_161 ) ;
V_3 -> V_13 -> V_86 . V_197 = & V_3 -> V_61 -> V_86 ;
V_3 -> V_13 -> V_209 [ 0 ] = F_107 ( V_210 ) ;
V_3 -> V_13 -> V_211 [ F_108 ( V_14 ) ] = F_107 ( V_14 ) ;
V_110 = F_109 ( V_3 -> V_13 ) ;
if ( V_110 ) {
F_110 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_47 ( V_3 ) ;
goto V_206;
}
#endif
return 0 ;
V_206:
if ( V_122 < V_123 )
V_124 [ V_122 ] . V_3 = NULL ;
F_111 ( & V_3 -> V_100 ) ;
V_205:
F_54 ( & V_3 -> V_126 ) ;
V_203:
F_97 ( V_65 , NULL ) ;
F_53 ( V_3 ) ;
return V_110 ;
}
static void F_112 ( struct V_64 * V_65 )
{
struct V_2 * V_3 = F_113 ( V_65 ) ;
F_81 ( & V_3 -> V_183 ) ;
F_81 ( & V_3 -> V_159 ) ;
F_97 ( V_65 , NULL ) ;
F_26 ( V_3 ) ;
F_35 ( V_3 ) ;
V_3 -> V_61 = NULL ;
F_83 ( & V_3 -> V_159 ) ;
F_83 ( & V_3 -> V_183 ) ;
F_47 ( V_3 ) ;
F_111 ( & V_3 -> V_100 ) ;
#ifdef F_9
if ( V_3 -> V_13 )
F_114 ( V_3 -> V_13 ) ;
#endif
}
static int T_6 F_115 ( void )
{
int V_33 ;
#ifdef F_98
F_87 ( L_127 V_212 L_128 ) ;
F_87 ( L_129 ) ;
F_87 ( L_130 ) ;
F_87 ( L_131 ) ;
if ( V_213 >= 0 ) {
F_116 ( L_132 , V_213 ) ;
}
#endif
if ( V_214 ) {
if ( V_214 < 4 || V_214 > 30 ) {
F_17 ( L_133 ) ;
return - V_109 ;
}
V_176 = V_214 ;
F_116 ( L_134 , V_176 ) ;
}
if ( V_215 >= 0 ) {
if ( V_215 > 3 ) {
F_17 ( L_135 ) ;
return - V_109 ;
}
V_184 = V_215 ;
F_116 ( L_136 , V_184 ) ;
}
if ( V_216 [ 0 ] >= 0 )
V_157 = V_216 [ 0 ] ;
if ( V_216 [ 1 ] >= 0 )
V_158 = V_216 [ 1 ] ;
for ( V_33 = 0 ; V_33 < V_123 ; V_33 ++ ) {
char * V_217 , * V_218 , * V_219 ;
V_124 [ V_33 ] . V_3 = NULL ;
V_217 = V_220 [ V_33 ] ;
if ( V_217 != NULL && * V_217 != '\0' ) {
V_124 [ V_33 ] . type = - 1 ;
strcpy ( V_124 [ V_33 ] . V_167 , L_137 ) ;
V_218 = V_219 = V_217 ;
while ( * V_218 != '\0' && * V_218 != ':' )
V_218 ++ ;
while ( * V_219 != '\0' && * V_219 != '.' )
V_219 ++ ;
if ( * V_219 != '\0' && V_219 > V_218 ) {
F_17 ( L_138 ) ;
return - V_109 ;
}
if ( * V_218 == '\0' ) {
if ( * V_219 != '\0' ) {
F_17 ( L_139 ) ;
return - V_109 ;
}
else {
V_124 [ V_33 ] . V_201 =
F_117 ( V_217 , NULL , 10 ) ;
}
}
else {
V_124 [ V_33 ] . type =
F_117 ( V_217 , NULL , 10 ) ;
V_124 [ V_33 ] . V_201 =
F_117 ( V_218 + 1 , NULL , 10 ) ;
if ( * V_219 != '\0' ) {
int V_221 ;
V_219 ++ ;
V_221 = 0 ;
while ( * V_219 != ':' && V_221 < 29 ) {
V_124 [ V_33 ] . V_167 [ V_221 ++ ] = * V_219 ;
V_219 ++ ;
}
V_124 [ V_33 ] . V_167 [ V_221 ] = '\0' ;
}
}
F_8 ( L_140 , V_33 ) ;
F_8 ( L_141 , V_124 [ V_33 ] . type ) ;
F_8 ( L_142 , V_124 [ V_33 ] . V_167 ) ;
F_8 ( L_143 , V_124 [ V_33 ] . V_201 ) ;
}
else
V_124 [ V_33 ] . type = 0 ;
}
F_86 ( L_144 , & V_222 ) ;
return F_118 ( & V_222 ) ;
}
static void T_7 F_119 ( void )
{
F_116 ( L_145 ) ;
F_120 ( & V_222 ) ;
F_87 ( L_146 ) ;
}
