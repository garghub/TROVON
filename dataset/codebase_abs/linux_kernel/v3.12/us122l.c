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
static int F_16 ( struct V_39 * V_40 ,
struct V_44 * V_45 )
{
unsigned long V_46 ;
struct V_47 * V_47 ;
void * V_48 ;
struct V_41 * V_41 = V_40 -> V_42 ;
struct V_49 * V_50 ;
F_17 ( & V_41 -> V_51 ) ;
V_50 = V_41 -> V_52 . V_50 ;
if ( ! V_50 )
goto V_53;
V_46 = V_45 -> V_54 << V_55 ;
if ( V_46 < F_18 ( V_50 -> V_56 ) )
V_48 = ( char * ) V_50 + V_46 ;
else {
V_46 -= F_18 ( V_50 -> V_56 ) ;
if ( V_46 >= F_18 ( V_50 -> V_57 ) )
goto V_53;
V_48 = V_41 -> V_52 . V_58 + V_46 ;
}
V_47 = F_19 ( V_48 ) ;
F_20 ( V_47 ) ;
F_21 ( & V_41 -> V_51 ) ;
V_45 -> V_47 = V_47 ;
return 0 ;
V_53:
F_21 ( & V_41 -> V_51 ) ;
return V_59 ;
}
static void F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_41 = V_40 -> V_42 ;
F_23 ( & V_41 -> V_43 ) ;
F_12 ( V_38 L_3 , F_15 ( & V_41 -> V_43 ) ) ;
}
static int F_24 ( struct V_60 * V_61 , struct V_62 * V_62 )
{
struct V_41 * V_41 = V_61 -> V_63 ;
struct V_19 * V_20 ;
F_12 ( V_38 L_4 , V_61 , V_62 ) ;
if ( V_61 -> V_64 >= 2 )
return - V_65 ;
if ( ! V_41 -> V_66 )
V_41 -> V_66 = V_62 ;
if ( V_41 -> V_18 -> V_67 . V_68 == V_69 ||
V_41 -> V_18 -> V_67 . V_68 == V_70 ) {
V_20 = F_3 ( V_41 -> V_18 , 0 ) ;
F_25 ( V_20 ) ;
}
V_20 = F_3 ( V_41 -> V_18 , 1 ) ;
F_25 ( V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_60 * V_61 , struct V_62 * V_62 )
{
struct V_41 * V_41 = V_61 -> V_63 ;
struct V_19 * V_20 ;
F_12 ( V_38 L_4 , V_61 , V_62 ) ;
if ( V_41 -> V_18 -> V_67 . V_68 == V_69 ||
V_41 -> V_18 -> V_67 . V_68 == V_70 ) {
V_20 = F_3 ( V_41 -> V_18 , 0 ) ;
F_27 ( V_20 ) ;
}
V_20 = F_3 ( V_41 -> V_18 , 1 ) ;
F_27 ( V_20 ) ;
if ( V_41 -> V_66 == V_62 )
V_41 -> V_66 = NULL ;
F_17 ( & V_41 -> V_51 ) ;
if ( V_41 -> V_71 == V_62 )
V_41 -> V_71 = V_41 -> V_72 ;
V_41 -> V_72 = NULL ;
F_21 ( & V_41 -> V_51 ) ;
return 0 ;
}
static int F_28 ( struct V_60 * V_61 ,
struct V_62 * V_73 , struct V_39 * V_40 )
{
unsigned long V_27 = V_40 -> V_74 - V_40 -> V_75 ;
struct V_41 * V_41 = V_61 -> V_63 ;
unsigned long V_46 ;
struct V_49 * V_50 ;
int V_29 = 0 ;
bool V_76 ;
V_46 = V_40 -> V_77 << V_55 ;
F_17 ( & V_41 -> V_51 ) ;
V_50 = V_41 -> V_52 . V_50 ;
V_76 = V_46 < V_50 -> V_56 ;
if ( V_76 && V_40 -> V_78 & V_79 ) {
V_29 = - V_80 ;
goto V_81;
}
F_12 ( V_38 L_5 , V_27 ,
V_76 ? V_50 -> V_56 : V_50 -> V_57 ) ;
if ( V_27 > F_18 ( V_76 ? V_50 -> V_56 : V_50 -> V_57 ) ) {
F_29 ( V_82 L_6 , V_27 ,
V_76 ? V_50 -> V_56 : V_50 -> V_57 ) ;
V_29 = - V_83 ;
goto V_81;
}
V_40 -> V_84 = & V_85 ;
V_40 -> V_78 |= V_86 ;
if ( ! V_76 )
V_40 -> V_78 |= V_87 ;
V_40 -> V_42 = V_41 ;
F_14 ( & V_41 -> V_43 ) ;
V_81:
F_21 ( & V_41 -> V_51 ) ;
return V_29 ;
}
static unsigned int F_30 ( struct V_60 * V_61 ,
struct V_62 * V_62 , T_4 * V_88 )
{
struct V_41 * V_41 = V_61 -> V_63 ;
unsigned * V_89 ;
unsigned int V_90 ;
F_31 ( V_62 , & V_41 -> V_52 . V_91 , V_88 ) ;
V_90 = V_92 | V_93 | V_94 | V_95 ;
if ( F_32 ( & V_41 -> V_51 ) ) {
struct V_49 * V_50 = V_41 -> V_52 . V_50 ;
if ( V_50 && V_50 -> V_96 == V_97 ) {
if ( V_41 -> V_66 == V_62 )
V_89 = & V_50 -> V_98 ;
else
V_89 = & V_41 -> V_99 ;
if ( * V_89 != V_50 -> V_100 ) {
* V_89 = V_50 -> V_100 ;
V_90 = V_92 | V_93 | V_94 ;
} else
V_90 = 0 ;
}
F_21 ( & V_41 -> V_51 ) ;
}
return V_90 ;
}
static void F_33 ( struct V_41 * V_41 )
{
struct V_101 * V_102 ;
F_34 (p, &us122l->midi_list)
F_35 ( V_102 ) ;
F_36 ( & V_41 -> V_52 ) ;
F_37 ( & V_41 -> V_52 ) ;
}
static int F_38 ( struct V_17 * V_18 , int V_103 )
{
unsigned int V_104 = 0x81 ;
unsigned char V_16 [ 3 ] ;
int V_29 ;
V_16 [ 0 ] = V_103 ;
V_16 [ 1 ] = V_103 >> 8 ;
V_16 [ 2 ] = V_103 >> 16 ;
V_29 = F_6 ( V_18 , F_11 ( V_18 , 0 ) , V_105 ,
V_106 | V_107 | V_35 ,
V_108 << 8 , V_104 , V_16 , 3 , 1000 ) ;
if ( V_29 < 0 )
F_29 ( V_109 L_7 ,
V_18 -> V_110 , V_103 , V_104 ) ;
return V_29 ;
}
static bool F_39 ( struct V_41 * V_41 ,
unsigned V_103 , unsigned V_111 )
{
struct V_101 * V_102 ;
int V_29 ;
unsigned V_112 = 0 ;
bool V_113 = false ;
if ( V_41 -> V_18 -> V_114 == V_115 ) {
switch ( V_103 ) {
case 44100 :
V_112 = 36 ;
break;
case 48000 :
V_112 = 42 ;
break;
case 88200 :
V_112 = 72 ;
break;
}
}
if ( ! F_40 ( & V_41 -> V_52 , V_41 -> V_18 , 1 , 2 ,
V_103 , V_112 , V_111 , 6 ) )
goto V_81;
V_29 = F_38 ( V_41 -> V_18 , V_103 ) ;
if ( V_29 < 0 ) {
F_33 ( V_41 ) ;
F_29 ( V_109 L_8 ) ;
goto V_81;
}
V_29 = F_41 ( & V_41 -> V_52 ) ;
if ( V_29 < 0 ) {
F_33 ( V_41 ) ;
F_29 ( V_109 L_9 , V_29 ) ;
goto V_81;
}
F_34 (p, &us122l->midi_list)
F_42 ( V_102 ) ;
V_113 = true ;
V_81:
return V_113 ;
}
static int F_43 ( struct V_60 * V_61 , struct V_62 * V_62 ,
unsigned V_116 , unsigned long V_117 )
{
struct V_118 * V_119 ;
struct V_41 * V_41 = V_61 -> V_63 ;
struct V_49 * V_50 ;
unsigned V_120 ;
int V_29 = 0 ;
bool V_121 ;
if ( V_116 != V_122 )
return - V_123 ;
V_119 = F_44 ( ( void * ) V_117 , sizeof( * V_119 ) ) ;
if ( F_45 ( V_119 ) )
return F_46 ( V_119 ) ;
if ( V_119 -> V_124 != V_125 ) {
V_29 = - V_126 ;
goto free;
}
V_121 = V_41 -> V_18 -> V_114 == V_115 ;
if ( ( V_119 -> V_127 != 44100 && V_119 -> V_127 != 48000 &&
( ! V_121 ||
( V_119 -> V_127 != 88200 && V_119 -> V_127 != 96000 ) ) ) ||
V_119 -> V_128 != 6 ||
V_119 -> V_111 > 0x3000 ) {
V_29 = - V_83 ;
goto free;
}
switch ( V_119 -> V_127 ) {
case 44100 :
V_120 = 48 ;
break;
case 48000 :
V_120 = 52 ;
break;
default:
V_120 = 104 ;
break;
}
if ( ! V_121 )
V_120 <<= 1 ;
if ( V_119 -> V_111 < V_120 ) {
V_29 = - V_83 ;
goto free;
}
F_47 ( V_61 -> V_2 , V_129 ) ;
F_17 ( & V_41 -> V_51 ) ;
V_50 = V_41 -> V_52 . V_50 ;
if ( ! V_41 -> V_71 )
V_41 -> V_71 = V_62 ;
else if ( V_41 -> V_71 != V_62 ) {
if ( ! V_50 || memcmp ( V_119 , & V_50 -> V_119 , sizeof( * V_119 ) ) ) {
V_29 = - V_130 ;
goto V_53;
}
V_41 -> V_72 = V_62 ;
}
if ( ! V_50 || memcmp ( V_119 , & V_50 -> V_119 , sizeof( * V_119 ) ) ||
V_50 -> V_96 == V_131 ) {
F_33 ( V_41 ) ;
if ( ! F_39 ( V_41 , V_119 -> V_127 , V_119 -> V_111 ) )
V_29 = - V_130 ;
else
V_29 = 1 ;
}
V_53:
F_21 ( & V_41 -> V_51 ) ;
free:
F_9 ( V_119 ) ;
F_48 ( & V_41 -> V_52 . V_91 ) ;
return V_29 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_60 * V_61 ;
struct V_17 * V_18 = F_2 ( V_2 ) -> V_18 ;
V_29 = F_50 ( V_2 , V_132 , 0 , & V_61 ) ;
if ( V_29 < 0 )
return V_29 ;
V_61 -> V_20 = V_133 ;
V_61 -> V_63 = F_2 ( V_2 ) ;
V_61 -> V_134 . V_135 = F_24 ;
V_61 -> V_134 . V_136 = F_26 ;
V_61 -> V_134 . V_137 = F_43 ;
V_61 -> V_134 . V_138 = F_43 ;
V_61 -> V_134 . V_139 = F_28 ;
V_61 -> V_134 . V_140 = F_30 ;
sprintf ( V_61 -> V_141 , L_10 ,
V_18 -> V_142 -> V_143 , V_18 -> V_110 ) ;
return 0 ;
}
static bool F_51 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_41 * V_41 = F_2 ( V_2 ) ;
if ( V_41 -> V_18 -> V_67 . V_68 == V_69 ||
V_41 -> V_18 -> V_67 . V_68 == V_70 ) {
V_29 = F_52 ( V_41 -> V_18 , 0 , 1 ) ;
if ( V_29 ) {
F_29 ( V_109 L_11 ) ;
return false ;
}
}
V_29 = F_52 ( V_41 -> V_18 , 1 , 1 ) ;
if ( V_29 ) {
F_29 ( V_109 L_11 ) ;
return false ;
}
F_10 ( V_41 -> V_18 , 0x11 ) ;
F_10 ( V_41 -> V_18 , 0x10 ) ;
if ( ! F_39 ( V_41 , 44100 , 256 ) )
return false ;
if ( V_41 -> V_18 -> V_67 . V_68 == V_69 ||
V_41 -> V_18 -> V_67 . V_68 == V_70 )
V_29 = F_5 ( V_2 ) ;
else
V_29 = F_1 ( V_2 ) ;
if ( V_29 < 0 ) {
F_29 ( V_109 L_12 , V_29 ) ;
F_33 ( V_41 ) ;
return false ;
}
V_29 = F_49 ( V_2 ) ;
if ( V_29 < 0 ) {
struct V_101 * V_102 ;
F_34 (p, &us122l->midi_list)
F_53 ( V_102 ) ;
F_33 ( V_41 ) ;
return false ;
}
return true ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = F_2 ( V_2 ) ;
int V_26 = V_41 -> V_144 ;
if ( V_26 >= 0 && V_26 < V_145 )
V_146 [ V_26 ] = 0 ;
}
static int F_55 ( struct V_17 * V_147 , struct V_1 * * V_148 )
{
int V_18 ;
struct V_1 * V_2 ;
int V_29 ;
for ( V_18 = 0 ; V_18 < V_145 ; ++ V_18 )
if ( V_149 [ V_18 ] && ! V_146 [ V_18 ] )
break;
if ( V_18 >= V_145 )
return - V_150 ;
V_29 = F_56 ( V_26 [ V_18 ] , V_151 [ V_18 ] , V_152 ,
sizeof( struct V_41 ) , & V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_146 [ F_2 ( V_2 ) -> V_144 = V_18 ] = 1 ;
V_2 -> V_153 = F_54 ;
F_2 ( V_2 ) -> V_18 = V_147 ;
F_57 ( & F_2 ( V_2 ) -> V_51 ) ;
F_58 ( & F_2 ( V_2 ) -> V_52 . V_91 ) ;
F_59 ( & F_2 ( V_2 ) -> V_21 ) ;
strcpy ( V_2 -> V_154 , L_13 V_13 L_14 ) ;
sprintf ( V_2 -> V_155 , L_15 V_13 L_14 ) ;
sprintf ( V_2 -> V_156 , L_16 ,
V_2 -> V_155 ,
F_60 ( V_147 -> V_67 . V_157 ) ,
F_60 ( V_147 -> V_67 . V_68 ) ,
0 ,
F_2 ( V_2 ) -> V_18 -> V_142 -> V_143 ,
F_2 ( V_2 ) -> V_18 -> V_110
) ;
* V_148 = V_2 ;
return 0 ;
}
static int F_61 ( struct V_19 * V_158 ,
const struct V_159 * V_160 ,
struct V_1 * * V_148 )
{
struct V_17 * V_147 = F_62 ( V_158 ) ;
struct V_1 * V_2 ;
int V_29 ;
V_29 = F_55 ( V_147 , & V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
F_63 ( V_2 , & V_158 -> V_18 ) ;
if ( ! F_51 ( V_2 ) ) {
F_64 ( V_2 ) ;
return - V_83 ;
}
V_29 = F_65 ( V_2 ) ;
if ( V_29 < 0 ) {
F_64 ( V_2 ) ;
return V_29 ;
}
F_66 ( F_3 ( V_147 , 0 ) ) ;
F_67 ( V_147 ) ;
* V_148 = V_2 ;
return 0 ;
}
static int F_68 ( struct V_19 * V_158 ,
const struct V_159 * V_151 )
{
struct V_17 * V_147 = F_62 ( V_158 ) ;
struct V_1 * V_2 ;
int V_29 ;
if ( ( V_147 -> V_67 . V_68 == V_69 ||
V_147 -> V_67 . V_68 == V_70 )
&& V_147 -> V_114 == V_115 ) {
F_29 ( V_109 L_17 ) ;
return - V_150 ;
}
F_12 ( V_38 L_18 ,
V_158 , V_158 -> V_161 -> V_162 . V_163 ) ;
if ( V_158 -> V_161 -> V_162 . V_163 != 1 )
return 0 ;
V_29 = F_61 ( F_66 ( V_158 ) , V_151 , & V_2 ) ;
if ( V_29 < 0 ) {
F_69 ( V_158 ) ;
return V_29 ;
}
F_70 ( V_158 , V_2 ) ;
return 0 ;
}
static void F_71 ( struct V_19 * V_158 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_101 * V_102 ;
V_2 = F_72 ( V_158 ) ;
if ( ! V_2 )
return;
F_73 ( V_2 ) ;
V_41 = F_2 ( V_2 ) ;
F_17 ( & V_41 -> V_51 ) ;
F_33 ( V_41 ) ;
F_21 ( & V_41 -> V_51 ) ;
F_34 (p, &us122l->midi_list) {
F_53 ( V_102 ) ;
}
F_69 ( F_3 ( V_41 -> V_18 , 0 ) ) ;
F_69 ( F_3 ( V_41 -> V_18 , 1 ) ) ;
F_74 ( V_41 -> V_18 ) ;
while ( F_15 ( & V_41 -> V_43 ) )
F_75 ( 500 ) ;
F_64 ( V_2 ) ;
}
static int F_76 ( struct V_19 * V_158 , T_5 V_164 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_101 * V_102 ;
V_2 = F_72 ( V_158 ) ;
if ( ! V_2 )
return 0 ;
F_77 ( V_2 , V_165 ) ;
V_41 = F_2 ( V_2 ) ;
if ( ! V_41 )
return 0 ;
F_34 (p, &us122l->midi_list)
F_35 ( V_102 ) ;
F_17 ( & V_41 -> V_51 ) ;
F_36 ( & V_41 -> V_52 ) ;
F_21 ( & V_41 -> V_51 ) ;
return 0 ;
}
static int F_78 ( struct V_19 * V_158 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_101 * V_102 ;
int V_29 ;
V_2 = F_72 ( V_158 ) ;
if ( ! V_2 )
return 0 ;
V_41 = F_2 ( V_2 ) ;
if ( ! V_41 )
return 0 ;
F_17 ( & V_41 -> V_51 ) ;
if ( V_41 -> V_18 -> V_67 . V_68 == V_69 ||
V_41 -> V_18 -> V_67 . V_68 == V_70 ) {
V_29 = F_52 ( V_41 -> V_18 , 0 , 1 ) ;
if ( V_29 ) {
F_29 ( V_109 L_11 ) ;
goto V_53;
}
}
V_29 = F_52 ( V_41 -> V_18 , 1 , 1 ) ;
if ( V_29 ) {
F_29 ( V_109 L_11 ) ;
goto V_53;
}
F_10 ( V_41 -> V_18 , 0x11 ) ;
F_10 ( V_41 -> V_18 , 0x10 ) ;
V_29 = F_38 ( V_41 -> V_18 ,
V_41 -> V_52 . V_50 -> V_119 . V_127 ) ;
if ( V_29 < 0 ) {
F_29 ( V_109 L_8 ) ;
goto V_53;
}
V_29 = F_41 ( & V_41 -> V_52 ) ;
if ( V_29 )
goto V_53;
F_34 (p, &us122l->midi_list)
F_42 ( V_102 ) ;
V_53:
F_21 ( & V_41 -> V_51 ) ;
F_77 ( V_2 , V_129 ) ;
return V_29 ;
}
