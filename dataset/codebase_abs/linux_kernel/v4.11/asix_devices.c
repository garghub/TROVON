static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
if ( V_3 -> V_7 < 8 )
return;
V_5 = V_3 -> V_8 ;
V_6 = V_5 -> V_6 & 0x01 ;
if ( F_2 ( V_2 -> V_9 ) != V_6 ) {
F_3 ( V_2 , V_6 , 1 ) ;
F_4 ( V_2 -> V_9 , L_1 , V_6 ) ;
}
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_10 )
{
if ( F_6 ( V_10 ) ) {
memcpy ( V_2 -> V_9 -> V_11 , V_10 , V_12 ) ;
} else {
F_7 ( V_2 -> V_9 , L_2 ) ;
F_8 ( V_2 -> V_9 ) ;
}
}
static T_2 F_9 ( struct V_1 * V_2 )
{
int V_13 ;
T_2 V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 100 ; V_15 ++ ) {
V_13 = F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_17 ) ;
if ( V_13 < 0 )
return 0 ;
if ( V_13 != 0 && V_13 != 0xFFFF )
break;
F_11 ( 1 ) ;
}
if ( V_13 <= 0 || V_13 == 0xFFFF )
return 0 ;
V_14 = ( V_13 & 0xffff ) << 16 ;
V_13 = F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_18 ) ;
if ( V_13 < 0 )
return 0 ;
V_14 |= ( V_13 & 0xffff ) ;
return V_14 ;
}
static T_2 F_12 ( struct V_19 * V_9 )
{
struct V_1 * V_2 = F_13 ( V_9 ) ;
return F_14 ( & V_2 -> V_16 ) ;
}
static int F_15 ( struct V_19 * V_9 , struct V_20 * V_21 , int V_22 )
{
struct V_1 * V_2 = F_13 ( V_9 ) ;
return F_16 ( & V_2 -> V_16 , F_17 ( V_21 ) , V_22 , NULL ) ;
}
static void F_18 ( struct V_19 * V_9 )
{
struct V_1 * V_2 = F_13 ( V_9 ) ;
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
T_1 V_25 = 0x8c ;
if ( V_9 -> V_26 & V_27 ) {
V_25 |= 0x01 ;
} else if ( V_9 -> V_26 & V_28 ||
F_19 ( V_9 ) > V_29 ) {
V_25 |= 0x02 ;
} else if ( F_20 ( V_9 ) ) {
} else {
struct V_30 * V_31 ;
T_2 V_32 ;
memset ( V_24 -> V_33 , 0 , V_34 ) ;
F_21 (ha, net) {
V_32 = F_22 ( V_12 , V_31 -> V_10 ) >> 26 ;
V_24 -> V_33 [ V_32 >> 3 ] |=
1 << ( V_32 & 7 ) ;
}
F_23 ( V_2 , V_35 , 0 , 0 ,
V_34 , V_24 -> V_33 ) ;
V_25 |= 0x10 ;
}
F_23 ( V_2 , V_36 , V_25 , 0 , 0 , NULL ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_37 ;
struct V_38 V_39 = { . V_22 = V_40 } ;
F_25 ( & V_2 -> V_16 , 1 , 1 ) ;
F_26 ( & V_2 -> V_16 , & V_39 ) ;
V_37 = V_41 ;
if ( V_39 . V_42 != V_43 )
V_37 |= ~ V_44 ;
F_4 ( V_2 -> V_9 , L_3 ,
F_27 ( & V_39 ) , V_39 . V_42 , V_37 ) ;
F_28 ( V_2 , V_37 , 0 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_45 )
{
unsigned int V_46 = 5000 ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_47 , V_45 ) ;
F_31 ( 500 ) ;
while ( V_46 -- ) {
if ( F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_47 )
& V_48 )
F_31 ( 100 ) ;
else
return;
}
F_32 ( V_2 -> V_9 , L_4 ,
V_2 -> V_16 . V_14 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_51 = 0 ;
T_1 V_52 [ V_12 ] ;
int V_15 ;
unsigned long V_53 = V_2 -> V_54 -> V_24 ;
F_34 ( V_2 , V_50 ) ;
for ( V_15 = 2 ; V_15 >= 0 ; V_15 -- ) {
V_51 = F_35 ( V_2 , V_55 ,
( V_53 >> ( V_15 * 8 ) ) & 0xff , 0 , 0 , NULL , 0 ) ;
if ( V_51 < 0 )
goto V_56;
F_36 ( 5 ) ;
}
V_51 = F_37 ( V_2 , 0x80 , 0 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_38 ( V_2 , V_57 ,
0 , 0 , V_12 , V_52 , 0 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_5 ,
V_51 ) ;
goto V_56;
}
F_5 ( V_2 , V_52 ) ;
V_2 -> V_16 . V_2 = V_2 -> V_9 ;
V_2 -> V_16 . V_58 = F_10 ;
V_2 -> V_16 . V_59 = F_30 ;
V_2 -> V_16 . V_60 = 0x3f ;
V_2 -> V_16 . V_61 = 0x1f ;
V_2 -> V_16 . V_14 = F_39 ( V_2 ) ;
V_2 -> V_9 -> V_62 = & V_63 ;
V_2 -> V_9 -> V_64 = & V_65 ;
V_2 -> V_9 -> V_66 = 4 ;
V_2 -> V_9 -> V_67 = 4 ;
F_29 ( V_2 , V_48 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_68 ,
V_69 | V_70 | V_71 ) ;
F_40 ( & V_2 -> V_16 ) ;
return 0 ;
V_56:
return V_51 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_3 V_37 ;
struct V_38 V_39 = { . V_22 = V_40 } ;
F_25 ( & V_2 -> V_16 , 1 , 1 ) ;
F_26 ( & V_2 -> V_16 , & V_39 ) ;
V_37 = V_72 ;
if ( F_27 ( & V_39 ) != V_73 )
V_37 &= ~ V_74 ;
if ( V_39 . V_42 != V_43 )
V_37 &= ~ V_75 ;
F_4 ( V_2 -> V_9 , L_6 ,
F_27 ( & V_39 ) , V_39 . V_42 , V_37 ) ;
F_28 ( V_2 , V_37 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
int V_51 ;
F_43 ( V_24 -> V_76 , V_2 -> V_9 -> V_11 ) ;
V_51 = F_35 ( V_2 , V_77 , 0 , 0 ,
V_12 , V_24 -> V_76 , 0 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_37 ( V_2 , V_78 , 0 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_28 ( V_2 , V_72 , 0 ) ;
if ( V_51 < 0 )
goto V_56;
return 0 ;
V_56:
return V_51 ;
}
static int F_44 ( struct V_1 * V_2 , int V_79 )
{
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
int V_51 , V_80 ;
T_3 V_25 ;
V_51 = F_45 ( V_2 , V_81 | V_82 |
V_83 , 5 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_80 = ( ( V_2 -> V_16 . V_14 & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_51 = F_35 ( V_2 , V_84 , V_80 ,
0 , 0 , NULL , V_79 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_7 , V_51 ) ;
goto V_56;
}
if ( V_80 ) {
V_51 = F_46 ( V_2 , V_85 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
F_47 ( 10000 , 11000 ) ;
V_51 = F_46 ( V_2 , V_86 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
F_36 ( 60 ) ;
V_51 = F_46 ( V_2 , V_87 | V_88 ,
V_79 ) ;
if ( V_51 < 0 )
goto V_56;
} else {
V_51 = F_46 ( V_2 , V_85 | V_88 ,
V_79 ) ;
if ( V_51 < 0 )
goto V_56;
}
F_36 ( 150 ) ;
if ( V_79 && ( ! F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_17 ) ) ) {
V_51 = - V_89 ;
goto V_56;
}
V_51 = F_37 ( V_2 , V_78 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_28 ( V_2 , V_72 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_35 ( V_2 , V_90 ,
V_91 | V_92 ,
V_93 , 0 , NULL , V_79 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_8 , V_51 ) ;
goto V_56;
}
F_43 ( V_24 -> V_76 , V_2 -> V_9 -> V_11 ) ;
V_51 = F_35 ( V_2 , V_77 , 0 , 0 ,
V_12 , V_24 -> V_76 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_37 ( V_2 , V_78 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_25 = F_49 ( V_2 , V_79 ) ;
F_4 ( V_2 -> V_9 , L_9 ,
V_25 ) ;
V_25 = F_50 ( V_2 , V_79 ) ;
F_4 ( V_2 -> V_9 ,
L_10 ,
V_25 ) ;
return 0 ;
V_56:
return V_51 ;
}
static int F_51 ( struct V_1 * V_2 , int V_79 )
{
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
int V_51 , V_80 ;
T_3 V_25 , V_94 , V_95 , V_96 ;
T_1 V_97 = 0 ;
V_51 = F_45 ( V_2 , V_81 , 5 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_80 = ( ( V_2 -> V_16 . V_14 & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_51 = F_35 ( V_2 , V_84 , V_80 |
V_98 , 0 , 0 , NULL , V_79 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_7 , V_51 ) ;
goto V_56;
}
F_47 ( 10000 , 11000 ) ;
V_51 = F_46 ( V_2 , V_85 | V_87 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
F_47 ( 10000 , 11000 ) ;
V_51 = F_46 ( V_2 , V_87 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
F_36 ( 160 ) ;
V_51 = F_46 ( V_2 , V_86 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_46 ( V_2 , V_87 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
F_36 ( 200 ) ;
if ( V_79 && ( ! F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_17 ) ) ) {
V_51 = - 1 ;
goto V_56;
}
V_51 = F_38 ( V_2 , V_99 , 0 ,
0 , 1 , & V_97 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
if ( ( V_97 & V_100 ) == V_101 ) {
V_51 = F_35 ( V_2 , V_102 , 0x8000 , 0x8001 ,
0 , NULL , V_79 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_11 ,
V_51 ) ;
goto V_56;
}
} else if ( ( V_97 & V_100 ) == V_103 ) {
V_94 = F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_104 ) ;
V_95 = F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_105 ) ;
V_96 = F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_106 ) ;
F_4 ( V_2 -> V_9 ,
L_12 ,
V_94 , V_95 , V_96 ) ;
if ( V_94 != V_107 )
F_52 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_104 ,
V_107 ) ;
if ( V_95 != V_108 )
F_52 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_105 ,
V_108 ) ;
if ( V_96 != V_109 )
F_52 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_106 ,
V_109 ) ;
}
V_51 = F_35 ( V_2 , V_90 ,
V_91 | V_92 ,
V_93 , 0 , NULL , V_79 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_8 , V_51 ) ;
goto V_56;
}
memcpy ( V_24 -> V_76 , V_2 -> V_9 -> V_11 , V_12 ) ;
V_51 = F_35 ( V_2 , V_77 , 0 , 0 , V_12 ,
V_24 -> V_76 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_37 ( V_2 , V_78 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_51 = F_28 ( V_2 , V_72 , V_79 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_37 ( V_2 , V_78 , V_79 ) ;
if ( V_51 < 0 )
goto V_56;
V_25 = F_49 ( V_2 , V_79 ) ;
F_4 ( V_2 -> V_9 , L_9 ,
V_25 ) ;
V_25 = F_50 ( V_2 , V_79 ) ;
F_4 ( V_2 -> V_9 ,
L_10 ,
V_25 ) ;
return 0 ;
V_56:
return V_51 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
T_3 V_113 ;
V_113 = F_50 ( V_2 , 1 ) ;
V_113 &= ~ V_114 ;
F_28 ( V_2 , V_113 , 1 ) ;
F_4 ( V_2 -> V_9 , L_13 ,
F_50 ( V_2 , 1 ) ) ;
V_111 -> V_115 =
F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_47 ) ;
V_111 -> V_116 =
F_48 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_68 ) ;
}
static int F_54 ( struct V_49 * V_50 , T_4 V_117 )
{
struct V_1 * V_2 = F_55 ( V_50 ) ;
struct V_110 * V_111 = V_2 -> V_112 ;
if ( V_111 -> V_118 )
V_111 -> V_118 ( V_2 ) ;
return F_56 ( V_50 , V_117 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_112 ;
if ( V_111 -> V_116 ) {
F_52 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_68 ,
V_111 -> V_116 ) ;
F_52 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_47 ,
V_111 -> V_115 ) ;
F_40 ( & V_2 -> V_16 ) ;
V_111 -> V_116 = 0 ;
V_111 -> V_115 = 0 ;
}
}
static void F_58 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
if ( ! F_44 ( V_2 , 1 ) )
break;
F_57 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
if ( ! F_51 ( V_2 , 1 ) )
break;
}
F_57 ( V_2 ) ;
}
static int F_60 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_55 ( V_50 ) ;
struct V_110 * V_111 = V_2 -> V_112 ;
if ( V_111 -> V_119 )
V_111 -> V_119 ( V_2 ) ;
return F_61 ( V_50 ) ;
}
static int F_62 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_51 , V_15 ;
T_1 V_52 [ V_12 ] , V_97 = 0 ;
T_2 V_120 ;
struct V_110 * V_111 ;
F_34 ( V_2 , V_50 ) ;
if ( V_2 -> V_54 -> V_24 & V_121 ) {
for ( V_15 = 0 ; V_15 < ( V_12 >> 1 ) ; V_15 ++ ) {
V_51 = F_38 ( V_2 , V_122 , 0x04 + V_15 ,
0 , 2 , V_52 + V_15 * 2 , 0 ) ;
if ( V_51 < 0 )
break;
}
} else {
V_51 = F_38 ( V_2 , V_123 ,
0 , 0 , V_12 , V_52 , 0 ) ;
}
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_14 , V_51 ) ;
return V_51 ;
}
F_5 ( V_2 , V_52 ) ;
V_2 -> V_16 . V_2 = V_2 -> V_9 ;
V_2 -> V_16 . V_58 = F_10 ;
V_2 -> V_16 . V_59 = F_30 ;
V_2 -> V_16 . V_60 = 0x1f ;
V_2 -> V_16 . V_61 = 0x1f ;
V_2 -> V_16 . V_14 = F_39 ( V_2 ) ;
V_2 -> V_9 -> V_62 = & V_124 ;
V_2 -> V_9 -> V_64 = & V_125 ;
V_2 -> V_9 -> V_66 = 4 ;
V_2 -> V_9 -> V_67 = 4 ;
F_38 ( V_2 , V_99 , 0 , 0 , 1 , & V_97 , 0 ) ;
V_97 &= V_100 ;
( V_97 == V_126 ) ? F_44 ( V_2 , 0 ) :
F_51 ( V_2 , 0 ) ;
V_120 = F_9 ( V_2 ) ;
F_4 ( V_2 -> V_9 , L_15 , V_120 ) ;
if ( V_2 -> V_54 -> V_26 & V_127 ) {
V_2 -> V_128 = 2048 ;
}
V_2 -> V_112 = F_63 ( sizeof( struct V_110 ) , V_129 ) ;
if ( ! V_2 -> V_112 )
return - V_130 ;
V_111 = V_2 -> V_112 ;
V_111 -> V_115 = 0 ;
V_111 -> V_116 = 0 ;
if ( V_97 == V_126 ) {
V_111 -> V_119 = F_58 ;
V_111 -> V_118 = F_53 ;
} else {
V_111 -> V_119 = F_59 ;
V_111 -> V_118 = F_53 ;
}
return 0 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
F_65 ( V_2 -> V_112 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
T_3 V_131 ;
F_4 ( V_2 -> V_9 , L_16 ) ;
V_131 = F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_132 ) ;
F_4 ( V_2 -> V_9 , L_17 , V_131 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_133 ,
V_134 | V_135 ) ;
if ( V_24 -> V_136 ) {
V_131 = F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_137 ) ;
F_4 ( V_2 -> V_9 , L_18 , V_131 ) ;
V_131 &= 0xf8ff ;
V_131 |= ( 1 + 0x0100 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_137 , V_131 ) ;
V_131 = F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 ,
V_137 ) ;
F_4 ( V_2 -> V_9 , L_19 , V_131 ) ;
V_131 &= 0xfc0f ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
F_4 ( V_2 -> V_9 , L_20 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x1f , 0x0005 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x0c , 0 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x01 ,
F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x01 ) | 0x0080 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x1f , 0 ) ;
if ( V_24 -> V_136 == 12 ) {
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x1f , 0x0002 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x1a , 0x00cb ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , 0x1f , 0 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_3 V_138 )
{
T_3 V_131 = F_10 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_139 ) ;
F_4 ( V_2 -> V_9 , L_21 , V_131 ) ;
V_131 &= 0xfc0f ;
switch ( V_138 ) {
case V_140 :
V_131 |= 0x03e0 ;
break;
case V_73 :
V_131 |= 0x03b0 ;
break;
default:
V_131 |= 0x02f0 ;
}
F_4 ( V_2 -> V_9 , L_22 , V_131 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_139 , V_131 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
int V_51 ;
T_5 V_141 ;
T_1 V_142 ;
int V_143 = 0 ;
T_2 V_120 ;
F_38 ( V_2 , V_144 , 0 , 0 , 1 , & V_142 , 0 ) ;
F_4 ( V_2 -> V_9 , L_23 , V_142 ) ;
F_35 ( V_2 , V_145 , 0 , 0 , 0 , NULL , 0 ) ;
F_38 ( V_2 , V_122 , 0x0017 , 0 , 2 , & V_141 , 0 ) ;
F_35 ( V_2 , V_146 , 0 , 0 , 0 , NULL , 0 ) ;
F_4 ( V_2 -> V_9 , L_24 , V_141 ) ;
if ( V_141 == F_70 ( 0xffff ) ) {
V_24 -> V_147 = V_148 ;
V_24 -> V_136 = 0 ;
V_143 = 1 ;
} else {
V_24 -> V_147 = F_71 ( V_141 ) & 0x7F ;
V_24 -> V_136 = F_71 ( V_141 ) >> 8 ;
V_143 = ( F_71 ( V_141 ) & 0x80 ) ? 0 : 1 ;
}
F_4 ( V_2 -> V_9 , L_25 , V_143 , V_24 -> V_147 ) ;
F_45 ( V_2 , V_81 | V_149 |
V_150 , 40 , 0 ) ;
if ( ( F_71 ( V_141 ) >> 8 ) != 1 ) {
F_45 ( V_2 , 0x003c , 30 , 0 ) ;
F_45 ( V_2 , 0x001c , 300 , 0 ) ;
F_45 ( V_2 , 0x003c , 30 , 0 ) ;
} else {
F_4 ( V_2 -> V_9 , L_26 ) ;
F_45 ( V_2 , V_150 , 30 , 0 ) ;
F_45 ( V_2 , V_150 | V_149 , 30 , 0 ) ;
}
V_120 = F_9 ( V_2 ) ;
F_4 ( V_2 -> V_9 , L_15 , V_120 ) ;
F_35 ( V_2 , V_84 , 0 , 0 , 0 , NULL , 0 ) ;
F_46 ( V_2 , 0 , 0 ) ;
F_36 ( 150 ) ;
F_46 ( V_2 , V_88 | V_85 , 0 ) ;
F_36 ( 150 ) ;
F_37 ( V_2 , 0 , 0 ) ;
if ( V_24 -> V_147 == V_148 ) {
F_66 ( V_2 ) ;
F_36 ( 60 ) ;
} else if ( V_24 -> V_147 == V_151 )
F_67 ( V_2 ) ;
F_29 ( V_2 , V_48 | V_152 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_68 ,
V_69 | V_70 | V_71 ) ;
F_30 ( V_2 -> V_9 , V_2 -> V_16 . V_14 , V_153 ,
V_154 ) ;
F_28 ( V_2 , V_155 , 0 ) ;
F_40 ( & V_2 -> V_16 ) ;
memcpy ( V_24 -> V_76 , V_2 -> V_9 -> V_11 , V_12 ) ;
V_51 = F_35 ( V_2 , V_77 , 0 , 0 , V_12 ,
V_24 -> V_76 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = F_37 ( V_2 , V_78 , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_3 V_37 ;
struct V_38 V_39 = { . V_22 = V_40 } ;
struct V_23 * V_24 = (struct V_23 * ) & V_2 -> V_24 ;
T_2 V_138 ;
F_4 ( V_2 -> V_9 , L_27 ) ;
F_25 ( & V_2 -> V_16 , 1 , 1 ) ;
F_26 ( & V_2 -> V_16 , & V_39 ) ;
V_37 = V_155 ;
V_138 = F_27 ( & V_39 ) ;
if ( V_138 == V_140 )
V_37 |= V_156 ;
else if ( V_138 == V_73 )
V_37 |= V_74 ;
else
V_37 &= ~ ( V_74 | V_156 ) ;
V_37 |= V_157 ;
if ( V_39 . V_42 == V_43 )
V_37 |= V_75 ;
else
V_37 &= ~ V_75 ;
F_4 ( V_2 -> V_9 , L_28 ,
V_138 , V_39 . V_42 , V_37 ) ;
F_28 ( V_2 , V_37 , 0 ) ;
if ( V_24 -> V_147 == V_148 && V_24 -> V_136 )
F_68 ( V_2 , V_138 ) ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
T_3 V_158 = V_159 ;
T_3 V_160 ;
T_3 V_113 ;
int V_161 = V_2 -> V_128 ;
if ( V_2 -> V_162 < 2048 ) {
V_2 -> V_128 = 2048 ;
V_158 = V_163 ;
} else if ( V_2 -> V_162 < 4096 ) {
V_2 -> V_128 = 4096 ;
V_158 = V_164 ;
} else if ( V_2 -> V_162 < 8192 ) {
V_2 -> V_128 = 8192 ;
V_158 = V_165 ;
} else if ( V_2 -> V_162 < 16384 ) {
V_2 -> V_128 = 16384 ;
V_158 = V_159 ;
}
V_160 = F_49 ( V_2 , 0 ) ;
F_37 ( V_2 , ( V_160 & ~ V_159 ) | V_158 , 0 ) ;
V_113 = F_50 ( V_2 , 0 ) ;
if ( V_2 -> V_9 -> V_166 > 1500 )
V_113 |= V_167 ;
else
V_113 &= ~ V_167 ;
F_28 ( V_2 , V_113 , 0 ) ;
if ( V_2 -> V_128 > V_161 )
F_74 ( V_2 ) ;
}
static int F_75 ( struct V_19 * V_9 , int V_168 )
{
struct V_1 * V_2 = F_13 ( V_9 ) ;
int V_169 = V_168 + V_9 -> V_170 + 4 ;
F_4 ( V_2 -> V_9 , L_29 , V_168 ) ;
if ( ( V_169 % V_2 -> V_171 ) == 0 )
return - V_172 ;
V_9 -> V_166 = V_168 ;
V_2 -> V_162 = V_9 -> V_166 + V_9 -> V_170 ;
F_73 ( V_2 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_51 ;
T_1 V_52 [ V_12 ] ;
F_34 ( V_2 , V_50 ) ;
V_51 = F_38 ( V_2 , V_123 , 0 , 0 , V_12 , V_52 , 0 ) ;
if ( V_51 < 0 ) {
F_4 ( V_2 -> V_9 , L_14 , V_51 ) ;
return V_51 ;
}
F_5 ( V_2 , V_52 ) ;
V_2 -> V_16 . V_2 = V_2 -> V_9 ;
V_2 -> V_16 . V_58 = F_10 ;
V_2 -> V_16 . V_59 = F_30 ;
V_2 -> V_16 . V_60 = 0x1f ;
V_2 -> V_16 . V_61 = 0xff ;
V_2 -> V_16 . V_173 = 1 ;
V_2 -> V_16 . V_14 = F_39 ( V_2 ) ;
V_2 -> V_9 -> V_62 = & V_174 ;
V_2 -> V_9 -> V_64 = & V_175 ;
V_2 -> V_9 -> V_176 = 16384 - ( V_2 -> V_9 -> V_170 + 4 ) ;
F_46 ( V_2 , 0 , 0 ) ;
F_36 ( 150 ) ;
F_46 ( V_2 , V_88 | V_85 , 0 ) ;
F_36 ( 150 ) ;
if ( V_2 -> V_54 -> V_26 & V_127 ) {
V_2 -> V_128 = 2048 ;
}
V_2 -> V_112 = F_63 ( sizeof( struct V_110 ) , V_129 ) ;
if ( ! V_2 -> V_112 )
return - V_130 ;
return 0 ;
}
