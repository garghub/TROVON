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
} else {
F_8 ( L_2 ) ;
}
#ifdef F_9
if ( V_3 -> V_12 ) {
F_10 ( V_3 -> V_12 , V_13 , V_11 ) ;
F_11 ( V_3 -> V_12 ) ;
}
#endif
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_14 = V_3 -> V_15 ;
if ( V_3 -> type == 730 ) {
unsigned char * V_16 = ( unsigned char * ) V_14 -> V_17 ;
if ( V_16 [ 1 ] == 1 && V_16 [ 0 ] & 0x10 ) {
F_8 ( L_3 ) ;
V_3 -> V_18 += 2 ;
}
if ( ( V_16 [ 0 ] ^ V_3 -> V_19 ) & 0x01 ) {
F_7 ( V_3 , V_16 [ 0 ] & 0x01 ) ;
}
if ( ( V_16 [ 0 ] ^ V_3 -> V_19 ) & 0x02 ) {
if ( V_16 [ 0 ] & 0x02 )
F_8 ( L_4 ) ;
else
F_8 ( L_5 ) ;
}
V_3 -> V_19 = V_16 [ 0 ] & 0x03 ;
if ( V_14 -> V_20 == 4 )
V_3 -> V_18 ++ ;
} else if ( V_3 -> type == 740 || V_3 -> type == 720 ) {
unsigned char * V_16 = ( unsigned char * ) V_14 -> V_17 ;
if ( ( V_16 [ 0 ] ^ V_3 -> V_19 ) & 0x01 ) {
F_7 ( V_3 , V_16 [ 0 ] & 0x01 ) ;
}
V_3 -> V_19 = V_16 [ 0 ] & 0x03 ;
}
if ( V_3 -> V_18 > 0 ) {
V_3 -> V_18 -- ;
} else {
if ( V_14 -> V_20 < V_3 -> V_21 ) {
F_13 ( L_6
L_7 , V_14 -> V_20 ) ;
} else {
V_14 -> V_22 . V_23 . V_24 = V_25 ;
V_14 -> V_22 . V_23 . V_26 = V_3 -> V_27 ;
F_14 ( & V_14 -> V_22 , V_28 ) ;
V_3 -> V_15 = NULL ;
V_3 -> V_29 = 0 ;
}
}
V_3 -> V_27 ++ ;
}
static void F_15 ( struct V_30 * V_30 )
{
struct V_2 * V_3 = (struct V_2 * ) V_30 -> V_31 ;
int V_32 , V_33 , V_34 ;
unsigned char * V_35 = NULL ;
if ( V_30 -> V_36 == - V_37 || V_30 -> V_36 == - V_38 ||
V_30 -> V_36 == - V_39 ) {
F_16 ( L_8 , V_30 , V_30 -> V_36 == - V_37 ? L_9 : L_10 ) ;
return;
}
if ( V_3 -> V_15 == NULL )
V_3 -> V_15 = F_1 ( V_3 ) ;
if ( V_30 -> V_36 != 0 ) {
const char * V_40 ;
V_40 = L_11 ;
switch( V_30 -> V_36 ) {
case - V_41 : V_40 = L_12 ; break;
case - V_42 : V_40 = L_13 ; break;
case - V_43 : V_40 = L_14 ; break;
case - V_44 : V_40 = L_15 ; break;
case - V_45 : V_40 = L_16 ; break;
case - V_46 : V_40 = L_17 ; break;
}
F_17 ( L_18 ,
V_30 -> V_36 , V_40 ) ;
if ( ++ V_3 -> V_47 > V_48 )
{
F_17 ( L_19 ) ;
if ( V_3 -> V_15 ) {
F_14 ( & V_3 -> V_15 -> V_22 ,
V_49 ) ;
V_3 -> V_15 = NULL ;
}
}
V_3 -> V_29 = 0 ;
goto V_50;
}
V_3 -> V_47 = 0 ;
for ( V_32 = 0 ; V_32 < V_30 -> V_51 ; V_32 ++ ) {
V_33 = V_30 -> V_52 [ V_32 ] . V_36 ;
V_34 = V_30 -> V_52 [ V_32 ] . V_53 ;
V_35 = V_30 -> V_54 + V_30 -> V_52 [ V_32 ] . V_55 ;
if ( V_33 != 0 ) {
F_17 ( L_20 , V_32 , V_33 ) ;
continue;
}
if ( V_34 > 0 && V_3 -> V_29 ) {
struct V_1 * V_14 = V_3 -> V_15 ;
if ( V_3 -> V_29 == 1 ) {
F_18 ( & V_14 -> V_22 . V_23 . V_56 ) ;
V_3 -> V_29 = 2 ;
}
if ( V_34 + V_14 -> V_20 > V_3 -> V_21 ) {
F_17 ( L_21 ,
V_34 + V_14 -> V_20 ,
V_3 -> V_21 ) ;
V_3 -> V_29 = 0 ;
} else {
memcpy ( V_14 -> V_17 + V_14 -> V_20 , V_35 ,
V_34 ) ;
V_14 -> V_20 += V_34 ;
}
}
if ( V_34 < V_3 -> V_57 ) {
if ( V_3 -> V_29 == 2 )
F_12 ( V_3 ) ;
if ( V_3 -> V_15 == NULL )
V_3 -> V_15 = F_1 ( V_3 ) ;
if ( V_3 -> V_15 ) {
V_3 -> V_15 -> V_20 = 0 ;
V_3 -> V_29 = 1 ;
}
}
V_3 -> V_57 = V_34 ;
}
V_50:
V_32 = F_19 ( V_30 , V_58 ) ;
if ( V_32 != 0 )
F_17 ( L_22 , V_32 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_59 * V_60 ;
struct V_30 * V_30 ;
int V_32 , V_61 , V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 = NULL ;
int V_67 = 0 ;
V_3 -> V_29 = 0 ;
V_3 -> V_57 = 0 ;
V_3 -> V_15 = NULL ;
V_3 -> V_27 = 0 ;
V_3 -> V_47 = 0 ;
V_60 = V_3 -> V_60 ;
V_68:
V_62 = F_21 ( V_3 , V_3 -> V_69 , V_3 -> V_70 , V_3 -> V_71 ,
V_3 -> V_72 , & V_67 , 1 ) ;
V_64 = F_22 ( V_60 , 0 ) ;
if ( V_64 )
V_66 = F_23 ( V_64 , V_3 -> V_73 ) ;
if ( ! V_66 )
return - V_74 ;
V_3 -> V_75 = - 1 ;
for ( V_32 = 0 ; V_32 < V_66 -> V_76 . V_77 ; V_32 ++ ) {
if ( ( V_66 -> V_78 [ V_32 ] . V_76 . V_79 & 0xF ) == V_3 -> V_80 ) {
V_3 -> V_75 = F_24 ( V_66 -> V_78 [ V_32 ] . V_76 . V_81 ) ;
break;
}
}
if ( V_3 -> V_75 < 0 || V_3 -> V_75 > V_82 ) {
F_17 ( L_23 ) ;
return - V_83 ;
}
F_16 ( L_24 , V_3 -> V_73 ) ;
V_62 = F_25 ( V_3 -> V_60 , 0 , V_3 -> V_73 ) ;
if ( V_62 == - V_84 && V_67 < 3 ) {
V_67 ++ ;
goto V_68;
}
if ( V_62 < 0 )
return V_62 ;
for ( V_32 = 0 ; V_32 < V_85 ; V_32 ++ ) {
V_30 = F_26 ( V_86 , V_87 ) ;
if ( V_30 == NULL ) {
F_17 ( L_25 , V_32 ) ;
F_27 ( V_3 ) ;
return - V_88 ;
}
V_3 -> V_89 [ V_32 ] = V_30 ;
F_28 ( L_26 , V_30 ) ;
V_30 -> V_90 = 1 ;
V_30 -> V_91 = V_60 ;
V_30 -> V_92 = F_29 ( V_60 , V_3 -> V_80 ) ;
V_30 -> V_93 = V_94 | V_95 ;
V_30 -> V_54 = F_30 ( V_60 ,
V_96 ,
V_87 ,
& V_30 -> V_97 ) ;
if ( V_30 -> V_54 == NULL ) {
F_17 ( L_27 , V_32 ) ;
F_27 ( V_3 ) ;
return - V_88 ;
}
V_30 -> V_98 = V_96 ;
V_30 -> V_99 = F_15 ;
V_30 -> V_31 = V_3 ;
V_30 -> V_100 = 0 ;
V_30 -> V_51 = V_86 ;
for ( V_61 = 0 ; V_61 < V_86 ; V_61 ++ ) {
V_30 -> V_52 [ V_61 ] . V_55 = V_61 * V_82 ;
V_30 -> V_52 [ V_61 ] . V_101 = V_3 -> V_75 ;
}
}
for ( V_32 = 0 ; V_32 < V_85 ; V_32 ++ ) {
V_62 = F_19 ( V_3 -> V_89 [ V_32 ] , V_87 ) ;
if ( V_62 == - V_84 && V_67 < 3 ) {
V_67 ++ ;
F_27 ( V_3 ) ;
goto V_68;
}
if ( V_62 ) {
F_17 ( L_28 , V_32 , V_62 ) ;
F_27 ( V_3 ) ;
return V_62 ;
}
F_28 ( L_29 , V_3 -> V_89 [ V_32 ] ) ;
}
F_16 ( L_30 ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_85 ; V_32 ++ ) {
if ( V_3 -> V_89 [ V_32 ] ) {
F_28 ( L_31 , V_3 -> V_89 [ V_32 ] ) ;
F_32 ( V_3 -> V_89 [ V_32 ] ) ;
}
}
}
static void F_33 ( struct V_2 * V_3 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_85 ; V_32 ++ ) {
if ( V_3 -> V_89 [ V_32 ] ) {
F_28 ( L_32 ) ;
if ( V_3 -> V_89 [ V_32 ] -> V_54 ) {
F_34 ( V_3 -> V_60 ,
V_3 -> V_89 [ V_32 ] -> V_98 ,
V_3 -> V_89 [ V_32 ] -> V_54 ,
V_3 -> V_89 [ V_32 ] -> V_97 ) ;
}
F_35 ( V_3 -> V_89 [ V_32 ] ) ;
V_3 -> V_89 [ V_32 ] = NULL ;
}
}
}
static void F_27 ( struct V_2 * V_3 )
{
F_16 ( L_33 ) ;
F_31 ( V_3 ) ;
F_33 ( V_3 ) ;
F_25 ( V_3 -> V_60 , 0 , 0 ) ;
F_16 ( L_34 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
unsigned long V_4 = 0 ;
F_2 ( & V_3 -> V_6 , V_4 ) ;
while ( ! F_3 ( & V_3 -> V_7 ) ) {
struct V_1 * V_5 ;
V_5 = F_4 ( V_3 -> V_7 . V_9 , struct V_1 ,
V_10 ) ;
F_5 ( & V_5 -> V_10 ) ;
F_14 ( & V_5 -> V_22 , V_49 ) ;
}
F_6 ( & V_3 -> V_6 , V_4 ) ;
}
static const char * F_37 ( unsigned int V_102 )
{
switch( V_102 ) {
case 0x00 :
return L_35 ;
case 0x20 :
return L_36 ;
case 0x2E :
return L_37 ;
case 0x2F :
return L_38 ;
case 0x30 :
return L_39 ;
case 0x3E :
return L_40 ;
case 0x3F :
return L_41 ;
case 0x40 :
return L_42 ;
case 0x100 :
return L_43 ;
case 0x101 :
return L_44 ;
default:
return L_45 ;
}
}
int F_38 ( struct V_2 * V_3 , struct V_103 * V_103 )
{
if ( V_3 -> V_104 != NULL &&
V_3 -> V_104 != V_103 )
return - V_105 ;
V_3 -> V_104 = V_103 ;
return 0 ;
}
static void F_39 ( struct V_106 * V_107 )
{
struct V_2 * V_3 = F_40 ( V_107 , struct V_2 , V_108 ) ;
F_41 ( & V_3 -> V_109 ) ;
F_42 ( & V_3 -> V_108 ) ;
F_43 ( V_3 -> V_110 ) ;
F_43 ( V_3 ) ;
}
static int F_44 ( struct V_103 * V_103 )
{
struct V_2 * V_3 = F_45 ( V_103 ) ;
if ( F_46 ( & V_3 -> V_111 ) )
return - V_112 ;
if ( F_46 ( & V_3 -> V_113 ) ) {
F_47 ( & V_3 -> V_111 ) ;
return - V_112 ;
}
if ( V_3 -> V_104 == V_103 ) {
F_48 ( & V_3 -> V_114 ) ;
V_3 -> V_104 = NULL ;
}
F_47 ( & V_3 -> V_113 ) ;
F_47 ( & V_3 -> V_111 ) ;
return F_49 ( V_103 ) ;
}
static T_1 F_50 ( struct V_103 * V_103 , char T_2 * V_5 ,
T_3 V_115 , T_4 * V_116 )
{
struct V_2 * V_3 = F_45 ( V_103 ) ;
int V_117 = 0 ;
T_1 V_62 ;
if ( F_46 ( & V_3 -> V_113 ) )
return - V_112 ;
V_62 = F_38 ( V_3 , V_103 ) ;
if ( V_62 )
goto V_118;
if ( V_3 -> V_114 . V_119 == NULL )
V_117 = 1 ;
if ( V_117 && ! F_51 ( & V_3 -> V_111 ) ) {
V_62 = - V_112 ;
goto V_118;
}
V_62 = F_52 ( & V_3 -> V_114 , V_5 , V_115 , V_116 ,
V_103 -> V_120 & V_121 ) ;
if ( V_117 )
F_47 ( & V_3 -> V_111 ) ;
V_118:
F_47 ( & V_3 -> V_113 ) ;
return V_62 ;
}
static unsigned int F_53 ( struct V_103 * V_103 , T_5 * V_122 )
{
struct V_2 * V_3 = F_45 ( V_103 ) ;
struct V_123 * V_124 = & V_3 -> V_114 ;
unsigned long V_125 = F_54 ( V_122 ) ;
unsigned int V_62 = V_126 ;
int V_117 = 0 ;
if ( F_46 ( & V_3 -> V_113 ) )
return V_126 ;
if ( ( V_125 & ( V_127 | V_128 ) ) &&
V_124 -> V_129 == 0 && ! V_124 -> V_130 && V_124 -> V_119 == NULL ) {
if ( F_38 ( V_3 , V_103 ) )
goto V_118;
V_117 = 1 ;
}
if ( V_117 && ! F_51 ( & V_3 -> V_111 ) )
goto V_118;
V_62 = F_55 ( & V_3 -> V_114 , V_103 , V_122 ) ;
if ( V_117 )
F_47 ( & V_3 -> V_111 ) ;
V_118:
if ( ! V_3 -> V_60 )
V_62 |= V_131 ;
F_47 ( & V_3 -> V_113 ) ;
return V_62 ;
}
static int F_56 ( struct V_103 * V_103 , struct V_132 * V_133 )
{
struct V_2 * V_3 = F_45 ( V_103 ) ;
int V_62 ;
if ( F_46 ( & V_3 -> V_113 ) )
return - V_112 ;
V_62 = F_38 ( V_3 , V_103 ) ;
if ( V_62 == 0 )
V_62 = F_57 ( & V_3 -> V_114 , V_133 ) ;
F_47 ( & V_3 -> V_113 ) ;
return V_62 ;
}
static int F_58 ( struct V_123 * V_134 , const struct V_135 * V_136 ,
unsigned int * V_137 , unsigned int * V_138 ,
unsigned int V_139 [] , void * V_140 [] )
{
struct V_2 * V_3 = F_59 ( V_134 ) ;
int V_141 ;
if ( * V_137 < V_142 )
* V_137 = V_142 ;
else if ( * V_137 > V_143 )
* V_137 = V_143 ;
* V_138 = 1 ;
V_141 = F_60 ( V_3 , V_144 , V_145 ) ;
V_139 [ 0 ] = F_61 ( V_146 [ V_141 ] [ 0 ] *
V_146 [ V_141 ] [ 1 ] * 3 / 2 ) ;
return 0 ;
}
static int F_62 ( struct V_147 * V_22 )
{
struct V_1 * V_5 = F_40 ( V_22 , struct V_1 , V_22 ) ;
V_5 -> V_17 = F_63 ( V_148 ) ;
if ( V_5 -> V_17 == NULL )
return - V_88 ;
return 0 ;
}
static int F_64 ( struct V_147 * V_22 )
{
struct V_2 * V_3 = F_59 ( V_22 -> V_123 ) ;
if ( ! V_3 -> V_60 )
return - V_149 ;
return 0 ;
}
static int F_65 ( struct V_147 * V_22 )
{
struct V_2 * V_3 = F_59 ( V_22 -> V_123 ) ;
struct V_1 * V_5 = F_40 ( V_22 , struct V_1 , V_22 ) ;
return F_66 ( V_3 , V_5 ) ;
}
static void F_67 ( struct V_147 * V_22 )
{
struct V_1 * V_5 = F_40 ( V_22 , struct V_1 , V_22 ) ;
F_68 ( V_5 -> V_17 ) ;
}
static void F_69 ( struct V_147 * V_22 )
{
struct V_2 * V_3 = F_59 ( V_22 -> V_123 ) ;
struct V_1 * V_5 = F_40 ( V_22 , struct V_1 , V_22 ) ;
unsigned long V_4 = 0 ;
if ( ! V_3 -> V_60 ) {
F_14 ( & V_5 -> V_22 , V_49 ) ;
return;
}
F_2 ( & V_3 -> V_6 , V_4 ) ;
F_70 ( & V_5 -> V_10 , & V_3 -> V_7 ) ;
F_6 ( & V_3 -> V_6 , V_4 ) ;
}
static int F_71 ( struct V_123 * V_134 , unsigned int V_115 )
{
struct V_2 * V_3 = F_59 ( V_134 ) ;
int V_150 ;
if ( ! V_3 -> V_60 )
return - V_149 ;
F_72 ( V_3 , 1 ) ;
F_73 ( V_3 , V_151 [ 0 ] , V_151 [ 1 ] ) ;
V_150 = F_20 ( V_3 ) ;
if ( V_150 ) {
F_73 ( V_3 , 0 , 0 ) ;
F_72 ( V_3 , 0 ) ;
F_36 ( V_3 ) ;
}
return V_150 ;
}
static int F_74 ( struct V_123 * V_134 )
{
struct V_2 * V_3 = F_59 ( V_134 ) ;
if ( V_3 -> V_60 ) {
F_73 ( V_3 , 0 , 0 ) ;
F_72 ( V_3 , 0 ) ;
F_27 ( V_3 ) ;
}
F_36 ( V_3 ) ;
return 0 ;
}
static void F_75 ( struct V_123 * V_134 )
{
struct V_2 * V_3 = F_59 ( V_134 ) ;
F_47 ( & V_3 -> V_113 ) ;
}
static void F_76 ( struct V_123 * V_134 )
{
struct V_2 * V_3 = F_59 ( V_134 ) ;
F_77 ( & V_3 -> V_113 ) ;
}
static int F_78 ( struct V_63 * V_64 , const struct V_152 * V_153 )
{
struct V_59 * V_60 = F_79 ( V_64 ) ;
struct V_2 * V_3 = NULL ;
int V_154 , V_155 , V_156 ;
int V_157 ;
int V_158 = 0 ;
int V_67 = 0 ;
int V_159 = V_160 ;
char V_161 [ 30 ] , * V_162 ;
V_154 = F_24 ( V_60 -> V_163 . V_164 ) ;
V_155 = F_24 ( V_60 -> V_163 . V_165 ) ;
F_80 ( L_46 ,
V_154 , V_155 ,
V_64 -> V_166 -> V_76 . V_167 ) ;
if ( V_64 -> V_166 -> V_76 . V_167 > 0 )
return - V_149 ;
if ( V_154 == 0x0471 ) {
switch ( V_155 ) {
case 0x0302 :
F_81 ( L_47 ) ;
V_162 = L_48 ;
V_156 = 645 ;
break;
case 0x0303 :
F_81 ( L_49 ) ;
V_162 = L_50 ;
V_156 = 646 ;
break;
case 0x0304 :
F_81 ( L_51 ) ;
V_162 = L_52 ;
V_156 = 646 ;
break;
case 0x0307 :
F_81 ( L_53 ) ;
V_162 = L_54 ;
V_156 = 675 ;
break;
case 0x0308 :
F_81 ( L_55 ) ;
V_162 = L_56 ;
V_156 = 680 ;
break;
case 0x030C :
F_81 ( L_57 ) ;
V_162 = L_58 ;
V_156 = 690 ;
break;
case 0x0310 :
F_81 ( L_59 ) ;
V_162 = L_60 ;
V_156 = 730 ;
break;
case 0x0311 :
F_81 ( L_61 ) ;
V_162 = L_62 ;
V_156 = 740 ;
break;
case 0x0312 :
F_81 ( L_63 ) ;
V_162 = L_64 ;
V_156 = 750 ;
break;
case 0x0313 :
F_81 ( L_65 ) ;
V_162 = L_66 ;
V_156 = 720 ;
break;
case 0x0329 :
F_81 ( L_67 ) ;
V_162 = L_68 ;
V_156 = 740 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x069A ) {
switch( V_155 ) {
case 0x0001 :
F_81 ( L_69 ) ;
V_162 = L_52 ;
V_156 = 645 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x046d ) {
switch( V_155 ) {
case 0x08b0 :
F_81 ( L_70 ) ;
V_162 = L_71 ;
V_156 = 740 ;
break;
case 0x08b1 :
F_81 ( L_72 ) ;
V_162 = L_73 ;
V_156 = 740 ;
break;
case 0x08b2 :
F_81 ( L_74 ) ;
V_162 = L_75 ;
V_156 = 740 ;
if ( V_159 == - 1 )
V_159 = 1 ;
break;
case 0x08b3 :
F_81 ( L_76 ) ;
V_162 = L_77 ;
V_156 = 740 ;
break;
case 0x08B4 :
F_81 ( L_78 ) ;
V_162 = L_77 ;
V_156 = 740 ;
if ( V_159 == - 1 )
V_159 = 1 ;
break;
case 0x08b5 :
F_81 ( L_79 ) ;
V_162 = L_80 ;
V_156 = 740 ;
if ( V_159 == - 1 )
V_159 = 1 ;
V_158 |= V_168 ;
break;
case 0x08b6 :
F_81 ( L_81 ) ;
V_162 = L_82 ;
V_156 = 740 ;
break;
case 0x08b7 :
F_81 ( L_83 ) ;
V_162 = L_84 ;
V_156 = 740 ;
break;
case 0x08b8 :
F_81 ( L_85 ) ;
V_162 = L_86 ;
V_156 = 730 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x055d ) {
switch( V_155 ) {
case 0x9000 :
F_81 ( L_87 ) ;
V_162 = L_88 ;
V_156 = 675 ;
break;
case 0x9001 :
F_81 ( L_89 ) ;
V_162 = L_90 ;
V_156 = 675 ;
break;
case 0x9002 :
F_81 ( L_91 ) ;
V_162 = L_90 ;
V_156 = 740 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x041e ) {
switch( V_155 ) {
case 0x400c :
F_81 ( L_92 ) ;
V_162 = L_93 ;
V_156 = 730 ;
if ( V_159 == - 1 )
V_159 = 1 ;
break;
case 0x4011 :
F_81 ( L_94 ) ;
V_162 = L_95 ;
V_156 = 740 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x04cc ) {
switch( V_155 ) {
case 0x8116 :
F_81 ( L_96 ) ;
V_162 = L_97 ;
V_156 = 730 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x06be ) {
switch( V_155 ) {
case 0x8116 :
F_81 ( L_98 ) ;
V_162 = L_99 ;
V_156 = 750 ;
break;
default:
return - V_149 ;
break;
}
}
else if ( V_154 == 0x0d81 ) {
switch( V_155 ) {
case 0x1900 :
F_81 ( L_100 ) ;
V_162 = L_101 ;
V_156 = 740 ;
break;
case 0x1910 :
F_81 ( L_102 ) ;
V_162 = L_103 ;
V_156 = 730 ;
break;
default:
return - V_149 ;
break;
}
}
else
return - V_149 ;
if ( V_159 == - 1 )
V_159 = 0 ;
memset ( V_161 , 0 , 30 ) ;
F_82 ( V_60 , V_60 -> V_163 . V_169 , V_161 , 29 ) ;
F_80 ( L_104 , V_161 ) ;
if ( V_60 -> V_163 . V_170 > 1 )
F_83 ( L_105 ) ;
V_3 = F_84 ( sizeof( struct V_2 ) , V_87 ) ;
if ( V_3 == NULL ) {
F_17 ( L_106 ) ;
return - V_88 ;
}
V_3 -> type = V_156 ;
V_3 -> V_158 = V_158 ;
F_85 ( V_3 ) ;
F_86 ( & V_3 -> V_111 ) ;
F_86 ( & V_3 -> V_113 ) ;
F_87 ( & V_3 -> V_6 ) ;
F_88 ( & V_3 -> V_7 ) ;
V_3 -> V_60 = V_60 ;
V_3 -> V_160 = V_159 ;
memset ( & V_3 -> V_114 , 0 , sizeof( V_3 -> V_114 ) ) ;
V_3 -> V_114 . type = V_171 ;
V_3 -> V_114 . V_172 = V_173 | V_174 | V_175 ;
V_3 -> V_114 . V_176 = V_3 ;
V_3 -> V_114 . V_177 = sizeof( struct V_1 ) ;
V_3 -> V_114 . V_178 = & V_179 ;
V_3 -> V_114 . V_180 = & V_181 ;
F_89 ( & V_3 -> V_114 ) ;
memcpy ( & V_3 -> V_182 , & V_183 , sizeof( V_183 ) ) ;
strcpy ( V_3 -> V_182 . V_162 , V_162 ) ;
F_90 ( V_184 , & V_3 -> V_182 . V_4 ) ;
F_91 ( & V_3 -> V_182 , V_3 ) ;
V_3 -> V_185 = F_24 ( V_60 -> V_163 . V_186 ) ;
F_80 ( L_107 , V_3 -> V_185 ) ;
V_3 -> V_110 = F_92 ( sizeof( V_3 -> V_187 ) , V_87 ) ;
if ( ! V_3 -> V_110 ) {
F_17 ( L_106 ) ;
V_157 = - V_88 ;
goto V_188;
}
#ifdef F_93
if ( F_94 ( V_3 , & V_157 ) >= 0 ) {
F_16 ( L_108 ,
V_3 -> V_182 . V_162 ,
F_37 ( V_157 ) , V_157 ) ;
}
#endif
F_73 ( V_3 , 0 , 0 ) ;
V_157 = F_21 ( V_3 , V_144 , V_145 ,
V_189 , 30 , & V_67 , 1 ) ;
if ( V_157 )
goto V_188;
V_157 = F_95 ( V_3 ) ;
if ( V_157 ) {
F_17 ( L_109 , V_157 ) ;
goto V_188;
}
F_72 ( V_3 , 0 ) ;
V_3 -> V_108 . V_185 = F_39 ;
V_157 = F_96 ( & V_64 -> V_91 , & V_3 -> V_108 ) ;
if ( V_157 ) {
F_17 ( L_110 , V_157 ) ;
goto V_190;
}
V_3 -> V_108 . V_109 = & V_3 -> V_109 ;
V_3 -> V_182 . V_108 = & V_3 -> V_108 ;
V_3 -> V_182 . V_191 = & V_3 -> V_111 ;
F_97 ( & V_3 -> V_182 , V_192 ) ;
F_97 ( & V_3 -> V_182 , V_193 ) ;
F_97 ( & V_3 -> V_182 , V_194 ) ;
V_157 = F_98 ( & V_3 -> V_182 , V_195 , - 1 ) ;
if ( V_157 < 0 ) {
F_17 ( L_111 , V_157 ) ;
goto V_196;
}
F_81 ( L_112 , F_99 ( & V_3 -> V_182 ) ) ;
#ifdef F_9
V_3 -> V_12 = F_100 () ;
if ( ! V_3 -> V_12 ) {
F_17 ( L_113 ) ;
V_157 = - V_88 ;
goto V_197;
}
F_101 ( V_60 , V_3 -> V_198 , sizeof( V_3 -> V_198 ) ) ;
F_102 ( V_3 -> V_198 , L_114 , sizeof( V_3 -> V_198 ) ) ;
V_3 -> V_12 -> V_162 = L_115 ;
V_3 -> V_12 -> V_199 = V_3 -> V_198 ;
F_103 ( V_3 -> V_60 , & V_3 -> V_12 -> V_153 ) ;
V_3 -> V_12 -> V_91 . V_200 = & V_3 -> V_60 -> V_91 ;
V_3 -> V_12 -> V_201 [ 0 ] = F_104 ( V_202 ) ;
V_3 -> V_12 -> V_203 [ F_105 ( V_13 ) ] = F_104 ( V_13 ) ;
V_157 = F_106 ( V_3 -> V_12 ) ;
if ( V_157 ) {
F_107 ( V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
goto V_197;
}
#endif
return 0 ;
V_197:
F_108 ( & V_3 -> V_182 ) ;
V_196:
F_42 ( & V_3 -> V_108 ) ;
V_190:
F_41 ( & V_3 -> V_109 ) ;
V_188:
F_43 ( V_3 -> V_110 ) ;
F_43 ( V_3 ) ;
return V_157 ;
}
static void F_109 ( struct V_63 * V_64 )
{
struct V_106 * V_107 = F_110 ( V_64 ) ;
struct V_2 * V_3 = F_40 ( V_107 , struct V_2 , V_108 ) ;
F_77 ( & V_3 -> V_111 ) ;
F_77 ( & V_3 -> V_113 ) ;
if ( V_3 -> V_114 . V_130 )
F_27 ( V_3 ) ;
V_3 -> V_60 = NULL ;
F_36 ( V_3 ) ;
F_47 ( & V_3 -> V_113 ) ;
F_111 ( & V_3 -> V_108 ) ;
F_108 ( & V_3 -> V_182 ) ;
F_47 ( & V_3 -> V_111 ) ;
#ifdef F_9
if ( V_3 -> V_12 )
F_112 ( V_3 -> V_12 ) ;
#endif
F_113 ( & V_3 -> V_108 ) ;
}
