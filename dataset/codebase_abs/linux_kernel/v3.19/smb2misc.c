static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ( * ( V_6 * ) V_2 -> V_7 == V_8 ) &&
( V_3 == V_4 ) ) {
if ( V_2 -> V_9 & V_10 )
return 0 ;
else {
if ( V_2 -> V_11 == V_12 )
return 0 ;
else
F_3 ( V_13 , L_1 ) ;
}
} else {
if ( * ( V_6 * ) V_2 -> V_7 != V_8 )
F_3 ( V_13 , L_2 ,
* ( unsigned int * ) V_2 -> V_7 ) ;
if ( V_3 != V_4 )
F_3 ( V_13 , L_3 ,
V_3 , V_4 ) ;
}
F_3 ( V_13 , L_4 , V_4 ) ;
return 1 ;
}
int
F_4 ( char * V_14 , unsigned int V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_16 * V_17 = (struct V_16 * ) V_2 ;
T_1 V_3 = F_2 ( V_2 -> V_5 ) ;
T_2 V_18 = F_5 ( V_14 ) ;
T_2 V_19 ;
int V_20 ;
F_3 ( V_21 , L_5 ,
V_22 , V_15 , V_18 ) ;
if ( V_15 < sizeof( struct V_16 ) ) {
if ( ( V_15 >= sizeof( struct V_1 ) ) && ( V_2 -> V_23 != 0 ) ) {
V_17 -> V_24 = 0 ;
return 0 ;
} else {
F_3 ( V_13 , L_6 ) ;
}
return 1 ;
}
if ( V_18 > V_25 + V_26 - 4 ) {
F_3 ( V_13 , L_7 ,
V_3 ) ;
return 1 ;
}
if ( F_1 ( V_2 , V_3 ) )
return 1 ;
if ( V_2 -> V_27 != V_28 ) {
F_3 ( V_13 , L_8 ,
F_6 ( V_2 -> V_27 ) ) ;
return 1 ;
}
V_20 = F_6 ( V_2 -> V_11 ) ;
if ( V_20 >= V_29 ) {
F_3 ( V_13 , L_9 , V_20 ) ;
return 1 ;
}
if ( V_30 [ V_20 ] != V_17 -> V_24 ) {
if ( V_20 != V_31 && ( V_2 -> V_23 == 0 ||
V_17 -> V_24 != V_32 ) ) {
F_3 ( V_13 , L_10 ,
F_6 ( V_17 -> V_24 ) , V_20 ) ;
return 1 ;
} else if ( V_20 == V_31 && ( V_2 -> V_23 == 0 )
&& ( F_6 ( V_17 -> V_24 ) != 44 )
&& ( F_6 ( V_17 -> V_24 ) != 36 ) ) {
F_3 ( V_13 , L_11 ,
F_6 ( V_17 -> V_24 ) ) ;
return 1 ;
}
}
if ( 4 + V_18 != V_15 ) {
F_3 ( V_13 , L_12 ,
V_15 , 4 + V_18 , V_3 ) ;
return 1 ;
}
V_19 = F_7 ( V_2 ) ;
if ( 4 + V_18 != V_19 ) {
F_3 ( V_21 , L_13 ,
V_19 , 4 + V_18 , V_3 ) ;
if ( V_20 == V_33 &&
V_2 -> V_23 == V_34 )
return 0 ;
if ( V_19 + 20 == V_18 && V_20 == V_31 )
return 0 ;
if ( V_19 == 4 + V_18 + 1 )
return 0 ;
if ( V_19 < 4 + V_18 ) {
F_8 ( V_35
L_14 ,
V_18 , V_19 - 4 ) ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
char *
F_9 ( int * V_36 , int * V_18 , struct V_1 * V_2 )
{
* V_36 = 0 ;
* V_18 = 0 ;
if ( V_2 -> V_23 && V_2 -> V_23 != V_37 &&
( ( (struct V_38 * ) V_2 ) -> V_27 ) ==
V_32 )
return NULL ;
switch ( V_2 -> V_11 ) {
case V_39 :
* V_36 = F_6 (
( (struct V_40 * ) V_2 ) -> V_41 ) ;
* V_18 = F_6 (
( (struct V_40 * ) V_2 ) -> V_42 ) ;
break;
case V_43 :
* V_36 = F_6 (
( (struct V_44 * ) V_2 ) -> V_41 ) ;
* V_18 = F_6 (
( (struct V_44 * ) V_2 ) -> V_42 ) ;
break;
case V_45 :
* V_36 = F_10 (
( (struct V_46 * ) V_2 ) -> V_47 ) ;
* V_18 = F_10 (
( (struct V_46 * ) V_2 ) -> V_48 ) ;
break;
case V_49 :
* V_36 = F_6 (
( (struct V_50 * ) V_2 ) -> V_51 ) ;
* V_18 = F_10 (
( (struct V_50 * ) V_2 ) -> V_52 ) ;
break;
case V_53 :
* V_36 = ( (struct V_54 * ) V_2 ) -> V_55 ;
* V_18 = F_10 ( ( (struct V_54 * ) V_2 ) -> V_56 ) ;
break;
case V_57 :
* V_36 = F_6 (
( (struct V_58 * ) V_2 ) -> V_51 ) ;
* V_18 = F_10 (
( (struct V_58 * ) V_2 ) -> V_52 ) ;
break;
case V_59 :
* V_36 = F_10 (
( (struct V_60 * ) V_2 ) -> V_61 ) ;
* V_18 = F_10 ( ( (struct V_60 * ) V_2 ) -> V_62 ) ;
break;
case V_63 :
default:
F_3 ( V_13 , L_15 ) ;
break;
}
if ( * V_36 > 4096 ) {
F_3 ( V_13 , L_16 , * V_36 ) ;
* V_18 = 0 ;
* V_36 = 0 ;
} else if ( * V_36 < 0 ) {
F_3 ( V_13 , L_17 ,
* V_36 ) ;
* V_36 = 0 ;
* V_18 = 0 ;
} else if ( * V_18 < 0 ) {
F_3 ( V_13 , L_18 ,
* V_18 ) ;
* V_18 = 0 ;
} else if ( * V_18 > 128 * 1024 ) {
F_3 ( V_13 , L_19 , * V_18 ) ;
* V_18 = 0 ;
}
if ( ( * V_36 != 0 ) && ( * V_18 != 0 ) )
return V_2 -> V_7 + * V_36 ;
else
return NULL ;
}
unsigned int
F_7 ( void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
struct V_16 * V_17 = (struct V_16 * ) V_2 ;
int V_64 ;
int V_65 ;
int V_18 = 4 + F_6 ( V_17 -> V_2 . V_27 ) ;
V_18 += F_6 ( V_17 -> V_24 ) ;
if ( V_66 [ F_6 ( V_2 -> V_11 ) ] == false )
goto V_67;
F_9 ( & V_64 , & V_65 , V_2 ) ;
F_3 ( V_21 , L_20 , V_65 , V_64 ) ;
if ( V_65 > 0 ) {
if ( V_64 + 4 + 1 < V_18 ) {
F_3 ( V_13 , L_21 ,
V_64 + 4 + 1 , V_18 ) ;
V_65 = 0 ;
} else {
V_18 = 4 + V_64 + V_65 ;
}
}
V_67:
F_3 ( V_21 , L_22 , V_18 ) ;
return V_18 ;
}
T_3 *
F_11 ( const char * V_68 , struct V_69 * V_70 )
{
int V_18 ;
const char * V_71 ;
T_3 * V_72 ;
int V_73 ;
if ( V_70 -> V_74 & V_75 )
V_73 = V_76 ;
else if ( V_70 -> V_74 & V_77 )
V_73 = V_78 ;
else
V_73 = V_79 ;
if ( V_68 [ 0 ] == '\\' )
V_71 = V_68 + 1 ;
else
V_71 = V_68 ;
V_72 = F_12 ( V_71 , V_80 , & V_18 ,
V_70 -> V_81 , V_73 ) ;
return V_72 ;
}
V_6
F_13 ( struct V_82 * V_83 )
{
V_6 V_84 = 0 ;
if ( F_14 ( V_83 ) )
V_84 |= V_85 ;
if ( F_15 ( V_83 ) )
V_84 |= V_86 ;
if ( F_16 ( V_83 ) )
V_84 |= V_87 ;
return V_84 ;
}
static void
F_17 ( struct V_88 * V_89 )
{
struct V_90 * V_91 = F_18 ( V_89 ,
struct V_90 , V_92 ) ;
int V_93 ;
V_93 = F_19 ( 0 , F_20 ( V_91 -> V_94 ) , V_91 -> V_95 ,
V_91 -> V_96 ) ;
F_3 ( V_21 , L_23 , V_93 ) ;
F_21 ( V_91 -> V_94 ) ;
F_22 ( V_91 ) ;
}
static bool
F_23 ( struct V_97 * V_98 , struct V_99 * V_100 ,
struct V_90 * V_91 )
{
bool V_101 ;
T_4 V_96 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 = V_98 -> V_108 -> V_107 ;
struct V_109 * V_110 ;
struct V_82 * V_83 ;
int V_111 = F_10 ( V_100 -> V_9 &
V_112 ) ;
V_96 = F_10 ( V_100 -> V_113 ) ;
F_24 (tmp, &tcon->openFileList) {
V_105 = F_25 ( V_103 , struct V_104 , V_114 ) ;
V_83 = F_26 ( V_105 -> V_115 -> V_116 ) ;
if ( memcmp ( V_83 -> V_95 , V_100 -> V_117 ,
V_118 ) )
continue;
F_3 ( V_21 , L_24 ) ;
F_3 ( V_21 , L_25 ,
F_10 ( V_100 -> V_113 ) ) ;
V_107 -> V_119 -> V_120 ( V_83 , V_96 , 0 , NULL ) ;
if ( V_111 )
V_105 -> V_121 = false ;
else
V_105 -> V_121 = true ;
F_27 ( V_122 , & V_105 -> V_123 ) ;
F_22 ( V_91 ) ;
return true ;
}
V_101 = false ;
F_28 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_110 -> V_95 , V_100 -> V_117 ,
V_118 ) )
continue;
if ( ! V_101 && V_111 ) {
V_101 = true ;
memcpy ( V_91 -> V_95 , V_110 -> V_95 ,
V_118 ) ;
V_91 -> V_94 = F_29 ( V_110 -> V_94 ) ;
F_27 ( V_122 , & V_91 -> V_92 ) ;
}
F_3 ( V_21 , L_26 ) ;
F_3 ( V_21 , L_25 ,
F_10 ( V_100 -> V_113 ) ) ;
V_110 -> V_124 = V_96 ;
}
return V_101 ;
}
static bool
F_30 ( char * V_125 )
{
struct V_99 * V_100 = (struct V_99 * ) V_125 ;
struct V_102 * V_103 , * V_126 , * V_127 ;
struct V_106 * V_107 ;
struct V_128 * V_108 ;
struct V_97 * V_98 ;
struct V_90 * V_91 ;
V_91 = F_31 ( sizeof( struct V_90 ) , V_129 ) ;
if ( ! V_91 )
return false ;
F_32 ( & V_91 -> V_92 , F_17 ) ;
V_91 -> V_96 = V_100 -> V_113 ;
F_3 ( V_21 , L_27 ) ;
F_33 ( & V_130 ) ;
F_24 (tmp, &cifs_tcp_ses_list) {
V_107 = F_25 ( V_103 , struct V_106 , V_131 ) ;
F_24 (tmp1, &server->smb_ses_list) {
V_108 = F_25 ( V_126 , struct V_128 , V_132 ) ;
F_33 ( & V_133 ) ;
F_24 (tmp2, &ses->tcon_list) {
V_98 = F_25 ( V_127 , struct V_97 ,
V_134 ) ;
F_34 (
& V_98 -> V_135 . V_136 . V_137 ) ;
if ( F_23 ( V_98 , V_100 , V_91 ) ) {
F_35 ( & V_133 ) ;
F_35 ( & V_130 ) ;
return true ;
}
}
F_35 ( & V_133 ) ;
}
}
F_35 ( & V_130 ) ;
F_22 ( V_91 ) ;
F_3 ( V_21 , L_28 ) ;
return false ;
}
bool
F_36 ( char * V_125 , struct V_106 * V_107 )
{
struct V_138 * V_100 = (struct V_138 * ) V_125 ;
struct V_102 * V_103 , * V_126 , * V_127 ;
struct V_128 * V_108 ;
struct V_97 * V_98 ;
struct V_82 * V_83 ;
struct V_104 * V_105 ;
F_3 ( V_21 , L_29 ) ;
if ( V_100 -> V_2 . V_11 != V_12 )
return false ;
if ( V_100 -> V_27 !=
V_30 [ V_31 ] ) {
if ( F_6 ( V_100 -> V_27 ) == 44 )
return F_30 ( V_125 ) ;
else
return false ;
}
F_3 ( V_21 , L_30 , V_100 -> V_139 ) ;
F_33 ( & V_130 ) ;
F_24 (tmp, &server->smb_ses_list) {
V_108 = F_25 ( V_103 , struct V_128 , V_132 ) ;
F_24 (tmp1, &ses->tcon_list) {
V_98 = F_25 ( V_126 , struct V_97 , V_134 ) ;
F_34 ( & V_98 -> V_135 . V_136 . V_137 ) ;
F_33 ( & V_133 ) ;
F_24 (tmp2, &tcon->openFileList) {
V_105 = F_25 ( V_127 , struct V_104 ,
V_114 ) ;
if ( V_100 -> V_140 !=
V_105 -> V_141 . V_142 ||
V_100 -> V_143 !=
V_105 -> V_141 . V_144 )
continue;
F_3 ( V_21 , L_31 ) ;
V_83 = F_26 ( V_105 -> V_115 -> V_116 ) ;
if ( ! F_14 ( V_83 ) &&
V_100 -> V_139 == V_145 )
V_105 -> V_121 = true ;
else
V_105 -> V_121 = false ;
F_37 ( V_146 ,
& V_83 -> V_147 ) ;
if ( V_100 -> V_139 )
F_37 (
V_148 ,
& V_83 -> V_147 ) ;
else
F_38 (
V_148 ,
& V_83 -> V_147 ) ;
F_27 ( V_122 , & V_105 -> V_123 ) ;
F_35 ( & V_133 ) ;
F_35 ( & V_130 ) ;
return true ;
}
F_35 ( & V_133 ) ;
F_35 ( & V_130 ) ;
F_3 ( V_21 , L_32 ) ;
return true ;
}
}
F_35 ( & V_130 ) ;
F_3 ( V_21 , L_33 ) ;
return false ;
}
