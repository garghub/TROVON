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
F_6 ( V_2 -> V_9 , NULL ) ;
F_5 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! F_8 ( V_10 , V_2 -> V_11 + 1 ) ) {
F_9 ( 400 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_11 = V_10 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_12 , const T_2 * V_13 , int V_14 )
{
int V_15 = 0 ;
T_3 V_16 = F_12 ( V_12 | V_17 ) ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_20 V_22 ;
F_13 ( & V_19 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_14 ( V_14 & 0x1 ) ;
F_7 ( V_2 ) ;
V_21 . V_23 = & V_16 ;
V_21 . V_14 = sizeof( V_16 ) ;
V_22 . V_23 = V_13 ;
V_22 . V_14 = V_14 ;
F_15 ( & V_21 , & V_19 ) ;
F_15 ( & V_22 , & V_19 ) ;
V_15 = F_16 ( V_2 -> V_9 , & V_19 ) ;
F_10 ( V_2 ) ;
return V_15 ;
}
static inline int F_17 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_24 )
{
T_3 V_25 ;
V_25 = F_12 ( V_24 ) ;
return F_11 ( V_2 , V_12 , ( T_2 * ) & V_25 , sizeof( T_1 ) ) ;
}
static inline int F_18 ( T_1 V_12 )
{
switch ( V_12 ) {
case V_26 :
case V_27 :
case V_28 :
return 1 ;
default:
return 0 ;
}
}
static int F_19 ( struct V_1 * V_2 , T_1 V_12 , T_2 * V_13 , int V_14 )
{
unsigned int V_29 ;
int V_15 = 0 ;
T_3 V_16 = F_12 ( V_12 | V_30 ) ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_20 V_31 ;
struct V_20 V_22 ;
F_14 ( V_14 & 0x1 ) ;
F_7 ( V_2 ) ;
F_13 ( & V_19 ) ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_21 . V_23 = & V_16 ;
V_21 . V_14 = sizeof( V_16 ) ;
F_15 ( & V_21 , & V_19 ) ;
V_29 = F_18 ( V_12 ) ? V_2 -> V_32 :
V_2 -> V_33 ;
if ( V_2 -> V_34 ) {
V_31 . V_14 = V_29 / 8 ;
F_15 ( & V_31 , & V_19 ) ;
} else {
V_21 . V_35 =
F_20 ( ( 100 + ( V_29 * 10 ) ) , 1000 ) ;
}
V_22 . V_36 = V_13 ;
V_22 . V_14 = V_14 ;
F_15 ( & V_22 , & V_19 ) ;
V_15 = F_16 ( V_2 -> V_9 , & V_19 ) ;
F_10 ( V_2 ) ;
return V_15 ;
}
static inline int F_21 ( struct V_1 * V_2 , T_1 V_12 , T_1 * V_24 )
{
T_3 V_13 ;
int V_37 ;
V_37 = F_19 ( V_2 , V_12 , ( T_2 * ) & V_13 , sizeof( V_13 ) ) ;
if ( V_37 == 0 )
* V_24 = F_22 ( & V_13 ) ;
return V_37 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_12 , T_4 * V_24 )
{
T_5 V_13 ;
int V_15 ;
V_15 = F_19 ( V_2 , V_12 , ( T_2 * ) & V_13 , sizeof( V_13 ) ) ;
if ( ! V_15 )
* V_24 = F_24 ( & V_13 ) ;
return V_15 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_38 , T_1 V_39 )
{
int V_15 ;
unsigned long V_40 = V_10 + 5 * V_41 ;
while ( 1 ) {
T_1 V_24 ;
V_15 = F_21 ( V_2 , V_12 , & V_24 ) ;
if ( V_15 )
return V_15 ;
if ( V_38 ) {
if ( ( V_24 & V_38 ) == V_39 )
return 0 ;
} else {
if ( V_24 )
return 0 ;
}
F_26 ( 100 ) ;
if ( F_8 ( V_10 , V_40 ) ) {
F_27 ( L_1 ,
V_42 , V_24 , V_38 , V_39 ) ;
return - V_43 ;
}
}
}
static int F_28 ( struct V_1 * V_2 , T_4 V_12 , T_4 V_39 )
{
int V_15 , V_44 ;
for ( V_44 = 0 ; V_44 < 4 ; ++ V_44 ) {
T_4 V_24 = 0 ;
V_15 = F_23 ( V_2 , V_12 , & V_24 ) ;
if ( V_15 )
return V_15 ;
if ( V_24 == V_39 )
return 0 ;
F_29 ( 100 ) ;
}
return - V_43 ;
}
static int F_30 ( struct V_1 * V_2 ,
int V_45 ,
int V_46 )
{
int V_15 = 0 ;
if ( V_45 ) {
V_15 = F_17 ( V_2 , V_47 , 0 ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = F_17 ( V_2 , V_47 ,
V_48 |
V_49 |
V_50 |
V_51 |
V_52 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_46 ) {
V_15 = F_17 ( V_2 , V_53 ,
V_54 |
V_55 |
V_56 |
V_57 ) ;
if ( V_15 )
return V_15 ;
} else {
V_15 = F_17 ( V_2 , V_47 , 0 ) ;
if ( V_15 )
return V_15 ;
}
return V_15 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_1 * V_58 , T_2 * V_59 )
{
int V_15 = 0 ;
T_4 V_60 ;
V_15 = F_23 ( V_2 , V_61 , & V_60 ) ;
if ( V_15 )
return V_15 ;
* V_58 = F_32 ( V_60 ) ;
* V_59 = F_33 ( V_60 ) ;
return V_15 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_62 )
{
int V_15 = 0 ;
T_1 V_63 ;
V_15 = F_17 ( V_2 , V_64 , V_62 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_21 ( V_2 , V_64 , & V_63 ) ;
if ( V_15 )
return V_15 ;
if ( ( V_63 & 0xF ) != V_62 ) {
F_27 ( L_2 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_34 )
{
int V_15 = 0 ;
T_4 V_29 ;
V_2 -> V_34 = 0 ;
V_15 = F_34 ( V_2 ,
V_66 |
V_67 |
V_68 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_32 = 1000 ;
V_2 -> V_33 = 1000 ;
V_15 = F_23 ( V_2 , V_69 , & V_29 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_32 = V_29 & 0x0000ffff ;
V_2 -> V_33 = ( V_29 & 0xffff0000 ) >> 16 ;
if ( V_34 ) {
V_2 -> V_34 = 1 ;
V_15 = F_34 ( V_2 ,
V_66 |
V_70 |
V_68 ) ;
if ( V_15 )
return V_15 ;
}
F_36 ( L_3
L_4 ,
V_2 -> V_32 , V_2 -> V_33 ) ;
return V_15 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_71 * V_71 )
{
int V_15 = 0 ;
int V_72 ;
const T_2 * V_73 ;
T_2 V_74 [ V_75 ] ;
F_38 ( V_76 ) ;
V_15 = F_30 ( V_2 , 1 , 0 ) ;
if ( V_15 )
goto V_77;
V_72 = V_71 -> V_78 ;
V_73 = V_71 -> V_79 ;
while ( V_72 > 0 ) {
V_15 = F_17 ( V_2 , V_80 ,
V_75 ) ;
if ( V_15 )
goto V_77;
V_15 = F_25 ( V_2 , V_81 ,
V_82 ,
V_82 ) ;
if ( V_15 )
goto V_77;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memcpy ( V_74 , V_73 ,
F_39 ( V_72 , V_75 ) ) ;
F_29 ( 10 ) ;
V_15 = F_11 ( V_2 , V_27 ,
V_74 , V_75 ) ;
if ( V_15 )
goto V_77;
V_15 = F_17 ( V_2 , V_81 , 0 ) ;
if ( V_15 )
goto V_77;
V_15 = F_17 ( V_2 , V_83 ,
V_84 ) ;
if ( V_15 )
goto V_77;
V_72 -= V_75 ;
V_73 += V_75 ;
}
V_15 = F_17 ( V_2 , V_80 , V_85 ) ;
if ( V_15 )
goto V_77;
V_15 = F_17 ( V_2 , V_81 , 0 ) ;
if ( V_15 )
goto V_77;
V_15 = F_17 ( V_2 , V_83 ,
V_84 ) ;
goto V_77;
F_36 ( L_5 ) ;
V_77:
if ( V_15 )
F_27 ( L_6 , V_15 ) ;
F_40 ( V_76 , L_7 , V_15 ) ;
return V_15 ;
}
static int F_41 ( struct V_1 * V_2 ,
int * V_86 )
{
T_1 V_14 ;
int V_15 = 0 ;
V_15 = F_25 ( V_2 , V_81 ,
V_82 ,
V_82 ) ;
if ( V_15 ) {
F_27 ( L_8 ) ;
return V_15 ;
}
V_15 = F_21 ( V_2 , V_80 , & V_14 ) ;
if ( V_15 )
return V_15 ;
if ( V_14 > V_87 ) {
F_27 ( L_9 ,
V_14 ) ;
return - V_65 ;
}
if ( V_14 & 0x1 ) {
F_36 ( L_10 , V_42 ) ;
V_14 &= ~ 0x1 ;
* V_86 = 1 ;
} else
* V_86 = 0 ;
return V_14 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_71 * V_71 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
int V_14 , V_90 ;
int V_91 , V_86 = 0 , V_15 = 0 ;
const T_2 * V_73 ;
T_1 V_92 ;
F_38 ( V_76 ) ;
V_15 = F_30 ( V_2 , 1 , 0 ) ;
if ( V_15 )
goto V_77;
V_15 = F_25 ( V_2 , V_80 , 0 , 0 ) ;
if ( V_15 ) {
F_43 ( V_89 -> V_93 ,
L_11 ,
V_42 ) ;
goto V_77;
}
V_92 = 0 ;
V_90 = 0 ;
V_91 = V_71 -> V_78 ;
V_73 = V_71 -> V_79 ;
while ( ( V_14 = F_41 ( V_2 , & V_86 ) ) ) {
if ( V_14 < 0 ) {
V_15 = V_14 ;
goto V_77;
}
if ( V_91 < 0 ) {
F_43 ( V_89 -> V_93 ,
L_12 ) ;
break;
}
if ( V_86 ) {
if ( ++ V_92 > V_94 ) {
F_27 ( L_13 ) ;
V_15 = - V_65 ;
goto V_77;
}
} else {
V_91 -= V_90 ;
V_73 += V_90 ;
}
if ( V_91 < V_14 ) {
memset ( V_2 -> V_95 , 0 , V_14 ) ;
memcpy ( V_2 -> V_95 , V_73 , V_91 ) ;
} else
memcpy ( V_2 -> V_95 , V_73 , V_14 ) ;
V_15 = F_17 ( V_2 , V_81 , 0 ) ;
if ( V_15 )
goto V_77;
V_15 = F_11 ( V_2 , V_27 ,
V_2 -> V_95 , V_14 ) ;
if ( V_15 )
goto V_77;
V_15 = F_17 ( V_2 , V_83 ,
V_84 ) ;
if ( V_15 )
goto V_77;
V_90 = V_14 ;
}
if ( V_91 > V_90 ) {
F_27 ( L_14 ) ;
}
V_15 = F_28 ( V_2 , V_96 ,
V_97 ) ;
if ( V_15 ) {
F_27 ( L_15 ) ;
goto V_77;
}
V_77:
if ( V_15 )
F_27 ( L_16 , V_15 ) ;
F_40 ( V_76 , L_7 , V_15 ) ;
return V_15 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned long V_98 ;
int V_15 = 0 ;
T_1 V_14 ;
T_2 V_99 ;
F_45 ( V_87 < V_100 ) ;
F_45 ( V_87 < V_101 ) ;
F_45 ( V_87 % 4 != 0 ) ;
F_38 ( V_76 ) ;
V_15 = F_21 ( V_2 , V_102 , & V_14 ) ;
if ( V_15 )
goto V_77;
if ( ! V_14 ) {
F_43 ( V_89 -> V_93 , L_17 ,
V_42 ) ;
V_15 = - V_103 ;
goto V_77;
} else if ( V_14 > V_87 ) {
F_43 ( V_89 -> V_93 ,
L_18 ,
V_42 , V_14 , V_87 ) ;
V_15 = - V_103 ;
goto V_77;
}
V_15 = F_19 ( V_2 , V_27 ,
V_2 -> V_95 , F_46 ( V_14 , 4 ) ) ;
if ( V_15 )
goto V_77;
F_47 ( & V_89 -> V_104 , V_98 ) ;
V_99 = ( V_89 -> V_105 == 0 ) ? 1 : 0 ;
F_14 ( V_89 -> V_106 [ V_99 ] ) ;
V_89 -> V_106 [ V_99 ] = V_14 ;
memcpy ( V_89 -> V_107 [ V_99 ] , V_2 -> V_95 , V_14 ) ;
F_48 ( V_89 , V_99 ) ;
F_49 ( & V_89 -> V_104 , V_98 ) ;
V_77:
if ( V_15 )
F_43 ( V_89 -> V_93 , L_19 , V_42 , V_15 ) ;
F_50 ( V_76 ) ;
return V_15 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
struct V_108 * V_109 ;
char * V_79 ;
T_1 V_14 ;
int V_15 = 0 ;
F_38 ( V_76 ) ;
V_15 = F_21 ( V_2 , V_80 , & V_14 ) ;
if ( V_15 )
goto V_77;
if ( ! V_14 ) {
F_43 ( V_89 -> V_93 , L_17 ,
V_42 ) ;
V_15 = - V_103 ;
goto V_77;
} else if ( V_14 > V_110 ) {
F_43 ( V_89 -> V_93 ,
L_20 ,
V_42 , V_14 , V_110 ) ;
V_15 = - V_103 ;
goto V_77;
}
V_109 = F_52 ( V_110 ) ;
if ( ! V_109 ) {
V_15 = - V_111 ;
goto V_77;
}
F_53 ( V_109 , V_112 ) ;
V_79 = F_54 ( V_109 , V_14 ) ;
V_15 = F_19 ( V_2 , V_28 , V_79 , F_46 ( V_14 , 4 ) ) ;
if ( V_15 )
goto V_113;
V_15 = F_55 ( V_2 -> V_89 , V_109 ) ;
if ( V_15 )
goto V_113;
goto V_77;
V_113:
F_56 ( V_109 ) ;
V_77:
if ( V_15 )
F_43 ( V_89 -> V_93 , L_19 , V_42 , V_15 ) ;
F_50 ( V_76 ) ;
return V_15 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_6 * V_7 , int type )
{
struct V_88 * V_89 = V_2 -> V_89 ;
int V_15 = 0 ;
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
F_43 ( V_89 -> V_93 , L_21 ,
type ) ;
V_15 = - V_103 ;
goto V_77;
}
V_15 = F_11 ( V_2 , V_115 , V_7 -> V_119 , V_7 -> V_120 ) ;
if ( V_15 )
goto V_77;
V_77:
F_5 ( V_7 ) ;
if ( V_15 )
F_43 ( V_89 -> V_93 , L_22 , V_42 , V_15 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
T_4 V_121 ;
struct V_88 * V_89 = V_2 -> V_89 ;
V_15 = F_23 ( V_2 , V_122 , & V_121 ) ;
if ( V_15 )
goto V_77;
F_17 ( V_2 , V_81 ,
~ V_123 ) ;
F_17 ( V_2 , V_83 , V_124 ) ;
F_59 ( V_89 , V_121 & 0xff ) ;
V_77:
if ( V_15 )
F_43 ( V_89 -> V_93 , L_22 , V_42 , V_15 ) ;
}
static void F_60 ( struct V_125 * V_126 )
{
int V_15 ;
struct V_1 * V_2 ;
T_1 V_127 ;
unsigned long V_98 ;
struct V_6 * V_7 ;
struct V_88 * V_89 ;
V_2 = F_3 ( V_126 , struct V_1 , V_128 ) ;
V_89 = V_2 -> V_89 ;
F_38 ( V_76 ) ;
V_15 = F_21 ( V_2 , V_81 ,
& V_127 ) ;
if ( V_15 ) {
F_43 ( V_89 -> V_93 , L_23 ) ;
goto V_15;
}
if ( V_127 & V_129 ) {
V_15 = F_44 ( V_2 ) ;
if ( V_15 )
goto V_15;
}
if ( V_127 & V_130 ) {
V_15 = F_51 ( V_2 ) ;
if ( V_15 )
goto V_15;
}
if ( V_127 & V_82 ||
( V_2 -> V_89 -> V_131 != V_132 &&
( V_127 & V_133 ) ) ) {
F_61 ( V_2 -> V_89 ) ;
V_7 = NULL ;
F_47 ( & V_2 -> V_134 , V_98 ) ;
if ( ! F_62 ( & V_2 -> V_135 ) ) {
V_7 = (struct V_6 * ) ( V_2 ->
V_135 . V_5 ) ;
F_4 ( & V_7 -> V_8 ) ;
}
F_49 ( & V_2 -> V_134 , V_98 ) ;
if ( V_7 )
F_57 ( V_2 , V_7 , V_118 ) ;
}
if ( V_127 & V_133 ) {
V_7 = NULL ;
F_47 ( & V_2 -> V_134 , V_98 ) ;
if ( ! F_62 ( & V_2 -> V_136 ) ) {
V_7 = (struct V_6 * ) ( V_2 ->
V_136 . V_5 ) ;
F_4 ( & V_7 -> V_8 ) ;
}
F_49 ( & V_2 -> V_134 , V_98 ) ;
if ( V_7 )
F_57 ( V_2 , V_7 , V_116 ) ;
}
if ( V_127 & V_137 )
F_58 ( V_2 ) ;
V_15:
if ( V_15 )
F_43 ( V_89 -> V_93 , L_24 , V_42 , V_15 ) ;
F_50 ( V_76 ) ;
}
static int F_63 ( struct V_88 * V_89 ,
T_2 type , T_2 * V_13 , T_1 V_138 )
{
int V_15 = 0 ;
unsigned long V_98 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_6 * V_7 ;
T_1 V_120 ;
F_64 ( V_76 , L_25 , type , V_138 ) ;
if ( V_138 == 0 ) {
F_43 ( V_89 -> V_93 , L_26 ,
V_42 , V_138 ) ;
V_15 = - V_103 ;
goto V_77;
}
V_120 = F_46 ( V_138 , 4 ) ;
V_7 = F_65 ( sizeof( struct V_6 ) + V_120 , V_139 ) ;
if ( ! V_7 ) {
V_15 = - V_140 ;
goto V_77;
}
V_7 -> V_120 = V_120 ;
memcpy ( V_7 -> V_119 , V_13 , V_138 ) ;
memset ( V_7 -> V_119 + V_138 , 0 , V_120 - V_138 ) ;
switch ( type ) {
case V_118 :
V_89 -> V_141 = V_142 ;
F_47 ( & V_2 -> V_134 , V_98 ) ;
F_66 ( & V_7 -> V_8 , & V_2 -> V_135 ) ;
F_49 ( & V_2 -> V_134 , V_98 ) ;
break;
case V_116 :
V_89 -> V_141 = V_143 ;
F_47 ( & V_2 -> V_134 , V_98 ) ;
F_66 ( & V_7 -> V_8 , & V_2 -> V_136 ) ;
F_49 ( & V_2 -> V_134 , V_98 ) ;
break;
default:
F_43 ( V_89 -> V_93 , L_21 ,
type ) ;
V_15 = - V_103 ;
break;
}
F_67 ( V_2 -> V_144 , & V_2 -> V_128 ) ;
V_77:
F_40 ( V_76 , L_27 , V_15 ) ;
return V_15 ;
}
static T_6 F_68 ( int V_145 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
F_67 ( V_2 -> V_144 , & V_2 -> V_128 ) ;
return V_147 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
struct V_148 * V_9 = V_2 -> V_9 ;
int V_15 , V_99 ;
T_4 V_149 ;
const struct V_71 * V_150 = NULL ;
const struct V_71 * V_151 = NULL ;
F_38 ( V_76 ) ;
V_15 = F_35 ( V_2 , V_2 -> V_152 -> V_34 ) ;
if ( V_15 )
goto V_77;
V_15 = F_31 ( V_2 , & V_2 -> V_58 , & V_2 -> V_59 ) ;
if ( V_15 )
goto V_77;
V_15 = F_23 ( V_2 , V_96 , & V_149 ) ;
if ( V_15 )
goto V_77;
if ( V_149 == V_97 )
F_36 ( L_28
L_29 ) ;
else {
for ( V_99 = 0 ; V_99 < F_70 ( V_153 ) ; V_99 ++ ) {
if ( V_2 -> V_58 == V_153 [ V_99 ] . V_154 )
break;
}
if ( V_99 == F_70 ( V_153 ) ) {
F_43 ( V_89 -> V_93 , L_30 ,
V_2 -> V_58 ) ;
V_15 = - V_155 ;
goto V_77;
}
V_15 = F_71 ( & V_2 -> V_9 -> V_93 , NULL , NULL ,
V_2 -> V_58 , & V_153 [ 0 ] , & V_150 ,
& V_151 ) ;
if ( V_15 ) {
F_43 ( V_89 -> V_93 , L_31 ,
V_15 ) ;
goto V_77;
}
F_36 ( L_32
L_33
L_34
L_35 ,
V_2 -> V_58 , V_2 -> V_59 ,
V_9 -> V_156 -> V_157 , V_9 -> V_158 ,
V_9 -> V_159 ) ;
V_15 = F_37 ( V_2 , V_150 ) ;
if ( V_15 )
goto V_77;
V_15 = F_42 ( V_2 , V_151 ) ;
if ( V_15 )
goto V_77;
F_36 ( L_36 ) ;
}
V_15 = F_30 ( V_2 , 0 , 1 ) ;
if ( V_15 )
goto V_77;
V_77:
if ( V_150 )
F_72 ( V_150 ) ;
if ( V_151 )
F_72 ( V_151 ) ;
F_40 ( V_76 , L_37 , V_15 ) ;
return V_15 ;
}
static void F_73 ( struct V_125 * V_126 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_126 , struct V_1 , V_160 ) ;
if ( V_2 -> V_161 ) {
if ( V_2 -> V_152 -> V_162 )
V_2 -> V_152 -> V_162 ( V_2 -> V_9 ) ;
F_69 ( V_2 ) ;
F_74 ( V_2 -> V_9 -> V_145 ) ;
F_75 ( V_2 -> V_89 ) ;
V_2 -> V_161 = 0 ;
}
}
static int T_7 F_76 ( struct V_148 * V_9 )
{
struct V_1 * V_2 ;
struct V_88 * V_89 = NULL ;
struct V_163 * V_152 = V_9 -> V_93 . V_164 ;
int V_15 = 0 ;
F_38 ( V_76 ) ;
if ( ! V_152 ) {
V_15 = - V_103 ;
goto V_77;
}
if ( V_152 -> V_162 ) {
V_15 = V_152 -> V_162 ( V_9 ) ;
if ( V_15 )
goto V_77;
}
V_2 = F_65 ( sizeof( struct V_1 ) , V_165 ) ;
if ( ! V_2 ) {
V_15 = - V_140 ;
goto V_166;
}
F_6 ( V_9 , V_2 ) ;
V_2 -> V_152 = V_152 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_11 = V_10 ;
F_77 ( & V_2 -> V_135 ) ;
F_77 ( & V_2 -> V_136 ) ;
F_78 ( & V_2 -> V_134 ) ;
V_15 = F_69 ( V_2 ) ;
if ( V_15 )
goto V_167;
V_89 = F_79 ( V_2 , & V_9 -> V_93 ) ;
if ( ! V_89 ) {
V_15 = - V_140 ;
goto V_167;
}
V_2 -> V_89 = V_89 ;
V_89 -> V_168 = 1 ;
V_89 -> V_2 = V_2 ;
V_89 -> V_169 = F_63 ;
V_89 -> V_170 = NULL ;
V_89 -> V_171 = NULL ;
V_89 -> V_172 = NULL ;
V_89 -> V_173 = 1 ;
V_2 -> V_144 = F_80 ( L_38 ) ;
F_81 ( & V_2 -> V_128 , F_60 ) ;
F_81 ( & V_2 -> V_160 , F_73 ) ;
V_15 = F_82 ( V_9 -> V_145 , F_68 ,
V_174 , L_38 , V_2 ) ;
if ( V_15 ) {
F_27 ( L_39 ) ;
goto V_175;
}
V_15 = F_83 ( V_89 ) ;
if ( V_15 )
goto V_176;
F_36 ( L_40 ) ;
goto V_77;
V_176:
F_84 ( V_9 -> V_145 , V_2 ) ;
V_175:
F_85 ( V_2 -> V_144 ) ;
F_86 ( V_2 -> V_144 ) ;
F_87 ( V_89 ) ;
V_167:
F_1 ( V_2 ) ;
V_166:
if ( V_152 -> V_166 )
V_152 -> V_166 ( V_9 ) ;
V_77:
F_40 ( V_76 , L_37 , V_15 ) ;
return V_15 ;
}
static int T_8 F_88 ( struct V_148 * V_9 )
{
struct V_1 * V_2 = F_89 ( V_9 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
F_36 ( L_41 ) ;
F_38 ( V_76 ) ;
F_90 ( & V_2 -> V_160 ) ;
F_91 ( V_89 ) ;
F_87 ( V_89 ) ;
F_84 ( V_9 -> V_145 , V_2 ) ;
F_85 ( V_2 -> V_144 ) ;
F_86 ( V_2 -> V_144 ) ;
if ( V_2 -> V_152 -> V_166 )
V_2 -> V_152 -> V_166 ( V_9 ) ;
F_1 ( V_2 ) ;
F_50 ( V_76 ) ;
return 0 ;
}
static int F_92 ( struct V_177 * V_93 )
{
struct V_148 * V_9 = F_93 ( V_93 ) ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
if ( ! V_2 -> V_161 ) {
F_94 ( V_2 -> V_89 ) ;
F_85 ( V_2 -> V_144 ) ;
F_95 ( V_9 -> V_145 ) ;
if ( V_2 -> V_152 -> V_166 )
V_2 -> V_152 -> V_166 ( V_9 ) ;
V_2 -> V_161 = 1 ;
}
return 0 ;
}
static int F_96 ( struct V_177 * V_93 )
{
struct V_148 * V_9 = F_93 ( V_93 ) ;
struct V_1 * V_2 = F_89 ( V_9 ) ;
F_97 ( & V_2 -> V_160 ) ;
return 0 ;
}
static int T_9 F_98 ( void )
{
int V_37 = 0 ;
F_38 ( V_76 ) ;
F_99 ( V_178 L_42 ) ;
V_37 = F_100 ( & V_179 ) ;
F_50 ( V_76 ) ;
return V_37 ;
}
static void T_10 F_101 ( void )
{
F_38 ( V_76 ) ;
F_102 ( & V_179 ) ;
F_50 ( V_76 ) ;
}
