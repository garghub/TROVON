static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
F_2 (cursor, next, &card->cmd_packet_list) {
V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
F_4 ( & V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
F_2 (cursor, next, &card->data_packet_list) {
V_7 = F_3 ( V_4 , struct V_6 , V_8 ) ;
F_4 ( & V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( ! F_7 ( V_9 , V_2 -> V_10 + 1 ) ) {
F_8 ( 400 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_10 = V_9 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_11 , const T_2 * V_12 , int V_13 )
{
int V_14 = 0 ;
T_3 V_15 = F_11 ( V_11 | V_16 ) ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_19 V_21 ;
F_12 ( & V_18 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
F_13 ( V_13 & 0x1 ) ;
F_6 ( V_2 ) ;
V_20 . V_22 = & V_15 ;
V_20 . V_13 = sizeof( V_15 ) ;
V_21 . V_22 = V_12 ;
V_21 . V_13 = V_13 ;
F_14 ( & V_20 , & V_18 ) ;
F_14 ( & V_21 , & V_18 ) ;
V_14 = F_15 ( V_2 -> V_23 , & V_18 ) ;
F_9 ( V_2 ) ;
return V_14 ;
}
static inline int F_16 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_24 )
{
T_3 V_25 ;
V_25 = F_11 ( V_24 ) ;
return F_10 ( V_2 , V_11 , ( T_2 * ) & V_25 , sizeof( T_1 ) ) ;
}
static inline int F_17 ( T_1 V_11 )
{
switch ( V_11 ) {
case V_26 :
case V_27 :
case V_28 :
return 1 ;
default:
return 0 ;
}
}
static int F_18 ( struct V_1 * V_2 , T_1 V_11 , T_2 * V_12 , int V_13 )
{
unsigned int V_29 ;
int V_14 = 0 ;
T_3 V_15 = F_11 ( V_11 | V_30 ) ;
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_19 V_31 ;
struct V_19 V_21 ;
F_13 ( V_13 & 0x1 ) ;
F_6 ( V_2 ) ;
F_12 ( & V_18 ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_20 . V_22 = & V_15 ;
V_20 . V_13 = sizeof( V_15 ) ;
F_14 ( & V_20 , & V_18 ) ;
V_29 = F_17 ( V_11 ) ? V_2 -> V_32 :
V_2 -> V_33 ;
if ( V_2 -> V_34 ) {
V_31 . V_13 = V_29 / 8 ;
F_14 ( & V_31 , & V_18 ) ;
} else {
V_20 . V_35 =
F_19 ( ( 100 + ( V_29 * 10 ) ) , 1000 ) ;
}
V_21 . V_36 = V_12 ;
V_21 . V_13 = V_13 ;
F_14 ( & V_21 , & V_18 ) ;
V_14 = F_15 ( V_2 -> V_23 , & V_18 ) ;
F_9 ( V_2 ) ;
return V_14 ;
}
static inline int F_20 ( struct V_1 * V_2 , T_1 V_11 , T_1 * V_24 )
{
T_3 V_12 ;
int V_37 ;
V_37 = F_18 ( V_2 , V_11 , ( T_2 * ) & V_12 , sizeof( V_12 ) ) ;
if ( V_37 == 0 )
* V_24 = F_21 ( & V_12 ) ;
return V_37 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_11 , T_4 * V_24 )
{
T_5 V_12 ;
int V_14 ;
V_14 = F_18 ( V_2 , V_11 , ( T_2 * ) & V_12 , sizeof( V_12 ) ) ;
if ( ! V_14 )
* V_24 = F_23 ( & V_12 ) ;
return V_14 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_11 ,
T_1 V_38 , T_1 V_39 )
{
int V_14 ;
unsigned long V_40 = V_9 + 5 * V_41 ;
while ( 1 ) {
T_1 V_24 ;
V_14 = F_20 ( V_2 , V_11 , & V_24 ) ;
if ( V_14 )
return V_14 ;
if ( V_38 ) {
if ( ( V_24 & V_38 ) == V_39 )
return 0 ;
} else {
if ( V_24 )
return 0 ;
}
F_25 ( 100 ) ;
if ( F_7 ( V_9 , V_40 ) ) {
F_26 ( L_1 ,
V_42 , V_24 , V_38 , V_39 ) ;
return - V_43 ;
}
}
}
static int F_27 ( struct V_1 * V_2 , T_4 V_11 , T_4 V_39 )
{
int V_14 , V_44 ;
for ( V_44 = 0 ; V_44 < 4 ; ++ V_44 ) {
T_4 V_24 = 0 ;
V_14 = F_22 ( V_2 , V_11 , & V_24 ) ;
if ( V_14 )
return V_14 ;
if ( V_24 == V_39 )
return 0 ;
F_28 ( 100 ) ;
}
return - V_43 ;
}
static int F_29 ( struct V_1 * V_2 ,
int V_45 ,
int V_46 )
{
int V_14 = 0 ;
if ( V_45 ) {
V_14 = F_16 ( V_2 , V_47 , 0 ) ;
if ( V_14 )
return V_14 ;
} else {
V_14 = F_16 ( V_2 , V_47 ,
V_48 |
V_49 |
V_50 |
V_51 |
V_52 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_46 ) {
V_14 = F_16 ( V_2 , V_53 ,
V_54 |
V_55 |
V_56 |
V_57 ) ;
if ( V_14 )
return V_14 ;
} else {
V_14 = F_16 ( V_2 , V_47 , 0 ) ;
if ( V_14 )
return V_14 ;
}
return V_14 ;
}
static int F_30 ( struct V_1 * V_2 ,
T_1 * V_58 , T_2 * V_59 )
{
int V_14 = 0 ;
T_4 V_60 ;
V_14 = F_22 ( V_2 , V_61 , & V_60 ) ;
if ( V_14 )
return V_14 ;
* V_58 = F_31 ( V_60 ) ;
* V_59 = F_32 ( V_60 ) ;
return V_14 ;
}
static int F_33 ( struct V_1 * V_2 , T_1 V_62 )
{
int V_14 = 0 ;
T_1 V_63 ;
V_14 = F_16 ( V_2 , V_64 , V_62 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_20 ( V_2 , V_64 , & V_63 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_63 & 0xF ) != V_62 ) {
F_26 ( L_2 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_34 )
{
int V_14 = 0 ;
T_4 V_29 ;
V_2 -> V_34 = 0 ;
V_14 = F_33 ( V_2 ,
V_66 |
V_67 |
V_68 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_32 = 1000 ;
V_2 -> V_33 = 1000 ;
V_14 = F_22 ( V_2 , V_69 , & V_29 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_32 = V_29 & 0x0000ffff ;
V_2 -> V_33 = ( V_29 & 0xffff0000 ) >> 16 ;
if ( V_34 ) {
V_2 -> V_34 = 1 ;
V_14 = F_33 ( V_2 ,
V_66 |
V_70 |
V_68 ) ;
if ( V_14 )
return V_14 ;
}
F_35 ( L_3
L_4 ,
V_2 -> V_32 , V_2 -> V_33 ) ;
return V_14 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_71 * V_71 )
{
int V_14 = 0 ;
int V_72 ;
const T_2 * V_73 ;
T_2 V_74 [ V_75 ] ;
V_14 = F_29 ( V_2 , 1 , 0 ) ;
if ( V_14 )
goto V_76;
V_72 = V_71 -> V_77 ;
V_73 = V_71 -> V_78 ;
while ( V_72 > 0 ) {
V_14 = F_16 ( V_2 , V_79 ,
V_75 ) ;
if ( V_14 )
goto V_76;
V_14 = F_24 ( V_2 , V_80 ,
V_81 ,
V_81 ) ;
if ( V_14 )
goto V_76;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memcpy ( V_74 , V_73 ,
F_37 ( V_72 , V_75 ) ) ;
F_28 ( 10 ) ;
V_14 = F_10 ( V_2 , V_27 ,
V_74 , V_75 ) ;
if ( V_14 )
goto V_76;
V_14 = F_16 ( V_2 , V_80 , 0 ) ;
if ( V_14 )
goto V_76;
V_14 = F_16 ( V_2 , V_82 ,
V_83 ) ;
if ( V_14 )
goto V_76;
V_72 -= V_75 ;
V_73 += V_75 ;
}
V_14 = F_16 ( V_2 , V_79 , V_84 ) ;
if ( V_14 )
goto V_76;
V_14 = F_16 ( V_2 , V_80 , 0 ) ;
if ( V_14 )
goto V_76;
V_14 = F_16 ( V_2 , V_82 ,
V_83 ) ;
V_76:
if ( V_14 )
F_26 ( L_5 , V_14 ) ;
return V_14 ;
}
static int F_38 ( struct V_1 * V_2 ,
int * V_85 )
{
T_1 V_13 ;
int V_14 = 0 ;
V_14 = F_24 ( V_2 , V_80 ,
V_81 ,
V_81 ) ;
if ( V_14 ) {
F_26 ( L_6 ) ;
return V_14 ;
}
V_14 = F_20 ( V_2 , V_79 , & V_13 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 > V_86 ) {
F_26 ( L_7 ,
V_13 ) ;
return - V_65 ;
}
if ( V_13 & 0x1 ) {
F_35 ( L_8 , V_42 ) ;
V_13 &= ~ 0x1 ;
* V_85 = 1 ;
} else
* V_85 = 0 ;
return V_13 ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_71 * V_71 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
int V_13 , V_89 ;
int V_90 , V_85 = 0 , V_14 = 0 ;
const T_2 * V_73 ;
T_1 V_91 ;
V_14 = F_29 ( V_2 , 1 , 0 ) ;
if ( V_14 )
goto V_76;
V_14 = F_24 ( V_2 , V_79 , 0 , 0 ) ;
if ( V_14 ) {
F_40 ( V_88 -> V_92 ,
L_9 ,
V_42 ) ;
goto V_76;
}
V_91 = 0 ;
V_89 = 0 ;
V_90 = V_71 -> V_77 ;
V_73 = V_71 -> V_78 ;
while ( ( V_13 = F_38 ( V_2 , & V_85 ) ) ) {
if ( V_13 < 0 ) {
V_14 = V_13 ;
goto V_76;
}
if ( V_90 < 0 ) {
F_40 ( V_88 -> V_92 ,
L_10 ) ;
break;
}
if ( V_85 ) {
if ( ++ V_91 > V_93 ) {
F_26 ( L_11 ) ;
V_14 = - V_65 ;
goto V_76;
}
} else {
V_90 -= V_89 ;
V_73 += V_89 ;
}
if ( V_90 < V_13 ) {
memset ( V_2 -> V_94 , 0 , V_13 ) ;
memcpy ( V_2 -> V_94 , V_73 , V_90 ) ;
} else
memcpy ( V_2 -> V_94 , V_73 , V_13 ) ;
V_14 = F_16 ( V_2 , V_80 , 0 ) ;
if ( V_14 )
goto V_76;
V_14 = F_10 ( V_2 , V_27 ,
V_2 -> V_94 , V_13 ) ;
if ( V_14 )
goto V_76;
V_14 = F_16 ( V_2 , V_82 ,
V_83 ) ;
if ( V_14 )
goto V_76;
V_89 = V_13 ;
}
if ( V_90 > V_89 ) {
F_26 ( L_12 ) ;
}
V_14 = F_27 ( V_2 , V_95 ,
V_96 ) ;
if ( V_14 ) {
F_26 ( L_13 ) ;
goto V_76;
}
V_76:
if ( V_14 )
F_26 ( L_14 , V_14 ) ;
return V_14 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
unsigned long V_97 ;
int V_14 = 0 ;
T_1 V_13 ;
T_2 V_98 ;
F_42 ( V_86 < V_99 ) ;
F_42 ( V_86 < V_100 ) ;
F_42 ( V_86 % 4 != 0 ) ;
V_14 = F_20 ( V_2 , V_101 , & V_13 ) ;
if ( V_14 )
goto V_76;
if ( ! V_13 ) {
F_40 ( V_88 -> V_92 , L_15 ,
V_42 ) ;
V_14 = - V_102 ;
goto V_76;
} else if ( V_13 > V_86 ) {
F_40 ( V_88 -> V_92 ,
L_16 ,
V_42 , V_13 , V_86 ) ;
V_14 = - V_102 ;
goto V_76;
}
V_14 = F_18 ( V_2 , V_27 ,
V_2 -> V_94 , F_43 ( V_13 , 4 ) ) ;
if ( V_14 )
goto V_76;
F_44 ( & V_88 -> V_103 , V_97 ) ;
V_98 = ( V_88 -> V_104 == 0 ) ? 1 : 0 ;
F_13 ( V_88 -> V_105 [ V_98 ] ) ;
V_88 -> V_105 [ V_98 ] = V_13 ;
memcpy ( V_88 -> V_106 [ V_98 ] , V_2 -> V_94 , V_13 ) ;
F_45 ( V_88 , V_98 ) ;
F_46 ( & V_88 -> V_103 , V_97 ) ;
V_76:
if ( V_14 )
F_40 ( V_88 -> V_92 , L_17 , V_42 , V_14 ) ;
return V_14 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
struct V_107 * V_108 ;
char * V_78 ;
T_1 V_13 ;
int V_14 = 0 ;
V_14 = F_20 ( V_2 , V_79 , & V_13 ) ;
if ( V_14 )
goto V_76;
if ( ! V_13 ) {
F_40 ( V_88 -> V_92 , L_15 ,
V_42 ) ;
V_14 = - V_102 ;
goto V_76;
} else if ( V_13 > V_109 ) {
F_40 ( V_88 -> V_92 ,
L_18 ,
V_42 , V_13 , V_109 ) ;
V_14 = - V_102 ;
goto V_76;
}
V_108 = F_48 ( V_109 ) ;
if ( ! V_108 ) {
V_14 = - V_110 ;
goto V_76;
}
F_49 ( V_108 , V_111 ) ;
V_78 = F_50 ( V_108 , V_13 ) ;
V_14 = F_18 ( V_2 , V_28 , V_78 , F_43 ( V_13 , 4 ) ) ;
if ( V_14 )
goto V_112;
V_14 = F_51 ( V_2 -> V_88 , V_108 ) ;
if ( V_14 )
goto V_112;
goto V_76;
V_112:
F_52 ( V_108 ) ;
V_76:
if ( V_14 )
F_40 ( V_88 -> V_92 , L_17 , V_42 , V_14 ) ;
return V_14 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int type )
{
struct V_87 * V_88 = V_2 -> V_88 ;
int V_14 = 0 ;
T_1 V_113 , V_114 ;
switch ( type ) {
case V_115 :
V_113 = V_116 ;
V_114 = V_28 ;
break;
case V_117 :
V_113 = V_83 ;
V_114 = V_27 ;
break;
default:
F_40 ( V_88 -> V_92 , L_19 ,
type ) ;
V_14 = - V_102 ;
goto V_76;
}
V_14 = F_10 ( V_2 , V_114 , V_7 -> V_118 , V_7 -> V_119 ) ;
if ( V_14 )
goto V_76;
V_76:
F_5 ( V_7 ) ;
if ( V_14 )
F_40 ( V_88 -> V_92 , L_20 , V_42 , V_14 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
T_4 V_120 ;
struct V_87 * V_88 = V_2 -> V_88 ;
V_14 = F_22 ( V_2 , V_121 , & V_120 ) ;
if ( V_14 )
goto V_76;
F_16 ( V_2 , V_80 ,
~ V_122 ) ;
F_16 ( V_2 , V_82 , V_123 ) ;
F_55 ( V_88 , V_120 & 0xff ) ;
V_76:
if ( V_14 )
F_40 ( V_88 -> V_92 , L_20 , V_42 , V_14 ) ;
}
static void F_56 ( struct V_124 * V_125 )
{
int V_14 ;
struct V_1 * V_2 ;
T_1 V_126 ;
unsigned long V_97 ;
struct V_6 * V_7 ;
struct V_87 * V_88 ;
V_2 = F_3 ( V_125 , struct V_1 , V_127 ) ;
V_88 = V_2 -> V_88 ;
V_14 = F_20 ( V_2 , V_80 ,
& V_126 ) ;
if ( V_14 ) {
F_40 ( V_88 -> V_92 , L_21 ) ;
goto V_14;
}
if ( V_126 & V_128 ) {
V_14 = F_41 ( V_2 ) ;
if ( V_14 )
goto V_14;
}
if ( V_126 & V_129 ) {
V_14 = F_47 ( V_2 ) ;
if ( V_14 )
goto V_14;
}
if ( V_126 & V_81 ||
( V_2 -> V_88 -> V_130 != V_131 &&
( V_126 & V_132 ) ) ) {
F_57 ( V_2 -> V_88 ) ;
V_7 = NULL ;
F_44 ( & V_2 -> V_133 , V_97 ) ;
if ( ! F_58 ( & V_2 -> V_134 ) ) {
V_7 = (struct V_6 * ) ( V_2 ->
V_134 . V_5 ) ;
F_4 ( & V_7 -> V_8 ) ;
}
F_46 ( & V_2 -> V_133 , V_97 ) ;
if ( V_7 )
F_53 ( V_2 , V_7 , V_117 ) ;
}
if ( V_126 & V_132 ) {
V_7 = NULL ;
F_44 ( & V_2 -> V_133 , V_97 ) ;
if ( ! F_58 ( & V_2 -> V_135 ) ) {
V_7 = (struct V_6 * ) ( V_2 ->
V_135 . V_5 ) ;
F_4 ( & V_7 -> V_8 ) ;
}
F_46 ( & V_2 -> V_133 , V_97 ) ;
if ( V_7 )
F_53 ( V_2 , V_7 , V_115 ) ;
}
if ( V_126 & V_136 )
F_54 ( V_2 ) ;
V_14:
if ( V_14 )
F_40 ( V_88 -> V_92 , L_22 , V_42 , V_14 ) ;
}
static int F_59 ( struct V_87 * V_88 ,
T_2 type , T_2 * V_12 , T_1 V_137 )
{
int V_14 = 0 ;
unsigned long V_97 ;
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_6 * V_7 ;
T_1 V_119 ;
if ( V_137 == 0 ) {
F_40 ( V_88 -> V_92 , L_23 ,
V_42 , V_137 ) ;
V_14 = - V_102 ;
goto V_76;
}
V_119 = F_43 ( V_137 , 4 ) ;
V_7 = F_60 ( sizeof( struct V_6 ) + V_119 , V_138 ) ;
if ( ! V_7 ) {
V_14 = - V_139 ;
goto V_76;
}
V_7 -> V_119 = V_119 ;
memcpy ( V_7 -> V_118 , V_12 , V_137 ) ;
memset ( V_7 -> V_118 + V_137 , 0 , V_119 - V_137 ) ;
switch ( type ) {
case V_117 :
V_88 -> V_140 = V_141 ;
F_44 ( & V_2 -> V_133 , V_97 ) ;
F_61 ( & V_7 -> V_8 , & V_2 -> V_134 ) ;
F_46 ( & V_2 -> V_133 , V_97 ) ;
break;
case V_115 :
V_88 -> V_140 = V_142 ;
F_44 ( & V_2 -> V_133 , V_97 ) ;
F_61 ( & V_7 -> V_8 , & V_2 -> V_135 ) ;
F_46 ( & V_2 -> V_133 , V_97 ) ;
break;
default:
F_5 ( V_7 ) ;
F_40 ( V_88 -> V_92 , L_19 ,
type ) ;
V_14 = - V_102 ;
break;
}
F_62 ( V_2 -> V_143 , & V_2 -> V_127 ) ;
V_76:
return V_14 ;
}
static T_6 F_63 ( int V_144 , void * V_145 )
{
struct V_1 * V_2 = V_145 ;
F_62 ( V_2 -> V_143 , & V_2 -> V_127 ) ;
return V_146 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
int V_14 , V_98 ;
T_4 V_147 ;
const struct V_71 * V_148 = NULL ;
const struct V_71 * V_149 = NULL ;
V_14 = F_34 ( V_2 , V_2 -> V_150 -> V_34 ) ;
if ( V_14 )
goto V_76;
V_14 = F_30 ( V_2 , & V_2 -> V_58 , & V_2 -> V_59 ) ;
if ( V_14 )
goto V_76;
V_14 = F_22 ( V_2 , V_95 , & V_147 ) ;
if ( V_14 )
goto V_76;
if ( V_147 == V_96 )
F_35 ( L_24
L_25 ) ;
else {
for ( V_98 = 0 ; V_98 < F_65 ( V_151 ) ; V_98 ++ ) {
if ( V_2 -> V_58 == V_151 [ V_98 ] . V_152 )
break;
}
if ( V_98 == F_65 ( V_151 ) ) {
F_40 ( V_88 -> V_92 , L_26 ,
V_2 -> V_58 ) ;
V_14 = - V_153 ;
goto V_76;
}
V_14 = F_66 ( & V_2 -> V_23 -> V_92 , V_2 -> V_58 ,
& V_151 [ 0 ] , & V_148 , & V_149 ) ;
if ( V_14 ) {
F_40 ( V_88 -> V_92 , L_27 ,
V_14 ) ;
goto V_76;
}
F_35 ( L_28
L_29
L_30
L_31 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_23 -> V_154 -> V_155 ,
V_2 -> V_23 -> V_156 ,
V_2 -> V_23 -> V_157 ) ;
V_14 = F_36 ( V_2 , V_148 ) ;
if ( V_14 )
goto V_76;
V_14 = F_39 ( V_2 , V_149 ) ;
if ( V_14 )
goto V_76;
F_35 ( L_32 ) ;
}
V_14 = F_29 ( V_2 , 0 , 1 ) ;
if ( V_14 )
goto V_76;
V_76:
return V_14 ;
}
static void F_67 ( struct V_124 * V_125 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_125 , struct V_1 , V_158 ) ;
if ( V_2 -> V_159 ) {
if ( V_2 -> V_150 -> V_160 )
V_2 -> V_150 -> V_160 ( V_2 -> V_23 ) ;
F_64 ( V_2 ) ;
F_68 ( V_2 -> V_23 -> V_144 ) ;
F_69 ( V_2 -> V_88 ) ;
V_2 -> V_159 = 0 ;
}
}
static int F_70 ( struct V_161 * V_23 )
{
struct V_1 * V_2 ;
struct V_87 * V_88 = NULL ;
struct V_162 * V_150 = F_71 ( & V_23 -> V_92 ) ;
int V_14 = 0 ;
if ( ! V_150 ) {
V_14 = - V_102 ;
goto V_76;
}
if ( V_150 -> V_160 ) {
V_14 = V_150 -> V_160 ( V_23 ) ;
if ( V_14 )
goto V_76;
}
V_2 = F_60 ( sizeof( struct V_1 ) , V_163 ) ;
if ( ! V_2 ) {
V_14 = - V_139 ;
goto V_164;
}
F_72 ( V_23 , V_2 ) ;
V_2 -> V_150 = V_150 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_10 = V_9 ;
F_73 ( & V_2 -> V_134 ) ;
F_73 ( & V_2 -> V_135 ) ;
F_74 ( & V_2 -> V_133 ) ;
V_14 = F_64 ( V_2 ) ;
if ( V_14 )
goto V_165;
V_88 = F_75 ( V_2 , & V_23 -> V_92 ) ;
if ( ! V_88 ) {
V_14 = - V_139 ;
goto V_165;
}
V_2 -> V_88 = V_88 ;
V_88 -> V_166 = 1 ;
V_88 -> V_2 = V_2 ;
V_88 -> V_167 = F_59 ;
V_88 -> V_168 = NULL ;
V_88 -> V_169 = NULL ;
V_88 -> V_170 = NULL ;
V_88 -> V_171 = 1 ;
V_2 -> V_143 = F_76 ( L_33 , V_172 , 0 ) ;
if ( ! V_2 -> V_143 ) {
V_14 = - V_139 ;
goto V_173;
}
F_77 ( & V_2 -> V_127 , F_56 ) ;
F_77 ( & V_2 -> V_158 , F_67 ) ;
V_14 = F_78 ( V_23 -> V_144 , F_63 ,
V_174 , L_33 , V_2 ) ;
if ( V_14 ) {
F_26 ( L_34 ) ;
goto V_175;
}
V_14 = F_79 ( V_88 ) ;
if ( V_14 )
goto V_176;
F_35 ( L_35 ) ;
goto V_76;
V_176:
F_80 ( V_23 -> V_144 , V_2 ) ;
V_175:
F_81 ( V_2 -> V_143 ) ;
V_173:
F_82 ( V_88 ) ;
V_165:
F_1 ( V_2 ) ;
V_164:
if ( V_150 -> V_164 )
V_150 -> V_164 ( V_23 ) ;
V_76:
return V_14 ;
}
static int F_83 ( struct V_161 * V_23 )
{
struct V_1 * V_2 = F_84 ( V_23 ) ;
struct V_87 * V_88 = V_2 -> V_88 ;
F_35 ( L_36 ) ;
F_85 ( & V_2 -> V_158 ) ;
F_86 ( V_88 ) ;
F_82 ( V_88 ) ;
F_80 ( V_23 -> V_144 , V_2 ) ;
F_81 ( V_2 -> V_143 ) ;
if ( V_2 -> V_150 -> V_164 )
V_2 -> V_150 -> V_164 ( V_23 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_177 * V_92 )
{
struct V_161 * V_23 = F_88 ( V_92 ) ;
struct V_1 * V_2 = F_84 ( V_23 ) ;
if ( ! V_2 -> V_159 ) {
F_89 ( V_2 -> V_88 ) ;
F_90 ( V_2 -> V_143 ) ;
F_91 ( V_23 -> V_144 ) ;
if ( V_2 -> V_150 -> V_164 )
V_2 -> V_150 -> V_164 ( V_23 ) ;
V_2 -> V_159 = 1 ;
}
return 0 ;
}
static int F_92 ( struct V_177 * V_92 )
{
struct V_161 * V_23 = F_88 ( V_92 ) ;
struct V_1 * V_2 = F_84 ( V_23 ) ;
F_93 ( & V_2 -> V_158 ) ;
return 0 ;
}
static int T_7 F_94 ( void )
{
int V_37 = 0 ;
F_95 ( V_178 L_37 ) ;
V_37 = F_96 ( & V_179 ) ;
return V_37 ;
}
static void T_8 F_97 ( void )
{
F_98 ( & V_179 ) ;
}
