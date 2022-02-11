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
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_17 * V_18 = (struct V_17 * ) V_2 ;
T_1 V_3 ;
T_2 V_19 = F_6 ( V_13 ) ;
T_2 V_20 ;
int V_21 ;
F_3 ( V_22 , L_5 ,
V_23 , V_14 , V_19 ) ;
if ( V_2 -> V_6 == V_24 ) {
struct V_25 * V_26 =
(struct V_25 * ) V_13 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 ;
F_7 ( & V_31 ) ;
F_8 (tmp, &srvr->smb_ses_list) {
V_28 = F_9 ( V_30 , struct V_27 , V_32 ) ;
if ( V_28 -> V_33 == V_26 -> V_34 )
break;
V_28 = NULL ;
}
F_10 ( & V_31 ) ;
if ( V_28 == NULL ) {
F_3 ( V_12 , L_6 ) ;
return 1 ;
}
}
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_14 < sizeof( struct V_17 ) ) {
if ( ( V_14 >= sizeof( struct V_1 ) ) && ( V_2 -> V_35 != 0 ) ) {
V_18 -> V_36 = 0 ;
return 0 ;
} else {
F_3 ( V_12 , L_7 ) ;
}
return 1 ;
}
if ( V_19 > V_37 + V_38 - 4 ) {
F_3 ( V_12 , L_8 ,
V_3 ) ;
return 1 ;
}
if ( F_1 ( V_2 , V_3 ) )
return 1 ;
if ( V_2 -> V_39 != V_40 ) {
F_3 ( V_12 , L_9 ,
F_11 ( V_2 -> V_39 ) ) ;
return 1 ;
}
V_21 = F_11 ( V_2 -> V_10 ) ;
if ( V_21 >= V_41 ) {
F_3 ( V_12 , L_10 , V_21 ) ;
return 1 ;
}
if ( V_42 [ V_21 ] != V_18 -> V_36 ) {
if ( V_21 != V_43 && ( V_2 -> V_35 == 0 ||
V_18 -> V_36 != V_44 ) ) {
F_3 ( V_12 , L_11 ,
F_11 ( V_18 -> V_36 ) , V_21 ) ;
return 1 ;
} else if ( V_21 == V_43 && ( V_2 -> V_35 == 0 )
&& ( F_11 ( V_18 -> V_36 ) != 44 )
&& ( F_11 ( V_18 -> V_36 ) != 36 ) ) {
F_3 ( V_12 , L_12 ,
F_11 ( V_18 -> V_36 ) ) ;
return 1 ;
}
}
if ( 4 + V_19 != V_14 ) {
F_3 ( V_12 , L_13 ,
V_14 , 4 + V_19 , V_3 ) ;
return 1 ;
}
V_20 = F_12 ( V_2 ) ;
if ( 4 + V_19 != V_20 ) {
F_3 ( V_22 , L_14 ,
V_20 , 4 + V_19 , V_3 ) ;
if ( V_21 == V_45 &&
V_2 -> V_35 == V_46 )
return 0 ;
if ( V_20 + 20 == V_19 && V_21 == V_43 )
return 0 ;
if ( V_20 == 4 + V_19 + 1 )
return 0 ;
if ( V_20 < 4 + V_19 ) {
F_13 ( V_47
L_15 ,
V_19 , V_20 - 4 ) ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
char *
F_14 ( int * V_48 , int * V_19 , struct V_1 * V_2 )
{
* V_48 = 0 ;
* V_19 = 0 ;
if ( V_2 -> V_35 && V_2 -> V_35 != V_49 &&
( ( (struct V_50 * ) V_2 ) -> V_39 ) ==
V_44 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_51 :
* V_48 = F_11 (
( (struct V_52 * ) V_2 ) -> V_53 ) ;
* V_19 = F_11 (
( (struct V_52 * ) V_2 ) -> V_54 ) ;
break;
case V_55 :
* V_48 = F_11 (
( (struct V_56 * ) V_2 ) -> V_53 ) ;
* V_19 = F_11 (
( (struct V_56 * ) V_2 ) -> V_54 ) ;
break;
case V_57 :
* V_48 = F_4 (
( (struct V_58 * ) V_2 ) -> V_59 ) ;
* V_19 = F_4 (
( (struct V_58 * ) V_2 ) -> V_60 ) ;
break;
case V_61 :
* V_48 = F_11 (
( (struct V_62 * ) V_2 ) -> V_63 ) ;
* V_19 = F_4 (
( (struct V_62 * ) V_2 ) -> V_64 ) ;
break;
case V_65 :
* V_48 = ( (struct V_66 * ) V_2 ) -> V_67 ;
* V_19 = F_4 ( ( (struct V_66 * ) V_2 ) -> V_68 ) ;
break;
case V_69 :
* V_48 = F_11 (
( (struct V_70 * ) V_2 ) -> V_63 ) ;
* V_19 = F_4 (
( (struct V_70 * ) V_2 ) -> V_64 ) ;
break;
case V_71 :
* V_48 = F_4 (
( (struct V_72 * ) V_2 ) -> V_73 ) ;
* V_19 = F_4 ( ( (struct V_72 * ) V_2 ) -> V_74 ) ;
break;
case V_75 :
default:
F_3 ( V_12 , L_16 ) ;
break;
}
if ( * V_48 > 4096 ) {
F_3 ( V_12 , L_17 , * V_48 ) ;
* V_19 = 0 ;
* V_48 = 0 ;
} else if ( * V_48 < 0 ) {
F_3 ( V_12 , L_18 ,
* V_48 ) ;
* V_48 = 0 ;
* V_19 = 0 ;
} else if ( * V_19 < 0 ) {
F_3 ( V_12 , L_19 ,
* V_19 ) ;
* V_19 = 0 ;
} else if ( * V_19 > 128 * 1024 ) {
F_3 ( V_12 , L_20 , * V_19 ) ;
* V_19 = 0 ;
}
if ( ( * V_48 != 0 ) && ( * V_19 != 0 ) )
return ( char * ) ( & V_2 -> V_6 ) + * V_48 ;
else
return NULL ;
}
unsigned int
F_12 ( void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_17 * V_18 = (struct V_17 * ) V_2 ;
int V_76 ;
int V_77 ;
int V_19 = 4 + F_11 ( V_18 -> V_2 . V_39 ) ;
V_19 += F_11 ( V_18 -> V_36 ) ;
if ( V_78 [ F_11 ( V_2 -> V_10 ) ] == false )
goto V_79;
F_14 ( & V_76 , & V_77 , V_2 ) ;
F_3 ( V_22 , L_21 , V_77 , V_76 ) ;
if ( V_77 > 0 ) {
if ( V_76 + 4 + 1 < V_19 ) {
F_3 ( V_12 , L_22 ,
V_76 + 4 + 1 , V_19 ) ;
V_77 = 0 ;
} else {
V_19 = 4 + V_76 + V_77 ;
}
}
V_79:
F_3 ( V_22 , L_23 , V_19 ) ;
return V_19 ;
}
T_3 *
F_15 ( const char * V_80 , struct V_81 * V_82 )
{
int V_19 ;
const char * V_83 ;
T_3 * V_84 ;
int V_85 ;
if ( V_82 -> V_86 & V_87 )
V_85 = V_88 ;
else if ( V_82 -> V_86 & V_89 )
V_85 = V_90 ;
else
V_85 = V_91 ;
if ( V_80 [ 0 ] == '\\' )
V_83 = V_80 + 1 ;
else
V_83 = V_80 ;
V_84 = F_16 ( V_83 , V_92 , & V_19 ,
V_82 -> V_93 , V_85 ) ;
return V_84 ;
}
T_4
F_17 ( struct V_94 * V_95 )
{
T_4 V_96 = 0 ;
if ( F_18 ( V_95 ) )
V_96 |= V_97 ;
if ( F_19 ( V_95 ) )
V_96 |= V_98 ;
if ( F_20 ( V_95 ) )
V_96 |= V_99 ;
return V_96 ;
}
static void
F_21 ( struct V_100 * V_101 )
{
struct V_102 * V_103 = F_22 ( V_101 ,
struct V_102 , V_104 ) ;
int V_105 ;
V_105 = F_23 ( 0 , F_24 ( V_103 -> V_106 ) , V_103 -> V_107 ,
V_103 -> V_108 ) ;
F_3 ( V_22 , L_24 , V_105 ) ;
F_25 ( V_103 -> V_106 ) ;
F_26 ( V_103 ) ;
}
static bool
F_27 ( struct V_109 * V_110 , struct V_111 * V_112 ,
struct V_102 * V_103 )
{
bool V_113 ;
T_5 V_108 ;
struct V_29 * V_30 ;
struct V_114 * V_115 ;
struct V_15 * V_116 = V_110 -> V_28 -> V_116 ;
struct V_117 * V_118 ;
struct V_94 * V_95 ;
int V_119 = F_4 ( V_112 -> V_8 &
V_120 ) ;
V_108 = F_4 ( V_112 -> V_121 ) ;
F_8 (tmp, &tcon->openFileList) {
V_115 = F_9 ( V_30 , struct V_114 , V_122 ) ;
V_95 = F_28 ( F_29 ( V_115 -> V_123 ) ) ;
if ( memcmp ( V_95 -> V_107 , V_112 -> V_124 ,
V_125 ) )
continue;
F_3 ( V_22 , L_25 ) ;
F_3 ( V_22 , L_26 ,
F_4 ( V_112 -> V_121 ) ) ;
V_116 -> V_126 -> V_127 ( V_95 , V_108 , 0 , NULL ) ;
if ( V_119 )
V_115 -> V_128 = false ;
else
V_115 -> V_128 = true ;
F_30 ( V_129 , & V_115 -> V_130 ) ;
F_26 ( V_103 ) ;
return true ;
}
V_113 = false ;
F_31 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_118 -> V_107 , V_112 -> V_124 ,
V_125 ) )
continue;
if ( ! V_113 && V_119 ) {
V_113 = true ;
memcpy ( V_103 -> V_107 , V_118 -> V_107 ,
V_125 ) ;
V_103 -> V_106 = F_32 ( V_118 -> V_106 ) ;
F_30 ( V_129 , & V_103 -> V_104 ) ;
}
F_3 ( V_22 , L_27 ) ;
F_3 ( V_22 , L_26 ,
F_4 ( V_112 -> V_121 ) ) ;
V_118 -> V_131 = V_108 ;
}
return V_113 ;
}
static bool
F_33 ( char * V_132 )
{
struct V_111 * V_112 = (struct V_111 * ) V_132 ;
struct V_29 * V_30 , * V_133 , * V_134 ;
struct V_15 * V_116 ;
struct V_27 * V_28 ;
struct V_109 * V_110 ;
struct V_102 * V_103 ;
V_103 = F_34 ( sizeof( struct V_102 ) , V_135 ) ;
if ( ! V_103 )
return false ;
F_35 ( & V_103 -> V_104 , F_21 ) ;
V_103 -> V_108 = V_112 -> V_121 ;
F_3 ( V_22 , L_28 ) ;
F_7 ( & V_31 ) ;
F_8 (tmp, &cifs_tcp_ses_list) {
V_116 = F_9 ( V_30 , struct V_15 , V_136 ) ;
F_8 (tmp1, &server->smb_ses_list) {
V_28 = F_9 ( V_133 , struct V_27 , V_32 ) ;
F_7 ( & V_137 ) ;
F_8 (tmp2, &ses->tcon_list) {
V_110 = F_9 ( V_134 , struct V_109 ,
V_138 ) ;
F_36 (
& V_110 -> V_139 . V_140 . V_141 ) ;
if ( F_27 ( V_110 , V_112 , V_103 ) ) {
F_10 ( & V_137 ) ;
F_10 ( & V_31 ) ;
return true ;
}
}
F_10 ( & V_137 ) ;
}
}
F_10 ( & V_31 ) ;
F_26 ( V_103 ) ;
F_3 ( V_22 , L_29 ) ;
return false ;
}
bool
F_37 ( char * V_132 , struct V_15 * V_116 )
{
struct V_142 * V_112 = (struct V_142 * ) V_132 ;
struct V_29 * V_30 , * V_133 , * V_134 ;
struct V_27 * V_28 ;
struct V_109 * V_110 ;
struct V_94 * V_95 ;
struct V_114 * V_115 ;
F_3 ( V_22 , L_30 ) ;
if ( V_112 -> V_2 . V_10 != V_11 )
return false ;
if ( V_112 -> V_39 !=
V_42 [ V_43 ] ) {
if ( F_11 ( V_112 -> V_39 ) == 44 )
return F_33 ( V_132 ) ;
else
return false ;
}
F_3 ( V_22 , L_31 , V_112 -> V_143 ) ;
F_7 ( & V_31 ) ;
F_8 (tmp, &server->smb_ses_list) {
V_28 = F_9 ( V_30 , struct V_27 , V_32 ) ;
F_8 (tmp1, &ses->tcon_list) {
V_110 = F_9 ( V_133 , struct V_109 , V_138 ) ;
F_36 ( & V_110 -> V_139 . V_140 . V_141 ) ;
F_7 ( & V_137 ) ;
F_8 (tmp2, &tcon->openFileList) {
V_115 = F_9 ( V_134 , struct V_114 ,
V_122 ) ;
if ( V_112 -> V_144 !=
V_115 -> V_145 . V_146 ||
V_112 -> V_147 !=
V_115 -> V_145 . V_148 )
continue;
F_3 ( V_22 , L_32 ) ;
V_95 = F_28 ( F_29 ( V_115 -> V_123 ) ) ;
if ( ! F_18 ( V_95 ) &&
V_112 -> V_143 == V_149 )
V_115 -> V_128 = true ;
else
V_115 -> V_128 = false ;
F_38 ( V_150 ,
& V_95 -> V_151 ) ;
if ( V_112 -> V_143 )
F_38 (
V_152 ,
& V_95 -> V_151 ) ;
else
F_39 (
V_152 ,
& V_95 -> V_151 ) ;
F_30 ( V_129 , & V_115 -> V_130 ) ;
F_10 ( & V_137 ) ;
F_10 ( & V_31 ) ;
return true ;
}
F_10 ( & V_137 ) ;
F_10 ( & V_31 ) ;
F_3 ( V_22 , L_33 ) ;
return true ;
}
}
F_10 ( & V_31 ) ;
F_3 ( V_22 , L_34 ) ;
return false ;
}
