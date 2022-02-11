static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_9 + V_2 -> V_10 . V_11 . V_12 ,
& V_3 ,
sizeof( V_3 ) ) ;
if ( V_5 < 0 ) {
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_1 , V_15 , V_5 ) ;
return V_5 ;
}
V_2 -> V_10 . V_16 = V_3 >> 7 ;
V_2 -> V_10 . V_12 = V_3 & 0x1f ;
if ( V_2 -> V_10 . V_12 != 0x00 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_2 ,
V_15 , V_2 -> V_10 . V_12 , V_2 -> V_10 . V_4 ) ;
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_9 + V_2 -> V_10 . V_11 . V_17 ,
& V_4 ,
sizeof( V_4 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_3 ,
V_15 ) ;
return V_5 ;
}
V_2 -> V_10 . V_4 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_18 )
{
unsigned long V_19 ;
V_19 = F_6 ( V_18 ) ;
if ( ! F_7 ( & V_2 -> V_10 . V_20 , V_19 ) ) {
F_8 ( & V_2 -> V_6 -> V_14 , L_4 ,
V_15 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_22 )
{
int V_5 ;
T_1 V_23 ;
struct V_24 V_25 ;
V_23 = V_2 -> V_6 -> V_8 . V_9 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
switch ( V_22 ) {
case V_26 :
V_25 . V_27 = V_28 ;
V_25 . V_4 = V_29 ;
break;
case V_30 :
V_25 . V_27 = V_28 ;
V_25 . V_4 = V_31 ;
break;
case V_32 :
V_25 . V_27 = V_33 ;
V_25 . V_4 = V_31 ;
break;
case V_34 :
V_25 . V_27 = V_35 ;
V_25 . V_4 = V_31 ;
break;
case V_36 :
V_25 . V_27 = V_37 ;
V_25 . V_4 = V_31 ;
break;
case V_38 :
V_25 . V_27 = V_39 ;
V_25 . V_4 = V_31 ;
break;
case V_40 :
V_25 . V_27 = V_41 ;
V_25 . V_4 = V_31 ;
break;
case V_42 :
V_25 . V_27 = V_43 ;
V_25 . V_4 = V_44 ;
break;
}
V_25 . V_45 [ 0 ] = V_2 -> V_46 [ 0 ] ;
V_25 . V_45 [ 1 ] = V_2 -> V_46 [ 1 ] ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_27 ,
& V_25 , sizeof( V_25 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_5 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_22 )
{
int V_5 ;
T_1 V_23 ;
T_1 V_4 ;
V_23 = V_2 -> V_6 -> V_8 . V_9 ;
switch ( V_22 ) {
case V_47 :
case V_48 :
case V_49 :
V_4 = V_50 ;
break;
case V_51 :
V_4 = V_52 ;
break;
case V_26 :
V_4 = V_29 ;
break;
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_38 :
case V_40 :
V_4 = V_31 ;
break;
case V_42 :
V_4 = V_44 ;
break;
default:
F_4 ( & V_2 -> V_6 -> V_14 , L_6 ,
V_15 , V_22 ) ;
return - V_53 ;
}
V_2 -> V_10 . V_4 = V_4 ;
switch ( V_22 ) {
case V_26 :
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_38 :
case V_40 :
case V_42 :
V_5 = F_9 ( V_2 , V_22 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return 0 ;
default:
break;
}
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_7 ,
V_15 , V_4 ) ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_17 ,
& V_4 , sizeof( V_4 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_8 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_22 )
{
int V_5 ;
T_1 V_23 ;
T_1 V_54 ;
V_23 = V_2 -> V_6 -> V_8 . V_9 ;
switch ( V_22 ) {
case V_47 :
V_54 = V_28 ;
break;
case V_48 :
case V_51 :
if ( V_2 -> V_10 . V_55 == V_56 )
V_54 = V_35 ;
else if ( V_2 -> V_10 . V_55 == V_57 )
V_54 = V_37 ;
else if ( V_2 -> V_10 . V_55 == V_58 )
V_54 = V_59 ;
else if ( V_2 -> V_10 . V_55 == V_60 )
V_54 = V_33 ;
else if ( V_2 -> V_10 . V_55 == V_61 )
V_54 = V_39 ;
break;
case V_49 :
V_54 = V_41 ;
break;
case V_26 :
V_54 = V_28 ;
break;
case V_32 :
V_54 = V_33 ;
break;
case V_34 :
V_54 = V_35 ;
break;
case V_36 :
V_54 = V_37 ;
break;
case V_38 :
V_54 = V_39 ;
break;
case V_40 :
V_54 = V_41 ;
break;
case V_42 :
V_54 = V_43 ;
break;
default:
F_4 ( & V_2 -> V_6 -> V_14 , L_6 ,
V_15 , V_22 ) ;
return - V_53 ;
}
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_27 ,
& V_54 , sizeof( V_54 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_9 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_19 ;
T_1 V_23 ;
T_2 V_62 ;
T_3 V_63 = 0 ;
V_23 = V_2 -> V_6 -> V_8 . V_9 ;
V_2 -> V_10 . V_55 = V_61 ;
V_5 = F_12 ( V_2 , V_51 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_63 ,
& V_63 , sizeof( V_63 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_10 ,
V_15 ) ;
return V_5 ;
}
F_14 ( V_2 -> V_10 . V_64 , & V_62 ) ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_65 ,
& V_62 , sizeof( V_62 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_11 ,
V_15 ) ;
return V_5 ;
}
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_11 ( V_2 , V_51 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_12 ,
V_15 ) ;
return V_5 ;
}
V_19 = F_6 ( V_66 ) ;
while ( F_16 ( V_67 , V_19 ) ) {
F_17 ( 5000 , 6000 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_10 . V_4 == V_68 &&
V_2 -> V_10 . V_12 == 0x00 ) {
break;
}
}
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_45 ,
V_2 -> V_10 . V_69 ,
V_2 -> V_10 . V_70 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_13 ,
V_15 ) ;
return V_5 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
const void * V_71 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
int V_76 ;
int V_77 ;
T_3 V_78 ;
T_3 V_74 ;
const struct V_71 * V_79 ;
for ( V_76 = 0 ; V_76 < V_2 -> V_10 . V_80 ; V_76 ++ ) {
V_77 = V_76 * 8 + 2 ;
V_79 = V_71 + V_77 ;
V_78 = F_19 ( V_79 -> V_78 ) ;
V_74 = F_19 ( V_79 -> V_81 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_14 ,
V_15 , V_76 , sizeof( struct V_71 ) , V_79 ) ;
switch ( V_79 -> V_27 & 0x1f ) {
case V_28 :
V_73 -> V_82 = V_78 ;
V_75 -> V_82 = V_74 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_15 ,
V_15 , V_73 -> V_82 ) ;
break;
case V_35 :
V_73 -> V_83 = V_78 ;
V_75 -> V_83 = V_74 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_16 ,
V_15 , V_73 -> V_83 ) ;
break;
case V_37 :
V_73 -> V_84 = V_78 ;
V_75 -> V_84 = V_74 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_17 ,
V_15 , V_73 -> V_84 ) ;
break;
case V_39 :
V_73 -> V_85 = V_78 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_18 ,
V_15 , V_73 -> V_85 ) ;
break;
case V_41 :
V_73 -> V_86 = V_78 ;
V_75 -> V_86 = V_74 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_19 ,
V_15 , V_73 -> V_86 ) ;
break;
case V_59 :
V_73 -> V_87 = V_78 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_20 ,
V_15 , V_73 -> V_87 ) ;
break;
case V_33 :
V_73 -> V_88 = V_78 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_21 ,
V_15 , V_73 -> V_88 ) ;
break;
case V_89 :
V_73 -> V_90 = V_78 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_22 ,
V_15 , V_73 -> V_90 ) ;
break;
}
}
}
static int F_20 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_23 ;
int V_91 ;
T_1 V_92 ;
struct V_93 V_94 ;
V_23 = V_2 -> V_6 -> V_8 . V_95 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_23 ,
& V_92 ,
sizeof( V_92 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_23 , V_15 ) ;
return V_5 ;
}
V_91 = ( V_92 & 0x7 ) + 1 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_23 + V_91 ,
& V_94 ,
sizeof( V_94 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_24 ,
V_15 ) ;
return V_5 ;
}
V_2 -> V_46 [ 0 ] = V_94 . V_96 ;
V_2 -> V_46 [ 1 ] = V_94 . V_97 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_25 ,
V_2 -> V_46 [ 1 ] , V_2 -> V_46 [ 0 ] ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
int V_76 ;
T_1 V_23 ;
int V_91 ;
T_1 * V_79 ;
T_1 V_92 ;
struct V_93 V_94 ;
V_23 = V_2 -> V_6 -> V_8 . V_95 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_23 ,
& V_92 ,
sizeof( V_92 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_23 , V_15 ) ;
return V_5 ;
}
V_91 = ( V_92 & 0x07 ) + 1 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_23 + V_91 ,
& V_94 ,
sizeof( V_94 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_24 ,
V_15 ) ;
return V_5 ;
}
V_2 -> V_46 [ 0 ] = V_94 . V_96 ;
V_2 -> V_46 [ 1 ] = V_94 . V_97 ;
V_2 -> V_10 . V_98 = F_19 ( V_94 . V_98 ) ;
V_2 -> V_10 . V_64 =
F_19 ( V_94 . V_64 ) ;
V_2 -> V_10 . V_99 = F_19 ( V_94 . V_99 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_26 ,
V_15 , V_2 -> V_10 . V_98 ) ;
V_2 -> V_10 . V_11 . V_12 = V_100 ;
V_2 -> V_10 . V_11 . V_27 = V_101 ;
V_2 -> V_10 . V_11 . V_63 = V_102 ;
V_2 -> V_10 . V_11 . V_65 = V_103 ;
V_2 -> V_10 . V_11 . V_17 = V_104 ;
V_2 -> V_10 . V_11 . V_45 = V_105 ;
V_2 -> V_10 . V_106 = V_94 . V_107 [ 1 ] & V_108 ;
V_2 -> V_10 . V_109 =
V_94 . V_107 [ 1 ] & V_110 ;
if ( V_92 & V_111 ) {
T_1 V_112 [ V_113 ] ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_114 ,
V_112 ,
sizeof( V_112 ) ) ;
if ( V_5 )
return V_5 ;
for ( V_76 = 0 ; V_76 < sizeof( V_112 ) - 1 && ! V_112 [ V_76 ] ; V_76 ++ )
;
snprintf ( V_2 -> V_115 , sizeof( V_2 -> V_115 ) ,
L_27 , ( int ) sizeof( V_112 ) - V_76 , V_112 + V_76 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_28 ,
V_2 -> V_115 ) ;
}
V_2 -> V_10 . V_80 = 0 ;
for ( V_76 = 0 ; V_76 < sizeof( V_94 . V_107 ) ; V_76 ++ )
V_2 -> V_10 . V_80 += F_22 ( V_94 . V_107 [ V_76 ] ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_29 ,
V_15 , sizeof( V_94 . V_107 ) ,
V_94 . V_107 ) ;
V_2 -> V_10 . V_70 = V_2 -> V_10 . V_80 * 8 + 2 ;
V_2 -> V_10 . V_69 = F_23 ( & V_2 -> V_6 -> V_14 ,
V_2 -> V_10 . V_70 ,
V_116 ) ;
if ( ! V_2 -> V_10 . V_69 ) {
V_2 -> V_10 . V_117 = 0 ;
return - V_118 ;
}
V_2 -> V_10 . V_117 = V_2 -> V_10 . V_70 ;
V_79 = V_2 -> V_10 . V_69 ;
V_5 = F_13 ( V_2 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_30 ,
V_15 ) ;
return V_5 ;
}
F_18 ( V_2 , V_79 ,
& V_2 -> V_10 . V_73 , & V_2 -> V_10 . V_75 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_3 V_72 ;
V_72 = V_2 -> V_10 . V_119 . V_82 . V_120 / V_2 -> V_10 . V_98 ;
V_2 -> V_121 += V_72 ;
if ( V_72 != V_2 -> V_10 . V_73 . V_82 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_31 ,
V_72 , V_2 -> V_10 . V_73 . V_82 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_3 V_72 ;
V_72 = V_2 -> V_10 . V_119 . V_83 . V_120 / V_2 -> V_10 . V_98 ;
V_2 -> V_121 += V_72 ;
if ( V_72 != V_2 -> V_10 . V_73 . V_83 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_32 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_3 V_72 ;
V_72 = V_2 -> V_10 . V_119 . V_84 . V_120 / V_2 -> V_10 . V_98 ;
V_2 -> V_121 += V_72 ;
if ( V_72 != V_2 -> V_10 . V_73 . V_84 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_33 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_3 V_72 ;
V_72 = V_2 -> V_10 . V_119 . V_86 . V_120 / V_2 -> V_10 . V_98 ;
V_2 -> V_121 += V_72 ;
if ( V_72 != V_2 -> V_10 . V_73 . V_86 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_34 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_3 V_72 ;
V_72 = V_2 -> V_10 . V_119 . V_88 . V_120 / V_2 -> V_10 . V_98 ;
V_2 -> V_121 += V_72 ;
if ( V_72 != V_2 -> V_10 . V_73 . V_88 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_35 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_5 ;
F_30 ( & V_2 -> V_6 -> V_14 , L_36 ) ;
F_15 ( & V_2 -> V_10 . V_20 ) ;
switch ( V_2 -> V_10 . V_55 ) {
case V_56 :
V_5 = F_11 ( V_2 , V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
case V_57 :
V_5 = F_11 ( V_2 , V_36 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
case V_60 :
V_5 = F_11 ( V_2 , V_32 ) ;
if ( V_5 < 0 )
return V_5 ;
break;
}
V_5 = F_5 ( V_2 , V_122 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_5 ;
F_30 ( & V_2 -> V_6 -> V_14 , L_37 ) ;
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_11 ( V_2 , V_40 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_122 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_5 ;
F_30 ( & V_2 -> V_6 -> V_14 , L_38 ) ;
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_11 ( V_2 , V_30 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_122 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 . V_55 = V_56 ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_10 . V_106 ) {
V_2 -> V_10 . V_55 = V_57 ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
if ( V_2 -> V_10 . V_123 && V_2 -> V_10 . V_109 ) {
V_5 = F_31 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
T_3 V_124 , T_1 V_4 )
{
int V_5 ;
T_1 V_23 ;
T_2 V_62 ;
T_3 V_125 ;
T_3 V_126 ;
T_3 V_127 = V_124 ;
T_3 V_63 = 0 ;
T_3 V_77 = 0 ;
V_23 = V_2 -> V_6 -> V_8 . V_9 ;
V_5 = F_12 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_63 ,
& V_63 , sizeof( V_63 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_10 ,
V_15 ) ;
return V_5 ;
}
V_126 = F_34 ( V_2 -> V_10 . V_99 ,
( T_3 ) ( V_128 / V_2 -> V_10 . V_98 ) ) ;
do {
V_125 = F_34 ( V_127 , V_126 ) ;
F_14 ( V_125 , & V_62 ) ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_65 ,
& V_62 , sizeof( V_62 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_39 ,
V_15 , V_127 ) ;
return V_5 ;
}
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_11 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_129 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_45 ,
& V_2 -> V_10 . V_69 [ V_77 ] ,
V_125 * V_2 -> V_10 . V_98 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_40 ,
V_15 , V_127 ) ;
return V_5 ;
}
V_77 += ( V_125 * V_2 -> V_10 . V_98 ) ;
V_127 -= V_125 ;
} while ( V_127 );
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
const void * V_130 , T_3 V_124 ,
T_1 V_4 )
{
int V_5 ;
T_1 V_23 ;
T_2 V_62 ;
T_3 V_125 ;
T_3 V_126 ;
T_3 V_127 = V_124 ;
T_3 V_63 = 0 ;
V_23 = V_2 -> V_6 -> V_8 . V_9 ;
V_5 = F_12 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_63 ,
& V_63 , sizeof( V_63 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_10 ,
V_15 ) ;
return V_5 ;
}
if ( V_2 -> V_10 . V_99 > ( V_128 / V_2 -> V_10 . V_98 ) )
V_126 = V_128 / V_2 -> V_10 . V_98 ;
else
V_126 = V_2 -> V_10 . V_99 ;
do {
V_125 = F_34 ( V_127 , V_126 ) ;
F_14 ( V_125 , & V_62 ) ;
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_65 ,
& V_62 , sizeof( V_62 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_39 ,
V_15 , V_127 ) ;
return V_5 ;
}
V_5 = F_11 ( V_2 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_10 ( V_2 -> V_6 -> V_7 ,
V_23 + V_2 -> V_10 . V_11 . V_45 ,
V_130 , V_125 * V_2 -> V_10 . V_98 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 ,
L_41 ,
V_15 , V_127 ) ;
return V_5 ;
}
V_5 = F_5 ( V_2 , V_129 ) ;
if ( V_5 < 0 )
return V_5 ;
V_130 += ( V_125 * V_2 -> V_10 . V_98 ) ;
V_127 -= V_125 ;
V_2 -> V_131 += V_125 ;
V_2 -> V_132 = ( V_2 -> V_131 * 100 ) /
V_2 -> V_121 ;
} while ( V_127 );
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return F_35 ( V_2 , V_2 -> V_10 . V_133 ,
V_2 -> V_10 . V_134 ,
V_48 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_55 = V_56 ;
V_2 -> V_10 . V_133 = V_2 -> V_10 . V_119 . V_83 . V_135 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_119 . V_83 . V_120 ;
V_2 -> V_10 . V_134 = V_2 -> V_10 . V_136 / V_2 -> V_10 . V_98 ;
return F_36 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
V_2 -> V_10 . V_55 = V_57 ;
V_2 -> V_10 . V_133 = V_2 -> V_10 . V_119 . V_84 . V_135 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_119 . V_84 . V_120 ;
V_2 -> V_10 . V_134 = V_2 -> V_10 . V_136 / V_2 -> V_10 . V_98 ;
return F_36 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
return F_35 ( V_2 , V_2 -> V_10 . V_119 . V_86 . V_135 ,
V_2 -> V_10 . V_119 . V_86 . V_120 /
V_2 -> V_10 . V_98 ,
V_49 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_10 . V_55 = V_61 ;
V_2 -> V_10 . V_133 = V_2 -> V_10 . V_119 . V_85 . V_135 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_119 . V_85 . V_120 ;
V_2 -> V_10 . V_134 = V_2 -> V_10 . V_136 / V_2 -> V_10 . V_98 ;
if ( V_2 -> V_10 . V_134 != V_2 -> V_10 . V_73 . V_85 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_42 ,
V_15 ) ;
return - V_53 ;
}
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_11 ( V_2 , V_38 ) ;
if ( V_5 < 0 )
return V_5 ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_43 , V_15 ) ;
V_5 = F_5 ( V_2 , V_66 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_36 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
T_3 V_72 ;
int V_5 ;
V_72 = V_2 -> V_10 . V_73 . V_88 ;
V_2 -> V_10 . V_55 = V_60 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_98 * V_72 ;
F_42 ( & V_2 -> V_6 -> V_14 , V_2 -> V_10 . V_69 ) ;
V_2 -> V_10 . V_69 = F_23 ( & V_2 -> V_6 -> V_14 ,
V_2 -> V_10 . V_136 , V_116 ) ;
if ( ! V_2 -> V_10 . V_69 ) {
V_2 -> V_10 . V_117 = 0 ;
return - V_118 ;
}
V_2 -> V_10 . V_117 = V_2 -> V_10 . V_136 ;
V_5 = F_33 ( V_2 , V_72 , V_51 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_40 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 . V_55 = V_60 ;
V_2 -> V_10 . V_133 = V_2 -> V_10 . V_69 ;
V_2 -> V_10 . V_136 = V_2 -> V_10 . V_119 . V_88 . V_120 ;
V_2 -> V_10 . V_134 = V_2 -> V_10 . V_136 / V_2 -> V_10 . V_98 ;
V_5 = F_36 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
T_3 V_137 ;
V_137 = V_2 -> V_10 . V_119 . V_82 . V_120 / V_2 -> V_10 . V_98 ;
return F_35 ( V_2 , V_2 -> V_10 . V_119 . V_82 . V_135 ,
V_137 , V_47 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 . V_75 . V_82 != V_2 -> V_10 . V_119 . V_75 . V_82 ) {
V_2 -> V_10 . V_123 = true ;
return;
}
if ( V_2 -> V_10 . V_75 . V_83 != V_2 -> V_10 . V_119 . V_75 . V_83 ) {
V_2 -> V_10 . V_123 = true ;
return;
}
if ( V_2 -> V_10 . V_106 &&
V_2 -> V_10 . V_75 . V_84 != V_2 -> V_10 . V_119 . V_75 . V_84 ) {
V_2 -> V_10 . V_123 = true ;
return;
}
if ( V_2 -> V_10 . V_109 &&
V_2 -> V_10 . V_75 . V_86 != V_2 -> V_10 . V_119 . V_75 . V_86 ) {
V_2 -> V_10 . V_123 = true ;
return;
}
V_2 -> V_10 . V_123 = false ;
}
static void F_45 ( struct V_1 * V_2 ,
const void * V_138 )
{
int V_76 ;
int V_139 ;
unsigned int V_140 ;
unsigned int V_141 ;
unsigned int V_62 ;
const void * V_142 ;
const struct V_143 * V_144 ;
V_139 = V_2 -> V_10 . V_119 . V_145 . V_120 / 4 - 1 ;
for ( V_76 = 1 ; V_76 <= V_139 ; V_76 ++ ) {
V_140 = F_46 ( V_2 -> V_10 . V_119 . V_145 . V_135 + V_76 * 4 ) ;
V_144 = V_138 + V_140 ;
V_141 = F_19 ( V_144 -> V_141 ) ;
V_142 = V_138 + F_47 ( V_144 -> V_146 ) ;
V_62 = F_47 ( V_144 -> V_147 ) ;
switch ( V_141 ) {
case V_148 :
case V_149 :
V_2 -> V_10 . V_119 . V_88 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_88 . V_120 = V_62 ;
break;
case V_150 :
case V_151 :
V_2 -> V_10 . V_119 . V_90 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_90 . V_120 = V_62 ;
break;
default:
break;
}
}
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned int V_76 ;
unsigned int V_139 ;
unsigned int V_140 ;
unsigned int V_91 ;
unsigned int V_141 ;
unsigned int V_62 ;
const void * V_138 = V_2 -> V_10 . V_138 ;
const T_1 * V_142 ;
const struct V_143 * V_144 ;
const struct V_152 * V_153 = V_138 ;
V_2 -> V_10 . V_119 . V_154 = F_47 ( V_153 -> V_154 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 , L_44 ,
V_15 , V_2 -> V_10 . V_119 . V_154 ) ;
V_91 = F_47 ( V_153 -> V_155 ) ;
V_144 = V_138 + V_91 ;
V_91 = F_47 ( V_144 -> V_146 ) ;
V_139 = F_47 ( V_144 -> V_147 ) / 4 ;
for ( V_76 = 0 ; V_76 < V_139 ; V_76 ++ ) {
V_140 = F_46 ( V_138 + V_91 ) ;
V_91 += 4 ;
V_144 = V_138 + V_140 ;
V_141 = F_19 ( V_144 -> V_141 ) ;
V_142 = V_138 + F_47 ( V_144 -> V_146 ) ;
V_62 = F_47 ( V_144 -> V_147 ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_45 , V_15 ,
V_141 , V_62 ) ;
switch ( V_141 ) {
case V_156 :
case V_157 :
V_2 -> V_10 . V_119 . V_82 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_82 . V_120 = V_62 ;
break;
case V_158 :
case V_159 :
V_2 -> V_10 . V_119 . V_83 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_83 . V_120 = V_62 ;
break;
case V_160 :
V_2 -> V_10 . V_119 . V_161 = * V_142 ;
V_2 -> V_10 . V_119 . V_145 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_145 . V_120 = V_62 ;
F_45 ( V_2 , V_138 ) ;
break;
case V_162 :
V_2 -> V_10 . V_119 . V_163 = true ;
V_2 -> V_10 . V_119 . V_86 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_86 . V_120 = V_62 ;
break;
case V_164 :
V_2 -> V_10 . V_119 . V_165 = true ;
V_2 -> V_10 . V_119 . V_84 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_84 . V_120 = V_62 ;
break;
case V_166 :
V_2 -> V_10 . V_119 . V_167 = true ;
V_2 -> V_10 . V_119 . V_85 . V_135 = V_142 ;
V_2 -> V_10 . V_119 . V_85 . V_120 = V_62 ;
break;
case V_168 :
V_2 -> V_10 . V_119 . V_169 = true ;
V_2 -> V_10 . V_119 . V_170 =
F_46 ( V_142 + 4 ) ;
break;
default:
break;
}
}
}
static int F_49 ( struct V_1 * V_2 )
{
const struct V_152 * V_153 = V_2 -> V_10 . V_138 ;
memset ( & V_2 -> V_10 . V_119 , 0x00 , sizeof( V_2 -> V_10 . V_119 ) ) ;
F_3 ( V_13 , & V_2 -> V_6 -> V_14 ,
L_46 ,
V_15 , V_153 -> V_171 ) ;
switch ( V_153 -> V_171 ) {
case V_172 :
F_48 ( V_2 ) ;
break;
default:
F_4 ( & V_2 -> V_6 -> V_14 , L_47 ,
V_153 -> V_171 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_10 . V_119 . V_167 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_48 ,
V_15 ) ;
return - V_53 ;
}
F_18 ( V_2 , V_2 -> V_10 . V_119 . V_85 . V_135 ,
& V_2 -> V_10 . V_119 . V_73 , & V_2 -> V_10 . V_119 . V_75 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , const struct V_173 * V_174 )
{
int V_5 ;
F_20 ( V_2 ) ;
V_2 -> V_10 . V_138 = V_174 -> V_135 ;
V_2 -> V_131 = 0 ;
V_2 -> V_121 = 0 ;
V_5 = F_49 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
if ( ! V_2 -> V_10 . V_123 ) {
V_5 = F_24 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
V_5 = F_25 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
if ( V_2 -> V_10 . V_106 &&
V_2 -> V_10 . V_119 . V_165 ) {
V_5 = F_26 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
}
if ( V_2 -> V_10 . V_109 && V_2 -> V_10 . V_119 . V_163 ) {
V_5 = F_27 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
}
} else {
V_5 = F_28 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
}
V_5 = F_32 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
if ( V_2 -> V_10 . V_123 ) {
V_5 = F_41 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
F_30 ( & V_2 -> V_6 -> V_14 , L_49 ,
V_15 ) ;
}
F_30 ( & V_2 -> V_6 -> V_14 , L_50 ,
V_2 -> V_10 . V_119 . V_82 . V_120 ) ;
V_5 = F_43 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
F_30 ( & V_2 -> V_6 -> V_14 , L_51 ,
V_2 -> V_10 . V_119 . V_83 . V_120 ) ;
V_2 -> V_10 . V_55 = V_56 ;
V_5 = F_37 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
if ( V_2 -> V_10 . V_106 && V_2 -> V_10 . V_119 . V_165 ) {
F_30 ( & V_2 -> V_6 -> V_14 , L_52 ) ;
V_5 = F_38 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
}
if ( V_2 -> V_10 . V_123 ) {
if ( V_2 -> V_10 . V_109 && V_2 -> V_10 . V_119 . V_163 ) {
F_30 ( & V_2 -> V_6 -> V_14 , L_53 ) ;
V_5 = F_39 ( V_2 ) ;
if ( V_5 < 0 )
goto V_175;
}
}
V_175:
return V_5 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_5 ;
V_2 -> V_6 -> V_7 -> V_176 -> V_177 ( V_2 -> V_6 -> V_7 , V_2 -> V_6 -> V_178 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_2 -> V_10 . V_16 )
return 0 ;
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_11 ( V_2 , V_42 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_2 , V_129 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , const struct V_173 * V_174 )
{
int V_5 = 0 ;
V_2 -> V_6 -> V_7 -> V_176 -> V_177 ( V_2 -> V_6 -> V_7 , V_2 -> V_6 -> V_178 ) ;
V_2 -> V_10 . V_55 = V_56 ;
V_2 -> V_10 . V_138 = V_174 -> V_135 ;
V_5 = F_49 ( V_2 ) ;
if ( V_5 < 0 )
goto exit;
if ( ! V_2 -> V_10 . V_179 && V_2 -> V_10 . V_123 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_54 ,
V_15 ) ;
V_5 = - V_53 ;
goto exit;
}
F_30 ( & V_2 -> V_6 -> V_14 , L_55 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
goto exit;
if ( V_2 -> V_10 . V_16 ) {
F_30 ( & V_2 -> V_6 -> V_14 , L_56 ,
V_15 ) ;
}
F_51 ( V_2 ) ;
return 0 ;
exit:
return V_5 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 . V_95 + V_180 ,
V_2 -> V_46 ,
sizeof( V_2 -> V_46 ) ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_6 -> V_14 , L_57 ,
V_15 ) ;
return V_5 ;
}
if ( V_2 -> V_46 [ 1 ] == '5' ) {
V_2 -> V_161 = 5 ;
} else if ( V_2 -> V_46 [ 1 ] == '6' ) {
V_2 -> V_161 = 6 ;
} else if ( V_2 -> V_46 [ 1 ] == 7 ) {
V_2 -> V_161 = 7 ;
} else {
F_4 ( & V_2 -> V_6 -> V_14 , L_58 ,
V_15 ) ;
return - V_53 ;
}
memset ( & V_2 -> V_10 . V_73 , 0x00 , sizeof( V_2 -> V_10 . V_73 ) ) ;
memset ( & V_2 -> V_10 . V_75 , 0x00 , sizeof( V_2 -> V_10 . V_75 ) ) ;
F_15 ( & V_2 -> V_10 . V_20 ) ;
V_5 = F_21 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_10 . V_179 = true ;
return 0 ;
}
