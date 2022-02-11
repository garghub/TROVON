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
int V_56 ;
T_5 V_57 = FALSE ;
* V_55 = F_7 ( V_1 -> V_14 ) ;
V_56 = F_8 ( V_1 , V_1 -> V_14 , & V_1 -> V_58 ,
V_2 , V_3 , & V_57 ) ;
if ( V_56 <= 0 ) {
return FALSE ;
}
if ( V_1 -> V_58 . V_59 > V_60 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_1 ,
V_1 -> V_58 . V_59 , V_60 ) ;
return FALSE ;
}
if ( V_1 -> V_34 == V_62 )
V_1 -> V_34 = V_1 -> V_58 . V_63 ;
else {
if ( V_1 -> V_34 != V_1 -> V_58 . V_63 )
V_1 -> V_34 = V_64 ;
}
F_10 ( V_1 -> V_65 , V_1 -> V_58 . V_59 ) ;
if ( ! F_11 ( V_1 -> V_14 , F_12 ( V_1 -> V_65 ) ,
V_1 -> V_58 . V_59 , V_2 , V_3 , V_57 ) )
return FALSE ;
return TRUE ;
}
static T_5
V_28 ( T_1 * V_1 , T_6 V_66 , struct V_67 * V_58 ,
T_7 * V_68 , int V_69 , int * V_2 , T_2 * * V_3 )
{
int V_56 ;
T_5 V_57 = FALSE ;
if ( F_6 ( V_1 -> V_70 , V_66 , V_52 , V_2 ) == - 1 )
return FALSE ;
V_56 = F_8 ( V_1 , V_1 -> V_70 , V_58 , V_2 , V_3 ,
& V_57 ) ;
if ( V_56 <= 0 ) {
if ( V_56 == 0 ) {
* V_2 = V_15 ;
}
return FALSE ;
}
return F_11 ( V_1 -> V_70 , V_68 , V_69 , V_2 , V_3 ,
V_57 ) ;
}
static int
F_8 ( T_1 * V_1 , T_8 V_14 , struct V_67 * V_58 ,
int * V_2 , T_2 * * V_3 , T_5 * V_57 )
{
union V_71 * V_72 = & V_58 -> V_72 ;
T_4 * V_9 = ( T_4 * ) V_1 -> V_22 ;
int V_8 ;
struct V_73 V_74 ;
T_3 V_75 ;
struct V_76 V_77 ;
T_3 V_69 , V_59 ;
int V_78 = 0 ;
int V_7 ;
int V_79 ;
T_7 V_80 [ 16 ] ;
V_10 = V_11 ;
V_8 = F_2 ( & V_74 . V_75 , sizeof V_74 . V_75 , V_14 ) ;
if ( V_8 != sizeof V_74 . V_75 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_8 != 0 ) {
* V_2 = V_15 ;
return - 1 ;
}
return 0 ;
}
V_78 += 2 ;
V_75 = F_5 ( V_74 . V_75 ) ;
if ( V_75 < V_81 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_2 ,
V_75 ) ;
return - 1 ;
}
V_8 = F_2 ( & V_74 . V_7 , V_81 - 2 , V_14 ) ;
if ( V_8 != V_81 - 2 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return - 1 ;
}
V_78 += V_81 - 2 ;
V_7 = F_5 ( V_74 . V_7 ) ;
V_75 -= V_81 ;
if ( F_6 ( V_14 , V_75 , V_82 , V_2 ) == - 1 )
return - 1 ;
V_78 += V_75 ;
if ( ( F_13 ( & V_74 . V_83 ) & V_84 ) == 0 ) {
V_58 -> V_63 = V_44 ;
V_69 = F_13 ( & V_74 . V_69 ) ;
V_59 = F_13 ( & V_74 . V_59 ) ;
V_79 = 0 ;
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
case V_102 :
case V_103 :
case V_43 :
case V_47 :
case V_45 :
case V_49 :
case V_104 :
if( ( V_7 == V_39 )
|| ( V_7 == V_40 )
|| ( V_7 == V_42 )
|| ( V_7 == V_41 )
|| ( V_7 == V_104 )
|| ( V_7 == V_43 ) ) {
V_58 -> V_63 = V_44 ;
} else if ( V_7 == V_45 ) {
V_58 -> V_63 = V_46 ;
} else if ( V_7 == V_47 ) {
V_58 -> V_63 = V_48 ;
} else if ( V_7 == V_49 ) {
V_58 -> V_63 = V_50 ;
} else if( ( V_7 == V_30 )
|| ( V_7 == V_31 )
|| ( V_7 == V_32 )
|| ( V_7 == V_33 ) ) {
V_58 -> V_63 = V_35 ;
} else if( ( V_7 == V_37 )
|| ( V_7 == V_36 ) ) {
V_58 -> V_63 = V_38 ;
} else {
V_58 -> V_63 = V_51 ;
}
V_69 = F_13 ( & V_74 . V_69 ) ;
V_59 = F_13 ( & V_74 . V_59 ) ;
if ( V_7 == V_30 ) {
if ( F_13 ( & V_74 . V_83 ) == V_105 ) {
* V_57 = TRUE ;
V_79 = 0 ;
} else {
V_8 = F_2 ( V_80 , 9 , V_14 ) ;
if ( V_8 != 9 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return - 1 ;
}
V_79 = ( int ) V_80 [ 8 ] ;
if ( F_6 ( V_14 , V_79 , V_82 , V_2 ) == - 1 )
return - 1 ;
V_79 += 9 ;
V_78 += V_79 ;
}
} else if ( ( V_7 == V_32 )
|| ( V_7 == V_31 )
|| ( V_7 == V_33 ) ) {
if ( F_6 ( V_14 , 3 , V_82 , V_2 ) == - 1 )
return - 1 ;
V_79 = 3 ;
V_78 += V_79 ;
} else if ( V_7 == V_40 ) {
if ( F_6 ( V_14 , 26 , V_82 , V_2 ) == - 1 )
return - 1 ;
V_79 = 26 ;
V_78 += V_79 ;
} else if ( V_7 == V_104 ) {
if ( F_6 ( V_14 , 8 , V_82 , V_2 ) == - 1 )
return - 1 ;
V_79 = 8 ;
V_78 += V_79 ;
} else {
V_79 = 0 ;
}
break;
case V_106 :
V_58 -> V_63 = V_51 ;
V_8 = F_2 ( & V_77 , V_107 , V_14 ) ;
if ( V_8 != V_107 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return - 1 ;
}
V_78 += V_107 ;
V_69 = F_14 ( & V_77 . V_69 ) ;
V_59 = F_14 ( & V_77 . V_59 ) ;
if ( V_9 -> V_24 ) {
if ( F_6 ( V_14 , 2 , V_82 , V_2 ) == - 1 ) return - 1 ;
V_78 += 2 ;
}
V_79 = 0 ;
break;
case V_108 :
case V_109 :
V_58 -> V_63 = V_110 ;
V_69 = F_13 ( & V_74 . V_69 ) ;
V_59 = F_13 ( & V_74 . V_59 ) ;
V_79 = 24 ;
if ( F_6 ( V_14 , V_79 , V_82 , V_2 ) == - 1 )
return - 1 ;
V_78 += V_79 ;
break;
default:
V_1 -> V_34 = V_64 ;
V_58 -> V_63 = V_51 ;
V_69 = F_13 ( & V_74 . V_69 ) ;
V_59 = F_13 ( & V_74 . V_59 ) ;
V_79 = 0 ;
break;
}
if ( V_69 < V_79 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_3 ,
V_69 , V_79 ) ;
return - 1 ;
}
V_58 -> V_111 = V_112 | V_113 ;
V_58 -> V_114 = V_69 - V_79 ;
if ( V_59 < V_79 ) {
* V_2 = V_61 ;
* V_3 = F_9 ( L_4 ,
V_59 , V_79 ) ;
return - 1 ;
}
V_58 -> V_59 = V_59 - V_79 ;
V_58 -> V_115 . V_116 = F_13 ( & V_74 . V_117 ) ;
V_58 -> V_115 . V_118 = F_13 ( & V_74 . V_119 ) * 1000 ;
V_72 -> V_9 . V_7 = V_7 ;
V_72 -> V_9 . V_120 = F_13 ( & V_74 . V_120 ) ;
V_72 -> V_9 . V_83 = F_13 ( & V_74 . V_83 ) ;
V_72 -> V_9 . V_121 = F_13 ( & V_74 . V_121 ) ;
V_72 -> V_9 . V_122 = F_14 ( & V_74 . V_122 ) ;
return V_78 ;
}
static T_5
F_11 ( T_8 V_14 , T_7 * V_68 , int V_69 , int * V_2 ,
T_2 * * V_3 , T_5 V_57 )
{
int V_123 , V_8 ;
T_7 V_6 [ 3 ] ;
if ( V_57 ) {
V_123 = 15 ;
if ( V_123 > V_69 )
V_123 = V_69 ;
V_8 = F_2 ( V_68 , V_123 , V_14 ) ;
if ( V_8 != V_123 ) {
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_69 -= V_8 ;
if ( V_69 == 0 ) {
return TRUE ;
}
if ( V_68 [ 13 ] == 0xAA ) {
V_123 = 3 ;
if ( V_123 > V_69 )
V_123 = V_69 ;
V_8 = F_2 ( V_6 , V_123 , V_14 ) ;
if ( V_8 != V_123 ) {
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
V_69 -= V_8 ;
if ( V_69 == 0 ) {
return TRUE ;
}
}
V_8 = F_2 ( V_68 + 15 , V_69 , V_14 ) ;
} else
V_8 = F_2 ( V_68 , V_69 , V_14 ) ;
if ( V_8 != V_69 ) {
* V_2 = F_3 ( V_14 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_15 ;
return FALSE ;
}
return TRUE ;
}
int F_15 ( int V_124 )
{
switch ( V_124 ) {
case V_125 :
case V_126 :
case V_127 :
case V_51 :
case V_35 :
case V_38 :
case V_44 :
case V_46 :
case V_48 :
case V_50 :
case V_64 :
case V_62 :
case V_128 :
return 0 ;
default:
return V_129 ;
}
}
T_5 F_16 ( T_9 * V_130 , int * V_2 )
{
struct V_4 V_5 ;
V_130 -> V_131 = V_132 ;
V_130 -> V_133 = NULL ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memcpy ( V_5 . V_12 , V_17 , sizeof( V_5 . V_12 ) ) ;
F_17 ( V_5 . V_18 , L_5 , V_134 ) ;
F_17 ( V_5 . V_135 , L_6 , 20 ) ;
F_17 ( V_5 . V_136 , L_7 , 9 ) ;
F_17 ( V_5 . V_23 , L_8 , 9 ) ;
V_5 . V_137 = 0x55 ;
F_17 ( V_5 . V_138 , L_9 , 11 ) ;
V_5 . V_139 = F_18 ( 0x406 ) ;
if ( ! F_19 ( V_130 , & V_5 , sizeof V_5 , V_2 ) )
return FALSE ;
V_130 -> V_140 += sizeof( V_5 ) ;
return TRUE ;
}
static T_5 V_132 ( T_9 * V_130 ,
const struct V_67 * V_58 ,
const T_7 * V_68 , int * V_2 )
{
const union V_71 * V_72 = & V_58 -> V_72 ;
struct V_73 V_74 ;
T_7 V_80 [ 24 ] ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_75 = F_18 ( sizeof( V_74 ) + 4 ) ;
V_74 . V_83 = F_20 ( V_105 ) ;
V_74 . V_117 = F_20 ( V_58 -> V_115 . V_116 ) ;
V_74 . V_119 = F_20 ( V_58 -> V_115 . V_118 / 1000 ) ;
V_74 . V_59 = F_20 ( V_58 -> V_59 ) ;
V_74 . V_69 = F_20 ( V_58 -> V_114 ) ;
V_74 . V_120 = - 1 ;
V_74 . V_121 = - 1 ;
V_74 . V_122 = - 1 ;
switch ( V_58 -> V_63 ) {
case V_35 :
V_74 . V_59 = F_20 ( V_58 -> V_59 + 3 ) ;
V_74 . V_69 = F_20 ( V_58 -> V_114 + 3 ) ;
case V_51 :
case V_38 :
case V_44 :
case V_46 :
case V_48 :
case V_50 :
case V_128 :
V_74 . V_7 = F_18 ( V_72 -> V_9 . V_7 ) ;
V_74 . V_120 = F_20 ( V_72 -> V_9 . V_120 ) ;
V_74 . V_83 = F_20 ( V_72 -> V_9 . V_83 ) ;
V_74 . V_121 = F_20 ( V_72 -> V_9 . V_121 ) ;
V_74 . V_122 = F_18 ( V_72 -> V_9 . V_122 ) ;
break;
case V_141 :
V_74 . V_7 = F_18 ( V_39 ) ;
break;
case V_125 :
V_74 . V_7 = F_18 ( V_93 ) ;
break;
case V_126 :
V_74 . V_7 = F_18 ( V_32 ) ;
V_74 . V_59 = F_20 ( V_58 -> V_59 + 3 ) ;
V_74 . V_69 = F_20 ( V_58 -> V_114 + 3 ) ;
break;
case V_127 :
V_74 . V_7 = F_18 ( V_37 ) ;
break;
default:
* V_2 = V_129 ;
return FALSE ;
}
if ( ! F_19 ( V_130 , & V_74 , sizeof( V_74 ) , V_2 ) )
return FALSE ;
V_130 -> V_140 += sizeof( V_74 ) ;
memset ( V_80 , 0 , sizeof V_80 ) ;
if ( ! F_19 ( V_130 , V_80 , 4 , V_2 ) )
return FALSE ;
V_130 -> V_140 += 4 ;
if ( ( V_58 -> V_63 == V_126 ) ||
( V_58 -> V_63 == V_35 ) ) {
if ( ! F_19 ( V_130 , V_80 , 3 , V_2 ) )
return FALSE ;
V_130 -> V_140 += 3 ;
}
if ( ! F_19 ( V_130 , V_68 , V_58 -> V_59 , V_2 ) )
return FALSE ;
V_130 -> V_140 += V_58 -> V_59 ;
return TRUE ;
}
