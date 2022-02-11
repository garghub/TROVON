static int F_1 ( struct V_1 * V_2 )
{
static struct V_3 V_4 = {
. V_5 = 4 ,
. V_6 = 3 ,
. V_7 = 0x001 ,
. V_8 = 0x001
} ;
static struct V_9 V_10 = {
. V_11 = L_1 ,
. V_12 = V_13 ,
. V_14 = 1 ,
. type = V_15 ,
. V_16 = & V_4
} ;
struct V_17 * V_18 = F_2 ( V_2 ) -> V_18 ;
struct V_19 * V_20 = F_3 ( V_18 , 1 ) ;
return F_4 ( V_2 , V_20 ,
& F_2 ( V_2 ) -> V_21 , & V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
static struct V_3 V_4 = {
. V_5 = 4 ,
. V_6 = 3 ,
. V_7 = 0x001 ,
. V_8 = 0x001
} ;
static struct V_9 V_10 = {
. V_11 = L_2 ,
. V_12 = V_13 ,
. V_14 = 0 ,
. type = V_15 ,
. V_16 = & V_4
} ;
struct V_17 * V_18 = F_2 ( V_2 ) -> V_18 ;
struct V_19 * V_20 = F_3 ( V_18 , 0 ) ;
return F_4 ( V_2 , V_20 ,
& F_2 ( V_2 ) -> V_21 , & V_10 ) ;
}
static int F_6 ( struct V_17 * V_18 , unsigned int V_22 ,
T_1 V_23 , T_1 V_24 ,
T_2 V_25 , T_2 V_26 , void * V_16 ,
T_2 V_27 , int V_28 )
{
int V_29 ;
void * V_30 = NULL ;
if ( V_27 > 0 ) {
V_30 = F_7 ( V_16 , V_27 , V_31 ) ;
if ( ! V_30 )
return - V_32 ;
}
V_29 = F_8 ( V_18 , V_22 , V_23 , V_24 ,
V_25 , V_26 , V_30 , V_27 , V_28 ) ;
if ( V_27 > 0 ) {
memcpy ( V_16 , V_30 , V_27 ) ;
F_9 ( V_30 ) ;
}
return V_29 ;
}
static void F_10 ( struct V_17 * V_18 , T_3 V_33 )
{
int V_34 ;
V_34 = F_8 ( V_18 , F_11 ( V_18 , 0 ) ,
'I' ,
V_35 | V_36 | V_37 ,
V_33 , 0 , NULL , 0 , 1000 ) ;
F_12 ( V_38 L_3 , V_34 ) ;
}
static void F_13 ( struct V_39 * V_40 )
{
struct V_41 * V_41 = V_40 -> V_42 ;
F_14 ( & V_41 -> V_43 ) ;
F_12 ( V_38 L_3 , F_15 ( & V_41 -> V_43 ) ) ;
}
static int F_16 ( struct V_44 * V_45 )
{
unsigned long V_46 ;
struct V_47 * V_47 ;
void * V_48 ;
struct V_41 * V_41 = V_45 -> V_49 -> V_42 ;
struct V_50 * V_51 ;
F_17 ( & V_41 -> V_52 ) ;
V_51 = V_41 -> V_53 . V_51 ;
if ( ! V_51 )
goto V_54;
V_46 = V_45 -> V_55 << V_56 ;
if ( V_46 < F_18 ( V_51 -> V_57 ) )
V_48 = ( char * ) V_51 + V_46 ;
else {
V_46 -= F_18 ( V_51 -> V_57 ) ;
if ( V_46 >= F_18 ( V_51 -> V_58 ) )
goto V_54;
V_48 = V_41 -> V_53 . V_59 + V_46 ;
}
V_47 = F_19 ( V_48 ) ;
F_20 ( V_47 ) ;
F_21 ( & V_41 -> V_52 ) ;
V_45 -> V_47 = V_47 ;
return 0 ;
V_54:
F_21 ( & V_41 -> V_52 ) ;
return V_60 ;
}
static void F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_41 = V_40 -> V_42 ;
F_23 ( & V_41 -> V_43 ) ;
F_12 ( V_38 L_3 , F_15 ( & V_41 -> V_43 ) ) ;
}
static int F_24 ( struct V_61 * V_62 , struct V_63 * V_63 )
{
struct V_41 * V_41 = V_62 -> V_64 ;
struct V_19 * V_20 ;
F_12 ( V_38 L_4 , V_62 , V_63 ) ;
if ( V_62 -> V_65 >= 2 )
return - V_66 ;
if ( ! V_41 -> V_67 )
V_41 -> V_67 = V_63 ;
if ( V_41 -> V_68 ) {
V_20 = F_3 ( V_41 -> V_18 , 0 ) ;
F_25 ( V_20 ) ;
}
V_20 = F_3 ( V_41 -> V_18 , 1 ) ;
F_25 ( V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_61 * V_62 , struct V_63 * V_63 )
{
struct V_41 * V_41 = V_62 -> V_64 ;
struct V_19 * V_20 ;
F_12 ( V_38 L_4 , V_62 , V_63 ) ;
if ( V_41 -> V_68 ) {
V_20 = F_3 ( V_41 -> V_18 , 0 ) ;
F_27 ( V_20 ) ;
}
V_20 = F_3 ( V_41 -> V_18 , 1 ) ;
F_27 ( V_20 ) ;
if ( V_41 -> V_67 == V_63 )
V_41 -> V_67 = NULL ;
F_17 ( & V_41 -> V_52 ) ;
if ( V_41 -> V_69 == V_63 )
V_41 -> V_69 = V_41 -> V_70 ;
V_41 -> V_70 = NULL ;
F_21 ( & V_41 -> V_52 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_62 ,
struct V_63 * V_71 , struct V_39 * V_40 )
{
unsigned long V_27 = V_40 -> V_72 - V_40 -> V_73 ;
struct V_41 * V_41 = V_62 -> V_64 ;
unsigned long V_46 ;
struct V_50 * V_51 ;
int V_29 = 0 ;
bool V_74 ;
V_46 = V_40 -> V_75 << V_56 ;
F_17 ( & V_41 -> V_52 ) ;
V_51 = V_41 -> V_53 . V_51 ;
V_74 = V_46 < V_51 -> V_57 ;
if ( V_74 && V_40 -> V_76 & V_77 ) {
V_29 = - V_78 ;
goto V_79;
}
F_12 ( V_38 L_5 , V_27 ,
V_74 ? V_51 -> V_57 : V_51 -> V_58 ) ;
if ( V_27 > F_18 ( V_74 ? V_51 -> V_57 : V_51 -> V_58 ) ) {
F_29 ( V_80 L_6 , V_27 ,
V_74 ? V_51 -> V_57 : V_51 -> V_58 ) ;
V_29 = - V_81 ;
goto V_79;
}
V_40 -> V_82 = & V_83 ;
V_40 -> V_76 |= V_84 ;
if ( ! V_74 )
V_40 -> V_76 |= V_85 ;
V_40 -> V_42 = V_41 ;
F_14 ( & V_41 -> V_43 ) ;
V_79:
F_21 ( & V_41 -> V_52 ) ;
return V_29 ;
}
static unsigned int F_30 ( struct V_61 * V_62 ,
struct V_63 * V_63 , T_4 * V_86 )
{
struct V_41 * V_41 = V_62 -> V_64 ;
unsigned * V_87 ;
unsigned int V_88 ;
F_31 ( V_63 , & V_41 -> V_53 . V_89 , V_86 ) ;
V_88 = V_90 | V_91 | V_92 | V_93 ;
if ( F_32 ( & V_41 -> V_52 ) ) {
struct V_50 * V_51 = V_41 -> V_53 . V_51 ;
if ( V_51 && V_51 -> V_94 == V_95 ) {
if ( V_41 -> V_67 == V_63 )
V_87 = & V_51 -> V_96 ;
else
V_87 = & V_41 -> V_97 ;
if ( * V_87 != V_51 -> V_98 ) {
* V_87 = V_51 -> V_98 ;
V_88 = V_90 | V_91 | V_92 ;
} else
V_88 = 0 ;
}
F_21 ( & V_41 -> V_52 ) ;
}
return V_88 ;
}
static void F_33 ( struct V_41 * V_41 )
{
struct V_99 * V_100 ;
F_34 (p, &us122l->midi_list)
F_35 ( V_100 ) ;
F_36 ( & V_41 -> V_53 ) ;
F_37 ( & V_41 -> V_53 ) ;
}
static int F_38 ( struct V_17 * V_18 , int V_101 )
{
unsigned int V_102 = 0x81 ;
unsigned char V_16 [ 3 ] ;
int V_29 ;
V_16 [ 0 ] = V_101 ;
V_16 [ 1 ] = V_101 >> 8 ;
V_16 [ 2 ] = V_101 >> 16 ;
V_29 = F_6 ( V_18 , F_11 ( V_18 , 0 ) , V_103 ,
V_104 | V_105 | V_35 ,
V_106 << 8 , V_102 , V_16 , 3 , 1000 ) ;
if ( V_29 < 0 )
F_29 ( V_107 L_7 ,
V_18 -> V_108 , V_101 , V_102 ) ;
return V_29 ;
}
static bool F_39 ( struct V_41 * V_41 ,
unsigned V_101 , unsigned V_109 )
{
struct V_99 * V_100 ;
int V_29 ;
unsigned V_110 = 0 ;
bool V_111 = false ;
if ( V_41 -> V_18 -> V_112 == V_113 ) {
switch ( V_101 ) {
case 44100 :
V_110 = 36 ;
break;
case 48000 :
V_110 = 42 ;
break;
case 88200 :
V_110 = 72 ;
break;
}
}
if ( ! F_40 ( & V_41 -> V_53 , V_41 -> V_18 , 1 , 2 ,
V_101 , V_110 , V_109 , 6 ) )
goto V_79;
V_29 = F_38 ( V_41 -> V_18 , V_101 ) ;
if ( V_29 < 0 ) {
F_33 ( V_41 ) ;
F_29 ( V_107 L_8 ) ;
goto V_79;
}
V_29 = F_41 ( & V_41 -> V_53 ) ;
if ( V_29 < 0 ) {
F_33 ( V_41 ) ;
F_29 ( V_107 L_9 , V_29 ) ;
goto V_79;
}
F_34 (p, &us122l->midi_list)
F_42 ( V_100 ) ;
V_111 = true ;
V_79:
return V_111 ;
}
static int F_43 ( struct V_61 * V_62 , struct V_63 * V_63 ,
unsigned V_114 , unsigned long V_115 )
{
struct V_116 * V_117 ;
struct V_41 * V_41 = V_62 -> V_64 ;
struct V_50 * V_51 ;
unsigned V_118 ;
int V_29 = 0 ;
bool V_119 ;
if ( V_114 != V_120 )
return - V_121 ;
V_117 = F_44 ( ( void * ) V_115 , sizeof( * V_117 ) ) ;
if ( F_45 ( V_117 ) )
return F_46 ( V_117 ) ;
if ( V_117 -> V_122 != V_123 ) {
V_29 = - V_124 ;
goto free;
}
V_119 = V_41 -> V_18 -> V_112 == V_113 ;
if ( ( V_117 -> V_125 != 44100 && V_117 -> V_125 != 48000 &&
( ! V_119 ||
( V_117 -> V_125 != 88200 && V_117 -> V_125 != 96000 ) ) ) ||
V_117 -> V_126 != 6 ||
V_117 -> V_109 > 0x3000 ) {
V_29 = - V_81 ;
goto free;
}
switch ( V_117 -> V_125 ) {
case 44100 :
V_118 = 48 ;
break;
case 48000 :
V_118 = 52 ;
break;
default:
V_118 = 104 ;
break;
}
if ( ! V_119 )
V_118 <<= 1 ;
if ( V_117 -> V_109 < V_118 ) {
V_29 = - V_81 ;
goto free;
}
F_47 ( V_62 -> V_2 , V_127 ) ;
F_17 ( & V_41 -> V_52 ) ;
V_51 = V_41 -> V_53 . V_51 ;
if ( ! V_41 -> V_69 )
V_41 -> V_69 = V_63 ;
else if ( V_41 -> V_69 != V_63 ) {
if ( ! V_51 || memcmp ( V_117 , & V_51 -> V_117 , sizeof( * V_117 ) ) ) {
V_29 = - V_128 ;
goto V_54;
}
V_41 -> V_70 = V_63 ;
}
if ( ! V_51 || memcmp ( V_117 , & V_51 -> V_117 , sizeof( * V_117 ) ) ||
V_51 -> V_94 == V_129 ) {
F_33 ( V_41 ) ;
if ( ! F_39 ( V_41 , V_117 -> V_125 , V_117 -> V_109 ) )
V_29 = - V_128 ;
else
V_29 = 1 ;
}
V_54:
F_21 ( & V_41 -> V_52 ) ;
free:
F_9 ( V_117 ) ;
F_48 ( & V_41 -> V_53 . V_89 ) ;
return V_29 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_61 * V_62 ;
struct V_17 * V_18 = F_2 ( V_2 ) -> V_18 ;
V_29 = F_50 ( V_2 , V_130 , 0 , & V_62 ) ;
if ( V_29 < 0 )
return V_29 ;
V_62 -> V_20 = V_131 ;
V_62 -> V_64 = F_2 ( V_2 ) ;
V_62 -> V_132 . V_133 = F_24 ;
V_62 -> V_132 . V_134 = F_26 ;
V_62 -> V_132 . V_135 = F_43 ;
V_62 -> V_132 . V_136 = F_43 ;
V_62 -> V_132 . V_137 = F_28 ;
V_62 -> V_132 . V_138 = F_30 ;
sprintf ( V_62 -> V_139 , L_10 ,
V_18 -> V_140 -> V_141 , V_18 -> V_108 ) ;
return 0 ;
}
static bool F_51 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_41 * V_41 = F_2 ( V_2 ) ;
if ( V_41 -> V_68 ) {
V_29 = F_52 ( V_41 -> V_18 , 0 , 1 ) ;
if ( V_29 ) {
F_29 ( V_107 L_11 ) ;
return false ;
}
}
V_29 = F_52 ( V_41 -> V_18 , 1 , 1 ) ;
if ( V_29 ) {
F_29 ( V_107 L_11 ) ;
return false ;
}
F_10 ( V_41 -> V_18 , 0x11 ) ;
F_10 ( V_41 -> V_18 , 0x10 ) ;
if ( ! F_39 ( V_41 , 44100 , 256 ) )
return false ;
if ( V_41 -> V_68 )
V_29 = F_5 ( V_2 ) ;
else
V_29 = F_1 ( V_2 ) ;
if ( V_29 < 0 ) {
F_29 ( V_107 L_12 , V_29 ) ;
goto V_142;
}
V_29 = F_49 ( V_2 ) ;
if ( V_29 < 0 ) {
struct V_99 * V_100 ;
F_34 (p, &us122l->midi_list)
F_53 ( V_100 ) ;
goto V_142;
}
return true ;
V_142:
F_33 ( V_41 ) ;
return false ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = F_2 ( V_2 ) ;
int V_26 = V_41 -> V_143 ;
if ( V_26 >= 0 && V_26 < V_144 )
V_145 [ V_26 ] = 0 ;
}
static int F_55 ( struct V_17 * V_146 ,
struct V_19 * V_147 ,
struct V_1 * * V_148 ,
unsigned long V_149 )
{
int V_18 ;
struct V_1 * V_2 ;
int V_29 ;
for ( V_18 = 0 ; V_18 < V_144 ; ++ V_18 )
if ( V_150 [ V_18 ] && ! V_145 [ V_18 ] )
break;
if ( V_18 >= V_144 )
return - V_151 ;
V_29 = F_56 ( & V_147 -> V_18 , V_26 [ V_18 ] , V_152 [ V_18 ] , V_153 ,
sizeof( struct V_41 ) , & V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_145 [ F_2 ( V_2 ) -> V_143 = V_18 ] = 1 ;
V_2 -> V_154 = F_54 ;
F_2 ( V_2 ) -> V_18 = V_146 ;
F_57 ( & F_2 ( V_2 ) -> V_52 ) ;
F_58 ( & F_2 ( V_2 ) -> V_53 . V_89 ) ;
F_2 ( V_2 ) -> V_68 = V_149 & V_155 ;
F_59 ( & F_2 ( V_2 ) -> V_21 ) ;
strcpy ( V_2 -> V_156 , L_13 V_13 L_14 ) ;
sprintf ( V_2 -> V_157 , L_15 V_13 L_14 ) ;
sprintf ( V_2 -> V_158 , L_16 ,
V_2 -> V_157 ,
F_60 ( V_146 -> V_159 . V_160 ) ,
F_60 ( V_146 -> V_159 . V_161 ) ,
0 ,
F_2 ( V_2 ) -> V_18 -> V_140 -> V_141 ,
F_2 ( V_2 ) -> V_18 -> V_108
) ;
* V_148 = V_2 ;
return 0 ;
}
static int F_61 ( struct V_19 * V_147 ,
const struct V_162 * V_163 ,
struct V_1 * * V_148 )
{
struct V_17 * V_146 = F_62 ( V_147 ) ;
struct V_1 * V_2 ;
int V_29 ;
V_29 = F_55 ( V_146 , V_147 , & V_2 , V_163 -> V_164 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! F_51 ( V_2 ) ) {
F_63 ( V_2 ) ;
return - V_81 ;
}
V_29 = F_64 ( V_2 ) ;
if ( V_29 < 0 ) {
F_63 ( V_2 ) ;
return V_29 ;
}
F_65 ( F_3 ( V_146 , 0 ) ) ;
F_66 ( V_146 ) ;
* V_148 = V_2 ;
return 0 ;
}
static int F_67 ( struct V_19 * V_147 ,
const struct V_162 * V_152 )
{
struct V_17 * V_146 = F_62 ( V_147 ) ;
struct V_1 * V_2 ;
int V_29 ;
if ( V_152 -> V_164 & V_155 &&
V_146 -> V_112 == V_113 ) {
F_29 ( V_107 L_17 ) ;
return - V_151 ;
}
F_12 ( V_38 L_18 ,
V_147 , V_147 -> V_165 -> V_166 . V_167 ) ;
if ( V_147 -> V_165 -> V_166 . V_167 != 1 )
return 0 ;
V_29 = F_61 ( F_65 ( V_147 ) , V_152 , & V_2 ) ;
if ( V_29 < 0 ) {
F_68 ( V_147 ) ;
return V_29 ;
}
F_69 ( V_147 , V_2 ) ;
return 0 ;
}
static void F_70 ( struct V_19 * V_147 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_99 * V_100 ;
V_2 = F_71 ( V_147 ) ;
if ( ! V_2 )
return;
F_72 ( V_2 ) ;
V_41 = F_2 ( V_2 ) ;
F_17 ( & V_41 -> V_52 ) ;
F_33 ( V_41 ) ;
F_21 ( & V_41 -> V_52 ) ;
F_34 (p, &us122l->midi_list) {
F_53 ( V_100 ) ;
}
F_68 ( F_3 ( V_41 -> V_18 , 0 ) ) ;
F_68 ( F_3 ( V_41 -> V_18 , 1 ) ) ;
F_73 ( V_41 -> V_18 ) ;
while ( F_15 ( & V_41 -> V_43 ) )
F_74 ( 500 ) ;
F_63 ( V_2 ) ;
}
static int F_75 ( struct V_19 * V_147 , T_5 V_168 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_99 * V_100 ;
V_2 = F_71 ( V_147 ) ;
if ( ! V_2 )
return 0 ;
F_76 ( V_2 , V_169 ) ;
V_41 = F_2 ( V_2 ) ;
if ( ! V_41 )
return 0 ;
F_34 (p, &us122l->midi_list)
F_35 ( V_100 ) ;
F_17 ( & V_41 -> V_52 ) ;
F_36 ( & V_41 -> V_53 ) ;
F_21 ( & V_41 -> V_52 ) ;
return 0 ;
}
static int F_77 ( struct V_19 * V_147 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_99 * V_100 ;
int V_29 ;
V_2 = F_71 ( V_147 ) ;
if ( ! V_2 )
return 0 ;
V_41 = F_2 ( V_2 ) ;
if ( ! V_41 )
return 0 ;
F_17 ( & V_41 -> V_52 ) ;
if ( V_41 -> V_68 ) {
V_29 = F_52 ( V_41 -> V_18 , 0 , 1 ) ;
if ( V_29 ) {
F_29 ( V_107 L_11 ) ;
goto V_54;
}
}
V_29 = F_52 ( V_41 -> V_18 , 1 , 1 ) ;
if ( V_29 ) {
F_29 ( V_107 L_11 ) ;
goto V_54;
}
F_10 ( V_41 -> V_18 , 0x11 ) ;
F_10 ( V_41 -> V_18 , 0x10 ) ;
V_29 = F_38 ( V_41 -> V_18 ,
V_41 -> V_53 . V_51 -> V_117 . V_125 ) ;
if ( V_29 < 0 ) {
F_29 ( V_107 L_8 ) ;
goto V_54;
}
V_29 = F_41 ( & V_41 -> V_53 ) ;
if ( V_29 )
goto V_54;
F_34 (p, &us122l->midi_list)
F_42 ( V_100 ) ;
V_54:
F_21 ( & V_41 -> V_52 ) ;
F_76 ( V_2 , V_127 ) ;
return V_29 ;
}
