static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
T_2 V_11 [ 2 ] ;
V_11 [ 0 ] = V_8 >> 8 ;
V_11 [ 1 ] = V_8 ;
F_6 ( V_10 , V_11 , 2 ) ;
F_7 ( V_10 , V_11 , 1 ) ;
return V_11 [ 0 ] ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_8 ,
T_2 V_12 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
T_2 V_11 [ 3 ] ;
V_11 [ 0 ] = V_8 >> 8 ;
V_11 [ 1 ] = V_8 ;
V_11 [ 2 ] = V_12 ;
return F_6 ( V_10 , V_11 , 3 ) ;
}
static int F_9 ( struct V_2 * V_3 , const T_1 * V_13 )
{
T_1 V_14 ;
T_2 V_15 ;
while ( * V_13 != 0x00 ) {
V_14 = * V_13 ++ ;
V_15 = * V_13 ++ ;
F_8 ( V_3 , V_14 , V_15 ) ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_16 ) {
case V_17 :
F_8 ( V_3 , V_18 , V_5 -> V_19 ) ;
break;
case V_20 :
F_8 ( V_3 , V_21 , V_5 -> V_19 ) ;
break;
case V_22 :
F_8 ( V_3 , V_23 , V_5 -> V_19 ) ;
break;
case V_24 :
F_8 ( V_3 , V_25 , V_5 -> V_19 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( V_30 -> V_31 || V_30 -> V_8 >= F_12 ( V_32 ) )
return - V_26 ;
V_30 -> V_30 = V_32 [ V_30 -> V_8 ] . V_33 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = & V_35 -> V_35 ;
struct V_1 * V_38 = F_1 ( V_3 ) ;
int V_8 ;
if ( V_35 -> V_31 )
return - V_26 ;
for ( V_8 = 0 ; V_8 < F_12 ( V_32 ) ; V_8 ++ )
if ( V_32 [ V_8 ] . V_33 == V_37 -> V_30 )
break;
if ( V_8 >= F_12 ( V_32 ) ) {
V_8 = 0 ;
V_37 -> V_30 = V_32 [ 0 ] . V_33 ;
}
if ( V_37 -> V_39 > V_40 )
V_37 -> V_39 = V_40 ;
if ( V_37 -> V_41 > V_42 )
V_37 -> V_41 = V_42 ;
V_37 -> V_39 = V_37 -> V_39 & ( ~ 3 ) ;
V_37 -> V_41 = V_37 -> V_41 & ( ~ 3 ) ;
V_37 -> V_43 = V_44 ;
V_37 -> V_45 = V_32 [ V_8 ] . V_45 ;
if ( V_35 -> V_46 == V_47 ) {
V_28 -> V_48 = * V_37 ;
return 0 ;
}
switch ( V_37 -> V_30 ) {
case V_49 :
F_8 ( V_3 , V_50 , 0x0 ) ;
F_8 ( V_3 , V_51 , 0x1 ) ;
break;
case V_52 :
F_8 ( V_3 , V_50 , 0x0 ) ;
F_8 ( V_3 , V_51 , 0x3 ) ;
break;
case V_53 :
F_8 ( V_3 , V_50 , 0x4 ) ;
F_8 ( V_3 , V_54 , 0x0 ) ;
break;
default:
return - V_26 ;
}
if ( ( V_37 -> V_39 == V_40 ) && ( V_37 -> V_41 == V_42 ) )
F_8 ( V_3 , V_55 , 0x2 ) ;
else if ( ( V_37 -> V_39 == V_56 ) && ( V_37 -> V_41 == V_57 ) )
F_8 ( V_3 , V_55 , 0x4 ) ;
else if ( ( V_37 -> V_39 == V_58 ) && ( V_37 -> V_41 == V_59 ) )
F_8 ( V_3 , V_55 , 0x6 ) ;
else if ( ( V_37 -> V_39 == V_60 ) && ( V_37 -> V_41 == V_61 ) )
F_8 ( V_3 , V_55 , 0x3 ) ;
else if ( ( V_37 -> V_39 == V_62 ) && ( V_37 -> V_41 == V_63 ) )
F_8 ( V_3 , V_55 , 0x5 ) ;
else if ( ( V_37 -> V_39 == V_64 ) && ( V_37 -> V_41 == V_65 ) )
F_8 ( V_3 , V_55 , 0x7 ) ;
else {
F_8 ( V_3 , V_55 , 0x8 ) ;
F_8 ( V_3 , V_66 , V_37 -> V_39 >> 8 ) ;
F_8 ( V_3 , V_67 , V_37 -> V_39 & 0xFF ) ;
F_8 ( V_3 , V_68 , V_37 -> V_41 >> 8 ) ;
F_8 ( V_3 , V_69 , V_37 -> V_41 & 0xFF ) ;
F_8 ( V_3 , V_70 , 0x1 ) ;
}
V_38 -> V_37 = * V_37 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_34 * V_35 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
if ( V_35 -> V_31 )
return - V_26 ;
V_35 -> V_35 = V_38 -> V_37 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
struct V_73 * V_74 = & V_72 -> V_75 . V_76 ;
if ( V_72 -> type != V_77 )
return - V_26 ;
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
V_74 -> V_78 = V_79 ;
V_74 -> V_80 . V_81 = V_38 -> V_82 . V_83 ;
V_74 -> V_80 . V_83 = V_38 -> V_82 . V_81 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_71 * V_72 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
struct V_73 * V_74 = & V_72 -> V_75 . V_76 ;
struct V_84 * V_85 = & V_74 -> V_80 ;
if ( V_72 -> type != V_77 )
return - V_26 ;
if ( V_74 -> V_86 != 0 )
return - V_26 ;
if ( V_85 -> V_81 == 0 || V_85 -> V_83 == 0
|| ( V_85 -> V_83 > V_85 -> V_81 * V_87 ) ) {
V_85 -> V_81 = 1 ;
V_85 -> V_83 = V_87 ;
}
V_38 -> V_82 . V_81 = V_85 -> V_83 ;
V_38 -> V_82 . V_83 = V_85 -> V_81 ;
F_8 ( V_3 , V_88 , 0x0 ) ;
F_8 ( V_3 , V_89 ,
V_38 -> V_82 . V_81 >> 8 ) ;
F_8 ( V_3 , V_90 ,
V_38 -> V_82 . V_81 & 0xFF ) ;
F_8 ( V_3 , V_91 ,
V_38 -> V_82 . V_83 & 0xFF ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , int V_92 )
{
if ( V_92 )
F_8 ( V_3 , V_93 , 0x2 ) ;
else
F_8 ( V_3 , V_93 , 0x4 ) ;
F_18 ( 100 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_94 * V_14 )
{
V_14 -> V_19 = F_4 ( V_3 , V_14 -> V_14 & 0xffff ) ;
V_14 -> V_95 = 1 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , const struct V_94 * V_14 )
{
F_8 ( V_3 , V_14 -> V_14 & 0xffff , V_14 -> V_19 & 0xff ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
const struct V_96 * V_16 )
{
struct V_1 * V_38 ;
struct V_2 * V_3 ;
struct V_97 * V_7 ;
const unsigned * V_98 ;
int V_99 ;
if ( ! F_22 ( V_10 -> V_100 , V_101 ) )
return - V_102 ;
V_98 = V_10 -> V_103 . V_104 ;
if ( V_98 == NULL )
return - V_26 ;
V_99 = F_23 ( & V_10 -> V_103 , * V_98 , V_105 ,
L_1 ) ;
if ( V_99 ) {
F_24 ( V_10 , L_2 , * V_98 ) ;
return V_99 ;
}
F_25 ( 100 ) ;
V_38 = F_26 ( & V_10 -> V_103 , sizeof( * V_38 ) , V_106 ) ;
if ( V_38 == NULL )
return - V_107 ;
V_3 = & V_38 -> V_3 ;
F_27 ( V_3 , V_10 , & V_108 ) ;
F_9 ( V_3 , V_109 ) ;
F_8 ( V_3 , V_110 , 0x2 ) ;
F_8 ( V_3 , V_111 , 0x1 ) ;
F_25 ( 10 ) ;
F_9 ( V_3 , V_112 ) ;
F_9 ( V_3 , V_113 ) ;
F_8 ( V_3 , V_114 , 0xF ) ;
F_9 ( V_3 , V_115 ) ;
V_38 -> V_82 . V_81 = V_87 ;
V_38 -> V_82 . V_83 = 1 ;
F_8 ( V_3 , V_88 , 0x0 ) ;
F_8 ( V_3 , V_89 ,
V_38 -> V_82 . V_81 >> 8 ) ;
F_8 ( V_3 , V_90 ,
V_38 -> V_82 . V_81 & 0xFF ) ;
F_8 ( V_3 , V_91 ,
V_38 -> V_82 . V_83 & 0xFF ) ;
V_38 -> V_37 = V_116 ;
V_38 -> V_117 = * V_98 ;
F_28 ( V_10 , L_3 ,
V_10 -> V_118 << 1 , V_10 -> V_100 -> V_119 ) ;
V_7 = & V_38 -> V_7 ;
F_29 ( V_7 , 4 ) ;
F_30 ( V_7 , & V_120 ,
V_17 , 0 , 0xFF , 1 , 0x87 ) ;
F_30 ( V_7 , & V_120 ,
V_20 , 0 , 0xFF , 1 , 0x78 ) ;
F_30 ( V_7 , & V_120 ,
V_22 , 0 , 1 , 1 , 0 ) ;
F_30 ( V_7 , & V_120 ,
V_24 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_121 = V_7 ;
if ( V_7 -> error ) {
int V_122 = V_7 -> error ;
F_31 ( V_7 ) ;
return V_122 ;
}
V_99 = F_32 ( V_7 ) ;
if ( V_99 )
F_31 ( V_7 ) ;
return V_99 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_34 ( V_10 ) ;
F_35 ( V_3 ) ;
F_31 ( V_3 -> V_121 ) ;
return 0 ;
}
