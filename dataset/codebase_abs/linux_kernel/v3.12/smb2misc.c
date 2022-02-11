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
return 1 ;
}
return 0 ;
}
char *
F_7 ( int * V_34 , int * V_17 , struct V_1 * V_2 )
{
* V_34 = 0 ;
* V_17 = 0 ;
if ( V_2 -> V_22 && V_2 -> V_22 != V_35 &&
( ( (struct V_36 * ) V_2 ) -> V_26 ) ==
V_31 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_37 :
* V_34 = F_5 (
( (struct V_38 * ) V_2 ) -> V_39 ) ;
* V_17 = F_5 (
( (struct V_38 * ) V_2 ) -> V_40 ) ;
break;
case V_41 :
* V_34 = F_5 (
( (struct V_42 * ) V_2 ) -> V_39 ) ;
* V_17 = F_5 (
( (struct V_42 * ) V_2 ) -> V_40 ) ;
break;
case V_43 :
* V_34 = F_8 (
( (struct V_44 * ) V_2 ) -> V_45 ) ;
* V_17 = F_8 (
( (struct V_44 * ) V_2 ) -> V_46 ) ;
break;
case V_47 :
* V_34 = F_5 (
( (struct V_48 * ) V_2 ) -> V_49 ) ;
* V_17 = F_8 (
( (struct V_48 * ) V_2 ) -> V_50 ) ;
break;
case V_51 :
* V_34 = ( (struct V_52 * ) V_2 ) -> V_53 ;
* V_17 = F_8 ( ( (struct V_52 * ) V_2 ) -> V_54 ) ;
break;
case V_55 :
* V_34 = F_5 (
( (struct V_56 * ) V_2 ) -> V_49 ) ;
* V_17 = F_8 (
( (struct V_56 * ) V_2 ) -> V_50 ) ;
break;
case V_57 :
* V_34 = F_8 (
( (struct V_58 * ) V_2 ) -> V_59 ) ;
* V_17 = F_8 ( ( (struct V_58 * ) V_2 ) -> V_60 ) ;
break;
case V_61 :
default:
F_2 ( V_12 , L_14 ) ;
break;
}
if ( * V_34 > 4096 ) {
F_2 ( V_12 , L_15 , * V_34 ) ;
* V_17 = 0 ;
* V_34 = 0 ;
} else if ( * V_34 < 0 ) {
F_2 ( V_12 , L_16 ,
* V_34 ) ;
* V_34 = 0 ;
* V_17 = 0 ;
} else if ( * V_17 < 0 ) {
F_2 ( V_12 , L_17 ,
* V_17 ) ;
* V_17 = 0 ;
} else if ( * V_17 > 128 * 1024 ) {
F_2 ( V_12 , L_18 , * V_17 ) ;
* V_17 = 0 ;
}
if ( ( * V_34 != 0 ) && ( * V_17 != 0 ) )
return V_2 -> V_5 + * V_34 ;
else
return NULL ;
}
unsigned int
F_6 ( void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_15 * V_16 = (struct V_15 * ) V_2 ;
int V_62 ;
int V_63 ;
int V_17 = 4 + F_5 ( V_16 -> V_2 . V_26 ) ;
V_17 += F_5 ( V_16 -> V_23 ) ;
if ( V_64 [ F_5 ( V_2 -> V_10 ) ] == false )
goto V_65;
F_7 ( & V_62 , & V_63 , V_2 ) ;
F_2 ( V_20 , L_19 , V_63 , V_62 ) ;
if ( V_63 > 0 ) {
if ( V_62 + 4 + 1 < V_17 ) {
F_2 ( V_12 , L_20 ,
V_62 + 4 + 1 , V_17 ) ;
V_63 = 0 ;
} else {
V_17 = 4 + V_62 + V_63 ;
}
}
V_65:
F_2 ( V_20 , L_21 , V_17 ) ;
return V_17 ;
}
T_3 *
F_9 ( const char * V_66 , struct V_67 * V_68 )
{
int V_17 ;
const char * V_69 ;
T_3 * V_70 ;
if ( V_66 [ 0 ] == '\\' )
V_69 = V_66 + 1 ;
else
V_69 = V_66 ;
V_70 = F_10 ( V_69 , V_71 , & V_17 ,
V_68 -> V_72 ,
V_68 -> V_73 &
V_74 ) ;
return V_70 ;
}
V_4
F_11 ( struct V_75 * V_76 )
{
V_4 V_77 = 0 ;
if ( F_12 ( V_76 ) )
V_77 |= V_78 ;
if ( F_13 ( V_76 ) )
V_77 |= V_79 ;
if ( F_14 ( V_76 ) )
V_77 |= V_80 ;
return V_77 ;
}
static void
F_15 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = F_16 ( V_82 ,
struct V_83 , V_85 ) ;
int V_86 ;
V_86 = F_17 ( 0 , F_18 ( V_84 -> V_87 ) , V_84 -> V_88 ,
V_84 -> V_89 ) ;
F_2 ( V_20 , L_22 , V_86 ) ;
F_19 ( V_84 -> V_87 ) ;
F_20 ( V_84 ) ;
}
static bool
F_21 ( struct V_90 * V_91 , struct V_92 * V_93 ,
struct V_83 * V_84 )
{
bool V_94 ;
T_4 V_89 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_100 = V_91 -> V_101 -> V_100 ;
struct V_102 * V_103 ;
struct V_75 * V_76 ;
int V_104 = F_8 ( V_93 -> V_8 &
V_105 ) ;
V_89 = F_8 ( V_93 -> V_106 ) ;
F_22 (tmp, &tcon->openFileList) {
V_98 = F_23 ( V_96 , struct V_97 , V_107 ) ;
V_76 = F_24 ( V_98 -> V_108 -> V_109 ) ;
if ( memcmp ( V_76 -> V_88 , V_93 -> V_110 ,
V_111 ) )
continue;
F_2 ( V_20 , L_23 ) ;
F_2 ( V_20 , L_24 ,
F_8 ( V_93 -> V_106 ) ) ;
V_100 -> V_112 -> V_113 ( V_76 , V_89 , 0 , NULL ) ;
if ( V_104 )
V_98 -> V_114 = false ;
else
V_98 -> V_114 = true ;
F_25 ( V_115 , & V_98 -> V_116 ) ;
F_20 ( V_84 ) ;
return true ;
}
V_94 = false ;
F_26 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_103 -> V_88 , V_93 -> V_110 ,
V_111 ) )
continue;
if ( ! V_94 && V_104 ) {
V_94 = true ;
memcpy ( V_84 -> V_88 , V_103 -> V_88 ,
V_111 ) ;
V_84 -> V_87 = F_27 ( V_103 -> V_87 ) ;
F_25 ( V_115 , & V_84 -> V_85 ) ;
}
F_2 ( V_20 , L_25 ) ;
F_2 ( V_20 , L_24 ,
F_8 ( V_93 -> V_106 ) ) ;
V_103 -> V_117 = V_89 ;
}
return V_94 ;
}
static bool
F_28 ( char * V_118 )
{
struct V_92 * V_93 = (struct V_92 * ) V_118 ;
struct V_95 * V_96 , * V_119 , * V_120 ;
struct V_99 * V_100 ;
struct V_121 * V_101 ;
struct V_90 * V_91 ;
struct V_83 * V_84 ;
V_84 = F_29 ( sizeof( struct V_83 ) , V_122 ) ;
if ( ! V_84 )
return false ;
F_30 ( & V_84 -> V_85 , F_15 ) ;
V_84 -> V_89 = V_93 -> V_106 ;
F_2 ( V_20 , L_26 ) ;
F_31 ( & V_123 ) ;
F_22 (tmp, &cifs_tcp_ses_list) {
V_100 = F_23 ( V_96 , struct V_99 , V_124 ) ;
F_22 (tmp1, &server->smb_ses_list) {
V_101 = F_23 ( V_119 , struct V_121 , V_125 ) ;
F_31 ( & V_126 ) ;
F_22 (tmp2, &ses->tcon_list) {
V_91 = F_23 ( V_120 , struct V_90 ,
V_127 ) ;
F_32 (
& V_91 -> V_128 . V_129 . V_130 ) ;
if ( F_21 ( V_91 , V_93 , V_84 ) ) {
F_33 ( & V_126 ) ;
F_33 ( & V_123 ) ;
return true ;
}
}
F_33 ( & V_126 ) ;
}
}
F_33 ( & V_123 ) ;
F_20 ( V_84 ) ;
F_2 ( V_20 , L_27 ) ;
return false ;
}
bool
F_34 ( char * V_118 , struct V_99 * V_100 )
{
struct V_131 * V_93 = (struct V_131 * ) V_118 ;
struct V_95 * V_96 , * V_119 , * V_120 ;
struct V_121 * V_101 ;
struct V_90 * V_91 ;
struct V_75 * V_76 ;
struct V_97 * V_98 ;
F_2 ( V_20 , L_28 ) ;
if ( V_93 -> V_2 . V_10 != V_11 )
return false ;
if ( V_93 -> V_26 !=
V_29 [ V_30 ] ) {
if ( F_5 ( V_93 -> V_26 ) == 44 )
return F_28 ( V_118 ) ;
else
return false ;
}
F_2 ( V_20 , L_29 , V_93 -> V_132 ) ;
F_31 ( & V_123 ) ;
F_22 (tmp, &server->smb_ses_list) {
V_101 = F_23 ( V_96 , struct V_121 , V_125 ) ;
F_22 (tmp1, &ses->tcon_list) {
V_91 = F_23 ( V_119 , struct V_90 , V_127 ) ;
F_32 ( & V_91 -> V_128 . V_129 . V_130 ) ;
F_31 ( & V_126 ) ;
F_22 (tmp2, &tcon->openFileList) {
V_98 = F_23 ( V_120 , struct V_97 ,
V_107 ) ;
if ( V_93 -> V_133 !=
V_98 -> V_134 . V_135 ||
V_93 -> V_136 !=
V_98 -> V_134 . V_137 )
continue;
F_2 ( V_20 , L_30 ) ;
V_76 = F_24 ( V_98 -> V_108 -> V_109 ) ;
if ( ! F_12 ( V_76 ) &&
V_93 -> V_132 == V_138 )
V_98 -> V_114 = true ;
else
V_98 -> V_114 = false ;
V_100 -> V_112 -> V_113 ( V_76 ,
V_93 -> V_132 ? V_139 : 0 ,
0 , NULL ) ;
F_25 ( V_115 , & V_98 -> V_116 ) ;
F_33 ( & V_126 ) ;
F_33 ( & V_123 ) ;
return true ;
}
F_33 ( & V_126 ) ;
F_33 ( & V_123 ) ;
F_2 ( V_20 , L_31 ) ;
return true ;
}
}
F_33 ( & V_123 ) ;
F_2 ( V_20 , L_32 ) ;
return false ;
}
