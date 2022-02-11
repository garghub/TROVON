static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , bool V_6 )
{
if ( V_6 ) {
F_4 ( 0x1 , V_5 -> V_7 + V_8 ) ;
F_4 ( 0x1 , V_5 -> V_7 + V_9 ) ;
F_4 ( 0x1 , V_5 -> V_7 + V_10 ) ;
} else {
F_4 ( 0x0 , V_5 -> V_7 + V_8 ) ;
F_4 ( 0x0 , V_5 -> V_7 + V_9 ) ;
F_4 ( 0x0 , V_5 -> V_7 + V_10 ) ;
}
}
static void F_5 ( struct V_1 * V_5 )
{
int V_11 = V_5 -> V_12 . V_13 ;
F_4 ( V_11 - 1 , V_5 -> V_7 + V_14 ) ;
}
static void F_6 ( struct V_1 * V_5 ,
T_1 V_15 , T_1 V_16 )
{
F_4 ( V_17 , V_5 -> V_7 + V_18 ) ;
F_4 ( 0x0 , V_5 -> V_7 + V_19 ) ;
F_4 ( 0x0 , V_5 -> V_7 + V_18 ) ;
F_4 ( V_20 , V_5 -> V_7 + V_18 ) ;
F_4 ( V_21 | V_15 , V_5 -> V_7 + V_19 ) ;
F_4 ( 0x0 , V_5 -> V_7 + V_18 ) ;
F_4 ( V_16 , V_5 -> V_7 + V_19 ) ;
F_4 ( V_20 , V_5 -> V_7 + V_18 ) ;
F_4 ( 0x0 , V_5 -> V_7 + V_18 ) ;
}
static int F_7 ( T_1 V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_8 ( V_24 ) ; V_23 ++ )
if ( V_24 [ V_23 ] . V_22 > V_22 )
return V_24 [ V_23 ] . V_25 ;
return - V_26 ;
}
static int F_9 ( struct V_1 * V_5 )
{
struct V_27 * V_28 ;
T_1 V_29 ;
int V_30 ;
V_28 = F_10 ( V_5 -> V_31 -> V_32 ,
V_33 ) ;
if ( ! V_28 )
V_29 = V_34 ;
else
V_29 = F_11 ( 2 * V_28 -> V_35 [ V_28 -> V_36 ] ,
V_37 ) ;
V_30 = F_7 ( V_29 ) ;
if ( V_30 < 0 )
return V_30 ;
F_6 ( V_5 , 0x44 , V_30 ) ;
return 0 ;
}
static int T_2 F_12 ( struct V_1 * V_5 )
{
T_1 V_38 ;
int V_39 ;
V_39 = F_13 ( V_5 -> V_7 + V_40 , V_38 ,
! ( V_38 & V_41 ) , 0 , 500000 ) ;
if ( V_39 ) {
F_14 ( & V_5 -> V_4 , L_1 , V_38 ) ;
return V_39 ;
}
V_39 = F_13 ( V_5 -> V_7 + V_42 , V_38 ,
V_38 == 0x0 , 0 , 500000 ) ;
if ( V_39 ) {
F_14 ( & V_5 -> V_4 , L_2 , V_38 ) ;
return V_39 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_5 )
{
T_1 V_43 , V_38 ;
int V_39 ;
V_43 = V_44 |
( ( V_5 -> V_12 . V_13 - 1 ) << V_45 ) ;
V_39 = F_13 ( V_5 -> V_7 + V_40 , V_38 ,
( V_38 & V_43 ) == V_43 , 0 , 500000 ) ;
if ( V_39 ) {
F_14 ( & V_5 -> V_4 , L_3 , V_38 ) ;
return V_39 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_5 )
{
T_1 V_38 ;
int V_39 ;
V_39 = F_13 ( V_5 -> V_7 + V_40 , V_38 ,
( V_38 & V_46 ) , 0 , 500000 ) ;
if ( V_39 ) {
F_14 ( & V_5 -> V_4 , L_4 ,
V_38 ) ;
return V_39 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_5 )
{
T_1 V_38 = 0 ;
switch ( V_5 -> V_47 . V_48 ) {
case V_49 :
case V_50 :
V_38 = V_51 ;
break;
default:
break;
}
F_4 ( V_38 , V_5 -> V_7 + V_52 ) ;
}
static int F_18 ( struct V_1 * V_5 )
{
int V_39 ;
V_39 = F_19 ( V_5 -> V_53 ) ;
if ( V_39 )
return V_39 ;
F_17 ( V_5 ) ;
V_39 = F_9 ( V_5 ) ;
if ( V_39 )
goto V_54;
F_5 ( V_5 ) ;
F_3 ( V_5 , true ) ;
V_39 = F_15 ( V_5 ) ;
if ( V_39 )
goto V_55;
V_39 = F_20 ( V_5 -> V_31 , V_56 , V_57 , 1 ) ;
V_39 = ( V_39 && V_39 != - V_58 ) ? V_39 : 0 ;
if ( V_39 )
goto V_55;
V_39 = F_16 ( V_5 ) ;
if ( V_39 )
goto V_59;
return 0 ;
V_59:
F_20 ( V_5 -> V_31 , V_56 , V_57 , 0 ) ;
V_55:
F_3 ( V_5 , false ) ;
V_54:
F_21 ( V_5 -> V_53 ) ;
return V_39 ;
}
static void F_22 ( struct V_1 * V_5 )
{
F_20 ( V_5 -> V_31 , V_56 , V_57 , 0 ) ;
F_3 ( V_5 , false ) ;
F_21 ( V_5 -> V_53 ) ;
}
static int F_23 ( struct V_2 * V_4 , int V_6 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_23 , V_39 = 0 ;
F_24 ( & V_5 -> V_60 ) ;
if ( ! V_5 -> V_31 ) {
V_39 = - V_61 ;
goto V_62;
}
for ( V_23 = 0 ; V_23 < V_63 ; V_23 ++ ) {
if ( V_5 -> V_64 [ V_23 ] )
break;
}
if ( V_23 >= V_63 ) {
V_39 = - V_61 ;
goto V_62;
}
if ( V_5 -> V_65 != ! V_6 )
goto V_66;
F_25 ( V_5 -> V_67 , L_5 , V_6 ? L_6 : L_7 ) ;
if ( V_6 )
V_39 = F_18 ( V_5 ) ;
else
F_22 ( V_5 ) ;
if ( V_39 )
goto V_62;
V_66:
V_5 -> V_65 += V_6 ? 1 : - 1 ;
if ( V_5 -> V_65 < 0 )
V_5 -> V_65 = 0 ;
V_62:
F_26 ( & V_5 -> V_60 ) ;
return V_39 ;
}
static int F_27 ( struct V_68 * V_69 ,
const struct V_70 * V_71 ,
const struct V_70 * V_72 , T_1 V_73 )
{
struct V_2 * V_4 = F_28 ( V_69 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_2 * V_74 ;
int V_39 = 0 ;
F_25 ( V_5 -> V_67 , L_8 , V_72 -> V_69 -> V_75 ,
V_71 -> V_69 -> V_75 ) ;
V_74 = F_28 ( V_72 -> V_69 ) ;
F_24 ( & V_5 -> V_60 ) ;
if ( V_71 -> V_73 & V_76 ) {
if ( V_73 & V_77 ) {
if ( V_5 -> V_64 [ V_71 -> V_78 - 1 ] ) {
V_39 = - V_79 ;
goto V_62;
}
V_5 -> V_64 [ V_71 -> V_78 - 1 ] = true ;
} else {
V_5 -> V_64 [ V_71 -> V_78 - 1 ] = false ;
}
} else {
if ( V_73 & V_77 ) {
if ( V_5 -> V_31 ) {
V_39 = - V_79 ;
goto V_62;
}
V_5 -> V_31 = V_74 ;
} else {
V_5 -> V_31 = NULL ;
}
}
V_62:
F_26 ( & V_5 -> V_60 ) ;
return V_39 ;
}
static int F_29 ( struct V_2 * V_4 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
struct V_84 * V_85 ;
F_24 ( & V_5 -> V_60 ) ;
if ( V_83 -> V_86 == V_87 )
V_85 = F_30 ( & V_5 -> V_4 , V_81 ,
V_83 -> V_88 ) ;
else
V_85 = & V_5 -> V_47 ;
V_83 -> V_89 = * V_85 ;
F_26 ( & V_5 -> V_60 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_4 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_39 = 0 ;
if ( V_83 -> V_88 >= V_90 )
return - V_26 ;
F_24 ( & V_5 -> V_60 ) ;
if ( V_5 -> V_65 > 0 ) {
V_39 = - V_79 ;
goto V_62;
}
if ( V_83 -> V_88 != V_91 )
V_83 -> V_89 = V_5 -> V_47 ;
if ( V_83 -> V_86 == V_87 )
V_81 -> V_92 = V_83 -> V_89 ;
else
V_5 -> V_47 = V_83 -> V_89 ;
V_62:
F_26 ( & V_5 -> V_60 ) ;
return V_39 ;
}
static int F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_23 , V_39 ;
for ( V_23 = 0 ; V_23 < V_90 ; V_23 ++ ) {
V_5 -> V_88 [ V_23 ] . V_73 = ( V_23 == V_91 ) ?
V_93 : V_76 ;
}
V_39 = F_33 ( & V_5 -> V_47 ,
640 , 480 , 0 , V_94 , NULL ) ;
if ( V_39 )
return V_39 ;
return F_34 ( & V_4 -> V_69 , V_90 , V_5 -> V_88 ) ;
}
static int F_35 ( struct V_1 * V_5 )
{
struct V_95 * V_96 = V_5 -> V_67 -> V_97 ;
struct V_95 * V_98 ;
struct V_99 V_100 ;
V_98 = F_36 ( V_96 , 0 , - 1 ) ;
if ( ! V_98 ) {
F_14 ( & V_5 -> V_4 , L_9 ) ;
return - V_26 ;
}
F_37 ( F_38 ( V_98 ) , & V_100 ) ;
F_39 ( V_98 ) ;
if ( V_100 . V_101 != V_102 ) {
F_14 ( & V_5 -> V_4 , L_10 ) ;
return - V_26 ;
}
V_5 -> V_12 = V_100 . V_12 . V_103 ;
F_25 ( V_5 -> V_67 , L_11 , V_5 -> V_12 . V_13 ) ;
F_25 ( V_5 -> V_67 , L_12 , V_5 -> V_12 . V_73 ) ;
return 0 ;
}
static int F_40 ( struct V_104 * V_105 )
{
struct V_1 * V_5 ;
struct V_106 * V_107 ;
int V_39 ;
V_5 = F_41 ( & V_105 -> V_67 , sizeof( * V_5 ) , V_108 ) ;
if ( ! V_5 )
return - V_109 ;
V_5 -> V_67 = & V_105 -> V_67 ;
F_42 ( & V_5 -> V_4 , & V_110 ) ;
F_43 ( & V_5 -> V_4 , & V_105 -> V_67 ) ;
V_5 -> V_4 . V_111 = & V_112 ;
V_5 -> V_4 . V_69 . V_113 = & V_114 ;
V_5 -> V_4 . V_67 = & V_105 -> V_67 ;
V_5 -> V_4 . V_115 = V_116 ;
V_5 -> V_4 . V_73 = V_117 ;
strcpy ( V_5 -> V_4 . V_75 , V_118 ) ;
V_5 -> V_4 . V_69 . V_119 = V_120 ;
V_5 -> V_4 . V_121 = V_122 ;
V_39 = F_35 ( V_5 ) ;
if ( V_39 )
return V_39 ;
V_5 -> V_123 = F_44 ( & V_105 -> V_67 , L_13 ) ;
if ( F_45 ( V_5 -> V_123 ) ) {
F_14 ( & V_5 -> V_4 , L_14 ) ;
V_39 = F_46 ( V_5 -> V_123 ) ;
return V_39 ;
}
V_5 -> V_124 = F_44 ( & V_105 -> V_67 , L_15 ) ;
if ( F_45 ( V_5 -> V_124 ) ) {
F_14 ( & V_5 -> V_4 , L_16 ) ;
V_39 = F_46 ( V_5 -> V_124 ) ;
return V_39 ;
}
V_5 -> V_53 = F_44 ( & V_105 -> V_67 , L_17 ) ;
if ( F_45 ( V_5 -> V_53 ) ) {
F_14 ( & V_5 -> V_4 , L_18 ) ;
V_39 = F_46 ( V_5 -> V_53 ) ;
return V_39 ;
}
V_107 = F_47 ( V_105 , V_125 , 0 ) ;
if ( ! V_107 ) {
F_14 ( & V_5 -> V_4 , L_19 ) ;
return - V_126 ;
}
V_5 -> V_7 = F_48 ( & V_105 -> V_67 , V_107 -> V_127 , V_128 ) ;
if ( ! V_5 -> V_7 ) {
F_14 ( & V_5 -> V_4 , L_20 ) ;
return - V_109 ;
}
F_49 ( & V_5 -> V_60 ) ;
V_39 = F_19 ( V_5 -> V_123 ) ;
if ( V_39 ) {
F_14 ( & V_5 -> V_4 , L_21 ) ;
goto V_129;
}
V_39 = F_19 ( V_5 -> V_124 ) ;
if ( V_39 ) {
F_14 ( & V_5 -> V_4 , L_22 ) ;
goto V_130;
}
F_50 ( V_105 , & V_5 -> V_4 ) ;
V_39 = F_51 ( & V_5 -> V_4 ) ;
if ( V_39 )
goto V_131;
return 0 ;
V_131:
F_21 ( V_5 -> V_124 ) ;
V_130:
F_21 ( V_5 -> V_123 ) ;
V_129:
F_52 ( & V_5 -> V_60 ) ;
return V_39 ;
}
static int F_53 ( struct V_104 * V_105 )
{
struct V_2 * V_4 = F_54 ( V_105 ) ;
struct V_1 * V_5 = F_1 ( V_4 ) ;
F_55 ( V_4 ) ;
F_21 ( V_5 -> V_124 ) ;
F_21 ( V_5 -> V_123 ) ;
F_52 ( & V_5 -> V_60 ) ;
F_56 ( & V_4 -> V_69 ) ;
return 0 ;
}
