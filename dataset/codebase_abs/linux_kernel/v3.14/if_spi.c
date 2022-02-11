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
F_37 ( V_76 ) ;
V_14 = F_29 ( V_2 , 1 , 0 ) ;
if ( V_14 )
goto V_77;
V_72 = V_71 -> V_78 ;
V_73 = V_71 -> V_79 ;
while ( V_72 > 0 ) {
V_14 = F_16 ( V_2 , V_80 ,
V_75 ) ;
if ( V_14 )
goto V_77;
V_14 = F_24 ( V_2 , V_81 ,
V_82 ,
V_82 ) ;
if ( V_14 )
goto V_77;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memcpy ( V_74 , V_73 ,
F_38 ( V_72 , V_75 ) ) ;
F_28 ( 10 ) ;
V_14 = F_10 ( V_2 , V_27 ,
V_74 , V_75 ) ;
if ( V_14 )
goto V_77;
V_14 = F_16 ( V_2 , V_81 , 0 ) ;
if ( V_14 )
goto V_77;
V_14 = F_16 ( V_2 , V_83 ,
V_84 ) ;
if ( V_14 )
goto V_77;
V_72 -= V_75 ;
V_73 += V_75 ;
}
V_14 = F_16 ( V_2 , V_80 , V_85 ) ;
if ( V_14 )
goto V_77;
V_14 = F_16 ( V_2 , V_81 , 0 ) ;
if ( V_14 )
goto V_77;
V_14 = F_16 ( V_2 , V_83 ,
V_84 ) ;
V_77:
if ( V_14 )
F_26 ( L_5 , V_14 ) ;
F_39 ( V_76 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_40 ( struct V_1 * V_2 ,
int * V_86 )
{
T_1 V_13 ;
int V_14 = 0 ;
V_14 = F_24 ( V_2 , V_81 ,
V_82 ,
V_82 ) ;
if ( V_14 ) {
F_26 ( L_7 ) ;
return V_14 ;
}
V_14 = F_20 ( V_2 , V_80 , & V_13 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 > V_87 ) {
F_26 ( L_8 ,
V_13 ) ;
return - V_65 ;
}
if ( V_13 & 0x1 ) {
F_35 ( L_9 , V_42 ) ;
V_13 &= ~ 0x1 ;
* V_86 = 1 ;
} else
* V_86 = 0 ;
return V_13 ;
}
static int F_41 ( struct V_1 * V_2 ,
const struct V_71 * V_71 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
int V_13 , V_90 ;
int V_91 , V_86 = 0 , V_14 = 0 ;
const T_2 * V_73 ;
T_1 V_92 ;
F_37 ( V_76 ) ;
V_14 = F_29 ( V_2 , 1 , 0 ) ;
if ( V_14 )
goto V_77;
V_14 = F_24 ( V_2 , V_80 , 0 , 0 ) ;
if ( V_14 ) {
F_42 ( V_89 -> V_93 ,
L_10 ,
V_42 ) ;
goto V_77;
}
V_92 = 0 ;
V_90 = 0 ;
V_91 = V_71 -> V_78 ;
V_73 = V_71 -> V_79 ;
while ( ( V_13 = F_40 ( V_2 , & V_86 ) ) ) {
if ( V_13 < 0 ) {
V_14 = V_13 ;
goto V_77;
}
if ( V_91 < 0 ) {
F_42 ( V_89 -> V_93 ,
L_11 ) ;
break;
}
if ( V_86 ) {
if ( ++ V_92 > V_94 ) {
F_26 ( L_12 ) ;
V_14 = - V_65 ;
goto V_77;
}
} else {
V_91 -= V_90 ;
V_73 += V_90 ;
}
if ( V_91 < V_13 ) {
memset ( V_2 -> V_95 , 0 , V_13 ) ;
memcpy ( V_2 -> V_95 , V_73 , V_91 ) ;
} else
memcpy ( V_2 -> V_95 , V_73 , V_13 ) ;
V_14 = F_16 ( V_2 , V_81 , 0 ) ;
if ( V_14 )
goto V_77;
V_14 = F_10 ( V_2 , V_27 ,
V_2 -> V_95 , V_13 ) ;
if ( V_14 )
goto V_77;
V_14 = F_16 ( V_2 , V_83 ,
V_84 ) ;
if ( V_14 )
goto V_77;
V_90 = V_13 ;
}
if ( V_91 > V_90 ) {
F_26 ( L_13 ) ;
}
V_14 = F_27 ( V_2 , V_96 ,
V_97 ) ;
if ( V_14 ) {
F_26 ( L_14 ) ;
goto V_77;
}
V_77:
if ( V_14 )
F_26 ( L_15 , V_14 ) ;
F_39 ( V_76 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned long V_98 ;
int V_14 = 0 ;
T_1 V_13 ;
T_2 V_99 ;
F_44 ( V_87 < V_100 ) ;
F_44 ( V_87 < V_101 ) ;
F_44 ( V_87 % 4 != 0 ) ;
F_37 ( V_76 ) ;
V_14 = F_20 ( V_2 , V_102 , & V_13 ) ;
if ( V_14 )
goto V_77;
if ( ! V_13 ) {
F_42 ( V_89 -> V_93 , L_16 ,
V_42 ) ;
V_14 = - V_103 ;
goto V_77;
} else if ( V_13 > V_87 ) {
F_42 ( V_89 -> V_93 ,
L_17 ,
V_42 , V_13 , V_87 ) ;
V_14 = - V_103 ;
goto V_77;
}
V_14 = F_18 ( V_2 , V_27 ,
V_2 -> V_95 , F_45 ( V_13 , 4 ) ) ;
if ( V_14 )
goto V_77;
F_46 ( & V_89 -> V_104 , V_98 ) ;
V_99 = ( V_89 -> V_105 == 0 ) ? 1 : 0 ;
F_13 ( V_89 -> V_106 [ V_99 ] ) ;
V_89 -> V_106 [ V_99 ] = V_13 ;
memcpy ( V_89 -> V_107 [ V_99 ] , V_2 -> V_95 , V_13 ) ;
F_47 ( V_89 , V_99 ) ;
F_48 ( & V_89 -> V_104 , V_98 ) ;
V_77:
if ( V_14 )
F_42 ( V_89 -> V_93 , L_18 , V_42 , V_14 ) ;
F_49 ( V_76 ) ;
return V_14 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
struct V_108 * V_109 ;
char * V_79 ;
T_1 V_13 ;
int V_14 = 0 ;
F_37 ( V_76 ) ;
V_14 = F_20 ( V_2 , V_80 , & V_13 ) ;
if ( V_14 )
goto V_77;
if ( ! V_13 ) {
F_42 ( V_89 -> V_93 , L_16 ,
V_42 ) ;
V_14 = - V_103 ;
goto V_77;
} else if ( V_13 > V_110 ) {
F_42 ( V_89 -> V_93 ,
L_19 ,
V_42 , V_13 , V_110 ) ;
V_14 = - V_103 ;
goto V_77;
}
V_109 = F_51 ( V_110 ) ;
if ( ! V_109 ) {
V_14 = - V_111 ;
goto V_77;
}
F_52 ( V_109 , V_112 ) ;
V_79 = F_53 ( V_109 , V_13 ) ;
V_14 = F_18 ( V_2 , V_28 , V_79 , F_45 ( V_13 , 4 ) ) ;
if ( V_14 )
goto V_113;
V_14 = F_54 ( V_2 -> V_89 , V_109 ) ;
if ( V_14 )
goto V_113;
goto V_77;
V_113:
F_55 ( V_109 ) ;
V_77:
if ( V_14 )
F_42 ( V_89 -> V_93 , L_18 , V_42 , V_14 ) ;
F_49 ( V_76 ) ;
return V_14 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int type )
{
struct V_88 * V_89 = V_2 -> V_89 ;
int V_14 = 0 ;
T_1 V_114 , V_115 ;
switch ( type ) {
case V_116 :
V_114 = V_117 ;
V_115 = V_28 ;
break;
case V_118 :
V_114 = V_84 ;
V_115 = V_27 ;
break;
default:
F_42 ( V_89 -> V_93 , L_20 ,
type ) ;
V_14 = - V_103 ;
goto V_77;
}
V_14 = F_10 ( V_2 , V_115 , V_7 -> V_119 , V_7 -> V_120 ) ;
if ( V_14 )
goto V_77;
V_77:
F_5 ( V_7 ) ;
if ( V_14 )
F_42 ( V_89 -> V_93 , L_21 , V_42 , V_14 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
T_4 V_121 ;
struct V_88 * V_89 = V_2 -> V_89 ;
V_14 = F_22 ( V_2 , V_122 , & V_121 ) ;
if ( V_14 )
goto V_77;
F_16 ( V_2 , V_81 ,
~ V_123 ) ;
F_16 ( V_2 , V_83 , V_124 ) ;
F_58 ( V_89 , V_121 & 0xff ) ;
V_77:
if ( V_14 )
F_42 ( V_89 -> V_93 , L_21 , V_42 , V_14 ) ;
}
static void F_59 ( struct V_125 * V_126 )
{
int V_14 ;
struct V_1 * V_2 ;
T_1 V_127 ;
unsigned long V_98 ;
struct V_6 * V_7 ;
struct V_88 * V_89 ;
V_2 = F_3 ( V_126 , struct V_1 , V_128 ) ;
V_89 = V_2 -> V_89 ;
F_37 ( V_76 ) ;
V_14 = F_20 ( V_2 , V_81 ,
& V_127 ) ;
if ( V_14 ) {
F_42 ( V_89 -> V_93 , L_22 ) ;
goto V_14;
}
if ( V_127 & V_129 ) {
V_14 = F_43 ( V_2 ) ;
if ( V_14 )
goto V_14;
}
if ( V_127 & V_130 ) {
V_14 = F_50 ( V_2 ) ;
if ( V_14 )
goto V_14;
}
if ( V_127 & V_82 ||
( V_2 -> V_89 -> V_131 != V_132 &&
( V_127 & V_133 ) ) ) {
F_60 ( V_2 -> V_89 ) ;
V_7 = NULL ;
F_46 ( & V_2 -> V_134 , V_98 ) ;
if ( ! F_61 ( & V_2 -> V_135 ) ) {
V_7 = (struct V_6 * ) ( V_2 ->
V_135 . V_5 ) ;
F_4 ( & V_7 -> V_8 ) ;
}
F_48 ( & V_2 -> V_134 , V_98 ) ;
if ( V_7 )
F_56 ( V_2 , V_7 , V_118 ) ;
}
if ( V_127 & V_133 ) {
V_7 = NULL ;
F_46 ( & V_2 -> V_134 , V_98 ) ;
if ( ! F_61 ( & V_2 -> V_136 ) ) {
V_7 = (struct V_6 * ) ( V_2 ->
V_136 . V_5 ) ;
F_4 ( & V_7 -> V_8 ) ;
}
F_48 ( & V_2 -> V_134 , V_98 ) ;
if ( V_7 )
F_56 ( V_2 , V_7 , V_116 ) ;
}
if ( V_127 & V_137 )
F_57 ( V_2 ) ;
V_14:
if ( V_14 )
F_42 ( V_89 -> V_93 , L_23 , V_42 , V_14 ) ;
F_49 ( V_76 ) ;
}
static int F_62 ( struct V_88 * V_89 ,
T_2 type , T_2 * V_12 , T_1 V_138 )
{
int V_14 = 0 ;
unsigned long V_98 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_6 * V_7 ;
T_1 V_120 ;
F_63 ( V_76 , L_24 , type , V_138 ) ;
if ( V_138 == 0 ) {
F_42 ( V_89 -> V_93 , L_25 ,
V_42 , V_138 ) ;
V_14 = - V_103 ;
goto V_77;
}
V_120 = F_45 ( V_138 , 4 ) ;
V_7 = F_64 ( sizeof( struct V_6 ) + V_120 , V_139 ) ;
if ( ! V_7 ) {
V_14 = - V_140 ;
goto V_77;
}
V_7 -> V_120 = V_120 ;
memcpy ( V_7 -> V_119 , V_12 , V_138 ) ;
memset ( V_7 -> V_119 + V_138 , 0 , V_120 - V_138 ) ;
switch ( type ) {
case V_118 :
V_89 -> V_141 = V_142 ;
F_46 ( & V_2 -> V_134 , V_98 ) ;
F_65 ( & V_7 -> V_8 , & V_2 -> V_135 ) ;
F_48 ( & V_2 -> V_134 , V_98 ) ;
break;
case V_116 :
V_89 -> V_141 = V_143 ;
F_46 ( & V_2 -> V_134 , V_98 ) ;
F_65 ( & V_7 -> V_8 , & V_2 -> V_136 ) ;
F_48 ( & V_2 -> V_134 , V_98 ) ;
break;
default:
F_5 ( V_7 ) ;
F_42 ( V_89 -> V_93 , L_20 ,
type ) ;
V_14 = - V_103 ;
break;
}
F_66 ( V_2 -> V_144 , & V_2 -> V_128 ) ;
V_77:
F_39 ( V_76 , L_26 , V_14 ) ;
return V_14 ;
}
static T_6 F_67 ( int V_145 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
F_66 ( V_2 -> V_144 , & V_2 -> V_128 ) ;
return V_147 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
int V_14 , V_99 ;
T_4 V_148 ;
const struct V_71 * V_149 = NULL ;
const struct V_71 * V_150 = NULL ;
F_37 ( V_76 ) ;
V_14 = F_34 ( V_2 , V_2 -> V_151 -> V_34 ) ;
if ( V_14 )
goto V_77;
V_14 = F_30 ( V_2 , & V_2 -> V_58 , & V_2 -> V_59 ) ;
if ( V_14 )
goto V_77;
V_14 = F_22 ( V_2 , V_96 , & V_148 ) ;
if ( V_14 )
goto V_77;
if ( V_148 == V_97 )
F_35 ( L_27
L_28 ) ;
else {
for ( V_99 = 0 ; V_99 < F_69 ( V_152 ) ; V_99 ++ ) {
if ( V_2 -> V_58 == V_152 [ V_99 ] . V_153 )
break;
}
if ( V_99 == F_69 ( V_152 ) ) {
F_42 ( V_89 -> V_93 , L_29 ,
V_2 -> V_58 ) ;
V_14 = - V_154 ;
goto V_77;
}
V_14 = F_70 ( & V_2 -> V_23 -> V_93 , V_2 -> V_58 ,
& V_152 [ 0 ] , & V_149 , & V_150 ) ;
if ( V_14 ) {
F_42 ( V_89 -> V_93 , L_30 ,
V_14 ) ;
goto V_77;
}
F_35 ( L_31
L_32
L_33
L_34 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_23 -> V_155 -> V_156 ,
V_2 -> V_23 -> V_157 ,
V_2 -> V_23 -> V_158 ) ;
V_14 = F_36 ( V_2 , V_149 ) ;
if ( V_14 )
goto V_77;
V_14 = F_41 ( V_2 , V_150 ) ;
if ( V_14 )
goto V_77;
F_35 ( L_35 ) ;
}
V_14 = F_29 ( V_2 , 0 , 1 ) ;
if ( V_14 )
goto V_77;
V_77:
F_39 ( V_76 , L_36 , V_14 ) ;
return V_14 ;
}
static void F_71 ( struct V_125 * V_126 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_126 , struct V_1 , V_159 ) ;
if ( V_2 -> V_160 ) {
if ( V_2 -> V_151 -> V_161 )
V_2 -> V_151 -> V_161 ( V_2 -> V_23 ) ;
F_68 ( V_2 ) ;
F_72 ( V_2 -> V_23 -> V_145 ) ;
F_73 ( V_2 -> V_89 ) ;
V_2 -> V_160 = 0 ;
}
}
static int F_74 ( struct V_162 * V_23 )
{
struct V_1 * V_2 ;
struct V_88 * V_89 = NULL ;
struct V_163 * V_151 = F_75 ( & V_23 -> V_93 ) ;
int V_14 = 0 ;
F_37 ( V_76 ) ;
if ( ! V_151 ) {
V_14 = - V_103 ;
goto V_77;
}
if ( V_151 -> V_161 ) {
V_14 = V_151 -> V_161 ( V_23 ) ;
if ( V_14 )
goto V_77;
}
V_2 = F_64 ( sizeof( struct V_1 ) , V_164 ) ;
if ( ! V_2 ) {
V_14 = - V_140 ;
goto V_165;
}
F_76 ( V_23 , V_2 ) ;
V_2 -> V_151 = V_151 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_10 = V_9 ;
F_77 ( & V_2 -> V_135 ) ;
F_77 ( & V_2 -> V_136 ) ;
F_78 ( & V_2 -> V_134 ) ;
V_14 = F_68 ( V_2 ) ;
if ( V_14 )
goto V_166;
V_89 = F_79 ( V_2 , & V_23 -> V_93 ) ;
if ( ! V_89 ) {
V_14 = - V_140 ;
goto V_166;
}
V_2 -> V_89 = V_89 ;
V_89 -> V_167 = 1 ;
V_89 -> V_2 = V_2 ;
V_89 -> V_168 = F_62 ;
V_89 -> V_169 = NULL ;
V_89 -> V_170 = NULL ;
V_89 -> V_171 = NULL ;
V_89 -> V_172 = 1 ;
V_2 -> V_144 = F_80 ( L_37 ) ;
F_81 ( & V_2 -> V_128 , F_59 ) ;
F_81 ( & V_2 -> V_159 , F_71 ) ;
V_14 = F_82 ( V_23 -> V_145 , F_67 ,
V_173 , L_37 , V_2 ) ;
if ( V_14 ) {
F_26 ( L_38 ) ;
goto V_174;
}
V_14 = F_83 ( V_89 ) ;
if ( V_14 )
goto V_175;
F_35 ( L_39 ) ;
goto V_77;
V_175:
F_84 ( V_23 -> V_145 , V_2 ) ;
V_174:
F_85 ( V_2 -> V_144 ) ;
F_86 ( V_2 -> V_144 ) ;
F_87 ( V_89 ) ;
V_166:
F_1 ( V_2 ) ;
V_165:
if ( V_151 -> V_165 )
V_151 -> V_165 ( V_23 ) ;
V_77:
F_39 ( V_76 , L_36 , V_14 ) ;
return V_14 ;
}
static int F_88 ( struct V_162 * V_23 )
{
struct V_1 * V_2 = F_89 ( V_23 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
F_35 ( L_40 ) ;
F_37 ( V_76 ) ;
F_90 ( & V_2 -> V_159 ) ;
F_91 ( V_89 ) ;
F_87 ( V_89 ) ;
F_84 ( V_23 -> V_145 , V_2 ) ;
F_85 ( V_2 -> V_144 ) ;
F_86 ( V_2 -> V_144 ) ;
if ( V_2 -> V_151 -> V_165 )
V_2 -> V_151 -> V_165 ( V_23 ) ;
F_1 ( V_2 ) ;
F_49 ( V_76 ) ;
return 0 ;
}
static int F_92 ( struct V_176 * V_93 )
{
struct V_162 * V_23 = F_93 ( V_93 ) ;
struct V_1 * V_2 = F_89 ( V_23 ) ;
if ( ! V_2 -> V_160 ) {
F_94 ( V_2 -> V_89 ) ;
F_85 ( V_2 -> V_144 ) ;
F_95 ( V_23 -> V_145 ) ;
if ( V_2 -> V_151 -> V_165 )
V_2 -> V_151 -> V_165 ( V_23 ) ;
V_2 -> V_160 = 1 ;
}
return 0 ;
}
static int F_96 ( struct V_176 * V_93 )
{
struct V_162 * V_23 = F_93 ( V_93 ) ;
struct V_1 * V_2 = F_89 ( V_23 ) ;
F_97 ( & V_2 -> V_159 ) ;
return 0 ;
}
static int T_7 F_98 ( void )
{
int V_37 = 0 ;
F_37 ( V_76 ) ;
F_99 ( V_177 L_41 ) ;
V_37 = F_100 ( & V_178 ) ;
F_49 ( V_76 ) ;
return V_37 ;
}
static void T_8 F_101 ( void )
{
F_37 ( V_76 ) ;
F_102 ( & V_178 ) ;
F_49 ( V_76 ) ;
}
