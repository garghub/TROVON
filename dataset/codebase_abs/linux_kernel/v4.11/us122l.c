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
if ( V_41 -> V_18 -> V_68 . V_69 == V_70 ||
V_41 -> V_18 -> V_68 . V_69 == V_71 ) {
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
if ( V_41 -> V_18 -> V_68 . V_69 == V_70 ||
V_41 -> V_18 -> V_68 . V_69 == V_71 ) {
V_20 = F_3 ( V_41 -> V_18 , 0 ) ;
F_27 ( V_20 ) ;
}
V_20 = F_3 ( V_41 -> V_18 , 1 ) ;
F_27 ( V_20 ) ;
if ( V_41 -> V_67 == V_63 )
V_41 -> V_67 = NULL ;
F_17 ( & V_41 -> V_52 ) ;
if ( V_41 -> V_72 == V_63 )
V_41 -> V_72 = V_41 -> V_73 ;
V_41 -> V_73 = NULL ;
F_21 ( & V_41 -> V_52 ) ;
return 0 ;
}
static int F_28 ( struct V_61 * V_62 ,
struct V_63 * V_74 , struct V_39 * V_40 )
{
unsigned long V_27 = V_40 -> V_75 - V_40 -> V_76 ;
struct V_41 * V_41 = V_62 -> V_64 ;
unsigned long V_46 ;
struct V_50 * V_51 ;
int V_29 = 0 ;
bool V_77 ;
V_46 = V_40 -> V_78 << V_56 ;
F_17 ( & V_41 -> V_52 ) ;
V_51 = V_41 -> V_53 . V_51 ;
V_77 = V_46 < V_51 -> V_57 ;
if ( V_77 && V_40 -> V_79 & V_80 ) {
V_29 = - V_81 ;
goto V_82;
}
F_12 ( V_38 L_5 , V_27 ,
V_77 ? V_51 -> V_57 : V_51 -> V_58 ) ;
if ( V_27 > F_18 ( V_77 ? V_51 -> V_57 : V_51 -> V_58 ) ) {
F_29 ( V_83 L_6 , V_27 ,
V_77 ? V_51 -> V_57 : V_51 -> V_58 ) ;
V_29 = - V_84 ;
goto V_82;
}
V_40 -> V_85 = & V_86 ;
V_40 -> V_79 |= V_87 ;
if ( ! V_77 )
V_40 -> V_79 |= V_88 ;
V_40 -> V_42 = V_41 ;
F_14 ( & V_41 -> V_43 ) ;
V_82:
F_21 ( & V_41 -> V_52 ) ;
return V_29 ;
}
static unsigned int F_30 ( struct V_61 * V_62 ,
struct V_63 * V_63 , T_4 * V_89 )
{
struct V_41 * V_41 = V_62 -> V_64 ;
unsigned * V_90 ;
unsigned int V_91 ;
F_31 ( V_63 , & V_41 -> V_53 . V_92 , V_89 ) ;
V_91 = V_93 | V_94 | V_95 | V_96 ;
if ( F_32 ( & V_41 -> V_52 ) ) {
struct V_50 * V_51 = V_41 -> V_53 . V_51 ;
if ( V_51 && V_51 -> V_97 == V_98 ) {
if ( V_41 -> V_67 == V_63 )
V_90 = & V_51 -> V_99 ;
else
V_90 = & V_41 -> V_100 ;
if ( * V_90 != V_51 -> V_101 ) {
* V_90 = V_51 -> V_101 ;
V_91 = V_93 | V_94 | V_95 ;
} else
V_91 = 0 ;
}
F_21 ( & V_41 -> V_52 ) ;
}
return V_91 ;
}
static void F_33 ( struct V_41 * V_41 )
{
struct V_102 * V_103 ;
F_34 (p, &us122l->midi_list)
F_35 ( V_103 ) ;
F_36 ( & V_41 -> V_53 ) ;
F_37 ( & V_41 -> V_53 ) ;
}
static int F_38 ( struct V_17 * V_18 , int V_104 )
{
unsigned int V_105 = 0x81 ;
unsigned char V_16 [ 3 ] ;
int V_29 ;
V_16 [ 0 ] = V_104 ;
V_16 [ 1 ] = V_104 >> 8 ;
V_16 [ 2 ] = V_104 >> 16 ;
V_29 = F_6 ( V_18 , F_11 ( V_18 , 0 ) , V_106 ,
V_107 | V_108 | V_35 ,
V_109 << 8 , V_105 , V_16 , 3 , 1000 ) ;
if ( V_29 < 0 )
F_29 ( V_110 L_7 ,
V_18 -> V_111 , V_104 , V_105 ) ;
return V_29 ;
}
static bool F_39 ( struct V_41 * V_41 ,
unsigned V_104 , unsigned V_112 )
{
struct V_102 * V_103 ;
int V_29 ;
unsigned V_113 = 0 ;
bool V_114 = false ;
if ( V_41 -> V_18 -> V_115 == V_116 ) {
switch ( V_104 ) {
case 44100 :
V_113 = 36 ;
break;
case 48000 :
V_113 = 42 ;
break;
case 88200 :
V_113 = 72 ;
break;
}
}
if ( ! F_40 ( & V_41 -> V_53 , V_41 -> V_18 , 1 , 2 ,
V_104 , V_113 , V_112 , 6 ) )
goto V_82;
V_29 = F_38 ( V_41 -> V_18 , V_104 ) ;
if ( V_29 < 0 ) {
F_33 ( V_41 ) ;
F_29 ( V_110 L_8 ) ;
goto V_82;
}
V_29 = F_41 ( & V_41 -> V_53 ) ;
if ( V_29 < 0 ) {
F_33 ( V_41 ) ;
F_29 ( V_110 L_9 , V_29 ) ;
goto V_82;
}
F_34 (p, &us122l->midi_list)
F_42 ( V_103 ) ;
V_114 = true ;
V_82:
return V_114 ;
}
static int F_43 ( struct V_61 * V_62 , struct V_63 * V_63 ,
unsigned V_117 , unsigned long V_118 )
{
struct V_119 * V_120 ;
struct V_41 * V_41 = V_62 -> V_64 ;
struct V_50 * V_51 ;
unsigned V_121 ;
int V_29 = 0 ;
bool V_122 ;
if ( V_117 != V_123 )
return - V_124 ;
V_120 = F_44 ( ( void * ) V_118 , sizeof( * V_120 ) ) ;
if ( F_45 ( V_120 ) )
return F_46 ( V_120 ) ;
if ( V_120 -> V_125 != V_126 ) {
V_29 = - V_127 ;
goto free;
}
V_122 = V_41 -> V_18 -> V_115 == V_116 ;
if ( ( V_120 -> V_128 != 44100 && V_120 -> V_128 != 48000 &&
( ! V_122 ||
( V_120 -> V_128 != 88200 && V_120 -> V_128 != 96000 ) ) ) ||
V_120 -> V_129 != 6 ||
V_120 -> V_112 > 0x3000 ) {
V_29 = - V_84 ;
goto free;
}
switch ( V_120 -> V_128 ) {
case 44100 :
V_121 = 48 ;
break;
case 48000 :
V_121 = 52 ;
break;
default:
V_121 = 104 ;
break;
}
if ( ! V_122 )
V_121 <<= 1 ;
if ( V_120 -> V_112 < V_121 ) {
V_29 = - V_84 ;
goto free;
}
F_47 ( V_62 -> V_2 , V_130 ) ;
F_17 ( & V_41 -> V_52 ) ;
V_51 = V_41 -> V_53 . V_51 ;
if ( ! V_41 -> V_72 )
V_41 -> V_72 = V_63 ;
else if ( V_41 -> V_72 != V_63 ) {
if ( ! V_51 || memcmp ( V_120 , & V_51 -> V_120 , sizeof( * V_120 ) ) ) {
V_29 = - V_131 ;
goto V_54;
}
V_41 -> V_73 = V_63 ;
}
if ( ! V_51 || memcmp ( V_120 , & V_51 -> V_120 , sizeof( * V_120 ) ) ||
V_51 -> V_97 == V_132 ) {
F_33 ( V_41 ) ;
if ( ! F_39 ( V_41 , V_120 -> V_128 , V_120 -> V_112 ) )
V_29 = - V_131 ;
else
V_29 = 1 ;
}
V_54:
F_21 ( & V_41 -> V_52 ) ;
free:
F_9 ( V_120 ) ;
F_48 ( & V_41 -> V_53 . V_92 ) ;
return V_29 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_61 * V_62 ;
struct V_17 * V_18 = F_2 ( V_2 ) -> V_18 ;
V_29 = F_50 ( V_2 , V_133 , 0 , & V_62 ) ;
if ( V_29 < 0 )
return V_29 ;
V_62 -> V_20 = V_134 ;
V_62 -> V_64 = F_2 ( V_2 ) ;
V_62 -> V_135 . V_136 = F_24 ;
V_62 -> V_135 . V_137 = F_26 ;
V_62 -> V_135 . V_138 = F_43 ;
V_62 -> V_135 . V_139 = F_43 ;
V_62 -> V_135 . V_140 = F_28 ;
V_62 -> V_135 . V_141 = F_30 ;
sprintf ( V_62 -> V_142 , L_10 ,
V_18 -> V_143 -> V_144 , V_18 -> V_111 ) ;
return 0 ;
}
static bool F_51 ( struct V_1 * V_2 )
{
int V_29 ;
struct V_41 * V_41 = F_2 ( V_2 ) ;
if ( V_41 -> V_18 -> V_68 . V_69 == V_70 ||
V_41 -> V_18 -> V_68 . V_69 == V_71 ) {
V_29 = F_52 ( V_41 -> V_18 , 0 , 1 ) ;
if ( V_29 ) {
F_29 ( V_110 L_11 ) ;
return false ;
}
}
V_29 = F_52 ( V_41 -> V_18 , 1 , 1 ) ;
if ( V_29 ) {
F_29 ( V_110 L_11 ) ;
return false ;
}
F_10 ( V_41 -> V_18 , 0x11 ) ;
F_10 ( V_41 -> V_18 , 0x10 ) ;
if ( ! F_39 ( V_41 , 44100 , 256 ) )
return false ;
if ( V_41 -> V_18 -> V_68 . V_69 == V_70 ||
V_41 -> V_18 -> V_68 . V_69 == V_71 )
V_29 = F_5 ( V_2 ) ;
else
V_29 = F_1 ( V_2 ) ;
if ( V_29 < 0 ) {
F_29 ( V_110 L_12 , V_29 ) ;
F_33 ( V_41 ) ;
return false ;
}
V_29 = F_49 ( V_2 ) ;
if ( V_29 < 0 ) {
struct V_102 * V_103 ;
F_34 (p, &us122l->midi_list)
F_53 ( V_103 ) ;
F_33 ( V_41 ) ;
return false ;
}
return true ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = F_2 ( V_2 ) ;
int V_26 = V_41 -> V_145 ;
if ( V_26 >= 0 && V_26 < V_146 )
V_147 [ V_26 ] = 0 ;
}
static int F_55 ( struct V_17 * V_148 ,
struct V_19 * V_149 ,
struct V_1 * * V_150 )
{
int V_18 ;
struct V_1 * V_2 ;
int V_29 ;
for ( V_18 = 0 ; V_18 < V_146 ; ++ V_18 )
if ( V_151 [ V_18 ] && ! V_147 [ V_18 ] )
break;
if ( V_18 >= V_146 )
return - V_152 ;
V_29 = F_56 ( & V_149 -> V_18 , V_26 [ V_18 ] , V_153 [ V_18 ] , V_154 ,
sizeof( struct V_41 ) , & V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_147 [ F_2 ( V_2 ) -> V_145 = V_18 ] = 1 ;
V_2 -> V_155 = F_54 ;
F_2 ( V_2 ) -> V_18 = V_148 ;
F_57 ( & F_2 ( V_2 ) -> V_52 ) ;
F_58 ( & F_2 ( V_2 ) -> V_53 . V_92 ) ;
F_59 ( & F_2 ( V_2 ) -> V_21 ) ;
strcpy ( V_2 -> V_156 , L_13 V_13 L_14 ) ;
sprintf ( V_2 -> V_157 , L_15 V_13 L_14 ) ;
sprintf ( V_2 -> V_158 , L_16 ,
V_2 -> V_157 ,
F_60 ( V_148 -> V_68 . V_159 ) ,
F_60 ( V_148 -> V_68 . V_69 ) ,
0 ,
F_2 ( V_2 ) -> V_18 -> V_143 -> V_144 ,
F_2 ( V_2 ) -> V_18 -> V_111
) ;
* V_150 = V_2 ;
return 0 ;
}
static int F_61 ( struct V_19 * V_149 ,
const struct V_160 * V_161 ,
struct V_1 * * V_150 )
{
struct V_17 * V_148 = F_62 ( V_149 ) ;
struct V_1 * V_2 ;
int V_29 ;
V_29 = F_55 ( V_148 , V_149 , & V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! F_51 ( V_2 ) ) {
F_63 ( V_2 ) ;
return - V_84 ;
}
V_29 = F_64 ( V_2 ) ;
if ( V_29 < 0 ) {
F_63 ( V_2 ) ;
return V_29 ;
}
F_65 ( F_3 ( V_148 , 0 ) ) ;
F_66 ( V_148 ) ;
* V_150 = V_2 ;
return 0 ;
}
static int F_67 ( struct V_19 * V_149 ,
const struct V_160 * V_153 )
{
struct V_17 * V_148 = F_62 ( V_149 ) ;
struct V_1 * V_2 ;
int V_29 ;
if ( ( V_148 -> V_68 . V_69 == V_70 ||
V_148 -> V_68 . V_69 == V_71 )
&& V_148 -> V_115 == V_116 ) {
F_29 ( V_110 L_17 ) ;
return - V_152 ;
}
F_12 ( V_38 L_18 ,
V_149 , V_149 -> V_162 -> V_163 . V_164 ) ;
if ( V_149 -> V_162 -> V_163 . V_164 != 1 )
return 0 ;
V_29 = F_61 ( F_65 ( V_149 ) , V_153 , & V_2 ) ;
if ( V_29 < 0 ) {
F_68 ( V_149 ) ;
return V_29 ;
}
F_69 ( V_149 , V_2 ) ;
return 0 ;
}
static void F_70 ( struct V_19 * V_149 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_102 * V_103 ;
V_2 = F_71 ( V_149 ) ;
if ( ! V_2 )
return;
F_72 ( V_2 ) ;
V_41 = F_2 ( V_2 ) ;
F_17 ( & V_41 -> V_52 ) ;
F_33 ( V_41 ) ;
F_21 ( & V_41 -> V_52 ) ;
F_34 (p, &us122l->midi_list) {
F_53 ( V_103 ) ;
}
F_68 ( F_3 ( V_41 -> V_18 , 0 ) ) ;
F_68 ( F_3 ( V_41 -> V_18 , 1 ) ) ;
F_73 ( V_41 -> V_18 ) ;
while ( F_15 ( & V_41 -> V_43 ) )
F_74 ( 500 ) ;
F_63 ( V_2 ) ;
}
static int F_75 ( struct V_19 * V_149 , T_5 V_165 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_102 * V_103 ;
V_2 = F_71 ( V_149 ) ;
if ( ! V_2 )
return 0 ;
F_76 ( V_2 , V_166 ) ;
V_41 = F_2 ( V_2 ) ;
if ( ! V_41 )
return 0 ;
F_34 (p, &us122l->midi_list)
F_35 ( V_103 ) ;
F_17 ( & V_41 -> V_52 ) ;
F_36 ( & V_41 -> V_53 ) ;
F_21 ( & V_41 -> V_52 ) ;
return 0 ;
}
static int F_77 ( struct V_19 * V_149 )
{
struct V_1 * V_2 ;
struct V_41 * V_41 ;
struct V_102 * V_103 ;
int V_29 ;
V_2 = F_71 ( V_149 ) ;
if ( ! V_2 )
return 0 ;
V_41 = F_2 ( V_2 ) ;
if ( ! V_41 )
return 0 ;
F_17 ( & V_41 -> V_52 ) ;
if ( V_41 -> V_18 -> V_68 . V_69 == V_70 ||
V_41 -> V_18 -> V_68 . V_69 == V_71 ) {
V_29 = F_52 ( V_41 -> V_18 , 0 , 1 ) ;
if ( V_29 ) {
F_29 ( V_110 L_11 ) ;
goto V_54;
}
}
V_29 = F_52 ( V_41 -> V_18 , 1 , 1 ) ;
if ( V_29 ) {
F_29 ( V_110 L_11 ) ;
goto V_54;
}
F_10 ( V_41 -> V_18 , 0x11 ) ;
F_10 ( V_41 -> V_18 , 0x10 ) ;
V_29 = F_38 ( V_41 -> V_18 ,
V_41 -> V_53 . V_51 -> V_120 . V_128 ) ;
if ( V_29 < 0 ) {
F_29 ( V_110 L_8 ) ;
goto V_54;
}
V_29 = F_41 ( & V_41 -> V_53 ) ;
if ( V_29 )
goto V_54;
F_34 (p, &us122l->midi_list)
F_42 ( V_103 ) ;
V_54:
F_21 ( & V_41 -> V_52 ) ;
F_76 ( V_2 , V_130 ) ;
return V_29 ;
}
