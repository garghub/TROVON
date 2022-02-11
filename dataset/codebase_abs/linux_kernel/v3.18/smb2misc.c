static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( * ( V_4 * ) V_2 -> V_5 == V_6 ) &&
( V_3 == V_2 -> V_7 ) ) {
if ( V_2 -> V_8 & V_9 )
return 0 ;
else {
if ( V_2 -> V_10 == V_11 )
return 0 ;
else
F_2 ( V_12 , L_1 ) ;
}
} else {
if ( * ( V_4 * ) V_2 -> V_5 != V_6 )
F_2 ( V_12 , L_2 ,
* ( unsigned int * ) V_2 -> V_5 ) ;
if ( V_3 != V_2 -> V_7 )
F_2 ( V_12 , L_3 ,
V_3 , V_2 -> V_7 ) ;
}
F_2 ( V_12 , L_4 , V_2 -> V_7 ) ;
return 1 ;
}
int
F_3 ( char * V_13 , unsigned int V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_15 * V_16 = (struct V_15 * ) V_2 ;
T_1 V_3 = V_2 -> V_7 ;
T_2 V_17 = F_4 ( V_13 ) ;
T_2 V_18 ;
int V_19 ;
F_2 ( V_20 , L_5 ,
V_21 , V_14 , V_17 ) ;
if ( V_14 < sizeof( struct V_15 ) ) {
if ( ( V_14 >= sizeof( struct V_1 ) ) && ( V_2 -> V_22 != 0 ) ) {
V_16 -> V_23 = 0 ;
return 0 ;
} else {
F_2 ( V_12 , L_6 ) ;
}
return 1 ;
}
if ( V_17 > V_24 + V_25 - 4 ) {
F_2 ( V_12 , L_7 ,
V_3 ) ;
return 1 ;
}
if ( F_1 ( V_2 , V_3 ) )
return 1 ;
if ( V_2 -> V_26 != V_27 ) {
F_2 ( V_12 , L_8 ,
F_5 ( V_2 -> V_26 ) ) ;
return 1 ;
}
V_19 = F_5 ( V_2 -> V_10 ) ;
if ( V_19 >= V_28 ) {
F_2 ( V_12 , L_9 , V_19 ) ;
return 1 ;
}
if ( V_29 [ V_19 ] != V_16 -> V_23 ) {
if ( V_19 != V_30 && ( V_2 -> V_22 == 0 ||
V_16 -> V_23 != V_31 ) ) {
F_2 ( V_12 , L_10 ,
F_5 ( V_16 -> V_23 ) , V_19 ) ;
return 1 ;
} else if ( V_19 == V_30 && ( V_2 -> V_22 == 0 )
&& ( F_5 ( V_16 -> V_23 ) != 44 )
&& ( F_5 ( V_16 -> V_23 ) != 36 ) ) {
F_2 ( V_12 , L_11 ,
F_5 ( V_16 -> V_23 ) ) ;
return 1 ;
}
}
if ( 4 + V_17 != V_14 ) {
F_2 ( V_12 , L_12 ,
V_14 , 4 + V_17 , V_3 ) ;
return 1 ;
}
V_18 = F_6 ( V_2 ) ;
if ( 4 + V_17 != V_18 ) {
F_2 ( V_20 , L_13 ,
V_18 , 4 + V_17 , V_3 ) ;
if ( V_19 == V_32 &&
V_2 -> V_22 == V_33 )
return 0 ;
if ( V_18 + 20 == V_17 && V_19 == V_30 )
return 0 ;
if ( V_18 == 4 + V_17 + 1 )
return 0 ;
if ( V_18 < 4 + V_17 ) {
F_7 ( V_34
L_14 ,
V_17 , V_18 - 4 ) ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
char *
F_8 ( int * V_35 , int * V_17 , struct V_1 * V_2 )
{
* V_35 = 0 ;
* V_17 = 0 ;
if ( V_2 -> V_22 && V_2 -> V_22 != V_36 &&
( ( (struct V_37 * ) V_2 ) -> V_26 ) ==
V_31 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_38 :
* V_35 = F_5 (
( (struct V_39 * ) V_2 ) -> V_40 ) ;
* V_17 = F_5 (
( (struct V_39 * ) V_2 ) -> V_41 ) ;
break;
case V_42 :
* V_35 = F_5 (
( (struct V_43 * ) V_2 ) -> V_40 ) ;
* V_17 = F_5 (
( (struct V_43 * ) V_2 ) -> V_41 ) ;
break;
case V_44 :
* V_35 = F_9 (
( (struct V_45 * ) V_2 ) -> V_46 ) ;
* V_17 = F_9 (
( (struct V_45 * ) V_2 ) -> V_47 ) ;
break;
case V_48 :
* V_35 = F_5 (
( (struct V_49 * ) V_2 ) -> V_50 ) ;
* V_17 = F_9 (
( (struct V_49 * ) V_2 ) -> V_51 ) ;
break;
case V_52 :
* V_35 = ( (struct V_53 * ) V_2 ) -> V_54 ;
* V_17 = F_9 ( ( (struct V_53 * ) V_2 ) -> V_55 ) ;
break;
case V_56 :
* V_35 = F_5 (
( (struct V_57 * ) V_2 ) -> V_50 ) ;
* V_17 = F_9 (
( (struct V_57 * ) V_2 ) -> V_51 ) ;
break;
case V_58 :
* V_35 = F_9 (
( (struct V_59 * ) V_2 ) -> V_60 ) ;
* V_17 = F_9 ( ( (struct V_59 * ) V_2 ) -> V_61 ) ;
break;
case V_62 :
default:
F_2 ( V_12 , L_15 ) ;
break;
}
if ( * V_35 > 4096 ) {
F_2 ( V_12 , L_16 , * V_35 ) ;
* V_17 = 0 ;
* V_35 = 0 ;
} else if ( * V_35 < 0 ) {
F_2 ( V_12 , L_17 ,
* V_35 ) ;
* V_35 = 0 ;
* V_17 = 0 ;
} else if ( * V_17 < 0 ) {
F_2 ( V_12 , L_18 ,
* V_17 ) ;
* V_17 = 0 ;
} else if ( * V_17 > 128 * 1024 ) {
F_2 ( V_12 , L_19 , * V_17 ) ;
* V_17 = 0 ;
}
if ( ( * V_35 != 0 ) && ( * V_17 != 0 ) )
return V_2 -> V_5 + * V_35 ;
else
return NULL ;
}
unsigned int
F_6 ( void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_15 * V_16 = (struct V_15 * ) V_2 ;
int V_63 ;
int V_64 ;
int V_17 = 4 + F_5 ( V_16 -> V_2 . V_26 ) ;
V_17 += F_5 ( V_16 -> V_23 ) ;
if ( V_65 [ F_5 ( V_2 -> V_10 ) ] == false )
goto V_66;
F_8 ( & V_63 , & V_64 , V_2 ) ;
F_2 ( V_20 , L_20 , V_64 , V_63 ) ;
if ( V_64 > 0 ) {
if ( V_63 + 4 + 1 < V_17 ) {
F_2 ( V_12 , L_21 ,
V_63 + 4 + 1 , V_17 ) ;
V_64 = 0 ;
} else {
V_17 = 4 + V_63 + V_64 ;
}
}
V_66:
F_2 ( V_20 , L_22 , V_17 ) ;
return V_17 ;
}
T_3 *
F_10 ( const char * V_67 , struct V_68 * V_69 )
{
int V_17 ;
const char * V_70 ;
T_3 * V_71 ;
int V_72 ;
if ( V_69 -> V_73 & V_74 )
V_72 = V_75 ;
else if ( V_69 -> V_73 & V_76 )
V_72 = V_77 ;
else
V_72 = V_78 ;
if ( V_67 [ 0 ] == '\\' )
V_70 = V_67 + 1 ;
else
V_70 = V_67 ;
V_71 = F_11 ( V_70 , V_79 , & V_17 ,
V_69 -> V_80 , V_72 ) ;
return V_71 ;
}
V_4
F_12 ( struct V_81 * V_82 )
{
V_4 V_83 = 0 ;
if ( F_13 ( V_82 ) )
V_83 |= V_84 ;
if ( F_14 ( V_82 ) )
V_83 |= V_85 ;
if ( F_15 ( V_82 ) )
V_83 |= V_86 ;
return V_83 ;
}
static void
F_16 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_17 ( V_88 ,
struct V_89 , V_91 ) ;
int V_92 ;
V_92 = F_18 ( 0 , F_19 ( V_90 -> V_93 ) , V_90 -> V_94 ,
V_90 -> V_95 ) ;
F_2 ( V_20 , L_23 , V_92 ) ;
F_20 ( V_90 -> V_93 ) ;
F_21 ( V_90 ) ;
}
static bool
F_22 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_89 * V_90 )
{
bool V_100 ;
T_4 V_95 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 = V_97 -> V_107 -> V_106 ;
struct V_108 * V_109 ;
struct V_81 * V_82 ;
int V_110 = F_9 ( V_99 -> V_8 &
V_111 ) ;
V_95 = F_9 ( V_99 -> V_112 ) ;
F_23 (tmp, &tcon->openFileList) {
V_104 = F_24 ( V_102 , struct V_103 , V_113 ) ;
V_82 = F_25 ( V_104 -> V_114 -> V_115 ) ;
if ( memcmp ( V_82 -> V_94 , V_99 -> V_116 ,
V_117 ) )
continue;
F_2 ( V_20 , L_24 ) ;
F_2 ( V_20 , L_25 ,
F_9 ( V_99 -> V_112 ) ) ;
V_106 -> V_118 -> V_119 ( V_82 , V_95 , 0 , NULL ) ;
if ( V_110 )
V_104 -> V_120 = false ;
else
V_104 -> V_120 = true ;
F_26 ( V_121 , & V_104 -> V_122 ) ;
F_21 ( V_90 ) ;
return true ;
}
V_100 = false ;
F_27 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_109 -> V_94 , V_99 -> V_116 ,
V_117 ) )
continue;
if ( ! V_100 && V_110 ) {
V_100 = true ;
memcpy ( V_90 -> V_94 , V_109 -> V_94 ,
V_117 ) ;
V_90 -> V_93 = F_28 ( V_109 -> V_93 ) ;
F_26 ( V_121 , & V_90 -> V_91 ) ;
}
F_2 ( V_20 , L_26 ) ;
F_2 ( V_20 , L_25 ,
F_9 ( V_99 -> V_112 ) ) ;
V_109 -> V_123 = V_95 ;
}
return V_100 ;
}
static bool
F_29 ( char * V_124 )
{
struct V_98 * V_99 = (struct V_98 * ) V_124 ;
struct V_101 * V_102 , * V_125 , * V_126 ;
struct V_105 * V_106 ;
struct V_127 * V_107 ;
struct V_96 * V_97 ;
struct V_89 * V_90 ;
V_90 = F_30 ( sizeof( struct V_89 ) , V_128 ) ;
if ( ! V_90 )
return false ;
F_31 ( & V_90 -> V_91 , F_16 ) ;
V_90 -> V_95 = V_99 -> V_112 ;
F_2 ( V_20 , L_27 ) ;
F_32 ( & V_129 ) ;
F_23 (tmp, &cifs_tcp_ses_list) {
V_106 = F_24 ( V_102 , struct V_105 , V_130 ) ;
F_23 (tmp1, &server->smb_ses_list) {
V_107 = F_24 ( V_125 , struct V_127 , V_131 ) ;
F_32 ( & V_132 ) ;
F_23 (tmp2, &ses->tcon_list) {
V_97 = F_24 ( V_126 , struct V_96 ,
V_133 ) ;
F_33 (
& V_97 -> V_134 . V_135 . V_136 ) ;
if ( F_22 ( V_97 , V_99 , V_90 ) ) {
F_34 ( & V_132 ) ;
F_34 ( & V_129 ) ;
return true ;
}
}
F_34 ( & V_132 ) ;
}
}
F_34 ( & V_129 ) ;
F_21 ( V_90 ) ;
F_2 ( V_20 , L_28 ) ;
return false ;
}
bool
F_35 ( char * V_124 , struct V_105 * V_106 )
{
struct V_137 * V_99 = (struct V_137 * ) V_124 ;
struct V_101 * V_102 , * V_125 , * V_126 ;
struct V_127 * V_107 ;
struct V_96 * V_97 ;
struct V_81 * V_82 ;
struct V_103 * V_104 ;
F_2 ( V_20 , L_29 ) ;
if ( V_99 -> V_2 . V_10 != V_11 )
return false ;
if ( V_99 -> V_26 !=
V_29 [ V_30 ] ) {
if ( F_5 ( V_99 -> V_26 ) == 44 )
return F_29 ( V_124 ) ;
else
return false ;
}
F_2 ( V_20 , L_30 , V_99 -> V_138 ) ;
F_32 ( & V_129 ) ;
F_23 (tmp, &server->smb_ses_list) {
V_107 = F_24 ( V_102 , struct V_127 , V_131 ) ;
F_23 (tmp1, &ses->tcon_list) {
V_97 = F_24 ( V_125 , struct V_96 , V_133 ) ;
F_33 ( & V_97 -> V_134 . V_135 . V_136 ) ;
F_32 ( & V_132 ) ;
F_23 (tmp2, &tcon->openFileList) {
V_104 = F_24 ( V_126 , struct V_103 ,
V_113 ) ;
if ( V_99 -> V_139 !=
V_104 -> V_140 . V_141 ||
V_99 -> V_142 !=
V_104 -> V_140 . V_143 )
continue;
F_2 ( V_20 , L_31 ) ;
V_82 = F_25 ( V_104 -> V_114 -> V_115 ) ;
if ( ! F_13 ( V_82 ) &&
V_99 -> V_138 == V_144 )
V_104 -> V_120 = true ;
else
V_104 -> V_120 = false ;
F_36 ( V_145 ,
& V_82 -> V_146 ) ;
if ( V_99 -> V_138 )
F_36 (
V_147 ,
& V_82 -> V_146 ) ;
else
F_37 (
V_147 ,
& V_82 -> V_146 ) ;
F_26 ( V_121 , & V_104 -> V_122 ) ;
F_34 ( & V_132 ) ;
F_34 ( & V_129 ) ;
return true ;
}
F_34 ( & V_132 ) ;
F_34 ( & V_129 ) ;
F_2 ( V_20 , L_32 ) ;
return true ;
}
}
F_34 ( & V_129 ) ;
F_2 ( V_20 , L_33 ) ;
return false ;
}
