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
F_4 ( L_4 , V_23 , V_24 ) ;
F_4 ( L_5 , V_13 -> V_25 ) ;
if ( V_13 -> V_25 ) {
F_4 ( L_6 , V_23 , V_13 -> V_21 ) ;
return - V_26 ;
}
F_4 ( L_7 , V_23 , V_13 -> V_21 ) ;
V_20 = F_11 ( sizeof( struct V_19 ) , V_27 ) ;
if ( V_20 == NULL ) {
V_14 = - 1 ;
goto V_28;
}
V_17 = F_12 ( V_13 -> V_21 , NULL ) ;
if ( F_13 ( V_17 ) ) {
V_14 = F_14 ( V_17 ) ;
goto V_29;
}
V_18 = F_15 ( L_8 , V_30 | V_31 , V_17 ,
V_13 , & V_32 ) ;
if ( F_13 ( V_18 ) ) {
V_14 = F_14 ( V_18 ) ;
goto V_33;
}
V_20 -> V_34 = V_17 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_35 = V_13 -> V_22 ;
F_16 ( & ( V_20 -> V_9 ) , & ( V_13 -> V_36 . V_9 ) ) ;
F_4 ( L_9 , V_23 , V_13 -> V_21 ) ;
V_13 -> V_37 = 0 ;
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
V_13 -> V_39 [ V_15 ] . V_40 = 0 ;
V_13 -> V_39 [ V_15 ] . V_41 = 0 ;
V_13 -> V_39 [ V_15 ] . V_42 = 0 ;
V_13 -> V_39 [ V_15 ] . V_43 = 0 ;
V_13 -> V_39 [ V_15 ] . V_44 = NULL ;
V_13 -> V_39 [ V_15 ] . V_45 = V_15 + 1 ;
V_13 -> V_39 [ V_15 ] . V_46 = 0 ;
V_13 -> V_39 [ V_15 ] . V_47 = 0 ;
F_17 ( & V_13 -> V_39 [ V_15 ] . V_48 ) ;
F_18 ( & V_13 -> V_39 [ V_15 ] . V_49 ) ;
}
V_13 -> V_25 = TRUE ;
V_24 ++ ;
return 0 ;
V_33:
F_19 ( V_17 ) ;
V_29:
F_20 ( V_20 ) ;
V_28:
return V_14 ;
}
void F_21 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_22 ( V_51 ) ;
struct V_12 * V_13 = V_53 -> V_54 ;
int V_15 ;
struct V_1 * V_10 ;
struct V_1 * V_5 ;
struct V_2 * V_55 , * V_56 ;
struct V_19 * V_17 ;
F_4 ( L_10 , V_23 ) ;
if ( V_13 -> V_25 ) {
V_24 -- ;
F_23 (pos, q, &dev->nodes.list) {
V_17 = F_5 ( V_55 , struct V_19 , V_9 ) ;
if ( V_17 -> V_35 == V_13 -> V_22 ) {
F_19 ( V_17 -> V_18 ) ;
F_19 ( V_17 -> V_34 ) ;
F_6 ( V_55 ) ;
F_20 ( V_17 ) ;
}
}
F_4 ( L_11 , V_23 ,
V_13 -> V_21 ) ;
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
while ( F_3 ( & V_13 -> V_39 [ V_15 ] . V_49 ) == 0 ) {
V_10 = F_5 ( V_13 -> V_39 [ V_15 ] . V_49 . V_8 , struct V_1 , V_9 ) ;
F_6 ( & V_10 -> V_9 ) ;
F_8 ( V_10 , & V_57 ) ;
}
F_24 ( & V_13 -> V_39 [ V_15 ] . V_48 ) ;
}
if ( V_24 == 0 ) {
while ( F_3 ( & V_57 ) == 0 ) {
V_5 = F_5 ( V_57 . V_8 , struct V_1 , V_9 ) ;
F_6 ( & V_5 -> V_9 ) ;
F_20 ( V_5 -> V_58 ) ;
F_20 ( V_5 ) ;
}
}
V_13 -> V_25 = FALSE ;
}
}
static int F_25 ( struct V_59 * V_59 , struct V_18 * V_18 )
{
struct V_52 * V_53 ;
struct V_12 * V_13 = (struct V_12 * ) V_59 -> V_60 ;
int V_15 , V_61 ;
F_4 ( L_10 , V_23 ) ;
V_61 = ( F_26 ( V_59 -> V_62 ) & 0xf ) ;
F_4 ( L_12 , V_61 ) ;
V_53 = V_18 -> V_63 = F_22 ( V_13 -> V_64 ) ;
F_4 ( L_13 , ( & V_18 -> V_65 ) , V_13 -> V_37 ) ;
if ( V_13 -> V_37 > V_38 ) {
F_4 ( L_14 ) ;
return - V_66 ;
}
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
if ( ( V_13 -> V_39 [ V_15 ] . V_44 == NULL ) ) {
break;
}
}
if ( V_15 == V_38 ) {
F_4 ( L_15 ) ;
return - V_66 ;
}
V_13 -> V_37 ++ ;
V_13 -> V_39 [ V_15 ] . V_44 = & V_18 -> V_65 ;
V_13 -> V_39 [ V_15 ] . V_40 = 0 ;
V_13 -> V_39 [ V_15 ] . V_41 = 0 ;
V_13 -> V_39 [ V_15 ] . V_42 = 0 ;
V_13 -> V_39 [ V_15 ] . V_43 = 0 ;
F_27 ( V_59 , V_18 ) ;
return 0 ;
}
static unsigned int F_28 ( struct V_18 * V_18 , T_1 * V_67 )
{
struct V_50 * V_51 = V_18 -> V_63 ;
struct V_52 * V_53 = F_22 ( V_51 ) ;
struct V_12 * V_13 = V_53 -> V_54 ;
int V_15 ;
if ( V_24 == 0 ) {
F_4 ( L_16 ) ;
return ( - V_68 ) ;
}
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
if ( V_13 -> V_39 [ V_15 ] . V_44 == & V_18 -> V_65 ) {
break;
}
}
if ( V_15 == V_38 ) {
F_4 ( L_17 ) ;
return ( - V_66 ) ;
}
if ( F_3 ( & V_13 -> V_39 [ V_15 ] . V_49 ) == 0 ) {
F_4 ( L_18 ) ;
return ( V_69 | V_70 | V_71 ) ;
}
F_29 ( V_18 , & V_13 -> V_39 [ V_15 ] . V_48 , V_67 ) ;
return ( 0 ) ;
}
static long F_30 ( struct V_18 * V_18 , unsigned int V_72 ,
unsigned long V_73 )
{
void T_2 * V_74 = ( void T_2 * ) V_73 ;
struct V_52 * V_53 ;
struct V_12 * V_75 ;
int V_14 = 0 ;
int V_76 ;
int V_15 ;
T_3 V_77 ;
unsigned long V_4 ;
struct V_78 V_79 ;
struct V_80 V_81 ;
struct V_82 V_83 ;
T_4 V_84 [] = { 0x00 , 0x44 , 0x10 , 0x20 , 0x80 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x03 , 0x00 , 0x00 , 0x00 , 0x93 , 0x64 ,
0x00 , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x05 , 0x00 , 0x00 , 0x00 , 0x0a ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x02 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x12 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x02 , 0x37 , 0x00 , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 , 0x00 , 0x01 , 0x00 , 0x01 , 0x7f , 0x00 ,
0x00 , 0x01 , 0x00 , 0x00 } ;
unsigned short V_85 = 0 ;
unsigned short V_86 = 0 ;
if ( V_24 == 0 ) {
F_4 ( L_19 ) ;
return ( - V_68 ) ;
}
V_53 = V_18 -> V_63 ;
V_75 = V_53 -> V_54 ;
V_76 = F_31 ( V_72 ) ;
switch ( V_76 ) {
case V_87 :
F_4 ( L_20 ) ;
V_14 = F_32 ( V_77 , ( V_88 T_2 * ) V_74 ) ;
if ( V_14 ) {
F_4 ( L_21 , V_14 ) ;
break;
}
if ( V_77 == V_89 ) {
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
if ( V_75 -> V_39 [ V_15 ] . V_44 == & V_18 -> V_65 ) {
V_75 -> V_39 [ V_15 ] . V_46 = 1 ;
F_4 ( L_22 ) ;
break;
}
}
}
break;
case V_90 :
F_4 ( L_23 ) ;
V_81 . V_91 = V_92 ;
if ( F_33 ( V_74 , & V_81 , sizeof( V_81 ) ) ) {
F_4 ( L_24 ) ;
V_14 = - V_93 ;
break;
}
F_4 ( L_25 , ( unsigned int ) V_81 . V_91 ) ;
break;
case V_94 :
F_4 ( L_26 ) ;
V_84 [ 79 ] = 0xfc ;
V_14 = F_34 ( V_75 , ( unsigned short * ) V_84 , 0x4c ) ;
break;
case V_95 :
F_4 ( L_27 ) ;
V_84 [ 79 ] = 0xfd ;
V_14 = F_34 ( V_75 , ( unsigned short * ) V_84 , 0x4c ) ;
break;
case V_96 :
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
memcpy ( V_83 . V_97 , V_53 -> V_97 , V_98 ) ;
memcpy ( V_83 . V_99 , V_53 -> V_99 , V_100 ) ;
memcpy ( V_83 . V_101 , V_53 -> V_101 , V_102 ) ;
memcpy ( V_83 . V_103 , V_53 -> V_103 , V_104 ) ;
if ( V_53 -> V_105 != 0xFF ) {
F_35 ( V_75 , V_106 , ( T_4 * ) & V_85 , V_107 ) ;
V_83 . V_108 = F_36 ( V_85 ) ;
F_4 ( L_28 , V_83 . V_108 ) ;
F_35 ( V_75 , V_109 , ( T_4 * ) & V_86 , V_110 ) ;
V_83 . V_111 = F_36 ( V_86 ) ;
F_4 ( L_29 , V_83 . V_111 ) ;
} else {
V_83 . V_111 = 0x0f ;
}
V_83 . V_112 = V_53 -> V_113 . V_114 ;
V_83 . V_115 = V_53 -> V_113 . V_116 ;
V_83 . V_117 = V_53 -> V_113 . V_118 ;
V_83 . V_119 = V_53 -> V_113 . V_120 ;
F_37 ( & V_79 ) ;
V_83 . V_121 = ( V_122 ) ( V_79 . V_123 - V_53 -> V_121 ) ;
F_4 ( L_30 , ( int ) V_83 . V_121 ) ;
if ( F_33 ( V_74 , & V_83 , sizeof( V_83 ) ) ) {
F_4 ( L_24 ) ;
V_14 = - V_93 ;
break;
}
F_4 ( L_31 ) ;
break;
case V_124 :
{
struct V_125 * V_126 = NULL ;
T_3 V_127 ;
T_3 V_128 ;
struct V_129 * V_130 ;
T_3 * V_131 ;
T_3 V_132 ;
T_3 V_133 ;
T_3 V_134 ;
if ( V_24 == 0 ) {
return ( - V_68 ) ;
}
if ( V_75 -> V_135 ) {
return ( - V_136 ) ;
}
if ( V_75 -> V_137 == 0 ) {
return ( - V_66 ) ;
}
V_75 -> V_138 = 1 ;
if ( V_53 -> V_139 ) {
V_14 = F_32 ( V_128 , ( V_88 T_2 * ) V_74 ) ;
if ( V_14 )
break;
V_128 = F_36 ( V_128 ) ;
if ( V_128 > V_140 ) {
F_4 ( L_32 , V_128 ) ;
V_14 = - V_141 ;
break;
}
V_14 = - V_142 ;
V_126 = F_11 ( V_128 + 2 , V_27 ) ;
if ( ! V_126 )
break;
if ( F_38 ( V_126 , V_74 , V_128 + 2 ) ) {
F_4 ( L_33 ) ;
V_14 = - V_93 ;
} else {
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
if ( V_75 -> V_39 [ V_15 ] . V_44 == & V_18 -> V_65 ) {
break;
}
}
if ( V_15 == V_38 ) {
F_4 ( L_34 ) ;
V_14 = - V_141 ;
F_20 ( V_126 ) ;
break;
}
V_133 = V_15 ;
V_127 = F_36 ( V_126 -> V_143 . V_144 ) & 0xff ;
if ( V_127 ) {
} else {
V_134 = F_39 ( V_75 , & V_77 , V_145 ) ;
if ( V_77 & V_146 ) {
F_40 ( 2 ) ;
V_134 = F_39 ( V_75 , & V_77 , V_145 ) ;
if ( V_77 & V_146 ) {
F_40 ( 1 ) ;
V_134 = F_39 ( V_75 , & V_77 , V_145 ) ;
if ( V_77 & V_146 ) {
V_134 = F_39 ( V_75 , & V_77 , V_145 ) ;
if ( V_77 & V_146 ) {
F_40 ( 3 ) ;
V_134 = F_39 ( V_75 , & V_77 , V_145 ) ;
if ( V_77 & V_146 ) {
F_4 ( L_35 ) ;
V_14 = - V_136 ;
F_20 ( V_126 ) ;
break;
}
}
}
}
}
if ( ( V_128 < V_140 ) && ( V_128 > V_147 ) ) {
V_131 = ( T_3 * ) & V_126 -> V_143 ;
V_130 = (struct V_129 * ) V_131 ;
V_132 = V_128 + 2 ;
if ( V_132 & 0x1 ) {
V_132 ++ ;
}
V_130 -> V_148 = V_53 -> V_149 ++ ;
V_130 -> V_150 = V_75 -> V_39 [ V_133 ] . V_45 ;
V_130 -> V_151 = * V_131 ++ ;
for ( V_15 = 1 ; V_15 < 7 ; V_15 ++ ) {
V_130 -> V_151 ^= * V_131 ++ ;
}
V_131 ++ ;
V_130 = (struct V_129 * ) V_131 ;
V_14 = F_34 ( V_75 , ( unsigned short * ) V_126 , V_132 + 2 ) ;
V_75 -> V_39 [ V_133 ] . V_40 ++ ;
} else {
V_14 = - V_141 ;
}
}
}
} else {
F_4 ( L_36 ) ;
V_14 = - V_66 ;
}
F_20 ( V_126 ) ;
}
break;
case V_152 :
{
struct V_1 * V_10 ;
struct V_125 T_2 * V_153 ;
int V_154 ;
if ( V_24 == 0 ) {
return ( - V_68 ) ;
}
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
if ( V_75 -> V_39 [ V_15 ] . V_44 == & V_18 -> V_65 ) {
break;
}
}
if ( V_15 == V_38 ) {
F_4 ( L_17 ) ;
V_14 = - V_68 ;
break;
}
V_14 = 0 ;
V_153 = V_74 ;
if ( F_3 ( & V_75 -> V_39 [ V_15 ] . V_49 ) == 0 ) {
F_2 ( & V_6 , V_4 ) ;
V_10 = F_5 ( V_75 -> V_39 [ V_15 ] . V_49 . V_8 , struct V_1 , V_9 ) ;
F_6 ( & V_10 -> V_9 ) ;
V_75 -> V_39 [ V_15 ] . V_47 -- ;
F_7 ( & V_6 , V_4 ) ;
V_154 = F_36 ( * ( T_3 * ) V_10 -> V_58 ) + V_147 ;
V_14 = F_32 ( V_154 , & V_153 -> V_132 ) ;
if ( V_14 )
break;
V_154 = F_41 ( V_154 ) ;
if ( F_33 ( & V_153 -> V_143 , V_10 -> V_58 , V_154 ) ) {
F_4 ( L_24 ) ;
V_14 = - V_93 ;
break;
}
F_8 ( V_10 , & V_57 ) ;
V_14 = V_154 ;
}
}
break;
default:
F_4 ( L_37 , V_72 ) ;
V_14 = - V_136 ;
break;
}
V_75 -> V_138 = 0 ;
return V_14 ;
}
static int F_42 ( struct V_59 * V_59 , struct V_18 * V_18 )
{
struct V_52 * V_53 ;
struct V_50 * V_13 ;
struct V_12 * V_75 ;
int V_15 ;
struct V_1 * V_10 ;
F_4 ( L_38 ) ;
V_13 = V_18 -> V_63 ;
V_53 = F_22 ( V_13 ) ;
V_75 = V_53 -> V_54 ;
if ( V_24 == 0 ) {
V_75 -> V_37 -- ;
return ( - V_68 ) ;
}
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ ) {
if ( V_75 -> V_39 [ V_15 ] . V_44 == & V_18 -> V_65 ) {
break;
}
}
if ( V_15 == V_38 )
return 0 ;
while ( F_3 ( & V_75 -> V_39 [ V_15 ] . V_49 ) == 0 ) {
F_4 ( L_39 ) ;
V_10 = F_5 ( V_75 -> V_39 [ V_15 ] . V_49 . V_8 , struct V_1 , V_9 ) ;
F_6 ( & V_10 -> V_9 ) ;
F_8 ( V_10 , & V_57 ) ;
}
V_75 -> V_37 -- ;
F_4 ( L_40 , V_23 , V_75 -> V_37 ) ;
V_75 -> V_39 [ V_15 ] . V_44 = NULL ;
return 0 ;
}
