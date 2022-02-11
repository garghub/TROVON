int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
struct V_4 V_5 ;
T_3 V_6 [ 2 ] ;
int V_7 ;
int V_8 ;
T_4 * V_9 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_10 = V_11 ;
V_8 = F_2 ( V_5 . V_12 , V_13 , V_1 -> V_14 ) ;
if ( V_8 != V_13 ) {
* V_2 = F_3 ( V_1 -> V_14 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_15 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 . V_12 , V_16 , V_13 ) &&
memcmp ( V_5 . V_12 , V_17 , V_13 ) ) {
return 0 ;
}
V_8 = F_2 ( V_5 . V_18 , V_19 - V_13 ,
V_1 -> V_14 ) ;
if ( V_8 != V_19 - V_13 ) {
* V_2 = F_3 ( V_1 -> V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return - 1 ;
}
V_1 -> V_20 = V_21 ;
V_9 = F_4 ( T_4 , 1 ) ;
V_1 -> V_22 = ( void * ) V_9 ;
if ( V_5 . V_23 [ 2 ] == '1' && V_5 . V_23 [ 3 ] == '1' )
V_9 -> V_24 = TRUE ;
else
V_9 -> V_24 = FALSE ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_29 = 0 ;
V_8 = F_2 ( V_6 , 4 , V_1 -> V_14 ) ;
if ( V_8 != 4 ) {
if ( * V_2 != 0 ) {
return - 1 ;
}
if ( V_8 != 0 ) {
* V_2 = V_15 ;
return - 1 ;
}
return 0 ;
}
V_7 = F_5 ( V_6 [ 1 ] ) ;
switch ( V_7 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
V_1 -> V_34 = V_35 ;
break;
case V_36 :
case V_37 :
V_1 -> V_34 = V_38 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_1 -> V_34 = V_44 ;
break;
case V_45 :
V_1 -> V_34 = V_46 ;
break;
case V_47 :
V_1 -> V_34 = V_48 ;
break;
case V_49 :
V_1 -> V_34 = V_50 ;
break;
default:
V_1 -> V_34 = V_51 ;
}
if ( F_6 ( V_1 -> V_14 , V_19 , V_52 , V_2 ) == - 1 ) {
return - 1 ;
}
V_1 -> V_53 = V_54 ;
return 1 ;
}
static T_5 V_26 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_55 )
{
* V_55 = F_7 ( V_1 -> V_14 ) ;
if ( ! F_8 ( V_1 , V_1 -> V_14 , & V_1 -> V_56 , V_1 -> V_57 ,
V_2 , V_3 ) ) {
return FALSE ;
}
if ( V_1 -> V_34 == V_58 )
V_1 -> V_34 = V_1 -> V_56 . V_59 ;
else {
if ( V_1 -> V_34 != V_1 -> V_56 . V_59 )
V_1 -> V_34 = V_60 ;
}
return TRUE ;
}
static T_5
V_28 ( T_1 * V_1 , T_6 V_61 , struct V_62 * V_56 ,
T_7 * V_63 , int * V_2 , T_2 * * V_3 )
{
if ( F_6 ( V_1 -> V_64 , V_61 , V_52 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_8 ( V_1 , V_1 -> V_64 , V_56 , V_63 , V_2 , V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_15 ;
}
return FALSE ;
}
return TRUE ;
}
static T_5
F_8 ( T_1 * V_1 , T_8 V_14 , struct V_62 * V_56 , T_7 * V_63 ,
int * V_2 , T_2 * * V_3 )
{
union V_65 * V_66 = & V_56 -> V_66 ;
T_4 * V_9 = ( T_4 * ) V_1 -> V_22 ;
T_5 V_67 = FALSE ;
int V_8 ;
struct V_68 V_69 ;
T_3 V_70 ;
struct V_71 V_72 ;
T_9 V_73 , V_74 ;
int V_7 ;
T_10 V_75 ;
int V_76 ;
T_11 V_77 [ 16 ] ;
int V_78 ;
T_11 * V_79 ;
T_11 V_6 [ 3 ] ;
V_10 = V_11 ;
V_8 = F_2 ( & V_69 . V_70 , sizeof V_69 . V_70 , V_14 ) ;
if ( V_8 != sizeof V_69 . V_70 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 && V_8 != 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_70 = F_5 ( V_69 . V_70 ) ;
if ( V_70 < V_80 ) {
* V_2 = V_81 ;
* V_3 = F_9 ( L_1 ,
V_70 ) ;
return FALSE ;
}
V_8 = F_2 ( & V_69 . V_7 , V_80 - 2 , V_14 ) ;
if ( V_8 != V_80 - 2 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_7 = F_5 ( V_69 . V_7 ) ;
V_70 -= V_80 ;
if ( F_6 ( V_14 , V_70 , V_82 , V_2 ) == - 1 )
return FALSE ;
if ( ( F_10 ( & V_69 . V_83 ) & V_84 ) == 0 ) {
V_56 -> V_59 = V_44 ;
V_73 = F_10 ( & V_69 . V_73 ) ;
V_74 = F_10 ( & V_69 . V_74 ) ;
V_75 = 0 ;
} else switch ( V_7 ) {
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
case V_103 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_36 :
case V_37 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_104 :
case V_105 :
case V_43 :
case V_47 :
case V_45 :
case V_49 :
case V_106 :
if( ( V_7 == V_39 )
|| ( V_7 == V_40 )
|| ( V_7 == V_42 )
|| ( V_7 == V_41 )
|| ( V_7 == V_106 )
|| ( V_7 == V_43 ) ) {
V_56 -> V_59 = V_44 ;
} else if ( V_7 == V_45 ) {
V_56 -> V_59 = V_46 ;
} else if ( V_7 == V_47 ) {
V_56 -> V_59 = V_48 ;
} else if ( V_7 == V_49 ) {
V_56 -> V_59 = V_50 ;
} else if( ( V_7 == V_30 )
|| ( V_7 == V_31 )
|| ( V_7 == V_32 )
|| ( V_7 == V_33 ) ) {
V_56 -> V_59 = V_35 ;
} else if( ( V_7 == V_37 )
|| ( V_7 == V_36 ) ) {
V_56 -> V_59 = V_38 ;
} else {
V_56 -> V_59 = V_51 ;
}
V_73 = F_10 ( & V_69 . V_73 ) ;
V_74 = F_10 ( & V_69 . V_74 ) ;
if ( V_7 == V_30 ) {
if ( F_10 ( & V_69 . V_83 ) == V_107 ) {
V_67 = TRUE ;
V_75 = 0 ;
} else {
V_8 = F_2 ( V_77 , 9 , V_14 ) ;
if ( V_8 != 9 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_75 = ( int ) V_77 [ 8 ] ;
if ( F_6 ( V_14 , V_75 , V_82 , V_2 ) == - 1 )
return FALSE ;
V_75 += 9 ;
}
} else if ( ( V_7 == V_32 )
|| ( V_7 == V_31 )
|| ( V_7 == V_33 ) ) {
if ( F_6 ( V_14 , 3 , V_82 , V_2 ) == - 1 )
return FALSE ;
V_75 = 3 ;
} else if ( V_7 == V_40 ) {
if ( F_6 ( V_14 , 26 , V_82 , V_2 ) == - 1 )
return FALSE ;
V_75 = 26 ;
} else if ( V_7 == V_106 ) {
if ( F_6 ( V_14 , 8 , V_82 , V_2 ) == - 1 )
return FALSE ;
V_75 = 8 ;
} else {
V_75 = 0 ;
}
break;
case V_108 :
V_56 -> V_59 = V_51 ;
V_8 = F_2 ( & V_72 , V_109 , V_14 ) ;
if ( V_8 != V_109 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_73 = F_11 ( & V_72 . V_73 ) ;
V_74 = F_11 ( & V_72 . V_74 ) ;
if ( V_9 -> V_24 ) {
if ( F_6 ( V_14 , 2 , V_82 , V_2 ) == - 1 ) return FALSE ;
}
V_75 = 0 ;
break;
case V_110 :
case V_111 :
V_56 -> V_59 = V_112 ;
V_73 = F_10 ( & V_69 . V_73 ) ;
V_74 = F_10 ( & V_69 . V_74 ) ;
V_75 = 24 ;
if ( F_6 ( V_14 , V_75 , V_82 , V_2 ) == - 1 )
return FALSE ;
break;
default:
V_1 -> V_34 = V_60 ;
V_56 -> V_59 = V_51 ;
V_73 = F_10 ( & V_69 . V_73 ) ;
V_74 = F_10 ( & V_69 . V_74 ) ;
V_75 = 0 ;
break;
}
if ( V_73 < V_75 ) {
* V_2 = V_81 ;
* V_3 = F_9 ( L_2 ,
V_73 , V_75 ) ;
return FALSE ;
}
V_56 -> V_113 = V_114 ;
V_56 -> V_115 = V_116 | V_117 ;
V_56 -> V_118 = V_73 - V_75 ;
if ( V_74 < V_75 ) {
* V_2 = V_81 ;
* V_3 = F_9 ( L_3 ,
V_74 , V_75 ) ;
return FALSE ;
}
V_76 = V_74 - V_75 ;
V_56 -> V_74 = V_76 ;
V_56 -> V_119 . V_120 = F_10 ( & V_69 . V_121 ) ;
V_56 -> V_119 . V_122 = F_10 ( & V_69 . V_123 ) * 1000 ;
V_66 -> V_9 . V_7 = V_7 ;
V_66 -> V_9 . V_124 = F_10 ( & V_69 . V_124 ) ;
V_66 -> V_9 . V_83 = F_10 ( & V_69 . V_83 ) ;
V_66 -> V_9 . V_125 = F_10 ( & V_69 . V_125 ) ;
V_66 -> V_9 . V_126 = F_11 ( & V_69 . V_126 ) ;
if ( V_56 -> V_74 > V_127 ) {
* V_2 = V_81 ;
* V_3 = F_9 ( L_4 ,
V_56 -> V_74 , V_127 ) ;
return FALSE ;
}
F_12 ( V_63 , V_76 ) ;
V_79 = F_13 ( V_63 ) ;
V_10 = V_11 ;
if ( V_67 ) {
V_78 = 15 ;
if ( V_78 > V_76 )
V_78 = V_76 ;
V_8 = F_2 ( V_79 , V_78 , V_14 ) ;
if ( V_8 != V_78 ) {
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_76 -= V_8 ;
if ( V_76 == 0 ) {
return TRUE ;
}
if ( V_79 [ 13 ] == 0xAA ) {
V_78 = 3 ;
if ( V_78 > V_76 )
V_78 = V_76 ;
V_8 = F_2 ( V_6 , V_78 , V_14 ) ;
if ( V_8 != V_78 ) {
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_76 -= V_8 ;
if ( V_76 == 0 ) {
return TRUE ;
}
}
V_8 = F_2 ( V_79 + 15 , V_76 , V_14 ) ;
} else
V_8 = F_2 ( V_79 , V_76 , V_14 ) ;
if ( V_8 != V_76 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
return TRUE ;
}
int F_14 ( int V_128 )
{
switch ( V_128 ) {
case V_129 :
case V_130 :
case V_131 :
case V_51 :
case V_35 :
case V_38 :
case V_44 :
case V_46 :
case V_48 :
case V_50 :
case V_60 :
case V_58 :
case V_132 :
return 0 ;
default:
return V_133 ;
}
}
T_5 F_15 ( T_12 * V_134 , int * V_2 )
{
struct V_4 V_5 ;
V_134 -> V_135 = V_136 ;
V_134 -> V_137 = NULL ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memcpy ( V_5 . V_12 , V_17 , sizeof( V_5 . V_12 ) ) ;
F_16 ( V_5 . V_18 , L_5 , V_138 ) ;
F_16 ( V_5 . V_139 , L_6 , 20 ) ;
F_16 ( V_5 . V_140 , L_7 , 9 ) ;
F_16 ( V_5 . V_23 , L_8 , 9 ) ;
V_5 . V_141 = 0x55 ;
F_16 ( V_5 . V_142 , L_9 , 11 ) ;
V_5 . V_143 = F_17 ( 0x406 ) ;
if ( ! F_18 ( V_134 , & V_5 , sizeof V_5 , V_2 ) )
return FALSE ;
V_134 -> V_144 += sizeof( V_5 ) ;
return TRUE ;
}
static T_5 V_136 ( T_12 * V_134 ,
const struct V_62 * V_56 ,
const T_11 * V_79 , int * V_2 )
{
const union V_65 * V_66 = & V_56 -> V_66 ;
struct V_68 V_69 ;
T_11 V_77 [ 24 ] ;
if ( V_56 -> V_113 != V_114 ) {
* V_2 = V_145 ;
return FALSE ;
}
if ( V_56 -> V_74 > V_127 ) {
* V_2 = V_146 ;
return FALSE ;
}
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 = F_17 ( sizeof( V_69 ) + 4 ) ;
V_69 . V_83 = F_19 ( V_107 ) ;
V_69 . V_121 = F_19 ( V_56 -> V_119 . V_120 ) ;
V_69 . V_123 = F_19 ( V_56 -> V_119 . V_122 / 1000 ) ;
V_69 . V_74 = F_19 ( V_56 -> V_74 ) ;
V_69 . V_73 = F_19 ( V_56 -> V_118 ) ;
V_69 . V_124 = - 1 ;
V_69 . V_125 = - 1 ;
V_69 . V_126 = - 1 ;
switch ( V_56 -> V_59 ) {
case V_35 :
V_69 . V_74 = F_19 ( V_56 -> V_74 + 3 ) ;
V_69 . V_73 = F_19 ( V_56 -> V_118 + 3 ) ;
case V_51 :
case V_38 :
case V_44 :
case V_46 :
case V_48 :
case V_50 :
case V_132 :
V_69 . V_7 = F_17 ( V_66 -> V_9 . V_7 ) ;
V_69 . V_124 = F_19 ( V_66 -> V_9 . V_124 ) ;
V_69 . V_83 = F_19 ( V_66 -> V_9 . V_83 ) ;
V_69 . V_125 = F_19 ( V_66 -> V_9 . V_125 ) ;
V_69 . V_126 = F_17 ( V_66 -> V_9 . V_126 ) ;
break;
case V_147 :
V_69 . V_7 = F_17 ( V_39 ) ;
break;
case V_129 :
V_69 . V_7 = F_17 ( V_93 ) ;
break;
case V_130 :
V_69 . V_7 = F_17 ( V_32 ) ;
V_69 . V_74 = F_19 ( V_56 -> V_74 + 3 ) ;
V_69 . V_73 = F_19 ( V_56 -> V_118 + 3 ) ;
break;
case V_131 :
V_69 . V_7 = F_17 ( V_37 ) ;
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
* V_2 = V_133 ;
return FALSE ;
}
if ( ! F_18 ( V_134 , & V_69 , sizeof( V_69 ) , V_2 ) )
return FALSE ;
V_134 -> V_144 += sizeof( V_69 ) ;
memset ( V_77 , 0 , sizeof V_77 ) ;
if ( ! F_18 ( V_134 , V_77 , 4 , V_2 ) )
return FALSE ;
V_134 -> V_144 += 4 ;
if ( ( V_56 -> V_59 == V_130 ) ||
( V_56 -> V_59 == V_35 ) ) {
if ( ! F_18 ( V_134 , V_77 , 3 , V_2 ) )
return FALSE ;
V_134 -> V_144 += 3 ;
}
if ( ! F_18 ( V_134 , V_79 , V_56 -> V_74 , V_2 ) )
return FALSE ;
V_134 -> V_144 += V_56 -> V_74 ;
return TRUE ;
}
