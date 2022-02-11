static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ( V_2 -> V_6 == V_7 ) &&
( V_3 == V_4 ) ) {
if ( V_2 -> V_8 & V_9 )
return 0 ;
else {
if ( V_2 -> V_10 == V_11 )
return 0 ;
else
F_3 ( V_12 , L_1 ) ;
}
} else {
if ( V_2 -> V_6 != V_7 )
F_3 ( V_12 , L_2 ,
F_4 ( V_2 -> V_6 ) ) ;
if ( V_3 != V_4 )
F_3 ( V_12 , L_3 ,
V_3 , V_4 ) ;
}
F_3 ( V_12 , L_4 , V_4 ) ;
return 1 ;
}
int
F_5 ( char * V_13 , unsigned int V_14 , struct V_15 * V_16 )
{
struct V_17 * V_18 = (struct V_17 * ) V_13 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
T_1 V_3 ;
T_2 V_21 = F_7 ( V_13 ) ;
T_2 V_22 ;
int V_23 ;
F_3 ( V_24 , L_5 ,
V_25 , V_14 , V_21 ) ;
if ( V_2 -> V_6 == V_26 ) {
struct V_27 * V_28 =
(struct V_27 * ) V_13 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
F_8 ( & V_33 ) ;
F_9 (tmp, &srvr->smb_ses_list) {
V_30 = F_10 ( V_32 , struct V_29 , V_34 ) ;
if ( V_30 -> V_35 == V_28 -> V_36 )
break;
V_30 = NULL ;
}
F_11 ( & V_33 ) ;
if ( V_30 == NULL ) {
F_3 ( V_12 , L_6 ) ;
return 1 ;
}
}
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_14 < sizeof( struct V_17 ) ) {
if ( ( V_14 >= sizeof( struct V_19 ) )
&& ( V_2 -> V_37 != 0 ) ) {
V_18 -> V_38 = 0 ;
return 0 ;
} else {
F_3 ( V_12 , L_7 ) ;
}
return 1 ;
}
if ( V_21 > V_39 + V_40 - 4 ) {
F_3 ( V_12 , L_8 ,
V_3 ) ;
return 1 ;
}
if ( F_1 ( V_2 , V_3 ) )
return 1 ;
if ( V_2 -> V_41 != V_42 ) {
F_3 ( V_12 , L_9 ,
F_12 ( V_2 -> V_41 ) ) ;
return 1 ;
}
V_23 = F_12 ( V_2 -> V_10 ) ;
if ( V_23 >= V_43 ) {
F_3 ( V_12 , L_10 , V_23 ) ;
return 1 ;
}
if ( V_44 [ V_23 ] != V_18 -> V_38 ) {
if ( V_23 != V_45 && ( V_2 -> V_37 == 0 ||
V_18 -> V_38 != V_46 ) ) {
F_3 ( V_12 , L_11 ,
F_12 ( V_18 -> V_38 ) , V_23 ) ;
return 1 ;
} else if ( V_23 == V_45
&& ( V_2 -> V_37 == 0 )
&& ( F_12 ( V_18 -> V_38 ) != 44 )
&& ( F_12 ( V_18 -> V_38 ) != 36 ) ) {
F_3 ( V_12 , L_12 ,
F_12 ( V_18 -> V_38 ) ) ;
return 1 ;
}
}
if ( 4 + V_21 != V_14 ) {
F_3 ( V_12 , L_13 ,
V_14 , 4 + V_21 , V_3 ) ;
return 1 ;
}
V_22 = F_13 ( V_20 ) ;
if ( 4 + V_21 != V_22 ) {
F_3 ( V_24 , L_14 ,
V_22 , 4 + V_21 , V_3 ) ;
if ( V_23 == V_47 &&
V_2 -> V_37 == V_48 )
return 0 ;
if ( V_22 + 20 == V_21 && V_23 == V_45 )
return 0 ;
if ( V_22 == 4 + V_21 + 1 )
return 0 ;
if ( V_22 < 4 + V_21 ) {
F_14 ( V_49
L_15 ,
V_21 , V_22 - 4 ) ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
char *
F_15 ( int * V_50 , int * V_21 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_20 ) ;
* V_50 = 0 ;
* V_21 = 0 ;
if ( V_2 -> V_37 && V_2 -> V_37 != V_51 &&
( ( (struct V_52 * ) V_20 ) -> V_41 ) ==
V_46 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_53 :
* V_50 = F_12 (
( (struct V_54 * ) V_20 ) -> V_55 ) ;
* V_21 = F_12 (
( (struct V_54 * ) V_20 ) -> V_56 ) ;
break;
case V_57 :
* V_50 = F_12 (
( (struct V_58 * ) V_20 ) -> V_55 ) ;
* V_21 = F_12 (
( (struct V_58 * ) V_20 ) -> V_56 ) ;
break;
case V_59 :
* V_50 = F_4 (
( (struct V_60 * ) V_20 ) -> V_61 ) ;
* V_21 = F_4 (
( (struct V_60 * ) V_20 ) -> V_62 ) ;
break;
case V_63 :
* V_50 = F_12 (
( (struct V_64 * ) V_20 ) -> V_65 ) ;
* V_21 = F_4 (
( (struct V_64 * ) V_20 ) -> V_66 ) ;
break;
case V_67 :
* V_50 = ( (struct V_68 * ) V_20 ) -> V_69 ;
* V_21 = F_4 ( ( (struct V_68 * ) V_20 ) -> V_70 ) ;
break;
case V_71 :
* V_50 = F_12 (
( (struct V_72 * ) V_20 ) -> V_65 ) ;
* V_21 = F_4 (
( (struct V_72 * ) V_20 ) -> V_66 ) ;
break;
case V_73 :
* V_50 = F_4 (
( (struct V_74 * ) V_20 ) -> V_75 ) ;
* V_21 = F_4 ( ( (struct V_74 * ) V_20 ) -> V_76 ) ;
break;
case V_77 :
default:
F_3 ( V_12 , L_16 ) ;
break;
}
if ( * V_50 > 4096 ) {
F_3 ( V_12 , L_17 , * V_50 ) ;
* V_21 = 0 ;
* V_50 = 0 ;
} else if ( * V_50 < 0 ) {
F_3 ( V_12 , L_18 ,
* V_50 ) ;
* V_50 = 0 ;
* V_21 = 0 ;
} else if ( * V_21 < 0 ) {
F_3 ( V_12 , L_19 ,
* V_21 ) ;
* V_21 = 0 ;
} else if ( * V_21 > 128 * 1024 ) {
F_3 ( V_12 , L_20 , * V_21 ) ;
* V_21 = 0 ;
}
if ( ( * V_50 != 0 ) && ( * V_21 != 0 ) )
return ( char * ) V_2 + * V_50 ;
else
return NULL ;
}
unsigned int
F_13 ( void * V_13 )
{
struct V_17 * V_18 = (struct V_17 * ) V_13 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_1 * V_2 = F_6 ( V_20 ) ;
int V_78 ;
int V_79 ;
int V_21 = 4 + F_12 ( V_2 -> V_41 ) ;
V_21 += F_12 ( V_18 -> V_38 ) ;
if ( V_80 [ F_12 ( V_2 -> V_10 ) ] == false )
goto V_81;
F_15 ( & V_78 , & V_79 , V_20 ) ;
F_3 ( V_24 , L_21 , V_79 , V_78 ) ;
if ( V_79 > 0 ) {
if ( V_78 + 4 + 1 < V_21 ) {
F_3 ( V_12 , L_22 ,
V_78 + 4 + 1 , V_21 ) ;
V_79 = 0 ;
} else {
V_21 = 4 + V_78 + V_79 ;
}
}
V_81:
F_3 ( V_24 , L_23 , V_21 ) ;
return V_21 ;
}
T_3 *
F_16 ( const char * V_82 , struct V_83 * V_84 )
{
int V_21 ;
const char * V_85 ;
T_3 * V_86 ;
int V_87 ;
if ( V_84 -> V_88 & V_89 )
V_87 = V_90 ;
else if ( V_84 -> V_88 & V_91 )
V_87 = V_92 ;
else
V_87 = V_93 ;
if ( V_82 [ 0 ] == '\\' )
V_85 = V_82 + 1 ;
else
V_85 = V_82 ;
V_86 = F_17 ( V_85 , V_94 , & V_21 ,
V_84 -> V_95 , V_87 ) ;
return V_86 ;
}
T_4
F_18 ( struct V_96 * V_97 )
{
T_4 V_98 = 0 ;
if ( F_19 ( V_97 ) )
V_98 |= V_99 ;
if ( F_20 ( V_97 ) )
V_98 |= V_100 ;
if ( F_21 ( V_97 ) )
V_98 |= V_101 ;
return V_98 ;
}
static void
F_22 ( struct V_102 * V_103 )
{
struct V_104 * V_105 = F_23 ( V_103 ,
struct V_104 , V_106 ) ;
int V_107 ;
V_107 = F_24 ( 0 , F_25 ( V_105 -> V_108 ) , V_105 -> V_109 ,
V_105 -> V_110 ) ;
F_3 ( V_24 , L_24 , V_107 ) ;
F_26 ( V_105 -> V_108 ) ;
F_27 ( V_105 ) ;
}
static bool
F_28 ( struct V_111 * V_112 , struct V_113 * V_114 ,
struct V_104 * V_105 )
{
bool V_115 ;
T_5 V_110 ;
struct V_31 * V_32 ;
struct V_116 * V_117 ;
struct V_15 * V_118 = V_112 -> V_30 -> V_118 ;
struct V_119 * V_120 ;
struct V_96 * V_97 ;
int V_121 = F_4 ( V_114 -> V_8 &
V_122 ) ;
V_110 = F_4 ( V_114 -> V_123 ) ;
F_9 (tmp, &tcon->openFileList) {
V_117 = F_10 ( V_32 , struct V_116 , V_124 ) ;
V_97 = F_29 ( F_30 ( V_117 -> V_125 ) ) ;
if ( memcmp ( V_97 -> V_109 , V_114 -> V_126 ,
V_127 ) )
continue;
F_3 ( V_24 , L_25 ) ;
F_3 ( V_24 , L_26 ,
F_4 ( V_114 -> V_123 ) ) ;
V_118 -> V_128 -> V_129 ( V_97 , V_110 , 0 , NULL ) ;
if ( V_121 )
V_117 -> V_130 = false ;
else
V_117 -> V_130 = true ;
F_31 ( V_131 , & V_117 -> V_132 ) ;
F_27 ( V_105 ) ;
return true ;
}
V_115 = false ;
F_32 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_120 -> V_109 , V_114 -> V_126 ,
V_127 ) )
continue;
if ( ! V_115 && V_121 ) {
V_115 = true ;
memcpy ( V_105 -> V_109 , V_120 -> V_109 ,
V_127 ) ;
V_105 -> V_108 = F_33 ( V_120 -> V_108 ) ;
F_31 ( V_133 , & V_105 -> V_106 ) ;
}
F_3 ( V_24 , L_27 ) ;
F_3 ( V_24 , L_26 ,
F_4 ( V_114 -> V_123 ) ) ;
V_120 -> V_134 = V_110 ;
}
return V_115 ;
}
static bool
F_34 ( char * V_135 )
{
struct V_113 * V_114 = (struct V_113 * ) V_135 ;
struct V_31 * V_32 , * V_136 , * V_137 ;
struct V_15 * V_118 ;
struct V_29 * V_30 ;
struct V_111 * V_112 ;
struct V_104 * V_105 ;
V_105 = F_35 ( sizeof( struct V_104 ) , V_138 ) ;
if ( ! V_105 )
return false ;
F_36 ( & V_105 -> V_106 , F_22 ) ;
V_105 -> V_110 = V_114 -> V_123 ;
F_3 ( V_24 , L_28 ) ;
F_8 ( & V_33 ) ;
F_9 (tmp, &cifs_tcp_ses_list) {
V_118 = F_10 ( V_32 , struct V_15 , V_139 ) ;
F_9 (tmp1, &server->smb_ses_list) {
V_30 = F_10 ( V_136 , struct V_29 , V_34 ) ;
F_9 (tmp2, &ses->tcon_list) {
V_112 = F_10 ( V_137 , struct V_111 ,
V_140 ) ;
F_8 ( & V_112 -> V_141 ) ;
F_37 (
& V_112 -> V_142 . V_143 . V_144 ) ;
if ( F_28 ( V_112 , V_114 , V_105 ) ) {
F_11 ( & V_112 -> V_141 ) ;
F_11 ( & V_33 ) ;
return true ;
}
F_11 ( & V_112 -> V_141 ) ;
}
}
}
F_11 ( & V_33 ) ;
F_27 ( V_105 ) ;
F_3 ( V_24 , L_29 ) ;
return false ;
}
bool
F_38 ( char * V_135 , struct V_15 * V_118 )
{
struct V_145 * V_114 = (struct V_145 * ) V_135 ;
struct V_31 * V_32 , * V_136 , * V_137 ;
struct V_29 * V_30 ;
struct V_111 * V_112 ;
struct V_96 * V_97 ;
struct V_116 * V_117 ;
F_3 ( V_24 , L_30 ) ;
if ( V_114 -> V_20 . V_146 . V_10 != V_11 )
return false ;
if ( V_114 -> V_41 !=
V_44 [ V_45 ] ) {
if ( F_12 ( V_114 -> V_41 ) == 44 )
return F_34 ( V_135 ) ;
else
return false ;
}
F_3 ( V_24 , L_31 , V_114 -> V_147 ) ;
F_8 ( & V_33 ) ;
F_9 (tmp, &server->smb_ses_list) {
V_30 = F_10 ( V_32 , struct V_29 , V_34 ) ;
F_9 (tmp1, &ses->tcon_list) {
V_112 = F_10 ( V_136 , struct V_111 , V_140 ) ;
F_37 ( & V_112 -> V_142 . V_143 . V_144 ) ;
F_8 ( & V_112 -> V_141 ) ;
F_9 (tmp2, &tcon->openFileList) {
V_117 = F_10 ( V_137 , struct V_116 ,
V_124 ) ;
if ( V_114 -> V_148 !=
V_117 -> V_149 . V_150 ||
V_114 -> V_151 !=
V_117 -> V_149 . V_152 )
continue;
F_3 ( V_24 , L_32 ) ;
V_97 = F_29 ( F_30 ( V_117 -> V_125 ) ) ;
F_8 ( & V_117 -> V_153 ) ;
if ( ! F_19 ( V_97 ) &&
V_114 -> V_147 == V_154 )
V_117 -> V_130 = true ;
else
V_117 -> V_130 = false ;
F_39 ( V_155 ,
& V_97 -> V_156 ) ;
if ( V_114 -> V_147 )
F_39 (
V_157 ,
& V_97 -> V_156 ) ;
else
F_40 (
V_157 ,
& V_97 -> V_156 ) ;
F_11 ( & V_117 -> V_153 ) ;
F_31 ( V_131 ,
& V_117 -> V_132 ) ;
F_11 ( & V_112 -> V_141 ) ;
F_11 ( & V_33 ) ;
return true ;
}
F_11 ( & V_112 -> V_141 ) ;
F_11 ( & V_33 ) ;
F_3 ( V_24 , L_33 ) ;
return true ;
}
}
F_11 ( & V_33 ) ;
F_3 ( V_24 , L_34 ) ;
return false ;
}
void
F_41 ( struct V_102 * V_103 )
{
struct V_158 * V_159 = F_23 ( V_103 ,
struct V_158 , V_103 ) ;
F_3 ( V_12 , L_35 ) ;
F_42 ( 0 , V_159 -> V_112 , V_159 -> V_149 . V_150 ,
V_159 -> V_149 . V_152 ) ;
F_43 ( V_159 -> V_112 ) ;
F_27 ( V_159 ) ;
}
int
F_44 ( char * V_135 , struct V_15 * V_118 )
{
struct V_1 * V_146 = F_6 ( V_135 ) ;
struct V_60 * V_114 = (struct V_60 * ) V_135 ;
struct V_111 * V_112 ;
struct V_158 * V_159 ;
if ( V_146 -> V_10 != V_59 ||
V_146 -> V_37 != V_160 )
return 0 ;
V_159 = F_45 ( sizeof( * V_159 ) , V_138 ) ;
if ( ! V_159 )
return - V_161 ;
V_112 = F_46 ( V_118 , V_146 -> V_36 ,
V_146 -> V_162 ) ;
if ( ! V_112 ) {
F_27 ( V_159 ) ;
return - V_163 ;
}
V_159 -> V_149 . V_150 = V_114 -> V_164 ;
V_159 -> V_149 . V_152 = V_114 -> V_165 ;
V_159 -> V_112 = V_112 ;
F_36 ( & V_159 -> V_103 , F_41 ) ;
F_31 ( V_133 , & V_159 -> V_103 ) ;
return 0 ;
}
