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
F_2 ( 1 , L_1 ) ;
}
} else {
if ( * ( V_4 * ) V_2 -> V_5 != V_6 )
F_2 ( 1 , L_2 ,
* ( unsigned int * ) V_2 -> V_5 ) ;
if ( V_3 != V_2 -> V_7 )
F_2 ( 1 , L_3 , V_3 ,
V_2 -> V_7 ) ;
}
F_2 ( 1 , L_4 , V_2 -> V_7 ) ;
return 1 ;
}
int
F_3 ( char * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
struct V_14 * V_15 = (struct V_14 * ) V_2 ;
T_1 V_3 = V_2 -> V_7 ;
T_2 V_16 = F_4 ( V_12 ) ;
T_2 V_17 ;
int V_18 ;
F_5 ( 1 , L_5 , V_19 , V_13 , V_16 ) ;
if ( V_13 < sizeof( struct V_14 ) ) {
if ( ( V_13 >= sizeof( struct V_1 ) ) && ( V_2 -> V_20 != 0 ) ) {
V_15 -> V_21 = 0 ;
return 0 ;
} else {
F_2 ( 1 , L_6 ) ;
}
return 1 ;
}
if ( V_16 > V_22 + V_23 - 4 ) {
F_2 ( 1 , L_7 , V_3 ) ;
return 1 ;
}
if ( F_1 ( V_2 , V_3 ) )
return 1 ;
if ( V_2 -> V_24 != V_25 ) {
F_2 ( 1 , L_8 ,
F_6 ( V_2 -> V_24 ) ) ;
return 1 ;
}
V_18 = F_6 ( V_2 -> V_10 ) ;
if ( V_18 >= V_26 ) {
F_2 ( 1 , L_9 , V_18 ) ;
return 1 ;
}
if ( V_27 [ V_18 ] != V_15 -> V_21 ) {
if ( V_18 != V_28 && ( V_2 -> V_20 == 0 ||
V_15 -> V_21 != V_29 ) ) {
F_2 ( 1 , L_10 ,
F_6 ( V_15 -> V_21 ) , V_18 ) ;
return 1 ;
} else if ( V_18 == V_28 && ( V_2 -> V_20 == 0 )
&& ( F_6 ( V_15 -> V_21 ) != 44 )
&& ( F_6 ( V_15 -> V_21 ) != 36 ) ) {
F_2 ( 1 , L_11 ,
F_6 ( V_15 -> V_21 ) ) ;
return 1 ;
}
}
if ( 4 + V_16 != V_13 ) {
F_2 ( 1 , L_12 ,
V_13 , 4 + V_16 , V_3 ) ;
return 1 ;
}
V_17 = F_7 ( V_2 ) ;
if ( 4 + V_16 != V_17 ) {
F_5 ( 1 , L_13 ,
V_17 , 4 + V_16 , V_3 ) ;
if ( V_17 + 20 == V_16 && V_18 == V_28 )
return 0 ;
if ( V_17 == 4 + V_16 + 1 )
return 0 ;
return 1 ;
}
return 0 ;
}
char *
F_8 ( int * V_30 , int * V_16 , struct V_1 * V_2 )
{
* V_30 = 0 ;
* V_16 = 0 ;
if ( V_2 -> V_20 && V_2 -> V_20 != V_31 &&
( ( (struct V_32 * ) V_2 ) -> V_24 ) ==
V_29 )
return NULL ;
switch ( V_2 -> V_10 ) {
case V_33 :
* V_30 = F_6 (
( (struct V_34 * ) V_2 ) -> V_35 ) ;
* V_16 = F_6 (
( (struct V_34 * ) V_2 ) -> V_36 ) ;
break;
case V_37 :
* V_30 = F_6 (
( (struct V_38 * ) V_2 ) -> V_35 ) ;
* V_16 = F_6 (
( (struct V_38 * ) V_2 ) -> V_36 ) ;
break;
case V_39 :
* V_30 = F_9 (
( (struct V_40 * ) V_2 ) -> V_41 ) ;
* V_16 = F_9 (
( (struct V_40 * ) V_2 ) -> V_42 ) ;
break;
case V_43 :
* V_30 = F_6 (
( (struct V_44 * ) V_2 ) -> V_45 ) ;
* V_16 = F_9 (
( (struct V_44 * ) V_2 ) -> V_46 ) ;
break;
case V_47 :
* V_30 = ( (struct V_48 * ) V_2 ) -> V_49 ;
* V_16 = F_9 ( ( (struct V_48 * ) V_2 ) -> V_50 ) ;
break;
case V_51 :
* V_30 = F_6 (
( (struct V_52 * ) V_2 ) -> V_45 ) ;
* V_16 = F_9 (
( (struct V_52 * ) V_2 ) -> V_46 ) ;
break;
case V_53 :
case V_54 :
default:
F_2 ( 1 , L_14 ) ;
break;
}
if ( * V_30 > 4096 ) {
F_2 ( 1 , L_15 , * V_30 ) ;
* V_16 = 0 ;
* V_30 = 0 ;
} else if ( * V_30 < 0 ) {
F_2 ( 1 , L_16 ,
* V_30 ) ;
* V_30 = 0 ;
* V_16 = 0 ;
} else if ( * V_16 < 0 ) {
F_2 ( 1 , L_17 ,
* V_16 ) ;
* V_16 = 0 ;
} else if ( * V_16 > 128 * 1024 ) {
F_2 ( 1 , L_18 , * V_16 ) ;
* V_16 = 0 ;
}
if ( ( * V_30 != 0 ) && ( * V_16 != 0 ) )
return V_2 -> V_5 + * V_30 ;
else
return NULL ;
}
unsigned int
F_7 ( void * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
struct V_14 * V_15 = (struct V_14 * ) V_2 ;
int V_55 ;
int V_56 ;
int V_16 = 4 + F_6 ( V_15 -> V_2 . V_24 ) ;
V_16 += F_6 ( V_15 -> V_21 ) ;
if ( V_57 [ F_6 ( V_2 -> V_10 ) ] == false )
goto V_58;
F_8 ( & V_55 , & V_56 , V_2 ) ;
F_5 ( 1 , L_19 , V_56 , V_55 ) ;
if ( V_56 > 0 ) {
if ( V_55 + 4 + 1 < V_16 ) {
F_2 ( 1 , L_20 ,
V_55 + 4 + 1 , V_16 ) ;
V_56 = 0 ;
} else {
V_16 = 4 + V_55 + V_56 ;
}
}
V_58:
F_5 ( 1 , L_21 , V_16 ) ;
return V_16 ;
}
T_3 *
F_10 ( const char * V_59 , struct V_60 * V_61 )
{
int V_16 ;
const char * V_62 ;
T_3 * V_63 ;
if ( V_59 [ 0 ] == '\\' )
V_62 = V_59 + 1 ;
else
V_62 = V_59 ;
V_63 = F_11 ( V_62 , V_64 , & V_16 ,
V_61 -> V_65 ,
V_61 -> V_66 &
V_67 ) ;
return V_63 ;
}
V_4
F_12 ( struct V_68 * V_69 )
{
if ( V_69 -> V_70 )
return V_71 | V_72 ;
else if ( V_69 -> V_73 )
return V_72 ;
return 0 ;
}
T_4 F_13 ( V_4 V_74 )
{
if ( V_74 & V_71 ) {
if ( V_74 & V_75 )
return V_76 ;
else
return V_77 ;
} else if ( V_74 & V_72 )
return V_78 ;
return 0 ;
}
static void
F_14 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_15 ( V_80 ,
struct V_81 , V_83 ) ;
int V_84 ;
V_84 = F_16 ( 0 , F_17 ( V_82 -> V_85 ) , V_82 -> V_86 ,
V_82 -> V_74 ) ;
F_5 ( 1 , L_22 , V_84 ) ;
F_18 ( V_82 -> V_85 ) ;
F_19 ( V_82 ) ;
}
static bool
F_20 ( char * V_87 , struct V_88 * V_89 )
{
struct V_90 * V_91 = (struct V_90 * ) V_87 ;
struct V_92 * V_93 , * V_94 , * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_68 * V_69 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_81 * V_82 ;
bool V_104 ;
int V_105 = F_9 ( V_91 -> V_8 &
V_106 ) ;
V_82 = F_21 ( sizeof( struct V_81 ) , V_107 ) ;
if ( ! V_82 ) {
F_2 ( 1 , L_23 ) ;
return false ;
}
F_22 ( & V_82 -> V_83 , F_14 ) ;
V_82 -> V_74 = V_91 -> V_108 ;
F_5 ( 1 , L_24 ) ;
F_23 ( & V_109 ) ;
F_24 (tmp, &server->smb_ses_list) {
V_97 = F_25 ( V_93 , struct V_96 , V_110 ) ;
F_23 ( & V_111 ) ;
F_24 (tmp1, &ses->tcon_list) {
V_99 = F_25 ( V_94 , struct V_98 , V_112 ) ;
F_26 ( & V_99 -> V_113 . V_114 . V_115 ) ;
F_24 (tmp2, &tcon->openFileList) {
V_101 = F_25 ( V_95 , struct V_100 ,
V_116 ) ;
V_69 = F_27 ( V_101 -> V_117 -> V_118 ) ;
if ( memcmp ( V_69 -> V_86 , V_91 -> V_119 ,
V_120 ) )
continue;
F_5 ( 1 , L_25 ) ;
F_5 ( 1 , L_26 ,
F_9 ( V_91 -> V_108 ) ) ;
F_28 ( V_69 ,
F_13 ( V_91 -> V_108 ) ) ;
if ( V_105 )
V_101 -> V_121 = false ;
else
V_101 -> V_121 = true ;
F_29 ( V_122 , & V_101 -> V_123 ) ;
F_30 ( & V_111 ) ;
F_30 ( & V_109 ) ;
return true ;
}
V_104 = false ;
F_31 (open, &tcon->pending_opens, olist) {
if ( memcmp ( V_103 -> V_86 , V_91 -> V_119 ,
V_120 ) )
continue;
if ( ! V_104 && V_105 ) {
V_104 = true ;
memcpy ( V_82 -> V_86 , V_103 -> V_86 ,
V_120 ) ;
V_82 -> V_85 = F_32 ( V_103 -> V_85 ) ;
F_29 ( V_122 ,
& V_82 -> V_83 ) ;
}
F_5 ( 1 , L_27 ) ;
F_5 ( 1 , L_26 ,
F_9 ( V_91 -> V_108 ) ) ;
V_103 -> V_124 =
F_13 ( V_91 -> V_108 ) ;
}
if ( V_104 ) {
F_30 ( & V_111 ) ;
F_30 ( & V_109 ) ;
return true ;
}
}
F_30 ( & V_111 ) ;
}
F_30 ( & V_109 ) ;
F_19 ( V_82 ) ;
F_5 ( 1 , L_28 ) ;
return false ;
}
bool
F_33 ( char * V_87 , struct V_88 * V_89 )
{
struct V_125 * V_91 = (struct V_125 * ) V_87 ;
struct V_92 * V_93 , * V_94 , * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_68 * V_69 ;
struct V_100 * V_101 ;
F_5 ( 1 , L_29 ) ;
if ( V_91 -> V_2 . V_10 != V_11 )
return false ;
if ( V_91 -> V_24 !=
V_27 [ V_28 ] ) {
if ( F_6 ( V_91 -> V_24 ) == 44 )
return F_20 ( V_87 , V_89 ) ;
else
return false ;
}
F_5 ( 1 , L_30 , V_91 -> V_126 ) ;
F_23 ( & V_109 ) ;
F_24 (tmp, &server->smb_ses_list) {
V_97 = F_25 ( V_93 , struct V_96 , V_110 ) ;
F_24 (tmp1, &ses->tcon_list) {
V_99 = F_25 ( V_94 , struct V_98 , V_112 ) ;
F_26 ( & V_99 -> V_113 . V_114 . V_115 ) ;
F_23 ( & V_111 ) ;
F_24 (tmp2, &tcon->openFileList) {
V_101 = F_25 ( V_95 , struct V_100 ,
V_116 ) ;
if ( V_91 -> V_127 !=
V_101 -> V_128 . V_129 ||
V_91 -> V_130 !=
V_101 -> V_128 . V_131 )
continue;
F_5 ( 1 , L_31 ) ;
V_69 = F_27 ( V_101 -> V_117 -> V_118 ) ;
if ( ! V_69 -> V_70 &&
V_91 -> V_126 == V_132 )
V_101 -> V_121 = true ;
else
V_101 -> V_121 = false ;
F_28 ( V_69 ,
V_91 -> V_126 ? V_78 : 0 ) ;
F_29 ( V_122 , & V_101 -> V_123 ) ;
F_30 ( & V_111 ) ;
F_30 ( & V_109 ) ;
return true ;
}
F_30 ( & V_111 ) ;
F_30 ( & V_109 ) ;
F_5 ( 1 , L_32 ) ;
return true ;
}
}
F_30 ( & V_109 ) ;
F_5 ( 1 , L_33 ) ;
return false ;
}
