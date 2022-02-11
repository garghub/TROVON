struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
struct V_1 * V_5 ;
F_2 ( & V_6 , V_4 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( L_1 , V_7 ) ;
V_5 = NULL ;
} else {
V_7 -- ;
V_5 = F_5 ( V_3 -> V_8 , struct V_1 , V_9 ) ;
F_6 ( & V_5 -> V_9 ) ;
}
F_7 ( & V_6 , V_4 ) ;
return V_5 ;
}
void F_8 ( struct V_1 * V_10 , struct V_2 * V_11 )
{
unsigned long V_4 ;
F_2 ( & V_6 , V_4 ) ;
F_9 ( & V_10 -> V_9 , V_11 ) ;
V_7 ++ ;
F_7 ( & V_6 , V_4 ) ;
}
int F_10 ( struct V_12 * V_13 )
{
int V_14 ;
int V_15 ;
struct V_16 * V_17 , * V_18 ;
struct V_19 * V_20 ;
sprintf ( V_13 -> V_21 , L_2 , L_3 , V_13 -> V_22 ) ;
F_4 ( L_4 , V_23 ) ;
F_4 ( L_5 , V_13 -> V_24 ) ;
if ( V_13 -> V_24 ) {
F_4 ( L_6 , V_13 -> V_21 ) ;
return - V_25 ;
}
F_4 ( L_7 , V_13 -> V_21 ) ;
V_20 = F_11 ( sizeof( struct V_19 ) , V_26 ) ;
if ( V_20 == NULL ) {
V_14 = - 1 ;
goto V_27;
}
V_17 = F_12 ( V_13 -> V_21 , NULL ) ;
if ( F_13 ( V_17 ) ) {
V_14 = F_14 ( V_17 ) ;
goto V_28;
}
V_18 = F_15 ( L_8 , V_29 | V_30 , V_17 ,
V_13 , & V_31 ) ;
if ( F_13 ( V_18 ) ) {
V_14 = F_14 ( V_18 ) ;
goto V_32;
}
V_20 -> V_33 = V_17 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_34 = V_13 -> V_22 ;
F_16 ( & V_20 -> V_9 , & V_13 -> V_35 . V_9 ) ;
F_4 ( L_9 , V_13 -> V_21 ) ;
V_13 -> V_36 = 0 ;
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
V_13 -> V_38 [ V_15 ] . V_39 = 0 ;
V_13 -> V_38 [ V_15 ] . V_40 = 0 ;
V_13 -> V_38 [ V_15 ] . V_41 = 0 ;
V_13 -> V_38 [ V_15 ] . V_42 = 0 ;
V_13 -> V_38 [ V_15 ] . V_43 = NULL ;
V_13 -> V_38 [ V_15 ] . V_44 = V_15 + 1 ;
V_13 -> V_38 [ V_15 ] . V_45 = 0 ;
V_13 -> V_38 [ V_15 ] . V_46 = 0 ;
F_17 ( & V_13 -> V_38 [ V_15 ] . V_47 ) ;
F_18 ( & V_13 -> V_38 [ V_15 ] . V_48 ) ;
}
V_13 -> V_24 = TRUE ;
V_23 ++ ;
return 0 ;
V_32:
F_19 ( V_17 ) ;
V_28:
F_20 ( V_20 ) ;
V_27:
return V_14 ;
}
void F_21 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = F_22 ( V_50 ) ;
struct V_12 * V_13 = V_52 -> V_53 ;
int V_15 ;
struct V_1 * V_10 ;
struct V_1 * V_5 ;
struct V_2 * V_54 , * V_55 ;
struct V_19 * V_17 ;
if ( V_13 -> V_24 ) {
V_23 -- ;
F_23 (pos, q, &dev->nodes.list) {
V_17 = F_5 ( V_54 , struct V_19 , V_9 ) ;
if ( V_17 -> V_34 == V_13 -> V_22 ) {
F_19 ( V_17 -> V_18 ) ;
F_19 ( V_17 -> V_33 ) ;
F_6 ( V_54 ) ;
F_20 ( V_17 ) ;
}
}
F_4 ( L_10 , V_13 -> V_21 ) ;
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
while ( F_3 ( & V_13 -> V_38 [ V_15 ] . V_48 ) == 0 ) {
V_10 = F_5 ( V_13 -> V_38 [ V_15 ] . V_48 . V_8 ,
struct V_1 , V_9 ) ;
F_6 ( & V_10 -> V_9 ) ;
F_8 ( V_10 , & V_56 ) ;
}
F_24 ( & V_13 -> V_38 [ V_15 ] . V_47 ) ;
}
if ( V_23 == 0 ) {
while ( F_3 ( & V_56 ) == 0 ) {
V_5 = F_5 ( V_56 . V_8 , struct V_1 , V_9 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_20 ( V_5 -> V_57 ) ;
F_20 ( V_5 ) ;
}
}
V_13 -> V_24 = FALSE ;
}
}
static int F_25 ( struct V_58 * V_58 , struct V_18 * V_18 )
{
struct V_51 * V_52 ;
struct V_12 * V_13 = (struct V_12 * ) V_58 -> V_59 ;
int V_15 , V_60 ;
V_60 = F_26 ( V_58 -> V_61 ) & 0xf ;
F_4 ( L_11 , V_60 ) ;
V_52 = V_18 -> V_62 = F_22 ( V_13 -> V_63 ) ;
F_4 ( L_12 ,
& V_18 -> V_64 , V_13 -> V_36 ) ;
if ( V_13 -> V_36 > V_37 ) {
F_4 ( L_13 ) ;
return - V_65 ;
}
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
if ( V_13 -> V_38 [ V_15 ] . V_43 == NULL )
break;
}
if ( V_15 == V_37 ) {
F_4 ( L_14 ) ;
return - V_65 ;
}
V_13 -> V_36 ++ ;
V_13 -> V_38 [ V_15 ] . V_43 = & V_18 -> V_64 ;
V_13 -> V_38 [ V_15 ] . V_39 = 0 ;
V_13 -> V_38 [ V_15 ] . V_40 = 0 ;
V_13 -> V_38 [ V_15 ] . V_41 = 0 ;
V_13 -> V_38 [ V_15 ] . V_42 = 0 ;
F_27 ( V_58 , V_18 ) ;
return 0 ;
}
static unsigned int F_28 ( struct V_18 * V_18 , T_1 * V_66 )
{
struct V_49 * V_50 = V_18 -> V_62 ;
struct V_51 * V_52 = F_22 ( V_50 ) ;
struct V_12 * V_13 = V_52 -> V_53 ;
int V_15 ;
if ( V_23 == 0 ) {
F_4 ( L_15 ) ;
return - V_67 ;
}
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
if ( V_13 -> V_38 [ V_15 ] . V_43 == & V_18 -> V_64 ) {
break;
}
}
if ( V_15 == V_37 ) {
F_4 ( L_16 ) ;
return - V_65 ;
}
if ( F_3 ( & V_13 -> V_38 [ V_15 ] . V_48 ) == 0 ) {
F_4 ( L_17 ) ;
return ( V_68 | V_69 | V_70 ) ;
}
F_29 ( V_18 , & V_13 -> V_38 [ V_15 ] . V_47 , V_66 ) ;
return 0 ;
}
static long F_30 ( struct V_18 * V_18 , unsigned int V_71 ,
unsigned long V_72 )
{
void T_2 * V_73 = ( void T_2 * ) V_72 ;
struct V_51 * V_52 ;
struct V_12 * V_74 ;
int V_14 = 0 ;
int V_75 ;
int V_15 ;
T_3 V_76 ;
unsigned long V_4 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
struct V_81 V_82 ;
T_4 V_83 [] = {
0x00 , 0x44 , 0x10 , 0x20 , 0x80 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x03 , 0x00 , 0x00 , 0x00 , 0x93 , 0x64 ,
0x00 , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x05 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x12 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x02 , 0x37 , 0x00 , 0x00 , 0x00 , 0x08 ,
0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x01 , 0x7f , 0x00 ,
0x00 , 0x01 , 0x00 , 0x00
} ;
unsigned short V_84 = 0 ;
unsigned short V_85 = 0 ;
if ( V_23 == 0 ) {
F_4 ( L_18 ) ;
return - V_67 ;
}
V_52 = V_18 -> V_62 ;
V_74 = V_52 -> V_53 ;
V_75 = F_31 ( V_71 ) ;
switch ( V_75 ) {
case V_86 :
F_4 ( L_19 ) ;
V_14 = F_32 ( V_76 , ( V_87 T_2 * ) V_73 ) ;
if ( V_14 ) {
F_4 ( L_20 , V_14 ) ;
break;
}
if ( V_76 == V_88 ) {
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
if ( V_74 -> V_38 [ V_15 ] . V_43 == & V_18 -> V_64 ) {
V_74 -> V_38 [ V_15 ] . V_45 = 1 ;
F_4 ( L_21 ) ;
break;
}
}
}
break;
case V_89 :
F_4 ( L_22 ) ;
V_80 . V_90 = V_91 ;
if ( F_33 ( V_73 , & V_80 , sizeof( V_80 ) ) ) {
F_4 ( L_23 ) ;
V_14 = - V_92 ;
break;
}
F_4 ( L_24 ,
( unsigned int ) V_80 . V_90 ) ;
break;
case V_93 :
F_4 ( L_25 ) ;
V_83 [ 79 ] = 0xfc ;
V_14 = F_34 ( V_74 , V_83 , 0x4c ) ;
break;
case V_94 :
F_4 ( L_26 ) ;
V_83 [ 79 ] = 0xfd ;
V_14 = F_34 ( V_74 , V_83 , 0x4c ) ;
break;
case V_95 :
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
memcpy ( V_82 . V_96 , V_52 -> V_96 , V_97 ) ;
memcpy ( V_82 . V_98 , V_52 -> V_98 , V_99 ) ;
memcpy ( V_82 . V_100 , V_52 -> V_100 , V_101 ) ;
memcpy ( V_82 . V_102 , V_52 -> V_102 , V_103 ) ;
if ( V_52 -> V_104 != 0xFF ) {
F_35 ( V_74 , V_105 ,
( T_4 * ) & V_84 , V_106 ) ;
V_82 . V_107 = F_36 ( V_84 ) ;
F_4 ( L_27 , V_82 . V_107 ) ;
F_35 ( V_74 , V_108 ,
( T_4 * ) & V_85 , V_109 ) ;
V_82 . V_110 = F_36 ( V_85 ) ;
F_4 ( L_28 , V_82 . V_110 ) ;
} else {
V_82 . V_110 = 0x0f ;
}
V_82 . V_111 = V_52 -> V_112 . V_113 ;
V_82 . V_114 = V_52 -> V_112 . V_115 ;
V_82 . V_116 = V_52 -> V_112 . V_117 ;
V_82 . V_118 = V_52 -> V_112 . V_119 ;
F_37 ( & V_78 ) ;
V_82 . V_120 = ( V_121 ) ( V_78 . V_122 - V_52 -> V_120 ) ;
F_4 ( L_29 , ( int ) V_82 . V_120 ) ;
if ( F_33 ( V_73 , & V_82 , sizeof( V_82 ) ) ) {
F_4 ( L_23 ) ;
V_14 = - V_92 ;
break;
}
F_4 ( L_30 ) ;
break;
case V_123 :
{
struct V_124 * V_125 = NULL ;
T_3 V_126 ;
T_3 V_127 ;
struct V_128 * V_129 ;
T_3 * V_130 ;
T_3 V_131 ;
T_3 V_132 ;
T_3 V_133 ;
if ( V_23 == 0 )
return - V_67 ;
if ( V_74 -> V_134 )
return - V_135 ;
if ( V_74 -> V_136 == 0 )
return - V_65 ;
V_74 -> V_137 = true ;
if ( V_52 -> V_138 ) {
V_14 = F_32 ( V_127 , ( V_87 T_2 * ) V_73 ) ;
if ( V_14 )
break;
V_127 = F_36 ( V_127 ) ;
if ( V_127 > V_139 ) {
F_4 ( L_31 , V_127 ) ;
V_14 = - V_140 ;
break;
}
V_14 = - V_141 ;
V_125 = F_11 ( V_127 + 2 , V_26 ) ;
if ( ! V_125 )
break;
if ( F_38 ( V_125 , V_73 , V_127 + 2 ) ) {
F_4 ( L_23 ) ;
V_14 = - V_92 ;
} else {
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
if ( V_74 -> V_38 [ V_15 ] . V_43 == & V_18 -> V_64 )
break;
}
if ( V_15 == V_37 ) {
F_4 ( L_32 ) ;
V_14 = - V_140 ;
F_20 ( V_125 ) ;
break;
}
V_132 = V_15 ;
V_126 = F_36 ( V_125 -> V_142 . V_143 ) & 0xff ;
if ( ! V_126 ) {
V_133 = F_39 ( V_74 , & V_76 , V_144 ) ;
if ( V_76 & V_145 ) {
F_40 ( 2 ) ;
V_133 = F_39 ( V_74 , & V_76 , V_144 ) ;
if ( V_76 & V_145 ) {
F_40 ( 1 ) ;
V_133 = F_39 ( V_74 , & V_76 , V_144 ) ;
if ( V_76 & V_145 ) {
V_133 = F_39 ( V_74 , & V_76 , V_144 ) ;
if ( V_76 & V_145 ) {
F_40 ( 3 ) ;
V_133 = F_39 ( V_74 , & V_76 , V_144 ) ;
if ( V_76 & V_145 ) {
F_4 ( L_33 ) ;
V_14 = - V_135 ;
F_20 ( V_125 ) ;
break;
}
}
}
}
}
if ( ( V_127 < V_139 ) && ( V_127 > V_146 ) ) {
V_130 = ( T_3 * ) & V_125 -> V_142 ;
V_129 = (struct V_128 * ) V_130 ;
V_131 = V_127 + 2 ;
if ( V_131 & 0x1 )
V_131 ++ ;
V_129 -> V_147 = V_52 -> V_148 ++ ;
V_129 -> V_149 = V_74 -> V_38 [ V_132 ] . V_44 ;
V_129 -> V_150 = * V_130 ++ ;
for ( V_15 = 1 ; V_15 < 7 ; V_15 ++ ) {
V_129 -> V_150 ^= * V_130 ++ ;
}
V_130 ++ ;
V_129 = (struct V_128 * ) V_130 ;
V_14 = F_34 ( V_74 , V_125 , V_131 + 2 ) ;
V_74 -> V_38 [ V_132 ] . V_39 ++ ;
} else {
V_14 = - V_140 ;
}
}
}
} else {
F_4 ( L_34 ) ;
V_14 = - V_65 ;
}
F_20 ( V_125 ) ;
}
break;
case V_151 :
{
struct V_1 * V_10 ;
struct V_124 T_2 * V_152 ;
int V_153 ;
if ( V_23 == 0 )
return - V_67 ;
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
if ( V_74 -> V_38 [ V_15 ] . V_43 == & V_18 -> V_64 ) {
break;
}
}
if ( V_15 == V_37 ) {
F_4 ( L_16 ) ;
V_14 = - V_67 ;
break;
}
V_14 = 0 ;
V_152 = V_73 ;
if ( F_3 ( & V_74 -> V_38 [ V_15 ] . V_48 ) == 0 ) {
F_2 ( & V_6 , V_4 ) ;
V_10 = F_5 ( V_74 -> V_38 [ V_15 ] . V_48 . V_8 ,
struct V_1 , V_9 ) ;
F_6 ( & V_10 -> V_9 ) ;
V_74 -> V_38 [ V_15 ] . V_46 -- ;
F_7 ( & V_6 , V_4 ) ;
V_153 = F_36 ( * ( T_3 * ) V_10 -> V_57 ) + V_146 ;
V_14 = F_32 ( V_153 , & V_152 -> V_131 ) ;
if ( V_14 )
break;
V_153 = F_41 ( V_153 ) ;
if ( F_33 ( & V_152 -> V_142 , V_10 -> V_57 , V_153 ) ) {
F_4 ( L_23 ) ;
V_14 = - V_92 ;
break;
}
F_8 ( V_10 , & V_56 ) ;
V_14 = V_153 ;
}
}
break;
default:
F_4 ( L_35 , V_71 ) ;
V_14 = - V_135 ;
break;
}
V_74 -> V_137 = false ;
return V_14 ;
}
static int F_42 ( struct V_58 * V_58 , struct V_18 * V_18 )
{
struct V_51 * V_52 ;
struct V_49 * V_13 ;
struct V_12 * V_74 ;
int V_15 ;
struct V_1 * V_10 ;
struct V_1 * V_20 ;
V_13 = V_18 -> V_62 ;
V_52 = F_22 ( V_13 ) ;
V_74 = V_52 -> V_53 ;
if ( V_23 == 0 ) {
V_74 -> V_36 -- ;
return - V_67 ;
}
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
if ( V_74 -> V_38 [ V_15 ] . V_43 == & V_18 -> V_64 ) {
break;
}
}
if ( V_15 == V_37 )
return 0 ;
F_43 (pdpram_blk, tmp, &ft1000dev->app_info[i].app_sqlist, list) {
F_4 ( L_36 ) ;
F_6 ( & V_10 -> V_9 ) ;
F_8 ( V_10 , & V_56 ) ;
}
V_74 -> V_36 -- ;
F_4 ( L_37 , V_74 -> V_36 ) ;
V_74 -> V_38 [ V_15 ] . V_43 = NULL ;
return 0 ;
}
