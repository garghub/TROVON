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
if ( V_18 + 20 == V_17 && V_19 == V_30 )
return 0 ;
if ( V_18 == 4 + V_17 + 1 )
return 0 ;
return 1 ;
}
return 0 ;
}
char *
F_7 ( int * V_32 , int * V_17 , struct V_1 * V_2 )
{
* V_32 = 0 ;
* V_17 = 0 ;
if ( V_2 -> V_22 && V_2 -> V_22 != V_33 &&
( ( (struct V_34 * ) V_2 ) -> V_26 ) ==
V_31 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_35 :
* V_32 = F_5 (
( (struct V_36 * ) V_2 ) -> V_37 ) ;
* V_17 = F_5 (
( (struct V_36 * ) V_2 ) -> V_38 ) ;
break;
case V_39 :
* V_32 = F_5 (
( (struct V_40 * ) V_2 ) -> V_37 ) ;
* V_17 = F_5 (
( (struct V_40 * ) V_2 ) -> V_38 ) ;
break;
case V_41 :
* V_32 = F_8 (
( (struct V_42 * ) V_2 ) -> V_43 ) ;
* V_17 = F_8 (
( (struct V_42 * ) V_2 ) -> V_44 ) ;
break;
case V_45 :
* V_32 = F_5 (
( (struct V_46 * ) V_2 ) -> V_47 ) ;
* V_17 = F_8 (
( (struct V_46 * ) V_2 ) -> V_48 ) ;
break;
case V_49 :
* V_32 = ( (struct V_50 * ) V_2 ) -> V_51 ;
* V_17 = F_8 ( ( (struct V_50 * ) V_2 ) -> V_52 ) ;
break;
case V_53 :
* V_32 = F_5 (
( (struct V_54 * ) V_2 ) -> V_47 ) ;
* V_17 = F_8 (
( (struct V_54 * ) V_2 ) -> V_48 ) ;
break;
case V_55 :
case V_56 :
default:
F_2 ( V_12 , L_14 ) ;
break;
}
if ( * V_32 > 4096 ) {
F_2 ( V_12 , L_15 , * V_32 ) ;
* V_17 = 0 ;
* V_32 = 0 ;
} else if ( * V_32 < 0 ) {
F_2 ( V_12 , L_16 ,
* V_32 ) ;
* V_32 = 0 ;
* V_17 = 0 ;
} else if ( * V_17 < 0 ) {
F_2 ( V_12 , L_17 ,
* V_17 ) ;
* V_17 = 0 ;
} else if ( * V_17 > 128 * 1024 ) {
F_2 ( V_12 , L_18 , * V_17 ) ;
* V_17 = 0 ;
}
if ( ( * V_32 != 0 ) && ( * V_17 != 0 ) )
return V_2 -> V_5 + * V_32 ;
else
return NULL ;
}
unsigned int
F_6 ( void * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_15 * V_16 = (struct V_15 * ) V_2 ;
int V_57 ;
int V_58 ;
int V_17 = 4 + F_5 ( V_16 -> V_2 . V_26 ) ;
V_17 += F_5 ( V_16 -> V_23 ) ;
if ( V_59 [ F_5 ( V_2 -> V_10 ) ] == false )
goto V_60;
F_7 ( & V_57 , & V_58 , V_2 ) ;
F_2 ( V_20 , L_19 , V_58 , V_57 ) ;
if ( V_58 > 0 ) {
if ( V_57 + 4 + 1 < V_17 ) {
F_2 ( V_12 , L_20 ,
V_57 + 4 + 1 , V_17 ) ;
V_58 = 0 ;
} else {
V_17 = 4 + V_57 + V_58 ;
}
}
V_60:
F_2 ( V_20 , L_21 , V_17 ) ;
return V_17 ;
}
T_3 *
F_9 ( const char * V_61 , struct V_62 * V_63 )
{
int V_17 ;
const char * V_64 ;
T_3 * V_65 ;
if ( V_61 [ 0 ] == '\\' )
V_64 = V_61 + 1 ;
else
V_64 = V_61 ;
V_65 = F_10 ( V_64 , V_66 , & V_17 ,
V_63 -> V_67 ,
V_63 -> V_68 &
V_69 ) ;
return V_65 ;
}
V_4
F_11 ( struct V_70 * V_71 )
{
if ( V_71 -> V_72 )
return V_73 | V_74 ;
else if ( V_71 -> V_75 )
return V_74 ;
return 0 ;
}
T_4 F_12 ( V_4 V_76 )
{
if ( V_76 & V_73 ) {
if ( V_76 & V_77 )
return V_78 ;
else
return V_79 ;
} else if ( V_76 & V_74 )
return V_80 ;
return 0 ;
}
static void
F_13 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = F_14 ( V_82 ,
struct V_83 , V_85 ) ;
int V_86 ;
V_86 = F_15 ( 0 , F_16 ( V_84 -> V_87 ) , V_84 -> V_88 ,
V_84 -> V_76 ) ;
F_2 ( V_20 , L_22 , V_86 ) ;
F_17 ( V_84 -> V_87 ) ;
F_18 ( V_84 ) ;
}
static bool
F_19 ( char * V_89 , struct V_90 * V_91 )
{
struct V_92 * V_93 = (struct V_92 * ) V_89 ;
struct V_94 * V_95 , * V_96 , * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_70 * V_71 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_83 * V_84 ;
bool V_106 ;
int V_107 = F_8 ( V_93 -> V_8 &
V_108 ) ;
V_84 = F_20 ( sizeof( struct V_83 ) , V_109 ) ;
if ( ! V_84 )
return false ;
F_21 ( & V_84 -> V_85 , F_13 ) ;
V_84 -> V_76 = V_93 -> V_110 ;
F_2 ( V_20 , L_23 ) ;
F_22 ( & V_111 ) ;
F_23 (tmp, &server->smb_ses_list) {
V_99 = F_24 ( V_95 , struct V_98 , V_112 ) ;
F_22 ( & V_113 ) ;
F_23 (tmp1, &ses->tcon_list) {
V_101 = F_24 ( V_96 , struct V_100 , V_114 ) ;
F_25 ( & V_101 -> V_115 . V_116 . V_117 ) ;
F_23 (tmp2, &tcon->openFileList) {
V_103 = F_24 ( V_97 , struct V_102 ,
V_118 ) ;
V_71 = F_26 ( V_103 -> V_119 -> V_120 ) ;
if ( memcmp ( V_71 -> V_88 , V_93 -> V_121 ,
V_122 ) )
continue;
F_2 ( V_20 , L_24 ) ;
F_2 ( V_20 , L_25 ,
F_8 ( V_93 -> V_110 ) ) ;
F_27 ( V_71 ,
F_12 ( V_93 -> V_110 ) ) ;
if ( V_107 )
V_103 -> V_123 = false ;
else
V_103 -> V_123 = true ;
F_28 ( V_124 , & V_103 -> V_125 ) ;
F_29 ( & V_113 ) ;
F_29 ( & V_111 ) ;
return true ;
}
V_106 = false ;
F_30 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_105 -> V_88 , V_93 -> V_121 ,
V_122 ) )
continue;
if ( ! V_106 && V_107 ) {
V_106 = true ;
memcpy ( V_84 -> V_88 , V_105 -> V_88 ,
V_122 ) ;
V_84 -> V_87 = F_31 ( V_105 -> V_87 ) ;
F_28 ( V_124 ,
& V_84 -> V_85 ) ;
}
F_2 ( V_20 , L_26 ) ;
F_2 ( V_20 , L_25 ,
F_8 ( V_93 -> V_110 ) ) ;
V_105 -> V_126 =
F_12 ( V_93 -> V_110 ) ;
}
if ( V_106 ) {
F_29 ( & V_113 ) ;
F_29 ( & V_111 ) ;
return true ;
}
}
F_29 ( & V_113 ) ;
}
F_29 ( & V_111 ) ;
F_18 ( V_84 ) ;
F_2 ( V_20 , L_27 ) ;
return false ;
}
bool
F_32 ( char * V_89 , struct V_90 * V_91 )
{
struct V_127 * V_93 = (struct V_127 * ) V_89 ;
struct V_94 * V_95 , * V_96 , * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_70 * V_71 ;
struct V_102 * V_103 ;
F_2 ( V_20 , L_28 ) ;
if ( V_93 -> V_2 . V_10 != V_11 )
return false ;
if ( V_93 -> V_26 !=
V_29 [ V_30 ] ) {
if ( F_5 ( V_93 -> V_26 ) == 44 )
return F_19 ( V_89 , V_91 ) ;
else
return false ;
}
F_2 ( V_20 , L_29 , V_93 -> V_128 ) ;
F_22 ( & V_111 ) ;
F_23 (tmp, &server->smb_ses_list) {
V_99 = F_24 ( V_95 , struct V_98 , V_112 ) ;
F_23 (tmp1, &ses->tcon_list) {
V_101 = F_24 ( V_96 , struct V_100 , V_114 ) ;
F_25 ( & V_101 -> V_115 . V_116 . V_117 ) ;
F_22 ( & V_113 ) ;
F_23 (tmp2, &tcon->openFileList) {
V_103 = F_24 ( V_97 , struct V_102 ,
V_118 ) ;
if ( V_93 -> V_129 !=
V_103 -> V_130 . V_131 ||
V_93 -> V_132 !=
V_103 -> V_130 . V_133 )
continue;
F_2 ( V_20 , L_30 ) ;
V_71 = F_26 ( V_103 -> V_119 -> V_120 ) ;
if ( ! V_71 -> V_72 &&
V_93 -> V_128 == V_134 )
V_103 -> V_123 = true ;
else
V_103 -> V_123 = false ;
F_27 ( V_71 ,
V_93 -> V_128 ? V_80 : 0 ) ;
F_28 ( V_124 , & V_103 -> V_125 ) ;
F_29 ( & V_113 ) ;
F_29 ( & V_111 ) ;
return true ;
}
F_29 ( & V_113 ) ;
F_29 ( & V_111 ) ;
F_2 ( V_20 , L_31 ) ;
return true ;
}
}
F_29 ( & V_111 ) ;
F_2 ( V_20 , L_32 ) ;
return false ;
}
