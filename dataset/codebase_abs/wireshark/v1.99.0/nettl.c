int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
struct V_4 V_5 ;
T_3 V_6 [ 2 ] ;
int V_7 ;
T_4 * V_8 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_9 = V_10 ;
if ( ! F_2 ( V_1 -> V_11 , V_5 . V_12 , V_13 , V_2 , V_3 ) ) {
if ( * V_2 != V_14 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 . V_12 , V_15 , V_13 ) &&
memcmp ( V_5 . V_12 , V_16 , V_13 ) ) {
return 0 ;
}
if ( ! F_2 ( V_1 -> V_11 , V_5 . V_17 , V_18 - V_13 ,
V_2 , V_3 ) )
return - 1 ;
V_1 -> V_19 = V_20 ;
V_8 = F_3 ( T_4 , 1 ) ;
V_1 -> V_21 = ( void * ) V_8 ;
if ( V_5 . V_22 [ 2 ] == '1' && V_5 . V_22 [ 3 ] == '1' )
V_8 -> V_23 = TRUE ;
else
V_8 -> V_23 = FALSE ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = 0 ;
if ( ! F_4 ( V_1 -> V_11 , V_6 , 4 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
return 0 ;
}
return - 1 ;
}
V_7 = F_5 ( V_6 [ 1 ] ) ;
switch ( V_7 ) {
case V_29 :
case V_30 :
case V_31 :
case V_32 :
V_1 -> V_33 = V_34 ;
break;
case V_35 :
case V_36 :
V_1 -> V_33 = V_37 ;
break;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
V_1 -> V_33 = V_43 ;
break;
case V_44 :
V_1 -> V_33 = V_45 ;
break;
case V_46 :
V_1 -> V_33 = V_47 ;
break;
case V_48 :
V_1 -> V_33 = V_49 ;
break;
default:
V_1 -> V_33 = V_50 ;
}
if ( F_6 ( V_1 -> V_11 , V_18 , V_51 , V_2 ) == - 1 ) {
return - 1 ;
}
V_1 -> V_52 = V_53 ;
return 1 ;
}
static T_5 V_25 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_54 )
{
* V_54 = F_7 ( V_1 -> V_11 ) ;
if ( ! F_8 ( V_1 , V_1 -> V_11 , & V_1 -> V_55 , V_1 -> V_56 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_33 == V_57 )
V_1 -> V_33 = V_1 -> V_55 . V_58 ;
else {
if ( V_1 -> V_33 != V_1 -> V_55 . V_58 )
V_1 -> V_33 = V_59 ;
}
return TRUE ;
}
static T_5
V_27 ( T_1 * V_1 , T_6 V_60 , struct V_61 * V_55 ,
T_7 * V_62 , int * V_2 , T_2 * * V_3 )
{
if ( F_6 ( V_1 -> V_63 , V_60 , V_51 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 , V_1 -> V_63 , V_55 , V_62 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_14 ;
}
return FALSE ;
}
return TRUE ;
}
static T_5
F_8 ( T_1 * V_1 , T_8 V_11 , struct V_61 * V_55 , T_7 * V_62 ,
int * V_2 , T_2 * * V_3 )
{
union V_64 * V_65 = & V_55 -> V_65 ;
T_4 * V_8 = ( T_4 * ) V_1 -> V_21 ;
T_5 V_66 = FALSE ;
struct V_67 V_68 ;
T_3 V_69 ;
struct V_70 V_71 ;
T_9 V_72 , V_73 ;
int V_7 ;
T_10 V_74 ;
int V_75 ;
T_11 V_76 [ 16 ] ;
int V_77 ;
T_11 * V_78 ;
V_9 = V_10 ;
if ( ! F_4 ( V_11 , & V_68 . V_69 , sizeof V_68 . V_69 ,
V_2 , V_3 ) )
return FALSE ;
V_69 = F_5 ( V_68 . V_69 ) ;
if ( V_69 < V_79 ) {
* V_2 = V_80 ;
* V_3 = F_9 ( L_1 ,
V_69 ) ;
return FALSE ;
}
if ( ! F_2 ( V_11 , & V_68 . V_7 , V_79 - 2 ,
V_2 , V_3 ) )
return FALSE ;
V_7 = F_5 ( V_68 . V_7 ) ;
V_69 -= V_79 ;
if ( F_6 ( V_11 , V_69 , V_81 , V_2 ) == - 1 )
return FALSE ;
if ( ( F_10 ( & V_68 . V_82 ) & V_83 ) == 0 ) {
V_55 -> V_58 = V_43 ;
V_72 = F_10 ( & V_68 . V_72 ) ;
V_73 = F_10 ( & V_68 . V_73 ) ;
V_74 = 0 ;
} else switch ( V_7 ) {
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_35 :
case V_36 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_103 :
case V_104 :
case V_42 :
case V_46 :
case V_44 :
case V_48 :
case V_105 :
if( ( V_7 == V_38 )
|| ( V_7 == V_39 )
|| ( V_7 == V_41 )
|| ( V_7 == V_40 )
|| ( V_7 == V_105 )
|| ( V_7 == V_42 ) ) {
V_55 -> V_58 = V_43 ;
} else if ( V_7 == V_44 ) {
V_55 -> V_58 = V_45 ;
} else if ( V_7 == V_46 ) {
V_55 -> V_58 = V_47 ;
} else if ( V_7 == V_48 ) {
V_55 -> V_58 = V_49 ;
} else if( ( V_7 == V_29 )
|| ( V_7 == V_30 )
|| ( V_7 == V_31 )
|| ( V_7 == V_32 ) ) {
V_55 -> V_58 = V_34 ;
} else if( ( V_7 == V_36 )
|| ( V_7 == V_35 ) ) {
V_55 -> V_58 = V_37 ;
} else {
V_55 -> V_58 = V_50 ;
}
V_72 = F_10 ( & V_68 . V_72 ) ;
V_73 = F_10 ( & V_68 . V_73 ) ;
if ( V_7 == V_29 ) {
if ( F_10 ( & V_68 . V_82 ) == V_106 ) {
V_66 = TRUE ;
V_74 = 0 ;
} else {
if ( ! F_2 ( V_11 , V_76 , 9 , V_2 , V_3 ) )
return FALSE ;
V_74 = ( int ) V_76 [ 8 ] ;
if ( F_6 ( V_11 , V_74 , V_81 , V_2 ) == - 1 )
return FALSE ;
V_74 += 9 ;
}
} else if ( ( V_7 == V_31 )
|| ( V_7 == V_30 )
|| ( V_7 == V_32 ) ) {
if ( F_6 ( V_11 , 3 , V_81 , V_2 ) == - 1 )
return FALSE ;
V_74 = 3 ;
} else if ( V_7 == V_39 ) {
if ( F_6 ( V_11 , 26 , V_81 , V_2 ) == - 1 )
return FALSE ;
V_74 = 26 ;
} else if ( V_7 == V_105 ) {
if ( F_6 ( V_11 , 8 , V_81 , V_2 ) == - 1 )
return FALSE ;
V_74 = 8 ;
} else {
V_74 = 0 ;
}
break;
case V_107 :
V_55 -> V_58 = V_50 ;
if ( ! F_2 ( V_11 , & V_71 , V_108 ,
V_2 , V_3 ) )
return FALSE ;
V_72 = F_11 ( & V_71 . V_72 ) ;
V_73 = F_11 ( & V_71 . V_73 ) ;
if ( V_8 -> V_23 ) {
if ( F_6 ( V_11 , 2 , V_81 , V_2 ) == - 1 ) return FALSE ;
}
V_74 = 0 ;
break;
case V_109 :
case V_110 :
V_55 -> V_58 = V_111 ;
V_72 = F_10 ( & V_68 . V_72 ) ;
V_73 = F_10 ( & V_68 . V_73 ) ;
V_74 = 24 ;
if ( F_6 ( V_11 , V_74 , V_81 , V_2 ) == - 1 )
return FALSE ;
break;
default:
V_1 -> V_33 = V_59 ;
V_55 -> V_58 = V_50 ;
V_72 = F_10 ( & V_68 . V_72 ) ;
V_73 = F_10 ( & V_68 . V_73 ) ;
V_74 = 0 ;
break;
}
if ( V_72 < V_74 ) {
* V_2 = V_80 ;
* V_3 = F_9 ( L_2 ,
V_72 , V_74 ) ;
return FALSE ;
}
V_55 -> V_112 = V_113 ;
V_55 -> V_114 = V_115 | V_116 ;
V_55 -> V_117 = V_72 - V_74 ;
if ( V_73 < V_74 ) {
* V_2 = V_80 ;
* V_3 = F_9 ( L_3 ,
V_73 , V_74 ) ;
return FALSE ;
}
V_75 = V_73 - V_74 ;
V_55 -> V_73 = V_75 ;
V_55 -> V_118 . V_119 = F_10 ( & V_68 . V_120 ) ;
V_55 -> V_118 . V_121 = F_10 ( & V_68 . V_122 ) * 1000 ;
V_65 -> V_8 . V_7 = V_7 ;
V_65 -> V_8 . V_123 = F_10 ( & V_68 . V_123 ) ;
V_65 -> V_8 . V_82 = F_10 ( & V_68 . V_82 ) ;
V_65 -> V_8 . V_124 = F_10 ( & V_68 . V_124 ) ;
V_65 -> V_8 . V_125 = F_11 ( & V_68 . V_125 ) ;
if ( V_55 -> V_73 > V_126 ) {
* V_2 = V_80 ;
* V_3 = F_9 ( L_4 ,
V_55 -> V_73 , V_126 ) ;
return FALSE ;
}
F_12 ( V_62 , V_75 ) ;
V_78 = F_13 ( V_62 ) ;
V_9 = V_10 ;
if ( V_66 ) {
V_77 = 15 ;
if ( V_77 > V_75 )
V_77 = V_75 ;
if ( ! F_2 ( V_11 , V_78 , V_77 , V_2 , V_3 ) )
return FALSE ;
V_75 -= V_77 ;
if ( V_75 == 0 ) {
return TRUE ;
}
if ( V_78 [ 13 ] == 0xAA ) {
V_77 = 3 ;
if ( V_77 > V_75 )
V_77 = V_75 ;
if ( ! F_14 ( V_11 , V_77 , V_2 ) )
return FALSE ;
V_75 -= V_77 ;
if ( V_75 == 0 ) {
return TRUE ;
}
}
if ( ! F_2 ( V_11 , V_78 + 15 , V_75 , V_2 , V_3 ) )
return FALSE ;
} else {
if ( ! F_2 ( V_11 , V_78 , V_75 , V_2 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
int F_15 ( int V_127 )
{
switch ( V_127 ) {
case V_128 :
case V_129 :
case V_130 :
case V_50 :
case V_34 :
case V_37 :
case V_43 :
case V_45 :
case V_47 :
case V_49 :
case V_59 :
case V_57 :
case V_131 :
return 0 ;
default:
return V_132 ;
}
}
T_5 F_16 ( T_12 * V_133 , int * V_2 )
{
struct V_4 V_5 ;
V_133 -> V_134 = V_135 ;
V_133 -> V_136 = NULL ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memcpy ( V_5 . V_12 , V_16 , sizeof( V_5 . V_12 ) ) ;
F_17 ( V_5 . V_17 , L_5 , V_137 ) ;
F_17 ( V_5 . V_138 , L_6 , 20 ) ;
F_17 ( V_5 . V_139 , L_7 , 9 ) ;
F_17 ( V_5 . V_22 , L_8 , 9 ) ;
V_5 . V_140 = 0x55 ;
F_17 ( V_5 . V_141 , L_9 , 11 ) ;
V_5 . V_142 = F_18 ( 0x406 ) ;
if ( ! F_19 ( V_133 , & V_5 , sizeof V_5 , V_2 ) )
return FALSE ;
V_133 -> V_143 += sizeof( V_5 ) ;
return TRUE ;
}
static T_5 V_135 ( T_12 * V_133 ,
const struct V_61 * V_55 ,
const T_11 * V_78 , int * V_2 )
{
const union V_64 * V_65 = & V_55 -> V_65 ;
struct V_67 V_68 ;
T_11 V_76 [ 24 ] ;
if ( V_55 -> V_112 != V_113 ) {
* V_2 = V_144 ;
return FALSE ;
}
if ( V_55 -> V_73 > V_126 ) {
* V_2 = V_145 ;
return FALSE ;
}
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_69 = F_18 ( sizeof( V_68 ) + 4 ) ;
V_68 . V_82 = F_20 ( V_106 ) ;
V_68 . V_120 = F_20 ( V_55 -> V_118 . V_119 ) ;
V_68 . V_122 = F_20 ( V_55 -> V_118 . V_121 / 1000 ) ;
V_68 . V_73 = F_20 ( V_55 -> V_73 ) ;
V_68 . V_72 = F_20 ( V_55 -> V_117 ) ;
V_68 . V_123 = - 1 ;
V_68 . V_124 = - 1 ;
V_68 . V_125 = - 1 ;
switch ( V_55 -> V_58 ) {
case V_34 :
V_68 . V_73 = F_20 ( V_55 -> V_73 + 3 ) ;
V_68 . V_72 = F_20 ( V_55 -> V_117 + 3 ) ;
case V_50 :
case V_37 :
case V_43 :
case V_45 :
case V_47 :
case V_49 :
case V_131 :
V_68 . V_7 = F_18 ( V_65 -> V_8 . V_7 ) ;
V_68 . V_123 = F_20 ( V_65 -> V_8 . V_123 ) ;
V_68 . V_82 = F_20 ( V_65 -> V_8 . V_82 ) ;
V_68 . V_124 = F_20 ( V_65 -> V_8 . V_124 ) ;
V_68 . V_125 = F_18 ( V_65 -> V_8 . V_125 ) ;
break;
case V_146 :
V_68 . V_7 = F_18 ( V_38 ) ;
break;
case V_128 :
V_68 . V_7 = F_18 ( V_92 ) ;
break;
case V_129 :
V_68 . V_7 = F_18 ( V_31 ) ;
V_68 . V_73 = F_20 ( V_55 -> V_73 + 3 ) ;
V_68 . V_72 = F_20 ( V_55 -> V_117 + 3 ) ;
break;
case V_130 :
V_68 . V_7 = F_18 ( V_36 ) ;
break;
#if 0
case WTAP_ENCAP_NETTL_X25:
rec_hdr.caplen = g_htonl(phdr->caplen + 24);
rec_hdr.length = g_htonl(phdr->len + 24);
rec_hdr.subsys = g_htons(pseudo_header->nettl.subsys);
rec_hdr.devid = g_htonl(pseudo_header->nettl.devid);
rec_hdr.kind = g_htonl(pseudo_header->nettl.kind);
rec_hdr.pid = g_htonl(pseudo_header->nettl.pid);
rec_hdr.uid = g_htons(pseudo_header->nettl.uid);
break;
#endif
default:
* V_2 = V_132 ;
return FALSE ;
}
if ( ! F_19 ( V_133 , & V_68 , sizeof( V_68 ) , V_2 ) )
return FALSE ;
V_133 -> V_143 += sizeof( V_68 ) ;
memset ( V_76 , 0 , sizeof V_76 ) ;
if ( ! F_19 ( V_133 , V_76 , 4 , V_2 ) )
return FALSE ;
V_133 -> V_143 += 4 ;
if ( ( V_55 -> V_58 == V_129 ) ||
( V_55 -> V_58 == V_34 ) ) {
if ( ! F_19 ( V_133 , V_76 , 3 , V_2 ) )
return FALSE ;
V_133 -> V_143 += 3 ;
}
if ( ! F_19 ( V_133 , V_78 , V_55 -> V_73 , V_2 ) )
return FALSE ;
V_133 -> V_143 += V_55 -> V_73 ;
return TRUE ;
}
